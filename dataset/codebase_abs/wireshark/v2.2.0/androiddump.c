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
F_4 ( L_1 ) ;
exit ( V_14 ) ;
}
V_7 = F_5 ( V_6 , V_15 , V_16 ) ;
V_3 . V_17 . V_7 = F_6 ( V_7 , V_4 ) ;
if ( ! V_3 . V_17 . V_7 ) {
F_4 ( L_2 ) ;
exit ( V_18 ) ;
}
V_3 . V_5 = V_5 ;
F_7 ( V_3 . V_17 . V_7 ) ;
#else
int V_19 = 0 ;
F_8 () ;
#ifdef F_9
F_10 () ;
F_11 () ;
#endif
if ( V_5 == V_8 )
V_6 = V_20 ;
else if ( V_5 == V_10 )
V_6 = V_21 ;
else if ( V_5 == V_12 )
V_6 = V_22 ;
else {
F_4 ( L_3 ) ;
exit ( V_23 ) ;
}
V_3 . V_17 . V_24 = F_12 ( V_4 , V_25 , V_6 , V_15 , FALSE , & V_19 ) ;
if ( ! V_3 . V_17 . V_24 ) {
F_4 ( L_4 ) ;
exit ( V_26 ) ;
}
V_3 . V_5 = V_5 ;
F_13 ( V_3 . V_17 . V_24 ) ;
#endif
return V_3 ;
}
static T_2 F_14 ( struct V_3 V_3 , char * V_27 ,
T_3 V_28 , T_3 V_29 ,
T_4 V_30 , int V_31 ) {
#ifdef F_3
struct V_32 V_33 ;
V_33 . V_34 = ( V_35 ) V_28 ;
V_33 . V_36 = ( V_35 ) V_29 ;
V_33 . V_37 . V_38 = V_30 ;
V_33 . V_37 . V_39 = V_31 / 1000 ;
F_15 ( ( V_40 * ) V_3 . V_17 . V_7 , & V_33 , V_27 ) ;
F_7 ( V_3 . V_17 . V_7 ) ;
#else
int V_19 = 0 ;
char * V_41 ;
struct V_42 V_43 ;
V_43 . V_44 = V_45 ;
V_43 . V_34 = ( V_46 ) V_28 ;
V_43 . V_36 = ( V_46 ) V_29 ;
V_43 . V_37 . V_47 = V_30 ;
V_43 . V_37 . V_48 = ( int ) V_31 ;
V_43 . V_49 = 0 ;
V_43 . V_49 = NULL ;
V_43 . V_50 = 0 ;
V_43 . V_51 = 0 ;
V_43 . V_52 = V_53 ;
if ( V_3 . V_5 == V_8 ) {
T_5 * V_54 ;
F_16 (direction, value_u32, buffer)
V_43 . V_55 . V_56 . V_57 = F_17 ( * V_54 ) ? 0 : 1 ;
V_43 . V_36 -= ( V_46 ) sizeof( V_58 ) ;
V_43 . V_34 -= ( V_46 ) sizeof( V_58 ) ;
V_27 += sizeof( V_58 ) ;
V_43 . V_59 = V_20 ;
}
else if ( V_3 . V_5 == V_12 ) {
V_43 . V_59 = V_22 ;
}
else {
V_43 . V_59 = V_21 ;
}
if ( ! F_18 ( V_3 . V_17 . V_24 , & V_43 , ( const V_60 * ) V_27 , & V_19 , & V_41 ) ) {
F_4 ( L_5 , V_41 ) ;
return FALSE ;
}
F_13 ( V_3 . V_17 . V_24 ) ;
#endif
return TRUE ;
}
static T_6 F_19 ( const char * V_61 , unsigned short * V_62 ) {
T_6 V_63 ;
T_7 V_64 ;
struct V_65 V_66 ;
memset ( & V_66 , 0x0 , sizeof( V_66 ) ) ;
V_66 . V_67 = V_68 ;
V_66 . V_69 = F_20 ( * V_62 ) ;
V_66 . V_70 . V_71 = F_21 ( V_61 ) ;
if ( ( V_63 = F_22 ( V_68 , V_72 , V_73 ) ) == V_74 ) {
F_4 ( L_6 , strerror ( V_75 ) ) ;
return V_74 ;
}
if ( F_23 ( V_63 , (struct V_76 * ) & V_66 , sizeof( V_66 ) ) == V_77 ) {
#if 0
#ifdef F_24
if (_execlp("adb", "adb", "start-server", NULL)) {
#else
if (execlp("adb", "adb", "start-server", NULL)) {
#endif
errmsg("WARNING: Cannot execute system command to start adb: %s", strerror(errno));
closesocket(sock);
return INVALID_SOCKET;
};
if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == SOCKET_ERROR) {
errmsg_print("ERROR: Cannot connect to ADB: <%s> Please check that adb daemon is running.", strerror(errno));
closesocket(sock);
return INVALID_SOCKET;
}
#else
F_25 ( L_7 , strerror ( V_75 ) ) ;
F_26 ( V_63 ) ;
return V_74 ;
#endif
}
if ( V_78 ) {
struct V_65 V_79 ;
V_64 = sizeof( V_79 ) ;
if ( F_27 ( V_63 , (struct V_76 * ) & V_79 , & V_64 ) ) {
F_4 ( L_8 , strerror ( V_75 ) ) ;
F_26 ( V_63 ) ;
return V_74 ;
}
if ( V_64 != sizeof( V_79 ) ) {
F_4 ( L_9 ) ;
F_26 ( V_63 ) ;
return V_74 ;
}
F_25 ( L_10 , F_28 ( V_79 . V_69 ) ) ;
}
return V_63 ;
}
static char * F_29 ( T_6 V_63 , const char * V_80 ,
char * V_27 , int V_81 , T_3 * V_82 ) {
T_3 V_83 ;
T_3 V_64 ;
T_3 V_84 ;
char V_85 [ 4 ] ;
char V_86 ;
T_8 V_87 ;
V_87 = strlen ( V_80 ) ;
V_84 = F_30 ( V_63 , V_80 , ( int ) V_87 , 0 ) ;
if ( V_84 != ( T_3 ) V_87 ) {
F_4 ( L_11 , V_80 ) ;
if ( V_82 )
* V_82 = 0 ;
return NULL ;
}
V_83 = 0 ;
while ( V_83 < 8 ) {
V_84 = F_31 ( V_63 , V_27 + V_83 , ( int ) ( V_81 - V_83 ) , 0 ) ;
if ( V_84 <= 0 ) {
F_4 ( L_12 , V_80 ) ;
return NULL ;
}
V_83 += V_84 ;
}
memcpy ( V_85 , V_27 , 4 ) ;
V_86 = V_27 [ 8 ] ;
V_27 [ 8 ] = '\0' ;
V_64 = ( T_3 ) F_32 ( V_27 + 4 , NULL , 16 ) ;
V_27 [ 8 ] = V_86 ;
while ( V_83 < V_64 + 8 ) {
V_84 = F_31 ( V_63 , V_27 + V_83 , ( int ) ( V_81 - V_83 ) , 0 ) ;
if ( V_84 <= 0 ) {
F_4 ( L_13 , V_80 ) ;
return NULL ;
}
V_83 += V_84 ;
}
if ( V_82 )
* V_82 = V_83 - 8 ;
if ( memcmp ( V_85 , L_14 , 4 ) ) {
F_4 ( L_15 , V_80 ) ;
if ( V_82 )
* V_82 = 0 ;
return NULL ;
}
return V_27 + 8 ;
}
static char * F_33 ( T_6 V_63 , const char * V_80 , char * V_27 ,
int V_81 , T_3 * V_82 ) {
T_3 V_83 ;
T_3 V_84 ;
char V_85 [ 4 ] ;
T_8 V_87 ;
V_87 = strlen ( V_80 ) ;
V_84 = F_30 ( V_63 , V_80 , ( int ) V_87 , 0 ) ;
if ( V_84 != ( T_3 ) V_87 ) {
F_4 ( L_16 , V_80 ) ;
if ( V_82 )
* V_82 = 0 ;
return NULL ;
}
V_83 = 0 ;
while ( V_83 < 4 ) {
V_84 = F_31 ( V_63 , V_27 + V_83 , ( int ) ( V_81 - V_83 ) , 0 ) ;
if ( V_84 <= 0 ) {
F_4 ( L_12 , V_80 ) ;
return NULL ;
}
V_83 += V_84 ;
}
memcpy ( V_85 , V_27 , 4 ) ;
while ( V_84 > 0 ) {
V_84 = F_31 ( V_63 , V_27 + V_83 , ( int ) ( V_81 - V_83 ) , 0 ) ;
if ( V_84 < 0 ) {
F_4 ( L_13 , V_80 ) ;
return NULL ;
} else if ( V_84 == 0 ) {
break;
}
V_83 += V_84 ;
}
if ( V_82 )
* V_82 = V_83 - 4 ;
if ( memcmp ( V_85 , L_14 , 4 ) ) {
F_4 ( L_15 , V_80 ) ;
if ( V_82 )
* V_82 = 0 ;
return NULL ;
}
return V_27 + 4 ;
}
static int F_34 ( T_6 V_63 , const char * V_80 ) {
char V_27 [ 4 ] ;
T_3 V_83 ;
T_3 V_84 ;
T_8 V_87 ;
V_87 = strlen ( V_80 ) ;
V_84 = F_30 ( V_63 , V_80 , ( int ) V_87 , 0 ) ;
if ( V_84 != ( T_3 ) V_87 ) {
F_4 ( L_16 , V_80 ) ;
return V_88 ;
}
V_83 = 0 ;
while ( V_83 < 4 ) {
V_84 = F_31 ( V_63 , V_27 + V_83 , ( int ) ( sizeof( V_27 ) - V_83 ) , 0 ) ;
if ( V_84 <= 0 ) {
F_4 ( L_12 , V_80 ) ;
return V_89 ;
}
V_83 += V_84 ;
}
if ( memcmp ( V_27 , L_14 , 4 ) ) {
F_4 ( L_15 , V_80 ) ;
return V_90 ;
}
return V_91 ;
}
static void F_35 ( T_9 * V_92 , const T_10 * V_93 ,
const T_10 * V_94 , const T_10 * V_95 , const T_10 * V_96 )
{
char * V_1 = F_36 ( L_17 , V_93 , V_95 ) ;
char * V_97 = F_36 ( L_18 , V_96 , V_94 , V_95 ) ;
if ( F_1 ( V_1 , V_98 ) ||
F_1 ( V_1 , V_99 ) ||
F_1 ( V_1 , V_100 ) ) {
F_37 ( V_92 , V_1 , V_97 , 99 , L_19 , L_20 ) ;
} else if ( F_1 ( V_1 , V_101 ) ||
F_1 ( V_1 , V_102 ) ||
F_1 ( V_1 , V_103 ) ||
F_1 ( V_1 , V_104 ) ||
F_1 ( V_1 , V_105 ) ||
F_1 ( V_1 , V_106 ) ||
F_1 ( V_1 , V_107 ) ||
F_1 ( V_1 , V_108 ) ||
F_1 ( V_1 , V_109 ) ) {
F_38 ( V_92 , V_1 , V_97 , 252 , L_21 ) ;
} else if ( F_1 ( V_1 , V_110 ) ) {
F_38 ( V_92 , V_1 , V_97 , 1 , L_22 ) ;
}
F_39 ( V_1 ) ;
F_39 ( V_97 ) ;
}
static int F_40 ( T_9 * V_92 , const char * V_111 , unsigned short * V_112 ) {
static char V_113 [ V_15 ] ;
static char V_114 [ V_15 ] ;
char * V_115 ;
char * V_116 ;
T_3 V_82 ;
T_3 V_117 ;
T_6 V_63 ;
const char * V_118 = L_23 V_119 : V_120 : % V_121 L_24 % 04x L_25 V_122 : V_123 / V_124 / % V_121 / V_125 / V_126 L_26 000E L_25 V_119 : V_127 - V_128 L_27 0022 L_25 V_122 : V_129 V_130 . V_131 . V_132 . V_133 L_28 0017 L_25 V_122 : V_134 -- V_132 L_29 0018 L_25 V_122 : V_135 V_136 . V_137 L_30 001E L_25 V_122 : V_135 V_138 . V_139 . V_137 L_31 0010 L_25 V_122 : V_140 - V_141 L_32 V_142 V_127 L_33 V_142 V_122 L_34 ERROR : V_143 V_144 V_145 V_146 V_147 V_148 V_127 L_35 V_149 : V_150 V_151 V_152 long , V_153 V_154\V_155");
continue;
}
memcpy(serial_number, prev_pos, result);
serial_number[result] = '\0';
serial_number_length = strlen(serial_number);
model_name[0] = '\0';
model_pos = g_strstr_len(i_pos, pos - i_pos, "V_156 : L_36 V_154 : L_37 V_157 L_38 V_158 : V_159 V_154 : \ L_39 , V_95 , V_94 );
V_63 = F_19 ( V_111 , V_112 ) ;
if ( V_63 == V_74 ) continue;
V_84 = F_41 ( ( char * ) V_114 , V_15 , V_118 , 15 + V_160 , V_95 ) ;
if ( V_84 <= 0 || V_84 > V_15 ) {
F_4 ( L_40 ) ;
F_26 ( V_63 ) ;
return V_161 ;
}
V_84 = F_34 ( V_63 , V_114 ) ;
if ( V_84 ) {
F_25 ( L_41 , V_114 ) ;
F_26 ( V_63 ) ;
} else {
V_115 = F_33 ( V_63 , V_162 , V_114 , sizeof( V_114 ) , & V_82 ) ;
F_26 ( V_63 ) ;
if ( V_115 ) {
V_115 [ V_82 ] = '\0' ;
if ( strstr ( V_115 , L_42 ) ) {
F_35 ( V_92 , V_110 , V_94 , V_95 , L_43 ) ;
}
} else {
F_25 ( L_44 , V_114 ) ;
}
}
V_63 = F_19 ( V_111 , V_112 ) ;
if ( V_63 == V_74 ) continue;
V_84 = F_41 ( ( char * ) V_114 , V_15 , V_118 , 15 + V_160 , V_95 ) ;
if ( V_84 <= 0 || V_84 > V_15 ) {
F_4 ( L_45 ) ;
F_26 ( V_63 ) ;
return V_163 ;
}
V_84 = F_34 ( V_63 , V_114 ) ;
if ( V_84 ) {
F_25 ( L_41 , V_114 ) ;
F_26 ( V_63 ) ;
continue;
}
V_115 = F_33 ( V_63 , V_164 , V_114 , sizeof( V_114 ) , & V_82 ) ;
F_26 ( V_63 ) ;
if ( ! V_115 ) {
F_25 ( L_44 , V_114 ) ;
continue;
}
V_115 [ V_82 ] = '\0' ;
V_165 = ( int ) F_32 ( V_115 , NULL , 10 ) ;
F_25 ( L_46 , V_95 , V_165 ) ;
if ( V_165 < 21 ) {
F_35 ( V_92 , V_101 , V_94 , V_95 , L_47 ) ;
F_35 ( V_92 , V_102 , V_94 , V_95 , L_48 ) ;
F_35 ( V_92 , V_103 , V_94 , V_95 , L_49 ) ;
F_35 ( V_92 , V_104 , V_94 , V_95 , L_50 ) ;
} else {
F_35 ( V_92 , V_105 , V_94 , V_95 , L_47 ) ;
F_35 ( V_92 , V_106 , V_94 , V_95 , L_48 ) ;
F_35 ( V_92 , V_107 , V_94 , V_95 , L_49 ) ;
F_35 ( V_92 , V_108 , V_94 , V_95 , L_50 ) ;
F_35 ( V_92 , V_109 , V_94 , V_95 , L_51 ) ;
}
if ( V_165 >= 5 && V_165 < 17 ) {
V_166 = 0 ;
V_63 = F_19 ( V_111 , V_112 ) ;
if ( V_63 == V_74 ) continue;
V_84 = F_41 ( ( char * ) V_114 , V_15 , V_118 , 15 + V_160 , V_95 ) ;
if ( V_84 <= 0 || V_84 > V_15 ) {
F_4 ( L_45 ) ;
F_26 ( V_63 ) ;
return V_167 ;
}
V_84 = F_34 ( V_63 , V_114 ) ;
if ( V_84 ) {
F_4 ( L_52 , V_114 ) ;
F_26 ( V_63 ) ;
return V_168 ;
}
V_115 = F_33 ( V_63 , V_169 , V_114 , sizeof( V_114 ) , & V_82 ) ;
F_26 ( V_63 ) ;
if ( ! V_115 || V_82 < 1 ) {
F_25 ( L_53 V_170 L_54 ,
V_169 , ( void * ) V_115 , V_82 ) ;
F_25 ( L_55 , V_95 ) ;
V_166 = 1 ;
} else {
V_115 [ V_82 ] = '\0' ;
if ( F_42 ( V_115 , NULL , 10 ) == 0 ) {
F_25 ( L_55 , V_95 ) ;
V_166 = 1 ;
} else {
F_25 ( L_56 , V_95 , V_115 ) ;
}
}
if ( ! V_166 ) {
F_35 ( V_92 , V_98 , V_94 , V_95 , L_57 ) ;
}
}
if ( V_165 >= 17 && V_165 < 21 ) {
V_166 = 0 ;
V_63 = F_19 ( V_111 , V_112 ) ;
if ( V_63 == V_74 ) continue;
V_84 = F_41 ( ( char * ) V_114 , V_15 , V_118 , 15 + V_160 , V_95 ) ;
if ( V_84 <= 0 || V_84 > V_15 ) {
F_4 ( L_45 ) ;
F_26 ( V_63 ) ;
return V_171 ;
}
V_84 = F_34 ( V_63 , V_114 ) ;
if ( V_84 ) {
F_4 ( L_52 , V_114 ) ;
F_26 ( V_63 ) ;
return V_168 ;
}
V_115 = F_33 ( V_63 , V_172 , V_114 , sizeof( V_114 ) , & V_82 ) ;
F_26 ( V_63 ) ;
if ( ! V_115 || V_82 < 1 ) {
F_25 ( L_58
L_59 V_170 L_54 , V_169 , ( void * ) V_115 , V_82 ) ;
F_25 ( L_60 , V_95 ) ;
V_166 = 1 ;
} else {
char * V_173 ;
char V_174 [ 16 ] ;
memset ( V_174 , 0 , sizeof( V_174 ) ) ;
V_115 [ V_82 ] = '\0' ;
V_173 = strchr ( V_115 , '\n' ) ;
if ( V_173 && sscanf ( V_173 , L_61 , V_174 ) == 1 ) {
F_25 ( L_62 , V_95 , V_174 ) ;
V_63 = F_19 ( V_111 , V_112 ) ;
if ( V_63 == V_74 )
return V_175 ;
V_84 = F_41 ( ( char * ) V_114 , V_15 , V_118 , 15 + V_160 , V_95 ) ;
if ( V_84 <= 0 || V_84 > V_15 ) {
F_4 ( L_45 ) ;
F_26 ( V_63 ) ;
return V_176 ;
}
V_84 = F_34 ( V_63 , V_114 ) ;
if ( V_84 ) {
F_4 ( L_52 , V_114 ) ;
F_26 ( V_63 ) ;
return V_168 ;
}
V_84 = F_41 ( ( char * ) V_114 , V_15 , V_177 , strlen ( V_177 ) - 6 + strlen ( V_174 ) , V_174 ) ;
if ( V_84 <= 0 || V_84 > V_15 ) {
F_4 ( L_45 ) ;
F_26 ( V_63 ) ;
return V_178 ;
}
V_115 = F_33 ( V_63 , V_114 , V_114 , sizeof( V_114 ) , & V_82 ) ;
F_26 ( V_63 ) ;
if ( ! V_115 ) {
V_166 = 1 ;
} else {
V_115 [ V_82 ] = '\0' ;
V_173 = strchr ( V_115 , '\n' ) ;
if ( V_173 && sscanf ( V_173 , L_61 , V_174 ) == 1 && strcmp ( V_174 + 9 , L_63 ) == 0 ) {
F_25 ( L_64 , V_95 , V_174 + 9 ) ;
} else {
V_166 = 1 ;
F_25 ( L_65 , V_95 ) ;
}
}
} else {
V_166 = 1 ;
F_25 ( L_60 , V_95 ) ;
}
}
if ( ! V_166 ) {
F_35 ( V_92 , V_99 , V_94 , V_95 , L_66 ) ;
}
}
if ( V_165 >= 21 ) {
V_166 = 0 ;
V_63 = F_19 ( V_111 , V_112 ) ;
if ( V_63 == V_74 ) continue;
V_84 = F_41 ( ( char * ) V_114 , V_15 , V_118 , 15 + V_160 , V_95 ) ;
if ( V_84 <= 0 || V_84 > V_15 ) {
F_4 ( L_45 ) ;
F_26 ( V_63 ) ;
return V_179 ;
}
V_84 = F_34 ( V_63 , V_114 ) ;
if ( V_84 ) {
F_4 ( L_52 , V_114 ) ;
F_26 ( V_63 ) ;
return V_168 ;
}
if ( V_165 >= 23 ) {
V_115 = F_33 ( V_63 , V_180 , V_114 , sizeof( V_114 ) , & V_82 ) ;
} else
V_115 = F_33 ( V_63 , V_172 , V_114 , sizeof( V_114 ) , & V_82 ) ;
F_26 ( V_63 ) ;
if ( ! V_115 || V_82 < 1 ) {
F_25 ( L_58
L_59 V_170 L_54 , V_169 , ( void * ) V_115 , V_82 ) ;
F_25 ( L_60 , V_95 ) ;
V_166 = 1 ;
} else {
char * V_173 ;
char V_174 [ 16 ] ;
memset ( V_174 , 0 , sizeof( V_174 ) ) ;
V_115 [ V_82 ] = '\0' ;
V_173 = strchr ( V_115 , '\n' ) ;
if ( V_173 && sscanf ( V_173 , L_61 , V_174 ) == 1 ) {
F_25 ( L_62 , V_95 , V_174 ) ;
V_63 = F_19 ( V_111 , V_112 ) ;
if ( V_63 == V_74 )
return V_181 ;
V_84 = F_41 ( ( char * ) V_114 , V_15 , V_118 , 15 + V_160 , V_95 ) ;
if ( V_84 <= 0 || V_84 > V_15 ) {
F_4 ( L_45 ) ;
F_26 ( V_63 ) ;
return V_182 ;
}
V_84 = F_34 ( V_63 , V_114 ) ;
if ( V_84 ) {
F_4 ( L_52 , V_114 ) ;
F_26 ( V_63 ) ;
return V_168 ;
}
V_84 = F_41 ( ( char * ) V_114 , V_15 , V_177 , strlen ( V_177 ) - 6 + strlen ( V_174 ) , V_174 ) ;
if ( V_84 <= 0 || V_84 > V_15 ) {
F_4 ( L_45 ) ;
F_26 ( V_63 ) ;
return V_183 ;
}
V_115 = F_33 ( V_63 , V_114 , V_114 , sizeof( V_114 ) , & V_82 ) ;
F_26 ( V_63 ) ;
if ( ! V_115 ) {
V_166 = 1 ;
} else {
V_115 [ V_82 ] = '\0' ;
V_173 = strchr ( V_115 , '\n' ) ;
if ( V_173 && sscanf ( V_173 , L_61 , V_174 ) == 1 && strcmp ( V_174 + 9 , L_67 ) == 0 ) {
F_25 ( L_68 , V_95 , V_174 + 9 ) ;
} else {
V_166 = 1 ;
F_25 ( L_69 , V_95 ) ;
}
}
} else {
V_166 = 1 ;
F_25 ( L_60 , V_95 ) ;
}
}
if ( ! V_166 ) {
F_35 ( V_92 , V_100 , V_94 , V_95 , L_70 ) ;
}
}
}
int F_43 ( char * V_1 ) {
if ( ! V_1 ) {
F_4 ( L_71 ) ;
return V_184 ;
}
if ( F_1 ( V_1 , V_99 ) ) {
printf ( L_72
L_73
L_74
L_75
L_76
L_77
L_78 ) ;
return V_91 ;
} else if ( F_1 ( V_1 , V_98 ) ||
F_1 ( V_1 , V_100 ) ||
F_1 ( V_1 , V_110 ) ) {
printf ( L_72
L_73
L_79 ) ;
return V_91 ;
} else if ( F_1 ( V_1 , V_101 ) ||
F_1 ( V_1 , V_102 ) ||
F_1 ( V_1 , V_103 ) ||
F_1 ( V_1 , V_104 ) ) {
printf ( L_72
L_73
L_80
L_81 ) ;
return V_91 ;
} else if ( F_1 ( V_1 , V_105 ) ||
F_1 ( V_1 , V_106 ) ||
F_1 ( V_1 , V_107 ) ||
F_1 ( V_1 , V_108 ) ||
F_1 ( V_1 , V_109 ) ) {
printf ( L_72
L_73
L_79 ) ;
return V_91 ;
}
F_4 ( L_82 , V_1 ) ;
return V_185 ;
}
static void F_44 ( void ) {
unsigned int V_186 ;
printf ( L_83 ) ;
printf ( L_84
L_85
L_86
L_87
L_88 ) ;
printf ( L_89 ) ;
for ( V_186 = 0 ; V_186 < ( sizeof( V_187 ) / sizeof( V_187 [ 0 ] ) ) - 1 ; V_186 += 1 ) {
printf ( L_90 , V_187 [ V_186 ] . V_188 ,
( V_187 [ V_186 ] . V_189 == V_190 ) ? L_91 :
( ( V_187 [ V_186 ] . V_189 == V_191 ) ? L_92 : L_25 ) ) ;
}
}
static int F_45 ( char * V_1 , char * V_4 ,
const char * V_111 , unsigned short * V_112 ) {
struct V_3 V_3 ;
static char V_192 [ V_15 ] ;
static char V_113 [ V_15 ] ;
static char V_114 [ V_15 ] ;
T_3 V_64 ;
T_3 V_83 = 0 ;
T_6 V_63 ;
const char * V_193 = L_93 V_119 : V_120 - V_194 L_94 % 04x L_25 V_119 : V_120 : % V_121 L_95 0013 L_25 V_122 : V_134 - V_195 - V_196 L_96 0019 L_25 V_122 : V_197 - V_198 V_134 - V_195 - V_196 L_97 ERROR : Error while setting adb transport for <%s>", adb_transport);
closesocket(sock);
return EXIT_CODE_GENERIC;
}
} else {
result = g_snprintf((char *) helpful_packet, PACKET_LENGTH, adb_transport_serial_templace, 15 + serial_number_length, serial_number);
if (result <= 0 || result > PACKET_LENGTH) {
errmsg_print("ERROR: Error while completing adb packet");
closesocket(sock);
return EXIT_CODE_BAD_SIZE_OF_ASSEMBLED_ADB_PACKET_10;
}
result = adb_send(sock, helpful_packet);
if (result) {
errmsg_print("ERROR: Error while setting adb transport for <%s>", helpful_packet);
closesocket(sock);
return EXIT_CODE_GENERIC;
}
}
result = adb_send(sock, adb_shell_hcidump);
if (result) {
errmsg_print("ERROR: Error while starting capture by sending command: %s", adb_shell_hcidump);
closesocket(sock);
return EXIT_CODE_GENERIC;
}
while (endless_loop) {
char *i_position;
errno = 0;
length = recv(sock, data + used_buffer_length, (int)(PACKET_LENGTH - used_buffer_length), 0);
if (errno == EAGAIN
#if EWOULDBLOCK != EAGAIN
|| errno == EWOULDBLOCK
#endif
) {
continue;
}
else if (errno != 0) {
errmsg_print("ERROR capture: %s", strerror(errno));
closesocket(sock);
return EXIT_CODE_GENERIC;
}
if (length <= 0) {
errmsg_print("ERROR: Broken socket connection.");
closesocket(sock);
return EXIT_CODE_GENERIC;
}
used_buffer_length += length;
i_position = (char *) memchr(data, '\n', used_buffer_length);
if (i_position && i_position < data + used_buffer_length) {
char *state_line_position = i_position + 1;
if (!strncmp(data, "/system/bin/sh: hcidump: not found", 34)) {
errmsg_print("ERROR: Command not found for <%s>", adb_shell_hcidump);
closesocket(sock);
return EXIT_CODE_GENERIC;
}
i_position = (char *) memchr(i_position + 1, '\n', used_buffer_length);
if (i_position) {
i_position += 1;
if (!strncmp(state_line_position, "Can't access device: Permission denied", 38)) {
verbose_print("WARNING: No permission for command <%s>\n", adb_shell_hcidump);
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
return EXIT_CODE_INVALID_SOCKET_4;
result = g_snprintf((char *) helpful_packet, PACKET_LENGTH, adb_transport_serial_templace, 15 + serial_number_length, serial_number);
if (result <= 0 || result > PACKET_LENGTH) {
errmsg_print("ERROR: Error while completing adb packet");
closesocket(sock);
return EXIT_CODE_BAD_SIZE_OF_ASSEMBLED_ADB_PACKET_11;
}
result = adb_send(sock, helpful_packet);
if (result) {
errmsg_print("ERROR: Error while setting adb transport for <%s>", helpful_packet);
closesocket(sock);
return EXIT_CODE_GENERIC;
}
result = adb_send(sock, adb_shell_su_hcidump);
if (result) {
errmsg_print("ERROR: Error while starting capture by sending command: <%s>", adb_shell_su_hcidump);
closesocket(sock);
return EXIT_CODE_GENERIC;
}
used_buffer_length = 0;
while (endless_loop) {
char *i_position;
errno = 0;
length = recv(sock, data + used_buffer_length, (int)(PACKET_LENGTH - used_buffer_length), 0);
if (errno == EAGAIN
#if EWOULDBLOCK != EAGAIN
|| errno == EWOULDBLOCK
#endif
) {
continue;
}
else if (errno != 0) {
errmsg_print("ERROR capture: %s", strerror(errno));
closesocket(sock);
return EXIT_CODE_GENERIC;
}
if (length <= 0) {
errmsg_print("ERROR: Broken socket connection.");
closesocket(sock);
return EXIT_CODE_GENERIC;
}
used_buffer_length += length;
i_position = (char *) memchr(data, '\n', used_buffer_length);
if (i_position && i_position < data + used_buffer_length) {
if (!strncmp(data, "/system/bin/sh: su: not found", 29)) {
errmsg_print("ERROR: Command 'su' not found for <%s>", adb_shell_su_hcidump);
closesocket(sock);
return EXIT_CODE_GENERIC;
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
if (errno == EAGAIN
#if EWOULDBLOCK != EAGAIN
|| errno == EWOULDBLOCK
#endif
) {
continue;
}
else if (errno != 0) {
errmsg_print("ERROR capture: %s", strerror(errno));
closesocket(sock);
return EXIT_CODE_GENERIC;
}
if (length <= 0) {
errmsg_print("ERROR: Broken socket connection.");
closesocket(sock);
return EXIT_CODE_GENERIC;
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
errmsg_print("ERROR: data format error: %s", strerror(errno));
closesocket(sock);
return EXIT_CODE_GENERIC;
}
hex_data = new_hex_data;
hex = g_ascii_strtoll(hex_data, &new_hex_data, 16);
if (hex < 0 || hex >= 256 || hex_data == new_hex_data) {
errmsg_print("ERROR: data format error: %s", strerror(errno));
closesocket(sock);
return EXIT_CODE_GENERIC;
}
hex_data = new_hex_data;
hex = g_ascii_strtoll(hex_data, &new_hex_data, 16);
raw_length = hex + 4;
} else if (hex == 0x04) {
hex_data = new_hex_data;
hex = g_ascii_strtoll(hex_data, &new_hex_data, 16);
if (hex < 0 || hex >= 256 || hex_data == new_hex_data) {
errmsg_print("ERROR: data format error: %s", strerror(errno));
closesocket(sock);
return EXIT_CODE_GENERIC;
}
hex_data = new_hex_data;
hex = g_ascii_strtoll(hex_data, &new_hex_data, 16);
raw_length = hex + 3;
} else if (hex == 0x02) {
hex_data = new_hex_data;
hex = g_ascii_strtoll(hex_data, &new_hex_data, 16);
if (hex < 0 || hex >= 256 || hex_data == new_hex_data) {
errmsg_print("ERROR: data format error: %s", strerror(errno));
closesocket(sock);
return EXIT_CODE_GENERIC;
}
hex_data = new_hex_data;
hex = g_ascii_strtoll(hex_data, &new_hex_data, 16);
if (hex < 0 || hex >= 256 || hex_data == new_hex_data) {
errmsg_print("ERROR: data format error: %s", strerror(errno));
closesocket(sock);
return EXIT_CODE_GENERIC;
}
hex_data = new_hex_data;
hex = g_ascii_strtoll(hex_data, &new_hex_data, 16);
raw_length = hex + 5;
hex_data = new_hex_data;
hex = g_ascii_strtoll(hex_data, &new_hex_data, 16);
raw_length += hex << 8;
}
} else {
errmsg_print("ERROR: bad raw stream");
closesocket(sock);
return EXIT_CODE_GENERIC;
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
verbose_print("time %04d-%02d-%02d %02d:%02d:%02d.%06d %c\n",
date.tm_year, date.tm_mon, date.tm_mday, date.tm_hour,
date.tm_min, date.tm_sec, ms, direction_character);
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
endless_loop = extcap_dumper_dump(extcap_dumper, packet,
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
return EXIT_CODE_SUCCESS;
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
return EXIT_CODE_INVALID_SOCKET_5;
result = g_snprintf(helpful_packet, PACKET_LENGTH, adb_forward_template, (serial_number) ? 5 + 7 + strlen(serial_number) + 28 : 4 + 28, (serial_number) ? "host-serial:" : "host", (serial_number) ? serial_number: "", local_tcp_port, server_tcp_port);
if (result <= 0 || result > PACKET_LENGTH) {
errmsg_print("ERROR: Error while completing adb packet");
closesocket(sock);
return EXIT_CODE_BAD_SIZE_OF_ASSEMBLED_ADB_PACKET_12;
}
result = adb_send(sock, helpful_packet);
closesocket(sock);
return result;
}
static int capture_android_bluetooth_external_parser(char *interface,
char *fifo, const char *adb_server_ip, unsigned short *adb_server_tcp_port,
unsigned short *bt_server_tcp_port, unsigned int bt_forward_socket, const char *bt_local_ip,
unsigned short *bt_local_tcp_port) {
struct extcap_dumper extcap_dumper;
static char buffer[PACKET_LENGTH];
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
size_t serial_number_length = 0;
SET_DATA(timestamp, value_u64, buffer);
SET_DATA(h4_header, value_own_pcap_bluetooth_h4_header, packet);
extcap_dumper = extcap_dumper_open(fifo, EXTCAP_ENCAP_BLUETOOTH_H4_WITH_PHDR);
if (is_specified_interface(interface, INTERFACE_ANDROID_BLUETOOTH_EXTERNAL_PARSER) &&
strlen(interface) > strlen(INTERFACE_ANDROID_BLUETOOTH_EXTERNAL_PARSER) + 1) {
serial_number = interface + strlen(INTERFACE_ANDROID_BLUETOOTH_EXTERNAL_PARSER) + 1;
serial_number_length = strlen(serial_number);
}
if (bt_forward_socket) {
if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET) {
errmsg_print("ERROR: Cannot open system TCP socket: %s", strerror(errno));
return EXIT_CODE_GENERIC;
}
verbose_print("Using config: Server TCP Port=%u, Local IP=%s, Local TCP Port=%u\n",
*bt_server_tcp_port, bt_local_ip, *bt_local_tcp_port);
if (*bt_local_tcp_port != 0) {
int result;
result = adb_forward(serial_number, adb_server_ip, adb_server_tcp_port, *bt_local_tcp_port, *bt_server_tcp_port);
verbose_print("DO: adb forward tcp:%u (local) tcp:%u (remote) result=%i\n",
*bt_local_tcp_port, *bt_server_tcp_port, result);
}
memset(&server, 0 , sizeof(server));
server.sin_family = AF_INET;
server.sin_port = GINT16_TO_BE(*bt_local_tcp_port);
server.sin_addr.s_addr = inet_addr(bt_local_ip);
if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == SOCKET_ERROR) {
errmsg_print("ERROR: <%s> Please check that adb daemon is running.", strerror(errno));
closesocket(sock);
return EXIT_CODE_GENERIC;
}
if (verbose) {
struct sockaddr_in client;
length = sizeof(client);
if (getsockname(sock, (struct sockaddr *) &client, (socklen_t *) &length)) {
errmsg_print("ERROR getsockname: %s", strerror(errno));
closesocket(sock);
return EXIT_CODE_GENERIC;
}
if (length != sizeof(client)) {
errmsg_print("ERROR: incorrect length");
closesocket(sock);
return EXIT_CODE_GENERIC;
}
verbose_print("VERBOSE: Client port %u\n", GUINT16_FROM_BE(client.sin_port));
}
} else {
int result;
sock = adb_connect(adb_server_ip, adb_server_tcp_port);
if (sock == INVALID_SOCKET)
return EXIT_CODE_INVALID_SOCKET_6;
if (!serial_number) {
result = adb_send(sock, adb_transport);
if (result) {
errmsg_print("ERROR: Error while setting adb transport");
closesocket(sock);
return EXIT_CODE_GENERIC;
}
} else {
result = g_snprintf((char *) buffer, PACKET_LENGTH, adb_transport_serial_templace, 15 + serial_number_length, serial_number);
if (result <= 0 || result > PACKET_LENGTH) {
errmsg_print("ERROR: Error while completing adb packet");
closesocket(sock);
return EXIT_CODE_BAD_SIZE_OF_ASSEMBLED_ADB_PACKET_13;
}
result = adb_send(sock, buffer);
if (result) {
errmsg_print("ERROR: Error while setting adb transport");
closesocket(sock);
return EXIT_CODE_GENERIC;
}
}
result = g_snprintf((char *) buffer, PACKET_LENGTH, adb_tcp_bluedroid_external_parser_template, 4 + 5, *bt_server_tcp_port);
if (result <= 0 || result > PACKET_LENGTH) {
errmsg_print("ERROR: Error while completing adb packet");
closesocket(sock);
return EXIT_CODE_BAD_SIZE_OF_ASSEMBLED_ADB_PACKET_14;
}
result = adb_send(sock, buffer);
if (result) {
errmsg_print("ERROR: Error while forwarding adb port");
closesocket(sock);
return EXIT_CODE_GENERIC;
}
}
while (endless_loop) {
errno = 0;
length = recv(sock, buffer + used_buffer_length, (int)(PACKET_LENGTH - used_buffer_length), 0);
if (errno == EAGAIN
#if EWOULDBLOCK != EAGAIN
|| errno == EWOULDBLOCK
#endif
) {
continue;
}
else if (errno != 0) {
errmsg_print("ERROR capture: %s", strerror(errno));
closesocket(sock);
return EXIT_CODE_GENERIC;
}
if (length <= 0) {
if (bt_forward_socket) {
/* NOTE: Workaround... It seems that Bluedroid is slower and we can connect to socket that are not really ready... */
verbose_print("WARNING: Broken socket connection. Try reconnect.\n");
closesocket(sock);
if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET) {
errmsg_print("ERROR: %s", strerror(errno));
return EXIT_CODE_GENERIC;
}
server.sin_family = AF_INET;
server.sin_port = GINT16_TO_BE(*bt_local_tcp_port);
server.sin_addr.s_addr = inet_addr(bt_local_ip);
if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == SOCKET_ERROR) {
errmsg_print("ERROR reconnect: <%s> Please check that adb daemon is running.", strerror(errno));
closesocket(sock);
return EXIT_CODE_GENERIC;
}
} else {
errmsg_print("ERROR: Broken socket connection.");
closesocket(sock);
return EXIT_CODE_GENERIC;
}
continue;
}
used_buffer_length += length;
verbose_print("Received: length=%"G_GSSIZE_FORMAT"\n", length);
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
length = sizeof(own_pcap_bluetooth_h4_header) + BLUEDROID_H4_SIZE + 2 + 2 + payload[3] + (gssize)(payload[3 + 1] << 8);
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
errmsg_print("ERROR: Invalid stream");
closesocket(sock);
return EXIT_CODE_GENERIC;
}
if (verbose) {
static unsigned int id = 1;
verbose_print("\t Packet %u: used_buffer_length=%"G_GSSIZE_FORMAT" length=%"G_GSSIZE_FORMAT" captured_length=%i type=0x%02x\n", id, used_buffer_length, length, captured_length, payload[BLUEDROID_H4_PACKET_TYPE]);
if (payload[BLUEDROID_H4_PACKET_TYPE] == BLUEDROID_H4_PACKET_TYPE_HCI_EVT)
verbose_print("\t Packet: %02x %02x %02x\n", (unsigned int) payload[0], (unsigned int) payload[1], (unsigned int)payload[2]);
id +=1;
}
ts -= BLUEDROID_TIMESTAMP_BASE;
endless_loop = extcap_dumper_dump(extcap_dumper, packet,
captured_length,
captured_length,
(uint32_t)(ts / 1000000),
((uint32_t)(ts % 1000000)) * 1000);
used_buffer_length -= length - sizeof(own_pcap_bluetooth_h4_header) + BLUEDROID_TIMESTAMP_SIZE;
if (used_buffer_length < 0) {
errmsg_print("ERROR: Internal error: Negative used buffer length.");
closesocket(sock);
return EXIT_CODE_GENERIC;
}
memmove(buffer, packet + length, used_buffer_length);
}
}
closesocket(sock);
return EXIT_CODE_SUCCESS;
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
size_t serial_number_length;
uint64_t ts;
static const uint64_t BTSNOOP_TIMESTAMP_BASE = G_GUINT64_CONSTANT(0x00dcddb30f2f8000);
uint32_t *reported_length;
uint32_t *captured_length;
uint32_t *flags;
/* uint32_t *cumulative_dropped_packets; */
uint64_t *timestamp;
char *payload = packet + sizeof(own_pcap_bluetooth_h4_header) + 24;
own_pcap_bluetooth_h4_header *h4_header;
SET_DATA(reported_length, value_u32, packet + sizeof(own_pcap_bluetooth_h4_header) + 0);
SET_DATA(captured_length, value_u32, packet + sizeof(own_pcap_bluetooth_h4_header) + 4);
SET_DATA(flags, value_u32, packet + sizeof(own_pcap_bluetooth_h4_header) + 8);
/* SET_DATA(cumulative_dropped_packets, value_u32, packet + sizeof(own_pcap_bluetooth_h4_header) + 12); */
SET_DATA(timestamp, value_u64, packet + sizeof(own_pcap_bluetooth_h4_header) + 16);
SET_DATA(h4_header, value_own_pcap_bluetooth_h4_header, payload - sizeof(own_pcap_bluetooth_h4_header));
extcap_dumper = extcap_dumper_open(fifo, EXTCAP_ENCAP_BLUETOOTH_H4_WITH_PHDR);
sock = adb_connect(adb_server_ip, adb_server_tcp_port);
if (sock == INVALID_SOCKET)
return EXIT_CODE_INVALID_SOCKET_7;
if (is_specified_interface(interface, INTERFACE_ANDROID_BLUETOOTH_BTSNOOP_NET) &&
strlen(interface) > strlen(INTERFACE_ANDROID_BLUETOOTH_BTSNOOP_NET) + 1) {
serial_number = interface + strlen(INTERFACE_ANDROID_BLUETOOTH_BTSNOOP_NET) + 1;
serial_number_length = strlen(serial_number);
}
if (!serial_number) {
result = adb_send(sock, adb_transport);
if (result) {
errmsg_print("ERROR: Error while setting adb transport for <%s>", adb_transport);
closesocket(sock);
return EXIT_CODE_GENERIC;
}
} else {
result = g_snprintf((char *) packet, PACKET_LENGTH, adb_transport_serial_templace, 15 + serial_number_length, serial_number);
if (result <= 0 || result > PACKET_LENGTH) {
errmsg_print("ERROR: Error while completing adb packet");
closesocket(sock);
return EXIT_CODE_BAD_SIZE_OF_ASSEMBLED_ADB_PACKET_15;
}
result = adb_send(sock, packet);
if (result) {
errmsg_print("ERROR: Error while setting adb transport for <%s>", packet);
closesocket(sock);
return EXIT_CODE_GENERIC;
}
}
result = adb_send(sock, adb_tcp_btsnoop_net);
if (result) {
errmsg_print("ERROR: Error while sending command <%s>", adb_tcp_btsnoop_net);
closesocket(sock);
return EXIT_CODE_ERROR_WHILE_SENDING_ADB_PACKET_2;
}
/* Read "btsnoop" header - 16 bytes */
while (used_buffer_length < 16) {
length = recv(sock, packet + used_buffer_length, (int)(PACKET_LENGTH - used_buffer_length), 0);
if (length <= 0) {
errmsg_print("ERROR: Broken socket connection.");
closesocket(sock);
return EXIT_CODE_GENERIC;
}
used_buffer_length += length;
}
if (used_buffer_length > 16)
memmove(packet, packet + 16, used_buffer_length - 16);
used_buffer_length = 0;
while (endless_loop) {
errno = 0;
length = recv(sock, packet + used_buffer_length + sizeof(own_pcap_bluetooth_h4_header),
(int)(PACKET_LENGTH - sizeof(own_pcap_bluetooth_h4_header) - used_buffer_length), 0);
if (errno == EAGAIN
#if EWOULDBLOCK != EAGAIN
|| errno == EWOULDBLOCK
#endif
) {
continue;
}
else if (errno != 0) {
errmsg_print("ERROR capture: %s", strerror(errno));
closesocket(sock);
return EXIT_CODE_GENERIC;
}
if (length <= 0) {
errmsg_print("ERROR: Broken socket connection.");
closesocket(sock);
return EXIT_CODE_GENERIC;
}
used_buffer_length += length;
while (used_buffer_length >= 24 &&
used_buffer_length >= (int) (24 + GINT32_FROM_BE(*captured_length))) {
gint32 direction;
ts = GINT64_FROM_BE(*timestamp);
ts -= BTSNOOP_TIMESTAMP_BASE;
direction = GINT32_FROM_BE(*flags) & 0x01;
h4_header->direction = GINT32_TO_BE(direction);
endless_loop = extcap_dumper_dump(extcap_dumper, payload - sizeof(own_pcap_bluetooth_h4_header),
GINT32_FROM_BE(*captured_length) + sizeof(own_pcap_bluetooth_h4_header),
GINT32_FROM_BE(*reported_length) + sizeof(own_pcap_bluetooth_h4_header),
(uint32_t)(ts / 1000000),
((uint32_t)(ts % 1000000)) * 1000);
used_buffer_length -= 24 + GINT32_FROM_BE(*captured_length);
if (used_buffer_length < 0) {
errmsg_print("ERROR: Internal error: Negative used buffer length.");
closesocket(sock);
return EXIT_CODE_GENERIC;
}
if (used_buffer_length > 0)
memmove(packet + sizeof(own_pcap_bluetooth_h4_header), payload + GINT32_FROM_BE(*captured_length), used_buffer_length);
}
}
closesocket(sock);
return EXIT_CODE_SUCCESS;
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
size_t serial_number_length = 0;
int result;
char *pos;
const char *logcat_buffer;
extcap_dumper = extcap_dumper_open(fifo, EXTCAP_ENCAP_WIRESHARK_UPPER_PDU);
exported_pdu_header_protocol_normal.tag = GUINT16_TO_BE(WIRESHARK_UPPER_PDU_TAG_DISSECTOR_NAME);
exported_pdu_header_protocol_normal.length = GUINT16_TO_BE(strlen(wireshark_protocol_logcat_text) + 2);
sock = adb_connect(adb_server_ip, adb_server_tcp_port);
if (sock == INVALID_SOCKET)
return EXIT_CODE_INVALID_SOCKET_8;
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
errmsg_print("ERROR: Error while setting adb transport for <%s>", adb_transport);
closesocket(sock);
return EXIT_CODE_GENERIC;
}
} else {
serial_number_length = strlen(serial_number);
result = g_snprintf((char *) packet, PACKET_LENGTH, adb_transport_serial_templace, 15 + serial_number_length, serial_number);
if (result <= 0 || result > PACKET_LENGTH) {
errmsg_print("ERROR: Error while completing adb packet");
closesocket(sock);
return EXIT_CODE_BAD_SIZE_OF_ASSEMBLED_ADB_PACKET_16;
}
result = adb_send(sock, packet);
if (result) {
errmsg_print("ERROR: Error while setting adb transport for <%s>", packet);
closesocket(sock);
return EXIT_CODE_GENERIC;
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
errmsg_print("ERROR: Unknown interface: <%s>", interface);
closesocket(sock);
return EXIT_CODE_GENERIC;
}
result = g_snprintf((char *) packet, PACKET_LENGTH, adb_logcat_template, strlen(adb_logcat_template) + -8 + strlen(logcat_buffer), logcat_buffer, "");
if (result <= 0 || result > PACKET_LENGTH) {
errmsg_print("ERROR: Error while completing adb packet");
closesocket(sock);
return EXIT_CODE_BAD_SIZE_OF_ASSEMBLED_ADB_PACKET_17;
}
result = adb_send(sock, packet);
if (result) {
errmsg_print("ERROR: Error while sending command <%s>", packet);
closesocket(sock);
return EXIT_CODE_ERROR_WHILE_SENDING_ADB_PACKET_3;
}
protocol_name = wireshark_protocol_logcat_text;
exported_pdu_header_protocol = &exported_pdu_header_protocol_normal;
memcpy(packet, exported_pdu_header_protocol, sizeof(struct exported_pdu_header));
exported_pdu_headers_size += sizeof(struct exported_pdu_header);
memcpy(packet + exported_pdu_headers_size, protocol_name, GUINT16_FROM_BE(exported_pdu_header_protocol->length) - 2);
exported_pdu_headers_size += GUINT16_FROM_BE(exported_pdu_header_protocol->length);
packet[exported_pdu_headers_size - 1] = 0;
packet[exported_pdu_headers_size - 2] = 0;
memcpy(packet + exported_pdu_headers_size, &exported_pdu_header_end, sizeof(struct exported_pdu_header));
exported_pdu_headers_size += sizeof(struct exported_pdu_header) + GUINT16_FROM_BE(exported_pdu_header_end.length);
used_buffer_length = 0;
while (endless_loop) {
errno = 0;
length = recv(sock, packet + exported_pdu_headers_size + used_buffer_length, (int)(PACKET_LENGTH - exported_pdu_headers_size - used_buffer_length), 0);
if (errno == EAGAIN
#if EWOULDBLOCK != EAGAIN
|| errno == EWOULDBLOCK
#endif
) {
continue;
}
else if (errno != 0) {
errmsg_print("ERROR capture: %s", strerror(errno));
closesocket(sock);
return EXIT_CODE_GENERIC;
}
if (length <= 0) {
errmsg_print("ERROR: Broken socket connection. Try reconnect.");
closesocket(sock);
return EXIT_CODE_GENERIC;
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
endless_loop = extcap_dumper_dump(extcap_dumper, packet,
length,
length,
secs, nsecs);
memmove(packet + exported_pdu_headers_size, packet + length, used_buffer_length + exported_pdu_headers_size - length);
used_buffer_length -= length - exported_pdu_headers_size;
}
}
closesocket(sock);
return EXIT_CODE_SUCCESS;
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
size_t serial_number_length = 0;
extcap_dumper = extcap_dumper_open(fifo, EXTCAP_ENCAP_WIRESHARK_UPPER_PDU);
exported_pdu_header_protocol_events.tag = GUINT16_TO_BE(WIRESHARK_UPPER_PDU_TAG_DISSECTOR_NAME);
exported_pdu_header_protocol_events.length = GUINT16_TO_BE(strlen(wireshark_protocol_logcat_events) + 2);
exported_pdu_header_protocol_normal.tag = GUINT16_TO_BE(WIRESHARK_UPPER_PDU_TAG_DISSECTOR_NAME);
exported_pdu_header_protocol_normal.length = GUINT16_TO_BE(strlen(wireshark_protocol_logcat) + 2);
sock = adb_connect(adb_server_ip, adb_server_tcp_port);
if (sock == INVALID_SOCKET)
return EXIT_CODE_INVALID_SOCKET_9;
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
errmsg_print("ERROR: Error while setting adb transport");
closesocket(sock);
return EXIT_CODE_GENERIC;
}
} else {
serial_number_length = strlen(serial_number);
result = g_snprintf(packet, PACKET_LENGTH, adb_transport_serial_templace, 15 + serial_number_length, serial_number);
if (result <= 0 || result > PACKET_LENGTH) {
errmsg_print("ERROR: Error while completing adb packet");
closesocket(sock);
return EXIT_CODE_BAD_SIZE_OF_ASSEMBLED_ADB_PACKET_18;
}
result = adb_send(sock, packet);
if (result) {
errmsg_print("ERROR: Error while setting adb transport");
closesocket(sock);
return EXIT_CODE_GENERIC;
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
errmsg_print("ERROR: Unknown interface: <%s>", interface);
closesocket(sock);
return EXIT_CODE_GENERIC;
}
result = adb_send(sock, adb_command);
if (result) {
errmsg_print("ERROR: Error while sending command <%s>", adb_command);
closesocket(sock);
return EXIT_CODE_ERROR_WHILE_SENDING_ADB_PACKET_4;
}
if (is_specified_interface(interface, INTERFACE_ANDROID_LOGCAT_EVENTS))
{
protocol_name = wireshark_protocol_logcat_events;
exported_pdu_header_protocol = &exported_pdu_header_protocol_events;
} else {
protocol_name = wireshark_protocol_logcat;
exported_pdu_header_protocol = &exported_pdu_header_protocol_normal;
}
memcpy(packet, exported_pdu_header_protocol, sizeof(struct exported_pdu_header));
exported_pdu_headers_size += sizeof(struct exported_pdu_header);
memcpy(packet + exported_pdu_headers_size, protocol_name, GUINT16_FROM_BE(exported_pdu_header_protocol->length) - 2);
exported_pdu_headers_size += GUINT16_FROM_BE(exported_pdu_header_protocol->length);
packet[exported_pdu_headers_size - 1] = 0;
packet[exported_pdu_headers_size - 2] = 0;
memcpy(packet + exported_pdu_headers_size, &exported_pdu_header_end, sizeof(struct exported_pdu_header));
exported_pdu_headers_size += sizeof(struct exported_pdu_header) + GUINT16_FROM_BE(exported_pdu_header_end.length);
SET_DATA(payload_length, value_u16, packet + exported_pdu_headers_size + 0);
SET_DATA(try_header_size, value_u16, packet + exported_pdu_headers_size + 2);
SET_DATA(timestamp_secs, value_u32, packet + exported_pdu_headers_size + 12);
SET_DATA(timestamp_nsecs, value_u32, packet + exported_pdu_headers_size + 16);
while (endless_loop) {
errno = 0;
length = recv(sock, packet + exported_pdu_headers_size + used_buffer_length, (int)(PACKET_LENGTH - exported_pdu_headers_size - used_buffer_length), 0);
if (errno == EAGAIN
#if EWOULDBLOCK != EAGAIN
|| errno == EWOULDBLOCK
#endif
) {
continue;
}
else if (errno != 0) {
errmsg_print("ERROR capture: %s", strerror(errno));
closesocket(sock);
return EXIT_CODE_GENERIC;
}
if (length <= 0) {
while (endless_loop) {
verbose_print("WARNING: Broken socket connection. Try reconnect.\n");
used_buffer_length = 0;
closesocket(sock);
sock = adb_connect(adb_server_ip, adb_server_tcp_port);
if (sock == INVALID_SOCKET)
return EXIT_CODE_INVALID_SOCKET_10;
if (!serial_number) {
result = adb_send(sock, adb_transport);
if (result) {
errmsg_print("ERROR: Error while setting adb transport for <%s>", adb_transport);
closesocket(sock);
return EXIT_CODE_GENERIC;
}
} else {
result = g_snprintf((char *) helper_packet, PACKET_LENGTH, adb_transport_serial_templace, 15 + serial_number_length, serial_number);
if (result <= 0 || result > PACKET_LENGTH) {
errmsg_print("ERROR: Error while completing adb packet");
closesocket(sock);
return EXIT_CODE_BAD_SIZE_OF_ASSEMBLED_ADB_PACKET_19;
}
result = adb_send(sock, helper_packet);
if (result) {
errmsg_print("ERROR: Error while setting adb transport for <%s>", helper_packet);
closesocket(sock);
return EXIT_CODE_GENERIC;
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
errmsg_print("ERROR: Unknown interface: <%s>", interface);
closesocket(sock);
return EXIT_CODE_GENERIC;
}
result = adb_send(sock, adb_command);
if (result) {
errmsg_print("WARNIG: Error while sending command <%s>", adb_command);
continue;
}
break;
}
}
used_buffer_length += length + exported_pdu_headers_size;
if (*try_header_size != 24)
header_size = 20;
else
header_size = *try_header_size;
length = (*payload_length) + header_size + (gssize)exported_pdu_headers_size;
while (used_buffer_length >= exported_pdu_headers_size + header_size && (size_t)length <= used_buffer_length) {
endless_loop = extcap_dumper_dump(extcap_dumper, packet,
length,
length,
*timestamp_secs, *timestamp_nsecs);
memmove(packet + exported_pdu_headers_size, packet + length, used_buffer_length - length);
used_buffer_length -= length;
used_buffer_length += exported_pdu_headers_size;
length = (*payload_length) + header_size + (gssize)exported_pdu_headers_size;
if (*try_header_size != 24)
header_size = 20;
else
header_size = *try_header_size;
}
used_buffer_length -= exported_pdu_headers_size;
}
closesocket(sock);
return EXIT_CODE_SUCCESS;
}
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
static char filter_buffer[PACKET_LENGTH];
gint device_endiness = G_LITTLE_ENDIAN;
gboolean global_header_skipped=FALSE;
pcaprec_hdr_t p_header;
/* First check for the device if it is connected or not */
sock = adb_connect(adb_server_ip, adb_server_tcp_port);
if (sock == INVALID_SOCKET)
return EXIT_CODE_INVALID_SOCKET_11;
if (is_specified_interface(interface, INTERFACE_ANDROID_WIFI_TCPDUMP)
&& strlen(interface) > strlen(INTERFACE_ANDROID_WIFI_TCPDUMP) + 1) {
serial_number = interface + strlen(INTERFACE_ANDROID_WIFI_TCPDUMP) + 1;
}
if (!serial_number) {
result = adb_send(sock, adb_transport);
if (result) {
errmsg_print("ERROR: Error while setting adb transport");
fflush(stdout);
errmsg_print("ERROR: Error while setting adb transport for <%s>",
adb_transport);
closesocket(sock);
return EXIT_CODE_GENERIC;
}
} else {
result = g_snprintf((char *) helpful_packet, PACKET_LENGTH, adb_transport_serial_templace,
15 + strlen(serial_number), serial_number);
if (result <= 0 || result > PACKET_LENGTH) {
errmsg_print("ERROR: Error while completing adb packet");
closesocket(sock);
return EXIT_CODE_BAD_SIZE_OF_ASSEMBLED_ADB_PACKET_20;
}
result = adb_send(sock, helpful_packet);
if (result) {
errmsg_print("ERROR: Error while setting adb transport");
closesocket(sock);
return EXIT_CODE_GENERIC;
}
}
result = adb_send(sock, adb_shell_tcpdump);
if (result) {
errmsg_print("ERROR: Error while setting adb transport");
closesocket(sock);
return EXIT_CODE_GENERIC;
}
extcap_dumper = extcap_dumper_open(fifo, EXTCAP_ENCAP_ETHERNET);
while (endless_loop) {
char *i_position;
errno = 0;
length = recv(sock, data + used_buffer_length, (int)(PACKET_LENGTH - used_buffer_length), 0);
if (errno == EAGAIN
#if EWOULDBLOCK != EAGAIN
|| errno == EWOULDBLOCK
#endif
) {
continue;
}
else if (errno != 0) {
errmsg_print("ERROR capture: %s", strerror(errno));
return EXIT_CODE_GENERIC;
}
if (length <= 0) {
errmsg_print("ERROR: Broken socket connection.");
closesocket(sock);
return EXIT_CODE_GENERIC;
}
used_buffer_length += length;
/*
* Checking for the starting for the pcap global header using the magic number
*/
if (used_buffer_length > 4) {
guint * magic_number;
magic_number= (guint *)data;
if (*magic_number == 0xd4c3b2a1 || *magic_number == 0xa1b2c3d4) {
if (data[0] == (char)0xd4){
device_endiness = G_LITTLE_ENDIAN;
}
else {
device_endiness = G_BIG_ENDIAN;
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
