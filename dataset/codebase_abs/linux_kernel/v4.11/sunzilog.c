static unsigned char F_1 ( struct V_1 T_1 * V_2 ,
unsigned char V_3 )
{
unsigned char V_4 ;
F_2 ( V_3 , & V_2 -> V_5 ) ;
F_3 () ;
V_4 = F_4 ( & V_2 -> V_5 ) ;
F_3 () ;
return V_4 ;
}
static void F_5 ( struct V_1 T_1 * V_2 ,
unsigned char V_3 , unsigned char V_6 )
{
F_2 ( V_3 , & V_2 -> V_5 ) ;
F_3 () ;
F_2 ( V_6 , & V_2 -> V_5 ) ;
F_3 () ;
}
static void F_6 ( struct V_1 T_1 * V_2 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < 32 ; V_7 ++ ) {
unsigned char V_8 ;
V_8 = F_4 ( & V_2 -> V_5 ) ;
F_3 () ;
if ( V_8 & V_9 )
break;
V_8 = F_1 ( V_2 , V_10 ) ;
F_4 ( & V_2 -> V_11 ) ;
F_3 () ;
if ( V_8 & ( V_12 | V_13 | V_14 ) ) {
F_2 ( V_15 , & V_2 -> V_5 ) ;
F_3 () ;
F_7 ( V_2 ) ;
}
}
}
static int F_8 ( struct V_1 T_1 * V_2 , unsigned char * V_16 )
{
int V_7 ;
int V_17 ;
unsigned char V_18 ;
for ( V_7 = 0 ; V_7 < 1000 ; V_7 ++ ) {
unsigned char V_19 = F_1 ( V_2 , V_10 ) ;
if ( V_19 & V_20 )
break;
F_9 ( 100 ) ;
}
F_2 ( V_15 , & V_2 -> V_5 ) ;
F_3 () ;
F_7 ( V_2 ) ;
F_6 ( V_2 ) ;
F_5 ( V_2 , V_10 ,
V_16 [ V_10 ] & ~ ( V_21 | V_22 | V_23 ) ) ;
F_5 ( V_2 , V_24 , V_16 [ V_24 ] ) ;
F_5 ( V_2 , V_25 , V_16 [ V_25 ] ) ;
F_5 ( V_2 , V_26 , V_16 [ V_26 ] & ~ V_27 ) ;
F_5 ( V_2 , V_28 , V_16 [ V_28 ] & ~ V_29 ) ;
F_5 ( V_2 , V_30 , V_16 [ V_30 ] ) ;
F_5 ( V_2 , V_31 , V_16 [ V_31 ] ) ;
F_5 ( V_2 , V_32 , V_16 [ V_32 ] & ~ V_33 ) ;
F_5 ( V_2 , V_34 , V_16 [ V_34 ] ) ;
F_5 ( V_2 , V_35 , V_16 [ V_35 ] ) ;
F_5 ( V_2 , V_36 , V_16 [ V_36 ] ) ;
F_5 ( V_2 , V_32 , V_16 [ V_32 ] ) ;
F_5 ( V_2 , V_37 , ( V_16 [ V_37 ] | V_38 ) & ~ V_39 ) ;
V_18 = F_1 ( V_2 , V_37 ) ;
if ( V_18 & 0x01 ) {
F_5 ( V_2 , V_31 , V_16 [ V_40 ] ) ;
F_5 ( V_2 , V_37 , V_16 [ V_37 ] & ~ V_38 ) ;
V_17 = 1 ;
} else {
V_16 [ V_37 ] &= ~ V_39 ;
V_17 = 0 ;
}
F_5 ( V_2 , V_41 , V_42 ) ;
F_5 ( V_2 , V_41 , V_42 ) ;
F_5 ( V_2 , V_26 , V_16 [ V_26 ] ) ;
F_5 ( V_2 , V_28 , V_16 [ V_28 ] ) ;
F_5 ( V_2 , V_10 , V_16 [ V_10 ] ) ;
return V_17 ;
}
static void F_10 ( struct V_43 * V_44 ,
struct V_1 T_1 * V_2 )
{
if ( ! F_11 ( V_44 ) ) {
if ( F_12 ( V_44 ) ) {
V_44 -> V_45 |= V_46 ;
} else {
F_8 ( V_2 , V_44 -> V_47 ) ;
}
}
}
static void F_13 ( struct V_43 * V_44 )
{
unsigned int V_48 = V_44 -> V_49 ;
int V_50 , V_51 ;
V_44 -> V_49 &= ~ V_52 ;
V_44 -> V_49 |= F_14 ( V_48 , & V_51 ) ;
V_50 = F_15 ( V_51 , V_53 / V_54 ) ;
V_44 -> V_47 [ V_35 ] = ( V_50 & 0xff ) ;
V_44 -> V_47 [ V_36 ] = ( V_50 >> 8 ) & 0xff ;
F_10 ( V_44 , F_16 ( & V_44 -> V_55 ) ) ;
}
static void F_17 ( struct V_43 * V_44 ,
unsigned char V_56 , int V_57 )
{
if ( F_18 ( V_44 ) ) {
#ifdef F_19
if ( V_44 -> V_58 )
F_20 ( & V_44 -> V_59 , V_56 , 0 ) ;
#endif
} else if ( F_21 ( V_44 ) ) {
int V_60 = F_22 ( V_56 , V_57 ) ;
switch ( V_60 ) {
case 2 :
F_13 ( V_44 ) ;
case 1 :
break;
case 0 :
#ifdef F_19
if ( V_44 -> V_58 )
F_20 ( & V_44 -> V_59 , V_56 , 0 ) ;
#endif
break;
}
}
}
static struct V_61 *
F_23 ( struct V_43 * V_44 ,
struct V_1 T_1 * V_2 )
{
struct V_61 * V_55 = NULL ;
unsigned char V_56 , V_62 , V_63 ;
if ( V_44 -> V_55 . V_64 != NULL )
V_55 = & V_44 -> V_55 . V_64 -> V_55 ;
for (; ; ) {
V_62 = F_1 ( V_2 , V_10 ) ;
if ( V_62 & ( V_12 | V_13 | V_14 ) ) {
F_2 ( V_15 , & V_2 -> V_5 ) ;
F_3 () ;
F_7 ( V_2 ) ;
}
V_56 = F_4 ( & V_2 -> V_5 ) ;
F_3 () ;
if ( V_56 & V_65 )
V_62 |= V_65 ;
if ( ! ( V_56 & V_9 ) )
break;
V_56 = F_4 ( & V_2 -> V_11 ) ;
F_3 () ;
V_56 &= V_44 -> V_66 ;
if ( F_24 ( F_18 ( V_44 ) ) || F_24 ( F_21 ( V_44 ) ) ) {
F_17 ( V_44 , V_56 , 0 ) ;
continue;
}
V_63 = V_67 ;
V_44 -> V_55 . V_68 . V_69 ++ ;
if ( V_62 & ( V_65 | V_12 | V_13 | V_14 ) ) {
if ( V_62 & V_65 ) {
V_62 &= ~ ( V_12 | V_14 ) ;
V_44 -> V_55 . V_68 . V_70 ++ ;
if ( F_25 ( & V_44 -> V_55 ) )
continue;
}
else if ( V_62 & V_12 )
V_44 -> V_55 . V_68 . V_71 ++ ;
else if ( V_62 & V_14 )
V_44 -> V_55 . V_68 . V_72 ++ ;
if ( V_62 & V_13 )
V_44 -> V_55 . V_68 . V_73 ++ ;
V_62 &= V_44 -> V_55 . V_74 ;
if ( V_62 & V_65 )
V_63 = V_75 ;
else if ( V_62 & V_12 )
V_63 = V_76 ;
else if ( V_62 & V_14 )
V_63 = V_77 ;
}
if ( F_26 ( & V_44 -> V_55 , V_56 ) || ! V_55 )
continue;
if ( V_44 -> V_55 . V_78 == 0xff ||
( V_62 & V_44 -> V_55 . V_78 ) == 0 ) {
F_27 ( V_55 , V_56 , V_63 ) ;
}
if ( V_62 & V_13 )
F_27 ( V_55 , 0 , V_79 ) ;
}
return V_55 ;
}
static void F_28 ( struct V_43 * V_44 ,
struct V_1 T_1 * V_2 )
{
unsigned char V_80 ;
V_80 = F_4 ( & V_2 -> V_5 ) ;
F_3 () ;
F_2 ( V_42 , & V_2 -> V_5 ) ;
F_3 () ;
F_7 ( V_2 ) ;
if ( V_80 & V_65 ) {
if ( F_21 ( V_44 ) )
F_17 ( V_44 , 0 , 1 ) ;
if ( F_29 ( V_44 ) ) {
while ( 1 ) {
V_80 = F_4 ( & V_2 -> V_5 ) ;
F_3 () ;
if ( ! ( V_80 & V_65 ) )
break;
}
F_30 () ;
return;
}
}
if ( F_31 ( V_44 ) ) {
if ( V_80 & V_81 )
V_44 -> V_55 . V_68 . V_82 ++ ;
if ( ( V_80 ^ V_44 -> V_83 ) ^ V_84 )
F_32 ( & V_44 -> V_55 ,
( V_80 & V_84 ) ) ;
if ( ( V_80 ^ V_44 -> V_83 ) ^ V_85 )
F_33 ( & V_44 -> V_55 ,
( V_80 & V_85 ) ) ;
F_34 ( & V_44 -> V_55 . V_64 -> V_55 . V_86 ) ;
}
V_44 -> V_83 = V_80 ;
}
static void F_35 ( struct V_43 * V_44 ,
struct V_1 T_1 * V_2 )
{
struct V_87 * V_88 ;
if ( F_29 ( V_44 ) ) {
unsigned char V_80 = F_4 ( & V_2 -> V_5 ) ;
F_3 () ;
if ( ! ( V_80 & V_89 ) )
return;
}
V_44 -> V_45 &= ~ V_90 ;
if ( F_11 ( V_44 ) ) {
F_8 ( V_2 , V_44 -> V_47 ) ;
V_44 -> V_45 &= ~ V_46 ;
}
if ( F_36 ( V_44 ) ) {
V_44 -> V_45 &= ~ V_91 ;
goto V_92;
}
if ( V_44 -> V_55 . V_93 ) {
V_44 -> V_45 |= V_90 ;
F_2 ( V_44 -> V_55 . V_93 , & V_2 -> V_11 ) ;
F_3 () ;
F_7 ( V_2 ) ;
V_44 -> V_55 . V_68 . V_94 ++ ;
V_44 -> V_55 . V_93 = 0 ;
return;
}
if ( V_44 -> V_55 . V_64 == NULL )
goto V_92;
V_88 = & V_44 -> V_55 . V_64 -> V_88 ;
if ( F_37 ( V_88 ) )
goto V_92;
if ( F_38 ( & V_44 -> V_55 ) )
goto V_92;
V_44 -> V_45 |= V_90 ;
F_2 ( V_88 -> V_95 [ V_88 -> V_96 ] , & V_2 -> V_11 ) ;
F_3 () ;
F_7 ( V_2 ) ;
V_88 -> V_96 = ( V_88 -> V_96 + 1 ) & ( V_97 - 1 ) ;
V_44 -> V_55 . V_68 . V_94 ++ ;
if ( F_39 ( V_88 ) < V_98 )
F_40 ( & V_44 -> V_55 ) ;
return;
V_92:
F_2 ( V_99 , & V_2 -> V_5 ) ;
F_3 () ;
F_7 ( V_2 ) ;
}
static T_2 F_41 ( int V_100 , void * V_101 )
{
struct V_43 * V_44 = V_101 ;
while ( V_44 ) {
struct V_1 T_1 * V_2
= F_16 ( & V_44 -> V_55 ) ;
struct V_61 * V_55 ;
unsigned char V_102 ;
F_42 ( & V_44 -> V_55 . V_103 ) ;
V_102 = F_1 ( V_2 , V_26 ) ;
V_55 = NULL ;
if ( V_102 & ( V_104 | V_105 | V_106 ) ) {
F_2 ( V_107 , & V_2 -> V_5 ) ;
F_3 () ;
F_7 ( V_2 ) ;
if ( V_102 & V_106 )
V_55 = F_23 ( V_44 , V_2 ) ;
if ( V_102 & V_104 )
F_28 ( V_44 , V_2 ) ;
if ( V_102 & V_105 )
F_35 ( V_44 , V_2 ) ;
}
F_43 ( & V_44 -> V_55 . V_103 ) ;
if ( V_55 )
F_44 ( V_55 ) ;
V_44 = V_44 -> V_108 ;
V_2 = F_16 ( & V_44 -> V_55 ) ;
F_42 ( & V_44 -> V_55 . V_103 ) ;
V_55 = NULL ;
if ( V_102 & ( V_109 | V_110 | V_111 ) ) {
F_2 ( V_107 , & V_2 -> V_5 ) ;
F_3 () ;
F_7 ( V_2 ) ;
if ( V_102 & V_111 )
V_55 = F_23 ( V_44 , V_2 ) ;
if ( V_102 & V_109 )
F_28 ( V_44 , V_2 ) ;
if ( V_102 & V_110 )
F_35 ( V_44 , V_2 ) ;
}
F_43 ( & V_44 -> V_55 . V_103 ) ;
if ( V_55 )
F_44 ( V_55 ) ;
V_44 = V_44 -> V_108 ;
}
return V_112 ;
}
static T_3 unsigned char F_45 ( struct V_113 * V_55 )
{
struct V_1 T_1 * V_2 ;
unsigned char V_80 ;
V_2 = F_16 ( V_55 ) ;
V_80 = F_4 ( & V_2 -> V_5 ) ;
F_3 () ;
return V_80 ;
}
static unsigned int F_46 ( struct V_113 * V_55 )
{
unsigned long V_45 ;
unsigned char V_80 ;
unsigned int V_60 ;
F_47 ( & V_55 -> V_103 , V_45 ) ;
V_80 = F_45 ( V_55 ) ;
F_48 ( & V_55 -> V_103 , V_45 ) ;
if ( V_80 & V_89 )
V_60 = V_114 ;
else
V_60 = 0 ;
return V_60 ;
}
static unsigned int F_49 ( struct V_113 * V_55 )
{
unsigned char V_80 ;
unsigned int V_60 ;
V_80 = F_45 ( V_55 ) ;
V_60 = 0 ;
if ( V_80 & V_84 )
V_60 |= V_115 ;
if ( V_80 & V_81 )
V_60 |= V_116 ;
if ( V_80 & V_85 )
V_60 |= V_117 ;
return V_60 ;
}
static void F_50 ( struct V_113 * V_55 , unsigned int V_118 )
{
struct V_43 * V_44 =
F_51 ( V_55 , struct V_43 , V_55 ) ;
struct V_1 T_1 * V_2 = F_16 ( V_55 ) ;
unsigned char V_119 , V_120 ;
V_119 = V_120 = 0 ;
if ( V_118 & V_121 )
V_119 |= V_122 ;
else
V_120 |= V_122 ;
if ( V_118 & V_123 )
V_119 |= V_124 ;
else
V_120 |= V_124 ;
V_44 -> V_47 [ V_28 ] |= V_119 ;
V_44 -> V_47 [ V_28 ] &= ~ V_120 ;
F_5 ( V_2 , V_28 , V_44 -> V_47 [ V_28 ] ) ;
}
static void F_52 ( struct V_113 * V_55 )
{
struct V_43 * V_44 =
F_51 ( V_55 , struct V_43 , V_55 ) ;
V_44 -> V_45 |= V_91 ;
}
static void F_53 ( struct V_113 * V_55 )
{
struct V_43 * V_44 =
F_51 ( V_55 , struct V_43 , V_55 ) ;
struct V_1 T_1 * V_2 = F_16 ( V_55 ) ;
unsigned char V_80 ;
V_44 -> V_45 |= V_90 ;
V_44 -> V_45 &= ~ V_91 ;
V_80 = F_4 ( & V_2 -> V_5 ) ;
F_3 () ;
if ( ! ( V_80 & V_89 ) )
return;
if ( V_55 -> V_93 ) {
F_2 ( V_55 -> V_93 , & V_2 -> V_11 ) ;
F_3 () ;
F_7 ( V_2 ) ;
V_55 -> V_68 . V_94 ++ ;
V_55 -> V_93 = 0 ;
} else {
struct V_87 * V_88 = & V_55 -> V_64 -> V_88 ;
if ( F_37 ( V_88 ) )
return;
F_2 ( V_88 -> V_95 [ V_88 -> V_96 ] , & V_2 -> V_11 ) ;
F_3 () ;
F_7 ( V_2 ) ;
V_88 -> V_96 = ( V_88 -> V_96 + 1 ) & ( V_97 - 1 ) ;
V_55 -> V_68 . V_94 ++ ;
if ( F_39 ( V_88 ) < V_98 )
F_40 ( & V_44 -> V_55 ) ;
}
}
static void F_54 ( struct V_113 * V_55 )
{
struct V_43 * V_44 = F_55 ( V_55 ) ;
struct V_1 T_1 * V_2 ;
if ( F_29 ( V_44 ) )
return;
V_2 = F_16 ( V_55 ) ;
V_44 -> V_47 [ V_10 ] &= ~ V_21 ;
F_10 ( V_44 , V_2 ) ;
}
static void F_56 ( struct V_113 * V_55 )
{
struct V_43 * V_44 =
F_51 ( V_55 , struct V_43 , V_55 ) ;
struct V_1 T_1 * V_2 = F_16 ( V_55 ) ;
unsigned char V_125 ;
V_125 = V_44 -> V_47 [ V_37 ] | ( V_126 | V_127 | V_128 ) ;
if ( V_125 != V_44 -> V_47 [ V_37 ] ) {
V_44 -> V_47 [ V_37 ] = V_125 ;
F_5 ( V_2 , V_37 , V_44 -> V_47 [ V_37 ] & ~ V_38 ) ;
}
}
static void F_57 ( struct V_113 * V_55 , int V_129 )
{
struct V_43 * V_44 =
F_51 ( V_55 , struct V_43 , V_55 ) ;
struct V_1 T_1 * V_2 = F_16 ( V_55 ) ;
unsigned char V_119 , V_120 , V_125 ;
unsigned long V_45 ;
V_119 = V_120 = 0 ;
if ( V_129 )
V_119 |= V_130 ;
else
V_120 |= V_130 ;
F_47 ( & V_55 -> V_103 , V_45 ) ;
V_125 = ( V_44 -> V_47 [ V_28 ] | V_119 ) & ~ V_120 ;
if ( V_125 != V_44 -> V_47 [ V_28 ] ) {
V_44 -> V_47 [ V_28 ] = V_125 ;
F_5 ( V_2 , V_28 , V_44 -> V_47 [ V_28 ] ) ;
}
F_48 ( & V_55 -> V_103 , V_45 ) ;
}
static void F_58 ( struct V_43 * V_44 )
{
struct V_1 T_1 * V_2 ;
V_2 = F_16 ( & V_44 -> V_55 ) ;
V_44 -> V_83 = F_4 ( & V_2 -> V_5 ) ;
V_44 -> V_47 [ V_26 ] |= V_27 ;
V_44 -> V_47 [ V_28 ] |= V_29 ;
V_44 -> V_47 [ V_10 ] |= V_23 | V_131 | V_22 ;
F_10 ( V_44 , V_2 ) ;
}
static int F_59 ( struct V_113 * V_55 )
{
struct V_43 * V_44 = F_55 ( V_55 ) ;
unsigned long V_45 ;
if ( F_29 ( V_44 ) )
return 0 ;
F_47 ( & V_55 -> V_103 , V_45 ) ;
F_58 ( V_44 ) ;
F_48 ( & V_55 -> V_103 , V_45 ) ;
return 0 ;
}
static void F_60 ( struct V_113 * V_55 )
{
struct V_43 * V_44 = F_55 ( V_55 ) ;
struct V_1 T_1 * V_2 ;
unsigned long V_45 ;
if ( F_29 ( V_44 ) )
return;
F_47 ( & V_55 -> V_103 , V_45 ) ;
V_2 = F_16 ( V_55 ) ;
V_44 -> V_47 [ V_26 ] &= ~ V_27 ;
V_44 -> V_47 [ V_28 ] &= ~ V_29 ;
V_44 -> V_47 [ V_10 ] &= ~ ( V_23 | V_22 | V_21 ) ;
V_44 -> V_47 [ V_28 ] &= ~ V_130 ;
F_10 ( V_44 , V_2 ) ;
F_48 ( & V_55 -> V_103 , V_45 ) ;
}
static void
F_61 ( struct V_43 * V_44 , unsigned int V_49 ,
unsigned int V_132 , int V_50 )
{
V_44 -> V_47 [ V_25 ] = V_133 ;
V_44 -> V_47 [ V_34 ] = V_134 | V_135 ;
V_44 -> V_47 [ V_24 ] &= ~ V_136 ;
V_44 -> V_47 [ V_24 ] |= V_137 ;
V_44 -> V_47 [ V_35 ] = V_50 & 0xff ;
V_44 -> V_47 [ V_36 ] = ( V_50 >> 8 ) & 0xff ;
V_44 -> V_47 [ V_32 ] = V_138 | V_33 ;
V_44 -> V_47 [ V_26 ] &= ~ V_139 ;
V_44 -> V_47 [ V_28 ] &= ~ V_140 ;
switch ( V_49 & V_141 ) {
case V_142 :
V_44 -> V_47 [ V_26 ] |= V_143 ;
V_44 -> V_47 [ V_28 ] |= V_144 ;
V_44 -> V_66 = 0x1f ;
break;
case V_145 :
V_44 -> V_47 [ V_26 ] |= V_146 ;
V_44 -> V_47 [ V_28 ] |= V_147 ;
V_44 -> V_66 = 0x3f ;
break;
case V_148 :
V_44 -> V_47 [ V_26 ] |= V_149 ;
V_44 -> V_47 [ V_28 ] |= V_150 ;
V_44 -> V_66 = 0x7f ;
break;
case V_151 :
default:
V_44 -> V_47 [ V_26 ] |= V_152 ;
V_44 -> V_47 [ V_28 ] |= V_153 ;
V_44 -> V_66 = 0xff ;
break;
}
V_44 -> V_47 [ V_24 ] &= ~ 0x0c ;
if ( V_49 & V_154 )
V_44 -> V_47 [ V_24 ] |= V_155 ;
else
V_44 -> V_47 [ V_24 ] |= V_156 ;
if ( V_49 & V_157 )
V_44 -> V_47 [ V_24 ] |= V_158 ;
else
V_44 -> V_47 [ V_24 ] &= ~ V_158 ;
if ( ! ( V_49 & V_159 ) )
V_44 -> V_47 [ V_24 ] |= V_160 ;
else
V_44 -> V_47 [ V_24 ] &= ~ V_160 ;
V_44 -> V_55 . V_74 = V_13 ;
if ( V_132 & V_161 )
V_44 -> V_55 . V_74 |= V_14 | V_12 ;
if ( V_132 & ( V_162 | V_163 | V_164 ) )
V_44 -> V_55 . V_74 |= V_65 ;
V_44 -> V_55 . V_78 = 0 ;
if ( V_132 & V_165 )
V_44 -> V_55 . V_78 |= V_14 | V_12 ;
if ( V_132 & V_162 ) {
V_44 -> V_55 . V_78 |= V_65 ;
if ( V_132 & V_165 )
V_44 -> V_55 . V_78 |= V_13 ;
}
if ( ( V_49 & V_166 ) == 0 )
V_44 -> V_55 . V_78 = 0xff ;
}
static void
F_62 ( struct V_113 * V_55 , struct V_167 * V_168 ,
struct V_167 * V_169 )
{
struct V_43 * V_44 =
F_51 ( V_55 , struct V_43 , V_55 ) ;
unsigned long V_45 ;
int V_170 , V_50 ;
V_170 = F_63 ( V_55 , V_168 , V_169 , 1200 , 76800 ) ;
F_47 ( & V_44 -> V_55 . V_103 , V_45 ) ;
V_50 = F_15 ( V_170 , V_53 / V_54 ) ;
F_61 ( V_44 , V_168 -> V_171 , V_168 -> V_172 , V_50 ) ;
if ( F_64 ( & V_44 -> V_55 , V_168 -> V_171 ) )
V_44 -> V_45 |= V_173 ;
else
V_44 -> V_45 &= ~ V_173 ;
V_44 -> V_49 = V_168 -> V_171 ;
F_10 ( V_44 , F_16 ( V_55 ) ) ;
F_65 ( V_55 , V_168 -> V_171 , V_170 ) ;
F_48 ( & V_44 -> V_55 . V_103 , V_45 ) ;
}
static const char * F_66 ( struct V_113 * V_55 )
{
struct V_43 * V_44 = F_55 ( V_55 ) ;
return ( V_44 -> V_45 & V_174 ) ? L_1 : L_2 ;
}
static void F_67 ( struct V_113 * V_55 )
{
}
static int F_68 ( struct V_113 * V_55 )
{
return 0 ;
}
static void F_69 ( struct V_113 * V_55 , int V_45 )
{
}
static int F_70 ( struct V_113 * V_55 , struct V_175 * V_176 )
{
return - V_177 ;
}
static int F_71 ( struct V_113 * V_55 )
{
unsigned char V_56 , V_62 ;
struct V_43 * V_44 =
F_51 ( V_55 , struct V_43 , V_55 ) ;
struct V_1 T_1 * V_2
= F_16 ( & V_44 -> V_55 ) ;
V_62 = F_1 ( V_2 , V_10 ) ;
if ( V_62 & ( V_12 | V_13 | V_14 ) ) {
F_2 ( V_15 , & V_2 -> V_5 ) ;
F_3 () ;
F_7 ( V_2 ) ;
}
V_56 = F_4 ( & V_2 -> V_5 ) ;
F_3 () ;
if ( V_56 & V_65 )
V_62 |= V_65 ;
if ( ! ( V_56 & V_9 ) )
return V_178 ;
V_56 = F_4 ( & V_2 -> V_11 ) ;
F_3 () ;
V_56 &= V_44 -> V_66 ;
return V_56 ;
}
static void F_72 ( struct V_113 * V_55 ,
unsigned char V_56 )
{
struct V_43 * V_44 =
F_51 ( V_55 , struct V_43 , V_55 ) ;
F_73 ( & V_44 -> V_55 , V_56 ) ;
}
static int T_4 F_74 ( int V_179 )
{
struct V_43 * V_44 ;
unsigned long V_180 ;
int V_181 = V_179 * 2 ;
int V_7 ;
V_180 = V_181 * sizeof( struct V_43 ) ;
V_182 = F_75 ( V_180 , V_183 ) ;
if ( ! V_182 )
return - V_184 ;
for ( V_7 = 0 ; V_7 < V_181 ; V_7 ++ ) {
V_44 = & V_182 [ V_7 ] ;
F_76 ( & V_44 -> V_55 . V_103 ) ;
if ( V_7 == 0 )
V_185 = V_44 ;
if ( V_7 < V_181 - 1 )
V_44 -> V_108 = V_44 + 1 ;
else
V_44 -> V_108 = NULL ;
}
V_180 = V_179 * sizeof(struct V_186 T_1 * ) ;
V_187 = F_75 ( V_180 , V_183 ) ;
if ( ! V_187 ) {
F_77 ( V_182 ) ;
V_185 = NULL ;
return - V_184 ;
}
return 0 ;
}
static void F_78 ( void )
{
F_77 ( V_182 ) ;
V_185 = NULL ;
F_77 ( V_187 ) ;
}
static void F_73 ( struct V_113 * V_55 , int V_56 )
{
struct V_1 T_1 * V_2 = F_16 ( V_55 ) ;
int V_188 = V_189 ;
do {
unsigned char V_190 = F_4 ( & V_2 -> V_5 ) ;
if ( V_190 & V_89 ) {
F_3 () ;
break;
}
F_9 ( 5 ) ;
} while ( -- V_188 );
F_2 ( V_56 , & V_2 -> V_11 ) ;
F_3 () ;
F_7 ( V_2 ) ;
}
static int F_79 ( struct V_59 * V_59 , unsigned char V_56 )
{
struct V_43 * V_44 = V_59 -> V_191 ;
unsigned long V_45 ;
F_47 ( & V_192 , V_45 ) ;
F_73 ( & V_44 -> V_55 , V_56 ) ;
F_48 ( & V_192 , V_45 ) ;
return 0 ;
}
static int F_80 ( struct V_59 * V_59 )
{
struct V_43 * V_44 = V_59 -> V_191 ;
unsigned long V_45 ;
int V_60 ;
F_47 ( & V_192 , V_45 ) ;
if ( ! V_44 -> V_58 ) {
V_44 -> V_58 = 1 ;
V_60 = 0 ;
} else
V_60 = - V_193 ;
F_48 ( & V_192 , V_45 ) ;
return V_60 ;
}
static void F_81 ( struct V_59 * V_59 )
{
struct V_43 * V_44 = V_59 -> V_191 ;
unsigned long V_45 ;
F_47 ( & V_192 , V_45 ) ;
V_44 -> V_58 = 0 ;
F_48 ( & V_192 , V_45 ) ;
}
static void
F_82 ( struct V_194 * V_195 , const char * V_196 , unsigned int V_197 )
{
struct V_43 * V_44 = & V_182 [ V_195 -> V_198 ] ;
unsigned long V_45 ;
int V_199 = 1 ;
if ( V_44 -> V_55 . V_200 || V_201 )
V_199 = F_83 ( & V_44 -> V_55 . V_103 , V_45 ) ;
else
F_47 ( & V_44 -> V_55 . V_103 , V_45 ) ;
F_84 ( & V_44 -> V_55 , V_196 , V_197 , F_73 ) ;
F_9 ( 2 ) ;
if ( V_199 )
F_48 ( & V_44 -> V_55 . V_103 , V_45 ) ;
}
static int T_4 F_85 ( struct V_194 * V_195 , char * V_202 )
{
struct V_43 * V_44 = & V_182 [ V_195 -> V_198 ] ;
unsigned long V_45 ;
int V_170 , V_50 ;
if ( V_44 -> V_55 . type != V_203 )
return - 1 ;
F_86 ( V_204 L_3 ,
( V_205 . V_206 - 64 ) + V_195 -> V_198 , V_195 -> V_198 ) ;
F_87 ( V_195 , V_44 -> V_55 . V_207 -> V_208 ) ;
switch ( V_195 -> V_49 & V_52 ) {
case V_209 : V_170 = 150 ; break;
case V_210 : V_170 = 300 ; break;
case V_211 : V_170 = 600 ; break;
case V_212 : V_170 = 1200 ; break;
case V_213 : V_170 = 2400 ; break;
case V_214 : V_170 = 4800 ; break;
default: case V_215 : V_170 = 9600 ; break;
case V_216 : V_170 = 19200 ; break;
case V_217 : V_170 = 38400 ; break;
}
V_50 = F_15 ( V_170 , V_53 / V_54 ) ;
F_47 ( & V_44 -> V_55 . V_103 , V_45 ) ;
V_44 -> V_47 [ V_37 ] |= V_218 ;
F_61 ( V_44 , V_195 -> V_49 , 0 , V_50 ) ;
F_50 ( & V_44 -> V_55 , V_123 | V_121 ) ;
F_58 ( V_44 ) ;
F_48 ( & V_44 -> V_55 . V_103 , V_45 ) ;
return 0 ;
}
static inline struct V_194 * F_88 ( void )
{
return & V_219 ;
}
static void F_89 ( struct V_43 * V_44 )
{
int V_170 , V_50 ;
if ( V_44 -> V_45 & V_220 ) {
V_44 -> V_49 = V_212 | V_151 | V_221 | V_166 ;
V_170 = 1200 ;
} else {
V_44 -> V_49 = V_214 | V_151 | V_221 | V_166 ;
V_170 = 4800 ;
}
V_44 -> V_47 [ V_37 ] |= V_218 ;
V_50 = F_15 ( V_170 , V_53 / V_54 ) ;
F_61 ( V_44 , V_44 -> V_49 , 0 , V_50 ) ;
F_50 ( & V_44 -> V_55 , V_123 | V_121 ) ;
F_58 ( V_44 ) ;
}
static void F_90 ( struct V_43 * V_44 )
{
struct V_59 * V_59 = & V_44 -> V_59 ;
V_59 -> V_191 = V_44 ;
V_59 -> V_222 . type = V_223 ;
if ( V_44 -> V_45 & V_220 ) {
V_59 -> V_222 . V_224 = V_225 ;
F_91 ( V_59 -> V_226 , L_4 , sizeof( V_59 -> V_226 ) ) ;
} else {
V_59 -> V_222 . V_224 = V_227 ;
V_59 -> V_222 . V_228 = 1 ;
F_91 ( V_59 -> V_226 , L_5 , sizeof( V_59 -> V_226 ) ) ;
}
F_91 ( V_59 -> V_229 ,
( ( V_44 -> V_45 & V_220 ) ?
L_6 : L_7 ) ,
sizeof( V_59 -> V_229 ) ) ;
V_59 -> V_230 = F_79 ;
V_59 -> V_231 = F_80 ;
V_59 -> V_232 = F_81 ;
V_59 -> V_207 . V_233 = V_44 -> V_55 . V_207 ;
F_92 ( V_59 ) ;
}
static void F_93 ( struct V_43 * V_44 )
{
struct V_1 T_1 * V_2 ;
unsigned long V_45 ;
int V_170 , V_50 ;
V_2 = F_16 ( & V_44 -> V_55 ) ;
F_47 ( & V_44 -> V_55 . V_103 , V_45 ) ;
if ( F_94 ( V_44 ) ) {
F_5 ( V_2 , V_234 , V_235 ) ;
F_95 () ;
( void ) F_1 ( V_2 , V_41 ) ;
}
if ( V_44 -> V_45 & ( V_220 |
V_236 ) ) {
V_44 -> V_47 [ V_10 ] = V_23 | V_131 | V_22 ;
V_44 -> V_47 [ V_24 ] = V_160 | V_137 | V_156 ;
V_44 -> V_47 [ V_26 ] = V_27 | V_152 ;
V_44 -> V_47 [ V_28 ] = V_29 | V_153 ;
V_44 -> V_47 [ V_30 ] = 0x00 ;
V_44 -> V_47 [ V_31 ] = 0x7E ;
V_44 -> V_47 [ V_234 ] = V_237 ;
V_44 -> V_47 [ V_40 ] = 0x00 ;
F_89 ( V_44 ) ;
if ( V_44 -> V_45 & V_238 )
V_44 -> V_47 [ V_234 ] |= V_239 ;
F_5 ( V_2 , V_234 , V_44 -> V_47 [ V_234 ] ) ;
} else {
V_44 -> V_66 = 0xff ;
V_44 -> V_47 [ V_10 ] = V_23 | V_131 | V_22 ;
V_44 -> V_47 [ V_24 ] = V_160 | V_137 | V_156 ;
V_44 -> V_47 [ V_26 ] = V_27 | V_152 ;
V_44 -> V_47 [ V_28 ] = V_29 | V_153 ;
V_44 -> V_47 [ V_30 ] = 0x00 ;
V_44 -> V_47 [ V_31 ] = 0x7E ;
V_44 -> V_47 [ V_234 ] = V_237 ;
V_44 -> V_47 [ V_25 ] = V_133 ;
V_44 -> V_47 [ V_34 ] = V_134 | V_135 ;
V_170 = 9600 ;
V_50 = F_15 ( V_170 , V_53 / V_54 ) ;
V_44 -> V_47 [ V_35 ] = ( V_50 & 0xff ) ;
V_44 -> V_47 [ V_36 ] = ( V_50 >> 8 ) & 0xff ;
V_44 -> V_47 [ V_32 ] = V_138 | V_33 ;
V_44 -> V_47 [ V_37 ] = V_39 ;
V_44 -> V_47 [ V_40 ] = V_240 | V_241 ;
if ( F_8 ( V_2 , V_44 -> V_47 ) ) {
V_44 -> V_45 |= V_174 ;
}
if ( V_44 -> V_45 & V_238 )
V_44 -> V_47 [ V_234 ] |= V_239 ;
F_5 ( V_2 , V_234 , V_44 -> V_47 [ V_234 ] ) ;
}
F_48 ( & V_44 -> V_55 . V_103 , V_45 ) ;
#ifdef F_19
if ( V_44 -> V_45 & ( V_220 |
V_236 ) )
F_90 ( V_44 ) ;
#endif
}
static int F_96 ( struct V_242 * V_243 )
{
static int V_244 , V_245 ;
int V_246 ;
struct V_43 * V_44 ;
struct V_186 T_1 * V_247 ;
int V_248 = 0 ;
int V_249 ;
if ( F_97 ( V_243 -> V_207 . V_208 , L_8 , NULL ) )
V_248 = 1 ;
if ( V_248 )
V_246 = V_250 + V_244 ;
else
V_246 = V_245 ;
V_187 [ V_246 ] = F_98 ( & V_243 -> V_251 [ 0 ] , 0 ,
sizeof( struct V_186 ) ,
L_2 ) ;
if ( ! V_187 [ V_246 ] )
return - V_184 ;
V_247 = V_187 [ V_246 ] ;
if ( ! V_252 )
V_252 = V_243 -> V_253 . V_254 [ 0 ] ;
V_44 = & V_182 [ V_246 * 2 ] ;
V_44 [ 0 ] . V_55 . V_255 = V_243 -> V_251 [ 0 ] . V_256 + 0x00 ;
V_44 [ 0 ] . V_55 . V_257 = ( void T_1 * ) & V_247 -> V_258 ;
V_44 [ 0 ] . V_55 . V_259 = V_260 ;
V_44 [ 0 ] . V_55 . V_100 = V_243 -> V_253 . V_254 [ 0 ] ;
V_44 [ 0 ] . V_55 . V_261 = V_53 ;
V_44 [ 0 ] . V_55 . V_262 = 1 ;
V_44 [ 0 ] . V_55 . V_263 = & V_264 ;
V_44 [ 0 ] . V_55 . type = V_203 ;
V_44 [ 0 ] . V_55 . V_45 = 0 ;
V_44 [ 0 ] . V_55 . line = ( V_246 * 2 ) + 0 ;
V_44 [ 0 ] . V_55 . V_207 = & V_243 -> V_207 ;
V_44 [ 0 ] . V_45 |= V_265 ;
if ( V_248 )
V_44 [ 0 ] . V_45 |= V_220 ;
F_93 ( & V_44 [ 0 ] ) ;
V_44 [ 1 ] . V_55 . V_255 = V_243 -> V_251 [ 0 ] . V_256 + 0x04 ;
V_44 [ 1 ] . V_55 . V_257 = ( void T_1 * ) & V_247 -> V_266 ;
V_44 [ 1 ] . V_55 . V_259 = V_260 ;
V_44 [ 1 ] . V_55 . V_100 = V_243 -> V_253 . V_254 [ 0 ] ;
V_44 [ 1 ] . V_55 . V_261 = V_53 ;
V_44 [ 1 ] . V_55 . V_262 = 1 ;
V_44 [ 1 ] . V_55 . V_263 = & V_264 ;
V_44 [ 1 ] . V_55 . type = V_203 ;
V_44 [ 1 ] . V_55 . V_45 = 0 ;
V_44 [ 1 ] . V_55 . line = ( V_246 * 2 ) + 1 ;
V_44 [ 1 ] . V_55 . V_207 = & V_243 -> V_207 ;
V_44 [ 1 ] . V_45 |= 0 ;
if ( V_248 )
V_44 [ 1 ] . V_45 |= V_236 ;
F_93 ( & V_44 [ 1 ] ) ;
if ( ! V_248 ) {
if ( F_99 ( F_88 () , V_243 -> V_207 . V_208 ,
& V_205 , V_44 [ 0 ] . V_55 . line ,
false ) )
V_44 -> V_45 |= V_267 ;
V_249 = F_100 ( & V_205 , & V_44 [ 0 ] . V_55 ) ;
if ( V_249 ) {
F_101 ( & V_243 -> V_251 [ 0 ] ,
V_247 , sizeof( struct V_186 ) ) ;
return V_249 ;
}
if ( F_99 ( F_88 () , V_243 -> V_207 . V_208 ,
& V_205 , V_44 [ 1 ] . V_55 . line ,
false ) )
V_44 -> V_45 |= V_267 ;
V_249 = F_100 ( & V_205 , & V_44 [ 1 ] . V_55 ) ;
if ( V_249 ) {
F_102 ( & V_205 , & V_44 [ 0 ] . V_55 ) ;
F_101 ( & V_243 -> V_251 [ 0 ] ,
V_247 , sizeof( struct V_186 ) ) ;
return V_249 ;
}
V_245 ++ ;
} else {
F_86 ( V_204 L_9
L_10 ,
F_103 ( & V_243 -> V_207 ) ,
( unsigned long long ) V_44 [ 0 ] . V_55 . V_255 ,
V_243 -> V_253 . V_254 [ 0 ] , F_66 ( & V_44 [ 0 ] . V_55 ) ) ;
F_86 ( V_204 L_11
L_10 ,
F_103 ( & V_243 -> V_207 ) ,
( unsigned long long ) V_44 [ 1 ] . V_55 . V_255 ,
V_243 -> V_253 . V_254 [ 0 ] , F_66 ( & V_44 [ 1 ] . V_55 ) ) ;
V_244 ++ ;
}
F_104 ( V_243 , & V_44 [ 0 ] ) ;
return 0 ;
}
static void F_105 ( struct V_43 * V_44 )
{
if ( F_18 ( V_44 ) || F_21 ( V_44 ) ) {
#ifdef F_19
F_106 ( & V_44 -> V_59 ) ;
#endif
} else
F_102 ( & V_205 , & V_44 -> V_55 ) ;
}
static int F_107 ( struct V_242 * V_243 )
{
struct V_43 * V_44 = F_108 ( V_243 ) ;
struct V_186 T_1 * V_16 ;
F_105 ( & V_44 [ 0 ] ) ;
F_105 ( & V_44 [ 1 ] ) ;
V_16 = V_187 [ V_44 [ 0 ] . V_55 . line / 2 ] ;
F_101 ( & V_243 -> V_251 [ 0 ] , V_16 , sizeof( struct V_186 ) ) ;
return 0 ;
}
static int T_4 F_109 ( void )
{
struct V_268 * V_269 ;
int V_249 ;
int V_270 = 0 ;
int V_179 = 0 ;
F_110 (dp, L_2 ) {
V_179 ++ ;
if ( F_97 ( V_269 , L_8 , NULL ) )
V_270 ++ ;
}
if ( V_179 ) {
V_249 = F_74 ( V_179 ) ;
if ( V_249 )
goto V_271;
V_250 = V_179 - V_270 ;
V_249 = F_111 ( & V_205 ,
V_250 * 2 ) ;
if ( V_249 )
goto V_272;
}
V_249 = F_112 ( & V_273 ) ;
if ( V_249 )
goto V_274;
if ( V_252 ) {
struct V_43 * V_44 = V_185 ;
V_249 = F_113 ( V_252 , F_41 , V_275 ,
L_2 , V_185 ) ;
if ( V_249 )
goto V_276;
while ( V_44 ) {
struct V_1 T_1 * V_2 ;
V_2 = F_16 ( & V_44 -> V_55 ) ;
V_44 -> V_45 |= V_238 ;
V_44 -> V_47 [ V_234 ] |= V_239 ;
F_5 ( V_2 , V_234 , V_44 -> V_47 [ V_234 ] ) ;
V_44 = V_44 -> V_108 ;
}
}
V_271:
return V_249 ;
V_276:
F_114 ( & V_273 ) ;
V_274:
if ( V_179 ) {
F_115 ( & V_205 , V_179 ) ;
V_205 . V_277 = NULL ;
}
V_272:
F_78 () ;
goto V_271;
}
static void T_5 F_116 ( void )
{
F_114 ( & V_273 ) ;
if ( V_252 ) {
struct V_43 * V_44 = V_185 ;
while ( V_44 ) {
struct V_1 T_1 * V_2 ;
V_2 = F_16 ( & V_44 -> V_55 ) ;
V_44 -> V_45 &= ~ V_238 ;
V_44 -> V_47 [ V_234 ] &= ~ V_239 ;
F_5 ( V_2 , V_234 , V_44 -> V_47 [ V_234 ] ) ;
V_44 = V_44 -> V_108 ;
}
F_117 ( V_252 , V_185 ) ;
V_252 = 0 ;
}
if ( V_205 . V_278 ) {
F_115 ( & V_205 , V_205 . V_278 ) ;
F_78 () ;
}
}
