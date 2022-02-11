static inline int F_1 ( char * V_1 , const char * V_2 ) {
return ! strncmp ( V_1 , V_2 , strlen ( V_2 ) ) ;
}
static struct V_3 F_2 ( char * V_4 , int V_5 ) {
struct V_3 V_3 ;
int V_6 ;
#ifdef F_3
T_1 * V_7 ;
if ( V_5 == V_8 )
V_6 = V_9 ;
else if ( V_5 == V_10 )
V_6 = V_11 ;
else if ( V_5 == V_12 )
V_6 = V_13 ;
else {
if ( V_14 )
F_4 ( V_15 , L_1 ) ;
exit ( 1 ) ;
}
V_7 = F_5 ( V_6 , V_16 , V_17 ) ;
V_3 . V_18 . V_7 = F_6 ( V_7 , V_4 ) ;
if ( ! V_3 . V_18 . V_7 ) {
if ( V_14 )
F_4 ( V_15 , L_2 ) ;
exit ( 1 ) ;
}
V_3 . V_5 = V_5 ;
F_7 ( V_3 . V_18 . V_7 ) ;
#else
int V_19 = 0 ;
if ( V_5 == V_8 )
V_6 = V_20 ;
else if ( V_5 == V_10 )
V_6 = V_21 ;
else if ( V_5 == V_12 )
V_6 = V_22 ;
else {
if ( V_14 )
F_4 ( V_15 , L_1 ) ;
exit ( 1 ) ;
}
V_3 . V_18 . V_23 = F_8 ( V_4 , V_24 , V_6 , V_16 , FALSE , & V_19 ) ;
if ( ! V_3 . V_18 . V_23 ) {
if ( V_14 )
F_4 ( V_15 , L_2 ) ;
exit ( 1 ) ;
}
V_3 . V_5 = V_5 ;
F_9 ( V_3 . V_18 . V_23 ) ;
#endif
return V_3 ;
}
static void F_10 ( struct V_3 V_3 , char * V_25 ,
T_2 V_26 , T_2 V_27 ,
T_3 V_28 , int V_29 ) {
#ifdef F_3
struct V_30 V_31 ;
V_31 . V_32 = ( V_33 ) V_26 ;
V_31 . V_34 = ( V_33 ) V_27 ;
V_31 . V_35 . V_36 = V_28 ;
V_31 . V_35 . V_37 = V_29 / 1000 ;
F_11 ( ( V_38 * ) V_3 . V_18 . V_7 , & V_31 , V_25 ) ;
F_7 ( V_3 . V_18 . V_7 ) ;
#else
int V_19 = 0 ;
char * V_39 ;
struct V_40 V_41 ;
V_41 . V_42 = V_43 ;
V_41 . V_32 = ( V_44 ) V_26 ;
V_41 . V_34 = ( V_44 ) V_27 ;
V_41 . V_35 . V_45 = V_28 ;
V_41 . V_35 . V_46 = ( int ) V_29 ;
V_41 . V_47 = 0 ;
V_41 . V_47 = NULL ;
V_41 . V_48 = 0 ;
V_41 . V_49 = 0 ;
V_41 . V_50 = V_51 ;
if ( V_3 . V_5 == V_8 ) {
T_4 * V_52 ;
F_12 (direction, value_u32, buffer)
V_41 . V_53 . V_54 . V_55 = F_13 ( * V_52 ) ? 0 : 1 ;
V_41 . V_34 -= ( V_44 ) sizeof( V_56 ) ;
V_41 . V_32 -= ( V_44 ) sizeof( V_56 ) ;
V_25 += sizeof( V_56 ) ;
V_41 . V_57 = V_20 ;
}
else if ( V_3 . V_5 == V_12 ) {
V_41 . V_57 = V_22 ;
}
else {
V_41 . V_57 = V_21 ;
}
F_14 ( V_3 . V_18 . V_23 , & V_41 , ( const V_58 * ) V_25 , & V_19 , & V_39 ) ;
F_9 ( V_3 . V_18 . V_23 ) ;
#endif
}
static T_5 F_15 ( const char * V_59 , unsigned short * V_60 ) {
T_5 V_61 ;
T_6 V_62 ;
struct V_63 V_64 ;
memset ( & V_64 , 0x0 , sizeof( V_64 ) ) ;
V_64 . V_65 = V_66 ;
V_64 . V_67 = F_16 ( * V_60 ) ;
V_64 . V_68 . V_69 = F_17 ( V_59 ) ;
if ( ( V_61 = F_18 ( V_66 , V_70 , V_71 ) ) == V_72 ) {
if ( V_14 )
F_4 ( V_15 , L_3 , strerror ( V_73 ) ) ;
return V_72 ;
}
if ( F_19 ( V_61 , (struct V_74 * ) & V_64 , sizeof( V_64 ) ) == V_75 ) {
#if 0
#ifdef F_20
if (_execlp("adb", "adb", "start-server", NULL)) {
#else
if (execlp("adb", "adb", "start-server", NULL)) {
#endif
if (verbose)
g_fprintf(stderr, "WARNING: Cannot execute system command to start adb: %s\n", strerror(errno));
closesocket(sock);
return INVALID_SOCKET;
};
if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == SOCKET_ERROR) {
if (verbose)
g_fprintf(stderr, "ERROR: Cannot connect to ADB: <%s> Please check that adb daemon is running.\n", strerror(errno));
closesocket(sock);
return INVALID_SOCKET;
}
#else
if ( V_14 ) {
F_4 ( V_15 , L_4 , strerror ( V_73 ) ) ;
}
F_21 ( V_61 ) ;
return V_72 ;
#endif
}
if ( V_14 ) {
struct V_63 V_76 ;
V_62 = sizeof( V_76 ) ;
if ( F_22 ( V_61 , (struct V_74 * ) & V_76 , & V_62 ) ) {
F_4 ( V_15 , L_5 , strerror ( V_73 ) ) ;
F_21 ( V_61 ) ;
return V_72 ;
}
if ( V_62 != sizeof( V_76 ) ) {
F_4 ( V_15 , L_6 ) ;
F_21 ( V_61 ) ;
return V_72 ;
}
F_4 ( V_15 , L_7 , F_23 ( V_76 . V_67 ) ) ;
}
return V_61 ;
}
static char * F_24 ( T_5 V_61 , const char * V_77 ,
char * V_25 , int V_78 , T_2 * V_79 ) {
T_2 V_80 ;
T_2 V_62 ;
T_2 V_81 ;
char V_82 [ 4 ] ;
char V_83 ;
V_81 = F_25 ( V_61 , V_77 , ( int ) strlen ( V_77 ) , 0 ) ;
if ( V_81 != ( T_2 ) strlen ( V_77 ) ) {
if ( V_14 )
F_4 ( V_15 , L_8 , V_77 ) ;
if ( V_79 )
* V_79 = 0 ;
return 0 ;
}
V_80 = 0 ;
while ( V_80 < 8 ) {
V_80 += F_26 ( V_61 , V_25 + V_80 , ( int ) ( V_78 - V_80 ) , 0 ) ;
}
memcpy ( V_82 , V_25 , 4 ) ;
V_83 = V_25 [ 8 ] ;
V_25 [ 8 ] = '\0' ;
V_62 = ( T_2 ) F_27 ( V_25 + 4 , NULL , 16 ) ;
V_25 [ 8 ] = V_83 ;
while ( V_80 < V_62 + 8 ) {
V_80 += F_26 ( V_61 , V_25 + V_80 , ( int ) ( V_78 - V_80 ) , 0 ) ;
}
if ( V_79 )
* V_79 = V_80 - 8 ;
if ( memcmp ( V_82 , L_9 , 4 ) ) {
if ( V_14 )
F_4 ( V_15 , L_10 , V_77 ) ;
if ( V_79 )
* V_79 = 0 ;
return 0 ;
}
return V_25 + 8 ;
}
static char * F_28 ( T_5 V_61 , const char * V_77 , char * V_25 ,
int V_78 , T_2 * V_79 ) {
T_2 V_80 ;
T_2 V_81 ;
char V_82 [ 4 ] ;
V_81 = F_25 ( V_61 , V_77 , ( int ) strlen ( V_77 ) , 0 ) ;
if ( V_81 != ( T_2 ) strlen ( V_77 ) ) {
if ( V_14 )
F_4 ( V_15 , L_8 , V_77 ) ;
if ( V_79 )
* V_79 = 0 ;
return 0 ;
}
V_80 = 0 ;
while ( V_80 < 4 ) {
V_80 += F_26 ( V_61 , V_25 + V_80 , ( int ) ( V_78 - V_80 ) , 0 ) ;
}
memcpy ( V_82 , V_25 , 4 ) ;
while ( V_81 > 0 ) {
V_81 = F_26 ( V_61 , V_25 + V_80 , ( int ) ( V_78 - V_80 ) , 0 ) ;
if ( V_81 > 0 )
V_80 += V_81 ;
}
if ( V_79 )
* V_79 = V_80 - 4 ;
if ( memcmp ( V_82 , L_9 , 4 ) ) {
if ( V_14 )
F_4 ( V_15 , L_10 , V_77 ) ;
if ( V_79 )
* V_79 = 0 ;
return 0 ;
}
return V_25 + 4 ;
}
static int F_29 ( T_5 V_61 , const char * V_77 ) {
char V_25 [ 4 ] ;
T_2 V_80 ;
T_2 V_81 ;
V_81 = F_25 ( V_61 , V_77 , ( int ) strlen ( V_77 ) , 0 ) ;
if ( V_81 != ( T_2 ) strlen ( V_77 ) ) {
if ( V_14 )
F_4 ( V_15 , L_8 , V_77 ) ;
return 1 ;
}
V_80 = 0 ;
while ( V_80 < 4 ) {
V_80 += F_26 ( V_61 , V_25 + V_80 , ( int ) ( sizeof( V_25 ) - V_80 ) , 0 ) ;
}
if ( memcmp ( V_25 , L_9 , 4 ) ) {
if ( V_14 )
F_4 ( V_15 , L_10 , V_77 ) ;
return 2 ;
}
return 0 ;
}
static int F_30 ( struct V_84 * * V_85 ,
const char * V_86 , unsigned short * V_87 )
{
static char V_88 [ V_16 ] ;
static char V_89 [ V_16 ] ;
char * V_90 ;
char * V_91 ;
T_2 V_79 ;
T_2 V_92 ;
T_5 V_61 ;
const char * V_93 = L_11 V_94 : V_95 : % V_96 L_12 % 04x L_13 V_97 : V_98 / V_99 / % V_96 / V_100 / V_101 L_14 000C L_13 V_94 : V_102 L_15 0022 L_13 V_97 : V_103 V_104 . V_105 . V_106 . V_107 L_16 0017 L_13 V_97 : V_108 -- V_106 L_17 0018 L_13 V_97 : V_109 V_110 . V_111 L_18 0010 L_13 V_97 : V_112 - V_113 L_19 V_114 V_102 L_20 V_114 V_97 L_21 V_115 : V_116 V_117 V_118 long , V_119 V_120\V_121");
continue;
}
memcpy(serial_number, prev_pos, result);
serial_number[result] = '\0';
/* Check for the presence of tcpdump in the android device. */
sock = adb_connect(adb_server_ip, adb_server_tcp_port);
if (sock == INVALID_SOCKET) continue;
sprintf((char *) helpful_packet, adb_transport_serial_templace, 15 + strlen(serial_number), serial_number);
result = adb_send(sock, helpful_packet);
if (result) {
if (verbose)
g_fprintf(stderr, "ERROR : Error while setting adb transport for <%s>\n", helpful_packet);
closesocket(sock);
return 1;
}
response = adb_send_and_read(sock, adb_tcpdump_help, helpful_packet, sizeof(helpful_packet), &data_length);
closesocket(sock);
response[data_length] = '\0';
/* If tcpdump is found in the android device, add Android Wifi Tcpdump as an interface */
if (strstr(response,"tcpdump version")) {
interface_name = (char *) malloc(strlen(INTERFACE_ANDROID_WIFI_TCPDUMP) + 1 + strlen(serial_number) + 1);
interface_name[0]= '\0';
strcat(interface_name, INTERFACE_ANDROID_WIFI_TCPDUMP);
strcat(interface_name, "-");
strcat(interface_name, serial_number);
if (*interface_list == NULL) {
i_interface_list = (struct interface_t *) malloc(sizeof(struct interface_t));
*interface_list = i_interface_list;
} else {
i_interface_list->next = (struct interface_t *) malloc(sizeof(struct interface_t));
i_interface_list = i_interface_list->next;
}
i_interface_list->display_name = "Android WiFi";
i_interface_list->interface_name = interface_name;
i_interface_list->next = NULL;
}
sock = adb_connect(adb_server_ip, adb_server_tcp_port);
sprintf((char *) helpful_packet, adb_transport_serial_templace, 15 + strlen(serial_number), serial_number);
result = adb_send(sock, helpful_packet);
if (result) {
if (verbose)
g_fprintf(stderr, "ERROR: Error while setting adb transport for <%s>\n", helpful_packet);
closesocket(sock);
return 1;
}
response = adb_send_and_read(sock, adb_api_level, helpful_packet, sizeof(helpful_packet), &data_length);
closesocket(sock);
response[data_length] = '\0';
api_level = (int) g_ascii_strtoll(response, NULL, 10);
if (verbose)
g_fprintf(stderr, "VERBOSE: Android API Level for %s is %i\n", serial_number, api_level);
if (api_level < 21) {
interface_name = (char *) malloc(strlen(INTERFACE_ANDROID_LOGCAT_MAIN) + 1 + strlen(serial_number) + 1);
interface_name[0]= '\0';
strcat(interface_name, INTERFACE_ANDROID_LOGCAT_MAIN);
strcat(interface_name, "-");
strcat(interface_name, serial_number);
if (*interface_list == NULL) {
i_interface_list = (struct interface_t *) malloc(sizeof(struct interface_t));
*interface_list = i_interface_list;
} else {
i_interface_list->next = (struct interface_t *) malloc(sizeof(struct interface_t));
i_interface_list = i_interface_list->next;
}
i_interface_list->display_name = "Android Logcat Main";
i_interface_list->interface_name = interface_name;
i_interface_list->next = NULL;
interface_name = (char *) malloc(strlen(INTERFACE_ANDROID_LOGCAT_SYSTEM) + 1 + strlen(serial_number) + 1);
interface_name[0]= '\0';
strcat(interface_name, INTERFACE_ANDROID_LOGCAT_SYSTEM);
strcat(interface_name, "-");
strcat(interface_name, serial_number);
i_interface_list->next = (struct interface_t *) malloc(sizeof(struct interface_t));
i_interface_list = i_interface_list->next;
i_interface_list->display_name = "Android Logcat System";
i_interface_list->interface_name = interface_name;
i_interface_list->next = NULL;
interface_name = (char *) malloc(strlen(INTERFACE_ANDROID_LOGCAT_RADIO) + 1 + strlen(serial_number) + 1);
interface_name[0]= '\0';
strcat(interface_name, INTERFACE_ANDROID_LOGCAT_RADIO);
strcat(interface_name, "-");
strcat(interface_name, serial_number);
i_interface_list->next = (struct interface_t *) malloc(sizeof(struct interface_t));
i_interface_list = i_interface_list->next;
i_interface_list->display_name = "Android Logcat Radio";
i_interface_list->interface_name = interface_name;
i_interface_list->next = NULL;
interface_name = (char *) malloc(strlen(INTERFACE_ANDROID_LOGCAT_EVENTS) + 1 + strlen(serial_number) + 1);
interface_name[0]= '\0';
strcat(interface_name, INTERFACE_ANDROID_LOGCAT_EVENTS);
strcat(interface_name, "-");
strcat(interface_name, serial_number);
i_interface_list->next = (struct interface_t *) malloc(sizeof(struct interface_t));
i_interface_list = i_interface_list->next;
i_interface_list->display_name = "Android Logcat Events";
i_interface_list->interface_name = interface_name;
i_interface_list->next = NULL;
} else {
interface_name = (char *) malloc(strlen(INTERFACE_ANDROID_LOGCAT_TEXT_MAIN) + 1 + strlen(serial_number) + 1);
interface_name[0]= '\0';
strcat(interface_name, INTERFACE_ANDROID_LOGCAT_TEXT_MAIN);
strcat(interface_name, "-");
strcat(interface_name, serial_number);
if (*interface_list == NULL) {
i_interface_list = (struct interface_t *) malloc(sizeof(struct interface_t));
*interface_list = i_interface_list;
} else {
i_interface_list->next = (struct interface_t *) malloc(sizeof(struct interface_t));
i_interface_list = i_interface_list->next;
}
i_interface_list->display_name = "Android Logcat Main";
i_interface_list->interface_name = interface_name;
i_interface_list->next = NULL;
interface_name = (char *) malloc(strlen(INTERFACE_ANDROID_LOGCAT_TEXT_SYSTEM) + 1 + strlen(serial_number) + 1);
interface_name[0]= '\0';
strcat(interface_name, INTERFACE_ANDROID_LOGCAT_TEXT_SYSTEM);
strcat(interface_name, "-");
strcat(interface_name, serial_number);
i_interface_list->next = (struct interface_t *) malloc(sizeof(struct interface_t));
i_interface_list = i_interface_list->next;
i_interface_list->display_name = "Android Logcat System";
i_interface_list->interface_name = interface_name;
i_interface_list->next = NULL;
interface_name = (char *) malloc(strlen(INTERFACE_ANDROID_LOGCAT_TEXT_RADIO) + 1 + strlen(serial_number) + 1);
interface_name[0]= '\0';
strcat(interface_name, INTERFACE_ANDROID_LOGCAT_TEXT_RADIO);
strcat(interface_name, "-");
strcat(interface_name, serial_number);
i_interface_list->next = (struct interface_t *) malloc(sizeof(struct interface_t));
i_interface_list = i_interface_list->next;
i_interface_list->display_name = "Android Logcat Radio";
i_interface_list->interface_name = interface_name;
i_interface_list->next = NULL;
interface_name = (char *) malloc(strlen(INTERFACE_ANDROID_LOGCAT_TEXT_EVENTS) + 1 + strlen(serial_number) + 1);
interface_name[0]= '\0';
strcat(interface_name, INTERFACE_ANDROID_LOGCAT_TEXT_EVENTS);
strcat(interface_name, "-");
strcat(interface_name, serial_number);
i_interface_list->next = (struct interface_t *) malloc(sizeof(struct interface_t));
i_interface_list = i_interface_list->next;
i_interface_list->display_name = "Android Logcat Events";
i_interface_list->interface_name = interface_name;
i_interface_list->next = NULL;
interface_name = (char *) malloc(strlen(INTERFACE_ANDROID_LOGCAT_TEXT_CRASH) + 1 + strlen(serial_number) + 1);
interface_name[0]= '\0';
strcat(interface_name, INTERFACE_ANDROID_LOGCAT_TEXT_CRASH);
strcat(interface_name, "-");
strcat(interface_name, serial_number);
i_interface_list->next = (struct interface_t *) malloc(sizeof(struct interface_t));
i_interface_list = i_interface_list->next;
i_interface_list->display_name = "Android Logcat Crash";
i_interface_list->interface_name = interface_name;
i_interface_list->next = NULL;
}
if (api_level >= 5 && api_level < 17) {
disable_interface = 0;
sock = adb_connect(adb_server_ip, adb_server_tcp_port);
if (sock == INVALID_SOCKET) continue;
sprintf((char *) helpful_packet, adb_transport_serial_templace, 15 + strlen(serial_number), serial_number);
result = adb_send(sock, helpful_packet);
if (result) {
if (verbose)
g_fprintf(stderr, "ERROR: Error while setting adb transport for <%s>\n", helpful_packet);
closesocket(sock);
return 1;
}
response = adb_send_and_read(sock, adb_hcidump_version, helpful_packet, sizeof(helpful_packet), &data_length);
closesocket(sock);
if (!response || data_length < 1) {
if (verbose) {
g_fprintf(stderr, "WARNING: Error while getting hcidump version by <%s> ( % V_122 V_34 = % L_22 ) \ V_121 L_23 V_123 : V_124 V_108 V_106 for %s is unknown\n", serial_number);
}
disable_interface = 1;
} else {
response[data_length] = '\0';
if (g_ascii_strtoull(response, NULL, 10) == 0) {
if (verbose)
g_fprintf(stderr, "VERBOSE: Android hcidump version for %s is unknown\n", serial_number);
disable_interface = 1;
} else {
if (verbose)
g_fprintf(stderr, "VERBOSE: Android hcidump version for %s is %s\n", serial_number, response);
}
}
if (!disable_interface) {
interface_name = (char *) malloc(strlen(INTERFACE_ANDROID_BLUETOOTH_HCIDUMP) + 1 + strlen(serial_number) + 1);
interface_name[0]= '\0';
strcat(interface_name, INTERFACE_ANDROID_BLUETOOTH_HCIDUMP);
strcat(interface_name, "-");
strcat(interface_name, serial_number);
i_interface_list->next = (struct interface_t *) malloc(sizeof(struct interface_t));
i_interface_list = i_interface_list->next;
i_interface_list->display_name = "Android Bluetooth Hcidump";
i_interface_list->interface_name = interface_name;
i_interface_list->next = NULL;
}
}
if (api_level >= 17 && api_level < 21) {
disable_interface = 0;
sock = adb_connect(adb_server_ip, adb_server_tcp_port);
if (sock == INVALID_SOCKET) continue;
sprintf((char *) helpful_packet, adb_transport_serial_templace, 15 + strlen(serial_number), serial_number);
result = adb_send(sock, helpful_packet);
if (result) {
if (verbose)
g_fprintf(stderr, "ERROR: Error while setting adb transport for <%s>\n", helpful_packet);
closesocket(sock);
return 1;
}
response = adb_send_and_read(sock, adb_ps_droid_bluetooth, helpful_packet, sizeof(helpful_packet), &data_length);
closesocket(sock);
if (!response || data_length < 1) {
if (verbose) {
g_fprintf(stderr, "WARNING: Error while getting Bluetooth application process id by <%s> ( % V_122 V_34 = % L_22 ) \ V_121 L_23 V_123 : V_124 V_125 V_126 V_127 for %s is unknown\n", serial_number);
}
disable_interface = 1;
} else {
char *data_str;
char pid[16];
response[data_length] = '\0';
data_str = strchr(response, '\n');
if (data_str && sscanf(data_str, "%*s %s", pid) == 1) {
if (verbose)
g_fprintf(stderr, "VERBOSE: Android Bluetooth application PID for %s is %s\n", serial_number, pid);
sock = adb_connect(adb_server_ip, adb_server_tcp_port);
sprintf((char *) helpful_packet, adb_transport_serial_templace, 15 + strlen(serial_number), serial_number);
result = adb_send(sock, helpful_packet);
if (result) {
if (verbose)
g_fprintf(stderr, "ERROR: Error while setting adb transport for <%s>\n", helpful_packet);
closesocket(sock);
return 1;
}
sprintf((char *) helpful_packet, adb_check_port_templace, strlen(adb_check_port_templace) - 6 + strlen(pid), pid);
response = adb_send_and_read(sock, helpful_packet, helpful_packet, sizeof(helpful_packet), &data_length);
response[data_length] = '\0';
closesocket(sock);
data_str = strchr(response, '\n');
if (data_str && sscanf(data_str, "%*s %s", pid) == 1 && strcmp(pid + 9, "10EA") == 0) {
if (verbose)
g_fprintf(stderr, "VERBOSE: Bluedroid External Parser Port for %s is %s\n", serial_number, pid + 9);
} else {
disable_interface = 1;
if (verbose)
g_fprintf(stderr, "VERBOSE: Bluedroid External Parser Port for %s is unknown\n", serial_number);
}
} else {
disable_interface = 1;
if (verbose)
g_fprintf(stderr, "VERBOSE: Android Bluetooth application PID for %s is unknown\n", serial_number);
}
}
if (!disable_interface) {
interface_name = (char *) malloc(strlen(INTERFACE_ANDROID_BLUETOOTH_EXTERNAL_PARSER) + 1 + strlen(serial_number) + 1);
interface_name[0]= '\0';
strcat(interface_name, INTERFACE_ANDROID_BLUETOOTH_EXTERNAL_PARSER);
strcat(interface_name, "-");
strcat(interface_name, serial_number);
i_interface_list->next = (struct interface_t *) malloc(sizeof(struct interface_t));
i_interface_list = i_interface_list->next;
i_interface_list->display_name = "Android Bluetooth External Parser";
i_interface_list->interface_name = interface_name;
i_interface_list->next = NULL;
}
}
if (api_level >= 21) {
disable_interface = 0;
sock = adb_connect(adb_server_ip, adb_server_tcp_port);
if (sock == INVALID_SOCKET) continue;
sprintf((char *) helpful_packet, adb_transport_serial_templace, 15 + strlen(serial_number), serial_number);
result = adb_send(sock, helpful_packet);
if (result) {
if (verbose)
g_fprintf(stderr, "ERROR: Error while setting adb transport for <%s>\n", helpful_packet);
closesocket(sock);
return 1;
}
response = adb_send_and_read(sock, adb_ps_droid_bluetooth, helpful_packet, sizeof(helpful_packet), &data_length);
closesocket(sock);
if (!response || data_length < 1) {
if (verbose) {
g_fprintf(stderr, "WARNING: Error while getting Bluetooth application process id by <%s> ( % V_122 V_34 = % L_22 ) \ V_121 L_23 V_123 : V_124 V_125 V_126 V_127 for %s is unknown\n", serial_number);
}
disable_interface = 1;
} else {
char *data_str;
char pid[16];
response[data_length] = '\0';
data_str = strchr(response, '\n');
if (data_str && sscanf(data_str, "%*s %s", pid) == 1) {
if (verbose)
g_fprintf(stderr, "VERBOSE: Android Bluetooth application PID for %s is %s\n", serial_number, pid);
sock = adb_connect(adb_server_ip, adb_server_tcp_port);
sprintf((char *) helpful_packet, adb_transport_serial_templace, 15 + strlen(serial_number), serial_number);
result = adb_send(sock, helpful_packet);
if (result) {
if (verbose)
g_fprintf(stderr, "ERROR: Error while setting adb transport for <%s>\n", helpful_packet);
closesocket(sock);
return 1;
}
sprintf((char *) helpful_packet, adb_check_port_templace, strlen(adb_check_port_templace) - 6 + strlen(pid), pid);
response = adb_send_and_read(sock, helpful_packet, helpful_packet, sizeof(helpful_packet), &data_length);
response[data_length] = '\0';
closesocket(sock);
data_str = strchr(response, '\n');
if (data_str && sscanf(data_str, "%*s %s", pid) == 1 && strcmp(pid + 9, "22A8") == 0) {
if (verbose)
g_fprintf(stderr, "VERBOSE: Btsnoop Net Port for %s is %s\n", serial_number, pid + 9);
} else {
disable_interface = 1;
if (verbose)
g_fprintf(stderr, "VERBOSE: Btsnoop Net Port for %s is unknown\n", serial_number);
}
} else {
disable_interface = 1;
if (verbose)
g_fprintf(stderr, "VERBOSE: Android Bluetooth application PID for %s is unknown\n", serial_number);
}
}
if (!disable_interface) {
interface_name = (char *) malloc(strlen(INTERFACE_ANDROID_BLUETOOTH_BTSNOOP_NET) + 1 + strlen(serial_number) + 1);
interface_name[0]= '\0';
strcat(interface_name, INTERFACE_ANDROID_BLUETOOTH_BTSNOOP_NET);
strcat(interface_name, "-");
strcat(interface_name, serial_number);
i_interface_list->next = (struct interface_t *) malloc(sizeof(struct interface_t));
i_interface_list = i_interface_list->next;
i_interface_list->display_name = "Android Bluetooth Btsnoop Net";
i_interface_list->interface_name = interface_name;
i_interface_list->next = NULL;
}
}
}
return 0;
}
static int list_interfaces(const char *server_ip, unsigned short *server_tcp_port) {
struct interface_t *interface_list = NULL;
struct interface_t *i_interface;
int result;
result = add_android_interfaces(&interface_list, server_ip, server_tcp_port);
for (i_interface = interface_list; i_interface; i_interface = i_interface->next)
g_printf("interface { V_128 = % V_96 } { V_129 = % V_96 } \ V_121 L_24 ERROR : V_130 V_1 V_131 . \V_121 L_25 V_132 { V_117 = 99 } { V_133 = V_134 } { V_128 = V_125 V_135 V_136 V_95 V_137 V_138 V_139 - V_140 } \ V_121 L_26 V_132 { V_117 = 252 } { V_133 = V_141 V_142 } { V_128 = V_141 V_142 } \ V_121 L_27 V_132 { V_117 = 1 } { V_133 = V_143 } { V_128 = V_143 } \ V_121 L_28 ERROR : V_144 V_1 : < % V_96 > \ V_121 L_29 ERROR : V_130 V_1 V_131 . \V_121 L_30 V_145 { V_117 = 0 } { V_146 = -- V_114 - V_64 - V_147 } { V_128 = V_148 V_149 V_150 V_151 } { type = string } {default= 127.0.0.1 } \ V_121 L_31 V_145 { V_117 = 1 } { V_146 = -- V_114 - V_64 - V_101 - V_152 } { V_128 = V_148 V_149 V_153 V_154 } { type = integer } { V_155 = 0 , 65535 } {default= 5037 } \ V_121 L_31 V_145 { V_117 = 2 } { V_146 = -- V_156 - V_64 - V_101 - V_152 } { V_128 = V_125 V_149 V_153 V_154 } { type = integer } { V_155 = 0 , 65535 } {default= 4330 } \ V_121 L_31 V_145 { V_117 = 3 } { V_146 = -- V_156 - V_157 - F_18 } { V_128 = V_158 V_125 V_159 } { type = boolean } {default= false } \ V_121 L_31 V_145 { V_117 = 4 } { V_146 = -- V_156 - V_160 - V_147 } { V_128 = V_125 V_161 V_150 V_151 } { type = string } {default= 127.0.0.1 } \ V_121 L_31 V_145 { V_117 = 5 } { V_146 = -- V_156 - V_160 - V_101 - V_152 } { V_128 = V_125 V_161 V_153 V_154 } { type = integer } { V_155 = 0 , 65535 } {default= 4330 } { V_162 = V_163 V_164 do \ L_32
L_33 ) ;
return 0 ;
}
void F_31 ( void ) {
unsigned int V_165 ;
F_32 ( L_34 ) ;
F_32 ( L_35
L_36
L_37
L_38
L_39 ) ;
F_32 ( L_40 ) ;
for ( V_165 = 0 ; V_165 < ( sizeof( V_166 ) / sizeof( V_166 [ 0 ] ) ) - 1 ; V_165 += 1 ) {
F_32 ( L_41 , V_166 [ V_165 ] . V_133 ,
( V_166 [ V_165 ] . V_167 == V_168 ) ? L_42 :
( ( V_166 [ V_165 ] . V_167 == V_169 ) ? L_43 : L_13 ) ) ;
}
}
static int F_33 ( char * V_1 , char * V_4 ,
const char * V_86 , unsigned short * V_87 ) {
struct V_3 V_3 ;
static char V_170 [ V_16 ] ;
static char V_88 [ V_16 ] ;
static char V_89 [ V_16 ] ;
T_2 V_62 ;
T_2 V_80 = 0 ;
T_5 V_61 ;
const char * V_171 = L_44 V_94 : V_95 - V_172 L_45 % 04x L_13 V_94 : V_95 : % V_96 L_46 0013 L_13 V_97 : V_108 - V_173 - V_174 L_47 0019 L_13 V_97 : V_175 - V_176 V_108 - V_173 - V_174 L_48 ERROR : Error while setting adb transport for <%s>\n", adb_transport);
closesocket(sock);
return 1;
}
} else {
sprintf((char *) helpful_packet, adb_transport_serial_templace, 15 + strlen(serial_number), serial_number);
result = adb_send(sock, helpful_packet);
if (result) {
if (verbose)
g_fprintf(stderr, "ERROR: Error while setting adb transport for <%s>\n", helpful_packet);
closesocket(sock);
return 1;
}
}
result = adb_send(sock, adb_shell_hcidump);
if (result) {
if (verbose)
g_fprintf(stderr, "ERROR: Error while starting capture by sending command: %s\n", adb_shell_hcidump);
closesocket(sock);
return 1;
}
while (endless_loop) {
char *i_position;
errno = 0;
length = recv(sock, data + used_buffer_length, (int)(PACKET_LENGTH - used_buffer_length), 0);
if (errno == EAGAIN || errno == EWOULDBLOCK) continue;
else if (errno != 0) {
if (verbose)
g_printf("ERROR capture: %s\n", strerror(errno));
closesocket(sock);
return 100;
}
used_buffer_length += length;
i_position = (char *) memchr(data, '\n', used_buffer_length);
if (i_position && i_position < data + used_buffer_length) {
char *state_line_position = i_position + 1;
if (!strncmp(data, "/system/bin/sh: hcidump: not found", 34)) {
if (verbose)
g_fprintf(stderr, "ERROR: Command not found for <%s>\n", adb_shell_hcidump);
closesocket(sock);
return 2;
}
i_position = (char *) memchr(i_position + 1, '\n', used_buffer_length);
if (i_position) {
i_position += 1;
if (!strncmp(state_line_position, "Can't access device: Permission denied", 38)) {
if (verbose)
g_fprintf(stderr, "WARNING: No permission for command <%s>\n", adb_shell_hcidump);
used_buffer_length = 0;
try_next += 1;
break;
}
memmove(data, i_position, used_buffer_length - (i_position - data));
used_buffer_length = used_buffer_length - (gssize)(i_position - data);
break;
}
}
}
if (try_next == 1) {
sock = adb_connect(adb_server_ip, adb_server_tcp_port);
if (sock == INVALID_SOCKET)
return -1;
sprintf((char *) helpful_packet, adb_transport_serial_templace, 15 + strlen(serial_number), serial_number);
result = adb_send(sock, helpful_packet);
if (result) {
if (verbose)
g_fprintf(stderr, "ERROR: Error while setting adb transport for <%s>\n", helpful_packet);
closesocket(sock);
return 1;
}
result = adb_send(sock, adb_shell_su_hcidump);
if (result) {
if (verbose)
g_fprintf(stderr, "ERROR: Error while starting capture by sending command: <%s>\n", adb_shell_su_hcidump);
closesocket(sock);
return 1;
}
used_buffer_length = 0;
while (endless_loop) {
char *i_position;
errno = 0;
length = recv(sock, data + used_buffer_length, (int)(PACKET_LENGTH - used_buffer_length), 0);
if (errno == EAGAIN || errno == EWOULDBLOCK) continue;
else if (errno != 0) {
if (verbose)
g_printf("ERROR capture: %s\n", strerror(errno));
closesocket(sock);
return 100;
}
used_buffer_length += length;
i_position = (char *) memchr(data, '\n', used_buffer_length);
if (i_position && i_position < data + used_buffer_length) {
if (!strncmp(data, "/system/bin/sh: su: not found", 29)) {
if (verbose)
g_fprintf(stderr, "ERROR: Command 'su' not found for <%s>\n", adb_shell_su_hcidump);
closesocket(sock);
return 2;
}
i_position = (char *) memchr(i_position + 1, '\n', used_buffer_length);
if (i_position) {
i_position += 1;
memmove(data, i_position, used_buffer_length - (i_position - data));
used_buffer_length = used_buffer_length - (gssize)(i_position - data);
break;
}
}
}
}
while (endless_loop) {
errno = 0;
length = recv(sock, data + used_buffer_length, (int)(PACKET_LENGTH - used_buffer_length), 0);
if (errno == EAGAIN || errno == EWOULDBLOCK) continue;
else if (errno != 0) {
if (verbose)
g_printf("ERROR capture: %s\n", strerror(errno));
closesocket(sock);
return 100;
}
while (endless_loop) {
if (used_buffer_length + length >= 1) {
hex_data = data + 29;
hex = g_ascii_strtoll(hex_data, &new_hex_data, 16);
if ((hex == 0x01 && used_buffer_length + length >= 4) ||
(hex == 0x02 && used_buffer_length + length >= 5) ||
(hex == 0x04 && used_buffer_length + length >= 3)) {
if (hex == 0x01) {
hex_data = new_hex_data;
hex = g_ascii_strtoll(hex_data, &new_hex_data, 16);
if (hex < 0 || hex >= 256 || hex_data == new_hex_data) {
if (verbose)
g_printf("ERROR: data format error: %s\n", strerror(errno));
closesocket(sock);
return 101;
}
hex_data = new_hex_data;
hex = g_ascii_strtoll(hex_data, &new_hex_data, 16);
if (hex < 0 || hex >= 256 || hex_data == new_hex_data) {
if (verbose)
g_printf("ERROR: data format error: %s\n", strerror(errno));
closesocket(sock);
return 101;
}
hex_data = new_hex_data;
hex = g_ascii_strtoll(hex_data, &new_hex_data, 16);
raw_length = hex + 4;
} else if (hex == 0x04) {
hex_data = new_hex_data;
hex = g_ascii_strtoll(hex_data, &new_hex_data, 16);
if (hex < 0 || hex >= 256 || hex_data == new_hex_data) {
if (verbose)
g_printf("ERROR: data format error: %s\n", strerror(errno));
closesocket(sock);
return 101;
}
hex_data = new_hex_data;
hex = g_ascii_strtoll(hex_data, &new_hex_data, 16);
raw_length = hex + 3;
} else if (hex == 0x02) {
hex_data = new_hex_data;
hex = g_ascii_strtoll(hex_data, &new_hex_data, 16);
if (hex < 0 || hex >= 256 || hex_data == new_hex_data) {
if (verbose)
g_printf("ERROR: data format error: %s\n", strerror(errno));
closesocket(sock);
return 101;
}
hex_data = new_hex_data;
hex = g_ascii_strtoll(hex_data, &new_hex_data, 16);
if (hex < 0 || hex >= 256 || hex_data == new_hex_data) {
if (verbose)
g_printf("ERROR: data format error: %s\n", strerror(errno));
closesocket(sock);
return 101;
}
hex_data = new_hex_data;
hex = g_ascii_strtoll(hex_data, &new_hex_data, 16);
raw_length = hex + 5;
hex_data = new_hex_data;
hex = g_ascii_strtoll(hex_data, &new_hex_data, 16);
raw_length += hex << 8;
}
} else {
if (verbose)
g_fprintf(stderr, "ERROR: bad raw stream\n");
closesocket(sock);
return 1;
}
} else {
used_buffer_length += length;
break;
}
frame_length = raw_length * 3 + (raw_length / 20) * 4 + ((raw_length % 20) ? 2 : -2) + 29;
if (used_buffer_length + length < frame_length) {
used_buffer_length += length;
break;
}
if (8 == sscanf(data, "%04d-%02d-%02d %02d:%02d:%02d.%06d %c",
&date.tm_year, &date.tm_mon, &date.tm_mday, &date.tm_hour,
&date.tm_min, &date.tm_sec, &ms, &direction_character)) {
if (verbose) {
g_fprintf(stderr, "time %04d-%02d-%02d %02d:%02d:%02d.%06d %c\n",
date.tm_year, date.tm_mon, date.tm_mday, date.tm_hour,
date.tm_min, date.tm_sec, ms, direction_character);
}
date.tm_mon -= 1;
date.tm_year -= 1900;
ts = mktime(&date);
new_hex_data = data + 29;
}
captured_length = 0;
while ((long)(new_hex_data - data + sizeof(own_pcap_bluetooth_h4_header)) < frame_length) {
hex_data = new_hex_data;
hex = g_ascii_strtoll(hex_data, &new_hex_data, 16);
packet[sizeof(own_pcap_bluetooth_h4_header) + captured_length] = (char) hex;
captured_length += 1;
}
h4_header->direction = GINT32_TO_BE(direction_character == '>');
extcap_dumper_dump(extcap_dumper, packet,
captured_length + sizeof(own_pcap_bluetooth_h4_header),
captured_length + sizeof(own_pcap_bluetooth_h4_header),
ts,
ms * 1000);
if (used_buffer_length + length >= frame_length) {
memmove(data, data + frame_length, (size_t)(used_buffer_length + length - frame_length));
used_buffer_length = (gssize)(used_buffer_length + length - frame_length);
length = 0;
continue;
}
length = 0;
}
}
closesocket(sock);
return 0;
}
/*----------------------------------------------------------------------------*/
/* Android Bluetooth External Parser */
/*----------------------------------------------------------------------------*/
#define BLUEDROID_H4_PACKET_TYPE 0
#define BLUEDROID_TIMESTAMP_SIZE 8
#define BLUEDROID_H4_SIZE 1
static const uint64_t BLUEDROID_TIMESTAMP_BASE = G_GUINT64_CONSTANT(0x00dcddb30f2f8000);
#define BLUEDROID_H4_PACKET_TYPE_HCI_CMD 0x01
#define BLUEDROID_H4_PACKET_TYPE_ACL 0x02
#define BLUEDROID_H4_PACKET_TYPE_SCO 0x03
#define BLUEDROID_H4_PACKET_TYPE_HCI_EVT 0x04
#define BLUEDROID_DIRECTION_SENT 0
#define BLUEDROID_DIRECTION_RECV 1
static int adb_forward(char *serial_number, const char *adb_server_ip, unsigned short *adb_server_tcp_port,
unsigned short local_tcp_port, unsigned short server_tcp_port) {
socket_handle_t sock;
int result;
static char helpful_packet[PACKET_LENGTH];
static const char *adb_forward_template = "%04x""%s%s:forward:tcp:%05u;tcp:%05u";
sock = adb_connect(adb_server_ip, adb_server_tcp_port);
if (sock == INVALID_SOCKET)
return -1;
g_snprintf(helpful_packet, PACKET_LENGTH, adb_forward_template, (serial_number) ? 5 + 7 + strlen(serial_number) + 28 : 4 + 28, (serial_number) ? "host-serial:" : "host", (serial_number) ? serial_number: "", local_tcp_port, server_tcp_port);
result = adb_send(sock, helpful_packet);
closesocket(sock);
return result;
}
static int capture_android_bluetooth_external_parser(char *interface,
char *fifo, const char *adb_server_ip, unsigned short *adb_server_tcp_port,
unsigned short *bt_server_tcp_port, unsigned int bt_forward_socket, const char *bt_local_ip,
unsigned short *bt_local_tcp_port) {
struct extcap_dumper extcap_dumper;
char buffer[PACKET_LENGTH];
uint64_t *timestamp;
char *packet = buffer + BLUEDROID_TIMESTAMP_SIZE - sizeof(own_pcap_bluetooth_h4_header); /* skip timestamp (8 bytes) and reuse its space for header */
own_pcap_bluetooth_h4_header *h4_header;
guint8 *payload = packet + sizeof(own_pcap_bluetooth_h4_header);
const char *adb_transport = "0012""host:transport-any";
const char *adb_transport_serial_templace = "%04x""host:transport:%s";
const char *adb_tcp_bluedroid_external_parser_template = "%04x""tcp:%05u";
gssize length;
gssize used_buffer_length = 0;
uint64_t ts;
socket_handle_t sock;
struct sockaddr_in server;
int captured_length;
char *serial_number = NULL;
SET_DATA(timestamp, value_u64, buffer);
SET_DATA(h4_header, value_own_pcap_bluetooth_h4_header, packet);
extcap_dumper = extcap_dumper_open(fifo, EXTCAP_ENCAP_BLUETOOTH_H4_WITH_PHDR);
if (is_specified_interface(interface, INTERFACE_ANDROID_BLUETOOTH_EXTERNAL_PARSER) &&
strlen(interface) > strlen(INTERFACE_ANDROID_BLUETOOTH_EXTERNAL_PARSER) + 1) {
serial_number = interface + strlen(INTERFACE_ANDROID_BLUETOOTH_EXTERNAL_PARSER) + 1;
}
if (bt_forward_socket) {
if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET) {
if (verbose)
g_printf("ERROR: Cannot open system TCP socket: %s\n", strerror(errno));
return 1;
}
if (verbose) {
g_printf("Using config: Server TCP Port=%u, Local IP=%s, Local TCP Port=%u\n",
*bt_server_tcp_port, bt_local_ip, *bt_local_tcp_port);
}
if (*bt_local_tcp_port != 0) {
int result;
result = adb_forward(serial_number, adb_server_ip, adb_server_tcp_port, *bt_local_tcp_port, *bt_server_tcp_port);
if (verbose)
g_printf("DO: adb forward tcp:%u (local) tcp:%u (remote) result=%i\n",
*bt_local_tcp_port, *bt_server_tcp_port, result);
}
memset(&server, 0 , sizeof(server));
server.sin_family = AF_INET;
server.sin_port = GINT16_TO_BE(*bt_local_tcp_port);
server.sin_addr.s_addr = inet_addr(bt_local_ip);
if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == SOCKET_ERROR) {
if (verbose)
g_printf("ERROR: <%s> Please check that adb daemon is running.\n\n", strerror(errno));
closesocket(sock);
return 2;
}
if (verbose) {
struct sockaddr_in client;
length = sizeof(client);
if (getsockname(sock, (struct sockaddr *) &client, (socklen_t *) &length)) {
g_printf("ERROR getsockname: %s\n", strerror(errno));
closesocket(sock);
return 3;
}
if (length != sizeof(client)) {
g_printf("ERROR: incorrect length\n");
closesocket(sock);
return 4;
}
g_printf("VERBOSE: Client port %u\n", GUINT16_FROM_BE(client.sin_port));
}
} else {
int result;
sock = adb_connect(adb_server_ip, adb_server_tcp_port);
if (sock == INVALID_SOCKET)
return -1;
if (!serial_number) {
result = adb_send(sock, adb_transport);
if (result) {
if (verbose)
g_fprintf(stderr, "ERROR: Error while setting adb transport\n");
closesocket(sock);
return 1;
}
} else {
g_snprintf((char *) buffer, PACKET_LENGTH, adb_transport_serial_templace, 15 + strlen(serial_number), serial_number);
result = adb_send(sock, buffer);
if (result) {
if (verbose)
g_fprintf(stderr, "ERROR: Error while setting adb transport\n");
closesocket(sock);
return 1;
}
}
sprintf((char *) buffer, adb_tcp_bluedroid_external_parser_template, 4 + 5, *bt_server_tcp_port);
result = adb_send(sock, buffer);
if (result) {
if (verbose)
g_fprintf(stderr, "ERROR: Error while forwarding adb port\n");
closesocket(sock);
return 1;
}
}
while (endless_loop) {
errno = 0;
length = recv(sock, buffer + used_buffer_length, (int)(PACKET_LENGTH - used_buffer_length), 0);
if (errno == EAGAIN || errno == EWOULDBLOCK) continue;
else if (errno != 0) {
if (verbose)
g_printf("ERROR capture: %s\n", strerror(errno));
closesocket(sock);
return 100;
}
if (length <= 0) {
if (bt_forward_socket) {
/* NOTE: Workaround... It seems that Bluedroid is slower and we can connect to socket that are not really ready... */
if (verbose)
g_printf("WARNING: Broken socket connection. Try reconnect.\n");
closesocket(sock);
if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET) {
if (verbose)
g_printf("ERROR1: %s\n", strerror(errno));
return 1;
}
server.sin_family = AF_INET;
server.sin_port = GINT16_TO_BE(*bt_local_tcp_port);
server.sin_addr.s_addr = inet_addr(bt_local_ip);
if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == SOCKET_ERROR) {
if (verbose)
g_printf("ERROR reconnect: <%s> Please check that adb daemon is running.\n", strerror(errno));
closesocket(sock);
return 2;
}
} else {
if (verbose)
g_printf("ERROR: Broken socket connection.\n");
closesocket(sock);
return 1;
}
continue;
}
used_buffer_length += length;
if (verbose) g_printf("Received: length=%"G_GSSIZE_FORMAT"\n", length);
while (((payload[BLUEDROID_H4_PACKET_TYPE] == BLUEDROID_H4_PACKET_TYPE_HCI_CMD || payload[BLUEDROID_H4_PACKET_TYPE] == BLUEDROID_H4_PACKET_TYPE_SCO) &&
used_buffer_length >= BLUEDROID_TIMESTAMP_SIZE + BLUEDROID_H4_SIZE + 2 + 1 &&
BLUEDROID_TIMESTAMP_SIZE + BLUEDROID_H4_SIZE + 2 + payload[BLUEDROID_H4_SIZE + 2] + 1 <= used_buffer_length) ||
(payload[BLUEDROID_H4_PACKET_TYPE] == BLUEDROID_H4_PACKET_TYPE_ACL &&
used_buffer_length >= BLUEDROID_TIMESTAMP_SIZE + BLUEDROID_H4_SIZE + 2 + 2 &&
BLUEDROID_TIMESTAMP_SIZE + BLUEDROID_H4_SIZE + 2 + payload[BLUEDROID_H4_SIZE + 2] + (payload[BLUEDROID_H4_SIZE + 2 + 1] << 8) + 2 <= used_buffer_length) ||
(payload[BLUEDROID_H4_PACKET_TYPE] == BLUEDROID_H4_PACKET_TYPE_SCO &&
used_buffer_length >= BLUEDROID_TIMESTAMP_SIZE + BLUEDROID_H4_SIZE + 2 + 1 &&
BLUEDROID_TIMESTAMP_SIZE + BLUEDROID_H4_SIZE + 2 + payload[BLUEDROID_H4_SIZE + 2] + 1 <= used_buffer_length) ||
(payload[BLUEDROID_H4_PACKET_TYPE] == BLUEDROID_H4_PACKET_TYPE_HCI_EVT &&
used_buffer_length >= BLUEDROID_TIMESTAMP_SIZE + BLUEDROID_H4_SIZE + 1 + 1 &&
BLUEDROID_TIMESTAMP_SIZE + BLUEDROID_H4_SIZE + 1 + payload[BLUEDROID_H4_SIZE + 1] + 1 <= used_buffer_length)) {
ts = GINT64_FROM_BE(*timestamp);
switch (payload[BLUEDROID_H4_PACKET_TYPE]) {
case BLUEDROID_H4_PACKET_TYPE_HCI_CMD:
h4_header->direction = GINT32_TO_BE(BLUEDROID_DIRECTION_SENT);
captured_length = (unsigned int)sizeof(own_pcap_bluetooth_h4_header) + payload[3] + 4;
length = sizeof(own_pcap_bluetooth_h4_header) + BLUEDROID_H4_SIZE + 2 + 1 + payload[3];
break;
case BLUEDROID_H4_PACKET_TYPE_ACL:
h4_header->direction = (payload[2] & 0x80) ? GINT32_TO_BE(BLUEDROID_DIRECTION_RECV) : GINT32_TO_BE(BLUEDROID_DIRECTION_SENT);
captured_length = (unsigned int)sizeof(own_pcap_bluetooth_h4_header) + payload[3] + (payload[3 + 1] << 8) + 5;
length = sizeof(own_pcap_bluetooth_h4_header) + BLUEDROID_H4_SIZE + 2 + 2 + payload[3] + (payload[3 + 1] << 8);
break;
case BLUEDROID_H4_PACKET_TYPE_SCO:
h4_header->direction = (payload[2] & 0x80) ? GINT32_TO_BE(BLUEDROID_DIRECTION_RECV) : GINT32_TO_BE(BLUEDROID_DIRECTION_SENT);
captured_length = (unsigned int)sizeof(own_pcap_bluetooth_h4_header) + payload[3] + 4;
length = sizeof(own_pcap_bluetooth_h4_header) + BLUEDROID_H4_SIZE + 2 + 1 + payload[3];
break;
case BLUEDROID_H4_PACKET_TYPE_HCI_EVT:
h4_header->direction = GINT32_TO_BE(BLUEDROID_DIRECTION_RECV);
captured_length = (unsigned int)sizeof(own_pcap_bluetooth_h4_header) + payload[2] + 3;
length = sizeof(own_pcap_bluetooth_h4_header) + BLUEDROID_H4_SIZE + 1 + 1 + payload[2];
break;
default:
if (verbose)
g_printf("ERROR: Invalid stream\n");
closesocket(sock);
return 1;
}
if (verbose) {
static unsigned int id = 1;
g_printf("\t Packet %u: used_buffer_length=%"G_GSSIZE_FORMAT" length=%"G_GSSIZE_FORMAT" captured_length=%i type=0x%02x\n", id, used_buffer_length, length, captured_length, payload[BLUEDROID_H4_PACKET_TYPE]);
if (payload[BLUEDROID_H4_PACKET_TYPE] == BLUEDROID_H4_PACKET_TYPE_HCI_EVT)
g_printf("\t Packet: %02x %02x %02x\n", (unsigned int) payload[0], (unsigned int) payload[1], (unsigned int)payload[2]);
id +=1;
}
ts -= BLUEDROID_TIMESTAMP_BASE;
extcap_dumper_dump(extcap_dumper, packet,
captured_length,
captured_length,
(uint32_t)(ts / 1000000),
((uint32_t)(ts % 1000000)) * 1000);
used_buffer_length -= length - sizeof(own_pcap_bluetooth_h4_header) + BLUEDROID_TIMESTAMP_SIZE;
if (used_buffer_length < 0) {
if (verbose)
g_printf("ERROR: Internal error: Negative used buffer length.\n");
closesocket(sock);
return 1;
}
memmove(buffer, packet + length, used_buffer_length);
}
}
closesocket(sock);
return 0;
}
/*----------------------------------------------------------------------------*/
/* Android Btsnoop Net */
/*----------------------------------------------------------------------------*/
static int capture_android_bluetooth_btsnoop_net(char *interface, char *fifo,
const char *adb_server_ip, unsigned short *adb_server_tcp_port) {
struct extcap_dumper extcap_dumper;
static char packet[PACKET_LENGTH];
gssize length;
gssize used_buffer_length = 0;
socket_handle_t sock;
const char *adb_transport = "0012""host:transport-any";
const char *adb_transport_serial_templace = "%04x""host:transport:%s";
const char *adb_tcp_btsnoop_net = "0008""tcp:8872";
int result;
char *serial_number = NULL;
uint64_t ts;
static const uint64_t BTSNOOP_TIMESTAMP_BASE = G_GUINT64_CONSTANT(0x00dcddb30f2f8000);
uint32_t *reported_length;
uint32_t *captured_length;
uint32_t *flags;
/* uint32_t *cummulative_dropped_packets; */
uint64_t *timestamp;
char *payload = packet + sizeof(own_pcap_bluetooth_h4_header) + 24;
own_pcap_bluetooth_h4_header *h4_header;
SET_DATA(reported_length, value_u32, packet + sizeof(own_pcap_bluetooth_h4_header) + 0);
SET_DATA(captured_length, value_u32, packet + sizeof(own_pcap_bluetooth_h4_header) + 4);
SET_DATA(flags, value_u32, packet + sizeof(own_pcap_bluetooth_h4_header) + 8);
/* SET_DATA(cummulative_dropped_packets, value_u32, packet + sizeof(own_pcap_bluetooth_h4_header) + 12); */
SET_DATA(timestamp, value_u64, packet + sizeof(own_pcap_bluetooth_h4_header) + 16);
SET_DATA(h4_header, value_own_pcap_bluetooth_h4_header, payload - sizeof(own_pcap_bluetooth_h4_header));
extcap_dumper = extcap_dumper_open(fifo, EXTCAP_ENCAP_BLUETOOTH_H4_WITH_PHDR);
sock = adb_connect(adb_server_ip, adb_server_tcp_port);
if (sock == INVALID_SOCKET)
return -1;
if (is_specified_interface(interface, INTERFACE_ANDROID_BLUETOOTH_BTSNOOP_NET) &&
strlen(interface) > strlen(INTERFACE_ANDROID_BLUETOOTH_BTSNOOP_NET) + 1) {
serial_number = interface + strlen(INTERFACE_ANDROID_BLUETOOTH_BTSNOOP_NET) + 1;
}
if (!serial_number) {
result = adb_send(sock, adb_transport);
if (result) {
if (verbose)
g_fprintf(stderr, "ERROR: Error while setting adb transport for <%s>\n", adb_transport);
return 1;
}
} else {
sprintf((char *) packet, adb_transport_serial_templace, 15 + strlen(serial_number), serial_number);
result = adb_send(sock, packet);
if (result) {
if (verbose)
g_fprintf(stderr, "ERROR: Error while setting adb transport for <%s>\n", packet);
closesocket(sock);
return 1;
}
}
result = adb_send(sock, adb_tcp_btsnoop_net);
if (result) {
if (verbose)
g_fprintf(stderr, "ERROR: Error while sending command <%s>\n", adb_tcp_btsnoop_net);
closesocket(sock);
return 1;
}
/* Read "btsnoop" header - 16 bytes */
while (used_buffer_length < 16) {
length = recv(sock, packet + used_buffer_length, (int)(PACKET_LENGTH - used_buffer_length), 0);
used_buffer_length += length;
}
if (used_buffer_length > 16)
memmove(packet, packet + 16, used_buffer_length - 16);
used_buffer_length = 0;
while (endless_loop) {
errno = 0;
length = recv(sock, packet + used_buffer_length + sizeof(own_pcap_bluetooth_h4_header),
(int)(PACKET_LENGTH - sizeof(own_pcap_bluetooth_h4_header) - used_buffer_length), 0);
if (errno == EAGAIN || errno == EWOULDBLOCK) continue;
else if (errno != 0) {
if (verbose)
g_printf("ERROR capture: %s\n", strerror(errno));
closesocket(sock);
return 100;
}
if (length <= 0) {
if (verbose)
g_printf("ERROR: Broken socket connection.\n");
closesocket(sock);
return 101;
}
used_buffer_length += length;
while (used_buffer_length >= 24 &&
used_buffer_length >= (int) (24 + GINT32_FROM_BE(*captured_length))) {
gint32 direction;
ts = GINT64_FROM_BE(*timestamp);
ts -= BTSNOOP_TIMESTAMP_BASE;
direction = GINT32_FROM_BE(*flags) & 0x01;
h4_header->direction = GINT32_TO_BE(direction);
extcap_dumper_dump(extcap_dumper, payload - sizeof(own_pcap_bluetooth_h4_header),
GINT32_FROM_BE(*captured_length) + sizeof(own_pcap_bluetooth_h4_header),
GINT32_FROM_BE(*reported_length) + sizeof(own_pcap_bluetooth_h4_header),
(uint32_t)(ts / 1000000),
((uint32_t)(ts % 1000000)) * 1000);
used_buffer_length -= 24 + GINT32_FROM_BE(*captured_length);
if (used_buffer_length < 0) {
if (verbose)
g_printf("ERROR: Internal error: Negative used buffer length.\n");
closesocket(sock);
return 1;
}
if (used_buffer_length > 0)
memmove(packet + sizeof(own_pcap_bluetooth_h4_header), payload + GINT32_FROM_BE(*captured_length), used_buffer_length);
}
}
closesocket(sock);
return 0;
}
/*----------------------------------------------------------------------------*/
/* Android Logcat Text*/
/*----------------------------------------------------------------------------*/
static int capture_android_logcat_text(char *interface, char *fifo,
const char *adb_server_ip, unsigned short *adb_server_tcp_port) {
struct extcap_dumper extcap_dumper;
static char packet[PACKET_LENGTH];
gssize length;
size_t used_buffer_length = 0;
socket_handle_t sock;
const char *protocol_name;
size_t exported_pdu_headers_size = 0;
struct exported_pdu_header exported_pdu_header_protocol_normal;
struct exported_pdu_header *exported_pdu_header_protocol;
struct exported_pdu_header exported_pdu_header_end = {0, 0};
static const char *wireshark_protocol_logcat_text = "logcat_text_threadtime";
const char *adb_transport = "0012""host:transport-any";
const char *adb_logcat_template = "%04x""shell:export ANDROID_LOG_TAGS=\"\" ; exec logcat -v threadtime%s%s";
const char *adb_transport_serial_templace = "%04x""host:transport:%s";
char *serial_number = NULL;
int result;
char *pos;
const char *logcat_buffer;
extcap_dumper = extcap_dumper_open(fifo, EXTCAP_ENCAP_WIRESHARK_UPPER_PDU);
exported_pdu_header_protocol_normal.tag = GINT16_TO_BE(WIRESHARK_UPPER_PDU_TAG_DISSECTOR_NAME);
exported_pdu_header_protocol_normal.length = GINT16_TO_BE(strlen(wireshark_protocol_logcat_text) + 2);
sock = adb_connect(adb_server_ip, adb_server_tcp_port);
if (sock == INVALID_SOCKET)
return -1;
if (is_specified_interface(interface, INTERFACE_ANDROID_LOGCAT_MAIN) && strlen(interface) > strlen(INTERFACE_ANDROID_LOGCAT_MAIN) + 1) {
serial_number = interface + strlen(INTERFACE_ANDROID_LOGCAT_MAIN) + 1;
} else if (is_specified_interface(interface, INTERFACE_ANDROID_LOGCAT_SYSTEM) && strlen(interface) > strlen(INTERFACE_ANDROID_LOGCAT_SYSTEM) + 1) {
serial_number = interface + strlen(INTERFACE_ANDROID_LOGCAT_SYSTEM) + 1;
} else if (is_specified_interface(interface, INTERFACE_ANDROID_LOGCAT_RADIO) && strlen(interface) > strlen(INTERFACE_ANDROID_LOGCAT_RADIO) + 1) {
serial_number = interface + strlen(INTERFACE_ANDROID_LOGCAT_RADIO) + 1;
} else if (is_specified_interface(interface, INTERFACE_ANDROID_LOGCAT_EVENTS) && strlen(interface) > strlen(INTERFACE_ANDROID_LOGCAT_EVENTS) + 1) {
serial_number = interface + strlen(INTERFACE_ANDROID_LOGCAT_EVENTS) + 1;
} else if (is_specified_interface(interface, INTERFACE_ANDROID_LOGCAT_TEXT_MAIN) && strlen(interface) > strlen(INTERFACE_ANDROID_LOGCAT_TEXT_MAIN) + 1) {
serial_number = interface + strlen(INTERFACE_ANDROID_LOGCAT_TEXT_MAIN) + 1;
} else if (is_specified_interface(interface, INTERFACE_ANDROID_LOGCAT_TEXT_SYSTEM) && strlen(interface) > strlen(INTERFACE_ANDROID_LOGCAT_TEXT_SYSTEM) + 1) {
serial_number = interface + strlen(INTERFACE_ANDROID_LOGCAT_TEXT_SYSTEM) + 1;
} else if (is_specified_interface(interface, INTERFACE_ANDROID_LOGCAT_TEXT_RADIO) && strlen(interface) > strlen(INTERFACE_ANDROID_LOGCAT_TEXT_RADIO) + 1) {
serial_number = interface + strlen(INTERFACE_ANDROID_LOGCAT_TEXT_RADIO) + 1;
} else if (is_specified_interface(interface, INTERFACE_ANDROID_LOGCAT_TEXT_EVENTS) && strlen(interface) > strlen(INTERFACE_ANDROID_LOGCAT_TEXT_EVENTS) + 1) {
serial_number = interface + strlen(INTERFACE_ANDROID_LOGCAT_TEXT_EVENTS) + 1;
} else if (is_specified_interface(interface, INTERFACE_ANDROID_LOGCAT_TEXT_CRASH) && strlen(interface) > strlen(INTERFACE_ANDROID_LOGCAT_TEXT_CRASH) + 1) {
serial_number = interface + strlen(INTERFACE_ANDROID_LOGCAT_TEXT_CRASH) + 1;
}
if (!serial_number) {
result = adb_send(sock, adb_transport);
if (result) {
if (verbose)
g_fprintf(stderr, "ERROR: Error while setting adb transport for <%s>\n", adb_transport);
closesocket(sock);
return 1;
}
} else {
sprintf((char *) packet, adb_transport_serial_templace, 15 + strlen(serial_number), serial_number);
result = adb_send(sock, packet);
if (result) {
if (verbose)
g_fprintf(stderr, "ERROR: Error while setting adb transport for <%s>\n", packet);
closesocket(sock);
return 1;
}
}
if (is_specified_interface(interface, INTERFACE_ANDROID_LOGCAT_MAIN) || is_specified_interface(interface, INTERFACE_ANDROID_LOGCAT_TEXT_MAIN))
logcat_buffer = " -b main";
else if (is_specified_interface(interface, INTERFACE_ANDROID_LOGCAT_SYSTEM) || is_specified_interface(interface, INTERFACE_ANDROID_LOGCAT_TEXT_SYSTEM))
logcat_buffer = " -b system";
else if (is_specified_interface(interface, INTERFACE_ANDROID_LOGCAT_RADIO) || is_specified_interface(interface, INTERFACE_ANDROID_LOGCAT_TEXT_RADIO))
logcat_buffer = " -b radio";
else if (is_specified_interface(interface, INTERFACE_ANDROID_LOGCAT_EVENTS) || is_specified_interface(interface, INTERFACE_ANDROID_LOGCAT_TEXT_EVENTS))
logcat_buffer = " -b events";
else if (is_specified_interface(interface, INTERFACE_ANDROID_LOGCAT_TEXT_CRASH))
logcat_buffer = " -b crash";
else {
g_printf("ERROR: Unknown interface: <%s>\n", interface);
closesocket(sock);
return -1;
}
g_snprintf((char *) packet, sizeof(packet), adb_logcat_template, strlen(adb_logcat_template) + -8 + strlen(logcat_buffer), logcat_buffer, "");
result = adb_send(sock, packet);
if (result) {
if (verbose)
g_fprintf(stderr, "ERROR: Error while sending command <%s>\n", packet);
closesocket(sock);
return 1;
}
protocol_name = wireshark_protocol_logcat_text;
exported_pdu_header_protocol = &exported_pdu_header_protocol_normal;
memcpy(packet + exported_pdu_headers_size, exported_pdu_header_protocol, sizeof(struct exported_pdu_header));
exported_pdu_headers_size += sizeof(struct exported_pdu_header);
memcpy(packet + exported_pdu_headers_size, protocol_name, GINT16_FROM_BE(exported_pdu_header_protocol->length) - 2);
exported_pdu_headers_size += GINT16_FROM_BE(exported_pdu_header_protocol->length);
packet[exported_pdu_headers_size - 1] = 0;
packet[exported_pdu_headers_size - 2] = 0;
memcpy(packet + exported_pdu_headers_size, &exported_pdu_header_end, sizeof(struct exported_pdu_header));
exported_pdu_headers_size += sizeof(struct exported_pdu_header) + GINT16_FROM_BE(exported_pdu_header_end.length);
used_buffer_length = 0;
while (endless_loop) {
errno = 0;
length = recv(sock, packet + exported_pdu_headers_size + used_buffer_length, (int)(PACKET_LENGTH - exported_pdu_headers_size - used_buffer_length), 0);
if (errno == EAGAIN || errno == EWOULDBLOCK) continue;
else if (errno != 0) {
if (verbose)
g_printf("ERROR capture: %s\n", strerror(errno));
closesocket(sock);
return 100;
}
if (length <= 0) {
if (verbose)
g_printf("ERROR: Broken socket connection. Try reconnect.\n");
closesocket(sock);
return 1;
}
used_buffer_length += length;
while (used_buffer_length > 0 && (pos = (char *) memchr(packet + exported_pdu_headers_size, '\n', used_buffer_length))) {
int ms;
struct tm date;
time_t seconds;
time_t secs = 0;
int nsecs = 0;
length = (gssize)(pos - packet) + 1;
if (6 == sscanf(packet + exported_pdu_headers_size, "%d-%d %d:%d:%d.%d", &date.tm_mon, &date.tm_mday, &date.tm_hour,
&date.tm_min, &date.tm_sec, &ms)) {
date.tm_year = 70;
date.tm_mon -= 1;
seconds = mktime(&date);
secs = (time_t) seconds;
nsecs = (int) (ms * 1e6);
}
extcap_dumper_dump(extcap_dumper, packet,
length,
length,
secs, nsecs);
memmove(packet + exported_pdu_headers_size, packet + length, used_buffer_length + exported_pdu_headers_size - length);
used_buffer_length -= length - exported_pdu_headers_size;
}
}
closesocket(sock);
return 0;
}
/*----------------------------------------------------------------------------*/
/* Android Logger / Logcat */
/*----------------------------------------------------------------------------*/
static int capture_android_logcat(char *interface, char *fifo,
const char *adb_server_ip, unsigned short *adb_server_tcp_port) {
struct extcap_dumper extcap_dumper;
static char packet[PACKET_LENGTH];
static char helper_packet[PACKET_LENGTH];
gssize length;
size_t used_buffer_length = 0;
socket_handle_t sock;
const char *protocol_name;
size_t exported_pdu_headers_size = 0;
struct exported_pdu_header exported_pdu_header_protocol_events;
struct exported_pdu_header exported_pdu_header_protocol_normal;
struct exported_pdu_header *exported_pdu_header_protocol;
struct exported_pdu_header exported_pdu_header_end = {0, 0};
static const char *wireshark_protocol_logcat = "logcat";
static const char *wireshark_protocol_logcat_events = "logcat_events";
const char *adb_transport = "0012""host:transport-any";
const char *adb_log_main = "0008""log:main";
const char *adb_log_system = "000A""log:system";
const char *adb_log_radio = "0009""log:radio";
const char *adb_log_events = "000A""log:events";
const char *adb_transport_serial_templace = "%04x""host:transport:%s";
const char *adb_command;
uint16_t *payload_length;
uint16_t *try_header_size;
uint32_t *timestamp_secs;
uint32_t *timestamp_nsecs;
uint16_t header_size;
int result;
char *serial_number = NULL;
extcap_dumper = extcap_dumper_open(fifo, EXTCAP_ENCAP_WIRESHARK_UPPER_PDU);
exported_pdu_header_protocol_events.tag = GINT16_TO_BE(WIRESHARK_UPPER_PDU_TAG_DISSECTOR_NAME);
exported_pdu_header_protocol_events.length = GINT16_TO_BE(strlen(wireshark_protocol_logcat_events) + 2);
exported_pdu_header_protocol_normal.tag = GINT16_TO_BE(WIRESHARK_UPPER_PDU_TAG_DISSECTOR_NAME);
exported_pdu_header_protocol_normal.length = GINT16_TO_BE(strlen(wireshark_protocol_logcat) + 2);
sock = adb_connect(adb_server_ip, adb_server_tcp_port);
if (sock == INVALID_SOCKET)
return -1;
if (is_specified_interface(interface, INTERFACE_ANDROID_LOGCAT_MAIN) && strlen(interface) > strlen(INTERFACE_ANDROID_LOGCAT_MAIN) + 1) {
serial_number = interface + strlen(INTERFACE_ANDROID_LOGCAT_MAIN) + 1;
} else if (is_specified_interface(interface, INTERFACE_ANDROID_LOGCAT_SYSTEM) && strlen(interface) > strlen(INTERFACE_ANDROID_LOGCAT_SYSTEM) + 1) {
serial_number = interface + strlen(INTERFACE_ANDROID_LOGCAT_SYSTEM) + 1;
} else if (is_specified_interface(interface, INTERFACE_ANDROID_LOGCAT_RADIO) && strlen(interface) > strlen(INTERFACE_ANDROID_LOGCAT_RADIO) + 1) {
serial_number = interface + strlen(INTERFACE_ANDROID_LOGCAT_RADIO) + 1;
} else if (is_specified_interface(interface, INTERFACE_ANDROID_LOGCAT_EVENTS) && strlen(interface) > strlen(INTERFACE_ANDROID_LOGCAT_EVENTS) + 1) {
serial_number = interface + strlen(INTERFACE_ANDROID_LOGCAT_EVENTS) + 1;
}
if (!serial_number) {
result = adb_send(sock, adb_transport);
if (result) {
if (verbose)
g_fprintf(stderr, "ERROR: Error while setting adb transport\n");
closesocket(sock);
return 1;
}
} else {
g_snprintf(packet, PACKET_LENGTH, adb_transport_serial_templace, 15 + strlen(serial_number), serial_number);
result = adb_send(sock, packet);
if (result) {
if (verbose)
g_fprintf(stderr, "ERROR: Error while setting adb transport\n");
closesocket(sock);
return 1;
}
}
if (is_specified_interface(interface, INTERFACE_ANDROID_LOGCAT_MAIN))
adb_command = adb_log_main;
else if (is_specified_interface(interface, INTERFACE_ANDROID_LOGCAT_SYSTEM))
adb_command = adb_log_system;
else if (is_specified_interface(interface, INTERFACE_ANDROID_LOGCAT_RADIO))
adb_command = adb_log_radio;
else if (is_specified_interface(interface, INTERFACE_ANDROID_LOGCAT_EVENTS))
adb_command = adb_log_events;
else {
g_printf("ERROR: Unknown interface: <%s>\n", interface);
closesocket(sock);
return -1;
}
result = adb_send(sock, adb_command);
if (result) {
if (verbose)
g_fprintf(stderr, "ERROR: Error while sending command <%s>\n", adb_command);
closesocket(sock);
return 1;
}
if (is_specified_interface(interface, INTERFACE_ANDROID_LOGCAT_EVENTS))
{
protocol_name = wireshark_protocol_logcat_events;
exported_pdu_header_protocol = &exported_pdu_header_protocol_events;
} else {
protocol_name = wireshark_protocol_logcat;
exported_pdu_header_protocol = &exported_pdu_header_protocol_normal;
}
memcpy(packet + exported_pdu_headers_size, exported_pdu_header_protocol, sizeof(struct exported_pdu_header));
exported_pdu_headers_size += sizeof(struct exported_pdu_header);
memcpy(packet + exported_pdu_headers_size, protocol_name, GINT16_FROM_BE(exported_pdu_header_protocol->length) - 2);
exported_pdu_headers_size += GINT16_FROM_BE(exported_pdu_header_protocol->length);
packet[exported_pdu_headers_size - 1] = 0;
packet[exported_pdu_headers_size - 2] = 0;
memcpy(packet + exported_pdu_headers_size, &exported_pdu_header_end, sizeof(struct exported_pdu_header));
exported_pdu_headers_size += sizeof(struct exported_pdu_header) + GINT16_FROM_BE(exported_pdu_header_end.length);
SET_DATA(payload_length, value_u16, packet + exported_pdu_headers_size + 0);
SET_DATA(try_header_size, value_u16, packet + exported_pdu_headers_size + 2);
SET_DATA(timestamp_secs, value_u32, packet + exported_pdu_headers_size + 12);
SET_DATA(timestamp_nsecs, value_u32, packet + exported_pdu_headers_size + 16);
while (endless_loop) {
errno = 0;
length = recv(sock, packet + exported_pdu_headers_size + used_buffer_length, (int)(PACKET_LENGTH - exported_pdu_headers_size - used_buffer_length), 0);
if (errno == EAGAIN || errno == EWOULDBLOCK) continue;
else if (errno != 0) {
if (verbose)
g_printf("ERROR capture: %s\n", strerror(errno));
closesocket(sock);
return 100;
}
if (length <= 0) {
while (endless_loop) {
if (verbose)
g_printf("WARNING: Broken socket connection. Try reconnect.\n");
used_buffer_length = 0;
closesocket(sock);
sock = adb_connect(adb_server_ip, adb_server_tcp_port);
if (sock == INVALID_SOCKET)
return -1;
if (!serial_number) {
result = adb_send(sock, adb_transport);
if (result) {
if (verbose)
g_fprintf(stderr, "ERROR: Error while setting adb transport for <%s>\n", adb_transport);
closesocket(sock);
return 1;
}
} else {
sprintf((char *) helper_packet, adb_transport_serial_templace, 15 + strlen(serial_number), serial_number);
result = adb_send(sock, helper_packet);
if (result) {
if (verbose)
g_fprintf(stderr, "ERROR: Error while setting adb transport for <%s>\n", helper_packet);
closesocket(sock);
return 1;
}
}
if (is_specified_interface(interface, INTERFACE_ANDROID_LOGCAT_MAIN))
adb_command = adb_log_main;
else if (is_specified_interface(interface, INTERFACE_ANDROID_LOGCAT_SYSTEM))
adb_command = adb_log_system;
else if (is_specified_interface(interface, INTERFACE_ANDROID_LOGCAT_RADIO))
adb_command = adb_log_radio;
else if (is_specified_interface(interface, INTERFACE_ANDROID_LOGCAT_EVENTS))
adb_command = adb_log_events;
else {
g_printf("ERROR: Unknown interface: <%s>\n", interface);
closesocket(sock);
return 1;
}
result = adb_send(sock, adb_command);
if (result) {
if (verbose)
g_fprintf(stderr, "ERROR: Error while sending command <%s>\n", adb_command);
continue;
}
break;
}
}
used_buffer_length += length + exported_pdu_headers_size;
if (*try_header_size == 0 || *try_header_size != 24)
header_size = 20;
else
header_size = *try_header_size;
length = (*payload_length) + header_size + (gssize)exported_pdu_headers_size;
while (used_buffer_length >= exported_pdu_headers_size + header_size && (size_t)length <= used_buffer_length) {
extcap_dumper_dump(extcap_dumper, packet,
length,
length,
*timestamp_secs, *timestamp_nsecs);
memmove(packet + exported_pdu_headers_size, packet + length, used_buffer_length - length);
used_buffer_length -= length;
used_buffer_length += exported_pdu_headers_size;
length = (*payload_length) + header_size + (gssize)exported_pdu_headers_size;
if (*try_header_size == 0 || *try_header_size != 24)
header_size = 20;
else
header_size = *try_header_size;
}
used_buffer_length -= exported_pdu_headers_size;
}
closesocket(sock);
return 0;
}
/*============================================================================*/
#ifdef _WIN32
BOOLEAN IsHandleRedirected(DWORD handle)
{
HANDLE h = GetStdHandle(handle);
if (h) {
BY_HANDLE_FILE_INFORMATION fi;
if (GetFileInformationByHandle(h, &fi)) {
return TRUE;
}
}
return FALSE;
}
static void attach_parent_console()
{
BOOL outRedirected, errRedirected;
outRedirected = IsHandleRedirected(STD_OUTPUT_HANDLE);
errRedirected = IsHandleRedirected(STD_ERROR_HANDLE);
if (outRedirected && errRedirected) {
/* Both standard output and error handles are redirected.
* There is no point in attaching to parent process console.
*/
return;
}
if (AttachConsole(ATTACH_PARENT_PROCESS) == 0) {
/* Console attach failed. */
return;
}
/* Console attach succeeded */
if (outRedirected == FALSE) {
freopen("CONOUT$", "w", stdout);
}
if (errRedirected == FALSE) {
freopen("CONOUT$", "w", stderr);
}
}
#endif
/*----------------------------------------------------------------------------*/
/* Android Wifi Tcpdump */
/* The Tcpdump sends data in pcap format. So for using the extcap_dumper we */
/* need to unpack the pcap and then send the packet data to the dumper. */
/*----------------------------------------------------------------------------*/
static int capture_android_wifi_tcpdump(char *interface, char *fifo,
const char *adb_server_ip, unsigned short *adb_server_tcp_port) {
struct extcap_dumper extcap_dumper;
static char data[PACKET_LENGTH];
static char helpful_packet[PACKET_LENGTH];
gssize length;
gssize used_buffer_length = 0;
gssize filter_buffer_length = 0;
gssize frame_length=0;
socket_handle_t sock;
const char *adb_transport = "0012" "host:transport-any";
const char *adb_transport_serial_templace = "%04x" "host:transport:%s";
const char *adb_shell_tcpdump = "001D" "shell:tcpdump -n -s 0 -u -w -";
gint result;
char *serial_number = NULL;
char filter_buffer[PACKET_LENGTH];
gint device_endiness;
gboolean global_header_skipped=FALSE;
pcaprec_hdr_t p_header;
/* First check for the device if it is connected or not */
sock = adb_connect(adb_server_ip, adb_server_tcp_port);
if (sock == INVALID_SOCKET)
return -1;
if (is_specified_interface(interface, INTERFACE_ANDROID_WIFI_TCPDUMP)
&& strlen(interface) > strlen(INTERFACE_ANDROID_WIFI_TCPDUMP) + 1) {
serial_number = interface + strlen(INTERFACE_ANDROID_WIFI_TCPDUMP) + 1;
}
if (!serial_number) {
result = adb_send(sock, adb_transport);
if (result) {
if (verbose)
g_printf("ERROR: Error while setting adb transport");
fflush(stdout);
g_fprintf(stderr,
"ERROR: Error while setting adb transport for <%s>\n",
adb_transport);
closesocket(sock);
return 1;
}
} else {
sprintf((char *) helpful_packet, adb_transport_serial_templace,
15 + strlen(serial_number), serial_number);
result = adb_send(sock, helpful_packet);
if (result) {
g_printf("ERROR: Error while setting adb transport");
fflush(stdout);
if (verbose)
g_fprintf(stderr,
"ERROR: Error while setting adb transport for <%s>\n",
helpful_packet);
closesocket(sock);
return 1;
}
}
result = adb_send(sock, adb_shell_tcpdump);
if (result) {
g_printf("ERROR: Error while setting adb transport");
fflush(stdout);
if (verbose)
g_fprintf(stderr,
"ERROR: Error while starting capture by sending command: %s\n",
adb_shell_tcpdump);
closesocket(sock);
return 1;
}
extcap_dumper = extcap_dumper_open(fifo, EXTCAP_ENCAP_ETHERNET);
while (endless_loop) {
char *i_position;
errno = 0;
length = recv(sock, data + used_buffer_length, (int)(PACKET_LENGTH - used_buffer_length), 0);
if (errno == EAGAIN || errno == EWOULDBLOCK)
continue;
else if (errno != 0) {
if (verbose)
g_printf("ERROR capture: %s\n", strerror(errno));
return 100;
}
used_buffer_length += length;
/*
* Checking for the starting for the pcap global header using the magic number
*/
if (used_buffer_length > 4) {
guint * magic_number;
magic_number= (guint *)data;
if (*magic_number == 0xd4c3b2a1 ||*magic_number == 0xa1b2c3d4) {
if (data[0]==(char)0xd4){
device_endiness=G_LITTLE_ENDIAN;
}
else {
device_endiness=G_BIG_ENDIAN;
}
break;
}
}
i_position = (char *) memchr(data, '\n', used_buffer_length);
if (i_position && i_position < data + used_buffer_length) {
memmove(data, i_position + 1 , used_buffer_length - (i_position + 1 - data));
used_buffer_length = used_buffer_length - (gssize) (i_position + 1 - data);
}
}
/*
* The data we are getting from the tcpdump stdoutput stream as the stdout is the text stream it is
* convertinng the 0A=0D0A; So we need to remove these extra character.
*/
filter_buffer_length=0;
while (endless_loop) {
gssize i = 0,read_offset,j=0;
/*Filter the received data to get rid of unwanted 0DOA*/
for (i = 0; i < (used_buffer_length - 1); i++) {
if (data[i] == 0x0d && data[i + 1] == 0x0a) {
i++;
}
filter_buffer[filter_buffer_length++] = data[i];
}
/* Put the last characters in the start if it is still left in buffer.*/
for (j=0; i < used_buffer_length; i++,j++) {
data[j] = data[i];
}
used_buffer_length = j;
if (global_header_skipped==FALSE && filter_buffer_length >= PCAP_GLOBAL_HEADER_LENGTH) {
/*Skip the Global pcap header*/
filter_buffer_length -= PCAP_GLOBAL_HEADER_LENGTH;
/*Move the remaining content from start*/
memmove(filter_buffer , filter_buffer + PCAP_GLOBAL_HEADER_LENGTH , filter_buffer_length);
global_header_skipped = TRUE;
}
else if (global_header_skipped && filter_buffer_length > PCAP_RECORD_HEADER_LENGTH) {
read_offset=0;
while (filter_buffer_length > PCAP_RECORD_HEADER_LENGTH) {
gchar *packet;
packet = filter_buffer + read_offset;
/*
* This fills the pcap header info based upon the endianess of the machine and android device.
* If the endianess are different, pcap header bytes received from the android device are swapped
* to be read properly by the machine else pcap header bytes are taken as it is.
*/
if (device_endiness == G_BYTE_ORDER) {
p_header = *((pcaprec_hdr_t*)packet);
}
else {
p_header.ts_sec = GUINT32_SWAP_LE_BE(*((guint32*)packet));
p_header.ts_usec = GUINT32_SWAP_LE_BE(*(guint32*)(packet +4));
p_header.incl_len = GUINT32_SWAP_LE_BE(*(guint32*)(packet +8));
p_header.orig_len = GUINT32_SWAP_LE_BE(*(guint32*)(packet +12));
}
if ((gssize)(p_header.incl_len + PCAP_RECORD_HEADER_LENGTH) <= filter_buffer_length) {
/*
* It was observed that some times tcpdump reports the length of packet as '0'
