static enum V_1
F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 , struct V_4 ,
V_6 ) ;
F_3 ( V_5 -> V_7 , L_1 ) ;
V_5 -> V_8 . V_9 = true ;
F_4 ( V_5 -> V_10 , & V_5 -> V_11 ) ;
return V_12 ;
}
static enum V_1
F_5 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 , struct V_4 ,
V_13 ) ;
F_6 ( V_5 -> V_7 , L_2 ) ;
V_5 -> V_8 . V_14 = true ;
F_4 ( V_5 -> V_10 , & V_5 -> V_11 ) ;
return V_12 ;
}
static void F_7 ( struct V_4 * V_5 ,
enum V_15 V_16 )
{
F_6 ( V_5 -> V_7 ,
L_3 ,
V_5 -> V_17 == V_16 ? L_4 : L_5 ,
V_5 -> V_17 ,
V_18 [ V_5 -> V_17 ] ,
V_16 ,
V_18 [ V_16 ] ) ;
V_5 -> V_17 = V_16 ;
}
static int F_8 ( struct V_4 * V_5 )
{
switch ( V_5 -> V_17 ) {
case V_19 :
case V_20 :
case V_21 :
break;
default:
return 0 ;
}
if ( V_5 -> V_22 . V_23 & V_24 ) {
return V_5 -> V_25 -> V_26 . V_27 ( V_5 -> V_25 ,
V_5 -> V_28 -> V_29 [ V_5 -> V_28 -> V_30 ] . V_31 ,
V_5 -> V_28 -> V_29 [ V_5 -> V_28 -> V_30 ] . V_32 ) ;
} else if ( ( V_5 -> V_22 . V_23 & V_33 ) &&
! ( V_5 -> V_34 -> V_35 ) ) {
return V_5 -> V_34 -> V_26 . V_27 ( V_5 -> V_34 ,
V_5 -> V_28 -> V_29 [ V_5 -> V_28 -> V_30 ] . V_31 ,
V_5 -> V_28 -> V_29 [ V_5 -> V_28 -> V_30 ] . V_32 ) ;
}
return 0 ;
}
static int F_9 ( struct V_4 * V_5 )
{
if ( V_5 -> V_22 . V_36 != V_5 -> V_22 . V_37 ||
V_5 -> V_38 . V_39 ) {
if ( ( V_5 -> V_22 . V_36 & V_33 ) &&
! V_5 -> V_38 . V_40 ) {
F_6 ( V_5 -> V_7 , L_6 ) ;
if ( V_5 -> V_22 . V_23 != V_33 ) {
V_5 -> V_22 . V_23 = V_33 ;
F_7 ( V_5 , V_41 ) ;
}
} else if ( ( V_5 -> V_22 . V_36 & V_24 ) &&
! V_5 -> V_38 . V_42 ) {
F_6 ( V_5 -> V_7 , L_7 ) ;
V_5 -> V_22 . V_23 = V_24 ;
F_7 ( V_5 , V_41 ) ;
} else if ( V_5 -> V_22 . V_36 &&
( V_5 -> V_38 . V_40 ||
V_5 -> V_38 . V_42 ) ) {
F_6 ( V_5 -> V_7 , L_8 ) ;
V_5 -> V_22 . V_23 = V_43 ;
F_7 ( V_5 , V_44 ) ;
} else {
F_6 ( V_5 -> V_7 , L_9 ) ;
V_5 -> V_22 . V_23 = V_43 ;
F_7 ( V_5 , V_45 ) ;
}
V_5 -> V_22 . V_37 = V_5 -> V_22 . V_36 ;
V_5 -> V_38 . V_39 = false ;
}
return V_5 -> V_22 . V_36 ;
}
static void F_10
( struct V_4 * V_5 )
{
if ( V_5 -> V_46 . V_47 )
F_7 ( V_5 , V_41 ) ;
V_5 -> V_46 . V_47 = false ;
}
static void F_11 ( struct V_4 * V_5 )
{
int V_48 = 0 ;
switch ( V_5 -> V_22 . V_23 ) {
case V_33 :
V_48 = V_5 -> V_28 -> V_49 ;
break;
case V_24 :
V_48 = V_5 -> V_28 -> V_50 ;
break;
default:
F_3 ( V_5 -> V_7 , L_10 ) ;
break;
}
V_5 -> V_8 . V_9 = false ;
F_12 ( & V_5 -> V_6 ,
F_13 ( V_48 * V_51 , 0 ) ,
F_13 ( V_52 , 0 ) ) ;
F_14 ( & V_5 -> V_6 , V_53 ) ;
}
static void F_15 ( struct V_4 * V_5 )
{
if ( F_16 ( & V_5 -> V_6 ) >= 0 )
V_5 -> V_8 . V_9 = false ;
}
static void F_17 ( struct V_4 * V_5 ,
int V_54 )
{
F_12 ( & V_5 -> V_13 ,
F_13 ( V_54 * V_51 , 0 ) ,
F_13 ( V_52 , 0 ) ) ;
V_5 -> V_8 . V_14 = false ;
F_14 ( & V_5 -> V_13 , V_53 ) ;
}
static void F_18 ( struct V_4 * V_5 )
{
if ( F_16 ( & V_5 -> V_13 ) >= 0 )
V_5 -> V_8 . V_14 = false ;
}
static int F_19 ( struct V_4 * V_5 )
{
if ( V_5 -> V_34 && V_5 -> V_34 -> V_26 . V_55 &&
V_5 -> V_22 . V_56 & V_33 ) {
if ( V_5 -> V_34 -> V_35 &&
V_5 -> V_25 && V_5 -> V_25 -> V_26 . V_55 )
V_5 -> V_25 -> V_26 . V_55 ( V_5 -> V_25 ) ;
return V_5 -> V_34 -> V_26 . V_55 ( V_5 -> V_34 ) ;
}
else if ( V_5 -> V_25 && V_5 -> V_25 -> V_26 . V_55 &&
V_5 -> V_22 . V_56 & V_24 )
return V_5 -> V_25 -> V_26 . V_55 ( V_5 -> V_25 ) ;
return - V_57 ;
}
static int F_20 ( struct V_4 * V_5 , int V_58 ,
int V_59 , int V_60 )
{
static int V_61 ;
if ( ! V_5 -> V_34 || ! V_5 -> V_34 -> V_26 . V_58 )
return - V_57 ;
if ( V_5 -> V_34 -> V_62 )
V_59 = F_21 ( V_59 , V_5 -> V_34 -> V_62 ) ;
if ( V_5 -> V_34 -> V_63 )
V_60 = F_21 ( V_60 , V_5 -> V_34 -> V_63 ) ;
V_5 -> V_22 . V_64 = V_60 ;
V_5 -> V_22 . V_65 = V_59 ;
if ( V_58 && V_5 -> V_34 -> V_35 &&
! V_61 ) {
F_22 ( & V_66 ,
0 , V_5 -> V_7 ) ;
V_61 ++ ;
}
return V_5 -> V_34 -> V_26 . V_58 ( V_5 -> V_34 , V_58 , V_59 , V_60 ) ;
}
static int F_23 ( struct V_4 * V_5 , int V_58 ,
int V_59 , int V_60 )
{
if ( ! V_5 -> V_25 || ! V_5 -> V_25 -> V_26 . V_58 )
return - V_57 ;
if ( V_5 -> V_25 -> V_62 )
V_59 = F_21 ( V_59 , V_5 -> V_25 -> V_62 ) ;
if ( V_5 -> V_25 -> V_63 )
V_60 = F_21 ( V_60 , V_5 -> V_25 -> V_63 ) ;
V_5 -> V_22 . V_67 = V_60 ;
V_5 -> V_22 . V_68 = V_59 ;
return V_5 -> V_25 -> V_26 . V_58 ( V_5 -> V_25 , V_58 , V_59 , V_60 ) ;
}
static int F_24 ( struct V_4 * V_5 , bool V_58 )
{
if ( ! V_5 -> V_25 || ! V_5 -> V_25 -> V_26 . V_69 )
return - V_57 ;
return V_5 -> V_25 -> V_26 . V_69 ( V_5 -> V_25 , V_58 ) ;
}
static int F_25 ( struct V_4 * V_5 ,
bool V_58 )
{
if ( ! V_5 -> V_25 || ! V_5 -> V_25 -> V_26 . V_70 )
return - V_57 ;
return V_5 -> V_25 -> V_26 . V_70 ( V_5 -> V_25 , V_58 ) ;
}
static int F_26 ( struct V_4 * V_5 ,
int V_60 )
{
if ( V_5 -> V_34 && V_5 -> V_34 -> V_26 . V_71 &&
V_5 -> V_22 . V_23 & V_33 ) {
if ( V_5 -> V_34 -> V_63 )
V_60 = F_21 ( V_60 , V_5 -> V_34 -> V_63 ) ;
V_5 -> V_22 . V_64 = V_60 ;
return V_5 -> V_34 -> V_26 . V_71 ( V_5 -> V_34 , V_60 ) ;
} else if ( V_5 -> V_25 && V_5 -> V_25 -> V_26 . V_71 &&
V_5 -> V_22 . V_23 & V_24 ) {
if ( V_5 -> V_25 -> V_63 )
V_60 = F_21 ( V_60 , V_5 -> V_25 -> V_63 ) ;
V_5 -> V_22 . V_67 = V_60 ;
return V_5 -> V_25 -> V_26 . V_71 ( V_5 -> V_25 , V_60 ) ;
}
return - V_57 ;
}
static void F_27 ( struct V_4 * V_5 )
{
F_20 ( V_5 , false , 0 , 0 ) ;
F_23 ( V_5 , false , 0 , 0 ) ;
F_15 ( V_5 ) ;
F_18 ( V_5 ) ;
V_5 -> V_72 = V_73 ;
V_5 -> V_74 = false ;
F_28 ( & V_5 -> V_75 ) ;
F_29 ( & V_5 -> V_76 ) ;
}
static void F_30 ( struct V_4 * V_5 )
{
F_20 ( V_5 , false , 0 , 0 ) ;
F_23 ( V_5 , false , 0 , 0 ) ;
F_15 ( V_5 ) ;
F_18 ( V_5 ) ;
V_5 -> V_72 = V_77 ;
V_5 -> V_74 = false ;
F_28 ( & V_5 -> V_75 ) ;
F_29 ( & V_5 -> V_76 ) ;
}
static void F_31 ( struct V_4 * V_5 ,
int V_59 , int V_60 )
{
switch ( V_5 -> V_22 . V_23 ) {
case V_33 :
F_6 ( V_5 -> V_7 ,
L_11 , V_59 , V_60 ) ;
F_23 ( V_5 , false , 0 , 0 ) ;
F_20 ( V_5 , true , V_59 , V_60 ) ;
break;
case V_24 :
F_6 ( V_5 -> V_7 ,
L_12 , V_59 , V_60 ) ;
F_20 ( V_5 , false , 0 , 0 ) ;
F_23 ( V_5 , true , V_59 , V_60 ) ;
break;
default:
F_3 ( V_5 -> V_7 , L_10 ) ;
break;
}
}
static void F_32 ( struct V_4 * V_5 )
{
if ( V_5 -> V_78 . V_79 > ( V_5 -> V_28 -> V_80 + V_5 -> V_81 ) &&
V_5 -> V_78 . V_79 < ( V_5 -> V_28 -> V_82 - V_5 -> V_81 ) ) {
V_5 -> V_8 . V_83 = false ;
V_5 -> V_8 . V_84 = false ;
V_5 -> V_81 = 0 ;
V_5 -> V_85 = 0 ;
} else {
if ( ( ( V_5 -> V_78 . V_79 >= V_5 -> V_28 -> V_82 ) &&
( V_5 -> V_78 . V_79 <
( V_5 -> V_28 -> V_86 - V_5 -> V_85 ) ) ) ||
( ( V_5 -> V_78 . V_79 >
( V_5 -> V_28 -> V_87 + V_5 -> V_85 ) ) &&
( V_5 -> V_78 . V_79 <= V_5 -> V_28 -> V_80 ) ) ) {
V_5 -> V_8 . V_83 = false ;
V_5 -> V_8 . V_84 = true ;
V_5 -> V_81 = V_5 -> V_28 -> V_88 ;
V_5 -> V_85 = 0 ;
} else if ( V_5 -> V_78 . V_79 <= V_5 -> V_28 -> V_87 ||
V_5 -> V_78 . V_79 >= V_5 -> V_28 -> V_86 ) {
V_5 -> V_8 . V_83 = true ;
V_5 -> V_8 . V_84 = false ;
V_5 -> V_81 = 0 ;
V_5 -> V_85 = V_5 -> V_28 -> V_88 ;
} else {
F_6 ( V_5 -> V_7 , L_13
L_14 ,
V_5 -> V_78 . V_79 , V_5 -> V_85 ,
V_5 -> V_81 ) ;
}
}
}
static void F_33 ( struct V_4 * V_5 )
{
if ( V_5 -> V_22 . V_89 > V_5 -> V_28 -> V_90 -> V_91 )
V_5 -> V_22 . V_92 = false ;
else
V_5 -> V_22 . V_92 = true ;
if ( V_5 -> V_22 . V_93 > V_5 -> V_28 -> V_90 -> V_94 )
V_5 -> V_22 . V_95 = false ;
else
V_5 -> V_22 . V_95 = true ;
}
static void F_34 ( struct V_4 * V_5 )
{
if ( V_5 -> V_72 == V_77 &&
V_5 -> V_17 == V_19 &&
! V_5 -> V_74 && ( V_5 -> V_78 . V_96 >=
V_5 -> V_28 -> V_29 [ V_5 -> V_28 -> V_30 ] . V_97 ||
V_5 -> V_8 . V_98 || V_5 -> V_8 . V_99 ) &&
V_5 -> V_78 . V_100 <
V_5 -> V_28 -> V_29 [ V_5 -> V_28 -> V_30 ] . V_101 &&
V_5 -> V_78 . V_100 > 0 ) {
if ( ++ V_5 -> V_102 >= V_103 ) {
V_5 -> V_102 = 0 ;
if ( ( V_5 -> V_22 . V_23 & V_24 ) &&
( V_5 -> V_25 -> V_104 ) )
F_24 ( V_5 , true ) ;
V_5 -> V_72 = V_105 ;
V_5 -> V_74 = true ;
F_6 ( V_5 -> V_7 , L_15 ) ;
F_29 ( & V_5 -> V_76 ) ;
} else {
F_6 ( V_5 -> V_7 ,
L_16
L_17 ,
V_5 -> V_102 ,
V_103 ) ;
}
} else {
V_5 -> V_102 = 0 ;
}
}
static void F_35 ( struct V_4 * V_5 )
{
V_5 -> V_106 . V_107 =
V_5 -> V_28 -> V_29 [ V_5 -> V_28 -> V_30 ] . V_32 ;
V_5 -> V_106 . V_108 =
V_5 -> V_28 -> V_29 [ V_5 -> V_28 -> V_30 ] . V_32 ;
V_5 -> V_106 . V_109 = V_5 -> V_28 -> V_110 -> V_111 ;
V_5 -> V_106 . V_112 = V_5 -> V_28 -> V_110 -> V_113 ;
V_5 -> V_106 . V_114 = V_5 -> V_28 -> V_110 -> V_115 ;
V_5 -> V_106 . V_116 = 0 ;
}
static enum V_117 F_36 ( struct V_4 * V_5 )
{
int V_118 ;
if ( ! V_5 -> V_28 -> V_110 -> V_119 )
return V_120 ;
V_118 = V_5 -> V_106 . V_107 - V_5 -> V_78 . V_121 ;
if ( V_5 -> V_8 . V_122 ) {
F_6 ( V_5 -> V_7 , L_18 ,
V_5 -> V_106 . V_123 ) ;
if ( V_5 -> V_106 . V_123 == 0 ) {
F_6 ( V_5 -> V_7 , L_19 ) ;
V_5 -> V_106 . V_123 ++ ;
V_5 -> V_106 . V_114 = V_5 -> V_28 -> V_110 -> V_115 ;
V_5 -> V_106 . V_112 =
V_5 -> V_106 . V_108 - V_5 -> V_106 . V_109 ;
V_5 -> V_106 . V_108 = V_5 -> V_106 . V_112 ;
V_5 -> V_106 . V_116 -- ;
return V_124 ;
} else {
F_6 ( V_5 -> V_7 , L_20 ) ;
V_5 -> V_106 . V_123 = ( V_5 -> V_106 . V_123 + 1 ) % 3 ;
return V_120 ;
}
}
V_5 -> V_106 . V_123 = 0 ;
if ( ( V_5 -> V_78 . V_121 > V_5 -> V_106 . V_107 ) ) {
F_6 ( V_5 -> V_7 , L_21
L_22 ,
V_5 -> V_78 . V_121 , V_5 -> V_106 . V_107 ,
V_5 -> V_106 . V_108 ) ;
if ( V_5 -> V_106 . V_108 == V_5 -> V_106 . V_107 )
return V_120 ;
V_5 -> V_106 . V_114 = V_5 -> V_28 -> V_110 -> V_115 ;
V_5 -> V_106 . V_108 = V_5 -> V_106 . V_107 ;
V_5 -> V_106 . V_116 = 0 ;
return V_125 ;
}
if ( V_118 > V_5 -> V_106 . V_109 &&
( V_5 -> V_106 . V_108 + V_5 -> V_106 . V_109 ) <
V_5 -> V_106 . V_112 ) {
if ( V_5 -> V_106 . V_114 -- == 0 ) {
V_5 -> V_106 . V_114 = V_5 -> V_28 -> V_110 -> V_115 ;
V_5 -> V_106 . V_108 += V_5 -> V_106 . V_109 ;
V_5 -> V_106 . V_116 ++ ;
F_6 ( V_5 -> V_7 , L_23
L_24
L_25 ,
V_5 -> V_106 . V_109 ,
V_5 -> V_106 . V_108 ,
V_5 -> V_106 . V_107 ,
V_5 -> V_106 . V_116 ) ;
return V_124 ;
} else {
return V_120 ;
}
} else {
V_5 -> V_106 . V_114 = V_5 -> V_28 -> V_110 -> V_115 ;
return V_120 ;
}
}
static void F_37 ( struct V_4 * V_5 )
{
enum V_117 V_126 ;
int V_127 ;
V_126 = F_36 ( V_5 ) ;
switch ( V_126 ) {
case V_124 :
V_127 = F_26 ( V_5 ,
V_5 -> V_106 . V_108 ) ;
if ( V_127 )
F_3 ( V_5 -> V_7 , L_26 ) ;
break;
case V_125 :
V_127 = F_26 ( V_5 ,
V_5 -> V_28 -> V_29 [ V_5 -> V_28 -> V_30 ] . V_32 ) ;
if ( V_127 )
F_3 ( V_5 -> V_7 , L_26 ) ;
break;
case V_120 :
default:
break;
}
}
static int F_38 ( struct V_128 * V_7 , void * V_129 )
{
struct V_130 * V_131 ;
struct V_130 * V_132 ;
struct V_4 * V_5 ;
union V_133 V_126 ;
int V_134 , V_135 ;
bool V_136 = false ;
bool V_137 = false ;
V_131 = (struct V_130 * ) V_129 ;
V_132 = F_39 ( V_7 ) ;
V_5 = F_40 ( V_131 ) ;
for ( V_134 = 0 ; V_134 < V_132 -> V_138 ; V_134 ++ ) {
if ( ! strcmp ( V_132 -> V_139 [ V_134 ] , V_131 -> V_140 ) )
V_136 = true ;
}
if ( ! V_136 )
return 0 ;
if ( ! V_132 -> V_141 ( V_132 , V_142 , & V_126 ) ) {
V_5 -> V_78 . V_143 = V_126 . V_144 ;
V_137 = true ;
}
for ( V_135 = 0 ; V_135 < V_132 -> V_145 ; V_135 ++ ) {
enum V_146 V_147 ;
V_147 = V_132 -> V_148 [ V_135 ] ;
if ( ! V_5 -> V_34 &&
V_132 -> type == V_149 )
V_5 -> V_34 = F_41 ( V_132 ) ;
else if ( ! V_5 -> V_25 &&
V_132 -> type == V_150 )
V_5 -> V_25 = F_41 ( V_132 ) ;
if ( V_132 -> V_141 ( V_132 , V_147 , & V_126 ) )
continue;
switch ( V_147 ) {
case V_151 :
switch ( V_132 -> type ) {
case V_152 :
if ( V_126 . V_144 )
V_5 -> V_8 . V_153 = false ;
else
V_5 -> V_8 . V_153 = true ;
break;
case V_149 :
if ( ! V_126 . V_144 &&
( V_5 -> V_22 . V_36 & V_33 ) ) {
V_5 -> V_22 . V_37 =
V_5 -> V_22 . V_36 ;
V_5 -> V_22 . V_36 &= ~ V_33 ;
}
else if ( V_126 . V_144 &&
! ( V_5 -> V_22 . V_36 & V_33 ) ) {
V_5 -> V_22 . V_37 =
V_5 -> V_22 . V_36 ;
V_5 -> V_22 . V_36 |= V_33 ;
}
break;
case V_150 :
if ( ! V_126 . V_144 &&
( V_5 -> V_22 . V_36 & V_24 ) ) {
V_5 -> V_22 . V_37 =
V_5 -> V_22 . V_36 ;
V_5 -> V_22 . V_36 &= ~ V_24 ;
}
else if ( V_126 . V_144 &&
! ( V_5 -> V_22 . V_36 & V_24 ) ) {
V_5 -> V_22 . V_37 =
V_5 -> V_22 . V_36 ;
V_5 -> V_22 . V_36 |= V_24 ;
}
break;
default:
break;
}
break;
case V_154 :
switch ( V_132 -> type ) {
case V_152 :
break;
case V_149 :
if ( ! V_126 . V_144 &&
( V_5 -> V_22 . V_56 & V_33 ) ) {
V_5 -> V_22 . V_155 =
V_5 -> V_22 . V_56 ;
V_5 -> V_22 . V_56 &= ~ V_33 ;
}
else if ( V_126 . V_144 &&
! ( V_5 -> V_22 . V_56 & V_33 ) ) {
V_5 -> V_22 . V_155 =
V_5 -> V_22 . V_56 ;
V_5 -> V_22 . V_56 |= V_33 ;
F_42 ( V_5 -> V_10 ,
& V_5 -> V_75 , 0 ) ;
}
break;
case V_150 :
if ( ! V_126 . V_144 &&
( V_5 -> V_22 . V_56 & V_24 ) ) {
V_5 -> V_22 . V_155 =
V_5 -> V_22 . V_56 ;
V_5 -> V_22 . V_56 &= ~ V_24 ;
}
else if ( V_126 . V_144 &&
! ( V_5 -> V_22 . V_56 & V_24 ) ) {
V_5 -> V_22 . V_155 =
V_5 -> V_22 . V_56 ;
V_5 -> V_22 . V_56 |= V_24 ;
F_42 ( V_5 -> V_10 ,
& V_5 -> V_75 , 0 ) ;
}
break;
default:
break;
}
break;
case V_156 :
switch ( V_132 -> type ) {
case V_152 :
break;
case V_149 :
switch ( V_126 . V_144 ) {
case V_157 :
V_5 -> V_8 . V_158 = true ;
V_5 -> V_8 . V_159 = false ;
V_5 -> V_8 . V_160 = false ;
V_5 -> V_8 . V_161 = false ;
break;
case V_162 :
V_5 -> V_8 . V_161 = true ;
V_5 -> V_8 . V_158 = false ;
V_5 -> V_8 . V_160 = false ;
V_5 -> V_8 . V_159 = false ;
break;
case V_163 :
case V_164 :
V_5 -> V_8 . V_159 = true ;
V_5 -> V_8 . V_158 = false ;
V_5 -> V_8 . V_160 = false ;
V_5 -> V_8 . V_161 = false ;
break;
case V_165 :
V_5 -> V_8 . V_160 = true ;
V_5 -> V_8 . V_158 = false ;
V_5 -> V_8 . V_159 = false ;
V_5 -> V_8 . V_161 = false ;
break;
case V_166 :
V_5 -> V_8 . V_159 = false ;
V_5 -> V_8 . V_158 = false ;
V_5 -> V_8 . V_160 = false ;
V_5 -> V_8 . V_161 = false ;
break;
default:
break;
}
break;
case V_150 :
switch ( V_126 . V_144 ) {
case V_157 :
V_5 -> V_8 . V_167 = true ;
V_5 -> V_8 . V_168 = false ;
V_5 -> V_8 . V_169 = false ;
V_5 -> V_8 . V_170 = false ;
break;
case V_162 :
V_5 -> V_8 . V_170 = true ;
V_5 -> V_8 . V_167 = false ;
V_5 -> V_8 . V_168 = false ;
V_5 -> V_8 . V_169 = false ;
break;
case V_163 :
case V_164 :
V_5 -> V_8 . V_168 = true ;
V_5 -> V_8 . V_167 = false ;
V_5 -> V_8 . V_169 = false ;
V_5 -> V_8 . V_170 = false ;
break;
case V_165 :
V_5 -> V_8 . V_169 = true ;
V_5 -> V_8 . V_167 = false ;
V_5 -> V_8 . V_168 = false ;
V_5 -> V_8 . V_170 = false ;
break;
case V_166 :
V_5 -> V_8 . V_167 = false ;
V_5 -> V_8 . V_168 = false ;
V_5 -> V_8 . V_169 = false ;
V_5 -> V_8 . V_170 = false ;
break;
default:
break;
}
default:
break;
}
break;
case V_171 :
switch ( V_132 -> type ) {
case V_152 :
V_5 -> V_78 . V_96 = V_126 . V_144 / 1000 ;
break;
case V_149 :
V_5 -> V_22 . V_93 = V_126 . V_144 / 1000 ;
break;
case V_150 :
V_5 -> V_22 . V_89 = V_126 . V_144 / 1000 ;
break;
default:
break;
}
break;
case V_172 :
switch ( V_132 -> type ) {
case V_149 :
if ( V_126 . V_144 )
V_5 -> V_8 . V_99 = true ;
else
V_5 -> V_8 . V_99 = false ;
break;
case V_150 :
if ( V_126 . V_144 )
V_5 -> V_8 . V_98 = true ;
else
V_5 -> V_8 . V_98 = false ;
break;
default:
break;
}
break;
case V_173 :
switch ( V_132 -> type ) {
case V_152 :
if ( V_126 . V_144 )
V_5 -> V_8 . V_174 = false ;
else
V_5 -> V_8 . V_174 = true ;
break;
default:
break;
}
break;
case V_175 :
V_5 -> V_78 . V_79 = V_126 . V_144 / 10 ;
break;
case V_176 :
switch ( V_132 -> type ) {
case V_149 :
V_5 -> V_22 . V_177 =
V_126 . V_144 / 1000 ;
break;
case V_150 :
V_5 -> V_22 . V_178 =
V_126 . V_144 / 1000 ;
break;
case V_152 :
V_5 -> V_78 . V_121 = V_126 . V_144 / 1000 ;
break;
default:
break;
}
break;
case V_179 :
switch ( V_132 -> type ) {
case V_152 :
V_5 -> V_78 . V_100 = V_126 . V_144 / 1000 ;
break;
case V_150 :
if ( V_126 . V_144 )
V_5 -> V_8 . V_122 = true ;
else
V_5 -> V_8 . V_122 = false ;
break;
default:
break;
}
break;
case V_142 :
if ( ! V_137 )
V_5 -> V_78 . V_143 = V_126 . V_144 ;
break;
default:
break;
}
}
return 0 ;
}
static void F_43 ( struct V_130 * V_131 )
{
struct V_4 * V_5 = F_40 ( V_131 ) ;
F_4 ( V_5 -> V_10 , & V_5 -> V_11 ) ;
}
static void F_44 ( struct V_4 * V_5 )
{
int V_180 ;
int V_126 ;
int V_181 ;
F_45 ( V_182 , NULL ,
& V_5 -> V_76 , F_38 ) ;
F_34 ( V_5 ) ;
F_32 ( V_5 ) ;
F_33 ( V_5 ) ;
V_180 = F_9 ( V_5 ) ;
F_10 ( V_5 ) ;
if ( F_46 ( V_5 -> V_183 ) ) {
V_126 = F_8 ( V_5 ) ;
if ( V_126 < 0 )
F_3 ( V_5 -> V_7 , L_27
L_28 , V_126 ) ;
}
if ( ! V_180 ||
( V_5 -> V_8 . V_174 && ! V_5 -> V_28 -> V_184 ) ) {
if ( V_5 -> V_17 != V_185 ) {
V_5 -> V_8 . V_9 = false ;
F_7 ( V_5 , V_45 ) ;
}
}
else if ( V_5 -> V_17 == V_44 ||
V_5 -> V_17 == V_186 ) {
}
else if ( V_5 -> V_8 . V_9 ) {
if ( V_5 -> V_17 != V_187 )
F_7 ( V_5 ,
V_188 ) ;
}
else if ( V_5 -> V_8 . V_153 ) {
if ( V_5 -> V_17 != V_189 )
F_7 ( V_5 , V_190 ) ;
}
else if ( V_5 -> V_8 . V_158 || V_5 -> V_8 . V_167 ) {
if ( V_5 -> V_17 != V_191 &&
! V_5 -> V_8 . V_122 )
F_7 ( V_5 , V_192 ) ;
}
else if ( V_5 -> V_8 . V_169 ||
V_5 -> V_8 . V_160 ||
V_5 -> V_8 . V_193 ||
! V_5 -> V_22 . V_92 ||
! V_5 -> V_22 . V_95 ) {
if ( V_5 -> V_17 != V_194 )
F_7 ( V_5 , V_195 ) ;
}
else if ( V_5 -> V_8 . V_159 ||
V_5 -> V_8 . V_168 ) {
if ( V_5 -> V_17 != V_196 )
F_7 ( V_5 ,
V_197 ) ;
}
else if ( V_5 -> V_8 . V_83 ) {
if ( V_5 -> V_17 != V_198 )
F_7 ( V_5 ,
V_199 ) ;
}
else if ( V_5 -> V_8 . V_161 ||
V_5 -> V_8 . V_170 ) {
if ( V_5 -> V_17 != V_200 )
F_7 ( V_5 , V_201 ) ;
}
else if ( V_5 -> V_8 . V_84 ) {
if ( V_5 -> V_17 != V_202 )
F_7 ( V_5 , V_203 ) ;
}
F_6 ( V_5 -> V_7 ,
L_29
L_30
L_31
L_32 ,
V_5 -> V_78 . V_96 ,
V_5 -> V_78 . V_100 ,
V_5 -> V_78 . V_121 ,
V_5 -> V_78 . V_79 ,
V_5 -> V_78 . V_143 ,
V_5 -> V_74 ,
V_18 [ V_5 -> V_17 ] ,
V_5 -> V_22 . V_23 ,
V_5 -> V_72 ,
V_5 -> V_22 . V_36 & V_33 ,
V_5 -> V_22 . V_36 & V_24 ,
V_5 -> V_22 . V_56 & V_33 ,
V_5 -> V_22 . V_56 & V_24 ,
V_5 -> V_8 . V_99 ,
V_5 -> V_8 . V_98 ,
V_5 -> V_22 . V_177 ,
V_5 -> V_22 . V_178 ,
V_5 -> V_22 . V_65 ,
V_5 -> V_22 . V_64 ,
V_5 -> V_22 . V_68 ,
V_5 -> V_22 . V_67 ) ;
switch ( V_5 -> V_17 ) {
case V_45 :
F_27 ( V_5 ) ;
V_5 -> V_72 = V_204 ;
F_7 ( V_5 , V_185 ) ;
case V_185 :
break;
case V_44 :
if ( V_5 -> V_38 . V_40 )
F_20 ( V_5 , false , 0 , 0 ) ;
if ( V_5 -> V_38 . V_42 )
F_23 ( V_5 , false , 0 , 0 ) ;
F_15 ( V_5 ) ;
F_18 ( V_5 ) ;
V_5 -> V_72 = V_73 ;
V_5 -> V_74 = false ;
F_7 ( V_5 , V_186 ) ;
F_29 ( & V_5 -> V_76 ) ;
case V_186 :
break;
case V_190 :
F_27 ( V_5 ) ;
F_7 ( V_5 , V_189 ) ;
case V_189 :
if ( ! V_5 -> V_8 . V_153 )
F_7 ( V_5 , V_41 ) ;
break;
case V_197 :
F_27 ( V_5 ) ;
F_7 ( V_5 , V_196 ) ;
case V_196 :
if ( ! V_5 -> V_8 . V_159 &&
! V_5 -> V_8 . V_168 )
F_7 ( V_5 , V_41 ) ;
break;
case V_195 :
F_27 ( V_5 ) ;
F_7 ( V_5 , V_194 ) ;
case V_194 :
if ( ! V_5 -> V_8 . V_169 &&
! V_5 -> V_8 . V_160 &&
! V_5 -> V_8 . V_193 &&
V_5 -> V_22 . V_92 &&
V_5 -> V_22 . V_95 )
F_7 ( V_5 , V_41 ) ;
break;
case V_192 :
F_27 ( V_5 ) ;
F_7 ( V_5 , V_191 ) ;
case V_191 :
if ( ! V_5 -> V_8 . V_158 &&
! V_5 -> V_8 . V_167 )
F_7 ( V_5 , V_41 ) ;
break;
case V_188 :
F_27 ( V_5 ) ;
F_7 ( V_5 , V_187 ) ;
case V_187 :
break;
case V_41 :
if ( ( V_5 -> V_22 . V_23 & V_24 ) &&
V_5 -> V_25 -> V_104 ) {
if ( V_5 -> V_78 . V_96 >
( V_5 -> V_28 -> V_205 -> V_206 +
V_207 ) ) {
F_25 ( V_5 , false ) ;
F_24 ( V_5 , false ) ;
} else {
F_24 ( V_5 , true ) ;
F_25 ( V_5 , true ) ;
F_7 ( V_5 ,
V_208 ) ;
break;
}
}
if ( V_5 -> V_46 . V_209 == V_210 )
F_27 ( V_5 ) ;
else {
V_181 = V_5 -> V_28 -> V_29 [
V_5 -> V_28 -> V_30 ] . V_32
* V_5 -> V_46 . V_209
/ V_211 ;
F_31 ( V_5 ,
V_5 -> V_28 -> V_29 [ V_5 -> V_28 -> V_30 ]
. V_31 , V_181 ) ;
}
F_7 ( V_5 , V_19 ) ;
F_11 ( V_5 ) ;
F_18 ( V_5 ) ;
F_35 ( V_5 ) ;
V_5 -> V_72 = V_77 ;
V_5 -> V_102 = 0 ;
V_5 -> V_74 = false ;
F_29 ( & V_5 -> V_76 ) ;
break;
case V_208 :
if ( V_5 -> V_78 . V_96 >
( V_5 -> V_28 -> V_205 -> V_206 +
V_207 ) )
F_7 ( V_5 , V_41 ) ;
break;
case V_19 :
F_37 ( V_5 ) ;
if ( V_5 -> V_72 == V_105 &&
V_5 -> V_74 ) {
if ( V_5 -> V_28 -> V_212 )
F_7 ( V_5 ,
V_213 ) ;
else
F_7 ( V_5 ,
V_214 ) ;
}
break;
case V_213 :
F_30 ( V_5 ) ;
F_7 ( V_5 , V_215 ) ;
case V_215 :
if ( V_5 -> V_78 . V_143 <=
V_5 -> V_28 -> V_29 [ V_5 -> V_28 -> V_30 ] .
V_216 )
F_7 ( V_5 , V_41 ) ;
break;
case V_214 :
F_15 ( V_5 ) ;
F_17 ( V_5 ,
V_5 -> V_28 -> V_29 [
V_5 -> V_28 -> V_30 ] . V_217 ) ;
F_31 ( V_5 ,
V_5 -> V_28 -> V_29 [
V_5 -> V_28 -> V_30 ] . V_218 ,
V_5 -> V_28 -> V_29 [
V_5 -> V_28 -> V_30 ] . V_219 ) ;
F_7 ( V_5 , V_20 ) ;
F_29 ( & V_5 -> V_76 ) ;
case V_20 :
if ( V_5 -> V_8 . V_14 ) {
F_18 ( V_5 ) ;
F_7 ( V_5 , V_220 ) ;
}
break;
case V_220 :
F_17 ( V_5 ,
V_5 -> V_28 -> V_29 [
V_5 -> V_28 -> V_30 ] . V_221 ) ;
F_31 ( V_5 ,
V_5 -> V_28 -> V_29 [
V_5 -> V_28 -> V_30 ] . V_222 ,
V_5 -> V_28 -> V_29 [
V_5 -> V_28 -> V_30 ] . V_223 ) ;
F_7 ( V_5 , V_21 ) ;
F_29 ( & V_5 -> V_76 ) ;
case V_21 :
if ( V_5 -> V_8 . V_14 ) {
F_18 ( V_5 ) ;
F_7 ( V_5 , V_41 ) ;
}
break;
case V_203 :
F_31 ( V_5 ,
V_5 -> V_28 -> V_29 [
V_5 -> V_28 -> V_30 ] . V_224 ,
V_5 -> V_28 -> V_29 [
V_5 -> V_28 -> V_30 ] . V_225 ) ;
F_18 ( V_5 ) ;
V_5 -> V_72 = V_77 ;
F_7 ( V_5 , V_202 ) ;
F_29 ( & V_5 -> V_76 ) ;
case V_202 :
if ( ! V_5 -> V_8 . V_84 )
F_7 ( V_5 , V_41 ) ;
break;
case V_201 :
F_27 ( V_5 ) ;
F_7 ( V_5 , V_200 ) ;
case V_200 :
if ( ! V_5 -> V_8 . V_161 &&
! V_5 -> V_8 . V_170 )
F_7 ( V_5 , V_41 ) ;
break;
case V_199 :
F_27 ( V_5 ) ;
F_7 ( V_5 , V_198 ) ;
case V_198 :
if ( ! V_5 -> V_8 . V_83 )
F_7 ( V_5 , V_41 ) ;
break;
}
if ( V_5 -> V_17 == V_41 ||
V_5 -> V_17 == V_214 ||
V_5 -> V_17 == V_220 )
F_4 ( V_5 -> V_10 , & V_5 -> V_11 ) ;
}
static void F_47 ( struct V_226 * V_227 )
{
struct V_4 * V_5 = F_2 ( V_227 ,
struct V_4 , V_228 . V_227 ) ;
F_44 ( V_5 ) ;
if ( V_5 -> V_22 . V_36 )
F_42 ( V_5 -> V_10 ,
& V_5 -> V_228 ,
V_5 -> V_28 -> V_229 * V_230 ) ;
else
F_42 ( V_5 -> V_10 ,
& V_5 -> V_228 ,
V_5 -> V_28 -> V_231 * V_230 ) ;
}
static void F_48 ( struct V_226 * V_227 )
{
int V_126 ;
struct V_4 * V_5 = F_2 ( V_227 ,
struct V_4 , V_75 . V_227 ) ;
F_6 ( V_5 -> V_7 , L_33 ) ;
V_126 = F_19 ( V_5 ) ;
if ( V_126 < 0 )
F_3 ( V_5 -> V_7 , L_34 ) ;
F_42 ( V_5 -> V_10 ,
& V_5 -> V_75 , V_232 ) ;
}
static void F_49 ( struct V_226 * V_227 )
{
struct V_4 * V_5 = F_2 ( V_227 ,
struct V_4 , V_11 ) ;
F_44 ( V_5 ) ;
}
static int F_50 ( struct V_130 * V_131 ,
enum V_146 V_233 ,
union V_133 * V_234 )
{
struct V_4 * V_5 ;
V_5 = F_40 ( V_131 ) ;
switch ( V_233 ) {
case V_235 :
V_234 -> V_144 = V_5 -> V_72 ;
break;
case V_156 :
if ( V_5 -> V_8 . V_193 ) {
V_234 -> V_144 = V_165 ;
} else if ( V_5 -> V_8 . V_83 ) {
if ( V_5 -> V_78 . V_79 <= V_5 -> V_28 -> V_87 )
V_234 -> V_144 = V_163 ;
else
V_234 -> V_144 = V_164 ;
} else if ( V_5 -> V_17 == V_187 ||
V_5 -> V_17 == V_188 ) {
V_234 -> V_144 = V_157 ;
} else {
V_234 -> V_144 = V_166 ;
}
break;
default:
return - V_236 ;
}
return 0 ;
}
static T_1 F_51 ( struct V_4 * V_5 ,
char * V_237 )
{
return sprintf ( V_237 , L_35 , V_5 -> V_46 . V_209 ) ;
}
static T_1 F_52 ( struct V_4 * V_5 ,
const char * V_237 , T_2 V_238 )
{
long int V_239 ;
int V_126 ;
V_126 = F_53 ( V_237 , 10 , & V_239 ) ;
if ( V_126 < 0 )
return V_126 ;
V_5 -> V_46 . V_209 = V_239 ;
if ( V_5 -> V_46 . V_209 >= V_210 &&
V_5 -> V_46 . V_209 <= V_211 ) {
V_5 -> V_46 . V_47 = true ;
F_4 ( V_5 -> V_10 , & V_5 -> V_11 ) ;
} else
F_54 ( V_5 -> V_7 , L_36
L_37
L_38
L_39 ) ;
return strlen ( V_237 ) ;
}
static T_1 F_55 ( struct V_4 * V_5 ,
char * V_237 )
{
return sprintf ( V_237 , L_35 ,
V_5 -> V_38 . V_40 &&
V_5 -> V_38 . V_42 ) ;
}
static T_1 F_56 ( struct V_4 * V_5 ,
const char * V_237 , T_2 V_238 )
{
long int V_239 ;
int V_240 ;
int V_126 ;
V_126 = F_53 ( V_237 , 10 , & V_239 ) ;
if ( V_126 < 0 )
return V_126 ;
V_240 = V_239 ;
switch ( V_240 ) {
case 0 :
V_5 -> V_38 . V_40 = true ;
V_5 -> V_38 . V_42 = true ;
V_5 -> V_38 . V_39 = true ;
F_4 ( V_5 -> V_10 ,
& V_5 -> V_11 ) ;
break;
case 1 :
V_5 -> V_38 . V_40 = false ;
V_5 -> V_38 . V_39 = true ;
F_4 ( V_5 -> V_10 ,
& V_5 -> V_11 ) ;
break;
case 2 :
V_5 -> V_38 . V_42 = false ;
V_5 -> V_38 . V_39 = true ;
F_4 ( V_5 -> V_10 ,
& V_5 -> V_11 ) ;
break;
default:
F_54 ( V_5 -> V_7 , L_40
L_37
L_41
L_42 ) ;
} ;
return strlen ( V_237 ) ;
}
static T_1 F_57 ( struct V_241 * V_242 ,
struct V_243 * V_244 , char * V_237 )
{
struct V_245 * V_246 = F_2 ( V_244 ,
struct V_245 , V_244 ) ;
struct V_4 * V_5 = F_2 ( V_242 ,
struct V_4 , V_247 ) ;
if ( ! V_246 -> V_248 )
return - V_249 ;
return V_246 -> V_248 ( V_5 , V_237 ) ;
}
static T_1 F_58 ( struct V_241 * V_242 ,
struct V_243 * V_244 , const char * V_237 , T_2 V_238 )
{
struct V_245 * V_246 = F_2 ( V_244 ,
struct V_245 , V_244 ) ;
struct V_4 * V_5 = F_2 ( V_242 ,
struct V_4 , V_247 ) ;
if ( ! V_246 -> V_250 )
return - V_249 ;
return V_246 -> V_250 ( V_5 , V_237 , V_238 ) ;
}
static void F_59 ( struct V_4 * V_5 )
{
F_60 ( & V_5 -> V_247 ) ;
}
static int F_61 ( struct V_4 * V_5 )
{
int V_126 = 0 ;
V_126 = F_62 ( & V_5 -> V_247 ,
& V_251 ,
NULL , L_43 ) ;
if ( V_126 < 0 )
F_3 ( V_5 -> V_7 , L_44 ) ;
return V_126 ;
}
static int F_63 ( struct V_252 * V_253 )
{
struct V_4 * V_5 = F_64 ( V_253 ) ;
if ( V_5 -> V_22 . V_56 )
F_42 ( V_5 -> V_10 , & V_5 -> V_75 , 0 ) ;
F_42 ( V_5 -> V_10 , & V_5 -> V_228 , 0 ) ;
return 0 ;
}
static int F_65 ( struct V_252 * V_253 ,
T_3 V_16 )
{
struct V_4 * V_5 = F_64 ( V_253 ) ;
if ( V_5 -> V_22 . V_56 )
F_66 ( & V_5 -> V_75 ) ;
F_66 ( & V_5 -> V_228 ) ;
return 0 ;
}
static int F_67 ( struct V_252 * V_253 )
{
struct V_4 * V_5 = F_64 ( V_253 ) ;
F_59 ( V_5 ) ;
F_68 ( & V_5 -> V_6 ) ;
F_68 ( & V_5 -> V_13 ) ;
F_66 ( & V_5 -> V_228 ) ;
F_66 ( & V_5 -> V_75 ) ;
F_69 ( & V_5 -> V_11 ) ;
F_70 ( V_5 -> V_10 ) ;
F_71 ( & V_5 -> V_76 ) ;
F_72 ( V_253 , NULL ) ;
return 0 ;
}
static int F_73 ( struct V_252 * V_253 )
{
struct V_254 * V_255 = V_253 -> V_7 . V_256 ;
struct V_257 * V_258 = V_253 -> V_7 . V_259 ;
struct V_4 * V_5 ;
int V_126 = 0 ;
V_5 = F_74 ( & V_253 -> V_7 , sizeof( * V_5 ) , V_260 ) ;
if ( ! V_5 ) {
F_3 ( & V_253 -> V_7 , L_45 , V_261 ) ;
return - V_262 ;
}
if ( ! V_258 ) {
F_3 ( & V_253 -> V_7 , L_46 ) ;
return - V_236 ;
}
V_5 -> V_28 = V_258 ;
if ( V_255 ) {
V_126 = F_75 ( & V_253 -> V_7 , V_255 , V_5 -> V_28 ) ;
if ( V_126 ) {
F_3 ( & V_253 -> V_7 , L_47 ) ;
return V_126 ;
}
}
V_5 -> V_7 = & V_253 -> V_7 ;
V_5 -> V_183 = F_39 ( V_253 -> V_7 . V_183 ) ;
V_5 -> V_76 . V_140 = L_43 ;
V_5 -> V_76 . type = V_152 ;
V_5 -> V_76 . V_148 = V_263 ;
V_5 -> V_76 . V_145 = F_76 ( V_263 ) ;
V_5 -> V_76 . V_141 = F_50 ;
V_5 -> V_76 . V_139 = V_264 ;
V_5 -> V_76 . V_138 = F_76 ( V_264 ) ,
V_5 -> V_76 . V_265 =
F_43 ;
F_77 ( & V_5 -> V_6 , V_266 , V_267 ) ;
V_5 -> V_6 . V_268 = F_1 ;
F_77 ( & V_5 -> V_13 , V_266 , V_267 ) ;
V_5 -> V_13 . V_268 =
F_5 ;
V_5 -> V_10 =
F_78 ( L_48 ) ;
if ( V_5 -> V_10 == NULL ) {
F_3 ( V_5 -> V_7 , L_49 ) ;
return - V_262 ;
}
F_79 ( & V_5 -> V_228 ,
F_47 ) ;
F_79 ( & V_5 -> V_75 ,
F_48 ) ;
F_80 ( & V_5 -> V_11 , F_49 ) ;
V_5 -> V_22 . V_37 = - 1 ;
V_126 = F_81 ( V_5 -> V_7 , & V_5 -> V_76 ) ;
if ( V_126 ) {
F_3 ( V_5 -> V_7 , L_50 ) ;
goto V_269;
}
F_72 ( V_253 , V_5 ) ;
V_126 = F_61 ( V_5 ) ;
if ( V_126 ) {
F_3 ( V_5 -> V_7 , L_44 ) ;
goto V_270;
}
V_5 -> V_46 . V_209 = V_211 ;
F_42 ( V_5 -> V_10 , & V_5 -> V_228 , 0 ) ;
F_54 ( V_5 -> V_7 , L_51 ) ;
return V_126 ;
V_270:
F_71 ( & V_5 -> V_76 ) ;
V_269:
F_70 ( V_5 -> V_10 ) ;
return V_126 ;
}
