static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return & V_2 -> V_3 . V_4 . V_5 ;
}
static bool F_2 ( const struct V_6 * V_7 , unsigned int V_8 ,
struct V_9 * V_10 )
{
const struct V_11 * V_12 ;
struct V_11 V_13 ;
V_12 = F_3 ( V_7 , V_8 , 8 , & V_13 ) ;
if ( V_12 == NULL )
return false ;
V_10 -> V_14 . V_15 . V_5 . V_16 = V_12 -> V_17 ;
V_10 -> V_18 . V_15 . V_5 . V_16 = V_12 -> V_19 ;
return true ;
}
static bool F_4 ( struct V_9 * V_10 ,
const struct V_9 * V_20 )
{
V_10 -> V_14 . V_15 . V_5 . V_16 = V_20 -> V_18 . V_15 . V_5 . V_16 ;
V_10 -> V_18 . V_15 . V_5 . V_16 = V_20 -> V_14 . V_15 . V_5 . V_16 ;
return true ;
}
static int F_5 ( struct V_21 * V_22 ,
const struct V_9 * V_10 )
{
return F_6 ( V_22 , L_1 ,
F_7 ( V_10 -> V_14 . V_15 . V_5 . V_16 ) ,
F_7 ( V_10 -> V_18 . V_15 . V_5 . V_16 ) ) ;
}
static int F_8 ( struct V_21 * V_22 , struct V_23 * V_3 )
{
enum V_24 V_25 ;
F_9 ( & V_3 -> V_26 ) ;
V_25 = V_3 -> V_27 . V_5 . V_25 ;
F_10 ( & V_3 -> V_26 ) ;
return F_6 ( V_22 , L_2 , V_28 [ V_25 ] ) ;
}
static unsigned int F_11 ( const struct V_11 * V_29 )
{
if ( V_29 -> V_30 ) return V_31 ;
else if ( V_29 -> V_32 ) return ( V_29 -> V_33 ? V_34 : V_35 ) ;
else if ( V_29 -> V_36 ) return V_37 ;
else if ( V_29 -> V_33 ) return V_38 ;
else return V_39 ;
}
static inline T_1 F_12 ( T_1 V_40 ,
T_2 V_41 ,
unsigned int V_8 ,
const struct V_11 * V_29 )
{
return ( V_40 + V_41 - V_8 - V_29 -> V_42 * 4
+ ( V_29 -> V_32 ? 1 : 0 ) + ( V_29 -> V_36 ? 1 : 0 ) ) ;
}
static void F_13 ( const struct V_6 * V_7 ,
unsigned int V_8 ,
const struct V_11 * V_29 ,
struct V_43 * V_25 )
{
unsigned char V_44 [ ( 15 * 4 ) - sizeof( struct V_11 ) ] ;
const unsigned char * V_45 ;
int V_46 = ( V_29 -> V_42 * 4 ) - sizeof( struct V_11 ) ;
if ( ! V_46 )
return;
V_45 = F_3 ( V_7 , V_8 + sizeof( struct V_11 ) ,
V_46 , V_44 ) ;
F_14 ( V_45 == NULL ) ;
V_25 -> V_47 =
V_25 -> V_48 = 0 ;
while ( V_46 > 0 ) {
int V_49 = * V_45 ++ ;
int V_50 ;
switch ( V_49 ) {
case V_51 :
return;
case V_52 :
V_46 -- ;
continue;
default:
V_50 = * V_45 ++ ;
if ( V_50 < 2 )
return;
if ( V_50 > V_46 )
return;
if ( V_49 == V_53
&& V_50 == V_54 )
V_25 -> V_48 |= V_55 ;
else if ( V_49 == V_56
&& V_50 == V_57 ) {
V_25 -> V_47 = * ( V_58 * ) V_45 ;
if ( V_25 -> V_47 > 14 ) {
V_25 -> V_47 = 14 ;
}
V_25 -> V_48 |=
V_59 ;
}
V_45 += V_50 - 2 ;
V_46 -= V_50 ;
}
}
}
static void F_15 ( const struct V_6 * V_7 , unsigned int V_8 ,
const struct V_11 * V_29 , T_1 * V_60 )
{
unsigned char V_44 [ ( 15 * 4 ) - sizeof( struct V_11 ) ] ;
const unsigned char * V_45 ;
int V_46 = ( V_29 -> V_42 * 4 ) - sizeof( struct V_11 ) ;
T_1 V_61 ;
if ( ! V_46 )
return;
V_45 = F_3 ( V_7 , V_8 + sizeof( struct V_11 ) ,
V_46 , V_44 ) ;
F_14 ( V_45 == NULL ) ;
if ( V_46 == V_62
&& * ( V_63 * ) V_45 == F_16 ( ( V_52 << 24 )
| ( V_52 << 16 )
| ( V_64 << 8 )
| V_65 ) )
return;
while ( V_46 > 0 ) {
int V_49 = * V_45 ++ ;
int V_50 , V_66 ;
switch ( V_49 ) {
case V_51 :
return;
case V_52 :
V_46 -- ;
continue;
default:
V_50 = * V_45 ++ ;
if ( V_50 < 2 )
return;
if ( V_50 > V_46 )
return;
if ( V_49 == V_67
&& V_50 >= ( V_68
+ V_69 )
&& ! ( ( V_50 - V_68 )
% V_69 ) ) {
for ( V_66 = 0 ;
V_66 < ( V_50 - V_68 ) ;
V_66 += V_69 ) {
V_61 = F_17 ( ( V_63 * ) ( V_45 + V_66 ) + 1 ) ;
if ( F_18 ( V_61 , * V_60 ) )
* V_60 = V_61 ;
}
return;
}
V_45 += V_50 - 2 ;
V_46 -= V_50 ;
}
}
}
static inline T_3 F_19 ( const struct V_23 * V_3 ,
enum V_70 V_71 ,
T_4 V_40 )
{
F_20 (nf_ct_nat_offset) V_72 = F_21 ( V_73 ) ;
return V_72 != NULL ? V_72 ( V_3 , V_71 , V_40 ) : 0 ;
}
static bool F_22 ( const struct V_23 * V_3 ,
struct V_74 * V_25 ,
enum V_70 V_71 ,
unsigned int V_75 ,
const struct V_6 * V_7 ,
unsigned int V_8 ,
const struct V_11 * V_29 ,
V_58 V_76 )
{
struct V_2 * V_2 = F_23 ( V_3 ) ;
struct V_1 * V_77 = F_1 ( V_2 ) ;
struct V_43 * V_78 = & V_25 -> V_79 [ V_71 ] ;
struct V_43 * V_80 = & V_25 -> V_79 [ ! V_71 ] ;
const struct V_9 * V_10 = & V_3 -> V_81 [ V_71 ] . V_10 ;
T_1 V_40 , V_33 , V_60 , V_82 , V_83 , V_84 ;
T_3 V_85 ;
bool V_86 ;
V_40 = F_24 ( V_29 -> V_40 ) ;
V_33 = V_60 = F_24 ( V_29 -> V_87 ) ;
V_83 = F_7 ( V_29 -> V_88 ) ;
V_82 = F_12 ( V_40 , V_7 -> V_41 , V_8 , V_29 ) ;
if ( V_80 -> V_48 & V_55 )
F_15 ( V_7 , V_8 , V_29 , & V_60 ) ;
V_85 = F_25 ( V_3 , ! V_71 , V_33 - 1 ) ;
V_33 -= V_85 ;
V_60 -= V_85 ;
F_26 ( L_3 ) ;
F_26 ( L_4 ) ;
F_27 ( V_10 ) ;
F_26 ( L_5 ,
V_40 , V_33 , V_85 , V_60 , V_85 , V_83 , V_82 ) ;
F_26 ( L_6
L_7 ,
V_78 -> V_89 , V_78 -> V_90 , V_78 -> V_91 ,
V_78 -> V_47 ,
V_80 -> V_89 , V_80 -> V_90 , V_80 -> V_91 ,
V_80 -> V_47 ) ;
if ( V_78 -> V_91 == 0 ) {
if ( V_29 -> V_32 ) {
V_78 -> V_89 =
V_78 -> V_90 = V_82 ;
V_78 -> V_91 = ( V_83 == 0 ? 1 : V_83 ) ;
F_13 ( V_7 , V_8 , V_29 , V_78 ) ;
if ( ! ( V_78 -> V_48 & V_59
&& V_80 -> V_48 & V_59 ) )
V_78 -> V_47 =
V_80 -> V_47 = 0 ;
if ( ! V_29 -> V_33 )
return true ;
} else {
V_78 -> V_89 = V_82 ;
V_84 = V_83 << V_78 -> V_47 ;
V_78 -> V_91 = ( V_84 == 0 ? 1 : V_84 ) ;
V_78 -> V_90 = V_82 + V_78 -> V_91 ;
if ( V_80 -> V_91 == 0 )
V_80 -> V_89 = V_80 -> V_90 = V_60 ;
}
} else if ( ( ( V_25 -> V_25 == V_92
&& V_71 == V_93 )
|| ( V_25 -> V_25 == V_94
&& V_71 == V_95 ) )
&& F_18 ( V_82 , V_78 -> V_89 ) ) {
V_78 -> V_89 =
V_78 -> V_90 = V_82 ;
V_78 -> V_91 = ( V_83 == 0 ? 1 : V_83 ) ;
F_13 ( V_7 , V_8 , V_29 , V_78 ) ;
}
if ( ! ( V_29 -> V_33 ) ) {
V_33 = V_60 = V_80 -> V_89 ;
} else if ( ( ( F_28 ( V_29 ) & ( V_96 | V_97 ) ) ==
( V_96 | V_97 ) )
&& ( V_33 == 0 ) ) {
V_33 = V_60 = V_80 -> V_89 ;
}
if ( V_29 -> V_30 && V_40 == 0 && V_25 -> V_25 == V_92 )
V_40 = V_82 = V_78 -> V_89 ;
F_26 ( L_4 ) ;
F_27 ( V_10 ) ;
F_26 ( L_5 ,
V_40 , V_33 , V_85 , V_60 , V_85 , V_83 , V_82 ) ;
F_26 ( L_6
L_7 ,
V_78 -> V_89 , V_78 -> V_90 , V_78 -> V_91 ,
V_78 -> V_47 ,
V_80 -> V_89 , V_80 -> V_90 , V_80 -> V_91 ,
V_80 -> V_47 ) ;
F_26 ( L_8 ,
F_29 ( V_40 , V_78 -> V_90 + 1 ) ,
F_18 ( V_82 , V_78 -> V_89 - V_80 -> V_91 - 1 ) ,
F_29 ( V_60 , V_80 -> V_89 + 1 ) ,
F_18 ( V_60 , V_80 -> V_89 - F_30 ( V_78 ) - 1 ) ) ;
if ( F_29 ( V_40 , V_78 -> V_90 + 1 ) &&
F_18 ( V_82 , V_78 -> V_89 - V_80 -> V_91 - 1 ) &&
F_29 ( V_60 , V_80 -> V_89 + 1 ) &&
F_18 ( V_60 , V_80 -> V_89 - F_30 ( V_78 ) - 1 ) ) {
if ( ! V_29 -> V_32 )
V_83 <<= V_78 -> V_47 ;
V_84 = V_83 + ( V_60 - V_33 ) ;
if ( V_78 -> V_91 < V_84 )
V_78 -> V_91 = V_84 ;
if ( F_18 ( V_82 , V_78 -> V_89 ) ) {
V_78 -> V_89 = V_82 ;
V_78 -> V_48 |= V_98 ;
}
if ( V_29 -> V_33 ) {
if ( ! ( V_78 -> V_48 & V_99 ) ) {
V_78 -> V_100 = V_33 ;
V_78 -> V_48 |= V_99 ;
} else if ( F_18 ( V_33 , V_78 -> V_100 ) )
V_78 -> V_100 = V_33 ;
}
if ( V_80 -> V_91 != 0 && F_18 ( V_82 , V_78 -> V_90 ) )
V_80 -> V_91 += V_82 - V_78 -> V_90 ;
if ( F_18 ( V_60 + V_83 , V_80 -> V_90 - 1 ) ) {
V_80 -> V_90 = V_60 + V_83 ;
if ( V_83 == 0 )
V_80 -> V_90 ++ ;
}
if ( V_33 == V_80 -> V_89 )
V_80 -> V_48 &= ~ V_98 ;
if ( V_75 == V_38 ) {
if ( V_25 -> V_101 == V_71
&& V_25 -> V_102 == V_40
&& V_25 -> V_103 == V_33
&& V_25 -> V_104 == V_82
&& V_25 -> V_105 == V_83 )
V_25 -> V_106 ++ ;
else {
V_25 -> V_101 = V_71 ;
V_25 -> V_102 = V_40 ;
V_25 -> V_103 = V_33 ;
V_25 -> V_104 = V_82 ;
V_25 -> V_105 = V_83 ;
V_25 -> V_106 = 0 ;
}
}
V_86 = true ;
} else {
V_86 = false ;
if ( V_78 -> V_48 & V_107 ||
V_77 -> V_108 )
V_86 = true ;
if ( ! V_86 && F_31 ( V_2 , V_109 ) )
F_32 ( V_2 , V_76 , 0 , V_7 , NULL , NULL , NULL ,
L_9 ,
F_29 ( V_40 , V_78 -> V_90 + 1 ) ?
F_18 ( V_82 , V_78 -> V_89 - V_80 -> V_91 - 1 ) ?
F_29 ( V_60 , V_80 -> V_89 + 1 ) ?
F_18 ( V_60 , V_80 -> V_89 - F_30 ( V_78 ) - 1 ) ? L_10
: L_11
: L_12
: L_13
: L_14 ) ;
}
F_26 ( L_15
L_16 ,
V_86 , V_78 -> V_89 , V_78 -> V_90 , V_78 -> V_91 ,
V_80 -> V_89 , V_80 -> V_90 , V_80 -> V_91 ) ;
return V_86 ;
}
static int F_33 ( struct V_2 * V_2 , struct V_23 * V_110 ,
struct V_6 * V_7 ,
unsigned int V_8 ,
enum V_111 * V_112 ,
V_58 V_76 ,
unsigned int V_113 )
{
const struct V_11 * V_114 ;
struct V_11 V_115 ;
unsigned int V_116 = V_7 -> V_41 - V_8 ;
V_58 V_117 ;
V_114 = F_3 ( V_7 , V_8 , sizeof( V_115 ) , & V_115 ) ;
if ( V_114 == NULL ) {
if ( F_31 ( V_2 , V_109 ) )
F_32 ( V_2 , V_76 , 0 , V_7 , NULL , NULL , NULL ,
L_17 ) ;
return - V_118 ;
}
if ( V_114 -> V_42 * 4 < sizeof( struct V_11 ) || V_116 < V_114 -> V_42 * 4 ) {
if ( F_31 ( V_2 , V_109 ) )
F_32 ( V_2 , V_76 , 0 , V_7 , NULL , NULL , NULL ,
L_18 ) ;
return - V_118 ;
}
if ( V_2 -> V_3 . V_119 && V_113 == V_120 &&
F_34 ( V_7 , V_113 , V_8 , V_109 , V_76 ) ) {
if ( F_31 ( V_2 , V_109 ) )
F_32 ( V_2 , V_76 , 0 , V_7 , NULL , NULL , NULL ,
L_19 ) ;
return - V_118 ;
}
V_117 = ( F_35 ( V_114 ) & ~ ( V_121 | V_122 | V_123 ) ) ;
if ( ! V_124 [ V_117 ] ) {
if ( F_31 ( V_2 , V_109 ) )
F_32 ( V_2 , V_76 , 0 , V_7 , NULL , NULL , NULL ,
L_20 ) ;
return - V_118 ;
}
return V_118 ;
}
static unsigned int * F_36 ( struct V_2 * V_2 )
{
return F_1 ( V_2 ) -> V_125 ;
}
static int F_37 ( struct V_23 * V_3 ,
const struct V_6 * V_7 ,
unsigned int V_8 ,
enum V_111 V_112 ,
V_58 V_76 ,
unsigned int V_113 ,
unsigned int * V_125 )
{
struct V_2 * V_2 = F_23 ( V_3 ) ;
struct V_1 * V_77 = F_1 ( V_2 ) ;
struct V_9 * V_10 ;
enum V_24 V_126 , V_127 ;
enum V_70 V_71 ;
const struct V_11 * V_114 ;
struct V_11 V_115 ;
unsigned long V_128 ;
unsigned int V_75 ;
V_114 = F_3 ( V_7 , V_8 , sizeof( V_115 ) , & V_115 ) ;
F_14 ( V_114 == NULL ) ;
F_9 ( & V_3 -> V_26 ) ;
V_127 = V_3 -> V_27 . V_5 . V_25 ;
V_71 = F_38 ( V_112 ) ;
V_75 = F_11 ( V_114 ) ;
V_126 = V_129 [ V_71 ] [ V_75 ] [ V_127 ] ;
V_10 = & V_3 -> V_81 [ V_71 ] . V_10 ;
switch ( V_126 ) {
case V_92 :
if ( V_127 < V_130 )
break;
if ( ( ( V_3 -> V_27 . V_5 . V_79 [ V_71 ] . V_48
| V_3 -> V_27 . V_5 . V_79 [ ! V_71 ] . V_48 )
& V_131 )
|| ( V_3 -> V_27 . V_5 . V_101 == V_71
&& V_3 -> V_27 . V_5 . V_132 == V_31 ) ) {
F_10 ( & V_3 -> V_26 ) ;
if ( F_39 ( V_3 ) )
return - V_133 ;
return V_134 ;
}
case V_135 :
if ( V_75 == V_34
&& V_3 -> V_27 . V_5 . V_132 == V_35
&& V_3 -> V_27 . V_5 . V_101 != V_71
&& F_24 ( V_114 -> V_87 ) == V_3 -> V_27 . V_5 . V_104 ) {
V_127 = V_92 ;
V_126 = V_94 ;
V_3 -> V_27 . V_5 . V_79 [ V_3 -> V_27 . V_5 . V_101 ] . V_89 =
V_3 -> V_27 . V_5 . V_104 ;
V_3 -> V_27 . V_5 . V_79 [ V_3 -> V_27 . V_5 . V_101 ] . V_90 =
V_3 -> V_27 . V_5 . V_104 ;
V_3 -> V_27 . V_5 . V_79 [ V_3 -> V_27 . V_5 . V_101 ] . V_91 =
V_3 -> V_27 . V_5 . V_105 == 0 ?
1 : V_3 -> V_27 . V_5 . V_105 ;
V_3 -> V_27 . V_5 . V_79 [ V_3 -> V_27 . V_5 . V_101 ] . V_47 =
V_3 -> V_27 . V_5 . V_136 ;
V_3 -> V_27 . V_5 . V_79 [ V_3 -> V_27 . V_5 . V_101 ] . V_48 =
V_3 -> V_27 . V_5 . V_137 ;
memset ( & V_3 -> V_27 . V_5 . V_79 [ V_71 ] , 0 ,
sizeof( struct V_43 ) ) ;
break;
}
V_3 -> V_27 . V_5 . V_132 = V_75 ;
V_3 -> V_27 . V_5 . V_101 = V_71 ;
V_3 -> V_27 . V_5 . V_102 = F_24 ( V_114 -> V_40 ) ;
V_3 -> V_27 . V_5 . V_104 =
F_12 ( F_24 ( V_114 -> V_40 ) , V_7 -> V_41 , V_8 , V_114 ) ;
V_3 -> V_27 . V_5 . V_105 = F_7 ( V_114 -> V_88 ) ;
if ( V_75 == V_35 && V_71 == V_93 ) {
struct V_43 V_79 = {} ;
V_3 -> V_27 . V_5 . V_137 =
V_3 -> V_27 . V_5 . V_136 = 0 ;
F_13 ( V_7 , V_8 , V_114 , & V_79 ) ;
if ( V_79 . V_48 & V_59 ) {
V_3 -> V_27 . V_5 . V_137 |=
V_59 ;
V_3 -> V_27 . V_5 . V_136 = V_79 . V_47 ;
}
if ( V_79 . V_48 & V_55 ) {
V_3 -> V_27 . V_5 . V_137 |=
V_55 ;
}
}
F_10 ( & V_3 -> V_26 ) ;
if ( F_31 ( V_2 , V_109 ) )
F_32 ( V_2 , V_76 , 0 , V_7 , NULL , NULL , NULL ,
L_21
L_22 , V_28 [ V_127 ] ) ;
return V_118 ;
case V_138 :
F_26 ( L_23 ,
V_71 , F_11 ( V_114 ) , V_127 ) ;
F_10 ( & V_3 -> V_26 ) ;
if ( F_31 ( V_2 , V_109 ) )
F_32 ( V_2 , V_76 , 0 , V_7 , NULL , NULL , NULL ,
L_24 ) ;
return - V_118 ;
case V_139 :
if ( V_75 == V_31
&& ( V_3 -> V_27 . V_5 . V_79 [ ! V_71 ] . V_48 & V_99 )
&& F_29 ( F_24 ( V_114 -> V_40 ) , V_3 -> V_27 . V_5 . V_79 [ ! V_71 ] . V_100 ) ) {
F_10 ( & V_3 -> V_26 ) ;
if ( F_31 ( V_2 , V_109 ) )
F_32 ( V_2 , V_76 , 0 , V_7 , NULL , NULL ,
NULL , L_25 ) ;
return - V_118 ;
}
if ( V_75 == V_31
&& ( ( F_40 ( V_140 , & V_3 -> V_141 )
&& V_3 -> V_27 . V_5 . V_132 == V_35 )
|| ( ! F_40 ( V_142 , & V_3 -> V_141 )
&& V_3 -> V_27 . V_5 . V_132 == V_38 ) )
&& F_24 ( V_114 -> V_87 ) == V_3 -> V_27 . V_5 . V_104 ) {
goto V_143;
}
default:
break;
}
if ( ! F_22 ( V_3 , & V_3 -> V_27 . V_5 , V_71 , V_75 ,
V_7 , V_8 , V_114 , V_76 ) ) {
F_10 ( & V_3 -> V_26 ) ;
return - V_118 ;
}
V_143:
V_3 -> V_27 . V_5 . V_132 = V_75 ;
V_3 -> V_27 . V_5 . V_101 = V_71 ;
F_26 ( L_26 ) ;
F_27 ( V_10 ) ;
F_26 ( L_27 ,
( V_114 -> V_32 ? 1 : 0 ) , ( V_114 -> V_33 ? 1 : 0 ) ,
( V_114 -> V_36 ? 1 : 0 ) , ( V_114 -> V_30 ? 1 : 0 ) ,
V_127 , V_126 ) ;
V_3 -> V_27 . V_5 . V_25 = V_126 ;
if ( V_127 != V_126
&& V_126 == V_144 )
V_3 -> V_27 . V_5 . V_79 [ V_71 ] . V_48 |= V_131 ;
if ( V_3 -> V_27 . V_5 . V_106 >= V_77 -> V_145 &&
V_125 [ V_126 ] > V_125 [ V_146 ] )
V_128 = V_125 [ V_146 ] ;
else if ( ( V_3 -> V_27 . V_5 . V_79 [ 0 ] . V_48 | V_3 -> V_27 . V_5 . V_79 [ 1 ] . V_48 ) &
V_98 &&
V_125 [ V_126 ] > V_125 [ V_147 ] )
V_128 = V_125 [ V_147 ] ;
else
V_128 = V_125 [ V_126 ] ;
F_10 ( & V_3 -> V_26 ) ;
if ( V_126 != V_127 )
F_41 ( V_148 , V_3 ) ;
if ( ! F_40 ( V_140 , & V_3 -> V_141 ) ) {
if ( V_114 -> V_30 ) {
F_42 ( V_3 , V_112 , V_7 ) ;
return V_118 ;
}
} else if ( ! F_40 ( V_142 , & V_3 -> V_141 )
&& ( V_127 == V_94
|| V_127 == V_149 )
&& V_126 == V_149 ) {
F_43 ( V_142 , & V_3 -> V_141 ) ;
F_41 ( V_150 , V_3 ) ;
}
F_44 ( V_3 , V_112 , V_7 , V_128 ) ;
return V_118 ;
}
static bool F_45 ( struct V_23 * V_3 , const struct V_6 * V_7 ,
unsigned int V_8 , unsigned int * V_125 )
{
enum V_24 V_126 ;
const struct V_11 * V_114 ;
struct V_11 V_115 ;
struct V_2 * V_2 = F_23 ( V_3 ) ;
struct V_1 * V_77 = F_1 ( V_2 ) ;
const struct V_43 * V_78 = & V_3 -> V_27 . V_5 . V_79 [ 0 ] ;
const struct V_43 * V_80 = & V_3 -> V_27 . V_5 . V_79 [ 1 ] ;
V_114 = F_3 ( V_7 , V_8 , sizeof( V_115 ) , & V_115 ) ;
F_14 ( V_114 == NULL ) ;
V_126 = V_129 [ 0 ] [ F_11 ( V_114 ) ] [ V_151 ] ;
if ( V_126 >= V_138 ) {
F_26 ( L_28 ) ;
return false ;
}
if ( V_126 == V_92 ) {
memset ( & V_3 -> V_27 . V_5 , 0 , sizeof( V_3 -> V_27 . V_5 ) ) ;
V_3 -> V_27 . V_5 . V_79 [ 0 ] . V_89 =
F_12 ( F_24 ( V_114 -> V_40 ) , V_7 -> V_41 ,
V_8 , V_114 ) ;
V_3 -> V_27 . V_5 . V_79 [ 0 ] . V_91 = F_7 ( V_114 -> V_88 ) ;
if ( V_3 -> V_27 . V_5 . V_79 [ 0 ] . V_91 == 0 )
V_3 -> V_27 . V_5 . V_79 [ 0 ] . V_91 = 1 ;
V_3 -> V_27 . V_5 . V_79 [ 0 ] . V_90 =
V_3 -> V_27 . V_5 . V_79 [ 0 ] . V_89 ;
F_13 ( V_7 , V_8 , V_114 , & V_3 -> V_27 . V_5 . V_79 [ 0 ] ) ;
} else if ( V_77 -> V_152 == 0 ) {
return false ;
} else {
memset ( & V_3 -> V_27 . V_5 , 0 , sizeof( V_3 -> V_27 . V_5 ) ) ;
V_3 -> V_27 . V_5 . V_79 [ 0 ] . V_89 =
F_12 ( F_24 ( V_114 -> V_40 ) , V_7 -> V_41 ,
V_8 , V_114 ) ;
V_3 -> V_27 . V_5 . V_79 [ 0 ] . V_91 = F_7 ( V_114 -> V_88 ) ;
if ( V_3 -> V_27 . V_5 . V_79 [ 0 ] . V_91 == 0 )
V_3 -> V_27 . V_5 . V_79 [ 0 ] . V_91 = 1 ;
V_3 -> V_27 . V_5 . V_79 [ 0 ] . V_90 =
V_3 -> V_27 . V_5 . V_79 [ 0 ] . V_89 +
V_3 -> V_27 . V_5 . V_79 [ 0 ] . V_91 ;
V_3 -> V_27 . V_5 . V_79 [ 0 ] . V_48 =
V_3 -> V_27 . V_5 . V_79 [ 1 ] . V_48 = V_55 |
V_107 ;
}
V_3 -> V_27 . V_5 . V_132 = V_39 ;
F_26 ( L_29
L_7 ,
V_78 -> V_89 , V_78 -> V_90 , V_78 -> V_91 ,
V_78 -> V_47 ,
V_80 -> V_89 , V_80 -> V_90 , V_80 -> V_91 ,
V_80 -> V_47 ) ;
return true ;
}
static int F_46 ( struct V_6 * V_7 , struct V_153 * V_154 ,
struct V_23 * V_3 )
{
struct V_153 * V_155 ;
struct V_156 V_61 = {} ;
F_9 ( & V_3 -> V_26 ) ;
V_155 = F_47 ( V_7 , V_157 | V_158 ) ;
if ( ! V_155 )
goto V_159;
if ( F_48 ( V_7 , V_160 , V_3 -> V_27 . V_5 . V_25 ) ||
F_48 ( V_7 , V_161 ,
V_3 -> V_27 . V_5 . V_79 [ 0 ] . V_47 ) ||
F_48 ( V_7 , V_162 ,
V_3 -> V_27 . V_5 . V_79 [ 1 ] . V_47 ) )
goto V_159;
V_61 . V_48 = V_3 -> V_27 . V_5 . V_79 [ 0 ] . V_48 ;
if ( F_49 ( V_7 , V_163 ,
sizeof( struct V_156 ) , & V_61 ) )
goto V_159;
V_61 . V_48 = V_3 -> V_27 . V_5 . V_79 [ 1 ] . V_48 ;
if ( F_49 ( V_7 , V_164 ,
sizeof( struct V_156 ) , & V_61 ) )
goto V_159;
F_10 ( & V_3 -> V_26 ) ;
F_50 ( V_7 , V_155 ) ;
return 0 ;
V_159:
F_10 ( & V_3 -> V_26 ) ;
return - 1 ;
}
static int F_51 ( struct V_153 * V_165 [] , struct V_23 * V_3 )
{
struct V_153 * V_166 = V_165 [ V_157 ] ;
struct V_153 * V_167 [ V_168 + 1 ] ;
int V_169 ;
if ( ! V_166 )
return 0 ;
V_169 = F_52 ( V_167 , V_168 , V_166 , V_170 ) ;
if ( V_169 < 0 )
return V_169 ;
if ( V_167 [ V_160 ] &&
F_53 ( V_167 [ V_160 ] ) >= V_138 )
return - V_171 ;
F_9 ( & V_3 -> V_26 ) ;
if ( V_167 [ V_160 ] )
V_3 -> V_27 . V_5 . V_25 = F_53 ( V_167 [ V_160 ] ) ;
if ( V_167 [ V_163 ] ) {
struct V_156 * V_172 =
F_54 ( V_167 [ V_163 ] ) ;
V_3 -> V_27 . V_5 . V_79 [ 0 ] . V_48 &= ~ V_172 -> V_173 ;
V_3 -> V_27 . V_5 . V_79 [ 0 ] . V_48 |= V_172 -> V_48 & V_172 -> V_173 ;
}
if ( V_167 [ V_164 ] ) {
struct V_156 * V_172 =
F_54 ( V_167 [ V_164 ] ) ;
V_3 -> V_27 . V_5 . V_79 [ 1 ] . V_48 &= ~ V_172 -> V_173 ;
V_3 -> V_27 . V_5 . V_79 [ 1 ] . V_48 |= V_172 -> V_48 & V_172 -> V_173 ;
}
if ( V_167 [ V_161 ] &&
V_167 [ V_162 ] &&
V_3 -> V_27 . V_5 . V_79 [ 0 ] . V_48 & V_59 &&
V_3 -> V_27 . V_5 . V_79 [ 1 ] . V_48 & V_59 ) {
V_3 -> V_27 . V_5 . V_79 [ 0 ] . V_47 =
F_53 ( V_167 [ V_161 ] ) ;
V_3 -> V_27 . V_5 . V_79 [ 1 ] . V_47 =
F_53 ( V_167 [ V_162 ] ) ;
}
F_10 ( & V_3 -> V_26 ) ;
return 0 ;
}
static int F_55 ( void )
{
return F_56 ( 0 )
+ F_57 ( V_170 , V_168 + 1 ) ;
}
static int F_58 ( void )
{
return F_57 ( V_174 , V_175 + 1 ) ;
}
static int F_59 ( struct V_153 * V_167 [] ,
struct V_2 * V_2 , void * V_176 )
{
unsigned int * V_125 = V_176 ;
struct V_1 * V_77 = F_1 ( V_2 ) ;
int V_66 ;
for ( V_66 = 0 ; V_66 < V_177 ; V_66 ++ )
V_125 [ V_66 ] = V_77 -> V_125 [ V_66 ] ;
if ( V_167 [ V_178 ] ) {
V_125 [ V_92 ] =
F_24 ( F_60 ( V_167 [ V_178 ] ) ) * V_179 ;
}
if ( V_167 [ V_180 ] ) {
V_125 [ V_94 ] =
F_24 ( F_60 ( V_167 [ V_180 ] ) ) * V_179 ;
}
if ( V_167 [ V_181 ] ) {
V_125 [ V_149 ] =
F_24 ( F_60 ( V_167 [ V_181 ] ) ) * V_179 ;
}
if ( V_167 [ V_182 ] ) {
V_125 [ V_144 ] =
F_24 ( F_60 ( V_167 [ V_182 ] ) ) * V_179 ;
}
if ( V_167 [ V_183 ] ) {
V_125 [ V_184 ] =
F_24 ( F_60 ( V_167 [ V_183 ] ) ) * V_179 ;
}
if ( V_167 [ V_185 ] ) {
V_125 [ V_186 ] =
F_24 ( F_60 ( V_167 [ V_185 ] ) ) * V_179 ;
}
if ( V_167 [ V_187 ] ) {
V_125 [ V_130 ] =
F_24 ( F_60 ( V_167 [ V_187 ] ) ) * V_179 ;
}
if ( V_167 [ V_188 ] ) {
V_125 [ V_139 ] =
F_24 ( F_60 ( V_167 [ V_188 ] ) ) * V_179 ;
}
if ( V_167 [ V_189 ] ) {
V_125 [ V_190 ] =
F_24 ( F_60 ( V_167 [ V_189 ] ) ) * V_179 ;
}
if ( V_167 [ V_191 ] ) {
V_125 [ V_146 ] =
F_24 ( F_60 ( V_167 [ V_191 ] ) ) * V_179 ;
}
if ( V_167 [ V_192 ] ) {
V_125 [ V_147 ] =
F_24 ( F_60 ( V_167 [ V_192 ] ) ) * V_179 ;
}
return 0 ;
}
static int
F_61 ( struct V_6 * V_7 , const void * V_176 )
{
const unsigned int * V_125 = V_176 ;
if ( F_62 ( V_7 , V_178 ,
F_16 ( V_125 [ V_92 ] / V_179 ) ) ||
F_62 ( V_7 , V_180 ,
F_16 ( V_125 [ V_94 ] / V_179 ) ) ||
F_62 ( V_7 , V_181 ,
F_16 ( V_125 [ V_149 ] / V_179 ) ) ||
F_62 ( V_7 , V_182 ,
F_16 ( V_125 [ V_144 ] / V_179 ) ) ||
F_62 ( V_7 , V_183 ,
F_16 ( V_125 [ V_184 ] / V_179 ) ) ||
F_62 ( V_7 , V_185 ,
F_16 ( V_125 [ V_186 ] / V_179 ) ) ||
F_62 ( V_7 , V_187 ,
F_16 ( V_125 [ V_130 ] / V_179 ) ) ||
F_62 ( V_7 , V_188 ,
F_16 ( V_125 [ V_139 ] / V_179 ) ) ||
F_62 ( V_7 , V_189 ,
F_16 ( V_125 [ V_190 ] / V_179 ) ) ||
F_62 ( V_7 , V_191 ,
F_16 ( V_125 [ V_146 ] / V_179 ) ) ||
F_62 ( V_7 , V_192 ,
F_16 ( V_125 [ V_147 ] / V_179 ) ) )
goto V_159;
return 0 ;
V_159:
return - V_193 ;
}
static int F_63 ( struct V_194 * V_195 ,
struct V_1 * V_77 )
{
#ifdef F_64
if ( V_195 -> V_196 )
return 0 ;
V_195 -> V_196 = F_65 ( V_197 ,
sizeof( V_197 ) ,
V_198 ) ;
if ( ! V_195 -> V_196 )
return - V_199 ;
V_195 -> V_196 [ 0 ] . V_176 = & V_77 -> V_125 [ V_92 ] ;
V_195 -> V_196 [ 1 ] . V_176 = & V_77 -> V_125 [ V_94 ] ;
V_195 -> V_196 [ 2 ] . V_176 = & V_77 -> V_125 [ V_149 ] ;
V_195 -> V_196 [ 3 ] . V_176 = & V_77 -> V_125 [ V_144 ] ;
V_195 -> V_196 [ 4 ] . V_176 = & V_77 -> V_125 [ V_184 ] ;
V_195 -> V_196 [ 5 ] . V_176 = & V_77 -> V_125 [ V_186 ] ;
V_195 -> V_196 [ 6 ] . V_176 = & V_77 -> V_125 [ V_130 ] ;
V_195 -> V_196 [ 7 ] . V_176 = & V_77 -> V_125 [ V_139 ] ;
V_195 -> V_196 [ 8 ] . V_176 = & V_77 -> V_125 [ V_146 ] ;
V_195 -> V_196 [ 9 ] . V_176 = & V_77 -> V_125 [ V_147 ] ;
V_195 -> V_196 [ 10 ] . V_176 = & V_77 -> V_152 ;
V_195 -> V_196 [ 11 ] . V_176 = & V_77 -> V_108 ;
V_195 -> V_196 [ 12 ] . V_176 = & V_77 -> V_145 ;
#endif
return 0 ;
}
static int F_66 ( struct V_194 * V_195 ,
struct V_1 * V_77 )
{
#ifdef F_64
#ifdef F_67
V_195 -> V_200 = F_65 ( V_201 ,
sizeof( V_201 ) ,
V_198 ) ;
if ( ! V_195 -> V_200 )
return - V_199 ;
V_195 -> V_200 [ 0 ] . V_176 = & V_77 -> V_125 [ V_92 ] ;
V_195 -> V_200 [ 1 ] . V_176 = & V_77 -> V_125 [ V_190 ] ;
V_195 -> V_200 [ 2 ] . V_176 = & V_77 -> V_125 [ V_94 ] ;
V_195 -> V_200 [ 3 ] . V_176 = & V_77 -> V_125 [ V_149 ] ;
V_195 -> V_200 [ 4 ] . V_176 = & V_77 -> V_125 [ V_144 ] ;
V_195 -> V_200 [ 5 ] . V_176 = & V_77 -> V_125 [ V_184 ] ;
V_195 -> V_200 [ 6 ] . V_176 = & V_77 -> V_125 [ V_186 ] ;
V_195 -> V_200 [ 7 ] . V_176 = & V_77 -> V_125 [ V_130 ] ;
V_195 -> V_200 [ 8 ] . V_176 = & V_77 -> V_125 [ V_139 ] ;
V_195 -> V_200 [ 9 ] . V_176 = & V_77 -> V_125 [ V_146 ] ;
V_195 -> V_200 [ 10 ] . V_176 = & V_77 -> V_152 ;
V_195 -> V_200 [ 11 ] . V_176 = & V_77 -> V_108 ;
V_195 -> V_200 [ 12 ] . V_176 = & V_77 -> V_145 ;
#endif
#endif
return 0 ;
}
static int F_68 ( struct V_2 * V_2 , T_5 V_27 )
{
int V_202 ;
struct V_1 * V_77 = F_1 ( V_2 ) ;
struct V_194 * V_195 = & V_77 -> V_195 ;
if ( ! V_195 -> V_203 ) {
int V_66 ;
for ( V_66 = 0 ; V_66 < V_177 ; V_66 ++ )
V_77 -> V_125 [ V_66 ] = V_204 [ V_66 ] ;
V_77 -> V_152 = V_205 ;
V_77 -> V_108 = V_206 ;
V_77 -> V_145 = V_207 ;
}
if ( V_27 == V_208 ) {
V_202 = F_66 ( V_195 , V_77 ) ;
if ( V_202 < 0 )
return V_202 ;
V_202 = F_63 ( V_195 , V_77 ) ;
if ( V_202 < 0 )
F_69 ( V_195 ) ;
} else
V_202 = F_63 ( V_195 , V_77 ) ;
return V_202 ;
}
static struct V_194 * F_70 ( struct V_2 * V_2 )
{
return & V_2 -> V_3 . V_4 . V_5 . V_195 ;
}
