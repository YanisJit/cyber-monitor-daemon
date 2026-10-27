TP Cyber - Compilation C, Systemd et paquet Debian

Projet de TP pour tester la chaîne de compilation C, la création d'un service Systemd et la simulation d'une persistance via un paquet Debian (MITRE ATT&CK T1543.002).

Arborescence du projet :

cyber-monitor-daemon/
- src/
  - cyber_daemon.c
- systemd/
  - cyber_monitor.service
- debian-package/
  - paquet-cyber/
    - DEBIAN/
      - control
      - postinst
    - etc/
      - systemd/
        - system/
          - cyber_monitor.service
    - usr/
      - local/
        - bin/
          - cyber_daemon

Étapes réalisées :

1. Compilation en C avec GCC
Création d'un petit démon en C (cyber_daemon.c) qui tourne en continu et affiche un log toutes les 5 secondes.
Test des 4 étapes de compilation :
- Option -E : préprocesseur pour inclure stdio.h et unistd.h.
- Option -S : passage en langage assembleur.
- Option -c : création du fichier objet binaire (.o).
- Édition de liens avec GCC pour sortir l'exécutable cyber_daemon.

2. Persistance avec Systemd
- Placement du binaire dans /usr/local/bin/.
- Écriture du fichier /etc/systemd/system/cyber_monitor.service avec Restart=always.
- Lecture des logs dans le terminal avec journalctl -u cyber_monitor.service -f.

3. Packaging Debian et script postinst
- Création des dossiers du paquet et du fichier DEBIAN/control.
- Écriture du script DEBIAN/postinst qui s'exécute en root pendant l'installation.
- Le script fait un systemctl daemon-reload et active le service avec systemctl enable --now sans action de l'utilisateur.
- Build du fichier .deb avec la commande dpkg-deb.

Test final :
Après avoir nettoyé le service à la main, l'installation avec sudo dpkg -i cyber-monitor.deb réinstalle le fichier, réactive le service Systemd et le relance en arrière-plan.
