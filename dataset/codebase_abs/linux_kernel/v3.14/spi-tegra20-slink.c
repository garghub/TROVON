static inline T_1 F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
T_1 V_5 , unsigned long V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
if ( V_3 != V_6 )
F_2 ( V_2 -> V_4 + V_7 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_1 V_8 ;
F_1 ( V_2 , V_9 ) ;
V_8 = V_10 | V_11 ;
F_3 ( V_2 , V_8 , V_9 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
switch ( V_2 -> V_14 ) {
case 0 :
return V_15 ;
case 1 :
return V_16 ;
case 2 :
return V_17 ;
case 4 :
return V_18 ;
default:
return 0 ;
}
}
static unsigned F_7 (
struct V_19 * V_20 , struct V_1 * V_2 ,
struct V_12 * V_13 )
{
unsigned V_21 = V_13 -> V_22 - V_2 -> V_23 ;
unsigned V_24 ;
unsigned V_25 ;
unsigned V_26 ;
unsigned V_27 ;
V_25 = V_13 -> V_25 ;
V_2 -> V_14 = F_8 ( V_25 , 8 ) ;
if ( V_25 == 8 || V_25 == 16 ) {
V_2 -> V_28 = 1 ;
V_2 -> V_29 = 32 / V_25 ;
} else {
V_2 -> V_28 = 0 ;
V_2 -> V_29 = 1 ;
}
V_2 -> V_30 = F_6 ( V_2 , V_13 ) ;
if ( V_2 -> V_28 ) {
V_26 = F_9 ( V_21 , V_2 -> V_31 ) ;
V_2 -> V_32 = V_26 / V_2 -> V_14 ;
V_27 = V_26 / 4 ;
} else {
V_24 = ( V_21 - 1 ) / V_2 -> V_14 + 1 ;
V_24 = F_9 ( V_24 , V_2 -> V_31 / 4 ) ;
V_2 -> V_32 = V_24 ;
V_27 = V_24 ;
}
return V_27 ;
}
static unsigned F_10 (
struct V_1 * V_2 , struct V_12 * V_13 )
{
unsigned V_33 ;
unsigned V_34 ;
T_1 V_35 ;
unsigned V_36 ;
unsigned V_37 , V_38 ;
unsigned int V_39 ;
unsigned V_40 ;
T_2 * V_41 = ( T_2 * ) V_13 -> V_41 + V_2 -> V_42 ;
V_35 = F_1 ( V_2 , V_43 ) ;
V_34 = F_11 ( V_35 ) ;
if ( V_2 -> V_28 ) {
V_40 = V_34 * V_2 -> V_29 ;
V_39 = F_9 ( V_40 , V_2 -> V_32 ) ;
V_33 = V_39 * V_2 -> V_14 ;
V_36 = F_8 ( V_33 , 4 ) ;
for ( V_38 = 0 ; V_38 < V_36 ; V_38 ++ ) {
T_1 V_44 = 0 ;
for ( V_37 = 0 ; ( V_37 < 4 ) && V_33 ; V_37 ++ , V_33 -- )
V_44 |= ( T_1 ) ( * V_41 ++ ) << ( V_37 * 8 ) ;
F_3 ( V_2 , V_44 , V_6 ) ;
}
} else {
V_36 = F_9 ( V_2 -> V_32 , V_34 ) ;
V_39 = V_36 ;
V_33 = V_39 * V_2 -> V_14 ;
for ( V_38 = 0 ; V_38 < V_36 ; V_38 ++ ) {
T_1 V_44 = 0 ;
for ( V_37 = 0 ; V_33 && ( V_37 < V_2 -> V_14 ) ;
V_37 ++ , V_33 -- )
V_44 |= ( T_1 ) ( * V_41 ++ ) << ( V_37 * 8 ) ;
F_3 ( V_2 , V_44 , V_6 ) ;
}
}
V_2 -> V_42 += V_39 * V_2 -> V_14 ;
return V_39 ;
}
static unsigned int F_12 (
struct V_1 * V_2 , struct V_12 * V_13 )
{
unsigned V_45 ;
T_1 V_35 ;
unsigned V_37 , V_38 ;
unsigned int V_46 = 0 ;
unsigned V_22 ;
T_2 * V_47 = ( T_2 * ) V_13 -> V_47 + V_2 -> V_48 ;
V_35 = F_1 ( V_2 , V_43 ) ;
V_45 = F_13 ( V_35 ) ;
if ( V_2 -> V_28 ) {
V_22 = V_2 -> V_32 * V_2 -> V_14 ;
for ( V_38 = 0 ; V_38 < V_45 ; V_38 ++ ) {
T_1 V_44 = F_1 ( V_2 , V_49 ) ;
for ( V_37 = 0 ; V_22 && ( V_37 < 4 ) ; V_37 ++ , V_22 -- )
* V_47 ++ = ( V_44 >> V_37 * 8 ) & 0xFF ;
}
V_2 -> V_48 += V_2 -> V_32 * V_2 -> V_14 ;
V_46 += V_2 -> V_32 ;
} else {
for ( V_38 = 0 ; V_38 < V_45 ; V_38 ++ ) {
T_1 V_44 = F_1 ( V_2 , V_49 ) ;
for ( V_37 = 0 ; ( V_37 < V_2 -> V_14 ) ; V_37 ++ )
* V_47 ++ = ( V_44 >> ( V_37 * 8 ) ) & 0xFF ;
}
V_2 -> V_48 += V_45 * V_2 -> V_14 ;
V_46 += V_45 ;
}
return V_46 ;
}
static void F_14 (
struct V_1 * V_2 , struct V_12 * V_13 )
{
F_15 ( V_2 -> V_50 , V_2 -> V_51 ,
V_2 -> V_52 , V_53 ) ;
if ( V_2 -> V_28 ) {
unsigned V_22 = V_2 -> V_32 * V_2 -> V_14 ;
memcpy ( V_2 -> V_54 , V_13 -> V_41 + V_2 -> V_23 , V_22 ) ;
} else {
unsigned int V_37 ;
unsigned int V_38 ;
T_2 * V_41 = ( T_2 * ) V_13 -> V_41 + V_2 -> V_42 ;
unsigned V_55 = V_2 -> V_32 * V_2 -> V_14 ;
for ( V_38 = 0 ; V_38 < V_2 -> V_32 ; V_38 ++ ) {
T_1 V_44 = 0 ;
for ( V_37 = 0 ; V_55 && ( V_37 < V_2 -> V_14 ) ;
V_37 ++ , V_55 -- )
V_44 |= ( T_1 ) ( * V_41 ++ ) << ( V_37 * 8 ) ;
V_2 -> V_54 [ V_38 ] = V_44 ;
}
}
V_2 -> V_42 += V_2 -> V_32 * V_2 -> V_14 ;
F_16 ( V_2 -> V_50 , V_2 -> V_51 ,
V_2 -> V_52 , V_53 ) ;
}
static void F_17 (
struct V_1 * V_2 , struct V_12 * V_13 )
{
unsigned V_22 ;
F_15 ( V_2 -> V_50 , V_2 -> V_56 ,
V_2 -> V_52 , V_57 ) ;
if ( V_2 -> V_28 ) {
V_22 = V_2 -> V_32 * V_2 -> V_14 ;
memcpy ( V_13 -> V_47 + V_2 -> V_48 , V_2 -> V_58 , V_22 ) ;
} else {
unsigned int V_37 ;
unsigned int V_38 ;
unsigned char * V_47 = V_13 -> V_47 + V_2 -> V_48 ;
T_1 V_59 = ( ( T_1 ) 1 << V_13 -> V_25 ) - 1 ;
for ( V_38 = 0 ; V_38 < V_2 -> V_32 ; V_38 ++ ) {
T_1 V_44 = V_2 -> V_58 [ V_38 ] & V_59 ;
for ( V_37 = 0 ; ( V_37 < V_2 -> V_14 ) ; V_37 ++ )
* V_47 ++ = ( V_44 >> ( V_37 * 8 ) ) & 0xFF ;
}
}
V_2 -> V_48 += V_2 -> V_32 * V_2 -> V_14 ;
F_16 ( V_2 -> V_50 , V_2 -> V_56 ,
V_2 -> V_52 , V_57 ) ;
}
static void F_18 ( void * args )
{
struct V_60 * V_61 = args ;
F_19 ( V_61 ) ;
}
static int F_20 ( struct V_1 * V_2 , int V_22 )
{
F_21 ( & V_2 -> V_62 ) ;
V_2 -> V_63 = F_22 ( V_2 -> V_64 ,
V_2 -> V_51 , V_22 , V_65 ,
V_66 | V_67 ) ;
if ( ! V_2 -> V_63 ) {
F_23 ( V_2 -> V_50 , L_1 ) ;
return - V_68 ;
}
V_2 -> V_63 -> V_69 = F_18 ;
V_2 -> V_63 -> V_70 = & V_2 -> V_62 ;
F_24 ( V_2 -> V_63 ) ;
F_25 ( V_2 -> V_64 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , int V_22 )
{
F_21 ( & V_2 -> V_71 ) ;
V_2 -> V_72 = F_22 ( V_2 -> V_73 ,
V_2 -> V_56 , V_22 , V_74 ,
V_66 | V_67 ) ;
if ( ! V_2 -> V_72 ) {
F_23 ( V_2 -> V_50 , L_2 ) ;
return - V_68 ;
}
V_2 -> V_72 -> V_69 = F_18 ;
V_2 -> V_72 -> V_70 = & V_2 -> V_71 ;
F_24 ( V_2 -> V_72 ) ;
F_25 ( V_2 -> V_73 ) ;
return 0 ;
}
static int F_27 (
struct V_1 * V_2 , struct V_12 * V_13 )
{
T_1 V_5 ;
unsigned int V_22 ;
int V_75 = 0 ;
T_1 V_76 ;
V_76 = F_1 ( V_2 , V_9 ) ;
if ( ( V_76 & V_77 ) != V_77 ) {
F_23 ( V_2 -> V_50 , L_3 ,
( unsigned ) V_76 ) ;
return - V_68 ;
}
V_5 = F_28 ( V_2 -> V_32 - 1 ) ;
V_5 |= V_2 -> V_30 ;
if ( V_2 -> V_28 )
V_22 = F_8 ( V_2 -> V_32 * V_2 -> V_14 ,
4 ) * 4 ;
else
V_22 = V_2 -> V_32 * 4 ;
if ( V_22 & 0xF )
V_5 |= V_78 | V_79 ;
else if ( ( ( V_22 ) >> 4 ) & 0x1 )
V_5 |= V_80 | V_81 ;
else
V_5 |= V_82 | V_83 ;
if ( V_2 -> V_84 & V_85 )
V_5 |= V_86 ;
if ( V_2 -> V_84 & V_87 )
V_5 |= V_88 ;
F_3 ( V_2 , V_5 , V_89 ) ;
V_2 -> V_90 = V_5 ;
if ( V_2 -> V_84 & V_85 ) {
F_14 ( V_2 , V_13 ) ;
F_29 () ;
V_75 = F_20 ( V_2 , V_22 ) ;
if ( V_75 < 0 ) {
F_23 ( V_2 -> V_50 ,
L_4 , V_75 ) ;
return V_75 ;
}
V_76 = F_1 ( V_2 , V_9 ) ;
while ( ! ( V_76 & V_91 ) )
V_76 = F_1 ( V_2 , V_9 ) ;
}
if ( V_2 -> V_84 & V_87 ) {
F_16 ( V_2 -> V_50 , V_2 -> V_56 ,
V_2 -> V_52 , V_57 ) ;
V_75 = F_26 ( V_2 , V_22 ) ;
if ( V_75 < 0 ) {
F_23 ( V_2 -> V_50 ,
L_5 , V_75 ) ;
if ( V_2 -> V_84 & V_85 )
F_30 ( V_2 -> V_64 ) ;
return V_75 ;
}
}
V_2 -> V_92 = true ;
if ( V_2 -> V_28 ) {
V_5 |= V_93 ;
F_3 ( V_2 , V_5 , V_89 ) ;
F_31 ( 1 ) ;
}
V_2 -> V_90 = V_5 ;
V_5 |= V_94 ;
F_3 ( V_2 , V_5 , V_89 ) ;
return V_75 ;
}
static int F_32 (
struct V_1 * V_2 , struct V_12 * V_13 )
{
T_1 V_5 ;
unsigned V_95 ;
V_5 = V_2 -> V_30 ;
if ( V_2 -> V_84 & V_85 )
V_5 |= V_86 ;
if ( V_2 -> V_84 & V_87 )
V_5 |= V_88 ;
F_3 ( V_2 , V_5 , V_89 ) ;
V_2 -> V_90 = V_5 ;
if ( V_2 -> V_84 & V_85 )
V_95 = F_10 ( V_2 , V_13 ) ;
else
V_95 = V_2 -> V_32 ;
V_5 |= F_28 ( V_95 - 1 ) ;
F_3 ( V_2 , V_5 , V_89 ) ;
V_2 -> V_90 = V_5 ;
V_2 -> V_92 = false ;
if ( V_2 -> V_28 ) {
V_5 |= V_93 ;
F_3 ( V_2 , V_5 , V_89 ) ;
F_31 ( 1 ) ;
F_29 () ;
}
V_2 -> V_90 = V_5 ;
V_5 |= V_94 ;
F_3 ( V_2 , V_5 , V_89 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
bool V_96 )
{
struct V_97 * V_97 ;
T_1 * V_98 ;
T_3 V_99 ;
int V_75 ;
struct V_100 V_101 ;
V_97 = F_34 ( V_2 -> V_50 ,
V_96 ? L_6 : L_7 ) ;
if ( F_35 ( V_97 ) ) {
V_75 = F_36 ( V_97 ) ;
if ( V_75 != - V_102 )
F_23 ( V_2 -> V_50 ,
L_8 , V_75 ) ;
return V_75 ;
}
V_98 = F_37 ( V_2 -> V_50 , V_2 -> V_52 ,
& V_99 , V_103 ) ;
if ( ! V_98 ) {
F_23 ( V_2 -> V_50 , L_9 ) ;
F_38 ( V_97 ) ;
return - V_104 ;
}
if ( V_96 ) {
V_101 . V_105 = V_2 -> V_106 + V_49 ;
V_101 . V_107 = V_108 ;
V_101 . V_109 = 0 ;
} else {
V_101 . V_110 = V_2 -> V_106 + V_6 ;
V_101 . V_111 = V_108 ;
V_101 . V_112 = 0 ;
}
V_75 = F_39 ( V_97 , & V_101 ) ;
if ( V_75 )
goto V_113;
if ( V_96 ) {
V_2 -> V_73 = V_97 ;
V_2 -> V_58 = V_98 ;
V_2 -> V_56 = V_99 ;
} else {
V_2 -> V_64 = V_97 ;
V_2 -> V_54 = V_98 ;
V_2 -> V_51 = V_99 ;
}
return 0 ;
V_113:
F_40 ( V_2 -> V_50 , V_2 -> V_52 , V_98 , V_99 ) ;
F_38 ( V_97 ) ;
return V_75 ;
}
static void F_41 ( struct V_1 * V_2 ,
bool V_96 )
{
T_1 * V_98 ;
T_3 V_99 ;
struct V_97 * V_97 ;
if ( V_96 ) {
V_98 = V_2 -> V_58 ;
V_97 = V_2 -> V_73 ;
V_99 = V_2 -> V_56 ;
V_2 -> V_73 = NULL ;
V_2 -> V_58 = NULL ;
} else {
V_98 = V_2 -> V_54 ;
V_97 = V_2 -> V_64 ;
V_99 = V_2 -> V_51 ;
V_2 -> V_54 = NULL ;
V_2 -> V_64 = NULL ;
}
if ( ! V_97 )
return;
F_40 ( V_2 -> V_50 , V_2 -> V_52 , V_98 , V_99 ) ;
F_38 ( V_97 ) ;
}
static int F_42 ( struct V_19 * V_20 ,
struct V_12 * V_13 )
{
struct V_1 * V_2 = F_43 ( V_20 -> V_114 ) ;
T_1 V_115 ;
T_2 V_25 ;
unsigned V_27 ;
int V_75 ;
T_1 V_116 ;
T_1 V_117 ;
V_25 = V_13 -> V_25 ;
V_115 = V_13 -> V_118 ;
if ( V_115 != V_2 -> V_119 ) {
F_44 ( V_2 -> V_120 , V_115 * 4 ) ;
V_2 -> V_119 = V_115 ;
}
V_2 -> V_121 = V_20 ;
V_2 -> V_23 = 0 ;
V_2 -> V_48 = 0 ;
V_2 -> V_42 = 0 ;
V_2 -> V_122 = V_13 ;
V_27 = F_7 ( V_20 , V_2 , V_13 ) ;
V_116 = V_2 -> V_123 ;
V_116 &= ~ F_45 ( ~ 0 ) ;
V_116 |= F_45 ( V_25 - 1 ) ;
V_117 = V_2 -> V_124 ;
V_117 &= ~ ( V_125 | V_126 ) ;
F_3 ( V_2 , V_116 , V_127 ) ;
V_2 -> V_123 = V_116 ;
V_2 -> V_84 = 0 ;
if ( V_13 -> V_47 ) {
V_117 |= V_125 ;
V_2 -> V_84 |= V_87 ;
}
if ( V_13 -> V_41 ) {
V_117 |= V_126 ;
V_2 -> V_84 |= V_85 ;
}
F_3 ( V_2 , V_117 , V_128 ) ;
V_2 -> V_124 = V_117 ;
if ( V_27 > V_129 )
V_75 = F_27 ( V_2 , V_13 ) ;
else
V_75 = F_32 ( V_2 , V_13 ) ;
return V_75 ;
}
static int F_46 ( struct V_19 * V_20 )
{
static const T_1 V_130 [ V_131 ] = {
V_132 ,
V_133 ,
V_134 ,
V_135 ,
} ;
struct V_1 * V_2 = F_43 ( V_20 -> V_114 ) ;
T_1 V_5 ;
unsigned long V_136 ;
int V_75 ;
F_47 ( & V_20 -> V_50 , L_10 ,
V_20 -> V_25 ,
V_20 -> V_137 & V_138 ? L_11 : L_12 ,
V_20 -> V_137 & V_139 ? L_11 : L_12 ,
V_20 -> V_140 ) ;
F_48 ( V_20 -> V_141 >= V_131 ) ;
V_20 -> V_140 = V_20 -> V_140 ? : V_2 -> V_142 ;
V_75 = F_49 ( V_2 -> V_50 ) ;
if ( V_75 < 0 ) {
F_23 ( V_2 -> V_50 , L_13 , V_75 ) ;
return V_75 ;
}
F_50 ( & V_2 -> V_143 , V_136 ) ;
V_5 = V_2 -> V_144 ;
if ( V_20 -> V_137 & V_145 )
V_5 |= V_130 [ V_20 -> V_141 ] ;
else
V_5 &= ~ V_130 [ V_20 -> V_141 ] ;
V_2 -> V_144 = V_5 ;
F_3 ( V_2 , V_2 -> V_144 , V_127 ) ;
F_51 ( & V_2 -> V_143 , V_136 ) ;
F_52 ( V_2 -> V_50 ) ;
return 0 ;
}
static int F_53 ( struct V_146 * V_114 ,
struct V_147 * V_148 )
{
struct V_1 * V_2 = F_43 ( V_114 ) ;
struct V_19 * V_20 = V_148 -> V_20 ;
F_5 ( V_2 ) ;
V_2 -> V_123 = V_2 -> V_144 ;
V_2 -> V_123 |= V_149 | V_150 ;
V_2 -> V_124 = V_2 -> V_151 ;
V_2 -> V_124 |= F_54 ( V_20 -> V_141 ) ;
V_2 -> V_123 &= ~ V_152 ;
if ( V_20 -> V_137 & V_139 )
V_2 -> V_123 |= V_153 ;
if ( V_20 -> V_137 & V_138 )
V_2 -> V_123 |= V_154 ;
else
V_2 -> V_123 |= V_155 ;
return 0 ;
}
static int F_55 ( struct V_146 * V_114 ,
struct V_19 * V_20 ,
struct V_12 * V_156 )
{
struct V_1 * V_2 = F_43 ( V_114 ) ;
int V_75 ;
F_21 ( & V_2 -> V_157 ) ;
V_75 = F_42 ( V_20 , V_156 ) ;
if ( V_75 < 0 ) {
F_23 ( V_2 -> V_50 ,
L_14 , V_75 ) ;
return V_75 ;
}
V_75 = F_56 ( & V_2 -> V_157 ,
V_158 ) ;
if ( F_57 ( V_75 == 0 ) ) {
F_23 ( V_2 -> V_50 ,
L_15 , V_75 ) ;
return - V_68 ;
}
if ( V_2 -> V_159 )
return V_2 -> V_159 ;
if ( V_2 -> V_160 )
return V_2 -> V_160 ;
return 0 ;
}
static int F_58 ( struct V_146 * V_114 ,
struct V_147 * V_148 )
{
struct V_1 * V_2 = F_43 ( V_114 ) ;
F_3 ( V_2 , V_2 -> V_144 , V_127 ) ;
F_3 ( V_2 , V_2 -> V_151 , V_128 ) ;
return 0 ;
}
static T_4 F_59 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_122 ;
unsigned long V_136 ;
F_50 ( & V_2 -> V_143 , V_136 ) ;
if ( V_2 -> V_159 || V_2 -> V_160 ||
( V_2 -> V_161 & V_162 ) ) {
F_23 ( V_2 -> V_50 ,
L_16 , V_2 -> V_161 ) ;
F_23 ( V_2 -> V_50 ,
L_17 , V_2 -> V_123 ,
V_2 -> V_124 , V_2 -> V_90 ) ;
F_60 ( V_2 -> V_163 ) ;
F_31 ( 2 ) ;
F_61 ( V_2 -> V_163 ) ;
F_19 ( & V_2 -> V_157 ) ;
goto exit;
}
if ( V_2 -> V_84 & V_87 )
F_12 ( V_2 , V_13 ) ;
if ( V_2 -> V_84 & V_85 )
V_2 -> V_23 = V_2 -> V_42 ;
else
V_2 -> V_23 = V_2 -> V_48 ;
if ( V_2 -> V_23 == V_13 -> V_22 ) {
F_19 ( & V_2 -> V_157 ) ;
goto exit;
}
F_7 ( V_2 -> V_121 , V_2 , V_13 ) ;
F_32 ( V_2 , V_13 ) ;
exit:
F_51 ( & V_2 -> V_143 , V_136 ) ;
return V_164 ;
}
static T_4 F_62 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_122 ;
long V_165 ;
int V_166 = 0 ;
unsigned V_27 ;
unsigned long V_136 ;
if ( V_2 -> V_84 & V_85 ) {
if ( V_2 -> V_159 ) {
F_30 ( V_2 -> V_64 ) ;
V_166 += 1 ;
} else {
V_165 = F_63 (
& V_2 -> V_62 , V_158 ) ;
if ( V_165 <= 0 ) {
F_30 ( V_2 -> V_64 ) ;
F_23 ( V_2 -> V_50 , L_18 ) ;
V_166 += 1 ;
}
}
}
if ( V_2 -> V_84 & V_87 ) {
if ( V_2 -> V_160 ) {
F_30 ( V_2 -> V_73 ) ;
V_166 += 2 ;
} else {
V_165 = F_63 (
& V_2 -> V_71 , V_158 ) ;
if ( V_165 <= 0 ) {
F_30 ( V_2 -> V_73 ) ;
F_23 ( V_2 -> V_50 , L_19 ) ;
V_166 += 2 ;
}
}
}
F_50 ( & V_2 -> V_143 , V_136 ) ;
if ( V_166 ) {
F_23 ( V_2 -> V_50 ,
L_20 , V_2 -> V_161 ) ;
F_23 ( V_2 -> V_50 ,
L_21 , V_2 -> V_123 ,
V_2 -> V_124 , V_2 -> V_90 ) ;
F_60 ( V_2 -> V_163 ) ;
F_31 ( 2 ) ;
F_60 ( V_2 -> V_163 ) ;
F_19 ( & V_2 -> V_157 ) ;
F_51 ( & V_2 -> V_143 , V_136 ) ;
return V_164 ;
}
if ( V_2 -> V_84 & V_87 )
F_17 ( V_2 , V_13 ) ;
if ( V_2 -> V_84 & V_85 )
V_2 -> V_23 = V_2 -> V_42 ;
else
V_2 -> V_23 = V_2 -> V_48 ;
if ( V_2 -> V_23 == V_13 -> V_22 ) {
F_19 ( & V_2 -> V_157 ) ;
goto exit;
}
V_27 = F_7 ( V_2 -> V_121 ,
V_2 , V_13 ) ;
if ( V_27 > V_129 )
V_166 = F_27 ( V_2 , V_13 ) ;
else
V_166 = F_32 ( V_2 , V_13 ) ;
exit:
F_51 ( & V_2 -> V_143 , V_136 ) ;
return V_164 ;
}
static T_4 F_64 ( int V_167 , void * V_168 )
{
struct V_1 * V_2 = V_168 ;
if ( ! V_2 -> V_92 )
return F_59 ( V_2 ) ;
return F_62 ( V_2 ) ;
}
static T_4 F_65 ( int V_167 , void * V_168 )
{
struct V_1 * V_2 = V_168 ;
V_2 -> V_161 = F_1 ( V_2 , V_9 ) ;
if ( V_2 -> V_84 & V_85 )
V_2 -> V_159 = V_2 -> V_161 &
( V_169 | V_170 ) ;
if ( V_2 -> V_84 & V_87 )
V_2 -> V_160 = V_2 -> V_161 &
( V_171 | V_172 ) ;
F_5 ( V_2 ) ;
return V_173 ;
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_174 * V_175 = V_2 -> V_50 -> V_176 ;
if ( F_67 ( V_175 , L_22 ,
& V_2 -> V_142 ) )
V_2 -> V_142 = 25000000 ;
}
static int F_68 ( struct V_177 * V_178 )
{
struct V_146 * V_114 ;
struct V_1 * V_2 ;
struct V_179 * V_180 ;
int V_75 , V_181 ;
const struct V_182 * V_183 = NULL ;
const struct V_184 * V_185 ;
V_185 = F_69 ( V_186 , & V_178 -> V_50 ) ;
if ( ! V_185 ) {
F_23 ( & V_178 -> V_50 , L_23 ) ;
return - V_187 ;
}
V_183 = V_185 -> V_188 ;
V_114 = F_70 ( & V_178 -> V_50 , sizeof( * V_2 ) ) ;
if ( ! V_114 ) {
F_23 ( & V_178 -> V_50 , L_24 ) ;
return - V_104 ;
}
V_114 -> V_189 = V_138 | V_139 | V_145 ;
V_114 -> V_190 = F_46 ;
V_114 -> V_191 = F_53 ;
V_114 -> V_192 = F_55 ;
V_114 -> V_193 = F_58 ;
V_114 -> V_194 = true ;
V_114 -> V_195 = V_131 ;
V_114 -> V_196 = - 1 ;
F_71 ( V_178 , V_114 ) ;
V_2 = F_43 ( V_114 ) ;
V_2 -> V_114 = V_114 ;
V_2 -> V_50 = & V_178 -> V_50 ;
V_2 -> V_197 = V_183 ;
F_72 ( & V_2 -> V_143 ) ;
F_66 ( V_2 ) ;
V_180 = F_73 ( V_178 , V_198 , 0 ) ;
if ( ! V_180 ) {
F_23 ( & V_178 -> V_50 , L_25 ) ;
V_75 = - V_187 ;
goto V_199;
}
V_2 -> V_106 = V_180 -> V_200 ;
V_2 -> V_4 = F_74 ( & V_178 -> V_50 , V_180 ) ;
if ( F_35 ( V_2 -> V_4 ) ) {
V_75 = F_36 ( V_2 -> V_4 ) ;
goto V_199;
}
V_181 = F_75 ( V_178 , 0 ) ;
V_2 -> V_167 = V_181 ;
V_75 = F_76 ( V_2 -> V_167 , F_65 ,
F_64 , V_201 ,
F_77 ( & V_178 -> V_50 ) , V_2 ) ;
if ( V_75 < 0 ) {
F_23 ( & V_178 -> V_50 , L_26 ,
V_2 -> V_167 ) ;
goto V_199;
}
V_2 -> V_120 = F_78 ( & V_178 -> V_50 , NULL ) ;
if ( F_35 ( V_2 -> V_120 ) ) {
F_23 ( & V_178 -> V_50 , L_27 ) ;
V_75 = F_36 ( V_2 -> V_120 ) ;
goto V_202;
}
V_2 -> V_163 = F_79 ( & V_178 -> V_50 , L_28 ) ;
if ( F_35 ( V_2 -> V_163 ) ) {
F_23 ( & V_178 -> V_50 , L_29 ) ;
V_75 = F_36 ( V_2 -> V_163 ) ;
goto V_202;
}
V_2 -> V_31 = V_129 << 2 ;
V_2 -> V_52 = V_203 ;
V_75 = F_33 ( V_2 , true ) ;
if ( V_75 < 0 )
goto V_202;
V_75 = F_33 ( V_2 , false ) ;
if ( V_75 < 0 )
goto V_204;
V_2 -> V_31 = V_2 -> V_52 ;
F_80 ( & V_2 -> V_62 ) ;
F_80 ( & V_2 -> V_71 ) ;
F_80 ( & V_2 -> V_157 ) ;
F_81 ( & V_178 -> V_50 ) ;
if ( ! F_82 ( & V_178 -> V_50 ) ) {
V_75 = F_83 ( & V_178 -> V_50 ) ;
if ( V_75 )
goto V_205;
}
V_75 = F_49 ( & V_178 -> V_50 ) ;
if ( V_75 < 0 ) {
F_23 ( & V_178 -> V_50 , L_30 , V_75 ) ;
goto V_205;
}
V_2 -> V_144 = V_206 ;
V_2 -> V_151 = V_207 ;
F_3 ( V_2 , V_2 -> V_144 , V_127 ) ;
F_3 ( V_2 , V_2 -> V_151 , V_128 ) ;
F_52 ( & V_178 -> V_50 ) ;
V_114 -> V_50 . V_176 = V_178 -> V_50 . V_176 ;
V_75 = F_84 ( & V_178 -> V_50 , V_114 ) ;
if ( V_75 < 0 ) {
F_23 ( & V_178 -> V_50 , L_31 , V_75 ) ;
goto V_205;
}
return V_75 ;
V_205:
F_85 ( & V_178 -> V_50 ) ;
if ( ! F_86 ( & V_178 -> V_50 ) )
F_87 ( & V_178 -> V_50 ) ;
F_41 ( V_2 , false ) ;
V_204:
F_41 ( V_2 , true ) ;
V_202:
F_88 ( V_181 , V_2 ) ;
V_199:
F_89 ( V_114 ) ;
return V_75 ;
}
static int F_90 ( struct V_177 * V_178 )
{
struct V_146 * V_114 = F_91 ( V_178 ) ;
struct V_1 * V_2 = F_43 ( V_114 ) ;
F_88 ( V_2 -> V_167 , V_2 ) ;
if ( V_2 -> V_64 )
F_41 ( V_2 , false ) ;
if ( V_2 -> V_73 )
F_41 ( V_2 , true ) ;
F_85 ( & V_178 -> V_50 ) ;
if ( ! F_86 ( & V_178 -> V_50 ) )
F_87 ( & V_178 -> V_50 ) ;
return 0 ;
}
static int F_92 ( struct V_208 * V_50 )
{
struct V_146 * V_114 = F_93 ( V_50 ) ;
return F_94 ( V_114 ) ;
}
static int F_95 ( struct V_208 * V_50 )
{
struct V_146 * V_114 = F_93 ( V_50 ) ;
struct V_1 * V_2 = F_43 ( V_114 ) ;
int V_75 ;
V_75 = F_49 ( V_50 ) ;
if ( V_75 < 0 ) {
F_23 ( V_50 , L_13 , V_75 ) ;
return V_75 ;
}
F_3 ( V_2 , V_2 -> V_123 , V_127 ) ;
F_3 ( V_2 , V_2 -> V_124 , V_128 ) ;
F_52 ( V_50 ) ;
return F_96 ( V_114 ) ;
}
static int F_87 ( struct V_208 * V_50 )
{
struct V_146 * V_114 = F_93 ( V_50 ) ;
struct V_1 * V_2 = F_43 ( V_114 ) ;
F_1 ( V_2 , V_7 ) ;
F_97 ( V_2 -> V_120 ) ;
return 0 ;
}
static int F_83 ( struct V_208 * V_50 )
{
struct V_146 * V_114 = F_93 ( V_50 ) ;
struct V_1 * V_2 = F_43 ( V_114 ) ;
int V_75 ;
V_75 = F_98 ( V_2 -> V_120 ) ;
if ( V_75 < 0 ) {
F_23 ( V_2 -> V_50 , L_32 , V_75 ) ;
return V_75 ;
}
return 0 ;
}
