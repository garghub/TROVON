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
if ( V_2 -> V_11 & V_12 )
F_8 ( & V_2 -> V_6 ,
V_2 -> V_11 & ~ V_13 ) ;
if ( V_2 -> V_11 & V_14 )
F_9 ( & V_2 -> V_6 ,
V_2 -> V_11 & ~ V_15 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_2 V_16 ;
V_16 = ( V_2 -> V_11 >> 16 ) & 0xff ;
if ( V_16 & V_17 )
V_6 -> V_18 . V_19 ++ ;
if ( V_16 & V_20 )
V_6 -> V_18 . V_21 ++ ;
if ( V_16 & V_22 )
V_6 -> V_18 . V_23 ++ ;
if ( V_16 & V_24 ) {
V_6 -> V_18 . V_25 ++ ;
F_11 ( V_6 ) ;
}
}
static T_3 F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_11 ;
T_3 V_26 ;
T_2 V_27 ;
T_2 V_28 ;
V_11 = F_3 ( V_6 -> V_10 + V_29 ) ;
V_27 = V_11 >> 24 ;
V_28 = ( V_11 & 0xC0 ) >> 6 ;
V_26 = V_27 | ( V_28 << 8 ) ;
return V_26 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_30 * V_31 = & V_6 -> V_32 -> V_6 ;
int V_33 ;
T_3 V_34 ;
int V_35 ;
V_34 = F_12 ( V_2 ) ;
if ( V_34 == 0 )
return;
if ( V_34 > V_36 )
V_34 = V_36 ;
V_35 = F_14 ( V_31 , V_34 ) ;
if ( V_35 != V_34 )
F_15 ( & V_2 -> V_37 -> V_38 ,
L_1 ,
V_35 ) ;
if ( V_35 == 0 )
return;
F_16 ( V_2 -> V_39 , V_6 -> V_10 + V_40 , V_35 ) ;
F_17 () ;
F_4 ( V_35 , V_6 -> V_10 + V_41 ) ;
V_33 = F_18 ( V_31 , V_2 -> V_39 , V_35 ) ;
if ( V_33 != V_35 )
F_15 ( & V_2 -> V_37 -> V_38 ,
L_2 ,
V_33 , V_35 ) ;
V_6 -> V_18 . V_42 += V_33 ;
F_19 ( V_31 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_43 * V_44 = & V_6 -> V_32 -> V_44 ;
T_1 V_45 ;
T_1 V_46 ;
int V_47 ;
int V_48 ;
int V_49 ;
int V_50 ;
int V_51 ;
int V_52 ;
if ( F_21 ( V_44 ) )
goto V_53;
if ( F_22 ( V_6 ) )
goto V_53;
if ( V_6 -> V_54 )
goto V_53;
V_47 = F_23 ( V_44 ) ;
if ( V_47 <= 0 )
goto V_53;
V_46 = F_3 ( V_6 -> V_10 + V_55 ) ;
V_45 = ( V_46 >> 16 ) & 0x3ff ;
V_46 &= 0x3ff ;
if ( V_45 > V_36 )
V_45 = V_36 ;
V_49 = V_36 - V_45 ;
if ( V_49 <= 0 ) {
F_24 ( L_3 ,
V_49 , V_47 ) ;
goto V_56;
}
if ( V_57 && V_47 >= 3 && F_25 ( V_46 ) )
V_48 = 4 - F_25 ( V_46 ) ;
else if ( V_47 > V_49 )
V_48 = V_49 ;
else
V_48 = V_47 ;
if ( V_48 <= 0 )
goto V_56;
V_50 = V_44 -> V_50 & ( V_58 - 1 ) ;
V_51 = V_44 -> V_51 & ( V_58 - 1 ) ;
V_52 = ( ( V_50 >= V_51 ) ? V_50 : V_58 ) - V_51 ;
V_48 = F_26 ( V_48 , V_52 ) ;
F_27 ( V_6 -> V_10 + V_59 , & V_44 -> V_60 [ V_44 -> V_51 ] , V_48 ) ;
V_44 -> V_51 = ( V_44 -> V_51 + V_48 ) & ( V_58 - 1 ) ;
F_28 () ;
F_4 ( V_48 & 0x3ff , V_6 -> V_10 + V_55 ) ;
V_6 -> V_18 . V_61 += V_48 ;
if ( F_23 ( V_44 ) < V_62 )
F_29 ( V_6 ) ;
V_56:
if ( ! F_21 ( V_44 ) )
F_1 ( V_2 , V_63 , V_64 ) ;
else
F_6 ( V_2 , V_63 , V_64 ) ;
V_53:
return;
}
static T_4 F_30 ( int V_65 , void * V_66 )
{
struct V_1 * V_2 = (struct V_1 * ) V_66 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
int V_67 ;
V_2 -> V_11 = F_3 ( V_6 -> V_10 + V_29 ) ;
if ( F_31 ( V_2 -> V_11 ) )
return V_68 ;
V_67 = F_32 ( V_2 -> V_11 ) ;
switch ( V_67 ) {
case V_69 :
F_7 ( V_2 ) ;
break;
case V_70 :
F_20 ( V_2 ) ;
break;
case V_71 :
F_33 ( & V_2 -> V_37 -> V_38 , L_4 ) ;
case V_72 :
F_13 ( V_2 ) ;
break;
case V_73 :
F_10 ( V_2 ) ;
break;
default:
F_15 ( & V_2 -> V_37 -> V_38 , L_5 , V_67 ) ;
return V_68 ;
}
return V_74 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_75 * V_38 = & V_2 -> V_37 -> V_38 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
int V_76 = 0 ;
V_76 = F_35 ( V_6 -> V_65 , F_30 , V_77 ,
L_6 , V_2 ) ;
if ( V_76 )
F_36 ( V_38 , L_7 , V_76 ) ;
return V_76 ;
}
static unsigned int F_37 ( struct V_5 * V_6 )
{
T_1 V_46 ;
T_3 V_45 ;
V_46 = F_3 ( V_6 -> V_10 + V_55 ) ;
V_45 = ( V_46 >> 16 ) & 0x3ff ;
if ( V_45 == 0 )
return V_78 ;
else
return 0 ;
}
static void F_38 ( struct V_5 * V_6 , unsigned int V_79 )
{
struct V_1 * V_2 = F_39 ( V_6 ) ;
T_1 V_80 = 0 ;
if ( V_79 & V_81 )
V_80 |= V_82 ;
if ( V_79 & V_83 )
V_80 |= V_84 ;
if ( V_79 & V_85 )
V_80 |= V_86 ;
if ( V_79 & V_87 )
V_80 |= V_88 ;
if ( V_79 & V_89 )
V_80 |= V_90 ;
F_1 ( V_2 , V_63 , V_80 ) ;
}
static unsigned int F_40 ( struct V_5 * V_6 )
{
unsigned int V_79 = 0 ;
T_1 V_11 ;
T_2 V_91 ;
V_11 = F_3 ( V_6 -> V_10 + V_29 ) ;
V_91 = ~ ( ( V_11 >> 8 ) & 0xff ) ;
if ( V_91 & V_15 )
V_79 |= V_92 ;
if ( V_91 & V_93 )
V_79 |= V_94 ;
if ( V_91 & V_95 )
V_79 |= V_96 ;
if ( V_91 & V_13 )
V_79 |= V_97 ;
return V_79 ;
}
static void F_41 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_39 ( V_6 ) ;
F_6 ( V_2 , V_63 , V_64 ) ;
}
static void F_42 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_39 ( V_6 ) ;
F_20 ( V_2 ) ;
}
static void F_43 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_39 ( V_6 ) ;
F_6 ( V_2 , V_63 , V_98 ) ;
}
static void F_44 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_39 ( V_6 ) ;
F_1 ( V_2 , V_63 , V_99 ) ;
}
static int F_45 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_39 ( V_6 ) ;
int V_76 ;
T_1 V_80 = 0 ;
V_76 = F_34 ( V_2 ) ;
if ( V_76 )
return - V_100 ;
V_80 = F_3 ( V_6 -> V_10 + V_63 ) ;
V_80 |= V_101 & ~ V_64 ;
V_80 &= ~ ( 0xff << 16 ) ;
V_80 |= ( V_102 << 16 ) ;
V_80 |= ( V_103 << 20 ) ;
F_4 ( V_80 , V_6 -> V_10 + V_63 ) ;
return 0 ;
}
static void F_46 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_39 ( V_6 ) ;
T_1 V_80 = 0 ;
V_80 |= V_101 ;
F_6 ( V_2 , V_63 , V_80 ) ;
F_47 ( V_2 -> V_6 . V_65 , V_2 ) ;
}
static void F_48 ( struct V_5 * V_6 ,
struct V_104 * V_105 ,
struct V_104 * V_106 )
{
unsigned int V_107 ;
T_1 V_80 ;
T_1 V_108 ;
T_1 V_109 ;
T_2 V_110 ;
V_80 = F_3 ( V_6 -> V_10 + V_63 ) ;
V_110 = F_49 ( V_80 ) ;
switch ( V_105 -> V_111 & V_112 ) {
case V_113 :
V_110 |= V_114 ;
break;
case V_115 :
V_110 |= V_116 ;
break;
case V_117 :
V_110 |= V_118 ;
break;
case V_119 :
V_110 |= V_120 ;
break;
}
if ( V_105 -> V_111 & V_121 )
V_110 |= V_122 << V_123 ;
if ( V_105 -> V_111 & V_124 ) {
V_110 |= V_125 << V_126 ;
if ( V_105 -> V_111 & V_127 )
V_110 |= V_128 << V_129 ;
else
V_110 |= V_130 << V_129 ;
} else
V_110 |= V_131 << V_126 ;
V_105 -> V_111 &= ~ V_132 ;
V_80 |= V_110 << V_133 ;
F_4 ( V_80 , V_6 -> V_10 + V_63 ) ;
V_109 = F_3 ( V_6 -> V_10 + V_134 ) ;
if ( V_109 == 0 )
V_109 = V_135 ;
V_107 = F_50 ( V_6 , V_105 , V_106 , 0 , V_109 / 16 ) ;
F_51 ( & V_6 -> V_9 ) ;
if ( F_52 ( V_105 ) )
F_53 ( V_105 , V_107 , V_107 ) ;
V_108 = V_109 / ( 4 * V_107 ) ;
F_4 ( V_108 , V_6 -> V_10 + V_136 ) ;
F_54 ( V_6 , V_105 -> V_111 , V_107 ) ;
F_55 ( & V_6 -> V_9 ) ;
}
static const char * F_56 ( struct V_5 * V_6 )
{
return V_137 ;
}
static void F_57 ( struct V_5 * V_6 )
{
F_58 ( V_6 -> V_10 ) ;
V_6 -> V_10 = NULL ;
F_59 ( V_6 -> V_138 , V_139 ) ;
}
static int F_60 ( struct V_5 * V_6 )
{
int V_34 = V_139 ;
if ( ! F_61 ( V_6 -> V_138 , V_34 , L_8 ) )
return - V_140 ;
V_6 -> V_10 = F_62 ( V_6 -> V_138 , V_139 ) ;
if ( V_6 -> V_10 == NULL ) {
F_59 ( V_6 -> V_138 , V_139 ) ;
return - V_141 ;
}
return 0 ;
}
static void F_63 ( struct V_5 * V_6 , int type )
{
V_6 -> type = V_142 ;
F_60 ( V_6 ) ;
}
static int F_64 ( struct V_5 * V_6 ,
struct V_143 * V_144 )
{
return - V_145 ;
}
static int F_65 ( struct V_146 * V_37 ,
const struct V_147 * V_148 )
{
struct V_1 * V_2 ;
struct V_149 * V_150 ;
struct V_75 * V_38 ;
int V_76 ;
V_38 = & V_37 -> V_38 ;
V_2 = F_66 ( V_38 , sizeof( struct V_1 ) , V_151 ) ;
if ( ! V_2 )
return - V_141 ;
V_2 -> V_39 = ( unsigned char * ) F_67 ( V_151 ) ;
if ( ! V_2 -> V_39 )
return - V_141 ;
V_150 = & V_37 -> V_150 ;
F_68 ( V_37 , V_2 ) ;
V_2 -> V_6 . V_152 = V_135 * 16 ;
V_2 -> V_6 . V_153 = V_154 ;
V_2 -> V_6 . V_155 = V_156 ;
V_2 -> V_6 . V_157 = & V_158 ;
V_2 -> V_6 . V_65 = F_69 ( V_37 ) ;
V_2 -> V_6 . V_155 = V_156 ;
V_2 -> V_6 . V_7 = V_159 | V_160 ;
V_2 -> V_6 . line = line ++ ;
V_2 -> V_6 . V_38 = V_38 ;
V_2 -> V_6 . type = V_142 ;
V_2 -> V_6 . V_138 = V_150 -> V_161 ;
V_2 -> V_6 . V_10 = NULL ;
V_2 -> V_37 = V_37 ;
F_70 ( & V_2 -> V_6 . V_9 ) ;
F_70 ( & V_2 -> V_9 ) ;
V_76 = F_71 ( & V_162 , & V_2 -> V_6 ) ;
if ( V_76 )
goto V_76;
return 0 ;
V_76:
F_72 ( ( unsigned long ) V_2 -> V_39 ) ;
F_36 ( V_38 , L_9 , V_76 ) ;
return V_76 ;
}
static void F_73 ( struct V_146 * V_37 )
{
struct V_1 * V_2 = F_74 ( V_37 ) ;
line -- ;
F_75 ( & V_162 , & V_2 -> V_6 ) ;
F_72 ( ( unsigned long ) V_2 -> V_39 ) ;
}
static int T_5 F_76 ( void )
{
int V_76 ;
V_76 = F_77 ( & V_162 ) ;
if ( V_76 ) {
F_24 ( L_10 , V_76 ) ;
return V_76 ;
}
V_76 = F_78 ( & V_163 ) ;
if ( V_76 ) {
F_24 ( L_11 , V_76 ) ;
F_79 ( & V_162 ) ;
return V_76 ;
}
return 0 ;
}
static void T_6 F_80 ( void )
{
F_81 ( & V_163 ) ;
F_79 ( & V_162 ) ;
}
