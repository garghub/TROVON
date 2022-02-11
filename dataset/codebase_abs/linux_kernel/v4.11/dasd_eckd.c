static int
F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 , V_4 |
V_5 | V_6 ) ;
if ( V_3 ) {
F_3 ( V_7 , V_2 , L_1 ,
L_2
L_3 ) ;
return V_3 ;
}
V_3 = F_4 ( V_2 , & V_8 ) ;
return V_3 ;
}
static int
F_5 ( struct V_1 * V_2 )
{
return F_6 ( V_2 , & V_8 ) ;
}
static inline unsigned int
F_7 ( unsigned int V_9 , unsigned int V_10 )
{
int V_11 = V_9 % V_10 ;
return ( V_11 ? V_9 - V_11 + V_10 : V_9 ) ;
}
static inline unsigned int
F_8 ( unsigned int V_12 , unsigned int V_13 )
{
return ( V_12 + ( V_13 - 1 ) ) / V_13 ;
}
static unsigned int
F_9 ( struct V_14 * V_15 ,
unsigned int V_16 , unsigned int V_17 )
{
int V_18 , V_19 ;
switch ( V_15 -> V_20 ) {
case 0x3380 :
if ( V_16 )
return 1499 / ( 15 + 7 + F_8 ( V_16 + 12 , 32 ) +
F_8 ( V_17 + 12 , 32 ) ) ;
else
return 1499 / ( 15 + F_8 ( V_17 + 12 , 32 ) ) ;
case 0x3390 :
V_18 = F_8 ( V_17 + 6 , 232 ) + 1 ;
if ( V_16 ) {
V_19 = F_8 ( V_16 + 6 , 232 ) + 1 ;
return 1729 / ( 10 + 9 + F_8 ( V_16 + 6 * V_19 , 34 ) +
9 + F_8 ( V_17 + 6 * V_18 , 34 ) ) ;
} else
return 1729 / ( 10 + 9 + F_8 ( V_17 + 6 * V_18 , 34 ) ) ;
case 0x9345 :
V_18 = F_8 ( V_17 + 6 , 232 ) + 1 ;
if ( V_16 ) {
V_19 = F_8 ( V_16 + 6 , 232 ) + 1 ;
return 1420 / ( 18 + 7 + F_8 ( V_16 + 6 * V_19 , 34 ) +
F_8 ( V_17 + 6 * V_18 , 34 ) ) ;
} else
return 1420 / ( 18 + 7 + F_8 ( V_17 + 6 * V_18 , 34 ) ) ;
}
return 0 ;
}
static void F_10 ( struct V_21 * V_22 , T_1 V_23 , T_2 V_24 )
{
V_22 -> V_23 = ( V_25 ) V_23 ;
V_22 -> V_24 = V_23 >> 16 ;
V_22 -> V_24 <<= 4 ;
V_22 -> V_24 |= V_24 ;
}
static int
F_11 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
int V_34 ;
if ( ! V_33 -> V_35 . V_36 . V_37 )
return 0 ;
V_29 -> V_38 |= 0x08 ;
V_29 -> V_38 |= 0x02 ;
V_34 = F_12 ( & V_29 -> V_39 ) ;
if ( V_34 == - V_40 || V_34 == - V_41 )
V_34 = 0 ;
V_27 -> V_42 = sizeof( struct V_28 ) ;
V_27 -> V_43 |= V_44 ;
return V_34 ;
}
static int
F_13 ( struct V_26 * V_45 , struct V_28 * V_29 , unsigned int V_46 ,
unsigned int V_47 , int V_48 , struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
T_3 V_49 , V_50 ;
T_4 V_51 , V_52 , V_53 ;
int V_34 = 0 ;
V_45 -> V_54 = V_55 ;
V_45 -> V_43 = 0 ;
V_45 -> V_42 = 16 ;
V_45 -> V_56 = ( T_1 ) F_14 ( V_29 ) ;
memset ( V_29 , 0 , sizeof( struct V_28 ) ) ;
switch ( V_48 ) {
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
V_29 -> V_65 . V_66 = 0x1 ;
V_29 -> V_67 . V_68 = V_33 -> V_69 . V_68 ;
break;
case V_70 :
V_29 -> V_65 . V_66 = 0x1 ;
V_29 -> V_67 . V_68 = V_71 ;
break;
case V_72 :
case V_73 :
case V_74 :
case V_75 :
V_29 -> V_65 . V_66 = 0x02 ;
V_29 -> V_67 . V_68 = V_33 -> V_69 . V_68 ;
V_34 = F_11 ( V_45 , V_29 , V_31 ) ;
break;
case V_76 :
case V_77 :
V_29 -> V_67 . V_68 = V_71 ;
V_34 = F_11 ( V_45 , V_29 , V_31 ) ;
break;
case V_78 :
case V_79 :
case V_80 :
V_29 -> V_65 . V_66 = 0x3 ;
V_29 -> V_65 . V_81 = 0x1 ;
V_29 -> V_67 . V_68 = V_71 ;
V_34 = F_11 ( V_45 , V_29 , V_31 ) ;
break;
default:
F_15 ( & V_31 -> V_2 -> V_82 ,
L_4 , V_48 ) ;
break;
}
V_29 -> V_67 . V_83 = 0x3 ;
if ( ( V_33 -> V_35 . V_84 == 0x2105 ||
V_33 -> V_35 . V_84 == 0x2107 ||
V_33 -> V_35 . V_84 == 0x1750 )
&& ! ( V_33 -> V_85 && V_46 < 2 ) )
V_29 -> V_38 |= 0x40 ;
V_51 = V_33 -> V_35 . V_86 ;
V_49 = V_46 / V_51 ;
V_52 = V_46 % V_51 ;
V_50 = V_47 / V_51 ;
V_53 = V_47 % V_51 ;
if ( V_29 -> V_67 . V_68 == V_87 ||
V_29 -> V_67 . V_68 == V_88 ) {
if ( V_50 + V_33 -> V_69 . V_89 < V_33 -> V_90 )
V_50 += V_33 -> V_69 . V_89 ;
else
V_50 = ( V_33 -> V_90 - 1 ) ;
}
F_10 ( & V_29 -> V_91 , V_49 , V_52 ) ;
F_10 ( & V_29 -> V_92 , V_50 , V_53 ) ;
return V_34 ;
}
static int F_16 ( struct V_93 * V_94 ,
struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
int V_34 ;
if ( ! V_33 -> V_35 . V_36 . V_37 )
return 0 ;
V_94 -> F_13 . V_38 |= 0x08 ;
V_94 -> F_13 . V_38 |= 0x02 ;
V_94 -> V_95 . V_96 = 1 ;
V_34 = F_12 ( & V_94 -> F_13 . V_39 ) ;
if ( V_34 == - V_40 || V_34 == - V_41 )
V_34 = 0 ;
return V_34 ;
}
static void F_17 ( struct V_97 * V_29 , unsigned int V_46 ,
unsigned int V_98 , int V_42 , int V_48 ,
struct V_30 * V_31 , unsigned int V_99 ,
unsigned int V_100 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
int V_101 ;
int V_18 , V_102 ;
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_101 = 0 ;
if ( V_98 ) {
switch ( V_33 -> V_35 . V_20 ) {
case 0x3390 :
V_18 = F_8 ( V_99 + 6 , 232 ) ;
V_102 = 9 + F_8 ( V_99 + 6 * ( V_18 + 1 ) , 34 ) ;
V_101 = ( 49 + ( V_98 - 1 ) * ( 10 + V_102 ) ) / 8 ;
break;
case 0x3380 :
V_102 = 7 + F_8 ( V_99 + 12 , 32 ) ;
V_101 = ( 39 + ( V_98 - 1 ) * ( 8 + V_102 ) ) / 7 ;
break;
}
}
V_29 -> V_101 = V_101 ;
V_29 -> V_42 = V_42 ;
switch ( V_48 ) {
case V_79 :
V_29 -> V_68 . V_103 = 0x3 ;
V_29 -> V_68 . V_68 = 0x03 ;
break;
case V_57 :
V_29 -> V_68 . V_103 = 0x3 ;
V_29 -> V_68 . V_68 = 0x16 ;
break;
case V_80 :
V_29 -> V_68 . V_103 = 0x1 ;
V_29 -> V_68 . V_68 = 0x03 ;
V_29 -> V_42 ++ ;
break;
case V_58 :
V_29 -> V_68 . V_103 = 0x3 ;
V_29 -> V_68 . V_68 = 0x16 ;
V_29 -> V_42 ++ ;
break;
case V_72 :
case V_73 :
case V_74 :
case V_75 :
V_29 -> V_104 . V_105 = 0x1 ;
V_29 -> V_106 = V_99 ;
V_29 -> V_68 . V_68 = 0x01 ;
break;
case V_76 :
case V_77 :
V_29 -> V_104 . V_105 = 0x1 ;
V_29 -> V_106 = V_99 ;
V_29 -> V_68 . V_68 = 0x03 ;
break;
case V_107 :
V_29 -> V_68 . V_103 = 0x0 ;
V_29 -> V_68 . V_68 = 0x3F ;
V_29 -> V_108 = 0x11 ;
V_29 -> V_106 = 0 ;
V_29 -> V_109 = 0x02 ;
if ( V_29 -> V_42 > 8 ) {
V_29 -> V_110 [ 0 ] = 0xFF ;
V_29 -> V_110 [ 1 ] = 0xFF ;
V_29 -> V_110 [ 1 ] <<= ( 16 - V_42 ) ;
} else {
V_29 -> V_110 [ 0 ] = 0xFF ;
V_29 -> V_110 [ 0 ] <<= ( 8 - V_42 ) ;
V_29 -> V_110 [ 1 ] = 0x00 ;
}
V_29 -> V_101 = 0xFF ;
break;
case V_111 :
V_29 -> V_104 . V_105 = 0x1 ;
V_29 -> V_106 = V_99 ;
V_29 -> V_68 . V_68 = 0x3F ;
V_29 -> V_108 = 0x23 ;
break;
case V_59 :
case V_60 :
case V_63 :
case V_64 :
V_29 -> V_104 . V_105 = 0x1 ;
V_29 -> V_106 = V_99 ;
V_29 -> V_68 . V_68 = 0x06 ;
break;
case V_61 :
case V_62 :
V_29 -> V_104 . V_105 = 0x1 ;
V_29 -> V_106 = V_99 ;
V_29 -> V_68 . V_68 = 0x16 ;
break;
case V_70 :
V_29 -> V_68 . V_68 = 0x06 ;
break;
case V_112 :
V_29 -> V_68 . V_103 = 0x1 ;
V_29 -> V_68 . V_68 = 0x0C ;
V_29 -> V_109 = 0 ;
V_29 -> V_101 = 0xFF ;
break;
case V_113 :
V_29 -> V_104 . V_105 = 0x1 ;
V_29 -> V_106 = V_100 ;
V_29 -> V_68 . V_68 = 0x0C ;
break;
case V_78 :
V_29 -> V_106 = V_99 ;
V_29 -> V_104 . V_105 = 0x1 ;
V_29 -> V_68 . V_68 = 0x0b ;
break;
default:
F_18 ( V_114 , V_31 ,
L_5 , V_48 ) ;
F_19 () ;
}
F_10 ( & V_29 -> V_115 ,
V_46 / V_33 -> V_35 . V_86 ,
V_46 % V_33 -> V_35 . V_86 ) ;
V_29 -> V_116 . V_23 = V_29 -> V_115 . V_23 ;
V_29 -> V_116 . V_24 = V_29 -> V_115 . V_24 ;
V_29 -> V_116 . V_117 = V_98 ;
}
static int F_20 ( struct V_26 * V_45 , struct V_93 * V_94 ,
unsigned int V_46 , unsigned int V_47 , int V_48 ,
struct V_30 * V_118 , struct V_30 * V_119 ,
unsigned char V_120 , unsigned int V_98 , int V_42 ,
unsigned int V_121 , unsigned int V_100 )
{
struct V_32 * V_122 , * V_123 ;
struct V_28 * V_124 ;
struct V_97 * V_125 ;
T_3 V_49 , V_50 ;
T_4 V_51 , V_52 , V_53 ;
int V_34 = 0 ;
V_122 = V_118 -> V_33 ;
V_123 = V_119 -> V_33 ;
V_124 = & V_94 -> F_13 ;
V_125 = & V_94 -> V_126 ;
V_45 -> V_54 = V_127 ;
V_45 -> V_43 = 0 ;
if ( V_48 == V_107 ) {
V_45 -> V_42 = sizeof( * V_94 ) + 2 ;
V_45 -> V_56 = ( T_1 ) F_14 ( V_94 ) ;
memset ( V_94 , 0 , sizeof( * V_94 ) + 2 ) ;
} else {
V_45 -> V_42 = sizeof( * V_94 ) ;
V_45 -> V_56 = ( T_1 ) F_14 ( V_94 ) ;
memset ( V_94 , 0 , sizeof( * V_94 ) ) ;
}
if ( V_120 > 1 ) {
F_18 ( V_114 , V_118 ,
L_6 , V_120 ) ;
F_19 () ;
return - V_128 ;
}
V_94 -> V_120 = V_120 ;
V_94 -> V_129 = V_122 -> V_130 -> V_131 ;
V_94 -> V_132 = V_122 -> V_130 -> V_133 ;
V_94 -> V_95 . F_13 = 1 ;
if ( V_123 -> V_134 . type != V_135 ) {
V_94 -> V_95 . V_136 = 1 ;
if ( V_123 -> V_134 . type == V_137 )
V_94 -> V_95 . V_138 = 1 ;
}
switch ( V_48 ) {
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
V_124 -> V_65 . V_66 = 0x1 ;
V_124 -> V_67 . V_68 = V_122 -> V_69 . V_68 ;
break;
case V_70 :
V_124 -> V_65 . V_66 = 0x1 ;
V_124 -> V_67 . V_68 = V_71 ;
break;
case V_112 :
case V_113 :
V_124 -> V_65 . V_66 = 0x1 ;
V_124 -> V_67 . V_68 = V_122 -> V_69 . V_68 ;
V_124 -> V_139 = 0 ;
break;
case V_72 :
case V_73 :
case V_74 :
case V_75 :
V_124 -> V_65 . V_66 = 0x02 ;
V_124 -> V_67 . V_68 = V_122 -> V_69 . V_68 ;
V_34 = F_16 ( V_94 , V_118 ) ;
break;
case V_76 :
case V_77 :
V_124 -> V_67 . V_68 = V_71 ;
V_34 = F_16 ( V_94 , V_118 ) ;
break;
case V_78 :
case V_79 :
case V_80 :
V_124 -> V_65 . V_66 = 0x3 ;
V_124 -> V_65 . V_81 = 0x1 ;
V_124 -> V_67 . V_68 = V_71 ;
V_34 = F_16 ( V_94 , V_118 ) ;
break;
case V_107 :
V_124 -> V_65 . V_66 = 0x03 ;
V_124 -> V_67 . V_68 = V_122 -> V_69 . V_68 ;
V_124 -> V_139 = 0 ;
break;
case V_111 :
V_124 -> V_65 . V_66 = 0x02 ;
V_124 -> V_67 . V_68 = V_122 -> V_69 . V_68 ;
V_124 -> V_139 = V_121 ;
V_34 = F_16 ( V_94 , V_118 ) ;
break;
default:
F_18 ( V_114 , V_118 ,
L_7 , V_48 ) ;
F_19 () ;
return - V_128 ;
}
V_124 -> V_67 . V_83 = 0x3 ;
if ( ( V_122 -> V_35 . V_84 == 0x2105 ||
V_122 -> V_35 . V_84 == 0x2107 ||
V_122 -> V_35 . V_84 == 0x1750 )
&& ! ( V_122 -> V_85 && V_46 < 2 ) )
V_124 -> V_38 |= 0x40 ;
V_51 = V_122 -> V_35 . V_86 ;
V_49 = V_46 / V_51 ;
V_52 = V_46 % V_51 ;
V_50 = V_47 / V_51 ;
V_53 = V_47 % V_51 ;
if ( V_124 -> V_67 . V_68 == V_87 ||
V_124 -> V_67 . V_68 == V_88 ) {
if ( V_50 + V_122 -> V_69 . V_89 < V_122 -> V_90 )
V_50 += V_122 -> V_69 . V_89 ;
else
V_50 = ( V_122 -> V_90 - 1 ) ;
}
F_10 ( & V_124 -> V_91 , V_49 , V_52 ) ;
F_10 ( & V_124 -> V_92 , V_50 , V_53 ) ;
if ( V_120 == 1 ) {
F_17 ( V_125 , V_46 , V_98 , V_42 , V_48 ,
V_118 , V_121 , V_100 ) ;
}
return V_34 ;
}
static int F_21 ( struct V_26 * V_45 , struct V_93 * V_94 ,
unsigned int V_46 , unsigned int V_47 , int V_48 ,
struct V_30 * V_118 , struct V_30 * V_119 )
{
return F_20 ( V_45 , V_94 , V_46 , V_47 , V_48 , V_118 , V_119 ,
0 , 0 , 0 , 0 , 0 ) ;
}
static void
V_126 ( struct V_26 * V_45 , struct V_140 * V_29 , unsigned int V_46 ,
unsigned int V_98 , int V_141 , int V_48 ,
struct V_30 * V_31 , int V_99 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
int V_101 ;
int V_18 , V_102 ;
F_18 ( V_142 , V_31 ,
L_8 ,
V_46 , V_98 , V_141 , V_48 , V_99 ) ;
V_45 -> V_54 = V_143 ;
V_45 -> V_43 = 0 ;
V_45 -> V_42 = 16 ;
V_45 -> V_56 = ( T_1 ) F_14 ( V_29 ) ;
memset ( V_29 , 0 , sizeof( struct V_140 ) ) ;
V_101 = 0 ;
if ( V_98 ) {
switch ( V_33 -> V_35 . V_20 ) {
case 0x3390 :
V_18 = F_8 ( V_99 + 6 , 232 ) ;
V_102 = 9 + F_8 ( V_99 + 6 * ( V_18 + 1 ) , 34 ) ;
V_101 = ( 49 + ( V_98 - 1 ) * ( 10 + V_102 ) ) / 8 ;
break;
case 0x3380 :
V_102 = 7 + F_8 ( V_99 + 12 , 32 ) ;
V_101 = ( 39 + ( V_98 - 1 ) * ( 8 + V_102 ) ) / 7 ;
break;
}
}
V_29 -> V_101 = V_101 ;
V_29 -> V_42 = V_141 ;
switch ( V_48 ) {
case V_79 :
V_29 -> V_68 . V_103 = 0x3 ;
V_29 -> V_68 . V_68 = 0x03 ;
break;
case V_57 :
V_29 -> V_68 . V_103 = 0x3 ;
V_29 -> V_68 . V_68 = 0x16 ;
break;
case V_80 :
V_29 -> V_68 . V_103 = 0x1 ;
V_29 -> V_68 . V_68 = 0x03 ;
V_29 -> V_42 ++ ;
break;
case V_58 :
V_29 -> V_68 . V_103 = 0x3 ;
V_29 -> V_68 . V_68 = 0x16 ;
V_29 -> V_42 ++ ;
break;
case V_72 :
case V_73 :
case V_74 :
case V_75 :
V_29 -> V_104 . V_144 = 0x1 ;
V_29 -> V_106 = V_99 ;
V_29 -> V_68 . V_68 = 0x01 ;
break;
case V_76 :
case V_77 :
V_29 -> V_104 . V_144 = 0x1 ;
V_29 -> V_106 = V_99 ;
V_29 -> V_68 . V_68 = 0x03 ;
break;
case V_59 :
case V_60 :
case V_63 :
case V_64 :
V_29 -> V_104 . V_144 = 0x1 ;
V_29 -> V_106 = V_99 ;
V_29 -> V_68 . V_68 = 0x06 ;
break;
case V_61 :
case V_62 :
V_29 -> V_104 . V_144 = 0x1 ;
V_29 -> V_106 = V_99 ;
V_29 -> V_68 . V_68 = 0x16 ;
break;
case V_70 :
V_29 -> V_68 . V_68 = 0x06 ;
break;
case V_78 :
V_29 -> V_106 = V_99 ;
V_29 -> V_104 . V_144 = 0x1 ;
V_29 -> V_68 . V_68 = 0x0b ;
break;
default:
F_18 ( V_114 , V_31 , L_9
L_10 , V_48 ) ;
}
F_10 ( & V_29 -> V_115 ,
V_46 / V_33 -> V_35 . V_86 ,
V_46 % V_33 -> V_35 . V_86 ) ;
V_29 -> V_116 . V_23 = V_29 -> V_115 . V_23 ;
V_29 -> V_116 . V_24 = V_29 -> V_115 . V_24 ;
V_29 -> V_116 . V_117 = V_98 ;
}
static inline int
F_22 ( int V_145 , int V_146 )
{
if ( V_146 < 3 )
return 1 ;
if ( V_146 < V_145 )
return 0 ;
if ( V_146 < 2 * V_145 )
return 1 ;
return 0 ;
}
static inline int
F_23 ( int V_146 )
{
if ( V_146 < 3 )
return V_147 [ V_146 ] ;
return V_148 ;
}
static void F_24 ( struct V_32 * V_33 )
{
int V_42 ;
struct V_149 * V_134 ;
V_134 = & V_33 -> V_134 ;
memset ( V_134 , 0 , sizeof( struct V_149 ) ) ;
memcpy ( V_134 -> V_150 , V_33 -> V_130 -> V_151 ,
sizeof( V_134 -> V_150 ) - 1 ) ;
F_25 ( V_134 -> V_150 , sizeof( V_134 -> V_150 ) - 1 ) ;
memcpy ( V_134 -> V_152 , V_33 -> V_130 -> V_153 ,
sizeof( V_134 -> V_152 ) - 1 ) ;
F_25 ( V_134 -> V_152 , sizeof( V_134 -> V_152 ) - 1 ) ;
V_134 -> V_154 = V_33 -> V_155 -> V_156 ;
V_134 -> V_157 = V_33 -> V_130 -> V_131 ;
if ( V_33 -> V_158 ) {
V_134 -> type = V_33 -> V_158 -> V_159 ;
if ( V_134 -> type == V_160 )
V_134 -> V_161 = V_33 -> V_158 -> V_161 ;
} else {
V_134 -> type = V_135 ;
}
if ( V_33 -> V_162 ) {
for ( V_42 = 0 ; V_42 < 16 ; V_42 ++ ) {
sprintf ( V_134 -> V_163 + 2 * V_42 , L_11 ,
V_33 -> V_162 -> V_164 [ V_42 ] ) ;
}
}
}
static int F_26 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
unsigned long V_43 ;
if ( ! V_33 )
return - V_165 ;
if ( ! V_33 -> V_130 || ! V_33 -> V_155 )
return - V_165 ;
F_27 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
F_24 ( V_33 ) ;
F_29 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
return 0 ;
}
static int F_30 ( struct V_30 * V_31 , struct V_149 * V_134 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
unsigned long V_43 ;
if ( V_33 ) {
F_27 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
* V_134 = V_33 -> V_134 ;
F_29 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
return 0 ;
}
return - V_128 ;
}
static int F_31 ( struct V_30 * V_31 ,
struct V_32 * V_33 )
{
struct V_149 V_166 ;
F_24 ( V_33 ) ;
F_30 ( V_31 , & V_166 ) ;
return memcmp ( & V_166 , & V_33 -> V_134 , sizeof( struct V_149 ) ) ;
}
static void F_32 ( struct V_30 * V_31 ,
struct V_167 * V_168 ,
T_2 * V_169 ,
T_2 V_170 )
{
struct V_26 * V_45 ;
V_169 [ 0 ] = 0xE5 ;
V_169 [ 1 ] = 0xF1 ;
V_169 [ 2 ] = 0x4B ;
V_169 [ 3 ] = 0xF0 ;
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_172 ;
V_45 -> V_43 = 0 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_169 ;
V_45 -> V_42 = V_174 ;
V_168 -> V_175 = V_176 ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_178 = NULL ;
V_168 -> V_179 = 10 * V_180 ;
V_168 -> V_170 = V_170 ;
V_168 -> V_181 = 256 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
F_34 ( V_185 , & V_168 -> V_43 ) ;
}
static void F_35 ( struct V_167 * V_168 , void * V_29 )
{
struct V_26 * V_45 ;
T_2 * V_169 ;
if ( V_168 -> V_183 != V_186 ) {
V_45 = V_168 -> V_171 ;
V_169 = ( T_2 * ) ( ( V_173 ) V_45 -> V_56 ) ;
memset ( V_169 , 0 , sizeof( * V_169 ) ) ;
V_169 [ 0 ] = 0xE5 ;
V_169 [ 1 ] = 0xF1 ;
V_169 [ 2 ] = 0x4B ;
V_169 [ 3 ] = 0xF0 ;
}
F_36 ( V_168 , V_29 ) ;
}
static int F_37 ( struct V_30 * V_31 ,
struct V_167 * V_168 ,
T_2 * V_169 ,
T_2 V_170 )
{
struct V_187 * V_187 ;
int V_34 ;
V_187 = F_38 ( V_31 -> V_2 , V_188 ) ;
if ( ! V_187 || V_187 -> V_48 != V_172 )
return - V_40 ;
F_32 ( V_31 , V_168 , V_169 , V_170 ) ;
F_39 ( V_189 , & V_168 -> V_43 ) ;
F_34 ( V_190 , & V_168 -> V_43 ) ;
V_168 -> V_181 = 5 ;
V_168 -> V_191 = F_35 ;
V_34 = F_40 ( V_168 ) ;
return V_34 ;
}
static int F_41 ( struct V_30 * V_31 ,
void * * V_169 ,
int * V_192 , T_2 V_170 )
{
struct V_187 * V_187 ;
char * V_193 = NULL ;
int V_3 ;
struct V_167 * V_168 ;
V_187 = F_38 ( V_31 -> V_2 , V_188 ) ;
if ( ! V_187 || V_187 -> V_48 != V_172 ) {
V_3 = - V_40 ;
goto V_194;
}
V_193 = F_42 ( V_174 , V_195 | V_196 ) ;
if ( ! V_193 ) {
V_3 = - V_197 ;
goto V_194;
}
V_168 = F_43 ( V_176 , 1 ,
0 ,
V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_18 ( V_7 , V_31 , L_1 ,
L_12 ) ;
V_3 = - V_197 ;
goto V_194;
}
F_32 ( V_31 , V_168 , V_193 , V_170 ) ;
V_168 -> V_191 = F_35 ;
V_3 = F_45 ( V_168 ) ;
F_46 ( V_168 , V_168 -> V_177 ) ;
if ( V_3 )
goto V_194;
* V_192 = V_174 ;
* V_169 = V_193 ;
return 0 ;
V_194:
F_47 ( V_193 ) ;
* V_169 = NULL ;
* V_192 = 0 ;
return V_3 ;
}
static int F_48 ( struct V_32 * V_33 )
{
struct V_198 * V_158 ;
int V_199 , V_42 ;
V_33 -> V_130 = NULL ;
V_33 -> V_158 = NULL ;
V_33 -> V_162 = NULL ;
V_33 -> V_155 = NULL ;
V_42 = V_33 -> V_200 / sizeof( struct V_198 ) ;
V_158 = (struct V_198 * ) V_33 -> V_201 ;
for ( V_199 = 0 ; V_199 < V_42 ; ++ V_199 ) {
if ( V_158 -> V_43 . V_202 == 1 && V_158 -> V_120 == 1 )
V_33 -> V_158 = V_158 ;
else if ( V_158 -> V_43 . V_202 == 1 && V_158 -> V_120 == 4 )
V_33 -> V_162 = (struct V_203 * ) V_158 ;
else if ( V_158 -> V_43 . V_202 == 2 )
V_33 -> V_155 = (struct V_204 * ) V_158 ;
else if ( V_158 -> V_43 . V_202 == 3 && V_158 -> V_205 == 1 )
V_33 -> V_130 = (struct V_206 * ) V_158 ;
V_158 ++ ;
}
if ( ! V_33 -> V_130 || ! V_33 -> V_155 ) {
V_33 -> V_130 = NULL ;
V_33 -> V_158 = NULL ;
V_33 -> V_162 = NULL ;
V_33 -> V_155 = NULL ;
return - V_128 ;
}
return 0 ;
}
static unsigned char F_49 ( void * V_201 , int V_200 )
{
struct V_204 * V_155 ;
int V_199 , V_42 , V_207 ;
V_42 = V_200 / sizeof( * V_155 ) ;
V_155 = (struct V_204 * ) V_201 ;
V_207 = 0 ;
for ( V_199 = 0 ; V_199 < V_42 ; ++ V_199 ) {
if ( V_155 -> V_43 . V_202 == 2 ) {
V_207 = 1 ;
break;
}
V_155 ++ ;
}
if ( V_207 )
return ( ( char * ) V_155 ) [ 18 ] & 0x07 ;
else
return 0 ;
}
static void F_50 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
int V_199 ;
V_33 -> V_201 = NULL ;
V_33 -> V_200 = 0 ;
for ( V_199 = 0 ; V_199 < 8 ; V_199 ++ ) {
F_47 ( V_31 -> V_208 [ V_199 ] . V_201 ) ;
V_31 -> V_208 [ V_199 ] . V_201 = NULL ;
V_31 -> V_208 [ V_199 ] . V_209 = 0 ;
V_31 -> V_208 [ V_199 ] . V_154 = 0 ;
V_31 -> V_208 [ V_199 ] . V_210 = 0 ;
}
}
static int F_51 ( struct V_30 * V_31 )
{
void * V_201 ;
int V_200 , V_211 ;
int V_34 , V_212 , V_213 ;
T_2 V_170 , V_214 ;
struct V_32 * V_33 , V_215 ;
struct V_149 * V_134 ;
char V_216 [ 60 ] , V_217 [ 60 ] ;
struct V_218 * V_219 ;
struct V_220 V_221 ;
V_33 = V_31 -> V_33 ;
V_214 = F_52 ( V_31 -> V_2 ) ;
F_53 ( V_31 -> V_2 , & V_221 ) ;
V_211 = 0 ;
V_212 = 0 ;
for ( V_170 = 0x80 ; V_170 ; V_170 >>= 1 ) {
if ( ! ( V_170 & V_214 ) )
continue;
V_34 = F_41 ( V_31 , & V_201 ,
& V_200 , V_170 ) ;
if ( V_34 && V_34 != - V_40 ) {
F_3 ( V_7 , V_31 -> V_2 ,
L_13
L_14 , V_34 ) ;
return V_34 ;
}
if ( V_201 == NULL ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_15
L_16 ) ;
F_54 ( V_31 , V_214 ) ;
continue;
}
if ( ! V_211 ) {
F_50 ( V_31 ) ;
V_33 -> V_201 = V_201 ;
V_33 -> V_200 = V_200 ;
if ( F_48 ( V_33 ) ) {
V_33 -> V_201 = NULL ;
V_33 -> V_200 = 0 ;
F_47 ( V_201 ) ;
continue;
}
V_213 = F_55 ( V_170 ) ;
V_31 -> V_208 [ V_213 ] . V_201 = V_201 ;
V_31 -> V_208 [ V_213 ] . V_209 = V_221 . V_209 ;
V_31 -> V_208 [ V_213 ] . V_154 = V_221 . V_154 ;
V_219 = F_56 ( V_31 -> V_2 , V_213 ) ;
if ( V_219 )
V_31 -> V_208 [ V_213 ] . V_210 = V_219 -> V_210 ;
F_47 ( V_219 ) ;
F_26 ( V_31 ) ;
V_211 ++ ;
} else {
V_215 . V_201 = V_201 ;
V_215 . V_200 = V_174 ;
if ( F_48 (
& V_215 ) ) {
V_215 . V_201 = NULL ;
V_215 . V_200 = 0 ;
F_47 ( V_201 ) ;
continue;
}
if ( F_31 (
V_31 , & V_215 ) ) {
V_134 = & V_215 . V_134 ;
if ( strlen ( V_134 -> V_163 ) > 0 )
snprintf ( V_216 ,
sizeof( V_216 ) ,
L_17 ,
V_134 -> V_150 , V_134 -> V_152 ,
V_134 -> V_154 , V_134 -> V_157 ,
V_134 -> V_163 ) ;
else
snprintf ( V_216 ,
sizeof( V_216 ) ,
L_18 ,
V_134 -> V_150 , V_134 -> V_152 ,
V_134 -> V_154 ,
V_134 -> V_157 ) ;
V_134 = & V_33 -> V_134 ;
if ( strlen ( V_134 -> V_163 ) > 0 )
snprintf ( V_217 ,
sizeof( V_217 ) ,
L_17 ,
V_134 -> V_150 , V_134 -> V_152 ,
V_134 -> V_154 , V_134 -> V_157 ,
V_134 -> V_163 ) ;
else
snprintf ( V_217 ,
sizeof( V_217 ) ,
L_18 ,
V_134 -> V_150 , V_134 -> V_152 ,
V_134 -> V_154 ,
V_134 -> V_157 ) ;
F_15 ( & V_31 -> V_2 -> V_82 ,
L_19
L_20
L_21 , V_170 ,
V_216 , V_217 ) ;
V_212 = - V_128 ;
F_57 ( V_31 , V_170 ) ;
continue;
}
V_213 = F_55 ( V_170 ) ;
V_31 -> V_208 [ V_213 ] . V_201 = V_201 ;
V_31 -> V_208 [ V_213 ] . V_209 = V_221 . V_209 ;
V_31 -> V_208 [ V_213 ] . V_154 = V_221 . V_154 ;
V_219 = F_56 ( V_31 -> V_2 , V_213 ) ;
if ( V_219 )
V_31 -> V_208 [ V_213 ] . V_210 = V_219 -> V_210 ;
F_47 ( V_219 ) ;
V_215 . V_201 = NULL ;
V_215 . V_200 = 0 ;
}
switch ( F_49 ( V_201 , V_200 ) ) {
case 0x02 :
F_58 ( V_31 , V_170 ) ;
break;
case 0x03 :
F_59 ( V_31 , V_170 ) ;
break;
}
if ( ! F_60 ( V_31 ) ) {
F_61 ( V_31 , V_170 ) ;
F_62 ( V_31 ) ;
} else {
F_54 ( V_31 , V_170 ) ;
}
}
return V_212 ;
}
static T_3 F_63 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
int V_222 , V_223 , V_224 ;
int V_225 , V_226 ;
if ( V_227 )
return 0 ;
V_222 = V_228 . V_229 ;
V_223 = V_33 -> V_155 -> V_230 [ 7 ] & 0x04 ;
V_224 = V_33 -> V_231 . V_232 [ 40 ] & 0x80 ;
V_225 = V_222 && V_223 && V_224 ;
if ( ! V_225 )
return 0 ;
V_226 = F_64 ( V_31 -> V_2 , 0 ) ;
if ( V_226 < 0 ) {
F_65 ( & V_31 -> V_2 -> V_82 , L_22 ) ;
return 0 ;
} else {
return ( T_3 ) V_226 * V_233 ;
}
}
static int F_66 ( struct V_30 * V_31 , T_2 V_170 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
int V_226 ;
T_3 V_234 ;
if ( V_33 -> V_234 ) {
V_226 = F_64 ( V_31 -> V_2 , V_170 ) ;
if ( ( V_226 < 0 ) ) {
F_65 ( & V_31 -> V_2 -> V_82 ,
L_23
L_24 ,
V_226 , V_170 ) ;
return V_226 ;
}
V_234 = ( T_3 ) V_226 * V_233 ;
if ( V_234 < V_33 -> V_234 ) {
F_65 ( & V_31 -> V_2 -> V_82 ,
L_25
L_26
L_27 , V_234 , V_170 ,
V_33 -> V_234 ) ;
return - V_41 ;
}
}
return 0 ;
}
static int F_67 ( struct V_30 * V_31 ,
struct V_235 * V_29 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
T_2 V_170 , V_214 = F_60 ( V_31 ) ;
int V_34 = - V_165 ;
for ( V_170 = 0x80 ; V_170 ; V_170 >>= 1 ) {
if ( ! ( V_170 & V_214 ) )
continue;
memset ( & V_29 -> V_169 , 0 , sizeof( V_29 -> V_169 ) ) ;
memset ( & V_29 -> V_168 , 0 , sizeof( V_29 -> V_168 ) ) ;
V_29 -> V_168 . V_171 = & V_29 -> V_45 ;
V_34 = F_37 ( V_31 , & V_29 -> V_168 ,
V_29 -> V_169 ,
V_170 ) ;
if ( V_34 ) {
if ( V_34 == - V_40 )
continue;
F_3 ( V_7 , V_31 -> V_2 ,
L_28
L_29 , V_34 ) ;
break;
}
memcpy ( V_33 -> V_201 , V_29 -> V_169 ,
V_174 ) ;
if ( F_48 ( V_33 ) ) {
V_34 = - V_165 ;
} else
break;
}
if ( ! V_34 )
V_34 = F_26 ( V_31 ) ;
return V_34 ;
}
static void F_68 ( struct V_236 * V_237 )
{
struct V_235 * V_29 ;
struct V_30 * V_31 ;
struct V_32 V_215 ;
struct V_149 * V_134 ;
T_2 V_238 [ V_174 ] ;
T_2 V_170 , V_214 , V_239 , V_240 , V_241 , V_242 , V_243 ;
unsigned long V_43 ;
char V_244 [ 60 ] ;
int V_34 ;
V_29 = F_69 ( V_237 , struct V_235 , V_245 ) ;
V_31 = V_29 -> V_31 ;
if ( F_70 ( V_246 , & V_31 -> V_43 ) ) {
F_71 ( V_237 ) ;
return;
}
if ( F_72 ( V_247 , & V_31 -> V_43 ) ) {
F_71 ( V_237 ) ;
return;
}
V_214 = 0 ;
V_239 = 0 ;
V_240 = 0 ;
V_241 = 0 ;
V_242 = 0 ;
V_243 = 0 ;
for ( V_170 = 0x80 ; V_170 ; V_170 >>= 1 ) {
if ( ! ( V_170 & V_29 -> V_248 ) )
continue;
memset ( & V_29 -> V_169 , 0 , sizeof( V_29 -> V_169 ) ) ;
memset ( & V_29 -> V_168 , 0 , sizeof( V_29 -> V_168 ) ) ;
V_29 -> V_168 . V_171 = & V_29 -> V_45 ;
V_34 = F_37 ( V_31 , & V_29 -> V_168 ,
V_29 -> V_169 ,
V_170 ) ;
if ( ! V_34 ) {
switch ( F_49 ( V_29 -> V_169 ,
V_174 )
) {
case 0x02 :
V_239 |= V_170 ;
break;
case 0x03 :
V_240 |= V_170 ;
break;
}
V_214 |= V_170 ;
} else if ( V_34 == - V_40 ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_30
L_31 ) ;
V_214 |= V_170 ;
} else if ( V_34 == - V_249 ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_32
L_33 ) ;
V_241 |= V_170 ;
} else {
F_65 ( & V_31 -> V_2 -> V_82 ,
L_34
L_35 , V_34 , V_170 ) ;
continue;
}
if ( F_66 ( V_31 , V_170 ) ) {
V_214 &= ~ V_170 ;
V_239 &= ~ V_170 ;
V_240 &= ~ V_170 ;
V_242 |= V_170 ;
continue;
}
memcpy ( & V_238 , V_29 -> V_169 ,
V_174 ) ;
V_215 . V_201 = ( void * ) & V_238 ;
V_215 . V_200 = V_174 ;
if ( F_48 ( & V_215 ) ) {
V_215 . V_201 = NULL ;
V_215 . V_200 = 0 ;
continue;
}
if ( F_60 ( V_31 ) &&
F_31 ( V_31 , & V_215 ) ) {
if ( F_67 ( V_31 , V_29 ) ||
F_31 (
V_31 , & V_215 ) ) {
V_134 = & V_215 . V_134 ;
if ( strlen ( V_134 -> V_163 ) > 0 )
snprintf ( V_244 , sizeof( V_244 ) ,
L_17 ,
V_134 -> V_150 , V_134 -> V_152 ,
V_134 -> V_154 , V_134 -> V_157 ,
V_134 -> V_163 ) ;
else
snprintf ( V_244 , sizeof( V_244 ) ,
L_18 ,
V_134 -> V_150 , V_134 -> V_152 ,
V_134 -> V_154 ,
V_134 -> V_157 ) ;
F_15 ( & V_31 -> V_2 -> V_82 ,
L_36
L_37
L_38 ,
V_170 , V_244 ) ;
V_214 &= ~ V_170 ;
V_239 &= ~ V_170 ;
V_240 &= ~ V_170 ;
V_243 |= V_170 ;
continue;
}
}
F_27 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
if ( ! F_60 ( V_31 ) && V_214 ) {
F_61 ( V_31 , V_214 ) ;
F_62 ( V_31 ) ;
} else {
F_54 ( V_31 , V_214 ) ;
}
F_58 ( V_31 , V_239 ) ;
F_59 ( V_31 , V_240 ) ;
F_73 ( V_31 , V_241 ) ;
F_57 ( V_31 , V_243 ) ;
F_74 ( V_31 , V_242 ) ;
F_29 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
}
F_39 ( V_247 , & V_31 -> V_43 ) ;
F_75 ( V_31 ) ;
if ( V_29 -> V_250 )
F_76 ( & V_251 ) ;
else
F_47 ( V_29 ) ;
}
static int F_77 ( struct V_30 * V_31 , T_2 V_170 )
{
struct V_235 * V_29 ;
V_29 = F_78 ( sizeof( * V_29 ) , V_252 | V_196 ) ;
if ( ! V_29 ) {
if ( F_79 ( & V_251 ) ) {
V_29 = V_253 ;
V_29 -> V_250 = 1 ;
} else
return - V_197 ;
} else {
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_29 -> V_250 = 0 ;
}
F_80 ( & V_29 -> V_245 , F_68 ) ;
F_81 ( V_31 ) ;
V_29 -> V_31 = V_31 ;
V_29 -> V_248 = V_170 ;
F_71 ( & V_29 -> V_245 ) ;
return 0 ;
}
static void F_82 ( struct V_30 * V_31 , T_2 V_254 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
unsigned long V_43 ;
if ( ! V_33 -> V_234 )
V_33 -> V_234 = F_63 ( V_31 ) ;
F_27 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
F_83 ( V_31 , V_254 ? : F_84 ( V_31 ) ) ;
F_85 ( V_31 ) ;
F_29 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
}
static int F_86 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_255 * V_256 ;
struct V_257 * V_231 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
int V_34 ;
memset ( & V_33 -> V_231 , 0 , sizeof( struct V_257 ) ) ;
V_168 = F_43 ( V_176 , 1 + 1 ,
( sizeof( struct V_255 ) +
sizeof( struct V_257 ) ) ,
V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 , L_39
L_40 ) ;
return F_87 ( V_168 ) ;
}
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_178 = NULL ;
V_168 -> V_181 = 256 ;
V_168 -> V_179 = 10 * V_180 ;
V_256 = (struct V_255 * ) V_168 -> V_29 ;
memset ( V_256 , 0 , sizeof( struct V_255 ) ) ;
V_256 -> V_258 = V_259 ;
V_256 -> V_260 = 0x41 ;
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_261 ;
V_45 -> V_42 = sizeof( struct V_255 ) ;
V_45 -> V_43 |= V_262 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_256 ;
V_231 = (struct V_257 * ) ( V_256 + 1 ) ;
memset ( V_231 , 0 , sizeof( struct V_257 ) ) ;
V_45 ++ ;
V_45 -> V_54 = V_263 ;
V_45 -> V_42 = sizeof( struct V_257 ) ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_231 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_45 ( V_168 ) ;
if ( V_34 == 0 ) {
V_256 = (struct V_255 * ) V_168 -> V_29 ;
V_231 = (struct V_257 * ) ( V_256 + 1 ) ;
memcpy ( & V_33 -> V_231 , V_231 ,
sizeof( struct V_257 ) ) ;
} else
F_65 ( & V_31 -> V_2 -> V_82 , L_41
L_42 , V_34 ) ;
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static struct V_167 * F_88 ( struct V_30 * V_31 ,
int V_264 )
{
struct V_167 * V_168 ;
struct V_265 * V_266 ;
struct V_26 * V_45 ;
V_168 = F_43 ( V_176 , 1 ,
sizeof( struct V_265 ) ,
V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_18 ( V_7 , V_31 , L_1 ,
L_43 ) ;
return V_168 ;
}
V_266 = (struct V_265 * ) V_168 -> V_29 ;
V_266 -> V_258 = V_267 ;
V_266 -> V_260 = 0xc0 ;
if ( V_264 ) {
V_266 -> V_260 |= 0x08 ;
V_266 -> V_268 [ 0 ] = 0x88 ;
}
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_261 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_266 ;
V_45 -> V_42 = 66 ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_178 = NULL ;
V_168 -> V_181 = 256 ;
V_168 -> V_179 = 10 * V_180 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
return V_168 ;
}
static int
F_89 ( struct V_30 * V_31 , int V_264 ,
unsigned long V_43 )
{
struct V_167 * V_168 ;
int V_34 ;
V_168 = F_88 ( V_31 , V_264 ) ;
if ( F_44 ( V_168 ) )
return F_87 ( V_168 ) ;
V_168 -> V_43 |= V_43 ;
V_34 = F_45 ( V_168 ) ;
if ( ! V_34 )
F_90 () ;
else if ( V_168 -> V_269 == - V_249 )
V_34 = - V_249 ;
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int F_91 ( struct V_30 * V_31 ,
unsigned long V_43 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
int V_264 , V_34 ;
if ( V_33 -> V_134 . type == V_160 ||
V_33 -> V_134 . type == V_137 )
return 0 ;
if ( V_270 || V_271 )
V_264 = 0 ;
else
V_264 = 1 ;
V_34 = F_89 ( V_31 , V_264 , V_43 ) ;
F_3 ( V_7 , V_31 -> V_2 , L_44
L_45 , V_33 -> V_134 . V_154 , V_34 ) ;
return V_34 ;
}
static void F_92 ( struct V_236 * V_237 )
{
struct V_30 * V_31 = F_69 ( V_237 , struct V_30 ,
V_272 ) ;
unsigned long V_43 = 0 ;
F_34 ( V_273 , & V_43 ) ;
if ( F_91 ( V_31 , V_43 )
== - V_249 ) {
F_71 ( & V_31 -> V_272 ) ;
return;
}
F_75 ( V_31 ) ;
}
static void F_93 ( struct V_30 * V_31 )
{
F_81 ( V_31 ) ;
if ( F_70 ( V_274 , & V_31 -> V_43 ) ||
V_31 -> V_275 < V_276 ) {
F_75 ( V_31 ) ;
return;
}
if ( ! F_71 ( & V_31 -> V_272 ) )
F_75 ( V_31 ) ;
}
static int
F_94 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_277 * V_178 ;
struct V_149 V_278 ;
int V_34 , V_199 ;
int V_279 ;
unsigned long V_280 ;
F_80 ( & V_31 -> V_272 , F_92 ) ;
F_80 ( & V_31 -> V_281 , V_282 ) ;
if ( ! F_95 ( V_31 -> V_2 ) ) {
F_65 ( & V_31 -> V_2 -> V_82 ,
L_46 ) ;
return - V_283 ;
}
if ( ! F_96 ( V_31 -> V_2 ) ) {
F_97 ( & V_31 -> V_2 -> V_82 ,
L_47 ) ;
}
if ( ! V_33 ) {
V_33 = F_42 ( sizeof( * V_33 ) , V_195 | V_196 ) ;
if ( ! V_33 ) {
F_65 ( & V_31 -> V_2 -> V_82 ,
L_48
L_49 ) ;
return - V_197 ;
}
V_31 -> V_33 = V_33 ;
} else {
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
}
V_33 -> V_284 = - 1 ;
V_33 -> V_69 . V_68 = V_285 ;
V_33 -> V_69 . V_89 = 0 ;
V_34 = F_51 ( V_31 ) ;
if ( V_34 )
goto V_286;
V_31 -> V_287 = V_288 ;
V_31 -> V_289 = V_290 ;
V_31 -> V_291 = V_292 ;
V_31 -> V_293 = V_294 ;
if ( V_33 -> V_155 ) {
V_280 = 1 ;
for ( V_199 = 0 ; V_199 < V_33 -> V_155 -> V_295 . V_280 ; V_199 ++ )
V_280 = 10 * V_280 ;
V_280 = V_280 * V_33 -> V_155 -> V_295 . V_296 ;
if ( V_280 != 0 && V_280 <= V_297 )
V_31 -> V_287 = V_280 ;
}
F_30 ( V_31 , & V_278 ) ;
if ( V_278 . type == V_135 ) {
V_178 = F_98 () ;
if ( F_44 ( V_178 ) ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_50
L_51 ) ;
V_34 = F_87 ( V_178 ) ;
goto V_286;
}
V_31 -> V_178 = V_178 ;
V_178 -> V_298 = V_31 ;
}
V_34 = F_99 ( V_31 ) ;
if ( V_34 )
goto V_299;
F_91 ( V_31 , 0 ) ;
V_34 = F_51 ( V_31 ) ;
if ( V_34 )
goto V_300;
F_86 ( V_31 ) ;
V_34 = F_100 ( V_31 , V_176 ,
& V_33 -> V_35 , 64 ) ;
if ( V_34 ) {
F_3 ( V_7 , V_31 -> V_2 ,
L_52 , V_34 ) ;
goto V_300;
}
if ( ( V_31 -> V_231 & V_301 ) &&
! ( V_33 -> V_35 . V_36 . V_302 ) ) {
F_15 ( & V_31 -> V_2 -> V_82 , L_53
L_54 ) ;
V_34 = - V_128 ;
goto V_300;
}
if ( V_33 -> V_35 . V_303 == V_304 &&
V_33 -> V_35 . V_305 )
V_33 -> V_90 = V_33 -> V_35 . V_305 ;
else
V_33 -> V_90 = V_33 -> V_35 . V_303 ;
V_33 -> V_234 = F_63 ( V_31 ) ;
V_279 = F_101 ( V_31 ) ;
if ( V_279 )
F_34 ( V_306 , & V_31 -> V_43 ) ;
F_97 ( & V_31 -> V_2 -> V_82 , L_55
L_56 ,
V_33 -> V_35 . V_20 ,
V_33 -> V_35 . V_307 ,
V_33 -> V_35 . V_84 ,
V_33 -> V_35 . V_308 . V_309 ,
V_33 -> V_90 ,
V_33 -> V_35 . V_86 ,
V_33 -> V_35 . V_310 ,
V_279 ? L_57 : L_58 ) ;
return 0 ;
V_300:
F_102 ( V_31 ) ;
V_299:
F_103 ( V_31 -> V_178 ) ;
V_31 -> V_178 = NULL ;
V_286:
F_47 ( V_33 -> V_201 ) ;
F_47 ( V_31 -> V_33 ) ;
V_31 -> V_33 = NULL ;
return V_34 ;
}
static void F_104 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
int V_199 ;
F_102 ( V_31 ) ;
V_33 -> V_130 = NULL ;
V_33 -> V_158 = NULL ;
V_33 -> V_162 = NULL ;
V_33 -> V_155 = NULL ;
V_33 -> V_200 = 0 ;
for ( V_199 = 0 ; V_199 < 8 ; V_199 ++ ) {
F_47 ( V_31 -> V_208 [ V_199 ] . V_201 ) ;
if ( ( T_2 * ) V_31 -> V_208 [ V_199 ] . V_201 ==
V_33 -> V_201 ) {
V_33 -> V_201 = NULL ;
V_33 -> V_200 = 0 ;
}
V_31 -> V_208 [ V_199 ] . V_201 = NULL ;
V_31 -> V_208 [ V_199 ] . V_209 = 0 ;
V_31 -> V_208 [ V_199 ] . V_154 = 0 ;
V_31 -> V_208 [ V_199 ] . V_210 = 0 ;
}
F_47 ( V_33 -> V_201 ) ;
V_33 -> V_201 = NULL ;
}
static struct V_167 *
F_105 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_311 * V_312 ;
struct V_140 * V_313 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
int V_314 , V_315 ;
int V_199 ;
V_314 = 8 ;
V_315 = sizeof( struct V_28 ) + 2 * sizeof( struct V_140 ) ;
V_168 = F_43 ( V_176 , V_314 , V_315 , V_31 ) ;
if ( F_44 ( V_168 ) )
return V_168 ;
V_45 = V_168 -> V_171 ;
F_13 ( V_45 ++ , V_168 -> V_29 , 0 , 2 ,
V_70 , V_31 ) ;
V_313 = V_168 -> V_29 + sizeof( struct V_28 ) ;
V_45 [ - 1 ] . V_43 |= V_262 ;
V_126 ( V_45 ++ , V_313 ++ , 0 , 0 , 4 ,
V_70 , V_31 , 0 ) ;
V_312 = V_33 -> V_316 ;
for ( V_199 = 0 ; V_199 < 4 ; V_199 ++ ) {
V_45 [ - 1 ] . V_43 |= V_262 ;
V_45 -> V_54 = V_70 ;
V_45 -> V_43 = 0 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_312 ;
V_45 ++ ;
V_312 ++ ;
}
V_45 [ - 1 ] . V_43 |= V_262 ;
V_126 ( V_45 ++ , V_313 ++ , 2 , 0 , 1 ,
V_70 , V_31 , 0 ) ;
V_45 [ - 1 ] . V_43 |= V_262 ;
V_45 -> V_54 = V_70 ;
V_45 -> V_43 = 0 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_312 ;
V_168 -> V_178 = NULL ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_181 = 255 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
return V_168 ;
}
static int F_106 ( struct V_167 * V_317 )
{
char * V_318 ;
if ( V_317 -> V_183 == V_186 )
return V_319 ;
else if ( V_317 -> V_183 == V_320 ||
V_317 -> V_183 == V_321 ) {
V_318 = F_107 ( & V_317 -> V_322 ) ;
if ( V_318 && ( V_318 [ 1 ] & V_323 ) )
return V_324 ;
else
return V_325 ;
} else
return V_325 ;
}
static void F_108 ( struct V_167 * V_317 ,
void * V_29 )
{
struct V_30 * V_31 = V_317 -> V_119 ;
struct V_32 * V_33 = V_31 -> V_33 ;
V_33 -> V_284 = F_106 ( V_317 ) ;
F_46 ( V_317 , V_31 ) ;
F_109 ( V_31 ) ;
}
static int F_110 ( struct V_277 * V_178 )
{
struct V_167 * V_317 ;
V_317 = F_105 ( V_178 -> V_298 ) ;
if ( F_44 ( V_317 ) )
return F_87 ( V_317 ) ;
V_317 -> V_191 = F_108 ;
V_317 -> V_326 = NULL ;
V_317 -> V_179 = 5 * V_180 ;
F_39 ( V_189 , & V_317 -> V_43 ) ;
V_317 -> V_181 = 0 ;
F_111 ( V_317 ) ;
return - V_249 ;
}
static int F_112 ( struct V_277 * V_178 )
{
struct V_30 * V_31 = V_178 -> V_298 ;
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_311 * V_316 ;
unsigned int V_327 , V_145 ;
int V_183 , V_199 ;
struct V_167 * V_317 ;
V_183 = V_33 -> V_284 ;
V_33 -> V_284 = - 1 ;
if ( V_183 == V_325 ) {
V_317 = F_105 ( V_31 ) ;
F_45 ( V_317 ) ;
V_183 = F_106 ( V_317 ) ;
F_46 ( V_317 , V_31 ) ;
}
if ( V_31 -> V_231 & V_301 ) {
V_178 -> V_328 = V_329 ;
V_145 = V_330 ;
V_178 -> V_331 = 3 ;
goto V_332;
}
if ( V_183 == V_324 ) {
F_65 ( & V_31 -> V_2 -> V_82 , L_59 ) ;
return - V_333 ;
} else if ( V_183 == V_325 ) {
F_15 ( & V_31 -> V_2 -> V_82 ,
L_60
L_61 ) ;
return - V_283 ;
}
V_33 -> V_85 = 1 ;
V_316 = NULL ;
for ( V_199 = 0 ; V_199 < 3 ; V_199 ++ ) {
if ( V_33 -> V_316 [ V_199 ] . V_16 != 4 ||
V_33 -> V_316 [ V_199 ] . V_17 != F_23 ( V_199 ) - 4 ||
V_33 -> V_316 [ V_199 ] . V_23 != 0 ||
V_33 -> V_316 [ V_199 ] . V_24 != V_334 [ V_199 ] ||
V_33 -> V_316 [ V_199 ] . V_117 != V_335 [ V_199 ] ) {
V_33 -> V_85 = 0 ;
break;
}
}
if ( V_199 == 3 )
V_316 = & V_33 -> V_316 [ 4 ] ;
if ( V_33 -> V_85 == 0 ) {
for ( V_199 = 0 ; V_199 < 5 ; V_199 ++ ) {
if ( ( V_33 -> V_316 [ V_199 ] . V_16 != 0 ) ||
( V_33 -> V_316 [ V_199 ] . V_17 !=
V_33 -> V_316 [ 0 ] . V_17 ) ||
V_33 -> V_316 [ V_199 ] . V_23 != 0 ||
V_33 -> V_316 [ V_199 ] . V_24 != V_334 [ V_199 ] ||
V_33 -> V_316 [ V_199 ] . V_117 != V_335 [ V_199 ] )
break;
}
if ( V_199 == 5 )
V_316 = & V_33 -> V_316 [ 0 ] ;
} else {
if ( V_33 -> V_316 [ 3 ] . V_117 == 1 )
F_65 ( & V_31 -> V_2 -> V_82 ,
L_62 ) ;
}
if ( V_316 != NULL && V_316 -> V_16 == 0 ) {
if ( F_113 ( V_316 -> V_17 ) == 0 )
V_178 -> V_328 = V_316 -> V_17 ;
}
if ( V_178 -> V_328 == 0 ) {
F_65 ( & V_31 -> V_2 -> V_82 ,
L_63 ) ;
return - V_333 ;
}
V_178 -> V_331 = 0 ;
for ( V_327 = 512 ; V_327 < V_178 -> V_328 ; V_327 = V_327 << 1 )
V_178 -> V_331 ++ ;
V_145 = F_9 ( & V_33 -> V_35 , 0 , V_178 -> V_328 ) ;
V_332:
V_178 -> V_336 = ( V_33 -> V_90 *
V_33 -> V_35 . V_86 *
V_145 ) ;
F_97 ( & V_31 -> V_2 -> V_82 ,
L_64
L_65 , ( V_178 -> V_328 >> 10 ) ,
( ( V_33 -> V_90 *
V_33 -> V_35 . V_86 *
V_145 * ( V_178 -> V_328 >> 9 ) ) >> 1 ) ,
( ( V_145 * V_178 -> V_328 ) >> 10 ) ,
V_33 -> V_85 ?
L_66 : L_67 ) ;
return 0 ;
}
static int F_114 ( struct V_277 * V_178 )
{
struct V_32 * V_33 = V_178 -> V_298 -> V_33 ;
if ( V_33 -> V_284 < 0 )
return F_110 ( V_178 ) ;
else
return F_112 ( V_178 ) ;
}
static int F_115 ( struct V_30 * V_31 )
{
return F_116 ( V_31 ) ;
}
static int F_117 ( struct V_30 * V_31 )
{
F_118 ( & V_31 -> V_337 ) ;
F_118 ( & V_31 -> V_272 ) ;
return 0 ;
}
static int F_119 ( struct V_30 * V_31 )
{
return F_120 ( V_31 ) ;
}
static int
F_121 ( struct V_277 * V_178 , struct V_338 * V_22 )
{
struct V_32 * V_33 = V_178 -> V_298 -> V_33 ;
if ( F_113 ( V_178 -> V_328 ) == 0 ) {
V_22 -> V_339 = F_9 ( & V_33 -> V_35 ,
0 , V_178 -> V_328 ) ;
}
V_22 -> V_340 = V_33 -> V_35 . V_303 ;
V_22 -> V_51 = V_33 -> V_35 . V_86 ;
return 0 ;
}
static struct V_167 *
F_122 ( struct V_30 * V_298 , struct V_341 * V_342 ,
int V_264 , struct V_311 * V_343 ,
int V_344 )
{
struct V_32 * V_345 ;
struct V_30 * V_119 = NULL ;
struct V_346 * V_347 = NULL ;
struct V_167 * V_168 ;
struct V_348 * V_348 ;
int V_349 ;
int V_42 ;
int V_34 ;
int V_199 ;
if ( V_264 )
V_119 = F_123 ( V_298 ) ;
if ( ! V_119 )
V_119 = V_298 ;
V_345 = V_119 -> V_33 ;
V_42 = V_344 * ( V_342 -> V_350 - V_342 -> V_351 + 1 ) ;
V_349 = F_124 ( 0 , V_42 , 0 ) ;
V_168 = F_43 ( V_176 , 0 , V_349 , V_119 ) ;
if ( F_44 ( V_168 ) )
return V_168 ;
V_345 -> V_42 ++ ;
V_348 = F_125 ( V_168 -> V_29 , V_349 , V_352 , 0 , V_42 , 0 ) ;
if ( F_44 ( V_348 ) ) {
V_34 = - V_128 ;
goto V_353;
}
V_168 -> V_171 = F_126 ( V_348 ) ;
V_34 = F_127 ( V_348 , V_342 -> V_351 , V_342 -> V_350 ,
V_354 , V_298 , V_119 , 0 , V_42 ,
sizeof( struct V_311 ) ,
V_42 * sizeof( struct V_311 ) , 0 , V_344 ) ;
if ( V_34 )
goto V_353;
for ( V_199 = 0 ; V_199 < V_42 ; V_199 ++ ) {
V_347 = F_128 ( V_348 , 0 , V_343 ++ ,
sizeof( struct V_311 ) ) ;
if ( F_44 ( V_347 ) ) {
V_34 = - V_128 ;
goto V_353;
}
}
V_347 -> V_43 |= V_355 ;
F_129 ( V_348 ) ;
V_168 -> V_356 = 1 ;
V_168 -> V_119 = V_119 ;
V_168 -> V_177 = V_119 ;
V_168 -> V_118 = V_298 ;
V_168 -> V_181 = V_119 -> V_289 ;
V_168 -> V_179 = V_119 -> V_287 * V_180 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
F_34 ( V_357 , & V_168 -> V_43 ) ;
F_34 ( V_358 , & V_168 -> V_43 ) ;
return V_168 ;
V_353:
F_46 ( V_168 , V_119 ) ;
return F_130 ( V_34 ) ;
}
static struct V_167 *
F_131 ( struct V_30 * V_298 , struct V_341 * V_342 ,
int V_264 , struct V_311 * V_343 , int V_344 )
{
struct V_32 * V_345 ;
struct V_32 * V_359 ;
struct V_30 * V_119 = NULL ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
void * V_29 ;
int V_314 , V_315 ;
int V_360 ;
int V_42 ;
int V_199 ;
if ( V_264 )
V_119 = F_123 ( V_298 ) ;
if ( ! V_119 )
V_119 = V_298 ;
V_345 = V_119 -> V_33 ;
V_359 = V_298 -> V_33 ;
V_42 = V_344 * ( V_342 -> V_350 - V_342 -> V_351 + 1 ) ;
V_360 = V_359 -> V_231 . V_232 [ 8 ] & 0x01 ;
if ( V_360 ) {
V_314 = 1 ;
V_315 = sizeof( struct V_93 ) ;
} else {
V_314 = 2 ;
V_315 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) ;
}
V_314 += V_42 ;
V_168 = F_43 ( V_176 , V_314 , V_315 ,
V_119 ) ;
if ( F_44 ( V_168 ) )
return V_168 ;
V_345 -> V_42 ++ ;
V_29 = V_168 -> V_29 ;
V_45 = V_168 -> V_171 ;
if ( V_360 ) {
F_20 ( V_45 ++ , V_29 , V_342 -> V_351 , V_342 -> V_350 ,
V_70 , V_298 , V_119 , 1 , 0 ,
V_42 , 0 , 0 ) ;
} else {
F_13 ( V_45 ++ , V_29 , V_342 -> V_351 , V_342 -> V_350 ,
V_70 , V_119 ) ;
V_29 += sizeof( struct V_28 ) ;
V_45 [ - 1 ] . V_43 |= V_262 ;
V_126 ( V_45 ++ , V_29 , V_342 -> V_351 , 0 , V_42 ,
V_70 , V_298 , 0 ) ;
}
for ( V_199 = 0 ; V_199 < V_42 ; V_199 ++ ) {
V_45 [ - 1 ] . V_43 |= V_262 ;
V_45 -> V_54 = V_70 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_343 ;
V_45 ++ ;
V_343 ++ ;
}
V_168 -> V_119 = V_119 ;
V_168 -> V_177 = V_119 ;
V_168 -> V_118 = V_298 ;
V_168 -> V_181 = V_290 ;
V_168 -> V_179 = V_119 -> V_287 * V_180 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
F_34 ( V_361 , & V_168 -> V_43 ) ;
return V_168 ;
}
static struct V_167 *
F_132 ( struct V_30 * V_298 ,
struct V_341 * V_342 ,
int V_264 )
{
struct V_32 * V_359 ;
struct V_32 * V_345 ;
struct V_30 * V_119 = NULL ;
struct V_167 * V_362 ;
struct V_311 * V_363 ;
struct V_21 V_364 ;
struct V_26 * V_45 ;
void * V_29 ;
int V_344 ;
int V_314 , V_315 ;
int V_199 , V_365 ;
int V_366 = 0 ;
int V_367 ;
int V_368 ;
int V_360 ;
if ( V_264 )
V_119 = F_123 ( V_298 ) ;
if ( ! V_119 )
V_119 = V_298 ;
V_345 = V_119 -> V_33 ;
V_359 = V_298 -> V_33 ;
V_344 = F_9 ( & V_359 -> V_35 , 0 , V_342 -> V_121 ) ;
V_368 = V_342 -> V_350 - V_342 -> V_351 + 1 ;
if ( V_342 -> V_366 & 0x10 ) {
V_367 = 0 ;
V_366 = V_342 -> V_366 & ~ 0x10 ;
} else {
V_367 = 1 ;
V_366 = V_342 -> V_366 ;
}
V_360 = V_359 -> V_231 . V_232 [ 8 ] & 0x01 ;
switch ( V_366 ) {
case 0x00 :
case 0x08 :
V_314 = 2 + ( V_344 * V_368 ) ;
if ( V_360 )
V_315 = sizeof( struct V_93 ) +
sizeof( struct V_140 ) +
V_344 * V_368 * sizeof( struct V_311 ) ;
else
V_315 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
V_344 * V_368 * sizeof( struct V_311 ) ;
break;
case 0x01 :
case 0x09 :
V_314 = 2 + V_344 * V_368 ;
if ( V_360 )
V_315 = sizeof( struct V_93 ) +
sizeof( struct V_140 ) +
sizeof( struct V_311 ) +
V_344 * V_368 * sizeof( struct V_311 ) ;
else
V_315 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
sizeof( struct V_311 ) +
V_344 * V_368 * sizeof( struct V_311 ) ;
break;
case 0x04 :
case 0x0c :
V_314 = 3 ;
if ( V_360 )
V_315 = sizeof( struct V_93 ) +
sizeof( struct V_140 ) +
sizeof( struct V_311 ) ;
else
V_315 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
sizeof( struct V_311 ) ;
break;
default:
F_65 ( & V_119 -> V_2 -> V_82 ,
L_68 ,
V_342 -> V_366 ) ;
return F_130 ( - V_128 ) ;
}
V_362 = F_43 ( V_176 , V_314 ,
V_315 , V_119 ) ;
if ( F_44 ( V_362 ) )
return V_362 ;
V_345 -> V_42 ++ ;
V_29 = V_362 -> V_29 ;
V_45 = V_362 -> V_171 ;
switch ( V_366 & ~ 0x08 ) {
case 0x00 :
if ( V_360 ) {
F_21 ( V_45 ++ , (struct V_93 * ) V_29 ,
V_342 -> V_351 , V_342 -> V_350 ,
V_76 , V_298 , V_119 ) ;
if ( V_367 )
( (struct V_93 * ) V_29 )
-> F_13 . V_38 |= 0x04 ;
V_29 += sizeof( struct V_93 ) ;
} else {
F_13 ( V_45 ++ , (struct V_28 * ) V_29 ,
V_342 -> V_351 , V_342 -> V_350 ,
V_76 , V_119 ) ;
if ( V_367 )
( (struct V_28 * ) V_29 )
-> V_38 |= 0x04 ;
V_29 += sizeof( struct V_28 ) ;
}
V_45 [ - 1 ] . V_43 |= V_262 ;
V_126 ( V_45 ++ , (struct V_140 * ) V_29 ,
V_342 -> V_351 , 0 , V_344 * V_368 ,
V_76 , V_298 ,
V_342 -> V_121 ) ;
V_29 += sizeof( struct V_140 ) ;
break;
case 0x01 :
if ( V_360 ) {
F_21 ( V_45 ++ , (struct V_93 * ) V_29 ,
V_342 -> V_351 , V_342 -> V_350 ,
V_80 ,
V_298 , V_119 ) ;
V_29 += sizeof( struct V_93 ) ;
} else {
F_13 ( V_45 ++ , (struct V_28 * ) V_29 ,
V_342 -> V_351 , V_342 -> V_350 ,
V_80 , V_119 ) ;
V_29 += sizeof( struct V_28 ) ;
}
V_45 [ - 1 ] . V_43 |= V_262 ;
V_126 ( V_45 ++ , (struct V_140 * ) V_29 ,
V_342 -> V_351 , 0 , V_344 * V_368 + 1 ,
V_80 , V_298 ,
V_298 -> V_178 -> V_328 ) ;
V_29 += sizeof( struct V_140 ) ;
break;
case 0x04 :
if ( V_360 ) {
F_21 ( V_45 ++ , (struct V_93 * ) V_29 ,
V_342 -> V_351 , V_342 -> V_350 ,
V_76 , V_298 , V_119 ) ;
V_29 += sizeof( struct V_93 ) ;
} else {
F_13 ( V_45 ++ , (struct V_28 * ) V_29 ,
V_342 -> V_351 , V_342 -> V_350 ,
V_76 , V_119 ) ;
V_29 += sizeof( struct V_28 ) ;
}
V_45 [ - 1 ] . V_43 |= V_262 ;
V_126 ( V_45 ++ , (struct V_140 * ) V_29 ,
V_342 -> V_351 , 0 , 1 ,
V_76 , V_298 , 8 ) ;
V_29 += sizeof( struct V_140 ) ;
break;
}
for ( V_365 = 0 ; V_365 < V_368 ; V_365 ++ ) {
F_10 ( & V_364 ,
( V_342 -> V_351 + V_365 ) /
V_359 -> V_35 . V_86 ,
( V_342 -> V_351 + V_365 ) %
V_359 -> V_35 . V_86 ) ;
if ( V_366 & 0x01 ) {
V_363 = (struct V_311 * ) V_29 ;
V_29 += sizeof( struct V_311 ) ;
V_363 -> V_23 = V_364 . V_23 ;
V_363 -> V_24 = V_364 . V_24 ;
V_363 -> V_117 = 0 ;
V_363 -> V_16 = 0 ;
V_363 -> V_17 = 8 ;
V_45 [ - 1 ] . V_43 |= V_262 ;
V_45 -> V_54 = V_80 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_363 ;
V_45 ++ ;
}
if ( ( V_366 & ~ 0x08 ) & 0x04 ) {
V_363 = (struct V_311 * ) V_29 ;
V_29 += sizeof( struct V_311 ) ;
V_363 -> V_23 = V_364 . V_23 ;
V_363 -> V_24 = V_364 . V_24 ;
V_363 -> V_117 = 1 ;
V_363 -> V_16 = 0 ;
V_363 -> V_17 = 0 ;
V_45 [ - 1 ] . V_43 |= V_262 ;
V_45 -> V_54 = V_76 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_363 ;
} else {
for ( V_199 = 0 ; V_199 < V_344 ; V_199 ++ ) {
V_363 = (struct V_311 * ) V_29 ;
V_29 += sizeof( struct V_311 ) ;
V_363 -> V_23 = V_364 . V_23 ;
V_363 -> V_24 = V_364 . V_24 ;
V_363 -> V_117 = V_199 + 1 ;
V_363 -> V_16 = 0 ;
V_363 -> V_17 = V_342 -> V_121 ;
if ( ( V_366 & 0x08 ) &&
V_364 . V_23 == 0 && V_364 . V_24 == 0 ) {
if ( V_199 < 3 ) {
V_363 -> V_16 = 4 ;
V_363 -> V_17 = V_147 [ V_199 ] - 4 ;
}
}
if ( ( V_366 & 0x08 ) &&
V_364 . V_23 == 0 && V_364 . V_24 == 1 ) {
V_363 -> V_16 = 44 ;
V_363 -> V_17 = V_148 - 44 ;
}
V_45 [ - 1 ] . V_43 |= V_262 ;
if ( V_199 != 0 || V_365 == 0 )
V_45 -> V_54 =
V_76 ;
else
V_45 -> V_54 =
V_77 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_363 ;
V_45 ++ ;
}
}
}
V_362 -> V_119 = V_119 ;
V_362 -> V_177 = V_119 ;
V_362 -> V_118 = V_298 ;
V_362 -> V_181 = 256 ;
V_362 -> V_179 = V_119 -> V_287 * V_180 ;
V_362 -> V_182 = F_33 () ;
V_362 -> V_183 = V_184 ;
return V_362 ;
}
static struct V_167 *
F_133 ( struct V_30 * V_298 ,
struct V_341 * V_342 , int V_264 ,
int V_225 , struct V_311 * V_343 , int V_344 )
{
struct V_167 * V_369 ;
if ( ! V_343 ) {
V_369 = F_132 ( V_298 , V_342 , V_264 ) ;
} else {
if ( V_225 )
V_369 = F_122 ( V_298 , V_342 ,
V_264 ,
V_343 , V_344 ) ;
else
V_369 = F_131 ( V_298 , V_342 , V_264 ,
V_343 , V_344 ) ;
}
return V_369 ;
}
static int F_134 ( struct V_30 * V_298 ,
struct V_341 * V_342 )
{
struct V_32 * V_33 = V_298 -> V_33 ;
if ( V_342 -> V_351 >=
( V_33 -> V_90 * V_33 -> V_35 . V_86 ) ) {
F_65 ( & V_298 -> V_2 -> V_82 ,
L_69 ,
V_342 -> V_351 ) ;
return - V_128 ;
}
if ( V_342 -> V_350 >=
( V_33 -> V_90 * V_33 -> V_35 . V_86 ) ) {
F_65 ( & V_298 -> V_2 -> V_82 ,
L_70 ,
V_342 -> V_350 ) ;
return - V_128 ;
}
if ( V_342 -> V_351 > V_342 -> V_350 ) {
F_65 ( & V_298 -> V_2 -> V_82 ,
L_71 ,
V_342 -> V_351 ) ;
return - V_128 ;
}
if ( F_113 ( V_342 -> V_121 ) != 0 ) {
F_65 ( & V_298 -> V_2 -> V_82 ,
L_72 ,
V_342 -> V_121 ) ;
return - V_128 ;
}
return 0 ;
}
static int F_135 ( struct V_30 * V_298 ,
struct V_341 * V_342 ,
int V_264 , int V_225 ,
struct V_311 * V_343 , int V_344 ,
struct V_322 * V_322 )
{
struct V_32 * V_33 = V_298 -> V_33 ;
struct V_167 * V_168 , * V_370 ;
struct V_371 V_372 ;
struct V_30 * V_31 ;
char * V_318 = NULL ;
int V_373 , V_374 , V_375 ;
int V_376 , V_377 ;
int V_34 ;
V_34 = F_134 ( V_298 , V_342 ) ;
if ( V_34 )
return V_34 ;
F_136 ( & V_372 ) ;
V_373 = V_342 -> V_351 ;
V_374 = V_342 -> V_350 ;
if ( ! V_225 && V_343 != NULL ) {
V_375 = 1 ;
} else if ( V_225 && V_343 != NULL ) {
V_375 = V_378 / V_344 ;
} else {
V_375 = V_378 /
F_9 ( & V_33 -> V_35 , 0 , V_342 -> V_121 ) ;
}
do {
V_377 = 0 ;
while ( V_342 -> V_351 <= V_374 ) {
V_376 = V_342 -> V_350 - V_342 -> V_351 + 1 ;
if ( V_376 > V_375 ) {
V_342 -> V_350 =
V_342 -> V_351 + V_375 - 1 ;
}
V_168 = F_133 ( V_298 , V_342 ,
V_264 , V_225 ,
V_343 , V_344 ) ;
if ( F_44 ( V_168 ) ) {
V_34 = F_87 ( V_168 ) ;
if ( V_34 == - V_197 ) {
if ( F_137 ( & V_372 ) )
goto V_379;
V_377 = 1 ;
break;
}
goto V_353;
}
F_138 ( & V_168 -> V_380 , & V_372 ) ;
if ( V_343 ) {
V_376 = V_342 -> V_350 - V_342 -> V_351 + 1 ;
V_343 += V_344 * V_376 ;
}
V_342 -> V_351 = V_342 -> V_350 + 1 ;
V_342 -> V_350 = V_374 ;
}
V_34 = F_139 ( & V_372 ) ;
V_353:
F_140 (cqr, n, &format_queue, blocklist) {
V_31 = V_168 -> V_119 ;
V_33 = V_31 -> V_33 ;
if ( V_168 -> V_183 == V_321 ) {
if ( V_343 && V_322 ) {
V_318 = F_107 ( & V_168 -> V_322 ) ;
memcpy ( V_322 , & V_168 -> V_322 , sizeof( * V_322 ) ) ;
}
V_34 = - V_283 ;
}
F_141 ( & V_168 -> V_380 ) ;
F_46 ( V_168 , V_31 ) ;
V_33 -> V_42 -- ;
}
if ( V_34 && V_34 != - V_283 )
goto V_379;
if ( V_34 == - V_283 ) {
if ( V_318 &&
( V_318 [ 1 ] & V_323 ||
V_318 [ 1 ] & V_381 ) )
V_377 = 1 ;
else
goto V_379;
}
} while ( V_377 );
V_379:
V_342 -> V_351 = V_373 ;
V_342 -> V_350 = V_374 ;
return V_34 ;
}
static int F_142 ( struct V_30 * V_298 ,
struct V_341 * V_342 , int V_264 )
{
return F_135 ( V_298 , V_342 , V_264 , 0 , NULL ,
0 , NULL ) ;
}
static int F_143 ( struct V_311 * V_343 , int V_382 ,
int V_383 )
{
int V_24 ;
int V_199 ;
V_24 = V_343 [ V_382 ] . V_24 ;
for ( V_199 = V_382 ; V_199 < V_383 ; V_199 ++ ) {
if ( V_199 > V_382 ) {
if ( ( V_343 [ V_199 ] . V_24 == V_24 &&
V_343 [ V_199 ] . V_117 == 1 ) ||
V_343 [ V_199 ] . V_24 != V_24 ||
V_343 [ V_199 ] . V_117 == 0 )
break;
}
}
return V_199 - V_382 ;
}
static void F_144 ( struct V_311 * V_343 ,
struct V_384 * V_385 ,
int V_386 , int V_387 ,
int V_86 , int V_225 )
{
struct V_21 V_22 ;
int V_388 ;
int V_42 = 0 ;
int V_389 ;
int V_121 ;
int V_213 = 0 ;
int V_199 , V_365 ;
int V_16 ;
V_389 = V_385 -> V_390 . V_350 - V_385 -> V_390 . V_351 + 1 ;
V_388 = V_389 * V_386 ;
for ( V_199 = V_385 -> V_390 . V_351 ; V_199 <= V_385 -> V_390 . V_350 ; V_199 ++ ) {
if ( V_225 ) {
while ( V_343 [ V_213 ] . V_117 == 0 &&
V_343 [ V_213 ] . V_17 == 0 ) {
if ( V_213 ++ > V_388 )
break;
}
} else {
if ( V_199 != V_385 -> V_390 . V_351 )
V_213 += V_386 - V_42 ;
}
F_10 ( & V_22 , V_199 / V_86 , V_199 % V_86 ) ;
V_42 = F_143 ( V_343 , V_213 , V_213 + V_386 ) ;
if ( V_42 < V_387 ) {
V_385 -> V_391 = V_392 ;
break;
}
if ( V_42 > V_387 ) {
V_385 -> V_391 = V_393 ;
break;
}
for ( V_365 = 0 ; V_365 < V_42 ; V_365 ++ , V_213 ++ ) {
V_121 = V_385 -> V_390 . V_121 ;
V_16 = 0 ;
if ( ( V_385 -> V_390 . V_366 & 0x08 ) &&
V_22 . V_23 == 0 && V_22 . V_24 == 0 ) {
if ( V_365 < 3 ) {
V_121 = V_147 [ V_365 ] - 4 ;
V_16 = 4 ;
}
}
if ( ( V_385 -> V_390 . V_366 & 0x08 ) &&
V_22 . V_23 == 0 && V_22 . V_24 == 1 ) {
V_121 = V_148 - 44 ;
V_16 = 44 ;
}
if ( V_343 [ V_213 ] . V_17 != V_121 ) {
V_385 -> V_391 = V_394 ;
goto V_379;
}
if ( V_343 [ V_213 ] . V_16 != V_16 ) {
V_385 -> V_391 = V_395 ;
goto V_379;
}
if ( V_343 [ V_213 ] . V_23 != V_22 . V_23 ||
V_343 [ V_213 ] . V_24 != V_22 . V_24 ||
V_343 [ V_213 ] . V_117 != ( V_365 + 1 ) ) {
V_385 -> V_391 = V_396 ;
goto V_379;
}
}
}
V_379:
if ( ! V_385 -> V_391 ) {
V_199 -- ;
V_213 -- ;
}
V_385 -> V_397 = V_199 ;
V_385 -> V_398 = V_42 ;
V_385 -> V_399 = V_343 [ V_213 ] . V_117 ;
V_385 -> V_121 = V_343 [ V_213 ] . V_17 ;
V_385 -> V_400 = V_343 [ V_213 ] . V_16 ;
}
static int F_145 ( struct V_30 * V_298 ,
struct V_384 * V_385 ,
int V_264 )
{
struct V_32 * V_33 = V_298 -> V_33 ;
struct V_311 * V_343 ;
struct V_322 V_322 ;
int V_386 , V_387 ;
int V_401 ;
int V_86 ;
int V_389 ;
int V_225 = 0 ;
int V_34 ;
V_86 = V_33 -> V_35 . V_86 ;
V_386 = F_9 ( & V_33 -> V_35 , 0 , 512 ) + 1 ;
V_387 = F_9 ( & V_33 -> V_35 , 0 , V_385 -> V_390 . V_121 ) ;
V_389 = V_385 -> V_390 . V_350 - V_385 -> V_390 . V_351 + 1 ;
V_401 = V_389 * V_386 * sizeof( struct V_311 ) ;
V_343 = F_42 ( V_401 , V_195 | V_196 ) ;
if ( ! V_343 )
return - V_197 ;
if ( ( V_33 -> V_231 . V_232 [ 40 ] & 0x04 ) &&
V_401 <= V_33 -> V_234 )
V_225 = 1 ;
V_34 = F_135 ( V_298 , & V_385 -> V_390 , V_264 ,
V_225 , V_343 , V_386 , & V_322 ) ;
if ( V_34 && V_34 != - V_283 )
goto V_379;
if ( V_34 == - V_283 ) {
if ( V_225 && F_146 ( & V_322 . V_402 ) == 0x40 ) {
V_225 = 0 ;
V_34 = F_135 ( V_298 , & V_385 -> V_390 ,
V_264 , V_225 ,
V_343 , V_386 ,
& V_322 ) ;
if ( V_34 )
goto V_379;
} else {
goto V_379;
}
}
F_144 ( V_343 , V_385 , V_386 , V_387 ,
V_86 , V_225 ) ;
V_379:
F_47 ( V_343 ) ;
return V_34 ;
}
static void F_147 ( struct V_167 * V_168 )
{
if ( V_168 -> V_181 < 0 ) {
V_168 -> V_183 = V_321 ;
return;
}
V_168 -> V_183 = V_184 ;
if ( V_168 -> V_178 && ( V_168 -> V_119 != V_168 -> V_178 -> V_298 ) ) {
F_148 ( V_168 ) ;
V_168 -> V_119 = V_168 -> V_178 -> V_298 ;
V_168 -> V_170 = F_60 ( V_168 -> V_178 -> V_298 ) ;
}
}
static T_5
F_149 ( struct V_167 * V_168 )
{
struct V_30 * V_31 = (struct V_30 * ) V_168 -> V_119 ;
struct V_1 * V_2 = V_31 -> V_2 ;
switch ( V_2 -> V_403 . V_84 ) {
case 0x3990 :
case 0x2105 :
case 0x2107 :
case 0x1750 :
return V_404 ;
case 0x9343 :
case 0x3880 :
default:
return V_405 ;
}
}
static T_5
F_150 ( struct V_167 * V_168 )
{
return V_406 ;
}
static void F_151 ( struct V_30 * V_31 ,
struct V_167 * V_168 ,
struct V_322 * V_322 )
{
char V_65 ;
char * V_318 = NULL ;
struct V_32 * V_33 = V_31 -> V_33 ;
V_65 = V_407 | V_408 | V_409 ;
if ( ( F_152 ( & V_322 -> V_402 ) & V_65 ) == V_65 ) {
if ( ! V_31 -> V_178 && V_33 -> V_410 &&
V_31 -> V_275 == V_276 &&
! F_70 ( V_274 , & V_31 -> V_43 ) &&
! F_70 ( V_246 , & V_31 -> V_43 ) ) {
F_153 ( V_31 ) ;
}
F_154 ( V_31 ) ;
return;
}
V_318 = F_107 ( V_322 ) ;
if ( ! V_318 )
return;
if ( ( V_318 [ 27 ] & V_411 ) && ( V_318 [ 7 ] == 0x0D ) &&
( F_152 ( & V_322 -> V_402 ) & V_412 ) ) {
if ( F_72 ( V_413 , & V_31 -> V_43 ) ) {
F_18 ( V_7 , V_31 , L_1 ,
L_73 ) ;
return;
}
V_318 = F_107 ( V_322 ) ;
if ( ! V_318 ) {
F_18 ( V_7 , V_31 , L_1 ,
L_74 ) ;
F_39 ( V_413 , & V_31 -> V_43 ) ;
return;
}
V_33 -> V_414 = V_318 [ 8 ] ;
F_18 ( V_415 , V_31 , L_75 ,
L_76 ,
V_33 -> V_414 ) ;
F_81 ( V_31 ) ;
if ( ! F_71 ( & V_31 -> V_281 ) )
F_75 ( V_31 ) ;
return;
}
if ( ! V_168 && ! ( V_318 [ 27 ] & V_411 ) &&
( ( V_318 [ 6 ] & V_416 ) == V_416 ) ) {
F_155 ( V_31 , V_318 ) ;
return;
}
if ( V_31 -> V_178 && ( V_318 [ 27 ] & V_411 ) &&
( V_318 [ 7 ] == 0x3F ) &&
( F_152 ( & V_322 -> V_402 ) & V_412 ) &&
F_70 ( V_417 , & V_31 -> V_43 ) ) {
if ( V_31 -> V_231 & V_418 )
F_34 ( V_419 , & V_31 -> V_43 ) ;
F_39 ( V_417 , & V_31 -> V_43 ) ;
F_15 ( & V_31 -> V_2 -> V_82 ,
L_77 ) ;
}
}
static struct V_167 * F_156 (
struct V_30 * V_119 ,
struct V_277 * V_178 ,
struct V_420 * V_421 ,
T_6 V_422 ,
T_6 V_423 ,
T_6 V_424 ,
T_6 V_425 ,
unsigned int V_426 ,
unsigned int V_427 ,
unsigned int V_145 ,
unsigned int V_121 )
{
struct V_32 * V_33 ;
unsigned long * V_428 ;
struct V_140 * V_313 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
struct V_429 V_430 ;
struct V_431 V_432 ;
char * V_433 ;
unsigned int V_434 ;
int V_42 , V_435 , V_314 , V_315 ;
T_6 V_146 ;
unsigned char V_48 , V_436 ;
int V_360 ;
struct V_30 * V_118 ;
V_118 = V_178 -> V_298 ;
V_33 = V_118 -> V_33 ;
if ( F_157 ( V_421 ) == V_437 )
V_48 = V_60 ;
else if ( F_157 ( V_421 ) == V_438 )
V_48 = V_73 ;
else
return F_130 ( - V_128 ) ;
V_42 = 0 ;
V_435 = 0 ;
F_158 (bv, req, iter) {
if ( V_432 . V_439 & ( V_121 - 1 ) )
return F_130 ( - V_128 ) ;
V_42 += V_432 . V_439 >> ( V_178 -> V_331 + 9 ) ;
if ( F_159 ( F_160 ( V_432 . V_440 ) , V_432 . V_439 ) )
V_435 += V_432 . V_439 >> ( V_178 -> V_331 + 9 ) ;
}
if ( V_42 != V_423 - V_422 + 1 )
return F_130 ( - V_128 ) ;
V_360 = V_33 -> V_231 . V_232 [ 8 ] & 0x01 ;
if ( V_360 ) {
V_314 = 2 + V_42 ;
V_315 = sizeof( struct V_93 ) +
sizeof( struct V_140 ) +
V_435 * sizeof( unsigned long ) ;
} else {
V_314 = 2 + V_42 ;
V_315 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
V_435 * sizeof( unsigned long ) ;
}
if ( V_33 -> V_85 && V_422 < 2 * V_145 ) {
if ( V_423 >= 2 * V_145 )
V_42 = 2 * V_145 - V_422 ;
V_314 += V_42 ;
V_315 += V_42 * sizeof( struct V_140 ) ;
}
V_168 = F_43 ( V_176 , V_314 , V_315 ,
V_119 ) ;
if ( F_44 ( V_168 ) )
return V_168 ;
V_45 = V_168 -> V_171 ;
if ( V_360 ) {
if ( F_21 ( V_45 ++ , V_168 -> V_29 , V_424 ,
V_425 , V_48 , V_118 , V_119 ) == - V_249 ) {
F_46 ( V_168 , V_119 ) ;
return F_130 ( - V_249 ) ;
}
V_428 = ( unsigned long * ) ( V_168 -> V_29 +
sizeof( struct V_93 ) ) ;
} else {
if ( F_13 ( V_45 ++ , V_168 -> V_29 , V_424 ,
V_425 , V_48 , V_118 ) == - V_249 ) {
F_46 ( V_168 , V_119 ) ;
return F_130 ( - V_249 ) ;
}
V_428 = ( unsigned long * ) ( V_168 -> V_29 +
sizeof( struct V_28 ) ) ;
}
V_313 = (struct V_140 * ) ( V_428 + V_435 ) ;
V_146 = V_422 ;
if ( V_33 -> V_85 == 0 || V_146 > 2 * V_145 ) {
V_45 [ - 1 ] . V_43 |= V_262 ;
V_126 ( V_45 ++ , V_313 ++ , V_424 , V_426 + 1 ,
V_423 - V_146 + 1 , V_48 , V_118 , V_121 ) ;
}
F_158 (bv, req, iter) {
V_433 = F_160 ( V_432 . V_440 ) + V_432 . V_441 ;
if ( V_442 ) {
char * V_443 = F_161 ( V_442 ,
V_196 | V_444 ) ;
if ( V_443 && F_157 ( V_421 ) == V_438 )
memcpy ( V_443 + V_432 . V_441 , V_433 , V_432 . V_439 ) ;
if ( V_443 )
V_433 = V_443 + V_432 . V_441 ;
}
for ( V_434 = 0 ; V_434 < V_432 . V_439 ; V_434 += V_121 ) {
T_6 V_445 = V_146 ;
unsigned int V_446 = F_162 ( V_445 , V_145 ) ;
V_436 = V_48 ;
V_42 = V_121 ;
if ( V_33 -> V_85 && V_146 < 2 * V_145 ) {
if ( F_22 ( V_145 , V_146 ) ) {
V_436 |= 0x8 ;
V_42 = F_23 ( V_146 ) ;
if ( V_42 < V_121 &&
F_157 ( V_421 ) == V_437 )
memset ( V_433 + V_42 , 0xe5 ,
V_121 - V_42 ) ;
}
V_45 [ - 1 ] . V_43 |= V_262 ;
V_126 ( V_45 ++ , V_313 ++ ,
V_445 , V_446 + 1 ,
1 , V_436 , V_118 , V_42 ) ;
}
if ( V_33 -> V_85 && V_146 == 2 * V_145 ) {
V_45 [ - 1 ] . V_43 |= V_262 ;
V_126 ( V_45 ++ , V_313 ++ ,
V_445 , V_446 + 1 ,
V_423 - V_146 + 1 ,
V_48 , V_118 , V_42 ) ;
}
V_45 [ - 1 ] . V_43 |= V_262 ;
V_45 -> V_54 = V_436 ;
V_45 -> V_42 = V_42 ;
if ( F_159 ( V_433 , V_121 ) ) {
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_428 ;
V_45 -> V_43 = V_447 ;
V_428 = F_163 ( V_428 , V_433 , V_121 ) ;
} else {
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_433 ;
V_45 -> V_43 = 0 ;
}
V_45 ++ ;
V_433 += V_121 ;
V_146 ++ ;
}
}
if ( F_164 ( V_421 ) ||
V_178 -> V_298 -> V_231 & V_448 )
F_34 ( V_273 , & V_168 -> V_43 ) ;
V_168 -> V_119 = V_119 ;
V_168 -> V_177 = V_119 ;
V_168 -> V_178 = V_178 ;
V_168 -> V_179 = V_119 -> V_287 * V_180 ;
V_168 -> V_170 = F_165 ( V_119 ) ;
V_168 -> V_181 = V_119 -> V_289 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
return V_168 ;
}
static struct V_167 * F_166 (
struct V_30 * V_119 ,
struct V_277 * V_178 ,
struct V_420 * V_421 ,
T_6 V_422 ,
T_6 V_423 ,
T_6 V_424 ,
T_6 V_425 ,
unsigned int V_426 ,
unsigned int V_427 ,
unsigned int V_145 ,
unsigned int V_121 )
{
unsigned long * V_428 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
struct V_429 V_430 ;
struct V_431 V_432 ;
char * V_433 , * V_449 ;
unsigned int V_435 , V_314 , V_315 ;
unsigned int V_100 ;
T_6 V_146 ;
unsigned char V_48 ;
struct V_30 * V_118 ;
unsigned int V_389 , V_42 , V_450 ;
unsigned int V_451 , V_452 , V_453 , V_454 ;
unsigned char V_455 , V_456 ;
T_6 V_445 ;
unsigned int V_446 ;
V_118 = V_178 -> V_298 ;
if ( F_157 ( V_421 ) == V_437 )
V_48 = V_113 ;
else if ( F_157 ( V_421 ) == V_438 )
V_48 = V_111 ;
else
return F_130 ( - V_128 ) ;
V_435 = V_423 - V_422 + 1 ;
V_389 = V_425 - V_424 + 1 ;
V_314 = 1 + V_389 ;
V_315 = sizeof( struct V_93 ) +
V_435 * sizeof( unsigned long long ) ;
V_168 = F_43 ( V_176 , V_314 , V_315 ,
V_119 ) ;
if ( F_44 ( V_168 ) )
return V_168 ;
V_45 = V_168 -> V_171 ;
if ( V_424 == V_425 )
V_100 = V_427 - V_426 + 1 ;
else
V_100 = V_427 + 1 ;
V_100 *= V_121 ;
if ( F_20 ( V_45 ++ , V_168 -> V_29 , V_424 ,
V_425 , V_48 , V_118 , V_119 ,
1 , V_426 + 1 ,
V_389 , V_121 ,
V_100 ) == - V_249 ) {
F_46 ( V_168 , V_119 ) ;
return F_130 ( - V_249 ) ;
}
V_428 = ( unsigned long * ) ( V_168 -> V_29 + sizeof( struct V_93 ) ) ;
V_146 = V_422 ;
V_455 = 1 ;
V_456 = 0 ;
V_454 = 0 ;
V_449 = NULL ;
V_451 = 0 ;
F_158 (bv, req, iter) {
V_433 = F_160 ( V_432 . V_440 ) + V_432 . V_441 ;
V_452 = V_432 . V_439 ;
while ( V_452 ) {
if ( V_455 ) {
V_445 = V_146 ;
V_446 = F_162 ( V_445 , V_145 ) ;
V_450 = V_145 - V_446 ;
V_42 = F_167 ( ( V_423 - V_146 + 1 ) ,
( T_6 ) V_450 ) ;
V_454 = V_42 * V_121 ;
V_45 [ - 1 ] . V_43 |= V_262 ;
V_45 -> V_54 = V_48 ;
V_45 -> V_42 = V_454 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_428 ;
V_45 -> V_43 = V_447 ;
V_45 ++ ;
V_146 += V_42 ;
V_455 = 0 ;
if ( ! V_449 )
V_449 = V_433 ;
}
if ( ! V_449 ) {
if ( F_14 ( V_433 ) & ( V_457 - 1 ) ) {
F_46 ( V_168 , V_119 ) ;
return F_130 ( - V_458 ) ;
} else
V_449 = V_433 ;
}
if ( ( V_449 + V_451 ) != V_433 ) {
F_46 ( V_168 , V_119 ) ;
return F_130 ( - V_458 ) ;
}
V_453 = F_167 ( V_452 , V_454 ) ;
V_452 -= V_453 ;
V_433 += V_453 ;
V_451 += V_453 ;
V_454 -= V_453 ;
if ( ! ( F_14 ( V_449 + V_451 ) & ( V_457 - 1 ) ) )
V_456 = 1 ;
if ( ! V_454 ) {
V_455 = 1 ;
V_456 = 1 ;
}
if ( V_456 ) {
V_428 = F_163 ( V_428 , V_449 ,
V_451 ) ;
V_449 = NULL ;
V_451 = 0 ;
V_456 = 0 ;
}
}
}
if ( F_164 ( V_421 ) ||
V_178 -> V_298 -> V_231 & V_448 )
F_34 ( V_273 , & V_168 -> V_43 ) ;
V_168 -> V_119 = V_119 ;
V_168 -> V_177 = V_119 ;
V_168 -> V_178 = V_178 ;
V_168 -> V_179 = V_119 -> V_287 * V_180 ;
V_168 -> V_170 = F_165 ( V_119 ) ;
V_168 -> V_181 = V_119 -> V_289 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
return V_168 ;
}
static int F_127 ( struct V_348 * V_348 ,
unsigned int V_46 , unsigned int V_47 , int V_48 ,
struct V_30 * V_118 ,
struct V_30 * V_119 ,
unsigned int V_98 , int V_42 ,
unsigned int V_121 ,
unsigned int V_459 ,
unsigned int V_100 ,
unsigned int V_145 )
{
struct V_93 V_94 ;
struct V_32 * V_122 , * V_123 ;
struct V_28 * V_124 ;
struct V_97 * V_125 ;
struct V_460 * V_460 ;
T_3 V_49 , V_50 ;
T_4 V_51 , V_52 , V_53 ;
T_7 V_461 ;
int V_34 = 0 ;
int V_101 = 0 ;
int V_18 , V_102 ;
V_122 = V_118 -> V_33 ;
V_123 = V_119 -> V_33 ;
V_124 = & V_94 . F_13 ;
V_125 = & V_94 . V_126 ;
memset ( & V_94 , 0 , sizeof( V_94 ) ) ;
V_94 . V_120 = 1 ;
V_94 . V_129 = V_122 -> V_130 -> V_131 ;
V_94 . V_132 = V_122 -> V_130 -> V_133 ;
V_94 . V_95 . F_13 = 1 ;
if ( V_123 -> V_134 . type != V_135 ) {
V_94 . V_95 . V_136 = 1 ;
if ( V_123 -> V_134 . type == V_137 )
V_94 . V_95 . V_138 = 1 ;
}
switch ( V_48 ) {
case V_113 :
V_124 -> V_65 . V_66 = 0x1 ;
V_124 -> V_67 . V_68 = V_122 -> V_69 . V_68 ;
V_124 -> V_139 = V_121 ;
V_124 -> V_38 |= 0x42 ;
V_125 -> V_68 . V_103 = 0x0 ;
V_125 -> V_68 . V_68 = 0x0C ;
V_125 -> V_104 . V_462 = 0x01 ;
V_461 = V_463 ;
break;
case V_111 :
V_124 -> V_65 . V_66 = 0x02 ;
V_124 -> V_67 . V_68 = V_122 -> V_69 . V_68 ;
V_124 -> V_139 = V_121 ;
V_34 = F_16 ( & V_94 , V_118 ) ;
V_124 -> V_38 |= 0x42 ;
V_125 -> V_68 . V_103 = 0x0 ;
V_125 -> V_68 . V_68 = 0x3F ;
V_125 -> V_108 = 0x23 ;
V_125 -> V_104 . V_462 = 0x2 ;
V_461 = V_127 ;
break;
case V_354 :
V_124 -> V_65 . V_66 = 0x1 ;
V_124 -> V_67 . V_68 = V_71 ;
V_124 -> V_38 |= 0x42 ;
V_124 -> V_139 = V_121 ;
V_125 -> V_68 . V_103 = 0x2 ;
V_125 -> V_68 . V_68 = 0x16 ;
V_125 -> V_104 . V_462 = 0x01 ;
V_461 = V_463 ;
break;
default:
F_18 ( V_114 , V_118 ,
L_78 , V_48 ) ;
F_19 () ;
break;
}
if ( V_34 )
return V_34 ;
V_124 -> V_67 . V_83 = 0x3 ;
V_51 = V_122 -> V_35 . V_86 ;
V_49 = V_46 / V_51 ;
V_52 = V_46 % V_51 ;
V_50 = V_47 / V_51 ;
V_53 = V_47 % V_51 ;
if ( V_124 -> V_67 . V_68 == V_87 ||
V_124 -> V_67 . V_68 == V_88 ) {
if ( V_50 + V_122 -> V_69 . V_89 < V_122 -> V_90 )
V_50 += V_122 -> V_69 . V_89 ;
else
V_50 = ( V_122 -> V_90 - 1 ) ;
}
F_10 ( & V_124 -> V_91 , V_49 , V_52 ) ;
F_10 ( & V_124 -> V_92 , V_50 , V_53 ) ;
V_124 -> V_464 = 0x20 ;
V_124 -> V_465 = V_145 ;
if ( V_98 ) {
switch ( V_122 -> V_35 . V_20 ) {
case 0x3390 :
V_18 = F_8 ( V_121 + 6 , 232 ) ;
V_102 = 9 + F_8 ( V_121 + 6 * ( V_18 + 1 ) , 34 ) ;
V_101 = ( 49 + ( V_98 - 1 ) * ( 10 + V_102 ) ) / 8 ;
break;
case 0x3380 :
V_102 = 7 + F_8 ( V_121 + 12 , 32 ) ;
V_101 = ( 39 + ( V_98 - 1 ) * ( 8 + V_102 ) ) / 7 ;
break;
}
}
if ( V_48 == V_354 ) {
V_125 -> V_104 . V_105 = 0 ;
V_125 -> V_104 . V_466 = 0 ;
V_125 -> V_101 = 0xff ;
} else {
V_125 -> V_104 . V_105 = 1 ;
V_125 -> V_104 . V_466 = 1 ;
V_125 -> V_101 = V_101 ;
}
V_125 -> V_104 . V_467 = 1 ;
V_125 -> V_106 = V_100 ;
V_125 -> V_468 = V_48 ;
V_125 -> V_42 = V_42 ;
F_10 ( & V_125 -> V_115 , V_49 , V_52 ) ;
V_125 -> V_116 . V_23 = V_125 -> V_115 . V_23 ;
V_125 -> V_116 . V_24 = V_125 -> V_115 . V_24 ;
V_125 -> V_116 . V_117 = V_98 ;
V_460 = F_168 ( V_348 , V_461 , 0 ,
& V_94 , sizeof( V_94 ) , V_459 ) ;
return F_169 ( V_460 ) ;
}
static struct V_167 * F_170 (
struct V_30 * V_119 ,
struct V_277 * V_178 ,
struct V_420 * V_421 ,
T_6 V_422 ,
T_6 V_423 ,
T_6 V_424 ,
T_6 V_425 ,
unsigned int V_426 ,
unsigned int V_427 ,
unsigned int V_145 ,
unsigned int V_121 )
{
struct V_167 * V_168 ;
struct V_429 V_430 ;
struct V_431 V_432 ;
char * V_433 ;
unsigned int V_389 , V_469 ;
unsigned char V_48 ;
struct V_30 * V_118 ;
unsigned int V_100 ;
struct V_348 * V_348 ;
struct V_346 * V_347 = NULL ;
int V_470 ;
T_8 V_349 ;
T_7 V_471 ;
unsigned int V_452 , V_453 , V_454 ;
unsigned char V_455 ;
T_6 V_146 , V_445 ;
unsigned int V_472 ;
unsigned int V_42 , V_450 ;
int V_3 ;
V_118 = V_178 -> V_298 ;
if ( F_157 ( V_421 ) == V_437 ) {
V_48 = V_113 ;
V_470 = V_352 ;
} else if ( F_157 ( V_421 ) == V_438 ) {
V_48 = V_111 ;
V_470 = V_473 ;
} else
return F_130 ( - V_128 ) ;
V_389 = V_425 - V_424 + 1 ;
V_469 = 0 ;
F_158 (bv, req, iter) {
++ V_469 ;
}
if ( F_157 ( V_421 ) == V_438 )
V_469 += ( V_425 - V_424 ) ;
V_349 = F_124 ( 0 , V_469 , 0 ) ;
V_168 = F_43 ( V_176 , 0 , V_349 , V_119 ) ;
if ( F_44 ( V_168 ) )
return V_168 ;
if ( V_424 == V_425 )
V_100 = V_427 - V_426 + 1 ;
else
V_100 = V_427 + 1 ;
V_100 *= V_121 ;
V_348 = F_125 ( V_168 -> V_29 , V_349 , V_470 , 0 , V_469 , 0 ) ;
if ( F_44 ( V_348 ) ) {
V_3 = - V_128 ;
goto V_194;
}
V_168 -> V_171 = F_126 ( V_348 ) ;
if ( F_127 ( V_348 , V_424 , V_425 ,
V_48 , V_118 , V_119 ,
V_426 + 1 ,
V_389 , V_121 ,
( V_423 - V_422 + 1 ) * V_121 ,
V_100 , V_145 ) == - V_249 ) {
V_3 = - V_249 ;
goto V_194;
}
V_454 = 0 ;
if ( F_157 ( V_421 ) == V_438 ) {
V_455 = 1 ;
V_146 = V_422 ;
F_158 (bv, req, iter) {
V_433 = F_160 ( V_432 . V_440 ) + V_432 . V_441 ;
V_452 = V_432 . V_439 ;
while ( V_452 ) {
if ( V_455 ) {
V_445 = V_146 ;
V_472 = F_162 ( V_445 , V_145 ) ;
V_450 = V_145 - V_472 ;
V_42 = F_167 ( ( V_423 - V_146 + 1 ) ,
( T_6 ) V_450 ) ;
V_454 = V_42 * V_121 ;
V_146 += V_42 ;
V_455 = 0 ;
}
V_453 = F_167 ( V_452 , V_454 ) ;
V_452 -= V_453 ;
V_454 -= V_453 ;
if ( ! V_454 ) {
V_455 = 1 ;
V_471 = V_474 ;
} else
V_471 = 0 ;
V_347 = F_128 ( V_348 , V_471 ,
V_433 , V_453 ) ;
if ( F_44 ( V_347 ) ) {
V_3 = - V_128 ;
goto V_194;
}
V_433 += V_453 ;
}
}
} else {
F_158 (bv, req, iter) {
V_433 = F_160 ( V_432 . V_440 ) + V_432 . V_441 ;
V_347 = F_128 ( V_348 , 0x00 ,
V_433 , V_432 . V_439 ) ;
if ( F_44 ( V_347 ) ) {
V_3 = - V_128 ;
goto V_194;
}
}
}
V_347 -> V_43 |= V_355 ;
V_347 -> V_43 &= ~ V_474 ;
F_129 ( V_348 ) ;
if ( F_164 ( V_421 ) ||
V_178 -> V_298 -> V_231 & V_448 )
F_34 ( V_273 , & V_168 -> V_43 ) ;
V_168 -> V_356 = 1 ;
V_168 -> V_119 = V_119 ;
V_168 -> V_177 = V_119 ;
V_168 -> V_178 = V_178 ;
V_168 -> V_179 = V_119 -> V_287 * V_180 ;
V_168 -> V_170 = F_165 ( V_119 ) ;
V_168 -> V_181 = V_119 -> V_289 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
return V_168 ;
V_194:
F_46 ( V_168 , V_119 ) ;
return F_130 ( V_3 ) ;
}
static struct V_167 * F_171 ( struct V_30 * V_119 ,
struct V_277 * V_178 ,
struct V_420 * V_421 )
{
int V_475 , V_476 ;
int V_360 ;
int V_477 ;
struct V_32 * V_33 ;
struct V_30 * V_118 ;
T_6 V_422 , V_423 ;
T_6 V_424 , V_425 ;
unsigned int V_426 , V_427 ;
unsigned int V_145 , V_121 ;
int V_478 ;
unsigned int V_479 ;
struct V_167 * V_168 ;
V_118 = V_178 -> V_298 ;
V_33 = V_118 -> V_33 ;
V_121 = V_178 -> V_328 ;
V_145 = F_9 ( & V_33 -> V_35 , 0 , V_121 ) ;
if ( V_145 == 0 )
return F_130 ( - V_128 ) ;
V_422 = V_424 = F_172 ( V_421 ) >> V_178 -> V_331 ;
V_426 = F_162 ( V_424 , V_145 ) ;
V_423 = V_425 =
( F_172 ( V_421 ) + F_173 ( V_421 ) - 1 ) >> V_178 -> V_331 ;
V_427 = F_162 ( V_425 , V_145 ) ;
V_478 = ( V_33 -> V_85 && V_422 < 2 * V_145 ) ;
V_477 = V_33 -> V_231 . V_232 [ 40 ] & 0x20 ;
V_479 = F_174 ( V_421 ) ;
if ( V_479 % V_121 )
return F_130 ( - V_128 ) ;
if ( F_157 ( V_421 ) == V_438 )
V_479 += ( V_425 - V_424 ) * 4 ;
V_475 = V_33 -> V_231 . V_232 [ 9 ] & 0x20 ;
V_476 = V_33 -> V_231 . V_232 [ 12 ] & 0x40 ;
V_360 = V_33 -> V_231 . V_232 [ 8 ] & 0x01 ;
V_168 = NULL ;
if ( V_478 || V_442 ) {
} else if ( ( V_479 <= V_33 -> V_234 )
&& ( V_477 || ( V_424 == V_425 ) ) ) {
V_168 = F_170 ( V_119 , V_178 , V_421 ,
V_422 , V_423 ,
V_424 , V_425 ,
V_426 , V_427 ,
V_145 , V_121 ) ;
if ( F_44 ( V_168 ) && ( F_87 ( V_168 ) != - V_249 ) &&
( F_87 ( V_168 ) != - V_197 ) )
V_168 = NULL ;
} else if ( V_360 &&
( ( ( F_157 ( V_421 ) == V_437 ) && V_475 ) ||
( ( F_157 ( V_421 ) == V_438 ) && V_476 ) ) ) {
V_168 = F_166 ( V_119 , V_178 , V_421 ,
V_422 , V_423 ,
V_424 , V_425 ,
V_426 , V_427 ,
V_145 , V_121 ) ;
if ( F_44 ( V_168 ) && ( F_87 ( V_168 ) != - V_249 ) &&
( F_87 ( V_168 ) != - V_197 ) )
V_168 = NULL ;
}
if ( ! V_168 )
V_168 = F_156 ( V_119 , V_178 , V_421 ,
V_422 , V_423 ,
V_424 , V_425 ,
V_426 , V_427 ,
V_145 , V_121 ) ;
return V_168 ;
}
static struct V_167 * F_175 ( struct V_30 * V_119 ,
struct V_277 * V_178 ,
struct V_420 * V_421 )
{
unsigned long * V_428 ;
struct V_30 * V_118 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
struct V_429 V_430 ;
struct V_431 V_432 ;
char * V_433 ;
unsigned char V_48 ;
unsigned int V_389 ;
unsigned int V_452 , V_454 ;
unsigned int V_426 ;
unsigned int V_435 , V_314 , V_315 ;
T_6 V_424 , V_425 , V_339 ;
T_6 V_480 , V_481 , V_482 ;
unsigned int V_483 ;
V_480 = F_172 ( V_421 ) % V_484 ;
V_481 = ( F_172 ( V_421 ) + F_173 ( V_421 ) ) %
V_484 ;
V_482 = ( V_484 - V_481 ) %
V_484 ;
V_118 = V_178 -> V_298 ;
if ( ( V_480 || V_482 ) &&
( F_157 ( V_421 ) == V_438 ) ) {
F_18 ( V_114 , V_118 ,
L_79 ,
V_480 , V_482 , V_421 ) ;
V_168 = F_130 ( - V_128 ) ;
goto V_379;
}
V_424 = F_172 ( V_421 ) / V_484 ;
V_425 = ( F_172 ( V_421 ) + F_173 ( V_421 ) - 1 ) /
V_484 ;
V_389 = V_425 - V_424 + 1 ;
V_426 = 0 ;
if ( F_157 ( V_421 ) == V_437 )
V_48 = V_112 ;
else if ( F_157 ( V_421 ) == V_438 )
V_48 = V_107 ;
else {
V_168 = F_130 ( - V_128 ) ;
goto V_379;
}
V_435 = V_389 * V_330 ;
V_314 = 1 + V_389 ;
V_483 = sizeof( struct V_93 ) + 8 ;
V_315 = V_483 + V_435 * sizeof( unsigned long long ) ;
V_168 = F_43 ( V_176 , V_314 ,
V_315 , V_119 ) ;
if ( F_44 ( V_168 ) )
goto V_379;
V_45 = V_168 -> V_171 ;
if ( F_20 ( V_45 ++ , V_168 -> V_29 , V_424 , V_425 , V_48 ,
V_118 , V_119 , 1 , V_426 + 1 ,
V_389 , 0 , 0 ) == - V_249 ) {
F_46 ( V_168 , V_119 ) ;
V_168 = F_130 ( - V_249 ) ;
goto V_379;
}
V_428 = ( unsigned long * ) ( V_168 -> V_29 + V_483 ) ;
V_454 = 0 ;
if ( V_480 ) {
V_45 [ - 1 ] . V_43 |= V_262 ;
V_45 -> V_54 = V_48 ;
V_45 -> V_42 = 57326 ;
V_454 = 65536 - V_480 * 512 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_428 ;
V_45 -> V_43 |= V_447 ;
V_45 -> V_43 |= V_44 ;
V_45 ++ ;
for ( V_339 = 0 ; V_339 < V_480 ; V_339 += 8 )
V_428 = F_163 ( V_428 , V_485 , V_486 ) ;
}
F_158 (bv, req, iter) {
V_433 = F_160 ( V_432 . V_440 ) + V_432 . V_441 ;
V_452 = V_432 . V_439 ;
if ( V_48 == V_112 )
memset ( V_433 , 0 , V_452 ) ;
if ( ! V_454 ) {
V_45 [ - 1 ] . V_43 |= V_262 ;
V_45 -> V_54 = V_48 ;
V_45 -> V_42 = 57326 ;
V_454 = 65536 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_428 ;
V_45 -> V_43 |= V_447 ;
V_45 -> V_43 |= V_44 ;
V_45 ++ ;
}
V_454 -= V_452 ;
V_428 = F_163 ( V_428 , V_433 , V_452 ) ;
}
for ( V_339 = 0 ; V_339 < V_482 ; V_339 += 8 )
V_428 = F_163 ( V_428 , V_485 , V_486 ) ;
if ( F_164 ( V_421 ) ||
V_178 -> V_298 -> V_231 & V_448 )
F_34 ( V_273 , & V_168 -> V_43 ) ;
V_168 -> V_119 = V_119 ;
V_168 -> V_177 = V_119 ;
V_168 -> V_178 = V_178 ;
V_168 -> V_179 = V_119 -> V_287 * V_180 ;
V_168 -> V_170 = F_165 ( V_119 ) ;
V_168 -> V_181 = V_119 -> V_289 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
if ( F_44 ( V_168 ) && F_87 ( V_168 ) != - V_249 )
V_168 = NULL ;
V_379:
return V_168 ;
}
static int
F_176 ( struct V_167 * V_168 , struct V_420 * V_421 )
{
struct V_32 * V_33 ;
struct V_26 * V_45 ;
struct V_429 V_430 ;
struct V_431 V_432 ;
char * V_433 , * V_56 ;
unsigned int V_121 , V_145 , V_434 ;
T_6 V_146 ;
int V_183 ;
if ( ! V_442 )
goto V_379;
V_33 = V_168 -> V_178 -> V_298 -> V_33 ;
V_121 = V_168 -> V_178 -> V_328 ;
V_145 = F_9 ( & V_33 -> V_35 , 0 , V_121 ) ;
V_146 = F_172 ( V_421 ) >> V_168 -> V_178 -> V_331 ;
V_45 = V_168 -> V_171 ;
V_45 ++ ;
if ( V_33 -> V_85 == 0 || V_146 > 2 * V_145 )
V_45 ++ ;
F_158 (bv, req, iter) {
V_433 = F_160 ( V_432 . V_440 ) + V_432 . V_441 ;
for ( V_434 = 0 ; V_434 < V_432 . V_439 ; V_434 += V_121 ) {
if ( V_33 -> V_85 && V_146 <= 2 * V_145 )
V_45 ++ ;
if ( V_433 ) {
if ( V_45 -> V_43 & V_447 )
V_56 = * ( ( char * * ) ( ( V_173 ) V_45 -> V_56 ) ) ;
else
V_56 = ( char * ) ( ( V_173 ) V_45 -> V_56 ) ;
if ( V_433 != V_56 ) {
if ( F_157 ( V_421 ) == V_437 )
memcpy ( V_433 , V_56 , V_432 . V_439 ) ;
F_177 ( V_442 ,
( void * ) ( ( V_173 ) V_56 & V_487 ) ) ;
}
V_433 = NULL ;
}
V_45 ++ ;
V_146 ++ ;
}
}
V_379:
V_183 = V_168 -> V_183 == V_186 ;
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_183 ;
}
void F_148 ( struct V_167 * V_168 )
{
struct V_26 * V_45 ;
struct V_93 * V_94 ;
struct V_488 * V_488 ;
struct V_489 * V_489 ;
struct V_460 * V_460 ;
if ( V_168 -> V_356 == 1 ) {
V_488 = V_168 -> V_171 ;
V_489 = F_178 ( V_488 ) ;
V_460 = (struct V_460 * ) & V_489 -> V_490 [ 0 ] ;
V_94 = (struct V_93 * ) & V_460 -> V_491 [ 0 ] ;
V_94 -> V_95 . V_136 = 0 ;
V_94 -> V_95 . V_138 = 0 ;
} else {
V_45 = V_168 -> V_171 ;
V_94 = V_168 -> V_29 ;
if ( V_45 -> V_54 == V_127 ) {
V_94 -> V_95 . V_136 = 0 ;
V_94 -> V_95 . V_138 = 0 ;
}
}
}
static struct V_167 * F_179 ( struct V_30 * V_298 ,
struct V_277 * V_178 ,
struct V_420 * V_421 )
{
struct V_32 * V_33 ;
struct V_30 * V_119 ;
unsigned long V_43 ;
struct V_167 * V_168 ;
V_119 = F_123 ( V_298 ) ;
if ( ! V_119 )
V_119 = V_298 ;
V_33 = V_119 -> V_33 ;
if ( V_33 -> V_42 >= V_492 )
return F_130 ( - V_493 ) ;
F_27 ( F_28 ( V_119 -> V_2 ) , V_43 ) ;
V_33 -> V_42 ++ ;
if ( ( V_298 -> V_231 & V_301 ) )
V_168 = F_175 ( V_119 , V_178 , V_421 ) ;
else
V_168 = F_171 ( V_119 , V_178 , V_421 ) ;
if ( F_44 ( V_168 ) )
V_33 -> V_42 -- ;
F_29 ( F_28 ( V_119 -> V_2 ) , V_43 ) ;
return V_168 ;
}
static int F_180 ( struct V_167 * V_168 ,
struct V_420 * V_421 )
{
struct V_32 * V_33 ;
unsigned long V_43 ;
F_27 ( F_28 ( V_168 -> V_177 -> V_2 ) , V_43 ) ;
V_33 = V_168 -> V_177 -> V_33 ;
V_33 -> V_42 -- ;
F_29 ( F_28 ( V_168 -> V_177 -> V_2 ) , V_43 ) ;
return F_176 ( V_168 , V_421 ) ;
}
static int
F_181 ( struct V_30 * V_31 ,
struct V_494 * V_495 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
V_495 -> V_496 = 2 ;
V_495 -> V_497 = V_33 -> V_85 ? 0 : 1 ;
V_495 -> V_120 = V_33 -> V_85 ? V_498 : V_499 ;
V_495 -> V_500 = sizeof( V_33 -> V_35 ) ;
memcpy ( V_495 -> V_501 , & V_33 -> V_35 ,
sizeof( V_33 -> V_35 ) ) ;
V_495 -> V_502 = F_167 ( ( unsigned long ) V_33 -> V_200 ,
sizeof( V_495 -> V_503 ) ) ;
memcpy ( V_495 -> V_503 , V_33 -> V_201 ,
V_495 -> V_502 ) ;
return 0 ;
}
static int
F_182 ( struct V_30 * V_31 )
{
struct V_167 * V_168 ;
int V_34 ;
struct V_26 * V_45 ;
int V_504 ;
if ( ! F_183 ( V_505 ) )
return - V_41 ;
V_504 = 0 ;
V_168 = F_43 ( V_176 , 1 , 32 , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_184 ( & V_506 ) ;
V_504 = 1 ;
V_168 = & V_507 -> V_168 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
memset ( & V_507 -> V_45 , 0 ,
sizeof( V_507 -> V_45 ) ) ;
V_168 -> V_171 = & V_507 -> V_45 ;
V_168 -> V_29 = & V_507 -> V_29 ;
V_168 -> V_175 = V_176 ;
}
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_508 ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_42 = 32 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_168 -> V_29 ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
F_39 ( V_189 , & V_168 -> V_43 ) ;
F_34 ( V_273 , & V_168 -> V_43 ) ;
V_168 -> V_181 = 2 ;
V_168 -> V_179 = 2 * V_180 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_40 ( V_168 ) ;
if ( ! V_34 )
F_39 ( V_417 , & V_31 -> V_43 ) ;
if ( V_504 )
F_76 ( & V_506 ) ;
else
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int
F_185 ( struct V_30 * V_31 )
{
struct V_167 * V_168 ;
int V_34 ;
struct V_26 * V_45 ;
int V_504 ;
if ( ! F_183 ( V_505 ) )
return - V_41 ;
V_504 = 0 ;
V_168 = F_43 ( V_176 , 1 , 32 , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_184 ( & V_506 ) ;
V_504 = 1 ;
V_168 = & V_507 -> V_168 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
memset ( & V_507 -> V_45 , 0 ,
sizeof( V_507 -> V_45 ) ) ;
V_168 -> V_171 = & V_507 -> V_45 ;
V_168 -> V_29 = & V_507 -> V_29 ;
V_168 -> V_175 = V_176 ;
}
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_509 ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_42 = 32 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_168 -> V_29 ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
F_39 ( V_189 , & V_168 -> V_43 ) ;
F_34 ( V_273 , & V_168 -> V_43 ) ;
V_168 -> V_181 = 2 ;
V_168 -> V_179 = 2 * V_180 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_40 ( V_168 ) ;
if ( ! V_34 )
F_34 ( V_417 , & V_31 -> V_43 ) ;
if ( V_504 )
F_76 ( & V_506 ) ;
else
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int
F_186 ( struct V_30 * V_31 )
{
struct V_167 * V_168 ;
int V_34 ;
struct V_26 * V_45 ;
int V_504 ;
if ( ! F_183 ( V_505 ) )
return - V_41 ;
V_504 = 0 ;
V_168 = F_43 ( V_176 , 1 , 32 , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_184 ( & V_506 ) ;
V_504 = 1 ;
V_168 = & V_507 -> V_168 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
memset ( & V_507 -> V_45 , 0 ,
sizeof( V_507 -> V_45 ) ) ;
V_168 -> V_171 = & V_507 -> V_45 ;
V_168 -> V_29 = & V_507 -> V_29 ;
V_168 -> V_175 = V_176 ;
}
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_510 ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_42 = 32 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_168 -> V_29 ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
F_39 ( V_189 , & V_168 -> V_43 ) ;
F_34 ( V_273 , & V_168 -> V_43 ) ;
V_168 -> V_181 = 2 ;
V_168 -> V_179 = 2 * V_180 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_40 ( V_168 ) ;
if ( ! V_34 )
F_34 ( V_417 , & V_31 -> V_43 ) ;
if ( V_504 )
F_76 ( & V_506 ) ;
else
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int F_187 ( struct V_30 * V_31 ,
void T_9 * V_511 )
{
struct V_167 * V_168 ;
int V_34 ;
struct V_26 * V_45 ;
int V_504 ;
struct V_512 V_513 ;
if ( ! F_183 ( V_505 ) )
return - V_41 ;
if ( F_188 ( & V_513 , V_511 , sizeof( V_513 ) ) )
return - V_514 ;
V_504 = 0 ;
V_168 = F_43 ( V_176 , 1 ,
sizeof( struct V_515 ) , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_184 ( & V_506 ) ;
V_504 = 1 ;
V_168 = & V_507 -> V_168 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
memset ( & V_507 -> V_45 , 0 ,
sizeof( V_507 -> V_45 ) ) ;
V_168 -> V_171 = & V_507 -> V_45 ;
V_168 -> V_29 = & V_507 -> V_29 ;
V_168 -> V_175 = V_176 ;
}
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_516 ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_42 = 12 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_168 -> V_29 ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
F_39 ( V_189 , & V_168 -> V_43 ) ;
F_34 ( V_273 , & V_168 -> V_43 ) ;
F_34 ( V_190 , & V_168 -> V_43 ) ;
V_168 -> V_181 = 5 ;
V_168 -> V_179 = 10 * V_180 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_168 -> V_170 = V_513 . V_517 ;
V_34 = F_40 ( V_168 ) ;
if ( ! V_34 && V_513 . V_517 && ( V_168 -> V_170 != V_513 . V_517 ) )
V_34 = - V_283 ;
if ( ! V_34 ) {
V_513 . V_29 = * ( (struct V_515 * ) V_168 -> V_29 ) ;
if ( F_189 ( V_511 , & V_513 , sizeof( V_513 ) ) )
V_34 = - V_514 ;
}
if ( V_504 )
F_76 ( & V_506 ) ;
else
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int
F_190 ( struct V_30 * V_31 , void T_9 * V_511 )
{
struct V_255 * V_256 ;
struct V_518 * V_519 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
int V_34 ;
V_168 = F_43 ( V_176 , 1 + 1 ,
( sizeof( struct V_255 ) +
sizeof( struct V_518 ) ) ,
V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_18 ( V_7 , V_31 , L_1 ,
L_80 ) ;
return F_87 ( V_168 ) ;
}
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_181 = 0 ;
F_39 ( V_189 , & V_168 -> V_43 ) ;
V_168 -> V_179 = 10 * V_180 ;
V_256 = (struct V_255 * ) V_168 -> V_29 ;
memset ( V_256 , 0 , sizeof( struct V_255 ) ) ;
V_256 -> V_258 = V_259 ;
V_256 -> V_260 = 0x01 ;
V_256 -> V_520 [ 1 ] = 0x01 ;
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_261 ;
V_45 -> V_42 = sizeof( struct V_255 ) ;
V_45 -> V_43 |= V_262 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_256 ;
V_519 = (struct V_518 * ) ( V_256 + 1 ) ;
memset ( V_519 , 0 , sizeof( struct V_518 ) ) ;
V_45 ++ ;
V_45 -> V_54 = V_263 ;
V_45 -> V_42 = sizeof( struct V_518 ) ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_519 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_45 ( V_168 ) ;
if ( V_34 == 0 ) {
V_256 = (struct V_255 * ) V_168 -> V_29 ;
V_519 = (struct V_518 * ) ( V_256 + 1 ) ;
if ( F_189 ( V_511 , V_519 ,
sizeof( struct V_518 ) ) )
V_34 = - V_514 ;
}
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int
F_191 ( struct V_30 * V_31 , void T_9 * V_511 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_521 V_69 = V_33 -> V_69 ;
int V_34 ;
if ( ! F_183 ( V_505 ) )
return - V_41 ;
if ( ! V_511 )
return - V_128 ;
V_34 = 0 ;
if ( F_189 ( V_511 , ( long * ) & V_69 ,
sizeof( struct V_521 ) ) )
V_34 = - V_514 ;
return V_34 ;
}
static int
F_192 ( struct V_30 * V_31 , void T_9 * V_511 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_521 V_69 ;
if ( ! F_183 ( V_505 ) )
return - V_41 ;
if ( ! V_511 )
return - V_128 ;
if ( F_188 ( & V_69 , V_511 , sizeof( struct V_521 ) ) )
return - V_514 ;
V_33 -> V_69 = V_69 ;
F_97 ( & V_31 -> V_2 -> V_82 ,
L_81 ,
V_33 -> V_69 . V_68 , V_33 -> V_69 . V_89 ) ;
return 0 ;
}
static int F_193 ( struct V_30 * V_31 , void T_9 * V_511 )
{
struct V_522 V_513 ;
char * V_523 , * V_524 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
char V_525 , V_526 ;
int V_34 ;
if ( ! F_183 ( V_505 ) && ! F_183 ( V_527 ) )
return - V_41 ;
V_525 = V_526 = 0 ;
V_34 = - V_514 ;
if ( F_188 ( & V_513 , V_511 , sizeof( V_513 ) ) )
goto V_379;
if ( F_194 () ) {
V_34 = - V_128 ;
if ( ( V_513 . V_523 >> 32 ) != 0 )
goto V_379;
if ( ( V_513 . V_524 >> 32 ) != 0 )
goto V_379;
V_513 . V_523 &= 0x7fffffffULL ;
V_513 . V_524 &= 0x7fffffffULL ;
}
V_523 = F_42 ( V_513 . V_528 , V_195 | V_196 ) ;
V_524 = F_42 ( V_513 . V_529 , V_195 | V_196 ) ;
if ( ! V_523 || ! V_524 ) {
V_34 = - V_197 ;
goto V_530;
}
V_34 = - V_514 ;
if ( F_188 ( V_523 ,
( void T_9 * ) ( unsigned long ) V_513 . V_523 ,
V_513 . V_528 ) )
goto V_530;
V_525 = V_523 [ 0 ] ;
V_526 = V_523 [ 1 ] ;
V_168 = F_43 ( V_176 , 2 , 0 , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_18 ( V_7 , V_31 , L_1 ,
L_80 ) ;
V_34 = F_87 ( V_168 ) ;
goto V_530;
}
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_181 = 3 ;
V_168 -> V_179 = 10 * V_180 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_261 ;
V_45 -> V_42 = V_513 . V_528 ;
V_45 -> V_43 |= V_262 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_523 ;
V_45 ++ ;
V_45 -> V_54 = V_263 ;
V_45 -> V_42 = V_513 . V_529 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_524 ;
V_34 = F_45 ( V_168 ) ;
if ( V_34 )
goto V_531;
V_34 = - V_514 ;
if ( F_189 ( ( void T_9 * ) ( unsigned long ) V_513 . V_524 ,
V_524 , V_513 . V_529 ) )
goto V_531;
V_34 = 0 ;
V_531:
F_46 ( V_168 , V_168 -> V_177 ) ;
V_530:
F_47 ( V_524 ) ;
F_47 ( V_523 ) ;
V_379:
F_18 ( V_7 , V_31 ,
L_82 ,
( int ) V_525 , ( int ) V_526 , V_34 ) ;
return V_34 ;
}
static int
F_195 ( struct V_277 * V_178 , unsigned int V_48 , void T_9 * V_511 )
{
struct V_30 * V_31 = V_178 -> V_298 ;
switch ( V_48 ) {
case V_532 :
return F_191 ( V_31 , V_511 ) ;
case V_533 :
return F_192 ( V_31 , V_511 ) ;
case V_534 :
return F_190 ( V_31 , V_511 ) ;
case V_535 :
return F_182 ( V_31 ) ;
case V_536 :
return F_185 ( V_31 ) ;
case V_537 :
return F_186 ( V_31 ) ;
case V_538 :
return F_187 ( V_31 , V_511 ) ;
case V_539 :
return F_193 ( V_31 , V_511 ) ;
default:
return - V_540 ;
}
}
static int
F_196 ( struct V_26 * V_541 , struct V_26 * V_542 , char * V_543 )
{
int V_544 , V_42 ;
char * V_545 ;
V_544 = 0 ;
while ( V_541 <= V_542 ) {
V_544 += sprintf ( V_543 + V_544 , V_546
L_83 ,
V_541 , ( ( int * ) V_541 ) [ 0 ] , ( ( int * ) V_541 ) [ 1 ] ) ;
if ( V_541 -> V_43 & V_447 )
V_545 = ( char * ) * ( ( V_173 * ) ( V_173 ) V_541 -> V_56 ) ;
else
V_545 = ( char * ) ( ( V_173 ) V_541 -> V_56 ) ;
for ( V_42 = 0 ; V_42 < V_541 -> V_42 && V_42 < 32 ; V_42 ++ ) {
if ( V_42 % 8 == 0 ) V_544 += sprintf ( V_543 + V_544 , L_84 ) ;
if ( V_42 % 4 == 0 ) V_544 += sprintf ( V_543 + V_544 , L_84 ) ;
V_544 += sprintf ( V_543 + V_544 , L_11 , V_545 [ V_42 ] ) ;
}
V_544 += sprintf ( V_543 + V_544 , L_85 ) ;
V_541 ++ ;
}
return V_544 ;
}
static void
F_197 ( struct V_30 * V_31 , struct V_322 * V_322 ,
char * V_547 )
{
T_10 * V_318 ;
T_10 * V_548 ;
V_318 = ( T_10 * ) F_107 ( V_322 ) ;
V_548 = ( T_10 * ) & V_322 -> V_402 ;
if ( V_318 ) {
F_18 ( V_549 , V_31 , L_86
L_87 ,
V_547 , * V_548 , * ( ( T_3 * ) ( V_548 + 1 ) ) ,
V_318 [ 0 ] , V_318 [ 1 ] , V_318 [ 2 ] , V_318 [ 3 ] ) ;
} else {
F_18 ( V_549 , V_31 , L_88 ,
V_547 , * V_548 , * ( ( T_3 * ) ( V_548 + 1 ) ) ,
L_89 ) ;
}
}
static void F_198 ( struct V_30 * V_31 ,
struct V_167 * V_421 , struct V_322 * V_322 )
{
char * V_543 ;
struct V_26 * V_550 , * V_551 , * V_552 , * V_541 , * V_542 ;
int V_544 , V_553 , V_554 ;
V_543 = ( char * ) F_199 ( V_252 ) ;
if ( V_543 == NULL ) {
F_18 ( V_7 , V_31 , L_1 ,
L_90 ) ;
return;
}
V_544 = sprintf ( V_543 , V_546
L_91 ,
F_200 ( & V_31 -> V_2 -> V_82 ) ) ;
V_544 += sprintf ( V_543 + V_544 , V_546
L_92
L_93 ,
V_421 , F_201 ( & V_322 -> V_402 ) , F_202 ( & V_322 -> V_402 ) ,
F_203 ( & V_322 -> V_402 ) , F_204 ( & V_322 -> V_402 ) ,
F_152 ( & V_322 -> V_402 ) , F_146 ( & V_322 -> V_402 ) ,
V_421 ? V_421 -> V_269 : 0 ) ;
V_544 += sprintf ( V_543 + V_544 , V_546
L_94 ,
F_200 ( & V_31 -> V_2 -> V_82 ) ,
( void * ) ( V_173 ) V_322 -> V_402 . V_48 . V_555 ) ;
if ( V_322 -> V_556 . V_557 . V_558 . V_559 ) {
for ( V_553 = 0 ; V_553 < 4 ; V_553 ++ ) {
V_544 += sprintf ( V_543 + V_544 , V_546
L_95 ,
( 8 * V_553 ) , ( ( 8 * V_553 ) + 7 ) ) ;
for ( V_554 = 0 ; V_554 < 8 ; V_554 ++ ) {
V_544 += sprintf ( V_543 + V_544 , L_96 ,
V_322 -> V_560 [ 8 * V_553 + V_554 ] ) ;
}
V_544 += sprintf ( V_543 + V_544 , L_85 ) ;
}
if ( V_322 -> V_560 [ 27 ] & V_411 ) {
sprintf ( V_543 + V_544 , V_546
L_97
L_98 ,
V_322 -> V_560 [ 7 ] >> 4 , V_322 -> V_560 [ 7 ] & 0x0f ,
V_322 -> V_560 [ 1 ] & 0x10 ? L_58 : L_99 ) ;
} else {
sprintf ( V_543 + V_544 , V_546
L_100
L_101 ,
V_322 -> V_560 [ 6 ] & 0x0f , V_322 -> V_560 [ 22 ] >> 4 ) ;
}
} else {
sprintf ( V_543 + V_544 , V_546
L_102 ) ;
}
F_205 ( V_561 L_1 , V_543 ) ;
if ( V_421 ) {
V_550 = V_421 -> V_171 ;
for ( V_551 = V_550 ; V_551 -> V_43 & ( V_262 | V_562 ) ; V_551 ++ ) ;
V_542 = F_167 ( V_550 + 6 , V_551 ) ;
V_544 = sprintf ( V_543 , V_546
L_103 , V_421 ) ;
F_196 ( V_550 , V_542 , V_543 + V_544 ) ;
F_205 ( V_561 L_1 , V_543 ) ;
V_544 = 0 ;
V_541 = ++ V_542 ;
V_552 = (struct V_26 * ) ( V_173 )
V_322 -> V_402 . V_48 . V_555 ;
if ( V_541 < V_552 - 2 ) {
V_541 = V_552 - 2 ;
V_544 += sprintf ( V_543 , V_546 L_104 ) ;
}
V_542 = F_167 ( V_552 + 1 , V_551 ) ;
V_544 += F_196 ( V_541 , V_542 , V_543 + V_544 ) ;
V_541 = V_383 ( V_541 , ++ V_542 ) ;
if ( V_541 < V_551 - 1 ) {
V_541 = V_551 - 1 ;
V_544 += sprintf ( V_543 + V_544 , V_546 L_104 ) ;
}
V_544 += F_196 ( V_541 , V_551 , V_543 + V_544 ) ;
if ( V_544 > 0 )
F_205 ( V_561 L_1 , V_543 ) ;
}
F_206 ( ( unsigned long ) V_543 ) ;
}
static void F_207 ( struct V_30 * V_31 ,
struct V_167 * V_421 , struct V_322 * V_322 )
{
char * V_543 ;
int V_544 , V_553 , V_554 , V_563 ;
struct V_564 * V_564 ;
T_7 * V_318 , * V_565 ;
V_543 = ( char * ) F_199 ( V_252 ) ;
if ( V_543 == NULL ) {
F_18 ( V_7 , V_31 , L_105 ,
L_106 ) ;
return;
}
V_544 = sprintf ( V_543 , V_546
L_91 ,
F_200 ( & V_31 -> V_2 -> V_82 ) ) ;
V_544 += sprintf ( V_543 + V_544 , V_546
L_92
L_107 ,
V_421 , F_201 ( & V_322 -> V_402 ) , F_202 ( & V_322 -> V_402 ) ,
F_203 ( & V_322 -> V_402 ) , F_204 ( & V_322 -> V_402 ) ,
F_152 ( & V_322 -> V_402 ) , F_146 ( & V_322 -> V_402 ) ,
V_322 -> V_402 . V_566 . V_567 ,
( V_322 -> V_402 . V_566 . V_568 << 7 ) | V_322 -> V_402 . V_566 . V_569 ,
V_421 ? V_421 -> V_269 : 0 ) ;
V_544 += sprintf ( V_543 + V_544 , V_546
L_108 ,
F_200 ( & V_31 -> V_2 -> V_82 ) ,
( void * ) ( V_173 ) V_322 -> V_402 . V_566 . V_488 ) ;
V_564 = NULL ;
V_318 = NULL ;
if ( V_322 -> V_402 . V_566 . V_488 && ( V_322 -> V_402 . V_566 . V_567 & 0x01 ) )
V_564 = F_208 (
(struct V_488 * ) ( unsigned long ) V_322 -> V_402 . V_566 . V_488 ) ;
if ( V_564 ) {
V_544 += sprintf ( V_543 + V_544 , V_546
L_109 , V_564 -> V_106 ) ;
V_544 += sprintf ( V_543 + V_544 , V_546
L_110 , V_564 -> V_43 ) ;
V_544 += sprintf ( V_543 + V_544 , V_546
L_111 , V_564 -> V_570 ) ;
V_544 += sprintf ( V_543 + V_544 , V_546
L_112 , V_564 -> V_42 ) ;
V_563 = V_564 -> V_42 - 28 ;
V_544 += sprintf ( V_543 + V_544 , V_546
L_113 , V_563 ) ;
switch ( V_564 -> V_43 & 0x07 ) {
case 1 :
V_544 += sprintf ( V_543 + V_544 , V_546
L_114 ,
V_564 -> V_571 . V_572 . V_573 ) ;
V_544 += sprintf ( V_543 + V_544 , V_546
L_115 ,
V_564 -> V_571 . V_572 . V_574 ) ;
V_544 += sprintf ( V_543 + V_544 , V_546
L_116 ,
V_564 -> V_571 . V_572 . V_575 ) ;
V_544 += sprintf ( V_543 + V_544 , V_546
L_117 ,
V_564 -> V_571 . V_572 . V_576 ) ;
V_544 += sprintf ( V_543 + V_544 , V_546
L_118 ,
V_564 -> V_571 . V_572 . V_577 ) ;
V_318 = V_564 -> V_571 . V_572 . V_318 ;
break;
case 2 :
V_544 += sprintf ( V_543 + V_544 , V_546
L_119 , V_564 -> V_571 . V_578 . V_34 ) ;
for ( V_553 = 0 ; V_553 < 2 ; V_553 ++ ) {
V_544 += sprintf ( V_543 + V_544 , V_546
L_120 ,
( 8 * V_553 ) , ( ( 8 * V_553 ) + 7 ) ) ;
V_565 = V_564 -> V_571 . V_578 . V_565 ;
for ( V_554 = 0 ; V_554 < 8 ; V_554 ++ ) {
V_544 += sprintf ( V_543 + V_544 , L_96 ,
V_565 [ 8 * V_553 + V_554 ] ) ;
}
V_544 += sprintf ( V_543 + V_544 , L_85 ) ;
}
V_318 = V_564 -> V_571 . V_578 . V_318 ;
break;
case 3 :
V_544 += sprintf ( V_543 + V_544 , V_546
L_121 ) ;
break;
}
if ( V_318 ) {
for ( V_553 = 0 ; V_553 < 4 ; V_553 ++ ) {
V_544 += sprintf ( V_543 + V_544 , V_546
L_95 ,
( 8 * V_553 ) , ( ( 8 * V_553 ) + 7 ) ) ;
for ( V_554 = 0 ; V_554 < 8 ; V_554 ++ ) {
V_544 += sprintf ( V_543 + V_544 , L_96 ,
V_318 [ 8 * V_553 + V_554 ] ) ;
}
V_544 += sprintf ( V_543 + V_544 , L_85 ) ;
}
if ( V_318 [ 27 ] & V_411 ) {
sprintf ( V_543 + V_544 , V_546
L_97
L_98 ,
V_318 [ 7 ] >> 4 , V_318 [ 7 ] & 0x0f ,
V_318 [ 1 ] & 0x10 ? L_58 : L_99 ) ;
} else {
sprintf ( V_543 + V_544 , V_546
L_100
L_101 ,
V_318 [ 6 ] & 0x0f , V_318 [ 22 ] >> 4 ) ;
}
} else {
sprintf ( V_543 + V_544 , V_546
L_102 ) ;
}
} else {
sprintf ( V_543 + V_544 , V_546
L_122 ) ;
}
F_205 ( V_561 L_1 , V_543 ) ;
F_206 ( ( unsigned long ) V_543 ) ;
}
static void F_209 ( struct V_30 * V_31 ,
struct V_167 * V_421 , struct V_322 * V_322 )
{
T_7 * V_318 = F_107 ( V_322 ) ;
if ( F_210 ( & V_322 -> V_402 ) ) {
if ( V_318 && ( V_318 [ 1 ] & V_381 ) &&
F_70 ( V_357 , & V_421 -> V_43 ) )
return;
if ( F_146 ( & V_322 -> V_402 ) == 0x40 &&
F_70 ( V_358 , & V_421 -> V_43 ) )
return;
F_207 ( V_31 , V_421 , V_322 ) ;
} else {
if ( V_318 && V_318 [ 1 ] & V_323 &&
F_70 ( V_361 , & V_421 -> V_43 ) )
return;
F_198 ( V_31 , V_421 , V_322 ) ;
}
}
static int F_211 ( struct V_30 * V_31 )
{
F_120 ( V_31 ) ;
F_102 ( V_31 ) ;
return 0 ;
}
static int F_212 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_14 V_579 ;
int V_34 ;
struct V_149 V_278 ;
unsigned long V_43 ;
unsigned long V_580 = 0 ;
V_34 = F_51 ( V_31 ) ;
if ( V_34 ) {
F_3 ( V_7 , V_31 -> V_2 ,
L_123 , V_34 ) ;
goto V_353;
}
F_30 ( V_31 , & V_278 ) ;
V_34 = F_26 ( V_31 ) ;
F_27 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
if ( memcmp ( & V_33 -> V_134 , & V_278 , sizeof( struct V_149 ) ) != 0 )
F_15 ( & V_31 -> V_2 -> V_82 , L_124
L_125 ) ;
F_29 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
if ( V_34 )
goto V_353;
V_34 = F_99 ( V_31 ) ;
if ( V_34 )
goto V_353;
F_34 ( V_273 , & V_580 ) ;
F_91 ( V_31 , V_580 ) ;
V_34 = F_51 ( V_31 ) ;
if ( V_34 ) {
F_3 ( V_7 , V_31 -> V_2 ,
L_123 , V_34 ) ;
goto V_299;
}
F_86 ( V_31 ) ;
V_34 = F_100 ( V_31 , V_176 ,
& V_579 , 64 ) ;
if ( V_34 ) {
F_3 ( V_7 , V_31 -> V_2 ,
L_52 , V_34 ) ;
goto V_299;
}
F_27 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
memcpy ( & V_33 -> V_35 , & V_579 , sizeof( V_579 ) ) ;
F_29 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
F_116 ( V_31 ) ;
return 0 ;
V_299:
F_102 ( V_31 ) ;
V_353:
return - 1 ;
}
static int F_213 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
int V_34 , V_581 ;
char V_244 [ 60 ] ;
struct V_149 V_134 ;
unsigned long V_43 ;
F_120 ( V_31 ) ;
F_27 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
V_581 = V_33 -> V_134 . V_161 ;
F_29 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
V_34 = F_51 ( V_31 ) ;
if ( V_34 )
goto V_353;
V_34 = F_26 ( V_31 ) ;
if ( V_34 )
goto V_353;
F_214 ( V_31 ) ;
F_30 ( V_31 , & V_134 ) ;
if ( V_581 != V_134 . V_161 ) {
if ( strlen ( V_134 . V_163 ) > 0 )
snprintf ( V_244 , sizeof( V_244 ) ,
L_17 , V_134 . V_150 , V_134 . V_152 ,
V_134 . V_154 , V_134 . V_161 , V_134 . V_163 ) ;
else
snprintf ( V_244 , sizeof( V_244 ) ,
L_18 , V_134 . V_150 , V_134 . V_152 ,
V_134 . V_154 , V_134 . V_161 ) ;
F_97 ( & V_31 -> V_2 -> V_82 ,
L_126
L_127 , V_244 ) ;
}
return 0 ;
V_353:
return - 1 ;
}
static int F_215 ( struct V_30 * V_31 ,
struct V_582 * V_583 ,
T_2 V_584 )
{
struct V_582 * V_585 ;
struct V_255 * V_256 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
int V_34 ;
V_168 = F_43 ( V_176 , 1 + 1 ,
( sizeof( struct V_255 ) +
sizeof( struct V_582 ) ) ,
V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_128 ) ;
return F_87 ( V_168 ) ;
}
V_168 -> V_170 = V_584 ;
V_377:
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_178 = NULL ;
V_168 -> V_179 = 10 * V_180 ;
F_34 ( V_185 , & V_168 -> V_43 ) ;
F_39 ( V_189 , & V_168 -> V_43 ) ;
V_168 -> V_181 = 256 ;
V_256 = (struct V_255 * ) V_168 -> V_29 ;
memset ( V_256 , 0 , sizeof( struct V_255 ) ) ;
V_256 -> V_258 = V_259 ;
V_256 -> V_260 = 0x03 ;
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_261 ;
V_45 -> V_42 = sizeof( struct V_255 ) ;
V_45 -> V_43 |= V_262 ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_256 ;
V_585 = (struct V_582 * ) ( V_256 + 1 ) ;
memset ( V_585 , 0 , sizeof( struct V_582 ) ) ;
V_45 ++ ;
V_45 -> V_54 = V_263 ;
V_45 -> V_42 = sizeof( struct V_582 ) ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_585 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_40 ( V_168 ) ;
if ( V_34 == 0 ) {
V_256 = (struct V_255 * ) V_168 -> V_29 ;
V_585 = (struct V_582 * )
( V_256 + 1 ) ;
memcpy ( V_583 , V_585 ,
sizeof( struct V_582 ) ) ;
} else if ( V_168 -> V_170 ) {
V_168 -> V_170 = 0 ;
goto V_377;
} else
F_3 ( V_7 , V_31 -> V_2 ,
L_129
, V_34 ) ;
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int F_216 ( struct V_30 * V_31 ,
struct V_586 * V_29 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_586 * V_587 ;
struct V_255 * V_256 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
int V_34 ;
if ( ! V_31 -> V_178 && V_33 -> V_410 -> V_588 == V_589 )
return - V_40 ;
V_168 = F_43 ( V_176 , 1 + 1 ,
sizeof( struct V_255 ) + 1 ,
V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_128 ) ;
return F_87 ( V_168 ) ;
}
V_587 = F_42 ( sizeof( * V_587 ) , V_195 | V_196 ) ;
if ( ! V_587 ) {
F_46 ( V_168 , V_31 ) ;
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_130 ) ;
return - V_197 ;
}
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_178 = NULL ;
V_168 -> V_181 = 256 ;
V_168 -> V_179 = 10 * V_180 ;
V_256 = (struct V_255 * ) V_168 -> V_29 ;
memset ( V_256 , 0 , sizeof( struct V_255 ) ) ;
V_256 -> V_258 = V_259 ;
V_256 -> V_260 = V_590 ;
V_256 -> V_591 = V_33 -> V_130 -> V_133 ;
V_256 -> V_592 = V_33 -> V_130 -> V_131 ;
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_261 ;
V_45 -> V_42 = sizeof( struct V_255 ) ;
V_45 -> V_43 |= V_262 ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_256 ;
V_45 ++ ;
V_45 -> V_54 = V_263 ;
V_45 -> V_42 = sizeof( struct V_586 ) ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_587 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_217 ( V_168 ) ;
if ( V_34 == 0 ) {
* V_29 = * V_587 ;
} else {
F_3 ( V_7 , V_31 -> V_2 ,
L_131 ,
V_34 ) ;
V_34 = - V_40 ;
}
F_46 ( V_168 , V_168 -> V_177 ) ;
F_47 ( V_587 ) ;
return V_34 ;
}
static int F_218 ( struct V_30 * V_31 )
{
struct V_586 * V_593 ;
struct V_594 * V_595 ;
struct V_596 * V_495 ;
int V_42 = 0 ;
int V_34 , V_199 ;
V_593 = F_42 ( sizeof( * V_593 ) , V_597 ) ;
if ( ! V_593 ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_132 ) ;
return - V_197 ;
}
V_34 = F_216 ( V_31 , V_593 ) ;
if ( V_34 ) {
F_47 ( V_593 ) ;
return V_34 ;
}
V_495 = (struct V_596 * )
V_593 -> V_598 ;
for ( V_199 = 0 ; V_199 < V_495 -> V_599 ; V_199 ++ ) {
V_595 = (struct V_594 * )
( V_495 -> V_595 + V_199 * V_495 -> V_600 ) ;
if ( V_595 -> V_601 & V_602 )
V_42 ++ ;
}
F_47 ( V_593 ) ;
return V_42 ;
}
static int F_219 ( struct V_30 * V_31 , struct V_603 * V_604 )
{
struct V_586 * V_593 ;
struct V_594 * V_595 ;
struct V_596 * V_495 ;
char V_605 [ 9 ] = L_58 ;
int V_34 , V_199 , V_365 ;
V_593 = F_42 ( sizeof( * V_593 ) , V_597 ) ;
if ( ! V_593 ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_132 ) ;
return - V_197 ;
}
V_34 = F_216 ( V_31 , V_593 ) ;
if ( V_34 ) {
F_47 ( V_593 ) ;
return V_34 ;
}
V_495 = (struct V_596 * )
V_593 -> V_598 ;
for ( V_199 = 0 ; V_199 < V_495 -> V_599 ; V_199 ++ ) {
V_595 = (struct V_594 * )
( V_495 -> V_595 + V_199 * V_495 -> V_600 ) ;
F_220 ( V_604 , L_133 ) ;
for ( V_365 = 0 ; V_365 < 11 ; V_365 ++ )
F_221 ( V_604 , L_11 , V_595 -> V_606 [ V_365 ] ) ;
F_222 ( V_604 , '\n' ) ;
F_221 ( V_604 , L_134 , V_595 -> V_601 ) ;
memcpy ( & V_605 , & V_595 -> V_607 , sizeof( V_605 ) - 1 ) ;
F_25 ( V_605 , sizeof( V_605 ) ) ;
F_221 ( V_604 , L_135 , V_605 ) ;
F_221 ( V_604 , L_136 , V_595 -> V_608 ) ;
F_221 ( V_604 , L_137 , ( unsigned long )
V_595 -> V_609 ) ;
}
F_47 ( V_593 ) ;
return 0 ;
}
static int
F_223 ( struct V_30 * V_31 , int V_610 ,
T_1 V_611 , T_2 V_584 )
{
struct V_612 * V_613 ;
int V_213 = F_55 ( V_584 ) ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
int V_34 ;
V_168 = F_43 ( V_176 , 1 ,
sizeof( struct V_612 ) ,
V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_18 ( V_7 , V_31 , L_1 ,
L_138 ) ;
return F_87 ( V_168 ) ;
}
V_613 = (struct V_612 * ) V_168 -> V_29 ;
V_613 -> V_258 = V_614 ;
V_613 -> V_615 = V_610 ;
V_613 -> V_210 = V_31 -> V_208 [ V_213 ] . V_210 ;
V_613 -> V_611 = V_611 ;
V_613 -> V_209 = V_31 -> V_208 [ V_213 ] . V_209 ;
V_613 -> V_154 = V_31 -> V_208 [ V_213 ] . V_154 ;
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_261 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_613 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_42 = sizeof( struct V_612 ) ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_178 = NULL ;
V_168 -> V_181 = 256 ;
V_168 -> V_179 = 10 * V_180 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
F_34 ( V_185 , & V_168 -> V_43 ) ;
V_34 = F_45 ( V_168 ) ;
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static struct V_616 * F_224 ( struct V_30 * V_31 ,
T_2 V_584 ,
struct V_617 * V_618 )
{
struct V_616 * V_201 ;
int V_208 , V_213 ;
if ( V_618 -> V_619 == 0 )
goto V_379;
for ( V_208 = 0x80 , V_213 = 0 ; V_208 ; V_208 >>= 1 , V_213 ++ ) {
V_201 = V_31 -> V_208 [ V_213 ] . V_201 ;
if ( V_201 -> V_155 . V_619 ==
V_618 -> V_619 )
return V_201 ;
}
V_379:
return V_31 -> V_208 [ F_55 ( V_584 ) ] . V_201 ;
}
static int F_225 ( struct V_30 * V_31 , T_2 V_584 ,
struct V_617 * V_618 )
{
struct V_616 * V_620 ;
unsigned long V_621 = 0 , V_65 = 0 ;
struct V_616 * V_201 ;
unsigned int V_213 , V_208 ;
char * V_622 , * V_155 ;
char * V_623 , * V_130 ;
int V_624 = 0 ;
if ( ! V_618 -> V_625 ||
! ( V_618 -> V_626 [ 0 ] | V_618 -> V_626 [ 1 ] | V_618 -> V_626 [ 2 ] ) )
return V_584 ;
V_620 = F_224 ( V_31 , V_584 , V_618 ) ;
V_213 = 8 - F_226 ( V_618 -> V_625 ) ;
V_623 = ( char * ) & V_620 -> V_627 [ V_213 ] ;
V_622 = ( char * ) & V_620 -> V_155 ;
V_65 = V_618 -> V_626 [ 2 ] ;
V_65 |= V_618 -> V_626 [ 1 ] << 8 ;
V_65 |= V_618 -> V_626 [ 0 ] << 16 ;
for ( V_208 = 0 ; V_208 < 8 ; V_208 ++ ) {
V_621 = V_65 ;
V_201 = V_31 -> V_208 [ V_208 ] . V_201 ;
V_213 = 8 - F_226 ( V_618 -> V_625 ) ;
V_130 = ( char * ) & V_201 -> V_627 [ V_213 ] ;
if ( memcmp ( V_623 , V_130 , sizeof( * V_130 ) ) != 0 )
continue;
V_155 = ( char * ) & V_201 -> V_155 ;
while ( V_621 ) {
V_213 = F_226 ( V_621 ) - 1 ;
if ( memcmp ( & V_622 [ 31 - V_213 ] , & V_155 [ 31 - V_213 ] , 1 )
!= 0 )
break;
F_39 ( V_213 , & V_621 ) ;
}
if ( V_621 )
continue;
V_624 |= 0x80 >> V_208 ;
}
return V_624 ;
}
static void F_227 ( struct V_30 * V_31 ,
unsigned long V_628 , int V_629 )
{
int V_213 ;
while ( V_628 ) {
V_213 = 8 - F_226 ( V_628 ) ;
if ( V_629 == V_630 )
F_228 ( L_139 ,
V_31 -> V_208 [ V_213 ] . V_209 ,
V_31 -> V_208 [ V_213 ] . V_210 ) ;
else if ( V_629 == V_631 )
F_229 ( L_140 ,
V_31 -> V_208 [ V_213 ] . V_209 ,
V_31 -> V_208 [ V_213 ] . V_210 ) ;
F_39 ( 7 - V_213 , & V_628 ) ;
}
}
static int F_230 ( struct V_30 * V_31 , T_2 V_584 ,
struct V_617 * V_618 )
{
unsigned long V_624 ;
V_624 = F_225 ( V_31 , V_584 , V_618 ) ;
if ( ! ( F_60 ( V_31 ) & V_624 ) )
return 0 ;
if ( ! ( F_60 ( V_31 ) & ~ V_624 ) ) {
return - V_128 ;
}
F_231 ( V_31 , V_624 ) ;
F_232 ( V_31 , V_624 ) ;
return V_624 ;
}
static int F_233 ( struct V_30 * V_31 , T_2 V_584 ,
struct V_617 * V_618 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_632 * V_633 , * V_634 ;
struct V_30 * V_82 , * V_370 ;
unsigned long V_628 = 0 ;
unsigned long V_43 ;
int V_624 ;
F_140 (dev, n, &private->lcu->active_devices,
alias_list) {
F_27 ( F_28 ( V_82 -> V_2 ) , V_43 ) ;
V_624 = F_230 ( V_82 , V_584 , V_618 ) ;
F_29 ( F_28 ( V_82 -> V_2 ) , V_43 ) ;
if ( V_624 < 0 )
goto V_353;
V_628 |= V_624 ;
}
F_140 (dev, n, &private->lcu->inactive_devices,
alias_list) {
F_27 ( F_28 ( V_82 -> V_2 ) , V_43 ) ;
V_624 = F_230 ( V_82 , V_584 , V_618 ) ;
F_29 ( F_28 ( V_82 -> V_2 ) , V_43 ) ;
if ( V_624 < 0 )
goto V_353;
V_628 |= V_624 ;
}
F_140 (pavgroup, tempgroup,
&private->lcu->grouplist, group) {
F_140 (dev, n, &pavgroup->baselist,
alias_list) {
F_27 ( F_28 ( V_82 -> V_2 ) , V_43 ) ;
V_624 = F_230 ( V_82 , V_584 , V_618 ) ;
F_29 (
F_28 ( V_82 -> V_2 ) , V_43 ) ;
if ( V_624 < 0 )
goto V_353;
V_628 |= V_624 ;
}
F_140 (dev, n, &pavgroup->aliaslist,
alias_list) {
F_27 ( F_28 ( V_82 -> V_2 ) , V_43 ) ;
V_624 = F_230 ( V_82 , V_584 , V_618 ) ;
F_29 (
F_28 ( V_82 -> V_2 ) , V_43 ) ;
if ( V_624 < 0 )
goto V_353;
V_628 |= V_624 ;
}
}
F_227 ( V_31 , V_628 , V_630 ) ;
return 0 ;
V_353:
return V_624 ;
}
static int F_234 ( struct V_30 * V_31 , T_2 V_584 ,
struct V_617 * V_618 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_632 * V_633 , * V_634 ;
struct V_30 * V_82 , * V_370 ;
unsigned long V_628 = 0 ;
int V_624 ;
F_140 (dev, n,
&private->lcu->active_devices,
alias_list) {
V_624 = F_225 ( V_82 , V_584 , V_618 ) ;
V_628 |= V_624 ;
if ( ! ( F_60 ( V_82 ) & V_624 ) ) {
F_73 ( V_82 , V_624 ) ;
F_85 ( V_82 ) ;
}
}
F_140 (dev, n,
&private->lcu->inactive_devices,
alias_list) {
V_624 = F_225 ( V_82 , V_584 , V_618 ) ;
V_628 |= V_624 ;
if ( ! ( F_60 ( V_82 ) & V_624 ) ) {
F_73 ( V_82 , V_624 ) ;
F_85 ( V_82 ) ;
}
}
F_140 (pavgroup, tempgroup,
&private->lcu->grouplist,
group) {
F_140 (dev, n,
&pavgroup->baselist,
alias_list) {
V_624 = F_225 ( V_82 , V_584 , V_618 ) ;
V_628 |= V_624 ;
if ( ! ( F_60 ( V_82 ) & V_624 ) ) {
F_73 ( V_82 , V_624 ) ;
F_85 ( V_82 ) ;
}
}
F_140 (dev, n,
&pavgroup->aliaslist,
alias_list) {
V_624 = F_225 ( V_82 , V_584 , V_618 ) ;
V_628 |= V_624 ;
if ( ! ( F_60 ( V_82 ) & V_624 ) ) {
F_73 ( V_82 , V_624 ) ;
F_85 ( V_82 ) ;
}
}
}
F_227 ( V_31 , V_628 , V_631 ) ;
return 0 ;
}
static void F_235 ( struct V_30 * V_31 , void * V_583 ,
T_2 V_584 )
{
struct V_617 * V_618 = V_583 ;
int V_610 ;
F_18 ( V_7 , V_31 ,
L_141 ,
( ( T_10 * ) V_618 ) [ 0 ] , ( ( T_10 * ) V_618 ) [ 1 ] , ( ( T_10 * ) V_618 ) [ 2 ] ,
( ( T_3 * ) V_618 ) [ 3 ] ) ;
if ( V_618 -> V_635 == V_630 ) {
if ( F_233 ( V_31 , V_584 , V_618 ) )
V_610 = V_636 ;
else
V_610 = V_637 ;
} else if ( V_618 -> V_635 == V_631 ) {
F_234 ( V_31 , V_584 , V_618 ) ;
V_610 = V_637 ;
} else
V_610 = V_638 ;
F_223 ( V_31 , V_610 ,
V_618 -> V_611 , V_584 ) ;
F_18 ( V_7 , V_31 ,
L_142 , V_610 ,
V_618 -> V_611 ) ;
V_31 -> V_639 -> V_640 ( V_31 , V_584 ) ;
}
static void F_236 ( struct V_236 * V_237 )
{
struct V_641 * V_29 ;
struct V_582 * V_583 ;
struct V_30 * V_31 ;
int V_34 ;
V_29 = F_69 ( V_237 , struct V_641 , V_245 ) ;
V_31 = V_29 -> V_31 ;
V_583 = F_42 ( sizeof( * V_583 ) , V_195 ) ;
if ( ! V_583 ) {
F_18 ( V_7 , V_31 , L_1 ,
L_143 ) ;
goto V_379;
}
V_34 = F_215 ( V_31 , V_583 , V_29 -> V_584 ) ;
if ( V_34 )
goto V_379;
if ( V_583 -> V_106 == V_642 &&
V_583 -> V_120 == V_643 )
F_235 ( V_31 , V_583 , V_29 -> V_584 ) ;
V_379:
F_75 ( V_31 ) ;
F_47 ( V_583 ) ;
F_47 ( V_29 ) ;
}
static int F_237 ( struct V_30 * V_31 , T_2 V_584 )
{
struct V_641 * V_29 ;
V_29 = F_42 ( sizeof( * V_29 ) , V_252 ) ;
if ( ! V_29 )
return - V_197 ;
F_80 ( & V_29 -> V_245 , F_236 ) ;
F_81 ( V_31 ) ;
V_29 -> V_31 = V_31 ;
V_29 -> V_584 = V_584 ;
F_71 ( & V_29 -> V_245 ) ;
return 0 ;
}
static int F_238 ( struct V_30 * V_31 , T_2 V_584 )
{
if ( ~ V_584 & F_60 ( V_31 ) ) {
F_74 ( V_31 , V_584 ) ;
F_231 ( V_31 , V_584 ) ;
F_15 ( & V_31 -> V_2 -> V_82 ,
L_144 ,
V_584 ) ;
return 1 ;
}
return 0 ;
}
static void F_239 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
F_15 ( & V_31 -> V_2 -> V_82 ,
L_145 ) ;
V_33 -> V_234 = 0 ;
}
static int F_240 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
return V_33 -> V_234 ? 1 : 0 ;
}
static void F_241 ( struct V_30 * V_31 ,
struct V_322 * V_322 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
if ( ! V_33 -> V_234 ) {
F_18 ( V_7 , V_31 , L_1 ,
L_146 ) ;
return;
}
if ( V_322 -> V_402 . V_566 . V_569 == V_644 ) {
F_239 ( V_31 ) ;
} else if ( V_322 -> V_402 . V_566 . V_569 == V_645 ) {
if ( F_238 ( V_31 , V_322 -> V_556 . V_646 . V_584 ) )
return;
F_239 ( V_31 ) ;
F_83 ( V_31 ,
F_242 ( V_31 ) ) ;
}
F_243 ( V_31 , V_647 ) ;
F_244 ( V_31 ) ;
}
static int T_11
F_245 ( void )
{
int V_3 ;
F_246 ( V_8 . V_648 , 4 ) ;
V_507 = F_78 ( sizeof( * V_507 ) ,
V_195 | V_196 ) ;
if ( ! V_507 )
return - V_197 ;
V_253 = F_78 ( sizeof( * V_253 ) ,
V_195 | V_196 ) ;
if ( ! V_253 ) {
F_47 ( V_507 ) ;
return - V_197 ;
}
V_485 = ( void * ) F_247 ( V_195 ) ;
if ( ! V_485 ) {
F_47 ( V_253 ) ;
F_47 ( V_507 ) ;
return - V_197 ;
}
V_3 = F_248 ( & V_649 ) ;
if ( ! V_3 )
F_249 () ;
else {
F_47 ( V_253 ) ;
F_47 ( V_507 ) ;
F_206 ( ( unsigned long ) V_485 ) ;
}
return V_3 ;
}
static void T_12
F_250 ( void )
{
F_251 ( & V_649 ) ;
F_47 ( V_253 ) ;
F_47 ( V_507 ) ;
F_206 ( ( unsigned long ) V_485 ) ;
}
