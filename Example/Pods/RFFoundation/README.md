# RFFoundation

[![CI Status](http://img.shields.io/travis/Geph0rce/RFFoundation.svg?style=flat)](https://travis-ci.org/Geph0rce/RFFoundation)
[![Version](https://img.shields.io/cocoapods/v/RFFoundation.svg?style=flat)](http://cocoapods.org/pods/RFFoundation)
[![License](https://img.shields.io/cocoapods/l/RFFoundation.svg?style=flat)](http://cocoapods.org/pods/RFFoundation)
[![Platform](https://img.shields.io/cocoapods/p/RFFoundation.svg?style=flat)](http://cocoapods.org/pods/RFFoundation)

## Example

To run the example project, clone the repo, and run `pod install` from the Example directory first.

## Requirements
#.bash_profile
#alias
alias gitlog="git log --graph --pretty='%Cred%h%Creset -%C(yellow)%d%Creset %s %Cgreen(%cr) %C(bold blue)<%an>%Creset' --abbrev-commit"

function podlint() { pod $@ lint --sources=https://github.com/CocoaPods/Specs.git,https://github.com/Geph0rce/specs.git; }

function podpush() { pod repo push $@ --sources=https://github.com/CocoaPods/Specs.git,https://github.com/Geph0rce/specs.git; }

podpush github RFFoundation.podspec

## Installation

RFFoundation is available through [CocoaPods](http://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod 'RFFoundation'
```

## Author

Geph0rce, iGeph0rce@gmail.com

## License

RFFoundation is available under the MIT license. See the LICENSE file for more info.
