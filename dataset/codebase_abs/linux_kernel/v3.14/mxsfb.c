static inline T_1 F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
return ( V_3 & V_2 -> V_4 -> V_5 ) <<
V_2 -> V_4 -> V_6 ;
}
static inline T_1 F_2 ( struct V_1 * V_2 , unsigned V_3 )
{
return ( V_3 >> V_2 -> V_4 -> V_6 ) &
V_2 -> V_4 -> V_5 ;
}
static inline unsigned F_3 ( unsigned V_7 , struct V_8 * V_9 )
{
V_7 &= 0xffff ;
V_7 >>= 16 - V_9 -> V_10 ;
return V_7 << V_9 -> V_11 ;
}
static int F_4 ( struct V_12 * V_13 ,
struct V_14 * V_14 )
{
struct V_1 * V_2 = F_5 ( V_14 ) ;
const struct V_8 * V_15 = NULL ;
if ( V_13 -> V_16 < V_17 )
V_13 -> V_16 = V_17 ;
if ( V_13 -> V_18 < V_19 )
V_13 -> V_18 = V_19 ;
V_13 -> V_20 = V_13 -> V_16 ;
V_13 -> V_21 = V_13 -> V_18 ;
switch ( V_13 -> V_22 ) {
case 16 :
V_15 = V_23 ;
break;
case 32 :
switch ( V_2 -> V_24 ) {
case V_25 :
F_6 ( L_1 ) ;
break;
case V_26 :
case V_27 :
case V_28 :
V_15 = V_29 ;
break;
}
break;
default:
F_7 ( L_2 , V_13 -> V_22 ) ;
return - V_30 ;
}
V_13 -> V_31 = V_15 [ V_32 ] ;
V_13 -> V_33 = V_15 [ V_34 ] ;
V_13 -> V_35 = V_15 [ V_36 ] ;
V_13 -> V_37 = V_15 [ V_38 ] ;
return 0 ;
}
static void F_8 ( struct V_14 * V_14 )
{
struct V_1 * V_2 = F_5 ( V_14 ) ;
T_1 V_39 ;
int V_40 ;
F_9 ( & V_2 -> V_41 -> V_42 , L_3 , V_43 ) ;
if ( V_2 -> V_44 ) {
V_40 = F_10 ( V_2 -> V_44 ) ;
if ( V_40 ) {
F_11 ( & V_2 -> V_41 -> V_42 ,
L_4 , V_40 ) ;
return;
}
}
F_12 ( V_2 -> V_45 ) ;
F_13 ( V_2 -> V_45 , F_14 ( V_14 -> V_13 . V_46 ) * 1000U ) ;
F_15 ( V_47 , V_2 -> V_48 + V_49 + V_50 ) ;
V_39 = F_16 ( V_2 -> V_48 + V_51 ) ;
V_39 |= V_52 ;
F_15 ( V_39 , V_2 -> V_48 + V_51 ) ;
F_15 ( V_53 , V_2 -> V_48 + V_49 + V_50 ) ;
V_2 -> V_54 = 1 ;
}
static void F_17 ( struct V_14 * V_14 )
{
struct V_1 * V_2 = F_5 ( V_14 ) ;
unsigned V_55 ;
T_1 V_39 ;
int V_40 ;
F_9 ( & V_2 -> V_41 -> V_42 , L_3 , V_43 ) ;
F_15 ( V_47 , V_2 -> V_48 + V_49 + V_56 ) ;
V_55 = 1000 ;
while ( V_55 ) {
V_39 = F_16 ( V_2 -> V_48 + V_49 ) ;
if ( ! ( V_39 & V_53 ) )
break;
V_55 -- ;
}
V_39 = F_16 ( V_2 -> V_48 + V_51 ) ;
F_15 ( V_39 & ~ V_52 , V_2 -> V_48 + V_51 ) ;
F_18 ( V_2 -> V_45 ) ;
V_2 -> V_54 = 0 ;
if ( V_2 -> V_44 ) {
V_40 = F_19 ( V_2 -> V_44 ) ;
if ( V_40 )
F_11 ( & V_2 -> V_41 -> V_42 ,
L_5 , V_40 ) ;
}
}
static int F_20 ( struct V_14 * V_14 )
{
struct V_1 * V_2 = F_5 ( V_14 ) ;
T_1 V_57 , V_58 , V_59 ;
int V_60 , V_61 ;
int V_62 = 0 ;
V_60 = V_14 -> V_13 . V_16 * ( V_14 -> V_13 . V_22 >> 3 ) ;
V_61 = V_14 -> V_13 . V_21 * V_60 ;
if ( V_61 > V_14 -> V_63 . V_64 )
return - V_65 ;
V_14 -> V_63 . V_66 = V_60 ;
if ( V_2 -> V_54 ) {
V_62 = 1 ;
F_17 ( V_14 ) ;
}
F_15 ( V_67 , V_2 -> V_48 + V_68 + V_50 ) ;
V_57 = V_69 | V_70 |
F_21 ( V_2 -> V_24 ) ;
switch ( V_14 -> V_13 . V_22 ) {
case 16 :
F_9 ( & V_2 -> V_41 -> V_42 , L_6 ) ;
V_57 |= F_22 ( 0 ) ;
F_15 ( F_23 ( 0xf ) , V_2 -> V_48 + V_68 ) ;
break;
case 32 :
F_9 ( & V_2 -> V_41 -> V_42 , L_7 ) ;
V_57 |= F_22 ( 3 ) ;
switch ( V_2 -> V_24 ) {
case V_25 :
F_11 ( & V_2 -> V_41 -> V_42 ,
L_1 ) ;
return - V_30 ;
case V_26 :
case V_27 :
case V_28 :
break;
}
F_15 ( F_23 ( 0x7 ) , V_2 -> V_48 + V_68 ) ;
break;
default:
F_11 ( & V_2 -> V_41 -> V_42 , L_8 ,
V_14 -> V_13 . V_22 ) ;
return - V_30 ;
}
F_15 ( V_57 , V_2 -> V_48 + V_49 ) ;
F_15 ( F_24 ( V_14 -> V_13 . V_18 ) |
F_25 ( V_14 -> V_13 . V_16 ) ,
V_2 -> V_48 + V_2 -> V_4 -> V_71 ) ;
V_58 = V_72 |
V_73 |
V_74 |
F_26 ( V_14 -> V_13 . V_75 ) ;
if ( V_14 -> V_13 . V_76 & V_77 )
V_58 |= V_78 ;
if ( V_14 -> V_13 . V_76 & V_79 )
V_58 |= V_80 ;
if ( V_2 -> V_76 & V_81 )
V_58 |= V_82 ;
if ( V_2 -> V_76 & V_83 )
V_58 |= V_84 ;
F_15 ( V_58 , V_2 -> V_48 + V_85 ) ;
F_15 ( V_14 -> V_13 . V_86 + V_14 -> V_13 . V_75 +
V_14 -> V_13 . V_87 + V_14 -> V_13 . V_18 ,
V_2 -> V_48 + V_88 ) ;
F_15 ( F_1 ( V_2 , V_14 -> V_13 . V_89 ) |
F_27 ( V_14 -> V_13 . V_90 +
V_14 -> V_13 . V_89 + V_14 -> V_13 . V_91 +
V_14 -> V_13 . V_16 ) ,
V_2 -> V_48 + V_92 ) ;
F_15 ( F_28 ( V_14 -> V_13 . V_90 +
V_14 -> V_13 . V_89 ) |
F_29 ( V_14 -> V_13 . V_86 +
V_14 -> V_13 . V_75 ) ,
V_2 -> V_48 + V_93 ) ;
V_59 = F_30 ( V_14 -> V_13 . V_16 ) ;
if ( F_31 ( V_2 ) )
V_59 |= F_32 ( V_2 -> V_94 ) ;
F_15 ( V_59 , V_2 -> V_48 + V_51 ) ;
F_15 ( V_14 -> V_63 . V_95 +
V_14 -> V_63 . V_66 * V_14 -> V_13 . V_96 ,
V_2 -> V_48 + V_2 -> V_4 -> V_97 ) ;
if ( V_62 )
F_8 ( V_14 ) ;
return 0 ;
}
static int F_33 ( T_2 V_98 , T_2 V_31 , T_2 V_33 , T_2 V_35 ,
T_2 V_37 , struct V_14 * V_14 )
{
unsigned int V_3 ;
int V_40 = - V_30 ;
if ( V_14 -> V_13 . V_99 )
V_31 = V_33 = V_35 = ( 19595 * V_31 + 38470 * V_33 +
7471 * V_35 ) >> 16 ;
switch ( V_14 -> V_63 . V_100 ) {
case V_101 :
if ( V_98 < 16 ) {
T_1 * V_102 = V_14 -> V_103 ;
V_3 = F_3 ( V_31 , & V_14 -> V_13 . V_31 ) ;
V_3 |= F_3 ( V_33 , & V_14 -> V_13 . V_33 ) ;
V_3 |= F_3 ( V_35 , & V_14 -> V_13 . V_35 ) ;
V_102 [ V_98 ] = V_3 ;
V_40 = 0 ;
}
break;
case V_104 :
case V_105 :
break;
}
return V_40 ;
}
static int F_34 ( int V_106 , struct V_14 * V_14 )
{
struct V_1 * V_2 = F_5 ( V_14 ) ;
switch ( V_106 ) {
case V_107 :
case V_108 :
case V_109 :
case V_110 :
if ( V_2 -> V_54 )
F_17 ( V_14 ) ;
break;
case V_111 :
if ( ! V_2 -> V_54 )
F_8 ( V_14 ) ;
break;
}
return 0 ;
}
static int F_35 ( struct V_12 * V_13 ,
struct V_14 * V_14 )
{
struct V_1 * V_2 = F_5 ( V_14 ) ;
unsigned V_11 ;
if ( V_13 -> V_112 != 0 )
return - V_30 ;
V_11 = V_14 -> V_63 . V_66 * V_13 -> V_96 ;
F_15 ( V_14 -> V_63 . V_95 + V_11 ,
V_2 -> V_48 + V_2 -> V_4 -> V_97 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_113 * V_114 )
{
struct V_14 * V_14 = & V_2 -> V_14 ;
unsigned V_115 ;
unsigned V_116 ;
unsigned long V_117 , V_118 ;
int V_22 , V_119 ;
T_1 V_71 , V_58 , V_120 , V_121 , V_59 , V_57 ;
V_57 = F_16 ( V_2 -> V_48 + V_49 ) ;
if ( ! ( V_57 & V_53 ) )
return - V_30 ;
V_58 = F_16 ( V_2 -> V_48 + V_85 ) ;
V_120 = F_16 ( V_2 -> V_48 + V_92 ) ;
V_121 = F_16 ( V_2 -> V_48 + V_93 ) ;
V_59 = F_16 ( V_2 -> V_48 + V_51 ) ;
V_71 = F_16 ( V_2 -> V_48 + V_2 -> V_4 -> V_71 ) ;
V_114 -> V_16 = F_37 ( V_71 ) ;
V_114 -> V_18 = F_38 ( V_71 ) ;
switch ( F_39 ( V_57 ) ) {
case 0 :
V_22 = 16 ;
break;
case 3 :
V_22 = 32 ;
break;
case 1 :
default:
return - V_30 ;
}
V_14 -> V_13 . V_22 = V_22 ;
V_114 -> V_46 = F_40 ( F_41 ( V_2 -> V_45 ) / 1000U ) ;
V_114 -> V_89 = F_2 ( V_2 , V_120 ) ;
V_114 -> V_90 = F_42 ( V_121 ) - V_114 -> V_89 ;
V_114 -> V_91 = F_43 ( V_120 ) -
V_114 -> V_89 - V_114 -> V_90 - V_114 -> V_16 ;
V_114 -> V_75 = F_44 ( V_58 ) ;
V_116 = F_16 ( V_2 -> V_48 + V_88 ) ;
V_114 -> V_86 = F_45 ( V_121 ) - V_114 -> V_75 ;
V_114 -> V_87 = V_116 - V_114 -> V_75 -
V_114 -> V_86 - V_114 -> V_18 ;
V_114 -> V_114 = V_122 ;
V_114 -> V_76 = 0 ;
if ( V_58 & V_78 )
V_114 -> V_76 |= V_77 ;
if ( V_58 & V_80 )
V_114 -> V_76 |= V_79 ;
F_6 ( L_9 ) ;
F_6 ( L_10 ,
V_114 -> V_16 , V_114 -> V_18 , V_114 -> V_89 , V_114 -> V_90 ,
V_114 -> V_91 , V_114 -> V_75 , V_114 -> V_86 ,
V_114 -> V_87 ) ;
F_6 ( L_11 , F_14 ( V_114 -> V_46 ) ) ;
V_2 -> V_24 = F_46 ( V_57 ) ;
V_2 -> V_94 = F_47 ( V_59 ) ;
V_14 -> V_63 . V_66 = V_114 -> V_16 * ( V_22 >> 3 ) ;
V_117 = F_16 ( V_2 -> V_48 + V_2 -> V_4 -> V_123 ) ;
V_118 = V_14 -> V_63 . V_66 * V_114 -> V_18 ;
if ( V_117 < V_14 -> V_63 . V_95 )
return - V_30 ;
if ( V_117 + V_118 > V_14 -> V_63 . V_95 + V_14 -> V_63 . V_64 )
return - V_30 ;
V_119 = V_117 - V_14 -> V_63 . V_95 ;
if ( V_119 ) {
memmove ( V_14 -> V_124 , V_14 -> V_124 + V_119 , V_118 ) ;
F_15 ( V_14 -> V_63 . V_95 , V_2 -> V_48 + V_2 -> V_4 -> V_97 ) ;
}
V_115 = V_14 -> V_63 . V_64 / V_14 -> V_63 . V_66 ;
V_14 -> V_63 . V_125 = 1 ;
F_12 ( V_2 -> V_45 ) ;
V_2 -> V_54 = 1 ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_113 * V_114 )
{
struct V_14 * V_14 = & V_2 -> V_14 ;
struct V_12 * V_13 = & V_14 -> V_13 ;
struct V_126 * V_42 = & V_2 -> V_41 -> V_42 ;
struct V_127 * V_128 = V_2 -> V_41 -> V_42 . V_129 ;
struct V_127 * V_130 ;
struct V_131 V_132 ;
T_1 V_133 ;
int V_40 ;
V_130 = F_49 ( V_128 , L_12 , 0 ) ;
if ( ! V_130 ) {
F_11 ( V_42 , L_13 ) ;
return - V_134 ;
}
V_40 = F_50 ( V_130 , L_14 , & V_133 ) ;
if ( V_40 < 0 ) {
F_11 ( V_42 , L_15 ) ;
goto V_135;
}
switch ( V_133 ) {
case 8 :
V_2 -> V_24 = V_25 ;
break;
case 16 :
V_2 -> V_24 = V_26 ;
break;
case 18 :
V_2 -> V_24 = V_27 ;
break;
case 24 :
V_2 -> V_24 = V_28 ;
break;
default:
F_11 ( V_42 , L_16 ) ;
V_40 = - V_30 ;
goto V_135;
}
V_40 = F_50 ( V_130 , L_17 ,
& V_13 -> V_22 ) ;
if ( V_40 < 0 ) {
F_11 ( V_42 , L_18 ) ;
goto V_135;
}
V_40 = F_51 ( V_130 , & V_132 , V_136 ) ;
if ( V_40 ) {
F_11 ( V_42 , L_19 ) ;
goto V_135;
}
V_40 = F_52 ( & V_132 , V_114 ) ;
if ( V_40 < 0 )
goto V_135;
if ( V_132 . V_137 & V_138 )
V_2 -> V_76 |= V_81 ;
if ( V_132 . V_137 & V_139 )
V_2 -> V_76 |= V_83 ;
V_135:
F_53 ( V_130 ) ;
return V_40 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_113 * V_114 )
{
int V_40 ;
struct V_14 * V_14 = & V_2 -> V_14 ;
struct V_12 * V_13 = & V_14 -> V_13 ;
T_3 V_140 ;
void * V_141 ;
unsigned V_61 ;
V_14 -> V_142 = & V_143 ;
V_14 -> V_137 = V_144 | V_145 ;
F_55 ( V_14 -> V_63 . V_146 , L_20 , sizeof( V_14 -> V_63 . V_146 ) ) ;
V_14 -> V_63 . type = V_147 ;
V_14 -> V_63 . V_125 = 1 ;
V_14 -> V_63 . V_100 = V_101 ,
V_14 -> V_63 . V_148 = V_149 ;
V_40 = F_48 ( V_2 , V_114 ) ;
if ( V_40 )
return V_40 ;
V_13 -> V_150 = 0 ;
V_13 -> V_151 = V_152 ;
V_13 -> V_153 = 0 ;
V_13 -> V_114 = V_122 ;
V_61 = V_154 ;
V_141 = F_56 ( V_61 , V_155 ) ;
if ( ! V_141 )
return - V_65 ;
V_140 = F_57 ( V_141 ) ;
V_14 -> V_63 . V_95 = V_140 ;
V_14 -> V_124 = V_141 ;
V_14 -> V_156 = V_14 -> V_63 . V_64 = V_61 ;
if ( F_36 ( V_2 , V_114 ) )
memset ( V_141 , 0 , V_61 ) ;
return 0 ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = & V_2 -> V_14 ;
F_59 ( V_14 -> V_124 , V_14 -> V_63 . V_64 ) ;
}
static int F_60 ( struct V_157 * V_41 )
{
const struct V_158 * V_159 =
F_61 ( V_160 , & V_41 -> V_42 ) ;
struct V_161 * V_162 ;
struct V_1 * V_2 ;
struct V_14 * V_14 ;
struct V_113 * V_163 ;
int V_40 ;
if ( V_159 )
V_41 -> V_164 = V_159 -> V_165 ;
V_14 = F_62 ( sizeof( struct V_1 ) , & V_41 -> V_42 ) ;
if ( ! V_14 ) {
F_11 ( & V_41 -> V_42 , L_21 ) ;
return - V_65 ;
}
V_163 = F_63 ( & V_41 -> V_42 , sizeof( struct V_113 ) ,
V_166 ) ;
if ( V_163 == NULL )
return - V_65 ;
V_2 = F_5 ( V_14 ) ;
V_162 = F_64 ( V_41 , V_167 , 0 ) ;
V_2 -> V_48 = F_65 ( & V_41 -> V_42 , V_162 ) ;
if ( F_66 ( V_2 -> V_48 ) ) {
V_40 = F_67 ( V_2 -> V_48 ) ;
goto V_168;
}
V_2 -> V_41 = V_41 ;
F_68 ( V_41 , V_2 ) ;
V_2 -> V_4 = & V_169 [ V_41 -> V_164 -> V_170 ] ;
V_2 -> V_45 = F_69 ( & V_2 -> V_41 -> V_42 , NULL ) ;
if ( F_66 ( V_2 -> V_45 ) ) {
V_40 = F_67 ( V_2 -> V_45 ) ;
goto V_168;
}
V_2 -> V_44 = F_70 ( & V_41 -> V_42 , L_22 ) ;
if ( F_66 ( V_2 -> V_44 ) )
V_2 -> V_44 = NULL ;
V_14 -> V_103 = F_63 ( & V_41 -> V_42 , sizeof( T_1 ) * 16 ,
V_166 ) ;
if ( ! V_14 -> V_103 ) {
V_40 = - V_65 ;
goto V_168;
}
V_40 = F_54 ( V_2 , V_163 ) ;
if ( V_40 != 0 )
goto V_168;
F_71 ( & V_14 -> V_13 , V_163 ) ;
F_4 ( & V_14 -> V_13 , V_14 ) ;
F_68 ( V_41 , V_14 ) ;
V_40 = F_72 ( V_14 ) ;
if ( V_40 != 0 ) {
F_11 ( & V_41 -> V_42 , L_23 ) ;
goto V_171;
}
if ( ! V_2 -> V_54 ) {
F_15 ( 0 , V_2 -> V_48 + V_49 ) ;
F_20 ( V_14 ) ;
F_8 ( V_14 ) ;
}
F_73 ( & V_41 -> V_42 , L_24 ) ;
return 0 ;
V_171:
if ( V_2 -> V_54 )
F_18 ( V_2 -> V_45 ) ;
V_168:
F_74 ( V_14 ) ;
return V_40 ;
}
static int F_75 ( struct V_157 * V_41 )
{
struct V_14 * V_14 = F_76 ( V_41 ) ;
struct V_1 * V_2 = F_5 ( V_14 ) ;
if ( V_2 -> V_54 )
F_17 ( V_14 ) ;
F_77 ( V_14 ) ;
F_58 ( V_2 ) ;
F_74 ( V_14 ) ;
return 0 ;
}
static void F_78 ( struct V_157 * V_41 )
{
struct V_14 * V_14 = F_76 ( V_41 ) ;
struct V_1 * V_2 = F_5 ( V_14 ) ;
F_15 ( V_53 , V_2 -> V_48 + V_49 + V_56 ) ;
}
