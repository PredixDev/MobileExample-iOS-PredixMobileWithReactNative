#!/bin/bash

echo it\'s expected you\'ve already run pm define....

react-native bundle --entry-file ./index.ios.js --platform ios --bundle-output ./dist/main.jsbundle --assets-dest ./PredixMobileReact/Resources
pm publish
