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
void F_3 ( struct V_4 * V_5 , T_1 V_10 , T_1 V_11 )
{
V_5 -> V_8 . V_12 [ V_10 ] = V_11 ;
V_5 -> V_8 . V_9 [ V_10 ] = true ;
}
void F_4 ( struct V_4 * V_5 ,
T_1 V_10 , T_1 * V_13 , T_2 V_14 )
{
T_2 V_6 ;
for ( V_6 = 0 ; V_6 < V_14 / sizeof( T_1 ) ; V_6 ++ ) {
V_5 -> V_8 . V_12 [ V_10 + V_6 ] = V_13 [ V_6 ] ;
V_5 -> V_8 . V_9 [ V_10 + V_6 ] = true ;
}
}
static int F_5 ( struct V_4 * V_5 ,
struct V_15 * V_16 ,
T_1 V_17 , T_3 V_10 , T_3 V_14 , bool V_18 )
{
T_1 * V_19 = & V_5 -> V_8 . V_12 [ V_10 ] ;
bool * V_20 = & V_5 -> V_8 . V_9 [ V_10 ] ;
T_3 V_6 , V_21 ;
int V_22 = 0 ;
for ( V_6 = 0 ; V_6 < V_14 ; V_6 ++ ) {
if ( ! V_20 [ V_6 ] )
continue;
if ( ! V_18 ) {
F_6 ( V_5 , V_16 , V_17 + ( V_6 << 2 ) , V_19 [ V_6 ] ) ;
continue;
}
for ( V_21 = 1 ; V_6 + V_21 < V_14 ; V_21 ++ )
if ( ! V_20 [ V_6 + V_21 ] )
break;
V_22 = F_7 ( V_5 , V_16 ,
( V_23 ) ( V_19 + V_6 ) ,
V_17 + ( V_6 << 2 ) , V_21 , 0 ) ;
if ( V_22 )
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
T_1 V_17 , T_1 V_31 , T_1 V_32 )
{
static T_1 V_33 [ V_34 ] ;
memset ( V_33 , 0 , sizeof( T_1 ) * V_34 ) ;
return F_7 ( V_5 , V_16 ,
( V_23 ) ( & V_33 [ 0 ] ) ,
V_17 , V_32 , V_35 ) ;
}
static void F_15 ( struct V_4 * V_5 ,
struct V_15 * V_16 ,
T_1 V_17 , T_1 V_31 , T_1 V_32 )
{
T_1 V_6 ;
for ( V_6 = 0 ; V_6 < V_32 ; V_6 ++ , V_17 += sizeof( T_1 ) )
F_6 ( V_5 , V_16 , V_17 , V_31 ) ;
}
static int F_16 ( struct V_4 * V_5 ,
struct V_15 * V_16 ,
struct V_36 * V_37 ,
bool V_18 , bool V_29 )
{
T_1 V_38 = F_17 ( V_37 -> args . V_39 ) ;
T_1 V_30 = F_17 ( V_37 -> V_30 ) ;
T_1 V_17 = F_18 ( V_30 , V_40 ) << 2 ;
T_1 V_41 , V_42 , V_43 , V_44 ;
struct V_1 * V_2 = V_5 -> V_2 ;
union V_45 * V_46 ;
const T_1 * V_47 ;
int V_22 = 0 ;
T_1 V_14 ;
V_47 = V_2 -> V_48 -> V_49 ;
V_46 = (union V_45 * ) ( V_47 + V_38 ) ;
V_30 = F_17 ( V_46 -> V_50 . V_30 ) ;
switch ( F_18 ( V_30 , V_51 ) ) {
case V_52 :
V_41 = V_38 + 1 ;
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
V_38 + 1 ,
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
V_38 + 1 ,
V_14 , V_47 ,
V_18 , V_29 ) ;
break;
}
return V_22 ;
}
static int F_21 ( struct V_4 * V_5 ,
struct V_15 * V_16 ,
struct V_36 * V_64 , bool V_29 )
{
T_1 V_30 = F_17 ( V_64 -> V_30 ) ;
bool V_18 = F_18 ( V_30 , V_65 ) ;
T_1 V_17 = F_18 ( V_30 , V_40 ) << 2 ;
union V_66 * V_67 = & V_64 -> args ;
int V_22 = 0 ;
if ( V_18 && ! V_29 ) {
F_20 ( V_5 ,
L_2 ,
V_17 ) ;
return - V_57 ;
}
switch ( F_18 ( V_30 , V_68 ) ) {
case V_69 :
V_30 = F_17 ( V_64 -> args . V_70 ) ;
F_6 ( V_5 , V_16 , V_17 , V_30 ) ;
break;
case V_71 :
V_30 = F_17 ( V_64 -> args . V_72 ) ;
if ( V_18 || ( V_29 && ( V_30 >= 64 ) ) )
V_22 = F_14 ( V_5 , V_16 , V_17 , 0 , V_30 ) ;
else
F_15 ( V_5 , V_16 , V_17 , 0 , V_30 ) ;
break;
case V_73 :
V_22 = F_16 ( V_5 , V_16 , V_64 ,
V_18 , V_29 ) ;
break;
case V_74 :
F_5 ( V_5 , V_16 , V_17 ,
F_22 ( V_67 -> V_75 . V_41 ) ,
F_22 ( V_67 -> V_75 . V_14 ) ,
V_18 ) ;
break;
}
return V_22 ;
}
static inline bool F_23 ( T_1 V_11 , T_1 V_76 )
{
return V_11 == V_76 ;
}
static inline bool F_24 ( T_1 V_11 , T_1 V_76 )
{
return ( V_11 & V_76 ) == V_76 ;
}
static inline bool F_25 ( T_1 V_11 , T_1 V_76 )
{
return ( V_11 | V_76 ) > 0 ;
}
static void F_26 ( struct V_4 * V_5 ,
struct V_15 * V_16 , struct V_77 * V_37 )
{
bool (* F_27)( T_1 V_11 , T_1 V_76 );
T_1 V_78 = V_79 , V_11 ;
T_1 V_30 , V_17 , V_80 ;
int V_6 ;
V_30 = F_17 ( V_37 -> V_81 ) ;
V_17 = F_18 ( V_30 , V_82 ) << 2 ;
V_80 = F_18 ( V_30 , V_83 ) ;
V_11 = F_28 ( V_5 , V_16 , V_17 ) ;
if ( V_80 == V_84 )
return;
switch ( V_80 ) {
case V_85 :
F_27 = F_23 ;
break;
case V_86 :
F_27 = F_25 ;
break;
case V_87 :
F_27 = F_24 ;
break;
default:
F_29 ( V_5 , L_3 ,
V_37 -> V_81 ) ;
return;
}
V_30 = F_17 ( V_37 -> V_76 ) ;
for ( V_6 = 0 ;
V_6 < V_88 && ! F_27 ( V_11 , V_30 ) ;
V_6 ++ ) {
F_30 ( V_78 ) ;
V_11 = F_28 ( V_5 , V_16 , V_17 ) ;
}
if ( V_6 == V_88 ) {
F_29 ( V_5 ,
L_4 ,
V_17 , F_17 ( V_37 -> V_76 ) ,
V_11 , F_17 ( V_37 -> V_81 ) ) ;
}
}
static void F_31 ( struct V_4 * V_5 ,
struct V_15 * V_16 ,
struct V_89 * V_64 )
{
F_20 ( V_5 , L_5 ) ;
}
static V_56 F_32 ( struct V_4 * V_5 ,
T_3 * V_90 , int V_91 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
const V_56 * V_92 ;
V_56 V_93 , V_94 , V_95 ;
V_92 = V_2 -> V_48 -> V_92 ;
V_95 = V_92 [ ( * V_90 ) ++ ] ;
switch ( V_95 ) {
case V_96 :
return F_32 ( V_5 , V_90 , V_91 ) ^ 1 ;
case V_97 :
V_93 = F_32 ( V_5 , V_90 , V_91 ) ;
V_94 = F_32 ( V_5 , V_90 , V_91 ) ;
return V_93 | V_94 ;
case V_98 :
V_93 = F_32 ( V_5 , V_90 , V_91 ) ;
V_94 = F_32 ( V_5 , V_90 , V_91 ) ;
return V_93 & V_94 ;
default:
V_95 -= V_99 ;
return ( V_91 & F_33 ( V_95 ) ) ? 1 : 0 ;
}
}
static T_1 F_34 ( struct V_4 * V_5 ,
struct V_100 * V_64 , int V_91 )
{
T_3 V_41 = F_22 ( V_64 -> V_101 ) ;
if ( F_32 ( V_5 , & V_41 , V_91 ) )
return 0 ;
else
return F_18 ( F_17 ( V_64 -> V_81 ) ,
V_102 ) ;
}
static T_1 F_35 ( struct V_4 * V_5 ,
struct V_103 * V_64 ,
T_1 V_104 , T_1 V_105 )
{
T_1 V_30 = F_17 ( V_64 -> V_106 ) ;
T_1 V_81 = F_17 ( V_64 -> V_81 ) ;
if ( ! ( F_18 ( V_30 , V_107 ) == V_104 &&
( F_18 ( V_30 , V_108 ) == V_109 ||
F_18 ( V_30 , V_108 ) == V_105 ) ) )
return F_18 ( V_81 , V_110 ) ;
else
return 0 ;
}
int F_36 ( struct V_4 * V_5 ,
struct V_15 * V_16 , int V_104 , int V_105 , int V_91 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
T_1 V_111 , V_112 ;
union V_113 * V_114 ;
bool V_115 = false ;
int V_22 = 0 ;
V_112 = V_2 -> V_48 -> V_116 ;
V_114 = V_2 -> V_48 -> V_114 ;
V_5 -> V_55 = F_10 ( V_54 * 4 , V_117 ) ;
if ( ! V_5 -> V_55 )
return - V_26 ;
for ( V_111 = 0 ; V_111 < V_112 ; V_111 ++ ) {
union V_113 * V_37 = & V_114 [ V_111 ] ;
T_1 V_30 = F_17 ( V_37 -> V_50 . V_81 ) ;
switch ( F_18 ( V_30 , V_118 ) ) {
case V_119 :
V_22 = F_21 ( V_5 , V_16 , & V_37 -> V_120 ,
V_115 ) ;
break;
case V_121 :
F_26 ( V_5 , V_16 , & V_37 -> V_122 ) ;
break;
case V_123 :
V_111 += F_34 ( V_5 , & V_37 -> V_124 ,
V_91 ) ;
break;
case V_125 :
V_111 += F_35 ( V_5 , & V_37 -> V_126 ,
V_104 , V_105 ) ;
V_115 = F_18 ( V_30 , V_127 ) ;
break;
case V_128 :
F_30 ( F_17 ( V_37 -> V_78 . V_78 ) ) ;
break;
case V_129 :
F_31 ( V_5 , V_16 , & V_37 -> V_130 ) ;
break;
}
if ( V_22 )
break;
}
F_11 ( V_5 -> V_55 ) ;
return V_22 ;
}
void F_37 ( struct V_4 * V_5 )
{
T_1 V_131 ;
T_1 V_6 ;
V_131 = V_132 + V_133 ;
for ( V_6 = 0 ; V_6 < F_38 ( V_134 ) ; V_6 ++ )
if ( V_134 [ V_6 ] )
F_39 ( V_5 , V_131 + V_6 * V_135 ,
V_134 [ V_6 ] ) ;
}
int F_40 ( struct V_1 * V_2 , const V_56 * V_30 )
{
struct V_136 * V_137 = V_2 -> V_48 ;
struct V_138 * V_139 ;
T_1 V_41 , V_140 ;
if ( ! V_30 ) {
F_20 ( V_2 , L_6 ) ;
return - V_57 ;
}
V_139 = (struct V_138 * ) V_30 ;
V_41 = V_139 [ V_141 ] . V_41 ;
V_137 -> V_142 = (struct V_142 * ) ( V_30 + V_41 ) ;
V_41 = V_139 [ V_143 ] . V_41 ;
V_137 -> V_114 = (union V_113 * ) ( V_30 + V_41 ) ;
V_41 = V_139 [ V_144 ] . V_41 ;
V_137 -> V_49 = ( T_1 * ) ( V_30 + V_41 ) ;
V_41 = V_139 [ V_145 ] . V_41 ;
V_137 -> V_92 = ( V_56 * ) ( V_30 + V_41 ) ;
V_140 = V_139 [ V_143 ] . V_146 ;
V_137 -> V_116 = V_140 / sizeof( struct V_147 ) ;
return 0 ;
}
