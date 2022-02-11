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
V_213 -> V_216 |= V_170 ;
continue;
}
V_211 . V_201 = NULL ;
V_211 . V_200 = 0 ;
}
switch ( F_49 ( V_201 , V_200 ) ) {
case 0x02 :
V_213 -> V_217 |= V_170 ;
break;
case 0x03 :
V_213 -> V_218 |= V_170 ;
break;
}
V_213 -> V_210 |= V_170 ;
V_213 -> V_216 &= ~ V_170 ;
V_213 -> V_219 &= ~ V_170 ;
V_213 -> V_220 &= ~ V_170 ;
if ( V_201 != V_33 -> V_201 )
F_47 ( V_201 ) ;
}
return V_209 ;
}
static int F_52 ( struct V_30 * V_31 , T_2 V_170 )
{
struct V_32 * V_33 ;
int V_221 ;
T_3 V_222 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
if ( V_33 -> V_222 ) {
V_221 = F_53 ( V_31 -> V_2 , V_170 ) ;
if ( ( V_221 < 0 ) ) {
F_54 ( & V_31 -> V_2 -> V_82 ,
L_22
L_23 ,
V_221 , V_170 ) ;
return V_221 ;
}
V_222 = V_221 * V_223 ;
if ( V_222 < V_33 -> V_222 ) {
F_54 ( & V_31 -> V_2 -> V_82 ,
L_24
L_25
L_26 , V_222 , V_170 ,
V_33 -> V_222 ) ;
return - V_41 ;
}
}
return 0 ;
}
static int F_55 ( struct V_30 * V_31 ,
struct V_224 * V_29 )
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
static void F_56 ( struct V_225 * V_226 )
{
struct V_224 * V_29 ;
struct V_30 * V_31 ;
struct V_32 V_211 ;
struct V_149 * V_134 ;
T_2 V_227 [ V_174 ] ;
T_2 V_170 , V_210 , V_217 , V_218 , V_228 , V_219 , V_216 ;
unsigned long V_43 ;
char V_229 [ 60 ] ;
int V_34 ;
V_29 = F_57 ( V_226 , struct V_224 , V_230 ) ;
V_31 = V_29 -> V_31 ;
if ( F_58 ( V_231 , & V_31 -> V_43 ) ) {
F_59 ( V_226 ) ;
return;
}
V_210 = 0 ;
V_217 = 0 ;
V_218 = 0 ;
V_228 = 0 ;
V_219 = 0 ;
V_216 = 0 ;
for ( V_170 = 0x80 ; V_170 ; V_170 >>= 1 ) {
if ( ! ( V_170 & V_29 -> V_232 ) )
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
V_217 |= V_170 ;
break;
case 0x03 :
V_218 |= V_170 ;
break;
}
V_210 |= V_170 ;
} else if ( V_34 == - V_40 ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_29
L_30 ) ;
V_210 |= V_170 ;
} else if ( V_34 == - V_233 ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_31
L_32 ) ;
V_228 |= V_170 ;
} else {
F_54 ( & V_31 -> V_2 -> V_82 ,
L_33
L_34 , V_34 , V_170 ) ;
continue;
}
if ( F_52 ( V_31 , V_170 ) ) {
V_210 &= ~ V_170 ;
V_217 &= ~ V_170 ;
V_218 &= ~ V_170 ;
V_219 |= V_170 ;
continue;
}
memcpy ( & V_227 , V_29 -> V_169 ,
V_174 ) ;
V_211 . V_201 = ( void * ) & V_227 ;
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
snprintf ( V_229 , sizeof( V_229 ) ,
L_17 ,
V_134 -> V_150 , V_134 -> V_152 ,
V_134 -> V_154 , V_134 -> V_157 ,
V_134 -> V_163 ) ;
else
snprintf ( V_229 , sizeof( V_229 ) ,
L_18 ,
V_134 -> V_150 , V_134 -> V_152 ,
V_134 -> V_154 ,
V_134 -> V_157 ) ;
F_15 ( & V_31 -> V_2 -> V_82 ,
L_35
L_36
L_37 ,
V_170 , V_229 ) ;
V_210 &= ~ V_170 ;
V_217 &= ~ V_170 ;
V_218 &= ~ V_170 ;
V_216 |= V_170 ;
continue;
}
}
F_27 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
if ( ! V_31 -> V_213 . V_210 && V_210 ) {
V_31 -> V_213 . V_210 = V_210 ;
V_31 -> V_213 . V_216 &= ~ V_210 ;
V_31 -> V_213 . V_220 &= ~ V_210 ;
V_31 -> V_213 . V_219 &= ~ V_210 ;
F_60 ( V_31 ) ;
} else {
V_31 -> V_213 . V_210 |= V_210 ;
V_31 -> V_213 . V_216 &= ~ V_210 ;
V_31 -> V_213 . V_220 &= ~ V_210 ;
V_31 -> V_213 . V_219 &= ~ V_210 ;
}
V_31 -> V_213 . V_217 |= V_217 ;
V_31 -> V_213 . V_218 |= V_218 ;
V_31 -> V_213 . V_232 |= V_228 ;
V_31 -> V_213 . V_216 |= V_216 ;
V_31 -> V_213 . V_219 |= V_219 ;
F_29 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
}
F_61 ( V_31 ) ;
if ( V_29 -> V_234 )
F_62 ( & V_235 ) ;
else
F_47 ( V_29 ) ;
}
static int F_63 ( struct V_30 * V_31 , T_2 V_170 )
{
struct V_224 * V_29 ;
V_29 = F_64 ( sizeof( * V_29 ) , V_236 | V_196 ) ;
if ( ! V_29 ) {
if ( F_65 ( & V_235 ) ) {
V_29 = V_237 ;
V_29 -> V_234 = 1 ;
} else
return - V_197 ;
} else {
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_29 -> V_234 = 0 ;
}
F_66 ( & V_29 -> V_230 , F_56 ) ;
F_67 ( V_31 ) ;
V_29 -> V_31 = V_31 ;
V_29 -> V_232 = V_170 ;
F_59 ( & V_29 -> V_230 ) ;
return 0 ;
}
static int F_68 ( struct V_30 * V_31 )
{
struct V_238 * V_239 ;
struct V_240 * V_241 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
int V_34 ;
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
memset ( & V_33 -> V_241 , 0 , sizeof( struct V_240 ) ) ;
V_168 = F_43 ( V_176 , 1 + 1 ,
( sizeof( struct V_238 ) +
sizeof( struct V_240 ) ) ,
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
V_239 = (struct V_238 * ) V_168 -> V_29 ;
memset ( V_239 , 0 , sizeof( struct V_238 ) ) ;
V_239 -> V_242 = V_243 ;
V_239 -> V_244 = 0x41 ;
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_245 ;
V_45 -> V_42 = sizeof( struct V_238 ) ;
V_45 -> V_43 |= V_246 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_239 ;
V_241 = (struct V_240 * ) ( V_239 + 1 ) ;
memset ( V_241 , 0 , sizeof( struct V_240 ) ) ;
V_45 ++ ;
V_45 -> V_54 = V_247 ;
V_45 -> V_42 = sizeof( struct V_240 ) ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_241 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_45 ( V_168 ) ;
if ( V_34 == 0 ) {
V_239 = (struct V_238 * ) V_168 -> V_29 ;
V_241 = (struct V_240 * ) ( V_239 + 1 ) ;
memcpy ( & V_33 -> V_241 , V_241 ,
sizeof( struct V_240 ) ) ;
} else
F_54 ( & V_31 -> V_2 -> V_82 , L_40
L_41 , V_34 ) ;
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static struct V_167 * F_70 ( struct V_30 * V_31 ,
int V_248 )
{
struct V_167 * V_168 ;
struct V_249 * V_250 ;
struct V_26 * V_45 ;
V_168 = F_43 ( V_176 , 1 ,
sizeof( struct V_249 ) ,
V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_18 ( V_7 , V_31 , L_1 ,
L_42 ) ;
return V_168 ;
}
V_250 = (struct V_249 * ) V_168 -> V_29 ;
V_250 -> V_242 = V_251 ;
V_250 -> V_244 = 0xc0 ;
if ( V_248 ) {
V_250 -> V_244 |= 0x08 ;
V_250 -> V_252 [ 0 ] = 0x88 ;
}
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_245 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_250 ;
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
F_71 ( struct V_30 * V_31 , int V_248 ,
unsigned long V_43 )
{
struct V_167 * V_168 ;
int V_34 ;
V_168 = F_70 ( V_31 , V_248 ) ;
if ( F_44 ( V_168 ) )
return F_69 ( V_168 ) ;
V_168 -> V_43 |= V_43 ;
V_34 = F_45 ( V_168 ) ;
if ( ! V_34 )
F_72 () ;
else if ( V_168 -> V_253 == - V_233 )
V_34 = - V_233 ;
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int F_73 ( struct V_30 * V_31 ,
unsigned long V_43 )
{
int V_34 ;
struct V_32 * V_33 ;
int V_248 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
if ( V_33 -> V_134 . type == V_160 ||
V_33 -> V_134 . type == V_137 )
return 0 ;
if ( V_254 || V_255 )
V_248 = 0 ;
else
V_248 = 1 ;
V_34 = F_71 ( V_31 , V_248 , V_43 ) ;
F_3 ( V_7 , V_31 -> V_2 , L_43
L_44 , V_33 -> V_134 . V_154 , V_34 ) ;
return V_34 ;
}
static void F_74 ( struct V_225 * V_226 )
{
struct V_30 * V_31 = F_57 ( V_226 , struct V_30 ,
V_256 ) ;
unsigned long V_43 = 0 ;
F_34 ( V_257 , & V_43 ) ;
if ( F_73 ( V_31 , V_43 )
== - V_233 ) {
F_59 ( & V_31 -> V_256 ) ;
return;
}
F_61 ( V_31 ) ;
}
static void F_75 ( struct V_30 * V_31 )
{
F_67 ( V_31 ) ;
if ( F_58 ( V_258 , & V_31 -> V_43 ) ||
V_31 -> V_259 < V_260 ) {
F_61 ( V_31 ) ;
return;
}
if ( ! F_59 ( & V_31 -> V_256 ) )
F_61 ( V_31 ) ;
}
static T_3 F_76 ( struct V_30 * V_31 )
{
int V_261 , V_221 ;
int V_262 , V_263 , V_264 ;
struct V_32 * V_33 ;
if ( V_265 )
return 0 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_262 = V_266 . V_267 ;
V_263 = V_33 -> V_155 -> V_268 [ 7 ] & 0x04 ;
V_264 = V_33 -> V_241 . V_269 [ 40 ] & 0x80 ;
V_261 = V_262 && V_263 && V_264 ;
if ( ! V_261 )
return 0 ;
V_221 = F_53 ( V_31 -> V_2 , 0 ) ;
if ( V_221 < 0 ) {
F_54 ( & V_31 -> V_2 -> V_82 , L_45
L_46 ) ;
return 0 ;
} else
return V_221 * V_223 ;
}
static int
F_77 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
struct V_270 * V_178 ;
struct V_149 V_271 ;
int V_34 , V_199 ;
int V_272 ;
unsigned long V_273 ;
F_66 ( & V_31 -> V_256 , F_74 ) ;
if ( ! F_78 ( V_31 -> V_2 ) ) {
F_54 ( & V_31 -> V_2 -> V_82 ,
L_47 ) ;
return - V_274 ;
}
if ( ! F_79 ( V_31 -> V_2 ) ) {
F_80 ( & V_31 -> V_2 -> V_82 ,
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
V_33 -> V_275 = - 1 ;
V_33 -> V_70 . V_69 = V_276 ;
V_33 -> V_70 . V_89 = 0 ;
V_34 = F_50 ( V_31 ) ;
if ( V_34 )
goto V_277;
V_31 -> V_278 = V_279 ;
V_31 -> V_280 = V_281 ;
if ( V_33 -> V_155 ) {
V_273 = 1 ;
for ( V_199 = 0 ; V_199 < V_33 -> V_155 -> V_282 . V_273 ; V_199 ++ )
V_273 = 10 * V_273 ;
V_273 = V_273 * V_33 -> V_155 -> V_282 . V_283 ;
if ( V_273 != 0 && V_273 <= V_284 )
V_31 -> V_278 = V_273 ;
}
F_30 ( V_31 , & V_271 ) ;
if ( V_271 . type == V_135 ) {
V_178 = F_81 () ;
if ( F_44 ( V_178 ) ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_51
L_52 ) ;
V_34 = F_69 ( V_178 ) ;
goto V_277;
}
V_31 -> V_178 = V_178 ;
V_178 -> V_285 = V_31 ;
}
V_34 = F_82 ( V_31 ) ;
if ( V_34 )
goto V_286;
F_73 ( V_31 , 0 ) ;
V_34 = F_50 ( V_31 ) ;
if ( V_34 )
goto V_287;
F_68 ( V_31 ) ;
V_34 = F_83 ( V_31 , V_176 ,
& V_33 -> V_35 , 64 ) ;
if ( V_34 ) {
F_3 ( V_7 , V_31 -> V_2 ,
L_53 , V_34 ) ;
goto V_287;
}
if ( ( V_31 -> V_241 & V_288 ) &&
! ( V_33 -> V_35 . V_36 . V_289 ) ) {
F_15 ( & V_31 -> V_2 -> V_82 , L_54
L_55 ) ;
V_34 = - V_128 ;
goto V_287;
}
if ( V_33 -> V_35 . V_290 == V_291 &&
V_33 -> V_35 . V_292 )
V_33 -> V_90 = V_33 -> V_35 . V_292 ;
else
V_33 -> V_90 = V_33 -> V_35 . V_290 ;
V_33 -> V_222 = F_76 ( V_31 ) ;
V_272 = F_84 ( V_31 ) ;
if ( V_272 )
F_34 ( V_293 , & V_31 -> V_43 ) ;
F_80 ( & V_31 -> V_2 -> V_82 , L_56
L_57 ,
V_33 -> V_35 . V_20 ,
V_33 -> V_35 . V_294 ,
V_33 -> V_35 . V_84 ,
V_33 -> V_35 . V_295 . V_296 ,
V_33 -> V_90 ,
V_33 -> V_35 . V_86 ,
V_33 -> V_35 . V_297 ,
V_272 ? L_58 : L_59 ) ;
return 0 ;
V_287:
F_85 ( V_31 ) ;
V_286:
F_86 ( V_31 -> V_178 ) ;
V_31 -> V_178 = NULL ;
V_277:
F_47 ( V_33 -> V_201 ) ;
F_47 ( V_31 -> V_33 ) ;
V_31 -> V_33 = NULL ;
return V_34 ;
}
static void F_87 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
F_85 ( V_31 ) ;
V_33 -> V_130 = NULL ;
V_33 -> V_158 = NULL ;
V_33 -> V_162 = NULL ;
V_33 -> V_155 = NULL ;
V_33 -> V_200 = 0 ;
F_47 ( V_33 -> V_201 ) ;
V_33 -> V_201 = NULL ;
}
static struct V_167 *
F_88 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
struct V_298 * V_299 ;
struct V_140 * V_300 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
int V_301 , V_302 ;
int V_199 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_301 = 8 ;
V_302 = sizeof( struct V_28 ) + 2 * sizeof( struct V_140 ) ;
V_168 = F_43 ( V_176 , V_301 , V_302 , V_31 ) ;
if ( F_44 ( V_168 ) )
return V_168 ;
V_45 = V_168 -> V_171 ;
F_13 ( V_45 ++ , V_168 -> V_29 , 0 , 2 ,
V_65 , V_31 ) ;
V_300 = V_168 -> V_29 + sizeof( struct V_28 ) ;
V_45 [ - 1 ] . V_43 |= V_246 ;
V_126 ( V_45 ++ , V_300 ++ , 0 , 0 , 4 ,
V_65 , V_31 , 0 ) ;
V_299 = V_33 -> V_303 ;
for ( V_199 = 0 ; V_199 < 4 ; V_199 ++ ) {
V_45 [ - 1 ] . V_43 |= V_246 ;
V_45 -> V_54 = V_65 ;
V_45 -> V_43 = 0 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_299 ;
V_45 ++ ;
V_299 ++ ;
}
V_45 [ - 1 ] . V_43 |= V_246 ;
V_126 ( V_45 ++ , V_300 ++ , 2 , 0 , 1 ,
V_65 , V_31 , 0 ) ;
V_45 [ - 1 ] . V_43 |= V_246 ;
V_45 -> V_54 = V_65 ;
V_45 -> V_43 = 0 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_299 ;
V_168 -> V_178 = NULL ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_181 = 255 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
return V_168 ;
}
static int F_89 ( struct V_167 * V_304 )
{
char * V_305 ;
if ( V_304 -> V_183 == V_186 )
return V_306 ;
else if ( V_304 -> V_183 == V_307 ||
V_304 -> V_183 == V_308 ) {
V_305 = F_90 ( & V_304 -> V_309 ) ;
if ( V_305 && ( V_305 [ 1 ] & V_310 ) )
return V_311 ;
else
return V_312 ;
} else
return V_312 ;
}
static void F_91 ( struct V_167 * V_304 ,
void * V_29 )
{
struct V_32 * V_33 ;
struct V_30 * V_31 ;
V_31 = V_304 -> V_119 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_33 -> V_275 = F_89 ( V_304 ) ;
F_46 ( V_304 , V_31 ) ;
F_92 ( V_31 ) ;
}
static int F_93 ( struct V_270 * V_178 )
{
struct V_167 * V_304 ;
V_304 = F_88 ( V_178 -> V_285 ) ;
if ( F_44 ( V_304 ) )
return F_69 ( V_304 ) ;
V_304 -> V_191 = F_91 ;
V_304 -> V_313 = NULL ;
V_304 -> V_179 = 5 * V_180 ;
F_39 ( V_189 , & V_304 -> V_43 ) ;
V_304 -> V_181 = 0 ;
F_94 ( V_304 ) ;
return - V_233 ;
}
static int F_95 ( struct V_270 * V_178 )
{
struct V_30 * V_31 ;
struct V_32 * V_33 ;
struct V_298 * V_303 ;
unsigned int V_314 , V_145 ;
int V_183 , V_199 ;
struct V_167 * V_304 ;
V_31 = V_178 -> V_285 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_183 = V_33 -> V_275 ;
V_33 -> V_275 = - 1 ;
if ( V_183 == V_312 ) {
V_304 = F_88 ( V_31 ) ;
F_45 ( V_304 ) ;
V_183 = F_89 ( V_304 ) ;
F_46 ( V_304 , V_31 ) ;
}
if ( V_31 -> V_241 & V_288 ) {
V_178 -> V_315 = V_316 ;
V_145 = V_317 ;
V_178 -> V_318 = 3 ;
goto V_319;
}
if ( V_183 == V_311 ) {
F_54 ( & V_31 -> V_2 -> V_82 , L_60 ) ;
return - V_320 ;
} else if ( V_183 == V_312 ) {
F_15 ( & V_31 -> V_2 -> V_82 ,
L_61
L_62 ) ;
return - V_274 ;
}
V_33 -> V_85 = 1 ;
V_303 = NULL ;
for ( V_199 = 0 ; V_199 < 3 ; V_199 ++ ) {
if ( V_33 -> V_303 [ V_199 ] . V_16 != 4 ||
V_33 -> V_303 [ V_199 ] . V_17 != F_23 ( V_199 ) - 4 ||
V_33 -> V_303 [ V_199 ] . V_23 != 0 ||
V_33 -> V_303 [ V_199 ] . V_24 != V_321 [ V_199 ] ||
V_33 -> V_303 [ V_199 ] . V_117 != V_322 [ V_199 ] ) {
V_33 -> V_85 = 0 ;
break;
}
}
if ( V_199 == 3 )
V_303 = & V_33 -> V_303 [ 4 ] ;
if ( V_33 -> V_85 == 0 ) {
for ( V_199 = 0 ; V_199 < 5 ; V_199 ++ ) {
if ( ( V_33 -> V_303 [ V_199 ] . V_16 != 0 ) ||
( V_33 -> V_303 [ V_199 ] . V_17 !=
V_33 -> V_303 [ 0 ] . V_17 ) ||
V_33 -> V_303 [ V_199 ] . V_23 != 0 ||
V_33 -> V_303 [ V_199 ] . V_24 != V_321 [ V_199 ] ||
V_33 -> V_303 [ V_199 ] . V_117 != V_322 [ V_199 ] )
break;
}
if ( V_199 == 5 )
V_303 = & V_33 -> V_303 [ 0 ] ;
} else {
if ( V_33 -> V_303 [ 3 ] . V_117 == 1 )
F_54 ( & V_31 -> V_2 -> V_82 ,
L_63 ) ;
}
if ( V_303 != NULL && V_303 -> V_16 == 0 ) {
if ( F_96 ( V_303 -> V_17 ) == 0 )
V_178 -> V_315 = V_303 -> V_17 ;
}
if ( V_178 -> V_315 == 0 ) {
F_54 ( & V_31 -> V_2 -> V_82 ,
L_64 ) ;
return - V_320 ;
}
V_178 -> V_318 = 0 ;
for ( V_314 = 512 ; V_314 < V_178 -> V_315 ; V_314 = V_314 << 1 )
V_178 -> V_318 ++ ;
V_145 = F_9 ( & V_33 -> V_35 , 0 , V_178 -> V_315 ) ;
V_319:
V_178 -> V_323 = ( V_33 -> V_90 *
V_33 -> V_35 . V_86 *
V_145 ) ;
F_80 ( & V_31 -> V_2 -> V_82 ,
L_65
L_66 , ( V_178 -> V_315 >> 10 ) ,
( ( V_33 -> V_90 *
V_33 -> V_35 . V_86 *
V_145 * ( V_178 -> V_315 >> 9 ) ) >> 1 ) ,
( ( V_145 * V_178 -> V_315 ) >> 10 ) ,
V_33 -> V_85 ?
L_67 : L_68 ) ;
return 0 ;
}
static int F_97 ( struct V_270 * V_178 )
{
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_178 -> V_285 -> V_33 ;
if ( V_33 -> V_275 < 0 )
return F_93 ( V_178 ) ;
else
return F_95 ( V_178 ) ;
}
static int F_98 ( struct V_30 * V_31 )
{
return F_99 ( V_31 ) ;
}
static int F_100 ( struct V_30 * V_31 )
{
F_101 ( & V_31 -> V_324 ) ;
F_101 ( & V_31 -> V_256 ) ;
return 0 ;
}
static int F_102 ( struct V_30 * V_31 )
{
return F_103 ( V_31 ) ;
}
static int
F_104 ( struct V_270 * V_178 , struct V_325 * V_22 )
{
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_178 -> V_285 -> V_33 ;
if ( F_96 ( V_178 -> V_315 ) == 0 ) {
V_22 -> V_326 = F_9 ( & V_33 -> V_35 ,
0 , V_178 -> V_315 ) ;
}
V_22 -> V_327 = V_33 -> V_35 . V_290 ;
V_22 -> V_51 = V_33 -> V_35 . V_86 ;
return 0 ;
}
static struct V_167 *
F_105 ( struct V_30 * V_285 ,
struct V_328 * V_329 ,
int V_248 )
{
struct V_32 * V_330 ;
struct V_32 * V_331 ;
struct V_30 * V_119 = NULL ;
struct V_167 * V_332 ;
struct V_298 * V_333 ;
struct V_21 V_334 ;
struct V_26 * V_45 ;
void * V_29 ;
int V_335 ;
int V_301 , V_302 ;
int V_199 , V_336 ;
int V_337 = 0 ;
int V_338 ;
int V_339 ;
int V_340 ;
if ( V_248 )
V_119 = F_106 ( V_285 ) ;
if ( ! V_119 )
V_119 = V_285 ;
V_331 = (struct V_32 * ) V_119 -> V_33 ;
V_330 = (struct V_32 * ) V_285 -> V_33 ;
V_335 = F_9 ( & V_330 -> V_35 , 0 , V_329 -> V_121 ) ;
V_339 = V_329 -> V_341 - V_329 -> V_342 + 1 ;
if ( V_329 -> V_337 & 0x10 ) {
V_338 = 0 ;
V_337 = V_329 -> V_337 & ~ 0x10 ;
} else {
V_338 = 1 ;
V_337 = V_329 -> V_337 ;
}
V_340 = V_330 -> V_241 . V_269 [ 8 ] & 0x01 ;
switch ( V_337 ) {
case 0x00 :
case 0x08 :
V_301 = 2 + ( V_335 * V_339 ) ;
if ( V_340 )
V_302 = sizeof( struct V_93 ) +
sizeof( struct V_140 ) +
V_335 * V_339 * sizeof( struct V_298 ) ;
else
V_302 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
V_335 * V_339 * sizeof( struct V_298 ) ;
break;
case 0x01 :
case 0x09 :
V_301 = 2 + V_335 * V_339 ;
if ( V_340 )
V_302 = sizeof( struct V_93 ) +
sizeof( struct V_140 ) +
sizeof( struct V_298 ) +
V_335 * V_339 * sizeof( struct V_298 ) ;
else
V_302 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
sizeof( struct V_298 ) +
V_335 * V_339 * sizeof( struct V_298 ) ;
break;
case 0x04 :
case 0x0c :
V_301 = 3 ;
if ( V_340 )
V_302 = sizeof( struct V_93 ) +
sizeof( struct V_140 ) +
sizeof( struct V_298 ) ;
else
V_302 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
sizeof( struct V_298 ) ;
break;
default:
F_54 ( & V_119 -> V_2 -> V_82 ,
L_69 ,
V_329 -> V_337 ) ;
return F_107 ( - V_128 ) ;
}
V_332 = F_43 ( V_176 , V_301 ,
V_302 , V_119 ) ;
if ( F_44 ( V_332 ) )
return V_332 ;
V_331 -> V_42 ++ ;
V_29 = V_332 -> V_29 ;
V_45 = V_332 -> V_171 ;
switch ( V_337 & ~ 0x08 ) {
case 0x00 :
if ( V_340 ) {
F_21 ( V_45 ++ , (struct V_93 * ) V_29 ,
V_329 -> V_342 , V_329 -> V_341 ,
V_75 , V_285 , V_119 ) ;
if ( V_338 )
( (struct V_93 * ) V_29 )
-> F_13 . V_38 |= 0x04 ;
V_29 += sizeof( struct V_93 ) ;
} else {
F_13 ( V_45 ++ , (struct V_28 * ) V_29 ,
V_329 -> V_342 , V_329 -> V_341 ,
V_75 , V_119 ) ;
if ( V_338 )
( (struct V_28 * ) V_29 )
-> V_38 |= 0x04 ;
V_29 += sizeof( struct V_28 ) ;
}
V_45 [ - 1 ] . V_43 |= V_246 ;
V_126 ( V_45 ++ , (struct V_140 * ) V_29 ,
V_329 -> V_342 , 0 , V_335 * V_339 ,
V_75 , V_285 ,
V_329 -> V_121 ) ;
V_29 += sizeof( struct V_140 ) ;
break;
case 0x01 :
if ( V_340 ) {
F_21 ( V_45 ++ , (struct V_93 * ) V_29 ,
V_329 -> V_342 , V_329 -> V_341 ,
V_80 ,
V_285 , V_119 ) ;
V_29 += sizeof( struct V_93 ) ;
} else {
F_13 ( V_45 ++ , (struct V_28 * ) V_29 ,
V_329 -> V_342 , V_329 -> V_341 ,
V_80 , V_119 ) ;
V_29 += sizeof( struct V_28 ) ;
}
V_45 [ - 1 ] . V_43 |= V_246 ;
V_126 ( V_45 ++ , (struct V_140 * ) V_29 ,
V_329 -> V_342 , 0 , V_335 * V_339 + 1 ,
V_80 , V_285 ,
V_285 -> V_178 -> V_315 ) ;
V_29 += sizeof( struct V_140 ) ;
break;
case 0x04 :
if ( V_340 ) {
F_21 ( V_45 ++ , (struct V_93 * ) V_29 ,
V_329 -> V_342 , V_329 -> V_341 ,
V_75 , V_285 , V_119 ) ;
V_29 += sizeof( struct V_93 ) ;
} else {
F_13 ( V_45 ++ , (struct V_28 * ) V_29 ,
V_329 -> V_342 , V_329 -> V_341 ,
V_75 , V_119 ) ;
V_29 += sizeof( struct V_28 ) ;
}
V_45 [ - 1 ] . V_43 |= V_246 ;
V_126 ( V_45 ++ , (struct V_140 * ) V_29 ,
V_329 -> V_342 , 0 , 1 ,
V_75 , V_285 , 8 ) ;
V_29 += sizeof( struct V_140 ) ;
break;
}
for ( V_336 = 0 ; V_336 < V_339 ; V_336 ++ ) {
F_10 ( & V_334 ,
( V_329 -> V_342 + V_336 ) /
V_330 -> V_35 . V_86 ,
( V_329 -> V_342 + V_336 ) %
V_330 -> V_35 . V_86 ) ;
if ( V_337 & 0x01 ) {
V_333 = (struct V_298 * ) V_29 ;
V_29 += sizeof( struct V_298 ) ;
V_333 -> V_23 = V_334 . V_23 ;
V_333 -> V_24 = V_334 . V_24 ;
V_333 -> V_117 = 0 ;
V_333 -> V_16 = 0 ;
V_333 -> V_17 = 8 ;
V_45 [ - 1 ] . V_43 |= V_246 ;
V_45 -> V_54 = V_80 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_333 ;
V_45 ++ ;
}
if ( ( V_337 & ~ 0x08 ) & 0x04 ) {
V_333 = (struct V_298 * ) V_29 ;
V_29 += sizeof( struct V_298 ) ;
V_333 -> V_23 = V_334 . V_23 ;
V_333 -> V_24 = V_334 . V_24 ;
V_333 -> V_117 = 1 ;
V_333 -> V_16 = 0 ;
V_333 -> V_17 = 0 ;
V_45 [ - 1 ] . V_43 |= V_246 ;
V_45 -> V_54 = V_75 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_333 ;
} else {
for ( V_199 = 0 ; V_199 < V_335 ; V_199 ++ ) {
V_333 = (struct V_298 * ) V_29 ;
V_29 += sizeof( struct V_298 ) ;
V_333 -> V_23 = V_334 . V_23 ;
V_333 -> V_24 = V_334 . V_24 ;
V_333 -> V_117 = V_199 + 1 ;
V_333 -> V_16 = 0 ;
V_333 -> V_17 = V_329 -> V_121 ;
if ( ( V_337 & 0x08 ) &&
V_329 -> V_342 == 0 ) {
if ( V_199 < 3 ) {
V_333 -> V_16 = 4 ;
V_333 -> V_17 = V_147 [ V_199 ] - 4 ;
}
}
if ( ( V_337 & 0x08 ) &&
V_329 -> V_342 == 1 ) {
V_333 -> V_16 = 44 ;
V_333 -> V_17 = V_148 - 44 ;
}
V_45 [ - 1 ] . V_43 |= V_246 ;
if ( V_199 != 0 || V_336 == 0 )
V_45 -> V_54 =
V_75 ;
else
V_45 -> V_54 =
V_76 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_333 ;
V_45 ++ ;
}
}
}
V_332 -> V_119 = V_119 ;
V_332 -> V_177 = V_119 ;
V_332 -> V_118 = V_285 ;
V_332 -> V_181 = 256 ;
V_332 -> V_179 = V_119 -> V_278 * V_180 ;
V_332 -> V_182 = F_33 () ;
V_332 -> V_183 = V_184 ;
return V_332 ;
}
static int
F_108 ( struct V_30 * V_285 ,
struct V_328 * V_329 ,
int V_248 )
{
struct V_167 * V_168 , * V_343 ;
struct V_270 * V_178 ;
struct V_32 * V_33 ;
struct V_344 V_345 ;
struct V_30 * V_31 ;
int V_346 , V_347 ;
int V_348 , V_34 = 0 , V_349 ;
V_178 = V_285 -> V_178 ;
V_33 = (struct V_32 * ) V_285 -> V_33 ;
if ( V_329 -> V_342 >=
( V_33 -> V_90 * V_33 -> V_35 . V_86 ) ) {
F_54 ( & V_285 -> V_2 -> V_82 ,
L_70 ,
V_329 -> V_342 ) ;
return - V_128 ;
}
if ( V_329 -> V_341 >=
( V_33 -> V_90 * V_33 -> V_35 . V_86 ) ) {
F_54 ( & V_285 -> V_2 -> V_82 ,
L_71 ,
V_329 -> V_341 ) ;
return - V_128 ;
}
if ( V_329 -> V_342 > V_329 -> V_341 ) {
F_54 ( & V_285 -> V_2 -> V_82 ,
L_72 ,
V_329 -> V_342 ) ;
return - V_128 ;
}
if ( F_96 ( V_329 -> V_121 ) != 0 ) {
F_54 ( & V_285 -> V_2 -> V_82 ,
L_73 ,
V_329 -> V_121 ) ;
return - V_128 ;
}
F_109 ( & V_345 ) ;
V_346 = V_329 -> V_341 ;
while ( V_329 -> V_342 <= 1 ) {
V_329 -> V_341 = V_329 -> V_342 ;
V_168 = F_105 ( V_285 , V_329 , V_248 ) ;
F_110 ( & V_168 -> V_350 , & V_345 ) ;
V_329 -> V_341 = V_346 ;
V_329 -> V_342 ++ ;
if ( V_329 -> V_342 > V_329 -> V_341 )
goto V_351;
}
V_352:
V_347 = 255 / F_9 ( & V_33 -> V_35 , 0 ,
V_329 -> V_121 ) ;
while ( V_329 -> V_342 <= V_346 ) {
V_348 = V_329 -> V_341 - V_329 -> V_342 + 1 ;
if ( V_348 > V_347 )
V_329 -> V_341 = V_329 -> V_342 + V_347 - 1 ;
V_168 = F_105 ( V_285 , V_329 , V_248 ) ;
if ( F_44 ( V_168 ) ) {
if ( F_69 ( V_168 ) == - V_197 ) {
V_329 -> V_341 = V_346 ;
goto V_351;
} else
return F_69 ( V_168 ) ;
}
F_110 ( & V_168 -> V_350 , & V_345 ) ;
V_329 -> V_342 = V_329 -> V_341 + 1 ;
V_329 -> V_341 = V_346 ;
}
V_351:
V_349 = F_111 ( & V_345 ) ;
F_112 (cqr, n, &format_queue, blocklist) {
V_31 = V_168 -> V_119 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
if ( V_168 -> V_183 == V_308 )
V_34 = - V_274 ;
F_113 ( & V_168 -> V_350 ) ;
F_46 ( V_168 , V_31 ) ;
V_33 -> V_42 -- ;
}
if ( V_349 )
return V_349 ;
if ( V_329 -> V_342 <= V_329 -> V_341 )
goto V_352;
return V_34 ;
}
static void F_114 ( struct V_167 * V_168 )
{
if ( V_168 -> V_181 < 0 ) {
V_168 -> V_183 = V_308 ;
return;
}
V_168 -> V_183 = V_184 ;
if ( V_168 -> V_178 && ( V_168 -> V_119 != V_168 -> V_178 -> V_285 ) ) {
F_115 ( V_168 ) ;
V_168 -> V_119 = V_168 -> V_178 -> V_285 ;
V_168 -> V_170 = V_168 -> V_178 -> V_285 -> V_213 . V_210 ;
}
}
static T_5
F_116 ( struct V_167 * V_168 )
{
struct V_30 * V_31 = (struct V_30 * ) V_168 -> V_119 ;
struct V_1 * V_2 = V_31 -> V_2 ;
switch ( V_2 -> V_353 . V_84 ) {
case 0x3990 :
case 0x2105 :
case 0x2107 :
case 0x1750 :
return V_354 ;
case 0x9343 :
case 0x3880 :
default:
return V_355 ;
}
}
static T_5
F_117 ( struct V_167 * V_168 )
{
return V_356 ;
}
static void F_118 ( struct V_30 * V_31 ,
struct V_167 * V_168 ,
struct V_309 * V_309 )
{
char V_66 ;
char * V_305 = NULL ;
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_66 = V_357 | V_358 | V_359 ;
if ( ( F_119 ( & V_309 -> V_360 ) & V_66 ) == V_66 ) {
if ( ! V_31 -> V_178 && V_33 -> V_361 &&
V_31 -> V_259 == V_260 &&
! F_58 ( V_258 , & V_31 -> V_43 ) &&
! F_58 ( V_231 , & V_31 -> V_43 ) ) {
F_103 ( V_31 ) ;
F_120 ( V_31 ) ;
}
F_121 ( V_31 ) ;
return;
}
V_305 = F_90 ( V_309 ) ;
if ( ! V_305 )
return;
if ( ( V_305 [ 27 ] & V_362 ) && ( V_305 [ 7 ] == 0x0D ) &&
( F_119 ( & V_309 -> V_360 ) & V_363 ) ) {
F_122 ( V_31 , V_309 ) ;
return;
}
if ( ! V_168 && ! ( V_305 [ 27 ] & V_362 ) &&
( ( V_305 [ 6 ] & V_364 ) == V_364 ) ) {
F_123 ( V_31 , V_305 ) ;
return;
}
if ( V_31 -> V_178 && ( V_305 [ 27 ] & V_362 ) &&
( V_305 [ 7 ] == 0x3F ) &&
( F_119 ( & V_309 -> V_360 ) & V_363 ) &&
F_58 ( V_365 , & V_31 -> V_43 ) ) {
if ( V_31 -> V_241 & V_366 )
F_34 ( V_367 , & V_31 -> V_43 ) ;
F_39 ( V_365 , & V_31 -> V_43 ) ;
F_15 ( & V_31 -> V_2 -> V_82 ,
L_74 ) ;
}
}
static struct V_167 * F_124 (
struct V_30 * V_119 ,
struct V_270 * V_178 ,
struct V_368 * V_369 ,
T_6 V_370 ,
T_6 V_371 ,
T_6 V_372 ,
T_6 V_373 ,
unsigned int V_374 ,
unsigned int V_375 ,
unsigned int V_145 ,
unsigned int V_121 )
{
struct V_32 * V_33 ;
unsigned long * V_376 ;
struct V_140 * V_300 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
struct V_377 V_378 ;
struct V_379 V_380 ;
char * V_381 ;
unsigned int V_382 ;
int V_42 , V_383 , V_301 , V_302 ;
T_6 V_146 ;
unsigned char V_48 , V_384 ;
int V_340 ;
struct V_30 * V_118 ;
V_118 = V_178 -> V_285 ;
V_33 = (struct V_32 * ) V_118 -> V_33 ;
if ( F_125 ( V_369 ) == V_385 )
V_48 = V_60 ;
else if ( F_125 ( V_369 ) == V_386 )
V_48 = V_72 ;
else
return F_107 ( - V_128 ) ;
V_42 = 0 ;
V_383 = 0 ;
F_126 (bv, req, iter) {
if ( V_380 . V_387 & ( V_121 - 1 ) )
return F_107 ( - V_128 ) ;
V_42 += V_380 . V_387 >> ( V_178 -> V_318 + 9 ) ;
if ( F_127 ( F_128 ( V_380 . V_388 ) , V_380 . V_387 ) )
V_383 += V_380 . V_387 >> ( V_178 -> V_318 + 9 ) ;
}
if ( V_42 != V_371 - V_370 + 1 )
return F_107 ( - V_128 ) ;
V_340 = V_33 -> V_241 . V_269 [ 8 ] & 0x01 ;
if ( V_340 ) {
V_301 = 2 + V_42 ;
V_302 = sizeof( struct V_93 ) +
sizeof( struct V_140 ) +
V_383 * sizeof( unsigned long ) ;
} else {
V_301 = 2 + V_42 ;
V_302 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
V_383 * sizeof( unsigned long ) ;
}
if ( V_33 -> V_85 && V_370 < 2 * V_145 ) {
if ( V_371 >= 2 * V_145 )
V_42 = 2 * V_145 - V_370 ;
V_301 += V_42 ;
V_302 += V_42 * sizeof( struct V_140 ) ;
}
V_168 = F_43 ( V_176 , V_301 , V_302 ,
V_119 ) ;
if ( F_44 ( V_168 ) )
return V_168 ;
V_45 = V_168 -> V_171 ;
if ( V_340 ) {
if ( F_21 ( V_45 ++ , V_168 -> V_29 , V_372 ,
V_373 , V_48 , V_118 , V_119 ) == - V_233 ) {
F_46 ( V_168 , V_119 ) ;
return F_107 ( - V_233 ) ;
}
V_376 = ( unsigned long * ) ( V_168 -> V_29 +
sizeof( struct V_93 ) ) ;
} else {
if ( F_13 ( V_45 ++ , V_168 -> V_29 , V_372 ,
V_373 , V_48 , V_118 ) == - V_233 ) {
F_46 ( V_168 , V_119 ) ;
return F_107 ( - V_233 ) ;
}
V_376 = ( unsigned long * ) ( V_168 -> V_29 +
sizeof( struct V_28 ) ) ;
}
V_300 = (struct V_140 * ) ( V_376 + V_383 ) ;
V_146 = V_370 ;
if ( V_33 -> V_85 == 0 || V_146 > 2 * V_145 ) {
V_45 [ - 1 ] . V_43 |= V_246 ;
V_126 ( V_45 ++ , V_300 ++ , V_372 , V_374 + 1 ,
V_371 - V_146 + 1 , V_48 , V_118 , V_121 ) ;
}
F_126 (bv, req, iter) {
V_381 = F_128 ( V_380 . V_388 ) + V_380 . V_389 ;
if ( V_390 ) {
char * V_391 = F_129 ( V_390 ,
V_196 | V_392 ) ;
if ( V_391 && F_125 ( V_369 ) == V_386 )
memcpy ( V_391 + V_380 . V_389 , V_381 , V_380 . V_387 ) ;
if ( V_391 )
V_381 = V_391 + V_380 . V_389 ;
}
for ( V_382 = 0 ; V_382 < V_380 . V_387 ; V_382 += V_121 ) {
T_6 V_393 = V_146 ;
unsigned int V_394 = F_130 ( V_393 , V_145 ) ;
V_384 = V_48 ;
V_42 = V_121 ;
if ( V_33 -> V_85 && V_146 < 2 * V_145 ) {
if ( F_22 ( V_145 , V_146 ) ) {
V_384 |= 0x8 ;
V_42 = F_23 ( V_146 ) ;
if ( V_42 < V_121 &&
F_125 ( V_369 ) == V_385 )
memset ( V_381 + V_42 , 0xe5 ,
V_121 - V_42 ) ;
}
V_45 [ - 1 ] . V_43 |= V_246 ;
V_126 ( V_45 ++ , V_300 ++ ,
V_393 , V_394 + 1 ,
1 , V_384 , V_118 , V_42 ) ;
}
if ( V_33 -> V_85 && V_146 == 2 * V_145 ) {
V_45 [ - 1 ] . V_43 |= V_246 ;
V_126 ( V_45 ++ , V_300 ++ ,
V_393 , V_394 + 1 ,
V_371 - V_146 + 1 ,
V_48 , V_118 , V_42 ) ;
}
V_45 [ - 1 ] . V_43 |= V_246 ;
V_45 -> V_54 = V_384 ;
V_45 -> V_42 = V_42 ;
if ( F_127 ( V_381 , V_121 ) ) {
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_376 ;
V_45 -> V_43 = V_395 ;
V_376 = F_131 ( V_376 , V_381 , V_121 ) ;
} else {
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_381 ;
V_45 -> V_43 = 0 ;
}
V_45 ++ ;
V_381 += V_121 ;
V_146 ++ ;
}
}
if ( F_132 ( V_369 ) ||
V_178 -> V_285 -> V_241 & V_396 )
F_34 ( V_257 , & V_168 -> V_43 ) ;
V_168 -> V_119 = V_119 ;
V_168 -> V_177 = V_119 ;
V_168 -> V_178 = V_178 ;
V_168 -> V_179 = V_119 -> V_278 * V_180 ;
V_168 -> V_170 = V_119 -> V_213 . V_218 ;
V_168 -> V_181 = V_119 -> V_280 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
return V_168 ;
}
static struct V_167 * F_133 (
struct V_30 * V_119 ,
struct V_270 * V_178 ,
struct V_368 * V_369 ,
T_6 V_370 ,
T_6 V_371 ,
T_6 V_372 ,
T_6 V_373 ,
unsigned int V_374 ,
unsigned int V_375 ,
unsigned int V_145 ,
unsigned int V_121 )
{
unsigned long * V_376 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
struct V_377 V_378 ;
struct V_379 V_380 ;
char * V_381 , * V_397 ;
unsigned int V_383 , V_301 , V_302 ;
unsigned int V_100 ;
T_6 V_146 ;
unsigned char V_48 ;
struct V_30 * V_118 ;
unsigned int V_398 , V_42 , V_399 ;
unsigned int V_400 , V_401 , V_402 , V_403 ;
unsigned char V_404 , V_405 ;
T_6 V_393 ;
unsigned int V_394 ;
V_118 = V_178 -> V_285 ;
if ( F_125 ( V_369 ) == V_385 )
V_48 = V_113 ;
else if ( F_125 ( V_369 ) == V_386 )
V_48 = V_111 ;
else
return F_107 ( - V_128 ) ;
V_383 = V_371 - V_370 + 1 ;
V_398 = V_373 - V_372 + 1 ;
V_301 = 1 + V_398 ;
V_302 = sizeof( struct V_93 ) +
V_383 * sizeof( unsigned long long ) ;
V_168 = F_43 ( V_176 , V_301 , V_302 ,
V_119 ) ;
if ( F_44 ( V_168 ) )
return V_168 ;
V_45 = V_168 -> V_171 ;
if ( V_372 == V_373 )
V_100 = V_375 - V_374 + 1 ;
else
V_100 = V_375 + 1 ;
V_100 *= V_121 ;
if ( F_20 ( V_45 ++ , V_168 -> V_29 , V_372 ,
V_373 , V_48 , V_118 , V_119 ,
1 , V_374 + 1 ,
V_398 , V_121 ,
V_100 ) == - V_233 ) {
F_46 ( V_168 , V_119 ) ;
return F_107 ( - V_233 ) ;
}
V_376 = ( unsigned long * ) ( V_168 -> V_29 + sizeof( struct V_93 ) ) ;
V_146 = V_370 ;
V_404 = 1 ;
V_405 = 0 ;
V_403 = 0 ;
V_397 = NULL ;
V_400 = 0 ;
F_126 (bv, req, iter) {
V_381 = F_128 ( V_380 . V_388 ) + V_380 . V_389 ;
V_401 = V_380 . V_387 ;
while ( V_401 ) {
if ( V_404 ) {
V_393 = V_146 ;
V_394 = F_130 ( V_393 , V_145 ) ;
V_399 = V_145 - V_394 ;
V_42 = F_134 ( ( V_371 - V_146 + 1 ) ,
( T_6 ) V_399 ) ;
V_403 = V_42 * V_121 ;
V_45 [ - 1 ] . V_43 |= V_246 ;
V_45 -> V_54 = V_48 ;
V_45 -> V_42 = V_403 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_376 ;
V_45 -> V_43 = V_395 ;
V_45 ++ ;
V_146 += V_42 ;
V_404 = 0 ;
if ( ! V_397 )
V_397 = V_381 ;
}
if ( ! V_397 ) {
if ( F_14 ( V_381 ) & ( V_406 - 1 ) ) {
F_46 ( V_168 , V_119 ) ;
return F_107 ( - V_407 ) ;
} else
V_397 = V_381 ;
}
if ( ( V_397 + V_400 ) != V_381 ) {
F_46 ( V_168 , V_119 ) ;
return F_107 ( - V_407 ) ;
}
V_402 = F_134 ( V_401 , V_403 ) ;
V_401 -= V_402 ;
V_381 += V_402 ;
V_400 += V_402 ;
V_403 -= V_402 ;
if ( ! ( F_14 ( V_397 + V_400 ) & ( V_406 - 1 ) ) )
V_405 = 1 ;
if ( ! V_403 ) {
V_404 = 1 ;
V_405 = 1 ;
}
if ( V_405 ) {
V_376 = F_131 ( V_376 , V_397 ,
V_400 ) ;
V_397 = NULL ;
V_400 = 0 ;
V_405 = 0 ;
}
}
}
if ( F_132 ( V_369 ) ||
V_178 -> V_285 -> V_241 & V_396 )
F_34 ( V_257 , & V_168 -> V_43 ) ;
V_168 -> V_119 = V_119 ;
V_168 -> V_177 = V_119 ;
V_168 -> V_178 = V_178 ;
V_168 -> V_179 = V_119 -> V_278 * V_180 ;
V_168 -> V_170 = V_119 -> V_213 . V_218 ;
V_168 -> V_181 = V_119 -> V_280 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
return V_168 ;
}
static int F_135 ( struct V_408 * V_408 ,
unsigned int V_46 , unsigned int V_47 , int V_48 ,
struct V_30 * V_118 ,
struct V_30 * V_119 ,
unsigned int V_98 , int V_42 ,
unsigned int V_121 ,
unsigned int V_409 ,
unsigned int V_100 ,
unsigned int V_145 )
{
struct V_93 V_94 ;
struct V_32 * V_122 , * V_123 ;
struct V_28 * V_124 ;
struct V_97 * V_125 ;
struct V_410 * V_410 ;
T_3 V_49 , V_50 ;
T_4 V_51 , V_52 , V_53 ;
T_7 V_411 ;
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
V_125 -> V_104 . V_412 = 0x01 ;
V_411 = V_413 ;
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
V_125 -> V_104 . V_412 = 0x2 ;
V_411 = V_127 ;
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
V_124 -> V_414 = 0x20 ;
V_124 -> V_415 = V_145 ;
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
V_125 -> V_104 . V_416 = 1 ;
V_125 -> V_104 . V_417 = 1 ;
V_125 -> V_106 = V_100 ;
V_125 -> V_418 = V_48 ;
V_125 -> V_42 = V_42 ;
V_125 -> V_101 = V_101 ;
F_10 ( & V_125 -> V_115 , V_49 , V_52 ) ;
V_125 -> V_116 . V_23 = V_125 -> V_115 . V_23 ;
V_125 -> V_116 . V_24 = V_125 -> V_115 . V_24 ;
V_125 -> V_116 . V_117 = V_98 ;
V_410 = F_136 ( V_408 , V_411 , 0 ,
& V_94 , sizeof( V_94 ) , V_409 ) ;
return F_137 ( V_410 ) ;
}
static struct V_167 * F_138 (
struct V_30 * V_119 ,
struct V_270 * V_178 ,
struct V_368 * V_369 ,
T_6 V_370 ,
T_6 V_371 ,
T_6 V_372 ,
T_6 V_373 ,
unsigned int V_374 ,
unsigned int V_375 ,
unsigned int V_145 ,
unsigned int V_121 )
{
struct V_167 * V_168 ;
struct V_377 V_378 ;
struct V_379 V_380 ;
char * V_381 ;
unsigned int V_398 , V_419 ;
unsigned char V_48 ;
struct V_30 * V_118 ;
unsigned int V_100 ;
struct V_408 * V_408 ;
struct V_420 * V_421 = NULL ;
int V_422 ;
T_8 V_423 ;
T_7 V_424 ;
unsigned int V_401 , V_402 , V_403 ;
unsigned char V_404 ;
T_6 V_146 , V_393 ;
unsigned int V_425 ;
unsigned int V_42 , V_399 ;
int V_3 ;
V_118 = V_178 -> V_285 ;
if ( F_125 ( V_369 ) == V_385 ) {
V_48 = V_113 ;
V_422 = V_426 ;
} else if ( F_125 ( V_369 ) == V_386 ) {
V_48 = V_111 ;
V_422 = V_427 ;
} else
return F_107 ( - V_128 ) ;
V_398 = V_373 - V_372 + 1 ;
V_419 = 0 ;
F_126 (bv, req, iter) {
++ V_419 ;
}
if ( F_125 ( V_369 ) == V_386 )
V_419 += ( V_373 - V_372 ) ;
V_423 = F_139 ( 0 , V_419 , 0 ) ;
V_168 = F_43 ( V_176 , 0 , V_423 , V_119 ) ;
if ( F_44 ( V_168 ) )
return V_168 ;
if ( V_372 == V_373 )
V_100 = V_375 - V_374 + 1 ;
else
V_100 = V_375 + 1 ;
V_100 *= V_121 ;
V_408 = F_140 ( V_168 -> V_29 , V_423 , V_422 , 0 , V_419 , 0 ) ;
if ( F_44 ( V_408 ) ) {
V_3 = - V_128 ;
goto V_194;
}
V_168 -> V_171 = F_141 ( V_408 ) ;
if ( F_135 ( V_408 , V_372 , V_373 ,
V_48 , V_118 , V_119 ,
V_374 + 1 ,
V_398 , V_121 ,
( V_371 - V_370 + 1 ) * V_121 ,
V_100 , V_145 ) == - V_233 ) {
V_3 = - V_233 ;
goto V_194;
}
V_403 = 0 ;
if ( F_125 ( V_369 ) == V_386 ) {
V_404 = 1 ;
V_146 = V_370 ;
F_126 (bv, req, iter) {
V_381 = F_128 ( V_380 . V_388 ) + V_380 . V_389 ;
V_401 = V_380 . V_387 ;
while ( V_401 ) {
if ( V_404 ) {
V_393 = V_146 ;
V_425 = F_130 ( V_393 , V_145 ) ;
V_399 = V_145 - V_425 ;
V_42 = F_134 ( ( V_371 - V_146 + 1 ) ,
( T_6 ) V_399 ) ;
V_403 = V_42 * V_121 ;
V_146 += V_42 ;
V_404 = 0 ;
}
V_402 = F_134 ( V_401 , V_403 ) ;
V_401 -= V_402 ;
V_403 -= V_402 ;
if ( ! V_403 ) {
V_404 = 1 ;
V_424 = V_428 ;
} else
V_424 = 0 ;
V_421 = F_142 ( V_408 , V_424 ,
V_381 , V_402 ) ;
if ( F_44 ( V_421 ) ) {
V_3 = - V_128 ;
goto V_194;
}
V_381 += V_402 ;
}
}
} else {
F_126 (bv, req, iter) {
V_381 = F_128 ( V_380 . V_388 ) + V_380 . V_389 ;
V_421 = F_142 ( V_408 , 0x00 ,
V_381 , V_380 . V_387 ) ;
if ( F_44 ( V_421 ) ) {
V_3 = - V_128 ;
goto V_194;
}
}
}
V_421 -> V_43 |= V_429 ;
V_421 -> V_43 &= ~ V_428 ;
F_143 ( V_408 ) ;
if ( F_132 ( V_369 ) ||
V_178 -> V_285 -> V_241 & V_396 )
F_34 ( V_257 , & V_168 -> V_43 ) ;
V_168 -> V_430 = 1 ;
V_168 -> V_119 = V_119 ;
V_168 -> V_177 = V_119 ;
V_168 -> V_178 = V_178 ;
V_168 -> V_179 = V_119 -> V_278 * V_180 ;
V_168 -> V_170 = V_119 -> V_213 . V_218 ;
V_168 -> V_181 = V_119 -> V_280 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
return V_168 ;
V_194:
F_46 ( V_168 , V_119 ) ;
return F_107 ( V_3 ) ;
}
static struct V_167 * F_144 ( struct V_30 * V_119 ,
struct V_270 * V_178 ,
struct V_368 * V_369 )
{
int V_431 , V_432 ;
int V_340 ;
int V_433 ;
struct V_32 * V_33 ;
struct V_30 * V_118 ;
T_6 V_370 , V_371 ;
T_6 V_372 , V_373 ;
unsigned int V_374 , V_375 ;
unsigned int V_145 , V_121 ;
int V_434 ;
unsigned int V_435 ;
struct V_167 * V_168 ;
V_118 = V_178 -> V_285 ;
V_33 = (struct V_32 * ) V_118 -> V_33 ;
V_121 = V_178 -> V_315 ;
V_145 = F_9 ( & V_33 -> V_35 , 0 , V_121 ) ;
if ( V_145 == 0 )
return F_107 ( - V_128 ) ;
V_370 = V_372 = F_145 ( V_369 ) >> V_178 -> V_318 ;
V_374 = F_130 ( V_372 , V_145 ) ;
V_371 = V_373 =
( F_145 ( V_369 ) + F_146 ( V_369 ) - 1 ) >> V_178 -> V_318 ;
V_375 = F_130 ( V_373 , V_145 ) ;
V_434 = ( V_33 -> V_85 && V_370 < 2 * V_145 ) ;
V_433 = V_33 -> V_241 . V_269 [ 40 ] & 0x20 ;
V_435 = F_147 ( V_369 ) ;
if ( V_435 % V_121 )
return F_107 ( - V_128 ) ;
if ( F_125 ( V_369 ) == V_386 )
V_435 += ( V_373 - V_372 ) * 4 ;
V_431 = V_33 -> V_241 . V_269 [ 9 ] & 0x20 ;
V_432 = V_33 -> V_241 . V_269 [ 12 ] & 0x40 ;
V_340 = V_33 -> V_241 . V_269 [ 8 ] & 0x01 ;
V_168 = NULL ;
if ( V_434 || V_390 ) {
} else if ( ( V_435 <= V_33 -> V_222 )
&& ( V_433 || ( V_372 == V_373 ) ) ) {
V_168 = F_138 ( V_119 , V_178 , V_369 ,
V_370 , V_371 ,
V_372 , V_373 ,
V_374 , V_375 ,
V_145 , V_121 ) ;
if ( F_44 ( V_168 ) && ( F_69 ( V_168 ) != - V_233 ) &&
( F_69 ( V_168 ) != - V_197 ) )
V_168 = NULL ;
} else if ( V_340 &&
( ( ( F_125 ( V_369 ) == V_385 ) && V_431 ) ||
( ( F_125 ( V_369 ) == V_386 ) && V_432 ) ) ) {
V_168 = F_133 ( V_119 , V_178 , V_369 ,
V_370 , V_371 ,
V_372 , V_373 ,
V_374 , V_375 ,
V_145 , V_121 ) ;
if ( F_44 ( V_168 ) && ( F_69 ( V_168 ) != - V_233 ) &&
( F_69 ( V_168 ) != - V_197 ) )
V_168 = NULL ;
}
if ( ! V_168 )
V_168 = F_124 ( V_119 , V_178 , V_369 ,
V_370 , V_371 ,
V_372 , V_373 ,
V_374 , V_375 ,
V_145 , V_121 ) ;
return V_168 ;
}
static struct V_167 * F_148 ( struct V_30 * V_119 ,
struct V_270 * V_178 ,
struct V_368 * V_369 )
{
unsigned long * V_376 ;
struct V_30 * V_118 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
struct V_377 V_378 ;
struct V_379 V_380 ;
char * V_381 ;
unsigned char V_48 ;
unsigned int V_398 ;
unsigned int V_401 , V_403 ;
unsigned int V_374 ;
unsigned int V_383 , V_301 , V_302 ;
T_6 V_372 , V_373 , V_326 ;
T_6 V_436 , V_437 , V_438 ;
unsigned int V_439 ;
V_436 = F_145 ( V_369 ) % V_440 ;
V_437 = ( F_145 ( V_369 ) + F_146 ( V_369 ) ) %
V_440 ;
V_438 = ( V_440 - V_437 ) %
V_440 ;
V_118 = V_178 -> V_285 ;
if ( ( V_436 || V_438 ) &&
( F_125 ( V_369 ) == V_386 ) ) {
F_18 ( V_114 , V_118 ,
L_76 ,
V_436 , V_438 , V_369 ) ;
V_168 = F_107 ( - V_128 ) ;
goto V_441;
}
V_372 = F_145 ( V_369 ) / V_440 ;
V_373 = ( F_145 ( V_369 ) + F_146 ( V_369 ) - 1 ) /
V_440 ;
V_398 = V_373 - V_372 + 1 ;
V_374 = 0 ;
if ( F_125 ( V_369 ) == V_385 )
V_48 = V_112 ;
else if ( F_125 ( V_369 ) == V_386 )
V_48 = V_107 ;
else {
V_168 = F_107 ( - V_128 ) ;
goto V_441;
}
V_383 = V_398 * V_317 ;
V_301 = 1 + V_398 ;
V_439 = sizeof( struct V_93 ) + 8 ;
V_302 = V_439 + V_383 * sizeof( unsigned long long ) ;
V_168 = F_43 ( V_176 , V_301 ,
V_302 , V_119 ) ;
if ( F_44 ( V_168 ) )
goto V_441;
V_45 = V_168 -> V_171 ;
if ( F_20 ( V_45 ++ , V_168 -> V_29 , V_372 , V_373 , V_48 ,
V_118 , V_119 , 1 , V_374 + 1 ,
V_398 , 0 , 0 ) == - V_233 ) {
F_46 ( V_168 , V_119 ) ;
V_168 = F_107 ( - V_233 ) ;
goto V_441;
}
V_376 = ( unsigned long * ) ( V_168 -> V_29 + V_439 ) ;
V_403 = 0 ;
if ( V_436 ) {
V_45 [ - 1 ] . V_43 |= V_246 ;
V_45 -> V_54 = V_48 ;
V_45 -> V_42 = 57326 ;
V_403 = 65536 - V_436 * 512 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_376 ;
V_45 -> V_43 |= V_395 ;
V_45 -> V_43 |= V_44 ;
V_45 ++ ;
for ( V_326 = 0 ; V_326 < V_436 ; V_326 += 8 )
V_376 = F_131 ( V_376 , V_442 , V_443 ) ;
}
F_126 (bv, req, iter) {
V_381 = F_128 ( V_380 . V_388 ) + V_380 . V_389 ;
V_401 = V_380 . V_387 ;
if ( V_48 == V_112 )
memset ( V_381 , 0 , V_401 ) ;
if ( ! V_403 ) {
V_45 [ - 1 ] . V_43 |= V_246 ;
V_45 -> V_54 = V_48 ;
V_45 -> V_42 = 57326 ;
V_403 = 65536 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_376 ;
V_45 -> V_43 |= V_395 ;
V_45 -> V_43 |= V_44 ;
V_45 ++ ;
}
V_403 -= V_401 ;
V_376 = F_131 ( V_376 , V_381 , V_401 ) ;
}
for ( V_326 = 0 ; V_326 < V_438 ; V_326 += 8 )
V_376 = F_131 ( V_376 , V_442 , V_443 ) ;
if ( F_132 ( V_369 ) ||
V_178 -> V_285 -> V_241 & V_396 )
F_34 ( V_257 , & V_168 -> V_43 ) ;
V_168 -> V_119 = V_119 ;
V_168 -> V_177 = V_119 ;
V_168 -> V_178 = V_178 ;
V_168 -> V_179 = V_119 -> V_278 * V_180 ;
V_168 -> V_170 = V_119 -> V_213 . V_218 ;
V_168 -> V_181 = V_119 -> V_280 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
if ( F_44 ( V_168 ) && F_69 ( V_168 ) != - V_233 )
V_168 = NULL ;
V_441:
return V_168 ;
}
static int
F_149 ( struct V_167 * V_168 , struct V_368 * V_369 )
{
struct V_32 * V_33 ;
struct V_26 * V_45 ;
struct V_377 V_378 ;
struct V_379 V_380 ;
char * V_381 , * V_56 ;
unsigned int V_121 , V_145 , V_382 ;
T_6 V_146 ;
int V_183 ;
if ( ! V_390 )
goto V_441;
V_33 = (struct V_32 * ) V_168 -> V_178 -> V_285 -> V_33 ;
V_121 = V_168 -> V_178 -> V_315 ;
V_145 = F_9 ( & V_33 -> V_35 , 0 , V_121 ) ;
V_146 = F_145 ( V_369 ) >> V_168 -> V_178 -> V_318 ;
V_45 = V_168 -> V_171 ;
V_45 ++ ;
if ( V_33 -> V_85 == 0 || V_146 > 2 * V_145 )
V_45 ++ ;
F_126 (bv, req, iter) {
V_381 = F_128 ( V_380 . V_388 ) + V_380 . V_389 ;
for ( V_382 = 0 ; V_382 < V_380 . V_387 ; V_382 += V_121 ) {
if ( V_33 -> V_85 && V_146 <= 2 * V_145 )
V_45 ++ ;
if ( V_381 ) {
if ( V_45 -> V_43 & V_395 )
V_56 = * ( ( char * * ) ( ( V_173 ) V_45 -> V_56 ) ) ;
else
V_56 = ( char * ) ( ( V_173 ) V_45 -> V_56 ) ;
if ( V_381 != V_56 ) {
if ( F_125 ( V_369 ) == V_385 )
memcpy ( V_381 , V_56 , V_380 . V_387 ) ;
F_150 ( V_390 ,
( void * ) ( ( V_173 ) V_56 & V_444 ) ) ;
}
V_381 = NULL ;
}
V_45 ++ ;
V_146 ++ ;
}
}
V_441:
V_183 = V_168 -> V_183 == V_186 ;
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_183 ;
}
void F_115 ( struct V_167 * V_168 )
{
struct V_26 * V_45 ;
struct V_93 * V_94 ;
struct V_445 * V_445 ;
struct V_446 * V_446 ;
struct V_410 * V_410 ;
if ( V_168 -> V_430 == 1 ) {
V_445 = V_168 -> V_171 ;
V_446 = F_151 ( V_445 ) ;
V_410 = (struct V_410 * ) & V_446 -> V_447 [ 0 ] ;
V_94 = (struct V_93 * ) & V_410 -> V_448 [ 0 ] ;
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
static struct V_167 * F_152 ( struct V_30 * V_285 ,
struct V_270 * V_178 ,
struct V_368 * V_369 )
{
struct V_32 * V_33 ;
struct V_30 * V_119 ;
unsigned long V_43 ;
struct V_167 * V_168 ;
V_119 = F_106 ( V_285 ) ;
if ( ! V_119 )
V_119 = V_285 ;
V_33 = (struct V_32 * ) V_119 -> V_33 ;
if ( V_33 -> V_42 >= V_449 )
return F_107 ( - V_450 ) ;
F_27 ( F_28 ( V_119 -> V_2 ) , V_43 ) ;
V_33 -> V_42 ++ ;
if ( ( V_285 -> V_241 & V_288 ) )
V_168 = F_148 ( V_119 , V_178 , V_369 ) ;
else
V_168 = F_144 ( V_119 , V_178 , V_369 ) ;
if ( F_44 ( V_168 ) )
V_33 -> V_42 -- ;
F_29 ( F_28 ( V_119 -> V_2 ) , V_43 ) ;
return V_168 ;
}
static int F_153 ( struct V_167 * V_168 ,
struct V_368 * V_369 )
{
struct V_32 * V_33 ;
unsigned long V_43 ;
F_27 ( F_28 ( V_168 -> V_177 -> V_2 ) , V_43 ) ;
V_33 = (struct V_32 * ) V_168 -> V_177 -> V_33 ;
V_33 -> V_42 -- ;
F_29 ( F_28 ( V_168 -> V_177 -> V_2 ) , V_43 ) ;
return F_149 ( V_168 , V_369 ) ;
}
static int
F_154 ( struct V_30 * V_31 ,
struct V_451 * V_452 )
{
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_452 -> V_453 = 2 ;
V_452 -> V_454 = V_33 -> V_85 ? 0 : 1 ;
V_452 -> V_120 = V_33 -> V_85 ? V_455 : V_456 ;
V_452 -> V_457 = sizeof( struct V_14 ) ;
memcpy ( V_452 -> V_458 , & V_33 -> V_35 ,
sizeof( struct V_14 ) ) ;
V_452 -> V_459 = F_134 ( ( unsigned long ) V_33 -> V_200 ,
sizeof( V_452 -> V_460 ) ) ;
memcpy ( V_452 -> V_460 , V_33 -> V_201 ,
V_452 -> V_459 ) ;
return 0 ;
}
static int
F_155 ( struct V_30 * V_31 )
{
struct V_167 * V_168 ;
int V_34 ;
struct V_26 * V_45 ;
int V_461 ;
if ( ! F_156 ( V_462 ) )
return - V_41 ;
V_461 = 0 ;
V_168 = F_43 ( V_176 , 1 , 32 , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_157 ( & V_463 ) ;
V_461 = 1 ;
V_168 = & V_464 -> V_168 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
memset ( & V_464 -> V_45 , 0 ,
sizeof( V_464 -> V_45 ) ) ;
V_168 -> V_171 = & V_464 -> V_45 ;
V_168 -> V_29 = & V_464 -> V_29 ;
V_168 -> V_175 = V_176 ;
}
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_465 ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_42 = 32 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_168 -> V_29 ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
F_39 ( V_189 , & V_168 -> V_43 ) ;
F_34 ( V_257 , & V_168 -> V_43 ) ;
V_168 -> V_181 = 2 ;
V_168 -> V_179 = 2 * V_180 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_40 ( V_168 ) ;
if ( ! V_34 )
F_39 ( V_365 , & V_31 -> V_43 ) ;
if ( V_461 )
F_62 ( & V_463 ) ;
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
int V_461 ;
if ( ! F_156 ( V_462 ) )
return - V_41 ;
V_461 = 0 ;
V_168 = F_43 ( V_176 , 1 , 32 , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_157 ( & V_463 ) ;
V_461 = 1 ;
V_168 = & V_464 -> V_168 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
memset ( & V_464 -> V_45 , 0 ,
sizeof( V_464 -> V_45 ) ) ;
V_168 -> V_171 = & V_464 -> V_45 ;
V_168 -> V_29 = & V_464 -> V_29 ;
V_168 -> V_175 = V_176 ;
}
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_466 ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_42 = 32 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_168 -> V_29 ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
F_39 ( V_189 , & V_168 -> V_43 ) ;
F_34 ( V_257 , & V_168 -> V_43 ) ;
V_168 -> V_181 = 2 ;
V_168 -> V_179 = 2 * V_180 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_40 ( V_168 ) ;
if ( ! V_34 )
F_34 ( V_365 , & V_31 -> V_43 ) ;
if ( V_461 )
F_62 ( & V_463 ) ;
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
int V_461 ;
if ( ! F_156 ( V_462 ) )
return - V_41 ;
V_461 = 0 ;
V_168 = F_43 ( V_176 , 1 , 32 , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_157 ( & V_463 ) ;
V_461 = 1 ;
V_168 = & V_464 -> V_168 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
memset ( & V_464 -> V_45 , 0 ,
sizeof( V_464 -> V_45 ) ) ;
V_168 -> V_171 = & V_464 -> V_45 ;
V_168 -> V_29 = & V_464 -> V_29 ;
V_168 -> V_175 = V_176 ;
}
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_467 ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_42 = 32 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_168 -> V_29 ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
F_39 ( V_189 , & V_168 -> V_43 ) ;
F_34 ( V_257 , & V_168 -> V_43 ) ;
V_168 -> V_181 = 2 ;
V_168 -> V_179 = 2 * V_180 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_40 ( V_168 ) ;
if ( ! V_34 )
F_34 ( V_365 , & V_31 -> V_43 ) ;
if ( V_461 )
F_62 ( & V_463 ) ;
else
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int F_160 ( struct V_30 * V_31 ,
void T_9 * V_468 )
{
struct V_167 * V_168 ;
int V_34 ;
struct V_26 * V_45 ;
int V_461 ;
struct V_469 V_470 ;
if ( ! F_156 ( V_462 ) )
return - V_41 ;
if ( F_161 ( & V_470 , V_468 , sizeof( V_470 ) ) )
return - V_471 ;
V_461 = 0 ;
V_168 = F_43 ( V_176 , 1 ,
sizeof( struct V_472 ) , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_157 ( & V_463 ) ;
V_461 = 1 ;
V_168 = & V_464 -> V_168 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
memset ( & V_464 -> V_45 , 0 ,
sizeof( V_464 -> V_45 ) ) ;
V_168 -> V_171 = & V_464 -> V_45 ;
V_168 -> V_29 = & V_464 -> V_29 ;
V_168 -> V_175 = V_176 ;
}
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_473 ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_42 = 12 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_168 -> V_29 ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
F_39 ( V_189 , & V_168 -> V_43 ) ;
F_34 ( V_257 , & V_168 -> V_43 ) ;
F_34 ( V_190 , & V_168 -> V_43 ) ;
V_168 -> V_181 = 5 ;
V_168 -> V_179 = 10 * V_180 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_168 -> V_170 = V_470 . V_474 ;
V_34 = F_40 ( V_168 ) ;
if ( ! V_34 && V_470 . V_474 && ( V_168 -> V_170 != V_470 . V_474 ) )
V_34 = - V_274 ;
if ( ! V_34 ) {
V_470 . V_29 = * ( (struct V_472 * ) V_168 -> V_29 ) ;
if ( F_162 ( V_468 , & V_470 , sizeof( V_470 ) ) )
V_34 = - V_471 ;
}
if ( V_461 )
F_62 ( & V_463 ) ;
else
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int
F_163 ( struct V_30 * V_31 , void T_9 * V_468 )
{
struct V_238 * V_239 ;
struct V_475 * V_476 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
int V_34 ;
V_168 = F_43 ( V_176 , 1 + 1 ,
( sizeof( struct V_238 ) +
sizeof( struct V_475 ) ) ,
V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_18 ( V_7 , V_31 , L_1 ,
L_77 ) ;
return F_69 ( V_168 ) ;
}
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_181 = 0 ;
F_39 ( V_189 , & V_168 -> V_43 ) ;
V_168 -> V_179 = 10 * V_180 ;
V_239 = (struct V_238 * ) V_168 -> V_29 ;
memset ( V_239 , 0 , sizeof( struct V_238 ) ) ;
V_239 -> V_242 = V_243 ;
V_239 -> V_244 = 0x01 ;
V_239 -> V_477 [ 1 ] = 0x01 ;
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_245 ;
V_45 -> V_42 = sizeof( struct V_238 ) ;
V_45 -> V_43 |= V_246 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_239 ;
V_476 = (struct V_475 * ) ( V_239 + 1 ) ;
memset ( V_476 , 0 , sizeof( struct V_475 ) ) ;
V_45 ++ ;
V_45 -> V_54 = V_247 ;
V_45 -> V_42 = sizeof( struct V_475 ) ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_476 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_45 ( V_168 ) ;
if ( V_34 == 0 ) {
V_239 = (struct V_238 * ) V_168 -> V_29 ;
V_476 = (struct V_475 * ) ( V_239 + 1 ) ;
if ( F_162 ( V_468 , V_476 ,
sizeof( struct V_475 ) ) )
V_34 = - V_471 ;
}
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int
F_164 ( struct V_30 * V_31 , void T_9 * V_468 )
{
struct V_32 * V_33 =
(struct V_32 * ) V_31 -> V_33 ;
struct V_478 V_70 = V_33 -> V_70 ;
int V_34 ;
if ( ! F_156 ( V_462 ) )
return - V_41 ;
if ( ! V_468 )
return - V_128 ;
V_34 = 0 ;
if ( F_162 ( V_468 , ( long * ) & V_70 ,
sizeof( struct V_478 ) ) )
V_34 = - V_471 ;
return V_34 ;
}
static int
F_165 ( struct V_30 * V_31 , void T_9 * V_468 )
{
struct V_32 * V_33 =
(struct V_32 * ) V_31 -> V_33 ;
struct V_478 V_70 ;
if ( ! F_156 ( V_462 ) )
return - V_41 ;
if ( ! V_468 )
return - V_128 ;
if ( F_161 ( & V_70 , V_468 , sizeof( struct V_478 ) ) )
return - V_471 ;
V_33 -> V_70 = V_70 ;
F_80 ( & V_31 -> V_2 -> V_82 ,
L_78 ,
V_33 -> V_70 . V_69 , V_33 -> V_70 . V_89 ) ;
return 0 ;
}
static int F_166 ( struct V_30 * V_31 , void T_9 * V_468 )
{
struct V_479 V_470 ;
char * V_480 , * V_481 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
char V_482 , V_483 ;
int V_34 ;
if ( ! F_156 ( V_462 ) && ! F_156 ( V_484 ) )
return - V_41 ;
V_482 = V_483 = 0 ;
V_34 = - V_471 ;
if ( F_161 ( & V_470 , V_468 , sizeof( V_470 ) ) )
goto V_441;
if ( F_167 () || sizeof( long ) == 4 ) {
V_34 = - V_128 ;
if ( ( V_470 . V_480 >> 32 ) != 0 )
goto V_441;
if ( ( V_470 . V_481 >> 32 ) != 0 )
goto V_441;
V_470 . V_480 &= 0x7fffffffULL ;
V_470 . V_481 &= 0x7fffffffULL ;
}
V_480 = F_42 ( V_470 . V_485 , V_195 | V_196 ) ;
V_481 = F_42 ( V_470 . V_486 , V_195 | V_196 ) ;
if ( ! V_480 || ! V_481 ) {
V_34 = - V_197 ;
goto V_487;
}
V_34 = - V_471 ;
if ( F_161 ( V_480 ,
( void T_9 * ) ( unsigned long ) V_470 . V_480 ,
V_470 . V_485 ) )
goto V_487;
V_482 = V_480 [ 0 ] ;
V_483 = V_480 [ 1 ] ;
V_168 = F_43 ( V_176 , 2 , 0 , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_18 ( V_7 , V_31 , L_1 ,
L_77 ) ;
V_34 = F_69 ( V_168 ) ;
goto V_487;
}
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_181 = 3 ;
V_168 -> V_179 = 10 * V_180 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_245 ;
V_45 -> V_42 = V_470 . V_485 ;
V_45 -> V_43 |= V_246 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_480 ;
V_45 ++ ;
V_45 -> V_54 = V_247 ;
V_45 -> V_42 = V_470 . V_486 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_481 ;
V_34 = F_45 ( V_168 ) ;
if ( V_34 )
goto V_488;
V_34 = - V_471 ;
if ( F_162 ( ( void T_9 * ) ( unsigned long ) V_470 . V_481 ,
V_481 , V_470 . V_486 ) )
goto V_488;
V_34 = 0 ;
V_488:
F_46 ( V_168 , V_168 -> V_177 ) ;
V_487:
F_47 ( V_481 ) ;
F_47 ( V_480 ) ;
V_441:
F_18 ( V_7 , V_31 ,
L_79 ,
( int ) V_482 , ( int ) V_483 , V_34 ) ;
return V_34 ;
}
static int
F_168 ( struct V_270 * V_178 , unsigned int V_48 , void T_9 * V_468 )
{
struct V_30 * V_31 = V_178 -> V_285 ;
switch ( V_48 ) {
case V_489 :
return F_164 ( V_31 , V_468 ) ;
case V_490 :
return F_165 ( V_31 , V_468 ) ;
case V_491 :
return F_163 ( V_31 , V_468 ) ;
case V_492 :
return F_155 ( V_31 ) ;
case V_493 :
return F_158 ( V_31 ) ;
case V_494 :
return F_159 ( V_31 ) ;
case V_495 :
return F_160 ( V_31 , V_468 ) ;
case V_496 :
return F_166 ( V_31 , V_468 ) ;
default:
return - V_497 ;
}
}
static int
F_169 ( struct V_26 * V_498 , struct V_26 * V_499 , char * V_500 )
{
int V_501 , V_42 ;
char * V_502 ;
V_501 = 0 ;
while ( V_498 <= V_499 ) {
V_501 += sprintf ( V_500 + V_501 , V_503
L_80 ,
V_498 , ( ( int * ) V_498 ) [ 0 ] , ( ( int * ) V_498 ) [ 1 ] ) ;
if ( V_498 -> V_43 & V_395 )
V_502 = ( char * ) * ( ( V_173 * ) ( V_173 ) V_498 -> V_56 ) ;
else
V_502 = ( char * ) ( ( V_173 ) V_498 -> V_56 ) ;
for ( V_42 = 0 ; V_42 < V_498 -> V_42 && V_42 < 32 ; V_42 ++ ) {
if ( V_42 % 8 == 0 ) V_501 += sprintf ( V_500 + V_501 , L_81 ) ;
if ( V_42 % 4 == 0 ) V_501 += sprintf ( V_500 + V_501 , L_81 ) ;
V_501 += sprintf ( V_500 + V_501 , L_11 , V_502 [ V_42 ] ) ;
}
V_501 += sprintf ( V_500 + V_501 , L_82 ) ;
V_498 ++ ;
}
return V_501 ;
}
static void
F_170 ( struct V_30 * V_31 , struct V_309 * V_309 ,
char * V_504 )
{
T_10 * V_305 ;
T_10 * V_505 ;
V_305 = ( T_10 * ) F_90 ( V_309 ) ;
V_505 = ( T_10 * ) & V_309 -> V_360 ;
if ( V_305 ) {
F_18 ( V_506 , V_31 , L_83
L_84 ,
V_504 , * V_505 , * ( ( T_3 * ) ( V_505 + 1 ) ) ,
V_305 [ 0 ] , V_305 [ 1 ] , V_305 [ 2 ] , V_305 [ 3 ] ) ;
} else {
F_18 ( V_506 , V_31 , L_85 ,
V_504 , * V_505 , * ( ( T_3 * ) ( V_505 + 1 ) ) ,
L_86 ) ;
}
}
static void F_171 ( struct V_30 * V_31 ,
struct V_167 * V_369 , struct V_309 * V_309 )
{
char * V_500 ;
struct V_26 * V_507 , * V_508 , * V_509 , * V_498 , * V_499 ;
int V_501 , V_510 , V_511 ;
V_500 = ( char * ) F_172 ( V_236 ) ;
if ( V_500 == NULL ) {
F_18 ( V_7 , V_31 , L_1 ,
L_87 ) ;
return;
}
V_501 = sprintf ( V_500 , V_503
L_88 ,
F_173 ( & V_31 -> V_2 -> V_82 ) ) ;
V_501 += sprintf ( V_500 + V_501 , V_503
L_89
L_90 ,
V_369 , F_174 ( & V_309 -> V_360 ) , F_175 ( & V_309 -> V_360 ) ,
F_176 ( & V_309 -> V_360 ) , F_177 ( & V_309 -> V_360 ) ,
F_119 ( & V_309 -> V_360 ) , F_178 ( & V_309 -> V_360 ) ,
V_369 ? V_369 -> V_253 : 0 ) ;
V_501 += sprintf ( V_500 + V_501 , V_503
L_91 ,
F_173 ( & V_31 -> V_2 -> V_82 ) ,
( void * ) ( V_173 ) V_309 -> V_360 . V_48 . V_512 ) ;
if ( V_309 -> V_513 . V_514 . V_515 . V_516 ) {
for ( V_510 = 0 ; V_510 < 4 ; V_510 ++ ) {
V_501 += sprintf ( V_500 + V_501 , V_503
L_92 ,
( 8 * V_510 ) , ( ( 8 * V_510 ) + 7 ) ) ;
for ( V_511 = 0 ; V_511 < 8 ; V_511 ++ ) {
V_501 += sprintf ( V_500 + V_501 , L_93 ,
V_309 -> V_517 [ 8 * V_510 + V_511 ] ) ;
}
V_501 += sprintf ( V_500 + V_501 , L_82 ) ;
}
if ( V_309 -> V_517 [ 27 ] & V_362 ) {
sprintf ( V_500 + V_501 , V_503
L_94
L_95 ,
V_309 -> V_517 [ 7 ] >> 4 , V_309 -> V_517 [ 7 ] & 0x0f ,
V_309 -> V_517 [ 1 ] & 0x10 ? L_59 : L_96 ) ;
} else {
sprintf ( V_500 + V_501 , V_503
L_97
L_98 ,
V_309 -> V_517 [ 6 ] & 0x0f , V_309 -> V_517 [ 22 ] >> 4 ) ;
}
} else {
sprintf ( V_500 + V_501 , V_503
L_99 ) ;
}
F_179 ( V_518 L_1 , V_500 ) ;
if ( V_369 ) {
V_507 = V_369 -> V_171 ;
for ( V_508 = V_507 ; V_508 -> V_43 & ( V_246 | V_519 ) ; V_508 ++ ) ;
V_499 = F_134 ( V_507 + 6 , V_508 ) ;
V_501 = sprintf ( V_500 , V_503
L_100 , V_369 ) ;
F_169 ( V_507 , V_499 , V_500 + V_501 ) ;
F_179 ( V_518 L_1 , V_500 ) ;
V_501 = 0 ;
V_498 = ++ V_499 ;
V_509 = (struct V_26 * ) ( V_173 )
V_309 -> V_360 . V_48 . V_512 ;
if ( V_498 < V_509 - 2 ) {
V_498 = V_509 - 2 ;
V_501 += sprintf ( V_500 , V_503 L_101 ) ;
}
V_499 = F_134 ( V_509 + 1 , V_508 ) ;
V_501 += F_169 ( V_498 , V_499 , V_500 + V_501 ) ;
V_498 = F_180 ( V_498 , ++ V_499 ) ;
if ( V_498 < V_508 - 1 ) {
V_498 = V_508 - 1 ;
V_501 += sprintf ( V_500 + V_501 , V_503 L_101 ) ;
}
V_501 += F_169 ( V_498 , V_508 , V_500 + V_501 ) ;
if ( V_501 > 0 )
F_179 ( V_518 L_1 , V_500 ) ;
}
F_181 ( ( unsigned long ) V_500 ) ;
}
static void F_182 ( struct V_30 * V_31 ,
struct V_167 * V_369 , struct V_309 * V_309 )
{
char * V_500 ;
int V_501 , V_510 , V_511 , V_520 ;
struct V_521 * V_521 ;
T_7 * V_305 , * V_522 ;
V_500 = ( char * ) F_172 ( V_236 ) ;
if ( V_500 == NULL ) {
F_18 ( V_7 , V_31 , L_102 ,
L_103 ) ;
return;
}
V_501 = sprintf ( V_500 , V_503
L_88 ,
F_173 ( & V_31 -> V_2 -> V_82 ) ) ;
V_501 += sprintf ( V_500 + V_501 , V_503
L_89
L_104 ,
V_369 , F_174 ( & V_309 -> V_360 ) , F_175 ( & V_309 -> V_360 ) ,
F_176 ( & V_309 -> V_360 ) , F_177 ( & V_309 -> V_360 ) ,
F_119 ( & V_309 -> V_360 ) , F_178 ( & V_309 -> V_360 ) ,
V_309 -> V_360 . V_523 . V_524 , V_309 -> V_360 . V_523 . V_525 ,
V_369 ? V_369 -> V_253 : 0 ) ;
V_501 += sprintf ( V_500 + V_501 , V_503
L_105 ,
F_173 ( & V_31 -> V_2 -> V_82 ) ,
( void * ) ( V_173 ) V_309 -> V_360 . V_523 . V_445 ) ;
V_521 = NULL ;
V_305 = NULL ;
if ( V_309 -> V_360 . V_523 . V_445 && ( V_309 -> V_360 . V_523 . V_524 & 0x01 ) )
V_521 = F_183 (
(struct V_445 * ) ( unsigned long ) V_309 -> V_360 . V_523 . V_445 ) ;
if ( V_521 ) {
V_501 += sprintf ( V_500 + V_501 , V_503
L_106 , V_521 -> V_106 ) ;
V_501 += sprintf ( V_500 + V_501 , V_503
L_107 , V_521 -> V_43 ) ;
V_501 += sprintf ( V_500 + V_501 , V_503
L_108 , V_521 -> V_526 ) ;
V_501 += sprintf ( V_500 + V_501 , V_503
L_109 , V_521 -> V_42 ) ;
V_520 = V_521 -> V_42 - 28 ;
V_501 += sprintf ( V_500 + V_501 , V_503
L_110 , V_520 ) ;
switch ( V_521 -> V_43 & 0x07 ) {
case 1 :
V_501 += sprintf ( V_500 + V_501 , V_503
L_111 ,
V_521 -> V_527 . V_528 . V_529 ) ;
V_501 += sprintf ( V_500 + V_501 , V_503
L_112 ,
V_521 -> V_527 . V_528 . V_530 ) ;
V_501 += sprintf ( V_500 + V_501 , V_503
L_113 ,
V_521 -> V_527 . V_528 . V_531 ) ;
V_501 += sprintf ( V_500 + V_501 , V_503
L_114 ,
V_521 -> V_527 . V_528 . V_532 ) ;
V_501 += sprintf ( V_500 + V_501 , V_503
L_115 ,
V_521 -> V_527 . V_528 . V_533 ) ;
V_305 = V_521 -> V_527 . V_528 . V_305 ;
break;
case 2 :
V_501 += sprintf ( V_500 + V_501 , V_503
L_116 , V_521 -> V_527 . V_534 . V_34 ) ;
for ( V_510 = 0 ; V_510 < 2 ; V_510 ++ ) {
V_501 += sprintf ( V_500 + V_501 , V_503
L_117 ,
( 8 * V_510 ) , ( ( 8 * V_510 ) + 7 ) ) ;
V_522 = V_521 -> V_527 . V_534 . V_522 ;
for ( V_511 = 0 ; V_511 < 8 ; V_511 ++ ) {
V_501 += sprintf ( V_500 + V_501 , L_93 ,
V_522 [ 8 * V_510 + V_511 ] ) ;
}
V_501 += sprintf ( V_500 + V_501 , L_82 ) ;
}
V_305 = V_521 -> V_527 . V_534 . V_305 ;
break;
case 3 :
V_501 += sprintf ( V_500 + V_501 , V_503
L_118 ) ;
break;
}
if ( V_305 ) {
for ( V_510 = 0 ; V_510 < 4 ; V_510 ++ ) {
V_501 += sprintf ( V_500 + V_501 , V_503
L_92 ,
( 8 * V_510 ) , ( ( 8 * V_510 ) + 7 ) ) ;
for ( V_511 = 0 ; V_511 < 8 ; V_511 ++ ) {
V_501 += sprintf ( V_500 + V_501 , L_93 ,
V_305 [ 8 * V_510 + V_511 ] ) ;
}
V_501 += sprintf ( V_500 + V_501 , L_82 ) ;
}
if ( V_305 [ 27 ] & V_362 ) {
sprintf ( V_500 + V_501 , V_503
L_94
L_95 ,
V_305 [ 7 ] >> 4 , V_305 [ 7 ] & 0x0f ,
V_305 [ 1 ] & 0x10 ? L_59 : L_96 ) ;
} else {
sprintf ( V_500 + V_501 , V_503
L_97
L_98 ,
V_305 [ 6 ] & 0x0f , V_305 [ 22 ] >> 4 ) ;
}
} else {
sprintf ( V_500 + V_501 , V_503
L_99 ) ;
}
} else {
sprintf ( V_500 + V_501 , V_503
L_119 ) ;
}
F_179 ( V_518 L_1 , V_500 ) ;
F_181 ( ( unsigned long ) V_500 ) ;
}
static void F_184 ( struct V_30 * V_31 ,
struct V_167 * V_369 , struct V_309 * V_309 )
{
if ( F_185 ( & V_309 -> V_360 ) )
F_182 ( V_31 , V_369 , V_309 ) ;
else
F_171 ( V_31 , V_369 , V_309 ) ;
}
static int F_186 ( struct V_30 * V_31 )
{
F_103 ( V_31 ) ;
F_85 ( V_31 ) ;
return 0 ;
}
static int F_187 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
struct V_14 V_535 ;
int V_34 ;
struct V_149 V_271 ;
unsigned long V_43 ;
unsigned long V_536 = 0 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
F_50 ( V_31 ) ;
F_30 ( V_31 , & V_271 ) ;
V_34 = F_26 ( V_31 ) ;
F_27 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
if ( memcmp ( & V_33 -> V_134 , & V_271 , sizeof( struct V_149 ) ) != 0 )
F_15 ( & V_31 -> V_2 -> V_82 , L_120
L_121 ) ;
F_29 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
if ( V_34 )
goto V_537;
V_34 = F_82 ( V_31 ) ;
if ( V_34 )
return V_34 ;
F_34 ( V_257 , & V_536 ) ;
F_73 ( V_31 , V_536 ) ;
F_50 ( V_31 ) ;
F_68 ( V_31 ) ;
V_34 = F_83 ( V_31 , V_176 ,
& V_535 , 64 ) ;
if ( V_34 ) {
F_3 ( V_7 , V_31 -> V_2 ,
L_53 , V_34 ) ;
goto V_537;
}
F_27 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
memcpy ( & V_33 -> V_35 , & V_535 , sizeof( V_535 ) ) ;
F_29 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
F_99 ( V_31 ) ;
return 0 ;
V_537:
return - 1 ;
}
static int F_188 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
int V_34 , V_538 ;
char V_229 [ 60 ] ;
struct V_149 V_134 ;
unsigned long V_43 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
F_27 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
V_538 = V_33 -> V_134 . V_161 ;
F_29 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
V_34 = F_50 ( V_31 ) ;
if ( V_34 )
goto V_537;
V_34 = F_26 ( V_31 ) ;
if ( V_34 )
goto V_537;
F_189 ( V_31 ) ;
F_30 ( V_31 , & V_134 ) ;
if ( V_538 != V_134 . V_161 ) {
if ( strlen ( V_134 . V_163 ) > 0 )
snprintf ( V_229 , sizeof( V_229 ) ,
L_17 , V_134 . V_150 , V_134 . V_152 ,
V_134 . V_154 , V_134 . V_161 , V_134 . V_163 ) ;
else
snprintf ( V_229 , sizeof( V_229 ) ,
L_18 , V_134 . V_150 , V_134 . V_152 ,
V_134 . V_154 , V_134 . V_161 ) ;
F_80 ( & V_31 -> V_2 -> V_82 ,
L_122
L_123 , V_229 ) ;
}
return 0 ;
V_537:
return - 1 ;
}
static int F_190 ( struct V_30 * V_31 ,
struct V_539 * V_540 ,
T_2 V_541 )
{
struct V_539 * V_542 ;
struct V_238 * V_239 ;
struct V_32 * V_33 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
int V_34 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_168 = F_43 ( V_176 , 1 + 1 ,
( sizeof( struct V_238 ) +
sizeof( struct V_539 ) ) ,
V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_124 ) ;
return F_69 ( V_168 ) ;
}
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_178 = NULL ;
V_168 -> V_181 = 256 ;
V_168 -> V_179 = 10 * V_180 ;
F_34 ( V_185 , & V_168 -> V_43 ) ;
V_168 -> V_170 = V_541 ;
V_239 = (struct V_238 * ) V_168 -> V_29 ;
memset ( V_239 , 0 , sizeof( struct V_238 ) ) ;
V_239 -> V_242 = V_243 ;
V_239 -> V_244 = 0x03 ;
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_245 ;
V_45 -> V_42 = sizeof( struct V_238 ) ;
V_45 -> V_43 |= V_246 ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_239 ;
V_542 = (struct V_539 * ) ( V_239 + 1 ) ;
memset ( V_542 , 0 , sizeof( struct V_539 ) ) ;
V_45 ++ ;
V_45 -> V_54 = V_247 ;
V_45 -> V_42 = sizeof( struct V_539 ) ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_542 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_40 ( V_168 ) ;
if ( V_34 == 0 ) {
V_239 = (struct V_238 * ) V_168 -> V_29 ;
V_542 = (struct V_539 * )
( V_239 + 1 ) ;
memcpy ( V_540 , V_542 ,
sizeof( struct V_539 ) ) ;
} else
F_3 ( V_7 , V_31 -> V_2 ,
L_125
, V_34 ) ;
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int
F_191 ( struct V_30 * V_31 , int V_543 ,
T_1 V_544 ,
struct V_545 * V_546 ,
struct V_547 V_548 )
{
struct V_549 * V_550 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
int V_34 ;
V_168 = F_43 ( V_176 , 1 ,
sizeof( struct V_549 ) ,
V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_18 ( V_7 , V_31 , L_1 ,
L_126 ) ;
return F_69 ( V_168 ) ;
}
V_550 = (struct V_549 * ) V_168 -> V_29 ;
V_550 -> V_242 = V_551 ;
V_550 -> V_552 = V_543 ;
if ( V_546 )
V_550 -> V_553 = V_546 -> V_553 ;
V_550 -> V_544 = V_544 ;
V_550 -> V_554 = V_548 . V_554 ;
V_550 -> V_154 = V_548 . V_154 ;
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_245 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_550 ;
V_45 -> V_42 = sizeof( struct V_549 ) ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_178 = NULL ;
V_168 -> V_181 = 256 ;
V_168 -> V_179 = 10 * V_180 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_45 ( V_168 ) ;
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int F_192 ( struct V_30 * V_31 , T_2 V_541 )
{
unsigned long V_43 ;
T_2 V_555 ;
F_27 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
V_555 = V_31 -> V_213 . V_210 & ~ V_541 ;
if ( V_555 ) {
V_31 -> V_213 . V_210 = V_555 ;
V_31 -> V_213 . V_220 |= V_541 ;
}
F_29 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
return V_555 ? 0 : V_556 ;
}
static int F_193 ( struct V_30 * V_31 , T_2 V_541 ,
struct V_545 * V_546 ,
struct V_547 V_548 )
{
struct V_557 * V_558 , * V_559 ;
struct V_32 * V_33 ;
struct V_30 * V_82 , * V_343 ;
int V_34 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_34 = 0 ;
F_112 (dev, n,
&private->lcu->active_devices,
alias_list) {
V_34 = F_192 ( V_82 , V_541 ) ;
if ( V_34 )
goto V_441;
}
F_112 (dev, n,
&private->lcu->inactive_devices,
alias_list) {
V_34 = F_192 ( V_82 , V_541 ) ;
if ( V_34 )
goto V_441;
}
F_112 (pavgroup, tempgroup,
&private->lcu->grouplist, group) {
F_112 (dev, n, &pavgroup->baselist,
alias_list) {
V_34 = F_192 ( V_82 , V_541 ) ;
if ( V_34 )
goto V_441;
}
F_112 (dev, n, &pavgroup->aliaslist,
alias_list) {
V_34 = F_192 ( V_82 , V_541 ) ;
if ( V_34 )
goto V_441;
}
}
F_194 ( L_127 ,
V_548 . V_554 , V_546 ? V_546 -> V_553 : 0 ) ;
V_34 = V_560 ;
V_441:
return V_34 ;
}
static int F_195 ( struct V_30 * V_31 , T_2 V_541 ,
struct V_545 * V_546 ,
struct V_547 V_548 )
{
struct V_557 * V_558 , * V_559 ;
struct V_32 * V_33 ;
struct V_30 * V_82 , * V_343 ;
F_196 ( L_128 ,
V_548 . V_554 , V_546 ? V_546 -> V_553 : 0 ) ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
F_112 (dev, n,
&private->lcu->active_devices,
alias_list) {
if ( ! ( V_82 -> V_213 . V_210 & V_541 ) ) {
V_82 -> V_213 . V_232 |= V_541 ;
F_197 ( V_82 ) ;
}
}
F_112 (dev, n,
&private->lcu->inactive_devices,
alias_list) {
if ( ! ( V_82 -> V_213 . V_210 & V_541 ) ) {
V_82 -> V_213 . V_232 |= V_541 ;
F_197 ( V_82 ) ;
}
}
F_112 (pavgroup, tempgroup,
&private->lcu->grouplist,
group) {
F_112 (dev, n,
&pavgroup->baselist,
alias_list) {
if ( ! ( V_82 -> V_213 . V_210 & V_541 ) ) {
V_82 -> V_213 . V_232 |= V_541 ;
F_197 ( V_82 ) ;
}
}
F_112 (dev, n,
&pavgroup->aliaslist,
alias_list) {
if ( ! ( V_82 -> V_213 . V_210 & V_541 ) ) {
V_82 -> V_213 . V_232 |= V_541 ;
F_197 ( V_82 ) ;
}
}
}
return V_560 ;
}
static void F_198 ( struct V_30 * V_31 , void * V_540 ,
T_2 V_541 )
{
struct V_561 * V_562 = V_540 ;
struct V_545 * V_546 ;
struct V_547 V_548 ;
int V_563 , V_543 ;
F_199 ( V_31 -> V_2 , & V_548 ) ;
V_563 = 8 - F_200 ( V_541 ) ;
V_546 = F_201 ( V_31 -> V_2 , V_563 ) ;
if ( V_562 -> V_564 == V_565 ) {
V_543 = F_193 ( V_31 , V_541 , V_546 , V_548 ) ;
} else if ( V_562 -> V_564 == V_566 ) {
V_543 = F_195 ( V_31 , V_541 , V_546 , V_548 ) ;
} else
V_543 = V_567 ;
F_191 ( V_31 , V_543 , V_562 -> V_544 ,
V_546 , V_548 ) ;
F_47 ( V_546 ) ;
}
static void F_202 ( struct V_225 * V_226 )
{
struct V_568 * V_29 ;
struct V_539 * V_540 ;
struct V_30 * V_31 ;
int V_34 ;
V_29 = F_57 ( V_226 , struct V_568 , V_230 ) ;
V_31 = V_29 -> V_31 ;
V_540 = F_42 ( sizeof( * V_540 ) , V_195 ) ;
if ( ! V_540 ) {
F_18 ( V_7 , V_31 , L_1 ,
L_129 ) ;
goto V_441;
}
V_34 = F_190 ( V_31 , V_540 , V_29 -> V_541 ) ;
if ( V_34 )
goto V_441;
if ( V_540 -> V_106 == V_569 &&
V_540 -> V_120 == V_570 )
F_198 ( V_31 , V_540 , V_29 -> V_541 ) ;
V_441:
F_61 ( V_31 ) ;
F_47 ( V_540 ) ;
F_47 ( V_29 ) ;
}
static int F_203 ( struct V_30 * V_31 , T_2 V_541 )
{
struct V_568 * V_29 ;
V_29 = F_42 ( sizeof( * V_29 ) , V_236 ) ;
if ( ! V_29 )
return - V_197 ;
F_66 ( & V_29 -> V_230 , F_202 ) ;
F_67 ( V_31 ) ;
V_29 -> V_31 = V_31 ;
V_29 -> V_541 = V_541 ;
F_59 ( & V_29 -> V_230 ) ;
return 0 ;
}
static int T_11
F_204 ( void )
{
int V_3 ;
F_205 ( V_8 . V_571 , 4 ) ;
V_464 = F_64 ( sizeof( * V_464 ) ,
V_195 | V_196 ) ;
if ( ! V_464 )
return - V_197 ;
V_237 = F_64 ( sizeof( * V_237 ) ,
V_195 | V_196 ) ;
if ( ! V_237 ) {
F_47 ( V_464 ) ;
return - V_197 ;
}
V_442 = ( void * ) F_206 ( V_195 ) ;
if ( ! V_442 ) {
F_47 ( V_237 ) ;
F_47 ( V_464 ) ;
return - V_197 ;
}
V_3 = F_207 ( & V_572 ) ;
if ( ! V_3 )
F_208 () ;
else {
F_47 ( V_237 ) ;
F_47 ( V_464 ) ;
F_181 ( ( unsigned long ) V_442 ) ;
}
return V_3 ;
}
static void T_12
F_209 ( void )
{
F_210 ( & V_572 ) ;
F_47 ( V_237 ) ;
F_47 ( V_464 ) ;
F_181 ( ( unsigned long ) V_442 ) ;
}
