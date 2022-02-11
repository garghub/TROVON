void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_3 ;
}
void F_2 ( struct V_4 * V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ )
V_5 -> V_8 [ V_6 ] . V_9 = false ;
}
void F_3 ( struct V_4 * V_5 ,
T_1 V_10 ,
T_1 V_11 )
{
V_5 -> V_8 [ V_10 ] . V_12 = V_11 ;
V_5 -> V_8 [ V_10 ] . V_9 = true ;
}
void F_4 ( struct V_4 * V_5 ,
T_1 V_10 ,
T_1 * V_11 ,
T_2 V_13 )
{
T_2 V_6 ;
for ( V_6 = 0 ; V_6 < V_13 / sizeof( T_1 ) ; V_6 ++ ) {
V_5 -> V_8 [ V_10 + V_6 ] . V_12 = V_11 [ V_6 ] ;
V_5 -> V_8 [ V_10 + V_6 ] . V_9 = true ;
}
}
static void F_5 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
T_1 V_16 ,
T_1 V_10 ,
T_1 V_13 )
{
struct V_17 * V_8 = V_5 -> V_8 + V_10 ;
T_1 V_6 ;
for ( V_6 = 0 ; V_6 < V_13 ; V_6 ++ ) {
if ( ! V_8 [ V_6 ] . V_9 )
continue;
F_6 ( V_5 , V_15 , V_16 + ( V_6 << 2 ) , V_8 [ V_6 ] . V_12 ) ;
}
}
int F_7 ( struct V_4 * V_5 )
{
struct V_17 * V_8 ;
V_8 = F_8 ( sizeof( * V_8 ) * V_7 , V_18 ) ;
if ( ! V_8 )
return - V_19 ;
V_5 -> V_8 = V_8 ;
return 0 ;
}
void F_9 ( struct V_4 * V_5 )
{
F_10 ( V_5 -> V_8 ) ;
V_5 -> V_8 = NULL ;
}
static int F_11 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
T_1 V_16 ,
T_1 V_20 ,
T_1 V_13 ,
const T_1 * V_21 ,
bool V_22 ,
bool V_23 )
{
int V_24 = 0 ;
if ( ! V_23 || ( ! V_22 && ( V_13 < 16 ) ) ) {
const T_1 * V_25 = V_21 + V_20 ;
T_1 V_6 ;
for ( V_6 = 0 ; V_6 < V_13 ; V_6 ++ )
F_6 ( V_5 , V_15 , V_16 + ( V_6 << 2 ) , V_25 [ V_6 ] ) ;
} else {
V_24 = F_12 ( V_5 , V_15 ,
( V_26 ) ( V_21 + V_20 ) ,
V_16 , V_13 , 0 ) ;
}
return V_24 ;
}
static int F_13 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
T_1 V_16 ,
T_1 V_27 ,
T_1 V_28 )
{
static T_1 V_29 [ V_30 ] ;
memset ( V_29 , 0 , sizeof( T_1 ) * V_30 ) ;
return F_12 ( V_5 , V_15 ,
( V_26 ) ( & V_29 [ 0 ] ) ,
V_16 , V_28 ,
V_31 ) ;
}
static void F_14 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
T_1 V_16 ,
T_1 V_27 ,
T_1 V_28 )
{
T_1 V_6 ;
for ( V_6 = 0 ; V_6 < V_28 ; V_6 ++ , V_16 += sizeof( T_1 ) )
F_6 ( V_5 , V_15 , V_16 , V_27 ) ;
}
static int F_15 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
struct V_32 * V_33 ,
bool V_22 ,
bool V_23 )
{
T_1 V_25 = F_16 ( V_33 -> V_25 ) ;
T_1 V_16 = F_17 ( V_25 , V_34 ) << 2 ;
T_1 V_35 = F_16 ( V_33 -> args . V_36 ) ;
T_1 V_37 , V_38 , V_39 , V_40 ;
struct V_1 * V_2 = V_5 -> V_2 ;
union V_41 * V_42 ;
const T_1 * V_43 ;
int V_24 = 0 ;
T_1 V_13 ;
V_43 = V_2 -> V_44 -> V_45 ;
V_42 = (union V_41 * ) ( V_43 +
V_35 ) ;
V_25 = F_16 ( V_42 -> V_46 . V_25 ) ;
switch ( F_17 ( V_25 , V_47 ) ) {
case V_48 :
V_37 = V_35 + 1 ;
V_39 = F_17 ( V_25 ,
V_49 ) ;
V_40 = V_50 * 4 ;
memset ( V_5 -> V_51 , 0 , V_40 ) ;
V_38 = F_18 ( V_5 , V_39 ,
( V_52 * ) & V_43 [ V_37 ] ,
V_40 , ( V_52 * ) V_5 -> V_51 ) ;
if ( V_38 ) {
V_24 = F_11 ( V_5 , V_15 , V_16 , 0 ,
V_38 ,
V_5 -> V_51 ,
V_22 , V_23 ) ;
} else {
F_19 ( V_5 , L_1 ) ;
V_24 = - V_53 ;
}
break;
case V_54 :
{
T_1 V_55 = F_17 ( V_25 ,
V_56 ) ;
T_1 V_6 ;
V_13 = F_17 ( V_25 , V_57 ) ;
for ( V_6 = 0 ; V_6 < V_55 ; V_6 ++ , V_16 += V_13 << 2 ) {
V_24 = F_11 ( V_5 , V_15 , V_16 ,
V_35 + 1 ,
V_13 , V_43 ,
V_22 , V_23 ) ;
if ( V_24 )
break;
}
break;
}
case V_58 :
V_13 = F_17 ( V_25 , V_59 ) ;
V_24 = F_11 ( V_5 , V_15 , V_16 ,
V_35 + 1 ,
V_13 , V_43 ,
V_22 , V_23 ) ;
break;
}
return V_24 ;
}
static int F_20 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
struct V_32 * V_33 ,
bool V_23 )
{
T_1 V_25 = F_16 ( V_33 -> V_25 ) ;
T_1 V_16 = F_17 ( V_25 , V_34 ) << 2 ;
bool V_22 = F_17 ( V_25 , V_60 ) ;
union V_61 * V_62 = & V_33 -> args ;
int V_24 = 0 ;
if ( V_22 && ! V_23 ) {
F_19 ( V_5 ,
L_2 ,
V_16 ) ;
return - V_53 ;
}
switch ( F_17 ( V_25 , V_63 ) ) {
case V_64 :
F_6 ( V_5 , V_15 , V_16 ,
F_16 ( V_62 -> V_65 ) ) ;
break;
case V_66 :
if ( V_22 ||
( V_23 && ( F_16 ( V_62 -> V_67 ) >= 64 ) ) )
V_24 = F_13 ( V_5 , V_15 , V_16 , 0 ,
F_16 ( V_62 -> V_67 ) ) ;
else
F_14 ( V_5 , V_15 , V_16 , 0 ,
F_16 ( V_62 -> V_67 ) ) ;
break;
case V_68 :
V_24 = F_15 ( V_5 , V_15 , V_33 ,
V_22 , V_23 ) ;
break;
case V_69 :
F_5 ( V_5 , V_15 , V_16 ,
F_21 ( V_62 -> V_70 . V_37 ) ,
F_21 ( V_62 -> V_70 . V_13 ) ) ;
break;
}
return V_24 ;
}
static inline bool F_22 ( T_1 V_11 , T_1 V_71 )
{
return V_11 == V_71 ;
}
static inline bool F_23 ( T_1 V_11 , T_1 V_71 )
{
return ( V_11 & V_71 ) == V_71 ;
}
static inline bool F_24 ( T_1 V_11 , T_1 V_71 )
{
return ( V_11 | V_71 ) > 0 ;
}
static void F_25 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
struct V_72 * V_33 )
{
T_1 V_25 = F_16 ( V_33 -> V_73 ) ;
T_1 V_16 = F_17 ( V_25 , V_74 ) << 2 ;
bool (* F_26)( T_1 V_11 ,
T_1 V_71 );
T_1 V_75 = V_76 , V_11 ;
V_11 = F_27 ( V_5 , V_15 , V_16 ) ;
V_25 = F_16 ( V_33 -> V_73 ) ;
if ( F_17 ( V_25 , V_77 ) ) {
int V_6 ;
switch ( F_17 ( V_25 , V_78 ) ) {
case V_79 :
F_26 = F_22 ;
break;
case V_80 :
F_26 = F_24 ;
break;
case V_81 :
F_26 = F_23 ;
break;
default:
F_26 = NULL ;
F_28 ( V_5 , L_3 ,
V_25 ) ;
return;
}
for ( V_6 = 0 ;
V_6 < V_82 &&
! F_26 ( V_11 , F_16 ( V_33 -> V_71 ) ) ;
V_6 ++ ) {
F_29 ( V_75 ) ;
V_11 = F_27 ( V_5 , V_15 , V_16 ) ;
}
if ( V_6 == V_82 )
F_28 ( V_5 ,
L_4 ,
V_16 , F_16 ( V_33 -> V_71 ) ,
V_11 , V_25 ) ;
}
}
static void F_30 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
struct V_83 * V_84 )
{
F_19 ( V_5 , L_5 ) ;
}
static V_52 F_31 ( struct V_4 * V_5 ,
T_3 * V_37 ,
int V_85 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
const V_52 * V_86 ;
V_52 V_87 , V_88 , V_89 ;
V_86 = V_2 -> V_44 -> V_86 ;
V_89 = V_86 [ ( * V_37 ) ++ ] ;
switch ( V_89 ) {
case V_90 :
return F_31 ( V_5 , V_37 , V_85 ) ^ 1 ;
case V_91 :
V_87 = F_31 ( V_5 , V_37 , V_85 ) ;
V_88 = F_31 ( V_5 , V_37 , V_85 ) ;
return V_87 | V_88 ;
case V_92 :
V_87 = F_31 ( V_5 , V_37 , V_85 ) ;
V_88 = F_31 ( V_5 , V_37 , V_85 ) ;
return V_87 & V_88 ;
default:
V_89 -= V_93 ;
return ( V_85 & ( 1 << V_89 ) ) ? 1 : 0 ;
}
}
static T_1 F_32 ( struct V_4 * V_5 ,
struct V_94 * V_84 ,
int V_85 )
{
T_3 V_37 = F_21 ( V_84 -> V_95 ) ;
if ( F_31 ( V_5 , & V_37 , V_85 ) )
return 0 ;
else
return F_17 ( F_16 ( V_84 -> V_73 ) ,
V_96 ) ;
}
static T_1 F_33 ( struct V_4 * V_5 ,
struct V_97 * V_84 ,
T_1 V_98 ,
T_1 V_99 )
{
T_1 V_25 = F_16 ( V_84 -> V_100 ) ;
T_1 V_73 = F_16 ( V_84 -> V_73 ) ;
if ( ! ( F_17 ( V_25 , V_101 ) == V_98 &&
( F_17 ( V_25 , V_102 ) == V_103 ||
F_17 ( V_25 , V_102 ) == V_99 ) ) )
return F_17 ( V_73 , V_104 ) ;
else
return 0 ;
}
int F_34 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
int V_98 ,
int V_99 ,
int V_85 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
T_1 V_105 , V_106 ;
union V_107 * V_108 ;
bool V_109 = false ;
int V_24 = 0 ;
V_106 = V_2 -> V_44 -> V_110 ;
V_108 = V_2 -> V_44 -> V_108 ;
V_5 -> V_51 = F_8 ( V_50 * 4 , V_18 ) ;
if ( ! V_5 -> V_51 ) {
F_19 ( V_5 , L_6 ) ;
return - V_19 ;
}
for ( V_105 = 0 ; V_105 < V_106 ; V_105 ++ ) {
union V_107 * V_33 = & V_108 [ V_105 ] ;
T_1 V_25 = F_16 ( V_33 -> V_46 . V_73 ) ;
switch ( F_17 ( V_25 , V_111 ) ) {
case V_112 :
V_24 = F_20 ( V_5 , V_15 , & V_33 -> V_113 ,
V_109 ) ;
break;
case V_114 :
F_25 ( V_5 , V_15 , & V_33 -> V_115 ) ;
break;
case V_116 :
V_105 += F_32 ( V_5 , & V_33 -> V_117 ,
V_85 ) ;
break;
case V_118 :
V_105 += F_33 ( V_5 , & V_33 -> V_119 ,
V_98 , V_99 ) ;
V_109 = F_17 ( V_25 , V_120 ) ;
break;
case V_121 :
F_29 ( F_16 ( V_33 -> V_75 . V_75 ) ) ;
break;
case V_122 :
F_30 ( V_5 , V_15 , & V_33 -> V_123 ) ;
break;
}
if ( V_24 )
break;
}
F_10 ( V_5 -> V_51 ) ;
return V_24 ;
}
void F_35 ( struct V_4 * V_5 )
{
T_1 V_124 ;
T_1 V_6 ;
V_124 = V_125 + V_126 ;
for ( V_6 = 0 ; V_6 < F_36 ( V_127 ) ; V_6 ++ )
if ( V_127 [ V_6 ] )
F_37 ( V_5 , V_124 + V_6 * V_128 ,
V_127 [ V_6 ] ) ;
}
int F_38 ( struct V_1 * V_2 ,
const V_52 * V_25 )
{
struct V_129 * V_130 = V_2 -> V_44 ;
struct V_131 * V_132 ;
T_1 V_37 , V_133 ;
if ( ! V_25 ) {
F_19 ( V_2 , L_7 ) ;
return - V_53 ;
}
V_132 = (struct V_131 * ) V_25 ;
V_37 = V_132 [ V_134 ] . V_37 ;
V_130 -> V_108 = (union V_107 * ) ( V_25 + V_37 ) ;
V_37 = V_132 [ V_135 ] . V_37 ;
V_130 -> V_45 = ( T_1 * ) ( V_25 + V_37 ) ;
V_37 = V_132 [ V_136 ] . V_37 ;
V_130 -> V_86 = ( V_52 * ) ( V_25 + V_37 ) ;
V_133 = V_132 [ V_134 ] . V_137 ;
V_130 -> V_110 = V_133 / sizeof( struct V_138 ) ;
return 0 ;
}
