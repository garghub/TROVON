static int F_1 ( struct V_1 * V_2 , unsigned char V_3 , unsigned short V_4 )
{
int V_5 ;
T_1 V_6 [ 3 ] = { V_7 , 0 , 0 } ;
T_1 V_8 [ 3 ] = { V_9 , 0 , 0 } ;
if ( ! V_2 )
return - V_10 ;
V_6 [ 2 ] = V_3 ;
V_8 [ 1 ] = V_4 >> 8 ;
V_8 [ 2 ] = V_4 & 0xFF ;
V_5 = F_2 ( V_2 , V_6 , F_3 ( V_6 ) ) ;
V_5 |= F_2 ( V_2 , V_8 , F_3 ( V_8 ) ) ;
return V_5 ;
}
static int T_2 F_4 ( struct V_1 * V_2 )
{
int V_5 ;
struct V_11 * V_12 ;
struct V_13 * V_14 = F_5 ( V_2 -> V_15 . V_16 ,
struct V_13 ,
V_17 . V_16 ) ;
V_12 = F_6 ( sizeof( * V_12 ) , V_18 ) ;
if ( ! V_12 )
return - V_19 ;
V_12 -> V_20 = ( V_14 -> V_21 -> V_20 &
V_22 ) | V_23 ;
V_5 = F_1 ( V_2 , V_24 , V_25 ) ;
V_5 |= F_1 ( V_2 , V_26 , V_12 -> V_20 ) ;
if ( V_5 ) {
F_7 ( V_12 ) ;
return V_5 ;
}
F_8 ( V_2 , V_12 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_24 , V_27 ) ;
}
static int F_10 ( struct V_1 * V_2 , T_3 V_28 )
{
return F_1 ( V_2 , V_24 , V_27 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_5 ;
struct V_11 * V_12 = F_12 ( V_2 ) ;
V_5 = F_1 ( V_2 , V_26 , V_12 -> V_20 ) ;
if ( V_5 )
return V_5 ;
return F_1 ( V_2 , V_24 , V_25 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_24 , V_27 ) ;
}
static int F_14 ( struct V_13 * V_14 , unsigned V_29 )
{
if ( V_14 -> V_21 -> V_30 )
F_15 ( V_14 -> V_21 -> V_31 , V_29 ) ;
return 0 ;
}
static int F_16 ( struct V_13 * V_32 )
{
unsigned long V_33 , V_34 ;
switch ( V_32 -> V_21 -> V_35 ) {
case V_36 :
V_32 -> V_37 = 16 ;
V_33 = 1 ;
V_34 = 0 ;
break;
case V_38 :
V_32 -> V_37 = 16 ;
V_33 = 2 ;
V_34 = 3 ;
break;
case V_39 :
V_32 -> V_37 = 24 ;
V_33 = 3 ;
V_34 = 5 ;
break;
default:
return - V_40 ;
}
V_32 -> V_41 = ( V_42 * V_33 ) ;
V_32 -> V_43 = ( 336 * V_33 ) ;
V_32 -> V_44 = ( 2 * V_33 ) ;
V_32 -> V_45 = ( 7 * V_33 + V_34 ) ;
V_32 -> V_46 = ( V_47 + V_48 ) ;
V_32 -> V_49 = ( 2 * V_33 ) ;
V_32 -> V_50 = ( V_32 -> V_43 * V_32 -> V_46 ) ;
return 0 ;
}
static void F_17 ( struct V_13 * V_32 )
{
unsigned V_51 ;
if ( V_32 -> V_21 -> V_35 == V_36 )
V_51 = V_52 ;
else
V_51 = ( V_53 | V_54 ) ;
F_18 ( V_32 -> V_45 ) ;
F_19 ( V_32 -> V_41 - 1 ) ;
F_20 ( V_32 -> V_46 ) ;
F_21 ( V_55 |
V_56 |
V_57 |
V_51 |
V_58 ) ;
}
static inline void F_22 ( void )
{
F_21 ( F_23 () & ~ V_59 ) ;
}
static inline void F_24 ( void )
{
F_21 ( F_23 () | V_59 ) ;
}
static void F_25 ( void )
{
F_26 ( V_60 | V_61 ) ;
}
static void F_27 ( void )
{
F_28 ( V_61 | V_60 ) ;
F_29 ( 0 , V_62 | V_63 |
V_64 | V_65 |
V_66 | V_67 ) ;
}
static void F_30 ( struct V_13 * V_32 )
{
F_27 () ;
F_31 ( V_68 , V_32 -> V_43 ) ;
F_32 ( V_68 , V_32 -> V_44 ) ;
F_33 ( V_68 , V_69 | V_70 |
V_71 | V_72 |
V_73 ) ;
F_31 ( V_74 , V_32 -> V_50 ) ;
F_32 ( V_74 , V_32 -> V_49 ) ;
F_33 ( V_74 , V_69 | V_70 |
V_71 | V_72 |
V_73 ) ;
}
static void F_34 ( struct V_13 * V_32 )
{
F_35 ( V_75 ,
F_36 ( V_76 , V_77 ,
V_78 , V_79 ,
V_80 ,
V_81 ) ) ;
F_37 ( V_75 , ( V_42 * V_32 -> V_37 ) / V_82 ) ;
F_38 ( V_75 , V_82 / 8 ) ;
F_39 ( V_75 , V_32 -> V_46 ) ;
F_40 ( V_75 , V_82 / 8 ) ;
F_41 ( V_75 , ( unsigned long ) V_32 -> V_83 ) ;
}
static inline void F_42 ( unsigned V_84 )
{
if ( V_84 )
F_43 ( V_85 ) ;
else
F_43 ( V_86 ) ;
if ( V_87 )
F_44 ( F_45 ( V_88 ) ) ;
}
static int T_2 F_46 ( struct V_89 * V_90 ,
unsigned V_84 )
{
int V_5 ;
if ( V_87 ) {
int V_5 = F_47 ( F_45 ( V_88 ) , L_1 ) ;
if ( V_5 )
return V_5 ;
F_48 ( F_45 ( V_88 ) , 0 ) ;
}
if ( V_84 )
V_5 = F_49 ( V_85 , V_91 ) ;
else
V_5 = F_49 ( V_86 , V_91 ) ;
if ( V_5 ) {
F_50 ( & V_90 -> V_15 , L_2 ) ;
return - V_92 ;
}
return 0 ;
}
static int F_51 ( struct V_93 * V_14 , int V_94 )
{
struct V_13 * V_32 = V_14 -> V_95 ;
F_52 ( & V_32 -> V_96 ) ;
V_32 -> V_97 ++ ;
if ( V_32 -> V_97 <= 1 ) {
F_22 () ;
F_53 () ;
F_34 ( V_32 ) ;
F_17 ( V_32 ) ;
F_30 ( V_32 ) ;
F_54 ( V_75 ) ;
F_24 () ;
F_25 () ;
F_14 ( V_32 , 1 ) ;
}
F_55 ( & V_32 -> V_96 ) ;
return 0 ;
}
static int F_56 ( struct V_93 * V_14 , int V_94 )
{
struct V_13 * V_32 = V_14 -> V_95 ;
F_52 ( & V_32 -> V_96 ) ;
V_32 -> V_97 -- ;
if ( V_32 -> V_97 <= 0 ) {
F_14 ( V_32 , 0 ) ;
F_22 () ;
F_53 () ;
F_57 ( V_75 ) ;
F_27 () ;
}
F_55 ( & V_32 -> V_96 ) ;
return 0 ;
}
static int F_58 ( struct V_98 * V_99 ,
struct V_93 * V_14 )
{
struct V_13 * V_32 = V_14 -> V_95 ;
if ( V_99 -> V_100 == V_32 -> V_37 ) {
V_99 -> V_101 . V_102 = V_14 -> V_99 . V_101 . V_102 ;
V_99 -> V_103 . V_102 = V_14 -> V_99 . V_103 . V_102 ;
V_99 -> V_104 . V_102 = V_14 -> V_99 . V_104 . V_102 ;
V_99 -> V_101 . V_105 = V_14 -> V_99 . V_101 . V_105 ;
V_99 -> V_103 . V_105 = V_14 -> V_99 . V_103 . V_105 ;
V_99 -> V_104 . V_105 = V_14 -> V_99 . V_104 . V_105 ;
V_99 -> V_106 . V_102 = 0 ;
V_99 -> V_106 . V_105 = 0 ;
V_99 -> V_106 . V_107 = 0 ;
V_99 -> V_101 . V_107 = 0 ;
V_99 -> V_103 . V_107 = 0 ;
V_99 -> V_104 . V_107 = 0 ;
} else {
F_59 ( L_3 , V_108 ,
V_99 -> V_100 ) ;
return - V_40 ;
}
if ( V_14 -> V_99 . V_109 != V_99 -> V_109 || V_14 -> V_99 . V_110 != V_99 -> V_110 ||
V_14 -> V_99 . V_111 != V_99 -> V_111 ||
V_14 -> V_99 . V_112 != V_99 -> V_112 ) {
F_59 ( L_4 ,
V_108 , V_99 -> V_109 , V_99 -> V_110 ) ;
return - V_40 ;
}
if ( ( V_14 -> V_113 . V_114 * V_99 -> V_112 ) > V_14 -> V_113 . V_115 ) {
F_59 ( L_5 ,
V_108 , V_99 -> V_112 ) ;
return - V_19 ;
}
return 0 ;
}
int F_60 ( struct V_93 * V_14 , struct V_116 * V_117 )
{
if ( V_118 )
return 0 ;
else
return - V_40 ;
}
static int F_61 ( T_4 V_119 , T_4 V_101 , T_4 V_103 ,
T_4 V_104 , T_4 V_106 ,
struct V_93 * V_14 )
{
if ( V_119 >= V_120 )
return - V_40 ;
if ( V_14 -> V_99 . V_121 ) {
V_101 = V_103 = V_104 = ( V_101 * 77 + V_103 * 151 + V_104 * 28 ) >> 8 ;
}
if ( V_14 -> V_113 . V_122 == V_123 ) {
T_5 V_4 ;
if ( V_119 > 16 )
return - V_40 ;
V_101 >>= ( 16 - V_14 -> V_99 . V_101 . V_105 ) ;
V_103 >>= ( 16 - V_14 -> V_99 . V_103 . V_105 ) ;
V_104 >>= ( 16 - V_14 -> V_99 . V_104 . V_105 ) ;
V_4 = ( V_101 << V_14 -> V_99 . V_101 . V_102 ) |
( V_103 << V_14 -> V_99 . V_103 . V_102 ) |
( V_104 << V_14 -> V_99 . V_104 . V_102 ) ;
V_4 &= 0xFFFFFF ;
( ( T_5 * ) ( V_14 -> V_124 ) ) [ V_119 ] = V_4 ;
}
return 0 ;
}
static T_6 F_62 ( int V_125 , void * V_126 )
{
T_7 V_127 = F_63 () ;
F_64 ( - 1 ) ;
if ( V_127 ) {
F_22 () ;
F_57 ( V_75 ) ;
F_54 ( V_75 ) ;
F_24 () ;
F_64 ( - 1 ) ;
}
return V_128 ;
}
static int T_2 F_65 ( struct V_89 * V_90 )
{
struct V_13 * V_14 ;
struct V_93 * V_129 ;
T_5 V_130 ;
int V_5 ;
V_5 = F_66 ( V_75 , V_91 L_6 ) ;
if ( V_5 < 0 ) {
F_50 ( & V_90 -> V_15 , L_7 ) ;
goto V_131;
}
V_129 = F_67 ( sizeof( * V_14 ) , & V_90 -> V_15 ) ;
if ( ! V_129 ) {
V_5 = - V_19 ;
goto V_132;
}
V_14 = V_129 -> V_95 ;
V_14 -> V_133 = V_129 ;
V_14 -> V_15 = & V_90 -> V_15 ;
V_14 -> V_21 = V_90 -> V_15 . V_134 ;
F_68 ( V_90 , V_129 ) ;
V_5 = F_16 ( V_14 ) ;
if ( V_5 < 0 ) {
F_50 ( & V_90 -> V_15 , L_8 ) ;
goto V_135;
}
strcpy ( V_129 -> V_113 . V_136 , V_91 ) ;
V_129 -> V_113 . type = V_137 ;
V_129 -> V_113 . V_138 = 0 ;
V_129 -> V_113 . V_139 = 0 ;
V_129 -> V_113 . V_140 = 0 ;
V_129 -> V_113 . V_141 = 0 ;
V_129 -> V_113 . V_142 = V_143 ;
V_129 -> V_113 . V_122 = V_123 ;
V_129 -> V_99 . V_144 = 0 ;
V_129 -> V_99 . V_145 = V_146 ;
V_129 -> V_99 . V_147 = - 1 ;
V_129 -> V_99 . V_148 = - 1 ;
V_129 -> V_99 . V_149 = 0 ;
V_129 -> V_99 . V_150 = V_151 ;
V_129 -> V_99 . V_109 = V_42 ;
V_129 -> V_99 . V_111 = V_42 ;
V_129 -> V_99 . V_110 = V_47 ;
V_129 -> V_99 . V_112 = V_47 ;
V_129 -> V_99 . V_100 = V_14 -> V_37 ;
if ( V_14 -> V_21 -> V_20 & V_152 ) {
if ( V_14 -> V_37 == 24 ) {
V_129 -> V_99 . V_101 . V_102 = 0 ;
V_129 -> V_99 . V_103 . V_102 = 8 ;
V_129 -> V_99 . V_104 . V_102 = 16 ;
} else {
V_129 -> V_99 . V_101 . V_102 = 0 ;
V_129 -> V_99 . V_103 . V_102 = 5 ;
V_129 -> V_99 . V_104 . V_102 = 11 ;
}
} else {
if ( V_14 -> V_37 == 24 ) {
V_129 -> V_99 . V_101 . V_102 = 16 ;
V_129 -> V_99 . V_103 . V_102 = 8 ;
V_129 -> V_99 . V_104 . V_102 = 0 ;
} else {
V_129 -> V_99 . V_101 . V_102 = 11 ;
V_129 -> V_99 . V_103 . V_102 = 5 ;
V_129 -> V_99 . V_104 . V_102 = 0 ;
}
}
V_129 -> V_99 . V_106 . V_102 = 0 ;
if ( V_14 -> V_37 == 24 ) {
V_129 -> V_99 . V_101 . V_105 = 8 ;
V_129 -> V_99 . V_103 . V_105 = 8 ;
V_129 -> V_99 . V_104 . V_105 = 8 ;
} else {
V_129 -> V_99 . V_101 . V_105 = 5 ;
V_129 -> V_99 . V_103 . V_105 = 6 ;
V_129 -> V_99 . V_104 . V_105 = 5 ;
}
V_129 -> V_99 . V_106 . V_105 = 0 ;
V_130 = ( ( V_48 / 2 ) * V_42 * ( V_14 -> V_37 / 8 ) ) ;
V_129 -> V_113 . V_115 = V_42 * V_47 * V_14 -> V_37 / 8
+ V_130 ;
V_129 -> V_113 . V_114 = V_129 -> V_99 . V_111 *
V_129 -> V_99 . V_100 / 8 ;
V_129 -> V_153 = & V_154 ;
V_129 -> V_155 = V_156 ;
V_14 -> V_83 =
F_69 ( NULL , V_129 -> V_113 . V_115 , & V_14 -> V_157 ,
V_18 ) ;
if ( NULL == V_14 -> V_83 ) {
F_50 ( & V_90 -> V_15 , L_9 ) ;
V_5 = - V_19 ;
goto V_135;
}
V_129 -> V_158 = ( void * ) V_14 -> V_83 + V_130 ;
V_129 -> V_113 . V_159 = ( int ) V_14 -> V_83 + V_130 ;
V_129 -> V_153 = & V_154 ;
V_129 -> V_124 = & V_14 -> V_160 ;
V_5 = F_70 ( & V_129 -> V_161 , V_120 , 0 ) ;
if ( V_5 < 0 ) {
F_50 ( & V_90 -> V_15 , L_10 ,
V_120 ) ;
goto V_162;
}
V_5 = F_46 ( V_90 ,
V_14 -> V_21 -> V_35 == V_36 ) ;
if ( V_5 ) {
F_50 ( & V_90 -> V_15 , L_11 ) ;
goto V_163;
}
V_14 -> V_125 = F_71 ( V_90 , 0 ) ;
if ( V_14 -> V_125 < 0 ) {
V_5 = - V_40 ;
goto V_164;
}
V_5 = F_72 ( V_14 -> V_125 , F_62 , 0 ,
V_91 L_12 , V_14 ) ;
if ( V_5 < 0 ) {
F_50 ( & V_90 -> V_15 , L_13 ) ;
goto V_164;
}
V_14 -> V_17 . V_16 . V_165 = V_91 L_14 ;
V_14 -> V_17 . V_166 = F_4 ;
V_14 -> V_17 . remove = F_73 ( F_9 ) ;
V_14 -> V_17 . V_167 = F_13 ;
V_14 -> V_17 . V_168 = F_10 ;
V_14 -> V_17 . V_169 = F_11 ;
V_5 = F_74 ( & V_14 -> V_17 ) ;
if ( V_5 < 0 ) {
F_50 ( & V_90 -> V_15 , L_15 ) ;
goto V_170;
}
if ( V_14 -> V_21 -> V_30 ) {
V_5 = F_47 ( V_14 -> V_21 -> V_31 , L_16 ) ;
if ( V_5 ) {
F_50 ( & V_90 -> V_15 , L_17 ,
V_14 -> V_21 -> V_31 ) ;
goto V_171;
}
F_48 ( V_14 -> V_21 -> V_31 , 0 ) ;
}
V_5 = F_75 ( V_129 ) ;
if ( V_5 < 0 ) {
F_50 ( & V_90 -> V_15 , L_18 ) ;
goto V_172;
}
F_76 ( & V_90 -> V_15 , L_19 ,
V_42 , V_47 , V_14 -> V_37 ) ;
return 0 ;
V_172:
if ( V_14 -> V_21 -> V_30 )
F_44 ( V_14 -> V_21 -> V_31 ) ;
V_171:
F_77 ( & V_14 -> V_17 ) ;
V_170:
F_78 ( V_14 -> V_125 , V_14 ) ;
V_164:
F_42 ( V_14 -> V_21 -> V_35 ==
V_36 ) ;
V_163:
F_79 ( & V_129 -> V_161 ) ;
V_162:
F_80 ( NULL , V_129 -> V_113 . V_115 , V_14 -> V_83 ,
V_14 -> V_157 ) ;
V_135:
F_81 ( V_129 ) ;
V_132:
F_82 ( V_75 ) ;
V_131:
F_68 ( V_90 , NULL ) ;
return V_5 ;
}
static int T_8 F_83 ( struct V_89 * V_90 )
{
struct V_93 * V_129 = F_84 ( V_90 ) ;
struct V_13 * V_14 = V_129 -> V_95 ;
if ( V_14 -> V_21 -> V_30 )
F_44 ( V_14 -> V_21 -> V_31 ) ;
F_77 ( & V_14 -> V_17 ) ;
F_85 ( V_129 ) ;
F_82 ( V_75 ) ;
F_78 ( V_14 -> V_125 , V_14 ) ;
if ( V_14 -> V_83 != NULL )
F_80 ( NULL , V_129 -> V_113 . V_115 , V_14 -> V_83 ,
V_14 -> V_157 ) ;
F_79 ( & V_129 -> V_161 ) ;
F_42 ( V_14 -> V_21 -> V_35 ==
V_36 ) ;
F_68 ( V_90 , NULL ) ;
F_81 ( V_129 ) ;
F_76 ( & V_90 -> V_15 , L_20 ) ;
return 0 ;
}
static int F_86 ( struct V_173 * V_15 )
{
struct V_93 * V_129 = F_87 ( V_15 ) ;
struct V_13 * V_14 = V_129 -> V_95 ;
if ( V_14 -> V_97 ) {
F_14 ( V_14 , 0 ) ;
F_22 () ;
F_53 () ;
F_57 ( V_75 ) ;
F_27 () ;
F_64 ( - 1 ) ;
}
return 0 ;
}
static int F_88 ( struct V_173 * V_15 )
{
struct V_93 * V_129 = F_87 ( V_15 ) ;
struct V_13 * V_14 = V_129 -> V_95 ;
if ( V_14 -> V_97 ) {
F_22 () ;
F_53 () ;
F_34 ( V_14 ) ;
F_17 ( V_14 ) ;
F_30 ( V_14 ) ;
F_54 ( V_75 ) ;
F_24 () ;
F_25 () ;
F_14 ( V_14 , 1 ) ;
}
return 0 ;
}
static int T_9 F_89 ( void )
{
return F_90 ( & V_174 ) ;
}
static void T_10 F_91 ( void )
{
F_92 ( & V_174 ) ;
}
