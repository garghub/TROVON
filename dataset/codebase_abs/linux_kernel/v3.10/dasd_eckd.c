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
struct V_32 * V_33 ;
int V_34 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
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
struct V_32 * V_33 ;
T_3 V_49 , V_50 ;
T_4 V_51 , V_52 , V_53 ;
int V_34 = 0 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
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
struct V_32 * V_33 ;
int V_34 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
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
struct V_32 * V_33 ;
int V_101 ;
int V_18 , V_102 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
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
V_122 = (struct V_32 * ) V_118 -> V_33 ;
V_123 = (struct V_32 * ) V_119 -> V_33 ;
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
struct V_32 * V_33 ;
int V_101 ;
int V_18 , V_102 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
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
struct V_32 * V_33 ;
unsigned long V_43 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
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
struct V_32 * V_33 ;
unsigned long V_43 ;
if ( V_31 -> V_33 ) {
V_33 = (struct V_32 * ) V_31 -> V_33 ;
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
static int F_50 ( struct V_30 * V_31 )
{
void * V_201 ;
int V_200 , V_208 ;
int V_34 , V_209 ;
T_2 V_170 , V_210 ;
struct V_32 * V_33 , V_211 ;
struct V_212 * V_213 ;
struct V_149 * V_134 ;
char V_214 [ 60 ] , V_215 [ 60 ] ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_213 = & V_31 -> V_213 ;
V_210 = F_51 ( V_31 -> V_2 ) ;
V_208 = 0 ;
V_209 = 0 ;
for ( V_170 = 0x80 ; V_170 ; V_170 >>= 1 ) {
if ( ! ( V_170 & V_210 ) )
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
V_213 -> V_210 |= V_170 ;
continue;
}
if ( ! V_208 ) {
F_47 ( V_33 -> V_201 ) ;
V_33 -> V_201 = V_201 ;
V_33 -> V_200 = V_200 ;
if ( F_48 ( V_33 ) ) {
V_33 -> V_201 = NULL ;
V_33 -> V_200 = 0 ;
F_47 ( V_201 ) ;
continue;
}
F_26 ( V_31 ) ;
V_208 ++ ;
} else {
V_211 . V_201 = V_201 ;
V_211 . V_200 = V_174 ;
if ( F_48 (
& V_211 ) ) {
V_211 . V_201 = NULL ;
V_211 . V_200 = 0 ;
F_47 ( V_201 ) ;
continue;
}
if ( F_31 (
V_31 , & V_211 ) ) {
V_134 = & V_211 . V_134 ;
if ( strlen ( V_134 -> V_163 ) > 0 )
snprintf ( V_214 ,
sizeof( V_214 ) ,
L_17 ,
V_134 -> V_150 , V_134 -> V_152 ,
V_134 -> V_154 , V_134 -> V_157 ,
V_134 -> V_163 ) ;
else
snprintf ( V_214 ,
sizeof( V_214 ) ,
L_18 ,
V_134 -> V_150 , V_134 -> V_152 ,
V_134 -> V_154 ,
V_134 -> V_157 ) ;
V_134 = & V_33 -> V_134 ;
if ( strlen ( V_134 -> V_163 ) > 0 )
snprintf ( V_215 ,
sizeof( V_215 ) ,
L_17 ,
V_134 -> V_150 , V_134 -> V_152 ,
V_134 -> V_154 , V_134 -> V_157 ,
V_134 -> V_163 ) ;
else
snprintf ( V_215 ,
sizeof( V_215 ) ,
L_18 ,
V_134 -> V_150 , V_134 -> V_152 ,
V_134 -> V_154 ,
V_134 -> V_157 ) ;
F_15 ( & V_31 -> V_2 -> V_82 ,
L_19
L_20
L_21 , V_170 ,
V_214 , V_215 ) ;
V_209 = - V_128 ;
continue;
}
V_211 . V_201 = NULL ;
V_211 . V_200 = 0 ;
}
switch ( F_49 ( V_201 , V_200 ) ) {
case 0x02 :
V_213 -> V_216 |= V_170 ;
break;
case 0x03 :
V_213 -> V_217 |= V_170 ;
break;
}
V_213 -> V_210 |= V_170 ;
if ( V_201 != V_33 -> V_201 )
F_47 ( V_201 ) ;
}
return V_209 ;
}
static int F_52 ( struct V_30 * V_31 , T_2 V_170 )
{
struct V_32 * V_33 ;
int V_218 ;
T_3 V_219 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
if ( V_33 -> V_219 ) {
V_218 = F_53 ( V_31 -> V_2 , V_170 ) ;
if ( ( V_218 < 0 ) ) {
F_54 ( & V_31 -> V_2 -> V_82 ,
L_22
L_23 ,
V_218 , V_170 ) ;
return V_218 ;
}
V_219 = V_218 * V_220 ;
if ( V_219 < V_33 -> V_219 ) {
F_54 ( & V_31 -> V_2 -> V_82 ,
L_24
L_25
L_26 , V_219 , V_170 ,
V_33 -> V_219 ) ;
return - V_41 ;
}
}
return 0 ;
}
static int F_55 ( struct V_30 * V_31 ,
struct V_221 * V_29 )
{
struct V_32 * V_33 ;
struct V_212 * V_213 ;
T_2 V_170 , V_210 ;
int V_34 ;
V_34 = - V_165 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_213 = & V_31 -> V_213 ;
V_210 = V_31 -> V_213 . V_210 ;
for ( V_170 = 0x80 ; V_170 ; V_170 >>= 1 ) {
if ( ! ( V_170 & V_210 ) )
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
static void F_56 ( struct V_222 * V_223 )
{
struct V_221 * V_29 ;
struct V_30 * V_31 ;
struct V_32 V_211 ;
struct V_149 * V_134 ;
T_2 V_224 [ V_174 ] ;
T_2 V_170 , V_210 , V_216 , V_217 , V_225 ;
unsigned long V_43 ;
char V_226 [ 60 ] ;
int V_34 ;
V_29 = F_57 ( V_223 , struct V_221 , V_227 ) ;
V_31 = V_29 -> V_31 ;
if ( F_58 ( V_228 , & V_31 -> V_43 ) ) {
F_59 ( V_223 ) ;
return;
}
V_210 = 0 ;
V_216 = 0 ;
V_217 = 0 ;
V_225 = 0 ;
for ( V_170 = 0x80 ; V_170 ; V_170 >>= 1 ) {
if ( ! ( V_170 & V_29 -> V_229 ) )
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
V_216 |= V_170 ;
break;
case 0x03 :
V_217 |= V_170 ;
break;
}
V_210 |= V_170 ;
} else if ( V_34 == - V_40 ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_29
L_30 ) ;
V_210 |= V_170 ;
} else if ( V_34 == - V_230 ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_31
L_32 ) ;
V_225 |= V_170 ;
} else {
F_54 ( & V_31 -> V_2 -> V_82 ,
L_33
L_34 , V_34 , V_170 ) ;
continue;
}
if ( F_52 ( V_31 , V_170 ) ) {
V_210 &= ~ V_170 ;
V_216 &= ~ V_170 ;
V_217 &= ~ V_170 ;
continue;
}
memcpy ( & V_224 , V_29 -> V_169 ,
V_174 ) ;
V_211 . V_201 = ( void * ) & V_224 ;
V_211 . V_200 = V_174 ;
if ( F_48 ( & V_211 ) ) {
V_211 . V_201 = NULL ;
V_211 . V_200 = 0 ;
continue;
}
if ( V_31 -> V_213 . V_210 &&
F_31 ( V_31 , & V_211 ) ) {
if ( F_55 ( V_31 , V_29 ) ||
F_31 (
V_31 , & V_211 ) ) {
V_134 = & V_211 . V_134 ;
if ( strlen ( V_134 -> V_163 ) > 0 )
snprintf ( V_226 , sizeof( V_226 ) ,
L_17 ,
V_134 -> V_150 , V_134 -> V_152 ,
V_134 -> V_154 , V_134 -> V_157 ,
V_134 -> V_163 ) ;
else
snprintf ( V_226 , sizeof( V_226 ) ,
L_18 ,
V_134 -> V_150 , V_134 -> V_152 ,
V_134 -> V_154 ,
V_134 -> V_157 ) ;
F_15 ( & V_31 -> V_2 -> V_82 ,
L_35
L_36
L_37 ,
V_170 , V_226 ) ;
V_210 &= ~ V_170 ;
V_216 &= ~ V_170 ;
V_217 &= ~ V_170 ;
continue;
}
}
F_27 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
if ( ! V_31 -> V_213 . V_210 && V_210 ) {
V_31 -> V_213 . V_210 = V_210 ;
F_60 ( V_31 ) ;
} else
V_31 -> V_213 . V_210 |= V_210 ;
V_31 -> V_213 . V_216 |= V_216 ;
V_31 -> V_213 . V_217 |= V_217 ;
V_31 -> V_213 . V_229 |= V_225 ;
F_29 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
}
F_61 ( V_31 ) ;
if ( V_29 -> V_231 )
F_62 ( & V_232 ) ;
else
F_47 ( V_29 ) ;
}
static int F_63 ( struct V_30 * V_31 , T_2 V_170 )
{
struct V_221 * V_29 ;
V_29 = F_64 ( sizeof( * V_29 ) , V_233 | V_196 ) ;
if ( ! V_29 ) {
if ( F_65 ( & V_232 ) ) {
V_29 = V_234 ;
V_29 -> V_231 = 1 ;
} else
return - V_197 ;
} else {
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_29 -> V_231 = 0 ;
}
F_66 ( & V_29 -> V_227 , F_56 ) ;
F_67 ( V_31 ) ;
V_29 -> V_31 = V_31 ;
V_29 -> V_229 = V_170 ;
F_59 ( & V_29 -> V_227 ) ;
return 0 ;
}
static int F_68 ( struct V_30 * V_31 )
{
struct V_235 * V_236 ;
struct V_237 * V_238 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
int V_34 ;
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
memset ( & V_33 -> V_238 , 0 , sizeof( struct V_237 ) ) ;
V_168 = F_43 ( V_176 , 1 + 1 ,
( sizeof( struct V_235 ) +
sizeof( struct V_237 ) ) ,
V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 , L_38
L_39 ) ;
return F_69 ( V_168 ) ;
}
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_178 = NULL ;
V_168 -> V_181 = 256 ;
V_168 -> V_179 = 10 * V_180 ;
V_236 = (struct V_235 * ) V_168 -> V_29 ;
memset ( V_236 , 0 , sizeof( struct V_235 ) ) ;
V_236 -> V_239 = V_240 ;
V_236 -> V_241 = 0x41 ;
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_242 ;
V_45 -> V_42 = sizeof( struct V_235 ) ;
V_45 -> V_43 |= V_243 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_236 ;
V_238 = (struct V_237 * ) ( V_236 + 1 ) ;
memset ( V_238 , 0 , sizeof( struct V_237 ) ) ;
V_45 ++ ;
V_45 -> V_54 = V_244 ;
V_45 -> V_42 = sizeof( struct V_237 ) ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_238 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_45 ( V_168 ) ;
if ( V_34 == 0 ) {
V_236 = (struct V_235 * ) V_168 -> V_29 ;
V_238 = (struct V_237 * ) ( V_236 + 1 ) ;
memcpy ( & V_33 -> V_238 , V_238 ,
sizeof( struct V_237 ) ) ;
} else
F_54 ( & V_31 -> V_2 -> V_82 , L_40
L_41 , V_34 ) ;
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static struct V_167 * F_70 ( struct V_30 * V_31 ,
int V_245 )
{
struct V_167 * V_168 ;
struct V_246 * V_247 ;
struct V_26 * V_45 ;
V_168 = F_43 ( V_176 , 1 ,
sizeof( struct V_246 ) ,
V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_18 ( V_7 , V_31 , L_1 ,
L_42 ) ;
return V_168 ;
}
V_247 = (struct V_246 * ) V_168 -> V_29 ;
V_247 -> V_239 = V_248 ;
V_247 -> V_241 = 0xc0 ;
if ( V_245 ) {
V_247 -> V_241 |= 0x08 ;
V_247 -> V_249 [ 0 ] = 0x88 ;
}
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_242 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_247 ;
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
F_71 ( struct V_30 * V_31 , int V_245 ,
unsigned long V_43 )
{
struct V_167 * V_168 ;
int V_34 ;
V_168 = F_70 ( V_31 , V_245 ) ;
if ( F_44 ( V_168 ) )
return F_69 ( V_168 ) ;
V_168 -> V_43 |= V_43 ;
V_34 = F_45 ( V_168 ) ;
if ( ! V_34 )
F_72 () ;
else if ( V_168 -> V_250 == - V_230 )
V_34 = - V_230 ;
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int F_73 ( struct V_30 * V_31 ,
unsigned long V_43 )
{
int V_34 ;
struct V_32 * V_33 ;
int V_245 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
if ( V_33 -> V_134 . type == V_160 ||
V_33 -> V_134 . type == V_137 )
return 0 ;
if ( V_251 || V_252 )
V_245 = 0 ;
else
V_245 = 1 ;
V_34 = F_71 ( V_31 , V_245 , V_43 ) ;
F_3 ( V_7 , V_31 -> V_2 , L_43
L_44 , V_33 -> V_134 . V_154 , V_34 ) ;
return V_34 ;
}
static void F_74 ( struct V_222 * V_223 )
{
struct V_30 * V_31 = F_57 ( V_223 , struct V_30 ,
V_253 ) ;
unsigned long V_43 = 0 ;
F_34 ( V_254 , & V_43 ) ;
if ( F_73 ( V_31 , V_43 )
== - V_230 ) {
F_59 ( & V_31 -> V_253 ) ;
return;
}
F_61 ( V_31 ) ;
}
static void F_75 ( struct V_30 * V_31 )
{
F_67 ( V_31 ) ;
if ( F_58 ( V_255 , & V_31 -> V_43 ) ||
V_31 -> V_256 < V_257 ) {
F_61 ( V_31 ) ;
return;
}
F_59 ( & V_31 -> V_253 ) ;
}
static T_3 F_76 ( struct V_30 * V_31 )
{
#if F_77 ( V_258 )
int V_259 , V_218 ;
int V_260 , V_261 , V_262 ;
struct V_32 * V_33 ;
if ( V_263 )
return 0 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_260 = V_264 . V_265 ;
V_261 = V_33 -> V_155 -> V_266 [ 7 ] & 0x04 ;
V_262 = V_33 -> V_238 . V_267 [ 40 ] & 0x80 ;
V_259 = V_260 && V_261 && V_262 ;
if ( ! V_259 )
return 0 ;
V_218 = F_53 ( V_31 -> V_2 , 0 ) ;
if ( V_218 < 0 ) {
F_54 ( & V_31 -> V_2 -> V_82 , L_45
L_46 ) ;
return 0 ;
} else
return V_218 * V_220 ;
#else
return 0 ;
#endif
}
static int
F_78 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
struct V_268 * V_178 ;
struct V_149 V_269 ;
int V_34 , V_199 ;
int V_270 ;
unsigned long V_271 ;
F_66 ( & V_31 -> V_253 , F_74 ) ;
if ( ! F_79 ( V_31 -> V_2 ) ) {
F_54 ( & V_31 -> V_2 -> V_82 ,
L_47 ) ;
return - V_272 ;
}
if ( ! F_80 ( V_31 -> V_2 ) ) {
F_81 ( & V_31 -> V_2 -> V_82 ,
L_48 ) ;
}
V_33 = (struct V_32 * ) V_31 -> V_33 ;
if ( ! V_33 ) {
V_33 = F_42 ( sizeof( * V_33 ) , V_195 | V_196 ) ;
if ( ! V_33 ) {
F_54 ( & V_31 -> V_2 -> V_82 ,
L_49
L_50 ) ;
return - V_197 ;
}
V_31 -> V_33 = ( void * ) V_33 ;
} else {
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
}
V_33 -> V_273 = - 1 ;
V_33 -> V_70 . V_69 = V_274 ;
V_33 -> V_70 . V_89 = 0 ;
V_34 = F_50 ( V_31 ) ;
if ( V_34 )
goto V_275;
V_31 -> V_276 = V_277 ;
if ( V_33 -> V_155 ) {
V_271 = 1 ;
for ( V_199 = 0 ; V_199 < V_33 -> V_155 -> V_278 . V_271 ; V_199 ++ )
V_271 = 10 * V_271 ;
V_271 = V_271 * V_33 -> V_155 -> V_278 . V_279 ;
if ( V_271 != 0 && V_271 <= V_280 )
V_31 -> V_276 = V_271 ;
}
F_30 ( V_31 , & V_269 ) ;
if ( V_269 . type == V_135 ) {
V_178 = F_82 () ;
if ( F_44 ( V_178 ) ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_51
L_52 ) ;
V_34 = F_69 ( V_178 ) ;
goto V_275;
}
V_31 -> V_178 = V_178 ;
V_178 -> V_281 = V_31 ;
}
V_34 = F_83 ( V_31 ) ;
if ( V_34 )
goto V_282;
F_73 ( V_31 , 0 ) ;
V_34 = F_50 ( V_31 ) ;
if ( V_34 )
goto V_283;
F_68 ( V_31 ) ;
V_34 = F_84 ( V_31 , V_176 ,
& V_33 -> V_35 , 64 ) ;
if ( V_34 ) {
F_3 ( V_7 , V_31 -> V_2 ,
L_53 , V_34 ) ;
goto V_283;
}
if ( ( V_31 -> V_238 & V_284 ) &&
! ( V_33 -> V_35 . V_36 . V_285 ) ) {
F_15 ( & V_31 -> V_2 -> V_82 , L_54
L_55 ) ;
V_34 = - V_128 ;
goto V_283;
}
if ( V_33 -> V_35 . V_286 == V_287 &&
V_33 -> V_35 . V_288 )
V_33 -> V_90 = V_33 -> V_35 . V_288 ;
else
V_33 -> V_90 = V_33 -> V_35 . V_286 ;
V_33 -> V_219 = F_76 ( V_31 ) ;
V_270 = F_85 ( V_31 ) ;
if ( V_270 )
F_34 ( V_289 , & V_31 -> V_43 ) ;
F_81 ( & V_31 -> V_2 -> V_82 , L_56
L_57 ,
V_33 -> V_35 . V_20 ,
V_33 -> V_35 . V_290 ,
V_33 -> V_35 . V_84 ,
V_33 -> V_35 . V_291 . V_292 ,
V_33 -> V_90 ,
V_33 -> V_35 . V_86 ,
V_33 -> V_35 . V_293 ,
V_270 ? L_58 : L_59 ) ;
return 0 ;
V_283:
F_86 ( V_31 ) ;
V_282:
F_87 ( V_31 -> V_178 ) ;
V_31 -> V_178 = NULL ;
V_275:
F_47 ( V_33 -> V_201 ) ;
F_47 ( V_31 -> V_33 ) ;
V_31 -> V_33 = NULL ;
return V_34 ;
}
static void F_88 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
F_86 ( V_31 ) ;
V_33 -> V_130 = NULL ;
V_33 -> V_158 = NULL ;
V_33 -> V_162 = NULL ;
V_33 -> V_155 = NULL ;
V_33 -> V_200 = 0 ;
F_47 ( V_33 -> V_201 ) ;
V_33 -> V_201 = NULL ;
}
static struct V_167 *
F_89 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
struct V_294 * V_295 ;
struct V_140 * V_296 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
int V_297 , V_298 ;
int V_199 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_297 = 8 ;
V_298 = sizeof( struct V_28 ) + 2 * sizeof( struct V_140 ) ;
V_168 = F_43 ( V_176 , V_297 , V_298 , V_31 ) ;
if ( F_44 ( V_168 ) )
return V_168 ;
V_45 = V_168 -> V_171 ;
F_13 ( V_45 ++ , V_168 -> V_29 , 0 , 2 ,
V_65 , V_31 ) ;
V_296 = V_168 -> V_29 + sizeof( struct V_28 ) ;
V_45 [ - 1 ] . V_43 |= V_243 ;
V_126 ( V_45 ++ , V_296 ++ , 0 , 0 , 4 ,
V_65 , V_31 , 0 ) ;
V_295 = V_33 -> V_299 ;
for ( V_199 = 0 ; V_199 < 4 ; V_199 ++ ) {
V_45 [ - 1 ] . V_43 |= V_243 ;
V_45 -> V_54 = V_65 ;
V_45 -> V_43 = 0 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_295 ;
V_45 ++ ;
V_295 ++ ;
}
V_45 [ - 1 ] . V_43 |= V_243 ;
V_126 ( V_45 ++ , V_296 ++ , 2 , 0 , 1 ,
V_65 , V_31 , 0 ) ;
V_45 [ - 1 ] . V_43 |= V_243 ;
V_45 -> V_54 = V_65 ;
V_45 -> V_43 = 0 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_295 ;
V_168 -> V_178 = NULL ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_181 = 255 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
return V_168 ;
}
static int F_90 ( struct V_167 * V_300 )
{
char * V_301 ;
if ( V_300 -> V_183 == V_186 )
return V_302 ;
else if ( V_300 -> V_183 == V_303 ||
V_300 -> V_183 == V_304 ) {
V_301 = F_91 ( & V_300 -> V_305 ) ;
if ( V_301 && ( V_301 [ 1 ] & V_306 ) )
return V_307 ;
else
return V_308 ;
} else
return V_308 ;
}
static void F_92 ( struct V_167 * V_300 ,
void * V_29 )
{
struct V_32 * V_33 ;
struct V_30 * V_31 ;
V_31 = V_300 -> V_119 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_33 -> V_273 = F_90 ( V_300 ) ;
F_46 ( V_300 , V_31 ) ;
F_93 ( V_31 ) ;
}
static int F_94 ( struct V_268 * V_178 )
{
struct V_167 * V_300 ;
V_300 = F_89 ( V_178 -> V_281 ) ;
if ( F_44 ( V_300 ) )
return F_69 ( V_300 ) ;
V_300 -> V_191 = F_92 ;
V_300 -> V_309 = NULL ;
V_300 -> V_179 = 5 * V_180 ;
F_39 ( V_189 , & V_300 -> V_43 ) ;
V_300 -> V_181 = 0 ;
F_95 ( V_300 ) ;
return - V_230 ;
}
static int F_96 ( struct V_268 * V_178 )
{
struct V_30 * V_31 ;
struct V_32 * V_33 ;
struct V_294 * V_299 ;
unsigned int V_310 , V_145 ;
int V_183 , V_199 ;
struct V_167 * V_300 ;
V_31 = V_178 -> V_281 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_183 = V_33 -> V_273 ;
V_33 -> V_273 = - 1 ;
if ( V_183 == V_308 ) {
V_300 = F_89 ( V_31 ) ;
F_45 ( V_300 ) ;
V_183 = F_90 ( V_300 ) ;
F_46 ( V_300 , V_31 ) ;
}
if ( V_31 -> V_238 & V_284 ) {
V_178 -> V_311 = V_312 ;
V_145 = V_313 ;
V_178 -> V_314 = 3 ;
goto V_315;
}
if ( V_183 == V_307 ) {
F_54 ( & V_31 -> V_2 -> V_82 , L_60 ) ;
return - V_316 ;
} else if ( V_183 == V_308 ) {
F_15 ( & V_31 -> V_2 -> V_82 ,
L_61
L_62 ) ;
return - V_272 ;
}
V_33 -> V_85 = 1 ;
V_299 = NULL ;
for ( V_199 = 0 ; V_199 < 3 ; V_199 ++ ) {
if ( V_33 -> V_299 [ V_199 ] . V_16 != 4 ||
V_33 -> V_299 [ V_199 ] . V_17 != F_23 ( V_199 ) - 4 ||
V_33 -> V_299 [ V_199 ] . V_23 != 0 ||
V_33 -> V_299 [ V_199 ] . V_24 != V_317 [ V_199 ] ||
V_33 -> V_299 [ V_199 ] . V_117 != V_318 [ V_199 ] ) {
V_33 -> V_85 = 0 ;
break;
}
}
if ( V_199 == 3 )
V_299 = & V_33 -> V_299 [ 4 ] ;
if ( V_33 -> V_85 == 0 ) {
for ( V_199 = 0 ; V_199 < 5 ; V_199 ++ ) {
if ( ( V_33 -> V_299 [ V_199 ] . V_16 != 0 ) ||
( V_33 -> V_299 [ V_199 ] . V_17 !=
V_33 -> V_299 [ 0 ] . V_17 ) ||
V_33 -> V_299 [ V_199 ] . V_23 != 0 ||
V_33 -> V_299 [ V_199 ] . V_24 != V_317 [ V_199 ] ||
V_33 -> V_299 [ V_199 ] . V_117 != V_318 [ V_199 ] )
break;
}
if ( V_199 == 5 )
V_299 = & V_33 -> V_299 [ 0 ] ;
} else {
if ( V_33 -> V_299 [ 3 ] . V_117 == 1 )
F_54 ( & V_31 -> V_2 -> V_82 ,
L_63 ) ;
}
if ( V_299 != NULL && V_299 -> V_16 == 0 ) {
if ( F_97 ( V_299 -> V_17 ) == 0 )
V_178 -> V_311 = V_299 -> V_17 ;
}
if ( V_178 -> V_311 == 0 ) {
F_54 ( & V_31 -> V_2 -> V_82 ,
L_64 ) ;
return - V_316 ;
}
V_178 -> V_314 = 0 ;
for ( V_310 = 512 ; V_310 < V_178 -> V_311 ; V_310 = V_310 << 1 )
V_178 -> V_314 ++ ;
V_145 = F_9 ( & V_33 -> V_35 , 0 , V_178 -> V_311 ) ;
V_315:
V_178 -> V_319 = ( V_33 -> V_90 *
V_33 -> V_35 . V_86 *
V_145 ) ;
F_81 ( & V_31 -> V_2 -> V_82 ,
L_65
L_66 , ( V_178 -> V_311 >> 10 ) ,
( ( V_33 -> V_90 *
V_33 -> V_35 . V_86 *
V_145 * ( V_178 -> V_311 >> 9 ) ) >> 1 ) ,
( ( V_145 * V_178 -> V_311 ) >> 10 ) ,
V_33 -> V_85 ?
L_67 : L_68 ) ;
return 0 ;
}
static int F_98 ( struct V_268 * V_178 )
{
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_178 -> V_281 -> V_33 ;
if ( V_33 -> V_273 < 0 )
return F_94 ( V_178 ) ;
else
return F_96 ( V_178 ) ;
}
static int F_99 ( struct V_30 * V_31 )
{
return F_100 ( V_31 ) ;
}
static int F_101 ( struct V_30 * V_31 )
{
F_102 ( & V_31 -> V_320 ) ;
F_102 ( & V_31 -> V_253 ) ;
return 0 ;
}
static int F_103 ( struct V_30 * V_31 )
{
return F_104 ( V_31 ) ;
}
static int
F_105 ( struct V_268 * V_178 , struct V_321 * V_22 )
{
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_178 -> V_281 -> V_33 ;
if ( F_97 ( V_178 -> V_311 ) == 0 ) {
V_22 -> V_322 = F_9 ( & V_33 -> V_35 ,
0 , V_178 -> V_311 ) ;
}
V_22 -> V_323 = V_33 -> V_35 . V_286 ;
V_22 -> V_51 = V_33 -> V_35 . V_86 ;
return 0 ;
}
static struct V_167 *
F_106 ( struct V_30 * V_281 ,
struct V_324 * V_325 )
{
struct V_32 * V_326 ;
struct V_32 * V_327 ;
struct V_30 * V_119 ;
struct V_167 * V_328 ;
struct V_294 * V_329 ;
struct V_21 V_330 ;
struct V_26 * V_45 ;
void * V_29 ;
int V_331 ;
int V_297 , V_298 ;
int V_199 , V_332 ;
int V_333 = 0 ;
int V_334 ;
int V_335 ;
V_119 = F_107 ( V_281 ) ;
if ( ! V_119 )
V_119 = V_281 ;
V_327 = (struct V_32 * ) V_119 -> V_33 ;
V_326 = (struct V_32 * ) V_281 -> V_33 ;
V_331 = F_9 ( & V_326 -> V_35 , 0 , V_325 -> V_121 ) ;
V_335 = V_325 -> V_336 - V_325 -> V_337 + 1 ;
if ( V_325 -> V_333 & 0x10 ) {
V_334 = 0 ;
V_333 = V_325 -> V_333 & ~ 0x10 ;
} else {
V_334 = 1 ;
V_333 = V_325 -> V_333 ;
}
switch ( V_333 ) {
case 0x00 :
case 0x08 :
V_297 = 2 + ( V_331 * V_335 ) ;
V_298 = sizeof( struct V_93 ) +
sizeof( struct V_140 ) +
V_331 * V_335 * sizeof( struct V_294 ) ;
break;
case 0x01 :
case 0x09 :
V_297 = 2 + V_331 * V_335 ;
V_298 = sizeof( struct V_93 ) +
sizeof( struct V_140 ) +
sizeof( struct V_294 ) +
V_331 * V_335 * sizeof( struct V_294 ) ;
break;
case 0x04 :
case 0x0c :
V_297 = 3 ;
V_298 = sizeof( struct V_93 ) +
sizeof( struct V_140 ) +
sizeof( struct V_294 ) ;
break;
default:
F_54 ( & V_119 -> V_2 -> V_82 ,
L_69 ,
V_325 -> V_333 ) ;
return F_108 ( - V_128 ) ;
}
V_328 = F_43 ( V_176 , V_297 ,
V_298 , V_119 ) ;
if ( F_44 ( V_328 ) )
return V_328 ;
V_327 -> V_42 ++ ;
V_29 = V_328 -> V_29 ;
V_45 = V_328 -> V_171 ;
switch ( V_333 & ~ 0x08 ) {
case 0x00 :
F_21 ( V_45 ++ , (struct V_93 * ) V_29 ,
V_325 -> V_337 , V_325 -> V_336 ,
V_75 , V_281 , V_119 ) ;
if ( V_334 )
( (struct V_93 * ) V_29 )
-> F_13 . V_38 |= 0x04 ;
V_29 += sizeof( struct V_93 ) ;
V_45 [ - 1 ] . V_43 |= V_243 ;
V_126 ( V_45 ++ , (struct V_140 * ) V_29 ,
V_325 -> V_337 , 0 , V_331 * V_335 ,
V_75 , V_281 ,
V_325 -> V_121 ) ;
V_29 += sizeof( struct V_140 ) ;
break;
case 0x01 :
F_21 ( V_45 ++ , (struct V_93 * ) V_29 ,
V_325 -> V_337 , V_325 -> V_336 ,
V_80 ,
V_281 , V_119 ) ;
V_29 += sizeof( struct V_93 ) ;
V_45 [ - 1 ] . V_43 |= V_243 ;
V_126 ( V_45 ++ , (struct V_140 * ) V_29 ,
V_325 -> V_337 , 0 , V_331 * V_335 + 1 ,
V_80 , V_281 ,
V_281 -> V_178 -> V_311 ) ;
V_29 += sizeof( struct V_140 ) ;
break;
case 0x04 :
F_21 ( V_45 ++ , (struct V_93 * ) V_29 ,
V_325 -> V_337 , V_325 -> V_336 ,
V_75 , V_281 , V_119 ) ;
V_29 += sizeof( struct V_93 ) ;
V_45 [ - 1 ] . V_43 |= V_243 ;
V_126 ( V_45 ++ , (struct V_140 * ) V_29 ,
V_325 -> V_337 , 0 , 1 ,
V_75 , V_281 , 8 ) ;
V_29 += sizeof( struct V_140 ) ;
break;
}
for ( V_332 = 0 ; V_332 < V_335 ; V_332 ++ ) {
F_10 ( & V_330 ,
( V_325 -> V_337 + V_332 ) /
V_326 -> V_35 . V_86 ,
( V_325 -> V_337 + V_332 ) %
V_326 -> V_35 . V_86 ) ;
if ( V_333 & 0x01 ) {
V_329 = (struct V_294 * ) V_29 ;
V_29 += sizeof( struct V_294 ) ;
V_329 -> V_23 = V_330 . V_23 ;
V_329 -> V_24 = V_330 . V_24 ;
V_329 -> V_117 = 0 ;
V_329 -> V_16 = 0 ;
V_329 -> V_17 = 8 ;
V_45 [ - 1 ] . V_43 |= V_243 ;
V_45 -> V_54 = V_80 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_329 ;
V_45 ++ ;
}
if ( ( V_333 & ~ 0x08 ) & 0x04 ) {
V_329 = (struct V_294 * ) V_29 ;
V_29 += sizeof( struct V_294 ) ;
V_329 -> V_23 = V_330 . V_23 ;
V_329 -> V_24 = V_330 . V_24 ;
V_329 -> V_117 = 1 ;
V_329 -> V_16 = 0 ;
V_329 -> V_17 = 0 ;
V_45 [ - 1 ] . V_43 |= V_243 ;
V_45 -> V_54 = V_75 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_329 ;
} else {
for ( V_199 = 0 ; V_199 < V_331 ; V_199 ++ ) {
V_329 = (struct V_294 * ) V_29 ;
V_29 += sizeof( struct V_294 ) ;
V_329 -> V_23 = V_330 . V_23 ;
V_329 -> V_24 = V_330 . V_24 ;
V_329 -> V_117 = V_199 + 1 ;
V_329 -> V_16 = 0 ;
V_329 -> V_17 = V_325 -> V_121 ;
if ( ( V_333 & 0x08 ) &&
V_325 -> V_337 == 0 ) {
if ( V_199 < 3 ) {
V_329 -> V_16 = 4 ;
V_329 -> V_17 = V_147 [ V_199 ] - 4 ;
}
}
if ( ( V_333 & 0x08 ) &&
V_325 -> V_337 == 1 ) {
V_329 -> V_16 = 44 ;
V_329 -> V_17 = V_148 - 44 ;
}
V_45 [ - 1 ] . V_43 |= V_243 ;
if ( V_199 != 0 || V_332 == 0 )
V_45 -> V_54 =
V_75 ;
else
V_45 -> V_54 =
V_76 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_329 ;
V_45 ++ ;
}
}
}
V_328 -> V_119 = V_119 ;
V_328 -> V_177 = V_119 ;
V_328 -> V_181 = 256 ;
V_328 -> V_179 = V_119 -> V_276 * V_180 ;
V_328 -> V_182 = F_33 () ;
V_328 -> V_183 = V_184 ;
return V_328 ;
}
static int
F_109 ( struct V_30 * V_281 ,
struct V_324 * V_325 )
{
struct V_167 * V_168 , * V_338 ;
struct V_268 * V_178 ;
struct V_32 * V_33 ;
struct V_339 V_340 ;
struct V_30 * V_31 ;
int V_341 , V_342 ;
int V_343 , V_34 = 0 ;
V_178 = V_281 -> V_178 ;
V_33 = (struct V_32 * ) V_281 -> V_33 ;
if ( V_325 -> V_337 >=
( V_33 -> V_90 * V_33 -> V_35 . V_86 ) ) {
F_54 ( & V_281 -> V_2 -> V_82 ,
L_70 ,
V_325 -> V_337 ) ;
return - V_128 ;
}
if ( V_325 -> V_336 >=
( V_33 -> V_90 * V_33 -> V_35 . V_86 ) ) {
F_54 ( & V_281 -> V_2 -> V_82 ,
L_71 ,
V_325 -> V_336 ) ;
return - V_128 ;
}
if ( V_325 -> V_337 > V_325 -> V_336 ) {
F_54 ( & V_281 -> V_2 -> V_82 ,
L_72 ,
V_325 -> V_337 ) ;
return - V_128 ;
}
if ( F_97 ( V_325 -> V_121 ) != 0 ) {
F_54 ( & V_281 -> V_2 -> V_82 ,
L_73 ,
V_325 -> V_121 ) ;
return - V_128 ;
}
F_110 ( & V_340 ) ;
V_341 = V_325 -> V_336 ;
while ( V_325 -> V_337 <= 1 ) {
V_325 -> V_336 = V_325 -> V_337 ;
V_168 = F_106 ( V_281 , V_325 ) ;
F_111 ( & V_168 -> V_344 , & V_340 ) ;
V_325 -> V_336 = V_341 ;
V_325 -> V_337 ++ ;
if ( V_325 -> V_337 > V_325 -> V_336 )
goto V_345;
}
V_346:
V_342 = 255 / F_9 ( & V_33 -> V_35 , 0 ,
V_325 -> V_121 ) ;
while ( V_325 -> V_337 <= V_341 ) {
V_343 = V_325 -> V_336 - V_325 -> V_337 + 1 ;
if ( V_343 > V_342 )
V_325 -> V_336 = V_325 -> V_337 + V_342 - 1 ;
V_168 = F_106 ( V_281 , V_325 ) ;
if ( F_44 ( V_168 ) ) {
if ( F_69 ( V_168 ) == - V_197 ) {
V_325 -> V_336 = V_341 ;
goto V_345;
} else
return F_69 ( V_168 ) ;
}
F_111 ( & V_168 -> V_344 , & V_340 ) ;
V_325 -> V_337 = V_325 -> V_336 + 1 ;
V_325 -> V_336 = V_341 ;
}
V_345:
F_112 ( & V_340 ) ;
F_113 (cqr, n, &format_queue, blocklist) {
V_31 = V_168 -> V_119 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
if ( V_168 -> V_183 == V_304 )
V_34 = - V_272 ;
F_114 ( & V_168 -> V_344 ) ;
F_46 ( V_168 , V_31 ) ;
V_33 -> V_42 -- ;
}
if ( V_325 -> V_337 <= V_325 -> V_336 )
goto V_346;
return V_34 ;
}
static void F_115 ( struct V_167 * V_168 )
{
V_168 -> V_183 = V_184 ;
if ( V_168 -> V_178 && ( V_168 -> V_119 != V_168 -> V_178 -> V_281 ) ) {
F_116 ( V_168 ) ;
V_168 -> V_119 = V_168 -> V_178 -> V_281 ;
V_168 -> V_170 = V_168 -> V_178 -> V_281 -> V_213 . V_210 ;
}
}
static T_5
F_117 ( struct V_167 * V_168 )
{
struct V_30 * V_31 = (struct V_30 * ) V_168 -> V_119 ;
struct V_1 * V_2 = V_31 -> V_2 ;
switch ( V_2 -> V_347 . V_84 ) {
case 0x3990 :
case 0x2105 :
case 0x2107 :
case 0x1750 :
return V_348 ;
case 0x9343 :
case 0x3880 :
default:
return V_349 ;
}
}
static T_5
F_118 ( struct V_167 * V_168 )
{
return V_350 ;
}
static void F_119 ( struct V_30 * V_31 ,
struct V_167 * V_168 ,
struct V_305 * V_305 )
{
char V_66 ;
char * V_301 = NULL ;
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_66 = V_351 | V_352 | V_353 ;
if ( ( F_120 ( & V_305 -> V_354 ) & V_66 ) == V_66 ) {
if ( ! V_31 -> V_178 && V_33 -> V_355 &&
V_31 -> V_256 == V_257 &&
! F_58 ( V_255 , & V_31 -> V_43 ) &&
! F_58 ( V_228 , & V_31 -> V_43 ) ) {
F_104 ( V_31 ) ;
F_121 ( V_31 ) ;
}
F_122 ( V_31 ) ;
return;
}
V_301 = F_91 ( V_305 ) ;
if ( ! V_301 )
return;
if ( ( V_301 [ 27 ] & V_356 ) && ( V_301 [ 7 ] == 0x0D ) &&
( F_120 ( & V_305 -> V_354 ) & V_357 ) ) {
F_123 ( V_31 , V_305 ) ;
return;
}
if ( ! V_168 && ! ( V_301 [ 27 ] & V_356 ) &&
( ( V_301 [ 6 ] & V_358 ) == V_358 ) ) {
F_124 ( V_31 , V_301 ) ;
return;
}
if ( V_31 -> V_178 && ( V_301 [ 27 ] & V_356 ) &&
( V_301 [ 7 ] == 0x3F ) &&
( F_120 ( & V_305 -> V_354 ) & V_357 ) &&
F_58 ( V_359 , & V_31 -> V_43 ) ) {
if ( V_31 -> V_238 & V_360 )
F_34 ( V_361 , & V_31 -> V_43 ) ;
F_39 ( V_359 , & V_31 -> V_43 ) ;
F_15 ( & V_31 -> V_2 -> V_82 ,
L_74 ) ;
}
}
static struct V_167 * F_125 (
struct V_30 * V_119 ,
struct V_268 * V_178 ,
struct V_362 * V_363 ,
T_6 V_364 ,
T_6 V_365 ,
T_6 V_366 ,
T_6 V_367 ,
unsigned int V_368 ,
unsigned int V_369 ,
unsigned int V_145 ,
unsigned int V_121 )
{
struct V_32 * V_33 ;
unsigned long * V_370 ;
struct V_140 * V_296 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
struct V_371 V_372 ;
struct V_373 * V_374 ;
char * V_375 ;
unsigned int V_376 ;
int V_42 , V_377 , V_297 , V_298 ;
T_6 V_146 ;
unsigned char V_48 , V_378 ;
int V_379 ;
struct V_30 * V_118 ;
V_118 = V_178 -> V_281 ;
V_33 = (struct V_32 * ) V_118 -> V_33 ;
if ( F_126 ( V_363 ) == V_380 )
V_48 = V_60 ;
else if ( F_126 ( V_363 ) == V_381 )
V_48 = V_72 ;
else
return F_108 ( - V_128 ) ;
V_42 = 0 ;
V_377 = 0 ;
F_127 (bv, req, iter) {
if ( V_374 -> V_382 & ( V_121 - 1 ) )
return F_108 ( - V_128 ) ;
V_42 += V_374 -> V_382 >> ( V_178 -> V_314 + 9 ) ;
#if F_77 ( V_258 )
if ( F_128 ( F_129 ( V_374 -> V_383 ) , V_374 -> V_382 ) )
V_377 += V_374 -> V_382 >> ( V_178 -> V_314 + 9 ) ;
#endif
}
if ( V_42 != V_365 - V_364 + 1 )
return F_108 ( - V_128 ) ;
V_379 = V_33 -> V_238 . V_267 [ 8 ] & 0x01 ;
if ( V_379 ) {
V_297 = 2 + V_42 ;
V_298 = sizeof( struct V_93 ) +
sizeof( struct V_140 ) +
V_377 * sizeof( unsigned long ) ;
} else {
V_297 = 2 + V_42 ;
V_298 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
V_377 * sizeof( unsigned long ) ;
}
if ( V_33 -> V_85 && V_364 < 2 * V_145 ) {
if ( V_365 >= 2 * V_145 )
V_42 = 2 * V_145 - V_364 ;
V_297 += V_42 ;
V_298 += V_42 * sizeof( struct V_140 ) ;
}
V_168 = F_43 ( V_176 , V_297 , V_298 ,
V_119 ) ;
if ( F_44 ( V_168 ) )
return V_168 ;
V_45 = V_168 -> V_171 ;
if ( V_379 ) {
if ( F_21 ( V_45 ++ , V_168 -> V_29 , V_366 ,
V_367 , V_48 , V_118 , V_119 ) == - V_230 ) {
F_46 ( V_168 , V_119 ) ;
return F_108 ( - V_230 ) ;
}
V_370 = ( unsigned long * ) ( V_168 -> V_29 +
sizeof( struct V_93 ) ) ;
} else {
if ( F_13 ( V_45 ++ , V_168 -> V_29 , V_366 ,
V_367 , V_48 , V_118 ) == - V_230 ) {
F_46 ( V_168 , V_119 ) ;
return F_108 ( - V_230 ) ;
}
V_370 = ( unsigned long * ) ( V_168 -> V_29 +
sizeof( struct V_28 ) ) ;
}
V_296 = (struct V_140 * ) ( V_370 + V_377 ) ;
V_146 = V_364 ;
if ( V_33 -> V_85 == 0 || V_146 > 2 * V_145 ) {
V_45 [ - 1 ] . V_43 |= V_243 ;
V_126 ( V_45 ++ , V_296 ++ , V_366 , V_368 + 1 ,
V_365 - V_146 + 1 , V_48 , V_118 , V_121 ) ;
}
F_127 (bv, req, iter) {
V_375 = F_129 ( V_374 -> V_383 ) + V_374 -> V_384 ;
if ( V_385 ) {
char * V_386 = F_130 ( V_385 ,
V_196 | V_387 ) ;
if ( V_386 && F_126 ( V_363 ) == V_381 )
memcpy ( V_386 + V_374 -> V_384 , V_375 , V_374 -> V_382 ) ;
if ( V_386 )
V_375 = V_386 + V_374 -> V_384 ;
}
for ( V_376 = 0 ; V_376 < V_374 -> V_382 ; V_376 += V_121 ) {
T_6 V_388 = V_146 ;
unsigned int V_389 = F_131 ( V_388 , V_145 ) ;
V_378 = V_48 ;
V_42 = V_121 ;
if ( V_33 -> V_85 && V_146 < 2 * V_145 ) {
if ( F_22 ( V_145 , V_146 ) ) {
V_378 |= 0x8 ;
V_42 = F_23 ( V_146 ) ;
if ( V_42 < V_121 &&
F_126 ( V_363 ) == V_380 )
memset ( V_375 + V_42 , 0xe5 ,
V_121 - V_42 ) ;
}
V_45 [ - 1 ] . V_43 |= V_243 ;
V_126 ( V_45 ++ , V_296 ++ ,
V_388 , V_389 + 1 ,
1 , V_378 , V_118 , V_42 ) ;
}
if ( V_33 -> V_85 && V_146 == 2 * V_145 ) {
V_45 [ - 1 ] . V_43 |= V_243 ;
V_126 ( V_45 ++ , V_296 ++ ,
V_388 , V_389 + 1 ,
V_365 - V_146 + 1 ,
V_48 , V_118 , V_42 ) ;
}
V_45 [ - 1 ] . V_43 |= V_243 ;
V_45 -> V_54 = V_378 ;
V_45 -> V_42 = V_42 ;
if ( F_128 ( V_375 , V_121 ) ) {
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_370 ;
V_45 -> V_43 = V_390 ;
V_370 = F_132 ( V_370 , V_375 , V_121 ) ;
} else {
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_375 ;
V_45 -> V_43 = 0 ;
}
V_45 ++ ;
V_375 += V_121 ;
V_146 ++ ;
}
}
if ( F_133 ( V_363 ) ||
V_178 -> V_281 -> V_238 & V_391 )
F_34 ( V_254 , & V_168 -> V_43 ) ;
V_168 -> V_119 = V_119 ;
V_168 -> V_177 = V_119 ;
V_168 -> V_178 = V_178 ;
V_168 -> V_179 = V_119 -> V_276 * V_180 ;
V_168 -> V_170 = V_119 -> V_213 . V_217 ;
V_168 -> V_181 = 256 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
return V_168 ;
}
static struct V_167 * F_134 (
struct V_30 * V_119 ,
struct V_268 * V_178 ,
struct V_362 * V_363 ,
T_6 V_364 ,
T_6 V_365 ,
T_6 V_366 ,
T_6 V_367 ,
unsigned int V_368 ,
unsigned int V_369 ,
unsigned int V_145 ,
unsigned int V_121 )
{
unsigned long * V_370 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
struct V_371 V_372 ;
struct V_373 * V_374 ;
char * V_375 , * V_392 ;
unsigned int V_377 , V_297 , V_298 ;
unsigned int V_100 ;
T_6 V_146 ;
unsigned char V_48 ;
struct V_30 * V_118 ;
unsigned int V_393 , V_42 , V_394 ;
unsigned int V_395 , V_396 , V_397 , V_398 ;
unsigned char V_399 , V_400 ;
T_6 V_388 ;
unsigned int V_389 ;
V_118 = V_178 -> V_281 ;
if ( F_126 ( V_363 ) == V_380 )
V_48 = V_113 ;
else if ( F_126 ( V_363 ) == V_381 )
V_48 = V_111 ;
else
return F_108 ( - V_128 ) ;
V_377 = V_365 - V_364 + 1 ;
V_393 = V_367 - V_366 + 1 ;
V_297 = 1 + V_393 ;
V_298 = sizeof( struct V_93 ) +
V_377 * sizeof( unsigned long long ) ;
V_168 = F_43 ( V_176 , V_297 , V_298 ,
V_119 ) ;
if ( F_44 ( V_168 ) )
return V_168 ;
V_45 = V_168 -> V_171 ;
if ( V_366 == V_367 )
V_100 = V_369 - V_368 + 1 ;
else
V_100 = V_369 + 1 ;
V_100 *= V_121 ;
if ( F_20 ( V_45 ++ , V_168 -> V_29 , V_366 ,
V_367 , V_48 , V_118 , V_119 ,
1 , V_368 + 1 ,
V_393 , V_121 ,
V_100 ) == - V_230 ) {
F_46 ( V_168 , V_119 ) ;
return F_108 ( - V_230 ) ;
}
V_370 = ( unsigned long * ) ( V_168 -> V_29 + sizeof( struct V_93 ) ) ;
V_146 = V_364 ;
V_399 = 1 ;
V_400 = 0 ;
V_398 = 0 ;
V_392 = NULL ;
V_395 = 0 ;
F_127 (bv, req, iter) {
V_375 = F_129 ( V_374 -> V_383 ) + V_374 -> V_384 ;
V_396 = V_374 -> V_382 ;
while ( V_396 ) {
if ( V_399 ) {
V_388 = V_146 ;
V_389 = F_131 ( V_388 , V_145 ) ;
V_394 = V_145 - V_389 ;
V_42 = F_135 ( ( V_365 - V_146 + 1 ) ,
( T_6 ) V_394 ) ;
V_398 = V_42 * V_121 ;
V_45 [ - 1 ] . V_43 |= V_243 ;
V_45 -> V_54 = V_48 ;
V_45 -> V_42 = V_398 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_370 ;
V_45 -> V_43 = V_390 ;
V_45 ++ ;
V_146 += V_42 ;
V_399 = 0 ;
if ( ! V_392 )
V_392 = V_375 ;
}
if ( ! V_392 ) {
if ( F_14 ( V_375 ) & ( V_401 - 1 ) ) {
F_46 ( V_168 , V_119 ) ;
return F_108 ( - V_402 ) ;
} else
V_392 = V_375 ;
}
if ( ( V_392 + V_395 ) != V_375 ) {
F_46 ( V_168 , V_119 ) ;
return F_108 ( - V_402 ) ;
}
V_397 = F_135 ( V_396 , V_398 ) ;
V_396 -= V_397 ;
V_375 += V_397 ;
V_395 += V_397 ;
V_398 -= V_397 ;
if ( ! ( F_14 ( V_392 + V_395 ) & ( V_401 - 1 ) ) )
V_400 = 1 ;
if ( ! V_398 ) {
V_399 = 1 ;
V_400 = 1 ;
}
if ( V_400 ) {
V_370 = F_132 ( V_370 , V_392 ,
V_395 ) ;
V_392 = NULL ;
V_395 = 0 ;
V_400 = 0 ;
}
}
}
if ( F_133 ( V_363 ) ||
V_178 -> V_281 -> V_238 & V_391 )
F_34 ( V_254 , & V_168 -> V_43 ) ;
V_168 -> V_119 = V_119 ;
V_168 -> V_177 = V_119 ;
V_168 -> V_178 = V_178 ;
V_168 -> V_179 = V_119 -> V_276 * V_180 ;
V_168 -> V_170 = V_119 -> V_213 . V_217 ;
V_168 -> V_181 = 256 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
return V_168 ;
}
static int F_136 ( struct V_403 * V_403 ,
unsigned int V_46 , unsigned int V_47 , int V_48 ,
struct V_30 * V_118 ,
struct V_30 * V_119 ,
unsigned int V_98 , int V_42 ,
unsigned int V_121 ,
unsigned int V_404 ,
unsigned int V_100 ,
unsigned int V_145 )
{
struct V_93 V_94 ;
struct V_32 * V_122 , * V_123 ;
struct V_28 * V_124 ;
struct V_97 * V_125 ;
struct V_405 * V_405 ;
T_3 V_49 , V_50 ;
T_4 V_51 , V_52 , V_53 ;
T_7 V_406 ;
int V_34 = 0 ;
int V_101 = 0 ;
int V_18 , V_102 ;
V_122 = (struct V_32 * ) V_118 -> V_33 ;
V_123 = (struct V_32 * ) V_119 -> V_33 ;
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
V_125 -> V_104 . V_407 = 0x01 ;
V_406 = V_408 ;
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
V_125 -> V_104 . V_407 = 0x2 ;
V_406 = V_127 ;
break;
default:
F_18 ( V_114 , V_118 ,
L_75 , V_48 ) ;
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
V_124 -> V_409 = 0x20 ;
V_124 -> V_410 = V_145 ;
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
V_125 -> V_104 . V_411 = 1 ;
V_125 -> V_104 . V_412 = 1 ;
V_125 -> V_106 = V_100 ;
V_125 -> V_413 = V_48 ;
V_125 -> V_42 = V_42 ;
V_125 -> V_101 = V_101 ;
F_10 ( & V_125 -> V_115 , V_49 , V_52 ) ;
V_125 -> V_116 . V_23 = V_125 -> V_115 . V_23 ;
V_125 -> V_116 . V_24 = V_125 -> V_115 . V_24 ;
V_125 -> V_116 . V_117 = V_98 ;
V_405 = F_137 ( V_403 , V_406 , 0 ,
& V_94 , sizeof( V_94 ) , V_404 ) ;
return F_44 ( V_405 ) ? F_69 ( V_405 ) : 0 ;
}
static struct V_167 * F_138 (
struct V_30 * V_119 ,
struct V_268 * V_178 ,
struct V_362 * V_363 ,
T_6 V_364 ,
T_6 V_365 ,
T_6 V_366 ,
T_6 V_367 ,
unsigned int V_368 ,
unsigned int V_369 ,
unsigned int V_145 ,
unsigned int V_121 )
{
struct V_167 * V_168 ;
struct V_371 V_372 ;
struct V_373 * V_374 ;
char * V_375 ;
unsigned int V_393 , V_414 ;
unsigned char V_48 ;
struct V_30 * V_118 ;
unsigned int V_100 ;
struct V_403 * V_403 ;
struct V_415 * V_416 = NULL ;
int V_417 ;
T_8 V_418 ;
T_7 V_419 ;
unsigned int V_396 , V_397 , V_398 ;
unsigned char V_399 ;
T_6 V_146 , V_388 ;
unsigned int V_420 ;
unsigned int V_42 , V_394 ;
int V_3 ;
V_118 = V_178 -> V_281 ;
if ( F_126 ( V_363 ) == V_380 ) {
V_48 = V_113 ;
V_417 = V_421 ;
} else if ( F_126 ( V_363 ) == V_381 ) {
V_48 = V_111 ;
V_417 = V_422 ;
} else
return F_108 ( - V_128 ) ;
V_393 = V_367 - V_366 + 1 ;
V_414 = 0 ;
F_127 (bv, req, iter) {
++ V_414 ;
}
if ( F_126 ( V_363 ) == V_381 )
V_414 += ( V_367 - V_366 ) ;
V_418 = F_139 ( 0 , V_414 , 0 ) ;
V_168 = F_43 ( V_176 , 0 , V_418 , V_119 ) ;
if ( F_44 ( V_168 ) )
return V_168 ;
if ( V_366 == V_367 )
V_100 = V_369 - V_368 + 1 ;
else
V_100 = V_369 + 1 ;
V_100 *= V_121 ;
V_403 = F_140 ( V_168 -> V_29 , V_418 , V_417 , 0 , V_414 , 0 ) ;
if ( F_44 ( V_403 ) ) {
V_3 = - V_128 ;
goto V_194;
}
V_168 -> V_171 = F_141 ( V_403 ) ;
if ( F_136 ( V_403 , V_366 , V_367 ,
V_48 , V_118 , V_119 ,
V_368 + 1 ,
V_393 , V_121 ,
( V_365 - V_364 + 1 ) * V_121 ,
V_100 , V_145 ) == - V_230 ) {
V_3 = - V_230 ;
goto V_194;
}
V_398 = 0 ;
if ( F_126 ( V_363 ) == V_381 ) {
V_399 = 1 ;
V_146 = V_364 ;
F_127 (bv, req, iter) {
V_375 = F_129 ( V_374 -> V_383 ) + V_374 -> V_384 ;
V_396 = V_374 -> V_382 ;
while ( V_396 ) {
if ( V_399 ) {
V_388 = V_146 ;
V_420 = F_131 ( V_388 , V_145 ) ;
V_394 = V_145 - V_420 ;
V_42 = F_135 ( ( V_365 - V_146 + 1 ) ,
( T_6 ) V_394 ) ;
V_398 = V_42 * V_121 ;
V_146 += V_42 ;
V_399 = 0 ;
}
V_397 = F_135 ( V_396 , V_398 ) ;
V_396 -= V_397 ;
V_398 -= V_397 ;
if ( ! V_398 ) {
V_399 = 1 ;
V_419 = V_423 ;
} else
V_419 = 0 ;
V_416 = F_142 ( V_403 , V_419 ,
V_375 , V_397 ) ;
if ( F_44 ( V_416 ) ) {
V_3 = - V_128 ;
goto V_194;
}
V_375 += V_397 ;
}
}
} else {
F_127 (bv, req, iter) {
V_375 = F_129 ( V_374 -> V_383 ) + V_374 -> V_384 ;
V_416 = F_142 ( V_403 , 0x00 ,
V_375 , V_374 -> V_382 ) ;
if ( F_44 ( V_416 ) ) {
V_3 = - V_128 ;
goto V_194;
}
}
}
V_416 -> V_43 |= V_424 ;
V_416 -> V_43 &= ~ V_423 ;
F_143 ( V_403 ) ;
if ( F_133 ( V_363 ) ||
V_178 -> V_281 -> V_238 & V_391 )
F_34 ( V_254 , & V_168 -> V_43 ) ;
V_168 -> V_425 = 1 ;
V_168 -> V_119 = V_119 ;
V_168 -> V_177 = V_119 ;
V_168 -> V_178 = V_178 ;
V_168 -> V_179 = V_119 -> V_276 * V_180 ;
V_168 -> V_170 = V_119 -> V_213 . V_217 ;
V_168 -> V_181 = 256 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
return V_168 ;
V_194:
F_46 ( V_168 , V_119 ) ;
return F_108 ( V_3 ) ;
}
static struct V_167 * F_144 ( struct V_30 * V_119 ,
struct V_268 * V_178 ,
struct V_362 * V_363 )
{
int V_426 , V_427 ;
int V_379 ;
int V_428 ;
struct V_32 * V_33 ;
struct V_30 * V_118 ;
T_6 V_364 , V_365 ;
T_6 V_366 , V_367 ;
unsigned int V_368 , V_369 ;
unsigned int V_145 , V_121 ;
int V_429 ;
unsigned int V_430 ;
struct V_167 * V_168 ;
V_118 = V_178 -> V_281 ;
V_33 = (struct V_32 * ) V_118 -> V_33 ;
V_121 = V_178 -> V_311 ;
V_145 = F_9 ( & V_33 -> V_35 , 0 , V_121 ) ;
if ( V_145 == 0 )
return F_108 ( - V_128 ) ;
V_364 = V_366 = F_145 ( V_363 ) >> V_178 -> V_314 ;
V_368 = F_131 ( V_366 , V_145 ) ;
V_365 = V_367 =
( F_145 ( V_363 ) + F_146 ( V_363 ) - 1 ) >> V_178 -> V_314 ;
V_369 = F_131 ( V_367 , V_145 ) ;
V_429 = ( V_33 -> V_85 && V_364 < 2 * V_145 ) ;
V_428 = V_33 -> V_238 . V_267 [ 40 ] & 0x20 ;
V_430 = F_147 ( V_363 ) ;
if ( F_126 ( V_363 ) == V_381 )
V_430 += ( V_367 - V_366 ) * 4 ;
V_426 = V_33 -> V_238 . V_267 [ 9 ] & 0x20 ;
V_427 = V_33 -> V_238 . V_267 [ 12 ] & 0x40 ;
V_379 = V_33 -> V_238 . V_267 [ 8 ] & 0x01 ;
V_168 = NULL ;
if ( V_429 || V_385 ) {
} else if ( ( V_430 <= V_33 -> V_219 )
&& ( V_428 || ( V_366 == V_367 ) ) ) {
V_168 = F_138 ( V_119 , V_178 , V_363 ,
V_364 , V_365 ,
V_366 , V_367 ,
V_368 , V_369 ,
V_145 , V_121 ) ;
if ( F_44 ( V_168 ) && ( F_69 ( V_168 ) != - V_230 ) &&
( F_69 ( V_168 ) != - V_197 ) )
V_168 = NULL ;
} else if ( V_379 &&
( ( ( F_126 ( V_363 ) == V_380 ) && V_426 ) ||
( ( F_126 ( V_363 ) == V_381 ) && V_427 ) ) ) {
V_168 = F_134 ( V_119 , V_178 , V_363 ,
V_364 , V_365 ,
V_366 , V_367 ,
V_368 , V_369 ,
V_145 , V_121 ) ;
if ( F_44 ( V_168 ) && ( F_69 ( V_168 ) != - V_230 ) &&
( F_69 ( V_168 ) != - V_197 ) )
V_168 = NULL ;
}
if ( ! V_168 )
V_168 = F_125 ( V_119 , V_178 , V_363 ,
V_364 , V_365 ,
V_366 , V_367 ,
V_368 , V_369 ,
V_145 , V_121 ) ;
return V_168 ;
}
static struct V_167 * F_148 ( struct V_30 * V_119 ,
struct V_268 * V_178 ,
struct V_362 * V_363 )
{
unsigned long * V_370 ;
struct V_30 * V_118 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
struct V_371 V_372 ;
struct V_373 * V_374 ;
char * V_375 ;
unsigned char V_48 ;
unsigned int V_393 ;
unsigned int V_396 , V_398 ;
unsigned int V_368 ;
unsigned int V_377 , V_297 , V_298 ;
T_6 V_366 , V_367 ;
unsigned int V_431 ;
if ( ( F_145 ( V_363 ) % V_432 ) != 0 ) {
V_168 = F_108 ( - V_128 ) ;
goto V_433;
}
if ( ( ( F_145 ( V_363 ) + F_146 ( V_363 ) ) %
V_432 ) != 0 ) {
V_168 = F_108 ( - V_128 ) ;
goto V_433;
}
V_366 = F_145 ( V_363 ) / V_432 ;
V_367 = ( F_145 ( V_363 ) + F_146 ( V_363 ) - 1 ) /
V_432 ;
V_393 = V_367 - V_366 + 1 ;
V_368 = 0 ;
V_118 = V_178 -> V_281 ;
if ( F_126 ( V_363 ) == V_380 )
V_48 = V_112 ;
else if ( F_126 ( V_363 ) == V_381 )
V_48 = V_107 ;
else {
V_168 = F_108 ( - V_128 ) ;
goto V_433;
}
V_377 = V_393 * V_313 ;
V_297 = 1 + V_393 ;
V_431 = sizeof( struct V_93 ) + 8 ;
V_298 = V_431 + V_377 * sizeof( unsigned long long ) ;
V_168 = F_43 ( V_176 , V_297 ,
V_298 , V_119 ) ;
if ( F_44 ( V_168 ) )
goto V_433;
V_45 = V_168 -> V_171 ;
if ( F_20 ( V_45 ++ , V_168 -> V_29 , V_366 , V_367 , V_48 ,
V_118 , V_119 , 1 , V_368 + 1 ,
V_393 , 0 , 0 ) == - V_230 ) {
F_46 ( V_168 , V_119 ) ;
V_168 = F_108 ( - V_230 ) ;
goto V_433;
}
V_370 = ( unsigned long * ) ( V_168 -> V_29 + V_431 ) ;
V_398 = 0 ;
F_127 (bv, req, iter) {
V_375 = F_129 ( V_374 -> V_383 ) + V_374 -> V_384 ;
V_396 = V_374 -> V_382 ;
if ( ! V_398 ) {
V_45 [ - 1 ] . V_43 |= V_243 ;
V_45 -> V_54 = V_48 ;
V_45 -> V_42 = 57326 ;
V_398 = 65536 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_370 ;
V_45 -> V_43 |= V_390 ;
V_45 -> V_43 |= V_44 ;
V_45 ++ ;
}
V_398 -= V_396 ;
V_370 = F_132 ( V_370 , V_375 , V_396 ) ;
}
if ( F_133 ( V_363 ) ||
V_178 -> V_281 -> V_238 & V_391 )
F_34 ( V_254 , & V_168 -> V_43 ) ;
V_168 -> V_119 = V_119 ;
V_168 -> V_177 = V_119 ;
V_168 -> V_178 = V_178 ;
V_168 -> V_179 = V_119 -> V_276 * V_180 ;
V_168 -> V_170 = V_119 -> V_213 . V_217 ;
V_168 -> V_181 = 256 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
if ( F_44 ( V_168 ) && F_69 ( V_168 ) != - V_230 )
V_168 = NULL ;
V_433:
return V_168 ;
}
static int
F_149 ( struct V_167 * V_168 , struct V_362 * V_363 )
{
struct V_32 * V_33 ;
struct V_26 * V_45 ;
struct V_371 V_372 ;
struct V_373 * V_374 ;
char * V_375 , * V_56 ;
unsigned int V_121 , V_145 , V_376 ;
T_6 V_146 ;
int V_183 ;
if ( ! V_385 )
goto V_433;
V_33 = (struct V_32 * ) V_168 -> V_178 -> V_281 -> V_33 ;
V_121 = V_168 -> V_178 -> V_311 ;
V_145 = F_9 ( & V_33 -> V_35 , 0 , V_121 ) ;
V_146 = F_145 ( V_363 ) >> V_168 -> V_178 -> V_314 ;
V_45 = V_168 -> V_171 ;
V_45 ++ ;
if ( V_33 -> V_85 == 0 || V_146 > 2 * V_145 )
V_45 ++ ;
F_127 (bv, req, iter) {
V_375 = F_129 ( V_374 -> V_383 ) + V_374 -> V_384 ;
for ( V_376 = 0 ; V_376 < V_374 -> V_382 ; V_376 += V_121 ) {
if ( V_33 -> V_85 && V_146 <= 2 * V_145 )
V_45 ++ ;
if ( V_375 ) {
if ( V_45 -> V_43 & V_390 )
V_56 = * ( ( char * * ) ( ( V_173 ) V_45 -> V_56 ) ) ;
else
V_56 = ( char * ) ( ( V_173 ) V_45 -> V_56 ) ;
if ( V_375 != V_56 ) {
if ( F_126 ( V_363 ) == V_380 )
memcpy ( V_375 , V_56 , V_374 -> V_382 ) ;
F_150 ( V_385 ,
( void * ) ( ( V_173 ) V_56 & V_434 ) ) ;
}
V_375 = NULL ;
}
V_45 ++ ;
V_146 ++ ;
}
}
V_433:
V_183 = V_168 -> V_183 == V_186 ;
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_183 ;
}
void F_116 ( struct V_167 * V_168 )
{
struct V_26 * V_45 ;
struct V_93 * V_94 ;
struct V_435 * V_435 ;
struct V_436 * V_436 ;
struct V_405 * V_405 ;
if ( V_168 -> V_425 == 1 ) {
V_435 = V_168 -> V_171 ;
V_436 = F_151 ( V_435 ) ;
V_405 = (struct V_405 * ) & V_436 -> V_437 [ 0 ] ;
V_94 = (struct V_93 * ) & V_405 -> V_438 [ 0 ] ;
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
static struct V_167 * F_152 ( struct V_30 * V_281 ,
struct V_268 * V_178 ,
struct V_362 * V_363 )
{
struct V_32 * V_33 ;
struct V_30 * V_119 ;
unsigned long V_43 ;
struct V_167 * V_168 ;
V_119 = F_107 ( V_281 ) ;
if ( ! V_119 )
V_119 = V_281 ;
V_33 = (struct V_32 * ) V_119 -> V_33 ;
if ( V_33 -> V_42 >= V_439 )
return F_108 ( - V_440 ) ;
F_27 ( F_28 ( V_119 -> V_2 ) , V_43 ) ;
V_33 -> V_42 ++ ;
if ( ( V_281 -> V_238 & V_284 ) )
V_168 = F_148 ( V_119 , V_178 , V_363 ) ;
else
V_168 = F_144 ( V_119 , V_178 , V_363 ) ;
if ( F_44 ( V_168 ) )
V_33 -> V_42 -- ;
F_29 ( F_28 ( V_119 -> V_2 ) , V_43 ) ;
return V_168 ;
}
static int F_153 ( struct V_167 * V_168 ,
struct V_362 * V_363 )
{
struct V_32 * V_33 ;
unsigned long V_43 ;
F_27 ( F_28 ( V_168 -> V_177 -> V_2 ) , V_43 ) ;
V_33 = (struct V_32 * ) V_168 -> V_177 -> V_33 ;
V_33 -> V_42 -- ;
F_29 ( F_28 ( V_168 -> V_177 -> V_2 ) , V_43 ) ;
return F_149 ( V_168 , V_363 ) ;
}
static int
F_154 ( struct V_30 * V_31 ,
struct V_441 * V_442 )
{
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_442 -> V_443 = 2 ;
V_442 -> V_444 = V_33 -> V_85 ? 0 : 1 ;
V_442 -> V_120 = V_33 -> V_85 ? V_445 : V_446 ;
V_442 -> V_447 = sizeof( struct V_14 ) ;
memcpy ( V_442 -> V_448 , & V_33 -> V_35 ,
sizeof( struct V_14 ) ) ;
V_442 -> V_449 = F_135 ( ( unsigned long ) V_33 -> V_200 ,
sizeof( V_442 -> V_450 ) ) ;
memcpy ( V_442 -> V_450 , V_33 -> V_201 ,
V_442 -> V_449 ) ;
return 0 ;
}
static int
F_155 ( struct V_30 * V_31 )
{
struct V_167 * V_168 ;
int V_34 ;
struct V_26 * V_45 ;
int V_451 ;
if ( ! F_156 ( V_452 ) )
return - V_41 ;
V_451 = 0 ;
V_168 = F_43 ( V_176 , 1 , 32 , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_157 ( & V_453 ) ;
V_451 = 1 ;
V_168 = & V_454 -> V_168 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
memset ( & V_454 -> V_45 , 0 ,
sizeof( V_454 -> V_45 ) ) ;
V_168 -> V_171 = & V_454 -> V_45 ;
V_168 -> V_29 = & V_454 -> V_29 ;
V_168 -> V_175 = V_176 ;
}
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_455 ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_42 = 32 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_168 -> V_29 ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
F_39 ( V_189 , & V_168 -> V_43 ) ;
F_34 ( V_254 , & V_168 -> V_43 ) ;
V_168 -> V_181 = 2 ;
V_168 -> V_179 = 2 * V_180 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_40 ( V_168 ) ;
if ( ! V_34 )
F_39 ( V_359 , & V_31 -> V_43 ) ;
if ( V_451 )
F_62 ( & V_453 ) ;
else
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int
F_158 ( struct V_30 * V_31 )
{
struct V_167 * V_168 ;
int V_34 ;
struct V_26 * V_45 ;
int V_451 ;
if ( ! F_156 ( V_452 ) )
return - V_41 ;
V_451 = 0 ;
V_168 = F_43 ( V_176 , 1 , 32 , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_157 ( & V_453 ) ;
V_451 = 1 ;
V_168 = & V_454 -> V_168 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
memset ( & V_454 -> V_45 , 0 ,
sizeof( V_454 -> V_45 ) ) ;
V_168 -> V_171 = & V_454 -> V_45 ;
V_168 -> V_29 = & V_454 -> V_29 ;
V_168 -> V_175 = V_176 ;
}
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_456 ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_42 = 32 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_168 -> V_29 ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
F_39 ( V_189 , & V_168 -> V_43 ) ;
F_34 ( V_254 , & V_168 -> V_43 ) ;
V_168 -> V_181 = 2 ;
V_168 -> V_179 = 2 * V_180 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_40 ( V_168 ) ;
if ( ! V_34 )
F_34 ( V_359 , & V_31 -> V_43 ) ;
if ( V_451 )
F_62 ( & V_453 ) ;
else
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int
F_159 ( struct V_30 * V_31 )
{
struct V_167 * V_168 ;
int V_34 ;
struct V_26 * V_45 ;
int V_451 ;
if ( ! F_156 ( V_452 ) )
return - V_41 ;
V_451 = 0 ;
V_168 = F_43 ( V_176 , 1 , 32 , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_157 ( & V_453 ) ;
V_451 = 1 ;
V_168 = & V_454 -> V_168 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
memset ( & V_454 -> V_45 , 0 ,
sizeof( V_454 -> V_45 ) ) ;
V_168 -> V_171 = & V_454 -> V_45 ;
V_168 -> V_29 = & V_454 -> V_29 ;
V_168 -> V_175 = V_176 ;
}
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_457 ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_42 = 32 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_168 -> V_29 ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
F_39 ( V_189 , & V_168 -> V_43 ) ;
F_34 ( V_254 , & V_168 -> V_43 ) ;
V_168 -> V_181 = 2 ;
V_168 -> V_179 = 2 * V_180 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_40 ( V_168 ) ;
if ( ! V_34 )
F_34 ( V_359 , & V_31 -> V_43 ) ;
if ( V_451 )
F_62 ( & V_453 ) ;
else
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int F_160 ( struct V_30 * V_31 ,
void T_9 * V_458 )
{
struct V_167 * V_168 ;
int V_34 ;
struct V_26 * V_45 ;
int V_451 ;
struct V_459 V_460 ;
if ( ! F_156 ( V_452 ) )
return - V_41 ;
if ( F_161 ( & V_460 , V_458 , sizeof( V_460 ) ) )
return - V_461 ;
V_451 = 0 ;
V_168 = F_43 ( V_176 , 1 ,
sizeof( struct V_462 ) , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_157 ( & V_453 ) ;
V_451 = 1 ;
V_168 = & V_454 -> V_168 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
memset ( & V_454 -> V_45 , 0 ,
sizeof( V_454 -> V_45 ) ) ;
V_168 -> V_171 = & V_454 -> V_45 ;
V_168 -> V_29 = & V_454 -> V_29 ;
V_168 -> V_175 = V_176 ;
}
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_463 ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_42 = 12 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_168 -> V_29 ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
F_39 ( V_189 , & V_168 -> V_43 ) ;
F_34 ( V_254 , & V_168 -> V_43 ) ;
F_34 ( V_190 , & V_168 -> V_43 ) ;
V_168 -> V_181 = 5 ;
V_168 -> V_179 = 10 * V_180 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_168 -> V_170 = V_460 . V_464 ;
V_34 = F_40 ( V_168 ) ;
if ( ! V_34 && V_460 . V_464 && ( V_168 -> V_170 != V_460 . V_464 ) )
V_34 = - V_272 ;
if ( ! V_34 ) {
V_460 . V_29 = * ( (struct V_462 * ) V_168 -> V_29 ) ;
if ( F_162 ( V_458 , & V_460 , sizeof( V_460 ) ) )
V_34 = - V_461 ;
}
if ( V_451 )
F_62 ( & V_453 ) ;
else
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int
F_163 ( struct V_30 * V_31 , void T_9 * V_458 )
{
struct V_235 * V_236 ;
struct V_465 * V_466 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
int V_34 ;
V_168 = F_43 ( V_176 , 1 + 1 ,
( sizeof( struct V_235 ) +
sizeof( struct V_465 ) ) ,
V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_18 ( V_7 , V_31 , L_1 ,
L_76 ) ;
return F_69 ( V_168 ) ;
}
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_181 = 0 ;
F_39 ( V_189 , & V_168 -> V_43 ) ;
V_168 -> V_179 = 10 * V_180 ;
V_236 = (struct V_235 * ) V_168 -> V_29 ;
memset ( V_236 , 0 , sizeof( struct V_235 ) ) ;
V_236 -> V_239 = V_240 ;
V_236 -> V_241 = 0x01 ;
V_236 -> V_467 [ 1 ] = 0x01 ;
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_242 ;
V_45 -> V_42 = sizeof( struct V_235 ) ;
V_45 -> V_43 |= V_243 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_236 ;
V_466 = (struct V_465 * ) ( V_236 + 1 ) ;
memset ( V_466 , 0 , sizeof( struct V_465 ) ) ;
V_45 ++ ;
V_45 -> V_54 = V_244 ;
V_45 -> V_42 = sizeof( struct V_465 ) ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_466 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_45 ( V_168 ) ;
if ( V_34 == 0 ) {
V_236 = (struct V_235 * ) V_168 -> V_29 ;
V_466 = (struct V_465 * ) ( V_236 + 1 ) ;
if ( F_162 ( V_458 , V_466 ,
sizeof( struct V_465 ) ) )
V_34 = - V_461 ;
}
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int
F_164 ( struct V_30 * V_31 , void T_9 * V_458 )
{
struct V_32 * V_33 =
(struct V_32 * ) V_31 -> V_33 ;
struct V_468 V_70 = V_33 -> V_70 ;
int V_34 ;
if ( ! F_156 ( V_452 ) )
return - V_41 ;
if ( ! V_458 )
return - V_128 ;
V_34 = 0 ;
if ( F_162 ( V_458 , ( long * ) & V_70 ,
sizeof( struct V_468 ) ) )
V_34 = - V_461 ;
return V_34 ;
}
static int
F_165 ( struct V_30 * V_31 , void T_9 * V_458 )
{
struct V_32 * V_33 =
(struct V_32 * ) V_31 -> V_33 ;
struct V_468 V_70 ;
if ( ! F_156 ( V_452 ) )
return - V_41 ;
if ( ! V_458 )
return - V_128 ;
if ( F_161 ( & V_70 , V_458 , sizeof( struct V_468 ) ) )
return - V_461 ;
V_33 -> V_70 = V_70 ;
F_81 ( & V_31 -> V_2 -> V_82 ,
L_77 ,
V_33 -> V_70 . V_69 , V_33 -> V_70 . V_89 ) ;
return 0 ;
}
static int F_166 ( struct V_30 * V_31 , void T_9 * V_458 )
{
struct V_469 V_460 ;
char * V_470 , * V_471 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
char V_472 , V_473 ;
int V_34 ;
if ( ! F_156 ( V_452 ) && ! F_156 ( V_474 ) )
return - V_41 ;
V_472 = V_473 = 0 ;
V_34 = - V_461 ;
if ( F_161 ( & V_460 , V_458 , sizeof( V_460 ) ) )
goto V_433;
if ( F_167 () || sizeof( long ) == 4 ) {
V_34 = - V_128 ;
if ( ( V_460 . V_470 >> 32 ) != 0 )
goto V_433;
if ( ( V_460 . V_471 >> 32 ) != 0 )
goto V_433;
V_460 . V_470 &= 0x7fffffffULL ;
V_460 . V_471 &= 0x7fffffffULL ;
}
V_470 = F_42 ( V_460 . V_475 , V_195 | V_196 ) ;
V_471 = F_42 ( V_460 . V_476 , V_195 | V_196 ) ;
if ( ! V_470 || ! V_471 ) {
V_34 = - V_197 ;
goto V_477;
}
V_34 = - V_461 ;
if ( F_161 ( V_470 ,
( void T_9 * ) ( unsigned long ) V_460 . V_470 ,
V_460 . V_475 ) )
goto V_477;
V_472 = V_470 [ 0 ] ;
V_473 = V_470 [ 1 ] ;
V_168 = F_43 ( V_176 , 2 , 0 , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_18 ( V_7 , V_31 , L_1 ,
L_76 ) ;
V_34 = F_69 ( V_168 ) ;
goto V_477;
}
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_181 = 3 ;
V_168 -> V_179 = 10 * V_180 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_242 ;
V_45 -> V_42 = V_460 . V_475 ;
V_45 -> V_43 |= V_243 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_470 ;
V_45 ++ ;
V_45 -> V_54 = V_244 ;
V_45 -> V_42 = V_460 . V_476 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_471 ;
V_34 = F_45 ( V_168 ) ;
if ( V_34 )
goto V_478;
V_34 = - V_461 ;
if ( F_162 ( ( void T_9 * ) ( unsigned long ) V_460 . V_471 ,
V_471 , V_460 . V_476 ) )
goto V_478;
V_34 = 0 ;
V_478:
F_46 ( V_168 , V_168 -> V_177 ) ;
V_477:
F_47 ( V_471 ) ;
F_47 ( V_470 ) ;
V_433:
F_18 ( V_7 , V_31 ,
L_78 ,
( int ) V_472 , ( int ) V_473 , V_34 ) ;
return V_34 ;
}
static int
F_168 ( struct V_268 * V_178 , unsigned int V_48 , void T_9 * V_458 )
{
struct V_30 * V_31 = V_178 -> V_281 ;
switch ( V_48 ) {
case V_479 :
return F_164 ( V_31 , V_458 ) ;
case V_480 :
return F_165 ( V_31 , V_458 ) ;
case V_481 :
return F_163 ( V_31 , V_458 ) ;
case V_482 :
return F_155 ( V_31 ) ;
case V_483 :
return F_158 ( V_31 ) ;
case V_484 :
return F_159 ( V_31 ) ;
case V_485 :
return F_160 ( V_31 , V_458 ) ;
case V_486 :
return F_166 ( V_31 , V_458 ) ;
default:
return - V_487 ;
}
}
static int
F_169 ( struct V_26 * V_488 , struct V_26 * V_489 , char * V_490 )
{
int V_491 , V_42 ;
char * V_492 ;
V_491 = 0 ;
while ( V_488 <= V_489 ) {
V_491 += sprintf ( V_490 + V_491 , V_493
L_79 ,
V_488 , ( ( int * ) V_488 ) [ 0 ] , ( ( int * ) V_488 ) [ 1 ] ) ;
if ( V_488 -> V_43 & V_390 )
V_492 = ( char * ) * ( ( V_173 * ) ( V_173 ) V_488 -> V_56 ) ;
else
V_492 = ( char * ) ( ( V_173 ) V_488 -> V_56 ) ;
for ( V_42 = 0 ; V_42 < V_488 -> V_42 && V_42 < 32 ; V_42 ++ ) {
if ( V_42 % 8 == 0 ) V_491 += sprintf ( V_490 + V_491 , L_80 ) ;
if ( V_42 % 4 == 0 ) V_491 += sprintf ( V_490 + V_491 , L_80 ) ;
V_491 += sprintf ( V_490 + V_491 , L_11 , V_492 [ V_42 ] ) ;
}
V_491 += sprintf ( V_490 + V_491 , L_81 ) ;
V_488 ++ ;
}
return V_491 ;
}
static void
F_170 ( struct V_30 * V_31 , struct V_305 * V_305 ,
char * V_494 )
{
T_10 * V_301 ;
T_10 * V_495 ;
V_301 = ( T_10 * ) F_91 ( V_305 ) ;
V_495 = ( T_10 * ) & V_305 -> V_354 ;
if ( V_301 ) {
F_18 ( V_496 , V_31 , L_82
L_83 ,
V_494 , * V_495 , * ( ( T_3 * ) ( V_495 + 1 ) ) ,
V_301 [ 0 ] , V_301 [ 1 ] , V_301 [ 2 ] , V_301 [ 3 ] ) ;
} else {
F_18 ( V_496 , V_31 , L_84 ,
V_494 , * V_495 , * ( ( T_3 * ) ( V_495 + 1 ) ) ,
L_85 ) ;
}
}
static void F_171 ( struct V_30 * V_31 ,
struct V_167 * V_363 , struct V_305 * V_305 )
{
char * V_490 ;
struct V_26 * V_497 , * V_498 , * V_499 , * V_488 , * V_489 ;
int V_491 , V_500 , V_501 ;
V_490 = ( char * ) F_172 ( V_233 ) ;
if ( V_490 == NULL ) {
F_18 ( V_7 , V_31 , L_1 ,
L_86 ) ;
return;
}
V_491 = sprintf ( V_490 , V_493
L_87 ,
F_173 ( & V_31 -> V_2 -> V_82 ) ) ;
V_491 += sprintf ( V_490 + V_491 , V_493
L_88
L_89 ,
V_363 , F_174 ( & V_305 -> V_354 ) , F_175 ( & V_305 -> V_354 ) ,
F_176 ( & V_305 -> V_354 ) , F_177 ( & V_305 -> V_354 ) ,
F_120 ( & V_305 -> V_354 ) , F_178 ( & V_305 -> V_354 ) ,
V_363 ? V_363 -> V_250 : 0 ) ;
V_491 += sprintf ( V_490 + V_491 , V_493
L_90 ,
F_173 ( & V_31 -> V_2 -> V_82 ) ,
( void * ) ( V_173 ) V_305 -> V_354 . V_48 . V_502 ) ;
if ( V_305 -> V_503 . V_504 . V_505 . V_506 ) {
for ( V_500 = 0 ; V_500 < 4 ; V_500 ++ ) {
V_491 += sprintf ( V_490 + V_491 , V_493
L_91 ,
( 8 * V_500 ) , ( ( 8 * V_500 ) + 7 ) ) ;
for ( V_501 = 0 ; V_501 < 8 ; V_501 ++ ) {
V_491 += sprintf ( V_490 + V_491 , L_92 ,
V_305 -> V_507 [ 8 * V_500 + V_501 ] ) ;
}
V_491 += sprintf ( V_490 + V_491 , L_81 ) ;
}
if ( V_305 -> V_507 [ 27 ] & V_356 ) {
sprintf ( V_490 + V_491 , V_493
L_93
L_94 ,
V_305 -> V_507 [ 7 ] >> 4 , V_305 -> V_507 [ 7 ] & 0x0f ,
V_305 -> V_507 [ 1 ] & 0x10 ? L_59 : L_95 ) ;
} else {
sprintf ( V_490 + V_491 , V_493
L_96
L_97 ,
V_305 -> V_507 [ 6 ] & 0x0f , V_305 -> V_507 [ 22 ] >> 4 ) ;
}
} else {
sprintf ( V_490 + V_491 , V_493
L_98 ) ;
}
F_179 ( V_508 L_1 , V_490 ) ;
if ( V_363 ) {
V_497 = V_363 -> V_171 ;
for ( V_498 = V_497 ; V_498 -> V_43 & ( V_243 | V_509 ) ; V_498 ++ ) ;
V_489 = F_135 ( V_497 + 6 , V_498 ) ;
V_491 = sprintf ( V_490 , V_493
L_99 , V_363 ) ;
F_169 ( V_497 , V_489 , V_490 + V_491 ) ;
F_179 ( V_508 L_1 , V_490 ) ;
V_491 = 0 ;
V_488 = ++ V_489 ;
V_499 = (struct V_26 * ) ( V_173 )
V_305 -> V_354 . V_48 . V_502 ;
if ( V_488 < V_499 - 2 ) {
V_488 = V_499 - 2 ;
V_491 += sprintf ( V_490 , V_493 L_100 ) ;
}
V_489 = F_135 ( V_499 + 1 , V_498 ) ;
V_491 += F_169 ( V_488 , V_489 , V_490 + V_491 ) ;
V_488 = F_180 ( V_488 , ++ V_489 ) ;
if ( V_488 < V_498 - 1 ) {
V_488 = V_498 - 1 ;
V_491 += sprintf ( V_490 + V_491 , V_493 L_100 ) ;
}
V_491 += F_169 ( V_488 , V_498 , V_490 + V_491 ) ;
if ( V_491 > 0 )
F_179 ( V_508 L_1 , V_490 ) ;
}
F_181 ( ( unsigned long ) V_490 ) ;
}
static void F_182 ( struct V_30 * V_31 ,
struct V_167 * V_363 , struct V_305 * V_305 )
{
char * V_490 ;
int V_491 , V_500 , V_501 , V_510 ;
struct V_511 * V_511 ;
T_7 * V_301 , * V_512 ;
V_490 = ( char * ) F_172 ( V_233 ) ;
if ( V_490 == NULL ) {
F_18 ( V_7 , V_31 , L_101 ,
L_102 ) ;
return;
}
V_491 = sprintf ( V_490 , V_493
L_87 ,
F_173 ( & V_31 -> V_2 -> V_82 ) ) ;
V_491 += sprintf ( V_490 + V_491 , V_493
L_88
L_103 ,
V_363 , F_174 ( & V_305 -> V_354 ) , F_175 ( & V_305 -> V_354 ) ,
F_176 ( & V_305 -> V_354 ) , F_177 ( & V_305 -> V_354 ) ,
F_120 ( & V_305 -> V_354 ) , F_178 ( & V_305 -> V_354 ) ,
V_305 -> V_354 . V_513 . V_514 , V_305 -> V_354 . V_513 . V_515 ,
V_363 ? V_363 -> V_250 : 0 ) ;
V_491 += sprintf ( V_490 + V_491 , V_493
L_104 ,
F_173 ( & V_31 -> V_2 -> V_82 ) ,
( void * ) ( V_173 ) V_305 -> V_354 . V_513 . V_435 ) ;
V_511 = NULL ;
V_301 = NULL ;
if ( V_305 -> V_354 . V_513 . V_435 && ( V_305 -> V_354 . V_513 . V_514 & 0x01 ) )
V_511 = F_183 (
(struct V_435 * ) ( unsigned long ) V_305 -> V_354 . V_513 . V_435 ) ;
if ( V_511 ) {
V_491 += sprintf ( V_490 + V_491 , V_493
L_105 , V_511 -> V_106 ) ;
V_491 += sprintf ( V_490 + V_491 , V_493
L_106 , V_511 -> V_43 ) ;
V_491 += sprintf ( V_490 + V_491 , V_493
L_107 , V_511 -> V_516 ) ;
V_491 += sprintf ( V_490 + V_491 , V_493
L_108 , V_511 -> V_42 ) ;
V_510 = V_511 -> V_42 - 28 ;
V_491 += sprintf ( V_490 + V_491 , V_493
L_109 , V_510 ) ;
switch ( V_511 -> V_43 & 0x07 ) {
case 1 :
V_491 += sprintf ( V_490 + V_491 , V_493
L_110 ,
V_511 -> V_517 . V_518 . V_519 ) ;
V_491 += sprintf ( V_490 + V_491 , V_493
L_111 ,
V_511 -> V_517 . V_518 . V_520 ) ;
V_491 += sprintf ( V_490 + V_491 , V_493
L_112 ,
V_511 -> V_517 . V_518 . V_521 ) ;
V_491 += sprintf ( V_490 + V_491 , V_493
L_113 ,
V_511 -> V_517 . V_518 . V_522 ) ;
V_491 += sprintf ( V_490 + V_491 , V_493
L_114 ,
V_511 -> V_517 . V_518 . V_523 ) ;
V_301 = V_511 -> V_517 . V_518 . V_301 ;
break;
case 2 :
V_491 += sprintf ( V_490 + V_491 , V_493
L_115 , V_511 -> V_517 . V_524 . V_34 ) ;
for ( V_500 = 0 ; V_500 < 2 ; V_500 ++ ) {
V_491 += sprintf ( V_490 + V_491 , V_493
L_116 ,
( 8 * V_500 ) , ( ( 8 * V_500 ) + 7 ) ) ;
V_512 = V_511 -> V_517 . V_524 . V_512 ;
for ( V_501 = 0 ; V_501 < 8 ; V_501 ++ ) {
V_491 += sprintf ( V_490 + V_491 , L_92 ,
V_512 [ 8 * V_500 + V_501 ] ) ;
}
V_491 += sprintf ( V_490 + V_491 , L_81 ) ;
}
V_301 = V_511 -> V_517 . V_524 . V_301 ;
break;
case 3 :
V_491 += sprintf ( V_490 + V_491 , V_493
L_117 ) ;
break;
}
if ( V_301 ) {
for ( V_500 = 0 ; V_500 < 4 ; V_500 ++ ) {
V_491 += sprintf ( V_490 + V_491 , V_493
L_91 ,
( 8 * V_500 ) , ( ( 8 * V_500 ) + 7 ) ) ;
for ( V_501 = 0 ; V_501 < 8 ; V_501 ++ ) {
V_491 += sprintf ( V_490 + V_491 , L_92 ,
V_301 [ 8 * V_500 + V_501 ] ) ;
}
V_491 += sprintf ( V_490 + V_491 , L_81 ) ;
}
if ( V_301 [ 27 ] & V_356 ) {
sprintf ( V_490 + V_491 , V_493
L_93
L_94 ,
V_301 [ 7 ] >> 4 , V_301 [ 7 ] & 0x0f ,
V_301 [ 1 ] & 0x10 ? L_59 : L_95 ) ;
} else {
sprintf ( V_490 + V_491 , V_493
L_96
L_97 ,
V_301 [ 6 ] & 0x0f , V_301 [ 22 ] >> 4 ) ;
}
} else {
sprintf ( V_490 + V_491 , V_493
L_98 ) ;
}
} else {
sprintf ( V_490 + V_491 , V_493
L_118 ) ;
}
F_179 ( V_508 L_1 , V_490 ) ;
F_181 ( ( unsigned long ) V_490 ) ;
}
static void F_184 ( struct V_30 * V_31 ,
struct V_167 * V_363 , struct V_305 * V_305 )
{
if ( F_185 ( & V_305 -> V_354 ) )
F_182 ( V_31 , V_363 , V_305 ) ;
else
F_171 ( V_31 , V_363 , V_305 ) ;
}
static int F_186 ( struct V_30 * V_31 )
{
F_104 ( V_31 ) ;
F_86 ( V_31 ) ;
return 0 ;
}
static int F_187 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
struct V_14 V_525 ;
int V_34 ;
struct V_149 V_269 ;
unsigned long V_43 ;
unsigned long V_526 = 0 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
F_50 ( V_31 ) ;
F_30 ( V_31 , & V_269 ) ;
V_34 = F_26 ( V_31 ) ;
F_27 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
if ( memcmp ( & V_33 -> V_134 , & V_269 , sizeof( struct V_149 ) ) != 0 )
F_15 ( & V_31 -> V_2 -> V_82 , L_119
L_120 ) ;
F_29 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
if ( V_34 )
goto V_527;
V_34 = F_83 ( V_31 ) ;
if ( V_34 )
return V_34 ;
F_34 ( V_254 , & V_526 ) ;
F_73 ( V_31 , V_526 ) ;
F_50 ( V_31 ) ;
F_68 ( V_31 ) ;
V_34 = F_84 ( V_31 , V_176 ,
& V_525 , 64 ) ;
if ( V_34 ) {
F_3 ( V_7 , V_31 -> V_2 ,
L_53 , V_34 ) ;
goto V_527;
}
F_27 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
memcpy ( & V_33 -> V_35 , & V_525 , sizeof( V_525 ) ) ;
F_29 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
F_100 ( V_31 ) ;
return 0 ;
V_527:
return - 1 ;
}
static int F_188 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
int V_34 , V_528 ;
char V_226 [ 60 ] ;
struct V_149 V_134 ;
unsigned long V_43 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
F_27 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
V_528 = V_33 -> V_134 . V_161 ;
F_29 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
V_34 = F_50 ( V_31 ) ;
if ( V_34 )
goto V_527;
V_34 = F_26 ( V_31 ) ;
if ( V_34 )
goto V_527;
F_189 ( V_31 ) ;
F_30 ( V_31 , & V_134 ) ;
if ( V_528 != V_134 . V_161 ) {
if ( strlen ( V_134 . V_163 ) > 0 )
snprintf ( V_226 , sizeof( V_226 ) ,
L_17 , V_134 . V_150 , V_134 . V_152 ,
V_134 . V_154 , V_134 . V_161 , V_134 . V_163 ) ;
else
snprintf ( V_226 , sizeof( V_226 ) ,
L_18 , V_134 . V_150 , V_134 . V_152 ,
V_134 . V_154 , V_134 . V_161 ) ;
F_81 ( & V_31 -> V_2 -> V_82 ,
L_121
L_122 , V_226 ) ;
}
return 0 ;
V_527:
return - 1 ;
}
static int T_11
F_190 ( void )
{
int V_3 ;
F_191 ( V_8 . V_529 , 4 ) ;
V_454 = F_64 ( sizeof( * V_454 ) ,
V_195 | V_196 ) ;
if ( ! V_454 )
return - V_197 ;
V_234 = F_64 ( sizeof( * V_234 ) ,
V_195 | V_196 ) ;
if ( ! V_234 ) {
F_47 ( V_454 ) ;
return - V_197 ;
}
V_3 = F_192 ( & V_530 ) ;
if ( ! V_3 )
F_193 () ;
else {
F_47 ( V_234 ) ;
F_47 ( V_454 ) ;
}
return V_3 ;
}
static void T_12
F_194 ( void )
{
F_195 ( & V_530 ) ;
F_47 ( V_234 ) ;
F_47 ( V_454 ) ;
}
