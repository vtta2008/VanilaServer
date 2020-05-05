@ECHO ON

npm install --global --production windows-build-tools

npm config set python '%USEPROFILE%/.windows-build-tools/python27/python.exe

yarn

yarn add global cross-env

yarn dll

yarn dev-win

npm install --save-dev stylelint stylelint-config-standard