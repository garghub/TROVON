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
static struct V_35 * F_14 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = NULL ;
unsigned char V_37 , V_38 , V_39 , error , V_40 ;
int V_41 = 0 ;
if ( V_2 -> V_42 . V_43 == NULL || V_2 -> V_42 . V_43 -> V_42 . V_36 == NULL ) {
F_15 ( 1 ) ;
( void ) F_16 ( V_2 ) ;
return NULL ;
}
V_36 = V_2 -> V_42 . V_43 -> V_42 . V_36 ;
while ( 1 ) {
error = 0 ;
V_39 = 0 ;
V_38 = F_2 ( V_2 , V_6 ) ;
V_37 = F_16 ( V_2 ) ;
if ( V_38 & ( V_44 | V_45 | V_46 ) ) {
F_7 ( V_2 , V_27 , V_47 ) ;
F_5 ( V_2 ) ;
}
V_37 &= V_2 -> V_48 ;
if ( V_37 == 0 && V_2 -> V_30 & V_49 ) {
V_2 -> V_30 &= ~ V_49 ;
}
#if F_17 ( V_50 ) && F_17 ( V_51 )
#ifdef F_18
if ( V_37 == '\x0f' ) {
V_2 -> V_42 . V_52 = V_53 + V_54 * 5 ;
goto V_55;
}
#endif
if ( V_2 -> V_42 . V_52 ) {
int V_56 ;
F_19 ( & V_2 -> V_42 . V_57 ) ;
V_56 = F_20 ( & V_2 -> V_42 , V_37 ) ;
F_21 ( & V_2 -> V_42 . V_57 ) ;
if ( V_56 )
goto V_55;
}
#endif
if ( V_39 )
goto V_55;
V_40 = V_58 ;
V_2 -> V_42 . V_59 . V_60 ++ ;
if ( V_38 & ( V_44 | V_45 | V_46 | V_61 ) ) {
error = 1 ;
if ( V_38 & V_61 ) {
F_11 ( L_2 ) ;
V_38 &= ~ ( V_44 | V_46 ) ;
V_2 -> V_42 . V_59 . V_62 ++ ;
if ( F_22 ( & V_2 -> V_42 ) )
goto V_55;
}
else if ( V_38 & V_44 )
V_2 -> V_42 . V_59 . V_63 ++ ;
else if ( V_38 & V_46 )
V_2 -> V_42 . V_59 . V_64 ++ ;
if ( V_38 & V_45 )
V_2 -> V_42 . V_59 . V_65 ++ ;
V_38 &= V_2 -> V_42 . V_66 ;
if ( V_38 & V_61 )
V_40 = V_67 ;
else if ( V_38 & V_44 )
V_40 = V_68 ;
else if ( V_38 & V_46 )
V_40 = V_69 ;
}
if ( V_2 -> V_42 . V_70 == 0xff ||
( V_38 & V_2 -> V_42 . V_70 ) == 0 ) {
F_23 ( V_36 , V_37 , V_40 ) ;
}
if ( V_38 & V_45 )
F_23 ( V_36 , 0 , V_71 ) ;
V_55:
if ( ( ++ V_41 ) > 1000 )
goto V_72;
V_37 = F_2 ( V_2 , V_27 ) ;
if ( ! ( V_37 & V_73 ) )
break;
}
return V_36 ;
V_72:
F_12 ( V_2 , 0 ) ;
F_24 ( L_3 ) ;
return V_36 ;
}
static void F_25 ( struct V_1 * V_2 )
{
unsigned char V_74 ;
V_74 = F_2 ( V_2 , V_27 ) ;
F_7 ( V_2 , V_27 , V_28 ) ;
F_5 ( V_2 ) ;
if ( F_26 ( V_2 ) && F_27 ( V_2 ) ) {
if ( V_74 & V_75 )
V_2 -> V_42 . V_59 . V_76 ++ ;
if ( ( V_74 ^ V_2 -> V_77 ) & V_78 )
F_28 ( & V_2 -> V_42 ,
( V_74 & V_78 ) ) ;
if ( ( V_74 ^ V_2 -> V_77 ) & V_79 )
F_29 ( & V_2 -> V_42 ,
! ( V_74 & V_79 ) ) ;
F_30 ( & V_2 -> V_42 . V_43 -> V_42 . V_80 ) ;
}
if ( V_74 & V_61 )
V_2 -> V_30 |= V_49 ;
V_2 -> V_77 = V_74 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_81 * V_82 ;
if ( F_32 ( V_2 ) ) {
unsigned char V_74 = F_2 ( V_2 , V_27 ) ;
if ( ! ( V_74 & V_83 ) )
return;
}
V_2 -> V_30 &= ~ V_84 ;
if ( F_9 ( V_2 ) ) {
F_1 ( V_2 , V_2 -> V_32 ) ;
V_2 -> V_30 &= ~ V_31 ;
}
if ( F_33 ( V_2 ) ) {
V_2 -> V_30 &= ~ V_85 ;
goto V_86;
}
if ( ! F_26 ( V_2 ) )
goto V_86;
if ( V_2 -> V_42 . V_87 ) {
V_2 -> V_30 |= V_84 ;
F_34 ( V_2 , V_2 -> V_42 . V_87 ) ;
F_5 ( V_2 ) ;
V_2 -> V_42 . V_59 . V_88 ++ ;
V_2 -> V_42 . V_87 = 0 ;
return;
}
if ( V_2 -> V_42 . V_43 == NULL )
goto V_86;
V_82 = & V_2 -> V_42 . V_43 -> V_82 ;
if ( F_35 ( V_82 ) ) {
F_36 ( & V_2 -> V_42 ) ;
goto V_86;
}
if ( F_37 ( & V_2 -> V_42 ) )
goto V_86;
V_2 -> V_30 |= V_84 ;
F_34 ( V_2 , V_82 -> V_89 [ V_82 -> V_90 ] ) ;
F_5 ( V_2 ) ;
V_82 -> V_90 = ( V_82 -> V_90 + 1 ) & ( V_91 - 1 ) ;
V_2 -> V_42 . V_59 . V_88 ++ ;
if ( F_38 ( V_82 ) < V_92 )
F_36 ( & V_2 -> V_42 ) ;
return;
V_86:
F_7 ( V_2 , V_27 , V_93 ) ;
F_5 ( V_2 ) ;
}
static T_2 F_39 ( int V_94 , void * V_95 )
{
struct V_1 * V_2 = V_95 ;
struct V_1 * V_96 ;
struct V_1 * V_97 ;
int V_98 = V_99 ;
struct V_35 * V_36 ;
T_1 V_100 ;
V_96 = F_40 ( V_2 ) ;
V_97 = V_96 -> V_101 ;
F_21 ( & V_96 -> V_42 . V_57 ) ;
V_100 = F_2 ( V_96 , V_13 ) ;
#ifdef F_41
F_11 ( L_4 , V_100 ) ;
#endif
V_36 = NULL ;
if ( V_100 & ( V_102 | V_103 | V_104 ) ) {
if ( ! F_26 ( V_96 ) ) {
F_11 ( L_5 ) ;
goto V_105;
}
F_7 ( V_96 , V_27 , V_106 ) ;
F_5 ( V_96 ) ;
if ( V_100 & V_102 )
F_25 ( V_96 ) ;
if ( V_100 & V_104 )
V_36 = F_14 ( V_96 ) ;
if ( V_100 & V_103 )
F_31 ( V_96 ) ;
V_98 = V_107 ;
}
V_105:
F_19 ( & V_96 -> V_42 . V_57 ) ;
if ( V_36 != NULL )
F_42 ( V_36 ) ;
if ( ! V_97 )
goto V_108;
F_21 ( & V_97 -> V_42 . V_57 ) ;
V_36 = NULL ;
if ( V_100 & ( V_109 | V_110 | V_111 ) ) {
if ( ! F_26 ( V_97 ) ) {
F_11 ( L_6 ) ;
goto V_112;
}
F_7 ( V_97 , V_27 , V_106 ) ;
F_5 ( V_97 ) ;
if ( V_100 & V_109 )
F_25 ( V_97 ) ;
if ( V_100 & V_111 )
V_36 = F_14 ( V_97 ) ;
if ( V_100 & V_110 )
F_31 ( V_97 ) ;
V_98 = V_107 ;
}
V_112:
F_19 ( & V_97 -> V_42 . V_57 ) ;
if ( V_36 != NULL )
F_42 ( V_36 ) ;
V_108:
return V_98 ;
}
static inline T_1 F_43 ( struct V_1 * V_2 )
{
unsigned long V_30 ;
T_1 V_74 ;
F_44 ( & V_2 -> V_42 . V_57 , V_30 ) ;
V_74 = F_2 ( V_2 , V_27 ) ;
F_45 ( & V_2 -> V_42 . V_57 , V_30 ) ;
return V_74 ;
}
static unsigned int F_46 ( struct V_113 * V_42 )
{
unsigned char V_74 ;
V_74 = F_43 ( F_47 ( V_42 ) ) ;
if ( V_74 & V_83 )
return V_114 ;
return 0 ;
}
static void F_48 ( struct V_113 * V_42 , unsigned int V_115 )
{
struct V_1 * V_2 = F_47 ( V_42 ) ;
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
static unsigned int F_51 ( struct V_113 * V_42 )
{
struct V_1 * V_2 = F_47 ( V_42 ) ;
unsigned char V_74 ;
unsigned int V_122 ;
V_74 = F_2 ( V_2 , V_27 ) ;
V_122 = 0 ;
if ( V_74 & V_78 )
V_122 |= V_123 ;
if ( V_74 & V_75 )
V_122 |= V_124 ;
if ( ! ( V_74 & V_79 ) )
V_122 |= V_125 ;
return V_122 ;
}
static void F_52 ( struct V_113 * V_42 )
{
F_47 ( V_42 ) -> V_30 |= V_85 ;
}
static void F_53 ( struct V_113 * V_42 )
{
struct V_1 * V_2 = F_47 ( V_42 ) ;
unsigned char V_74 ;
F_11 ( L_8 ) ;
V_2 -> V_30 |= V_84 ;
V_2 -> V_30 &= ~ V_85 ;
V_74 = F_2 ( V_2 , V_27 ) ;
if ( ! ( V_74 & V_83 ) )
return;
if ( V_42 -> V_87 ) {
F_34 ( V_2 , V_42 -> V_87 ) ;
F_5 ( V_2 ) ;
V_42 -> V_59 . V_88 ++ ;
V_42 -> V_87 = 0 ;
} else {
struct V_81 * V_82 = & V_42 -> V_43 -> V_82 ;
F_34 ( V_2 , V_82 -> V_89 [ V_82 -> V_90 ] ) ;
F_5 ( V_2 ) ;
V_82 -> V_90 = ( V_82 -> V_90 + 1 ) & ( V_91 - 1 ) ;
V_42 -> V_59 . V_88 ++ ;
if ( F_38 ( V_82 ) < V_92 )
F_36 ( & V_2 -> V_42 ) ;
}
F_11 ( L_9 ) ;
}
static void F_54 ( struct V_113 * V_42 )
{
struct V_1 * V_2 = F_47 ( V_42 ) ;
F_11 ( L_10 ) ;
V_2 -> V_32 [ V_6 ] &= ~ V_8 ;
F_8 ( V_2 ) ;
F_11 ( L_11 ) ;
}
static void F_55 ( struct V_113 * V_42 )
{
struct V_1 * V_2 = F_47 ( V_42 ) ;
unsigned char V_126 ;
if ( F_49 ( V_2 ) )
return;
V_126 = V_2 -> V_32 [ V_17 ] | ( V_127 | V_128 | V_129 ) ;
if ( V_126 != V_2 -> V_32 [ V_17 ] ) {
V_2 -> V_32 [ V_17 ] = V_126 ;
F_7 ( V_2 , V_17 , V_2 -> V_32 [ V_17 ] ) ;
}
}
static void F_56 ( struct V_113 * V_42 , int V_130 )
{
struct V_1 * V_2 = F_47 ( V_42 ) ;
unsigned char V_116 , V_117 , V_126 ;
unsigned long V_30 ;
V_116 = V_117 = 0 ;
if ( V_130 )
V_116 |= V_131 ;
else
V_117 |= V_131 ;
F_44 ( & V_42 -> V_57 , V_30 ) ;
V_126 = ( V_2 -> V_32 [ V_15 ] | V_116 ) & ~ V_117 ;
if ( V_126 != V_2 -> V_32 [ V_15 ] ) {
V_2 -> V_32 [ V_15 ] = V_126 ;
F_7 ( V_2 , V_15 , V_2 -> V_32 [ V_15 ] ) ;
}
F_45 ( & V_42 -> V_57 , V_30 ) ;
}
static int F_57 ( struct V_1 * V_2 , int V_43 )
{
int V_132 = 0 ;
int V_98 ;
if ( V_43 ) {
V_98 = F_58 (
V_133 , V_2 -> V_134 , V_2 -> V_135 , 1 ) ;
F_11 ( L_12 , V_98 ) ;
if ( F_50 ( V_2 ) ) {
V_98 = F_58 (
V_136 , V_2 -> V_134 , 0 , 1 ) ;
V_132 = 2500 ;
F_11 ( L_13 , V_98 ) ;
}
} else {
if ( F_50 ( V_2 ) ) {
V_98 = F_58 (
V_136 , V_2 -> V_134 , 0 , 0 ) ;
F_11 ( L_14 , V_98 ) ;
}
F_58 ( V_133 , V_2 -> V_134 , V_2 -> V_135 , 0 ) ;
}
return V_132 ;
}
static int F_57 ( struct V_1 * V_2 , int V_43 )
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
while ( F_2 ( V_2 , 0 ) & V_73 ) {
( void ) F_2 ( V_2 , 8 ) ;
F_7 ( V_2 , 0 , V_28 ) ;
F_7 ( V_2 , 0 , V_47 ) ;
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
F_7 ( V_2 , V_27 , V_47 ) ;
F_7 ( V_2 , V_27 , V_47 ) ;
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
V_2 -> V_77 = F_2 ( V_2 , V_27 ) ;
return V_150 ;
}
static void F_62 ( struct V_1 * V_2 )
{
unsigned long V_30 ;
F_44 ( & V_2 -> V_42 . V_57 , V_30 ) ;
V_2 -> V_32 [ V_15 ] |= V_121 ;
F_7 ( V_2 , V_15 , V_2 -> V_32 [ V_15 ] ) ;
F_5 ( V_2 ) ;
F_45 ( & V_2 -> V_42 . V_57 , V_30 ) ;
F_63 ( 110 ) ;
F_44 ( & V_2 -> V_42 . V_57 , V_30 ) ;
V_2 -> V_32 [ V_15 ] &= ~ V_121 ;
F_7 ( V_2 , V_15 , V_2 -> V_32 [ V_15 ] ) ;
F_5 ( V_2 ) ;
F_45 ( & V_2 -> V_42 . V_57 , V_30 ) ;
F_63 ( 10 ) ;
}
static int F_64 ( struct V_113 * V_42 )
{
struct V_1 * V_2 = F_47 ( V_42 ) ;
unsigned long V_30 ;
int V_150 = 0 ;
F_11 ( L_15 ) ;
V_2 -> V_30 |= V_154 ;
if ( ! F_32 ( V_2 ) ) {
F_44 ( & V_42 -> V_57 , V_30 ) ;
V_150 = F_61 ( V_2 ) ;
F_45 ( & V_42 -> V_57 , V_30 ) ;
}
sprintf ( V_2 -> V_155 , V_156 L_16 , V_2 -> V_42 . line ) ;
if ( F_65 ( V_2 -> V_42 . V_94 , F_39 , V_157 ,
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
F_44 ( & V_42 -> V_57 , V_30 ) ;
F_12 ( V_2 , 1 ) ;
F_45 ( & V_42 -> V_57 , V_30 ) ;
F_11 ( L_19 ) ;
return 0 ;
}
static void F_66 ( struct V_113 * V_42 )
{
struct V_1 * V_2 = F_47 ( V_42 ) ;
unsigned long V_30 ;
F_11 ( L_20 ) ;
F_44 ( & V_42 -> V_57 , V_30 ) ;
F_12 ( V_2 , 0 ) ;
if ( ! F_32 ( V_2 ) ) {
V_2 -> V_32 [ V_13 ] &= ~ V_14 ;
V_2 -> V_32 [ V_15 ] &= ~ V_16 ;
V_2 -> V_32 [ V_15 ] &= ~ V_131 ;
F_8 ( V_2 ) ;
}
F_45 ( & V_42 -> V_57 , V_30 ) ;
F_67 ( V_2 -> V_42 . V_94 , V_2 ) ;
F_44 ( & V_42 -> V_57 , V_30 ) ;
V_2 -> V_30 &= ~ V_154 ;
if ( ! F_32 ( V_2 ) )
F_57 ( V_2 , 0 ) ;
F_45 ( & V_42 -> V_57 , V_30 ) ;
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
V_2 -> V_48 = 0x1f ;
break;
case V_174 :
V_2 -> V_32 [ 3 ] |= V_175 ;
V_2 -> V_32 [ 5 ] |= V_176 ;
V_2 -> V_48 = 0x3f ;
break;
case V_177 :
V_2 -> V_32 [ 3 ] |= V_178 ;
V_2 -> V_32 [ 5 ] |= V_179 ;
V_2 -> V_48 = 0x7f ;
break;
case V_180 :
default:
V_2 -> V_32 [ 3 ] |= V_142 ;
V_2 -> V_32 [ 5 ] |= V_143 ;
V_2 -> V_48 = 0xff ;
break;
} ;
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
V_2 -> V_42 . V_66 = V_45 ;
if ( V_160 & V_187 )
V_2 -> V_42 . V_66 |= V_46 | V_44 ;
if ( V_160 & ( V_188 | V_189 ) )
V_2 -> V_42 . V_66 |= V_61 ;
V_2 -> V_42 . V_70 = 0 ;
if ( V_160 & V_190 )
V_2 -> V_42 . V_70 |= V_46 | V_44 ;
if ( V_160 & V_191 ) {
V_2 -> V_42 . V_70 |= V_61 ;
if ( V_160 & V_190 )
V_2 -> V_42 . V_70 |= V_45 ;
}
if ( ( V_159 & V_192 ) == 0 )
V_2 -> V_42 . V_70 = 0xff ;
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
while ( ( F_2 ( V_2 , V_27 ) & V_83 ) == 0
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
while ( F_2 ( V_2 , V_27 ) & V_73 ) {
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
while ( ( F_2 ( V_2 , V_27 ) & V_73 ) == 0 ) {
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
while ( ( F_2 ( V_2 , V_27 ) & V_73 ) == 0 ) {
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
static void F_73 ( struct V_113 * V_42 , struct V_196 * V_197 ,
struct V_196 * V_198 )
{
struct V_1 * V_2 = F_47 ( V_42 ) ;
unsigned long V_161 ;
F_11 ( L_29 ) ;
memcpy ( & V_2 -> V_199 , V_197 , sizeof( struct V_196 ) ) ;
if ( F_49 ( V_2 ) ) {
V_161 = F_74 ( V_42 , V_197 , V_198 , 1200 , 4000000 ) ;
F_11 ( L_30 , V_161 ) ;
F_70 ( V_2 , & V_161 ) ;
F_68 ( V_2 , V_197 -> V_200 , V_197 -> V_201 , V_161 ) ;
F_1 ( V_2 , V_2 -> V_32 ) ;
F_5 ( V_2 ) ;
} else {
V_161 = F_74 ( V_42 , V_197 , V_198 , 1200 , 230400 ) ;
F_68 ( V_2 , V_197 -> V_200 , V_197 -> V_201 , V_161 ) ;
if ( F_75 ( & V_2 -> V_42 , V_197 -> V_200 ) ) {
V_2 -> V_32 [ V_17 ] |= V_127 | V_128 | V_129 ;
V_2 -> V_30 |= V_202 ;
} else {
V_2 -> V_32 [ V_17 ] &= ~ ( V_127 | V_128 | V_129 ) ;
V_2 -> V_30 &= ~ V_202 ;
}
F_8 ( V_2 ) ;
}
F_76 ( V_42 , V_197 -> V_200 , V_161 ) ;
F_11 ( L_31 ) ;
}
static void F_77 ( struct V_113 * V_42 , struct V_196 * V_197 ,
struct V_196 * V_198 )
{
struct V_1 * V_2 = F_47 ( V_42 ) ;
unsigned long V_30 ;
F_44 ( & V_42 -> V_57 , V_30 ) ;
F_12 ( V_2 , 0 ) ;
F_73 ( V_42 , V_197 , V_198 ) ;
if ( F_26 ( V_2 ) )
F_12 ( V_2 , 1 ) ;
F_45 ( & V_42 -> V_57 , V_30 ) ;
}
static const char * F_78 ( struct V_113 * V_42 )
{
struct V_1 * V_2 = F_47 ( V_42 ) ;
if ( F_49 ( V_2 ) )
return L_32 ;
else if ( F_50 ( V_2 ) )
return L_33 ;
return L_34 ;
}
static void F_79 ( struct V_113 * V_42 )
{
}
static int F_80 ( struct V_113 * V_42 )
{
return 0 ;
}
static void F_81 ( struct V_113 * V_42 , int V_30 )
{
}
static int F_82 ( struct V_113 * V_42 , struct V_203 * V_204 )
{
return - V_205 ;
}
static int F_83 ( struct V_113 * V_42 )
{
struct V_1 * V_2 = (struct V_1 * ) V_42 ;
while ( ( F_2 ( V_2 , V_27 ) & V_73 ) == 0 )
F_3 ( 5 ) ;
return F_16 ( V_2 ) ;
}
static void F_84 ( struct V_113 * V_42 , unsigned char V_206 )
{
struct V_1 * V_2 = (struct V_1 * ) V_42 ;
while ( ( F_2 ( V_2 , V_27 ) & V_83 ) == 0 )
F_3 ( 5 ) ;
F_34 ( V_2 , V_206 ) ;
}
static int T_3 F_85 ( struct V_1 * V_2 )
{
struct V_207 * V_208 = V_2 -> V_134 ;
const char * V_209 ;
const struct V_210 {
int V_211 ;
char V_212 [ 1 ] ;
} * V_213 ;
int V_214 ;
struct V_215 V_216 , V_217 , V_218 ;
if ( F_86 ( V_208 , 0 , & V_216 ) )
return - V_219 ;
V_2 -> V_42 . V_220 = V_216 . V_221 ;
V_2 -> V_42 . V_222 = F_87 ( V_2 -> V_42 . V_220 , 0x1000 ) ;
V_2 -> V_223 = V_2 -> V_42 . V_222 ;
V_2 -> V_224 = V_2 -> V_223 + 0x10 ;
#ifdef F_88
if ( F_86 ( V_208 , 1 , & V_218 ) == 0 &&
F_86 ( V_208 , 2 , & V_217 ) == 0 )
V_2 -> V_30 |= V_225 ;
#else
memset ( & V_218 , 0 , sizeof( struct V_215 ) ) ;
memset ( & V_217 , 0 , sizeof( struct V_215 ) ) ;
#endif
if ( F_89 ( V_2 ) ) {
V_2 -> V_226 = F_87 ( V_218 . V_221 , 0x100 ) ;
if ( V_2 -> V_226 == NULL ) {
V_2 -> V_30 &= ~ V_225 ;
goto V_227;
}
V_2 -> V_228 = F_87 ( V_217 . V_221 , 0x100 ) ;
if ( V_2 -> V_228 == NULL ) {
F_90 ( V_2 -> V_226 ) ;
V_2 -> V_226 = NULL ;
V_2 -> V_30 &= ~ V_225 ;
goto V_227;
}
V_2 -> V_229 = F_91 ( V_208 , 1 ) ;
V_2 -> V_230 = F_91 ( V_208 , 2 ) ;
}
V_227:
if ( F_92 ( V_208 , L_35 ) )
V_2 -> V_30 |= V_231 ;
V_209 = F_93 ( V_208 , L_36 , & V_214 ) ;
if ( V_209 && ( strcmp ( V_209 , L_37 ) == 0 ) )
V_2 -> V_30 |= V_232 ;
V_2 -> V_135 = V_233 ;
V_213 = F_93 ( V_208 , L_38 , & V_214 ) ;
if ( V_213 && V_213 -> V_211 > 0 ) {
if ( strcmp ( V_213 -> V_212 , L_39 ) == 0 )
V_2 -> V_30 |= V_232 ;
else if ( strcmp ( V_213 -> V_212 , L_40 ) == 0 )
V_2 -> V_30 |= V_231 ;
}
if ( F_49 ( V_2 ) )
V_2 -> V_135 = V_234 ;
if ( F_50 ( V_2 ) ) {
struct V_207 * V_235 =
F_94 ( NULL , L_41 ) ;
if ( V_235 ) {
const char * V_236 =
F_93 ( V_235 , L_42 , NULL ) ;
if ( V_236 ) switch( * V_236 ) {
case 0x04 :
case 0x05 :
case 0x07 :
case 0x08 :
case 0x0b :
case 0x0c :
V_2 -> V_135 = V_237 ;
}
F_95 ( V_238 L_43 ,
V_236 ? ( * V_236 ) : 0 ) ;
F_96 ( V_235 ) ;
} else {
F_95 ( V_238 L_44 ) ;
}
}
V_2 -> V_42 . V_239 = V_240 ;
V_2 -> V_42 . V_94 = F_91 ( V_208 , 0 ) ;
V_2 -> V_42 . V_241 = V_166 ;
V_2 -> V_42 . V_242 = 1 ;
V_2 -> V_42 . V_243 = & V_244 ;
V_2 -> V_42 . type = V_245 ;
V_2 -> V_42 . V_30 = 0 ;
if ( V_2 -> V_42 . V_94 == 0 &&
V_208 -> V_246 && V_208 -> V_246 -> V_246 &&
F_92 ( V_208 -> V_246 -> V_246 , L_45 ) ) {
V_2 -> V_42 . V_94 = F_97 ( NULL , 64 + 15 ) ;
V_2 -> V_229 = F_97 ( NULL , 64 + 4 ) ;
V_2 -> V_230 = F_97 ( NULL , 64 + 5 ) ;
}
F_68 ( V_2 , V_180 , 0 , 9600 ) ;
return 0 ;
}
static void F_98 ( struct V_1 * V_2 )
{
struct V_207 * V_208 ;
V_208 = V_2 -> V_134 ;
F_90 ( V_2 -> V_228 ) ;
F_90 ( V_2 -> V_226 ) ;
F_90 ( V_2 -> V_223 ) ;
V_2 -> V_134 = NULL ;
F_96 ( V_208 ) ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
}
static int F_99 ( struct V_247 * V_248 , const struct V_249 * V_250 )
{
struct V_1 * V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_251 ; V_4 ++ )
if ( V_252 [ V_4 ] . V_134 == V_248 -> V_253 . V_254 . V_255 )
break;
if ( V_4 >= V_251 )
return - V_219 ;
V_2 = & V_252 [ V_4 ] ;
V_2 -> V_254 = V_248 ;
V_2 -> V_42 . V_254 = & V_248 -> V_253 . V_254 ;
F_100 ( & V_248 -> V_253 . V_254 , V_2 ) ;
if ( F_101 ( V_2 -> V_254 , L_46 ) )
F_95 ( V_256 L_47
L_48 ,
V_2 -> V_134 -> V_212 ) ;
else
V_2 -> V_30 |= V_257 ;
return F_102 ( & V_258 , & V_2 -> V_42 ) ;
}
static int F_103 ( struct V_247 * V_248 )
{
struct V_1 * V_2 = F_104 ( & V_248 -> V_253 . V_254 ) ;
if ( ! V_2 )
return - V_219 ;
F_105 ( & V_258 , & V_2 -> V_42 ) ;
if ( V_2 -> V_30 & V_257 ) {
F_106 ( V_2 -> V_254 ) ;
V_2 -> V_30 &= ~ V_257 ;
}
F_100 ( & V_248 -> V_253 . V_254 , NULL ) ;
V_2 -> V_254 = NULL ;
V_2 -> V_42 . V_254 = NULL ;
return 0 ;
}
static int F_107 ( struct V_247 * V_248 , T_4 V_259 )
{
struct V_1 * V_2 = F_104 ( & V_248 -> V_253 . V_254 ) ;
if ( V_2 == NULL ) {
F_95 ( L_49 ) ;
return 0 ;
}
F_108 ( & V_258 , & V_2 -> V_42 ) ;
return 0 ;
}
static int F_109 ( struct V_247 * V_248 )
{
struct V_1 * V_2 = F_104 ( & V_248 -> V_253 . V_254 ) ;
if ( V_2 == NULL )
return 0 ;
F_110 ( & V_258 , & V_2 -> V_42 ) ;
return 0 ;
}
static int T_3 F_111 ( void )
{
struct V_207 * V_260 , * V_261 , * V_262 , * V_208 ;
int V_211 = 0 ;
int V_98 ;
V_260 = F_94 ( NULL , L_50 ) ;
while ( V_260 ) {
V_261 = V_262 = NULL ;
for ( V_208 = NULL ; ( V_208 = F_112 ( V_260 , V_208 ) ) != NULL ; ) {
if ( strncmp ( V_208 -> V_212 , L_51 , 4 ) == 0 )
V_261 = F_113 ( V_208 ) ;
else if ( strncmp ( V_208 -> V_212 , L_52 , 4 ) == 0 )
V_262 = F_113 ( V_208 ) ;
}
if ( ! V_261 && ! V_262 ) {
F_96 ( V_261 ) ;
F_96 ( V_262 ) ;
F_95 ( V_263 L_53 ,
( ! V_261 ) ? 'a' : 'b' , V_260 -> V_264 ) ;
goto V_265;
}
if ( V_262 != NULL ) {
V_252 [ V_211 ] . V_101 = & V_252 [ V_211 + 1 ] ;
V_252 [ V_211 + 1 ] . V_101 = & V_252 [ V_211 ] ;
}
V_252 [ V_211 ] . V_30 = V_266 ;
V_252 [ V_211 ] . V_134 = V_261 ;
V_252 [ V_211 + 1 ] . V_134 = V_262 ;
V_252 [ V_211 ] . V_42 . line = V_211 ;
V_252 [ V_211 + 1 ] . V_42 . line = V_211 + 1 ;
V_98 = F_85 ( & V_252 [ V_211 ] ) ;
if ( V_98 == 0 && V_262 != NULL )
V_98 = F_85 ( & V_252 [ V_211 + 1 ] ) ;
if ( V_98 != 0 ) {
F_96 ( V_261 ) ;
F_96 ( V_262 ) ;
memset ( & V_252 [ V_211 ] , 0 , sizeof( struct V_1 ) ) ;
memset ( & V_252 [ V_211 + 1 ] , 0 , sizeof( struct V_1 ) ) ;
goto V_265;
}
V_211 += 2 ;
V_265:
V_260 = F_94 ( V_260 , L_50 ) ;
}
V_267 = V_211 ;
return 0 ;
}
static int T_3 F_85 ( struct V_1 * V_2 )
{
struct V_215 * V_216 ;
int V_94 ;
V_216 = F_114 ( V_2 -> V_268 , V_269 , 0 ) ;
V_94 = F_115 ( V_2 -> V_268 , 0 ) ;
if ( ! V_216 || ! V_94 )
return - V_219 ;
V_2 -> V_42 . V_220 = V_216 -> V_221 ;
V_2 -> V_42 . V_222 = ( unsigned char V_270 * ) V_216 -> V_221 ;
V_2 -> V_42 . V_239 = V_240 ;
V_2 -> V_42 . V_94 = V_94 ;
V_2 -> V_42 . V_241 = V_166 ;
V_2 -> V_42 . V_242 = 1 ;
V_2 -> V_42 . V_243 = & V_244 ;
V_2 -> V_42 . type = V_245 ;
V_2 -> V_42 . V_30 = 0 ;
V_2 -> V_223 = V_2 -> V_42 . V_222 ;
V_2 -> V_224 = V_2 -> V_223 + 4 ;
V_2 -> V_135 = 0 ;
F_68 ( V_2 , V_180 , 0 , 9600 ) ;
return 0 ;
}
static int T_3 F_111 ( void )
{
int V_271 ;
V_267 = 0 ;
V_252 [ 0 ] . V_42 . line = 0 ;
V_252 [ 0 ] . V_30 = V_266 ;
V_252 [ 0 ] . V_268 = & V_272 ;
V_271 = F_85 ( & V_252 [ 0 ] ) ;
if ( V_271 )
return V_271 ;
V_267 ++ ;
V_252 [ 0 ] . V_101 = & V_252 [ 1 ] ;
V_252 [ 1 ] . V_101 = & V_252 [ 0 ] ;
V_252 [ 1 ] . V_42 . line = 1 ;
V_252 [ 1 ] . V_30 = 0 ;
V_252 [ 1 ] . V_268 = & V_273 ;
V_271 = F_85 ( & V_252 [ 1 ] ) ;
if ( V_271 )
return V_271 ;
V_267 ++ ;
return 0 ;
}
static void F_98 ( struct V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
}
static int T_3 F_99 ( struct V_274 * V_268 )
{
struct V_1 * V_2 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_267 ; V_4 ++ )
if ( V_252 [ V_4 ] . V_268 == V_268 )
break;
if ( V_4 >= V_267 )
return - V_219 ;
V_2 = & V_252 [ V_4 ] ;
V_2 -> V_42 . V_254 = & V_268 -> V_254 ;
F_116 ( V_268 , V_2 ) ;
return F_102 ( & V_258 , & V_2 -> V_42 ) ;
}
static int T_5 F_103 ( struct V_274 * V_268 )
{
struct V_1 * V_2 = F_117 ( V_268 ) ;
if ( ! V_2 )
return - V_219 ;
F_105 ( & V_258 , & V_2 -> V_42 ) ;
F_116 ( V_268 , NULL ) ;
V_2 -> V_42 . V_254 = NULL ;
return 0 ;
}
static int T_3 F_118 ( void )
{
V_258 . V_275 = V_267 ;
V_258 . V_276 = V_277 ;
return F_119 ( & V_258 ) ;
}
static int T_3 F_120 ( void )
{
int V_98 , V_4 ;
F_95 ( V_238 L_54 , V_195 ) ;
if ( V_267 == 0 )
F_111 () ;
if ( V_267 == 0 )
return - V_219 ;
V_98 = F_118 () ;
if ( V_98 ) {
F_95 ( V_263
L_55
L_56 ) ;
for ( V_4 = 0 ; V_4 < V_267 ; V_4 ++ )
F_98 ( & V_252 [ V_4 ] ) ;
return V_98 ;
}
#ifdef F_121
return F_122 ( & V_278 ) ;
#else
return F_123 ( & V_278 , F_99 ) ;
#endif
}
static void T_5 F_124 ( void )
{
int V_4 ;
#ifdef F_121
F_125 ( & V_278 ) ;
#else
F_126 ( & V_278 ) ;
#endif
for ( V_4 = 0 ; V_4 < V_267 ; V_4 ++ ) {
struct V_1 * V_279 = & V_252 [ V_4 ] ;
#ifdef F_121
if ( V_279 -> V_134 != NULL )
F_98 ( V_279 ) ;
#else
if ( V_279 -> V_268 != NULL )
F_98 ( V_279 ) ;
#endif
}
F_127 ( & V_258 ) ;
}
static void F_128 ( struct V_113 * V_42 , int V_37 )
{
struct V_1 * V_2 = (struct V_1 * ) V_42 ;
while ( ( F_2 ( V_2 , V_27 ) & V_83 ) == 0 )
F_3 ( 5 ) ;
F_34 ( V_2 , V_37 ) ;
}
static void F_129 ( struct V_280 * V_281 , const char * V_282 , unsigned int V_211 )
{
struct V_1 * V_2 = & V_252 [ V_281 -> V_283 ] ;
unsigned long V_30 ;
F_44 ( & V_2 -> V_42 . V_57 , V_30 ) ;
F_7 ( V_2 , V_6 , V_2 -> V_32 [ 1 ] & ~ V_9 ) ;
F_7 ( V_2 , V_15 , V_2 -> V_32 [ 5 ] | V_16 | V_119 | V_121 ) ;
F_130 ( & V_2 -> V_42 , V_282 , V_211 , F_128 ) ;
F_7 ( V_2 , V_6 , V_2 -> V_32 [ 1 ] ) ;
F_45 ( & V_2 -> V_42 . V_57 , V_30 ) ;
}
static int T_3 F_131 ( struct V_280 * V_284 , char * V_285 )
{
struct V_1 * V_2 ;
struct V_113 * V_42 ;
int V_161 = 38400 ;
int V_286 = 8 ;
int V_63 = 'n' ;
int V_287 = 'n' ;
unsigned long V_150 ;
if ( F_132 ( L_57 )
|| F_132 ( L_58 )
|| F_132 ( L_59 ) )
V_161 = 57600 ;
if ( V_284 -> V_283 >= V_267 )
V_284 -> V_283 = 0 ;
V_2 = & V_252 [ V_284 -> V_283 ] ;
#ifdef F_121
if ( V_2 -> V_134 == NULL )
return - V_219 ;
#else
if ( V_2 -> V_268 == NULL )
return - V_219 ;
#endif
V_42 = & V_2 -> V_42 ;
V_2 -> V_30 |= V_288 ;
F_133 ( & V_42 -> V_57 ) ;
V_150 = F_61 ( V_2 ) ;
if ( V_150 )
F_71 ( V_150 ) ;
if ( V_285 )
F_134 ( V_285 , & V_161 , & V_63 , & V_286 , & V_287 ) ;
return F_135 ( V_42 , V_284 , V_161 , V_63 , V_286 , V_287 ) ;
}
static int T_3 F_136 ( void )
{
F_111 () ;
F_137 ( & V_289 ) ;
return 0 ;
}
