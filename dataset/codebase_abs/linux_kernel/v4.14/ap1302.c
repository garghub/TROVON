static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , void * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
int V_10 ;
if ( V_4 == V_11 )
V_10 = F_4 ( V_7 -> V_12 , V_3 , V_5 ) ;
else if ( V_4 == V_13 )
V_10 = F_4 ( V_7 -> V_14 , V_3 , V_5 ) ;
else
V_10 = - V_15 ;
if ( V_10 ) {
F_5 ( & V_9 -> V_7 , L_1 , V_3 ) ;
return V_10 ;
}
if ( V_4 == V_11 )
F_5 ( & V_9 -> V_7 , L_2 ,
V_3 , * ( T_1 * ) V_5 ) ;
else
F_5 ( & V_9 -> V_7 , L_3 ,
V_3 , * ( V_16 * ) V_5 ) ;
return V_10 ;
}
static int F_6 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , V_16 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
int V_10 ;
if ( V_4 == V_11 )
V_10 = F_7 ( V_7 -> V_12 , V_3 , V_5 ) ;
else if ( V_4 == V_13 )
V_10 = F_7 ( V_7 -> V_14 , V_3 , V_5 ) ;
else
V_10 = - V_15 ;
if ( V_10 ) {
F_5 ( & V_9 -> V_7 , L_4 , V_3 ) ;
return V_10 ;
}
if ( V_4 == V_11 )
F_5 ( & V_9 -> V_7 , L_5 ,
V_3 , ( T_1 ) V_5 ) ;
else
F_5 ( & V_9 -> V_7 , L_6 ,
V_3 , ( V_16 ) V_5 ) ;
return V_10 ;
}
static T_1
F_8 ( enum V_17 V_18 , T_1 V_19 )
{
T_1 V_20 ;
if ( V_18 == V_21 ) {
if ( V_19 == V_22 )
return 0 ;
if ( V_19 > V_22 )
V_19 -= 2 ;
}
if ( V_18 == V_23 )
V_20 = V_24 + V_19 ;
else if ( V_18 == V_25 )
V_20 = V_26 + V_19 ;
else
V_20 = V_27 + V_19 ;
return V_20 ;
}
static int F_9 ( struct V_1 * V_2 ,
enum V_17 V_18 , T_1 V_19 , T_1 V_4 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_20 = F_8 ( V_18 , V_19 ) ;
if ( V_20 == 0 )
return - V_15 ;
return F_1 ( V_2 , V_20 , V_4 ,
( ( V_28 * ) & V_7 -> V_29 [ V_18 ] ) + V_19 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
enum V_17 V_18 , T_1 V_19 , T_1 V_4 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_20 = F_8 ( V_18 , V_19 ) ;
if ( V_20 == 0 )
return - V_15 ;
return F_6 ( V_2 , V_20 , V_4 ,
* ( V_16 * ) ( ( ( V_28 * ) & V_7 -> V_29 [ V_18 ] ) + V_19 ) ) ;
}
static int F_11 ( struct V_1 * V_2 ,
enum V_17 V_18 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_30 ;
F_5 ( & V_9 -> V_7 , L_7 , V_18 ) ;
for ( V_30 = 0 ; V_30 < F_12 ( V_31 ) ; V_30 ++ ) {
struct V_32 * V_33 = & V_31 [ V_30 ] ;
V_28 * V_34 = ( V_28 * ) & V_7 -> V_29 [ V_18 ] + V_33 -> V_19 ;
if ( V_18 == V_21 &&
V_33 -> V_19 == V_22 )
continue;
F_9 ( V_2 , V_18 , V_33 -> V_19 , V_33 -> V_4 ) ;
if ( V_33 -> V_4 == V_11 )
F_5 ( & V_9 -> V_7 , L_8 ,
V_33 -> V_35 , * ( T_1 * ) V_34 , * ( T_1 * ) V_34 ) ;
else
F_5 ( & V_9 -> V_7 , L_9 ,
V_33 -> V_35 , * ( V_16 * ) V_34 , * ( V_16 * ) V_34 ) ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_10 ;
V_10 = F_14 ( & V_7 -> V_36 , L_10 , & V_9 -> V_7 ) ;
if ( V_10 )
F_15 ( & V_9 -> V_7 ,
L_11 , V_10 ) ;
return V_10 ;
}
static int F_16 ( struct V_1 * V_2 ,
T_1 * V_37 , const V_28 * V_38 , V_16 V_4 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_10 ;
V_16 V_39 ;
V_16 V_40 ;
for ( V_39 = 0 ; V_39 < V_4 ; V_39 += V_40 ) {
if ( V_4 - V_39 < V_41 - * V_37 )
V_40 = V_4 - V_39 ;
else
V_40 = V_41 - * V_37 ;
V_10 = F_17 ( V_7 -> V_12 ,
* V_37 + V_42 ,
V_38 + V_39 , V_40 ) ;
if ( V_10 )
return V_10 ;
* V_37 += V_40 ;
if ( * V_37 >= V_41 )
* V_37 = 0 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
const struct V_43 * V_36 ;
const V_28 * V_44 ;
T_1 V_45 = 0 ;
T_1 V_37 = 0 ;
int V_10 ;
F_19 ( & V_9 -> V_7 , L_12 ) ;
if ( ! V_7 -> V_36 ) {
F_15 ( & V_9 -> V_7 , L_13 ) ;
return - V_15 ;
}
V_36 = ( const struct V_43 * ) V_7 -> V_36 -> V_46 ;
if ( V_7 -> V_36 -> V_47 != ( sizeof( * V_36 ) + V_36 -> V_48 ) ) {
F_15 ( & V_9 -> V_7 , L_14 ) ;
return - V_15 ;
}
V_44 = ( V_28 * ) & V_36 [ 1 ] ;
V_10 = F_6 ( V_2 , V_49 , V_11 , 0xFFFF ) ;
if ( V_10 )
return V_10 ;
V_10 = F_16 ( V_2 , & V_37 , V_44 , V_36 -> V_50 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_6 ( V_2 , V_51 ,
V_11 , 0x0002 ) ;
if ( V_10 )
return V_10 ;
F_20 ( 20 ) ;
V_10 = F_16 ( V_2 , & V_37 , V_44 + V_36 -> V_50 ,
V_36 -> V_48 - V_36 -> V_50 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_1 ( V_2 , V_49 , V_11 , & V_45 ) ;
if ( V_10 )
return V_10 ;
if ( V_45 != V_36 -> V_52 ) {
F_15 ( & V_9 -> V_7 ,
L_15 ,
V_36 -> V_52 , V_45 ) ;
return - V_53 ;
}
V_10 = F_6 ( V_2 , V_51 ,
V_11 , 0xFFFF ) ;
if ( V_10 )
return V_10 ;
F_19 ( & V_9 -> V_7 , L_16 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , int V_54 , int V_55 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
int V_10 , V_30 ;
T_1 V_56 ;
F_19 ( & V_9 -> V_7 , L_17 ) ;
V_10 = V_7 -> V_57 -> V_58 ( V_2 , V_54 ) ;
if ( V_10 ) {
F_15 ( & V_9 -> V_7 ,
L_18 , V_54 , V_10 ) ;
return V_10 ;
}
V_7 -> V_59 = V_54 ;
if ( ! V_54 || ! V_55 )
return 0 ;
V_10 = F_18 ( V_2 ) ;
if ( V_10 ) {
F_15 ( & V_9 -> V_7 ,
L_19 , V_10 ) ;
return V_10 ;
}
V_10 = F_1 ( V_2 , V_60 , V_11 , & V_56 ) ;
if ( V_10 )
return V_10 ;
for ( V_30 = 0 ; V_30 < F_12 ( V_61 ) ; V_30 ++ ) {
V_10 = F_6 ( V_2 , V_56 + V_30 * 2 ,
V_11 , V_61 [ V_30 ] ) ;
if ( V_10 )
return V_10 ;
}
return V_10 ;
}
static int F_22 ( struct V_1 * V_2 , int V_54 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_10 ;
F_23 ( & V_7 -> V_62 ) ;
V_10 = F_21 ( V_2 , V_54 , 1 ) ;
V_7 -> V_63 = 0 ;
F_24 ( & V_7 -> V_62 ) ;
return V_10 ;
}
static int F_25 ( struct V_1 * V_2 , void * V_64 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_65 * V_66 ;
T_1 V_45 = 0 ;
int V_10 ;
F_19 ( & V_9 -> V_7 , L_20 ) ;
if ( V_64 == NULL )
return - V_67 ;
V_7 -> V_57 = V_64 ;
F_23 ( & V_7 -> V_62 ) ;
if ( V_7 -> V_57 -> V_68 ) {
V_10 = V_7 -> V_57 -> V_68 ( V_9 ) ;
if ( V_10 )
goto V_69;
}
V_10 = F_21 ( V_2 , 1 , 0 ) ;
if ( V_10 )
goto V_69;
V_10 = F_1 ( V_2 , V_70 , V_11 , & V_45 ) ;
if ( V_10 || ( V_45 != V_71 ) ) {
F_15 ( & V_9 -> V_7 ,
L_21 ,
V_10 , V_45 ) ;
goto V_72;
}
F_19 ( & V_9 -> V_7 , L_22 , V_45 ) ;
V_10 = F_1 ( V_2 , V_73 , V_11 , & V_45 ) ;
if ( V_10 )
goto V_72;
F_19 ( & V_9 -> V_7 , L_23 , V_45 ) ;
V_10 = V_7 -> V_57 -> V_74 ( V_2 , 1 ) ;
if ( V_10 )
goto V_72;
V_66 = F_26 ( V_2 ) ;
if ( ! V_66 )
goto V_72;
V_7 -> V_75 = V_66 -> V_75 ;
V_10 = F_21 ( V_2 , 0 , 0 ) ;
if ( V_10 )
goto V_69;
F_24 ( & V_7 -> V_62 ) ;
return V_10 ;
V_72:
F_21 ( V_2 , 0 , 0 ) ;
V_69:
F_24 ( & V_7 -> V_62 ) ;
F_15 ( & V_9 -> V_7 , L_24 ) ;
return V_10 ;
}
static enum V_17 F_27 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return V_7 -> V_76 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_77 * V_78 ,
struct V_79 * V_80 )
{
if ( V_80 -> V_81 )
return - V_15 ;
V_80 -> V_80 = V_82 ;
return 0 ;
}
static int F_29 ( struct V_83 * V_84 ,
struct V_85 * V_86 )
{
T_2 V_87 , V_88 , V_89 , V_90 ;
T_2 V_91 = V_86 -> V_92 ;
T_2 V_93 = V_86 -> V_94 ;
T_2 V_95 = V_96 ;
T_2 V_30 , V_97 = - 1 ;
if ( V_91 == 0 || V_93 == 0 )
return - 1 ;
for ( V_30 = 0 ; V_30 < V_84 -> V_98 ; V_30 ++ ) {
V_87 = V_84 -> V_99 [ V_30 ] . V_92 ;
V_88 = V_84 -> V_99 [ V_30 ] . V_94 ;
if ( V_87 < V_91 || V_88 < V_93 )
continue;
V_89 = abs ( V_87 * V_93 - V_91 * V_88 ) * 8192 / V_91 / V_88 ;
if ( V_89 > 8192 * V_100 / 100 )
continue;
V_90 = ( V_87 * V_93 + V_91 * V_88 ) * 8192 / V_91 / V_93 ;
if ( V_90 < V_95 ) {
V_95 = V_90 ;
V_97 = V_30 ;
}
}
return V_97 ;
}
static T_2 F_30 ( struct V_1 * V_2 ,
enum V_17 V_18 ,
struct V_85 * V_86 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_101 * V_99 ;
T_2 V_98 , V_97 = - 1 ;
V_99 = V_7 -> V_102 [ V_18 ] . V_99 ;
V_98 = V_7 -> V_102 [ V_18 ] . V_98 ;
if ( ( V_86 -> V_92 <= V_99 [ V_98 - 1 ] . V_92 ) &&
( V_86 -> V_94 <= V_99 [ V_98 - 1 ] . V_94 ) )
V_97 = F_29 ( & V_7 -> V_102 [ V_18 ] , V_86 ) ;
if ( V_97 == - 1 )
V_97 = V_98 - 1 ;
V_86 -> V_92 = V_99 [ V_97 ] . V_92 ;
V_86 -> V_94 = V_99 [ V_97 ] . V_94 ;
V_86 -> V_80 = V_82 ;
return V_97 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_77 * V_78 ,
struct V_103 * V_104 )
{
struct V_85 * V_86 = & V_104 -> V_104 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
enum V_17 V_18 ;
struct V_101 * V_99 ;
T_2 V_105 ;
if ( V_104 -> V_106 )
return - V_15 ;
F_23 ( & V_7 -> V_62 ) ;
V_18 = F_27 ( V_2 ) ;
V_99 = V_7 -> V_102 [ V_18 ] . V_99 ;
V_105 = V_7 -> V_102 [ V_18 ] . V_105 ;
V_86 -> V_80 = V_82 ;
V_86 -> V_92 = V_99 [ V_105 ] . V_92 ;
V_86 -> V_94 = V_99 [ V_105 ] . V_94 ;
F_24 ( & V_7 -> V_62 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_77 * V_78 ,
struct V_103 * V_104 )
{
struct V_85 * V_86 = & V_104 -> V_104 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_107 * V_108 =
(struct V_107 * ) V_86 -> V_109 ;
enum V_17 V_18 , V_110 ;
if ( V_104 -> V_106 )
return - V_15 ;
if ( ! V_86 )
return - V_15 ;
F_23 ( & V_7 -> V_62 ) ;
if ( V_104 -> V_111 == V_112 ) {
V_18 = F_27 ( V_2 ) ;
F_30 ( V_2 , V_18 , V_86 ) ;
V_78 -> V_113 = * V_86 ;
F_24 ( & V_7 -> V_62 ) ;
return 0 ;
}
V_18 = V_114 [ V_108 -> V_115 ] ;
F_5 ( & V_9 -> V_7 , L_25 ,
V_108 -> V_115 , V_18 ) ;
V_7 -> V_102 [ V_18 ] . V_105 =
F_30 ( V_2 , V_18 , V_86 ) ;
V_7 -> V_29 [ V_18 ] . V_92 = V_86 -> V_92 ;
V_7 -> V_29 [ V_18 ] . V_94 = V_86 -> V_94 ;
F_10 ( V_2 , V_18 , V_116 , V_11 ) ;
F_10 ( V_2 , V_18 , V_117 , V_11 ) ;
F_9 ( V_2 , V_18 , V_118 , V_11 ) ;
V_7 -> V_29 [ V_18 ] . V_119 &= ~ V_120 ;
V_7 -> V_29 [ V_18 ] . V_119 |= V_121 ;
F_10 ( V_2 , V_18 , V_118 , V_11 ) ;
V_110 = F_27 ( V_2 ) ;
if ( V_18 == V_110 ) {
F_9 ( V_2 , V_18 ,
V_122 , V_11 ) ;
V_7 -> V_29 [ V_18 ] . V_123 &= ~ V_124 ;
V_7 -> V_29 [ V_18 ] . V_123 |=
( V_18 << V_125 ) ;
V_7 -> V_29 [ V_18 ] . V_123 &= ~ V_126 ;
V_7 -> V_29 [ V_18 ] . V_123 |=
( V_18 << V_127 ) ;
V_7 -> V_29 [ V_18 ] . V_123 &= ~ V_128 ;
V_7 -> V_29 [ V_18 ] . V_123 |=
( 0x12 << V_129 ) ;
F_10 ( V_2 , V_18 ,
V_122 , V_11 ) ;
F_9 ( V_2 , V_18 ,
V_130 , V_11 ) ;
V_7 -> V_29 [ V_18 ] . V_131 = V_132 ;
F_10 ( V_2 , V_18 ,
V_130 , V_11 ) ;
} else {
F_9 ( V_2 , V_18 ,
V_133 , V_11 ) ;
V_7 -> V_29 [ V_18 ] . V_134 &= ~ V_124 ;
V_7 -> V_29 [ V_18 ] . V_134 |=
( V_18 << V_125 ) ;
F_10 ( V_2 , V_18 ,
V_133 , V_11 ) ;
if ( V_108 -> V_135 ) {
F_9 ( V_2 , V_110 ,
V_118 , V_11 ) ;
V_7 -> V_29 [ V_18 ] . V_119 |=
( V_136 [ V_110 ] [ V_18 ]
<< V_137 ) ;
F_10 ( V_2 , V_110 ,
V_118 , V_11 ) ;
}
}
V_108 -> V_138 = V_18 ;
F_24 ( & V_7 -> V_62 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_139 * V_140 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
enum V_17 V_18 ;
struct V_101 * V_99 ;
V_16 V_105 ;
F_23 ( & V_7 -> V_62 ) ;
V_18 = F_27 ( V_2 ) ;
V_99 = V_7 -> V_102 [ V_18 ] . V_99 ;
V_105 = V_7 -> V_102 [ V_18 ] . V_105 ;
V_140 -> V_140 . V_141 = V_99 [ V_105 ] . V_142 ;
V_140 -> V_140 . V_143 = 1 ;
F_24 ( & V_7 -> V_62 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_77 * V_78 ,
struct V_144 * V_145 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
enum V_17 V_18 ;
struct V_101 * V_99 ;
int V_81 = V_145 -> V_81 ;
F_23 ( & V_7 -> V_62 ) ;
V_18 = F_27 ( V_2 ) ;
if ( V_81 >= V_7 -> V_102 [ V_18 ] . V_98 ) {
F_24 ( & V_7 -> V_62 ) ;
return - V_15 ;
}
V_99 = V_7 -> V_102 [ V_18 ] . V_99 ;
V_145 -> V_146 = V_99 [ V_81 ] . V_92 ;
V_145 -> V_147 = V_99 [ V_81 ] . V_94 ;
V_145 -> V_148 = V_99 [ V_81 ] . V_92 ;
V_145 -> V_149 = V_99 [ V_81 ] . V_94 ;
F_24 ( & V_7 -> V_62 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , V_16 * V_150 )
{
* V_150 = 0 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , int V_135 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
enum V_17 V_18 ;
V_16 V_45 ;
int V_10 ;
F_23 ( & V_7 -> V_62 ) ;
V_18 = F_27 ( V_2 ) ;
F_5 ( & V_9 -> V_7 , L_26 ,
V_18 , V_135 ) ;
F_1 ( V_2 , V_151 ,
V_11 , & V_45 ) ;
V_45 &= ~ V_152 ;
V_45 |= ( V_18 << V_153 ) ;
F_6 ( V_2 , V_151 ,
V_11 , V_45 ) ;
F_1 ( V_2 , V_154 ,
V_11 , & V_45 ) ;
V_45 &= ~ V_155 ;
V_45 |= ( V_156 << V_157 ) ;
F_6 ( V_2 , V_154 ,
V_11 , V_45 ) ;
if ( V_135 ) {
F_19 ( & V_9 -> V_7 , L_27 , V_18 ) ;
F_11 ( V_2 , V_18 ) ;
if ( ! V_7 -> V_63 ) {
V_45 = V_158 ;
V_7 -> V_63 = 1 ;
} else {
V_45 = V_159 ;
}
} else {
F_19 ( & V_9 -> V_7 , L_28 , V_18 ) ;
V_45 = V_159 ;
}
V_10 = F_6 ( V_2 , V_160 , V_11 , V_45 ) ;
if ( V_10 )
F_15 ( & V_9 -> V_7 ,
L_29 , V_135 ) ;
F_24 ( & V_7 -> V_62 ) ;
return V_10 ;
}
static int F_37 ( struct V_1 * V_2 , T_2 V_5 )
{
V_5 -= V_161 ;
return F_6 ( V_2 , V_162 , V_11 ,
V_163 [ V_5 ] ) ;
}
static int F_38 ( struct V_1 * V_2 , T_2 V_5 )
{
int V_10 = 0 ;
T_1 V_45 ;
V_10 = F_1 ( V_2 , V_164 , V_11 , & V_45 ) ;
if ( V_10 )
return V_10 ;
V_45 &= ~ V_165 ;
V_45 |= V_166 [ V_5 ] << V_167 ;
if ( V_5 == V_168 )
V_45 |= V_169 ;
else
V_45 &= ~ V_169 ;
V_10 = F_6 ( V_2 , V_164 , V_11 , V_45 ) ;
return V_10 ;
}
static int F_39 ( struct V_1 * V_2 , T_2 V_5 )
{
F_6 ( V_2 , V_170 , V_11 ,
V_5 * 4 + 0x100 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , T_2 V_5 )
{
F_6 ( V_2 , V_171 , V_11 ,
V_172 [ V_5 ] ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , T_2 V_5 )
{
F_6 ( V_2 , V_173 , V_11 ,
V_174 [ V_5 ] ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , T_2 V_5 )
{
F_6 ( V_2 , V_175 , V_11 ,
V_176 [ V_5 ] ) ;
return 0 ;
}
static int F_43 ( struct V_177 * V_178 )
{
struct V_6 * V_7 = F_44 (
V_178 -> V_179 , struct V_6 , V_180 ) ;
switch ( V_178 -> V_181 ) {
case V_182 :
V_7 -> V_76 = V_183 [ V_178 -> V_5 ] ;
break;
case V_184 :
F_37 ( & V_7 -> V_2 , V_178 -> V_5 ) ;
break;
case V_185 :
F_38 ( & V_7 -> V_2 , V_178 -> V_5 ) ;
break;
case V_186 :
F_39 ( & V_7 -> V_2 , V_178 -> V_5 ) ;
break;
case V_187 :
F_40 ( & V_7 -> V_2 , V_178 -> V_5 ) ;
break;
case V_188 :
F_41 ( & V_7 -> V_2 , V_178 -> V_5 ) ;
break;
case V_189 :
F_42 ( & V_7 -> V_2 , V_178 -> V_5 ) ;
break;
default:
return - V_15 ;
}
return 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_190 * V_3 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_10 ;
V_16 V_45 ;
if ( V_3 -> V_47 != V_11 &&
V_3 -> V_47 != V_13 )
return - V_15 ;
F_23 ( & V_7 -> V_62 ) ;
if ( V_7 -> V_59 )
V_10 = F_1 ( V_2 , V_3 -> V_3 , V_3 -> V_47 , & V_45 ) ;
else
V_10 = - V_191 ;
F_24 ( & V_7 -> V_62 ) ;
if ( V_10 )
return V_10 ;
V_3 -> V_5 = V_45 ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
const struct V_190 * V_3 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_10 ;
if ( V_3 -> V_47 != V_11 &&
V_3 -> V_47 != V_13 )
return - V_15 ;
F_23 ( & V_7 -> V_62 ) ;
if ( V_7 -> V_59 )
V_10 = F_6 ( V_2 , V_3 -> V_3 , V_3 -> V_47 , V_3 -> V_5 ) ;
else
V_10 = - V_191 ;
F_24 ( & V_7 -> V_62 ) ;
return V_10 ;
}
static long F_47 ( struct V_1 * V_2 , unsigned int V_192 , void * V_193 )
{
long V_10 = 0 ;
switch ( V_192 ) {
case V_194 :
V_10 = F_45 ( V_2 , V_193 ) ;
break;
case V_195 :
V_10 = F_46 ( V_2 , V_193 ) ;
break;
default:
V_10 = - V_15 ;
}
return V_10 ;
}
static int F_48 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_49 ( V_9 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_57 -> V_196 )
V_7 -> V_57 -> V_196 () ;
F_50 ( V_7 -> V_36 ) ;
F_51 ( & V_7 -> V_2 . V_197 ) ;
V_7 -> V_57 -> V_74 ( V_2 , 0 ) ;
F_52 ( V_2 ) ;
return 0 ;
}
static int F_53 ( struct V_8 * V_9 ,
const struct V_198 * V_181 )
{
struct V_6 * V_7 ;
int V_10 ;
unsigned int V_30 ;
F_19 ( & V_9 -> V_7 , L_30 ) ;
V_7 = F_54 ( & V_9 -> V_7 , sizeof( * V_7 ) , V_199 ) ;
if ( ! V_7 ) {
F_15 ( & V_9 -> V_7 , L_31 , V_200 ) ;
return - V_201 ;
}
F_55 ( & V_7 -> V_62 ) ;
F_56 ( & ( V_7 -> V_2 ) , V_9 , & V_202 ) ;
V_10 = F_13 ( & ( V_7 -> V_2 ) ) ;
if ( V_10 ) {
F_15 ( & V_9 -> V_7 , L_32 ) ;
goto V_203;
}
V_7 -> V_12 = F_57 ( V_9 , & V_204 ) ;
if ( F_58 ( V_7 -> V_12 ) ) {
V_10 = F_59 ( V_7 -> V_12 ) ;
F_15 ( & V_9 -> V_7 ,
L_33 , V_10 ) ;
return V_10 ;
}
V_7 -> V_14 = F_57 ( V_9 , & V_205 ) ;
if ( F_58 ( V_7 -> V_14 ) ) {
V_10 = F_59 ( V_7 -> V_14 ) ;
F_15 ( & V_9 -> V_7 ,
L_34 , V_10 ) ;
return V_10 ;
}
if ( V_9 -> V_7 . V_57 ) {
V_10 = F_25 ( & V_7 -> V_2 , V_9 -> V_7 . V_57 ) ;
if ( V_10 )
goto V_203;
}
V_7 -> V_2 . V_206 |= V_207 ;
V_7 -> V_106 . V_206 = V_208 ;
V_7 -> V_2 . V_197 . V_209 = V_210 ;
V_7 -> V_102 [ V_23 ] . V_98 = F_12 ( V_211 ) ;
V_7 -> V_102 [ V_23 ] . V_99 = V_211 ;
V_7 -> V_102 [ V_21 ] . V_98 =
F_12 ( V_212 ) ;
V_7 -> V_102 [ V_21 ] . V_99 = V_212 ;
V_7 -> V_102 [ V_25 ] . V_98 = F_12 ( V_213 ) ;
V_7 -> V_102 [ V_25 ] . V_99 = V_213 ;
V_10 = F_60 ( & V_7 -> V_180 , F_12 ( V_214 ) ) ;
if ( V_10 ) {
F_48 ( V_9 ) ;
return V_10 ;
}
for ( V_30 = 0 ; V_30 < F_12 ( V_214 ) ; V_30 ++ )
F_61 ( & V_7 -> V_180 , & V_214 [ V_30 ] , NULL ) ;
if ( V_7 -> V_180 . error ) {
F_48 ( V_9 ) ;
return V_7 -> V_180 . error ;
}
V_7 -> V_180 . V_215 = & V_7 -> V_62 ;
V_7 -> V_2 . V_180 = & V_7 -> V_180 ;
F_62 ( & V_7 -> V_180 ) ;
V_7 -> V_216 = F_63 ( & V_7 -> V_180 , V_182 ) ;
F_64 ( V_7 -> V_216 , V_217 ) ;
V_10 = F_65 ( & V_7 -> V_2 . V_197 , 1 , & V_7 -> V_106 ) ;
if ( V_10 )
F_48 ( V_9 ) ;
return V_10 ;
V_203:
F_52 ( & V_7 -> V_2 ) ;
return V_10 ;
}
