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
} ;
}
}
static struct V_61 *
F_23 ( struct V_43 * V_44 ,
struct V_1 T_1 * V_2 )
{
struct V_61 * V_62 ;
unsigned char V_56 , V_63 , V_64 ;
V_62 = NULL ;
if ( V_44 -> V_55 . V_65 != NULL &&
V_44 -> V_55 . V_65 -> V_55 . V_62 != NULL )
V_62 = V_44 -> V_55 . V_65 -> V_55 . V_62 ;
for (; ; ) {
V_63 = F_1 ( V_2 , V_10 ) ;
if ( V_63 & ( V_12 | V_13 | V_14 ) ) {
F_2 ( V_15 , & V_2 -> V_5 ) ;
F_3 () ;
F_7 ( V_2 ) ;
}
V_56 = F_4 ( & V_2 -> V_5 ) ;
F_3 () ;
if ( V_56 & V_66 )
V_63 |= V_66 ;
if ( ! ( V_56 & V_9 ) )
break;
V_56 = F_4 ( & V_2 -> V_11 ) ;
F_3 () ;
V_56 &= V_44 -> V_67 ;
if ( F_24 ( F_18 ( V_44 ) ) || F_24 ( F_21 ( V_44 ) ) ) {
F_17 ( V_44 , V_56 , 0 ) ;
continue;
}
if ( V_62 == NULL ) {
F_25 ( & V_44 -> V_55 , V_56 ) ;
continue;
}
V_64 = V_68 ;
V_44 -> V_55 . V_69 . V_70 ++ ;
if ( V_63 & ( V_66 | V_12 | V_13 | V_14 ) ) {
if ( V_63 & V_66 ) {
V_63 &= ~ ( V_12 | V_14 ) ;
V_44 -> V_55 . V_69 . V_71 ++ ;
if ( F_26 ( & V_44 -> V_55 ) )
continue;
}
else if ( V_63 & V_12 )
V_44 -> V_55 . V_69 . V_72 ++ ;
else if ( V_63 & V_14 )
V_44 -> V_55 . V_69 . V_73 ++ ;
if ( V_63 & V_13 )
V_44 -> V_55 . V_69 . V_74 ++ ;
V_63 &= V_44 -> V_55 . V_75 ;
if ( V_63 & V_66 )
V_64 = V_76 ;
else if ( V_63 & V_12 )
V_64 = V_77 ;
else if ( V_63 & V_14 )
V_64 = V_78 ;
}
if ( F_25 ( & V_44 -> V_55 , V_56 ) )
continue;
if ( V_44 -> V_55 . V_79 == 0xff ||
( V_63 & V_44 -> V_55 . V_79 ) == 0 ) {
F_27 ( V_62 , V_56 , V_64 ) ;
}
if ( V_63 & V_13 )
F_27 ( V_62 , 0 , V_80 ) ;
}
return V_62 ;
}
static void F_28 ( struct V_43 * V_44 ,
struct V_1 T_1 * V_2 )
{
unsigned char V_81 ;
V_81 = F_4 ( & V_2 -> V_5 ) ;
F_3 () ;
F_2 ( V_42 , & V_2 -> V_5 ) ;
F_3 () ;
F_7 ( V_2 ) ;
if ( V_81 & V_66 ) {
if ( F_21 ( V_44 ) )
F_17 ( V_44 , 0 , 1 ) ;
if ( F_29 ( V_44 ) ) {
while ( 1 ) {
V_81 = F_4 ( & V_2 -> V_5 ) ;
F_3 () ;
if ( ! ( V_81 & V_66 ) )
break;
}
F_30 () ;
return;
}
}
if ( F_31 ( V_44 ) ) {
if ( V_81 & V_82 )
V_44 -> V_55 . V_69 . V_83 ++ ;
if ( ( V_81 ^ V_44 -> V_84 ) ^ V_85 )
F_32 ( & V_44 -> V_55 ,
( V_81 & V_85 ) ) ;
if ( ( V_81 ^ V_44 -> V_84 ) ^ V_86 )
F_33 ( & V_44 -> V_55 ,
( V_81 & V_86 ) ) ;
F_34 ( & V_44 -> V_55 . V_65 -> V_55 . V_87 ) ;
}
V_44 -> V_84 = V_81 ;
}
static void F_35 ( struct V_43 * V_44 ,
struct V_1 T_1 * V_2 )
{
struct V_88 * V_89 ;
if ( F_29 ( V_44 ) ) {
unsigned char V_81 = F_4 ( & V_2 -> V_5 ) ;
F_3 () ;
if ( ! ( V_81 & V_90 ) )
return;
}
V_44 -> V_45 &= ~ V_91 ;
if ( F_11 ( V_44 ) ) {
F_8 ( V_2 , V_44 -> V_47 ) ;
V_44 -> V_45 &= ~ V_46 ;
}
if ( F_36 ( V_44 ) ) {
V_44 -> V_45 &= ~ V_92 ;
goto V_93;
}
if ( V_44 -> V_55 . V_94 ) {
V_44 -> V_45 |= V_91 ;
F_2 ( V_44 -> V_55 . V_94 , & V_2 -> V_11 ) ;
F_3 () ;
F_7 ( V_2 ) ;
V_44 -> V_55 . V_69 . V_95 ++ ;
V_44 -> V_55 . V_94 = 0 ;
return;
}
if ( V_44 -> V_55 . V_65 == NULL )
goto V_93;
V_89 = & V_44 -> V_55 . V_65 -> V_89 ;
if ( F_37 ( V_89 ) )
goto V_93;
if ( F_38 ( & V_44 -> V_55 ) )
goto V_93;
V_44 -> V_45 |= V_91 ;
F_2 ( V_89 -> V_96 [ V_89 -> V_97 ] , & V_2 -> V_11 ) ;
F_3 () ;
F_7 ( V_2 ) ;
V_89 -> V_97 = ( V_89 -> V_97 + 1 ) & ( V_98 - 1 ) ;
V_44 -> V_55 . V_69 . V_95 ++ ;
if ( F_39 ( V_89 ) < V_99 )
F_40 ( & V_44 -> V_55 ) ;
return;
V_93:
F_2 ( V_100 , & V_2 -> V_5 ) ;
F_3 () ;
F_7 ( V_2 ) ;
}
static T_2 F_41 ( int V_101 , void * V_102 )
{
struct V_43 * V_44 = V_102 ;
while ( V_44 ) {
struct V_1 T_1 * V_2
= F_16 ( & V_44 -> V_55 ) ;
struct V_61 * V_62 ;
unsigned char V_103 ;
F_42 ( & V_44 -> V_55 . V_104 ) ;
V_103 = F_1 ( V_2 , V_26 ) ;
V_62 = NULL ;
if ( V_103 & ( V_105 | V_106 | V_107 ) ) {
F_2 ( V_108 , & V_2 -> V_5 ) ;
F_3 () ;
F_7 ( V_2 ) ;
if ( V_103 & V_107 )
V_62 = F_23 ( V_44 , V_2 ) ;
if ( V_103 & V_105 )
F_28 ( V_44 , V_2 ) ;
if ( V_103 & V_106 )
F_35 ( V_44 , V_2 ) ;
}
F_43 ( & V_44 -> V_55 . V_104 ) ;
if ( V_62 )
F_44 ( V_62 ) ;
V_44 = V_44 -> V_109 ;
V_2 = F_16 ( & V_44 -> V_55 ) ;
F_42 ( & V_44 -> V_55 . V_104 ) ;
V_62 = NULL ;
if ( V_103 & ( V_110 | V_111 | V_112 ) ) {
F_2 ( V_108 , & V_2 -> V_5 ) ;
F_3 () ;
F_7 ( V_2 ) ;
if ( V_103 & V_112 )
V_62 = F_23 ( V_44 , V_2 ) ;
if ( V_103 & V_110 )
F_28 ( V_44 , V_2 ) ;
if ( V_103 & V_111 )
F_35 ( V_44 , V_2 ) ;
}
F_43 ( & V_44 -> V_55 . V_104 ) ;
if ( V_62 )
F_44 ( V_62 ) ;
V_44 = V_44 -> V_109 ;
}
return V_113 ;
}
static T_3 unsigned char F_45 ( struct V_114 * V_55 )
{
struct V_1 T_1 * V_2 ;
unsigned char V_81 ;
V_2 = F_16 ( V_55 ) ;
V_81 = F_4 ( & V_2 -> V_5 ) ;
F_3 () ;
return V_81 ;
}
static unsigned int F_46 ( struct V_114 * V_55 )
{
unsigned long V_45 ;
unsigned char V_81 ;
unsigned int V_60 ;
F_47 ( & V_55 -> V_104 , V_45 ) ;
V_81 = F_45 ( V_55 ) ;
F_48 ( & V_55 -> V_104 , V_45 ) ;
if ( V_81 & V_90 )
V_60 = V_115 ;
else
V_60 = 0 ;
return V_60 ;
}
static unsigned int F_49 ( struct V_114 * V_55 )
{
unsigned char V_81 ;
unsigned int V_60 ;
V_81 = F_45 ( V_55 ) ;
V_60 = 0 ;
if ( V_81 & V_85 )
V_60 |= V_116 ;
if ( V_81 & V_82 )
V_60 |= V_117 ;
if ( V_81 & V_86 )
V_60 |= V_118 ;
return V_60 ;
}
static void F_50 ( struct V_114 * V_55 , unsigned int V_119 )
{
struct V_43 * V_44 = (struct V_43 * ) V_55 ;
struct V_1 T_1 * V_2 = F_16 ( V_55 ) ;
unsigned char V_120 , V_121 ;
V_120 = V_121 = 0 ;
if ( V_119 & V_122 )
V_120 |= V_123 ;
else
V_121 |= V_123 ;
if ( V_119 & V_124 )
V_120 |= V_125 ;
else
V_121 |= V_125 ;
V_44 -> V_47 [ V_28 ] |= V_120 ;
V_44 -> V_47 [ V_28 ] &= ~ V_121 ;
F_5 ( V_2 , V_28 , V_44 -> V_47 [ V_28 ] ) ;
}
static void F_51 ( struct V_114 * V_55 )
{
struct V_43 * V_44 = (struct V_43 * ) V_55 ;
V_44 -> V_45 |= V_92 ;
}
static void F_52 ( struct V_114 * V_55 )
{
struct V_43 * V_44 = (struct V_43 * ) V_55 ;
struct V_1 T_1 * V_2 = F_16 ( V_55 ) ;
unsigned char V_81 ;
V_44 -> V_45 |= V_91 ;
V_44 -> V_45 &= ~ V_92 ;
V_81 = F_4 ( & V_2 -> V_5 ) ;
F_3 () ;
if ( ! ( V_81 & V_90 ) )
return;
if ( V_55 -> V_94 ) {
F_2 ( V_55 -> V_94 , & V_2 -> V_11 ) ;
F_3 () ;
F_7 ( V_2 ) ;
V_55 -> V_69 . V_95 ++ ;
V_55 -> V_94 = 0 ;
} else {
struct V_88 * V_89 = & V_55 -> V_65 -> V_89 ;
F_2 ( V_89 -> V_96 [ V_89 -> V_97 ] , & V_2 -> V_11 ) ;
F_3 () ;
F_7 ( V_2 ) ;
V_89 -> V_97 = ( V_89 -> V_97 + 1 ) & ( V_98 - 1 ) ;
V_55 -> V_69 . V_95 ++ ;
if ( F_39 ( V_89 ) < V_99 )
F_40 ( & V_44 -> V_55 ) ;
}
}
static void F_53 ( struct V_114 * V_55 )
{
struct V_43 * V_44 = F_54 ( V_55 ) ;
struct V_1 T_1 * V_2 ;
if ( F_29 ( V_44 ) )
return;
V_2 = F_16 ( V_55 ) ;
V_44 -> V_47 [ V_10 ] &= ~ V_21 ;
F_10 ( V_44 , V_2 ) ;
}
static void F_55 ( struct V_114 * V_55 )
{
struct V_43 * V_44 = (struct V_43 * ) V_55 ;
struct V_1 T_1 * V_2 = F_16 ( V_55 ) ;
unsigned char V_126 ;
V_126 = V_44 -> V_47 [ V_37 ] | ( V_127 | V_128 | V_129 ) ;
if ( V_126 != V_44 -> V_47 [ V_37 ] ) {
V_44 -> V_47 [ V_37 ] = V_126 ;
F_5 ( V_2 , V_37 , V_44 -> V_47 [ V_37 ] & ~ V_38 ) ;
}
}
static void F_56 ( struct V_114 * V_55 , int V_130 )
{
struct V_43 * V_44 = (struct V_43 * ) V_55 ;
struct V_1 T_1 * V_2 = F_16 ( V_55 ) ;
unsigned char V_120 , V_121 , V_126 ;
unsigned long V_45 ;
V_120 = V_121 = 0 ;
if ( V_130 )
V_120 |= V_131 ;
else
V_121 |= V_131 ;
F_47 ( & V_55 -> V_104 , V_45 ) ;
V_126 = ( V_44 -> V_47 [ V_28 ] | V_120 ) & ~ V_121 ;
if ( V_126 != V_44 -> V_47 [ V_28 ] ) {
V_44 -> V_47 [ V_28 ] = V_126 ;
F_5 ( V_2 , V_28 , V_44 -> V_47 [ V_28 ] ) ;
}
F_48 ( & V_55 -> V_104 , V_45 ) ;
}
static void F_57 ( struct V_43 * V_44 )
{
struct V_1 T_1 * V_2 ;
V_2 = F_16 ( & V_44 -> V_55 ) ;
V_44 -> V_84 = F_4 ( & V_2 -> V_5 ) ;
V_44 -> V_47 [ V_26 ] |= V_27 ;
V_44 -> V_47 [ V_28 ] |= V_29 ;
V_44 -> V_47 [ V_10 ] |= V_23 | V_132 | V_22 ;
F_10 ( V_44 , V_2 ) ;
}
static int F_58 ( struct V_114 * V_55 )
{
struct V_43 * V_44 = F_54 ( V_55 ) ;
unsigned long V_45 ;
if ( F_29 ( V_44 ) )
return 0 ;
F_47 ( & V_55 -> V_104 , V_45 ) ;
F_57 ( V_44 ) ;
F_48 ( & V_55 -> V_104 , V_45 ) ;
return 0 ;
}
static void F_59 ( struct V_114 * V_55 )
{
struct V_43 * V_44 = F_54 ( V_55 ) ;
struct V_1 T_1 * V_2 ;
unsigned long V_45 ;
if ( F_29 ( V_44 ) )
return;
F_47 ( & V_55 -> V_104 , V_45 ) ;
V_2 = F_16 ( V_55 ) ;
V_44 -> V_47 [ V_26 ] &= ~ V_27 ;
V_44 -> V_47 [ V_28 ] &= ~ V_29 ;
V_44 -> V_47 [ V_10 ] &= ~ ( V_23 | V_22 | V_21 ) ;
V_44 -> V_47 [ V_28 ] &= ~ V_131 ;
F_10 ( V_44 , V_2 ) ;
F_48 ( & V_55 -> V_104 , V_45 ) ;
}
static void
F_60 ( struct V_43 * V_44 , unsigned int V_49 ,
unsigned int V_133 , int V_50 )
{
V_44 -> V_47 [ V_25 ] = V_134 ;
V_44 -> V_47 [ V_34 ] = V_135 | V_136 ;
V_44 -> V_47 [ V_24 ] &= ~ V_137 ;
V_44 -> V_47 [ V_24 ] |= V_138 ;
V_44 -> V_47 [ V_35 ] = V_50 & 0xff ;
V_44 -> V_47 [ V_36 ] = ( V_50 >> 8 ) & 0xff ;
V_44 -> V_47 [ V_32 ] = V_139 | V_33 ;
V_44 -> V_47 [ V_26 ] &= ~ V_140 ;
V_44 -> V_47 [ V_28 ] &= ~ V_141 ;
switch ( V_49 & V_142 ) {
case V_143 :
V_44 -> V_47 [ V_26 ] |= V_144 ;
V_44 -> V_47 [ V_28 ] |= V_145 ;
V_44 -> V_67 = 0x1f ;
break;
case V_146 :
V_44 -> V_47 [ V_26 ] |= V_147 ;
V_44 -> V_47 [ V_28 ] |= V_148 ;
V_44 -> V_67 = 0x3f ;
break;
case V_149 :
V_44 -> V_47 [ V_26 ] |= V_150 ;
V_44 -> V_47 [ V_28 ] |= V_151 ;
V_44 -> V_67 = 0x7f ;
break;
case V_152 :
default:
V_44 -> V_47 [ V_26 ] |= V_153 ;
V_44 -> V_47 [ V_28 ] |= V_154 ;
V_44 -> V_67 = 0xff ;
break;
} ;
V_44 -> V_47 [ V_24 ] &= ~ 0x0c ;
if ( V_49 & V_155 )
V_44 -> V_47 [ V_24 ] |= V_156 ;
else
V_44 -> V_47 [ V_24 ] |= V_157 ;
if ( V_49 & V_158 )
V_44 -> V_47 [ V_24 ] |= V_159 ;
else
V_44 -> V_47 [ V_24 ] &= ~ V_159 ;
if ( ! ( V_49 & V_160 ) )
V_44 -> V_47 [ V_24 ] |= V_161 ;
else
V_44 -> V_47 [ V_24 ] &= ~ V_161 ;
V_44 -> V_55 . V_75 = V_13 ;
if ( V_133 & V_162 )
V_44 -> V_55 . V_75 |= V_14 | V_12 ;
if ( V_133 & ( V_163 | V_164 ) )
V_44 -> V_55 . V_75 |= V_66 ;
V_44 -> V_55 . V_79 = 0 ;
if ( V_133 & V_165 )
V_44 -> V_55 . V_79 |= V_14 | V_12 ;
if ( V_133 & V_166 ) {
V_44 -> V_55 . V_79 |= V_66 ;
if ( V_133 & V_165 )
V_44 -> V_55 . V_79 |= V_13 ;
}
if ( ( V_49 & V_167 ) == 0 )
V_44 -> V_55 . V_79 = 0xff ;
}
static void
F_61 ( struct V_114 * V_55 , struct V_168 * V_169 ,
struct V_168 * V_170 )
{
struct V_43 * V_44 = (struct V_43 * ) V_55 ;
unsigned long V_45 ;
int V_171 , V_50 ;
V_171 = F_62 ( V_55 , V_169 , V_170 , 1200 , 76800 ) ;
F_47 ( & V_44 -> V_55 . V_104 , V_45 ) ;
V_50 = F_15 ( V_171 , V_53 / V_54 ) ;
F_60 ( V_44 , V_169 -> V_172 , V_169 -> V_173 , V_50 ) ;
if ( F_63 ( & V_44 -> V_55 , V_169 -> V_172 ) )
V_44 -> V_45 |= V_174 ;
else
V_44 -> V_45 &= ~ V_174 ;
V_44 -> V_49 = V_169 -> V_172 ;
F_10 ( V_44 , F_16 ( V_55 ) ) ;
F_64 ( V_55 , V_169 -> V_172 , V_171 ) ;
F_48 ( & V_44 -> V_55 . V_104 , V_45 ) ;
}
static const char * F_65 ( struct V_114 * V_55 )
{
struct V_43 * V_44 = F_54 ( V_55 ) ;
return ( V_44 -> V_45 & V_175 ) ? L_1 : L_2 ;
}
static void F_66 ( struct V_114 * V_55 )
{
}
static int F_67 ( struct V_114 * V_55 )
{
return 0 ;
}
static void F_68 ( struct V_114 * V_55 , int V_45 )
{
}
static int F_69 ( struct V_114 * V_55 , struct V_176 * V_177 )
{
return - V_178 ;
}
static int F_70 ( struct V_114 * V_55 )
{
unsigned char V_56 , V_63 ;
struct V_43 * V_44 = (struct V_43 * ) V_55 ;
struct V_1 T_1 * V_2
= F_16 ( & V_44 -> V_55 ) ;
V_63 = F_1 ( V_2 , V_10 ) ;
if ( V_63 & ( V_12 | V_13 | V_14 ) ) {
F_2 ( V_15 , & V_2 -> V_5 ) ;
F_3 () ;
F_7 ( V_2 ) ;
}
V_56 = F_4 ( & V_2 -> V_5 ) ;
F_3 () ;
if ( V_56 & V_66 )
V_63 |= V_66 ;
if ( ! ( V_56 & V_9 ) )
return V_179 ;
V_56 = F_4 ( & V_2 -> V_11 ) ;
F_3 () ;
V_56 &= V_44 -> V_67 ;
return V_56 ;
}
static void F_71 ( struct V_114 * V_55 ,
unsigned char V_56 )
{
struct V_43 * V_44 = (struct V_43 * ) V_55 ;
F_72 ( & V_44 -> V_55 , V_56 ) ;
}
static int T_4 F_73 ( int V_180 )
{
struct V_43 * V_44 ;
unsigned long V_181 ;
int V_182 = V_180 * 2 ;
int V_7 ;
V_181 = V_182 * sizeof( struct V_43 ) ;
V_183 = F_74 ( V_181 , V_184 ) ;
if ( ! V_183 )
return - V_185 ;
for ( V_7 = 0 ; V_7 < V_182 ; V_7 ++ ) {
V_44 = & V_183 [ V_7 ] ;
F_75 ( & V_44 -> V_55 . V_104 ) ;
if ( V_7 == 0 )
V_186 = V_44 ;
if ( V_7 < V_182 - 1 )
V_44 -> V_109 = V_44 + 1 ;
else
V_44 -> V_109 = NULL ;
}
V_181 = V_180 * sizeof(struct V_187 T_1 * ) ;
V_188 = F_74 ( V_181 , V_184 ) ;
if ( ! V_188 ) {
F_76 ( V_183 ) ;
V_186 = NULL ;
return - V_185 ;
}
return 0 ;
}
static void F_77 ( void )
{
F_76 ( V_183 ) ;
V_186 = NULL ;
F_76 ( V_188 ) ;
}
static void F_72 ( struct V_114 * V_55 , int V_56 )
{
struct V_1 T_1 * V_2 = F_16 ( V_55 ) ;
int V_189 = V_190 ;
do {
unsigned char V_191 = F_4 ( & V_2 -> V_5 ) ;
if ( V_191 & V_90 ) {
F_3 () ;
break;
}
F_9 ( 5 ) ;
} while ( -- V_189 );
F_2 ( V_56 , & V_2 -> V_11 ) ;
F_3 () ;
F_7 ( V_2 ) ;
}
static int F_78 ( struct V_59 * V_59 , unsigned char V_56 )
{
struct V_43 * V_44 = V_59 -> V_192 ;
unsigned long V_45 ;
F_47 ( & V_193 , V_45 ) ;
F_72 ( & V_44 -> V_55 , V_56 ) ;
F_48 ( & V_193 , V_45 ) ;
return 0 ;
}
static int F_79 ( struct V_59 * V_59 )
{
struct V_43 * V_44 = V_59 -> V_192 ;
unsigned long V_45 ;
int V_60 ;
F_47 ( & V_193 , V_45 ) ;
if ( ! V_44 -> V_58 ) {
V_44 -> V_58 = 1 ;
V_60 = 0 ;
} else
V_60 = - V_194 ;
F_48 ( & V_193 , V_45 ) ;
return V_60 ;
}
static void F_80 ( struct V_59 * V_59 )
{
struct V_43 * V_44 = V_59 -> V_192 ;
unsigned long V_45 ;
F_47 ( & V_193 , V_45 ) ;
V_44 -> V_58 = 0 ;
F_48 ( & V_193 , V_45 ) ;
}
static void
F_81 ( struct V_195 * V_196 , const char * V_197 , unsigned int V_198 )
{
struct V_43 * V_44 = & V_183 [ V_196 -> V_199 ] ;
unsigned long V_45 ;
int V_200 = 1 ;
F_82 ( V_45 ) ;
if ( V_44 -> V_55 . V_201 ) {
V_200 = 0 ;
} else if ( V_202 ) {
V_200 = F_83 ( & V_44 -> V_55 . V_104 ) ;
} else
F_42 ( & V_44 -> V_55 . V_104 ) ;
F_84 ( & V_44 -> V_55 , V_197 , V_198 , F_72 ) ;
F_9 ( 2 ) ;
if ( V_200 )
F_43 ( & V_44 -> V_55 . V_104 ) ;
F_85 ( V_45 ) ;
}
static int T_4 F_86 ( struct V_195 * V_196 , char * V_203 )
{
struct V_43 * V_44 = & V_183 [ V_196 -> V_199 ] ;
unsigned long V_45 ;
int V_171 , V_50 ;
if ( V_44 -> V_55 . type != V_204 )
return - 1 ;
F_87 ( V_205 L_3 ,
( V_206 . V_207 - 64 ) + V_196 -> V_199 , V_196 -> V_199 ) ;
F_88 ( V_196 , V_44 -> V_55 . V_208 -> V_209 ) ;
switch ( V_196 -> V_49 & V_52 ) {
case V_210 : V_171 = 150 ; break;
case V_211 : V_171 = 300 ; break;
case V_212 : V_171 = 600 ; break;
case V_213 : V_171 = 1200 ; break;
case V_214 : V_171 = 2400 ; break;
case V_215 : V_171 = 4800 ; break;
default: case V_216 : V_171 = 9600 ; break;
case V_217 : V_171 = 19200 ; break;
case V_218 : V_171 = 38400 ; break;
} ;
V_50 = F_15 ( V_171 , V_53 / V_54 ) ;
F_47 ( & V_44 -> V_55 . V_104 , V_45 ) ;
V_44 -> V_47 [ V_37 ] |= V_219 ;
F_60 ( V_44 , V_196 -> V_49 , 0 , V_50 ) ;
F_50 ( & V_44 -> V_55 , V_124 | V_122 ) ;
F_57 ( V_44 ) ;
F_48 ( & V_44 -> V_55 . V_104 , V_45 ) ;
return 0 ;
}
static inline struct V_195 * F_89 ( void )
{
return & V_220 ;
}
static void T_5 F_90 ( struct V_43 * V_44 )
{
int V_171 , V_50 ;
if ( V_44 -> V_45 & V_221 ) {
V_44 -> V_49 = V_213 | V_152 | V_222 | V_167 ;
V_171 = 1200 ;
} else {
V_44 -> V_49 = V_215 | V_152 | V_222 | V_167 ;
V_171 = 4800 ;
}
V_44 -> V_47 [ V_37 ] |= V_219 ;
V_50 = F_15 ( V_171 , V_53 / V_54 ) ;
F_60 ( V_44 , V_44 -> V_49 , 0 , V_50 ) ;
F_50 ( & V_44 -> V_55 , V_124 | V_122 ) ;
F_57 ( V_44 ) ;
}
static void T_5 F_91 ( struct V_43 * V_44 )
{
struct V_59 * V_59 = & V_44 -> V_59 ;
V_59 -> V_192 = V_44 ;
V_59 -> V_223 . type = V_224 ;
if ( V_44 -> V_45 & V_221 ) {
V_59 -> V_223 . V_225 = V_226 ;
F_92 ( V_59 -> V_227 , L_4 , sizeof( V_59 -> V_227 ) ) ;
} else {
V_59 -> V_223 . V_225 = V_228 ;
V_59 -> V_223 . V_229 = 1 ;
F_92 ( V_59 -> V_227 , L_5 , sizeof( V_59 -> V_227 ) ) ;
}
F_92 ( V_59 -> V_230 ,
( ( V_44 -> V_45 & V_221 ) ?
L_6 : L_7 ) ,
sizeof( V_59 -> V_230 ) ) ;
V_59 -> V_231 = F_78 ;
V_59 -> V_232 = F_79 ;
V_59 -> V_233 = F_80 ;
V_59 -> V_208 . V_234 = V_44 -> V_55 . V_208 ;
F_93 ( V_59 ) ;
}
static void T_5 F_94 ( struct V_43 * V_44 )
{
struct V_1 T_1 * V_2 ;
unsigned long V_45 ;
int V_171 , V_50 ;
V_2 = F_16 ( & V_44 -> V_55 ) ;
F_47 ( & V_44 -> V_55 . V_104 , V_45 ) ;
if ( F_95 ( V_44 ) ) {
F_5 ( V_2 , V_235 , V_236 ) ;
F_96 () ;
( void ) F_1 ( V_2 , V_41 ) ;
}
if ( V_44 -> V_45 & ( V_221 |
V_237 ) ) {
V_44 -> V_47 [ V_10 ] = V_23 | V_132 | V_22 ;
V_44 -> V_47 [ V_24 ] = V_161 | V_138 | V_157 ;
V_44 -> V_47 [ V_26 ] = V_27 | V_153 ;
V_44 -> V_47 [ V_28 ] = V_29 | V_154 ;
V_44 -> V_47 [ V_30 ] = 0x00 ;
V_44 -> V_47 [ V_31 ] = 0x7E ;
V_44 -> V_47 [ V_235 ] = V_238 ;
V_44 -> V_47 [ V_40 ] = 0x00 ;
F_90 ( V_44 ) ;
if ( V_44 -> V_45 & V_239 )
V_44 -> V_47 [ V_235 ] |= V_240 ;
F_5 ( V_2 , V_235 , V_44 -> V_47 [ V_235 ] ) ;
} else {
V_44 -> V_67 = 0xff ;
V_44 -> V_47 [ V_10 ] = V_23 | V_132 | V_22 ;
V_44 -> V_47 [ V_24 ] = V_161 | V_138 | V_157 ;
V_44 -> V_47 [ V_26 ] = V_27 | V_153 ;
V_44 -> V_47 [ V_28 ] = V_29 | V_154 ;
V_44 -> V_47 [ V_30 ] = 0x00 ;
V_44 -> V_47 [ V_31 ] = 0x7E ;
V_44 -> V_47 [ V_235 ] = V_238 ;
V_44 -> V_47 [ V_25 ] = V_134 ;
V_44 -> V_47 [ V_34 ] = V_135 | V_136 ;
V_171 = 9600 ;
V_50 = F_15 ( V_171 , V_53 / V_54 ) ;
V_44 -> V_47 [ V_35 ] = ( V_50 & 0xff ) ;
V_44 -> V_47 [ V_36 ] = ( V_50 >> 8 ) & 0xff ;
V_44 -> V_47 [ V_32 ] = V_139 | V_33 ;
V_44 -> V_47 [ V_37 ] = V_39 ;
V_44 -> V_47 [ V_40 ] = V_241 | V_242 ;
if ( F_8 ( V_2 , V_44 -> V_47 ) ) {
V_44 -> V_45 |= V_175 ;
}
if ( V_44 -> V_45 & V_239 )
V_44 -> V_47 [ V_235 ] |= V_240 ;
F_5 ( V_2 , V_235 , V_44 -> V_47 [ V_235 ] ) ;
}
F_48 ( & V_44 -> V_55 . V_104 , V_45 ) ;
#ifdef F_19
if ( V_44 -> V_45 & ( V_221 |
V_237 ) )
F_91 ( V_44 ) ;
#endif
}
static int T_5 F_97 ( struct V_243 * V_244 )
{
static int V_245 , V_246 ;
int V_247 ;
struct V_43 * V_44 ;
struct V_187 T_1 * V_248 ;
int V_249 = 0 ;
int V_250 ;
if ( F_98 ( V_244 -> V_208 . V_209 , L_8 , NULL ) )
V_249 = 1 ;
if ( V_249 )
V_247 = V_251 + V_245 ;
else
V_247 = V_246 ;
V_188 [ V_247 ] = F_99 ( & V_244 -> V_252 [ 0 ] , 0 ,
sizeof( struct V_187 ) ,
L_2 ) ;
if ( ! V_188 [ V_247 ] )
return - V_185 ;
V_248 = V_188 [ V_247 ] ;
if ( V_253 == - 1 )
V_253 = V_244 -> V_254 . V_255 [ 0 ] ;
V_44 = & V_183 [ V_247 * 2 ] ;
V_44 [ 0 ] . V_55 . V_256 = V_244 -> V_252 [ 0 ] . V_257 + 0x00 ;
V_44 [ 0 ] . V_55 . V_258 = ( void T_1 * ) & V_248 -> V_259 ;
V_44 [ 0 ] . V_55 . V_260 = V_261 ;
V_44 [ 0 ] . V_55 . V_101 = V_244 -> V_254 . V_255 [ 0 ] ;
V_44 [ 0 ] . V_55 . V_262 = V_53 ;
V_44 [ 0 ] . V_55 . V_263 = 1 ;
V_44 [ 0 ] . V_55 . V_264 = & V_265 ;
V_44 [ 0 ] . V_55 . type = V_204 ;
V_44 [ 0 ] . V_55 . V_45 = 0 ;
V_44 [ 0 ] . V_55 . line = ( V_247 * 2 ) + 0 ;
V_44 [ 0 ] . V_55 . V_208 = & V_244 -> V_208 ;
V_44 [ 0 ] . V_45 |= V_266 ;
if ( V_249 )
V_44 [ 0 ] . V_45 |= V_221 ;
F_94 ( & V_44 [ 0 ] ) ;
V_44 [ 1 ] . V_55 . V_256 = V_244 -> V_252 [ 0 ] . V_257 + 0x04 ;
V_44 [ 1 ] . V_55 . V_258 = ( void T_1 * ) & V_248 -> V_267 ;
V_44 [ 1 ] . V_55 . V_260 = V_261 ;
V_44 [ 1 ] . V_55 . V_101 = V_244 -> V_254 . V_255 [ 0 ] ;
V_44 [ 1 ] . V_55 . V_262 = V_53 ;
V_44 [ 1 ] . V_55 . V_263 = 1 ;
V_44 [ 1 ] . V_55 . V_264 = & V_265 ;
V_44 [ 1 ] . V_55 . type = V_204 ;
V_44 [ 1 ] . V_55 . V_45 = 0 ;
V_44 [ 1 ] . V_55 . line = ( V_247 * 2 ) + 1 ;
V_44 [ 1 ] . V_55 . V_208 = & V_244 -> V_208 ;
V_44 [ 1 ] . V_45 |= 0 ;
if ( V_249 )
V_44 [ 1 ] . V_45 |= V_237 ;
F_94 ( & V_44 [ 1 ] ) ;
if ( ! V_249 ) {
if ( F_100 ( F_89 () , V_244 -> V_208 . V_209 ,
& V_206 , V_44 [ 0 ] . V_55 . line ,
false ) )
V_44 -> V_45 |= V_268 ;
V_250 = F_101 ( & V_206 , & V_44 [ 0 ] . V_55 ) ;
if ( V_250 ) {
F_102 ( & V_244 -> V_252 [ 0 ] ,
V_248 , sizeof( struct V_187 ) ) ;
return V_250 ;
}
if ( F_100 ( F_89 () , V_244 -> V_208 . V_209 ,
& V_206 , V_44 [ 1 ] . V_55 . line ,
false ) )
V_44 -> V_45 |= V_268 ;
V_250 = F_101 ( & V_206 , & V_44 [ 1 ] . V_55 ) ;
if ( V_250 ) {
F_103 ( & V_206 , & V_44 [ 0 ] . V_55 ) ;
F_102 ( & V_244 -> V_252 [ 0 ] ,
V_248 , sizeof( struct V_187 ) ) ;
return V_250 ;
}
V_246 ++ ;
} else {
F_87 ( V_205 L_9
L_10 ,
F_104 ( & V_244 -> V_208 ) ,
( unsigned long long ) V_44 [ 0 ] . V_55 . V_256 ,
V_244 -> V_254 . V_255 [ 0 ] , F_65 ( & V_44 [ 0 ] . V_55 ) ) ;
F_87 ( V_205 L_11
L_10 ,
F_104 ( & V_244 -> V_208 ) ,
( unsigned long long ) V_44 [ 1 ] . V_55 . V_256 ,
V_244 -> V_254 . V_255 [ 0 ] , F_65 ( & V_44 [ 1 ] . V_55 ) ) ;
V_245 ++ ;
}
F_105 ( & V_244 -> V_208 , & V_44 [ 0 ] ) ;
return 0 ;
}
static void T_6 F_106 ( struct V_43 * V_44 )
{
if ( F_18 ( V_44 ) || F_21 ( V_44 ) ) {
#ifdef F_19
F_107 ( & V_44 -> V_59 ) ;
#endif
} else
F_103 ( & V_206 , & V_44 -> V_55 ) ;
}
static int T_6 F_108 ( struct V_243 * V_244 )
{
struct V_43 * V_44 = F_109 ( & V_244 -> V_208 ) ;
struct V_187 T_1 * V_16 ;
F_106 ( & V_44 [ 0 ] ) ;
F_106 ( & V_44 [ 1 ] ) ;
V_16 = V_188 [ V_44 [ 0 ] . V_55 . line / 2 ] ;
F_102 ( & V_244 -> V_252 [ 0 ] , V_16 , sizeof( struct V_187 ) ) ;
F_105 ( & V_244 -> V_208 , NULL ) ;
return 0 ;
}
static int T_4 F_110 ( void )
{
struct V_269 * V_270 ;
int V_250 ;
int V_271 = 0 ;
int V_180 = 0 ;
F_111 (dp, L_2 ) {
V_180 ++ ;
if ( F_98 ( V_270 , L_8 , NULL ) )
V_271 ++ ;
}
if ( V_180 ) {
V_250 = F_73 ( V_180 ) ;
if ( V_250 )
goto V_272;
V_251 = V_180 - V_271 ;
V_250 = F_112 ( & V_206 ,
V_251 * 2 ) ;
if ( V_250 )
goto V_273;
}
V_250 = F_113 ( & V_274 ) ;
if ( V_250 )
goto V_275;
if ( V_253 != - 1 ) {
struct V_43 * V_44 = V_186 ;
V_250 = F_114 ( V_253 , F_41 , V_276 ,
L_2 , V_186 ) ;
if ( V_250 )
goto V_277;
while ( V_44 ) {
struct V_1 T_1 * V_2 ;
V_2 = F_16 ( & V_44 -> V_55 ) ;
V_44 -> V_45 |= V_239 ;
V_44 -> V_47 [ V_235 ] |= V_240 ;
F_5 ( V_2 , V_235 , V_44 -> V_47 [ V_235 ] ) ;
V_44 = V_44 -> V_109 ;
}
}
V_272:
return V_250 ;
V_277:
F_115 ( & V_274 ) ;
V_275:
if ( V_180 ) {
F_116 ( & V_206 , V_180 ) ;
V_206 . V_278 = NULL ;
}
V_273:
F_77 () ;
goto V_272;
}
static void T_7 F_117 ( void )
{
F_115 ( & V_274 ) ;
if ( V_253 != - 1 ) {
struct V_43 * V_44 = V_186 ;
while ( V_44 ) {
struct V_1 T_1 * V_2 ;
V_2 = F_16 ( & V_44 -> V_55 ) ;
V_44 -> V_45 &= ~ V_239 ;
V_44 -> V_47 [ V_235 ] &= ~ V_240 ;
F_5 ( V_2 , V_235 , V_44 -> V_47 [ V_235 ] ) ;
V_44 = V_44 -> V_109 ;
}
F_118 ( V_253 , V_186 ) ;
V_253 = - 1 ;
}
if ( V_206 . V_279 ) {
F_116 ( & V_206 , V_206 . V_279 ) ;
F_77 () ;
}
}
