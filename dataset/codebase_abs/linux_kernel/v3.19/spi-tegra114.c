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
T_1 V_5 ;
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
T_1 V_30 ;
unsigned V_31 ;
unsigned V_32 , V_33 ;
unsigned int V_34 ;
unsigned V_35 ;
T_2 * V_36 = ( T_2 * ) V_15 -> V_36 + V_2 -> V_37 ;
V_30 = F_1 ( V_2 , V_9 ) ;
V_29 = F_10 ( V_30 ) ;
if ( V_2 -> V_24 ) {
V_35 = V_29 * V_2 -> V_25 ;
V_34 = F_8 ( V_35 , V_2 -> V_27 ) ;
V_28 = V_34 * V_2 -> V_23 ;
V_31 = F_7 ( V_28 , 4 ) ;
for ( V_33 = 0 ; V_33 < V_31 ; V_33 ++ ) {
T_1 V_38 = 0 ;
for ( V_32 = 0 ; ( V_32 < 4 ) && V_28 ; V_32 ++ , V_28 -- )
V_38 |= ( T_1 ) ( * V_36 ++ ) << ( V_32 * 8 ) ;
F_3 ( V_2 , V_38 , V_6 ) ;
}
} else {
V_31 = F_8 ( V_2 -> V_27 , V_29 ) ;
V_34 = V_31 ;
V_28 = V_34 * V_2 -> V_23 ;
for ( V_33 = 0 ; V_33 < V_31 ; V_33 ++ ) {
T_1 V_38 = 0 ;
for ( V_32 = 0 ; V_28 && ( V_32 < V_2 -> V_23 ) ;
V_32 ++ , V_28 -- )
V_38 |= ( T_1 ) ( * V_36 ++ ) << ( V_32 * 8 ) ;
F_3 ( V_2 , V_38 , V_6 ) ;
}
}
V_2 -> V_37 += V_34 * V_2 -> V_23 ;
return V_34 ;
}
static unsigned int F_11 (
struct V_1 * V_2 , struct V_14 * V_15 )
{
unsigned V_39 ;
T_1 V_30 ;
unsigned V_32 , V_33 ;
unsigned int V_40 = 0 ;
unsigned V_17 ;
T_2 * V_41 = ( T_2 * ) V_15 -> V_41 + V_2 -> V_42 ;
V_30 = F_1 ( V_2 , V_9 ) ;
V_39 = F_12 ( V_30 ) ;
if ( V_2 -> V_24 ) {
V_17 = V_2 -> V_27 * V_2 -> V_23 ;
for ( V_33 = 0 ; V_33 < V_39 ; V_33 ++ ) {
T_1 V_38 = F_1 ( V_2 , V_43 ) ;
for ( V_32 = 0 ; V_17 && ( V_32 < 4 ) ; V_32 ++ , V_17 -- )
* V_41 ++ = ( V_38 >> V_32 * 8 ) & 0xFF ;
}
V_2 -> V_42 += V_2 -> V_27 * V_2 -> V_23 ;
V_40 += V_2 -> V_27 ;
} else {
T_1 V_44 = ( ( T_1 ) 1 << V_15 -> V_20 ) - 1 ;
for ( V_33 = 0 ; V_33 < V_39 ; V_33 ++ ) {
T_1 V_38 = F_1 ( V_2 , V_43 ) & V_44 ;
for ( V_32 = 0 ; ( V_32 < V_2 -> V_23 ) ; V_32 ++ )
* V_41 ++ = ( V_38 >> ( V_32 * 8 ) ) & 0xFF ;
}
V_2 -> V_42 += V_39 * V_2 -> V_23 ;
V_40 += V_39 ;
}
return V_40 ;
}
static void F_13 (
struct V_1 * V_2 , struct V_14 * V_15 )
{
F_14 ( V_2 -> V_45 , V_2 -> V_46 ,
V_2 -> V_47 , V_48 ) ;
if ( V_2 -> V_24 ) {
unsigned V_17 = V_2 -> V_27 * V_2 -> V_23 ;
memcpy ( V_2 -> V_49 , V_15 -> V_36 + V_2 -> V_18 , V_17 ) ;
} else {
unsigned int V_32 ;
unsigned int V_33 ;
T_2 * V_36 = ( T_2 * ) V_15 -> V_36 + V_2 -> V_37 ;
unsigned V_50 = V_2 -> V_27 * V_2 -> V_23 ;
for ( V_33 = 0 ; V_33 < V_2 -> V_27 ; V_33 ++ ) {
T_1 V_38 = 0 ;
for ( V_32 = 0 ; V_50 && ( V_32 < V_2 -> V_23 ) ;
V_32 ++ , V_50 -- )
V_38 |= ( T_1 ) ( * V_36 ++ ) << ( V_32 * 8 ) ;
V_2 -> V_49 [ V_33 ] = V_38 ;
}
}
V_2 -> V_37 += V_2 -> V_27 * V_2 -> V_23 ;
F_15 ( V_2 -> V_45 , V_2 -> V_46 ,
V_2 -> V_47 , V_48 ) ;
}
static void F_16 (
struct V_1 * V_2 , struct V_14 * V_15 )
{
F_14 ( V_2 -> V_45 , V_2 -> V_51 ,
V_2 -> V_47 , V_52 ) ;
if ( V_2 -> V_24 ) {
unsigned V_17 = V_2 -> V_27 * V_2 -> V_23 ;
memcpy ( V_15 -> V_41 + V_2 -> V_42 , V_2 -> V_53 , V_17 ) ;
} else {
unsigned int V_32 ;
unsigned int V_33 ;
unsigned char * V_41 = V_15 -> V_41 + V_2 -> V_42 ;
T_1 V_44 = ( ( T_1 ) 1 << V_15 -> V_20 ) - 1 ;
for ( V_33 = 0 ; V_33 < V_2 -> V_27 ; V_33 ++ ) {
T_1 V_38 = V_2 -> V_53 [ V_33 ] & V_44 ;
for ( V_32 = 0 ; ( V_32 < V_2 -> V_23 ) ; V_32 ++ )
* V_41 ++ = ( V_38 >> ( V_32 * 8 ) ) & 0xFF ;
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
T_1 V_5 ;
unsigned int V_17 ;
int V_69 = 0 ;
T_1 V_70 ;
V_70 = F_1 ( V_2 , V_9 ) ;
if ( ( V_70 & V_71 ) != V_71 ) {
F_22 ( V_2 -> V_45 , L_3 ,
( unsigned ) V_70 ) ;
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
T_1 V_5 ;
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
T_1 * V_91 ;
T_3 V_92 ;
int V_69 ;
struct V_93 V_94 ;
V_90 = F_31 ( V_2 -> V_45 ,
V_89 ? L_6 : L_7 ) ;
if ( F_32 ( V_90 ) ) {
V_69 = F_33 ( V_90 ) ;
if ( V_69 != - V_95 )
F_22 ( V_2 -> V_45 ,
L_8 , V_69 ) ;
return V_69 ;
}
V_91 = F_34 ( V_2 -> V_45 , V_2 -> V_47 ,
& V_92 , V_96 ) ;
if ( ! V_91 ) {
F_22 ( V_2 -> V_45 , L_9 ) ;
F_35 ( V_90 ) ;
return - V_97 ;
}
if ( V_89 ) {
V_94 . V_98 = V_2 -> V_99 + V_43 ;
V_94 . V_100 = V_101 ;
V_94 . V_102 = 0 ;
} else {
V_94 . V_103 = V_2 -> V_99 + V_6 ;
V_94 . V_104 = V_101 ;
V_94 . V_105 = 0 ;
}
V_69 = F_36 ( V_90 , & V_94 ) ;
if ( V_69 )
goto V_106;
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
V_106:
F_37 ( V_2 -> V_45 , V_2 -> V_47 , V_91 , V_92 ) ;
F_35 ( V_90 ) ;
return V_69 ;
}
static void F_38 ( struct V_1 * V_2 ,
bool V_89 )
{
T_1 * V_91 ;
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
static T_1 F_39 ( struct V_12 * V_13 ,
struct V_14 * V_15 , bool V_107 )
{
struct V_1 * V_2 = F_40 ( V_13 -> V_108 ) ;
T_1 V_109 = V_15 -> V_110 ;
T_2 V_20 = V_15 -> V_20 ;
T_1 V_111 ;
int V_112 ;
if ( V_109 != V_2 -> V_113 ) {
F_41 ( V_2 -> V_114 , V_109 ) ;
V_2 -> V_113 = V_109 ;
}
V_2 -> V_115 = V_13 ;
V_2 -> V_18 = 0 ;
V_2 -> V_42 = 0 ;
V_2 -> V_37 = 0 ;
V_2 -> V_116 = V_15 ;
if ( V_107 ) {
F_5 ( V_2 ) ;
V_111 = V_2 -> V_117 ;
V_111 |= F_42 ( V_20 - 1 ) ;
V_111 &= ~ V_118 ;
V_112 = V_13 -> V_119 & 0x3 ;
if ( V_112 == V_120 )
V_111 |= V_121 ;
else if ( V_112 == V_122 )
V_111 |= V_123 ;
else if ( V_112 == V_124 )
V_111 |= V_125 ;
else if ( V_112 == V_126 )
V_111 |= V_127 ;
if ( V_2 -> V_128 ) {
if ( V_2 -> V_128 != V_13 )
F_3 ( V_2 , V_111 , V_7 ) ;
V_2 -> V_128 = NULL ;
} else
F_3 ( V_2 , V_111 , V_7 ) ;
V_111 |= V_129 ;
if ( V_13 -> V_119 & V_130 )
V_111 |= V_131 ;
else
V_111 &= ~ V_131 ;
F_3 ( V_2 , 0 , V_132 ) ;
} else {
V_111 = V_2 -> V_133 ;
V_111 &= ~ F_42 ( ~ 0 ) ;
V_111 |= F_42 ( V_20 - 1 ) ;
}
return V_111 ;
}
static int F_43 ( struct V_12 * V_13 ,
struct V_14 * V_15 , T_1 V_111 )
{
struct V_1 * V_2 = F_40 ( V_13 -> V_108 ) ;
unsigned V_22 ;
int V_69 ;
V_22 = F_6 ( V_13 , V_2 , V_15 ) ;
if ( V_2 -> V_24 )
V_111 |= V_134 ;
V_111 &= ~ ( V_135 | V_136 | V_137 ) ;
V_2 -> V_79 = 0 ;
if ( V_15 -> V_41 ) {
V_111 |= V_137 ;
V_2 -> V_79 |= V_82 ;
}
if ( V_15 -> V_36 ) {
V_111 |= V_136 ;
V_2 -> V_79 |= V_80 ;
}
V_111 |= F_44 ( V_13 -> V_138 ) ;
F_3 ( V_2 , V_111 , V_7 ) ;
V_2 -> V_133 = V_111 ;
F_45 ( V_2 -> V_45 , L_10 ,
V_2 -> V_117 , ( unsigned ) V_111 ) ;
if ( V_22 > V_139 )
V_69 = F_26 ( V_2 , V_15 ) ;
else
V_69 = F_29 ( V_2 , V_15 ) ;
return V_69 ;
}
static int F_46 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_40 ( V_13 -> V_108 ) ;
T_1 V_5 ;
unsigned long V_140 ;
int V_69 ;
F_45 ( & V_13 -> V_45 , L_11 ,
V_13 -> V_20 ,
V_13 -> V_119 & V_141 ? L_12 : L_13 ,
V_13 -> V_119 & V_142 ? L_12 : L_13 ,
V_13 -> V_143 ) ;
V_69 = F_47 ( V_2 -> V_45 ) ;
if ( V_69 < 0 ) {
F_22 ( V_2 -> V_45 , L_14 , V_69 ) ;
return V_69 ;
}
F_48 ( & V_2 -> V_144 , V_140 ) ;
V_5 = V_2 -> V_117 ;
if ( V_13 -> V_119 & V_130 )
V_5 &= ~ F_49 ( V_13 -> V_138 ) ;
else
V_5 |= F_49 ( V_13 -> V_138 ) ;
V_2 -> V_117 = V_5 ;
F_3 ( V_2 , V_2 -> V_117 , V_7 ) ;
F_50 ( & V_2 -> V_144 , V_140 ) ;
F_51 ( V_2 -> V_45 ) ;
return 0 ;
}
static void F_52 ( int V_145 )
{
if ( ! V_145 )
return;
if ( V_145 >= 1000 )
F_53 ( V_145 / 1000 ) ;
F_54 ( V_145 % 1000 ) ;
}
static int F_55 ( struct V_146 * V_108 ,
struct V_147 * V_148 )
{
bool V_149 = true ;
struct V_1 * V_2 = F_40 ( V_108 ) ;
struct V_14 * V_150 ;
struct V_12 * V_13 = V_148 -> V_13 ;
int V_69 ;
bool V_151 = false ;
V_148 -> V_70 = 0 ;
V_148 -> V_152 = 0 ;
F_56 (xfer, &msg->transfers, transfer_list) {
T_1 V_153 ;
F_20 ( & V_2 -> V_154 ) ;
V_153 = F_39 ( V_13 , V_150 , V_149 ) ;
if ( ! V_150 -> V_17 ) {
V_69 = 0 ;
V_151 = true ;
goto V_155;
}
V_69 = F_43 ( V_13 , V_150 , V_153 ) ;
if ( V_69 < 0 ) {
F_22 ( V_2 -> V_45 ,
L_15 , V_69 ) ;
goto V_155;
}
V_149 = false ;
V_69 = F_57 ( & V_2 -> V_154 ,
V_156 ) ;
if ( F_58 ( V_69 == 0 ) ) {
F_22 ( V_2 -> V_45 ,
L_16 , V_69 ) ;
V_69 = - V_62 ;
goto V_155;
}
if ( V_2 -> V_157 || V_2 -> V_158 ) {
F_22 ( V_2 -> V_45 , L_17 ) ;
V_69 = - V_62 ;
goto V_155;
}
V_148 -> V_152 += V_150 -> V_17 ;
V_155:
if ( V_69 < 0 || V_151 ) {
F_3 ( V_2 , V_2 -> V_117 ,
V_7 ) ;
F_52 ( V_150 -> V_159 ) ;
goto exit;
} else if ( F_59 ( & V_150 -> V_160 ,
& V_148 -> V_161 ) ) {
if ( V_150 -> V_162 )
V_2 -> V_128 = V_13 ;
else {
F_3 ( V_2 , V_2 -> V_117 ,
V_7 ) ;
F_52 ( V_150 -> V_159 ) ;
}
} else if ( V_150 -> V_162 ) {
F_3 ( V_2 , V_2 -> V_117 ,
V_7 ) ;
F_52 ( V_150 -> V_159 ) ;
}
}
V_69 = 0 ;
exit:
V_148 -> V_70 = V_69 ;
F_60 ( V_108 ) ;
return V_69 ;
}
static T_4 F_61 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_116 ;
unsigned long V_140 ;
F_48 ( & V_2 -> V_144 , V_140 ) ;
if ( V_2 -> V_157 || V_2 -> V_158 ) {
F_22 ( V_2 -> V_45 , L_18 ,
V_2 -> V_163 ) ;
F_22 ( V_2 -> V_45 , L_19 ,
V_2 -> V_133 , V_2 -> V_85 ) ;
F_62 ( V_2 -> V_164 ) ;
F_54 ( 2 ) ;
F_63 ( V_2 -> V_164 ) ;
F_18 ( & V_2 -> V_154 ) ;
goto exit;
}
if ( V_2 -> V_79 & V_82 )
F_11 ( V_2 , V_15 ) ;
if ( V_2 -> V_79 & V_80 )
V_2 -> V_18 = V_2 -> V_37 ;
else
V_2 -> V_18 = V_2 -> V_42 ;
if ( V_2 -> V_18 == V_15 -> V_17 ) {
F_18 ( & V_2 -> V_154 ) ;
goto exit;
}
F_6 ( V_2 -> V_115 , V_2 , V_15 ) ;
F_29 ( V_2 , V_15 ) ;
exit:
F_50 ( & V_2 -> V_144 , V_140 ) ;
return V_165 ;
}
static T_4 F_64 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_116 ;
long V_166 ;
int V_167 = 0 ;
unsigned V_22 ;
unsigned long V_140 ;
if ( V_2 -> V_79 & V_80 ) {
if ( V_2 -> V_157 ) {
F_28 ( V_2 -> V_58 ) ;
V_167 += 1 ;
} else {
V_166 = F_65 (
& V_2 -> V_56 , V_156 ) ;
if ( V_166 <= 0 ) {
F_28 ( V_2 -> V_58 ) ;
F_22 ( V_2 -> V_45 , L_20 ) ;
V_167 += 1 ;
}
}
}
if ( V_2 -> V_79 & V_82 ) {
if ( V_2 -> V_158 ) {
F_28 ( V_2 -> V_67 ) ;
V_167 += 2 ;
} else {
V_166 = F_65 (
& V_2 -> V_65 , V_156 ) ;
if ( V_166 <= 0 ) {
F_28 ( V_2 -> V_67 ) ;
F_22 ( V_2 -> V_45 , L_21 ) ;
V_167 += 2 ;
}
}
}
F_48 ( & V_2 -> V_144 , V_140 ) ;
if ( V_167 ) {
F_22 ( V_2 -> V_45 , L_22 ,
V_2 -> V_163 ) ;
F_22 ( V_2 -> V_45 , L_23 ,
V_2 -> V_133 , V_2 -> V_85 ) ;
F_62 ( V_2 -> V_164 ) ;
F_54 ( 2 ) ;
F_63 ( V_2 -> V_164 ) ;
F_18 ( & V_2 -> V_154 ) ;
F_50 ( & V_2 -> V_144 , V_140 ) ;
return V_165 ;
}
if ( V_2 -> V_79 & V_82 )
F_16 ( V_2 , V_15 ) ;
if ( V_2 -> V_79 & V_80 )
V_2 -> V_18 = V_2 -> V_37 ;
else
V_2 -> V_18 = V_2 -> V_42 ;
if ( V_2 -> V_18 == V_15 -> V_17 ) {
F_18 ( & V_2 -> V_154 ) ;
goto exit;
}
V_22 = F_6 ( V_2 -> V_115 ,
V_2 , V_15 ) ;
if ( V_22 > V_139 )
V_167 = F_26 ( V_2 , V_15 ) ;
else
V_167 = F_29 ( V_2 , V_15 ) ;
exit:
F_50 ( & V_2 -> V_144 , V_140 ) ;
return V_165 ;
}
static T_4 F_66 ( int V_168 , void * V_169 )
{
struct V_1 * V_2 = V_169 ;
if ( ! V_2 -> V_86 )
return F_61 ( V_2 ) ;
return F_64 ( V_2 ) ;
}
static T_4 F_67 ( int V_168 , void * V_169 )
{
struct V_1 * V_2 = V_169 ;
V_2 -> V_163 = F_1 ( V_2 , V_9 ) ;
if ( V_2 -> V_79 & V_80 )
V_2 -> V_157 = V_2 -> V_163 &
( V_170 | V_171 ) ;
if ( V_2 -> V_79 & V_82 )
V_2 -> V_158 = V_2 -> V_163 &
( V_172 | V_173 ) ;
F_5 ( V_2 ) ;
return V_174 ;
}
static int F_68 ( struct V_175 * V_176 )
{
struct V_146 * V_108 ;
struct V_1 * V_2 ;
struct V_177 * V_178 ;
int V_69 , V_179 ;
V_108 = F_69 ( & V_176 -> V_45 , sizeof( * V_2 ) ) ;
if ( ! V_108 ) {
F_22 ( & V_176 -> V_45 , L_24 ) ;
return - V_97 ;
}
F_70 ( V_176 , V_108 ) ;
V_2 = F_40 ( V_108 ) ;
if ( F_71 ( V_176 -> V_45 . V_180 , L_25 ,
& V_108 -> V_143 ) )
V_108 -> V_143 = 25000000 ;
V_108 -> V_181 = V_141 | V_142 | V_130 ;
V_108 -> V_182 = F_46 ;
V_108 -> V_183 = F_55 ;
V_108 -> V_184 = V_185 ;
V_108 -> V_186 = true ;
V_2 -> V_108 = V_108 ;
V_2 -> V_45 = & V_176 -> V_45 ;
F_72 ( & V_2 -> V_144 ) ;
V_178 = F_73 ( V_176 , V_187 , 0 ) ;
V_2 -> V_4 = F_74 ( & V_176 -> V_45 , V_178 ) ;
if ( F_32 ( V_2 -> V_4 ) ) {
V_69 = F_33 ( V_2 -> V_4 ) ;
goto V_188;
}
V_2 -> V_99 = V_178 -> V_189 ;
V_179 = F_75 ( V_176 , 0 ) ;
V_2 -> V_168 = V_179 ;
V_69 = F_76 ( V_2 -> V_168 , F_67 ,
F_66 , V_190 ,
F_77 ( & V_176 -> V_45 ) , V_2 ) ;
if ( V_69 < 0 ) {
F_22 ( & V_176 -> V_45 , L_26 ,
V_2 -> V_168 ) ;
goto V_188;
}
V_2 -> V_114 = F_78 ( & V_176 -> V_45 , L_27 ) ;
if ( F_32 ( V_2 -> V_114 ) ) {
F_22 ( & V_176 -> V_45 , L_28 ) ;
V_69 = F_33 ( V_2 -> V_114 ) ;
goto V_191;
}
V_2 -> V_164 = F_79 ( & V_176 -> V_45 , L_27 ) ;
if ( F_32 ( V_2 -> V_164 ) ) {
F_22 ( & V_176 -> V_45 , L_29 ) ;
V_69 = F_33 ( V_2 -> V_164 ) ;
goto V_191;
}
V_2 -> V_26 = V_139 << 2 ;
V_2 -> V_47 = V_192 ;
V_69 = F_30 ( V_2 , true ) ;
if ( V_69 < 0 )
goto V_191;
V_69 = F_30 ( V_2 , false ) ;
if ( V_69 < 0 )
goto V_193;
V_2 -> V_26 = V_2 -> V_47 ;
F_80 ( & V_2 -> V_56 ) ;
F_80 ( & V_2 -> V_65 ) ;
F_80 ( & V_2 -> V_154 ) ;
F_81 ( & V_176 -> V_45 ) ;
if ( ! F_82 ( & V_176 -> V_45 ) ) {
V_69 = F_83 ( & V_176 -> V_45 ) ;
if ( V_69 )
goto V_194;
}
V_69 = F_47 ( & V_176 -> V_45 ) ;
if ( V_69 < 0 ) {
F_22 ( & V_176 -> V_45 , L_30 , V_69 ) ;
goto V_194;
}
V_2 -> V_117 = V_195 ;
F_3 ( V_2 , V_2 -> V_117 , V_7 ) ;
F_51 ( & V_176 -> V_45 ) ;
V_108 -> V_45 . V_180 = V_176 -> V_45 . V_180 ;
V_69 = F_84 ( & V_176 -> V_45 , V_108 ) ;
if ( V_69 < 0 ) {
F_22 ( & V_176 -> V_45 , L_31 , V_69 ) ;
goto V_194;
}
return V_69 ;
V_194:
F_85 ( & V_176 -> V_45 ) ;
if ( ! F_86 ( & V_176 -> V_45 ) )
F_87 ( & V_176 -> V_45 ) ;
F_38 ( V_2 , false ) ;
V_193:
F_38 ( V_2 , true ) ;
V_191:
F_88 ( V_179 , V_2 ) ;
V_188:
F_89 ( V_108 ) ;
return V_69 ;
}
static int F_90 ( struct V_175 * V_176 )
{
struct V_146 * V_108 = F_91 ( V_176 ) ;
struct V_1 * V_2 = F_40 ( V_108 ) ;
F_88 ( V_2 -> V_168 , V_2 ) ;
if ( V_2 -> V_58 )
F_38 ( V_2 , false ) ;
if ( V_2 -> V_67 )
F_38 ( V_2 , true ) ;
F_85 ( & V_176 -> V_45 ) ;
if ( ! F_86 ( & V_176 -> V_45 ) )
F_87 ( & V_176 -> V_45 ) ;
return 0 ;
}
static int F_92 ( struct V_196 * V_45 )
{
struct V_146 * V_108 = F_93 ( V_45 ) ;
return F_94 ( V_108 ) ;
}
static int F_95 ( struct V_196 * V_45 )
{
struct V_146 * V_108 = F_93 ( V_45 ) ;
struct V_1 * V_2 = F_40 ( V_108 ) ;
int V_69 ;
V_69 = F_47 ( V_45 ) ;
if ( V_69 < 0 ) {
F_22 ( V_45 , L_14 , V_69 ) ;
return V_69 ;
}
F_3 ( V_2 , V_2 -> V_133 , V_7 ) ;
F_51 ( V_45 ) ;
return F_96 ( V_108 ) ;
}
static int F_87 ( struct V_196 * V_45 )
{
struct V_146 * V_108 = F_93 ( V_45 ) ;
struct V_1 * V_2 = F_40 ( V_108 ) ;
F_1 ( V_2 , V_7 ) ;
F_97 ( V_2 -> V_114 ) ;
return 0 ;
}
static int F_83 ( struct V_196 * V_45 )
{
struct V_146 * V_108 = F_93 ( V_45 ) ;
struct V_1 * V_2 = F_40 ( V_108 ) ;
int V_69 ;
V_69 = F_98 ( V_2 -> V_114 ) ;
if ( V_69 < 0 ) {
F_22 ( V_2 -> V_45 , L_32 , V_69 ) ;
return V_69 ;
}
return 0 ;
}
