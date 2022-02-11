static void F_1 ( void ) {
if ( ! V_1 . V_2 ) {
char * V_3 = getenv ( L_1 ) ;
T_1 V_4 ;
V_5 = V_3 ? ( int ) strtoul ( V_3 , NULL , 10 ) : 0 ;
V_1 . V_2 = F_2 ( F_3 () ) ;
V_4 = 0 ; F_4 ( L_2 , 1 , & V_4 ) ;
V_4 = 1 ; F_4 ( L_3 , 1 , & V_4 ) ;
V_4 = 2 ; F_4 ( L_4 , 1 , & V_4 ) ;
}
}
static T_2 * F_5 ( const char * V_6 , T_3 V_7 , const T_4 * type , T_5 * V_8 , T_6 V_9 , T_1 * V_10 ) {
T_6 V_11 = 0 ;
T_2 * V_12 = & V_1 ;
F_1 () ;
V_9 -- ;
do {
T_2 * V_13 = ( T_2 * ) F_6 ( V_12 -> V_2 , V_10 [ V_11 ] ) ;
if( V_13 ) {
if ( V_11 == V_9 ) {
if ( V_13 -> V_6 ) {
if ( ! F_7 ( V_13 -> V_6 , V_6 ) ) {
F_8 ( 2 , ( L_5 , V_13 -> V_6 , V_6 ) ) ;
}
F_9 ( F_3 () , V_13 -> V_6 ) ;
}
V_13 -> V_6 = F_10 ( F_3 () , V_6 ) ;
if ( ! V_13 -> V_14 ) {
V_13 -> V_14 = type ;
}
return V_13 ;
}
} else {
V_13 = F_11 ( F_3 () , T_2 ) ;
V_13 -> V_4 = V_10 [ V_11 ] ;
V_13 -> V_7 = V_7 ;
V_13 -> V_2 = F_2 ( F_3 () ) ;
V_13 -> V_15 = - 2 ;
V_13 -> V_8 = V_8 ;
V_13 -> V_16 = V_12 ;
V_13 -> V_17 = NULL ;
F_12 ( V_12 -> V_2 , V_13 -> V_4 , V_13 ) ;
if ( V_11 == V_9 ) {
V_13 -> V_6 = F_10 ( F_3 () , V_6 ) ;
V_13 -> V_14 = type ;
V_13 -> V_7 = V_7 ;
return V_13 ;
} else {
V_13 -> V_6 = NULL ;
V_13 -> V_14 = NULL ;
V_13 -> V_7 = V_18 ;
}
}
V_12 = V_13 ;
} while( ++ V_11 );
F_13 () ;
return NULL ;
}
void F_4 ( const char * V_6 , T_6 V_9 , T_1 * V_10 ) {
F_14 ( V_10 && * V_10 <= 2 ) ;
if ( V_9 ) {
T_7 * V_19 = F_15 ( NULL , V_10 , V_9 ) ;
F_8 ( 3 , ( L_6 , V_6 ? V_6 : L_7 , V_19 ) ) ;
F_5 ( V_6 , V_18 , NULL , NULL , V_9 , V_10 ) ;
F_9 ( NULL , V_19 ) ;
} else {
F_8 ( 1 , ( L_8 , V_6 ? V_6 : L_7 ) ) ;
}
}
void F_16 ( const char * V_6 , const T_7 * V_20 ) {
T_1 * V_10 ;
T_6 V_9 = F_17 ( NULL , V_20 , & V_10 ) ;
if ( V_9 ) {
T_7 * V_19 = F_15 ( NULL , V_10 , V_9 ) ;
F_8 ( 3 , ( L_9 , V_6 ? V_6 : L_7 , V_19 ) ) ;
F_5 ( V_6 , V_18 , NULL , NULL , V_9 , V_10 ) ;
F_9 ( NULL , V_19 ) ;
} else {
F_8 ( 1 , ( L_10 , V_6 ? V_6 : L_7 , V_20 ? V_20 : NULL ) ) ;
}
F_9 ( NULL , V_10 ) ;
}
extern void F_18 ( const char * V_6 , const T_8 * V_21 , T_9 V_9 ) {
T_1 * V_10 = NULL ;
T_6 V_22 = F_19 ( NULL , V_21 , V_9 , & V_10 ) ;
if ( V_22 ) {
T_7 * V_19 = F_15 ( NULL , V_10 , V_22 ) ;
F_8 ( 3 , ( L_11 , V_6 , V_19 ) ) ;
F_5 ( V_6 , V_18 , NULL , NULL , V_22 , V_10 ) ;
F_9 ( NULL , V_19 ) ;
} else {
T_7 * V_23 = F_20 ( NULL , V_21 , V_9 , ':' ) ;
F_8 ( 1 , ( L_12 , V_6 ? V_6 : L_7 , V_9 , V_23 ) ) ;
F_9 ( NULL , V_23 ) ;
}
F_9 ( NULL , V_10 ) ;
}
static void F_21 ( void * V_24 ) {
#if ( V_25 >= 0 ) && ( V_26 >= 4 ) && ( V_27 >= 8 )
F_22 ( V_24 ) ;
#else
#ifdef F_23
#error Invalid Windows libsmi version ?? !!
#endif
#define F_24 free
F_24 ( V_24 ) ;
#endif
}
static void F_25 ( char * V_28 , int line , int V_29 , char * V_30 , char * V_31 ) {
F_26 ( V_32 , L_13 ,
V_28 ? V_28 : L_14 ,
line , V_29 ,
V_31 ? V_31 : L_14 ,
V_30 ? V_30 : L_15 ) ;
}
static void * F_27 ( void * V_33 , const void * V_34 , T_10 T_11 V_35 ) {
const T_12 * V_36 = ( const T_12 * ) V_34 ;
T_12 * V_37 = ( T_12 * ) V_33 ;
V_37 -> V_6 = F_28 ( V_36 -> V_6 ) ;
return V_37 ;
}
static void F_29 ( void * V_38 ) {
T_12 * V_36 = ( T_12 * ) V_38 ;
F_30 ( V_36 -> V_6 ) ;
}
static char * F_31 ( const char * V_6 ) {
char * V_39 = F_28 ( V_6 ) ;
char * V_40 = V_39 ;
char * V_41 = V_40 ;
char V_12 ;
for (; ( V_12 = * V_40 ) ; V_40 ++ ) {
if ( F_32 ( V_12 ) || V_12 == '_' || V_12 == '-' || V_12 == '.' ) {
* ( V_41 ++ ) = V_12 ;
} else if ( V_12 == ':' && V_40 [ 1 ] == ':' ) {
* ( V_41 ++ ) = '.' ;
}
}
* V_41 = '\0' ;
return V_39 ;
}
static const T_4 * F_33 ( T_13 * V_42 ) {
static const struct V_43 {
const char * V_6 ;
T_14 V_44 ;
const T_4 * type ;
} V_45 [] = {
{ L_16 , V_46 , & V_47 } ,
{ L_17 , V_46 , & V_47 } ,
{ L_18 , V_46 , & V_48 } ,
{ L_19 , V_46 , & V_47 } ,
{ L_20 , V_46 , & V_49 } ,
{ L_21 , V_46 , & V_50 } ,
{ L_22 , V_46 , & V_48 } ,
{ L_23 , V_46 , & V_50 } ,
{ L_24 , V_46 , & V_51 } ,
{ L_25 , V_46 , & V_51 } ,
{ L_26 , V_46 , & V_52 } ,
{ L_27 , V_46 , & V_53 } ,
{ L_28 , V_46 , & V_53 } ,
{ L_29 , V_46 , & V_54 } ,
{ L_30 , V_46 , & V_54 } ,
{ L_31 , V_46 , & V_54 } ,
{ L_32 , V_46 , & V_55 } ,
{ L_33 , V_56 , & V_57 } ,
{ L_34 , V_58 , & V_59 } ,
{ L_35 , V_60 , & V_61 } ,
{ L_36 , V_62 , & V_54 } ,
{ L_37 , V_63 , & V_64 } ,
{ L_38 , V_65 , & V_66 } ,
{ L_39 , V_67 , & V_68 } ,
{ L_40 , V_69 , & V_59 } ,
{ L_41 , V_70 , & V_57 } ,
{ L_42 , V_71 , & V_59 } ,
{ L_43 , V_46 , & V_72 } ,
{ NULL , V_46 , NULL }
} ;
const struct V_43 * V_73 ;
T_13 * V_74 = V_42 ;
if ( ! V_42 ) return NULL ;
do {
for ( V_73 = V_45 ; V_73 -> type ; V_73 ++ ) {
char * V_6 = F_34 ( V_74 , V_75 ) ;
if ( V_6 && V_73 -> V_6 && F_7 ( V_6 , V_73 -> V_6 ) ) {
F_21 ( V_6 ) ;
return V_73 -> type ;
}
if ( V_6 ) {
F_21 ( V_6 ) ;
}
}
} while( ( V_74 = F_35 ( V_74 ) ) );
for ( V_73 = V_45 ; V_73 -> type ; V_73 ++ ) {
if( V_42 -> V_76 == V_73 -> V_44 ) {
return V_73 -> type ;
}
}
return & V_72 ;
}
static T_6 F_36 ( T_13 * V_74 ) {
T_15 * V_77 ;
T_6 V_78 = 0xffffffff ;
switch ( V_74 -> V_76 ) {
case V_58 :
case V_60 :
break;
default:
return 0 ;
}
for ( ; V_74 ; V_74 = F_35 ( V_74 ) ) {
for ( V_77 = F_37 ( V_74 ) ; V_77 ; V_77 = F_38 ( V_77 ) ) {
if ( V_78 == 0xffffffff ) {
if ( V_77 -> V_79 . V_80 . V_81 == V_77 -> V_82 . V_80 . V_81 ) {
V_78 = ( T_1 ) V_77 -> V_79 . V_80 . V_81 ;
} else {
return 0 ;
}
} else {
if ( V_77 -> V_79 . V_80 . V_81 != V_78 || V_77 -> V_82 . V_80 . V_81 != V_78 ) {
return 0 ;
}
}
}
}
return V_78 == 0xffffffff ? 0 : V_78 ;
}
static inline T_3 F_39 ( T_16 * V_83 , T_5 * * V_84 ) {
* V_84 = NULL ;
switch( V_83 -> V_85 ) {
case V_86 : {
T_17 * V_87 ;
T_5 * V_88 = NULL ;
const T_4 * V_89 = NULL ;
T_18 V_90 ;
switch ( V_83 -> V_91 ) {
case V_92 :
break;
case V_93 :
case V_94 :
case V_95 :
case V_96 :
V_83 = F_40 ( V_83 ) ;
break;
case V_97 :
return V_18 ;
} ;
V_90 = V_83 -> V_90 ;
for ( V_87 = F_41 ( V_83 ) ; V_87 ; V_87 = F_42 ( V_87 ) ) {
T_16 * V_98 = F_43 ( V_87 ) ;
T_13 * V_99 = F_44 ( V_98 ) ;
T_5 * V_100 ;
T_6 V_101 = 0 ;
char * V_102 , * V_103 ;
if ( V_99 ) {
V_101 = F_36 ( V_99 ) ;
}
V_89 = F_33 ( V_99 ) ;
V_100 = F_45 ( T_5 , 1 ) ;
V_102 = F_46 ( V_83 -> V_104 , V_83 -> V_21 , V_105 ) ;
V_103 = F_46 ( V_98 -> V_104 , V_98 -> V_21 , V_75 ) ;
V_100 -> V_6 = F_47 ( V_102 , L_44 , V_103 , NULL ) ;
F_21 ( V_102 ) ;
F_21 ( V_103 ) ;
V_100 -> V_106 = - 2 ;
V_100 -> V_107 = V_89 ? V_89 -> V_107 : V_108 ;
V_100 -> V_109 = V_89 ? V_89 -> V_109 : V_110 ;
V_100 -> V_111 = NULL ;
if ( V_89 ) {
V_100 -> V_112 = V_89 -> V_113 ;
V_100 -> V_114 = V_89 -> V_115 ;
} else {
if ( V_99 ) {
switch ( V_99 -> V_76 ) {
case V_71 :
case V_58 : {
V_100 -> V_112 = V_116 ;
V_100 -> V_114 = V_101 ;
break;
}
case V_70 :
case V_60 :
case V_56 :
case V_62 :
case V_117 :
case V_63 :
V_100 -> V_112 = V_118 ;
V_100 -> V_114 = 1 ;
break;
default:
V_100 -> V_112 = V_119 ;
V_100 -> V_114 = 0 ;
break;
}
} else {
V_100 -> V_112 = V_119 ;
V_100 -> V_114 = 0 ;
break;
}
}
if ( ! * V_84 ) * V_84 = V_100 ;
if ( V_88 ) V_88 -> V_111 = V_100 ;
V_88 = V_100 ;
}
if ( V_90 && V_88 ) {
switch ( V_88 -> V_112 ) {
case V_116 : V_88 -> V_112 = V_120 ; break;
case V_121 : V_88 -> V_112 = V_122 ; break;
case V_123 : V_88 -> V_112 = V_124 ; break;
default: break;
}
}
return V_125 ;
}
case V_126 : return V_127 ;
case V_128 : return V_129 ;
case V_130 : return V_131 ;
case V_132 : return V_133 ;
case V_134 : return V_135 ;
case V_136 : return V_137 ;
case V_138 : return V_139 ;
case V_140 : return V_141 ;
default: return V_18 ;
}
}
static void F_48 ( void ) {
}
static void F_49 ( void ) {
if ( V_142 )
F_50 ( L_45 ) ;
}
static void F_51 ( void ) {
T_19 * V_143 ;
T_16 * V_144 ;
T_6 V_11 ;
int V_145 = - 1 ;
T_20 * V_146 ;
T_21 * V_147 ;
T_7 * V_148 ;
if ( ! V_149 ) {
F_8 ( 1 , ( L_46 ) ) ;
return;
}
if ( V_142 ) {
F_8 ( 1 , ( L_47 ) ) ;
return;
} else {
V_142 = TRUE ;
}
V_146 = F_52 ( F_3 () , sizeof( V_150 ) ) ;
V_147 = F_53 ( FALSE , TRUE , sizeof( T_9 * ) ) ;
F_54 ( NULL ) ;
V_32 = F_55 ( L_15 ) ;
F_56 ( F_25 ) ;
V_148 = F_57 () ;
F_8 ( 1 , ( L_48 , V_148 ) ) ;
F_58 ( V_148 ) ;
for( V_11 = 0 ; V_11 < V_151 ; V_11 ++ ) {
if ( ! V_152 [ V_11 ] . V_6 ) continue;
if ( F_59 ( V_152 [ V_11 ] . V_6 ) ) {
continue;
} else {
char * V_153 = F_60 ( V_152 [ V_11 ] . V_6 ) ;
if ( V_153 )
F_8 ( 2 , ( L_49 , V_152 [ V_11 ] . V_6 , V_11 , V_153 ) ) ;
else
F_8 ( 1 , ( L_50 , V_152 [ V_11 ] . V_6 , V_11 ) ) ;
}
}
if ( V_32 -> T_11 ) {
if ( ! V_154 ) {
F_50 ( L_51
L_52
L_53
L_54
L_55 , V_32 -> V_155 , V_148 ) ;
}
F_8 ( 1 , ( L_56 , V_32 -> V_155 ) ) ;
}
F_30 ( V_148 ) ;
F_61 ( V_32 , TRUE ) ;
for ( V_143 = F_62 () ;
V_143 ;
V_143 = F_63 ( V_143 ) ) {
F_8 ( 3 , ( L_57 , V_143 -> V_6 ) ) ;
if ( V_143 -> V_156 == 1 ) {
if ( ! V_154 ) {
F_50 ( L_58
L_59
L_60
L_61 ,
V_143 -> V_6 , V_143 -> V_156 ) ;
}
continue;
}
for ( V_144 = F_64 ( V_143 , V_157 ) ;
V_144 ;
V_144 = F_65 ( V_144 , V_157 ) ) {
T_13 * V_42 = F_44 ( V_144 ) ;
const T_4 * V_89 = F_33 ( V_42 ) ;
T_5 * V_8 ;
T_3 V_7 = F_39 ( V_144 , & V_8 ) ;
char * V_19 ;
char * V_21 = F_46 ( V_144 -> V_104 , V_144 -> V_21 , V_105 ) ;
T_2 * V_158 = F_5 ( V_21 ,
V_7 ,
V_89 ,
V_8 ,
V_144 -> V_104 ,
V_144 -> V_21 ) ;
F_21 ( V_21 ) ;
V_19 = F_15 ( NULL , V_144 -> V_21 , V_144 -> V_104 ) ;
F_8 ( 4 , ( L_62 ,
V_158 -> V_7 , V_19 , V_158 -> V_6 ) ) ;
F_9 ( NULL , V_19 ) ;
if ( V_89 && V_158 -> V_15 == - 2 ) {
T_22 * V_159 ;
V_150 V_160 ;
V_160 . V_161 = & ( V_158 -> V_15 ) ;
V_160 . V_162 . V_6 = F_28 ( V_158 -> V_6 ) ;
V_160 . V_162 . V_163 = F_31 ( V_158 -> V_6 ) ;
V_160 . V_162 . type = V_89 -> V_107 ;
V_160 . V_162 . V_109 = V_89 -> V_109 ;
V_160 . V_162 . V_164 = NULL ;
V_160 . V_162 . V_165 = 0 ;
V_160 . V_162 . V_166 = F_46 ( V_144 -> V_104 , V_144 -> V_21 , V_167 ) ;
F_66 ( V_160 ) ;
if ( strcmp ( V_160 . V_162 . V_166 , V_160 . V_162 . V_6 ) == 0 ) {
F_21 ( ( void * ) V_160 . V_162 . V_166 ) ;
V_160 . V_162 . V_166 = NULL ;
}
V_158 -> V_15 = - 1 ;
if ( F_67 ( V_160 . V_162 . type ) && ( V_159 = F_68 ( V_42 ) ) ) {
T_21 * V_168 = F_53 ( TRUE , TRUE , sizeof( V_169 ) ) ;
for(; V_159 ; V_159 = F_69 ( V_159 ) ) {
if ( V_159 -> V_6 ) {
V_169 V_170 ;
V_170 . V_80 = ( T_1 ) V_159 -> V_80 . V_80 . V_171 ;
V_170 . V_172 = F_28 ( V_159 -> V_6 ) ;
F_70 ( V_168 , V_170 ) ;
}
}
V_160 . V_162 . V_164 = V_168 -> V_173 ;
F_71 ( V_168 , FALSE ) ;
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
hf2.hfinfo.name = g_strconcat("%s:%s",oid_data->name, ":", smiEnum->name, NULL);
hf2.hfinfo.abbrev = g_strconcat(base, ".", ext, NULL);
g_free(base);
g_free(ext);
g_array_append_val(hfa,hf2);
}
#endif
F_72 ( V_146 , V_160 ) ;
}
if ( ( V_8 = V_158 -> V_8 ) ) {
for(; V_8 ; V_8 = V_8 -> V_111 ) {
V_150 V_160 ;
V_160 . V_161 = & ( V_8 -> V_106 ) ;
V_160 . V_162 . V_6 = V_8 -> V_6 ;
V_160 . V_162 . V_163 = F_31 ( V_8 -> V_6 ) ;
V_160 . V_162 . type = V_8 -> V_107 ;
V_160 . V_162 . V_109 = V_8 -> V_109 ;
V_160 . V_162 . V_164 = NULL ;
V_160 . V_162 . V_165 = 0 ;
V_160 . V_162 . V_166 = NULL ;
F_66 ( V_160 ) ;
F_8 ( 5 , ( L_63 ,
V_8 -> V_6 , V_8 -> V_114 , V_8 -> V_112 ) ) ;
if ( V_8 -> V_106 == - 2 ) {
F_72 ( V_146 , V_160 ) ;
V_8 -> V_106 = - 1 ;
} else {
F_30 ( ( void * ) V_160 . V_162 . V_163 ) ;
}
}
}
}
}
V_145 = F_73 ( L_64 , L_65 , L_66 ) ;
F_74 ( V_145 , ( V_150 * ) F_75 ( V_146 ) , F_76 ( V_146 ) ) ;
F_77 ( ( T_9 * * ) ( void * ) V_147 -> V_173 , V_147 -> T_11 ) ;
F_71 ( V_147 , TRUE ) ;
}
void F_78 ( T_23 * V_174 )
{
#ifdef F_79
static T_24 V_175 [] = {
F_80 ( V_176 , V_6 , L_67 , L_68 ) ,
V_177
} ;
static T_24 V_178 [] = {
F_81 ( V_176 , V_6 , L_69 , L_70 ) ,
V_177
} ;
F_82 ( V_174 , L_71 ,
L_72 ,
L_73
L_74
L_75 ,
& V_149 ) ;
F_82 ( V_174 , L_76 ,
L_77 ,
L_78
L_79
L_80 ,
& V_154 ) ;
V_179 = F_83 ( L_81 ,
sizeof( T_12 ) ,
L_82 ,
FALSE ,
( void * * ) & V_180 ,
& V_181 ,
V_182 ,
L_83 ,
F_27 ,
NULL ,
F_29 ,
F_49 ,
NULL ,
V_178 ) ;
F_84 ( V_174 ,
L_82 ,
L_84 ,
L_85
L_86 ,
V_179 ) ;
V_183 = F_83 ( L_87 ,
sizeof( T_12 ) ,
L_88 ,
FALSE ,
( void * * ) & V_152 ,
& V_151 ,
V_182 ,
L_89 ,
F_27 ,
NULL ,
F_29 ,
F_49 ,
NULL ,
V_175 ) ;
F_84 ( V_174 ,
L_88 ,
L_90 ,
L_91
L_86 ,
V_183 ) ;
#else
F_85 ( V_174 , L_92 ,
L_93 ,
L_94 ) ;
F_85 ( V_174 , L_95 ,
L_96 ,
L_94 ) ;
F_85 ( V_174 , L_97 ,
L_98 ,
L_94 ) ;
#endif
}
void F_86 ( void ) {
F_1 () ;
#ifdef F_79
F_51 () ;
#else
F_8 ( 1 , ( L_99 ) ) ;
#endif
}
void F_87 ( void ) {
#ifdef F_79
F_48 () ;
#else
F_8 ( 1 , ( L_99 ) ) ;
#endif
}
char * F_15 ( T_25 * V_184 , T_1 * V_10 , T_6 T_11 ) {
return F_88 ( V_184 , V_10 , T_11 , TRUE ) ;
}
char * F_88 ( T_25 * V_184 , T_1 * V_10 , T_6 T_11 , T_18 V_185 ) {
T_26 * V_20 ;
T_27 V_186 ;
if( ! V_10 || T_11 == 0 )
return F_10 ( V_184 , L_100 ) ;
V_20 = F_89 ( V_184 , L_15 ) ;
if ( ! V_185 )
F_90 ( V_20 , '.' ) ;
do {
F_91 ( V_20 , L_101 , * V_10 ++ ) ;
} while( -- T_11 );
V_186 = F_92 ( V_20 ) ;
F_93 ( V_20 , V_186 - 1 ) ;
return F_94 ( V_20 ) ;
}
static T_6 F_95 ( const char * V_155 ) {
const char * V_40 = V_155 ;
char V_12 = '.' ;
T_6 V_13 = 0 ;
F_8 ( 8 , ( L_102 , V_155 ) ) ;
if ( ! V_40 ) return 0 ;
do {
F_8 ( 9 , ( L_103 , * V_40 , V_13 ) ) ;
switch( * V_40 ) {
case '.' : case '\0' :
V_13 ++ ;
if ( V_12 == '.' ) return 0 ;
break;
case '1' : case '2' : case '3' : case '4' : case '5' :
case '6' : case '7' : case '8' : case '9' : case '0' :
continue;
default:
return 0 ;
}
} while( ( V_12 = * V_40 ++ ) );
return V_13 ;
}
T_6 F_17 ( T_25 * V_184 , const char * V_155 , T_1 * * V_187 ) {
const char * V_40 = V_155 ;
T_1 * V_10 ;
T_1 * V_188 ;
T_6 V_13 = F_95 ( V_155 ) ;
T_28 V_4 = 0 ;
F_8 ( 6 , ( L_104 , V_155 ) ) ;
if ( ! V_13 ) {
* V_187 = NULL ;
return 0 ;
}
* V_187 = V_10 = F_96 ( V_184 , T_1 , V_13 ) ;
V_188 = V_10 + V_13 ;
do switch( * V_40 ) {
case '.' :
V_4 = 0 ;
V_10 ++ ;
continue;
case '1' : case '2' : case '3' : case '4' : case '5' :
case '6' : case '7' : case '8' : case '9' : case '0' :
V_4 *= 10 ;
V_4 += * V_40 - '0' ;
if( V_10 >= V_188 || V_4 > 0xffffffff ) {
* V_187 = NULL ;
return 0 ;
}
* ( V_10 ) *= 10 ;
* ( V_10 ) += * V_40 - '0' ;
continue;
case '\0' :
break;
default:
return 0 ;
} while( * V_40 ++ );
return V_13 ;
}
T_6 F_19 ( T_25 * V_184 , const T_8 * V_189 , T_9 V_9 , T_1 * * V_187 ) {
return F_97 ( V_184 , V_189 , V_9 , V_187 , TRUE ) ;
}
T_6 F_97 ( T_25 * V_184 , const T_8 * V_189 , T_9 V_9 , T_1 * * V_187 ,
T_18 V_190 ) {
T_9 V_11 ;
T_6 V_13 = V_190 ? 1 : 0 ;
T_1 * V_10 ;
T_1 * V_191 ;
T_28 V_4 = 0 ;
for ( V_11 = 0 ; V_11 < V_9 ; V_11 ++ ) { if ( ! ( V_189 [ V_11 ] & 0x80 ) ) V_13 ++ ; }
* V_187 = V_10 = ( T_1 * ) F_98 ( V_184 , sizeof( T_1 ) * V_13 ) ;
V_191 = V_10 + V_13 ;
if ( V_190 && V_13 == 1 ) {
* V_10 = 0 ;
return V_13 ;
}
else if ( ! V_190 && V_13 == 0 ) {
return V_13 ;
}
for ( V_11 = 0 ; V_11 < V_9 ; V_11 ++ ) {
T_8 V_192 = V_189 [ V_11 ] ;
V_4 <<= 7 ;
V_4 |= V_192 & 0x7F ;
if ( V_192 & 0x80 ) {
continue;
}
if ( V_190 ) {
T_1 V_193 = 0 ;
if ( V_4 >= 40 ) { V_193 ++ ; V_4 -= 40 ; }
if ( V_4 >= 40 ) { V_193 ++ ; V_4 -= 40 ; }
* V_10 ++ = V_193 ;
V_190 = FALSE ;
}
if( V_10 >= V_191 || V_4 > 0xffffffff ) {
F_9 ( V_184 , * V_187 ) ;
* V_187 = NULL ;
return 0 ;
}
* V_10 ++ = ( T_1 ) V_4 ;
V_4 = 0 ;
}
F_14 ( V_10 == V_191 ) ;
return V_13 ;
}
T_2 * F_99 ( T_6 T_11 , T_1 * V_10 , T_6 * V_194 , T_6 * V_195 ) {
T_2 * V_196 = & V_1 ;
T_6 V_11 ;
if( ! ( V_10 && * V_10 <= 2 ) ) {
* V_194 = 0 ;
* V_195 = T_11 ;
return V_196 ;
}
for( V_11 = 0 ; V_11 < T_11 ; V_11 ++ ) {
T_2 * V_197 = ( T_2 * ) F_6 ( V_196 -> V_2 , V_10 [ V_11 ] ) ;
if ( V_197 ) {
V_196 = V_197 ;
} else {
goto V_198;
}
}
V_198:
* V_194 = V_11 ;
* V_195 = T_11 - V_11 ;
return V_196 ;
}
T_2 * F_100 ( T_25 * V_184 , const T_8 * V_199 , T_9 V_200 , T_1 * * V_187 , T_6 * V_201 , T_6 * V_202 ) {
T_6 V_22 = F_19 ( V_184 , V_199 , V_200 , V_187 ) ;
return F_99 ( V_22 , * V_187 , V_201 , V_202 ) ;
}
T_2 * F_101 ( T_25 * V_184 , const T_7 * V_20 , T_1 * * V_187 , T_6 * V_194 , T_6 * V_195 ) {
T_6 V_22 = F_17 ( V_184 , V_20 , V_187 ) ;
return F_99 ( V_22 , * V_187 , V_194 , V_195 ) ;
}
T_7 * F_102 ( T_25 * V_184 , const T_8 * V_21 , T_9 V_9 ) {
T_1 * V_203 = NULL ;
T_7 * V_204 ;
T_6 V_205 = F_19 ( NULL , V_21 , V_9 , & V_203 ) ;
V_204 = F_103 ( V_184 , V_205 , V_203 ) ;
F_9 ( NULL , V_203 ) ;
return V_204 ;
}
T_7 * F_104 ( T_25 * V_184 , const T_8 * V_21 , T_9 V_9 ) {
T_1 * V_203 = NULL ;
T_7 * V_204 ;
T_6 V_205 = F_97 ( NULL , V_21 , V_9 , & V_203 , FALSE ) ;
V_204 = F_88 ( V_184 , V_203 , V_205 , FALSE ) ;
F_9 ( NULL , V_203 ) ;
return V_204 ;
}
T_6 F_105 ( T_25 * V_184 , T_6 V_22 , T_1 * V_10 , T_8 * * V_206 ) {
T_6 V_207 = 0 ;
T_6 V_11 ;
T_1 V_4 ;
T_8 * V_208 ;
if ( ! V_10 || V_22 <= 1 ) {
* V_206 = NULL ;
return 0 ;
}
for ( V_4 = V_10 [ 0 ] * 40 , V_11 = 1 ; V_11 < V_22 ; V_11 ++ , V_4 = 0 ) {
V_4 += V_10 [ V_11 ] ;
if ( V_4 <= 0x0000007F ) {
V_207 += 1 ;
} else if ( V_4 <= 0x00003FFF ) {
V_207 += 2 ;
} else if ( V_4 <= 0x001FFFFF ) {
V_207 += 3 ;
} else if ( V_4 <= 0x0FFFFFFF ) {
V_207 += 4 ;
} else {
V_207 += 5 ;
}
}
* V_206 = V_208 = ( T_8 * ) F_98 ( V_184 , V_207 ) ;
for ( V_4 = V_10 [ 0 ] * 40 , V_11 = 1 ; V_11 < V_22 ; V_11 ++ , V_4 = 0 ) {
T_6 T_11 ;
V_4 += V_10 [ V_11 ] ;
if ( ( V_4 <= 0x0000007F ) ) T_11 = 1 ;
else if ( ( V_4 <= 0x00003FFF ) ) T_11 = 2 ;
else if ( ( V_4 <= 0x001FFFFF ) ) T_11 = 3 ;
else if ( ( V_4 <= 0x0FFFFFFF ) ) T_11 = 4 ;
else T_11 = 5 ;
switch( T_11 ) {
default: * V_206 = NULL ; return 0 ;
case 5 : * ( V_208 ++ ) = ( ( V_4 & 0xF0000000 ) >> 28 ) | 0x80 ;
case 4 : * ( V_208 ++ ) = ( ( V_4 & 0x0FE00000 ) >> 21 ) | 0x80 ;
case 3 : * ( V_208 ++ ) = ( ( V_4 & 0x001FC000 ) >> 14 ) | 0x80 ;
case 2 : * ( V_208 ++ ) = ( ( V_4 & 0x00003F80 ) >> 7 ) | 0x80 ;
case 1 : * ( V_208 ++ ) = V_4 & 0x0000007F ; break;
}
}
return V_207 ;
}
T_7 * F_106 ( T_25 * V_184 , const T_8 * V_209 , T_6 T_11 ) {
T_1 * V_10 = NULL ;
T_7 * V_204 ;
T_6 V_22 = F_19 ( NULL , V_209 , T_11 , & V_10 ) ;
if ( V_22 ) {
V_204 = F_15 ( V_184 , V_10 , V_22 ) ;
} else {
V_204 = F_10 ( V_184 , L_15 ) ;
}
F_9 ( NULL , V_10 ) ;
return V_204 ;
}
T_7 * F_107 ( T_25 * V_184 , const T_8 * V_209 , T_6 T_11 ) {
T_1 * V_10 = NULL ;
T_7 * V_204 ;
T_6 V_22 = F_97 ( NULL , V_209 , T_11 , & V_10 , FALSE ) ;
if ( V_22 ) {
V_204 = F_88 ( V_184 , V_10 , V_22 , FALSE ) ;
} else {
V_204 = F_10 ( V_184 , L_15 ) ;
}
F_9 ( NULL , V_10 ) ;
return V_204 ;
}
T_6 F_108 ( T_25 * V_184 , const char * V_20 , T_8 * * V_199 ) {
T_1 * V_10 ;
T_1 V_22 ;
T_6 V_200 ;
if ( ( V_22 = F_17 ( NULL , V_20 , & V_10 ) ) &&
( V_200 = F_105 ( V_184 , V_22 , V_10 , V_199 ) ) ) {
F_9 ( NULL , V_10 ) ;
return V_200 ;
}
F_9 ( NULL , V_10 ) ;
return 0 ;
}
T_7 * F_109 ( T_25 * V_184 , const T_7 * V_20 ) {
T_1 * V_203 ;
T_6 V_205 ;
T_7 * V_210 ;
V_205 = F_17 ( NULL , V_20 , & V_203 ) ;
V_210 = F_103 ( V_184 , V_205 , V_203 ) ;
F_9 ( NULL , V_203 ) ;
return V_210 ;
}
T_7 * F_103 ( T_25 * V_184 , T_1 V_114 , T_1 * V_10 ) {
T_6 V_194 ;
T_6 V_195 ;
T_2 * V_21 ;
if( ! ( V_10 && * V_10 <= 2 ) )
return F_10 ( V_184 , L_105 ) ;
V_21 = F_99 ( V_114 , V_10 , & V_194 , & V_195 ) ;
while ( ! V_21 -> V_6 ) {
if ( ! ( V_21 = V_21 -> V_16 ) ) {
return F_15 ( V_184 , V_10 , V_114 ) ;
}
V_195 ++ ;
V_194 -- ;
}
if ( V_195 ) {
T_7 * V_204 ,
* V_211 = F_15 ( NULL , V_10 , V_194 ) ,
* V_212 = F_15 ( NULL , & ( V_10 [ V_194 ] ) , V_195 ) ;
V_204 = F_110 ( V_184 , V_21 -> V_6 ? V_21 -> V_6 : V_211 , L_44 , V_212 , NULL ) ;
F_9 ( NULL , V_211 ) ;
F_9 ( NULL , V_212 ) ;
return V_204 ;
} else {
return V_21 -> V_6 ? F_10 ( V_184 , V_21 -> V_6 ) : F_15 ( V_184 , V_10 , V_194 ) ;
}
}
extern void F_111 ( T_25 * V_184 , T_6 V_9 , T_1 * V_10 , T_7 * * V_213 , T_7 * * V_214 ) {
* V_213 = F_103 ( V_184 , V_9 , V_10 ) ;
* V_214 = F_15 ( V_184 , V_10 , V_9 ) ;
}
extern void F_112 ( T_25 * V_184 , const T_8 * V_21 , T_9 V_9 , T_7 * * V_213 , T_7 * * V_214 ) {
T_1 * V_10 = NULL ;
T_6 V_22 = F_19 ( NULL , V_21 , V_9 , & V_10 ) ;
* V_213 = F_103 ( V_184 , V_22 , V_10 ) ;
* V_214 = F_15 ( V_184 , V_10 , V_22 ) ;
F_9 ( NULL , V_10 ) ;
}
void F_113 ( T_25 * V_184 , const T_7 * V_20 , T_7 * * V_213 , T_7 * * V_214 ) {
T_1 * V_10 ;
T_6 V_22 ;
V_22 = F_17 ( NULL , V_20 , & V_10 ) ;
* V_213 = F_103 ( V_184 , V_22 , V_10 ) ;
* V_214 = F_15 ( V_184 , V_10 , V_22 ) ;
F_9 ( NULL , V_10 ) ;
}
extern T_7 *
F_57 ( void ) {
#ifdef F_79
T_29 * V_148 ;
char * V_28 ;
T_6 V_11 ;
V_148 = F_55 ( L_15 ) ;
if ( ! V_149 ) {
F_8 ( 1 , ( L_46 ) ) ;
return V_148 -> V_155 ;
}
#ifdef F_23
#define F_114 ";"
V_28 = F_115 ( L_106 ) ;
F_26 ( V_148 , L_107 , V_28 ) ;
F_30 ( V_28 ) ;
V_28 = F_116 ( L_106 , FALSE ) ;
F_26 ( V_148 , L_108 , V_28 ) ;
F_30 ( V_28 ) ;
#else
#define F_114 ":"
V_28 = F_117 () ;
F_118 ( V_148 , L_109 ) ;
if ( strlen ( V_28 ) > 0 ) {
F_118 ( V_148 , F_114 ) ;
}
F_26 ( V_148 , L_108 , V_28 ) ;
F_21 ( V_28 ) ;
#endif
for( V_11 = 0 ; V_11 < V_181 ; V_11 ++ ) {
if ( ! ( V_180 [ V_11 ] . V_6 && * V_180 [ V_11 ] . V_6 ) )
continue;
F_26 ( V_148 , F_114 L_108 , V_180 [ V_11 ] . V_6 ) ;
}
return F_61 ( V_148 , FALSE ) ;
#else
return F_28 ( L_15 ) ;
#endif
}
char * F_119 ( T_1 V_114 , T_1 * V_10 ) {
T_8 * V_215 = NULL ;
T_8 * V_216 = NULL ;
T_1 * V_217 = NULL ;
T_1 * V_218 ;
char * V_204 ;
char * V_219 = F_15 ( NULL , V_10 , V_114 ) ;
T_6 V_220 = F_105 ( NULL , V_114 , V_10 , & V_215 ) ;
T_6 V_221 = F_19 ( NULL , V_215 , V_220 , & V_217 ) ;
char * V_222 = F_106 ( NULL , V_215 , V_220 ) ;
T_6 V_223 = F_108 ( NULL , V_219 , & V_216 ) ;
T_6 V_224 = F_17 ( V_219 , & V_218 ) ;
V_204 = F_120 ( F_121 () ,
L_110
L_111
L_112
L_113
L_114
L_115
, V_219
, V_220 , F_20 ( F_121 () , V_215 , V_220 , ':' )
, V_217 ? F_15 ( F_121 () , V_217 , V_221 ) : L_14
, V_222
, V_223 , F_20 ( F_121 () , V_216 , V_223 , ':' )
, V_218 ? F_15 ( F_121 () , V_218 , V_224 ) : L_14
) ;
F_9 ( NULL , V_219 ) ;
F_9 ( NULL , V_217 ) ;
F_9 ( NULL , V_215 ) ;
F_9 ( NULL , V_216 ) ;
F_9 ( NULL , V_222 ) ;
return V_204 ;
}
void F_122 ( T_2 * V_225 , T_30 * V_226 ) {
static const char * V_227 [] = { L_116 , L_117 , L_118 , L_119 , L_120 , L_121 , L_122 , L_123 , L_124 , L_125 } ;
static const char * V_228 [] = { L_126 , L_127 ,
L_128 , L_129 , L_130 ,
L_131 , L_132 , L_133 , L_134 } ;
T_31 * V_229 = F_123 ( V_226 , NULL , 0 , 0 ,
L_135 ,
V_225 -> V_6 ? V_225 -> V_6 : L_15 ,
V_225 -> V_4 ,
V_225 -> V_7 <= V_141 ? V_227 [ V_225 -> V_7 ] : L_136 ,
V_225 -> V_15 ) ;
T_30 * V_230 = F_124 ( V_229 , 0 ) ;
T_5 * V_8 ;
for( V_8 = V_225 -> V_8 ; V_8 ; V_8 = V_8 -> V_111 ) {
F_123 ( V_230 , NULL , 0 , 0 ,
L_137 ,
V_8 -> V_6 ,
V_8 -> V_112 <= V_231 ? V_228 [ V_8 -> V_112 ] : L_136
) ;
} ;
if ( V_225 -> V_16 ) {
V_229 = F_123 ( V_230 , NULL , 0 , 0 , L_138 ) ;
V_230 = F_124 ( V_229 , 0 ) ;
F_122 ( V_225 -> V_16 , V_230 ) ;
}
}
