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
F_7 ( & V_6 -> V_2 , L_1 ) ;
return - V_25 ;
}
V_24 = F_8 ( V_4 , V_11 ) ;
( ( V_26 * ) V_2 -> V_15 . V_16 ) [ V_10 << 1 ] = F_9 ( V_24 ) ;
V_22 = F_10 ( V_4 , V_11 , V_12 ) ;
V_12 -= V_22 ;
if ( ! V_12 ) {
if ( V_9 == V_7 - 1 )
V_23 = V_27 ;
else
V_23 = V_28 ;
} else
V_23 = 0 ;
( ( V_26 * ) V_2 -> V_15 . V_16 ) [ ( V_10 << 1 ) + 1 ] = F_9 ( V_22 | V_23 ) ;
V_2 -> V_20 [ V_10 ] . V_29 = V_11 ;
V_2 -> V_20 [ V_10 ] . V_30 = V_22 ;
V_11 += V_22 ;
V_10 ++ ;
} while ( V_12 > 0 );
}
V_2 -> V_31 = V_10 ;
V_2 -> V_32 = V_7 * V_8 ;
V_2 -> V_33 = V_2 -> V_32 / 2 ;
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
return F_15 ( F_16 ( V_14 , V_34 ) ) ;
}
static inline void F_17 ( struct V_13 * V_14 , unsigned int V_35 )
{
F_18 ( V_35 , F_16 ( V_14 , V_34 ) ) ;
}
static int F_19 ( struct V_13 * V_14 , int V_36 )
{
unsigned int V_37 = 1000 ;
unsigned int V_35 ;
while ( V_37 -- > 0 ) {
F_20 ( 1 ) ;
if ( ! ( ( V_35 = F_14 ( V_14 ) ) & V_38 ) )
return V_35 & 0xffff ;
}
F_7 ( V_14 -> V_39 -> V_2 , L_2 ,
V_36 , F_14 ( V_14 ) ) ;
return - V_40 ;
}
static int F_21 ( struct V_13 * V_14 , int V_36 )
{
unsigned int V_37 = 1000 ;
unsigned int V_35 , V_41 ;
unsigned int V_42 = ! V_36 ? V_43 :
V_44 ;
while ( V_37 -- > 0 ) {
V_35 = F_14 ( V_14 ) ;
V_41 = V_35 & ( V_38 | V_42 ) ;
if ( V_41 == V_42 )
return V_35 & 0xffff ;
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
unsigned short V_35 )
{
struct V_13 * V_14 = V_46 -> V_47 ;
unsigned int V_52 ;
V_52 = ! V_46 -> V_49 ? V_53 : V_54 ;
V_52 <<= V_55 ;
V_52 |= V_51 << V_56 ;
V_52 |= V_35 << V_57 ;
F_17 ( V_14 , V_52 ) ;
F_19 ( V_14 , V_46 -> V_49 ) ;
}
static unsigned short F_25 ( struct V_45 * V_46 , unsigned short V_51 )
{
struct V_13 * V_14 = V_46 -> V_47 ;
unsigned int V_52 , V_35 = 0xffff ;
int V_58 = 0 ;
V_52 = V_46 -> V_49 << V_55 ;
V_52 |= V_46 -> V_49 ? V_44 : V_43 ;
V_52 |= V_59 ;
V_52 |= ( V_51 & 0x7f ) << V_56 ;
while ( 1 ) {
if ( V_58 ++ > 3 ) {
F_7 ( V_14 -> V_39 -> V_2 ,
L_3 ,
V_46 -> V_49 , F_14 ( V_14 ) ) ;
return 0xffff ;
}
F_17 ( V_14 , V_52 ) ;
F_20 ( 20 ) ;
if ( F_21 ( V_14 , V_46 -> V_49 ) >= 0 ) {
F_20 ( 25 ) ;
V_35 = F_14 ( V_14 ) ;
break;
}
}
return V_35 & 0xffff ;
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
unsigned char V_35 ;
if ( V_14 -> V_92 != V_93 )
V_35 = V_94 ;
else
V_35 = 0 ;
switch ( V_90 ) {
case V_95 :
case V_96 :
V_35 |= V_97 ;
V_1 -> V_82 = 1 ;
break;
case V_98 :
case V_99 :
V_35 = V_61 ;
V_1 -> V_82 = 0 ;
break;
case V_100 :
V_35 |= V_60 ;
V_1 -> V_82 = 0 ;
break;
case V_101 :
V_1 -> V_82 = 1 ;
break;
default:
return - V_25 ;
}
F_27 ( V_35 , F_28 ( V_1 , V_63 ) ) ;
if ( V_90 == V_98 )
F_26 ( V_14 , V_1 ) ;
return 0 ;
}
static inline unsigned int F_38 ( struct V_13 * V_14 ,
struct V_1 * V_1 ,
unsigned int V_10 ,
unsigned int V_102 )
{
unsigned int V_30 , V_103 , V_104 ;
V_30 = V_1 -> V_20 [ V_10 ] . V_30 ;
V_103 = V_1 -> V_20 [ V_10 ] . V_29 ;
V_104 = V_103 + V_30 - V_102 ;
if ( V_104 >= V_1 -> V_32 )
V_104 -= V_1 -> V_32 ;
if ( V_30 < V_102 ) {
F_39 ( V_14 -> V_39 -> V_2 ,
L_4 ,
( int ) V_30 , ( int ) V_102 ) ;
V_104 = V_1 -> V_66 ;
} else {
if ( ! V_102 ) {
int V_105 = V_104 - V_1 -> V_66 ;
if ( V_105 < 0 )
V_105 += V_1 -> V_32 ;
if ( ( unsigned int ) V_105 > V_1 -> V_8 )
V_104 = V_103 ;
}
if ( F_40 ( V_1 , V_104 ) ) {
#ifdef F_41
F_39 ( V_14 -> V_39 -> V_2 ,
L_5 ,
V_10 , V_1 -> V_31 ,
V_1 -> V_66 , V_1 -> V_33 ,
V_1 -> V_20 [ V_10 ] . V_29 ,
V_1 -> V_20 [ V_10 ] . V_30 , V_102 ) ;
#endif
V_104 = V_103 + V_30 ;
if ( F_40 ( V_1 , V_104 ) ) {
F_39 ( V_14 -> V_39 -> V_2 ,
L_6 ) ;
V_104 = V_1 -> V_66 ;
}
}
}
return V_104 ;
}
static T_2 F_42 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = V_4 -> V_91 -> V_47 ;
unsigned int V_10 , V_106 , V_102 , V_104 ;
if ( F_43 ( ! V_1 -> V_31 ) )
return 0 ;
if ( ! ( F_29 ( F_28 ( V_1 , V_64 ) ) & V_89 ) )
return 0 ;
F_32 ( & V_14 -> V_75 ) ;
V_102 = F_15 ( F_28 ( V_1 , V_107 ) ) & 0xffffff ;
V_106 = F_15 ( F_28 ( V_1 , V_108 ) ) ;
if ( V_106 <= ( unsigned int ) V_1 -> V_15 . V_24 )
V_10 = 0 ;
else
V_10 = ( ( V_106 - ( unsigned int ) V_1 -> V_15 . V_24 ) / 8 - 1 ) % V_1 -> V_31 ;
V_104 = F_38 ( V_14 , V_1 , V_10 , V_102 ) ;
V_1 -> V_66 = V_104 ;
F_33 ( & V_14 -> V_75 ) ;
return F_44 ( V_4 -> V_91 , V_104 ) ;
}
static T_2 F_45 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = V_4 -> V_91 -> V_47 ;
unsigned int V_10 , V_102 , V_104 ;
int V_70 ;
if ( F_43 ( ! V_1 -> V_31 ) )
return 0 ;
F_32 ( & V_14 -> V_75 ) ;
V_102 = F_15 ( F_28 ( V_1 , V_107 ) ) ;
V_70 = V_1 -> V_83 ;
if ( ! V_70 )
V_70 = F_29 ( F_28 ( V_1 , V_64 ) ) ;
if ( V_14 -> V_109 == V_110 && ( V_70 & V_79 ) )
F_37 ( V_4 , V_95 ) ;
if ( ! ( V_70 & V_89 ) ) {
V_104 = 0 ;
goto V_111;
}
if ( V_102 & 0xffffff ) {
V_10 = V_102 >> 24 ;
if ( V_10 >= V_1 -> V_31 ) {
#ifdef F_41
F_39 ( V_14 -> V_39 -> V_2 ,
L_7 , V_10 ,
V_1 -> V_31 ) ;
#endif
V_104 = V_1 -> V_66 ;
} else {
V_102 &= 0xffffff ;
V_104 = F_38 ( V_14 , V_1 , V_10 , V_102 ) ;
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
V_111:
V_1 -> V_66 = V_104 ;
F_33 ( & V_14 -> V_75 ) ;
return F_44 ( V_4 -> V_91 , V_104 ) ;
}
static int F_46 ( struct V_3 * V_4 ,
struct V_112 * V_113 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = V_4 -> V_91 -> V_47 ;
int V_48 ;
V_48 = F_47 ( V_4 , F_48 ( V_113 ) ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = F_1 ( V_1 , V_4 , V_14 -> V_6 ,
F_49 ( V_113 ) ,
F_50 ( V_113 ) ) ;
if ( V_48 < 0 )
return V_48 ;
return 0 ;
}
static int F_51 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = V_4 -> V_91 -> V_47 ;
F_11 ( V_1 , V_4 , V_14 -> V_6 ) ;
F_52 ( V_4 ) ;
return 0 ;
}
static void F_53 ( struct V_13 * V_14 , struct V_1 * V_1 )
{
F_19 ( V_14 , 0 ) ;
F_18 ( ( V_26 ) V_1 -> V_15 . V_24 , F_28 ( V_1 , V_114 ) ) ;
F_20 ( 20 ) ;
F_19 ( V_14 , 0 ) ;
}
static void F_54 ( struct V_13 * V_14 , struct V_1 * V_1 ,
struct V_115 * V_91 )
{
F_26 ( V_14 , V_1 ) ;
F_53 ( V_14 , V_1 ) ;
F_27 ( V_116 |
( V_91 -> V_117 == V_118 ? V_119 : 0 ) |
( V_91 -> V_120 > 1 ? V_121 : 0 ) |
( ( V_1 -> V_122 & 0x10 ) == 0 ? V_123 : 0 ) |
V_124 |
V_125 , F_28 ( V_1 , V_65 ) ) ;
}
static int F_55 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = V_4 -> V_91 -> V_47 ;
struct V_115 * V_91 = V_4 -> V_91 ;
F_56 ( V_14 -> V_46 , V_126 , V_91 -> V_127 ) ;
F_56 ( V_14 -> V_46 , V_128 , V_91 -> V_127 ) ;
F_54 ( V_14 , V_1 , V_91 ) ;
return 0 ;
}
static int F_57 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = V_4 -> V_91 -> V_47 ;
struct V_115 * V_91 = V_4 -> V_91 ;
F_56 ( V_14 -> V_46 , V_129 , V_91 -> V_127 ) ;
F_54 ( V_14 , V_1 , V_91 ) ;
return 0 ;
}
static int F_58 ( struct V_130 * V_131 , int V_127 )
{
int V_132 = 0 ;
F_59 ( & V_131 -> V_133 ) ;
if ( V_131 -> V_127 != V_127 ) {
if ( V_131 -> V_127 && V_131 -> V_134 > 1 )
V_132 = - V_25 ;
else {
V_131 -> V_127 = V_127 ;
V_132 = 1 ;
}
}
F_60 ( & V_131 -> V_133 ) ;
return V_132 ;
}
static int F_61 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = V_4 -> V_91 -> V_47 ;
struct V_115 * V_91 = V_4 -> V_91 ;
int V_135 = V_14 -> V_136 ? 48000 : V_91 -> V_127 ;
int V_137 ;
V_26 V_138 ;
if ( ( V_137 = F_58 ( & V_14 -> V_139 [ 0 ] , V_135 ) ) < 0 )
return V_137 ;
if ( V_137 )
F_56 ( V_14 -> V_46 , V_126 ,
V_14 -> V_140 ? 48000 : V_91 -> V_127 ) ;
if ( V_14 -> V_141 && V_1 -> V_122 == 0x30 )
F_56 ( V_14 -> V_46 , V_128 , V_91 -> V_127 ) ;
if ( V_91 -> V_127 == 48000 )
V_138 = 0xfffff ;
else
V_138 = ( 0x100000 / 48000 ) * V_91 -> V_127 +
( ( 0x100000 % 48000 ) * V_91 -> V_127 ) / 48000 ;
F_43 ( V_138 & ~ 0xfffff ) ;
F_26 ( V_14 , V_1 ) ;
F_53 ( V_14 , V_1 ) ;
F_27 ( V_14 -> V_142 [ V_1 -> V_122 / 0x10 ] [ 0 ] ,
F_28 ( V_1 , V_143 ) ) ;
F_27 ( V_14 -> V_142 [ V_1 -> V_122 / 0x10 ] [ 1 ] ,
F_28 ( V_1 , V_144 ) ) ;
F_18 ( ( V_91 -> V_117 == V_118 ? V_145 : 0 ) |
( V_91 -> V_120 > 1 ? V_146 : 0 ) |
V_138 |
0xff000000 ,
F_28 ( V_1 , V_147 ) ) ;
F_20 ( 20 ) ;
F_19 ( V_14 , 0 ) ;
return 0 ;
}
static int F_62 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = V_4 -> V_91 -> V_47 ;
struct V_115 * V_91 = V_4 -> V_91 ;
unsigned int V_148 ;
int V_149 ;
if ( F_58 ( & V_14 -> V_139 [ 0 ] , V_91 -> V_127 ) < 0 )
return - V_25 ;
F_56 ( V_14 -> V_46 , V_126 , V_91 -> V_127 ) ;
F_56 ( V_14 -> V_46 , V_150 , V_91 -> V_127 ) ;
F_56 ( V_14 -> V_46 , V_151 , V_91 -> V_127 ) ;
F_56 ( V_14 -> V_46 , V_128 , V_91 -> V_127 ) ;
F_26 ( V_14 , V_1 ) ;
F_53 ( V_14 , V_1 ) ;
V_149 = ( V_91 -> V_117 == V_118 ) ?
V_152 : V_153 ;
V_149 |= V_91 -> V_120 << 4 ;
F_27 ( V_149 , F_28 ( V_1 , V_154 ) ) ;
#if 0
if (chip->revision == VIA_REV_8233A)
slots = 0;
else
#endif
{
switch ( V_91 -> V_120 ) {
case 1 : V_148 = ( 1 << 0 ) | ( 1 << 4 ) ; break;
case 2 : V_148 = ( 1 << 0 ) | ( 2 << 4 ) ; break;
case 3 : V_148 = ( 1 << 0 ) | ( 2 << 4 ) | ( 5 << 8 ) ; break;
case 4 : V_148 = ( 1 << 0 ) | ( 2 << 4 ) | ( 3 << 8 ) | ( 4 << 12 ) ; break;
case 5 : V_148 = ( 1 << 0 ) | ( 2 << 4 ) | ( 3 << 8 ) | ( 4 << 12 ) | ( 5 << 16 ) ; break;
case 6 : V_148 = ( 1 << 0 ) | ( 2 << 4 ) | ( 3 << 8 ) | ( 4 << 12 ) | ( 5 << 16 ) | ( 6 << 20 ) ; break;
default: V_148 = 0 ; break;
}
}
F_18 ( 0xff000000 | V_148 , F_28 ( V_1 , V_147 ) ) ;
F_20 ( 20 ) ;
F_19 ( V_14 , 0 ) ;
return 0 ;
}
static int F_63 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = V_4 -> V_91 -> V_47 ;
struct V_115 * V_91 = V_4 -> V_91 ;
if ( F_58 ( & V_14 -> V_139 [ 1 ] , V_91 -> V_127 ) < 0 )
return - V_25 ;
F_56 ( V_14 -> V_46 , V_129 , V_91 -> V_127 ) ;
F_26 ( V_14 , V_1 ) ;
F_53 ( V_14 , V_1 ) ;
F_27 ( V_155 , F_28 ( V_1 , V_156 ) ) ;
F_18 ( ( V_91 -> V_117 == V_118 ? V_145 : 0 ) |
( V_91 -> V_120 > 1 ? V_146 : 0 ) |
0xff000000 ,
F_28 ( V_1 , V_147 ) ) ;
F_20 ( 20 ) ;
F_19 ( V_14 , 0 ) ;
return 0 ;
}
static int F_64 ( struct V_13 * V_14 , struct V_1 * V_1 ,
struct V_3 * V_4 )
{
struct V_115 * V_91 = V_4 -> V_91 ;
int V_48 ;
struct V_130 * V_157 ;
bool V_158 = false ;
V_91 -> V_159 = V_160 ;
V_157 = & V_14 -> V_139 [ V_1 -> V_161 ] ;
F_59 ( & V_157 -> V_133 ) ;
V_157 -> V_134 ++ ;
if ( V_14 -> V_141 && V_1 -> V_122 == 0x30 ) {
V_91 -> V_159 . V_139 = V_14 -> V_46 -> V_139 [ V_162 ] ;
F_65 ( V_91 ) ;
} else if ( V_14 -> V_163 && V_1 -> V_122 < 0x40 ) {
V_91 -> V_159 . V_139 = V_164 ;
V_91 -> V_159 . V_165 = V_91 -> V_159 . V_166 = 48000 ;
} else if ( V_14 -> V_136 && V_1 -> V_122 < 0x40 ) {
V_91 -> V_159 . V_139 = ( V_167 |
V_168 ) ;
V_91 -> V_159 . V_165 = 8000 ;
V_91 -> V_159 . V_166 = 48000 ;
V_158 = true ;
} else if ( ! V_157 -> V_127 ) {
int V_10 = V_1 -> V_161 ? V_169 : V_170 ;
V_91 -> V_159 . V_139 = V_14 -> V_46 -> V_139 [ V_10 ] ;
F_65 ( V_91 ) ;
} else {
V_91 -> V_159 . V_139 = V_171 ;
V_91 -> V_159 . V_166 = V_91 -> V_159 . V_165 = V_157 -> V_127 ;
}
F_60 ( & V_157 -> V_133 ) ;
if ( ( V_48 = F_66 ( V_91 , V_172 ) ) < 0 )
return V_48 ;
if ( V_158 ) {
V_48 = F_67 ( V_91 , 48000 ) ;
if ( V_48 < 0 )
return V_48 ;
}
V_91 -> V_47 = V_1 ;
V_1 -> V_4 = V_4 ;
return 0 ;
}
static int F_68 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = & V_14 -> V_77 [ V_14 -> V_173 + V_4 -> V_174 ] ;
int V_48 ;
if ( ( V_48 = F_64 ( V_14 , V_1 , V_4 ) ) < 0 )
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
if ( ( V_48 = F_64 ( V_14 , V_1 , V_4 ) ) < 0 )
return V_48 ;
V_175 = V_1 -> V_122 / 0x10 ;
if ( V_14 -> V_176 [ V_175 ] ) {
V_14 -> V_142 [ V_175 ] [ 0 ] =
V_177 - ( V_178 & 31 ) ;
V_14 -> V_142 [ V_175 ] [ 1 ] =
V_177 - ( V_178 & 31 ) ;
V_14 -> V_176 [ V_175 ] -> V_179 [ 0 ] . V_180 &=
~ V_181 ;
F_70 ( V_14 -> V_39 , V_182 |
V_183 ,
& V_14 -> V_176 [ V_175 ] -> V_184 ) ;
}
return 0 ;
}
static int F_71 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = & V_14 -> V_77 [ V_14 -> V_185 ] ;
int V_48 ;
static unsigned int V_120 [] = {
1 , 2 , 4 , 6
} ;
static struct V_186 V_187 = {
. V_102 = F_72 ( V_120 ) ,
. V_188 = V_120 ,
. V_189 = 0 ,
} ;
if ( ( V_48 = F_64 ( V_14 , V_1 , V_4 ) ) < 0 )
return V_48 ;
V_4 -> V_91 -> V_159 . V_190 = 6 ;
if ( V_14 -> V_109 == V_191 )
V_186 ( V_4 -> V_91 , 0 ,
V_192 ,
& V_187 ) ;
return 0 ;
}
static int F_73 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = & V_14 -> V_77 [ V_14 -> V_193 + V_4 -> V_194 -> V_195 ] ;
return F_64 ( V_14 , V_1 , V_4 ) ;
}
static int F_74 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = V_4 -> V_91 -> V_47 ;
struct V_130 * V_157 ;
V_157 = & V_14 -> V_139 [ V_1 -> V_161 ] ;
F_59 ( & V_157 -> V_133 ) ;
V_157 -> V_134 -- ;
if ( ! V_157 -> V_134 )
V_157 -> V_127 = 0 ;
F_60 ( & V_157 -> V_133 ) ;
if ( ! V_157 -> V_127 ) {
if ( ! V_1 -> V_161 ) {
F_75 ( V_14 -> V_46 ,
V_126 , 0 ) ;
F_75 ( V_14 -> V_46 ,
V_150 , 0 ) ;
F_75 ( V_14 -> V_46 ,
V_151 , 0 ) ;
} else
F_75 ( V_14 -> V_46 ,
V_129 , 0 ) ;
}
V_1 -> V_4 = NULL ;
return 0 ;
}
static int F_76 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = V_4 -> V_91 -> V_47 ;
unsigned int V_175 ;
V_175 = V_1 -> V_122 / 0x10 ;
if ( V_14 -> V_176 [ V_175 ] ) {
V_14 -> V_176 [ V_175 ] -> V_179 [ 0 ] . V_180 |=
V_181 ;
F_70 ( V_14 -> V_39 , V_183 ,
& V_14 -> V_176 [ V_175 ] -> V_184 ) ;
}
return F_74 ( V_4 ) ;
}
static void F_77 ( struct V_13 * V_14 , int V_10 , unsigned int V_122 ,
int V_196 , int V_161 )
{
V_14 -> V_77 [ V_10 ] . V_122 = V_122 ;
V_14 -> V_77 [ V_10 ] . V_87 = V_196 * 4 ;
V_14 -> V_77 [ V_10 ] . V_161 = V_161 ;
V_14 -> V_77 [ V_10 ] . V_197 = V_14 -> V_197 + V_122 ;
}
static int F_78 ( struct V_13 * V_14 )
{
struct V_198 * V_194 ;
struct V_199 * V_200 ;
int V_9 , V_48 ;
V_14 -> V_173 = 0 ;
V_14 -> V_185 = 4 ;
V_14 -> V_193 = 5 ;
V_14 -> V_76 = 7 ;
V_14 -> V_72 = 0x33033333 ;
V_48 = F_79 ( V_14 -> V_39 , V_14 -> V_39 -> V_201 , 0 , 4 , 1 , & V_194 ) ;
if ( V_48 < 0 )
return V_48 ;
F_80 ( V_194 , V_202 , & V_203 ) ;
F_80 ( V_194 , V_204 , & V_205 ) ;
V_194 -> V_47 = V_14 ;
strcpy ( V_194 -> V_206 , V_14 -> V_39 -> V_201 ) ;
V_14 -> V_207 [ 0 ] = V_194 ;
for ( V_9 = 0 ; V_9 < 4 ; V_9 ++ )
F_77 ( V_14 , V_9 , 0x10 * V_9 , V_9 , 0 ) ;
F_77 ( V_14 , V_14 -> V_193 , V_208 , 6 , 1 ) ;
F_81 ( V_194 , V_209 ,
F_4 ( V_14 -> V_6 ) ,
64 * 1024 , V_210 ) ;
V_48 = F_82 ( V_194 , V_202 ,
V_211 , 2 , 0 ,
& V_200 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = F_79 ( V_14 -> V_39 , V_14 -> V_39 -> V_201 , 1 , 1 , 1 , & V_194 ) ;
if ( V_48 < 0 )
return V_48 ;
F_80 ( V_194 , V_202 , & V_212 ) ;
F_80 ( V_194 , V_204 , & V_205 ) ;
V_194 -> V_47 = V_14 ;
strcpy ( V_194 -> V_206 , V_14 -> V_39 -> V_201 ) ;
V_14 -> V_207 [ 1 ] = V_194 ;
F_77 ( V_14 , V_14 -> V_185 , V_213 , 4 , 0 ) ;
F_77 ( V_14 , V_14 -> V_193 + 1 , V_208 + 0x10 , 7 , 1 ) ;
F_81 ( V_194 , V_209 ,
F_4 ( V_14 -> V_6 ) ,
64 * 1024 , V_210 ) ;
V_48 = F_82 ( V_194 , V_202 ,
V_214 , 6 , 0 ,
& V_200 ) ;
if ( V_48 < 0 )
return V_48 ;
V_14 -> V_46 -> V_215 [ V_202 ] = V_200 ;
return 0 ;
}
static int F_83 ( struct V_13 * V_14 )
{
struct V_198 * V_194 ;
struct V_199 * V_200 ;
int V_48 ;
V_14 -> V_185 = 0 ;
V_14 -> V_173 = 1 ;
V_14 -> V_193 = 2 ;
V_14 -> V_76 = 3 ;
V_14 -> V_72 = 0x03033000 ;
V_48 = F_79 ( V_14 -> V_39 , V_14 -> V_39 -> V_201 , 0 , 1 , 1 , & V_194 ) ;
if ( V_48 < 0 )
return V_48 ;
F_80 ( V_194 , V_202 , & V_212 ) ;
F_80 ( V_194 , V_204 , & V_205 ) ;
V_194 -> V_47 = V_14 ;
strcpy ( V_194 -> V_206 , V_14 -> V_39 -> V_201 ) ;
V_14 -> V_207 [ 0 ] = V_194 ;
F_77 ( V_14 , V_14 -> V_185 , V_213 , 4 , 0 ) ;
F_77 ( V_14 , V_14 -> V_193 , V_208 , 6 , 1 ) ;
F_81 ( V_194 , V_209 ,
F_4 ( V_14 -> V_6 ) ,
64 * 1024 , V_210 ) ;
V_48 = F_82 ( V_194 , V_202 ,
V_214 , 6 , 0 ,
& V_200 ) ;
if ( V_48 < 0 )
return V_48 ;
V_14 -> V_46 -> V_215 [ V_202 ] = V_200 ;
if ( ! F_84 ( V_14 -> V_46 ) )
return 0 ;
V_48 = F_79 ( V_14 -> V_39 , V_14 -> V_39 -> V_201 , 1 , 1 , 0 , & V_194 ) ;
if ( V_48 < 0 )
return V_48 ;
F_80 ( V_194 , V_202 , & V_203 ) ;
V_194 -> V_47 = V_14 ;
strcpy ( V_194 -> V_206 , V_14 -> V_39 -> V_201 ) ;
V_14 -> V_207 [ 1 ] = V_194 ;
F_77 ( V_14 , V_14 -> V_173 , 0x30 , 3 , 0 ) ;
F_81 ( V_194 , V_209 ,
F_4 ( V_14 -> V_6 ) ,
64 * 1024 , V_210 ) ;
return 0 ;
}
static int F_85 ( struct V_13 * V_14 )
{
struct V_198 * V_194 ;
int V_48 ;
V_14 -> V_173 = 0 ;
V_14 -> V_193 = 1 ;
V_14 -> V_76 = 2 ;
V_14 -> V_72 = 0x77 ;
V_48 = F_79 ( V_14 -> V_39 , V_14 -> V_39 -> V_201 , 0 , 1 , 1 , & V_194 ) ;
if ( V_48 < 0 )
return V_48 ;
F_80 ( V_194 , V_202 , & V_216 ) ;
F_80 ( V_194 , V_204 , & V_217 ) ;
V_194 -> V_47 = V_14 ;
strcpy ( V_194 -> V_206 , V_14 -> V_39 -> V_201 ) ;
V_14 -> V_207 [ 0 ] = V_194 ;
F_77 ( V_14 , 0 , V_218 , 0 , 0 ) ;
F_77 ( V_14 , 1 , V_219 , 0 , 1 ) ;
F_81 ( V_194 , V_209 ,
F_4 ( V_14 -> V_6 ) ,
64 * 1024 , V_210 ) ;
return 0 ;
}
static int F_86 ( struct V_220 * V_221 ,
struct V_222 * V_223 )
{
static const char * const V_224 [ 2 ] = {
L_8 , L_9
} ;
return F_87 ( V_223 , 1 , 2 , V_224 ) ;
}
static int F_88 ( struct V_220 * V_221 ,
struct V_225 * V_226 )
{
struct V_13 * V_14 = F_89 ( V_221 ) ;
unsigned long V_197 = V_14 -> V_197 + ( V_221 -> V_184 . V_227 ? ( V_228 + 0x10 ) : V_228 ) ;
V_226 -> V_229 . V_230 . V_231 [ 0 ] = F_29 ( V_197 ) & V_232 ? 1 : 0 ;
return 0 ;
}
static int F_90 ( struct V_220 * V_221 ,
struct V_225 * V_226 )
{
struct V_13 * V_14 = F_89 ( V_221 ) ;
unsigned long V_197 = V_14 -> V_197 + ( V_221 -> V_184 . V_227 ? ( V_228 + 0x10 ) : V_228 ) ;
T_3 V_35 , V_233 ;
F_59 ( & V_14 -> V_75 ) ;
V_233 = F_29 ( V_197 ) ;
V_35 = V_233 & ~ V_232 ;
if ( V_226 -> V_229 . V_230 . V_231 [ 0 ] )
V_35 |= V_232 ;
if ( V_35 != V_233 )
F_27 ( V_35 , V_197 ) ;
F_60 ( & V_14 -> V_75 ) ;
return V_35 != V_233 ;
}
static int F_91 ( struct V_220 * V_221 ,
struct V_225 * V_226 )
{
struct V_13 * V_14 = F_89 ( V_221 ) ;
T_3 V_35 ;
F_92 ( V_14 -> V_6 , V_234 , & V_35 ) ;
V_226 -> V_229 . integer . V_229 [ 0 ] = ( V_35 & V_235 ) ? 1 : 0 ;
return 0 ;
}
static int F_93 ( struct V_220 * V_221 ,
struct V_225 * V_226 )
{
struct V_13 * V_14 = F_89 ( V_221 ) ;
T_3 V_35 , V_233 ;
F_92 ( V_14 -> V_6 , V_234 , & V_233 ) ;
V_35 = V_233 & ~ V_235 ;
if ( V_226 -> V_229 . integer . V_229 [ 0 ] )
V_35 |= V_235 ;
V_14 -> V_141 = V_226 -> V_229 . integer . V_229 [ 0 ] ? 1 : 0 ;
if ( V_35 != V_233 ) {
F_94 ( V_14 -> V_6 , V_234 , V_35 ) ;
return 1 ;
}
return 0 ;
}
static int F_95 ( struct V_220 * V_221 ,
struct V_222 * V_223 )
{
V_223 -> type = V_236 ;
V_223 -> V_102 = 2 ;
V_223 -> V_229 . integer . V_237 = 0 ;
V_223 -> V_229 . integer . V_238 = V_177 ;
return 0 ;
}
static int F_96 ( struct V_220 * V_221 ,
struct V_225 * V_226 )
{
struct V_13 * V_14 = F_89 ( V_221 ) ;
unsigned int V_10 = V_221 -> V_184 . V_239 ;
V_226 -> V_229 . integer . V_229 [ 0 ] = V_177 - V_14 -> V_142 [ V_10 ] [ 0 ] ;
V_226 -> V_229 . integer . V_229 [ 1 ] = V_177 - V_14 -> V_142 [ V_10 ] [ 1 ] ;
return 0 ;
}
static int F_97 ( struct V_220 * V_221 ,
struct V_225 * V_226 )
{
struct V_13 * V_14 = F_89 ( V_221 ) ;
V_226 -> V_229 . integer . V_229 [ 0 ] = V_177 - V_14 -> V_240 [ 0 ] ;
V_226 -> V_229 . integer . V_229 [ 1 ] = V_177 - V_14 -> V_240 [ 1 ] ;
return 0 ;
}
static int F_98 ( struct V_220 * V_221 ,
struct V_225 * V_226 )
{
struct V_13 * V_14 = F_89 ( V_221 ) ;
unsigned int V_10 = V_221 -> V_184 . V_239 ;
unsigned long V_197 = V_14 -> V_197 + 0x10 * V_10 ;
unsigned char V_35 ;
int V_9 , V_241 = 0 ;
for ( V_9 = 0 ; V_9 < 2 ; V_9 ++ ) {
V_35 = V_226 -> V_229 . integer . V_229 [ V_9 ] ;
if ( V_35 > V_177 )
V_35 = V_177 ;
V_35 = V_177 - V_35 ;
V_241 |= V_35 != V_14 -> V_142 [ V_10 ] [ V_9 ] ;
if ( V_241 ) {
V_14 -> V_142 [ V_10 ] [ V_9 ] = V_35 ;
F_27 ( V_35 , V_197 + V_242 + V_9 ) ;
}
}
return V_241 ;
}
static int F_99 ( struct V_220 * V_221 ,
struct V_225 * V_226 )
{
struct V_13 * V_14 = F_89 ( V_221 ) ;
unsigned int V_10 ;
unsigned char V_35 ;
int V_9 , V_241 = 0 ;
for ( V_9 = 0 ; V_9 < 2 ; V_9 ++ ) {
V_35 = V_226 -> V_229 . integer . V_229 [ V_9 ] ;
if ( V_35 > V_177 )
V_35 = V_177 ;
V_35 = V_177 - V_35 ;
if ( V_35 != V_14 -> V_240 [ V_9 ] ) {
V_241 = 1 ;
V_14 -> V_240 [ V_9 ] = V_35 ;
for ( V_10 = 0 ; V_10 < 4 ; V_10 ++ ) {
unsigned long V_197 = V_14 -> V_197 + 0x10 * V_10 ;
V_14 -> V_142 [ V_10 ] [ V_9 ] = V_35 ;
F_27 ( V_35 , V_197 + V_242 + V_9 ) ;
}
}
}
return V_241 ;
}
static void F_100 ( struct V_243 * V_244 )
{
struct V_13 * V_14 = V_244 -> V_47 ;
V_14 -> V_245 = NULL ;
}
static void F_101 ( struct V_45 * V_46 )
{
struct V_13 * V_14 = V_46 -> V_47 ;
V_14 -> V_46 = NULL ;
}
static int F_102 ( struct V_13 * V_14 , const char * V_246 )
{
struct V_247 V_46 ;
int V_48 ;
static struct V_248 V_249 = {
. V_250 = F_24 ,
. V_251 = F_25 ,
. V_252 = F_22 ,
} ;
if ( ( V_48 = V_243 ( V_14 -> V_39 , 0 , & V_249 , V_14 , & V_14 -> V_245 ) ) < 0 )
return V_48 ;
V_14 -> V_245 -> V_253 = F_100 ;
V_14 -> V_245 -> clock = V_14 -> V_254 ;
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
V_46 . V_47 = V_14 ;
V_46 . V_253 = F_101 ;
V_46 . V_6 = V_14 -> V_6 ;
V_46 . V_255 = V_256 | V_257 ;
if ( ( V_48 = F_103 ( V_14 -> V_245 , & V_46 , & V_14 -> V_46 ) ) < 0 )
return V_48 ;
F_104 ( V_14 -> V_46 , V_258 , V_246 ) ;
if ( V_14 -> V_92 != V_93 ) {
F_105 ( V_14 -> V_46 , V_259 , 0x03 << 4 , 0x03 << 4 ) ;
}
return 0 ;
}
static int F_106 ( struct V_13 * V_14 , unsigned char * V_260 )
{
struct V_261 * V_262 ;
struct V_263 * V_22 ;
if ( ! V_264 )
return - V_265 ;
V_22 = F_107 ( V_266 , 8 , L_10 ) ;
if ( ! V_22 ) {
F_108 ( V_14 -> V_39 -> V_2 , L_11 ,
V_266 ) ;
return - V_267 ;
}
V_14 -> V_261 = V_262 = F_109 () ;
if ( ! V_262 ) {
F_7 ( V_14 -> V_39 -> V_2 ,
L_12 ) ;
F_110 ( V_22 ) ;
return - V_19 ;
}
F_111 ( V_262 , L_13 ) ;
F_112 ( V_262 , L_14 , F_113 ( V_14 -> V_6 ) ) ;
F_114 ( V_262 , & V_14 -> V_6 -> V_2 ) ;
V_262 -> V_268 = V_266 ;
F_115 ( V_262 , V_22 ) ;
* V_260 |= V_269 ;
F_94 ( V_14 -> V_6 , V_270 , * V_260 ) ;
F_116 ( V_14 -> V_261 ) ;
return 0 ;
}
static void F_117 ( struct V_13 * V_14 )
{
if ( V_14 -> V_261 ) {
struct V_263 * V_22 = F_118 ( V_14 -> V_261 ) ;
F_119 ( V_14 -> V_261 ) ;
V_14 -> V_261 = NULL ;
F_110 ( V_22 ) ;
}
}
static inline int F_106 ( struct V_13 * V_14 , unsigned char * V_260 )
{
return - V_271 ;
}
static inline void F_117 ( struct V_13 * V_14 ) { }
static int F_120 ( struct V_13 * V_14 )
{
int V_9 , V_48 , V_272 ;
unsigned char V_35 ;
V_272 = V_14 -> V_92 == V_273 ? 1 : 2 ;
for ( V_9 = 0 ; V_9 < V_272 ; V_9 ++ ) {
V_274 . V_227 = V_9 ;
V_48 = F_121 ( V_14 -> V_39 , F_122 ( & V_274 , V_14 ) ) ;
if ( V_48 < 0 )
return V_48 ;
}
if ( F_84 ( V_14 -> V_46 ) ) {
V_48 = F_121 ( V_14 -> V_39 , F_122 ( & V_275 , V_14 ) ) ;
if ( V_48 < 0 )
return V_48 ;
}
if ( V_14 -> V_92 != V_273 ) {
struct V_276 V_277 ;
memset ( & V_277 , 0 , sizeof( V_277 ) ) ;
strcpy ( V_277 . V_206 , L_15 ) ;
V_277 . V_278 = V_279 ;
if ( ! F_123 ( V_14 -> V_39 , & V_277 ) ) {
F_124 ( V_14 -> V_39 -> V_2 ,
L_16 ) ;
V_48 = F_121 ( V_14 -> V_39 , F_122 ( & V_280 , V_14 ) ) ;
if ( V_48 < 0 )
return V_48 ;
}
else
{
for ( V_9 = 0 ; V_9 < 4 ; ++ V_9 ) {
struct V_220 * V_281 ;
V_281 = F_122 (
& V_282 , V_14 ) ;
if ( ! V_281 )
return - V_19 ;
V_281 -> V_184 . V_239 = V_9 ;
V_48 = F_121 ( V_14 -> V_39 , V_281 ) ;
if ( V_48 < 0 )
return V_48 ;
V_14 -> V_176 [ V_9 ] = V_281 ;
}
}
}
F_92 ( V_14 -> V_6 , V_234 , & V_35 ) ;
V_35 = ( V_35 & ~ V_283 ) | V_284 ;
V_35 &= ~ V_235 ;
F_94 ( V_14 -> V_6 , V_234 , V_35 ) ;
return 0 ;
}
static int F_125 ( struct V_13 * V_14 )
{
unsigned char V_260 , V_285 ;
int V_286 = 0 ;
V_260 = V_14 -> V_287 ;
V_285 = V_14 -> V_288 ;
V_260 |= V_289 ;
V_260 &= ~ V_269 ;
if ( V_14 -> V_109 >= V_290 ) {
V_286 = 1 ;
if ( V_291 >= 0x200 ) {
V_291 &= 0xfffc ;
F_126 ( V_14 -> V_6 , 0x18 , V_291 | 0x01 ) ;
#ifdef F_127
V_14 -> V_292 = V_291 ;
#endif
} else {
V_291 = F_128 ( V_14 -> V_6 , 2 ) ;
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
if ( V_260 & V_293 )
V_291 = 0x300 + ( ( V_285 & 0x000c ) << 2 ) ;
break;
}
}
if ( V_291 >= 0x200 &&
( V_14 -> V_294 = F_107 ( V_291 , 2 , L_17 ) )
!= NULL ) {
if ( V_286 )
V_260 |= V_295 ;
V_260 |= V_293 ;
} else {
if ( V_286 )
V_260 &= ~ V_295 ;
V_260 &= ~ V_293 ;
V_291 = 0 ;
}
F_94 ( V_14 -> V_6 , V_270 , V_260 ) ;
F_94 ( V_14 -> V_6 , V_296 , V_285 ) ;
if ( V_14 -> V_294 ) {
if ( F_129 ( V_14 -> V_39 , 0 , V_297 ,
V_291 , V_298 |
V_299 , - 1 ,
& V_14 -> V_73 ) < 0 ) {
F_108 ( V_14 -> V_39 -> V_2 ,
L_18 ,
V_291 ) ;
V_260 &= ~ V_293 ;
} else {
V_260 &= ~ V_289 ;
}
F_94 ( V_14 -> V_6 , V_270 , V_260 ) ;
}
F_106 ( V_14 , & V_260 ) ;
#ifdef F_127
V_14 -> V_300 = V_260 ;
V_14 -> V_301 = V_285 ;
#endif
return 0 ;
}
static void F_130 ( struct V_302 * V_303 ,
struct V_304 * V_305 )
{
struct V_13 * V_14 = V_303 -> V_47 ;
int V_9 ;
F_131 ( V_305 , L_19 , V_14 -> V_39 -> V_306 ) ;
for ( V_9 = 0 ; V_9 < 0xa0 ; V_9 += 4 ) {
F_131 ( V_305 , L_20 , V_9 , F_15 ( V_14 -> V_197 + V_9 ) ) ;
}
}
static void F_132 ( struct V_13 * V_14 )
{
struct V_302 * V_303 ;
if ( ! F_133 ( V_14 -> V_39 , L_21 , & V_303 ) )
F_134 ( V_303 , V_14 , F_130 ) ;
}
static int F_135 ( struct V_13 * V_14 )
{
unsigned int V_35 ;
unsigned long V_307 ;
unsigned char V_308 ;
#if 0
if (chip->chip_type == TYPE_VIA686)
pci_write_config_byte(chip->pci, VIA_FUNC_ENABLE, 0);
#endif
F_92 ( V_14 -> V_6 , V_309 , & V_308 ) ;
if ( ! ( V_308 & V_310 ) ) {
F_94 ( V_14 -> V_6 , V_311 ,
V_312 |
V_313 |
V_314 ) ;
F_20 ( 100 ) ;
#if 1
F_94 ( V_14 -> V_6 , V_311 , 0x00 ) ;
F_20 ( 100 ) ;
#else
F_94 ( V_14 -> V_6 , V_311 ,
V_313 | V_314 ) ;
F_20 ( 2 ) ;
#endif
F_94 ( V_14 -> V_6 , V_311 , V_315 ) ;
F_20 ( 100 ) ;
}
F_92 ( V_14 -> V_6 , V_311 , & V_308 ) ;
if ( ( V_308 & V_315 ) != V_315 ) {
F_94 ( V_14 -> V_6 , V_311 , V_315 ) ;
F_20 ( 100 ) ;
}
V_307 = V_316 + F_136 ( 750 ) ;
do {
F_92 ( V_14 -> V_6 , V_309 , & V_308 ) ;
if ( V_308 & V_310 )
break;
F_137 ( 1 ) ;
} while ( F_138 ( V_316 , V_307 ) );
if ( ( V_35 = F_14 ( V_14 ) ) & V_38 )
F_7 ( V_14 -> V_39 -> V_2 ,
L_22 , V_35 ) ;
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
F_94 ( V_14 -> V_6 , V_317 , 0 ) ;
F_18 ( 0 , F_16 ( V_14 , V_318 ) ) ;
}
if ( V_14 -> V_92 != V_93 ) {
struct V_5 * V_6 ;
V_6 = F_139 ( 0x1106 , 0x3068 , NULL ) ;
if ( V_6 ) {
unsigned char V_319 ;
F_92 ( V_6 , 0x44 , & V_319 ) ;
F_94 ( V_6 , 0x44 , V_319 | 0x40 ) ;
F_140 ( V_6 ) ;
}
}
if ( V_14 -> V_92 != V_273 ) {
int V_9 , V_10 ;
for ( V_10 = 0 ; V_10 < 4 ; V_10 ++ ) {
unsigned long V_197 = V_14 -> V_197 + 0x10 * V_10 ;
for ( V_9 = 0 ; V_9 < 2 ; V_9 ++ ) {
V_14 -> V_142 [ V_10 ] [ V_9 ] = V_14 -> V_240 [ V_9 ] ;
F_27 ( V_14 -> V_240 [ V_9 ] ,
V_197 + V_242 + V_9 ) ;
}
}
}
return 0 ;
}
static int F_141 ( struct V_195 * V_2 )
{
struct V_5 * V_6 = F_142 ( V_2 ) ;
struct V_320 * V_39 = F_143 ( V_2 ) ;
struct V_13 * V_14 = V_39 -> V_47 ;
int V_9 ;
F_144 ( V_39 , V_321 ) ;
for ( V_9 = 0 ; V_9 < 2 ; V_9 ++ )
F_145 ( V_14 -> V_207 [ V_9 ] ) ;
for ( V_9 = 0 ; V_9 < V_14 -> V_76 ; V_9 ++ )
F_26 ( V_14 , & V_14 -> V_77 [ V_9 ] ) ;
F_146 ( V_14 -> V_68 ) ;
F_147 ( V_14 -> V_46 ) ;
if ( V_14 -> V_92 != V_93 ) {
F_92 ( V_14 -> V_6 , V_234 , & V_14 -> V_322 ) ;
V_14 -> V_323 [ 0 ] = F_29 ( V_14 -> V_197 + V_228 ) ;
V_14 -> V_323 [ 1 ] = F_29 ( V_14 -> V_197 + V_228 + 0x10 ) ;
}
F_148 ( V_6 ) ;
F_149 ( V_6 ) ;
F_150 ( V_6 , V_324 ) ;
return 0 ;
}
static int F_151 ( struct V_195 * V_2 )
{
struct V_5 * V_6 = F_142 ( V_2 ) ;
struct V_320 * V_39 = F_143 ( V_2 ) ;
struct V_13 * V_14 = V_39 -> V_47 ;
int V_9 ;
F_150 ( V_6 , V_325 ) ;
F_152 ( V_6 ) ;
if ( F_153 ( V_6 ) < 0 ) {
F_7 ( V_2 , L_23 ) ;
F_154 ( V_39 ) ;
return - V_40 ;
}
F_155 ( V_6 ) ;
F_135 ( V_14 ) ;
if ( V_14 -> V_92 == V_93 ) {
if ( V_14 -> V_292 )
F_126 ( V_14 -> V_6 , 0x18 , V_14 -> V_292 | 0x01 ) ;
F_94 ( V_14 -> V_6 , V_270 , V_14 -> V_300 ) ;
F_94 ( V_14 -> V_6 , V_296 , V_14 -> V_301 ) ;
} else {
F_94 ( V_14 -> V_6 , V_234 , V_14 -> V_322 ) ;
F_27 ( V_14 -> V_323 [ 0 ] , V_14 -> V_197 + V_228 ) ;
F_27 ( V_14 -> V_323 [ 1 ] , V_14 -> V_197 + V_228 + 0x10 ) ;
}
F_156 ( V_14 -> V_46 ) ;
for ( V_9 = 0 ; V_9 < V_14 -> V_76 ; V_9 ++ )
F_26 ( V_14 , & V_14 -> V_77 [ V_9 ] ) ;
F_144 ( V_39 , V_326 ) ;
return 0 ;
}
static int F_157 ( struct V_13 * V_14 )
{
unsigned int V_9 ;
if ( V_14 -> V_68 < 0 )
goto V_327;
for ( V_9 = 0 ; V_9 < V_14 -> V_76 ; V_9 ++ )
F_26 ( V_14 , & V_14 -> V_77 [ V_9 ] ) ;
if ( V_14 -> V_68 >= 0 )
F_158 ( V_14 -> V_68 , V_14 ) ;
V_327:
F_110 ( V_14 -> V_294 ) ;
F_159 ( V_14 -> V_6 ) ;
if ( V_14 -> V_92 == V_93 ) {
F_117 ( V_14 ) ;
F_94 ( V_14 -> V_6 , V_270 , V_14 -> V_287 ) ;
F_94 ( V_14 -> V_6 , V_296 , V_14 -> V_288 ) ;
}
F_148 ( V_14 -> V_6 ) ;
F_13 ( V_14 ) ;
return 0 ;
}
static int F_160 ( struct V_328 * V_195 )
{
struct V_13 * V_14 = V_195 -> V_329 ;
return F_157 ( V_14 ) ;
}
static int F_161 ( struct V_320 * V_39 ,
struct V_5 * V_6 ,
int V_92 ,
int V_109 ,
unsigned int V_254 ,
struct V_13 * * V_330 )
{
struct V_13 * V_14 ;
int V_48 ;
static struct V_331 V_249 = {
. V_332 = F_160 ,
} ;
if ( ( V_48 = F_153 ( V_6 ) ) < 0 )
return V_48 ;
if ( ( V_14 = F_162 ( sizeof( * V_14 ) , V_21 ) ) == NULL ) {
F_148 ( V_6 ) ;
return - V_19 ;
}
V_14 -> V_92 = V_92 ;
V_14 -> V_109 = V_109 ;
F_163 ( & V_14 -> V_75 ) ;
F_163 ( & V_14 -> V_139 [ 0 ] . V_133 ) ;
F_163 ( & V_14 -> V_139 [ 1 ] . V_133 ) ;
V_14 -> V_39 = V_39 ;
V_14 -> V_6 = V_6 ;
V_14 -> V_68 = - 1 ;
F_92 ( V_6 , V_270 , & V_14 -> V_287 ) ;
F_92 ( V_6 , V_296 , & V_14 -> V_288 ) ;
F_94 ( V_14 -> V_6 , V_270 ,
V_14 -> V_287 & ~ ( V_333 | V_334 ) ) ;
if ( ( V_48 = F_164 ( V_6 , V_39 -> V_335 ) ) < 0 ) {
F_13 ( V_14 ) ;
F_148 ( V_6 ) ;
return V_48 ;
}
V_14 -> V_197 = F_128 ( V_6 , 0 ) ;
if ( F_165 ( V_6 -> V_68 ,
V_92 == V_336 ?
F_35 : F_30 ,
V_337 ,
V_338 , V_14 ) ) {
F_7 ( V_39 -> V_2 , L_24 , V_6 -> V_68 ) ;
F_157 ( V_14 ) ;
return - V_267 ;
}
V_14 -> V_68 = V_6 -> V_68 ;
if ( V_254 >= 8000 && V_254 <= 48000 )
V_14 -> V_254 = V_254 ;
F_146 ( V_14 -> V_68 ) ;
if ( ( V_48 = F_135 ( V_14 ) ) < 0 ) {
F_157 ( V_14 ) ;
return V_48 ;
}
if ( ( V_48 = F_166 ( V_39 , V_339 , V_14 , & V_249 ) ) < 0 ) {
F_157 ( V_14 ) ;
return V_48 ;
}
F_155 ( V_6 ) ;
* V_330 = V_14 ;
return 0 ;
}
static int F_167 ( struct V_5 * V_6 , int V_109 )
{
const struct V_340 * V_341 ;
V_341 = F_168 ( V_6 , V_342 ) ;
if ( V_341 ) {
F_39 ( & V_6 -> V_2 , L_25 ,
F_169 ( V_341 ) ) ;
return V_341 -> V_229 ;
}
if ( V_109 >= V_343 )
return V_344 ;
F_124 ( & V_6 -> V_2 , L_26 ) ;
F_124 ( & V_6 -> V_2 , L_27 ) ;
F_124 ( & V_6 -> V_2 , L_28 ) ;
F_124 ( & V_6 -> V_2 , L_29 ) ;
return V_345 ;
}
static int F_170 ( struct V_5 * V_6 ,
const struct V_346 * V_347 )
{
struct V_320 * V_39 ;
struct V_13 * V_14 ;
int V_92 = 0 , V_348 ;
unsigned int V_9 ;
int V_48 ;
V_48 = F_171 ( & V_6 -> V_2 , V_227 , V_184 , V_349 , 0 , & V_39 ) ;
if ( V_48 < 0 )
return V_48 ;
V_348 = V_347 -> V_350 ;
switch ( V_348 ) {
case V_351 :
strcpy ( V_39 -> V_335 , L_30 ) ;
sprintf ( V_39 -> V_201 , L_31 , V_6 -> V_109 ) ;
V_92 = V_93 ;
break;
case V_352 :
V_92 = V_336 ;
sprintf ( V_39 -> V_201 , L_32 , V_6 -> V_109 ) ;
for ( V_9 = 0 ; V_9 < F_72 ( V_353 ) ; V_9 ++ ) {
if ( V_6 -> V_109 == V_353 [ V_9 ] . V_109 ) {
V_92 = V_353 [ V_9 ] . type ;
strcpy ( V_39 -> V_201 , V_353 [ V_9 ] . V_206 ) ;
break;
}
}
if ( V_92 != V_273 ) {
if ( V_354 == V_355 )
V_354 = F_167 ( V_6 , V_6 -> V_109 ) ;
if ( V_354 == V_356 )
V_92 = V_273 ;
else
V_92 = V_336 ;
}
if ( V_92 == V_273 )
strcpy ( V_39 -> V_335 , L_33 ) ;
else if ( V_6 -> V_109 >= V_357 )
strcpy ( V_39 -> V_335 , L_34 ) ;
else
strcpy ( V_39 -> V_335 , L_35 ) ;
break;
default:
F_7 ( V_39 -> V_2 , L_36 , V_348 ) ;
V_48 = - V_25 ;
goto V_358;
}
if ( ( V_48 = F_161 ( V_39 , V_6 , V_92 , V_6 -> V_109 ,
V_254 , & V_14 ) ) < 0 )
goto V_358;
V_39 -> V_47 = V_14 ;
if ( ( V_48 = F_102 ( V_14 , V_359 ) ) < 0 )
goto V_358;
if ( V_92 == V_93 ) {
if ( ( V_48 = F_85 ( V_14 ) ) < 0 ||
( V_48 = F_125 ( V_14 ) ) < 0 )
goto V_358;
} else {
if ( V_92 == V_273 ) {
if ( ( V_48 = F_83 ( V_14 ) ) < 0 )
goto V_358;
} else {
if ( ( V_48 = F_78 ( V_14 ) ) < 0 )
goto V_358;
if ( V_354 == V_345 )
V_14 -> V_163 = 1 ;
else if ( V_354 == V_360 )
V_14 -> V_140 = 1 ;
else if ( V_354 == V_344 ) {
V_14 -> V_140 = 1 ;
V_14 -> V_136 = 1 ;
}
}
if ( ( V_48 = F_120 ( V_14 ) ) < 0 )
goto V_358;
}
for ( V_9 = 0 ; V_9 < V_14 -> V_76 ; V_9 ++ )
F_26 ( V_14 , & V_14 -> V_77 [ V_9 ] ) ;
snprintf ( V_39 -> V_306 , sizeof( V_39 -> V_306 ) ,
L_37 , V_39 -> V_201 ,
F_172 ( V_14 -> V_46 ) , V_14 -> V_197 , V_14 -> V_68 ) ;
F_132 ( V_14 ) ;
if ( ( V_48 = F_173 ( V_39 ) ) < 0 ) {
F_174 ( V_39 ) ;
return V_48 ;
}
F_175 ( V_6 , V_39 ) ;
return 0 ;
V_358:
F_174 ( V_39 ) ;
return V_48 ;
}
static void F_176 ( struct V_5 * V_6 )
{
F_174 ( F_177 ( V_6 ) ) ;
}
