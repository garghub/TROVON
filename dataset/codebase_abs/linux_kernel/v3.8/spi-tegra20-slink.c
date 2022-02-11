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
V_25 = V_13 -> V_25 ? V_13 -> V_25 :
V_20 -> V_25 ;
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
unsigned int V_25 ;
V_25 = V_13 -> V_25 ? V_13 -> V_25 :
V_2 -> V_50 -> V_25 ;
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
F_15 ( V_2 -> V_51 , V_2 -> V_52 ,
V_2 -> V_53 , V_54 ) ;
if ( V_2 -> V_28 ) {
V_22 = V_2 -> V_32 * V_2 -> V_14 ;
memcpy ( V_2 -> V_55 , V_13 -> V_42 + V_2 -> V_23 , V_22 ) ;
} else {
unsigned int V_37 ;
unsigned int V_38 ;
T_1 * V_42 = ( T_1 * ) V_13 -> V_42 + V_2 -> V_43 ;
unsigned V_56 = V_2 -> V_32 * V_2 -> V_14 ;
unsigned int V_39 ;
for ( V_38 = 0 ; V_38 < V_2 -> V_32 ; V_38 ++ ) {
V_39 = 0 ;
for ( V_37 = 0 ; V_56 && ( V_37 < V_2 -> V_14 ) ;
V_37 ++ , V_56 -- )
V_39 |= ( ( * V_42 ++ ) << V_37 * 8 ) ;
V_2 -> V_55 [ V_38 ] = V_39 ;
}
}
V_2 -> V_43 += V_2 -> V_32 * V_2 -> V_14 ;
F_16 ( V_2 -> V_51 , V_2 -> V_52 ,
V_2 -> V_53 , V_54 ) ;
}
static void F_17 (
struct V_1 * V_2 , struct V_12 * V_13 )
{
unsigned V_22 ;
F_15 ( V_2 -> V_51 , V_2 -> V_57 ,
V_2 -> V_53 , V_58 ) ;
if ( V_2 -> V_28 ) {
V_22 = V_2 -> V_32 * V_2 -> V_14 ;
memcpy ( V_13 -> V_47 + V_2 -> V_48 , V_2 -> V_59 , V_22 ) ;
} else {
unsigned int V_37 ;
unsigned int V_38 ;
unsigned char * V_47 = V_13 -> V_47 + V_2 -> V_48 ;
unsigned int V_39 ;
unsigned int V_60 , V_25 ;
V_25 = V_13 -> V_25 ? V_13 -> V_25 :
V_2 -> V_50 -> V_25 ;
V_60 = ( 1 << V_25 ) - 1 ;
for ( V_38 = 0 ; V_38 < V_2 -> V_32 ; V_38 ++ ) {
V_39 = V_2 -> V_59 [ V_38 ] ;
V_39 &= V_60 ;
for ( V_37 = 0 ; ( V_37 < V_2 -> V_14 ) ; V_37 ++ )
* V_47 ++ = ( V_39 >> ( V_37 * 8 ) ) & 0xFF ;
}
}
V_2 -> V_48 += V_2 -> V_32 * V_2 -> V_14 ;
F_16 ( V_2 -> V_51 , V_2 -> V_57 ,
V_2 -> V_53 , V_58 ) ;
}
static void F_18 ( void * args )
{
struct V_61 * V_62 = args ;
F_19 ( V_62 ) ;
}
static int F_20 ( struct V_1 * V_2 , int V_22 )
{
F_21 ( V_2 -> V_63 ) ;
V_2 -> V_64 = F_22 ( V_2 -> V_65 ,
V_2 -> V_52 , V_22 , V_66 ,
V_67 | V_68 ) ;
if ( ! V_2 -> V_64 ) {
F_23 ( V_2 -> V_51 , L_1 ) ;
return - V_69 ;
}
V_2 -> V_64 -> V_70 = F_18 ;
V_2 -> V_64 -> V_71 = & V_2 -> V_63 ;
F_24 ( V_2 -> V_64 ) ;
F_25 ( V_2 -> V_65 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , int V_22 )
{
F_21 ( V_2 -> V_72 ) ;
V_2 -> V_73 = F_22 ( V_2 -> V_74 ,
V_2 -> V_57 , V_22 , V_75 ,
V_67 | V_68 ) ;
if ( ! V_2 -> V_73 ) {
F_23 ( V_2 -> V_51 , L_2 ) ;
return - V_69 ;
}
V_2 -> V_73 -> V_70 = F_18 ;
V_2 -> V_73 -> V_71 = & V_2 -> V_72 ;
F_24 ( V_2 -> V_73 ) ;
F_25 ( V_2 -> V_74 ) ;
return 0 ;
}
static int F_27 (
struct V_1 * V_2 , struct V_12 * V_13 )
{
unsigned long V_5 ;
unsigned long V_76 ;
unsigned int V_22 ;
int V_77 = 0 ;
unsigned long V_78 ;
V_78 = F_1 ( V_2 , V_9 ) ;
if ( ( V_78 & V_79 ) != V_79 ) {
F_23 ( V_2 -> V_51 ,
L_3 , V_78 ) ;
return - V_69 ;
}
V_5 = F_28 ( V_2 -> V_32 - 1 ) ;
V_5 |= V_2 -> V_30 ;
if ( V_2 -> V_28 )
V_22 = F_11 ( V_2 -> V_32 * V_2 -> V_14 ,
4 ) * 4 ;
else
V_22 = V_2 -> V_32 * 4 ;
if ( V_22 & 0xF )
V_5 |= V_80 | V_81 ;
else if ( ( ( V_22 ) >> 4 ) & 0x1 )
V_5 |= V_82 | V_83 ;
else
V_5 |= V_84 | V_85 ;
if ( V_2 -> V_86 & V_87 )
V_5 |= V_88 ;
if ( V_2 -> V_86 & V_89 )
V_5 |= V_90 ;
F_3 ( V_2 , V_5 , V_91 ) ;
V_2 -> V_92 = V_5 ;
if ( V_2 -> V_86 & V_87 ) {
F_14 ( V_2 , V_13 ) ;
F_29 () ;
V_77 = F_20 ( V_2 , V_22 ) ;
if ( V_77 < 0 ) {
F_23 ( V_2 -> V_51 ,
L_4 , V_77 ) ;
return V_77 ;
}
V_76 = F_1 ( V_2 , V_9 ) ;
while ( ! ( V_76 & V_93 ) )
V_76 = F_1 ( V_2 , V_9 ) ;
}
if ( V_2 -> V_86 & V_89 ) {
F_16 ( V_2 -> V_51 , V_2 -> V_57 ,
V_2 -> V_53 , V_58 ) ;
V_77 = F_26 ( V_2 , V_22 ) ;
if ( V_77 < 0 ) {
F_23 ( V_2 -> V_51 ,
L_5 , V_77 ) ;
if ( V_2 -> V_86 & V_87 )
F_30 ( V_2 -> V_65 ) ;
return V_77 ;
}
}
V_2 -> V_94 = true ;
if ( V_2 -> V_28 ) {
V_5 |= V_95 ;
F_3 ( V_2 , V_5 , V_91 ) ;
F_31 ( 1 ) ;
}
V_2 -> V_92 = V_5 ;
V_5 |= V_96 ;
F_3 ( V_2 , V_5 , V_91 ) ;
return V_77 ;
}
static int F_32 (
struct V_1 * V_2 , struct V_12 * V_13 )
{
unsigned long V_5 ;
unsigned V_97 ;
V_5 = V_2 -> V_30 ;
if ( V_2 -> V_86 & V_87 )
V_5 |= V_88 ;
if ( V_2 -> V_86 & V_89 )
V_5 |= V_90 ;
F_3 ( V_2 , V_5 , V_91 ) ;
V_2 -> V_92 = V_5 ;
if ( V_2 -> V_86 & V_87 )
V_97 = F_9 ( V_2 , V_13 ) ;
else
V_97 = V_2 -> V_32 ;
V_5 |= F_28 ( V_97 - 1 ) ;
F_3 ( V_2 , V_5 , V_91 ) ;
V_2 -> V_92 = V_5 ;
V_2 -> V_94 = false ;
if ( V_2 -> V_28 ) {
V_5 |= V_95 ;
F_3 ( V_2 , V_5 , V_91 ) ;
F_31 ( 1 ) ;
F_29 () ;
}
V_2 -> V_92 = V_5 ;
V_5 |= V_96 ;
F_3 ( V_2 , V_5 , V_91 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
bool V_98 )
{
struct V_99 * V_99 ;
T_2 * V_100 ;
T_3 V_101 ;
int V_77 ;
struct V_102 V_103 ;
T_4 V_104 ;
F_34 ( V_104 ) ;
F_35 ( V_105 , V_104 ) ;
V_99 = F_36 ( V_104 , NULL , NULL ) ;
if ( ! V_99 ) {
F_23 ( V_2 -> V_51 ,
L_6 ) ;
return - V_106 ;
}
V_100 = F_37 ( V_2 -> V_51 , V_2 -> V_53 ,
& V_101 , V_107 ) ;
if ( ! V_100 ) {
F_23 ( V_2 -> V_51 , L_7 ) ;
F_38 ( V_99 ) ;
return - V_108 ;
}
V_103 . V_109 = V_2 -> V_110 ;
if ( V_98 ) {
V_103 . V_111 = V_2 -> V_112 + V_49 ;
V_103 . V_113 = V_114 ;
V_103 . V_115 = 0 ;
} else {
V_103 . V_116 = V_2 -> V_112 + V_6 ;
V_103 . V_117 = V_114 ;
V_103 . V_118 = 0 ;
}
V_77 = F_39 ( V_99 , & V_103 ) ;
if ( V_77 )
goto V_119;
if ( V_98 ) {
V_2 -> V_74 = V_99 ;
V_2 -> V_59 = V_100 ;
V_2 -> V_57 = V_101 ;
} else {
V_2 -> V_65 = V_99 ;
V_2 -> V_55 = V_100 ;
V_2 -> V_52 = V_101 ;
}
return 0 ;
V_119:
F_40 ( V_2 -> V_51 , V_2 -> V_53 , V_100 , V_101 ) ;
F_38 ( V_99 ) ;
return V_77 ;
}
static void F_41 ( struct V_1 * V_2 ,
bool V_98 )
{
T_2 * V_100 ;
T_3 V_101 ;
struct V_99 * V_99 ;
if ( V_98 ) {
V_100 = V_2 -> V_59 ;
V_99 = V_2 -> V_74 ;
V_101 = V_2 -> V_57 ;
V_2 -> V_74 = NULL ;
V_2 -> V_59 = NULL ;
} else {
V_100 = V_2 -> V_55 ;
V_99 = V_2 -> V_65 ;
V_101 = V_2 -> V_52 ;
V_2 -> V_55 = NULL ;
V_2 -> V_65 = NULL ;
}
if ( ! V_99 )
return;
F_40 ( V_2 -> V_51 , V_2 -> V_53 , V_100 , V_101 ) ;
F_38 ( V_99 ) ;
}
static int F_42 ( struct V_19 * V_20 ,
struct V_12 * V_13 , bool V_120 ,
bool V_121 )
{
struct V_1 * V_2 = F_43 ( V_20 -> V_122 ) ;
T_2 V_123 ;
T_1 V_25 ;
unsigned V_27 ;
int V_77 ;
struct V_124 * V_125 = V_20 -> V_126 ;
unsigned long V_127 ;
unsigned long V_128 ;
V_25 = V_13 -> V_25 ;
V_123 = V_13 -> V_129 ? V_13 -> V_129 : V_20 -> V_130 ;
if ( ! V_123 )
V_123 = V_2 -> V_131 ;
if ( V_123 != V_2 -> V_132 ) {
F_44 ( V_2 -> V_133 , V_123 * 4 ) ;
V_2 -> V_132 = V_123 ;
}
V_2 -> V_50 = V_20 ;
V_2 -> V_23 = 0 ;
V_2 -> V_48 = 0 ;
V_2 -> V_43 = 0 ;
V_2 -> V_134 = V_13 ;
V_27 = F_7 ( V_20 , V_2 , V_13 ) ;
if ( V_120 ) {
F_5 ( V_2 ) ;
V_127 = V_2 -> V_135 ;
V_127 |= F_45 ( V_25 - 1 ) ;
V_128 = V_2 -> V_136 ;
V_128 |= F_46 ( V_20 -> V_137 ) ;
V_2 -> V_138 = false ;
if ( V_125 && V_125 -> V_138 && V_121 &&
( ( V_2 -> V_32 * V_2 -> V_14 ) ==
( V_13 -> V_22 - V_2 -> V_23 ) ) ) {
int V_139 ;
int V_140 ;
V_139 = V_125 -> V_141 >> 1 ;
V_139 = F_47 ( V_139 , 3 ) ;
V_128 |= F_48 ( V_139 ) ;
if ( V_2 -> V_142 -> V_143 ) {
int V_144 ;
V_144 = V_125 -> V_145 ;
V_144 = F_47 ( V_144 , 0xF ) ;
V_140 = F_1 ( V_2 , V_44 ) ;
V_140 &= ~ F_49 ( 0xF ) ;
V_140 |= F_49 ( V_144 ) ;
F_3 ( V_2 , V_140 , V_44 ) ;
}
V_2 -> V_138 = true ;
}
if ( V_2 -> V_138 )
V_127 &= ~ V_146 ;
else
V_127 |= V_146 | V_147 ;
V_127 &= ~ V_148 ;
if ( V_20 -> V_149 & V_150 )
V_127 |= V_151 ;
if ( V_20 -> V_149 & V_152 )
V_127 |= V_153 ;
else
V_127 |= V_154 ;
} else {
V_127 = V_2 -> V_155 ;
V_127 &= ~ F_45 ( ~ 0 ) ;
V_127 |= F_45 ( V_25 - 1 ) ;
V_128 = V_2 -> V_156 ;
V_128 &= ~ ( V_157 | V_158 ) ;
}
F_3 ( V_2 , V_127 , V_159 ) ;
V_2 -> V_155 = V_127 ;
V_2 -> V_86 = 0 ;
if ( V_13 -> V_47 ) {
V_128 |= V_157 ;
V_2 -> V_86 |= V_89 ;
}
if ( V_13 -> V_42 ) {
V_128 |= V_158 ;
V_2 -> V_86 |= V_87 ;
}
F_3 ( V_2 , V_128 , V_160 ) ;
V_2 -> V_156 = V_128 ;
if ( V_27 > V_161 )
V_77 = F_27 ( V_2 , V_13 ) ;
else
V_77 = F_32 ( V_2 , V_13 ) ;
return V_77 ;
}
static int F_50 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_43 ( V_20 -> V_122 ) ;
unsigned long V_5 ;
unsigned long V_162 ;
int V_77 ;
unsigned int V_163 [ V_164 ] = {
V_165 ,
V_166 ,
V_167 ,
V_168 ,
} ;
F_51 ( & V_20 -> V_51 , L_8 ,
V_20 -> V_25 ,
V_20 -> V_149 & V_152 ? L_9 : L_10 ,
V_20 -> V_149 & V_150 ? L_9 : L_10 ,
V_20 -> V_130 ) ;
F_52 ( V_20 -> V_137 >= V_164 ) ;
V_77 = F_53 ( V_2 -> V_51 ) ;
if ( V_77 < 0 ) {
F_23 ( V_2 -> V_51 , L_11 , V_77 ) ;
return V_77 ;
}
F_54 ( & V_2 -> V_169 , V_162 ) ;
V_5 = V_2 -> V_135 ;
if ( V_20 -> V_149 & V_170 )
V_5 |= V_163 [ V_20 -> V_137 ] ;
else
V_5 &= ~ V_163 [ V_20 -> V_137 ] ;
V_2 -> V_135 = V_5 ;
F_3 ( V_2 , V_2 -> V_135 , V_159 ) ;
F_55 ( & V_2 -> V_169 , V_162 ) ;
F_56 ( V_2 -> V_51 ) ;
return 0 ;
}
static int F_57 ( struct V_171 * V_122 )
{
struct V_1 * V_2 = F_43 ( V_122 ) ;
return F_53 ( V_2 -> V_51 ) ;
}
static int F_58 ( struct V_171 * V_122 )
{
struct V_1 * V_2 = F_43 ( V_122 ) ;
F_56 ( V_2 -> V_51 ) ;
return 0 ;
}
static int F_59 ( struct V_171 * V_122 ,
struct V_172 * V_173 )
{
bool V_174 = true ;
int V_175 ;
struct V_1 * V_2 = F_43 ( V_122 ) ;
struct V_12 * V_176 ;
struct V_19 * V_20 = V_173 -> V_20 ;
int V_77 ;
V_173 -> V_78 = 0 ;
V_173 -> V_177 = 0 ;
V_175 = F_60 ( & V_173 -> V_178 ) ;
F_61 (xfer, &msg->transfers, transfer_list) {
F_21 ( V_2 -> V_179 ) ;
V_77 = F_42 ( V_20 , V_176 ,
V_174 , V_175 ) ;
if ( V_77 < 0 ) {
F_23 ( V_2 -> V_51 ,
L_12 , V_77 ) ;
goto exit;
}
V_174 = false ;
V_77 = F_62 ( & V_2 -> V_179 ,
V_180 ) ;
if ( F_63 ( V_77 == 0 ) ) {
F_23 ( V_2 -> V_51 ,
L_13 , V_77 ) ;
V_77 = - V_69 ;
goto exit;
}
if ( V_2 -> V_181 || V_2 -> V_182 ) {
F_23 ( V_2 -> V_51 , L_14 ) ;
V_77 = - V_69 ;
goto exit;
}
V_173 -> V_177 += V_176 -> V_22 ;
if ( V_176 -> V_183 && V_176 -> V_184 ) {
F_3 ( V_2 , V_2 -> V_135 ,
V_159 ) ;
F_31 ( V_176 -> V_184 ) ;
}
}
V_77 = 0 ;
exit:
F_3 ( V_2 , V_2 -> V_135 , V_159 ) ;
F_3 ( V_2 , V_2 -> V_136 , V_160 ) ;
V_173 -> V_78 = V_77 ;
F_64 ( V_122 ) ;
return V_77 ;
}
static T_5 F_65 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_134 ;
unsigned long V_162 ;
F_54 ( & V_2 -> V_169 , V_162 ) ;
if ( V_2 -> V_181 || V_2 -> V_182 ||
( V_2 -> V_185 & V_186 ) ) {
F_23 ( V_2 -> V_51 ,
L_15 , V_2 -> V_185 ) ;
F_23 ( V_2 -> V_51 ,
L_16 , V_2 -> V_155 ,
V_2 -> V_156 , V_2 -> V_92 ) ;
F_66 ( V_2 -> V_133 ) ;
F_31 ( 2 ) ;
F_67 ( V_2 -> V_133 ) ;
F_19 ( & V_2 -> V_179 ) ;
goto exit;
}
if ( V_2 -> V_86 & V_89 )
F_12 ( V_2 , V_13 ) ;
if ( V_2 -> V_86 & V_87 )
V_2 -> V_23 = V_2 -> V_43 ;
else
V_2 -> V_23 = V_2 -> V_48 ;
if ( V_2 -> V_23 == V_13 -> V_22 ) {
F_19 ( & V_2 -> V_179 ) ;
goto exit;
}
F_7 ( V_2 -> V_50 , V_2 , V_13 ) ;
F_32 ( V_2 , V_13 ) ;
exit:
F_55 ( & V_2 -> V_169 , V_162 ) ;
return V_187 ;
}
static T_5 F_68 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_134 ;
long V_188 ;
int V_189 = 0 ;
unsigned V_27 ;
unsigned long V_162 ;
if ( V_2 -> V_86 & V_87 ) {
if ( V_2 -> V_181 ) {
F_30 ( V_2 -> V_65 ) ;
V_189 += 1 ;
} else {
V_188 = F_69 (
& V_2 -> V_63 , V_180 ) ;
if ( V_188 <= 0 ) {
F_30 ( V_2 -> V_65 ) ;
F_23 ( V_2 -> V_51 , L_17 ) ;
V_189 += 1 ;
}
}
}
if ( V_2 -> V_86 & V_89 ) {
if ( V_2 -> V_182 ) {
F_30 ( V_2 -> V_74 ) ;
V_189 += 2 ;
} else {
V_188 = F_69 (
& V_2 -> V_72 , V_180 ) ;
if ( V_188 <= 0 ) {
F_30 ( V_2 -> V_74 ) ;
F_23 ( V_2 -> V_51 , L_18 ) ;
V_189 += 2 ;
}
}
}
F_54 ( & V_2 -> V_169 , V_162 ) ;
if ( V_189 ) {
F_23 ( V_2 -> V_51 ,
L_19 , V_2 -> V_185 ) ;
F_23 ( V_2 -> V_51 ,
L_20 , V_2 -> V_155 ,
V_2 -> V_156 , V_2 -> V_92 ) ;
F_66 ( V_2 -> V_133 ) ;
F_31 ( 2 ) ;
F_67 ( V_2 -> V_133 ) ;
F_19 ( & V_2 -> V_179 ) ;
F_55 ( & V_2 -> V_169 , V_162 ) ;
return V_187 ;
}
if ( V_2 -> V_86 & V_89 )
F_17 ( V_2 , V_13 ) ;
if ( V_2 -> V_86 & V_87 )
V_2 -> V_23 = V_2 -> V_43 ;
else
V_2 -> V_23 = V_2 -> V_48 ;
if ( V_2 -> V_23 == V_13 -> V_22 ) {
F_19 ( & V_2 -> V_179 ) ;
goto exit;
}
V_27 = F_7 ( V_2 -> V_50 ,
V_2 , V_13 ) ;
if ( V_27 > V_161 )
V_189 = F_27 ( V_2 , V_13 ) ;
else
V_189 = F_32 ( V_2 , V_13 ) ;
exit:
F_55 ( & V_2 -> V_169 , V_162 ) ;
return V_187 ;
}
static T_5 F_70 ( int V_190 , void * V_191 )
{
struct V_1 * V_2 = V_191 ;
if ( ! V_2 -> V_94 )
return F_65 ( V_2 ) ;
return F_68 ( V_2 ) ;
}
static T_5 F_71 ( int V_190 , void * V_191 )
{
struct V_1 * V_2 = V_191 ;
V_2 -> V_185 = F_1 ( V_2 , V_9 ) ;
if ( V_2 -> V_86 & V_87 )
V_2 -> V_181 = V_2 -> V_185 &
( V_192 | V_193 ) ;
if ( V_2 -> V_86 & V_89 )
V_2 -> V_182 = V_2 -> V_185 &
( V_194 | V_195 ) ;
F_5 ( V_2 ) ;
return V_196 ;
}
static struct V_197 * F_72 (
struct V_198 * V_199 )
{
struct V_197 * V_200 ;
const unsigned int * V_201 ;
struct V_202 * V_203 = V_199 -> V_51 . V_204 ;
T_2 V_205 [ 2 ] ;
V_200 = F_73 ( & V_199 -> V_51 , sizeof( * V_200 ) , V_107 ) ;
if ( ! V_200 ) {
F_23 ( & V_199 -> V_51 , L_21 ) ;
return NULL ;
}
if ( F_74 ( V_203 , L_22 ,
V_205 , 2 ) >= 0 )
V_200 -> V_110 = V_205 [ 1 ] ;
V_201 = F_75 ( V_203 , L_23 , NULL ) ;
if ( V_201 )
V_200 -> V_131 = F_76 ( V_201 ) ;
return V_200 ;
}
static int F_77 ( struct V_198 * V_199 )
{
struct V_171 * V_122 ;
struct V_1 * V_2 ;
struct V_206 * V_207 ;
struct V_197 * V_200 = V_199 -> V_51 . V_208 ;
int V_77 , V_209 ;
const struct V_210 * V_125 = NULL ;
const struct V_211 * V_212 ;
V_212 = F_78 ( F_79 ( V_213 ) , & V_199 -> V_51 ) ;
if ( ! V_212 ) {
F_23 ( & V_199 -> V_51 , L_24 ) ;
return - V_214 ;
}
V_125 = V_212 -> V_215 ;
if ( ! V_200 && V_199 -> V_51 . V_204 )
V_200 = F_72 ( V_199 ) ;
if ( ! V_200 ) {
F_23 ( & V_199 -> V_51 , L_25 ) ;
return - V_214 ;
}
if ( ! V_200 -> V_131 )
V_200 -> V_131 = 25000000 ;
V_122 = F_80 ( & V_199 -> V_51 , sizeof( * V_2 ) ) ;
if ( ! V_122 ) {
F_23 ( & V_199 -> V_51 , L_26 ) ;
return - V_108 ;
}
V_122 -> V_216 = V_152 | V_150 | V_170 ;
V_122 -> V_217 = F_50 ;
V_122 -> V_218 = F_57 ;
V_122 -> V_219 = F_59 ;
V_122 -> V_220 = F_58 ;
V_122 -> V_221 = V_164 ;
V_122 -> V_222 = - 1 ;
F_81 ( & V_199 -> V_51 , V_122 ) ;
V_2 = F_43 ( V_122 ) ;
V_2 -> V_122 = V_122 ;
V_2 -> V_110 = V_200 -> V_110 ;
V_2 -> V_51 = & V_199 -> V_51 ;
V_2 -> V_142 = V_125 ;
F_82 ( & V_2 -> V_169 ) ;
V_207 = F_83 ( V_199 , V_223 , 0 ) ;
if ( ! V_207 ) {
F_23 ( & V_199 -> V_51 , L_27 ) ;
V_77 = - V_214 ;
goto V_224;
}
V_2 -> V_112 = V_207 -> V_225 ;
V_2 -> V_4 = F_84 ( & V_199 -> V_51 , V_207 ) ;
if ( ! V_2 -> V_4 ) {
F_23 ( & V_199 -> V_51 ,
L_28 ) ;
V_77 = - V_226 ;
goto V_224;
}
V_209 = F_85 ( V_199 , 0 ) ;
V_2 -> V_190 = V_209 ;
V_77 = F_86 ( V_2 -> V_190 , F_71 ,
F_70 , V_227 ,
F_87 ( & V_199 -> V_51 ) , V_2 ) ;
if ( V_77 < 0 ) {
F_23 ( & V_199 -> V_51 , L_29 ,
V_2 -> V_190 ) ;
goto V_224;
}
V_2 -> V_133 = F_88 ( & V_199 -> V_51 , L_30 ) ;
if ( F_89 ( V_2 -> V_133 ) ) {
F_23 ( & V_199 -> V_51 , L_31 ) ;
V_77 = F_90 ( V_2 -> V_133 ) ;
goto V_228;
}
V_2 -> V_31 = V_161 << 2 ;
V_2 -> V_53 = V_229 ;
V_2 -> V_131 = V_200 -> V_131 ;
if ( V_200 -> V_110 ) {
V_77 = F_33 ( V_2 , true ) ;
if ( V_77 < 0 ) {
F_23 ( & V_199 -> V_51 , L_32 , V_77 ) ;
goto V_228;
}
V_77 = F_33 ( V_2 , false ) ;
if ( V_77 < 0 ) {
F_23 ( & V_199 -> V_51 , L_33 , V_77 ) ;
goto V_230;
}
V_2 -> V_31 = V_2 -> V_53 ;
F_91 ( & V_2 -> V_63 ) ;
F_91 ( & V_2 -> V_72 ) ;
}
F_91 ( & V_2 -> V_179 ) ;
F_92 ( & V_199 -> V_51 ) ;
if ( ! F_93 ( & V_199 -> V_51 ) ) {
V_77 = F_94 ( & V_199 -> V_51 ) ;
if ( V_77 )
goto V_231;
}
V_77 = F_53 ( & V_199 -> V_51 ) ;
if ( V_77 < 0 ) {
F_23 ( & V_199 -> V_51 , L_34 , V_77 ) ;
goto V_231;
}
V_2 -> V_135 = V_232 ;
V_2 -> V_136 = V_233 ;
F_3 ( V_2 , V_2 -> V_135 , V_159 ) ;
F_3 ( V_2 , V_2 -> V_136 , V_160 ) ;
F_56 ( & V_199 -> V_51 ) ;
V_122 -> V_51 . V_204 = V_199 -> V_51 . V_204 ;
V_77 = F_95 ( V_122 ) ;
if ( V_77 < 0 ) {
F_23 ( & V_199 -> V_51 , L_35 , V_77 ) ;
goto V_231;
}
return V_77 ;
V_231:
F_96 ( & V_199 -> V_51 ) ;
if ( ! F_97 ( & V_199 -> V_51 ) )
F_98 ( & V_199 -> V_51 ) ;
F_41 ( V_2 , false ) ;
V_230:
F_41 ( V_2 , true ) ;
V_228:
F_99 ( V_209 , V_2 ) ;
V_224:
F_100 ( V_122 ) ;
return V_77 ;
}
static int F_101 ( struct V_198 * V_199 )
{
struct V_171 * V_122 = F_102 ( & V_199 -> V_51 ) ;
struct V_1 * V_2 = F_43 ( V_122 ) ;
F_99 ( V_2 -> V_190 , V_2 ) ;
F_103 ( V_122 ) ;
if ( V_2 -> V_65 )
F_41 ( V_2 , false ) ;
if ( V_2 -> V_74 )
F_41 ( V_2 , true ) ;
F_96 ( & V_199 -> V_51 ) ;
if ( ! F_97 ( & V_199 -> V_51 ) )
F_98 ( & V_199 -> V_51 ) ;
return 0 ;
}
static int F_104 ( struct V_234 * V_51 )
{
struct V_171 * V_122 = F_102 ( V_51 ) ;
return F_105 ( V_122 ) ;
}
static int F_106 ( struct V_234 * V_51 )
{
struct V_171 * V_122 = F_102 ( V_51 ) ;
struct V_1 * V_2 = F_43 ( V_122 ) ;
int V_77 ;
V_77 = F_53 ( V_51 ) ;
if ( V_77 < 0 ) {
F_23 ( V_51 , L_11 , V_77 ) ;
return V_77 ;
}
F_3 ( V_2 , V_2 -> V_155 , V_159 ) ;
F_3 ( V_2 , V_2 -> V_156 , V_160 ) ;
F_56 ( V_51 ) ;
return F_107 ( V_122 ) ;
}
static int F_98 ( struct V_234 * V_51 )
{
struct V_171 * V_122 = F_102 ( V_51 ) ;
struct V_1 * V_2 = F_43 ( V_122 ) ;
F_1 ( V_2 , V_7 ) ;
F_108 ( V_2 -> V_133 ) ;
return 0 ;
}
static int F_94 ( struct V_234 * V_51 )
{
struct V_171 * V_122 = F_102 ( V_51 ) ;
struct V_1 * V_2 = F_43 ( V_122 ) ;
int V_77 ;
V_77 = F_109 ( V_2 -> V_133 ) ;
if ( V_77 < 0 ) {
F_23 ( V_2 -> V_51 , L_36 , V_77 ) ;
return V_77 ;
}
return 0 ;
}
