static int F_1 ( void T_1 * V_1 , int V_2 , int V_3 )
{
int V_4 = V_5 ;
T_2 V_6 ;
F_2 ( V_7 + V_3 + ( V_2 << 8 ) , V_1 + V_8 ) ;
while ( V_4 -- ) {
V_6 = F_3 ( V_1 + V_8 ) ;
if ( ! ( V_6 & V_7 ) )
break;
F_4 ( 1 ) ;
}
if ( V_4 < 0 )
return - V_9 ;
return F_3 ( V_1 + V_10 ) ;
}
static int F_5 ( void T_1 * V_1 ,
int V_2 , int V_3 , T_2 V_11 )
{
int V_4 = V_5 ;
T_2 V_6 ;
F_2 ( V_11 , V_1 + V_12 ) ;
F_2 ( V_13 + V_3 + ( V_2 << 8 ) , V_1 + V_8 ) ;
while ( V_4 -- ) {
V_6 = F_3 ( V_1 + V_8 ) ;
if ( ! ( V_6 & V_13 ) )
break;
F_4 ( 1 ) ;
}
return ( V_4 < 0 ) ? - V_9 : 0 ;
}
static int F_6 ( struct V_14 * V_15 , int V_2 , int V_3 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_19 * V_20 = F_7 ( V_17 ) ;
void T_1 * V_1 = V_20 -> V_21 ;
return F_1 ( V_1 , V_2 , V_3 ) ;
}
static int F_8 ( struct V_14 * V_15 , int V_2 ,
int V_3 , T_2 V_22 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_19 * V_20 = F_7 ( V_17 ) ;
void T_1 * V_1 = V_20 -> V_21 ;
return F_5 ( V_1 , V_2 , V_3 , V_22 ) ;
}
static int F_9 ( struct V_14 * V_15 )
{
return 0 ;
}
static void F_10 ( struct V_16 * V_17 )
{
struct V_19 * V_20 = F_7 ( V_17 ) ;
int V_23 ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
if ( V_20 -> V_25 -> V_26 ) {
F_11 ( V_20 -> V_27 ,
F_12 ( V_20 -> V_25 -> V_28 ) ,
V_29 , V_30 ) ;
F_13 ( V_20 -> V_25 -> V_26 ) ;
V_20 -> V_25 -> V_26 = NULL ;
}
V_20 -> V_25 = V_20 -> V_25 -> V_31 ;
}
}
static void F_14 ( struct V_16 * V_17 )
{
struct V_19 * V_20 = F_7 ( V_17 ) ;
int V_23 ;
for ( V_23 = 0 ; V_23 < V_32 ; V_23 ++ ) {
if ( V_20 -> V_33 -> V_26 ) {
F_11 ( V_20 -> V_27 ,
F_12 ( V_20 -> V_33 -> V_28 ) ,
V_29 , V_34 ) ;
F_13 ( V_20 -> V_33 -> V_26 ) ;
V_20 -> V_33 -> V_26 = NULL ;
}
V_20 -> V_33 = V_20 -> V_33 -> V_31 ;
}
}
static void F_15 ( struct V_35 * V_36 ,
T_3 V_37 , int V_38 )
{
struct V_35 * V_39 = V_36 ;
T_3 V_40 = V_37 ;
while ( V_38 -- > 0 ) {
V_40 += sizeof( * V_39 ) ;
V_39 -> V_41 = F_16 ( V_40 ) ;
V_39 -> V_31 = V_39 + 1 ;
V_39 ++ ;
}
V_39 -- ;
V_39 -> V_41 = F_16 ( V_37 ) ;
V_39 -> V_31 = V_36 ;
}
static void F_17 ( struct V_16 * V_17 )
{
struct V_19 * V_20 = F_7 ( V_17 ) ;
V_20 -> V_42 = V_24 ;
V_20 -> V_43 = V_20 -> V_25 = V_20 -> V_44 ;
F_15 ( V_20 -> V_44 , V_20 -> V_45 , V_24 ) ;
}
static int F_18 ( struct V_16 * V_17 )
{
struct V_19 * V_20 = F_7 ( V_17 ) ;
struct V_35 * V_39 ;
struct V_46 * V_47 ;
int V_48 ;
V_20 -> V_49 = V_20 -> V_33 = V_20 -> V_50 ;
F_15 ( V_20 -> V_50 , V_20 -> V_51 , V_32 ) ;
V_39 = V_20 -> V_50 ;
do {
V_47 = F_19 ( V_17 , V_29 ) ;
if ( ! V_47 ) {
V_48 = - V_52 ;
goto V_53;
}
V_39 -> V_26 = V_47 ;
V_39 -> V_28 = F_16 ( F_20 ( V_20 -> V_27 ,
V_39 -> V_26 -> V_54 ,
V_29 , V_34 ) ) ;
V_39 -> V_55 = V_56 ;
V_39 = V_39 -> V_31 ;
} while ( V_39 != V_20 -> V_50 );
return 0 ;
V_53:
F_14 ( V_17 ) ;
return V_48 ;
}
static void F_21 ( struct V_19 * V_20 )
{
void T_1 * V_1 = V_20 -> V_21 ;
int V_4 = V_5 ;
T_2 V_6 ;
F_2 ( V_57 , V_1 + V_58 ) ;
while ( V_4 -- ) {
V_6 = F_3 ( V_1 + V_58 ) ;
if ( V_6 & V_57 )
break;
}
F_2 ( V_59 , V_1 + V_60 ) ;
F_2 ( 0 , V_1 + V_60 ) ;
F_22 ( 5 ) ;
}
static void F_23 ( struct V_16 * V_17 )
{
struct V_19 * V_20 = F_7 ( V_17 ) ;
void T_1 * V_1 = V_20 -> V_21 ;
F_2 ( V_61 , V_1 + V_62 ) ;
F_21 ( V_20 ) ;
F_2 ( V_63 , V_1 + V_64 ) ;
F_2 ( V_29 , V_1 + V_65 ) ;
F_2 ( V_20 -> V_45 , V_1 + V_66 ) ;
F_2 ( V_20 -> V_45 >> 16 , V_1 + V_67 ) ;
F_2 ( V_20 -> V_51 , V_1 + V_68 ) ;
F_2 ( V_20 -> V_51 >> 16 , V_1 + V_69 ) ;
F_2 ( 0 , V_1 + V_70 ) ;
F_2 ( 0 , V_1 + V_71 ) ;
F_2 ( V_72 , V_1 + V_62 ) ;
F_2 ( V_20 -> V_73 | V_74 , V_1 ) ;
F_2 ( V_75 , V_1 + V_76 ) ;
}
static void F_24 ( struct V_16 * V_17 )
{
struct V_19 * V_18 = F_7 ( V_17 ) ;
void T_1 * V_1 = V_18 -> V_21 ;
F_25 ( V_17 , L_1
L_2 ,
F_3 ( V_1 + V_62 ) ,
F_3 ( V_1 + V_77 ) ) ;
V_17 -> V_78 . V_79 ++ ;
F_23 ( V_17 ) ;
}
static struct V_80 * F_26 ( struct V_16 * V_17 )
{
struct V_19 * V_18 = F_7 ( V_17 ) ;
void T_1 * V_1 = V_18 -> V_21 ;
unsigned long V_81 ;
F_27 ( & V_18 -> V_82 , V_81 ) ;
V_17 -> V_78 . V_83 += F_28 ( V_1 + V_84 ) ;
V_17 -> V_78 . V_85 += F_28 ( V_1 + V_86 ) ;
F_29 ( & V_18 -> V_82 , V_81 ) ;
return & V_17 -> V_78 ;
}
static void F_30 ( struct V_16 * V_17 )
{
struct V_19 * V_20 = F_7 ( V_17 ) ;
void T_1 * V_1 = V_20 -> V_21 ;
T_2 * V_87 ;
F_2 ( V_61 , V_1 + V_62 ) ;
F_21 ( V_20 ) ;
V_87 = ( T_2 * ) V_17 -> V_88 ;
F_2 ( V_87 [ 0 ] , V_1 + V_89 ) ;
F_2 ( V_87 [ 1 ] , V_1 + V_90 ) ;
F_2 ( V_87 [ 2 ] , V_1 + V_91 ) ;
F_31 ( V_20 -> V_92 ) ;
}
static int F_32 ( struct V_16 * V_17 )
{
struct V_19 * V_20 = F_7 ( V_17 ) ;
struct V_93 * V_27 = V_20 -> V_27 ;
F_33 ( & V_20 -> V_82 ) ;
F_34 ( & V_20 -> V_94 ) ;
F_35 ( V_17 ) ;
F_30 ( V_17 ) ;
F_36 ( V_17 -> V_95 , V_17 ) ;
F_14 ( V_17 ) ;
F_10 ( V_17 ) ;
F_37 ( & V_20 -> V_82 ) ;
if ( V_20 -> V_50 ) {
F_38 ( V_27 ,
V_96 , V_20 -> V_50 , V_20 -> V_51 ) ;
V_20 -> V_50 = NULL ;
}
if ( V_20 -> V_44 ) {
F_38 ( V_27 ,
V_97 , V_20 -> V_44 , V_20 -> V_45 ) ;
V_20 -> V_44 = NULL ;
}
return 0 ;
}
static int F_39 ( struct V_16 * V_17 , struct V_98 * V_99 , int V_6 )
{
struct V_19 * V_20 = F_7 ( V_17 ) ;
if ( ! V_20 -> V_92 )
return - V_100 ;
return F_40 ( V_20 -> V_92 , V_99 , V_6 ) ;
}
static int F_41 ( struct V_16 * V_17 , int V_4 )
{
struct V_19 * V_18 = F_7 ( V_17 ) ;
struct V_35 * V_101 = V_18 -> V_49 ;
struct V_46 * V_26 , * V_102 ;
int V_103 = 0 ;
T_2 V_104 ;
while ( V_103 < V_4 && ! ( V_101 -> V_55 & V_56 ) ) {
V_104 = V_101 -> V_55 ;
if ( V_104 & V_105 ) {
if ( V_104 & V_106 )
V_17 -> V_78 . V_107 ++ ;
if ( V_104 & V_108 )
V_17 -> V_78 . V_109 ++ ;
if ( V_104 & V_110 )
V_17 -> V_78 . V_109 ++ ;
if ( V_104 & V_111 )
V_17 -> V_78 . V_109 ++ ;
if ( V_104 & V_112 ) {
F_42 ( & V_18 -> V_82 ) ;
V_17 -> V_78 . V_83 ++ ;
F_43 ( & V_18 -> V_82 ) ;
}
goto V_113;
}
V_102 = F_19 ( V_17 , V_29 ) ;
if ( ! V_102 ) {
V_17 -> V_78 . V_114 ++ ;
goto V_113;
}
V_26 = V_101 -> V_26 ;
V_26 -> V_17 = V_18 -> V_17 ;
F_44 ( V_26 , V_101 -> V_115 - 4 ) ;
F_11 ( V_18 -> V_27 , F_12 ( V_101 -> V_28 ) ,
V_29 , V_34 ) ;
V_26 -> V_116 = F_45 ( V_26 , V_18 -> V_17 ) ;
F_46 ( V_26 ) ;
V_17 -> V_78 . V_117 ++ ;
V_17 -> V_78 . V_118 += V_101 -> V_115 - 4 ;
V_101 -> V_26 = V_102 ;
V_101 -> V_28 = F_16 ( F_20 ( V_18 -> V_27 ,
V_101 -> V_26 -> V_54 ,
V_29 , V_34 ) ) ;
V_113:
V_101 -> V_55 = V_56 ;
V_101 = V_101 -> V_31 ;
V_103 ++ ;
}
V_18 -> V_49 = V_101 ;
return V_103 ;
}
static void F_47 ( struct V_16 * V_17 )
{
struct V_19 * V_18 = F_7 ( V_17 ) ;
struct V_35 * V_101 ;
void T_1 * V_1 = V_18 -> V_21 ;
struct V_46 * V_26 ;
T_2 V_104 ;
F_42 ( & V_18 -> V_82 ) ;
V_101 = V_18 -> V_43 ;
while ( V_18 -> V_42 < V_24 ) {
V_104 = F_3 ( V_1 + V_119 ) ;
if ( V_104 & V_120 )
V_17 -> V_78 . V_121 ++ ;
if ( V_104 & ( V_122 | V_123 ) )
V_17 -> V_78 . V_124 ++ ;
if ( V_101 -> V_55 & V_56 )
break;
V_26 = V_101 -> V_26 ;
F_11 ( V_18 -> V_27 , F_12 ( V_101 -> V_28 ) ,
V_26 -> V_115 , V_30 ) ;
F_48 ( V_26 ) ;
V_101 -> V_26 = NULL ;
V_101 = V_101 -> V_31 ;
V_18 -> V_42 ++ ;
}
V_18 -> V_43 = V_101 ;
if ( V_18 -> V_42 )
F_49 ( V_17 ) ;
F_43 ( & V_18 -> V_82 ) ;
}
static int F_50 ( struct V_125 * V_94 , int V_126 )
{
struct V_19 * V_18 =
F_51 ( V_94 , struct V_19 , V_94 ) ;
struct V_16 * V_17 = V_18 -> V_17 ;
void T_1 * V_1 = V_18 -> V_21 ;
int V_127 ;
V_127 = F_41 ( V_17 , V_126 ) ;
if ( V_127 < V_126 ) {
F_52 ( V_94 ) ;
F_2 ( F_3 ( V_1 + V_62 ) | V_128 , V_1 + V_62 ) ;
}
return V_127 ;
}
static T_4 F_53 ( int V_95 , void * V_129 )
{
struct V_16 * V_17 = V_129 ;
struct V_19 * V_20 = F_7 ( V_17 ) ;
void T_1 * V_1 = V_20 -> V_21 ;
T_2 V_130 , V_55 ;
V_130 = F_3 ( V_1 + V_62 ) ;
F_2 ( V_61 , V_1 + V_62 ) ;
V_55 = F_3 ( V_1 + V_77 ) ;
if ( V_55 == 0x0000 || V_55 == 0xffff ) {
F_2 ( V_130 , V_1 + V_62 ) ;
return V_131 ;
}
if ( V_55 & V_128 ) {
if ( V_55 & V_132 ) {
V_17 -> V_78 . V_114 ++ ;
V_17 -> V_78 . V_133 ++ ;
}
if ( V_55 & V_134 )
V_17 -> V_78 . V_135 ++ ;
if ( F_54 ( F_55 ( & V_20 -> V_94 ) ) ) {
V_130 &= ~ V_128 ;
F_56 ( & V_20 -> V_94 ) ;
}
}
if ( V_55 & V_136 )
F_47 ( V_17 ) ;
F_2 ( V_130 , V_1 + V_62 ) ;
return V_137 ;
}
static void F_57 ( struct V_16 * V_17 )
{
F_58 ( V_17 -> V_95 ) ;
F_53 ( V_17 -> V_95 , V_17 ) ;
F_59 ( V_17 -> V_95 ) ;
}
static int F_60 ( struct V_16 * V_17 )
{
struct V_19 * V_20 = F_7 ( V_17 ) ;
void T_1 * V_1 = V_20 -> V_21 ;
int V_138 ;
F_17 ( V_17 ) ;
V_138 = F_18 ( V_17 ) ;
if ( V_138 )
return V_138 ;
F_5 ( V_1 , 30 , 17 ,
( F_1 ( V_1 , 30 , 17 ) | 0x4000 ) ) ;
F_5 ( V_1 , 30 , 17 ,
~ ( ( ~ F_1 ( V_1 , 30 , 17 ) ) | 0x2000 ) ) ;
F_5 ( V_1 , 0 , 19 , 0x0000 ) ;
F_5 ( V_1 , 0 , 30 , 0x01F0 ) ;
F_23 ( V_17 ) ;
F_61 ( V_20 -> V_92 ) ;
return 0 ;
}
static void F_62 ( struct V_16 * V_17 )
{
struct V_19 * V_20 = F_7 ( V_17 ) ;
void T_1 * V_1 = V_20 -> V_21 ;
T_2 * V_87 ;
F_21 ( V_20 ) ;
V_87 = ( T_2 * ) V_17 -> V_88 ;
F_2 ( V_87 [ 0 ] , V_1 + V_89 ) ;
F_2 ( V_87 [ 1 ] , V_1 + V_90 ) ;
F_2 ( V_87 [ 2 ] , V_1 + V_91 ) ;
}
static int F_63 ( struct V_16 * V_17 )
{
struct V_19 * V_20 = F_7 ( V_17 ) ;
int V_138 ;
V_138 = F_64 ( V_17 -> V_95 , F_53 ,
V_139 , V_17 -> V_140 , V_17 ) ;
if ( V_138 )
goto V_141;
F_62 ( V_17 ) ;
V_20 -> V_50 =
F_65 ( V_20 -> V_27 , V_96 , & V_20 -> V_51 ) ;
if ( ! V_20 -> V_50 ) {
V_138 = - V_52 ;
goto V_142;
}
V_20 -> V_44 =
F_65 ( V_20 -> V_27 , V_97 , & V_20 -> V_45 ) ;
if ( ! V_20 -> V_44 ) {
V_138 = - V_52 ;
goto V_143;
}
V_138 = F_60 ( V_17 ) ;
if ( V_138 )
goto V_144;
F_66 ( & V_20 -> V_94 ) ;
F_67 ( V_17 ) ;
return 0 ;
V_144:
F_38 ( V_20 -> V_27 , V_97 , V_20 -> V_44 ,
V_20 -> V_45 ) ;
V_143:
F_38 ( V_20 -> V_27 , V_96 , V_20 -> V_50 ,
V_20 -> V_51 ) ;
V_142:
F_36 ( V_17 -> V_95 , V_17 ) ;
V_141:
return V_138 ;
}
static T_5 F_68 ( struct V_46 * V_47 ,
struct V_16 * V_17 )
{
struct V_19 * V_20 = F_7 ( V_17 ) ;
struct V_35 * V_101 ;
void T_1 * V_1 = V_20 -> V_21 ;
unsigned long V_81 ;
F_27 ( & V_20 -> V_82 , V_81 ) ;
if ( ! V_20 -> V_42 ) {
F_29 ( & V_20 -> V_82 , V_81 ) ;
F_35 ( V_17 ) ;
F_69 ( V_17 , L_3 ) ;
return V_145 ;
}
V_17 -> V_78 . V_146 ++ ;
V_17 -> V_78 . V_147 += V_47 -> V_115 ;
V_20 -> V_42 -- ;
V_101 = V_20 -> V_25 ;
if ( V_47 -> V_115 < V_148 )
V_101 -> V_115 = V_148 ;
else
V_101 -> V_115 = V_47 -> V_115 ;
V_101 -> V_26 = V_47 ;
V_101 -> V_28 = F_16 ( F_20 ( V_20 -> V_27 ,
V_47 -> V_54 , V_47 -> V_115 , V_30 ) ) ;
V_101 -> V_55 = V_56 ;
F_70 ( V_47 ) ;
F_2 ( V_75 , V_1 + V_76 ) ;
V_20 -> V_25 = V_101 -> V_31 ;
if ( ! V_20 -> V_42 )
F_35 ( V_17 ) ;
F_29 ( & V_20 -> V_82 , V_81 ) ;
return V_149 ;
}
static void F_71 ( struct V_16 * V_17 )
{
struct V_19 * V_20 = F_7 ( V_17 ) ;
void T_1 * V_1 = V_20 -> V_21 ;
unsigned long V_81 ;
struct V_150 * V_151 ;
int V_23 ;
T_2 * V_87 ;
T_2 V_152 [ 4 ] = { 0 } ;
F_27 ( & V_20 -> V_82 , V_81 ) ;
V_87 = ( T_2 * ) V_17 -> V_88 ;
F_2 ( V_87 [ 0 ] , V_1 + V_89 ) ;
F_2 ( V_87 [ 1 ] , V_1 + V_90 ) ;
F_2 ( V_87 [ 2 ] , V_1 + V_91 ) ;
V_20 -> V_73 = F_3 ( V_1 + V_153 ) & ~ ( V_154 | V_155 ) ;
if ( V_17 -> V_81 & V_156 )
V_20 -> V_73 |= V_154 ;
else if ( V_17 -> V_81 & V_157 ) {
V_20 -> V_73 |= V_155 ;
for ( V_23 = 0 ; V_23 < V_158 ; V_23 ++ ) {
F_2 ( 0 , V_1 + V_159 + 8 * V_23 ) ;
F_2 ( 0 , V_1 + V_160 + 8 * V_23 ) ;
F_2 ( 0 , V_1 + V_161 + 8 * V_23 ) ;
}
for ( V_23 = 0 ; V_23 < 4 ; V_23 ++ )
V_152 [ V_23 ] = 0xffff ;
}
else if ( F_72 ( V_17 ) <= V_158 ) {
V_23 = 0 ;
F_73 (ha, dev) {
T_2 * V_87 = ( T_2 * ) V_151 -> V_162 ;
F_2 ( V_87 [ 0 ] , V_1 + V_159 + 8 * V_23 ) ;
F_2 ( V_87 [ 1 ] , V_1 + V_160 + 8 * V_23 ) ;
F_2 ( V_87 [ 2 ] , V_1 + V_161 + 8 * V_23 ) ;
V_23 ++ ;
}
while ( V_23 < V_158 ) {
F_2 ( 0 , V_1 + V_159 + 8 * V_23 ) ;
F_2 ( 0 , V_1 + V_160 + 8 * V_23 ) ;
F_2 ( 0 , V_1 + V_161 + 8 * V_23 ) ;
V_23 ++ ;
}
}
else {
T_6 V_163 ;
V_20 -> V_73 |= V_155 ;
for ( V_23 = 0 ; V_23 < V_158 ; V_23 ++ ) {
F_2 ( 0 , V_1 + V_159 + 8 * V_23 ) ;
F_2 ( 0 , V_1 + V_160 + 8 * V_23 ) ;
F_2 ( 0 , V_1 + V_161 + 8 * V_23 ) ;
}
F_73 (ha, dev) {
T_7 * V_164 = V_151 -> V_162 ;
V_163 = F_74 ( V_165 , V_164 ) ;
V_163 >>= 26 ;
V_152 [ V_163 >> 4 ] |= 1 << ( V_163 & 0xf ) ;
}
}
F_2 ( V_20 -> V_73 , V_1 + V_153 ) ;
if ( V_20 -> V_73 & V_155 ) {
F_2 ( V_152 [ 0 ] , V_1 + V_166 ) ;
F_2 ( V_152 [ 1 ] , V_1 + V_167 ) ;
F_2 ( V_152 [ 2 ] , V_1 + V_168 ) ;
F_2 ( V_152 [ 3 ] , V_1 + V_169 ) ;
}
F_29 ( & V_20 -> V_82 , V_81 ) ;
}
static void F_75 ( struct V_16 * V_17 ,
struct V_170 * V_171 )
{
struct V_19 * V_172 = F_7 ( V_17 ) ;
F_76 ( V_171 -> V_173 , V_174 , sizeof( V_171 -> V_173 ) ) ;
F_76 ( V_171 -> V_175 , V_176 , sizeof( V_171 -> V_175 ) ) ;
F_76 ( V_171 -> V_177 , F_77 ( V_172 -> V_27 ) , sizeof( V_171 -> V_177 ) ) ;
}
static int F_78 ( struct V_16 * V_17 , struct V_178 * V_6 )
{
struct V_19 * V_172 = F_7 ( V_17 ) ;
return F_79 ( V_172 -> V_92 , V_6 ) ;
}
static int F_80 ( struct V_16 * V_17 , struct V_178 * V_6 )
{
struct V_19 * V_172 = F_7 ( V_17 ) ;
return F_81 ( V_172 -> V_92 , V_6 ) ;
}
static void F_82 ( struct V_16 * V_17 )
{
struct V_19 * V_20 = F_7 ( V_17 ) ;
struct V_179 * V_92 = V_20 -> V_92 ;
int V_180 = 0 ;
void T_1 * V_1 = V_20 -> V_21 ;
F_83 ( ! V_92 ) ;
if ( V_20 -> V_181 != V_92 -> V_182 ) {
V_180 = 1 ;
V_20 -> V_181 = V_92 -> V_182 ;
}
if ( V_92 -> V_182 && ( V_20 -> V_183 != V_92 -> V_184 ) ) {
V_20 -> V_73 |= ( V_92 -> V_184 == V_185 ? V_186 : 0 ) ;
F_2 ( V_20 -> V_73 , V_1 ) ;
V_180 = 1 ;
V_20 -> V_183 = V_92 -> V_184 ;
}
if ( V_180 ) {
F_84 ( L_4 , V_17 -> V_140 , V_92 -> V_182 ?
L_5 : L_6 ) ;
if ( V_92 -> V_182 )
F_85 ( L_7 , V_92 -> V_187 ,
V_185 == V_92 -> V_184 ? L_8 : L_9 ) ;
F_85 ( L_10 ) ;
}
}
static int F_86 ( struct V_16 * V_17 )
{
struct V_19 * V_20 = F_7 ( V_17 ) ;
struct V_179 * V_92 = NULL ;
V_92 = F_87 ( V_20 -> V_14 ) ;
if ( ! V_92 ) {
F_88 ( & V_20 -> V_27 -> V_17 , L_11 ) ;
return - V_188 ;
}
V_92 = F_89 ( V_17 , F_90 ( & V_92 -> V_17 ) , & F_82 ,
V_189 ) ;
if ( F_91 ( V_92 ) ) {
F_88 ( & V_20 -> V_27 -> V_17 , L_12 ) ;
return F_92 ( V_92 ) ;
}
V_92 -> V_190 &= ( V_191
| V_192
| V_193
| V_194
| V_195
| V_196
| V_197 ) ;
V_92 -> V_198 = V_92 -> V_190 ;
V_20 -> V_92 = V_92 ;
V_20 -> V_181 = 0 ;
V_20 -> V_183 = - 1 ;
F_93 ( & V_20 -> V_27 -> V_17 , L_13
L_14 ,
V_92 -> V_199 -> V_140 , F_90 ( & V_92 -> V_17 ) ) ;
return 0 ;
}
static int F_94 ( struct V_93 * V_27 , const struct V_200 * V_201 )
{
struct V_16 * V_17 ;
struct V_19 * V_20 ;
void T_1 * V_1 ;
int V_104 , V_202 = V_203 ;
static int V_204 = - 1 ;
int V_205 = 0 ;
T_2 * V_87 ;
int V_23 ;
F_84 ( L_15 , V_175 ) ;
V_104 = F_95 ( V_27 ) ;
if ( V_104 )
goto V_206;
V_104 = F_96 ( V_27 , F_97 ( 32 ) ) ;
if ( V_104 ) {
F_88 ( & V_27 -> V_17 , L_16
L_17 ) ;
goto V_207;
}
V_104 = F_98 ( V_27 , F_97 ( 32 ) ) ;
if ( V_104 ) {
F_88 ( & V_27 -> V_17 , L_16
L_17 ) ;
goto V_207;
}
if ( F_99 ( V_27 , V_205 ) < V_202 ) {
F_88 ( & V_27 -> V_17 , L_18 ) ;
V_104 = - V_208 ;
goto V_207;
}
F_100 ( V_27 ) ;
V_17 = F_101 ( sizeof( struct V_19 ) ) ;
if ( ! V_17 ) {
V_104 = - V_52 ;
goto V_207;
}
F_102 ( V_17 , & V_27 -> V_17 ) ;
V_20 = F_7 ( V_17 ) ;
V_104 = F_103 ( V_27 , V_174 ) ;
if ( V_104 ) {
F_88 ( & V_27 -> V_17 , L_19 ) ;
goto V_209;
}
V_1 = F_104 ( V_27 , V_205 , V_202 ) ;
if ( ! V_1 ) {
F_88 ( & V_27 -> V_17 , L_20 ) ;
V_104 = - V_208 ;
goto V_210;
}
if ( F_3 ( V_1 + V_211 ) == 0 )
F_2 ( V_212 | V_213 << V_214 |
7 << V_215 , V_1 + V_211 ) ;
V_20 -> V_21 = V_1 ;
V_17 -> V_95 = V_27 -> V_95 ;
F_105 ( & V_20 -> V_82 ) ;
F_106 ( V_27 , V_17 ) ;
V_204 ++ ;
V_87 = ( T_2 * ) V_17 -> V_88 ;
V_87 [ 0 ] = F_3 ( V_1 + V_89 ) ;
V_87 [ 1 ] = F_3 ( V_1 + V_90 ) ;
V_87 [ 2 ] = F_3 ( V_1 + V_91 ) ;
if ( ! ( V_87 [ 0 ] || V_87 [ 1 ] || V_87 [ 2 ] ) ) {
F_25 ( V_17 , L_21
L_22 ) ;
F_107 ( V_17 ) ;
}
V_20 -> V_27 = V_27 ;
V_20 -> V_17 = V_17 ;
V_20 -> V_73 = V_216 | V_74 ;
V_17 -> V_217 = & V_218 ;
V_17 -> V_219 = & V_220 ;
V_17 -> V_221 = V_222 ;
F_108 ( V_17 , & V_20 -> V_94 , F_50 , 64 ) ;
V_20 -> V_14 = F_109 () ;
if ( ! V_20 -> V_14 ) {
F_88 ( & V_27 -> V_17 , L_23 ) ;
V_104 = - V_52 ;
goto V_223;
}
V_20 -> V_14 -> V_18 = V_17 ;
V_20 -> V_14 -> V_224 = F_6 ;
V_20 -> V_14 -> V_225 = F_8 ;
V_20 -> V_14 -> V_226 = F_9 ;
V_20 -> V_14 -> V_140 = L_24 ;
snprintf ( V_20 -> V_14 -> V_227 , V_228 , L_25 ,
F_90 ( & V_27 -> V_17 ) , V_204 ) ;
V_20 -> V_14 -> V_95 = F_110 ( V_213 , sizeof( int ) , V_229 ) ;
if ( ! V_20 -> V_14 -> V_95 ) {
V_104 = - V_52 ;
goto V_230;
}
for ( V_23 = 0 ; V_23 < V_213 ; V_23 ++ )
V_20 -> V_14 -> V_95 [ V_23 ] = V_231 ;
V_104 = F_111 ( V_20 -> V_14 ) ;
if ( V_104 ) {
F_88 ( & V_27 -> V_17 , L_26 ) ;
goto V_232;
}
V_104 = F_86 ( V_17 ) ;
if ( V_104 ) {
F_88 ( & V_27 -> V_17 , L_27 ) ;
goto V_233;
}
V_104 = F_112 ( V_17 ) ;
if ( V_104 ) {
F_88 ( & V_27 -> V_17 , L_28 ) ;
goto V_233;
}
return 0 ;
V_233:
F_113 ( V_20 -> V_14 ) ;
V_232:
F_114 ( V_20 -> V_14 -> V_95 ) ;
V_230:
F_115 ( V_20 -> V_14 ) ;
V_223:
F_116 ( & V_20 -> V_94 ) ;
F_117 ( V_27 , V_1 ) ;
V_210:
F_118 ( V_27 ) ;
V_209:
F_119 ( V_17 ) ;
V_207:
F_120 ( V_27 ) ;
V_206:
return V_104 ;
}
static void F_121 ( struct V_93 * V_27 )
{
struct V_16 * V_17 = F_122 ( V_27 ) ;
struct V_19 * V_20 = F_7 ( V_17 ) ;
F_123 ( V_17 ) ;
F_113 ( V_20 -> V_14 ) ;
F_114 ( V_20 -> V_14 -> V_95 ) ;
F_115 ( V_20 -> V_14 ) ;
F_116 ( & V_20 -> V_94 ) ;
F_117 ( V_27 , V_20 -> V_21 ) ;
F_118 ( V_27 ) ;
F_119 ( V_17 ) ;
F_120 ( V_27 ) ;
}
