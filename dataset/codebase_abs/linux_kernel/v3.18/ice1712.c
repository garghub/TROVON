static inline int F_1 ( struct V_1 * V_2 )
{
return ( F_2 ( F_3 ( V_2 , V_3 ) ) & V_4 ) ? 1 : 0 ;
}
static inline int F_4 ( struct V_1 * V_2 )
{
return F_1 ( V_2 ) || V_5 ;
}
static inline void F_5 ( struct V_1 * V_2 , T_1 V_6 , T_1 V_7 , T_2 V_8 )
{
F_6 ( ( V_6 << 4 ) | V_7 , F_7 ( V_2 , V_9 ) ) ;
F_8 ( V_8 , F_7 ( V_2 , V_10 ) ) ;
}
static inline T_2 F_9 ( struct V_1 * V_2 , T_1 V_6 , T_1 V_7 )
{
F_6 ( ( V_6 << 4 ) | V_7 , F_7 ( V_2 , V_9 ) ) ;
return F_10 ( F_7 ( V_2 , V_10 ) ) ;
}
static void F_11 ( struct V_11 * V_12 ,
unsigned short V_13 ,
unsigned short V_14 )
{
struct V_1 * V_2 = V_12 -> V_15 ;
int V_16 ;
unsigned char V_17 = 0 ;
for ( V_16 = 0 ; V_16 < 0x10000 ; V_16 ++ ) {
V_17 = F_2 ( F_12 ( V_2 , V_18 ) ) ;
if ( V_17 & ( V_19 | V_20 ) )
continue;
if ( ! ( V_17 & V_21 ) )
continue;
break;
}
F_6 ( V_13 , F_12 ( V_2 , V_22 ) ) ;
F_13 ( V_14 , F_12 ( V_2 , V_23 ) ) ;
V_17 &= ~ ( V_24 | V_25 ) ;
F_6 ( V_17 | V_19 , F_12 ( V_2 , V_18 ) ) ;
for ( V_16 = 0 ; V_16 < 0x10000 ; V_16 ++ )
if ( ( F_2 ( F_12 ( V_2 , V_18 ) ) & V_19 ) == 0 )
break;
}
static unsigned short F_14 ( struct V_11 * V_12 ,
unsigned short V_13 )
{
struct V_1 * V_2 = V_12 -> V_15 ;
int V_16 ;
unsigned char V_17 = 0 ;
for ( V_16 = 0 ; V_16 < 0x10000 ; V_16 ++ ) {
V_17 = F_2 ( F_12 ( V_2 , V_18 ) ) ;
if ( V_17 & ( V_19 | V_20 ) )
continue;
if ( ! ( V_17 & V_21 ) )
continue;
break;
}
F_6 ( V_13 , F_12 ( V_2 , V_22 ) ) ;
F_6 ( V_17 | V_20 , F_12 ( V_2 , V_18 ) ) ;
for ( V_16 = 0 ; V_16 < 0x10000 ; V_16 ++ )
if ( ( F_2 ( F_12 ( V_2 , V_18 ) ) & V_20 ) == 0 )
break;
if ( V_16 >= 0x10000 )
return ~ 0 ;
return F_15 ( F_12 ( V_2 , V_23 ) ) ;
}
static void F_16 ( struct V_11 * V_12 ,
unsigned short V_13 ,
unsigned short V_14 )
{
struct V_1 * V_2 = V_12 -> V_15 ;
int V_16 ;
unsigned char V_17 = 0 ;
for ( V_16 = 0 ; V_16 < 0x10000 ; V_16 ++ ) {
V_17 = F_2 ( F_3 ( V_2 , V_18 ) ) ;
if ( V_17 & ( V_19 | V_20 ) )
continue;
if ( ! ( V_17 & V_21 ) )
continue;
break;
}
F_6 ( V_13 , F_3 ( V_2 , V_22 ) ) ;
F_13 ( V_14 , F_3 ( V_2 , V_23 ) ) ;
V_17 &= ~ ( V_24 | V_25 ) ;
F_6 ( V_17 | V_19 , F_3 ( V_2 , V_18 ) ) ;
for ( V_16 = 0 ; V_16 < 0x10000 ; V_16 ++ )
if ( ( F_2 ( F_3 ( V_2 , V_18 ) ) & V_19 ) == 0 )
break;
}
static unsigned short F_17 ( struct V_11 * V_12 ,
unsigned short V_13 )
{
struct V_1 * V_2 = V_12 -> V_15 ;
int V_16 ;
unsigned char V_17 = 0 ;
for ( V_16 = 0 ; V_16 < 0x10000 ; V_16 ++ ) {
V_17 = F_2 ( F_3 ( V_2 , V_18 ) ) ;
if ( V_17 & ( V_19 | V_20 ) )
continue;
if ( ! ( V_17 & V_21 ) )
continue;
break;
}
F_6 ( V_13 , F_3 ( V_2 , V_22 ) ) ;
F_6 ( V_17 | V_20 , F_3 ( V_2 , V_18 ) ) ;
for ( V_16 = 0 ; V_16 < 0x10000 ; V_16 ++ )
if ( ( F_2 ( F_3 ( V_2 , V_18 ) ) & V_20 ) == 0 )
break;
if ( V_16 >= 0x10000 )
return ~ 0 ;
return F_15 ( F_3 ( V_2 , V_23 ) ) ;
}
static int F_18 ( struct V_26 * V_27 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_19 ( V_27 ) ;
V_29 -> V_30 . integer . V_30 [ 0 ] = F_2 ( F_3 ( V_2 , V_31 ) ) & V_32 ? 1 : 0 ;
return 0 ;
}
static int F_20 ( struct V_26 * V_27 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_19 ( V_27 ) ;
unsigned char V_14 , V_33 ;
F_21 ( & V_2 -> V_34 ) ;
V_14 = F_2 ( F_3 ( V_2 , V_31 ) ) ;
V_33 = V_14 & ~ V_32 ;
if ( V_29 -> V_30 . integer . V_30 [ 0 ] )
V_33 |= V_32 ;
F_6 ( V_33 , F_3 ( V_2 , V_31 ) ) ;
F_22 ( & V_2 -> V_34 ) ;
return V_14 != V_33 ;
}
static void F_23 ( struct V_1 * V_2 , unsigned int V_8 )
{
F_24 ( V_2 , V_35 , V_8 ) ;
F_2 ( F_12 ( V_2 , V_10 ) ) ;
}
static unsigned int F_25 ( struct V_1 * V_2 )
{
return F_26 ( V_2 , V_35 ) ;
}
static unsigned int F_27 ( struct V_1 * V_2 )
{
return F_26 ( V_2 , V_36 ) ;
}
static void F_28 ( struct V_1 * V_2 , unsigned int V_8 )
{
F_24 ( V_2 , V_36 , V_8 ) ;
F_2 ( F_12 ( V_2 , V_10 ) ) ;
}
static unsigned int F_29 ( struct V_1 * V_2 )
{
return F_26 ( V_2 , V_37 ) ;
}
static void F_30 ( struct V_1 * V_2 , unsigned int V_14 )
{
F_24 ( V_2 , V_37 , V_14 ) ;
F_2 ( F_12 ( V_2 , V_10 ) ) ;
}
static int F_31 ( struct V_1 * V_2 , int V_38 )
{
unsigned char V_13 [ 2 ] = { 0x80 | 4 , 0 } ;
unsigned char V_14 , V_33 ;
int V_39 = 0 ;
F_32 ( V_2 -> V_40 ) ;
if ( F_33 ( V_2 -> V_41 , V_13 , 1 ) != 1 ) {
F_34 ( V_2 -> V_40 ) ;
return - V_42 ;
}
if ( F_35 ( V_2 -> V_41 , & V_14 , 1 ) != 1 ) {
F_34 ( V_2 -> V_40 ) ;
return - V_42 ;
}
V_33 = V_14 & 0xf0 ;
if ( V_38 )
V_33 |= 0x01 ;
else
V_33 |= 0x04 ;
if ( V_14 != V_33 ) {
V_13 [ 1 ] = V_33 ;
if ( F_33 ( V_2 -> V_41 , V_13 , 2 ) != 2 ) {
V_39 = - V_42 ;
} else {
V_39 ++ ;
}
}
F_34 ( V_2 -> V_40 ) ;
return V_39 ;
}
static void F_36 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
F_37 ( V_2 -> V_41 , 1 ) ;
}
static void F_38 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
F_37 ( V_2 -> V_41 , 0 ) ;
}
static void F_39 ( struct V_1 * V_2 , int V_45 )
{
F_40 ( V_2 -> V_41 , V_45 ) ;
}
int F_41 ( struct V_1 * V_2 , int V_7 )
{
int V_46 ;
V_46 = F_42 ( V_2 -> V_40 , V_7 ,
( V_2 -> V_47 * V_48 ) / 1000 , & V_2 -> V_41 ) ;
if ( V_46 < 0 ) {
F_43 ( V_2 -> V_49 -> V_50 , L_1 ) ;
return V_46 ;
}
V_2 -> V_51 . V_52 . V_53 = F_36 ;
V_2 -> V_51 . V_52 . V_54 = F_38 ;
V_2 -> V_51 . V_52 . V_55 = F_39 ;
return 0 ;
}
static void F_44 ( struct V_1 * V_2 , int V_56 )
{
if ( V_2 -> V_41 )
F_31 ( V_2 , V_56 ) ;
if ( V_56 ) {
unsigned int V_57 ;
for ( V_57 = 0 ; V_57 < V_2 -> V_58 ; V_57 ++ ) {
if ( V_2 -> V_59 [ V_57 ] . V_52 . V_60 )
V_2 -> V_59 [ V_57 ] . V_52 . V_60 ( & V_2 -> V_59 [ V_57 ] , 0 ) ;
}
}
}
static T_3 F_45 ( int V_61 , void * V_62 )
{
struct V_1 * V_2 = V_62 ;
unsigned char V_63 ;
int V_64 = 0 ;
while ( 1 ) {
V_63 = F_2 ( F_12 ( V_2 , V_65 ) ) ;
if ( V_63 == 0 )
break;
V_64 = 1 ;
if ( V_63 & V_66 ) {
if ( V_2 -> V_67 [ 0 ] )
F_46 ( V_61 , V_2 -> V_67 [ 0 ] -> V_15 ) ;
F_6 ( V_66 , F_12 ( V_2 , V_65 ) ) ;
V_63 &= ~ V_66 ;
}
if ( V_63 & V_68 )
F_6 ( V_68 , F_12 ( V_2 , V_65 ) ) ;
if ( V_63 & V_69 ) {
if ( V_2 -> V_67 [ 1 ] )
F_46 ( V_61 , V_2 -> V_67 [ 1 ] -> V_15 ) ;
F_6 ( V_69 , F_12 ( V_2 , V_65 ) ) ;
V_63 &= ~ V_69 ;
}
if ( V_63 & V_70 ) {
unsigned char V_71 = F_2 ( F_3 ( V_2 , V_72 ) ) ;
if ( V_71 & V_73 ) {
if ( V_2 -> V_74 )
F_47 ( V_2 -> V_74 ) ;
F_6 ( V_73 , F_3 ( V_2 , V_72 ) ) ;
}
if ( V_71 & V_75 ) {
if ( V_2 -> V_76 )
F_47 ( V_2 -> V_76 ) ;
F_6 ( V_75 , F_3 ( V_2 , V_72 ) ) ;
}
}
if ( V_63 & V_77 )
F_6 ( V_77 , F_12 ( V_2 , V_65 ) ) ;
if ( V_63 & V_78 ) {
T_2 V_79 ;
T_4 V_80 ;
struct V_43 * V_44 ;
V_80 = F_15 ( F_7 ( V_2 , V_81 ) ) ;
for ( V_79 = 0 ; V_79 < 6 ; V_79 ++ ) {
if ( ( V_80 & ( 3 << ( V_79 * 2 ) ) ) == 0 )
continue;
V_44 = V_2 -> V_82 [ V_79 ] ;
if ( V_44 != NULL )
F_47 ( V_44 ) ;
F_13 ( 3 << ( V_79 * 2 ) , F_7 ( V_2 , V_81 ) ) ;
}
F_6 ( V_78 , F_12 ( V_2 , V_65 ) ) ;
}
if ( V_63 & V_83 ) {
if ( V_2 -> V_84 )
F_47 ( V_2 -> V_84 ) ;
F_6 ( V_83 , F_12 ( V_2 , V_65 ) ) ;
}
if ( V_63 & V_85 ) {
if ( V_2 -> V_86 )
F_47 ( V_2 -> V_86 ) ;
F_6 ( V_85 , F_12 ( V_2 , V_65 ) ) ;
}
}
return F_48 ( V_64 ) ;
}
static int F_49 ( struct V_43 * V_44 ,
struct V_87 * V_88 )
{
return F_50 ( V_44 , F_51 ( V_88 ) ) ;
}
static int F_52 ( struct V_43 * V_44 )
{
return F_53 ( V_44 ) ;
}
static int F_54 ( struct V_43 * V_44 ,
int V_89 )
{
struct V_1 * V_2 = F_55 ( V_44 ) ;
int V_90 = 0 ;
T_2 V_91 ;
F_56 ( & V_2 -> V_34 ) ;
V_91 = F_26 ( V_2 , V_92 ) ;
if ( V_89 == V_93 ) {
V_91 |= 1 ;
} else if ( V_89 == V_94 ) {
V_91 &= ~ 1 ;
} else if ( V_89 == V_95 ) {
V_91 |= 2 ;
} else if ( V_89 == V_96 ) {
V_91 &= ~ 2 ;
} else {
V_90 = - V_97 ;
}
F_24 ( V_2 , V_92 , V_91 ) ;
F_57 ( & V_2 -> V_34 ) ;
return V_90 ;
}
static int F_58 ( struct V_43 * V_44 ,
int V_89 )
{
struct V_1 * V_2 = F_55 ( V_44 ) ;
int V_90 = 0 ;
T_2 V_91 ;
F_56 ( & V_2 -> V_34 ) ;
V_91 = F_9 ( V_2 , V_44 -> V_98 * 2 , V_99 ) ;
if ( V_89 == V_93 ) {
V_91 |= 1 ;
} else if ( V_89 == V_94 ) {
V_91 &= ~ 1 ;
} else if ( V_89 == V_95 ) {
V_91 |= 2 ;
} else if ( V_89 == V_96 ) {
V_91 &= ~ 2 ;
} else {
V_90 = - V_97 ;
}
F_5 ( V_2 , V_44 -> V_98 * 2 , V_99 , V_91 ) ;
F_57 ( & V_2 -> V_34 ) ;
return V_90 ;
}
static int F_59 ( struct V_43 * V_44 ,
int V_89 )
{
struct V_1 * V_2 = F_55 ( V_44 ) ;
int V_90 = 0 ;
T_1 V_91 ;
F_56 ( & V_2 -> V_34 ) ;
V_91 = F_26 ( V_2 , V_100 ) ;
if ( V_89 == V_93 ) {
V_91 |= 1 ;
} else if ( V_89 == V_94 ) {
V_91 &= ~ 1 ;
} else {
V_90 = - V_97 ;
}
F_24 ( V_2 , V_100 , V_91 ) ;
F_57 ( & V_2 -> V_34 ) ;
return V_90 ;
}
static int F_60 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_55 ( V_44 ) ;
struct V_101 * V_102 = V_44 -> V_102 ;
T_2 V_103 , V_104 , V_45 , V_91 ;
V_103 = ( F_61 ( V_44 ) >> 2 ) - 1 ;
V_104 = F_62 ( V_44 ) - 1 ;
V_91 = 0x0000 ;
if ( F_63 ( V_102 -> V_105 ) == 16 )
V_91 |= 0x10 ;
if ( V_102 -> V_106 == 2 )
V_91 |= 0x08 ;
V_45 = ( V_102 -> V_45 * 8192 ) / 375 ;
if ( V_45 > 0x000fffff )
V_45 = 0x000fffff ;
F_21 ( & V_2 -> V_34 ) ;
F_6 ( 0 , V_2 -> V_107 + 15 ) ;
F_6 ( V_108 | V_109 , V_2 -> V_107 + 0x0b ) ;
F_8 ( V_102 -> V_110 , V_2 -> V_107 + 0 ) ;
F_13 ( V_104 , V_2 -> V_107 + 4 ) ;
F_24 ( V_2 , V_111 , V_45 & 0xff ) ;
F_24 ( V_2 , V_112 , ( V_45 >> 8 ) & 0xff ) ;
F_24 ( V_2 , V_113 , ( V_45 >> 16 ) & 0xff ) ;
F_24 ( V_2 , V_92 , V_91 ) ;
F_24 ( V_2 , V_114 , V_103 & 0xff ) ;
F_24 ( V_2 , V_115 , V_103 >> 8 ) ;
F_24 ( V_2 , V_116 , 0 ) ;
F_24 ( V_2 , V_117 , 0 ) ;
F_22 ( & V_2 -> V_34 ) ;
return 0 ;
}
static int F_64 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_55 ( V_44 ) ;
struct V_101 * V_102 = V_44 -> V_102 ;
T_2 V_103 , V_104 , V_45 , V_91 , V_118 ;
V_103 = F_61 ( V_44 ) - 1 ;
V_104 = F_62 ( V_44 ) - 1 ;
V_91 = 0x0064 ;
if ( F_63 ( V_102 -> V_105 ) == 16 )
V_91 &= ~ 0x04 ;
if ( V_102 -> V_106 == 2 )
V_91 |= 0x08 ;
V_45 = ( V_102 -> V_45 * 8192 ) / 375 ;
if ( V_45 > 0x000fffff )
V_45 = 0x000fffff ;
V_2 -> V_119 [ V_44 -> V_98 ] = 0 ;
V_2 -> V_120 [ V_44 -> V_98 ] = V_102 -> V_110 ;
V_118 = V_44 -> V_98 * 2 ;
F_21 ( & V_2 -> V_34 ) ;
F_5 ( V_2 , V_118 , V_121 , V_102 -> V_110 ) ;
F_5 ( V_2 , V_118 , V_122 , V_103 ) ;
F_5 ( V_2 , V_118 , V_123 , V_102 -> V_110 + ( V_102 -> V_124 > 1 ? V_103 + 1 : 0 ) ) ;
F_5 ( V_2 , V_118 , V_125 , V_103 ) ;
F_5 ( V_2 , V_118 , V_126 , V_45 ) ;
F_5 ( V_2 , V_118 , V_127 , 0 ) ;
F_5 ( V_2 , V_118 , V_99 , V_91 ) ;
if ( V_102 -> V_106 == 2 ) {
F_5 ( V_2 , V_118 + 1 , V_126 , V_45 ) ;
F_5 ( V_2 , V_118 + 1 , V_127 , 0 ) ;
}
F_22 ( & V_2 -> V_34 ) ;
return 0 ;
}
static int F_65 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_55 ( V_44 ) ;
struct V_101 * V_102 = V_44 -> V_102 ;
T_2 V_103 , V_104 ;
T_1 V_91 ;
V_103 = ( F_61 ( V_44 ) >> 2 ) - 1 ;
V_104 = F_62 ( V_44 ) - 1 ;
V_91 = 0x06 ;
if ( F_63 ( V_102 -> V_105 ) == 16 )
V_91 &= ~ 0x04 ;
if ( V_102 -> V_106 == 2 )
V_91 &= ~ 0x02 ;
F_21 ( & V_2 -> V_34 ) ;
F_8 ( V_2 -> V_128 = V_102 -> V_110 , F_12 ( V_2 , V_129 ) ) ;
F_13 ( V_104 , F_12 ( V_2 , V_130 ) ) ;
F_24 ( V_2 , V_131 , V_103 >> 8 ) ;
F_24 ( V_2 , V_132 , V_103 & 0xff ) ;
F_24 ( V_2 , V_100 , V_91 ) ;
F_22 ( & V_2 -> V_34 ) ;
F_66 ( V_2 -> V_12 , V_133 , V_102 -> V_45 ) ;
return 0 ;
}
static T_5 F_67 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_55 ( V_44 ) ;
struct V_101 * V_102 = V_44 -> V_102 ;
T_6 V_134 ;
if ( ! ( F_26 ( V_2 , V_92 ) & 1 ) )
return 0 ;
V_134 = V_102 -> V_135 - F_15 ( V_2 -> V_107 + 4 ) ;
V_134 = F_68 ( V_44 -> V_102 , V_134 ) ;
if ( V_134 == V_102 -> V_135 )
V_134 = 0 ;
return V_134 ;
}
static T_5 F_69 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_55 ( V_44 ) ;
T_1 V_7 ;
T_6 V_134 ;
if ( ! ( F_9 ( V_2 , V_44 -> V_98 * 2 , V_99 ) & 1 ) )
return 0 ;
if ( V_2 -> V_119 [ V_44 -> V_98 ] )
V_7 = V_123 ;
else
V_7 = V_121 ;
V_134 = F_9 ( V_2 , V_44 -> V_98 * 2 , V_7 ) -
V_2 -> V_120 [ V_44 -> V_98 ] ;
V_134 = F_68 ( V_44 -> V_102 , V_134 ) ;
if ( V_134 == V_44 -> V_102 -> V_135 )
V_134 = 0 ;
return V_134 ;
}
static T_5 F_70 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_55 ( V_44 ) ;
T_6 V_134 ;
if ( ! ( F_26 ( V_2 , V_100 ) & 1 ) )
return 0 ;
V_134 = F_10 ( F_12 ( V_2 , V_129 ) ) - V_2 -> V_128 ;
V_134 = F_68 ( V_44 -> V_102 , V_134 ) ;
if ( V_134 == V_44 -> V_102 -> V_135 )
V_134 = 0 ;
return V_134 ;
}
static int F_71 ( struct V_43 * V_44 )
{
struct V_101 * V_102 = V_44 -> V_102 ;
struct V_1 * V_2 = F_55 ( V_44 ) ;
V_2 -> V_86 = V_44 ;
V_102 -> V_136 = V_137 ;
return 0 ;
}
static int F_72 ( struct V_43 * V_44 )
{
struct V_101 * V_102 = V_44 -> V_102 ;
struct V_1 * V_2 = F_55 ( V_44 ) ;
T_2 V_91 ;
V_2 -> V_82 [ V_44 -> V_98 ] = V_44 ;
V_102 -> V_136 = V_138 ;
F_21 ( & V_2 -> V_34 ) ;
V_91 = F_15 ( F_7 ( V_2 , V_139 ) ) & ~ ( 1 << ( V_44 -> V_98 * 2 ) ) ;
F_13 ( V_91 , F_7 ( V_2 , V_139 ) ) ;
F_22 ( & V_2 -> V_34 ) ;
return 0 ;
}
static int F_73 ( struct V_43 * V_44 )
{
struct V_101 * V_102 = V_44 -> V_102 ;
struct V_1 * V_2 = F_55 ( V_44 ) ;
V_2 -> V_84 = V_44 ;
V_102 -> V_136 = V_140 ;
V_102 -> V_136 . V_141 = V_2 -> V_12 -> V_141 [ V_142 ] ;
if ( ! ( V_102 -> V_136 . V_141 & V_143 ) )
V_102 -> V_136 . V_144 = 48000 ;
return 0 ;
}
static int F_74 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_55 ( V_44 ) ;
V_2 -> V_86 = NULL ;
return 0 ;
}
static int F_75 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_55 ( V_44 ) ;
T_2 V_91 ;
F_21 ( & V_2 -> V_34 ) ;
V_91 = F_15 ( F_7 ( V_2 , V_139 ) ) | ( 3 << ( V_44 -> V_98 * 2 ) ) ;
F_13 ( V_91 , F_7 ( V_2 , V_139 ) ) ;
F_22 ( & V_2 -> V_34 ) ;
V_2 -> V_82 [ V_44 -> V_98 ] = NULL ;
return 0 ;
}
static int F_76 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_55 ( V_44 ) ;
V_2 -> V_84 = NULL ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 , int V_145 , struct V_146 * * V_147 )
{
struct V_146 * V_148 ;
int V_46 ;
if ( V_147 )
* V_147 = NULL ;
V_46 = F_78 ( V_2 -> V_49 , L_2 , V_145 , 1 , 1 , & V_148 ) ;
if ( V_46 < 0 )
return V_46 ;
F_79 ( V_148 , V_149 , & V_150 ) ;
F_79 ( V_148 , V_151 , & V_152 ) ;
V_148 -> V_15 = V_2 ;
V_148 -> V_153 = 0 ;
strcpy ( V_148 -> V_154 , L_2 ) ;
V_2 -> V_148 = V_148 ;
F_80 ( V_148 , V_155 ,
F_81 ( V_2 -> V_156 ) , 64 * 1024 , 64 * 1024 ) ;
if ( V_147 )
* V_147 = V_148 ;
F_82 ( V_2 -> V_49 -> V_50 ,
L_3 ) ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 , int V_145 , struct V_146 * * V_147 )
{
struct V_146 * V_148 ;
int V_46 ;
if ( V_147 )
* V_147 = NULL ;
V_46 = F_78 ( V_2 -> V_49 , L_4 , V_145 , 6 , 0 , & V_148 ) ;
if ( V_46 < 0 )
return V_46 ;
F_79 ( V_148 , V_149 , & V_157 ) ;
V_148 -> V_15 = V_2 ;
V_148 -> V_153 = 0 ;
strcpy ( V_148 -> V_154 , L_4 ) ;
V_2 -> V_158 = V_148 ;
F_80 ( V_148 , V_155 ,
F_81 ( V_2 -> V_156 ) , 64 * 1024 , 128 * 1024 ) ;
if ( V_147 )
* V_147 = V_148 ;
return 0 ;
}
static int F_84 ( struct V_43 * V_44 ,
int V_89 )
{
struct V_1 * V_2 = F_55 ( V_44 ) ;
switch ( V_89 ) {
case V_95 :
case V_96 :
{
unsigned int V_159 ;
unsigned int V_160 ;
if ( V_44 -> V_161 != V_149 )
return - V_97 ;
V_159 = V_162 ;
F_85 ( V_44 , V_44 ) ;
F_56 ( & V_2 -> V_34 ) ;
V_160 = F_10 ( F_3 ( V_2 , V_163 ) ) ;
if ( V_89 == V_95 )
V_160 |= V_159 ;
else
V_160 &= ~ V_159 ;
F_8 ( V_160 , F_3 ( V_2 , V_163 ) ) ;
F_57 ( & V_2 -> V_34 ) ;
break;
}
case V_93 :
case V_94 :
{
unsigned int V_159 = 0 ;
unsigned int V_160 ;
struct V_43 * V_164 ;
F_86 (s, substream) {
if ( V_164 == V_2 -> V_74 ) {
V_159 |= V_165 ;
F_85 ( V_164 , V_44 ) ;
} else if ( V_164 == V_2 -> V_76 ) {
V_159 |= V_166 ;
F_85 ( V_164 , V_44 ) ;
}
}
F_56 ( & V_2 -> V_34 ) ;
V_160 = F_10 ( F_3 ( V_2 , V_163 ) ) ;
if ( V_89 == V_93 )
V_160 |= V_159 ;
else
V_160 &= ~ V_159 ;
F_8 ( V_160 , F_3 ( V_2 , V_163 ) ) ;
F_57 ( & V_2 -> V_34 ) ;
break;
}
default:
return - V_97 ;
}
return 0 ;
}
static void F_87 ( struct V_1 * V_2 , unsigned int V_45 , int V_167 )
{
unsigned long V_168 ;
unsigned char V_14 , V_160 ;
unsigned int V_57 ;
switch ( V_45 ) {
case 8000 : V_14 = 6 ; break;
case 9600 : V_14 = 3 ; break;
case 11025 : V_14 = 10 ; break;
case 12000 : V_14 = 2 ; break;
case 16000 : V_14 = 5 ; break;
case 22050 : V_14 = 9 ; break;
case 24000 : V_14 = 1 ; break;
case 32000 : V_14 = 4 ; break;
case 44100 : V_14 = 8 ; break;
case 48000 : V_14 = 0 ; break;
case 64000 : V_14 = 15 ; break;
case 88200 : V_14 = 11 ; break;
case 96000 : V_14 = 7 ; break;
default:
F_88 () ;
V_14 = 0 ;
V_45 = 48000 ;
break;
}
F_89 ( & V_2 -> V_34 , V_168 ) ;
if ( F_2 ( F_3 ( V_2 , V_163 ) ) & ( V_166 |
V_162 |
V_165 ) ) {
V_169:
F_90 ( & V_2 -> V_34 , V_168 ) ;
return;
}
if ( ! V_167 && F_4 ( V_2 ) )
goto V_169;
V_160 = F_2 ( F_3 ( V_2 , V_3 ) ) ;
if ( ! V_167 && V_160 == V_14 )
goto V_169;
V_2 -> V_170 = V_45 ;
F_6 ( V_14 , F_3 ( V_2 , V_3 ) ) ;
F_90 ( & V_2 -> V_34 , V_168 ) ;
if ( V_2 -> V_171 . V_172 )
V_2 -> V_171 . V_172 ( V_2 , V_45 ) ;
for ( V_57 = 0 ; V_57 < V_2 -> V_58 ; V_57 ++ ) {
if ( V_2 -> V_59 [ V_57 ] . V_52 . V_60 )
V_2 -> V_59 [ V_57 ] . V_52 . V_60 ( & V_2 -> V_59 [ V_57 ] , V_45 ) ;
}
if ( V_2 -> V_51 . V_52 . V_55 )
V_2 -> V_51 . V_52 . V_55 ( V_2 , V_45 ) ;
}
static int F_91 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_55 ( V_44 ) ;
V_2 -> V_173 = F_62 ( V_44 ) ;
F_21 ( & V_2 -> V_34 ) ;
F_8 ( V_44 -> V_102 -> V_110 , F_3 ( V_2 , V_174 ) ) ;
F_13 ( ( V_2 -> V_173 >> 2 ) - 1 , F_3 ( V_2 , V_175 ) ) ;
F_13 ( ( F_61 ( V_44 ) >> 2 ) - 1 , F_3 ( V_2 , V_176 ) ) ;
F_22 ( & V_2 -> V_34 ) ;
return 0 ;
}
static int F_92 ( struct V_43 * V_44 ,
struct V_87 * V_88 )
{
struct V_1 * V_2 = F_55 ( V_44 ) ;
F_87 ( V_2 , F_93 ( V_88 ) , 0 ) ;
return F_50 ( V_44 , F_51 ( V_88 ) ) ;
}
static int F_94 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_55 ( V_44 ) ;
V_2 -> V_177 = F_62 ( V_44 ) ;
F_21 ( & V_2 -> V_34 ) ;
F_8 ( V_44 -> V_102 -> V_110 , F_3 ( V_2 , V_178 ) ) ;
F_13 ( ( V_2 -> V_177 >> 2 ) - 1 , F_3 ( V_2 , V_179 ) ) ;
F_13 ( ( F_61 ( V_44 ) >> 2 ) - 1 , F_3 ( V_2 , V_180 ) ) ;
F_22 ( & V_2 -> V_34 ) ;
return 0 ;
}
static int F_95 ( struct V_43 * V_44 ,
struct V_87 * V_88 )
{
struct V_1 * V_2 = F_55 ( V_44 ) ;
F_87 ( V_2 , F_93 ( V_88 ) , 0 ) ;
return F_50 ( V_44 , F_51 ( V_88 ) ) ;
}
static T_5 F_96 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_55 ( V_44 ) ;
T_6 V_134 ;
if ( ! ( F_10 ( F_3 ( V_2 , V_163 ) ) & V_165 ) )
return 0 ;
V_134 = V_2 -> V_173 - ( F_15 ( F_3 ( V_2 , V_175 ) ) << 2 ) ;
V_134 = F_68 ( V_44 -> V_102 , V_134 ) ;
if ( V_134 == V_44 -> V_102 -> V_135 )
V_134 = 0 ;
return V_134 ;
}
static T_5 F_97 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_55 ( V_44 ) ;
T_6 V_134 ;
if ( ! ( F_10 ( F_3 ( V_2 , V_163 ) ) & V_166 ) )
return 0 ;
V_134 = V_2 -> V_177 - ( F_15 ( F_3 ( V_2 , V_179 ) ) << 2 ) ;
V_134 = F_68 ( V_44 -> V_102 , V_134 ) ;
if ( V_134 == V_44 -> V_102 -> V_135 )
V_134 = 0 ;
return V_134 ;
}
static int F_98 ( struct V_43 * V_44 )
{
struct V_101 * V_102 = V_44 -> V_102 ;
struct V_1 * V_2 = F_55 ( V_44 ) ;
V_2 -> V_74 = V_44 ;
V_102 -> V_136 = V_181 ;
F_99 ( V_44 ) ;
F_100 ( V_102 , 0 , 32 , 24 ) ;
F_101 ( V_102 , 0 , V_182 , & V_183 ) ;
if ( F_4 ( V_2 ) ) {
V_102 -> V_136 . V_144 = V_184 ;
V_102 -> V_136 . V_185 = V_184 ;
}
if ( V_2 -> V_51 . V_52 . V_53 )
V_2 -> V_51 . V_52 . V_53 ( V_2 , V_44 ) ;
return 0 ;
}
static int F_102 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_55 ( V_44 ) ;
struct V_101 * V_102 = V_44 -> V_102 ;
V_2 -> V_76 = V_44 ;
V_102 -> V_136 = V_186 ;
F_99 ( V_44 ) ;
F_100 ( V_102 , 0 , 32 , 24 ) ;
F_101 ( V_102 , 0 , V_182 , & V_183 ) ;
if ( F_4 ( V_2 ) ) {
V_102 -> V_136 . V_144 = V_184 ;
V_102 -> V_136 . V_185 = V_184 ;
}
return 0 ;
}
static int F_103 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_55 ( V_44 ) ;
if ( V_187 )
F_87 ( V_2 , V_184 , 0 ) ;
V_2 -> V_74 = NULL ;
if ( V_2 -> V_51 . V_52 . V_54 )
V_2 -> V_51 . V_52 . V_54 ( V_2 , V_44 ) ;
return 0 ;
}
static int F_104 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_55 ( V_44 ) ;
if ( V_187 )
F_87 ( V_2 , V_184 , 0 ) ;
V_2 -> V_76 = NULL ;
return 0 ;
}
static int F_105 ( struct V_1 * V_2 , int V_145 , struct V_146 * * V_147 )
{
struct V_146 * V_148 ;
int V_46 ;
if ( V_147 )
* V_147 = NULL ;
V_46 = F_78 ( V_2 -> V_49 , L_5 , V_145 , 1 , 1 , & V_148 ) ;
if ( V_46 < 0 )
return V_46 ;
F_79 ( V_148 , V_149 , & V_188 ) ;
F_79 ( V_148 , V_151 , & V_189 ) ;
V_148 -> V_15 = V_2 ;
V_148 -> V_153 = 0 ;
strcpy ( V_148 -> V_154 , L_5 ) ;
F_80 ( V_148 , V_155 ,
F_81 ( V_2 -> V_156 ) , 256 * 1024 , 256 * 1024 ) ;
V_2 -> V_190 = V_148 ;
if ( V_147 )
* V_147 = V_148 ;
if ( V_2 -> V_41 ) {
V_46 = F_106 ( V_2 -> V_41 ,
V_148 -> V_191 [ 0 ] . V_44 ,
V_148 -> V_191 [ 1 ] . V_44 ) ;
if ( V_46 < 0 )
return V_46 ;
}
V_46 = F_107 ( V_2 ) ;
if ( V_46 < 0 )
return V_46 ;
return 0 ;
}
static void F_108 ( struct V_1 * V_2 , int V_192 )
{
unsigned int V_193 = V_2 -> V_194 [ V_192 ] ;
unsigned short V_14 = 0 ;
V_14 |= ( V_193 & 0x8000 ) == 0 ? ( 96 - ( V_193 & 0x7f ) ) : 0x7f ;
V_14 |= ( ( V_193 & 0x80000000 ) == 0 ? ( 96 - ( ( V_193 >> 16 ) & 0x7f ) ) : 0x7f ) << 8 ;
F_6 ( V_192 , F_3 ( V_2 , V_195 ) ) ;
F_13 ( V_14 , F_3 ( V_2 , V_196 ) ) ;
}
static int F_109 ( struct V_26 * V_27 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_19 ( V_27 ) ;
int V_197 = F_110 ( V_27 , & V_29 -> V_198 ) +
V_27 -> V_199 ;
F_21 ( & V_2 -> V_34 ) ;
V_29 -> V_30 . integer . V_30 [ 0 ] =
! ( ( V_2 -> V_194 [ V_197 ] >> 15 ) & 1 ) ;
V_29 -> V_30 . integer . V_30 [ 1 ] =
! ( ( V_2 -> V_194 [ V_197 ] >> 31 ) & 1 ) ;
F_22 ( & V_2 -> V_34 ) ;
return 0 ;
}
static int F_111 ( struct V_26 * V_27 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_19 ( V_27 ) ;
int V_197 = F_110 ( V_27 , & V_29 -> V_198 ) +
V_27 -> V_199 ;
unsigned int V_33 , V_200 ;
V_33 = ( V_29 -> V_30 . integer . V_30 [ 0 ] ? 0 : 0x00008000 ) |
( V_29 -> V_30 . integer . V_30 [ 1 ] ? 0 : 0x80000000 ) ;
F_21 ( & V_2 -> V_34 ) ;
V_33 |= V_2 -> V_194 [ V_197 ] & ~ 0x80008000 ;
V_200 = V_33 != V_2 -> V_194 [ V_197 ] ;
V_2 -> V_194 [ V_197 ] = V_33 ;
F_108 ( V_2 , V_197 ) ;
F_22 ( & V_2 -> V_34 ) ;
return V_200 ;
}
static int F_112 ( struct V_26 * V_27 , struct V_201 * V_202 )
{
V_202 -> type = V_203 ;
V_202 -> V_204 = 2 ;
V_202 -> V_30 . integer . V_205 = 0 ;
V_202 -> V_30 . integer . V_206 = 96 ;
return 0 ;
}
static int F_113 ( struct V_26 * V_27 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_19 ( V_27 ) ;
int V_197 = F_110 ( V_27 , & V_29 -> V_198 ) +
V_27 -> V_199 ;
F_21 ( & V_2 -> V_34 ) ;
V_29 -> V_30 . integer . V_30 [ 0 ] =
( V_2 -> V_194 [ V_197 ] >> 0 ) & 127 ;
V_29 -> V_30 . integer . V_30 [ 1 ] =
( V_2 -> V_194 [ V_197 ] >> 16 ) & 127 ;
F_22 ( & V_2 -> V_34 ) ;
return 0 ;
}
static int F_114 ( struct V_26 * V_27 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_19 ( V_27 ) ;
int V_197 = F_110 ( V_27 , & V_29 -> V_198 ) +
V_27 -> V_199 ;
unsigned int V_33 , V_200 ;
V_33 = ( V_29 -> V_30 . integer . V_30 [ 0 ] & 127 ) |
( ( V_29 -> V_30 . integer . V_30 [ 1 ] & 127 ) << 16 ) ;
F_21 ( & V_2 -> V_34 ) ;
V_33 |= V_2 -> V_194 [ V_197 ] & ~ 0x007f007f ;
V_200 = V_33 != V_2 -> V_194 [ V_197 ] ;
V_2 -> V_194 [ V_197 ] = V_33 ;
F_108 ( V_2 , V_197 ) ;
F_22 ( & V_2 -> V_34 ) ;
return V_200 ;
}
static int F_107 ( struct V_1 * V_2 )
{
struct V_207 * V_49 = V_2 -> V_49 ;
unsigned int V_79 ;
int V_46 ;
for ( V_79 = 0 ; V_79 < F_115 ( V_208 ) ; V_79 ++ ) {
V_46 = F_116 ( V_49 , F_117 ( & V_208 [ V_79 ] , V_2 ) ) ;
if ( V_46 < 0 )
return V_46 ;
}
if ( V_2 -> V_209 > 0 ) {
struct V_210 V_91 = V_211 ;
V_91 . V_204 = V_2 -> V_209 ;
V_46 = F_116 ( V_49 , F_117 ( & V_91 , V_2 ) ) ;
if ( V_46 < 0 )
return V_46 ;
}
V_46 = F_116 ( V_49 , F_117 ( & V_212 , V_2 ) ) ;
if ( V_46 < 0 )
return V_46 ;
if ( V_2 -> V_209 > 0 ) {
struct V_210 V_91 = V_213 ;
V_91 . V_204 = V_2 -> V_209 ;
V_46 = F_116 ( V_49 , F_117 ( & V_91 , V_2 ) ) ;
if ( V_46 < 0 )
return V_46 ;
}
V_46 = F_116 ( V_49 , F_117 ( & V_214 , V_2 ) ) ;
if ( V_46 < 0 )
return V_46 ;
for ( V_79 = 0 ; V_79 < 10 ; V_79 ++ ) {
V_2 -> V_194 [ V_79 ] = 0x80008000 ;
F_108 ( V_2 , V_79 ) ;
}
for ( V_79 = 10 ; V_79 < 10 + V_2 -> V_209 ; V_79 ++ ) {
V_2 -> V_194 [ V_79 ] = 0x80008000 ;
F_108 ( V_2 , V_79 ) ;
}
for ( V_79 = 18 ; V_79 < 20 ; V_79 ++ ) {
V_2 -> V_194 [ V_79 ] = 0x80008000 ;
F_108 ( V_2 , V_79 ) ;
}
return 0 ;
}
static void F_118 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_15 ;
V_2 -> V_12 = NULL ;
}
static int F_119 ( struct V_1 * V_2 )
{
int V_46 , V_215 = 0 ;
struct V_216 V_12 ;
struct V_217 * V_218 ;
static struct V_219 V_220 = {
. V_221 = F_11 ,
. V_222 = F_14 ,
} ;
static struct V_219 V_223 = {
. V_221 = F_16 ,
. V_222 = F_17 ,
} ;
if ( F_120 ( V_2 ) ) {
V_46 = V_217 ( V_2 -> V_49 , V_215 ++ , & V_220 , NULL , & V_218 ) ;
if ( V_46 < 0 )
return V_46 ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_12 . V_15 = V_2 ;
V_12 . V_224 = F_118 ;
V_46 = F_121 ( V_218 , & V_12 , & V_2 -> V_12 ) ;
if ( V_46 < 0 )
F_82 ( V_2 -> V_49 -> V_50 ,
L_6 ) ;
else {
V_46 = F_116 ( V_2 -> V_49 , F_117 ( & V_225 , V_2 ) ) ;
if ( V_46 < 0 )
return V_46 ;
return 0 ;
}
}
if ( ! ( V_2 -> V_226 . V_8 [ V_227 ] & V_228 ) ) {
V_46 = V_217 ( V_2 -> V_49 , V_215 , & V_223 , NULL , & V_218 ) ;
if ( V_46 < 0 )
return V_46 ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_12 . V_15 = V_2 ;
V_12 . V_224 = F_118 ;
V_46 = F_121 ( V_218 , & V_12 , & V_2 -> V_12 ) ;
if ( V_46 < 0 )
F_82 ( V_2 -> V_49 -> V_50 ,
L_7 ) ;
else
return 0 ;
}
strcat ( V_2 -> V_49 -> V_229 , L_8 ) ;
return 0 ;
}
static inline unsigned int F_122 ( struct V_1 * V_2 , int V_79 )
{
return ( unsigned int ) V_2 -> V_226 . V_8 [ V_79 ] | ( ( unsigned int ) V_2 -> V_226 . V_8 [ V_79 + 1 ] << 8 ) ;
}
static void F_123 ( struct V_230 * V_231 ,
struct V_232 * V_233 )
{
struct V_1 * V_2 = V_231 -> V_15 ;
unsigned int V_79 ;
F_124 ( V_233 , L_9 , V_2 -> V_49 -> V_234 ) ;
F_124 ( V_233 , L_10 ) ;
F_124 ( V_233 , L_11 , V_2 -> V_226 . V_235 ) ;
F_124 ( V_233 , L_12 , V_2 -> V_226 . V_236 ) ;
F_124 ( V_233 , L_13 , V_2 -> V_226 . V_237 ) ;
F_124 ( V_233 , L_14 , V_2 -> V_226 . V_8 [ V_238 ] ) ;
F_124 ( V_233 , L_15 , V_2 -> V_226 . V_8 [ V_227 ] ) ;
F_124 ( V_233 , L_16 , V_2 -> V_226 . V_8 [ V_239 ] ) ;
F_124 ( V_233 , L_17 , V_2 -> V_226 . V_8 [ V_240 ] ) ;
F_124 ( V_233 , L_18 , V_2 -> V_226 . V_241 ) ;
F_124 ( V_233 , L_19 , V_2 -> V_226 . V_242 ) ;
F_124 ( V_233 , L_20 , V_2 -> V_226 . V_243 ) ;
F_124 ( V_233 , L_21 , F_122 ( V_2 , V_244 ) ) ;
F_124 ( V_233 , L_22 , F_122 ( V_2 , V_245 ) ) ;
F_124 ( V_233 , L_23 , F_122 ( V_2 , V_246 ) ) ;
F_124 ( V_233 , L_24 , V_2 -> V_226 . V_8 [ V_247 ] ) ;
for ( V_79 = 0 ; V_79 < 4 ; V_79 ++ )
F_124 ( V_233 , L_25 , V_79 , V_2 -> V_226 . V_8 [ V_248 + V_79 ] ) ;
for ( V_79 = 0 ; V_79 < 4 ; V_79 ++ )
F_124 ( V_233 , L_26 , V_79 , V_2 -> V_226 . V_8 [ V_249 + V_79 ] ) ;
for ( V_79 = 0x1c ; V_79 < V_2 -> V_226 . V_236 ; V_79 ++ )
F_124 ( V_233 , L_27 , V_79 , V_2 -> V_226 . V_8 [ V_79 ] ) ;
F_124 ( V_233 , L_28 ) ;
F_124 ( V_233 , L_29 , ( unsigned ) F_15 ( F_3 ( V_2 , V_250 ) ) ) ;
F_124 ( V_233 , L_30 , F_10 ( F_3 ( V_2 , V_251 ) ) ) ;
F_124 ( V_233 , L_31 , ( unsigned ) F_15 ( F_3 ( V_2 , V_252 ) ) ) ;
F_124 ( V_233 , L_32 , ( unsigned ) F_2 ( F_3 ( V_2 , V_3 ) ) ) ;
F_124 ( V_233 , L_33 , ( unsigned ) F_29 ( V_2 ) ) ;
F_124 ( V_233 , L_34 , ( unsigned ) F_26 ( V_2 , V_36 ) ) ;
F_124 ( V_233 , L_35 , ( unsigned ) F_26 ( V_2 , V_35 ) ) ;
}
static void F_125 ( struct V_1 * V_2 )
{
struct V_230 * V_231 ;
if ( ! F_126 ( V_2 -> V_49 , L_36 , & V_231 ) )
F_127 ( V_231 , V_2 , F_123 ) ;
}
static int F_128 ( struct V_26 * V_27 ,
struct V_201 * V_202 )
{
V_202 -> type = V_253 ;
V_202 -> V_204 = sizeof( struct V_254 ) ;
return 0 ;
}
static int F_129 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 = F_19 ( V_27 ) ;
memcpy ( V_29 -> V_30 . V_255 . V_8 , & V_2 -> V_226 , sizeof( V_2 -> V_226 ) ) ;
return 0 ;
}
static int F_130 ( struct V_26 * V_27 ,
struct V_201 * V_202 )
{
V_202 -> type = V_256 ;
V_202 -> V_204 = 1 ;
return 0 ;
}
static int F_131 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 = F_19 ( V_27 ) ;
if ( V_2 -> V_51 . V_52 . V_257 )
V_2 -> V_51 . V_52 . V_257 ( V_2 , V_29 ) ;
return 0 ;
}
static int F_132 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 = F_19 ( V_27 ) ;
if ( V_2 -> V_51 . V_52 . V_258 )
return V_2 -> V_51 . V_52 . V_258 ( V_2 , V_29 ) ;
return 0 ;
}
static int F_133 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 = F_19 ( V_27 ) ;
if ( V_2 -> V_51 . V_52 . V_257 ) {
V_29 -> V_30 . V_259 . V_63 [ 0 ] = V_260 |
V_261 |
V_262 |
V_263 ;
V_29 -> V_30 . V_259 . V_63 [ 1 ] = V_264 |
V_265 ;
V_29 -> V_30 . V_259 . V_63 [ 3 ] = V_266 ;
} else {
V_29 -> V_30 . V_259 . V_63 [ 0 ] = 0xff ;
V_29 -> V_30 . V_259 . V_63 [ 1 ] = 0xff ;
V_29 -> V_30 . V_259 . V_63 [ 2 ] = 0xff ;
V_29 -> V_30 . V_259 . V_63 [ 3 ] = 0xff ;
V_29 -> V_30 . V_259 . V_63 [ 4 ] = 0xff ;
}
return 0 ;
}
static int F_134 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 = F_19 ( V_27 ) ;
if ( V_2 -> V_51 . V_52 . V_257 ) {
V_29 -> V_30 . V_259 . V_63 [ 0 ] = V_260 |
V_261 |
V_267 |
V_268 ;
V_29 -> V_30 . V_259 . V_63 [ 1 ] = V_269 ;
} else {
V_29 -> V_30 . V_259 . V_63 [ 0 ] = 0xff ;
V_29 -> V_30 . V_259 . V_63 [ 1 ] = 0xff ;
V_29 -> V_30 . V_259 . V_63 [ 2 ] = 0xff ;
V_29 -> V_30 . V_259 . V_63 [ 3 ] = 0xff ;
V_29 -> V_30 . V_259 . V_63 [ 4 ] = 0xff ;
}
return 0 ;
}
static int F_135 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 = F_19 ( V_27 ) ;
if ( V_2 -> V_51 . V_52 . V_270 )
V_2 -> V_51 . V_52 . V_270 ( V_2 , V_29 ) ;
return 0 ;
}
static int F_136 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 = F_19 ( V_27 ) ;
if ( V_2 -> V_51 . V_52 . V_271 )
return V_2 -> V_51 . V_52 . V_271 ( V_2 , V_29 ) ;
return 0 ;
}
int F_137 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 = F_19 ( V_27 ) ;
unsigned char V_272 = V_27 -> V_199 & 0xff ;
int V_273 = ( V_27 -> V_199 & ( 1 << 24 ) ) ? 1 : 0 ;
F_138 ( V_2 ) ;
V_29 -> V_30 . integer . V_30 [ 0 ] =
( F_139 ( V_2 ) & V_272 ? 1 : 0 ) ^ V_273 ;
F_140 ( V_2 ) ;
return 0 ;
}
int F_141 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 = F_19 ( V_27 ) ;
unsigned char V_272 = V_27 -> V_199 & 0xff ;
int V_273 = ( V_27 -> V_199 & ( 1 << 24 ) ) ? V_272 : 0 ;
unsigned int V_14 , V_33 ;
if ( V_27 -> V_199 & ( 1 << 31 ) )
return - V_274 ;
V_33 = ( V_29 -> V_30 . integer . V_30 [ 0 ] ? V_272 : 0 ) ^ V_273 ;
F_138 ( V_2 ) ;
V_14 = F_139 ( V_2 ) ;
V_33 |= V_14 & ~ V_272 ;
if ( V_14 != V_33 )
F_142 ( V_2 , V_33 ) ;
F_140 ( V_2 ) ;
return V_14 != V_33 ;
}
static int F_143 ( struct V_26 * V_27 ,
struct V_201 * V_202 )
{
static const char * const V_275 [] = {
L_37 ,
L_38 ,
L_39 ,
L_40 ,
L_41 ,
L_42 ,
L_43 ,
L_44 ,
L_45 ,
L_46 ,
L_47 ,
L_48 ,
L_49 ,
L_50 ,
} ;
V_202 -> type = V_276 ;
V_202 -> V_204 = 1 ;
V_202 -> V_30 . V_277 . V_278 = 14 ;
if ( V_202 -> V_30 . V_277 . V_279 >= V_202 -> V_30 . V_277 . V_278 )
V_202 -> V_30 . V_277 . V_279 = V_202 -> V_30 . V_277 . V_278 - 1 ;
strcpy ( V_202 -> V_30 . V_277 . V_154 , V_275 [ V_202 -> V_30 . V_277 . V_279 ] ) ;
return 0 ;
}
static int F_144 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 = F_19 ( V_27 ) ;
static const unsigned char V_280 [ 16 ] = {
9 , 6 , 3 , 1 , 7 , 4 , 0 , 12 , 8 , 5 , 2 , 11 , 255 , 255 , 255 , 10
} ;
unsigned char V_14 ;
F_21 ( & V_2 -> V_34 ) ;
if ( F_1 ( V_2 ) ) {
V_29 -> V_30 . V_277 . V_279 [ 0 ] = 13 ;
} else {
V_14 = V_280 [ F_2 ( F_3 ( V_2 , V_3 ) ) & 15 ] ;
if ( V_14 == 255 ) {
F_88 () ;
V_14 = 0 ;
}
V_29 -> V_30 . V_277 . V_279 [ 0 ] = V_14 ;
}
F_22 ( & V_2 -> V_34 ) ;
return 0 ;
}
static int F_145 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 = F_19 ( V_27 ) ;
static const unsigned int V_281 [ 13 ] = {
8000 , 9600 , 11025 , 12000 , 16000 , 22050 , 24000 ,
32000 , 44100 , 48000 , 64000 , 88200 , 96000
} ;
unsigned char V_282 ;
int V_200 = 0 ;
F_21 ( & V_2 -> V_34 ) ;
V_282 = F_2 ( F_3 ( V_2 , V_3 ) ) ;
if ( V_29 -> V_30 . V_277 . V_279 [ 0 ] == 13 ) {
F_6 ( V_282 | V_4 , F_3 ( V_2 , V_3 ) ) ;
} else {
V_184 = V_281 [ V_29 -> V_30 . integer . V_30 [ 0 ] % 13 ] ;
F_22 ( & V_2 -> V_34 ) ;
F_87 ( V_2 , V_184 , 1 ) ;
F_21 ( & V_2 -> V_34 ) ;
}
V_200 = F_2 ( F_3 ( V_2 , V_3 ) ) != V_282 ;
F_22 ( & V_2 -> V_34 ) ;
if ( ( V_282 & V_4 ) !=
( F_2 ( F_3 ( V_2 , V_3 ) ) & V_4 ) )
F_44 ( V_2 , F_1 ( V_2 ) ) ;
return V_200 ;
}
static int F_146 ( struct V_26 * V_27 ,
struct V_201 * V_202 )
{
static const char * const V_275 [] = {
L_37 ,
L_38 ,
L_39 ,
L_40 ,
L_41 ,
L_42 ,
L_43 ,
L_44 ,
L_45 ,
L_46 ,
L_47 ,
L_48 ,
L_49 ,
} ;
V_202 -> type = V_276 ;
V_202 -> V_204 = 1 ;
V_202 -> V_30 . V_277 . V_278 = 13 ;
if ( V_202 -> V_30 . V_277 . V_279 >= V_202 -> V_30 . V_277 . V_278 )
V_202 -> V_30 . V_277 . V_279 = V_202 -> V_30 . V_277 . V_278 - 1 ;
strcpy ( V_202 -> V_30 . V_277 . V_154 , V_275 [ V_202 -> V_30 . V_277 . V_279 ] ) ;
return 0 ;
}
static int F_147 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
int V_14 ;
static const unsigned int V_281 [ 13 ] = {
8000 , 9600 , 11025 , 12000 , 16000 , 22050 , 24000 ,
32000 , 44100 , 48000 , 64000 , 88200 , 96000
} ;
for ( V_14 = 0 ; V_14 < 13 ; V_14 ++ ) {
if ( V_281 [ V_14 ] == V_184 )
break;
}
V_29 -> V_30 . V_277 . V_279 [ 0 ] = V_14 ;
return 0 ;
}
static int F_148 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
static const unsigned int V_281 [ 13 ] = {
8000 , 9600 , 11025 , 12000 , 16000 , 22050 , 24000 ,
32000 , 44100 , 48000 , 64000 , 88200 , 96000
} ;
unsigned char V_282 ;
int V_200 = 0 ;
V_282 = V_184 ;
V_184 = V_281 [ V_29 -> V_30 . integer . V_30 [ 0 ] % 13 ] ;
V_200 = V_184 != V_282 ;
return V_200 ;
}
static int F_149 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
V_29 -> V_30 . integer . V_30 [ 0 ] = V_5 ;
return 0 ;
}
static int F_150 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 = F_19 ( V_27 ) ;
int V_200 = 0 , V_33 ;
V_33 = V_29 -> V_30 . integer . V_30 [ 0 ] ? 1 : 0 ;
F_21 ( & V_2 -> V_34 ) ;
V_200 = V_5 != V_33 ;
V_5 = V_33 ;
F_22 ( & V_2 -> V_34 ) ;
return V_200 ;
}
static int F_151 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
V_29 -> V_30 . integer . V_30 [ 0 ] = V_187 ;
return 0 ;
}
static int F_152 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 = F_19 ( V_27 ) ;
int V_200 = 0 , V_33 ;
V_33 = V_29 -> V_30 . integer . V_30 [ 0 ] ? 1 : 0 ;
F_21 ( & V_2 -> V_34 ) ;
V_200 = V_187 != V_33 ;
V_187 = V_33 ;
F_22 ( & V_2 -> V_34 ) ;
return V_200 ;
}
static int F_153 ( struct V_26 * V_27 ,
struct V_201 * V_202 )
{
static const char * const V_275 [] = {
L_51 ,
L_52 , L_53 , L_54 , L_55 ,
L_56 , L_57 , L_58 , L_59 ,
L_60 , L_61 ,
L_62 ,
} ;
V_202 -> type = V_276 ;
V_202 -> V_204 = 1 ;
V_202 -> V_30 . V_277 . V_278 =
F_110 ( V_27 , & V_202 -> V_198 ) < 2 ? 12 : 11 ;
if ( V_202 -> V_30 . V_277 . V_279 >= V_202 -> V_30 . V_277 . V_278 )
V_202 -> V_30 . V_277 . V_279 = V_202 -> V_30 . V_277 . V_278 - 1 ;
strcpy ( V_202 -> V_30 . V_277 . V_154 , V_275 [ V_202 -> V_30 . V_277 . V_279 ] ) ;
return 0 ;
}
static int F_154 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 = F_19 ( V_27 ) ;
int V_79 = F_110 ( V_27 , & V_29 -> V_198 ) ;
unsigned int V_14 , V_283 ;
F_21 ( & V_2 -> V_34 ) ;
V_14 = F_15 ( F_3 ( V_2 , V_250 ) ) ;
V_283 = F_10 ( F_3 ( V_2 , V_251 ) ) ;
F_22 ( & V_2 -> V_34 ) ;
V_14 >>= ( ( V_79 % 2 ) * 8 ) + ( ( V_79 / 2 ) * 2 ) ;
V_14 &= 3 ;
V_283 >>= ( ( V_79 / 2 ) * 8 ) + ( ( V_79 % 2 ) * 4 ) ;
if ( V_14 == 1 && V_79 < 2 )
V_29 -> V_30 . V_277 . V_279 [ 0 ] = 11 ;
else if ( V_14 == 2 )
V_29 -> V_30 . V_277 . V_279 [ 0 ] = ( V_283 & 7 ) + 1 ;
else if ( V_14 == 3 )
V_29 -> V_30 . V_277 . V_279 [ 0 ] = ( ( V_283 >> 3 ) & 1 ) + 9 ;
else
V_29 -> V_30 . V_277 . V_279 [ 0 ] = 0 ;
return 0 ;
}
static int F_155 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 = F_19 ( V_27 ) ;
int V_200 , V_284 ;
int V_79 = F_110 ( V_27 , & V_29 -> V_198 ) ;
unsigned int V_14 , V_285 , V_33 ;
if ( V_29 -> V_30 . V_277 . V_279 [ 0 ] >= 11 )
V_33 = V_79 < 2 ? 1 : 0 ;
else if ( V_29 -> V_30 . V_277 . V_279 [ 0 ] >= 9 )
V_33 = 3 ;
else if ( V_29 -> V_30 . V_277 . V_279 [ 0 ] >= 1 )
V_33 = 2 ;
else
V_33 = 0 ;
V_284 = ( ( V_79 % 2 ) * 8 ) + ( ( V_79 / 2 ) * 2 ) ;
F_21 ( & V_2 -> V_34 ) ;
V_14 = V_285 = F_15 ( F_3 ( V_2 , V_250 ) ) ;
V_14 &= ~ ( 0x03 << V_284 ) ;
V_14 |= V_33 << V_284 ;
V_200 = V_14 != V_285 ;
if ( V_200 )
F_13 ( V_14 , F_3 ( V_2 , V_250 ) ) ;
F_22 ( & V_2 -> V_34 ) ;
if ( V_33 < 2 )
return V_200 ;
F_21 ( & V_2 -> V_34 ) ;
V_14 = V_285 = F_10 ( F_3 ( V_2 , V_251 ) ) ;
V_284 = ( ( V_79 / 2 ) * 8 ) + ( ( V_79 % 2 ) * 4 ) ;
if ( V_33 == 2 ) {
V_33 = V_29 -> V_30 . V_277 . V_279 [ 0 ] - 1 ;
V_14 &= ~ ( 0x07 << V_284 ) ;
V_14 |= V_33 << V_284 ;
} else {
V_33 = ( V_29 -> V_30 . V_277 . V_279 [ 0 ] - 9 ) << 3 ;
V_14 &= ~ ( 0x08 << V_284 ) ;
V_14 |= V_33 << V_284 ;
}
if ( V_14 != V_285 ) {
V_200 = 1 ;
F_8 ( V_14 , F_3 ( V_2 , V_251 ) ) ;
}
F_22 ( & V_2 -> V_34 ) ;
return V_200 ;
}
static int F_156 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 = F_19 ( V_27 ) ;
int V_79 = F_110 ( V_27 , & V_29 -> V_198 ) ;
unsigned int V_14 , V_283 ;
V_14 = F_15 ( F_3 ( V_2 , V_252 ) ) ;
V_283 = ( V_14 >> ( V_79 * 4 + 8 ) ) & 0x0f ;
V_14 = ( V_14 >> ( V_79 * 2 ) ) & 0x03 ;
if ( V_14 == 1 )
V_29 -> V_30 . V_277 . V_279 [ 0 ] = 11 ;
else if ( V_14 == 2 )
V_29 -> V_30 . V_277 . V_279 [ 0 ] = ( V_283 & 7 ) + 1 ;
else if ( V_14 == 3 )
V_29 -> V_30 . V_277 . V_279 [ 0 ] = ( ( V_283 >> 3 ) & 1 ) + 9 ;
else
V_29 -> V_30 . V_277 . V_279 [ 0 ] = 0 ;
return 0 ;
}
static int F_157 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 = F_19 ( V_27 ) ;
int V_200 , V_284 ;
int V_79 = F_110 ( V_27 , & V_29 -> V_198 ) ;
unsigned int V_14 , V_285 , V_33 ;
F_21 ( & V_2 -> V_34 ) ;
V_14 = V_285 = F_15 ( F_3 ( V_2 , V_252 ) ) ;
if ( V_29 -> V_30 . V_277 . V_279 [ 0 ] >= 11 )
V_33 = 1 ;
else if ( V_29 -> V_30 . V_277 . V_279 [ 0 ] >= 9 )
V_33 = 3 ;
else if ( V_29 -> V_30 . V_277 . V_279 [ 0 ] >= 1 )
V_33 = 2 ;
else
V_33 = 0 ;
V_284 = V_79 * 2 ;
V_14 &= ~ ( 0x03 << V_284 ) ;
V_14 |= V_33 << V_284 ;
V_284 = V_79 * 4 + 8 ;
if ( V_33 == 2 ) {
V_33 = V_29 -> V_30 . V_277 . V_279 [ 0 ] - 1 ;
V_14 &= ~ ( 0x07 << V_284 ) ;
V_14 |= V_33 << V_284 ;
} else if ( V_33 == 3 ) {
V_33 = ( V_29 -> V_30 . V_277 . V_279 [ 0 ] - 9 ) << 3 ;
V_14 &= ~ ( 0x08 << V_284 ) ;
V_14 |= V_33 << V_284 ;
}
V_200 = V_14 != V_285 ;
if ( V_200 )
F_13 ( V_14 , F_3 ( V_2 , V_252 ) ) ;
F_22 ( & V_2 -> V_34 ) ;
return V_200 ;
}
static int F_158 ( struct V_26 * V_27 ,
struct V_201 * V_202 )
{
V_202 -> type = V_203 ;
V_202 -> V_204 = 1 ;
V_202 -> V_30 . integer . V_205 = 0 ;
V_202 -> V_30 . integer . V_206 = 255 ;
return 0 ;
}
static int F_159 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 = F_19 ( V_27 ) ;
V_29 -> V_30 . integer . V_30 [ 0 ] = F_2 ( F_3 ( V_2 , V_286 ) ) ;
return 0 ;
}
static int F_160 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 = F_19 ( V_27 ) ;
int V_200 ;
F_21 ( & V_2 -> V_34 ) ;
V_200 = F_2 ( F_3 ( V_2 , V_286 ) ) != V_29 -> V_30 . integer . V_30 [ 0 ] ;
F_6 ( V_29 -> V_30 . integer . V_30 [ 0 ] , F_3 ( V_2 , V_286 ) ) ;
F_22 ( & V_2 -> V_34 ) ;
return V_200 ;
}
static int F_161 ( struct V_26 * V_27 ,
struct V_201 * V_202 )
{
V_202 -> type = V_203 ;
V_202 -> V_204 = 22 ;
V_202 -> V_30 . integer . V_205 = 0 ;
V_202 -> V_30 . integer . V_206 = 255 ;
return 0 ;
}
static int F_162 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 = F_19 ( V_27 ) ;
int V_79 ;
F_21 ( & V_2 -> V_34 ) ;
for ( V_79 = 0 ; V_79 < 22 ; V_79 ++ ) {
F_6 ( V_79 , F_3 ( V_2 , V_287 ) ) ;
V_29 -> V_30 . integer . V_30 [ V_79 ] = F_2 ( F_3 ( V_2 , V_288 ) ) ;
}
F_22 ( & V_2 -> V_34 ) ;
return 0 ;
}
static unsigned char F_163 ( struct V_1 * V_2 ,
unsigned char V_50 ,
unsigned char V_7 )
{
long V_289 = 0x10000 ;
F_6 ( V_7 , F_12 ( V_2 , V_290 ) ) ;
F_6 ( V_50 & ~ V_291 , F_12 ( V_2 , V_292 ) ) ;
while ( V_289 -- > 0 && ( F_2 ( F_12 ( V_2 , V_293 ) ) & V_294 ) ) ;
return F_2 ( F_12 ( V_2 , V_295 ) ) ;
}
static int F_164 ( struct V_1 * V_2 ,
const char * V_296 )
{
int V_50 = 0xa0 ;
unsigned int V_57 , V_236 ;
struct V_297 * const * V_298 , * V_299 ;
if ( ! V_296 || ! * V_296 ) {
V_2 -> V_226 . V_235 = 0 ;
if ( ( F_2 ( F_12 ( V_2 , V_293 ) ) & V_300 ) != 0 )
V_2 -> V_226 . V_235 = ( F_163 ( V_2 , V_50 , 0x00 ) << 0 ) |
( F_163 ( V_2 , V_50 , 0x01 ) << 8 ) |
( F_163 ( V_2 , V_50 , 0x02 ) << 16 ) |
( F_163 ( V_2 , V_50 , 0x03 ) << 24 ) ;
if ( V_2 -> V_226 . V_235 == 0 ||
V_2 -> V_226 . V_235 == ( unsigned int ) - 1 ) {
T_4 V_301 , V_145 ;
F_165 ( V_2 -> V_156 , V_302 , & V_301 ) ;
F_165 ( V_2 -> V_156 , V_303 , & V_145 ) ;
V_2 -> V_226 . V_235 = ( ( unsigned int ) F_166 ( V_301 ) << 16 ) | F_166 ( V_145 ) ;
if ( V_2 -> V_226 . V_235 == 0 || V_2 -> V_226 . V_235 == ( unsigned int ) - 1 ) {
F_43 ( V_2 -> V_49 -> V_50 ,
L_63 ) ;
return - V_304 ;
}
}
}
for ( V_298 = V_305 ; * V_298 ; V_298 ++ ) {
for ( V_299 = * V_298 ; V_299 -> V_235 ; V_299 ++ ) {
if ( V_296 && V_299 -> V_306 && ! strcmp ( V_296 , V_299 -> V_306 ) ) {
F_167 ( V_2 -> V_49 -> V_50 ,
L_64 , V_299 -> V_154 ) ;
V_2 -> V_226 . V_235 = V_299 -> V_235 ;
} else if ( V_299 -> V_235 != V_2 -> V_226 . V_235 )
continue;
if ( ! V_299 -> V_307 || ! V_299 -> V_308 )
goto V_309;
F_168 ( V_2 -> V_49 -> V_50 , L_65 ) ;
V_2 -> V_226 . V_237 = 1 ;
V_2 -> V_226 . V_236 = V_299 -> V_307 + 6 ;
memcpy ( V_2 -> V_226 . V_8 , V_299 -> V_308 , V_299 -> V_307 ) ;
goto V_310;
}
}
F_82 ( V_2 -> V_49 -> V_50 , L_66 ,
V_2 -> V_226 . V_235 ) ;
V_309:
V_2 -> V_226 . V_236 = F_163 ( V_2 , V_50 , 0x04 ) ;
if ( V_2 -> V_226 . V_236 < 6 )
V_2 -> V_226 . V_236 = 32 ;
else if ( V_2 -> V_226 . V_236 > 32 ) {
F_43 ( V_2 -> V_49 -> V_50 ,
L_67 , V_2 -> V_226 . V_236 ) ;
return - V_42 ;
}
V_2 -> V_226 . V_237 = F_163 ( V_2 , V_50 , 0x05 ) ;
if ( V_2 -> V_226 . V_237 != 1 ) {
F_43 ( V_2 -> V_49 -> V_50 , L_68 ,
V_2 -> V_226 . V_237 ) ;
}
V_236 = V_2 -> V_226 . V_236 - 6 ;
for ( V_57 = 0 ; V_57 < V_236 ; V_57 ++ )
V_2 -> V_226 . V_8 [ V_57 ] = F_163 ( V_2 , V_50 , V_57 + 6 ) ;
V_310:
V_2 -> V_226 . V_241 = V_2 -> V_226 . V_8 [ V_311 ] ;
V_2 -> V_226 . V_242 = V_2 -> V_226 . V_8 [ V_312 ] ;
V_2 -> V_226 . V_243 = V_2 -> V_226 . V_8 [ V_313 ] ;
return 0 ;
}
static int F_169 ( struct V_1 * V_2 )
{
F_6 ( V_314 | V_315 , F_12 ( V_2 , V_316 ) ) ;
F_170 ( 200 ) ;
F_6 ( V_315 , F_12 ( V_2 , V_316 ) ) ;
F_170 ( 200 ) ;
if ( V_2 -> V_226 . V_235 == V_317 &&
! V_2 -> V_318 )
V_2 -> V_226 . V_8 [ V_238 ] = 0x3a ;
F_171 ( V_2 -> V_156 , 0x60 , V_2 -> V_226 . V_8 [ V_238 ] ) ;
F_171 ( V_2 -> V_156 , 0x61 , V_2 -> V_226 . V_8 [ V_227 ] ) ;
F_171 ( V_2 -> V_156 , 0x62 , V_2 -> V_226 . V_8 [ V_239 ] ) ;
F_171 ( V_2 -> V_156 , 0x63 , V_2 -> V_226 . V_8 [ V_240 ] ) ;
if ( V_2 -> V_226 . V_235 != V_319 ) {
V_2 -> V_171 . V_320 = V_2 -> V_226 . V_241 ;
V_2 -> V_171 . V_321 = V_2 -> V_226 . V_243 ;
F_24 ( V_2 , V_36 ,
V_2 -> V_226 . V_241 ) ;
F_24 ( V_2 , V_35 ,
V_2 -> V_226 . V_243 ) ;
F_24 ( V_2 , V_37 ,
V_2 -> V_226 . V_242 ) ;
} else {
V_2 -> V_171 . V_320 = 0xc0 ;
V_2 -> V_171 . V_321 = 0xff ;
F_24 ( V_2 , V_36 , 0xc0 ) ;
F_24 ( V_2 , V_35 , 0xff ) ;
F_24 ( V_2 , V_37 ,
V_322 ) ;
}
F_24 ( V_2 , V_323 , 0 ) ;
if ( ! ( V_2 -> V_226 . V_8 [ V_238 ] & V_324 ) ) {
F_6 ( V_325 , F_12 ( V_2 , V_18 ) ) ;
F_170 ( 100 ) ;
F_6 ( 0 , F_12 ( V_2 , V_18 ) ) ;
F_170 ( 200 ) ;
F_24 ( V_2 , V_326 , 0 ) ;
}
F_87 ( V_2 , 48000 , 1 ) ;
F_6 ( ( ( V_2 -> V_226 . V_8 [ V_238 ] & V_327 ) == 0 ?
V_69 : 0 ) |
( ( V_2 -> V_226 . V_8 [ V_238 ] & V_324 ) ?
V_78 | V_83 | V_85 : 0 ) ,
F_12 ( V_2 , V_328 ) ) ;
F_6 ( 0x00 , F_3 ( V_2 , V_72 ) ) ;
return 0 ;
}
int F_172 ( struct V_1 * V_2 )
{
int V_46 ;
struct V_26 * V_329 ;
if ( F_173 ( ! V_2 -> V_190 ) )
return - V_42 ;
V_46 = F_116 ( V_2 -> V_49 , V_329 = F_117 ( & V_330 , V_2 ) ) ;
if ( V_46 < 0 )
return V_46 ;
V_329 -> V_198 . V_145 = V_2 -> V_190 -> V_145 ;
V_46 = F_116 ( V_2 -> V_49 , V_329 = F_117 ( & V_331 , V_2 ) ) ;
if ( V_46 < 0 )
return V_46 ;
V_329 -> V_198 . V_145 = V_2 -> V_190 -> V_145 ;
V_46 = F_116 ( V_2 -> V_49 , V_329 = F_117 ( & V_332 , V_2 ) ) ;
if ( V_46 < 0 )
return V_46 ;
V_329 -> V_198 . V_145 = V_2 -> V_190 -> V_145 ;
V_46 = F_116 ( V_2 -> V_49 , V_329 = F_117 ( & V_333 , V_2 ) ) ;
if ( V_46 < 0 )
return V_46 ;
V_329 -> V_198 . V_145 = V_2 -> V_190 -> V_145 ;
V_2 -> V_51 . V_334 = V_329 ;
return 0 ;
}
static int F_174 ( struct V_1 * V_2 )
{
int V_46 ;
V_46 = F_116 ( V_2 -> V_49 , F_117 ( & V_254 , V_2 ) ) ;
if ( V_46 < 0 )
return V_46 ;
V_46 = F_116 ( V_2 -> V_49 , F_117 ( & V_335 , V_2 ) ) ;
if ( V_46 < 0 )
return V_46 ;
V_46 = F_116 ( V_2 -> V_49 , F_117 ( & V_336 , V_2 ) ) ;
if ( V_46 < 0 )
return V_46 ;
V_46 = F_116 ( V_2 -> V_49 , F_117 ( & V_337 , V_2 ) ) ;
if ( V_46 < 0 )
return V_46 ;
V_46 = F_116 ( V_2 -> V_49 , F_117 ( & V_338 , V_2 ) ) ;
if ( V_46 < 0 )
return V_46 ;
if ( V_2 -> V_339 > 0 ) {
struct V_210 V_91 = V_340 ;
V_91 . V_204 = V_2 -> V_339 ;
V_46 = F_116 ( V_2 -> V_49 , F_117 ( & V_91 , V_2 ) ) ;
if ( V_46 < 0 )
return V_46 ;
}
V_46 = F_116 ( V_2 -> V_49 , F_117 ( & V_341 , V_2 ) ) ;
if ( V_46 < 0 )
return V_46 ;
V_46 = F_116 ( V_2 -> V_49 , F_117 ( & V_342 , V_2 ) ) ;
if ( V_46 < 0 )
return V_46 ;
V_46 = F_116 ( V_2 -> V_49 , F_117 ( & V_343 , V_2 ) ) ;
if ( V_46 < 0 )
return V_46 ;
return 0 ;
}
static int F_175 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_344 )
goto V_345;
F_6 ( V_346 | V_347 , F_3 ( V_2 , V_72 ) ) ;
F_6 ( 0xff , F_12 ( V_2 , V_328 ) ) ;
V_345:
if ( V_2 -> V_61 >= 0 )
F_176 ( V_2 -> V_61 , V_2 ) ;
if ( V_2 -> V_344 )
F_177 ( V_2 -> V_156 ) ;
F_178 ( V_2 ) ;
F_179 ( V_2 -> V_156 ) ;
F_180 ( V_2 -> V_348 ) ;
F_180 ( V_2 ) ;
return 0 ;
}
static int F_181 ( struct V_349 * V_145 )
{
struct V_1 * V_2 = V_145 -> V_350 ;
return F_175 ( V_2 ) ;
}
static int F_182 ( struct V_207 * V_49 ,
struct V_351 * V_156 ,
const char * V_296 ,
int V_352 ,
int V_47 ,
int V_318 ,
struct V_1 * * V_353 )
{
struct V_1 * V_2 ;
int V_46 ;
static struct V_354 V_52 = {
. V_355 = F_181 ,
} ;
* V_353 = NULL ;
V_46 = F_183 ( V_156 ) ;
if ( V_46 < 0 )
return V_46 ;
if ( F_184 ( V_156 , F_185 ( 28 ) ) < 0 ||
F_186 ( V_156 , F_185 ( 28 ) ) < 0 ) {
F_43 ( V_49 -> V_50 ,
L_69 ) ;
F_179 ( V_156 ) ;
return - V_304 ;
}
V_2 = F_187 ( sizeof( * V_2 ) , V_356 ) ;
if ( V_2 == NULL ) {
F_179 ( V_156 ) ;
return - V_357 ;
}
V_2 -> V_352 = V_352 ? 1 : 0 ;
if ( V_47 < 1 )
V_47 = 1 ;
else if ( V_47 > 1000 )
V_47 = 1000 ;
V_2 -> V_47 = V_47 ;
V_2 -> V_318 = V_318 ;
F_188 ( & V_2 -> V_34 ) ;
F_189 ( & V_2 -> V_358 ) ;
F_189 ( & V_2 -> V_359 ) ;
F_189 ( & V_2 -> V_360 ) ;
V_2 -> V_171 . V_361 = F_28 ;
V_2 -> V_171 . V_362 = F_27 ;
V_2 -> V_171 . V_363 = F_23 ;
V_2 -> V_171 . V_364 = F_25 ;
V_2 -> V_171 . V_365 = F_30 ;
V_2 -> V_171 . V_366 = F_29 ;
V_2 -> V_51 . V_367 =
V_2 -> V_51 . V_368 = ( 0x01 |
0x10 |
0x20 ) ;
V_2 -> V_49 = V_49 ;
V_2 -> V_156 = V_156 ;
V_2 -> V_61 = - 1 ;
F_190 ( V_156 ) ;
F_191 ( V_2 -> V_156 , 0x40 , 0x807f ) ;
F_191 ( V_2 -> V_156 , 0x42 , 0x0006 ) ;
F_125 ( V_2 ) ;
F_192 ( V_156 -> V_61 ) ;
V_49 -> V_15 = V_2 ;
V_46 = F_193 ( V_156 , L_70 ) ;
if ( V_46 < 0 ) {
F_180 ( V_2 ) ;
F_179 ( V_156 ) ;
return V_46 ;
}
V_2 -> V_344 = F_194 ( V_156 , 0 ) ;
V_2 -> V_107 = F_194 ( V_156 , 1 ) ;
V_2 -> V_369 = F_194 ( V_156 , 2 ) ;
V_2 -> V_370 = F_194 ( V_156 , 3 ) ;
if ( F_195 ( V_156 -> V_61 , F_45 , V_371 ,
V_372 , V_2 ) ) {
F_43 ( V_49 -> V_50 , L_71 , V_156 -> V_61 ) ;
F_175 ( V_2 ) ;
return - V_42 ;
}
V_2 -> V_61 = V_156 -> V_61 ;
if ( F_164 ( V_2 , V_296 ) < 0 ) {
F_175 ( V_2 ) ;
return - V_42 ;
}
if ( F_169 ( V_2 ) < 0 ) {
F_175 ( V_2 ) ;
return - V_42 ;
}
V_46 = F_196 ( V_49 , V_373 , V_2 , & V_52 ) ;
if ( V_46 < 0 ) {
F_175 ( V_2 ) ;
return V_46 ;
}
* V_353 = V_2 ;
return 0 ;
}
static int F_197 ( struct V_351 * V_156 ,
const struct V_374 * V_375 )
{
static int V_50 ;
struct V_207 * V_49 ;
struct V_1 * V_2 ;
int V_376 = 0 , V_46 ;
struct V_297 * const * V_298 , * V_299 ;
if ( V_50 >= V_377 )
return - V_378 ;
if ( ! V_379 [ V_50 ] ) {
V_50 ++ ;
return - V_380 ;
}
V_46 = F_198 ( & V_156 -> V_50 , V_192 [ V_50 ] , V_198 [ V_50 ] , V_381 ,
0 , & V_49 ) ;
if ( V_46 < 0 )
return V_46 ;
strcpy ( V_49 -> V_382 , L_70 ) ;
strcpy ( V_49 -> V_383 , L_72 ) ;
V_46 = F_182 ( V_49 , V_156 , V_306 [ V_50 ] , V_352 [ V_50 ] ,
V_47 [ V_50 ] , V_318 [ V_50 ] , & V_2 ) ;
if ( V_46 < 0 ) {
F_199 ( V_49 ) ;
return V_46 ;
}
for ( V_298 = V_305 ; * V_298 ; V_298 ++ ) {
for ( V_299 = * V_298 ; V_299 -> V_235 ; V_299 ++ ) {
if ( V_299 -> V_235 == V_2 -> V_226 . V_235 ) {
V_2 -> V_384 = V_299 ;
strcpy ( V_49 -> V_383 , V_299 -> V_154 ) ;
if ( V_299 -> V_382 )
strcpy ( V_49 -> V_382 , V_299 -> V_382 ) ;
if ( V_299 -> V_385 ) {
V_46 = V_299 -> V_385 ( V_2 ) ;
if ( V_46 < 0 ) {
F_199 ( V_49 ) ;
return V_46 ;
}
}
goto V_386;
}
}
}
V_299 = & V_387 ;
V_386:
V_46 = F_105 ( V_2 , V_376 ++ , NULL ) ;
if ( V_46 < 0 ) {
F_199 ( V_49 ) ;
return V_46 ;
}
if ( F_120 ( V_2 ) ) {
V_46 = F_77 ( V_2 , V_376 ++ , NULL ) ;
if ( V_46 < 0 ) {
F_199 ( V_49 ) ;
return V_46 ;
}
}
V_46 = F_119 ( V_2 ) ;
if ( V_46 < 0 ) {
F_199 ( V_49 ) ;
return V_46 ;
}
V_46 = F_174 ( V_2 ) ;
if ( V_46 < 0 ) {
F_199 ( V_49 ) ;
return V_46 ;
}
if ( V_299 -> V_388 ) {
V_46 = V_299 -> V_388 ( V_2 ) ;
if ( V_46 < 0 ) {
F_199 ( V_49 ) ;
return V_46 ;
}
}
if ( F_120 ( V_2 ) ) {
V_46 = F_83 ( V_2 , V_376 ++ , NULL ) ;
if ( V_46 < 0 ) {
F_199 ( V_49 ) ;
return V_46 ;
}
}
if ( ! V_299 -> V_389 ) {
V_46 = F_200 ( V_49 , 0 , V_390 ,
F_12 ( V_2 , V_391 ) ,
V_299 -> V_392 |
V_393 | V_394 ,
- 1 , & V_2 -> V_67 [ 0 ] ) ;
if ( V_46 < 0 ) {
F_199 ( V_49 ) ;
return V_46 ;
}
if ( V_299 -> V_395 )
snprintf ( V_2 -> V_67 [ 0 ] -> V_154 ,
sizeof( V_2 -> V_67 [ 0 ] -> V_154 ) ,
L_73 , V_299 -> V_395 , V_49 -> V_98 ) ;
if ( V_2 -> V_226 . V_8 [ V_238 ] & V_327 ) {
V_46 = F_200 ( V_49 , 1 , V_390 ,
F_12 ( V_2 , V_396 ) ,
V_299 -> V_397 |
V_393 | V_394 ,
- 1 , & V_2 -> V_67 [ 1 ] ) ;
if ( V_46 < 0 ) {
F_199 ( V_49 ) ;
return V_46 ;
}
if ( V_299 -> V_398 )
snprintf ( V_2 -> V_67 [ 1 ] -> V_154 ,
sizeof( V_2 -> V_67 [ 1 ] -> V_154 ) ,
L_73 , V_299 -> V_398 ,
V_49 -> V_98 ) ;
}
}
F_44 ( V_2 , 0 ) ;
sprintf ( V_49 -> V_234 , L_74 ,
V_49 -> V_383 , V_2 -> V_344 , V_2 -> V_61 ) ;
V_46 = F_201 ( V_49 ) ;
if ( V_46 < 0 ) {
F_199 ( V_49 ) ;
return V_46 ;
}
F_202 ( V_156 , V_49 ) ;
V_50 ++ ;
return 0 ;
}
static void F_203 ( struct V_351 * V_156 )
{
struct V_207 * V_49 = F_204 ( V_156 ) ;
struct V_1 * V_2 = V_49 -> V_15 ;
if ( V_2 -> V_384 && V_2 -> V_384 -> V_399 )
V_2 -> V_384 -> V_399 ( V_2 ) ;
F_199 ( V_49 ) ;
}
static int F_205 ( struct V_145 * V_50 )
{
struct V_351 * V_156 = F_206 ( V_50 ) ;
struct V_207 * V_49 = F_207 ( V_50 ) ;
struct V_1 * V_2 = V_49 -> V_15 ;
if ( ! V_2 -> V_400 )
return 0 ;
F_208 ( V_49 , V_401 ) ;
F_209 ( V_2 -> V_148 ) ;
F_209 ( V_2 -> V_190 ) ;
F_209 ( V_2 -> V_158 ) ;
F_210 ( V_2 -> V_12 ) ;
F_21 ( & V_2 -> V_34 ) ;
V_2 -> V_402 = F_1 ( V_2 ) ;
V_2 -> V_403 = F_15 ( F_3 ( V_2 , V_252 ) ) ;
V_2 -> V_404 = F_15 ( F_3 ( V_2 , V_250 ) ) ;
F_22 ( & V_2 -> V_34 ) ;
if ( V_2 -> V_405 )
V_2 -> V_405 ( V_2 ) ;
F_179 ( V_156 ) ;
F_211 ( V_156 ) ;
F_212 ( V_156 , V_406 ) ;
return 0 ;
}
static int F_213 ( struct V_145 * V_50 )
{
struct V_351 * V_156 = F_206 ( V_50 ) ;
struct V_207 * V_49 = F_207 ( V_50 ) ;
struct V_1 * V_2 = V_49 -> V_15 ;
int V_45 ;
if ( ! V_2 -> V_400 )
return 0 ;
F_212 ( V_156 , V_407 ) ;
F_214 ( V_156 ) ;
if ( F_183 ( V_156 ) < 0 ) {
F_215 ( V_49 ) ;
return - V_42 ;
}
F_190 ( V_156 ) ;
if ( V_2 -> V_170 )
V_45 = V_2 -> V_170 ;
else
V_45 = V_184 ;
if ( F_169 ( V_2 ) < 0 ) {
F_215 ( V_49 ) ;
return - V_42 ;
}
V_2 -> V_170 = V_45 ;
if ( V_2 -> V_408 )
V_2 -> V_408 ( V_2 ) ;
if ( V_2 -> V_402 ) {
F_21 ( & V_2 -> V_34 ) ;
F_6 ( F_2 ( F_3 ( V_2 , V_3 ) ) | V_4 ,
F_3 ( V_2 , V_3 ) ) ;
F_22 ( & V_2 -> V_34 ) ;
F_44 ( V_2 , 1 ) ;
} else {
F_87 ( V_2 , V_45 , 1 ) ;
F_44 ( V_2 , 0 ) ;
}
F_13 ( V_2 -> V_403 , F_3 ( V_2 , V_252 ) ) ;
F_13 ( V_2 -> V_404 , F_3 ( V_2 , V_250 ) ) ;
if ( V_2 -> V_12 )
F_216 ( V_2 -> V_12 ) ;
F_208 ( V_49 , V_409 ) ;
return 0 ;
}
