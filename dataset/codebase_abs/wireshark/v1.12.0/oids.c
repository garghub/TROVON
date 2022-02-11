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
F_8 ( 3 , ( L_6 , V_6 ? V_6 : L_7 , F_15 ( V_10 , V_9 ) ) ) ;
F_5 ( V_6 , V_18 , NULL , NULL , V_9 , V_10 ) ;
} else {
F_8 ( 1 , ( L_8 , V_6 ? V_6 : L_7 ) ) ;
}
}
void F_16 ( const char * V_6 , const T_7 * V_19 ) {
T_1 * V_10 ;
T_6 V_9 = F_17 ( NULL , V_19 , & V_10 ) ;
if ( V_9 ) {
F_8 ( 3 , ( L_9 , V_6 ? V_6 : L_7 , F_15 ( V_10 , V_9 ) ) ) ;
F_5 ( V_6 , V_18 , NULL , NULL , V_9 , V_10 ) ;
} else {
F_8 ( 1 , ( L_10 , V_6 ? V_6 : L_7 , V_19 ? V_19 : NULL ) ) ;
}
F_9 ( NULL , V_10 ) ;
}
extern void F_18 ( const char * V_6 , const T_8 * V_20 , T_9 V_9 ) {
T_1 * V_10 ;
T_6 V_21 = F_19 ( V_20 , V_9 , & V_10 ) ;
if ( V_21 ) {
F_8 ( 3 , ( L_11 , V_6 , F_15 ( V_10 , V_21 ) ) ) ;
F_5 ( V_6 , V_18 , NULL , NULL , V_21 , V_10 ) ;
} else {
F_8 ( 1 , ( L_12 , V_6 ? V_6 : L_7 , V_9 , F_20 ( V_20 , V_9 , ':' ) ) ) ;
}
}
static void F_21 ( void * V_22 ) {
#if ( V_23 >= 0 ) && ( V_24 >= 4 ) && ( V_25 >= 8 )
F_22 ( V_22 ) ;
#else
#ifdef F_23
#error Invalid Windows libsmi version ?? !!
#endif
#define F_24 free
F_24 ( V_22 ) ;
#endif
}
static void F_25 ( char * V_26 , int line , int V_27 , char * V_28 , char * V_29 ) {
F_26 ( V_30 , L_13 ,
V_26 ? V_26 : L_14 ,
line , V_27 ,
V_29 ? V_29 : L_14 ,
V_28 ? V_28 : L_15 ) ;
}
static void * F_27 ( void * V_31 , const void * V_32 , T_10 T_11 V_33 ) {
const T_12 * V_34 = ( const T_12 * ) V_32 ;
T_12 * V_35 = ( T_12 * ) V_31 ;
V_35 -> V_6 = F_28 ( V_34 -> V_6 ) ;
return V_35 ;
}
static void F_29 ( void * V_36 ) {
T_12 * V_34 = ( T_12 * ) V_36 ;
F_30 ( V_34 -> V_6 ) ;
}
static char * F_31 ( const char * V_6 ) {
char * V_37 = F_28 ( V_6 ) ;
char * V_38 = V_37 ;
char * V_39 = V_38 ;
char V_12 ;
for (; ( V_12 = * V_38 ) ; V_38 ++ ) {
if ( isalnum ( V_12 ) || V_12 == '_' || V_12 == '-' || V_12 == '.' ) {
* ( V_39 ++ ) = V_12 ;
} else if ( V_12 == ':' && V_38 [ 1 ] == ':' ) {
* ( V_39 ++ ) = '.' ;
}
}
* V_39 = '\0' ;
return V_37 ;
}
static const T_4 * F_32 ( T_13 * V_40 ) {
static const struct V_41 {
const char * V_6 ;
T_14 V_42 ;
const T_4 * type ;
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
char * V_6 = F_33 ( V_72 , V_73 ) ;
if ( V_6 && V_71 -> V_6 && F_7 ( V_6 , V_71 -> V_6 ) ) {
F_21 ( V_6 ) ;
return V_71 -> type ;
}
if ( V_6 ) {
F_21 ( V_6 ) ;
}
}
} while( ( V_72 = F_34 ( V_72 ) ) );
for ( V_71 = V_43 ; V_71 -> type ; V_71 ++ ) {
if( V_40 -> V_74 == V_71 -> V_42 ) {
return V_71 -> type ;
}
}
return & V_70 ;
}
static T_6 F_35 ( T_13 * V_72 ) {
T_15 * V_75 ;
T_6 V_76 = 0xffffffff ;
switch ( V_72 -> V_74 ) {
case V_56 :
case V_58 :
break;
default:
return 0 ;
}
for ( ; V_72 ; V_72 = F_34 ( V_72 ) ) {
for ( V_75 = F_36 ( V_72 ) ; V_75 ; V_75 = F_37 ( V_75 ) ) {
if ( V_76 == 0xffffffff ) {
if ( V_75 -> V_77 . V_78 . V_79 == V_75 -> V_80 . V_78 . V_79 ) {
V_76 = ( T_1 ) V_75 -> V_77 . V_78 . V_79 ;
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
static inline T_3 F_38 ( T_16 * V_81 , T_5 * * V_82 ) {
* V_82 = NULL ;
switch( V_81 -> V_83 ) {
case V_84 : {
T_17 * V_85 ;
T_5 * V_86 = NULL ;
const T_4 * V_87 = NULL ;
T_18 V_88 ;
switch ( V_81 -> V_89 ) {
case V_90 :
break;
case V_91 :
case V_92 :
case V_93 :
case V_94 :
V_81 = F_39 ( V_81 ) ;
break;
case V_95 :
return V_18 ;
} ;
V_88 = V_81 -> V_88 ;
for ( V_85 = F_40 ( V_81 ) ; V_85 ; V_85 = F_41 ( V_85 ) ) {
T_16 * V_96 = F_42 ( V_85 ) ;
T_13 * V_97 = F_43 ( V_96 ) ;
T_5 * V_98 ;
T_6 V_99 = 0 ;
char * V_100 , * V_101 ;
if ( V_97 ) {
V_99 = F_35 ( V_97 ) ;
}
V_87 = F_32 ( V_97 ) ;
V_98 = F_44 ( T_5 , 1 ) ;
V_100 = F_45 ( V_81 -> V_102 , V_81 -> V_20 , V_103 ) ;
V_101 = F_45 ( V_96 -> V_102 , V_96 -> V_20 , V_73 ) ;
V_98 -> V_6 = F_46 ( L_44 , V_100 , V_101 ) ;
F_21 ( V_100 ) ;
F_21 ( V_101 ) ;
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
static void F_47 ( void ) {
}
static void F_48 ( void ) {
if ( V_140 )
F_49 ( L_45 ) ;
}
static void F_50 ( void ) {
T_19 * V_141 ;
T_16 * V_142 ;
T_6 V_11 ;
int V_143 = - 1 ;
T_20 * V_144 ;
T_21 * V_145 ;
T_7 * V_146 ;
if ( ! V_147 ) {
F_8 ( 1 , ( L_46 ) ) ;
return;
}
if ( V_140 ) {
F_8 ( 1 , ( L_47 ) ) ;
return;
} else {
V_140 = TRUE ;
}
V_144 = F_51 ( F_3 () , sizeof( V_148 ) ) ;
V_145 = F_52 ( FALSE , TRUE , sizeof( T_9 * ) ) ;
F_53 ( NULL ) ;
V_30 = F_54 ( L_15 ) ;
F_55 ( F_25 ) ;
V_146 = F_56 () ;
F_8 ( 1 , ( L_48 , V_146 ) ) ;
F_57 ( V_146 ) ;
for( V_11 = 0 ; V_11 < V_149 ; V_11 ++ ) {
if ( ! V_150 [ V_11 ] . V_6 ) continue;
if ( F_58 ( V_150 [ V_11 ] . V_6 ) ) {
continue;
} else {
char * V_151 = F_59 ( V_150 [ V_11 ] . V_6 ) ;
if ( V_151 )
F_8 ( 2 , ( L_49 , V_150 [ V_11 ] . V_6 , V_11 , V_151 ) ) ;
else
F_8 ( 1 , ( L_50 , V_150 [ V_11 ] . V_6 , V_11 ) ) ;
}
}
if ( V_30 -> T_11 ) {
if ( ! V_152 ) {
F_49 ( L_51
L_52
L_53
L_54
L_55 , V_30 -> V_153 , V_146 ) ;
}
F_8 ( 1 , ( L_56 , V_30 -> V_153 ) ) ;
}
F_30 ( V_146 ) ;
F_60 ( V_30 , TRUE ) ;
for ( V_141 = F_61 () ;
V_141 ;
V_141 = F_62 ( V_141 ) ) {
F_8 ( 3 , ( L_57 , V_141 -> V_6 ) ) ;
if ( V_141 -> V_154 == 1 ) {
if ( ! V_152 ) {
F_49 ( L_58
L_59
L_60
L_61 ,
V_141 -> V_6 , V_141 -> V_154 ) ;
}
continue;
}
for ( V_142 = F_63 ( V_141 , V_155 ) ;
V_142 ;
V_142 = F_64 ( V_142 , V_155 ) ) {
T_13 * V_40 = F_43 ( V_142 ) ;
const T_4 * V_87 = F_32 ( V_40 ) ;
T_5 * V_8 ;
T_3 V_7 = F_38 ( V_142 , & V_8 ) ;
char * V_20 = F_45 ( V_142 -> V_102 , V_142 -> V_20 , V_103 ) ;
T_2 * V_156 = F_5 ( V_20 ,
V_7 ,
V_87 ,
V_8 ,
V_142 -> V_102 ,
V_142 -> V_20 ) ;
F_21 ( V_20 ) ;
F_8 ( 4 , ( L_62 ,
V_156 -> V_7 , F_15 ( V_142 -> V_20 , V_142 -> V_102 ) , V_156 -> V_6 ) ) ;
if ( V_87 && V_156 -> V_15 == - 2 ) {
T_22 * V_157 ;
V_148 V_158 ;
V_158 . V_159 = & ( V_156 -> V_15 ) ;
V_158 . V_160 . V_6 = V_156 -> V_6 ;
V_158 . V_160 . V_161 = F_31 ( V_156 -> V_6 ) ;
V_158 . V_160 . type = V_87 -> V_105 ;
V_158 . V_160 . V_107 = V_87 -> V_107 ;
V_158 . V_160 . V_162 = NULL ;
V_158 . V_160 . V_163 = 0 ;
V_158 . V_160 . V_164 = F_45 ( V_142 -> V_102 , V_142 -> V_20 , V_165 ) ;
F_65 ( V_158 ) ;
if ( strcmp ( V_158 . V_160 . V_164 , V_158 . V_160 . V_6 ) == 0 ) {
F_21 ( ( void * ) V_158 . V_160 . V_164 ) ;
V_158 . V_160 . V_164 = NULL ;
}
V_156 -> V_15 = - 1 ;
if ( F_66 ( V_158 . V_160 . type ) && ( V_157 = F_67 ( V_40 ) ) ) {
T_21 * V_166 = F_52 ( TRUE , TRUE , sizeof( V_167 ) ) ;
for(; V_157 ; V_157 = F_68 ( V_157 ) ) {
if ( V_157 -> V_6 ) {
V_167 V_168 ;
V_168 . V_78 = ( T_1 ) V_157 -> V_78 . V_78 . V_169 ;
V_168 . V_170 = F_28 ( V_157 -> V_6 ) ;
F_69 ( V_166 , V_168 ) ;
}
}
V_158 . V_160 . V_162 = V_166 -> V_171 ;
F_70 ( V_166 , FALSE ) ;
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
F_71 ( V_144 , V_158 ) ;
}
if ( ( V_8 = V_156 -> V_8 ) ) {
for(; V_8 ; V_8 = V_8 -> V_109 ) {
V_148 V_158 ;
V_158 . V_159 = & ( V_8 -> V_104 ) ;
V_158 . V_160 . V_6 = V_8 -> V_6 ;
V_158 . V_160 . V_161 = F_31 ( V_8 -> V_6 ) ;
V_158 . V_160 . type = V_8 -> V_105 ;
V_158 . V_160 . V_107 = V_8 -> V_107 ;
V_158 . V_160 . V_162 = NULL ;
V_158 . V_160 . V_163 = 0 ;
V_158 . V_160 . V_164 = NULL ;
F_65 ( V_158 ) ;
F_8 ( 5 , ( L_63 ,
V_8 -> V_6 , V_8 -> V_112 , V_8 -> V_110 ) ) ;
if ( V_8 -> V_104 == - 2 ) {
F_71 ( V_144 , V_158 ) ;
V_8 -> V_104 = - 1 ;
} else {
F_30 ( ( void * ) V_158 . V_160 . V_161 ) ;
}
}
}
}
}
V_143 = F_72 ( L_64 , L_65 , L_66 ) ;
F_73 ( V_143 , ( V_148 * ) F_74 ( V_144 ) , F_75 ( V_144 ) ) ;
F_76 ( ( T_9 * * ) ( void * ) V_145 -> V_171 , V_145 -> T_11 ) ;
F_70 ( V_145 , TRUE ) ;
}
void F_77 ( T_23 * V_172 )
{
#ifdef F_78
static T_24 V_173 [] = {
F_79 ( V_174 , V_6 , L_67 , L_68 ) ,
V_175
} ;
static T_24 V_176 [] = {
F_80 ( V_174 , V_6 , L_69 , L_70 ) ,
V_175
} ;
F_81 ( V_172 , L_71 ,
L_72 ,
L_73 ,
& V_147 ) ;
F_81 ( V_172 , L_74 ,
L_75 ,
L_76 ,
& V_152 ) ;
V_177 = F_82 ( L_77 ,
sizeof( T_12 ) ,
L_78 ,
FALSE ,
( void * * ) & V_178 ,
& V_179 ,
V_180 ,
L_79 ,
F_27 ,
NULL ,
F_29 ,
F_48 ,
V_176 ) ;
F_83 ( V_172 ,
L_78 ,
L_80 ,
L_81
L_82 ,
V_177 ) ;
V_181 = F_82 ( L_83 ,
sizeof( T_12 ) ,
L_84 ,
FALSE ,
( void * * ) & V_150 ,
& V_149 ,
V_180 ,
L_85 ,
F_27 ,
NULL ,
F_29 ,
F_48 ,
V_173 ) ;
F_83 ( V_172 ,
L_84 ,
L_86 ,
L_87
L_82 ,
V_181 ) ;
#else
F_84 ( V_172 , L_88 ,
L_89 ,
L_90 ) ;
F_84 ( V_172 , L_91 ,
L_92 ,
L_90 ) ;
F_84 ( V_172 , L_93 ,
L_94 ,
L_90 ) ;
#endif
}
void F_85 ( void ) {
F_1 () ;
#ifdef F_78
F_50 () ;
#else
F_8 ( 1 , ( L_95 ) ) ;
#endif
}
void F_86 ( void ) {
#ifdef F_78
F_47 () ;
#else
F_8 ( 1 , ( L_95 ) ) ;
#endif
}
const char * F_15 ( T_1 * V_10 , T_6 T_11 ) {
return F_87 ( V_10 , T_11 , TRUE ) ;
}
const char * F_87 ( T_1 * V_10 , T_6 T_11 , T_18 V_182 ) {
char * V_37 , * V_39 ;
if( ! V_10 || T_11 == 0 )
return L_96 ;
V_37 = ( char * ) F_88 ( ( ( T_11 ) * 11 ) + 2 ) ;
V_39 = V_37 ;
if ( ! V_182 )
* V_39 ++ = '.' ;
do {
V_39 += F_89 ( V_39 , 12 , L_97 , * V_10 ++ ) ;
} while( -- T_11 );
if ( V_39 != V_37 ) * ( V_39 - 1 ) = '\0' ; else * ( V_37 ) = '\0' ;
return V_37 ;
}
static T_6 F_90 ( const char * V_153 ) {
const char * V_38 = V_153 ;
char V_12 = '.' ;
T_6 V_13 = 0 ;
F_8 ( 8 , ( L_98 , V_153 ) ) ;
if ( ! V_38 ) return 0 ;
do {
F_8 ( 9 , ( L_99 , * V_38 , V_13 ) ) ;
switch( * V_38 ) {
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
} while( ( V_12 = * V_38 ++ ) );
return V_13 ;
}
T_6 F_17 ( T_25 * V_183 , const char * V_153 , T_1 * * V_184 ) {
const char * V_38 = V_153 ;
T_1 * V_10 ;
T_1 * V_185 ;
T_6 V_13 = F_90 ( V_153 ) ;
T_26 V_4 = 0 ;
F_8 ( 6 , ( L_100 , V_153 ) ) ;
if ( ! V_13 ) {
* V_184 = NULL ;
return 0 ;
}
* V_184 = V_10 = F_91 ( V_183 , T_1 , V_13 ) ;
V_185 = V_10 + V_13 ;
do switch( * V_38 ) {
case '.' :
V_4 = 0 ;
V_10 ++ ;
continue;
case '1' : case '2' : case '3' : case '4' : case '5' :
case '6' : case '7' : case '8' : case '9' : case '0' :
V_4 *= 10 ;
V_4 += * V_38 - '0' ;
if( V_10 >= V_185 || V_4 > 0xffffffff ) {
* V_184 = NULL ;
return 0 ;
}
* ( V_10 ) *= 10 ;
* ( V_10 ) += * V_38 - '0' ;
continue;
case '\0' :
break;
default:
return 0 ;
} while( * V_38 ++ );
return V_13 ;
}
T_6 F_19 ( const T_8 * V_186 , T_9 V_9 , T_1 * * V_184 ) {
return F_92 ( V_186 , V_9 , V_184 , TRUE ) ;
}
T_6 F_92 ( const T_8 * V_186 , T_9 V_9 , T_1 * * V_184 ,
T_18 V_187 ) {
T_9 V_11 ;
T_6 V_13 = V_187 ? 1 : 0 ;
T_1 * V_10 ;
T_1 * V_188 ;
T_26 V_4 = 0 ;
for ( V_11 = 0 ; V_11 < V_9 ; V_11 ++ ) { if ( ! ( V_186 [ V_11 ] & 0x80 ) ) V_13 ++ ; }
* V_184 = V_10 = ( T_1 * ) F_93 ( sizeof( T_1 ) * V_13 ) ;
V_188 = V_10 + V_13 ;
if ( V_187 && V_13 == 1 ) {
* V_10 = 0 ;
return V_13 ;
}
else if ( ! V_187 && V_13 == 0 ) {
return V_13 ;
}
for ( V_11 = 0 ; V_11 < V_9 ; V_11 ++ ) {
T_8 V_189 = V_186 [ V_11 ] ;
V_4 <<= 7 ;
V_4 |= V_189 & 0x7F ;
if ( V_189 & 0x80 ) {
continue;
}
if ( V_187 ) {
T_1 V_190 = 0 ;
if ( V_4 >= 40 ) { V_190 ++ ; V_4 -= 40 ; }
if ( V_4 >= 40 ) { V_190 ++ ; V_4 -= 40 ; }
* V_10 ++ = V_190 ;
V_187 = FALSE ;
}
if( V_10 >= V_188 || V_4 > 0xffffffff ) {
* V_184 = NULL ;
return 0 ;
}
* V_10 ++ = ( T_1 ) V_4 ;
V_4 = 0 ;
}
F_14 ( V_10 == V_188 ) ;
return V_13 ;
}
T_2 * F_94 ( T_6 T_11 , T_1 * V_10 , T_6 * V_191 , T_6 * V_192 ) {
T_2 * V_193 = & V_1 ;
T_6 V_11 ;
if( ! ( V_10 && * V_10 <= 2 ) ) {
* V_191 = 0 ;
* V_192 = T_11 ;
return V_193 ;
}
for( V_11 = 0 ; V_11 < T_11 ; V_11 ++ ) {
T_2 * V_194 = ( T_2 * ) F_6 ( V_193 -> V_2 , V_10 [ V_11 ] ) ;
if ( V_194 ) {
V_193 = V_194 ;
} else {
goto V_195;
}
}
V_195:
* V_191 = V_11 ;
* V_192 = T_11 - V_11 ;
return V_193 ;
}
T_2 * F_95 ( const T_8 * V_196 , T_9 V_197 , T_1 * * V_184 , T_6 * V_198 , T_6 * V_199 ) {
T_6 V_21 = F_19 ( V_196 , V_197 , V_184 ) ;
return F_94 ( V_21 , * V_184 , V_198 , V_199 ) ;
}
T_2 * F_96 ( T_25 * V_183 , const T_7 * V_19 , T_1 * * V_184 , T_6 * V_191 , T_6 * V_192 ) {
T_6 V_21 = F_17 ( V_183 , V_19 , V_184 ) ;
return F_94 ( V_21 , * V_184 , V_191 , V_192 ) ;
}
const T_7 * F_97 ( const T_8 * V_20 , T_9 V_9 ) {
T_1 * V_200 ;
T_6 V_201 = F_19 ( V_20 , V_9 , & V_200 ) ;
return F_98 ( V_201 , V_200 ) ;
}
const T_7 * F_99 ( const T_8 * V_20 , T_9 V_9 ) {
T_1 * V_200 ;
T_6 V_201 = F_92 ( V_20 , V_9 , & V_200 , FALSE ) ;
return F_87 ( V_200 , V_201 , FALSE ) ;
}
T_6 F_100 ( T_6 V_21 , T_1 * V_10 , T_8 * * V_202 ) {
T_6 V_203 = 0 ;
T_6 V_11 ;
T_1 V_4 ;
T_8 * V_204 ;
if ( ! V_10 || V_21 <= 1 ) {
* V_202 = NULL ;
return 0 ;
}
for ( V_4 = V_10 [ 0 ] * 40 , V_11 = 1 ; V_11 < V_21 ; V_11 ++ , V_4 = 0 ) {
V_4 += V_10 [ V_11 ] ;
if ( V_4 <= 0x0000007F ) {
V_203 += 1 ;
} else if ( V_4 <= 0x00003FFF ) {
V_203 += 2 ;
} else if ( V_4 <= 0x001FFFFF ) {
V_203 += 3 ;
} else if ( V_4 <= 0x0FFFFFFF ) {
V_203 += 4 ;
} else {
V_203 += 5 ;
}
}
* V_202 = V_204 = ( T_8 * ) F_93 ( V_203 ) ;
for ( V_4 = V_10 [ 0 ] * 40 , V_11 = 1 ; V_11 < V_21 ; V_11 ++ , V_4 = 0 ) {
T_6 T_11 ;
V_4 += V_10 [ V_11 ] ;
if ( ( V_4 <= 0x0000007F ) ) T_11 = 1 ;
else if ( ( V_4 <= 0x00003FFF ) ) T_11 = 2 ;
else if ( ( V_4 <= 0x001FFFFF ) ) T_11 = 3 ;
else if ( ( V_4 <= 0x0FFFFFFF ) ) T_11 = 4 ;
else T_11 = 5 ;
switch( T_11 ) {
default: * V_202 = NULL ; return 0 ;
case 5 : * ( V_204 ++ ) = ( ( V_4 & 0xF0000000 ) >> 28 ) | 0x80 ;
case 4 : * ( V_204 ++ ) = ( ( V_4 & 0x0FE00000 ) >> 21 ) | 0x80 ;
case 3 : * ( V_204 ++ ) = ( ( V_4 & 0x001FC000 ) >> 14 ) | 0x80 ;
case 2 : * ( V_204 ++ ) = ( ( V_4 & 0x00003F80 ) >> 7 ) | 0x80 ;
case 1 : * ( V_204 ++ ) = V_4 & 0x0000007F ; break;
}
}
return V_203 ;
}
const T_7 * F_101 ( const T_8 * V_205 , T_6 T_11 ) {
T_1 * V_10 ;
T_6 V_21 = F_19 ( V_205 , T_11 , & V_10 ) ;
if ( V_21 ) {
return F_15 ( V_10 , V_21 ) ;
} else {
return L_15 ;
}
}
const T_7 * F_102 ( const T_8 * V_205 , T_6 T_11 ) {
T_1 * V_10 ;
T_6 V_21 = F_92 ( V_205 , T_11 , & V_10 , FALSE ) ;
if ( V_21 ) {
return F_87 ( V_10 , V_21 , FALSE ) ;
} else {
return L_15 ;
}
}
T_6 F_103 ( const char * V_19 , T_8 * * V_196 ) {
T_1 * V_10 ;
T_1 V_21 ;
T_6 V_197 ;
if ( ( V_21 = F_17 ( NULL , V_19 , & V_10 ) ) &&
( V_197 = F_100 ( V_21 , V_10 , V_196 ) ) ) {
F_9 ( NULL , V_10 ) ;
return V_197 ;
}
F_9 ( NULL , V_10 ) ;
return 0 ;
}
const T_7 * F_104 ( const T_7 * V_19 ) {
T_1 * V_200 ;
T_6 V_201 ;
const T_7 * V_206 ;
V_201 = F_17 ( NULL , V_19 , & V_200 ) ;
V_206 = F_98 ( V_201 , V_200 ) ;
F_9 ( NULL , V_200 ) ;
return V_206 ;
}
const T_7 * F_98 ( T_1 V_112 , T_1 * V_10 ) {
T_6 V_191 ;
T_6 V_192 ;
T_2 * V_20 ;
if( ! ( V_10 && * V_10 <= 2 ) )
return L_101 ;
V_20 = F_94 ( V_112 , V_10 , & V_191 , & V_192 ) ;
while ( ! V_20 -> V_6 ) {
if ( ! ( V_20 = V_20 -> V_16 ) ) {
return F_15 ( V_10 , V_112 ) ;
}
V_192 ++ ;
V_191 -- ;
}
if ( V_192 ) {
return F_105 ( L_44 ,
V_20 -> V_6 ? V_20 -> V_6 : F_15 ( V_10 , V_191 ) ,
F_15 ( & ( V_10 [ V_191 ] ) , V_192 ) ) ;
} else {
return V_20 -> V_6 ? V_20 -> V_6 : F_15 ( V_10 , V_191 ) ;
}
}
extern void F_106 ( T_6 V_9 , T_1 * V_10 , const char * * V_207 , const char * * V_208 ) {
* V_207 = F_98 ( V_9 , V_10 ) ;
* V_208 = F_15 ( V_10 , V_9 ) ;
}
extern void F_107 ( const T_8 * V_20 , T_9 V_9 , const char * * V_207 , const char * * V_208 ) {
T_1 * V_10 ;
T_6 V_21 = F_19 ( V_20 , V_9 , & V_10 ) ;
* V_207 = F_98 ( V_21 , V_10 ) ;
* V_208 = F_15 ( V_10 , V_21 ) ;
}
void F_108 ( const T_7 * V_19 , const char * * V_207 , const char * * V_208 ) {
T_1 * V_10 ;
T_6 V_21 ;
V_21 = F_17 ( NULL , V_19 , & V_10 ) ;
* V_207 = F_98 ( V_21 , V_10 ) ;
* V_208 = F_15 ( V_10 , V_21 ) ;
F_9 ( NULL , V_10 ) ;
}
extern T_7 *
F_56 ( void ) {
#ifdef F_78
T_27 * V_146 ;
T_7 * V_209 ;
char * V_26 ;
T_6 V_11 ;
V_146 = F_54 ( L_15 ) ;
if ( ! V_147 ) {
F_8 ( 1 , ( L_46 ) ) ;
return V_146 -> V_153 ;
}
#ifdef F_23
#define F_109 ";"
V_26 = F_110 ( L_102 ) ;
F_26 ( V_146 , L_103 , V_26 ) ;
F_30 ( V_26 ) ;
V_26 = F_111 ( L_102 , FALSE ) ;
F_26 ( V_146 , L_104 , V_26 ) ;
F_30 ( V_26 ) ;
#else
#define F_109 ":"
V_26 = F_112 () ;
F_113 ( V_146 , L_105 ) ;
if ( strlen ( V_26 ) > 0 ) {
F_113 ( V_146 , F_109 ) ;
}
F_26 ( V_146 , L_104 , V_26 ) ;
free ( V_26 ) ;
#endif
for( V_11 = 0 ; V_11 < V_179 ; V_11 ++ ) {
if ( ! ( V_178 [ V_11 ] . V_6 && * V_178 [ V_11 ] . V_6 ) )
continue;
F_26 ( V_146 , F_109 L_104 , V_178 [ V_11 ] . V_6 ) ;
}
V_209 = V_146 -> V_153 ;
F_60 ( V_146 , FALSE ) ;
return V_209 ;
#else
return F_28 ( L_15 ) ;
#endif
}
char * F_114 ( T_1 V_112 , T_1 * V_10 ) {
T_8 * V_210 ;
T_8 * V_211 ;
T_1 * V_212 ;
T_1 * V_213 ;
const char * V_214 = F_15 ( V_10 , V_112 ) ;
T_6 V_215 = F_100 ( V_112 , V_10 , & V_210 ) ;
T_6 V_216 = F_19 ( V_210 , V_215 , & V_212 ) ;
const char * V_217 = F_101 ( V_210 , V_215 ) ;
T_6 V_218 = F_103 ( V_214 , & V_211 ) ;
T_6 V_219 = F_17 ( V_214 , & V_213 ) ;
return F_105 (
L_106
L_107
L_108
L_109
L_110
L_111
, V_214
, V_215 , F_20 ( V_210 , V_215 , ':' )
, V_212 ? F_15 ( V_212 , V_216 ) : L_14
, V_217
, V_218 , F_20 ( V_211 , V_218 , ':' )
, V_213 ? F_15 ( V_213 , V_219 ) : L_14
) ;
}
void F_115 ( T_2 * V_220 , T_28 * V_221 ) {
static const char * V_222 [] = { L_112 , L_113 , L_114 , L_115 , L_116 , L_117 , L_118 , L_119 , L_120 , L_121 } ;
static const char * V_223 [] = { L_122 , L_123 ,
L_124 , L_125 , L_126 ,
L_127 , L_128 , L_129 , L_130 } ;
T_29 * V_224 = F_116 ( V_221 , NULL , 0 , 0 ,
L_131 ,
V_220 -> V_6 ? V_220 -> V_6 : L_15 ,
V_220 -> V_4 ,
V_220 -> V_7 <= V_139 ? V_222 [ V_220 -> V_7 ] : L_132 ,
V_220 -> V_15 ) ;
T_28 * V_225 = F_117 ( V_224 , 0 ) ;
T_5 * V_8 ;
for( V_8 = V_220 -> V_8 ; V_8 ; V_8 = V_8 -> V_109 ) {
F_116 ( V_225 , NULL , 0 , 0 ,
L_133 ,
V_8 -> V_6 ,
V_8 -> V_110 <= V_226 ? V_223 [ V_8 -> V_110 ] : L_132
) ;
} ;
if ( V_220 -> V_16 ) {
V_224 = F_116 ( V_225 , NULL , 0 , 0 , L_134 ) ;
V_225 = F_117 ( V_224 , 0 ) ;
F_115 ( V_220 -> V_16 , V_225 ) ;
}
}
