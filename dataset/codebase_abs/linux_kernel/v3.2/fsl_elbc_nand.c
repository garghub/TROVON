static void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_8 = V_7 -> V_8 ;
struct V_10 * V_11 = V_8 -> V_11 ;
struct V_12 T_1 * V_13 = V_11 -> V_14 ;
struct V_15 * V_16 = V_11 -> V_17 ;
int V_18 ;
V_16 -> V_19 = V_4 ;
F_2 ( & V_13 -> V_20 ,
V_4 >> ( V_7 -> V_21 - V_7 -> V_22 ) ) ;
if ( V_8 -> V_23 ) {
F_2 ( & V_13 -> V_24 ,
( ( V_4 << V_25 ) & V_26 ) |
( V_5 ? V_27 : 0 ) | V_3 ) ;
V_18 = ( V_4 & 1 ) << 2 ;
} else {
F_2 ( & V_13 -> V_24 ,
( ( V_4 << V_28 ) & V_29 ) |
( V_5 ? V_30 : 0 ) | V_3 ) ;
V_18 = V_4 & 7 ;
}
V_16 -> V_31 = V_8 -> V_32 + V_18 * 1024 ;
V_16 -> V_33 = V_3 ;
if ( V_5 )
V_16 -> V_33 += V_8 -> V_23 ? 2048 : 512 ;
F_3 ( V_8 -> V_34 , L_1
L_2
L_3 ,
V_18 , V_16 -> V_31 , V_8 -> V_32 ,
V_16 -> V_33 ,
V_7 -> V_21 , V_7 -> V_22 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_8 = V_7 -> V_8 ;
struct V_10 * V_11 = V_8 -> V_11 ;
struct V_15 * V_16 = V_11 -> V_17 ;
struct V_12 T_1 * V_13 = V_11 -> V_14 ;
F_2 ( & V_13 -> V_35 , V_8 -> V_35 | 3 ) ;
if ( V_16 -> V_36 )
F_2 ( & V_13 -> V_37 , V_16 -> V_37 ) ;
F_3 ( V_8 -> V_34 ,
L_4 ,
F_5 ( & V_13 -> V_35 ) , F_5 ( & V_13 -> V_38 ) , F_5 ( & V_13 -> V_39 ) ) ;
F_3 ( V_8 -> V_34 ,
L_5
L_6 ,
F_5 ( & V_13 -> V_20 ) , F_5 ( & V_13 -> V_24 ) ,
F_5 ( & V_13 -> V_40 ) , V_8 -> V_41 ) ;
V_11 -> V_42 = 0 ;
F_2 ( & V_13 -> V_43 , V_8 -> V_41 ) ;
F_6 ( V_11 -> V_44 , V_11 -> V_42 ,
V_45 * V_46 / 1000 ) ;
V_16 -> V_47 = V_11 -> V_42 ;
if ( V_16 -> V_36 )
V_16 -> V_37 = F_5 ( & V_13 -> V_37 ) ;
V_16 -> V_36 = 0 ;
if ( V_16 -> V_47 != V_48 ) {
F_7 ( V_8 -> V_34 ,
L_7 ,
F_5 ( & V_13 -> V_38 ) , F_5 ( & V_13 -> V_39 ) ,
V_16 -> V_47 , V_16 -> V_37 ) ;
return - V_49 ;
}
if ( V_7 -> V_50 . V_51 != V_52 )
return 0 ;
if ( V_16 -> V_53 == V_2 -> V_54 + V_2 -> V_55 ) {
T_2 V_56 = F_5 ( & V_13 -> V_56 ) ;
if ( V_56 & 0x000F000F )
F_2 ( & V_13 -> V_56 , 0x000F000F ) ;
if ( V_56 & 0x000F0000 )
V_2 -> V_57 . V_58 ++ ;
}
return 0 ;
}
static void F_8 ( struct V_6 * V_7 , int V_5 )
{
struct V_9 * V_8 = V_7 -> V_8 ;
struct V_10 * V_11 = V_8 -> V_11 ;
struct V_12 T_1 * V_13 = V_11 -> V_14 ;
if ( V_8 -> V_23 ) {
F_2 ( & V_13 -> V_38 ,
( V_59 << V_60 ) |
( V_61 << V_62 ) |
( V_63 << V_64 ) |
( V_65 << V_66 ) |
( V_67 << V_68 ) ) ;
F_2 ( & V_13 -> V_39 , ( V_69 << V_70 ) |
( V_71 << V_72 ) ) ;
} else {
F_2 ( & V_13 -> V_38 ,
( V_59 << V_60 ) |
( V_61 << V_62 ) |
( V_63 << V_64 ) |
( V_67 << V_66 ) ) ;
if ( V_5 )
F_2 ( & V_13 -> V_39 , V_73 << V_70 ) ;
else
F_2 ( & V_13 -> V_39 , V_69 << V_70 ) ;
}
}
static void F_9 ( struct V_1 * V_2 , unsigned int V_74 ,
int V_3 , int V_4 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_8 = V_7 -> V_8 ;
struct V_10 * V_11 = V_8 -> V_11 ;
struct V_15 * V_16 = V_11 -> V_17 ;
struct V_12 T_1 * V_13 = V_11 -> V_14 ;
V_16 -> V_36 = 0 ;
V_16 -> V_53 = 0 ;
if ( V_74 != V_75 )
V_16 -> V_33 = 0 ;
switch ( V_74 ) {
case V_76 :
V_3 += 256 ;
case V_69 :
F_10 ( V_8 -> V_34 ,
L_8
L_9 , V_4 , V_3 ) ;
F_2 ( & V_13 -> V_40 , 0 ) ;
F_1 ( V_2 , 0 , V_4 , 0 ) ;
V_16 -> V_53 = V_2 -> V_54 + V_2 -> V_55 ;
V_16 -> V_33 += V_3 ;
F_8 ( V_7 , 0 ) ;
F_4 ( V_2 ) ;
return;
case V_73 :
F_3 ( V_8 -> V_34 ,
L_10
L_9 , V_4 , V_3 ) ;
F_2 ( & V_13 -> V_40 , V_2 -> V_55 - V_3 ) ;
F_1 ( V_2 , V_3 , V_4 , 1 ) ;
V_16 -> V_53 = V_2 -> V_54 + V_2 -> V_55 ;
F_8 ( V_7 , 1 ) ;
F_4 ( V_2 ) ;
return;
case V_77 :
F_3 ( V_8 -> V_34 , L_11 ) ;
F_2 ( & V_13 -> V_38 , ( V_59 << V_60 ) |
( V_78 << V_62 ) |
( V_67 << V_64 ) ) ;
F_2 ( & V_13 -> V_39 , V_77 << V_70 ) ;
F_2 ( & V_13 -> V_40 , 8 ) ;
V_16 -> V_53 = 8 ;
V_16 -> V_36 = 1 ;
V_16 -> V_37 = 0 ;
F_1 ( V_2 , 0 , 0 , 0 ) ;
F_4 ( V_2 ) ;
return;
case V_79 :
F_3 ( V_8 -> V_34 ,
L_12
L_13 , V_4 ) ;
F_1 ( V_2 , 0 , V_4 , 0 ) ;
return;
case V_80 :
F_3 ( V_8 -> V_34 , L_14 ) ;
F_2 ( & V_13 -> V_38 ,
( V_59 << V_60 ) |
( V_63 << V_62 ) |
( V_81 << V_64 ) |
( V_82 << V_66 ) |
( V_83 << V_68 ) ) ;
F_2 ( & V_13 -> V_39 ,
( V_79 << V_70 ) |
( V_84 << V_72 ) |
( V_80 << V_85 ) ) ;
F_2 ( & V_13 -> V_40 , 0 ) ;
V_16 -> V_53 = 0 ;
V_16 -> V_36 = 1 ;
F_4 ( V_2 ) ;
return;
case V_86 : {
T_3 V_39 ;
F_3 ( V_8 -> V_34 ,
L_15
L_16 ,
V_4 , V_3 ) ;
V_16 -> V_3 = V_3 ;
V_16 -> V_5 = 0 ;
V_16 -> V_36 = 1 ;
V_39 = ( V_84 << V_72 ) |
( V_86 << V_85 ) |
( V_75 << V_87 ) ;
if ( V_8 -> V_23 ) {
F_2 ( & V_13 -> V_38 ,
( V_81 << V_60 ) |
( V_61 << V_62 ) |
( V_63 << V_64 ) |
( V_88 << V_66 ) |
( V_89 << V_68 ) |
( V_82 << V_90 ) |
( V_83 << V_91 ) ) ;
} else {
F_2 ( & V_13 -> V_38 ,
( V_59 << V_60 ) |
( V_81 << V_62 ) |
( V_61 << V_64 ) |
( V_63 << V_66 ) |
( V_88 << V_68 ) |
( V_89 << V_90 ) |
( V_82 << V_91 ) |
( V_83 << V_92 ) ) ;
if ( V_3 >= V_2 -> V_54 ) {
V_3 -= V_2 -> V_54 ;
V_39 |= V_73 << V_70 ;
V_16 -> V_5 = 1 ;
} else {
F_11 ( V_3 != 0 ) ;
V_39 |= V_69 << V_70 ;
}
}
F_2 ( & V_13 -> V_39 , V_39 ) ;
F_1 ( V_2 , V_3 , V_4 , V_16 -> V_5 ) ;
return;
}
case V_75 : {
F_3 ( V_8 -> V_34 ,
L_17
L_18 , V_16 -> V_33 ) ;
if ( V_16 -> V_5 || V_16 -> V_3 != 0 ||
V_16 -> V_33 != V_2 -> V_54 + V_2 -> V_55 )
F_2 ( & V_13 -> V_40 , V_16 -> V_33 ) ;
else
F_2 ( & V_13 -> V_40 , 0 ) ;
F_4 ( V_2 ) ;
return;
}
case V_84 :
F_2 ( & V_13 -> V_38 ,
( V_59 << V_60 ) |
( V_67 << V_62 ) ) ;
F_2 ( & V_13 -> V_39 , V_84 << V_70 ) ;
F_2 ( & V_13 -> V_40 , 1 ) ;
F_1 ( V_2 , 0 , 0 , 0 ) ;
V_16 -> V_53 = 1 ;
F_4 ( V_2 ) ;
F_12 ( V_16 -> V_31 , V_93 ) ;
return;
case V_94 :
F_10 ( V_8 -> V_34 , L_19 ) ;
F_2 ( & V_13 -> V_38 , V_59 << V_60 ) ;
F_2 ( & V_13 -> V_39 , V_94 << V_70 ) ;
F_4 ( V_2 ) ;
return;
default:
F_13 ( V_8 -> V_34 ,
L_20 ,
V_74 ) ;
}
}
static void F_14 ( struct V_1 * V_2 , int V_7 )
{
}
static void F_15 ( struct V_1 * V_2 , const T_4 * V_95 , int V_96 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_8 = V_7 -> V_8 ;
struct V_15 * V_16 = V_8 -> V_11 -> V_17 ;
unsigned int V_97 = V_2 -> V_54 + V_2 -> V_55 ;
if ( V_96 <= 0 ) {
F_13 ( V_8 -> V_34 , L_21 , V_96 ) ;
V_16 -> V_47 = 0 ;
return;
}
if ( ( unsigned int ) V_96 > V_97 - V_16 -> V_33 ) {
F_13 ( V_8 -> V_34 ,
L_22
L_23 ,
V_96 , V_97 - V_16 -> V_33 ) ;
V_96 = V_97 - V_16 -> V_33 ;
}
F_16 ( & V_16 -> V_31 [ V_16 -> V_33 ] , V_95 , V_96 ) ;
F_17 ( & V_16 -> V_31 [ V_16 -> V_33 ] + V_96 - 1 ) ;
V_16 -> V_33 += V_96 ;
}
static T_4 F_18 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_8 = V_7 -> V_8 ;
struct V_15 * V_16 = V_8 -> V_11 -> V_17 ;
if ( V_16 -> V_33 < V_16 -> V_53 )
return F_17 ( & V_16 -> V_31 [ V_16 -> V_33 ++ ] ) ;
F_13 ( V_8 -> V_34 , L_24 ) ;
return V_98 ;
}
static void F_19 ( struct V_1 * V_2 , T_4 * V_95 , int V_96 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_8 = V_7 -> V_8 ;
struct V_15 * V_16 = V_8 -> V_11 -> V_17 ;
int V_99 ;
if ( V_96 < 0 )
return;
V_99 = F_20 ( ( unsigned int ) V_96 ,
V_16 -> V_53 - V_16 -> V_33 ) ;
F_21 ( V_95 , & V_16 -> V_31 [ V_16 -> V_33 ] , V_99 ) ;
V_16 -> V_33 += V_99 ;
if ( V_96 > V_99 )
F_13 ( V_8 -> V_34 ,
L_25
L_26 ,
V_96 , V_99 ) ;
}
static int F_22 ( struct V_1 * V_2 , const T_5 * V_95 , int V_96 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_8 = V_7 -> V_8 ;
struct V_15 * V_16 = V_8 -> V_11 -> V_17 ;
int V_100 ;
if ( V_96 < 0 ) {
F_13 ( V_8 -> V_34 , L_21 , V_96 ) ;
return - V_101 ;
}
if ( ( unsigned int ) V_96 >
V_16 -> V_53 - V_16 -> V_33 ) {
F_13 ( V_8 -> V_34 ,
L_27
L_23 ,
V_96 , V_16 -> V_53 - V_16 -> V_33 ) ;
V_16 -> V_33 = V_16 -> V_53 ;
return - V_101 ;
}
for ( V_100 = 0 ; V_100 < V_96 ; V_100 ++ )
if ( F_17 ( & V_16 -> V_31 [ V_16 -> V_33 + V_100 ] )
!= V_95 [ V_100 ] )
break;
V_16 -> V_33 += V_96 ;
return V_100 == V_96 && V_16 -> V_47 == V_48 ? 0 : - V_49 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_9 * V_8 = V_7 -> V_8 ;
struct V_15 * V_16 = V_8 -> V_11 -> V_17 ;
if ( V_16 -> V_47 != V_48 )
return V_102 ;
return ( V_16 -> V_37 & 0xff ) | V_93 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_8 = V_7 -> V_8 ;
struct V_10 * V_11 = V_8 -> V_11 ;
struct V_12 T_1 * V_13 = V_11 -> V_14 ;
unsigned int V_103 ;
V_103 = 0 ;
if ( V_7 -> V_104 & 0xffff0000 )
V_103 ++ ;
if ( V_7 -> V_104 & 0xff000000 )
V_103 ++ ;
V_8 -> V_35 |= ( 12 << V_105 ) |
( V_103 << V_106 ) ;
F_10 ( V_8 -> V_34 , L_28 ,
V_7 -> V_107 ) ;
F_10 ( V_8 -> V_34 , L_29 ,
V_7 -> V_108 ) ;
F_10 ( V_8 -> V_34 , L_30 ,
V_7 -> V_104 ) ;
F_10 ( V_8 -> V_34 , L_31 ,
V_7 -> V_109 ) ;
F_10 ( V_8 -> V_34 , L_32 ,
V_7 -> V_110 ) ;
F_10 ( V_8 -> V_34 , L_33 ,
V_7 -> V_111 ) ;
F_10 ( V_8 -> V_34 , L_34 ,
V_7 -> V_22 ) ;
F_10 ( V_8 -> V_34 , L_35 ,
V_7 -> V_21 ) ;
F_10 ( V_8 -> V_34 , L_36 ,
V_7 -> V_112 ) ;
F_10 ( V_8 -> V_34 , L_37 ,
V_7 -> V_50 . V_51 ) ;
F_10 ( V_8 -> V_34 , L_38 ,
V_7 -> V_50 . V_113 ) ;
F_10 ( V_8 -> V_34 , L_39 ,
V_7 -> V_50 . V_114 ) ;
F_10 ( V_8 -> V_34 , L_40 ,
V_7 -> V_50 . V_115 ) ;
F_10 ( V_8 -> V_34 , L_41 ,
V_7 -> V_50 . V_116 ) ;
F_10 ( V_8 -> V_34 , L_42 , V_2 -> V_117 ) ;
F_10 ( V_8 -> V_34 , L_43 , V_2 -> V_118 ) ;
F_10 ( V_8 -> V_34 , L_44 ,
V_2 -> V_119 ) ;
F_10 ( V_8 -> V_34 , L_45 ,
V_2 -> V_54 ) ;
F_10 ( V_8 -> V_34 , L_46 ,
V_2 -> V_55 ) ;
if ( V_2 -> V_54 == 512 ) {
V_8 -> V_23 = 0 ;
F_25 ( & V_13 -> V_41 [ V_8 -> V_41 ] . V_120 , V_121 ) ;
} else if ( V_2 -> V_54 == 2048 ) {
V_8 -> V_23 = 1 ;
F_26 ( & V_13 -> V_41 [ V_8 -> V_41 ] . V_120 , V_121 ) ;
if ( ( F_5 ( & V_13 -> V_41 [ V_8 -> V_41 ] . V_122 ) & V_123 ) ==
V_124 ) {
V_7 -> V_50 . V_118 = 512 ;
V_7 -> V_50 . V_116 = ( V_8 -> V_35 & V_125 ) ?
& V_126 :
& V_127 ;
V_7 -> V_128 = & V_129 ;
}
} else {
F_13 ( V_8 -> V_34 ,
L_47 ,
V_2 -> V_54 ) ;
return - 1 ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
T_6 * V_95 ,
int V_19 )
{
F_19 ( V_2 , V_95 , V_2 -> V_54 ) ;
F_19 ( V_2 , V_7 -> V_130 , V_2 -> V_55 ) ;
if ( F_23 ( V_2 , V_7 ) & V_102 )
V_2 -> V_57 . V_131 ++ ;
return 0 ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
const T_6 * V_95 )
{
F_15 ( V_2 , V_95 , V_2 -> V_54 ) ;
F_15 ( V_2 , V_7 -> V_130 , V_2 -> V_55 ) ;
}
static int F_29 ( struct V_9 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_11 ;
struct V_12 T_1 * V_13 = V_11 -> V_14 ;
struct V_15 * V_16 = V_11 -> V_17 ;
struct V_6 * V_7 = & V_8 -> V_7 ;
F_10 ( V_8 -> V_34 , L_48 , V_8 -> V_41 ) ;
V_8 -> V_2 . V_8 = V_7 ;
V_8 -> V_2 . V_132 = V_133 ;
V_8 -> V_35 = F_5 ( & V_13 -> V_35 ) & V_125 ;
V_7 -> V_134 = F_18 ;
V_7 -> V_135 = F_15 ;
V_7 -> V_136 = F_19 ;
V_7 -> V_137 = F_22 ;
V_7 -> V_138 = F_14 ;
V_7 -> V_139 = F_9 ;
V_7 -> V_140 = F_23 ;
V_7 -> V_141 = & V_142 ;
V_7 -> V_143 = & V_144 ;
V_7 -> V_145 = V_146 | V_147 ;
V_7 -> V_148 = V_149 ;
V_7 -> V_150 = & V_16 -> V_150 ;
V_7 -> V_8 = V_8 ;
V_7 -> V_50 . V_151 = F_27 ;
V_7 -> V_50 . V_152 = F_28 ;
if ( ( F_5 ( & V_13 -> V_41 [ V_8 -> V_41 ] . V_122 ) & V_123 ) ==
V_124 ) {
V_7 -> V_50 . V_51 = V_52 ;
V_7 -> V_50 . V_116 = ( V_8 -> V_35 & V_125 ) ?
& V_153 : & V_154 ;
V_7 -> V_50 . V_118 = 512 ;
V_7 -> V_50 . V_114 = 3 ;
} else {
V_7 -> V_50 . V_51 = V_155 ;
}
return 0 ;
}
static int F_30 ( struct V_9 * V_8 )
{
struct V_15 * V_16 = V_8 -> V_11 -> V_17 ;
F_31 ( & V_8 -> V_2 ) ;
F_32 ( V_8 -> V_2 . V_156 ) ;
if ( V_8 -> V_32 )
F_33 ( V_8 -> V_32 ) ;
V_16 -> V_157 [ V_8 -> V_41 ] = NULL ;
F_32 ( V_8 ) ;
return 0 ;
}
static int T_7 F_34 ( struct V_158 * V_159 )
{
struct V_12 T_1 * V_13 ;
struct V_9 * V_8 ;
struct V_160 V_161 ;
struct V_15 * V_16 ;
static const char * V_162 []
= { L_49 , L_50 , L_51 , NULL } ;
int V_163 ;
int V_41 ;
struct V_164 * V_34 ;
struct V_165 * V_166 = V_159 -> V_34 . V_167 ;
struct V_168 V_169 ;
V_169 . V_167 = V_159 -> V_34 . V_167 ;
if ( ! V_170 || ! V_170 -> V_14 )
return - V_171 ;
V_13 = V_170 -> V_14 ;
V_34 = V_170 -> V_34 ;
V_163 = F_35 ( V_166 , 0 , & V_161 ) ;
if ( V_163 ) {
F_13 ( V_34 , L_52 ) ;
return V_163 ;
}
for ( V_41 = 0 ; V_41 < V_172 ; V_41 ++ )
if ( ( F_5 ( & V_13 -> V_41 [ V_41 ] . V_122 ) & V_173 ) &&
( F_5 ( & V_13 -> V_41 [ V_41 ] . V_122 ) & V_174 ) == V_175 &&
( F_5 ( & V_13 -> V_41 [ V_41 ] . V_122 ) &
F_5 ( & V_13 -> V_41 [ V_41 ] . V_120 ) & V_176 )
== F_36 ( V_161 . V_177 ) )
break;
if ( V_41 >= V_172 ) {
F_13 ( V_34 , L_53 ) ;
return - V_171 ;
}
V_8 = F_37 ( sizeof( * V_8 ) , V_178 ) ;
if ( ! V_8 )
return - V_179 ;
F_38 ( & V_180 ) ;
if ( ! V_170 -> V_17 ) {
V_16 = F_37 ( sizeof( * V_16 ) , V_178 ) ;
if ( ! V_16 ) {
F_13 ( V_34 , L_54 ) ;
F_39 ( & V_180 ) ;
V_163 = - V_179 ;
goto V_181;
}
V_16 -> V_182 ++ ;
F_40 ( & V_16 -> V_150 . V_183 ) ;
F_41 ( & V_16 -> V_150 . V_184 ) ;
V_170 -> V_17 = V_16 ;
} else {
V_16 = V_170 -> V_17 ;
}
F_39 ( & V_180 ) ;
V_16 -> V_157 [ V_41 ] = V_8 ;
V_8 -> V_41 = V_41 ;
V_8 -> V_11 = V_170 ;
V_8 -> V_34 = V_34 ;
V_8 -> V_32 = F_42 ( V_161 . V_177 , F_43 ( & V_161 ) ) ;
if ( ! V_8 -> V_32 ) {
F_13 ( V_34 , L_55 ) ;
V_163 = - V_179 ;
goto V_181;
}
V_8 -> V_2 . V_156 = F_44 ( V_178 , L_56 , ( unsigned ) V_161 . V_177 ) ;
if ( ! V_8 -> V_2 . V_156 ) {
V_163 = - V_179 ;
goto V_181;
}
V_163 = F_29 ( V_8 ) ;
if ( V_163 )
goto V_181;
V_163 = F_45 ( & V_8 -> V_2 , 1 , NULL ) ;
if ( V_163 )
goto V_181;
V_163 = F_24 ( & V_8 -> V_2 ) ;
if ( V_163 )
goto V_181;
V_163 = F_46 ( & V_8 -> V_2 ) ;
if ( V_163 )
goto V_181;
F_47 ( & V_8 -> V_2 , V_162 , & V_169 ,
NULL , 0 ) ;
F_48 ( V_185 L_57 ,
( unsigned long long ) V_161 . V_177 , V_8 -> V_41 ) ;
return 0 ;
V_181:
F_30 ( V_8 ) ;
return V_163 ;
}
static int F_49 ( struct V_158 * V_159 )
{
int V_100 ;
struct V_15 * V_16 = V_170 -> V_17 ;
for ( V_100 = 0 ; V_100 < V_172 ; V_100 ++ )
if ( V_16 -> V_157 [ V_100 ] )
F_30 ( V_16 -> V_157 [ V_100 ] ) ;
F_38 ( & V_180 ) ;
V_16 -> V_182 -- ;
if ( ! V_16 -> V_182 ) {
V_170 -> V_17 = NULL ;
F_32 ( V_16 ) ;
}
F_39 ( & V_180 ) ;
return 0 ;
}
static int T_8 F_50 ( void )
{
return F_51 ( & V_186 ) ;
}
static void T_9 F_52 ( void )
{
F_53 ( & V_186 ) ;
}
