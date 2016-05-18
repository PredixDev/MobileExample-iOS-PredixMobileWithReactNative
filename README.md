# MobileExample-iOS-PredixMobileWithReactNative

This example is a Predix Mobile container, that demonstrates how a developer might use [React-Native](https://facebook.github.io/react-native/) in combination with Predix Mobile.

####Quick setup:

Download this example from Github, and then from the command line:

* Step 1: install the React Native cli tools:


     npm install -g react-native-cli

* Step 2: Download the React Native components this example depends on.


    npm install

* Step 3: Run the first-time setup script to add the expected pm-app and pm-web-app to your Predix Mobile database:


    .\setup-react-pm.sh

Now you are ready to begin, open and run the PredixMobileReact project in XCode.

This project is very simple. It demonstrates calling a Predix Mobile client service from React Native, and also subscribing to a notification, receiving data from Predix Mobile notifications in your React Native javascript code.

#### Tips
When updating index.io.js, to compile and publish to Couchbase, run the included script:

    ./publish-react-pm.sh

