# 🎮 Touch Controls - Version 0.87

🌍 **Available languages**

[🇪🇸 Español](#-español) | [🇬🇧 English](#-english) | [🇫🇷 Français](#-français) | [🇩🇪 Deutsch](#-deutsch)

---

# 🇪🇸 Español

## 🎮 Controles táctiles totalmente integrados

Con la versión **0.87**, el port de *The Simpsons: Hit & Run* para Android recibe una de sus mejoras más importantes hasta la fecha: **controles táctiles completamente integrados con el sistema original del juego**.

Esta implementación no ha sido sencilla, pero ha merecido totalmente la pena. Han sido más de **100 horas de trabajo**, investigación, pruebas y ajustes para conseguir que el resultado no se sienta como un simple añadido externo, sino como una parte real del propio juego.

El objetivo desde el principio era claro: no colocar una simple capa visual encima del juego, sino construir un sistema táctil que respetara al máximo el motor original, su arquitectura interna y la forma en la que el propio juego gestionaba la entrada y el renderizado en 2003.

Por eso, los controles táctiles han sido integrados usando el propio sistema del juego y las herramientas originales que el motor utilizaba para dibujar elementos en pantalla. Esto permite conseguir una experiencia mucho más sólida, limpia y coherente, manteniendo el mejor rendimiento posible y una integración mucho más fiel con el funcionamiento interno del juego.

En la actualizacion  **0.87.4** se ha desplazado el minimapa del juego para ofrecer una mejor experiencia al usuario que juega con controles táctiles, no interfiriendo ahora la posición de los iconos con el minimapa como ocurría en versiones anteriores

## ✨ Iconos diseñados manualmente

Todos los iconos táctiles han sido diseñados por mí usando **GIMP**, cuidando que encajen visualmente con la estética del juego y que sean claros durante la partida.

La idea no era simplemente colocar botones en pantalla, sino crear una interfaz táctil cómoda, reconocible y agradable de usar, especialmente pensada para dispositivos Android.

Cada icono ha sido preparado intentando mantener un equilibrio entre visibilidad, estilo y comodidad, para que el jugador pueda entender rápidamente qué acción realiza cada botón sin romper la personalidad visual del juego.

## 🧠 Controles inteligentes según el contexto

Los nuevos controles táctiles son inteligentes y saben reconocer en qué situación se encuentra el jugador.

El sistema cambia automáticamente entre diferentes layouts según el contexto:

* **Menú**
* **A pie**
* **En vehículo**

Esto significa que los controles no son estáticos ni aparecen siempre de la misma forma. El juego adapta el layout táctil dependiendo de lo que esté ocurriendo en pantalla.

Además, cuando el jugador va a pie, el sistema puede mostrar iconos personalizados para las diferentes acciones que puede realizar el personaje, haciendo que la experiencia sea más clara, natural y cómoda.

Esto permite que la pantalla no esté llena de botones innecesarios y que solo aparezcan los controles realmente útiles en cada momento.

## 🎮 Integración como un mando real

Uno de los puntos más importantes de esta versión es que los controles táctiles no funcionan como un añadido externo improvisado. Han sido integrados como si fueran un **mando disponible dentro del propio sistema del juego**.

Gracias a esto, el juego puede trabajar con los controles táctiles de forma mucho más natural, respetando mejor su sistema interno de input.

Además, el port es capaz de detectar si hay un mando físico conectado. Si el jugador conecta un mando, el layout táctil puede ocultarse automáticamente. Si no hay mando disponible, los iconos táctiles aparecen para permitir jugar cómodamente desde la pantalla.

Esto hace que la experiencia sea mucho más flexible: puedes jugar con controles táctiles cuando quieras, pero también puedes usar un mando físico sin que la interfaz táctil moleste en pantalla.

## ⚙️ Archivo de compatibilidad táctil: Simpsons_touch_mode.txt

Debido a diferencias técnicas entre dispositivos Android, algunos móviles pueden normalizar las coordenadas táctiles de forma diferente.

Para ofrecer la mayor compatibilidad posible, he añadido un archivo llamado:

```txt
Simpsons_touch_mode.txt
```

Este archivo se encuentra en la siguiente ruta:

```txt
Android/data/com.c4rlox.simpsons/touch_controls/Simpsons_touch_mode.txt
```

Por defecto, el juego utiliza el **modo 1**, que debería funcionar correctamente en la mayoría de dispositivos.

Sin embargo, si en tu móvil notas que los controles táctiles no responden bien, que los toques no coinciden correctamente con la posición de los botones o que la zona táctil parece desplazada, puedes cambiar al **modo 2** desde este archivo.

Este sistema se ha añadido para que más dispositivos puedan disfrutar de los controles táctiles correctamente, incluso cuando Android o el propio dispositivo gestionan las coordenadas táctiles de una forma diferente.

En resumen:

* **Modo 1**: modo por defecto y recomendado para la mayoría de dispositivos.
* **Modo 2**: modo alternativo de compatibilidad si el modo 1 no funciona correctamente en tu móvil.

## 🚀 Una mejora clave para Android

Esta actualización representa un paso enorme para hacer que el port sea mucho más accesible, cómodo y disfrutable en Android.

La versión **0.87** no solo añade botones en pantalla: introduce una arquitectura táctil mucho más seria, pensada para integrarse con el juego de la forma más limpia posible y ofrecer una experiencia realmente cómoda.

De hecho, el resultado se siente tan natural que, en algunos momentos, puede llegar a ser igual de cómodo o incluso más cómodo que un control tradicional. Lo digo totalmente en serio: merece mucho la pena probarlo.

---

# 🇬🇧 English

## 🎮 Fully integrated touch controls

With version **0.87**, the Android port of *The Simpsons: Hit & Run* receives one of its most important improvements so far: **touch controls fully integrated with the original game system**.

This implementation was not easy, but it was absolutely worth it. It represents more than **100 hours of work**, research, testing and fine-tuning to make the result feel not like a simple external addition, but like a real part of the game itself.

From the beginning, the goal was clear: not to place a simple visual layer on top of the game, but to build a touch control system that respected the original engine, its internal architecture and the way the game handled input and rendering back in 2003.

That is why the touch controls have been integrated using the game’s own systems and the original tools the engine used to draw elements on screen. This helps provide a much more solid, clean and coherent experience, while keeping the best possible performance and a much more faithful integration with the game’s internal behavior.

In update **0.87.4**, the in-game minimap has been moved to provide a better experience for users playing with touch controls, preventing the position of the icons from interfering with the minimap as happened in previous versions.

## ✨ Manually designed icons

All touch icons have been designed by me using **GIMP**, carefully making sure they fit the visual style of the game and remain clear during gameplay.

The idea was not simply to place buttons on the screen, but to create a comfortable, recognizable and pleasant touch interface, especially designed for Android devices.

Each icon has been prepared with a balance between visibility, style and comfort, so the player can quickly understand each action without breaking the visual personality of the game.

## 🧠 Smart context-aware controls

The new touch controls are intelligent and can recognize the situation the player is currently in.

The system automatically switches between different layouts depending on the context:

* **Menu**
* **On foot**
* **In vehicle**

This means the controls are not static and do not always appear in the same way. The game adapts the touch layout depending on what is happening on screen.

When the player is on foot, the system can also display custom icons for the different actions the character can perform, making the experience clearer, more natural and more comfortable.

This prevents the screen from being filled with unnecessary buttons and ensures that only the controls that are actually useful appear at the right moment.

## 🎮 Integrated as a real controller

One of the most important aspects of this version is that the touch controls do not work like a quick external workaround. They have been integrated as if they were a **real controller available inside the game’s own input system**.

Because of this, the game can work with the touch controls in a much more natural way, while better respecting its internal input system.

The port is also able to detect whether a physical controller is connected. If the player connects a controller, the touch layout can be hidden automatically. If no controller is available, the touch icons appear so the game can be played comfortably from the screen.

This makes the experience much more flexible: you can play with touch controls whenever you want, but you can also use a physical controller without the touch interface getting in the way.

## ⚙️ Touch compatibility file: Simpsons_touch_mode.txt

Due to technical differences between Android devices, some phones may normalize touch coordinates in a different way.

To provide the best compatibility possible, I have added a file called:

```txt
Simpsons_touch_mode.txt
```

This file is located in the following path:

```txt
Android/data/com.c4rlox.simpsons/touch_controls/Simpsons_touch_mode.txt
```

By default, the game uses **mode 1**, which should work correctly on most devices.

However, if you notice that the touch controls do not respond properly on your phone, that touches do not correctly match the button positions, or that the touch area feels offset, you can switch to **mode 2** using this file.

This system has been added so that more devices can enjoy the touch controls correctly, even when Android or the device itself handles touch coordinates differently.

In summary:

* **Mode 1**: default mode, recommended for most devices.
* **Mode 2**: alternative compatibility mode if mode 1 does not work correctly on your phone.

## 🚀 A key improvement for Android

This update represents a huge step toward making the port much more accessible, comfortable and enjoyable on Android.

Version **0.87** does not simply add buttons to the screen: it introduces a much more serious touch architecture, designed to integrate with the game as cleanly as possible and offer a truly comfortable experience.

In fact, the result feels so natural that, in some moments, it can be just as comfortable as a traditional controller, or maybe even more comfortable. I am completely serious: it is really worth trying.

---

# 🇫🇷 Français

## 🎮 Commandes tactiles entièrement intégrées

Avec la version **0.87**, le port Android de *The Simpsons: Hit & Run* reçoit l’une de ses améliorations les plus importantes à ce jour : **des commandes tactiles entièrement intégrées au système original du jeu**.

Cette implémentation n’a pas été simple, mais elle en valait vraiment la peine. Elle représente plus de **100 heures de travail**, de recherche, de tests et d’ajustements afin que le résultat ne ressemble pas à un simple ajout externe, mais à une véritable partie du jeu lui-même.

Dès le départ, l’objectif était clair : ne pas placer une simple couche visuelle par-dessus le jeu, mais construire un système de commandes tactiles qui respecte au maximum le moteur original, son architecture interne et la manière dont le jeu gérait les entrées et l’affichage en 2003.

C’est pourquoi les commandes tactiles ont été intégrées en utilisant les propres systèmes du jeu ainsi que les outils originaux que le moteur utilisait pour afficher les éléments à l’écran. Cela permet d’obtenir une expérience beaucoup plus solide, propre et cohérente, tout en conservant les meilleures performances possibles et une intégration beaucoup plus fidèle au fonctionnement interne du jeu.

Dans la mise à jour **0.87.4**, la mini-carte du jeu a été déplacée afin d’offrir une meilleure expérience aux utilisateurs jouant avec les commandes tactiles, en évitant désormais que la position des icônes n’interfère avec la mini-carte comme c’était le cas dans les versions précédentes.

## ✨ Icônes conçues manuellement

Toutes les icônes tactiles ont été conçues par moi avec **GIMP**, en veillant à ce qu’elles s’intègrent visuellement à l’esthétique du jeu tout en restant claires pendant la partie.

L’idée n’était pas simplement de placer des boutons à l’écran, mais de créer une interface tactile confortable, reconnaissable et agréable à utiliser, spécialement pensée pour les appareils Android.

Chaque icône a été préparée en recherchant un équilibre entre lisibilité, style et confort, afin que le joueur puisse comprendre rapidement chaque action sans casser la personnalité visuelle du jeu.

## 🧠 Commandes intelligentes selon le contexte

Les nouvelles commandes tactiles sont intelligentes et savent reconnaître la situation dans laquelle se trouve le joueur.

Le système change automatiquement de disposition selon le contexte :

* **Menu**
* **À pied**
* **En véhicule**

Cela signifie que les commandes ne sont pas statiques et n’apparaissent pas toujours de la même manière. Le jeu adapte la disposition tactile en fonction de ce qui se passe à l’écran.

Lorsque le joueur est à pied, le système peut également afficher des icônes personnalisées pour les différentes actions que le personnage peut effectuer, ce qui rend l’expérience plus claire, plus naturelle et plus confortable.

Cela évite de surcharger l’écran avec des boutons inutiles et permet d’afficher uniquement les commandes réellement utiles au bon moment.

## 🎮 Intégration comme une vraie manette

L’un des points les plus importants de cette version est que les commandes tactiles ne fonctionnent pas comme une solution externe improvisée. Elles ont été intégrées comme s’il s’agissait d’une **véritable manette disponible dans le système d’entrée du jeu**.

Grâce à cela, le jeu peut travailler avec les commandes tactiles de manière beaucoup plus naturelle, tout en respectant mieux son système interne d’input.

Le port est également capable de détecter si une manette physique est connectée. Si le joueur connecte une manette, la disposition tactile peut se masquer automatiquement. Si aucune manette n’est disponible, les icônes tactiles apparaissent afin de permettre de jouer confortablement depuis l’écran.

Cela rend l’expérience beaucoup plus flexible : vous pouvez jouer avec les commandes tactiles quand vous le souhaitez, mais vous pouvez aussi utiliser une manette physique sans que l’interface tactile gêne l’écran.

## ⚙️ Fichier de compatibilité tactile : Simpsons_touch_mode.txt

En raison de différences techniques entre les appareils Android, certains téléphones peuvent normaliser les coordonnées tactiles d’une manière différente.

Pour offrir la meilleure compatibilité possible, j’ai ajouté un fichier appelé :

```txt
Simpsons_touch_mode.txt
```

Ce fichier se trouve dans le chemin suivant :

```txt
Android/data/com.c4rlox.simpsons/touch_controls/Simpsons_touch_mode.txt
```

Par défaut, le jeu utilise le **mode 1**, qui devrait fonctionner correctement sur la plupart des appareils.

Cependant, si vous remarquez que les commandes tactiles ne répondent pas correctement sur votre téléphone, que les appuis ne correspondent pas bien à la position des boutons ou que la zone tactile semble décalée, vous pouvez passer au **mode 2** grâce à ce fichier.

Ce système a été ajouté afin que davantage d’appareils puissent profiter correctement des commandes tactiles, même lorsque Android ou l’appareil lui-même gère les coordonnées tactiles d’une manière différente.

En résumé :

* **Mode 1** : mode par défaut, recommandé pour la plupart des appareils.
* **Mode 2** : mode de compatibilité alternatif si le mode 1 ne fonctionne pas correctement sur votre téléphone.

## 🚀 Une amélioration essentielle pour Android

Cette mise à jour représente une énorme avancée pour rendre le port beaucoup plus accessible, confortable et agréable sur Android.

La version **0.87** n’ajoute pas simplement des boutons à l’écran : elle introduit une architecture tactile beaucoup plus sérieuse, pensée pour s’intégrer au jeu de la manière la plus propre possible et offrir une expérience réellement confortable.

En réalité, le résultat paraît tellement naturel que, dans certains moments, il peut être aussi confortable qu’une manette traditionnelle, voire même plus confortable. Je le dis très sérieusement : cela vaut vraiment la peine de l’essayer.

---

# 🇩🇪 Deutsch

## 🎮 Vollständig integrierte Touch-Steuerung

Mit Version **0.87** erhält der Android-Port von *The Simpsons: Hit & Run* eine der bisher wichtigsten Verbesserungen: **eine vollständig in das originale Spielsystem integrierte Touch-Steuerung**.

Diese Umsetzung war nicht einfach, aber sie hat sich absolut gelohnt. Mehr als **100 Stunden Arbeit**, Recherche, Tests und Feinanpassungen waren nötig, damit sich das Ergebnis nicht wie eine einfache externe Ergänzung anfühlt, sondern wie ein echter Teil des Spiels selbst.

Von Anfang an war das Ziel klar: Es sollte nicht einfach nur eine visuelle Ebene über das Spiel gelegt werden. Stattdessen sollte ein Touch-Steuerungssystem entstehen, das die ursprüngliche Engine, ihre interne Architektur und die Art, wie das Spiel im Jahr 2003 Eingaben und Darstellung verwaltet hat, so weit wie möglich respektiert.

Deshalb wurden die Touch-Steuerelemente mit den eigenen Systemen des Spiels und den originalen Werkzeugen integriert, die die Engine zum Zeichnen von Bildschirmelementen verwendet hat. Dadurch entsteht eine deutlich stabilere, sauberere und stimmigere Spielerfahrung, mit der bestmöglichen Performance und einer viel engeren Verbindung zur internen Logik des Spiels.

Im Update **0.87.4** wurde die Minikarte des Spiels verschoben, um Nutzern, die mit Touch-Steuerung spielen, ein besseres Spielerlebnis zu bieten. Die Position der Symbole überlappt nun nicht mehr mit der Minikarte, wie es in früheren Versionen der Fall war.

## ✨ Manuell gestaltete Symbole

Alle Touch-Symbole wurden von mir mit **GIMP** gestaltet. Dabei wurde darauf geachtet, dass sie optisch zum Stil des Spiels passen und während des Spielens klar erkennbar bleiben.

Die Idee war nicht einfach, ein paar Buttons auf den Bildschirm zu setzen, sondern eine angenehme, verständliche und komfortable Touch-Oberfläche zu schaffen, die speziell für Android-Geräte entwickelt wurde.

Jedes Symbol wurde mit einem Gleichgewicht aus Sichtbarkeit, Stil und Bedienkomfort vorbereitet, damit der Spieler jede Aktion schnell versteht, ohne dass die visuelle Persönlichkeit des Spiels verloren geht.

## 🧠 Intelligente Steuerung je nach Kontext

Die neuen Touch-Steuerelemente sind intelligent und erkennen, in welcher Spielsituation sich der Spieler gerade befindet.

Das System wechselt automatisch zwischen verschiedenen Layouts:

* **Menü**
* **Zu Fuß**
* **Im Fahrzeug**

Das bedeutet, dass die Steuerung nicht statisch ist und nicht immer auf die gleiche Weise angezeigt wird. Das Spiel passt das Touch-Layout daran an, was gerade auf dem Bildschirm passiert.

Wenn der Spieler zu Fuß unterwegs ist, kann das System außerdem spezielle Symbole für die verschiedenen Aktionen anzeigen, die die Figur ausführen kann. Dadurch wirkt die Steuerung klarer, natürlicher und angenehmer.

So wird verhindert, dass der Bildschirm mit unnötigen Buttons überladen wird. Stattdessen erscheinen nur die Steuerelemente, die im jeweiligen Moment wirklich sinnvoll sind.

## 🎮 Integration wie ein echter Controller

Einer der wichtigsten Punkte dieser Version ist, dass die Touch-Steuerung nicht wie eine schnelle externe Notlösung funktioniert. Sie wurde so integriert, als wäre sie ein **echter Controller innerhalb des eigenen Eingabesystems des Spiels**.

Dadurch kann das Spiel viel natürlicher mit den Touch-Eingaben arbeiten und gleichzeitig sein ursprüngliches Input-System besser respektieren.

Der Port kann außerdem erkennen, ob ein physischer Controller verbunden ist. Wenn der Spieler einen Controller verbindet, kann das Touch-Layout automatisch ausgeblendet werden. Wenn kein Controller verfügbar ist, erscheinen die Touch-Symbole, damit das Spiel bequem über den Bildschirm gespielt werden kann.

Das macht die Erfahrung deutlich flexibler: Man kann jederzeit mit Touch-Steuerung spielen, aber auch einen physischen Controller verwenden, ohne dass die Touch-Oberfläche auf dem Bildschirm stört.

## ⚙️ Touch-Kompatibilitätsdatei: Simpsons_touch_mode.txt

Aufgrund technischer Unterschiede zwischen Android-Geräten können manche Smartphones Touch-Koordinaten unterschiedlich normalisieren.

Um die bestmögliche Kompatibilität zu bieten, habe ich eine Datei hinzugefügt:

```txt
Simpsons_touch_mode.txt
```

Diese Datei befindet sich im folgenden Pfad:

```txt
Android/data/com.c4rlox.simpsons/touch_controls/Simpsons_touch_mode.txt
```

Standardmäßig verwendet das Spiel **Modus 1**, der auf den meisten Geräten korrekt funktionieren sollte.

Falls du jedoch bemerkst, dass die Touch-Steuerung auf deinem Gerät nicht richtig reagiert, dass Berührungen nicht exakt mit den Button-Positionen übereinstimmen oder dass sich der Touch-Bereich verschoben anfühlt, kannst du über diese Datei auf **Modus 2** wechseln.

Dieses System wurde hinzugefügt, damit mehr Geräte die Touch-Steuerung korrekt nutzen können, selbst wenn Android oder das jeweilige Gerät Touch-Koordinaten auf eine andere Weise verarbeitet.

Zusammengefasst:

* **Modus 1**: Standardmodus, empfohlen für die meisten Geräte.
* **Modus 2**: alternativer Kompatibilitätsmodus, falls Modus 1 auf deinem Gerät nicht korrekt funktioniert.

## 🚀 Eine wichtige Verbesserung für Android

Dieses Update ist ein großer Schritt, um den Port auf Android zugänglicher, komfortabler und angenehmer spielbar zu machen.

Version **0.87** fügt nicht einfach nur Buttons auf dem Bildschirm hinzu: Sie führt eine deutlich durchdachtere Touch-Architektur ein, die so sauber wie möglich mit dem Spiel integriert wurde und eine wirklich komfortable Erfahrung bietet.

Tatsächlich fühlt sich das Ergebnis so natürlich an, dass es in manchen Momenten genauso angenehm wie ein klassischer Controller sein kann, vielleicht sogar noch angenehmer. Ich meine das völlig ernst: Es lohnt sich wirklich, es auszuprobieren.
