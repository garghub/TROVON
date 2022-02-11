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
case V_65 :
V_29 -> V_66 . V_67 = 0x1 ;
V_29 -> V_68 . V_69 = V_33 -> V_70 . V_69 ;
break;
case V_71 :
case V_72 :
case V_73 :
case V_74 :
V_29 -> V_66 . V_67 = 0x02 ;
V_29 -> V_68 . V_69 = V_33 -> V_70 . V_69 ;
V_34 = F_11 ( V_45 , V_29 , V_31 ) ;
break;
case V_75 :
case V_76 :
V_29 -> V_68 . V_69 = V_77 ;
V_34 = F_11 ( V_45 , V_29 , V_31 ) ;
break;
case V_78 :
case V_79 :
case V_80 :
V_29 -> V_66 . V_67 = 0x3 ;
V_29 -> V_66 . V_81 = 0x1 ;
V_29 -> V_68 . V_69 = V_77 ;
V_34 = F_11 ( V_45 , V_29 , V_31 ) ;
break;
default:
F_15 ( & V_31 -> V_2 -> V_82 ,
L_4 , V_48 ) ;
break;
}
V_29 -> V_68 . V_83 = 0x3 ;
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
if ( V_29 -> V_68 . V_69 == V_87 ||
V_29 -> V_68 . V_69 == V_88 ) {
if ( V_50 + V_33 -> V_70 . V_89 < V_33 -> V_90 )
V_50 += V_33 -> V_70 . V_89 ;
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
V_29 -> V_69 . V_103 = 0x3 ;
V_29 -> V_69 . V_69 = 0x03 ;
break;
case V_57 :
V_29 -> V_69 . V_103 = 0x3 ;
V_29 -> V_69 . V_69 = 0x16 ;
break;
case V_80 :
V_29 -> V_69 . V_103 = 0x1 ;
V_29 -> V_69 . V_69 = 0x03 ;
V_29 -> V_42 ++ ;
break;
case V_58 :
V_29 -> V_69 . V_103 = 0x3 ;
V_29 -> V_69 . V_69 = 0x16 ;
V_29 -> V_42 ++ ;
break;
case V_71 :
case V_72 :
case V_73 :
case V_74 :
V_29 -> V_104 . V_105 = 0x1 ;
V_29 -> V_106 = V_99 ;
V_29 -> V_69 . V_69 = 0x01 ;
break;
case V_75 :
case V_76 :
V_29 -> V_104 . V_105 = 0x1 ;
V_29 -> V_106 = V_99 ;
V_29 -> V_69 . V_69 = 0x03 ;
break;
case V_107 :
V_29 -> V_69 . V_103 = 0x0 ;
V_29 -> V_69 . V_69 = 0x3F ;
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
V_29 -> V_69 . V_69 = 0x3F ;
V_29 -> V_108 = 0x23 ;
break;
case V_59 :
case V_60 :
case V_63 :
case V_64 :
V_29 -> V_104 . V_105 = 0x1 ;
V_29 -> V_106 = V_99 ;
V_29 -> V_69 . V_69 = 0x06 ;
break;
case V_61 :
case V_62 :
V_29 -> V_104 . V_105 = 0x1 ;
V_29 -> V_106 = V_99 ;
V_29 -> V_69 . V_69 = 0x16 ;
break;
case V_65 :
V_29 -> V_69 . V_69 = 0x06 ;
break;
case V_112 :
V_29 -> V_69 . V_103 = 0x1 ;
V_29 -> V_69 . V_69 = 0x0C ;
V_29 -> V_109 = 0 ;
V_29 -> V_101 = 0xFF ;
break;
case V_113 :
V_29 -> V_104 . V_105 = 0x1 ;
V_29 -> V_106 = V_100 ;
V_29 -> V_69 . V_69 = 0x0C ;
break;
case V_78 :
V_29 -> V_106 = V_99 ;
V_29 -> V_104 . V_105 = 0x1 ;
V_29 -> V_69 . V_69 = 0x0b ;
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
case V_65 :
V_124 -> V_66 . V_67 = 0x1 ;
V_124 -> V_68 . V_69 = V_122 -> V_70 . V_69 ;
break;
case V_112 :
case V_113 :
V_124 -> V_66 . V_67 = 0x1 ;
V_124 -> V_68 . V_69 = V_122 -> V_70 . V_69 ;
V_124 -> V_139 = 0 ;
break;
case V_71 :
case V_72 :
case V_73 :
case V_74 :
V_124 -> V_66 . V_67 = 0x02 ;
V_124 -> V_68 . V_69 = V_122 -> V_70 . V_69 ;
V_34 = F_16 ( V_94 , V_118 ) ;
break;
case V_75 :
case V_76 :
V_124 -> V_68 . V_69 = V_77 ;
V_34 = F_16 ( V_94 , V_118 ) ;
break;
case V_78 :
case V_79 :
case V_80 :
V_124 -> V_66 . V_67 = 0x3 ;
V_124 -> V_66 . V_81 = 0x1 ;
V_124 -> V_68 . V_69 = V_77 ;
V_34 = F_16 ( V_94 , V_118 ) ;
break;
case V_107 :
V_124 -> V_66 . V_67 = 0x03 ;
V_124 -> V_68 . V_69 = V_122 -> V_70 . V_69 ;
V_124 -> V_139 = 0 ;
break;
case V_111 :
V_124 -> V_66 . V_67 = 0x02 ;
V_124 -> V_68 . V_69 = V_122 -> V_70 . V_69 ;
V_124 -> V_139 = V_121 ;
V_34 = F_16 ( V_94 , V_118 ) ;
break;
default:
F_18 ( V_114 , V_118 ,
L_7 , V_48 ) ;
F_19 () ;
return - V_128 ;
}
V_124 -> V_68 . V_83 = 0x3 ;
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
if ( V_124 -> V_68 . V_69 == V_87 ||
V_124 -> V_68 . V_69 == V_88 ) {
if ( V_50 + V_122 -> V_70 . V_89 < V_122 -> V_90 )
V_50 += V_122 -> V_70 . V_89 ;
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
V_29 -> V_69 . V_103 = 0x3 ;
V_29 -> V_69 . V_69 = 0x03 ;
break;
case V_57 :
V_29 -> V_69 . V_103 = 0x3 ;
V_29 -> V_69 . V_69 = 0x16 ;
break;
case V_80 :
V_29 -> V_69 . V_103 = 0x1 ;
V_29 -> V_69 . V_69 = 0x03 ;
V_29 -> V_42 ++ ;
break;
case V_58 :
V_29 -> V_69 . V_103 = 0x3 ;
V_29 -> V_69 . V_69 = 0x16 ;
V_29 -> V_42 ++ ;
break;
case V_71 :
case V_72 :
case V_73 :
case V_74 :
V_29 -> V_104 . V_144 = 0x1 ;
V_29 -> V_106 = V_99 ;
V_29 -> V_69 . V_69 = 0x01 ;
break;
case V_75 :
case V_76 :
V_29 -> V_104 . V_144 = 0x1 ;
V_29 -> V_106 = V_99 ;
V_29 -> V_69 . V_69 = 0x03 ;
break;
case V_59 :
case V_60 :
case V_63 :
case V_64 :
V_29 -> V_104 . V_144 = 0x1 ;
V_29 -> V_106 = V_99 ;
V_29 -> V_69 . V_69 = 0x06 ;
break;
case V_61 :
case V_62 :
V_29 -> V_104 . V_144 = 0x1 ;
V_29 -> V_106 = V_99 ;
V_29 -> V_69 . V_69 = 0x16 ;
break;
case V_65 :
V_29 -> V_69 . V_69 = 0x06 ;
break;
case V_78 :
V_29 -> V_106 = V_99 ;
V_29 -> V_104 . V_144 = 0x1 ;
V_29 -> V_69 . V_69 = 0x0b ;
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
V_33 -> V_70 . V_69 = V_282 ;
V_33 -> V_70 . V_89 = 0 ;
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
V_65 , V_31 ) ;
V_306 = V_168 -> V_29 + sizeof( struct V_28 ) ;
V_45 [ - 1 ] . V_43 |= V_250 ;
V_126 ( V_45 ++ , V_306 ++ , 0 , 0 , 4 ,
V_65 , V_31 , 0 ) ;
V_305 = V_33 -> V_309 ;
for ( V_199 = 0 ; V_199 < 4 ; V_199 ++ ) {
V_45 [ - 1 ] . V_43 |= V_250 ;
V_45 -> V_54 = V_65 ;
V_45 -> V_43 = 0 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_305 ;
V_45 ++ ;
V_305 ++ ;
}
V_45 [ - 1 ] . V_43 |= V_250 ;
V_126 ( V_45 ++ , V_306 ++ , 2 , 0 , 1 ,
V_65 , V_31 , 0 ) ;
V_45 [ - 1 ] . V_43 |= V_250 ;
V_45 -> V_54 = V_65 ;
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
F_108 ( struct V_30 * V_291 ,
struct V_334 * V_335 ,
int V_252 )
{
struct V_32 * V_336 ;
struct V_32 * V_337 ;
struct V_30 * V_119 = NULL ;
struct V_167 * V_338 ;
struct V_304 * V_339 ;
struct V_21 V_340 ;
struct V_26 * V_45 ;
void * V_29 ;
int V_341 ;
int V_307 , V_308 ;
int V_199 , V_342 ;
int V_343 = 0 ;
int V_344 ;
int V_345 ;
int V_346 ;
if ( V_252 )
V_119 = F_109 ( V_291 ) ;
if ( ! V_119 )
V_119 = V_291 ;
V_337 = V_119 -> V_33 ;
V_336 = V_291 -> V_33 ;
V_341 = F_9 ( & V_336 -> V_35 , 0 , V_335 -> V_121 ) ;
V_345 = V_335 -> V_347 - V_335 -> V_348 + 1 ;
if ( V_335 -> V_343 & 0x10 ) {
V_344 = 0 ;
V_343 = V_335 -> V_343 & ~ 0x10 ;
} else {
V_344 = 1 ;
V_343 = V_335 -> V_343 ;
}
V_346 = V_336 -> V_245 . V_273 [ 8 ] & 0x01 ;
switch ( V_343 ) {
case 0x00 :
case 0x08 :
V_307 = 2 + ( V_341 * V_345 ) ;
if ( V_346 )
V_308 = sizeof( struct V_93 ) +
sizeof( struct V_140 ) +
V_341 * V_345 * sizeof( struct V_304 ) ;
else
V_308 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
V_341 * V_345 * sizeof( struct V_304 ) ;
break;
case 0x01 :
case 0x09 :
V_307 = 2 + V_341 * V_345 ;
if ( V_346 )
V_308 = sizeof( struct V_93 ) +
sizeof( struct V_140 ) +
sizeof( struct V_304 ) +
V_341 * V_345 * sizeof( struct V_304 ) ;
else
V_308 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
sizeof( struct V_304 ) +
V_341 * V_345 * sizeof( struct V_304 ) ;
break;
case 0x04 :
case 0x0c :
V_307 = 3 ;
if ( V_346 )
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
V_335 -> V_343 ) ;
return F_110 ( - V_128 ) ;
}
V_338 = F_43 ( V_176 , V_307 ,
V_308 , V_119 ) ;
if ( F_44 ( V_338 ) )
return V_338 ;
V_337 -> V_42 ++ ;
V_29 = V_338 -> V_29 ;
V_45 = V_338 -> V_171 ;
switch ( V_343 & ~ 0x08 ) {
case 0x00 :
if ( V_346 ) {
F_21 ( V_45 ++ , (struct V_93 * ) V_29 ,
V_335 -> V_348 , V_335 -> V_347 ,
V_75 , V_291 , V_119 ) ;
if ( V_344 )
( (struct V_93 * ) V_29 )
-> F_13 . V_38 |= 0x04 ;
V_29 += sizeof( struct V_93 ) ;
} else {
F_13 ( V_45 ++ , (struct V_28 * ) V_29 ,
V_335 -> V_348 , V_335 -> V_347 ,
V_75 , V_119 ) ;
if ( V_344 )
( (struct V_28 * ) V_29 )
-> V_38 |= 0x04 ;
V_29 += sizeof( struct V_28 ) ;
}
V_45 [ - 1 ] . V_43 |= V_250 ;
V_126 ( V_45 ++ , (struct V_140 * ) V_29 ,
V_335 -> V_348 , 0 , V_341 * V_345 ,
V_75 , V_291 ,
V_335 -> V_121 ) ;
V_29 += sizeof( struct V_140 ) ;
break;
case 0x01 :
if ( V_346 ) {
F_21 ( V_45 ++ , (struct V_93 * ) V_29 ,
V_335 -> V_348 , V_335 -> V_347 ,
V_80 ,
V_291 , V_119 ) ;
V_29 += sizeof( struct V_93 ) ;
} else {
F_13 ( V_45 ++ , (struct V_28 * ) V_29 ,
V_335 -> V_348 , V_335 -> V_347 ,
V_80 , V_119 ) ;
V_29 += sizeof( struct V_28 ) ;
}
V_45 [ - 1 ] . V_43 |= V_250 ;
V_126 ( V_45 ++ , (struct V_140 * ) V_29 ,
V_335 -> V_348 , 0 , V_341 * V_345 + 1 ,
V_80 , V_291 ,
V_291 -> V_178 -> V_321 ) ;
V_29 += sizeof( struct V_140 ) ;
break;
case 0x04 :
if ( V_346 ) {
F_21 ( V_45 ++ , (struct V_93 * ) V_29 ,
V_335 -> V_348 , V_335 -> V_347 ,
V_75 , V_291 , V_119 ) ;
V_29 += sizeof( struct V_93 ) ;
} else {
F_13 ( V_45 ++ , (struct V_28 * ) V_29 ,
V_335 -> V_348 , V_335 -> V_347 ,
V_75 , V_119 ) ;
V_29 += sizeof( struct V_28 ) ;
}
V_45 [ - 1 ] . V_43 |= V_250 ;
V_126 ( V_45 ++ , (struct V_140 * ) V_29 ,
V_335 -> V_348 , 0 , 1 ,
V_75 , V_291 , 8 ) ;
V_29 += sizeof( struct V_140 ) ;
break;
}
for ( V_342 = 0 ; V_342 < V_345 ; V_342 ++ ) {
F_10 ( & V_340 ,
( V_335 -> V_348 + V_342 ) /
V_336 -> V_35 . V_86 ,
( V_335 -> V_348 + V_342 ) %
V_336 -> V_35 . V_86 ) ;
if ( V_343 & 0x01 ) {
V_339 = (struct V_304 * ) V_29 ;
V_29 += sizeof( struct V_304 ) ;
V_339 -> V_23 = V_340 . V_23 ;
V_339 -> V_24 = V_340 . V_24 ;
V_339 -> V_117 = 0 ;
V_339 -> V_16 = 0 ;
V_339 -> V_17 = 8 ;
V_45 [ - 1 ] . V_43 |= V_250 ;
V_45 -> V_54 = V_80 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_339 ;
V_45 ++ ;
}
if ( ( V_343 & ~ 0x08 ) & 0x04 ) {
V_339 = (struct V_304 * ) V_29 ;
V_29 += sizeof( struct V_304 ) ;
V_339 -> V_23 = V_340 . V_23 ;
V_339 -> V_24 = V_340 . V_24 ;
V_339 -> V_117 = 1 ;
V_339 -> V_16 = 0 ;
V_339 -> V_17 = 0 ;
V_45 [ - 1 ] . V_43 |= V_250 ;
V_45 -> V_54 = V_75 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_339 ;
} else {
for ( V_199 = 0 ; V_199 < V_341 ; V_199 ++ ) {
V_339 = (struct V_304 * ) V_29 ;
V_29 += sizeof( struct V_304 ) ;
V_339 -> V_23 = V_340 . V_23 ;
V_339 -> V_24 = V_340 . V_24 ;
V_339 -> V_117 = V_199 + 1 ;
V_339 -> V_16 = 0 ;
V_339 -> V_17 = V_335 -> V_121 ;
if ( ( V_343 & 0x08 ) &&
V_340 . V_23 == 0 && V_340 . V_24 == 0 ) {
if ( V_199 < 3 ) {
V_339 -> V_16 = 4 ;
V_339 -> V_17 = V_147 [ V_199 ] - 4 ;
}
}
if ( ( V_343 & 0x08 ) &&
V_340 . V_23 == 0 && V_340 . V_24 == 1 ) {
V_339 -> V_16 = 44 ;
V_339 -> V_17 = V_148 - 44 ;
}
V_45 [ - 1 ] . V_43 |= V_250 ;
if ( V_199 != 0 || V_342 == 0 )
V_45 -> V_54 =
V_75 ;
else
V_45 -> V_54 =
V_76 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_339 ;
V_45 ++ ;
}
}
}
V_338 -> V_119 = V_119 ;
V_338 -> V_177 = V_119 ;
V_338 -> V_118 = V_291 ;
V_338 -> V_181 = 256 ;
V_338 -> V_179 = V_119 -> V_284 * V_180 ;
V_338 -> V_182 = F_33 () ;
V_338 -> V_183 = V_184 ;
return V_338 ;
}
static struct V_167 *
F_111 ( struct V_30 * V_291 ,
struct V_334 * V_335 , int V_252 )
{
return F_108 ( V_291 , V_335 , V_252 ) ;
}
static int F_112 ( struct V_30 * V_291 ,
struct V_334 * V_335 )
{
struct V_32 * V_33 = V_291 -> V_33 ;
if ( V_335 -> V_348 >=
( V_33 -> V_90 * V_33 -> V_35 . V_86 ) ) {
F_57 ( & V_291 -> V_2 -> V_82 ,
L_70 ,
V_335 -> V_348 ) ;
return - V_128 ;
}
if ( V_335 -> V_347 >=
( V_33 -> V_90 * V_33 -> V_35 . V_86 ) ) {
F_57 ( & V_291 -> V_2 -> V_82 ,
L_71 ,
V_335 -> V_347 ) ;
return - V_128 ;
}
if ( V_335 -> V_348 > V_335 -> V_347 ) {
F_57 ( & V_291 -> V_2 -> V_82 ,
L_72 ,
V_335 -> V_348 ) ;
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
static int F_113 ( struct V_30 * V_291 ,
struct V_334 * V_335 ,
int V_252 )
{
struct V_32 * V_33 = V_291 -> V_33 ;
struct V_167 * V_168 , * V_349 ;
struct V_350 V_351 ;
struct V_30 * V_31 ;
int V_352 , V_353 , V_354 ;
int V_355 , V_356 ;
int V_34 ;
V_34 = F_112 ( V_291 , V_335 ) ;
if ( V_34 )
return V_34 ;
F_114 ( & V_351 ) ;
V_352 = V_335 -> V_348 ;
V_353 = V_335 -> V_347 ;
V_354 = V_357 / F_9 ( & V_33 -> V_35 , 0 ,
V_335 -> V_121 ) ;
do {
V_356 = 0 ;
while ( V_335 -> V_348 <= V_353 ) {
V_355 = V_335 -> V_347 - V_335 -> V_348 + 1 ;
if ( V_355 > V_354 ) {
V_335 -> V_347 =
V_335 -> V_348 + V_354 - 1 ;
}
V_168 = F_111 ( V_291 , V_335 ,
V_252 ) ;
if ( F_44 ( V_168 ) ) {
V_34 = F_72 ( V_168 ) ;
if ( V_34 == - V_197 ) {
if ( F_115 ( & V_351 ) )
goto V_358;
V_356 = 1 ;
break;
}
goto V_359;
}
F_116 ( & V_168 -> V_360 , & V_351 ) ;
V_335 -> V_348 = V_335 -> V_347 + 1 ;
V_335 -> V_347 = V_353 ;
}
V_34 = F_117 ( & V_351 ) ;
V_359:
F_118 (cqr, n, &format_queue, blocklist) {
V_31 = V_168 -> V_119 ;
V_33 = V_31 -> V_33 ;
if ( V_168 -> V_183 == V_314 )
V_34 = - V_280 ;
F_119 ( & V_168 -> V_360 ) ;
F_46 ( V_168 , V_31 ) ;
V_33 -> V_42 -- ;
}
if ( V_34 )
goto V_358;
} while ( V_356 );
V_358:
V_335 -> V_348 = V_352 ;
V_335 -> V_347 = V_353 ;
return V_34 ;
}
static int F_120 ( struct V_30 * V_291 ,
struct V_334 * V_335 , int V_252 )
{
return F_113 ( V_291 , V_335 , V_252 ) ;
}
static void F_121 ( struct V_167 * V_168 )
{
if ( V_168 -> V_181 < 0 ) {
V_168 -> V_183 = V_314 ;
return;
}
V_168 -> V_183 = V_184 ;
if ( V_168 -> V_178 && ( V_168 -> V_119 != V_168 -> V_178 -> V_291 ) ) {
F_122 ( V_168 ) ;
V_168 -> V_119 = V_168 -> V_178 -> V_291 ;
V_168 -> V_170 = V_168 -> V_178 -> V_291 -> V_215 . V_212 ;
}
}
static T_5
F_123 ( struct V_167 * V_168 )
{
struct V_30 * V_31 = (struct V_30 * ) V_168 -> V_119 ;
struct V_1 * V_2 = V_31 -> V_2 ;
switch ( V_2 -> V_361 . V_84 ) {
case 0x3990 :
case 0x2105 :
case 0x2107 :
case 0x1750 :
return V_362 ;
case 0x9343 :
case 0x3880 :
default:
return V_363 ;
}
}
static T_5
F_124 ( struct V_167 * V_168 )
{
return V_364 ;
}
static void F_125 ( struct V_30 * V_31 ,
struct V_167 * V_168 ,
struct V_315 * V_315 )
{
char V_66 ;
char * V_311 = NULL ;
struct V_32 * V_33 = V_31 -> V_33 ;
V_66 = V_365 | V_366 | V_367 ;
if ( ( F_126 ( & V_315 -> V_368 ) & V_66 ) == V_66 ) {
if ( ! V_31 -> V_178 && V_33 -> V_369 &&
V_31 -> V_263 == V_264 &&
! F_61 ( V_262 , & V_31 -> V_43 ) &&
! F_61 ( V_234 , & V_31 -> V_43 ) ) {
F_127 ( V_31 ) ;
}
F_128 ( V_31 ) ;
return;
}
V_311 = F_93 ( V_315 ) ;
if ( ! V_311 )
return;
if ( ( V_311 [ 27 ] & V_370 ) && ( V_311 [ 7 ] == 0x0D ) &&
( F_126 ( & V_315 -> V_368 ) & V_371 ) ) {
if ( F_63 ( V_372 , & V_31 -> V_43 ) ) {
F_18 ( V_7 , V_31 , L_1 ,
L_74 ) ;
return;
}
V_311 = F_93 ( V_315 ) ;
if ( ! V_311 ) {
F_18 ( V_7 , V_31 , L_1 ,
L_75 ) ;
F_39 ( V_372 , & V_31 -> V_43 ) ;
return;
}
V_33 -> V_373 = V_311 [ 8 ] ;
F_18 ( V_374 , V_31 , L_76 ,
L_77 ,
V_33 -> V_373 ) ;
F_70 ( V_31 ) ;
if ( ! F_62 ( & V_31 -> V_278 ) )
F_64 ( V_31 ) ;
return;
}
if ( ! V_168 && ! ( V_311 [ 27 ] & V_370 ) &&
( ( V_311 [ 6 ] & V_375 ) == V_375 ) ) {
F_129 ( V_31 , V_311 ) ;
return;
}
if ( V_31 -> V_178 && ( V_311 [ 27 ] & V_370 ) &&
( V_311 [ 7 ] == 0x3F ) &&
( F_126 ( & V_315 -> V_368 ) & V_371 ) &&
F_61 ( V_376 , & V_31 -> V_43 ) ) {
if ( V_31 -> V_245 & V_377 )
F_34 ( V_378 , & V_31 -> V_43 ) ;
F_39 ( V_376 , & V_31 -> V_43 ) ;
F_15 ( & V_31 -> V_2 -> V_82 ,
L_78 ) ;
}
}
static struct V_167 * F_130 (
struct V_30 * V_119 ,
struct V_274 * V_178 ,
struct V_379 * V_380 ,
T_6 V_381 ,
T_6 V_382 ,
T_6 V_383 ,
T_6 V_384 ,
unsigned int V_385 ,
unsigned int V_386 ,
unsigned int V_145 ,
unsigned int V_121 )
{
struct V_32 * V_33 ;
unsigned long * V_387 ;
struct V_140 * V_306 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
struct V_388 V_389 ;
struct V_390 V_391 ;
char * V_392 ;
unsigned int V_393 ;
int V_42 , V_394 , V_307 , V_308 ;
T_6 V_146 ;
unsigned char V_48 , V_395 ;
int V_346 ;
struct V_30 * V_118 ;
V_118 = V_178 -> V_291 ;
V_33 = V_118 -> V_33 ;
if ( F_131 ( V_380 ) == V_396 )
V_48 = V_60 ;
else if ( F_131 ( V_380 ) == V_397 )
V_48 = V_72 ;
else
return F_110 ( - V_128 ) ;
V_42 = 0 ;
V_394 = 0 ;
F_132 (bv, req, iter) {
if ( V_391 . V_398 & ( V_121 - 1 ) )
return F_110 ( - V_128 ) ;
V_42 += V_391 . V_398 >> ( V_178 -> V_324 + 9 ) ;
if ( F_133 ( F_134 ( V_391 . V_399 ) , V_391 . V_398 ) )
V_394 += V_391 . V_398 >> ( V_178 -> V_324 + 9 ) ;
}
if ( V_42 != V_382 - V_381 + 1 )
return F_110 ( - V_128 ) ;
V_346 = V_33 -> V_245 . V_273 [ 8 ] & 0x01 ;
if ( V_346 ) {
V_307 = 2 + V_42 ;
V_308 = sizeof( struct V_93 ) +
sizeof( struct V_140 ) +
V_394 * sizeof( unsigned long ) ;
} else {
V_307 = 2 + V_42 ;
V_308 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
V_394 * sizeof( unsigned long ) ;
}
if ( V_33 -> V_85 && V_381 < 2 * V_145 ) {
if ( V_382 >= 2 * V_145 )
V_42 = 2 * V_145 - V_381 ;
V_307 += V_42 ;
V_308 += V_42 * sizeof( struct V_140 ) ;
}
V_168 = F_43 ( V_176 , V_307 , V_308 ,
V_119 ) ;
if ( F_44 ( V_168 ) )
return V_168 ;
V_45 = V_168 -> V_171 ;
if ( V_346 ) {
if ( F_21 ( V_45 ++ , V_168 -> V_29 , V_383 ,
V_384 , V_48 , V_118 , V_119 ) == - V_237 ) {
F_46 ( V_168 , V_119 ) ;
return F_110 ( - V_237 ) ;
}
V_387 = ( unsigned long * ) ( V_168 -> V_29 +
sizeof( struct V_93 ) ) ;
} else {
if ( F_13 ( V_45 ++ , V_168 -> V_29 , V_383 ,
V_384 , V_48 , V_118 ) == - V_237 ) {
F_46 ( V_168 , V_119 ) ;
return F_110 ( - V_237 ) ;
}
V_387 = ( unsigned long * ) ( V_168 -> V_29 +
sizeof( struct V_28 ) ) ;
}
V_306 = (struct V_140 * ) ( V_387 + V_394 ) ;
V_146 = V_381 ;
if ( V_33 -> V_85 == 0 || V_146 > 2 * V_145 ) {
V_45 [ - 1 ] . V_43 |= V_250 ;
V_126 ( V_45 ++ , V_306 ++ , V_383 , V_385 + 1 ,
V_382 - V_146 + 1 , V_48 , V_118 , V_121 ) ;
}
F_132 (bv, req, iter) {
V_392 = F_134 ( V_391 . V_399 ) + V_391 . V_400 ;
if ( V_401 ) {
char * V_402 = F_135 ( V_401 ,
V_196 | V_403 ) ;
if ( V_402 && F_131 ( V_380 ) == V_397 )
memcpy ( V_402 + V_391 . V_400 , V_392 , V_391 . V_398 ) ;
if ( V_402 )
V_392 = V_402 + V_391 . V_400 ;
}
for ( V_393 = 0 ; V_393 < V_391 . V_398 ; V_393 += V_121 ) {
T_6 V_404 = V_146 ;
unsigned int V_405 = F_136 ( V_404 , V_145 ) ;
V_395 = V_48 ;
V_42 = V_121 ;
if ( V_33 -> V_85 && V_146 < 2 * V_145 ) {
if ( F_22 ( V_145 , V_146 ) ) {
V_395 |= 0x8 ;
V_42 = F_23 ( V_146 ) ;
if ( V_42 < V_121 &&
F_131 ( V_380 ) == V_396 )
memset ( V_392 + V_42 , 0xe5 ,
V_121 - V_42 ) ;
}
V_45 [ - 1 ] . V_43 |= V_250 ;
V_126 ( V_45 ++ , V_306 ++ ,
V_404 , V_405 + 1 ,
1 , V_395 , V_118 , V_42 ) ;
}
if ( V_33 -> V_85 && V_146 == 2 * V_145 ) {
V_45 [ - 1 ] . V_43 |= V_250 ;
V_126 ( V_45 ++ , V_306 ++ ,
V_404 , V_405 + 1 ,
V_382 - V_146 + 1 ,
V_48 , V_118 , V_42 ) ;
}
V_45 [ - 1 ] . V_43 |= V_250 ;
V_45 -> V_54 = V_395 ;
V_45 -> V_42 = V_42 ;
if ( F_133 ( V_392 , V_121 ) ) {
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_387 ;
V_45 -> V_43 = V_406 ;
V_387 = F_137 ( V_387 , V_392 , V_121 ) ;
} else {
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_392 ;
V_45 -> V_43 = 0 ;
}
V_45 ++ ;
V_392 += V_121 ;
V_146 ++ ;
}
}
if ( F_138 ( V_380 ) ||
V_178 -> V_291 -> V_245 & V_407 )
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
static struct V_167 * F_139 (
struct V_30 * V_119 ,
struct V_274 * V_178 ,
struct V_379 * V_380 ,
T_6 V_381 ,
T_6 V_382 ,
T_6 V_383 ,
T_6 V_384 ,
unsigned int V_385 ,
unsigned int V_386 ,
unsigned int V_145 ,
unsigned int V_121 )
{
unsigned long * V_387 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
struct V_388 V_389 ;
struct V_390 V_391 ;
char * V_392 , * V_408 ;
unsigned int V_394 , V_307 , V_308 ;
unsigned int V_100 ;
T_6 V_146 ;
unsigned char V_48 ;
struct V_30 * V_118 ;
unsigned int V_409 , V_42 , V_410 ;
unsigned int V_411 , V_412 , V_413 , V_414 ;
unsigned char V_415 , V_416 ;
T_6 V_404 ;
unsigned int V_405 ;
V_118 = V_178 -> V_291 ;
if ( F_131 ( V_380 ) == V_396 )
V_48 = V_113 ;
else if ( F_131 ( V_380 ) == V_397 )
V_48 = V_111 ;
else
return F_110 ( - V_128 ) ;
V_394 = V_382 - V_381 + 1 ;
V_409 = V_384 - V_383 + 1 ;
V_307 = 1 + V_409 ;
V_308 = sizeof( struct V_93 ) +
V_394 * sizeof( unsigned long long ) ;
V_168 = F_43 ( V_176 , V_307 , V_308 ,
V_119 ) ;
if ( F_44 ( V_168 ) )
return V_168 ;
V_45 = V_168 -> V_171 ;
if ( V_383 == V_384 )
V_100 = V_386 - V_385 + 1 ;
else
V_100 = V_386 + 1 ;
V_100 *= V_121 ;
if ( F_20 ( V_45 ++ , V_168 -> V_29 , V_383 ,
V_384 , V_48 , V_118 , V_119 ,
1 , V_385 + 1 ,
V_409 , V_121 ,
V_100 ) == - V_237 ) {
F_46 ( V_168 , V_119 ) ;
return F_110 ( - V_237 ) ;
}
V_387 = ( unsigned long * ) ( V_168 -> V_29 + sizeof( struct V_93 ) ) ;
V_146 = V_381 ;
V_415 = 1 ;
V_416 = 0 ;
V_414 = 0 ;
V_408 = NULL ;
V_411 = 0 ;
F_132 (bv, req, iter) {
V_392 = F_134 ( V_391 . V_399 ) + V_391 . V_400 ;
V_412 = V_391 . V_398 ;
while ( V_412 ) {
if ( V_415 ) {
V_404 = V_146 ;
V_405 = F_136 ( V_404 , V_145 ) ;
V_410 = V_145 - V_405 ;
V_42 = F_140 ( ( V_382 - V_146 + 1 ) ,
( T_6 ) V_410 ) ;
V_414 = V_42 * V_121 ;
V_45 [ - 1 ] . V_43 |= V_250 ;
V_45 -> V_54 = V_48 ;
V_45 -> V_42 = V_414 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_387 ;
V_45 -> V_43 = V_406 ;
V_45 ++ ;
V_146 += V_42 ;
V_415 = 0 ;
if ( ! V_408 )
V_408 = V_392 ;
}
if ( ! V_408 ) {
if ( F_14 ( V_392 ) & ( V_417 - 1 ) ) {
F_46 ( V_168 , V_119 ) ;
return F_110 ( - V_418 ) ;
} else
V_408 = V_392 ;
}
if ( ( V_408 + V_411 ) != V_392 ) {
F_46 ( V_168 , V_119 ) ;
return F_110 ( - V_418 ) ;
}
V_413 = F_140 ( V_412 , V_414 ) ;
V_412 -= V_413 ;
V_392 += V_413 ;
V_411 += V_413 ;
V_414 -= V_413 ;
if ( ! ( F_14 ( V_408 + V_411 ) & ( V_417 - 1 ) ) )
V_416 = 1 ;
if ( ! V_414 ) {
V_415 = 1 ;
V_416 = 1 ;
}
if ( V_416 ) {
V_387 = F_137 ( V_387 , V_408 ,
V_411 ) ;
V_408 = NULL ;
V_411 = 0 ;
V_416 = 0 ;
}
}
}
if ( F_138 ( V_380 ) ||
V_178 -> V_291 -> V_245 & V_407 )
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
static int F_141 ( struct V_419 * V_419 ,
unsigned int V_46 , unsigned int V_47 , int V_48 ,
struct V_30 * V_118 ,
struct V_30 * V_119 ,
unsigned int V_98 , int V_42 ,
unsigned int V_121 ,
unsigned int V_420 ,
unsigned int V_100 ,
unsigned int V_145 )
{
struct V_93 V_94 ;
struct V_32 * V_122 , * V_123 ;
struct V_28 * V_124 ;
struct V_97 * V_125 ;
struct V_421 * V_421 ;
T_3 V_49 , V_50 ;
T_4 V_51 , V_52 , V_53 ;
T_7 V_422 ;
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
V_124 -> V_66 . V_67 = 0x1 ;
V_124 -> V_68 . V_69 = V_122 -> V_70 . V_69 ;
V_124 -> V_139 = V_121 ;
V_124 -> V_38 |= 0x42 ;
V_125 -> V_69 . V_103 = 0x0 ;
V_125 -> V_69 . V_69 = 0x0C ;
V_125 -> V_104 . V_423 = 0x01 ;
V_422 = V_424 ;
break;
case V_111 :
V_124 -> V_66 . V_67 = 0x02 ;
V_124 -> V_68 . V_69 = V_122 -> V_70 . V_69 ;
V_124 -> V_139 = V_121 ;
V_34 = F_16 ( & V_94 , V_118 ) ;
V_124 -> V_38 |= 0x42 ;
V_125 -> V_69 . V_103 = 0x0 ;
V_125 -> V_69 . V_69 = 0x3F ;
V_125 -> V_108 = 0x23 ;
V_125 -> V_104 . V_423 = 0x2 ;
V_422 = V_127 ;
break;
default:
F_18 ( V_114 , V_118 ,
L_79 , V_48 ) ;
F_19 () ;
break;
}
if ( V_34 )
return V_34 ;
V_124 -> V_68 . V_83 = 0x3 ;
V_51 = V_122 -> V_35 . V_86 ;
V_49 = V_46 / V_51 ;
V_52 = V_46 % V_51 ;
V_50 = V_47 / V_51 ;
V_53 = V_47 % V_51 ;
if ( V_124 -> V_68 . V_69 == V_87 ||
V_124 -> V_68 . V_69 == V_88 ) {
if ( V_50 + V_122 -> V_70 . V_89 < V_122 -> V_90 )
V_50 += V_122 -> V_70 . V_89 ;
else
V_50 = ( V_122 -> V_90 - 1 ) ;
}
F_10 ( & V_124 -> V_91 , V_49 , V_52 ) ;
F_10 ( & V_124 -> V_92 , V_50 , V_53 ) ;
V_124 -> V_425 = 0x20 ;
V_124 -> V_426 = V_145 ;
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
V_125 -> V_104 . V_105 = 1 ;
V_125 -> V_104 . V_427 = 1 ;
V_125 -> V_104 . V_428 = 1 ;
V_125 -> V_106 = V_100 ;
V_125 -> V_429 = V_48 ;
V_125 -> V_42 = V_42 ;
V_125 -> V_101 = V_101 ;
F_10 ( & V_125 -> V_115 , V_49 , V_52 ) ;
V_125 -> V_116 . V_23 = V_125 -> V_115 . V_23 ;
V_125 -> V_116 . V_24 = V_125 -> V_115 . V_24 ;
V_125 -> V_116 . V_117 = V_98 ;
V_421 = F_142 ( V_419 , V_422 , 0 ,
& V_94 , sizeof( V_94 ) , V_420 ) ;
return F_143 ( V_421 ) ;
}
static struct V_167 * F_144 (
struct V_30 * V_119 ,
struct V_274 * V_178 ,
struct V_379 * V_380 ,
T_6 V_381 ,
T_6 V_382 ,
T_6 V_383 ,
T_6 V_384 ,
unsigned int V_385 ,
unsigned int V_386 ,
unsigned int V_145 ,
unsigned int V_121 )
{
struct V_167 * V_168 ;
struct V_388 V_389 ;
struct V_390 V_391 ;
char * V_392 ;
unsigned int V_409 , V_430 ;
unsigned char V_48 ;
struct V_30 * V_118 ;
unsigned int V_100 ;
struct V_419 * V_419 ;
struct V_431 * V_432 = NULL ;
int V_433 ;
T_8 V_434 ;
T_7 V_435 ;
unsigned int V_412 , V_413 , V_414 ;
unsigned char V_415 ;
T_6 V_146 , V_404 ;
unsigned int V_436 ;
unsigned int V_42 , V_410 ;
int V_3 ;
V_118 = V_178 -> V_291 ;
if ( F_131 ( V_380 ) == V_396 ) {
V_48 = V_113 ;
V_433 = V_437 ;
} else if ( F_131 ( V_380 ) == V_397 ) {
V_48 = V_111 ;
V_433 = V_438 ;
} else
return F_110 ( - V_128 ) ;
V_409 = V_384 - V_383 + 1 ;
V_430 = 0 ;
F_132 (bv, req, iter) {
++ V_430 ;
}
if ( F_131 ( V_380 ) == V_397 )
V_430 += ( V_384 - V_383 ) ;
V_434 = F_145 ( 0 , V_430 , 0 ) ;
V_168 = F_43 ( V_176 , 0 , V_434 , V_119 ) ;
if ( F_44 ( V_168 ) )
return V_168 ;
if ( V_383 == V_384 )
V_100 = V_386 - V_385 + 1 ;
else
V_100 = V_386 + 1 ;
V_100 *= V_121 ;
V_419 = F_146 ( V_168 -> V_29 , V_434 , V_433 , 0 , V_430 , 0 ) ;
if ( F_44 ( V_419 ) ) {
V_3 = - V_128 ;
goto V_194;
}
V_168 -> V_171 = F_147 ( V_419 ) ;
if ( F_141 ( V_419 , V_383 , V_384 ,
V_48 , V_118 , V_119 ,
V_385 + 1 ,
V_409 , V_121 ,
( V_382 - V_381 + 1 ) * V_121 ,
V_100 , V_145 ) == - V_237 ) {
V_3 = - V_237 ;
goto V_194;
}
V_414 = 0 ;
if ( F_131 ( V_380 ) == V_397 ) {
V_415 = 1 ;
V_146 = V_381 ;
F_132 (bv, req, iter) {
V_392 = F_134 ( V_391 . V_399 ) + V_391 . V_400 ;
V_412 = V_391 . V_398 ;
while ( V_412 ) {
if ( V_415 ) {
V_404 = V_146 ;
V_436 = F_136 ( V_404 , V_145 ) ;
V_410 = V_145 - V_436 ;
V_42 = F_140 ( ( V_382 - V_146 + 1 ) ,
( T_6 ) V_410 ) ;
V_414 = V_42 * V_121 ;
V_146 += V_42 ;
V_415 = 0 ;
}
V_413 = F_140 ( V_412 , V_414 ) ;
V_412 -= V_413 ;
V_414 -= V_413 ;
if ( ! V_414 ) {
V_415 = 1 ;
V_435 = V_439 ;
} else
V_435 = 0 ;
V_432 = F_148 ( V_419 , V_435 ,
V_392 , V_413 ) ;
if ( F_44 ( V_432 ) ) {
V_3 = - V_128 ;
goto V_194;
}
V_392 += V_413 ;
}
}
} else {
F_132 (bv, req, iter) {
V_392 = F_134 ( V_391 . V_399 ) + V_391 . V_400 ;
V_432 = F_148 ( V_419 , 0x00 ,
V_392 , V_391 . V_398 ) ;
if ( F_44 ( V_432 ) ) {
V_3 = - V_128 ;
goto V_194;
}
}
}
V_432 -> V_43 |= V_440 ;
V_432 -> V_43 &= ~ V_439 ;
F_149 ( V_419 ) ;
if ( F_138 ( V_380 ) ||
V_178 -> V_291 -> V_245 & V_407 )
F_34 ( V_261 , & V_168 -> V_43 ) ;
V_168 -> V_441 = 1 ;
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
return F_110 ( V_3 ) ;
}
static struct V_167 * F_150 ( struct V_30 * V_119 ,
struct V_274 * V_178 ,
struct V_379 * V_380 )
{
int V_442 , V_443 ;
int V_346 ;
int V_444 ;
struct V_32 * V_33 ;
struct V_30 * V_118 ;
T_6 V_381 , V_382 ;
T_6 V_383 , V_384 ;
unsigned int V_385 , V_386 ;
unsigned int V_145 , V_121 ;
int V_445 ;
unsigned int V_446 ;
struct V_167 * V_168 ;
V_118 = V_178 -> V_291 ;
V_33 = V_118 -> V_33 ;
V_121 = V_178 -> V_321 ;
V_145 = F_9 ( & V_33 -> V_35 , 0 , V_121 ) ;
if ( V_145 == 0 )
return F_110 ( - V_128 ) ;
V_381 = V_383 = F_151 ( V_380 ) >> V_178 -> V_324 ;
V_385 = F_136 ( V_383 , V_145 ) ;
V_382 = V_384 =
( F_151 ( V_380 ) + F_152 ( V_380 ) - 1 ) >> V_178 -> V_324 ;
V_386 = F_136 ( V_384 , V_145 ) ;
V_445 = ( V_33 -> V_85 && V_381 < 2 * V_145 ) ;
V_444 = V_33 -> V_245 . V_273 [ 40 ] & 0x20 ;
V_446 = F_153 ( V_380 ) ;
if ( V_446 % V_121 )
return F_110 ( - V_128 ) ;
if ( F_131 ( V_380 ) == V_397 )
V_446 += ( V_384 - V_383 ) * 4 ;
V_442 = V_33 -> V_245 . V_273 [ 9 ] & 0x20 ;
V_443 = V_33 -> V_245 . V_273 [ 12 ] & 0x40 ;
V_346 = V_33 -> V_245 . V_273 [ 8 ] & 0x01 ;
V_168 = NULL ;
if ( V_445 || V_401 ) {
} else if ( ( V_446 <= V_33 -> V_225 )
&& ( V_444 || ( V_383 == V_384 ) ) ) {
V_168 = F_144 ( V_119 , V_178 , V_380 ,
V_381 , V_382 ,
V_383 , V_384 ,
V_385 , V_386 ,
V_145 , V_121 ) ;
if ( F_44 ( V_168 ) && ( F_72 ( V_168 ) != - V_237 ) &&
( F_72 ( V_168 ) != - V_197 ) )
V_168 = NULL ;
} else if ( V_346 &&
( ( ( F_131 ( V_380 ) == V_396 ) && V_442 ) ||
( ( F_131 ( V_380 ) == V_397 ) && V_443 ) ) ) {
V_168 = F_139 ( V_119 , V_178 , V_380 ,
V_381 , V_382 ,
V_383 , V_384 ,
V_385 , V_386 ,
V_145 , V_121 ) ;
if ( F_44 ( V_168 ) && ( F_72 ( V_168 ) != - V_237 ) &&
( F_72 ( V_168 ) != - V_197 ) )
V_168 = NULL ;
}
if ( ! V_168 )
V_168 = F_130 ( V_119 , V_178 , V_380 ,
V_381 , V_382 ,
V_383 , V_384 ,
V_385 , V_386 ,
V_145 , V_121 ) ;
return V_168 ;
}
static struct V_167 * F_154 ( struct V_30 * V_119 ,
struct V_274 * V_178 ,
struct V_379 * V_380 )
{
unsigned long * V_387 ;
struct V_30 * V_118 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
struct V_388 V_389 ;
struct V_390 V_391 ;
char * V_392 ;
unsigned char V_48 ;
unsigned int V_409 ;
unsigned int V_412 , V_414 ;
unsigned int V_385 ;
unsigned int V_394 , V_307 , V_308 ;
T_6 V_383 , V_384 , V_332 ;
T_6 V_447 , V_448 , V_449 ;
unsigned int V_450 ;
V_447 = F_151 ( V_380 ) % V_451 ;
V_448 = ( F_151 ( V_380 ) + F_152 ( V_380 ) ) %
V_451 ;
V_449 = ( V_451 - V_448 ) %
V_451 ;
V_118 = V_178 -> V_291 ;
if ( ( V_447 || V_449 ) &&
( F_131 ( V_380 ) == V_397 ) ) {
F_18 ( V_114 , V_118 ,
L_80 ,
V_447 , V_449 , V_380 ) ;
V_168 = F_110 ( - V_128 ) ;
goto V_358;
}
V_383 = F_151 ( V_380 ) / V_451 ;
V_384 = ( F_151 ( V_380 ) + F_152 ( V_380 ) - 1 ) /
V_451 ;
V_409 = V_384 - V_383 + 1 ;
V_385 = 0 ;
if ( F_131 ( V_380 ) == V_396 )
V_48 = V_112 ;
else if ( F_131 ( V_380 ) == V_397 )
V_48 = V_107 ;
else {
V_168 = F_110 ( - V_128 ) ;
goto V_358;
}
V_394 = V_409 * V_323 ;
V_307 = 1 + V_409 ;
V_450 = sizeof( struct V_93 ) + 8 ;
V_308 = V_450 + V_394 * sizeof( unsigned long long ) ;
V_168 = F_43 ( V_176 , V_307 ,
V_308 , V_119 ) ;
if ( F_44 ( V_168 ) )
goto V_358;
V_45 = V_168 -> V_171 ;
if ( F_20 ( V_45 ++ , V_168 -> V_29 , V_383 , V_384 , V_48 ,
V_118 , V_119 , 1 , V_385 + 1 ,
V_409 , 0 , 0 ) == - V_237 ) {
F_46 ( V_168 , V_119 ) ;
V_168 = F_110 ( - V_237 ) ;
goto V_358;
}
V_387 = ( unsigned long * ) ( V_168 -> V_29 + V_450 ) ;
V_414 = 0 ;
if ( V_447 ) {
V_45 [ - 1 ] . V_43 |= V_250 ;
V_45 -> V_54 = V_48 ;
V_45 -> V_42 = 57326 ;
V_414 = 65536 - V_447 * 512 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_387 ;
V_45 -> V_43 |= V_406 ;
V_45 -> V_43 |= V_44 ;
V_45 ++ ;
for ( V_332 = 0 ; V_332 < V_447 ; V_332 += 8 )
V_387 = F_137 ( V_387 , V_452 , V_453 ) ;
}
F_132 (bv, req, iter) {
V_392 = F_134 ( V_391 . V_399 ) + V_391 . V_400 ;
V_412 = V_391 . V_398 ;
if ( V_48 == V_112 )
memset ( V_392 , 0 , V_412 ) ;
if ( ! V_414 ) {
V_45 [ - 1 ] . V_43 |= V_250 ;
V_45 -> V_54 = V_48 ;
V_45 -> V_42 = 57326 ;
V_414 = 65536 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_387 ;
V_45 -> V_43 |= V_406 ;
V_45 -> V_43 |= V_44 ;
V_45 ++ ;
}
V_414 -= V_412 ;
V_387 = F_137 ( V_387 , V_392 , V_412 ) ;
}
for ( V_332 = 0 ; V_332 < V_449 ; V_332 += 8 )
V_387 = F_137 ( V_387 , V_452 , V_453 ) ;
if ( F_138 ( V_380 ) ||
V_178 -> V_291 -> V_245 & V_407 )
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
V_358:
return V_168 ;
}
static int
F_155 ( struct V_167 * V_168 , struct V_379 * V_380 )
{
struct V_32 * V_33 ;
struct V_26 * V_45 ;
struct V_388 V_389 ;
struct V_390 V_391 ;
char * V_392 , * V_56 ;
unsigned int V_121 , V_145 , V_393 ;
T_6 V_146 ;
int V_183 ;
if ( ! V_401 )
goto V_358;
V_33 = V_168 -> V_178 -> V_291 -> V_33 ;
V_121 = V_168 -> V_178 -> V_321 ;
V_145 = F_9 ( & V_33 -> V_35 , 0 , V_121 ) ;
V_146 = F_151 ( V_380 ) >> V_168 -> V_178 -> V_324 ;
V_45 = V_168 -> V_171 ;
V_45 ++ ;
if ( V_33 -> V_85 == 0 || V_146 > 2 * V_145 )
V_45 ++ ;
F_132 (bv, req, iter) {
V_392 = F_134 ( V_391 . V_399 ) + V_391 . V_400 ;
for ( V_393 = 0 ; V_393 < V_391 . V_398 ; V_393 += V_121 ) {
if ( V_33 -> V_85 && V_146 <= 2 * V_145 )
V_45 ++ ;
if ( V_392 ) {
if ( V_45 -> V_43 & V_406 )
V_56 = * ( ( char * * ) ( ( V_173 ) V_45 -> V_56 ) ) ;
else
V_56 = ( char * ) ( ( V_173 ) V_45 -> V_56 ) ;
if ( V_392 != V_56 ) {
if ( F_131 ( V_380 ) == V_396 )
memcpy ( V_392 , V_56 , V_391 . V_398 ) ;
F_156 ( V_401 ,
( void * ) ( ( V_173 ) V_56 & V_454 ) ) ;
}
V_392 = NULL ;
}
V_45 ++ ;
V_146 ++ ;
}
}
V_358:
V_183 = V_168 -> V_183 == V_186 ;
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_183 ;
}
void F_122 ( struct V_167 * V_168 )
{
struct V_26 * V_45 ;
struct V_93 * V_94 ;
struct V_455 * V_455 ;
struct V_456 * V_456 ;
struct V_421 * V_421 ;
if ( V_168 -> V_441 == 1 ) {
V_455 = V_168 -> V_171 ;
V_456 = F_157 ( V_455 ) ;
V_421 = (struct V_421 * ) & V_456 -> V_457 [ 0 ] ;
V_94 = (struct V_93 * ) & V_421 -> V_458 [ 0 ] ;
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
static struct V_167 * F_158 ( struct V_30 * V_291 ,
struct V_274 * V_178 ,
struct V_379 * V_380 )
{
struct V_32 * V_33 ;
struct V_30 * V_119 ;
unsigned long V_43 ;
struct V_167 * V_168 ;
V_119 = F_109 ( V_291 ) ;
if ( ! V_119 )
V_119 = V_291 ;
V_33 = V_119 -> V_33 ;
if ( V_33 -> V_42 >= V_459 )
return F_110 ( - V_460 ) ;
F_27 ( F_28 ( V_119 -> V_2 ) , V_43 ) ;
V_33 -> V_42 ++ ;
if ( ( V_291 -> V_245 & V_294 ) )
V_168 = F_154 ( V_119 , V_178 , V_380 ) ;
else
V_168 = F_150 ( V_119 , V_178 , V_380 ) ;
if ( F_44 ( V_168 ) )
V_33 -> V_42 -- ;
F_29 ( F_28 ( V_119 -> V_2 ) , V_43 ) ;
return V_168 ;
}
static int F_159 ( struct V_167 * V_168 ,
struct V_379 * V_380 )
{
struct V_32 * V_33 ;
unsigned long V_43 ;
F_27 ( F_28 ( V_168 -> V_177 -> V_2 ) , V_43 ) ;
V_33 = V_168 -> V_177 -> V_33 ;
V_33 -> V_42 -- ;
F_29 ( F_28 ( V_168 -> V_177 -> V_2 ) , V_43 ) ;
return F_155 ( V_168 , V_380 ) ;
}
static int
F_160 ( struct V_30 * V_31 ,
struct V_461 * V_462 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
V_462 -> V_463 = 2 ;
V_462 -> V_464 = V_33 -> V_85 ? 0 : 1 ;
V_462 -> V_120 = V_33 -> V_85 ? V_465 : V_466 ;
V_462 -> V_467 = sizeof( V_33 -> V_35 ) ;
memcpy ( V_462 -> V_468 , & V_33 -> V_35 ,
sizeof( V_33 -> V_35 ) ) ;
V_462 -> V_469 = F_140 ( ( unsigned long ) V_33 -> V_200 ,
sizeof( V_462 -> V_470 ) ) ;
memcpy ( V_462 -> V_470 , V_33 -> V_201 ,
V_462 -> V_469 ) ;
return 0 ;
}
static int
F_161 ( struct V_30 * V_31 )
{
struct V_167 * V_168 ;
int V_34 ;
struct V_26 * V_45 ;
int V_471 ;
if ( ! F_162 ( V_472 ) )
return - V_41 ;
V_471 = 0 ;
V_168 = F_43 ( V_176 , 1 , 32 , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_163 ( & V_473 ) ;
V_471 = 1 ;
V_168 = & V_474 -> V_168 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
memset ( & V_474 -> V_45 , 0 ,
sizeof( V_474 -> V_45 ) ) ;
V_168 -> V_171 = & V_474 -> V_45 ;
V_168 -> V_29 = & V_474 -> V_29 ;
V_168 -> V_175 = V_176 ;
}
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_475 ;
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
F_39 ( V_376 , & V_31 -> V_43 ) ;
if ( V_471 )
F_65 ( & V_473 ) ;
else
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int
F_164 ( struct V_30 * V_31 )
{
struct V_167 * V_168 ;
int V_34 ;
struct V_26 * V_45 ;
int V_471 ;
if ( ! F_162 ( V_472 ) )
return - V_41 ;
V_471 = 0 ;
V_168 = F_43 ( V_176 , 1 , 32 , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_163 ( & V_473 ) ;
V_471 = 1 ;
V_168 = & V_474 -> V_168 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
memset ( & V_474 -> V_45 , 0 ,
sizeof( V_474 -> V_45 ) ) ;
V_168 -> V_171 = & V_474 -> V_45 ;
V_168 -> V_29 = & V_474 -> V_29 ;
V_168 -> V_175 = V_176 ;
}
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_476 ;
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
F_34 ( V_376 , & V_31 -> V_43 ) ;
if ( V_471 )
F_65 ( & V_473 ) ;
else
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int
F_165 ( struct V_30 * V_31 )
{
struct V_167 * V_168 ;
int V_34 ;
struct V_26 * V_45 ;
int V_471 ;
if ( ! F_162 ( V_472 ) )
return - V_41 ;
V_471 = 0 ;
V_168 = F_43 ( V_176 , 1 , 32 , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_163 ( & V_473 ) ;
V_471 = 1 ;
V_168 = & V_474 -> V_168 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
memset ( & V_474 -> V_45 , 0 ,
sizeof( V_474 -> V_45 ) ) ;
V_168 -> V_171 = & V_474 -> V_45 ;
V_168 -> V_29 = & V_474 -> V_29 ;
V_168 -> V_175 = V_176 ;
}
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_477 ;
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
F_34 ( V_376 , & V_31 -> V_43 ) ;
if ( V_471 )
F_65 ( & V_473 ) ;
else
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int F_166 ( struct V_30 * V_31 ,
void T_9 * V_478 )
{
struct V_167 * V_168 ;
int V_34 ;
struct V_26 * V_45 ;
int V_471 ;
struct V_479 V_480 ;
if ( ! F_162 ( V_472 ) )
return - V_41 ;
if ( F_167 ( & V_480 , V_478 , sizeof( V_480 ) ) )
return - V_481 ;
V_471 = 0 ;
V_168 = F_43 ( V_176 , 1 ,
sizeof( struct V_482 ) , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_163 ( & V_473 ) ;
V_471 = 1 ;
V_168 = & V_474 -> V_168 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
memset ( & V_474 -> V_45 , 0 ,
sizeof( V_474 -> V_45 ) ) ;
V_168 -> V_171 = & V_474 -> V_45 ;
V_168 -> V_29 = & V_474 -> V_29 ;
V_168 -> V_175 = V_176 ;
}
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_483 ;
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
V_168 -> V_170 = V_480 . V_484 ;
V_34 = F_40 ( V_168 ) ;
if ( ! V_34 && V_480 . V_484 && ( V_168 -> V_170 != V_480 . V_484 ) )
V_34 = - V_280 ;
if ( ! V_34 ) {
V_480 . V_29 = * ( (struct V_482 * ) V_168 -> V_29 ) ;
if ( F_168 ( V_478 , & V_480 , sizeof( V_480 ) ) )
V_34 = - V_481 ;
}
if ( V_471 )
F_65 ( & V_473 ) ;
else
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int
F_169 ( struct V_30 * V_31 , void T_9 * V_478 )
{
struct V_242 * V_243 ;
struct V_485 * V_486 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
int V_34 ;
V_168 = F_43 ( V_176 , 1 + 1 ,
( sizeof( struct V_242 ) +
sizeof( struct V_485 ) ) ,
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
V_243 -> V_487 [ 1 ] = 0x01 ;
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_249 ;
V_45 -> V_42 = sizeof( struct V_242 ) ;
V_45 -> V_43 |= V_250 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_243 ;
V_486 = (struct V_485 * ) ( V_243 + 1 ) ;
memset ( V_486 , 0 , sizeof( struct V_485 ) ) ;
V_45 ++ ;
V_45 -> V_54 = V_251 ;
V_45 -> V_42 = sizeof( struct V_485 ) ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_486 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_45 ( V_168 ) ;
if ( V_34 == 0 ) {
V_243 = (struct V_242 * ) V_168 -> V_29 ;
V_486 = (struct V_485 * ) ( V_243 + 1 ) ;
if ( F_168 ( V_478 , V_486 ,
sizeof( struct V_485 ) ) )
V_34 = - V_481 ;
}
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int
F_170 ( struct V_30 * V_31 , void T_9 * V_478 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_488 V_70 = V_33 -> V_70 ;
int V_34 ;
if ( ! F_162 ( V_472 ) )
return - V_41 ;
if ( ! V_478 )
return - V_128 ;
V_34 = 0 ;
if ( F_168 ( V_478 , ( long * ) & V_70 ,
sizeof( struct V_488 ) ) )
V_34 = - V_481 ;
return V_34 ;
}
static int
F_171 ( struct V_30 * V_31 , void T_9 * V_478 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_488 V_70 ;
if ( ! F_162 ( V_472 ) )
return - V_41 ;
if ( ! V_478 )
return - V_128 ;
if ( F_167 ( & V_70 , V_478 , sizeof( struct V_488 ) ) )
return - V_481 ;
V_33 -> V_70 = V_70 ;
F_83 ( & V_31 -> V_2 -> V_82 ,
L_82 ,
V_33 -> V_70 . V_69 , V_33 -> V_70 . V_89 ) ;
return 0 ;
}
static int F_172 ( struct V_30 * V_31 , void T_9 * V_478 )
{
struct V_489 V_480 ;
char * V_490 , * V_491 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
char V_492 , V_493 ;
int V_34 ;
if ( ! F_162 ( V_472 ) && ! F_162 ( V_494 ) )
return - V_41 ;
V_492 = V_493 = 0 ;
V_34 = - V_481 ;
if ( F_167 ( & V_480 , V_478 , sizeof( V_480 ) ) )
goto V_358;
if ( F_173 () ) {
V_34 = - V_128 ;
if ( ( V_480 . V_490 >> 32 ) != 0 )
goto V_358;
if ( ( V_480 . V_491 >> 32 ) != 0 )
goto V_358;
V_480 . V_490 &= 0x7fffffffULL ;
V_480 . V_491 &= 0x7fffffffULL ;
}
V_490 = F_42 ( V_480 . V_495 , V_195 | V_196 ) ;
V_491 = F_42 ( V_480 . V_496 , V_195 | V_196 ) ;
if ( ! V_490 || ! V_491 ) {
V_34 = - V_197 ;
goto V_497;
}
V_34 = - V_481 ;
if ( F_167 ( V_490 ,
( void T_9 * ) ( unsigned long ) V_480 . V_490 ,
V_480 . V_495 ) )
goto V_497;
V_492 = V_490 [ 0 ] ;
V_493 = V_490 [ 1 ] ;
V_168 = F_43 ( V_176 , 2 , 0 , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_18 ( V_7 , V_31 , L_1 ,
L_81 ) ;
V_34 = F_72 ( V_168 ) ;
goto V_497;
}
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_181 = 3 ;
V_168 -> V_179 = 10 * V_180 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_249 ;
V_45 -> V_42 = V_480 . V_495 ;
V_45 -> V_43 |= V_250 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_490 ;
V_45 ++ ;
V_45 -> V_54 = V_251 ;
V_45 -> V_42 = V_480 . V_496 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_491 ;
V_34 = F_45 ( V_168 ) ;
if ( V_34 )
goto V_498;
V_34 = - V_481 ;
if ( F_168 ( ( void T_9 * ) ( unsigned long ) V_480 . V_491 ,
V_491 , V_480 . V_496 ) )
goto V_498;
V_34 = 0 ;
V_498:
F_46 ( V_168 , V_168 -> V_177 ) ;
V_497:
F_47 ( V_491 ) ;
F_47 ( V_490 ) ;
V_358:
F_18 ( V_7 , V_31 ,
L_83 ,
( int ) V_492 , ( int ) V_493 , V_34 ) ;
return V_34 ;
}
static int
F_174 ( struct V_274 * V_178 , unsigned int V_48 , void T_9 * V_478 )
{
struct V_30 * V_31 = V_178 -> V_291 ;
switch ( V_48 ) {
case V_499 :
return F_170 ( V_31 , V_478 ) ;
case V_500 :
return F_171 ( V_31 , V_478 ) ;
case V_501 :
return F_169 ( V_31 , V_478 ) ;
case V_502 :
return F_161 ( V_31 ) ;
case V_503 :
return F_164 ( V_31 ) ;
case V_504 :
return F_165 ( V_31 ) ;
case V_505 :
return F_166 ( V_31 , V_478 ) ;
case V_506 :
return F_172 ( V_31 , V_478 ) ;
default:
return - V_507 ;
}
}
static int
F_175 ( struct V_26 * V_508 , struct V_26 * V_509 , char * V_510 )
{
int V_511 , V_42 ;
char * V_512 ;
V_511 = 0 ;
while ( V_508 <= V_509 ) {
V_511 += sprintf ( V_510 + V_511 , V_513
L_84 ,
V_508 , ( ( int * ) V_508 ) [ 0 ] , ( ( int * ) V_508 ) [ 1 ] ) ;
if ( V_508 -> V_43 & V_406 )
V_512 = ( char * ) * ( ( V_173 * ) ( V_173 ) V_508 -> V_56 ) ;
else
V_512 = ( char * ) ( ( V_173 ) V_508 -> V_56 ) ;
for ( V_42 = 0 ; V_42 < V_508 -> V_42 && V_42 < 32 ; V_42 ++ ) {
if ( V_42 % 8 == 0 ) V_511 += sprintf ( V_510 + V_511 , L_85 ) ;
if ( V_42 % 4 == 0 ) V_511 += sprintf ( V_510 + V_511 , L_85 ) ;
V_511 += sprintf ( V_510 + V_511 , L_11 , V_512 [ V_42 ] ) ;
}
V_511 += sprintf ( V_510 + V_511 , L_86 ) ;
V_508 ++ ;
}
return V_511 ;
}
static void
F_176 ( struct V_30 * V_31 , struct V_315 * V_315 ,
char * V_514 )
{
T_10 * V_311 ;
T_10 * V_515 ;
V_311 = ( T_10 * ) F_93 ( V_315 ) ;
V_515 = ( T_10 * ) & V_315 -> V_368 ;
if ( V_311 ) {
F_18 ( V_516 , V_31 , L_87
L_88 ,
V_514 , * V_515 , * ( ( T_3 * ) ( V_515 + 1 ) ) ,
V_311 [ 0 ] , V_311 [ 1 ] , V_311 [ 2 ] , V_311 [ 3 ] ) ;
} else {
F_18 ( V_516 , V_31 , L_89 ,
V_514 , * V_515 , * ( ( T_3 * ) ( V_515 + 1 ) ) ,
L_90 ) ;
}
}
static void F_177 ( struct V_30 * V_31 ,
struct V_167 * V_380 , struct V_315 * V_315 )
{
char * V_510 ;
struct V_26 * V_517 , * V_518 , * V_519 , * V_508 , * V_509 ;
int V_511 , V_520 , V_521 ;
V_510 = ( char * ) F_178 ( V_240 ) ;
if ( V_510 == NULL ) {
F_18 ( V_7 , V_31 , L_1 ,
L_91 ) ;
return;
}
V_511 = sprintf ( V_510 , V_513
L_92 ,
F_179 ( & V_31 -> V_2 -> V_82 ) ) ;
V_511 += sprintf ( V_510 + V_511 , V_513
L_93
L_94 ,
V_380 , F_180 ( & V_315 -> V_368 ) , F_181 ( & V_315 -> V_368 ) ,
F_182 ( & V_315 -> V_368 ) , F_183 ( & V_315 -> V_368 ) ,
F_126 ( & V_315 -> V_368 ) , F_184 ( & V_315 -> V_368 ) ,
V_380 ? V_380 -> V_257 : 0 ) ;
V_511 += sprintf ( V_510 + V_511 , V_513
L_95 ,
F_179 ( & V_31 -> V_2 -> V_82 ) ,
( void * ) ( V_173 ) V_315 -> V_368 . V_48 . V_522 ) ;
if ( V_315 -> V_523 . V_524 . V_525 . V_526 ) {
for ( V_520 = 0 ; V_520 < 4 ; V_520 ++ ) {
V_511 += sprintf ( V_510 + V_511 , V_513
L_96 ,
( 8 * V_520 ) , ( ( 8 * V_520 ) + 7 ) ) ;
for ( V_521 = 0 ; V_521 < 8 ; V_521 ++ ) {
V_511 += sprintf ( V_510 + V_511 , L_97 ,
V_315 -> V_527 [ 8 * V_520 + V_521 ] ) ;
}
V_511 += sprintf ( V_510 + V_511 , L_86 ) ;
}
if ( V_315 -> V_527 [ 27 ] & V_370 ) {
sprintf ( V_510 + V_511 , V_513
L_98
L_99 ,
V_315 -> V_527 [ 7 ] >> 4 , V_315 -> V_527 [ 7 ] & 0x0f ,
V_315 -> V_527 [ 1 ] & 0x10 ? L_59 : L_100 ) ;
} else {
sprintf ( V_510 + V_511 , V_513
L_101
L_102 ,
V_315 -> V_527 [ 6 ] & 0x0f , V_315 -> V_527 [ 22 ] >> 4 ) ;
}
} else {
sprintf ( V_510 + V_511 , V_513
L_103 ) ;
}
F_185 ( V_528 L_1 , V_510 ) ;
if ( V_380 ) {
V_517 = V_380 -> V_171 ;
for ( V_518 = V_517 ; V_518 -> V_43 & ( V_250 | V_529 ) ; V_518 ++ ) ;
V_509 = F_140 ( V_517 + 6 , V_518 ) ;
V_511 = sprintf ( V_510 , V_513
L_104 , V_380 ) ;
F_175 ( V_517 , V_509 , V_510 + V_511 ) ;
F_185 ( V_528 L_1 , V_510 ) ;
V_511 = 0 ;
V_508 = ++ V_509 ;
V_519 = (struct V_26 * ) ( V_173 )
V_315 -> V_368 . V_48 . V_522 ;
if ( V_508 < V_519 - 2 ) {
V_508 = V_519 - 2 ;
V_511 += sprintf ( V_510 , V_513 L_105 ) ;
}
V_509 = F_140 ( V_519 + 1 , V_518 ) ;
V_511 += F_175 ( V_508 , V_509 , V_510 + V_511 ) ;
V_508 = F_186 ( V_508 , ++ V_509 ) ;
if ( V_508 < V_518 - 1 ) {
V_508 = V_518 - 1 ;
V_511 += sprintf ( V_510 + V_511 , V_513 L_105 ) ;
}
V_511 += F_175 ( V_508 , V_518 , V_510 + V_511 ) ;
if ( V_511 > 0 )
F_185 ( V_528 L_1 , V_510 ) ;
}
F_187 ( ( unsigned long ) V_510 ) ;
}
static void F_188 ( struct V_30 * V_31 ,
struct V_167 * V_380 , struct V_315 * V_315 )
{
char * V_510 ;
int V_511 , V_520 , V_521 , V_530 ;
struct V_531 * V_531 ;
T_7 * V_311 , * V_532 ;
V_510 = ( char * ) F_178 ( V_240 ) ;
if ( V_510 == NULL ) {
F_18 ( V_7 , V_31 , L_106 ,
L_107 ) ;
return;
}
V_511 = sprintf ( V_510 , V_513
L_92 ,
F_179 ( & V_31 -> V_2 -> V_82 ) ) ;
V_511 += sprintf ( V_510 + V_511 , V_513
L_93
L_108 ,
V_380 , F_180 ( & V_315 -> V_368 ) , F_181 ( & V_315 -> V_368 ) ,
F_182 ( & V_315 -> V_368 ) , F_183 ( & V_315 -> V_368 ) ,
F_126 ( & V_315 -> V_368 ) , F_184 ( & V_315 -> V_368 ) ,
V_315 -> V_368 . V_533 . V_534 , V_315 -> V_368 . V_533 . V_535 ,
V_380 ? V_380 -> V_257 : 0 ) ;
V_511 += sprintf ( V_510 + V_511 , V_513
L_109 ,
F_179 ( & V_31 -> V_2 -> V_82 ) ,
( void * ) ( V_173 ) V_315 -> V_368 . V_533 . V_455 ) ;
V_531 = NULL ;
V_311 = NULL ;
if ( V_315 -> V_368 . V_533 . V_455 && ( V_315 -> V_368 . V_533 . V_534 & 0x01 ) )
V_531 = F_189 (
(struct V_455 * ) ( unsigned long ) V_315 -> V_368 . V_533 . V_455 ) ;
if ( V_531 ) {
V_511 += sprintf ( V_510 + V_511 , V_513
L_110 , V_531 -> V_106 ) ;
V_511 += sprintf ( V_510 + V_511 , V_513
L_111 , V_531 -> V_43 ) ;
V_511 += sprintf ( V_510 + V_511 , V_513
L_112 , V_531 -> V_536 ) ;
V_511 += sprintf ( V_510 + V_511 , V_513
L_113 , V_531 -> V_42 ) ;
V_530 = V_531 -> V_42 - 28 ;
V_511 += sprintf ( V_510 + V_511 , V_513
L_114 , V_530 ) ;
switch ( V_531 -> V_43 & 0x07 ) {
case 1 :
V_511 += sprintf ( V_510 + V_511 , V_513
L_115 ,
V_531 -> V_537 . V_538 . V_539 ) ;
V_511 += sprintf ( V_510 + V_511 , V_513
L_116 ,
V_531 -> V_537 . V_538 . V_540 ) ;
V_511 += sprintf ( V_510 + V_511 , V_513
L_117 ,
V_531 -> V_537 . V_538 . V_541 ) ;
V_511 += sprintf ( V_510 + V_511 , V_513
L_118 ,
V_531 -> V_537 . V_538 . V_542 ) ;
V_511 += sprintf ( V_510 + V_511 , V_513
L_119 ,
V_531 -> V_537 . V_538 . V_543 ) ;
V_311 = V_531 -> V_537 . V_538 . V_311 ;
break;
case 2 :
V_511 += sprintf ( V_510 + V_511 , V_513
L_120 , V_531 -> V_537 . V_544 . V_34 ) ;
for ( V_520 = 0 ; V_520 < 2 ; V_520 ++ ) {
V_511 += sprintf ( V_510 + V_511 , V_513
L_121 ,
( 8 * V_520 ) , ( ( 8 * V_520 ) + 7 ) ) ;
V_532 = V_531 -> V_537 . V_544 . V_532 ;
for ( V_521 = 0 ; V_521 < 8 ; V_521 ++ ) {
V_511 += sprintf ( V_510 + V_511 , L_97 ,
V_532 [ 8 * V_520 + V_521 ] ) ;
}
V_511 += sprintf ( V_510 + V_511 , L_86 ) ;
}
V_311 = V_531 -> V_537 . V_544 . V_311 ;
break;
case 3 :
V_511 += sprintf ( V_510 + V_511 , V_513
L_122 ) ;
break;
}
if ( V_311 ) {
for ( V_520 = 0 ; V_520 < 4 ; V_520 ++ ) {
V_511 += sprintf ( V_510 + V_511 , V_513
L_96 ,
( 8 * V_520 ) , ( ( 8 * V_520 ) + 7 ) ) ;
for ( V_521 = 0 ; V_521 < 8 ; V_521 ++ ) {
V_511 += sprintf ( V_510 + V_511 , L_97 ,
V_311 [ 8 * V_520 + V_521 ] ) ;
}
V_511 += sprintf ( V_510 + V_511 , L_86 ) ;
}
if ( V_311 [ 27 ] & V_370 ) {
sprintf ( V_510 + V_511 , V_513
L_98
L_99 ,
V_311 [ 7 ] >> 4 , V_311 [ 7 ] & 0x0f ,
V_311 [ 1 ] & 0x10 ? L_59 : L_100 ) ;
} else {
sprintf ( V_510 + V_511 , V_513
L_101
L_102 ,
V_311 [ 6 ] & 0x0f , V_311 [ 22 ] >> 4 ) ;
}
} else {
sprintf ( V_510 + V_511 , V_513
L_103 ) ;
}
} else {
sprintf ( V_510 + V_511 , V_513
L_123 ) ;
}
F_185 ( V_528 L_1 , V_510 ) ;
F_187 ( ( unsigned long ) V_510 ) ;
}
static void F_190 ( struct V_30 * V_31 ,
struct V_167 * V_380 , struct V_315 * V_315 )
{
if ( F_191 ( & V_315 -> V_368 ) )
F_188 ( V_31 , V_380 , V_315 ) ;
else
F_177 ( V_31 , V_380 , V_315 ) ;
}
static int F_192 ( struct V_30 * V_31 )
{
F_106 ( V_31 ) ;
F_88 ( V_31 ) ;
return 0 ;
}
static int F_193 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_14 V_545 ;
int V_34 ;
struct V_149 V_275 ;
unsigned long V_43 ;
unsigned long V_546 = 0 ;
V_34 = F_51 ( V_31 ) ;
if ( V_34 ) {
F_3 ( V_7 , V_31 -> V_2 ,
L_124 , V_34 ) ;
goto V_359;
}
F_30 ( V_31 , & V_275 ) ;
V_34 = F_26 ( V_31 ) ;
F_27 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
if ( memcmp ( & V_33 -> V_134 , & V_275 , sizeof( struct V_149 ) ) != 0 )
F_15 ( & V_31 -> V_2 -> V_82 , L_125
L_126 ) ;
F_29 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
if ( V_34 )
goto V_359;
V_34 = F_85 ( V_31 ) ;
if ( V_34 )
goto V_359;
F_34 ( V_261 , & V_546 ) ;
F_76 ( V_31 , V_546 ) ;
V_34 = F_51 ( V_31 ) ;
if ( V_34 ) {
F_3 ( V_7 , V_31 -> V_2 ,
L_124 , V_34 ) ;
goto V_292;
}
F_71 ( V_31 ) ;
V_34 = F_86 ( V_31 , V_176 ,
& V_545 , 64 ) ;
if ( V_34 ) {
F_3 ( V_7 , V_31 -> V_2 ,
L_53 , V_34 ) ;
goto V_292;
}
F_27 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
memcpy ( & V_33 -> V_35 , & V_545 , sizeof( V_545 ) ) ;
F_29 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
F_102 ( V_31 ) ;
return 0 ;
V_292:
F_88 ( V_31 ) ;
V_359:
return - 1 ;
}
static int F_194 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
int V_34 , V_547 ;
char V_232 [ 60 ] ;
struct V_149 V_134 ;
unsigned long V_43 ;
F_106 ( V_31 ) ;
F_27 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
V_547 = V_33 -> V_134 . V_161 ;
F_29 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
V_34 = F_51 ( V_31 ) ;
if ( V_34 )
goto V_359;
V_34 = F_26 ( V_31 ) ;
if ( V_34 )
goto V_359;
F_195 ( V_31 ) ;
F_30 ( V_31 , & V_134 ) ;
if ( V_547 != V_134 . V_161 ) {
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
V_359:
return - 1 ;
}
static int F_196 ( struct V_30 * V_31 ,
struct V_548 * V_549 ,
T_2 V_550 )
{
struct V_548 * V_551 ;
struct V_242 * V_243 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
int V_34 ;
V_168 = F_43 ( V_176 , 1 + 1 ,
( sizeof( struct V_242 ) +
sizeof( struct V_548 ) ) ,
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
V_551 = (struct V_548 * ) ( V_243 + 1 ) ;
memset ( V_551 , 0 , sizeof( struct V_548 ) ) ;
V_45 ++ ;
V_45 -> V_54 = V_251 ;
V_45 -> V_42 = sizeof( struct V_548 ) ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_551 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_40 ( V_168 ) ;
if ( V_34 == 0 ) {
V_243 = (struct V_242 * ) V_168 -> V_29 ;
V_551 = (struct V_548 * )
( V_243 + 1 ) ;
memcpy ( V_549 , V_551 ,
sizeof( struct V_548 ) ) ;
} else
F_3 ( V_7 , V_31 -> V_2 ,
L_130
, V_34 ) ;
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int
F_197 ( struct V_30 * V_31 , int V_552 ,
T_1 V_553 ,
struct V_554 * V_555 ,
struct V_556 V_557 )
{
struct V_558 * V_559 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
int V_34 ;
V_168 = F_43 ( V_176 , 1 ,
sizeof( struct V_558 ) ,
V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_18 ( V_7 , V_31 , L_1 ,
L_131 ) ;
return F_72 ( V_168 ) ;
}
V_559 = (struct V_558 * ) V_168 -> V_29 ;
V_559 -> V_246 = V_560 ;
V_559 -> V_561 = V_552 ;
if ( V_555 )
V_559 -> V_562 = V_555 -> V_562 ;
V_559 -> V_553 = V_553 ;
V_559 -> V_563 = V_557 . V_563 ;
V_559 -> V_154 = V_557 . V_154 ;
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_249 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_559 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_42 = sizeof( struct V_558 ) ;
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
static struct V_218 * F_198 ( struct V_30 * V_31 ,
T_2 V_550 ,
struct V_564 * V_565 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_218 * V_201 ;
int V_566 , V_211 ;
if ( V_565 -> V_567 == 0 )
goto V_358;
for ( V_566 = 0x80 , V_211 = 0 ; V_566 ; V_566 >>= 1 , V_211 ++ ) {
V_201 = V_33 -> V_208 [ V_211 ] ;
if ( V_201 -> V_155 . V_567 ==
V_565 -> V_567 )
return V_201 ;
}
V_358:
return V_33 -> V_208 [ F_53 ( V_550 ) ] ;
}
static int F_199 ( struct V_30 * V_31 , T_2 V_550 ,
struct V_564 * V_565 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_218 * V_568 ;
unsigned long V_569 = 0 , V_66 = 0 ;
struct V_218 * V_201 ;
unsigned int V_211 , V_566 ;
char * V_570 , * V_155 ;
char * V_571 , * V_130 ;
int V_572 = 0 ;
if ( ! V_565 -> V_573 ||
! ( V_565 -> V_574 [ 0 ] | V_565 -> V_574 [ 1 ] | V_565 -> V_574 [ 2 ] ) )
return V_550 ;
V_568 = F_198 ( V_31 , V_550 , V_565 ) ;
V_211 = 8 - F_200 ( V_565 -> V_573 ) ;
V_571 = ( char * ) & V_568 -> V_575 [ V_211 ] ;
V_570 = ( char * ) & V_568 -> V_155 ;
V_66 = V_565 -> V_574 [ 2 ] ;
V_66 |= V_565 -> V_574 [ 1 ] << 8 ;
V_66 |= V_565 -> V_574 [ 0 ] << 16 ;
for ( V_566 = 0x80 ; V_566 ; V_566 >>= 1 ) {
V_569 = V_66 ;
V_211 = F_53 ( V_566 ) ;
V_201 = V_33 -> V_208 [ V_211 ] ;
V_211 = 8 - F_200 ( V_565 -> V_573 ) ;
V_130 = ( char * ) & V_201 -> V_575 [ V_211 ] ;
if ( memcmp ( V_571 , V_130 , sizeof( * V_130 ) ) != 0 )
continue;
V_155 = ( char * ) & V_201 -> V_155 ;
while ( V_569 ) {
V_211 = F_200 ( V_569 ) - 1 ;
if ( memcmp ( & V_570 [ 31 - V_211 ] , & V_155 [ 31 - V_211 ] , 1 )
!= 0 )
break;
F_39 ( V_211 , & V_569 ) ;
}
if ( V_569 )
continue;
V_572 |= V_566 ;
}
return V_572 ;
}
static void F_201 ( struct V_30 * V_31 ,
unsigned long V_576 ,
struct V_556 V_557 , int V_577 )
{
struct V_554 * V_555 ;
int V_211 ;
while ( V_576 ) {
V_211 = F_200 ( V_576 ) - 1 ;
V_555 = F_202 ( V_31 -> V_2 , 7 - V_211 ) ;
if ( V_577 == V_578 )
F_203 ( L_132
L_133 , V_557 . V_563 ,
V_555 ? V_555 -> V_562 : 0 ) ;
else if ( V_577 == V_579 )
F_204 ( L_134
L_135 , V_557 . V_563 ,
V_555 ? V_555 -> V_562 : 0 ) ;
F_47 ( V_555 ) ;
F_39 ( V_211 , & V_576 ) ;
}
}
static int F_205 ( struct V_30 * V_31 , T_2 V_550 ,
struct V_564 * V_565 )
{
unsigned long V_572 ;
V_572 = F_199 ( V_31 , V_550 , V_565 ) ;
if ( ! ( V_31 -> V_215 . V_212 & V_572 ) )
return 0 ;
if ( ! ( V_31 -> V_215 . V_212 & ~ V_572 ) ) {
return - V_128 ;
}
V_31 -> V_215 . V_212 &= ~ V_572 ;
V_31 -> V_215 . V_223 |= V_572 ;
return V_572 ;
}
static int F_206 ( struct V_30 * V_31 , T_2 V_550 ,
struct V_556 V_557 ,
struct V_564 * V_565 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_580 * V_581 , * V_582 ;
struct V_30 * V_82 , * V_349 ;
unsigned long V_576 = 0 ;
unsigned long V_43 ;
int V_572 ;
F_118 (dev, n, &private->lcu->active_devices,
alias_list) {
F_27 ( F_28 ( V_82 -> V_2 ) , V_43 ) ;
V_572 = F_205 ( V_82 , V_550 , V_565 ) ;
F_29 ( F_28 ( V_82 -> V_2 ) , V_43 ) ;
if ( V_572 < 0 )
goto V_359;
V_576 |= V_572 ;
}
F_118 (dev, n, &private->lcu->inactive_devices,
alias_list) {
F_27 ( F_28 ( V_82 -> V_2 ) , V_43 ) ;
V_572 = F_205 ( V_82 , V_550 , V_565 ) ;
F_29 ( F_28 ( V_82 -> V_2 ) , V_43 ) ;
if ( V_572 < 0 )
goto V_359;
V_576 |= V_572 ;
}
F_118 (pavgroup, tempgroup,
&private->lcu->grouplist, group) {
F_118 (dev, n, &pavgroup->baselist,
alias_list) {
F_27 ( F_28 ( V_82 -> V_2 ) , V_43 ) ;
V_572 = F_205 ( V_82 , V_550 , V_565 ) ;
F_29 (
F_28 ( V_82 -> V_2 ) , V_43 ) ;
if ( V_572 < 0 )
goto V_359;
V_576 |= V_572 ;
}
F_118 (dev, n, &pavgroup->aliaslist,
alias_list) {
F_27 ( F_28 ( V_82 -> V_2 ) , V_43 ) ;
V_572 = F_205 ( V_82 , V_550 , V_565 ) ;
F_29 (
F_28 ( V_82 -> V_2 ) , V_43 ) ;
if ( V_572 < 0 )
goto V_359;
V_576 |= V_572 ;
}
}
F_201 ( V_31 , V_576 , V_557 , V_578 ) ;
return 0 ;
V_359:
return V_572 ;
}
static int F_207 ( struct V_30 * V_31 , T_2 V_550 ,
struct V_556 V_557 ,
struct V_564 * V_565 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_580 * V_581 , * V_582 ;
struct V_30 * V_82 , * V_349 ;
unsigned long V_576 = 0 ;
int V_572 ;
F_118 (dev, n,
&private->lcu->active_devices,
alias_list) {
V_572 = F_199 ( V_82 , V_550 , V_565 ) ;
V_576 |= V_572 ;
if ( ! ( V_82 -> V_215 . V_212 & V_572 ) ) {
V_82 -> V_215 . V_236 |= V_572 ;
F_208 ( V_82 ) ;
}
}
F_118 (dev, n,
&private->lcu->inactive_devices,
alias_list) {
V_572 = F_199 ( V_82 , V_550 , V_565 ) ;
V_576 |= V_572 ;
if ( ! ( V_82 -> V_215 . V_212 & V_572 ) ) {
V_82 -> V_215 . V_236 |= V_572 ;
F_208 ( V_82 ) ;
}
}
F_118 (pavgroup, tempgroup,
&private->lcu->grouplist,
group) {
F_118 (dev, n,
&pavgroup->baselist,
alias_list) {
V_572 = F_199 ( V_82 , V_550 , V_565 ) ;
V_576 |= V_572 ;
if ( ! ( V_82 -> V_215 . V_212 & V_572 ) ) {
V_82 -> V_215 . V_236 |= V_572 ;
F_208 ( V_82 ) ;
}
}
F_118 (dev, n,
&pavgroup->aliaslist,
alias_list) {
V_572 = F_199 ( V_82 , V_550 , V_565 ) ;
V_576 |= V_572 ;
if ( ! ( V_82 -> V_215 . V_212 & V_572 ) ) {
V_82 -> V_215 . V_236 |= V_572 ;
F_208 ( V_82 ) ;
}
}
}
F_201 ( V_31 , V_576 , V_557 , V_579 ) ;
return 0 ;
}
static void F_209 ( struct V_30 * V_31 , void * V_549 ,
T_2 V_550 )
{
struct V_564 * V_565 = V_549 ;
struct V_554 * V_555 ;
struct V_556 V_557 ;
int V_211 , V_552 ;
F_18 ( V_7 , V_31 ,
L_136 ,
( ( T_10 * ) V_565 ) [ 0 ] , ( ( T_10 * ) V_565 ) [ 1 ] , ( ( T_10 * ) V_565 ) [ 2 ] ,
( ( T_3 * ) V_565 ) [ 3 ] ) ;
F_210 ( V_31 -> V_2 , & V_557 ) ;
V_211 = F_53 ( V_550 ) ;
V_555 = F_202 ( V_31 -> V_2 , V_211 ) ;
if ( V_565 -> V_583 == V_578 ) {
if ( F_206 ( V_31 , V_550 , V_557 , V_565 ) )
V_552 = V_584 ;
else
V_552 = V_585 ;
} else if ( V_565 -> V_583 == V_579 ) {
F_207 ( V_31 , V_550 , V_557 , V_565 ) ;
V_552 = V_585 ;
} else
V_552 = V_586 ;
F_197 ( V_31 , V_552 ,
V_565 -> V_553 , V_555 , V_557 ) ;
F_18 ( V_7 , V_31 ,
L_137 , V_552 ,
V_565 -> V_553 ) ;
F_47 ( V_555 ) ;
V_31 -> V_587 -> V_588 ( V_31 , V_550 ) ;
}
static void F_211 ( struct V_228 * V_229 )
{
struct V_589 * V_29 ;
struct V_548 * V_549 ;
struct V_30 * V_31 ;
int V_34 ;
V_29 = F_60 ( V_229 , struct V_589 , V_233 ) ;
V_31 = V_29 -> V_31 ;
V_549 = F_42 ( sizeof( * V_549 ) , V_195 ) ;
if ( ! V_549 ) {
F_18 ( V_7 , V_31 , L_1 ,
L_138 ) ;
goto V_358;
}
V_34 = F_196 ( V_31 , V_549 , V_29 -> V_550 ) ;
if ( V_34 )
goto V_358;
if ( V_549 -> V_106 == V_590 &&
V_549 -> V_120 == V_591 )
F_209 ( V_31 , V_549 , V_29 -> V_550 ) ;
V_358:
F_64 ( V_31 ) ;
F_47 ( V_549 ) ;
F_47 ( V_29 ) ;
}
static int F_212 ( struct V_30 * V_31 , T_2 V_550 )
{
struct V_589 * V_29 ;
V_29 = F_42 ( sizeof( * V_29 ) , V_240 ) ;
if ( ! V_29 )
return - V_197 ;
F_69 ( & V_29 -> V_233 , F_211 ) ;
F_70 ( V_31 ) ;
V_29 -> V_31 = V_31 ;
V_29 -> V_550 = V_550 ;
F_62 ( & V_29 -> V_233 ) ;
return 0 ;
}
static int T_11
F_213 ( void )
{
int V_3 ;
F_214 ( V_8 . V_592 , 4 ) ;
V_474 = F_67 ( sizeof( * V_474 ) ,
V_195 | V_196 ) ;
if ( ! V_474 )
return - V_197 ;
V_241 = F_67 ( sizeof( * V_241 ) ,
V_195 | V_196 ) ;
if ( ! V_241 ) {
F_47 ( V_474 ) ;
return - V_197 ;
}
V_452 = ( void * ) F_215 ( V_195 ) ;
if ( ! V_452 ) {
F_47 ( V_241 ) ;
F_47 ( V_474 ) ;
return - V_197 ;
}
V_3 = F_216 ( & V_593 ) ;
if ( ! V_3 )
F_217 () ;
else {
F_47 ( V_241 ) ;
F_47 ( V_474 ) ;
F_187 ( ( unsigned long ) V_452 ) ;
}
return V_3 ;
}
static void T_12
F_218 ( void )
{
F_219 ( & V_593 ) ;
F_47 ( V_241 ) ;
F_47 ( V_474 ) ;
F_187 ( ( unsigned long ) V_452 ) ;
}
