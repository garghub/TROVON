static inline unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
unsigned long V_5 , unsigned long V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
if ( V_3 != V_6 )
F_2 ( V_2 -> V_4 + V_7 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
unsigned long V_5 ;
unsigned long V_8 = 0 ;
V_5 = F_1 ( V_2 , V_9 ) ;
V_8 = V_10 | V_11 ;
F_3 ( V_2 , V_8 , V_9 ) ;
}
static unsigned long F_6 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
unsigned long V_5 ;
switch ( V_2 -> V_14 ) {
case 0 :
V_5 = V_15 ;
break;
case 1 :
V_5 = V_16 ;
break;
case 2 :
V_5 = V_17 ;
break;
case 4 :
V_5 = V_18 ;
break;
default:
V_5 = 0 ;
}
return V_5 ;
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
unsigned long V_35 ;
unsigned V_36 ;
unsigned V_37 , V_38 ;
unsigned long V_39 ;
unsigned int V_40 ;
unsigned V_41 ;
T_1 * V_42 = ( T_1 * ) V_13 -> V_42 + V_2 -> V_43 ;
V_35 = F_1 ( V_2 , V_44 ) ;
V_34 = F_11 ( V_35 ) ;
if ( V_2 -> V_28 ) {
V_41 = V_34 * V_2 -> V_29 ;
V_40 = F_9 ( V_41 , V_2 -> V_32 ) ;
V_33 = V_40 * V_2 -> V_14 ;
V_36 = F_8 ( V_33 , 4 ) ;
for ( V_38 = 0 ; V_38 < V_36 ; V_38 ++ ) {
V_39 = 0 ;
for ( V_37 = 0 ; ( V_37 < 4 ) && V_33 ; V_37 ++ , V_33 -- )
V_39 |= ( * V_42 ++ ) << ( V_37 * 8 ) ;
F_3 ( V_2 , V_39 , V_6 ) ;
}
} else {
V_36 = F_9 ( V_2 -> V_32 , V_34 ) ;
V_40 = V_36 ;
V_33 = V_40 * V_2 -> V_14 ;
for ( V_38 = 0 ; V_38 < V_36 ; V_38 ++ ) {
V_39 = 0 ;
for ( V_37 = 0 ; V_33 && ( V_37 < V_2 -> V_14 ) ;
V_37 ++ , V_33 -- )
V_39 |= ( ( * V_42 ++ ) << V_37 * 8 ) ;
F_3 ( V_2 , V_39 , V_6 ) ;
}
}
V_2 -> V_43 += V_40 * V_2 -> V_14 ;
return V_40 ;
}
static unsigned int F_12 (
struct V_1 * V_2 , struct V_12 * V_13 )
{
unsigned V_45 ;
unsigned long V_35 ;
unsigned V_37 , V_38 ;
unsigned long V_39 ;
unsigned int V_46 = 0 ;
unsigned V_22 ;
T_1 * V_47 = ( T_1 * ) V_13 -> V_47 + V_2 -> V_48 ;
V_35 = F_1 ( V_2 , V_44 ) ;
V_45 = F_13 ( V_35 ) ;
if ( V_2 -> V_28 ) {
V_22 = V_2 -> V_32 * V_2 -> V_14 ;
for ( V_38 = 0 ; V_38 < V_45 ; V_38 ++ ) {
V_39 = F_1 ( V_2 , V_49 ) ;
for ( V_37 = 0 ; V_22 && ( V_37 < 4 ) ; V_37 ++ , V_22 -- )
* V_47 ++ = ( V_39 >> V_37 * 8 ) & 0xFF ;
}
V_2 -> V_48 += V_2 -> V_32 * V_2 -> V_14 ;
V_46 += V_2 -> V_32 ;
} else {
for ( V_38 = 0 ; V_38 < V_45 ; V_38 ++ ) {
V_39 = F_1 ( V_2 , V_49 ) ;
for ( V_37 = 0 ; ( V_37 < V_2 -> V_14 ) ; V_37 ++ )
* V_47 ++ = ( V_39 >> ( V_37 * 8 ) ) & 0xFF ;
}
V_2 -> V_48 += V_45 * V_2 -> V_14 ;
V_46 += V_45 ;
}
return V_46 ;
}
static void F_14 (
struct V_1 * V_2 , struct V_12 * V_13 )
{
unsigned V_22 ;
F_15 ( V_2 -> V_50 , V_2 -> V_51 ,
V_2 -> V_52 , V_53 ) ;
if ( V_2 -> V_28 ) {
V_22 = V_2 -> V_32 * V_2 -> V_14 ;
memcpy ( V_2 -> V_54 , V_13 -> V_42 + V_2 -> V_23 , V_22 ) ;
} else {
unsigned int V_37 ;
unsigned int V_38 ;
T_1 * V_42 = ( T_1 * ) V_13 -> V_42 + V_2 -> V_43 ;
unsigned V_55 = V_2 -> V_32 * V_2 -> V_14 ;
unsigned int V_39 ;
for ( V_38 = 0 ; V_38 < V_2 -> V_32 ; V_38 ++ ) {
V_39 = 0 ;
for ( V_37 = 0 ; V_55 && ( V_37 < V_2 -> V_14 ) ;
V_37 ++ , V_55 -- )
V_39 |= ( ( * V_42 ++ ) << V_37 * 8 ) ;
V_2 -> V_54 [ V_38 ] = V_39 ;
}
}
V_2 -> V_43 += V_2 -> V_32 * V_2 -> V_14 ;
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
unsigned int V_39 ;
unsigned int V_59 , V_25 ;
V_25 = V_13 -> V_25 ;
V_59 = ( 1 << V_25 ) - 1 ;
for ( V_38 = 0 ; V_38 < V_2 -> V_32 ; V_38 ++ ) {
V_39 = V_2 -> V_58 [ V_38 ] ;
V_39 &= V_59 ;
for ( V_37 = 0 ; ( V_37 < V_2 -> V_14 ) ; V_37 ++ )
* V_47 ++ = ( V_39 >> ( V_37 * 8 ) ) & 0xFF ;
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
unsigned long V_5 ;
unsigned long V_75 ;
unsigned int V_22 ;
int V_76 = 0 ;
unsigned long V_77 ;
V_77 = F_1 ( V_2 , V_9 ) ;
if ( ( V_77 & V_78 ) != V_78 ) {
F_23 ( V_2 -> V_50 ,
L_3 , V_77 ) ;
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
V_5 |= V_79 | V_80 ;
else if ( ( ( V_22 ) >> 4 ) & 0x1 )
V_5 |= V_81 | V_82 ;
else
V_5 |= V_83 | V_84 ;
if ( V_2 -> V_85 & V_86 )
V_5 |= V_87 ;
if ( V_2 -> V_85 & V_88 )
V_5 |= V_89 ;
F_3 ( V_2 , V_5 , V_90 ) ;
V_2 -> V_91 = V_5 ;
if ( V_2 -> V_85 & V_86 ) {
F_14 ( V_2 , V_13 ) ;
F_29 () ;
V_76 = F_20 ( V_2 , V_22 ) ;
if ( V_76 < 0 ) {
F_23 ( V_2 -> V_50 ,
L_4 , V_76 ) ;
return V_76 ;
}
V_75 = F_1 ( V_2 , V_9 ) ;
while ( ! ( V_75 & V_92 ) )
V_75 = F_1 ( V_2 , V_9 ) ;
}
if ( V_2 -> V_85 & V_88 ) {
F_16 ( V_2 -> V_50 , V_2 -> V_56 ,
V_2 -> V_52 , V_57 ) ;
V_76 = F_26 ( V_2 , V_22 ) ;
if ( V_76 < 0 ) {
F_23 ( V_2 -> V_50 ,
L_5 , V_76 ) ;
if ( V_2 -> V_85 & V_86 )
F_30 ( V_2 -> V_64 ) ;
return V_76 ;
}
}
V_2 -> V_93 = true ;
if ( V_2 -> V_28 ) {
V_5 |= V_94 ;
F_3 ( V_2 , V_5 , V_90 ) ;
F_31 ( 1 ) ;
}
V_2 -> V_91 = V_5 ;
V_5 |= V_95 ;
F_3 ( V_2 , V_5 , V_90 ) ;
return V_76 ;
}
static int F_32 (
struct V_1 * V_2 , struct V_12 * V_13 )
{
unsigned long V_5 ;
unsigned V_96 ;
V_5 = V_2 -> V_30 ;
if ( V_2 -> V_85 & V_86 )
V_5 |= V_87 ;
if ( V_2 -> V_85 & V_88 )
V_5 |= V_89 ;
F_3 ( V_2 , V_5 , V_90 ) ;
V_2 -> V_91 = V_5 ;
if ( V_2 -> V_85 & V_86 )
V_96 = F_10 ( V_2 , V_13 ) ;
else
V_96 = V_2 -> V_32 ;
V_5 |= F_28 ( V_96 - 1 ) ;
F_3 ( V_2 , V_5 , V_90 ) ;
V_2 -> V_91 = V_5 ;
V_2 -> V_93 = false ;
if ( V_2 -> V_28 ) {
V_5 |= V_94 ;
F_3 ( V_2 , V_5 , V_90 ) ;
F_31 ( 1 ) ;
F_29 () ;
}
V_2 -> V_91 = V_5 ;
V_5 |= V_95 ;
F_3 ( V_2 , V_5 , V_90 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
bool V_97 )
{
struct V_98 * V_98 ;
T_2 * V_99 ;
T_3 V_100 ;
int V_76 ;
struct V_101 V_102 ;
T_4 V_103 ;
F_34 ( V_103 ) ;
F_35 ( V_104 , V_103 ) ;
V_98 = F_36 ( V_103 , NULL , NULL ) ;
if ( ! V_98 ) {
F_23 ( V_2 -> V_50 ,
L_6 ) ;
return - V_105 ;
}
V_99 = F_37 ( V_2 -> V_50 , V_2 -> V_52 ,
& V_100 , V_106 ) ;
if ( ! V_99 ) {
F_23 ( V_2 -> V_50 , L_7 ) ;
F_38 ( V_98 ) ;
return - V_107 ;
}
V_102 . V_108 = V_2 -> V_109 ;
if ( V_97 ) {
V_102 . V_110 = V_2 -> V_111 + V_49 ;
V_102 . V_112 = V_113 ;
V_102 . V_114 = 0 ;
} else {
V_102 . V_115 = V_2 -> V_111 + V_6 ;
V_102 . V_116 = V_113 ;
V_102 . V_117 = 0 ;
}
V_76 = F_39 ( V_98 , & V_102 ) ;
if ( V_76 )
goto V_118;
if ( V_97 ) {
V_2 -> V_73 = V_98 ;
V_2 -> V_58 = V_99 ;
V_2 -> V_56 = V_100 ;
} else {
V_2 -> V_64 = V_98 ;
V_2 -> V_54 = V_99 ;
V_2 -> V_51 = V_100 ;
}
return 0 ;
V_118:
F_40 ( V_2 -> V_50 , V_2 -> V_52 , V_99 , V_100 ) ;
F_38 ( V_98 ) ;
return V_76 ;
}
static void F_41 ( struct V_1 * V_2 ,
bool V_97 )
{
T_2 * V_99 ;
T_3 V_100 ;
struct V_98 * V_98 ;
if ( V_97 ) {
V_99 = V_2 -> V_58 ;
V_98 = V_2 -> V_73 ;
V_100 = V_2 -> V_56 ;
V_2 -> V_73 = NULL ;
V_2 -> V_58 = NULL ;
} else {
V_99 = V_2 -> V_54 ;
V_98 = V_2 -> V_64 ;
V_100 = V_2 -> V_51 ;
V_2 -> V_54 = NULL ;
V_2 -> V_64 = NULL ;
}
if ( ! V_98 )
return;
F_40 ( V_2 -> V_50 , V_2 -> V_52 , V_99 , V_100 ) ;
F_38 ( V_98 ) ;
}
static int F_42 ( struct V_19 * V_20 ,
struct V_12 * V_13 )
{
struct V_1 * V_2 = F_43 ( V_20 -> V_119 ) ;
T_2 V_120 ;
T_1 V_25 ;
unsigned V_27 ;
int V_76 ;
unsigned long V_121 ;
unsigned long V_122 ;
V_25 = V_13 -> V_25 ;
V_120 = V_13 -> V_123 ;
if ( V_120 != V_2 -> V_124 ) {
F_44 ( V_2 -> V_125 , V_120 * 4 ) ;
V_2 -> V_124 = V_120 ;
}
V_2 -> V_126 = V_20 ;
V_2 -> V_23 = 0 ;
V_2 -> V_48 = 0 ;
V_2 -> V_43 = 0 ;
V_2 -> V_127 = V_13 ;
V_27 = F_7 ( V_20 , V_2 , V_13 ) ;
V_121 = V_2 -> V_128 ;
V_121 &= ~ F_45 ( ~ 0 ) ;
V_121 |= F_45 ( V_25 - 1 ) ;
V_122 = V_2 -> V_129 ;
V_122 &= ~ ( V_130 | V_131 ) ;
F_3 ( V_2 , V_121 , V_132 ) ;
V_2 -> V_128 = V_121 ;
V_2 -> V_85 = 0 ;
if ( V_13 -> V_47 ) {
V_122 |= V_130 ;
V_2 -> V_85 |= V_88 ;
}
if ( V_13 -> V_42 ) {
V_122 |= V_131 ;
V_2 -> V_85 |= V_86 ;
}
F_3 ( V_2 , V_122 , V_133 ) ;
V_2 -> V_129 = V_122 ;
if ( V_27 > V_134 )
V_76 = F_27 ( V_2 , V_13 ) ;
else
V_76 = F_32 ( V_2 , V_13 ) ;
return V_76 ;
}
static int F_46 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_43 ( V_20 -> V_119 ) ;
unsigned long V_5 ;
unsigned long V_135 ;
int V_76 ;
unsigned int V_136 [ V_137 ] = {
V_138 ,
V_139 ,
V_140 ,
V_141 ,
} ;
F_47 ( & V_20 -> V_50 , L_8 ,
V_20 -> V_25 ,
V_20 -> V_142 & V_143 ? L_9 : L_10 ,
V_20 -> V_142 & V_144 ? L_9 : L_10 ,
V_20 -> V_145 ) ;
F_48 ( V_20 -> V_146 >= V_137 ) ;
V_20 -> V_145 = V_20 -> V_145 ? : V_2 -> V_147 ;
V_76 = F_49 ( V_2 -> V_50 ) ;
if ( V_76 < 0 ) {
F_23 ( V_2 -> V_50 , L_11 , V_76 ) ;
return V_76 ;
}
F_50 ( & V_2 -> V_148 , V_135 ) ;
V_5 = V_2 -> V_149 ;
if ( V_20 -> V_142 & V_150 )
V_5 |= V_136 [ V_20 -> V_146 ] ;
else
V_5 &= ~ V_136 [ V_20 -> V_146 ] ;
V_2 -> V_149 = V_5 ;
F_3 ( V_2 , V_2 -> V_149 , V_132 ) ;
F_51 ( & V_2 -> V_148 , V_135 ) ;
F_52 ( V_2 -> V_50 ) ;
return 0 ;
}
static int F_53 ( struct V_151 * V_119 ,
struct V_152 * V_153 )
{
struct V_1 * V_2 = F_43 ( V_119 ) ;
struct V_19 * V_20 = V_153 -> V_20 ;
F_5 ( V_2 ) ;
V_2 -> V_128 = V_2 -> V_149 ;
V_2 -> V_128 |= V_154 | V_155 ;
V_2 -> V_129 = V_2 -> V_156 ;
V_2 -> V_129 |= F_54 ( V_20 -> V_146 ) ;
V_2 -> V_128 &= ~ V_157 ;
if ( V_20 -> V_142 & V_144 )
V_2 -> V_128 |= V_158 ;
if ( V_20 -> V_142 & V_143 )
V_2 -> V_128 |= V_159 ;
else
V_2 -> V_128 |= V_160 ;
return 0 ;
}
static int F_55 ( struct V_151 * V_119 ,
struct V_19 * V_20 ,
struct V_12 * V_161 )
{
struct V_1 * V_2 = F_43 ( V_119 ) ;
int V_76 ;
F_21 ( & V_2 -> V_162 ) ;
V_76 = F_42 ( V_20 , V_161 ) ;
if ( V_76 < 0 ) {
F_23 ( V_2 -> V_50 ,
L_12 , V_76 ) ;
return V_76 ;
}
V_76 = F_56 ( & V_2 -> V_162 ,
V_163 ) ;
if ( F_57 ( V_76 == 0 ) ) {
F_23 ( V_2 -> V_50 ,
L_13 , V_76 ) ;
return - V_68 ;
}
if ( V_2 -> V_164 )
return V_2 -> V_164 ;
if ( V_2 -> V_165 )
return V_2 -> V_165 ;
return 0 ;
}
static int F_58 ( struct V_151 * V_119 ,
struct V_152 * V_153 )
{
struct V_1 * V_2 = F_43 ( V_119 ) ;
F_3 ( V_2 , V_2 -> V_149 , V_132 ) ;
F_3 ( V_2 , V_2 -> V_156 , V_133 ) ;
return 0 ;
}
static T_5 F_59 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_127 ;
unsigned long V_135 ;
F_50 ( & V_2 -> V_148 , V_135 ) ;
if ( V_2 -> V_164 || V_2 -> V_165 ||
( V_2 -> V_166 & V_167 ) ) {
F_23 ( V_2 -> V_50 ,
L_14 , V_2 -> V_166 ) ;
F_23 ( V_2 -> V_50 ,
L_15 , V_2 -> V_128 ,
V_2 -> V_129 , V_2 -> V_91 ) ;
F_60 ( V_2 -> V_125 ) ;
F_31 ( 2 ) ;
F_61 ( V_2 -> V_125 ) ;
F_19 ( & V_2 -> V_162 ) ;
goto exit;
}
if ( V_2 -> V_85 & V_88 )
F_12 ( V_2 , V_13 ) ;
if ( V_2 -> V_85 & V_86 )
V_2 -> V_23 = V_2 -> V_43 ;
else
V_2 -> V_23 = V_2 -> V_48 ;
if ( V_2 -> V_23 == V_13 -> V_22 ) {
F_19 ( & V_2 -> V_162 ) ;
goto exit;
}
F_7 ( V_2 -> V_126 , V_2 , V_13 ) ;
F_32 ( V_2 , V_13 ) ;
exit:
F_51 ( & V_2 -> V_148 , V_135 ) ;
return V_168 ;
}
static T_5 F_62 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_127 ;
long V_169 ;
int V_170 = 0 ;
unsigned V_27 ;
unsigned long V_135 ;
if ( V_2 -> V_85 & V_86 ) {
if ( V_2 -> V_164 ) {
F_30 ( V_2 -> V_64 ) ;
V_170 += 1 ;
} else {
V_169 = F_63 (
& V_2 -> V_62 , V_163 ) ;
if ( V_169 <= 0 ) {
F_30 ( V_2 -> V_64 ) ;
F_23 ( V_2 -> V_50 , L_16 ) ;
V_170 += 1 ;
}
}
}
if ( V_2 -> V_85 & V_88 ) {
if ( V_2 -> V_165 ) {
F_30 ( V_2 -> V_73 ) ;
V_170 += 2 ;
} else {
V_169 = F_63 (
& V_2 -> V_71 , V_163 ) ;
if ( V_169 <= 0 ) {
F_30 ( V_2 -> V_73 ) ;
F_23 ( V_2 -> V_50 , L_17 ) ;
V_170 += 2 ;
}
}
}
F_50 ( & V_2 -> V_148 , V_135 ) ;
if ( V_170 ) {
F_23 ( V_2 -> V_50 ,
L_18 , V_2 -> V_166 ) ;
F_23 ( V_2 -> V_50 ,
L_19 , V_2 -> V_128 ,
V_2 -> V_129 , V_2 -> V_91 ) ;
F_60 ( V_2 -> V_125 ) ;
F_31 ( 2 ) ;
F_61 ( V_2 -> V_125 ) ;
F_19 ( & V_2 -> V_162 ) ;
F_51 ( & V_2 -> V_148 , V_135 ) ;
return V_168 ;
}
if ( V_2 -> V_85 & V_88 )
F_17 ( V_2 , V_13 ) ;
if ( V_2 -> V_85 & V_86 )
V_2 -> V_23 = V_2 -> V_43 ;
else
V_2 -> V_23 = V_2 -> V_48 ;
if ( V_2 -> V_23 == V_13 -> V_22 ) {
F_19 ( & V_2 -> V_162 ) ;
goto exit;
}
V_27 = F_7 ( V_2 -> V_126 ,
V_2 , V_13 ) ;
if ( V_27 > V_134 )
V_170 = F_27 ( V_2 , V_13 ) ;
else
V_170 = F_32 ( V_2 , V_13 ) ;
exit:
F_51 ( & V_2 -> V_148 , V_135 ) ;
return V_168 ;
}
static T_5 F_64 ( int V_171 , void * V_172 )
{
struct V_1 * V_2 = V_172 ;
if ( ! V_2 -> V_93 )
return F_59 ( V_2 ) ;
return F_62 ( V_2 ) ;
}
static T_5 F_65 ( int V_171 , void * V_172 )
{
struct V_1 * V_2 = V_172 ;
V_2 -> V_166 = F_1 ( V_2 , V_9 ) ;
if ( V_2 -> V_85 & V_86 )
V_2 -> V_164 = V_2 -> V_166 &
( V_173 | V_174 ) ;
if ( V_2 -> V_85 & V_88 )
V_2 -> V_165 = V_2 -> V_166 &
( V_175 | V_176 ) ;
F_5 ( V_2 ) ;
return V_177 ;
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_178 * V_179 = V_2 -> V_50 -> V_180 ;
T_2 V_181 [ 2 ] ;
if ( F_67 ( V_179 , L_20 ,
V_181 , 2 ) >= 0 )
V_2 -> V_109 = V_181 [ 1 ] ;
if ( F_68 ( V_179 , L_21 ,
& V_2 -> V_147 ) )
V_2 -> V_147 = 25000000 ;
}
static int F_69 ( struct V_182 * V_183 )
{
struct V_151 * V_119 ;
struct V_1 * V_2 ;
struct V_184 * V_185 ;
int V_76 , V_186 ;
const struct V_187 * V_188 = NULL ;
const struct V_189 * V_190 ;
V_190 = F_70 ( V_191 , & V_183 -> V_50 ) ;
if ( ! V_190 ) {
F_23 ( & V_183 -> V_50 , L_22 ) ;
return - V_192 ;
}
V_188 = V_190 -> V_193 ;
V_119 = F_71 ( & V_183 -> V_50 , sizeof( * V_2 ) ) ;
if ( ! V_119 ) {
F_23 ( & V_183 -> V_50 , L_23 ) ;
return - V_107 ;
}
V_119 -> V_194 = V_143 | V_144 | V_150 ;
V_119 -> V_195 = F_46 ;
V_119 -> V_196 = F_53 ;
V_119 -> V_197 = F_55 ;
V_119 -> V_198 = F_58 ;
V_119 -> V_199 = true ;
V_119 -> V_200 = V_137 ;
V_119 -> V_201 = - 1 ;
F_72 ( V_183 , V_119 ) ;
V_2 = F_43 ( V_119 ) ;
V_2 -> V_119 = V_119 ;
V_2 -> V_50 = & V_183 -> V_50 ;
V_2 -> V_202 = V_188 ;
F_73 ( & V_2 -> V_148 ) ;
F_66 ( V_2 ) ;
V_185 = F_74 ( V_183 , V_203 , 0 ) ;
if ( ! V_185 ) {
F_23 ( & V_183 -> V_50 , L_24 ) ;
V_76 = - V_192 ;
goto V_204;
}
V_2 -> V_111 = V_185 -> V_205 ;
V_2 -> V_4 = F_75 ( & V_183 -> V_50 , V_185 ) ;
if ( F_76 ( V_2 -> V_4 ) ) {
V_76 = F_77 ( V_2 -> V_4 ) ;
goto V_204;
}
V_186 = F_78 ( V_183 , 0 ) ;
V_2 -> V_171 = V_186 ;
V_76 = F_79 ( V_2 -> V_171 , F_65 ,
F_64 , V_206 ,
F_80 ( & V_183 -> V_50 ) , V_2 ) ;
if ( V_76 < 0 ) {
F_23 ( & V_183 -> V_50 , L_25 ,
V_2 -> V_171 ) ;
goto V_204;
}
V_2 -> V_125 = F_81 ( & V_183 -> V_50 , NULL ) ;
if ( F_76 ( V_2 -> V_125 ) ) {
F_23 ( & V_183 -> V_50 , L_26 ) ;
V_76 = F_77 ( V_2 -> V_125 ) ;
goto V_207;
}
V_2 -> V_31 = V_134 << 2 ;
V_2 -> V_52 = V_208 ;
if ( V_2 -> V_109 ) {
V_76 = F_33 ( V_2 , true ) ;
if ( V_76 < 0 ) {
F_23 ( & V_183 -> V_50 , L_27 , V_76 ) ;
goto V_207;
}
V_76 = F_33 ( V_2 , false ) ;
if ( V_76 < 0 ) {
F_23 ( & V_183 -> V_50 , L_28 , V_76 ) ;
goto V_209;
}
V_2 -> V_31 = V_2 -> V_52 ;
F_82 ( & V_2 -> V_62 ) ;
F_82 ( & V_2 -> V_71 ) ;
}
F_82 ( & V_2 -> V_162 ) ;
F_83 ( & V_183 -> V_50 ) ;
if ( ! F_84 ( & V_183 -> V_50 ) ) {
V_76 = F_85 ( & V_183 -> V_50 ) ;
if ( V_76 )
goto V_210;
}
V_76 = F_49 ( & V_183 -> V_50 ) ;
if ( V_76 < 0 ) {
F_23 ( & V_183 -> V_50 , L_29 , V_76 ) ;
goto V_210;
}
V_2 -> V_149 = V_211 ;
V_2 -> V_156 = V_212 ;
F_3 ( V_2 , V_2 -> V_149 , V_132 ) ;
F_3 ( V_2 , V_2 -> V_156 , V_133 ) ;
F_52 ( & V_183 -> V_50 ) ;
V_119 -> V_50 . V_180 = V_183 -> V_50 . V_180 ;
V_76 = F_86 ( & V_183 -> V_50 , V_119 ) ;
if ( V_76 < 0 ) {
F_23 ( & V_183 -> V_50 , L_30 , V_76 ) ;
goto V_210;
}
return V_76 ;
V_210:
F_87 ( & V_183 -> V_50 ) ;
if ( ! F_88 ( & V_183 -> V_50 ) )
F_89 ( & V_183 -> V_50 ) ;
F_41 ( V_2 , false ) ;
V_209:
F_41 ( V_2 , true ) ;
V_207:
F_90 ( V_186 , V_2 ) ;
V_204:
F_91 ( V_119 ) ;
return V_76 ;
}
static int F_92 ( struct V_182 * V_183 )
{
struct V_151 * V_119 = F_93 ( V_183 ) ;
struct V_1 * V_2 = F_43 ( V_119 ) ;
F_90 ( V_2 -> V_171 , V_2 ) ;
if ( V_2 -> V_64 )
F_41 ( V_2 , false ) ;
if ( V_2 -> V_73 )
F_41 ( V_2 , true ) ;
F_87 ( & V_183 -> V_50 ) ;
if ( ! F_88 ( & V_183 -> V_50 ) )
F_89 ( & V_183 -> V_50 ) ;
return 0 ;
}
static int F_94 ( struct V_213 * V_50 )
{
struct V_151 * V_119 = F_95 ( V_50 ) ;
return F_96 ( V_119 ) ;
}
static int F_97 ( struct V_213 * V_50 )
{
struct V_151 * V_119 = F_95 ( V_50 ) ;
struct V_1 * V_2 = F_43 ( V_119 ) ;
int V_76 ;
V_76 = F_49 ( V_50 ) ;
if ( V_76 < 0 ) {
F_23 ( V_50 , L_11 , V_76 ) ;
return V_76 ;
}
F_3 ( V_2 , V_2 -> V_128 , V_132 ) ;
F_3 ( V_2 , V_2 -> V_129 , V_133 ) ;
F_52 ( V_50 ) ;
return F_98 ( V_119 ) ;
}
static int F_89 ( struct V_213 * V_50 )
{
struct V_151 * V_119 = F_95 ( V_50 ) ;
struct V_1 * V_2 = F_43 ( V_119 ) ;
F_1 ( V_2 , V_7 ) ;
F_99 ( V_2 -> V_125 ) ;
return 0 ;
}
static int F_85 ( struct V_213 * V_50 )
{
struct V_151 * V_119 = F_95 ( V_50 ) ;
struct V_1 * V_2 = F_43 ( V_119 ) ;
int V_76 ;
V_76 = F_100 ( V_2 -> V_125 ) ;
if ( V_76 < 0 ) {
F_23 ( V_2 -> V_50 , L_31 , V_76 ) ;
return V_76 ;
}
return 0 ;
}
