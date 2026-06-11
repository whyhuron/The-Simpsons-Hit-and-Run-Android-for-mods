# 📝 Changelog - Simpsons Hit & Run Port for Android

🌍 **Available languages**

[🇪🇸 Español](#-español) | [🇬🇧 English](#-english) | [🇫🇷 Français](#-français) | [🇩🇪 Deutsch](#-deutsch)

---

# 🇪🇸 Español

## 🚀 Versión 0.87.2

La versión **0.87.2** es una actualización centrada en mejorar la comodidad de los controles táctiles, añadir nuevas opciones de configuración y corregir algunos comportamientos no deseados detectados tras la versión 0.87.

Aunque se trata de una actualización menor, incluye cambios importantes para hacer que la experiencia de juego en Android sea más cómoda, precisa y configurable.

---

## 🎮 Mejoras en el joystick virtual a pie

Se ha mejorado el comportamiento del **joystick virtual cuando el personaje va a pie**.

En versiones anteriores, el joystick táctil tenía una zona muerta demasiado grande, lo que podía hacer que el movimiento del personaje se sintiera menos preciso o algo incómodo en determinadas situaciones.

En esta versión se ha reducido esa zona muerta excesiva, consiguiendo que el control a pie sea más cómodo, más sensible y más preciso al jugar directamente desde la pantalla táctil.

---

## ⚙️ Nueva opción de configuración en la pantalla de pausa

Se ha añadido una nueva opción de **configuración** dentro de la pantalla de pausa in-game.

Desde esta nueva sección, el usuario puede modificar algunos ajustes del port a su gusto sin necesidad de salir completamente de la experiencia de juego.

Esto permite que la versión de Android sea más flexible y se adapte mejor a las preferencias de cada jugador.

---

## 📝 Configuración adicional mediante archivo externo

Debido a que el usuario aporta los assets de la versión original de PC, y dicha versión de 2003 no incluía opciones de menú para activar o desactivar la vibración ni para invertir la cámara, estos ajustes se han añadido mediante un archivo de configuración externo.

El archivo se encuentra en la siguiente ruta:

```txt
Android/data/com.c4rlox.simpsons/files/Simpsons_configuration/Simpsons_configuration.txt
```

Desde este archivo, antes de iniciar el juego, el usuario puede elegir:

* Activar o desactivar la vibración del gamepad.
* Invertir o no la cámara en el eje X.

De esta forma, se añaden opciones modernas de configuración respetando las limitaciones de los assets originales de la versión de PC.

---

## 📳 Corrección de vibración no deseada del teléfono

Se ha corregido un bug que provocaba que el teléfono vibrase en algunos dispositivos.

Este comportamiento no era intencionado ni formaba parte de ninguna función prevista del port. La vibración del teléfono era un efecto no deseado que solo ocurría en ciertos dispositivos, por lo que ha sido eliminada.

La vibración configurable se mantiene únicamente para mandos compatibles mediante la opción correspondiente del archivo de configuración.

---

## ✨ Resumen de la versión 0.87.2

* Mejorado el joystick virtual a pie.
* Reducida la zona muerta excesiva del joystick táctil.
* Movimiento a pie más cómodo y preciso.
* Añadida opción de configuración en la pantalla de pausa in-game.
* Añadido archivo de configuración externo para opciones no disponibles en los assets originales de PC.
* Añadida opción para activar o desactivar la vibración del gamepad.
* Añadida opción para invertir la cámara en el eje X.
* Corregido el bug que provocaba vibración no deseada del teléfono en algunos dispositivos.


## 🚀 Versión 0.87

La versión **0.87** representa una de las actualizaciones más importantes del port de *The Simpsons: Hit & Run* para Android hasta la fecha.

Esta versión está centrada principalmente en mejorar la experiencia de juego en dispositivos móviles, haciendo que el port sea más cómodo, más accesible y mucho más disfrutable para todos aquellos jugadores que quieran jugar directamente desde la pantalla táctil.

---

## 🎮 Controles táctiles totalmente integrados

La gran novedad de esta versión es la incorporación de **controles táctiles completamente integrados con el sistema original del juego**.

No se trata de una simple capa de botones colocada por encima del juego. Los controles táctiles han sido integrados respetando la arquitectura interna del motor original, utilizando el propio sistema de input del juego y las herramientas que el motor utilizaba para dibujar elementos en pantalla.

Esto permite que la experiencia sea mucho más limpia, fluida y coherente, manteniendo el mejor rendimiento posible y consiguiendo que los controles táctiles se sientan como una parte real del juego.

Los controles táctiles son inteligentes y pueden adaptarse al contexto del jugador, cambiando automáticamente entre layouts de menú, a pie y en vehículo. Además, el port puede detectar si existe un mando físico conectado, mostrando u ocultando los controles táctiles según sea necesario.

Para conocer todos los detalles sobre esta nueva arquitectura, los iconos, los layouts y el archivo de compatibilidad táctil, puedes visitar:

* 📱 [Controles táctiles](TOUCH_CONTROLS.md)

---

## 📱 Mejor soporte de pantalla completa

También se ha añadido una mejora importante relacionada con el modo **pantalla completa**.

En algunos dispositivos Android, el fullscreen no se aplicaba correctamente, lo que podía provocar que el juego no aprovechara toda la pantalla o que aparecieran barras del sistema de forma no deseada.

Con esta actualización se ha mejorado el soporte de pantalla completa para ofrecer una experiencia más inmersiva, limpia y agradable en aquellos dispositivos donde antes no funcionaba correctamente.

---

## ✨ Resumen de la versión 0.87

* Añadidos controles táctiles totalmente integrados con el sistema original del juego.
* Añadidos layouts inteligentes para menú, personaje a pie y vehículo.
* Añadida detección de mando físico para mostrar u ocultar automáticamente los controles táctiles.
* Añadidos iconos táctiles personalizados.
* Añadido archivo de compatibilidad táctil para dispositivos con coordenadas táctiles normalizadas de forma diferente.
* Mejorado el soporte de pantalla completa en dispositivos donde no se aplicaba correctamente.

La versión **0.87** es un paso enorme para hacer que el port sea mucho más cómodo y natural en Android. Es una actualización pensada para que jugar en móvil se sienta mejor, más integrado y mucho más cercano a una experiencia nativa.

---

# 🇬🇧 English

## 🚀 Version 0.87.2

Version **0.87.2** is an update focused on improving the comfort of touch controls, adding new configuration options, and fixing some unwanted behaviors detected after version 0.87.

Although this is a minor update, it includes important changes to make the Android gameplay experience more comfortable, precise, and configurable.

---

## 🎮 Improvements to the on-foot virtual joystick

The behavior of the **virtual joystick when the character is on foot** has been improved.

In previous versions, the touch joystick had an overly large dead zone, which could make character movement feel less precise or somewhat uncomfortable in certain situations.

In this version, that excessive dead zone has been reduced, making on-foot controls more comfortable, more responsive, and more precise when playing directly from the touchscreen.

---

## ⚙️ New configuration option in the pause screen

A new **configuration** option has been added inside the in-game pause screen.

From this new section, users can modify some port settings to their liking without needing to completely exit the gameplay experience.

This makes the Android version more flexible and better adapted to each player's preferences.

---

## 📝 Additional configuration through an external file

Because the user provides the assets from the original PC version, and that 2003 version did not include menu options to enable or disable vibration or to invert the camera, these settings have been added through an external configuration file.

The file is located at the following path:

```txt
Android/data/com.c4rlox.simpsons/files/Simpsons_configuration/Simpsons_configuration.txt
```

From this file, before launching the game, the user can choose to:

* Enable or disable gamepad vibration.
* Invert or not invert the camera on the X axis.

This adds modern configuration options while respecting the limitations of the original PC version assets.

---

## 📳 Fix for unwanted phone vibration

A bug that caused the phone to vibrate on some devices has been fixed.

This behavior was not intentional and was not part of any planned feature of the port. The phone vibration was an unwanted effect that only occurred on certain devices, so it has been removed.

Configurable vibration remains available only for compatible controllers through the corresponding option in the configuration file.

---

## ✨ Version 0.87.2 summary

* Improved the on-foot virtual joystick.
* Reduced the excessive dead zone of the touch joystick.
* Made on-foot movement more comfortable and precise.
* Added a configuration option to the in-game pause screen.
* Added an external configuration file for options not available in the original PC assets.
* Added an option to enable or disable gamepad vibration.
* Added an option to invert the camera on the X axis.
* Fixed the bug that caused unwanted phone vibration on some devices.


## 🚀 Version 0.87

Version **0.87** represents one of the most important updates so far for the Android port of *The Simpsons: Hit & Run*.

This version mainly focuses on improving the gameplay experience on mobile devices, making the port more comfortable, more accessible and much more enjoyable for players who want to play directly using the touchscreen.

---

## 🎮 Fully integrated touch controls

The biggest new feature in this version is the addition of **touch controls fully integrated with the original game system**.

This is not just a simple layer of buttons placed on top of the game. The touch controls have been integrated while respecting the internal architecture of the original engine, using the game’s own input system and the tools the engine used to draw elements on screen.

This allows the experience to feel much cleaner, smoother and more coherent, while maintaining the best possible performance and making the touch controls feel like a real part of the game.

The touch controls are intelligent and can adapt to the player’s context, automatically switching between menu, on-foot and vehicle layouts. The port can also detect whether a physical controller is connected, showing or hiding the touch controls when needed.

For full details about this new architecture, the icons, the layouts and the touch compatibility file, please visit:

* 📱 [Touch controls](TOUCH_CONTROLS.md)

---

## 📱 Improved fullscreen support

An important improvement has also been added regarding **fullscreen mode**.

On some Android devices, fullscreen was not applied correctly, which could cause the game to not use the entire screen or make system bars appear when they should not.

With this update, fullscreen support has been improved to provide a more immersive, cleaner and more pleasant experience on devices where it was not working correctly before.

---

## ✨ Version 0.87 summary

* Added fully integrated touch controls using the original game system.
* Added intelligent layouts for menu, on-foot gameplay and vehicle gameplay.
* Added physical controller detection to automatically show or hide the touch controls.
* Added custom touch icons.
* Added a touch compatibility file for devices that normalize touch coordinates differently.
* Improved fullscreen support on devices where it was not applied correctly.

Version **0.87** is a huge step toward making the port feel much more comfortable and natural on Android. It is an update designed to make playing on mobile feel better, more integrated and much closer to a native experience.

---

# 🇫🇷 Français

## 🚀 Version 0.87.2

La version **0.87.2** est une mise à jour axée sur l’amélioration du confort des commandes tactiles, l’ajout de nouvelles options de configuration et la correction de certains comportements indésirables détectés après la version 0.87.

Même s’il s’agit d’une mise à jour mineure, elle inclut des changements importants afin de rendre l’expérience de jeu sur Android plus confortable, plus précise et plus configurable.

---

## 🎮 Améliorations du joystick virtuel à pied

Le comportement du **joystick virtuel lorsque le personnage se déplace à pied** a été amélioré.

Dans les versions précédentes, le joystick tactile possédait une zone morte trop importante, ce qui pouvait rendre les déplacements du personnage moins précis ou quelque peu inconfortables dans certaines situations.

Dans cette version, cette zone morte excessive a été réduite, ce qui permet d’obtenir un contrôle à pied plus confortable, plus sensible et plus précis lors du jeu directement depuis l’écran tactile.

---

## ⚙️ Nouvelle option de configuration dans l’écran de pause

Une nouvelle option de **configuration** a été ajoutée dans l’écran de pause en jeu.

Depuis cette nouvelle section, l’utilisateur peut modifier certains paramètres du portage selon ses préférences, sans avoir besoin de quitter complètement l’expérience de jeu.

Cela permet à la version Android d’être plus flexible et de mieux s’adapter aux préférences de chaque joueur.

---

## 📝 Configuration supplémentaire via un fichier externe

Étant donné que l’utilisateur fournit les assets de la version originale PC, et que cette version de 2003 n’incluait pas d’options de menu permettant d’activer ou de désactiver la vibration ni d’inverser la caméra, ces paramètres ont été ajoutés via un fichier de configuration externe.

Le fichier se trouve dans le chemin suivant :

```txt
Android/data/com.c4rlox.simpsons/files/Simpsons_configuration/Simpsons_configuration.txt
```

Depuis ce fichier, avant de lancer le jeu, l’utilisateur peut choisir :

* Activer ou désactiver la vibration de la manette.
* Inverser ou non la caméra sur l’axe X.

De cette manière, des options de configuration modernes sont ajoutées tout en respectant les limitations des assets originaux de la version PC.

---

## 📳 Correction de la vibration indésirable du téléphone

Un bug qui provoquait la vibration du téléphone sur certains appareils a été corrigé.

Ce comportement n’était pas intentionnel et ne faisait partie d’aucune fonctionnalité prévue du portage. La vibration du téléphone était un effet indésirable qui ne se produisait que sur certains appareils, elle a donc été supprimée.

La vibration configurable est conservée uniquement pour les manettes compatibles via l’option correspondante du fichier de configuration.

---

## ✨ Résumé de la version 0.87.2

* Joystick virtuel à pied amélioré.
* Zone morte excessive du joystick tactile réduite.
* Déplacements à pied plus confortables et plus précis.
* Option de configuration ajoutée dans l’écran de pause en jeu.
* Fichier de configuration externe ajouté pour les options non disponibles dans les assets originaux PC.
* Option ajoutée pour activer ou désactiver la vibration de la manette.
* Option ajoutée pour inverser la caméra sur l’axe X.
* Bug provoquant une vibration indésirable du téléphone sur certains appareils corrigé.


## 🚀 Version 0.87

La version **0.87** représente l’une des mises à jour les plus importantes à ce jour pour le port Android de *The Simpsons: Hit & Run*.

Cette version se concentre principalement sur l’amélioration de l’expérience de jeu sur appareils mobiles, afin de rendre le port plus confortable, plus accessible et beaucoup plus agréable pour les joueurs qui souhaitent jouer directement avec l’écran tactile.

---

## 🎮 Commandes tactiles entièrement intégrées

La grande nouveauté de cette version est l’ajout de **commandes tactiles entièrement intégrées au système original du jeu**.

Il ne s’agit pas simplement d’une couche de boutons placée par-dessus le jeu. Les commandes tactiles ont été intégrées en respectant l’architecture interne du moteur original, en utilisant le propre système d’entrée du jeu ainsi que les outils que le moteur utilisait pour afficher les éléments à l’écran.

Cela permet d’obtenir une expérience beaucoup plus propre, fluide et cohérente, tout en conservant les meilleures performances possibles et en donnant aux commandes tactiles l’impression de faire réellement partie du jeu.

Les commandes tactiles sont intelligentes et peuvent s’adapter au contexte du joueur, en changeant automatiquement entre les dispositions du menu, du personnage à pied et du véhicule. Le port peut également détecter si une manette physique est connectée, afin d’afficher ou de masquer les commandes tactiles selon la situation.

Pour découvrir tous les détails sur cette nouvelle architecture, les icônes, les dispositions et le fichier de compatibilité tactile, vous pouvez consulter :

* 📱 [Commandes tactiles](TOUCH_CONTROLS.md)

---

## 📱 Meilleur support du mode plein écran

Une amélioration importante a également été ajoutée concernant le mode **plein écran**.

Sur certains appareils Android, le plein écran ne s’appliquait pas correctement, ce qui pouvait empêcher le jeu d’utiliser toute la surface de l’écran ou faire apparaître des barres système de manière indésirable.

Avec cette mise à jour, le support du plein écran a été amélioré afin d’offrir une expérience plus immersive, plus propre et plus agréable sur les appareils où il ne fonctionnait pas correctement auparavant.

---

## ✨ Résumé de la version 0.87

* Ajout de commandes tactiles entièrement intégrées au système original du jeu.
* Ajout de dispositions intelligentes pour le menu, le personnage à pied et les véhicules.
* Ajout de la détection de manette physique pour afficher ou masquer automatiquement les commandes tactiles.
* Ajout d’icônes tactiles personnalisées.
* Ajout d’un fichier de compatibilité tactile pour les appareils qui normalisent les coordonnées tactiles différemment.
* Amélioration du support du plein écran sur les appareils où il ne s’appliquait pas correctement.

La version **0.87** est une énorme avancée pour rendre le port beaucoup plus confortable et naturel sur Android. C’est une mise à jour pensée pour rendre le jeu sur mobile plus agréable, mieux intégré et beaucoup plus proche d’une expérience native.

---

# 🇩🇪 Deutsch

## 🚀 Version 0.87.2

Die Version **0.87.2** ist ein Update, das sich auf die Verbesserung des Komforts der Touch-Steuerung, das Hinzufügen neuer Konfigurationsoptionen und die Behebung einiger unerwünschter Verhaltensweisen konzentriert, die nach Version 0.87 festgestellt wurden.

Auch wenn es sich um ein kleineres Update handelt, enthält es wichtige Änderungen, um das Spielerlebnis auf Android komfortabler, präziser und besser konfigurierbar zu machen.

---

## 🎮 Verbesserungen am virtuellen Joystick zu Fuß

Das Verhalten des **virtuellen Joysticks, wenn sich die Spielfigur zu Fuß bewegt**, wurde verbessert.

In früheren Versionen hatte der Touch-Joystick eine zu große Totzone, wodurch sich die Bewegung der Spielfigur in bestimmten Situationen weniger präzise oder etwas unbequem anfühlen konnte.

In dieser Version wurde diese übermäßige Totzone reduziert, sodass die Steuerung zu Fuß beim Spielen direkt über den Touchscreen komfortabler, empfindlicher und präziser ist.

---

## ⚙️ Neue Konfigurationsoption im Pausenbildschirm

Im Pausenbildschirm während des Spiels wurde eine neue **Konfigurationsoption** hinzugefügt.

Über diesen neuen Bereich kann der Nutzer einige Einstellungen des Ports nach seinen eigenen Vorlieben ändern, ohne das Spielerlebnis vollständig verlassen zu müssen.

Dadurch wird die Android-Version flexibler und kann besser an die Vorlieben jedes Spielers angepasst werden.

---

## 📝 Zusätzliche Konfiguration über eine externe Datei

Da der Nutzer die Assets der originalen PC-Version bereitstellt und diese Version aus dem Jahr 2003 keine Menüoptionen zum Aktivieren oder Deaktivieren der Vibration oder zum Invertieren der Kamera enthielt, wurden diese Einstellungen über eine externe Konfigurationsdatei hinzugefügt.

Die Datei befindet sich unter folgendem Pfad:

```txt
Android/data/com.c4rlox.simpsons/files/Simpsons_configuration/Simpsons_configuration.txt
```

Über diese Datei kann der Nutzer vor dem Start des Spiels Folgendes auswählen:

* Die Vibration des Gamepads aktivieren oder deaktivieren.
* Die Kamera auf der X-Achse invertieren oder nicht.

Auf diese Weise werden moderne Konfigurationsoptionen hinzugefügt, während die Einschränkungen der ursprünglichen Assets der PC-Version respektiert werden.

---

## 📳 Behebung unerwünschter Telefonvibration

Ein Fehler wurde behoben, der auf einigen Geräten dazu führte, dass das Telefon vibrierte.

Dieses Verhalten war nicht beabsichtigt und gehörte zu keiner geplanten Funktion des Ports. Die Telefonvibration war ein unerwünschter Effekt, der nur auf bestimmten Geräten auftrat, und wurde daher entfernt.

Die konfigurierbare Vibration bleibt ausschließlich für kompatible Controller über die entsprechende Option in der Konfigurationsdatei erhalten.

---

## ✨ Zusammenfassung der Version 0.87.2

* Virtueller Joystick zu Fuß verbessert.
* Übermäßige Totzone des Touch-Joysticks reduziert.
* Bewegung zu Fuß komfortabler und präziser gemacht.
* Konfigurationsoption im Pausenbildschirm während des Spiels hinzugefügt.
* Externe Konfigurationsdatei für Optionen hinzugefügt, die in den ursprünglichen PC-Assets nicht verfügbar waren.
* Option zum Aktivieren oder Deaktivieren der Gamepad-Vibration hinzugefügt.
* Option zum Invertieren der Kamera auf der X-Achse hinzugefügt.
* Fehler behoben, der auf einigen Geräten eine unerwünschte Telefonvibration verursachte.


## 🚀 Version 0.87

Version **0.87** ist eines der bisher wichtigsten Updates für den Android-Port von *The Simpsons: Hit & Run*.

Diese Version konzentriert sich vor allem darauf, das Spielerlebnis auf mobilen Geräten zu verbessern und den Port komfortabler, zugänglicher und deutlich angenehmer für alle Spieler zu machen, die direkt über den Touchscreen spielen möchten.

---

## 🎮 Vollständig integrierte Touch-Steuerung

Die größte Neuerung dieser Version ist die Einführung einer **vollständig in das originale Spielsystem integrierten Touch-Steuerung**.

Dabei handelt es sich nicht nur um eine einfache Ebene mit Buttons, die über das Spiel gelegt wurde. Die Touch-Steuerung wurde so integriert, dass sie die interne Architektur der ursprünglichen Engine respektiert und das eigene Eingabesystem des Spiels sowie die Werkzeuge nutzt, mit denen die Engine Bildschirmelemente gezeichnet hat.

Dadurch fühlt sich die Erfahrung deutlich sauberer, flüssiger und stimmiger an, während gleichzeitig die bestmögliche Performance erhalten bleibt und die Touch-Steuerung wie ein echter Teil des Spiels wirkt.

Die Touch-Steuerung ist intelligent und kann sich an den aktuellen Spielkontext anpassen, indem sie automatisch zwischen Menü-, Zu-Fuß- und Fahrzeug-Layouts wechselt. Außerdem kann der Port erkennen, ob ein physischer Controller verbunden ist, und die Touch-Steuerung je nach Situation ein- oder ausblenden.

Alle Details zu dieser neuen Architektur, den Symbolen, den Layouts und der Touch-Kompatibilitätsdatei findest du hier:

* 📱 [Touch-Steuerung](TOUCH_CONTROLS.md)

---

## 📱 Verbesserte Vollbild-Unterstützung

Außerdem wurde eine wichtige Verbesserung für den **Vollbildmodus** hinzugefügt.

Auf einigen Android-Geräten wurde der Vollbildmodus nicht korrekt angewendet. Dadurch konnte es passieren, dass das Spiel nicht den gesamten Bildschirm nutzte oder dass Systemleisten unerwünscht sichtbar blieben.

Mit diesem Update wurde die Vollbild-Unterstützung verbessert, um auf betroffenen Geräten ein immersiveres, saubereres und angenehmeres Spielerlebnis zu ermöglichen.

---

## ✨ Zusammenfassung von Version 0.87

* Vollständig integrierte Touch-Steuerung über das originale Spielsystem hinzugefügt.
* Intelligente Layouts für Menü, Spielfigur zu Fuß und Fahrzeuge hinzugefügt.
* Erkennung physischer Controller hinzugefügt, um die Touch-Steuerung automatisch ein- oder auszublenden.
* Eigene Touch-Symbole hinzugefügt.
* Touch-Kompatibilitätsdatei für Geräte hinzugefügt, die Touch-Koordinaten unterschiedlich normalisieren.
* Verbesserte Vollbild-Unterstützung auf Geräten, bei denen der Vollbildmodus nicht korrekt angewendet wurde.

Version **0.87** ist ein großer Schritt, damit sich der Port auf Android deutlich komfortabler und natürlicher anfühlt. Dieses Update wurde entwickelt, um das Spielen auf mobilen Geräten angenehmer, besser integriert und deutlich näher an einer nativen Erfahrung zu machen.
