static unsigned short F_1 ( struct V_1 * V_2 ,
unsigned short V_3 ,
int V_4 )
{
int V_5 ;
unsigned short V_6 , V_7 ;
T_1 V_8 = 0 ;
if ( F_2 ( V_4 != V_9 &&
V_4 != V_10 ) )
return 0xffff ;
V_2 -> V_11 ( V_2 , 1 ) ;
if ( V_4 == V_10 )
V_8 = V_12 ;
F_3 ( V_2 , V_13 + V_8 ) ;
V_7 = F_3 ( V_2 , V_14 ) ;
if ( ( V_7 & V_15 ) == 0 ) {
F_4 ( V_16 L_1 , V_7 ) ;
F_5 ( V_2 , V_14 , ( V_7 & ( ~ V_17 ) ) | V_15 ) ;
F_6 ( 50 ) ;
V_7 = F_3 ( V_2 , V_14 + V_8 ) ;
F_5 ( V_2 , V_14 , V_7 | V_17 | V_15 ) ;
}
F_5 ( V_2 , V_18 , V_3 ) ;
F_5 ( V_2 , V_19 , 0 ) ;
if ( V_4 == V_9 ) {
F_5 ( V_2 , V_14 , V_20 |
V_15 | V_17 |
V_21 ) ;
F_5 ( V_2 , V_14 , V_22 | V_20 |
V_15 | V_17 |
V_21 ) ;
} else {
F_5 ( V_2 , V_14 , V_22 | V_23 |
V_20 | V_15 | V_17 |
V_21 ) ;
}
for ( V_5 = 0 ; V_5 < 1000 ; V_5 ++ ) {
F_7 ( 10 ) ;
if ( ! ( F_3 ( V_2 , V_14 ) & V_22 ) )
goto V_24;
}
F_4 ( V_25 L_2 , V_3 ) ;
V_6 = 0xffff ;
goto V_26;
V_24:
for ( V_5 = 0 ; V_5 < 100 ; V_5 ++ ) {
if ( F_3 ( V_2 , V_27 + V_8 ) & V_28 )
goto V_29;
F_7 ( 10 ) ;
}
F_4 ( V_25 L_3 , V_4 , V_3 ) ;
V_6 = 0xffff ;
goto V_26;
V_29:
#if 0
printk(KERN_DEBUG "e) reg = 0x%x, val = 0x%x, BA0_ACCAD = 0x%x\n", reg,
snd_cs46xx_peekBA0(chip, BA0_ACSDA),
snd_cs46xx_peekBA0(chip, BA0_ACCAD));
#endif
V_6 = F_3 ( V_2 , V_13 + V_8 ) ;
V_26:
V_2 -> V_11 ( V_2 , - 1 ) ;
return V_6 ;
}
static unsigned short F_8 ( struct V_30 * V_31 ,
unsigned short V_3 )
{
struct V_1 * V_2 = V_31 -> V_32 ;
unsigned short V_33 ;
int V_4 = V_31 -> V_34 ;
if ( F_2 ( V_4 != V_9 &&
V_4 != V_10 ) )
return 0xffff ;
V_33 = F_1 ( V_2 , V_3 , V_4 ) ;
return V_33 ;
}
static void F_9 ( struct V_1 * V_2 ,
unsigned short V_3 ,
unsigned short V_33 ,
int V_4 )
{
int V_5 ;
if ( F_2 ( V_4 != V_9 &&
V_4 != V_10 ) )
return;
V_2 -> V_11 ( V_2 , 1 ) ;
F_5 ( V_2 , V_18 , V_3 ) ;
F_5 ( V_2 , V_19 , V_33 ) ;
F_3 ( V_2 , V_14 ) ;
if ( V_4 == V_9 ) {
F_5 ( V_2 , V_14 , V_15 |
V_17 | V_21 ) ;
F_5 ( V_2 , V_14 , V_22 | V_15 |
V_17 | V_21 ) ;
} else {
F_5 ( V_2 , V_14 , V_22 | V_23 |
V_15 | V_17 | V_21 ) ;
}
for ( V_5 = 0 ; V_5 < 4000 ; V_5 ++ ) {
F_7 ( 10 ) ;
if ( ! ( F_3 ( V_2 , V_14 ) & V_22 ) ) {
goto V_26;
}
}
F_4 ( V_25 L_4 , V_4 , V_3 , V_33 ) ;
V_26:
V_2 -> V_11 ( V_2 , - 1 ) ;
}
static void F_10 ( struct V_30 * V_31 ,
unsigned short V_3 ,
unsigned short V_33 )
{
struct V_1 * V_2 = V_31 -> V_32 ;
int V_4 = V_31 -> V_34 ;
if ( F_2 ( V_4 != V_9 &&
V_4 != V_10 ) )
return;
F_9 ( V_2 , V_3 , V_33 , V_4 ) ;
}
int F_11 ( struct V_1 * V_2 ,
T_1 * V_35 ,
unsigned long V_8 ,
unsigned long V_36 )
{
void T_2 * V_37 ;
unsigned int V_38 = V_8 >> 16 ;
V_8 = V_8 & 0xffff ;
if ( F_2 ( ( V_8 & 3 ) || ( V_36 & 3 ) ) )
return - V_39 ;
V_37 = V_2 -> V_40 . V_41 [ V_38 + 1 ] . V_42 + V_8 ;
V_36 /= sizeof( T_1 ) ;
while ( V_36 -- > 0 ) {
F_12 ( * V_35 ++ , V_37 ) ;
V_37 += sizeof( T_1 ) ;
}
return 0 ;
}
int F_13 ( struct V_1 * V_2 ,
unsigned long V_8 ,
unsigned long V_36 )
{
void T_2 * V_37 ;
unsigned int V_38 = V_8 >> 16 ;
V_8 = V_8 & 0xffff ;
if ( F_2 ( ( V_8 & 3 ) || ( V_36 & 3 ) ) )
return - V_39 ;
V_37 = V_2 -> V_40 . V_41 [ V_38 + 1 ] . V_42 + V_8 ;
V_36 /= sizeof( T_1 ) ;
while ( V_36 -- > 0 ) {
F_12 ( 0 , V_37 ) ;
V_37 += sizeof( T_1 ) ;
}
return 0 ;
}
int F_14 ( struct V_1 * V_2 )
{
int V_41 , V_43 ;
unsigned long V_8 = 0 ;
for ( V_41 = 0 ; V_41 < V_44 ; V_41 ++ ) {
if ( ( V_43 = F_11 ( V_2 ,
& V_45 . V_46 [ V_8 ] ,
V_45 . V_47 [ V_41 ] . V_8 ,
V_45 . V_47 [ V_41 ] . V_48 ) ) < 0 )
return V_43 ;
V_8 += V_45 . V_47 [ V_41 ] . V_48 >> 2 ;
}
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
int V_41 ;
F_16 ( V_2 , V_49 , V_50 ) ;
F_16 ( V_2 , V_49 , V_51 ) ;
for ( V_41 = 0 ; V_41 < 8 ; V_41 ++ ) {
F_16 ( V_2 , V_52 , V_53 + V_41 ) ;
F_16 ( V_2 , V_54 , 0xFFFF ) ;
}
F_16 ( V_2 , V_52 , 0 ) ;
F_16 ( V_2 , V_55 , 0xadf ) ;
}
static int F_17 ( struct V_1 * V_2 , int V_56 )
{
T_1 V_57 , V_58 = 0 ;
for( V_57 = 0 ; V_57 < 50 ; V_57 ++ ) {
V_58 = F_3 ( V_2 , V_59 ) ;
if( ! ( V_58 & V_60 ) )
break;
F_18 ( V_56 ) ;
}
if( V_58 & V_60 ) {
F_4 ( V_25 L_5
L_6 ) ;
return - V_39 ;
}
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
int V_41 , V_61 = 0 ;
unsigned int V_7 ;
V_7 = F_3 ( V_2 , V_62 ) ;
if ( ! ( V_7 & V_63 ) ) {
F_5 ( V_2 , V_62 , V_7 | V_63 ) ;
V_61 = 1 ;
}
F_5 ( V_2 , V_64 , 0 ) ;
for ( V_41 = 0 ; V_41 < 0xFF ; V_41 ++ ) {
if ( F_17 ( V_2 , 1 ) ) {
F_20 ( L_7 , V_41 ) ;
if ( V_61 )
F_5 ( V_2 , V_62 , V_7 ) ;
break;
}
F_5 ( V_2 , V_65 , V_41 ) ;
F_5 ( V_2 , V_66 , V_67 ) ;
}
if ( V_61 )
F_5 ( V_2 , V_62 , V_7 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
int V_68 ;
F_16 ( V_2 , V_55 , 0xadf ) ;
F_16 ( V_2 , V_49 , V_69 | V_70 | V_51 ) ;
for ( V_68 = 0 ; V_68 < 25 ; V_68 ++ ) {
F_7 ( 50 ) ;
if ( ! ( F_22 ( V_2 , V_49 ) & V_70 ) )
break;
}
if ( F_22 ( V_2 , V_49 ) & V_70 )
F_4 ( V_25 L_8 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
F_16 ( V_2 , V_49 , 0 ) ;
}
static void F_24 ( struct V_1 * V_2 , unsigned int V_71 )
{
unsigned long V_72 ;
unsigned int V_73 , V_74 ;
unsigned int V_75 ;
unsigned int V_76 , V_77 ;
V_73 = V_71 << 16 ;
V_75 = V_73 / 48000 ;
V_73 -= V_75 * 48000 ;
V_73 <<= 10 ;
V_75 <<= 10 ;
V_74 = V_73 / 48000 ;
V_75 += V_74 ;
V_73 -= V_74 * 48000 ;
V_76 = V_73 / V_78 ;
V_73 -= V_76 * V_78 ;
V_77 = V_73 ;
F_25 ( & V_2 -> V_79 , V_72 ) ;
F_16 ( V_2 , V_80 ,
( ( V_77 << 16 ) & 0xFFFF0000 ) | ( V_76 & 0xFFFF ) ) ;
F_16 ( V_2 , V_81 , V_75 ) ;
F_26 ( & V_2 -> V_79 , V_72 ) ;
}
static void F_27 ( struct V_1 * V_2 , unsigned int V_71 )
{
unsigned long V_72 ;
unsigned int V_75 , V_82 , V_73 , V_74 ;
unsigned int V_76 , V_77 , V_83 ;
unsigned int V_84 , V_68 ;
if ( ( V_71 * 9 ) < 48000 )
V_71 = 48000 / 9 ;
if ( V_71 > 48000 )
V_71 = 48000 ;
V_73 = V_71 << 16 ;
V_82 = V_73 / 48000 ;
V_73 -= V_82 * 48000 ;
V_73 <<= 7 ;
V_82 <<= 7 ;
V_82 += V_73 / 48000 ;
V_82 ^= 0xFFFFFFFF ;
V_82 ++ ;
V_73 = 48000 << 16 ;
V_75 = V_73 / V_71 ;
V_73 -= V_75 * V_71 ;
V_73 <<= 10 ;
V_75 <<= 10 ;
V_74 = V_73 / V_71 ;
V_75 += V_74 ;
V_73 -= V_74 * V_71 ;
V_76 = V_73 / V_78 ;
V_73 -= V_76 * V_78 ;
V_77 = V_73 ;
V_83 = ( ( 48000 * 24 ) + V_71 - 1 ) / V_71 ;
F_25 ( & V_2 -> V_79 , V_72 ) ;
F_16 ( V_2 , V_85 ,
( ( V_77 << 16 ) & 0xFFFF0000 ) | ( V_76 & 0xFFFF ) ) ;
F_16 ( V_2 , V_86 , V_82 ) ;
F_16 ( V_2 , V_87 ,
( ( ( V_88 + ( V_83 << 2 ) ) << 16 ) & 0xFFFF0000 ) | 0x80 ) ;
F_16 ( V_2 , V_89 , V_75 ) ;
F_26 ( & V_2 -> V_79 , V_72 ) ;
V_84 = 1 ;
for ( V_68 = 2 ; V_68 <= 64 ; V_68 *= 2 ) {
if ( ( ( V_71 / V_68 ) * V_68 ) != V_71 )
V_84 *= 2 ;
}
if ( ( ( V_71 / 3 ) * 3 ) != V_71 ) {
V_84 *= 3 ;
}
for ( V_68 = 5 ; V_68 <= 125 ; V_68 *= 5 ) {
if ( ( ( V_71 / V_68 ) * V_68 ) != V_71 )
V_84 *= 5 ;
}
F_25 ( & V_2 -> V_79 , V_72 ) ;
F_16 ( V_2 , V_90 , V_84 ) ;
F_16 ( V_2 , V_91 , ( 0x00800000 | V_84 ) ) ;
F_16 ( V_2 , V_92 , 0x0000FFFF ) ;
F_16 ( V_2 , V_93 , ( ( 65536 * V_71 ) / 24000 ) ) ;
F_16 ( V_2 , ( V_93 + 4 ) , 0x0000FFFF ) ;
F_26 ( & V_2 -> V_79 , V_72 ) ;
}
static void F_28 ( struct V_94 * V_95 ,
struct V_96 * V_97 , T_3 V_98 )
{
struct V_99 * V_100 = V_95 -> V_100 ;
struct V_101 * V_102 = V_100 -> V_32 ;
memcpy ( V_102 -> V_103 . V_104 + V_97 -> V_105 , V_100 -> V_106 + V_97 -> V_107 , V_98 ) ;
}
static int F_29 ( struct V_94 * V_95 )
{
struct V_99 * V_100 = V_95 -> V_100 ;
struct V_101 * V_102 = V_100 -> V_32 ;
F_30 ( V_95 , & V_102 -> V_108 , F_28 ) ;
return 0 ;
}
static void F_31 ( struct V_94 * V_95 ,
struct V_96 * V_97 , T_3 V_98 )
{
struct V_1 * V_2 = F_32 ( V_95 ) ;
struct V_99 * V_100 = V_95 -> V_100 ;
memcpy ( V_100 -> V_106 + V_97 -> V_107 ,
V_2 -> V_109 . V_103 . V_104 + V_97 -> V_105 , V_98 ) ;
}
static int F_33 ( struct V_94 * V_95 )
{
struct V_1 * V_2 = F_32 ( V_95 ) ;
F_34 ( V_95 , & V_2 -> V_109 . V_108 , F_31 ) ;
return 0 ;
}
static T_4 F_35 ( struct V_94 * V_95 )
{
struct V_1 * V_2 = F_32 ( V_95 ) ;
T_3 V_110 ;
struct V_101 * V_102 = V_95 -> V_100 -> V_32 ;
if ( F_2 ( ! V_102 -> V_111 ) )
return - V_112 ;
#ifdef F_36
V_110 = F_22 ( V_2 , ( V_102 -> V_111 -> V_113 -> V_114 + 2 ) << 2 ) ;
#else
V_110 = F_22 ( V_2 , V_115 ) ;
#endif
V_110 -= V_102 -> V_103 . V_116 ;
return V_110 >> V_102 -> V_117 ;
}
static T_4 F_37 ( struct V_94 * V_95 )
{
struct V_1 * V_2 = F_32 ( V_95 ) ;
T_3 V_110 ;
struct V_101 * V_102 = V_95 -> V_100 -> V_32 ;
#ifdef F_36
if ( F_2 ( ! V_102 -> V_111 ) )
return - V_112 ;
V_110 = F_22 ( V_2 , ( V_102 -> V_111 -> V_113 -> V_114 + 2 ) << 2 ) ;
#else
V_110 = F_22 ( V_2 , V_115 ) ;
#endif
V_110 -= V_102 -> V_103 . V_116 ;
return F_38 ( V_95 , & V_102 -> V_108 , V_110 ) ;
}
static T_4 F_39 ( struct V_94 * V_95 )
{
struct V_1 * V_2 = F_32 ( V_95 ) ;
T_3 V_110 = F_22 ( V_2 , V_118 ) - V_2 -> V_109 . V_103 . V_116 ;
return V_110 >> V_2 -> V_109 . V_117 ;
}
static T_4 F_40 ( struct V_94 * V_95 )
{
struct V_1 * V_2 = F_32 ( V_95 ) ;
T_3 V_110 = F_22 ( V_2 , V_118 ) - V_2 -> V_109 . V_103 . V_116 ;
return F_41 ( V_95 , & V_2 -> V_109 . V_108 , V_110 ) ;
}
static int F_42 ( struct V_94 * V_95 ,
int V_119 )
{
struct V_1 * V_2 = F_32 ( V_95 ) ;
int V_6 = 0 ;
#ifdef F_36
struct V_101 * V_102 = V_95 -> V_100 -> V_32 ;
if ( ! V_102 -> V_111 ) {
return - V_112 ;
}
#endif
switch ( V_119 ) {
case V_120 :
case V_121 :
#ifdef F_36
F_16 ( V_2 , ( V_102 -> V_111 -> V_113 -> V_114 +
V_122 ) << 2 , 0x80008000 ) ;
if ( V_102 -> V_111 -> V_123 )
F_43 ( V_2 , V_102 -> V_111 ) ;
if ( V_95 -> V_100 -> V_124 != V_125 )
F_29 ( V_95 ) ;
#else
F_44 ( & V_2 -> V_79 ) ;
if ( V_95 -> V_100 -> V_124 != V_125 )
F_29 ( V_95 ) ;
{ unsigned int V_7 ;
V_7 = F_22 ( V_2 , V_126 ) ;
V_7 &= 0x0000ffff ;
F_16 ( V_2 , V_126 , V_2 -> V_127 | V_7 ) ;
}
F_45 ( & V_2 -> V_79 ) ;
#endif
break;
case V_128 :
case V_129 :
#ifdef F_36
F_16 ( V_2 , ( V_102 -> V_111 -> V_113 -> V_114 +
V_122 ) << 2 , 0xffffffff ) ;
if ( ! V_102 -> V_111 -> V_123 )
F_46 ( V_2 , V_102 -> V_111 ) ;
#else
F_44 ( & V_2 -> V_79 ) ;
{ unsigned int V_7 ;
V_7 = F_22 ( V_2 , V_126 ) ;
V_7 &= 0x0000ffff ;
F_16 ( V_2 , V_126 , V_7 ) ;
}
F_45 ( & V_2 -> V_79 ) ;
#endif
break;
default:
V_6 = - V_39 ;
break;
}
return V_6 ;
}
static int F_47 ( struct V_94 * V_95 ,
int V_119 )
{
struct V_1 * V_2 = F_32 ( V_95 ) ;
unsigned int V_7 ;
int V_6 = 0 ;
F_44 ( & V_2 -> V_79 ) ;
switch ( V_119 ) {
case V_120 :
case V_121 :
V_7 = F_22 ( V_2 , V_130 ) ;
V_7 &= 0xffff0000 ;
F_16 ( V_2 , V_130 , V_2 -> V_109 . V_131 | V_7 ) ;
break;
case V_128 :
case V_129 :
V_7 = F_22 ( V_2 , V_130 ) ;
V_7 &= 0xffff0000 ;
F_16 ( V_2 , V_130 , V_7 ) ;
break;
default:
V_6 = - V_39 ;
break;
}
F_45 ( & V_2 -> V_79 ) ;
return V_6 ;
}
static int F_48 ( struct V_1 * V_2 , struct V_101 * V_102 ,
int V_132 )
{
if ( V_102 -> V_111 == NULL ) {
V_102 -> V_111 = F_49 ( V_2 , V_132 ,
V_102 , V_102 -> V_103 . V_116 , V_102 -> V_133 ) ;
if ( V_102 -> V_111 == NULL ) {
F_4 ( V_25 L_9 ) ;
return - V_134 ;
}
V_102 -> V_111 -> V_132 = V_132 ;
} else
if ( ( int ) V_102 -> V_111 -> V_132 != V_132 ) {
int V_123 = V_102 -> V_111 -> V_123 ;
F_50 ( V_2 , V_102 -> V_111 ) ;
if ( ( V_102 -> V_111 = F_49 ( V_2 , V_132 , V_102 ,
V_102 -> V_103 . V_116 ,
V_102 -> V_133 ) ) == NULL ) {
F_4 ( V_25 L_10 ) ;
return - V_134 ;
}
if ( ! V_123 ) F_43 ( V_2 , V_102 -> V_111 ) ;
V_102 -> V_111 -> V_132 = V_132 ;
}
return 0 ;
}
static int F_51 ( struct V_94 * V_95 ,
struct V_135 * V_136 )
{
struct V_99 * V_100 = V_95 -> V_100 ;
struct V_101 * V_102 ;
int V_43 ;
#ifdef F_36
struct V_1 * V_2 = F_32 ( V_95 ) ;
int V_132 = F_52 ( V_136 ) ;
int V_137 = F_53 ( V_136 ) ;
#endif
V_102 = V_100 -> V_32 ;
#ifdef F_36
if ( F_2 ( ! V_132 ) )
return - V_112 ;
F_54 ( & V_2 -> V_138 ) ;
if ( F_48 ( V_2 , V_102 , V_132 ) ) {
F_55 ( & V_2 -> V_138 ) ;
return - V_112 ;
}
F_2 ( ! V_102 -> V_111 ) ;
if ( ! V_102 -> V_111 ) {
F_55 ( & V_2 -> V_138 ) ;
return - V_112 ;
}
if ( F_56 ( V_2 , V_102 -> V_111 , V_137 ) ) {
F_55 ( & V_2 -> V_138 ) ;
return - V_39 ;
}
F_20 ( L_11 ,
V_137 , F_57 ( V_136 ) ,
F_58 ( V_136 ) ) ;
#endif
if ( F_57 ( V_136 ) == V_125 ) {
if ( V_100 -> V_106 != V_102 -> V_103 . V_104 )
F_59 ( V_95 ) ;
V_100 -> V_106 = V_102 -> V_103 . V_104 ;
V_100 -> V_139 = V_102 -> V_103 . V_116 ;
V_100 -> V_140 = V_102 -> V_103 . V_98 ;
#ifdef F_36
if ( V_102 -> V_133 == V_141 ) {
V_95 -> V_142 = & V_143 ;
} else if ( V_102 -> V_133 == V_144 ) {
V_95 -> V_142 = & V_145 ;
} else if ( V_102 -> V_133 == V_146 ) {
V_95 -> V_142 = & V_147 ;
} else if ( V_102 -> V_133 == V_148 ) {
V_95 -> V_142 = & V_149 ;
} else {
F_60 () ;
}
#else
V_95 -> V_142 = & V_143 ;
#endif
} else {
if ( V_100 -> V_106 == V_102 -> V_103 . V_104 ) {
V_100 -> V_106 = NULL ;
V_100 -> V_139 = 0 ;
V_100 -> V_140 = 0 ;
}
if ( ( V_43 = F_61 ( V_95 , F_58 ( V_136 ) ) ) < 0 ) {
#ifdef F_36
F_55 ( & V_2 -> V_138 ) ;
#endif
return V_43 ;
}
#ifdef F_36
if ( V_102 -> V_133 == V_141 ) {
V_95 -> V_142 = & V_150 ;
} else if ( V_102 -> V_133 == V_144 ) {
V_95 -> V_142 = & V_151 ;
} else if ( V_102 -> V_133 == V_146 ) {
V_95 -> V_142 = & V_152 ;
} else if ( V_102 -> V_133 == V_148 ) {
V_95 -> V_142 = & V_153 ;
} else {
F_60 () ;
}
#else
V_95 -> V_142 = & V_150 ;
#endif
}
#ifdef F_36
F_55 ( & V_2 -> V_138 ) ;
#endif
return 0 ;
}
static int F_62 ( struct V_94 * V_95 )
{
struct V_99 * V_100 = V_95 -> V_100 ;
struct V_101 * V_102 ;
V_102 = V_100 -> V_32 ;
if ( ! V_102 ) return - V_112 ;
if ( V_100 -> V_106 != V_102 -> V_103 . V_104 )
F_59 ( V_95 ) ;
V_100 -> V_106 = NULL ;
V_100 -> V_139 = 0 ;
V_100 -> V_140 = 0 ;
return 0 ;
}
static int F_63 ( struct V_94 * V_95 )
{
unsigned int V_7 ;
unsigned int V_154 ;
struct V_1 * V_2 = F_32 ( V_95 ) ;
struct V_99 * V_100 = V_95 -> V_100 ;
struct V_101 * V_102 ;
V_102 = V_100 -> V_32 ;
#ifdef F_36
if ( F_2 ( ! V_102 -> V_111 ) )
return - V_112 ;
V_154 = F_22 ( V_2 , ( V_102 -> V_111 -> V_113 -> V_114 + 1 ) << 2 ) ;
V_154 &= ~ 0x0000f03f ;
#else
V_154 = F_22 ( V_2 , V_155 ) ;
V_154 &= ~ 0x0000f03f ;
#endif
V_102 -> V_117 = 2 ;
if ( V_100 -> V_156 == 1 ) {
V_102 -> V_117 -- ;
V_154 |= 0x00002000 ;
}
if ( F_64 ( V_100 -> V_157 ) == 8 ) {
V_102 -> V_117 -- ;
V_154 |= 0x00001000 ;
}
if ( F_65 ( V_100 -> V_157 ) )
V_154 |= 0x00008000 ;
if ( F_64 ( V_100 -> V_157 ) != 8 ) {
if ( F_66 ( V_100 -> V_157 ) )
V_154 |= 0x00004000 ;
}
memset ( & V_102 -> V_108 , 0 , sizeof( V_102 -> V_108 ) ) ;
V_102 -> V_108 . V_158 = F_67 ( V_95 ) ;
V_102 -> V_108 . V_159 = V_100 -> V_137 * V_125 << V_102 -> V_117 ;
#ifdef F_36
V_7 = F_22 ( V_2 , ( V_102 -> V_111 -> V_113 -> V_114 ) << 2 ) ;
V_7 &= ~ 0x000003ff ;
V_7 |= ( 4 << V_102 -> V_117 ) - 1 ;
F_16 ( V_2 , ( V_102 -> V_111 -> V_113 -> V_114 ) << 2 , V_7 ) ;
F_16 ( V_2 , ( V_102 -> V_111 -> V_113 -> V_114 + 1 ) << 2 , V_154 | V_102 -> V_111 -> V_160 ) ;
#else
F_16 ( V_2 , V_115 , V_102 -> V_103 . V_116 ) ;
V_7 = F_22 ( V_2 , V_161 ) ;
V_7 &= ~ 0x000003ff ;
V_7 |= ( 4 << V_102 -> V_117 ) - 1 ;
F_16 ( V_2 , V_161 , V_7 ) ;
F_16 ( V_2 , V_155 , V_154 ) ;
F_24 ( V_2 , V_100 -> V_71 ) ;
#endif
return 0 ;
}
static int F_68 ( struct V_94 * V_95 ,
struct V_135 * V_136 )
{
struct V_1 * V_2 = F_32 ( V_95 ) ;
struct V_99 * V_100 = V_95 -> V_100 ;
int V_43 ;
#ifdef F_36
F_69 ( V_2 , F_53 ( V_136 ) ) ;
#endif
if ( V_100 -> V_124 == V_125 ) {
if ( V_100 -> V_106 != V_2 -> V_109 . V_103 . V_104 )
F_59 ( V_95 ) ;
V_100 -> V_106 = V_2 -> V_109 . V_103 . V_104 ;
V_100 -> V_139 = V_2 -> V_109 . V_103 . V_116 ;
V_100 -> V_140 = V_2 -> V_109 . V_103 . V_98 ;
V_95 -> V_142 = & V_162 ;
} else {
if ( V_100 -> V_106 == V_2 -> V_109 . V_103 . V_104 ) {
V_100 -> V_106 = NULL ;
V_100 -> V_139 = 0 ;
V_100 -> V_140 = 0 ;
}
if ( ( V_43 = F_61 ( V_95 , F_58 ( V_136 ) ) ) < 0 )
return V_43 ;
V_95 -> V_142 = & V_163 ;
}
return 0 ;
}
static int F_70 ( struct V_94 * V_95 )
{
struct V_1 * V_2 = F_32 ( V_95 ) ;
struct V_99 * V_100 = V_95 -> V_100 ;
if ( V_100 -> V_106 != V_2 -> V_109 . V_103 . V_104 )
F_59 ( V_95 ) ;
V_100 -> V_106 = NULL ;
V_100 -> V_139 = 0 ;
V_100 -> V_140 = 0 ;
return 0 ;
}
static int F_71 ( struct V_94 * V_95 )
{
struct V_1 * V_2 = F_32 ( V_95 ) ;
struct V_99 * V_100 = V_95 -> V_100 ;
F_16 ( V_2 , V_118 , V_2 -> V_109 . V_103 . V_116 ) ;
V_2 -> V_109 . V_117 = 2 ;
memset ( & V_2 -> V_109 . V_108 , 0 , sizeof( V_2 -> V_109 . V_108 ) ) ;
V_2 -> V_109 . V_108 . V_158 = F_67 ( V_95 ) ;
V_2 -> V_109 . V_108 . V_159 = V_100 -> V_137 * V_125 << 2 ;
F_27 ( V_2 , V_100 -> V_71 ) ;
return 0 ;
}
static T_5 F_72 ( int V_164 , void * V_165 )
{
struct V_1 * V_2 = V_165 ;
T_1 V_166 ;
#ifdef F_36
struct V_167 * V_168 = V_2 -> V_167 ;
T_1 V_169 ;
int V_57 ;
struct V_101 * V_102 = NULL ;
#endif
V_166 = F_3 ( V_2 , V_170 ) ;
if ( ( V_166 & 0x7fffffff ) == 0 ) {
F_5 ( V_2 , V_171 , V_172 | V_173 ) ;
return V_174 ;
}
#ifdef F_36
V_169 = F_3 ( V_2 , V_175 ) ;
for ( V_57 = 0 ; V_57 < V_176 ; ++ V_57 ) {
if ( V_57 <= 15 ) {
if ( V_166 & ( 1 << V_57 ) ) {
if ( V_57 == V_177 ) {
if ( V_2 -> V_109 . V_95 )
F_73 ( V_2 -> V_109 . V_95 ) ;
} else {
if ( V_168 -> V_178 [ V_57 ] . V_179 &&
V_168 -> V_178 [ V_57 ] . V_32 &&
! V_168 -> V_178 [ V_57 ] . V_123 ) {
V_102 = V_168 -> V_178 [ V_57 ] . V_32 ;
F_73 ( V_102 -> V_95 ) ;
}
}
}
} else {
if ( V_169 & ( 1 << ( V_57 - 16 ) ) ) {
if ( V_168 -> V_178 [ V_57 ] . V_179 &&
V_168 -> V_178 [ V_57 ] . V_32 &&
! V_168 -> V_178 [ V_57 ] . V_123 ) {
V_102 = V_168 -> V_178 [ V_57 ] . V_32 ;
F_73 ( V_102 -> V_95 ) ;
}
}
}
}
#else
if ( ( V_166 & V_180 ) && V_2 -> V_181 ) {
if ( V_2 -> V_181 -> V_95 )
F_73 ( V_2 -> V_181 -> V_95 ) ;
}
if ( ( V_166 & V_182 ) && V_2 -> V_183 ) {
if ( V_2 -> V_109 . V_95 )
F_73 ( V_2 -> V_109 . V_95 ) ;
}
#endif
if ( ( V_166 & V_184 ) && V_2 -> V_185 ) {
unsigned char V_186 ;
F_44 ( & V_2 -> V_79 ) ;
while ( ( F_3 ( V_2 , V_187 ) & V_188 ) == 0 ) {
V_186 = F_3 ( V_2 , V_189 ) ;
if ( ( V_2 -> V_190 & V_191 ) == 0 )
continue;
F_74 ( V_2 -> V_192 , & V_186 , 1 ) ;
}
while ( ( F_3 ( V_2 , V_187 ) & V_193 ) == 0 ) {
if ( ( V_2 -> V_190 & V_194 ) == 0 )
break;
if ( F_75 ( V_2 -> V_195 , & V_186 , 1 ) != 1 ) {
V_2 -> V_190 &= ~ V_194 ;
F_5 ( V_2 , V_196 , V_2 -> V_190 ) ;
break;
}
F_5 ( V_2 , V_197 , V_186 ) ;
}
F_45 ( & V_2 -> V_79 ) ;
}
F_5 ( V_2 , V_171 , V_172 | V_173 ) ;
return V_198 ;
}
static void F_76 ( struct V_99 * V_100 )
{
F_77 ( V_100 -> V_32 ) ;
}
static int F_78 ( struct V_94 * V_95 , int V_133 )
{
struct V_1 * V_2 = F_32 ( V_95 ) ;
struct V_101 * V_102 ;
struct V_99 * V_100 = V_95 -> V_100 ;
V_102 = F_79 ( sizeof( * V_102 ) , V_199 ) ;
if ( V_102 == NULL )
return - V_134 ;
if ( F_80 ( V_200 , F_81 ( V_2 -> V_201 ) ,
V_202 , & V_102 -> V_103 ) < 0 ) {
F_77 ( V_102 ) ;
return - V_134 ;
}
V_100 -> V_203 = V_204 ;
V_100 -> V_32 = V_102 ;
V_100 -> V_205 = F_76 ;
V_102 -> V_95 = V_95 ;
#ifdef F_36
F_54 ( & V_2 -> V_138 ) ;
V_102 -> V_111 = NULL ;
V_102 -> V_133 = V_133 ;
F_82 ( V_100 , 0 ,
V_206 ,
& V_207 ) ;
F_55 ( & V_2 -> V_138 ) ;
#else
V_2 -> V_181 = V_102 ;
#endif
if ( V_2 -> V_208 )
V_95 -> V_100 -> V_203 . V_209 |= V_210 ;
V_2 -> V_11 ( V_2 , 1 ) ;
return 0 ;
}
static int F_83 ( struct V_94 * V_95 )
{
F_20 ( L_12 ) ;
return F_78 ( V_95 , V_141 ) ;
}
static int F_84 ( struct V_94 * V_95 )
{
F_20 ( L_13 ) ;
return F_78 ( V_95 , V_144 ) ;
}
static int F_85 ( struct V_94 * V_95 )
{
F_20 ( L_14 ) ;
return F_78 ( V_95 , V_146 ) ;
}
static int F_86 ( struct V_94 * V_95 )
{
struct V_1 * V_2 = F_32 ( V_95 ) ;
F_20 ( L_15 ) ;
F_54 ( & V_2 -> V_138 ) ;
F_87 ( V_2 ) ;
F_55 ( & V_2 -> V_138 ) ;
return F_78 ( V_95 , V_148 ) ;
}
static int F_88 ( struct V_94 * V_95 )
{
int V_43 ;
struct V_1 * V_2 = F_32 ( V_95 ) ;
F_20 ( L_16 ) ;
V_43 = F_89 ( V_95 ) ;
F_54 ( & V_2 -> V_138 ) ;
F_90 ( V_2 ) ;
F_55 ( & V_2 -> V_138 ) ;
return V_43 ;
}
static int F_91 ( struct V_94 * V_95 )
{
struct V_1 * V_2 = F_32 ( V_95 ) ;
if ( F_80 ( V_200 , F_81 ( V_2 -> V_201 ) ,
V_202 , & V_2 -> V_109 . V_103 ) < 0 )
return - V_134 ;
V_2 -> V_109 . V_95 = V_95 ;
V_95 -> V_100 -> V_203 = V_211 ;
if ( V_2 -> V_208 )
V_95 -> V_100 -> V_203 . V_209 |= V_210 ;
V_2 -> V_11 ( V_2 , 1 ) ;
#ifdef F_36
F_82 ( V_95 -> V_100 , 0 ,
V_206 ,
& V_207 ) ;
#endif
return 0 ;
}
static int F_89 ( struct V_94 * V_95 )
{
struct V_1 * V_2 = F_32 ( V_95 ) ;
struct V_99 * V_100 = V_95 -> V_100 ;
struct V_101 * V_102 ;
V_102 = V_100 -> V_32 ;
if ( ! V_102 ) return - V_112 ;
#ifdef F_36
F_54 ( & V_2 -> V_138 ) ;
if ( V_102 -> V_111 ) {
F_50 ( V_2 , V_102 -> V_111 ) ;
V_102 -> V_111 = NULL ;
}
F_55 ( & V_2 -> V_138 ) ;
#else
V_2 -> V_181 = NULL ;
#endif
V_102 -> V_95 = NULL ;
F_92 ( & V_102 -> V_103 ) ;
V_2 -> V_11 ( V_2 , - 1 ) ;
return 0 ;
}
static int F_93 ( struct V_94 * V_95 )
{
struct V_1 * V_2 = F_32 ( V_95 ) ;
V_2 -> V_109 . V_95 = NULL ;
F_92 ( & V_2 -> V_109 . V_103 ) ;
V_2 -> V_11 ( V_2 , - 1 ) ;
return 0 ;
}
int V_101 ( struct V_1 * V_2 , int V_212 , struct V_213 * * V_214 )
{
struct V_213 * V_183 ;
int V_43 ;
if ( V_214 )
* V_214 = NULL ;
if ( ( V_43 = F_94 ( V_2 -> V_215 , L_17 , V_212 , V_216 , 1 , & V_183 ) ) < 0 )
return V_43 ;
V_183 -> V_32 = V_2 ;
F_95 ( V_183 , V_217 , & V_143 ) ;
F_95 ( V_183 , V_218 , & V_162 ) ;
V_183 -> V_219 = 0 ;
strcpy ( V_183 -> V_220 , L_17 ) ;
V_2 -> V_183 = V_183 ;
F_96 ( V_183 , V_200 ,
F_81 ( V_2 -> V_201 ) , 64 * 1024 , 256 * 1024 ) ;
if ( V_214 )
* V_214 = V_183 ;
return 0 ;
}
int F_97 ( struct V_1 * V_2 , int V_212 ,
struct V_213 * * V_214 )
{
struct V_213 * V_183 ;
int V_43 ;
if ( V_214 )
* V_214 = NULL ;
if ( ( V_43 = F_94 ( V_2 -> V_215 , L_18 , V_212 , V_216 , 0 , & V_183 ) ) < 0 )
return V_43 ;
V_183 -> V_32 = V_2 ;
F_95 ( V_183 , V_217 , & V_145 ) ;
V_183 -> V_219 = 0 ;
strcpy ( V_183 -> V_220 , L_18 ) ;
V_2 -> V_221 = V_183 ;
F_96 ( V_183 , V_200 ,
F_81 ( V_2 -> V_201 ) , 64 * 1024 , 256 * 1024 ) ;
if ( V_214 )
* V_214 = V_183 ;
return 0 ;
}
int F_98 ( struct V_1 * V_2 , int V_212 ,
struct V_213 * * V_214 )
{
struct V_213 * V_183 ;
int V_43 ;
if ( V_214 )
* V_214 = NULL ;
if ( ( V_43 = F_94 ( V_2 -> V_215 , L_19 , V_212 , V_216 , 0 , & V_183 ) ) < 0 )
return V_43 ;
V_183 -> V_32 = V_2 ;
F_95 ( V_183 , V_217 , & V_147 ) ;
V_183 -> V_219 = 0 ;
strcpy ( V_183 -> V_220 , L_19 ) ;
V_2 -> V_222 = V_183 ;
F_96 ( V_183 , V_200 ,
F_81 ( V_2 -> V_201 ) , 64 * 1024 , 256 * 1024 ) ;
if ( V_214 )
* V_214 = V_183 ;
return 0 ;
}
int F_99 ( struct V_1 * V_2 , int V_212 ,
struct V_213 * * V_214 )
{
struct V_213 * V_183 ;
int V_43 ;
if ( V_214 )
* V_214 = NULL ;
if ( ( V_43 = F_94 ( V_2 -> V_215 , L_20 , V_212 , 1 , 0 , & V_183 ) ) < 0 )
return V_43 ;
V_183 -> V_32 = V_2 ;
F_95 ( V_183 , V_217 , & V_149 ) ;
V_183 -> V_219 = 0 ;
strcpy ( V_183 -> V_220 , L_20 ) ;
V_2 -> V_221 = V_183 ;
F_96 ( V_183 , V_200 ,
F_81 ( V_2 -> V_201 ) , 64 * 1024 , 256 * 1024 ) ;
if ( V_214 )
* V_214 = V_183 ;
return 0 ;
}
static void F_100 ( struct V_223 * V_224 )
{
struct V_1 * V_2 = V_224 -> V_32 ;
V_2 -> V_225 = NULL ;
}
static void F_101 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_32 ;
if ( F_2 ( V_31 != V_2 -> V_31 [ V_9 ] &&
V_31 != V_2 -> V_31 [ V_10 ] ) )
return;
if ( V_31 == V_2 -> V_31 [ V_9 ] ) {
V_2 -> V_31 [ V_9 ] = NULL ;
V_2 -> V_226 = NULL ;
}
else
V_2 -> V_31 [ V_10 ] = NULL ;
}
static int F_102 ( struct V_227 * V_228 ,
struct V_229 * V_230 )
{
V_230 -> type = V_231 ;
V_230 -> V_5 = 2 ;
V_230 -> V_232 . integer . V_233 = 0 ;
V_230 -> V_232 . integer . V_234 = 0x7fff ;
return 0 ;
}
static int F_103 ( struct V_227 * V_228 , struct V_235 * V_236 )
{
struct V_1 * V_2 = F_104 ( V_228 ) ;
int V_3 = V_228 -> V_237 ;
unsigned int V_33 = F_22 ( V_2 , V_3 ) ;
V_236 -> V_232 . integer . V_232 [ 0 ] = 0xffff - ( V_33 >> 16 ) ;
V_236 -> V_232 . integer . V_232 [ 1 ] = 0xffff - ( V_33 & 0xffff ) ;
return 0 ;
}
static int F_105 ( struct V_227 * V_228 , struct V_235 * V_236 )
{
struct V_1 * V_2 = F_104 ( V_228 ) ;
int V_3 = V_228 -> V_237 ;
unsigned int V_33 = ( ( 0xffff - V_236 -> V_232 . integer . V_232 [ 0 ] ) << 16 |
( 0xffff - V_236 -> V_232 . integer . V_232 [ 1 ] ) ) ;
unsigned int V_238 = F_22 ( V_2 , V_3 ) ;
int V_239 = ( V_238 != V_33 ) ;
if ( V_239 ) {
F_16 ( V_2 , V_3 , V_33 ) ;
}
return V_239 ;
}
static int F_106 ( struct V_227 * V_228 , struct V_235 * V_236 )
{
struct V_1 * V_2 = F_104 ( V_228 ) ;
V_236 -> V_232 . integer . V_232 [ 0 ] = V_2 -> V_167 -> V_240 ;
V_236 -> V_232 . integer . V_232 [ 1 ] = V_2 -> V_167 -> V_241 ;
return 0 ;
}
static int F_107 ( struct V_227 * V_228 , struct V_235 * V_236 )
{
struct V_1 * V_2 = F_104 ( V_228 ) ;
int V_239 = 0 ;
if ( V_2 -> V_167 -> V_241 != V_236 -> V_232 . integer . V_232 [ 0 ] ||
V_2 -> V_167 -> V_240 != V_236 -> V_232 . integer . V_232 [ 1 ] ) {
F_108 ( V_2 ,
V_236 -> V_232 . integer . V_232 [ 0 ] ,
V_236 -> V_232 . integer . V_232 [ 1 ] ) ;
V_239 = 1 ;
}
return V_239 ;
}
static int F_109 ( struct V_227 * V_228 ,
struct V_235 * V_236 )
{
struct V_1 * V_2 = F_104 ( V_228 ) ;
int V_3 = V_228 -> V_237 ;
if ( V_3 == V_242 )
V_236 -> V_232 . integer . V_232 [ 0 ] = ( V_2 -> V_167 -> V_243 & V_244 ) ;
else
V_236 -> V_232 . integer . V_232 [ 0 ] = V_2 -> V_167 -> V_245 ;
return 0 ;
}
static int F_110 ( struct V_227 * V_228 ,
struct V_235 * V_236 )
{
struct V_1 * V_2 = F_104 ( V_228 ) ;
int V_239 , V_246 ;
switch ( V_228 -> V_237 ) {
case V_242 :
F_54 ( & V_2 -> V_138 ) ;
V_239 = ( V_2 -> V_167 -> V_243 & V_244 ) ;
if ( V_236 -> V_232 . integer . V_232 [ 0 ] && ! V_239 )
F_111 ( V_2 ) ;
else if ( V_239 && ! V_236 -> V_232 . integer . V_232 [ 0 ] )
F_112 ( V_2 ) ;
V_246 = ( V_239 != ( V_2 -> V_167 -> V_243 & V_244 ) ) ;
F_55 ( & V_2 -> V_138 ) ;
break;
case V_247 :
V_239 = V_2 -> V_167 -> V_245 ;
if ( V_236 -> V_232 . integer . V_232 [ 0 ] && ! V_239 ) {
F_113 ( V_2 ) ;
}
else if ( V_239 && ! V_236 -> V_232 . integer . V_232 [ 0 ] )
F_114 ( V_2 ) ;
V_246 = ( V_239 != V_2 -> V_167 -> V_245 ) ;
break;
default:
V_246 = - V_39 ;
F_60 () ;
}
return V_246 ;
}
static int F_115 ( struct V_227 * V_228 ,
struct V_235 * V_236 )
{
struct V_1 * V_2 = F_104 ( V_228 ) ;
struct V_167 * V_168 = V_2 -> V_167 ;
if ( V_168 -> V_248 != NULL )
V_236 -> V_232 . integer . V_232 [ 0 ] = 1 ;
else
V_236 -> V_232 . integer . V_232 [ 0 ] = 0 ;
return 0 ;
}
static int F_116 ( struct V_227 * V_228 ,
struct V_235 * V_236 )
{
struct V_1 * V_2 = F_104 ( V_228 ) ;
struct V_167 * V_168 = V_2 -> V_167 ;
int V_239 = 0 ;
if ( V_236 -> V_232 . integer . V_232 [ 0 ] && ! V_168 -> V_248 ) {
F_117 ( V_2 ) ;
V_239 = 1 ;
} else if ( ! V_236 -> V_232 . integer . V_232 [ 0 ] && V_168 -> V_248 ) {
F_118 ( V_2 ) ;
V_239 = 1 ;
}
return V_239 ;
}
static int F_119 ( struct V_227 * V_228 ,
struct V_235 * V_236 )
{
struct V_1 * V_2 = F_104 ( V_228 ) ;
struct V_167 * V_168 = V_2 -> V_167 ;
if ( V_168 -> V_249 != NULL )
V_236 -> V_232 . integer . V_232 [ 0 ] = 1 ;
else
V_236 -> V_232 . integer . V_232 [ 0 ] = 0 ;
return 0 ;
}
static int F_120 ( struct V_227 * V_228 ,
struct V_235 * V_236 )
{
struct V_1 * V_2 = F_104 ( V_228 ) ;
struct V_167 * V_168 = V_2 -> V_167 ;
int V_239 = 0 ;
if ( V_236 -> V_232 . integer . V_232 [ 0 ] && ! V_168 -> V_249 ) {
F_121 ( V_2 ) ;
V_239 = 1 ;
} else if ( ! V_236 -> V_232 . integer . V_232 [ 0 ] && V_168 -> V_249 ) {
F_122 ( V_2 ) ;
V_239 = 1 ;
}
return V_239 ;
}
static int F_123 ( struct V_227 * V_228 ,
struct V_235 * V_236 )
{
struct V_1 * V_2 = F_104 ( V_228 ) ;
int V_250 = F_3 ( V_2 , V_251 ) ;
if ( V_250 & V_252 )
V_236 -> V_232 . integer . V_232 [ 0 ] = 1 ;
else
V_236 -> V_232 . integer . V_232 [ 0 ] = 0 ;
return 0 ;
}
static int F_124 ( struct V_227 * V_228 ,
struct V_235 * V_236 )
{
struct V_1 * V_2 = F_104 ( V_228 ) ;
int V_250 = F_3 ( V_2 , V_251 ) ;
int V_253 = F_3 ( V_2 , V_254 ) ;
if ( V_236 -> V_232 . integer . V_232 [ 0 ] ) {
F_5 ( V_2 , V_251 ,
V_252 | V_250 ) ;
F_5 ( V_2 , V_254 ,
V_255 | V_253 ) ;
} else {
F_5 ( V_2 , V_251 , V_250 & ~ V_252 ) ;
F_5 ( V_2 , V_254 , V_253 & ~ V_255 ) ;
}
return ( V_250 != ( int ) F_3 ( V_2 , V_251 ) ) ;
}
static int F_125 ( struct V_227 * V_228 , struct V_229 * V_230 )
{
V_230 -> type = V_256 ;
V_230 -> V_5 = 1 ;
return 0 ;
}
static int F_126 ( struct V_227 * V_228 ,
struct V_235 * V_236 )
{
struct V_1 * V_2 = F_104 ( V_228 ) ;
struct V_167 * V_168 = V_2 -> V_167 ;
F_54 ( & V_2 -> V_138 ) ;
V_236 -> V_232 . V_257 . V_58 [ 0 ] = F_127 ( ( V_168 -> V_258 >> 24 ) & 0xff ) ;
V_236 -> V_232 . V_257 . V_58 [ 1 ] = F_127 ( ( V_168 -> V_258 >> 16 ) & 0xff ) ;
V_236 -> V_232 . V_257 . V_58 [ 2 ] = 0 ;
V_236 -> V_232 . V_257 . V_58 [ 3 ] = F_127 ( ( V_168 -> V_258 ) & 0xff ) ;
F_55 ( & V_2 -> V_138 ) ;
return 0 ;
}
static int F_128 ( struct V_227 * V_228 ,
struct V_235 * V_236 )
{
struct V_1 * V_2 = F_104 ( V_228 ) ;
struct V_167 * V_168 = V_2 -> V_167 ;
unsigned int V_33 ;
int V_239 ;
F_54 ( & V_2 -> V_138 ) ;
V_33 = ( ( unsigned int ) F_127 ( V_236 -> V_232 . V_257 . V_58 [ 0 ] ) << 24 ) |
( ( unsigned int ) F_127 ( V_236 -> V_232 . V_257 . V_58 [ 2 ] ) << 16 ) |
( ( unsigned int ) F_127 ( V_236 -> V_232 . V_257 . V_58 [ 3 ] ) ) |
( 1 << 13 ) | ( 1 << 12 ) ;
V_239 = ( unsigned int ) V_168 -> V_258 != V_33 ;
V_168 -> V_258 = V_33 ;
if ( ! ( V_168 -> V_243 & V_259 ) )
F_129 ( V_2 , V_260 , V_33 ) ;
F_55 ( & V_2 -> V_138 ) ;
return V_239 ;
}
static int F_130 ( struct V_227 * V_228 ,
struct V_235 * V_236 )
{
V_236 -> V_232 . V_257 . V_58 [ 0 ] = 0xff ;
V_236 -> V_232 . V_257 . V_58 [ 1 ] = 0xff ;
V_236 -> V_232 . V_257 . V_58 [ 2 ] = 0x00 ;
V_236 -> V_232 . V_257 . V_58 [ 3 ] = 0xff ;
return 0 ;
}
static int F_131 ( struct V_227 * V_228 ,
struct V_235 * V_236 )
{
struct V_1 * V_2 = F_104 ( V_228 ) ;
struct V_167 * V_168 = V_2 -> V_167 ;
F_54 ( & V_2 -> V_138 ) ;
V_236 -> V_232 . V_257 . V_58 [ 0 ] = F_127 ( ( V_168 -> V_261 >> 24 ) & 0xff ) ;
V_236 -> V_232 . V_257 . V_58 [ 1 ] = F_127 ( ( V_168 -> V_261 >> 16 ) & 0xff ) ;
V_236 -> V_232 . V_257 . V_58 [ 2 ] = 0 ;
V_236 -> V_232 . V_257 . V_58 [ 3 ] = F_127 ( ( V_168 -> V_261 ) & 0xff ) ;
F_55 ( & V_2 -> V_138 ) ;
return 0 ;
}
static int F_132 ( struct V_227 * V_228 ,
struct V_235 * V_236 )
{
struct V_1 * V_2 = F_104 ( V_228 ) ;
struct V_167 * V_168 = V_2 -> V_167 ;
unsigned int V_33 ;
int V_239 ;
F_54 ( & V_2 -> V_138 ) ;
V_33 = ( ( unsigned int ) F_127 ( V_236 -> V_232 . V_257 . V_58 [ 0 ] ) << 24 ) |
( ( unsigned int ) F_127 ( V_236 -> V_232 . V_257 . V_58 [ 1 ] ) << 16 ) |
( ( unsigned int ) F_127 ( V_236 -> V_232 . V_257 . V_58 [ 3 ] ) ) |
( 1 << 13 ) | ( 1 << 12 ) ;
V_239 = V_168 -> V_261 != V_33 ;
V_168 -> V_261 = V_33 ;
if ( V_168 -> V_243 & V_259 )
F_129 ( V_2 , V_260 , V_33 ) ;
F_55 ( & V_2 -> V_138 ) ;
return V_239 ;
}
static int F_133 ( struct V_227 * V_228 ,
struct V_235 * V_236 )
{
struct V_1 * V_2 = F_104 ( V_228 ) ;
unsigned short V_33 ;
V_33 = F_134 ( V_2 -> V_31 [ V_9 ] , V_262 ) ;
V_236 -> V_232 . integer . V_232 [ 0 ] = ( V_33 & 0x200 ) ? 0 : 1 ;
return 0 ;
}
static int F_135 ( struct V_227 * V_228 ,
struct V_235 * V_236 )
{
struct V_1 * V_2 = F_104 ( V_228 ) ;
return F_136 ( V_2 -> V_31 [ V_9 ] ,
V_262 , 0x200 ,
V_236 -> V_232 . integer . V_232 [ 0 ] ? 0 : 0x200 ) ;
}
static void F_137 ( struct V_30 * V_31 )
{
unsigned long V_263 ;
int V_43 ;
F_138 ( V_31 , V_264 , 0 ) ;
if ( V_31 -> V_34 == V_9 ) {
F_20 ( L_21 , 0x0 ) ;
F_10 ( V_31 , V_262 , 0x0 ) ;
} else if ( V_31 -> V_34 == V_10 ) {
F_20 ( L_22 , 0x3 ) ;
F_10 ( V_31 , V_262 , 0x3 ) ;
} else {
F_60 () ;
}
F_7 ( 50 ) ;
V_263 = V_265 + V_266 ;
do {
unsigned short V_267 ;
F_134 ( V_31 , V_264 ) ;
F_134 ( V_31 , V_268 ) ;
F_134 ( V_31 , V_269 ) ;
V_267 = F_134 ( V_31 , V_270 ) ;
if ( V_267 != 0xffff && ( V_267 & 1 ) != 0 )
return;
F_138 ( V_31 , V_271 , 0x8a05 ) ;
if ( ( V_43 = F_134 ( V_31 , V_271 ) ) == 0x8a05 )
return;
F_6 ( 10 ) ;
} while ( F_139 ( V_263 , V_265 ) );
F_4 ( V_25 L_23 ) ;
}
static int F_140 ( struct V_1 * V_2 , int V_272 )
{
int V_41 , V_43 ;
struct V_273 V_31 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_32 = V_2 ;
V_31 . V_205 = F_101 ;
V_31 . V_34 = V_272 ;
if ( V_2 -> V_274 == V_275 )
V_31 . V_276 = V_277 ;
if ( V_272 == V_10 ) {
F_9 ( V_2 , V_264 , 0 , V_272 ) ;
F_7 ( 10 ) ;
if ( F_1 ( V_2 , V_264 , V_272 ) & 0x8000 ) {
F_20 ( L_24 ) ;
return - V_112 ;
}
}
F_9 ( V_2 , V_278 , 0x8000 , V_272 ) ;
for ( V_41 = 0 ; V_41 < 100 ; ++ V_41 ) {
if ( F_1 ( V_2 , V_278 , V_272 ) == 0x8000 ) {
V_43 = F_141 ( V_2 -> V_225 , & V_31 , & V_2 -> V_31 [ V_272 ] ) ;
return V_43 ;
}
F_6 ( 10 ) ;
}
F_20 ( L_25 , V_272 ) ;
return - V_112 ;
}
int F_142 ( struct V_1 * V_2 , int V_279 )
{
struct V_280 * V_215 = V_2 -> V_215 ;
struct V_281 V_282 ;
int V_43 ;
unsigned int V_41 ;
static struct V_283 V_142 = {
#ifdef F_36
. V_284 = F_137 ,
#endif
. V_285 = F_10 ,
. V_286 = F_8 ,
} ;
V_2 -> V_287 = 0 ;
F_20 ( L_26 ) ;
if ( ( V_43 = V_223 ( V_215 , 0 , & V_142 , V_2 , & V_2 -> V_225 ) ) < 0 )
return V_43 ;
V_2 -> V_225 -> V_205 = F_100 ;
if ( F_140 ( V_2 , V_9 ) < 0 )
return - V_112 ;
V_2 -> V_287 = 1 ;
#ifdef F_36
F_20 ( L_27 ) ;
if ( ! F_140 ( V_2 , V_10 ) )
V_2 -> V_287 = 2 ;
#endif
for ( V_41 = 0 ; V_41 < F_143 ( V_288 ) ; V_41 ++ ) {
struct V_227 * V_289 ;
V_289 = F_144 ( & V_288 [ V_41 ] , V_2 ) ;
if ( V_289 && V_289 -> V_282 . V_290 == V_291 )
V_289 -> V_282 . V_212 = V_279 ;
if ( ( V_43 = F_145 ( V_215 , V_289 ) ) < 0 )
return V_43 ;
}
memset ( & V_282 , 0 , sizeof( V_282 ) ) ;
V_282 . V_290 = V_292 ;
strcpy ( V_282 . V_220 , L_28 ) ;
V_2 -> V_226 = F_146 ( V_2 -> V_215 , & V_282 ) ;
#ifdef F_36
if ( V_2 -> V_287 == 1 ) {
unsigned int V_293 = V_2 -> V_31 [ V_9 ] -> V_282 & 0xffff ;
if ( V_293 == 0x592b || V_293 == 0x592d ) {
V_43 = F_145 ( V_215 , F_144 ( & V_294 , V_2 ) ) ;
if ( V_43 < 0 )
return V_43 ;
F_147 ( V_2 -> V_31 [ V_9 ] ,
V_262 , 0x200 ) ;
}
}
if ( V_2 -> V_295 ) {
F_20 ( L_29 ) ;
V_2 -> V_295 ( V_2 ) ;
}
#endif
V_2 -> V_274 ( V_2 , 1 ) ;
return 0 ;
}
static void F_148 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_196 , V_296 ) ;
F_7 ( 100 ) ;
F_5 ( V_2 , V_196 , V_2 -> V_190 ) ;
}
static int F_149 ( struct V_297 * V_95 )
{
struct V_1 * V_2 = V_95 -> V_185 -> V_32 ;
V_2 -> V_11 ( V_2 , 1 ) ;
F_150 ( & V_2 -> V_79 ) ;
V_2 -> V_298 |= V_299 ;
V_2 -> V_190 |= V_300 ;
V_2 -> V_192 = V_95 ;
if ( ! ( V_2 -> V_298 & V_301 ) ) {
F_148 ( V_2 ) ;
} else {
F_5 ( V_2 , V_196 , V_2 -> V_190 ) ;
}
F_151 ( & V_2 -> V_79 ) ;
return 0 ;
}
static int F_152 ( struct V_297 * V_95 )
{
struct V_1 * V_2 = V_95 -> V_185 -> V_32 ;
F_150 ( & V_2 -> V_79 ) ;
V_2 -> V_190 &= ~ ( V_300 | V_191 ) ;
V_2 -> V_192 = NULL ;
if ( ! ( V_2 -> V_298 & V_301 ) ) {
F_148 ( V_2 ) ;
} else {
F_5 ( V_2 , V_196 , V_2 -> V_190 ) ;
}
V_2 -> V_298 &= ~ V_299 ;
F_151 ( & V_2 -> V_79 ) ;
V_2 -> V_11 ( V_2 , - 1 ) ;
return 0 ;
}
static int F_153 ( struct V_297 * V_95 )
{
struct V_1 * V_2 = V_95 -> V_185 -> V_32 ;
V_2 -> V_11 ( V_2 , 1 ) ;
F_150 ( & V_2 -> V_79 ) ;
V_2 -> V_298 |= V_301 ;
V_2 -> V_190 |= V_302 ;
V_2 -> V_195 = V_95 ;
if ( ! ( V_2 -> V_298 & V_299 ) ) {
F_148 ( V_2 ) ;
} else {
F_5 ( V_2 , V_196 , V_2 -> V_190 ) ;
}
F_151 ( & V_2 -> V_79 ) ;
return 0 ;
}
static int F_154 ( struct V_297 * V_95 )
{
struct V_1 * V_2 = V_95 -> V_185 -> V_32 ;
F_150 ( & V_2 -> V_79 ) ;
V_2 -> V_190 &= ~ ( V_302 | V_194 ) ;
V_2 -> V_195 = NULL ;
if ( ! ( V_2 -> V_298 & V_299 ) ) {
F_148 ( V_2 ) ;
} else {
F_5 ( V_2 , V_196 , V_2 -> V_190 ) ;
}
V_2 -> V_298 &= ~ V_301 ;
F_151 ( & V_2 -> V_79 ) ;
V_2 -> V_11 ( V_2 , - 1 ) ;
return 0 ;
}
static void F_155 ( struct V_297 * V_95 , int V_303 )
{
unsigned long V_72 ;
struct V_1 * V_2 = V_95 -> V_185 -> V_32 ;
F_25 ( & V_2 -> V_79 , V_72 ) ;
if ( V_303 ) {
if ( ( V_2 -> V_190 & V_191 ) == 0 ) {
V_2 -> V_190 |= V_191 ;
F_5 ( V_2 , V_196 , V_2 -> V_190 ) ;
}
} else {
if ( V_2 -> V_190 & V_191 ) {
V_2 -> V_190 &= ~ V_191 ;
F_5 ( V_2 , V_196 , V_2 -> V_190 ) ;
}
}
F_26 ( & V_2 -> V_79 , V_72 ) ;
}
static void F_156 ( struct V_297 * V_95 , int V_303 )
{
unsigned long V_72 ;
struct V_1 * V_2 = V_95 -> V_185 -> V_32 ;
unsigned char V_304 ;
F_25 ( & V_2 -> V_79 , V_72 ) ;
if ( V_303 ) {
if ( ( V_2 -> V_190 & V_194 ) == 0 ) {
V_2 -> V_190 |= V_194 ;
while ( ( V_2 -> V_190 & V_194 ) &&
( F_3 ( V_2 , V_187 ) & V_193 ) == 0 ) {
if ( F_75 ( V_95 , & V_304 , 1 ) != 1 ) {
V_2 -> V_190 &= ~ V_194 ;
} else {
F_5 ( V_2 , V_197 , V_304 ) ;
}
}
F_5 ( V_2 , V_196 , V_2 -> V_190 ) ;
}
} else {
if ( V_2 -> V_190 & V_194 ) {
V_2 -> V_190 &= ~ V_194 ;
F_5 ( V_2 , V_196 , V_2 -> V_190 ) ;
}
}
F_26 ( & V_2 -> V_79 , V_72 ) ;
}
int F_157 ( struct V_1 * V_2 , int V_212 , struct V_305 * * V_306 )
{
struct V_305 * V_185 ;
int V_43 ;
if ( V_306 )
* V_306 = NULL ;
if ( ( V_43 = F_158 ( V_2 -> V_215 , L_30 , V_212 , 1 , 1 , & V_185 ) ) < 0 )
return V_43 ;
strcpy ( V_185 -> V_220 , L_30 ) ;
F_159 ( V_185 , V_307 , & V_308 ) ;
F_159 ( V_185 , V_309 , & V_310 ) ;
V_185 -> V_219 |= V_311 | V_312 | V_313 ;
V_185 -> V_32 = V_2 ;
V_2 -> V_185 = V_185 ;
if ( V_306 )
* V_306 = NULL ;
return 0 ;
}
static void F_160 ( struct V_314 * V_314 )
{
struct V_1 * V_2 = F_161 ( V_314 ) ;
if ( F_2 ( ! V_2 ) )
return;
F_5 ( V_2 , V_315 , 0xFF ) ;
}
static unsigned char F_162 ( struct V_314 * V_314 )
{
struct V_1 * V_2 = F_161 ( V_314 ) ;
if ( F_2 ( ! V_2 ) )
return 0 ;
return F_3 ( V_2 , V_315 ) ;
}
static int F_163 ( struct V_314 * V_314 , int * V_316 , int * V_317 )
{
struct V_1 * V_2 = F_161 ( V_314 ) ;
unsigned V_318 , V_319 , V_320 ;
if ( F_2 ( ! V_2 ) )
return 0 ;
V_318 = F_3 ( V_2 , V_321 ) ;
V_319 = F_3 ( V_2 , V_322 ) ;
V_320 = F_3 ( V_2 , V_315 ) ;
* V_317 = ( ~ V_320 >> 4 ) & 0x0F ;
V_316 [ 0 ] = ( ( V_318 & V_323 ) >> V_324 ) & 0xFFFF ;
V_316 [ 1 ] = ( ( V_318 & V_325 ) >> V_326 ) & 0xFFFF ;
V_316 [ 2 ] = ( ( V_319 & V_327 ) >> V_328 ) & 0xFFFF ;
V_316 [ 3 ] = ( ( V_319 & V_329 ) >> V_330 ) & 0xFFFF ;
for( V_320 = 0 ; V_320 < 4 ; ++ V_320 )
if( V_316 [ V_320 ] == 0xFFFF ) V_316 [ V_320 ] = - 1 ;
return 0 ;
}
static int F_164 ( struct V_314 * V_314 , int V_331 )
{
switch ( V_331 ) {
case V_332 :
return 0 ;
case V_333 :
return 0 ;
default:
return - 1 ;
}
return 0 ;
}
int F_165 ( struct V_1 * V_2 )
{
struct V_314 * V_334 ;
V_2 -> V_314 = V_334 = F_166 () ;
if ( ! V_334 ) {
F_167 ( V_25 L_31 ) ;
return - V_134 ;
}
F_168 ( V_334 , L_32 ) ;
F_169 ( V_334 , L_33 , F_170 ( V_2 -> V_201 ) ) ;
F_171 ( V_334 , & V_2 -> V_201 -> V_335 ) ;
F_172 ( V_334 , V_2 ) ;
V_334 -> V_336 = F_164 ;
V_334 -> V_286 = F_162 ;
V_334 -> V_337 = F_160 ;
V_334 -> V_338 = F_163 ;
F_5 ( V_2 , V_339 , 0xFF ) ;
F_5 ( V_2 , V_340 , V_341 ) ;
F_173 ( V_334 ) ;
return 0 ;
}
static inline void F_174 ( struct V_1 * V_2 )
{
if ( V_2 -> V_314 ) {
F_175 ( V_2 -> V_314 ) ;
V_2 -> V_314 = NULL ;
}
}
int F_165 ( struct V_1 * V_2 ) { return - V_342 ; }
static inline void F_174 ( struct V_1 * V_2 ) { }
static T_6 F_176 ( struct V_343 * V_344 ,
void * V_345 ,
struct V_346 * V_346 , char T_7 * V_347 ,
T_3 V_5 , T_8 V_348 )
{
struct V_349 * V_40 = V_344 -> V_32 ;
if ( F_177 ( V_347 , V_40 -> V_42 + V_348 , V_5 ) )
return - V_350 ;
return V_5 ;
}
static int F_178 ( struct V_280 * V_215 , struct V_1 * V_2 )
{
struct V_343 * V_344 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < 5 ; V_41 ++ ) {
struct V_349 * V_40 = & V_2 -> V_40 . V_41 [ V_41 ] ;
if ( ! F_179 ( V_215 , V_40 -> V_220 , & V_344 ) ) {
V_344 -> V_351 = V_352 ;
V_344 -> V_32 = V_2 ;
V_344 -> V_186 . V_142 = & V_353 ;
V_344 -> V_48 = V_40 -> V_48 ;
V_344 -> V_331 = V_354 | V_355 ;
}
}
#ifdef F_36
F_180 ( V_215 , V_2 ) ;
#endif
return 0 ;
}
static int F_181 ( struct V_1 * V_2 )
{
#ifdef F_36
F_182 ( V_2 ) ;
#endif
return 0 ;
}
static void F_183 ( struct V_1 * V_2 )
{
unsigned int V_7 ;
V_7 = F_22 ( V_2 , V_155 ) ;
V_7 &= ~ 0x0000f03f ;
V_7 |= 0x00000010 ;
F_16 ( V_2 , V_155 , V_7 ) ;
V_7 = F_22 ( V_2 , V_356 ) ;
V_7 &= ~ 0x0000003f ;
V_7 |= 0x00000011 ;
F_16 ( V_2 , V_356 , V_7 ) ;
V_7 = F_22 ( V_2 , V_126 ) ;
F_16 ( V_2 , V_126 , V_7 & 0x0000ffff ) ;
V_7 = F_22 ( V_2 , V_130 ) ;
F_16 ( V_2 , V_130 , V_7 & 0xffff0000 ) ;
F_15 ( V_2 ) ;
F_23 ( V_2 ) ;
F_5 ( V_2 , V_62 , 0 ) ;
V_7 = F_3 ( V_2 , V_62 ) & ~ V_63 ;
F_5 ( V_2 , V_62 , V_7 ) ;
}
static int F_184 ( struct V_1 * V_2 )
{
int V_41 ;
if ( F_2 ( ! V_2 ) )
return - V_39 ;
if ( V_2 -> V_11 )
V_2 -> V_11 ( V_2 , 1 ) ;
F_174 ( V_2 ) ;
if ( V_2 -> V_274 )
V_2 -> V_274 ( V_2 , - V_2 -> V_357 ) ;
F_181 ( V_2 ) ;
if ( V_2 -> V_40 . V_41 [ 0 ] . V_358 )
F_183 ( V_2 ) ;
if ( V_2 -> V_164 >= 0 )
F_185 ( V_2 -> V_164 , V_2 ) ;
if ( V_2 -> V_11 )
V_2 -> V_11 ( V_2 , - V_2 -> V_357 ) ;
for ( V_41 = 0 ; V_41 < 5 ; V_41 ++ ) {
struct V_349 * V_40 = & V_2 -> V_40 . V_41 [ V_41 ] ;
if ( V_40 -> V_42 )
F_186 ( V_40 -> V_42 ) ;
F_187 ( V_40 -> V_358 ) ;
}
#ifdef F_36
if ( V_2 -> V_167 ) {
F_188 ( V_2 ) ;
V_2 -> V_167 = NULL ;
}
#endif
#ifdef F_189
F_77 ( V_2 -> V_359 ) ;
#endif
F_190 ( V_2 -> V_201 ) ;
F_77 ( V_2 ) ;
return 0 ;
}
static int F_191 ( struct V_360 * V_212 )
{
struct V_1 * V_2 = V_212 -> V_361 ;
return F_184 ( V_2 ) ;
}
static int F_192 ( struct V_1 * V_2 )
{
int V_362 ;
F_5 ( V_2 , V_62 , 0 ) ;
F_5 ( V_2 , V_363 , 0 ) ;
#ifdef F_36
F_5 ( V_2 , V_364 , V_365 | V_366 |
V_367 ) ;
#else
F_5 ( V_2 , V_364 , V_365 | V_368 ) ;
#endif
F_5 ( V_2 , V_14 , 0 ) ;
#ifdef F_36
F_5 ( V_2 , V_369 , 0 ) ;
#endif
F_7 ( 50 ) ;
F_5 ( V_2 , V_14 , V_21 ) ;
#ifdef F_36
F_5 ( V_2 , V_369 , V_21 ) ;
#endif
F_5 ( V_2 , V_14 , V_17 | V_21 ) ;
#ifdef F_36
F_5 ( V_2 , V_369 , V_17 | V_21 ) ;
#endif
F_18 ( 10 ) ;
F_5 ( V_2 , V_363 , V_370 ) ;
F_5 ( V_2 , V_371 , V_372 | V_373 ) ;
F_5 ( V_2 , V_374 , 0x3a ) ;
F_5 ( V_2 , V_375 , V_376 ) ;
F_5 ( V_2 , V_62 , V_377 ) ;
F_6 ( 100 ) ;
F_5 ( V_2 , V_62 , V_377 | V_63 ) ;
F_5 ( V_2 , V_378 , V_379 ) ;
F_19 ( V_2 ) ;
F_5 ( V_2 , V_380 , V_381 | V_382 ) ;
F_5 ( V_2 , V_383 , V_384 | V_382 ) ;
F_5 ( V_2 , V_363 , V_370 | V_385 ) ;
#ifdef F_36
F_5 ( V_2 , V_386 , V_387 ) ;
F_5 ( V_2 , V_388 , 0 ) ;
F_5 ( V_2 , V_389 , 0 ) ;
F_5 ( V_2 , V_390 , 0 ) ;
F_5 ( V_2 , V_391 , 1 ) ;
#endif
F_18 ( 5 ) ;
V_362 = 150 ;
while ( V_362 -- > 0 ) {
if ( F_3 ( V_2 , V_27 ) & V_392 )
goto V_24;
F_6 ( 10 ) ;
}
F_4 ( V_25 L_34 ) ;
F_4 ( V_25 L_35 ) ;
return - V_393 ;
V_24:
#ifdef F_36
{
int V_5 ;
for ( V_5 = 0 ; V_5 < 150 ; V_5 ++ ) {
F_7 ( 25 ) ;
if ( F_3 ( V_2 , V_394 ) & V_392 )
break;
}
if ( ! ( F_3 ( V_2 , V_394 ) & V_392 ) )
F_20 ( L_36 ) ;
}
#endif
F_5 ( V_2 , V_14 , V_15 | V_17 | V_21 ) ;
#ifdef F_36
F_5 ( V_2 , V_369 , V_15 | V_17 | V_21 ) ;
#endif
V_362 = 150 ;
while ( V_362 -- > 0 ) {
if ( ( F_3 ( V_2 , V_395 ) & ( V_396 | V_397 ) ) == ( V_396 | V_397 ) )
goto V_29;
F_6 ( 10 ) ;
}
#ifndef F_36
F_4 ( V_25 L_37 ) ;
return - V_393 ;
#else
F_4 ( V_25 L_38 ) ;
F_4 ( V_25 L_39 ) ;
F_4 ( V_25 L_40 ) ;
F_4 ( V_25 L_41 ) ;
return - V_393 ;
#endif
V_29:
F_5 ( V_2 , V_398 , V_399 | V_400 ) ;
return 0 ;
}
static void F_193 ( struct V_1 * V_2 )
{
unsigned int V_7 ;
F_5 ( V_2 , V_171 , V_173 | V_172 ) ;
V_7 = F_22 ( V_2 , V_155 ) ;
V_7 &= ~ 0x0000f03f ;
F_16 ( V_2 , V_155 , V_7 ) ;
V_7 = F_22 ( V_2 , V_356 ) ;
V_7 &= ~ 0x0000003f ;
V_7 |= 0x00000001 ;
F_16 ( V_2 , V_356 , V_7 ) ;
}
int F_194 ( struct V_1 * V_2 )
{
unsigned int V_7 ;
F_15 ( V_2 ) ;
#ifdef F_36
#if 0
if (cs46xx_dsp_load_module(chip, &cwcemb80_module) < 0) {
snd_printk(KERN_ERR "image download error\n");
return -EIO;
}
#endif
if ( F_195 ( V_2 , & V_401 ) < 0 ) {
F_4 ( V_25 L_42 ) ;
return - V_393 ;
}
if ( F_195 ( V_2 , & V_402 ) < 0 ) {
F_4 ( V_25 L_43 ) ;
return - V_393 ;
}
if ( F_195 ( V_2 , & V_403 ) < 0 ) {
F_4 ( V_25 L_44 ) ;
return - V_393 ;
}
if ( F_195 ( V_2 , & V_404 ) < 0 ) {
F_4 ( V_25 L_45 ) ;
return - V_393 ;
}
if ( F_195 ( V_2 , & V_405 ) < 0 ) {
F_4 ( V_25 L_46 ) ;
return - V_393 ;
}
if ( F_196 ( V_2 ) < 0 )
return - V_393 ;
#else
if ( F_14 ( V_2 ) < 0 ) {
F_4 ( V_25 L_47 ) ;
return - V_393 ;
}
V_7 = F_22 ( V_2 , V_126 ) ;
V_2 -> V_127 = V_7 & 0xffff0000 ;
F_16 ( V_2 , V_126 , V_7 & 0x0000ffff ) ;
#endif
V_7 = F_22 ( V_2 , V_130 ) ;
V_2 -> V_109 . V_131 = V_7 & 0x0000ffff ;
F_16 ( V_2 , V_130 , V_7 & 0xffff0000 ) ;
F_18 ( 5 ) ;
F_24 ( V_2 , 8000 ) ;
F_27 ( V_2 , 8000 ) ;
F_21 ( V_2 ) ;
F_193 ( V_2 ) ;
#ifndef F_36
F_16 ( V_2 , V_406 , 0x80008000 ) ;
F_16 ( V_2 , V_407 , 0x80008000 ) ;
#endif
return 0 ;
}
static void F_197 ( struct V_1 * V_2 , int V_239 )
{
}
static int F_198 ( struct V_1 * V_2 )
{
T_1 V_41 , V_408 , V_7 , V_61 = 0 ;
T_9 V_409 , V_410 , V_411 ;
F_20 ( L_48 ) ;
V_7 = F_3 ( V_2 , V_62 ) ;
if ( ! ( V_7 & V_63 ) ) {
F_5 ( V_2 , V_62 , V_7 | V_63 ) ;
V_61 = 1 ;
}
if( V_2 -> V_287 != 2 ) {
F_4 ( V_25 L_49 ) ;
return - V_39 ;
}
V_409 = F_1 ( V_2 ,
V_412 ,
V_10 ) ;
V_409 &= 0xFEFF ;
F_9 ( V_2 ,
V_412 , V_409 ,
V_10 ) ;
V_410 = F_1 ( V_2 ,
V_413 ,
V_10 ) ;
V_410 &= 0x27F ;
F_9 ( V_2 ,
V_413 , V_410 ,
V_10 ) ;
V_411 = F_1 ( V_2 , V_414 ,
V_10 ) ;
V_411 &= 0x27F ;
F_9 ( V_2 , V_414 , V_411 ,
V_10 ) ;
V_408 = F_3 ( V_2 , V_398 ) ;
V_408 |= 0x200 ;
F_5 ( V_2 , V_398 , V_408 ) ;
if ( F_17 ( V_2 , 1 ) ) {
F_20 ( L_50 ) ;
return - V_39 ;
}
for( V_41 = 0x90 ; V_41 <= 0x9F ; V_41 ++ ) {
F_5 ( V_2 , V_64 , 0x1800 ) ;
if ( F_17 ( V_2 , 200 ) ) {
F_20 ( L_7 , V_41 ) ;
return - V_39 ;
}
F_5 ( V_2 , V_65 , V_41 ) ;
F_5 ( V_2 , V_66 , V_67 ) ;
}
F_17 ( V_2 , 200 ) ;
if ( V_61 )
F_5 ( V_2 , V_62 , V_7 ) ;
return 0 ;
}
static void V_275 ( struct V_1 * V_2 , int V_239 )
{
#ifdef F_36
int V_238 = V_2 -> V_357 ;
#endif
int V_415 , V_33 ;
V_2 -> V_357 += V_239 ;
V_415 = F_1 ( V_2 , V_416 ,
V_9 ) ;
V_33 = V_415 ;
if ( V_2 -> V_357 ) {
V_33 |= 0x8000 ;
} else {
V_33 &= ~ 0x8000 ;
}
if ( V_33 != V_415 ) {
F_9 ( V_2 , V_416 , V_33 ,
V_9 ) ;
if ( V_2 -> V_226 )
F_199 ( V_2 -> V_215 , V_417 ,
& V_2 -> V_226 -> V_282 ) ;
}
#ifdef F_36
if ( V_2 -> V_357 && ! V_238 ) {
F_198 ( V_2 ) ;
}
#endif
}
static void F_200 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_251 , V_252 ) ;
F_5 ( V_2 , V_254 , V_252 ) ;
}
static void F_201 ( struct V_1 * V_2 , int V_239 )
{
int V_238 = V_2 -> V_357 ;
int V_250 = F_3 ( V_2 , V_251 ) ;
int V_253 = F_3 ( V_2 , V_254 ) ;
V_2 -> V_357 += V_239 ;
if ( V_2 -> V_357 && ! V_238 ) {
F_20 ( L_51 ) ;
F_5 ( V_2 , V_251 ,
V_418 | V_250 ) ;
F_5 ( V_2 , V_254 ,
V_419 | V_253 ) ;
} else if ( V_238 && ! V_2 -> V_357 ) {
F_20 ( L_52 ) ;
F_5 ( V_2 , V_251 , V_250 & ~ V_418 ) ;
F_5 ( V_2 , V_254 , V_253 & ~ V_419 ) ;
}
}
static void F_202 ( struct V_1 * V_2 )
{
F_20 ( L_53 ) ;
F_5 ( V_2 , V_251 , V_252 ) ;
F_5 ( V_2 , V_254 , V_252 ) ;
}
static void F_203 ( struct V_1 * V_2 )
{
#ifdef F_36
unsigned int V_41 ;
int V_43 ;
struct V_280 * V_215 = V_2 -> V_215 ;
#endif
F_200 ( V_2 ) ;
F_20 ( L_54 ) ;
#ifdef F_36
if ( V_2 -> V_420 )
return;
for ( V_41 = 0 ; V_41 < F_143 ( V_421 ) ; V_41 ++ ) {
struct V_227 * V_289 ;
V_289 = F_144 ( & V_421 [ V_41 ] , V_2 ) ;
if ( ( V_43 = F_145 ( V_215 , V_289 ) ) < 0 ) {
F_167 ( V_25 L_55 , V_43 ) ;
break;
}
}
#endif
}
static void F_204 ( struct V_1 * V_2 , int V_239 )
{
T_9 V_422 , V_423 ;
if ( ! V_2 -> V_424 )
return;
V_2 -> V_357 += V_239 ;
V_423 = V_422 = F_205 ( V_2 -> V_424 + 0x10 ) ;
if ( ! V_2 -> V_357 )
V_423 |= 0x2000 ;
else
V_423 &= ~ 0x2000 ;
if ( V_423 != V_422 )
F_206 ( V_423 , V_2 -> V_424 + 0x10 ) ;
}
static void F_207 ( struct V_1 * V_2 )
{
struct V_425 * V_426 ;
T_10 V_427 ;
V_2 -> V_424 = 0 ;
V_426 = F_208 ( V_428 ,
V_429 , NULL ) ;
if ( V_426 == NULL )
return;
F_209 ( V_426 , 0x41 , & V_427 ) ;
V_2 -> V_424 = V_427 << 8 ;
F_210 ( V_426 ) ;
}
static int F_211 ( struct V_212 * V_335 )
{
struct V_425 * V_201 = F_212 ( V_335 ) ;
struct V_280 * V_215 = F_213 ( V_335 ) ;
struct V_1 * V_2 = V_215 -> V_32 ;
int V_57 , V_430 ;
F_214 ( V_215 , V_431 ) ;
V_2 -> V_420 = 1 ;
F_215 ( V_2 -> V_183 ) ;
F_216 ( V_2 -> V_31 [ V_9 ] ) ;
F_216 ( V_2 -> V_31 [ V_10 ] ) ;
for ( V_57 = 0 ; V_57 < F_143 ( V_359 ) ; V_57 ++ )
V_2 -> V_359 [ V_57 ] = F_3 ( V_2 , V_359 [ V_57 ] ) ;
V_430 = V_2 -> V_357 ;
V_2 -> V_274 ( V_2 , - V_2 -> V_357 ) ;
F_183 ( V_2 ) ;
V_2 -> V_11 ( V_2 , - V_2 -> V_357 ) ;
V_2 -> V_357 = V_430 ;
F_190 ( V_201 ) ;
F_217 ( V_201 ) ;
F_218 ( V_201 , V_432 ) ;
return 0 ;
}
static int F_219 ( struct V_212 * V_335 )
{
struct V_425 * V_201 = F_212 ( V_335 ) ;
struct V_280 * V_215 = F_213 ( V_335 ) ;
struct V_1 * V_2 = V_215 -> V_32 ;
int V_430 ;
#ifdef F_36
int V_57 ;
#endif
unsigned int V_7 ;
F_218 ( V_201 , V_433 ) ;
F_220 ( V_201 ) ;
if ( F_221 ( V_201 ) < 0 ) {
F_167 ( V_25 L_56
L_57 ) ;
F_222 ( V_215 ) ;
return - V_393 ;
}
F_223 ( V_201 ) ;
V_430 = V_2 -> V_357 ;
V_2 -> V_357 = 0 ;
V_2 -> V_11 ( V_2 , 1 ) ;
F_192 ( V_2 ) ;
F_15 ( V_2 ) ;
#ifdef F_36
F_224 ( V_2 ) ;
for ( V_57 = 0 ; V_57 < F_143 ( V_359 ) ; V_57 ++ )
F_5 ( V_2 , V_359 [ V_57 ] , V_2 -> V_359 [ V_57 ] ) ;
#else
F_14 ( V_2 ) ;
#endif
#if 0
snd_cs46xx_codec_write(chip, BA0_AC97_GENERAL_PURPOSE,
chip->ac97_general_purpose);
snd_cs46xx_codec_write(chip, AC97_POWER_CONTROL,
chip->ac97_powerdown);
mdelay(10);
snd_cs46xx_codec_write(chip, BA0_AC97_POWERDOWN,
chip->ac97_powerdown);
mdelay(5);
#endif
F_225 ( V_2 -> V_31 [ V_9 ] ) ;
F_225 ( V_2 -> V_31 [ V_10 ] ) ;
V_7 = F_22 ( V_2 , V_130 ) ;
V_2 -> V_109 . V_131 = V_7 & 0x0000ffff ;
F_16 ( V_2 , V_130 , V_7 & 0xffff0000 ) ;
F_18 ( 5 ) ;
F_24 ( V_2 , 8000 ) ;
F_27 ( V_2 , 8000 ) ;
F_21 ( V_2 ) ;
F_193 ( V_2 ) ;
if ( V_430 )
V_2 -> V_274 ( V_2 , 1 ) ;
else
V_2 -> V_11 ( V_2 , - 1 ) ;
V_2 -> V_357 = V_430 ;
V_2 -> V_420 = 0 ;
F_214 ( V_215 , V_434 ) ;
return 0 ;
}
int F_226 ( struct V_280 * V_215 ,
struct V_425 * V_201 ,
int V_435 , int V_436 ,
struct V_1 * * V_437 )
{
struct V_1 * V_2 ;
int V_43 , V_41 ;
struct V_349 * V_40 ;
struct V_438 * V_439 ;
T_9 V_440 , V_441 ;
static struct V_442 V_142 = {
. V_443 = F_191 ,
} ;
* V_437 = NULL ;
if ( ( V_43 = F_221 ( V_201 ) ) < 0 )
return V_43 ;
V_2 = F_79 ( sizeof( * V_2 ) , V_199 ) ;
if ( V_2 == NULL ) {
F_190 ( V_201 ) ;
return - V_134 ;
}
F_227 ( & V_2 -> V_79 ) ;
#ifdef F_36
F_228 ( & V_2 -> V_138 ) ;
#endif
V_2 -> V_215 = V_215 ;
V_2 -> V_201 = V_201 ;
V_2 -> V_164 = - 1 ;
V_2 -> V_444 = F_229 ( V_201 , 0 ) ;
V_2 -> V_445 = F_229 ( V_201 , 1 ) ;
if ( V_2 -> V_444 == 0 || V_2 -> V_444 == ( unsigned long ) ~ 0 ||
V_2 -> V_445 == 0 || V_2 -> V_445 == ( unsigned long ) ~ 0 ) {
F_4 ( V_25 L_58 ,
V_2 -> V_444 , V_2 -> V_445 ) ;
F_184 ( V_2 ) ;
return - V_134 ;
}
V_40 = & V_2 -> V_40 . V_220 . V_446 ;
strcpy ( V_40 -> V_220 , L_59 ) ;
V_40 -> V_447 = V_2 -> V_444 ;
V_40 -> V_48 = V_448 ;
V_40 = & V_2 -> V_40 . V_220 . V_449 ;
strcpy ( V_40 -> V_220 , L_60 ) ;
V_40 -> V_447 = V_2 -> V_445 + V_450 ;
V_40 -> V_48 = V_451 ;
V_40 = & V_2 -> V_40 . V_220 . V_452 ;
strcpy ( V_40 -> V_220 , L_61 ) ;
V_40 -> V_447 = V_2 -> V_445 + V_453 ;
V_40 -> V_48 = V_454 ;
V_40 = & V_2 -> V_40 . V_220 . V_455 ;
strcpy ( V_40 -> V_220 , L_62 ) ;
V_40 -> V_447 = V_2 -> V_445 + V_456 ;
V_40 -> V_48 = V_457 ;
V_40 = & V_2 -> V_40 . V_220 . V_3 ;
strcpy ( V_40 -> V_220 , L_63 ) ;
V_40 -> V_447 = V_2 -> V_445 + V_458 ;
V_40 -> V_48 = V_459 ;
F_230 ( V_201 , V_460 , & V_441 ) ;
F_230 ( V_201 , V_461 , & V_440 ) ;
for ( V_439 = & V_462 [ 0 ] ; V_439 -> V_220 ; V_439 ++ ) {
if ( V_439 -> V_463 == V_441 && V_439 -> V_282 == V_440 ) {
F_20 ( L_64 , V_439 -> V_220 ) ;
V_2 -> V_274 = V_439 -> V_464 ;
V_2 -> V_11 = V_439 -> V_179 ;
V_2 -> V_295 = V_439 -> V_295 ;
if ( V_439 -> V_465 )
V_439 -> V_465 ( V_2 ) ;
break;
}
}
if ( V_435 ) {
F_4 ( V_466 L_65 ) ;
V_2 -> V_274 = V_275 ;
}
if ( V_436 ) {
F_4 ( V_466 L_66 ) ;
V_2 -> V_11 = F_204 ;
F_207 ( V_2 ) ;
}
if ( V_2 -> V_274 == NULL )
V_2 -> V_274 = F_197 ;
if ( V_2 -> V_11 == NULL )
V_2 -> V_11 = F_197 ;
V_2 -> V_11 ( V_2 , 1 ) ;
F_223 ( V_201 ) ;
for ( V_41 = 0 ; V_41 < 5 ; V_41 ++ ) {
V_40 = & V_2 -> V_40 . V_41 [ V_41 ] ;
if ( ( V_40 -> V_358 = F_231 ( V_40 -> V_447 , V_40 -> V_48 ,
V_40 -> V_220 ) ) == NULL ) {
F_4 ( V_25 L_67 ,
V_40 -> V_447 , V_40 -> V_447 + V_40 -> V_48 - 1 ) ;
F_184 ( V_2 ) ;
return - V_467 ;
}
V_40 -> V_42 = F_232 ( V_40 -> V_447 , V_40 -> V_48 ) ;
if ( V_40 -> V_42 == NULL ) {
F_4 ( V_25 L_68 , V_40 -> V_220 ) ;
F_184 ( V_2 ) ;
return - V_134 ;
}
}
if ( F_233 ( V_201 -> V_164 , F_72 , V_468 ,
V_469 , V_2 ) ) {
F_4 ( V_25 L_69 , V_201 -> V_164 ) ;
F_184 ( V_2 ) ;
return - V_467 ;
}
V_2 -> V_164 = V_201 -> V_164 ;
#ifdef F_36
V_2 -> V_167 = F_234 ( V_2 ) ;
if ( V_2 -> V_167 == NULL ) {
F_184 ( V_2 ) ;
return - V_134 ;
}
#endif
V_43 = F_192 ( V_2 ) ;
if ( V_43 < 0 ) {
F_184 ( V_2 ) ;
return V_43 ;
}
if ( ( V_43 = F_235 ( V_215 , V_470 , V_2 , & V_142 ) ) < 0 ) {
F_184 ( V_2 ) ;
return V_43 ;
}
F_178 ( V_215 , V_2 ) ;
#ifdef F_189
V_2 -> V_359 = F_236 ( sizeof( * V_2 -> V_359 ) *
F_143 ( V_359 ) , V_199 ) ;
if ( ! V_2 -> V_359 ) {
F_184 ( V_2 ) ;
return - V_134 ;
}
#endif
V_2 -> V_11 ( V_2 , - 1 ) ;
F_237 ( V_215 , & V_201 -> V_335 ) ;
* V_437 = V_2 ;
return 0 ;
}
