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
F_47 ( V_33 -> V_208 [ V_199 ] ) ;
V_33 -> V_208 [ V_199 ] = NULL ;
}
}
static int F_51 ( struct V_30 * V_31 )
{
void * V_201 ;
int V_200 , V_209 ;
int V_34 , V_210 , V_211 ;
T_2 V_170 , V_212 ;
struct V_32 * V_33 , V_213 ;
struct V_214 * V_215 ;
struct V_149 * V_134 ;
char V_216 [ 60 ] , V_217 [ 60 ] ;
V_33 = V_31 -> V_33 ;
V_215 = & V_31 -> V_215 ;
V_212 = F_52 ( V_31 -> V_2 ) ;
V_209 = 0 ;
V_210 = 0 ;
for ( V_170 = 0x80 ; V_170 ; V_170 >>= 1 ) {
if ( ! ( V_170 & V_212 ) )
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
V_215 -> V_212 |= V_170 ;
continue;
}
if ( ! V_209 ) {
F_50 ( V_31 ) ;
V_33 -> V_201 = V_201 ;
V_33 -> V_200 = V_200 ;
if ( F_48 ( V_33 ) ) {
V_33 -> V_201 = NULL ;
V_33 -> V_200 = 0 ;
F_47 ( V_201 ) ;
continue;
}
V_211 = F_53 ( V_170 ) ;
V_33 -> V_208 [ V_211 ] =
(struct V_218 * ) V_201 ;
F_26 ( V_31 ) ;
V_209 ++ ;
} else {
V_213 . V_201 = V_201 ;
V_213 . V_200 = V_174 ;
if ( F_48 (
& V_213 ) ) {
V_213 . V_201 = NULL ;
V_213 . V_200 = 0 ;
F_47 ( V_201 ) ;
continue;
}
if ( F_31 (
V_31 , & V_213 ) ) {
V_134 = & V_213 . V_134 ;
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
V_210 = - V_128 ;
V_215 -> V_219 |= V_170 ;
continue;
}
V_211 = F_53 ( V_170 ) ;
V_33 -> V_208 [ V_211 ] =
(struct V_218 * ) V_201 ;
V_213 . V_201 = NULL ;
V_213 . V_200 = 0 ;
}
switch ( F_49 ( V_201 , V_200 ) ) {
case 0x02 :
V_215 -> V_220 |= V_170 ;
break;
case 0x03 :
V_215 -> V_221 |= V_170 ;
break;
}
if ( ! V_215 -> V_212 ) {
V_215 -> V_212 = V_170 ;
F_54 ( V_31 ) ;
} else {
V_215 -> V_212 |= V_170 ;
}
V_215 -> V_219 &= ~ V_170 ;
V_215 -> V_222 &= ~ V_170 ;
V_215 -> V_223 &= ~ V_170 ;
}
return V_210 ;
}
static int F_55 ( struct V_30 * V_31 , T_2 V_170 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
int V_224 ;
T_3 V_225 ;
if ( V_33 -> V_225 ) {
V_224 = F_56 ( V_31 -> V_2 , V_170 ) ;
if ( ( V_224 < 0 ) ) {
F_57 ( & V_31 -> V_2 -> V_82 ,
L_22
L_23 ,
V_224 , V_170 ) ;
return V_224 ;
}
V_225 = V_224 * V_226 ;
if ( V_225 < V_33 -> V_225 ) {
F_57 ( & V_31 -> V_2 -> V_82 ,
L_24
L_25
L_26 , V_225 , V_170 ,
V_33 -> V_225 ) ;
return - V_41 ;
}
}
return 0 ;
}
static int F_58 ( struct V_30 * V_31 ,
struct V_227 * V_29 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_214 * V_215 = & V_31 -> V_215 ;
T_2 V_170 , V_212 = V_215 -> V_212 ;
int V_34 = - V_165 ;
for ( V_170 = 0x80 ; V_170 ; V_170 >>= 1 ) {
if ( ! ( V_170 & V_212 ) )
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
L_27
L_28 , V_34 ) ;
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
static void F_59 ( struct V_228 * V_229 )
{
struct V_227 * V_29 ;
struct V_30 * V_31 ;
struct V_32 V_213 ;
struct V_149 * V_134 ;
T_2 V_230 [ V_174 ] ;
T_2 V_170 , V_212 , V_220 , V_221 , V_231 , V_222 , V_219 ;
unsigned long V_43 ;
char V_232 [ 60 ] ;
int V_34 ;
V_29 = F_60 ( V_229 , struct V_227 , V_233 ) ;
V_31 = V_29 -> V_31 ;
if ( F_61 ( V_234 , & V_31 -> V_43 ) ) {
F_62 ( V_229 ) ;
return;
}
if ( F_63 ( V_235 , & V_31 -> V_43 ) ) {
F_62 ( V_229 ) ;
return;
}
V_212 = 0 ;
V_220 = 0 ;
V_221 = 0 ;
V_231 = 0 ;
V_222 = 0 ;
V_219 = 0 ;
for ( V_170 = 0x80 ; V_170 ; V_170 >>= 1 ) {
if ( ! ( V_170 & V_29 -> V_236 ) )
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
V_220 |= V_170 ;
break;
case 0x03 :
V_221 |= V_170 ;
break;
}
V_212 |= V_170 ;
} else if ( V_34 == - V_40 ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_29
L_30 ) ;
V_212 |= V_170 ;
} else if ( V_34 == - V_237 ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_31
L_32 ) ;
V_231 |= V_170 ;
} else {
F_57 ( & V_31 -> V_2 -> V_82 ,
L_33
L_34 , V_34 , V_170 ) ;
continue;
}
if ( F_55 ( V_31 , V_170 ) ) {
V_212 &= ~ V_170 ;
V_220 &= ~ V_170 ;
V_221 &= ~ V_170 ;
V_222 |= V_170 ;
continue;
}
memcpy ( & V_230 , V_29 -> V_169 ,
V_174 ) ;
V_213 . V_201 = ( void * ) & V_230 ;
V_213 . V_200 = V_174 ;
if ( F_48 ( & V_213 ) ) {
V_213 . V_201 = NULL ;
V_213 . V_200 = 0 ;
continue;
}
if ( V_31 -> V_215 . V_212 &&
F_31 ( V_31 , & V_213 ) ) {
if ( F_58 ( V_31 , V_29 ) ||
F_31 (
V_31 , & V_213 ) ) {
V_134 = & V_213 . V_134 ;
if ( strlen ( V_134 -> V_163 ) > 0 )
snprintf ( V_232 , sizeof( V_232 ) ,
L_17 ,
V_134 -> V_150 , V_134 -> V_152 ,
V_134 -> V_154 , V_134 -> V_157 ,
V_134 -> V_163 ) ;
else
snprintf ( V_232 , sizeof( V_232 ) ,
L_18 ,
V_134 -> V_150 , V_134 -> V_152 ,
V_134 -> V_154 ,
V_134 -> V_157 ) ;
F_15 ( & V_31 -> V_2 -> V_82 ,
L_35
L_36
L_37 ,
V_170 , V_232 ) ;
V_212 &= ~ V_170 ;
V_220 &= ~ V_170 ;
V_221 &= ~ V_170 ;
V_219 |= V_170 ;
continue;
}
}
F_27 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
if ( ! V_31 -> V_215 . V_212 && V_212 ) {
V_31 -> V_215 . V_212 = V_212 ;
V_31 -> V_215 . V_219 &= ~ V_212 ;
V_31 -> V_215 . V_223 &= ~ V_212 ;
V_31 -> V_215 . V_222 &= ~ V_212 ;
F_54 ( V_31 ) ;
} else {
V_31 -> V_215 . V_212 |= V_212 ;
V_31 -> V_215 . V_219 &= ~ V_212 ;
V_31 -> V_215 . V_223 &= ~ V_212 ;
V_31 -> V_215 . V_222 &= ~ V_212 ;
}
V_31 -> V_215 . V_220 |= V_220 ;
V_31 -> V_215 . V_221 |= V_221 ;
V_31 -> V_215 . V_236 |= V_231 ;
V_31 -> V_215 . V_219 |= V_219 ;
V_31 -> V_215 . V_222 |= V_222 ;
F_29 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
}
F_39 ( V_235 , & V_31 -> V_43 ) ;
F_64 ( V_31 ) ;
if ( V_29 -> V_238 )
F_65 ( & V_239 ) ;
else
F_47 ( V_29 ) ;
}
static int F_66 ( struct V_30 * V_31 , T_2 V_170 )
{
struct V_227 * V_29 ;
V_29 = F_67 ( sizeof( * V_29 ) , V_240 | V_196 ) ;
if ( ! V_29 ) {
if ( F_68 ( & V_239 ) ) {
V_29 = V_241 ;
V_29 -> V_238 = 1 ;
} else
return - V_197 ;
} else {
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_29 -> V_238 = 0 ;
}
F_69 ( & V_29 -> V_233 , F_59 ) ;
F_70 ( V_31 ) ;
V_29 -> V_31 = V_31 ;
V_29 -> V_236 = V_170 ;
F_62 ( & V_29 -> V_233 ) ;
return 0 ;
}
static int F_71 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_242 * V_243 ;
struct V_244 * V_245 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
int V_34 ;
memset ( & V_33 -> V_245 , 0 , sizeof( struct V_244 ) ) ;
V_168 = F_43 ( V_176 , 1 + 1 ,
( sizeof( struct V_242 ) +
sizeof( struct V_244 ) ) ,
V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 , L_38
L_39 ) ;
return F_72 ( V_168 ) ;
}
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_178 = NULL ;
V_168 -> V_181 = 256 ;
V_168 -> V_179 = 10 * V_180 ;
V_243 = (struct V_242 * ) V_168 -> V_29 ;
memset ( V_243 , 0 , sizeof( struct V_242 ) ) ;
V_243 -> V_246 = V_247 ;
V_243 -> V_248 = 0x41 ;
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_249 ;
V_45 -> V_42 = sizeof( struct V_242 ) ;
V_45 -> V_43 |= V_250 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_243 ;
V_245 = (struct V_244 * ) ( V_243 + 1 ) ;
memset ( V_245 , 0 , sizeof( struct V_244 ) ) ;
V_45 ++ ;
V_45 -> V_54 = V_251 ;
V_45 -> V_42 = sizeof( struct V_244 ) ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_245 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_45 ( V_168 ) ;
if ( V_34 == 0 ) {
V_243 = (struct V_242 * ) V_168 -> V_29 ;
V_245 = (struct V_244 * ) ( V_243 + 1 ) ;
memcpy ( & V_33 -> V_245 , V_245 ,
sizeof( struct V_244 ) ) ;
} else
F_57 ( & V_31 -> V_2 -> V_82 , L_40
L_41 , V_34 ) ;
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static struct V_167 * F_73 ( struct V_30 * V_31 ,
int V_252 )
{
struct V_167 * V_168 ;
struct V_253 * V_254 ;
struct V_26 * V_45 ;
V_168 = F_43 ( V_176 , 1 ,
sizeof( struct V_253 ) ,
V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_18 ( V_7 , V_31 , L_1 ,
L_42 ) ;
return V_168 ;
}
V_254 = (struct V_253 * ) V_168 -> V_29 ;
V_254 -> V_246 = V_255 ;
V_254 -> V_248 = 0xc0 ;
if ( V_252 ) {
V_254 -> V_248 |= 0x08 ;
V_254 -> V_256 [ 0 ] = 0x88 ;
}
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_249 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_254 ;
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
F_74 ( struct V_30 * V_31 , int V_252 ,
unsigned long V_43 )
{
struct V_167 * V_168 ;
int V_34 ;
V_168 = F_73 ( V_31 , V_252 ) ;
if ( F_44 ( V_168 ) )
return F_72 ( V_168 ) ;
V_168 -> V_43 |= V_43 ;
V_34 = F_45 ( V_168 ) ;
if ( ! V_34 )
F_75 () ;
else if ( V_168 -> V_257 == - V_237 )
V_34 = - V_237 ;
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int F_76 ( struct V_30 * V_31 ,
unsigned long V_43 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
int V_252 , V_34 ;
if ( V_33 -> V_134 . type == V_160 ||
V_33 -> V_134 . type == V_137 )
return 0 ;
if ( V_258 || V_259 )
V_252 = 0 ;
else
V_252 = 1 ;
V_34 = F_74 ( V_31 , V_252 , V_43 ) ;
F_3 ( V_7 , V_31 -> V_2 , L_43
L_44 , V_33 -> V_134 . V_154 , V_34 ) ;
return V_34 ;
}
static void F_77 ( struct V_228 * V_229 )
{
struct V_30 * V_31 = F_60 ( V_229 , struct V_30 ,
V_260 ) ;
unsigned long V_43 = 0 ;
F_34 ( V_261 , & V_43 ) ;
if ( F_76 ( V_31 , V_43 )
== - V_237 ) {
F_62 ( & V_31 -> V_260 ) ;
return;
}
F_64 ( V_31 ) ;
}
static void F_78 ( struct V_30 * V_31 )
{
F_70 ( V_31 ) ;
if ( F_61 ( V_262 , & V_31 -> V_43 ) ||
V_31 -> V_263 < V_264 ) {
F_64 ( V_31 ) ;
return;
}
if ( ! F_62 ( & V_31 -> V_260 ) )
F_64 ( V_31 ) ;
}
static T_3 F_79 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
int V_265 , V_266 , V_267 ;
int V_268 , V_224 ;
if ( V_269 )
return 0 ;
V_265 = V_270 . V_271 ;
V_266 = V_33 -> V_155 -> V_272 [ 7 ] & 0x04 ;
V_267 = V_33 -> V_245 . V_273 [ 40 ] & 0x80 ;
V_268 = V_265 && V_266 && V_267 ;
if ( ! V_268 )
return 0 ;
V_224 = F_56 ( V_31 -> V_2 , 0 ) ;
if ( V_224 < 0 ) {
F_57 ( & V_31 -> V_2 -> V_82 , L_45
L_46 ) ;
return 0 ;
} else
return V_224 * V_226 ;
}
static int
F_80 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_274 * V_178 ;
struct V_149 V_275 ;
int V_34 , V_199 ;
int V_276 ;
unsigned long V_277 ;
F_69 ( & V_31 -> V_260 , F_77 ) ;
F_69 ( & V_31 -> V_278 , V_279 ) ;
if ( ! F_81 ( V_31 -> V_2 ) ) {
F_57 ( & V_31 -> V_2 -> V_82 ,
L_47 ) ;
return - V_280 ;
}
if ( ! F_82 ( V_31 -> V_2 ) ) {
F_83 ( & V_31 -> V_2 -> V_82 ,
L_48 ) ;
}
if ( ! V_33 ) {
V_33 = F_42 ( sizeof( * V_33 ) , V_195 | V_196 ) ;
if ( ! V_33 ) {
F_57 ( & V_31 -> V_2 -> V_82 ,
L_49
L_50 ) ;
return - V_197 ;
}
V_31 -> V_33 = V_33 ;
} else {
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
}
V_33 -> V_281 = - 1 ;
V_33 -> V_69 . V_68 = V_282 ;
V_33 -> V_69 . V_89 = 0 ;
V_34 = F_51 ( V_31 ) ;
if ( V_34 )
goto V_283;
V_31 -> V_284 = V_285 ;
V_31 -> V_286 = V_287 ;
if ( V_33 -> V_155 ) {
V_277 = 1 ;
for ( V_199 = 0 ; V_199 < V_33 -> V_155 -> V_288 . V_277 ; V_199 ++ )
V_277 = 10 * V_277 ;
V_277 = V_277 * V_33 -> V_155 -> V_288 . V_289 ;
if ( V_277 != 0 && V_277 <= V_290 )
V_31 -> V_284 = V_277 ;
}
F_30 ( V_31 , & V_275 ) ;
if ( V_275 . type == V_135 ) {
V_178 = F_84 () ;
if ( F_44 ( V_178 ) ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_51
L_52 ) ;
V_34 = F_72 ( V_178 ) ;
goto V_283;
}
V_31 -> V_178 = V_178 ;
V_178 -> V_291 = V_31 ;
}
V_34 = F_85 ( V_31 ) ;
if ( V_34 )
goto V_292;
F_76 ( V_31 , 0 ) ;
V_34 = F_51 ( V_31 ) ;
if ( V_34 )
goto V_293;
F_71 ( V_31 ) ;
V_34 = F_86 ( V_31 , V_176 ,
& V_33 -> V_35 , 64 ) ;
if ( V_34 ) {
F_3 ( V_7 , V_31 -> V_2 ,
L_53 , V_34 ) ;
goto V_293;
}
if ( ( V_31 -> V_245 & V_294 ) &&
! ( V_33 -> V_35 . V_36 . V_295 ) ) {
F_15 ( & V_31 -> V_2 -> V_82 , L_54
L_55 ) ;
V_34 = - V_128 ;
goto V_293;
}
if ( V_33 -> V_35 . V_296 == V_297 &&
V_33 -> V_35 . V_298 )
V_33 -> V_90 = V_33 -> V_35 . V_298 ;
else
V_33 -> V_90 = V_33 -> V_35 . V_296 ;
V_33 -> V_225 = F_79 ( V_31 ) ;
V_276 = F_87 ( V_31 ) ;
if ( V_276 )
F_34 ( V_299 , & V_31 -> V_43 ) ;
F_83 ( & V_31 -> V_2 -> V_82 , L_56
L_57 ,
V_33 -> V_35 . V_20 ,
V_33 -> V_35 . V_300 ,
V_33 -> V_35 . V_84 ,
V_33 -> V_35 . V_301 . V_302 ,
V_33 -> V_90 ,
V_33 -> V_35 . V_86 ,
V_33 -> V_35 . V_303 ,
V_276 ? L_58 : L_59 ) ;
return 0 ;
V_293:
F_88 ( V_31 ) ;
V_292:
F_89 ( V_31 -> V_178 ) ;
V_31 -> V_178 = NULL ;
V_283:
F_47 ( V_33 -> V_201 ) ;
F_47 ( V_31 -> V_33 ) ;
V_31 -> V_33 = NULL ;
return V_34 ;
}
static void F_90 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
int V_199 ;
F_88 ( V_31 ) ;
V_33 -> V_130 = NULL ;
V_33 -> V_158 = NULL ;
V_33 -> V_162 = NULL ;
V_33 -> V_155 = NULL ;
V_33 -> V_200 = 0 ;
for ( V_199 = 0 ; V_199 < 8 ; V_199 ++ ) {
F_47 ( V_33 -> V_208 [ V_199 ] ) ;
if ( ( T_2 * ) V_33 -> V_208 [ V_199 ] ==
V_33 -> V_201 ) {
V_33 -> V_201 = NULL ;
V_33 -> V_200 = 0 ;
}
V_33 -> V_208 [ V_199 ] = NULL ;
}
F_47 ( V_33 -> V_201 ) ;
V_33 -> V_201 = NULL ;
}
static struct V_167 *
F_91 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_304 * V_305 ;
struct V_140 * V_306 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
int V_307 , V_308 ;
int V_199 ;
V_307 = 8 ;
V_308 = sizeof( struct V_28 ) + 2 * sizeof( struct V_140 ) ;
V_168 = F_43 ( V_176 , V_307 , V_308 , V_31 ) ;
if ( F_44 ( V_168 ) )
return V_168 ;
V_45 = V_168 -> V_171 ;
F_13 ( V_45 ++ , V_168 -> V_29 , 0 , 2 ,
V_70 , V_31 ) ;
V_306 = V_168 -> V_29 + sizeof( struct V_28 ) ;
V_45 [ - 1 ] . V_43 |= V_250 ;
V_126 ( V_45 ++ , V_306 ++ , 0 , 0 , 4 ,
V_70 , V_31 , 0 ) ;
V_305 = V_33 -> V_309 ;
for ( V_199 = 0 ; V_199 < 4 ; V_199 ++ ) {
V_45 [ - 1 ] . V_43 |= V_250 ;
V_45 -> V_54 = V_70 ;
V_45 -> V_43 = 0 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_305 ;
V_45 ++ ;
V_305 ++ ;
}
V_45 [ - 1 ] . V_43 |= V_250 ;
V_126 ( V_45 ++ , V_306 ++ , 2 , 0 , 1 ,
V_70 , V_31 , 0 ) ;
V_45 [ - 1 ] . V_43 |= V_250 ;
V_45 -> V_54 = V_70 ;
V_45 -> V_43 = 0 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_305 ;
V_168 -> V_178 = NULL ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_181 = 255 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
return V_168 ;
}
static int F_92 ( struct V_167 * V_310 )
{
char * V_311 ;
if ( V_310 -> V_183 == V_186 )
return V_312 ;
else if ( V_310 -> V_183 == V_313 ||
V_310 -> V_183 == V_314 ) {
V_311 = F_93 ( & V_310 -> V_315 ) ;
if ( V_311 && ( V_311 [ 1 ] & V_316 ) )
return V_317 ;
else
return V_318 ;
} else
return V_318 ;
}
static void F_94 ( struct V_167 * V_310 ,
void * V_29 )
{
struct V_30 * V_31 = V_310 -> V_119 ;
struct V_32 * V_33 = V_31 -> V_33 ;
V_33 -> V_281 = F_92 ( V_310 ) ;
F_46 ( V_310 , V_31 ) ;
F_95 ( V_31 ) ;
}
static int F_96 ( struct V_274 * V_178 )
{
struct V_167 * V_310 ;
V_310 = F_91 ( V_178 -> V_291 ) ;
if ( F_44 ( V_310 ) )
return F_72 ( V_310 ) ;
V_310 -> V_191 = F_94 ;
V_310 -> V_319 = NULL ;
V_310 -> V_179 = 5 * V_180 ;
F_39 ( V_189 , & V_310 -> V_43 ) ;
V_310 -> V_181 = 0 ;
F_97 ( V_310 ) ;
return - V_237 ;
}
static int F_98 ( struct V_274 * V_178 )
{
struct V_30 * V_31 = V_178 -> V_291 ;
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_304 * V_309 ;
unsigned int V_320 , V_145 ;
int V_183 , V_199 ;
struct V_167 * V_310 ;
V_183 = V_33 -> V_281 ;
V_33 -> V_281 = - 1 ;
if ( V_183 == V_318 ) {
V_310 = F_91 ( V_31 ) ;
F_45 ( V_310 ) ;
V_183 = F_92 ( V_310 ) ;
F_46 ( V_310 , V_31 ) ;
}
if ( V_31 -> V_245 & V_294 ) {
V_178 -> V_321 = V_322 ;
V_145 = V_323 ;
V_178 -> V_324 = 3 ;
goto V_325;
}
if ( V_183 == V_317 ) {
F_57 ( & V_31 -> V_2 -> V_82 , L_60 ) ;
return - V_326 ;
} else if ( V_183 == V_318 ) {
F_15 ( & V_31 -> V_2 -> V_82 ,
L_61
L_62 ) ;
return - V_280 ;
}
V_33 -> V_85 = 1 ;
V_309 = NULL ;
for ( V_199 = 0 ; V_199 < 3 ; V_199 ++ ) {
if ( V_33 -> V_309 [ V_199 ] . V_16 != 4 ||
V_33 -> V_309 [ V_199 ] . V_17 != F_23 ( V_199 ) - 4 ||
V_33 -> V_309 [ V_199 ] . V_23 != 0 ||
V_33 -> V_309 [ V_199 ] . V_24 != V_327 [ V_199 ] ||
V_33 -> V_309 [ V_199 ] . V_117 != V_328 [ V_199 ] ) {
V_33 -> V_85 = 0 ;
break;
}
}
if ( V_199 == 3 )
V_309 = & V_33 -> V_309 [ 4 ] ;
if ( V_33 -> V_85 == 0 ) {
for ( V_199 = 0 ; V_199 < 5 ; V_199 ++ ) {
if ( ( V_33 -> V_309 [ V_199 ] . V_16 != 0 ) ||
( V_33 -> V_309 [ V_199 ] . V_17 !=
V_33 -> V_309 [ 0 ] . V_17 ) ||
V_33 -> V_309 [ V_199 ] . V_23 != 0 ||
V_33 -> V_309 [ V_199 ] . V_24 != V_327 [ V_199 ] ||
V_33 -> V_309 [ V_199 ] . V_117 != V_328 [ V_199 ] )
break;
}
if ( V_199 == 5 )
V_309 = & V_33 -> V_309 [ 0 ] ;
} else {
if ( V_33 -> V_309 [ 3 ] . V_117 == 1 )
F_57 ( & V_31 -> V_2 -> V_82 ,
L_63 ) ;
}
if ( V_309 != NULL && V_309 -> V_16 == 0 ) {
if ( F_99 ( V_309 -> V_17 ) == 0 )
V_178 -> V_321 = V_309 -> V_17 ;
}
if ( V_178 -> V_321 == 0 ) {
F_57 ( & V_31 -> V_2 -> V_82 ,
L_64 ) ;
return - V_326 ;
}
V_178 -> V_324 = 0 ;
for ( V_320 = 512 ; V_320 < V_178 -> V_321 ; V_320 = V_320 << 1 )
V_178 -> V_324 ++ ;
V_145 = F_9 ( & V_33 -> V_35 , 0 , V_178 -> V_321 ) ;
V_325:
V_178 -> V_329 = ( V_33 -> V_90 *
V_33 -> V_35 . V_86 *
V_145 ) ;
F_83 ( & V_31 -> V_2 -> V_82 ,
L_65
L_66 , ( V_178 -> V_321 >> 10 ) ,
( ( V_33 -> V_90 *
V_33 -> V_35 . V_86 *
V_145 * ( V_178 -> V_321 >> 9 ) ) >> 1 ) ,
( ( V_145 * V_178 -> V_321 ) >> 10 ) ,
V_33 -> V_85 ?
L_67 : L_68 ) ;
return 0 ;
}
static int F_100 ( struct V_274 * V_178 )
{
struct V_32 * V_33 = V_178 -> V_291 -> V_33 ;
if ( V_33 -> V_281 < 0 )
return F_96 ( V_178 ) ;
else
return F_98 ( V_178 ) ;
}
static int F_101 ( struct V_30 * V_31 )
{
return F_102 ( V_31 ) ;
}
static int F_103 ( struct V_30 * V_31 )
{
F_104 ( & V_31 -> V_330 ) ;
F_104 ( & V_31 -> V_260 ) ;
return 0 ;
}
static int F_105 ( struct V_30 * V_31 )
{
return F_106 ( V_31 ) ;
}
static int
F_107 ( struct V_274 * V_178 , struct V_331 * V_22 )
{
struct V_32 * V_33 = V_178 -> V_291 -> V_33 ;
if ( F_99 ( V_178 -> V_321 ) == 0 ) {
V_22 -> V_332 = F_9 ( & V_33 -> V_35 ,
0 , V_178 -> V_321 ) ;
}
V_22 -> V_333 = V_33 -> V_35 . V_296 ;
V_22 -> V_51 = V_33 -> V_35 . V_86 ;
return 0 ;
}
static struct V_167 *
F_108 ( struct V_30 * V_291 , struct V_334 * V_335 ,
int V_252 , struct V_304 * V_336 ,
int V_337 )
{
struct V_32 * V_338 ;
struct V_30 * V_119 = NULL ;
struct V_339 * V_340 = NULL ;
struct V_167 * V_168 ;
struct V_341 * V_341 ;
int V_342 ;
int V_42 ;
int V_34 ;
int V_199 ;
if ( V_252 )
V_119 = F_109 ( V_291 ) ;
if ( ! V_119 )
V_119 = V_291 ;
V_338 = V_119 -> V_33 ;
V_42 = V_337 * ( V_335 -> V_343 - V_335 -> V_344 + 1 ) ;
V_342 = F_110 ( 0 , V_42 , 0 ) ;
V_168 = F_43 ( V_176 , 0 , V_342 , V_119 ) ;
if ( F_44 ( V_168 ) )
return V_168 ;
V_338 -> V_42 ++ ;
V_341 = F_111 ( V_168 -> V_29 , V_342 , V_345 , 0 , V_42 , 0 ) ;
if ( F_44 ( V_341 ) ) {
V_34 = - V_128 ;
goto V_346;
}
V_168 -> V_171 = F_112 ( V_341 ) ;
V_34 = F_113 ( V_341 , V_335 -> V_344 , V_335 -> V_343 ,
V_347 , V_291 , V_119 , 0 , V_42 ,
sizeof( struct V_304 ) ,
V_42 * sizeof( struct V_304 ) , 0 , V_337 ) ;
if ( V_34 )
goto V_346;
for ( V_199 = 0 ; V_199 < V_42 ; V_199 ++ ) {
V_340 = F_114 ( V_341 , 0 , V_336 ++ ,
sizeof( struct V_304 ) ) ;
if ( F_44 ( V_340 ) ) {
V_34 = - V_128 ;
goto V_346;
}
}
V_340 -> V_43 |= V_348 ;
F_115 ( V_341 ) ;
V_168 -> V_349 = 1 ;
V_168 -> V_119 = V_119 ;
V_168 -> V_177 = V_119 ;
V_168 -> V_118 = V_291 ;
V_168 -> V_181 = V_119 -> V_286 ;
V_168 -> V_179 = V_119 -> V_284 * V_180 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
F_34 ( V_350 , & V_168 -> V_43 ) ;
F_34 ( V_351 , & V_168 -> V_43 ) ;
return V_168 ;
V_346:
F_46 ( V_168 , V_119 ) ;
return F_116 ( V_34 ) ;
}
static struct V_167 *
F_117 ( struct V_30 * V_291 , struct V_334 * V_335 ,
int V_252 , struct V_304 * V_336 , int V_337 )
{
struct V_32 * V_338 ;
struct V_32 * V_352 ;
struct V_30 * V_119 = NULL ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
void * V_29 ;
int V_307 , V_308 ;
int V_353 ;
int V_42 ;
int V_199 ;
if ( V_252 )
V_119 = F_109 ( V_291 ) ;
if ( ! V_119 )
V_119 = V_291 ;
V_338 = V_119 -> V_33 ;
V_352 = V_291 -> V_33 ;
V_42 = V_337 * ( V_335 -> V_343 - V_335 -> V_344 + 1 ) ;
V_353 = V_352 -> V_245 . V_273 [ 8 ] & 0x01 ;
if ( V_353 ) {
V_307 = 1 ;
V_308 = sizeof( struct V_93 ) ;
} else {
V_307 = 2 ;
V_308 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) ;
}
V_307 += V_42 ;
V_168 = F_43 ( V_176 , V_307 , V_308 ,
V_119 ) ;
if ( F_44 ( V_168 ) )
return V_168 ;
V_338 -> V_42 ++ ;
V_29 = V_168 -> V_29 ;
V_45 = V_168 -> V_171 ;
if ( V_353 ) {
F_20 ( V_45 ++ , V_29 , V_335 -> V_344 , V_335 -> V_343 ,
V_70 , V_291 , V_119 , 1 , 0 ,
V_42 , 0 , 0 ) ;
} else {
F_13 ( V_45 ++ , V_29 , V_335 -> V_344 , V_335 -> V_343 ,
V_70 , V_119 ) ;
V_29 += sizeof( struct V_28 ) ;
V_45 [ - 1 ] . V_43 |= V_250 ;
V_126 ( V_45 ++ , V_29 , V_335 -> V_344 , 0 , V_42 ,
V_70 , V_291 , 0 ) ;
}
for ( V_199 = 0 ; V_199 < V_42 ; V_199 ++ ) {
V_45 [ - 1 ] . V_43 |= V_250 ;
V_45 -> V_54 = V_70 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_336 ;
V_45 ++ ;
V_336 ++ ;
}
V_168 -> V_119 = V_119 ;
V_168 -> V_177 = V_119 ;
V_168 -> V_118 = V_291 ;
V_168 -> V_181 = V_287 ;
V_168 -> V_179 = V_119 -> V_284 * V_180 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
F_34 ( V_354 , & V_168 -> V_43 ) ;
return V_168 ;
}
static struct V_167 *
F_118 ( struct V_30 * V_291 ,
struct V_334 * V_335 ,
int V_252 )
{
struct V_32 * V_352 ;
struct V_32 * V_338 ;
struct V_30 * V_119 = NULL ;
struct V_167 * V_355 ;
struct V_304 * V_356 ;
struct V_21 V_357 ;
struct V_26 * V_45 ;
void * V_29 ;
int V_337 ;
int V_307 , V_308 ;
int V_199 , V_358 ;
int V_359 = 0 ;
int V_360 ;
int V_361 ;
int V_353 ;
if ( V_252 )
V_119 = F_109 ( V_291 ) ;
if ( ! V_119 )
V_119 = V_291 ;
V_338 = V_119 -> V_33 ;
V_352 = V_291 -> V_33 ;
V_337 = F_9 ( & V_352 -> V_35 , 0 , V_335 -> V_121 ) ;
V_361 = V_335 -> V_343 - V_335 -> V_344 + 1 ;
if ( V_335 -> V_359 & 0x10 ) {
V_360 = 0 ;
V_359 = V_335 -> V_359 & ~ 0x10 ;
} else {
V_360 = 1 ;
V_359 = V_335 -> V_359 ;
}
V_353 = V_352 -> V_245 . V_273 [ 8 ] & 0x01 ;
switch ( V_359 ) {
case 0x00 :
case 0x08 :
V_307 = 2 + ( V_337 * V_361 ) ;
if ( V_353 )
V_308 = sizeof( struct V_93 ) +
sizeof( struct V_140 ) +
V_337 * V_361 * sizeof( struct V_304 ) ;
else
V_308 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
V_337 * V_361 * sizeof( struct V_304 ) ;
break;
case 0x01 :
case 0x09 :
V_307 = 2 + V_337 * V_361 ;
if ( V_353 )
V_308 = sizeof( struct V_93 ) +
sizeof( struct V_140 ) +
sizeof( struct V_304 ) +
V_337 * V_361 * sizeof( struct V_304 ) ;
else
V_308 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
sizeof( struct V_304 ) +
V_337 * V_361 * sizeof( struct V_304 ) ;
break;
case 0x04 :
case 0x0c :
V_307 = 3 ;
if ( V_353 )
V_308 = sizeof( struct V_93 ) +
sizeof( struct V_140 ) +
sizeof( struct V_304 ) ;
else
V_308 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
sizeof( struct V_304 ) ;
break;
default:
F_57 ( & V_119 -> V_2 -> V_82 ,
L_69 ,
V_335 -> V_359 ) ;
return F_116 ( - V_128 ) ;
}
V_355 = F_43 ( V_176 , V_307 ,
V_308 , V_119 ) ;
if ( F_44 ( V_355 ) )
return V_355 ;
V_338 -> V_42 ++ ;
V_29 = V_355 -> V_29 ;
V_45 = V_355 -> V_171 ;
switch ( V_359 & ~ 0x08 ) {
case 0x00 :
if ( V_353 ) {
F_21 ( V_45 ++ , (struct V_93 * ) V_29 ,
V_335 -> V_344 , V_335 -> V_343 ,
V_76 , V_291 , V_119 ) ;
if ( V_360 )
( (struct V_93 * ) V_29 )
-> F_13 . V_38 |= 0x04 ;
V_29 += sizeof( struct V_93 ) ;
} else {
F_13 ( V_45 ++ , (struct V_28 * ) V_29 ,
V_335 -> V_344 , V_335 -> V_343 ,
V_76 , V_119 ) ;
if ( V_360 )
( (struct V_28 * ) V_29 )
-> V_38 |= 0x04 ;
V_29 += sizeof( struct V_28 ) ;
}
V_45 [ - 1 ] . V_43 |= V_250 ;
V_126 ( V_45 ++ , (struct V_140 * ) V_29 ,
V_335 -> V_344 , 0 , V_337 * V_361 ,
V_76 , V_291 ,
V_335 -> V_121 ) ;
V_29 += sizeof( struct V_140 ) ;
break;
case 0x01 :
if ( V_353 ) {
F_21 ( V_45 ++ , (struct V_93 * ) V_29 ,
V_335 -> V_344 , V_335 -> V_343 ,
V_80 ,
V_291 , V_119 ) ;
V_29 += sizeof( struct V_93 ) ;
} else {
F_13 ( V_45 ++ , (struct V_28 * ) V_29 ,
V_335 -> V_344 , V_335 -> V_343 ,
V_80 , V_119 ) ;
V_29 += sizeof( struct V_28 ) ;
}
V_45 [ - 1 ] . V_43 |= V_250 ;
V_126 ( V_45 ++ , (struct V_140 * ) V_29 ,
V_335 -> V_344 , 0 , V_337 * V_361 + 1 ,
V_80 , V_291 ,
V_291 -> V_178 -> V_321 ) ;
V_29 += sizeof( struct V_140 ) ;
break;
case 0x04 :
if ( V_353 ) {
F_21 ( V_45 ++ , (struct V_93 * ) V_29 ,
V_335 -> V_344 , V_335 -> V_343 ,
V_76 , V_291 , V_119 ) ;
V_29 += sizeof( struct V_93 ) ;
} else {
F_13 ( V_45 ++ , (struct V_28 * ) V_29 ,
V_335 -> V_344 , V_335 -> V_343 ,
V_76 , V_119 ) ;
V_29 += sizeof( struct V_28 ) ;
}
V_45 [ - 1 ] . V_43 |= V_250 ;
V_126 ( V_45 ++ , (struct V_140 * ) V_29 ,
V_335 -> V_344 , 0 , 1 ,
V_76 , V_291 , 8 ) ;
V_29 += sizeof( struct V_140 ) ;
break;
}
for ( V_358 = 0 ; V_358 < V_361 ; V_358 ++ ) {
F_10 ( & V_357 ,
( V_335 -> V_344 + V_358 ) /
V_352 -> V_35 . V_86 ,
( V_335 -> V_344 + V_358 ) %
V_352 -> V_35 . V_86 ) ;
if ( V_359 & 0x01 ) {
V_356 = (struct V_304 * ) V_29 ;
V_29 += sizeof( struct V_304 ) ;
V_356 -> V_23 = V_357 . V_23 ;
V_356 -> V_24 = V_357 . V_24 ;
V_356 -> V_117 = 0 ;
V_356 -> V_16 = 0 ;
V_356 -> V_17 = 8 ;
V_45 [ - 1 ] . V_43 |= V_250 ;
V_45 -> V_54 = V_80 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_356 ;
V_45 ++ ;
}
if ( ( V_359 & ~ 0x08 ) & 0x04 ) {
V_356 = (struct V_304 * ) V_29 ;
V_29 += sizeof( struct V_304 ) ;
V_356 -> V_23 = V_357 . V_23 ;
V_356 -> V_24 = V_357 . V_24 ;
V_356 -> V_117 = 1 ;
V_356 -> V_16 = 0 ;
V_356 -> V_17 = 0 ;
V_45 [ - 1 ] . V_43 |= V_250 ;
V_45 -> V_54 = V_76 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_356 ;
} else {
for ( V_199 = 0 ; V_199 < V_337 ; V_199 ++ ) {
V_356 = (struct V_304 * ) V_29 ;
V_29 += sizeof( struct V_304 ) ;
V_356 -> V_23 = V_357 . V_23 ;
V_356 -> V_24 = V_357 . V_24 ;
V_356 -> V_117 = V_199 + 1 ;
V_356 -> V_16 = 0 ;
V_356 -> V_17 = V_335 -> V_121 ;
if ( ( V_359 & 0x08 ) &&
V_357 . V_23 == 0 && V_357 . V_24 == 0 ) {
if ( V_199 < 3 ) {
V_356 -> V_16 = 4 ;
V_356 -> V_17 = V_147 [ V_199 ] - 4 ;
}
}
if ( ( V_359 & 0x08 ) &&
V_357 . V_23 == 0 && V_357 . V_24 == 1 ) {
V_356 -> V_16 = 44 ;
V_356 -> V_17 = V_148 - 44 ;
}
V_45 [ - 1 ] . V_43 |= V_250 ;
if ( V_199 != 0 || V_358 == 0 )
V_45 -> V_54 =
V_76 ;
else
V_45 -> V_54 =
V_77 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_356 ;
V_45 ++ ;
}
}
}
V_355 -> V_119 = V_119 ;
V_355 -> V_177 = V_119 ;
V_355 -> V_118 = V_291 ;
V_355 -> V_181 = 256 ;
V_355 -> V_179 = V_119 -> V_284 * V_180 ;
V_355 -> V_182 = F_33 () ;
V_355 -> V_183 = V_184 ;
return V_355 ;
}
static struct V_167 *
F_119 ( struct V_30 * V_291 ,
struct V_334 * V_335 , int V_252 ,
int V_268 , struct V_304 * V_336 , int V_337 )
{
struct V_167 * V_362 ;
if ( ! V_336 ) {
V_362 = F_118 ( V_291 , V_335 , V_252 ) ;
} else {
if ( V_268 )
V_362 = F_108 ( V_291 , V_335 ,
V_252 ,
V_336 , V_337 ) ;
else
V_362 = F_117 ( V_291 , V_335 , V_252 ,
V_336 , V_337 ) ;
}
return V_362 ;
}
static int F_120 ( struct V_30 * V_291 ,
struct V_334 * V_335 )
{
struct V_32 * V_33 = V_291 -> V_33 ;
if ( V_335 -> V_344 >=
( V_33 -> V_90 * V_33 -> V_35 . V_86 ) ) {
F_57 ( & V_291 -> V_2 -> V_82 ,
L_70 ,
V_335 -> V_344 ) ;
return - V_128 ;
}
if ( V_335 -> V_343 >=
( V_33 -> V_90 * V_33 -> V_35 . V_86 ) ) {
F_57 ( & V_291 -> V_2 -> V_82 ,
L_71 ,
V_335 -> V_343 ) ;
return - V_128 ;
}
if ( V_335 -> V_344 > V_335 -> V_343 ) {
F_57 ( & V_291 -> V_2 -> V_82 ,
L_72 ,
V_335 -> V_344 ) ;
return - V_128 ;
}
if ( F_99 ( V_335 -> V_121 ) != 0 ) {
F_57 ( & V_291 -> V_2 -> V_82 ,
L_73 ,
V_335 -> V_121 ) ;
return - V_128 ;
}
return 0 ;
}
static int F_121 ( struct V_30 * V_291 ,
struct V_334 * V_335 ,
int V_252 , int V_268 ,
struct V_304 * V_336 , int V_337 ,
struct V_315 * V_315 )
{
struct V_32 * V_33 = V_291 -> V_33 ;
struct V_167 * V_168 , * V_363 ;
struct V_364 V_365 ;
struct V_30 * V_31 ;
char * V_311 = NULL ;
int V_366 , V_367 , V_368 ;
int V_369 , V_370 ;
int V_34 ;
V_34 = F_120 ( V_291 , V_335 ) ;
if ( V_34 )
return V_34 ;
F_122 ( & V_365 ) ;
V_366 = V_335 -> V_344 ;
V_367 = V_335 -> V_343 ;
if ( ! V_268 && V_336 != NULL ) {
V_368 = 1 ;
} else if ( V_268 && V_336 != NULL ) {
V_368 = V_371 / V_337 ;
} else {
V_368 = V_371 /
F_9 ( & V_33 -> V_35 , 0 , V_335 -> V_121 ) ;
}
do {
V_370 = 0 ;
while ( V_335 -> V_344 <= V_367 ) {
V_369 = V_335 -> V_343 - V_335 -> V_344 + 1 ;
if ( V_369 > V_368 ) {
V_335 -> V_343 =
V_335 -> V_344 + V_368 - 1 ;
}
V_168 = F_119 ( V_291 , V_335 ,
V_252 , V_268 ,
V_336 , V_337 ) ;
if ( F_44 ( V_168 ) ) {
V_34 = F_72 ( V_168 ) ;
if ( V_34 == - V_197 ) {
if ( F_123 ( & V_365 ) )
goto V_372;
V_370 = 1 ;
break;
}
goto V_346;
}
F_124 ( & V_168 -> V_373 , & V_365 ) ;
if ( V_336 ) {
V_369 = V_335 -> V_343 - V_335 -> V_344 + 1 ;
V_336 += V_337 * V_369 ;
}
V_335 -> V_344 = V_335 -> V_343 + 1 ;
V_335 -> V_343 = V_367 ;
}
V_34 = F_125 ( & V_365 ) ;
V_346:
F_126 (cqr, n, &format_queue, blocklist) {
V_31 = V_168 -> V_119 ;
V_33 = V_31 -> V_33 ;
if ( V_168 -> V_183 == V_314 ) {
if ( V_336 && V_315 ) {
V_311 = F_93 ( & V_168 -> V_315 ) ;
memcpy ( V_315 , & V_168 -> V_315 , sizeof( * V_315 ) ) ;
}
V_34 = - V_280 ;
}
F_127 ( & V_168 -> V_373 ) ;
F_46 ( V_168 , V_31 ) ;
V_33 -> V_42 -- ;
}
if ( V_34 && V_34 != - V_280 )
goto V_372;
if ( V_34 == - V_280 ) {
if ( V_311 &&
( V_311 [ 1 ] & V_316 ||
V_311 [ 1 ] & V_374 ) )
V_370 = 1 ;
else
goto V_372;
}
} while ( V_370 );
V_372:
V_335 -> V_344 = V_366 ;
V_335 -> V_343 = V_367 ;
return V_34 ;
}
static int F_128 ( struct V_30 * V_291 ,
struct V_334 * V_335 , int V_252 )
{
return F_121 ( V_291 , V_335 , V_252 , 0 , NULL ,
0 , NULL ) ;
}
static int F_129 ( struct V_304 * V_336 , int V_375 ,
int V_376 )
{
int V_24 ;
int V_199 ;
V_24 = V_336 [ V_375 ] . V_24 ;
for ( V_199 = V_375 ; V_199 < V_376 ; V_199 ++ ) {
if ( V_199 > V_375 ) {
if ( ( V_336 [ V_199 ] . V_24 == V_24 &&
V_336 [ V_199 ] . V_117 == 1 ) ||
V_336 [ V_199 ] . V_24 != V_24 ||
V_336 [ V_199 ] . V_117 == 0 )
break;
}
}
return V_199 - V_375 ;
}
static void F_130 ( struct V_304 * V_336 ,
struct V_377 * V_378 ,
int V_379 , int V_380 ,
int V_86 , int V_268 )
{
struct V_21 V_22 ;
int V_381 ;
int V_42 = 0 ;
int V_382 ;
int V_121 ;
int V_211 = 0 ;
int V_199 , V_358 ;
int V_16 ;
V_382 = V_378 -> V_383 . V_343 - V_378 -> V_383 . V_344 + 1 ;
V_381 = V_382 * V_379 ;
for ( V_199 = V_378 -> V_383 . V_344 ; V_199 <= V_378 -> V_383 . V_343 ; V_199 ++ ) {
if ( V_268 ) {
while ( V_336 [ V_211 ] . V_117 == 0 &&
V_336 [ V_211 ] . V_17 == 0 ) {
if ( V_211 ++ > V_381 )
break;
}
} else {
if ( V_199 != V_378 -> V_383 . V_344 )
V_211 += V_379 - V_42 ;
}
F_10 ( & V_22 , V_199 / V_86 , V_199 % V_86 ) ;
V_42 = F_129 ( V_336 , V_211 , V_211 + V_379 ) ;
if ( V_42 < V_380 ) {
V_378 -> V_384 = V_385 ;
break;
}
if ( V_42 > V_380 ) {
V_378 -> V_384 = V_386 ;
break;
}
for ( V_358 = 0 ; V_358 < V_42 ; V_358 ++ , V_211 ++ ) {
V_121 = V_378 -> V_383 . V_121 ;
V_16 = 0 ;
if ( ( V_378 -> V_383 . V_359 & 0x08 ) &&
V_22 . V_23 == 0 && V_22 . V_24 == 0 ) {
if ( V_358 < 3 ) {
V_121 = V_147 [ V_358 ] - 4 ;
V_16 = 4 ;
}
}
if ( ( V_378 -> V_383 . V_359 & 0x08 ) &&
V_22 . V_23 == 0 && V_22 . V_24 == 1 ) {
V_121 = V_148 - 44 ;
V_16 = 44 ;
}
if ( V_336 [ V_211 ] . V_17 != V_121 ) {
V_378 -> V_384 = V_387 ;
goto V_372;
}
if ( V_336 [ V_211 ] . V_16 != V_16 ) {
V_378 -> V_384 = V_388 ;
goto V_372;
}
if ( V_336 [ V_211 ] . V_23 != V_22 . V_23 ||
V_336 [ V_211 ] . V_24 != V_22 . V_24 ||
V_336 [ V_211 ] . V_117 != ( V_358 + 1 ) ) {
V_378 -> V_384 = V_389 ;
goto V_372;
}
}
}
V_372:
if ( ! V_378 -> V_384 ) {
V_199 -- ;
V_211 -- ;
}
V_378 -> V_390 = V_199 ;
V_378 -> V_391 = V_42 ;
V_378 -> V_392 = V_336 [ V_211 ] . V_117 ;
V_378 -> V_121 = V_336 [ V_211 ] . V_17 ;
V_378 -> V_393 = V_336 [ V_211 ] . V_16 ;
}
static int F_131 ( struct V_30 * V_291 ,
struct V_377 * V_378 ,
int V_252 )
{
struct V_32 * V_33 = V_291 -> V_33 ;
struct V_304 * V_336 ;
struct V_315 V_315 ;
int V_379 , V_380 ;
int V_394 ;
int V_86 ;
int V_382 ;
int V_268 = 0 ;
int V_34 ;
V_86 = V_33 -> V_35 . V_86 ;
V_379 = F_9 ( & V_33 -> V_35 , 0 , 512 ) + 1 ;
V_380 = F_9 ( & V_33 -> V_35 , 0 , V_378 -> V_383 . V_121 ) ;
V_382 = V_378 -> V_383 . V_343 - V_378 -> V_383 . V_344 + 1 ;
V_394 = V_382 * V_379 * sizeof( struct V_304 ) ;
V_336 = F_42 ( V_394 , V_195 | V_196 ) ;
if ( ! V_336 )
return - V_197 ;
if ( ( V_33 -> V_245 . V_273 [ 40 ] & 0x04 ) &&
V_394 <= V_33 -> V_225 )
V_268 = 1 ;
V_34 = F_121 ( V_291 , & V_378 -> V_383 , V_252 ,
V_268 , V_336 , V_379 , & V_315 ) ;
if ( V_34 && V_34 != - V_280 )
goto V_372;
if ( V_34 == - V_280 ) {
if ( V_268 && F_132 ( & V_315 . V_395 ) == 0x40 ) {
V_268 = 0 ;
V_34 = F_121 ( V_291 , & V_378 -> V_383 ,
V_252 , V_268 ,
V_336 , V_379 ,
& V_315 ) ;
if ( V_34 )
goto V_372;
} else {
goto V_372;
}
}
F_130 ( V_336 , V_378 , V_379 , V_380 ,
V_86 , V_268 ) ;
V_372:
F_47 ( V_336 ) ;
return V_34 ;
}
static void F_133 ( struct V_167 * V_168 )
{
if ( V_168 -> V_181 < 0 ) {
V_168 -> V_183 = V_314 ;
return;
}
V_168 -> V_183 = V_184 ;
if ( V_168 -> V_178 && ( V_168 -> V_119 != V_168 -> V_178 -> V_291 ) ) {
F_134 ( V_168 ) ;
V_168 -> V_119 = V_168 -> V_178 -> V_291 ;
V_168 -> V_170 = V_168 -> V_178 -> V_291 -> V_215 . V_212 ;
}
}
static T_5
F_135 ( struct V_167 * V_168 )
{
struct V_30 * V_31 = (struct V_30 * ) V_168 -> V_119 ;
struct V_1 * V_2 = V_31 -> V_2 ;
switch ( V_2 -> V_396 . V_84 ) {
case 0x3990 :
case 0x2105 :
case 0x2107 :
case 0x1750 :
return V_397 ;
case 0x9343 :
case 0x3880 :
default:
return V_398 ;
}
}
static T_5
F_136 ( struct V_167 * V_168 )
{
return V_399 ;
}
static void F_137 ( struct V_30 * V_31 ,
struct V_167 * V_168 ,
struct V_315 * V_315 )
{
char V_65 ;
char * V_311 = NULL ;
struct V_32 * V_33 = V_31 -> V_33 ;
V_65 = V_400 | V_401 | V_402 ;
if ( ( F_138 ( & V_315 -> V_395 ) & V_65 ) == V_65 ) {
if ( ! V_31 -> V_178 && V_33 -> V_403 &&
V_31 -> V_263 == V_264 &&
! F_61 ( V_262 , & V_31 -> V_43 ) &&
! F_61 ( V_234 , & V_31 -> V_43 ) ) {
F_139 ( V_31 ) ;
}
F_140 ( V_31 ) ;
return;
}
V_311 = F_93 ( V_315 ) ;
if ( ! V_311 )
return;
if ( ( V_311 [ 27 ] & V_404 ) && ( V_311 [ 7 ] == 0x0D ) &&
( F_138 ( & V_315 -> V_395 ) & V_405 ) ) {
if ( F_63 ( V_406 , & V_31 -> V_43 ) ) {
F_18 ( V_7 , V_31 , L_1 ,
L_74 ) ;
return;
}
V_311 = F_93 ( V_315 ) ;
if ( ! V_311 ) {
F_18 ( V_7 , V_31 , L_1 ,
L_75 ) ;
F_39 ( V_406 , & V_31 -> V_43 ) ;
return;
}
V_33 -> V_407 = V_311 [ 8 ] ;
F_18 ( V_408 , V_31 , L_76 ,
L_77 ,
V_33 -> V_407 ) ;
F_70 ( V_31 ) ;
if ( ! F_62 ( & V_31 -> V_278 ) )
F_64 ( V_31 ) ;
return;
}
if ( ! V_168 && ! ( V_311 [ 27 ] & V_404 ) &&
( ( V_311 [ 6 ] & V_409 ) == V_409 ) ) {
F_141 ( V_31 , V_311 ) ;
return;
}
if ( V_31 -> V_178 && ( V_311 [ 27 ] & V_404 ) &&
( V_311 [ 7 ] == 0x3F ) &&
( F_138 ( & V_315 -> V_395 ) & V_405 ) &&
F_61 ( V_410 , & V_31 -> V_43 ) ) {
if ( V_31 -> V_245 & V_411 )
F_34 ( V_412 , & V_31 -> V_43 ) ;
F_39 ( V_410 , & V_31 -> V_43 ) ;
F_15 ( & V_31 -> V_2 -> V_82 ,
L_78 ) ;
}
}
static struct V_167 * F_142 (
struct V_30 * V_119 ,
struct V_274 * V_178 ,
struct V_413 * V_414 ,
T_6 V_415 ,
T_6 V_416 ,
T_6 V_417 ,
T_6 V_418 ,
unsigned int V_419 ,
unsigned int V_420 ,
unsigned int V_145 ,
unsigned int V_121 )
{
struct V_32 * V_33 ;
unsigned long * V_421 ;
struct V_140 * V_306 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
struct V_422 V_423 ;
struct V_424 V_425 ;
char * V_426 ;
unsigned int V_427 ;
int V_42 , V_428 , V_307 , V_308 ;
T_6 V_146 ;
unsigned char V_48 , V_429 ;
int V_353 ;
struct V_30 * V_118 ;
V_118 = V_178 -> V_291 ;
V_33 = V_118 -> V_33 ;
if ( F_143 ( V_414 ) == V_430 )
V_48 = V_60 ;
else if ( F_143 ( V_414 ) == V_431 )
V_48 = V_73 ;
else
return F_116 ( - V_128 ) ;
V_42 = 0 ;
V_428 = 0 ;
F_144 (bv, req, iter) {
if ( V_425 . V_432 & ( V_121 - 1 ) )
return F_116 ( - V_128 ) ;
V_42 += V_425 . V_432 >> ( V_178 -> V_324 + 9 ) ;
if ( F_145 ( F_146 ( V_425 . V_433 ) , V_425 . V_432 ) )
V_428 += V_425 . V_432 >> ( V_178 -> V_324 + 9 ) ;
}
if ( V_42 != V_416 - V_415 + 1 )
return F_116 ( - V_128 ) ;
V_353 = V_33 -> V_245 . V_273 [ 8 ] & 0x01 ;
if ( V_353 ) {
V_307 = 2 + V_42 ;
V_308 = sizeof( struct V_93 ) +
sizeof( struct V_140 ) +
V_428 * sizeof( unsigned long ) ;
} else {
V_307 = 2 + V_42 ;
V_308 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
V_428 * sizeof( unsigned long ) ;
}
if ( V_33 -> V_85 && V_415 < 2 * V_145 ) {
if ( V_416 >= 2 * V_145 )
V_42 = 2 * V_145 - V_415 ;
V_307 += V_42 ;
V_308 += V_42 * sizeof( struct V_140 ) ;
}
V_168 = F_43 ( V_176 , V_307 , V_308 ,
V_119 ) ;
if ( F_44 ( V_168 ) )
return V_168 ;
V_45 = V_168 -> V_171 ;
if ( V_353 ) {
if ( F_21 ( V_45 ++ , V_168 -> V_29 , V_417 ,
V_418 , V_48 , V_118 , V_119 ) == - V_237 ) {
F_46 ( V_168 , V_119 ) ;
return F_116 ( - V_237 ) ;
}
V_421 = ( unsigned long * ) ( V_168 -> V_29 +
sizeof( struct V_93 ) ) ;
} else {
if ( F_13 ( V_45 ++ , V_168 -> V_29 , V_417 ,
V_418 , V_48 , V_118 ) == - V_237 ) {
F_46 ( V_168 , V_119 ) ;
return F_116 ( - V_237 ) ;
}
V_421 = ( unsigned long * ) ( V_168 -> V_29 +
sizeof( struct V_28 ) ) ;
}
V_306 = (struct V_140 * ) ( V_421 + V_428 ) ;
V_146 = V_415 ;
if ( V_33 -> V_85 == 0 || V_146 > 2 * V_145 ) {
V_45 [ - 1 ] . V_43 |= V_250 ;
V_126 ( V_45 ++ , V_306 ++ , V_417 , V_419 + 1 ,
V_416 - V_146 + 1 , V_48 , V_118 , V_121 ) ;
}
F_144 (bv, req, iter) {
V_426 = F_146 ( V_425 . V_433 ) + V_425 . V_434 ;
if ( V_435 ) {
char * V_436 = F_147 ( V_435 ,
V_196 | V_437 ) ;
if ( V_436 && F_143 ( V_414 ) == V_431 )
memcpy ( V_436 + V_425 . V_434 , V_426 , V_425 . V_432 ) ;
if ( V_436 )
V_426 = V_436 + V_425 . V_434 ;
}
for ( V_427 = 0 ; V_427 < V_425 . V_432 ; V_427 += V_121 ) {
T_6 V_438 = V_146 ;
unsigned int V_439 = F_148 ( V_438 , V_145 ) ;
V_429 = V_48 ;
V_42 = V_121 ;
if ( V_33 -> V_85 && V_146 < 2 * V_145 ) {
if ( F_22 ( V_145 , V_146 ) ) {
V_429 |= 0x8 ;
V_42 = F_23 ( V_146 ) ;
if ( V_42 < V_121 &&
F_143 ( V_414 ) == V_430 )
memset ( V_426 + V_42 , 0xe5 ,
V_121 - V_42 ) ;
}
V_45 [ - 1 ] . V_43 |= V_250 ;
V_126 ( V_45 ++ , V_306 ++ ,
V_438 , V_439 + 1 ,
1 , V_429 , V_118 , V_42 ) ;
}
if ( V_33 -> V_85 && V_146 == 2 * V_145 ) {
V_45 [ - 1 ] . V_43 |= V_250 ;
V_126 ( V_45 ++ , V_306 ++ ,
V_438 , V_439 + 1 ,
V_416 - V_146 + 1 ,
V_48 , V_118 , V_42 ) ;
}
V_45 [ - 1 ] . V_43 |= V_250 ;
V_45 -> V_54 = V_429 ;
V_45 -> V_42 = V_42 ;
if ( F_145 ( V_426 , V_121 ) ) {
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_421 ;
V_45 -> V_43 = V_440 ;
V_421 = F_149 ( V_421 , V_426 , V_121 ) ;
} else {
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_426 ;
V_45 -> V_43 = 0 ;
}
V_45 ++ ;
V_426 += V_121 ;
V_146 ++ ;
}
}
if ( F_150 ( V_414 ) ||
V_178 -> V_291 -> V_245 & V_441 )
F_34 ( V_261 , & V_168 -> V_43 ) ;
V_168 -> V_119 = V_119 ;
V_168 -> V_177 = V_119 ;
V_168 -> V_178 = V_178 ;
V_168 -> V_179 = V_119 -> V_284 * V_180 ;
V_168 -> V_170 = V_119 -> V_215 . V_221 ;
V_168 -> V_181 = V_119 -> V_286 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
return V_168 ;
}
static struct V_167 * F_151 (
struct V_30 * V_119 ,
struct V_274 * V_178 ,
struct V_413 * V_414 ,
T_6 V_415 ,
T_6 V_416 ,
T_6 V_417 ,
T_6 V_418 ,
unsigned int V_419 ,
unsigned int V_420 ,
unsigned int V_145 ,
unsigned int V_121 )
{
unsigned long * V_421 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
struct V_422 V_423 ;
struct V_424 V_425 ;
char * V_426 , * V_442 ;
unsigned int V_428 , V_307 , V_308 ;
unsigned int V_100 ;
T_6 V_146 ;
unsigned char V_48 ;
struct V_30 * V_118 ;
unsigned int V_382 , V_42 , V_443 ;
unsigned int V_444 , V_445 , V_446 , V_447 ;
unsigned char V_448 , V_449 ;
T_6 V_438 ;
unsigned int V_439 ;
V_118 = V_178 -> V_291 ;
if ( F_143 ( V_414 ) == V_430 )
V_48 = V_113 ;
else if ( F_143 ( V_414 ) == V_431 )
V_48 = V_111 ;
else
return F_116 ( - V_128 ) ;
V_428 = V_416 - V_415 + 1 ;
V_382 = V_418 - V_417 + 1 ;
V_307 = 1 + V_382 ;
V_308 = sizeof( struct V_93 ) +
V_428 * sizeof( unsigned long long ) ;
V_168 = F_43 ( V_176 , V_307 , V_308 ,
V_119 ) ;
if ( F_44 ( V_168 ) )
return V_168 ;
V_45 = V_168 -> V_171 ;
if ( V_417 == V_418 )
V_100 = V_420 - V_419 + 1 ;
else
V_100 = V_420 + 1 ;
V_100 *= V_121 ;
if ( F_20 ( V_45 ++ , V_168 -> V_29 , V_417 ,
V_418 , V_48 , V_118 , V_119 ,
1 , V_419 + 1 ,
V_382 , V_121 ,
V_100 ) == - V_237 ) {
F_46 ( V_168 , V_119 ) ;
return F_116 ( - V_237 ) ;
}
V_421 = ( unsigned long * ) ( V_168 -> V_29 + sizeof( struct V_93 ) ) ;
V_146 = V_415 ;
V_448 = 1 ;
V_449 = 0 ;
V_447 = 0 ;
V_442 = NULL ;
V_444 = 0 ;
F_144 (bv, req, iter) {
V_426 = F_146 ( V_425 . V_433 ) + V_425 . V_434 ;
V_445 = V_425 . V_432 ;
while ( V_445 ) {
if ( V_448 ) {
V_438 = V_146 ;
V_439 = F_148 ( V_438 , V_145 ) ;
V_443 = V_145 - V_439 ;
V_42 = F_152 ( ( V_416 - V_146 + 1 ) ,
( T_6 ) V_443 ) ;
V_447 = V_42 * V_121 ;
V_45 [ - 1 ] . V_43 |= V_250 ;
V_45 -> V_54 = V_48 ;
V_45 -> V_42 = V_447 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_421 ;
V_45 -> V_43 = V_440 ;
V_45 ++ ;
V_146 += V_42 ;
V_448 = 0 ;
if ( ! V_442 )
V_442 = V_426 ;
}
if ( ! V_442 ) {
if ( F_14 ( V_426 ) & ( V_450 - 1 ) ) {
F_46 ( V_168 , V_119 ) ;
return F_116 ( - V_451 ) ;
} else
V_442 = V_426 ;
}
if ( ( V_442 + V_444 ) != V_426 ) {
F_46 ( V_168 , V_119 ) ;
return F_116 ( - V_451 ) ;
}
V_446 = F_152 ( V_445 , V_447 ) ;
V_445 -= V_446 ;
V_426 += V_446 ;
V_444 += V_446 ;
V_447 -= V_446 ;
if ( ! ( F_14 ( V_442 + V_444 ) & ( V_450 - 1 ) ) )
V_449 = 1 ;
if ( ! V_447 ) {
V_448 = 1 ;
V_449 = 1 ;
}
if ( V_449 ) {
V_421 = F_149 ( V_421 , V_442 ,
V_444 ) ;
V_442 = NULL ;
V_444 = 0 ;
V_449 = 0 ;
}
}
}
if ( F_150 ( V_414 ) ||
V_178 -> V_291 -> V_245 & V_441 )
F_34 ( V_261 , & V_168 -> V_43 ) ;
V_168 -> V_119 = V_119 ;
V_168 -> V_177 = V_119 ;
V_168 -> V_178 = V_178 ;
V_168 -> V_179 = V_119 -> V_284 * V_180 ;
V_168 -> V_170 = V_119 -> V_215 . V_221 ;
V_168 -> V_181 = V_119 -> V_286 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
return V_168 ;
}
static int F_113 ( struct V_341 * V_341 ,
unsigned int V_46 , unsigned int V_47 , int V_48 ,
struct V_30 * V_118 ,
struct V_30 * V_119 ,
unsigned int V_98 , int V_42 ,
unsigned int V_121 ,
unsigned int V_452 ,
unsigned int V_100 ,
unsigned int V_145 )
{
struct V_93 V_94 ;
struct V_32 * V_122 , * V_123 ;
struct V_28 * V_124 ;
struct V_97 * V_125 ;
struct V_453 * V_453 ;
T_3 V_49 , V_50 ;
T_4 V_51 , V_52 , V_53 ;
T_7 V_454 ;
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
V_125 -> V_104 . V_455 = 0x01 ;
V_454 = V_456 ;
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
V_125 -> V_104 . V_455 = 0x2 ;
V_454 = V_127 ;
break;
case V_347 :
V_124 -> V_65 . V_66 = 0x1 ;
V_124 -> V_67 . V_68 = V_71 ;
V_124 -> V_38 |= 0x42 ;
V_124 -> V_139 = V_121 ;
V_125 -> V_68 . V_103 = 0x2 ;
V_125 -> V_68 . V_68 = 0x16 ;
V_125 -> V_104 . V_455 = 0x01 ;
V_454 = V_456 ;
break;
default:
F_18 ( V_114 , V_118 ,
L_79 , V_48 ) ;
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
V_124 -> V_457 = 0x20 ;
V_124 -> V_458 = V_145 ;
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
if ( V_48 == V_347 ) {
V_125 -> V_104 . V_105 = 0 ;
V_125 -> V_104 . V_459 = 0 ;
V_125 -> V_101 = 0xff ;
} else {
V_125 -> V_104 . V_105 = 1 ;
V_125 -> V_104 . V_459 = 1 ;
V_125 -> V_101 = V_101 ;
}
V_125 -> V_104 . V_460 = 1 ;
V_125 -> V_106 = V_100 ;
V_125 -> V_461 = V_48 ;
V_125 -> V_42 = V_42 ;
F_10 ( & V_125 -> V_115 , V_49 , V_52 ) ;
V_125 -> V_116 . V_23 = V_125 -> V_115 . V_23 ;
V_125 -> V_116 . V_24 = V_125 -> V_115 . V_24 ;
V_125 -> V_116 . V_117 = V_98 ;
V_453 = F_153 ( V_341 , V_454 , 0 ,
& V_94 , sizeof( V_94 ) , V_452 ) ;
return F_154 ( V_453 ) ;
}
static struct V_167 * F_155 (
struct V_30 * V_119 ,
struct V_274 * V_178 ,
struct V_413 * V_414 ,
T_6 V_415 ,
T_6 V_416 ,
T_6 V_417 ,
T_6 V_418 ,
unsigned int V_419 ,
unsigned int V_420 ,
unsigned int V_145 ,
unsigned int V_121 )
{
struct V_167 * V_168 ;
struct V_422 V_423 ;
struct V_424 V_425 ;
char * V_426 ;
unsigned int V_382 , V_462 ;
unsigned char V_48 ;
struct V_30 * V_118 ;
unsigned int V_100 ;
struct V_341 * V_341 ;
struct V_339 * V_340 = NULL ;
int V_463 ;
T_8 V_342 ;
T_7 V_464 ;
unsigned int V_445 , V_446 , V_447 ;
unsigned char V_448 ;
T_6 V_146 , V_438 ;
unsigned int V_465 ;
unsigned int V_42 , V_443 ;
int V_3 ;
V_118 = V_178 -> V_291 ;
if ( F_143 ( V_414 ) == V_430 ) {
V_48 = V_113 ;
V_463 = V_345 ;
} else if ( F_143 ( V_414 ) == V_431 ) {
V_48 = V_111 ;
V_463 = V_466 ;
} else
return F_116 ( - V_128 ) ;
V_382 = V_418 - V_417 + 1 ;
V_462 = 0 ;
F_144 (bv, req, iter) {
++ V_462 ;
}
if ( F_143 ( V_414 ) == V_431 )
V_462 += ( V_418 - V_417 ) ;
V_342 = F_110 ( 0 , V_462 , 0 ) ;
V_168 = F_43 ( V_176 , 0 , V_342 , V_119 ) ;
if ( F_44 ( V_168 ) )
return V_168 ;
if ( V_417 == V_418 )
V_100 = V_420 - V_419 + 1 ;
else
V_100 = V_420 + 1 ;
V_100 *= V_121 ;
V_341 = F_111 ( V_168 -> V_29 , V_342 , V_463 , 0 , V_462 , 0 ) ;
if ( F_44 ( V_341 ) ) {
V_3 = - V_128 ;
goto V_194;
}
V_168 -> V_171 = F_112 ( V_341 ) ;
if ( F_113 ( V_341 , V_417 , V_418 ,
V_48 , V_118 , V_119 ,
V_419 + 1 ,
V_382 , V_121 ,
( V_416 - V_415 + 1 ) * V_121 ,
V_100 , V_145 ) == - V_237 ) {
V_3 = - V_237 ;
goto V_194;
}
V_447 = 0 ;
if ( F_143 ( V_414 ) == V_431 ) {
V_448 = 1 ;
V_146 = V_415 ;
F_144 (bv, req, iter) {
V_426 = F_146 ( V_425 . V_433 ) + V_425 . V_434 ;
V_445 = V_425 . V_432 ;
while ( V_445 ) {
if ( V_448 ) {
V_438 = V_146 ;
V_465 = F_148 ( V_438 , V_145 ) ;
V_443 = V_145 - V_465 ;
V_42 = F_152 ( ( V_416 - V_146 + 1 ) ,
( T_6 ) V_443 ) ;
V_447 = V_42 * V_121 ;
V_146 += V_42 ;
V_448 = 0 ;
}
V_446 = F_152 ( V_445 , V_447 ) ;
V_445 -= V_446 ;
V_447 -= V_446 ;
if ( ! V_447 ) {
V_448 = 1 ;
V_464 = V_467 ;
} else
V_464 = 0 ;
V_340 = F_114 ( V_341 , V_464 ,
V_426 , V_446 ) ;
if ( F_44 ( V_340 ) ) {
V_3 = - V_128 ;
goto V_194;
}
V_426 += V_446 ;
}
}
} else {
F_144 (bv, req, iter) {
V_426 = F_146 ( V_425 . V_433 ) + V_425 . V_434 ;
V_340 = F_114 ( V_341 , 0x00 ,
V_426 , V_425 . V_432 ) ;
if ( F_44 ( V_340 ) ) {
V_3 = - V_128 ;
goto V_194;
}
}
}
V_340 -> V_43 |= V_348 ;
V_340 -> V_43 &= ~ V_467 ;
F_115 ( V_341 ) ;
if ( F_150 ( V_414 ) ||
V_178 -> V_291 -> V_245 & V_441 )
F_34 ( V_261 , & V_168 -> V_43 ) ;
V_168 -> V_349 = 1 ;
V_168 -> V_119 = V_119 ;
V_168 -> V_177 = V_119 ;
V_168 -> V_178 = V_178 ;
V_168 -> V_179 = V_119 -> V_284 * V_180 ;
V_168 -> V_170 = V_119 -> V_215 . V_221 ;
V_168 -> V_181 = V_119 -> V_286 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
return V_168 ;
V_194:
F_46 ( V_168 , V_119 ) ;
return F_116 ( V_3 ) ;
}
static struct V_167 * F_156 ( struct V_30 * V_119 ,
struct V_274 * V_178 ,
struct V_413 * V_414 )
{
int V_468 , V_469 ;
int V_353 ;
int V_470 ;
struct V_32 * V_33 ;
struct V_30 * V_118 ;
T_6 V_415 , V_416 ;
T_6 V_417 , V_418 ;
unsigned int V_419 , V_420 ;
unsigned int V_145 , V_121 ;
int V_471 ;
unsigned int V_472 ;
struct V_167 * V_168 ;
V_118 = V_178 -> V_291 ;
V_33 = V_118 -> V_33 ;
V_121 = V_178 -> V_321 ;
V_145 = F_9 ( & V_33 -> V_35 , 0 , V_121 ) ;
if ( V_145 == 0 )
return F_116 ( - V_128 ) ;
V_415 = V_417 = F_157 ( V_414 ) >> V_178 -> V_324 ;
V_419 = F_148 ( V_417 , V_145 ) ;
V_416 = V_418 =
( F_157 ( V_414 ) + F_158 ( V_414 ) - 1 ) >> V_178 -> V_324 ;
V_420 = F_148 ( V_418 , V_145 ) ;
V_471 = ( V_33 -> V_85 && V_415 < 2 * V_145 ) ;
V_470 = V_33 -> V_245 . V_273 [ 40 ] & 0x20 ;
V_472 = F_159 ( V_414 ) ;
if ( V_472 % V_121 )
return F_116 ( - V_128 ) ;
if ( F_143 ( V_414 ) == V_431 )
V_472 += ( V_418 - V_417 ) * 4 ;
V_468 = V_33 -> V_245 . V_273 [ 9 ] & 0x20 ;
V_469 = V_33 -> V_245 . V_273 [ 12 ] & 0x40 ;
V_353 = V_33 -> V_245 . V_273 [ 8 ] & 0x01 ;
V_168 = NULL ;
if ( V_471 || V_435 ) {
} else if ( ( V_472 <= V_33 -> V_225 )
&& ( V_470 || ( V_417 == V_418 ) ) ) {
V_168 = F_155 ( V_119 , V_178 , V_414 ,
V_415 , V_416 ,
V_417 , V_418 ,
V_419 , V_420 ,
V_145 , V_121 ) ;
if ( F_44 ( V_168 ) && ( F_72 ( V_168 ) != - V_237 ) &&
( F_72 ( V_168 ) != - V_197 ) )
V_168 = NULL ;
} else if ( V_353 &&
( ( ( F_143 ( V_414 ) == V_430 ) && V_468 ) ||
( ( F_143 ( V_414 ) == V_431 ) && V_469 ) ) ) {
V_168 = F_151 ( V_119 , V_178 , V_414 ,
V_415 , V_416 ,
V_417 , V_418 ,
V_419 , V_420 ,
V_145 , V_121 ) ;
if ( F_44 ( V_168 ) && ( F_72 ( V_168 ) != - V_237 ) &&
( F_72 ( V_168 ) != - V_197 ) )
V_168 = NULL ;
}
if ( ! V_168 )
V_168 = F_142 ( V_119 , V_178 , V_414 ,
V_415 , V_416 ,
V_417 , V_418 ,
V_419 , V_420 ,
V_145 , V_121 ) ;
return V_168 ;
}
static struct V_167 * F_160 ( struct V_30 * V_119 ,
struct V_274 * V_178 ,
struct V_413 * V_414 )
{
unsigned long * V_421 ;
struct V_30 * V_118 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
struct V_422 V_423 ;
struct V_424 V_425 ;
char * V_426 ;
unsigned char V_48 ;
unsigned int V_382 ;
unsigned int V_445 , V_447 ;
unsigned int V_419 ;
unsigned int V_428 , V_307 , V_308 ;
T_6 V_417 , V_418 , V_332 ;
T_6 V_473 , V_474 , V_475 ;
unsigned int V_476 ;
V_473 = F_157 ( V_414 ) % V_477 ;
V_474 = ( F_157 ( V_414 ) + F_158 ( V_414 ) ) %
V_477 ;
V_475 = ( V_477 - V_474 ) %
V_477 ;
V_118 = V_178 -> V_291 ;
if ( ( V_473 || V_475 ) &&
( F_143 ( V_414 ) == V_431 ) ) {
F_18 ( V_114 , V_118 ,
L_80 ,
V_473 , V_475 , V_414 ) ;
V_168 = F_116 ( - V_128 ) ;
goto V_372;
}
V_417 = F_157 ( V_414 ) / V_477 ;
V_418 = ( F_157 ( V_414 ) + F_158 ( V_414 ) - 1 ) /
V_477 ;
V_382 = V_418 - V_417 + 1 ;
V_419 = 0 ;
if ( F_143 ( V_414 ) == V_430 )
V_48 = V_112 ;
else if ( F_143 ( V_414 ) == V_431 )
V_48 = V_107 ;
else {
V_168 = F_116 ( - V_128 ) ;
goto V_372;
}
V_428 = V_382 * V_323 ;
V_307 = 1 + V_382 ;
V_476 = sizeof( struct V_93 ) + 8 ;
V_308 = V_476 + V_428 * sizeof( unsigned long long ) ;
V_168 = F_43 ( V_176 , V_307 ,
V_308 , V_119 ) ;
if ( F_44 ( V_168 ) )
goto V_372;
V_45 = V_168 -> V_171 ;
if ( F_20 ( V_45 ++ , V_168 -> V_29 , V_417 , V_418 , V_48 ,
V_118 , V_119 , 1 , V_419 + 1 ,
V_382 , 0 , 0 ) == - V_237 ) {
F_46 ( V_168 , V_119 ) ;
V_168 = F_116 ( - V_237 ) ;
goto V_372;
}
V_421 = ( unsigned long * ) ( V_168 -> V_29 + V_476 ) ;
V_447 = 0 ;
if ( V_473 ) {
V_45 [ - 1 ] . V_43 |= V_250 ;
V_45 -> V_54 = V_48 ;
V_45 -> V_42 = 57326 ;
V_447 = 65536 - V_473 * 512 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_421 ;
V_45 -> V_43 |= V_440 ;
V_45 -> V_43 |= V_44 ;
V_45 ++ ;
for ( V_332 = 0 ; V_332 < V_473 ; V_332 += 8 )
V_421 = F_149 ( V_421 , V_478 , V_479 ) ;
}
F_144 (bv, req, iter) {
V_426 = F_146 ( V_425 . V_433 ) + V_425 . V_434 ;
V_445 = V_425 . V_432 ;
if ( V_48 == V_112 )
memset ( V_426 , 0 , V_445 ) ;
if ( ! V_447 ) {
V_45 [ - 1 ] . V_43 |= V_250 ;
V_45 -> V_54 = V_48 ;
V_45 -> V_42 = 57326 ;
V_447 = 65536 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_421 ;
V_45 -> V_43 |= V_440 ;
V_45 -> V_43 |= V_44 ;
V_45 ++ ;
}
V_447 -= V_445 ;
V_421 = F_149 ( V_421 , V_426 , V_445 ) ;
}
for ( V_332 = 0 ; V_332 < V_475 ; V_332 += 8 )
V_421 = F_149 ( V_421 , V_478 , V_479 ) ;
if ( F_150 ( V_414 ) ||
V_178 -> V_291 -> V_245 & V_441 )
F_34 ( V_261 , & V_168 -> V_43 ) ;
V_168 -> V_119 = V_119 ;
V_168 -> V_177 = V_119 ;
V_168 -> V_178 = V_178 ;
V_168 -> V_179 = V_119 -> V_284 * V_180 ;
V_168 -> V_170 = V_119 -> V_215 . V_221 ;
V_168 -> V_181 = V_119 -> V_286 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
if ( F_44 ( V_168 ) && F_72 ( V_168 ) != - V_237 )
V_168 = NULL ;
V_372:
return V_168 ;
}
static int
F_161 ( struct V_167 * V_168 , struct V_413 * V_414 )
{
struct V_32 * V_33 ;
struct V_26 * V_45 ;
struct V_422 V_423 ;
struct V_424 V_425 ;
char * V_426 , * V_56 ;
unsigned int V_121 , V_145 , V_427 ;
T_6 V_146 ;
int V_183 ;
if ( ! V_435 )
goto V_372;
V_33 = V_168 -> V_178 -> V_291 -> V_33 ;
V_121 = V_168 -> V_178 -> V_321 ;
V_145 = F_9 ( & V_33 -> V_35 , 0 , V_121 ) ;
V_146 = F_157 ( V_414 ) >> V_168 -> V_178 -> V_324 ;
V_45 = V_168 -> V_171 ;
V_45 ++ ;
if ( V_33 -> V_85 == 0 || V_146 > 2 * V_145 )
V_45 ++ ;
F_144 (bv, req, iter) {
V_426 = F_146 ( V_425 . V_433 ) + V_425 . V_434 ;
for ( V_427 = 0 ; V_427 < V_425 . V_432 ; V_427 += V_121 ) {
if ( V_33 -> V_85 && V_146 <= 2 * V_145 )
V_45 ++ ;
if ( V_426 ) {
if ( V_45 -> V_43 & V_440 )
V_56 = * ( ( char * * ) ( ( V_173 ) V_45 -> V_56 ) ) ;
else
V_56 = ( char * ) ( ( V_173 ) V_45 -> V_56 ) ;
if ( V_426 != V_56 ) {
if ( F_143 ( V_414 ) == V_430 )
memcpy ( V_426 , V_56 , V_425 . V_432 ) ;
F_162 ( V_435 ,
( void * ) ( ( V_173 ) V_56 & V_480 ) ) ;
}
V_426 = NULL ;
}
V_45 ++ ;
V_146 ++ ;
}
}
V_372:
V_183 = V_168 -> V_183 == V_186 ;
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_183 ;
}
void F_134 ( struct V_167 * V_168 )
{
struct V_26 * V_45 ;
struct V_93 * V_94 ;
struct V_481 * V_481 ;
struct V_482 * V_482 ;
struct V_453 * V_453 ;
if ( V_168 -> V_349 == 1 ) {
V_481 = V_168 -> V_171 ;
V_482 = F_163 ( V_481 ) ;
V_453 = (struct V_453 * ) & V_482 -> V_483 [ 0 ] ;
V_94 = (struct V_93 * ) & V_453 -> V_484 [ 0 ] ;
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
static struct V_167 * F_164 ( struct V_30 * V_291 ,
struct V_274 * V_178 ,
struct V_413 * V_414 )
{
struct V_32 * V_33 ;
struct V_30 * V_119 ;
unsigned long V_43 ;
struct V_167 * V_168 ;
V_119 = F_109 ( V_291 ) ;
if ( ! V_119 )
V_119 = V_291 ;
V_33 = V_119 -> V_33 ;
if ( V_33 -> V_42 >= V_485 )
return F_116 ( - V_486 ) ;
F_27 ( F_28 ( V_119 -> V_2 ) , V_43 ) ;
V_33 -> V_42 ++ ;
if ( ( V_291 -> V_245 & V_294 ) )
V_168 = F_160 ( V_119 , V_178 , V_414 ) ;
else
V_168 = F_156 ( V_119 , V_178 , V_414 ) ;
if ( F_44 ( V_168 ) )
V_33 -> V_42 -- ;
F_29 ( F_28 ( V_119 -> V_2 ) , V_43 ) ;
return V_168 ;
}
static int F_165 ( struct V_167 * V_168 ,
struct V_413 * V_414 )
{
struct V_32 * V_33 ;
unsigned long V_43 ;
F_27 ( F_28 ( V_168 -> V_177 -> V_2 ) , V_43 ) ;
V_33 = V_168 -> V_177 -> V_33 ;
V_33 -> V_42 -- ;
F_29 ( F_28 ( V_168 -> V_177 -> V_2 ) , V_43 ) ;
return F_161 ( V_168 , V_414 ) ;
}
static int
F_166 ( struct V_30 * V_31 ,
struct V_487 * V_488 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
V_488 -> V_489 = 2 ;
V_488 -> V_490 = V_33 -> V_85 ? 0 : 1 ;
V_488 -> V_120 = V_33 -> V_85 ? V_491 : V_492 ;
V_488 -> V_493 = sizeof( V_33 -> V_35 ) ;
memcpy ( V_488 -> V_494 , & V_33 -> V_35 ,
sizeof( V_33 -> V_35 ) ) ;
V_488 -> V_495 = F_152 ( ( unsigned long ) V_33 -> V_200 ,
sizeof( V_488 -> V_496 ) ) ;
memcpy ( V_488 -> V_496 , V_33 -> V_201 ,
V_488 -> V_495 ) ;
return 0 ;
}
static int
F_167 ( struct V_30 * V_31 )
{
struct V_167 * V_168 ;
int V_34 ;
struct V_26 * V_45 ;
int V_497 ;
if ( ! F_168 ( V_498 ) )
return - V_41 ;
V_497 = 0 ;
V_168 = F_43 ( V_176 , 1 , 32 , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_169 ( & V_499 ) ;
V_497 = 1 ;
V_168 = & V_500 -> V_168 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
memset ( & V_500 -> V_45 , 0 ,
sizeof( V_500 -> V_45 ) ) ;
V_168 -> V_171 = & V_500 -> V_45 ;
V_168 -> V_29 = & V_500 -> V_29 ;
V_168 -> V_175 = V_176 ;
}
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_501 ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_42 = 32 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_168 -> V_29 ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
F_39 ( V_189 , & V_168 -> V_43 ) ;
F_34 ( V_261 , & V_168 -> V_43 ) ;
V_168 -> V_181 = 2 ;
V_168 -> V_179 = 2 * V_180 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_40 ( V_168 ) ;
if ( ! V_34 )
F_39 ( V_410 , & V_31 -> V_43 ) ;
if ( V_497 )
F_65 ( & V_499 ) ;
else
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int
F_170 ( struct V_30 * V_31 )
{
struct V_167 * V_168 ;
int V_34 ;
struct V_26 * V_45 ;
int V_497 ;
if ( ! F_168 ( V_498 ) )
return - V_41 ;
V_497 = 0 ;
V_168 = F_43 ( V_176 , 1 , 32 , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_169 ( & V_499 ) ;
V_497 = 1 ;
V_168 = & V_500 -> V_168 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
memset ( & V_500 -> V_45 , 0 ,
sizeof( V_500 -> V_45 ) ) ;
V_168 -> V_171 = & V_500 -> V_45 ;
V_168 -> V_29 = & V_500 -> V_29 ;
V_168 -> V_175 = V_176 ;
}
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_502 ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_42 = 32 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_168 -> V_29 ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
F_39 ( V_189 , & V_168 -> V_43 ) ;
F_34 ( V_261 , & V_168 -> V_43 ) ;
V_168 -> V_181 = 2 ;
V_168 -> V_179 = 2 * V_180 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_40 ( V_168 ) ;
if ( ! V_34 )
F_34 ( V_410 , & V_31 -> V_43 ) ;
if ( V_497 )
F_65 ( & V_499 ) ;
else
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int
F_171 ( struct V_30 * V_31 )
{
struct V_167 * V_168 ;
int V_34 ;
struct V_26 * V_45 ;
int V_497 ;
if ( ! F_168 ( V_498 ) )
return - V_41 ;
V_497 = 0 ;
V_168 = F_43 ( V_176 , 1 , 32 , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_169 ( & V_499 ) ;
V_497 = 1 ;
V_168 = & V_500 -> V_168 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
memset ( & V_500 -> V_45 , 0 ,
sizeof( V_500 -> V_45 ) ) ;
V_168 -> V_171 = & V_500 -> V_45 ;
V_168 -> V_29 = & V_500 -> V_29 ;
V_168 -> V_175 = V_176 ;
}
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_503 ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_42 = 32 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_168 -> V_29 ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
F_39 ( V_189 , & V_168 -> V_43 ) ;
F_34 ( V_261 , & V_168 -> V_43 ) ;
V_168 -> V_181 = 2 ;
V_168 -> V_179 = 2 * V_180 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_40 ( V_168 ) ;
if ( ! V_34 )
F_34 ( V_410 , & V_31 -> V_43 ) ;
if ( V_497 )
F_65 ( & V_499 ) ;
else
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int F_172 ( struct V_30 * V_31 ,
void T_9 * V_504 )
{
struct V_167 * V_168 ;
int V_34 ;
struct V_26 * V_45 ;
int V_497 ;
struct V_505 V_506 ;
if ( ! F_168 ( V_498 ) )
return - V_41 ;
if ( F_173 ( & V_506 , V_504 , sizeof( V_506 ) ) )
return - V_507 ;
V_497 = 0 ;
V_168 = F_43 ( V_176 , 1 ,
sizeof( struct V_508 ) , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_169 ( & V_499 ) ;
V_497 = 1 ;
V_168 = & V_500 -> V_168 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
memset ( & V_500 -> V_45 , 0 ,
sizeof( V_500 -> V_45 ) ) ;
V_168 -> V_171 = & V_500 -> V_45 ;
V_168 -> V_29 = & V_500 -> V_29 ;
V_168 -> V_175 = V_176 ;
}
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_509 ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_42 = 12 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_168 -> V_29 ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
F_39 ( V_189 , & V_168 -> V_43 ) ;
F_34 ( V_261 , & V_168 -> V_43 ) ;
F_34 ( V_190 , & V_168 -> V_43 ) ;
V_168 -> V_181 = 5 ;
V_168 -> V_179 = 10 * V_180 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_168 -> V_170 = V_506 . V_510 ;
V_34 = F_40 ( V_168 ) ;
if ( ! V_34 && V_506 . V_510 && ( V_168 -> V_170 != V_506 . V_510 ) )
V_34 = - V_280 ;
if ( ! V_34 ) {
V_506 . V_29 = * ( (struct V_508 * ) V_168 -> V_29 ) ;
if ( F_174 ( V_504 , & V_506 , sizeof( V_506 ) ) )
V_34 = - V_507 ;
}
if ( V_497 )
F_65 ( & V_499 ) ;
else
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int
F_175 ( struct V_30 * V_31 , void T_9 * V_504 )
{
struct V_242 * V_243 ;
struct V_511 * V_512 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
int V_34 ;
V_168 = F_43 ( V_176 , 1 + 1 ,
( sizeof( struct V_242 ) +
sizeof( struct V_511 ) ) ,
V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_18 ( V_7 , V_31 , L_1 ,
L_81 ) ;
return F_72 ( V_168 ) ;
}
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_181 = 0 ;
F_39 ( V_189 , & V_168 -> V_43 ) ;
V_168 -> V_179 = 10 * V_180 ;
V_243 = (struct V_242 * ) V_168 -> V_29 ;
memset ( V_243 , 0 , sizeof( struct V_242 ) ) ;
V_243 -> V_246 = V_247 ;
V_243 -> V_248 = 0x01 ;
V_243 -> V_513 [ 1 ] = 0x01 ;
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_249 ;
V_45 -> V_42 = sizeof( struct V_242 ) ;
V_45 -> V_43 |= V_250 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_243 ;
V_512 = (struct V_511 * ) ( V_243 + 1 ) ;
memset ( V_512 , 0 , sizeof( struct V_511 ) ) ;
V_45 ++ ;
V_45 -> V_54 = V_251 ;
V_45 -> V_42 = sizeof( struct V_511 ) ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_512 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_45 ( V_168 ) ;
if ( V_34 == 0 ) {
V_243 = (struct V_242 * ) V_168 -> V_29 ;
V_512 = (struct V_511 * ) ( V_243 + 1 ) ;
if ( F_174 ( V_504 , V_512 ,
sizeof( struct V_511 ) ) )
V_34 = - V_507 ;
}
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int
F_176 ( struct V_30 * V_31 , void T_9 * V_504 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_514 V_69 = V_33 -> V_69 ;
int V_34 ;
if ( ! F_168 ( V_498 ) )
return - V_41 ;
if ( ! V_504 )
return - V_128 ;
V_34 = 0 ;
if ( F_174 ( V_504 , ( long * ) & V_69 ,
sizeof( struct V_514 ) ) )
V_34 = - V_507 ;
return V_34 ;
}
static int
F_177 ( struct V_30 * V_31 , void T_9 * V_504 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_514 V_69 ;
if ( ! F_168 ( V_498 ) )
return - V_41 ;
if ( ! V_504 )
return - V_128 ;
if ( F_173 ( & V_69 , V_504 , sizeof( struct V_514 ) ) )
return - V_507 ;
V_33 -> V_69 = V_69 ;
F_83 ( & V_31 -> V_2 -> V_82 ,
L_82 ,
V_33 -> V_69 . V_68 , V_33 -> V_69 . V_89 ) ;
return 0 ;
}
static int F_178 ( struct V_30 * V_31 , void T_9 * V_504 )
{
struct V_515 V_506 ;
char * V_516 , * V_517 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
char V_518 , V_519 ;
int V_34 ;
if ( ! F_168 ( V_498 ) && ! F_168 ( V_520 ) )
return - V_41 ;
V_518 = V_519 = 0 ;
V_34 = - V_507 ;
if ( F_173 ( & V_506 , V_504 , sizeof( V_506 ) ) )
goto V_372;
if ( F_179 () ) {
V_34 = - V_128 ;
if ( ( V_506 . V_516 >> 32 ) != 0 )
goto V_372;
if ( ( V_506 . V_517 >> 32 ) != 0 )
goto V_372;
V_506 . V_516 &= 0x7fffffffULL ;
V_506 . V_517 &= 0x7fffffffULL ;
}
V_516 = F_42 ( V_506 . V_521 , V_195 | V_196 ) ;
V_517 = F_42 ( V_506 . V_522 , V_195 | V_196 ) ;
if ( ! V_516 || ! V_517 ) {
V_34 = - V_197 ;
goto V_523;
}
V_34 = - V_507 ;
if ( F_173 ( V_516 ,
( void T_9 * ) ( unsigned long ) V_506 . V_516 ,
V_506 . V_521 ) )
goto V_523;
V_518 = V_516 [ 0 ] ;
V_519 = V_516 [ 1 ] ;
V_168 = F_43 ( V_176 , 2 , 0 , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_18 ( V_7 , V_31 , L_1 ,
L_81 ) ;
V_34 = F_72 ( V_168 ) ;
goto V_523;
}
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_181 = 3 ;
V_168 -> V_179 = 10 * V_180 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_249 ;
V_45 -> V_42 = V_506 . V_521 ;
V_45 -> V_43 |= V_250 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_516 ;
V_45 ++ ;
V_45 -> V_54 = V_251 ;
V_45 -> V_42 = V_506 . V_522 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_517 ;
V_34 = F_45 ( V_168 ) ;
if ( V_34 )
goto V_524;
V_34 = - V_507 ;
if ( F_174 ( ( void T_9 * ) ( unsigned long ) V_506 . V_517 ,
V_517 , V_506 . V_522 ) )
goto V_524;
V_34 = 0 ;
V_524:
F_46 ( V_168 , V_168 -> V_177 ) ;
V_523:
F_47 ( V_517 ) ;
F_47 ( V_516 ) ;
V_372:
F_18 ( V_7 , V_31 ,
L_83 ,
( int ) V_518 , ( int ) V_519 , V_34 ) ;
return V_34 ;
}
static int
F_180 ( struct V_274 * V_178 , unsigned int V_48 , void T_9 * V_504 )
{
struct V_30 * V_31 = V_178 -> V_291 ;
switch ( V_48 ) {
case V_525 :
return F_176 ( V_31 , V_504 ) ;
case V_526 :
return F_177 ( V_31 , V_504 ) ;
case V_527 :
return F_175 ( V_31 , V_504 ) ;
case V_528 :
return F_167 ( V_31 ) ;
case V_529 :
return F_170 ( V_31 ) ;
case V_530 :
return F_171 ( V_31 ) ;
case V_531 :
return F_172 ( V_31 , V_504 ) ;
case V_532 :
return F_178 ( V_31 , V_504 ) ;
default:
return - V_533 ;
}
}
static int
F_181 ( struct V_26 * V_534 , struct V_26 * V_535 , char * V_536 )
{
int V_537 , V_42 ;
char * V_538 ;
V_537 = 0 ;
while ( V_534 <= V_535 ) {
V_537 += sprintf ( V_536 + V_537 , V_539
L_84 ,
V_534 , ( ( int * ) V_534 ) [ 0 ] , ( ( int * ) V_534 ) [ 1 ] ) ;
if ( V_534 -> V_43 & V_440 )
V_538 = ( char * ) * ( ( V_173 * ) ( V_173 ) V_534 -> V_56 ) ;
else
V_538 = ( char * ) ( ( V_173 ) V_534 -> V_56 ) ;
for ( V_42 = 0 ; V_42 < V_534 -> V_42 && V_42 < 32 ; V_42 ++ ) {
if ( V_42 % 8 == 0 ) V_537 += sprintf ( V_536 + V_537 , L_85 ) ;
if ( V_42 % 4 == 0 ) V_537 += sprintf ( V_536 + V_537 , L_85 ) ;
V_537 += sprintf ( V_536 + V_537 , L_11 , V_538 [ V_42 ] ) ;
}
V_537 += sprintf ( V_536 + V_537 , L_86 ) ;
V_534 ++ ;
}
return V_537 ;
}
static void
F_182 ( struct V_30 * V_31 , struct V_315 * V_315 ,
char * V_540 )
{
T_10 * V_311 ;
T_10 * V_541 ;
V_311 = ( T_10 * ) F_93 ( V_315 ) ;
V_541 = ( T_10 * ) & V_315 -> V_395 ;
if ( V_311 ) {
F_18 ( V_542 , V_31 , L_87
L_88 ,
V_540 , * V_541 , * ( ( T_3 * ) ( V_541 + 1 ) ) ,
V_311 [ 0 ] , V_311 [ 1 ] , V_311 [ 2 ] , V_311 [ 3 ] ) ;
} else {
F_18 ( V_542 , V_31 , L_89 ,
V_540 , * V_541 , * ( ( T_3 * ) ( V_541 + 1 ) ) ,
L_90 ) ;
}
}
static void F_183 ( struct V_30 * V_31 ,
struct V_167 * V_414 , struct V_315 * V_315 )
{
char * V_536 ;
struct V_26 * V_543 , * V_544 , * V_545 , * V_534 , * V_535 ;
int V_537 , V_546 , V_547 ;
V_536 = ( char * ) F_184 ( V_240 ) ;
if ( V_536 == NULL ) {
F_18 ( V_7 , V_31 , L_1 ,
L_91 ) ;
return;
}
V_537 = sprintf ( V_536 , V_539
L_92 ,
F_185 ( & V_31 -> V_2 -> V_82 ) ) ;
V_537 += sprintf ( V_536 + V_537 , V_539
L_93
L_94 ,
V_414 , F_186 ( & V_315 -> V_395 ) , F_187 ( & V_315 -> V_395 ) ,
F_188 ( & V_315 -> V_395 ) , F_189 ( & V_315 -> V_395 ) ,
F_138 ( & V_315 -> V_395 ) , F_132 ( & V_315 -> V_395 ) ,
V_414 ? V_414 -> V_257 : 0 ) ;
V_537 += sprintf ( V_536 + V_537 , V_539
L_95 ,
F_185 ( & V_31 -> V_2 -> V_82 ) ,
( void * ) ( V_173 ) V_315 -> V_395 . V_48 . V_548 ) ;
if ( V_315 -> V_549 . V_550 . V_551 . V_552 ) {
for ( V_546 = 0 ; V_546 < 4 ; V_546 ++ ) {
V_537 += sprintf ( V_536 + V_537 , V_539
L_96 ,
( 8 * V_546 ) , ( ( 8 * V_546 ) + 7 ) ) ;
for ( V_547 = 0 ; V_547 < 8 ; V_547 ++ ) {
V_537 += sprintf ( V_536 + V_537 , L_97 ,
V_315 -> V_553 [ 8 * V_546 + V_547 ] ) ;
}
V_537 += sprintf ( V_536 + V_537 , L_86 ) ;
}
if ( V_315 -> V_553 [ 27 ] & V_404 ) {
sprintf ( V_536 + V_537 , V_539
L_98
L_99 ,
V_315 -> V_553 [ 7 ] >> 4 , V_315 -> V_553 [ 7 ] & 0x0f ,
V_315 -> V_553 [ 1 ] & 0x10 ? L_59 : L_100 ) ;
} else {
sprintf ( V_536 + V_537 , V_539
L_101
L_102 ,
V_315 -> V_553 [ 6 ] & 0x0f , V_315 -> V_553 [ 22 ] >> 4 ) ;
}
} else {
sprintf ( V_536 + V_537 , V_539
L_103 ) ;
}
F_190 ( V_554 L_1 , V_536 ) ;
if ( V_414 ) {
V_543 = V_414 -> V_171 ;
for ( V_544 = V_543 ; V_544 -> V_43 & ( V_250 | V_555 ) ; V_544 ++ ) ;
V_535 = F_152 ( V_543 + 6 , V_544 ) ;
V_537 = sprintf ( V_536 , V_539
L_104 , V_414 ) ;
F_181 ( V_543 , V_535 , V_536 + V_537 ) ;
F_190 ( V_554 L_1 , V_536 ) ;
V_537 = 0 ;
V_534 = ++ V_535 ;
V_545 = (struct V_26 * ) ( V_173 )
V_315 -> V_395 . V_48 . V_548 ;
if ( V_534 < V_545 - 2 ) {
V_534 = V_545 - 2 ;
V_537 += sprintf ( V_536 , V_539 L_105 ) ;
}
V_535 = F_152 ( V_545 + 1 , V_544 ) ;
V_537 += F_181 ( V_534 , V_535 , V_536 + V_537 ) ;
V_534 = V_376 ( V_534 , ++ V_535 ) ;
if ( V_534 < V_544 - 1 ) {
V_534 = V_544 - 1 ;
V_537 += sprintf ( V_536 + V_537 , V_539 L_105 ) ;
}
V_537 += F_181 ( V_534 , V_544 , V_536 + V_537 ) ;
if ( V_537 > 0 )
F_190 ( V_554 L_1 , V_536 ) ;
}
F_191 ( ( unsigned long ) V_536 ) ;
}
static void F_192 ( struct V_30 * V_31 ,
struct V_167 * V_414 , struct V_315 * V_315 )
{
char * V_536 ;
int V_537 , V_546 , V_547 , V_556 ;
struct V_557 * V_557 ;
T_7 * V_311 , * V_558 ;
V_536 = ( char * ) F_184 ( V_240 ) ;
if ( V_536 == NULL ) {
F_18 ( V_7 , V_31 , L_106 ,
L_107 ) ;
return;
}
V_537 = sprintf ( V_536 , V_539
L_92 ,
F_185 ( & V_31 -> V_2 -> V_82 ) ) ;
V_537 += sprintf ( V_536 + V_537 , V_539
L_93
L_108 ,
V_414 , F_186 ( & V_315 -> V_395 ) , F_187 ( & V_315 -> V_395 ) ,
F_188 ( & V_315 -> V_395 ) , F_189 ( & V_315 -> V_395 ) ,
F_138 ( & V_315 -> V_395 ) , F_132 ( & V_315 -> V_395 ) ,
V_315 -> V_395 . V_559 . V_560 , V_315 -> V_395 . V_559 . V_561 ,
V_414 ? V_414 -> V_257 : 0 ) ;
V_537 += sprintf ( V_536 + V_537 , V_539
L_109 ,
F_185 ( & V_31 -> V_2 -> V_82 ) ,
( void * ) ( V_173 ) V_315 -> V_395 . V_559 . V_481 ) ;
V_557 = NULL ;
V_311 = NULL ;
if ( V_315 -> V_395 . V_559 . V_481 && ( V_315 -> V_395 . V_559 . V_560 & 0x01 ) )
V_557 = F_193 (
(struct V_481 * ) ( unsigned long ) V_315 -> V_395 . V_559 . V_481 ) ;
if ( V_557 ) {
V_537 += sprintf ( V_536 + V_537 , V_539
L_110 , V_557 -> V_106 ) ;
V_537 += sprintf ( V_536 + V_537 , V_539
L_111 , V_557 -> V_43 ) ;
V_537 += sprintf ( V_536 + V_537 , V_539
L_112 , V_557 -> V_562 ) ;
V_537 += sprintf ( V_536 + V_537 , V_539
L_113 , V_557 -> V_42 ) ;
V_556 = V_557 -> V_42 - 28 ;
V_537 += sprintf ( V_536 + V_537 , V_539
L_114 , V_556 ) ;
switch ( V_557 -> V_43 & 0x07 ) {
case 1 :
V_537 += sprintf ( V_536 + V_537 , V_539
L_115 ,
V_557 -> V_563 . V_564 . V_565 ) ;
V_537 += sprintf ( V_536 + V_537 , V_539
L_116 ,
V_557 -> V_563 . V_564 . V_566 ) ;
V_537 += sprintf ( V_536 + V_537 , V_539
L_117 ,
V_557 -> V_563 . V_564 . V_567 ) ;
V_537 += sprintf ( V_536 + V_537 , V_539
L_118 ,
V_557 -> V_563 . V_564 . V_568 ) ;
V_537 += sprintf ( V_536 + V_537 , V_539
L_119 ,
V_557 -> V_563 . V_564 . V_569 ) ;
V_311 = V_557 -> V_563 . V_564 . V_311 ;
break;
case 2 :
V_537 += sprintf ( V_536 + V_537 , V_539
L_120 , V_557 -> V_563 . V_570 . V_34 ) ;
for ( V_546 = 0 ; V_546 < 2 ; V_546 ++ ) {
V_537 += sprintf ( V_536 + V_537 , V_539
L_121 ,
( 8 * V_546 ) , ( ( 8 * V_546 ) + 7 ) ) ;
V_558 = V_557 -> V_563 . V_570 . V_558 ;
for ( V_547 = 0 ; V_547 < 8 ; V_547 ++ ) {
V_537 += sprintf ( V_536 + V_537 , L_97 ,
V_558 [ 8 * V_546 + V_547 ] ) ;
}
V_537 += sprintf ( V_536 + V_537 , L_86 ) ;
}
V_311 = V_557 -> V_563 . V_570 . V_311 ;
break;
case 3 :
V_537 += sprintf ( V_536 + V_537 , V_539
L_122 ) ;
break;
}
if ( V_311 ) {
for ( V_546 = 0 ; V_546 < 4 ; V_546 ++ ) {
V_537 += sprintf ( V_536 + V_537 , V_539
L_96 ,
( 8 * V_546 ) , ( ( 8 * V_546 ) + 7 ) ) ;
for ( V_547 = 0 ; V_547 < 8 ; V_547 ++ ) {
V_537 += sprintf ( V_536 + V_537 , L_97 ,
V_311 [ 8 * V_546 + V_547 ] ) ;
}
V_537 += sprintf ( V_536 + V_537 , L_86 ) ;
}
if ( V_311 [ 27 ] & V_404 ) {
sprintf ( V_536 + V_537 , V_539
L_98
L_99 ,
V_311 [ 7 ] >> 4 , V_311 [ 7 ] & 0x0f ,
V_311 [ 1 ] & 0x10 ? L_59 : L_100 ) ;
} else {
sprintf ( V_536 + V_537 , V_539
L_101
L_102 ,
V_311 [ 6 ] & 0x0f , V_311 [ 22 ] >> 4 ) ;
}
} else {
sprintf ( V_536 + V_537 , V_539
L_103 ) ;
}
} else {
sprintf ( V_536 + V_537 , V_539
L_123 ) ;
}
F_190 ( V_554 L_1 , V_536 ) ;
F_191 ( ( unsigned long ) V_536 ) ;
}
static void F_194 ( struct V_30 * V_31 ,
struct V_167 * V_414 , struct V_315 * V_315 )
{
T_7 * V_311 = F_93 ( V_315 ) ;
if ( F_195 ( & V_315 -> V_395 ) ) {
if ( V_311 && ( V_311 [ 1 ] & V_374 ) &&
F_61 ( V_350 , & V_414 -> V_43 ) )
return;
if ( F_132 ( & V_315 -> V_395 ) == 0x40 &&
F_61 ( V_351 , & V_414 -> V_43 ) )
return;
F_192 ( V_31 , V_414 , V_315 ) ;
} else {
if ( V_311 && V_311 [ 1 ] & V_316 &&
F_61 ( V_354 , & V_414 -> V_43 ) )
return;
F_183 ( V_31 , V_414 , V_315 ) ;
}
}
static int F_196 ( struct V_30 * V_31 )
{
F_106 ( V_31 ) ;
F_88 ( V_31 ) ;
return 0 ;
}
static int F_197 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_14 V_571 ;
int V_34 ;
struct V_149 V_275 ;
unsigned long V_43 ;
unsigned long V_572 = 0 ;
V_34 = F_51 ( V_31 ) ;
if ( V_34 ) {
F_3 ( V_7 , V_31 -> V_2 ,
L_124 , V_34 ) ;
goto V_346;
}
F_30 ( V_31 , & V_275 ) ;
V_34 = F_26 ( V_31 ) ;
F_27 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
if ( memcmp ( & V_33 -> V_134 , & V_275 , sizeof( struct V_149 ) ) != 0 )
F_15 ( & V_31 -> V_2 -> V_82 , L_125
L_126 ) ;
F_29 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
if ( V_34 )
goto V_346;
V_34 = F_85 ( V_31 ) ;
if ( V_34 )
goto V_346;
F_34 ( V_261 , & V_572 ) ;
F_76 ( V_31 , V_572 ) ;
V_34 = F_51 ( V_31 ) ;
if ( V_34 ) {
F_3 ( V_7 , V_31 -> V_2 ,
L_124 , V_34 ) ;
goto V_292;
}
F_71 ( V_31 ) ;
V_34 = F_86 ( V_31 , V_176 ,
& V_571 , 64 ) ;
if ( V_34 ) {
F_3 ( V_7 , V_31 -> V_2 ,
L_53 , V_34 ) ;
goto V_292;
}
F_27 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
memcpy ( & V_33 -> V_35 , & V_571 , sizeof( V_571 ) ) ;
F_29 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
F_102 ( V_31 ) ;
return 0 ;
V_292:
F_88 ( V_31 ) ;
V_346:
return - 1 ;
}
static int F_198 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
int V_34 , V_573 ;
char V_232 [ 60 ] ;
struct V_149 V_134 ;
unsigned long V_43 ;
F_106 ( V_31 ) ;
F_27 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
V_573 = V_33 -> V_134 . V_161 ;
F_29 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
V_34 = F_51 ( V_31 ) ;
if ( V_34 )
goto V_346;
V_34 = F_26 ( V_31 ) ;
if ( V_34 )
goto V_346;
F_199 ( V_31 ) ;
F_30 ( V_31 , & V_134 ) ;
if ( V_573 != V_134 . V_161 ) {
if ( strlen ( V_134 . V_163 ) > 0 )
snprintf ( V_232 , sizeof( V_232 ) ,
L_17 , V_134 . V_150 , V_134 . V_152 ,
V_134 . V_154 , V_134 . V_161 , V_134 . V_163 ) ;
else
snprintf ( V_232 , sizeof( V_232 ) ,
L_18 , V_134 . V_150 , V_134 . V_152 ,
V_134 . V_154 , V_134 . V_161 ) ;
F_83 ( & V_31 -> V_2 -> V_82 ,
L_127
L_128 , V_232 ) ;
}
return 0 ;
V_346:
return - 1 ;
}
static int F_200 ( struct V_30 * V_31 ,
struct V_574 * V_575 ,
T_2 V_576 )
{
struct V_574 * V_577 ;
struct V_242 * V_243 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
int V_34 ;
V_168 = F_43 ( V_176 , 1 + 1 ,
( sizeof( struct V_242 ) +
sizeof( struct V_574 ) ) ,
V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_129 ) ;
return F_72 ( V_168 ) ;
}
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_178 = NULL ;
V_168 -> V_179 = 10 * V_180 ;
F_34 ( V_185 , & V_168 -> V_43 ) ;
F_39 ( V_189 , & V_168 -> V_43 ) ;
V_168 -> V_181 = 256 ;
V_243 = (struct V_242 * ) V_168 -> V_29 ;
memset ( V_243 , 0 , sizeof( struct V_242 ) ) ;
V_243 -> V_246 = V_247 ;
V_243 -> V_248 = 0x03 ;
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_249 ;
V_45 -> V_42 = sizeof( struct V_242 ) ;
V_45 -> V_43 |= V_250 ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_243 ;
V_577 = (struct V_574 * ) ( V_243 + 1 ) ;
memset ( V_577 , 0 , sizeof( struct V_574 ) ) ;
V_45 ++ ;
V_45 -> V_54 = V_251 ;
V_45 -> V_42 = sizeof( struct V_574 ) ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_577 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_40 ( V_168 ) ;
if ( V_34 == 0 ) {
V_243 = (struct V_242 * ) V_168 -> V_29 ;
V_577 = (struct V_574 * )
( V_243 + 1 ) ;
memcpy ( V_575 , V_577 ,
sizeof( struct V_574 ) ) ;
} else
F_3 ( V_7 , V_31 -> V_2 ,
L_130
, V_34 ) ;
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int F_201 ( struct V_30 * V_31 ,
struct V_578 * V_29 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_578 * V_579 ;
struct V_242 * V_243 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
int V_34 ;
if ( ! V_31 -> V_178 && V_33 -> V_403 -> V_580 == V_581 )
return - V_40 ;
V_168 = F_43 ( V_176 , 1 + 1 ,
sizeof( struct V_242 ) + 1 ,
V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_129 ) ;
return F_72 ( V_168 ) ;
}
V_579 = F_42 ( sizeof( * V_579 ) , V_195 | V_196 ) ;
if ( ! V_579 ) {
F_46 ( V_168 , V_31 ) ;
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_131 ) ;
return - V_197 ;
}
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_178 = NULL ;
V_168 -> V_181 = 256 ;
V_168 -> V_179 = 10 * V_180 ;
V_243 = (struct V_242 * ) V_168 -> V_29 ;
memset ( V_243 , 0 , sizeof( struct V_242 ) ) ;
V_243 -> V_246 = V_247 ;
V_243 -> V_248 = V_582 ;
V_243 -> V_583 = V_33 -> V_130 -> V_133 ;
V_243 -> V_584 = V_33 -> V_130 -> V_131 ;
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_249 ;
V_45 -> V_42 = sizeof( struct V_242 ) ;
V_45 -> V_43 |= V_250 ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_243 ;
V_45 ++ ;
V_45 -> V_54 = V_251 ;
V_45 -> V_42 = sizeof( struct V_578 ) ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_579 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_45 ( V_168 ) ;
if ( V_34 == 0 ) {
* V_29 = * V_579 ;
} else {
F_3 ( V_7 , V_31 -> V_2 ,
L_132 ,
V_34 ) ;
V_34 = - V_40 ;
}
F_46 ( V_168 , V_168 -> V_177 ) ;
F_47 ( V_579 ) ;
return V_34 ;
}
static int F_202 ( struct V_30 * V_31 )
{
struct V_578 * V_585 ;
struct V_586 * V_587 ;
struct V_588 * V_488 ;
int V_42 = 0 ;
int V_34 , V_199 ;
V_585 = F_42 ( sizeof( * V_585 ) , V_589 ) ;
if ( ! V_585 ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_133 ) ;
return - V_197 ;
}
V_34 = F_201 ( V_31 , V_585 ) ;
if ( V_34 ) {
F_47 ( V_585 ) ;
return V_34 ;
}
V_488 = (struct V_588 * )
V_585 -> V_590 ;
for ( V_199 = 0 ; V_199 < V_488 -> V_591 ; V_199 ++ ) {
V_587 = (struct V_586 * )
( V_488 -> V_587 + V_199 * V_488 -> V_592 ) ;
if ( V_587 -> V_593 & V_594 )
V_42 ++ ;
}
F_47 ( V_585 ) ;
return V_42 ;
}
static int F_203 ( struct V_30 * V_31 , struct V_595 * V_596 )
{
struct V_578 * V_585 ;
struct V_586 * V_587 ;
struct V_588 * V_488 ;
char V_597 [ 9 ] = L_59 ;
int V_34 , V_199 , V_358 ;
V_585 = F_42 ( sizeof( * V_585 ) , V_589 ) ;
if ( ! V_585 ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_133 ) ;
return - V_197 ;
}
V_34 = F_201 ( V_31 , V_585 ) ;
if ( V_34 ) {
F_47 ( V_585 ) ;
return V_34 ;
}
V_488 = (struct V_588 * )
V_585 -> V_590 ;
for ( V_199 = 0 ; V_199 < V_488 -> V_591 ; V_199 ++ ) {
V_587 = (struct V_586 * )
( V_488 -> V_587 + V_199 * V_488 -> V_592 ) ;
F_204 ( V_596 , L_134 ) ;
for ( V_358 = 0 ; V_358 < 11 ; V_358 ++ )
F_205 ( V_596 , L_11 , V_587 -> V_598 [ V_358 ] ) ;
F_206 ( V_596 , '\n' ) ;
F_205 ( V_596 , L_135 , V_587 -> V_593 ) ;
memcpy ( & V_597 , & V_587 -> V_599 , sizeof( V_597 ) - 1 ) ;
F_25 ( V_597 , sizeof( V_597 ) ) ;
F_205 ( V_596 , L_136 , V_597 ) ;
F_205 ( V_596 , L_137 , V_587 -> V_600 ) ;
F_205 ( V_596 , L_138 , ( unsigned long )
V_587 -> V_601 ) ;
}
F_47 ( V_585 ) ;
return 0 ;
}
static int
F_207 ( struct V_30 * V_31 , int V_602 ,
T_1 V_603 ,
struct V_604 * V_605 ,
struct V_606 V_607 )
{
struct V_608 * V_609 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
int V_34 ;
V_168 = F_43 ( V_176 , 1 ,
sizeof( struct V_608 ) ,
V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_18 ( V_7 , V_31 , L_1 ,
L_139 ) ;
return F_72 ( V_168 ) ;
}
V_609 = (struct V_608 * ) V_168 -> V_29 ;
V_609 -> V_246 = V_610 ;
V_609 -> V_611 = V_602 ;
if ( V_605 )
V_609 -> V_612 = V_605 -> V_612 ;
V_609 -> V_603 = V_603 ;
V_609 -> V_613 = V_607 . V_613 ;
V_609 -> V_154 = V_607 . V_154 ;
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_249 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_609 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_42 = sizeof( struct V_608 ) ;
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
static struct V_218 * F_208 ( struct V_30 * V_31 ,
T_2 V_576 ,
struct V_614 * V_615 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_218 * V_201 ;
int V_616 , V_211 ;
if ( V_615 -> V_617 == 0 )
goto V_372;
for ( V_616 = 0x80 , V_211 = 0 ; V_616 ; V_616 >>= 1 , V_211 ++ ) {
V_201 = V_33 -> V_208 [ V_211 ] ;
if ( V_201 -> V_155 . V_617 ==
V_615 -> V_617 )
return V_201 ;
}
V_372:
return V_33 -> V_208 [ F_53 ( V_576 ) ] ;
}
static int F_209 ( struct V_30 * V_31 , T_2 V_576 ,
struct V_614 * V_615 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_218 * V_618 ;
unsigned long V_619 = 0 , V_65 = 0 ;
struct V_218 * V_201 ;
unsigned int V_211 , V_616 ;
char * V_620 , * V_155 ;
char * V_621 , * V_130 ;
int V_622 = 0 ;
if ( ! V_615 -> V_623 ||
! ( V_615 -> V_624 [ 0 ] | V_615 -> V_624 [ 1 ] | V_615 -> V_624 [ 2 ] ) )
return V_576 ;
V_618 = F_208 ( V_31 , V_576 , V_615 ) ;
V_211 = 8 - F_210 ( V_615 -> V_623 ) ;
V_621 = ( char * ) & V_618 -> V_625 [ V_211 ] ;
V_620 = ( char * ) & V_618 -> V_155 ;
V_65 = V_615 -> V_624 [ 2 ] ;
V_65 |= V_615 -> V_624 [ 1 ] << 8 ;
V_65 |= V_615 -> V_624 [ 0 ] << 16 ;
for ( V_616 = 0x80 ; V_616 ; V_616 >>= 1 ) {
V_619 = V_65 ;
V_211 = F_53 ( V_616 ) ;
V_201 = V_33 -> V_208 [ V_211 ] ;
V_211 = 8 - F_210 ( V_615 -> V_623 ) ;
V_130 = ( char * ) & V_201 -> V_625 [ V_211 ] ;
if ( memcmp ( V_621 , V_130 , sizeof( * V_130 ) ) != 0 )
continue;
V_155 = ( char * ) & V_201 -> V_155 ;
while ( V_619 ) {
V_211 = F_210 ( V_619 ) - 1 ;
if ( memcmp ( & V_620 [ 31 - V_211 ] , & V_155 [ 31 - V_211 ] , 1 )
!= 0 )
break;
F_39 ( V_211 , & V_619 ) ;
}
if ( V_619 )
continue;
V_622 |= V_616 ;
}
return V_622 ;
}
static void F_211 ( struct V_30 * V_31 ,
unsigned long V_626 ,
struct V_606 V_607 , int V_627 )
{
struct V_604 * V_605 ;
int V_211 ;
while ( V_626 ) {
V_211 = F_210 ( V_626 ) - 1 ;
V_605 = F_212 ( V_31 -> V_2 , 7 - V_211 ) ;
if ( V_627 == V_628 )
F_213 ( L_140
L_141 , V_607 . V_613 ,
V_605 ? V_605 -> V_612 : 0 ) ;
else if ( V_627 == V_629 )
F_214 ( L_142
L_143 , V_607 . V_613 ,
V_605 ? V_605 -> V_612 : 0 ) ;
F_47 ( V_605 ) ;
F_39 ( V_211 , & V_626 ) ;
}
}
static int F_215 ( struct V_30 * V_31 , T_2 V_576 ,
struct V_614 * V_615 )
{
unsigned long V_622 ;
V_622 = F_209 ( V_31 , V_576 , V_615 ) ;
if ( ! ( V_31 -> V_215 . V_212 & V_622 ) )
return 0 ;
if ( ! ( V_31 -> V_215 . V_212 & ~ V_622 ) ) {
return - V_128 ;
}
V_31 -> V_215 . V_212 &= ~ V_622 ;
V_31 -> V_215 . V_223 |= V_622 ;
return V_622 ;
}
static int F_216 ( struct V_30 * V_31 , T_2 V_576 ,
struct V_606 V_607 ,
struct V_614 * V_615 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_630 * V_631 , * V_632 ;
struct V_30 * V_82 , * V_363 ;
unsigned long V_626 = 0 ;
unsigned long V_43 ;
int V_622 ;
F_126 (dev, n, &private->lcu->active_devices,
alias_list) {
F_27 ( F_28 ( V_82 -> V_2 ) , V_43 ) ;
V_622 = F_215 ( V_82 , V_576 , V_615 ) ;
F_29 ( F_28 ( V_82 -> V_2 ) , V_43 ) ;
if ( V_622 < 0 )
goto V_346;
V_626 |= V_622 ;
}
F_126 (dev, n, &private->lcu->inactive_devices,
alias_list) {
F_27 ( F_28 ( V_82 -> V_2 ) , V_43 ) ;
V_622 = F_215 ( V_82 , V_576 , V_615 ) ;
F_29 ( F_28 ( V_82 -> V_2 ) , V_43 ) ;
if ( V_622 < 0 )
goto V_346;
V_626 |= V_622 ;
}
F_126 (pavgroup, tempgroup,
&private->lcu->grouplist, group) {
F_126 (dev, n, &pavgroup->baselist,
alias_list) {
F_27 ( F_28 ( V_82 -> V_2 ) , V_43 ) ;
V_622 = F_215 ( V_82 , V_576 , V_615 ) ;
F_29 (
F_28 ( V_82 -> V_2 ) , V_43 ) ;
if ( V_622 < 0 )
goto V_346;
V_626 |= V_622 ;
}
F_126 (dev, n, &pavgroup->aliaslist,
alias_list) {
F_27 ( F_28 ( V_82 -> V_2 ) , V_43 ) ;
V_622 = F_215 ( V_82 , V_576 , V_615 ) ;
F_29 (
F_28 ( V_82 -> V_2 ) , V_43 ) ;
if ( V_622 < 0 )
goto V_346;
V_626 |= V_622 ;
}
}
F_211 ( V_31 , V_626 , V_607 , V_628 ) ;
return 0 ;
V_346:
return V_622 ;
}
static int F_217 ( struct V_30 * V_31 , T_2 V_576 ,
struct V_606 V_607 ,
struct V_614 * V_615 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_630 * V_631 , * V_632 ;
struct V_30 * V_82 , * V_363 ;
unsigned long V_626 = 0 ;
int V_622 ;
F_126 (dev, n,
&private->lcu->active_devices,
alias_list) {
V_622 = F_209 ( V_82 , V_576 , V_615 ) ;
V_626 |= V_622 ;
if ( ! ( V_82 -> V_215 . V_212 & V_622 ) ) {
V_82 -> V_215 . V_236 |= V_622 ;
F_218 ( V_82 ) ;
}
}
F_126 (dev, n,
&private->lcu->inactive_devices,
alias_list) {
V_622 = F_209 ( V_82 , V_576 , V_615 ) ;
V_626 |= V_622 ;
if ( ! ( V_82 -> V_215 . V_212 & V_622 ) ) {
V_82 -> V_215 . V_236 |= V_622 ;
F_218 ( V_82 ) ;
}
}
F_126 (pavgroup, tempgroup,
&private->lcu->grouplist,
group) {
F_126 (dev, n,
&pavgroup->baselist,
alias_list) {
V_622 = F_209 ( V_82 , V_576 , V_615 ) ;
V_626 |= V_622 ;
if ( ! ( V_82 -> V_215 . V_212 & V_622 ) ) {
V_82 -> V_215 . V_236 |= V_622 ;
F_218 ( V_82 ) ;
}
}
F_126 (dev, n,
&pavgroup->aliaslist,
alias_list) {
V_622 = F_209 ( V_82 , V_576 , V_615 ) ;
V_626 |= V_622 ;
if ( ! ( V_82 -> V_215 . V_212 & V_622 ) ) {
V_82 -> V_215 . V_236 |= V_622 ;
F_218 ( V_82 ) ;
}
}
}
F_211 ( V_31 , V_626 , V_607 , V_629 ) ;
return 0 ;
}
static void F_219 ( struct V_30 * V_31 , void * V_575 ,
T_2 V_576 )
{
struct V_614 * V_615 = V_575 ;
struct V_604 * V_605 ;
struct V_606 V_607 ;
int V_211 , V_602 ;
F_18 ( V_7 , V_31 ,
L_144 ,
( ( T_10 * ) V_615 ) [ 0 ] , ( ( T_10 * ) V_615 ) [ 1 ] , ( ( T_10 * ) V_615 ) [ 2 ] ,
( ( T_3 * ) V_615 ) [ 3 ] ) ;
F_220 ( V_31 -> V_2 , & V_607 ) ;
V_211 = F_53 ( V_576 ) ;
V_605 = F_212 ( V_31 -> V_2 , V_211 ) ;
if ( V_615 -> V_633 == V_628 ) {
if ( F_216 ( V_31 , V_576 , V_607 , V_615 ) )
V_602 = V_634 ;
else
V_602 = V_635 ;
} else if ( V_615 -> V_633 == V_629 ) {
F_217 ( V_31 , V_576 , V_607 , V_615 ) ;
V_602 = V_635 ;
} else
V_602 = V_636 ;
F_207 ( V_31 , V_602 ,
V_615 -> V_603 , V_605 , V_607 ) ;
F_18 ( V_7 , V_31 ,
L_145 , V_602 ,
V_615 -> V_603 ) ;
F_47 ( V_605 ) ;
V_31 -> V_637 -> V_638 ( V_31 , V_576 ) ;
}
static void F_221 ( struct V_228 * V_229 )
{
struct V_639 * V_29 ;
struct V_574 * V_575 ;
struct V_30 * V_31 ;
int V_34 ;
V_29 = F_60 ( V_229 , struct V_639 , V_233 ) ;
V_31 = V_29 -> V_31 ;
V_575 = F_42 ( sizeof( * V_575 ) , V_195 ) ;
if ( ! V_575 ) {
F_18 ( V_7 , V_31 , L_1 ,
L_146 ) ;
goto V_372;
}
V_34 = F_200 ( V_31 , V_575 , V_29 -> V_576 ) ;
if ( V_34 )
goto V_372;
if ( V_575 -> V_106 == V_640 &&
V_575 -> V_120 == V_641 )
F_219 ( V_31 , V_575 , V_29 -> V_576 ) ;
V_372:
F_64 ( V_31 ) ;
F_47 ( V_575 ) ;
F_47 ( V_29 ) ;
}
static int F_222 ( struct V_30 * V_31 , T_2 V_576 )
{
struct V_639 * V_29 ;
V_29 = F_42 ( sizeof( * V_29 ) , V_240 ) ;
if ( ! V_29 )
return - V_197 ;
F_69 ( & V_29 -> V_233 , F_221 ) ;
F_70 ( V_31 ) ;
V_29 -> V_31 = V_31 ;
V_29 -> V_576 = V_576 ;
F_62 ( & V_29 -> V_233 ) ;
return 0 ;
}
static int T_11
F_223 ( void )
{
int V_3 ;
F_224 ( V_8 . V_642 , 4 ) ;
V_500 = F_67 ( sizeof( * V_500 ) ,
V_195 | V_196 ) ;
if ( ! V_500 )
return - V_197 ;
V_241 = F_67 ( sizeof( * V_241 ) ,
V_195 | V_196 ) ;
if ( ! V_241 ) {
F_47 ( V_500 ) ;
return - V_197 ;
}
V_478 = ( void * ) F_225 ( V_195 ) ;
if ( ! V_478 ) {
F_47 ( V_241 ) ;
F_47 ( V_500 ) ;
return - V_197 ;
}
V_3 = F_226 ( & V_643 ) ;
if ( ! V_3 )
F_227 () ;
else {
F_47 ( V_241 ) ;
F_47 ( V_500 ) ;
F_191 ( ( unsigned long ) V_478 ) ;
}
return V_3 ;
}
static void T_12
F_228 ( void )
{
F_229 ( & V_643 ) ;
F_47 ( V_241 ) ;
F_47 ( V_500 ) ;
F_191 ( ( unsigned long ) V_478 ) ;
}
