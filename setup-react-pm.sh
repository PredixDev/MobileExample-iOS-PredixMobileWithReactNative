#!/bin/bash

react-native bundle --entry-file ./index.ios.js --platform ios --bundle-output ./dist/main.jsbundle --assets-dest ./PredixMobileReact/Resources
pm publish
pm define
