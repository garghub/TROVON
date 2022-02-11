static inline int F_1 ( char * V_1 , const char * V_2 ) {
return ! strncmp ( V_1 , V_2 , strlen ( V_2 ) ) ;
}
static void
F_2 ( const char * V_3 , T_1 V_4 )
{
F_3 ( V_5 , V_6 , V_3 , V_4 ) ;
}
static void F_4 ( T_2 V_7 ) {
int V_8 ;
#ifdef F_5
const T_3 V_9 = V_10 ;
V_8 = F_6 ( V_7 , V_11 , V_12 , ( const char * ) & V_9 , ( V_13 ) sizeof( V_9 ) ) ;
#else
const struct V_14 V_9 = {
. V_15 = V_10 / 1000 ,
. V_16 = ( V_10 % 1000 ) * 1000
} ;
V_8 = F_6 ( V_7 , V_11 , V_12 , & V_9 , ( V_13 ) sizeof( V_9 ) ) ;
#endif
if ( V_8 != 0 )
F_7 ( L_1 ) ;
}
static void F_8 ( T_2 V_7 ) {
int V_17 ;
int V_18 ;
#ifdef F_5
const T_3 V_9 = V_10 ;
unsigned long V_19 = 1 ;
V_17 = F_6 ( V_7 , V_11 , V_12 , ( const char * ) & V_9 , sizeof( V_9 ) ) ;
V_18 = F_6 ( V_7 , V_11 , V_20 , ( const char * ) & V_9 , sizeof( V_9 ) ) ;
F_9 ( V_7 , V_21 , & V_19 ) ;
#else
const struct V_14 V_9 = {
. V_15 = V_10 / 1000 ,
. V_16 = ( V_10 % 1000 ) * 1000
} ;
V_17 = F_6 ( V_7 , V_11 , V_12 , & V_9 , sizeof( V_9 ) ) ;
V_18 = F_6 ( V_7 , V_11 , V_20 , & V_9 , sizeof( V_9 ) ) ;
#endif
if ( V_17 != 0 )
F_7 ( L_1 ) ;
if ( V_18 != 0 )
F_7 ( L_1 ) ;
}
static void F_10 ( T_2 V_7 ) {
int V_18 ;
#ifdef F_5
const T_3 V_9 = 0 ;
unsigned long V_19 = 0 ;
V_18 = F_6 ( V_7 , V_11 , V_20 , ( const char * ) & V_9 , sizeof( V_9 ) ) ;
F_9 ( V_7 , V_21 , & V_19 ) ;
#else
const struct V_14 V_9 = {
. V_15 = V_10 / 1000 ,
. V_16 = ( V_10 % 1000 ) * 1000
} ;
V_18 = F_6 ( V_7 , V_11 , V_20 , & V_9 , sizeof( V_9 ) ) ;
#endif
if ( V_18 != 0 )
F_7 ( L_1 ) ;
}
static struct V_22 F_11 ( char * V_23 , int V_24 ) {
struct V_22 V_22 ;
int V_25 ;
#ifdef F_12
T_4 * V_26 ;
if ( V_24 == V_27 )
V_25 = V_28 ;
else if ( V_24 == V_29 )
V_25 = V_30 ;
else if ( V_24 == V_31 )
V_25 = V_32 ;
else {
F_13 ( L_2 ) ;
exit ( V_33 ) ;
}
V_26 = F_14 ( V_25 , V_34 , V_35 ) ;
V_22 . V_36 . V_26 = F_15 ( V_26 , V_23 ) ;
if ( ! V_22 . V_36 . V_26 ) {
F_13 ( L_3 , F_16 ( V_26 ) ) ;
F_17 ( V_26 ) ;
exit ( V_37 ) ;
}
V_22 . V_24 = V_24 ;
if ( F_18 ( V_22 . V_36 . V_26 ) == - 1 ) {
F_13 ( L_4 , F_19 ( V_38 ) ) ;
}
#else
int V_39 = 0 ;
F_20 () ;
#ifdef F_21
F_22 () ;
#endif
if ( V_24 == V_27 )
V_25 = V_40 ;
else if ( V_24 == V_29 )
V_25 = V_41 ;
else if ( V_24 == V_31 )
V_25 = V_42 ;
else {
F_13 ( L_5 ) ;
exit ( V_43 ) ;
}
V_22 . V_36 . V_44 = F_23 ( V_23 , V_45 , V_25 , V_34 , FALSE , & V_39 ) ;
if ( ! V_22 . V_36 . V_44 ) {
F_24 ( L_6 , V_23 , V_39 , V_45 ) ;
exit ( V_46 ) ;
}
V_22 . V_24 = V_24 ;
F_25 ( V_22 . V_36 . V_44 ) ;
#endif
return V_22 ;
}
static T_5 F_26 ( struct V_22 V_22 ,
char * V_23 , char * V_47 ,
T_6 V_48 , T_6 V_49 ,
T_7 V_50 , int V_51 ) {
#ifdef F_12
struct V_52 V_53 ;
V_53 . V_54 = ( V_55 ) V_48 ;
V_53 . V_56 = ( V_55 ) V_49 ;
V_53 . V_57 . V_15 = V_50 ;
V_53 . V_57 . V_16 = V_51 / 1000 ;
F_27 ( ( V_58 * ) V_22 . V_36 . V_26 , & V_53 , V_47 ) ;
if ( F_18 ( V_22 . V_36 . V_26 ) == - 1 ) {
F_13 ( L_4 , F_19 ( V_38 ) ) ;
}
#else
int V_39 = 0 ;
char * V_59 ;
struct V_60 V_61 ;
V_61 . V_62 = V_63 ;
V_61 . V_54 = ( V_64 ) V_48 ;
V_61 . V_56 = ( V_64 ) V_49 ;
V_61 . V_57 . V_65 = V_50 ;
V_61 . V_57 . V_66 = ( int ) V_51 ;
V_61 . V_67 = 0 ;
V_61 . V_67 = NULL ;
V_61 . V_68 = 0 ;
V_61 . V_69 = 0 ;
V_61 . V_70 = V_71 ;
if ( V_22 . V_24 == V_27 ) {
T_8 * V_72 ;
F_28 (direction, value_u32, buffer)
V_61 . V_73 . V_74 . V_75 = F_29 ( * V_72 ) ? 0 : 1 ;
V_61 . V_56 -= ( V_64 ) sizeof( V_76 ) ;
V_61 . V_54 -= ( V_64 ) sizeof( V_76 ) ;
V_47 += sizeof( V_76 ) ;
V_61 . V_77 = V_40 ;
}
else if ( V_22 . V_24 == V_31 ) {
V_61 . V_77 = V_42 ;
}
else {
V_61 . V_77 = V_41 ;
}
if ( ! F_30 ( V_22 . V_36 . V_44 , & V_61 , ( const V_78 * ) V_47 , & V_39 , & V_59 ) ) {
F_31 ( L_6 , NULL , V_23 , V_39 , V_59 ,
0 , V_45 ) ;
return FALSE ;
}
F_25 ( V_22 . V_36 . V_44 ) ;
#endif
return TRUE ;
}
static T_2 F_32 ( const char * V_79 , unsigned short * V_80 ) {
T_2 V_7 ;
V_13 V_81 ;
struct V_82 V_83 ;
struct V_82 V_84 ;
int V_85 ;
int V_86 = 0 ;
memset ( & V_83 , 0x0 , sizeof( V_83 ) ) ;
V_83 . V_87 = V_88 ;
V_83 . V_89 = F_33 ( * V_80 ) ;
V_83 . V_90 . V_91 = F_34 ( V_79 ) ;
if ( ( V_7 = F_35 ( V_88 , V_92 , V_93 ) ) == V_94 ) {
F_13 ( L_7 , strerror ( V_38 ) ) ;
return V_94 ;
}
F_8 ( V_7 ) ;
while ( V_86 < V_95 ) {
V_85 = F_36 ( V_7 , (struct V_96 * ) & V_83 , ( V_13 ) sizeof( V_83 ) ) ;
V_86 += 1 ;
if ( V_85 != V_97 )
break;
F_37 ( V_98 ) ;
}
F_10 ( V_7 ) ;
if ( V_85 == V_97 ) {
#if 0
#ifdef F_5
if (_execlp("adb", "adb", "start-server", NULL)) {
#else
if (execlp("adb", "adb", "start-server", NULL)) {
#endif
errmsg("WARNING: Cannot execute system command to start adb: %s", strerror(errno));
closesocket(sock);
return INVALID_SOCKET;
};
if (connect(sock, (struct sockaddr *) &server, (socklen_t)sizeof(server)) == SOCKET_ERROR) {
g_warning("Cannot connect to ADB: <%s> Please check that adb daemon is running.", strerror(errno));
closesocket(sock);
return INVALID_SOCKET;
}
#else
F_7 ( L_8 , strerror ( V_38 ) ) ;
F_38 ( V_7 ) ;
return V_94 ;
#endif
}
V_81 = sizeof( V_84 ) ;
if ( F_39 ( V_7 , (struct V_96 * ) & V_84 , & V_81 ) ) {
F_13 ( L_9 , strerror ( V_38 ) ) ;
F_38 ( V_7 ) ;
return V_94 ;
}
if ( V_81 != sizeof( V_84 ) ) {
F_13 ( L_10 ) ;
F_38 ( V_7 ) ;
return V_94 ;
}
F_7 ( L_11 , F_40 ( V_84 . V_89 ) ) ;
return V_7 ;
}
static char * F_41 ( T_2 V_7 , const char * V_99 ,
char * V_47 , T_9 V_100 , T_9 * V_101 ) {
T_9 V_102 ;
T_9 V_103 ;
V_64 V_81 ;
T_6 V_104 ;
char V_85 [ 4 ] ;
char V_105 ;
T_9 V_106 ;
V_106 = strlen ( V_99 ) ;
if ( V_106 > V_107 ) {
F_13 ( L_12 , V_99 ) ;
if ( V_101 )
* V_101 = 0 ;
return NULL ;
}
if ( V_100 < 9 ) {
F_13 ( L_13 , V_99 ) ;
if ( V_101 )
* V_101 = 0 ;
return NULL ;
}
V_104 = F_42 ( V_7 , V_99 , ( int ) V_106 , 0 ) ;
if ( V_104 != ( T_6 ) V_106 ) {
F_13 ( L_14 , V_99 ) ;
if ( V_101 )
* V_101 = 0 ;
return NULL ;
}
V_102 = 0 ;
while ( V_102 < 8 ) {
V_103 = V_100 - V_102 ;
if ( V_103 > V_107 )
V_103 = V_107 ;
V_104 = F_43 ( V_7 , V_47 + V_102 , ( int ) V_103 , 0 ) ;
if ( V_104 <= 0 ) {
F_13 ( L_15 , V_99 ) ;
if ( V_101 )
* V_101 = 0 ;
return NULL ;
}
V_102 += V_104 ;
}
memcpy ( V_85 , V_47 , 4 ) ;
V_105 = V_47 [ 8 ] ;
V_47 [ 8 ] = '\0' ;
if ( ! F_44 ( V_47 + 4 , NULL , & V_81 ) ) {
F_13 ( L_16 , V_47 + 4 , V_99 ) ;
if ( V_101 )
* V_101 = 0 ;
return NULL ;
}
V_47 [ 8 ] = V_105 ;
if ( V_100 < V_81 + 8 ) {
F_13 ( L_13 , V_99 ) ;
if ( V_101 )
* V_101 = 0 ;
return NULL ;
}
while ( V_102 < V_81 + 8 ) {
V_103 = V_100 - V_102 ;
if ( V_103 > V_107 )
V_103 = V_107 ;
V_104 = F_43 ( V_7 , V_47 + V_102 , ( int ) V_103 , 0 ) ;
if ( V_104 <= 0 ) {
F_13 ( L_17 , V_99 ) ;
if ( V_101 )
* V_101 = 0 ;
return NULL ;
}
V_102 += V_104 ;
}
if ( V_101 )
* V_101 = V_102 - 8 ;
if ( memcmp ( V_85 , L_18 , 4 ) ) {
F_13 ( L_19 , V_99 ) ;
if ( V_101 )
* V_101 = 0 ;
return NULL ;
}
return V_47 + 8 ;
}
static char * F_45 ( T_2 V_7 , const char * V_99 , char * V_47 ,
int V_100 , T_6 * V_101 ) {
T_6 V_102 ;
T_6 V_104 ;
char V_85 [ 4 ] ;
T_9 V_106 ;
V_106 = strlen ( V_99 ) ;
V_104 = F_42 ( V_7 , V_99 , ( int ) V_106 , 0 ) ;
if ( V_104 != ( T_6 ) V_106 ) {
F_13 ( L_20 , V_99 ) ;
if ( V_101 )
* V_101 = 0 ;
return NULL ;
}
V_102 = 0 ;
while ( V_102 < 4 ) {
V_104 = F_43 ( V_7 , V_47 + V_102 , ( int ) ( V_100 - V_102 ) , 0 ) ;
if ( V_104 <= 0 ) {
F_13 ( L_15 , V_99 ) ;
return NULL ;
}
V_102 += V_104 ;
}
memcpy ( V_85 , V_47 , 4 ) ;
while ( V_104 > 0 ) {
V_104 = F_43 ( V_7 , V_47 + V_102 , ( int ) ( V_100 - V_102 ) , 0 ) ;
if ( V_104 < 0 ) {
F_13 ( L_17 , V_99 ) ;
return NULL ;
} else if ( V_104 == 0 ) {
break;
}
V_102 += V_104 ;
}
if ( V_101 )
* V_101 = V_102 - 4 ;
if ( memcmp ( V_85 , L_18 , 4 ) ) {
F_13 ( L_19 , V_99 ) ;
if ( V_101 )
* V_101 = 0 ;
return NULL ;
}
return V_47 + 4 ;
}
static int F_46 ( T_2 V_7 , const char * V_99 ) {
char V_47 [ 4 ] ;
T_6 V_102 ;
T_6 V_104 ;
T_9 V_106 ;
V_106 = strlen ( V_99 ) ;
V_104 = F_42 ( V_7 , V_99 , ( int ) V_106 , 0 ) ;
if ( V_104 != ( T_6 ) V_106 ) {
F_13 ( L_20 , V_99 ) ;
return V_108 ;
}
V_102 = 0 ;
while ( V_102 < 4 ) {
V_104 = F_43 ( V_7 , V_47 + V_102 , ( int ) ( sizeof( V_47 ) - V_102 ) , 0 ) ;
if ( V_104 <= 0 ) {
F_13 ( L_15 , V_99 ) ;
return V_109 ;
}
V_102 += V_104 ;
}
if ( memcmp ( V_47 , L_18 , 4 ) ) {
F_13 ( L_19 , V_99 ) ;
return V_110 ;
}
return V_111 ;
}
static void F_47 ( T_10 * V_112 , const T_11 * V_113 ,
const T_11 * V_114 , const T_11 * V_115 , const T_11 * V_116 )
{
char * V_1 = F_48 ( L_21 , V_113 , V_115 ) ;
char * V_117 = F_48 ( L_22 , V_116 , V_114 , V_115 ) ;
if ( F_1 ( V_1 , V_118 ) ||
F_1 ( V_1 , V_119 ) ||
F_1 ( V_1 , V_120 ) ) {
F_49 ( V_112 , V_1 , V_117 , 99 , L_23 , L_24 ) ;
} else if ( F_1 ( V_1 , V_121 ) ||
F_1 ( V_1 , V_122 ) ||
F_1 ( V_1 , V_123 ) ||
F_1 ( V_1 , V_124 ) ||
F_1 ( V_1 , V_125 ) ||
F_1 ( V_1 , V_126 ) ||
F_1 ( V_1 , V_127 ) ||
F_1 ( V_1 , V_128 ) ||
F_1 ( V_1 , V_129 ) ) {
F_50 ( V_112 , V_1 , V_117 , 252 , L_25 ) ;
} else if ( F_1 ( V_1 , V_130 ) ) {
F_50 ( V_112 , V_1 , V_117 , 1 , L_26 ) ;
}
F_51 ( V_1 ) ;
F_51 ( V_117 ) ;
}
static int F_52 ( T_10 * V_112 , const char * V_131 , unsigned short * V_132 ) {
static char V_133 [ V_34 ] ;
static char V_134 [ V_34 ] ;
char * V_135 ;
char * V_136 ;
T_6 V_101 ;
T_9 V_137 ;
T_2 V_7 ;
const char * V_138 = L_27 V_139 : V_140 : % V_141 L_28 % 04x L_29 V_142 : V_143 / V_144 / % V_141 / V_145 / V_146 L_30 000E L_29 V_139 : V_147 - V_148 L_31 0022 L_29 V_142 : V_149 V_150 . V_151 . V_152 . V_153 L_32 0017 L_29 V_142 : V_154 -- V_152 L_33 0018 L_29 V_142 : V_155 V_156 . V_157 L_34 001E L_29 V_142 : V_155 V_158 . V_159 . V_157 L_35 0025 L_29 V_142 : V_155 | V_160 V_158 . V_159 . V_157 L_36 0010 L_29 V_142 : V_161 - V_162 L_37 V_163 V_147 L_38 V_163 V_142 L_39 V_164 V_165 V_166 V_167 V_168 V_169 V_147 L_40 V_170 V_171 V_172 long , V_173 V_174");
continue;
}
memcpy(serial_number, prev_pos, result);
serial_number[result] = '\0';
serial_number_length = strlen(serial_number);
model_name[0] = '\0';
model_pos = g_strstr_len(i_pos, pos - i_pos, "V_175 : L_41 V_174 : L_42 V_176 L_43 V_177 V_174 : \ L_44 , V_115 , V_114 );
V_7 = F_32 ( V_131 , V_132 ) ;
if ( V_7 == V_94 ) continue;
V_104 = F_53 ( ( char * ) V_134 , V_34 , V_138 , 15 + V_178 , V_115 ) ;
if ( V_104 <= 0 || V_104 > V_34 ) {
F_13 ( L_45 ) ;
F_38 ( V_7 ) ;
return V_179 ;
}
V_104 = F_46 ( V_7 , V_134 ) ;
if ( V_104 ) {
F_13 ( L_46 , V_134 ) ;
F_38 ( V_7 ) ;
} else {
V_135 = F_45 ( V_7 , V_180 , V_134 , sizeof( V_134 ) , & V_101 ) ;
F_38 ( V_7 ) ;
if ( V_135 ) {
V_135 [ V_101 ] = '\0' ;
if ( strstr ( V_135 , L_47 ) ) {
F_47 ( V_112 , V_130 , V_114 , V_115 , L_48 ) ;
}
} else {
F_13 ( L_49 , V_134 ) ;
}
}
V_7 = F_32 ( V_131 , V_132 ) ;
if ( V_7 == V_94 ) continue;
V_104 = F_53 ( ( char * ) V_134 , V_34 , V_138 , 15 + V_178 , V_115 ) ;
if ( V_104 <= 0 || V_104 > V_34 ) {
F_13 ( L_50 ) ;
F_38 ( V_7 ) ;
return V_181 ;
}
V_104 = F_46 ( V_7 , V_134 ) ;
if ( V_104 ) {
F_13 ( L_46 , V_134 ) ;
F_38 ( V_7 ) ;
continue;
}
V_135 = F_45 ( V_7 , V_182 , V_134 , sizeof( V_134 ) , & V_101 ) ;
F_38 ( V_7 ) ;
if ( ! V_135 ) {
F_13 ( L_49 , V_134 ) ;
continue;
}
V_135 [ V_101 ] = '\0' ;
V_183 = ( int ) F_54 ( V_135 , NULL , 10 ) ;
F_7 ( L_51 , V_115 , V_183 ) ;
if ( V_183 < 21 ) {
F_47 ( V_112 , V_121 , V_114 , V_115 , L_52 ) ;
F_47 ( V_112 , V_122 , V_114 , V_115 , L_53 ) ;
F_47 ( V_112 , V_123 , V_114 , V_115 , L_54 ) ;
F_47 ( V_112 , V_124 , V_114 , V_115 , L_55 ) ;
F_47 ( V_112 , V_125 , V_114 , V_115 , L_52 ) ;
F_47 ( V_112 , V_126 , V_114 , V_115 , L_53 ) ;
F_47 ( V_112 , V_127 , V_114 , V_115 , L_54 ) ;
F_47 ( V_112 , V_128 , V_114 , V_115 , L_55 ) ;
} else {
F_47 ( V_112 , V_125 , V_114 , V_115 , L_52 ) ;
F_47 ( V_112 , V_126 , V_114 , V_115 , L_53 ) ;
F_47 ( V_112 , V_127 , V_114 , V_115 , L_54 ) ;
F_47 ( V_112 , V_128 , V_114 , V_115 , L_55 ) ;
F_47 ( V_112 , V_129 , V_114 , V_115 , L_56 ) ;
}
if ( V_183 >= 5 && V_183 < 17 ) {
V_184 = 0 ;
V_7 = F_32 ( V_131 , V_132 ) ;
if ( V_7 == V_94 ) continue;
V_104 = F_53 ( ( char * ) V_134 , V_34 , V_138 , 15 + V_178 , V_115 ) ;
if ( V_104 <= 0 || V_104 > V_34 ) {
F_13 ( L_50 ) ;
F_38 ( V_7 ) ;
return V_185 ;
}
V_104 = F_46 ( V_7 , V_134 ) ;
if ( V_104 ) {
F_13 ( L_46 , V_134 ) ;
F_38 ( V_7 ) ;
return V_186 ;
}
V_135 = F_45 ( V_7 , V_187 , V_134 , sizeof( V_134 ) , & V_101 ) ;
F_38 ( V_7 ) ;
if ( ! V_135 || V_101 < 1 ) {
F_13 ( L_57 V_188 L_58 ,
V_187 , ( void * ) V_135 , V_101 ) ;
F_7 ( L_59 , V_115 ) ;
V_184 = 1 ;
} else {
V_135 [ V_101 ] = '\0' ;
if ( F_55 ( V_135 , NULL , 10 ) == 0 ) {
F_7 ( L_59 , V_115 ) ;
V_184 = 1 ;
} else {
F_7 ( L_60 , V_115 , V_135 ) ;
}
}
if ( ! V_184 ) {
F_47 ( V_112 , V_118 , V_114 , V_115 , L_61 ) ;
}
}
if ( V_183 >= 17 && V_183 < 21 ) {
V_184 = 0 ;
V_7 = F_32 ( V_131 , V_132 ) ;
if ( V_7 == V_94 ) continue;
V_104 = F_53 ( ( char * ) V_134 , V_34 , V_138 , 15 + V_178 , V_115 ) ;
if ( V_104 <= 0 || V_104 > V_34 ) {
F_13 ( L_50 ) ;
F_38 ( V_7 ) ;
return V_189 ;
}
V_104 = F_46 ( V_7 , V_134 ) ;
if ( V_104 ) {
F_13 ( L_46 , V_134 ) ;
F_38 ( V_7 ) ;
return V_186 ;
}
V_135 = F_45 ( V_7 , V_190 , V_134 , sizeof( V_134 ) , & V_101 ) ;
F_38 ( V_7 ) ;
if ( ! V_135 || V_101 < 1 ) {
F_13 ( L_62
L_63 V_188 L_58 , V_187 , ( void * ) V_135 , V_101 ) ;
F_7 ( L_64 , V_115 ) ;
V_184 = 1 ;
} else {
char * V_191 ;
char V_192 [ 16 ] ;
memset ( V_192 , 0 , sizeof( V_192 ) ) ;
V_135 [ V_101 ] = '\0' ;
V_191 = strchr ( V_135 , '\n' ) ;
if ( V_191 && sscanf ( V_191 , L_65 , V_192 ) == 1 ) {
F_7 ( L_66 , V_115 , V_192 ) ;
V_7 = F_32 ( V_131 , V_132 ) ;
if ( V_7 == V_94 )
return V_193 ;
V_104 = F_53 ( ( char * ) V_134 , V_34 , V_138 , 15 + V_178 , V_115 ) ;
if ( V_104 <= 0 || V_104 > V_34 ) {
F_13 ( L_50 ) ;
F_38 ( V_7 ) ;
return V_194 ;
}
V_104 = F_46 ( V_7 , V_134 ) ;
if ( V_104 ) {
F_13 ( L_46 , V_134 ) ;
F_38 ( V_7 ) ;
return V_186 ;
}
V_104 = F_53 ( ( char * ) V_134 , V_34 , V_195 , strlen ( V_195 ) - 6 + strlen ( V_192 ) , V_192 ) ;
if ( V_104 <= 0 || V_104 > V_34 ) {
F_13 ( L_50 ) ;
F_38 ( V_7 ) ;
return V_196 ;
}
V_135 = F_45 ( V_7 , V_134 , V_134 , sizeof( V_134 ) , & V_101 ) ;
F_38 ( V_7 ) ;
if ( ! V_135 ) {
V_184 = 1 ;
} else {
V_135 [ V_101 ] = '\0' ;
V_191 = strchr ( V_135 , '\n' ) ;
if ( V_191 && sscanf ( V_191 , L_65 , V_192 ) == 1 && strcmp ( V_192 + 9 , L_67 ) == 0 ) {
F_7 ( L_68 , V_115 , V_192 + 9 ) ;
} else {
V_184 = 1 ;
F_7 ( L_69 , V_115 ) ;
}
}
} else {
V_184 = 1 ;
F_7 ( L_64 , V_115 ) ;
}
}
if ( ! V_184 ) {
F_47 ( V_112 , V_119 , V_114 , V_115 , L_70 ) ;
}
}
if ( V_183 >= 21 ) {
V_184 = 0 ;
V_7 = F_32 ( V_131 , V_132 ) ;
if ( V_7 == V_94 ) continue;
V_104 = F_53 ( ( char * ) V_134 , V_34 , V_138 , 15 + V_178 , V_115 ) ;
if ( V_104 <= 0 || V_104 > V_34 ) {
F_13 ( L_50 ) ;
F_38 ( V_7 ) ;
return V_197 ;
}
V_104 = F_46 ( V_7 , V_134 ) ;
if ( V_104 ) {
F_13 ( L_46 , V_134 ) ;
F_38 ( V_7 ) ;
return V_186 ;
}
if ( V_183 >= 24 ) {
V_135 = F_45 ( V_7 , V_198 , V_134 , sizeof( V_134 ) , & V_101 ) ;
} else if ( V_183 >= 23 ) {
V_135 = F_45 ( V_7 , V_199 , V_134 , sizeof( V_134 ) , & V_101 ) ;
} else
V_135 = F_45 ( V_7 , V_190 , V_134 , sizeof( V_134 ) , & V_101 ) ;
F_38 ( V_7 ) ;
if ( ! V_135 || V_101 < 1 ) {
F_13 ( L_62
L_63 V_188 L_58 , V_187 , ( void * ) V_135 , V_101 ) ;
F_7 ( L_64 , V_115 ) ;
V_184 = 1 ;
} else {
char * V_191 ;
char V_192 [ 16 ] ;
memset ( V_192 , 0 , sizeof( V_192 ) ) ;
V_135 [ V_101 ] = '\0' ;
if ( V_183 >= 24 )
V_191 = V_135 ;
else
V_191 = strchr ( V_135 , '\n' ) ;
if ( V_191 && sscanf ( V_191 , L_65 , V_192 ) == 1 ) {
F_7 ( L_66 , V_115 , V_192 ) ;
V_7 = F_32 ( V_131 , V_132 ) ;
if ( V_7 == V_94 )
return V_200 ;
V_104 = F_53 ( ( char * ) V_134 , V_34 , V_138 , 15 + V_178 , V_115 ) ;
if ( V_104 <= 0 || V_104 > V_34 ) {
F_13 ( L_50 ) ;
F_38 ( V_7 ) ;
return V_201 ;
}
V_104 = F_46 ( V_7 , V_134 ) ;
if ( V_104 ) {
F_13 ( L_46 , V_134 ) ;
F_38 ( V_7 ) ;
return V_186 ;
}
V_104 = F_53 ( ( char * ) V_134 , V_34 , V_195 , strlen ( V_195 ) - 6 + strlen ( V_192 ) , V_192 ) ;
if ( V_104 <= 0 || V_104 > V_34 ) {
F_13 ( L_50 ) ;
F_38 ( V_7 ) ;
return V_202 ;
}
V_135 = F_45 ( V_7 , V_134 , V_134 , sizeof( V_134 ) , & V_101 ) ;
F_38 ( V_7 ) ;
if ( ! V_135 ) {
V_184 = 1 ;
} else {
V_135 [ V_101 ] = '\0' ;
V_191 = strchr ( V_135 , '\n' ) ;
if ( V_191 && sscanf ( V_191 , L_65 , V_192 ) == 1 && strcmp ( V_192 + 9 , L_71 ) == 0 ) {
F_7 ( L_72 , V_115 , V_192 + 9 ) ;
} else {
V_184 = 1 ;
F_7 ( L_73 , V_115 ) ;
}
}
} else {
V_184 = 1 ;
F_7 ( L_64 , V_115 ) ;
}
}
if ( ! V_184 ) {
F_47 ( V_112 , V_120 , V_114 , V_115 , L_74 ) ;
}
}
}
int F_56 ( char * V_1 ) {
if ( ! V_1 ) {
F_13 ( L_75 ) ;
return V_203 ;
}
if ( F_1 ( V_1 , V_119 ) ) {
printf ( L_76
L_77
L_78
L_79
L_80
L_81
L_82 ) ;
return V_111 ;
} else if ( F_1 ( V_1 , V_118 ) ||
F_1 ( V_1 , V_120 ) ||
F_1 ( V_1 , V_130 ) ) {
printf ( L_76
L_77
L_83 ) ;
return V_111 ;
} else if ( F_1 ( V_1 , V_121 ) ||
F_1 ( V_1 , V_122 ) ||
F_1 ( V_1 , V_123 ) ||
F_1 ( V_1 , V_124 ) ) {
printf ( L_76
L_77
L_84
L_85
L_86
L_87 ) ;
return V_111 ;
} else if ( F_1 ( V_1 , V_125 ) ||
F_1 ( V_1 , V_126 ) ||
F_1 ( V_1 , V_127 ) ||
F_1 ( V_1 , V_128 ) ||
F_1 ( V_1 , V_129 ) ) {
printf ( L_76
L_77
L_88
L_89
L_90 ) ;
return V_111 ;
}
F_13 ( L_91 , V_1 ) ;
return V_204 ;
}
static int F_57 ( char * V_1 , char * V_23 ,
const char * V_131 , unsigned short * V_132 ) {
struct V_22 V_22 ;
static char V_205 [ V_34 ] ;
static char V_133 [ V_34 ] ;
static char V_134 [ V_34 ] ;
T_6 V_81 ;
T_6 V_102 = 0 ;
T_2 V_7 = V_94 ;
const char * V_206 = L_92 V_139 : V_140 - V_207 L_93 % 04x L_29 V_139 : V_140 : % V_141 L_94 0013 L_29 V_142 : V_154 - V_208 - V_209 L_95 0019 L_29 V_142 : V_210 - V_211 V_154 - V_208 - V_209 L_96 Error while setting adb transport for <%s>", adb_transport);
closesocket(sock);
return EXIT_CODE_GENERIC;
}
} else {
result = g_snprintf((char *) helpful_packet, PACKET_LENGTH, adb_transport_serial_templace, 15 + serial_number_length, serial_number);
if (result <= 0 || result > PACKET_LENGTH) {
g_warning("Error while completing adb packet");
closesocket(sock);
return EXIT_CODE_BAD_SIZE_OF_ASSEMBLED_ADB_PACKET_10;
}
result = adb_send(sock, helpful_packet);
if (result) {
g_warning("Error while setting adb transport for <%s>", helpful_packet);
closesocket(sock);
return EXIT_CODE_GENERIC;
}
}
result = adb_send(sock, adb_shell_hcidump);
if (result) {
g_warning("Error while starting capture by sending command: %s", adb_shell_hcidump);
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
g_warning("ERROR capture: %s", strerror(errno));
closesocket(sock);
return EXIT_CODE_GENERIC;
}
if (length <= 0) {
g_warning("Broken socket connection.");
closesocket(sock);
return EXIT_CODE_GENERIC;
}
used_buffer_length += length;
i_position = (char *) memchr(data, '\n', used_buffer_length);
if (i_position && i_position < data + used_buffer_length) {
char *state_line_position = i_position + 1;
if (!strncmp(data, "/system/bin/sh: hcidump: not found", 34)) {
g_warning("Command not found for <%s>", adb_shell_hcidump);
closesocket(sock);
return EXIT_CODE_GENERIC;
}
i_position = (char *) memchr(i_position + 1, '\n', used_buffer_length);
if (i_position) {
i_position += 1;
if (!strncmp(state_line_position, "Can't access device: Permission denied", 38)) {
g_warning("No permission for command <%s>", adb_shell_hcidump);
used_buffer_length = 0;
closesocket(sock);
sock = INVALID_SOCKET;
break;
}
memmove(data, i_position, used_buffer_length - (i_position - data));
used_buffer_length = used_buffer_length - (gssize)(i_position - data);
break;
}
}
}
if (sock == INVALID_SOCKET) {
sock = adb_connect(adb_server_ip, adb_server_tcp_port);
if (sock == INVALID_SOCKET)
return EXIT_CODE_INVALID_SOCKET_4;
result = g_snprintf((char *) helpful_packet, PACKET_LENGTH, adb_transport_serial_templace, 15 + serial_number_length, serial_number);
if (result <= 0 || result > PACKET_LENGTH) {
g_warning("Error while completing adb packet");
closesocket(sock);
return EXIT_CODE_BAD_SIZE_OF_ASSEMBLED_ADB_PACKET_11;
}
result = adb_send(sock, helpful_packet);
if (result) {
g_warning("Error while setting adb transport for <%s>", helpful_packet);
closesocket(sock);
return EXIT_CODE_GENERIC;
}
result = adb_send(sock, adb_shell_su_hcidump);
if (result) {
g_warning("Error while starting capture by sending command: <%s>", adb_shell_su_hcidump);
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
g_warning("ERROR capture: %s", strerror(errno));
closesocket(sock);
return EXIT_CODE_GENERIC;
}
if (length <= 0) {
g_warning("Broken socket connection.");
closesocket(sock);
return EXIT_CODE_GENERIC;
}
used_buffer_length += length;
i_position = (char *) memchr(data, '\n', used_buffer_length);
if (i_position && i_position < data + used_buffer_length) {
if (!strncmp(data, "/system/bin/sh: su: not found", 29)) {
g_warning("Command 'su' not found for <%s>", adb_shell_su_hcidump);
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
g_warning("ERROR capture: %s", strerror(errno));
closesocket(sock);
return EXIT_CODE_GENERIC;
}
if (length <= 0) {
g_warning("Broken socket connection.");
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
g_warning("data format %s", strerror(errno));
closesocket(sock);
return EXIT_CODE_GENERIC;
}
hex_data = new_hex_data;
hex = g_ascii_strtoll(hex_data, &new_hex_data, 16);
if (hex < 0 || hex >= 256 || hex_data == new_hex_data) {
g_warning("data format %s", strerror(errno));
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
g_warning("data format %s", strerror(errno));
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
g_warning("data format %s", strerror(errno));
closesocket(sock);
return EXIT_CODE_GENERIC;
}
hex_data = new_hex_data;
hex = g_ascii_strtoll(hex_data, &new_hex_data, 16);
if (hex < 0 || hex >= 256 || hex_data == new_hex_data) {
g_warning("data format %s", strerror(errno));
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
g_warning("bad raw stream");
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
g_debug("time %04d-%02d-%02d %02d:%02d:%02d.%06d %c",
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
endless_loop = extcap_dumper_dump(extcap_dumper, fifo, packet,
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
g_warning("Error while completing adb packet");
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
socklen_t slen;
gssize length;
gssize used_buffer_length = 0;
uint64_t ts;
socket_handle_t sock;
struct sockaddr_in server;
int captured_length;
char *serial_number = NULL;
size_t serial_number_length = 0;
static unsigned int id = 1;
struct sockaddr_in client;
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
g_warning("Cannot open system TCP socket: %s", strerror(errno));
return EXIT_CODE_GENERIC;
}
g_debug("Using config: Server TCP Port=%u, Local IP=%s, Local TCP Port=%u",
*bt_server_tcp_port, bt_local_ip, *bt_local_tcp_port);
if (*bt_local_tcp_port != 0) {
int result;
result = adb_forward(serial_number, adb_server_ip, adb_server_tcp_port, *bt_local_tcp_port, *bt_server_tcp_port);
g_debug("DO: adb forward tcp:%u (local) tcp:%u (remote) result=%i",
*bt_local_tcp_port, *bt_server_tcp_port, result);
}
memset(&server, 0 , sizeof(server));
server.sin_family = AF_INET;
server.sin_port = GINT16_TO_BE(*bt_local_tcp_port);
server.sin_addr.s_addr = inet_addr(bt_local_ip);
useSndTimeout(sock);
if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == SOCKET_ERROR) {
g_warning("<%s> Please check that adb daemon is running.", strerror(errno));
closesocket(sock);
return EXIT_CODE_GENERIC;
}
slen = (socklen_t)sizeof(client);
if (getsockname(sock, (struct sockaddr *) &client, &slen)) {
g_warning("getsockname: %s", strerror(errno));
closesocket(sock);
return EXIT_CODE_GENERIC;
}
if (slen != sizeof(client)) {
g_warning("incorrect length");
closesocket(sock);
return EXIT_CODE_GENERIC;
}
g_debug("Client port %u", GUINT16_FROM_BE(client.sin_port));
} else {
int result;
sock = adb_connect(adb_server_ip, adb_server_tcp_port);
if (sock == INVALID_SOCKET)
return EXIT_CODE_INVALID_SOCKET_6;
if (!serial_number) {
result = adb_send(sock, adb_transport);
if (result) {
g_warning("Error while setting adb transport");
closesocket(sock);
return EXIT_CODE_GENERIC;
}
} else {
result = g_snprintf((char *) buffer, PACKET_LENGTH, adb_transport_serial_templace, 15 + serial_number_length, serial_number);
if (result <= 0 || result > PACKET_LENGTH) {
g_warning("Error while completing adb packet");
closesocket(sock);
return EXIT_CODE_BAD_SIZE_OF_ASSEMBLED_ADB_PACKET_13;
}
result = adb_send(sock, buffer);
if (result) {
g_warning("Error while setting adb transport");
closesocket(sock);
return EXIT_CODE_GENERIC;
}
}
result = g_snprintf((char *) buffer, PACKET_LENGTH, adb_tcp_bluedroid_external_parser_template, 4 + 5, *bt_server_tcp_port);
if (result <= 0 || result > PACKET_LENGTH) {
g_warning("Error while completing adb packet");
closesocket(sock);
return EXIT_CODE_BAD_SIZE_OF_ASSEMBLED_ADB_PACKET_14;
}
result = adb_send(sock, buffer);
if (result) {
g_warning("Error while forwarding adb port");
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
g_warning("ERROR capture: %s", strerror(errno));
closesocket(sock);
return EXIT_CODE_GENERIC;
}
if (length <= 0) {
if (bt_forward_socket) {
/* NOTE: Workaround... It seems that Bluedroid is slower and we can connect to socket that are not really ready... */
g_warning("Broken socket connection. Try reconnect.");
closesocket(sock);
if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET) {
g_warning("%s", strerror(errno));
return EXIT_CODE_GENERIC;
}
server.sin_family = AF_INET;
server.sin_port = GINT16_TO_BE(*bt_local_tcp_port);
server.sin_addr.s_addr = inet_addr(bt_local_ip);
useSndTimeout(sock);
if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == SOCKET_ERROR) {
g_warning("ERROR reconnect: <%s> Please check that adb daemon is running.", strerror(errno));
closesocket(sock);
return EXIT_CODE_GENERIC;
}
} else {
g_warning("Broken socket connection.");
closesocket(sock);
return EXIT_CODE_GENERIC;
}
continue;
}
used_buffer_length += length;
g_debug("Received: length=%"G_GSSIZE_FORMAT"", length);
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
g_warning("Invalid stream");
closesocket(sock);
return EXIT_CODE_GENERIC;
}
g_debug("\t Packet %u: used_buffer_length=%"G_GSSIZE_FORMAT" length=%"G_GSSIZE_FORMAT" captured_length=%i type=0x%02x", id, used_buffer_length, length, captured_length, payload[BLUEDROID_H4_PACKET_TYPE]);
if (payload[BLUEDROID_H4_PACKET_TYPE] == BLUEDROID_H4_PACKET_TYPE_HCI_EVT)
g_debug("\t Packet: %02x %02x %02x", (unsigned int) payload[0], (unsigned int) payload[1], (unsigned int)payload[2]);
id +=1;
ts -= BLUEDROID_TIMESTAMP_BASE;
endless_loop = extcap_dumper_dump(extcap_dumper, fifo, packet,
captured_length,
captured_length,
(uint32_t)(ts / 1000000),
((uint32_t)(ts % 1000000)) * 1000);
used_buffer_length -= length - sizeof(own_pcap_bluetooth_h4_header) + BLUEDROID_TIMESTAMP_SIZE;
if (used_buffer_length < 0) {
g_warning("Internal Negative used buffer length.");
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
g_warning("Error while setting adb transport for <%s>", adb_transport);
closesocket(sock);
return EXIT_CODE_GENERIC;
}
} else {
result = g_snprintf((char *) packet, PACKET_LENGTH, adb_transport_serial_templace, 15 + serial_number_length, serial_number);
if (result <= 0 || result > PACKET_LENGTH) {
g_warning("Error while completing adb packet");
closesocket(sock);
return EXIT_CODE_BAD_SIZE_OF_ASSEMBLED_ADB_PACKET_15;
}
result = adb_send(sock, packet);
if (result) {
g_warning("Error while setting adb transport for <%s>", packet);
closesocket(sock);
return EXIT_CODE_GENERIC;
}
}
result = adb_send(sock, adb_tcp_btsnoop_net);
if (result) {
g_warning("Error while sending command <%s>", adb_tcp_btsnoop_net);
closesocket(sock);
return EXIT_CODE_ERROR_WHILE_SENDING_ADB_PACKET_2;
}
/* Read "btsnoop" header - 16 bytes */
while (used_buffer_length < 16) {
length = recv(sock, packet + used_buffer_length, (int)(PACKET_LENGTH - used_buffer_length), 0);
if (length <= 0) {
g_warning("Broken socket connection.");
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
g_warning("ERROR capture: %s", strerror(errno));
closesocket(sock);
return EXIT_CODE_GENERIC;
}
if (length <= 0) {
g_warning("Broken socket connection.");
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
endless_loop = extcap_dumper_dump(extcap_dumper, fifo,
payload - sizeof(own_pcap_bluetooth_h4_header),
GINT32_FROM_BE(*captured_length) + sizeof(own_pcap_bluetooth_h4_header),
GINT32_FROM_BE(*reported_length) + sizeof(own_pcap_bluetooth_h4_header),
(uint32_t)(ts / 1000000),
((uint32_t)(ts % 1000000)) * 1000);
used_buffer_length -= 24 + GINT32_FROM_BE(*captured_length);
if (used_buffer_length < 0) {
g_warning("Internal Negative used buffer length.");
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
const char *adb_server_ip, unsigned short *adb_server_tcp_port,
int logcat_ignore_log_buffer, const char *logcat_custom_parameter) {
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
const char *adb_logcat_template = "%04x""shell:export ANDROID_LOG_TAGS=\"\" ; exec logcat -v threadtime%s%s%s%s";
const char *adb_transport_serial_templace = "%04x""host:transport:%s";
char *serial_number = NULL;
size_t serial_number_length = 0;
int result;
char *pos;
const char *logcat_buffer;
const char *logcat_log_buffer;
size_t command_length;
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
g_warning("Error while setting adb transport for <%s>", adb_transport);
closesocket(sock);
return EXIT_CODE_GENERIC;
}
} else {
serial_number_length = strlen(serial_number);
result = g_snprintf((char *) packet, PACKET_LENGTH, adb_transport_serial_templace, 15 + serial_number_length, serial_number);
if (result <= 0 || result > PACKET_LENGTH) {
g_warning("Error while completing adb packet");
closesocket(sock);
return EXIT_CODE_BAD_SIZE_OF_ASSEMBLED_ADB_PACKET_16;
}
result = adb_send(sock, packet);
if (result) {
g_warning("Error while setting adb transport for <%s>", packet);
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
g_warning("Unknown interface: <%s>", interface);
closesocket(sock);
return EXIT_CODE_GENERIC;
}
command_length = strlen(adb_logcat_template) - 4 - 8 + strlen(logcat_buffer);
if (logcat_ignore_log_buffer)
logcat_log_buffer = " -T 1";
else
logcat_log_buffer = "";
command_length += strlen(logcat_log_buffer);
if (logcat_custom_parameter) {
command_length += 1; /* additional command "space" */
command_length += strlen(logcat_custom_parameter);
}
result = g_snprintf((char *) packet, PACKET_LENGTH, adb_logcat_template, command_length, logcat_buffer, logcat_log_buffer, (logcat_custom_parameter? " " : ""), logcat_custom_parameter);
if (result <= 0 || result > PACKET_LENGTH) {
g_warning("Error while completing adb packet");
closesocket(sock);
return EXIT_CODE_BAD_SIZE_OF_ASSEMBLED_ADB_PACKET_17;
}
result = adb_send(sock, packet);
if (result) {
g_warning("Error while sending command <%s>", packet);
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
g_warning("ERROR capture: %s", strerror(errno));
closesocket(sock);
return EXIT_CODE_GENERIC;
}
if (length <= 0) {
g_warning("Broken socket connection. Try reconnect.");
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
time_t t;
length = (gssize)(pos - packet) + 1;
t = time(NULL);
date = *localtime(&t);
if (6 == sscanf(packet + exported_pdu_headers_size, "%d-%d %d:%d:%d.%d", &date.tm_mon, &date.tm_mday, &date.tm_hour,
&date.tm_min, &date.tm_sec, &ms)) {
date.tm_mon -= 1;
seconds = mktime(&date);
secs = (time_t) seconds;
nsecs = (int) (ms * 1e6);
}
endless_loop = extcap_dumper_dump(extcap_dumper, fifo, packet,
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
g_warning("Error while setting adb transport");
closesocket(sock);
return EXIT_CODE_GENERIC;
}
} else {
serial_number_length = strlen(serial_number);
result = g_snprintf(packet, PACKET_LENGTH, adb_transport_serial_templace, 15 + serial_number_length, serial_number);
if (result <= 0 || result > PACKET_LENGTH) {
g_warning("Error while completing adb packet");
closesocket(sock);
return EXIT_CODE_BAD_SIZE_OF_ASSEMBLED_ADB_PACKET_18;
}
result = adb_send(sock, packet);
if (result) {
g_warning("Error while setting adb transport");
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
g_warning("Unknown interface: <%s>", interface);
closesocket(sock);
return EXIT_CODE_GENERIC;
}
result = adb_send(sock, adb_command);
if (result) {
g_warning("Error while sending command <%s>", adb_command);
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
g_warning("ERROR capture: %s", strerror(errno));
closesocket(sock);
return EXIT_CODE_GENERIC;
}
if (length <= 0) {
while (endless_loop) {
g_warning("Broken socket connection. Try reconnect.");
used_buffer_length = 0;
closesocket(sock);
sock = adb_connect(adb_server_ip, adb_server_tcp_port);
if (sock == INVALID_SOCKET)
return EXIT_CODE_INVALID_SOCKET_10;
if (!serial_number) {
result = adb_send(sock, adb_transport);
if (result) {
g_warning("Error while setting adb transport for <%s>", adb_transport);
closesocket(sock);
return EXIT_CODE_GENERIC;
}
} else {
result = g_snprintf((char *) helper_packet, PACKET_LENGTH, adb_transport_serial_templace, 15 + serial_number_length, serial_number);
if (result <= 0 || result > PACKET_LENGTH) {
g_warning("Error while completing adb packet");
closesocket(sock);
return EXIT_CODE_BAD_SIZE_OF_ASSEMBLED_ADB_PACKET_19;
}
result = adb_send(sock, helper_packet);
if (result) {
g_warning("Error while setting adb transport for <%s>", helper_packet);
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
g_warning("Unknown interface: <%s>", interface);
closesocket(sock);
return EXIT_CODE_GENERIC;
}
result = adb_send(sock, adb_command);
if (result) {
g_warning("WARNIG: Error while sending command <%s>", adb_command);
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
endless_loop = extcap_dumper_dump(extcap_dumper, fifo, packet,
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
g_warning("Error while setting adb transport");
fflush(stdout);
g_warning("Error while setting adb transport for <%s>",
adb_transport);
closesocket(sock);
return EXIT_CODE_GENERIC;
}
} else {
result = g_snprintf((char *) helpful_packet, PACKET_LENGTH, adb_transport_serial_templace,
15 + strlen(serial_number), serial_number);
if (result <= 0 || result > PACKET_LENGTH) {
g_warning("Error while completing adb packet");
closesocket(sock);
return EXIT_CODE_BAD_SIZE_OF_ASSEMBLED_ADB_PACKET_20;
}
result = adb_send(sock, helpful_packet);
if (result) {
g_warning("Error while setting adb transport");
closesocket(sock);
return EXIT_CODE_GENERIC;
}
}
result = adb_send(sock, adb_shell_tcpdump);
if (result) {
g_warning("Error while setting adb transport");
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
g_warning("ERROR capture: %s", strerror(errno));
return EXIT_CODE_GENERIC;
}
if (length <= 0) {
g_warning("Broken socket connection.");
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
* It was observed that some times tcpdump reports the length of packet as '0' and that leads to the
* ( Warn Error "Less data was read than was expected" while reading )
* So to avoid this error we are checking for length of packet before passing it to dumper.
*/
if (p_header.incl_len > 0) {
endless_loop = extcap_dumper_dump(extcap_dumper, fifo, filter_buffer + read_offset+ PCAP_RECORD_HEADER_LENGTH,
p_header.incl_len , p_header.orig_len , p_header.ts_sec , p_header.ts_usec);
}
frame_length = p_header.incl_len + PCAP_RECORD_HEADER_LENGTH;
/*update the offset value for the next packet*/
filter_buffer_length -= frame_length;
read_offset += frame_length;
}
else {
/*The complete packet has not yet received*/
break;
}
}
if (read_offset!=0) {
/*Move the rest of the filter data to the beginning of the filter_buffer */
memmove(filter_buffer, filter_buffer + read_offset , filter_buffer_length);
}
}
/*Get the data from the tcpdump process running in the android device*/
while (endless_loop) {
errno = 0;
length = recv(sock, data + used_buffer_length, (int)(PACKET_LENGTH -(used_buffer_length + filter_buffer_length)), 0);
if (errno == EAGAIN
#if EWOULDBLOCK != EAGAIN
|| errno == EWOULDBLOCK
#endif
) {
continue;
}
else if (errno != 0) {
g_warning("ERROR capture: %s", strerror(errno));
return EXIT_CODE_GENERIC;
}
if (length <= 0) {
g_warning("Broken socket connection.");
closesocket(sock);
return EXIT_CODE_GENERIC;
}
if ((used_buffer_length += length) > 1) {
break;
}
}
}
closesocket(sock);
return EXIT_CODE_SUCCESS;
}
int main(int argc, char **argv) {
int ret = EXIT_CODE_GENERIC;
int option_idx = 0;
int result;
const char *adb_server_ip = NULL;
unsigned short *adb_server_tcp_port = NULL;
unsigned int logcat_text = 0;
unsigned int logcat_ignore_log_buffer = 0;
const char *logcat_custom_parameter = NULL;
const char *default_adb_server_ip = "127.0.0.1";
unsigned short default_adb_server_tcp_port = 5037;
unsigned short local_adb_server_tcp_port;
unsigned short local_bt_server_tcp_port;
unsigned short local_bt_local_tcp_port;
unsigned short *bt_server_tcp_port = NULL;
unsigned int bt_forward_socket = 0;
const char *bt_local_ip = NULL;
unsigned short *bt_local_tcp_port = NULL;
unsigned short default_bt_server_tcp_port = 4330;
const char *default_bt_local_ip = "127.0.0.1";
unsigned short default_bt_local_tcp_port = 4330;
extcap_parameters * extcap_conf = NULL;
char *help_url;
char *help_header = NULL;
#ifdef _WIN32
WSADATA wsaData;
attach_parent_console();
#endif /* _WIN32 */
cmdarg_err_init(failure_warning_message, failure_warning_message);
extcap_conf = g_new0(extcap_parameters, 1);
help_url = data_file_url("androiddump.html");
extcap_base_set_util_info(extcap_conf, argv[0], ANDROIDDUMP_VERSION_MAJOR, ANDROIDDUMP_VERSION_MINOR,
ANDROIDDUMP_VERSION_RELEASE, help_url);
g_free(help_url);
help_header = g_strdup_printf(
" %s --extcap-interfaces [--adb-server-ip=<arg>] [--adb-server-tcp-port=<arg>]\n"
" %s --extcap-interface=INTERFACE --extcap-dlts\n"
" %s --extcap-interface=INTERFACE --extcap-config\n"
" %s --extcap-interface=INTERFACE --fifo=PATH_FILENAME --capture\n"
"\nINTERFACE has the form TYPE-DEVICEID:\n"
"\t""For example: "INTERFACE_ANDROID_BLUETOOTH_BTSNOOP_NET"-W3D7N15C29005648""\n"
"\n"
"\tTYPE is one of:\n"
"\t"INTERFACE_ANDROID_LOGCAT_MAIN"\n"
"\t"INTERFACE_ANDROID_LOGCAT_SYSTEM"\n"
"\t"INTERFACE_ANDROID_LOGCAT_RADIO"\n"
"\t"INTERFACE_ANDROID_LOGCAT_EVENTS"\n"
"\t"INTERFACE_ANDROID_LOGCAT_TEXT_MAIN"\n"
"\t"INTERFACE_ANDROID_LOGCAT_TEXT_SYSTEM"\n"
"\t"INTERFACE_ANDROID_LOGCAT_TEXT_RADIO"\n"
"\t"INTERFACE_ANDROID_LOGCAT_TEXT_EVENTS"\n"
"\t"INTERFACE_ANDROID_LOGCAT_TEXT_CRASH"\n"
"\t"INTERFACE_ANDROID_BLUETOOTH_HCIDUMP"\n"
"\t"INTERFACE_ANDROID_BLUETOOTH_EXTERNAL_PARSER"\n"
"\t"INTERFACE_ANDROID_BLUETOOTH_BTSNOOP_NET"\n"
"\t"INTERFACE_ANDROID_WIFI_TCPDUMP"\n"
"\n"
"\t""DEVICEID is the identifier of the device provided by Android SDK (see \"adb devices\")\n"
"\t""For example: W3D7N15C29005648""\n",
argv[0], argv[0], argv[0], argv[0]);
extcap_help_add_header(extcap_conf, help_header);
g_free(help_header);
extcap_help_add_option(extcap_conf, "--help", "print this help");
extcap_help_add_option(extcap_conf, "--adb-server-ip <IP>", "the IP address of the ADB server");
extcap_help_add_option(extcap_conf, "--adb-server-tcp-port <port>", "the TCP port of the ADB server");
extcap_help_add_option(extcap_conf, "--logcat-text", "use logcat text format");
extcap_help_add_option(extcap_conf, "--logcat-ignore-log-buffer", "ignore log buffer");
extcap_help_add_option(extcap_conf, "--logcat-custom-options <text>", "use custom logcat parameters");
extcap_help_add_option(extcap_conf, "--bt-server-tcp-port <port>", "bluetooth server TCP port");
extcap_help_add_option(extcap_conf, "--bt-forward-socket <path>", "bluetooth forward socket");
extcap_help_add_option(extcap_conf, "--bt-local-ip <IP>", "the bluetooth local IP");
extcap_help_add_option(extcap_conf, "--bt-local-tcp-port <port>", "the bluetooth local TCP port");
opterr = 0;
optind = 0;
if (argc == 1) {
extcap_help_print(extcap_conf);
ret = EXIT_CODE_SUCCESS;
goto end;
}
while ((result = getopt_long(argc, argv, "", longopts, &option_idx)) != -1) {
switch (result) {
case OPT_VERSION:
printf("%s\n", extcap_conf->version);
ret = EXIT_CODE_SUCCESS;
goto end;
case OPT_HELP:
extcap_help_print(extcap_conf);
ret = EXIT_CODE_SUCCESS;
goto end;
case OPT_CONFIG_ADB_SERVER_IP:
adb_server_ip = optarg;
break;
case OPT_CONFIG_ADB_SERVER_TCP_PORT:
adb_server_tcp_port = &local_adb_server_tcp_port;
if (!optarg){
g_warning("Impossible exception. Parameter required argument, but there is no it right now.");
goto end;
}
if (!ws_strtou16(optarg, NULL, adb_server_tcp_port)) {
g_warning("Invalid adb server TCP port: %s", optarg);
goto end;
}
break;
case OPT_CONFIG_LOGCAT_TEXT:
if (optarg && !*optarg)
logcat_text = TRUE;
else
logcat_text = (g_ascii_strncasecmp(optarg, "TRUE", 4) == 0);
break;
case OPT_CONFIG_LOGCAT_IGNORE_LOG_BUFFER:
if (optarg == NULL || (optarg && !*optarg))
logcat_ignore_log_buffer = TRUE;
else
logcat_ignore_log_buffer = (g_ascii_strncasecmp(optarg, "TRUE", 4) == 0);
break;
case OPT_CONFIG_LOGCAT_CUSTOM_OPTIONS:
if (optarg == NULL || (optarg && *optarg == '\0'
