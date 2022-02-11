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
static void F_5 ( struct V_13 * V_14 , struct V_15 * V_16 ,
T_1 V_1 , int type )
{
if ( V_16 -> V_17 < V_18 ) {
V_16 -> V_19 [ V_16 -> V_17 ] . V_12 = V_1 ;
V_16 -> V_19 [ V_16 -> V_17 ] . type = type ;
V_16 -> V_19 [ V_16 -> V_17 ] . V_20 =
F_6 ( V_14 , V_1 , V_21 ) ;
V_16 -> V_17 ++ ;
}
}
static int F_7 ( const void * V_3 , const void * V_4 )
{
const struct V_22 * V_6 = V_3 ;
const struct V_22 * V_7 = V_4 ;
if ( V_6 -> type != V_7 -> type )
return ( int ) ( V_6 -> type - V_7 -> type ) ;
return ( int ) ( V_7 -> V_20 - V_6 -> V_20 ) ;
}
static void F_8 ( unsigned int V_23 , T_1 * V_9 )
{
T_1 V_1 ;
switch ( V_23 ) {
case 3 :
case 4 :
V_1 = V_9 [ 1 ] ;
V_9 [ 1 ] = V_9 [ 2 ] ;
V_9 [ 2 ] = V_1 ;
break;
}
}
static bool F_9 ( struct V_13 * V_14 , T_1 V_12 ,
unsigned int V_24 )
{
unsigned int V_25 = F_10 ( V_14 , V_12 ) ;
if ( ! V_25 )
return true ;
switch ( V_24 ) {
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
return ! ! ( V_25 & V_31 ) ;
default:
return ! ! ( V_25 & V_32 ) ;
}
}
static bool F_11 ( struct V_13 * V_14 ,
struct V_22 * V_33 ,
int V_34 )
{
int V_35 ;
unsigned int V_36 ;
if ( V_33 -> type != V_37 )
return false ;
if ( V_33 -> V_38 || V_33 -> V_39 )
return false ;
V_36 = F_12 ( V_14 , V_33 -> V_12 ) ;
V_35 = F_13 ( V_36 ) ;
if ( V_35 <= V_40 )
return false ;
if ( V_34 >= 0 ) {
int V_8 = F_14 ( V_36 ) ;
if ( V_8 != V_34 )
return false ;
}
return true ;
}
int F_15 ( struct V_13 * V_14 ,
struct V_15 * V_16 ,
const T_1 * V_41 ,
unsigned int V_42 )
{
T_1 V_1 , V_43 ;
short V_8 , V_44 ;
struct V_5 V_45 [ F_16 ( V_16 -> V_46 ) ] ;
struct V_5 V_47 [ F_16 ( V_16 -> V_48 ) ] ;
struct V_5 V_49 [ F_16 ( V_16 -> V_50 ) ] ;
int V_11 ;
if ( ! F_17 ( V_14 , L_1 , & V_11 ) )
V_42 = V_11 ;
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
memset ( V_45 , 0 , sizeof( V_45 ) ) ;
memset ( V_47 , 0 , sizeof( V_47 ) ) ;
memset ( V_49 , 0 , sizeof( V_49 ) ) ;
V_44 = 0 ;
V_43 = V_14 -> V_51 + V_14 -> V_52 ;
for ( V_1 = V_14 -> V_51 ; V_1 < V_43 ; V_1 ++ ) {
unsigned int V_53 = F_18 ( V_14 , V_1 ) ;
unsigned int V_54 = F_19 ( V_53 ) ;
unsigned int V_36 ;
short V_55 , V_56 , V_57 , V_24 ;
if ( V_54 != V_58 )
continue;
if ( V_41 && F_1 ( V_1 , V_41 ) )
continue;
V_36 = F_12 ( V_14 , V_1 ) ;
V_57 = F_20 ( V_36 ) ;
if ( V_57 == V_59 )
continue;
V_56 = F_21 ( V_36 ) ;
V_24 = F_22 ( V_36 ) ;
if ( V_24 == V_26 ) {
if ( V_57 == V_60 ||
V_57 == V_61 )
V_24 = V_27 ;
}
if ( ! F_9 ( V_14 , V_1 , V_24 ) )
continue;
switch ( V_24 ) {
case V_26 :
V_8 = F_14 ( V_36 ) ;
V_55 = F_23 ( V_36 ) ;
if ( ! ( V_53 & V_62 ) )
if ( ! V_16 -> V_63 )
V_16 -> V_63 = V_1 ;
if ( ! V_55 )
continue;
if ( ! V_44 )
V_44 = V_55 ;
else if ( V_44 != V_55 ) {
F_24 ( V_14 ,
L_2 ,
V_1 , V_55 , V_44 ) ;
continue;
}
if ( V_16 -> V_64 >= F_16 ( V_16 -> V_46 ) ) {
F_24 ( V_14 ,
L_3 ,
V_1 ) ;
continue;
}
V_45 [ V_16 -> V_64 ] . V_12 = V_1 ;
V_45 [ V_16 -> V_64 ] . V_8 = V_8 ;
V_16 -> V_64 ++ ;
break;
case V_27 :
V_8 = F_14 ( V_36 ) ;
V_55 = F_23 ( V_36 ) ;
if ( V_16 -> V_65 >= F_16 ( V_16 -> V_48 ) ) {
F_24 ( V_14 ,
L_3 ,
V_1 ) ;
continue;
}
V_47 [ V_16 -> V_65 ] . V_12 = V_1 ;
V_47 [ V_16 -> V_65 ] . V_8 = ( V_55 << 4 ) | V_8 ;
V_16 -> V_65 ++ ;
break;
case V_28 :
V_8 = F_14 ( V_36 ) ;
V_55 = F_23 ( V_36 ) ;
if ( V_16 -> V_66 >= F_16 ( V_16 -> V_50 ) ) {
F_24 ( V_14 ,
L_3 ,
V_1 ) ;
continue;
}
V_49 [ V_16 -> V_66 ] . V_12 = V_1 ;
V_49 [ V_16 -> V_66 ] . V_8 = ( V_55 << 4 ) | V_8 ;
V_16 -> V_66 ++ ;
break;
case V_67 :
F_5 ( V_14 , V_16 , V_1 , V_37 ) ;
break;
case V_68 :
F_5 ( V_14 , V_16 , V_1 , V_69 ) ;
break;
case V_70 :
F_5 ( V_14 , V_16 , V_1 , V_71 ) ;
break;
case V_72 :
F_5 ( V_14 , V_16 , V_1 , V_73 ) ;
break;
case V_29 :
case V_30 :
if ( V_16 -> V_74 >= F_16 ( V_16 -> V_75 ) ) {
F_24 ( V_14 ,
L_3 ,
V_1 ) ;
continue;
}
V_16 -> V_75 [ V_16 -> V_74 ] = V_1 ;
V_16 -> V_76 [ V_16 -> V_74 ] =
( V_56 == V_77 ) ?
V_78 : V_79 ;
V_16 -> V_74 ++ ;
break;
case V_80 :
case V_81 :
V_16 -> V_82 = V_1 ;
if ( V_56 == V_77 )
V_16 -> V_83 = V_78 ;
else
V_16 -> V_83 = V_79 ;
break;
}
}
if ( V_42 & V_84 || V_42 & V_85 ) {
bool V_86 = ! ! ( V_42 & V_84 ) ;
bool V_87 = ! ! ( V_42 & V_85 ) ;
for ( V_11 = 0 ; ( V_86 || V_87 ) && ( V_11 < V_16 -> V_17 ) ; V_11 ++ )
if ( V_86 && F_11 ( V_14 , & V_16 -> V_19 [ V_11 ] , 0xc ) ) {
V_16 -> V_19 [ V_11 ] . V_38 = 1 ;
V_86 = false ;
} else if ( V_87 && F_11 ( V_14 , & V_16 -> V_19 [ V_11 ] , 0xd ) ) {
V_16 -> V_19 [ V_11 ] . V_39 = 1 ;
V_87 = false ;
}
for ( V_11 = 0 ; ( V_86 || V_87 ) && ( V_11 < V_16 -> V_17 ) ; V_11 ++ ) {
if ( ! F_11 ( V_14 , & V_16 -> V_19 [ V_11 ] , - 1 ) )
continue;
if ( V_86 ) {
V_16 -> V_19 [ V_11 ] . V_38 = 1 ;
V_86 = false ;
} else if ( V_87 ) {
V_16 -> V_19 [ V_11 ] . V_39 = 1 ;
V_87 = false ;
}
}
if ( V_86 )
F_25 ( V_14 , L_4 ) ;
if ( V_87 )
F_25 ( V_14 , L_5 ) ;
}
if ( ! V_16 -> V_64 && V_16 -> V_66 > 1 &&
! ( V_42 & V_88 ) ) {
int V_11 = 0 ;
while ( V_11 < V_16 -> V_66 ) {
if ( ( V_49 [ V_11 ] . V_8 & 0x0f ) == 0x0f ) {
V_11 ++ ;
continue;
}
V_45 [ V_16 -> V_64 ++ ] = V_49 [ V_11 ] ;
V_16 -> V_66 -- ;
memmove ( V_49 + V_11 , V_49 + V_11 + 1 ,
sizeof( V_49 [ 0 ] ) * ( V_16 -> V_66 - V_11 ) ) ;
}
memset ( V_49 + V_16 -> V_66 , 0 ,
sizeof( V_49 [ 0 ] ) * ( V_89 - V_16 -> V_66 ) ) ;
if ( ! V_16 -> V_66 )
V_16 -> V_90 = V_91 ;
}
F_3 ( V_16 -> V_46 , V_45 , V_16 -> V_64 ) ;
F_3 ( V_16 -> V_48 , V_47 ,
V_16 -> V_65 ) ;
F_3 ( V_16 -> V_50 , V_49 , V_16 -> V_66 ) ;
if ( ! V_16 -> V_64 &&
! ( V_42 & V_92 ) ) {
if ( V_16 -> V_65 ) {
V_16 -> V_64 = V_16 -> V_65 ;
memcpy ( V_16 -> V_46 , V_16 -> V_48 ,
sizeof( V_16 -> V_48 ) ) ;
V_16 -> V_65 = 0 ;
memset ( V_16 -> V_48 , 0 , sizeof( V_16 -> V_48 ) ) ;
V_16 -> V_90 = V_93 ;
} else if ( V_16 -> V_66 ) {
V_16 -> V_64 = V_16 -> V_66 ;
memcpy ( V_16 -> V_46 , V_16 -> V_50 ,
sizeof( V_16 -> V_50 ) ) ;
V_16 -> V_66 = 0 ;
memset ( V_16 -> V_50 , 0 , sizeof( V_16 -> V_50 ) ) ;
V_16 -> V_90 = V_91 ;
}
}
F_8 ( V_16 -> V_64 , V_16 -> V_46 ) ;
F_8 ( V_16 -> V_66 , V_16 -> V_50 ) ;
F_8 ( V_16 -> V_65 , V_16 -> V_48 ) ;
F_4 ( V_16 -> V_19 , V_16 -> V_17 , sizeof( V_16 -> V_19 [ 0 ] ) ,
F_7 , NULL ) ;
F_24 ( V_14 , L_6 ,
V_16 -> V_64 , V_16 -> V_46 [ 0 ] , V_16 -> V_46 [ 1 ] ,
V_16 -> V_46 [ 2 ] , V_16 -> V_46 [ 3 ] ,
V_16 -> V_46 [ 4 ] ,
V_16 -> V_90 == V_91 ? L_7 :
( V_16 -> V_90 == V_93 ?
L_8 : L_9 ) ) ;
F_24 ( V_14 , L_10 ,
V_16 -> V_65 , V_16 -> V_48 [ 0 ] ,
V_16 -> V_48 [ 1 ] , V_16 -> V_48 [ 2 ] ,
V_16 -> V_48 [ 3 ] , V_16 -> V_48 [ 4 ] ) ;
F_24 ( V_14 , L_11 ,
V_16 -> V_66 , V_16 -> V_50 [ 0 ] ,
V_16 -> V_50 [ 1 ] , V_16 -> V_50 [ 2 ] ,
V_16 -> V_50 [ 3 ] , V_16 -> V_50 [ 4 ] ) ;
F_24 ( V_14 , L_12 , V_16 -> V_63 ) ;
if ( V_16 -> V_74 )
F_24 ( V_14 , L_13 ,
V_16 -> V_75 [ 0 ] , V_16 -> V_75 [ 1 ] ) ;
F_24 ( V_14 , L_14 ) ;
for ( V_11 = 0 ; V_11 < V_16 -> V_17 ; V_11 ++ ) {
F_24 ( V_14 , L_15 ,
F_26 ( V_14 , V_16 , V_11 ) ,
V_16 -> V_19 [ V_11 ] . V_12 ) ;
}
if ( V_16 -> V_82 )
F_24 ( V_14 , L_16 , V_16 -> V_82 ) ;
return 0 ;
}
int F_13 ( unsigned int V_36 )
{
unsigned int V_56 = F_21 ( V_36 ) ;
unsigned int V_57 = F_20 ( V_36 ) ;
if ( V_57 == V_59 )
return V_94 ;
if ( V_57 == V_60 || V_57 == V_61 )
return V_95 ;
if ( ( V_56 & 0x30 ) == V_96 )
return V_95 ;
if ( ( V_56 & 0x30 ) == V_97 )
return V_40 ;
if ( V_56 == V_98 )
return V_99 ;
if ( V_56 == V_100 )
return V_101 ;
return V_102 ;
}
static const char * F_27 ( struct V_13 * V_14 ,
const struct V_22 * V_33 ,
T_1 V_12 , bool V_103 )
{
unsigned int V_36 ;
static const char * const V_104 [] = {
L_17 , L_18 , L_19 , L_20 , L_21
} ;
int V_35 ;
V_36 = F_12 ( V_14 , V_12 ) ;
switch ( F_22 ( V_36 ) ) {
case V_67 :
if ( V_33 && V_33 -> V_38 )
return L_22 ;
if ( V_33 && V_33 -> V_39 )
return L_23 ;
if ( ! V_103 )
return L_19 ;
V_35 = F_13 ( V_36 ) ;
if ( ! V_35 )
return L_24 ;
return V_104 [ V_35 - 1 ] ;
case V_68 :
if ( ! V_103 )
return L_25 ;
V_35 = F_13 ( V_36 ) ;
if ( ! V_35 )
return L_24 ;
if ( V_35 == V_40 )
return L_26 ;
return L_25 ;
case V_72 :
return L_27 ;
case V_70 :
return L_28 ;
case V_80 :
return L_29 ;
case V_81 :
return L_30 ;
case V_28 :
return L_23 ;
default:
return L_31 ;
}
}
static int F_28 ( struct V_13 * V_14 ,
const struct V_15 * V_16 ,
int V_105 )
{
unsigned int V_106 ;
int V_11 , V_35 , V_107 ;
V_106 = F_12 ( V_14 , V_16 -> V_19 [ V_105 ] . V_12 ) ;
V_35 = F_13 ( V_106 ) ;
if ( V_35 <= V_102 )
return 1 ;
V_35 = 0 ;
for ( V_11 = 0 ; V_11 < V_16 -> V_17 ; V_11 ++ ) {
V_106 = F_12 ( V_14 , V_16 -> V_19 [ V_11 ] . V_12 ) ;
V_107 = F_13 ( V_106 ) ;
if ( V_107 >= V_102 ) {
if ( V_35 && V_35 != V_107 )
return 1 ;
V_35 = V_107 ;
}
}
return 0 ;
}
const char * F_26 ( struct V_13 * V_14 ,
const struct V_15 * V_16 ,
int V_105 )
{
int type = V_16 -> V_19 [ V_105 ] . type ;
int V_108 = 0 ;
if ( ( V_105 > 0 && V_16 -> V_19 [ V_105 - 1 ] . type == type ) ||
( V_105 < V_16 -> V_17 - 1 && V_16 -> V_19 [ V_105 + 1 ] . type == type ) )
V_108 = 1 ;
if ( V_108 && type == V_37 )
V_108 &= F_28 ( V_14 , V_16 , V_105 ) ;
return F_27 ( V_14 , & V_16 -> V_19 [ V_105 ] ,
V_16 -> V_19 [ V_105 ] . V_12 ,
V_108 ) ;
}
static int F_29 ( T_1 V_1 , const T_1 * V_2 , int V_23 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_23 ; V_11 ++ )
if ( V_2 [ V_11 ] == V_1 )
return V_11 ;
return - 1 ;
}
static const char * F_30 ( T_1 V_1 , const T_1 * V_9 ,
int V_10 , int * V_109 )
{
static const char * const V_110 [] = {
L_32 , L_33 , L_34 , L_35
} ;
int V_11 ;
V_11 = F_29 ( V_1 , V_9 , V_10 ) ;
if ( V_11 < 0 )
return NULL ;
if ( V_10 == 1 )
return L_36 ;
if ( V_10 > F_16 ( V_110 ) ) {
if ( V_109 )
* V_109 = V_11 ;
return L_36 ;
}
return V_110 [ V_11 ] ;
}
static const char * F_31 ( struct V_13 * V_14 , T_1 V_1 )
{
unsigned int V_36 = F_12 ( V_14 , V_1 ) ;
int V_35 = F_13 ( V_36 ) ;
switch ( V_35 ) {
case V_40 :
return L_37 ;
case V_101 :
return L_38 ;
}
return L_36 ;
}
static int F_32 ( struct V_13 * V_14 , T_1 V_1 ,
const T_1 * V_9 , int V_10 )
{
int V_11 , V_111 , V_112 = 0 ;
const char * V_113 = F_31 ( V_14 , V_1 ) ;
V_11 = F_29 ( V_1 , V_9 , V_10 ) ;
if ( V_11 < 0 )
return - 1 ;
for ( V_111 = 0 ; V_111 < V_11 ; V_111 ++ )
if ( V_113 == F_31 ( V_14 , V_9 [ V_111 ] ) )
V_112 ++ ;
return V_112 ;
}
static int F_33 ( struct V_13 * V_14 , T_1 V_1 ,
const struct V_15 * V_16 ,
const char * V_114 , char * V_115 , int V_116 ,
int * V_109 )
{
unsigned int V_36 = F_12 ( V_14 , V_1 ) ;
int V_35 = F_13 ( V_36 ) ;
const char * V_113 , * V_117 = L_36 ;
if ( ! strcmp ( V_114 , L_39 ) && V_35 == V_95 )
V_114 = L_40 ;
V_113 = F_31 ( V_14 , V_1 ) ;
if ( V_16 ) {
V_117 = F_30 ( V_1 , V_16 -> V_46 , V_16 -> V_64 ,
V_109 ) ;
if ( ! V_117 )
V_117 = F_30 ( V_1 , V_16 -> V_48 , V_16 -> V_65 ,
V_109 ) ;
if ( ! V_117 ) {
int V_112 = F_32 ( V_14 , V_1 , V_16 -> V_50 ,
V_16 -> V_66 ) ;
if ( V_112 >= 0 && V_109 )
* V_109 = V_112 ;
V_117 = L_36 ;
}
}
snprintf ( V_115 , V_116 , L_41 , V_113 , V_114 , V_117 ) ;
return 1 ;
}
int F_34 ( struct V_13 * V_14 , T_1 V_1 ,
const struct V_15 * V_16 ,
char * V_115 , int V_116 , int * V_109 )
{
unsigned int V_36 = F_12 ( V_14 , V_1 ) ;
const char * V_114 = NULL ;
int V_11 ;
bool V_118 ;
if ( V_109 )
* V_109 = 0 ;
if ( F_20 ( V_36 ) == V_59 )
return 0 ;
switch ( F_22 ( V_36 ) ) {
case V_26 :
return F_33 ( V_14 , V_1 , V_16 , L_39 ,
V_115 , V_116 , V_109 ) ;
case V_27 :
return F_33 ( V_14 , V_1 , V_16 , L_40 ,
V_115 , V_116 , V_109 ) ;
case V_28 :
return F_33 ( V_14 , V_1 , V_16 , L_42 ,
V_115 , V_116 , V_109 ) ;
case V_29 :
case V_30 :
V_118 = F_35 ( V_36 ) ;
V_114 = V_118 ? L_43 : L_44 ;
if ( V_16 && V_109 )
for ( V_11 = 0 ; V_11 < V_16 -> V_74 ; V_11 ++ ) {
T_1 V_12 = V_16 -> V_75 [ V_11 ] ;
unsigned int V_119 ;
if ( V_12 == V_1 )
break;
V_119 = F_12 ( V_14 , V_12 ) ;
if ( V_118 == F_35 ( V_119 ) )
( * V_109 ) ++ ;
}
break;
default:
if ( V_16 ) {
for ( V_11 = 0 ; V_11 < V_16 -> V_17 ; V_11 ++ ) {
if ( V_16 -> V_19 [ V_11 ] . V_12 != V_1 )
continue;
V_114 = F_26 ( V_14 , V_16 , V_11 ) ;
if ( V_114 )
break;
}
}
if ( ! V_114 )
V_114 = F_27 ( V_14 , NULL , V_1 , true ) ;
break;
}
if ( ! V_114 )
return 0 ;
F_36 ( V_115 , V_114 , V_116 ) ;
return 1 ;
}
int F_37 ( struct V_13 * V_14 ,
const struct V_120 * V_2 )
{
const struct V_120 * * V_121 ;
V_121 = F_38 ( & V_14 -> V_122 ) ;
if ( ! V_121 )
return - V_123 ;
* V_121 = V_2 ;
return 0 ;
}
void F_39 ( struct V_13 * V_14 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_14 -> V_122 . V_124 ; V_11 ++ ) {
struct V_120 * * V_121 = F_40 ( & V_14 -> V_122 , V_11 ) ;
F_41 ( V_14 , * V_121 ) ;
}
}
void F_42 ( struct V_13 * V_14 ,
const struct V_125 * V_16 )
{
for (; V_16 -> V_1 ; V_16 ++ )
F_43 ( V_14 , V_16 -> V_1 , V_16 -> V_126 ) ;
}
static void F_44 ( struct V_13 * V_14 ,
const struct V_125 * V_16 )
{
for (; V_16 -> V_1 ; V_16 ++ )
F_45 ( V_14 , V_16 -> V_1 , V_16 -> V_126 ) ;
}
static void F_46 ( struct V_13 * V_14 , int V_127 , int V_128 , int V_129 )
{
const char * V_130 = V_14 -> V_131 ;
while ( V_127 >= 0 ) {
const struct V_132 * V_133 = V_14 -> V_134 + V_127 ;
if ( V_133 -> V_135 )
F_46 ( V_14 , V_133 -> V_136 , V_128 , V_129 + 1 ) ;
switch ( V_133 -> type ) {
case V_137 :
if ( V_128 != V_138 || ! V_133 -> V_121 . V_9 )
break;
F_25 ( V_14 , L_45 ,
V_14 -> V_139 , V_130 ) ;
F_42 ( V_14 , V_133 -> V_121 . V_9 ) ;
break;
case V_140 :
if ( V_128 != V_141 || ! V_133 -> V_121 . V_122 )
break;
F_25 ( V_14 , L_46 ,
V_14 -> V_139 , V_130 ) ;
F_37 ( V_14 , V_133 -> V_121 . V_122 ) ;
break;
case V_142 :
if ( ! V_133 -> V_121 . V_143 )
break;
F_25 ( V_14 , L_47 ,
V_14 -> V_139 , V_130 ) ;
V_133 -> V_121 . V_143 ( V_14 , V_133 , V_128 ) ;
break;
case V_144 :
if ( V_128 != V_141 || ! V_133 -> V_121 . V_9 )
break;
F_25 ( V_14 , L_48 ,
V_14 -> V_139 , V_130 ) ;
F_44 ( V_14 , V_133 -> V_121 . V_9 ) ;
break;
default:
F_47 ( V_14 , L_49 ,
V_14 -> V_139 , V_133 -> type ) ;
break;
}
if ( ! V_133 -> V_145 || V_133 -> V_135 )
break;
if ( ++ V_129 > 10 )
break;
V_127 = V_133 -> V_136 ;
}
}
void F_48 ( struct V_13 * V_14 , int V_128 )
{
if ( V_14 -> V_134 )
F_46 ( V_14 , V_14 -> V_146 , V_128 , 0 ) ;
}
static bool F_49 ( struct V_13 * V_14 ,
const struct V_125 * V_9 )
{
for (; V_9 -> V_1 ; V_9 ++ ) {
T_2 V_36 = F_12 ( V_14 , V_9 -> V_1 ) ;
if ( V_9 -> V_126 != V_36 )
return false ;
}
return true ;
}
void F_50 ( struct V_13 * V_14 ,
const struct V_147 * V_148 ,
const struct V_132 * V_149 )
{
const struct V_147 * V_150 ;
if ( V_14 -> V_146 != V_151 )
return;
for ( V_150 = V_148 ; V_150 -> V_152 ; V_150 ++ ) {
if ( ( V_14 -> V_153 & 0xffff0000 ) != ( V_150 -> V_152 << 16 ) )
continue;
if ( V_14 -> V_154 != V_150 -> V_14 )
continue;
if ( F_49 ( V_14 , V_150 -> V_9 ) ) {
V_14 -> V_146 = V_150 -> V_155 ;
#ifdef F_51
V_14 -> V_131 = V_150 -> V_114 ;
#endif
V_14 -> V_134 = V_149 ;
return;
}
}
}
void F_52 ( struct V_13 * V_14 ,
const struct V_156 * V_157 ,
const struct V_158 * V_159 ,
const struct V_132 * V_149 )
{
const struct V_158 * V_160 ;
int V_127 = V_151 ;
const char * V_114 = NULL ;
if ( V_14 -> V_146 != V_151 )
return;
if ( V_14 -> V_130 && ! strcmp ( V_14 -> V_130 , L_50 ) ) {
V_14 -> V_134 = NULL ;
V_14 -> V_131 = NULL ;
V_14 -> V_146 = V_161 ;
return;
}
if ( V_14 -> V_130 && V_157 ) {
while ( V_157 -> V_114 ) {
if ( ! strcmp ( V_14 -> V_130 , V_157 -> V_114 ) ) {
V_14 -> V_146 = V_157 -> V_127 ;
V_14 -> V_131 = V_157 -> V_114 ;
V_14 -> V_134 = V_149 ;
return;
}
V_157 ++ ;
}
}
if ( V_159 ) {
V_160 = F_53 ( V_14 -> V_162 -> V_163 , V_159 ) ;
if ( V_160 ) {
V_127 = V_160 -> V_155 ;
#ifdef F_51
V_114 = V_160 -> V_114 ;
#endif
}
}
if ( V_127 < 0 && V_159 ) {
for ( V_160 = V_159 ; V_160 -> V_152 || V_160 -> V_164 ; V_160 ++ ) {
unsigned int V_165 =
V_160 -> V_164 | ( V_160 -> V_152 << 16 ) ;
unsigned int V_166 = 0xffff0000 | V_160 -> V_167 ;
if ( ( V_14 -> V_153 & V_166 ) == ( V_165 & V_166 ) ) {
V_127 = V_160 -> V_155 ;
#ifdef F_51
V_114 = V_160 -> V_114 ;
#endif
break;
}
}
}
V_14 -> V_146 = V_127 ;
if ( V_127 >= 0 ) {
V_14 -> V_134 = V_149 ;
V_14 -> V_131 = V_114 ;
}
}
