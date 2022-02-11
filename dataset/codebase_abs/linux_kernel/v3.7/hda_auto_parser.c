static int F_1 ( T_1 V_1 , const T_1 * V_2 )
{
for (; * V_2 ; V_2 ++ )
if ( * V_2 == V_1 )
return 1 ;
return 0 ;
}
static void F_2 ( T_1 * V_3 , short * V_4 ,
int V_5 )
{
int V_6 , V_7 ;
short V_8 ;
T_1 V_1 ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ ) {
for ( V_7 = V_6 + 1 ; V_7 < V_5 ; V_7 ++ ) {
if ( V_4 [ V_6 ] > V_4 [ V_7 ] ) {
V_8 = V_4 [ V_6 ] ;
V_4 [ V_6 ] = V_4 [ V_7 ] ;
V_4 [ V_7 ] = V_8 ;
V_1 = V_3 [ V_6 ] ;
V_3 [ V_6 ] = V_3 [ V_7 ] ;
V_3 [ V_7 ] = V_1 ;
}
}
}
}
static void F_3 ( struct V_9 * V_10 , T_1 V_1 ,
int type )
{
if ( V_10 -> V_11 < V_12 ) {
V_10 -> V_13 [ V_10 -> V_11 ] . V_14 = V_1 ;
V_10 -> V_13 [ V_10 -> V_11 ] . type = type ;
V_10 -> V_11 ++ ;
}
}
static void F_4 ( struct V_9 * V_10 )
{
int V_6 , V_7 ;
for ( V_6 = 0 ; V_6 < V_10 -> V_11 ; V_6 ++ ) {
for ( V_7 = V_6 + 1 ; V_7 < V_10 -> V_11 ; V_7 ++ ) {
if ( V_10 -> V_13 [ V_6 ] . type > V_10 -> V_13 [ V_7 ] . type ) {
struct V_15 V_16 ;
V_16 = V_10 -> V_13 [ V_6 ] ;
V_10 -> V_13 [ V_6 ] = V_10 -> V_13 [ V_7 ] ;
V_10 -> V_13 [ V_7 ] = V_16 ;
}
}
}
}
static void F_5 ( unsigned int V_17 , T_1 * V_3 )
{
T_1 V_1 ;
switch ( V_17 ) {
case 3 :
case 4 :
V_1 = V_3 [ 1 ] ;
V_3 [ 1 ] = V_3 [ 2 ] ;
V_3 [ 2 ] = V_1 ;
break;
}
}
int F_6 ( struct V_18 * V_19 ,
struct V_9 * V_10 ,
const T_1 * V_20 ,
unsigned int V_21 )
{
T_1 V_1 , V_22 ;
short V_8 , V_23 ;
short V_24 [ F_7 ( V_10 -> V_25 ) ] ;
short V_26 [ F_7 ( V_10 -> V_27 ) ] ;
short V_28 [ F_7 ( V_10 -> V_29 ) ] ;
int V_6 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
memset ( V_24 , 0 , sizeof( V_24 ) ) ;
memset ( V_26 , 0 , sizeof( V_26 ) ) ;
memset ( V_28 , 0 , sizeof( V_28 ) ) ;
V_23 = 0 ;
V_22 = V_19 -> V_30 + V_19 -> V_31 ;
for ( V_1 = V_19 -> V_30 ; V_1 < V_22 ; V_1 ++ ) {
unsigned int V_32 = F_8 ( V_19 , V_1 ) ;
unsigned int V_33 = F_9 ( V_32 ) ;
unsigned int V_34 ;
short V_35 , V_36 , V_37 , V_38 ;
if ( V_33 != V_39 )
continue;
if ( V_20 && F_1 ( V_1 , V_20 ) )
continue;
V_34 = F_10 ( V_19 , V_1 ) ;
V_37 = F_11 ( V_34 ) ;
if ( V_37 == V_40 )
continue;
V_36 = F_12 ( V_34 ) ;
V_38 = F_13 ( V_34 ) ;
if ( V_38 == V_41 ) {
if ( V_37 == V_42 )
V_38 = V_43 ;
}
switch ( V_38 ) {
case V_41 :
V_8 = F_14 ( V_34 ) ;
V_35 = F_15 ( V_34 ) ;
if ( ! ( V_32 & V_44 ) )
if ( ! V_10 -> V_45 )
V_10 -> V_45 = V_1 ;
if ( ! V_35 )
continue;
if ( ! V_23 )
V_23 = V_35 ;
else if ( V_23 != V_35 )
continue;
if ( V_10 -> V_46 >= F_7 ( V_10 -> V_25 ) )
continue;
V_10 -> V_25 [ V_10 -> V_46 ] = V_1 ;
V_24 [ V_10 -> V_46 ] = V_8 ;
V_10 -> V_46 ++ ;
break;
case V_43 :
V_8 = F_14 ( V_34 ) ;
V_35 = F_15 ( V_34 ) ;
if ( V_10 -> V_47 >= F_7 ( V_10 -> V_27 ) )
continue;
V_10 -> V_27 [ V_10 -> V_47 ] = V_1 ;
V_26 [ V_10 -> V_47 ] = ( V_35 << 4 ) | V_8 ;
V_10 -> V_47 ++ ;
break;
case V_48 :
V_8 = F_14 ( V_34 ) ;
V_35 = F_15 ( V_34 ) ;
if ( V_10 -> V_49 >= F_7 ( V_10 -> V_29 ) )
continue;
V_10 -> V_29 [ V_10 -> V_49 ] = V_1 ;
V_28 [ V_10 -> V_49 ] = ( V_35 << 4 ) | V_8 ;
V_10 -> V_49 ++ ;
break;
case V_50 :
F_3 ( V_10 , V_1 , V_51 ) ;
break;
case V_52 :
F_3 ( V_10 , V_1 , V_53 ) ;
break;
case V_54 :
F_3 ( V_10 , V_1 , V_55 ) ;
break;
case V_56 :
F_3 ( V_10 , V_1 , V_57 ) ;
break;
case V_58 :
case V_59 :
if ( V_10 -> V_60 >= F_7 ( V_10 -> V_61 ) )
continue;
V_10 -> V_61 [ V_10 -> V_60 ] = V_1 ;
V_10 -> V_62 [ V_10 -> V_60 ] =
( V_36 == V_63 ) ?
V_64 : V_65 ;
V_10 -> V_60 ++ ;
break;
case V_66 :
case V_67 :
V_10 -> V_68 = V_1 ;
if ( V_36 == V_63 )
V_10 -> V_69 = V_64 ;
else
V_10 -> V_69 = V_65 ;
break;
}
}
if ( ! V_10 -> V_46 && V_10 -> V_49 > 1 &&
! ( V_21 & V_70 ) ) {
int V_6 = 0 ;
while ( V_6 < V_10 -> V_49 ) {
if ( ( V_28 [ V_6 ] & 0x0f ) == 0x0f ) {
V_6 ++ ;
continue;
}
V_10 -> V_25 [ V_10 -> V_46 ] = V_10 -> V_29 [ V_6 ] ;
V_24 [ V_10 -> V_46 ] = V_28 [ V_6 ] ;
V_10 -> V_46 ++ ;
V_10 -> V_49 -- ;
memmove ( V_10 -> V_29 + V_6 , V_10 -> V_29 + V_6 + 1 ,
sizeof( V_10 -> V_29 [ 0 ] ) * ( V_10 -> V_49 - V_6 ) ) ;
memmove ( V_28 + V_6 , V_28 + V_6 + 1 ,
sizeof( V_28 [ 0 ] ) * ( V_10 -> V_49 - V_6 ) ) ;
}
memset ( V_10 -> V_29 + V_10 -> V_49 , 0 ,
sizeof( T_1 ) * ( V_71 - V_10 -> V_49 ) ) ;
if ( ! V_10 -> V_49 )
V_10 -> V_72 = V_73 ;
}
F_2 ( V_10 -> V_25 , V_24 ,
V_10 -> V_46 ) ;
F_2 ( V_10 -> V_27 , V_26 ,
V_10 -> V_47 ) ;
F_2 ( V_10 -> V_29 , V_28 ,
V_10 -> V_49 ) ;
if ( ! V_10 -> V_46 &&
! ( V_21 & V_74 ) ) {
if ( V_10 -> V_47 ) {
V_10 -> V_46 = V_10 -> V_47 ;
memcpy ( V_10 -> V_25 , V_10 -> V_27 ,
sizeof( V_10 -> V_27 ) ) ;
V_10 -> V_47 = 0 ;
memset ( V_10 -> V_27 , 0 , sizeof( V_10 -> V_27 ) ) ;
V_10 -> V_72 = V_75 ;
} else if ( V_10 -> V_49 ) {
V_10 -> V_46 = V_10 -> V_49 ;
memcpy ( V_10 -> V_25 , V_10 -> V_29 ,
sizeof( V_10 -> V_29 ) ) ;
V_10 -> V_49 = 0 ;
memset ( V_10 -> V_29 , 0 , sizeof( V_10 -> V_29 ) ) ;
V_10 -> V_72 = V_73 ;
}
}
F_5 ( V_10 -> V_46 , V_10 -> V_25 ) ;
F_5 ( V_10 -> V_49 , V_10 -> V_29 ) ;
F_5 ( V_10 -> V_47 , V_10 -> V_27 ) ;
F_4 ( V_10 ) ;
F_16 ( L_1 ,
V_10 -> V_46 , V_10 -> V_25 [ 0 ] , V_10 -> V_25 [ 1 ] ,
V_10 -> V_25 [ 2 ] , V_10 -> V_25 [ 3 ] ,
V_10 -> V_25 [ 4 ] ,
V_10 -> V_72 == V_73 ? L_2 :
( V_10 -> V_72 == V_75 ?
L_3 : L_4 ) ) ;
F_16 ( L_5 ,
V_10 -> V_47 , V_10 -> V_27 [ 0 ] ,
V_10 -> V_27 [ 1 ] , V_10 -> V_27 [ 2 ] ,
V_10 -> V_27 [ 3 ] , V_10 -> V_27 [ 4 ] ) ;
F_16 ( L_6 ,
V_10 -> V_49 , V_10 -> V_29 [ 0 ] ,
V_10 -> V_29 [ 1 ] , V_10 -> V_29 [ 2 ] ,
V_10 -> V_29 [ 3 ] , V_10 -> V_29 [ 4 ] ) ;
F_16 ( L_7 , V_10 -> V_45 ) ;
if ( V_10 -> V_60 )
F_16 ( L_8 ,
V_10 -> V_61 [ 0 ] , V_10 -> V_61 [ 1 ] ) ;
F_16 ( L_9 ) ;
for ( V_6 = 0 ; V_6 < V_10 -> V_11 ; V_6 ++ ) {
F_16 ( L_10 ,
F_17 ( V_19 , V_10 , V_6 ) ,
V_10 -> V_13 [ V_6 ] . V_14 ) ;
}
if ( V_10 -> V_68 )
F_16 ( L_11 , V_10 -> V_68 ) ;
return 0 ;
}
int F_18 ( unsigned int V_34 )
{
unsigned int V_36 = F_12 ( V_34 ) ;
unsigned int V_37 = F_11 ( V_34 ) ;
if ( V_37 == V_40 )
return V_76 ;
if ( V_37 == V_42 || V_37 == V_77 )
return V_78 ;
if ( ( V_36 & 0x30 ) == V_79 )
return V_78 ;
if ( ( V_36 & 0x30 ) == V_80 )
return V_81 ;
if ( V_36 == V_82 )
return V_83 ;
if ( V_36 == V_84 )
return V_85 ;
return V_86 ;
}
static const char * F_19 ( struct V_18 * V_19 ,
T_1 V_14 , bool V_87 )
{
unsigned int V_34 ;
static const char * const V_88 [] = {
L_12 , L_13 , L_14 , L_15 , L_16 ,
} ;
int V_89 ;
V_34 = F_10 ( V_19 , V_14 ) ;
switch ( F_13 ( V_34 ) ) {
case V_50 :
if ( ! V_87 )
return L_14 ;
V_89 = F_18 ( V_34 ) ;
if ( ! V_89 )
return L_17 ;
return V_88 [ V_89 - 1 ] ;
case V_52 :
if ( ! V_87 )
return L_18 ;
V_89 = F_18 ( V_34 ) ;
if ( ! V_89 )
return L_17 ;
if ( V_89 == V_81 )
return L_19 ;
return L_18 ;
case V_56 :
return L_20 ;
case V_54 :
return L_21 ;
case V_66 :
return L_22 ;
case V_67 :
return L_23 ;
default:
return L_24 ;
}
}
static int F_20 ( struct V_18 * V_19 ,
const struct V_9 * V_10 ,
int V_90 )
{
unsigned int V_91 ;
int V_6 , V_89 , V_92 ;
V_91 = F_10 ( V_19 , V_10 -> V_13 [ V_90 ] . V_14 ) ;
V_89 = F_18 ( V_91 ) ;
if ( V_89 <= V_86 )
return 1 ;
V_89 = 0 ;
for ( V_6 = 0 ; V_6 < V_10 -> V_11 ; V_6 ++ ) {
V_91 = F_10 ( V_19 , V_10 -> V_13 [ V_6 ] . V_14 ) ;
V_92 = F_18 ( V_91 ) ;
if ( V_92 >= V_86 ) {
if ( V_89 && V_89 != V_92 )
return 1 ;
V_89 = V_92 ;
}
}
return 0 ;
}
const char * F_17 ( struct V_18 * V_19 ,
const struct V_9 * V_10 ,
int V_90 )
{
int type = V_10 -> V_13 [ V_90 ] . type ;
int V_93 = 0 ;
if ( ( V_90 > 0 && V_10 -> V_13 [ V_90 - 1 ] . type == type ) ||
( V_90 < V_10 -> V_11 - 1 && V_10 -> V_13 [ V_90 + 1 ] . type == type ) )
V_93 = 1 ;
if ( V_93 && type == V_51 )
V_93 &= F_20 ( V_19 , V_10 , V_90 ) ;
return F_19 ( V_19 , V_10 -> V_13 [ V_90 ] . V_14 ,
V_93 ) ;
}
static int F_21 ( T_1 V_1 , const T_1 * V_2 , int V_17 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_17 ; V_6 ++ )
if ( V_2 [ V_6 ] == V_1 )
return V_6 ;
return - 1 ;
}
static const char * F_22 ( T_1 V_1 , const T_1 * V_3 ,
int V_5 , int * V_94 )
{
static const char * const V_95 [] = {
L_25 , L_26 , L_27 , L_28
} ;
int V_6 ;
V_6 = F_21 ( V_1 , V_3 , V_5 ) ;
if ( V_6 < 0 )
return NULL ;
if ( V_5 == 1 )
return L_29 ;
if ( V_5 > F_7 ( V_95 ) ) {
if ( V_94 )
* V_94 = V_6 ;
return L_29 ;
}
return V_95 [ V_6 ] ;
}
static const char * F_23 ( struct V_18 * V_19 , T_1 V_1 )
{
unsigned int V_34 = F_10 ( V_19 , V_1 ) ;
int V_89 = F_18 ( V_34 ) ;
switch ( V_89 ) {
case V_81 :
return L_30 ;
case V_85 :
return L_31 ;
}
return L_29 ;
}
static int F_24 ( struct V_18 * V_19 , T_1 V_1 ,
const T_1 * V_3 , int V_5 )
{
int V_6 , V_7 , V_96 = 0 ;
const char * V_97 = F_23 ( V_19 , V_1 ) ;
V_6 = F_21 ( V_1 , V_3 , V_5 ) ;
if ( V_6 < 0 )
return - 1 ;
for ( V_7 = 0 ; V_7 < V_6 ; V_7 ++ )
if ( V_97 == F_23 ( V_19 , V_3 [ V_7 ] ) )
V_96 ++ ;
return V_96 ;
}
static int F_25 ( struct V_18 * V_19 , T_1 V_1 ,
const struct V_9 * V_10 ,
const char * V_98 , char * V_99 , int V_100 ,
int * V_94 )
{
unsigned int V_34 = F_10 ( V_19 , V_1 ) ;
int V_89 = F_18 ( V_34 ) ;
const char * V_97 , * V_101 = L_29 ;
if ( ! strcmp ( V_98 , L_32 ) && V_89 == V_78 )
V_98 = L_33 ;
V_97 = F_23 ( V_19 , V_1 ) ;
if ( V_10 ) {
V_101 = F_22 ( V_1 , V_10 -> V_25 , V_10 -> V_46 ,
V_94 ) ;
if ( ! V_101 )
V_101 = F_22 ( V_1 , V_10 -> V_27 , V_10 -> V_47 ,
V_94 ) ;
if ( ! V_101 ) {
int V_96 = F_24 ( V_19 , V_1 , V_10 -> V_29 ,
V_10 -> V_49 ) ;
if ( V_96 >= 0 )
* V_94 = V_96 ;
V_101 = L_29 ;
}
}
snprintf ( V_99 , V_100 , L_34 , V_97 , V_98 , V_101 ) ;
return 1 ;
}
int F_26 ( struct V_18 * V_19 , T_1 V_1 ,
const struct V_9 * V_10 ,
char * V_99 , int V_100 , int * V_94 )
{
unsigned int V_34 = F_10 ( V_19 , V_1 ) ;
const char * V_98 = NULL ;
int V_6 ;
if ( V_94 )
* V_94 = 0 ;
if ( F_11 ( V_34 ) == V_40 )
return 0 ;
switch ( F_13 ( V_34 ) ) {
case V_41 :
return F_25 ( V_19 , V_1 , V_10 , L_32 ,
V_99 , V_100 , V_94 ) ;
case V_43 :
return F_25 ( V_19 , V_1 , V_10 , L_33 ,
V_99 , V_100 , V_94 ) ;
case V_48 :
return F_25 ( V_19 , V_1 , V_10 , L_35 ,
V_99 , V_100 , V_94 ) ;
case V_58 :
case V_59 :
if ( F_12 ( V_34 ) == V_63 )
V_98 = L_36 ;
else
V_98 = L_37 ;
if ( V_10 && V_94 ) {
V_6 = F_21 ( V_1 , V_10 -> V_61 ,
V_10 -> V_60 ) ;
if ( V_6 >= 0 )
* V_94 = V_6 ;
}
break;
default:
if ( V_10 ) {
for ( V_6 = 0 ; V_6 < V_10 -> V_11 ; V_6 ++ ) {
if ( V_10 -> V_13 [ V_6 ] . V_14 != V_1 )
continue;
V_98 = F_17 ( V_19 , V_10 , V_6 ) ;
if ( V_98 )
break;
}
}
if ( ! V_98 )
V_98 = F_19 ( V_19 , V_1 , true ) ;
break;
}
if ( ! V_98 )
return 0 ;
F_27 ( V_99 , V_98 , V_100 ) ;
return 1 ;
}
int F_28 ( struct V_102 * V_103 ,
const struct V_104 * V_2 )
{
const struct V_104 * * V_105 ;
V_105 = F_29 ( & V_103 -> V_106 ) ;
if ( ! V_105 )
return - V_107 ;
* V_105 = V_2 ;
return 0 ;
}
void F_30 ( struct V_18 * V_19 )
{
struct V_102 * V_103 = V_19 -> V_103 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_103 -> V_106 . V_108 ; V_6 ++ ) {
struct V_104 * * V_105 = F_31 ( & V_103 -> V_106 , V_6 ) ;
F_32 ( V_19 , * V_105 ) ;
}
}
void F_33 ( struct V_18 * V_19 ,
const struct V_109 * V_10 )
{
for (; V_10 -> V_1 ; V_10 ++ )
F_34 ( V_19 , V_10 -> V_1 , V_10 -> V_110 ) ;
}
void F_35 ( struct V_18 * V_19 , int V_111 )
{
struct V_102 * V_103 = V_19 -> V_103 ;
int V_112 = V_103 -> V_113 ;
#ifdef F_36
const char * V_114 = V_103 -> V_115 ;
#endif
int V_116 = 0 ;
if ( ! V_103 -> V_117 )
return;
while ( V_112 >= 0 ) {
const struct V_118 * V_119 = V_103 -> V_117 + V_112 ;
switch ( V_119 -> type ) {
case V_120 :
if ( V_111 != V_121 || ! V_119 -> V_105 . V_3 )
break;
F_37 (KERN_INFO SFX
L_38 ,
codec->chip_name, modelname) ;
F_33 ( V_19 , V_119 -> V_105 . V_3 ) ;
break;
case V_122 :
if ( V_111 != V_123 || ! V_119 -> V_105 . V_106 )
break;
F_37 (KERN_INFO SFX
L_39 ,
codec->chip_name, modelname) ;
F_28 ( V_19 -> V_103 , V_119 -> V_105 . V_106 ) ;
break;
case V_124 :
if ( ! V_119 -> V_105 . V_125 )
break;
F_37 (KERN_INFO SFX
L_40 ,
codec->chip_name, modelname) ;
V_119 -> V_105 . V_125 ( V_19 , V_119 , V_111 ) ;
break;
default:
F_38 (KERN_ERR SFX
L_41 ,
codec->chip_name, fix->type) ;
break;
}
if ( ! V_119 -> V_126 )
break;
if ( ++ V_116 > 10 )
break;
V_112 = V_119 -> V_127 ;
}
}
void F_39 ( struct V_18 * V_19 ,
const struct V_128 * V_129 ,
const struct V_130 * V_131 ,
const struct V_118 * V_132 )
{
struct V_102 * V_103 = V_19 -> V_103 ;
const struct V_130 * V_133 ;
int V_112 = - 1 ;
const char * V_98 = NULL ;
if ( V_19 -> V_114 && ! strcmp ( V_19 -> V_114 , L_42 ) ) {
V_103 -> V_117 = NULL ;
V_103 -> V_113 = - 1 ;
return;
}
if ( V_19 -> V_114 && V_129 ) {
while ( V_129 -> V_98 ) {
if ( ! strcmp ( V_19 -> V_114 , V_129 -> V_98 ) ) {
V_112 = V_129 -> V_112 ;
V_98 = V_129 -> V_98 ;
break;
}
V_129 ++ ;
}
}
if ( V_112 < 0 && V_131 ) {
V_133 = F_40 ( V_19 -> V_134 -> V_135 , V_131 ) ;
if ( V_133 ) {
V_112 = V_133 -> V_136 ;
#ifdef F_36
V_98 = V_133 -> V_98 ;
#endif
}
}
if ( V_112 < 0 && V_131 ) {
for ( V_133 = V_131 ; V_133 -> V_137 ; V_133 ++ ) {
unsigned int V_138 =
V_133 -> V_139 | ( V_133 -> V_137 << 16 ) ;
unsigned int V_140 = 0xffff0000 | V_133 -> V_141 ;
if ( ( V_19 -> V_142 & V_140 ) == ( V_138 & V_140 ) ) {
V_112 = V_133 -> V_136 ;
#ifdef F_36
V_98 = V_133 -> V_98 ;
#endif
break;
}
}
}
V_103 -> V_113 = V_112 ;
if ( V_112 >= 0 ) {
V_103 -> V_117 = V_132 ;
V_103 -> V_115 = V_98 ;
}
}
