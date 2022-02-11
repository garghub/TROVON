static bool F_1 ( const struct V_1 * V_2 , unsigned int V_3 ,
struct V_4 * V_5 )
{
const struct V_6 * V_7 ;
struct V_6 V_8 ;
V_7 = F_2 ( V_2 , V_3 , 8 , & V_8 ) ;
if ( V_7 == NULL )
return false ;
V_5 -> V_9 . V_10 . V_11 . V_12 = V_7 -> V_13 ;
V_5 -> V_14 . V_10 . V_11 . V_12 = V_7 -> V_15 ;
return true ;
}
static bool F_3 ( struct V_4 * V_5 ,
const struct V_4 * V_16 )
{
V_5 -> V_9 . V_10 . V_11 . V_12 = V_16 -> V_14 . V_10 . V_11 . V_12 ;
V_5 -> V_14 . V_10 . V_11 . V_12 = V_16 -> V_9 . V_10 . V_11 . V_12 ;
return true ;
}
static int F_4 ( struct V_17 * V_18 ,
const struct V_4 * V_5 )
{
return F_5 ( V_18 , L_1 ,
F_6 ( V_5 -> V_9 . V_10 . V_11 . V_12 ) ,
F_6 ( V_5 -> V_14 . V_10 . V_11 . V_12 ) ) ;
}
static int F_7 ( struct V_17 * V_18 , struct V_19 * V_20 )
{
enum V_21 V_22 ;
F_8 ( & V_20 -> V_23 ) ;
V_22 = V_20 -> V_24 . V_11 . V_22 ;
F_9 ( & V_20 -> V_23 ) ;
return F_5 ( V_18 , L_2 , V_25 [ V_22 ] ) ;
}
static unsigned int F_10 ( const struct V_6 * V_26 )
{
if ( V_26 -> V_27 ) return V_28 ;
else if ( V_26 -> V_29 ) return ( V_26 -> V_30 ? V_31 : V_32 ) ;
else if ( V_26 -> V_33 ) return V_34 ;
else if ( V_26 -> V_30 ) return V_35 ;
else return V_36 ;
}
static inline T_1 F_11 ( T_1 V_37 ,
T_2 V_38 ,
unsigned int V_3 ,
const struct V_6 * V_26 )
{
return ( V_37 + V_38 - V_3 - V_26 -> V_39 * 4
+ ( V_26 -> V_29 ? 1 : 0 ) + ( V_26 -> V_33 ? 1 : 0 ) ) ;
}
static void F_12 ( const struct V_1 * V_2 ,
unsigned int V_3 ,
const struct V_6 * V_26 ,
struct V_40 * V_22 )
{
unsigned char V_41 [ ( 15 * 4 ) - sizeof( struct V_6 ) ] ;
const unsigned char * V_42 ;
int V_43 = ( V_26 -> V_39 * 4 ) - sizeof( struct V_6 ) ;
if ( ! V_43 )
return;
V_42 = F_2 ( V_2 , V_3 + sizeof( struct V_6 ) ,
V_43 , V_41 ) ;
F_13 ( V_42 == NULL ) ;
V_22 -> V_44 =
V_22 -> V_45 = 0 ;
while ( V_43 > 0 ) {
int V_46 = * V_42 ++ ;
int V_47 ;
switch ( V_46 ) {
case V_48 :
return;
case V_49 :
V_43 -- ;
continue;
default:
V_47 = * V_42 ++ ;
if ( V_47 < 2 )
return;
if ( V_47 > V_43 )
break;
if ( V_46 == V_50
&& V_47 == V_51 )
V_22 -> V_45 |= V_52 ;
else if ( V_46 == V_53
&& V_47 == V_54 ) {
V_22 -> V_44 = * ( V_55 * ) V_42 ;
if ( V_22 -> V_44 > 14 ) {
V_22 -> V_44 = 14 ;
}
V_22 -> V_45 |=
V_56 ;
}
V_42 += V_47 - 2 ;
V_43 -= V_47 ;
}
}
}
static void F_14 ( const struct V_1 * V_2 , unsigned int V_3 ,
const struct V_6 * V_26 , T_1 * V_57 )
{
unsigned char V_41 [ ( 15 * 4 ) - sizeof( struct V_6 ) ] ;
const unsigned char * V_42 ;
int V_43 = ( V_26 -> V_39 * 4 ) - sizeof( struct V_6 ) ;
T_1 V_58 ;
if ( ! V_43 )
return;
V_42 = F_2 ( V_2 , V_3 + sizeof( struct V_6 ) ,
V_43 , V_41 ) ;
F_13 ( V_42 == NULL ) ;
if ( V_43 == V_59 * 4
&& * ( V_60 * ) V_42 == F_15 ( ( V_49 << 24 )
| ( V_49 << 16 )
| ( V_61 << 8 )
| V_62 ) )
return;
while ( V_43 > 0 ) {
int V_46 = * V_42 ++ ;
int V_47 , V_63 ;
switch ( V_46 ) {
case V_48 :
return;
case V_49 :
V_43 -- ;
continue;
default:
V_47 = * V_42 ++ ;
if ( V_47 < 2 )
return;
if ( V_47 > V_43 )
break;
if ( V_46 == V_64
&& V_47 >= ( V_65
+ V_66 )
&& ! ( ( V_47 - V_65 )
% V_66 ) ) {
for ( V_63 = 0 ;
V_63 < ( V_47 - V_65 ) ;
V_63 += V_66 ) {
V_58 = F_16 ( ( V_60 * ) ( V_42 + V_63 ) + 1 ) ;
if ( F_17 ( V_58 , * V_57 ) )
* V_57 = V_58 ;
}
return;
}
V_42 += V_47 - 2 ;
V_43 -= V_47 ;
}
}
}
static inline T_3 F_18 ( const struct V_19 * V_20 ,
enum V_67 V_68 ,
T_4 V_37 )
{
F_19 (nf_ct_nat_offset) V_69 = F_20 ( V_70 ) ;
return V_69 != NULL ? V_69 ( V_20 , V_68 , V_37 ) : 0 ;
}
static bool F_21 ( const struct V_19 * V_20 ,
struct V_71 * V_22 ,
enum V_67 V_68 ,
unsigned int V_72 ,
const struct V_1 * V_2 ,
unsigned int V_3 ,
const struct V_6 * V_26 ,
V_55 V_73 )
{
struct V_74 * V_74 = F_22 ( V_20 ) ;
struct V_40 * V_75 = & V_22 -> V_76 [ V_68 ] ;
struct V_40 * V_77 = & V_22 -> V_76 [ ! V_68 ] ;
const struct V_4 * V_5 = & V_20 -> V_78 [ V_68 ] . V_5 ;
T_1 V_37 , V_30 , V_57 , V_79 , V_80 , V_81 ;
T_3 V_82 ;
bool V_83 ;
V_37 = F_23 ( V_26 -> V_37 ) ;
V_30 = V_57 = F_23 ( V_26 -> V_84 ) ;
V_80 = F_6 ( V_26 -> V_85 ) ;
V_79 = F_11 ( V_37 , V_2 -> V_38 , V_3 , V_26 ) ;
if ( V_77 -> V_45 & V_52 )
F_14 ( V_2 , V_3 , V_26 , & V_57 ) ;
V_82 = F_24 ( V_73 , V_20 , ! V_68 , V_30 - 1 ) ;
V_30 -= V_82 ;
V_57 -= V_82 ;
F_25 ( L_3 ) ;
F_25 ( L_4 ) ;
F_26 ( V_5 ) ;
F_25 ( L_5 ,
V_37 , V_30 , V_82 , V_57 , V_82 , V_80 , V_79 ) ;
F_25 ( L_6
L_7 ,
V_75 -> V_86 , V_75 -> V_87 , V_75 -> V_88 ,
V_75 -> V_44 ,
V_77 -> V_86 , V_77 -> V_87 , V_77 -> V_88 ,
V_77 -> V_44 ) ;
if ( V_75 -> V_88 == 0 ) {
if ( V_26 -> V_29 ) {
V_75 -> V_86 =
V_75 -> V_87 = V_79 ;
V_75 -> V_88 = ( V_80 == 0 ? 1 : V_80 ) ;
F_12 ( V_2 , V_3 , V_26 , V_75 ) ;
if ( ! ( V_75 -> V_45 & V_56
&& V_77 -> V_45 & V_56 ) )
V_75 -> V_44 =
V_77 -> V_44 = 0 ;
if ( ! V_26 -> V_30 )
return true ;
} else {
V_75 -> V_86 = V_79 ;
V_80 <<= V_75 -> V_44 ;
V_75 -> V_88 = ( V_80 == 0 ? 1 : V_80 ) ;
V_75 -> V_87 = V_79 + V_75 -> V_88 ;
if ( V_77 -> V_88 == 0 )
V_77 -> V_86 = V_77 -> V_87 = V_57 ;
}
} else if ( ( ( V_22 -> V_22 == V_89
&& V_68 == V_90 )
|| ( V_22 -> V_22 == V_91
&& V_68 == V_92 ) )
&& F_17 ( V_79 , V_75 -> V_86 ) ) {
V_75 -> V_86 =
V_75 -> V_87 = V_79 ;
V_75 -> V_88 = ( V_80 == 0 ? 1 : V_80 ) ;
F_12 ( V_2 , V_3 , V_26 , V_75 ) ;
}
if ( ! ( V_26 -> V_30 ) ) {
V_30 = V_57 = V_77 -> V_86 ;
} else if ( ( ( F_27 ( V_26 ) & ( V_93 | V_94 ) ) ==
( V_93 | V_94 ) )
&& ( V_30 == 0 ) ) {
V_30 = V_57 = V_77 -> V_86 ;
}
if ( V_37 == V_79
&& ( ! V_26 -> V_27
|| ( V_37 == 0 && V_22 -> V_22 == V_89 ) ) )
V_37 = V_79 = V_75 -> V_86 ;
F_25 ( L_4 ) ;
F_26 ( V_5 ) ;
F_25 ( L_5 ,
V_37 , V_30 , V_82 , V_57 , V_82 , V_80 , V_79 ) ;
F_25 ( L_6
L_7 ,
V_75 -> V_86 , V_75 -> V_87 , V_75 -> V_88 ,
V_75 -> V_44 ,
V_77 -> V_86 , V_77 -> V_87 , V_77 -> V_88 ,
V_77 -> V_44 ) ;
F_25 ( L_8 ,
F_28 ( V_37 , V_75 -> V_87 + 1 ) ,
F_17 ( V_79 , V_75 -> V_86 - V_77 -> V_88 - 1 ) ,
F_28 ( V_57 , V_77 -> V_86 + 1 ) ,
F_17 ( V_57 , V_77 -> V_86 - F_29 ( V_75 ) - 1 ) ) ;
if ( F_28 ( V_37 , V_75 -> V_87 + 1 ) &&
F_17 ( V_79 , V_75 -> V_86 - V_77 -> V_88 - 1 ) &&
F_28 ( V_57 , V_77 -> V_86 + 1 ) &&
F_17 ( V_57 , V_77 -> V_86 - F_29 ( V_75 ) - 1 ) ) {
if ( ! V_26 -> V_29 )
V_80 <<= V_75 -> V_44 ;
V_81 = V_80 + ( V_57 - V_30 ) ;
if ( V_75 -> V_88 < V_81 )
V_75 -> V_88 = V_81 ;
if ( F_17 ( V_79 , V_75 -> V_86 ) ) {
V_75 -> V_86 = V_79 ;
V_75 -> V_45 |= V_95 ;
}
if ( V_26 -> V_30 ) {
if ( ! ( V_75 -> V_45 & V_96 ) ) {
V_75 -> V_97 = V_30 ;
V_75 -> V_45 |= V_96 ;
} else if ( F_17 ( V_30 , V_75 -> V_97 ) )
V_75 -> V_97 = V_30 ;
}
if ( V_77 -> V_88 != 0 && F_17 ( V_79 , V_75 -> V_87 ) )
V_77 -> V_88 += V_79 - V_75 -> V_87 ;
if ( F_17 ( V_57 + V_80 , V_77 -> V_87 - 1 ) ) {
V_77 -> V_87 = V_57 + V_80 ;
if ( V_80 == 0 )
V_77 -> V_87 ++ ;
}
if ( V_30 == V_77 -> V_86 )
V_77 -> V_45 &= ~ V_95 ;
if ( V_72 == V_35 ) {
if ( V_22 -> V_98 == V_68
&& V_22 -> V_99 == V_37
&& V_22 -> V_100 == V_30
&& V_22 -> V_101 == V_79
&& V_22 -> V_102 == V_80 )
V_22 -> V_103 ++ ;
else {
V_22 -> V_98 = V_68 ;
V_22 -> V_99 = V_37 ;
V_22 -> V_100 = V_30 ;
V_22 -> V_101 = V_79 ;
V_22 -> V_102 = V_80 ;
V_22 -> V_103 = 0 ;
}
}
V_83 = true ;
} else {
V_83 = false ;
if ( V_75 -> V_45 & V_104 ||
V_105 )
V_83 = true ;
if ( ! V_83 && F_30 ( V_74 , V_106 ) )
F_31 ( V_73 , 0 , V_2 , NULL , NULL , NULL ,
L_9 ,
F_28 ( V_37 , V_75 -> V_87 + 1 ) ?
F_17 ( V_79 , V_75 -> V_86 - V_77 -> V_88 - 1 ) ?
F_28 ( V_57 , V_77 -> V_86 + 1 ) ?
F_17 ( V_57 , V_77 -> V_86 - F_29 ( V_75 ) - 1 ) ? L_10
: L_11
: L_12
: L_13
: L_14 ) ;
}
F_25 ( L_15
L_16 ,
V_83 , V_75 -> V_86 , V_75 -> V_87 , V_75 -> V_88 ,
V_77 -> V_86 , V_77 -> V_87 , V_77 -> V_88 ) ;
return V_83 ;
}
static int F_32 ( struct V_74 * V_74 , struct V_19 * V_107 ,
struct V_1 * V_2 ,
unsigned int V_3 ,
enum V_108 * V_109 ,
V_55 V_73 ,
unsigned int V_110 )
{
const struct V_6 * V_111 ;
struct V_6 V_112 ;
unsigned int V_113 = V_2 -> V_38 - V_3 ;
V_55 V_114 ;
V_111 = F_2 ( V_2 , V_3 , sizeof( V_112 ) , & V_112 ) ;
if ( V_111 == NULL ) {
if ( F_30 ( V_74 , V_106 ) )
F_31 ( V_73 , 0 , V_2 , NULL , NULL , NULL ,
L_17 ) ;
return - V_115 ;
}
if ( V_111 -> V_39 * 4 < sizeof( struct V_6 ) || V_113 < V_111 -> V_39 * 4 ) {
if ( F_30 ( V_74 , V_106 ) )
F_31 ( V_73 , 0 , V_2 , NULL , NULL , NULL ,
L_18 ) ;
return - V_115 ;
}
if ( V_74 -> V_20 . V_116 && V_110 == V_117 &&
F_33 ( V_2 , V_110 , V_3 , V_106 , V_73 ) ) {
if ( F_30 ( V_74 , V_106 ) )
F_31 ( V_73 , 0 , V_2 , NULL , NULL , NULL ,
L_19 ) ;
return - V_115 ;
}
V_114 = ( F_34 ( V_111 ) & ~ ( V_118 | V_119 | V_120 ) ) ;
if ( ! V_121 [ V_114 ] ) {
if ( F_30 ( V_74 , V_106 ) )
F_31 ( V_73 , 0 , V_2 , NULL , NULL , NULL ,
L_20 ) ;
return - V_115 ;
}
return V_115 ;
}
static int F_35 ( struct V_19 * V_20 ,
const struct V_1 * V_2 ,
unsigned int V_3 ,
enum V_108 V_109 ,
V_55 V_73 ,
unsigned int V_110 )
{
struct V_74 * V_74 = F_22 ( V_20 ) ;
struct V_4 * V_5 ;
enum V_21 V_122 , V_123 ;
enum V_67 V_68 ;
const struct V_6 * V_111 ;
struct V_6 V_112 ;
unsigned long V_124 ;
unsigned int V_72 ;
V_111 = F_2 ( V_2 , V_3 , sizeof( V_112 ) , & V_112 ) ;
F_13 ( V_111 == NULL ) ;
F_8 ( & V_20 -> V_23 ) ;
V_123 = V_20 -> V_24 . V_11 . V_22 ;
V_68 = F_36 ( V_109 ) ;
V_72 = F_10 ( V_111 ) ;
V_122 = V_125 [ V_68 ] [ V_72 ] [ V_123 ] ;
V_5 = & V_20 -> V_78 [ V_68 ] . V_5 ;
switch ( V_122 ) {
case V_89 :
if ( V_123 < V_126 )
break;
if ( ( ( V_20 -> V_24 . V_11 . V_76 [ V_68 ] . V_45
| V_20 -> V_24 . V_11 . V_76 [ ! V_68 ] . V_45 )
& V_127 )
|| ( V_20 -> V_24 . V_11 . V_98 == V_68
&& V_20 -> V_24 . V_11 . V_128 == V_28 ) ) {
F_9 ( & V_20 -> V_23 ) ;
if ( F_37 ( V_20 ) )
return - V_129 ;
return V_130 ;
}
case V_131 :
if ( V_72 == V_31
&& V_20 -> V_24 . V_11 . V_128 == V_32
&& V_20 -> V_24 . V_11 . V_98 != V_68
&& F_23 ( V_111 -> V_84 ) == V_20 -> V_24 . V_11 . V_101 ) {
V_123 = V_89 ;
V_122 = V_91 ;
V_20 -> V_24 . V_11 . V_76 [ V_20 -> V_24 . V_11 . V_98 ] . V_86 =
V_20 -> V_24 . V_11 . V_101 ;
V_20 -> V_24 . V_11 . V_76 [ V_20 -> V_24 . V_11 . V_98 ] . V_87 =
V_20 -> V_24 . V_11 . V_101 ;
V_20 -> V_24 . V_11 . V_76 [ V_20 -> V_24 . V_11 . V_98 ] . V_88 =
V_20 -> V_24 . V_11 . V_102 == 0 ?
1 : V_20 -> V_24 . V_11 . V_102 ;
V_20 -> V_24 . V_11 . V_76 [ V_20 -> V_24 . V_11 . V_98 ] . V_44 =
V_20 -> V_24 . V_11 . V_132 ;
V_20 -> V_24 . V_11 . V_76 [ V_20 -> V_24 . V_11 . V_98 ] . V_45 =
V_20 -> V_24 . V_11 . V_133 ;
memset ( & V_20 -> V_24 . V_11 . V_76 [ V_68 ] , 0 ,
sizeof( struct V_40 ) ) ;
break;
}
V_20 -> V_24 . V_11 . V_128 = V_72 ;
V_20 -> V_24 . V_11 . V_98 = V_68 ;
V_20 -> V_24 . V_11 . V_99 = F_23 ( V_111 -> V_37 ) ;
V_20 -> V_24 . V_11 . V_101 =
F_11 ( F_23 ( V_111 -> V_37 ) , V_2 -> V_38 , V_3 , V_111 ) ;
V_20 -> V_24 . V_11 . V_102 = F_6 ( V_111 -> V_85 ) ;
if ( V_72 == V_32 && V_68 == V_90 ) {
struct V_40 V_76 = {} ;
V_20 -> V_24 . V_11 . V_133 =
V_20 -> V_24 . V_11 . V_132 = 0 ;
F_12 ( V_2 , V_3 , V_111 , & V_76 ) ;
if ( V_76 . V_45 & V_56 ) {
V_20 -> V_24 . V_11 . V_133 |=
V_56 ;
V_20 -> V_24 . V_11 . V_132 = V_76 . V_44 ;
}
if ( V_76 . V_45 & V_52 ) {
V_20 -> V_24 . V_11 . V_133 |=
V_52 ;
}
}
F_9 ( & V_20 -> V_23 ) ;
if ( F_30 ( V_74 , V_106 ) )
F_31 ( V_73 , 0 , V_2 , NULL , NULL , NULL ,
L_21 ) ;
return V_115 ;
case V_134 :
F_25 ( L_22 ,
V_68 , F_10 ( V_111 ) , V_123 ) ;
F_9 ( & V_20 -> V_23 ) ;
if ( F_30 ( V_74 , V_106 ) )
F_31 ( V_73 , 0 , V_2 , NULL , NULL , NULL ,
L_23 ) ;
return - V_115 ;
case V_135 :
if ( V_72 == V_28
&& ( V_20 -> V_24 . V_11 . V_76 [ ! V_68 ] . V_45 & V_96 )
&& F_28 ( F_23 ( V_111 -> V_37 ) , V_20 -> V_24 . V_11 . V_76 [ ! V_68 ] . V_97 ) ) {
F_9 ( & V_20 -> V_23 ) ;
if ( F_30 ( V_74 , V_106 ) )
F_31 ( V_73 , 0 , V_2 , NULL , NULL , NULL ,
L_24 ) ;
return - V_115 ;
}
if ( V_72 == V_28
&& ( ( F_38 ( V_136 , & V_20 -> V_137 )
&& V_20 -> V_24 . V_11 . V_128 == V_32 )
|| ( ! F_38 ( V_138 , & V_20 -> V_137 )
&& V_20 -> V_24 . V_11 . V_128 == V_35 ) )
&& F_23 ( V_111 -> V_84 ) == V_20 -> V_24 . V_11 . V_101 ) {
goto V_139;
}
default:
break;
}
if ( ! F_21 ( V_20 , & V_20 -> V_24 . V_11 , V_68 , V_72 ,
V_2 , V_3 , V_111 , V_73 ) ) {
F_9 ( & V_20 -> V_23 ) ;
return - V_115 ;
}
V_139:
V_20 -> V_24 . V_11 . V_128 = V_72 ;
V_20 -> V_24 . V_11 . V_98 = V_68 ;
F_25 ( L_25 ) ;
F_26 ( V_5 ) ;
F_25 ( L_26 ,
( V_111 -> V_29 ? 1 : 0 ) , ( V_111 -> V_30 ? 1 : 0 ) ,
( V_111 -> V_33 ? 1 : 0 ) , ( V_111 -> V_27 ? 1 : 0 ) ,
V_123 , V_122 ) ;
V_20 -> V_24 . V_11 . V_22 = V_122 ;
if ( V_123 != V_122
&& V_122 == V_140 )
V_20 -> V_24 . V_11 . V_76 [ V_68 ] . V_45 |= V_127 ;
if ( V_20 -> V_24 . V_11 . V_103 >= V_141 &&
V_142 [ V_122 ] > V_143 )
V_124 = V_143 ;
else if ( ( V_20 -> V_24 . V_11 . V_76 [ 0 ] . V_45 | V_20 -> V_24 . V_11 . V_76 [ 1 ] . V_45 ) &
V_95 &&
V_142 [ V_122 ] > V_144 )
V_124 = V_144 ;
else
V_124 = V_142 [ V_122 ] ;
F_9 ( & V_20 -> V_23 ) ;
if ( V_122 != V_123 )
F_39 ( V_145 , V_20 ) ;
if ( ! F_38 ( V_136 , & V_20 -> V_137 ) ) {
if ( V_111 -> V_27 ) {
F_40 ( V_20 , V_109 , V_2 ) ;
return V_115 ;
}
} else if ( ! F_38 ( V_138 , & V_20 -> V_137 )
&& ( V_123 == V_91
|| V_123 == V_146 )
&& V_122 == V_146 ) {
F_41 ( V_138 , & V_20 -> V_137 ) ;
F_39 ( V_147 , V_20 ) ;
}
F_42 ( V_20 , V_109 , V_2 , V_124 ) ;
return V_115 ;
}
static bool F_43 ( struct V_19 * V_20 , const struct V_1 * V_2 ,
unsigned int V_3 )
{
enum V_21 V_122 ;
const struct V_6 * V_111 ;
struct V_6 V_112 ;
const struct V_40 * V_75 = & V_20 -> V_24 . V_11 . V_76 [ 0 ] ;
const struct V_40 * V_77 = & V_20 -> V_24 . V_11 . V_76 [ 1 ] ;
V_111 = F_2 ( V_2 , V_3 , sizeof( V_112 ) , & V_112 ) ;
F_13 ( V_111 == NULL ) ;
V_122 = V_125 [ 0 ] [ F_10 ( V_111 ) ] [ V_148 ] ;
if ( V_122 >= V_134 ) {
F_25 ( L_27 ) ;
return false ;
}
if ( V_122 == V_89 ) {
memset ( & V_20 -> V_24 . V_11 , 0 , sizeof( V_20 -> V_24 . V_11 ) ) ;
V_20 -> V_24 . V_11 . V_76 [ 0 ] . V_86 =
F_11 ( F_23 ( V_111 -> V_37 ) , V_2 -> V_38 ,
V_3 , V_111 ) ;
V_20 -> V_24 . V_11 . V_76 [ 0 ] . V_88 = F_6 ( V_111 -> V_85 ) ;
if ( V_20 -> V_24 . V_11 . V_76 [ 0 ] . V_88 == 0 )
V_20 -> V_24 . V_11 . V_76 [ 0 ] . V_88 = 1 ;
V_20 -> V_24 . V_11 . V_76 [ 0 ] . V_87 =
V_20 -> V_24 . V_11 . V_76 [ 0 ] . V_86 ;
F_12 ( V_2 , V_3 , V_111 , & V_20 -> V_24 . V_11 . V_76 [ 0 ] ) ;
} else if ( V_149 == 0 ) {
return false ;
} else {
memset ( & V_20 -> V_24 . V_11 , 0 , sizeof( V_20 -> V_24 . V_11 ) ) ;
V_20 -> V_24 . V_11 . V_76 [ 0 ] . V_86 =
F_11 ( F_23 ( V_111 -> V_37 ) , V_2 -> V_38 ,
V_3 , V_111 ) ;
V_20 -> V_24 . V_11 . V_76 [ 0 ] . V_88 = F_6 ( V_111 -> V_85 ) ;
if ( V_20 -> V_24 . V_11 . V_76 [ 0 ] . V_88 == 0 )
V_20 -> V_24 . V_11 . V_76 [ 0 ] . V_88 = 1 ;
V_20 -> V_24 . V_11 . V_76 [ 0 ] . V_87 =
V_20 -> V_24 . V_11 . V_76 [ 0 ] . V_86 +
V_20 -> V_24 . V_11 . V_76 [ 0 ] . V_88 ;
V_20 -> V_24 . V_11 . V_76 [ 0 ] . V_45 =
V_20 -> V_24 . V_11 . V_76 [ 1 ] . V_45 = V_52 |
V_104 ;
}
V_20 -> V_24 . V_11 . V_128 = V_36 ;
F_25 ( L_28
L_7 ,
V_75 -> V_86 , V_75 -> V_87 , V_75 -> V_88 ,
V_75 -> V_44 ,
V_77 -> V_86 , V_77 -> V_87 , V_77 -> V_88 ,
V_77 -> V_44 ) ;
return true ;
}
static int F_44 ( struct V_1 * V_2 , struct V_150 * V_151 ,
struct V_19 * V_20 )
{
struct V_150 * V_152 ;
struct V_153 V_58 = {} ;
F_8 ( & V_20 -> V_23 ) ;
V_152 = F_45 ( V_2 , V_154 | V_155 ) ;
if ( ! V_152 )
goto V_156;
F_46 ( V_2 , V_157 , V_20 -> V_24 . V_11 . V_22 ) ;
F_46 ( V_2 , V_158 ,
V_20 -> V_24 . V_11 . V_76 [ 0 ] . V_44 ) ;
F_46 ( V_2 , V_159 ,
V_20 -> V_24 . V_11 . V_76 [ 1 ] . V_44 ) ;
V_58 . V_45 = V_20 -> V_24 . V_11 . V_76 [ 0 ] . V_45 ;
F_47 ( V_2 , V_160 ,
sizeof( struct V_153 ) , & V_58 ) ;
V_58 . V_45 = V_20 -> V_24 . V_11 . V_76 [ 1 ] . V_45 ;
F_47 ( V_2 , V_161 ,
sizeof( struct V_153 ) , & V_58 ) ;
F_9 ( & V_20 -> V_23 ) ;
F_48 ( V_2 , V_152 ) ;
return 0 ;
V_156:
F_9 ( & V_20 -> V_23 ) ;
return - 1 ;
}
static int F_49 ( struct V_150 * V_162 [] , struct V_19 * V_20 )
{
struct V_150 * V_163 = V_162 [ V_154 ] ;
struct V_150 * V_164 [ V_165 + 1 ] ;
int V_166 ;
if ( ! V_163 )
return 0 ;
V_166 = F_50 ( V_164 , V_165 , V_163 , V_167 ) ;
if ( V_166 < 0 )
return V_166 ;
if ( V_164 [ V_157 ] &&
F_51 ( V_164 [ V_157 ] ) >= V_134 )
return - V_168 ;
F_8 ( & V_20 -> V_23 ) ;
if ( V_164 [ V_157 ] )
V_20 -> V_24 . V_11 . V_22 = F_51 ( V_164 [ V_157 ] ) ;
if ( V_164 [ V_160 ] ) {
struct V_153 * V_169 =
F_52 ( V_164 [ V_160 ] ) ;
V_20 -> V_24 . V_11 . V_76 [ 0 ] . V_45 &= ~ V_169 -> V_170 ;
V_20 -> V_24 . V_11 . V_76 [ 0 ] . V_45 |= V_169 -> V_45 & V_169 -> V_170 ;
}
if ( V_164 [ V_161 ] ) {
struct V_153 * V_169 =
F_52 ( V_164 [ V_161 ] ) ;
V_20 -> V_24 . V_11 . V_76 [ 1 ] . V_45 &= ~ V_169 -> V_170 ;
V_20 -> V_24 . V_11 . V_76 [ 1 ] . V_45 |= V_169 -> V_45 & V_169 -> V_170 ;
}
if ( V_164 [ V_158 ] &&
V_164 [ V_159 ] &&
V_20 -> V_24 . V_11 . V_76 [ 0 ] . V_45 & V_56 &&
V_20 -> V_24 . V_11 . V_76 [ 1 ] . V_45 & V_56 ) {
V_20 -> V_24 . V_11 . V_76 [ 0 ] . V_44 =
F_51 ( V_164 [ V_158 ] ) ;
V_20 -> V_24 . V_11 . V_76 [ 1 ] . V_44 =
F_51 ( V_164 [ V_159 ] ) ;
}
F_9 ( & V_20 -> V_23 ) ;
return 0 ;
}
static int F_53 ( void )
{
return F_54 ( 0 )
+ F_55 ( V_167 , V_165 + 1 ) ;
}
static int F_56 ( void )
{
return F_55 ( V_171 , V_172 + 1 ) ;
}
