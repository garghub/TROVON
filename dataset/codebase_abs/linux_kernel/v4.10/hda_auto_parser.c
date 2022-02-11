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
T_1 V_1 ;
short V_8 , V_43 ;
struct V_5 V_44 [ F_16 ( V_16 -> V_45 ) ] ;
struct V_5 V_46 [ F_16 ( V_16 -> V_47 ) ] ;
struct V_5 V_48 [ F_16 ( V_16 -> V_49 ) ] ;
int V_11 ;
if ( ! F_17 ( V_14 , L_1 , & V_11 ) )
V_42 = V_11 ;
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
memset ( V_44 , 0 , sizeof( V_44 ) ) ;
memset ( V_46 , 0 , sizeof( V_46 ) ) ;
memset ( V_48 , 0 , sizeof( V_48 ) ) ;
V_43 = 0 ;
F_18 (nid, codec) {
unsigned int V_50 = F_19 ( V_14 , V_1 ) ;
unsigned int V_51 = F_20 ( V_50 ) ;
unsigned int V_36 ;
short V_52 , V_53 , V_54 , V_24 ;
if ( V_51 != V_55 )
continue;
if ( V_41 && F_1 ( V_1 , V_41 ) )
continue;
V_36 = F_12 ( V_14 , V_1 ) ;
V_54 = F_21 ( V_36 ) ;
if ( V_54 == V_56 )
continue;
V_53 = F_22 ( V_36 ) ;
V_24 = F_23 ( V_36 ) ;
if ( V_24 == V_26 ) {
if ( V_54 == V_57 ||
V_54 == V_58 )
V_24 = V_27 ;
}
if ( ! F_9 ( V_14 , V_1 , V_24 ) )
continue;
switch ( V_24 ) {
case V_26 :
V_8 = F_14 ( V_36 ) ;
V_52 = F_24 ( V_36 ) ;
if ( ! ( V_50 & V_59 ) )
if ( ! V_16 -> V_60 )
V_16 -> V_60 = V_1 ;
if ( ! V_52 )
continue;
if ( ! V_43 )
V_43 = V_52 ;
else if ( V_43 != V_52 ) {
F_25 ( V_14 ,
L_2 ,
V_1 , V_52 , V_43 ) ;
continue;
}
if ( V_16 -> V_61 >= F_16 ( V_16 -> V_45 ) ) {
F_25 ( V_14 ,
L_3 ,
V_1 ) ;
continue;
}
V_44 [ V_16 -> V_61 ] . V_12 = V_1 ;
V_44 [ V_16 -> V_61 ] . V_8 = V_8 ;
V_16 -> V_61 ++ ;
break;
case V_27 :
V_8 = F_14 ( V_36 ) ;
V_52 = F_24 ( V_36 ) ;
if ( V_16 -> V_62 >= F_16 ( V_16 -> V_47 ) ) {
F_25 ( V_14 ,
L_3 ,
V_1 ) ;
continue;
}
V_46 [ V_16 -> V_62 ] . V_12 = V_1 ;
V_46 [ V_16 -> V_62 ] . V_8 = ( V_52 << 4 ) | V_8 ;
V_16 -> V_62 ++ ;
break;
case V_28 :
V_8 = F_14 ( V_36 ) ;
V_52 = F_24 ( V_36 ) ;
if ( V_16 -> V_63 >= F_16 ( V_16 -> V_49 ) ) {
F_25 ( V_14 ,
L_3 ,
V_1 ) ;
continue;
}
V_48 [ V_16 -> V_63 ] . V_12 = V_1 ;
V_48 [ V_16 -> V_63 ] . V_8 = ( V_52 << 4 ) | V_8 ;
V_16 -> V_63 ++ ;
break;
case V_64 :
F_5 ( V_14 , V_16 , V_1 , V_37 ) ;
break;
case V_65 :
F_5 ( V_14 , V_16 , V_1 , V_66 ) ;
break;
case V_67 :
F_5 ( V_14 , V_16 , V_1 , V_68 ) ;
break;
case V_69 :
F_5 ( V_14 , V_16 , V_1 , V_70 ) ;
break;
case V_29 :
case V_30 :
if ( V_16 -> V_71 >= F_16 ( V_16 -> V_72 ) ) {
F_25 ( V_14 ,
L_3 ,
V_1 ) ;
continue;
}
V_16 -> V_72 [ V_16 -> V_71 ] = V_1 ;
V_16 -> V_73 [ V_16 -> V_71 ] =
( V_53 == V_74 ) ?
V_75 : V_76 ;
V_16 -> V_71 ++ ;
break;
case V_77 :
case V_78 :
V_16 -> V_79 = V_1 ;
if ( V_53 == V_74 )
V_16 -> V_80 = V_75 ;
else
V_16 -> V_80 = V_76 ;
break;
}
}
if ( V_42 & V_81 || V_42 & V_82 ) {
bool V_83 = ! ! ( V_42 & V_81 ) ;
bool V_84 = ! ! ( V_42 & V_82 ) ;
for ( V_11 = 0 ; ( V_83 || V_84 ) && ( V_11 < V_16 -> V_17 ) ; V_11 ++ )
if ( V_83 && F_11 ( V_14 , & V_16 -> V_19 [ V_11 ] , 0xc ) ) {
V_16 -> V_19 [ V_11 ] . V_38 = 1 ;
V_83 = false ;
} else if ( V_84 && F_11 ( V_14 , & V_16 -> V_19 [ V_11 ] , 0xd ) ) {
V_16 -> V_19 [ V_11 ] . V_39 = 1 ;
V_84 = false ;
}
for ( V_11 = 0 ; ( V_83 || V_84 ) && ( V_11 < V_16 -> V_17 ) ; V_11 ++ ) {
if ( ! F_11 ( V_14 , & V_16 -> V_19 [ V_11 ] , - 1 ) )
continue;
if ( V_83 ) {
V_16 -> V_19 [ V_11 ] . V_38 = 1 ;
V_83 = false ;
} else if ( V_84 ) {
V_16 -> V_19 [ V_11 ] . V_39 = 1 ;
V_84 = false ;
}
}
if ( V_83 )
F_26 ( V_14 , L_4 ) ;
if ( V_84 )
F_26 ( V_14 , L_5 ) ;
}
if ( ! V_16 -> V_61 && V_16 -> V_63 > 1 &&
! ( V_42 & V_85 ) ) {
int V_11 = 0 ;
while ( V_11 < V_16 -> V_63 ) {
if ( ( V_48 [ V_11 ] . V_8 & 0x0f ) == 0x0f ) {
V_11 ++ ;
continue;
}
V_44 [ V_16 -> V_61 ++ ] = V_48 [ V_11 ] ;
V_16 -> V_63 -- ;
memmove ( V_48 + V_11 , V_48 + V_11 + 1 ,
sizeof( V_48 [ 0 ] ) * ( V_16 -> V_63 - V_11 ) ) ;
}
memset ( V_48 + V_16 -> V_63 , 0 ,
sizeof( V_48 [ 0 ] ) * ( V_86 - V_16 -> V_63 ) ) ;
if ( ! V_16 -> V_63 )
V_16 -> V_87 = V_88 ;
}
F_3 ( V_16 -> V_45 , V_44 , V_16 -> V_61 ) ;
F_3 ( V_16 -> V_47 , V_46 ,
V_16 -> V_62 ) ;
F_3 ( V_16 -> V_49 , V_48 , V_16 -> V_63 ) ;
if ( ! V_16 -> V_61 &&
! ( V_42 & V_89 ) ) {
if ( V_16 -> V_62 ) {
V_16 -> V_61 = V_16 -> V_62 ;
memcpy ( V_16 -> V_45 , V_16 -> V_47 ,
sizeof( V_16 -> V_47 ) ) ;
V_16 -> V_62 = 0 ;
memset ( V_16 -> V_47 , 0 , sizeof( V_16 -> V_47 ) ) ;
V_16 -> V_87 = V_90 ;
} else if ( V_16 -> V_63 ) {
V_16 -> V_61 = V_16 -> V_63 ;
memcpy ( V_16 -> V_45 , V_16 -> V_49 ,
sizeof( V_16 -> V_49 ) ) ;
V_16 -> V_63 = 0 ;
memset ( V_16 -> V_49 , 0 , sizeof( V_16 -> V_49 ) ) ;
V_16 -> V_87 = V_88 ;
}
}
F_8 ( V_16 -> V_61 , V_16 -> V_45 ) ;
F_8 ( V_16 -> V_63 , V_16 -> V_49 ) ;
F_8 ( V_16 -> V_62 , V_16 -> V_47 ) ;
F_4 ( V_16 -> V_19 , V_16 -> V_17 , sizeof( V_16 -> V_19 [ 0 ] ) ,
F_7 , NULL ) ;
F_25 ( V_14 , L_6 ,
V_14 -> V_91 . V_92 , V_16 -> V_61 , V_16 -> V_45 [ 0 ] ,
V_16 -> V_45 [ 1 ] , V_16 -> V_45 [ 2 ] ,
V_16 -> V_45 [ 3 ] , V_16 -> V_45 [ 4 ] ,
V_16 -> V_87 == V_88 ? L_7 :
( V_16 -> V_87 == V_90 ?
L_8 : L_9 ) ) ;
F_25 ( V_14 , L_10 ,
V_16 -> V_62 , V_16 -> V_47 [ 0 ] ,
V_16 -> V_47 [ 1 ] , V_16 -> V_47 [ 2 ] ,
V_16 -> V_47 [ 3 ] , V_16 -> V_47 [ 4 ] ) ;
F_25 ( V_14 , L_11 ,
V_16 -> V_63 , V_16 -> V_49 [ 0 ] ,
V_16 -> V_49 [ 1 ] , V_16 -> V_49 [ 2 ] ,
V_16 -> V_49 [ 3 ] , V_16 -> V_49 [ 4 ] ) ;
F_25 ( V_14 , L_12 , V_16 -> V_60 ) ;
if ( V_16 -> V_71 )
F_25 ( V_14 , L_13 ,
V_16 -> V_72 [ 0 ] , V_16 -> V_72 [ 1 ] ) ;
F_25 ( V_14 , L_14 ) ;
for ( V_11 = 0 ; V_11 < V_16 -> V_17 ; V_11 ++ ) {
F_25 ( V_14 , L_15 ,
F_27 ( V_14 , V_16 , V_11 ) ,
V_16 -> V_19 [ V_11 ] . V_12 ) ;
}
if ( V_16 -> V_79 )
F_25 ( V_14 , L_16 , V_16 -> V_79 ) ;
return 0 ;
}
int F_13 ( unsigned int V_36 )
{
unsigned int V_53 = F_22 ( V_36 ) ;
unsigned int V_54 = F_21 ( V_36 ) ;
if ( V_54 == V_56 )
return V_93 ;
if ( V_54 == V_57 || V_54 == V_58 )
return V_94 ;
if ( ( V_53 & 0x30 ) == V_95 )
return V_94 ;
if ( ( V_53 & 0x30 ) == V_96 )
return V_40 ;
if ( V_53 == V_97 )
return V_98 ;
if ( V_53 == V_99 )
return V_100 ;
return V_101 ;
}
static const char * F_28 ( struct V_13 * V_14 ,
const struct V_22 * V_33 ,
T_1 V_12 , bool V_102 )
{
unsigned int V_36 ;
static const char * const V_103 [] = {
L_17 , L_18 , L_19 , L_20 , L_21
} ;
int V_35 ;
V_36 = F_12 ( V_14 , V_12 ) ;
switch ( F_23 ( V_36 ) ) {
case V_64 :
if ( V_33 && V_33 -> V_38 )
return L_22 ;
if ( V_33 && V_33 -> V_39 )
return L_23 ;
if ( ! V_102 )
return L_19 ;
V_35 = F_13 ( V_36 ) ;
if ( ! V_35 )
return L_24 ;
return V_103 [ V_35 - 1 ] ;
case V_65 :
if ( ! V_102 )
return L_25 ;
V_35 = F_13 ( V_36 ) ;
if ( ! V_35 )
return L_24 ;
if ( V_35 == V_40 )
return L_26 ;
return L_25 ;
case V_69 :
return L_27 ;
case V_67 :
return L_28 ;
case V_77 :
return L_29 ;
case V_78 :
return L_30 ;
case V_28 :
return L_23 ;
default:
return L_31 ;
}
}
static int F_29 ( struct V_13 * V_14 ,
const struct V_15 * V_16 ,
int V_104 )
{
unsigned int V_105 ;
int V_11 , V_35 , V_106 ;
V_105 = F_12 ( V_14 , V_16 -> V_19 [ V_104 ] . V_12 ) ;
V_35 = F_13 ( V_105 ) ;
if ( V_35 <= V_101 )
return 1 ;
V_35 = 0 ;
for ( V_11 = 0 ; V_11 < V_16 -> V_17 ; V_11 ++ ) {
V_105 = F_12 ( V_14 , V_16 -> V_19 [ V_11 ] . V_12 ) ;
V_106 = F_13 ( V_105 ) ;
if ( V_106 >= V_101 ) {
if ( V_35 && V_35 != V_106 )
return 1 ;
V_35 = V_106 ;
}
}
return 0 ;
}
const char * F_27 ( struct V_13 * V_14 ,
const struct V_15 * V_16 ,
int V_104 )
{
int type = V_16 -> V_19 [ V_104 ] . type ;
int V_107 = 0 ;
if ( ( V_104 > 0 && V_16 -> V_19 [ V_104 - 1 ] . type == type ) ||
( V_104 < V_16 -> V_17 - 1 && V_16 -> V_19 [ V_104 + 1 ] . type == type ) )
V_107 = 1 ;
if ( V_107 && type == V_37 )
V_107 &= F_29 ( V_14 , V_16 , V_104 ) ;
return F_28 ( V_14 , & V_16 -> V_19 [ V_104 ] ,
V_16 -> V_19 [ V_104 ] . V_12 ,
V_107 ) ;
}
static int F_30 ( T_1 V_1 , const T_1 * V_2 , int V_23 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_23 ; V_11 ++ )
if ( V_2 [ V_11 ] == V_1 )
return V_11 ;
return - 1 ;
}
static const char * F_31 ( T_1 V_1 , const T_1 * V_9 ,
int V_10 , int * V_108 )
{
static const char * const V_109 [] = {
L_32 , L_33 , L_34 , L_35
} ;
int V_11 ;
V_11 = F_30 ( V_1 , V_9 , V_10 ) ;
if ( V_11 < 0 )
return NULL ;
if ( V_10 == 1 )
return L_36 ;
if ( V_10 > F_16 ( V_109 ) ) {
if ( V_108 )
* V_108 = V_11 ;
return L_36 ;
}
return V_109 [ V_11 ] ;
}
static const char * F_32 ( struct V_13 * V_14 , T_1 V_1 )
{
unsigned int V_36 = F_12 ( V_14 , V_1 ) ;
int V_35 = F_13 ( V_36 ) ;
switch ( V_35 ) {
case V_40 :
return L_37 ;
case V_100 :
return L_38 ;
}
return L_36 ;
}
static int F_33 ( struct V_13 * V_14 , T_1 V_1 ,
const T_1 * V_9 , int V_10 )
{
int V_11 , V_110 , V_111 = 0 ;
const char * V_112 = F_32 ( V_14 , V_1 ) ;
V_11 = F_30 ( V_1 , V_9 , V_10 ) ;
if ( V_11 < 0 )
return - 1 ;
for ( V_110 = 0 ; V_110 < V_11 ; V_110 ++ )
if ( V_112 == F_32 ( V_14 , V_9 [ V_110 ] ) )
V_111 ++ ;
return V_111 ;
}
static int F_34 ( struct V_13 * V_14 , T_1 V_1 ,
const struct V_15 * V_16 ,
const char * V_113 , char * V_114 , int V_115 ,
int * V_108 )
{
unsigned int V_36 = F_12 ( V_14 , V_1 ) ;
int V_35 = F_13 ( V_36 ) ;
const char * V_112 , * V_116 = L_36 ;
if ( ! strcmp ( V_113 , L_39 ) && V_35 == V_94 )
V_113 = L_40 ;
V_112 = F_32 ( V_14 , V_1 ) ;
if ( V_16 ) {
V_116 = F_31 ( V_1 , V_16 -> V_45 , V_16 -> V_61 ,
V_108 ) ;
if ( ! V_116 )
V_116 = F_31 ( V_1 , V_16 -> V_47 , V_16 -> V_62 ,
V_108 ) ;
if ( ! V_116 ) {
int V_111 = F_33 ( V_14 , V_1 , V_16 -> V_49 ,
V_16 -> V_63 ) ;
if ( V_111 >= 0 && V_108 )
* V_108 = V_111 ;
V_116 = L_36 ;
}
}
snprintf ( V_114 , V_115 , L_41 , V_112 , V_113 , V_116 ) ;
return 1 ;
}
int F_35 ( struct V_13 * V_14 , T_1 V_1 ,
const struct V_15 * V_16 ,
char * V_114 , int V_115 , int * V_108 )
{
unsigned int V_36 = F_12 ( V_14 , V_1 ) ;
const char * V_113 = NULL ;
int V_11 ;
bool V_117 ;
if ( V_108 )
* V_108 = 0 ;
if ( F_21 ( V_36 ) == V_56 )
return 0 ;
switch ( F_23 ( V_36 ) ) {
case V_26 :
return F_34 ( V_14 , V_1 , V_16 , L_39 ,
V_114 , V_115 , V_108 ) ;
case V_27 :
return F_34 ( V_14 , V_1 , V_16 , L_40 ,
V_114 , V_115 , V_108 ) ;
case V_28 :
return F_34 ( V_14 , V_1 , V_16 , L_42 ,
V_114 , V_115 , V_108 ) ;
case V_29 :
case V_30 :
V_117 = F_36 ( V_36 ) ;
V_113 = V_117 ? L_43 : L_44 ;
if ( V_16 && V_108 )
for ( V_11 = 0 ; V_11 < V_16 -> V_71 ; V_11 ++ ) {
T_1 V_12 = V_16 -> V_72 [ V_11 ] ;
unsigned int V_118 ;
if ( V_12 == V_1 )
break;
V_118 = F_12 ( V_14 , V_12 ) ;
if ( V_117 == F_36 ( V_118 ) )
( * V_108 ) ++ ;
}
break;
default:
if ( V_16 ) {
for ( V_11 = 0 ; V_11 < V_16 -> V_17 ; V_11 ++ ) {
if ( V_16 -> V_19 [ V_11 ] . V_12 != V_1 )
continue;
V_113 = F_27 ( V_14 , V_16 , V_11 ) ;
if ( V_113 )
break;
}
}
if ( ! V_113 )
V_113 = F_28 ( V_14 , NULL , V_1 , true ) ;
break;
}
if ( ! V_113 )
return 0 ;
F_37 ( V_114 , V_113 , V_115 ) ;
return 1 ;
}
int F_38 ( struct V_13 * V_14 ,
const struct V_119 * V_2 )
{
const struct V_119 * * V_120 ;
V_120 = F_39 ( & V_14 -> V_121 ) ;
if ( ! V_120 )
return - V_122 ;
* V_120 = V_2 ;
return 0 ;
}
void F_40 ( struct V_13 * V_14 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_14 -> V_121 . V_123 ; V_11 ++ ) {
struct V_119 * * V_120 = F_41 ( & V_14 -> V_121 , V_11 ) ;
F_42 ( V_14 , * V_120 ) ;
}
}
void F_43 ( struct V_13 * V_14 ,
const struct V_124 * V_16 )
{
for (; V_16 -> V_1 ; V_16 ++ )
F_44 ( V_14 , V_16 -> V_1 , V_16 -> V_125 ) ;
}
static void F_45 ( struct V_13 * V_14 ,
const struct V_124 * V_16 )
{
for (; V_16 -> V_1 ; V_16 ++ )
F_46 ( V_14 , V_16 -> V_1 , V_16 -> V_125 ) ;
}
static void F_47 ( struct V_13 * V_14 , int V_126 , int V_127 , int V_128 )
{
const char * V_129 = V_14 -> V_130 ;
while ( V_126 >= 0 ) {
const struct V_131 * V_132 = V_14 -> V_133 + V_126 ;
if ( V_132 -> V_134 )
F_47 ( V_14 , V_132 -> V_135 , V_127 , V_128 + 1 ) ;
switch ( V_132 -> type ) {
case V_136 :
if ( V_127 != V_137 || ! V_132 -> V_120 . V_9 )
break;
F_26 ( V_14 , L_45 ,
V_14 -> V_91 . V_92 , V_129 ) ;
F_43 ( V_14 , V_132 -> V_120 . V_9 ) ;
break;
case V_138 :
if ( V_127 != V_139 || ! V_132 -> V_120 . V_121 )
break;
F_26 ( V_14 , L_46 ,
V_14 -> V_91 . V_92 , V_129 ) ;
F_38 ( V_14 , V_132 -> V_120 . V_121 ) ;
break;
case V_140 :
if ( ! V_132 -> V_120 . V_141 )
break;
F_26 ( V_14 , L_47 ,
V_14 -> V_91 . V_92 , V_129 ) ;
V_132 -> V_120 . V_141 ( V_14 , V_132 , V_127 ) ;
break;
case V_142 :
if ( V_127 != V_139 || ! V_132 -> V_120 . V_9 )
break;
F_26 ( V_14 , L_48 ,
V_14 -> V_91 . V_92 , V_129 ) ;
F_45 ( V_14 , V_132 -> V_120 . V_9 ) ;
break;
default:
F_48 ( V_14 , L_49 ,
V_14 -> V_91 . V_92 , V_132 -> type ) ;
break;
}
if ( ! V_132 -> V_143 || V_132 -> V_134 )
break;
if ( ++ V_128 > 10 )
break;
V_126 = V_132 -> V_135 ;
}
}
void F_49 ( struct V_13 * V_14 , int V_127 )
{
if ( V_14 -> V_133 )
F_47 ( V_14 , V_14 -> V_144 , V_127 , 0 ) ;
}
static bool F_50 ( struct V_13 * V_14 ,
const struct V_124 * V_9 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_14 -> V_145 . V_123 ; V_11 ++ ) {
struct V_146 * V_12 = F_41 ( & V_14 -> V_145 , V_11 ) ;
T_1 V_1 = V_12 -> V_1 ;
T_2 V_16 = V_12 -> V_16 ;
const struct V_124 * V_147 ;
int V_148 ;
V_147 = V_9 ;
V_148 = 0 ;
for (; V_147 -> V_1 ; V_147 ++ ) {
if ( V_147 -> V_1 == V_1 ) {
V_148 = 1 ;
if ( ( V_147 -> V_125 & V_149 ) == ( V_16 & V_149 ) )
break;
else if ( ( V_16 & 0xf0000000 ) == 0x40000000 && ( V_147 -> V_125 & 0xf0000000 ) == 0x40000000 )
break;
else
return false ;
}
}
if ( ! V_148 && ( V_16 & 0xf0000000 ) != 0x40000000 )
return false ;
}
return true ;
}
void F_51 ( struct V_13 * V_14 ,
const struct V_150 * V_151 ,
const struct V_131 * V_152 )
{
const struct V_150 * V_153 ;
if ( V_14 -> V_144 != V_154 )
return;
for ( V_153 = V_151 ; V_153 -> V_155 ; V_153 ++ ) {
if ( ( V_14 -> V_91 . V_156 & 0xffff0000 ) != ( V_153 -> V_155 << 16 ) )
continue;
if ( V_14 -> V_91 . V_157 != V_153 -> V_14 )
continue;
if ( F_50 ( V_14 , V_153 -> V_9 ) ) {
V_14 -> V_144 = V_153 -> V_158 ;
#ifdef F_52
V_14 -> V_130 = V_153 -> V_113 ;
F_26 ( V_14 , L_50 ,
V_14 -> V_91 . V_92 , V_14 -> V_130 ) ;
#endif
V_14 -> V_133 = V_152 ;
return;
}
}
}
void F_53 ( struct V_13 * V_14 ,
const struct V_159 * V_160 ,
const struct V_161 * V_162 ,
const struct V_131 * V_152 )
{
const struct V_161 * V_163 ;
int V_126 = V_154 ;
const char * V_113 = NULL ;
if ( V_14 -> V_144 != V_154 )
return;
if ( V_14 -> V_129 && ! strcmp ( V_14 -> V_129 , L_51 ) ) {
V_14 -> V_133 = NULL ;
V_14 -> V_130 = NULL ;
V_14 -> V_144 = V_164 ;
F_26 ( V_14 , L_52 ,
V_14 -> V_91 . V_92 ) ;
return;
}
if ( V_14 -> V_129 && V_160 ) {
while ( V_160 -> V_113 ) {
if ( ! strcmp ( V_14 -> V_129 , V_160 -> V_113 ) ) {
V_14 -> V_144 = V_160 -> V_126 ;
V_14 -> V_130 = V_160 -> V_113 ;
V_14 -> V_133 = V_152 ;
F_26 ( V_14 , L_53 ,
V_14 -> V_91 . V_92 , V_14 -> V_130 ) ;
return;
}
V_160 ++ ;
}
}
if ( V_162 ) {
V_163 = F_54 ( V_14 -> V_165 -> V_166 , V_162 ) ;
if ( V_163 ) {
V_126 = V_163 -> V_158 ;
#ifdef F_52
V_113 = V_163 -> V_113 ;
F_26 ( V_14 , L_54 ,
V_14 -> V_91 . V_92 , V_113 , V_163 -> V_167 ? L_36 : L_55 ) ;
#endif
}
}
if ( V_126 < 0 && V_162 ) {
for ( V_163 = V_162 ; V_163 -> V_155 || V_163 -> V_168 ; V_163 ++ ) {
unsigned int V_169 =
V_163 -> V_168 | ( V_163 -> V_155 << 16 ) ;
unsigned int V_170 = 0xffff0000 | V_163 -> V_167 ;
if ( ( V_14 -> V_91 . V_156 & V_170 ) == ( V_169 & V_170 ) ) {
V_126 = V_163 -> V_158 ;
#ifdef F_52
V_113 = V_163 -> V_113 ;
F_26 ( V_14 , L_56 ,
V_14 -> V_91 . V_92 , V_113 ) ;
#endif
break;
}
}
}
V_14 -> V_144 = V_126 ;
if ( V_126 >= 0 ) {
V_14 -> V_133 = V_152 ;
V_14 -> V_130 = V_113 ;
}
}
