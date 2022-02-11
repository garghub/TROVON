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
return - V_189 ;
F_32 ( V_31 , V_168 , V_169 , V_170 ) ;
F_39 ( V_190 , & V_168 -> V_43 ) ;
F_34 ( V_191 , & V_168 -> V_43 ) ;
V_168 -> V_181 = 5 ;
V_168 -> V_192 = F_35 ;
V_34 = F_40 ( V_168 ) ;
return V_34 ;
}
static int F_41 ( struct V_30 * V_31 ,
void * * V_169 ,
int * V_193 , T_2 V_170 )
{
struct V_187 * V_187 ;
char * V_194 = NULL ;
int V_3 ;
struct V_167 * V_168 ;
V_187 = F_38 ( V_31 -> V_2 , V_188 ) ;
if ( ! V_187 || V_187 -> V_48 != V_172 ) {
V_3 = - V_189 ;
goto V_195;
}
V_194 = F_42 ( V_174 , V_196 | V_197 ) ;
if ( ! V_194 ) {
V_3 = - V_198 ;
goto V_195;
}
V_168 = F_43 ( V_176 , 1 ,
0 ,
V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_18 ( V_7 , V_31 , L_1 ,
L_12 ) ;
V_3 = - V_198 ;
goto V_195;
}
F_32 ( V_31 , V_168 , V_194 , V_170 ) ;
V_168 -> V_192 = F_35 ;
V_3 = F_45 ( V_168 ) ;
F_46 ( V_168 , V_168 -> V_177 ) ;
if ( V_3 )
goto V_195;
* V_193 = V_174 ;
* V_169 = V_194 ;
return 0 ;
V_195:
F_47 ( V_194 ) ;
* V_169 = NULL ;
* V_193 = 0 ;
return V_3 ;
}
static int F_48 ( struct V_32 * V_33 )
{
struct V_199 * V_158 ;
int V_200 , V_42 ;
V_33 -> V_130 = NULL ;
V_33 -> V_158 = NULL ;
V_33 -> V_162 = NULL ;
V_33 -> V_155 = NULL ;
V_42 = V_33 -> V_201 / sizeof( struct V_199 ) ;
V_158 = (struct V_199 * ) V_33 -> V_202 ;
for ( V_200 = 0 ; V_200 < V_42 ; ++ V_200 ) {
if ( V_158 -> V_43 . V_203 == 1 && V_158 -> V_120 == 1 )
V_33 -> V_158 = V_158 ;
else if ( V_158 -> V_43 . V_203 == 1 && V_158 -> V_120 == 4 )
V_33 -> V_162 = (struct V_204 * ) V_158 ;
else if ( V_158 -> V_43 . V_203 == 2 )
V_33 -> V_155 = (struct V_205 * ) V_158 ;
else if ( V_158 -> V_43 . V_203 == 3 && V_158 -> V_206 == 1 )
V_33 -> V_130 = (struct V_207 * ) V_158 ;
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
static unsigned char F_49 ( void * V_202 , int V_201 )
{
struct V_205 * V_155 ;
int V_200 , V_42 , V_208 ;
V_42 = V_201 / sizeof( * V_155 ) ;
V_155 = (struct V_205 * ) V_202 ;
V_208 = 0 ;
for ( V_200 = 0 ; V_200 < V_42 ; ++ V_200 ) {
if ( V_155 -> V_43 . V_203 == 2 ) {
V_208 = 1 ;
break;
}
V_155 ++ ;
}
if ( V_208 )
return ( ( char * ) V_155 ) [ 18 ] & 0x07 ;
else
return 0 ;
}
static int F_50 ( struct V_30 * V_31 )
{
void * V_202 ;
int V_201 , V_209 ;
int V_34 ;
T_2 V_170 , V_210 ;
struct V_32 * V_33 , V_211 ;
struct V_212 * V_213 ;
struct V_149 * V_134 ;
char V_214 [ 60 ] , V_215 [ 60 ] ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_213 = & V_31 -> V_213 ;
V_210 = F_51 ( V_31 -> V_2 ) ;
V_209 = 0 ;
for ( V_170 = 0x80 ; V_170 ; V_170 >>= 1 ) {
if ( ! ( V_170 & V_210 ) )
continue;
V_34 = F_41 ( V_31 , & V_202 ,
& V_201 , V_170 ) ;
if ( V_34 && V_34 != - V_189 ) {
F_3 ( V_7 , V_31 -> V_2 ,
L_13
L_14 , V_34 ) ;
return V_34 ;
}
if ( V_202 == NULL ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_15
L_16 ) ;
V_213 -> V_210 |= V_170 ;
continue;
}
if ( ! V_209 ) {
F_47 ( V_33 -> V_202 ) ;
V_33 -> V_202 = V_202 ;
V_33 -> V_201 = V_201 ;
if ( F_48 ( V_33 ) ) {
V_33 -> V_202 = NULL ;
V_33 -> V_201 = 0 ;
F_47 ( V_202 ) ;
continue;
}
F_26 ( V_31 ) ;
V_209 ++ ;
} else {
V_211 . V_202 = V_202 ;
V_211 . V_201 = V_174 ;
if ( F_48 (
& V_211 ) ) {
V_211 . V_202 = NULL ;
V_211 . V_201 = 0 ;
F_47 ( V_202 ) ;
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
return - V_128 ;
}
V_211 . V_202 = NULL ;
V_211 . V_201 = 0 ;
}
switch ( F_49 ( V_202 , V_201 ) ) {
case 0x02 :
V_213 -> V_216 |= V_170 ;
break;
case 0x03 :
V_213 -> V_217 |= V_170 ;
break;
}
V_213 -> V_210 |= V_170 ;
if ( V_202 != V_33 -> V_202 )
F_47 ( V_202 ) ;
}
return 0 ;
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
if ( V_34 == - V_189 )
continue;
F_3 ( V_7 , V_31 -> V_2 ,
L_27
L_28 , V_34 ) ;
break;
}
memcpy ( V_33 -> V_202 , V_29 -> V_169 ,
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
} else if ( V_34 == - V_189 ) {
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
V_211 . V_202 = ( void * ) & V_224 ;
V_211 . V_201 = V_174 ;
if ( F_48 ( & V_211 ) ) {
V_211 . V_202 = NULL ;
V_211 . V_201 = 0 ;
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
V_29 = F_64 ( sizeof( * V_29 ) , V_233 | V_197 ) ;
if ( ! V_29 ) {
if ( F_65 ( & V_232 ) ) {
V_29 = V_234 ;
V_29 -> V_231 = 1 ;
} else
return - V_198 ;
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
if ( F_73 ( V_31 , V_254 )
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
int V_34 , V_200 ;
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
V_33 = F_42 ( sizeof( * V_33 ) , V_196 | V_197 ) ;
if ( ! V_33 ) {
F_54 ( & V_31 -> V_2 -> V_82 ,
L_49
L_50 ) ;
return - V_198 ;
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
for ( V_200 = 0 ; V_200 < V_33 -> V_155 -> V_278 . V_271 ; V_200 ++ )
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
F_47 ( V_33 -> V_202 ) ;
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
V_33 -> V_201 = 0 ;
F_47 ( V_33 -> V_202 ) ;
V_33 -> V_202 = NULL ;
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
int V_200 ;
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
for ( V_200 = 0 ; V_200 < 4 ; V_200 ++ ) {
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
V_300 -> V_192 = F_92 ;
V_300 -> V_309 = NULL ;
V_300 -> V_179 = 5 * V_180 ;
F_39 ( V_190 , & V_300 -> V_43 ) ;
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
int V_183 , V_200 ;
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
for ( V_200 = 0 ; V_200 < 3 ; V_200 ++ ) {
if ( V_33 -> V_299 [ V_200 ] . V_16 != 4 ||
V_33 -> V_299 [ V_200 ] . V_17 != F_23 ( V_200 ) - 4 ) {
V_33 -> V_85 = 0 ;
break;
}
}
if ( V_200 == 3 )
V_299 = & V_33 -> V_299 [ 4 ] ;
if ( V_33 -> V_85 == 0 ) {
for ( V_200 = 0 ; V_200 < 5 ; V_200 ++ ) {
if ( ( V_33 -> V_299 [ V_200 ] . V_16 != 0 ) ||
( V_33 -> V_299 [ V_200 ] . V_17 !=
V_33 -> V_299 [ 0 ] . V_17 ) )
break;
}
if ( V_200 == 5 )
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
V_178 -> V_317 = ( V_33 -> V_90 *
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
F_102 ( & V_31 -> V_318 ) ;
F_102 ( & V_31 -> V_253 ) ;
return F_103 ( V_31 ) ;
}
static int
F_104 ( struct V_268 * V_178 , struct V_319 * V_22 )
{
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_178 -> V_281 -> V_33 ;
if ( F_97 ( V_178 -> V_311 ) == 0 ) {
V_22 -> V_320 = F_9 ( & V_33 -> V_35 ,
0 , V_178 -> V_311 ) ;
}
V_22 -> V_321 = V_33 -> V_35 . V_286 ;
V_22 -> V_51 = V_33 -> V_35 . V_86 ;
return 0 ;
}
static struct V_167 *
F_105 ( struct V_30 * V_31 ,
struct V_322 * V_323 )
{
struct V_32 * V_33 ;
struct V_167 * V_324 ;
struct V_294 * V_325 ;
struct V_26 * V_45 ;
void * V_29 ;
int V_326 ;
struct V_21 V_327 ;
int V_297 , V_298 ;
int V_200 ;
int V_328 = 0 ;
int V_329 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_326 = F_9 ( & V_33 -> V_35 , 0 , V_323 -> V_121 ) ;
F_10 ( & V_327 ,
V_323 -> V_330 / V_33 -> V_35 . V_86 ,
V_323 -> V_330 % V_33 -> V_35 . V_86 ) ;
if ( V_323 -> V_330 >=
( V_33 -> V_90 * V_33 -> V_35 . V_86 ) ) {
F_54 ( & V_31 -> V_2 -> V_82 , L_69
L_70 , V_323 -> V_330 ) ;
return F_106 ( - V_128 ) ;
}
if ( V_323 -> V_330 > V_323 -> V_331 ) {
F_54 ( & V_31 -> V_2 -> V_82 , L_71
L_72 , V_323 -> V_330 ) ;
return F_106 ( - V_128 ) ;
}
if ( F_97 ( V_323 -> V_121 ) != 0 ) {
F_54 ( & V_31 -> V_2 -> V_82 ,
L_73 ,
V_323 -> V_121 ) ;
return F_106 ( - V_128 ) ;
}
if ( V_323 -> V_328 & 0x10 ) {
V_329 = 0 ;
V_328 = V_323 -> V_328 & ~ 0x10 ;
} else {
V_329 = 1 ;
V_328 = V_323 -> V_328 ;
}
switch ( V_328 ) {
case 0x00 :
case 0x08 :
V_297 = 2 + V_326 ;
V_298 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
V_326 * sizeof( struct V_294 ) ;
break;
case 0x01 :
case 0x09 :
V_297 = 3 + V_326 ;
V_298 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
sizeof( struct V_294 ) +
V_326 * sizeof( struct V_294 ) ;
break;
case 0x04 :
case 0x0c :
V_297 = 3 ;
V_298 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
sizeof( struct V_294 ) ;
break;
default:
F_54 ( & V_31 -> V_2 -> V_82 , L_74
L_75 , V_323 -> V_328 ) ;
return F_106 ( - V_128 ) ;
}
V_324 = F_43 ( V_176 , V_297 , V_298 , V_31 ) ;
if ( F_44 ( V_324 ) )
return V_324 ;
V_29 = V_324 -> V_29 ;
V_45 = V_324 -> V_171 ;
switch ( V_328 & ~ 0x08 ) {
case 0x00 :
F_13 ( V_45 ++ , (struct V_28 * ) V_29 ,
V_323 -> V_330 , V_323 -> V_330 ,
V_75 , V_31 ) ;
if ( V_329 )
( (struct V_28 * ) V_29 ) -> V_38 |= 0x04 ;
V_29 += sizeof( struct V_28 ) ;
V_45 [ - 1 ] . V_43 |= V_243 ;
V_126 ( V_45 ++ , (struct V_140 * ) V_29 ,
V_323 -> V_330 , 0 , V_326 ,
V_75 , V_31 ,
V_323 -> V_121 ) ;
V_29 += sizeof( struct V_140 ) ;
break;
case 0x01 :
F_13 ( V_45 ++ , (struct V_28 * ) V_29 ,
V_323 -> V_330 , V_323 -> V_330 ,
V_80 ,
V_31 ) ;
V_29 += sizeof( struct V_28 ) ;
V_45 [ - 1 ] . V_43 |= V_243 ;
V_126 ( V_45 ++ , (struct V_140 * ) V_29 ,
V_323 -> V_330 , 0 , V_326 + 1 ,
V_80 , V_31 ,
V_31 -> V_178 -> V_311 ) ;
V_29 += sizeof( struct V_140 ) ;
break;
case 0x04 :
F_13 ( V_45 ++ , (struct V_28 * ) V_29 ,
V_323 -> V_330 , V_323 -> V_330 ,
V_75 , V_31 ) ;
V_29 += sizeof( struct V_28 ) ;
V_45 [ - 1 ] . V_43 |= V_243 ;
V_126 ( V_45 ++ , (struct V_140 * ) V_29 ,
V_323 -> V_330 , 0 , 1 ,
V_75 , V_31 , 8 ) ;
V_29 += sizeof( struct V_140 ) ;
break;
}
if ( V_328 & 0x01 ) {
V_325 = (struct V_294 * ) V_29 ;
V_29 += sizeof( struct V_294 ) ;
V_325 -> V_23 = V_327 . V_23 ;
V_325 -> V_24 = V_327 . V_24 ;
V_325 -> V_117 = 0 ;
V_325 -> V_16 = 0 ;
V_325 -> V_17 = 8 ;
V_45 [ - 1 ] . V_43 |= V_243 ;
V_45 -> V_54 = V_80 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_325 ;
V_45 ++ ;
}
if ( ( V_328 & ~ 0x08 ) & 0x04 ) {
V_325 = (struct V_294 * ) V_29 ;
V_29 += sizeof( struct V_294 ) ;
V_325 -> V_23 = V_327 . V_23 ;
V_325 -> V_24 = V_327 . V_24 ;
V_325 -> V_117 = 1 ;
V_325 -> V_16 = 0 ;
V_325 -> V_17 = 0 ;
V_45 [ - 1 ] . V_43 |= V_243 ;
V_45 -> V_54 = V_75 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_325 ;
} else {
for ( V_200 = 0 ; V_200 < V_326 ; V_200 ++ ) {
V_325 = (struct V_294 * ) V_29 ;
V_29 += sizeof( struct V_294 ) ;
V_325 -> V_23 = V_327 . V_23 ;
V_325 -> V_24 = V_327 . V_24 ;
V_325 -> V_117 = V_200 + 1 ;
V_325 -> V_16 = 0 ;
V_325 -> V_17 = V_323 -> V_121 ;
if ( ( V_328 & 0x08 ) &&
V_323 -> V_330 == 0 ) {
if ( V_200 < 3 ) {
V_325 -> V_16 = 4 ;
V_325 -> V_17 = V_147 [ V_200 ] - 4 ;
}
}
if ( ( V_328 & 0x08 ) &&
V_323 -> V_330 == 1 ) {
V_325 -> V_16 = 44 ;
V_325 -> V_17 = V_148 - 44 ;
}
V_45 [ - 1 ] . V_43 |= V_243 ;
V_45 -> V_54 = V_75 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_325 ;
V_45 ++ ;
}
}
V_324 -> V_119 = V_31 ;
V_324 -> V_177 = V_31 ;
V_324 -> V_181 = 256 ;
V_324 -> V_182 = F_33 () ;
V_324 -> V_183 = V_184 ;
return V_324 ;
}
static void F_107 ( struct V_167 * V_168 )
{
V_168 -> V_183 = V_184 ;
if ( V_168 -> V_178 && ( V_168 -> V_119 != V_168 -> V_178 -> V_281 ) ) {
F_108 ( V_168 ) ;
V_168 -> V_119 = V_168 -> V_178 -> V_281 ;
V_168 -> V_170 = V_168 -> V_178 -> V_281 -> V_213 . V_210 ;
}
}
static T_5
F_109 ( struct V_167 * V_168 )
{
struct V_30 * V_31 = (struct V_30 * ) V_168 -> V_119 ;
struct V_1 * V_2 = V_31 -> V_2 ;
switch ( V_2 -> V_332 . V_84 ) {
case 0x3990 :
case 0x2105 :
case 0x2107 :
case 0x1750 :
return V_333 ;
case 0x9343 :
case 0x3880 :
default:
return V_334 ;
}
}
static T_5
F_110 ( struct V_167 * V_168 )
{
return V_335 ;
}
static void F_111 ( struct V_30 * V_31 ,
struct V_167 * V_168 ,
struct V_305 * V_305 )
{
char V_66 ;
char * V_301 = NULL ;
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_66 = V_336 | V_337 | V_338 ;
if ( ( F_112 ( & V_305 -> V_339 ) & V_66 ) == V_66 ) {
if ( ! V_31 -> V_178 && V_33 -> V_340 &&
V_31 -> V_256 == V_257 &&
! F_58 ( V_255 , & V_31 -> V_43 ) &&
! F_58 ( V_228 , & V_31 -> V_43 ) ) {
F_103 ( V_31 ) ;
F_113 ( V_31 ) ;
}
F_114 ( V_31 ) ;
return;
}
V_301 = F_91 ( V_305 ) ;
if ( ! V_301 )
return;
if ( ( V_301 [ 27 ] & V_341 ) && ( V_301 [ 7 ] == 0x0D ) &&
( F_112 ( & V_305 -> V_339 ) & V_342 ) ) {
F_115 ( V_31 , V_305 ) ;
return;
}
if ( ! V_168 && ! ( V_301 [ 27 ] & V_341 ) &&
( ( V_301 [ 6 ] & V_343 ) == V_343 ) ) {
F_116 ( V_31 , V_301 ) ;
return;
}
if ( V_31 -> V_178 && ( V_301 [ 27 ] & V_341 ) &&
( V_301 [ 7 ] == 0x3F ) &&
( F_112 ( & V_305 -> V_339 ) & V_342 ) &&
F_58 ( V_344 , & V_31 -> V_43 ) ) {
if ( V_31 -> V_238 & V_345 )
F_34 ( V_346 , & V_31 -> V_43 ) ;
F_39 ( V_344 , & V_31 -> V_43 ) ;
F_15 ( & V_31 -> V_2 -> V_82 ,
L_76 ) ;
}
}
static struct V_167 * F_117 (
struct V_30 * V_119 ,
struct V_268 * V_178 ,
struct V_347 * V_348 ,
T_6 V_349 ,
T_6 V_350 ,
T_6 V_351 ,
T_6 V_352 ,
unsigned int V_353 ,
unsigned int V_354 ,
unsigned int V_145 ,
unsigned int V_121 )
{
struct V_32 * V_33 ;
unsigned long * V_355 ;
struct V_140 * V_296 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
struct V_356 V_357 ;
struct V_358 * V_359 ;
char * V_360 ;
unsigned int V_361 ;
int V_42 , V_362 , V_297 , V_298 ;
T_6 V_146 ;
unsigned char V_48 , V_363 ;
int V_364 ;
struct V_30 * V_118 ;
V_118 = V_178 -> V_281 ;
V_33 = (struct V_32 * ) V_118 -> V_33 ;
if ( F_118 ( V_348 ) == V_365 )
V_48 = V_60 ;
else if ( F_118 ( V_348 ) == V_366 )
V_48 = V_72 ;
else
return F_106 ( - V_128 ) ;
V_42 = 0 ;
V_362 = 0 ;
F_119 (bv, req, iter) {
if ( V_359 -> V_367 & ( V_121 - 1 ) )
return F_106 ( - V_128 ) ;
V_42 += V_359 -> V_367 >> ( V_178 -> V_314 + 9 ) ;
#if F_77 ( V_258 )
if ( F_120 ( F_121 ( V_359 -> V_368 ) , V_359 -> V_367 ) )
V_362 += V_359 -> V_367 >> ( V_178 -> V_314 + 9 ) ;
#endif
}
if ( V_42 != V_350 - V_349 + 1 )
return F_106 ( - V_128 ) ;
V_364 = V_33 -> V_238 . V_267 [ 8 ] & 0x01 ;
if ( V_364 ) {
V_297 = 2 + V_42 ;
V_298 = sizeof( struct V_93 ) +
sizeof( struct V_140 ) +
V_362 * sizeof( unsigned long ) ;
} else {
V_297 = 2 + V_42 ;
V_298 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
V_362 * sizeof( unsigned long ) ;
}
if ( V_33 -> V_85 && V_349 < 2 * V_145 ) {
if ( V_350 >= 2 * V_145 )
V_42 = 2 * V_145 - V_349 ;
V_297 += V_42 ;
V_298 += V_42 * sizeof( struct V_140 ) ;
}
V_168 = F_43 ( V_176 , V_297 , V_298 ,
V_119 ) ;
if ( F_44 ( V_168 ) )
return V_168 ;
V_45 = V_168 -> V_171 ;
if ( V_364 ) {
if ( F_21 ( V_45 ++ , V_168 -> V_29 , V_351 ,
V_352 , V_48 , V_118 , V_119 ) == - V_230 ) {
F_46 ( V_168 , V_119 ) ;
return F_106 ( - V_230 ) ;
}
V_355 = ( unsigned long * ) ( V_168 -> V_29 +
sizeof( struct V_93 ) ) ;
} else {
if ( F_13 ( V_45 ++ , V_168 -> V_29 , V_351 ,
V_352 , V_48 , V_118 ) == - V_230 ) {
F_46 ( V_168 , V_119 ) ;
return F_106 ( - V_230 ) ;
}
V_355 = ( unsigned long * ) ( V_168 -> V_29 +
sizeof( struct V_28 ) ) ;
}
V_296 = (struct V_140 * ) ( V_355 + V_362 ) ;
V_146 = V_349 ;
if ( V_33 -> V_85 == 0 || V_146 > 2 * V_145 ) {
V_45 [ - 1 ] . V_43 |= V_243 ;
V_126 ( V_45 ++ , V_296 ++ , V_351 , V_353 + 1 ,
V_350 - V_146 + 1 , V_48 , V_118 , V_121 ) ;
}
F_119 (bv, req, iter) {
V_360 = F_121 ( V_359 -> V_368 ) + V_359 -> V_369 ;
if ( V_370 ) {
char * V_371 = F_122 ( V_370 ,
V_197 | V_372 ) ;
if ( V_371 && F_118 ( V_348 ) == V_366 )
memcpy ( V_371 + V_359 -> V_369 , V_360 , V_359 -> V_367 ) ;
if ( V_371 )
V_360 = V_371 + V_359 -> V_369 ;
}
for ( V_361 = 0 ; V_361 < V_359 -> V_367 ; V_361 += V_121 ) {
T_6 V_373 = V_146 ;
unsigned int V_374 = F_123 ( V_373 , V_145 ) ;
V_363 = V_48 ;
V_42 = V_121 ;
if ( V_33 -> V_85 && V_146 < 2 * V_145 ) {
if ( F_22 ( V_145 , V_146 ) ) {
V_363 |= 0x8 ;
V_42 = F_23 ( V_146 ) ;
if ( V_42 < V_121 &&
F_118 ( V_348 ) == V_365 )
memset ( V_360 + V_42 , 0xe5 ,
V_121 - V_42 ) ;
}
V_45 [ - 1 ] . V_43 |= V_243 ;
V_126 ( V_45 ++ , V_296 ++ ,
V_373 , V_374 + 1 ,
1 , V_363 , V_118 , V_42 ) ;
}
if ( V_33 -> V_85 && V_146 == 2 * V_145 ) {
V_45 [ - 1 ] . V_43 |= V_243 ;
V_126 ( V_45 ++ , V_296 ++ ,
V_373 , V_374 + 1 ,
V_350 - V_146 + 1 ,
V_48 , V_118 , V_42 ) ;
}
V_45 [ - 1 ] . V_43 |= V_243 ;
V_45 -> V_54 = V_363 ;
V_45 -> V_42 = V_42 ;
if ( F_120 ( V_360 , V_121 ) ) {
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_355 ;
V_45 -> V_43 = V_375 ;
V_355 = F_124 ( V_355 , V_360 , V_121 ) ;
} else {
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_360 ;
V_45 -> V_43 = 0 ;
}
V_45 ++ ;
V_360 += V_121 ;
V_146 ++ ;
}
}
if ( F_125 ( V_348 ) ||
V_178 -> V_281 -> V_238 & V_376 )
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
static struct V_167 * F_126 (
struct V_30 * V_119 ,
struct V_268 * V_178 ,
struct V_347 * V_348 ,
T_6 V_349 ,
T_6 V_350 ,
T_6 V_351 ,
T_6 V_352 ,
unsigned int V_353 ,
unsigned int V_354 ,
unsigned int V_145 ,
unsigned int V_121 )
{
unsigned long * V_355 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
struct V_356 V_357 ;
struct V_358 * V_359 ;
char * V_360 , * V_377 ;
unsigned int V_362 , V_297 , V_298 ;
unsigned int V_100 ;
T_6 V_146 ;
unsigned char V_48 ;
struct V_30 * V_118 ;
unsigned int V_378 , V_42 , V_379 ;
unsigned int V_380 , V_381 , V_382 , V_383 ;
unsigned char V_384 , V_385 ;
T_6 V_373 ;
unsigned int V_374 ;
V_118 = V_178 -> V_281 ;
if ( F_118 ( V_348 ) == V_365 )
V_48 = V_113 ;
else if ( F_118 ( V_348 ) == V_366 )
V_48 = V_111 ;
else
return F_106 ( - V_128 ) ;
V_362 = V_350 - V_349 + 1 ;
V_378 = V_352 - V_351 + 1 ;
V_297 = 1 + V_378 ;
V_298 = sizeof( struct V_93 ) +
V_362 * sizeof( unsigned long long ) ;
V_168 = F_43 ( V_176 , V_297 , V_298 ,
V_119 ) ;
if ( F_44 ( V_168 ) )
return V_168 ;
V_45 = V_168 -> V_171 ;
if ( V_351 == V_352 )
V_100 = V_354 - V_353 + 1 ;
else
V_100 = V_354 + 1 ;
V_100 *= V_121 ;
if ( F_20 ( V_45 ++ , V_168 -> V_29 , V_351 ,
V_352 , V_48 , V_118 , V_119 ,
1 , V_353 + 1 ,
V_378 , V_121 ,
V_100 ) == - V_230 ) {
F_46 ( V_168 , V_119 ) ;
return F_106 ( - V_230 ) ;
}
V_355 = ( unsigned long * ) ( V_168 -> V_29 + sizeof( struct V_93 ) ) ;
V_146 = V_349 ;
V_384 = 1 ;
V_385 = 0 ;
V_383 = 0 ;
V_377 = NULL ;
V_380 = 0 ;
F_119 (bv, req, iter) {
V_360 = F_121 ( V_359 -> V_368 ) + V_359 -> V_369 ;
V_381 = V_359 -> V_367 ;
while ( V_381 ) {
if ( V_384 ) {
V_373 = V_146 ;
V_374 = F_123 ( V_373 , V_145 ) ;
V_379 = V_145 - V_374 ;
V_42 = F_127 ( ( V_350 - V_146 + 1 ) ,
( T_6 ) V_379 ) ;
V_383 = V_42 * V_121 ;
V_45 [ - 1 ] . V_43 |= V_243 ;
V_45 -> V_54 = V_48 ;
V_45 -> V_42 = V_383 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_355 ;
V_45 -> V_43 = V_375 ;
V_45 ++ ;
V_146 += V_42 ;
V_384 = 0 ;
if ( ! V_377 )
V_377 = V_360 ;
}
if ( ! V_377 ) {
if ( F_14 ( V_360 ) & ( V_386 - 1 ) ) {
F_46 ( V_168 , V_119 ) ;
return F_106 ( - V_387 ) ;
} else
V_377 = V_360 ;
}
if ( ( V_377 + V_380 ) != V_360 ) {
F_46 ( V_168 , V_119 ) ;
return F_106 ( - V_387 ) ;
}
V_382 = F_127 ( V_381 , V_383 ) ;
V_381 -= V_382 ;
V_360 += V_382 ;
V_380 += V_382 ;
V_383 -= V_382 ;
if ( ! ( F_14 ( V_377 + V_380 ) & ( V_386 - 1 ) ) )
V_385 = 1 ;
if ( ! V_383 ) {
V_384 = 1 ;
V_385 = 1 ;
}
if ( V_385 ) {
V_355 = F_124 ( V_355 , V_377 ,
V_380 ) ;
V_377 = NULL ;
V_380 = 0 ;
V_385 = 0 ;
}
}
}
if ( F_125 ( V_348 ) ||
V_178 -> V_281 -> V_238 & V_376 )
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
static int F_128 ( struct V_388 * V_388 ,
unsigned int V_46 , unsigned int V_47 , int V_48 ,
struct V_30 * V_118 ,
struct V_30 * V_119 ,
unsigned int V_98 , int V_42 ,
unsigned int V_121 ,
unsigned int V_389 ,
unsigned int V_100 ,
unsigned int V_145 )
{
struct V_93 V_94 ;
struct V_32 * V_122 , * V_123 ;
struct V_28 * V_124 ;
struct V_97 * V_125 ;
struct V_390 * V_390 ;
T_3 V_49 , V_50 ;
T_4 V_51 , V_52 , V_53 ;
T_7 V_391 ;
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
V_125 -> V_104 . V_392 = 0x01 ;
V_391 = V_393 ;
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
V_125 -> V_104 . V_392 = 0x2 ;
V_391 = V_127 ;
break;
default:
F_18 ( V_114 , V_118 ,
L_77 , V_48 ) ;
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
V_124 -> V_394 = 0x20 ;
V_124 -> V_395 = V_145 ;
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
V_125 -> V_104 . V_396 = 1 ;
V_125 -> V_104 . V_397 = 1 ;
V_125 -> V_106 = V_100 ;
V_125 -> V_398 = V_48 ;
V_125 -> V_42 = V_42 ;
V_125 -> V_101 = V_101 ;
F_10 ( & V_125 -> V_115 , V_49 , V_52 ) ;
V_125 -> V_116 . V_23 = V_125 -> V_115 . V_23 ;
V_125 -> V_116 . V_24 = V_125 -> V_115 . V_24 ;
V_125 -> V_116 . V_117 = V_98 ;
V_390 = F_129 ( V_388 , V_391 , 0 ,
& V_94 , sizeof( V_94 ) , V_389 ) ;
return F_44 ( V_390 ) ? F_69 ( V_390 ) : 0 ;
}
static struct V_167 * F_130 (
struct V_30 * V_119 ,
struct V_268 * V_178 ,
struct V_347 * V_348 ,
T_6 V_349 ,
T_6 V_350 ,
T_6 V_351 ,
T_6 V_352 ,
unsigned int V_353 ,
unsigned int V_354 ,
unsigned int V_145 ,
unsigned int V_121 )
{
struct V_167 * V_168 ;
struct V_356 V_357 ;
struct V_358 * V_359 ;
char * V_360 ;
unsigned int V_378 , V_399 ;
unsigned char V_48 ;
struct V_30 * V_118 ;
unsigned int V_100 ;
struct V_388 * V_388 ;
struct V_400 * V_401 = NULL ;
int V_402 ;
T_8 V_403 ;
T_7 V_404 ;
unsigned int V_381 , V_382 , V_383 ;
unsigned char V_384 ;
T_6 V_146 , V_373 ;
unsigned int V_405 ;
unsigned int V_42 , V_379 ;
int V_3 ;
V_118 = V_178 -> V_281 ;
if ( F_118 ( V_348 ) == V_365 ) {
V_48 = V_113 ;
V_402 = V_406 ;
} else if ( F_118 ( V_348 ) == V_366 ) {
V_48 = V_111 ;
V_402 = V_407 ;
} else
return F_106 ( - V_128 ) ;
V_378 = V_352 - V_351 + 1 ;
V_399 = 0 ;
F_119 (bv, req, iter) {
++ V_399 ;
}
if ( F_118 ( V_348 ) == V_366 )
V_399 += ( V_352 - V_351 ) ;
V_403 = F_131 ( 0 , V_399 , 0 ) ;
V_168 = F_43 ( V_176 , 0 , V_403 , V_119 ) ;
if ( F_44 ( V_168 ) )
return V_168 ;
if ( V_351 == V_352 )
V_100 = V_354 - V_353 + 1 ;
else
V_100 = V_354 + 1 ;
V_100 *= V_121 ;
V_388 = F_132 ( V_168 -> V_29 , V_403 , V_402 , 0 , V_399 , 0 ) ;
if ( F_44 ( V_388 ) ) {
V_3 = - V_128 ;
goto V_195;
}
V_168 -> V_171 = F_133 ( V_388 ) ;
if ( F_128 ( V_388 , V_351 , V_352 ,
V_48 , V_118 , V_119 ,
V_353 + 1 ,
V_378 , V_121 ,
( V_350 - V_349 + 1 ) * V_121 ,
V_100 , V_145 ) == - V_230 ) {
V_3 = - V_230 ;
goto V_195;
}
V_383 = 0 ;
if ( F_118 ( V_348 ) == V_366 ) {
V_384 = 1 ;
V_146 = V_349 ;
F_119 (bv, req, iter) {
V_360 = F_121 ( V_359 -> V_368 ) + V_359 -> V_369 ;
V_381 = V_359 -> V_367 ;
while ( V_381 ) {
if ( V_384 ) {
V_373 = V_146 ;
V_405 = F_123 ( V_373 , V_145 ) ;
V_379 = V_145 - V_405 ;
V_42 = F_127 ( ( V_350 - V_146 + 1 ) ,
( T_6 ) V_379 ) ;
V_383 = V_42 * V_121 ;
V_146 += V_42 ;
V_384 = 0 ;
}
V_382 = F_127 ( V_381 , V_383 ) ;
V_381 -= V_382 ;
V_383 -= V_382 ;
if ( ! V_383 ) {
V_384 = 1 ;
V_404 = V_408 ;
} else
V_404 = 0 ;
V_401 = F_134 ( V_388 , V_404 ,
V_360 , V_382 ) ;
if ( F_44 ( V_401 ) ) {
V_3 = - V_128 ;
goto V_195;
}
V_360 += V_382 ;
}
}
} else {
F_119 (bv, req, iter) {
V_360 = F_121 ( V_359 -> V_368 ) + V_359 -> V_369 ;
V_401 = F_134 ( V_388 , 0x00 ,
V_360 , V_359 -> V_367 ) ;
if ( F_44 ( V_401 ) ) {
V_3 = - V_128 ;
goto V_195;
}
}
}
V_401 -> V_43 |= V_409 ;
V_401 -> V_43 &= ~ V_408 ;
F_135 ( V_388 ) ;
if ( F_125 ( V_348 ) ||
V_178 -> V_281 -> V_238 & V_376 )
F_34 ( V_254 , & V_168 -> V_43 ) ;
V_168 -> V_410 = 1 ;
V_168 -> V_119 = V_119 ;
V_168 -> V_177 = V_119 ;
V_168 -> V_178 = V_178 ;
V_168 -> V_179 = V_119 -> V_276 * V_180 ;
V_168 -> V_170 = V_119 -> V_213 . V_217 ;
V_168 -> V_181 = 256 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
return V_168 ;
V_195:
F_46 ( V_168 , V_119 ) ;
return F_106 ( V_3 ) ;
}
static struct V_167 * F_136 ( struct V_30 * V_119 ,
struct V_268 * V_178 ,
struct V_347 * V_348 )
{
int V_411 , V_412 ;
int V_364 ;
int V_413 ;
struct V_32 * V_33 ;
struct V_30 * V_118 ;
T_6 V_349 , V_350 ;
T_6 V_351 , V_352 ;
unsigned int V_353 , V_354 ;
unsigned int V_145 , V_121 ;
int V_414 ;
unsigned int V_415 ;
struct V_167 * V_168 ;
V_118 = V_178 -> V_281 ;
V_33 = (struct V_32 * ) V_118 -> V_33 ;
V_121 = V_178 -> V_311 ;
V_145 = F_9 ( & V_33 -> V_35 , 0 , V_121 ) ;
if ( V_145 == 0 )
return F_106 ( - V_128 ) ;
V_349 = V_351 = F_137 ( V_348 ) >> V_178 -> V_314 ;
V_353 = F_123 ( V_351 , V_145 ) ;
V_350 = V_352 =
( F_137 ( V_348 ) + F_138 ( V_348 ) - 1 ) >> V_178 -> V_314 ;
V_354 = F_123 ( V_352 , V_145 ) ;
V_414 = ( V_33 -> V_85 && V_349 < 2 * V_145 ) ;
V_413 = V_33 -> V_238 . V_267 [ 40 ] & 0x20 ;
V_415 = F_139 ( V_348 ) ;
if ( F_118 ( V_348 ) == V_366 )
V_415 += ( V_352 - V_351 ) * 4 ;
V_411 = V_33 -> V_238 . V_267 [ 9 ] & 0x20 ;
V_412 = V_33 -> V_238 . V_267 [ 12 ] & 0x40 ;
V_364 = V_33 -> V_238 . V_267 [ 8 ] & 0x01 ;
V_168 = NULL ;
if ( V_414 || V_370 ) {
} else if ( ( V_415 <= V_33 -> V_219 )
&& ( V_413 || ( V_351 == V_352 ) ) ) {
V_168 = F_130 ( V_119 , V_178 , V_348 ,
V_349 , V_350 ,
V_351 , V_352 ,
V_353 , V_354 ,
V_145 , V_121 ) ;
if ( F_44 ( V_168 ) && ( F_69 ( V_168 ) != - V_230 ) &&
( F_69 ( V_168 ) != - V_198 ) )
V_168 = NULL ;
} else if ( V_364 &&
( ( ( F_118 ( V_348 ) == V_365 ) && V_411 ) ||
( ( F_118 ( V_348 ) == V_366 ) && V_412 ) ) ) {
V_168 = F_126 ( V_119 , V_178 , V_348 ,
V_349 , V_350 ,
V_351 , V_352 ,
V_353 , V_354 ,
V_145 , V_121 ) ;
if ( F_44 ( V_168 ) && ( F_69 ( V_168 ) != - V_230 ) &&
( F_69 ( V_168 ) != - V_198 ) )
V_168 = NULL ;
}
if ( ! V_168 )
V_168 = F_117 ( V_119 , V_178 , V_348 ,
V_349 , V_350 ,
V_351 , V_352 ,
V_353 , V_354 ,
V_145 , V_121 ) ;
return V_168 ;
}
static struct V_167 * F_140 ( struct V_30 * V_119 ,
struct V_268 * V_178 ,
struct V_347 * V_348 )
{
unsigned long * V_355 ;
struct V_30 * V_118 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
struct V_356 V_357 ;
struct V_358 * V_359 ;
char * V_360 ;
unsigned char V_48 ;
unsigned int V_378 ;
unsigned int V_381 , V_383 ;
unsigned int V_353 ;
unsigned int V_362 , V_297 , V_298 ;
T_6 V_351 , V_352 ;
unsigned int V_416 ;
if ( ( F_137 ( V_348 ) % V_417 ) != 0 ) {
V_168 = F_106 ( - V_128 ) ;
goto V_418;
}
if ( ( ( F_137 ( V_348 ) + F_138 ( V_348 ) ) %
V_417 ) != 0 ) {
V_168 = F_106 ( - V_128 ) ;
goto V_418;
}
V_351 = F_137 ( V_348 ) / V_417 ;
V_352 = ( F_137 ( V_348 ) + F_138 ( V_348 ) - 1 ) /
V_417 ;
V_378 = V_352 - V_351 + 1 ;
V_353 = 0 ;
V_118 = V_178 -> V_281 ;
if ( F_118 ( V_348 ) == V_365 )
V_48 = V_112 ;
else if ( F_118 ( V_348 ) == V_366 )
V_48 = V_107 ;
else {
V_168 = F_106 ( - V_128 ) ;
goto V_418;
}
V_362 = V_378 * V_313 ;
V_297 = 1 + V_378 ;
V_416 = sizeof( struct V_93 ) + 8 ;
V_298 = V_416 + V_362 * sizeof( unsigned long long ) ;
V_168 = F_43 ( V_176 , V_297 ,
V_298 , V_119 ) ;
if ( F_44 ( V_168 ) )
goto V_418;
V_45 = V_168 -> V_171 ;
if ( F_20 ( V_45 ++ , V_168 -> V_29 , V_351 , V_352 , V_48 ,
V_118 , V_119 , 1 , V_353 + 1 ,
V_378 , 0 , 0 ) == - V_230 ) {
F_46 ( V_168 , V_119 ) ;
V_168 = F_106 ( - V_230 ) ;
goto V_418;
}
V_355 = ( unsigned long * ) ( V_168 -> V_29 + V_416 ) ;
V_383 = 0 ;
F_119 (bv, req, iter) {
V_360 = F_121 ( V_359 -> V_368 ) + V_359 -> V_369 ;
V_381 = V_359 -> V_367 ;
if ( ! V_383 ) {
V_45 [ - 1 ] . V_43 |= V_243 ;
V_45 -> V_54 = V_48 ;
V_45 -> V_42 = 57326 ;
V_383 = 65536 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_355 ;
V_45 -> V_43 |= V_375 ;
V_45 -> V_43 |= V_44 ;
V_45 ++ ;
}
V_383 -= V_381 ;
V_355 = F_124 ( V_355 , V_360 , V_381 ) ;
}
if ( F_125 ( V_348 ) ||
V_178 -> V_281 -> V_238 & V_376 )
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
V_418:
return V_168 ;
}
static int
F_141 ( struct V_167 * V_168 , struct V_347 * V_348 )
{
struct V_32 * V_33 ;
struct V_26 * V_45 ;
struct V_356 V_357 ;
struct V_358 * V_359 ;
char * V_360 , * V_56 ;
unsigned int V_121 , V_145 , V_361 ;
T_6 V_146 ;
int V_183 ;
if ( ! V_370 )
goto V_418;
V_33 = (struct V_32 * ) V_168 -> V_178 -> V_281 -> V_33 ;
V_121 = V_168 -> V_178 -> V_311 ;
V_145 = F_9 ( & V_33 -> V_35 , 0 , V_121 ) ;
V_146 = F_137 ( V_348 ) >> V_168 -> V_178 -> V_314 ;
V_45 = V_168 -> V_171 ;
V_45 ++ ;
if ( V_33 -> V_85 == 0 || V_146 > 2 * V_145 )
V_45 ++ ;
F_119 (bv, req, iter) {
V_360 = F_121 ( V_359 -> V_368 ) + V_359 -> V_369 ;
for ( V_361 = 0 ; V_361 < V_359 -> V_367 ; V_361 += V_121 ) {
if ( V_33 -> V_85 && V_146 <= 2 * V_145 )
V_45 ++ ;
if ( V_360 ) {
if ( V_45 -> V_43 & V_375 )
V_56 = * ( ( char * * ) ( ( V_173 ) V_45 -> V_56 ) ) ;
else
V_56 = ( char * ) ( ( V_173 ) V_45 -> V_56 ) ;
if ( V_360 != V_56 ) {
if ( F_118 ( V_348 ) == V_365 )
memcpy ( V_360 , V_56 , V_359 -> V_367 ) ;
F_142 ( V_370 ,
( void * ) ( ( V_173 ) V_56 & V_419 ) ) ;
}
V_360 = NULL ;
}
V_45 ++ ;
V_146 ++ ;
}
}
V_418:
V_183 = V_168 -> V_183 == V_186 ;
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_183 ;
}
void F_108 ( struct V_167 * V_168 )
{
struct V_26 * V_45 ;
struct V_93 * V_94 ;
struct V_420 * V_420 ;
struct V_421 * V_421 ;
struct V_390 * V_390 ;
if ( V_168 -> V_410 == 1 ) {
V_420 = V_168 -> V_171 ;
V_421 = F_143 ( V_420 ) ;
V_390 = (struct V_390 * ) & V_421 -> V_422 [ 0 ] ;
V_94 = (struct V_93 * ) & V_390 -> V_423 [ 0 ] ;
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
static struct V_167 * F_144 ( struct V_30 * V_281 ,
struct V_268 * V_178 ,
struct V_347 * V_348 )
{
struct V_32 * V_33 ;
struct V_30 * V_119 ;
unsigned long V_43 ;
struct V_167 * V_168 ;
V_119 = F_145 ( V_281 ) ;
if ( ! V_119 )
V_119 = V_281 ;
V_33 = (struct V_32 * ) V_119 -> V_33 ;
if ( V_33 -> V_42 >= V_424 )
return F_106 ( - V_425 ) ;
F_27 ( F_28 ( V_119 -> V_2 ) , V_43 ) ;
V_33 -> V_42 ++ ;
if ( ( V_281 -> V_238 & V_284 ) )
V_168 = F_140 ( V_119 , V_178 , V_348 ) ;
else
V_168 = F_136 ( V_119 , V_178 , V_348 ) ;
if ( F_44 ( V_168 ) )
V_33 -> V_42 -- ;
F_29 ( F_28 ( V_119 -> V_2 ) , V_43 ) ;
return V_168 ;
}
static int F_146 ( struct V_167 * V_168 ,
struct V_347 * V_348 )
{
struct V_32 * V_33 ;
unsigned long V_43 ;
F_27 ( F_28 ( V_168 -> V_177 -> V_2 ) , V_43 ) ;
V_33 = (struct V_32 * ) V_168 -> V_177 -> V_33 ;
V_33 -> V_42 -- ;
F_29 ( F_28 ( V_168 -> V_177 -> V_2 ) , V_43 ) ;
return F_141 ( V_168 , V_348 ) ;
}
static int
F_147 ( struct V_30 * V_31 ,
struct V_426 * V_427 )
{
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_427 -> V_428 = 2 ;
V_427 -> V_429 = V_33 -> V_85 ? 0 : 1 ;
V_427 -> V_120 = V_33 -> V_85 ? V_430 : V_431 ;
V_427 -> V_432 = sizeof( struct V_14 ) ;
memcpy ( V_427 -> V_433 , & V_33 -> V_35 ,
sizeof( struct V_14 ) ) ;
V_427 -> V_434 = F_127 ( ( unsigned long ) V_33 -> V_201 ,
sizeof( V_427 -> V_435 ) ) ;
memcpy ( V_427 -> V_435 , V_33 -> V_202 ,
V_427 -> V_434 ) ;
return 0 ;
}
static int
F_148 ( struct V_30 * V_31 )
{
struct V_167 * V_168 ;
int V_34 ;
struct V_26 * V_45 ;
int V_436 ;
if ( ! F_149 ( V_437 ) )
return - V_41 ;
V_436 = 0 ;
V_168 = F_43 ( V_176 , 1 , 32 , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_150 ( & V_438 ) ;
V_436 = 1 ;
V_168 = & V_439 -> V_168 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
memset ( & V_439 -> V_45 , 0 ,
sizeof( V_439 -> V_45 ) ) ;
V_168 -> V_171 = & V_439 -> V_45 ;
V_168 -> V_29 = & V_439 -> V_29 ;
V_168 -> V_175 = V_176 ;
}
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_440 ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_42 = 32 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_168 -> V_29 ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
F_39 ( V_190 , & V_168 -> V_43 ) ;
F_34 ( V_254 , & V_168 -> V_43 ) ;
V_168 -> V_181 = 2 ;
V_168 -> V_179 = 2 * V_180 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_40 ( V_168 ) ;
if ( ! V_34 )
F_39 ( V_344 , & V_31 -> V_43 ) ;
if ( V_436 )
F_62 ( & V_438 ) ;
else
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int
F_151 ( struct V_30 * V_31 )
{
struct V_167 * V_168 ;
int V_34 ;
struct V_26 * V_45 ;
int V_436 ;
if ( ! F_149 ( V_437 ) )
return - V_41 ;
V_436 = 0 ;
V_168 = F_43 ( V_176 , 1 , 32 , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_150 ( & V_438 ) ;
V_436 = 1 ;
V_168 = & V_439 -> V_168 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
memset ( & V_439 -> V_45 , 0 ,
sizeof( V_439 -> V_45 ) ) ;
V_168 -> V_171 = & V_439 -> V_45 ;
V_168 -> V_29 = & V_439 -> V_29 ;
V_168 -> V_175 = V_176 ;
}
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_441 ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_42 = 32 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_168 -> V_29 ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
F_39 ( V_190 , & V_168 -> V_43 ) ;
F_34 ( V_254 , & V_168 -> V_43 ) ;
V_168 -> V_181 = 2 ;
V_168 -> V_179 = 2 * V_180 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_40 ( V_168 ) ;
if ( ! V_34 )
F_34 ( V_344 , & V_31 -> V_43 ) ;
if ( V_436 )
F_62 ( & V_438 ) ;
else
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int
F_152 ( struct V_30 * V_31 )
{
struct V_167 * V_168 ;
int V_34 ;
struct V_26 * V_45 ;
int V_436 ;
if ( ! F_149 ( V_437 ) )
return - V_41 ;
V_436 = 0 ;
V_168 = F_43 ( V_176 , 1 , 32 , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_150 ( & V_438 ) ;
V_436 = 1 ;
V_168 = & V_439 -> V_168 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
memset ( & V_439 -> V_45 , 0 ,
sizeof( V_439 -> V_45 ) ) ;
V_168 -> V_171 = & V_439 -> V_45 ;
V_168 -> V_29 = & V_439 -> V_29 ;
V_168 -> V_175 = V_176 ;
}
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_442 ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_42 = 32 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_168 -> V_29 ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
F_39 ( V_190 , & V_168 -> V_43 ) ;
F_34 ( V_254 , & V_168 -> V_43 ) ;
V_168 -> V_181 = 2 ;
V_168 -> V_179 = 2 * V_180 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_40 ( V_168 ) ;
if ( ! V_34 )
F_34 ( V_344 , & V_31 -> V_43 ) ;
if ( V_436 )
F_62 ( & V_438 ) ;
else
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int F_153 ( struct V_30 * V_31 ,
void T_9 * V_443 )
{
struct V_167 * V_168 ;
int V_34 ;
struct V_26 * V_45 ;
int V_436 ;
struct V_444 V_445 ;
if ( ! F_149 ( V_437 ) )
return - V_41 ;
if ( F_154 ( & V_445 , V_443 , sizeof( V_445 ) ) )
return - V_446 ;
V_436 = 0 ;
V_168 = F_43 ( V_176 , 1 ,
sizeof( struct V_447 ) , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_150 ( & V_438 ) ;
V_436 = 1 ;
V_168 = & V_439 -> V_168 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
memset ( & V_439 -> V_45 , 0 ,
sizeof( V_439 -> V_45 ) ) ;
V_168 -> V_171 = & V_439 -> V_45 ;
V_168 -> V_29 = & V_439 -> V_29 ;
V_168 -> V_175 = V_176 ;
}
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_448 ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_42 = 12 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_168 -> V_29 ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
F_39 ( V_190 , & V_168 -> V_43 ) ;
F_34 ( V_254 , & V_168 -> V_43 ) ;
F_34 ( V_191 , & V_168 -> V_43 ) ;
V_168 -> V_181 = 5 ;
V_168 -> V_179 = 10 * V_180 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_168 -> V_170 = V_445 . V_449 ;
V_34 = F_40 ( V_168 ) ;
if ( ! V_34 && V_445 . V_449 && ( V_168 -> V_170 != V_445 . V_449 ) )
V_34 = - V_272 ;
if ( ! V_34 ) {
V_445 . V_29 = * ( (struct V_447 * ) V_168 -> V_29 ) ;
if ( F_155 ( V_443 , & V_445 , sizeof( V_445 ) ) )
V_34 = - V_446 ;
}
if ( V_436 )
F_62 ( & V_438 ) ;
else
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int
F_156 ( struct V_30 * V_31 , void T_9 * V_443 )
{
struct V_235 * V_236 ;
struct V_450 * V_451 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
int V_34 ;
V_168 = F_43 ( V_176 , 1 + 1 ,
( sizeof( struct V_235 ) +
sizeof( struct V_450 ) ) ,
V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_18 ( V_7 , V_31 , L_1 ,
L_78 ) ;
return F_69 ( V_168 ) ;
}
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_181 = 0 ;
F_39 ( V_190 , & V_168 -> V_43 ) ;
V_168 -> V_179 = 10 * V_180 ;
V_236 = (struct V_235 * ) V_168 -> V_29 ;
memset ( V_236 , 0 , sizeof( struct V_235 ) ) ;
V_236 -> V_239 = V_240 ;
V_236 -> V_241 = 0x01 ;
V_236 -> V_452 [ 1 ] = 0x01 ;
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_242 ;
V_45 -> V_42 = sizeof( struct V_235 ) ;
V_45 -> V_43 |= V_243 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_236 ;
V_451 = (struct V_450 * ) ( V_236 + 1 ) ;
memset ( V_451 , 0 , sizeof( struct V_450 ) ) ;
V_45 ++ ;
V_45 -> V_54 = V_244 ;
V_45 -> V_42 = sizeof( struct V_450 ) ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_451 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_45 ( V_168 ) ;
if ( V_34 == 0 ) {
V_236 = (struct V_235 * ) V_168 -> V_29 ;
V_451 = (struct V_450 * ) ( V_236 + 1 ) ;
if ( F_155 ( V_443 , V_451 ,
sizeof( struct V_450 ) ) )
V_34 = - V_446 ;
}
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int
F_157 ( struct V_30 * V_31 , void T_9 * V_443 )
{
struct V_32 * V_33 =
(struct V_32 * ) V_31 -> V_33 ;
struct V_453 V_70 = V_33 -> V_70 ;
int V_34 ;
if ( ! F_149 ( V_437 ) )
return - V_41 ;
if ( ! V_443 )
return - V_128 ;
V_34 = 0 ;
if ( F_155 ( V_443 , ( long * ) & V_70 ,
sizeof( struct V_453 ) ) )
V_34 = - V_446 ;
return V_34 ;
}
static int
F_158 ( struct V_30 * V_31 , void T_9 * V_443 )
{
struct V_32 * V_33 =
(struct V_32 * ) V_31 -> V_33 ;
struct V_453 V_70 ;
if ( ! F_149 ( V_437 ) )
return - V_41 ;
if ( ! V_443 )
return - V_128 ;
if ( F_154 ( & V_70 , V_443 , sizeof( struct V_453 ) ) )
return - V_446 ;
V_33 -> V_70 = V_70 ;
F_81 ( & V_31 -> V_2 -> V_82 ,
L_79 ,
V_33 -> V_70 . V_69 , V_33 -> V_70 . V_89 ) ;
return 0 ;
}
static int F_159 ( struct V_30 * V_31 , void T_9 * V_443 )
{
struct V_454 V_445 ;
char * V_455 , * V_456 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
char V_457 , V_458 ;
int V_34 ;
if ( ! F_149 ( V_437 ) && ! F_149 ( V_459 ) )
return - V_41 ;
V_457 = V_458 = 0 ;
V_34 = - V_446 ;
if ( F_154 ( & V_445 , V_443 , sizeof( V_445 ) ) )
goto V_418;
if ( F_160 () || sizeof( long ) == 4 ) {
V_34 = - V_128 ;
if ( ( V_445 . V_455 >> 32 ) != 0 )
goto V_418;
if ( ( V_445 . V_456 >> 32 ) != 0 )
goto V_418;
V_445 . V_455 &= 0x7fffffffULL ;
V_445 . V_456 &= 0x7fffffffULL ;
}
V_455 = F_42 ( V_445 . V_460 , V_196 | V_197 ) ;
V_456 = F_42 ( V_445 . V_461 , V_196 | V_197 ) ;
if ( ! V_455 || ! V_456 ) {
V_34 = - V_198 ;
goto V_462;
}
V_34 = - V_446 ;
if ( F_154 ( V_455 ,
( void T_9 * ) ( unsigned long ) V_445 . V_455 ,
V_445 . V_460 ) )
goto V_462;
V_457 = V_455 [ 0 ] ;
V_458 = V_455 [ 1 ] ;
V_168 = F_43 ( V_176 , 2 , 0 , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_18 ( V_7 , V_31 , L_1 ,
L_78 ) ;
V_34 = F_69 ( V_168 ) ;
goto V_462;
}
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_181 = 3 ;
V_168 -> V_179 = 10 * V_180 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_242 ;
V_45 -> V_42 = V_445 . V_460 ;
V_45 -> V_43 |= V_243 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_455 ;
V_45 ++ ;
V_45 -> V_54 = V_244 ;
V_45 -> V_42 = V_445 . V_461 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_456 ;
V_34 = F_45 ( V_168 ) ;
if ( V_34 )
goto V_463;
V_34 = - V_446 ;
if ( F_155 ( ( void T_9 * ) ( unsigned long ) V_445 . V_456 ,
V_456 , V_445 . V_461 ) )
goto V_463;
V_34 = 0 ;
V_463:
F_46 ( V_168 , V_168 -> V_177 ) ;
V_462:
F_47 ( V_456 ) ;
F_47 ( V_455 ) ;
V_418:
F_18 ( V_7 , V_31 ,
L_80 ,
( int ) V_457 , ( int ) V_458 , V_34 ) ;
return V_34 ;
}
static int
F_161 ( struct V_268 * V_178 , unsigned int V_48 , void T_9 * V_443 )
{
struct V_30 * V_31 = V_178 -> V_281 ;
switch ( V_48 ) {
case V_464 :
return F_157 ( V_31 , V_443 ) ;
case V_465 :
return F_158 ( V_31 , V_443 ) ;
case V_466 :
return F_156 ( V_31 , V_443 ) ;
case V_467 :
return F_148 ( V_31 ) ;
case V_468 :
return F_151 ( V_31 ) ;
case V_469 :
return F_152 ( V_31 ) ;
case V_470 :
return F_153 ( V_31 , V_443 ) ;
case V_471 :
return F_159 ( V_31 , V_443 ) ;
default:
return - V_472 ;
}
}
static int
F_162 ( struct V_26 * V_473 , struct V_26 * V_474 , char * V_475 )
{
int V_476 , V_42 ;
char * V_477 ;
V_476 = 0 ;
while ( V_473 <= V_474 ) {
V_476 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_81 ,
from, ((int *) from)[0], ((int *) from)[1]) ;
if ( V_473 -> V_43 & V_375 )
V_477 = ( char * ) * ( ( V_173 * ) ( V_173 ) V_473 -> V_56 ) ;
else
V_477 = ( char * ) ( ( V_173 ) V_473 -> V_56 ) ;
for ( V_42 = 0 ; V_42 < V_473 -> V_42 && V_42 < 32 ; V_42 ++ ) {
if ( V_42 % 8 == 0 ) V_476 += sprintf ( V_475 + V_476 , L_82 ) ;
if ( V_42 % 4 == 0 ) V_476 += sprintf ( V_475 + V_476 , L_82 ) ;
V_476 += sprintf ( V_475 + V_476 , L_11 , V_477 [ V_42 ] ) ;
}
V_476 += sprintf ( V_475 + V_476 , L_83 ) ;
V_473 ++ ;
}
return V_476 ;
}
static void
F_163 ( struct V_30 * V_31 , struct V_305 * V_305 ,
char * V_478 )
{
T_10 * V_301 ;
T_10 * V_479 ;
V_301 = ( T_10 * ) F_91 ( V_305 ) ;
V_479 = ( T_10 * ) & V_305 -> V_339 ;
if ( V_301 ) {
F_18 ( V_480 , V_31 , L_84
L_85 ,
V_478 , * V_479 , * ( ( T_3 * ) ( V_479 + 1 ) ) ,
V_301 [ 0 ] , V_301 [ 1 ] , V_301 [ 2 ] , V_301 [ 3 ] ) ;
} else {
F_18 ( V_480 , V_31 , L_86 ,
V_478 , * V_479 , * ( ( T_3 * ) ( V_479 + 1 ) ) ,
L_87 ) ;
}
}
static void F_164 ( struct V_30 * V_31 ,
struct V_167 * V_348 , struct V_305 * V_305 )
{
char * V_475 ;
struct V_26 * V_481 , * V_482 , * V_483 , * V_473 , * V_474 ;
int V_476 , V_484 , V_485 ;
V_475 = ( char * ) F_165 ( V_233 ) ;
if ( V_475 == NULL ) {
F_18 ( V_7 , V_31 , L_1 ,
L_88 ) ;
return;
}
V_476 = sprintf (page, KERN_ERR PRINTK_HEADER
L_89 ,
dev_name(&device->cdev->dev)) ;
V_476 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_90
L_91 ,
req, scsw_cc(&irb->scsw), scsw_fctl(&irb->scsw),
scsw_actl(&irb->scsw), scsw_stctl(&irb->scsw),
scsw_dstat(&irb->scsw), scsw_cstat(&irb->scsw),
req ? req->intrc : 0 ) ;
V_476 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_92 ,
dev_name(&device->cdev->dev),
(void *) (addr_t) irb->scsw.cmd.cpa) ;
if ( V_305 -> V_486 . V_487 . V_488 . V_489 ) {
for ( V_484 = 0 ; V_484 < 4 ; V_484 ++ ) {
V_476 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_93 ,
(8 * sl), ((8 * sl) + 7)) ;
for ( V_485 = 0 ; V_485 < 8 ; V_485 ++ ) {
V_476 += sprintf ( V_475 + V_476 , L_94 ,
V_305 -> V_490 [ 8 * V_484 + V_485 ] ) ;
}
V_476 += sprintf ( V_475 + V_476 , L_83 ) ;
}
if ( V_305 -> V_490 [ 27 ] & V_341 ) {
sprintf (page + len, KERN_ERR PRINTK_HEADER
L_95
L_96 ,
irb->ecw[7] >> 4 , irb->ecw[7] & 0x0f ,
irb->ecw[1] & 0x10 ? L_59 : L_97 ) ;
} else {
sprintf (page + len, KERN_ERR PRINTK_HEADER
L_98
L_99 ,
irb->ecw[6] & 0x0f , irb->ecw[22] >> 4 ) ;
}
} else {
sprintf (page + len, KERN_ERR PRINTK_HEADER
L_100 ) ;
}
F_166 ( L_1 , V_475 ) ;
if ( V_348 ) {
V_481 = V_348 -> V_171 ;
for ( V_482 = V_481 ; V_482 -> V_43 & ( V_243 | V_491 ) ; V_482 ++ ) ;
V_474 = F_127 ( V_481 + 6 , V_482 ) ;
V_476 = sprintf (page, KERN_ERR PRINTK_HEADER
L_101 , req) ;
F_162 ( V_481 , V_474 , V_475 + V_476 ) ;
F_166 ( L_1 , V_475 ) ;
V_476 = 0 ;
V_473 = ++ V_474 ;
V_483 = (struct V_26 * ) ( V_173 )
V_305 -> V_339 . V_48 . V_492 ;
if ( V_473 < V_483 - 2 ) {
V_473 = V_483 - 2 ;
V_476 += sprintf (page, KERN_ERR PRINTK_HEADER L_102 ) ;
}
V_474 = F_127 ( V_483 + 1 , V_482 ) ;
V_476 += F_162 ( V_473 , V_474 , V_475 + V_476 ) ;
V_473 = F_167 ( V_473 , ++ V_474 ) ;
if ( V_473 < V_482 - 1 ) {
V_473 = V_482 - 1 ;
V_476 += sprintf (page + len, KERN_ERR PRINTK_HEADER L_102 ) ;
}
V_476 += F_162 ( V_473 , V_482 , V_475 + V_476 ) ;
if ( V_476 > 0 )
F_166 ( L_1 , V_475 ) ;
}
F_168 ( ( unsigned long ) V_475 ) ;
}
static void F_169 ( struct V_30 * V_31 ,
struct V_167 * V_348 , struct V_305 * V_305 )
{
char * V_475 ;
int V_476 , V_484 , V_485 , V_493 ;
struct V_494 * V_494 ;
T_7 * V_301 , * V_495 ;
V_475 = ( char * ) F_165 ( V_233 ) ;
if ( V_475 == NULL ) {
F_18 ( V_7 , V_31 , L_103 ,
L_104 ) ;
return;
}
V_476 = sprintf (page, KERN_ERR PRINTK_HEADER
L_89 ,
dev_name(&device->cdev->dev)) ;
V_476 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_90
L_105 ,
req, scsw_cc(&irb->scsw), scsw_fctl(&irb->scsw),
scsw_actl(&irb->scsw), scsw_stctl(&irb->scsw),
scsw_dstat(&irb->scsw), scsw_cstat(&irb->scsw),
irb->scsw.tm.fcxs, irb->scsw.tm.schxs,
req ? req->intrc : 0 ) ;
V_476 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_106 ,
dev_name(&device->cdev->dev),
(void *) (addr_t) irb->scsw.tm.tcw) ;
V_494 = NULL ;
V_301 = NULL ;
if ( V_305 -> V_339 . V_496 . V_420 && ( V_305 -> V_339 . V_496 . V_497 & 0x01 ) )
V_494 = F_170 (
(struct V_420 * ) ( unsigned long ) V_305 -> V_339 . V_496 . V_420 ) ;
if ( V_494 ) {
V_476 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_107 , tsb->length) ;
V_476 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_108 , tsb->flags) ;
V_476 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_109 , tsb->dcw_offset) ;
V_476 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_110 , tsb->count) ;
V_493 = V_494 -> V_42 - 28 ;
V_476 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_111 , residual) ;
switch ( V_494 -> V_43 & 0x07 ) {
case 1 :
V_476 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_112 ,
tsb->tsa.iostat.dev_time) ;
V_476 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_113 ,
tsb->tsa.iostat.def_time) ;
V_476 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_114 ,
tsb->tsa.iostat.queue_time) ;
V_476 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_115 ,
tsb->tsa.iostat.dev_busy_time) ;
V_476 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_116 ,
tsb->tsa.iostat.dev_act_time) ;
V_301 = V_494 -> V_498 . V_499 . V_301 ;
break;
case 2 :
V_476 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_117 , tsb->tsa.ddpc.rc) ;
for ( V_484 = 0 ; V_484 < 2 ; V_484 ++ ) {
V_476 += sprintf (page + len,
KERN_ERR PRINTK_HEADER
L_118 ,
(8 * sl), ((8 * sl) + 7)) ;
V_495 = V_494 -> V_498 . V_500 . V_495 ;
for ( V_485 = 0 ; V_485 < 8 ; V_485 ++ ) {
V_476 += sprintf ( V_475 + V_476 , L_94 ,
V_495 [ 8 * V_484 + V_485 ] ) ;
}
V_476 += sprintf ( V_475 + V_476 , L_83 ) ;
}
V_301 = V_494 -> V_498 . V_500 . V_301 ;
break;
case 3 :
V_476 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_119 ) ;
break;
}
if ( V_301 ) {
for ( V_484 = 0 ; V_484 < 4 ; V_484 ++ ) {
V_476 += sprintf (page + len,
KERN_ERR PRINTK_HEADER
L_93 ,
(8 * sl), ((8 * sl) + 7)) ;
for ( V_485 = 0 ; V_485 < 8 ; V_485 ++ ) {
V_476 += sprintf ( V_475 + V_476 , L_94 ,
V_301 [ 8 * V_484 + V_485 ] ) ;
}
V_476 += sprintf ( V_475 + V_476 , L_83 ) ;
}
if ( V_301 [ 27 ] & V_341 ) {
sprintf (page + len, KERN_ERR PRINTK_HEADER
L_95
L_96 ,
sense[7] >> 4 , sense[7] & 0x0f ,
sense[1] & 0x10 ? L_59 : L_97 ) ;
} else {
sprintf (page + len, KERN_ERR PRINTK_HEADER
L_98
L_99 ,
sense[6] & 0x0f , sense[22] >> 4 ) ;
}
} else {
sprintf (page + len, KERN_ERR PRINTK_HEADER
L_100 ) ;
}
} else {
sprintf (page + len, KERN_ERR PRINTK_HEADER
L_120 ) ;
}
F_166 ( L_1 , V_475 ) ;
F_168 ( ( unsigned long ) V_475 ) ;
}
static void F_171 ( struct V_30 * V_31 ,
struct V_167 * V_348 , struct V_305 * V_305 )
{
if ( F_172 ( & V_305 -> V_339 ) )
F_169 ( V_31 , V_348 , V_305 ) ;
else
F_164 ( V_31 , V_348 , V_305 ) ;
}
static int F_173 ( struct V_30 * V_31 )
{
F_103 ( V_31 ) ;
F_86 ( V_31 ) ;
return 0 ;
}
static int F_174 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
struct V_14 V_501 ;
int V_34 ;
struct V_149 V_269 ;
unsigned long V_43 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_34 = F_50 ( V_31 ) ;
if ( V_34 )
goto V_502;
F_30 ( V_31 , & V_269 ) ;
V_34 = F_26 ( V_31 ) ;
F_27 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
if ( memcmp ( & V_33 -> V_134 , & V_269 , sizeof( struct V_149 ) ) != 0 )
F_15 ( & V_31 -> V_2 -> V_82 , L_121
L_122 ) ;
F_29 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
if ( V_34 )
goto V_502;
V_34 = F_83 ( V_31 ) ;
if ( V_34 )
return V_34 ;
F_73 ( V_31 , V_254 ) ;
V_34 = F_50 ( V_31 ) ;
if ( V_34 )
goto V_502;
F_68 ( V_31 ) ;
V_34 = F_84 ( V_31 , V_176 ,
& V_501 , 64 ) ;
if ( V_34 ) {
F_3 ( V_7 , V_31 -> V_2 ,
L_53 , V_34 ) ;
goto V_502;
}
F_27 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
memcpy ( & V_33 -> V_35 , & V_501 , sizeof( V_501 ) ) ;
F_29 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
F_100 ( V_31 ) ;
return 0 ;
V_502:
return - 1 ;
}
static int F_175 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
int V_34 , V_503 ;
char V_226 [ 60 ] ;
struct V_149 V_134 ;
unsigned long V_43 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
F_27 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
V_503 = V_33 -> V_134 . V_161 ;
F_29 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
V_34 = F_50 ( V_31 ) ;
if ( V_34 )
goto V_502;
V_34 = F_26 ( V_31 ) ;
if ( V_34 )
goto V_502;
F_176 ( V_31 ) ;
F_30 ( V_31 , & V_134 ) ;
if ( V_503 != V_134 . V_161 ) {
if ( strlen ( V_134 . V_163 ) > 0 )
snprintf ( V_226 , sizeof( V_226 ) ,
L_17 , V_134 . V_150 , V_134 . V_152 ,
V_134 . V_154 , V_134 . V_161 , V_134 . V_163 ) ;
else
snprintf ( V_226 , sizeof( V_226 ) ,
L_18 , V_134 . V_150 , V_134 . V_152 ,
V_134 . V_154 , V_134 . V_161 ) ;
F_81 ( & V_31 -> V_2 -> V_82 ,
L_123
L_124 , V_226 ) ;
}
return 0 ;
V_502:
return - 1 ;
}
static int T_11
F_177 ( void )
{
int V_3 ;
F_178 ( V_8 . V_504 , 4 ) ;
V_439 = F_64 ( sizeof( * V_439 ) ,
V_196 | V_197 ) ;
if ( ! V_439 )
return - V_198 ;
V_234 = F_64 ( sizeof( * V_234 ) ,
V_196 | V_197 ) ;
if ( ! V_234 ) {
F_47 ( V_439 ) ;
return - V_198 ;
}
V_3 = F_179 ( & V_505 ) ;
if ( ! V_3 )
F_180 () ;
else {
F_47 ( V_234 ) ;
F_47 ( V_439 ) ;
}
return V_3 ;
}
static void T_12
F_181 ( void )
{
F_182 ( & V_505 ) ;
F_47 ( V_234 ) ;
F_47 ( V_439 ) ;
}
