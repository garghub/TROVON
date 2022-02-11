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
int V_34 ;
T_2 V_170 , V_209 ;
struct V_32 * V_33 , V_210 ;
struct V_211 * V_212 ;
struct V_149 * V_134 ;
char V_213 [ 60 ] , V_214 [ 60 ] ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_212 = & V_31 -> V_212 ;
V_209 = F_51 ( V_31 -> V_2 ) ;
V_208 = 0 ;
for ( V_170 = 0x80 ; V_170 ; V_170 >>= 1 ) {
if ( ! ( V_170 & V_209 ) )
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
V_212 -> V_209 |= V_170 ;
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
V_210 . V_201 = V_201 ;
V_210 . V_200 = V_174 ;
if ( F_48 (
& V_210 ) ) {
V_210 . V_201 = NULL ;
V_210 . V_200 = 0 ;
F_47 ( V_201 ) ;
continue;
}
if ( F_31 (
V_31 , & V_210 ) ) {
V_134 = & V_210 . V_134 ;
if ( strlen ( V_134 -> V_163 ) > 0 )
snprintf ( V_213 ,
sizeof( V_213 ) ,
L_17 ,
V_134 -> V_150 , V_134 -> V_152 ,
V_134 -> V_154 , V_134 -> V_157 ,
V_134 -> V_163 ) ;
else
snprintf ( V_213 ,
sizeof( V_213 ) ,
L_18 ,
V_134 -> V_150 , V_134 -> V_152 ,
V_134 -> V_154 ,
V_134 -> V_157 ) ;
V_134 = & V_33 -> V_134 ;
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
F_15 ( & V_31 -> V_2 -> V_82 ,
L_19
L_20
L_21 , V_170 ,
V_213 , V_214 ) ;
return - V_128 ;
}
V_210 . V_201 = NULL ;
V_210 . V_200 = 0 ;
}
switch ( F_49 ( V_201 , V_200 ) ) {
case 0x02 :
V_212 -> V_215 |= V_170 ;
break;
case 0x03 :
V_212 -> V_216 |= V_170 ;
break;
}
V_212 -> V_209 |= V_170 ;
if ( V_201 != V_33 -> V_201 )
F_47 ( V_201 ) ;
}
return 0 ;
}
static int F_52 ( struct V_30 * V_31 , T_2 V_170 )
{
struct V_32 * V_33 ;
int V_217 ;
T_3 V_218 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
if ( V_33 -> V_218 ) {
V_217 = F_53 ( V_31 -> V_2 , V_170 ) ;
if ( ( V_217 < 0 ) ) {
F_54 ( & V_31 -> V_2 -> V_82 ,
L_22
L_23 ,
V_217 , V_170 ) ;
return V_217 ;
}
V_218 = V_217 * V_219 ;
if ( V_218 < V_33 -> V_218 ) {
F_54 ( & V_31 -> V_2 -> V_82 ,
L_24
L_25
L_26 , V_218 , V_170 ,
V_33 -> V_218 ) ;
return - V_41 ;
}
}
return 0 ;
}
static int F_55 ( struct V_30 * V_31 ,
struct V_220 * V_29 )
{
struct V_32 * V_33 ;
struct V_211 * V_212 ;
T_2 V_170 , V_209 ;
int V_34 ;
V_34 = - V_165 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_212 = & V_31 -> V_212 ;
V_209 = V_31 -> V_212 . V_209 ;
for ( V_170 = 0x80 ; V_170 ; V_170 >>= 1 ) {
if ( ! ( V_170 & V_209 ) )
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
static void F_56 ( struct V_221 * V_222 )
{
struct V_220 * V_29 ;
struct V_30 * V_31 ;
struct V_32 V_210 ;
struct V_149 * V_134 ;
T_2 V_223 [ V_174 ] ;
T_2 V_170 , V_209 , V_215 , V_216 , V_224 ;
unsigned long V_43 ;
char V_225 [ 60 ] ;
int V_34 ;
V_29 = F_57 ( V_222 , struct V_220 , V_226 ) ;
V_31 = V_29 -> V_31 ;
if ( F_58 ( V_227 , & V_31 -> V_43 ) ) {
F_59 ( V_222 ) ;
return;
}
V_209 = 0 ;
V_215 = 0 ;
V_216 = 0 ;
V_224 = 0 ;
for ( V_170 = 0x80 ; V_170 ; V_170 >>= 1 ) {
if ( ! ( V_170 & V_29 -> V_228 ) )
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
V_215 |= V_170 ;
break;
case 0x03 :
V_216 |= V_170 ;
break;
}
V_209 |= V_170 ;
} else if ( V_34 == - V_40 ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_29
L_30 ) ;
V_209 |= V_170 ;
} else if ( V_34 == - V_229 ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_31
L_32 ) ;
V_224 |= V_170 ;
} else {
F_54 ( & V_31 -> V_2 -> V_82 ,
L_33
L_34 , V_34 , V_170 ) ;
continue;
}
if ( F_52 ( V_31 , V_170 ) ) {
V_209 &= ~ V_170 ;
V_215 &= ~ V_170 ;
V_216 &= ~ V_170 ;
continue;
}
memcpy ( & V_223 , V_29 -> V_169 ,
V_174 ) ;
V_210 . V_201 = ( void * ) & V_223 ;
V_210 . V_200 = V_174 ;
if ( F_48 ( & V_210 ) ) {
V_210 . V_201 = NULL ;
V_210 . V_200 = 0 ;
continue;
}
if ( V_31 -> V_212 . V_209 &&
F_31 ( V_31 , & V_210 ) ) {
if ( F_55 ( V_31 , V_29 ) ||
F_31 (
V_31 , & V_210 ) ) {
V_134 = & V_210 . V_134 ;
if ( strlen ( V_134 -> V_163 ) > 0 )
snprintf ( V_225 , sizeof( V_225 ) ,
L_17 ,
V_134 -> V_150 , V_134 -> V_152 ,
V_134 -> V_154 , V_134 -> V_157 ,
V_134 -> V_163 ) ;
else
snprintf ( V_225 , sizeof( V_225 ) ,
L_18 ,
V_134 -> V_150 , V_134 -> V_152 ,
V_134 -> V_154 ,
V_134 -> V_157 ) ;
F_15 ( & V_31 -> V_2 -> V_82 ,
L_35
L_36
L_37 ,
V_170 , V_225 ) ;
V_209 &= ~ V_170 ;
V_215 &= ~ V_170 ;
V_216 &= ~ V_170 ;
continue;
}
}
F_27 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
if ( ! V_31 -> V_212 . V_209 && V_209 ) {
V_31 -> V_212 . V_209 = V_209 ;
F_60 ( V_31 ) ;
} else
V_31 -> V_212 . V_209 |= V_209 ;
V_31 -> V_212 . V_215 |= V_215 ;
V_31 -> V_212 . V_216 |= V_216 ;
V_31 -> V_212 . V_228 |= V_224 ;
F_29 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
}
F_61 ( V_31 ) ;
if ( V_29 -> V_230 )
F_62 ( & V_231 ) ;
else
F_47 ( V_29 ) ;
}
static int F_63 ( struct V_30 * V_31 , T_2 V_170 )
{
struct V_220 * V_29 ;
V_29 = F_64 ( sizeof( * V_29 ) , V_232 | V_196 ) ;
if ( ! V_29 ) {
if ( F_65 ( & V_231 ) ) {
V_29 = V_233 ;
V_29 -> V_230 = 1 ;
} else
return - V_197 ;
} else {
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_29 -> V_230 = 0 ;
}
F_66 ( & V_29 -> V_226 , F_56 ) ;
F_67 ( V_31 ) ;
V_29 -> V_31 = V_31 ;
V_29 -> V_228 = V_170 ;
F_59 ( & V_29 -> V_226 ) ;
return 0 ;
}
static int F_68 ( struct V_30 * V_31 )
{
struct V_234 * V_235 ;
struct V_236 * V_237 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
int V_34 ;
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
memset ( & V_33 -> V_237 , 0 , sizeof( struct V_236 ) ) ;
V_168 = F_43 ( V_176 , 1 + 1 ,
( sizeof( struct V_234 ) +
sizeof( struct V_236 ) ) ,
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
V_235 = (struct V_234 * ) V_168 -> V_29 ;
memset ( V_235 , 0 , sizeof( struct V_234 ) ) ;
V_235 -> V_238 = V_239 ;
V_235 -> V_240 = 0x41 ;
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_241 ;
V_45 -> V_42 = sizeof( struct V_234 ) ;
V_45 -> V_43 |= V_242 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_235 ;
V_237 = (struct V_236 * ) ( V_235 + 1 ) ;
memset ( V_237 , 0 , sizeof( struct V_236 ) ) ;
V_45 ++ ;
V_45 -> V_54 = V_243 ;
V_45 -> V_42 = sizeof( struct V_236 ) ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_237 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_45 ( V_168 ) ;
if ( V_34 == 0 ) {
V_235 = (struct V_234 * ) V_168 -> V_29 ;
V_237 = (struct V_236 * ) ( V_235 + 1 ) ;
memcpy ( & V_33 -> V_237 , V_237 ,
sizeof( struct V_236 ) ) ;
} else
F_54 ( & V_31 -> V_2 -> V_82 , L_40
L_41 , V_34 ) ;
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static struct V_167 * F_70 ( struct V_30 * V_31 ,
int V_244 )
{
struct V_167 * V_168 ;
struct V_245 * V_246 ;
struct V_26 * V_45 ;
V_168 = F_43 ( V_176 , 1 ,
sizeof( struct V_245 ) ,
V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_18 ( V_7 , V_31 , L_1 ,
L_42 ) ;
return V_168 ;
}
V_246 = (struct V_245 * ) V_168 -> V_29 ;
V_246 -> V_238 = V_247 ;
V_246 -> V_240 = 0xc0 ;
if ( V_244 ) {
V_246 -> V_240 |= 0x08 ;
V_246 -> V_248 [ 0 ] = 0x88 ;
}
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_241 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_246 ;
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
F_71 ( struct V_30 * V_31 , int V_244 ,
unsigned long V_43 )
{
struct V_167 * V_168 ;
int V_34 ;
V_168 = F_70 ( V_31 , V_244 ) ;
if ( F_44 ( V_168 ) )
return F_69 ( V_168 ) ;
V_168 -> V_43 |= V_43 ;
V_34 = F_45 ( V_168 ) ;
if ( ! V_34 )
F_72 () ;
else if ( V_168 -> V_249 == - V_229 )
V_34 = - V_229 ;
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int F_73 ( struct V_30 * V_31 ,
unsigned long V_43 )
{
int V_34 ;
struct V_32 * V_33 ;
int V_244 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
if ( V_33 -> V_134 . type == V_160 ||
V_33 -> V_134 . type == V_137 )
return 0 ;
if ( V_250 || V_251 )
V_244 = 0 ;
else
V_244 = 1 ;
V_34 = F_71 ( V_31 , V_244 , V_43 ) ;
F_3 ( V_7 , V_31 -> V_2 , L_43
L_44 , V_33 -> V_134 . V_154 , V_34 ) ;
return V_34 ;
}
static void F_74 ( struct V_221 * V_222 )
{
struct V_30 * V_31 = F_57 ( V_222 , struct V_30 ,
V_252 ) ;
if ( F_73 ( V_31 , V_253 )
== - V_229 ) {
F_59 ( & V_31 -> V_252 ) ;
return;
}
F_61 ( V_31 ) ;
}
static void F_75 ( struct V_30 * V_31 )
{
F_67 ( V_31 ) ;
if ( F_58 ( V_254 , & V_31 -> V_43 ) ||
V_31 -> V_255 < V_256 ) {
F_61 ( V_31 ) ;
return;
}
F_59 ( & V_31 -> V_252 ) ;
}
static T_3 F_76 ( struct V_30 * V_31 )
{
#if F_77 ( V_257 )
int V_258 , V_217 ;
int V_259 , V_260 , V_261 ;
struct V_32 * V_33 ;
if ( V_262 )
return 0 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_259 = V_263 . V_264 ;
V_260 = V_33 -> V_155 -> V_265 [ 7 ] & 0x04 ;
V_261 = V_33 -> V_237 . V_266 [ 40 ] & 0x80 ;
V_258 = V_259 && V_260 && V_261 ;
if ( ! V_258 )
return 0 ;
V_217 = F_53 ( V_31 -> V_2 , 0 ) ;
if ( V_217 < 0 ) {
F_54 ( & V_31 -> V_2 -> V_82 , L_45
L_46 ) ;
return 0 ;
} else
return V_217 * V_219 ;
#else
return 0 ;
#endif
}
static int
F_78 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
struct V_267 * V_178 ;
struct V_149 V_268 ;
int V_34 , V_199 ;
int V_269 ;
unsigned long V_270 ;
F_66 ( & V_31 -> V_252 , F_74 ) ;
if ( ! F_79 ( V_31 -> V_2 ) ) {
F_54 ( & V_31 -> V_2 -> V_82 ,
L_47 ) ;
return - V_271 ;
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
V_33 -> V_272 = - 1 ;
V_33 -> V_70 . V_69 = V_273 ;
V_33 -> V_70 . V_89 = 0 ;
V_34 = F_50 ( V_31 ) ;
if ( V_34 )
goto V_274;
V_31 -> V_275 = V_276 ;
if ( V_33 -> V_155 ) {
V_270 = 1 ;
for ( V_199 = 0 ; V_199 < V_33 -> V_155 -> V_277 . V_270 ; V_199 ++ )
V_270 = 10 * V_270 ;
V_270 = V_270 * V_33 -> V_155 -> V_277 . V_278 ;
if ( V_270 != 0 && V_270 <= V_279 )
V_31 -> V_275 = V_270 ;
}
F_30 ( V_31 , & V_268 ) ;
if ( V_268 . type == V_135 ) {
V_178 = F_82 () ;
if ( F_44 ( V_178 ) ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_51
L_52 ) ;
V_34 = F_69 ( V_178 ) ;
goto V_274;
}
V_31 -> V_178 = V_178 ;
V_178 -> V_280 = V_31 ;
}
V_34 = F_83 ( V_31 ) ;
if ( V_34 )
goto V_281;
F_73 ( V_31 , 0 ) ;
V_34 = F_50 ( V_31 ) ;
if ( V_34 )
goto V_282;
F_68 ( V_31 ) ;
V_34 = F_84 ( V_31 , V_176 ,
& V_33 -> V_35 , 64 ) ;
if ( V_34 ) {
F_3 ( V_7 , V_31 -> V_2 ,
L_53 , V_34 ) ;
goto V_282;
}
if ( ( V_31 -> V_237 & V_283 ) &&
! ( V_33 -> V_35 . V_36 . V_284 ) ) {
F_15 ( & V_31 -> V_2 -> V_82 , L_54
L_55 ) ;
V_34 = - V_128 ;
goto V_282;
}
if ( V_33 -> V_35 . V_285 == V_286 &&
V_33 -> V_35 . V_287 )
V_33 -> V_90 = V_33 -> V_35 . V_287 ;
else
V_33 -> V_90 = V_33 -> V_35 . V_285 ;
V_33 -> V_218 = F_76 ( V_31 ) ;
V_269 = F_85 ( V_31 ) ;
if ( V_269 )
F_34 ( V_288 , & V_31 -> V_43 ) ;
F_81 ( & V_31 -> V_2 -> V_82 , L_56
L_57 ,
V_33 -> V_35 . V_20 ,
V_33 -> V_35 . V_289 ,
V_33 -> V_35 . V_84 ,
V_33 -> V_35 . V_290 . V_291 ,
V_33 -> V_90 ,
V_33 -> V_35 . V_86 ,
V_33 -> V_35 . V_292 ,
V_269 ? L_58 : L_59 ) ;
return 0 ;
V_282:
F_86 ( V_31 ) ;
V_281:
F_87 ( V_31 -> V_178 ) ;
V_31 -> V_178 = NULL ;
V_274:
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
struct V_293 * V_294 ;
struct V_140 * V_295 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
int V_296 , V_297 ;
int V_199 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_296 = 8 ;
V_297 = sizeof( struct V_28 ) + 2 * sizeof( struct V_140 ) ;
V_168 = F_43 ( V_176 , V_296 , V_297 , V_31 ) ;
if ( F_44 ( V_168 ) )
return V_168 ;
V_45 = V_168 -> V_171 ;
F_13 ( V_45 ++ , V_168 -> V_29 , 0 , 2 ,
V_65 , V_31 ) ;
V_295 = V_168 -> V_29 + sizeof( struct V_28 ) ;
V_45 [ - 1 ] . V_43 |= V_242 ;
V_126 ( V_45 ++ , V_295 ++ , 0 , 0 , 4 ,
V_65 , V_31 , 0 ) ;
V_294 = V_33 -> V_298 ;
for ( V_199 = 0 ; V_199 < 4 ; V_199 ++ ) {
V_45 [ - 1 ] . V_43 |= V_242 ;
V_45 -> V_54 = V_65 ;
V_45 -> V_43 = 0 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_294 ;
V_45 ++ ;
V_294 ++ ;
}
V_45 [ - 1 ] . V_43 |= V_242 ;
V_126 ( V_45 ++ , V_295 ++ , 2 , 0 , 1 ,
V_65 , V_31 , 0 ) ;
V_45 [ - 1 ] . V_43 |= V_242 ;
V_45 -> V_54 = V_65 ;
V_45 -> V_43 = 0 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_294 ;
V_168 -> V_178 = NULL ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_181 = 255 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
return V_168 ;
}
static int F_90 ( struct V_167 * V_299 )
{
char * V_300 ;
if ( V_299 -> V_183 == V_186 )
return V_301 ;
else if ( V_299 -> V_183 == V_302 ||
V_299 -> V_183 == V_303 ) {
V_300 = F_91 ( & V_299 -> V_304 ) ;
if ( V_300 && ( V_300 [ 1 ] & V_305 ) )
return V_306 ;
else
return V_307 ;
} else
return V_307 ;
}
static void F_92 ( struct V_167 * V_299 ,
void * V_29 )
{
struct V_32 * V_33 ;
struct V_30 * V_31 ;
V_31 = V_299 -> V_119 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_33 -> V_272 = F_90 ( V_299 ) ;
F_46 ( V_299 , V_31 ) ;
F_93 ( V_31 ) ;
}
static int F_94 ( struct V_267 * V_178 )
{
struct V_167 * V_299 ;
V_299 = F_89 ( V_178 -> V_280 ) ;
if ( F_44 ( V_299 ) )
return F_69 ( V_299 ) ;
V_299 -> V_191 = F_92 ;
V_299 -> V_308 = NULL ;
V_299 -> V_179 = 5 * V_180 ;
F_39 ( V_189 , & V_299 -> V_43 ) ;
V_299 -> V_181 = 0 ;
F_95 ( V_299 ) ;
return - V_229 ;
}
static int F_96 ( struct V_267 * V_178 )
{
struct V_30 * V_31 ;
struct V_32 * V_33 ;
struct V_293 * V_298 ;
unsigned int V_309 , V_145 ;
int V_183 , V_199 ;
struct V_167 * V_299 ;
V_31 = V_178 -> V_280 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_183 = V_33 -> V_272 ;
V_33 -> V_272 = - 1 ;
if ( V_183 == V_307 ) {
V_299 = F_89 ( V_31 ) ;
F_45 ( V_299 ) ;
V_183 = F_90 ( V_299 ) ;
F_46 ( V_299 , V_31 ) ;
}
if ( V_31 -> V_237 & V_283 ) {
V_178 -> V_310 = V_311 ;
V_145 = V_312 ;
V_178 -> V_313 = 3 ;
goto V_314;
}
if ( V_183 == V_306 ) {
F_54 ( & V_31 -> V_2 -> V_82 , L_60 ) ;
return - V_315 ;
} else if ( V_183 == V_307 ) {
F_15 ( & V_31 -> V_2 -> V_82 ,
L_61
L_62 ) ;
return - V_271 ;
}
V_33 -> V_85 = 1 ;
V_298 = NULL ;
for ( V_199 = 0 ; V_199 < 3 ; V_199 ++ ) {
if ( V_33 -> V_298 [ V_199 ] . V_16 != 4 ||
V_33 -> V_298 [ V_199 ] . V_17 != F_23 ( V_199 ) - 4 ||
V_33 -> V_298 [ V_199 ] . V_23 != 0 ||
V_33 -> V_298 [ V_199 ] . V_24 != V_316 [ V_199 ] ||
V_33 -> V_298 [ V_199 ] . V_117 != V_317 [ V_199 ] ) {
V_33 -> V_85 = 0 ;
break;
}
}
if ( V_199 == 3 )
V_298 = & V_33 -> V_298 [ 4 ] ;
if ( V_33 -> V_85 == 0 ) {
for ( V_199 = 0 ; V_199 < 5 ; V_199 ++ ) {
if ( ( V_33 -> V_298 [ V_199 ] . V_16 != 0 ) ||
( V_33 -> V_298 [ V_199 ] . V_17 !=
V_33 -> V_298 [ 0 ] . V_17 ) ||
V_33 -> V_298 [ V_199 ] . V_23 != 0 ||
V_33 -> V_298 [ V_199 ] . V_24 != V_316 [ V_199 ] ||
V_33 -> V_298 [ V_199 ] . V_117 != V_317 [ V_199 ] )
break;
}
if ( V_199 == 5 )
V_298 = & V_33 -> V_298 [ 0 ] ;
} else {
if ( V_33 -> V_298 [ 3 ] . V_117 == 1 )
F_54 ( & V_31 -> V_2 -> V_82 ,
L_63 ) ;
}
if ( V_298 != NULL && V_298 -> V_16 == 0 ) {
if ( F_97 ( V_298 -> V_17 ) == 0 )
V_178 -> V_310 = V_298 -> V_17 ;
}
if ( V_178 -> V_310 == 0 ) {
F_54 ( & V_31 -> V_2 -> V_82 ,
L_64 ) ;
return - V_315 ;
}
V_178 -> V_313 = 0 ;
for ( V_309 = 512 ; V_309 < V_178 -> V_310 ; V_309 = V_309 << 1 )
V_178 -> V_313 ++ ;
V_145 = F_9 ( & V_33 -> V_35 , 0 , V_178 -> V_310 ) ;
V_314:
V_178 -> V_318 = ( V_33 -> V_90 *
V_33 -> V_35 . V_86 *
V_145 ) ;
F_81 ( & V_31 -> V_2 -> V_82 ,
L_65
L_66 , ( V_178 -> V_310 >> 10 ) ,
( ( V_33 -> V_90 *
V_33 -> V_35 . V_86 *
V_145 * ( V_178 -> V_310 >> 9 ) ) >> 1 ) ,
( ( V_145 * V_178 -> V_310 ) >> 10 ) ,
V_33 -> V_85 ?
L_67 : L_68 ) ;
return 0 ;
}
static int F_98 ( struct V_267 * V_178 )
{
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_178 -> V_280 -> V_33 ;
if ( V_33 -> V_272 < 0 )
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
F_102 ( & V_31 -> V_319 ) ;
F_102 ( & V_31 -> V_252 ) ;
return F_103 ( V_31 ) ;
}
static int
F_104 ( struct V_267 * V_178 , struct V_320 * V_22 )
{
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_178 -> V_280 -> V_33 ;
if ( F_97 ( V_178 -> V_310 ) == 0 ) {
V_22 -> V_321 = F_9 ( & V_33 -> V_35 ,
0 , V_178 -> V_310 ) ;
}
V_22 -> V_322 = V_33 -> V_35 . V_285 ;
V_22 -> V_51 = V_33 -> V_35 . V_86 ;
return 0 ;
}
static struct V_167 *
F_105 ( struct V_30 * V_31 ,
struct V_323 * V_324 )
{
struct V_32 * V_33 ;
struct V_167 * V_325 ;
struct V_293 * V_326 ;
struct V_26 * V_45 ;
void * V_29 ;
int V_327 ;
struct V_21 V_328 ;
int V_296 , V_297 ;
int V_199 ;
int V_329 = 0 ;
int V_330 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_327 = F_9 ( & V_33 -> V_35 , 0 , V_324 -> V_121 ) ;
F_10 ( & V_328 ,
V_324 -> V_331 / V_33 -> V_35 . V_86 ,
V_324 -> V_331 % V_33 -> V_35 . V_86 ) ;
if ( V_324 -> V_331 >=
( V_33 -> V_90 * V_33 -> V_35 . V_86 ) ) {
F_54 ( & V_31 -> V_2 -> V_82 , L_69
L_70 , V_324 -> V_331 ) ;
return F_106 ( - V_128 ) ;
}
if ( V_324 -> V_331 > V_324 -> V_332 ) {
F_54 ( & V_31 -> V_2 -> V_82 , L_71
L_72 , V_324 -> V_331 ) ;
return F_106 ( - V_128 ) ;
}
if ( F_97 ( V_324 -> V_121 ) != 0 ) {
F_54 ( & V_31 -> V_2 -> V_82 ,
L_73 ,
V_324 -> V_121 ) ;
return F_106 ( - V_128 ) ;
}
if ( V_324 -> V_329 & 0x10 ) {
V_330 = 0 ;
V_329 = V_324 -> V_329 & ~ 0x10 ;
} else {
V_330 = 1 ;
V_329 = V_324 -> V_329 ;
}
switch ( V_329 ) {
case 0x00 :
case 0x08 :
V_296 = 2 + V_327 ;
V_297 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
V_327 * sizeof( struct V_293 ) ;
break;
case 0x01 :
case 0x09 :
V_296 = 3 + V_327 ;
V_297 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
sizeof( struct V_293 ) +
V_327 * sizeof( struct V_293 ) ;
break;
case 0x04 :
case 0x0c :
V_296 = 3 ;
V_297 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
sizeof( struct V_293 ) ;
break;
default:
F_54 ( & V_31 -> V_2 -> V_82 , L_74
L_75 , V_324 -> V_329 ) ;
return F_106 ( - V_128 ) ;
}
V_325 = F_43 ( V_176 , V_296 , V_297 , V_31 ) ;
if ( F_44 ( V_325 ) )
return V_325 ;
V_29 = V_325 -> V_29 ;
V_45 = V_325 -> V_171 ;
switch ( V_329 & ~ 0x08 ) {
case 0x00 :
F_13 ( V_45 ++ , (struct V_28 * ) V_29 ,
V_324 -> V_331 , V_324 -> V_331 ,
V_75 , V_31 ) ;
if ( V_330 )
( (struct V_28 * ) V_29 ) -> V_38 |= 0x04 ;
V_29 += sizeof( struct V_28 ) ;
V_45 [ - 1 ] . V_43 |= V_242 ;
V_126 ( V_45 ++ , (struct V_140 * ) V_29 ,
V_324 -> V_331 , 0 , V_327 ,
V_75 , V_31 ,
V_324 -> V_121 ) ;
V_29 += sizeof( struct V_140 ) ;
break;
case 0x01 :
F_13 ( V_45 ++ , (struct V_28 * ) V_29 ,
V_324 -> V_331 , V_324 -> V_331 ,
V_80 ,
V_31 ) ;
V_29 += sizeof( struct V_28 ) ;
V_45 [ - 1 ] . V_43 |= V_242 ;
V_126 ( V_45 ++ , (struct V_140 * ) V_29 ,
V_324 -> V_331 , 0 , V_327 + 1 ,
V_80 , V_31 ,
V_31 -> V_178 -> V_310 ) ;
V_29 += sizeof( struct V_140 ) ;
break;
case 0x04 :
F_13 ( V_45 ++ , (struct V_28 * ) V_29 ,
V_324 -> V_331 , V_324 -> V_331 ,
V_75 , V_31 ) ;
V_29 += sizeof( struct V_28 ) ;
V_45 [ - 1 ] . V_43 |= V_242 ;
V_126 ( V_45 ++ , (struct V_140 * ) V_29 ,
V_324 -> V_331 , 0 , 1 ,
V_75 , V_31 , 8 ) ;
V_29 += sizeof( struct V_140 ) ;
break;
}
if ( V_329 & 0x01 ) {
V_326 = (struct V_293 * ) V_29 ;
V_29 += sizeof( struct V_293 ) ;
V_326 -> V_23 = V_328 . V_23 ;
V_326 -> V_24 = V_328 . V_24 ;
V_326 -> V_117 = 0 ;
V_326 -> V_16 = 0 ;
V_326 -> V_17 = 8 ;
V_45 [ - 1 ] . V_43 |= V_242 ;
V_45 -> V_54 = V_80 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_326 ;
V_45 ++ ;
}
if ( ( V_329 & ~ 0x08 ) & 0x04 ) {
V_326 = (struct V_293 * ) V_29 ;
V_29 += sizeof( struct V_293 ) ;
V_326 -> V_23 = V_328 . V_23 ;
V_326 -> V_24 = V_328 . V_24 ;
V_326 -> V_117 = 1 ;
V_326 -> V_16 = 0 ;
V_326 -> V_17 = 0 ;
V_45 [ - 1 ] . V_43 |= V_242 ;
V_45 -> V_54 = V_75 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_326 ;
} else {
for ( V_199 = 0 ; V_199 < V_327 ; V_199 ++ ) {
V_326 = (struct V_293 * ) V_29 ;
V_29 += sizeof( struct V_293 ) ;
V_326 -> V_23 = V_328 . V_23 ;
V_326 -> V_24 = V_328 . V_24 ;
V_326 -> V_117 = V_199 + 1 ;
V_326 -> V_16 = 0 ;
V_326 -> V_17 = V_324 -> V_121 ;
if ( ( V_329 & 0x08 ) &&
V_324 -> V_331 == 0 ) {
if ( V_199 < 3 ) {
V_326 -> V_16 = 4 ;
V_326 -> V_17 = V_147 [ V_199 ] - 4 ;
}
}
if ( ( V_329 & 0x08 ) &&
V_324 -> V_331 == 1 ) {
V_326 -> V_16 = 44 ;
V_326 -> V_17 = V_148 - 44 ;
}
V_45 [ - 1 ] . V_43 |= V_242 ;
V_45 -> V_54 = V_75 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_326 ;
V_45 ++ ;
}
}
V_325 -> V_119 = V_31 ;
V_325 -> V_177 = V_31 ;
V_325 -> V_181 = 256 ;
V_325 -> V_182 = F_33 () ;
V_325 -> V_183 = V_184 ;
return V_325 ;
}
static void F_107 ( struct V_167 * V_168 )
{
V_168 -> V_183 = V_184 ;
if ( V_168 -> V_178 && ( V_168 -> V_119 != V_168 -> V_178 -> V_280 ) ) {
F_108 ( V_168 ) ;
V_168 -> V_119 = V_168 -> V_178 -> V_280 ;
V_168 -> V_170 = V_168 -> V_178 -> V_280 -> V_212 . V_209 ;
}
}
static T_5
F_109 ( struct V_167 * V_168 )
{
struct V_30 * V_31 = (struct V_30 * ) V_168 -> V_119 ;
struct V_1 * V_2 = V_31 -> V_2 ;
switch ( V_2 -> V_333 . V_84 ) {
case 0x3990 :
case 0x2105 :
case 0x2107 :
case 0x1750 :
return V_334 ;
case 0x9343 :
case 0x3880 :
default:
return V_335 ;
}
}
static T_5
F_110 ( struct V_167 * V_168 )
{
return V_336 ;
}
static void F_111 ( struct V_30 * V_31 ,
struct V_167 * V_168 ,
struct V_304 * V_304 )
{
char V_66 ;
char * V_300 = NULL ;
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_66 = V_337 | V_338 | V_339 ;
if ( ( F_112 ( & V_304 -> V_340 ) & V_66 ) == V_66 ) {
if ( ! V_31 -> V_178 && V_33 -> V_341 &&
V_31 -> V_255 == V_256 &&
! F_58 ( V_254 , & V_31 -> V_43 ) &&
! F_58 ( V_227 , & V_31 -> V_43 ) ) {
F_103 ( V_31 ) ;
F_113 ( V_31 ) ;
}
F_114 ( V_31 ) ;
return;
}
V_300 = F_91 ( V_304 ) ;
if ( ! V_300 )
return;
if ( ( V_300 [ 27 ] & V_342 ) && ( V_300 [ 7 ] == 0x0D ) &&
( F_112 ( & V_304 -> V_340 ) & V_343 ) ) {
F_115 ( V_31 , V_304 ) ;
return;
}
if ( ! V_168 && ! ( V_300 [ 27 ] & V_342 ) &&
( ( V_300 [ 6 ] & V_344 ) == V_344 ) ) {
F_116 ( V_31 , V_300 ) ;
return;
}
if ( V_31 -> V_178 && ( V_300 [ 27 ] & V_342 ) &&
( V_300 [ 7 ] == 0x3F ) &&
( F_112 ( & V_304 -> V_340 ) & V_343 ) &&
F_58 ( V_345 , & V_31 -> V_43 ) ) {
if ( V_31 -> V_237 & V_346 )
F_34 ( V_347 , & V_31 -> V_43 ) ;
F_39 ( V_345 , & V_31 -> V_43 ) ;
F_15 ( & V_31 -> V_2 -> V_82 ,
L_76 ) ;
}
}
static struct V_167 * F_117 (
struct V_30 * V_119 ,
struct V_267 * V_178 ,
struct V_348 * V_349 ,
T_6 V_350 ,
T_6 V_351 ,
T_6 V_352 ,
T_6 V_353 ,
unsigned int V_354 ,
unsigned int V_355 ,
unsigned int V_145 ,
unsigned int V_121 )
{
struct V_32 * V_33 ;
unsigned long * V_356 ;
struct V_140 * V_295 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
struct V_357 V_358 ;
struct V_359 * V_360 ;
char * V_361 ;
unsigned int V_362 ;
int V_42 , V_363 , V_296 , V_297 ;
T_6 V_146 ;
unsigned char V_48 , V_364 ;
int V_365 ;
struct V_30 * V_118 ;
V_118 = V_178 -> V_280 ;
V_33 = (struct V_32 * ) V_118 -> V_33 ;
if ( F_118 ( V_349 ) == V_366 )
V_48 = V_60 ;
else if ( F_118 ( V_349 ) == V_367 )
V_48 = V_72 ;
else
return F_106 ( - V_128 ) ;
V_42 = 0 ;
V_363 = 0 ;
F_119 (bv, req, iter) {
if ( V_360 -> V_368 & ( V_121 - 1 ) )
return F_106 ( - V_128 ) ;
V_42 += V_360 -> V_368 >> ( V_178 -> V_313 + 9 ) ;
#if F_77 ( V_257 )
if ( F_120 ( F_121 ( V_360 -> V_369 ) , V_360 -> V_368 ) )
V_363 += V_360 -> V_368 >> ( V_178 -> V_313 + 9 ) ;
#endif
}
if ( V_42 != V_351 - V_350 + 1 )
return F_106 ( - V_128 ) ;
V_365 = V_33 -> V_237 . V_266 [ 8 ] & 0x01 ;
if ( V_365 ) {
V_296 = 2 + V_42 ;
V_297 = sizeof( struct V_93 ) +
sizeof( struct V_140 ) +
V_363 * sizeof( unsigned long ) ;
} else {
V_296 = 2 + V_42 ;
V_297 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
V_363 * sizeof( unsigned long ) ;
}
if ( V_33 -> V_85 && V_350 < 2 * V_145 ) {
if ( V_351 >= 2 * V_145 )
V_42 = 2 * V_145 - V_350 ;
V_296 += V_42 ;
V_297 += V_42 * sizeof( struct V_140 ) ;
}
V_168 = F_43 ( V_176 , V_296 , V_297 ,
V_119 ) ;
if ( F_44 ( V_168 ) )
return V_168 ;
V_45 = V_168 -> V_171 ;
if ( V_365 ) {
if ( F_21 ( V_45 ++ , V_168 -> V_29 , V_352 ,
V_353 , V_48 , V_118 , V_119 ) == - V_229 ) {
F_46 ( V_168 , V_119 ) ;
return F_106 ( - V_229 ) ;
}
V_356 = ( unsigned long * ) ( V_168 -> V_29 +
sizeof( struct V_93 ) ) ;
} else {
if ( F_13 ( V_45 ++ , V_168 -> V_29 , V_352 ,
V_353 , V_48 , V_118 ) == - V_229 ) {
F_46 ( V_168 , V_119 ) ;
return F_106 ( - V_229 ) ;
}
V_356 = ( unsigned long * ) ( V_168 -> V_29 +
sizeof( struct V_28 ) ) ;
}
V_295 = (struct V_140 * ) ( V_356 + V_363 ) ;
V_146 = V_350 ;
if ( V_33 -> V_85 == 0 || V_146 > 2 * V_145 ) {
V_45 [ - 1 ] . V_43 |= V_242 ;
V_126 ( V_45 ++ , V_295 ++ , V_352 , V_354 + 1 ,
V_351 - V_146 + 1 , V_48 , V_118 , V_121 ) ;
}
F_119 (bv, req, iter) {
V_361 = F_121 ( V_360 -> V_369 ) + V_360 -> V_370 ;
if ( V_371 ) {
char * V_372 = F_122 ( V_371 ,
V_196 | V_373 ) ;
if ( V_372 && F_118 ( V_349 ) == V_367 )
memcpy ( V_372 + V_360 -> V_370 , V_361 , V_360 -> V_368 ) ;
if ( V_372 )
V_361 = V_372 + V_360 -> V_370 ;
}
for ( V_362 = 0 ; V_362 < V_360 -> V_368 ; V_362 += V_121 ) {
T_6 V_374 = V_146 ;
unsigned int V_375 = F_123 ( V_374 , V_145 ) ;
V_364 = V_48 ;
V_42 = V_121 ;
if ( V_33 -> V_85 && V_146 < 2 * V_145 ) {
if ( F_22 ( V_145 , V_146 ) ) {
V_364 |= 0x8 ;
V_42 = F_23 ( V_146 ) ;
if ( V_42 < V_121 &&
F_118 ( V_349 ) == V_366 )
memset ( V_361 + V_42 , 0xe5 ,
V_121 - V_42 ) ;
}
V_45 [ - 1 ] . V_43 |= V_242 ;
V_126 ( V_45 ++ , V_295 ++ ,
V_374 , V_375 + 1 ,
1 , V_364 , V_118 , V_42 ) ;
}
if ( V_33 -> V_85 && V_146 == 2 * V_145 ) {
V_45 [ - 1 ] . V_43 |= V_242 ;
V_126 ( V_45 ++ , V_295 ++ ,
V_374 , V_375 + 1 ,
V_351 - V_146 + 1 ,
V_48 , V_118 , V_42 ) ;
}
V_45 [ - 1 ] . V_43 |= V_242 ;
V_45 -> V_54 = V_364 ;
V_45 -> V_42 = V_42 ;
if ( F_120 ( V_361 , V_121 ) ) {
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_356 ;
V_45 -> V_43 = V_376 ;
V_356 = F_124 ( V_356 , V_361 , V_121 ) ;
} else {
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_361 ;
V_45 -> V_43 = 0 ;
}
V_45 ++ ;
V_361 += V_121 ;
V_146 ++ ;
}
}
if ( F_125 ( V_349 ) ||
V_178 -> V_280 -> V_237 & V_377 )
F_34 ( V_253 , & V_168 -> V_43 ) ;
V_168 -> V_119 = V_119 ;
V_168 -> V_177 = V_119 ;
V_168 -> V_178 = V_178 ;
V_168 -> V_179 = V_119 -> V_275 * V_180 ;
V_168 -> V_170 = V_119 -> V_212 . V_216 ;
V_168 -> V_181 = 256 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
return V_168 ;
}
static struct V_167 * F_126 (
struct V_30 * V_119 ,
struct V_267 * V_178 ,
struct V_348 * V_349 ,
T_6 V_350 ,
T_6 V_351 ,
T_6 V_352 ,
T_6 V_353 ,
unsigned int V_354 ,
unsigned int V_355 ,
unsigned int V_145 ,
unsigned int V_121 )
{
unsigned long * V_356 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
struct V_357 V_358 ;
struct V_359 * V_360 ;
char * V_361 , * V_378 ;
unsigned int V_363 , V_296 , V_297 ;
unsigned int V_100 ;
T_6 V_146 ;
unsigned char V_48 ;
struct V_30 * V_118 ;
unsigned int V_379 , V_42 , V_380 ;
unsigned int V_381 , V_382 , V_383 , V_384 ;
unsigned char V_385 , V_386 ;
T_6 V_374 ;
unsigned int V_375 ;
V_118 = V_178 -> V_280 ;
if ( F_118 ( V_349 ) == V_366 )
V_48 = V_113 ;
else if ( F_118 ( V_349 ) == V_367 )
V_48 = V_111 ;
else
return F_106 ( - V_128 ) ;
V_363 = V_351 - V_350 + 1 ;
V_379 = V_353 - V_352 + 1 ;
V_296 = 1 + V_379 ;
V_297 = sizeof( struct V_93 ) +
V_363 * sizeof( unsigned long long ) ;
V_168 = F_43 ( V_176 , V_296 , V_297 ,
V_119 ) ;
if ( F_44 ( V_168 ) )
return V_168 ;
V_45 = V_168 -> V_171 ;
if ( V_352 == V_353 )
V_100 = V_355 - V_354 + 1 ;
else
V_100 = V_355 + 1 ;
V_100 *= V_121 ;
if ( F_20 ( V_45 ++ , V_168 -> V_29 , V_352 ,
V_353 , V_48 , V_118 , V_119 ,
1 , V_354 + 1 ,
V_379 , V_121 ,
V_100 ) == - V_229 ) {
F_46 ( V_168 , V_119 ) ;
return F_106 ( - V_229 ) ;
}
V_356 = ( unsigned long * ) ( V_168 -> V_29 + sizeof( struct V_93 ) ) ;
V_146 = V_350 ;
V_385 = 1 ;
V_386 = 0 ;
V_384 = 0 ;
V_378 = NULL ;
V_381 = 0 ;
F_119 (bv, req, iter) {
V_361 = F_121 ( V_360 -> V_369 ) + V_360 -> V_370 ;
V_382 = V_360 -> V_368 ;
while ( V_382 ) {
if ( V_385 ) {
V_374 = V_146 ;
V_375 = F_123 ( V_374 , V_145 ) ;
V_380 = V_145 - V_375 ;
V_42 = F_127 ( ( V_351 - V_146 + 1 ) ,
( T_6 ) V_380 ) ;
V_384 = V_42 * V_121 ;
V_45 [ - 1 ] . V_43 |= V_242 ;
V_45 -> V_54 = V_48 ;
V_45 -> V_42 = V_384 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_356 ;
V_45 -> V_43 = V_376 ;
V_45 ++ ;
V_146 += V_42 ;
V_385 = 0 ;
if ( ! V_378 )
V_378 = V_361 ;
}
if ( ! V_378 ) {
if ( F_14 ( V_361 ) & ( V_387 - 1 ) ) {
F_46 ( V_168 , V_119 ) ;
return F_106 ( - V_388 ) ;
} else
V_378 = V_361 ;
}
if ( ( V_378 + V_381 ) != V_361 ) {
F_46 ( V_168 , V_119 ) ;
return F_106 ( - V_388 ) ;
}
V_383 = F_127 ( V_382 , V_384 ) ;
V_382 -= V_383 ;
V_361 += V_383 ;
V_381 += V_383 ;
V_384 -= V_383 ;
if ( ! ( F_14 ( V_378 + V_381 ) & ( V_387 - 1 ) ) )
V_386 = 1 ;
if ( ! V_384 ) {
V_385 = 1 ;
V_386 = 1 ;
}
if ( V_386 ) {
V_356 = F_124 ( V_356 , V_378 ,
V_381 ) ;
V_378 = NULL ;
V_381 = 0 ;
V_386 = 0 ;
}
}
}
if ( F_125 ( V_349 ) ||
V_178 -> V_280 -> V_237 & V_377 )
F_34 ( V_253 , & V_168 -> V_43 ) ;
V_168 -> V_119 = V_119 ;
V_168 -> V_177 = V_119 ;
V_168 -> V_178 = V_178 ;
V_168 -> V_179 = V_119 -> V_275 * V_180 ;
V_168 -> V_170 = V_119 -> V_212 . V_216 ;
V_168 -> V_181 = 256 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
return V_168 ;
}
static int F_128 ( struct V_389 * V_389 ,
unsigned int V_46 , unsigned int V_47 , int V_48 ,
struct V_30 * V_118 ,
struct V_30 * V_119 ,
unsigned int V_98 , int V_42 ,
unsigned int V_121 ,
unsigned int V_390 ,
unsigned int V_100 ,
unsigned int V_145 )
{
struct V_93 V_94 ;
struct V_32 * V_122 , * V_123 ;
struct V_28 * V_124 ;
struct V_97 * V_125 ;
struct V_391 * V_391 ;
T_3 V_49 , V_50 ;
T_4 V_51 , V_52 , V_53 ;
T_7 V_392 ;
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
V_125 -> V_104 . V_393 = 0x01 ;
V_392 = V_394 ;
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
V_125 -> V_104 . V_393 = 0x2 ;
V_392 = V_127 ;
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
V_124 -> V_395 = 0x20 ;
V_124 -> V_396 = V_145 ;
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
V_125 -> V_104 . V_397 = 1 ;
V_125 -> V_104 . V_398 = 1 ;
V_125 -> V_106 = V_100 ;
V_125 -> V_399 = V_48 ;
V_125 -> V_42 = V_42 ;
V_125 -> V_101 = V_101 ;
F_10 ( & V_125 -> V_115 , V_49 , V_52 ) ;
V_125 -> V_116 . V_23 = V_125 -> V_115 . V_23 ;
V_125 -> V_116 . V_24 = V_125 -> V_115 . V_24 ;
V_125 -> V_116 . V_117 = V_98 ;
V_391 = F_129 ( V_389 , V_392 , 0 ,
& V_94 , sizeof( V_94 ) , V_390 ) ;
return F_44 ( V_391 ) ? F_69 ( V_391 ) : 0 ;
}
static struct V_167 * F_130 (
struct V_30 * V_119 ,
struct V_267 * V_178 ,
struct V_348 * V_349 ,
T_6 V_350 ,
T_6 V_351 ,
T_6 V_352 ,
T_6 V_353 ,
unsigned int V_354 ,
unsigned int V_355 ,
unsigned int V_145 ,
unsigned int V_121 )
{
struct V_167 * V_168 ;
struct V_357 V_358 ;
struct V_359 * V_360 ;
char * V_361 ;
unsigned int V_379 , V_400 ;
unsigned char V_48 ;
struct V_30 * V_118 ;
unsigned int V_100 ;
struct V_389 * V_389 ;
struct V_401 * V_402 = NULL ;
int V_403 ;
T_8 V_404 ;
T_7 V_405 ;
unsigned int V_382 , V_383 , V_384 ;
unsigned char V_385 ;
T_6 V_146 , V_374 ;
unsigned int V_406 ;
unsigned int V_42 , V_380 ;
int V_3 ;
V_118 = V_178 -> V_280 ;
if ( F_118 ( V_349 ) == V_366 ) {
V_48 = V_113 ;
V_403 = V_407 ;
} else if ( F_118 ( V_349 ) == V_367 ) {
V_48 = V_111 ;
V_403 = V_408 ;
} else
return F_106 ( - V_128 ) ;
V_379 = V_353 - V_352 + 1 ;
V_400 = 0 ;
F_119 (bv, req, iter) {
++ V_400 ;
}
if ( F_118 ( V_349 ) == V_367 )
V_400 += ( V_353 - V_352 ) ;
V_404 = F_131 ( 0 , V_400 , 0 ) ;
V_168 = F_43 ( V_176 , 0 , V_404 , V_119 ) ;
if ( F_44 ( V_168 ) )
return V_168 ;
if ( V_352 == V_353 )
V_100 = V_355 - V_354 + 1 ;
else
V_100 = V_355 + 1 ;
V_100 *= V_121 ;
V_389 = F_132 ( V_168 -> V_29 , V_404 , V_403 , 0 , V_400 , 0 ) ;
if ( F_44 ( V_389 ) ) {
V_3 = - V_128 ;
goto V_194;
}
V_168 -> V_171 = F_133 ( V_389 ) ;
if ( F_128 ( V_389 , V_352 , V_353 ,
V_48 , V_118 , V_119 ,
V_354 + 1 ,
V_379 , V_121 ,
( V_351 - V_350 + 1 ) * V_121 ,
V_100 , V_145 ) == - V_229 ) {
V_3 = - V_229 ;
goto V_194;
}
V_384 = 0 ;
if ( F_118 ( V_349 ) == V_367 ) {
V_385 = 1 ;
V_146 = V_350 ;
F_119 (bv, req, iter) {
V_361 = F_121 ( V_360 -> V_369 ) + V_360 -> V_370 ;
V_382 = V_360 -> V_368 ;
while ( V_382 ) {
if ( V_385 ) {
V_374 = V_146 ;
V_406 = F_123 ( V_374 , V_145 ) ;
V_380 = V_145 - V_406 ;
V_42 = F_127 ( ( V_351 - V_146 + 1 ) ,
( T_6 ) V_380 ) ;
V_384 = V_42 * V_121 ;
V_146 += V_42 ;
V_385 = 0 ;
}
V_383 = F_127 ( V_382 , V_384 ) ;
V_382 -= V_383 ;
V_384 -= V_383 ;
if ( ! V_384 ) {
V_385 = 1 ;
V_405 = V_409 ;
} else
V_405 = 0 ;
V_402 = F_134 ( V_389 , V_405 ,
V_361 , V_383 ) ;
if ( F_44 ( V_402 ) ) {
V_3 = - V_128 ;
goto V_194;
}
V_361 += V_383 ;
}
}
} else {
F_119 (bv, req, iter) {
V_361 = F_121 ( V_360 -> V_369 ) + V_360 -> V_370 ;
V_402 = F_134 ( V_389 , 0x00 ,
V_361 , V_360 -> V_368 ) ;
if ( F_44 ( V_402 ) ) {
V_3 = - V_128 ;
goto V_194;
}
}
}
V_402 -> V_43 |= V_410 ;
V_402 -> V_43 &= ~ V_409 ;
F_135 ( V_389 ) ;
if ( F_125 ( V_349 ) ||
V_178 -> V_280 -> V_237 & V_377 )
F_34 ( V_253 , & V_168 -> V_43 ) ;
V_168 -> V_411 = 1 ;
V_168 -> V_119 = V_119 ;
V_168 -> V_177 = V_119 ;
V_168 -> V_178 = V_178 ;
V_168 -> V_179 = V_119 -> V_275 * V_180 ;
V_168 -> V_170 = V_119 -> V_212 . V_216 ;
V_168 -> V_181 = 256 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
return V_168 ;
V_194:
F_46 ( V_168 , V_119 ) ;
return F_106 ( V_3 ) ;
}
static struct V_167 * F_136 ( struct V_30 * V_119 ,
struct V_267 * V_178 ,
struct V_348 * V_349 )
{
int V_412 , V_413 ;
int V_365 ;
int V_414 ;
struct V_32 * V_33 ;
struct V_30 * V_118 ;
T_6 V_350 , V_351 ;
T_6 V_352 , V_353 ;
unsigned int V_354 , V_355 ;
unsigned int V_145 , V_121 ;
int V_415 ;
unsigned int V_416 ;
struct V_167 * V_168 ;
V_118 = V_178 -> V_280 ;
V_33 = (struct V_32 * ) V_118 -> V_33 ;
V_121 = V_178 -> V_310 ;
V_145 = F_9 ( & V_33 -> V_35 , 0 , V_121 ) ;
if ( V_145 == 0 )
return F_106 ( - V_128 ) ;
V_350 = V_352 = F_137 ( V_349 ) >> V_178 -> V_313 ;
V_354 = F_123 ( V_352 , V_145 ) ;
V_351 = V_353 =
( F_137 ( V_349 ) + F_138 ( V_349 ) - 1 ) >> V_178 -> V_313 ;
V_355 = F_123 ( V_353 , V_145 ) ;
V_415 = ( V_33 -> V_85 && V_350 < 2 * V_145 ) ;
V_414 = V_33 -> V_237 . V_266 [ 40 ] & 0x20 ;
V_416 = F_139 ( V_349 ) ;
if ( F_118 ( V_349 ) == V_367 )
V_416 += ( V_353 - V_352 ) * 4 ;
V_412 = V_33 -> V_237 . V_266 [ 9 ] & 0x20 ;
V_413 = V_33 -> V_237 . V_266 [ 12 ] & 0x40 ;
V_365 = V_33 -> V_237 . V_266 [ 8 ] & 0x01 ;
V_168 = NULL ;
if ( V_415 || V_371 ) {
} else if ( ( V_416 <= V_33 -> V_218 )
&& ( V_414 || ( V_352 == V_353 ) ) ) {
V_168 = F_130 ( V_119 , V_178 , V_349 ,
V_350 , V_351 ,
V_352 , V_353 ,
V_354 , V_355 ,
V_145 , V_121 ) ;
if ( F_44 ( V_168 ) && ( F_69 ( V_168 ) != - V_229 ) &&
( F_69 ( V_168 ) != - V_197 ) )
V_168 = NULL ;
} else if ( V_365 &&
( ( ( F_118 ( V_349 ) == V_366 ) && V_412 ) ||
( ( F_118 ( V_349 ) == V_367 ) && V_413 ) ) ) {
V_168 = F_126 ( V_119 , V_178 , V_349 ,
V_350 , V_351 ,
V_352 , V_353 ,
V_354 , V_355 ,
V_145 , V_121 ) ;
if ( F_44 ( V_168 ) && ( F_69 ( V_168 ) != - V_229 ) &&
( F_69 ( V_168 ) != - V_197 ) )
V_168 = NULL ;
}
if ( ! V_168 )
V_168 = F_117 ( V_119 , V_178 , V_349 ,
V_350 , V_351 ,
V_352 , V_353 ,
V_354 , V_355 ,
V_145 , V_121 ) ;
return V_168 ;
}
static struct V_167 * F_140 ( struct V_30 * V_119 ,
struct V_267 * V_178 ,
struct V_348 * V_349 )
{
unsigned long * V_356 ;
struct V_30 * V_118 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
struct V_357 V_358 ;
struct V_359 * V_360 ;
char * V_361 ;
unsigned char V_48 ;
unsigned int V_379 ;
unsigned int V_382 , V_384 ;
unsigned int V_354 ;
unsigned int V_363 , V_296 , V_297 ;
T_6 V_352 , V_353 ;
unsigned int V_417 ;
if ( ( F_137 ( V_349 ) % V_418 ) != 0 ) {
V_168 = F_106 ( - V_128 ) ;
goto V_419;
}
if ( ( ( F_137 ( V_349 ) + F_138 ( V_349 ) ) %
V_418 ) != 0 ) {
V_168 = F_106 ( - V_128 ) ;
goto V_419;
}
V_352 = F_137 ( V_349 ) / V_418 ;
V_353 = ( F_137 ( V_349 ) + F_138 ( V_349 ) - 1 ) /
V_418 ;
V_379 = V_353 - V_352 + 1 ;
V_354 = 0 ;
V_118 = V_178 -> V_280 ;
if ( F_118 ( V_349 ) == V_366 )
V_48 = V_112 ;
else if ( F_118 ( V_349 ) == V_367 )
V_48 = V_107 ;
else {
V_168 = F_106 ( - V_128 ) ;
goto V_419;
}
V_363 = V_379 * V_312 ;
V_296 = 1 + V_379 ;
V_417 = sizeof( struct V_93 ) + 8 ;
V_297 = V_417 + V_363 * sizeof( unsigned long long ) ;
V_168 = F_43 ( V_176 , V_296 ,
V_297 , V_119 ) ;
if ( F_44 ( V_168 ) )
goto V_419;
V_45 = V_168 -> V_171 ;
if ( F_20 ( V_45 ++ , V_168 -> V_29 , V_352 , V_353 , V_48 ,
V_118 , V_119 , 1 , V_354 + 1 ,
V_379 , 0 , 0 ) == - V_229 ) {
F_46 ( V_168 , V_119 ) ;
V_168 = F_106 ( - V_229 ) ;
goto V_419;
}
V_356 = ( unsigned long * ) ( V_168 -> V_29 + V_417 ) ;
V_384 = 0 ;
F_119 (bv, req, iter) {
V_361 = F_121 ( V_360 -> V_369 ) + V_360 -> V_370 ;
V_382 = V_360 -> V_368 ;
if ( ! V_384 ) {
V_45 [ - 1 ] . V_43 |= V_242 ;
V_45 -> V_54 = V_48 ;
V_45 -> V_42 = 57326 ;
V_384 = 65536 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_356 ;
V_45 -> V_43 |= V_376 ;
V_45 -> V_43 |= V_44 ;
V_45 ++ ;
}
V_384 -= V_382 ;
V_356 = F_124 ( V_356 , V_361 , V_382 ) ;
}
if ( F_125 ( V_349 ) ||
V_178 -> V_280 -> V_237 & V_377 )
F_34 ( V_253 , & V_168 -> V_43 ) ;
V_168 -> V_119 = V_119 ;
V_168 -> V_177 = V_119 ;
V_168 -> V_178 = V_178 ;
V_168 -> V_179 = V_119 -> V_275 * V_180 ;
V_168 -> V_170 = V_119 -> V_212 . V_216 ;
V_168 -> V_181 = 256 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
if ( F_44 ( V_168 ) && F_69 ( V_168 ) != - V_229 )
V_168 = NULL ;
V_419:
return V_168 ;
}
static int
F_141 ( struct V_167 * V_168 , struct V_348 * V_349 )
{
struct V_32 * V_33 ;
struct V_26 * V_45 ;
struct V_357 V_358 ;
struct V_359 * V_360 ;
char * V_361 , * V_56 ;
unsigned int V_121 , V_145 , V_362 ;
T_6 V_146 ;
int V_183 ;
if ( ! V_371 )
goto V_419;
V_33 = (struct V_32 * ) V_168 -> V_178 -> V_280 -> V_33 ;
V_121 = V_168 -> V_178 -> V_310 ;
V_145 = F_9 ( & V_33 -> V_35 , 0 , V_121 ) ;
V_146 = F_137 ( V_349 ) >> V_168 -> V_178 -> V_313 ;
V_45 = V_168 -> V_171 ;
V_45 ++ ;
if ( V_33 -> V_85 == 0 || V_146 > 2 * V_145 )
V_45 ++ ;
F_119 (bv, req, iter) {
V_361 = F_121 ( V_360 -> V_369 ) + V_360 -> V_370 ;
for ( V_362 = 0 ; V_362 < V_360 -> V_368 ; V_362 += V_121 ) {
if ( V_33 -> V_85 && V_146 <= 2 * V_145 )
V_45 ++ ;
if ( V_361 ) {
if ( V_45 -> V_43 & V_376 )
V_56 = * ( ( char * * ) ( ( V_173 ) V_45 -> V_56 ) ) ;
else
V_56 = ( char * ) ( ( V_173 ) V_45 -> V_56 ) ;
if ( V_361 != V_56 ) {
if ( F_118 ( V_349 ) == V_366 )
memcpy ( V_361 , V_56 , V_360 -> V_368 ) ;
F_142 ( V_371 ,
( void * ) ( ( V_173 ) V_56 & V_420 ) ) ;
}
V_361 = NULL ;
}
V_45 ++ ;
V_146 ++ ;
}
}
V_419:
V_183 = V_168 -> V_183 == V_186 ;
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_183 ;
}
void F_108 ( struct V_167 * V_168 )
{
struct V_26 * V_45 ;
struct V_93 * V_94 ;
struct V_421 * V_421 ;
struct V_422 * V_422 ;
struct V_391 * V_391 ;
if ( V_168 -> V_411 == 1 ) {
V_421 = V_168 -> V_171 ;
V_422 = F_143 ( V_421 ) ;
V_391 = (struct V_391 * ) & V_422 -> V_423 [ 0 ] ;
V_94 = (struct V_93 * ) & V_391 -> V_424 [ 0 ] ;
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
static struct V_167 * F_144 ( struct V_30 * V_280 ,
struct V_267 * V_178 ,
struct V_348 * V_349 )
{
struct V_32 * V_33 ;
struct V_30 * V_119 ;
unsigned long V_43 ;
struct V_167 * V_168 ;
V_119 = F_145 ( V_280 ) ;
if ( ! V_119 )
V_119 = V_280 ;
V_33 = (struct V_32 * ) V_119 -> V_33 ;
if ( V_33 -> V_42 >= V_425 )
return F_106 ( - V_426 ) ;
F_27 ( F_28 ( V_119 -> V_2 ) , V_43 ) ;
V_33 -> V_42 ++ ;
if ( ( V_280 -> V_237 & V_283 ) )
V_168 = F_140 ( V_119 , V_178 , V_349 ) ;
else
V_168 = F_136 ( V_119 , V_178 , V_349 ) ;
if ( F_44 ( V_168 ) )
V_33 -> V_42 -- ;
F_29 ( F_28 ( V_119 -> V_2 ) , V_43 ) ;
return V_168 ;
}
static int F_146 ( struct V_167 * V_168 ,
struct V_348 * V_349 )
{
struct V_32 * V_33 ;
unsigned long V_43 ;
F_27 ( F_28 ( V_168 -> V_177 -> V_2 ) , V_43 ) ;
V_33 = (struct V_32 * ) V_168 -> V_177 -> V_33 ;
V_33 -> V_42 -- ;
F_29 ( F_28 ( V_168 -> V_177 -> V_2 ) , V_43 ) ;
return F_141 ( V_168 , V_349 ) ;
}
static int
F_147 ( struct V_30 * V_31 ,
struct V_427 * V_428 )
{
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_428 -> V_429 = 2 ;
V_428 -> V_430 = V_33 -> V_85 ? 0 : 1 ;
V_428 -> V_120 = V_33 -> V_85 ? V_431 : V_432 ;
V_428 -> V_433 = sizeof( struct V_14 ) ;
memcpy ( V_428 -> V_434 , & V_33 -> V_35 ,
sizeof( struct V_14 ) ) ;
V_428 -> V_435 = F_127 ( ( unsigned long ) V_33 -> V_200 ,
sizeof( V_428 -> V_436 ) ) ;
memcpy ( V_428 -> V_436 , V_33 -> V_201 ,
V_428 -> V_435 ) ;
return 0 ;
}
static int
F_148 ( struct V_30 * V_31 )
{
struct V_167 * V_168 ;
int V_34 ;
struct V_26 * V_45 ;
int V_437 ;
if ( ! F_149 ( V_438 ) )
return - V_41 ;
V_437 = 0 ;
V_168 = F_43 ( V_176 , 1 , 32 , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_150 ( & V_439 ) ;
V_437 = 1 ;
V_168 = & V_440 -> V_168 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
memset ( & V_440 -> V_45 , 0 ,
sizeof( V_440 -> V_45 ) ) ;
V_168 -> V_171 = & V_440 -> V_45 ;
V_168 -> V_29 = & V_440 -> V_29 ;
V_168 -> V_175 = V_176 ;
}
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_441 ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_42 = 32 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_168 -> V_29 ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
F_39 ( V_189 , & V_168 -> V_43 ) ;
F_34 ( V_253 , & V_168 -> V_43 ) ;
V_168 -> V_181 = 2 ;
V_168 -> V_179 = 2 * V_180 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_40 ( V_168 ) ;
if ( ! V_34 )
F_39 ( V_345 , & V_31 -> V_43 ) ;
if ( V_437 )
F_62 ( & V_439 ) ;
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
int V_437 ;
if ( ! F_149 ( V_438 ) )
return - V_41 ;
V_437 = 0 ;
V_168 = F_43 ( V_176 , 1 , 32 , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_150 ( & V_439 ) ;
V_437 = 1 ;
V_168 = & V_440 -> V_168 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
memset ( & V_440 -> V_45 , 0 ,
sizeof( V_440 -> V_45 ) ) ;
V_168 -> V_171 = & V_440 -> V_45 ;
V_168 -> V_29 = & V_440 -> V_29 ;
V_168 -> V_175 = V_176 ;
}
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_442 ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_42 = 32 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_168 -> V_29 ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
F_39 ( V_189 , & V_168 -> V_43 ) ;
F_34 ( V_253 , & V_168 -> V_43 ) ;
V_168 -> V_181 = 2 ;
V_168 -> V_179 = 2 * V_180 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_40 ( V_168 ) ;
if ( ! V_34 )
F_34 ( V_345 , & V_31 -> V_43 ) ;
if ( V_437 )
F_62 ( & V_439 ) ;
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
int V_437 ;
if ( ! F_149 ( V_438 ) )
return - V_41 ;
V_437 = 0 ;
V_168 = F_43 ( V_176 , 1 , 32 , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_150 ( & V_439 ) ;
V_437 = 1 ;
V_168 = & V_440 -> V_168 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
memset ( & V_440 -> V_45 , 0 ,
sizeof( V_440 -> V_45 ) ) ;
V_168 -> V_171 = & V_440 -> V_45 ;
V_168 -> V_29 = & V_440 -> V_29 ;
V_168 -> V_175 = V_176 ;
}
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_443 ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_42 = 32 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_168 -> V_29 ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
F_39 ( V_189 , & V_168 -> V_43 ) ;
F_34 ( V_253 , & V_168 -> V_43 ) ;
V_168 -> V_181 = 2 ;
V_168 -> V_179 = 2 * V_180 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_40 ( V_168 ) ;
if ( ! V_34 )
F_34 ( V_345 , & V_31 -> V_43 ) ;
if ( V_437 )
F_62 ( & V_439 ) ;
else
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int F_153 ( struct V_30 * V_31 ,
void T_9 * V_444 )
{
struct V_167 * V_168 ;
int V_34 ;
struct V_26 * V_45 ;
int V_437 ;
struct V_445 V_446 ;
if ( ! F_149 ( V_438 ) )
return - V_41 ;
if ( F_154 ( & V_446 , V_444 , sizeof( V_446 ) ) )
return - V_447 ;
V_437 = 0 ;
V_168 = F_43 ( V_176 , 1 ,
sizeof( struct V_448 ) , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_150 ( & V_439 ) ;
V_437 = 1 ;
V_168 = & V_440 -> V_168 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
memset ( & V_440 -> V_45 , 0 ,
sizeof( V_440 -> V_45 ) ) ;
V_168 -> V_171 = & V_440 -> V_45 ;
V_168 -> V_29 = & V_440 -> V_29 ;
V_168 -> V_175 = V_176 ;
}
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_449 ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_42 = 12 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_168 -> V_29 ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
F_39 ( V_189 , & V_168 -> V_43 ) ;
F_34 ( V_253 , & V_168 -> V_43 ) ;
F_34 ( V_190 , & V_168 -> V_43 ) ;
V_168 -> V_181 = 5 ;
V_168 -> V_179 = 10 * V_180 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_168 -> V_170 = V_446 . V_450 ;
V_34 = F_40 ( V_168 ) ;
if ( ! V_34 && V_446 . V_450 && ( V_168 -> V_170 != V_446 . V_450 ) )
V_34 = - V_271 ;
if ( ! V_34 ) {
V_446 . V_29 = * ( (struct V_448 * ) V_168 -> V_29 ) ;
if ( F_155 ( V_444 , & V_446 , sizeof( V_446 ) ) )
V_34 = - V_447 ;
}
if ( V_437 )
F_62 ( & V_439 ) ;
else
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int
F_156 ( struct V_30 * V_31 , void T_9 * V_444 )
{
struct V_234 * V_235 ;
struct V_451 * V_452 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
int V_34 ;
V_168 = F_43 ( V_176 , 1 + 1 ,
( sizeof( struct V_234 ) +
sizeof( struct V_451 ) ) ,
V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_18 ( V_7 , V_31 , L_1 ,
L_78 ) ;
return F_69 ( V_168 ) ;
}
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_181 = 0 ;
F_39 ( V_189 , & V_168 -> V_43 ) ;
V_168 -> V_179 = 10 * V_180 ;
V_235 = (struct V_234 * ) V_168 -> V_29 ;
memset ( V_235 , 0 , sizeof( struct V_234 ) ) ;
V_235 -> V_238 = V_239 ;
V_235 -> V_240 = 0x01 ;
V_235 -> V_453 [ 1 ] = 0x01 ;
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_241 ;
V_45 -> V_42 = sizeof( struct V_234 ) ;
V_45 -> V_43 |= V_242 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_235 ;
V_452 = (struct V_451 * ) ( V_235 + 1 ) ;
memset ( V_452 , 0 , sizeof( struct V_451 ) ) ;
V_45 ++ ;
V_45 -> V_54 = V_243 ;
V_45 -> V_42 = sizeof( struct V_451 ) ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_452 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_45 ( V_168 ) ;
if ( V_34 == 0 ) {
V_235 = (struct V_234 * ) V_168 -> V_29 ;
V_452 = (struct V_451 * ) ( V_235 + 1 ) ;
if ( F_155 ( V_444 , V_452 ,
sizeof( struct V_451 ) ) )
V_34 = - V_447 ;
}
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int
F_157 ( struct V_30 * V_31 , void T_9 * V_444 )
{
struct V_32 * V_33 =
(struct V_32 * ) V_31 -> V_33 ;
struct V_454 V_70 = V_33 -> V_70 ;
int V_34 ;
if ( ! F_149 ( V_438 ) )
return - V_41 ;
if ( ! V_444 )
return - V_128 ;
V_34 = 0 ;
if ( F_155 ( V_444 , ( long * ) & V_70 ,
sizeof( struct V_454 ) ) )
V_34 = - V_447 ;
return V_34 ;
}
static int
F_158 ( struct V_30 * V_31 , void T_9 * V_444 )
{
struct V_32 * V_33 =
(struct V_32 * ) V_31 -> V_33 ;
struct V_454 V_70 ;
if ( ! F_149 ( V_438 ) )
return - V_41 ;
if ( ! V_444 )
return - V_128 ;
if ( F_154 ( & V_70 , V_444 , sizeof( struct V_454 ) ) )
return - V_447 ;
V_33 -> V_70 = V_70 ;
F_81 ( & V_31 -> V_2 -> V_82 ,
L_79 ,
V_33 -> V_70 . V_69 , V_33 -> V_70 . V_89 ) ;
return 0 ;
}
static int F_159 ( struct V_30 * V_31 , void T_9 * V_444 )
{
struct V_455 V_446 ;
char * V_456 , * V_457 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
char V_458 , V_459 ;
int V_34 ;
if ( ! F_149 ( V_438 ) && ! F_149 ( V_460 ) )
return - V_41 ;
V_458 = V_459 = 0 ;
V_34 = - V_447 ;
if ( F_154 ( & V_446 , V_444 , sizeof( V_446 ) ) )
goto V_419;
if ( F_160 () || sizeof( long ) == 4 ) {
V_34 = - V_128 ;
if ( ( V_446 . V_456 >> 32 ) != 0 )
goto V_419;
if ( ( V_446 . V_457 >> 32 ) != 0 )
goto V_419;
V_446 . V_456 &= 0x7fffffffULL ;
V_446 . V_457 &= 0x7fffffffULL ;
}
V_456 = F_42 ( V_446 . V_461 , V_195 | V_196 ) ;
V_457 = F_42 ( V_446 . V_462 , V_195 | V_196 ) ;
if ( ! V_456 || ! V_457 ) {
V_34 = - V_197 ;
goto V_463;
}
V_34 = - V_447 ;
if ( F_154 ( V_456 ,
( void T_9 * ) ( unsigned long ) V_446 . V_456 ,
V_446 . V_461 ) )
goto V_463;
V_458 = V_456 [ 0 ] ;
V_459 = V_456 [ 1 ] ;
V_168 = F_43 ( V_176 , 2 , 0 , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_18 ( V_7 , V_31 , L_1 ,
L_78 ) ;
V_34 = F_69 ( V_168 ) ;
goto V_463;
}
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_181 = 3 ;
V_168 -> V_179 = 10 * V_180 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_241 ;
V_45 -> V_42 = V_446 . V_461 ;
V_45 -> V_43 |= V_242 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_456 ;
V_45 ++ ;
V_45 -> V_54 = V_243 ;
V_45 -> V_42 = V_446 . V_462 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_457 ;
V_34 = F_45 ( V_168 ) ;
if ( V_34 )
goto V_464;
V_34 = - V_447 ;
if ( F_155 ( ( void T_9 * ) ( unsigned long ) V_446 . V_457 ,
V_457 , V_446 . V_462 ) )
goto V_464;
V_34 = 0 ;
V_464:
F_46 ( V_168 , V_168 -> V_177 ) ;
V_463:
F_47 ( V_457 ) ;
F_47 ( V_456 ) ;
V_419:
F_18 ( V_7 , V_31 ,
L_80 ,
( int ) V_458 , ( int ) V_459 , V_34 ) ;
return V_34 ;
}
static int
F_161 ( struct V_267 * V_178 , unsigned int V_48 , void T_9 * V_444 )
{
struct V_30 * V_31 = V_178 -> V_280 ;
switch ( V_48 ) {
case V_465 :
return F_157 ( V_31 , V_444 ) ;
case V_466 :
return F_158 ( V_31 , V_444 ) ;
case V_467 :
return F_156 ( V_31 , V_444 ) ;
case V_468 :
return F_148 ( V_31 ) ;
case V_469 :
return F_151 ( V_31 ) ;
case V_470 :
return F_152 ( V_31 ) ;
case V_471 :
return F_153 ( V_31 , V_444 ) ;
case V_472 :
return F_159 ( V_31 , V_444 ) ;
default:
return - V_473 ;
}
}
static int
F_162 ( struct V_26 * V_474 , struct V_26 * V_475 , char * V_476 )
{
int V_477 , V_42 ;
char * V_478 ;
V_477 = 0 ;
while ( V_474 <= V_475 ) {
V_477 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_81 ,
from, ((int *) from)[0], ((int *) from)[1]) ;
if ( V_474 -> V_43 & V_376 )
V_478 = ( char * ) * ( ( V_173 * ) ( V_173 ) V_474 -> V_56 ) ;
else
V_478 = ( char * ) ( ( V_173 ) V_474 -> V_56 ) ;
for ( V_42 = 0 ; V_42 < V_474 -> V_42 && V_42 < 32 ; V_42 ++ ) {
if ( V_42 % 8 == 0 ) V_477 += sprintf ( V_476 + V_477 , L_82 ) ;
if ( V_42 % 4 == 0 ) V_477 += sprintf ( V_476 + V_477 , L_82 ) ;
V_477 += sprintf ( V_476 + V_477 , L_11 , V_478 [ V_42 ] ) ;
}
V_477 += sprintf ( V_476 + V_477 , L_83 ) ;
V_474 ++ ;
}
return V_477 ;
}
static void
F_163 ( struct V_30 * V_31 , struct V_304 * V_304 ,
char * V_479 )
{
T_10 * V_300 ;
T_10 * V_480 ;
V_300 = ( T_10 * ) F_91 ( V_304 ) ;
V_480 = ( T_10 * ) & V_304 -> V_340 ;
if ( V_300 ) {
F_18 ( V_481 , V_31 , L_84
L_85 ,
V_479 , * V_480 , * ( ( T_3 * ) ( V_480 + 1 ) ) ,
V_300 [ 0 ] , V_300 [ 1 ] , V_300 [ 2 ] , V_300 [ 3 ] ) ;
} else {
F_18 ( V_481 , V_31 , L_86 ,
V_479 , * V_480 , * ( ( T_3 * ) ( V_480 + 1 ) ) ,
L_87 ) ;
}
}
static void F_164 ( struct V_30 * V_31 ,
struct V_167 * V_349 , struct V_304 * V_304 )
{
char * V_476 ;
struct V_26 * V_482 , * V_483 , * V_484 , * V_474 , * V_475 ;
int V_477 , V_485 , V_486 ;
V_476 = ( char * ) F_165 ( V_232 ) ;
if ( V_476 == NULL ) {
F_18 ( V_7 , V_31 , L_1 ,
L_88 ) ;
return;
}
V_477 = sprintf (page, KERN_ERR PRINTK_HEADER
L_89 ,
dev_name(&device->cdev->dev)) ;
V_477 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_90
L_91 ,
req, scsw_cc(&irb->scsw), scsw_fctl(&irb->scsw),
scsw_actl(&irb->scsw), scsw_stctl(&irb->scsw),
scsw_dstat(&irb->scsw), scsw_cstat(&irb->scsw),
req ? req->intrc : 0 ) ;
V_477 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_92 ,
dev_name(&device->cdev->dev),
(void *) (addr_t) irb->scsw.cmd.cpa) ;
if ( V_304 -> V_487 . V_488 . V_489 . V_490 ) {
for ( V_485 = 0 ; V_485 < 4 ; V_485 ++ ) {
V_477 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_93 ,
(8 * sl), ((8 * sl) + 7)) ;
for ( V_486 = 0 ; V_486 < 8 ; V_486 ++ ) {
V_477 += sprintf ( V_476 + V_477 , L_94 ,
V_304 -> V_491 [ 8 * V_485 + V_486 ] ) ;
}
V_477 += sprintf ( V_476 + V_477 , L_83 ) ;
}
if ( V_304 -> V_491 [ 27 ] & V_342 ) {
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
F_166 ( L_1 , V_476 ) ;
if ( V_349 ) {
V_482 = V_349 -> V_171 ;
for ( V_483 = V_482 ; V_483 -> V_43 & ( V_242 | V_492 ) ; V_483 ++ ) ;
V_475 = F_127 ( V_482 + 6 , V_483 ) ;
V_477 = sprintf (page, KERN_ERR PRINTK_HEADER
L_101 , req) ;
F_162 ( V_482 , V_475 , V_476 + V_477 ) ;
F_166 ( L_1 , V_476 ) ;
V_477 = 0 ;
V_474 = ++ V_475 ;
V_484 = (struct V_26 * ) ( V_173 )
V_304 -> V_340 . V_48 . V_493 ;
if ( V_474 < V_484 - 2 ) {
V_474 = V_484 - 2 ;
V_477 += sprintf (page, KERN_ERR PRINTK_HEADER L_102 ) ;
}
V_475 = F_127 ( V_484 + 1 , V_483 ) ;
V_477 += F_162 ( V_474 , V_475 , V_476 + V_477 ) ;
V_474 = F_167 ( V_474 , ++ V_475 ) ;
if ( V_474 < V_483 - 1 ) {
V_474 = V_483 - 1 ;
V_477 += sprintf (page + len, KERN_ERR PRINTK_HEADER L_102 ) ;
}
V_477 += F_162 ( V_474 , V_483 , V_476 + V_477 ) ;
if ( V_477 > 0 )
F_166 ( L_1 , V_476 ) ;
}
F_168 ( ( unsigned long ) V_476 ) ;
}
static void F_169 ( struct V_30 * V_31 ,
struct V_167 * V_349 , struct V_304 * V_304 )
{
char * V_476 ;
int V_477 , V_485 , V_486 , V_494 ;
struct V_495 * V_495 ;
T_7 * V_300 , * V_496 ;
V_476 = ( char * ) F_165 ( V_232 ) ;
if ( V_476 == NULL ) {
F_18 ( V_7 , V_31 , L_103 ,
L_104 ) ;
return;
}
V_477 = sprintf (page, KERN_ERR PRINTK_HEADER
L_89 ,
dev_name(&device->cdev->dev)) ;
V_477 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_90
L_105 ,
req, scsw_cc(&irb->scsw), scsw_fctl(&irb->scsw),
scsw_actl(&irb->scsw), scsw_stctl(&irb->scsw),
scsw_dstat(&irb->scsw), scsw_cstat(&irb->scsw),
irb->scsw.tm.fcxs, irb->scsw.tm.schxs,
req ? req->intrc : 0 ) ;
V_477 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_106 ,
dev_name(&device->cdev->dev),
(void *) (addr_t) irb->scsw.tm.tcw) ;
V_495 = NULL ;
V_300 = NULL ;
if ( V_304 -> V_340 . V_497 . V_421 && ( V_304 -> V_340 . V_497 . V_498 & 0x01 ) )
V_495 = F_170 (
(struct V_421 * ) ( unsigned long ) V_304 -> V_340 . V_497 . V_421 ) ;
if ( V_495 ) {
V_477 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_107 , tsb->length) ;
V_477 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_108 , tsb->flags) ;
V_477 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_109 , tsb->dcw_offset) ;
V_477 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_110 , tsb->count) ;
V_494 = V_495 -> V_42 - 28 ;
V_477 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_111 , residual) ;
switch ( V_495 -> V_43 & 0x07 ) {
case 1 :
V_477 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_112 ,
tsb->tsa.iostat.dev_time) ;
V_477 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_113 ,
tsb->tsa.iostat.def_time) ;
V_477 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_114 ,
tsb->tsa.iostat.queue_time) ;
V_477 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_115 ,
tsb->tsa.iostat.dev_busy_time) ;
V_477 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_116 ,
tsb->tsa.iostat.dev_act_time) ;
V_300 = V_495 -> V_499 . V_500 . V_300 ;
break;
case 2 :
V_477 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_117 , tsb->tsa.ddpc.rc) ;
for ( V_485 = 0 ; V_485 < 2 ; V_485 ++ ) {
V_477 += sprintf (page + len,
KERN_ERR PRINTK_HEADER
L_118 ,
(8 * sl), ((8 * sl) + 7)) ;
V_496 = V_495 -> V_499 . V_501 . V_496 ;
for ( V_486 = 0 ; V_486 < 8 ; V_486 ++ ) {
V_477 += sprintf ( V_476 + V_477 , L_94 ,
V_496 [ 8 * V_485 + V_486 ] ) ;
}
V_477 += sprintf ( V_476 + V_477 , L_83 ) ;
}
V_300 = V_495 -> V_499 . V_501 . V_300 ;
break;
case 3 :
V_477 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_119 ) ;
break;
}
if ( V_300 ) {
for ( V_485 = 0 ; V_485 < 4 ; V_485 ++ ) {
V_477 += sprintf (page + len,
KERN_ERR PRINTK_HEADER
L_93 ,
(8 * sl), ((8 * sl) + 7)) ;
for ( V_486 = 0 ; V_486 < 8 ; V_486 ++ ) {
V_477 += sprintf ( V_476 + V_477 , L_94 ,
V_300 [ 8 * V_485 + V_486 ] ) ;
}
V_477 += sprintf ( V_476 + V_477 , L_83 ) ;
}
if ( V_300 [ 27 ] & V_342 ) {
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
F_166 ( L_1 , V_476 ) ;
F_168 ( ( unsigned long ) V_476 ) ;
}
static void F_171 ( struct V_30 * V_31 ,
struct V_167 * V_349 , struct V_304 * V_304 )
{
if ( F_172 ( & V_304 -> V_340 ) )
F_169 ( V_31 , V_349 , V_304 ) ;
else
F_164 ( V_31 , V_349 , V_304 ) ;
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
struct V_14 V_502 ;
int V_34 ;
struct V_149 V_268 ;
unsigned long V_43 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_34 = F_50 ( V_31 ) ;
if ( V_34 )
goto V_503;
F_30 ( V_31 , & V_268 ) ;
V_34 = F_26 ( V_31 ) ;
F_27 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
if ( memcmp ( & V_33 -> V_134 , & V_268 , sizeof( struct V_149 ) ) != 0 )
F_15 ( & V_31 -> V_2 -> V_82 , L_121
L_122 ) ;
F_29 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
if ( V_34 )
goto V_503;
V_34 = F_83 ( V_31 ) ;
if ( V_34 )
return V_34 ;
F_73 ( V_31 , V_253 ) ;
V_34 = F_50 ( V_31 ) ;
if ( V_34 )
goto V_503;
F_68 ( V_31 ) ;
V_34 = F_84 ( V_31 , V_176 ,
& V_502 , 64 ) ;
if ( V_34 ) {
F_3 ( V_7 , V_31 -> V_2 ,
L_53 , V_34 ) ;
goto V_503;
}
F_27 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
memcpy ( & V_33 -> V_35 , & V_502 , sizeof( V_502 ) ) ;
F_29 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
F_100 ( V_31 ) ;
return 0 ;
V_503:
return - 1 ;
}
static int F_175 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
int V_34 , V_504 ;
char V_225 [ 60 ] ;
struct V_149 V_134 ;
unsigned long V_43 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
F_27 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
V_504 = V_33 -> V_134 . V_161 ;
F_29 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
V_34 = F_50 ( V_31 ) ;
if ( V_34 )
goto V_503;
V_34 = F_26 ( V_31 ) ;
if ( V_34 )
goto V_503;
F_176 ( V_31 ) ;
F_30 ( V_31 , & V_134 ) ;
if ( V_504 != V_134 . V_161 ) {
if ( strlen ( V_134 . V_163 ) > 0 )
snprintf ( V_225 , sizeof( V_225 ) ,
L_17 , V_134 . V_150 , V_134 . V_152 ,
V_134 . V_154 , V_134 . V_161 , V_134 . V_163 ) ;
else
snprintf ( V_225 , sizeof( V_225 ) ,
L_18 , V_134 . V_150 , V_134 . V_152 ,
V_134 . V_154 , V_134 . V_161 ) ;
F_81 ( & V_31 -> V_2 -> V_82 ,
L_123
L_124 , V_225 ) ;
}
return 0 ;
V_503:
return - 1 ;
}
static int T_11
F_177 ( void )
{
int V_3 ;
F_178 ( V_8 . V_505 , 4 ) ;
V_440 = F_64 ( sizeof( * V_440 ) ,
V_195 | V_196 ) ;
if ( ! V_440 )
return - V_197 ;
V_233 = F_64 ( sizeof( * V_233 ) ,
V_195 | V_196 ) ;
if ( ! V_233 ) {
F_47 ( V_440 ) ;
return - V_197 ;
}
V_3 = F_179 ( & V_506 ) ;
if ( ! V_3 )
F_180 () ;
else {
F_47 ( V_233 ) ;
F_47 ( V_440 ) ;
}
return V_3 ;
}
static void T_12
F_181 ( void )
{
F_182 ( & V_506 ) ;
F_47 ( V_233 ) ;
F_47 ( V_440 ) ;
}
