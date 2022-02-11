static inline void F_1 ( int V_1 )
{
V_2 . V_3 |= V_1 ;
}
static inline void F_2 ( int V_1 )
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
static inline void F_37 ( void )
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
V_2 . V_84 = F_50 ( V_2 . V_15 -> V_16 , V_124 ,
& V_2 . V_85 , V_125 ) ;
if ( V_2 . V_84 == NULL ) {
F_13 ( V_2 . V_15 -> V_16 , L_13 ) ;
return - V_126 ;
}
memset ( V_2 . V_84 , 0 , V_124 ) ;
return 0 ;
}
static void F_51 ( void )
{
F_52 ( V_2 . V_15 -> V_16 , V_124 , V_2 . V_84 ,
V_2 . V_85 ) ;
}
static int F_53 ( struct V_127 * V_128 )
{
int V_44 ;
int V_129 ;
struct V_65 * V_66 = V_2 . V_15 -> V_66 ;
V_44 = V_66 -> V_44 ;
if ( V_44 == 12 )
V_44 = 16 ;
V_129 = F_54 ( V_66 -> V_69 * V_44 / 8 * V_66 -> V_70 ) ;
if ( V_128 -> V_130 > V_129 )
V_129 = V_128 -> V_130 ;
V_2 . V_131 = V_129 ;
V_2 . V_132 = F_50 ( V_2 . V_15 -> V_16 , V_2 . V_131 ,
& V_2 . V_36 , V_125 ) ;
if ( V_2 . V_132 == NULL ) {
F_13 ( V_2 . V_15 -> V_16 , L_14 ) ;
return - V_126 ;
}
V_128 -> V_130 = V_129 ;
V_128 -> V_133 = V_2 . V_36 ;
V_128 -> V_134 = V_2 . V_132 ;
V_128 -> V_135 = 1 ;
memset ( V_2 . V_132 , 0 , V_2 . V_131 ) ;
return 0 ;
}
static void F_55 ( void )
{
F_52 ( V_2 . V_15 -> V_16 , V_2 . V_131 , V_2 . V_132 ,
V_2 . V_36 ) ;
}
static int F_56 ( struct V_136 * V_137 )
{
if ( ! V_137 -> V_138 ) {
F_13 ( V_2 . V_15 -> V_16 , L_15 ) ;
return - V_71 ;
}
if ( V_137 -> V_138 > 1 ) {
F_13 ( V_2 . V_15 -> V_16 , L_16 ) ;
V_137 -> V_138 = 1 ;
}
return F_53 ( & V_137 -> V_128 [ 0 ] ) ;
}
static int F_57 ( struct V_139 * V_15 , int V_77 ,
struct V_136 * V_140 )
{
int V_116 ;
T_1 V_6 ;
int V_141 ;
struct V_142 * V_143 ;
V_2 . V_3 = 0 ;
V_2 . V_15 = V_15 ;
V_2 . V_77 = V_77 ;
V_6 = 0 ;
F_6 ( V_6 , V_7 ) ;
V_2 . V_97 = F_58 ( V_15 -> V_16 , L_17 ) ;
if ( F_59 ( V_2 . V_97 ) ) {
F_13 ( V_15 -> V_16 , L_18 ) ;
V_116 = F_60 ( V_2 . V_97 ) ;
goto V_144;
}
V_143 = F_58 ( V_15 -> V_16 , L_19 ) ;
if ( F_59 ( V_143 ) ) {
F_13 ( V_15 -> V_16 , L_20 ) ;
V_116 = F_60 ( V_143 ) ;
goto V_145;
}
V_141 = F_35 ( V_143 ) ;
F_61 ( V_143 ) ;
if ( F_62 () )
V_141 /= 4 ;
if ( F_63 () )
V_141 /= 3 ;
V_116 = F_64 ( V_2 . V_97 , V_141 ) ;
if ( V_116 ) {
F_13 ( V_15 -> V_16 , L_21 ) ;
goto V_145;
}
F_65 ( V_2 . V_97 ) ;
V_116 = F_66 ( V_146 , F_25 , 0 , V_147 , V_15 ) ;
if ( V_116 ) {
F_13 ( V_15 -> V_16 , L_22 ) ;
goto V_148;
}
V_116 = F_67 ( F_48 , NULL ) ;
if ( V_116 ) {
F_13 ( V_15 -> V_16 , L_23 ) ;
goto V_149;
}
F_31 ( V_77 ) ;
F_68 ( V_77 ) ;
if ( ! V_77 )
if ( ( V_116 = F_49 () ) < 0 )
goto V_150;
if ( ( V_116 = F_56 ( V_140 ) ) < 0 )
goto V_151;
F_69 ( L_24 ) ;
return 0 ;
V_151:
if ( ! V_77 )
F_51 () ;
V_150:
F_70 () ;
V_149:
F_71 ( V_146 , V_2 . V_15 ) ;
V_148:
F_72 ( V_2 . V_97 ) ;
V_145:
F_61 ( V_2 . V_97 ) ;
V_144:
return V_116 ;
}
static void F_73 ( void )
{
if ( ! V_2 . V_77 )
F_51 () ;
F_55 () ;
F_70 () ;
F_71 ( V_146 , V_2 . V_15 ) ;
F_72 ( V_2 . V_97 ) ;
F_61 ( V_2 . V_97 ) ;
}
