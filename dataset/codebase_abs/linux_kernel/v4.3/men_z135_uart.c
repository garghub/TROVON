static inline void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
unsigned long V_7 ;
T_1 V_8 ;
F_2 ( & V_2 -> V_9 , V_7 ) ;
V_8 = F_3 ( V_6 -> V_10 + V_3 ) ;
V_8 |= V_4 ;
F_4 ( V_8 , V_6 -> V_10 + V_3 ) ;
F_5 ( & V_2 -> V_9 , V_7 ) ;
}
static inline void F_6 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
unsigned long V_7 ;
T_1 V_8 ;
F_2 ( & V_2 -> V_9 , V_7 ) ;
V_8 = F_3 ( V_6 -> V_10 + V_3 ) ;
V_8 &= ~ V_4 ;
F_4 ( V_8 , V_6 -> V_10 + V_3 ) ;
F_5 ( & V_2 -> V_9 , V_7 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_2 V_11 ;
V_11 = ( V_2 -> V_12 >> 8 ) & 0xff ;
if ( V_11 & V_13 )
F_8 ( & V_2 -> V_6 ,
V_11 & V_14 ) ;
if ( V_11 & V_15 )
F_9 ( & V_2 -> V_6 ,
V_11 & V_16 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_2 V_17 ;
V_17 = ( V_2 -> V_12 >> 16 ) & 0xff ;
if ( V_17 & V_18 )
V_6 -> V_19 . V_20 ++ ;
if ( V_17 & V_21 )
V_6 -> V_19 . V_22 ++ ;
if ( V_17 & V_23 )
V_6 -> V_19 . V_24 ++ ;
if ( V_17 & V_25 ) {
V_6 -> V_19 . V_26 ++ ;
F_11 ( V_6 ) ;
}
}
static T_3 F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_12 ;
T_3 V_27 ;
T_2 V_28 ;
T_2 V_29 ;
V_12 = F_3 ( V_6 -> V_10 + V_30 ) ;
V_28 = V_12 >> 24 ;
V_29 = ( V_12 & 0xC0 ) >> 6 ;
V_27 = V_28 | ( V_29 << 8 ) ;
return V_27 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_31 * V_32 = & V_6 -> V_33 -> V_6 ;
int V_34 ;
T_3 V_35 ;
int V_36 ;
V_35 = F_12 ( V_2 ) ;
if ( V_35 == 0 )
return;
if ( V_35 > V_37 )
V_35 = V_37 ;
V_36 = F_14 ( V_32 , V_35 ) ;
if ( V_36 != V_35 )
F_15 ( & V_2 -> V_38 -> V_39 ,
L_1 ,
V_36 ) ;
if ( V_36 == 0 )
return;
F_16 ( V_2 -> V_40 , V_6 -> V_10 + V_41 , V_36 ) ;
F_17 () ;
F_4 ( V_36 , V_6 -> V_10 + V_42 ) ;
V_34 = F_18 ( V_32 , V_2 -> V_40 , V_36 ) ;
if ( V_34 != V_36 )
F_15 ( & V_2 -> V_38 -> V_39 ,
L_2 ,
V_34 , V_36 ) ;
V_6 -> V_19 . V_43 += V_34 ;
F_19 ( V_32 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_44 * V_45 = & V_6 -> V_33 -> V_45 ;
T_1 V_46 ;
T_1 V_47 ;
int V_48 ;
int V_49 ;
int V_50 ;
int V_51 ;
int V_52 ;
int V_53 ;
if ( F_21 ( V_45 ) )
goto V_54;
if ( F_22 ( V_6 ) )
goto V_54;
if ( V_6 -> V_55 )
goto V_54;
V_48 = F_23 ( V_45 ) ;
if ( V_48 <= 0 )
goto V_54;
V_47 = F_3 ( V_6 -> V_10 + V_56 ) ;
V_46 = ( V_47 >> 16 ) & 0x3ff ;
V_47 &= 0x3ff ;
if ( V_46 > V_37 )
V_46 = V_37 ;
V_50 = V_37 - V_46 ;
if ( V_50 <= 0 ) {
F_24 ( & V_2 -> V_38 -> V_39 ,
L_3 ,
V_50 , V_48 ) ;
goto V_57;
}
if ( V_58 && V_48 >= 3 && F_25 ( V_47 ) )
V_49 = 4 - F_25 ( V_47 ) ;
else if ( V_48 > V_50 )
V_49 = V_50 ;
else
V_49 = V_48 ;
if ( V_49 <= 0 )
goto V_57;
V_51 = V_45 -> V_51 & ( V_59 - 1 ) ;
V_52 = V_45 -> V_52 & ( V_59 - 1 ) ;
V_53 = ( ( V_51 >= V_52 ) ? V_51 : V_59 ) - V_52 ;
V_49 = F_26 ( V_49 , V_53 ) ;
F_27 ( V_6 -> V_10 + V_60 , & V_45 -> V_61 [ V_45 -> V_52 ] , V_49 ) ;
V_45 -> V_52 = ( V_45 -> V_52 + V_49 ) & ( V_59 - 1 ) ;
F_28 () ;
F_4 ( V_49 & 0x3ff , V_6 -> V_10 + V_56 ) ;
V_6 -> V_19 . V_62 += V_49 ;
if ( F_23 ( V_45 ) < V_63 )
F_29 ( V_6 ) ;
V_57:
if ( ! F_21 ( V_45 ) )
F_1 ( V_2 , V_64 , V_65 ) ;
else
F_6 ( V_2 , V_64 , V_65 ) ;
V_54:
return;
}
static T_4 F_30 ( int V_66 , void * V_67 )
{
struct V_1 * V_2 = (struct V_1 * ) V_67 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
bool V_68 = false ;
int V_69 ;
V_2 -> V_12 = F_3 ( V_6 -> V_10 + V_30 ) ;
V_69 = F_31 ( V_2 -> V_12 ) ;
if ( ! V_69 )
goto V_54;
F_32 ( & V_6 -> V_9 ) ;
F_33 ( V_69 , V_6 -> V_10 + V_30 ) ;
if ( V_69 & V_70 ) {
F_10 ( V_2 ) ;
V_68 = true ;
}
if ( V_69 & ( V_71 | V_72 ) ) {
if ( V_69 & V_72 )
F_34 ( & V_2 -> V_38 -> V_39 , L_4 ) ;
F_13 ( V_2 ) ;
V_68 = true ;
}
if ( V_69 & V_73 ) {
F_20 ( V_2 ) ;
V_68 = true ;
}
if ( V_69 & V_74 ) {
F_7 ( V_2 ) ;
V_68 = true ;
}
F_35 ( & V_6 -> V_9 ) ;
V_54:
return F_36 ( V_68 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_75 * V_39 = & V_2 -> V_38 -> V_39 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
int V_76 = 0 ;
V_76 = F_38 ( V_6 -> V_66 , F_30 , V_77 ,
L_5 , V_2 ) ;
if ( V_76 )
F_24 ( V_39 , L_6 , V_76 ) ;
return V_76 ;
}
static unsigned int F_39 ( struct V_5 * V_6 )
{
T_1 V_47 ;
T_3 V_46 ;
V_47 = F_3 ( V_6 -> V_10 + V_56 ) ;
V_46 = ( V_47 >> 16 ) & 0x3ff ;
if ( V_46 == 0 )
return V_78 ;
else
return 0 ;
}
static void F_40 ( struct V_5 * V_6 , unsigned int V_79 )
{
T_1 V_80 ;
T_1 V_81 ;
V_81 = V_80 = F_3 ( V_6 -> V_10 + V_64 ) ;
if ( V_79 & V_82 )
V_81 |= V_83 ;
else
V_81 &= ~ V_83 ;
if ( V_79 & V_84 )
V_81 |= V_85 ;
else
V_81 &= ~ V_85 ;
if ( V_79 & V_86 )
V_81 |= V_87 ;
else
V_81 &= ~ V_87 ;
if ( V_79 & V_88 )
V_81 |= V_89 ;
else
V_81 &= ~ V_89 ;
if ( V_79 & V_90 )
V_81 |= V_91 ;
else
V_81 &= ~ V_91 ;
if ( V_81 != V_80 )
F_4 ( V_81 , V_6 -> V_10 + V_64 ) ;
}
static unsigned int F_41 ( struct V_5 * V_6 )
{
unsigned int V_79 = 0 ;
T_2 V_11 ;
V_11 = F_42 ( V_6 -> V_10 + V_30 + 1 ) ;
if ( V_11 & V_16 )
V_79 |= V_92 ;
if ( V_11 & V_93 )
V_79 |= V_94 ;
if ( V_11 & V_95 )
V_79 |= V_96 ;
if ( V_11 & V_14 )
V_79 |= V_97 ;
return V_79 ;
}
static void F_43 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_44 ( V_6 ) ;
F_6 ( V_2 , V_64 , V_65 ) ;
}
static void F_45 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_44 ( V_6 ) ;
F_6 ( V_2 , V_64 , V_98 ) ;
}
static void F_46 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_44 ( V_6 ) ;
if ( V_2 -> V_99 )
F_45 ( V_6 ) ;
F_20 ( V_2 ) ;
}
static void F_47 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_44 ( V_6 ) ;
F_6 ( V_2 , V_64 , V_100 ) ;
}
static void F_48 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_44 ( V_6 ) ;
F_1 ( V_2 , V_64 , V_98 ) ;
}
static int F_49 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_44 ( V_6 ) ;
int V_76 ;
T_1 V_81 = 0 ;
V_76 = F_37 ( V_2 ) ;
if ( V_76 )
return - V_101 ;
V_81 = F_3 ( V_6 -> V_10 + V_64 ) ;
V_81 |= V_102 & ~ V_65 ;
V_81 &= ~ ( 0xff << 16 ) ;
V_81 |= ( V_103 << 16 ) ;
V_81 |= ( V_104 << 20 ) ;
F_4 ( V_81 , V_6 -> V_10 + V_64 ) ;
if ( V_105 )
F_4 ( V_105 , V_6 -> V_10 + V_106 ) ;
return 0 ;
}
static void F_50 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_44 ( V_6 ) ;
T_1 V_81 = 0 ;
V_81 |= V_102 ;
F_6 ( V_2 , V_64 , V_81 ) ;
F_51 ( V_2 -> V_6 . V_66 , V_2 ) ;
}
static void F_52 ( struct V_5 * V_6 ,
struct V_107 * V_108 ,
struct V_107 * V_80 )
{
struct V_1 * V_2 = F_44 ( V_6 ) ;
unsigned int V_109 ;
T_1 V_81 ;
T_1 V_110 ;
T_1 V_111 ;
T_2 V_112 ;
V_81 = F_3 ( V_6 -> V_10 + V_64 ) ;
V_112 = F_53 ( V_81 ) ;
switch ( V_108 -> V_113 & V_114 ) {
case V_115 :
V_112 |= V_116 ;
break;
case V_117 :
V_112 |= V_118 ;
break;
case V_119 :
V_112 |= V_120 ;
break;
case V_121 :
V_112 |= V_122 ;
break;
}
if ( V_108 -> V_113 & V_123 )
V_112 |= V_124 << V_125 ;
if ( V_108 -> V_113 & V_126 ) {
V_112 |= V_127 << V_128 ;
if ( V_108 -> V_113 & V_129 )
V_112 |= V_130 << V_131 ;
else
V_112 |= V_132 << V_131 ;
} else
V_112 |= V_133 << V_128 ;
V_81 |= V_98 ;
if ( V_108 -> V_113 & V_134 ) {
V_81 |= V_135 ;
V_2 -> V_99 = true ;
V_108 -> V_113 &= ~ V_136 ;
} else {
V_81 &= ~ V_135 ;
V_2 -> V_99 = false ;
}
V_108 -> V_113 &= ~ V_137 ;
V_81 |= V_112 << V_138 ;
F_4 ( V_81 , V_6 -> V_10 + V_64 ) ;
V_111 = F_3 ( V_6 -> V_10 + V_139 ) ;
if ( V_111 == 0 )
V_111 = V_140 ;
V_109 = F_54 ( V_6 , V_108 , V_80 , 0 , V_111 / 16 ) ;
F_55 ( & V_6 -> V_9 ) ;
if ( F_56 ( V_108 ) )
F_57 ( V_108 , V_109 , V_109 ) ;
V_110 = V_111 / ( 4 * V_109 ) ;
F_4 ( V_110 , V_6 -> V_10 + V_141 ) ;
F_58 ( V_6 , V_108 -> V_113 , V_109 ) ;
F_59 ( & V_6 -> V_9 ) ;
}
static const char * F_60 ( struct V_5 * V_6 )
{
return V_142 ;
}
static void F_61 ( struct V_5 * V_6 )
{
F_62 ( V_6 -> V_10 ) ;
V_6 -> V_10 = NULL ;
F_63 ( V_6 -> V_143 , V_144 ) ;
}
static int F_64 ( struct V_5 * V_6 )
{
int V_35 = V_144 ;
if ( ! F_65 ( V_6 -> V_143 , V_35 , L_7 ) )
return - V_145 ;
V_6 -> V_10 = F_66 ( V_6 -> V_143 , V_144 ) ;
if ( V_6 -> V_10 == NULL ) {
F_63 ( V_6 -> V_143 , V_144 ) ;
return - V_146 ;
}
return 0 ;
}
static void F_67 ( struct V_5 * V_6 , int type )
{
V_6 -> type = V_147 ;
F_64 ( V_6 ) ;
}
static int F_68 ( struct V_5 * V_6 ,
struct V_148 * V_149 )
{
return - V_150 ;
}
static int F_69 ( struct V_151 * V_38 ,
const struct V_152 * V_153 )
{
struct V_1 * V_2 ;
struct V_154 * V_155 ;
struct V_75 * V_39 ;
int V_76 ;
V_39 = & V_38 -> V_39 ;
V_2 = F_70 ( V_39 , sizeof( struct V_1 ) , V_156 ) ;
if ( ! V_2 )
return - V_146 ;
V_2 -> V_40 = ( unsigned char * ) F_71 ( V_156 ) ;
if ( ! V_2 -> V_40 )
return - V_146 ;
V_155 = & V_38 -> V_155 ;
F_72 ( V_38 , V_2 ) ;
V_2 -> V_6 . V_157 = V_140 * 16 ;
V_2 -> V_6 . V_158 = V_159 ;
V_2 -> V_6 . V_160 = V_161 ;
V_2 -> V_6 . V_162 = & V_163 ;
V_2 -> V_6 . V_66 = F_73 ( V_38 ) ;
V_2 -> V_6 . V_160 = V_161 ;
V_2 -> V_6 . V_7 = V_164 | V_165 ;
V_2 -> V_6 . line = line ++ ;
V_2 -> V_6 . V_39 = V_39 ;
V_2 -> V_6 . type = V_147 ;
V_2 -> V_6 . V_143 = V_155 -> V_166 ;
V_2 -> V_6 . V_10 = NULL ;
V_2 -> V_38 = V_38 ;
F_74 ( & V_2 -> V_9 ) ;
V_76 = F_75 ( & V_167 , & V_2 -> V_6 ) ;
if ( V_76 )
goto V_76;
return 0 ;
V_76:
F_76 ( ( unsigned long ) V_2 -> V_40 ) ;
F_24 ( V_39 , L_8 , V_76 ) ;
return V_76 ;
}
static void F_77 ( struct V_151 * V_38 )
{
struct V_1 * V_2 = F_78 ( V_38 ) ;
line -- ;
F_79 ( & V_167 , & V_2 -> V_6 ) ;
F_76 ( ( unsigned long ) V_2 -> V_40 ) ;
}
static int T_5 F_80 ( void )
{
int V_76 ;
V_76 = F_81 ( & V_167 ) ;
if ( V_76 ) {
F_82 ( L_9 , V_76 ) ;
return V_76 ;
}
V_76 = F_83 ( & V_168 ) ;
if ( V_76 ) {
F_82 ( L_10 , V_76 ) ;
F_84 ( & V_167 ) ;
return V_76 ;
}
return 0 ;
}
static void T_6 F_85 ( void )
{
F_86 ( & V_168 ) ;
F_84 ( & V_167 ) ;
}
