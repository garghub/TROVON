static T_1 * F_1 ( const char * V_1 , T_2 V_2 , const T_3 * type , T_4 * V_3 , T_5 V_4 , T_6 * V_5 ) {
T_5 V_6 = 0 ;
T_1 * V_7 = & V_8 ;
if ( ! V_8 . V_9 ) {
char * V_10 = getenv ( L_1 ) ;
T_6 V_11 ;
V_12 = V_10 ? strtoul ( V_10 , NULL , 10 ) : 0 ;
V_8 . V_9 = F_2 ( V_13 , L_2 ) ;
V_11 = 0 ; F_3 ( L_3 , 1 , & V_11 ) ;
V_11 = 1 ; F_3 ( L_4 , 1 , & V_11 ) ;
V_11 = 2 ; F_3 ( L_5 , 1 , & V_11 ) ;
}
V_4 -- ;
do {
T_1 * V_14 = F_4 ( V_7 -> V_9 , V_5 [ V_6 ] ) ;
if( V_14 ) {
if ( V_6 == V_4 ) {
if ( V_14 -> V_1 ) {
if ( ! F_5 ( V_14 -> V_1 , V_1 ) ) {
F_6 ( 2 , ( L_6 , V_14 -> V_1 , V_1 ) ) ;
}
}
V_14 -> V_1 = F_7 ( V_1 ) ;
if ( ! V_14 -> V_15 ) {
V_14 -> V_15 = type ;
}
return V_14 ;
}
} else {
V_14 = F_8 ( sizeof( T_1 ) ) ;
V_14 -> V_11 = V_5 [ V_6 ] ;
V_14 -> V_2 = V_2 ;
V_14 -> V_9 = F_2 ( V_13 , L_7 ) ;
V_14 -> V_16 = - 2 ;
V_14 -> V_3 = V_3 ;
V_14 -> V_17 = V_7 ;
V_14 -> V_18 = NULL ;
F_9 ( V_7 -> V_9 , V_14 -> V_11 , V_14 ) ;
if ( V_6 == V_4 ) {
V_14 -> V_1 = F_7 ( V_1 ) ;
V_14 -> V_15 = type ;
V_14 -> V_2 = V_2 ;
return V_14 ;
} else {
V_14 -> V_1 = NULL ;
V_14 -> V_15 = NULL ;
V_14 -> V_2 = V_19 ;
}
}
V_7 = V_14 ;
} while( ++ V_6 );
F_10 () ;
return NULL ;
}
void F_3 ( const char * V_1 , T_5 V_4 , T_6 * V_5 ) {
F_11 ( V_5 && * V_5 <= 2 ) ;
if ( V_4 ) {
F_6 ( 3 , ( L_8 , V_1 ? V_1 : L_9 , F_12 ( V_5 , V_4 ) ) ) ;
F_1 ( V_1 , V_19 , NULL , NULL , V_4 , V_5 ) ;
} else {
F_6 ( 1 , ( L_10 , V_1 ? V_1 : L_9 ) ) ;
}
}
void F_13 ( const char * V_1 , const T_7 * V_20 ) {
T_6 * V_5 ;
T_5 V_4 = F_14 ( V_20 , & V_5 ) ;
if ( V_4 ) {
F_6 ( 3 , ( L_11 , V_1 ? V_1 : L_9 , F_12 ( V_5 , V_4 ) ) ) ;
F_1 ( V_1 , V_19 , NULL , NULL , V_4 , V_5 ) ;
} else {
F_6 ( 1 , ( L_12 , V_1 ? V_1 : L_9 , V_20 ? V_20 : NULL ) ) ;
}
}
extern void F_15 ( const char * V_1 , const T_8 * V_21 , T_9 V_4 ) {
T_6 * V_5 ;
T_5 V_22 = F_16 ( V_21 , V_4 , & V_5 ) ;
if ( V_22 ) {
F_6 ( 3 , ( L_13 , V_1 , F_12 ( V_5 , V_22 ) ) ) ;
F_1 ( V_1 , V_19 , NULL , NULL , V_22 , V_5 ) ;
} else {
F_6 ( 1 , ( L_14 , V_1 ? V_1 : L_9 , V_4 , F_17 ( V_21 , V_4 , ':' ) ) ) ;
}
}
static void F_18 ( void * V_23 ) {
#if ( V_24 >= 0 ) && ( V_25 >= 4 ) && ( V_26 >= 8 )
F_19 ( V_23 ) ;
#else
#ifdef F_20
#error Invalid Windows libsmi version ?? !!
#endif
#define F_21 free
F_21 ( V_23 ) ;
#endif
}
static void F_22 ( char * V_27 , int line , int V_28 , char * V_29 , char * V_30 ) {
F_23 ( V_31 , L_15 ,
V_27 ? V_27 : L_16 ,
line , V_28 ,
V_30 ? V_30 : L_16 ,
V_29 ? V_29 : L_17 ) ;
}
static void * F_24 ( void * V_32 , const void * V_33 , T_10 T_11 V_34 ) {
const T_12 * V_35 = V_33 ;
T_12 * V_36 = V_32 ;
V_36 -> V_1 = F_7 ( V_35 -> V_1 ) ;
return V_36 ;
}
static void F_25 ( void * V_37 ) {
T_12 * V_35 = V_37 ;
F_26 ( V_35 -> V_1 ) ;
}
static char * F_27 ( const char * V_1 ) {
char * V_38 = F_7 ( V_1 ) ;
char * V_39 = V_38 ;
char * V_40 = V_39 ;
char V_7 ;
for (; ( V_7 = * V_39 ) ; V_39 ++ ) {
if ( isalnum ( V_7 ) || V_7 == '_' || V_7 == '-' || V_7 == '.' ) {
* ( V_40 ++ ) = V_7 ;
} else if ( V_7 == ':' && V_39 [ 1 ] == ':' ) {
* ( V_40 ++ ) = '.' ;
}
}
* V_40 = '\0' ;
return V_38 ;
}
static const T_3 * F_28 ( T_13 * V_41 ) {
static const struct V_42 {
const char * V_1 ;
T_14 V_43 ;
const T_3 * type ;
} V_44 [] = {
{ L_18 , V_45 , & V_46 } ,
{ L_19 , V_45 , & V_46 } ,
{ L_20 , V_45 , & V_47 } ,
{ L_21 , V_45 , & V_46 } ,
{ L_22 , V_45 , & V_48 } ,
{ L_23 , V_45 , & V_49 } ,
{ L_24 , V_45 , & V_47 } ,
{ L_25 , V_45 , & V_49 } ,
{ L_26 , V_45 , & V_50 } ,
{ L_27 , V_45 , & V_50 } ,
{ L_28 , V_45 , & V_50 } ,
{ L_29 , V_45 , & V_51 } ,
{ L_30 , V_45 , & V_51 } ,
{ L_31 , V_45 , & V_52 } ,
{ L_32 , V_45 , & V_52 } ,
{ L_33 , V_45 , & V_52 } ,
{ L_34 , V_45 , & V_53 } ,
{ L_35 , V_54 , & V_55 } ,
{ L_36 , V_56 , & V_57 } ,
{ L_37 , V_58 , & V_59 } ,
{ L_38 , V_60 , & V_52 } ,
{ L_39 , V_61 , & V_62 } ,
{ L_40 , V_63 , & V_64 } ,
{ L_41 , V_65 , & V_66 } ,
{ L_42 , V_67 , & V_57 } ,
{ L_43 , V_68 , & V_55 } ,
{ L_44 , V_69 , & V_57 } ,
{ L_45 , V_45 , & V_70 } ,
{ NULL , 0 , NULL }
} ;
const struct V_42 * V_71 ;
T_13 * V_72 = V_41 ;
if ( ! V_41 ) return NULL ;
do {
for ( V_71 = V_44 ; V_71 -> type ; V_71 ++ ) {
char * V_1 = F_29 ( V_72 , V_73 ) ;
if ( V_1 && V_71 -> V_1 && F_5 ( V_1 , V_71 -> V_1 ) ) {
F_18 ( V_1 ) ;
return V_71 -> type ;
}
if ( V_1 ) {
F_18 ( V_1 ) ;
}
}
} while( ( V_72 = F_30 ( V_72 ) ) );
for ( V_71 = V_44 ; V_71 -> type ; V_71 ++ ) {
if( V_41 -> V_74 == V_71 -> V_43 ) {
return V_71 -> type ;
}
}
return & V_70 ;
}
static T_5 F_31 ( T_13 * V_72 ) {
T_15 * V_75 ;
T_5 V_76 = 0xffffffff ;
switch ( V_72 -> V_74 ) {
case V_56 :
case V_58 :
break;
default:
return 0 ;
}
for ( ; V_72 ; V_72 = F_30 ( V_72 ) ) {
for ( V_75 = F_32 ( V_72 ) ; V_75 ; V_75 = F_33 ( V_75 ) ) {
if ( V_76 == 0xffffffff ) {
if ( V_75 -> V_77 . V_78 . V_79 == V_75 -> V_80 . V_78 . V_79 ) {
V_76 = V_75 -> V_77 . V_78 . V_79 ;
} else {
return 0 ;
}
} else {
if ( V_75 -> V_77 . V_78 . V_79 != V_76 || V_75 -> V_80 . V_78 . V_79 != V_76 ) {
return 0 ;
}
}
}
}
return V_76 == 0xffffffff ? 0 : V_76 ;
}
static inline T_2 F_34 ( T_16 * V_81 , T_4 * * V_82 ) {
* V_82 = NULL ;
switch( V_81 -> V_83 ) {
case V_84 : {
T_17 * V_85 ;
T_4 * V_86 = NULL ;
const T_3 * V_87 = NULL ;
T_18 V_88 ;
switch ( V_81 -> V_89 ) {
case V_90 :
break;
case V_91 :
case V_92 :
case V_93 :
case V_94 :
V_81 = F_35 ( V_81 ) ;
break;
case V_95 :
return V_19 ;
} ;
V_88 = V_81 -> V_88 ;
for ( V_85 = F_36 ( V_81 ) ; V_85 ; V_85 = F_37 ( V_85 ) ) {
T_16 * V_96 = F_38 ( V_85 ) ;
T_13 * V_97 = F_39 ( V_96 ) ;
T_4 * V_98 ;
T_5 V_99 = 0 ;
char * V_100 , * V_101 ;
if ( V_97 ) {
V_99 = F_31 ( V_97 ) ;
}
V_87 = F_28 ( V_97 ) ;
V_98 = F_8 ( sizeof( T_4 ) ) ;
V_100 = F_40 ( V_81 -> V_102 , V_81 -> V_21 , V_103 ) ;
V_101 = F_40 ( V_96 -> V_102 , V_96 -> V_21 , V_73 ) ;
V_98 -> V_1 = F_41 ( L_46 , V_100 , V_101 ) ;
F_18 ( V_100 ) ;
F_18 ( V_101 ) ;
V_98 -> V_104 = - 2 ;
V_98 -> V_105 = V_87 ? V_87 -> V_105 : V_106 ;
V_98 -> V_107 = V_87 ? V_87 -> V_107 : V_108 ;
V_98 -> V_109 = NULL ;
if ( V_87 ) {
V_98 -> V_110 = V_87 -> V_111 ;
V_98 -> V_112 = V_87 -> V_113 ;
} else {
if ( V_97 ) {
switch ( V_97 -> V_74 ) {
case V_69 :
case V_56 : {
V_98 -> V_110 = V_114 ;
V_98 -> V_112 = V_99 ;
break;
}
case V_68 :
case V_58 :
case V_54 :
case V_60 :
case V_115 :
case V_61 :
V_98 -> V_110 = V_116 ;
V_98 -> V_112 = 1 ;
break;
default:
V_98 -> V_110 = V_117 ;
V_98 -> V_112 = 0 ;
break;
}
} else {
V_98 -> V_110 = V_117 ;
V_98 -> V_112 = 0 ;
break;
}
}
if ( ! * V_82 ) * V_82 = V_98 ;
if ( V_86 ) V_86 -> V_109 = V_98 ;
V_86 = V_98 ;
}
if ( V_88 && V_86 ) {
switch ( V_86 -> V_110 ) {
case V_114 : V_86 -> V_110 = V_118 ; break;
case V_119 : V_86 -> V_110 = V_120 ; break;
case V_121 : V_86 -> V_110 = V_122 ; break;
default: break;
}
}
return V_123 ;
}
case V_124 : return V_125 ;
case V_126 : return V_127 ;
case V_128 : return V_129 ;
case V_130 : return V_131 ;
case V_132 : return V_133 ;
case V_134 : return V_135 ;
case V_136 : return V_137 ;
case V_138 : return V_139 ;
default: return V_19 ;
}
}
static void F_42 ( void ) {
}
static void F_43 ( void ) {
if ( V_140 )
F_44 ( L_47 ) ;
}
static void F_45 ( void ) {
T_19 * V_141 ;
T_16 * V_142 ;
T_5 V_6 ;
int V_143 = - 1 ;
T_20 * V_144 = F_46 ( FALSE , TRUE , sizeof( V_145 ) ) ;
T_20 * V_146 = F_46 ( FALSE , TRUE , sizeof( T_9 * ) ) ;
static T_21 V_147 [] = {
F_47 ( V_148 , V_1 , L_48 , L_49 ) ,
V_149
} ;
static T_21 V_150 [] = {
F_48 ( V_148 , V_1 , L_50 , L_51 ) ,
V_149
} ;
char * V_151 = NULL ;
T_7 * V_152 ;
V_153 = F_49 ( L_52 ,
sizeof( T_12 ) ,
L_53 ,
FALSE ,
( void * ) & V_154 ,
& V_155 ,
V_156 ,
L_54 ,
F_24 ,
NULL ,
F_25 ,
F_43 ,
V_147 ) ;
V_157 = F_49 ( L_55 ,
sizeof( T_12 ) ,
L_56 ,
FALSE ,
( void * ) & V_158 ,
& V_159 ,
V_156 ,
L_57 ,
F_24 ,
NULL ,
F_25 ,
F_43 ,
V_150 ) ;
F_50 ( V_153 , & V_151 ) ;
if ( V_151 ) {
F_44 ( L_58 , V_151 ) ;
return;
}
F_50 ( V_157 , & V_151 ) ;
if ( V_151 ) {
F_44 ( L_59 , V_151 ) ;
return;
}
if ( ! V_160 . V_161 ) {
F_6 ( 1 , ( L_60 ) ) ;
return;
}
if ( V_140 ) {
F_6 ( 1 , ( L_61 ) ) ;
return;
} else {
V_140 = TRUE ;
}
F_51 ( NULL ) ;
V_31 = F_52 ( L_17 ) ;
F_53 ( F_22 ) ;
V_152 = F_54 () ;
F_6 ( 1 , ( L_62 , V_152 ) ) ;
F_55 ( V_152 ) ;
for( V_6 = 0 ; V_6 < V_155 ; V_6 ++ ) {
if ( ! V_154 [ V_6 ] . V_1 ) continue;
if ( F_56 ( V_154 [ V_6 ] . V_1 ) ) {
continue;
} else {
char * V_162 = F_57 ( V_154 [ V_6 ] . V_1 ) ;
if ( V_162 )
F_6 ( 2 , ( L_63 , V_154 [ V_6 ] . V_1 , V_6 , V_162 ) ) ;
else
F_6 ( 1 , ( L_64 , V_154 [ V_6 ] . V_1 , V_6 ) ) ;
}
}
if ( V_31 -> T_11 ) {
if ( ! V_160 . V_163 ) {
F_44 ( L_65
L_66
L_67
L_68
L_69 , V_31 -> V_164 , V_152 ) ;
}
F_6 ( 1 , ( L_70 , V_31 -> V_164 ) ) ;
}
F_26 ( V_152 ) ;
F_58 ( V_31 , TRUE ) ;
for ( V_141 = F_59 () ;
V_141 ;
V_141 = F_60 ( V_141 ) ) {
F_6 ( 3 , ( L_71 , V_141 -> V_1 ) ) ;
if ( V_141 -> V_165 == 1 ) {
if ( ! V_160 . V_163 ) {
F_44 ( L_72
L_73
L_74
L_75 ,
V_141 -> V_1 , V_141 -> V_165 ) ;
}
continue;
}
for ( V_142 = F_61 ( V_141 , V_166 ) ;
V_142 ;
V_142 = F_62 ( V_142 , V_166 ) ) {
T_13 * V_41 = F_39 ( V_142 ) ;
const T_3 * V_87 = F_28 ( V_41 ) ;
T_4 * V_3 ;
T_2 V_2 = F_34 ( V_142 , & V_3 ) ;
char * V_21 = F_40 ( V_142 -> V_102 , V_142 -> V_21 , V_103 ) ;
T_1 * V_167 = F_1 ( V_21 ,
V_2 ,
V_87 ,
V_3 ,
V_142 -> V_102 ,
V_142 -> V_21 ) ;
F_18 ( V_21 ) ;
F_6 ( 4 , ( L_76 ,
V_167 -> V_2 , F_12 ( V_142 -> V_21 , V_142 -> V_102 ) , V_167 -> V_1 ) ) ;
if ( V_87 && V_167 -> V_16 == - 2 ) {
T_22 * V_168 ;
V_145 V_169 = { & ( V_167 -> V_16 ) , {
V_167 -> V_1 ,
F_27 ( V_167 -> V_1 ) ,
V_87 -> V_105 ,
V_87 -> V_107 ,
NULL ,
0 ,
F_40 ( V_142 -> V_102 , V_142 -> V_21 , V_170 ) ,
V_171 } } ;
if ( strcmp ( V_169 . V_172 . V_173 , V_169 . V_172 . V_1 ) == 0 ) {
F_18 ( ( void * ) V_169 . V_172 . V_173 ) ;
V_169 . V_172 . V_173 = NULL ;
}
V_167 -> V_16 = - 1 ;
if ( F_63 ( V_169 . V_172 . type ) && ( V_168 = F_64 ( V_41 ) ) ) {
T_20 * V_174 = F_46 ( TRUE , TRUE , sizeof( V_175 ) ) ;
for(; V_168 ; V_168 = F_65 ( V_168 ) ) {
if ( V_168 -> V_1 ) {
V_175 V_176 = { V_168 -> V_78 . V_78 . V_177 , F_7 (smiEnum->name) } ;
F_66 ( V_174 , V_176 ) ;
}
}
V_169 . V_172 . V_178 = V_174 -> V_179 ;
F_67 ( V_174 , FALSE ) ;
}
#if 0
} else if (smiType->basetype == SMI_BASETYPE_BITS && ( smiEnum = smiGetFirstNamedNumber(smiType) )) {
guint n = 0;
oid_bits_info_t* bits = g_malloc(sizeof(oid_bits_info_t));
gint* ettp = &(bits->ett);
bits->num = 0;
bits->ett = -1;
g_array_append_val(etta,ettp);
for(;smiEnum; smiEnum = smiGetNextNamedNumber(smiEnum), bits->num++);
bits->data = g_malloc(sizeof(struct _oid_bit_t)*bits->num);
for(smiEnum = smiGetFirstNamedNumber(smiType),n=0;
smiEnum;
smiEnum = smiGetNextNamedNumber(smiEnum),n++) {
guint mask = 1 << (smiEnum->value.value.integer32 % 8);
char* base = alnumerize(oid_data->name);
char* ext = alnumerize(smiEnum->name);
hf_register_info hf2 = { &(bits->data[n].hfid), { NULL, NULL, FT_UINT8, BASE_HEX, NULL, mask, NULL, HFILL }};
bits->data[n].hfid = -1;
bits->data[n].offset = smiEnum->value.value.integer32 / 8;
hf2.hfinfo.name = g_strdup_printf("%s:%s",oid_data->name,smiEnum->name);
hf2.hfinfo.abbrev = g_strdup_printf("%s.%s",base,ext);
g_free(base);
g_free(ext);
g_array_append_val(hfa,hf2);
}
#endif
F_66 ( V_144 , V_169 ) ;
}
if ( ( V_3 = V_167 -> V_3 ) ) {
for(; V_3 ; V_3 = V_3 -> V_109 ) {
V_145 V_169 = { & ( V_3 -> V_104 ) , {
V_3 -> V_1 ,
F_27 ( V_3 -> V_1 ) ,
V_3 -> V_105 ,
V_3 -> V_107 ,
NULL ,
0 ,
NULL ,
V_171 } } ;
F_6 ( 5 , ( L_77 ,
V_3 -> V_1 , V_3 -> V_112 , V_3 -> V_110 ) ) ;
if ( V_3 -> V_104 == - 2 ) {
F_66 ( V_144 , V_169 ) ;
V_3 -> V_104 = - 1 ;
} else {
F_26 ( ( void * ) V_169 . V_172 . V_180 ) ;
}
}
}
}
}
V_143 = F_68 ( L_78 , L_79 , L_80 ) ;
F_69 ( V_143 , ( V_145 * ) ( void * ) V_144 -> V_179 , V_144 -> T_11 ) ;
F_70 ( ( T_9 * * ) ( void * ) V_146 -> V_179 , V_146 -> T_11 ) ;
F_67 ( V_146 , TRUE ) ;
F_67 ( V_144 , FALSE ) ;
}
void F_71 ( void ) {
#ifdef F_72
F_45 () ;
#else
F_6 ( 1 , ( L_81 ) ) ;
#endif
}
void F_73 ( void ) {
#ifdef F_72
F_42 () ;
#else
F_6 ( 1 , ( L_81 ) ) ;
#endif
}
const char * F_12 ( T_6 * V_5 , T_5 T_11 ) {
char * V_38 = F_74 ( ( ( T_11 ) * 11 ) + 1 ) ;
char * V_40 = V_38 ;
if( ! V_5 )
return L_82 ;
do {
V_40 += F_75 ( V_40 , 12 , L_83 , * V_5 ++ ) ;
} while( -- T_11 );
if ( V_40 != V_38 ) * ( V_40 - 1 ) = '\0' ; else * ( V_38 ) = '\0' ;
return V_38 ;
}
static T_5 F_76 ( const char * V_164 ) {
const char * V_39 = V_164 ;
char V_7 = '\0' ;
T_5 V_14 = 0 ;
F_6 ( 8 , ( L_84 , V_164 ) ) ;
if ( ! V_39 || * V_39 == '.' || * V_39 == '\0' ) return 0 ;
do {
F_6 ( 9 , ( L_85 , * V_39 , V_14 ) ) ;
switch( * V_39 ) {
case '.' :
V_14 ++ ;
if ( V_7 == '.' ) return 0 ;
case '1' : case '2' : case '3' : case '4' : case '5' :
case '6' : case '7' : case '8' : case '9' : case '0' :
continue;
case '\0' :
V_14 ++ ;
break;
default:
return 0 ;
}
} while( ( V_7 = * V_39 ++ ) );
if ( V_7 == '.' ) return 0 ;
return V_14 ;
}
T_5 F_14 ( const char * V_164 , T_6 * * V_181 ) {
const char * V_39 = V_164 ;
T_6 * V_5 ;
T_6 * V_182 ;
T_5 V_14 = F_76 ( V_164 ) ;
T_23 V_11 = 0 ;
F_6 ( 6 , ( L_86 , V_164 ) ) ;
if ( ! V_14 ) {
* V_181 = NULL ;
return 0 ;
}
* V_181 = V_5 = F_74 ( sizeof( T_6 ) * V_14 ) ;
V_182 = V_5 + V_14 ;
do switch( * V_39 ) {
case '.' :
V_11 = 0 ;
V_5 ++ ;
continue;
case '1' : case '2' : case '3' : case '4' : case '5' :
case '6' : case '7' : case '8' : case '9' : case '0' :
V_11 *= 10 ;
V_11 += * V_39 - '0' ;
if( V_5 >= V_182 || V_11 > 0xffffffff ) {
* V_181 = NULL ;
return 0 ;
}
* ( V_5 ) *= 10 ;
* ( V_5 ) += * V_39 - '0' ;
continue;
case '\0' :
break;
default:
return 0 ;
} while( * V_39 ++ );
return V_14 ;
}
T_5 F_16 ( const T_8 * V_183 , T_9 V_4 , T_6 * * V_181 ) {
T_9 V_6 ;
T_5 V_14 = 1 ;
T_18 V_184 = TRUE ;
T_6 * V_5 ;
T_6 * V_185 ;
T_23 V_11 = 0 ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ ) { if ( ! ( V_183 [ V_6 ] & 0x80 ) ) V_14 ++ ; }
* V_181 = V_5 = F_77 ( sizeof( T_6 ) * V_14 ) ;
V_185 = V_5 + V_14 ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ ) {
T_8 V_186 = V_183 [ V_6 ] ;
V_11 <<= 7 ;
V_11 |= V_186 & 0x7F ;
if ( V_186 & 0x80 ) {
continue;
}
if ( V_184 ) {
T_6 V_187 = 0 ;
if ( V_11 >= 40 ) { V_187 ++ ; V_11 -= 40 ; }
if ( V_11 >= 40 ) { V_187 ++ ; V_11 -= 40 ; }
* V_5 ++ = V_187 ;
V_184 = FALSE ;
}
if( V_5 >= V_185 || V_11 > 0xffffffff ) {
* V_181 = NULL ;
return 0 ;
}
* V_5 ++ = ( T_6 ) V_11 ;
V_11 = 0 ;
}
return V_14 ;
}
T_1 * F_78 ( T_5 T_11 , T_6 * V_5 , T_5 * V_188 , T_5 * V_189 ) {
T_1 * V_190 = & V_8 ;
T_5 V_6 ;
if( ! ( V_5 && * V_5 <= 2 ) ) {
* V_188 = 0 ;
* V_189 = T_11 ;
return V_190 ;
}
for( V_6 = 0 ; V_6 < T_11 ; V_6 ++ ) {
T_1 * V_191 = F_4 ( V_190 -> V_9 , V_5 [ V_6 ] ) ;
if ( V_191 ) {
V_190 = V_191 ;
} else {
goto V_192;
}
}
V_192:
* V_188 = V_6 ;
* V_189 = T_11 - V_6 ;
return V_190 ;
}
T_1 * F_79 ( const T_8 * V_193 , T_9 V_194 , T_6 * * V_181 , T_5 * V_195 , T_5 * V_196 ) {
T_5 V_22 = F_16 ( V_193 , V_194 , V_181 ) ;
return F_78 ( V_22 , * V_181 , V_195 , V_196 ) ;
}
T_1 * F_80 ( const T_7 * V_20 , T_6 * * V_181 , T_5 * V_188 , T_5 * V_189 ) {
T_5 V_22 = F_14 ( V_20 , V_181 ) ;
return F_78 ( V_22 , * V_181 , V_188 , V_189 ) ;
}
const T_7 * F_81 ( const T_8 * V_21 , T_9 V_4 ) {
T_6 * V_197 ;
T_5 V_198 = F_16 ( V_21 , V_4 , & V_197 ) ;
return F_82 ( V_198 , V_197 ) ;
}
T_5 F_83 ( T_5 V_22 , T_6 * V_5 , T_8 * * V_199 ) {
T_5 V_200 = 0 ;
T_5 V_6 ;
T_6 V_11 ;
T_8 * V_201 ;
if ( ! V_5 || V_22 <= 0 ) {
* V_199 = NULL ;
return 0 ;
}
V_11 = ( V_5 [ 0 ] * 40 ) + V_5 [ 1 ] ;
V_6 = 2 ;
do {
if ( V_11 <= 0x0000007F ) {
V_200 += 1 ;
} else if ( V_11 <= 0x00003FFF ) {
V_200 += 2 ;
} else if ( V_11 <= 0x001FFFFF ) {
V_200 += 3 ;
} else if ( V_11 <= 0x0FFFFFFF ) {
V_200 += 4 ;
} else {
V_200 += 5 ;
}
V_11 = V_5 [ V_6 ] ;
} while ( V_6 ++ < V_22 );
* V_199 = V_201 = F_77 ( V_200 ) ;
V_11 = ( V_5 [ 0 ] * 40 ) + V_5 [ 1 ] ;
V_6 = 2 ;
do {
T_5 T_11 ;
if ( ( V_11 <= 0x0000007F ) ) T_11 = 1 ;
else if ( ( V_11 <= 0x00003FFF ) ) T_11 = 2 ;
else if ( ( V_11 <= 0x001FFFFF ) ) T_11 = 3 ;
else if ( ( V_11 <= 0x0FFFFFFF ) ) T_11 = 4 ;
else T_11 = 5 ;
switch( T_11 ) {
default: * V_199 = NULL ; return 0 ;
case 5 : * ( V_201 ++ ) = ( ( V_11 & 0xF0000000 ) >> 28 ) | 0x80 ;
case 4 : * ( V_201 ++ ) = ( ( V_11 & 0x0FE00000 ) >> 21 ) | 0x80 ;
case 3 : * ( V_201 ++ ) = ( ( V_11 & 0x001FC000 ) >> 14 ) | 0x80 ;
case 2 : * ( V_201 ++ ) = ( ( V_11 & 0x00003F10 ) >> 7 ) | 0x80 ;
case 1 : * ( V_201 ++ ) = V_11 & 0x0000007F ; break;
}
V_11 = V_5 [ V_6 ] ;
} while ( V_6 ++ < V_22 );
return V_200 ;
}
const T_7 * F_84 ( const T_8 * V_202 , T_5 T_11 ) {
T_6 * V_5 ;
T_5 V_22 = F_16 ( V_202 , T_11 , & V_5 ) ;
if ( V_22 ) {
return F_12 ( V_5 , V_22 ) ;
} else {
return L_17 ;
}
}
T_5 F_85 ( const char * V_20 , T_8 * * V_193 ) {
T_6 * V_5 ;
T_6 V_22 ;
T_5 V_194 ;
if ( ( V_22 = F_14 ( V_20 , & V_5 ) )
&&
( V_194 = F_83 ( V_22 , V_5 , V_193 ) ) ) {
return V_194 ;
}
return 0 ;
}
const T_7 * F_86 ( const T_7 * V_20 ) {
T_6 * V_197 ;
T_5 V_198 = F_14 ( V_20 , & V_197 ) ;
return F_82 ( V_198 , V_197 ) ;
}
const T_7 * F_82 ( T_6 V_112 , T_6 * V_5 ) {
T_5 V_188 ;
T_5 V_189 ;
T_1 * V_21 ;
if( ! ( V_5 && * V_5 <= 2 ) )
return L_87 ;
V_21 = F_78 ( V_112 , V_5 , & V_188 , & V_189 ) ;
while ( ! V_21 -> V_1 ) {
if ( ! ( V_21 = V_21 -> V_17 ) ) {
return F_12 ( V_5 , V_112 ) ;
}
V_189 ++ ;
V_188 -- ;
}
if ( V_189 ) {
return F_87 ( L_46 ,
V_21 -> V_1 ? V_21 -> V_1 : F_12 ( V_5 , V_188 ) ,
F_12 ( & ( V_5 [ V_188 ] ) , V_189 ) ) ;
} else {
return V_21 -> V_1 ? V_21 -> V_1 : F_12 ( V_5 , V_188 ) ;
}
}
extern void F_88 ( T_5 V_4 , T_6 * V_5 , char * * V_203 , char * * V_204 ) {
* V_203 = ( void * ) F_82 ( V_4 , V_5 ) ;
* V_204 = ( void * ) F_12 ( V_5 , V_4 ) ;
}
extern void F_89 ( const T_8 * V_21 , T_9 V_4 , char * * V_203 , char * * V_204 ) {
T_6 * V_5 ;
T_5 V_22 = F_16 ( V_21 , V_4 , & V_5 ) ;
* V_203 = ( void * ) F_82 ( V_22 , V_5 ) ;
* V_204 = ( void * ) F_12 ( V_5 , V_22 ) ;
}
extern void F_90 ( const T_7 * V_20 , char * * V_203 , char * * V_204 ) {
T_6 * V_5 ;
T_5 V_22 = F_14 ( V_20 , & V_5 ) ;
* V_203 = ( void * ) F_82 ( V_22 , V_5 ) ;
* V_204 = ( void * ) F_12 ( V_5 , V_22 ) ;
}
extern T_7 *
F_54 ( void ) {
#ifdef F_72
T_24 * V_152 ;
T_7 * V_205 ;
char * V_27 ;
T_5 V_6 ;
V_152 = F_52 ( L_17 ) ;
if ( ! V_160 . V_161 ) {
F_6 ( 1 , ( L_60 ) ) ;
return V_152 -> V_164 ;
}
#ifdef F_20
#define F_91 ";"
V_27 = F_92 ( L_88 ) ;
F_23 ( V_152 , L_89 , V_27 ) ;
F_26 ( V_27 ) ;
V_27 = F_93 ( L_88 , FALSE , FALSE ) ;
F_23 ( V_152 , L_90 , V_27 ) ;
F_26 ( V_27 ) ;
#else
#define F_91 ":"
V_27 = F_94 () ;
F_95 ( V_152 , L_91 ) ;
if ( strlen ( V_27 ) > 0 ) {
F_95 ( V_152 , F_91 ) ;
}
F_23 ( V_152 , L_90 , V_27 ) ;
free ( V_27 ) ;
#endif
for( V_6 = 0 ; V_6 < V_159 ; V_6 ++ ) {
if ( ! ( V_158 [ V_6 ] . V_1 && * V_158 [ V_6 ] . V_1 ) )
continue;
F_23 ( V_152 , F_91 L_90 , V_158 [ V_6 ] . V_1 ) ;
}
V_205 = V_152 -> V_164 ;
F_58 ( V_152 , FALSE ) ;
return V_205 ;
#else
return F_7 ( L_17 ) ;
#endif
}
char * F_96 ( T_6 V_112 , T_6 * V_5 ) {
T_8 * V_206 ;
T_8 * V_207 ;
T_6 * V_208 ;
T_6 * V_209 ;
const char * V_210 = F_12 ( V_5 , V_112 ) ;
T_5 V_211 = F_83 ( V_112 , V_5 , & V_206 ) ;
T_5 V_212 = F_16 ( V_206 , V_211 , & V_208 ) ;
const char * V_213 = F_84 ( V_206 , V_211 ) ;
T_5 V_214 = F_85 ( V_210 , & V_207 ) ;
T_5 V_215 = F_14 ( V_210 , & V_209 ) ;
return F_87 (
L_92
L_93
L_94
L_95
L_96
L_97
, V_210
, V_211 , F_17 ( V_206 , V_211 , ':' )
, V_208 ? F_12 ( V_208 , V_212 ) : L_16
, V_213
, V_214 , F_17 ( V_207 , V_214 , ':' )
, V_209 ? F_12 ( V_209 , V_215 ) : L_16
) ;
}
void F_97 ( T_1 * V_216 , T_25 * V_217 ) {
static const char * V_218 [] = { L_98 , L_99 , L_100 , L_101 , L_102 , L_103 , L_104 , L_105 , L_106 , L_107 } ;
static const char * V_219 [] = { L_108 , L_109 ,
L_110 , L_111 , L_112 ,
L_113 , L_114 , L_115 , L_116 } ;
T_26 * V_220 = F_98 ( V_217 , NULL , 0 , 0 ,
L_117 ,
V_216 -> V_1 ? V_216 -> V_1 : L_17 ,
V_216 -> V_11 ,
V_216 -> V_2 <= V_139 ? V_218 [ V_216 -> V_2 ] : L_118 ,
V_216 -> V_16 ) ;
T_25 * V_221 = F_99 ( V_220 , 0 ) ;
T_4 * V_3 ;
for( V_3 = V_216 -> V_3 ; V_3 ; V_3 = V_3 -> V_109 ) {
F_98 ( V_221 , NULL , 0 , 0 ,
L_119 ,
V_3 -> V_1 ,
V_3 -> V_110 <= V_222 ? V_219 [ V_3 -> V_110 ] : L_118
) ;
} ;
if ( V_216 -> V_17 ) {
V_220 = F_98 ( V_221 , NULL , 0 , 0 , L_120 ) ;
V_221 = F_99 ( V_220 , 0 ) ;
F_97 ( V_216 -> V_17 , V_221 ) ;
}
}
