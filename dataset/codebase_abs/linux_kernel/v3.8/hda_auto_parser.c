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
int F_8 ( struct V_20 * V_21 ,
struct V_13 * V_14 ,
const T_1 * V_22 ,
unsigned int V_23 )
{
T_1 V_1 , V_24 ;
short V_8 , V_25 ;
struct V_5 V_26 [ F_9 ( V_14 -> V_27 ) ] ;
struct V_5 V_28 [ F_9 ( V_14 -> V_29 ) ] ;
struct V_5 V_30 [ F_9 ( V_14 -> V_31 ) ] ;
int V_11 ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
memset ( V_26 , 0 , sizeof( V_26 ) ) ;
memset ( V_28 , 0 , sizeof( V_28 ) ) ;
memset ( V_30 , 0 , sizeof( V_30 ) ) ;
V_25 = 0 ;
V_24 = V_21 -> V_32 + V_21 -> V_33 ;
for ( V_1 = V_21 -> V_32 ; V_1 < V_24 ; V_1 ++ ) {
unsigned int V_34 = F_10 ( V_21 , V_1 ) ;
unsigned int V_35 = F_11 ( V_34 ) ;
unsigned int V_36 ;
short V_37 , V_38 , V_39 , V_40 ;
if ( V_35 != V_41 )
continue;
if ( V_22 && F_1 ( V_1 , V_22 ) )
continue;
V_36 = F_12 ( V_21 , V_1 ) ;
V_39 = F_13 ( V_36 ) ;
if ( V_39 == V_42 )
continue;
V_38 = F_14 ( V_36 ) ;
V_40 = F_15 ( V_36 ) ;
if ( V_40 == V_43 ) {
if ( V_39 == V_44 )
V_40 = V_45 ;
}
switch ( V_40 ) {
case V_43 :
V_8 = F_16 ( V_36 ) ;
V_37 = F_17 ( V_36 ) ;
if ( ! ( V_34 & V_46 ) )
if ( ! V_14 -> V_47 )
V_14 -> V_47 = V_1 ;
if ( ! V_37 )
continue;
if ( ! V_25 )
V_25 = V_37 ;
else if ( V_25 != V_37 )
continue;
if ( V_14 -> V_48 >= F_9 ( V_14 -> V_27 ) )
continue;
V_26 [ V_14 -> V_48 ] . V_12 = V_1 ;
V_26 [ V_14 -> V_48 ] . V_8 = V_8 ;
V_14 -> V_48 ++ ;
break;
case V_45 :
V_8 = F_16 ( V_36 ) ;
V_37 = F_17 ( V_36 ) ;
if ( V_14 -> V_49 >= F_9 ( V_14 -> V_29 ) )
continue;
V_28 [ V_14 -> V_49 ] . V_12 = V_1 ;
V_28 [ V_14 -> V_49 ] . V_8 = ( V_37 << 4 ) | V_8 ;
V_14 -> V_49 ++ ;
break;
case V_50 :
V_8 = F_16 ( V_36 ) ;
V_37 = F_17 ( V_36 ) ;
if ( V_14 -> V_51 >= F_9 ( V_14 -> V_31 ) )
continue;
V_30 [ V_14 -> V_51 ] . V_12 = V_1 ;
V_30 [ V_14 -> V_51 ] . V_8 = ( V_37 << 4 ) | V_8 ;
V_14 -> V_51 ++ ;
break;
case V_52 :
F_5 ( V_14 , V_1 , V_53 ) ;
break;
case V_54 :
F_5 ( V_14 , V_1 , V_55 ) ;
break;
case V_56 :
F_5 ( V_14 , V_1 , V_57 ) ;
break;
case V_58 :
F_5 ( V_14 , V_1 , V_59 ) ;
break;
case V_60 :
case V_61 :
if ( V_14 -> V_62 >= F_9 ( V_14 -> V_63 ) )
continue;
V_14 -> V_63 [ V_14 -> V_62 ] = V_1 ;
V_14 -> V_64 [ V_14 -> V_62 ] =
( V_38 == V_65 ) ?
V_66 : V_67 ;
V_14 -> V_62 ++ ;
break;
case V_68 :
case V_69 :
V_14 -> V_70 = V_1 ;
if ( V_38 == V_65 )
V_14 -> V_71 = V_66 ;
else
V_14 -> V_71 = V_67 ;
break;
}
}
if ( ! V_14 -> V_48 && V_14 -> V_51 > 1 &&
! ( V_23 & V_72 ) ) {
int V_11 = 0 ;
while ( V_11 < V_14 -> V_51 ) {
if ( ( V_30 [ V_11 ] . V_8 & 0x0f ) == 0x0f ) {
V_11 ++ ;
continue;
}
V_26 [ V_14 -> V_48 ++ ] = V_30 [ V_11 ] ;
V_14 -> V_51 -- ;
memmove ( V_30 + V_11 , V_30 + V_11 + 1 ,
sizeof( V_30 [ 0 ] ) * ( V_14 -> V_51 - V_11 ) ) ;
}
memset ( V_30 + V_14 -> V_51 , 0 ,
sizeof( V_30 [ 0 ] ) * ( V_73 - V_14 -> V_51 ) ) ;
if ( ! V_14 -> V_51 )
V_14 -> V_74 = V_75 ;
}
F_3 ( V_14 -> V_27 , V_26 , V_14 -> V_48 ) ;
F_3 ( V_14 -> V_29 , V_28 ,
V_14 -> V_49 ) ;
F_3 ( V_14 -> V_31 , V_30 , V_14 -> V_51 ) ;
if ( ! V_14 -> V_48 &&
! ( V_23 & V_76 ) ) {
if ( V_14 -> V_49 ) {
V_14 -> V_48 = V_14 -> V_49 ;
memcpy ( V_14 -> V_27 , V_14 -> V_29 ,
sizeof( V_14 -> V_29 ) ) ;
V_14 -> V_49 = 0 ;
memset ( V_14 -> V_29 , 0 , sizeof( V_14 -> V_29 ) ) ;
V_14 -> V_74 = V_77 ;
} else if ( V_14 -> V_51 ) {
V_14 -> V_48 = V_14 -> V_51 ;
memcpy ( V_14 -> V_27 , V_14 -> V_31 ,
sizeof( V_14 -> V_31 ) ) ;
V_14 -> V_51 = 0 ;
memset ( V_14 -> V_31 , 0 , sizeof( V_14 -> V_31 ) ) ;
V_14 -> V_74 = V_75 ;
}
}
F_7 ( V_14 -> V_48 , V_14 -> V_27 ) ;
F_7 ( V_14 -> V_51 , V_14 -> V_31 ) ;
F_7 ( V_14 -> V_49 , V_14 -> V_29 ) ;
F_4 ( V_14 -> V_17 , V_14 -> V_15 , sizeof( V_14 -> V_17 [ 0 ] ) ,
F_6 , NULL ) ;
F_18 ( L_1 ,
V_14 -> V_48 , V_14 -> V_27 [ 0 ] , V_14 -> V_27 [ 1 ] ,
V_14 -> V_27 [ 2 ] , V_14 -> V_27 [ 3 ] ,
V_14 -> V_27 [ 4 ] ,
V_14 -> V_74 == V_75 ? L_2 :
( V_14 -> V_74 == V_77 ?
L_3 : L_4 ) ) ;
F_18 ( L_5 ,
V_14 -> V_49 , V_14 -> V_29 [ 0 ] ,
V_14 -> V_29 [ 1 ] , V_14 -> V_29 [ 2 ] ,
V_14 -> V_29 [ 3 ] , V_14 -> V_29 [ 4 ] ) ;
F_18 ( L_6 ,
V_14 -> V_51 , V_14 -> V_31 [ 0 ] ,
V_14 -> V_31 [ 1 ] , V_14 -> V_31 [ 2 ] ,
V_14 -> V_31 [ 3 ] , V_14 -> V_31 [ 4 ] ) ;
F_18 ( L_7 , V_14 -> V_47 ) ;
if ( V_14 -> V_62 )
F_18 ( L_8 ,
V_14 -> V_63 [ 0 ] , V_14 -> V_63 [ 1 ] ) ;
F_18 ( L_9 ) ;
for ( V_11 = 0 ; V_11 < V_14 -> V_15 ; V_11 ++ ) {
F_18 ( L_10 ,
F_19 ( V_21 , V_14 , V_11 ) ,
V_14 -> V_17 [ V_11 ] . V_12 ) ;
}
if ( V_14 -> V_70 )
F_18 ( L_11 , V_14 -> V_70 ) ;
return 0 ;
}
int F_20 ( unsigned int V_36 )
{
unsigned int V_38 = F_14 ( V_36 ) ;
unsigned int V_39 = F_13 ( V_36 ) ;
if ( V_39 == V_42 )
return V_78 ;
if ( V_39 == V_44 || V_39 == V_79 )
return V_80 ;
if ( ( V_38 & 0x30 ) == V_81 )
return V_80 ;
if ( ( V_38 & 0x30 ) == V_82 )
return V_83 ;
if ( V_38 == V_84 )
return V_85 ;
if ( V_38 == V_86 )
return V_87 ;
return V_88 ;
}
static const char * F_21 ( struct V_20 * V_21 ,
T_1 V_12 , bool V_89 )
{
unsigned int V_36 ;
static const char * const V_90 [] = {
L_12 , L_13 , L_14 , L_15 , L_16 ,
} ;
int V_91 ;
V_36 = F_12 ( V_21 , V_12 ) ;
switch ( F_15 ( V_36 ) ) {
case V_52 :
if ( ! V_89 )
return L_14 ;
V_91 = F_20 ( V_36 ) ;
if ( ! V_91 )
return L_17 ;
return V_90 [ V_91 - 1 ] ;
case V_54 :
if ( ! V_89 )
return L_18 ;
V_91 = F_20 ( V_36 ) ;
if ( ! V_91 )
return L_17 ;
if ( V_91 == V_83 )
return L_19 ;
return L_18 ;
case V_58 :
return L_20 ;
case V_56 :
return L_21 ;
case V_68 :
return L_22 ;
case V_69 :
return L_23 ;
default:
return L_24 ;
}
}
static int F_22 ( struct V_20 * V_21 ,
const struct V_13 * V_14 ,
int V_92 )
{
unsigned int V_93 ;
int V_11 , V_91 , V_94 ;
V_93 = F_12 ( V_21 , V_14 -> V_17 [ V_92 ] . V_12 ) ;
V_91 = F_20 ( V_93 ) ;
if ( V_91 <= V_88 )
return 1 ;
V_91 = 0 ;
for ( V_11 = 0 ; V_11 < V_14 -> V_15 ; V_11 ++ ) {
V_93 = F_12 ( V_21 , V_14 -> V_17 [ V_11 ] . V_12 ) ;
V_94 = F_20 ( V_93 ) ;
if ( V_94 >= V_88 ) {
if ( V_91 && V_91 != V_94 )
return 1 ;
V_91 = V_94 ;
}
}
return 0 ;
}
const char * F_19 ( struct V_20 * V_21 ,
const struct V_13 * V_14 ,
int V_92 )
{
int type = V_14 -> V_17 [ V_92 ] . type ;
int V_95 = 0 ;
if ( ( V_92 > 0 && V_14 -> V_17 [ V_92 - 1 ] . type == type ) ||
( V_92 < V_14 -> V_15 - 1 && V_14 -> V_17 [ V_92 + 1 ] . type == type ) )
V_95 = 1 ;
if ( V_95 && type == V_53 )
V_95 &= F_22 ( V_21 , V_14 , V_92 ) ;
return F_21 ( V_21 , V_14 -> V_17 [ V_92 ] . V_12 ,
V_95 ) ;
}
static int F_23 ( T_1 V_1 , const T_1 * V_2 , int V_19 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_19 ; V_11 ++ )
if ( V_2 [ V_11 ] == V_1 )
return V_11 ;
return - 1 ;
}
static const char * F_24 ( T_1 V_1 , const T_1 * V_9 ,
int V_10 , int * V_96 )
{
static const char * const V_97 [] = {
L_25 , L_26 , L_27 , L_28
} ;
int V_11 ;
V_11 = F_23 ( V_1 , V_9 , V_10 ) ;
if ( V_11 < 0 )
return NULL ;
if ( V_10 == 1 )
return L_29 ;
if ( V_10 > F_9 ( V_97 ) ) {
if ( V_96 )
* V_96 = V_11 ;
return L_29 ;
}
return V_97 [ V_11 ] ;
}
static const char * F_25 ( struct V_20 * V_21 , T_1 V_1 )
{
unsigned int V_36 = F_12 ( V_21 , V_1 ) ;
int V_91 = F_20 ( V_36 ) ;
switch ( V_91 ) {
case V_83 :
return L_30 ;
case V_87 :
return L_31 ;
}
return L_29 ;
}
static int F_26 ( struct V_20 * V_21 , T_1 V_1 ,
const T_1 * V_9 , int V_10 )
{
int V_11 , V_98 , V_99 = 0 ;
const char * V_100 = F_25 ( V_21 , V_1 ) ;
V_11 = F_23 ( V_1 , V_9 , V_10 ) ;
if ( V_11 < 0 )
return - 1 ;
for ( V_98 = 0 ; V_98 < V_11 ; V_98 ++ )
if ( V_100 == F_25 ( V_21 , V_9 [ V_98 ] ) )
V_99 ++ ;
return V_99 ;
}
static int F_27 ( struct V_20 * V_21 , T_1 V_1 ,
const struct V_13 * V_14 ,
const char * V_101 , char * V_102 , int V_103 ,
int * V_96 )
{
unsigned int V_36 = F_12 ( V_21 , V_1 ) ;
int V_91 = F_20 ( V_36 ) ;
const char * V_100 , * V_104 = L_29 ;
if ( ! strcmp ( V_101 , L_32 ) && V_91 == V_80 )
V_101 = L_33 ;
V_100 = F_25 ( V_21 , V_1 ) ;
if ( V_14 ) {
V_104 = F_24 ( V_1 , V_14 -> V_27 , V_14 -> V_48 ,
V_96 ) ;
if ( ! V_104 )
V_104 = F_24 ( V_1 , V_14 -> V_29 , V_14 -> V_49 ,
V_96 ) ;
if ( ! V_104 ) {
int V_99 = F_26 ( V_21 , V_1 , V_14 -> V_31 ,
V_14 -> V_51 ) ;
if ( V_99 >= 0 )
* V_96 = V_99 ;
V_104 = L_29 ;
}
}
snprintf ( V_102 , V_103 , L_34 , V_100 , V_101 , V_104 ) ;
return 1 ;
}
int F_28 ( struct V_20 * V_21 , T_1 V_1 ,
const struct V_13 * V_14 ,
char * V_102 , int V_103 , int * V_96 )
{
unsigned int V_36 = F_12 ( V_21 , V_1 ) ;
const char * V_101 = NULL ;
int V_11 ;
if ( V_96 )
* V_96 = 0 ;
if ( F_13 ( V_36 ) == V_42 )
return 0 ;
switch ( F_15 ( V_36 ) ) {
case V_43 :
return F_27 ( V_21 , V_1 , V_14 , L_32 ,
V_102 , V_103 , V_96 ) ;
case V_45 :
return F_27 ( V_21 , V_1 , V_14 , L_33 ,
V_102 , V_103 , V_96 ) ;
case V_50 :
return F_27 ( V_21 , V_1 , V_14 , L_35 ,
V_102 , V_103 , V_96 ) ;
case V_60 :
case V_61 :
if ( F_14 ( V_36 ) == V_65 )
V_101 = L_36 ;
else
V_101 = L_37 ;
if ( V_14 && V_96 ) {
V_11 = F_23 ( V_1 , V_14 -> V_63 ,
V_14 -> V_62 ) ;
if ( V_11 >= 0 )
* V_96 = V_11 ;
}
break;
default:
if ( V_14 ) {
for ( V_11 = 0 ; V_11 < V_14 -> V_15 ; V_11 ++ ) {
if ( V_14 -> V_17 [ V_11 ] . V_12 != V_1 )
continue;
V_101 = F_19 ( V_21 , V_14 , V_11 ) ;
if ( V_101 )
break;
}
}
if ( ! V_101 )
V_101 = F_21 ( V_21 , V_1 , true ) ;
break;
}
if ( ! V_101 )
return 0 ;
F_29 ( V_102 , V_101 , V_103 ) ;
return 1 ;
}
int F_30 ( struct V_105 * V_106 ,
const struct V_107 * V_2 )
{
const struct V_107 * * V_108 ;
V_108 = F_31 ( & V_106 -> V_109 ) ;
if ( ! V_108 )
return - V_110 ;
* V_108 = V_2 ;
return 0 ;
}
void F_32 ( struct V_20 * V_21 )
{
struct V_105 * V_106 = V_21 -> V_106 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_106 -> V_109 . V_111 ; V_11 ++ ) {
struct V_107 * * V_108 = F_33 ( & V_106 -> V_109 , V_11 ) ;
F_34 ( V_21 , * V_108 ) ;
}
}
void F_35 ( struct V_20 * V_21 ,
const struct V_112 * V_14 )
{
for (; V_14 -> V_1 ; V_14 ++ )
F_36 ( V_21 , V_14 -> V_1 , V_14 -> V_113 ) ;
}
void F_37 ( struct V_20 * V_21 , int V_114 )
{
struct V_105 * V_106 = V_21 -> V_106 ;
int V_115 = V_106 -> V_116 ;
#ifdef F_38
const char * V_117 = V_106 -> V_118 ;
#endif
int V_119 = 0 ;
if ( ! V_106 -> V_120 )
return;
while ( V_115 >= 0 ) {
const struct V_121 * V_122 = V_106 -> V_120 + V_115 ;
switch ( V_122 -> type ) {
case V_123 :
if ( V_114 != V_124 || ! V_122 -> V_108 . V_9 )
break;
F_39 (KERN_INFO SFX
L_38 ,
codec->chip_name, modelname) ;
F_35 ( V_21 , V_122 -> V_108 . V_9 ) ;
break;
case V_125 :
if ( V_114 != V_126 || ! V_122 -> V_108 . V_109 )
break;
F_39 (KERN_INFO SFX
L_39 ,
codec->chip_name, modelname) ;
F_30 ( V_21 -> V_106 , V_122 -> V_108 . V_109 ) ;
break;
case V_127 :
if ( ! V_122 -> V_108 . V_128 )
break;
F_39 (KERN_INFO SFX
L_40 ,
codec->chip_name, modelname) ;
V_122 -> V_108 . V_128 ( V_21 , V_122 , V_114 ) ;
break;
default:
F_40 (KERN_ERR SFX
L_41 ,
codec->chip_name, fix->type) ;
break;
}
if ( ! V_122 -> V_129 )
break;
if ( ++ V_119 > 10 )
break;
V_115 = V_122 -> V_130 ;
}
}
void F_41 ( struct V_20 * V_21 ,
const struct V_131 * V_132 ,
const struct V_133 * V_134 ,
const struct V_121 * V_135 )
{
struct V_105 * V_106 = V_21 -> V_106 ;
const struct V_133 * V_136 ;
int V_115 = - 1 ;
const char * V_101 = NULL ;
if ( V_21 -> V_117 && ! strcmp ( V_21 -> V_117 , L_42 ) ) {
V_106 -> V_120 = NULL ;
V_106 -> V_116 = - 1 ;
return;
}
if ( V_21 -> V_117 && V_132 ) {
while ( V_132 -> V_101 ) {
if ( ! strcmp ( V_21 -> V_117 , V_132 -> V_101 ) ) {
V_115 = V_132 -> V_115 ;
V_101 = V_132 -> V_101 ;
break;
}
V_132 ++ ;
}
}
if ( V_115 < 0 && V_134 ) {
V_136 = F_42 ( V_21 -> V_137 -> V_138 , V_134 ) ;
if ( V_136 ) {
V_115 = V_136 -> V_139 ;
#ifdef F_38
V_101 = V_136 -> V_101 ;
#endif
}
}
if ( V_115 < 0 && V_134 ) {
for ( V_136 = V_134 ; V_136 -> V_140 ; V_136 ++ ) {
unsigned int V_141 =
V_136 -> V_142 | ( V_136 -> V_140 << 16 ) ;
unsigned int V_143 = 0xffff0000 | V_136 -> V_144 ;
if ( ( V_21 -> V_145 & V_143 ) == ( V_141 & V_143 ) ) {
V_115 = V_136 -> V_139 ;
#ifdef F_38
V_101 = V_136 -> V_101 ;
#endif
break;
}
}
}
V_106 -> V_116 = V_115 ;
if ( V_115 >= 0 ) {
V_106 -> V_120 = V_135 ;
V_106 -> V_118 = V_101 ;
}
}
