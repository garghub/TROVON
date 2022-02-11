static void F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
int V_4 ;
if ( F_2 ( V_2 ) )
return;
for ( V_4 = 0 ; V_4 < 1000 ; V_4 ++ ) {
unsigned char V_5 = F_3 ( V_2 , V_6 ) ;
if ( V_5 & V_7 )
break;
F_4 ( 100 ) ;
}
F_5 ( V_2 ) ;
F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
F_6 ( V_2 ) ;
F_5 ( V_2 ) ;
F_8 ( V_2 , V_6 ,
V_3 [ V_6 ] & ~ ( V_8 | V_9 | V_10 ) ) ;
F_8 ( V_2 , V_11 , V_3 [ V_11 ] ) ;
F_8 ( V_2 , V_12 , V_3 [ V_12 ] ) ;
F_8 ( V_2 , V_13 , V_3 [ V_13 ] & ~ V_14 ) ;
F_8 ( V_2 , V_15 , V_3 [ V_15 ] & ~ V_16 ) ;
F_8 ( V_2 , V_17 , V_3 [ V_17 ] | V_18 ) ;
F_8 ( V_2 , V_19 , V_3 [ V_20 ] ) ;
F_8 ( V_2 , V_17 , V_3 [ V_17 ] & ~ V_18 ) ;
F_8 ( V_2 , V_21 , V_3 [ V_21 ] ) ;
F_8 ( V_2 , V_19 , V_3 [ V_19 ] ) ;
F_8 ( V_2 , V_22 , V_3 [ V_22 ] & ~ V_23 ) ;
F_8 ( V_2 , V_24 , V_3 [ V_24 ] ) ;
F_8 ( V_2 , V_25 , V_3 [ V_25 ] ) ;
F_8 ( V_2 , V_26 , V_3 [ V_26 ] ) ;
F_8 ( V_2 , V_22 , V_3 [ V_22 ] ) ;
F_8 ( V_2 , V_27 , V_28 ) ;
F_8 ( V_2 , V_27 , V_28 ) ;
F_8 ( V_2 , V_13 , V_3 [ V_13 ] ) ;
F_8 ( V_2 , V_15 , V_3 [ V_15 ] ) ;
F_8 ( V_2 , V_6 , V_3 [ V_6 ] ) ;
F_8 ( V_2 , V_29 , V_3 [ V_29 ] ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
if ( ! F_10 ( V_2 ) ) {
if ( F_11 ( V_2 ) ) {
V_2 -> V_30 |= V_31 ;
} else {
F_12 ( L_1 ) ;
F_1 ( V_2 , V_2 -> V_32 ) ;
}
}
}
static struct V_33 * F_13 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = NULL ;
unsigned char V_35 , V_36 , V_37 , error , V_38 ;
int V_39 = 0 ;
if ( ! F_14 ( V_2 ) ) {
F_12 ( L_2 ) ;
for (; ; ) {
if ( ( ++ V_39 ) > 1000 )
goto V_40;
( void ) F_3 ( V_2 , V_6 ) ;
F_8 ( V_2 , V_27 , V_41 ) ;
( void ) F_15 ( V_2 ) ;
V_35 = F_3 ( V_2 , V_27 ) ;
if ( ! ( V_35 & V_42 ) )
break;
}
return NULL ;
}
if ( V_2 -> V_43 . V_44 == NULL || V_2 -> V_43 . V_44 -> V_43 . V_34 == NULL ) {
F_16 ( 1 ) ;
( void ) F_15 ( V_2 ) ;
return NULL ;
}
V_34 = V_2 -> V_43 . V_44 -> V_43 . V_34 ;
while ( 1 ) {
error = 0 ;
V_37 = 0 ;
V_36 = F_3 ( V_2 , V_6 ) ;
V_35 = F_15 ( V_2 ) ;
if ( V_36 & ( V_45 | V_46 | V_47 ) ) {
F_8 ( V_2 , V_27 , V_41 ) ;
F_6 ( V_2 ) ;
}
V_35 &= V_2 -> V_48 ;
if ( V_35 == 0 && V_2 -> V_30 & V_49 ) {
V_2 -> V_30 &= ~ V_49 ;
}
#if F_17 ( V_50 ) && F_17 ( V_51 )
#ifdef F_18
if ( V_35 == '\x0f' ) {
V_2 -> V_43 . V_52 = V_53 + V_54 * 5 ;
goto V_55;
}
#endif
if ( V_2 -> V_43 . V_52 ) {
int V_56 ;
F_19 ( & V_2 -> V_43 . V_57 ) ;
V_56 = F_20 ( & V_2 -> V_43 , V_35 ) ;
F_21 ( & V_2 -> V_43 . V_57 ) ;
if ( V_56 )
goto V_55;
}
#endif
if ( V_37 )
goto V_55;
V_38 = V_58 ;
V_2 -> V_43 . V_59 . V_60 ++ ;
if ( V_36 & ( V_45 | V_46 | V_47 | V_61 ) ) {
error = 1 ;
if ( V_36 & V_61 ) {
F_12 ( L_3 ) ;
V_36 &= ~ ( V_45 | V_47 ) ;
V_2 -> V_43 . V_59 . V_62 ++ ;
if ( F_22 ( & V_2 -> V_43 ) )
goto V_55;
}
else if ( V_36 & V_45 )
V_2 -> V_43 . V_59 . V_63 ++ ;
else if ( V_36 & V_47 )
V_2 -> V_43 . V_59 . V_64 ++ ;
if ( V_36 & V_46 )
V_2 -> V_43 . V_59 . V_65 ++ ;
V_36 &= V_2 -> V_43 . V_66 ;
if ( V_36 & V_61 )
V_38 = V_67 ;
else if ( V_36 & V_45 )
V_38 = V_68 ;
else if ( V_36 & V_47 )
V_38 = V_69 ;
}
if ( V_2 -> V_43 . V_70 == 0xff ||
( V_36 & V_2 -> V_43 . V_70 ) == 0 ) {
F_23 ( V_34 , V_35 , V_38 ) ;
}
if ( V_36 & V_46 )
F_23 ( V_34 , 0 , V_71 ) ;
V_55:
if ( ( ++ V_39 ) > 1000 )
goto V_40;
V_35 = F_3 ( V_2 , V_27 ) ;
if ( ! ( V_35 & V_42 ) )
break;
}
return V_34 ;
V_40:
V_2 -> V_32 [ V_6 ] &= ~ ( V_10 | V_9 | V_8 ) ;
F_8 ( V_2 , V_6 , V_2 -> V_32 [ V_6 ] ) ;
F_6 ( V_2 ) ;
F_24 ( L_4 ) ;
return V_34 ;
}
static void F_25 ( struct V_1 * V_2 )
{
unsigned char V_72 ;
V_72 = F_3 ( V_2 , V_27 ) ;
F_8 ( V_2 , V_27 , V_28 ) ;
F_6 ( V_2 ) ;
if ( F_14 ( V_2 ) && F_26 ( V_2 ) ) {
if ( V_72 & V_73 )
V_2 -> V_43 . V_59 . V_74 ++ ;
if ( ( V_72 ^ V_2 -> V_75 ) & V_76 )
F_27 ( & V_2 -> V_43 ,
( V_72 & V_76 ) ) ;
if ( ( V_72 ^ V_2 -> V_75 ) & V_77 )
F_28 ( & V_2 -> V_43 ,
! ( V_72 & V_77 ) ) ;
F_29 ( & V_2 -> V_43 . V_44 -> V_43 . V_78 ) ;
}
if ( V_72 & V_61 )
V_2 -> V_30 |= V_49 ;
V_2 -> V_75 = V_72 ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_79 * V_80 ;
if ( F_2 ( V_2 ) )
return;
if ( F_31 ( V_2 ) ) {
unsigned char V_72 = F_3 ( V_2 , V_27 ) ;
if ( ! ( V_72 & V_81 ) )
return;
}
V_2 -> V_30 &= ~ V_82 ;
if ( F_10 ( V_2 ) ) {
F_1 ( V_2 , V_2 -> V_32 ) ;
V_2 -> V_30 &= ~ V_31 ;
}
if ( F_32 ( V_2 ) ) {
V_2 -> V_30 &= ~ V_83 ;
goto V_84;
}
if ( ! F_14 ( V_2 ) )
goto V_84;
if ( V_2 -> V_43 . V_85 ) {
V_2 -> V_30 |= V_82 ;
F_33 ( V_2 , V_2 -> V_43 . V_85 ) ;
F_6 ( V_2 ) ;
V_2 -> V_43 . V_59 . V_86 ++ ;
V_2 -> V_43 . V_85 = 0 ;
return;
}
if ( V_2 -> V_43 . V_44 == NULL )
goto V_84;
V_80 = & V_2 -> V_43 . V_44 -> V_80 ;
if ( F_34 ( V_80 ) ) {
F_35 ( & V_2 -> V_43 ) ;
goto V_84;
}
if ( F_36 ( & V_2 -> V_43 ) )
goto V_84;
V_2 -> V_30 |= V_82 ;
F_33 ( V_2 , V_80 -> V_87 [ V_80 -> V_88 ] ) ;
F_6 ( V_2 ) ;
V_80 -> V_88 = ( V_80 -> V_88 + 1 ) & ( V_89 - 1 ) ;
V_2 -> V_43 . V_59 . V_86 ++ ;
if ( F_37 ( V_80 ) < V_90 )
F_35 ( & V_2 -> V_43 ) ;
return;
V_84:
F_8 ( V_2 , V_27 , V_91 ) ;
F_6 ( V_2 ) ;
}
static T_2 F_38 ( int V_92 , void * V_93 )
{
struct V_1 * V_2 = V_93 ;
struct V_1 * V_94 ;
struct V_1 * V_95 ;
int V_96 = V_97 ;
struct V_33 * V_34 ;
T_1 V_98 ;
V_94 = F_39 ( V_2 ) ;
V_95 = V_94 -> V_99 ;
F_21 ( & V_94 -> V_43 . V_57 ) ;
V_98 = F_3 ( V_94 , V_13 ) ;
#ifdef F_40
F_12 ( L_5 , V_98 ) ;
#endif
V_34 = NULL ;
if ( V_98 & ( V_100 | V_101 | V_102 ) ) {
F_8 ( V_94 , V_27 , V_103 ) ;
F_6 ( V_94 ) ;
if ( V_98 & V_100 )
F_25 ( V_94 ) ;
if ( V_98 & V_102 )
V_34 = F_13 ( V_94 ) ;
if ( V_98 & V_101 )
F_30 ( V_94 ) ;
V_96 = V_104 ;
}
F_19 ( & V_94 -> V_43 . V_57 ) ;
if ( V_34 != NULL )
F_41 ( V_34 ) ;
if ( V_95 -> V_105 == NULL )
goto V_106;
F_21 ( & V_95 -> V_43 . V_57 ) ;
V_34 = NULL ;
if ( V_98 & ( V_107 | V_108 | V_109 ) ) {
F_8 ( V_95 , V_27 , V_103 ) ;
F_6 ( V_95 ) ;
if ( V_98 & V_107 )
F_25 ( V_95 ) ;
if ( V_98 & V_109 )
V_34 = F_13 ( V_95 ) ;
if ( V_98 & V_108 )
F_30 ( V_95 ) ;
V_96 = V_104 ;
}
F_19 ( & V_95 -> V_43 . V_57 ) ;
if ( V_34 != NULL )
F_41 ( V_34 ) ;
V_106:
#ifdef F_40
F_12 ( L_6 ) ;
#endif
return V_96 ;
}
static inline T_1 F_42 ( struct V_1 * V_2 )
{
unsigned long V_30 ;
T_1 V_72 ;
F_43 ( & V_2 -> V_43 . V_57 , V_30 ) ;
V_72 = F_3 ( V_2 , V_27 ) ;
F_44 ( & V_2 -> V_43 . V_57 , V_30 ) ;
return V_72 ;
}
static unsigned int F_45 ( struct V_110 * V_43 )
{
struct V_1 * V_2 = F_46 ( V_43 ) ;
unsigned char V_72 ;
if ( F_2 ( V_2 ) || V_2 -> V_105 == NULL )
return V_111 ;
V_72 = F_42 ( F_46 ( V_43 ) ) ;
if ( V_72 & V_81 )
return V_111 ;
return 0 ;
}
static void F_47 ( struct V_110 * V_43 , unsigned int V_112 )
{
struct V_1 * V_2 = F_46 ( V_43 ) ;
unsigned char V_113 , V_114 ;
if ( F_48 ( V_2 ) )
return;
if ( F_2 ( V_2 ) ||
! ( F_14 ( V_2 ) || F_31 ( V_2 ) ) )
return;
V_113 = V_114 = 0 ;
if ( F_49 ( V_2 ) ) {
if ( V_112 & V_115 )
V_113 |= V_116 ;
else
V_114 |= V_116 ;
}
if ( V_112 & V_117 )
V_113 |= V_118 ;
else
V_114 |= V_118 ;
V_2 -> V_32 [ V_15 ] |= V_113 ;
V_2 -> V_32 [ V_15 ] &= ~ V_114 ;
if ( F_2 ( V_2 ) )
return;
F_8 ( V_2 , V_15 , V_2 -> V_32 [ V_15 ] ) ;
F_12 ( L_7 ,
V_113 , V_114 , V_2 -> V_32 [ V_15 ] ) ;
F_6 ( V_2 ) ;
}
static unsigned int F_50 ( struct V_110 * V_43 )
{
struct V_1 * V_2 = F_46 ( V_43 ) ;
unsigned char V_72 ;
unsigned int V_119 ;
if ( F_2 ( V_2 ) || V_2 -> V_105 == NULL )
return 0 ;
V_72 = F_3 ( V_2 , V_27 ) ;
V_119 = 0 ;
if ( V_72 & V_76 )
V_119 |= V_120 ;
if ( V_72 & V_73 )
V_119 |= V_121 ;
if ( ! ( V_72 & V_77 ) )
V_119 |= V_122 ;
return V_119 ;
}
static void F_51 ( struct V_110 * V_43 )
{
F_46 ( V_43 ) -> V_30 |= V_83 ;
}
static void F_52 ( struct V_110 * V_43 )
{
struct V_1 * V_2 = F_46 ( V_43 ) ;
unsigned char V_72 ;
F_12 ( L_8 ) ;
V_2 -> V_30 |= V_82 ;
V_2 -> V_30 &= ~ V_83 ;
if ( F_2 ( V_2 ) || V_2 -> V_105 == NULL )
return;
V_72 = F_3 ( V_2 , V_27 ) ;
if ( ! ( V_72 & V_81 ) )
return;
if ( V_43 -> V_85 ) {
F_33 ( V_2 , V_43 -> V_85 ) ;
F_6 ( V_2 ) ;
V_43 -> V_59 . V_86 ++ ;
V_43 -> V_85 = 0 ;
} else {
struct V_79 * V_80 = & V_43 -> V_44 -> V_80 ;
F_33 ( V_2 , V_80 -> V_87 [ V_80 -> V_88 ] ) ;
F_6 ( V_2 ) ;
V_80 -> V_88 = ( V_80 -> V_88 + 1 ) & ( V_89 - 1 ) ;
V_43 -> V_59 . V_86 ++ ;
if ( F_37 ( V_80 ) < V_90 )
F_35 ( & V_2 -> V_43 ) ;
}
F_12 ( L_9 ) ;
}
static void F_53 ( struct V_110 * V_43 )
{
struct V_1 * V_2 = F_46 ( V_43 ) ;
if ( F_2 ( V_2 ) || V_2 -> V_105 == NULL )
return;
F_12 ( L_10 ) ;
V_2 -> V_32 [ V_6 ] &= ~ V_8 ;
F_9 ( V_2 ) ;
F_12 ( L_11 ) ;
}
static void F_54 ( struct V_110 * V_43 )
{
struct V_1 * V_2 = F_46 ( V_43 ) ;
unsigned char V_123 ;
if ( F_48 ( V_2 ) || V_2 -> V_105 == NULL )
return;
V_123 = V_2 -> V_32 [ V_17 ] | ( V_124 | V_125 | V_126 ) ;
if ( V_123 != V_2 -> V_32 [ V_17 ] ) {
V_2 -> V_32 [ V_17 ] = V_123 ;
if ( F_2 ( V_2 ) )
return;
F_8 ( V_2 , V_17 , V_2 -> V_32 [ V_17 ] ) ;
}
}
static void F_55 ( struct V_110 * V_43 , int V_127 )
{
struct V_1 * V_2 = F_46 ( V_43 ) ;
unsigned char V_113 , V_114 , V_123 ;
unsigned long V_30 ;
if ( V_2 -> V_105 == NULL )
return;
V_113 = V_114 = 0 ;
if ( V_127 )
V_113 |= V_128 ;
else
V_114 |= V_128 ;
F_43 ( & V_43 -> V_57 , V_30 ) ;
V_123 = ( V_2 -> V_32 [ V_15 ] | V_113 ) & ~ V_114 ;
if ( V_123 != V_2 -> V_32 [ V_15 ] ) {
V_2 -> V_32 [ V_15 ] = V_123 ;
if ( F_2 ( V_2 ) ) {
F_44 ( & V_43 -> V_57 , V_30 ) ;
return;
}
F_8 ( V_2 , V_15 , V_2 -> V_32 [ V_15 ] ) ;
}
F_44 ( & V_43 -> V_57 , V_30 ) ;
}
static int F_56 ( struct V_1 * V_2 , int V_44 )
{
int V_129 = 0 ;
int V_96 ;
if ( V_44 ) {
V_96 = F_57 (
V_130 , V_2 -> V_105 , V_2 -> V_131 , 1 ) ;
F_12 ( L_12 , V_96 ) ;
if ( F_49 ( V_2 ) ) {
V_96 = F_57 (
V_132 , V_2 -> V_105 , 0 , 1 ) ;
V_129 = 2500 ;
F_12 ( L_13 , V_96 ) ;
}
} else {
if ( F_49 ( V_2 ) ) {
V_96 = F_57 (
V_132 , V_2 -> V_105 , 0 , 0 ) ;
F_12 ( L_14 , V_96 ) ;
}
F_57 ( V_130 , V_2 -> V_105 , V_2 -> V_131 , 0 ) ;
}
return V_129 ;
}
static int F_56 ( struct V_1 * V_2 , int V_44 )
{
return 0 ;
}
static void F_58 ( struct V_1 * V_2 )
{
F_8 ( V_2 , 9 , F_59 ( V_2 ) ? V_133 : V_134 ) ;
F_6 ( V_2 ) ;
F_4 ( 10 ) ;
F_8 ( V_2 , 9 , ( F_59 ( V_2 ) ? V_133 : V_134 ) | V_135 ) ;
F_6 ( V_2 ) ;
F_8 ( V_2 , 4 , V_136 | V_137 ) ;
F_8 ( V_2 , 3 , V_138 ) ;
F_8 ( V_2 , 5 , V_139 | V_116 ) ;
F_8 ( V_2 , 9 , V_135 ) ;
F_8 ( V_2 , 11 , V_140 | V_141 ) ;
F_8 ( V_2 , 12 , 0 ) ;
F_8 ( V_2 , 13 , 0 ) ;
F_8 ( V_2 , 14 , ( V_142 | V_143 ) ) ;
F_8 ( V_2 , 14 , ( V_142 | V_143 | V_23 ) ) ;
F_8 ( V_2 , 3 , V_138 | V_14 ) ;
F_8 ( V_2 , 0 , V_28 ) ;
F_8 ( V_2 , 0 , V_28 ) ;
F_8 ( V_2 , 0 , V_28 ) ;
F_8 ( V_2 , 9 , V_135 ) ;
F_8 ( V_2 , 4 , V_144 | V_145 ) ;
F_8 ( V_2 , 3 , V_138 ) ;
while ( F_3 ( V_2 , 0 ) & V_42 ) {
( void ) F_3 ( V_2 , 8 ) ;
F_8 ( V_2 , 0 , V_28 ) ;
F_8 ( V_2 , 0 , V_41 ) ;
}
}
static int F_60 ( struct V_1 * V_2 )
{
int V_146 = 0 ;
memset ( & V_2 -> V_32 , 0 , sizeof( V_2 -> V_32 ) ) ;
V_146 = F_56 ( V_2 , 1 ) ;
F_58 ( V_2 ) ;
V_2 -> V_32 [ V_29 ] = 0 ;
F_8 ( V_2 , 9 , F_59 ( V_2 ) ? V_133 : V_134 ) ;
F_6 ( V_2 ) ;
F_4 ( 10 ) ;
F_8 ( V_2 , 9 , 0 ) ;
F_6 ( V_2 ) ;
F_8 ( V_2 , V_6 , 0 ) ;
F_8 ( V_2 , V_27 , V_41 ) ;
F_8 ( V_2 , V_27 , V_41 ) ;
F_8 ( V_2 , V_27 , V_103 ) ;
F_8 ( V_2 , V_27 , V_103 ) ;
V_2 -> V_32 [ V_11 ] = V_144 | V_147 ;
V_2 -> V_32 [ V_13 ] = V_138 ;
V_2 -> V_32 [ V_15 ] = V_139 | V_116 ;
if ( ! F_48 ( V_2 ) )
V_2 -> V_32 [ V_15 ] |= V_118 ;
V_2 -> V_32 [ V_25 ] = 0 ;
V_2 -> V_32 [ V_26 ] = 0 ;
V_2 -> V_32 [ V_22 ] = V_23 ;
V_2 -> V_32 [ V_17 ] = V_148 ;
V_2 -> V_32 [ V_29 ] |= V_135 | V_149 ;
F_1 ( V_2 , V_2 -> V_32 ) ;
F_8 ( V_2 , V_13 , V_2 -> V_32 [ V_13 ] |= V_14 ) ;
F_8 ( V_2 , V_15 , V_2 -> V_32 [ V_15 ] |= V_16 ) ;
V_2 -> V_75 = F_3 ( V_2 , V_27 ) ;
return V_146 ;
}
static void F_61 ( struct V_1 * V_2 )
{
V_2 -> V_32 [ V_15 ] |= V_118 ;
F_8 ( V_2 , V_15 , V_2 -> V_32 [ V_15 ] ) ;
F_6 ( V_2 ) ;
F_62 ( 110 ) ;
V_2 -> V_32 [ V_15 ] &= ~ V_118 ;
F_8 ( V_2 , V_15 , V_2 -> V_32 [ V_15 ] ) ;
F_6 ( V_2 ) ;
F_62 ( 10 ) ;
}
static int F_63 ( struct V_110 * V_43 )
{
struct V_1 * V_2 = F_46 ( V_43 ) ;
unsigned long V_30 ;
int V_146 = 0 ;
F_12 ( L_15 ) ;
if ( F_2 ( V_2 ) )
return - V_150 ;
if ( V_2 -> V_105 == NULL )
return - V_151 ;
F_64 ( & V_152 ) ;
V_2 -> V_30 |= V_153 ;
if ( ! F_31 ( V_2 ) ) {
F_43 ( & V_43 -> V_57 , V_30 ) ;
V_146 = F_60 ( V_2 ) ;
F_44 ( & V_43 -> V_57 , V_30 ) ;
}
F_39 ( V_2 ) -> V_30 |= V_154 ;
if ( F_65 ( V_2 -> V_43 . V_92 , F_38 , V_155 ,
L_16 , V_2 ) ) {
F_24 ( L_17 ) ;
F_56 ( V_2 , 0 ) ;
F_66 ( & V_152 ) ;
return - V_156 ;
}
F_66 ( & V_152 ) ;
if ( V_146 != 0 ) {
F_12 ( L_18 , V_146 ) ;
F_67 ( V_146 ) ;
}
if ( F_48 ( V_2 ) )
F_61 ( V_2 ) ;
F_43 ( & V_43 -> V_57 , V_30 ) ;
V_2 -> V_32 [ V_6 ] |= V_157 | V_9 ;
if ( ! F_68 ( V_2 ) )
V_2 -> V_32 [ V_6 ] |= V_10 ;
F_8 ( V_2 , V_6 , V_2 -> V_32 [ V_6 ] ) ;
F_44 ( & V_43 -> V_57 , V_30 ) ;
F_12 ( L_19 ) ;
return 0 ;
}
static void F_69 ( struct V_110 * V_43 )
{
struct V_1 * V_2 = F_46 ( V_43 ) ;
unsigned long V_30 ;
F_12 ( L_20 ) ;
if ( V_2 -> V_105 == NULL )
return;
F_64 ( & V_152 ) ;
F_70 ( V_2 -> V_43 . V_92 , V_2 ) ;
F_43 ( & V_43 -> V_57 , V_30 ) ;
V_2 -> V_30 &= ~ V_153 ;
if ( ! F_14 ( V_2 -> V_99 ) )
F_39 ( V_2 ) -> V_30 &= ~ V_154 ;
if ( ! F_2 ( V_2 ) ) {
V_2 -> V_32 [ V_6 ] &= ~ ( V_10 | V_9 | V_8 ) ;
F_8 ( V_2 , V_6 , V_2 -> V_32 [ V_6 ] ) ;
F_6 ( V_2 ) ;
}
if ( F_31 ( V_2 ) || F_2 ( V_2 ) ) {
F_44 ( & V_43 -> V_57 , V_30 ) ;
F_66 ( & V_152 ) ;
return;
}
V_2 -> V_32 [ V_13 ] &= ~ V_14 ;
V_2 -> V_32 [ V_15 ] &= ~ V_16 ;
V_2 -> V_32 [ V_15 ] &= ~ V_128 ;
F_9 ( V_2 ) ;
F_56 ( V_2 , 0 ) ;
F_44 ( & V_43 -> V_57 , V_30 ) ;
F_66 ( & V_152 ) ;
F_12 ( L_21 ) ;
}
static void F_71 ( struct V_1 * V_2 , unsigned int V_158 ,
unsigned int V_159 , unsigned long V_160 )
{
int V_161 ;
if ( V_160 >= 115200 && F_48 ( V_2 ) ) {
V_2 -> V_32 [ V_11 ] = V_136 ;
V_2 -> V_32 [ V_24 ] = V_162 | V_163 ;
V_2 -> V_32 [ V_22 ] = 0 ;
V_2 -> V_32 [ V_25 ] = 0 ;
V_2 -> V_32 [ V_26 ] = 0 ;
V_2 -> V_30 |= V_164 ;
} else {
switch ( V_160 ) {
case V_165 / 16 :
V_2 -> V_32 [ V_11 ] = V_144 ;
V_2 -> V_32 [ V_24 ] = 0 ;
V_2 -> V_32 [ V_22 ] = 0 ;
break;
case V_165 / 32 :
V_2 -> V_32 [ V_11 ] = V_166 ;
V_2 -> V_32 [ V_24 ] = 0 ;
V_2 -> V_32 [ V_22 ] = 0 ;
break;
default:
V_2 -> V_32 [ V_11 ] = V_144 ;
V_2 -> V_32 [ V_24 ] = V_141 | V_140 ;
V_161 = F_72 ( V_160 , V_165 / 16 ) ;
V_2 -> V_32 [ V_25 ] = ( V_161 & 255 ) ;
V_2 -> V_32 [ V_26 ] = ( ( V_161 >> 8 ) & 255 ) ;
V_2 -> V_32 [ V_22 ] = V_23 ;
}
V_2 -> V_30 &= ~ V_164 ;
}
V_2 -> V_32 [ 3 ] &= ~ V_167 ;
V_2 -> V_32 [ 5 ] &= ~ V_168 ;
switch ( V_158 & V_169 ) {
case V_170 :
V_2 -> V_32 [ 3 ] |= V_171 ;
V_2 -> V_32 [ 5 ] |= V_172 ;
V_2 -> V_48 = 0x1f ;
break;
case V_173 :
V_2 -> V_32 [ 3 ] |= V_174 ;
V_2 -> V_32 [ 5 ] |= V_175 ;
V_2 -> V_48 = 0x3f ;
break;
case V_176 :
V_2 -> V_32 [ 3 ] |= V_177 ;
V_2 -> V_32 [ 5 ] |= V_178 ;
V_2 -> V_48 = 0x7f ;
break;
case V_179 :
default:
V_2 -> V_32 [ 3 ] |= V_138 ;
V_2 -> V_32 [ 5 ] |= V_139 ;
V_2 -> V_48 = 0xff ;
break;
} ;
V_2 -> V_32 [ 4 ] &= ~ ( V_145 ) ;
if ( V_158 & V_180 )
V_2 -> V_32 [ 4 ] |= V_181 ;
else
V_2 -> V_32 [ 4 ] |= V_147 ;
if ( V_158 & V_182 )
V_2 -> V_32 [ 4 ] |= V_183 ;
else
V_2 -> V_32 [ 4 ] &= ~ V_183 ;
if ( ! ( V_158 & V_184 ) )
V_2 -> V_32 [ 4 ] |= V_185 ;
else
V_2 -> V_32 [ 4 ] &= ~ V_185 ;
V_2 -> V_43 . V_66 = V_46 ;
if ( V_159 & V_186 )
V_2 -> V_43 . V_66 |= V_47 | V_45 ;
if ( V_159 & ( V_187 | V_188 ) )
V_2 -> V_43 . V_66 |= V_61 ;
V_2 -> V_43 . V_70 = 0 ;
if ( V_159 & V_189 )
V_2 -> V_43 . V_70 |= V_47 | V_45 ;
if ( V_159 & V_190 ) {
V_2 -> V_43 . V_70 |= V_61 ;
if ( V_159 & V_189 )
V_2 -> V_43 . V_70 |= V_46 ;
}
if ( ( V_158 & V_191 ) == 0 )
V_2 -> V_43 . V_70 = 0xff ;
}
static void F_73 ( struct V_1 * V_2 , unsigned long * V_160 )
{
T_1 V_192 ;
int V_193 , V_194 ;
switch ( * V_160 ) {
case 2400 :
V_192 = 0x53 ;
break;
case 4800 :
V_192 = 0x52 ;
break;
case 9600 :
V_192 = 0x51 ;
break;
case 19200 :
V_192 = 0x50 ;
break;
case 38400 :
V_192 = 0x4f ;
break;
case 57600 :
V_192 = 0x4e ;
break;
case 115200 :
V_192 = 0x4d ;
break;
case 1152000 :
V_192 = 0 ;
break;
case 4000000 :
V_192 = 0 ;
break;
default:
V_192 = 0x51 ;
* V_160 = 9600 ;
break;
}
V_193 = 10000 ;
while ( ( F_3 ( V_2 , V_27 ) & V_81 ) == 0
|| ( F_3 ( V_2 , V_6 ) & V_7 ) == 0 ) {
if ( -- V_193 <= 0 ) {
F_24 ( L_22 ) ;
return;
}
F_4 ( 10 ) ;
}
V_193 = 100 ;
( void ) F_15 ( V_2 ) ;
( void ) F_15 ( V_2 ) ;
( void ) F_15 ( V_2 ) ;
F_62 ( 10 ) ;
while ( F_3 ( V_2 , V_27 ) & V_42 ) {
F_15 ( V_2 ) ;
F_62 ( 10 ) ;
if ( -- V_193 <= 0 ) {
F_24 ( L_23 ) ;
return;
}
}
V_2 -> V_32 [ V_15 ] |= V_118 ;
F_8 ( V_2 , V_15 , V_2 -> V_32 [ V_15 ] ) ;
F_6 ( V_2 ) ;
F_62 ( 1 ) ;
F_71 ( V_2 , V_179 , 0 , 19200 ) ;
F_1 ( V_2 , V_2 -> V_32 ) ;
F_62 ( 1 ) ;
F_33 ( V_2 , 1 ) ;
V_193 = 5000 ;
while ( ( F_3 ( V_2 , V_27 ) & V_42 ) == 0 ) {
if ( -- V_193 <= 0 ) {
F_24 ( L_24 ) ;
goto V_106;
}
F_4 ( 10 ) ;
}
V_194 = F_15 ( V_2 ) ;
if ( V_194 < 4 ) {
F_74 ( L_25 , V_194 ) ;
goto V_106;
}
F_33 ( V_2 , V_192 ) ;
V_193 = 5000 ;
while ( ( F_3 ( V_2 , V_27 ) & V_42 ) == 0 ) {
if ( -- V_193 <= 0 ) {
F_24 ( L_26 ) ;
goto V_106;
}
F_4 ( 10 ) ;
}
V_193 = F_15 ( V_2 ) ;
if ( V_193 != V_192 )
F_24 ( L_27 , V_193 , V_192 ) ;
F_74 ( L_28 ,
* V_160 , V_194 ) ;
( void ) F_15 ( V_2 ) ;
( void ) F_15 ( V_2 ) ;
( void ) F_15 ( V_2 ) ;
V_106:
V_2 -> V_32 [ V_15 ] &= ~ V_118 ;
F_8 ( V_2 , V_15 , V_2 -> V_32 [ V_15 ] ) ;
F_6 ( V_2 ) ;
( void ) F_15 ( V_2 ) ;
( void ) F_15 ( V_2 ) ;
( void ) F_15 ( V_2 ) ;
}
static void F_75 ( struct V_110 * V_43 , struct V_195 * V_196 ,
struct V_195 * V_197 )
{
struct V_1 * V_2 = F_46 ( V_43 ) ;
unsigned long V_160 ;
F_12 ( L_29 ) ;
if ( F_2 ( V_2 ) )
return;
memcpy ( & V_2 -> V_198 , V_196 , sizeof( struct V_195 ) ) ;
if ( F_48 ( V_2 ) ) {
V_160 = F_76 ( V_43 , V_196 , V_197 , 1200 , 4000000 ) ;
F_12 ( L_30 , V_160 ) ;
F_73 ( V_2 , & V_160 ) ;
F_71 ( V_2 , V_196 -> V_199 , V_196 -> V_200 , V_160 ) ;
F_1 ( V_2 , V_2 -> V_32 ) ;
F_6 ( V_2 ) ;
} else {
V_160 = F_76 ( V_43 , V_196 , V_197 , 1200 , 230400 ) ;
F_71 ( V_2 , V_196 -> V_199 , V_196 -> V_200 , V_160 ) ;
if ( F_77 ( & V_2 -> V_43 , V_196 -> V_199 ) ) {
V_2 -> V_32 [ V_17 ] |= V_124 | V_125 | V_126 ;
V_2 -> V_30 |= V_201 ;
} else {
V_2 -> V_32 [ V_17 ] &= ~ ( V_124 | V_125 | V_126 ) ;
V_2 -> V_30 &= ~ V_201 ;
}
F_9 ( V_2 ) ;
}
F_78 ( V_43 , V_196 -> V_199 , V_160 ) ;
F_12 ( L_31 ) ;
}
static void F_79 ( struct V_110 * V_43 , struct V_195 * V_196 ,
struct V_195 * V_197 )
{
struct V_1 * V_2 = F_46 ( V_43 ) ;
unsigned long V_30 ;
F_43 ( & V_43 -> V_57 , V_30 ) ;
V_2 -> V_32 [ V_6 ] &= ~ ( V_10 | V_9 | V_8 ) ;
F_8 ( V_2 , V_6 , V_2 -> V_32 [ V_6 ] ) ;
F_75 ( V_43 , V_196 , V_197 ) ;
if ( F_14 ( V_2 ) ) {
V_2 -> V_32 [ V_6 ] |= V_157 | V_9 ;
if ( ! F_68 ( V_2 ) )
V_2 -> V_32 [ V_6 ] |= V_10 ;
F_8 ( V_2 , V_6 , V_2 -> V_32 [ V_6 ] ) ;
}
F_44 ( & V_43 -> V_57 , V_30 ) ;
}
static const char * F_80 ( struct V_110 * V_43 )
{
struct V_1 * V_2 = F_46 ( V_43 ) ;
if ( F_48 ( V_2 ) )
return L_32 ;
else if ( F_49 ( V_2 ) )
return L_33 ;
return L_34 ;
}
static void F_81 ( struct V_110 * V_43 )
{
}
static int F_82 ( struct V_110 * V_43 )
{
return 0 ;
}
static void F_83 ( struct V_110 * V_43 , int V_30 )
{
}
static int F_84 ( struct V_110 * V_43 , struct V_202 * V_203 )
{
return - V_204 ;
}
static int F_85 ( struct V_110 * V_43 )
{
struct V_1 * V_2 = (struct V_1 * ) V_43 ;
while ( ( F_3 ( V_2 , V_27 ) & V_42 ) == 0 )
F_4 ( 5 ) ;
return F_15 ( V_2 ) ;
}
static void F_86 ( struct V_110 * V_43 , unsigned char V_205 )
{
struct V_1 * V_2 = (struct V_1 * ) V_43 ;
while ( ( F_3 ( V_2 , V_27 ) & V_81 ) == 0 )
F_4 ( 5 ) ;
F_33 ( V_2 , V_205 ) ;
}
static int T_3 F_87 ( struct V_1 * V_2 )
{
struct V_206 * V_207 = V_2 -> V_105 ;
const char * V_208 ;
const struct V_209 {
int V_210 ;
char V_211 [ 1 ] ;
} * V_212 ;
int V_213 ;
struct V_214 V_215 , V_216 , V_217 ;
if ( F_88 ( V_207 , 0 , & V_215 ) )
return - V_151 ;
V_2 -> V_43 . V_218 = V_215 . V_219 ;
V_2 -> V_43 . V_220 = F_89 ( V_2 -> V_43 . V_218 , 0x1000 ) ;
V_2 -> V_221 = V_2 -> V_43 . V_220 ;
V_2 -> V_222 = V_2 -> V_221 + 0x10 ;
#ifdef F_90
if ( F_88 ( V_207 , 1 , & V_217 ) == 0 &&
F_88 ( V_207 , 2 , & V_216 ) == 0 )
V_2 -> V_30 |= V_223 ;
#else
memset ( & V_217 , 0 , sizeof( struct V_214 ) ) ;
memset ( & V_216 , 0 , sizeof( struct V_214 ) ) ;
#endif
if ( F_91 ( V_2 ) ) {
V_2 -> V_224 = F_89 ( V_217 . V_219 , 0x100 ) ;
if ( V_2 -> V_224 == NULL ) {
V_2 -> V_30 &= ~ V_223 ;
goto V_225;
}
V_2 -> V_226 = F_89 ( V_216 . V_219 , 0x100 ) ;
if ( V_2 -> V_226 == NULL ) {
F_92 ( V_2 -> V_224 ) ;
V_2 -> V_224 = NULL ;
V_2 -> V_30 &= ~ V_223 ;
goto V_225;
}
V_2 -> V_227 = F_93 ( V_207 , 1 ) ;
V_2 -> V_228 = F_93 ( V_207 , 2 ) ;
}
V_225:
if ( F_94 ( V_207 , L_35 ) )
V_2 -> V_30 |= V_229 ;
V_208 = F_95 ( V_207 , L_36 , & V_213 ) ;
if ( V_208 && ( strcmp ( V_208 , L_37 ) == 0 ) )
V_2 -> V_30 |= V_230 ;
V_2 -> V_131 = V_231 ;
V_212 = F_95 ( V_207 , L_38 , & V_213 ) ;
if ( V_212 && V_212 -> V_210 > 0 ) {
if ( strcmp ( V_212 -> V_211 , L_39 ) == 0 )
V_2 -> V_30 |= V_230 ;
else if ( strcmp ( V_212 -> V_211 , L_40 ) == 0 )
V_2 -> V_30 |= V_229 ;
}
if ( F_48 ( V_2 ) )
V_2 -> V_131 = V_232 ;
if ( F_49 ( V_2 ) ) {
struct V_206 * V_233 =
F_96 ( NULL , L_41 ) ;
if ( V_233 ) {
const char * V_234 =
F_95 ( V_233 , L_42 , NULL ) ;
if ( V_234 ) switch( * V_234 ) {
case 0x04 :
case 0x05 :
case 0x07 :
case 0x08 :
case 0x0b :
case 0x0c :
V_2 -> V_131 = V_235 ;
}
F_97 ( V_236 L_43 ,
V_234 ? ( * V_234 ) : 0 ) ;
F_98 ( V_233 ) ;
} else {
F_97 ( V_236 L_44 ) ;
}
}
V_2 -> V_43 . V_237 = V_238 ;
V_2 -> V_43 . V_92 = F_93 ( V_207 , 0 ) ;
V_2 -> V_43 . V_239 = V_165 ;
V_2 -> V_43 . V_240 = 1 ;
V_2 -> V_43 . V_241 = & V_242 ;
V_2 -> V_43 . type = V_243 ;
V_2 -> V_43 . V_30 = 0 ;
if ( V_2 -> V_43 . V_92 == V_244 &&
V_207 -> V_245 && V_207 -> V_245 -> V_245 &&
F_94 ( V_207 -> V_245 -> V_245 , L_45 ) ) {
V_2 -> V_43 . V_92 = F_99 ( NULL , 64 + 15 ) ;
V_2 -> V_227 = F_99 ( NULL , 64 + 4 ) ;
V_2 -> V_228 = F_99 ( NULL , 64 + 5 ) ;
}
F_71 ( V_2 , V_179 , 0 , 9600 ) ;
return 0 ;
}
static void F_100 ( struct V_1 * V_2 )
{
struct V_206 * V_207 ;
V_207 = V_2 -> V_105 ;
F_92 ( V_2 -> V_226 ) ;
F_92 ( V_2 -> V_224 ) ;
F_92 ( V_2 -> V_221 ) ;
V_2 -> V_105 = NULL ;
F_98 ( V_207 ) ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
}
static int F_101 ( struct V_246 * V_247 , const struct V_248 * V_249 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_250 ; V_4 ++ )
if ( V_251 [ V_4 ] . V_105 == V_247 -> V_252 . V_253 . V_254 ) {
struct V_1 * V_2 = & V_251 [ V_4 ] ;
V_2 -> V_253 = V_247 ;
F_102 ( & V_247 -> V_252 . V_253 , V_2 ) ;
if ( F_103 ( V_2 -> V_253 , L_46 ) )
F_97 ( V_255 L_47
L_48 ,
V_2 -> V_105 -> V_211 ) ;
else
V_2 -> V_30 |= V_256 ;
return 0 ;
}
return - V_151 ;
}
static int F_104 ( struct V_246 * V_247 )
{
struct V_1 * V_2 = F_105 ( & V_247 -> V_252 . V_253 ) ;
if ( ! V_2 )
return - V_151 ;
if ( V_2 -> V_30 & V_256 ) {
F_106 ( V_2 -> V_253 ) ;
V_2 -> V_30 &= ~ V_256 ;
}
F_102 ( & V_247 -> V_252 . V_253 , NULL ) ;
V_2 -> V_253 = NULL ;
return 0 ;
}
static int F_107 ( struct V_246 * V_247 , T_4 V_257 )
{
struct V_1 * V_2 = F_105 ( & V_247 -> V_252 . V_253 ) ;
struct V_258 * V_44 ;
unsigned long V_30 ;
if ( V_2 == NULL ) {
F_97 ( L_49 ) ;
return 0 ;
}
if ( V_257 . V_259 == V_247 -> V_252 . V_253 . V_260 . V_261 . V_259 )
return 0 ;
F_12 ( L_50 , V_257 . V_259 ) ;
V_44 = V_262 . V_44 + V_2 -> V_43 . line ;
F_64 ( & V_152 ) ;
F_64 ( & V_44 -> V_43 . V_263 ) ;
F_43 ( & V_2 -> V_43 . V_57 , V_30 ) ;
if ( F_14 ( V_2 ) || F_31 ( V_2 ) ) {
V_2 -> V_32 [ V_13 ] &= ~ V_14 ;
V_2 -> V_32 [ V_15 ] &= ~ V_16 ;
V_2 -> V_32 [ V_6 ] &= ~ ( V_10 | V_9 | V_8 ) ;
V_2 -> V_32 [ V_15 ] &= ~ V_128 ;
F_1 ( V_2 , V_2 -> V_32 ) ;
V_2 -> V_30 |= V_264 ;
F_108 () ;
}
F_44 ( & V_2 -> V_43 . V_57 , V_30 ) ;
if ( F_14 ( V_2 ) || F_14 ( V_2 -> V_99 ) )
if ( F_2 ( V_2 -> V_99 ) && F_109 ( F_39 ( V_2 ) ) ) {
F_39 ( V_2 ) -> V_30 &= ~ V_154 ;
F_110 ( V_2 -> V_43 . V_92 ) ;
}
if ( F_31 ( V_2 ) )
V_2 -> V_43 . V_265 -> V_30 &= ~ V_266 ;
F_56 ( V_2 , 0 ) ;
F_66 ( & V_44 -> V_43 . V_263 ) ;
F_66 ( & V_152 ) ;
F_12 ( L_51 ) ;
V_247 -> V_252 . V_253 . V_260 . V_261 = V_257 ;
return 0 ;
}
static int F_111 ( struct V_246 * V_247 )
{
struct V_1 * V_2 = F_105 ( & V_247 -> V_252 . V_253 ) ;
struct V_258 * V_44 ;
unsigned long V_30 ;
int V_146 = 0 ;
if ( V_2 == NULL )
return 0 ;
if ( V_247 -> V_252 . V_253 . V_260 . V_261 . V_259 == V_267 )
return 0 ;
F_12 ( L_52 ) ;
V_44 = V_262 . V_44 + V_2 -> V_43 . line ;
F_64 ( & V_152 ) ;
F_64 ( & V_44 -> V_43 . V_263 ) ;
F_43 ( & V_2 -> V_43 . V_57 , V_30 ) ;
if ( ! F_14 ( V_2 ) && ! F_31 ( V_2 ) ) {
F_44 ( & V_2 -> V_43 . V_57 , V_30 ) ;
goto V_268;
}
V_146 = F_60 ( V_2 ) ;
F_75 ( & V_2 -> V_43 , & V_2 -> V_198 , NULL ) ;
if ( F_14 ( V_2 ) ) {
V_2 -> V_32 [ V_6 ] |= V_157 | V_9 ;
if ( ! F_68 ( V_2 ) )
V_2 -> V_32 [ V_6 ] |= V_10 ;
F_8 ( V_2 , V_6 , V_2 -> V_32 [ V_6 ] ) ;
}
F_44 ( & V_2 -> V_43 . V_57 , V_30 ) ;
if ( F_31 ( V_2 ) )
V_2 -> V_43 . V_265 -> V_30 |= V_266 ;
if ( F_14 ( V_2 ) && ! F_109 ( F_39 ( V_2 ) ) ) {
F_39 ( V_2 ) -> V_30 |= V_154 ;
F_112 ( V_2 -> V_43 . V_92 ) ;
}
V_268:
F_66 ( & V_44 -> V_43 . V_263 ) ;
F_66 ( & V_152 ) ;
if ( V_146 != 0 ) {
F_12 ( L_18 , V_146 ) ;
F_67 ( V_146 ) ;
}
F_12 ( L_53 ) ;
V_247 -> V_252 . V_253 . V_260 . V_261 . V_259 = V_267 ;
return 0 ;
}
static int T_3 F_113 ( void )
{
struct V_206 * V_269 , * V_270 , * V_271 , * V_207 ;
int V_210 = 0 ;
int V_96 ;
V_269 = F_96 ( NULL , L_54 ) ;
while ( V_269 ) {
V_270 = V_271 = NULL ;
for ( V_207 = NULL ; ( V_207 = F_114 ( V_269 , V_207 ) ) != NULL ; ) {
if ( strncmp ( V_207 -> V_211 , L_55 , 4 ) == 0 )
V_270 = F_115 ( V_207 ) ;
else if ( strncmp ( V_207 -> V_211 , L_56 , 4 ) == 0 )
V_271 = F_115 ( V_207 ) ;
}
if ( ! V_270 && ! V_271 ) {
F_98 ( V_270 ) ;
F_98 ( V_271 ) ;
F_97 ( V_272 L_57 ,
( ! V_270 ) ? 'a' : 'b' , V_269 -> V_273 ) ;
goto V_274;
}
V_251 [ V_210 ] . V_99 = & V_251 [ V_210 + 1 ] ;
V_251 [ V_210 + 1 ] . V_99 = & V_251 [ V_210 ] ;
V_251 [ V_210 ] . V_30 = V_275 ;
V_251 [ V_210 ] . V_105 = V_270 ;
V_251 [ V_210 + 1 ] . V_105 = V_271 ;
V_251 [ V_210 ] . V_43 . line = V_210 ;
V_251 [ V_210 + 1 ] . V_43 . line = V_210 + 1 ;
V_96 = F_87 ( & V_251 [ V_210 ] ) ;
if ( V_96 == 0 && V_271 != NULL )
V_96 = F_87 ( & V_251 [ V_210 + 1 ] ) ;
if ( V_96 != 0 ) {
F_98 ( V_270 ) ;
F_98 ( V_271 ) ;
memset ( & V_251 [ V_210 ] , 0 , sizeof( struct V_1 ) ) ;
memset ( & V_251 [ V_210 + 1 ] , 0 , sizeof( struct V_1 ) ) ;
goto V_274;
}
V_210 += 2 ;
V_274:
V_269 = F_96 ( V_269 , L_54 ) ;
}
V_276 = V_210 ;
return 0 ;
}
static int T_3 F_87 ( struct V_1 * V_2 )
{
struct V_214 * V_215 ;
int V_92 ;
V_215 = F_116 ( V_2 -> V_105 , V_277 , 0 ) ;
V_92 = F_117 ( V_2 -> V_105 , 0 ) ;
if ( ! V_215 || ! V_92 )
return - V_151 ;
V_2 -> V_43 . V_218 = V_215 -> V_219 ;
V_2 -> V_43 . V_220 = ( unsigned char V_278 * ) V_215 -> V_219 ;
V_2 -> V_43 . V_237 = V_238 ;
V_2 -> V_43 . V_92 = V_92 ;
V_2 -> V_43 . V_239 = V_165 ;
V_2 -> V_43 . V_240 = 1 ;
V_2 -> V_43 . V_241 = & V_242 ;
V_2 -> V_43 . type = V_243 ;
V_2 -> V_43 . V_30 = 0 ;
V_2 -> V_221 = V_2 -> V_43 . V_220 ;
V_2 -> V_222 = V_2 -> V_221 + 4 ;
V_2 -> V_131 = 0 ;
F_71 ( V_2 , V_179 , 0 , 9600 ) ;
return 0 ;
}
static int T_3 F_113 ( void )
{
int V_279 ;
V_276 = 0 ;
V_251 [ 0 ] . V_99 = & V_251 [ 1 ] ;
V_251 [ 0 ] . V_43 . line = 0 ;
V_251 [ 0 ] . V_30 = V_275 ;
V_251 [ 0 ] . V_105 = & V_280 ;
V_279 = F_87 ( & V_251 [ 0 ] ) ;
if ( V_279 )
return V_279 ;
V_276 ++ ;
V_251 [ 1 ] . V_99 = & V_251 [ 0 ] ;
V_251 [ 1 ] . V_43 . line = 1 ;
V_251 [ 1 ] . V_30 = 0 ;
V_251 [ 1 ] . V_105 = & V_281 ;
V_279 = F_87 ( & V_251 [ 1 ] ) ;
if ( V_279 )
return V_279 ;
V_276 ++ ;
return 0 ;
}
static void F_100 ( struct V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
}
static int T_3 F_101 ( struct V_282 * V_283 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_276 ; V_4 ++ )
if ( V_251 [ V_4 ] . V_105 == V_283 )
return 0 ;
return - V_151 ;
}
static int T_5 F_104 ( struct V_282 * V_283 )
{
return 0 ;
}
static int T_3 F_118 ( void )
{
int V_4 , V_96 ;
V_262 . V_284 = V_276 ;
V_262 . V_265 = V_285 ;
V_96 = F_119 ( & V_262 ) ;
if ( V_96 )
return V_96 ;
for ( V_4 = 0 ; V_4 < V_276 ; V_4 ++ ) {
struct V_1 * V_286 = & V_251 [ V_4 ] ;
if ( V_286 -> V_105 != NULL )
V_96 = F_120 ( & V_262 , & V_286 -> V_43 ) ;
if ( V_96 )
goto V_287;
}
return 0 ;
V_287:
while ( V_4 -- > 0 ) {
struct V_1 * V_286 = & V_251 [ V_4 ] ;
F_121 ( & V_262 , & V_286 -> V_43 ) ;
}
F_122 ( & V_262 ) ;
return V_96 ;
}
static int T_3 F_123 ( void )
{
int V_96 , V_4 ;
F_97 ( V_236 L_58 , V_194 ) ;
if ( V_276 == 0 )
F_113 () ;
if ( V_276 == 0 )
return - V_151 ;
V_96 = F_118 () ;
if ( V_96 ) {
F_97 ( V_272
L_59
L_60 ) ;
for ( V_4 = 0 ; V_4 < V_276 ; V_4 ++ )
F_100 ( & V_251 [ V_4 ] ) ;
return V_96 ;
}
#ifdef F_124
return F_125 ( & V_288 ) ;
#else
return F_126 ( & V_288 , F_101 ) ;
#endif
}
static void T_5 F_127 ( void )
{
int V_4 ;
#ifdef F_124
F_128 ( & V_288 ) ;
#else
F_129 ( & V_288 ) ;
#endif
for ( V_4 = 0 ; V_4 < V_276 ; V_4 ++ ) {
struct V_1 * V_286 = & V_251 [ V_4 ] ;
if ( V_286 -> V_105 != NULL ) {
F_121 ( & V_262 , & V_286 -> V_43 ) ;
F_100 ( V_286 ) ;
}
}
F_122 ( & V_262 ) ;
}
static void F_130 ( struct V_110 * V_43 , int V_35 )
{
struct V_1 * V_2 = (struct V_1 * ) V_43 ;
while ( ( F_3 ( V_2 , V_27 ) & V_81 ) == 0 )
F_4 ( 5 ) ;
F_33 ( V_2 , V_35 ) ;
}
static void F_131 ( struct V_289 * V_290 , const char * V_291 , unsigned int V_210 )
{
struct V_1 * V_2 = & V_251 [ V_290 -> V_292 ] ;
unsigned long V_30 ;
if ( F_2 ( V_2 ) )
return;
F_43 ( & V_2 -> V_43 . V_57 , V_30 ) ;
F_8 ( V_2 , V_6 , V_2 -> V_32 [ 1 ] & ~ V_9 ) ;
F_8 ( V_2 , V_15 , V_2 -> V_32 [ 5 ] | V_16 | V_116 | V_118 ) ;
F_132 ( & V_2 -> V_43 , V_291 , V_210 , F_130 ) ;
F_8 ( V_2 , V_6 , V_2 -> V_32 [ 1 ] ) ;
F_44 ( & V_2 -> V_43 . V_57 , V_30 ) ;
}
static int T_3 F_133 ( struct V_289 * V_293 , char * V_294 )
{
struct V_1 * V_2 ;
struct V_110 * V_43 ;
int V_160 = 38400 ;
int V_295 = 8 ;
int V_63 = 'n' ;
int V_296 = 'n' ;
unsigned long V_146 ;
if ( F_134 ( L_61 )
|| F_134 ( L_62 )
|| F_134 ( L_63 ) )
V_160 = 57600 ;
if ( V_293 -> V_292 >= V_276 )
V_293 -> V_292 = 0 ;
V_2 = & V_251 [ V_293 -> V_292 ] ;
if ( V_2 -> V_105 == NULL )
return - V_151 ;
V_43 = & V_2 -> V_43 ;
V_2 -> V_30 |= V_297 ;
F_135 ( & V_43 -> V_57 ) ;
V_146 = F_60 ( V_2 ) ;
if ( V_146 )
F_62 ( V_146 ) ;
if ( V_294 )
F_136 ( V_294 , & V_160 , & V_63 , & V_295 , & V_296 ) ;
return F_137 ( V_43 , V_293 , V_160 , V_63 , V_295 , V_296 ) ;
}
static int T_3 F_138 ( void )
{
F_113 () ;
F_139 ( & V_298 ) ;
return 0 ;
}
