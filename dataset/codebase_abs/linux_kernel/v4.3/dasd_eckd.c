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
int V_34 , V_209 , V_210 ;
T_2 V_170 , V_211 ;
struct V_32 * V_33 , V_212 ;
struct V_213 * V_214 ;
struct V_149 * V_134 ;
char V_215 [ 60 ] , V_216 [ 60 ] ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_214 = & V_31 -> V_214 ;
V_211 = F_51 ( V_31 -> V_2 ) ;
V_208 = 0 ;
V_209 = 0 ;
for ( V_170 = 0x80 ; V_170 ; V_170 >>= 1 ) {
if ( ! ( V_170 & V_211 ) )
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
V_214 -> V_211 |= V_170 ;
continue;
}
V_210 = 8 - F_52 ( V_170 ) ;
F_47 ( V_33 -> V_217 [ V_210 ] ) ;
if ( ( T_2 * ) V_33 -> V_217 [ V_210 ] ==
V_33 -> V_201 ) {
V_33 -> V_201 = NULL ;
V_33 -> V_200 = 0 ;
V_208 = 0 ;
}
V_33 -> V_217 [ V_210 ] =
(struct V_218 * ) V_201 ;
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
V_212 . V_201 = V_201 ;
V_212 . V_200 = V_174 ;
if ( F_48 (
& V_212 ) ) {
V_212 . V_201 = NULL ;
V_212 . V_200 = 0 ;
F_47 ( V_201 ) ;
continue;
}
if ( F_31 (
V_31 , & V_212 ) ) {
V_134 = & V_212 . V_134 ;
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
V_134 = & V_33 -> V_134 ;
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
F_15 ( & V_31 -> V_2 -> V_82 ,
L_19
L_20
L_21 , V_170 ,
V_215 , V_216 ) ;
V_209 = - V_128 ;
V_214 -> V_219 |= V_170 ;
continue;
}
V_212 . V_201 = NULL ;
V_212 . V_200 = 0 ;
}
switch ( F_49 ( V_201 , V_200 ) ) {
case 0x02 :
V_214 -> V_220 |= V_170 ;
break;
case 0x03 :
V_214 -> V_221 |= V_170 ;
break;
}
V_214 -> V_211 |= V_170 ;
V_214 -> V_219 &= ~ V_170 ;
V_214 -> V_222 &= ~ V_170 ;
V_214 -> V_223 &= ~ V_170 ;
}
return V_209 ;
}
static int F_53 ( struct V_30 * V_31 , T_2 V_170 )
{
struct V_32 * V_33 ;
int V_224 ;
T_3 V_225 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
if ( V_33 -> V_225 ) {
V_224 = F_54 ( V_31 -> V_2 , V_170 ) ;
if ( ( V_224 < 0 ) ) {
F_55 ( & V_31 -> V_2 -> V_82 ,
L_22
L_23 ,
V_224 , V_170 ) ;
return V_224 ;
}
V_225 = V_224 * V_226 ;
if ( V_225 < V_33 -> V_225 ) {
F_55 ( & V_31 -> V_2 -> V_82 ,
L_24
L_25
L_26 , V_225 , V_170 ,
V_33 -> V_225 ) ;
return - V_41 ;
}
}
return 0 ;
}
static int F_56 ( struct V_30 * V_31 ,
struct V_227 * V_29 )
{
struct V_32 * V_33 ;
struct V_213 * V_214 ;
T_2 V_170 , V_211 ;
int V_34 ;
V_34 = - V_165 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_214 = & V_31 -> V_214 ;
V_211 = V_31 -> V_214 . V_211 ;
for ( V_170 = 0x80 ; V_170 ; V_170 >>= 1 ) {
if ( ! ( V_170 & V_211 ) )
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
static void F_57 ( struct V_228 * V_229 )
{
struct V_227 * V_29 ;
struct V_30 * V_31 ;
struct V_32 V_212 ;
struct V_149 * V_134 ;
T_2 V_230 [ V_174 ] ;
T_2 V_170 , V_211 , V_220 , V_221 , V_231 , V_222 , V_219 ;
unsigned long V_43 ;
char V_232 [ 60 ] ;
int V_34 ;
V_29 = F_58 ( V_229 , struct V_227 , V_233 ) ;
V_31 = V_29 -> V_31 ;
if ( F_59 ( V_234 , & V_31 -> V_43 ) ) {
F_60 ( V_229 ) ;
return;
}
if ( F_61 ( V_235 , & V_31 -> V_43 ) ) {
F_60 ( V_229 ) ;
return;
}
V_211 = 0 ;
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
V_211 |= V_170 ;
} else if ( V_34 == - V_40 ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_29
L_30 ) ;
V_211 |= V_170 ;
} else if ( V_34 == - V_237 ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_31
L_32 ) ;
V_231 |= V_170 ;
} else {
F_55 ( & V_31 -> V_2 -> V_82 ,
L_33
L_34 , V_34 , V_170 ) ;
continue;
}
if ( F_53 ( V_31 , V_170 ) ) {
V_211 &= ~ V_170 ;
V_220 &= ~ V_170 ;
V_221 &= ~ V_170 ;
V_222 |= V_170 ;
continue;
}
memcpy ( & V_230 , V_29 -> V_169 ,
V_174 ) ;
V_212 . V_201 = ( void * ) & V_230 ;
V_212 . V_200 = V_174 ;
if ( F_48 ( & V_212 ) ) {
V_212 . V_201 = NULL ;
V_212 . V_200 = 0 ;
continue;
}
if ( V_31 -> V_214 . V_211 &&
F_31 ( V_31 , & V_212 ) ) {
if ( F_56 ( V_31 , V_29 ) ||
F_31 (
V_31 , & V_212 ) ) {
V_134 = & V_212 . V_134 ;
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
V_211 &= ~ V_170 ;
V_220 &= ~ V_170 ;
V_221 &= ~ V_170 ;
V_219 |= V_170 ;
continue;
}
}
F_27 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
if ( ! V_31 -> V_214 . V_211 && V_211 ) {
V_31 -> V_214 . V_211 = V_211 ;
V_31 -> V_214 . V_219 &= ~ V_211 ;
V_31 -> V_214 . V_223 &= ~ V_211 ;
V_31 -> V_214 . V_222 &= ~ V_211 ;
F_62 ( V_31 ) ;
} else {
V_31 -> V_214 . V_211 |= V_211 ;
V_31 -> V_214 . V_219 &= ~ V_211 ;
V_31 -> V_214 . V_223 &= ~ V_211 ;
V_31 -> V_214 . V_222 &= ~ V_211 ;
}
V_31 -> V_214 . V_220 |= V_220 ;
V_31 -> V_214 . V_221 |= V_221 ;
V_31 -> V_214 . V_236 |= V_231 ;
V_31 -> V_214 . V_219 |= V_219 ;
V_31 -> V_214 . V_222 |= V_222 ;
F_29 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
}
F_39 ( V_235 , & V_31 -> V_43 ) ;
F_63 ( V_31 ) ;
if ( V_29 -> V_238 )
F_64 ( & V_239 ) ;
else
F_47 ( V_29 ) ;
}
static int F_65 ( struct V_30 * V_31 , T_2 V_170 )
{
struct V_227 * V_29 ;
V_29 = F_66 ( sizeof( * V_29 ) , V_240 | V_196 ) ;
if ( ! V_29 ) {
if ( F_67 ( & V_239 ) ) {
V_29 = V_241 ;
V_29 -> V_238 = 1 ;
} else
return - V_197 ;
} else {
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_29 -> V_238 = 0 ;
}
F_68 ( & V_29 -> V_233 , F_57 ) ;
F_69 ( V_31 ) ;
V_29 -> V_31 = V_31 ;
V_29 -> V_236 = V_170 ;
F_60 ( & V_29 -> V_233 ) ;
return 0 ;
}
static int F_70 ( struct V_30 * V_31 )
{
struct V_242 * V_243 ;
struct V_244 * V_245 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
int V_34 ;
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
memset ( & V_33 -> V_245 , 0 , sizeof( struct V_244 ) ) ;
V_168 = F_43 ( V_176 , 1 + 1 ,
( sizeof( struct V_242 ) +
sizeof( struct V_244 ) ) ,
V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 , L_38
L_39 ) ;
return F_71 ( V_168 ) ;
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
F_55 ( & V_31 -> V_2 -> V_82 , L_40
L_41 , V_34 ) ;
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static struct V_167 * F_72 ( struct V_30 * V_31 ,
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
F_73 ( struct V_30 * V_31 , int V_252 ,
unsigned long V_43 )
{
struct V_167 * V_168 ;
int V_34 ;
V_168 = F_72 ( V_31 , V_252 ) ;
if ( F_44 ( V_168 ) )
return F_71 ( V_168 ) ;
V_168 -> V_43 |= V_43 ;
V_34 = F_45 ( V_168 ) ;
if ( ! V_34 )
F_74 () ;
else if ( V_168 -> V_257 == - V_237 )
V_34 = - V_237 ;
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int F_75 ( struct V_30 * V_31 ,
unsigned long V_43 )
{
int V_34 ;
struct V_32 * V_33 ;
int V_252 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
if ( V_33 -> V_134 . type == V_160 ||
V_33 -> V_134 . type == V_137 )
return 0 ;
if ( V_258 || V_259 )
V_252 = 0 ;
else
V_252 = 1 ;
V_34 = F_73 ( V_31 , V_252 , V_43 ) ;
F_3 ( V_7 , V_31 -> V_2 , L_43
L_44 , V_33 -> V_134 . V_154 , V_34 ) ;
return V_34 ;
}
static void F_76 ( struct V_228 * V_229 )
{
struct V_30 * V_31 = F_58 ( V_229 , struct V_30 ,
V_260 ) ;
unsigned long V_43 = 0 ;
F_34 ( V_261 , & V_43 ) ;
if ( F_75 ( V_31 , V_43 )
== - V_237 ) {
F_60 ( & V_31 -> V_260 ) ;
return;
}
F_63 ( V_31 ) ;
}
static void F_77 ( struct V_30 * V_31 )
{
F_69 ( V_31 ) ;
if ( F_59 ( V_262 , & V_31 -> V_43 ) ||
V_31 -> V_263 < V_264 ) {
F_63 ( V_31 ) ;
return;
}
if ( ! F_60 ( & V_31 -> V_260 ) )
F_63 ( V_31 ) ;
}
static T_3 F_78 ( struct V_30 * V_31 )
{
int V_265 , V_224 ;
int V_266 , V_267 , V_268 ;
struct V_32 * V_33 ;
if ( V_269 )
return 0 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_266 = V_270 . V_271 ;
V_267 = V_33 -> V_155 -> V_272 [ 7 ] & 0x04 ;
V_268 = V_33 -> V_245 . V_273 [ 40 ] & 0x80 ;
V_265 = V_266 && V_267 && V_268 ;
if ( ! V_265 )
return 0 ;
V_224 = F_54 ( V_31 -> V_2 , 0 ) ;
if ( V_224 < 0 ) {
F_55 ( & V_31 -> V_2 -> V_82 , L_45
L_46 ) ;
return 0 ;
} else
return V_224 * V_226 ;
}
static int
F_79 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
struct V_274 * V_178 ;
struct V_149 V_275 ;
int V_34 , V_199 ;
int V_276 ;
unsigned long V_277 ;
F_68 ( & V_31 -> V_260 , F_76 ) ;
if ( ! F_80 ( V_31 -> V_2 ) ) {
F_55 ( & V_31 -> V_2 -> V_82 ,
L_47 ) ;
return - V_278 ;
}
if ( ! F_81 ( V_31 -> V_2 ) ) {
F_82 ( & V_31 -> V_2 -> V_82 ,
L_48 ) ;
}
V_33 = (struct V_32 * ) V_31 -> V_33 ;
if ( ! V_33 ) {
V_33 = F_42 ( sizeof( * V_33 ) , V_195 | V_196 ) ;
if ( ! V_33 ) {
F_55 ( & V_31 -> V_2 -> V_82 ,
L_49
L_50 ) ;
return - V_197 ;
}
V_31 -> V_33 = ( void * ) V_33 ;
} else {
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
}
V_33 -> V_279 = - 1 ;
V_33 -> V_70 . V_69 = V_280 ;
V_33 -> V_70 . V_89 = 0 ;
V_34 = F_50 ( V_31 ) ;
if ( V_34 )
goto V_281;
V_31 -> V_282 = V_283 ;
V_31 -> V_284 = V_285 ;
if ( V_33 -> V_155 ) {
V_277 = 1 ;
for ( V_199 = 0 ; V_199 < V_33 -> V_155 -> V_286 . V_277 ; V_199 ++ )
V_277 = 10 * V_277 ;
V_277 = V_277 * V_33 -> V_155 -> V_286 . V_287 ;
if ( V_277 != 0 && V_277 <= V_288 )
V_31 -> V_282 = V_277 ;
}
F_30 ( V_31 , & V_275 ) ;
if ( V_275 . type == V_135 ) {
V_178 = F_83 () ;
if ( F_44 ( V_178 ) ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_51
L_52 ) ;
V_34 = F_71 ( V_178 ) ;
goto V_281;
}
V_31 -> V_178 = V_178 ;
V_178 -> V_289 = V_31 ;
}
V_34 = F_84 ( V_31 ) ;
if ( V_34 )
goto V_290;
F_75 ( V_31 , 0 ) ;
V_34 = F_50 ( V_31 ) ;
if ( V_34 )
goto V_291;
F_70 ( V_31 ) ;
V_34 = F_85 ( V_31 , V_176 ,
& V_33 -> V_35 , 64 ) ;
if ( V_34 ) {
F_3 ( V_7 , V_31 -> V_2 ,
L_53 , V_34 ) ;
goto V_291;
}
if ( ( V_31 -> V_245 & V_292 ) &&
! ( V_33 -> V_35 . V_36 . V_293 ) ) {
F_15 ( & V_31 -> V_2 -> V_82 , L_54
L_55 ) ;
V_34 = - V_128 ;
goto V_291;
}
if ( V_33 -> V_35 . V_294 == V_295 &&
V_33 -> V_35 . V_296 )
V_33 -> V_90 = V_33 -> V_35 . V_296 ;
else
V_33 -> V_90 = V_33 -> V_35 . V_294 ;
V_33 -> V_225 = F_78 ( V_31 ) ;
V_276 = F_86 ( V_31 ) ;
if ( V_276 )
F_34 ( V_297 , & V_31 -> V_43 ) ;
F_82 ( & V_31 -> V_2 -> V_82 , L_56
L_57 ,
V_33 -> V_35 . V_20 ,
V_33 -> V_35 . V_298 ,
V_33 -> V_35 . V_84 ,
V_33 -> V_35 . V_299 . V_300 ,
V_33 -> V_90 ,
V_33 -> V_35 . V_86 ,
V_33 -> V_35 . V_301 ,
V_276 ? L_58 : L_59 ) ;
return 0 ;
V_291:
F_87 ( V_31 ) ;
V_290:
F_88 ( V_31 -> V_178 ) ;
V_31 -> V_178 = NULL ;
V_281:
F_47 ( V_33 -> V_201 ) ;
F_47 ( V_31 -> V_33 ) ;
V_31 -> V_33 = NULL ;
return V_34 ;
}
static void F_89 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
int V_199 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
F_87 ( V_31 ) ;
V_33 -> V_130 = NULL ;
V_33 -> V_158 = NULL ;
V_33 -> V_162 = NULL ;
V_33 -> V_155 = NULL ;
V_33 -> V_200 = 0 ;
for ( V_199 = 0 ; V_199 < 8 ; V_199 ++ ) {
F_47 ( V_33 -> V_217 [ V_199 ] ) ;
if ( ( T_2 * ) V_33 -> V_217 [ V_199 ] ==
V_33 -> V_201 ) {
V_33 -> V_201 = NULL ;
V_33 -> V_200 = 0 ;
}
V_33 -> V_217 [ V_199 ] = NULL ;
}
F_47 ( V_33 -> V_201 ) ;
V_33 -> V_201 = NULL ;
}
static struct V_167 *
F_90 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
struct V_302 * V_303 ;
struct V_140 * V_304 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
int V_305 , V_306 ;
int V_199 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_305 = 8 ;
V_306 = sizeof( struct V_28 ) + 2 * sizeof( struct V_140 ) ;
V_168 = F_43 ( V_176 , V_305 , V_306 , V_31 ) ;
if ( F_44 ( V_168 ) )
return V_168 ;
V_45 = V_168 -> V_171 ;
F_13 ( V_45 ++ , V_168 -> V_29 , 0 , 2 ,
V_65 , V_31 ) ;
V_304 = V_168 -> V_29 + sizeof( struct V_28 ) ;
V_45 [ - 1 ] . V_43 |= V_250 ;
V_126 ( V_45 ++ , V_304 ++ , 0 , 0 , 4 ,
V_65 , V_31 , 0 ) ;
V_303 = V_33 -> V_307 ;
for ( V_199 = 0 ; V_199 < 4 ; V_199 ++ ) {
V_45 [ - 1 ] . V_43 |= V_250 ;
V_45 -> V_54 = V_65 ;
V_45 -> V_43 = 0 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_303 ;
V_45 ++ ;
V_303 ++ ;
}
V_45 [ - 1 ] . V_43 |= V_250 ;
V_126 ( V_45 ++ , V_304 ++ , 2 , 0 , 1 ,
V_65 , V_31 , 0 ) ;
V_45 [ - 1 ] . V_43 |= V_250 ;
V_45 -> V_54 = V_65 ;
V_45 -> V_43 = 0 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_303 ;
V_168 -> V_178 = NULL ;
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_181 = 255 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
return V_168 ;
}
static int F_91 ( struct V_167 * V_308 )
{
char * V_309 ;
if ( V_308 -> V_183 == V_186 )
return V_310 ;
else if ( V_308 -> V_183 == V_311 ||
V_308 -> V_183 == V_312 ) {
V_309 = F_92 ( & V_308 -> V_313 ) ;
if ( V_309 && ( V_309 [ 1 ] & V_314 ) )
return V_315 ;
else
return V_316 ;
} else
return V_316 ;
}
static void F_93 ( struct V_167 * V_308 ,
void * V_29 )
{
struct V_32 * V_33 ;
struct V_30 * V_31 ;
V_31 = V_308 -> V_119 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_33 -> V_279 = F_91 ( V_308 ) ;
F_46 ( V_308 , V_31 ) ;
F_94 ( V_31 ) ;
}
static int F_95 ( struct V_274 * V_178 )
{
struct V_167 * V_308 ;
V_308 = F_90 ( V_178 -> V_289 ) ;
if ( F_44 ( V_308 ) )
return F_71 ( V_308 ) ;
V_308 -> V_191 = F_93 ;
V_308 -> V_317 = NULL ;
V_308 -> V_179 = 5 * V_180 ;
F_39 ( V_189 , & V_308 -> V_43 ) ;
V_308 -> V_181 = 0 ;
F_96 ( V_308 ) ;
return - V_237 ;
}
static int F_97 ( struct V_274 * V_178 )
{
struct V_30 * V_31 ;
struct V_32 * V_33 ;
struct V_302 * V_307 ;
unsigned int V_318 , V_145 ;
int V_183 , V_199 ;
struct V_167 * V_308 ;
V_31 = V_178 -> V_289 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_183 = V_33 -> V_279 ;
V_33 -> V_279 = - 1 ;
if ( V_183 == V_316 ) {
V_308 = F_90 ( V_31 ) ;
F_45 ( V_308 ) ;
V_183 = F_91 ( V_308 ) ;
F_46 ( V_308 , V_31 ) ;
}
if ( V_31 -> V_245 & V_292 ) {
V_178 -> V_319 = V_320 ;
V_145 = V_321 ;
V_178 -> V_322 = 3 ;
goto V_323;
}
if ( V_183 == V_315 ) {
F_55 ( & V_31 -> V_2 -> V_82 , L_60 ) ;
return - V_324 ;
} else if ( V_183 == V_316 ) {
F_15 ( & V_31 -> V_2 -> V_82 ,
L_61
L_62 ) ;
return - V_278 ;
}
V_33 -> V_85 = 1 ;
V_307 = NULL ;
for ( V_199 = 0 ; V_199 < 3 ; V_199 ++ ) {
if ( V_33 -> V_307 [ V_199 ] . V_16 != 4 ||
V_33 -> V_307 [ V_199 ] . V_17 != F_23 ( V_199 ) - 4 ||
V_33 -> V_307 [ V_199 ] . V_23 != 0 ||
V_33 -> V_307 [ V_199 ] . V_24 != V_325 [ V_199 ] ||
V_33 -> V_307 [ V_199 ] . V_117 != V_326 [ V_199 ] ) {
V_33 -> V_85 = 0 ;
break;
}
}
if ( V_199 == 3 )
V_307 = & V_33 -> V_307 [ 4 ] ;
if ( V_33 -> V_85 == 0 ) {
for ( V_199 = 0 ; V_199 < 5 ; V_199 ++ ) {
if ( ( V_33 -> V_307 [ V_199 ] . V_16 != 0 ) ||
( V_33 -> V_307 [ V_199 ] . V_17 !=
V_33 -> V_307 [ 0 ] . V_17 ) ||
V_33 -> V_307 [ V_199 ] . V_23 != 0 ||
V_33 -> V_307 [ V_199 ] . V_24 != V_325 [ V_199 ] ||
V_33 -> V_307 [ V_199 ] . V_117 != V_326 [ V_199 ] )
break;
}
if ( V_199 == 5 )
V_307 = & V_33 -> V_307 [ 0 ] ;
} else {
if ( V_33 -> V_307 [ 3 ] . V_117 == 1 )
F_55 ( & V_31 -> V_2 -> V_82 ,
L_63 ) ;
}
if ( V_307 != NULL && V_307 -> V_16 == 0 ) {
if ( F_98 ( V_307 -> V_17 ) == 0 )
V_178 -> V_319 = V_307 -> V_17 ;
}
if ( V_178 -> V_319 == 0 ) {
F_55 ( & V_31 -> V_2 -> V_82 ,
L_64 ) ;
return - V_324 ;
}
V_178 -> V_322 = 0 ;
for ( V_318 = 512 ; V_318 < V_178 -> V_319 ; V_318 = V_318 << 1 )
V_178 -> V_322 ++ ;
V_145 = F_9 ( & V_33 -> V_35 , 0 , V_178 -> V_319 ) ;
V_323:
V_178 -> V_327 = ( V_33 -> V_90 *
V_33 -> V_35 . V_86 *
V_145 ) ;
F_82 ( & V_31 -> V_2 -> V_82 ,
L_65
L_66 , ( V_178 -> V_319 >> 10 ) ,
( ( V_33 -> V_90 *
V_33 -> V_35 . V_86 *
V_145 * ( V_178 -> V_319 >> 9 ) ) >> 1 ) ,
( ( V_145 * V_178 -> V_319 ) >> 10 ) ,
V_33 -> V_85 ?
L_67 : L_68 ) ;
return 0 ;
}
static int F_99 ( struct V_274 * V_178 )
{
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_178 -> V_289 -> V_33 ;
if ( V_33 -> V_279 < 0 )
return F_95 ( V_178 ) ;
else
return F_97 ( V_178 ) ;
}
static int F_100 ( struct V_30 * V_31 )
{
return F_101 ( V_31 ) ;
}
static int F_102 ( struct V_30 * V_31 )
{
F_103 ( & V_31 -> V_328 ) ;
F_103 ( & V_31 -> V_260 ) ;
return 0 ;
}
static int F_104 ( struct V_30 * V_31 )
{
return F_105 ( V_31 ) ;
}
static int
F_106 ( struct V_274 * V_178 , struct V_329 * V_22 )
{
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_178 -> V_289 -> V_33 ;
if ( F_98 ( V_178 -> V_319 ) == 0 ) {
V_22 -> V_330 = F_9 ( & V_33 -> V_35 ,
0 , V_178 -> V_319 ) ;
}
V_22 -> V_331 = V_33 -> V_35 . V_294 ;
V_22 -> V_51 = V_33 -> V_35 . V_86 ;
return 0 ;
}
static struct V_167 *
F_107 ( struct V_30 * V_289 ,
struct V_332 * V_333 ,
int V_252 )
{
struct V_32 * V_334 ;
struct V_32 * V_335 ;
struct V_30 * V_119 = NULL ;
struct V_167 * V_336 ;
struct V_302 * V_337 ;
struct V_21 V_338 ;
struct V_26 * V_45 ;
void * V_29 ;
int V_339 ;
int V_305 , V_306 ;
int V_199 , V_340 ;
int V_341 = 0 ;
int V_342 ;
int V_343 ;
int V_344 ;
if ( V_252 )
V_119 = F_108 ( V_289 ) ;
if ( ! V_119 )
V_119 = V_289 ;
V_335 = (struct V_32 * ) V_119 -> V_33 ;
V_334 = (struct V_32 * ) V_289 -> V_33 ;
V_339 = F_9 ( & V_334 -> V_35 , 0 , V_333 -> V_121 ) ;
V_343 = V_333 -> V_345 - V_333 -> V_346 + 1 ;
if ( V_333 -> V_341 & 0x10 ) {
V_342 = 0 ;
V_341 = V_333 -> V_341 & ~ 0x10 ;
} else {
V_342 = 1 ;
V_341 = V_333 -> V_341 ;
}
V_344 = V_334 -> V_245 . V_273 [ 8 ] & 0x01 ;
switch ( V_341 ) {
case 0x00 :
case 0x08 :
V_305 = 2 + ( V_339 * V_343 ) ;
if ( V_344 )
V_306 = sizeof( struct V_93 ) +
sizeof( struct V_140 ) +
V_339 * V_343 * sizeof( struct V_302 ) ;
else
V_306 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
V_339 * V_343 * sizeof( struct V_302 ) ;
break;
case 0x01 :
case 0x09 :
V_305 = 2 + V_339 * V_343 ;
if ( V_344 )
V_306 = sizeof( struct V_93 ) +
sizeof( struct V_140 ) +
sizeof( struct V_302 ) +
V_339 * V_343 * sizeof( struct V_302 ) ;
else
V_306 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
sizeof( struct V_302 ) +
V_339 * V_343 * sizeof( struct V_302 ) ;
break;
case 0x04 :
case 0x0c :
V_305 = 3 ;
if ( V_344 )
V_306 = sizeof( struct V_93 ) +
sizeof( struct V_140 ) +
sizeof( struct V_302 ) ;
else
V_306 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
sizeof( struct V_302 ) ;
break;
default:
F_55 ( & V_119 -> V_2 -> V_82 ,
L_69 ,
V_333 -> V_341 ) ;
return F_109 ( - V_128 ) ;
}
V_336 = F_43 ( V_176 , V_305 ,
V_306 , V_119 ) ;
if ( F_44 ( V_336 ) )
return V_336 ;
V_335 -> V_42 ++ ;
V_29 = V_336 -> V_29 ;
V_45 = V_336 -> V_171 ;
switch ( V_341 & ~ 0x08 ) {
case 0x00 :
if ( V_344 ) {
F_21 ( V_45 ++ , (struct V_93 * ) V_29 ,
V_333 -> V_346 , V_333 -> V_345 ,
V_75 , V_289 , V_119 ) ;
if ( V_342 )
( (struct V_93 * ) V_29 )
-> F_13 . V_38 |= 0x04 ;
V_29 += sizeof( struct V_93 ) ;
} else {
F_13 ( V_45 ++ , (struct V_28 * ) V_29 ,
V_333 -> V_346 , V_333 -> V_345 ,
V_75 , V_119 ) ;
if ( V_342 )
( (struct V_28 * ) V_29 )
-> V_38 |= 0x04 ;
V_29 += sizeof( struct V_28 ) ;
}
V_45 [ - 1 ] . V_43 |= V_250 ;
V_126 ( V_45 ++ , (struct V_140 * ) V_29 ,
V_333 -> V_346 , 0 , V_339 * V_343 ,
V_75 , V_289 ,
V_333 -> V_121 ) ;
V_29 += sizeof( struct V_140 ) ;
break;
case 0x01 :
if ( V_344 ) {
F_21 ( V_45 ++ , (struct V_93 * ) V_29 ,
V_333 -> V_346 , V_333 -> V_345 ,
V_80 ,
V_289 , V_119 ) ;
V_29 += sizeof( struct V_93 ) ;
} else {
F_13 ( V_45 ++ , (struct V_28 * ) V_29 ,
V_333 -> V_346 , V_333 -> V_345 ,
V_80 , V_119 ) ;
V_29 += sizeof( struct V_28 ) ;
}
V_45 [ - 1 ] . V_43 |= V_250 ;
V_126 ( V_45 ++ , (struct V_140 * ) V_29 ,
V_333 -> V_346 , 0 , V_339 * V_343 + 1 ,
V_80 , V_289 ,
V_289 -> V_178 -> V_319 ) ;
V_29 += sizeof( struct V_140 ) ;
break;
case 0x04 :
if ( V_344 ) {
F_21 ( V_45 ++ , (struct V_93 * ) V_29 ,
V_333 -> V_346 , V_333 -> V_345 ,
V_75 , V_289 , V_119 ) ;
V_29 += sizeof( struct V_93 ) ;
} else {
F_13 ( V_45 ++ , (struct V_28 * ) V_29 ,
V_333 -> V_346 , V_333 -> V_345 ,
V_75 , V_119 ) ;
V_29 += sizeof( struct V_28 ) ;
}
V_45 [ - 1 ] . V_43 |= V_250 ;
V_126 ( V_45 ++ , (struct V_140 * ) V_29 ,
V_333 -> V_346 , 0 , 1 ,
V_75 , V_289 , 8 ) ;
V_29 += sizeof( struct V_140 ) ;
break;
}
for ( V_340 = 0 ; V_340 < V_343 ; V_340 ++ ) {
F_10 ( & V_338 ,
( V_333 -> V_346 + V_340 ) /
V_334 -> V_35 . V_86 ,
( V_333 -> V_346 + V_340 ) %
V_334 -> V_35 . V_86 ) ;
if ( V_341 & 0x01 ) {
V_337 = (struct V_302 * ) V_29 ;
V_29 += sizeof( struct V_302 ) ;
V_337 -> V_23 = V_338 . V_23 ;
V_337 -> V_24 = V_338 . V_24 ;
V_337 -> V_117 = 0 ;
V_337 -> V_16 = 0 ;
V_337 -> V_17 = 8 ;
V_45 [ - 1 ] . V_43 |= V_250 ;
V_45 -> V_54 = V_80 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_337 ;
V_45 ++ ;
}
if ( ( V_341 & ~ 0x08 ) & 0x04 ) {
V_337 = (struct V_302 * ) V_29 ;
V_29 += sizeof( struct V_302 ) ;
V_337 -> V_23 = V_338 . V_23 ;
V_337 -> V_24 = V_338 . V_24 ;
V_337 -> V_117 = 1 ;
V_337 -> V_16 = 0 ;
V_337 -> V_17 = 0 ;
V_45 [ - 1 ] . V_43 |= V_250 ;
V_45 -> V_54 = V_75 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_337 ;
} else {
for ( V_199 = 0 ; V_199 < V_339 ; V_199 ++ ) {
V_337 = (struct V_302 * ) V_29 ;
V_29 += sizeof( struct V_302 ) ;
V_337 -> V_23 = V_338 . V_23 ;
V_337 -> V_24 = V_338 . V_24 ;
V_337 -> V_117 = V_199 + 1 ;
V_337 -> V_16 = 0 ;
V_337 -> V_17 = V_333 -> V_121 ;
if ( ( V_341 & 0x08 ) &&
V_333 -> V_346 == 0 ) {
if ( V_199 < 3 ) {
V_337 -> V_16 = 4 ;
V_337 -> V_17 = V_147 [ V_199 ] - 4 ;
}
}
if ( ( V_341 & 0x08 ) &&
V_333 -> V_346 == 1 ) {
V_337 -> V_16 = 44 ;
V_337 -> V_17 = V_148 - 44 ;
}
V_45 [ - 1 ] . V_43 |= V_250 ;
if ( V_199 != 0 || V_340 == 0 )
V_45 -> V_54 =
V_75 ;
else
V_45 -> V_54 =
V_76 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_337 ;
V_45 ++ ;
}
}
}
V_336 -> V_119 = V_119 ;
V_336 -> V_177 = V_119 ;
V_336 -> V_118 = V_289 ;
V_336 -> V_181 = 256 ;
V_336 -> V_179 = V_119 -> V_282 * V_180 ;
V_336 -> V_182 = F_33 () ;
V_336 -> V_183 = V_184 ;
return V_336 ;
}
static int
F_110 ( struct V_30 * V_289 ,
struct V_332 * V_333 ,
int V_252 )
{
struct V_167 * V_168 , * V_347 ;
struct V_274 * V_178 ;
struct V_32 * V_33 ;
struct V_348 V_349 ;
struct V_30 * V_31 ;
int V_350 , V_351 ;
int V_352 , V_34 = 0 , V_353 ;
V_178 = V_289 -> V_178 ;
V_33 = (struct V_32 * ) V_289 -> V_33 ;
if ( V_333 -> V_346 >=
( V_33 -> V_90 * V_33 -> V_35 . V_86 ) ) {
F_55 ( & V_289 -> V_2 -> V_82 ,
L_70 ,
V_333 -> V_346 ) ;
return - V_128 ;
}
if ( V_333 -> V_345 >=
( V_33 -> V_90 * V_33 -> V_35 . V_86 ) ) {
F_55 ( & V_289 -> V_2 -> V_82 ,
L_71 ,
V_333 -> V_345 ) ;
return - V_128 ;
}
if ( V_333 -> V_346 > V_333 -> V_345 ) {
F_55 ( & V_289 -> V_2 -> V_82 ,
L_72 ,
V_333 -> V_346 ) ;
return - V_128 ;
}
if ( F_98 ( V_333 -> V_121 ) != 0 ) {
F_55 ( & V_289 -> V_2 -> V_82 ,
L_73 ,
V_333 -> V_121 ) ;
return - V_128 ;
}
F_111 ( & V_349 ) ;
V_350 = V_333 -> V_345 ;
while ( V_333 -> V_346 <= 1 ) {
V_333 -> V_345 = V_333 -> V_346 ;
V_168 = F_107 ( V_289 , V_333 , V_252 ) ;
F_112 ( & V_168 -> V_354 , & V_349 ) ;
V_333 -> V_345 = V_350 ;
V_333 -> V_346 ++ ;
if ( V_333 -> V_346 > V_333 -> V_345 )
goto V_355;
}
V_356:
V_351 = 255 / F_9 ( & V_33 -> V_35 , 0 ,
V_333 -> V_121 ) ;
while ( V_333 -> V_346 <= V_350 ) {
V_352 = V_333 -> V_345 - V_333 -> V_346 + 1 ;
if ( V_352 > V_351 )
V_333 -> V_345 = V_333 -> V_346 + V_351 - 1 ;
V_168 = F_107 ( V_289 , V_333 , V_252 ) ;
if ( F_44 ( V_168 ) ) {
if ( F_71 ( V_168 ) == - V_197 ) {
V_333 -> V_345 = V_350 ;
goto V_355;
} else
return F_71 ( V_168 ) ;
}
F_112 ( & V_168 -> V_354 , & V_349 ) ;
V_333 -> V_346 = V_333 -> V_345 + 1 ;
V_333 -> V_345 = V_350 ;
}
V_355:
V_353 = F_113 ( & V_349 ) ;
F_114 (cqr, n, &format_queue, blocklist) {
V_31 = V_168 -> V_119 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
if ( V_168 -> V_183 == V_312 )
V_34 = - V_278 ;
F_115 ( & V_168 -> V_354 ) ;
F_46 ( V_168 , V_31 ) ;
V_33 -> V_42 -- ;
}
if ( V_353 )
return V_353 ;
if ( V_333 -> V_346 <= V_333 -> V_345 )
goto V_356;
return V_34 ;
}
static void F_116 ( struct V_167 * V_168 )
{
if ( V_168 -> V_181 < 0 ) {
V_168 -> V_183 = V_312 ;
return;
}
V_168 -> V_183 = V_184 ;
if ( V_168 -> V_178 && ( V_168 -> V_119 != V_168 -> V_178 -> V_289 ) ) {
F_117 ( V_168 ) ;
V_168 -> V_119 = V_168 -> V_178 -> V_289 ;
V_168 -> V_170 = V_168 -> V_178 -> V_289 -> V_214 . V_211 ;
}
}
static T_5
F_118 ( struct V_167 * V_168 )
{
struct V_30 * V_31 = (struct V_30 * ) V_168 -> V_119 ;
struct V_1 * V_2 = V_31 -> V_2 ;
switch ( V_2 -> V_357 . V_84 ) {
case 0x3990 :
case 0x2105 :
case 0x2107 :
case 0x1750 :
return V_358 ;
case 0x9343 :
case 0x3880 :
default:
return V_359 ;
}
}
static T_5
F_119 ( struct V_167 * V_168 )
{
return V_360 ;
}
static void F_120 ( struct V_30 * V_31 ,
struct V_167 * V_168 ,
struct V_313 * V_313 )
{
char V_66 ;
char * V_309 = NULL ;
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_66 = V_361 | V_362 | V_363 ;
if ( ( F_121 ( & V_313 -> V_364 ) & V_66 ) == V_66 ) {
if ( ! V_31 -> V_178 && V_33 -> V_365 &&
V_31 -> V_263 == V_264 &&
! F_59 ( V_262 , & V_31 -> V_43 ) &&
! F_59 ( V_234 , & V_31 -> V_43 ) ) {
F_105 ( V_31 ) ;
F_122 ( V_31 ) ;
}
F_123 ( V_31 ) ;
return;
}
V_309 = F_92 ( V_313 ) ;
if ( ! V_309 )
return;
if ( ( V_309 [ 27 ] & V_366 ) && ( V_309 [ 7 ] == 0x0D ) &&
( F_121 ( & V_313 -> V_364 ) & V_367 ) ) {
F_124 ( V_31 , V_313 ) ;
return;
}
if ( ! V_168 && ! ( V_309 [ 27 ] & V_366 ) &&
( ( V_309 [ 6 ] & V_368 ) == V_368 ) ) {
F_125 ( V_31 , V_309 ) ;
return;
}
if ( V_31 -> V_178 && ( V_309 [ 27 ] & V_366 ) &&
( V_309 [ 7 ] == 0x3F ) &&
( F_121 ( & V_313 -> V_364 ) & V_367 ) &&
F_59 ( V_369 , & V_31 -> V_43 ) ) {
if ( V_31 -> V_245 & V_370 )
F_34 ( V_371 , & V_31 -> V_43 ) ;
F_39 ( V_369 , & V_31 -> V_43 ) ;
F_15 ( & V_31 -> V_2 -> V_82 ,
L_74 ) ;
}
}
static struct V_167 * F_126 (
struct V_30 * V_119 ,
struct V_274 * V_178 ,
struct V_372 * V_373 ,
T_6 V_374 ,
T_6 V_375 ,
T_6 V_376 ,
T_6 V_377 ,
unsigned int V_378 ,
unsigned int V_379 ,
unsigned int V_145 ,
unsigned int V_121 )
{
struct V_32 * V_33 ;
unsigned long * V_380 ;
struct V_140 * V_304 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
struct V_381 V_382 ;
struct V_383 V_384 ;
char * V_385 ;
unsigned int V_386 ;
int V_42 , V_387 , V_305 , V_306 ;
T_6 V_146 ;
unsigned char V_48 , V_388 ;
int V_344 ;
struct V_30 * V_118 ;
V_118 = V_178 -> V_289 ;
V_33 = (struct V_32 * ) V_118 -> V_33 ;
if ( F_127 ( V_373 ) == V_389 )
V_48 = V_60 ;
else if ( F_127 ( V_373 ) == V_390 )
V_48 = V_72 ;
else
return F_109 ( - V_128 ) ;
V_42 = 0 ;
V_387 = 0 ;
F_128 (bv, req, iter) {
if ( V_384 . V_391 & ( V_121 - 1 ) )
return F_109 ( - V_128 ) ;
V_42 += V_384 . V_391 >> ( V_178 -> V_322 + 9 ) ;
if ( F_129 ( F_130 ( V_384 . V_392 ) , V_384 . V_391 ) )
V_387 += V_384 . V_391 >> ( V_178 -> V_322 + 9 ) ;
}
if ( V_42 != V_375 - V_374 + 1 )
return F_109 ( - V_128 ) ;
V_344 = V_33 -> V_245 . V_273 [ 8 ] & 0x01 ;
if ( V_344 ) {
V_305 = 2 + V_42 ;
V_306 = sizeof( struct V_93 ) +
sizeof( struct V_140 ) +
V_387 * sizeof( unsigned long ) ;
} else {
V_305 = 2 + V_42 ;
V_306 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
V_387 * sizeof( unsigned long ) ;
}
if ( V_33 -> V_85 && V_374 < 2 * V_145 ) {
if ( V_375 >= 2 * V_145 )
V_42 = 2 * V_145 - V_374 ;
V_305 += V_42 ;
V_306 += V_42 * sizeof( struct V_140 ) ;
}
V_168 = F_43 ( V_176 , V_305 , V_306 ,
V_119 ) ;
if ( F_44 ( V_168 ) )
return V_168 ;
V_45 = V_168 -> V_171 ;
if ( V_344 ) {
if ( F_21 ( V_45 ++ , V_168 -> V_29 , V_376 ,
V_377 , V_48 , V_118 , V_119 ) == - V_237 ) {
F_46 ( V_168 , V_119 ) ;
return F_109 ( - V_237 ) ;
}
V_380 = ( unsigned long * ) ( V_168 -> V_29 +
sizeof( struct V_93 ) ) ;
} else {
if ( F_13 ( V_45 ++ , V_168 -> V_29 , V_376 ,
V_377 , V_48 , V_118 ) == - V_237 ) {
F_46 ( V_168 , V_119 ) ;
return F_109 ( - V_237 ) ;
}
V_380 = ( unsigned long * ) ( V_168 -> V_29 +
sizeof( struct V_28 ) ) ;
}
V_304 = (struct V_140 * ) ( V_380 + V_387 ) ;
V_146 = V_374 ;
if ( V_33 -> V_85 == 0 || V_146 > 2 * V_145 ) {
V_45 [ - 1 ] . V_43 |= V_250 ;
V_126 ( V_45 ++ , V_304 ++ , V_376 , V_378 + 1 ,
V_375 - V_146 + 1 , V_48 , V_118 , V_121 ) ;
}
F_128 (bv, req, iter) {
V_385 = F_130 ( V_384 . V_392 ) + V_384 . V_393 ;
if ( V_394 ) {
char * V_395 = F_131 ( V_394 ,
V_196 | V_396 ) ;
if ( V_395 && F_127 ( V_373 ) == V_390 )
memcpy ( V_395 + V_384 . V_393 , V_385 , V_384 . V_391 ) ;
if ( V_395 )
V_385 = V_395 + V_384 . V_393 ;
}
for ( V_386 = 0 ; V_386 < V_384 . V_391 ; V_386 += V_121 ) {
T_6 V_397 = V_146 ;
unsigned int V_398 = F_132 ( V_397 , V_145 ) ;
V_388 = V_48 ;
V_42 = V_121 ;
if ( V_33 -> V_85 && V_146 < 2 * V_145 ) {
if ( F_22 ( V_145 , V_146 ) ) {
V_388 |= 0x8 ;
V_42 = F_23 ( V_146 ) ;
if ( V_42 < V_121 &&
F_127 ( V_373 ) == V_389 )
memset ( V_385 + V_42 , 0xe5 ,
V_121 - V_42 ) ;
}
V_45 [ - 1 ] . V_43 |= V_250 ;
V_126 ( V_45 ++ , V_304 ++ ,
V_397 , V_398 + 1 ,
1 , V_388 , V_118 , V_42 ) ;
}
if ( V_33 -> V_85 && V_146 == 2 * V_145 ) {
V_45 [ - 1 ] . V_43 |= V_250 ;
V_126 ( V_45 ++ , V_304 ++ ,
V_397 , V_398 + 1 ,
V_375 - V_146 + 1 ,
V_48 , V_118 , V_42 ) ;
}
V_45 [ - 1 ] . V_43 |= V_250 ;
V_45 -> V_54 = V_388 ;
V_45 -> V_42 = V_42 ;
if ( F_129 ( V_385 , V_121 ) ) {
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_380 ;
V_45 -> V_43 = V_399 ;
V_380 = F_133 ( V_380 , V_385 , V_121 ) ;
} else {
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_385 ;
V_45 -> V_43 = 0 ;
}
V_45 ++ ;
V_385 += V_121 ;
V_146 ++ ;
}
}
if ( F_134 ( V_373 ) ||
V_178 -> V_289 -> V_245 & V_400 )
F_34 ( V_261 , & V_168 -> V_43 ) ;
V_168 -> V_119 = V_119 ;
V_168 -> V_177 = V_119 ;
V_168 -> V_178 = V_178 ;
V_168 -> V_179 = V_119 -> V_282 * V_180 ;
V_168 -> V_170 = V_119 -> V_214 . V_221 ;
V_168 -> V_181 = V_119 -> V_284 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
return V_168 ;
}
static struct V_167 * F_135 (
struct V_30 * V_119 ,
struct V_274 * V_178 ,
struct V_372 * V_373 ,
T_6 V_374 ,
T_6 V_375 ,
T_6 V_376 ,
T_6 V_377 ,
unsigned int V_378 ,
unsigned int V_379 ,
unsigned int V_145 ,
unsigned int V_121 )
{
unsigned long * V_380 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
struct V_381 V_382 ;
struct V_383 V_384 ;
char * V_385 , * V_401 ;
unsigned int V_387 , V_305 , V_306 ;
unsigned int V_100 ;
T_6 V_146 ;
unsigned char V_48 ;
struct V_30 * V_118 ;
unsigned int V_402 , V_42 , V_403 ;
unsigned int V_404 , V_405 , V_406 , V_407 ;
unsigned char V_408 , V_409 ;
T_6 V_397 ;
unsigned int V_398 ;
V_118 = V_178 -> V_289 ;
if ( F_127 ( V_373 ) == V_389 )
V_48 = V_113 ;
else if ( F_127 ( V_373 ) == V_390 )
V_48 = V_111 ;
else
return F_109 ( - V_128 ) ;
V_387 = V_375 - V_374 + 1 ;
V_402 = V_377 - V_376 + 1 ;
V_305 = 1 + V_402 ;
V_306 = sizeof( struct V_93 ) +
V_387 * sizeof( unsigned long long ) ;
V_168 = F_43 ( V_176 , V_305 , V_306 ,
V_119 ) ;
if ( F_44 ( V_168 ) )
return V_168 ;
V_45 = V_168 -> V_171 ;
if ( V_376 == V_377 )
V_100 = V_379 - V_378 + 1 ;
else
V_100 = V_379 + 1 ;
V_100 *= V_121 ;
if ( F_20 ( V_45 ++ , V_168 -> V_29 , V_376 ,
V_377 , V_48 , V_118 , V_119 ,
1 , V_378 + 1 ,
V_402 , V_121 ,
V_100 ) == - V_237 ) {
F_46 ( V_168 , V_119 ) ;
return F_109 ( - V_237 ) ;
}
V_380 = ( unsigned long * ) ( V_168 -> V_29 + sizeof( struct V_93 ) ) ;
V_146 = V_374 ;
V_408 = 1 ;
V_409 = 0 ;
V_407 = 0 ;
V_401 = NULL ;
V_404 = 0 ;
F_128 (bv, req, iter) {
V_385 = F_130 ( V_384 . V_392 ) + V_384 . V_393 ;
V_405 = V_384 . V_391 ;
while ( V_405 ) {
if ( V_408 ) {
V_397 = V_146 ;
V_398 = F_132 ( V_397 , V_145 ) ;
V_403 = V_145 - V_398 ;
V_42 = F_136 ( ( V_375 - V_146 + 1 ) ,
( T_6 ) V_403 ) ;
V_407 = V_42 * V_121 ;
V_45 [ - 1 ] . V_43 |= V_250 ;
V_45 -> V_54 = V_48 ;
V_45 -> V_42 = V_407 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_380 ;
V_45 -> V_43 = V_399 ;
V_45 ++ ;
V_146 += V_42 ;
V_408 = 0 ;
if ( ! V_401 )
V_401 = V_385 ;
}
if ( ! V_401 ) {
if ( F_14 ( V_385 ) & ( V_410 - 1 ) ) {
F_46 ( V_168 , V_119 ) ;
return F_109 ( - V_411 ) ;
} else
V_401 = V_385 ;
}
if ( ( V_401 + V_404 ) != V_385 ) {
F_46 ( V_168 , V_119 ) ;
return F_109 ( - V_411 ) ;
}
V_406 = F_136 ( V_405 , V_407 ) ;
V_405 -= V_406 ;
V_385 += V_406 ;
V_404 += V_406 ;
V_407 -= V_406 ;
if ( ! ( F_14 ( V_401 + V_404 ) & ( V_410 - 1 ) ) )
V_409 = 1 ;
if ( ! V_407 ) {
V_408 = 1 ;
V_409 = 1 ;
}
if ( V_409 ) {
V_380 = F_133 ( V_380 , V_401 ,
V_404 ) ;
V_401 = NULL ;
V_404 = 0 ;
V_409 = 0 ;
}
}
}
if ( F_134 ( V_373 ) ||
V_178 -> V_289 -> V_245 & V_400 )
F_34 ( V_261 , & V_168 -> V_43 ) ;
V_168 -> V_119 = V_119 ;
V_168 -> V_177 = V_119 ;
V_168 -> V_178 = V_178 ;
V_168 -> V_179 = V_119 -> V_282 * V_180 ;
V_168 -> V_170 = V_119 -> V_214 . V_221 ;
V_168 -> V_181 = V_119 -> V_284 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
return V_168 ;
}
static int F_137 ( struct V_412 * V_412 ,
unsigned int V_46 , unsigned int V_47 , int V_48 ,
struct V_30 * V_118 ,
struct V_30 * V_119 ,
unsigned int V_98 , int V_42 ,
unsigned int V_121 ,
unsigned int V_413 ,
unsigned int V_100 ,
unsigned int V_145 )
{
struct V_93 V_94 ;
struct V_32 * V_122 , * V_123 ;
struct V_28 * V_124 ;
struct V_97 * V_125 ;
struct V_414 * V_414 ;
T_3 V_49 , V_50 ;
T_4 V_51 , V_52 , V_53 ;
T_7 V_415 ;
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
V_125 -> V_104 . V_416 = 0x01 ;
V_415 = V_417 ;
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
V_125 -> V_104 . V_416 = 0x2 ;
V_415 = V_127 ;
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
V_124 -> V_418 = 0x20 ;
V_124 -> V_419 = V_145 ;
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
V_125 -> V_104 . V_420 = 1 ;
V_125 -> V_104 . V_421 = 1 ;
V_125 -> V_106 = V_100 ;
V_125 -> V_422 = V_48 ;
V_125 -> V_42 = V_42 ;
V_125 -> V_101 = V_101 ;
F_10 ( & V_125 -> V_115 , V_49 , V_52 ) ;
V_125 -> V_116 . V_23 = V_125 -> V_115 . V_23 ;
V_125 -> V_116 . V_24 = V_125 -> V_115 . V_24 ;
V_125 -> V_116 . V_117 = V_98 ;
V_414 = F_138 ( V_412 , V_415 , 0 ,
& V_94 , sizeof( V_94 ) , V_413 ) ;
return F_139 ( V_414 ) ;
}
static struct V_167 * F_140 (
struct V_30 * V_119 ,
struct V_274 * V_178 ,
struct V_372 * V_373 ,
T_6 V_374 ,
T_6 V_375 ,
T_6 V_376 ,
T_6 V_377 ,
unsigned int V_378 ,
unsigned int V_379 ,
unsigned int V_145 ,
unsigned int V_121 )
{
struct V_167 * V_168 ;
struct V_381 V_382 ;
struct V_383 V_384 ;
char * V_385 ;
unsigned int V_402 , V_423 ;
unsigned char V_48 ;
struct V_30 * V_118 ;
unsigned int V_100 ;
struct V_412 * V_412 ;
struct V_424 * V_425 = NULL ;
int V_426 ;
T_8 V_427 ;
T_7 V_428 ;
unsigned int V_405 , V_406 , V_407 ;
unsigned char V_408 ;
T_6 V_146 , V_397 ;
unsigned int V_429 ;
unsigned int V_42 , V_403 ;
int V_3 ;
V_118 = V_178 -> V_289 ;
if ( F_127 ( V_373 ) == V_389 ) {
V_48 = V_113 ;
V_426 = V_430 ;
} else if ( F_127 ( V_373 ) == V_390 ) {
V_48 = V_111 ;
V_426 = V_431 ;
} else
return F_109 ( - V_128 ) ;
V_402 = V_377 - V_376 + 1 ;
V_423 = 0 ;
F_128 (bv, req, iter) {
++ V_423 ;
}
if ( F_127 ( V_373 ) == V_390 )
V_423 += ( V_377 - V_376 ) ;
V_427 = F_141 ( 0 , V_423 , 0 ) ;
V_168 = F_43 ( V_176 , 0 , V_427 , V_119 ) ;
if ( F_44 ( V_168 ) )
return V_168 ;
if ( V_376 == V_377 )
V_100 = V_379 - V_378 + 1 ;
else
V_100 = V_379 + 1 ;
V_100 *= V_121 ;
V_412 = F_142 ( V_168 -> V_29 , V_427 , V_426 , 0 , V_423 , 0 ) ;
if ( F_44 ( V_412 ) ) {
V_3 = - V_128 ;
goto V_194;
}
V_168 -> V_171 = F_143 ( V_412 ) ;
if ( F_137 ( V_412 , V_376 , V_377 ,
V_48 , V_118 , V_119 ,
V_378 + 1 ,
V_402 , V_121 ,
( V_375 - V_374 + 1 ) * V_121 ,
V_100 , V_145 ) == - V_237 ) {
V_3 = - V_237 ;
goto V_194;
}
V_407 = 0 ;
if ( F_127 ( V_373 ) == V_390 ) {
V_408 = 1 ;
V_146 = V_374 ;
F_128 (bv, req, iter) {
V_385 = F_130 ( V_384 . V_392 ) + V_384 . V_393 ;
V_405 = V_384 . V_391 ;
while ( V_405 ) {
if ( V_408 ) {
V_397 = V_146 ;
V_429 = F_132 ( V_397 , V_145 ) ;
V_403 = V_145 - V_429 ;
V_42 = F_136 ( ( V_375 - V_146 + 1 ) ,
( T_6 ) V_403 ) ;
V_407 = V_42 * V_121 ;
V_146 += V_42 ;
V_408 = 0 ;
}
V_406 = F_136 ( V_405 , V_407 ) ;
V_405 -= V_406 ;
V_407 -= V_406 ;
if ( ! V_407 ) {
V_408 = 1 ;
V_428 = V_432 ;
} else
V_428 = 0 ;
V_425 = F_144 ( V_412 , V_428 ,
V_385 , V_406 ) ;
if ( F_44 ( V_425 ) ) {
V_3 = - V_128 ;
goto V_194;
}
V_385 += V_406 ;
}
}
} else {
F_128 (bv, req, iter) {
V_385 = F_130 ( V_384 . V_392 ) + V_384 . V_393 ;
V_425 = F_144 ( V_412 , 0x00 ,
V_385 , V_384 . V_391 ) ;
if ( F_44 ( V_425 ) ) {
V_3 = - V_128 ;
goto V_194;
}
}
}
V_425 -> V_43 |= V_433 ;
V_425 -> V_43 &= ~ V_432 ;
F_145 ( V_412 ) ;
if ( F_134 ( V_373 ) ||
V_178 -> V_289 -> V_245 & V_400 )
F_34 ( V_261 , & V_168 -> V_43 ) ;
V_168 -> V_434 = 1 ;
V_168 -> V_119 = V_119 ;
V_168 -> V_177 = V_119 ;
V_168 -> V_178 = V_178 ;
V_168 -> V_179 = V_119 -> V_282 * V_180 ;
V_168 -> V_170 = V_119 -> V_214 . V_221 ;
V_168 -> V_181 = V_119 -> V_284 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
return V_168 ;
V_194:
F_46 ( V_168 , V_119 ) ;
return F_109 ( V_3 ) ;
}
static struct V_167 * F_146 ( struct V_30 * V_119 ,
struct V_274 * V_178 ,
struct V_372 * V_373 )
{
int V_435 , V_436 ;
int V_344 ;
int V_437 ;
struct V_32 * V_33 ;
struct V_30 * V_118 ;
T_6 V_374 , V_375 ;
T_6 V_376 , V_377 ;
unsigned int V_378 , V_379 ;
unsigned int V_145 , V_121 ;
int V_438 ;
unsigned int V_439 ;
struct V_167 * V_168 ;
V_118 = V_178 -> V_289 ;
V_33 = (struct V_32 * ) V_118 -> V_33 ;
V_121 = V_178 -> V_319 ;
V_145 = F_9 ( & V_33 -> V_35 , 0 , V_121 ) ;
if ( V_145 == 0 )
return F_109 ( - V_128 ) ;
V_374 = V_376 = F_147 ( V_373 ) >> V_178 -> V_322 ;
V_378 = F_132 ( V_376 , V_145 ) ;
V_375 = V_377 =
( F_147 ( V_373 ) + F_148 ( V_373 ) - 1 ) >> V_178 -> V_322 ;
V_379 = F_132 ( V_377 , V_145 ) ;
V_438 = ( V_33 -> V_85 && V_374 < 2 * V_145 ) ;
V_437 = V_33 -> V_245 . V_273 [ 40 ] & 0x20 ;
V_439 = F_149 ( V_373 ) ;
if ( V_439 % V_121 )
return F_109 ( - V_128 ) ;
if ( F_127 ( V_373 ) == V_390 )
V_439 += ( V_377 - V_376 ) * 4 ;
V_435 = V_33 -> V_245 . V_273 [ 9 ] & 0x20 ;
V_436 = V_33 -> V_245 . V_273 [ 12 ] & 0x40 ;
V_344 = V_33 -> V_245 . V_273 [ 8 ] & 0x01 ;
V_168 = NULL ;
if ( V_438 || V_394 ) {
} else if ( ( V_439 <= V_33 -> V_225 )
&& ( V_437 || ( V_376 == V_377 ) ) ) {
V_168 = F_140 ( V_119 , V_178 , V_373 ,
V_374 , V_375 ,
V_376 , V_377 ,
V_378 , V_379 ,
V_145 , V_121 ) ;
if ( F_44 ( V_168 ) && ( F_71 ( V_168 ) != - V_237 ) &&
( F_71 ( V_168 ) != - V_197 ) )
V_168 = NULL ;
} else if ( V_344 &&
( ( ( F_127 ( V_373 ) == V_389 ) && V_435 ) ||
( ( F_127 ( V_373 ) == V_390 ) && V_436 ) ) ) {
V_168 = F_135 ( V_119 , V_178 , V_373 ,
V_374 , V_375 ,
V_376 , V_377 ,
V_378 , V_379 ,
V_145 , V_121 ) ;
if ( F_44 ( V_168 ) && ( F_71 ( V_168 ) != - V_237 ) &&
( F_71 ( V_168 ) != - V_197 ) )
V_168 = NULL ;
}
if ( ! V_168 )
V_168 = F_126 ( V_119 , V_178 , V_373 ,
V_374 , V_375 ,
V_376 , V_377 ,
V_378 , V_379 ,
V_145 , V_121 ) ;
return V_168 ;
}
static struct V_167 * F_150 ( struct V_30 * V_119 ,
struct V_274 * V_178 ,
struct V_372 * V_373 )
{
unsigned long * V_380 ;
struct V_30 * V_118 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
struct V_381 V_382 ;
struct V_383 V_384 ;
char * V_385 ;
unsigned char V_48 ;
unsigned int V_402 ;
unsigned int V_405 , V_407 ;
unsigned int V_378 ;
unsigned int V_387 , V_305 , V_306 ;
T_6 V_376 , V_377 , V_330 ;
T_6 V_440 , V_441 , V_442 ;
unsigned int V_443 ;
V_440 = F_147 ( V_373 ) % V_444 ;
V_441 = ( F_147 ( V_373 ) + F_148 ( V_373 ) ) %
V_444 ;
V_442 = ( V_444 - V_441 ) %
V_444 ;
V_118 = V_178 -> V_289 ;
if ( ( V_440 || V_442 ) &&
( F_127 ( V_373 ) == V_390 ) ) {
F_18 ( V_114 , V_118 ,
L_76 ,
V_440 , V_442 , V_373 ) ;
V_168 = F_109 ( - V_128 ) ;
goto V_445;
}
V_376 = F_147 ( V_373 ) / V_444 ;
V_377 = ( F_147 ( V_373 ) + F_148 ( V_373 ) - 1 ) /
V_444 ;
V_402 = V_377 - V_376 + 1 ;
V_378 = 0 ;
if ( F_127 ( V_373 ) == V_389 )
V_48 = V_112 ;
else if ( F_127 ( V_373 ) == V_390 )
V_48 = V_107 ;
else {
V_168 = F_109 ( - V_128 ) ;
goto V_445;
}
V_387 = V_402 * V_321 ;
V_305 = 1 + V_402 ;
V_443 = sizeof( struct V_93 ) + 8 ;
V_306 = V_443 + V_387 * sizeof( unsigned long long ) ;
V_168 = F_43 ( V_176 , V_305 ,
V_306 , V_119 ) ;
if ( F_44 ( V_168 ) )
goto V_445;
V_45 = V_168 -> V_171 ;
if ( F_20 ( V_45 ++ , V_168 -> V_29 , V_376 , V_377 , V_48 ,
V_118 , V_119 , 1 , V_378 + 1 ,
V_402 , 0 , 0 ) == - V_237 ) {
F_46 ( V_168 , V_119 ) ;
V_168 = F_109 ( - V_237 ) ;
goto V_445;
}
V_380 = ( unsigned long * ) ( V_168 -> V_29 + V_443 ) ;
V_407 = 0 ;
if ( V_440 ) {
V_45 [ - 1 ] . V_43 |= V_250 ;
V_45 -> V_54 = V_48 ;
V_45 -> V_42 = 57326 ;
V_407 = 65536 - V_440 * 512 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_380 ;
V_45 -> V_43 |= V_399 ;
V_45 -> V_43 |= V_44 ;
V_45 ++ ;
for ( V_330 = 0 ; V_330 < V_440 ; V_330 += 8 )
V_380 = F_133 ( V_380 , V_446 , V_447 ) ;
}
F_128 (bv, req, iter) {
V_385 = F_130 ( V_384 . V_392 ) + V_384 . V_393 ;
V_405 = V_384 . V_391 ;
if ( V_48 == V_112 )
memset ( V_385 , 0 , V_405 ) ;
if ( ! V_407 ) {
V_45 [ - 1 ] . V_43 |= V_250 ;
V_45 -> V_54 = V_48 ;
V_45 -> V_42 = 57326 ;
V_407 = 65536 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_380 ;
V_45 -> V_43 |= V_399 ;
V_45 -> V_43 |= V_44 ;
V_45 ++ ;
}
V_407 -= V_405 ;
V_380 = F_133 ( V_380 , V_385 , V_405 ) ;
}
for ( V_330 = 0 ; V_330 < V_442 ; V_330 += 8 )
V_380 = F_133 ( V_380 , V_446 , V_447 ) ;
if ( F_134 ( V_373 ) ||
V_178 -> V_289 -> V_245 & V_400 )
F_34 ( V_261 , & V_168 -> V_43 ) ;
V_168 -> V_119 = V_119 ;
V_168 -> V_177 = V_119 ;
V_168 -> V_178 = V_178 ;
V_168 -> V_179 = V_119 -> V_282 * V_180 ;
V_168 -> V_170 = V_119 -> V_214 . V_221 ;
V_168 -> V_181 = V_119 -> V_284 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
if ( F_44 ( V_168 ) && F_71 ( V_168 ) != - V_237 )
V_168 = NULL ;
V_445:
return V_168 ;
}
static int
F_151 ( struct V_167 * V_168 , struct V_372 * V_373 )
{
struct V_32 * V_33 ;
struct V_26 * V_45 ;
struct V_381 V_382 ;
struct V_383 V_384 ;
char * V_385 , * V_56 ;
unsigned int V_121 , V_145 , V_386 ;
T_6 V_146 ;
int V_183 ;
if ( ! V_394 )
goto V_445;
V_33 = (struct V_32 * ) V_168 -> V_178 -> V_289 -> V_33 ;
V_121 = V_168 -> V_178 -> V_319 ;
V_145 = F_9 ( & V_33 -> V_35 , 0 , V_121 ) ;
V_146 = F_147 ( V_373 ) >> V_168 -> V_178 -> V_322 ;
V_45 = V_168 -> V_171 ;
V_45 ++ ;
if ( V_33 -> V_85 == 0 || V_146 > 2 * V_145 )
V_45 ++ ;
F_128 (bv, req, iter) {
V_385 = F_130 ( V_384 . V_392 ) + V_384 . V_393 ;
for ( V_386 = 0 ; V_386 < V_384 . V_391 ; V_386 += V_121 ) {
if ( V_33 -> V_85 && V_146 <= 2 * V_145 )
V_45 ++ ;
if ( V_385 ) {
if ( V_45 -> V_43 & V_399 )
V_56 = * ( ( char * * ) ( ( V_173 ) V_45 -> V_56 ) ) ;
else
V_56 = ( char * ) ( ( V_173 ) V_45 -> V_56 ) ;
if ( V_385 != V_56 ) {
if ( F_127 ( V_373 ) == V_389 )
memcpy ( V_385 , V_56 , V_384 . V_391 ) ;
F_152 ( V_394 ,
( void * ) ( ( V_173 ) V_56 & V_448 ) ) ;
}
V_385 = NULL ;
}
V_45 ++ ;
V_146 ++ ;
}
}
V_445:
V_183 = V_168 -> V_183 == V_186 ;
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_183 ;
}
void F_117 ( struct V_167 * V_168 )
{
struct V_26 * V_45 ;
struct V_93 * V_94 ;
struct V_449 * V_449 ;
struct V_450 * V_450 ;
struct V_414 * V_414 ;
if ( V_168 -> V_434 == 1 ) {
V_449 = V_168 -> V_171 ;
V_450 = F_153 ( V_449 ) ;
V_414 = (struct V_414 * ) & V_450 -> V_451 [ 0 ] ;
V_94 = (struct V_93 * ) & V_414 -> V_452 [ 0 ] ;
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
static struct V_167 * F_154 ( struct V_30 * V_289 ,
struct V_274 * V_178 ,
struct V_372 * V_373 )
{
struct V_32 * V_33 ;
struct V_30 * V_119 ;
unsigned long V_43 ;
struct V_167 * V_168 ;
V_119 = F_108 ( V_289 ) ;
if ( ! V_119 )
V_119 = V_289 ;
V_33 = (struct V_32 * ) V_119 -> V_33 ;
if ( V_33 -> V_42 >= V_453 )
return F_109 ( - V_454 ) ;
F_27 ( F_28 ( V_119 -> V_2 ) , V_43 ) ;
V_33 -> V_42 ++ ;
if ( ( V_289 -> V_245 & V_292 ) )
V_168 = F_150 ( V_119 , V_178 , V_373 ) ;
else
V_168 = F_146 ( V_119 , V_178 , V_373 ) ;
if ( F_44 ( V_168 ) )
V_33 -> V_42 -- ;
F_29 ( F_28 ( V_119 -> V_2 ) , V_43 ) ;
return V_168 ;
}
static int F_155 ( struct V_167 * V_168 ,
struct V_372 * V_373 )
{
struct V_32 * V_33 ;
unsigned long V_43 ;
F_27 ( F_28 ( V_168 -> V_177 -> V_2 ) , V_43 ) ;
V_33 = (struct V_32 * ) V_168 -> V_177 -> V_33 ;
V_33 -> V_42 -- ;
F_29 ( F_28 ( V_168 -> V_177 -> V_2 ) , V_43 ) ;
return F_151 ( V_168 , V_373 ) ;
}
static int
F_156 ( struct V_30 * V_31 ,
struct V_455 * V_456 )
{
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_456 -> V_457 = 2 ;
V_456 -> V_458 = V_33 -> V_85 ? 0 : 1 ;
V_456 -> V_120 = V_33 -> V_85 ? V_459 : V_460 ;
V_456 -> V_461 = sizeof( struct V_14 ) ;
memcpy ( V_456 -> V_462 , & V_33 -> V_35 ,
sizeof( struct V_14 ) ) ;
V_456 -> V_463 = F_136 ( ( unsigned long ) V_33 -> V_200 ,
sizeof( V_456 -> V_464 ) ) ;
memcpy ( V_456 -> V_464 , V_33 -> V_201 ,
V_456 -> V_463 ) ;
return 0 ;
}
static int
F_157 ( struct V_30 * V_31 )
{
struct V_167 * V_168 ;
int V_34 ;
struct V_26 * V_45 ;
int V_465 ;
if ( ! F_158 ( V_466 ) )
return - V_41 ;
V_465 = 0 ;
V_168 = F_43 ( V_176 , 1 , 32 , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_159 ( & V_467 ) ;
V_465 = 1 ;
V_168 = & V_468 -> V_168 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
memset ( & V_468 -> V_45 , 0 ,
sizeof( V_468 -> V_45 ) ) ;
V_168 -> V_171 = & V_468 -> V_45 ;
V_168 -> V_29 = & V_468 -> V_29 ;
V_168 -> V_175 = V_176 ;
}
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_469 ;
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
F_39 ( V_369 , & V_31 -> V_43 ) ;
if ( V_465 )
F_64 ( & V_467 ) ;
else
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int
F_160 ( struct V_30 * V_31 )
{
struct V_167 * V_168 ;
int V_34 ;
struct V_26 * V_45 ;
int V_465 ;
if ( ! F_158 ( V_466 ) )
return - V_41 ;
V_465 = 0 ;
V_168 = F_43 ( V_176 , 1 , 32 , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_159 ( & V_467 ) ;
V_465 = 1 ;
V_168 = & V_468 -> V_168 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
memset ( & V_468 -> V_45 , 0 ,
sizeof( V_468 -> V_45 ) ) ;
V_168 -> V_171 = & V_468 -> V_45 ;
V_168 -> V_29 = & V_468 -> V_29 ;
V_168 -> V_175 = V_176 ;
}
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_470 ;
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
F_34 ( V_369 , & V_31 -> V_43 ) ;
if ( V_465 )
F_64 ( & V_467 ) ;
else
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int
F_161 ( struct V_30 * V_31 )
{
struct V_167 * V_168 ;
int V_34 ;
struct V_26 * V_45 ;
int V_465 ;
if ( ! F_158 ( V_466 ) )
return - V_41 ;
V_465 = 0 ;
V_168 = F_43 ( V_176 , 1 , 32 , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_159 ( & V_467 ) ;
V_465 = 1 ;
V_168 = & V_468 -> V_168 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
memset ( & V_468 -> V_45 , 0 ,
sizeof( V_468 -> V_45 ) ) ;
V_168 -> V_171 = & V_468 -> V_45 ;
V_168 -> V_29 = & V_468 -> V_29 ;
V_168 -> V_175 = V_176 ;
}
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_471 ;
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
F_34 ( V_369 , & V_31 -> V_43 ) ;
if ( V_465 )
F_64 ( & V_467 ) ;
else
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int F_162 ( struct V_30 * V_31 ,
void T_9 * V_472 )
{
struct V_167 * V_168 ;
int V_34 ;
struct V_26 * V_45 ;
int V_465 ;
struct V_473 V_474 ;
if ( ! F_158 ( V_466 ) )
return - V_41 ;
if ( F_163 ( & V_474 , V_472 , sizeof( V_474 ) ) )
return - V_475 ;
V_465 = 0 ;
V_168 = F_43 ( V_176 , 1 ,
sizeof( struct V_476 ) , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_159 ( & V_467 ) ;
V_465 = 1 ;
V_168 = & V_468 -> V_168 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
memset ( & V_468 -> V_45 , 0 ,
sizeof( V_468 -> V_45 ) ) ;
V_168 -> V_171 = & V_468 -> V_45 ;
V_168 -> V_29 = & V_468 -> V_29 ;
V_168 -> V_175 = V_176 ;
}
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_477 ;
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
V_168 -> V_170 = V_474 . V_478 ;
V_34 = F_40 ( V_168 ) ;
if ( ! V_34 && V_474 . V_478 && ( V_168 -> V_170 != V_474 . V_478 ) )
V_34 = - V_278 ;
if ( ! V_34 ) {
V_474 . V_29 = * ( (struct V_476 * ) V_168 -> V_29 ) ;
if ( F_164 ( V_472 , & V_474 , sizeof( V_474 ) ) )
V_34 = - V_475 ;
}
if ( V_465 )
F_64 ( & V_467 ) ;
else
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int
F_165 ( struct V_30 * V_31 , void T_9 * V_472 )
{
struct V_242 * V_243 ;
struct V_479 * V_480 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
int V_34 ;
V_168 = F_43 ( V_176 , 1 + 1 ,
( sizeof( struct V_242 ) +
sizeof( struct V_479 ) ) ,
V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_18 ( V_7 , V_31 , L_1 ,
L_77 ) ;
return F_71 ( V_168 ) ;
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
V_243 -> V_481 [ 1 ] = 0x01 ;
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_249 ;
V_45 -> V_42 = sizeof( struct V_242 ) ;
V_45 -> V_43 |= V_250 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_243 ;
V_480 = (struct V_479 * ) ( V_243 + 1 ) ;
memset ( V_480 , 0 , sizeof( struct V_479 ) ) ;
V_45 ++ ;
V_45 -> V_54 = V_251 ;
V_45 -> V_42 = sizeof( struct V_479 ) ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_480 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_45 ( V_168 ) ;
if ( V_34 == 0 ) {
V_243 = (struct V_242 * ) V_168 -> V_29 ;
V_480 = (struct V_479 * ) ( V_243 + 1 ) ;
if ( F_164 ( V_472 , V_480 ,
sizeof( struct V_479 ) ) )
V_34 = - V_475 ;
}
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int
F_166 ( struct V_30 * V_31 , void T_9 * V_472 )
{
struct V_32 * V_33 =
(struct V_32 * ) V_31 -> V_33 ;
struct V_482 V_70 = V_33 -> V_70 ;
int V_34 ;
if ( ! F_158 ( V_466 ) )
return - V_41 ;
if ( ! V_472 )
return - V_128 ;
V_34 = 0 ;
if ( F_164 ( V_472 , ( long * ) & V_70 ,
sizeof( struct V_482 ) ) )
V_34 = - V_475 ;
return V_34 ;
}
static int
F_167 ( struct V_30 * V_31 , void T_9 * V_472 )
{
struct V_32 * V_33 =
(struct V_32 * ) V_31 -> V_33 ;
struct V_482 V_70 ;
if ( ! F_158 ( V_466 ) )
return - V_41 ;
if ( ! V_472 )
return - V_128 ;
if ( F_163 ( & V_70 , V_472 , sizeof( struct V_482 ) ) )
return - V_475 ;
V_33 -> V_70 = V_70 ;
F_82 ( & V_31 -> V_2 -> V_82 ,
L_78 ,
V_33 -> V_70 . V_69 , V_33 -> V_70 . V_89 ) ;
return 0 ;
}
static int F_168 ( struct V_30 * V_31 , void T_9 * V_472 )
{
struct V_483 V_474 ;
char * V_484 , * V_485 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
char V_486 , V_487 ;
int V_34 ;
if ( ! F_158 ( V_466 ) && ! F_158 ( V_488 ) )
return - V_41 ;
V_486 = V_487 = 0 ;
V_34 = - V_475 ;
if ( F_163 ( & V_474 , V_472 , sizeof( V_474 ) ) )
goto V_445;
if ( F_169 () ) {
V_34 = - V_128 ;
if ( ( V_474 . V_484 >> 32 ) != 0 )
goto V_445;
if ( ( V_474 . V_485 >> 32 ) != 0 )
goto V_445;
V_474 . V_484 &= 0x7fffffffULL ;
V_474 . V_485 &= 0x7fffffffULL ;
}
V_484 = F_42 ( V_474 . V_489 , V_195 | V_196 ) ;
V_485 = F_42 ( V_474 . V_490 , V_195 | V_196 ) ;
if ( ! V_484 || ! V_485 ) {
V_34 = - V_197 ;
goto V_491;
}
V_34 = - V_475 ;
if ( F_163 ( V_484 ,
( void T_9 * ) ( unsigned long ) V_474 . V_484 ,
V_474 . V_489 ) )
goto V_491;
V_486 = V_484 [ 0 ] ;
V_487 = V_484 [ 1 ] ;
V_168 = F_43 ( V_176 , 2 , 0 , V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_18 ( V_7 , V_31 , L_1 ,
L_77 ) ;
V_34 = F_71 ( V_168 ) ;
goto V_491;
}
V_168 -> V_119 = V_31 ;
V_168 -> V_177 = V_31 ;
V_168 -> V_181 = 3 ;
V_168 -> V_179 = 10 * V_180 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_249 ;
V_45 -> V_42 = V_474 . V_489 ;
V_45 -> V_43 |= V_250 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_484 ;
V_45 ++ ;
V_45 -> V_54 = V_251 ;
V_45 -> V_42 = V_474 . V_490 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_485 ;
V_34 = F_45 ( V_168 ) ;
if ( V_34 )
goto V_492;
V_34 = - V_475 ;
if ( F_164 ( ( void T_9 * ) ( unsigned long ) V_474 . V_485 ,
V_485 , V_474 . V_490 ) )
goto V_492;
V_34 = 0 ;
V_492:
F_46 ( V_168 , V_168 -> V_177 ) ;
V_491:
F_47 ( V_485 ) ;
F_47 ( V_484 ) ;
V_445:
F_18 ( V_7 , V_31 ,
L_79 ,
( int ) V_486 , ( int ) V_487 , V_34 ) ;
return V_34 ;
}
static int
F_170 ( struct V_274 * V_178 , unsigned int V_48 , void T_9 * V_472 )
{
struct V_30 * V_31 = V_178 -> V_289 ;
switch ( V_48 ) {
case V_493 :
return F_166 ( V_31 , V_472 ) ;
case V_494 :
return F_167 ( V_31 , V_472 ) ;
case V_495 :
return F_165 ( V_31 , V_472 ) ;
case V_496 :
return F_157 ( V_31 ) ;
case V_497 :
return F_160 ( V_31 ) ;
case V_498 :
return F_161 ( V_31 ) ;
case V_499 :
return F_162 ( V_31 , V_472 ) ;
case V_500 :
return F_168 ( V_31 , V_472 ) ;
default:
return - V_501 ;
}
}
static int
F_171 ( struct V_26 * V_502 , struct V_26 * V_503 , char * V_504 )
{
int V_505 , V_42 ;
char * V_506 ;
V_505 = 0 ;
while ( V_502 <= V_503 ) {
V_505 += sprintf ( V_504 + V_505 , V_507
L_80 ,
V_502 , ( ( int * ) V_502 ) [ 0 ] , ( ( int * ) V_502 ) [ 1 ] ) ;
if ( V_502 -> V_43 & V_399 )
V_506 = ( char * ) * ( ( V_173 * ) ( V_173 ) V_502 -> V_56 ) ;
else
V_506 = ( char * ) ( ( V_173 ) V_502 -> V_56 ) ;
for ( V_42 = 0 ; V_42 < V_502 -> V_42 && V_42 < 32 ; V_42 ++ ) {
if ( V_42 % 8 == 0 ) V_505 += sprintf ( V_504 + V_505 , L_81 ) ;
if ( V_42 % 4 == 0 ) V_505 += sprintf ( V_504 + V_505 , L_81 ) ;
V_505 += sprintf ( V_504 + V_505 , L_11 , V_506 [ V_42 ] ) ;
}
V_505 += sprintf ( V_504 + V_505 , L_82 ) ;
V_502 ++ ;
}
return V_505 ;
}
static void
F_172 ( struct V_30 * V_31 , struct V_313 * V_313 ,
char * V_508 )
{
T_10 * V_309 ;
T_10 * V_509 ;
V_309 = ( T_10 * ) F_92 ( V_313 ) ;
V_509 = ( T_10 * ) & V_313 -> V_364 ;
if ( V_309 ) {
F_18 ( V_510 , V_31 , L_83
L_84 ,
V_508 , * V_509 , * ( ( T_3 * ) ( V_509 + 1 ) ) ,
V_309 [ 0 ] , V_309 [ 1 ] , V_309 [ 2 ] , V_309 [ 3 ] ) ;
} else {
F_18 ( V_510 , V_31 , L_85 ,
V_508 , * V_509 , * ( ( T_3 * ) ( V_509 + 1 ) ) ,
L_86 ) ;
}
}
static void F_173 ( struct V_30 * V_31 ,
struct V_167 * V_373 , struct V_313 * V_313 )
{
char * V_504 ;
struct V_26 * V_511 , * V_512 , * V_513 , * V_502 , * V_503 ;
int V_505 , V_514 , V_515 ;
V_504 = ( char * ) F_174 ( V_240 ) ;
if ( V_504 == NULL ) {
F_18 ( V_7 , V_31 , L_1 ,
L_87 ) ;
return;
}
V_505 = sprintf ( V_504 , V_507
L_88 ,
F_175 ( & V_31 -> V_2 -> V_82 ) ) ;
V_505 += sprintf ( V_504 + V_505 , V_507
L_89
L_90 ,
V_373 , F_176 ( & V_313 -> V_364 ) , F_177 ( & V_313 -> V_364 ) ,
F_178 ( & V_313 -> V_364 ) , F_179 ( & V_313 -> V_364 ) ,
F_121 ( & V_313 -> V_364 ) , F_180 ( & V_313 -> V_364 ) ,
V_373 ? V_373 -> V_257 : 0 ) ;
V_505 += sprintf ( V_504 + V_505 , V_507
L_91 ,
F_175 ( & V_31 -> V_2 -> V_82 ) ,
( void * ) ( V_173 ) V_313 -> V_364 . V_48 . V_516 ) ;
if ( V_313 -> V_517 . V_518 . V_519 . V_520 ) {
for ( V_514 = 0 ; V_514 < 4 ; V_514 ++ ) {
V_505 += sprintf ( V_504 + V_505 , V_507
L_92 ,
( 8 * V_514 ) , ( ( 8 * V_514 ) + 7 ) ) ;
for ( V_515 = 0 ; V_515 < 8 ; V_515 ++ ) {
V_505 += sprintf ( V_504 + V_505 , L_93 ,
V_313 -> V_521 [ 8 * V_514 + V_515 ] ) ;
}
V_505 += sprintf ( V_504 + V_505 , L_82 ) ;
}
if ( V_313 -> V_521 [ 27 ] & V_366 ) {
sprintf ( V_504 + V_505 , V_507
L_94
L_95 ,
V_313 -> V_521 [ 7 ] >> 4 , V_313 -> V_521 [ 7 ] & 0x0f ,
V_313 -> V_521 [ 1 ] & 0x10 ? L_59 : L_96 ) ;
} else {
sprintf ( V_504 + V_505 , V_507
L_97
L_98 ,
V_313 -> V_521 [ 6 ] & 0x0f , V_313 -> V_521 [ 22 ] >> 4 ) ;
}
} else {
sprintf ( V_504 + V_505 , V_507
L_99 ) ;
}
F_181 ( V_522 L_1 , V_504 ) ;
if ( V_373 ) {
V_511 = V_373 -> V_171 ;
for ( V_512 = V_511 ; V_512 -> V_43 & ( V_250 | V_523 ) ; V_512 ++ ) ;
V_503 = F_136 ( V_511 + 6 , V_512 ) ;
V_505 = sprintf ( V_504 , V_507
L_100 , V_373 ) ;
F_171 ( V_511 , V_503 , V_504 + V_505 ) ;
F_181 ( V_522 L_1 , V_504 ) ;
V_505 = 0 ;
V_502 = ++ V_503 ;
V_513 = (struct V_26 * ) ( V_173 )
V_313 -> V_364 . V_48 . V_516 ;
if ( V_502 < V_513 - 2 ) {
V_502 = V_513 - 2 ;
V_505 += sprintf ( V_504 , V_507 L_101 ) ;
}
V_503 = F_136 ( V_513 + 1 , V_512 ) ;
V_505 += F_171 ( V_502 , V_503 , V_504 + V_505 ) ;
V_502 = F_182 ( V_502 , ++ V_503 ) ;
if ( V_502 < V_512 - 1 ) {
V_502 = V_512 - 1 ;
V_505 += sprintf ( V_504 + V_505 , V_507 L_101 ) ;
}
V_505 += F_171 ( V_502 , V_512 , V_504 + V_505 ) ;
if ( V_505 > 0 )
F_181 ( V_522 L_1 , V_504 ) ;
}
F_183 ( ( unsigned long ) V_504 ) ;
}
static void F_184 ( struct V_30 * V_31 ,
struct V_167 * V_373 , struct V_313 * V_313 )
{
char * V_504 ;
int V_505 , V_514 , V_515 , V_524 ;
struct V_525 * V_525 ;
T_7 * V_309 , * V_526 ;
V_504 = ( char * ) F_174 ( V_240 ) ;
if ( V_504 == NULL ) {
F_18 ( V_7 , V_31 , L_102 ,
L_103 ) ;
return;
}
V_505 = sprintf ( V_504 , V_507
L_88 ,
F_175 ( & V_31 -> V_2 -> V_82 ) ) ;
V_505 += sprintf ( V_504 + V_505 , V_507
L_89
L_104 ,
V_373 , F_176 ( & V_313 -> V_364 ) , F_177 ( & V_313 -> V_364 ) ,
F_178 ( & V_313 -> V_364 ) , F_179 ( & V_313 -> V_364 ) ,
F_121 ( & V_313 -> V_364 ) , F_180 ( & V_313 -> V_364 ) ,
V_313 -> V_364 . V_527 . V_528 , V_313 -> V_364 . V_527 . V_529 ,
V_373 ? V_373 -> V_257 : 0 ) ;
V_505 += sprintf ( V_504 + V_505 , V_507
L_105 ,
F_175 ( & V_31 -> V_2 -> V_82 ) ,
( void * ) ( V_173 ) V_313 -> V_364 . V_527 . V_449 ) ;
V_525 = NULL ;
V_309 = NULL ;
if ( V_313 -> V_364 . V_527 . V_449 && ( V_313 -> V_364 . V_527 . V_528 & 0x01 ) )
V_525 = F_185 (
(struct V_449 * ) ( unsigned long ) V_313 -> V_364 . V_527 . V_449 ) ;
if ( V_525 ) {
V_505 += sprintf ( V_504 + V_505 , V_507
L_106 , V_525 -> V_106 ) ;
V_505 += sprintf ( V_504 + V_505 , V_507
L_107 , V_525 -> V_43 ) ;
V_505 += sprintf ( V_504 + V_505 , V_507
L_108 , V_525 -> V_530 ) ;
V_505 += sprintf ( V_504 + V_505 , V_507
L_109 , V_525 -> V_42 ) ;
V_524 = V_525 -> V_42 - 28 ;
V_505 += sprintf ( V_504 + V_505 , V_507
L_110 , V_524 ) ;
switch ( V_525 -> V_43 & 0x07 ) {
case 1 :
V_505 += sprintf ( V_504 + V_505 , V_507
L_111 ,
V_525 -> V_531 . V_532 . V_533 ) ;
V_505 += sprintf ( V_504 + V_505 , V_507
L_112 ,
V_525 -> V_531 . V_532 . V_534 ) ;
V_505 += sprintf ( V_504 + V_505 , V_507
L_113 ,
V_525 -> V_531 . V_532 . V_535 ) ;
V_505 += sprintf ( V_504 + V_505 , V_507
L_114 ,
V_525 -> V_531 . V_532 . V_536 ) ;
V_505 += sprintf ( V_504 + V_505 , V_507
L_115 ,
V_525 -> V_531 . V_532 . V_537 ) ;
V_309 = V_525 -> V_531 . V_532 . V_309 ;
break;
case 2 :
V_505 += sprintf ( V_504 + V_505 , V_507
L_116 , V_525 -> V_531 . V_538 . V_34 ) ;
for ( V_514 = 0 ; V_514 < 2 ; V_514 ++ ) {
V_505 += sprintf ( V_504 + V_505 , V_507
L_117 ,
( 8 * V_514 ) , ( ( 8 * V_514 ) + 7 ) ) ;
V_526 = V_525 -> V_531 . V_538 . V_526 ;
for ( V_515 = 0 ; V_515 < 8 ; V_515 ++ ) {
V_505 += sprintf ( V_504 + V_505 , L_93 ,
V_526 [ 8 * V_514 + V_515 ] ) ;
}
V_505 += sprintf ( V_504 + V_505 , L_82 ) ;
}
V_309 = V_525 -> V_531 . V_538 . V_309 ;
break;
case 3 :
V_505 += sprintf ( V_504 + V_505 , V_507
L_118 ) ;
break;
}
if ( V_309 ) {
for ( V_514 = 0 ; V_514 < 4 ; V_514 ++ ) {
V_505 += sprintf ( V_504 + V_505 , V_507
L_92 ,
( 8 * V_514 ) , ( ( 8 * V_514 ) + 7 ) ) ;
for ( V_515 = 0 ; V_515 < 8 ; V_515 ++ ) {
V_505 += sprintf ( V_504 + V_505 , L_93 ,
V_309 [ 8 * V_514 + V_515 ] ) ;
}
V_505 += sprintf ( V_504 + V_505 , L_82 ) ;
}
if ( V_309 [ 27 ] & V_366 ) {
sprintf ( V_504 + V_505 , V_507
L_94
L_95 ,
V_309 [ 7 ] >> 4 , V_309 [ 7 ] & 0x0f ,
V_309 [ 1 ] & 0x10 ? L_59 : L_96 ) ;
} else {
sprintf ( V_504 + V_505 , V_507
L_97
L_98 ,
V_309 [ 6 ] & 0x0f , V_309 [ 22 ] >> 4 ) ;
}
} else {
sprintf ( V_504 + V_505 , V_507
L_99 ) ;
}
} else {
sprintf ( V_504 + V_505 , V_507
L_119 ) ;
}
F_181 ( V_522 L_1 , V_504 ) ;
F_183 ( ( unsigned long ) V_504 ) ;
}
static void F_186 ( struct V_30 * V_31 ,
struct V_167 * V_373 , struct V_313 * V_313 )
{
if ( F_187 ( & V_313 -> V_364 ) )
F_184 ( V_31 , V_373 , V_313 ) ;
else
F_173 ( V_31 , V_373 , V_313 ) ;
}
static int F_188 ( struct V_30 * V_31 )
{
F_105 ( V_31 ) ;
F_87 ( V_31 ) ;
return 0 ;
}
static int F_189 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
struct V_14 V_539 ;
int V_34 ;
struct V_149 V_275 ;
unsigned long V_43 ;
unsigned long V_540 = 0 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
F_50 ( V_31 ) ;
F_30 ( V_31 , & V_275 ) ;
V_34 = F_26 ( V_31 ) ;
F_27 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
if ( memcmp ( & V_33 -> V_134 , & V_275 , sizeof( struct V_149 ) ) != 0 )
F_15 ( & V_31 -> V_2 -> V_82 , L_120
L_121 ) ;
F_29 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
if ( V_34 )
goto V_541;
V_34 = F_84 ( V_31 ) ;
if ( V_34 )
return V_34 ;
F_34 ( V_261 , & V_540 ) ;
F_75 ( V_31 , V_540 ) ;
F_50 ( V_31 ) ;
F_70 ( V_31 ) ;
V_34 = F_85 ( V_31 , V_176 ,
& V_539 , 64 ) ;
if ( V_34 ) {
F_3 ( V_7 , V_31 -> V_2 ,
L_53 , V_34 ) ;
goto V_541;
}
F_27 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
memcpy ( & V_33 -> V_35 , & V_539 , sizeof( V_539 ) ) ;
F_29 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
F_101 ( V_31 ) ;
return 0 ;
V_541:
return - 1 ;
}
static int F_190 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
int V_34 , V_542 ;
char V_232 [ 60 ] ;
struct V_149 V_134 ;
unsigned long V_43 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
F_27 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
V_542 = V_33 -> V_134 . V_161 ;
F_29 ( F_28 ( V_31 -> V_2 ) , V_43 ) ;
V_34 = F_50 ( V_31 ) ;
if ( V_34 )
goto V_541;
V_34 = F_26 ( V_31 ) ;
if ( V_34 )
goto V_541;
F_191 ( V_31 ) ;
F_30 ( V_31 , & V_134 ) ;
if ( V_542 != V_134 . V_161 ) {
if ( strlen ( V_134 . V_163 ) > 0 )
snprintf ( V_232 , sizeof( V_232 ) ,
L_17 , V_134 . V_150 , V_134 . V_152 ,
V_134 . V_154 , V_134 . V_161 , V_134 . V_163 ) ;
else
snprintf ( V_232 , sizeof( V_232 ) ,
L_18 , V_134 . V_150 , V_134 . V_152 ,
V_134 . V_154 , V_134 . V_161 ) ;
F_82 ( & V_31 -> V_2 -> V_82 ,
L_122
L_123 , V_232 ) ;
}
return 0 ;
V_541:
return - 1 ;
}
static int F_192 ( struct V_30 * V_31 ,
struct V_543 * V_544 ,
T_2 V_545 )
{
struct V_543 * V_546 ;
struct V_242 * V_243 ;
struct V_32 * V_33 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
int V_34 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_168 = F_43 ( V_176 , 1 + 1 ,
( sizeof( struct V_242 ) +
sizeof( struct V_543 ) ) ,
V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_124 ) ;
return F_71 ( V_168 ) ;
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
V_546 = (struct V_543 * ) ( V_243 + 1 ) ;
memset ( V_546 , 0 , sizeof( struct V_543 ) ) ;
V_45 ++ ;
V_45 -> V_54 = V_251 ;
V_45 -> V_42 = sizeof( struct V_543 ) ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_546 ;
V_168 -> V_182 = F_33 () ;
V_168 -> V_183 = V_184 ;
V_34 = F_40 ( V_168 ) ;
if ( V_34 == 0 ) {
V_243 = (struct V_242 * ) V_168 -> V_29 ;
V_546 = (struct V_543 * )
( V_243 + 1 ) ;
memcpy ( V_544 , V_546 ,
sizeof( struct V_543 ) ) ;
} else
F_3 ( V_7 , V_31 -> V_2 ,
L_125
, V_34 ) ;
F_46 ( V_168 , V_168 -> V_177 ) ;
return V_34 ;
}
static int
F_193 ( struct V_30 * V_31 , int V_547 ,
T_1 V_548 ,
struct V_549 * V_550 ,
struct V_551 V_552 )
{
struct V_553 * V_554 ;
struct V_167 * V_168 ;
struct V_26 * V_45 ;
int V_34 ;
V_168 = F_43 ( V_176 , 1 ,
sizeof( struct V_553 ) ,
V_31 ) ;
if ( F_44 ( V_168 ) ) {
F_18 ( V_7 , V_31 , L_1 ,
L_126 ) ;
return F_71 ( V_168 ) ;
}
V_554 = (struct V_553 * ) V_168 -> V_29 ;
V_554 -> V_246 = V_555 ;
V_554 -> V_556 = V_547 ;
if ( V_550 )
V_554 -> V_557 = V_550 -> V_557 ;
V_554 -> V_548 = V_548 ;
V_554 -> V_558 = V_552 . V_558 ;
V_554 -> V_154 = V_552 . V_154 ;
V_45 = V_168 -> V_171 ;
V_45 -> V_54 = V_249 ;
V_45 -> V_56 = ( T_1 ) ( V_173 ) V_554 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_42 = sizeof( struct V_553 ) ;
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
static struct V_218 * F_194 ( struct V_30 * V_31 ,
T_2 V_545 ,
struct V_559 * V_560 )
{
struct V_32 * V_33 ;
struct V_218 * V_201 ;
int V_561 , V_210 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
if ( V_560 -> V_562 == 0 )
goto V_445;
for ( V_561 = 0x80 , V_210 = 0 ; V_561 ; V_561 >>= 1 , V_210 ++ ) {
V_201 = V_33 -> V_217 [ V_210 ] ;
if ( V_201 -> V_155 . V_562 ==
V_560 -> V_562 )
return V_201 ;
}
V_445:
return V_33 -> V_217 [ 8 - F_52 ( V_545 ) ] ;
}
static int F_195 ( struct V_30 * V_31 , T_2 V_545 ,
struct V_559 * V_560 )
{
struct V_218 * V_563 ;
unsigned long V_564 = 0 , V_66 = 0 ;
struct V_32 * V_33 ;
struct V_218 * V_201 ;
unsigned int V_210 , V_561 ;
char * V_565 , * V_155 ;
char * V_566 , * V_130 ;
int V_567 = 0 ;
if ( ! V_560 -> V_568 ||
! ( V_560 -> V_569 [ 0 ] | V_560 -> V_569 [ 1 ] | V_560 -> V_569 [ 2 ] ) )
return V_545 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_563 = F_194 ( V_31 , V_545 , V_560 ) ;
V_210 = 8 - F_52 ( V_560 -> V_568 ) ;
V_566 = ( char * ) & V_563 -> V_570 [ V_210 ] ;
V_565 = ( char * ) & V_563 -> V_155 ;
V_66 = V_560 -> V_569 [ 2 ] ;
V_66 |= V_560 -> V_569 [ 1 ] << 8 ;
V_66 |= V_560 -> V_569 [ 0 ] << 16 ;
for ( V_561 = 0x80 ; V_561 ; V_561 >>= 1 ) {
V_564 = V_66 ;
V_210 = 8 - F_52 ( V_561 ) ;
V_201 = V_33 -> V_217 [ V_210 ] ;
V_210 = 8 - F_52 ( V_560 -> V_568 ) ;
V_130 = ( char * ) & V_201 -> V_570 [ V_210 ] ;
if ( memcmp ( V_566 , V_130 , sizeof( * V_130 ) ) != 0 )
continue;
V_155 = ( char * ) & V_201 -> V_155 ;
while ( V_564 ) {
V_210 = F_52 ( V_564 ) - 1 ;
if ( memcmp ( & V_565 [ 31 - V_210 ] , & V_155 [ 31 - V_210 ] , 1 )
!= 0 )
break;
F_39 ( V_210 , & V_564 ) ;
}
if ( V_564 )
continue;
V_567 |= V_561 ;
}
return V_567 ;
}
static void F_196 ( struct V_30 * V_31 ,
unsigned long V_571 ,
struct V_551 V_552 , int V_572 )
{
struct V_549 * V_550 ;
int V_210 ;
while ( V_571 ) {
V_210 = F_52 ( V_571 ) - 1 ;
V_550 = F_197 ( V_31 -> V_2 , 7 - V_210 ) ;
if ( V_572 == V_573 )
F_198 ( L_127
L_128 , V_552 . V_558 ,
V_550 ? V_550 -> V_557 : 0 ) ;
else if ( V_572 == V_574 )
F_199 ( L_129
L_130 , V_552 . V_558 ,
V_550 ? V_550 -> V_557 : 0 ) ;
F_47 ( V_550 ) ;
F_39 ( V_210 , & V_571 ) ;
}
}
static int F_200 ( struct V_30 * V_31 , T_2 V_545 ,
struct V_559 * V_560 )
{
unsigned long V_567 ;
V_567 = F_195 ( V_31 , V_545 , V_560 ) ;
if ( ! ( V_31 -> V_214 . V_211 & V_567 ) )
return 0 ;
if ( ! ( V_31 -> V_214 . V_211 & ~ V_567 ) ) {
return - V_128 ;
}
V_31 -> V_214 . V_211 &= ~ V_567 ;
V_31 -> V_214 . V_223 |= V_567 ;
return V_567 ;
}
static int F_201 ( struct V_30 * V_31 , T_2 V_545 ,
struct V_551 V_552 ,
struct V_559 * V_560 )
{
struct V_575 * V_576 , * V_577 ;
struct V_32 * V_33 ;
struct V_30 * V_82 , * V_347 ;
unsigned long V_571 = 0 ;
unsigned long V_43 ;
int V_567 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
F_114 (dev, n, &private->lcu->active_devices,
alias_list) {
F_27 ( F_28 ( V_82 -> V_2 ) , V_43 ) ;
V_567 = F_200 ( V_82 , V_545 , V_560 ) ;
F_29 ( F_28 ( V_82 -> V_2 ) , V_43 ) ;
if ( V_567 < 0 )
goto V_541;
V_571 |= V_567 ;
}
F_114 (dev, n, &private->lcu->inactive_devices,
alias_list) {
F_27 ( F_28 ( V_82 -> V_2 ) , V_43 ) ;
V_567 = F_200 ( V_82 , V_545 , V_560 ) ;
F_29 ( F_28 ( V_82 -> V_2 ) , V_43 ) ;
if ( V_567 < 0 )
goto V_541;
V_571 |= V_567 ;
}
F_114 (pavgroup, tempgroup,
&private->lcu->grouplist, group) {
F_114 (dev, n, &pavgroup->baselist,
alias_list) {
F_27 ( F_28 ( V_82 -> V_2 ) , V_43 ) ;
V_567 = F_200 ( V_82 , V_545 , V_560 ) ;
F_29 (
F_28 ( V_82 -> V_2 ) , V_43 ) ;
if ( V_567 < 0 )
goto V_541;
V_571 |= V_567 ;
}
F_114 (dev, n, &pavgroup->aliaslist,
alias_list) {
F_27 ( F_28 ( V_82 -> V_2 ) , V_43 ) ;
V_567 = F_200 ( V_82 , V_545 , V_560 ) ;
F_29 (
F_28 ( V_82 -> V_2 ) , V_43 ) ;
if ( V_567 < 0 )
goto V_541;
V_571 |= V_567 ;
}
}
F_196 ( V_31 , V_571 , V_552 , V_573 ) ;
return 0 ;
V_541:
return V_567 ;
}
static int F_202 ( struct V_30 * V_31 , T_2 V_545 ,
struct V_551 V_552 ,
struct V_559 * V_560 )
{
struct V_575 * V_576 , * V_577 ;
struct V_32 * V_33 ;
struct V_30 * V_82 , * V_347 ;
unsigned long V_571 = 0 ;
int V_567 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
F_114 (dev, n,
&private->lcu->active_devices,
alias_list) {
V_567 = F_195 ( V_82 , V_545 , V_560 ) ;
V_571 |= V_567 ;
if ( ! ( V_82 -> V_214 . V_211 & V_567 ) ) {
V_82 -> V_214 . V_236 |= V_567 ;
F_203 ( V_82 ) ;
}
}
F_114 (dev, n,
&private->lcu->inactive_devices,
alias_list) {
V_567 = F_195 ( V_82 , V_545 , V_560 ) ;
V_571 |= V_567 ;
if ( ! ( V_82 -> V_214 . V_211 & V_567 ) ) {
V_82 -> V_214 . V_236 |= V_567 ;
F_203 ( V_82 ) ;
}
}
F_114 (pavgroup, tempgroup,
&private->lcu->grouplist,
group) {
F_114 (dev, n,
&pavgroup->baselist,
alias_list) {
V_567 = F_195 ( V_82 , V_545 , V_560 ) ;
V_571 |= V_567 ;
if ( ! ( V_82 -> V_214 . V_211 & V_567 ) ) {
V_82 -> V_214 . V_236 |= V_567 ;
F_203 ( V_82 ) ;
}
}
F_114 (dev, n,
&pavgroup->aliaslist,
alias_list) {
V_567 = F_195 ( V_82 , V_545 , V_560 ) ;
V_571 |= V_567 ;
if ( ! ( V_82 -> V_214 . V_211 & V_567 ) ) {
V_82 -> V_214 . V_236 |= V_567 ;
F_203 ( V_82 ) ;
}
}
}
F_196 ( V_31 , V_571 , V_552 , V_574 ) ;
return 0 ;
}
static void F_204 ( struct V_30 * V_31 , void * V_544 ,
T_2 V_545 )
{
struct V_559 * V_560 = V_544 ;
struct V_549 * V_550 ;
struct V_551 V_552 ;
int V_210 , V_547 ;
F_18 ( V_7 , V_31 ,
L_131 ,
( ( T_10 * ) V_560 ) [ 0 ] , ( ( T_10 * ) V_560 ) [ 1 ] , ( ( T_10 * ) V_560 ) [ 2 ] ,
( ( T_3 * ) V_560 ) [ 3 ] ) ;
F_205 ( V_31 -> V_2 , & V_552 ) ;
V_210 = 8 - F_52 ( V_545 ) ;
V_550 = F_197 ( V_31 -> V_2 , V_210 ) ;
if ( V_560 -> V_578 == V_573 ) {
if ( F_201 ( V_31 , V_545 , V_552 , V_560 ) )
V_547 = V_579 ;
else
V_547 = V_580 ;
} else if ( V_560 -> V_578 == V_574 ) {
F_202 ( V_31 , V_545 , V_552 , V_560 ) ;
V_547 = V_580 ;
} else
V_547 = V_581 ;
F_193 ( V_31 , V_547 ,
V_560 -> V_548 , V_550 , V_552 ) ;
F_18 ( V_7 , V_31 ,
L_132 , V_547 ,
V_560 -> V_548 ) ;
F_47 ( V_550 ) ;
V_31 -> V_582 -> V_583 ( V_31 , V_545 ) ;
}
static void F_206 ( struct V_228 * V_229 )
{
struct V_584 * V_29 ;
struct V_543 * V_544 ;
struct V_30 * V_31 ;
int V_34 ;
V_29 = F_58 ( V_229 , struct V_584 , V_233 ) ;
V_31 = V_29 -> V_31 ;
V_544 = F_42 ( sizeof( * V_544 ) , V_195 ) ;
if ( ! V_544 ) {
F_18 ( V_7 , V_31 , L_1 ,
L_133 ) ;
goto V_445;
}
V_34 = F_192 ( V_31 , V_544 , V_29 -> V_545 ) ;
if ( V_34 )
goto V_445;
if ( V_544 -> V_106 == V_585 &&
V_544 -> V_120 == V_586 )
F_204 ( V_31 , V_544 , V_29 -> V_545 ) ;
V_445:
F_63 ( V_31 ) ;
F_47 ( V_544 ) ;
F_47 ( V_29 ) ;
}
static int F_207 ( struct V_30 * V_31 , T_2 V_545 )
{
struct V_584 * V_29 ;
V_29 = F_42 ( sizeof( * V_29 ) , V_240 ) ;
if ( ! V_29 )
return - V_197 ;
F_68 ( & V_29 -> V_233 , F_206 ) ;
F_69 ( V_31 ) ;
V_29 -> V_31 = V_31 ;
V_29 -> V_545 = V_545 ;
F_60 ( & V_29 -> V_233 ) ;
return 0 ;
}
static int T_11
F_208 ( void )
{
int V_3 ;
F_209 ( V_8 . V_587 , 4 ) ;
V_468 = F_66 ( sizeof( * V_468 ) ,
V_195 | V_196 ) ;
if ( ! V_468 )
return - V_197 ;
V_241 = F_66 ( sizeof( * V_241 ) ,
V_195 | V_196 ) ;
if ( ! V_241 ) {
F_47 ( V_468 ) ;
return - V_197 ;
}
V_446 = ( void * ) F_210 ( V_195 ) ;
if ( ! V_446 ) {
F_47 ( V_241 ) ;
F_47 ( V_468 ) ;
return - V_197 ;
}
V_3 = F_211 ( & V_588 ) ;
if ( ! V_3 )
F_212 () ;
else {
F_47 ( V_241 ) ;
F_47 ( V_468 ) ;
F_183 ( ( unsigned long ) V_446 ) ;
}
return V_3 ;
}
static void T_12
F_213 ( void )
{
F_214 ( & V_588 ) ;
F_47 ( V_241 ) ;
F_47 ( V_468 ) ;
F_183 ( ( unsigned long ) V_446 ) ;
}
