static T_1 * F_1 ( const char * V_1 , T_2 V_2 , const T_3 * type , T_4 * V_3 , T_5 V_4 , T_6 * V_5 ) {
T_5 V_6 = 0 ;
T_1 * V_7 = & V_8 ;
if ( ! V_8 . V_9 ) {
char * V_10 = getenv ( L_1 ) ;
T_6 V_11 ;
V_12 = V_10 ? ( int ) strtoul ( V_10 , NULL , 10 ) : 0 ;
V_8 . V_9 = F_2 ( F_3 () ) ;
V_11 = 0 ; F_4 ( L_2 , 1 , & V_11 ) ;
V_11 = 1 ; F_4 ( L_3 , 1 , & V_11 ) ;
V_11 = 2 ; F_4 ( L_4 , 1 , & V_11 ) ;
}
V_4 -- ;
do {
T_1 * V_13 = ( T_1 * ) F_5 ( V_7 -> V_9 , V_5 [ V_6 ] ) ;
if( V_13 ) {
if ( V_6 == V_4 ) {
if ( V_13 -> V_1 ) {
if ( ! F_6 ( V_13 -> V_1 , V_1 ) ) {
F_7 ( 2 , ( L_5 , V_13 -> V_1 , V_1 ) ) ;
}
F_8 ( F_3 () , V_13 -> V_1 ) ;
}
V_13 -> V_1 = F_9 ( F_3 () , V_1 ) ;
if ( ! V_13 -> V_14 ) {
V_13 -> V_14 = type ;
}
return V_13 ;
}
} else {
V_13 = F_10 ( F_3 () , T_1 ) ;
V_13 -> V_11 = V_5 [ V_6 ] ;
V_13 -> V_2 = V_2 ;
V_13 -> V_9 = F_2 ( F_3 () ) ;
V_13 -> V_15 = - 2 ;
V_13 -> V_3 = V_3 ;
V_13 -> V_16 = V_7 ;
V_13 -> V_17 = NULL ;
F_11 ( V_7 -> V_9 , V_13 -> V_11 , V_13 ) ;
if ( V_6 == V_4 ) {
V_13 -> V_1 = F_9 ( F_3 () , V_1 ) ;
V_13 -> V_14 = type ;
V_13 -> V_2 = V_2 ;
return V_13 ;
} else {
V_13 -> V_1 = NULL ;
V_13 -> V_14 = NULL ;
V_13 -> V_2 = V_18 ;
}
}
V_7 = V_13 ;
} while( ++ V_6 );
F_12 () ;
return NULL ;
}
void F_4 ( const char * V_1 , T_5 V_4 , T_6 * V_5 ) {
F_13 ( V_5 && * V_5 <= 2 ) ;
if ( V_4 ) {
F_7 ( 3 , ( L_6 , V_1 ? V_1 : L_7 , F_14 ( V_5 , V_4 ) ) ) ;
F_1 ( V_1 , V_18 , NULL , NULL , V_4 , V_5 ) ;
} else {
F_7 ( 1 , ( L_8 , V_1 ? V_1 : L_7 ) ) ;
}
}
void F_15 ( const char * V_1 , const T_7 * V_19 ) {
T_6 * V_5 ;
T_5 V_4 = F_16 ( V_19 , & V_5 ) ;
if ( V_4 ) {
F_7 ( 3 , ( L_9 , V_1 ? V_1 : L_7 , F_14 ( V_5 , V_4 ) ) ) ;
F_1 ( V_1 , V_18 , NULL , NULL , V_4 , V_5 ) ;
} else {
F_7 ( 1 , ( L_10 , V_1 ? V_1 : L_7 , V_19 ? V_19 : NULL ) ) ;
}
}
extern void F_17 ( const char * V_1 , const T_8 * V_20 , T_9 V_4 ) {
T_6 * V_5 ;
T_5 V_21 = F_18 ( V_20 , V_4 , & V_5 ) ;
if ( V_21 ) {
F_7 ( 3 , ( L_11 , V_1 , F_14 ( V_5 , V_21 ) ) ) ;
F_1 ( V_1 , V_18 , NULL , NULL , V_21 , V_5 ) ;
} else {
F_7 ( 1 , ( L_12 , V_1 ? V_1 : L_7 , V_4 , F_19 ( V_20 , V_4 , ':' ) ) ) ;
}
}
static void F_20 ( void * V_22 ) {
#if ( V_23 >= 0 ) && ( V_24 >= 4 ) && ( V_25 >= 8 )
F_21 ( V_22 ) ;
#else
#ifdef F_22
#error Invalid Windows libsmi version ?? !!
#endif
#define F_23 free
F_23 ( V_22 ) ;
#endif
}
static void F_24 ( char * V_26 , int line , int V_27 , char * V_28 , char * V_29 ) {
F_25 ( V_30 , L_13 ,
V_26 ? V_26 : L_14 ,
line , V_27 ,
V_29 ? V_29 : L_14 ,
V_28 ? V_28 : L_15 ) ;
}
static void * F_26 ( void * V_31 , const void * V_32 , T_10 T_11 V_33 ) {
const T_12 * V_34 = ( const T_12 * ) V_32 ;
T_12 * V_35 = ( T_12 * ) V_31 ;
V_35 -> V_1 = F_27 ( V_34 -> V_1 ) ;
return V_35 ;
}
static void F_28 ( void * V_36 ) {
T_12 * V_34 = ( T_12 * ) V_36 ;
F_29 ( V_34 -> V_1 ) ;
}
static char * F_30 ( const char * V_1 ) {
char * V_37 = F_27 ( V_1 ) ;
char * V_38 = V_37 ;
char * V_39 = V_38 ;
char V_7 ;
for (; ( V_7 = * V_38 ) ; V_38 ++ ) {
if ( isalnum ( V_7 ) || V_7 == '_' || V_7 == '-' || V_7 == '.' ) {
* ( V_39 ++ ) = V_7 ;
} else if ( V_7 == ':' && V_38 [ 1 ] == ':' ) {
* ( V_39 ++ ) = '.' ;
}
}
* V_39 = '\0' ;
return V_37 ;
}
static const T_3 * F_31 ( T_13 * V_40 ) {
static const struct V_41 {
const char * V_1 ;
T_14 V_42 ;
const T_3 * type ;
} V_43 [] = {
{ L_16 , V_44 , & V_45 } ,
{ L_17 , V_44 , & V_45 } ,
{ L_18 , V_44 , & V_46 } ,
{ L_19 , V_44 , & V_45 } ,
{ L_20 , V_44 , & V_47 } ,
{ L_21 , V_44 , & V_48 } ,
{ L_22 , V_44 , & V_46 } ,
{ L_23 , V_44 , & V_48 } ,
{ L_24 , V_44 , & V_49 } ,
{ L_25 , V_44 , & V_49 } ,
{ L_26 , V_44 , & V_50 } ,
{ L_27 , V_44 , & V_51 } ,
{ L_28 , V_44 , & V_51 } ,
{ L_29 , V_44 , & V_52 } ,
{ L_30 , V_44 , & V_52 } ,
{ L_31 , V_44 , & V_52 } ,
{ L_32 , V_44 , & V_53 } ,
{ L_33 , V_54 , & V_55 } ,
{ L_34 , V_56 , & V_57 } ,
{ L_35 , V_58 , & V_59 } ,
{ L_36 , V_60 , & V_52 } ,
{ L_37 , V_61 , & V_62 } ,
{ L_38 , V_63 , & V_64 } ,
{ L_39 , V_65 , & V_66 } ,
{ L_40 , V_67 , & V_57 } ,
{ L_41 , V_68 , & V_55 } ,
{ L_42 , V_69 , & V_57 } ,
{ L_43 , V_44 , & V_70 } ,
{ NULL , V_44 , NULL }
} ;
const struct V_41 * V_71 ;
T_13 * V_72 = V_40 ;
if ( ! V_40 ) return NULL ;
do {
for ( V_71 = V_43 ; V_71 -> type ; V_71 ++ ) {
char * V_1 = F_32 ( V_72 , V_73 ) ;
if ( V_1 && V_71 -> V_1 && F_6 ( V_1 , V_71 -> V_1 ) ) {
F_20 ( V_1 ) ;
return V_71 -> type ;
}
if ( V_1 ) {
F_20 ( V_1 ) ;
}
}
} while( ( V_72 = F_33 ( V_72 ) ) );
for ( V_71 = V_43 ; V_71 -> type ; V_71 ++ ) {
if( V_40 -> V_74 == V_71 -> V_42 ) {
return V_71 -> type ;
}
}
return & V_70 ;
}
static T_5 F_34 ( T_13 * V_72 ) {
T_15 * V_75 ;
T_5 V_76 = 0xffffffff ;
switch ( V_72 -> V_74 ) {
case V_56 :
case V_58 :
break;
default:
return 0 ;
}
for ( ; V_72 ; V_72 = F_33 ( V_72 ) ) {
for ( V_75 = F_35 ( V_72 ) ; V_75 ; V_75 = F_36 ( V_75 ) ) {
if ( V_76 == 0xffffffff ) {
if ( V_75 -> V_77 . V_78 . V_79 == V_75 -> V_80 . V_78 . V_79 ) {
V_76 = ( T_6 ) V_75 -> V_77 . V_78 . V_79 ;
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
static inline T_2 F_37 ( T_16 * V_81 , T_4 * * V_82 ) {
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
V_81 = F_38 ( V_81 ) ;
break;
case V_95 :
return V_18 ;
} ;
V_88 = V_81 -> V_88 ;
for ( V_85 = F_39 ( V_81 ) ; V_85 ; V_85 = F_40 ( V_85 ) ) {
T_16 * V_96 = F_41 ( V_85 ) ;
T_13 * V_97 = F_42 ( V_96 ) ;
T_4 * V_98 ;
T_5 V_99 = 0 ;
char * V_100 , * V_101 ;
if ( V_97 ) {
V_99 = F_34 ( V_97 ) ;
}
V_87 = F_31 ( V_97 ) ;
V_98 = F_43 ( T_4 , 1 ) ;
V_100 = F_44 ( V_81 -> V_102 , V_81 -> V_20 , V_103 ) ;
V_101 = F_44 ( V_96 -> V_102 , V_96 -> V_20 , V_73 ) ;
V_98 -> V_1 = F_45 ( L_44 , V_100 , V_101 ) ;
F_20 ( V_100 ) ;
F_20 ( V_101 ) ;
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
default: return V_18 ;
}
}
static void F_46 ( void ) {
}
static void F_47 ( void ) {
if ( V_140 )
F_48 ( L_45 ) ;
}
static void F_49 ( void ) {
T_19 * V_141 ;
T_16 * V_142 ;
T_5 V_6 ;
int V_143 = - 1 ;
T_20 * V_144 ;
T_21 * V_145 ;
T_7 * V_146 ;
if ( ! V_147 ) {
F_7 ( 1 , ( L_46 ) ) ;
return;
}
if ( V_140 ) {
F_7 ( 1 , ( L_47 ) ) ;
return;
} else {
V_140 = TRUE ;
}
V_144 = F_50 ( F_3 () , sizeof( V_148 ) ) ;
V_145 = F_51 ( FALSE , TRUE , sizeof( T_9 * ) ) ;
F_52 ( NULL ) ;
V_30 = F_53 ( L_15 ) ;
F_54 ( F_24 ) ;
V_146 = F_55 () ;
F_7 ( 1 , ( L_48 , V_146 ) ) ;
F_56 ( V_146 ) ;
for( V_6 = 0 ; V_6 < V_149 ; V_6 ++ ) {
if ( ! V_150 [ V_6 ] . V_1 ) continue;
if ( F_57 ( V_150 [ V_6 ] . V_1 ) ) {
continue;
} else {
char * V_151 = F_58 ( V_150 [ V_6 ] . V_1 ) ;
if ( V_151 )
F_7 ( 2 , ( L_49 , V_150 [ V_6 ] . V_1 , V_6 , V_151 ) ) ;
else
F_7 ( 1 , ( L_50 , V_150 [ V_6 ] . V_1 , V_6 ) ) ;
}
}
if ( V_30 -> T_11 ) {
if ( ! V_152 ) {
F_48 ( L_51
L_52
L_53
L_54
L_55 , V_30 -> V_153 , V_146 ) ;
}
F_7 ( 1 , ( L_56 , V_30 -> V_153 ) ) ;
}
F_29 ( V_146 ) ;
F_59 ( V_30 , TRUE ) ;
for ( V_141 = F_60 () ;
V_141 ;
V_141 = F_61 ( V_141 ) ) {
F_7 ( 3 , ( L_57 , V_141 -> V_1 ) ) ;
if ( V_141 -> V_154 == 1 ) {
if ( ! V_152 ) {
F_48 ( L_58
L_59
L_60
L_61 ,
V_141 -> V_1 , V_141 -> V_154 ) ;
}
continue;
}
for ( V_142 = F_62 ( V_141 , V_155 ) ;
V_142 ;
V_142 = F_63 ( V_142 , V_155 ) ) {
T_13 * V_40 = F_42 ( V_142 ) ;
const T_3 * V_87 = F_31 ( V_40 ) ;
T_4 * V_3 ;
T_2 V_2 = F_37 ( V_142 , & V_3 ) ;
char * V_20 = F_44 ( V_142 -> V_102 , V_142 -> V_20 , V_103 ) ;
T_1 * V_156 = F_1 ( V_20 ,
V_2 ,
V_87 ,
V_3 ,
V_142 -> V_102 ,
V_142 -> V_20 ) ;
F_20 ( V_20 ) ;
F_7 ( 4 , ( L_62 ,
V_156 -> V_2 , F_14 ( V_142 -> V_20 , V_142 -> V_102 ) , V_156 -> V_1 ) ) ;
if ( V_87 && V_156 -> V_15 == - 2 ) {
T_22 * V_157 ;
V_148 V_158 = { & ( V_156 -> V_15 ) , {
V_156 -> V_1 ,
F_30 ( V_156 -> V_1 ) ,
V_87 -> V_105 ,
V_87 -> V_107 ,
NULL ,
0 ,
F_44 ( V_142 -> V_102 , V_142 -> V_20 , V_159 ) ,
V_160 } } ;
if ( strcmp ( V_158 . V_161 . V_162 , V_158 . V_161 . V_1 ) == 0 ) {
F_20 ( ( void * ) V_158 . V_161 . V_162 ) ;
V_158 . V_161 . V_162 = NULL ;
}
V_156 -> V_15 = - 1 ;
if ( F_64 ( V_158 . V_161 . type ) && ( V_157 = F_65 ( V_40 ) ) ) {
T_21 * V_163 = F_51 ( TRUE , TRUE , sizeof( V_164 ) ) ;
for(; V_157 ; V_157 = F_66 ( V_157 ) ) {
if ( V_157 -> V_1 ) {
V_164 V_165 = { ( T_6 ) V_157 -> V_78 . V_78 . V_166 , F_27 (smiEnum->name) } ;
F_67 ( V_163 , V_165 ) ;
}
}
V_158 . V_161 . V_167 = V_163 -> V_168 ;
F_68 ( V_163 , FALSE ) ;
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
F_69 ( V_144 , V_158 ) ;
}
if ( ( V_3 = V_156 -> V_3 ) ) {
for(; V_3 ; V_3 = V_3 -> V_109 ) {
V_148 V_158 = { & ( V_3 -> V_104 ) , {
V_3 -> V_1 ,
F_30 ( V_3 -> V_1 ) ,
V_3 -> V_105 ,
V_3 -> V_107 ,
NULL ,
0 ,
NULL ,
V_160 } } ;
F_7 ( 5 , ( L_63 ,
V_3 -> V_1 , V_3 -> V_112 , V_3 -> V_110 ) ) ;
if ( V_3 -> V_104 == - 2 ) {
F_69 ( V_144 , V_158 ) ;
V_3 -> V_104 = - 1 ;
} else {
F_29 ( ( void * ) V_158 . V_161 . V_169 ) ;
}
}
}
}
}
V_143 = F_70 ( L_64 , L_65 , L_66 ) ;
F_71 ( V_143 , ( V_148 * ) F_72 ( V_144 ) , F_73 ( V_144 ) ) ;
F_74 ( ( T_9 * * ) ( void * ) V_145 -> V_168 , V_145 -> T_11 ) ;
F_68 ( V_145 , TRUE ) ;
}
void F_75 ( T_23 * V_170 )
{
#ifdef F_76
static T_24 V_171 [] = {
F_77 ( V_172 , V_1 , L_67 , L_68 ) ,
V_173
} ;
static T_24 V_174 [] = {
F_78 ( V_172 , V_1 , L_69 , L_70 ) ,
V_173
} ;
F_79 ( V_170 , L_71 ,
L_72 ,
L_73 ,
& V_147 ) ;
F_79 ( V_170 , L_74 ,
L_75 ,
L_76 ,
& V_152 ) ;
V_175 = F_80 ( L_77 ,
sizeof( T_12 ) ,
L_78 ,
FALSE ,
( void * * ) & V_176 ,
& V_177 ,
V_178 ,
L_79 ,
F_26 ,
NULL ,
F_28 ,
F_47 ,
V_174 ) ;
F_81 ( V_170 ,
L_78 ,
L_80 ,
L_81
L_82 ,
V_175 ) ;
V_179 = F_80 ( L_83 ,
sizeof( T_12 ) ,
L_84 ,
FALSE ,
( void * * ) & V_150 ,
& V_149 ,
V_178 ,
L_85 ,
F_26 ,
NULL ,
F_28 ,
F_47 ,
V_171 ) ;
F_81 ( V_170 ,
L_84 ,
L_86 ,
L_87
L_82 ,
V_179 ) ;
#else
F_82 ( V_170 , L_88 ,
L_89 ,
L_90 ) ;
F_82 ( V_170 , L_91 ,
L_92 ,
L_90 ) ;
F_82 ( V_170 , L_93 ,
L_94 ,
L_90 ) ;
#endif
}
void F_83 ( void ) {
#ifdef F_76
F_49 () ;
#else
F_7 ( 1 , ( L_95 ) ) ;
#endif
}
void F_84 ( void ) {
#ifdef F_76
F_46 () ;
#else
F_7 ( 1 , ( L_95 ) ) ;
#endif
}
const char * F_14 ( T_6 * V_5 , T_5 T_11 ) {
return F_85 ( V_5 , T_11 , TRUE ) ;
}
const char * F_85 ( T_6 * V_5 , T_5 T_11 , T_18 V_180 ) {
char * V_37 , * V_39 ;
if( ! V_5 || T_11 == 0 )
return L_96 ;
V_37 = ( char * ) F_86 ( ( ( T_11 ) * 11 ) + 2 ) ;
V_39 = V_37 ;
if ( ! V_180 )
* V_39 ++ = '.' ;
do {
V_39 += F_87 ( V_39 , 12 , L_97 , * V_5 ++ ) ;
} while( -- T_11 );
if ( V_39 != V_37 ) * ( V_39 - 1 ) = '\0' ; else * ( V_37 ) = '\0' ;
return V_37 ;
}
static T_5 F_88 ( const char * V_153 ) {
const char * V_38 = V_153 ;
char V_7 = '.' ;
T_5 V_13 = 0 ;
F_7 ( 8 , ( L_98 , V_153 ) ) ;
if ( ! V_38 ) return 0 ;
do {
F_7 ( 9 , ( L_99 , * V_38 , V_13 ) ) ;
switch( * V_38 ) {
case '.' : case '\0' :
V_13 ++ ;
if ( V_7 == '.' ) return 0 ;
break;
case '1' : case '2' : case '3' : case '4' : case '5' :
case '6' : case '7' : case '8' : case '9' : case '0' :
continue;
default:
return 0 ;
}
} while( ( V_7 = * V_38 ++ ) );
return V_13 ;
}
T_5 F_16 ( const char * V_153 , T_6 * * V_181 ) {
const char * V_38 = V_153 ;
T_6 * V_5 ;
T_6 * V_182 ;
T_5 V_13 = F_88 ( V_153 ) ;
T_25 V_11 = 0 ;
F_7 ( 6 , ( L_100 , V_153 ) ) ;
if ( ! V_13 ) {
* V_181 = NULL ;
return 0 ;
}
* V_181 = V_5 = ( T_6 * ) F_86 ( sizeof( T_6 ) * V_13 ) ;
V_182 = V_5 + V_13 ;
do switch( * V_38 ) {
case '.' :
V_11 = 0 ;
V_5 ++ ;
continue;
case '1' : case '2' : case '3' : case '4' : case '5' :
case '6' : case '7' : case '8' : case '9' : case '0' :
V_11 *= 10 ;
V_11 += * V_38 - '0' ;
if( V_5 >= V_182 || V_11 > 0xffffffff ) {
* V_181 = NULL ;
return 0 ;
}
* ( V_5 ) *= 10 ;
* ( V_5 ) += * V_38 - '0' ;
continue;
case '\0' :
break;
default:
return 0 ;
} while( * V_38 ++ );
return V_13 ;
}
T_5 F_18 ( const T_8 * V_183 , T_9 V_4 , T_6 * * V_181 ) {
return F_89 ( V_183 , V_4 , V_181 , TRUE ) ;
}
T_5 F_89 ( const T_8 * V_183 , T_9 V_4 , T_6 * * V_181 ,
T_18 V_184 ) {
T_9 V_6 ;
T_5 V_13 = V_184 ? 1 : 0 ;
T_6 * V_5 ;
T_6 * V_185 ;
T_25 V_11 = 0 ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ ) { if ( ! ( V_183 [ V_6 ] & 0x80 ) ) V_13 ++ ; }
* V_181 = V_5 = ( T_6 * ) F_90 ( sizeof( T_6 ) * V_13 ) ;
V_185 = V_5 + V_13 ;
if ( ( V_184 && V_13 == 1 ) || ( ! V_184 && V_13 == 0 ) ) {
* V_5 = 0 ;
return V_13 ;
}
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
F_13 ( V_5 == V_185 ) ;
return V_13 ;
}
T_1 * F_91 ( T_5 T_11 , T_6 * V_5 , T_5 * V_188 , T_5 * V_189 ) {
T_1 * V_190 = & V_8 ;
T_5 V_6 ;
if( ! ( V_5 && * V_5 <= 2 ) ) {
* V_188 = 0 ;
* V_189 = T_11 ;
return V_190 ;
}
for( V_6 = 0 ; V_6 < T_11 ; V_6 ++ ) {
T_1 * V_191 = ( T_1 * ) F_5 ( V_190 -> V_9 , V_5 [ V_6 ] ) ;
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
T_1 * F_92 ( const T_8 * V_193 , T_9 V_194 , T_6 * * V_181 , T_5 * V_195 , T_5 * V_196 ) {
T_5 V_21 = F_18 ( V_193 , V_194 , V_181 ) ;
return F_91 ( V_21 , * V_181 , V_195 , V_196 ) ;
}
T_1 * F_93 ( const T_7 * V_19 , T_6 * * V_181 , T_5 * V_188 , T_5 * V_189 ) {
T_5 V_21 = F_16 ( V_19 , V_181 ) ;
return F_91 ( V_21 , * V_181 , V_188 , V_189 ) ;
}
const T_7 * F_94 ( const T_8 * V_20 , T_9 V_4 ) {
T_6 * V_197 ;
T_5 V_198 = F_18 ( V_20 , V_4 , & V_197 ) ;
return F_95 ( V_198 , V_197 ) ;
}
const T_7 * F_96 ( const T_8 * V_20 , T_9 V_4 ) {
T_6 * V_197 ;
T_5 V_198 = F_89 ( V_20 , V_4 , & V_197 , FALSE ) ;
return F_85 ( V_197 , V_198 , FALSE ) ;
}
T_5 F_97 ( T_5 V_21 , T_6 * V_5 , T_8 * * V_199 ) {
T_5 V_200 = 0 ;
T_5 V_6 ;
T_6 V_11 ;
T_8 * V_201 ;
if ( ! V_5 || V_21 <= 1 ) {
* V_199 = NULL ;
return 0 ;
}
for ( V_11 = V_5 [ 0 ] * 40 , V_6 = 1 ; V_6 < V_21 ; V_6 ++ , V_11 = 0 ) {
V_11 += V_5 [ V_6 ] ;
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
}
* V_199 = V_201 = ( T_8 * ) F_90 ( V_200 ) ;
for ( V_11 = V_5 [ 0 ] * 40 , V_6 = 1 ; V_6 < V_21 ; V_6 ++ , V_11 = 0 ) {
T_5 T_11 ;
V_11 += V_5 [ V_6 ] ;
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
case 2 : * ( V_201 ++ ) = ( ( V_11 & 0x00003F80 ) >> 7 ) | 0x80 ;
case 1 : * ( V_201 ++ ) = V_11 & 0x0000007F ; break;
}
}
return V_200 ;
}
const T_7 * F_98 ( const T_8 * V_202 , T_5 T_11 ) {
T_6 * V_5 ;
T_5 V_21 = F_18 ( V_202 , T_11 , & V_5 ) ;
if ( V_21 ) {
return F_14 ( V_5 , V_21 ) ;
} else {
return L_15 ;
}
}
const T_7 * F_99 ( const T_8 * V_202 , T_5 T_11 ) {
T_6 * V_5 ;
T_5 V_21 = F_89 ( V_202 , T_11 , & V_5 , FALSE ) ;
if ( V_21 ) {
return F_85 ( V_5 , V_21 , FALSE ) ;
} else {
return L_15 ;
}
}
T_5 F_100 ( const char * V_19 , T_8 * * V_193 ) {
T_6 * V_5 ;
T_6 V_21 ;
T_5 V_194 ;
if ( ( V_21 = F_16 ( V_19 , & V_5 ) )
&&
( V_194 = F_97 ( V_21 , V_5 , V_193 ) ) ) {
return V_194 ;
}
return 0 ;
}
const T_7 * F_101 ( const T_7 * V_19 ) {
T_6 * V_197 ;
T_5 V_198 = F_16 ( V_19 , & V_197 ) ;
return F_95 ( V_198 , V_197 ) ;
}
const T_7 * F_95 ( T_6 V_112 , T_6 * V_5 ) {
T_5 V_188 ;
T_5 V_189 ;
T_1 * V_20 ;
if( ! ( V_5 && * V_5 <= 2 ) )
return L_101 ;
V_20 = F_91 ( V_112 , V_5 , & V_188 , & V_189 ) ;
while ( ! V_20 -> V_1 ) {
if ( ! ( V_20 = V_20 -> V_16 ) ) {
return F_14 ( V_5 , V_112 ) ;
}
V_189 ++ ;
V_188 -- ;
}
if ( V_189 ) {
return F_102 ( L_44 ,
V_20 -> V_1 ? V_20 -> V_1 : F_14 ( V_5 , V_188 ) ,
F_14 ( & ( V_5 [ V_188 ] ) , V_189 ) ) ;
} else {
return V_20 -> V_1 ? V_20 -> V_1 : F_14 ( V_5 , V_188 ) ;
}
}
extern void F_103 ( T_5 V_4 , T_6 * V_5 , char * * V_203 , char * * V_204 ) {
* V_203 = ( char * ) F_95 ( V_4 , V_5 ) ;
* V_204 = ( char * ) F_14 ( V_5 , V_4 ) ;
}
extern void F_104 ( const T_8 * V_20 , T_9 V_4 , char * * V_203 , char * * V_204 ) {
T_6 * V_5 ;
T_5 V_21 = F_18 ( V_20 , V_4 , & V_5 ) ;
* V_203 = ( char * ) F_95 ( V_21 , V_5 ) ;
* V_204 = ( char * ) F_14 ( V_5 , V_21 ) ;
}
extern void F_105 ( const T_7 * V_19 , char * * V_203 , char * * V_204 ) {
T_6 * V_5 ;
T_5 V_21 = F_16 ( V_19 , & V_5 ) ;
* V_203 = ( char * ) F_95 ( V_21 , V_5 ) ;
* V_204 = ( char * ) F_14 ( V_5 , V_21 ) ;
}
extern T_7 *
F_55 ( void ) {
#ifdef F_76
T_26 * V_146 ;
T_7 * V_205 ;
char * V_26 ;
T_5 V_6 ;
V_146 = F_53 ( L_15 ) ;
if ( ! V_147 ) {
F_7 ( 1 , ( L_46 ) ) ;
return V_146 -> V_153 ;
}
#ifdef F_22
#define F_106 ";"
V_26 = F_107 ( L_102 ) ;
F_25 ( V_146 , L_103 , V_26 ) ;
F_29 ( V_26 ) ;
V_26 = F_108 ( L_102 , FALSE ) ;
F_25 ( V_146 , L_104 , V_26 ) ;
F_29 ( V_26 ) ;
#else
#define F_106 ":"
V_26 = F_109 () ;
F_110 ( V_146 , L_105 ) ;
if ( strlen ( V_26 ) > 0 ) {
F_110 ( V_146 , F_106 ) ;
}
F_25 ( V_146 , L_104 , V_26 ) ;
free ( V_26 ) ;
#endif
for( V_6 = 0 ; V_6 < V_177 ; V_6 ++ ) {
if ( ! ( V_176 [ V_6 ] . V_1 && * V_176 [ V_6 ] . V_1 ) )
continue;
F_25 ( V_146 , F_106 L_104 , V_176 [ V_6 ] . V_1 ) ;
}
V_205 = V_146 -> V_153 ;
F_59 ( V_146 , FALSE ) ;
return V_205 ;
#else
return F_27 ( L_15 ) ;
#endif
}
char * F_111 ( T_6 V_112 , T_6 * V_5 ) {
T_8 * V_206 ;
T_8 * V_207 ;
T_6 * V_208 ;
T_6 * V_209 ;
const char * V_210 = F_14 ( V_5 , V_112 ) ;
T_5 V_211 = F_97 ( V_112 , V_5 , & V_206 ) ;
T_5 V_212 = F_18 ( V_206 , V_211 , & V_208 ) ;
const char * V_213 = F_98 ( V_206 , V_211 ) ;
T_5 V_214 = F_100 ( V_210 , & V_207 ) ;
T_5 V_215 = F_16 ( V_210 , & V_209 ) ;
return F_102 (
L_106
L_107
L_108
L_109
L_110
L_111
, V_210
, V_211 , F_19 ( V_206 , V_211 , ':' )
, V_208 ? F_14 ( V_208 , V_212 ) : L_14
, V_213
, V_214 , F_19 ( V_207 , V_214 , ':' )
, V_209 ? F_14 ( V_209 , V_215 ) : L_14
) ;
}
void F_112 ( T_1 * V_216 , T_27 * V_217 ) {
static const char * V_218 [] = { L_112 , L_113 , L_114 , L_115 , L_116 , L_117 , L_118 , L_119 , L_120 , L_121 } ;
static const char * V_219 [] = { L_122 , L_123 ,
L_124 , L_125 , L_126 ,
L_127 , L_128 , L_129 , L_130 } ;
T_28 * V_220 = F_113 ( V_217 , NULL , 0 , 0 ,
L_131 ,
V_216 -> V_1 ? V_216 -> V_1 : L_15 ,
V_216 -> V_11 ,
V_216 -> V_2 <= V_139 ? V_218 [ V_216 -> V_2 ] : L_132 ,
V_216 -> V_15 ) ;
T_27 * V_221 = F_114 ( V_220 , 0 ) ;
T_4 * V_3 ;
for( V_3 = V_216 -> V_3 ; V_3 ; V_3 = V_3 -> V_109 ) {
F_113 ( V_221 , NULL , 0 , 0 ,
L_133 ,
V_3 -> V_1 ,
V_3 -> V_110 <= V_222 ? V_219 [ V_3 -> V_110 ] : L_132
) ;
} ;
if ( V_216 -> V_16 ) {
V_220 = F_113 ( V_221 , NULL , 0 , 0 , L_134 ) ;
V_221 = F_114 ( V_220 , 0 ) ;
F_112 ( V_216 -> V_16 , V_221 ) ;
}
}
