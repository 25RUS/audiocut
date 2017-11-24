Summary:	Graphical .flac .ape .wav splitter
Name:		audiocut	
Version:	1.0
Release:	1
License:	GPLv3
Group:		Sound 
Url:		https://github.com/25RUS/audiocut
Source0:	%{name}-%{version}.tar.bz2
BuildRequires:  cmake
BuildRequires:  qt5-devel
BuildRequires:	pkgconfig(Qt5Core)
BuildRequires:	pkgconfig(Qt5DBus)
BuildRequires:	pkgconfig(Qt5Gui)
BuildRequires:	pkgconfig(Qt5Widgets)

Requires: shntool
Requires: flac
Requires: wavpack

%description
audiocut is graphical interface for shntool

%files
%{_bindir}/%{name}
%{_datadir}/applications/%{name}.desktop
%{_datadir}/pixmaps/%{name}.png
%doc doc/LICENSE doc/README.md

#------------------------------------------------------------------

%prep
%setup -q

%build
%cmake_qt5
%make

%install
%makeinstall_std -C build

mkdir -p %{buildroot}%{_datadir}/applications
cat > %{buildroot}%{_datadir}/applications/%{name}.desktop << EOF
[Desktop Entry]
Type=Application
Name=AudioCut
Comment=AudioCut is GUI for shntool
Exec=%{name}
Icon=%{name}
StartupNotify=false
Terminal=false
Categories=AudioVideo;Player;Qt;Audio;
EOF

# icon file
mkdir -p %{buildroot}%{_datadir}/pixmaps
install -m644 %{name}.png %{buildroot}%{_datadir}/pixmaps/






