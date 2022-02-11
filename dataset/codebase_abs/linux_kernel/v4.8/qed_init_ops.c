void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_3 ;
}
void F_2 ( struct V_4 * V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ )
V_5 -> V_8 . V_9 [ V_6 ] = false ;
}
void F_3 ( struct V_4 * V_5 ,
T_1 V_10 ,
T_1 V_11 )
{
V_5 -> V_8 . V_12 [ V_10 ] = V_11 ;
V_5 -> V_8 . V_9 [ V_10 ] = true ;
}
void F_4 ( struct V_4 * V_5 ,
T_1 V_10 , T_1 * V_13 ,
T_2 V_14 )
{
T_2 V_6 ;
for ( V_6 = 0 ; V_6 < V_14 / sizeof( T_1 ) ; V_6 ++ ) {
V_5 -> V_8 . V_12 [ V_10 + V_6 ] = V_13 [ V_6 ] ;
V_5 -> V_8 . V_9 [ V_10 + V_6 ] = true ;
}
}
static int F_5 ( struct V_4 * V_5 ,
struct V_15 * V_16 ,
T_1 V_17 ,
T_3 V_10 ,
T_3 V_14 ,
bool V_18 )
{
T_1 * V_19 = & V_5 -> V_8 . V_12 [ V_10 ] ;
bool * V_20 = & V_5 -> V_8 . V_9 [ V_10 ] ;
T_3 V_6 , V_21 ;
int V_22 = 0 ;
for ( V_6 = 0 ; V_6 < V_14 ; V_6 ++ ) {
if ( ! V_20 [ V_6 ] )
continue;
if ( ! V_18 ) {
F_6 ( V_5 , V_16 , V_17 + ( V_6 << 2 ) ,
V_19 [ V_6 ] ) ;
continue;
}
for ( V_21 = 1 ; V_6 + V_21 < V_14 ; V_21 ++ )
if ( ! V_20 [ V_6 + V_21 ] )
break;
V_22 = F_7 ( V_5 , V_16 ,
( V_23 ) ( V_19 + V_6 ) ,
V_17 + ( V_6 << 2 ) , V_21 , 0 ) ;
if ( V_22 != 0 )
return V_22 ;
V_6 += V_21 ;
}
return V_22 ;
}
int F_8 ( struct V_4 * V_5 )
{
struct V_24 * V_8 = & V_5 -> V_8 ;
if ( F_9 ( V_5 -> V_2 ) )
return 0 ;
V_8 -> V_9 = F_10 ( sizeof( bool ) * V_7 ,
V_25 ) ;
if ( ! V_8 -> V_9 )
return - V_26 ;
V_8 -> V_12 = F_10 ( sizeof( T_1 ) * V_7 ,
V_25 ) ;
if ( ! V_8 -> V_12 ) {
F_11 ( V_8 -> V_9 ) ;
return - V_26 ;
}
return 0 ;
}
void F_12 ( struct V_4 * V_5 )
{
F_11 ( V_5 -> V_8 . V_12 ) ;
F_11 ( V_5 -> V_8 . V_9 ) ;
}
static int F_13 ( struct V_4 * V_5 ,
struct V_15 * V_16 ,
T_1 V_17 ,
T_1 V_27 ,
T_1 V_14 ,
const T_1 * V_28 ,
bool V_18 ,
bool V_29 )
{
int V_22 = 0 ;
if ( ! V_29 || ( ! V_18 && ( V_14 < 16 ) ) ) {
const T_1 * V_30 = V_28 + V_27 ;
T_1 V_6 ;
for ( V_6 = 0 ; V_6 < V_14 ; V_6 ++ )
F_6 ( V_5 , V_16 , V_17 + ( V_6 << 2 ) , V_30 [ V_6 ] ) ;
} else {
V_22 = F_7 ( V_5 , V_16 ,
( V_23 ) ( V_28 + V_27 ) ,
V_17 , V_14 , 0 ) ;
}
return V_22 ;
}
static int F_14 ( struct V_4 * V_5 ,
struct V_15 * V_16 ,
T_1 V_17 ,
T_1 V_31 ,
T_1 V_32 )
{
static T_1 V_33 [ V_34 ] ;
memset ( V_33 , 0 , sizeof( T_1 ) * V_34 ) ;
return F_7 ( V_5 , V_16 ,
( V_23 ) ( & V_33 [ 0 ] ) ,
V_17 , V_32 ,
V_35 ) ;
}
static void F_15 ( struct V_4 * V_5 ,
struct V_15 * V_16 ,
T_1 V_17 ,
T_1 V_31 ,
T_1 V_32 )
{
T_1 V_6 ;
for ( V_6 = 0 ; V_6 < V_32 ; V_6 ++ , V_17 += sizeof( T_1 ) )
F_6 ( V_5 , V_16 , V_17 , V_31 ) ;
}
static int F_16 ( struct V_4 * V_5 ,
struct V_15 * V_16 ,
struct V_36 * V_37 ,
bool V_18 ,
bool V_29 )
{
T_1 V_30 = F_17 ( V_37 -> V_30 ) ;
T_1 V_17 = F_18 ( V_30 , V_38 ) << 2 ;
T_1 V_39 = F_17 ( V_37 -> args . V_40 ) ;
T_1 V_41 , V_42 , V_43 , V_44 ;
struct V_1 * V_2 = V_5 -> V_2 ;
union V_45 * V_46 ;
const T_1 * V_47 ;
int V_22 = 0 ;
T_1 V_14 ;
V_47 = V_2 -> V_48 -> V_49 ;
V_46 = (union V_45 * ) ( V_47 +
V_39 ) ;
V_30 = F_17 ( V_46 -> V_50 . V_30 ) ;
switch ( F_18 ( V_30 , V_51 ) ) {
case V_52 :
V_41 = V_39 + 1 ;
V_43 = F_18 ( V_30 ,
V_53 ) ;
V_44 = V_54 * 4 ;
memset ( V_5 -> V_55 , 0 , V_44 ) ;
V_42 = F_19 ( V_5 , V_43 ,
( V_56 * ) & V_47 [ V_41 ] ,
V_44 , ( V_56 * ) V_5 -> V_55 ) ;
if ( V_42 ) {
V_22 = F_13 ( V_5 , V_16 , V_17 , 0 ,
V_42 ,
V_5 -> V_55 ,
V_18 , V_29 ) ;
} else {
F_20 ( V_5 , L_1 ) ;
V_22 = - V_57 ;
}
break;
case V_58 :
{
T_1 V_59 = F_18 ( V_30 ,
V_60 ) ;
T_1 V_6 ;
V_14 = F_18 ( V_30 , V_61 ) ;
for ( V_6 = 0 ; V_6 < V_59 ; V_6 ++ , V_17 += V_14 << 2 ) {
V_22 = F_13 ( V_5 , V_16 , V_17 ,
V_39 + 1 ,
V_14 , V_47 ,
V_18 , V_29 ) ;
if ( V_22 )
break;
}
break;
}
case V_62 :
V_14 = F_18 ( V_30 , V_63 ) ;
V_22 = F_13 ( V_5 , V_16 , V_17 ,
V_39 + 1 ,
V_14 , V_47 ,
V_18 , V_29 ) ;
break;
}
return V_22 ;
}
static int F_21 ( struct V_4 * V_5 ,
struct V_15 * V_16 ,
struct V_36 * V_37 ,
bool V_29 )
{
T_1 V_30 = F_17 ( V_37 -> V_30 ) ;
T_1 V_17 = F_18 ( V_30 , V_38 ) << 2 ;
bool V_18 = F_18 ( V_30 , V_64 ) ;
union V_65 * V_66 = & V_37 -> args ;
int V_22 = 0 ;
if ( V_18 && ! V_29 ) {
F_20 ( V_5 ,
L_2 ,
V_17 ) ;
return - V_57 ;
}
switch ( F_18 ( V_30 , V_67 ) ) {
case V_68 :
F_6 ( V_5 , V_16 , V_17 ,
F_17 ( V_66 -> V_69 ) ) ;
break;
case V_70 :
if ( V_18 ||
( V_29 && ( F_17 ( V_66 -> V_71 ) >= 64 ) ) )
V_22 = F_14 ( V_5 , V_16 , V_17 , 0 ,
F_17 ( V_66 -> V_71 ) ) ;
else
F_15 ( V_5 , V_16 , V_17 , 0 ,
F_17 ( V_66 -> V_71 ) ) ;
break;
case V_72 :
V_22 = F_16 ( V_5 , V_16 , V_37 ,
V_18 , V_29 ) ;
break;
case V_73 :
F_5 ( V_5 , V_16 , V_17 ,
F_22 ( V_66 -> V_74 . V_41 ) ,
F_22 ( V_66 -> V_74 . V_14 ) ,
V_18 ) ;
break;
}
return V_22 ;
}
static inline bool F_23 ( T_1 V_11 , T_1 V_75 )
{
return V_11 == V_75 ;
}
static inline bool F_24 ( T_1 V_11 , T_1 V_75 )
{
return ( V_11 & V_75 ) == V_75 ;
}
static inline bool F_25 ( T_1 V_11 , T_1 V_75 )
{
return ( V_11 | V_75 ) > 0 ;
}
static void F_26 ( struct V_4 * V_5 ,
struct V_15 * V_16 ,
struct V_76 * V_37 )
{
bool (* F_27)( T_1 V_11 , T_1 V_75 );
T_1 V_77 = V_78 , V_11 ;
T_1 V_30 , V_17 , V_79 ;
int V_6 ;
V_30 = F_17 ( V_37 -> V_80 ) ;
V_17 = F_18 ( V_30 , V_81 ) << 2 ;
V_79 = F_18 ( V_30 , V_82 ) ;
V_11 = F_28 ( V_5 , V_16 , V_17 ) ;
if ( V_79 == V_83 )
return;
switch ( V_79 ) {
case V_84 :
F_27 = F_23 ;
break;
case V_85 :
F_27 = F_25 ;
break;
case V_86 :
F_27 = F_24 ;
break;
default:
F_29 ( V_5 , L_3 ,
V_37 -> V_80 ) ;
return;
}
V_30 = F_17 ( V_37 -> V_75 ) ;
for ( V_6 = 0 ;
V_6 < V_87 && ! F_27 ( V_11 , V_30 ) ;
V_6 ++ ) {
F_30 ( V_77 ) ;
V_11 = F_28 ( V_5 , V_16 , V_17 ) ;
}
if ( V_6 == V_87 ) {
F_29 ( V_5 ,
L_4 ,
V_17 , F_17 ( V_37 -> V_75 ) ,
V_11 , F_17 ( V_37 -> V_80 ) ) ;
}
}
static void F_31 ( struct V_4 * V_5 ,
struct V_15 * V_16 ,
struct V_88 * V_89 )
{
F_20 ( V_5 , L_5 ) ;
}
static V_56 F_32 ( struct V_4 * V_5 ,
T_3 * V_41 ,
int V_90 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
const V_56 * V_91 ;
V_56 V_92 , V_93 , V_94 ;
V_91 = V_2 -> V_48 -> V_91 ;
V_94 = V_91 [ ( * V_41 ) ++ ] ;
switch ( V_94 ) {
case V_95 :
return F_32 ( V_5 , V_41 , V_90 ) ^ 1 ;
case V_96 :
V_92 = F_32 ( V_5 , V_41 , V_90 ) ;
V_93 = F_32 ( V_5 , V_41 , V_90 ) ;
return V_92 | V_93 ;
case V_97 :
V_92 = F_32 ( V_5 , V_41 , V_90 ) ;
V_93 = F_32 ( V_5 , V_41 , V_90 ) ;
return V_92 & V_93 ;
default:
V_94 -= V_98 ;
return ( V_90 & ( 1 << V_94 ) ) ? 1 : 0 ;
}
}
static T_1 F_33 ( struct V_4 * V_5 ,
struct V_99 * V_89 ,
int V_90 )
{
T_3 V_41 = F_22 ( V_89 -> V_100 ) ;
if ( F_32 ( V_5 , & V_41 , V_90 ) )
return 0 ;
else
return F_18 ( F_17 ( V_89 -> V_80 ) ,
V_101 ) ;
}
static T_1 F_34 ( struct V_4 * V_5 ,
struct V_102 * V_89 ,
T_1 V_103 ,
T_1 V_104 )
{
T_1 V_30 = F_17 ( V_89 -> V_105 ) ;
T_1 V_80 = F_17 ( V_89 -> V_80 ) ;
if ( ! ( F_18 ( V_30 , V_106 ) == V_103 &&
( F_18 ( V_30 , V_107 ) == V_108 ||
F_18 ( V_30 , V_107 ) == V_104 ) ) )
return F_18 ( V_80 , V_109 ) ;
else
return 0 ;
}
int F_35 ( struct V_4 * V_5 ,
struct V_15 * V_16 ,
int V_103 ,
int V_104 ,
int V_90 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
T_1 V_110 , V_111 ;
union V_112 * V_113 ;
bool V_114 = false ;
int V_22 = 0 ;
V_111 = V_2 -> V_48 -> V_115 ;
V_113 = V_2 -> V_48 -> V_113 ;
V_5 -> V_55 = F_10 ( V_54 * 4 , V_116 ) ;
if ( ! V_5 -> V_55 ) {
F_20 ( V_5 , L_6 ) ;
return - V_26 ;
}
for ( V_110 = 0 ; V_110 < V_111 ; V_110 ++ ) {
union V_112 * V_37 = & V_113 [ V_110 ] ;
T_1 V_30 = F_17 ( V_37 -> V_50 . V_80 ) ;
switch ( F_18 ( V_30 , V_117 ) ) {
case V_118 :
V_22 = F_21 ( V_5 , V_16 , & V_37 -> V_119 ,
V_114 ) ;
break;
case V_120 :
F_26 ( V_5 , V_16 , & V_37 -> V_121 ) ;
break;
case V_122 :
V_110 += F_33 ( V_5 , & V_37 -> V_123 ,
V_90 ) ;
break;
case V_124 :
V_110 += F_34 ( V_5 , & V_37 -> V_125 ,
V_103 , V_104 ) ;
V_114 = F_18 ( V_30 , V_126 ) ;
break;
case V_127 :
F_30 ( F_17 ( V_37 -> V_77 . V_77 ) ) ;
break;
case V_128 :
F_31 ( V_5 , V_16 , & V_37 -> V_129 ) ;
break;
}
if ( V_22 )
break;
}
F_11 ( V_5 -> V_55 ) ;
return V_22 ;
}
void F_36 ( struct V_4 * V_5 )
{
T_1 V_130 ;
T_1 V_6 ;
V_130 = V_131 + V_132 ;
for ( V_6 = 0 ; V_6 < F_37 ( V_133 ) ; V_6 ++ )
if ( V_133 [ V_6 ] )
F_38 ( V_5 , V_130 + V_6 * V_134 ,
V_133 [ V_6 ] ) ;
}
int F_39 ( struct V_1 * V_2 , const V_56 * V_30 )
{
struct V_135 * V_136 = V_2 -> V_48 ;
struct V_137 * V_138 ;
T_1 V_41 , V_139 ;
if ( ! V_30 ) {
F_20 ( V_2 , L_7 ) ;
return - V_57 ;
}
V_138 = (struct V_137 * ) ( V_30 + sizeof( T_1 ) ) ;
V_41 = V_138 [ V_140 ] . V_41 ;
V_136 -> V_141 = (struct V_141 * ) ( V_30 + V_41 ) ;
V_41 = V_138 [ V_142 ] . V_41 ;
V_136 -> V_113 = (union V_112 * ) ( V_30 + V_41 ) ;
V_41 = V_138 [ V_143 ] . V_41 ;
V_136 -> V_49 = ( T_1 * ) ( V_30 + V_41 ) ;
V_41 = V_138 [ V_144 ] . V_41 ;
V_136 -> V_91 = ( V_56 * ) ( V_30 + V_41 ) ;
V_139 = V_138 [ V_142 ] . V_145 ;
V_136 -> V_115 = V_139 / sizeof( struct V_146 ) ;
return 0 ;
}
