# Vanilla Server Side Rendering Work Flow
###### React - React Router - Redux | Express | Webpack

> My own build of Server Side Rendering with user authentication.
> I build this project from scratch without helping from handy framework/libs such as Next.js, React-loadable, React-universal, Isomorphic-react & etc. So I can understand stuffs behind the scene as well as fully customizing and controlling on my desire.

> Essentially, this is a combo of React, React Router 4, Redux, React-Jss, Material-UI, Express, Webpack 4 and so on. 

#### There are many ways to make a SSR Web App. 
##### All by Express (PHP-like) * * * 
You can put all the effort to express server and let it handle everything on every request such as pre-rendered content, routing, store. However, that solution creates a heavy work-loading burden to server as the link transition will trigger a full page reloading every time. Thus, I don't like that much, especially in case we want a client-only SPA we cannot switch easily.
##### A True Hybrid SSR SPA * * * * *
It is still better if we can make a true hybrid SSR SPA. That just loads our application only once with pre-populated content of the specific requested routing. Otherwise, it shall handle the rest from client side and communicate with server via REST API. It is also a flexible solution of returning back to SPA client-only, when you have to deploy the project to just a static http server.

#### Work flow:
##### Server: 
REST User Authentication Check => Redux Store with Session => Route Matching / Data Fetching => React Router => ReactDOM
##### Client:
Redux Store with Server Preloaded Store => React Router => ReactDOM => Async Route Data Fetching

> The project supports server side rendering in both 'before phase' and 'after phase' of user authentication.

### My Free Note:
- Require from Node need to be hacked in order to work friendly with other assets type (images, scss, fonts, text). It need to read complilation stats from webpack, build a reference list of output assets with calling context and module source content.

- Client need to be initialized with preloadedStore from Server to ensure the DOM matching between client and server.

- Axios from Server for the very first handshake of client and server need to collect the client cookies or client sessionStorage, inject it into the header of each later store dispatching XHR (server side).

- Jss cache the generateClassName function, in order to reload it (avoid className mismatching among client & server) Jss need to be loaded with new Registry between request.

- Material UI also caches the sheetsManager of MuiThemeProvider, so to prevent className mismatching again, every request sheetsManager has to be reset with new Map().

- JWT should be created with nbf (notBefore) options to avoid robot attack, hence the token retuned to client won't work before that amount of time we declared. We need to be careful of any ajax/fetch data request which require user authentication. The best way is that delaying a certain amount of time of the promise returned by user logged in, make sure jwt is valid at the time issued.


npm install --global --production windows-build-tools

npm install --save-dev stylelint stylelint-config-standard

npm config set python /path/to/executable/python

yarn

yarn add global cross-env

yarn dll

yarn dev-win