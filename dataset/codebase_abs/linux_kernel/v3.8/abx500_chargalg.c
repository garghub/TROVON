static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
F_2 ( V_3 -> V_4 , L_1 ) ;
V_3 -> V_5 . V_6 = true ;
F_3 ( V_3 -> V_7 , & V_3 -> V_8 ) ;
}
static void F_4 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
F_5 ( V_3 -> V_4 , L_2 ) ;
V_3 -> V_5 . V_9 = true ;
F_3 ( V_3 -> V_7 , & V_3 -> V_8 ) ;
}
static void F_6 ( struct V_2 * V_3 ,
enum V_10 V_11 )
{
F_5 ( V_3 -> V_4 ,
L_3 ,
V_3 -> V_12 == V_11 ? L_4 : L_5 ,
V_3 -> V_12 ,
V_13 [ V_3 -> V_12 ] ,
V_11 ,
V_13 [ V_11 ] ) ;
V_3 -> V_12 = V_11 ;
}
static int F_7 ( struct V_2 * V_3 )
{
if ( V_3 -> V_14 . V_15 != V_3 -> V_14 . V_16 ||
V_3 -> V_17 . V_18 ) {
if ( ( V_3 -> V_14 . V_15 & V_19 ) &&
! V_3 -> V_17 . V_20 ) {
F_5 ( V_3 -> V_4 , L_6 ) ;
if ( V_3 -> V_14 . V_21 != V_19 ) {
V_3 -> V_14 . V_21 = V_19 ;
F_6 ( V_3 , V_22 ) ;
}
} else if ( ( V_3 -> V_14 . V_15 & V_23 ) &&
! V_3 -> V_17 . V_24 ) {
F_5 ( V_3 -> V_4 , L_7 ) ;
V_3 -> V_14 . V_21 = V_23 ;
F_6 ( V_3 , V_22 ) ;
} else if ( V_3 -> V_14 . V_15 &&
( V_3 -> V_17 . V_20 ||
V_3 -> V_17 . V_24 ) ) {
F_5 ( V_3 -> V_4 , L_8 ) ;
V_3 -> V_14 . V_21 = V_25 ;
F_6 ( V_3 , V_26 ) ;
} else {
F_5 ( V_3 -> V_4 , L_9 ) ;
V_3 -> V_14 . V_21 = V_25 ;
F_6 ( V_3 , V_27 ) ;
}
V_3 -> V_14 . V_16 = V_3 -> V_14 . V_15 ;
V_3 -> V_17 . V_18 = false ;
}
return V_3 -> V_14 . V_15 ;
}
static void F_8 ( struct V_2 * V_3 )
{
unsigned long V_28 = 0 ;
switch ( V_3 -> V_14 . V_21 ) {
case V_19 :
V_28 =
F_9 ( V_29 +
( V_3 -> V_30 -> V_31 * 3600 * V_32 ) ) ;
break;
case V_23 :
V_28 =
F_9 ( V_29 +
( V_3 -> V_30 -> V_33 * 3600 * V_32 ) ) ;
break;
default:
F_2 ( V_3 -> V_4 , L_10 ) ;
break;
}
V_3 -> V_5 . V_6 = false ;
V_3 -> V_34 . V_35 = V_28 ;
if ( ! F_10 ( & V_3 -> V_34 ) )
F_11 ( & V_3 -> V_34 ) ;
else
F_12 ( & V_3 -> V_34 , V_28 ) ;
}
static void F_13 ( struct V_2 * V_3 )
{
V_3 -> V_5 . V_6 = false ;
F_14 ( & V_3 -> V_34 ) ;
}
static void F_15 ( struct V_2 * V_3 ,
int V_36 )
{
unsigned long V_28 ;
V_28 = F_9 ( V_29 + ( V_36 * 3600 * V_32 ) ) ;
V_3 -> V_5 . V_9 = false ;
V_3 -> V_37 . V_35 = V_28 ;
if ( ! F_10 ( & V_3 -> V_37 ) )
F_11 ( & V_3 -> V_37 ) ;
else
F_12 ( & V_3 -> V_37 , V_28 ) ;
}
static void F_16 ( struct V_2 * V_3 )
{
V_3 -> V_5 . V_9 = false ;
F_14 ( & V_3 -> V_37 ) ;
}
static int F_17 ( struct V_2 * V_3 )
{
if ( V_3 -> V_38 && V_3 -> V_38 -> V_39 . V_40 &&
V_3 -> V_14 . V_41 & V_19 )
return V_3 -> V_38 -> V_39 . V_40 ( V_3 -> V_38 ) ;
else if ( V_3 -> V_42 && V_3 -> V_42 -> V_39 . V_40 &&
V_3 -> V_14 . V_41 & V_23 )
return V_3 -> V_42 -> V_39 . V_40 ( V_3 -> V_42 ) ;
return - V_43 ;
}
static int F_18 ( struct V_2 * V_3 , int V_44 ,
int V_45 , int V_46 )
{
if ( ! V_3 -> V_38 || ! V_3 -> V_38 -> V_39 . V_44 )
return - V_43 ;
if ( V_3 -> V_38 -> V_47 )
V_45 = F_19 ( V_45 , V_3 -> V_38 -> V_47 ) ;
if ( V_3 -> V_38 -> V_48 )
V_46 = F_19 ( V_46 , V_3 -> V_38 -> V_48 ) ;
V_3 -> V_14 . V_49 = V_46 ;
V_3 -> V_14 . V_50 = V_45 ;
return V_3 -> V_38 -> V_39 . V_44 ( V_3 -> V_38 , V_44 , V_45 , V_46 ) ;
}
static int F_20 ( struct V_2 * V_3 , int V_44 ,
int V_45 , int V_46 )
{
if ( ! V_3 -> V_42 || ! V_3 -> V_42 -> V_39 . V_44 )
return - V_43 ;
if ( V_3 -> V_42 -> V_47 )
V_45 = F_19 ( V_45 , V_3 -> V_42 -> V_47 ) ;
if ( V_3 -> V_42 -> V_48 )
V_46 = F_19 ( V_46 , V_3 -> V_42 -> V_48 ) ;
V_3 -> V_14 . V_51 = V_46 ;
V_3 -> V_14 . V_52 = V_45 ;
return V_3 -> V_42 -> V_39 . V_44 ( V_3 -> V_42 , V_44 , V_45 , V_46 ) ;
}
static int F_21 ( struct V_2 * V_3 ,
int V_46 )
{
if ( V_3 -> V_38 && V_3 -> V_38 -> V_39 . V_53 &&
V_3 -> V_14 . V_21 & V_19 ) {
if ( V_3 -> V_38 -> V_48 )
V_46 = F_19 ( V_46 , V_3 -> V_38 -> V_48 ) ;
V_3 -> V_14 . V_49 = V_46 ;
return V_3 -> V_38 -> V_39 . V_53 ( V_3 -> V_38 , V_46 ) ;
} else if ( V_3 -> V_42 && V_3 -> V_42 -> V_39 . V_53 &&
V_3 -> V_14 . V_21 & V_23 ) {
if ( V_3 -> V_42 -> V_48 )
V_46 = F_19 ( V_46 , V_3 -> V_42 -> V_48 ) ;
V_3 -> V_14 . V_51 = V_46 ;
return V_3 -> V_42 -> V_39 . V_53 ( V_3 -> V_42 , V_46 ) ;
}
return - V_43 ;
}
static void F_22 ( struct V_2 * V_3 )
{
F_18 ( V_3 , false , 0 , 0 ) ;
F_20 ( V_3 , false , 0 , 0 ) ;
F_13 ( V_3 ) ;
F_16 ( V_3 ) ;
V_3 -> V_54 = V_55 ;
V_3 -> V_56 = false ;
F_23 ( & V_3 -> V_57 ) ;
F_24 ( & V_3 -> V_58 ) ;
}
static void F_25 ( struct V_2 * V_3 )
{
F_18 ( V_3 , false , 0 , 0 ) ;
F_20 ( V_3 , false , 0 , 0 ) ;
F_13 ( V_3 ) ;
F_16 ( V_3 ) ;
V_3 -> V_54 = V_59 ;
V_3 -> V_56 = false ;
F_23 ( & V_3 -> V_57 ) ;
F_24 ( & V_3 -> V_58 ) ;
}
static void F_26 ( struct V_2 * V_3 ,
int V_45 , int V_46 )
{
switch ( V_3 -> V_14 . V_21 ) {
case V_19 :
F_5 ( V_3 -> V_4 ,
L_11 , V_45 , V_46 ) ;
F_20 ( V_3 , false , 0 , 0 ) ;
F_18 ( V_3 , true , V_45 , V_46 ) ;
break;
case V_23 :
F_5 ( V_3 -> V_4 ,
L_12 , V_45 , V_46 ) ;
F_18 ( V_3 , false , 0 , 0 ) ;
F_20 ( V_3 , true , V_45 , V_46 ) ;
break;
default:
F_2 ( V_3 -> V_4 , L_10 ) ;
break;
}
}
static void F_27 ( struct V_2 * V_3 )
{
if ( V_3 -> V_60 . V_61 > ( V_3 -> V_30 -> V_62 + V_3 -> V_63 ) &&
V_3 -> V_60 . V_61 < ( V_3 -> V_30 -> V_64 - V_3 -> V_63 ) ) {
V_3 -> V_5 . V_65 = false ;
V_3 -> V_5 . V_66 = false ;
V_3 -> V_63 = 0 ;
V_3 -> V_67 = 0 ;
} else {
if ( ( ( V_3 -> V_60 . V_61 >= V_3 -> V_30 -> V_64 ) &&
( V_3 -> V_60 . V_61 <
( V_3 -> V_30 -> V_68 - V_3 -> V_67 ) ) ) ||
( ( V_3 -> V_60 . V_61 >
( V_3 -> V_30 -> V_69 + V_3 -> V_67 ) ) &&
( V_3 -> V_60 . V_61 <= V_3 -> V_30 -> V_62 ) ) ) {
V_3 -> V_5 . V_65 = false ;
V_3 -> V_5 . V_66 = true ;
V_3 -> V_63 = V_3 -> V_30 -> V_70 ;
V_3 -> V_67 = 0 ;
} else if ( V_3 -> V_60 . V_61 <= V_3 -> V_30 -> V_69 ||
V_3 -> V_60 . V_61 >= V_3 -> V_30 -> V_68 ) {
V_3 -> V_5 . V_65 = true ;
V_3 -> V_5 . V_66 = false ;
V_3 -> V_63 = 0 ;
V_3 -> V_67 = V_3 -> V_30 -> V_70 ;
} else {
F_5 ( V_3 -> V_4 , L_13
L_14 ,
V_3 -> V_60 . V_61 , V_3 -> V_67 ,
V_3 -> V_63 ) ;
}
}
}
static void F_28 ( struct V_2 * V_3 )
{
if ( V_3 -> V_14 . V_71 > V_3 -> V_30 -> V_72 -> V_73 )
V_3 -> V_14 . V_74 = false ;
else
V_3 -> V_14 . V_74 = true ;
if ( V_3 -> V_14 . V_75 > V_3 -> V_30 -> V_72 -> V_76 )
V_3 -> V_14 . V_77 = false ;
else
V_3 -> V_14 . V_77 = true ;
}
static void F_29 ( struct V_2 * V_3 )
{
if ( V_3 -> V_54 == V_59 &&
V_3 -> V_12 == V_78 &&
! V_3 -> V_56 && ( V_3 -> V_60 . V_79 >=
V_3 -> V_30 -> V_80 [ V_3 -> V_30 -> V_81 ] . V_82 ||
V_3 -> V_5 . V_83 || V_3 -> V_5 . V_84 ) &&
V_3 -> V_60 . V_85 <
V_3 -> V_30 -> V_80 [ V_3 -> V_30 -> V_81 ] . V_86 &&
V_3 -> V_60 . V_85 > 0 ) {
if ( ++ V_3 -> V_87 >= V_88 ) {
V_3 -> V_87 = 0 ;
V_3 -> V_54 = V_89 ;
V_3 -> V_56 = true ;
F_5 ( V_3 -> V_4 , L_15 ) ;
F_24 ( & V_3 -> V_58 ) ;
} else {
F_5 ( V_3 -> V_4 ,
L_16
L_17 ,
V_3 -> V_87 ,
V_88 ) ;
}
} else {
V_3 -> V_87 = 0 ;
}
}
static void F_30 ( struct V_2 * V_3 )
{
V_3 -> V_90 . V_91 =
V_3 -> V_30 -> V_80 [ V_3 -> V_30 -> V_81 ] . V_92 ;
V_3 -> V_90 . V_93 =
V_3 -> V_30 -> V_80 [ V_3 -> V_30 -> V_81 ] . V_92 ;
V_3 -> V_90 . V_94 = V_3 -> V_30 -> V_95 -> V_96 ;
V_3 -> V_90 . V_97 = V_3 -> V_30 -> V_95 -> V_98 ;
V_3 -> V_90 . V_99 = V_3 -> V_30 -> V_95 -> V_100 ;
V_3 -> V_90 . V_101 = 0 ;
}
static enum V_102 F_31 ( struct V_2 * V_3 )
{
int V_103 ;
if ( ! V_3 -> V_30 -> V_95 -> V_104 )
return V_105 ;
V_103 = V_3 -> V_90 . V_91 - V_3 -> V_60 . V_106 ;
if ( V_3 -> V_5 . V_107 ) {
F_5 ( V_3 -> V_4 , L_18 ,
V_3 -> V_90 . V_108 ) ;
if ( V_3 -> V_90 . V_108 == 0 ) {
F_5 ( V_3 -> V_4 , L_19 ) ;
V_3 -> V_90 . V_108 ++ ;
V_3 -> V_90 . V_99 = V_3 -> V_30 -> V_95 -> V_100 ;
V_3 -> V_90 . V_97 =
V_3 -> V_90 . V_93 - V_3 -> V_90 . V_94 ;
V_3 -> V_90 . V_93 = V_3 -> V_90 . V_97 ;
V_3 -> V_90 . V_101 -- ;
return V_109 ;
} else {
F_5 ( V_3 -> V_4 , L_20 ) ;
V_3 -> V_90 . V_108 = ( V_3 -> V_90 . V_108 + 1 ) % 3 ;
return V_105 ;
}
}
V_3 -> V_90 . V_108 = 0 ;
if ( ( V_3 -> V_60 . V_106 > V_3 -> V_90 . V_91 ) ) {
F_5 ( V_3 -> V_4 , L_21
L_22 ,
V_3 -> V_60 . V_106 , V_3 -> V_90 . V_91 ,
V_3 -> V_90 . V_93 ) ;
if ( V_3 -> V_90 . V_93 == V_3 -> V_90 . V_91 )
return V_105 ;
V_3 -> V_90 . V_99 = V_3 -> V_30 -> V_95 -> V_100 ;
V_3 -> V_90 . V_93 = V_3 -> V_90 . V_91 ;
V_3 -> V_90 . V_101 = 0 ;
return V_110 ;
}
if ( V_103 > V_3 -> V_90 . V_94 &&
( V_3 -> V_90 . V_93 + V_3 -> V_90 . V_94 ) <
V_3 -> V_90 . V_97 ) {
if ( V_3 -> V_90 . V_99 -- == 0 ) {
V_3 -> V_90 . V_99 = V_3 -> V_30 -> V_95 -> V_100 ;
V_3 -> V_90 . V_93 += V_3 -> V_90 . V_94 ;
V_3 -> V_90 . V_101 ++ ;
F_5 ( V_3 -> V_4 , L_23
L_24
L_25 ,
V_3 -> V_90 . V_94 ,
V_3 -> V_90 . V_93 ,
V_3 -> V_90 . V_91 ,
V_3 -> V_90 . V_101 ) ;
return V_109 ;
} else {
return V_105 ;
}
} else {
V_3 -> V_90 . V_99 = V_3 -> V_30 -> V_95 -> V_100 ;
return V_105 ;
}
}
static void F_32 ( struct V_2 * V_3 )
{
enum V_102 V_111 ;
int V_112 ;
V_111 = F_31 ( V_3 ) ;
switch ( V_111 ) {
case V_109 :
V_112 = F_21 ( V_3 ,
V_3 -> V_90 . V_93 ) ;
if ( V_112 )
F_2 ( V_3 -> V_4 , L_26 ) ;
break;
case V_110 :
V_112 = F_21 ( V_3 ,
V_3 -> V_30 -> V_80 [ V_3 -> V_30 -> V_81 ] . V_92 ) ;
if ( V_112 )
F_2 ( V_3 -> V_4 , L_26 ) ;
break;
case V_105 :
default:
break;
}
}
static int F_33 ( struct V_113 * V_4 , void * V_1 )
{
struct V_114 * V_115 ;
struct V_114 * V_116 ;
struct V_2 * V_3 ;
union V_117 V_111 ;
int V_118 , V_119 ;
bool V_120 = false ;
V_115 = (struct V_114 * ) V_1 ;
V_116 = F_34 ( V_4 ) ;
V_3 = F_35 ( V_115 ) ;
for ( V_118 = 0 ; V_118 < V_116 -> V_121 ; V_118 ++ ) {
if ( ! strcmp ( V_116 -> V_122 [ V_118 ] , V_115 -> V_123 ) )
V_120 = true ;
}
if ( ! V_120 )
return 0 ;
for ( V_119 = 0 ; V_119 < V_116 -> V_124 ; V_119 ++ ) {
enum V_125 V_126 ;
V_126 = V_116 -> V_127 [ V_119 ] ;
if ( ! V_3 -> V_38 &&
V_116 -> type == V_128 )
V_3 -> V_38 = F_36 ( V_116 ) ;
else if ( ! V_3 -> V_42 &&
V_116 -> type == V_129 )
V_3 -> V_42 = F_36 ( V_116 ) ;
if ( V_116 -> V_130 ( V_116 , V_126 , & V_111 ) )
continue;
switch ( V_126 ) {
case V_131 :
switch ( V_116 -> type ) {
case V_132 :
if ( V_111 . V_133 )
V_3 -> V_5 . V_134 = false ;
else
V_3 -> V_5 . V_134 = true ;
break;
case V_128 :
if ( ! V_111 . V_133 &&
( V_3 -> V_14 . V_15 & V_19 ) ) {
V_3 -> V_14 . V_16 =
V_3 -> V_14 . V_15 ;
V_3 -> V_14 . V_15 &= ~ V_19 ;
}
else if ( V_111 . V_133 &&
! ( V_3 -> V_14 . V_15 & V_19 ) ) {
V_3 -> V_14 . V_16 =
V_3 -> V_14 . V_15 ;
V_3 -> V_14 . V_15 |= V_19 ;
}
break;
case V_129 :
if ( ! V_111 . V_133 &&
( V_3 -> V_14 . V_15 & V_23 ) ) {
V_3 -> V_14 . V_16 =
V_3 -> V_14 . V_15 ;
V_3 -> V_14 . V_15 &= ~ V_23 ;
}
else if ( V_111 . V_133 &&
! ( V_3 -> V_14 . V_15 & V_23 ) ) {
V_3 -> V_14 . V_16 =
V_3 -> V_14 . V_15 ;
V_3 -> V_14 . V_15 |= V_23 ;
}
break;
default:
break;
}
break;
case V_135 :
switch ( V_116 -> type ) {
case V_132 :
break;
case V_128 :
if ( ! V_111 . V_133 &&
( V_3 -> V_14 . V_41 & V_19 ) ) {
V_3 -> V_14 . V_136 =
V_3 -> V_14 . V_41 ;
V_3 -> V_14 . V_41 &= ~ V_19 ;
}
else if ( V_111 . V_133 &&
! ( V_3 -> V_14 . V_41 & V_19 ) ) {
V_3 -> V_14 . V_136 =
V_3 -> V_14 . V_41 ;
V_3 -> V_14 . V_41 |= V_19 ;
F_37 ( V_3 -> V_7 ,
& V_3 -> V_57 , 0 ) ;
}
break;
case V_129 :
if ( ! V_111 . V_133 &&
( V_3 -> V_14 . V_41 & V_23 ) ) {
V_3 -> V_14 . V_136 =
V_3 -> V_14 . V_41 ;
V_3 -> V_14 . V_41 &= ~ V_23 ;
}
else if ( V_111 . V_133 &&
! ( V_3 -> V_14 . V_41 & V_23 ) ) {
V_3 -> V_14 . V_136 =
V_3 -> V_14 . V_41 ;
V_3 -> V_14 . V_41 |= V_23 ;
F_37 ( V_3 -> V_7 ,
& V_3 -> V_57 , 0 ) ;
}
break;
default:
break;
}
break;
case V_137 :
switch ( V_116 -> type ) {
case V_132 :
break;
case V_128 :
switch ( V_111 . V_133 ) {
case V_138 :
V_3 -> V_5 . V_139 = true ;
V_3 -> V_5 . V_140 = false ;
V_3 -> V_5 . V_141 = false ;
V_3 -> V_5 . V_142 = false ;
break;
case V_143 :
V_3 -> V_5 . V_142 = true ;
V_3 -> V_5 . V_139 = false ;
V_3 -> V_5 . V_141 = false ;
V_3 -> V_5 . V_140 = false ;
break;
case V_144 :
case V_145 :
V_3 -> V_5 . V_140 = true ;
V_3 -> V_5 . V_139 = false ;
V_3 -> V_5 . V_141 = false ;
V_3 -> V_5 . V_142 = false ;
break;
case V_146 :
V_3 -> V_5 . V_141 = true ;
V_3 -> V_5 . V_139 = false ;
V_3 -> V_5 . V_140 = false ;
V_3 -> V_5 . V_142 = false ;
break;
case V_147 :
V_3 -> V_5 . V_140 = false ;
V_3 -> V_5 . V_139 = false ;
V_3 -> V_5 . V_141 = false ;
V_3 -> V_5 . V_142 = false ;
break;
default:
break;
}
break;
case V_129 :
switch ( V_111 . V_133 ) {
case V_138 :
V_3 -> V_5 . V_148 = true ;
V_3 -> V_5 . V_149 = false ;
V_3 -> V_5 . V_150 = false ;
V_3 -> V_5 . V_151 = false ;
break;
case V_143 :
V_3 -> V_5 . V_151 = true ;
V_3 -> V_5 . V_148 = false ;
V_3 -> V_5 . V_149 = false ;
V_3 -> V_5 . V_150 = false ;
break;
case V_144 :
case V_145 :
V_3 -> V_5 . V_149 = true ;
V_3 -> V_5 . V_148 = false ;
V_3 -> V_5 . V_150 = false ;
V_3 -> V_5 . V_151 = false ;
break;
case V_146 :
V_3 -> V_5 . V_150 = true ;
V_3 -> V_5 . V_148 = false ;
V_3 -> V_5 . V_149 = false ;
V_3 -> V_5 . V_151 = false ;
break;
case V_147 :
V_3 -> V_5 . V_148 = false ;
V_3 -> V_5 . V_149 = false ;
V_3 -> V_5 . V_150 = false ;
V_3 -> V_5 . V_151 = false ;
break;
default:
break;
}
default:
break;
}
break;
case V_152 :
switch ( V_116 -> type ) {
case V_132 :
V_3 -> V_60 . V_79 = V_111 . V_133 / 1000 ;
break;
case V_128 :
V_3 -> V_14 . V_75 = V_111 . V_133 / 1000 ;
break;
case V_129 :
V_3 -> V_14 . V_71 = V_111 . V_133 / 1000 ;
break;
default:
break;
}
break;
case V_153 :
switch ( V_116 -> type ) {
case V_128 :
if ( V_111 . V_133 )
V_3 -> V_5 . V_84 = true ;
else
V_3 -> V_5 . V_84 = false ;
break;
case V_129 :
if ( V_111 . V_133 )
V_3 -> V_5 . V_83 = true ;
else
V_3 -> V_5 . V_83 = false ;
break;
default:
break;
}
break;
case V_154 :
switch ( V_116 -> type ) {
case V_132 :
if ( V_111 . V_133 )
V_3 -> V_5 . V_155 = false ;
else
V_3 -> V_5 . V_155 = true ;
break;
default:
break;
}
break;
case V_156 :
V_3 -> V_60 . V_61 = V_111 . V_133 / 10 ;
break;
case V_157 :
switch ( V_116 -> type ) {
case V_128 :
V_3 -> V_14 . V_158 =
V_111 . V_133 / 1000 ;
break;
case V_129 :
V_3 -> V_14 . V_159 =
V_111 . V_133 / 1000 ;
break;
case V_132 :
V_3 -> V_60 . V_106 = V_111 . V_133 / 1000 ;
break;
default:
break;
}
break;
case V_160 :
switch ( V_116 -> type ) {
case V_132 :
V_3 -> V_60 . V_85 = V_111 . V_133 / 1000 ;
break;
case V_129 :
if ( V_111 . V_133 )
V_3 -> V_5 . V_107 = true ;
else
V_3 -> V_5 . V_107 = false ;
break;
default:
break;
}
break;
case V_161 :
V_3 -> V_60 . V_162 = V_111 . V_133 ;
break;
default:
break;
}
}
return 0 ;
}
static void F_38 ( struct V_114 * V_115 )
{
struct V_2 * V_3 = F_35 ( V_115 ) ;
F_3 ( V_3 -> V_7 , & V_3 -> V_8 ) ;
}
static void F_39 ( struct V_2 * V_3 )
{
int V_163 ;
F_40 ( V_164 , NULL ,
& V_3 -> V_58 , F_33 ) ;
F_29 ( V_3 ) ;
F_27 ( V_3 ) ;
F_28 ( V_3 ) ;
V_163 = F_7 ( V_3 ) ;
if ( ! V_163 ||
( V_3 -> V_5 . V_155 && ! V_3 -> V_30 -> V_165 ) ) {
if ( V_3 -> V_12 != V_166 ) {
V_3 -> V_5 . V_6 = false ;
F_6 ( V_3 , V_27 ) ;
}
}
else if ( V_3 -> V_12 == V_26 ||
V_3 -> V_12 == V_167 ) {
}
else if ( V_3 -> V_5 . V_6 ) {
if ( V_3 -> V_12 != V_168 )
F_6 ( V_3 ,
V_169 ) ;
}
else if ( V_3 -> V_5 . V_134 ) {
if ( V_3 -> V_12 != V_170 )
F_6 ( V_3 , V_171 ) ;
}
else if ( V_3 -> V_5 . V_139 || V_3 -> V_5 . V_148 ) {
if ( V_3 -> V_12 != V_172 &&
! V_3 -> V_5 . V_107 )
F_6 ( V_3 , V_173 ) ;
}
else if ( V_3 -> V_5 . V_150 ||
V_3 -> V_5 . V_141 ||
V_3 -> V_5 . V_174 ||
! V_3 -> V_14 . V_74 ||
! V_3 -> V_14 . V_77 ) {
if ( V_3 -> V_12 != V_175 )
F_6 ( V_3 , V_176 ) ;
}
else if ( V_3 -> V_5 . V_140 ||
V_3 -> V_5 . V_149 ) {
if ( V_3 -> V_12 != V_177 )
F_6 ( V_3 ,
V_178 ) ;
}
else if ( V_3 -> V_5 . V_65 ) {
if ( V_3 -> V_12 != V_179 )
F_6 ( V_3 ,
V_180 ) ;
}
else if ( V_3 -> V_5 . V_142 ||
V_3 -> V_5 . V_151 ) {
if ( V_3 -> V_12 != V_181 )
F_6 ( V_3 , V_182 ) ;
}
else if ( V_3 -> V_5 . V_66 ) {
if ( V_3 -> V_12 != V_183 )
F_6 ( V_3 , V_184 ) ;
}
F_5 ( V_3 -> V_4 ,
L_27
L_28
L_29
L_30 ,
V_3 -> V_60 . V_79 ,
V_3 -> V_60 . V_85 ,
V_3 -> V_60 . V_106 ,
V_3 -> V_60 . V_61 ,
V_3 -> V_60 . V_162 ,
V_3 -> V_56 ,
V_13 [ V_3 -> V_12 ] ,
V_3 -> V_14 . V_21 ,
V_3 -> V_54 ,
V_3 -> V_14 . V_15 & V_19 ,
V_3 -> V_14 . V_15 & V_23 ,
V_3 -> V_14 . V_41 & V_19 ,
V_3 -> V_14 . V_41 & V_23 ,
V_3 -> V_5 . V_84 ,
V_3 -> V_5 . V_83 ,
V_3 -> V_14 . V_158 ,
V_3 -> V_14 . V_159 ,
V_3 -> V_14 . V_50 ,
V_3 -> V_14 . V_49 ,
V_3 -> V_14 . V_52 ,
V_3 -> V_14 . V_51 ) ;
switch ( V_3 -> V_12 ) {
case V_27 :
F_22 ( V_3 ) ;
V_3 -> V_54 = V_185 ;
F_6 ( V_3 , V_166 ) ;
case V_166 :
break;
case V_26 :
if ( V_3 -> V_17 . V_20 )
F_18 ( V_3 , false , 0 , 0 ) ;
if ( V_3 -> V_17 . V_24 )
F_20 ( V_3 , false , 0 , 0 ) ;
F_13 ( V_3 ) ;
F_16 ( V_3 ) ;
V_3 -> V_54 = V_55 ;
V_3 -> V_56 = false ;
F_6 ( V_3 , V_167 ) ;
F_24 ( & V_3 -> V_58 ) ;
case V_167 :
break;
case V_171 :
F_22 ( V_3 ) ;
F_6 ( V_3 , V_170 ) ;
case V_170 :
if ( ! V_3 -> V_5 . V_134 )
F_6 ( V_3 , V_22 ) ;
break;
case V_178 :
F_22 ( V_3 ) ;
F_6 ( V_3 , V_177 ) ;
case V_177 :
if ( ! V_3 -> V_5 . V_140 &&
! V_3 -> V_5 . V_149 )
F_6 ( V_3 , V_22 ) ;
break;
case V_176 :
F_22 ( V_3 ) ;
F_6 ( V_3 , V_175 ) ;
case V_175 :
if ( ! V_3 -> V_5 . V_150 &&
! V_3 -> V_5 . V_141 &&
! V_3 -> V_5 . V_174 &&
V_3 -> V_14 . V_74 &&
V_3 -> V_14 . V_77 )
F_6 ( V_3 , V_22 ) ;
break;
case V_173 :
F_22 ( V_3 ) ;
F_6 ( V_3 , V_172 ) ;
case V_172 :
if ( ! V_3 -> V_5 . V_139 &&
! V_3 -> V_5 . V_148 )
F_6 ( V_3 , V_22 ) ;
break;
case V_169 :
F_22 ( V_3 ) ;
F_6 ( V_3 , V_168 ) ;
case V_168 :
break;
case V_22 :
F_26 ( V_3 ,
V_3 -> V_30 -> V_80 [ V_3 -> V_30 -> V_81 ] . V_186 ,
V_3 -> V_30 -> V_80 [ V_3 -> V_30 -> V_81 ] . V_92 ) ;
F_6 ( V_3 , V_78 ) ;
F_8 ( V_3 ) ;
F_16 ( V_3 ) ;
F_30 ( V_3 ) ;
V_3 -> V_54 = V_59 ;
V_3 -> V_87 = 0 ;
V_3 -> V_56 = false ;
F_24 ( & V_3 -> V_58 ) ;
break;
case V_78 :
F_32 ( V_3 ) ;
if ( V_3 -> V_54 == V_89 &&
V_3 -> V_56 ) {
if ( V_3 -> V_30 -> V_187 )
F_6 ( V_3 ,
V_188 ) ;
else
F_6 ( V_3 ,
V_189 ) ;
}
break;
case V_188 :
F_25 ( V_3 ) ;
F_6 ( V_3 , V_190 ) ;
V_3 -> V_191 = V_192 ;
case V_190 :
if ( V_3 -> V_60 . V_79 <=
V_3 -> V_30 -> V_80 [ V_3 -> V_30 -> V_81 ] . V_193 ) {
if ( V_3 -> V_191 -- == 0 )
F_6 ( V_3 , V_22 ) ;
} else
V_3 -> V_191 = V_192 ;
break;
case V_189 :
F_13 ( V_3 ) ;
F_15 ( V_3 ,
V_3 -> V_30 -> V_80 [
V_3 -> V_30 -> V_81 ] . V_194 ) ;
F_26 ( V_3 ,
V_3 -> V_30 -> V_80 [
V_3 -> V_30 -> V_81 ] . V_195 ,
V_3 -> V_30 -> V_80 [
V_3 -> V_30 -> V_81 ] . V_196 ) ;
F_6 ( V_3 , V_197 ) ;
F_24 ( & V_3 -> V_58 ) ;
case V_197 :
if ( V_3 -> V_5 . V_9 ) {
F_16 ( V_3 ) ;
F_6 ( V_3 , V_198 ) ;
}
break;
case V_198 :
F_15 ( V_3 ,
V_3 -> V_30 -> V_80 [
V_3 -> V_30 -> V_81 ] . V_199 ) ;
F_26 ( V_3 ,
V_3 -> V_30 -> V_80 [
V_3 -> V_30 -> V_81 ] . V_200 ,
V_3 -> V_30 -> V_80 [
V_3 -> V_30 -> V_81 ] . V_201 ) ;
F_6 ( V_3 , V_202 ) ;
F_24 ( & V_3 -> V_58 ) ;
case V_202 :
if ( V_3 -> V_5 . V_9 ) {
F_16 ( V_3 ) ;
F_6 ( V_3 , V_22 ) ;
}
break;
case V_184 :
F_26 ( V_3 ,
V_3 -> V_30 -> V_80 [
V_3 -> V_30 -> V_81 ] . V_203 ,
V_3 -> V_30 -> V_80 [
V_3 -> V_30 -> V_81 ] . V_204 ) ;
F_16 ( V_3 ) ;
V_3 -> V_54 = V_59 ;
F_6 ( V_3 , V_183 ) ;
F_24 ( & V_3 -> V_58 ) ;
case V_183 :
if ( ! V_3 -> V_5 . V_66 )
F_6 ( V_3 , V_22 ) ;
break;
case V_182 :
F_22 ( V_3 ) ;
F_6 ( V_3 , V_181 ) ;
case V_181 :
if ( ! V_3 -> V_5 . V_142 &&
! V_3 -> V_5 . V_151 )
F_6 ( V_3 , V_22 ) ;
break;
case V_180 :
F_22 ( V_3 ) ;
F_6 ( V_3 , V_179 ) ;
case V_179 :
if ( ! V_3 -> V_5 . V_65 )
F_6 ( V_3 , V_22 ) ;
break;
}
if ( V_3 -> V_12 == V_22 ||
V_3 -> V_12 == V_189 ||
V_3 -> V_12 == V_198 )
F_3 ( V_3 -> V_7 , & V_3 -> V_8 ) ;
}
static void F_41 ( struct V_205 * V_206 )
{
struct V_2 * V_3 = F_42 ( V_206 ,
struct V_2 , V_207 . V_206 ) ;
F_39 ( V_3 ) ;
if ( V_3 -> V_14 . V_15 )
F_37 ( V_3 -> V_7 ,
& V_3 -> V_207 ,
V_3 -> V_30 -> V_208 * V_32 ) ;
else
F_37 ( V_3 -> V_7 ,
& V_3 -> V_207 ,
V_3 -> V_30 -> V_209 * V_32 ) ;
}
static void F_43 ( struct V_205 * V_206 )
{
int V_111 ;
struct V_2 * V_3 = F_42 ( V_206 ,
struct V_2 , V_57 . V_206 ) ;
F_5 ( V_3 -> V_4 , L_31 ) ;
V_111 = F_17 ( V_3 ) ;
if ( V_111 < 0 )
F_2 ( V_3 -> V_4 , L_32 ) ;
F_37 ( V_3 -> V_7 ,
& V_3 -> V_57 , V_210 ) ;
}
static void F_44 ( struct V_205 * V_206 )
{
struct V_2 * V_3 = F_42 ( V_206 ,
struct V_2 , V_8 ) ;
F_39 ( V_3 ) ;
}
static int F_45 ( struct V_114 * V_115 ,
enum V_125 V_211 ,
union V_117 * V_212 )
{
struct V_2 * V_3 ;
V_3 = F_35 ( V_115 ) ;
switch ( V_211 ) {
case V_213 :
V_212 -> V_133 = V_3 -> V_54 ;
break;
case V_137 :
if ( V_3 -> V_5 . V_174 ) {
V_212 -> V_133 = V_146 ;
} else if ( V_3 -> V_5 . V_65 ) {
if ( V_3 -> V_60 . V_61 <= V_3 -> V_30 -> V_69 )
V_212 -> V_133 = V_144 ;
else
V_212 -> V_133 = V_145 ;
} else {
V_212 -> V_133 = V_147 ;
}
break;
default:
return - V_214 ;
}
return 0 ;
}
static T_1 F_46 ( struct V_215 * V_216 ,
struct V_217 * V_218 , const char * V_219 , T_2 V_220 )
{
struct V_2 * V_3 = F_42 ( V_216 ,
struct V_2 , V_221 ) ;
long int V_222 ;
int V_223 ;
int V_111 ;
char V_224 = * V_218 -> V_123 ;
switch ( V_224 ) {
case 'c' :
V_111 = F_47 ( V_219 , 10 , & V_222 ) ;
if ( V_111 < 0 )
return V_111 ;
V_223 = V_222 ;
switch ( V_223 ) {
case 0 :
V_3 -> V_17 . V_20 = true ;
V_3 -> V_17 . V_24 = true ;
V_3 -> V_17 . V_18 = true ;
F_3 ( V_3 -> V_7 ,
& V_3 -> V_8 ) ;
break;
case 1 :
V_3 -> V_17 . V_20 = false ;
V_3 -> V_17 . V_18 = true ;
F_3 ( V_3 -> V_7 ,
& V_3 -> V_8 ) ;
break;
case 2 :
V_3 -> V_17 . V_24 = false ;
V_3 -> V_17 . V_18 = true ;
F_3 ( V_3 -> V_7 ,
& V_3 -> V_8 ) ;
break;
default:
F_48 ( V_3 -> V_4 , L_33
L_34
L_35
L_36 ) ;
} ;
break;
} ;
return strlen ( V_219 ) ;
}
static void F_49 ( struct V_2 * V_3 )
{
F_50 ( & V_3 -> V_221 ) ;
}
static int F_51 ( struct V_2 * V_3 )
{
int V_111 = 0 ;
V_111 = F_52 ( & V_3 -> V_221 ,
& V_225 ,
NULL , L_37 ) ;
if ( V_111 < 0 )
F_2 ( V_3 -> V_4 , L_38 ) ;
return V_111 ;
}
static int F_53 ( struct V_226 * V_227 )
{
struct V_2 * V_3 = F_54 ( V_227 ) ;
if ( V_3 -> V_14 . V_41 )
F_37 ( V_3 -> V_7 , & V_3 -> V_57 , 0 ) ;
F_37 ( V_3 -> V_7 , & V_3 -> V_207 , 0 ) ;
return 0 ;
}
static int F_55 ( struct V_226 * V_227 ,
T_3 V_11 )
{
struct V_2 * V_3 = F_54 ( V_227 ) ;
if ( V_3 -> V_14 . V_41 )
F_56 ( & V_3 -> V_57 ) ;
F_56 ( & V_3 -> V_207 ) ;
return 0 ;
}
static int F_57 ( struct V_226 * V_227 )
{
struct V_2 * V_3 = F_54 ( V_227 ) ;
F_49 ( V_3 ) ;
F_58 ( V_3 -> V_7 ) ;
F_59 () ;
F_60 ( & V_3 -> V_58 ) ;
F_61 ( V_227 , NULL ) ;
return 0 ;
}
static int F_62 ( struct V_226 * V_227 )
{
struct V_228 * V_229 = V_227 -> V_4 . V_230 ;
struct V_2 * V_3 ;
int V_111 = 0 ;
V_3 = F_63 ( & V_227 -> V_4 , sizeof( * V_3 ) , V_231 ) ;
if ( ! V_3 ) {
F_2 ( & V_227 -> V_4 , L_39 , V_232 ) ;
return - V_233 ;
}
V_3 -> V_30 = V_227 -> V_234 -> V_235 ;
if ( ! V_3 -> V_30 ) {
if ( V_229 ) {
V_111 = F_64 ( & V_227 -> V_4 , V_229 , & V_3 -> V_30 ) ;
if ( V_111 ) {
F_2 ( & V_227 -> V_4 ,
L_40 ) ;
return V_111 ;
}
} else {
F_2 ( & V_227 -> V_4 , L_41 ) ;
return - V_214 ;
}
} else {
F_48 ( & V_227 -> V_4 , L_42 ) ;
}
V_3 -> V_4 = & V_227 -> V_4 ;
V_3 -> V_58 . V_123 = L_37 ;
V_3 -> V_58 . type = V_132 ;
V_3 -> V_58 . V_127 = V_236 ;
V_3 -> V_58 . V_124 = F_65 ( V_236 ) ;
V_3 -> V_58 . V_130 = F_45 ;
V_3 -> V_58 . V_122 = V_237 ;
V_3 -> V_58 . V_121 = F_65 ( V_237 ) ,
V_3 -> V_58 . V_238 =
F_38 ;
F_66 ( & V_3 -> V_34 ) ;
V_3 -> V_34 . V_239 = F_1 ;
V_3 -> V_34 . V_1 = ( unsigned long ) V_3 ;
F_66 ( & V_3 -> V_37 ) ;
V_3 -> V_37 . V_239 =
F_4 ;
V_3 -> V_37 . V_1 = ( unsigned long ) V_3 ;
V_3 -> V_7 =
F_67 ( L_43 ) ;
if ( V_3 -> V_7 == NULL ) {
F_2 ( V_3 -> V_4 , L_44 ) ;
return - V_233 ;
}
F_68 ( & V_3 -> V_207 ,
F_41 ) ;
F_68 ( & V_3 -> V_57 ,
F_43 ) ;
F_69 ( & V_3 -> V_8 , F_44 ) ;
V_3 -> V_14 . V_16 = - 1 ;
V_111 = F_70 ( V_3 -> V_4 , & V_3 -> V_58 ) ;
if ( V_111 ) {
F_2 ( V_3 -> V_4 , L_45 ) ;
goto V_240;
}
F_61 ( V_227 , V_3 ) ;
V_111 = F_51 ( V_3 ) ;
if ( V_111 ) {
F_2 ( V_3 -> V_4 , L_38 ) ;
goto V_241;
}
F_37 ( V_3 -> V_7 , & V_3 -> V_207 , 0 ) ;
F_48 ( V_3 -> V_4 , L_46 ) ;
return V_111 ;
V_241:
F_60 ( & V_3 -> V_58 ) ;
V_240:
F_58 ( V_3 -> V_7 ) ;
return V_111 ;
}
static int T_4 F_71 ( void )
{
return F_72 ( & V_242 ) ;
}
static void T_5 F_73 ( void )
{
F_74 ( & V_242 ) ;
}
