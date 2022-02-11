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
V_3 -> V_14 . V_41 & V_19 ) {
if ( V_3 -> V_38 -> V_42 &&
V_3 -> V_43 && V_3 -> V_43 -> V_39 . V_40 )
V_3 -> V_43 -> V_39 . V_40 ( V_3 -> V_43 ) ;
return V_3 -> V_38 -> V_39 . V_40 ( V_3 -> V_38 ) ;
}
else if ( V_3 -> V_43 && V_3 -> V_43 -> V_39 . V_40 &&
V_3 -> V_14 . V_41 & V_23 )
return V_3 -> V_43 -> V_39 . V_40 ( V_3 -> V_43 ) ;
return - V_44 ;
}
static int F_18 ( struct V_2 * V_3 , int V_45 ,
int V_46 , int V_47 )
{
if ( ! V_3 -> V_38 || ! V_3 -> V_38 -> V_39 . V_45 )
return - V_44 ;
if ( V_3 -> V_38 -> V_48 )
V_46 = F_19 ( V_46 , V_3 -> V_38 -> V_48 ) ;
if ( V_3 -> V_38 -> V_49 )
V_47 = F_19 ( V_47 , V_3 -> V_38 -> V_49 ) ;
V_3 -> V_14 . V_50 = V_47 ;
V_3 -> V_14 . V_51 = V_46 ;
return V_3 -> V_38 -> V_39 . V_45 ( V_3 -> V_38 , V_45 , V_46 , V_47 ) ;
}
static int F_20 ( struct V_2 * V_3 , int V_45 ,
int V_46 , int V_47 )
{
if ( ! V_3 -> V_43 || ! V_3 -> V_43 -> V_39 . V_45 )
return - V_44 ;
if ( V_3 -> V_43 -> V_48 )
V_46 = F_19 ( V_46 , V_3 -> V_43 -> V_48 ) ;
if ( V_3 -> V_43 -> V_49 )
V_47 = F_19 ( V_47 , V_3 -> V_43 -> V_49 ) ;
V_3 -> V_14 . V_52 = V_47 ;
V_3 -> V_14 . V_53 = V_46 ;
return V_3 -> V_43 -> V_39 . V_45 ( V_3 -> V_43 , V_45 , V_46 , V_47 ) ;
}
static int F_21 ( struct V_2 * V_3 ,
int V_47 )
{
if ( V_3 -> V_38 && V_3 -> V_38 -> V_39 . V_54 &&
V_3 -> V_14 . V_21 & V_19 ) {
if ( V_3 -> V_38 -> V_49 )
V_47 = F_19 ( V_47 , V_3 -> V_38 -> V_49 ) ;
V_3 -> V_14 . V_50 = V_47 ;
return V_3 -> V_38 -> V_39 . V_54 ( V_3 -> V_38 , V_47 ) ;
} else if ( V_3 -> V_43 && V_3 -> V_43 -> V_39 . V_54 &&
V_3 -> V_14 . V_21 & V_23 ) {
if ( V_3 -> V_43 -> V_49 )
V_47 = F_19 ( V_47 , V_3 -> V_43 -> V_49 ) ;
V_3 -> V_14 . V_52 = V_47 ;
return V_3 -> V_43 -> V_39 . V_54 ( V_3 -> V_43 , V_47 ) ;
}
return - V_44 ;
}
static void F_22 ( struct V_2 * V_3 )
{
F_18 ( V_3 , false , 0 , 0 ) ;
F_20 ( V_3 , false , 0 , 0 ) ;
F_13 ( V_3 ) ;
F_16 ( V_3 ) ;
V_3 -> V_55 = V_56 ;
V_3 -> V_57 = false ;
F_23 ( & V_3 -> V_58 ) ;
F_24 ( & V_3 -> V_59 ) ;
}
static void F_25 ( struct V_2 * V_3 )
{
F_18 ( V_3 , false , 0 , 0 ) ;
F_20 ( V_3 , false , 0 , 0 ) ;
F_13 ( V_3 ) ;
F_16 ( V_3 ) ;
V_3 -> V_55 = V_60 ;
V_3 -> V_57 = false ;
F_23 ( & V_3 -> V_58 ) ;
F_24 ( & V_3 -> V_59 ) ;
}
static void F_26 ( struct V_2 * V_3 ,
int V_46 , int V_47 )
{
bool V_61 = true ;
switch ( V_3 -> V_14 . V_21 ) {
case V_19 :
F_5 ( V_3 -> V_4 ,
L_11 , V_46 , V_47 ) ;
F_20 ( V_3 , false , 0 , 0 ) ;
F_18 ( V_3 , true , V_46 , V_47 ) ;
break;
case V_23 :
F_5 ( V_3 -> V_4 ,
L_12 , V_46 , V_47 ) ;
F_18 ( V_3 , false , 0 , 0 ) ;
F_20 ( V_3 , true , V_46 , V_47 ) ;
break;
default:
F_2 ( V_3 -> V_4 , L_10 ) ;
V_61 = false ;
break;
}
if ( V_61 && ! F_27 ( & V_3 -> V_58 ) )
F_28 ( V_3 -> V_7 , & V_3 -> V_58 , 0 ) ;
}
static void F_29 ( struct V_2 * V_3 )
{
if ( V_3 -> V_62 . V_63 > ( V_3 -> V_30 -> V_64 + V_3 -> V_65 ) &&
V_3 -> V_62 . V_63 < ( V_3 -> V_30 -> V_66 - V_3 -> V_65 ) ) {
V_3 -> V_5 . V_67 = false ;
V_3 -> V_5 . V_68 = false ;
V_3 -> V_65 = 0 ;
V_3 -> V_69 = 0 ;
} else {
if ( ( ( V_3 -> V_62 . V_63 >= V_3 -> V_30 -> V_66 ) &&
( V_3 -> V_62 . V_63 <
( V_3 -> V_30 -> V_70 - V_3 -> V_69 ) ) ) ||
( ( V_3 -> V_62 . V_63 >
( V_3 -> V_30 -> V_71 + V_3 -> V_69 ) ) &&
( V_3 -> V_62 . V_63 <= V_3 -> V_30 -> V_64 ) ) ) {
V_3 -> V_5 . V_67 = false ;
V_3 -> V_5 . V_68 = true ;
V_3 -> V_65 = V_3 -> V_30 -> V_72 ;
V_3 -> V_69 = 0 ;
} else if ( V_3 -> V_62 . V_63 <= V_3 -> V_30 -> V_71 ||
V_3 -> V_62 . V_63 >= V_3 -> V_30 -> V_70 ) {
V_3 -> V_5 . V_67 = true ;
V_3 -> V_5 . V_68 = false ;
V_3 -> V_65 = 0 ;
V_3 -> V_69 = V_3 -> V_30 -> V_72 ;
} else {
F_5 ( V_3 -> V_4 , L_13
L_14 ,
V_3 -> V_62 . V_63 , V_3 -> V_69 ,
V_3 -> V_65 ) ;
}
}
}
static void F_30 ( struct V_2 * V_3 )
{
if ( V_3 -> V_14 . V_73 > V_3 -> V_30 -> V_74 -> V_75 )
V_3 -> V_14 . V_76 = false ;
else
V_3 -> V_14 . V_76 = true ;
if ( V_3 -> V_14 . V_77 > V_3 -> V_30 -> V_74 -> V_78 )
V_3 -> V_14 . V_79 = false ;
else
V_3 -> V_14 . V_79 = true ;
}
static void F_31 ( struct V_2 * V_3 )
{
if ( V_3 -> V_55 == V_60 &&
V_3 -> V_12 == V_80 &&
! V_3 -> V_57 && ( V_3 -> V_62 . V_81 >=
V_3 -> V_30 -> V_82 [ V_3 -> V_30 -> V_83 ] . V_84 ||
V_3 -> V_5 . V_85 || V_3 -> V_5 . V_86 ) &&
V_3 -> V_62 . V_87 <
V_3 -> V_30 -> V_82 [ V_3 -> V_30 -> V_83 ] . V_88 &&
V_3 -> V_62 . V_87 > 0 ) {
if ( ++ V_3 -> V_89 >= V_90 ) {
V_3 -> V_89 = 0 ;
V_3 -> V_55 = V_91 ;
V_3 -> V_57 = true ;
F_5 ( V_3 -> V_4 , L_15 ) ;
F_24 ( & V_3 -> V_59 ) ;
} else {
F_5 ( V_3 -> V_4 ,
L_16
L_17 ,
V_3 -> V_89 ,
V_90 ) ;
}
} else {
V_3 -> V_89 = 0 ;
}
}
static void F_32 ( struct V_2 * V_3 )
{
V_3 -> V_92 . V_93 =
V_3 -> V_30 -> V_82 [ V_3 -> V_30 -> V_83 ] . V_94 ;
V_3 -> V_92 . V_95 =
V_3 -> V_30 -> V_82 [ V_3 -> V_30 -> V_83 ] . V_94 ;
V_3 -> V_92 . V_96 = V_3 -> V_30 -> V_97 -> V_98 ;
V_3 -> V_92 . V_99 = V_3 -> V_30 -> V_97 -> V_100 ;
V_3 -> V_92 . V_101 = V_3 -> V_30 -> V_97 -> V_102 ;
V_3 -> V_92 . V_103 = 0 ;
}
static enum V_104 F_33 ( struct V_2 * V_3 )
{
int V_105 ;
if ( ! V_3 -> V_30 -> V_97 -> V_106 )
return V_107 ;
V_105 = V_3 -> V_92 . V_93 - V_3 -> V_62 . V_108 ;
if ( V_3 -> V_5 . V_109 ) {
F_5 ( V_3 -> V_4 , L_18 ,
V_3 -> V_92 . V_110 ) ;
if ( V_3 -> V_92 . V_110 == 0 ) {
F_5 ( V_3 -> V_4 , L_19 ) ;
V_3 -> V_92 . V_110 ++ ;
V_3 -> V_92 . V_101 = V_3 -> V_30 -> V_97 -> V_102 ;
V_3 -> V_92 . V_99 =
V_3 -> V_92 . V_95 - V_3 -> V_92 . V_96 ;
V_3 -> V_92 . V_95 = V_3 -> V_92 . V_99 ;
V_3 -> V_92 . V_103 -- ;
return V_111 ;
} else {
F_5 ( V_3 -> V_4 , L_20 ) ;
V_3 -> V_92 . V_110 = ( V_3 -> V_92 . V_110 + 1 ) % 3 ;
return V_107 ;
}
}
V_3 -> V_92 . V_110 = 0 ;
if ( ( V_3 -> V_62 . V_108 > V_3 -> V_92 . V_93 ) ) {
F_5 ( V_3 -> V_4 , L_21
L_22 ,
V_3 -> V_62 . V_108 , V_3 -> V_92 . V_93 ,
V_3 -> V_92 . V_95 ) ;
if ( V_3 -> V_92 . V_95 == V_3 -> V_92 . V_93 )
return V_107 ;
V_3 -> V_92 . V_101 = V_3 -> V_30 -> V_97 -> V_102 ;
V_3 -> V_92 . V_95 = V_3 -> V_92 . V_93 ;
V_3 -> V_92 . V_103 = 0 ;
return V_112 ;
}
if ( V_105 > V_3 -> V_92 . V_96 &&
( V_3 -> V_92 . V_95 + V_3 -> V_92 . V_96 ) <
V_3 -> V_92 . V_99 ) {
if ( V_3 -> V_92 . V_101 -- == 0 ) {
V_3 -> V_92 . V_101 = V_3 -> V_30 -> V_97 -> V_102 ;
V_3 -> V_92 . V_95 += V_3 -> V_92 . V_96 ;
V_3 -> V_92 . V_103 ++ ;
F_5 ( V_3 -> V_4 , L_23
L_24
L_25 ,
V_3 -> V_92 . V_96 ,
V_3 -> V_92 . V_95 ,
V_3 -> V_92 . V_93 ,
V_3 -> V_92 . V_103 ) ;
return V_111 ;
} else {
return V_107 ;
}
} else {
V_3 -> V_92 . V_101 = V_3 -> V_30 -> V_97 -> V_102 ;
return V_107 ;
}
}
static void F_34 ( struct V_2 * V_3 )
{
enum V_104 V_113 ;
int V_114 ;
V_113 = F_33 ( V_3 ) ;
switch ( V_113 ) {
case V_111 :
V_114 = F_21 ( V_3 ,
V_3 -> V_92 . V_95 ) ;
if ( V_114 )
F_2 ( V_3 -> V_4 , L_26 ) ;
break;
case V_112 :
V_114 = F_21 ( V_3 ,
V_3 -> V_30 -> V_82 [ V_3 -> V_30 -> V_83 ] . V_94 ) ;
if ( V_114 )
F_2 ( V_3 -> V_4 , L_26 ) ;
break;
case V_107 :
default:
break;
}
}
static int F_35 ( struct V_115 * V_4 , void * V_1 )
{
struct V_116 * V_117 ;
struct V_116 * V_118 ;
struct V_2 * V_3 ;
union V_119 V_113 ;
int V_120 , V_121 ;
bool V_122 = false ;
bool V_123 = false ;
V_117 = (struct V_116 * ) V_1 ;
V_118 = F_36 ( V_4 ) ;
V_3 = F_37 ( V_117 ) ;
for ( V_120 = 0 ; V_120 < V_118 -> V_124 ; V_120 ++ ) {
if ( ! strcmp ( V_118 -> V_125 [ V_120 ] , V_117 -> V_126 ) )
V_122 = true ;
}
if ( ! V_122 )
return 0 ;
if ( ! V_118 -> V_127 ( V_118 , V_128 , & V_113 ) ) {
V_3 -> V_62 . V_129 = V_113 . V_130 ;
V_123 = true ;
}
for ( V_121 = 0 ; V_121 < V_118 -> V_131 ; V_121 ++ ) {
enum V_132 V_133 ;
V_133 = V_118 -> V_134 [ V_121 ] ;
if ( ! V_3 -> V_38 &&
V_118 -> type == V_135 )
V_3 -> V_38 = F_38 ( V_118 ) ;
else if ( ! V_3 -> V_43 &&
V_118 -> type == V_136 )
V_3 -> V_43 = F_38 ( V_118 ) ;
if ( V_118 -> V_127 ( V_118 , V_133 , & V_113 ) )
continue;
switch ( V_133 ) {
case V_137 :
switch ( V_118 -> type ) {
case V_138 :
if ( V_113 . V_130 )
V_3 -> V_5 . V_139 = false ;
else
V_3 -> V_5 . V_139 = true ;
break;
case V_135 :
if ( ! V_113 . V_130 &&
( V_3 -> V_14 . V_15 & V_19 ) ) {
V_3 -> V_14 . V_16 =
V_3 -> V_14 . V_15 ;
V_3 -> V_14 . V_15 &= ~ V_19 ;
}
else if ( V_113 . V_130 &&
! ( V_3 -> V_14 . V_15 & V_19 ) ) {
V_3 -> V_14 . V_16 =
V_3 -> V_14 . V_15 ;
V_3 -> V_14 . V_15 |= V_19 ;
}
break;
case V_136 :
if ( ! V_113 . V_130 &&
( V_3 -> V_14 . V_15 & V_23 ) ) {
V_3 -> V_14 . V_16 =
V_3 -> V_14 . V_15 ;
V_3 -> V_14 . V_15 &= ~ V_23 ;
}
else if ( V_113 . V_130 &&
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
case V_140 :
switch ( V_118 -> type ) {
case V_138 :
break;
case V_135 :
if ( ! V_113 . V_130 &&
( V_3 -> V_14 . V_41 & V_19 ) ) {
V_3 -> V_14 . V_141 =
V_3 -> V_14 . V_41 ;
V_3 -> V_14 . V_41 &= ~ V_19 ;
}
else if ( V_113 . V_130 &&
! ( V_3 -> V_14 . V_41 & V_19 ) ) {
V_3 -> V_14 . V_141 =
V_3 -> V_14 . V_41 ;
V_3 -> V_14 . V_41 |= V_19 ;
F_28 ( V_3 -> V_7 ,
& V_3 -> V_58 , 0 ) ;
}
break;
case V_136 :
if ( ! V_113 . V_130 &&
( V_3 -> V_14 . V_41 & V_23 ) ) {
V_3 -> V_14 . V_141 =
V_3 -> V_14 . V_41 ;
V_3 -> V_14 . V_41 &= ~ V_23 ;
}
else if ( V_113 . V_130 &&
! ( V_3 -> V_14 . V_41 & V_23 ) ) {
V_3 -> V_14 . V_141 =
V_3 -> V_14 . V_41 ;
V_3 -> V_14 . V_41 |= V_23 ;
F_28 ( V_3 -> V_7 ,
& V_3 -> V_58 , 0 ) ;
}
break;
default:
break;
}
break;
case V_142 :
switch ( V_118 -> type ) {
case V_138 :
break;
case V_135 :
switch ( V_113 . V_130 ) {
case V_143 :
V_3 -> V_5 . V_144 = true ;
V_3 -> V_5 . V_145 = false ;
V_3 -> V_5 . V_146 = false ;
V_3 -> V_5 . V_147 = false ;
break;
case V_148 :
V_3 -> V_5 . V_147 = true ;
V_3 -> V_5 . V_144 = false ;
V_3 -> V_5 . V_146 = false ;
V_3 -> V_5 . V_145 = false ;
break;
case V_149 :
case V_150 :
V_3 -> V_5 . V_145 = true ;
V_3 -> V_5 . V_144 = false ;
V_3 -> V_5 . V_146 = false ;
V_3 -> V_5 . V_147 = false ;
break;
case V_151 :
V_3 -> V_5 . V_146 = true ;
V_3 -> V_5 . V_144 = false ;
V_3 -> V_5 . V_145 = false ;
V_3 -> V_5 . V_147 = false ;
break;
case V_152 :
V_3 -> V_5 . V_145 = false ;
V_3 -> V_5 . V_144 = false ;
V_3 -> V_5 . V_146 = false ;
V_3 -> V_5 . V_147 = false ;
break;
default:
break;
}
break;
case V_136 :
switch ( V_113 . V_130 ) {
case V_143 :
V_3 -> V_5 . V_153 = true ;
V_3 -> V_5 . V_154 = false ;
V_3 -> V_5 . V_155 = false ;
V_3 -> V_5 . V_156 = false ;
break;
case V_148 :
V_3 -> V_5 . V_156 = true ;
V_3 -> V_5 . V_153 = false ;
V_3 -> V_5 . V_154 = false ;
V_3 -> V_5 . V_155 = false ;
break;
case V_149 :
case V_150 :
V_3 -> V_5 . V_154 = true ;
V_3 -> V_5 . V_153 = false ;
V_3 -> V_5 . V_155 = false ;
V_3 -> V_5 . V_156 = false ;
break;
case V_151 :
V_3 -> V_5 . V_155 = true ;
V_3 -> V_5 . V_153 = false ;
V_3 -> V_5 . V_154 = false ;
V_3 -> V_5 . V_156 = false ;
break;
case V_152 :
V_3 -> V_5 . V_153 = false ;
V_3 -> V_5 . V_154 = false ;
V_3 -> V_5 . V_155 = false ;
V_3 -> V_5 . V_156 = false ;
break;
default:
break;
}
default:
break;
}
break;
case V_157 :
switch ( V_118 -> type ) {
case V_138 :
V_3 -> V_62 . V_81 = V_113 . V_130 / 1000 ;
break;
case V_135 :
V_3 -> V_14 . V_77 = V_113 . V_130 / 1000 ;
break;
case V_136 :
V_3 -> V_14 . V_73 = V_113 . V_130 / 1000 ;
break;
default:
break;
}
break;
case V_158 :
switch ( V_118 -> type ) {
case V_135 :
if ( V_113 . V_130 )
V_3 -> V_5 . V_86 = true ;
else
V_3 -> V_5 . V_86 = false ;
break;
case V_136 :
if ( V_113 . V_130 )
V_3 -> V_5 . V_85 = true ;
else
V_3 -> V_5 . V_85 = false ;
break;
default:
break;
}
break;
case V_159 :
switch ( V_118 -> type ) {
case V_138 :
if ( V_113 . V_130 )
V_3 -> V_5 . V_160 = false ;
else
V_3 -> V_5 . V_160 = true ;
break;
default:
break;
}
break;
case V_161 :
V_3 -> V_62 . V_63 = V_113 . V_130 / 10 ;
break;
case V_162 :
switch ( V_118 -> type ) {
case V_135 :
V_3 -> V_14 . V_163 =
V_113 . V_130 / 1000 ;
break;
case V_136 :
V_3 -> V_14 . V_164 =
V_113 . V_130 / 1000 ;
break;
case V_138 :
V_3 -> V_62 . V_108 = V_113 . V_130 / 1000 ;
break;
default:
break;
}
break;
case V_165 :
switch ( V_118 -> type ) {
case V_138 :
V_3 -> V_62 . V_87 = V_113 . V_130 / 1000 ;
break;
case V_136 :
if ( V_113 . V_130 )
V_3 -> V_5 . V_109 = true ;
else
V_3 -> V_5 . V_109 = false ;
break;
default:
break;
}
break;
case V_128 :
if ( ! V_123 )
V_3 -> V_62 . V_129 = V_113 . V_130 ;
break;
default:
break;
}
}
return 0 ;
}
static void F_39 ( struct V_116 * V_117 )
{
struct V_2 * V_3 = F_37 ( V_117 ) ;
F_3 ( V_3 -> V_7 , & V_3 -> V_8 ) ;
}
static void F_40 ( struct V_2 * V_3 )
{
int V_166 ;
F_41 ( V_167 , NULL ,
& V_3 -> V_59 , F_35 ) ;
F_31 ( V_3 ) ;
F_29 ( V_3 ) ;
F_30 ( V_3 ) ;
V_166 = F_7 ( V_3 ) ;
if ( ! V_166 ||
( V_3 -> V_5 . V_160 && ! V_3 -> V_30 -> V_168 ) ) {
if ( V_3 -> V_12 != V_169 ) {
V_3 -> V_5 . V_6 = false ;
F_6 ( V_3 , V_27 ) ;
}
}
else if ( V_3 -> V_12 == V_26 ||
V_3 -> V_12 == V_170 ) {
}
else if ( V_3 -> V_5 . V_6 ) {
if ( V_3 -> V_12 != V_171 )
F_6 ( V_3 ,
V_172 ) ;
}
else if ( V_3 -> V_5 . V_139 ) {
if ( V_3 -> V_12 != V_173 )
F_6 ( V_3 , V_174 ) ;
}
else if ( V_3 -> V_5 . V_144 || V_3 -> V_5 . V_153 ) {
if ( V_3 -> V_12 != V_175 &&
! V_3 -> V_5 . V_109 )
F_6 ( V_3 , V_176 ) ;
}
else if ( V_3 -> V_5 . V_155 ||
V_3 -> V_5 . V_146 ||
V_3 -> V_5 . V_177 ||
! V_3 -> V_14 . V_76 ||
! V_3 -> V_14 . V_79 ) {
if ( V_3 -> V_12 != V_178 )
F_6 ( V_3 , V_179 ) ;
}
else if ( V_3 -> V_5 . V_145 ||
V_3 -> V_5 . V_154 ) {
if ( V_3 -> V_12 != V_180 )
F_6 ( V_3 ,
V_181 ) ;
}
else if ( V_3 -> V_5 . V_67 ) {
if ( V_3 -> V_12 != V_182 )
F_6 ( V_3 ,
V_183 ) ;
}
else if ( V_3 -> V_5 . V_147 ||
V_3 -> V_5 . V_156 ) {
if ( V_3 -> V_12 != V_184 )
F_6 ( V_3 , V_185 ) ;
}
else if ( V_3 -> V_5 . V_68 ) {
if ( V_3 -> V_12 != V_186 )
F_6 ( V_3 , V_187 ) ;
}
F_5 ( V_3 -> V_4 ,
L_27
L_28
L_29
L_30 ,
V_3 -> V_62 . V_81 ,
V_3 -> V_62 . V_87 ,
V_3 -> V_62 . V_108 ,
V_3 -> V_62 . V_63 ,
V_3 -> V_62 . V_129 ,
V_3 -> V_57 ,
V_13 [ V_3 -> V_12 ] ,
V_3 -> V_14 . V_21 ,
V_3 -> V_55 ,
V_3 -> V_14 . V_15 & V_19 ,
V_3 -> V_14 . V_15 & V_23 ,
V_3 -> V_14 . V_41 & V_19 ,
V_3 -> V_14 . V_41 & V_23 ,
V_3 -> V_5 . V_86 ,
V_3 -> V_5 . V_85 ,
V_3 -> V_14 . V_163 ,
V_3 -> V_14 . V_164 ,
V_3 -> V_14 . V_51 ,
V_3 -> V_14 . V_50 ,
V_3 -> V_14 . V_53 ,
V_3 -> V_14 . V_52 ) ;
switch ( V_3 -> V_12 ) {
case V_27 :
F_22 ( V_3 ) ;
V_3 -> V_55 = V_188 ;
F_6 ( V_3 , V_169 ) ;
case V_169 :
break;
case V_26 :
if ( V_3 -> V_17 . V_20 )
F_18 ( V_3 , false , 0 , 0 ) ;
if ( V_3 -> V_17 . V_24 )
F_20 ( V_3 , false , 0 , 0 ) ;
F_13 ( V_3 ) ;
F_16 ( V_3 ) ;
V_3 -> V_55 = V_56 ;
V_3 -> V_57 = false ;
F_6 ( V_3 , V_170 ) ;
F_24 ( & V_3 -> V_59 ) ;
case V_170 :
break;
case V_174 :
F_22 ( V_3 ) ;
F_6 ( V_3 , V_173 ) ;
case V_173 :
if ( ! V_3 -> V_5 . V_139 )
F_6 ( V_3 , V_22 ) ;
break;
case V_181 :
F_22 ( V_3 ) ;
F_6 ( V_3 , V_180 ) ;
case V_180 :
if ( ! V_3 -> V_5 . V_145 &&
! V_3 -> V_5 . V_154 )
F_6 ( V_3 , V_22 ) ;
break;
case V_179 :
F_22 ( V_3 ) ;
F_6 ( V_3 , V_178 ) ;
case V_178 :
if ( ! V_3 -> V_5 . V_155 &&
! V_3 -> V_5 . V_146 &&
! V_3 -> V_5 . V_177 &&
V_3 -> V_14 . V_76 &&
V_3 -> V_14 . V_79 )
F_6 ( V_3 , V_22 ) ;
break;
case V_176 :
F_22 ( V_3 ) ;
F_6 ( V_3 , V_175 ) ;
case V_175 :
if ( ! V_3 -> V_5 . V_144 &&
! V_3 -> V_5 . V_153 )
F_6 ( V_3 , V_22 ) ;
break;
case V_172 :
F_22 ( V_3 ) ;
F_6 ( V_3 , V_171 ) ;
case V_171 :
break;
case V_22 :
F_26 ( V_3 ,
V_3 -> V_30 -> V_82 [ V_3 -> V_30 -> V_83 ] . V_189 ,
V_3 -> V_30 -> V_82 [ V_3 -> V_30 -> V_83 ] . V_94 ) ;
F_6 ( V_3 , V_80 ) ;
F_8 ( V_3 ) ;
F_16 ( V_3 ) ;
F_32 ( V_3 ) ;
V_3 -> V_55 = V_60 ;
V_3 -> V_89 = 0 ;
V_3 -> V_57 = false ;
F_24 ( & V_3 -> V_59 ) ;
break;
case V_80 :
F_34 ( V_3 ) ;
if ( V_3 -> V_55 == V_91 &&
V_3 -> V_57 ) {
if ( V_3 -> V_30 -> V_190 )
F_6 ( V_3 ,
V_191 ) ;
else
F_6 ( V_3 ,
V_192 ) ;
}
break;
case V_191 :
F_25 ( V_3 ) ;
F_6 ( V_3 , V_193 ) ;
case V_193 :
if ( V_3 -> V_62 . V_129 <=
V_3 -> V_30 -> V_82 [ V_3 -> V_30 -> V_83 ] .
V_194 )
F_6 ( V_3 , V_22 ) ;
break;
case V_192 :
F_13 ( V_3 ) ;
F_15 ( V_3 ,
V_3 -> V_30 -> V_82 [
V_3 -> V_30 -> V_83 ] . V_195 ) ;
F_26 ( V_3 ,
V_3 -> V_30 -> V_82 [
V_3 -> V_30 -> V_83 ] . V_196 ,
V_3 -> V_30 -> V_82 [
V_3 -> V_30 -> V_83 ] . V_197 ) ;
F_6 ( V_3 , V_198 ) ;
F_24 ( & V_3 -> V_59 ) ;
case V_198 :
if ( V_3 -> V_5 . V_9 ) {
F_16 ( V_3 ) ;
F_6 ( V_3 , V_199 ) ;
}
break;
case V_199 :
F_15 ( V_3 ,
V_3 -> V_30 -> V_82 [
V_3 -> V_30 -> V_83 ] . V_200 ) ;
F_26 ( V_3 ,
V_3 -> V_30 -> V_82 [
V_3 -> V_30 -> V_83 ] . V_201 ,
V_3 -> V_30 -> V_82 [
V_3 -> V_30 -> V_83 ] . V_202 ) ;
F_6 ( V_3 , V_203 ) ;
F_24 ( & V_3 -> V_59 ) ;
case V_203 :
if ( V_3 -> V_5 . V_9 ) {
F_16 ( V_3 ) ;
F_6 ( V_3 , V_22 ) ;
}
break;
case V_187 :
F_26 ( V_3 ,
V_3 -> V_30 -> V_82 [
V_3 -> V_30 -> V_83 ] . V_204 ,
V_3 -> V_30 -> V_82 [
V_3 -> V_30 -> V_83 ] . V_205 ) ;
F_16 ( V_3 ) ;
V_3 -> V_55 = V_60 ;
F_6 ( V_3 , V_186 ) ;
F_24 ( & V_3 -> V_59 ) ;
case V_186 :
if ( ! V_3 -> V_5 . V_68 )
F_6 ( V_3 , V_22 ) ;
break;
case V_185 :
F_22 ( V_3 ) ;
F_6 ( V_3 , V_184 ) ;
case V_184 :
if ( ! V_3 -> V_5 . V_147 &&
! V_3 -> V_5 . V_156 )
F_6 ( V_3 , V_22 ) ;
break;
case V_183 :
F_22 ( V_3 ) ;
F_6 ( V_3 , V_182 ) ;
case V_182 :
if ( ! V_3 -> V_5 . V_67 )
F_6 ( V_3 , V_22 ) ;
break;
}
if ( V_3 -> V_12 == V_22 ||
V_3 -> V_12 == V_192 ||
V_3 -> V_12 == V_199 )
F_3 ( V_3 -> V_7 , & V_3 -> V_8 ) ;
}
static void F_42 ( struct V_206 * V_207 )
{
struct V_2 * V_3 = F_43 ( V_207 ,
struct V_2 , V_208 . V_207 ) ;
F_40 ( V_3 ) ;
if ( V_3 -> V_14 . V_15 )
F_28 ( V_3 -> V_7 ,
& V_3 -> V_208 ,
V_3 -> V_30 -> V_209 * V_32 ) ;
else
F_28 ( V_3 -> V_7 ,
& V_3 -> V_208 ,
V_3 -> V_30 -> V_210 * V_32 ) ;
}
static void F_44 ( struct V_206 * V_207 )
{
int V_113 ;
struct V_2 * V_3 = F_43 ( V_207 ,
struct V_2 , V_58 . V_207 ) ;
F_5 ( V_3 -> V_4 , L_31 ) ;
V_113 = F_17 ( V_3 ) ;
if ( V_113 < 0 )
F_2 ( V_3 -> V_4 , L_32 ) ;
F_28 ( V_3 -> V_7 ,
& V_3 -> V_58 , V_211 ) ;
}
static void F_45 ( struct V_206 * V_207 )
{
struct V_2 * V_3 = F_43 ( V_207 ,
struct V_2 , V_8 ) ;
F_40 ( V_3 ) ;
}
static int F_46 ( struct V_116 * V_117 ,
enum V_132 V_212 ,
union V_119 * V_213 )
{
struct V_2 * V_3 ;
V_3 = F_37 ( V_117 ) ;
switch ( V_212 ) {
case V_214 :
V_213 -> V_130 = V_3 -> V_55 ;
break;
case V_142 :
if ( V_3 -> V_5 . V_177 ) {
V_213 -> V_130 = V_151 ;
} else if ( V_3 -> V_5 . V_67 ) {
if ( V_3 -> V_62 . V_63 <= V_3 -> V_30 -> V_71 )
V_213 -> V_130 = V_149 ;
else
V_213 -> V_130 = V_150 ;
} else if ( V_3 -> V_12 == V_171 ||
V_3 -> V_12 == V_172 ) {
V_213 -> V_130 = V_143 ;
} else {
V_213 -> V_130 = V_152 ;
}
break;
default:
return - V_215 ;
}
return 0 ;
}
static T_1 F_47 ( struct V_216 * V_217 ,
struct V_218 * V_219 , char * V_220 )
{
struct V_2 * V_3 = F_43 ( V_217 ,
struct V_2 , V_221 ) ;
return sprintf ( V_220 , L_33 ,
V_3 -> V_17 . V_20 &&
V_3 -> V_17 . V_24 ) ;
}
static T_1 F_48 ( struct V_216 * V_217 ,
struct V_218 * V_219 , const char * V_220 , T_2 V_222 )
{
struct V_2 * V_3 = F_43 ( V_217 ,
struct V_2 , V_221 ) ;
long int V_223 ;
int V_224 ;
int V_113 ;
char V_225 = * V_219 -> V_126 ;
switch ( V_225 ) {
case 'c' :
V_113 = F_49 ( V_220 , 10 , & V_223 ) ;
if ( V_113 < 0 )
return V_113 ;
V_224 = V_223 ;
switch ( V_224 ) {
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
F_50 ( V_3 -> V_4 , L_34
L_35
L_36
L_37 ) ;
} ;
break;
} ;
return strlen ( V_220 ) ;
}
static void F_51 ( struct V_2 * V_3 )
{
F_52 ( & V_3 -> V_221 ) ;
}
static int F_53 ( struct V_2 * V_3 )
{
int V_113 = 0 ;
V_113 = F_54 ( & V_3 -> V_221 ,
& V_226 ,
NULL , L_38 ) ;
if ( V_113 < 0 )
F_2 ( V_3 -> V_4 , L_39 ) ;
return V_113 ;
}
static int F_55 ( struct V_227 * V_228 )
{
struct V_2 * V_3 = F_56 ( V_228 ) ;
if ( V_3 -> V_14 . V_41 )
F_28 ( V_3 -> V_7 , & V_3 -> V_58 , 0 ) ;
F_28 ( V_3 -> V_7 , & V_3 -> V_208 , 0 ) ;
return 0 ;
}
static int F_57 ( struct V_227 * V_228 ,
T_3 V_11 )
{
struct V_2 * V_3 = F_56 ( V_228 ) ;
if ( V_3 -> V_14 . V_41 )
F_58 ( & V_3 -> V_58 ) ;
F_58 ( & V_3 -> V_208 ) ;
return 0 ;
}
static int F_59 ( struct V_227 * V_228 )
{
struct V_2 * V_3 = F_56 ( V_228 ) ;
F_51 ( V_3 ) ;
F_60 ( V_3 -> V_7 ) ;
F_61 () ;
F_62 ( & V_3 -> V_59 ) ;
F_63 ( V_228 , NULL ) ;
return 0 ;
}
static int F_64 ( struct V_227 * V_228 )
{
struct V_229 * V_230 = V_228 -> V_4 . V_231 ;
struct V_232 * V_233 = V_228 -> V_4 . V_234 ;
struct V_2 * V_3 ;
int V_113 = 0 ;
V_3 = F_65 ( & V_228 -> V_4 , sizeof( * V_3 ) , V_235 ) ;
if ( ! V_3 ) {
F_2 ( & V_228 -> V_4 , L_40 , V_236 ) ;
return - V_237 ;
}
if ( ! V_233 ) {
F_2 ( & V_228 -> V_4 , L_41 ) ;
return - V_215 ;
}
V_3 -> V_30 = V_233 ;
if ( V_230 ) {
V_113 = F_66 ( & V_228 -> V_4 , V_230 , V_3 -> V_30 ) ;
if ( V_113 ) {
F_2 ( & V_228 -> V_4 , L_42 ) ;
return V_113 ;
}
}
V_3 -> V_4 = & V_228 -> V_4 ;
V_3 -> V_59 . V_126 = L_38 ;
V_3 -> V_59 . type = V_138 ;
V_3 -> V_59 . V_134 = V_238 ;
V_3 -> V_59 . V_131 = F_67 ( V_238 ) ;
V_3 -> V_59 . V_127 = F_46 ;
V_3 -> V_59 . V_125 = V_239 ;
V_3 -> V_59 . V_124 = F_67 ( V_239 ) ,
V_3 -> V_59 . V_240 =
F_39 ;
F_68 ( & V_3 -> V_34 ) ;
V_3 -> V_34 . V_241 = F_1 ;
V_3 -> V_34 . V_1 = ( unsigned long ) V_3 ;
F_68 ( & V_3 -> V_37 ) ;
V_3 -> V_37 . V_241 =
F_4 ;
V_3 -> V_37 . V_1 = ( unsigned long ) V_3 ;
V_3 -> V_7 =
F_69 ( L_43 ) ;
if ( V_3 -> V_7 == NULL ) {
F_2 ( V_3 -> V_4 , L_44 ) ;
return - V_237 ;
}
F_70 ( & V_3 -> V_208 ,
F_42 ) ;
F_70 ( & V_3 -> V_58 ,
F_44 ) ;
F_71 ( & V_3 -> V_8 , F_45 ) ;
V_3 -> V_14 . V_16 = - 1 ;
V_113 = F_72 ( V_3 -> V_4 , & V_3 -> V_59 ) ;
if ( V_113 ) {
F_2 ( V_3 -> V_4 , L_45 ) ;
goto V_242;
}
F_63 ( V_228 , V_3 ) ;
V_113 = F_53 ( V_3 ) ;
if ( V_113 ) {
F_2 ( V_3 -> V_4 , L_39 ) ;
goto V_243;
}
F_28 ( V_3 -> V_7 , & V_3 -> V_208 , 0 ) ;
F_50 ( V_3 -> V_4 , L_46 ) ;
return V_113 ;
V_243:
F_62 ( & V_3 -> V_59 ) ;
V_242:
F_60 ( V_3 -> V_7 ) ;
return V_113 ;
}
static int T_4 F_73 ( void )
{
return F_74 ( & V_244 ) ;
}
static void T_5 F_75 ( void )
{
F_76 ( & V_244 ) ;
}
