# MobileExample-iOS-PredixMobileWithReactNative

This example Predix Mobile app container demonstrates how a developer might use [React Native](https://facebook.github.io/react-native/) to extend Predix Mobile.

This simple project demonstrates calling a Predix Mobile client service from React Native, and also subscribing to a notification, receiving data from Predix Mobile notifications in your React Native javascript code.

####Quick setup:

Download this example from Github, and then from the command line:

* Step 1: install the React Native cli tools:


     npm install -g react-native-cli

* Step 2: Download the React Native components this example depends on.


    npm install

* Step 3: Run the first-time setup script to add the expected pm-app and pm-web-app to your Predix Mobile database:


    .\setup-react-pm.sh

Now you are ready to begin, open and run the PredixMobileReact project in XCode.



#### Tips
When updating `index.io.js` to compile and publish to Couchbase, run the included script:

    ./publish-react-pm.sh

