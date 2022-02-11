static unsigned char F_1 ( struct V_1 * V_2 ,
unsigned char V_3 )
{
unsigned char V_4 ;
F_2 ( V_3 , & V_2 -> V_5 ) ;
F_3 () ;
V_4 = F_4 ( & V_2 -> V_5 ) ;
F_3 () ;
return V_4 ;
}
static void F_5 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned char V_6 )
{
F_2 ( V_3 , & V_2 -> V_5 ) ;
F_3 () ;
F_2 ( V_6 , & V_2 -> V_5 ) ;
F_3 () ;
}
static void F_6 ( struct V_1 * V_2 )
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
static void F_8 ( struct V_1 * V_2 , unsigned char * V_16 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < 1000 ; V_7 ++ ) {
unsigned char V_17 = F_1 ( V_2 , V_10 ) ;
if ( V_17 & V_18 )
break;
F_9 ( 100 ) ;
}
F_2 ( V_15 , & V_2 -> V_5 ) ;
F_3 () ;
F_7 ( V_2 ) ;
F_6 ( V_2 ) ;
F_5 ( V_2 , V_10 ,
V_16 [ V_10 ] & ~ ( V_19 | V_20 | V_21 ) ) ;
F_5 ( V_2 , V_22 , V_16 [ V_22 ] ) ;
F_5 ( V_2 , V_23 , V_16 [ V_23 ] ) ;
F_5 ( V_2 , V_24 , V_16 [ V_24 ] & ~ V_25 ) ;
F_5 ( V_2 , V_26 , V_16 [ V_26 ] & ~ V_27 ) ;
F_5 ( V_2 , V_28 , V_16 [ V_28 ] ) ;
F_5 ( V_2 , V_29 , V_16 [ V_29 ] ) ;
F_5 ( V_2 , V_30 , V_16 [ V_30 ] & ~ V_31 ) ;
F_5 ( V_2 , V_32 , V_16 [ V_32 ] ) ;
F_5 ( V_2 , V_33 , V_16 [ V_33 ] ) ;
F_5 ( V_2 , V_34 , V_16 [ V_34 ] ) ;
F_5 ( V_2 , V_30 , V_16 [ V_30 ] ) ;
F_5 ( V_2 , V_35 , V_16 [ V_35 ] ) ;
F_5 ( V_2 , V_36 , V_37 ) ;
F_5 ( V_2 , V_36 , V_37 ) ;
F_5 ( V_2 , V_24 , V_16 [ V_24 ] ) ;
F_5 ( V_2 , V_26 , V_16 [ V_26 ] ) ;
F_5 ( V_2 , V_10 , V_16 [ V_10 ] ) ;
}
static void F_10 ( struct V_38 * V_39 ,
struct V_1 * V_2 )
{
if ( ! F_11 ( V_39 ) ) {
if ( F_12 ( V_39 ) ) {
V_39 -> V_40 |= V_41 ;
} else {
F_8 ( V_2 , V_39 -> V_42 ) ;
}
}
}
static bool F_13 ( struct V_38 * V_39 ,
struct V_1 * V_2 )
{
unsigned char V_43 , V_44 ;
unsigned int V_45 ;
bool V_46 = V_39 -> V_47 . V_48 != NULL ;
for (; ; ) {
V_43 = F_4 ( & V_2 -> V_5 ) ;
F_3 () ;
if ( ! ( V_43 & V_9 ) )
break;
V_45 = F_1 ( V_2 , V_10 ) ;
if ( V_45 & ( V_12 | V_13 | V_14 ) ) {
F_2 ( V_15 , & V_2 -> V_5 ) ;
F_3 () ;
F_7 ( V_2 ) ;
}
V_43 = F_4 ( & V_2 -> V_11 ) ;
F_3 () ;
V_43 &= V_39 -> V_49 ;
if ( ! V_43 )
V_45 |= V_39 -> V_50 ;
V_44 = V_51 ;
V_39 -> V_47 . V_52 . V_53 ++ ;
if ( V_45 & ( V_12 | V_13 | V_14 | V_54 | V_55 ) ) {
V_39 -> V_50 = 0 ;
if ( V_45 & ( V_54 | V_55 ) ) {
V_39 -> V_47 . V_52 . V_56 ++ ;
if ( V_45 & V_54 )
continue;
V_45 &= ~ ( V_12 | V_14 ) ;
}
else if ( V_45 & V_12 )
V_39 -> V_47 . V_52 . V_57 ++ ;
else if ( V_45 & V_14 )
V_39 -> V_47 . V_52 . V_58 ++ ;
if ( V_45 & V_13 )
V_39 -> V_47 . V_52 . V_59 ++ ;
V_45 &= V_39 -> V_47 . V_60 ;
if ( V_45 & V_55 )
V_44 = V_61 ;
else if ( V_45 & V_12 )
V_44 = V_62 ;
else if ( V_45 & V_14 )
V_44 = V_63 ;
}
if ( F_14 ( & V_39 -> V_47 , V_43 ) )
continue;
if ( V_46 )
F_15 ( & V_39 -> V_47 , V_45 , V_13 , V_43 , V_44 ) ;
}
return V_46 ;
}
static void F_16 ( struct V_38 * V_39 ,
struct V_1 * V_2 )
{
unsigned char V_64 ;
V_64 = F_4 ( & V_2 -> V_5 ) ;
F_3 () ;
F_2 ( V_37 , & V_2 -> V_5 ) ;
F_3 () ;
F_7 ( V_2 ) ;
if ( V_39 -> V_42 [ V_35 ] & V_65 ) {
if ( ( V_64 & V_66 ) && ! ( V_39 -> V_67 & V_66 ) ) {
if ( F_17 ( & V_39 -> V_47 ) )
V_39 -> V_50 = V_54 ;
else
V_39 -> V_50 = V_55 ;
}
}
if ( F_18 ( V_39 ) ) {
if ( V_64 & V_68 )
V_39 -> V_47 . V_52 . V_69 ++ ;
if ( ( V_64 ^ V_39 -> V_67 ) ^ V_70 )
F_19 ( & V_39 -> V_47 ,
( V_64 & V_70 ) ) ;
if ( ( V_64 ^ V_39 -> V_67 ) ^ V_71 )
F_20 ( & V_39 -> V_47 ,
( V_64 & V_71 ) ) ;
F_21 ( & V_39 -> V_47 . V_48 -> V_47 . V_72 ) ;
}
V_39 -> V_67 = V_64 ;
}
static void F_22 ( struct V_38 * V_39 ,
struct V_1 * V_2 )
{
struct V_73 * V_74 ;
if ( F_23 ( V_39 ) ) {
unsigned char V_64 = F_4 ( & V_2 -> V_5 ) ;
F_3 () ;
if ( ! ( V_64 & V_75 ) )
return;
}
V_39 -> V_40 &= ~ V_76 ;
if ( F_11 ( V_39 ) ) {
F_8 ( V_2 , V_39 -> V_42 ) ;
V_39 -> V_40 &= ~ V_41 ;
}
if ( F_24 ( V_39 ) ) {
V_39 -> V_40 &= ~ V_77 ;
goto V_78;
}
if ( V_39 -> V_47 . V_79 ) {
V_39 -> V_40 |= V_76 ;
F_2 ( V_39 -> V_47 . V_79 , & V_2 -> V_11 ) ;
F_3 () ;
F_7 ( V_2 ) ;
V_39 -> V_47 . V_52 . V_80 ++ ;
V_39 -> V_47 . V_79 = 0 ;
return;
}
if ( V_39 -> V_47 . V_48 == NULL )
goto V_78;
V_74 = & V_39 -> V_47 . V_48 -> V_74 ;
if ( F_25 ( V_74 ) )
goto V_78;
if ( F_26 ( & V_39 -> V_47 ) )
goto V_78;
V_39 -> V_40 |= V_76 ;
F_2 ( V_74 -> V_81 [ V_74 -> V_82 ] , & V_2 -> V_11 ) ;
F_3 () ;
F_7 ( V_2 ) ;
V_74 -> V_82 = ( V_74 -> V_82 + 1 ) & ( V_83 - 1 ) ;
V_39 -> V_47 . V_52 . V_80 ++ ;
if ( F_27 ( V_74 ) < V_84 )
F_28 ( & V_39 -> V_47 ) ;
return;
V_78:
F_2 ( V_85 , & V_2 -> V_5 ) ;
F_3 () ;
F_7 ( V_2 ) ;
}
static T_1 F_29 ( int V_86 , void * V_87 )
{
struct V_38 * V_39 = V_87 ;
while ( V_39 ) {
struct V_1 * V_2
= F_30 ( & V_39 -> V_47 ) ;
unsigned char V_88 ;
bool V_46 = false ;
F_31 ( & V_39 -> V_47 . V_89 ) ;
V_88 = F_1 ( V_2 , V_24 ) ;
if ( V_88 & ( V_90 | V_91 | V_92 ) ) {
F_2 ( V_93 , & V_2 -> V_5 ) ;
F_3 () ;
F_7 ( V_2 ) ;
if ( V_88 & V_92 )
V_46 = F_13 ( V_39 , V_2 ) ;
if ( V_88 & V_90 )
F_16 ( V_39 , V_2 ) ;
if ( V_88 & V_91 )
F_22 ( V_39 , V_2 ) ;
}
F_32 ( & V_39 -> V_47 . V_89 ) ;
if ( V_46 )
F_33 ( & V_39 -> V_47 . V_48 -> V_47 ) ;
V_39 = V_39 -> V_94 ;
V_2 = F_30 ( & V_39 -> V_47 ) ;
V_46 = false ;
F_31 ( & V_39 -> V_47 . V_89 ) ;
if ( V_88 & ( V_95 | V_96 | V_97 ) ) {
F_2 ( V_93 , & V_2 -> V_5 ) ;
F_3 () ;
F_7 ( V_2 ) ;
if ( V_88 & V_97 )
V_46 = F_13 ( V_39 , V_2 ) ;
if ( V_88 & V_95 )
F_16 ( V_39 , V_2 ) ;
if ( V_88 & V_96 )
F_22 ( V_39 , V_2 ) ;
}
F_32 ( & V_39 -> V_47 . V_89 ) ;
if ( V_46 )
F_33 ( & V_39 -> V_47 . V_48 -> V_47 ) ;
V_39 = V_39 -> V_94 ;
}
return V_98 ;
}
static T_2 unsigned char F_34 ( struct V_99 * V_47 )
{
struct V_1 * V_2 ;
unsigned char V_64 ;
V_2 = F_30 ( V_47 ) ;
V_64 = F_4 ( & V_2 -> V_5 ) ;
F_3 () ;
return V_64 ;
}
static unsigned int F_35 ( struct V_99 * V_47 )
{
unsigned long V_40 ;
unsigned char V_64 ;
unsigned int V_100 ;
F_36 ( & V_47 -> V_89 , V_40 ) ;
V_64 = F_34 ( V_47 ) ;
F_37 ( & V_47 -> V_89 , V_40 ) ;
if ( V_64 & V_75 )
V_100 = V_101 ;
else
V_100 = 0 ;
return V_100 ;
}
static unsigned int F_38 ( struct V_99 * V_47 )
{
unsigned char V_64 ;
unsigned int V_100 ;
V_64 = F_34 ( V_47 ) ;
V_100 = 0 ;
if ( V_64 & V_70 )
V_100 |= V_102 ;
if ( V_64 & V_68 )
V_100 |= V_103 ;
if ( V_64 & V_71 )
V_100 |= V_104 ;
return V_100 ;
}
static void F_39 ( struct V_99 * V_47 , unsigned int V_105 )
{
struct V_38 * V_39 = (struct V_38 * ) V_47 ;
struct V_1 * V_2 = F_30 ( V_47 ) ;
unsigned char V_106 , V_107 ;
V_106 = V_107 = 0 ;
if ( V_105 & V_108 )
V_106 |= V_109 ;
else
V_107 |= V_109 ;
if ( V_105 & V_110 )
V_106 |= V_111 ;
else
V_107 |= V_111 ;
V_39 -> V_42 [ V_26 ] |= V_106 ;
V_39 -> V_42 [ V_26 ] &= ~ V_107 ;
F_5 ( V_2 , V_26 , V_39 -> V_42 [ V_26 ] ) ;
}
static void F_40 ( struct V_99 * V_47 )
{
struct V_38 * V_39 = (struct V_38 * ) V_47 ;
V_39 -> V_40 |= V_77 ;
}
static void F_41 ( struct V_99 * V_47 )
{
struct V_38 * V_39 = (struct V_38 * ) V_47 ;
struct V_1 * V_2 = F_30 ( V_47 ) ;
unsigned char V_64 ;
V_39 -> V_40 |= V_76 ;
V_39 -> V_40 &= ~ V_77 ;
V_64 = F_4 ( & V_2 -> V_5 ) ;
F_3 () ;
if ( ! ( V_64 & V_75 ) )
return;
if ( V_47 -> V_79 ) {
F_2 ( V_47 -> V_79 , & V_2 -> V_11 ) ;
F_3 () ;
F_7 ( V_2 ) ;
V_47 -> V_52 . V_80 ++ ;
V_47 -> V_79 = 0 ;
} else {
struct V_73 * V_74 = & V_47 -> V_48 -> V_74 ;
F_2 ( V_74 -> V_81 [ V_74 -> V_82 ] , & V_2 -> V_11 ) ;
F_3 () ;
F_7 ( V_2 ) ;
V_74 -> V_82 = ( V_74 -> V_82 + 1 ) & ( V_83 - 1 ) ;
V_47 -> V_52 . V_80 ++ ;
if ( F_27 ( V_74 ) < V_84 )
F_28 ( & V_39 -> V_47 ) ;
}
}
static void F_42 ( struct V_99 * V_47 )
{
struct V_38 * V_39 = F_43 ( V_47 ) ;
struct V_1 * V_2 ;
if ( F_23 ( V_39 ) )
return;
V_2 = F_30 ( V_47 ) ;
V_39 -> V_42 [ V_10 ] &= ~ V_19 ;
F_10 ( V_39 , V_2 ) ;
}
static void F_44 ( struct V_99 * V_47 )
{
struct V_38 * V_39 = (struct V_38 * ) V_47 ;
struct V_1 * V_2 = F_30 ( V_47 ) ;
unsigned char V_112 ;
V_112 = V_39 -> V_42 [ V_35 ] | ( V_113 | V_114 | V_115 ) ;
if ( V_112 != V_39 -> V_42 [ V_35 ] ) {
V_39 -> V_42 [ V_35 ] = V_112 ;
F_5 ( V_2 , V_35 , V_39 -> V_42 [ V_35 ] ) ;
}
}
static void F_45 ( struct V_99 * V_47 , int V_116 )
{
struct V_38 * V_39 = (struct V_38 * ) V_47 ;
struct V_1 * V_2 = F_30 ( V_47 ) ;
unsigned char V_106 , V_107 , V_112 ;
unsigned long V_40 ;
V_106 = V_107 = 0 ;
if ( V_116 )
V_106 |= V_117 ;
else
V_107 |= V_117 ;
F_36 ( & V_47 -> V_89 , V_40 ) ;
V_112 = ( V_39 -> V_42 [ V_26 ] | V_106 ) & ~ V_107 ;
if ( V_112 != V_39 -> V_42 [ V_26 ] ) {
V_39 -> V_42 [ V_26 ] = V_112 ;
F_5 ( V_2 , V_26 , V_39 -> V_42 [ V_26 ] ) ;
}
F_37 ( & V_47 -> V_89 , V_40 ) ;
}
static void F_46 ( struct V_38 * V_39 )
{
struct V_1 * V_2 ;
int V_7 ;
if ( V_39 -> V_40 & V_118 )
return;
V_2 = F_30 ( & V_39 -> V_47 ) ;
for ( V_7 = 0 ; V_7 < 1000 ; V_7 ++ ) {
unsigned char V_17 = F_1 ( V_2 , V_10 ) ;
if ( V_17 & V_18 )
break;
F_9 ( 100 ) ;
}
if ( ! F_47 ( V_39 ) ) {
V_39 ++ ;
V_2 = F_30 ( & V_39 -> V_47 ) ;
}
F_5 ( V_2 , V_119 , V_120 ) ;
F_48 () ;
( void ) F_1 ( V_2 , V_36 ) ;
V_39 -> V_40 |= V_118 ;
V_39 -> V_94 -> V_40 |= V_118 ;
}
static void F_49 ( struct V_38 * V_39 )
{
struct V_1 * V_2 ;
V_2 = F_30 ( & V_39 -> V_47 ) ;
F_46 ( V_39 ) ;
F_8 ( V_2 , V_39 -> V_42 ) ;
F_5 ( V_2 , V_119 , V_39 -> V_42 [ V_119 ] ) ;
V_39 -> V_67 = F_4 ( & V_2 -> V_5 ) ;
V_39 -> V_42 [ V_24 ] |= V_25 ;
V_39 -> V_42 [ V_26 ] |= V_27 ;
V_39 -> V_42 [ V_10 ] |= V_21 | V_121 | V_20 ;
F_10 ( V_39 , V_2 ) ;
}
static int F_50 ( struct V_99 * V_47 )
{
struct V_38 * V_39 = F_43 ( V_47 ) ;
unsigned long V_40 ;
if ( F_23 ( V_39 ) )
return 0 ;
F_36 ( & V_47 -> V_89 , V_40 ) ;
F_49 ( V_39 ) ;
F_37 ( & V_47 -> V_89 , V_40 ) ;
return 0 ;
}
static void F_51 ( struct V_99 * V_47 )
{
struct V_38 * V_39 = F_43 ( V_47 ) ;
struct V_1 * V_2 ;
unsigned long V_40 ;
if ( F_23 ( V_39 ) )
return;
F_36 ( & V_47 -> V_89 , V_40 ) ;
V_2 = F_30 ( V_47 ) ;
V_39 -> V_42 [ V_24 ] &= ~ V_25 ;
V_39 -> V_42 [ V_26 ] &= ~ V_27 ;
V_39 -> V_42 [ V_10 ] &= ~ ( V_21 | V_20 | V_19 ) ;
V_39 -> V_42 [ V_26 ] &= ~ V_117 ;
F_10 ( V_39 , V_2 ) ;
F_37 ( & V_47 -> V_89 , V_40 ) ;
}
static void
F_52 ( struct V_38 * V_39 , unsigned int V_122 ,
unsigned int V_123 , int V_124 )
{
V_39 -> V_42 [ V_23 ] = V_125 ;
V_39 -> V_42 [ V_32 ] = V_126 | V_127 ;
V_39 -> V_42 [ V_22 ] &= ~ V_128 ;
V_39 -> V_42 [ V_22 ] |= V_129 ;
V_39 -> V_42 [ V_33 ] = V_124 & 0xff ;
V_39 -> V_42 [ V_34 ] = ( V_124 >> 8 ) & 0xff ;
V_39 -> V_42 [ V_30 ] = V_31 ;
V_39 -> V_42 [ 3 ] &= ~ V_130 ;
V_39 -> V_42 [ 5 ] &= ~ V_131 ;
switch ( V_122 & V_132 ) {
case V_133 :
V_39 -> V_42 [ 3 ] |= V_134 ;
V_39 -> V_42 [ 5 ] |= V_135 ;
V_39 -> V_49 = 0x1f ;
break;
case V_136 :
V_39 -> V_42 [ 3 ] |= V_137 ;
V_39 -> V_42 [ 5 ] |= V_138 ;
V_39 -> V_49 = 0x3f ;
break;
case V_139 :
V_39 -> V_42 [ 3 ] |= V_140 ;
V_39 -> V_42 [ 5 ] |= V_141 ;
V_39 -> V_49 = 0x7f ;
break;
case V_142 :
default:
V_39 -> V_42 [ 3 ] |= V_143 ;
V_39 -> V_42 [ 5 ] |= V_144 ;
V_39 -> V_49 = 0xff ;
break;
}
V_39 -> V_42 [ 4 ] &= ~ 0x0c ;
if ( V_122 & V_145 )
V_39 -> V_42 [ 4 ] |= V_146 ;
else
V_39 -> V_42 [ 4 ] |= V_147 ;
if ( V_122 & V_148 )
V_39 -> V_42 [ 4 ] |= V_149 ;
else
V_39 -> V_42 [ 4 ] &= ~ V_149 ;
if ( ! ( V_122 & V_150 ) )
V_39 -> V_42 [ 4 ] |= V_151 ;
else
V_39 -> V_42 [ 4 ] &= ~ V_151 ;
V_39 -> V_47 . V_60 = V_13 ;
if ( V_123 & V_152 )
V_39 -> V_47 . V_60 |= V_14 | V_12 ;
if ( V_123 & ( V_153 | V_154 ) )
V_39 -> V_47 . V_60 |= V_66 ;
V_39 -> V_47 . V_155 = 0 ;
if ( V_123 & V_156 )
V_39 -> V_47 . V_155 |= V_14 | V_12 ;
if ( V_123 & V_157 ) {
V_39 -> V_47 . V_155 |= V_66 ;
if ( V_123 & V_156 )
V_39 -> V_47 . V_155 |= V_13 ;
}
if ( ( V_122 & V_158 ) == 0 )
V_39 -> V_47 . V_155 = 0xff ;
}
static void
F_53 ( struct V_99 * V_47 , struct V_159 * V_160 ,
struct V_159 * V_161 )
{
struct V_38 * V_39 = (struct V_38 * ) V_47 ;
unsigned long V_40 ;
int V_162 , V_124 ;
V_162 = F_54 ( V_47 , V_160 , V_161 , 1200 , 76800 ) ;
F_36 ( & V_39 -> V_47 . V_89 , V_40 ) ;
V_124 = F_55 ( V_162 , V_163 / V_164 ) ;
F_52 ( V_39 , V_160 -> V_165 , V_160 -> V_166 , V_124 ) ;
if ( F_56 ( & V_39 -> V_47 , V_160 -> V_165 ) )
V_39 -> V_40 |= V_167 ;
else
V_39 -> V_40 &= ~ V_167 ;
F_10 ( V_39 , F_30 ( V_47 ) ) ;
F_57 ( V_47 , V_160 -> V_165 , V_162 ) ;
F_37 ( & V_39 -> V_47 . V_89 , V_40 ) ;
}
static const char * F_58 ( struct V_99 * V_47 )
{
return L_1 ;
}
static void F_59 ( struct V_99 * V_47 )
{
}
static int F_60 ( struct V_99 * V_47 )
{
return 0 ;
}
static void F_61 ( struct V_99 * V_47 , int V_40 )
{
}
static int F_62 ( struct V_99 * V_47 , struct V_168 * V_169 )
{
return - V_170 ;
}
static void * T_3 F_63 ( unsigned long V_171 )
{
return F_64 ( V_171 , V_172 ) ;
}
static void T_3 F_65 ( void )
{
V_173 = (struct V_38 * )
F_63 ( V_174 * sizeof( struct V_38 ) ) ;
V_175 = (struct V_176 * * )
F_63 ( V_177 * sizeof( struct V_176 * ) ) ;
if ( V_173 == NULL || V_175 == NULL ) {
F_66 ( L_2 ) ;
}
}
static struct V_176 * T_3 F_67 ( int V_178 )
{
unsigned long V_179 ;
if ( V_178 < 0 || V_178 >= V_177 ) {
F_66 ( L_3 , V_178 ) ;
}
V_179 = ( unsigned long ) & V_180 -> V_181 ;
V_182 = V_183 ;
F_68 ( V_179 , 8 , L_1 ) ;
return (struct V_176 * ) V_179 ;
}
static void F_69 ( struct V_99 * V_47 , int V_43 )
{
struct V_1 * V_2 = F_30 ( V_47 ) ;
int V_184 = V_185 ;
do {
unsigned char V_186 = F_4 ( & V_2 -> V_5 ) ;
if ( V_186 & V_75 ) {
F_3 () ;
break;
}
F_9 ( 5 ) ;
} while ( -- V_184 );
F_2 ( V_43 , & V_2 -> V_11 ) ;
F_3 () ;
F_7 ( V_2 ) ;
}
static void
F_70 ( struct V_187 * V_188 , const char * V_189 , unsigned int V_190 )
{
struct V_38 * V_39 = & V_173 [ V_188 -> V_191 ] ;
unsigned long V_40 ;
F_36 ( & V_39 -> V_47 . V_89 , V_40 ) ;
F_71 ( & V_39 -> V_47 , V_189 , V_190 , F_69 ) ;
F_9 ( 2 ) ;
F_37 ( & V_39 -> V_47 . V_89 , V_40 ) ;
}
static int T_3 F_72 ( struct V_187 * V_188 , char * V_192 )
{
struct V_38 * V_39 = & V_173 [ V_188 -> V_191 ] ;
unsigned long V_40 ;
int V_162 = 9600 , V_193 = 8 ;
int V_57 = 'n' ;
int V_194 = 'n' ;
V_39 -> V_40 |= V_195 ;
F_73 ( V_196 L_4 , V_188 -> V_191 ) ;
F_36 ( & V_39 -> V_47 . V_89 , V_40 ) ;
V_39 -> V_42 [ V_35 ] |= V_65 ;
F_49 ( V_39 ) ;
F_37 ( & V_39 -> V_47 . V_89 , V_40 ) ;
if ( V_192 )
F_74 ( V_192 , & V_162 , & V_57 , & V_193 , & V_194 ) ;
return F_75 ( & V_39 -> V_47 , V_188 , V_162 , V_57 , V_193 , V_194 ) ;
}
static void T_3 F_76 ( void )
{
struct V_38 * V_39 ;
struct V_176 * V_197 ;
int V_2 , V_178 ;
for ( V_2 = 0 ; V_2 < V_174 ; V_2 ++ )
F_77 ( & V_173 [ V_2 ] . V_47 . V_89 ) ;
V_198 = & V_173 [ V_174 - 1 ] ;
V_39 = & V_173 [ 0 ] ;
for ( V_2 = V_174 - 1 ; V_2 > 0 ; V_2 -- )
V_39 [ V_2 ] . V_94 = & V_39 [ V_2 - 1 ] ;
V_39 [ V_2 ] . V_94 = NULL ;
for ( V_178 = 0 ; V_178 < V_177 ; V_178 ++ ) {
if ( ! V_175 [ V_178 ] ) {
V_175 [ V_178 ] = V_197 = F_67 ( V_178 ) ;
V_39 [ ( V_178 * 2 ) + 0 ] . V_47 . V_199 = ( char * ) & V_197 -> V_200 ;
V_39 [ ( V_178 * 2 ) + 1 ] . V_47 . V_199 = ( char * ) & V_197 -> V_201 ;
V_39 [ ( V_178 * 2 ) + 0 ] . V_47 . V_202 =
( unsigned long ) F_78 ( ( unsigned long ) & V_197 -> V_200 , 8 ) ;
V_39 [ ( V_178 * 2 ) + 1 ] . V_47 . V_202 =
( unsigned long ) F_78 ( ( unsigned long ) & V_197 -> V_201 , 8 ) ;
}
V_39 [ ( V_178 * 2 ) + 0 ] . V_47 . V_203 = V_204 ;
V_39 [ ( V_178 * 2 ) + 0 ] . V_47 . V_86 = V_182 ;
V_39 [ ( V_178 * 2 ) + 0 ] . V_47 . V_205 = V_163 ;
V_39 [ ( V_178 * 2 ) + 0 ] . V_47 . V_206 = 1 ;
V_39 [ ( V_178 * 2 ) + 0 ] . V_47 . V_207 = & V_208 ;
V_39 [ ( V_178 * 2 ) + 0 ] . V_47 . type = V_209 ;
V_39 [ ( V_178 * 2 ) + 0 ] . V_47 . V_40 = 0 ;
V_39 [ ( V_178 * 2 ) + 0 ] . V_47 . line = ( V_178 * 2 ) + 0 ;
V_39 [ ( V_178 * 2 ) + 0 ] . V_40 = 0 ;
V_39 [ ( V_178 * 2 ) + 1 ] . V_47 . V_203 = V_204 ;
V_39 [ ( V_178 * 2 ) + 1 ] . V_47 . V_86 = V_182 ;
V_39 [ ( V_178 * 2 ) + 1 ] . V_47 . V_205 = V_163 ;
V_39 [ ( V_178 * 2 ) + 1 ] . V_47 . V_206 = 1 ;
V_39 [ ( V_178 * 2 ) + 1 ] . V_47 . V_207 = & V_208 ;
V_39 [ ( V_178 * 2 ) + 1 ] . V_47 . type = V_209 ;
V_39 [ ( V_178 * 2 ) + 1 ] . V_47 . line = ( V_178 * 2 ) + 1 ;
V_39 [ ( V_178 * 2 ) + 1 ] . V_40 |= V_210 ;
}
for ( V_2 = 0 ; V_2 < V_174 ; V_2 ++ ) {
struct V_38 * V_39 = & V_173 [ V_2 ] ;
int V_124 ;
V_39 -> V_49 = 0xff ;
V_39 -> V_42 [ V_10 ] = V_21 | V_121 | V_20 ;
V_39 -> V_42 [ V_22 ] = V_151 | V_129 | V_147 ;
V_39 -> V_42 [ V_24 ] = V_25 | V_143 ;
V_39 -> V_42 [ V_26 ] = V_27 | V_144 ;
V_39 -> V_42 [ V_119 ] = V_211 | V_212 ;
V_39 -> V_42 [ V_23 ] = V_125 ;
V_39 -> V_42 [ V_32 ] = V_126 | V_127 ;
V_124 = F_55 ( 9600 , V_163 / V_164 ) ;
V_39 -> V_42 [ V_33 ] = ( V_124 & 0xff ) ;
V_39 -> V_42 [ V_34 ] = ( V_124 >> 8 ) & 0xff ;
V_39 -> V_42 [ V_30 ] = V_31 ;
}
}
static int T_3 F_79 ( void )
{
int V_100 ;
F_73 ( V_196 L_5 , V_177 ) ;
F_76 () ;
if ( F_80 ( V_182 , F_29 , 0 ,
L_1 , V_198 ) ) {
F_66 ( L_6 ) ;
}
V_100 = F_81 ( & V_213 ) ;
if ( V_100 == 0 ) {
int V_7 ;
for ( V_7 = 0 ; V_7 < V_174 ; V_7 ++ ) {
struct V_38 * V_39 = & V_173 [ V_7 ] ;
F_82 ( & V_213 , & V_39 -> V_47 ) ;
}
}
return V_100 ;
}
static int T_3 F_83 ( void )
{
F_65 () ;
F_79 () ;
return 0 ;
}
static void T_4 F_84 ( void )
{
int V_7 ;
struct V_38 * V_39 ;
for ( V_7 = 0 ; V_7 < V_174 ; V_7 ++ ) {
V_39 = & V_173 [ V_7 ] ;
F_85 ( & V_213 , & V_39 -> V_47 ) ;
}
V_39 = & V_173 [ 0 ] ;
for ( V_7 = 0 ; V_7 < V_177 ; V_7 ++ ) {
if ( V_39 [ ( V_7 * 2 ) + 0 ] . V_47 . V_202 ) {
F_86 ( ( void * ) V_39 [ ( V_7 * 2 ) + 0 ] . V_47 . V_202 ) ;
V_39 [ ( V_7 * 2 ) + 0 ] . V_47 . V_202 = 0 ;
}
if ( V_39 [ ( V_7 * 2 ) + 1 ] . V_47 . V_202 ) {
F_86 ( ( void * ) V_39 [ ( V_7 * 2 ) + 1 ] . V_47 . V_202 ) ;
V_39 [ ( V_7 * 2 ) + 1 ] . V_47 . V_202 = 0 ;
}
}
F_87 ( & V_213 ) ;
}
