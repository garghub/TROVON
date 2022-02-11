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
if ( V_2 -> V_45 )
F_12 ( V_2 -> V_45 ) ;
if ( V_2 -> V_46 )
F_12 ( V_2 -> V_46 ) ;
F_12 ( V_2 -> V_47 ) ;
F_13 ( V_2 -> V_47 , F_14 ( V_14 -> V_13 . V_48 ) * 1000U ) ;
F_15 ( V_49 , V_2 -> V_50 + V_51 + V_52 ) ;
V_39 = F_16 ( V_2 -> V_50 + V_53 ) ;
V_39 |= V_54 ;
F_15 ( V_39 , V_2 -> V_50 + V_53 ) ;
F_15 ( V_55 , V_2 -> V_50 + V_51 + V_52 ) ;
V_2 -> V_56 = 1 ;
}
static void F_17 ( struct V_14 * V_14 )
{
struct V_1 * V_2 = F_5 ( V_14 ) ;
unsigned V_57 ;
T_1 V_39 ;
int V_40 ;
F_9 ( & V_2 -> V_41 -> V_42 , L_3 , V_43 ) ;
F_15 ( V_49 , V_2 -> V_50 + V_51 + V_58 ) ;
V_57 = 1000 ;
while ( V_57 ) {
V_39 = F_16 ( V_2 -> V_50 + V_51 ) ;
if ( ! ( V_39 & V_55 ) )
break;
V_57 -- ;
}
V_39 = F_16 ( V_2 -> V_50 + V_53 ) ;
F_15 ( V_39 & ~ V_54 , V_2 -> V_50 + V_53 ) ;
F_18 ( V_2 -> V_47 ) ;
if ( V_2 -> V_46 )
F_18 ( V_2 -> V_46 ) ;
if ( V_2 -> V_45 )
F_18 ( V_2 -> V_45 ) ;
V_2 -> V_56 = 0 ;
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
T_1 V_59 , V_60 , V_61 ;
int V_62 , V_63 ;
int V_64 = 0 ;
V_62 = V_14 -> V_13 . V_16 * ( V_14 -> V_13 . V_22 >> 3 ) ;
V_63 = V_14 -> V_13 . V_21 * V_62 ;
if ( V_63 > V_14 -> V_65 . V_66 )
return - V_67 ;
V_14 -> V_65 . V_68 = V_62 ;
if ( V_2 -> V_56 ) {
V_64 = 1 ;
F_17 ( V_14 ) ;
}
F_15 ( V_69 , V_2 -> V_50 + V_70 + V_52 ) ;
V_59 = V_71 | V_72 |
F_21 ( V_2 -> V_24 ) ;
switch ( V_14 -> V_13 . V_22 ) {
case 16 :
F_9 ( & V_2 -> V_41 -> V_42 , L_6 ) ;
V_59 |= F_22 ( 0 ) ;
F_15 ( F_23 ( 0xf ) , V_2 -> V_50 + V_70 ) ;
break;
case 32 :
F_9 ( & V_2 -> V_41 -> V_42 , L_7 ) ;
V_59 |= F_22 ( 3 ) ;
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
F_15 ( F_23 ( 0x7 ) , V_2 -> V_50 + V_70 ) ;
break;
default:
F_11 ( & V_2 -> V_41 -> V_42 , L_8 ,
V_14 -> V_13 . V_22 ) ;
return - V_30 ;
}
F_15 ( V_59 , V_2 -> V_50 + V_51 ) ;
F_15 ( F_24 ( V_14 -> V_13 . V_18 ) |
F_25 ( V_14 -> V_13 . V_16 ) ,
V_2 -> V_50 + V_2 -> V_4 -> V_73 ) ;
V_60 = V_74 |
V_75 |
V_76 |
F_26 ( V_14 -> V_13 . V_77 ) ;
if ( V_14 -> V_13 . V_78 & V_79 )
V_60 |= V_80 ;
if ( V_14 -> V_13 . V_78 & V_81 )
V_60 |= V_82 ;
if ( V_2 -> V_78 & V_83 )
V_60 |= V_84 ;
if ( V_2 -> V_78 & V_85 )
V_60 |= V_86 ;
F_15 ( V_60 , V_2 -> V_50 + V_87 ) ;
F_15 ( V_14 -> V_13 . V_88 + V_14 -> V_13 . V_77 +
V_14 -> V_13 . V_89 + V_14 -> V_13 . V_18 ,
V_2 -> V_50 + V_90 ) ;
F_15 ( F_1 ( V_2 , V_14 -> V_13 . V_91 ) |
F_27 ( V_14 -> V_13 . V_92 +
V_14 -> V_13 . V_91 + V_14 -> V_13 . V_93 +
V_14 -> V_13 . V_16 ) ,
V_2 -> V_50 + V_94 ) ;
F_15 ( F_28 ( V_14 -> V_13 . V_92 +
V_14 -> V_13 . V_91 ) |
F_29 ( V_14 -> V_13 . V_88 +
V_14 -> V_13 . V_77 ) ,
V_2 -> V_50 + V_95 ) ;
V_61 = F_30 ( V_14 -> V_13 . V_16 ) ;
if ( F_31 ( V_2 ) )
V_61 |= F_32 ( V_2 -> V_96 ) ;
F_15 ( V_61 , V_2 -> V_50 + V_53 ) ;
F_15 ( V_14 -> V_65 . V_97 +
V_14 -> V_65 . V_68 * V_14 -> V_13 . V_98 ,
V_2 -> V_50 + V_2 -> V_4 -> V_99 ) ;
if ( V_64 )
F_8 ( V_14 ) ;
return 0 ;
}
static int F_33 ( T_2 V_100 , T_2 V_31 , T_2 V_33 , T_2 V_35 ,
T_2 V_37 , struct V_14 * V_14 )
{
unsigned int V_3 ;
int V_40 = - V_30 ;
if ( V_14 -> V_13 . V_101 )
V_31 = V_33 = V_35 = ( 19595 * V_31 + 38470 * V_33 +
7471 * V_35 ) >> 16 ;
switch ( V_14 -> V_65 . V_102 ) {
case V_103 :
if ( V_100 < 16 ) {
T_1 * V_104 = V_14 -> V_105 ;
V_3 = F_3 ( V_31 , & V_14 -> V_13 . V_31 ) ;
V_3 |= F_3 ( V_33 , & V_14 -> V_13 . V_33 ) ;
V_3 |= F_3 ( V_35 , & V_14 -> V_13 . V_35 ) ;
V_104 [ V_100 ] = V_3 ;
V_40 = 0 ;
}
break;
case V_106 :
case V_107 :
break;
}
return V_40 ;
}
static int F_34 ( int V_108 , struct V_14 * V_14 )
{
struct V_1 * V_2 = F_5 ( V_14 ) ;
switch ( V_108 ) {
case V_109 :
case V_110 :
case V_111 :
case V_112 :
if ( V_2 -> V_56 )
F_17 ( V_14 ) ;
break;
case V_113 :
if ( ! V_2 -> V_56 )
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
if ( V_13 -> V_114 != 0 )
return - V_30 ;
V_11 = V_14 -> V_65 . V_68 * V_13 -> V_98 ;
F_15 ( V_14 -> V_65 . V_97 + V_11 ,
V_2 -> V_50 + V_2 -> V_4 -> V_99 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_115 * V_116 )
{
struct V_14 * V_14 = & V_2 -> V_14 ;
unsigned V_117 ;
unsigned V_118 ;
unsigned long V_119 , V_120 ;
int V_22 , V_121 ;
T_1 V_73 , V_60 , V_122 , V_123 , V_61 , V_59 ;
V_59 = F_16 ( V_2 -> V_50 + V_51 ) ;
if ( ! ( V_59 & V_55 ) )
return - V_30 ;
V_60 = F_16 ( V_2 -> V_50 + V_87 ) ;
V_122 = F_16 ( V_2 -> V_50 + V_94 ) ;
V_123 = F_16 ( V_2 -> V_50 + V_95 ) ;
V_61 = F_16 ( V_2 -> V_50 + V_53 ) ;
V_73 = F_16 ( V_2 -> V_50 + V_2 -> V_4 -> V_73 ) ;
V_116 -> V_16 = F_37 ( V_73 ) ;
V_116 -> V_18 = F_38 ( V_73 ) ;
switch ( F_39 ( V_59 ) ) {
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
V_116 -> V_48 = F_40 ( F_41 ( V_2 -> V_47 ) / 1000U ) ;
V_116 -> V_91 = F_2 ( V_2 , V_122 ) ;
V_116 -> V_92 = F_42 ( V_123 ) - V_116 -> V_91 ;
V_116 -> V_93 = F_43 ( V_122 ) -
V_116 -> V_91 - V_116 -> V_92 - V_116 -> V_16 ;
V_116 -> V_77 = F_44 ( V_60 ) ;
V_118 = F_16 ( V_2 -> V_50 + V_90 ) ;
V_116 -> V_88 = F_45 ( V_123 ) - V_116 -> V_77 ;
V_116 -> V_89 = V_118 - V_116 -> V_77 -
V_116 -> V_88 - V_116 -> V_18 ;
V_116 -> V_116 = V_124 ;
V_116 -> V_78 = 0 ;
if ( V_60 & V_80 )
V_116 -> V_78 |= V_79 ;
if ( V_60 & V_82 )
V_116 -> V_78 |= V_81 ;
F_6 ( L_9 ) ;
F_6 ( L_10 ,
V_116 -> V_16 , V_116 -> V_18 , V_116 -> V_91 , V_116 -> V_92 ,
V_116 -> V_93 , V_116 -> V_77 , V_116 -> V_88 ,
V_116 -> V_89 ) ;
F_6 ( L_11 , F_14 ( V_116 -> V_48 ) ) ;
V_2 -> V_24 = F_46 ( V_59 ) ;
V_2 -> V_96 = F_47 ( V_61 ) ;
V_14 -> V_65 . V_68 = V_116 -> V_16 * ( V_22 >> 3 ) ;
V_119 = F_16 ( V_2 -> V_50 + V_2 -> V_4 -> V_125 ) ;
V_120 = V_14 -> V_65 . V_68 * V_116 -> V_18 ;
if ( V_119 < V_14 -> V_65 . V_97 )
return - V_30 ;
if ( V_119 + V_120 > V_14 -> V_65 . V_97 + V_14 -> V_65 . V_66 )
return - V_30 ;
V_121 = V_119 - V_14 -> V_65 . V_97 ;
if ( V_121 ) {
memmove ( V_14 -> V_126 , V_14 -> V_126 + V_121 , V_120 ) ;
F_15 ( V_14 -> V_65 . V_97 , V_2 -> V_50 + V_2 -> V_4 -> V_99 ) ;
}
V_117 = V_14 -> V_65 . V_66 / V_14 -> V_65 . V_68 ;
V_14 -> V_65 . V_127 = 1 ;
F_12 ( V_2 -> V_47 ) ;
V_2 -> V_56 = 1 ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_115 * V_116 )
{
struct V_14 * V_14 = & V_2 -> V_14 ;
struct V_12 * V_13 = & V_14 -> V_13 ;
struct V_128 * V_42 = & V_2 -> V_41 -> V_42 ;
struct V_129 * V_130 = V_2 -> V_41 -> V_42 . V_131 ;
struct V_129 * V_132 ;
struct V_133 V_134 ;
T_1 V_135 ;
int V_40 ;
V_132 = F_49 ( V_130 , L_12 , 0 ) ;
if ( ! V_132 ) {
F_11 ( V_42 , L_13 ) ;
return - V_136 ;
}
V_40 = F_50 ( V_132 , L_14 , & V_135 ) ;
if ( V_40 < 0 ) {
F_11 ( V_42 , L_15 ) ;
goto V_137;
}
switch ( V_135 ) {
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
goto V_137;
}
V_40 = F_50 ( V_132 , L_17 ,
& V_13 -> V_22 ) ;
if ( V_40 < 0 ) {
F_11 ( V_42 , L_18 ) ;
goto V_137;
}
V_40 = F_51 ( V_132 , & V_134 , V_138 ) ;
if ( V_40 ) {
F_11 ( V_42 , L_19 ) ;
goto V_137;
}
V_40 = F_52 ( & V_134 , V_116 ) ;
if ( V_40 < 0 )
goto V_137;
if ( V_134 . V_139 & V_140 )
V_2 -> V_78 |= V_83 ;
if ( V_134 . V_139 & V_141 )
V_2 -> V_78 |= V_85 ;
V_137:
F_53 ( V_132 ) ;
return V_40 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_115 * V_116 )
{
int V_40 ;
struct V_14 * V_14 = & V_2 -> V_14 ;
struct V_12 * V_13 = & V_14 -> V_13 ;
T_3 V_142 ;
void * V_143 ;
unsigned V_63 ;
V_14 -> V_144 = & V_145 ;
V_14 -> V_139 = V_146 | V_147 ;
F_55 ( V_14 -> V_65 . V_148 , L_20 , sizeof( V_14 -> V_65 . V_148 ) ) ;
V_14 -> V_65 . type = V_149 ;
V_14 -> V_65 . V_127 = 1 ;
V_14 -> V_65 . V_102 = V_103 ,
V_14 -> V_65 . V_150 = V_151 ;
V_40 = F_48 ( V_2 , V_116 ) ;
if ( V_40 )
return V_40 ;
V_13 -> V_152 = 0 ;
V_13 -> V_153 = V_154 ;
V_13 -> V_155 = 0 ;
V_13 -> V_116 = V_124 ;
V_63 = V_156 ;
V_143 = F_56 ( V_63 , V_157 ) ;
if ( ! V_143 )
return - V_67 ;
V_142 = F_57 ( V_143 ) ;
V_14 -> V_65 . V_97 = V_142 ;
V_14 -> V_126 = V_143 ;
V_14 -> V_158 = V_14 -> V_65 . V_66 = V_63 ;
if ( F_36 ( V_2 , V_116 ) )
memset ( V_143 , 0 , V_63 ) ;
return 0 ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = & V_2 -> V_14 ;
F_59 ( V_14 -> V_126 , V_14 -> V_65 . V_66 ) ;
}
static int F_60 ( struct V_159 * V_41 )
{
const struct V_160 * V_161 =
F_61 ( V_162 , & V_41 -> V_42 ) ;
struct V_163 * V_164 ;
struct V_1 * V_2 ;
struct V_14 * V_14 ;
struct V_115 * V_165 ;
int V_40 ;
if ( V_161 )
V_41 -> V_166 = V_161 -> V_167 ;
V_14 = F_62 ( sizeof( struct V_1 ) , & V_41 -> V_42 ) ;
if ( ! V_14 ) {
F_11 ( & V_41 -> V_42 , L_21 ) ;
return - V_67 ;
}
V_165 = F_63 ( & V_41 -> V_42 , sizeof( struct V_115 ) ,
V_168 ) ;
if ( V_165 == NULL )
return - V_67 ;
V_2 = F_5 ( V_14 ) ;
V_164 = F_64 ( V_41 , V_169 , 0 ) ;
V_2 -> V_50 = F_65 ( & V_41 -> V_42 , V_164 ) ;
if ( F_66 ( V_2 -> V_50 ) ) {
V_40 = F_67 ( V_2 -> V_50 ) ;
goto V_170;
}
V_2 -> V_41 = V_41 ;
F_68 ( V_41 , V_2 ) ;
V_2 -> V_4 = & V_171 [ V_41 -> V_166 -> V_172 ] ;
V_2 -> V_47 = F_69 ( & V_2 -> V_41 -> V_42 , NULL ) ;
if ( F_66 ( V_2 -> V_47 ) ) {
V_40 = F_67 ( V_2 -> V_47 ) ;
goto V_170;
}
V_2 -> V_45 = F_69 ( & V_2 -> V_41 -> V_42 , L_22 ) ;
if ( F_66 ( V_2 -> V_45 ) )
V_2 -> V_45 = NULL ;
V_2 -> V_46 = F_69 ( & V_2 -> V_41 -> V_42 , L_23 ) ;
if ( F_66 ( V_2 -> V_46 ) )
V_2 -> V_46 = NULL ;
V_2 -> V_44 = F_70 ( & V_41 -> V_42 , L_24 ) ;
if ( F_66 ( V_2 -> V_44 ) )
V_2 -> V_44 = NULL ;
V_14 -> V_105 = F_63 ( & V_41 -> V_42 , sizeof( T_1 ) * 16 ,
V_168 ) ;
if ( ! V_14 -> V_105 ) {
V_40 = - V_67 ;
goto V_170;
}
V_40 = F_54 ( V_2 , V_165 ) ;
if ( V_40 != 0 )
goto V_170;
F_71 ( & V_14 -> V_13 , V_165 ) ;
F_4 ( & V_14 -> V_13 , V_14 ) ;
F_68 ( V_41 , V_14 ) ;
V_40 = F_72 ( V_14 ) ;
if ( V_40 != 0 ) {
F_11 ( & V_41 -> V_42 , L_25 ) ;
goto V_173;
}
if ( ! V_2 -> V_56 ) {
F_15 ( 0 , V_2 -> V_50 + V_51 ) ;
F_20 ( V_14 ) ;
F_8 ( V_14 ) ;
}
F_73 ( & V_41 -> V_42 , L_26 ) ;
return 0 ;
V_173:
if ( V_2 -> V_56 )
F_18 ( V_2 -> V_47 ) ;
V_170:
F_74 ( V_14 ) ;
return V_40 ;
}
static int F_75 ( struct V_159 * V_41 )
{
struct V_14 * V_14 = F_76 ( V_41 ) ;
struct V_1 * V_2 = F_5 ( V_14 ) ;
if ( V_2 -> V_56 )
F_17 ( V_14 ) ;
F_77 ( V_14 ) ;
F_58 ( V_2 ) ;
F_74 ( V_14 ) ;
return 0 ;
}
static void F_78 ( struct V_159 * V_41 )
{
struct V_14 * V_14 = F_76 ( V_41 ) ;
struct V_1 * V_2 = F_5 ( V_14 ) ;
F_15 ( V_55 , V_2 -> V_50 + V_51 + V_58 ) ;
}
