static void F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < 1000 ; V_4 ++ ) {
unsigned char V_5 = F_2 ( V_2 , V_6 ) ;
if ( V_5 & V_7 )
break;
F_3 ( 100 ) ;
}
F_4 ( V_2 ) ;
F_5 ( V_2 ) ;
F_6 ( V_2 ) ;
F_5 ( V_2 ) ;
F_4 ( V_2 ) ;
F_7 ( V_2 , V_6 ,
V_3 [ V_6 ] & ~ ( V_8 | V_9 | V_10 ) ) ;
F_7 ( V_2 , V_11 , V_3 [ V_11 ] ) ;
F_7 ( V_2 , V_12 , V_3 [ V_12 ] ) ;
F_7 ( V_2 , V_13 , V_3 [ V_13 ] & ~ V_14 ) ;
F_7 ( V_2 , V_15 , V_3 [ V_15 ] & ~ V_16 ) ;
F_7 ( V_2 , V_17 , V_3 [ V_17 ] | V_18 ) ;
F_7 ( V_2 , V_19 , V_3 [ V_20 ] ) ;
F_7 ( V_2 , V_17 , V_3 [ V_17 ] & ~ V_18 ) ;
F_7 ( V_2 , V_21 , V_3 [ V_21 ] ) ;
F_7 ( V_2 , V_19 , V_3 [ V_19 ] ) ;
F_7 ( V_2 , V_22 , V_3 [ V_22 ] & ~ V_23 ) ;
F_7 ( V_2 , V_24 , V_3 [ V_24 ] ) ;
F_7 ( V_2 , V_25 , V_3 [ V_25 ] ) ;
F_7 ( V_2 , V_26 , V_3 [ V_26 ] ) ;
F_7 ( V_2 , V_22 , V_3 [ V_22 ] ) ;
F_7 ( V_2 , V_27 , V_28 ) ;
F_7 ( V_2 , V_27 , V_28 ) ;
F_7 ( V_2 , V_13 , V_3 [ V_13 ] ) ;
F_7 ( V_2 , V_15 , V_3 [ V_15 ] ) ;
F_7 ( V_2 , V_6 , V_3 [ V_6 ] ) ;
F_7 ( V_2 , V_29 , V_3 [ V_29 ] ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
if ( ! F_9 ( V_2 ) ) {
if ( F_10 ( V_2 ) ) {
V_2 -> V_30 |= V_31 ;
} else {
F_11 ( L_1 ) ;
F_1 ( V_2 , V_2 -> V_32 ) ;
}
}
}
static void F_12 ( struct V_1 * V_2 , int V_33 )
{
if ( V_33 ) {
V_2 -> V_32 [ 1 ] |= V_34 | V_9 ;
if ( ! F_13 ( V_2 ) )
V_2 -> V_32 [ 1 ] |= V_10 ;
} else {
V_2 -> V_32 [ 1 ] &= ~ ( V_10 | V_9 | V_8 ) ;
}
F_7 ( V_2 , V_6 , V_2 -> V_32 [ 1 ] ) ;
}
static bool F_14 ( struct V_1 * V_2 )
{
struct V_35 * V_36 ;
unsigned char V_37 , V_38 , V_39 , error , V_40 ;
int V_41 = 0 ;
if ( V_2 -> V_36 . V_42 == NULL ) {
F_15 ( 1 ) ;
( void ) F_16 ( V_2 ) ;
return false ;
}
V_36 = & V_2 -> V_36 . V_42 -> V_36 ;
while ( 1 ) {
error = 0 ;
V_39 = 0 ;
V_38 = F_2 ( V_2 , V_6 ) ;
V_37 = F_16 ( V_2 ) ;
if ( V_38 & ( V_43 | V_44 | V_45 ) ) {
F_7 ( V_2 , V_27 , V_46 ) ;
F_5 ( V_2 ) ;
}
V_37 &= V_2 -> V_47 ;
if ( V_37 == 0 && V_2 -> V_30 & V_48 ) {
V_2 -> V_30 &= ~ V_48 ;
}
#if F_17 ( V_49 ) && F_17 ( V_50 )
#ifdef F_18
if ( V_37 == '\x0f' ) {
V_2 -> V_36 . V_51 = V_52 + V_53 * 5 ;
goto V_54;
}
#endif
if ( V_2 -> V_36 . V_51 ) {
int V_55 ;
F_19 ( & V_2 -> V_36 . V_56 ) ;
V_55 = F_20 ( & V_2 -> V_36 , V_37 ) ;
F_21 ( & V_2 -> V_36 . V_56 ) ;
if ( V_55 )
goto V_54;
}
#endif
if ( V_39 )
goto V_54;
V_40 = V_57 ;
V_2 -> V_36 . V_58 . V_59 ++ ;
if ( V_38 & ( V_43 | V_44 | V_45 | V_60 ) ) {
error = 1 ;
if ( V_38 & V_60 ) {
F_11 ( L_2 ) ;
V_38 &= ~ ( V_43 | V_45 ) ;
V_2 -> V_36 . V_58 . V_61 ++ ;
if ( F_22 ( & V_2 -> V_36 ) )
goto V_54;
}
else if ( V_38 & V_43 )
V_2 -> V_36 . V_58 . V_62 ++ ;
else if ( V_38 & V_45 )
V_2 -> V_36 . V_58 . V_63 ++ ;
if ( V_38 & V_44 )
V_2 -> V_36 . V_58 . V_64 ++ ;
V_38 &= V_2 -> V_36 . V_65 ;
if ( V_38 & V_60 )
V_40 = V_66 ;
else if ( V_38 & V_43 )
V_40 = V_67 ;
else if ( V_38 & V_45 )
V_40 = V_68 ;
}
if ( V_2 -> V_36 . V_69 == 0xff ||
( V_38 & V_2 -> V_36 . V_69 ) == 0 ) {
F_23 ( V_36 , V_37 , V_40 ) ;
}
if ( V_38 & V_44 )
F_23 ( V_36 , 0 , V_70 ) ;
V_54:
if ( ( ++ V_41 ) > 1000 )
goto V_71;
V_37 = F_2 ( V_2 , V_27 ) ;
if ( ! ( V_37 & V_72 ) )
break;
}
return true ;
V_71:
F_12 ( V_2 , 0 ) ;
F_24 ( L_3 ) ;
return true ;
}
static void F_25 ( struct V_1 * V_2 )
{
unsigned char V_73 ;
V_73 = F_2 ( V_2 , V_27 ) ;
F_7 ( V_2 , V_27 , V_28 ) ;
F_5 ( V_2 ) ;
if ( F_26 ( V_2 ) && F_27 ( V_2 ) ) {
if ( V_73 & V_74 )
V_2 -> V_36 . V_58 . V_75 ++ ;
if ( ( V_73 ^ V_2 -> V_76 ) & V_77 )
F_28 ( & V_2 -> V_36 ,
( V_73 & V_77 ) ) ;
if ( ( V_73 ^ V_2 -> V_76 ) & V_78 )
F_29 ( & V_2 -> V_36 ,
! ( V_73 & V_78 ) ) ;
F_30 ( & V_2 -> V_36 . V_42 -> V_36 . V_79 ) ;
}
if ( V_73 & V_60 )
V_2 -> V_30 |= V_48 ;
V_2 -> V_76 = V_73 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_80 * V_81 ;
if ( F_32 ( V_2 ) ) {
unsigned char V_73 = F_2 ( V_2 , V_27 ) ;
if ( ! ( V_73 & V_82 ) )
return;
}
V_2 -> V_30 &= ~ V_83 ;
if ( F_9 ( V_2 ) ) {
F_1 ( V_2 , V_2 -> V_32 ) ;
V_2 -> V_30 &= ~ V_31 ;
}
if ( F_33 ( V_2 ) ) {
V_2 -> V_30 &= ~ V_84 ;
goto V_85;
}
if ( ! F_26 ( V_2 ) )
goto V_85;
if ( V_2 -> V_36 . V_86 ) {
V_2 -> V_30 |= V_83 ;
F_34 ( V_2 , V_2 -> V_36 . V_86 ) ;
F_5 ( V_2 ) ;
V_2 -> V_36 . V_58 . V_87 ++ ;
V_2 -> V_36 . V_86 = 0 ;
return;
}
if ( V_2 -> V_36 . V_42 == NULL )
goto V_85;
V_81 = & V_2 -> V_36 . V_42 -> V_81 ;
if ( F_35 ( V_81 ) ) {
F_36 ( & V_2 -> V_36 ) ;
goto V_85;
}
if ( F_37 ( & V_2 -> V_36 ) )
goto V_85;
V_2 -> V_30 |= V_83 ;
F_34 ( V_2 , V_81 -> V_88 [ V_81 -> V_89 ] ) ;
F_5 ( V_2 ) ;
V_81 -> V_89 = ( V_81 -> V_89 + 1 ) & ( V_90 - 1 ) ;
V_2 -> V_36 . V_58 . V_87 ++ ;
if ( F_38 ( V_81 ) < V_91 )
F_36 ( & V_2 -> V_36 ) ;
return;
V_85:
F_7 ( V_2 , V_27 , V_92 ) ;
F_5 ( V_2 ) ;
}
static T_2 F_39 ( int V_93 , void * V_94 )
{
struct V_1 * V_2 = V_94 ;
struct V_1 * V_95 ;
struct V_1 * V_96 ;
int V_97 = V_98 ;
bool V_99 ;
T_1 V_100 ;
V_95 = F_40 ( V_2 ) ;
V_96 = V_95 -> V_101 ;
F_21 ( & V_95 -> V_36 . V_56 ) ;
V_100 = F_2 ( V_95 , V_13 ) ;
#ifdef F_41
F_11 ( L_4 , V_100 ) ;
#endif
V_99 = false ;
if ( V_100 & ( V_102 | V_103 | V_104 ) ) {
if ( ! F_26 ( V_95 ) ) {
F_11 ( L_5 ) ;
goto V_105;
}
F_7 ( V_95 , V_27 , V_106 ) ;
F_5 ( V_95 ) ;
if ( V_100 & V_102 )
F_25 ( V_95 ) ;
if ( V_100 & V_104 )
V_99 = F_14 ( V_95 ) ;
if ( V_100 & V_103 )
F_31 ( V_95 ) ;
V_97 = V_107 ;
}
V_105:
F_19 ( & V_95 -> V_36 . V_56 ) ;
if ( V_99 )
F_42 ( & V_2 -> V_36 . V_42 -> V_36 ) ;
if ( ! V_96 )
goto V_108;
F_21 ( & V_96 -> V_36 . V_56 ) ;
V_99 = false ;
if ( V_100 & ( V_109 | V_110 | V_111 ) ) {
if ( ! F_26 ( V_96 ) ) {
F_11 ( L_6 ) ;
goto V_112;
}
F_7 ( V_96 , V_27 , V_106 ) ;
F_5 ( V_96 ) ;
if ( V_100 & V_109 )
F_25 ( V_96 ) ;
if ( V_100 & V_111 )
V_99 = F_14 ( V_96 ) ;
if ( V_100 & V_110 )
F_31 ( V_96 ) ;
V_97 = V_107 ;
}
V_112:
F_19 ( & V_96 -> V_36 . V_56 ) ;
if ( V_99 )
F_42 ( & V_2 -> V_36 . V_42 -> V_36 ) ;
V_108:
return V_97 ;
}
static inline T_1 F_43 ( struct V_1 * V_2 )
{
unsigned long V_30 ;
T_1 V_73 ;
F_44 ( & V_2 -> V_36 . V_56 , V_30 ) ;
V_73 = F_2 ( V_2 , V_27 ) ;
F_45 ( & V_2 -> V_36 . V_56 , V_30 ) ;
return V_73 ;
}
static unsigned int F_46 ( struct V_113 * V_36 )
{
unsigned char V_73 ;
V_73 = F_43 ( F_47 ( V_36 ) ) ;
if ( V_73 & V_82 )
return V_114 ;
return 0 ;
}
static void F_48 ( struct V_113 * V_36 , unsigned int V_115 )
{
struct V_1 * V_2 = F_47 ( V_36 ) ;
unsigned char V_116 , V_117 ;
if ( F_49 ( V_2 ) )
return;
if ( ! ( F_26 ( V_2 ) || F_32 ( V_2 ) ) )
return;
V_116 = V_117 = 0 ;
if ( F_50 ( V_2 ) ) {
if ( V_115 & V_118 )
V_116 |= V_119 ;
else
V_117 |= V_119 ;
}
if ( V_115 & V_120 )
V_116 |= V_121 ;
else
V_117 |= V_121 ;
V_2 -> V_32 [ V_15 ] |= V_116 ;
V_2 -> V_32 [ V_15 ] &= ~ V_117 ;
F_7 ( V_2 , V_15 , V_2 -> V_32 [ V_15 ] ) ;
F_11 ( L_7 ,
V_116 , V_117 , V_2 -> V_32 [ V_15 ] ) ;
F_5 ( V_2 ) ;
}
static unsigned int F_51 ( struct V_113 * V_36 )
{
struct V_1 * V_2 = F_47 ( V_36 ) ;
unsigned char V_73 ;
unsigned int V_122 ;
V_73 = F_2 ( V_2 , V_27 ) ;
V_122 = 0 ;
if ( V_73 & V_77 )
V_122 |= V_123 ;
if ( V_73 & V_74 )
V_122 |= V_124 ;
if ( ! ( V_73 & V_78 ) )
V_122 |= V_125 ;
return V_122 ;
}
static void F_52 ( struct V_113 * V_36 )
{
F_47 ( V_36 ) -> V_30 |= V_84 ;
}
static void F_53 ( struct V_113 * V_36 )
{
struct V_1 * V_2 = F_47 ( V_36 ) ;
unsigned char V_73 ;
F_11 ( L_8 ) ;
V_2 -> V_30 |= V_83 ;
V_2 -> V_30 &= ~ V_84 ;
V_73 = F_2 ( V_2 , V_27 ) ;
if ( ! ( V_73 & V_82 ) )
return;
if ( V_36 -> V_86 ) {
F_34 ( V_2 , V_36 -> V_86 ) ;
F_5 ( V_2 ) ;
V_36 -> V_58 . V_87 ++ ;
V_36 -> V_86 = 0 ;
} else {
struct V_80 * V_81 = & V_36 -> V_42 -> V_81 ;
if ( F_35 ( V_81 ) )
goto V_108;
F_34 ( V_2 , V_81 -> V_88 [ V_81 -> V_89 ] ) ;
F_5 ( V_2 ) ;
V_81 -> V_89 = ( V_81 -> V_89 + 1 ) & ( V_90 - 1 ) ;
V_36 -> V_58 . V_87 ++ ;
if ( F_38 ( V_81 ) < V_91 )
F_36 ( & V_2 -> V_36 ) ;
}
V_108:
F_11 ( L_9 ) ;
}
static void F_54 ( struct V_113 * V_36 )
{
struct V_1 * V_2 = F_47 ( V_36 ) ;
F_11 ( L_10 ) ;
V_2 -> V_32 [ V_6 ] &= ~ V_8 ;
F_8 ( V_2 ) ;
F_11 ( L_11 ) ;
}
static void F_55 ( struct V_113 * V_36 )
{
struct V_1 * V_2 = F_47 ( V_36 ) ;
unsigned char V_126 ;
if ( F_49 ( V_2 ) )
return;
V_126 = V_2 -> V_32 [ V_17 ] | ( V_127 | V_128 | V_129 ) ;
if ( V_126 != V_2 -> V_32 [ V_17 ] ) {
V_2 -> V_32 [ V_17 ] = V_126 ;
F_7 ( V_2 , V_17 , V_2 -> V_32 [ V_17 ] ) ;
}
}
static void F_56 ( struct V_113 * V_36 , int V_130 )
{
struct V_1 * V_2 = F_47 ( V_36 ) ;
unsigned char V_116 , V_117 , V_126 ;
unsigned long V_30 ;
V_116 = V_117 = 0 ;
if ( V_130 )
V_116 |= V_131 ;
else
V_117 |= V_131 ;
F_44 ( & V_36 -> V_56 , V_30 ) ;
V_126 = ( V_2 -> V_32 [ V_15 ] | V_116 ) & ~ V_117 ;
if ( V_126 != V_2 -> V_32 [ V_15 ] ) {
V_2 -> V_32 [ V_15 ] = V_126 ;
F_7 ( V_2 , V_15 , V_2 -> V_32 [ V_15 ] ) ;
}
F_45 ( & V_36 -> V_56 , V_30 ) ;
}
static int F_57 ( struct V_1 * V_2 , int V_42 )
{
int V_132 = 0 ;
int V_97 ;
if ( V_42 ) {
V_97 = F_58 (
V_133 , V_2 -> V_134 , V_2 -> V_135 , 1 ) ;
F_11 ( L_12 , V_97 ) ;
if ( F_50 ( V_2 ) ) {
V_97 = F_58 (
V_136 , V_2 -> V_134 , 0 , 1 ) ;
V_132 = 2500 ;
F_11 ( L_13 , V_97 ) ;
}
} else {
if ( F_50 ( V_2 ) ) {
V_97 = F_58 (
V_136 , V_2 -> V_134 , 0 , 0 ) ;
F_11 ( L_14 , V_97 ) ;
}
F_58 ( V_133 , V_2 -> V_134 , V_2 -> V_135 , 0 ) ;
}
return V_132 ;
}
static int F_57 ( struct V_1 * V_2 , int V_42 )
{
return 0 ;
}
static void F_59 ( struct V_1 * V_2 )
{
F_7 ( V_2 , 9 , F_60 ( V_2 ) ? V_137 : V_138 ) ;
F_5 ( V_2 ) ;
F_3 ( 10 ) ;
F_7 ( V_2 , 9 , ( F_60 ( V_2 ) ? V_137 : V_138 ) | V_139 ) ;
F_5 ( V_2 ) ;
F_7 ( V_2 , 4 , V_140 | V_141 ) ;
F_7 ( V_2 , 3 , V_142 ) ;
F_7 ( V_2 , 5 , V_143 | V_119 ) ;
F_7 ( V_2 , 9 , V_139 ) ;
F_7 ( V_2 , 11 , V_144 | V_145 ) ;
F_7 ( V_2 , 12 , 0 ) ;
F_7 ( V_2 , 13 , 0 ) ;
F_7 ( V_2 , 14 , ( V_146 | V_147 ) ) ;
F_7 ( V_2 , 14 , ( V_146 | V_147 | V_23 ) ) ;
F_7 ( V_2 , 3 , V_142 | V_14 ) ;
F_7 ( V_2 , 0 , V_28 ) ;
F_7 ( V_2 , 0 , V_28 ) ;
F_7 ( V_2 , 0 , V_28 ) ;
F_7 ( V_2 , 9 , V_139 ) ;
F_7 ( V_2 , 4 , V_148 | V_149 ) ;
F_7 ( V_2 , 3 , V_142 ) ;
while ( F_2 ( V_2 , 0 ) & V_72 ) {
( void ) F_2 ( V_2 , 8 ) ;
F_7 ( V_2 , 0 , V_28 ) ;
F_7 ( V_2 , 0 , V_46 ) ;
}
}
static int F_61 ( struct V_1 * V_2 )
{
int V_150 = 0 ;
memset ( & V_2 -> V_32 , 0 , sizeof( V_2 -> V_32 ) ) ;
V_150 = F_57 ( V_2 , 1 ) ;
F_59 ( V_2 ) ;
V_2 -> V_32 [ V_29 ] = 0 ;
F_7 ( V_2 , 9 , F_60 ( V_2 ) ? V_137 : V_138 ) ;
F_5 ( V_2 ) ;
F_3 ( 10 ) ;
F_7 ( V_2 , 9 , 0 ) ;
F_5 ( V_2 ) ;
F_7 ( V_2 , V_6 , 0 ) ;
F_7 ( V_2 , V_27 , V_46 ) ;
F_7 ( V_2 , V_27 , V_46 ) ;
F_7 ( V_2 , V_27 , V_106 ) ;
F_7 ( V_2 , V_27 , V_106 ) ;
V_2 -> V_32 [ V_11 ] = V_148 | V_151 ;
V_2 -> V_32 [ V_13 ] = V_142 ;
V_2 -> V_32 [ V_15 ] = V_143 | V_119 ;
if ( ! F_49 ( V_2 ) )
V_2 -> V_32 [ V_15 ] |= V_121 ;
V_2 -> V_32 [ V_25 ] = 0 ;
V_2 -> V_32 [ V_26 ] = 0 ;
V_2 -> V_32 [ V_22 ] = V_23 ;
V_2 -> V_32 [ V_17 ] = V_152 ;
V_2 -> V_32 [ V_29 ] |= V_139 | V_153 ;
F_1 ( V_2 , V_2 -> V_32 ) ;
F_7 ( V_2 , V_13 , V_2 -> V_32 [ V_13 ] |= V_14 ) ;
F_7 ( V_2 , V_15 , V_2 -> V_32 [ V_15 ] |= V_16 ) ;
V_2 -> V_76 = F_2 ( V_2 , V_27 ) ;
return V_150 ;
}
static void F_62 ( struct V_1 * V_2 )
{
unsigned long V_30 ;
F_44 ( & V_2 -> V_36 . V_56 , V_30 ) ;
V_2 -> V_32 [ V_15 ] |= V_121 ;
F_7 ( V_2 , V_15 , V_2 -> V_32 [ V_15 ] ) ;
F_5 ( V_2 ) ;
F_45 ( & V_2 -> V_36 . V_56 , V_30 ) ;
F_63 ( 110 ) ;
F_44 ( & V_2 -> V_36 . V_56 , V_30 ) ;
V_2 -> V_32 [ V_15 ] &= ~ V_121 ;
F_7 ( V_2 , V_15 , V_2 -> V_32 [ V_15 ] ) ;
F_5 ( V_2 ) ;
F_45 ( & V_2 -> V_36 . V_56 , V_30 ) ;
F_63 ( 10 ) ;
}
static int F_64 ( struct V_113 * V_36 )
{
struct V_1 * V_2 = F_47 ( V_36 ) ;
unsigned long V_30 ;
int V_150 = 0 ;
F_11 ( L_15 ) ;
V_2 -> V_30 |= V_154 ;
if ( ! F_32 ( V_2 ) ) {
F_44 ( & V_36 -> V_56 , V_30 ) ;
V_150 = F_61 ( V_2 ) ;
F_45 ( & V_36 -> V_56 , V_30 ) ;
}
sprintf ( V_2 -> V_155 , V_156 L_16 , V_2 -> V_36 . line ) ;
if ( F_65 ( V_2 -> V_36 . V_93 , F_39 , V_157 ,
V_2 -> V_155 , V_2 ) ) {
F_24 ( L_17 ) ;
F_57 ( V_2 , 0 ) ;
return - V_158 ;
}
if ( V_150 != 0 ) {
F_11 ( L_18 , V_150 ) ;
F_63 ( V_150 ) ;
}
if ( F_49 ( V_2 ) )
F_62 ( V_2 ) ;
F_44 ( & V_36 -> V_56 , V_30 ) ;
F_12 ( V_2 , 1 ) ;
F_45 ( & V_36 -> V_56 , V_30 ) ;
F_11 ( L_19 ) ;
return 0 ;
}
static void F_66 ( struct V_113 * V_36 )
{
struct V_1 * V_2 = F_47 ( V_36 ) ;
unsigned long V_30 ;
F_11 ( L_20 ) ;
F_44 ( & V_36 -> V_56 , V_30 ) ;
F_12 ( V_2 , 0 ) ;
if ( ! F_32 ( V_2 ) ) {
V_2 -> V_32 [ V_13 ] &= ~ V_14 ;
V_2 -> V_32 [ V_15 ] &= ~ V_16 ;
V_2 -> V_32 [ V_15 ] &= ~ V_131 ;
F_8 ( V_2 ) ;
}
F_45 ( & V_36 -> V_56 , V_30 ) ;
F_67 ( V_2 -> V_36 . V_93 , V_2 ) ;
F_44 ( & V_36 -> V_56 , V_30 ) ;
V_2 -> V_30 &= ~ V_154 ;
if ( ! F_32 ( V_2 ) )
F_57 ( V_2 , 0 ) ;
F_45 ( & V_36 -> V_56 , V_30 ) ;
F_11 ( L_21 ) ;
}
static void F_68 ( struct V_1 * V_2 , unsigned int V_159 ,
unsigned int V_160 , unsigned long V_161 )
{
int V_162 ;
if ( V_161 >= 115200 && F_49 ( V_2 ) ) {
V_2 -> V_32 [ V_11 ] = V_140 ;
V_2 -> V_32 [ V_24 ] = V_163 | V_164 ;
V_2 -> V_32 [ V_22 ] = 0 ;
V_2 -> V_32 [ V_25 ] = 0 ;
V_2 -> V_32 [ V_26 ] = 0 ;
V_2 -> V_30 |= V_165 ;
} else {
switch ( V_161 ) {
case V_166 / 16 :
V_2 -> V_32 [ V_11 ] = V_148 ;
V_2 -> V_32 [ V_24 ] = 0 ;
V_2 -> V_32 [ V_22 ] = 0 ;
break;
case V_166 / 32 :
V_2 -> V_32 [ V_11 ] = V_167 ;
V_2 -> V_32 [ V_24 ] = 0 ;
V_2 -> V_32 [ V_22 ] = 0 ;
break;
default:
V_2 -> V_32 [ V_11 ] = V_148 ;
V_2 -> V_32 [ V_24 ] = V_145 | V_144 ;
V_162 = F_69 ( V_161 , V_166 / 16 ) ;
V_2 -> V_32 [ V_25 ] = ( V_162 & 255 ) ;
V_2 -> V_32 [ V_26 ] = ( ( V_162 >> 8 ) & 255 ) ;
V_2 -> V_32 [ V_22 ] = V_23 ;
}
V_2 -> V_30 &= ~ V_165 ;
}
V_2 -> V_32 [ 3 ] &= ~ V_168 ;
V_2 -> V_32 [ 5 ] &= ~ V_169 ;
switch ( V_159 & V_170 ) {
case V_171 :
V_2 -> V_32 [ 3 ] |= V_172 ;
V_2 -> V_32 [ 5 ] |= V_173 ;
V_2 -> V_47 = 0x1f ;
break;
case V_174 :
V_2 -> V_32 [ 3 ] |= V_175 ;
V_2 -> V_32 [ 5 ] |= V_176 ;
V_2 -> V_47 = 0x3f ;
break;
case V_177 :
V_2 -> V_32 [ 3 ] |= V_178 ;
V_2 -> V_32 [ 5 ] |= V_179 ;
V_2 -> V_47 = 0x7f ;
break;
case V_180 :
default:
V_2 -> V_32 [ 3 ] |= V_142 ;
V_2 -> V_32 [ 5 ] |= V_143 ;
V_2 -> V_47 = 0xff ;
break;
}
V_2 -> V_32 [ 4 ] &= ~ ( V_149 ) ;
if ( V_159 & V_181 )
V_2 -> V_32 [ 4 ] |= V_182 ;
else
V_2 -> V_32 [ 4 ] |= V_151 ;
if ( V_159 & V_183 )
V_2 -> V_32 [ 4 ] |= V_184 ;
else
V_2 -> V_32 [ 4 ] &= ~ V_184 ;
if ( ! ( V_159 & V_185 ) )
V_2 -> V_32 [ 4 ] |= V_186 ;
else
V_2 -> V_32 [ 4 ] &= ~ V_186 ;
V_2 -> V_36 . V_65 = V_44 ;
if ( V_160 & V_187 )
V_2 -> V_36 . V_65 |= V_45 | V_43 ;
if ( V_160 & ( V_188 | V_189 | V_190 ) )
V_2 -> V_36 . V_65 |= V_60 ;
V_2 -> V_36 . V_69 = 0 ;
if ( V_160 & V_191 )
V_2 -> V_36 . V_69 |= V_45 | V_43 ;
if ( V_160 & V_188 ) {
V_2 -> V_36 . V_69 |= V_60 ;
if ( V_160 & V_191 )
V_2 -> V_36 . V_69 |= V_44 ;
}
if ( ( V_159 & V_192 ) == 0 )
V_2 -> V_36 . V_69 = 0xff ;
}
static void F_70 ( struct V_1 * V_2 , unsigned long * V_161 )
{
T_1 V_193 ;
int V_194 , V_195 ;
switch ( * V_161 ) {
case 2400 :
V_193 = 0x53 ;
break;
case 4800 :
V_193 = 0x52 ;
break;
case 9600 :
V_193 = 0x51 ;
break;
case 19200 :
V_193 = 0x50 ;
break;
case 38400 :
V_193 = 0x4f ;
break;
case 57600 :
V_193 = 0x4e ;
break;
case 115200 :
V_193 = 0x4d ;
break;
case 1152000 :
V_193 = 0 ;
break;
case 4000000 :
V_193 = 0 ;
break;
default:
V_193 = 0x51 ;
* V_161 = 9600 ;
break;
}
V_194 = 10000 ;
while ( ( F_2 ( V_2 , V_27 ) & V_82 ) == 0
|| ( F_2 ( V_2 , V_6 ) & V_7 ) == 0 ) {
if ( -- V_194 <= 0 ) {
F_24 ( L_22 ) ;
return;
}
F_3 ( 10 ) ;
}
V_194 = 100 ;
( void ) F_16 ( V_2 ) ;
( void ) F_16 ( V_2 ) ;
( void ) F_16 ( V_2 ) ;
F_71 ( 10 ) ;
while ( F_2 ( V_2 , V_27 ) & V_72 ) {
F_16 ( V_2 ) ;
F_71 ( 10 ) ;
if ( -- V_194 <= 0 ) {
F_24 ( L_23 ) ;
return;
}
}
V_2 -> V_32 [ V_15 ] |= V_121 ;
F_7 ( V_2 , V_15 , V_2 -> V_32 [ V_15 ] ) ;
F_5 ( V_2 ) ;
F_71 ( 1 ) ;
F_68 ( V_2 , V_180 , 0 , 19200 ) ;
F_1 ( V_2 , V_2 -> V_32 ) ;
F_71 ( 1 ) ;
F_34 ( V_2 , 1 ) ;
V_194 = 5000 ;
while ( ( F_2 ( V_2 , V_27 ) & V_72 ) == 0 ) {
if ( -- V_194 <= 0 ) {
F_24 ( L_24 ) ;
goto V_108;
}
F_3 ( 10 ) ;
}
V_195 = F_16 ( V_2 ) ;
if ( V_195 < 4 ) {
F_72 ( L_25 , V_195 ) ;
goto V_108;
}
F_34 ( V_2 , V_193 ) ;
V_194 = 5000 ;
while ( ( F_2 ( V_2 , V_27 ) & V_72 ) == 0 ) {
if ( -- V_194 <= 0 ) {
F_24 ( L_26 ) ;
goto V_108;
}
F_3 ( 10 ) ;
}
V_194 = F_16 ( V_2 ) ;
if ( V_194 != V_193 )
F_24 ( L_27 , V_194 , V_193 ) ;
F_72 ( L_28 ,
* V_161 , V_195 ) ;
( void ) F_16 ( V_2 ) ;
( void ) F_16 ( V_2 ) ;
( void ) F_16 ( V_2 ) ;
V_108:
V_2 -> V_32 [ V_15 ] &= ~ V_121 ;
F_7 ( V_2 , V_15 , V_2 -> V_32 [ V_15 ] ) ;
F_5 ( V_2 ) ;
( void ) F_16 ( V_2 ) ;
( void ) F_16 ( V_2 ) ;
( void ) F_16 ( V_2 ) ;
}
static void F_73 ( struct V_113 * V_36 , struct V_196 * V_197 ,
struct V_196 * V_198 )
{
struct V_1 * V_2 = F_47 ( V_36 ) ;
unsigned long V_161 ;
F_11 ( L_29 ) ;
memcpy ( & V_2 -> V_199 , V_197 , sizeof( struct V_196 ) ) ;
if ( F_49 ( V_2 ) ) {
V_161 = F_74 ( V_36 , V_197 , V_198 , 1200 , 4000000 ) ;
F_11 ( L_30 , V_161 ) ;
F_70 ( V_2 , & V_161 ) ;
F_68 ( V_2 , V_197 -> V_200 , V_197 -> V_201 , V_161 ) ;
F_1 ( V_2 , V_2 -> V_32 ) ;
F_5 ( V_2 ) ;
} else {
V_161 = F_74 ( V_36 , V_197 , V_198 , 1200 , 230400 ) ;
F_68 ( V_2 , V_197 -> V_200 , V_197 -> V_201 , V_161 ) ;
if ( F_75 ( & V_2 -> V_36 , V_197 -> V_200 ) ) {
V_2 -> V_32 [ V_17 ] |= V_127 | V_128 | V_129 ;
V_2 -> V_30 |= V_202 ;
} else {
V_2 -> V_32 [ V_17 ] &= ~ ( V_127 | V_128 | V_129 ) ;
V_2 -> V_30 &= ~ V_202 ;
}
F_8 ( V_2 ) ;
}
F_76 ( V_36 , V_197 -> V_200 , V_161 ) ;
F_11 ( L_31 ) ;
}
static void F_77 ( struct V_113 * V_36 , struct V_196 * V_197 ,
struct V_196 * V_198 )
{
struct V_1 * V_2 = F_47 ( V_36 ) ;
unsigned long V_30 ;
F_44 ( & V_36 -> V_56 , V_30 ) ;
F_12 ( V_2 , 0 ) ;
F_73 ( V_36 , V_197 , V_198 ) ;
if ( F_26 ( V_2 ) )
F_12 ( V_2 , 1 ) ;
F_45 ( & V_36 -> V_56 , V_30 ) ;
}
static const char * F_78 ( struct V_113 * V_36 )
{
struct V_1 * V_2 = F_47 ( V_36 ) ;
if ( F_49 ( V_2 ) )
return L_32 ;
else if ( F_50 ( V_2 ) )
return L_33 ;
return L_34 ;
}
static void F_79 ( struct V_113 * V_36 )
{
}
static int F_80 ( struct V_113 * V_36 )
{
return 0 ;
}
static void F_81 ( struct V_113 * V_36 , int V_30 )
{
}
static int F_82 ( struct V_113 * V_36 , struct V_203 * V_204 )
{
return - V_205 ;
}
static int F_83 ( struct V_113 * V_36 )
{
struct V_1 * V_2 =
F_84 ( V_36 , struct V_1 , V_36 ) ;
int V_206 = 2 ;
while ( V_206 ) {
if ( ( F_2 ( V_2 , V_27 ) & V_72 ) != 0 )
return F_16 ( V_2 ) ;
if ( V_206 -- )
F_3 ( 5 ) ;
}
return V_207 ;
}
static void F_85 ( struct V_113 * V_36 , unsigned char V_208 )
{
struct V_1 * V_2 =
F_84 ( V_36 , struct V_1 , V_36 ) ;
while ( ( F_2 ( V_2 , V_27 ) & V_82 ) == 0 )
F_3 ( 5 ) ;
F_34 ( V_2 , V_208 ) ;
}
static int T_3 F_86 ( struct V_1 * V_2 )
{
struct V_209 * V_210 = V_2 -> V_134 ;
const char * V_211 ;
const struct V_212 {
int V_213 ;
char V_214 [ 1 ] ;
} * V_215 ;
int V_216 ;
struct V_217 V_218 , V_219 , V_220 ;
if ( F_87 ( V_210 , 0 , & V_218 ) )
return - V_221 ;
V_2 -> V_36 . V_222 = V_218 . V_223 ;
V_2 -> V_36 . V_224 = F_88 ( V_2 -> V_36 . V_222 , 0x1000 ) ;
V_2 -> V_225 = V_2 -> V_36 . V_224 ;
V_2 -> V_226 = V_2 -> V_225 + 0x10 ;
#ifdef F_89
if ( F_87 ( V_210 , 1 , & V_220 ) == 0 &&
F_87 ( V_210 , 2 , & V_219 ) == 0 )
V_2 -> V_30 |= V_227 ;
#else
memset ( & V_220 , 0 , sizeof( struct V_217 ) ) ;
memset ( & V_219 , 0 , sizeof( struct V_217 ) ) ;
#endif
if ( F_90 ( V_2 ) ) {
V_2 -> V_228 = F_88 ( V_220 . V_223 , 0x100 ) ;
if ( V_2 -> V_228 == NULL ) {
V_2 -> V_30 &= ~ V_227 ;
goto V_229;
}
V_2 -> V_230 = F_88 ( V_219 . V_223 , 0x100 ) ;
if ( V_2 -> V_230 == NULL ) {
F_91 ( V_2 -> V_228 ) ;
V_2 -> V_228 = NULL ;
V_2 -> V_30 &= ~ V_227 ;
goto V_229;
}
V_2 -> V_231 = F_92 ( V_210 , 1 ) ;
V_2 -> V_232 = F_92 ( V_210 , 2 ) ;
}
V_229:
if ( F_93 ( V_210 , L_35 ) )
V_2 -> V_30 |= V_233 ;
V_211 = F_94 ( V_210 , L_36 , & V_216 ) ;
if ( V_211 && ( strcmp ( V_211 , L_37 ) == 0 ) )
V_2 -> V_30 |= V_234 ;
V_2 -> V_135 = V_235 ;
V_215 = F_94 ( V_210 , L_38 , & V_216 ) ;
if ( V_215 && V_215 -> V_213 > 0 ) {
if ( strcmp ( V_215 -> V_214 , L_39 ) == 0 )
V_2 -> V_30 |= V_234 ;
else if ( strcmp ( V_215 -> V_214 , L_40 ) == 0 )
V_2 -> V_30 |= V_233 ;
}
if ( F_49 ( V_2 ) )
V_2 -> V_135 = V_236 ;
if ( F_50 ( V_2 ) ) {
struct V_209 * V_237 =
F_95 ( NULL , L_41 ) ;
if ( V_237 ) {
const char * V_238 =
F_94 ( V_237 , L_42 , NULL ) ;
if ( V_238 ) switch( * V_238 ) {
case 0x04 :
case 0x05 :
case 0x07 :
case 0x08 :
case 0x0b :
case 0x0c :
V_2 -> V_135 = V_239 ;
}
F_96 ( V_240 L_43 ,
V_238 ? ( * V_238 ) : 0 ) ;
F_97 ( V_237 ) ;
} else {
F_96 ( V_240 L_44 ) ;
}
}
V_2 -> V_36 . V_241 = V_242 ;
V_2 -> V_36 . V_93 = F_92 ( V_210 , 0 ) ;
V_2 -> V_36 . V_243 = V_166 ;
V_2 -> V_36 . V_244 = 1 ;
V_2 -> V_36 . V_245 = & V_246 ;
V_2 -> V_36 . type = V_247 ;
V_2 -> V_36 . V_30 = 0 ;
if ( V_2 -> V_36 . V_93 == 0 &&
V_210 -> V_248 && V_210 -> V_248 -> V_248 &&
F_93 ( V_210 -> V_248 -> V_248 , L_45 ) ) {
V_2 -> V_36 . V_93 = F_98 ( NULL , 64 + 15 ) ;
V_2 -> V_231 = F_98 ( NULL , 64 + 4 ) ;
V_2 -> V_232 = F_98 ( NULL , 64 + 5 ) ;
}
F_68 ( V_2 , V_180 , 0 , 9600 ) ;
return 0 ;
}
static void F_99 ( struct V_1 * V_2 )
{
struct V_209 * V_210 ;
V_210 = V_2 -> V_134 ;
F_91 ( V_2 -> V_230 ) ;
F_91 ( V_2 -> V_228 ) ;
F_91 ( V_2 -> V_225 ) ;
V_2 -> V_134 = NULL ;
F_97 ( V_210 ) ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
}
static int F_100 ( struct V_249 * V_250 , const struct V_251 * V_252 )
{
struct V_1 * V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_253 ; V_4 ++ )
if ( V_254 [ V_4 ] . V_134 == V_250 -> V_255 . V_256 . V_257 )
break;
if ( V_4 >= V_253 )
return - V_221 ;
V_2 = & V_254 [ V_4 ] ;
V_2 -> V_256 = V_250 ;
V_2 -> V_36 . V_256 = & V_250 -> V_255 . V_256 ;
F_101 ( & V_250 -> V_255 . V_256 , V_2 ) ;
if ( F_102 ( V_2 -> V_256 , L_46 ) )
F_96 ( V_258 L_47
L_48 ,
V_2 -> V_134 -> V_214 ) ;
else
V_2 -> V_30 |= V_259 ;
return F_103 ( & V_260 , & V_2 -> V_36 ) ;
}
static int F_104 ( struct V_249 * V_250 )
{
struct V_1 * V_2 = F_105 ( & V_250 -> V_255 . V_256 ) ;
if ( ! V_2 )
return - V_221 ;
F_106 ( & V_260 , & V_2 -> V_36 ) ;
if ( V_2 -> V_30 & V_259 ) {
F_107 ( V_2 -> V_256 ) ;
V_2 -> V_30 &= ~ V_259 ;
}
F_101 ( & V_250 -> V_255 . V_256 , NULL ) ;
V_2 -> V_256 = NULL ;
V_2 -> V_36 . V_256 = NULL ;
return 0 ;
}
static int F_108 ( struct V_249 * V_250 , T_4 V_261 )
{
struct V_1 * V_2 = F_105 ( & V_250 -> V_255 . V_256 ) ;
if ( V_2 == NULL ) {
F_96 ( L_49 ) ;
return 0 ;
}
F_109 ( & V_260 , & V_2 -> V_36 ) ;
return 0 ;
}
static int F_110 ( struct V_249 * V_250 )
{
struct V_1 * V_2 = F_105 ( & V_250 -> V_255 . V_256 ) ;
if ( V_2 == NULL )
return 0 ;
F_111 ( & V_260 , & V_2 -> V_36 ) ;
return 0 ;
}
static int T_3 F_112 ( void )
{
struct V_209 * V_262 , * V_263 , * V_264 , * V_210 ;
int V_213 = 0 ;
int V_97 ;
F_113 (node_p, L_50 ) {
V_263 = V_264 = NULL ;
for ( V_210 = NULL ; ( V_210 = F_114 ( V_262 , V_210 ) ) != NULL ; ) {
if ( strncmp ( V_210 -> V_214 , L_51 , 4 ) == 0 )
V_263 = F_115 ( V_210 ) ;
else if ( strncmp ( V_210 -> V_214 , L_52 , 4 ) == 0 )
V_264 = F_115 ( V_210 ) ;
}
if ( ! V_263 && ! V_264 ) {
F_97 ( V_263 ) ;
F_97 ( V_264 ) ;
F_96 ( V_265 L_53 ,
( ! V_263 ) ? 'a' : 'b' , V_262 -> V_266 ) ;
continue;
}
if ( V_264 != NULL ) {
V_254 [ V_213 ] . V_101 = & V_254 [ V_213 + 1 ] ;
V_254 [ V_213 + 1 ] . V_101 = & V_254 [ V_213 ] ;
}
V_254 [ V_213 ] . V_30 = V_267 ;
V_254 [ V_213 ] . V_134 = V_263 ;
V_254 [ V_213 + 1 ] . V_134 = V_264 ;
V_254 [ V_213 ] . V_36 . line = V_213 ;
V_254 [ V_213 + 1 ] . V_36 . line = V_213 + 1 ;
V_97 = F_86 ( & V_254 [ V_213 ] ) ;
if ( V_97 == 0 && V_264 != NULL )
V_97 = F_86 ( & V_254 [ V_213 + 1 ] ) ;
if ( V_97 != 0 ) {
F_97 ( V_263 ) ;
F_97 ( V_264 ) ;
memset ( & V_254 [ V_213 ] , 0 , sizeof( struct V_1 ) ) ;
memset ( & V_254 [ V_213 + 1 ] , 0 , sizeof( struct V_1 ) ) ;
continue;
}
V_213 += 2 ;
}
V_268 = V_213 ;
return 0 ;
}
static int T_3 F_86 ( struct V_1 * V_2 )
{
struct V_217 * V_218 ;
int V_93 ;
V_218 = F_116 ( V_2 -> V_269 , V_270 , 0 ) ;
V_93 = F_117 ( V_2 -> V_269 , 0 ) ;
if ( ! V_218 || V_93 <= 0 )
return - V_221 ;
V_2 -> V_36 . V_222 = V_218 -> V_223 ;
V_2 -> V_36 . V_224 = ( unsigned char V_271 * ) V_218 -> V_223 ;
V_2 -> V_36 . V_241 = V_242 ;
V_2 -> V_36 . V_93 = V_93 ;
V_2 -> V_36 . V_243 = V_166 ;
V_2 -> V_36 . V_244 = 1 ;
V_2 -> V_36 . V_245 = & V_246 ;
V_2 -> V_36 . type = V_247 ;
V_2 -> V_36 . V_30 = 0 ;
V_2 -> V_225 = V_2 -> V_36 . V_224 ;
V_2 -> V_226 = V_2 -> V_225 + 4 ;
V_2 -> V_135 = 0 ;
F_68 ( V_2 , V_180 , 0 , 9600 ) ;
return 0 ;
}
static int T_3 F_112 ( void )
{
int V_272 ;
V_268 = 0 ;
V_254 [ 0 ] . V_36 . line = 0 ;
V_254 [ 0 ] . V_30 = V_267 ;
V_254 [ 0 ] . V_269 = & V_273 ;
V_272 = F_86 ( & V_254 [ 0 ] ) ;
if ( V_272 )
return V_272 ;
V_268 ++ ;
V_254 [ 0 ] . V_101 = & V_254 [ 1 ] ;
V_254 [ 1 ] . V_101 = & V_254 [ 0 ] ;
V_254 [ 1 ] . V_36 . line = 1 ;
V_254 [ 1 ] . V_30 = 0 ;
V_254 [ 1 ] . V_269 = & V_274 ;
V_272 = F_86 ( & V_254 [ 1 ] ) ;
if ( V_272 )
return V_272 ;
V_268 ++ ;
return 0 ;
}
static void F_99 ( struct V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
}
static int T_3 F_100 ( struct V_275 * V_269 )
{
struct V_1 * V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_268 ; V_4 ++ )
if ( V_254 [ V_4 ] . V_269 == V_269 )
break;
if ( V_4 >= V_268 )
return - V_221 ;
V_2 = & V_254 [ V_4 ] ;
V_2 -> V_36 . V_256 = & V_269 -> V_256 ;
F_118 ( V_269 , V_2 ) ;
return F_103 ( & V_260 , & V_2 -> V_36 ) ;
}
static int T_5 F_104 ( struct V_275 * V_269 )
{
struct V_1 * V_2 = F_119 ( V_269 ) ;
if ( ! V_2 )
return - V_221 ;
F_106 ( & V_260 , & V_2 -> V_36 ) ;
V_2 -> V_36 . V_256 = NULL ;
return 0 ;
}
static int T_3 F_120 ( void )
{
V_260 . V_276 = V_268 ;
V_260 . V_277 = V_278 ;
return F_121 ( & V_260 ) ;
}
static int T_3 F_122 ( void )
{
int V_97 , V_4 ;
F_96 ( V_240 L_54 , V_195 ) ;
if ( V_268 == 0 )
F_112 () ;
if ( V_268 == 0 )
return - V_221 ;
V_97 = F_120 () ;
if ( V_97 ) {
F_96 ( V_265
L_55
L_56 ) ;
for ( V_4 = 0 ; V_4 < V_268 ; V_4 ++ )
F_99 ( & V_254 [ V_4 ] ) ;
return V_97 ;
}
#ifdef F_123
return F_124 ( & V_279 ) ;
#else
return F_125 ( & V_279 , F_100 ) ;
#endif
}
static void T_5 F_126 ( void )
{
int V_4 ;
#ifdef F_123
F_127 ( & V_279 ) ;
#else
F_128 ( & V_279 ) ;
#endif
for ( V_4 = 0 ; V_4 < V_268 ; V_4 ++ ) {
struct V_1 * V_280 = & V_254 [ V_4 ] ;
#ifdef F_123
if ( V_280 -> V_134 != NULL )
F_99 ( V_280 ) ;
#else
if ( V_280 -> V_269 != NULL )
F_99 ( V_280 ) ;
#endif
}
F_129 ( & V_260 ) ;
}
static void F_130 ( struct V_113 * V_36 , int V_37 )
{
struct V_1 * V_2 =
F_84 ( V_36 , struct V_1 , V_36 ) ;
while ( ( F_2 ( V_2 , V_27 ) & V_82 ) == 0 )
F_3 ( 5 ) ;
F_34 ( V_2 , V_37 ) ;
}
static void F_131 ( struct V_281 * V_282 , const char * V_283 , unsigned int V_213 )
{
struct V_1 * V_2 = & V_254 [ V_282 -> V_284 ] ;
unsigned long V_30 ;
F_44 ( & V_2 -> V_36 . V_56 , V_30 ) ;
F_7 ( V_2 , V_6 , V_2 -> V_32 [ 1 ] & ~ V_9 ) ;
F_7 ( V_2 , V_15 , V_2 -> V_32 [ 5 ] | V_16 | V_119 | V_121 ) ;
F_132 ( & V_2 -> V_36 , V_283 , V_213 , F_130 ) ;
F_7 ( V_2 , V_6 , V_2 -> V_32 [ 1 ] ) ;
F_45 ( & V_2 -> V_36 . V_56 , V_30 ) ;
}
static int T_3 F_133 ( struct V_281 * V_285 , char * V_286 )
{
struct V_1 * V_2 ;
struct V_113 * V_36 ;
int V_161 = 38400 ;
int V_287 = 8 ;
int V_62 = 'n' ;
int V_288 = 'n' ;
unsigned long V_150 ;
if ( F_134 ( L_57 )
|| F_134 ( L_58 )
|| F_134 ( L_59 ) )
V_161 = 57600 ;
if ( V_285 -> V_284 >= V_268 )
V_285 -> V_284 = 0 ;
V_2 = & V_254 [ V_285 -> V_284 ] ;
#ifdef F_123
if ( V_2 -> V_134 == NULL )
return - V_221 ;
#else
if ( V_2 -> V_269 == NULL )
return - V_221 ;
#endif
V_36 = & V_2 -> V_36 ;
V_2 -> V_30 |= V_289 ;
F_135 ( & V_36 -> V_56 ) ;
V_150 = F_61 ( V_2 ) ;
if ( V_150 )
F_71 ( V_150 ) ;
if ( V_286 )
F_136 ( V_286 , & V_161 , & V_62 , & V_287 , & V_288 ) ;
return F_137 ( V_36 , V_285 , V_161 , V_62 , V_287 , V_288 ) ;
}
static int T_3 F_138 ( void )
{
F_112 () ;
if ( V_268 == 0 )
return - V_221 ;
F_139 ( & V_290 ) ;
return 0 ;
}
