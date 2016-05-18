/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 * @flow
 */

import React, { Component } from 'react';
import {
  AppRegistry,
  StyleSheet,
  Text,
  View,
  TouchableHighlight,
  AlertIOS,
  NativeAppEventEmitter
} from 'react-native';

var subscription = NativeAppEventEmitter.addListener(
 'connectivityNotificationHandler', 
 (values) => AlertIOS.alert("Received Connectivity Handler", "Parameters:" + values)
);
	
class PredixMobileReact extends Component {
  render() {
    return (
      <View style={styles.container}>
        <Text style={styles.welcome}>
          Welcome to Predix Mobile / React Native Example
        </Text>
        
        <TouchableHighlight onPress={this.callConnectivity} style={styles.button}>
           <Text>Test PM API call</Text>
        </TouchableHighlight>
        
        <TouchableHighlight onPress={this.watchConnectivity} style={styles.button}>
           <Text>Watch Connectivity</Text>
        </TouchableHighlight>
        
        <Text style={styles.instructions}>
          To get started, edit index.ios.js
        </Text>
        <Text style={styles.instructions}>
          Press Cmd+R to reload,{'\n'}
          Cmd+D or shake for dev menu
        </Text>
      </View>
    );
  }
  
   callConnectivity() {
   
   		var xmlhttp = new XMLHttpRequest();

		xmlhttp.onreadystatechange = function() {
			if (xmlhttp.readyState == XMLHttpRequest.DONE) {
				console.log("Response status: " + xmlhttp.status);
				console.log("Response payload: " + xmlhttp.responseText);
				AlertIOS.alert(
                  "GET Response",
                  "Response -> " + xmlhttp.responseText
                )
			}
		  };

		xmlhttp.open("GET", "http://pmapi/connectivity", true);
		xmlhttp.setRequestHeader("Content-type","application/json;charset=UTF-8");
		xmlhttp.send();
    }
    
    watchConnectivity() {
    	
    	var xmlhttp = new XMLHttpRequest();

		xmlhttp.onreadystatechange = function() {
			if (xmlhttp.readyState == XMLHttpRequest.DONE) {
				console.log("Response status: " + xmlhttp.status);
				console.log("Response payload: " + xmlhttp.responseText);
			}
		  };

		xmlhttp.open("POST", "http://pmapi/notify/events/ReachabilityWatcherNotification", true);
		xmlhttp.setRequestHeader("Content-type","application/json;charset=UTF-8");
		
		var json = JSON.stringify({"script":"connectivityNotificationHandler"});
		
		xmlhttp.send(json);
    }
    
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: '#F5FCFF',
  },
  welcome: {
    fontSize: 20,
    textAlign: 'center',
    margin: 10,
  },
  instructions: {
    textAlign: 'center',
    color: '#333333',
    marginBottom: 5,
  },
  button: {
	backgroundColor: '#eeeeee',
	padding: 10,
	marginRight: 5,
	marginLeft: 5,
   }
});

AppRegistry.registerComponent('PredixMobileReact', () => PredixMobileReact);
