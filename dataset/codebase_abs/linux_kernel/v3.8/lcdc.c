static void inline F_1 ( int V_1 )
{
V_2 . V_3 |= V_1 ;
}
static void inline F_2 ( int V_1 )
{
V_2 . V_3 &= ~ V_1 ;
}
static void F_3 ( enum V_4 V_5 )
{
T_1 V_6 ;
V_6 = F_4 ( V_7 ) ;
V_6 &= ~ ( 3 << 20 ) ;
switch ( V_5 ) {
case V_8 :
V_6 |= 1 << 20 ;
break;
case V_9 :
V_6 |= 2 << 20 ;
break;
case V_10 :
break;
default:
F_5 () ;
}
F_6 ( V_6 , V_7 ) ;
}
static void F_7 ( void )
{
T_1 V_6 ;
V_6 = F_4 ( V_7 ) ;
V_6 |= V_11 ;
V_6 &= ~ V_12 ;
V_6 |= V_2 . V_3 | V_13 ;
F_6 ( V_6 , V_7 ) ;
}
static void F_8 ( void )
{
T_1 V_6 ;
T_1 V_1 ;
V_6 = F_4 ( V_7 ) ;
V_1 = V_11 | V_12 ;
V_1 &= ~ V_13 ;
V_6 &= ~ V_1 ;
F_6 ( V_6 , V_7 ) ;
}
static void F_9 ( void )
{
F_10 ( & V_2 . V_14 ) ;
F_8 () ;
if ( ! F_11 ( & V_2 . V_14 ,
F_12 ( 500 ) ) )
F_13 ( V_2 . V_15 -> V_16 , L_1 ) ;
}
static void F_14 ( T_1 V_17 )
{
static unsigned long V_18 ;
static unsigned long V_19 ;
F_8 () ;
V_18 ++ ;
if ( V_18 == 1 || F_15 ( V_20 , V_19 + V_21 ) ) {
F_13 ( V_2 . V_15 -> V_16 ,
L_2 ,
V_17 , V_18 ) ;
V_19 = V_20 ;
}
if ( V_18 < 100 ) {
F_7 () ;
} else {
V_18 = 0 ;
F_13 ( V_2 . V_15 -> V_16 ,
L_3 ) ;
}
}
static void F_16 ( void )
{
static const int V_22 [] = {
0 ,
V_23 ,
V_24 ,
0 ,
V_25 ,
} ;
struct V_26 * V_27 = V_2 . V_15 -> V_28 [ 0 ] -> V_29 ;
struct V_30 * V_31 = & V_2 . V_15 -> V_28 [ 0 ] -> V_31 ;
unsigned long V_32 ;
int V_33 , V_34 , V_35 ;
V_32 = V_2 . V_36 + V_2 . V_37 ;
switch ( V_31 -> V_38 ) {
case 0 :
if ( V_27 -> V_39 . V_40 || ( V_32 & 3 ) ||
V_2 . V_41 == V_42 ||
( V_2 . V_43 & 1 ) )
V_33 = 2 ;
else
V_33 = 4 ;
V_34 = V_2 . V_43 * V_2 . V_44 / 8 / V_33 ;
V_35 = V_2 . V_45 ;
break;
case 90 :
case 180 :
case 270 :
if ( F_17 () ) {
F_5 () ;
}
V_33 = 2 ;
V_34 = V_2 . V_45 * V_2 . V_44 / 16 ;
V_35 = V_2 . V_43 ;
break;
default:
F_5 () ;
return;
}
#ifdef F_18
F_19 ( V_2 . V_15 -> V_16 ,
L_4 ,
V_32 , V_33 , V_34 , V_35 ) ;
#endif
F_20 ( V_32 , V_34 , V_35 , V_22 [ V_33 ] ) ;
if ( ! F_17 () ) {
int V_44 = V_2 . V_44 ;
if ( V_2 . V_41 == V_42 )
V_44 = 16 ;
F_21 (
V_2 . V_46 * V_44 / 8 / V_33 ) ;
F_22 ( V_31 -> V_38 ) ;
F_23 ( V_27 -> V_39 . V_40 ) ;
}
F_24 () ;
}
static T_2 F_25 ( int V_47 , void * V_48 )
{
T_1 V_17 ;
V_17 = F_4 ( V_49 ) ;
if ( V_17 & ( V_50 | V_51 ) )
F_14 ( V_17 ) ;
else {
if ( V_17 & V_52 ) {
T_1 V_6 ;
V_6 = F_4 ( V_7 ) ;
V_6 &= ~ V_13 ;
F_6 ( V_6 , V_7 ) ;
F_26 ( & V_2 . V_14 ) ;
}
if ( V_17 & V_53 ) {
F_8 () ;
F_26 ( & V_2 . V_54 ) ;
}
}
V_17 &= ~ ( V_55 |
V_53 |
V_56 |
V_57 ) ;
F_6 ( V_17 , V_49 ) ;
return V_58 ;
}
static int F_27 ( int V_27 , int V_59 ,
unsigned long V_60 , int V_46 ,
int V_61 , int V_62 , int V_63 , int V_64 ,
int V_41 )
{
struct V_30 * V_31 = & V_2 . V_15 -> V_28 [ 0 ] -> V_31 ;
struct V_65 * V_66 = V_2 . V_15 -> V_66 ;
int V_67 , V_68 ;
if ( V_31 -> V_38 == 0 ) {
V_67 = V_66 -> V_69 ;
V_68 = V_66 -> V_70 ;
} else {
V_67 = V_66 -> V_70 ;
V_68 = V_66 -> V_69 ;
}
if ( V_27 != 0 || V_59 != 0 || V_61 != 0 || V_62 != 0 ||
V_63 > V_67 || V_64 > V_68 ) {
#ifdef F_18
F_19 ( V_2 . V_15 -> V_16 ,
L_5
L_6 , V_27 , V_61 , V_62 , V_63 , V_64 ) ;
#endif
return - V_71 ;
}
V_2 . V_37 = V_60 ;
V_2 . V_43 = V_63 ;
V_2 . V_45 = V_64 ;
V_2 . V_46 = V_46 ;
V_2 . V_41 = V_41 ;
switch ( V_41 ) {
case V_72 :
V_2 . V_44 = 8 ;
V_2 . V_73 = 0x3000 ;
V_2 . V_74 = 512 ;
break;
case V_75 :
V_2 . V_44 = 16 ;
V_2 . V_73 = 0x4000 ;
V_2 . V_74 = 32 ;
break;
case V_76 :
V_2 . V_44 = 16 ;
V_2 . V_73 = 0x4000 ;
V_2 . V_74 = 32 ;
break;
case V_42 :
if ( V_2 . V_77 ) {
V_2 . V_44 = 12 ;
break;
}
case V_78 :
if ( V_2 . V_77 ) {
V_2 . V_44 = 16 ;
break;
}
default:
F_19 ( V_2 . V_15 -> V_16 , L_7 , V_41 ) ;
F_5 () ;
return - 1 ;
}
if ( V_2 . V_77 ) {
F_16 () ;
return 0 ;
}
if ( V_2 . V_79 == V_80 ) {
F_9 () ;
F_28 () ;
F_16 () ;
F_7 () ;
}
return 0 ;
}
static int F_29 ( int V_27 , int V_81 )
{
F_19 ( V_2 . V_15 -> V_16 ,
L_8 ,
V_27 , V_81 , V_2 . V_79 , V_2 . V_77 ) ;
if ( V_27 != V_82 )
return - V_71 ;
return 0 ;
}
static void F_30 ( void )
{
T_3 * V_83 ;
V_83 = ( T_3 * ) V_2 . V_84 ;
* ( T_3 * ) V_83 &= 0x0fff ;
* ( T_3 * ) V_83 |= V_2 . V_73 ;
F_20 ( V_2 . V_85 ,
V_2 . V_74 / 4 + 1 , 1 , V_25 ) ;
F_31 ( 1 ) ;
F_24 () ;
F_10 ( & V_2 . V_54 ) ;
F_1 ( V_86 ) ;
F_3 ( V_8 ) ;
F_7 () ;
if ( ! F_11 ( & V_2 . V_54 ,
F_12 ( 500 ) ) )
F_13 ( V_2 . V_15 -> V_16 , L_1 ) ;
F_2 ( V_86 ) ;
F_28 () ;
F_31 ( V_2 . V_77 ) ;
}
static int F_32 ( T_4 V_87 , T_3 V_88 , T_3 V_89 , T_3 V_90 ,
T_3 V_91 , int V_92 )
{
T_3 * V_83 ;
if ( V_2 . V_41 != V_72 || V_87 > 255 )
return - V_71 ;
V_83 = ( T_3 * ) V_2 . V_84 ;
V_83 [ V_87 ] &= ~ 0x0fff ;
V_83 [ V_87 ] |= ( ( V_88 >> 12 ) << 8 ) | ( ( V_89 >> 12 ) << 4 ) |
( V_90 >> 12 ) ;
if ( V_92 ) {
F_9 () ;
F_28 () ;
F_30 () ;
F_16 () ;
F_3 ( V_9 ) ;
F_7 () ;
}
return 0 ;
}
static void F_33 ( int V_93 , int V_94 , int * V_95 )
{
unsigned long V_96 ;
V_94 = F_34 ( 1 , V_94 ) ;
V_96 = F_35 ( V_2 . V_97 ) ;
* V_95 = ( V_96 + V_94 - 1 ) / V_94 ;
if ( V_93 )
* V_95 = F_34 ( 2 , * V_95 ) ;
else
* V_95 = F_34 ( 3 , * V_95 ) ;
if ( * V_95 > 255 ) {
* V_95 = 255 ;
F_36 ( V_2 . V_15 -> V_16 , L_9 ,
V_94 / 1000 ) ;
}
}
static void inline F_37 ( void )
{
T_1 V_6 ;
struct V_65 * V_66 = V_2 . V_15 -> V_66 ;
int V_93 = V_66 -> V_98 & V_99 ;
unsigned long V_96 ;
int V_100 ;
V_6 = F_4 ( V_7 ) ;
V_6 &= ~ V_101 ;
V_6 |= V_93 ? V_101 : 0 ;
#ifdef F_38
V_6 |= ( V_93 && V_66 -> V_44 == 8 ) ? 0x810000 : 0 ;
#endif
F_6 ( V_6 , V_7 ) ;
V_6 = F_4 ( V_102 ) ;
V_6 &= ~ ( ( ( 1 << 6 ) - 1 ) << 20 ) ;
V_6 |= ( V_66 -> V_98 & V_103 ) << 20 ;
F_6 ( V_6 , V_102 ) ;
V_6 = V_66 -> V_69 - 1 ;
V_6 |= ( V_66 -> V_104 - 1 ) << 10 ;
V_6 |= ( V_66 -> V_105 - 1 ) << 16 ;
V_6 |= ( V_66 -> V_106 - 1 ) << 24 ;
F_6 ( V_6 , V_107 ) ;
V_6 = V_66 -> V_70 - 1 ;
V_6 |= ( V_66 -> V_108 - 1 ) << 10 ;
V_6 |= V_66 -> V_109 << 16 ;
V_6 |= V_66 -> V_110 << 24 ;
F_6 ( V_6 , V_111 ) ;
V_6 = F_4 ( V_102 ) ;
V_6 &= ~ 0xff ;
V_96 = F_35 ( V_2 . V_97 ) ;
if ( ! V_66 -> V_100 )
F_33 ( V_93 , V_66 -> V_112 * 1000 , & V_100 ) ;
else {
F_36 ( V_2 . V_15 -> V_16 ,
L_10
L_11
L_12 ,
V_96 / V_66 -> V_100 / 1000 , V_66 -> V_113 ) ;
V_100 = V_66 -> V_100 ;
}
V_6 |= V_100 & 0xff ;
V_6 |= V_66 -> V_114 << 8 ;
F_6 ( V_6 , V_102 ) ;
V_66 -> V_112 = V_96 / V_100 / 1000 ;
}
static int F_39 ( enum V_115 V_5 )
{
int V_116 = 0 ;
if ( V_5 != V_2 . V_79 ) {
switch ( V_5 ) {
case V_80 :
F_37 () ;
F_30 () ;
F_16 () ;
F_3 ( V_9 ) ;
F_1 ( V_13 ) ;
F_7 () ;
V_2 . V_79 = V_5 ;
break;
case V_117 :
F_9 () ;
F_28 () ;
V_2 . V_79 = V_5 ;
break;
default:
V_116 = - V_71 ;
}
}
return V_116 ;
}
static enum V_115 F_40 ( void )
{
return V_2 . V_79 ;
}
static void F_41 ( void )
{
F_39 ( V_117 ) ;
}
static void F_42 ( void )
{
F_39 ( V_80 ) ;
}
static void F_43 ( int V_27 , struct V_118 * V_119 )
{
return;
}
int F_44 ( void (* F_45)( void * V_120 ) , void * V_120 )
{
F_46 ( F_45 == NULL ) ;
if ( V_2 . V_121 )
return - V_122 ;
else {
V_2 . V_121 = F_45 ;
V_2 . V_123 = V_120 ;
}
return 0 ;
}
void F_47 ( void )
{
V_2 . V_121 = NULL ;
}
static void F_48 ( T_3 V_17 , void * V_120 )
{
if ( V_2 . V_121 )
V_2 . V_121 ( V_2 . V_123 ) ;
}
static int F_49 ( void )
{
struct V_124 * V_125 ;
struct V_126 V_127 ;
T_5 V_128 ;
unsigned long V_129 ;
V_125 = F_50 ( V_2 . V_130 , V_131 ) ;
if ( V_125 == NULL ) {
F_13 ( V_2 . V_15 -> V_16 , L_13 ) ;
return - V_132 ;
}
V_127 . V_133 = & V_134 ;
V_129 = ( unsigned long ) V_125 -> V_135 ;
V_127 . V_136 = V_129 ;
V_127 . V_137 = V_129 + V_2 . V_130 ;
V_128 = F_51 ( V_138 ) ;
if ( F_52 ( & V_127 , V_129 ,
V_2 . V_36 >> V_139 ,
V_2 . V_130 , V_128 ) < 0 ) {
F_13 ( V_2 . V_15 -> V_16 , L_14 ) ;
return - V_140 ;
}
V_2 . V_141 = ( void * ) V_129 ;
return 0 ;
}
static void F_53 ( void )
{
F_54 ( V_2 . V_141 ) ;
}
static int F_55 ( void )
{
V_2 . V_84 = F_56 ( V_2 . V_15 -> V_16 ,
V_142 , & V_2 . V_85 , V_143 ) ;
if ( V_2 . V_84 == NULL ) {
F_13 ( V_2 . V_15 -> V_16 , L_15 ) ;
return - V_132 ;
}
memset ( V_2 . V_84 , 0 , V_142 ) ;
return 0 ;
}
static void F_57 ( void )
{
F_58 ( V_2 . V_15 -> V_16 , V_142 ,
V_2 . V_84 , V_2 . V_85 ) ;
}
static int F_59 ( struct V_144 * V_145 )
{
int V_44 ;
int V_146 ;
struct V_65 * V_66 = V_2 . V_15 -> V_66 ;
V_44 = V_66 -> V_44 ;
if ( V_44 == 12 )
V_44 = 16 ;
V_146 = F_60 ( V_66 -> V_69 * V_44 / 8 * V_66 -> V_70 ) ;
if ( V_145 -> V_147 > V_146 )
V_146 = V_145 -> V_147 ;
V_2 . V_130 = V_146 ;
V_2 . V_141 = F_56 ( V_2 . V_15 -> V_16 ,
V_2 . V_130 , & V_2 . V_36 , V_143 ) ;
if ( V_2 . V_141 == NULL ) {
F_13 ( V_2 . V_15 -> V_16 , L_16 ) ;
return - V_132 ;
}
V_145 -> V_147 = V_146 ;
V_145 -> V_148 = V_2 . V_36 ;
V_145 -> V_129 = V_2 . V_141 ;
V_145 -> V_149 = 1 ;
memset ( V_2 . V_141 , 0 , V_2 . V_130 ) ;
return 0 ;
}
static void F_61 ( void )
{
F_58 ( V_2 . V_15 -> V_16 , V_2 . V_130 ,
V_2 . V_141 , V_2 . V_36 ) ;
}
static int F_62 ( struct V_150 * V_151 )
{
int V_116 ;
if ( ! V_151 -> V_152 ) {
F_13 ( V_2 . V_15 -> V_16 , L_17 ) ;
return - V_71 ;
}
if ( V_151 -> V_152 > 1 ) {
F_13 ( V_2 . V_15 -> V_16 , L_18 ) ;
V_151 -> V_152 = 1 ;
}
if ( V_151 -> V_145 [ 0 ] . V_148 == 0 ) {
V_2 . V_153 = 1 ;
if ( ( V_116 = F_59 ( & V_151 -> V_145 [ 0 ] ) ) < 0 )
return V_116 ;
return 0 ;
}
V_2 . V_36 = V_151 -> V_145 [ 0 ] . V_148 ;
V_2 . V_130 = V_151 -> V_145 [ 0 ] . V_147 ;
if ( ( V_116 = F_49 () ) < 0 )
return V_116 ;
F_19 ( V_2 . V_15 -> V_16 , L_19 ,
V_2 . V_36 , V_2 . V_130 , V_2 . V_141 ) ;
return 0 ;
}
static void F_63 ( void )
{
if ( V_2 . V_153 )
F_61 () ;
else
F_53 () ;
}
static int F_64 ( struct V_154 * V_15 , int V_77 ,
struct V_150 * V_155 )
{
int V_116 ;
T_1 V_6 ;
int V_156 ;
struct V_157 * V_158 ;
V_2 . V_3 = 0 ;
V_2 . V_15 = V_15 ;
V_2 . V_77 = V_77 ;
V_6 = 0 ;
F_6 ( V_6 , V_7 ) ;
V_2 . V_97 = F_65 ( V_15 -> V_16 , L_20 ) ;
if ( F_66 ( V_2 . V_97 ) ) {
F_13 ( V_15 -> V_16 , L_21 ) ;
V_116 = F_67 ( V_2 . V_97 ) ;
goto V_159;
}
V_158 = F_65 ( V_15 -> V_16 , L_22 ) ;
if ( F_66 ( V_158 ) ) {
F_13 ( V_15 -> V_16 , L_23 ) ;
V_116 = F_67 ( V_158 ) ;
goto V_160;
}
V_156 = F_35 ( V_158 ) ;
F_68 ( V_158 ) ;
if ( F_69 () )
V_156 /= 4 ;
if ( F_70 () )
V_156 /= 3 ;
V_116 = F_71 ( V_2 . V_97 , V_156 ) ;
if ( V_116 ) {
F_13 ( V_15 -> V_16 , L_24 ) ;
goto V_160;
}
F_72 ( V_2 . V_97 ) ;
V_116 = F_73 ( V_161 , F_25 , 0 , V_162 , V_15 ) ;
if ( V_116 ) {
F_13 ( V_15 -> V_16 , L_25 ) ;
goto V_163;
}
V_116 = F_74 ( F_48 , NULL ) ;
if ( V_116 ) {
F_13 ( V_15 -> V_16 , L_26 ) ;
goto V_164;
}
F_31 ( V_77 ) ;
F_75 ( V_77 ) ;
if ( ! V_77 )
if ( ( V_116 = F_55 () ) < 0 )
goto V_165;
if ( ( V_116 = F_62 ( V_155 ) ) < 0 )
goto V_166;
F_76 ( L_27 ) ;
return 0 ;
V_166:
if ( ! V_77 )
F_57 () ;
V_165:
F_77 () ;
V_164:
F_78 ( V_161 , V_2 . V_15 ) ;
V_163:
F_79 ( V_2 . V_97 ) ;
V_160:
F_68 ( V_2 . V_97 ) ;
V_159:
return V_116 ;
}
static void F_80 ( void )
{
if ( ! V_2 . V_77 )
F_57 () ;
F_63 () ;
F_77 () ;
F_78 ( V_161 , V_2 . V_15 ) ;
F_79 ( V_2 . V_97 ) ;
F_68 ( V_2 . V_97 ) ;
}
