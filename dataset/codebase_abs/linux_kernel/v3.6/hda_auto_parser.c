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
V_19 -> V_30 = true ;
V_22 = V_19 -> V_31 + V_19 -> V_32 ;
for ( V_1 = V_19 -> V_31 ; V_1 < V_22 ; V_1 ++ ) {
unsigned int V_33 = F_8 ( V_19 , V_1 ) ;
unsigned int V_34 = F_9 ( V_33 ) ;
unsigned int V_35 ;
short V_36 , V_37 , V_38 , V_39 ;
if ( V_34 != V_40 )
continue;
if ( V_20 && F_1 ( V_1 , V_20 ) )
continue;
V_35 = F_10 ( V_19 , V_1 ) ;
if ( ! ( F_11 ( F_10 ( V_19 , V_1 ) ) &
V_41 ) )
V_19 -> V_30 = false ;
V_38 = F_12 ( V_35 ) ;
if ( V_38 == V_42 )
continue;
V_37 = F_13 ( V_35 ) ;
V_39 = F_14 ( V_35 ) ;
if ( V_39 == V_43 ) {
if ( V_38 == V_44 )
V_39 = V_45 ;
}
switch ( V_39 ) {
case V_43 :
V_8 = F_15 ( V_35 ) ;
V_36 = F_16 ( V_35 ) ;
if ( ! ( V_33 & V_46 ) )
if ( ! V_10 -> V_47 )
V_10 -> V_47 = V_1 ;
if ( ! V_36 )
continue;
if ( ! V_23 )
V_23 = V_36 ;
else if ( V_23 != V_36 )
continue;
if ( V_10 -> V_48 >= F_7 ( V_10 -> V_25 ) )
continue;
V_10 -> V_25 [ V_10 -> V_48 ] = V_1 ;
V_24 [ V_10 -> V_48 ] = V_8 ;
V_10 -> V_48 ++ ;
break;
case V_45 :
V_8 = F_15 ( V_35 ) ;
V_36 = F_16 ( V_35 ) ;
if ( V_10 -> V_49 >= F_7 ( V_10 -> V_27 ) )
continue;
V_10 -> V_27 [ V_10 -> V_49 ] = V_1 ;
V_26 [ V_10 -> V_49 ] = ( V_36 << 4 ) | V_8 ;
V_10 -> V_49 ++ ;
break;
case V_50 :
V_8 = F_15 ( V_35 ) ;
V_36 = F_16 ( V_35 ) ;
if ( V_10 -> V_51 >= F_7 ( V_10 -> V_29 ) )
continue;
V_10 -> V_29 [ V_10 -> V_51 ] = V_1 ;
V_28 [ V_10 -> V_51 ] = ( V_36 << 4 ) | V_8 ;
V_10 -> V_51 ++ ;
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
F_3 ( V_10 , V_1 , V_59 ) ;
break;
case V_60 :
case V_61 :
if ( V_10 -> V_62 >= F_7 ( V_10 -> V_63 ) )
continue;
V_10 -> V_63 [ V_10 -> V_62 ] = V_1 ;
V_10 -> V_64 [ V_10 -> V_62 ] =
( V_37 == V_65 ) ?
V_66 : V_67 ;
V_10 -> V_62 ++ ;
break;
case V_68 :
case V_69 :
V_10 -> V_70 = V_1 ;
if ( V_37 == V_65 )
V_10 -> V_71 = V_66 ;
else
V_10 -> V_71 = V_67 ;
break;
}
}
if ( ! V_10 -> V_48 && V_10 -> V_51 > 1 &&
! ( V_21 & V_72 ) ) {
int V_6 = 0 ;
while ( V_6 < V_10 -> V_51 ) {
if ( ( V_28 [ V_6 ] & 0x0f ) == 0x0f ) {
V_6 ++ ;
continue;
}
V_10 -> V_25 [ V_10 -> V_48 ] = V_10 -> V_29 [ V_6 ] ;
V_24 [ V_10 -> V_48 ] = V_28 [ V_6 ] ;
V_10 -> V_48 ++ ;
V_10 -> V_51 -- ;
memmove ( V_10 -> V_29 + V_6 , V_10 -> V_29 + V_6 + 1 ,
sizeof( V_10 -> V_29 [ 0 ] ) * ( V_10 -> V_51 - V_6 ) ) ;
memmove ( V_28 + V_6 , V_28 + V_6 + 1 ,
sizeof( V_28 [ 0 ] ) * ( V_10 -> V_51 - V_6 ) ) ;
}
memset ( V_10 -> V_29 + V_10 -> V_51 , 0 ,
sizeof( T_1 ) * ( V_73 - V_10 -> V_51 ) ) ;
if ( ! V_10 -> V_51 )
V_10 -> V_74 = V_75 ;
}
F_2 ( V_10 -> V_25 , V_24 ,
V_10 -> V_48 ) ;
F_2 ( V_10 -> V_27 , V_26 ,
V_10 -> V_49 ) ;
F_2 ( V_10 -> V_29 , V_28 ,
V_10 -> V_51 ) ;
if ( ! V_10 -> V_48 &&
! ( V_21 & V_76 ) ) {
if ( V_10 -> V_49 ) {
V_10 -> V_48 = V_10 -> V_49 ;
memcpy ( V_10 -> V_25 , V_10 -> V_27 ,
sizeof( V_10 -> V_27 ) ) ;
V_10 -> V_49 = 0 ;
memset ( V_10 -> V_27 , 0 , sizeof( V_10 -> V_27 ) ) ;
V_10 -> V_74 = V_77 ;
} else if ( V_10 -> V_51 ) {
V_10 -> V_48 = V_10 -> V_51 ;
memcpy ( V_10 -> V_25 , V_10 -> V_29 ,
sizeof( V_10 -> V_29 ) ) ;
V_10 -> V_51 = 0 ;
memset ( V_10 -> V_29 , 0 , sizeof( V_10 -> V_29 ) ) ;
V_10 -> V_74 = V_75 ;
}
}
F_5 ( V_10 -> V_48 , V_10 -> V_25 ) ;
F_5 ( V_10 -> V_51 , V_10 -> V_29 ) ;
F_5 ( V_10 -> V_49 , V_10 -> V_27 ) ;
F_4 ( V_10 ) ;
F_17 ( L_1 ,
V_10 -> V_48 , V_10 -> V_25 [ 0 ] , V_10 -> V_25 [ 1 ] ,
V_10 -> V_25 [ 2 ] , V_10 -> V_25 [ 3 ] ,
V_10 -> V_25 [ 4 ] ,
V_10 -> V_74 == V_75 ? L_2 :
( V_10 -> V_74 == V_77 ?
L_3 : L_4 ) ) ;
F_17 ( L_5 ,
V_10 -> V_49 , V_10 -> V_27 [ 0 ] ,
V_10 -> V_27 [ 1 ] , V_10 -> V_27 [ 2 ] ,
V_10 -> V_27 [ 3 ] , V_10 -> V_27 [ 4 ] ) ;
F_17 ( L_6 ,
V_10 -> V_51 , V_10 -> V_29 [ 0 ] ,
V_10 -> V_29 [ 1 ] , V_10 -> V_29 [ 2 ] ,
V_10 -> V_29 [ 3 ] , V_10 -> V_29 [ 4 ] ) ;
F_17 ( L_7 , V_10 -> V_47 ) ;
if ( V_10 -> V_62 )
F_17 ( L_8 ,
V_10 -> V_63 [ 0 ] , V_10 -> V_63 [ 1 ] ) ;
F_17 ( L_9 ) ;
for ( V_6 = 0 ; V_6 < V_10 -> V_11 ; V_6 ++ ) {
F_17 ( L_10 ,
F_18 ( V_19 , V_10 , V_6 ) ,
V_10 -> V_13 [ V_6 ] . V_14 ) ;
}
if ( V_10 -> V_70 )
F_17 ( L_11 , V_10 -> V_70 ) ;
return 0 ;
}
int F_19 ( unsigned int V_35 )
{
unsigned int V_37 = F_13 ( V_35 ) ;
unsigned int V_38 = F_12 ( V_35 ) ;
if ( V_38 == V_42 )
return V_78 ;
if ( V_38 == V_44 || V_38 == V_79 )
return V_80 ;
if ( ( V_37 & 0x30 ) == V_81 )
return V_80 ;
if ( ( V_37 & 0x30 ) == V_82 )
return V_83 ;
if ( V_37 == V_84 )
return V_85 ;
if ( V_37 == V_86 )
return V_87 ;
return V_88 ;
}
static const char * F_20 ( struct V_18 * V_19 ,
T_1 V_14 , bool V_89 )
{
unsigned int V_35 ;
static const char * const V_90 [] = {
L_12 , L_13 , L_14 , L_15 , L_16 ,
} ;
int V_91 ;
V_35 = F_10 ( V_19 , V_14 ) ;
switch ( F_14 ( V_35 ) ) {
case V_52 :
if ( ! V_89 )
return L_14 ;
V_91 = F_19 ( V_35 ) ;
if ( ! V_91 )
return L_17 ;
return V_90 [ V_91 - 1 ] ;
case V_54 :
if ( ! V_89 )
return L_18 ;
V_91 = F_19 ( V_35 ) ;
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
static int F_21 ( struct V_18 * V_19 ,
const struct V_9 * V_10 ,
int V_92 )
{
unsigned int V_93 ;
int V_6 , V_91 , V_94 ;
V_93 = F_10 ( V_19 , V_10 -> V_13 [ V_92 ] . V_14 ) ;
V_91 = F_19 ( V_93 ) ;
if ( V_91 <= V_88 )
return 1 ;
V_91 = 0 ;
for ( V_6 = 0 ; V_6 < V_10 -> V_11 ; V_6 ++ ) {
V_93 = F_10 ( V_19 , V_10 -> V_13 [ V_6 ] . V_14 ) ;
V_94 = F_19 ( V_93 ) ;
if ( V_94 >= V_88 ) {
if ( V_91 && V_91 != V_94 )
return 1 ;
V_91 = V_94 ;
}
}
return 0 ;
}
const char * F_18 ( struct V_18 * V_19 ,
const struct V_9 * V_10 ,
int V_92 )
{
int type = V_10 -> V_13 [ V_92 ] . type ;
int V_95 = 0 ;
if ( ( V_92 > 0 && V_10 -> V_13 [ V_92 - 1 ] . type == type ) ||
( V_92 < V_10 -> V_11 - 1 && V_10 -> V_13 [ V_92 + 1 ] . type == type ) )
V_95 = 1 ;
if ( V_95 && type == V_53 )
V_95 &= F_21 ( V_19 , V_10 , V_92 ) ;
return F_20 ( V_19 , V_10 -> V_13 [ V_92 ] . V_14 ,
V_95 ) ;
}
static int F_22 ( T_1 V_1 , const T_1 * V_2 , int V_17 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_17 ; V_6 ++ )
if ( V_2 [ V_6 ] == V_1 )
return V_6 ;
return - 1 ;
}
static const char * F_23 ( T_1 V_1 , const T_1 * V_3 ,
int V_5 , int * V_96 )
{
static const char * const V_97 [] = {
L_25 , L_26 , L_27 , L_28
} ;
int V_6 ;
V_6 = F_22 ( V_1 , V_3 , V_5 ) ;
if ( V_6 < 0 )
return NULL ;
if ( V_5 == 1 )
return L_29 ;
if ( V_5 > F_7 ( V_97 ) ) {
if ( V_96 )
* V_96 = V_6 ;
return L_29 ;
}
return V_97 [ V_6 ] ;
}
static int F_24 ( struct V_18 * V_19 , T_1 V_1 ,
const struct V_9 * V_10 ,
const char * V_98 , char * V_99 , int V_100 ,
int * V_96 )
{
unsigned int V_35 = F_10 ( V_19 , V_1 ) ;
int V_91 = F_19 ( V_35 ) ;
const char * V_101 = L_29 , * V_102 = L_29 ;
if ( ! strcmp ( V_98 , L_30 ) && V_91 == V_80 )
V_98 = L_31 ;
switch ( V_91 ) {
case V_83 :
V_101 = L_32 ;
break;
case V_87 :
V_101 = L_33 ;
break;
}
if ( V_10 ) {
V_102 = F_23 ( V_1 , V_10 -> V_25 , V_10 -> V_48 ,
V_96 ) ;
if ( ! V_102 )
V_102 = F_23 ( V_1 , V_10 -> V_27 , V_10 -> V_49 ,
V_96 ) ;
if ( ! V_102 ) {
int V_103 = F_22 ( V_1 , V_10 -> V_29 ,
V_10 -> V_51 ) ;
if ( V_103 >= 0 )
* V_96 = V_103 ;
V_102 = L_29 ;
}
}
snprintf ( V_99 , V_100 , L_34 , V_101 , V_98 , V_102 ) ;
return 1 ;
}
int F_25 ( struct V_18 * V_19 , T_1 V_1 ,
const struct V_9 * V_10 ,
char * V_99 , int V_100 , int * V_96 )
{
unsigned int V_35 = F_10 ( V_19 , V_1 ) ;
const char * V_98 = NULL ;
int V_6 ;
if ( V_96 )
* V_96 = 0 ;
if ( F_12 ( V_35 ) == V_42 )
return 0 ;
switch ( F_14 ( V_35 ) ) {
case V_43 :
return F_24 ( V_19 , V_1 , V_10 , L_30 ,
V_99 , V_100 , V_96 ) ;
case V_45 :
return F_24 ( V_19 , V_1 , V_10 , L_31 ,
V_99 , V_100 , V_96 ) ;
case V_50 :
return F_24 ( V_19 , V_1 , V_10 , L_35 ,
V_99 , V_100 , V_96 ) ;
case V_60 :
case V_61 :
if ( F_13 ( V_35 ) == V_65 )
V_98 = L_36 ;
else
V_98 = L_37 ;
if ( V_10 && V_96 ) {
V_6 = F_22 ( V_1 , V_10 -> V_63 ,
V_10 -> V_62 ) ;
if ( V_6 >= 0 )
* V_96 = V_6 ;
}
break;
default:
if ( V_10 ) {
for ( V_6 = 0 ; V_6 < V_10 -> V_11 ; V_6 ++ ) {
if ( V_10 -> V_13 [ V_6 ] . V_14 != V_1 )
continue;
V_98 = F_18 ( V_19 , V_10 , V_6 ) ;
if ( V_98 )
break;
}
}
if ( ! V_98 )
V_98 = F_20 ( V_19 , V_1 , true ) ;
break;
}
if ( ! V_98 )
return 0 ;
F_26 ( V_99 , V_98 , V_100 ) ;
return 1 ;
}
int F_27 ( struct V_104 * V_105 ,
const struct V_106 * V_2 )
{
const struct V_106 * * V_107 ;
V_107 = F_28 ( & V_105 -> V_108 ) ;
if ( ! V_107 )
return - V_109 ;
* V_107 = V_2 ;
return 0 ;
}
void F_29 ( struct V_18 * V_19 )
{
struct V_104 * V_105 = V_19 -> V_105 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_105 -> V_108 . V_110 ; V_6 ++ ) {
struct V_106 * * V_107 = F_30 ( & V_105 -> V_108 , V_6 ) ;
F_31 ( V_19 , * V_107 ) ;
}
}
void F_32 ( struct V_18 * V_19 ,
const struct V_111 * V_10 )
{
for (; V_10 -> V_1 ; V_10 ++ )
F_33 ( V_19 , V_10 -> V_1 , V_10 -> V_112 ) ;
}
void F_34 ( struct V_18 * V_19 , int V_113 )
{
struct V_104 * V_105 = V_19 -> V_105 ;
int V_114 = V_105 -> V_115 ;
#ifdef F_35
const char * V_116 = V_105 -> V_117 ;
#endif
int V_118 = 0 ;
if ( ! V_105 -> V_119 )
return;
while ( V_114 >= 0 ) {
const struct V_120 * V_121 = V_105 -> V_119 + V_114 ;
switch ( V_121 -> type ) {
case V_122 :
if ( V_113 != V_123 || ! V_121 -> V_107 . V_3 )
break;
F_36 (KERN_INFO SFX
L_38 ,
codec->chip_name, modelname) ;
F_32 ( V_19 , V_121 -> V_107 . V_3 ) ;
break;
case V_124 :
if ( V_113 != V_125 || ! V_121 -> V_107 . V_108 )
break;
F_36 (KERN_INFO SFX
L_39 ,
codec->chip_name, modelname) ;
F_27 ( V_19 -> V_105 , V_121 -> V_107 . V_108 ) ;
break;
case V_126 :
if ( ! V_121 -> V_107 . V_127 )
break;
F_36 (KERN_INFO SFX
L_40 ,
codec->chip_name, modelname) ;
V_121 -> V_107 . V_127 ( V_19 , V_121 , V_113 ) ;
break;
default:
F_37 (KERN_ERR SFX
L_41 ,
codec->chip_name, fix->type) ;
break;
}
if ( ! V_121 -> V_128 )
break;
if ( ++ V_118 > 10 )
break;
V_114 = V_121 -> V_129 ;
}
}
void F_38 ( struct V_18 * V_19 ,
const struct V_130 * V_131 ,
const struct V_132 * V_133 ,
const struct V_120 * V_134 )
{
struct V_104 * V_105 = V_19 -> V_105 ;
const struct V_132 * V_135 ;
int V_114 = - 1 ;
const char * V_98 = NULL ;
if ( V_19 -> V_116 && ! strcmp ( V_19 -> V_116 , L_42 ) ) {
V_105 -> V_119 = NULL ;
V_105 -> V_115 = - 1 ;
return;
}
if ( V_19 -> V_116 && V_131 ) {
while ( V_131 -> V_98 ) {
if ( ! strcmp ( V_19 -> V_116 , V_131 -> V_98 ) ) {
V_114 = V_131 -> V_114 ;
V_98 = V_131 -> V_98 ;
break;
}
V_131 ++ ;
}
}
if ( V_114 < 0 && V_133 ) {
V_135 = F_39 ( V_19 -> V_136 -> V_137 , V_133 ) ;
if ( V_135 ) {
V_114 = V_135 -> V_138 ;
#ifdef F_35
V_98 = V_135 -> V_98 ;
#endif
}
}
if ( V_114 < 0 && V_133 ) {
for ( V_135 = V_133 ; V_135 -> V_139 ; V_135 ++ ) {
unsigned int V_140 =
V_135 -> V_141 | ( V_135 -> V_139 << 16 ) ;
if ( V_140 == V_19 -> V_142 ) {
V_114 = V_135 -> V_138 ;
#ifdef F_35
V_98 = V_135 -> V_98 ;
#endif
break;
}
}
}
V_105 -> V_115 = V_114 ;
if ( V_114 >= 0 ) {
V_105 -> V_119 = V_134 ;
V_105 -> V_117 = V_98 ;
}
}
