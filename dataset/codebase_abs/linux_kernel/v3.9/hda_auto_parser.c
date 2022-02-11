static int F_1 ( T_1 V_1 , const T_1 * V_2 )
{
for (; * V_2 ; V_2 ++ )
if ( * V_2 == V_1 )
return 1 ;
return 0 ;
}
static int F_2 ( const void * V_3 , const void * V_4 )
{
const struct V_5 * V_6 = V_3 ;
const struct V_5 * V_7 = V_4 ;
return ( int ) ( V_6 -> V_8 - V_7 -> V_8 ) ;
}
static void F_3 ( T_1 * V_9 , struct V_5 * V_2 ,
int V_10 )
{
int V_11 ;
F_4 ( V_2 , V_10 , sizeof( V_2 [ 0 ] ) , F_2 , NULL ) ;
for ( V_11 = 0 ; V_11 < V_10 ; V_11 ++ )
V_9 [ V_11 ] = V_2 [ V_11 ] . V_12 ;
}
static void F_5 ( struct V_13 * V_14 , T_1 V_1 ,
int type )
{
if ( V_14 -> V_15 < V_16 ) {
V_14 -> V_17 [ V_14 -> V_15 ] . V_12 = V_1 ;
V_14 -> V_17 [ V_14 -> V_15 ] . type = type ;
V_14 -> V_15 ++ ;
}
}
static int F_6 ( const void * V_3 , const void * V_4 )
{
const struct V_18 * V_6 = V_3 ;
const struct V_18 * V_7 = V_4 ;
return ( int ) ( V_6 -> type - V_7 -> type ) ;
}
static void F_7 ( unsigned int V_19 , T_1 * V_9 )
{
T_1 V_1 ;
switch ( V_19 ) {
case 3 :
case 4 :
V_1 = V_9 [ 1 ] ;
V_9 [ 1 ] = V_9 [ 2 ] ;
V_9 [ 2 ] = V_1 ;
break;
}
}
static bool F_8 ( struct V_20 * V_21 , T_1 V_12 ,
unsigned int V_22 )
{
unsigned int V_23 = F_9 ( V_21 , V_12 ) ;
if ( ! V_23 )
return true ;
switch ( V_22 ) {
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
return ! ! ( V_23 & V_29 ) ;
default:
return ! ! ( V_23 & V_30 ) ;
}
}
int F_10 ( struct V_20 * V_21 ,
struct V_13 * V_14 ,
const T_1 * V_31 ,
unsigned int V_32 )
{
T_1 V_1 , V_33 ;
short V_8 , V_34 ;
struct V_5 V_35 [ F_11 ( V_14 -> V_36 ) ] ;
struct V_5 V_37 [ F_11 ( V_14 -> V_38 ) ] ;
struct V_5 V_39 [ F_11 ( V_14 -> V_40 ) ] ;
int V_11 ;
if ( ! F_12 ( V_21 , L_1 , & V_11 ) )
V_32 = V_11 ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
memset ( V_35 , 0 , sizeof( V_35 ) ) ;
memset ( V_37 , 0 , sizeof( V_37 ) ) ;
memset ( V_39 , 0 , sizeof( V_39 ) ) ;
V_34 = 0 ;
V_33 = V_21 -> V_41 + V_21 -> V_42 ;
for ( V_1 = V_21 -> V_41 ; V_1 < V_33 ; V_1 ++ ) {
unsigned int V_43 = F_13 ( V_21 , V_1 ) ;
unsigned int V_44 = F_14 ( V_43 ) ;
unsigned int V_45 ;
short V_46 , V_47 , V_48 , V_22 ;
if ( V_44 != V_49 )
continue;
if ( V_31 && F_1 ( V_1 , V_31 ) )
continue;
V_45 = F_15 ( V_21 , V_1 ) ;
V_48 = F_16 ( V_45 ) ;
if ( V_48 == V_50 )
continue;
V_47 = F_17 ( V_45 ) ;
V_22 = F_18 ( V_45 ) ;
if ( V_22 == V_24 ) {
if ( V_48 == V_51 ||
V_48 == V_52 )
V_22 = V_25 ;
}
if ( ! F_8 ( V_21 , V_1 , V_22 ) )
continue;
switch ( V_22 ) {
case V_24 :
V_8 = F_19 ( V_45 ) ;
V_46 = F_20 ( V_45 ) ;
if ( ! ( V_43 & V_53 ) )
if ( ! V_14 -> V_54 )
V_14 -> V_54 = V_1 ;
if ( ! V_46 )
continue;
if ( ! V_34 )
V_34 = V_46 ;
else if ( V_34 != V_46 )
continue;
if ( V_14 -> V_55 >= F_11 ( V_14 -> V_36 ) )
continue;
V_35 [ V_14 -> V_55 ] . V_12 = V_1 ;
V_35 [ V_14 -> V_55 ] . V_8 = V_8 ;
V_14 -> V_55 ++ ;
break;
case V_25 :
V_8 = F_19 ( V_45 ) ;
V_46 = F_20 ( V_45 ) ;
if ( V_14 -> V_56 >= F_11 ( V_14 -> V_38 ) )
continue;
V_37 [ V_14 -> V_56 ] . V_12 = V_1 ;
V_37 [ V_14 -> V_56 ] . V_8 = ( V_46 << 4 ) | V_8 ;
V_14 -> V_56 ++ ;
break;
case V_26 :
V_8 = F_19 ( V_45 ) ;
V_46 = F_20 ( V_45 ) ;
if ( V_14 -> V_57 >= F_11 ( V_14 -> V_40 ) )
continue;
V_39 [ V_14 -> V_57 ] . V_12 = V_1 ;
V_39 [ V_14 -> V_57 ] . V_8 = ( V_46 << 4 ) | V_8 ;
V_14 -> V_57 ++ ;
break;
case V_58 :
F_5 ( V_14 , V_1 , V_59 ) ;
break;
case V_60 :
F_5 ( V_14 , V_1 , V_61 ) ;
break;
case V_62 :
F_5 ( V_14 , V_1 , V_63 ) ;
break;
case V_64 :
F_5 ( V_14 , V_1 , V_65 ) ;
break;
case V_27 :
case V_28 :
if ( V_14 -> V_66 >= F_11 ( V_14 -> V_67 ) )
continue;
V_14 -> V_67 [ V_14 -> V_66 ] = V_1 ;
V_14 -> V_68 [ V_14 -> V_66 ] =
( V_47 == V_69 ) ?
V_70 : V_71 ;
V_14 -> V_66 ++ ;
break;
case V_72 :
case V_73 :
V_14 -> V_74 = V_1 ;
if ( V_47 == V_69 )
V_14 -> V_75 = V_70 ;
else
V_14 -> V_75 = V_71 ;
break;
}
}
if ( ! V_14 -> V_55 && V_14 -> V_57 > 1 &&
! ( V_32 & V_76 ) ) {
int V_11 = 0 ;
while ( V_11 < V_14 -> V_57 ) {
if ( ( V_39 [ V_11 ] . V_8 & 0x0f ) == 0x0f ) {
V_11 ++ ;
continue;
}
V_35 [ V_14 -> V_55 ++ ] = V_39 [ V_11 ] ;
V_14 -> V_57 -- ;
memmove ( V_39 + V_11 , V_39 + V_11 + 1 ,
sizeof( V_39 [ 0 ] ) * ( V_14 -> V_57 - V_11 ) ) ;
}
memset ( V_39 + V_14 -> V_57 , 0 ,
sizeof( V_39 [ 0 ] ) * ( V_77 - V_14 -> V_57 ) ) ;
if ( ! V_14 -> V_57 )
V_14 -> V_78 = V_79 ;
}
F_3 ( V_14 -> V_36 , V_35 , V_14 -> V_55 ) ;
F_3 ( V_14 -> V_38 , V_37 ,
V_14 -> V_56 ) ;
F_3 ( V_14 -> V_40 , V_39 , V_14 -> V_57 ) ;
if ( ! V_14 -> V_55 &&
! ( V_32 & V_80 ) ) {
if ( V_14 -> V_56 ) {
V_14 -> V_55 = V_14 -> V_56 ;
memcpy ( V_14 -> V_36 , V_14 -> V_38 ,
sizeof( V_14 -> V_38 ) ) ;
V_14 -> V_56 = 0 ;
memset ( V_14 -> V_38 , 0 , sizeof( V_14 -> V_38 ) ) ;
V_14 -> V_78 = V_81 ;
} else if ( V_14 -> V_57 ) {
V_14 -> V_55 = V_14 -> V_57 ;
memcpy ( V_14 -> V_36 , V_14 -> V_40 ,
sizeof( V_14 -> V_40 ) ) ;
V_14 -> V_57 = 0 ;
memset ( V_14 -> V_40 , 0 , sizeof( V_14 -> V_40 ) ) ;
V_14 -> V_78 = V_79 ;
}
}
F_7 ( V_14 -> V_55 , V_14 -> V_36 ) ;
F_7 ( V_14 -> V_57 , V_14 -> V_40 ) ;
F_7 ( V_14 -> V_56 , V_14 -> V_38 ) ;
F_4 ( V_14 -> V_17 , V_14 -> V_15 , sizeof( V_14 -> V_17 [ 0 ] ) ,
F_6 , NULL ) ;
F_21 ( L_2 ,
V_14 -> V_55 , V_14 -> V_36 [ 0 ] , V_14 -> V_36 [ 1 ] ,
V_14 -> V_36 [ 2 ] , V_14 -> V_36 [ 3 ] ,
V_14 -> V_36 [ 4 ] ,
V_14 -> V_78 == V_79 ? L_3 :
( V_14 -> V_78 == V_81 ?
L_4 : L_5 ) ) ;
F_21 ( L_6 ,
V_14 -> V_56 , V_14 -> V_38 [ 0 ] ,
V_14 -> V_38 [ 1 ] , V_14 -> V_38 [ 2 ] ,
V_14 -> V_38 [ 3 ] , V_14 -> V_38 [ 4 ] ) ;
F_21 ( L_7 ,
V_14 -> V_57 , V_14 -> V_40 [ 0 ] ,
V_14 -> V_40 [ 1 ] , V_14 -> V_40 [ 2 ] ,
V_14 -> V_40 [ 3 ] , V_14 -> V_40 [ 4 ] ) ;
F_21 ( L_8 , V_14 -> V_54 ) ;
if ( V_14 -> V_66 )
F_21 ( L_9 ,
V_14 -> V_67 [ 0 ] , V_14 -> V_67 [ 1 ] ) ;
F_21 ( L_10 ) ;
for ( V_11 = 0 ; V_11 < V_14 -> V_15 ; V_11 ++ ) {
F_21 ( L_11 ,
F_22 ( V_21 , V_14 , V_11 ) ,
V_14 -> V_17 [ V_11 ] . V_12 ) ;
}
if ( V_14 -> V_74 )
F_21 ( L_12 , V_14 -> V_74 ) ;
return 0 ;
}
int F_23 ( unsigned int V_45 )
{
unsigned int V_47 = F_17 ( V_45 ) ;
unsigned int V_48 = F_16 ( V_45 ) ;
if ( V_48 == V_50 )
return V_82 ;
if ( V_48 == V_51 || V_48 == V_52 )
return V_83 ;
if ( ( V_47 & 0x30 ) == V_84 )
return V_83 ;
if ( ( V_47 & 0x30 ) == V_85 )
return V_86 ;
if ( V_47 == V_87 )
return V_88 ;
if ( V_47 == V_89 )
return V_90 ;
return V_91 ;
}
static const char * F_24 ( struct V_20 * V_21 ,
T_1 V_12 , bool V_92 )
{
unsigned int V_45 ;
static const char * const V_93 [] = {
L_13 , L_14 , L_15 , L_16 , L_17
} ;
int V_94 ;
V_45 = F_15 ( V_21 , V_12 ) ;
switch ( F_18 ( V_45 ) ) {
case V_58 :
if ( ! V_92 )
return L_15 ;
V_94 = F_23 ( V_45 ) ;
if ( ! V_94 )
return L_18 ;
return V_93 [ V_94 - 1 ] ;
case V_60 :
if ( ! V_92 )
return L_19 ;
V_94 = F_23 ( V_45 ) ;
if ( ! V_94 )
return L_18 ;
if ( V_94 == V_86 )
return L_20 ;
return L_19 ;
case V_64 :
return L_21 ;
case V_62 :
return L_22 ;
case V_72 :
return L_23 ;
case V_73 :
return L_24 ;
case V_26 :
return L_25 ;
default:
return L_26 ;
}
}
static int F_25 ( struct V_20 * V_21 ,
const struct V_13 * V_14 ,
int V_95 )
{
unsigned int V_96 ;
int V_11 , V_94 , V_97 ;
V_96 = F_15 ( V_21 , V_14 -> V_17 [ V_95 ] . V_12 ) ;
V_94 = F_23 ( V_96 ) ;
if ( V_94 <= V_91 )
return 1 ;
V_94 = 0 ;
for ( V_11 = 0 ; V_11 < V_14 -> V_15 ; V_11 ++ ) {
V_96 = F_15 ( V_21 , V_14 -> V_17 [ V_11 ] . V_12 ) ;
V_97 = F_23 ( V_96 ) ;
if ( V_97 >= V_91 ) {
if ( V_94 && V_94 != V_97 )
return 1 ;
V_94 = V_97 ;
}
}
return 0 ;
}
const char * F_22 ( struct V_20 * V_21 ,
const struct V_13 * V_14 ,
int V_95 )
{
int type = V_14 -> V_17 [ V_95 ] . type ;
int V_98 = 0 ;
if ( ( V_95 > 0 && V_14 -> V_17 [ V_95 - 1 ] . type == type ) ||
( V_95 < V_14 -> V_15 - 1 && V_14 -> V_17 [ V_95 + 1 ] . type == type ) )
V_98 = 1 ;
if ( V_98 && type == V_59 )
V_98 &= F_25 ( V_21 , V_14 , V_95 ) ;
return F_24 ( V_21 , V_14 -> V_17 [ V_95 ] . V_12 ,
V_98 ) ;
}
static int F_26 ( T_1 V_1 , const T_1 * V_2 , int V_19 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_19 ; V_11 ++ )
if ( V_2 [ V_11 ] == V_1 )
return V_11 ;
return - 1 ;
}
static const char * F_27 ( T_1 V_1 , const T_1 * V_9 ,
int V_10 , int * V_99 )
{
static const char * const V_100 [] = {
L_27 , L_28 , L_29 , L_30
} ;
int V_11 ;
V_11 = F_26 ( V_1 , V_9 , V_10 ) ;
if ( V_11 < 0 )
return NULL ;
if ( V_10 == 1 )
return L_31 ;
if ( V_10 > F_11 ( V_100 ) ) {
if ( V_99 )
* V_99 = V_11 ;
return L_31 ;
}
return V_100 [ V_11 ] ;
}
static const char * F_28 ( struct V_20 * V_21 , T_1 V_1 )
{
unsigned int V_45 = F_15 ( V_21 , V_1 ) ;
int V_94 = F_23 ( V_45 ) ;
switch ( V_94 ) {
case V_86 :
return L_32 ;
case V_90 :
return L_33 ;
}
return L_31 ;
}
static int F_29 ( struct V_20 * V_21 , T_1 V_1 ,
const T_1 * V_9 , int V_10 )
{
int V_11 , V_101 , V_102 = 0 ;
const char * V_103 = F_28 ( V_21 , V_1 ) ;
V_11 = F_26 ( V_1 , V_9 , V_10 ) ;
if ( V_11 < 0 )
return - 1 ;
for ( V_101 = 0 ; V_101 < V_11 ; V_101 ++ )
if ( V_103 == F_28 ( V_21 , V_9 [ V_101 ] ) )
V_102 ++ ;
return V_102 ;
}
static int F_30 ( struct V_20 * V_21 , T_1 V_1 ,
const struct V_13 * V_14 ,
const char * V_104 , char * V_105 , int V_106 ,
int * V_99 )
{
unsigned int V_45 = F_15 ( V_21 , V_1 ) ;
int V_94 = F_23 ( V_45 ) ;
const char * V_103 , * V_107 = L_31 ;
if ( ! strcmp ( V_104 , L_34 ) && V_94 == V_83 )
V_104 = L_35 ;
V_103 = F_28 ( V_21 , V_1 ) ;
if ( V_14 ) {
V_107 = F_27 ( V_1 , V_14 -> V_36 , V_14 -> V_55 ,
V_99 ) ;
if ( ! V_107 )
V_107 = F_27 ( V_1 , V_14 -> V_38 , V_14 -> V_56 ,
V_99 ) ;
if ( ! V_107 ) {
int V_102 = F_29 ( V_21 , V_1 , V_14 -> V_40 ,
V_14 -> V_57 ) ;
if ( V_102 >= 0 )
* V_99 = V_102 ;
V_107 = L_31 ;
}
}
snprintf ( V_105 , V_106 , L_36 , V_103 , V_104 , V_107 ) ;
return 1 ;
}
int F_31 ( struct V_20 * V_21 , T_1 V_1 ,
const struct V_13 * V_14 ,
char * V_105 , int V_106 , int * V_99 )
{
unsigned int V_45 = F_15 ( V_21 , V_1 ) ;
const char * V_104 = NULL ;
int V_11 ;
bool V_108 ;
if ( V_99 )
* V_99 = 0 ;
if ( F_16 ( V_45 ) == V_50 )
return 0 ;
switch ( F_18 ( V_45 ) ) {
case V_24 :
return F_30 ( V_21 , V_1 , V_14 , L_34 ,
V_105 , V_106 , V_99 ) ;
case V_25 :
return F_30 ( V_21 , V_1 , V_14 , L_35 ,
V_105 , V_106 , V_99 ) ;
case V_26 :
return F_30 ( V_21 , V_1 , V_14 , L_37 ,
V_105 , V_106 , V_99 ) ;
case V_27 :
case V_28 :
V_108 = F_32 ( V_45 ) ;
V_104 = V_108 ? L_38 : L_39 ;
if ( V_14 && V_99 )
for ( V_11 = 0 ; V_11 < V_14 -> V_66 ; V_11 ++ ) {
T_1 V_12 = V_14 -> V_67 [ V_11 ] ;
unsigned int V_109 ;
if ( V_12 == V_1 )
break;
V_109 = F_15 ( V_21 , V_12 ) ;
if ( V_108 == F_32 ( V_109 ) )
( * V_99 ) ++ ;
}
break;
default:
if ( V_14 ) {
for ( V_11 = 0 ; V_11 < V_14 -> V_15 ; V_11 ++ ) {
if ( V_14 -> V_17 [ V_11 ] . V_12 != V_1 )
continue;
V_104 = F_22 ( V_21 , V_14 , V_11 ) ;
if ( V_104 )
break;
}
}
if ( ! V_104 )
V_104 = F_24 ( V_21 , V_1 , true ) ;
break;
}
if ( ! V_104 )
return 0 ;
F_33 ( V_105 , V_104 , V_106 ) ;
return 1 ;
}
int F_34 ( struct V_20 * V_21 ,
const struct V_110 * V_2 )
{
const struct V_110 * * V_111 ;
V_111 = F_35 ( & V_21 -> V_112 ) ;
if ( ! V_111 )
return - V_113 ;
* V_111 = V_2 ;
return 0 ;
}
void F_36 ( struct V_20 * V_21 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_21 -> V_112 . V_114 ; V_11 ++ ) {
struct V_110 * * V_111 = F_37 ( & V_21 -> V_112 , V_11 ) ;
F_38 ( V_21 , * V_111 ) ;
}
}
void F_39 ( struct V_20 * V_21 ,
const struct V_115 * V_14 )
{
for (; V_14 -> V_1 ; V_14 ++ )
F_40 ( V_21 , V_14 -> V_1 , V_14 -> V_116 ) ;
}
static void F_41 ( struct V_20 * V_21 ,
const struct V_115 * V_14 )
{
for (; V_14 -> V_1 ; V_14 ++ )
F_42 ( V_21 , V_14 -> V_1 , V_14 -> V_116 ) ;
}
static void F_43 ( struct V_20 * V_21 , int V_117 , int V_118 , int V_119 )
{
const char * V_120 = V_21 -> V_121 ;
while ( V_117 >= 0 ) {
const struct V_122 * V_123 = V_21 -> V_124 + V_117 ;
if ( V_123 -> V_125 )
F_43 ( V_21 , V_123 -> V_126 , V_118 , V_119 + 1 ) ;
switch ( V_123 -> type ) {
case V_127 :
if ( V_118 != V_128 || ! V_123 -> V_111 . V_9 )
break;
F_44 (KERN_INFO SFX
L_40 ,
codec->chip_name, modelname) ;
F_39 ( V_21 , V_123 -> V_111 . V_9 ) ;
break;
case V_129 :
if ( V_118 != V_130 || ! V_123 -> V_111 . V_112 )
break;
F_44 (KERN_INFO SFX
L_41 ,
codec->chip_name, modelname) ;
F_34 ( V_21 , V_123 -> V_111 . V_112 ) ;
break;
case V_131 :
if ( ! V_123 -> V_111 . V_132 )
break;
F_44 (KERN_INFO SFX
L_42 ,
codec->chip_name, modelname) ;
V_123 -> V_111 . V_132 ( V_21 , V_123 , V_118 ) ;
break;
case V_133 :
if ( V_118 != V_130 || ! V_123 -> V_111 . V_9 )
break;
F_44 (KERN_INFO SFX
L_43 ,
codec->chip_name, modelname) ;
F_41 ( V_21 , V_123 -> V_111 . V_9 ) ;
break;
default:
F_45 (KERN_ERR SFX
L_44 ,
codec->chip_name, fix->type) ;
break;
}
if ( ! V_123 -> V_134 || V_123 -> V_125 )
break;
if ( ++ V_119 > 10 )
break;
V_117 = V_123 -> V_126 ;
}
}
void F_46 ( struct V_20 * V_21 , int V_118 )
{
if ( V_21 -> V_124 )
F_43 ( V_21 , V_21 -> V_135 , V_118 , 0 ) ;
}
void F_47 ( struct V_20 * V_21 ,
const struct V_136 * V_137 ,
const struct V_138 * V_139 ,
const struct V_122 * V_140 )
{
const struct V_138 * V_141 ;
int V_117 = - 1 ;
const char * V_104 = NULL ;
if ( V_21 -> V_120 && ! strcmp ( V_21 -> V_120 , L_45 ) ) {
V_21 -> V_124 = NULL ;
V_21 -> V_135 = - 1 ;
return;
}
if ( V_21 -> V_120 && V_137 ) {
while ( V_137 -> V_104 ) {
if ( ! strcmp ( V_21 -> V_120 , V_137 -> V_104 ) ) {
V_117 = V_137 -> V_117 ;
V_104 = V_137 -> V_104 ;
break;
}
V_137 ++ ;
}
}
if ( V_117 < 0 && V_139 ) {
V_141 = F_48 ( V_21 -> V_142 -> V_143 , V_139 ) ;
if ( V_141 ) {
V_117 = V_141 -> V_144 ;
#ifdef F_49
V_104 = V_141 -> V_104 ;
#endif
}
}
if ( V_117 < 0 && V_139 ) {
for ( V_141 = V_139 ; V_141 -> V_145 ; V_141 ++ ) {
unsigned int V_146 =
V_141 -> V_147 | ( V_141 -> V_145 << 16 ) ;
unsigned int V_148 = 0xffff0000 | V_141 -> V_149 ;
if ( ( V_21 -> V_150 & V_148 ) == ( V_146 & V_148 ) ) {
V_117 = V_141 -> V_144 ;
#ifdef F_49
V_104 = V_141 -> V_104 ;
#endif
break;
}
}
}
V_21 -> V_135 = V_117 ;
if ( V_117 >= 0 ) {
V_21 -> V_124 = V_140 ;
V_21 -> V_121 = V_104 ;
}
}
