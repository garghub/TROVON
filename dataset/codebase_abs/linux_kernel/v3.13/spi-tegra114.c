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
V_5 = F_1 ( V_2 , V_8 ) ;
F_3 ( V_2 , V_5 , V_8 ) ;
V_5 = F_1 ( V_2 , V_9 ) ;
if ( V_5 & V_10 )
F_3 ( V_2 , V_10 | V_11 ,
V_9 ) ;
}
static unsigned F_6 (
struct V_12 * V_13 , struct V_1 * V_2 ,
struct V_14 * V_15 )
{
unsigned V_16 = V_15 -> V_17 - V_2 -> V_18 ;
unsigned V_19 ;
unsigned V_20 = V_15 -> V_20 ;
unsigned V_21 ;
unsigned V_22 ;
V_2 -> V_23 = F_7 ( V_20 , 8 ) ;
if ( V_20 == 8 || V_20 == 16 ) {
V_2 -> V_24 = 1 ;
V_2 -> V_25 = 32 / V_20 ;
} else {
V_2 -> V_24 = 0 ;
V_2 -> V_25 = 1 ;
}
if ( V_2 -> V_24 ) {
V_21 = F_8 ( V_16 , V_2 -> V_26 ) ;
V_2 -> V_27 = V_21 / V_2 -> V_23 ;
V_22 = ( V_21 + 3 ) / 4 ;
} else {
V_19 = ( V_16 - 1 ) / V_2 -> V_23 + 1 ;
V_19 = F_8 ( V_19 , V_2 -> V_26 / 4 ) ;
V_2 -> V_27 = V_19 ;
V_22 = V_19 ;
}
return V_22 ;
}
static unsigned F_9 (
struct V_1 * V_2 , struct V_14 * V_15 )
{
unsigned V_28 ;
unsigned V_29 ;
unsigned long V_30 ;
unsigned V_31 ;
unsigned V_32 , V_33 ;
unsigned long V_34 ;
unsigned int V_35 ;
unsigned V_36 ;
T_1 * V_37 = ( T_1 * ) V_15 -> V_37 + V_2 -> V_38 ;
V_30 = F_1 ( V_2 , V_9 ) ;
V_29 = F_10 ( V_30 ) ;
if ( V_2 -> V_24 ) {
V_36 = V_29 * V_2 -> V_25 ;
V_35 = F_8 ( V_36 , V_2 -> V_27 ) ;
V_28 = V_35 * V_2 -> V_23 ;
V_31 = F_7 ( V_28 , 4 ) ;
for ( V_33 = 0 ; V_33 < V_31 ; V_33 ++ ) {
V_34 = 0 ;
for ( V_32 = 0 ; ( V_32 < 4 ) && V_28 ; V_32 ++ , V_28 -- )
V_34 |= ( * V_37 ++ ) << ( V_32 * 8 ) ;
F_3 ( V_2 , V_34 , V_6 ) ;
}
} else {
V_31 = F_8 ( V_2 -> V_27 , V_29 ) ;
V_35 = V_31 ;
V_28 = V_35 * V_2 -> V_23 ;
for ( V_33 = 0 ; V_33 < V_31 ; V_33 ++ ) {
V_34 = 0 ;
for ( V_32 = 0 ; V_28 && ( V_32 < V_2 -> V_23 ) ;
V_32 ++ , V_28 -- )
V_34 |= ( ( * V_37 ++ ) << V_32 * 8 ) ;
F_3 ( V_2 , V_34 , V_6 ) ;
}
}
V_2 -> V_38 += V_35 * V_2 -> V_23 ;
return V_35 ;
}
static unsigned int F_11 (
struct V_1 * V_2 , struct V_14 * V_15 )
{
unsigned V_39 ;
unsigned long V_30 ;
unsigned V_32 , V_33 ;
unsigned long V_34 ;
unsigned int V_40 = 0 ;
unsigned V_17 ;
T_1 * V_41 = ( T_1 * ) V_15 -> V_41 + V_2 -> V_42 ;
V_30 = F_1 ( V_2 , V_9 ) ;
V_39 = F_12 ( V_30 ) ;
if ( V_2 -> V_24 ) {
V_17 = V_2 -> V_27 * V_2 -> V_23 ;
for ( V_33 = 0 ; V_33 < V_39 ; V_33 ++ ) {
V_34 = F_1 ( V_2 , V_43 ) ;
for ( V_32 = 0 ; V_17 && ( V_32 < 4 ) ; V_32 ++ , V_17 -- )
* V_41 ++ = ( V_34 >> V_32 * 8 ) & 0xFF ;
}
V_2 -> V_42 += V_2 -> V_27 * V_2 -> V_23 ;
V_40 += V_2 -> V_27 ;
} else {
unsigned int V_44 ;
unsigned int V_20 = V_15 -> V_20 ;
V_44 = ( 1 << V_20 ) - 1 ;
for ( V_33 = 0 ; V_33 < V_39 ; V_33 ++ ) {
V_34 = F_1 ( V_2 , V_43 ) ;
V_34 &= V_44 ;
for ( V_32 = 0 ; ( V_32 < V_2 -> V_23 ) ; V_32 ++ )
* V_41 ++ = ( V_34 >> ( V_32 * 8 ) ) & 0xFF ;
}
V_2 -> V_42 += V_39 * V_2 -> V_23 ;
V_40 += V_39 ;
}
return V_40 ;
}
static void F_13 (
struct V_1 * V_2 , struct V_14 * V_15 )
{
unsigned V_17 ;
F_14 ( V_2 -> V_45 , V_2 -> V_46 ,
V_2 -> V_47 , V_48 ) ;
if ( V_2 -> V_24 ) {
V_17 = V_2 -> V_27 * V_2 -> V_23 ;
memcpy ( V_2 -> V_49 , V_15 -> V_37 + V_2 -> V_18 , V_17 ) ;
} else {
unsigned int V_32 ;
unsigned int V_33 ;
T_1 * V_37 = ( T_1 * ) V_15 -> V_37 + V_2 -> V_38 ;
unsigned V_50 = V_2 -> V_27 * V_2 -> V_23 ;
unsigned int V_34 ;
for ( V_33 = 0 ; V_33 < V_2 -> V_27 ; V_33 ++ ) {
V_34 = 0 ;
for ( V_32 = 0 ; V_50 && ( V_32 < V_2 -> V_23 ) ;
V_32 ++ , V_50 -- )
V_34 |= ( ( * V_37 ++ ) << V_32 * 8 ) ;
V_2 -> V_49 [ V_33 ] = V_34 ;
}
}
V_2 -> V_38 += V_2 -> V_27 * V_2 -> V_23 ;
F_15 ( V_2 -> V_45 , V_2 -> V_46 ,
V_2 -> V_47 , V_48 ) ;
}
static void F_16 (
struct V_1 * V_2 , struct V_14 * V_15 )
{
unsigned V_17 ;
F_14 ( V_2 -> V_45 , V_2 -> V_51 ,
V_2 -> V_47 , V_52 ) ;
if ( V_2 -> V_24 ) {
V_17 = V_2 -> V_27 * V_2 -> V_23 ;
memcpy ( V_15 -> V_41 + V_2 -> V_42 , V_2 -> V_53 , V_17 ) ;
} else {
unsigned int V_32 ;
unsigned int V_33 ;
unsigned char * V_41 = V_15 -> V_41 + V_2 -> V_42 ;
unsigned int V_34 ;
unsigned int V_44 ;
unsigned int V_20 = V_15 -> V_20 ;
V_44 = ( 1 << V_20 ) - 1 ;
for ( V_33 = 0 ; V_33 < V_2 -> V_27 ; V_33 ++ ) {
V_34 = V_2 -> V_53 [ V_33 ] ;
V_34 &= V_44 ;
for ( V_32 = 0 ; ( V_32 < V_2 -> V_23 ) ; V_32 ++ )
* V_41 ++ = ( V_34 >> ( V_32 * 8 ) ) & 0xFF ;
}
}
V_2 -> V_42 += V_2 -> V_27 * V_2 -> V_23 ;
F_15 ( V_2 -> V_45 , V_2 -> V_51 ,
V_2 -> V_47 , V_52 ) ;
}
static void F_17 ( void * args )
{
struct V_54 * V_55 = args ;
F_18 ( V_55 ) ;
}
static int F_19 ( struct V_1 * V_2 , int V_17 )
{
F_20 ( & V_2 -> V_56 ) ;
V_2 -> V_57 = F_21 ( V_2 -> V_58 ,
V_2 -> V_46 , V_17 , V_59 ,
V_60 | V_61 ) ;
if ( ! V_2 -> V_57 ) {
F_22 ( V_2 -> V_45 , L_1 ) ;
return - V_62 ;
}
V_2 -> V_57 -> V_63 = F_17 ;
V_2 -> V_57 -> V_64 = & V_2 -> V_56 ;
F_23 ( V_2 -> V_57 ) ;
F_24 ( V_2 -> V_58 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , int V_17 )
{
F_20 ( & V_2 -> V_65 ) ;
V_2 -> V_66 = F_21 ( V_2 -> V_67 ,
V_2 -> V_51 , V_17 , V_68 ,
V_60 | V_61 ) ;
if ( ! V_2 -> V_66 ) {
F_22 ( V_2 -> V_45 , L_2 ) ;
return - V_62 ;
}
V_2 -> V_66 -> V_63 = F_17 ;
V_2 -> V_66 -> V_64 = & V_2 -> V_65 ;
F_23 ( V_2 -> V_66 ) ;
F_24 ( V_2 -> V_67 ) ;
return 0 ;
}
static int F_26 (
struct V_1 * V_2 , struct V_14 * V_15 )
{
unsigned long V_5 ;
unsigned int V_17 ;
int V_69 = 0 ;
unsigned long V_70 ;
V_70 = F_1 ( V_2 , V_9 ) ;
if ( ( V_70 & V_71 ) != V_71 ) {
F_22 ( V_2 -> V_45 ,
L_3 , V_70 ) ;
return - V_62 ;
}
V_5 = F_27 ( V_2 -> V_27 - 1 ) ;
F_3 ( V_2 , V_5 , V_72 ) ;
if ( V_2 -> V_24 )
V_17 = F_7 ( V_2 -> V_27 * V_2 -> V_23 ,
4 ) * 4 ;
else
V_17 = V_2 -> V_27 * 4 ;
if ( V_17 & 0xF )
V_5 |= V_73 | V_74 ;
else if ( ( ( V_17 ) >> 4 ) & 0x1 )
V_5 |= V_75 | V_76 ;
else
V_5 |= V_77 | V_78 ;
if ( V_2 -> V_79 & V_80 )
V_5 |= V_81 ;
if ( V_2 -> V_79 & V_82 )
V_5 |= V_83 ;
F_3 ( V_2 , V_5 , V_84 ) ;
V_2 -> V_85 = V_5 ;
if ( V_2 -> V_79 & V_80 ) {
F_13 ( V_2 , V_15 ) ;
V_69 = F_19 ( V_2 , V_17 ) ;
if ( V_69 < 0 ) {
F_22 ( V_2 -> V_45 ,
L_4 , V_69 ) ;
return V_69 ;
}
}
if ( V_2 -> V_79 & V_82 ) {
F_15 ( V_2 -> V_45 , V_2 -> V_51 ,
V_2 -> V_47 , V_52 ) ;
V_69 = F_25 ( V_2 , V_17 ) ;
if ( V_69 < 0 ) {
F_22 ( V_2 -> V_45 ,
L_5 , V_69 ) ;
if ( V_2 -> V_79 & V_80 )
F_28 ( V_2 -> V_58 ) ;
return V_69 ;
}
}
V_2 -> V_86 = true ;
V_2 -> V_85 = V_5 ;
V_5 |= V_87 ;
F_3 ( V_2 , V_5 , V_84 ) ;
return V_69 ;
}
static int F_29 (
struct V_1 * V_2 , struct V_14 * V_15 )
{
unsigned long V_5 ;
unsigned V_88 ;
if ( V_2 -> V_79 & V_80 )
V_88 = F_9 ( V_2 , V_15 ) ;
else
V_88 = V_2 -> V_27 ;
V_5 = F_27 ( V_88 - 1 ) ;
F_3 ( V_2 , V_5 , V_72 ) ;
V_5 = 0 ;
if ( V_2 -> V_79 & V_80 )
V_5 |= V_81 ;
if ( V_2 -> V_79 & V_82 )
V_5 |= V_83 ;
F_3 ( V_2 , V_5 , V_84 ) ;
V_2 -> V_85 = V_5 ;
V_2 -> V_86 = false ;
V_5 |= V_87 ;
F_3 ( V_2 , V_5 , V_84 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
bool V_89 )
{
struct V_90 * V_90 ;
T_2 * V_91 ;
T_3 V_92 ;
int V_69 ;
struct V_93 V_94 ;
T_4 V_95 ;
F_31 ( V_95 ) ;
F_32 ( V_96 , V_95 ) ;
V_90 = F_33 ( V_95 , NULL , NULL ) ;
if ( ! V_90 ) {
F_22 ( V_2 -> V_45 ,
L_6 ) ;
return - V_97 ;
}
V_91 = F_34 ( V_2 -> V_45 , V_2 -> V_47 ,
& V_92 , V_98 ) ;
if ( ! V_91 ) {
F_22 ( V_2 -> V_45 , L_7 ) ;
F_35 ( V_90 ) ;
return - V_99 ;
}
V_94 . V_100 = V_2 -> V_101 ;
if ( V_89 ) {
V_94 . V_102 = V_2 -> V_103 + V_43 ;
V_94 . V_104 = V_105 ;
V_94 . V_106 = 0 ;
} else {
V_94 . V_107 = V_2 -> V_103 + V_6 ;
V_94 . V_108 = V_105 ;
V_94 . V_109 = 0 ;
}
V_69 = F_36 ( V_90 , & V_94 ) ;
if ( V_69 )
goto V_110;
if ( V_89 ) {
V_2 -> V_67 = V_90 ;
V_2 -> V_53 = V_91 ;
V_2 -> V_51 = V_92 ;
} else {
V_2 -> V_58 = V_90 ;
V_2 -> V_49 = V_91 ;
V_2 -> V_46 = V_92 ;
}
return 0 ;
V_110:
F_37 ( V_2 -> V_45 , V_2 -> V_47 , V_91 , V_92 ) ;
F_35 ( V_90 ) ;
return V_69 ;
}
static void F_38 ( struct V_1 * V_2 ,
bool V_89 )
{
T_2 * V_91 ;
T_3 V_92 ;
struct V_90 * V_90 ;
if ( V_89 ) {
V_91 = V_2 -> V_53 ;
V_90 = V_2 -> V_67 ;
V_92 = V_2 -> V_51 ;
V_2 -> V_67 = NULL ;
V_2 -> V_53 = NULL ;
} else {
V_91 = V_2 -> V_49 ;
V_90 = V_2 -> V_58 ;
V_92 = V_2 -> V_46 ;
V_2 -> V_49 = NULL ;
V_2 -> V_58 = NULL ;
}
if ( ! V_90 )
return;
F_37 ( V_2 -> V_45 , V_2 -> V_47 , V_91 , V_92 ) ;
F_35 ( V_90 ) ;
}
static unsigned long F_39 ( struct V_12 * V_13 ,
struct V_14 * V_15 , bool V_111 )
{
struct V_1 * V_2 = F_40 ( V_13 -> V_112 ) ;
T_2 V_113 = V_15 -> V_114 ;
T_1 V_20 = V_15 -> V_20 ;
unsigned long V_115 ;
int V_116 ;
if ( V_113 != V_2 -> V_117 ) {
F_41 ( V_2 -> V_118 , V_113 ) ;
V_2 -> V_117 = V_113 ;
}
V_2 -> V_119 = V_13 ;
V_2 -> V_18 = 0 ;
V_2 -> V_42 = 0 ;
V_2 -> V_38 = 0 ;
V_2 -> V_120 = V_15 ;
if ( V_111 ) {
F_5 ( V_2 ) ;
V_115 = V_2 -> V_121 ;
V_115 |= F_42 ( V_20 - 1 ) ;
V_115 &= ~ V_122 ;
V_116 = V_13 -> V_123 & 0x3 ;
if ( V_116 == V_124 )
V_115 |= V_125 ;
else if ( V_116 == V_126 )
V_115 |= V_127 ;
else if ( V_116 == V_128 )
V_115 |= V_129 ;
else if ( V_116 == V_130 )
V_115 |= V_131 ;
if ( V_2 -> V_132 ) {
if ( V_2 -> V_132 != V_13 )
F_3 ( V_2 , V_115 , V_7 ) ;
V_2 -> V_132 = NULL ;
} else
F_3 ( V_2 , V_115 , V_7 ) ;
V_115 |= V_133 ;
if ( V_13 -> V_123 & V_134 )
V_115 |= V_135 ;
else
V_115 &= ~ V_135 ;
F_3 ( V_2 , 0 , V_136 ) ;
} else {
V_115 = V_2 -> V_137 ;
V_115 &= ~ F_42 ( ~ 0 ) ;
V_115 |= F_42 ( V_20 - 1 ) ;
}
return V_115 ;
}
static int F_43 ( struct V_12 * V_13 ,
struct V_14 * V_15 , unsigned long V_115 )
{
struct V_1 * V_2 = F_40 ( V_13 -> V_112 ) ;
unsigned V_22 ;
int V_69 ;
V_22 = F_6 ( V_13 , V_2 , V_15 ) ;
if ( V_2 -> V_24 )
V_115 |= V_138 ;
V_115 &= ~ ( V_139 | V_140 | V_141 ) ;
V_2 -> V_79 = 0 ;
if ( V_15 -> V_41 ) {
V_115 |= V_141 ;
V_2 -> V_79 |= V_82 ;
}
if ( V_15 -> V_37 ) {
V_115 |= V_140 ;
V_2 -> V_79 |= V_80 ;
}
V_115 |= F_44 ( V_13 -> V_142 ) ;
F_3 ( V_2 , V_115 , V_7 ) ;
V_2 -> V_137 = V_115 ;
F_45 ( V_2 -> V_45 , L_8 ,
V_2 -> V_121 , V_115 ) ;
if ( V_22 > V_143 )
V_69 = F_26 ( V_2 , V_15 ) ;
else
V_69 = F_29 ( V_2 , V_15 ) ;
return V_69 ;
}
static int F_46 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_40 ( V_13 -> V_112 ) ;
unsigned long V_5 ;
unsigned long V_144 ;
int V_69 ;
unsigned int V_145 [ V_146 ] = {
V_147 ,
V_148 ,
V_149 ,
V_150 ,
} ;
F_45 ( & V_13 -> V_45 , L_9 ,
V_13 -> V_20 ,
V_13 -> V_123 & V_151 ? L_10 : L_11 ,
V_13 -> V_123 & V_152 ? L_10 : L_11 ,
V_13 -> V_153 ) ;
F_47 ( V_13 -> V_142 >= V_146 ) ;
V_13 -> V_153 = V_13 -> V_153 ? : V_2 -> V_154 ;
V_69 = F_48 ( V_2 -> V_45 ) ;
if ( V_69 < 0 ) {
F_22 ( V_2 -> V_45 , L_12 , V_69 ) ;
return V_69 ;
}
F_49 ( & V_2 -> V_155 , V_144 ) ;
V_5 = V_2 -> V_121 ;
if ( V_13 -> V_123 & V_134 )
V_5 &= ~ V_145 [ V_13 -> V_142 ] ;
else
V_5 |= V_145 [ V_13 -> V_142 ] ;
V_2 -> V_121 = V_5 ;
F_3 ( V_2 , V_2 -> V_121 , V_7 ) ;
F_50 ( & V_2 -> V_155 , V_144 ) ;
F_51 ( V_2 -> V_45 ) ;
return 0 ;
}
static void F_52 ( int V_156 )
{
if ( ! V_156 )
return;
if ( V_156 >= 1000 )
F_53 ( V_156 / 1000 ) ;
F_54 ( V_156 % 1000 ) ;
}
static int F_55 ( struct V_157 * V_112 ,
struct V_158 * V_159 )
{
bool V_160 = true ;
struct V_1 * V_2 = F_40 ( V_112 ) ;
struct V_14 * V_161 ;
struct V_12 * V_13 = V_159 -> V_13 ;
int V_69 ;
bool V_162 = false ;
V_159 -> V_70 = 0 ;
V_159 -> V_163 = 0 ;
F_56 (xfer, &msg->transfers, transfer_list) {
unsigned long V_164 ;
F_20 ( & V_2 -> V_165 ) ;
V_164 = F_39 ( V_13 , V_161 , V_160 ) ;
if ( ! V_161 -> V_17 ) {
V_69 = 0 ;
V_162 = true ;
goto V_166;
}
V_69 = F_43 ( V_13 , V_161 , V_164 ) ;
if ( V_69 < 0 ) {
F_22 ( V_2 -> V_45 ,
L_13 , V_69 ) ;
goto V_166;
}
V_160 = false ;
V_69 = F_57 ( & V_2 -> V_165 ,
V_167 ) ;
if ( F_58 ( V_69 == 0 ) ) {
F_22 ( V_2 -> V_45 ,
L_14 , V_69 ) ;
V_69 = - V_62 ;
goto V_166;
}
if ( V_2 -> V_168 || V_2 -> V_169 ) {
F_22 ( V_2 -> V_45 , L_15 ) ;
V_69 = - V_62 ;
goto V_166;
}
V_159 -> V_163 += V_161 -> V_17 ;
V_166:
if ( V_69 < 0 || V_162 ) {
F_3 ( V_2 , V_2 -> V_121 ,
V_7 ) ;
F_52 ( V_161 -> V_170 ) ;
goto exit;
} else if ( V_159 -> V_171 . V_172 == & V_161 -> V_173 ) {
if ( V_161 -> V_174 )
V_2 -> V_132 = V_13 ;
else {
F_3 ( V_2 , V_2 -> V_121 ,
V_7 ) ;
F_52 ( V_161 -> V_170 ) ;
}
} else if ( V_161 -> V_174 ) {
F_3 ( V_2 , V_2 -> V_121 ,
V_7 ) ;
F_52 ( V_161 -> V_170 ) ;
}
}
V_69 = 0 ;
exit:
V_159 -> V_70 = V_69 ;
F_59 ( V_112 ) ;
return V_69 ;
}
static T_5 F_60 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_120 ;
unsigned long V_144 ;
F_49 ( & V_2 -> V_155 , V_144 ) ;
if ( V_2 -> V_168 || V_2 -> V_169 ) {
F_22 ( V_2 -> V_45 , L_16 ,
V_2 -> V_175 ) ;
F_22 ( V_2 -> V_45 , L_17 ,
V_2 -> V_137 , V_2 -> V_85 ) ;
F_61 ( V_2 -> V_118 ) ;
F_54 ( 2 ) ;
F_62 ( V_2 -> V_118 ) ;
F_18 ( & V_2 -> V_165 ) ;
goto exit;
}
if ( V_2 -> V_79 & V_82 )
F_11 ( V_2 , V_15 ) ;
if ( V_2 -> V_79 & V_80 )
V_2 -> V_18 = V_2 -> V_38 ;
else
V_2 -> V_18 = V_2 -> V_42 ;
if ( V_2 -> V_18 == V_15 -> V_17 ) {
F_18 ( & V_2 -> V_165 ) ;
goto exit;
}
F_6 ( V_2 -> V_119 , V_2 , V_15 ) ;
F_29 ( V_2 , V_15 ) ;
exit:
F_50 ( & V_2 -> V_155 , V_144 ) ;
return V_176 ;
}
static T_5 F_63 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_120 ;
long V_177 ;
int V_178 = 0 ;
unsigned V_22 ;
unsigned long V_144 ;
if ( V_2 -> V_79 & V_80 ) {
if ( V_2 -> V_168 ) {
F_28 ( V_2 -> V_58 ) ;
V_178 += 1 ;
} else {
V_177 = F_64 (
& V_2 -> V_56 , V_167 ) ;
if ( V_177 <= 0 ) {
F_28 ( V_2 -> V_58 ) ;
F_22 ( V_2 -> V_45 , L_18 ) ;
V_178 += 1 ;
}
}
}
if ( V_2 -> V_79 & V_82 ) {
if ( V_2 -> V_169 ) {
F_28 ( V_2 -> V_67 ) ;
V_178 += 2 ;
} else {
V_177 = F_64 (
& V_2 -> V_65 , V_167 ) ;
if ( V_177 <= 0 ) {
F_28 ( V_2 -> V_67 ) ;
F_22 ( V_2 -> V_45 , L_19 ) ;
V_178 += 2 ;
}
}
}
F_49 ( & V_2 -> V_155 , V_144 ) ;
if ( V_178 ) {
F_22 ( V_2 -> V_45 , L_20 ,
V_2 -> V_175 ) ;
F_22 ( V_2 -> V_45 , L_21 ,
V_2 -> V_137 , V_2 -> V_85 ) ;
F_61 ( V_2 -> V_118 ) ;
F_54 ( 2 ) ;
F_62 ( V_2 -> V_118 ) ;
F_18 ( & V_2 -> V_165 ) ;
F_50 ( & V_2 -> V_155 , V_144 ) ;
return V_176 ;
}
if ( V_2 -> V_79 & V_82 )
F_16 ( V_2 , V_15 ) ;
if ( V_2 -> V_79 & V_80 )
V_2 -> V_18 = V_2 -> V_38 ;
else
V_2 -> V_18 = V_2 -> V_42 ;
if ( V_2 -> V_18 == V_15 -> V_17 ) {
F_18 ( & V_2 -> V_165 ) ;
goto exit;
}
V_22 = F_6 ( V_2 -> V_119 ,
V_2 , V_15 ) ;
if ( V_22 > V_143 )
V_178 = F_26 ( V_2 , V_15 ) ;
else
V_178 = F_29 ( V_2 , V_15 ) ;
exit:
F_50 ( & V_2 -> V_155 , V_144 ) ;
return V_176 ;
}
static T_5 F_65 ( int V_179 , void * V_180 )
{
struct V_1 * V_2 = V_180 ;
if ( ! V_2 -> V_86 )
return F_60 ( V_2 ) ;
return F_63 ( V_2 ) ;
}
static T_5 F_66 ( int V_179 , void * V_180 )
{
struct V_1 * V_2 = V_180 ;
V_2 -> V_175 = F_1 ( V_2 , V_9 ) ;
if ( V_2 -> V_79 & V_80 )
V_2 -> V_168 = V_2 -> V_175 &
( V_181 | V_182 ) ;
if ( V_2 -> V_79 & V_82 )
V_2 -> V_169 = V_2 -> V_175 &
( V_183 | V_184 ) ;
F_5 ( V_2 ) ;
return V_185 ;
}
static void F_67 ( struct V_186 * V_187 ,
struct V_1 * V_2 )
{
struct V_188 * V_189 = V_187 -> V_45 . V_190 ;
T_2 V_191 [ 2 ] ;
if ( F_68 ( V_189 , L_22 ,
V_191 , 2 ) >= 0 )
V_2 -> V_101 = V_191 [ 1 ] ;
if ( F_69 ( V_189 , L_23 ,
& V_2 -> V_154 ) )
V_2 -> V_154 = 25000000 ;
}
static int F_70 ( struct V_186 * V_187 )
{
struct V_157 * V_112 ;
struct V_1 * V_2 ;
struct V_192 * V_193 ;
int V_69 , V_194 ;
V_112 = F_71 ( & V_187 -> V_45 , sizeof( * V_2 ) ) ;
if ( ! V_112 ) {
F_22 ( & V_187 -> V_45 , L_24 ) ;
return - V_99 ;
}
F_72 ( V_187 , V_112 ) ;
V_2 = F_40 ( V_112 ) ;
F_67 ( V_187 , V_2 ) ;
V_112 -> V_195 = V_151 | V_152 | V_134 ;
V_112 -> V_196 = F_46 ;
V_112 -> V_197 = F_55 ;
V_112 -> V_198 = V_146 ;
V_112 -> V_199 = - 1 ;
V_112 -> V_200 = true ;
V_2 -> V_112 = V_112 ;
V_2 -> V_45 = & V_187 -> V_45 ;
F_73 ( & V_2 -> V_155 ) ;
V_193 = F_74 ( V_187 , V_201 , 0 ) ;
V_2 -> V_4 = F_75 ( & V_187 -> V_45 , V_193 ) ;
if ( F_76 ( V_2 -> V_4 ) ) {
V_69 = F_77 ( V_2 -> V_4 ) ;
goto V_202;
}
V_2 -> V_103 = V_193 -> V_203 ;
V_194 = F_78 ( V_187 , 0 ) ;
V_2 -> V_179 = V_194 ;
V_69 = F_79 ( V_2 -> V_179 , F_66 ,
F_65 , V_204 ,
F_80 ( & V_187 -> V_45 ) , V_2 ) ;
if ( V_69 < 0 ) {
F_22 ( & V_187 -> V_45 , L_25 ,
V_2 -> V_179 ) ;
goto V_202;
}
V_2 -> V_118 = F_81 ( & V_187 -> V_45 , L_26 ) ;
if ( F_76 ( V_2 -> V_118 ) ) {
F_22 ( & V_187 -> V_45 , L_27 ) ;
V_69 = F_77 ( V_2 -> V_118 ) ;
goto V_205;
}
V_2 -> V_26 = V_143 << 2 ;
V_2 -> V_47 = V_206 ;
if ( V_2 -> V_101 ) {
V_69 = F_30 ( V_2 , true ) ;
if ( V_69 < 0 ) {
F_22 ( & V_187 -> V_45 , L_28 , V_69 ) ;
goto V_205;
}
V_69 = F_30 ( V_2 , false ) ;
if ( V_69 < 0 ) {
F_22 ( & V_187 -> V_45 , L_29 , V_69 ) ;
goto V_207;
}
V_2 -> V_26 = V_2 -> V_47 ;
F_82 ( & V_2 -> V_56 ) ;
F_82 ( & V_2 -> V_65 ) ;
}
F_82 ( & V_2 -> V_165 ) ;
F_83 ( & V_187 -> V_45 ) ;
if ( ! F_84 ( & V_187 -> V_45 ) ) {
V_69 = F_85 ( & V_187 -> V_45 ) ;
if ( V_69 )
goto V_208;
}
V_69 = F_48 ( & V_187 -> V_45 ) ;
if ( V_69 < 0 ) {
F_22 ( & V_187 -> V_45 , L_30 , V_69 ) ;
goto V_208;
}
V_2 -> V_121 = V_209 ;
F_3 ( V_2 , V_2 -> V_121 , V_7 ) ;
F_51 ( & V_187 -> V_45 ) ;
V_112 -> V_45 . V_190 = V_187 -> V_45 . V_190 ;
V_69 = F_86 ( & V_187 -> V_45 , V_112 ) ;
if ( V_69 < 0 ) {
F_22 ( & V_187 -> V_45 , L_31 , V_69 ) ;
goto V_208;
}
return V_69 ;
V_208:
F_87 ( & V_187 -> V_45 ) ;
if ( ! F_88 ( & V_187 -> V_45 ) )
F_89 ( & V_187 -> V_45 ) ;
F_38 ( V_2 , false ) ;
V_207:
F_38 ( V_2 , true ) ;
V_205:
F_90 ( V_194 , V_2 ) ;
V_202:
F_91 ( V_112 ) ;
return V_69 ;
}
static int F_92 ( struct V_186 * V_187 )
{
struct V_157 * V_112 = F_93 ( V_187 ) ;
struct V_1 * V_2 = F_40 ( V_112 ) ;
F_90 ( V_2 -> V_179 , V_2 ) ;
if ( V_2 -> V_58 )
F_38 ( V_2 , false ) ;
if ( V_2 -> V_67 )
F_38 ( V_2 , true ) ;
F_87 ( & V_187 -> V_45 ) ;
if ( ! F_88 ( & V_187 -> V_45 ) )
F_89 ( & V_187 -> V_45 ) ;
return 0 ;
}
static int F_94 ( struct V_210 * V_45 )
{
struct V_157 * V_112 = F_95 ( V_45 ) ;
return F_96 ( V_112 ) ;
}
static int F_97 ( struct V_210 * V_45 )
{
struct V_157 * V_112 = F_95 ( V_45 ) ;
struct V_1 * V_2 = F_40 ( V_112 ) ;
int V_69 ;
V_69 = F_48 ( V_45 ) ;
if ( V_69 < 0 ) {
F_22 ( V_45 , L_12 , V_69 ) ;
return V_69 ;
}
F_3 ( V_2 , V_2 -> V_137 , V_7 ) ;
F_51 ( V_45 ) ;
return F_98 ( V_112 ) ;
}
static int F_89 ( struct V_210 * V_45 )
{
struct V_157 * V_112 = F_95 ( V_45 ) ;
struct V_1 * V_2 = F_40 ( V_112 ) ;
F_1 ( V_2 , V_7 ) ;
F_99 ( V_2 -> V_118 ) ;
return 0 ;
}
static int F_85 ( struct V_210 * V_45 )
{
struct V_157 * V_112 = F_95 ( V_45 ) ;
struct V_1 * V_2 = F_40 ( V_112 ) ;
int V_69 ;
V_69 = F_100 ( V_2 -> V_118 ) ;
if ( V_69 < 0 ) {
F_22 ( V_2 -> V_45 , L_32 , V_69 ) ;
return V_69 ;
}
return 0 ;
}
