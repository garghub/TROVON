static bool F_1 ( const unsigned int V_1 , const char * V_2 ,
const int V_3 , const struct F_1 * V_4 ,
T_1 * V_5 )
{
int V_6 ;
struct V_7 V_8 ;
V_8 . V_9 = V_2 ;
for ( V_6 = 0 ; V_6 < V_3 ; V_4 ++ , V_5 ++ , V_6 ++ ) {
bool V_10 ;
if ( V_1 != V_4 -> V_1 )
continue;
* V_5 = 1 ;
F_2 ( & V_8 ) ;
V_10 = F_3 ( & V_8 , V_4 -> V_11 ) ;
if ( V_4 -> V_12 )
V_10 = ! V_10 ;
if ( ! V_10 )
return false ;
}
return true ;
}
static bool F_4 ( const char * V_13 , const char * V_14 ,
const int V_15 , const struct F_4 * V_16 ,
T_1 * V_5 )
{
int V_6 ;
struct V_7 V_9 ;
struct V_7 V_11 ;
V_9 . V_9 = V_13 ;
F_2 ( & V_9 ) ;
V_11 . V_9 = V_14 ;
F_2 ( & V_11 ) ;
for ( V_6 = 0 ; V_6 < V_15 ; V_16 ++ , V_5 ++ , V_6 ++ ) {
bool V_10 ;
if ( ! F_3 ( & V_9 , V_16 -> V_9 ) )
continue;
* V_5 = 1 ;
if ( V_16 -> V_11 ) {
V_10 = F_3 ( & V_11 ,
V_16 -> V_11 ) ;
if ( V_16 -> V_12 )
V_10 = ! V_10 ;
} else {
V_10 = true ;
if ( ! V_16 -> V_12 )
V_10 = ! V_10 ;
}
if ( ! V_10 )
return false ;
}
return true ;
}
static bool F_5 ( struct V_17 * V_18 ,
const T_2 V_3 , const struct F_1 * V_4 ,
const T_2 V_15 , const struct F_4 * V_16 )
{
struct V_19 * V_20 = V_18 -> V_20 ;
struct V_21 * V_22 = & V_18 -> V_22 ;
char * V_2 = V_18 -> V_23 ;
int V_24 = 0 ;
unsigned long V_25 = V_20 -> V_26 ;
int V_27 = V_25 % V_28 ;
int V_29 = V_20 -> V_3 ;
int V_30 = V_20 -> V_15 ;
bool V_10 = true ;
T_1 V_31 [ 32 ] ;
T_1 * V_5 ;
if ( V_3 + V_15 <= sizeof( V_31 ) ) {
V_5 = V_31 ;
memset ( V_31 , 0 , sizeof( V_31 ) ) ;
} else {
V_5 = F_6 ( V_3 + V_15 , V_32 ) ;
if ( ! V_5 )
return false ;
}
while ( V_29 || V_30 ) {
if ( ! F_7 ( V_20 , V_25 , V_22 ) ) {
V_10 = false ;
goto V_33;
}
V_25 += V_28 - V_27 ;
while ( V_27 < V_28 ) {
const char * V_34 = V_22 -> V_35 ;
const unsigned char V_36 = V_34 [ V_27 ++ ] ;
if ( V_36 && V_24 < V_37 - 10 ) {
if ( V_36 == '\\' ) {
V_2 [ V_24 ++ ] = '\\' ;
V_2 [ V_24 ++ ] = '\\' ;
} else if ( V_36 > ' ' && V_36 < 127 ) {
V_2 [ V_24 ++ ] = V_36 ;
} else {
V_2 [ V_24 ++ ] = '\\' ;
V_2 [ V_24 ++ ] = ( V_36 >> 6 ) + '0' ;
V_2 [ V_24 ++ ] =
( ( V_36 >> 3 ) & 7 ) + '0' ;
V_2 [ V_24 ++ ] = ( V_36 & 7 ) + '0' ;
}
} else {
V_2 [ V_24 ] = '\0' ;
}
if ( V_36 )
continue;
if ( V_29 ) {
if ( ! F_1 ( V_20 -> V_3 - V_29 ,
V_2 , V_3 , V_4 ,
V_5 ) ) {
V_10 = false ;
break;
}
V_29 -- ;
} else if ( V_30 ) {
char * V_38 = strchr ( V_2 , '=' ) ;
if ( V_38 ) {
* V_38 = '\0' ;
if ( ! F_4 ( V_2 , V_38 + 1 ,
V_15 , V_16 ,
V_5 + V_3 ) ) {
V_10 = false ;
break;
}
}
V_30 -- ;
} else {
break;
}
V_24 = 0 ;
}
V_27 = 0 ;
if ( ! V_10 )
break;
}
V_33:
if ( V_10 ) {
int V_6 ;
for ( V_6 = 0 ; V_6 < V_3 ; V_6 ++ ) {
if ( V_5 [ V_6 ] )
continue;
if ( V_4 [ V_6 ] . V_12 )
continue;
V_10 = false ;
break;
}
for ( V_6 = 0 ; V_6 < V_15 ; V_16 ++ , V_6 ++ ) {
if ( V_5 [ V_3 + V_6 ] )
continue;
if ( ( ! V_16 -> V_11 && ! V_16 -> V_12 ) ||
( V_16 -> V_11 && V_16 -> V_12 ) )
continue;
V_10 = false ;
break;
}
}
if ( V_5 != V_31 )
F_8 ( V_5 ) ;
return V_10 ;
}
static bool F_9 ( struct V_39 * V_39 ,
const struct V_40 * V_41 ,
const bool V_42 )
{
bool V_10 ;
struct V_7 V_43 ;
if ( ! V_39 )
return false ;
V_43 . V_9 = F_10 ( & V_39 -> V_44 ) ;
if ( ! V_43 . V_9 )
return false ;
F_2 ( & V_43 ) ;
V_10 = F_11 ( & V_43 , V_41 ) ;
F_8 ( V_43 . V_9 ) ;
return V_10 == V_42 ;
}
static const struct V_7 * F_12 ( char * V_45 )
{
char * V_38 = V_45 + strlen ( V_45 ) - 1 ;
if ( V_38 == V_45 || * V_45 ++ != '"' || * V_38 != '"' )
return NULL ;
* V_38 = '\0' ;
if ( * V_45 && ! F_13 ( V_45 ) )
return NULL ;
return F_14 ( V_45 ) ;
}
static bool F_15 ( struct V_46 * V_47 ,
struct V_40 * V_41 )
{
char * V_48 = V_47 -> V_35 ;
if ( * V_48 == '@' )
return F_16 ( V_47 , V_41 ) ;
V_41 -> V_48 = F_12 ( V_48 ) ;
return V_41 -> V_48 != NULL ;
}
static bool F_17 ( char * V_49 , char * V_50 ,
struct F_1 * V_4 )
{
if ( F_18 ( & V_4 -> V_1 , & V_49 ) !=
V_51 || * V_49 ++ != ']' || * V_49 )
return false ;
V_4 -> V_11 = F_12 ( V_50 ) ;
return V_4 -> V_11 != NULL ;
}
static bool F_19 ( char * V_49 , char * V_50 ,
struct F_4 * V_16 )
{
const struct V_7 * V_9 ;
const struct V_7 * V_11 ;
char * V_38 = V_49 + strlen ( V_49 ) - 1 ;
if ( * V_38 -- != ']' || * V_38 != '"' )
goto V_33;
* V_38 = '\0' ;
if ( ! F_13 ( V_49 ) )
goto V_33;
V_9 = F_14 ( V_49 ) ;
if ( ! V_9 )
goto V_33;
if ( ! strcmp ( V_50 , L_1 ) ) {
V_11 = NULL ;
} else {
V_11 = F_12 ( V_50 ) ;
if ( ! V_11 ) {
F_20 ( V_9 ) ;
goto V_33;
}
}
V_16 -> V_9 = V_9 ;
V_16 -> V_11 = V_11 ;
return true ;
V_33:
return false ;
}
static inline bool F_21 ( const struct V_52 * V_53 ,
const struct V_52 * V_54 )
{
return V_53 -> V_55 == V_54 -> V_55 && V_53 -> V_56 == V_54 -> V_56 &&
V_53 -> V_57 == V_54 -> V_57 &&
V_53 -> V_58 == V_54 -> V_58 &&
V_53 -> V_3 == V_54 -> V_3 && V_53 -> V_15 == V_54 -> V_15 &&
V_53 -> V_59 == V_54 -> V_59 && V_53 -> V_60 == V_54 -> V_60 &&
! memcmp ( V_53 + 1 , V_54 + 1 , V_53 -> V_55 - sizeof( * V_53 ) ) ;
}
static T_1 F_22 ( const char * V_61 )
{
T_1 V_6 ;
for ( V_6 = 0 ; V_6 < V_62 ; V_6 ++ ) {
if ( ! strcmp ( V_61 , V_63 [ V_6 ] ) )
break;
}
return V_6 ;
}
static struct V_52 * F_23
( struct V_52 * V_64 )
{
struct V_52 * V_41 ;
bool V_65 = false ;
if ( F_24 ( & V_66 ) ) {
F_25 ( V_67 L_2 , __LINE__ , V_68 ) ;
V_41 = NULL ;
V_65 = true ;
goto V_33;
}
F_26 (ptr, &tomoyo_condition_list, head.list) {
if ( ! F_21 ( V_41 , V_64 ) ||
F_27 ( & V_41 -> V_69 . V_70 ) == V_71 )
continue;
F_28 ( & V_41 -> V_69 . V_70 ) ;
V_65 = true ;
break;
}
if ( ! V_65 ) {
if ( F_29 ( V_64 ) ) {
F_30 ( & V_64 -> V_69 . V_70 , 1 ) ;
F_31 ( & V_64 -> V_69 . V_72 , & V_73 ) ;
} else {
V_65 = true ;
V_41 = NULL ;
}
}
F_32 ( & V_66 ) ;
V_33:
if ( V_65 ) {
F_33 ( & V_64 -> V_69 . V_72 ) ;
F_8 ( V_64 ) ;
V_64 = V_41 ;
}
return V_64 ;
}
static char * F_34 ( struct V_46 * V_47 ,
struct V_52 * V_74 )
{
char * const V_25 = V_47 -> V_35 ;
bool V_75 ;
if ( * V_25 == '<' ) {
V_74 -> V_60 = F_35 ( V_47 ) ;
goto V_76;
}
{
char * V_38 = strchr ( V_25 , ' ' ) ;
if ( V_38 )
* V_38 = '\0' ;
V_75 = F_36 ( V_25 ) || ! strcmp ( V_25 , L_3 ) ||
! strcmp ( V_25 , L_4 ) || ! strcmp ( V_25 , L_5 ) ||
! strcmp ( V_25 , L_6 ) || ! strcmp ( V_25 , L_7 ) ;
if ( V_38 )
* V_38 = ' ' ;
}
if ( ! V_75 )
return V_25 ;
V_74 -> V_60 = F_14 ( F_37 ( V_47 ) ) ;
V_76:
if ( V_74 -> V_60 )
return V_47 -> V_35 ;
return L_8 ;
}
struct V_52 * F_38 ( struct V_46 * V_47 )
{
struct V_52 * V_64 = NULL ;
struct V_77 * V_78 = NULL ;
struct V_79 * V_80 = NULL ;
struct V_40 * V_81 = NULL ;
struct F_1 * V_4 = NULL ;
struct F_4 * V_16 = NULL ;
struct V_52 V_74 = { } ;
char * const V_82 =
F_34 ( V_47 , & V_74 ) ;
char * const V_83 = V_82 + strlen ( V_82 ) ;
char * V_25 ;
V_84:
V_25 = V_82 ;
while ( 1 ) {
T_1 V_49 = - 1 ;
T_1 V_50 = - 1 ;
char * V_85 = V_25 ;
char * V_38 ;
char * V_86 ;
bool V_12 ;
if ( ! * V_85 )
break;
V_38 = strchr ( V_25 , ' ' ) ;
if ( V_38 ) {
* V_38 = '\0' ;
V_25 = V_38 + 1 ;
} else {
V_25 = L_9 ;
}
V_86 = strchr ( V_85 , '=' ) ;
if ( ! V_86 || V_86 == V_85 )
goto V_33;
V_12 = * ( V_86 - 1 ) == '!' ;
if ( V_12 )
* ( V_86 ++ - 1 ) = '\0' ;
else if ( * ( V_86 + 1 ) != '=' )
* V_86 ++ = '\0' ;
else
goto V_33;
F_25 ( V_67 L_10 , __LINE__ , V_85 ,
V_12 ? L_11 : L_9 , V_86 ) ;
if ( ! strcmp ( V_85 , L_12 ) ) {
if ( V_64 ) {
if ( V_12 ||
V_64 -> V_59 != V_87 )
goto V_33;
else if ( ! strcmp ( V_86 , L_13 ) )
V_64 -> V_59 = V_88 ;
else if ( ! strcmp ( V_86 , L_14 ) )
V_64 -> V_59 = V_89 ;
else
goto V_33;
}
continue;
}
if ( ! strncmp ( V_85 , L_15 , 10 ) ) {
if ( ! V_4 ) {
V_74 . V_3 ++ ;
V_74 . V_56 ++ ;
} else {
V_74 . V_3 -- ;
V_74 . V_56 -- ;
V_49 = V_90 ;
V_4 -> V_12 = V_12 ;
if ( ! F_17 ( V_85 + 10 ,
V_86 , V_4 ++ ) )
goto V_33;
}
goto V_91;
}
if ( ! strncmp ( V_85 , L_16 , 11 ) ) {
if ( ! V_16 ) {
V_74 . V_15 ++ ;
V_74 . V_56 ++ ;
} else {
V_74 . V_15 -- ;
V_74 . V_56 -- ;
V_49 = V_92 ;
V_16 -> V_12 = V_12 ;
if ( ! F_19 ( V_85 + 11 ,
V_86 , V_16 ++ ) )
goto V_33;
}
goto V_91;
}
V_49 = F_22 ( V_85 ) ;
F_25 ( V_67 L_17 , __LINE__ , V_85 ,
V_49 ) ;
if ( V_49 == V_62 ) {
if ( ! V_80 ) {
V_74 . V_57 ++ ;
} else {
V_74 . V_57 -- ;
V_49 = V_93 ;
V_47 -> V_35 = V_85 ;
if ( * V_85 == '@' ||
! F_39 ( V_47 ,
V_80 ++ ) )
goto V_33;
}
}
if ( ! V_78 )
V_74 . V_56 ++ ;
else
V_74 . V_56 -- ;
if ( V_49 == V_94 ||
V_49 == V_95 ) {
if ( ! V_81 ) {
V_74 . V_58 ++ ;
} else {
V_74 . V_58 -- ;
V_50 = V_96 ;
V_47 -> V_35 = V_86 ;
if ( ! F_15 ( V_47 ,
V_81 ++ ) )
goto V_33;
}
goto V_91;
}
V_50 = F_22 ( V_86 ) ;
if ( V_50 == V_62 ) {
if ( ! V_80 ) {
V_74 . V_57 ++ ;
} else {
V_74 . V_57 -- ;
V_50 = V_93 ;
V_47 -> V_35 = V_86 ;
if ( ! F_39 ( V_47 ,
V_80 ++ ) )
goto V_33;
}
}
V_91:
if ( ! V_78 ) {
F_25 ( V_67 L_18
L_19 , __LINE__ , V_49 , V_50 , ! V_12 ) ;
continue;
}
V_78 -> V_49 = V_49 ;
V_78 -> V_50 = V_50 ;
V_78 -> V_97 = ! V_12 ;
F_25 ( V_67 L_20 ,
__LINE__ , V_78 -> V_49 , V_78 -> V_50 ,
V_78 -> V_97 ) ;
V_78 ++ ;
}
F_25 ( V_98 L_21 ,
__LINE__ , V_74 . V_56 , V_74 . V_57 , V_74 . V_58 , V_74 . V_3 ,
V_74 . V_15 ) ;
if ( V_64 ) {
F_40 ( V_74 . V_58 | V_74 . V_57 | V_74 . V_3 | V_74 . V_15 |
V_74 . V_56 ) ;
return F_23 ( V_64 ) ;
}
V_74 . V_55 = sizeof( * V_64 )
+ V_74 . V_56 * sizeof( struct V_77 )
+ V_74 . V_57 * sizeof( struct V_79 )
+ V_74 . V_58 * sizeof( struct V_40 )
+ V_74 . V_3 * sizeof( struct F_1 )
+ V_74 . V_15 * sizeof( struct F_4 ) ;
V_64 = F_6 ( V_74 . V_55 , V_32 ) ;
if ( ! V_64 )
goto V_99;
* V_64 = V_74 ;
V_74 . V_60 = NULL ;
V_78 = (struct V_77 * ) ( V_64 + 1 ) ;
V_80 = (struct V_79 * ) ( V_78 + V_74 . V_56 ) ;
V_81 = (struct V_40 * ) ( V_80 + V_74 . V_57 ) ;
V_4 = (struct F_1 * ) ( V_81 + V_74 . V_58 ) ;
V_16 = (struct F_4 * ) ( V_4 + V_74 . V_3 ) ;
{
bool V_75 = false ;
for ( V_25 = V_82 ; V_25 < V_83 ; V_25 ++ ) {
if ( * V_25 )
continue;
if ( V_75 )
* V_25 = ' ' ;
else if ( * ( V_25 + 1 ) == '=' )
* V_25 = '!' ;
else
* V_25 = '=' ;
V_75 = ! V_75 ;
}
}
goto V_84;
V_33:
F_25 ( V_67 L_2 , __LINE__ , V_68 ) ;
if ( V_64 ) {
F_33 ( & V_64 -> V_69 . V_72 ) ;
F_8 ( V_64 ) ;
}
V_99:
F_20 ( V_74 . V_60 ) ;
return NULL ;
}
void F_41 ( struct V_100 * V_101 )
{
T_1 V_6 ;
struct V_102 * V_102 = NULL ;
for ( V_6 = 0 ; V_6 < V_103 ; V_6 ++ ) {
struct V_104 * V_104 ;
switch ( V_6 ) {
case V_105 :
V_102 = V_101 -> V_106 . V_102 ;
if ( ! V_102 )
continue;
break;
case V_107 :
V_102 = V_101 -> V_108 . V_102 ;
if ( ! V_102 )
continue;
break;
default:
if ( ! V_102 )
continue;
V_102 = F_42 ( V_102 ) ;
break;
}
V_104 = V_102 -> V_109 ;
if ( V_104 ) {
struct V_110 * V_111 = & V_101 -> V_111 [ V_6 ] ;
V_111 -> V_112 = V_104 -> V_113 ;
V_111 -> V_114 = V_104 -> V_115 ;
V_111 -> V_116 = V_104 -> V_117 ;
V_111 -> V_118 = V_104 -> V_119 ;
V_111 -> V_120 = V_104 -> V_121 -> V_122 ;
V_111 -> V_123 = V_104 -> V_124 ;
V_101 -> V_125 [ V_6 ] = true ;
}
if ( V_6 & 1 )
F_43 ( V_102 ) ;
}
}
bool V_52 ( struct V_126 * V_127 ,
const struct V_52 * V_128 )
{
T_3 V_6 ;
unsigned long V_129 [ 2 ] = { 0 , 0 } ;
unsigned long V_130 [ 2 ] = { 0 , 0 } ;
const struct V_77 * V_78 ;
const struct V_79 * V_80 ;
const struct V_40 * V_81 ;
const struct F_1 * V_4 ;
const struct F_4 * V_16 ;
struct V_100 * V_101 ;
T_2 V_56 ;
T_2 V_3 ;
T_2 V_15 ;
struct V_19 * V_20 = NULL ;
if ( ! V_128 )
return true ;
V_56 = V_128 -> V_56 ;
V_3 = V_128 -> V_3 ;
V_15 = V_128 -> V_15 ;
V_101 = V_127 -> V_101 ;
if ( V_127 -> V_18 )
V_20 = V_127 -> V_18 -> V_20 ;
if ( ! V_20 && ( V_3 || V_15 ) )
return false ;
V_78 = (struct V_77 * ) ( V_128 + 1 ) ;
V_80 = ( const struct V_79 * ) ( V_78 + V_56 ) ;
V_81 = ( const struct V_40 * )
( V_80 + V_128 -> V_57 ) ;
V_4 = ( const struct F_1 * ) ( V_81 + V_128 -> V_58 ) ;
V_16 = ( const struct F_4 * ) ( V_4 + V_3 ) ;
for ( V_6 = 0 ; V_6 < V_56 ; V_6 ++ ) {
const bool V_42 = V_78 -> V_97 ;
const T_1 V_49 = V_78 -> V_49 ;
const T_1 V_50 = V_78 -> V_50 ;
bool V_131 [ 2 ] = { false , false } ;
T_1 V_132 ;
V_78 ++ ;
if ( V_49 == V_90 || V_49 == V_92 )
continue;
if ( V_50 == V_96 ) {
const struct V_40 * V_41 = V_81 ++ ;
switch ( V_49 ) {
struct V_7 * V_133 ;
struct V_17 * V_18 ;
struct V_39 * V_39 ;
case V_95 :
V_133 = V_101 ? V_101 -> V_134 : NULL ;
if ( ! V_133 ||
! F_11 ( V_133 , V_41 )
== V_42 )
goto V_33;
break;
case V_94 :
V_18 = V_127 -> V_18 ;
V_39 = V_18 ? V_18 -> V_20 -> V_39 : NULL ;
if ( ! F_9 ( V_39 , V_41 ,
V_42 ) )
goto V_33;
break;
}
continue;
}
for ( V_132 = 0 ; V_132 < 2 ; V_132 ++ ) {
const T_1 V_1 = V_132 ? V_50 : V_49 ;
unsigned long V_11 = 0 ;
switch ( V_1 ) {
case V_135 :
V_11 = F_44 ( & V_136 , F_45 () ) ;
break;
case V_137 :
V_11 = F_44 ( & V_136 , F_46 () ) ;
break;
case V_138 :
V_11 = F_44 ( & V_136 , F_47 () ) ;
break;
case V_139 :
V_11 = F_44 ( & V_136 , F_48 () ) ;
break;
case V_140 :
V_11 = F_49 ( & V_136 , F_50 () ) ;
break;
case V_141 :
V_11 = F_49 ( & V_136 , F_51 () ) ;
break;
case V_142 :
V_11 = F_49 ( & V_136 , F_52 () ) ;
break;
case V_143 :
V_11 = F_49 ( & V_136 , F_53 () ) ;
break;
case V_144 :
V_11 = F_54 () ;
break;
case V_145 :
V_11 = F_55 () ;
break;
case V_146 :
V_11 = V_147 ;
break;
case V_148 :
V_11 = V_149 ;
break;
case V_150 :
V_11 = V_151 ;
break;
case V_152 :
V_11 = V_153 ;
break;
case V_154 :
V_11 = V_155 ;
break;
case V_156 :
V_11 = V_157 ;
break;
case V_158 :
V_11 = V_159 ;
break;
case V_160 :
V_11 = V_161 ;
break;
case V_162 :
V_11 = V_163 ;
break;
case V_164 :
V_11 = V_165 ;
break;
case V_166 :
V_11 = V_167 ;
break;
case V_168 :
V_11 = V_169 ;
break;
case V_170 :
V_11 = V_171 ;
break;
case V_172 :
V_11 = V_173 ;
break;
case V_174 :
V_11 = V_175 ;
break;
case V_176 :
V_11 = V_177 ;
break;
case V_178 :
V_11 = V_179 ;
break;
case V_180 :
V_11 = V_181 ;
break;
case V_182 :
V_11 = V_183 ;
break;
case V_184 :
if ( ! V_20 )
goto V_33;
V_11 = V_20 -> V_3 ;
break;
case V_185 :
if ( ! V_20 )
goto V_33;
V_11 = V_20 -> V_15 ;
break;
case V_93 :
break;
default:
if ( ! V_101 )
goto V_33;
if ( ! V_101 -> V_186 ) {
F_41 ( V_101 ) ;
V_101 -> V_186 = true ;
}
{
T_1 V_187 ;
struct V_110 * V_111 ;
switch ( V_1 ) {
case V_188 :
case V_189 :
case V_190 :
case V_191 :
case V_192 :
case V_193 :
case V_194 :
case V_195 :
case V_196 :
V_187 = V_105 ;
break;
case V_197 :
case V_198 :
case V_199 :
case V_200 :
case V_201 :
case V_202 :
case V_203 :
case V_204 :
case V_205 :
V_187 = V_107 ;
break;
case V_206 :
case V_207 :
case V_208 :
case V_209 :
V_187 =
V_210 ;
break;
case V_211 :
case V_212 :
case V_213 :
case V_214 :
V_187 =
V_215 ;
break;
default:
goto V_33;
}
if ( ! V_101 -> V_125 [ V_187 ] )
goto V_33;
V_111 = & V_101 -> V_111 [ V_187 ] ;
switch ( V_1 ) {
case V_188 :
case V_197 :
case V_206 :
case V_211 :
V_11 = F_44 ( & V_136 , V_111 -> V_112 ) ;
break;
case V_189 :
case V_198 :
case V_207 :
case V_212 :
V_11 = F_49 ( & V_136 , V_111 -> V_114 ) ;
break;
case V_190 :
case V_199 :
case V_208 :
case V_213 :
V_11 = V_111 -> V_116 ;
break;
case V_191 :
case V_200 :
V_11 = F_56 ( V_111 -> V_120 ) ;
break;
case V_192 :
case V_201 :
V_11 = F_57 ( V_111 -> V_120 ) ;
break;
case V_193 :
case V_202 :
V_11 = V_111 -> V_118 & V_216 ;
break;
case V_194 :
case V_203 :
V_11 = F_56 ( V_111 -> V_123 ) ;
break;
case V_195 :
case V_204 :
V_11 = F_57 ( V_111 -> V_123 ) ;
break;
case V_196 :
case V_205 :
case V_209 :
case V_214 :
V_11 = V_111 -> V_118 & V_217 ;
break;
}
}
break;
}
V_130 [ V_132 ] = V_11 ;
V_129 [ V_132 ] = V_11 ;
switch ( V_1 ) {
case V_160 :
case V_162 :
case V_164 :
case V_166 :
case V_168 :
case V_170 :
case V_172 :
case V_174 :
case V_176 :
case V_178 :
case V_180 :
case V_182 :
V_131 [ V_132 ] = true ;
}
}
if ( V_49 == V_93 ) {
const struct V_79 * V_41 = V_80 ++ ;
V_129 [ 0 ] = V_41 -> V_218 [ 0 ] ;
V_130 [ 0 ] = V_41 -> V_218 [ 1 ] ;
}
if ( V_50 == V_93 ) {
const struct V_79 * V_41 = V_80 ++ ;
if ( V_41 -> V_219 ) {
if ( F_58 ( V_129 [ 0 ] ,
V_130 [ 0 ] ,
V_41 -> V_219 )
== V_42 )
continue;
} else {
if ( ( V_129 [ 0 ] <= V_41 -> V_218 [ 1 ] &&
V_130 [ 0 ] >= V_41 -> V_218 [ 0 ] ) == V_42 )
continue;
}
goto V_33;
}
if ( V_131 [ 0 ] && V_131 [ 1 ] ) {
goto V_33;
} else if ( V_131 [ 0 ] ) {
switch ( V_50 ) {
case V_196 :
case V_209 :
case V_205 :
case V_214 :
if ( ! ( V_130 [ 0 ] & V_130 [ 1 ] ) == ! V_42 )
continue;
}
goto V_33;
} else if ( V_131 [ 1 ] ) {
switch ( V_49 ) {
case V_196 :
case V_209 :
case V_205 :
case V_214 :
if ( ! ( V_130 [ 0 ] & V_130 [ 1 ] ) == ! V_42 )
continue;
}
goto V_33;
}
if ( ( V_129 [ 0 ] <= V_130 [ 1 ] && V_130 [ 0 ] >= V_129 [ 1 ] ) == V_42 )
continue;
V_33:
return false ;
}
if ( V_127 -> V_18 && ( V_3 || V_15 ) )
return F_5 ( V_127 -> V_18 , V_3 , V_4 , V_15 , V_16 ) ;
return true ;
}
