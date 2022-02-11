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
static bool F_10 ( struct V_20 * V_21 ,
struct V_18 * V_31 ,
int V_32 )
{
int V_33 ;
unsigned int V_34 ;
if ( V_31 -> type != V_35 )
return false ;
if ( V_31 -> V_36 || V_31 -> V_37 )
return false ;
V_34 = F_11 ( V_21 , V_31 -> V_12 ) ;
V_33 = F_12 ( V_34 ) ;
if ( V_33 <= V_38 )
return false ;
if ( V_32 >= 0 ) {
int V_8 = F_13 ( V_34 ) ;
if ( V_8 != V_32 )
return false ;
}
return true ;
}
int F_14 ( struct V_20 * V_21 ,
struct V_13 * V_14 ,
const T_1 * V_39 ,
unsigned int V_40 )
{
T_1 V_1 , V_41 ;
short V_8 , V_42 ;
struct V_5 V_43 [ F_15 ( V_14 -> V_44 ) ] ;
struct V_5 V_45 [ F_15 ( V_14 -> V_46 ) ] ;
struct V_5 V_47 [ F_15 ( V_14 -> V_48 ) ] ;
int V_11 ;
if ( ! F_16 ( V_21 , L_1 , & V_11 ) )
V_40 = V_11 ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
memset ( V_43 , 0 , sizeof( V_43 ) ) ;
memset ( V_45 , 0 , sizeof( V_45 ) ) ;
memset ( V_47 , 0 , sizeof( V_47 ) ) ;
V_42 = 0 ;
V_41 = V_21 -> V_49 + V_21 -> V_50 ;
for ( V_1 = V_21 -> V_49 ; V_1 < V_41 ; V_1 ++ ) {
unsigned int V_51 = F_17 ( V_21 , V_1 ) ;
unsigned int V_52 = F_18 ( V_51 ) ;
unsigned int V_34 ;
short V_53 , V_54 , V_55 , V_22 ;
if ( V_52 != V_56 )
continue;
if ( V_39 && F_1 ( V_1 , V_39 ) )
continue;
V_34 = F_11 ( V_21 , V_1 ) ;
V_55 = F_19 ( V_34 ) ;
if ( V_55 == V_57 )
continue;
V_54 = F_20 ( V_34 ) ;
V_22 = F_21 ( V_34 ) ;
if ( V_22 == V_24 ) {
if ( V_55 == V_58 ||
V_55 == V_59 )
V_22 = V_25 ;
}
if ( ! F_8 ( V_21 , V_1 , V_22 ) )
continue;
switch ( V_22 ) {
case V_24 :
V_8 = F_13 ( V_34 ) ;
V_53 = F_22 ( V_34 ) ;
if ( ! ( V_51 & V_60 ) )
if ( ! V_14 -> V_61 )
V_14 -> V_61 = V_1 ;
if ( ! V_53 )
continue;
if ( ! V_42 )
V_42 = V_53 ;
else if ( V_42 != V_53 )
continue;
if ( V_14 -> V_62 >= F_15 ( V_14 -> V_44 ) )
continue;
V_43 [ V_14 -> V_62 ] . V_12 = V_1 ;
V_43 [ V_14 -> V_62 ] . V_8 = V_8 ;
V_14 -> V_62 ++ ;
break;
case V_25 :
V_8 = F_13 ( V_34 ) ;
V_53 = F_22 ( V_34 ) ;
if ( V_14 -> V_63 >= F_15 ( V_14 -> V_46 ) )
continue;
V_45 [ V_14 -> V_63 ] . V_12 = V_1 ;
V_45 [ V_14 -> V_63 ] . V_8 = ( V_53 << 4 ) | V_8 ;
V_14 -> V_63 ++ ;
break;
case V_26 :
V_8 = F_13 ( V_34 ) ;
V_53 = F_22 ( V_34 ) ;
if ( V_14 -> V_64 >= F_15 ( V_14 -> V_48 ) )
continue;
V_47 [ V_14 -> V_64 ] . V_12 = V_1 ;
V_47 [ V_14 -> V_64 ] . V_8 = ( V_53 << 4 ) | V_8 ;
V_14 -> V_64 ++ ;
break;
case V_65 :
F_5 ( V_14 , V_1 , V_35 ) ;
break;
case V_66 :
F_5 ( V_14 , V_1 , V_67 ) ;
break;
case V_68 :
F_5 ( V_14 , V_1 , V_69 ) ;
break;
case V_70 :
F_5 ( V_14 , V_1 , V_71 ) ;
break;
case V_27 :
case V_28 :
if ( V_14 -> V_72 >= F_15 ( V_14 -> V_73 ) )
continue;
V_14 -> V_73 [ V_14 -> V_72 ] = V_1 ;
V_14 -> V_74 [ V_14 -> V_72 ] =
( V_54 == V_75 ) ?
V_76 : V_77 ;
V_14 -> V_72 ++ ;
break;
case V_78 :
case V_79 :
V_14 -> V_80 = V_1 ;
if ( V_54 == V_75 )
V_14 -> V_81 = V_76 ;
else
V_14 -> V_81 = V_77 ;
break;
}
}
if ( V_40 & V_82 || V_40 & V_83 ) {
bool V_84 = ! ! ( V_40 & V_82 ) ;
bool V_85 = ! ! ( V_40 & V_83 ) ;
for ( V_11 = 0 ; ( V_84 || V_85 ) && ( V_11 < V_14 -> V_15 ) ; V_11 ++ )
if ( V_84 && F_10 ( V_21 , & V_14 -> V_17 [ V_11 ] , 0xc ) ) {
V_14 -> V_17 [ V_11 ] . V_36 = 1 ;
V_84 = false ;
} else if ( V_85 && F_10 ( V_21 , & V_14 -> V_17 [ V_11 ] , 0xd ) ) {
V_14 -> V_17 [ V_11 ] . V_37 = 1 ;
V_85 = false ;
}
for ( V_11 = 0 ; ( V_84 || V_85 ) && ( V_11 < V_14 -> V_15 ) ; V_11 ++ ) {
if ( ! F_10 ( V_21 , & V_14 -> V_17 [ V_11 ] , - 1 ) )
continue;
if ( V_84 ) {
V_14 -> V_17 [ V_11 ] . V_36 = 1 ;
V_84 = false ;
} else if ( V_85 ) {
V_14 -> V_17 [ V_11 ] . V_37 = 1 ;
V_85 = false ;
}
}
if ( V_84 )
F_23 ( L_2 ) ;
if ( V_85 )
F_23 ( L_3 ) ;
}
if ( ! V_14 -> V_62 && V_14 -> V_64 > 1 &&
! ( V_40 & V_86 ) ) {
int V_11 = 0 ;
while ( V_11 < V_14 -> V_64 ) {
if ( ( V_47 [ V_11 ] . V_8 & 0x0f ) == 0x0f ) {
V_11 ++ ;
continue;
}
V_43 [ V_14 -> V_62 ++ ] = V_47 [ V_11 ] ;
V_14 -> V_64 -- ;
memmove ( V_47 + V_11 , V_47 + V_11 + 1 ,
sizeof( V_47 [ 0 ] ) * ( V_14 -> V_64 - V_11 ) ) ;
}
memset ( V_47 + V_14 -> V_64 , 0 ,
sizeof( V_47 [ 0 ] ) * ( V_87 - V_14 -> V_64 ) ) ;
if ( ! V_14 -> V_64 )
V_14 -> V_88 = V_89 ;
}
F_3 ( V_14 -> V_44 , V_43 , V_14 -> V_62 ) ;
F_3 ( V_14 -> V_46 , V_45 ,
V_14 -> V_63 ) ;
F_3 ( V_14 -> V_48 , V_47 , V_14 -> V_64 ) ;
if ( ! V_14 -> V_62 &&
! ( V_40 & V_90 ) ) {
if ( V_14 -> V_63 ) {
V_14 -> V_62 = V_14 -> V_63 ;
memcpy ( V_14 -> V_44 , V_14 -> V_46 ,
sizeof( V_14 -> V_46 ) ) ;
V_14 -> V_63 = 0 ;
memset ( V_14 -> V_46 , 0 , sizeof( V_14 -> V_46 ) ) ;
V_14 -> V_88 = V_91 ;
} else if ( V_14 -> V_64 ) {
V_14 -> V_62 = V_14 -> V_64 ;
memcpy ( V_14 -> V_44 , V_14 -> V_48 ,
sizeof( V_14 -> V_48 ) ) ;
V_14 -> V_64 = 0 ;
memset ( V_14 -> V_48 , 0 , sizeof( V_14 -> V_48 ) ) ;
V_14 -> V_88 = V_89 ;
}
}
F_7 ( V_14 -> V_62 , V_14 -> V_44 ) ;
F_7 ( V_14 -> V_64 , V_14 -> V_48 ) ;
F_7 ( V_14 -> V_63 , V_14 -> V_46 ) ;
F_4 ( V_14 -> V_17 , V_14 -> V_15 , sizeof( V_14 -> V_17 [ 0 ] ) ,
F_6 , NULL ) ;
F_24 ( L_4 ,
V_14 -> V_62 , V_14 -> V_44 [ 0 ] , V_14 -> V_44 [ 1 ] ,
V_14 -> V_44 [ 2 ] , V_14 -> V_44 [ 3 ] ,
V_14 -> V_44 [ 4 ] ,
V_14 -> V_88 == V_89 ? L_5 :
( V_14 -> V_88 == V_91 ?
L_6 : L_7 ) ) ;
F_24 ( L_8 ,
V_14 -> V_63 , V_14 -> V_46 [ 0 ] ,
V_14 -> V_46 [ 1 ] , V_14 -> V_46 [ 2 ] ,
V_14 -> V_46 [ 3 ] , V_14 -> V_46 [ 4 ] ) ;
F_24 ( L_9 ,
V_14 -> V_64 , V_14 -> V_48 [ 0 ] ,
V_14 -> V_48 [ 1 ] , V_14 -> V_48 [ 2 ] ,
V_14 -> V_48 [ 3 ] , V_14 -> V_48 [ 4 ] ) ;
F_24 ( L_10 , V_14 -> V_61 ) ;
if ( V_14 -> V_72 )
F_24 ( L_11 ,
V_14 -> V_73 [ 0 ] , V_14 -> V_73 [ 1 ] ) ;
F_24 ( L_12 ) ;
for ( V_11 = 0 ; V_11 < V_14 -> V_15 ; V_11 ++ ) {
F_24 ( L_13 ,
F_25 ( V_21 , V_14 , V_11 ) ,
V_14 -> V_17 [ V_11 ] . V_12 ) ;
}
if ( V_14 -> V_80 )
F_24 ( L_14 , V_14 -> V_80 ) ;
return 0 ;
}
int F_12 ( unsigned int V_34 )
{
unsigned int V_54 = F_20 ( V_34 ) ;
unsigned int V_55 = F_19 ( V_34 ) ;
if ( V_55 == V_57 )
return V_92 ;
if ( V_55 == V_58 || V_55 == V_59 )
return V_93 ;
if ( ( V_54 & 0x30 ) == V_94 )
return V_93 ;
if ( ( V_54 & 0x30 ) == V_95 )
return V_38 ;
if ( V_54 == V_96 )
return V_97 ;
if ( V_54 == V_98 )
return V_99 ;
return V_100 ;
}
static const char * F_26 ( struct V_20 * V_21 ,
const struct V_18 * V_31 ,
T_1 V_12 , bool V_101 )
{
unsigned int V_34 ;
static const char * const V_102 [] = {
L_15 , L_16 , L_17 , L_18 , L_19
} ;
int V_33 ;
V_34 = F_11 ( V_21 , V_12 ) ;
switch ( F_21 ( V_34 ) ) {
case V_65 :
if ( V_31 && V_31 -> V_36 )
return L_20 ;
if ( V_31 && V_31 -> V_37 )
return L_21 ;
if ( ! V_101 )
return L_17 ;
V_33 = F_12 ( V_34 ) ;
if ( ! V_33 )
return L_22 ;
return V_102 [ V_33 - 1 ] ;
case V_66 :
if ( ! V_101 )
return L_23 ;
V_33 = F_12 ( V_34 ) ;
if ( ! V_33 )
return L_22 ;
if ( V_33 == V_38 )
return L_24 ;
return L_23 ;
case V_70 :
return L_25 ;
case V_68 :
return L_26 ;
case V_78 :
return L_27 ;
case V_79 :
return L_28 ;
case V_26 :
return L_21 ;
default:
return L_29 ;
}
}
static int F_27 ( struct V_20 * V_21 ,
const struct V_13 * V_14 ,
int V_103 )
{
unsigned int V_104 ;
int V_11 , V_33 , V_105 ;
V_104 = F_11 ( V_21 , V_14 -> V_17 [ V_103 ] . V_12 ) ;
V_33 = F_12 ( V_104 ) ;
if ( V_33 <= V_100 )
return 1 ;
V_33 = 0 ;
for ( V_11 = 0 ; V_11 < V_14 -> V_15 ; V_11 ++ ) {
V_104 = F_11 ( V_21 , V_14 -> V_17 [ V_11 ] . V_12 ) ;
V_105 = F_12 ( V_104 ) ;
if ( V_105 >= V_100 ) {
if ( V_33 && V_33 != V_105 )
return 1 ;
V_33 = V_105 ;
}
}
return 0 ;
}
const char * F_25 ( struct V_20 * V_21 ,
const struct V_13 * V_14 ,
int V_103 )
{
int type = V_14 -> V_17 [ V_103 ] . type ;
int V_106 = 0 ;
if ( ( V_103 > 0 && V_14 -> V_17 [ V_103 - 1 ] . type == type ) ||
( V_103 < V_14 -> V_15 - 1 && V_14 -> V_17 [ V_103 + 1 ] . type == type ) )
V_106 = 1 ;
if ( V_106 && type == V_35 )
V_106 &= F_27 ( V_21 , V_14 , V_103 ) ;
return F_26 ( V_21 , & V_14 -> V_17 [ V_103 ] ,
V_14 -> V_17 [ V_103 ] . V_12 ,
V_106 ) ;
}
static int F_28 ( T_1 V_1 , const T_1 * V_2 , int V_19 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_19 ; V_11 ++ )
if ( V_2 [ V_11 ] == V_1 )
return V_11 ;
return - 1 ;
}
static const char * F_29 ( T_1 V_1 , const T_1 * V_9 ,
int V_10 , int * V_107 )
{
static const char * const V_108 [] = {
L_30 , L_31 , L_32 , L_33
} ;
int V_11 ;
V_11 = F_28 ( V_1 , V_9 , V_10 ) ;
if ( V_11 < 0 )
return NULL ;
if ( V_10 == 1 )
return L_34 ;
if ( V_10 > F_15 ( V_108 ) ) {
if ( V_107 )
* V_107 = V_11 ;
return L_34 ;
}
return V_108 [ V_11 ] ;
}
static const char * F_30 ( struct V_20 * V_21 , T_1 V_1 )
{
unsigned int V_34 = F_11 ( V_21 , V_1 ) ;
int V_33 = F_12 ( V_34 ) ;
switch ( V_33 ) {
case V_38 :
return L_35 ;
case V_99 :
return L_36 ;
}
return L_34 ;
}
static int F_31 ( struct V_20 * V_21 , T_1 V_1 ,
const T_1 * V_9 , int V_10 )
{
int V_11 , V_109 , V_110 = 0 ;
const char * V_111 = F_30 ( V_21 , V_1 ) ;
V_11 = F_28 ( V_1 , V_9 , V_10 ) ;
if ( V_11 < 0 )
return - 1 ;
for ( V_109 = 0 ; V_109 < V_11 ; V_109 ++ )
if ( V_111 == F_30 ( V_21 , V_9 [ V_109 ] ) )
V_110 ++ ;
return V_110 ;
}
static int F_32 ( struct V_20 * V_21 , T_1 V_1 ,
const struct V_13 * V_14 ,
const char * V_112 , char * V_113 , int V_114 ,
int * V_107 )
{
unsigned int V_34 = F_11 ( V_21 , V_1 ) ;
int V_33 = F_12 ( V_34 ) ;
const char * V_111 , * V_115 = L_34 ;
if ( ! strcmp ( V_112 , L_37 ) && V_33 == V_93 )
V_112 = L_38 ;
V_111 = F_30 ( V_21 , V_1 ) ;
if ( V_14 ) {
V_115 = F_29 ( V_1 , V_14 -> V_44 , V_14 -> V_62 ,
V_107 ) ;
if ( ! V_115 )
V_115 = F_29 ( V_1 , V_14 -> V_46 , V_14 -> V_63 ,
V_107 ) ;
if ( ! V_115 ) {
int V_110 = F_31 ( V_21 , V_1 , V_14 -> V_48 ,
V_14 -> V_64 ) ;
if ( V_110 >= 0 )
* V_107 = V_110 ;
V_115 = L_34 ;
}
}
snprintf ( V_113 , V_114 , L_39 , V_111 , V_112 , V_115 ) ;
return 1 ;
}
int F_33 ( struct V_20 * V_21 , T_1 V_1 ,
const struct V_13 * V_14 ,
char * V_113 , int V_114 , int * V_107 )
{
unsigned int V_34 = F_11 ( V_21 , V_1 ) ;
const char * V_112 = NULL ;
int V_11 ;
bool V_116 ;
if ( V_107 )
* V_107 = 0 ;
if ( F_19 ( V_34 ) == V_57 )
return 0 ;
switch ( F_21 ( V_34 ) ) {
case V_24 :
return F_32 ( V_21 , V_1 , V_14 , L_37 ,
V_113 , V_114 , V_107 ) ;
case V_25 :
return F_32 ( V_21 , V_1 , V_14 , L_38 ,
V_113 , V_114 , V_107 ) ;
case V_26 :
return F_32 ( V_21 , V_1 , V_14 , L_40 ,
V_113 , V_114 , V_107 ) ;
case V_27 :
case V_28 :
V_116 = F_34 ( V_34 ) ;
V_112 = V_116 ? L_41 : L_42 ;
if ( V_14 && V_107 )
for ( V_11 = 0 ; V_11 < V_14 -> V_72 ; V_11 ++ ) {
T_1 V_12 = V_14 -> V_73 [ V_11 ] ;
unsigned int V_117 ;
if ( V_12 == V_1 )
break;
V_117 = F_11 ( V_21 , V_12 ) ;
if ( V_116 == F_34 ( V_117 ) )
( * V_107 ) ++ ;
}
break;
default:
if ( V_14 ) {
for ( V_11 = 0 ; V_11 < V_14 -> V_15 ; V_11 ++ ) {
if ( V_14 -> V_17 [ V_11 ] . V_12 != V_1 )
continue;
V_112 = F_25 ( V_21 , V_14 , V_11 ) ;
if ( V_112 )
break;
}
}
if ( ! V_112 )
V_112 = F_26 ( V_21 , NULL , V_1 , true ) ;
break;
}
if ( ! V_112 )
return 0 ;
F_35 ( V_113 , V_112 , V_114 ) ;
return 1 ;
}
int F_36 ( struct V_20 * V_21 ,
const struct V_118 * V_2 )
{
const struct V_118 * * V_119 ;
V_119 = F_37 ( & V_21 -> V_120 ) ;
if ( ! V_119 )
return - V_121 ;
* V_119 = V_2 ;
return 0 ;
}
void F_38 ( struct V_20 * V_21 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_21 -> V_120 . V_122 ; V_11 ++ ) {
struct V_118 * * V_119 = F_39 ( & V_21 -> V_120 , V_11 ) ;
F_40 ( V_21 , * V_119 ) ;
}
}
void F_41 ( struct V_20 * V_21 ,
const struct V_123 * V_14 )
{
for (; V_14 -> V_1 ; V_14 ++ )
F_42 ( V_21 , V_14 -> V_1 , V_14 -> V_124 ) ;
}
static void F_43 ( struct V_20 * V_21 ,
const struct V_123 * V_14 )
{
for (; V_14 -> V_1 ; V_14 ++ )
F_44 ( V_21 , V_14 -> V_1 , V_14 -> V_124 ) ;
}
static void F_45 ( struct V_20 * V_21 , int V_125 , int V_126 , int V_127 )
{
const char * V_128 = V_21 -> V_129 ;
while ( V_125 >= 0 ) {
const struct V_130 * V_131 = V_21 -> V_132 + V_125 ;
if ( V_131 -> V_133 )
F_45 ( V_21 , V_131 -> V_134 , V_126 , V_127 + 1 ) ;
switch ( V_131 -> type ) {
case V_135 :
if ( V_126 != V_136 || ! V_131 -> V_119 . V_9 )
break;
F_23 (KERN_INFO SFX
L_43 ,
codec->chip_name, modelname) ;
F_41 ( V_21 , V_131 -> V_119 . V_9 ) ;
break;
case V_137 :
if ( V_126 != V_138 || ! V_131 -> V_119 . V_120 )
break;
F_23 (KERN_INFO SFX
L_44 ,
codec->chip_name, modelname) ;
F_36 ( V_21 , V_131 -> V_119 . V_120 ) ;
break;
case V_139 :
if ( ! V_131 -> V_119 . V_140 )
break;
F_23 (KERN_INFO SFX
L_45 ,
codec->chip_name, modelname) ;
V_131 -> V_119 . V_140 ( V_21 , V_131 , V_126 ) ;
break;
case V_141 :
if ( V_126 != V_138 || ! V_131 -> V_119 . V_9 )
break;
F_23 (KERN_INFO SFX
L_46 ,
codec->chip_name, modelname) ;
F_43 ( V_21 , V_131 -> V_119 . V_9 ) ;
break;
default:
F_46 (KERN_ERR SFX
L_47 ,
codec->chip_name, fix->type) ;
break;
}
if ( ! V_131 -> V_142 || V_131 -> V_133 )
break;
if ( ++ V_127 > 10 )
break;
V_125 = V_131 -> V_134 ;
}
}
void F_47 ( struct V_20 * V_21 , int V_126 )
{
if ( V_21 -> V_132 )
F_45 ( V_21 , V_21 -> V_143 , V_126 , 0 ) ;
}
void F_48 ( struct V_20 * V_21 ,
const struct V_144 * V_145 ,
const struct V_146 * V_147 ,
const struct V_130 * V_148 )
{
const struct V_146 * V_149 ;
int V_125 = - 1 ;
const char * V_112 = NULL ;
if ( V_21 -> V_128 && ! strcmp ( V_21 -> V_128 , L_48 ) ) {
V_21 -> V_132 = NULL ;
V_21 -> V_143 = - 1 ;
return;
}
if ( V_21 -> V_128 && V_145 ) {
while ( V_145 -> V_112 ) {
if ( ! strcmp ( V_21 -> V_128 , V_145 -> V_112 ) ) {
V_125 = V_145 -> V_125 ;
V_112 = V_145 -> V_112 ;
break;
}
V_145 ++ ;
}
}
if ( V_125 < 0 && V_147 ) {
V_149 = F_49 ( V_21 -> V_150 -> V_151 , V_147 ) ;
if ( V_149 ) {
V_125 = V_149 -> V_152 ;
#ifdef F_50
V_112 = V_149 -> V_112 ;
#endif
}
}
if ( V_125 < 0 && V_147 ) {
for ( V_149 = V_147 ; V_149 -> V_153 ; V_149 ++ ) {
unsigned int V_154 =
V_149 -> V_155 | ( V_149 -> V_153 << 16 ) ;
unsigned int V_156 = 0xffff0000 | V_149 -> V_157 ;
if ( ( V_21 -> V_158 & V_156 ) == ( V_154 & V_156 ) ) {
V_125 = V_149 -> V_152 ;
#ifdef F_50
V_112 = V_149 -> V_112 ;
#endif
break;
}
}
}
V_21 -> V_143 = V_125 ;
if ( V_125 >= 0 ) {
V_21 -> V_132 = V_148 ;
V_21 -> V_129 = V_112 ;
}
}
