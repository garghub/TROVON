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
V_2 -> V_14 = ( V_25 - 1 ) / 8 + 1 ;
if ( V_25 == 8 || V_25 == 16 ) {
V_2 -> V_28 = 1 ;
V_2 -> V_29 = 32 / V_25 ;
} else {
V_2 -> V_28 = 0 ;
V_2 -> V_29 = 1 ;
}
V_2 -> V_30 = F_6 ( V_2 , V_13 ) ;
if ( V_2 -> V_28 ) {
V_26 = F_8 ( V_21 , V_2 -> V_31 ) ;
V_2 -> V_32 = V_26 / V_2 -> V_14 ;
V_27 = V_26 / 4 ;
} else {
V_24 = ( V_21 - 1 ) / V_2 -> V_14 + 1 ;
V_24 = F_8 ( V_24 , V_2 -> V_31 / 4 ) ;
V_2 -> V_32 = V_24 ;
V_27 = V_24 ;
}
return V_27 ;
}
static unsigned F_9 (
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
V_34 = F_10 ( V_35 ) ;
if ( V_2 -> V_28 ) {
V_41 = V_34 * V_2 -> V_29 ;
V_40 = F_8 ( V_41 , V_2 -> V_32 ) ;
V_33 = V_40 * V_2 -> V_14 ;
V_36 = F_11 ( V_33 , 4 ) ;
for ( V_38 = 0 ; V_38 < V_36 ; V_38 ++ ) {
V_39 = 0 ;
for ( V_37 = 0 ; ( V_37 < 4 ) && V_33 ; V_37 ++ , V_33 -- )
V_39 |= ( * V_42 ++ ) << ( V_37 * 8 ) ;
F_3 ( V_2 , V_39 , V_6 ) ;
}
} else {
V_36 = F_8 ( V_2 -> V_32 , V_34 ) ;
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
F_21 ( V_2 -> V_62 ) ;
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
F_21 ( V_2 -> V_71 ) ;
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
V_22 = F_11 ( V_2 -> V_32 * V_2 -> V_14 ,
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
V_96 = F_9 ( V_2 , V_13 ) ;
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
struct V_12 * V_13 , bool V_119 ,
bool V_120 )
{
struct V_1 * V_2 = F_43 ( V_20 -> V_121 ) ;
T_2 V_122 ;
T_1 V_25 ;
unsigned V_27 ;
int V_76 ;
unsigned long V_123 ;
unsigned long V_124 ;
V_25 = V_13 -> V_25 ;
V_122 = V_13 -> V_125 ;
if ( V_122 != V_2 -> V_126 ) {
F_44 ( V_2 -> V_127 , V_122 * 4 ) ;
V_2 -> V_126 = V_122 ;
}
V_2 -> V_128 = V_20 ;
V_2 -> V_23 = 0 ;
V_2 -> V_48 = 0 ;
V_2 -> V_43 = 0 ;
V_2 -> V_129 = V_13 ;
V_27 = F_7 ( V_20 , V_2 , V_13 ) ;
if ( V_119 ) {
F_5 ( V_2 ) ;
V_123 = V_2 -> V_130 ;
V_123 |= F_45 ( V_25 - 1 ) ;
V_123 |= V_131 | V_132 ;
V_124 = V_2 -> V_133 ;
V_124 |= F_46 ( V_20 -> V_134 ) ;
V_123 &= ~ V_135 ;
if ( V_20 -> V_136 & V_137 )
V_123 |= V_138 ;
if ( V_20 -> V_136 & V_139 )
V_123 |= V_140 ;
else
V_123 |= V_141 ;
} else {
V_123 = V_2 -> V_142 ;
V_123 &= ~ F_45 ( ~ 0 ) ;
V_123 |= F_45 ( V_25 - 1 ) ;
V_124 = V_2 -> V_143 ;
V_124 &= ~ ( V_144 | V_145 ) ;
}
F_3 ( V_2 , V_123 , V_146 ) ;
V_2 -> V_142 = V_123 ;
V_2 -> V_85 = 0 ;
if ( V_13 -> V_47 ) {
V_124 |= V_144 ;
V_2 -> V_85 |= V_88 ;
}
if ( V_13 -> V_42 ) {
V_124 |= V_145 ;
V_2 -> V_85 |= V_86 ;
}
F_3 ( V_2 , V_124 , V_147 ) ;
V_2 -> V_143 = V_124 ;
if ( V_27 > V_148 )
V_76 = F_27 ( V_2 , V_13 ) ;
else
V_76 = F_32 ( V_2 , V_13 ) ;
return V_76 ;
}
static int F_47 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_43 ( V_20 -> V_121 ) ;
unsigned long V_5 ;
unsigned long V_149 ;
int V_76 ;
unsigned int V_150 [ V_151 ] = {
V_152 ,
V_153 ,
V_154 ,
V_155 ,
} ;
F_48 ( & V_20 -> V_50 , L_8 ,
V_20 -> V_25 ,
V_20 -> V_136 & V_139 ? L_9 : L_10 ,
V_20 -> V_136 & V_137 ? L_9 : L_10 ,
V_20 -> V_156 ) ;
F_49 ( V_20 -> V_134 >= V_151 ) ;
V_20 -> V_156 = V_20 -> V_156 ? : V_2 -> V_157 ;
V_76 = F_50 ( V_2 -> V_50 ) ;
if ( V_76 < 0 ) {
F_23 ( V_2 -> V_50 , L_11 , V_76 ) ;
return V_76 ;
}
F_51 ( & V_2 -> V_158 , V_149 ) ;
V_5 = V_2 -> V_130 ;
if ( V_20 -> V_136 & V_159 )
V_5 |= V_150 [ V_20 -> V_134 ] ;
else
V_5 &= ~ V_150 [ V_20 -> V_134 ] ;
V_2 -> V_130 = V_5 ;
F_3 ( V_2 , V_2 -> V_130 , V_146 ) ;
F_52 ( & V_2 -> V_158 , V_149 ) ;
F_53 ( V_2 -> V_50 ) ;
return 0 ;
}
static int F_54 ( struct V_160 * V_121 ,
struct V_161 * V_162 )
{
bool V_163 = true ;
int V_164 ;
struct V_1 * V_2 = F_43 ( V_121 ) ;
struct V_12 * V_165 ;
struct V_19 * V_20 = V_162 -> V_20 ;
int V_76 ;
V_162 -> V_77 = 0 ;
V_162 -> V_166 = 0 ;
V_76 = F_50 ( V_2 -> V_50 ) ;
if ( V_76 < 0 ) {
F_23 ( V_2 -> V_50 , L_12 , V_76 ) ;
goto V_167;
}
V_164 = F_55 ( & V_162 -> V_168 ) ;
F_56 (xfer, &msg->transfers, transfer_list) {
F_21 ( V_2 -> V_169 ) ;
V_76 = F_42 ( V_20 , V_165 ,
V_163 , V_164 ) ;
if ( V_76 < 0 ) {
F_23 ( V_2 -> V_50 ,
L_13 , V_76 ) ;
goto exit;
}
V_163 = false ;
V_76 = F_57 ( & V_2 -> V_169 ,
V_170 ) ;
if ( F_58 ( V_76 == 0 ) ) {
F_23 ( V_2 -> V_50 ,
L_14 , V_76 ) ;
V_76 = - V_68 ;
goto exit;
}
if ( V_2 -> V_171 || V_2 -> V_172 ) {
F_23 ( V_2 -> V_50 , L_15 ) ;
V_76 = - V_68 ;
goto exit;
}
V_162 -> V_166 += V_165 -> V_22 ;
if ( V_165 -> V_173 && V_165 -> V_174 ) {
F_3 ( V_2 , V_2 -> V_130 ,
V_146 ) ;
F_31 ( V_165 -> V_174 ) ;
}
}
V_76 = 0 ;
exit:
F_3 ( V_2 , V_2 -> V_130 , V_146 ) ;
F_3 ( V_2 , V_2 -> V_133 , V_147 ) ;
F_53 ( V_2 -> V_50 ) ;
V_167:
V_162 -> V_77 = V_76 ;
F_59 ( V_121 ) ;
return V_76 ;
}
static T_5 F_60 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_129 ;
unsigned long V_149 ;
F_51 ( & V_2 -> V_158 , V_149 ) ;
if ( V_2 -> V_171 || V_2 -> V_172 ||
( V_2 -> V_175 & V_176 ) ) {
F_23 ( V_2 -> V_50 ,
L_16 , V_2 -> V_175 ) ;
F_23 ( V_2 -> V_50 ,
L_17 , V_2 -> V_142 ,
V_2 -> V_143 , V_2 -> V_91 ) ;
F_61 ( V_2 -> V_127 ) ;
F_31 ( 2 ) ;
F_62 ( V_2 -> V_127 ) ;
F_19 ( & V_2 -> V_169 ) ;
goto exit;
}
if ( V_2 -> V_85 & V_88 )
F_12 ( V_2 , V_13 ) ;
if ( V_2 -> V_85 & V_86 )
V_2 -> V_23 = V_2 -> V_43 ;
else
V_2 -> V_23 = V_2 -> V_48 ;
if ( V_2 -> V_23 == V_13 -> V_22 ) {
F_19 ( & V_2 -> V_169 ) ;
goto exit;
}
F_7 ( V_2 -> V_128 , V_2 , V_13 ) ;
F_32 ( V_2 , V_13 ) ;
exit:
F_52 ( & V_2 -> V_158 , V_149 ) ;
return V_177 ;
}
static T_5 F_63 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_129 ;
long V_178 ;
int V_179 = 0 ;
unsigned V_27 ;
unsigned long V_149 ;
if ( V_2 -> V_85 & V_86 ) {
if ( V_2 -> V_171 ) {
F_30 ( V_2 -> V_64 ) ;
V_179 += 1 ;
} else {
V_178 = F_64 (
& V_2 -> V_62 , V_170 ) ;
if ( V_178 <= 0 ) {
F_30 ( V_2 -> V_64 ) ;
F_23 ( V_2 -> V_50 , L_18 ) ;
V_179 += 1 ;
}
}
}
if ( V_2 -> V_85 & V_88 ) {
if ( V_2 -> V_172 ) {
F_30 ( V_2 -> V_73 ) ;
V_179 += 2 ;
} else {
V_178 = F_64 (
& V_2 -> V_71 , V_170 ) ;
if ( V_178 <= 0 ) {
F_30 ( V_2 -> V_73 ) ;
F_23 ( V_2 -> V_50 , L_19 ) ;
V_179 += 2 ;
}
}
}
F_51 ( & V_2 -> V_158 , V_149 ) ;
if ( V_179 ) {
F_23 ( V_2 -> V_50 ,
L_20 , V_2 -> V_175 ) ;
F_23 ( V_2 -> V_50 ,
L_21 , V_2 -> V_142 ,
V_2 -> V_143 , V_2 -> V_91 ) ;
F_61 ( V_2 -> V_127 ) ;
F_31 ( 2 ) ;
F_62 ( V_2 -> V_127 ) ;
F_19 ( & V_2 -> V_169 ) ;
F_52 ( & V_2 -> V_158 , V_149 ) ;
return V_177 ;
}
if ( V_2 -> V_85 & V_88 )
F_17 ( V_2 , V_13 ) ;
if ( V_2 -> V_85 & V_86 )
V_2 -> V_23 = V_2 -> V_43 ;
else
V_2 -> V_23 = V_2 -> V_48 ;
if ( V_2 -> V_23 == V_13 -> V_22 ) {
F_19 ( & V_2 -> V_169 ) ;
goto exit;
}
V_27 = F_7 ( V_2 -> V_128 ,
V_2 , V_13 ) ;
if ( V_27 > V_148 )
V_179 = F_27 ( V_2 , V_13 ) ;
else
V_179 = F_32 ( V_2 , V_13 ) ;
exit:
F_52 ( & V_2 -> V_158 , V_149 ) ;
return V_177 ;
}
static T_5 F_65 ( int V_180 , void * V_181 )
{
struct V_1 * V_2 = V_181 ;
if ( ! V_2 -> V_93 )
return F_60 ( V_2 ) ;
return F_63 ( V_2 ) ;
}
static T_5 F_66 ( int V_180 , void * V_181 )
{
struct V_1 * V_2 = V_181 ;
V_2 -> V_175 = F_1 ( V_2 , V_9 ) ;
if ( V_2 -> V_85 & V_86 )
V_2 -> V_171 = V_2 -> V_175 &
( V_182 | V_183 ) ;
if ( V_2 -> V_85 & V_88 )
V_2 -> V_172 = V_2 -> V_175 &
( V_184 | V_185 ) ;
F_5 ( V_2 ) ;
return V_186 ;
}
static void F_67 ( struct V_1 * V_2 )
{
struct V_187 * V_188 = V_2 -> V_50 -> V_189 ;
T_2 V_190 [ 2 ] ;
if ( F_68 ( V_188 , L_22 ,
V_190 , 2 ) >= 0 )
V_2 -> V_109 = V_190 [ 1 ] ;
if ( F_69 ( V_188 , L_23 ,
& V_2 -> V_157 ) )
V_2 -> V_157 = 25000000 ;
}
static int F_70 ( struct V_191 * V_192 )
{
struct V_160 * V_121 ;
struct V_1 * V_2 ;
struct V_193 * V_194 ;
int V_76 , V_195 ;
const struct V_196 * V_197 = NULL ;
const struct V_198 * V_199 ;
V_199 = F_71 ( V_200 , & V_192 -> V_50 ) ;
if ( ! V_199 ) {
F_23 ( & V_192 -> V_50 , L_24 ) ;
return - V_201 ;
}
V_197 = V_199 -> V_202 ;
V_121 = F_72 ( & V_192 -> V_50 , sizeof( * V_2 ) ) ;
if ( ! V_121 ) {
F_23 ( & V_192 -> V_50 , L_25 ) ;
return - V_107 ;
}
V_121 -> V_203 = V_139 | V_137 | V_159 ;
V_121 -> V_204 = F_47 ;
V_121 -> V_205 = F_54 ;
V_121 -> V_206 = V_151 ;
V_121 -> V_207 = - 1 ;
F_73 ( & V_192 -> V_50 , V_121 ) ;
V_2 = F_43 ( V_121 ) ;
V_2 -> V_121 = V_121 ;
V_2 -> V_50 = & V_192 -> V_50 ;
V_2 -> V_208 = V_197 ;
F_74 ( & V_2 -> V_158 ) ;
F_67 ( V_2 ) ;
V_194 = F_75 ( V_192 , V_209 , 0 ) ;
if ( ! V_194 ) {
F_23 ( & V_192 -> V_50 , L_26 ) ;
V_76 = - V_201 ;
goto V_210;
}
V_2 -> V_111 = V_194 -> V_211 ;
V_2 -> V_4 = F_76 ( & V_192 -> V_50 , V_194 ) ;
if ( F_77 ( V_2 -> V_4 ) ) {
V_76 = F_78 ( V_2 -> V_4 ) ;
goto V_210;
}
V_195 = F_79 ( V_192 , 0 ) ;
V_2 -> V_180 = V_195 ;
V_76 = F_80 ( V_2 -> V_180 , F_66 ,
F_65 , V_212 ,
F_81 ( & V_192 -> V_50 ) , V_2 ) ;
if ( V_76 < 0 ) {
F_23 ( & V_192 -> V_50 , L_27 ,
V_2 -> V_180 ) ;
goto V_210;
}
V_2 -> V_127 = F_82 ( & V_192 -> V_50 , NULL ) ;
if ( F_77 ( V_2 -> V_127 ) ) {
F_23 ( & V_192 -> V_50 , L_28 ) ;
V_76 = F_78 ( V_2 -> V_127 ) ;
goto V_213;
}
V_2 -> V_31 = V_148 << 2 ;
V_2 -> V_52 = V_214 ;
if ( V_2 -> V_109 ) {
V_76 = F_33 ( V_2 , true ) ;
if ( V_76 < 0 ) {
F_23 ( & V_192 -> V_50 , L_29 , V_76 ) ;
goto V_213;
}
V_76 = F_33 ( V_2 , false ) ;
if ( V_76 < 0 ) {
F_23 ( & V_192 -> V_50 , L_30 , V_76 ) ;
goto V_215;
}
V_2 -> V_31 = V_2 -> V_52 ;
F_83 ( & V_2 -> V_62 ) ;
F_83 ( & V_2 -> V_71 ) ;
}
F_83 ( & V_2 -> V_169 ) ;
F_84 ( & V_192 -> V_50 ) ;
if ( ! F_85 ( & V_192 -> V_50 ) ) {
V_76 = F_86 ( & V_192 -> V_50 ) ;
if ( V_76 )
goto V_216;
}
V_76 = F_50 ( & V_192 -> V_50 ) ;
if ( V_76 < 0 ) {
F_23 ( & V_192 -> V_50 , L_31 , V_76 ) ;
goto V_216;
}
V_2 -> V_130 = V_217 ;
V_2 -> V_133 = V_218 ;
F_3 ( V_2 , V_2 -> V_130 , V_146 ) ;
F_3 ( V_2 , V_2 -> V_133 , V_147 ) ;
F_53 ( & V_192 -> V_50 ) ;
V_121 -> V_50 . V_189 = V_192 -> V_50 . V_189 ;
V_76 = F_87 ( V_121 ) ;
if ( V_76 < 0 ) {
F_23 ( & V_192 -> V_50 , L_32 , V_76 ) ;
goto V_216;
}
return V_76 ;
V_216:
F_88 ( & V_192 -> V_50 ) ;
if ( ! F_89 ( & V_192 -> V_50 ) )
F_90 ( & V_192 -> V_50 ) ;
F_41 ( V_2 , false ) ;
V_215:
F_41 ( V_2 , true ) ;
V_213:
F_91 ( V_195 , V_2 ) ;
V_210:
F_92 ( V_121 ) ;
return V_76 ;
}
static int F_93 ( struct V_191 * V_192 )
{
struct V_160 * V_121 = F_94 ( & V_192 -> V_50 ) ;
struct V_1 * V_2 = F_43 ( V_121 ) ;
F_91 ( V_2 -> V_180 , V_2 ) ;
F_95 ( V_121 ) ;
if ( V_2 -> V_64 )
F_41 ( V_2 , false ) ;
if ( V_2 -> V_73 )
F_41 ( V_2 , true ) ;
F_88 ( & V_192 -> V_50 ) ;
if ( ! F_89 ( & V_192 -> V_50 ) )
F_90 ( & V_192 -> V_50 ) ;
return 0 ;
}
static int F_96 ( struct V_219 * V_50 )
{
struct V_160 * V_121 = F_94 ( V_50 ) ;
return F_97 ( V_121 ) ;
}
static int F_98 ( struct V_219 * V_50 )
{
struct V_160 * V_121 = F_94 ( V_50 ) ;
struct V_1 * V_2 = F_43 ( V_121 ) ;
int V_76 ;
V_76 = F_50 ( V_50 ) ;
if ( V_76 < 0 ) {
F_23 ( V_50 , L_11 , V_76 ) ;
return V_76 ;
}
F_3 ( V_2 , V_2 -> V_142 , V_146 ) ;
F_3 ( V_2 , V_2 -> V_143 , V_147 ) ;
F_53 ( V_50 ) ;
return F_99 ( V_121 ) ;
}
static int F_90 ( struct V_219 * V_50 )
{
struct V_160 * V_121 = F_94 ( V_50 ) ;
struct V_1 * V_2 = F_43 ( V_121 ) ;
F_1 ( V_2 , V_7 ) ;
F_100 ( V_2 -> V_127 ) ;
return 0 ;
}
static int F_86 ( struct V_219 * V_50 )
{
struct V_160 * V_121 = F_94 ( V_50 ) ;
struct V_1 * V_2 = F_43 ( V_121 ) ;
int V_76 ;
V_76 = F_101 ( V_2 -> V_127 ) ;
if ( V_76 < 0 ) {
F_23 ( V_2 -> V_50 , L_33 , V_76 ) ;
return V_76 ;
}
return 0 ;
}
