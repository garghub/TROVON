static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int V_7 , unsigned int V_8 )
{
unsigned int V_9 , V_10 , V_11 , V_12 ;
struct V_13 * V_14 = F_2 ( V_4 ) ;
if ( V_2 -> V_15 . V_16 == NULL ) {
if ( F_3 ( V_17 , F_4 ( V_14 -> V_6 ) ,
F_5 ( V_18 * 2 * 8 ) ,
& V_2 -> V_15 ) < 0 )
return - V_19 ;
}
if ( ! V_2 -> V_20 ) {
V_2 -> V_20 = F_6 ( sizeof( * V_2 -> V_20 ) * V_18 , V_21 ) ;
if ( ! V_2 -> V_20 )
return - V_19 ;
}
V_10 = 0 ;
V_11 = 0 ;
for ( V_9 = 0 ; V_9 < V_7 ; V_9 ++ ) {
V_12 = V_8 ;
do {
unsigned int V_22 ;
unsigned int V_23 ;
unsigned int V_24 ;
if ( V_10 >= V_18 ) {
F_7 ( V_25 L_1 ) ;
return - V_26 ;
}
V_24 = F_8 ( V_4 , V_11 ) ;
( ( V_27 * ) V_2 -> V_15 . V_16 ) [ V_10 << 1 ] = F_9 ( V_24 ) ;
V_22 = F_10 ( V_4 , V_11 , V_12 ) ;
V_12 -= V_22 ;
if ( ! V_12 ) {
if ( V_9 == V_7 - 1 )
V_23 = V_28 ;
else
V_23 = V_29 ;
} else
V_23 = 0 ;
( ( V_27 * ) V_2 -> V_15 . V_16 ) [ ( V_10 << 1 ) + 1 ] = F_9 ( V_22 | V_23 ) ;
V_2 -> V_20 [ V_10 ] . V_30 = V_11 ;
V_2 -> V_20 [ V_10 ] . V_31 = V_22 ;
V_11 += V_22 ;
V_10 ++ ;
} while ( V_12 > 0 );
}
V_2 -> V_32 = V_10 ;
V_2 -> V_33 = V_7 * V_8 ;
V_2 -> V_34 = V_2 -> V_33 / 2 ;
V_2 -> V_8 = V_8 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
if ( V_2 -> V_15 . V_16 ) {
F_12 ( & V_2 -> V_15 ) ;
V_2 -> V_15 . V_16 = NULL ;
}
F_13 ( V_2 -> V_20 ) ;
V_2 -> V_20 = NULL ;
return 0 ;
}
static inline unsigned int F_14 ( struct V_13 * V_14 )
{
return F_15 ( F_16 ( V_14 , V_35 ) ) ;
}
static inline void F_17 ( struct V_13 * V_14 , unsigned int V_36 )
{
F_18 ( V_36 , F_16 ( V_14 , V_35 ) ) ;
}
static int F_19 ( struct V_13 * V_14 , int V_37 )
{
unsigned int V_38 = 1000 ;
unsigned int V_36 ;
while ( V_38 -- > 0 ) {
F_20 ( 1 ) ;
if ( ! ( ( V_36 = F_14 ( V_14 ) ) & V_39 ) )
return V_36 & 0xffff ;
}
F_7 ( V_25 L_2 ,
V_37 , F_14 ( V_14 ) ) ;
return - V_40 ;
}
static int F_21 ( struct V_13 * V_14 , int V_37 )
{
unsigned int V_38 = 1000 ;
unsigned int V_36 , V_41 ;
unsigned int V_42 = ! V_37 ? V_43 :
V_44 ;
while ( V_38 -- > 0 ) {
V_36 = F_14 ( V_14 ) ;
V_41 = V_36 & ( V_39 | V_42 ) ;
if ( V_41 == V_42 )
return V_36 & 0xffff ;
F_20 ( 1 ) ;
}
return - V_40 ;
}
static void F_22 ( struct V_45 * V_46 )
{
struct V_13 * V_14 = V_46 -> V_47 ;
int V_48 ;
V_48 = F_19 ( V_14 , V_46 -> V_49 ) ;
if ( ! V_50 )
F_23 ( 500 ) ;
}
static void F_24 ( struct V_45 * V_46 ,
unsigned short V_51 ,
unsigned short V_36 )
{
struct V_13 * V_14 = V_46 -> V_47 ;
unsigned int V_52 ;
V_52 = ! V_46 -> V_49 ? V_53 : V_54 ;
V_52 <<= V_55 ;
V_52 |= V_51 << V_56 ;
V_52 |= V_36 << V_57 ;
F_17 ( V_14 , V_52 ) ;
F_19 ( V_14 , V_46 -> V_49 ) ;
}
static unsigned short F_25 ( struct V_45 * V_46 , unsigned short V_51 )
{
struct V_13 * V_14 = V_46 -> V_47 ;
unsigned int V_52 , V_36 = 0xffff ;
int V_58 = 0 ;
V_52 = V_46 -> V_49 << V_55 ;
V_52 |= V_46 -> V_49 ? V_44 : V_43 ;
V_52 |= V_59 ;
V_52 |= ( V_51 & 0x7f ) << V_56 ;
while ( 1 ) {
if ( V_58 ++ > 3 ) {
F_7 ( V_25 L_3 ,
V_46 -> V_49 , F_14 ( V_14 ) ) ;
return 0xffff ;
}
F_17 ( V_14 , V_52 ) ;
F_20 ( 20 ) ;
if ( F_21 ( V_14 , V_46 -> V_49 ) >= 0 ) {
F_20 ( 25 ) ;
V_36 = F_14 ( V_14 ) ;
break;
}
}
return V_36 & 0xffff ;
}
static void F_26 ( struct V_13 * V_14 , struct V_1 * V_1 )
{
F_27 ( V_60 | V_61 | V_62 ,
F_28 ( V_1 , V_63 ) ) ;
F_29 ( F_28 ( V_1 , V_63 ) ) ;
F_20 ( 50 ) ;
F_27 ( 0x00 , F_28 ( V_1 , V_63 ) ) ;
F_27 ( 0x03 , F_28 ( V_1 , V_64 ) ) ;
F_27 ( 0x00 , F_28 ( V_1 , V_65 ) ) ;
V_1 -> V_66 = 0 ;
V_1 -> V_67 = 0 ;
}
static T_1 F_30 ( int V_68 , void * V_69 )
{
struct V_13 * V_14 = V_69 ;
unsigned int V_70 ;
unsigned int V_9 ;
V_70 = F_15 ( F_16 ( V_14 , V_71 ) ) ;
if ( ! ( V_70 & V_14 -> V_72 ) ) {
if ( V_14 -> V_73 )
return F_31 ( V_68 , V_14 -> V_73 -> V_47 ) ;
return V_74 ;
}
F_32 ( & V_14 -> V_75 ) ;
for ( V_9 = 0 ; V_9 < V_14 -> V_76 ; V_9 ++ ) {
struct V_1 * V_1 = & V_14 -> V_77 [ V_9 ] ;
unsigned char V_78 = F_29 ( F_28 ( V_1 , V_64 ) ) ;
if ( ! ( V_78 & ( V_79 | V_80 | V_81 ) ) )
continue;
if ( V_1 -> V_4 && V_1 -> V_82 ) {
if ( V_78 & V_79 )
V_1 -> V_67 = 0 ;
else
V_1 -> V_67 += V_1 -> V_8 ;
V_1 -> V_83 = V_78 ;
F_33 ( & V_14 -> V_75 ) ;
F_34 ( V_1 -> V_4 ) ;
F_32 ( & V_14 -> V_75 ) ;
V_1 -> V_83 = 0 ;
}
F_27 ( V_78 , F_28 ( V_1 , V_64 ) ) ;
}
F_33 ( & V_14 -> V_75 ) ;
return V_84 ;
}
static T_1 F_35 ( int V_68 , void * V_69 )
{
struct V_13 * V_14 = V_69 ;
unsigned int V_70 ;
unsigned int V_9 ;
int V_85 = 0 ;
F_32 ( & V_14 -> V_75 ) ;
V_70 = F_15 ( F_16 ( V_14 , V_71 ) ) ;
for ( V_9 = 0 ; V_9 < V_14 -> V_76 ; V_9 ++ ) {
struct V_1 * V_1 = & V_14 -> V_77 [ V_9 ] ;
struct V_3 * V_4 ;
unsigned char V_78 , V_86 ;
V_86 = ( V_70 >> V_1 -> V_87 ) &
( V_88 | V_79 |
V_80 ) ;
V_78 = V_86 & ( V_79 | V_80 ) ;
if ( ! V_78 )
continue;
V_4 = V_1 -> V_4 ;
if ( V_4 && V_1 -> V_82 ) {
if ( V_78 & V_79 )
V_1 -> V_67 = 0 ;
else
V_1 -> V_67 += V_1 -> V_8 ;
V_1 -> V_83 = V_78 ;
if ( V_86 & V_88 )
V_1 -> V_83 |= V_89 ;
F_33 ( & V_14 -> V_75 ) ;
F_34 ( V_4 ) ;
F_32 ( & V_14 -> V_75 ) ;
V_1 -> V_83 = 0 ;
}
F_27 ( V_78 , F_28 ( V_1 , V_64 ) ) ;
V_85 = 1 ;
}
F_33 ( & V_14 -> V_75 ) ;
return F_36 ( V_85 ) ;
}
static int F_37 ( struct V_3 * V_4 , int V_90 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = V_4 -> V_91 -> V_47 ;
unsigned char V_36 ;
if ( V_14 -> V_92 != V_93 )
V_36 = V_94 ;
else
V_36 = 0 ;
switch ( V_90 ) {
case V_95 :
case V_96 :
V_36 |= V_97 ;
V_1 -> V_82 = 1 ;
break;
case V_98 :
case V_99 :
V_36 = V_61 ;
V_1 -> V_82 = 0 ;
break;
case V_100 :
V_36 |= V_60 ;
V_1 -> V_82 = 0 ;
break;
case V_101 :
V_1 -> V_82 = 1 ;
break;
default:
return - V_26 ;
}
F_27 ( V_36 , F_28 ( V_1 , V_63 ) ) ;
if ( V_90 == V_98 )
F_26 ( V_14 , V_1 ) ;
return 0 ;
}
static inline unsigned int F_38 ( struct V_1 * V_1 , unsigned int V_10 ,
unsigned int V_102 )
{
unsigned int V_31 , V_103 , V_104 ;
V_31 = V_1 -> V_20 [ V_10 ] . V_31 ;
V_103 = V_1 -> V_20 [ V_10 ] . V_30 ;
V_104 = V_103 + V_31 - V_102 ;
if ( V_104 >= V_1 -> V_33 )
V_104 -= V_1 -> V_33 ;
if ( V_31 < V_102 ) {
F_39 ( V_25 L_4 ,
( int ) V_31 , ( int ) V_102 ) ;
V_104 = V_1 -> V_66 ;
} else {
if ( ! V_102 ) {
int V_105 = V_104 - V_1 -> V_66 ;
if ( V_105 < 0 )
V_105 += V_1 -> V_33 ;
if ( ( unsigned int ) V_105 > V_1 -> V_8 )
V_104 = V_103 ;
}
if ( F_40 ( V_1 , V_104 ) ) {
#ifdef F_41
F_42 ( V_106 L_5
L_6
L_7 , V_10 , V_1 -> V_32 ,
V_1 -> V_66 , V_1 -> V_34 ,
V_1 -> V_20 [ V_10 ] . V_30 ,
V_1 -> V_20 [ V_10 ] . V_31 , V_102 ) ;
#endif
V_104 = V_103 + V_31 ;
if ( F_40 ( V_1 , V_104 ) ) {
F_39 ( V_25 L_8
L_9 ) ;
V_104 = V_1 -> V_66 ;
}
}
}
return V_104 ;
}
static T_2 F_43 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = V_4 -> V_91 -> V_47 ;
unsigned int V_10 , V_107 , V_102 , V_104 ;
if ( F_44 ( ! V_1 -> V_32 ) )
return 0 ;
if ( ! ( F_29 ( F_28 ( V_1 , V_64 ) ) & V_89 ) )
return 0 ;
F_32 ( & V_14 -> V_75 ) ;
V_102 = F_15 ( F_28 ( V_1 , V_108 ) ) & 0xffffff ;
V_107 = F_15 ( F_28 ( V_1 , V_109 ) ) ;
if ( V_107 <= ( unsigned int ) V_1 -> V_15 . V_24 )
V_10 = 0 ;
else
V_10 = ( ( V_107 - ( unsigned int ) V_1 -> V_15 . V_24 ) / 8 - 1 ) % V_1 -> V_32 ;
V_104 = F_38 ( V_1 , V_10 , V_102 ) ;
V_1 -> V_66 = V_104 ;
F_33 ( & V_14 -> V_75 ) ;
return F_45 ( V_4 -> V_91 , V_104 ) ;
}
static T_2 F_46 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = V_4 -> V_91 -> V_47 ;
unsigned int V_10 , V_102 , V_104 ;
int V_70 ;
if ( F_44 ( ! V_1 -> V_32 ) )
return 0 ;
F_32 ( & V_14 -> V_75 ) ;
V_102 = F_15 ( F_28 ( V_1 , V_108 ) ) ;
V_70 = V_1 -> V_83 ;
if ( ! V_70 )
V_70 = F_29 ( F_28 ( V_1 , V_64 ) ) ;
if ( V_14 -> V_110 == V_111 && ( V_70 & V_79 ) )
F_37 ( V_4 , V_95 ) ;
if ( ! ( V_70 & V_89 ) ) {
V_104 = 0 ;
goto V_112;
}
if ( V_102 & 0xffffff ) {
V_10 = V_102 >> 24 ;
if ( V_10 >= V_1 -> V_32 ) {
#ifdef F_41
F_42 ( V_106 L_10 , V_10 ,
V_1 -> V_32 ) ;
#endif
V_104 = V_1 -> V_66 ;
} else {
V_102 &= 0xffffff ;
V_104 = F_38 ( V_1 , V_10 , V_102 ) ;
}
} else {
V_104 = V_1 -> V_67 ;
if ( ! V_1 -> V_83 ) {
if ( V_70 & V_79 ) {
V_104 = 0 ;
} else
if ( V_70 & V_80 ) {
V_104 += V_1 -> V_8 ;
}
}
}
V_112:
V_1 -> V_66 = V_104 ;
F_33 ( & V_14 -> V_75 ) ;
return F_45 ( V_4 -> V_91 , V_104 ) ;
}
static int F_47 ( struct V_3 * V_4 ,
struct V_113 * V_114 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = V_4 -> V_91 -> V_47 ;
int V_48 ;
V_48 = F_48 ( V_4 , F_49 ( V_114 ) ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = F_1 ( V_1 , V_4 , V_14 -> V_6 ,
F_50 ( V_114 ) ,
F_51 ( V_114 ) ) ;
if ( V_48 < 0 )
return V_48 ;
return 0 ;
}
static int F_52 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = V_4 -> V_91 -> V_47 ;
F_11 ( V_1 , V_4 , V_14 -> V_6 ) ;
F_53 ( V_4 ) ;
return 0 ;
}
static void F_54 ( struct V_13 * V_14 , struct V_1 * V_1 )
{
F_19 ( V_14 , 0 ) ;
F_18 ( ( V_27 ) V_1 -> V_15 . V_24 , F_28 ( V_1 , V_115 ) ) ;
F_20 ( 20 ) ;
F_19 ( V_14 , 0 ) ;
}
static void F_55 ( struct V_13 * V_14 , struct V_1 * V_1 ,
struct V_116 * V_91 )
{
F_26 ( V_14 , V_1 ) ;
F_54 ( V_14 , V_1 ) ;
F_27 ( V_117 |
( V_91 -> V_118 == V_119 ? V_120 : 0 ) |
( V_91 -> V_121 > 1 ? V_122 : 0 ) |
( ( V_1 -> V_123 & 0x10 ) == 0 ? V_124 : 0 ) |
V_125 |
V_126 , F_28 ( V_1 , V_65 ) ) ;
}
static int F_56 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = V_4 -> V_91 -> V_47 ;
struct V_116 * V_91 = V_4 -> V_91 ;
F_57 ( V_14 -> V_46 , V_127 , V_91 -> V_128 ) ;
F_57 ( V_14 -> V_46 , V_129 , V_91 -> V_128 ) ;
F_55 ( V_14 , V_1 , V_91 ) ;
return 0 ;
}
static int F_58 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = V_4 -> V_91 -> V_47 ;
struct V_116 * V_91 = V_4 -> V_91 ;
F_57 ( V_14 -> V_46 , V_130 , V_91 -> V_128 ) ;
F_55 ( V_14 , V_1 , V_91 ) ;
return 0 ;
}
static int F_59 ( struct V_131 * V_132 , int V_128 )
{
int V_133 = 0 ;
F_60 ( & V_132 -> V_134 ) ;
if ( V_132 -> V_128 != V_128 ) {
if ( V_132 -> V_128 && V_132 -> V_135 > 1 )
V_133 = - V_26 ;
else {
V_132 -> V_128 = V_128 ;
V_133 = 1 ;
}
}
F_61 ( & V_132 -> V_134 ) ;
return V_133 ;
}
static int F_62 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = V_4 -> V_91 -> V_47 ;
struct V_116 * V_91 = V_4 -> V_91 ;
int V_136 = V_14 -> V_137 ? 48000 : V_91 -> V_128 ;
int V_138 ;
V_27 V_139 ;
if ( ( V_138 = F_59 ( & V_14 -> V_140 [ 0 ] , V_136 ) ) < 0 )
return V_138 ;
if ( V_138 )
F_57 ( V_14 -> V_46 , V_127 ,
V_14 -> V_141 ? 48000 : V_91 -> V_128 ) ;
if ( V_14 -> V_142 && V_1 -> V_123 == 0x30 )
F_57 ( V_14 -> V_46 , V_129 , V_91 -> V_128 ) ;
if ( V_91 -> V_128 == 48000 )
V_139 = 0xfffff ;
else
V_139 = ( 0x100000 / 48000 ) * V_91 -> V_128 +
( ( 0x100000 % 48000 ) * V_91 -> V_128 ) / 48000 ;
F_44 ( V_139 & ~ 0xfffff ) ;
F_26 ( V_14 , V_1 ) ;
F_54 ( V_14 , V_1 ) ;
F_27 ( V_14 -> V_143 [ V_1 -> V_123 / 0x10 ] [ 0 ] ,
F_28 ( V_1 , V_144 ) ) ;
F_27 ( V_14 -> V_143 [ V_1 -> V_123 / 0x10 ] [ 1 ] ,
F_28 ( V_1 , V_145 ) ) ;
F_18 ( ( V_91 -> V_118 == V_119 ? V_146 : 0 ) |
( V_91 -> V_121 > 1 ? V_147 : 0 ) |
V_139 |
0xff000000 ,
F_28 ( V_1 , V_148 ) ) ;
F_20 ( 20 ) ;
F_19 ( V_14 , 0 ) ;
return 0 ;
}
static int F_63 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = V_4 -> V_91 -> V_47 ;
struct V_116 * V_91 = V_4 -> V_91 ;
unsigned int V_149 ;
int V_150 ;
if ( F_59 ( & V_14 -> V_140 [ 0 ] , V_91 -> V_128 ) < 0 )
return - V_26 ;
F_57 ( V_14 -> V_46 , V_127 , V_91 -> V_128 ) ;
F_57 ( V_14 -> V_46 , V_151 , V_91 -> V_128 ) ;
F_57 ( V_14 -> V_46 , V_152 , V_91 -> V_128 ) ;
F_57 ( V_14 -> V_46 , V_129 , V_91 -> V_128 ) ;
F_26 ( V_14 , V_1 ) ;
F_54 ( V_14 , V_1 ) ;
V_150 = ( V_91 -> V_118 == V_119 ) ?
V_153 : V_154 ;
V_150 |= V_91 -> V_121 << 4 ;
F_27 ( V_150 , F_28 ( V_1 , V_155 ) ) ;
#if 0
if (chip->revision == VIA_REV_8233A)
slots = 0;
else
#endif
{
switch ( V_91 -> V_121 ) {
case 1 : V_149 = ( 1 << 0 ) | ( 1 << 4 ) ; break;
case 2 : V_149 = ( 1 << 0 ) | ( 2 << 4 ) ; break;
case 3 : V_149 = ( 1 << 0 ) | ( 2 << 4 ) | ( 5 << 8 ) ; break;
case 4 : V_149 = ( 1 << 0 ) | ( 2 << 4 ) | ( 3 << 8 ) | ( 4 << 12 ) ; break;
case 5 : V_149 = ( 1 << 0 ) | ( 2 << 4 ) | ( 3 << 8 ) | ( 4 << 12 ) | ( 5 << 16 ) ; break;
case 6 : V_149 = ( 1 << 0 ) | ( 2 << 4 ) | ( 3 << 8 ) | ( 4 << 12 ) | ( 5 << 16 ) | ( 6 << 20 ) ; break;
default: V_149 = 0 ; break;
}
}
F_18 ( 0xff000000 | V_149 , F_28 ( V_1 , V_148 ) ) ;
F_20 ( 20 ) ;
F_19 ( V_14 , 0 ) ;
return 0 ;
}
static int F_64 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = V_4 -> V_91 -> V_47 ;
struct V_116 * V_91 = V_4 -> V_91 ;
if ( F_59 ( & V_14 -> V_140 [ 1 ] , V_91 -> V_128 ) < 0 )
return - V_26 ;
F_57 ( V_14 -> V_46 , V_130 , V_91 -> V_128 ) ;
F_26 ( V_14 , V_1 ) ;
F_54 ( V_14 , V_1 ) ;
F_27 ( V_156 , F_28 ( V_1 , V_157 ) ) ;
F_18 ( ( V_91 -> V_118 == V_119 ? V_146 : 0 ) |
( V_91 -> V_121 > 1 ? V_147 : 0 ) |
0xff000000 ,
F_28 ( V_1 , V_148 ) ) ;
F_20 ( 20 ) ;
F_19 ( V_14 , 0 ) ;
return 0 ;
}
static int F_65 ( struct V_13 * V_14 , struct V_1 * V_1 ,
struct V_3 * V_4 )
{
struct V_116 * V_91 = V_4 -> V_91 ;
int V_48 ;
struct V_131 * V_158 ;
V_91 -> V_159 = V_160 ;
V_158 = & V_14 -> V_140 [ V_1 -> V_161 ] ;
F_60 ( & V_158 -> V_134 ) ;
V_158 -> V_135 ++ ;
if ( V_14 -> V_142 && V_1 -> V_123 == 0x30 ) {
V_91 -> V_159 . V_140 = V_14 -> V_46 -> V_140 [ V_162 ] ;
F_66 ( V_91 ) ;
} else if ( V_14 -> V_163 && V_1 -> V_123 < 0x40 ) {
V_91 -> V_159 . V_140 = V_164 ;
V_91 -> V_159 . V_165 = V_91 -> V_159 . V_166 = 48000 ;
} else if ( V_14 -> V_137 && V_1 -> V_123 < 0x40 ) {
V_91 -> V_159 . V_140 = ( V_167 |
V_168 ) ;
V_91 -> V_159 . V_165 = 8000 ;
V_91 -> V_159 . V_166 = 48000 ;
} else if ( ! V_158 -> V_128 ) {
int V_10 = V_1 -> V_161 ? V_169 : V_170 ;
V_91 -> V_159 . V_140 = V_14 -> V_46 -> V_140 [ V_10 ] ;
F_66 ( V_91 ) ;
} else {
V_91 -> V_159 . V_140 = V_171 ;
V_91 -> V_159 . V_166 = V_91 -> V_159 . V_165 = V_158 -> V_128 ;
}
F_61 ( & V_158 -> V_134 ) ;
if ( ( V_48 = F_67 ( V_91 , V_172 ) ) < 0 )
return V_48 ;
V_91 -> V_47 = V_1 ;
V_1 -> V_4 = V_4 ;
return 0 ;
}
static int F_68 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = & V_14 -> V_77 [ V_14 -> V_173 + V_4 -> V_174 ] ;
int V_48 ;
if ( ( V_48 = F_65 ( V_14 , V_1 , V_4 ) ) < 0 )
return V_48 ;
return 0 ;
}
static int F_69 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 ;
unsigned int V_175 ;
int V_48 ;
V_1 = & V_14 -> V_77 [ V_14 -> V_173 + V_4 -> V_174 ] ;
if ( ( V_48 = F_65 ( V_14 , V_1 , V_4 ) ) < 0 )
return V_48 ;
V_175 = V_1 -> V_123 / 0x10 ;
if ( V_14 -> V_176 [ V_175 ] ) {
V_14 -> V_143 [ V_175 ] [ 0 ] =
V_177 - ( V_178 & 31 ) ;
V_14 -> V_143 [ V_175 ] [ 1 ] =
V_177 - ( V_178 & 31 ) ;
V_14 -> V_176 [ V_175 ] -> V_179 [ 0 ] . V_180 &=
~ V_181 ;
F_70 ( V_14 -> V_182 , V_183 |
V_184 ,
& V_14 -> V_176 [ V_175 ] -> V_185 ) ;
}
return 0 ;
}
static int F_71 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = & V_14 -> V_77 [ V_14 -> V_186 ] ;
int V_48 ;
static unsigned int V_121 [] = {
1 , 2 , 4 , 6
} ;
static struct V_187 V_188 = {
. V_102 = F_72 ( V_121 ) ,
. V_189 = V_121 ,
. V_190 = 0 ,
} ;
if ( ( V_48 = F_65 ( V_14 , V_1 , V_4 ) ) < 0 )
return V_48 ;
V_4 -> V_91 -> V_159 . V_191 = 6 ;
if ( V_14 -> V_110 == V_192 )
V_187 ( V_4 -> V_91 , 0 ,
V_193 ,
& V_188 ) ;
return 0 ;
}
static int F_73 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = & V_14 -> V_77 [ V_14 -> V_194 + V_4 -> V_195 -> V_196 ] ;
return F_65 ( V_14 , V_1 , V_4 ) ;
}
static int F_74 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = V_4 -> V_91 -> V_47 ;
struct V_131 * V_158 ;
V_158 = & V_14 -> V_140 [ V_1 -> V_161 ] ;
F_60 ( & V_158 -> V_134 ) ;
V_158 -> V_135 -- ;
if ( ! V_158 -> V_135 )
V_158 -> V_128 = 0 ;
F_61 ( & V_158 -> V_134 ) ;
if ( ! V_158 -> V_128 ) {
if ( ! V_1 -> V_161 ) {
F_75 ( V_14 -> V_46 ,
V_127 , 0 ) ;
F_75 ( V_14 -> V_46 ,
V_151 , 0 ) ;
F_75 ( V_14 -> V_46 ,
V_152 , 0 ) ;
} else
F_75 ( V_14 -> V_46 ,
V_130 , 0 ) ;
}
V_1 -> V_4 = NULL ;
return 0 ;
}
static int F_76 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = V_4 -> V_91 -> V_47 ;
unsigned int V_175 ;
V_175 = V_1 -> V_123 / 0x10 ;
if ( V_14 -> V_176 [ V_175 ] ) {
V_14 -> V_176 [ V_175 ] -> V_179 [ 0 ] . V_180 |=
V_181 ;
F_70 ( V_14 -> V_182 , V_184 ,
& V_14 -> V_176 [ V_175 ] -> V_185 ) ;
}
return F_74 ( V_4 ) ;
}
static void F_77 ( struct V_13 * V_14 , int V_10 , unsigned int V_123 ,
int V_197 , int V_161 )
{
V_14 -> V_77 [ V_10 ] . V_123 = V_123 ;
V_14 -> V_77 [ V_10 ] . V_87 = V_197 * 4 ;
V_14 -> V_77 [ V_10 ] . V_161 = V_161 ;
V_14 -> V_77 [ V_10 ] . V_198 = V_14 -> V_198 + V_123 ;
}
static int T_3 F_78 ( struct V_13 * V_14 )
{
struct V_199 * V_195 ;
int V_9 , V_48 ;
V_14 -> V_173 = 0 ;
V_14 -> V_186 = 4 ;
V_14 -> V_194 = 5 ;
V_14 -> V_76 = 7 ;
V_14 -> V_72 = 0x33033333 ;
V_48 = F_79 ( V_14 -> V_182 , V_14 -> V_182 -> V_200 , 0 , 4 , 1 , & V_195 ) ;
if ( V_48 < 0 )
return V_48 ;
F_80 ( V_195 , V_201 , & V_202 ) ;
F_80 ( V_195 , V_203 , & V_204 ) ;
V_195 -> V_47 = V_14 ;
strcpy ( V_195 -> V_205 , V_14 -> V_182 -> V_200 ) ;
V_14 -> V_206 [ 0 ] = V_195 ;
for ( V_9 = 0 ; V_9 < 4 ; V_9 ++ )
F_77 ( V_14 , V_9 , 0x10 * V_9 , V_9 , 0 ) ;
F_77 ( V_14 , V_14 -> V_194 , V_207 , 6 , 1 ) ;
F_81 ( V_195 , V_208 ,
F_4 ( V_14 -> V_6 ) ,
64 * 1024 , V_209 ) ;
V_48 = F_79 ( V_14 -> V_182 , V_14 -> V_182 -> V_200 , 1 , 1 , 1 , & V_195 ) ;
if ( V_48 < 0 )
return V_48 ;
F_80 ( V_195 , V_201 , & V_210 ) ;
F_80 ( V_195 , V_203 , & V_204 ) ;
V_195 -> V_47 = V_14 ;
strcpy ( V_195 -> V_205 , V_14 -> V_182 -> V_200 ) ;
V_14 -> V_206 [ 1 ] = V_195 ;
F_77 ( V_14 , V_14 -> V_186 , V_211 , 4 , 0 ) ;
F_77 ( V_14 , V_14 -> V_194 + 1 , V_207 + 0x10 , 7 , 1 ) ;
F_81 ( V_195 , V_208 ,
F_4 ( V_14 -> V_6 ) ,
64 * 1024 , V_209 ) ;
return 0 ;
}
static int T_3 F_82 ( struct V_13 * V_14 )
{
struct V_199 * V_195 ;
int V_48 ;
V_14 -> V_186 = 0 ;
V_14 -> V_173 = 1 ;
V_14 -> V_194 = 2 ;
V_14 -> V_76 = 3 ;
V_14 -> V_72 = 0x03033000 ;
V_48 = F_79 ( V_14 -> V_182 , V_14 -> V_182 -> V_200 , 0 , 1 , 1 , & V_195 ) ;
if ( V_48 < 0 )
return V_48 ;
F_80 ( V_195 , V_201 , & V_210 ) ;
F_80 ( V_195 , V_203 , & V_204 ) ;
V_195 -> V_47 = V_14 ;
strcpy ( V_195 -> V_205 , V_14 -> V_182 -> V_200 ) ;
V_14 -> V_206 [ 0 ] = V_195 ;
F_77 ( V_14 , V_14 -> V_186 , V_211 , 4 , 0 ) ;
F_77 ( V_14 , V_14 -> V_194 , V_207 , 6 , 1 ) ;
F_81 ( V_195 , V_208 ,
F_4 ( V_14 -> V_6 ) ,
64 * 1024 , V_209 ) ;
if ( ! F_83 ( V_14 -> V_46 ) )
return 0 ;
V_48 = F_79 ( V_14 -> V_182 , V_14 -> V_182 -> V_200 , 1 , 1 , 0 , & V_195 ) ;
if ( V_48 < 0 )
return V_48 ;
F_80 ( V_195 , V_201 , & V_202 ) ;
V_195 -> V_47 = V_14 ;
strcpy ( V_195 -> V_205 , V_14 -> V_182 -> V_200 ) ;
V_14 -> V_206 [ 1 ] = V_195 ;
F_77 ( V_14 , V_14 -> V_173 , 0x30 , 3 , 0 ) ;
F_81 ( V_195 , V_208 ,
F_4 ( V_14 -> V_6 ) ,
64 * 1024 , V_209 ) ;
return 0 ;
}
static int T_3 F_84 ( struct V_13 * V_14 )
{
struct V_199 * V_195 ;
int V_48 ;
V_14 -> V_173 = 0 ;
V_14 -> V_194 = 1 ;
V_14 -> V_76 = 2 ;
V_14 -> V_72 = 0x77 ;
V_48 = F_79 ( V_14 -> V_182 , V_14 -> V_182 -> V_200 , 0 , 1 , 1 , & V_195 ) ;
if ( V_48 < 0 )
return V_48 ;
F_80 ( V_195 , V_201 , & V_212 ) ;
F_80 ( V_195 , V_203 , & V_213 ) ;
V_195 -> V_47 = V_14 ;
strcpy ( V_195 -> V_205 , V_14 -> V_182 -> V_200 ) ;
V_14 -> V_206 [ 0 ] = V_195 ;
F_77 ( V_14 , 0 , V_214 , 0 , 0 ) ;
F_77 ( V_14 , 1 , V_215 , 0 , 1 ) ;
F_81 ( V_195 , V_208 ,
F_4 ( V_14 -> V_6 ) ,
64 * 1024 , V_209 ) ;
return 0 ;
}
static int F_85 ( struct V_216 * V_217 ,
struct V_218 * V_219 )
{
static char * V_220 [ 2 ] = {
L_11 , L_12
} ;
V_219 -> type = V_221 ;
V_219 -> V_102 = 1 ;
V_219 -> V_222 . V_223 . V_224 = 2 ;
if ( V_219 -> V_222 . V_223 . V_225 >= 2 )
V_219 -> V_222 . V_223 . V_225 = 1 ;
strcpy ( V_219 -> V_222 . V_223 . V_205 , V_220 [ V_219 -> V_222 . V_223 . V_225 ] ) ;
return 0 ;
}
static int F_86 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_13 * V_14 = F_87 ( V_217 ) ;
unsigned long V_198 = V_14 -> V_198 + ( V_217 -> V_185 . V_228 ? ( V_229 + 0x10 ) : V_229 ) ;
V_227 -> V_222 . V_223 . V_225 [ 0 ] = F_29 ( V_198 ) & V_230 ? 1 : 0 ;
return 0 ;
}
static int F_88 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_13 * V_14 = F_87 ( V_217 ) ;
unsigned long V_198 = V_14 -> V_198 + ( V_217 -> V_185 . V_228 ? ( V_229 + 0x10 ) : V_229 ) ;
T_4 V_36 , V_231 ;
F_60 ( & V_14 -> V_75 ) ;
V_231 = F_29 ( V_198 ) ;
V_36 = V_231 & ~ V_230 ;
if ( V_227 -> V_222 . V_223 . V_225 [ 0 ] )
V_36 |= V_230 ;
if ( V_36 != V_231 )
F_27 ( V_36 , V_198 ) ;
F_61 ( & V_14 -> V_75 ) ;
return V_36 != V_231 ;
}
static int F_89 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_13 * V_14 = F_87 ( V_217 ) ;
T_4 V_36 ;
F_90 ( V_14 -> V_6 , V_232 , & V_36 ) ;
V_227 -> V_222 . integer . V_222 [ 0 ] = ( V_36 & V_233 ) ? 1 : 0 ;
return 0 ;
}
static int F_91 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_13 * V_14 = F_87 ( V_217 ) ;
T_4 V_36 , V_231 ;
F_90 ( V_14 -> V_6 , V_232 , & V_231 ) ;
V_36 = V_231 & ~ V_233 ;
if ( V_227 -> V_222 . integer . V_222 [ 0 ] )
V_36 |= V_233 ;
V_14 -> V_142 = V_227 -> V_222 . integer . V_222 [ 0 ] ? 1 : 0 ;
if ( V_36 != V_231 ) {
F_92 ( V_14 -> V_6 , V_232 , V_36 ) ;
return 1 ;
}
return 0 ;
}
static int F_93 ( struct V_216 * V_217 ,
struct V_218 * V_219 )
{
V_219 -> type = V_234 ;
V_219 -> V_102 = 2 ;
V_219 -> V_222 . integer . V_235 = 0 ;
V_219 -> V_222 . integer . V_236 = V_177 ;
return 0 ;
}
static int F_94 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_13 * V_14 = F_87 ( V_217 ) ;
unsigned int V_10 = V_217 -> V_185 . V_237 ;
V_227 -> V_222 . integer . V_222 [ 0 ] = V_177 - V_14 -> V_143 [ V_10 ] [ 0 ] ;
V_227 -> V_222 . integer . V_222 [ 1 ] = V_177 - V_14 -> V_143 [ V_10 ] [ 1 ] ;
return 0 ;
}
static int F_95 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_13 * V_14 = F_87 ( V_217 ) ;
V_227 -> V_222 . integer . V_222 [ 0 ] = V_177 - V_14 -> V_238 [ 0 ] ;
V_227 -> V_222 . integer . V_222 [ 1 ] = V_177 - V_14 -> V_238 [ 1 ] ;
return 0 ;
}
static int F_96 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_13 * V_14 = F_87 ( V_217 ) ;
unsigned int V_10 = V_217 -> V_185 . V_237 ;
unsigned long V_198 = V_14 -> V_198 + 0x10 * V_10 ;
unsigned char V_36 ;
int V_9 , V_239 = 0 ;
for ( V_9 = 0 ; V_9 < 2 ; V_9 ++ ) {
V_36 = V_227 -> V_222 . integer . V_222 [ V_9 ] ;
if ( V_36 > V_177 )
V_36 = V_177 ;
V_36 = V_177 - V_36 ;
V_239 |= V_36 != V_14 -> V_143 [ V_10 ] [ V_9 ] ;
if ( V_239 ) {
V_14 -> V_143 [ V_10 ] [ V_9 ] = V_36 ;
F_27 ( V_36 , V_198 + V_240 + V_9 ) ;
}
}
return V_239 ;
}
static int F_97 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_13 * V_14 = F_87 ( V_217 ) ;
unsigned int V_10 ;
unsigned char V_36 ;
int V_9 , V_239 = 0 ;
for ( V_9 = 0 ; V_9 < 2 ; V_9 ++ ) {
V_36 = V_227 -> V_222 . integer . V_222 [ V_9 ] ;
if ( V_36 > V_177 )
V_36 = V_177 ;
V_36 = V_177 - V_36 ;
if ( V_36 != V_14 -> V_238 [ V_9 ] ) {
V_239 = 1 ;
V_14 -> V_238 [ V_9 ] = V_36 ;
for ( V_10 = 0 ; V_10 < 4 ; V_10 ++ ) {
unsigned long V_198 = V_14 -> V_198 + 0x10 * V_10 ;
V_14 -> V_143 [ V_10 ] [ V_9 ] = V_36 ;
F_27 ( V_36 , V_198 + V_240 + V_9 ) ;
}
}
}
return V_239 ;
}
static void F_98 ( struct V_241 * V_242 )
{
struct V_13 * V_14 = V_242 -> V_47 ;
V_14 -> V_243 = NULL ;
}
static void F_99 ( struct V_45 * V_46 )
{
struct V_13 * V_14 = V_46 -> V_47 ;
V_14 -> V_46 = NULL ;
}
static int T_3 F_100 ( struct V_13 * V_14 , const char * V_244 )
{
struct V_245 V_46 ;
int V_48 ;
static struct V_246 V_247 = {
. V_248 = F_24 ,
. V_249 = F_25 ,
. V_250 = F_22 ,
} ;
if ( ( V_48 = V_241 ( V_14 -> V_182 , 0 , & V_247 , V_14 , & V_14 -> V_243 ) ) < 0 )
return V_48 ;
V_14 -> V_243 -> V_251 = F_98 ;
V_14 -> V_243 -> clock = V_14 -> V_252 ;
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
V_46 . V_47 = V_14 ;
V_46 . V_251 = F_99 ;
V_46 . V_6 = V_14 -> V_6 ;
V_46 . V_253 = V_254 | V_255 ;
if ( ( V_48 = F_101 ( V_14 -> V_243 , & V_46 , & V_14 -> V_46 ) ) < 0 )
return V_48 ;
F_102 ( V_14 -> V_46 , V_256 , V_244 ) ;
if ( V_14 -> V_92 != V_93 ) {
F_103 ( V_14 -> V_46 , V_257 , 0x03 << 4 , 0x03 << 4 ) ;
}
return 0 ;
}
static int T_3 F_104 ( struct V_13 * V_14 , unsigned char * V_258 )
{
struct V_259 * V_260 ;
struct V_261 * V_22 ;
if ( ! V_262 )
return - V_263 ;
V_22 = F_105 ( V_264 , 8 , L_13 ) ;
if ( ! V_22 ) {
F_42 ( V_265 L_14 ,
V_264 ) ;
return - V_266 ;
}
V_14 -> V_259 = V_260 = F_106 () ;
if ( ! V_260 ) {
F_42 ( V_25 L_15 ) ;
F_107 ( V_22 ) ;
return - V_19 ;
}
F_108 ( V_260 , L_16 ) ;
F_109 ( V_260 , L_17 , F_110 ( V_14 -> V_6 ) ) ;
F_111 ( V_260 , & V_14 -> V_6 -> V_2 ) ;
V_260 -> V_267 = V_264 ;
F_112 ( V_260 , V_22 ) ;
* V_258 |= V_268 ;
F_92 ( V_14 -> V_6 , V_269 , * V_258 ) ;
F_113 ( V_14 -> V_259 ) ;
return 0 ;
}
static void F_114 ( struct V_13 * V_14 )
{
if ( V_14 -> V_259 ) {
struct V_261 * V_22 = F_115 ( V_14 -> V_259 ) ;
F_116 ( V_14 -> V_259 ) ;
V_14 -> V_259 = NULL ;
F_107 ( V_22 ) ;
}
}
static inline int F_104 ( struct V_13 * V_14 , unsigned char * V_258 )
{
return - V_270 ;
}
static inline void F_114 ( struct V_13 * V_14 ) { }
static int T_3 F_117 ( struct V_13 * V_14 )
{
int V_9 , V_48 , V_271 ;
unsigned char V_36 ;
V_271 = V_14 -> V_92 == V_272 ? 1 : 2 ;
for ( V_9 = 0 ; V_9 < V_271 ; V_9 ++ ) {
V_273 . V_228 = V_9 ;
V_48 = F_118 ( V_14 -> V_182 , F_119 ( & V_273 , V_14 ) ) ;
if ( V_48 < 0 )
return V_48 ;
}
if ( F_83 ( V_14 -> V_46 ) ) {
V_48 = F_118 ( V_14 -> V_182 , F_119 ( & V_274 , V_14 ) ) ;
if ( V_48 < 0 )
return V_48 ;
}
if ( V_14 -> V_92 != V_272 ) {
struct V_275 V_276 ;
memset ( & V_276 , 0 , sizeof( V_276 ) ) ;
strcpy ( V_276 . V_205 , L_18 ) ;
V_276 . V_277 = V_278 ;
if ( ! F_120 ( V_14 -> V_182 , & V_276 ) ) {
F_39 ( V_279 L_19 ) ;
V_48 = F_118 ( V_14 -> V_182 , F_119 ( & V_280 , V_14 ) ) ;
if ( V_48 < 0 )
return V_48 ;
}
else
{
for ( V_9 = 0 ; V_9 < 4 ; ++ V_9 ) {
struct V_216 * V_281 ;
V_281 = F_119 (
& V_282 , V_14 ) ;
if ( ! V_281 )
return - V_19 ;
V_281 -> V_185 . V_237 = V_9 ;
V_48 = F_118 ( V_14 -> V_182 , V_281 ) ;
if ( V_48 < 0 )
return V_48 ;
V_14 -> V_176 [ V_9 ] = V_281 ;
}
}
}
F_90 ( V_14 -> V_6 , V_232 , & V_36 ) ;
V_36 = ( V_36 & ~ V_283 ) | V_284 ;
V_36 &= ~ V_233 ;
F_92 ( V_14 -> V_6 , V_232 , V_36 ) ;
return 0 ;
}
static int T_3 F_121 ( struct V_13 * V_14 )
{
unsigned char V_258 , V_285 ;
int V_286 = 0 ;
V_258 = V_14 -> V_287 ;
V_285 = V_14 -> V_288 ;
V_258 |= V_289 ;
V_258 &= ~ V_268 ;
if ( V_14 -> V_110 >= V_290 ) {
V_286 = 1 ;
if ( V_291 >= 0x200 ) {
V_291 &= 0xfffc ;
F_122 ( V_14 -> V_6 , 0x18 , V_291 | 0x01 ) ;
#ifdef F_123
V_14 -> V_292 = V_291 ;
#endif
} else {
V_291 = F_124 ( V_14 -> V_6 , 2 ) ;
}
} else {
switch ( V_291 ) {
case 0x300 :
case 0x310 :
case 0x320 :
case 0x330 :
V_285 &= ~ ( 3 << 2 ) ;
V_285 |= ( V_291 & 0x0030 ) >> 2 ;
break;
default:
if ( V_258 & V_293 )
V_291 = 0x300 + ( ( V_285 & 0x000c ) << 2 ) ;
break;
}
}
if ( V_291 >= 0x200 &&
( V_14 -> V_294 = F_105 ( V_291 , 2 , L_20 ) )
!= NULL ) {
if ( V_286 )
V_258 |= V_295 ;
V_258 |= V_293 ;
} else {
if ( V_286 )
V_258 &= ~ V_295 ;
V_258 &= ~ V_293 ;
V_291 = 0 ;
}
F_92 ( V_14 -> V_6 , V_269 , V_258 ) ;
F_92 ( V_14 -> V_6 , V_296 , V_285 ) ;
if ( V_14 -> V_294 ) {
if ( F_125 ( V_14 -> V_182 , 0 , V_297 ,
V_291 , V_298 ,
V_14 -> V_68 , 0 , & V_14 -> V_73 ) < 0 ) {
F_42 ( V_265 L_21
L_22 , V_291 ) ;
V_258 &= ~ V_293 ;
} else {
V_258 &= ~ V_289 ;
}
F_92 ( V_14 -> V_6 , V_269 , V_258 ) ;
}
F_104 ( V_14 , & V_258 ) ;
#ifdef F_123
V_14 -> V_299 = V_258 ;
V_14 -> V_300 = V_285 ;
#endif
return 0 ;
}
static void F_126 ( struct V_301 * V_302 ,
struct V_303 * V_304 )
{
struct V_13 * V_14 = V_302 -> V_47 ;
int V_9 ;
F_127 ( V_304 , L_23 , V_14 -> V_182 -> V_305 ) ;
for ( V_9 = 0 ; V_9 < 0xa0 ; V_9 += 4 ) {
F_127 ( V_304 , L_24 , V_9 , F_15 ( V_14 -> V_198 + V_9 ) ) ;
}
}
static void T_3 F_128 ( struct V_13 * V_14 )
{
struct V_301 * V_302 ;
if ( ! F_129 ( V_14 -> V_182 , L_25 , & V_302 ) )
F_130 ( V_302 , V_14 , F_126 ) ;
}
static int F_131 ( struct V_13 * V_14 )
{
unsigned int V_36 ;
unsigned long V_306 ;
unsigned char V_307 ;
#if 0
if (chip->chip_type == TYPE_VIA686)
pci_write_config_byte(chip->pci, VIA_FUNC_ENABLE, 0);
#endif
F_90 ( V_14 -> V_6 , V_308 , & V_307 ) ;
if ( ! ( V_307 & V_309 ) ) {
F_92 ( V_14 -> V_6 , V_310 ,
V_311 |
V_312 |
V_313 ) ;
F_20 ( 100 ) ;
#if 1
F_92 ( V_14 -> V_6 , V_310 , 0x00 ) ;
F_20 ( 100 ) ;
#else
F_92 ( V_14 -> V_6 , V_310 ,
V_312 | V_313 ) ;
F_20 ( 2 ) ;
#endif
F_92 ( V_14 -> V_6 , V_310 , V_314 ) ;
F_20 ( 100 ) ;
}
F_90 ( V_14 -> V_6 , V_310 , & V_307 ) ;
if ( ( V_307 & V_314 ) != V_314 ) {
F_92 ( V_14 -> V_6 , V_310 , V_314 ) ;
F_20 ( 100 ) ;
}
V_306 = V_315 + F_132 ( 750 ) ;
do {
F_90 ( V_14 -> V_6 , V_308 , & V_307 ) ;
if ( V_307 & V_309 )
break;
F_133 ( 1 ) ;
} while ( F_134 ( V_315 , V_306 ) );
if ( ( V_36 = F_14 ( V_14 ) ) & V_39 )
F_7 ( V_25 L_26 , V_36 ) ;
#if 0
snd_via82xx_codec_xwrite(chip, VIA_REG_AC97_READ |
VIA_REG_AC97_SECONDARY_VALID |
(VIA_REG_AC97_CODEC_ID_SECONDARY << VIA_REG_AC97_CODEC_ID_SHIFT));
end_time = jiffies + msecs_to_jiffies(750);
snd_via82xx_codec_xwrite(chip, VIA_REG_AC97_READ |
VIA_REG_AC97_SECONDARY_VALID |
(VIA_REG_AC97_CODEC_ID_SECONDARY << VIA_REG_AC97_CODEC_ID_SHIFT));
do {
if ((val = snd_via82xx_codec_xread(chip)) & VIA_REG_AC97_SECONDARY_VALID) {
chip->ac97_secondary = 1;
goto __ac97_ok2;
}
schedule_timeout_uninterruptible(1);
} while (time_before(jiffies, end_time));
__ac97_ok2:
#endif
if ( V_14 -> V_92 == V_93 ) {
F_92 ( V_14 -> V_6 , V_316 , 0 ) ;
F_18 ( 0 , F_16 ( V_14 , V_317 ) ) ;
}
if ( V_14 -> V_92 != V_93 ) {
struct V_5 * V_6 ;
V_6 = F_135 ( 0x1106 , 0x3068 , NULL ) ;
if ( V_6 ) {
unsigned char V_318 ;
F_90 ( V_6 , 0x44 , & V_318 ) ;
F_92 ( V_6 , 0x44 , V_318 | 0x40 ) ;
F_136 ( V_6 ) ;
}
}
if ( V_14 -> V_92 != V_272 ) {
int V_9 , V_10 ;
for ( V_10 = 0 ; V_10 < 4 ; V_10 ++ ) {
unsigned long V_198 = V_14 -> V_198 + 0x10 * V_10 ;
for ( V_9 = 0 ; V_9 < 2 ; V_9 ++ ) {
V_14 -> V_143 [ V_10 ] [ V_9 ] = V_14 -> V_238 [ V_9 ] ;
F_27 ( V_14 -> V_238 [ V_9 ] ,
V_198 + V_240 + V_9 ) ;
}
}
}
return 0 ;
}
static int F_137 ( struct V_5 * V_6 , T_5 V_319 )
{
struct V_320 * V_182 = F_138 ( V_6 ) ;
struct V_13 * V_14 = V_182 -> V_47 ;
int V_9 ;
F_139 ( V_182 , V_321 ) ;
for ( V_9 = 0 ; V_9 < 2 ; V_9 ++ )
F_140 ( V_14 -> V_206 [ V_9 ] ) ;
for ( V_9 = 0 ; V_9 < V_14 -> V_76 ; V_9 ++ )
F_26 ( V_14 , & V_14 -> V_77 [ V_9 ] ) ;
F_141 ( V_14 -> V_68 ) ;
F_142 ( V_14 -> V_46 ) ;
if ( V_14 -> V_92 != V_93 ) {
F_90 ( V_14 -> V_6 , V_232 , & V_14 -> V_322 ) ;
V_14 -> V_323 [ 0 ] = F_29 ( V_14 -> V_198 + V_229 ) ;
V_14 -> V_323 [ 1 ] = F_29 ( V_14 -> V_198 + V_229 + 0x10 ) ;
}
F_143 ( V_6 ) ;
F_144 ( V_6 ) ;
F_145 ( V_6 , F_146 ( V_6 , V_319 ) ) ;
return 0 ;
}
static int F_147 ( struct V_5 * V_6 )
{
struct V_320 * V_182 = F_138 ( V_6 ) ;
struct V_13 * V_14 = V_182 -> V_47 ;
int V_9 ;
F_145 ( V_6 , V_324 ) ;
F_148 ( V_6 ) ;
if ( F_149 ( V_6 ) < 0 ) {
F_42 ( V_25 L_27
L_28 ) ;
F_150 ( V_182 ) ;
return - V_40 ;
}
F_151 ( V_6 ) ;
F_131 ( V_14 ) ;
if ( V_14 -> V_92 == V_93 ) {
if ( V_14 -> V_292 )
F_122 ( V_14 -> V_6 , 0x18 , V_14 -> V_292 | 0x01 ) ;
F_92 ( V_14 -> V_6 , V_269 , V_14 -> V_299 ) ;
F_92 ( V_14 -> V_6 , V_296 , V_14 -> V_300 ) ;
} else {
F_92 ( V_14 -> V_6 , V_232 , V_14 -> V_322 ) ;
F_27 ( V_14 -> V_323 [ 0 ] , V_14 -> V_198 + V_229 ) ;
F_27 ( V_14 -> V_323 [ 1 ] , V_14 -> V_198 + V_229 + 0x10 ) ;
}
F_152 ( V_14 -> V_46 ) ;
for ( V_9 = 0 ; V_9 < V_14 -> V_76 ; V_9 ++ )
F_26 ( V_14 , & V_14 -> V_77 [ V_9 ] ) ;
F_139 ( V_182 , V_325 ) ;
return 0 ;
}
static int F_153 ( struct V_13 * V_14 )
{
unsigned int V_9 ;
if ( V_14 -> V_68 < 0 )
goto V_326;
for ( V_9 = 0 ; V_9 < V_14 -> V_76 ; V_9 ++ )
F_26 ( V_14 , & V_14 -> V_77 [ V_9 ] ) ;
if ( V_14 -> V_68 >= 0 )
F_154 ( V_14 -> V_68 , V_14 ) ;
V_326:
F_107 ( V_14 -> V_294 ) ;
F_155 ( V_14 -> V_6 ) ;
if ( V_14 -> V_92 == V_93 ) {
F_114 ( V_14 ) ;
F_92 ( V_14 -> V_6 , V_269 , V_14 -> V_287 ) ;
F_92 ( V_14 -> V_6 , V_296 , V_14 -> V_288 ) ;
}
F_143 ( V_14 -> V_6 ) ;
F_13 ( V_14 ) ;
return 0 ;
}
static int F_156 ( struct V_327 * V_196 )
{
struct V_13 * V_14 = V_196 -> V_328 ;
return F_153 ( V_14 ) ;
}
static int T_3 F_157 ( struct V_320 * V_182 ,
struct V_5 * V_6 ,
int V_92 ,
int V_110 ,
unsigned int V_252 ,
struct V_13 * * V_329 )
{
struct V_13 * V_14 ;
int V_48 ;
static struct V_330 V_247 = {
. V_331 = F_156 ,
} ;
if ( ( V_48 = F_149 ( V_6 ) ) < 0 )
return V_48 ;
if ( ( V_14 = F_158 ( sizeof( * V_14 ) , V_21 ) ) == NULL ) {
F_143 ( V_6 ) ;
return - V_19 ;
}
V_14 -> V_92 = V_92 ;
V_14 -> V_110 = V_110 ;
F_159 ( & V_14 -> V_75 ) ;
F_159 ( & V_14 -> V_140 [ 0 ] . V_134 ) ;
F_159 ( & V_14 -> V_140 [ 1 ] . V_134 ) ;
V_14 -> V_182 = V_182 ;
V_14 -> V_6 = V_6 ;
V_14 -> V_68 = - 1 ;
F_90 ( V_6 , V_269 , & V_14 -> V_287 ) ;
F_90 ( V_6 , V_296 , & V_14 -> V_288 ) ;
F_92 ( V_14 -> V_6 , V_269 ,
V_14 -> V_287 & ~ ( V_332 | V_333 ) ) ;
if ( ( V_48 = F_160 ( V_6 , V_182 -> V_334 ) ) < 0 ) {
F_13 ( V_14 ) ;
F_143 ( V_6 ) ;
return V_48 ;
}
V_14 -> V_198 = F_124 ( V_6 , 0 ) ;
if ( F_161 ( V_6 -> V_68 ,
V_92 == V_335 ?
F_35 : F_30 ,
V_336 ,
V_182 -> V_334 , V_14 ) ) {
F_7 ( V_25 L_29 , V_6 -> V_68 ) ;
F_153 ( V_14 ) ;
return - V_266 ;
}
V_14 -> V_68 = V_6 -> V_68 ;
if ( V_252 >= 8000 && V_252 <= 48000 )
V_14 -> V_252 = V_252 ;
F_141 ( V_14 -> V_68 ) ;
if ( ( V_48 = F_131 ( V_14 ) ) < 0 ) {
F_153 ( V_14 ) ;
return V_48 ;
}
if ( ( V_48 = F_162 ( V_182 , V_337 , V_14 , & V_247 ) ) < 0 ) {
F_153 ( V_14 ) ;
return V_48 ;
}
F_151 ( V_6 ) ;
F_163 ( V_182 , & V_6 -> V_2 ) ;
* V_329 = V_14 ;
return 0 ;
}
static int T_3 F_164 ( struct V_5 * V_6 , int V_110 )
{
const struct V_338 * V_339 ;
V_339 = F_165 ( V_6 , V_340 ) ;
if ( V_339 ) {
F_166 ( V_279 L_30 ,
V_339 -> V_205 ) ;
return V_339 -> V_222 ;
}
if ( V_110 >= V_341 )
return V_342 ;
F_42 ( V_279 L_31 ) ;
F_42 ( V_279 L_32 ) ;
F_42 ( V_279 L_33 ) ;
F_42 ( V_279 L_34 ) ;
return V_343 ;
}
static int T_3 F_167 ( struct V_5 * V_6 ,
const struct V_344 * V_345 )
{
struct V_320 * V_182 ;
struct V_13 * V_14 ;
int V_92 = 0 , V_346 ;
unsigned int V_9 ;
int V_48 ;
V_48 = F_168 ( V_228 , V_185 , V_347 , 0 , & V_182 ) ;
if ( V_48 < 0 )
return V_48 ;
V_346 = V_345 -> V_348 ;
switch ( V_346 ) {
case V_349 :
strcpy ( V_182 -> V_334 , L_35 ) ;
sprintf ( V_182 -> V_200 , L_36 , V_6 -> V_110 ) ;
V_92 = V_93 ;
break;
case V_350 :
V_92 = V_335 ;
sprintf ( V_182 -> V_200 , L_37 , V_6 -> V_110 ) ;
for ( V_9 = 0 ; V_9 < F_72 ( V_351 ) ; V_9 ++ ) {
if ( V_6 -> V_110 == V_351 [ V_9 ] . V_110 ) {
V_92 = V_351 [ V_9 ] . type ;
strcpy ( V_182 -> V_200 , V_351 [ V_9 ] . V_205 ) ;
break;
}
}
if ( V_92 != V_272 ) {
if ( V_352 == V_353 )
V_352 = F_164 ( V_6 , V_6 -> V_110 ) ;
if ( V_352 == V_354 )
V_92 = V_272 ;
else
V_92 = V_335 ;
}
if ( V_92 == V_272 )
strcpy ( V_182 -> V_334 , L_38 ) ;
else if ( V_6 -> V_110 >= V_355 )
strcpy ( V_182 -> V_334 , L_39 ) ;
else
strcpy ( V_182 -> V_334 , L_40 ) ;
break;
default:
F_7 ( V_25 L_41 , V_346 ) ;
V_48 = - V_26 ;
goto V_356;
}
if ( ( V_48 = F_157 ( V_182 , V_6 , V_92 , V_6 -> V_110 ,
V_252 , & V_14 ) ) < 0 )
goto V_356;
V_182 -> V_47 = V_14 ;
if ( ( V_48 = F_100 ( V_14 , V_357 ) ) < 0 )
goto V_356;
if ( V_92 == V_93 ) {
if ( ( V_48 = F_84 ( V_14 ) ) < 0 ||
( V_48 = F_121 ( V_14 ) ) < 0 )
goto V_356;
} else {
if ( V_92 == V_272 ) {
if ( ( V_48 = F_82 ( V_14 ) ) < 0 )
goto V_356;
} else {
if ( ( V_48 = F_78 ( V_14 ) ) < 0 )
goto V_356;
if ( V_352 == V_343 )
V_14 -> V_163 = 1 ;
else if ( V_352 == V_358 )
V_14 -> V_141 = 1 ;
else if ( V_352 == V_342 ) {
V_14 -> V_141 = 1 ;
V_14 -> V_137 = 1 ;
}
}
if ( ( V_48 = F_117 ( V_14 ) ) < 0 )
goto V_356;
}
for ( V_9 = 0 ; V_9 < V_14 -> V_76 ; V_9 ++ )
F_26 ( V_14 , & V_14 -> V_77 [ V_9 ] ) ;
snprintf ( V_182 -> V_305 , sizeof( V_182 -> V_305 ) ,
L_42 , V_182 -> V_200 ,
F_169 ( V_14 -> V_46 ) , V_14 -> V_198 , V_14 -> V_68 ) ;
F_128 ( V_14 ) ;
if ( ( V_48 = F_170 ( V_182 ) ) < 0 ) {
F_171 ( V_182 ) ;
return V_48 ;
}
F_172 ( V_6 , V_182 ) ;
return 0 ;
V_356:
F_171 ( V_182 ) ;
return V_48 ;
}
static void T_6 F_173 ( struct V_5 * V_6 )
{
F_171 ( F_138 ( V_6 ) ) ;
F_172 ( V_6 , NULL ) ;
}
static int T_7 F_174 ( void )
{
return F_175 ( & V_334 ) ;
}
static void T_8 F_176 ( void )
{
F_177 ( & V_334 ) ;
}
