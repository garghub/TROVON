static T_1 * F_1 ( const char * V_1 , T_2 V_2 , const T_3 * type , T_4 * V_3 , T_5 V_4 , T_6 * V_5 ) {
T_5 V_6 = 0 ;
T_1 * V_7 = & V_8 ;
if ( ! V_8 . V_9 ) {
char * V_10 = getenv ( L_1 ) ;
T_6 V_11 ;
V_12 = V_10 ? ( int ) strtoul ( V_10 , NULL , 10 ) : 0 ;
V_8 . V_9 = F_2 ( V_13 , L_2 ) ;
V_11 = 0 ; F_3 ( L_3 , 1 , & V_11 ) ;
V_11 = 1 ; F_3 ( L_4 , 1 , & V_11 ) ;
V_11 = 2 ; F_3 ( L_5 , 1 , & V_11 ) ;
}
V_4 -- ;
do {
T_1 * V_14 = ( T_1 * ) F_4 ( ( V_15 * ) V_7 -> V_9 , V_5 [ V_6 ] ) ;
if( V_14 ) {
if ( V_6 == V_4 ) {
if ( V_14 -> V_1 ) {
if ( ! F_5 ( V_14 -> V_1 , V_1 ) ) {
F_6 ( 2 , ( L_6 , V_14 -> V_1 , V_1 ) ) ;
}
F_7 ( V_14 -> V_1 ) ;
}
V_14 -> V_1 = F_8 ( V_1 ) ;
if ( ! V_14 -> V_16 ) {
V_14 -> V_16 = type ;
}
return V_14 ;
}
} else {
V_14 = ( T_1 * ) F_9 ( sizeof( T_1 ) ) ;
V_14 -> V_11 = V_5 [ V_6 ] ;
V_14 -> V_2 = V_2 ;
V_14 -> V_9 = F_2 ( V_13 , L_7 ) ;
V_14 -> V_17 = - 2 ;
V_14 -> V_3 = V_3 ;
V_14 -> V_18 = V_7 ;
V_14 -> V_19 = NULL ;
F_10 ( ( V_15 * ) V_7 -> V_9 , V_14 -> V_11 , V_14 ) ;
if ( V_6 == V_4 ) {
V_14 -> V_1 = F_8 ( V_1 ) ;
V_14 -> V_16 = type ;
V_14 -> V_2 = V_2 ;
return V_14 ;
} else {
V_14 -> V_1 = NULL ;
V_14 -> V_16 = NULL ;
V_14 -> V_2 = V_20 ;
}
}
V_7 = V_14 ;
} while( ++ V_6 );
F_11 () ;
return NULL ;
}
void F_3 ( const char * V_1 , T_5 V_4 , T_6 * V_5 ) {
F_12 ( V_5 && * V_5 <= 2 ) ;
if ( V_4 ) {
F_6 ( 3 , ( L_8 , V_1 ? V_1 : L_9 , F_13 ( V_5 , V_4 ) ) ) ;
F_1 ( V_1 , V_20 , NULL , NULL , V_4 , V_5 ) ;
} else {
F_6 ( 1 , ( L_10 , V_1 ? V_1 : L_9 ) ) ;
}
}
void F_14 ( const char * V_1 , const T_7 * V_21 ) {
T_6 * V_5 ;
T_5 V_4 = F_15 ( V_21 , & V_5 ) ;
if ( V_4 ) {
F_6 ( 3 , ( L_11 , V_1 ? V_1 : L_9 , F_13 ( V_5 , V_4 ) ) ) ;
F_1 ( V_1 , V_20 , NULL , NULL , V_4 , V_5 ) ;
} else {
F_6 ( 1 , ( L_12 , V_1 ? V_1 : L_9 , V_21 ? V_21 : NULL ) ) ;
}
}
extern void F_16 ( const char * V_1 , const T_8 * V_22 , T_9 V_4 ) {
T_6 * V_5 ;
T_5 V_23 = F_17 ( V_22 , V_4 , & V_5 ) ;
if ( V_23 ) {
F_6 ( 3 , ( L_13 , V_1 , F_13 ( V_5 , V_23 ) ) ) ;
F_1 ( V_1 , V_20 , NULL , NULL , V_23 , V_5 ) ;
} else {
F_6 ( 1 , ( L_14 , V_1 ? V_1 : L_9 , V_4 , F_18 ( V_22 , V_4 , ':' ) ) ) ;
}
}
static void F_19 ( void * V_24 ) {
#if ( V_25 >= 0 ) && ( V_26 >= 4 ) && ( V_27 >= 8 )
F_20 ( V_24 ) ;
#else
#ifdef F_21
#error Invalid Windows libsmi version ?? !!
#endif
#define F_22 free
F_22 ( V_24 ) ;
#endif
}
static void F_23 ( char * V_28 , int line , int V_29 , char * V_30 , char * V_31 ) {
F_24 ( V_32 , L_15 ,
V_28 ? V_28 : L_16 ,
line , V_29 ,
V_31 ? V_31 : L_16 ,
V_30 ? V_30 : L_17 ) ;
}
static void * F_25 ( void * V_33 , const void * V_34 , T_10 T_11 V_35 ) {
const T_12 * V_36 = ( const T_12 * ) V_34 ;
T_12 * V_37 = ( T_12 * ) V_33 ;
V_37 -> V_1 = F_8 ( V_36 -> V_1 ) ;
return V_37 ;
}
static void F_26 ( void * V_38 ) {
T_12 * V_36 = ( T_12 * ) V_38 ;
F_7 ( V_36 -> V_1 ) ;
}
static char * F_27 ( const char * V_1 ) {
char * V_39 = F_8 ( V_1 ) ;
char * V_40 = V_39 ;
char * V_41 = V_40 ;
char V_7 ;
for (; ( V_7 = * V_40 ) ; V_40 ++ ) {
if ( isalnum ( V_7 ) || V_7 == '_' || V_7 == '-' || V_7 == '.' ) {
* ( V_41 ++ ) = V_7 ;
} else if ( V_7 == ':' && V_40 [ 1 ] == ':' ) {
* ( V_41 ++ ) = '.' ;
}
}
* V_41 = '\0' ;
return V_39 ;
}
static const T_3 * F_28 ( T_13 * V_42 ) {
static const struct V_43 {
const char * V_1 ;
T_14 V_44 ;
const T_3 * type ;
} V_45 [] = {
{ L_18 , V_46 , & V_47 } ,
{ L_19 , V_46 , & V_47 } ,
{ L_20 , V_46 , & V_48 } ,
{ L_21 , V_46 , & V_47 } ,
{ L_22 , V_46 , & V_49 } ,
{ L_23 , V_46 , & V_50 } ,
{ L_24 , V_46 , & V_48 } ,
{ L_25 , V_46 , & V_50 } ,
{ L_26 , V_46 , & V_51 } ,
{ L_27 , V_46 , & V_51 } ,
{ L_28 , V_46 , & V_51 } ,
{ L_29 , V_46 , & V_52 } ,
{ L_30 , V_46 , & V_52 } ,
{ L_31 , V_46 , & V_53 } ,
{ L_32 , V_46 , & V_53 } ,
{ L_33 , V_46 , & V_53 } ,
{ L_34 , V_46 , & V_54 } ,
{ L_35 , V_55 , & V_56 } ,
{ L_36 , V_57 , & V_58 } ,
{ L_37 , V_59 , & V_60 } ,
{ L_38 , V_61 , & V_53 } ,
{ L_39 , V_62 , & V_63 } ,
{ L_40 , V_64 , & V_65 } ,
{ L_41 , V_66 , & V_67 } ,
{ L_42 , V_68 , & V_58 } ,
{ L_43 , V_69 , & V_56 } ,
{ L_44 , V_70 , & V_58 } ,
{ L_45 , V_46 , & V_71 } ,
{ NULL , V_46 , NULL }
} ;
const struct V_43 * V_72 ;
T_13 * V_73 = V_42 ;
if ( ! V_42 ) return NULL ;
do {
for ( V_72 = V_45 ; V_72 -> type ; V_72 ++ ) {
char * V_1 = F_29 ( V_73 , V_74 ) ;
if ( V_1 && V_72 -> V_1 && F_5 ( V_1 , V_72 -> V_1 ) ) {
F_19 ( V_1 ) ;
return V_72 -> type ;
}
if ( V_1 ) {
F_19 ( V_1 ) ;
}
}
} while( ( V_73 = F_30 ( V_73 ) ) );
for ( V_72 = V_45 ; V_72 -> type ; V_72 ++ ) {
if( V_42 -> V_75 == V_72 -> V_44 ) {
return V_72 -> type ;
}
}
return & V_71 ;
}
static T_5 F_31 ( T_13 * V_73 ) {
T_15 * V_76 ;
T_5 V_77 = 0xffffffff ;
switch ( V_73 -> V_75 ) {
case V_57 :
case V_59 :
break;
default:
return 0 ;
}
for ( ; V_73 ; V_73 = F_30 ( V_73 ) ) {
for ( V_76 = F_32 ( V_73 ) ; V_76 ; V_76 = F_33 ( V_76 ) ) {
if ( V_77 == 0xffffffff ) {
if ( V_76 -> V_78 . V_79 . V_80 == V_76 -> V_81 . V_79 . V_80 ) {
V_77 = ( T_6 ) V_76 -> V_78 . V_79 . V_80 ;
} else {
return 0 ;
}
} else {
if ( V_76 -> V_78 . V_79 . V_80 != V_77 || V_76 -> V_81 . V_79 . V_80 != V_77 ) {
return 0 ;
}
}
}
}
return V_77 == 0xffffffff ? 0 : V_77 ;
}
static inline T_2 F_34 ( T_16 * V_82 , T_4 * * V_83 ) {
* V_83 = NULL ;
switch( V_82 -> V_84 ) {
case V_85 : {
T_17 * V_86 ;
T_4 * V_87 = NULL ;
const T_3 * V_88 = NULL ;
T_18 V_89 ;
switch ( V_82 -> V_90 ) {
case V_91 :
break;
case V_92 :
case V_93 :
case V_94 :
case V_95 :
V_82 = F_35 ( V_82 ) ;
break;
case V_96 :
return V_20 ;
} ;
V_89 = V_82 -> V_89 ;
for ( V_86 = F_36 ( V_82 ) ; V_86 ; V_86 = F_37 ( V_86 ) ) {
T_16 * V_97 = F_38 ( V_86 ) ;
T_13 * V_98 = F_39 ( V_97 ) ;
T_4 * V_99 ;
T_5 V_100 = 0 ;
char * V_101 , * V_102 ;
if ( V_98 ) {
V_100 = F_31 ( V_98 ) ;
}
V_88 = F_28 ( V_98 ) ;
V_99 = F_40 ( T_4 , 1 ) ;
V_101 = F_41 ( V_82 -> V_103 , V_82 -> V_22 , V_104 ) ;
V_102 = F_41 ( V_97 -> V_103 , V_97 -> V_22 , V_74 ) ;
V_99 -> V_1 = F_42 ( L_46 , V_101 , V_102 ) ;
F_19 ( V_101 ) ;
F_19 ( V_102 ) ;
V_99 -> V_105 = - 2 ;
V_99 -> V_106 = V_88 ? V_88 -> V_106 : V_107 ;
V_99 -> V_108 = V_88 ? V_88 -> V_108 : V_109 ;
V_99 -> V_110 = NULL ;
if ( V_88 ) {
V_99 -> V_111 = V_88 -> V_112 ;
V_99 -> V_113 = V_88 -> V_114 ;
} else {
if ( V_98 ) {
switch ( V_98 -> V_75 ) {
case V_70 :
case V_57 : {
V_99 -> V_111 = V_115 ;
V_99 -> V_113 = V_100 ;
break;
}
case V_69 :
case V_59 :
case V_55 :
case V_61 :
case V_116 :
case V_62 :
V_99 -> V_111 = V_117 ;
V_99 -> V_113 = 1 ;
break;
default:
V_99 -> V_111 = V_118 ;
V_99 -> V_113 = 0 ;
break;
}
} else {
V_99 -> V_111 = V_118 ;
V_99 -> V_113 = 0 ;
break;
}
}
if ( ! * V_83 ) * V_83 = V_99 ;
if ( V_87 ) V_87 -> V_110 = V_99 ;
V_87 = V_99 ;
}
if ( V_89 && V_87 ) {
switch ( V_87 -> V_111 ) {
case V_115 : V_87 -> V_111 = V_119 ; break;
case V_120 : V_87 -> V_111 = V_121 ; break;
case V_122 : V_87 -> V_111 = V_123 ; break;
default: break;
}
}
return V_124 ;
}
case V_125 : return V_126 ;
case V_127 : return V_128 ;
case V_129 : return V_130 ;
case V_131 : return V_132 ;
case V_133 : return V_134 ;
case V_135 : return V_136 ;
case V_137 : return V_138 ;
case V_139 : return V_140 ;
default: return V_20 ;
}
}
static void F_43 ( void ) {
}
static void F_44 ( void ) {
if ( V_141 )
F_45 ( L_47 ) ;
}
static void F_46 ( void ) {
T_19 * V_142 ;
T_16 * V_143 ;
T_5 V_6 ;
int V_144 = - 1 ;
T_20 * V_145 = F_47 ( FALSE , TRUE , sizeof( V_146 ) ) ;
T_20 * V_147 = F_47 ( FALSE , TRUE , sizeof( T_9 * ) ) ;
T_7 * V_148 ;
if ( ! V_149 ) {
F_6 ( 1 , ( L_48 ) ) ;
return;
}
if ( V_141 ) {
F_6 ( 1 , ( L_49 ) ) ;
return;
} else {
V_141 = TRUE ;
}
F_48 ( NULL ) ;
V_32 = F_49 ( L_17 ) ;
F_50 ( F_23 ) ;
V_148 = F_51 () ;
F_6 ( 1 , ( L_50 , V_148 ) ) ;
F_52 ( V_148 ) ;
for( V_6 = 0 ; V_6 < V_150 ; V_6 ++ ) {
if ( ! V_151 [ V_6 ] . V_1 ) continue;
if ( F_53 ( V_151 [ V_6 ] . V_1 ) ) {
continue;
} else {
char * V_152 = F_54 ( V_151 [ V_6 ] . V_1 ) ;
if ( V_152 )
F_6 ( 2 , ( L_51 , V_151 [ V_6 ] . V_1 , V_6 , V_152 ) ) ;
else
F_6 ( 1 , ( L_52 , V_151 [ V_6 ] . V_1 , V_6 ) ) ;
}
}
if ( V_32 -> T_11 ) {
if ( ! V_153 ) {
F_45 ( L_53
L_54
L_55
L_56
L_57 , V_32 -> V_154 , V_148 ) ;
}
F_6 ( 1 , ( L_58 , V_32 -> V_154 ) ) ;
}
F_7 ( V_148 ) ;
F_55 ( V_32 , TRUE ) ;
for ( V_142 = F_56 () ;
V_142 ;
V_142 = F_57 ( V_142 ) ) {
F_6 ( 3 , ( L_59 , V_142 -> V_1 ) ) ;
if ( V_142 -> V_155 == 1 ) {
if ( ! V_153 ) {
F_45 ( L_60
L_61
L_62
L_63 ,
V_142 -> V_1 , V_142 -> V_155 ) ;
}
continue;
}
for ( V_143 = F_58 ( V_142 , V_156 ) ;
V_143 ;
V_143 = F_59 ( V_143 , V_156 ) ) {
T_13 * V_42 = F_39 ( V_143 ) ;
const T_3 * V_88 = F_28 ( V_42 ) ;
T_4 * V_3 ;
T_2 V_2 = F_34 ( V_143 , & V_3 ) ;
char * V_22 = F_41 ( V_143 -> V_103 , V_143 -> V_22 , V_104 ) ;
T_1 * V_157 = F_1 ( V_22 ,
V_2 ,
V_88 ,
V_3 ,
V_143 -> V_103 ,
V_143 -> V_22 ) ;
F_19 ( V_22 ) ;
F_6 ( 4 , ( L_64 ,
V_157 -> V_2 , F_13 ( V_143 -> V_22 , V_143 -> V_103 ) , V_157 -> V_1 ) ) ;
if ( V_88 && V_157 -> V_17 == - 2 ) {
T_21 * V_158 ;
V_146 V_159 = { & ( V_157 -> V_17 ) , {
V_157 -> V_1 ,
F_27 ( V_157 -> V_1 ) ,
V_88 -> V_106 ,
V_88 -> V_108 ,
NULL ,
0 ,
F_41 ( V_143 -> V_103 , V_143 -> V_22 , V_160 ) ,
V_161 } } ;
if ( strcmp ( V_159 . V_162 . V_163 , V_159 . V_162 . V_1 ) == 0 ) {
F_19 ( ( void * ) V_159 . V_162 . V_163 ) ;
V_159 . V_162 . V_163 = NULL ;
}
V_157 -> V_17 = - 1 ;
if ( F_60 ( V_159 . V_162 . type ) && ( V_158 = F_61 ( V_42 ) ) ) {
T_20 * V_164 = F_47 ( TRUE , TRUE , sizeof( V_165 ) ) ;
for(; V_158 ; V_158 = F_62 ( V_158 ) ) {
if ( V_158 -> V_1 ) {
V_165 V_166 = { ( T_6 ) V_158 -> V_79 . V_79 . V_167 , F_8 (smiEnum->name) } ;
F_63 ( V_164 , V_166 ) ;
}
}
V_159 . V_162 . V_168 = V_164 -> V_169 ;
F_64 ( V_164 , FALSE ) ;
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
F_63 ( V_145 , V_159 ) ;
}
if ( ( V_3 = V_157 -> V_3 ) ) {
for(; V_3 ; V_3 = V_3 -> V_110 ) {
V_146 V_159 = { & ( V_3 -> V_105 ) , {
V_3 -> V_1 ,
F_27 ( V_3 -> V_1 ) ,
V_3 -> V_106 ,
V_3 -> V_108 ,
NULL ,
0 ,
NULL ,
V_161 } } ;
F_6 ( 5 , ( L_65 ,
V_3 -> V_1 , V_3 -> V_113 , V_3 -> V_111 ) ) ;
if ( V_3 -> V_105 == - 2 ) {
F_63 ( V_145 , V_159 ) ;
V_3 -> V_105 = - 1 ;
} else {
F_7 ( ( void * ) V_159 . V_162 . V_170 ) ;
}
}
}
}
}
V_144 = F_65 ( L_66 , L_67 , L_68 ) ;
F_66 ( V_144 , ( V_146 * ) ( void * ) V_145 -> V_169 , V_145 -> T_11 ) ;
F_67 ( ( T_9 * * ) ( void * ) V_147 -> V_169 , V_147 -> T_11 ) ;
F_64 ( V_147 , TRUE ) ;
F_64 ( V_145 , FALSE ) ;
}
void F_68 ( T_22 * V_171 )
{
#ifdef F_69
static T_23 V_172 [] = {
F_70 ( V_173 , V_1 , L_69 , L_70 ) ,
V_174
} ;
static T_23 V_175 [] = {
F_71 ( V_173 , V_1 , L_71 , L_72 ) ,
V_174
} ;
F_72 ( V_171 , L_73 ,
L_74 ,
L_75 ,
& V_149 ) ;
F_72 ( V_171 , L_76 ,
L_77 ,
L_78 ,
& V_153 ) ;
V_176 = F_73 ( L_79 ,
sizeof( T_12 ) ,
L_80 ,
FALSE ,
( void * * ) & V_177 ,
& V_178 ,
V_179 ,
L_81 ,
F_25 ,
NULL ,
F_26 ,
F_44 ,
V_175 ) ;
F_74 ( V_171 ,
L_80 ,
L_82 ,
L_83
L_84 ,
V_176 ) ;
V_180 = F_73 ( L_85 ,
sizeof( T_12 ) ,
L_86 ,
FALSE ,
( void * * ) & V_151 ,
& V_150 ,
V_179 ,
L_87 ,
F_25 ,
NULL ,
F_26 ,
F_44 ,
V_172 ) ;
F_74 ( V_171 ,
L_86 ,
L_88 ,
L_89
L_84 ,
V_180 ) ;
#else
F_75 ( V_171 , L_90 ,
L_91 ,
L_92 ) ;
F_75 ( V_171 , L_93 ,
L_94 ,
L_92 ) ;
F_75 ( V_171 , L_95 ,
L_96 ,
L_92 ) ;
#endif
}
void F_76 ( void ) {
#ifdef F_69
F_46 () ;
#else
F_6 ( 1 , ( L_97 ) ) ;
#endif
}
void F_77 ( void ) {
#ifdef F_69
F_43 () ;
#else
F_6 ( 1 , ( L_97 ) ) ;
#endif
}
const char * F_13 ( T_6 * V_5 , T_5 T_11 ) {
char * V_39 = ( char * ) F_78 ( ( ( T_11 ) * 11 ) + 1 ) ;
char * V_41 = V_39 ;
if( ! V_5 )
return L_98 ;
do {
V_41 += F_79 ( V_41 , 12 , L_99 , * V_5 ++ ) ;
} while( -- T_11 );
if ( V_41 != V_39 ) * ( V_41 - 1 ) = '\0' ; else * ( V_39 ) = '\0' ;
return V_39 ;
}
static T_5 F_80 ( const char * V_154 ) {
const char * V_40 = V_154 ;
char V_7 = '.' ;
T_5 V_14 = 0 ;
F_6 ( 8 , ( L_100 , V_154 ) ) ;
if ( ! V_40 ) return 0 ;
do {
F_6 ( 9 , ( L_101 , * V_40 , V_14 ) ) ;
switch( * V_40 ) {
case '.' : case '\0' :
V_14 ++ ;
if ( V_7 == '.' ) return 0 ;
break;
case '1' : case '2' : case '3' : case '4' : case '5' :
case '6' : case '7' : case '8' : case '9' : case '0' :
continue;
default:
return 0 ;
}
} while( ( V_7 = * V_40 ++ ) );
return V_14 ;
}
T_5 F_15 ( const char * V_154 , T_6 * * V_181 ) {
const char * V_40 = V_154 ;
T_6 * V_5 ;
T_6 * V_182 ;
T_5 V_14 = F_80 ( V_154 ) ;
T_24 V_11 = 0 ;
F_6 ( 6 , ( L_102 , V_154 ) ) ;
if ( ! V_14 ) {
* V_181 = NULL ;
return 0 ;
}
* V_181 = V_5 = ( T_6 * ) F_78 ( sizeof( T_6 ) * V_14 ) ;
V_182 = V_5 + V_14 ;
do switch( * V_40 ) {
case '.' :
V_11 = 0 ;
V_5 ++ ;
continue;
case '1' : case '2' : case '3' : case '4' : case '5' :
case '6' : case '7' : case '8' : case '9' : case '0' :
V_11 *= 10 ;
V_11 += * V_40 - '0' ;
if( V_5 >= V_182 || V_11 > 0xffffffff ) {
* V_181 = NULL ;
return 0 ;
}
* ( V_5 ) *= 10 ;
* ( V_5 ) += * V_40 - '0' ;
continue;
case '\0' :
break;
default:
return 0 ;
} while( * V_40 ++ );
return V_14 ;
}
T_5 F_17 ( const T_8 * V_183 , T_9 V_4 , T_6 * * V_181 ) {
T_9 V_6 ;
T_5 V_14 = 1 ;
T_18 V_184 = TRUE ;
T_6 * V_5 ;
T_6 * V_185 ;
T_24 V_11 = 0 ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ ) { if ( ! ( V_183 [ V_6 ] & 0x80 ) ) V_14 ++ ; }
* V_181 = V_5 = ( T_6 * ) F_81 ( sizeof( T_6 ) * V_14 ) ;
V_185 = V_5 + V_14 ;
if ( V_14 == 1 ) {
* V_5 = 0 ;
return V_14 ;
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
return V_14 ;
}
T_1 * F_82 ( T_5 T_11 , T_6 * V_5 , T_5 * V_188 , T_5 * V_189 ) {
T_1 * V_190 = & V_8 ;
T_5 V_6 ;
if( ! ( V_5 && * V_5 <= 2 ) ) {
* V_188 = 0 ;
* V_189 = T_11 ;
return V_190 ;
}
for( V_6 = 0 ; V_6 < T_11 ; V_6 ++ ) {
T_1 * V_191 = ( T_1 * ) F_4 ( ( V_15 * ) V_190 -> V_9 , V_5 [ V_6 ] ) ;
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
T_1 * F_83 ( const T_8 * V_193 , T_9 V_194 , T_6 * * V_181 , T_5 * V_195 , T_5 * V_196 ) {
T_5 V_23 = F_17 ( V_193 , V_194 , V_181 ) ;
return F_82 ( V_23 , * V_181 , V_195 , V_196 ) ;
}
T_1 * F_84 ( const T_7 * V_21 , T_6 * * V_181 , T_5 * V_188 , T_5 * V_189 ) {
T_5 V_23 = F_15 ( V_21 , V_181 ) ;
return F_82 ( V_23 , * V_181 , V_188 , V_189 ) ;
}
const T_7 * F_85 ( const T_8 * V_22 , T_9 V_4 ) {
T_6 * V_197 ;
T_5 V_198 = F_17 ( V_22 , V_4 , & V_197 ) ;
return F_86 ( V_198 , V_197 ) ;
}
T_5 F_87 ( T_5 V_23 , T_6 * V_5 , T_8 * * V_199 ) {
T_5 V_200 = 0 ;
T_5 V_6 ;
T_6 V_11 ;
T_8 * V_201 ;
if ( ! V_5 || V_23 <= 0 ) {
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
} while ( V_6 ++ < V_23 );
* V_199 = V_201 = ( T_8 * ) F_81 ( V_200 ) ;
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
} while ( V_6 ++ < V_23 );
return V_200 ;
}
const T_7 * F_88 ( const T_8 * V_202 , T_5 T_11 ) {
T_6 * V_5 ;
T_5 V_23 = F_17 ( V_202 , T_11 , & V_5 ) ;
if ( V_23 ) {
return F_13 ( V_5 , V_23 ) ;
} else {
return L_17 ;
}
}
T_5 F_89 ( const char * V_21 , T_8 * * V_193 ) {
T_6 * V_5 ;
T_6 V_23 ;
T_5 V_194 ;
if ( ( V_23 = F_15 ( V_21 , & V_5 ) )
&&
( V_194 = F_87 ( V_23 , V_5 , V_193 ) ) ) {
return V_194 ;
}
return 0 ;
}
const T_7 * F_90 ( const T_7 * V_21 ) {
T_6 * V_197 ;
T_5 V_198 = F_15 ( V_21 , & V_197 ) ;
return F_86 ( V_198 , V_197 ) ;
}
const T_7 * F_86 ( T_6 V_113 , T_6 * V_5 ) {
T_5 V_188 ;
T_5 V_189 ;
T_1 * V_22 ;
if( ! ( V_5 && * V_5 <= 2 ) )
return L_103 ;
V_22 = F_82 ( V_113 , V_5 , & V_188 , & V_189 ) ;
while ( ! V_22 -> V_1 ) {
if ( ! ( V_22 = V_22 -> V_18 ) ) {
return F_13 ( V_5 , V_113 ) ;
}
V_189 ++ ;
V_188 -- ;
}
if ( V_189 ) {
return F_91 ( L_46 ,
V_22 -> V_1 ? V_22 -> V_1 : F_13 ( V_5 , V_188 ) ,
F_13 ( & ( V_5 [ V_188 ] ) , V_189 ) ) ;
} else {
return V_22 -> V_1 ? V_22 -> V_1 : F_13 ( V_5 , V_188 ) ;
}
}
extern void F_92 ( T_5 V_4 , T_6 * V_5 , char * * V_203 , char * * V_204 ) {
* V_203 = ( char * ) F_86 ( V_4 , V_5 ) ;
* V_204 = ( char * ) F_13 ( V_5 , V_4 ) ;
}
extern void F_93 ( const T_8 * V_22 , T_9 V_4 , char * * V_203 , char * * V_204 ) {
T_6 * V_5 ;
T_5 V_23 = F_17 ( V_22 , V_4 , & V_5 ) ;
* V_203 = ( char * ) F_86 ( V_23 , V_5 ) ;
* V_204 = ( char * ) F_13 ( V_5 , V_23 ) ;
}
extern void F_94 ( const T_7 * V_21 , char * * V_203 , char * * V_204 ) {
T_6 * V_5 ;
T_5 V_23 = F_15 ( V_21 , & V_5 ) ;
* V_203 = ( char * ) F_86 ( V_23 , V_5 ) ;
* V_204 = ( char * ) F_13 ( V_5 , V_23 ) ;
}
extern T_7 *
F_51 ( void ) {
#ifdef F_69
T_25 * V_148 ;
T_7 * V_205 ;
char * V_28 ;
T_5 V_6 ;
V_148 = F_49 ( L_17 ) ;
if ( ! V_149 ) {
F_6 ( 1 , ( L_48 ) ) ;
return V_148 -> V_154 ;
}
#ifdef F_21
#define F_95 ";"
V_28 = F_96 ( L_104 ) ;
F_24 ( V_148 , L_105 , V_28 ) ;
F_7 ( V_28 ) ;
V_28 = F_97 ( L_104 , FALSE ) ;
F_24 ( V_148 , L_106 , V_28 ) ;
F_7 ( V_28 ) ;
#else
#define F_95 ":"
V_28 = F_98 () ;
F_99 ( V_148 , L_107 ) ;
if ( strlen ( V_28 ) > 0 ) {
F_99 ( V_148 , F_95 ) ;
}
F_24 ( V_148 , L_106 , V_28 ) ;
free ( V_28 ) ;
#endif
for( V_6 = 0 ; V_6 < V_178 ; V_6 ++ ) {
if ( ! ( V_177 [ V_6 ] . V_1 && * V_177 [ V_6 ] . V_1 ) )
continue;
F_24 ( V_148 , F_95 L_106 , V_177 [ V_6 ] . V_1 ) ;
}
V_205 = V_148 -> V_154 ;
F_55 ( V_148 , FALSE ) ;
return V_205 ;
#else
return F_8 ( L_17 ) ;
#endif
}
char * F_100 ( T_6 V_113 , T_6 * V_5 ) {
T_8 * V_206 ;
T_8 * V_207 ;
T_6 * V_208 ;
T_6 * V_209 ;
const char * V_210 = F_13 ( V_5 , V_113 ) ;
T_5 V_211 = F_87 ( V_113 , V_5 , & V_206 ) ;
T_5 V_212 = F_17 ( V_206 , V_211 , & V_208 ) ;
const char * V_213 = F_88 ( V_206 , V_211 ) ;
T_5 V_214 = F_89 ( V_210 , & V_207 ) ;
T_5 V_215 = F_15 ( V_210 , & V_209 ) ;
return F_91 (
L_108
L_109
L_110
L_111
L_112
L_113
, V_210
, V_211 , F_18 ( V_206 , V_211 , ':' )
, V_208 ? F_13 ( V_208 , V_212 ) : L_16
, V_213
, V_214 , F_18 ( V_207 , V_214 , ':' )
, V_209 ? F_13 ( V_209 , V_215 ) : L_16
) ;
}
void F_101 ( T_1 * V_216 , T_26 * V_217 ) {
static const char * V_218 [] = { L_114 , L_115 , L_116 , L_117 , L_118 , L_119 , L_120 , L_121 , L_122 , L_123 } ;
static const char * V_219 [] = { L_124 , L_125 ,
L_126 , L_127 , L_128 ,
L_129 , L_130 , L_131 , L_132 } ;
T_27 * V_220 = F_102 ( V_217 , NULL , 0 , 0 ,
L_133 ,
V_216 -> V_1 ? V_216 -> V_1 : L_17 ,
V_216 -> V_11 ,
V_216 -> V_2 <= V_140 ? V_218 [ V_216 -> V_2 ] : L_134 ,
V_216 -> V_17 ) ;
T_26 * V_221 = F_103 ( V_220 , 0 ) ;
T_4 * V_3 ;
for( V_3 = V_216 -> V_3 ; V_3 ; V_3 = V_3 -> V_110 ) {
F_102 ( V_221 , NULL , 0 , 0 ,
L_135 ,
V_3 -> V_1 ,
V_3 -> V_111 <= V_222 ? V_219 [ V_3 -> V_111 ] : L_134
) ;
} ;
if ( V_216 -> V_18 ) {
V_220 = F_102 ( V_221 , NULL , 0 , 0 , L_136 ) ;
V_221 = F_103 ( V_220 , 0 ) ;
F_101 ( V_216 -> V_18 , V_221 ) ;
}
}
