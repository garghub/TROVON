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
static int F_24 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
struct V_149 * V_134 ;
int V_42 ;
unsigned long V_43 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
if ( ! V_33 )
return - V_150 ;
if ( ! V_33 -> V_130 || ! V_33 -> V_151 )
return - V_150 ;
V_134 = & V_33 -> V_134 ;
F_25 ( F_26 ( V_31 -> V_2 ) , V_43 ) ;
memset ( V_134 , 0 , sizeof( struct V_149 ) ) ;
memcpy ( V_134 -> V_152 , V_33 -> V_130 -> V_153 ,
sizeof( V_134 -> V_152 ) - 1 ) ;
F_27 ( V_134 -> V_152 , sizeof( V_134 -> V_152 ) - 1 ) ;
memcpy ( V_134 -> V_154 , V_33 -> V_130 -> V_155 ,
sizeof( V_134 -> V_154 ) - 1 ) ;
F_27 ( V_134 -> V_154 , sizeof( V_134 -> V_154 ) - 1 ) ;
V_134 -> V_156 = V_33 -> V_151 -> V_157 ;
V_134 -> V_158 = V_33 -> V_130 -> V_131 ;
if ( V_33 -> V_159 ) {
V_134 -> type = V_33 -> V_159 -> V_160 ;
if ( V_134 -> type == V_161 )
V_134 -> V_162 = V_33 -> V_159 -> V_162 ;
} else {
V_134 -> type = V_135 ;
}
if ( V_33 -> V_163 ) {
for ( V_42 = 0 ; V_42 < 16 ; V_42 ++ ) {
sprintf ( V_134 -> V_164 + 2 * V_42 , L_11 ,
V_33 -> V_163 -> V_165 [ V_42 ] ) ;
}
}
F_28 ( F_26 ( V_31 -> V_2 ) , V_43 ) ;
return 0 ;
}
static int F_29 ( struct V_30 * V_31 , struct V_149 * V_134 )
{
struct V_32 * V_33 ;
unsigned long V_43 ;
if ( V_31 -> V_33 ) {
V_33 = (struct V_32 * ) V_31 -> V_33 ;
F_25 ( F_26 ( V_31 -> V_2 ) , V_43 ) ;
* V_134 = V_33 -> V_134 ;
F_28 ( F_26 ( V_31 -> V_2 ) , V_43 ) ;
return 0 ;
}
return - V_128 ;
}
static void F_30 ( struct V_30 * V_31 ,
struct V_166 * V_167 ,
T_2 * V_168 ,
T_2 V_169 )
{
struct V_26 * V_45 ;
V_168 [ 0 ] = 0xE5 ;
V_168 [ 1 ] = 0xF1 ;
V_168 [ 2 ] = 0x4B ;
V_168 [ 3 ] = 0xF0 ;
V_45 = V_167 -> V_170 ;
V_45 -> V_54 = V_171 ;
V_45 -> V_43 = 0 ;
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_168 ;
V_45 -> V_42 = V_173 ;
V_167 -> V_174 = V_175 ;
V_167 -> V_119 = V_31 ;
V_167 -> V_176 = V_31 ;
V_167 -> V_177 = NULL ;
V_167 -> V_178 = 10 * V_179 ;
V_167 -> V_169 = V_169 ;
V_167 -> V_180 = 256 ;
V_167 -> V_181 = F_31 () ;
V_167 -> V_182 = V_183 ;
F_32 ( V_184 , & V_167 -> V_43 ) ;
}
static int F_33 ( struct V_30 * V_31 ,
struct V_166 * V_167 ,
T_2 * V_168 ,
T_2 V_169 )
{
struct V_185 * V_185 ;
int V_34 ;
V_185 = F_34 ( V_31 -> V_2 , V_186 ) ;
if ( ! V_185 || V_185 -> V_48 != V_171 )
return - V_187 ;
F_30 ( V_31 , V_167 , V_168 , V_169 ) ;
F_35 ( V_188 , & V_167 -> V_43 ) ;
F_32 ( V_189 , & V_167 -> V_43 ) ;
V_167 -> V_180 = 5 ;
V_34 = F_36 ( V_167 ) ;
return V_34 ;
}
static int F_37 ( struct V_30 * V_31 ,
void * * V_168 ,
int * V_190 , T_2 V_169 )
{
struct V_185 * V_185 ;
char * V_191 = NULL ;
int V_3 ;
struct V_166 * V_167 ;
V_185 = F_34 ( V_31 -> V_2 , V_186 ) ;
if ( ! V_185 || V_185 -> V_48 != V_171 ) {
V_3 = - V_187 ;
goto V_192;
}
V_191 = F_38 ( V_173 , V_193 | V_194 ) ;
if ( ! V_191 ) {
V_3 = - V_195 ;
goto V_192;
}
V_167 = F_39 ( V_175 , 1 ,
0 ,
V_31 ) ;
if ( F_40 ( V_167 ) ) {
F_18 ( V_7 , V_31 , L_1 ,
L_12 ) ;
V_3 = - V_195 ;
goto V_192;
}
F_30 ( V_31 , V_167 , V_191 , V_169 ) ;
V_3 = F_41 ( V_167 ) ;
F_42 ( V_167 , V_167 -> V_176 ) ;
if ( V_3 )
goto V_192;
* V_190 = V_173 ;
* V_168 = V_191 ;
return 0 ;
V_192:
F_43 ( V_191 ) ;
* V_168 = NULL ;
* V_190 = 0 ;
return V_3 ;
}
static int F_44 ( struct V_32 * V_33 )
{
struct V_196 * V_159 ;
int V_197 , V_42 ;
V_33 -> V_130 = NULL ;
V_33 -> V_159 = NULL ;
V_33 -> V_163 = NULL ;
V_33 -> V_151 = NULL ;
V_42 = V_33 -> V_198 / sizeof( struct V_196 ) ;
V_159 = (struct V_196 * ) V_33 -> V_199 ;
for ( V_197 = 0 ; V_197 < V_42 ; ++ V_197 ) {
if ( V_159 -> V_43 . V_200 == 1 && V_159 -> V_120 == 1 )
V_33 -> V_159 = V_159 ;
else if ( V_159 -> V_43 . V_200 == 1 && V_159 -> V_120 == 4 )
V_33 -> V_163 = (struct V_201 * ) V_159 ;
else if ( V_159 -> V_43 . V_200 == 2 )
V_33 -> V_151 = (struct V_202 * ) V_159 ;
else if ( V_159 -> V_43 . V_200 == 3 && V_159 -> V_203 == 1 )
V_33 -> V_130 = (struct V_204 * ) V_159 ;
V_159 ++ ;
}
if ( ! V_33 -> V_130 || ! V_33 -> V_151 ) {
V_33 -> V_130 = NULL ;
V_33 -> V_159 = NULL ;
V_33 -> V_163 = NULL ;
V_33 -> V_151 = NULL ;
return - V_128 ;
}
return 0 ;
}
static unsigned char F_45 ( void * V_199 , int V_198 )
{
struct V_202 * V_151 ;
int V_197 , V_42 , V_205 ;
V_42 = V_198 / sizeof( * V_151 ) ;
V_151 = (struct V_202 * ) V_199 ;
V_205 = 0 ;
for ( V_197 = 0 ; V_197 < V_42 ; ++ V_197 ) {
if ( V_151 -> V_43 . V_200 == 2 ) {
V_205 = 1 ;
break;
}
V_151 ++ ;
}
if ( V_205 )
return ( ( char * ) V_151 ) [ 18 ] & 0x07 ;
else
return 0 ;
}
static int F_46 ( struct V_30 * V_31 )
{
void * V_199 ;
int V_198 , V_206 ;
int V_34 ;
T_2 V_169 , V_207 ;
struct V_32 * V_33 ;
struct V_208 * V_209 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_209 = & V_31 -> V_209 ;
V_207 = F_47 ( V_31 -> V_2 ) ;
V_169 = 0x80 ;
V_206 = 0 ;
for ( V_169 = 0x80 ; V_169 ; V_169 >>= 1 ) {
if ( V_169 & V_207 ) {
V_34 = F_37 ( V_31 , & V_199 ,
& V_198 , V_169 ) ;
if ( V_34 && V_34 != - V_187 ) {
F_3 ( V_7 , V_31 -> V_2 ,
L_13
L_14 , V_34 ) ;
return V_34 ;
}
if ( V_199 == NULL ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_15
L_16 ) ;
V_209 -> V_207 |= V_169 ;
continue;
}
if ( ! V_206 ) {
F_43 ( V_33 -> V_199 ) ;
V_33 -> V_199 = V_199 ;
V_33 -> V_198 = V_198 ;
if ( F_44 ( V_33 ) ) {
V_33 -> V_199 = NULL ;
V_33 -> V_198 = 0 ;
F_43 ( V_199 ) ;
continue;
}
V_206 ++ ;
}
switch ( F_45 ( V_199 , V_198 ) ) {
case 0x02 :
V_209 -> V_210 |= V_169 ;
break;
case 0x03 :
V_209 -> V_211 |= V_169 ;
break;
}
V_209 -> V_207 |= V_169 ;
if ( V_199 != V_33 -> V_199 )
F_43 ( V_199 ) ;
}
}
return 0 ;
}
static int F_48 ( struct V_30 * V_31 , T_2 V_169 )
{
struct V_32 * V_33 ;
int V_212 ;
T_3 V_213 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
if ( V_33 -> V_213 ) {
V_212 = F_49 ( V_31 -> V_2 , V_169 ) ;
if ( ( V_212 < 0 ) ) {
F_50 ( & V_31 -> V_2 -> V_82 ,
L_17
L_18 ,
V_212 , V_169 ) ;
return V_212 ;
}
V_213 = V_212 * V_214 ;
if ( V_213 < V_33 -> V_213 ) {
F_50 ( & V_31 -> V_2 -> V_82 ,
L_19
L_20
L_21 , V_213 , V_169 ,
V_33 -> V_213 ) ;
return - V_41 ;
}
}
return 0 ;
}
static void F_51 ( struct V_215 * V_216 )
{
struct V_217 * V_29 ;
struct V_30 * V_31 ;
T_2 V_169 , V_207 , V_210 , V_211 , V_218 ;
unsigned long V_43 ;
int V_34 ;
V_29 = F_52 ( V_216 , struct V_217 , V_219 ) ;
V_31 = V_29 -> V_31 ;
V_207 = 0 ;
V_210 = 0 ;
V_211 = 0 ;
V_218 = 0 ;
for ( V_169 = 0x80 ; V_169 ; V_169 >>= 1 ) {
if ( V_169 & V_29 -> V_220 ) {
memset ( V_29 -> V_168 , 0 , sizeof( V_29 -> V_168 ) ) ;
memset ( & V_29 -> V_167 , 0 , sizeof( V_29 -> V_167 ) ) ;
V_29 -> V_167 . V_170 = & V_29 -> V_45 ;
V_34 = F_33 ( V_31 , & V_29 -> V_167 ,
V_29 -> V_168 ,
V_169 ) ;
if ( ! V_34 ) {
switch ( F_45 ( V_29 -> V_168 ,
V_173 ) ) {
case 0x02 :
V_210 |= V_169 ;
break;
case 0x03 :
V_211 |= V_169 ;
break;
}
V_207 |= V_169 ;
} else if ( V_34 == - V_187 ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_22
L_23 ) ;
V_207 |= V_169 ;
} else if ( V_34 == - V_221 ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_24
L_25 ) ;
V_218 |= V_169 ;
} else {
F_50 ( & V_31 -> V_2 -> V_82 ,
L_26
L_27 , V_34 , V_169 ) ;
continue;
}
if ( F_48 ( V_31 , V_169 ) ) {
V_207 &= ~ V_169 ;
V_210 &= ~ V_169 ;
V_211 &= ~ V_169 ;
}
}
}
F_25 ( F_26 ( V_31 -> V_2 ) , V_43 ) ;
if ( ! V_31 -> V_209 . V_207 && V_207 ) {
V_31 -> V_209 . V_207 = V_207 ;
F_53 ( V_31 ) ;
} else
V_31 -> V_209 . V_207 |= V_207 ;
V_31 -> V_209 . V_210 |= V_210 ;
V_31 -> V_209 . V_211 |= V_211 ;
V_31 -> V_209 . V_220 |= V_218 ;
F_28 ( F_26 ( V_31 -> V_2 ) , V_43 ) ;
F_54 ( V_31 ) ;
if ( V_29 -> V_222 )
F_55 ( & V_223 ) ;
else
F_43 ( V_29 ) ;
}
static int F_56 ( struct V_30 * V_31 , T_2 V_169 )
{
struct V_217 * V_29 ;
V_29 = F_57 ( sizeof( * V_29 ) , V_224 | V_194 ) ;
if ( ! V_29 ) {
if ( F_58 ( & V_223 ) ) {
V_29 = V_225 ;
V_29 -> V_222 = 1 ;
} else
return - V_195 ;
} else {
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_29 -> V_222 = 0 ;
}
F_59 ( & V_29 -> V_219 , F_51 ) ;
F_60 ( V_31 ) ;
V_29 -> V_31 = V_31 ;
V_29 -> V_220 = V_169 ;
F_61 ( & V_29 -> V_219 ) ;
return 0 ;
}
static int F_62 ( struct V_30 * V_31 )
{
struct V_226 * V_227 ;
struct V_228 * V_229 ;
struct V_166 * V_167 ;
struct V_26 * V_45 ;
int V_34 ;
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
memset ( & V_33 -> V_229 , 0 , sizeof( struct V_228 ) ) ;
V_167 = F_39 ( V_175 , 1 + 1 ,
( sizeof( struct V_226 ) +
sizeof( struct V_228 ) ) ,
V_31 ) ;
if ( F_40 ( V_167 ) ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 , L_28
L_29 ) ;
return F_63 ( V_167 ) ;
}
V_167 -> V_119 = V_31 ;
V_167 -> V_176 = V_31 ;
V_167 -> V_177 = NULL ;
V_167 -> V_180 = 256 ;
V_167 -> V_178 = 10 * V_179 ;
V_227 = (struct V_226 * ) V_167 -> V_29 ;
memset ( V_227 , 0 , sizeof( struct V_226 ) ) ;
V_227 -> V_230 = V_231 ;
V_227 -> V_232 = 0x41 ;
V_45 = V_167 -> V_170 ;
V_45 -> V_54 = V_233 ;
V_45 -> V_42 = sizeof( struct V_226 ) ;
V_45 -> V_43 |= V_234 ;
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_227 ;
V_229 = (struct V_228 * ) ( V_227 + 1 ) ;
memset ( V_229 , 0 , sizeof( struct V_228 ) ) ;
V_45 ++ ;
V_45 -> V_54 = V_235 ;
V_45 -> V_42 = sizeof( struct V_228 ) ;
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_229 ;
V_167 -> V_181 = F_31 () ;
V_167 -> V_182 = V_183 ;
V_34 = F_41 ( V_167 ) ;
if ( V_34 == 0 ) {
V_227 = (struct V_226 * ) V_167 -> V_29 ;
V_229 = (struct V_228 * ) ( V_227 + 1 ) ;
memcpy ( & V_33 -> V_229 , V_229 ,
sizeof( struct V_228 ) ) ;
} else
F_50 ( & V_31 -> V_2 -> V_82 , L_30
L_31 , V_34 ) ;
F_42 ( V_167 , V_167 -> V_176 ) ;
return V_34 ;
}
static struct V_166 * F_64 ( struct V_30 * V_31 ,
int V_236 )
{
struct V_166 * V_167 ;
struct V_237 * V_238 ;
struct V_26 * V_45 ;
V_167 = F_39 ( V_175 , 1 ,
sizeof( struct V_237 ) ,
V_31 ) ;
if ( F_40 ( V_167 ) ) {
F_18 ( V_7 , V_31 , L_1 ,
L_32 ) ;
return V_167 ;
}
V_238 = (struct V_237 * ) V_167 -> V_29 ;
V_238 -> V_230 = V_239 ;
V_238 -> V_232 = 0xc0 ;
if ( V_236 ) {
V_238 -> V_232 |= 0x08 ;
V_238 -> V_240 [ 0 ] = 0x88 ;
}
V_45 = V_167 -> V_170 ;
V_45 -> V_54 = V_233 ;
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_238 ;
V_45 -> V_42 = 66 ;
V_167 -> V_119 = V_31 ;
V_167 -> V_176 = V_31 ;
V_167 -> V_177 = NULL ;
V_167 -> V_180 = 256 ;
V_167 -> V_178 = 10 * V_179 ;
V_167 -> V_181 = F_31 () ;
V_167 -> V_182 = V_183 ;
return V_167 ;
}
static int
F_65 ( struct V_30 * V_31 , int V_236 )
{
struct V_166 * V_167 ;
int V_34 ;
V_167 = F_64 ( V_31 , V_236 ) ;
if ( F_40 ( V_167 ) )
return F_63 ( V_167 ) ;
V_34 = F_41 ( V_167 ) ;
if ( ! V_34 )
F_66 () ;
F_42 ( V_167 , V_167 -> V_176 ) ;
return V_34 ;
}
static void F_67 ( struct V_30 * V_31 )
{
int V_34 ;
struct V_32 * V_33 ;
int V_236 ;
if ( V_241 || V_242 )
V_236 = 0 ;
else
V_236 = 1 ;
V_34 = F_65 ( V_31 , V_236 ) ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
F_3 ( V_7 , V_31 -> V_2 , L_33
L_34 , V_33 -> V_134 . V_156 , V_34 ) ;
}
static T_3 F_68 ( struct V_30 * V_31 )
{
#if F_69 ( V_243 )
int V_244 , V_212 ;
int V_245 , V_246 , V_247 ;
struct V_32 * V_33 ;
if ( V_248 )
return 0 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_245 = V_249 . V_250 ;
V_246 = V_33 -> V_151 -> V_251 [ 7 ] & 0x04 ;
V_247 = V_33 -> V_229 . V_252 [ 40 ] & 0x80 ;
V_244 = V_245 && V_246 && V_247 ;
if ( ! V_244 )
return 0 ;
V_212 = F_49 ( V_31 -> V_2 , 0 ) ;
if ( V_212 < 0 ) {
F_50 ( & V_31 -> V_2 -> V_82 , L_35
L_36 ) ;
return 0 ;
} else
return V_212 * V_214 ;
#else
return 0 ;
#endif
}
static int
F_70 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
struct V_253 * V_177 ;
struct V_149 V_254 ;
int V_255 , V_34 , V_197 ;
int V_256 ;
unsigned long V_257 ;
if ( ! F_71 ( V_31 -> V_2 ) ) {
F_50 ( & V_31 -> V_2 -> V_82 ,
L_37 ) ;
return - V_258 ;
}
if ( ! F_72 ( V_31 -> V_2 ) ) {
F_73 ( & V_31 -> V_2 -> V_82 ,
L_38 ) ;
}
V_33 = (struct V_32 * ) V_31 -> V_33 ;
if ( ! V_33 ) {
V_33 = F_38 ( sizeof( * V_33 ) , V_193 | V_194 ) ;
if ( ! V_33 ) {
F_50 ( & V_31 -> V_2 -> V_82 ,
L_39
L_40 ) ;
return - V_195 ;
}
V_31 -> V_33 = ( void * ) V_33 ;
} else {
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
}
V_33 -> V_259 = - 1 ;
V_33 -> V_70 . V_69 = V_260 ;
V_33 -> V_70 . V_89 = 0 ;
V_34 = F_46 ( V_31 ) ;
if ( V_34 )
goto V_261;
V_31 -> V_262 = V_263 ;
if ( V_33 -> V_151 ) {
V_257 = 1 ;
for ( V_197 = 0 ; V_197 < V_33 -> V_151 -> V_264 . V_257 ; V_197 ++ )
V_257 = 10 * V_257 ;
V_257 = V_257 * V_33 -> V_151 -> V_264 . V_265 ;
if ( V_257 != 0 && V_257 <= V_266 )
V_31 -> V_262 = V_257 ;
}
V_34 = F_24 ( V_31 ) ;
if ( V_34 )
goto V_261;
F_29 ( V_31 , & V_254 ) ;
if ( V_254 . type == V_135 ) {
V_177 = F_74 () ;
if ( F_40 ( V_177 ) ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_41
L_42 ) ;
V_34 = F_63 ( V_177 ) ;
goto V_261;
}
V_31 -> V_177 = V_177 ;
V_177 -> V_267 = V_31 ;
}
V_255 = F_75 ( V_31 ) ;
if ( V_255 < 0 ) {
V_34 = V_255 ;
goto V_268;
}
if ( ! V_255 ) {
F_67 ( V_31 ) ;
F_76 ( V_31 ) ;
} else
F_77 ( V_31 ) ;
V_34 = F_46 ( V_31 ) ;
if ( V_34 )
goto V_269;
F_62 ( V_31 ) ;
V_34 = F_78 ( V_31 , V_175 ,
& V_33 -> V_35 , 64 ) ;
if ( V_34 ) {
F_3 ( V_7 , V_31 -> V_2 ,
L_43 , V_34 ) ;
goto V_269;
}
if ( V_33 -> V_35 . V_270 == V_271 &&
V_33 -> V_35 . V_272 )
V_33 -> V_90 = V_33 -> V_35 . V_272 ;
else
V_33 -> V_90 = V_33 -> V_35 . V_270 ;
V_33 -> V_213 = F_68 ( V_31 ) ;
V_256 = F_79 ( V_31 ) ;
if ( V_256 )
F_32 ( V_273 , & V_31 -> V_43 ) ;
F_73 ( & V_31 -> V_2 -> V_82 , L_44
L_45 ,
V_33 -> V_35 . V_20 ,
V_33 -> V_35 . V_274 ,
V_33 -> V_35 . V_84 ,
V_33 -> V_35 . V_275 . V_276 ,
V_33 -> V_90 ,
V_33 -> V_35 . V_86 ,
V_33 -> V_35 . V_277 ,
V_256 ? L_46 : L_47 ) ;
return 0 ;
V_269:
F_80 ( V_31 ) ;
V_268:
F_81 ( V_31 -> V_177 ) ;
V_31 -> V_177 = NULL ;
V_261:
F_43 ( V_33 -> V_199 ) ;
F_43 ( V_31 -> V_33 ) ;
V_31 -> V_33 = NULL ;
return V_34 ;
}
static void F_82 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
F_80 ( V_31 ) ;
V_33 -> V_130 = NULL ;
V_33 -> V_159 = NULL ;
V_33 -> V_163 = NULL ;
V_33 -> V_151 = NULL ;
V_33 -> V_198 = 0 ;
F_43 ( V_33 -> V_199 ) ;
V_33 -> V_199 = NULL ;
}
static struct V_166 *
F_83 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
struct V_278 * V_279 ;
struct V_140 * V_280 ;
struct V_166 * V_167 ;
struct V_26 * V_45 ;
int V_281 , V_282 ;
int V_197 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_281 = 8 ;
V_282 = sizeof( struct V_28 ) + 2 * sizeof( struct V_140 ) ;
V_167 = F_39 ( V_175 , V_281 , V_282 , V_31 ) ;
if ( F_40 ( V_167 ) )
return V_167 ;
V_45 = V_167 -> V_170 ;
F_13 ( V_45 ++ , V_167 -> V_29 , 0 , 2 ,
V_65 , V_31 ) ;
V_280 = V_167 -> V_29 + sizeof( struct V_28 ) ;
V_45 [ - 1 ] . V_43 |= V_234 ;
V_126 ( V_45 ++ , V_280 ++ , 0 , 0 , 4 ,
V_65 , V_31 , 0 ) ;
V_279 = V_33 -> V_283 ;
for ( V_197 = 0 ; V_197 < 4 ; V_197 ++ ) {
V_45 [ - 1 ] . V_43 |= V_234 ;
V_45 -> V_54 = V_65 ;
V_45 -> V_43 = 0 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_279 ;
V_45 ++ ;
V_279 ++ ;
}
V_45 [ - 1 ] . V_43 |= V_234 ;
V_126 ( V_45 ++ , V_280 ++ , 2 , 0 , 1 ,
V_65 , V_31 , 0 ) ;
V_45 [ - 1 ] . V_43 |= V_234 ;
V_45 -> V_54 = V_65 ;
V_45 -> V_43 = 0 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_279 ;
V_167 -> V_177 = NULL ;
V_167 -> V_119 = V_31 ;
V_167 -> V_176 = V_31 ;
V_167 -> V_180 = 255 ;
V_167 -> V_181 = F_31 () ;
V_167 -> V_182 = V_183 ;
return V_167 ;
}
static int F_84 ( struct V_166 * V_284 )
{
char * V_285 ;
if ( V_284 -> V_182 == V_286 )
return V_287 ;
else if ( V_284 -> V_182 == V_288 ||
V_284 -> V_182 == V_289 ) {
V_285 = F_85 ( & V_284 -> V_290 ) ;
if ( V_285 && ( V_285 [ 1 ] & V_291 ) )
return V_292 ;
else
return V_293 ;
} else
return V_293 ;
}
static void F_86 ( struct V_166 * V_284 ,
void * V_29 )
{
struct V_32 * V_33 ;
struct V_30 * V_31 ;
V_31 = V_284 -> V_119 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_33 -> V_259 = F_84 ( V_284 ) ;
F_42 ( V_284 , V_31 ) ;
F_87 ( V_31 ) ;
}
static int F_88 ( struct V_253 * V_177 )
{
struct V_166 * V_284 ;
V_284 = F_83 ( V_177 -> V_267 ) ;
if ( F_40 ( V_284 ) )
return F_63 ( V_284 ) ;
V_284 -> V_294 = F_86 ;
V_284 -> V_295 = NULL ;
V_284 -> V_178 = 5 * V_179 ;
F_35 ( V_188 , & V_284 -> V_43 ) ;
V_284 -> V_180 = 0 ;
F_89 ( V_284 ) ;
return - V_221 ;
}
static int F_90 ( struct V_253 * V_177 )
{
struct V_30 * V_31 ;
struct V_32 * V_33 ;
struct V_278 * V_283 ;
unsigned int V_296 , V_145 ;
int V_182 , V_197 ;
struct V_166 * V_284 ;
V_31 = V_177 -> V_267 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_182 = V_33 -> V_259 ;
V_33 -> V_259 = - 1 ;
if ( V_182 == V_293 ) {
V_284 = F_83 ( V_31 ) ;
F_41 ( V_284 ) ;
V_182 = F_84 ( V_284 ) ;
F_42 ( V_284 , V_31 ) ;
}
if ( V_31 -> V_229 & V_297 ) {
V_177 -> V_298 = V_299 ;
V_145 = V_300 ;
V_177 -> V_301 = 3 ;
goto V_302;
}
if ( V_182 == V_292 ) {
F_50 ( & V_31 -> V_2 -> V_82 , L_48 ) ;
return - V_303 ;
} else if ( V_182 == V_293 ) {
F_15 ( & V_31 -> V_2 -> V_82 ,
L_49
L_50 ) ;
return - V_258 ;
}
V_33 -> V_85 = 1 ;
V_283 = NULL ;
for ( V_197 = 0 ; V_197 < 3 ; V_197 ++ ) {
if ( V_33 -> V_283 [ V_197 ] . V_16 != 4 ||
V_33 -> V_283 [ V_197 ] . V_17 != F_23 ( V_197 ) - 4 ) {
V_33 -> V_85 = 0 ;
break;
}
}
if ( V_197 == 3 )
V_283 = & V_33 -> V_283 [ 4 ] ;
if ( V_33 -> V_85 == 0 ) {
for ( V_197 = 0 ; V_197 < 5 ; V_197 ++ ) {
if ( ( V_33 -> V_283 [ V_197 ] . V_16 != 0 ) ||
( V_33 -> V_283 [ V_197 ] . V_17 !=
V_33 -> V_283 [ 0 ] . V_17 ) )
break;
}
if ( V_197 == 5 )
V_283 = & V_33 -> V_283 [ 0 ] ;
} else {
if ( V_33 -> V_283 [ 3 ] . V_117 == 1 )
F_50 ( & V_31 -> V_2 -> V_82 ,
L_51 ) ;
}
if ( V_283 != NULL && V_283 -> V_16 == 0 ) {
if ( F_91 ( V_283 -> V_17 ) == 0 )
V_177 -> V_298 = V_283 -> V_17 ;
}
if ( V_177 -> V_298 == 0 ) {
F_50 ( & V_31 -> V_2 -> V_82 ,
L_52 ) ;
return - V_303 ;
}
V_177 -> V_301 = 0 ;
for ( V_296 = 512 ; V_296 < V_177 -> V_298 ; V_296 = V_296 << 1 )
V_177 -> V_301 ++ ;
V_145 = F_9 ( & V_33 -> V_35 , 0 , V_177 -> V_298 ) ;
V_302:
V_177 -> V_304 = ( V_33 -> V_90 *
V_33 -> V_35 . V_86 *
V_145 ) ;
F_73 ( & V_31 -> V_2 -> V_82 ,
L_53
L_54 , ( V_177 -> V_298 >> 10 ) ,
( ( V_33 -> V_90 *
V_33 -> V_35 . V_86 *
V_145 * ( V_177 -> V_298 >> 9 ) ) >> 1 ) ,
( ( V_145 * V_177 -> V_298 ) >> 10 ) ,
V_33 -> V_85 ?
L_55 : L_56 ) ;
return 0 ;
}
static int F_92 ( struct V_253 * V_177 )
{
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_177 -> V_267 -> V_33 ;
if ( V_33 -> V_259 < 0 )
return F_88 ( V_177 ) ;
else
return F_90 ( V_177 ) ;
}
static int F_93 ( struct V_30 * V_31 )
{
return F_94 ( V_31 ) ;
}
static int F_95 ( struct V_30 * V_31 )
{
F_96 ( & V_31 -> V_305 ) ;
return F_97 ( V_31 ) ;
}
static int
F_98 ( struct V_253 * V_177 , struct V_306 * V_22 )
{
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_177 -> V_267 -> V_33 ;
if ( F_91 ( V_177 -> V_298 ) == 0 ) {
V_22 -> V_307 = F_9 ( & V_33 -> V_35 ,
0 , V_177 -> V_298 ) ;
}
V_22 -> V_308 = V_33 -> V_35 . V_270 ;
V_22 -> V_51 = V_33 -> V_35 . V_86 ;
return 0 ;
}
static struct V_166 *
F_99 ( struct V_30 * V_31 ,
struct V_309 * V_310 )
{
struct V_32 * V_33 ;
struct V_166 * V_311 ;
struct V_278 * V_312 ;
struct V_26 * V_45 ;
void * V_29 ;
int V_313 ;
struct V_21 V_314 ;
int V_281 , V_282 ;
int V_197 ;
int V_315 = 0 ;
int V_316 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_313 = F_9 ( & V_33 -> V_35 , 0 , V_310 -> V_121 ) ;
F_10 ( & V_314 ,
V_310 -> V_317 / V_33 -> V_35 . V_86 ,
V_310 -> V_317 % V_33 -> V_35 . V_86 ) ;
if ( V_310 -> V_317 >=
( V_33 -> V_90 * V_33 -> V_35 . V_86 ) ) {
F_50 ( & V_31 -> V_2 -> V_82 , L_57
L_58 , V_310 -> V_317 ) ;
return F_100 ( - V_128 ) ;
}
if ( V_310 -> V_317 > V_310 -> V_318 ) {
F_50 ( & V_31 -> V_2 -> V_82 , L_59
L_60 , V_310 -> V_317 ) ;
return F_100 ( - V_128 ) ;
}
if ( F_91 ( V_310 -> V_121 ) != 0 ) {
F_50 ( & V_31 -> V_2 -> V_82 ,
L_61 ,
V_310 -> V_121 ) ;
return F_100 ( - V_128 ) ;
}
if ( V_310 -> V_315 & 0x10 ) {
V_316 = 0 ;
V_315 = V_310 -> V_315 & ~ 0x10 ;
} else {
V_316 = 1 ;
V_315 = V_310 -> V_315 ;
}
switch ( V_315 ) {
case 0x00 :
case 0x08 :
V_281 = 2 + V_313 ;
V_282 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
V_313 * sizeof( struct V_278 ) ;
break;
case 0x01 :
case 0x09 :
V_281 = 3 + V_313 ;
V_282 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
sizeof( struct V_278 ) +
V_313 * sizeof( struct V_278 ) ;
break;
case 0x04 :
case 0x0c :
V_281 = 3 ;
V_282 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
sizeof( struct V_278 ) ;
break;
default:
F_50 ( & V_31 -> V_2 -> V_82 , L_62
L_63 , V_310 -> V_315 ) ;
return F_100 ( - V_128 ) ;
}
V_311 = F_39 ( V_175 , V_281 , V_282 , V_31 ) ;
if ( F_40 ( V_311 ) )
return V_311 ;
V_29 = V_311 -> V_29 ;
V_45 = V_311 -> V_170 ;
switch ( V_315 & ~ 0x08 ) {
case 0x00 :
F_13 ( V_45 ++ , (struct V_28 * ) V_29 ,
V_310 -> V_317 , V_310 -> V_317 ,
V_75 , V_31 ) ;
if ( V_316 )
( (struct V_28 * ) V_29 ) -> V_38 |= 0x04 ;
V_29 += sizeof( struct V_28 ) ;
V_45 [ - 1 ] . V_43 |= V_234 ;
V_126 ( V_45 ++ , (struct V_140 * ) V_29 ,
V_310 -> V_317 , 0 , V_313 ,
V_75 , V_31 ,
V_310 -> V_121 ) ;
V_29 += sizeof( struct V_140 ) ;
break;
case 0x01 :
F_13 ( V_45 ++ , (struct V_28 * ) V_29 ,
V_310 -> V_317 , V_310 -> V_317 ,
V_80 ,
V_31 ) ;
V_29 += sizeof( struct V_28 ) ;
V_45 [ - 1 ] . V_43 |= V_234 ;
V_126 ( V_45 ++ , (struct V_140 * ) V_29 ,
V_310 -> V_317 , 0 , V_313 + 1 ,
V_80 , V_31 ,
V_31 -> V_177 -> V_298 ) ;
V_29 += sizeof( struct V_140 ) ;
break;
case 0x04 :
F_13 ( V_45 ++ , (struct V_28 * ) V_29 ,
V_310 -> V_317 , V_310 -> V_317 ,
V_75 , V_31 ) ;
V_29 += sizeof( struct V_28 ) ;
V_45 [ - 1 ] . V_43 |= V_234 ;
V_126 ( V_45 ++ , (struct V_140 * ) V_29 ,
V_310 -> V_317 , 0 , 1 ,
V_75 , V_31 , 8 ) ;
V_29 += sizeof( struct V_140 ) ;
break;
}
if ( V_315 & 0x01 ) {
V_312 = (struct V_278 * ) V_29 ;
V_29 += sizeof( struct V_278 ) ;
V_312 -> V_23 = V_314 . V_23 ;
V_312 -> V_24 = V_314 . V_24 ;
V_312 -> V_117 = 0 ;
V_312 -> V_16 = 0 ;
V_312 -> V_17 = 8 ;
V_45 [ - 1 ] . V_43 |= V_234 ;
V_45 -> V_54 = V_80 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_312 ;
V_45 ++ ;
}
if ( ( V_315 & ~ 0x08 ) & 0x04 ) {
V_312 = (struct V_278 * ) V_29 ;
V_29 += sizeof( struct V_278 ) ;
V_312 -> V_23 = V_314 . V_23 ;
V_312 -> V_24 = V_314 . V_24 ;
V_312 -> V_117 = 1 ;
V_312 -> V_16 = 0 ;
V_312 -> V_17 = 0 ;
V_45 [ - 1 ] . V_43 |= V_234 ;
V_45 -> V_54 = V_75 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_312 ;
} else {
for ( V_197 = 0 ; V_197 < V_313 ; V_197 ++ ) {
V_312 = (struct V_278 * ) V_29 ;
V_29 += sizeof( struct V_278 ) ;
V_312 -> V_23 = V_314 . V_23 ;
V_312 -> V_24 = V_314 . V_24 ;
V_312 -> V_117 = V_197 + 1 ;
V_312 -> V_16 = 0 ;
V_312 -> V_17 = V_310 -> V_121 ;
if ( ( V_315 & 0x08 ) &&
V_310 -> V_317 == 0 ) {
if ( V_197 < 3 ) {
V_312 -> V_16 = 4 ;
V_312 -> V_17 = V_147 [ V_197 ] - 4 ;
}
}
if ( ( V_315 & 0x08 ) &&
V_310 -> V_317 == 1 ) {
V_312 -> V_16 = 44 ;
V_312 -> V_17 = V_148 - 44 ;
}
V_45 [ - 1 ] . V_43 |= V_234 ;
V_45 -> V_54 = V_75 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_312 ;
V_45 ++ ;
}
}
V_311 -> V_119 = V_31 ;
V_311 -> V_176 = V_31 ;
V_311 -> V_180 = 256 ;
V_311 -> V_181 = F_31 () ;
V_311 -> V_182 = V_183 ;
return V_311 ;
}
static void F_101 ( struct V_166 * V_167 )
{
V_167 -> V_182 = V_183 ;
if ( V_167 -> V_177 && ( V_167 -> V_119 != V_167 -> V_177 -> V_267 ) ) {
F_102 ( V_167 ) ;
V_167 -> V_119 = V_167 -> V_177 -> V_267 ;
V_167 -> V_169 = V_167 -> V_177 -> V_267 -> V_209 . V_207 ;
}
}
static T_5
F_103 ( struct V_166 * V_167 )
{
struct V_30 * V_31 = (struct V_30 * ) V_167 -> V_119 ;
struct V_1 * V_2 = V_31 -> V_2 ;
switch ( V_2 -> V_319 . V_84 ) {
case 0x3990 :
case 0x2105 :
case 0x2107 :
case 0x1750 :
return V_320 ;
case 0x9343 :
case 0x3880 :
default:
return V_321 ;
}
}
static T_5
F_104 ( struct V_166 * V_167 )
{
return V_322 ;
}
static void F_105 ( struct V_30 * V_31 ,
struct V_166 * V_167 ,
struct V_290 * V_290 )
{
char V_66 ;
char * V_285 = NULL ;
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_66 = V_323 | V_324 | V_325 ;
if ( ( F_106 ( & V_290 -> V_326 ) & V_66 ) == V_66 ) {
if ( ! V_31 -> V_177 && V_33 -> V_327 &&
! F_107 ( V_328 , & V_31 -> V_43 ) ) {
F_97 ( V_31 ) ;
F_108 ( V_31 ) ;
}
F_109 ( V_31 ) ;
return;
}
V_285 = F_85 ( V_290 ) ;
if ( ! V_285 )
return;
if ( ( V_285 [ 27 ] & V_329 ) && ( V_285 [ 7 ] == 0x0D ) &&
( F_106 ( & V_290 -> V_326 ) & V_330 ) ) {
F_110 ( V_31 , V_290 ) ;
return;
}
if ( ! V_167 && ! ( V_285 [ 27 ] & V_329 ) &&
( ( V_285 [ 6 ] & V_331 ) == V_331 ) ) {
F_111 ( V_31 , V_285 ) ;
return;
}
if ( V_31 -> V_177 && ( V_285 [ 27 ] & V_329 ) &&
( V_285 [ 7 ] == 0x3F ) &&
( F_106 ( & V_290 -> V_326 ) & V_330 ) &&
F_107 ( V_332 , & V_31 -> V_43 ) ) {
if ( V_31 -> V_229 & V_333 )
F_32 ( V_334 , & V_31 -> V_43 ) ;
F_35 ( V_332 , & V_31 -> V_43 ) ;
F_15 ( & V_31 -> V_2 -> V_82 ,
L_64 ) ;
}
}
static struct V_166 * F_112 (
struct V_30 * V_119 ,
struct V_253 * V_177 ,
struct V_335 * V_336 ,
T_6 V_337 ,
T_6 V_338 ,
T_6 V_339 ,
T_6 V_340 ,
unsigned int V_341 ,
unsigned int V_342 ,
unsigned int V_145 ,
unsigned int V_121 )
{
struct V_32 * V_33 ;
unsigned long * V_343 ;
struct V_140 * V_280 ;
struct V_166 * V_167 ;
struct V_26 * V_45 ;
struct V_344 V_345 ;
struct V_346 * V_347 ;
char * V_348 ;
unsigned int V_349 ;
int V_42 , V_350 , V_281 , V_282 ;
T_6 V_146 ;
unsigned char V_48 , V_351 ;
int V_352 ;
struct V_30 * V_118 ;
V_118 = V_177 -> V_267 ;
V_33 = (struct V_32 * ) V_118 -> V_33 ;
if ( F_113 ( V_336 ) == V_353 )
V_48 = V_60 ;
else if ( F_113 ( V_336 ) == V_354 )
V_48 = V_72 ;
else
return F_100 ( - V_128 ) ;
V_42 = 0 ;
V_350 = 0 ;
F_114 (bv, req, iter) {
if ( V_347 -> V_355 & ( V_121 - 1 ) )
return F_100 ( - V_128 ) ;
V_42 += V_347 -> V_355 >> ( V_177 -> V_301 + 9 ) ;
#if F_69 ( V_243 )
if ( F_115 ( F_116 ( V_347 -> V_356 ) , V_347 -> V_355 ) )
V_350 += V_347 -> V_355 >> ( V_177 -> V_301 + 9 ) ;
#endif
}
if ( V_42 != V_338 - V_337 + 1 )
return F_100 ( - V_128 ) ;
V_352 = V_33 -> V_229 . V_252 [ 8 ] & 0x01 ;
if ( V_352 ) {
V_281 = 2 + V_42 ;
V_282 = sizeof( struct V_93 ) +
sizeof( struct V_140 ) +
V_350 * sizeof( unsigned long ) ;
} else {
V_281 = 2 + V_42 ;
V_282 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
V_350 * sizeof( unsigned long ) ;
}
if ( V_33 -> V_85 && V_337 < 2 * V_145 ) {
if ( V_338 >= 2 * V_145 )
V_42 = 2 * V_145 - V_337 ;
V_281 += V_42 ;
V_282 += V_42 * sizeof( struct V_140 ) ;
}
V_167 = F_39 ( V_175 , V_281 , V_282 ,
V_119 ) ;
if ( F_40 ( V_167 ) )
return V_167 ;
V_45 = V_167 -> V_170 ;
if ( V_352 ) {
if ( F_21 ( V_45 ++ , V_167 -> V_29 , V_339 ,
V_340 , V_48 , V_118 , V_119 ) == - V_221 ) {
F_42 ( V_167 , V_119 ) ;
return F_100 ( - V_221 ) ;
}
V_343 = ( unsigned long * ) ( V_167 -> V_29 +
sizeof( struct V_93 ) ) ;
} else {
if ( F_13 ( V_45 ++ , V_167 -> V_29 , V_339 ,
V_340 , V_48 , V_119 ) == - V_221 ) {
F_42 ( V_167 , V_119 ) ;
return F_100 ( - V_221 ) ;
}
V_343 = ( unsigned long * ) ( V_167 -> V_29 +
sizeof( struct V_28 ) ) ;
}
V_280 = (struct V_140 * ) ( V_343 + V_350 ) ;
V_146 = V_337 ;
if ( V_33 -> V_85 == 0 || V_146 > 2 * V_145 ) {
V_45 [ - 1 ] . V_43 |= V_234 ;
V_126 ( V_45 ++ , V_280 ++ , V_339 , V_341 + 1 ,
V_338 - V_146 + 1 , V_48 , V_118 , V_121 ) ;
}
F_114 (bv, req, iter) {
V_348 = F_116 ( V_347 -> V_356 ) + V_347 -> V_357 ;
if ( V_358 ) {
char * V_359 = F_117 ( V_358 ,
V_194 | V_360 ) ;
if ( V_359 && F_113 ( V_336 ) == V_354 )
memcpy ( V_359 + V_347 -> V_357 , V_348 , V_347 -> V_355 ) ;
if ( V_359 )
V_348 = V_359 + V_347 -> V_357 ;
}
for ( V_349 = 0 ; V_349 < V_347 -> V_355 ; V_349 += V_121 ) {
T_6 V_361 = V_146 ;
unsigned int V_362 = F_118 ( V_361 , V_145 ) ;
V_351 = V_48 ;
V_42 = V_121 ;
if ( V_33 -> V_85 && V_146 < 2 * V_145 ) {
if ( F_22 ( V_145 , V_146 ) ) {
V_351 |= 0x8 ;
V_42 = F_23 ( V_146 ) ;
if ( V_42 < V_121 &&
F_113 ( V_336 ) == V_353 )
memset ( V_348 + V_42 , 0xe5 ,
V_121 - V_42 ) ;
}
V_45 [ - 1 ] . V_43 |= V_234 ;
V_126 ( V_45 ++ , V_280 ++ ,
V_361 , V_362 + 1 ,
1 , V_351 , V_118 , V_42 ) ;
}
if ( V_33 -> V_85 && V_146 == 2 * V_145 ) {
V_45 [ - 1 ] . V_43 |= V_234 ;
V_126 ( V_45 ++ , V_280 ++ ,
V_361 , V_362 + 1 ,
V_338 - V_146 + 1 ,
V_48 , V_118 , V_42 ) ;
}
V_45 [ - 1 ] . V_43 |= V_234 ;
V_45 -> V_54 = V_351 ;
V_45 -> V_42 = V_42 ;
if ( F_115 ( V_348 , V_121 ) ) {
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_343 ;
V_45 -> V_43 = V_363 ;
V_343 = F_119 ( V_343 , V_348 , V_121 ) ;
} else {
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_348 ;
V_45 -> V_43 = 0 ;
}
V_45 ++ ;
V_348 += V_121 ;
V_146 ++ ;
}
}
if ( F_120 ( V_336 ) ||
V_177 -> V_267 -> V_229 & V_364 )
F_32 ( V_365 , & V_167 -> V_43 ) ;
V_167 -> V_119 = V_119 ;
V_167 -> V_176 = V_119 ;
V_167 -> V_177 = V_177 ;
V_167 -> V_178 = V_119 -> V_262 * V_179 ;
V_167 -> V_169 = V_119 -> V_209 . V_211 ;
V_167 -> V_180 = 256 ;
V_167 -> V_181 = F_31 () ;
V_167 -> V_182 = V_183 ;
return V_167 ;
}
static struct V_166 * F_121 (
struct V_30 * V_119 ,
struct V_253 * V_177 ,
struct V_335 * V_336 ,
T_6 V_337 ,
T_6 V_338 ,
T_6 V_339 ,
T_6 V_340 ,
unsigned int V_341 ,
unsigned int V_342 ,
unsigned int V_145 ,
unsigned int V_121 )
{
unsigned long * V_343 ;
struct V_166 * V_167 ;
struct V_26 * V_45 ;
struct V_344 V_345 ;
struct V_346 * V_347 ;
char * V_348 , * V_366 ;
unsigned int V_350 , V_281 , V_282 ;
unsigned int V_100 ;
T_6 V_146 ;
unsigned char V_48 ;
struct V_30 * V_118 ;
unsigned int V_367 , V_42 , V_368 ;
unsigned int V_369 , V_370 , V_371 , V_372 ;
unsigned char V_373 , V_374 ;
T_6 V_361 ;
unsigned int V_362 ;
V_118 = V_177 -> V_267 ;
if ( F_113 ( V_336 ) == V_353 )
V_48 = V_113 ;
else if ( F_113 ( V_336 ) == V_354 )
V_48 = V_111 ;
else
return F_100 ( - V_128 ) ;
V_350 = V_338 - V_337 + 1 ;
V_367 = V_340 - V_339 + 1 ;
V_281 = 1 + V_367 ;
V_282 = sizeof( struct V_93 ) +
V_350 * sizeof( unsigned long long ) ;
V_167 = F_39 ( V_175 , V_281 , V_282 ,
V_119 ) ;
if ( F_40 ( V_167 ) )
return V_167 ;
V_45 = V_167 -> V_170 ;
if ( V_339 == V_340 )
V_100 = V_342 - V_341 + 1 ;
else
V_100 = V_342 + 1 ;
V_100 *= V_121 ;
if ( F_20 ( V_45 ++ , V_167 -> V_29 , V_339 ,
V_340 , V_48 , V_118 , V_119 ,
1 , V_341 + 1 ,
V_367 , V_121 ,
V_100 ) == - V_221 ) {
F_42 ( V_167 , V_119 ) ;
return F_100 ( - V_221 ) ;
}
V_343 = ( unsigned long * ) ( V_167 -> V_29 + sizeof( struct V_93 ) ) ;
V_146 = V_337 ;
V_373 = 1 ;
V_374 = 0 ;
V_372 = 0 ;
V_366 = 0 ;
V_369 = 0 ;
F_114 (bv, req, iter) {
V_348 = F_116 ( V_347 -> V_356 ) + V_347 -> V_357 ;
V_370 = V_347 -> V_355 ;
while ( V_370 ) {
if ( V_373 ) {
V_361 = V_146 ;
V_362 = F_118 ( V_361 , V_145 ) ;
V_368 = V_145 - V_362 ;
V_42 = F_122 ( ( V_338 - V_146 + 1 ) ,
( T_6 ) V_368 ) ;
V_372 = V_42 * V_121 ;
V_45 [ - 1 ] . V_43 |= V_234 ;
V_45 -> V_54 = V_48 ;
V_45 -> V_42 = V_372 ;
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_343 ;
V_45 -> V_43 = V_363 ;
V_45 ++ ;
V_146 += V_42 ;
V_373 = 0 ;
if ( ! V_366 )
V_366 = V_348 ;
}
if ( ! V_366 ) {
if ( F_14 ( V_348 ) & ( V_375 - 1 ) ) {
F_42 ( V_167 , V_119 ) ;
return F_100 ( - V_376 ) ;
} else
V_366 = V_348 ;
}
if ( ( V_366 + V_369 ) != V_348 ) {
F_42 ( V_167 , V_119 ) ;
return F_100 ( - V_376 ) ;
}
V_371 = F_122 ( V_370 , V_372 ) ;
V_370 -= V_371 ;
V_348 += V_371 ;
V_369 += V_371 ;
V_372 -= V_371 ;
if ( ! ( F_14 ( V_366 + V_369 ) & ( V_375 - 1 ) ) )
V_374 = 1 ;
if ( ! V_372 ) {
V_373 = 1 ;
V_374 = 1 ;
}
if ( V_374 ) {
V_343 = F_119 ( V_343 , V_366 ,
V_369 ) ;
V_366 = 0 ;
V_369 = 0 ;
V_374 = 0 ;
}
}
}
if ( F_120 ( V_336 ) ||
V_177 -> V_267 -> V_229 & V_364 )
F_32 ( V_365 , & V_167 -> V_43 ) ;
V_167 -> V_119 = V_119 ;
V_167 -> V_176 = V_119 ;
V_167 -> V_177 = V_177 ;
V_167 -> V_178 = V_119 -> V_262 * V_179 ;
V_167 -> V_169 = V_119 -> V_209 . V_211 ;
V_167 -> V_180 = 256 ;
V_167 -> V_181 = F_31 () ;
V_167 -> V_182 = V_183 ;
return V_167 ;
}
static int F_123 ( struct V_377 * V_377 ,
unsigned int V_46 , unsigned int V_47 , int V_48 ,
struct V_30 * V_118 ,
struct V_30 * V_119 ,
unsigned int V_98 , int V_42 ,
unsigned int V_121 ,
unsigned int V_378 ,
unsigned int V_100 ,
unsigned int V_145 )
{
struct V_93 V_94 ;
struct V_32 * V_122 , * V_123 ;
struct V_28 * V_124 ;
struct V_97 * V_125 ;
struct V_379 * V_379 ;
T_3 V_49 , V_50 ;
T_4 V_51 , V_52 , V_53 ;
T_7 V_380 ;
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
V_125 -> V_104 . V_381 = 0x01 ;
V_380 = V_382 ;
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
V_125 -> V_104 . V_381 = 0x2 ;
V_380 = V_127 ;
break;
default:
F_18 ( V_114 , V_118 ,
L_65 , V_48 ) ;
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
V_124 -> V_383 = 0x20 ;
V_124 -> V_384 = V_145 ;
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
V_125 -> V_104 . V_385 = 1 ;
V_125 -> V_104 . V_386 = 1 ;
V_125 -> V_106 = V_100 ;
V_125 -> V_387 = V_48 ;
V_125 -> V_42 = V_42 ;
V_125 -> V_101 = V_101 ;
F_10 ( & V_125 -> V_115 , V_49 , V_52 ) ;
V_125 -> V_116 . V_23 = V_125 -> V_115 . V_23 ;
V_125 -> V_116 . V_24 = V_125 -> V_115 . V_24 ;
V_125 -> V_116 . V_117 = V_98 ;
V_379 = F_124 ( V_377 , V_380 , 0 ,
& V_94 , sizeof( V_94 ) , V_378 ) ;
return F_40 ( V_379 ) ? F_63 ( V_379 ) : 0 ;
}
static struct V_166 * F_125 (
struct V_30 * V_119 ,
struct V_253 * V_177 ,
struct V_335 * V_336 ,
T_6 V_337 ,
T_6 V_338 ,
T_6 V_339 ,
T_6 V_340 ,
unsigned int V_341 ,
unsigned int V_342 ,
unsigned int V_145 ,
unsigned int V_121 )
{
struct V_166 * V_167 ;
struct V_344 V_345 ;
struct V_346 * V_347 ;
char * V_348 ;
unsigned int V_367 , V_388 ;
unsigned char V_48 ;
struct V_30 * V_118 ;
unsigned int V_100 ;
struct V_377 * V_377 ;
struct V_389 * V_390 = NULL ;
int V_391 ;
T_8 V_392 ;
T_7 V_393 ;
unsigned int V_370 , V_371 , V_372 ;
unsigned char V_373 ;
T_6 V_146 , V_361 ;
unsigned int V_394 ;
unsigned int V_42 , V_368 ;
V_118 = V_177 -> V_267 ;
if ( F_113 ( V_336 ) == V_353 ) {
V_48 = V_113 ;
V_391 = V_395 ;
} else if ( F_113 ( V_336 ) == V_354 ) {
V_48 = V_111 ;
V_391 = V_396 ;
} else
return F_100 ( - V_128 ) ;
V_367 = V_340 - V_339 + 1 ;
V_388 = 0 ;
F_114 (bv, req, iter) {
++ V_388 ;
}
if ( F_113 ( V_336 ) == V_354 )
V_388 += ( V_340 - V_339 ) ;
V_392 = F_126 ( 0 , V_388 , 0 ) ;
V_167 = F_39 ( V_175 , 0 , V_392 , V_119 ) ;
if ( F_40 ( V_167 ) )
return V_167 ;
if ( V_339 == V_340 )
V_100 = V_342 - V_341 + 1 ;
else
V_100 = V_342 + 1 ;
V_100 *= V_121 ;
V_377 = F_127 ( V_167 -> V_29 , V_392 , V_391 , 0 , V_388 , 0 ) ;
if ( F_40 ( V_377 ) ) {
F_42 ( V_167 , V_119 ) ;
return F_100 ( - V_128 ) ;
}
V_167 -> V_170 = F_128 ( V_377 ) ;
if ( F_123 ( V_377 , V_339 , V_340 ,
V_48 , V_118 , V_119 ,
V_341 + 1 ,
V_367 , V_121 ,
( V_338 - V_337 + 1 ) * V_121 ,
V_100 , V_145 ) == - V_221 ) {
F_42 ( V_167 , V_119 ) ;
return F_100 ( - V_221 ) ;
}
V_372 = 0 ;
if ( F_113 ( V_336 ) == V_354 ) {
V_373 = 1 ;
V_146 = V_337 ;
F_114 (bv, req, iter) {
V_348 = F_116 ( V_347 -> V_356 ) + V_347 -> V_357 ;
V_370 = V_347 -> V_355 ;
while ( V_370 ) {
if ( V_373 ) {
V_361 = V_146 ;
V_394 = F_118 ( V_361 , V_145 ) ;
V_368 = V_145 - V_394 ;
V_42 = F_122 ( ( V_338 - V_146 + 1 ) ,
( T_6 ) V_368 ) ;
V_372 = V_42 * V_121 ;
V_146 += V_42 ;
V_373 = 0 ;
}
V_371 = F_122 ( V_370 , V_372 ) ;
V_370 -= V_371 ;
V_372 -= V_371 ;
if ( ! V_372 ) {
V_373 = 1 ;
V_393 = V_397 ;
} else
V_393 = 0 ;
V_390 = F_129 ( V_377 , V_393 ,
V_348 , V_371 ) ;
if ( F_40 ( V_390 ) )
return F_100 ( - V_128 ) ;
V_348 += V_371 ;
}
}
} else {
F_114 (bv, req, iter) {
V_348 = F_116 ( V_347 -> V_356 ) + V_347 -> V_357 ;
V_390 = F_129 ( V_377 , 0x00 ,
V_348 , V_347 -> V_355 ) ;
if ( F_40 ( V_390 ) )
return F_100 ( - V_128 ) ;
}
}
V_390 -> V_43 |= V_398 ;
V_390 -> V_43 &= ~ V_397 ;
F_130 ( V_377 ) ;
if ( F_120 ( V_336 ) ||
V_177 -> V_267 -> V_229 & V_364 )
F_32 ( V_365 , & V_167 -> V_43 ) ;
V_167 -> V_399 = 1 ;
V_167 -> V_119 = V_119 ;
V_167 -> V_176 = V_119 ;
V_167 -> V_177 = V_177 ;
V_167 -> V_178 = V_119 -> V_262 * V_179 ;
V_167 -> V_169 = V_119 -> V_209 . V_211 ;
V_167 -> V_180 = 256 ;
V_167 -> V_181 = F_31 () ;
V_167 -> V_182 = V_183 ;
return V_167 ;
}
static struct V_166 * F_131 ( struct V_30 * V_119 ,
struct V_253 * V_177 ,
struct V_335 * V_336 )
{
int V_400 , V_401 ;
int V_352 ;
int V_402 ;
struct V_32 * V_33 ;
struct V_30 * V_118 ;
T_6 V_337 , V_338 ;
T_6 V_339 , V_340 ;
unsigned int V_341 , V_342 ;
unsigned int V_145 , V_121 ;
int V_403 ;
unsigned int V_404 ;
struct V_166 * V_167 ;
V_118 = V_177 -> V_267 ;
V_33 = (struct V_32 * ) V_118 -> V_33 ;
V_121 = V_177 -> V_298 ;
V_145 = F_9 ( & V_33 -> V_35 , 0 , V_121 ) ;
if ( V_145 == 0 )
return F_100 ( - V_128 ) ;
V_337 = V_339 = F_132 ( V_336 ) >> V_177 -> V_301 ;
V_341 = F_118 ( V_339 , V_145 ) ;
V_338 = V_340 =
( F_132 ( V_336 ) + F_133 ( V_336 ) - 1 ) >> V_177 -> V_301 ;
V_342 = F_118 ( V_340 , V_145 ) ;
V_403 = ( V_33 -> V_85 && V_337 < 2 * V_145 ) ;
V_402 = V_33 -> V_229 . V_252 [ 40 ] & 0x20 ;
V_404 = F_134 ( V_336 ) ;
if ( F_113 ( V_336 ) == V_354 )
V_404 += ( V_340 - V_339 ) * 4 ;
V_400 = V_33 -> V_229 . V_252 [ 9 ] & 0x20 ;
V_401 = V_33 -> V_229 . V_252 [ 12 ] & 0x40 ;
V_352 = V_33 -> V_229 . V_252 [ 8 ] & 0x01 ;
V_167 = NULL ;
if ( V_403 || V_358 ) {
} else if ( ( V_404 <= V_33 -> V_213 )
&& ( V_402 || ( V_339 == V_340 ) ) ) {
V_167 = F_125 ( V_119 , V_177 , V_336 ,
V_337 , V_338 ,
V_339 , V_340 ,
V_341 , V_342 ,
V_145 , V_121 ) ;
if ( F_40 ( V_167 ) && ( F_63 ( V_167 ) != - V_221 ) &&
( F_63 ( V_167 ) != - V_195 ) )
V_167 = NULL ;
} else if ( V_352 &&
( ( ( F_113 ( V_336 ) == V_353 ) && V_400 ) ||
( ( F_113 ( V_336 ) == V_354 ) && V_401 ) ) ) {
V_167 = F_121 ( V_119 , V_177 , V_336 ,
V_337 , V_338 ,
V_339 , V_340 ,
V_341 , V_342 ,
V_145 , V_121 ) ;
if ( F_40 ( V_167 ) && ( F_63 ( V_167 ) != - V_221 ) &&
( F_63 ( V_167 ) != - V_195 ) )
V_167 = NULL ;
}
if ( ! V_167 )
V_167 = F_112 ( V_119 , V_177 , V_336 ,
V_337 , V_338 ,
V_339 , V_340 ,
V_341 , V_342 ,
V_145 , V_121 ) ;
return V_167 ;
}
static struct V_166 * F_135 ( struct V_30 * V_119 ,
struct V_253 * V_177 ,
struct V_335 * V_336 )
{
unsigned long * V_343 ;
struct V_30 * V_118 ;
struct V_166 * V_167 ;
struct V_26 * V_45 ;
struct V_344 V_345 ;
struct V_346 * V_347 ;
char * V_348 ;
unsigned char V_48 ;
unsigned int V_367 ;
unsigned int V_370 , V_372 ;
unsigned int V_341 ;
unsigned int V_350 , V_281 , V_282 ;
T_6 V_339 , V_340 ;
unsigned int V_405 ;
if ( ( F_132 ( V_336 ) % V_406 ) != 0 ) {
V_167 = F_100 ( - V_128 ) ;
goto V_407;
}
if ( ( ( F_132 ( V_336 ) + F_133 ( V_336 ) ) %
V_406 ) != 0 ) {
V_167 = F_100 ( - V_128 ) ;
goto V_407;
}
V_339 = F_132 ( V_336 ) / V_406 ;
V_340 = ( F_132 ( V_336 ) + F_133 ( V_336 ) - 1 ) /
V_406 ;
V_367 = V_340 - V_339 + 1 ;
V_341 = 0 ;
V_118 = V_177 -> V_267 ;
if ( F_113 ( V_336 ) == V_353 )
V_48 = V_112 ;
else if ( F_113 ( V_336 ) == V_354 )
V_48 = V_107 ;
else {
V_167 = F_100 ( - V_128 ) ;
goto V_407;
}
V_350 = V_367 * V_300 ;
V_281 = 1 + V_367 ;
V_405 = sizeof( struct V_93 ) + 8 ;
V_282 = V_405 + V_350 * sizeof( unsigned long long ) ;
V_167 = F_39 ( V_175 , V_281 ,
V_282 , V_119 ) ;
if ( F_40 ( V_167 ) )
goto V_407;
V_45 = V_167 -> V_170 ;
if ( F_20 ( V_45 ++ , V_167 -> V_29 , V_339 , V_340 , V_48 ,
V_118 , V_119 , 1 , V_341 + 1 ,
V_367 , 0 , 0 ) == - V_221 ) {
F_42 ( V_167 , V_119 ) ;
V_167 = F_100 ( - V_221 ) ;
goto V_407;
}
V_343 = ( unsigned long * ) ( V_167 -> V_29 + V_405 ) ;
V_372 = 0 ;
F_114 (bv, req, iter) {
V_348 = F_116 ( V_347 -> V_356 ) + V_347 -> V_357 ;
V_370 = V_347 -> V_355 ;
if ( ! V_372 ) {
V_45 [ - 1 ] . V_43 |= V_234 ;
V_45 -> V_54 = V_48 ;
V_45 -> V_42 = 57326 ;
V_372 = 65536 ;
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_343 ;
V_45 -> V_43 |= V_363 ;
V_45 -> V_43 |= V_44 ;
V_45 ++ ;
}
V_372 -= V_370 ;
V_343 = F_119 ( V_343 , V_348 , V_370 ) ;
}
if ( F_120 ( V_336 ) ||
V_177 -> V_267 -> V_229 & V_364 )
F_32 ( V_365 , & V_167 -> V_43 ) ;
V_167 -> V_119 = V_119 ;
V_167 -> V_176 = V_119 ;
V_167 -> V_177 = V_177 ;
V_167 -> V_178 = V_119 -> V_262 * V_179 ;
V_167 -> V_169 = V_119 -> V_209 . V_211 ;
V_167 -> V_180 = 256 ;
V_167 -> V_181 = F_31 () ;
V_167 -> V_182 = V_183 ;
if ( F_40 ( V_167 ) && F_63 ( V_167 ) != - V_221 )
V_167 = NULL ;
V_407:
return V_167 ;
}
static int
F_136 ( struct V_166 * V_167 , struct V_335 * V_336 )
{
struct V_32 * V_33 ;
struct V_26 * V_45 ;
struct V_344 V_345 ;
struct V_346 * V_347 ;
char * V_348 , * V_56 ;
unsigned int V_121 , V_145 , V_349 ;
T_6 V_146 ;
int V_182 ;
if ( ! V_358 )
goto V_407;
V_33 = (struct V_32 * ) V_167 -> V_177 -> V_267 -> V_33 ;
V_121 = V_167 -> V_177 -> V_298 ;
V_145 = F_9 ( & V_33 -> V_35 , 0 , V_121 ) ;
V_146 = F_132 ( V_336 ) >> V_167 -> V_177 -> V_301 ;
V_45 = V_167 -> V_170 ;
V_45 ++ ;
if ( V_33 -> V_85 == 0 || V_146 > 2 * V_145 )
V_45 ++ ;
F_114 (bv, req, iter) {
V_348 = F_116 ( V_347 -> V_356 ) + V_347 -> V_357 ;
for ( V_349 = 0 ; V_349 < V_347 -> V_355 ; V_349 += V_121 ) {
if ( V_33 -> V_85 && V_146 <= 2 * V_145 )
V_45 ++ ;
if ( V_348 ) {
if ( V_45 -> V_43 & V_363 )
V_56 = * ( ( char * * ) ( ( V_172 ) V_45 -> V_56 ) ) ;
else
V_56 = ( char * ) ( ( V_172 ) V_45 -> V_56 ) ;
if ( V_348 != V_56 ) {
if ( F_113 ( V_336 ) == V_353 )
memcpy ( V_348 , V_56 , V_347 -> V_355 ) ;
F_137 ( V_358 ,
( void * ) ( ( V_172 ) V_56 & V_408 ) ) ;
}
V_348 = NULL ;
}
V_45 ++ ;
V_146 ++ ;
}
}
V_407:
V_182 = V_167 -> V_182 == V_286 ;
F_42 ( V_167 , V_167 -> V_176 ) ;
return V_182 ;
}
void F_102 ( struct V_166 * V_167 )
{
struct V_26 * V_45 ;
struct V_93 * V_94 ;
struct V_409 * V_409 ;
struct V_410 * V_410 ;
struct V_379 * V_379 ;
if ( V_167 -> V_399 == 1 ) {
V_409 = V_167 -> V_170 ;
V_410 = F_138 ( V_409 ) ;
V_379 = (struct V_379 * ) & V_410 -> V_411 [ 0 ] ;
V_94 = (struct V_93 * ) & V_379 -> V_412 [ 0 ] ;
V_94 -> V_95 . V_136 = 0 ;
V_94 -> V_95 . V_138 = 0 ;
} else {
V_45 = V_167 -> V_170 ;
V_94 = V_167 -> V_29 ;
if ( V_45 -> V_54 == V_127 ) {
V_94 -> V_95 . V_136 = 0 ;
V_94 -> V_95 . V_138 = 0 ;
}
}
}
static struct V_166 * F_139 ( struct V_30 * V_267 ,
struct V_253 * V_177 ,
struct V_335 * V_336 )
{
struct V_32 * V_33 ;
struct V_30 * V_119 ;
unsigned long V_43 ;
struct V_166 * V_167 ;
V_119 = F_140 ( V_267 ) ;
if ( ! V_119 )
V_119 = V_267 ;
V_33 = (struct V_32 * ) V_119 -> V_33 ;
if ( V_33 -> V_42 >= V_413 )
return F_100 ( - V_414 ) ;
F_25 ( F_26 ( V_119 -> V_2 ) , V_43 ) ;
V_33 -> V_42 ++ ;
if ( ( V_267 -> V_229 & V_297 ) )
V_167 = F_135 ( V_119 , V_177 , V_336 ) ;
else
V_167 = F_131 ( V_119 , V_177 , V_336 ) ;
if ( F_40 ( V_167 ) )
V_33 -> V_42 -- ;
F_28 ( F_26 ( V_119 -> V_2 ) , V_43 ) ;
return V_167 ;
}
static int F_141 ( struct V_166 * V_167 ,
struct V_335 * V_336 )
{
struct V_32 * V_33 ;
unsigned long V_43 ;
F_25 ( F_26 ( V_167 -> V_176 -> V_2 ) , V_43 ) ;
V_33 = (struct V_32 * ) V_167 -> V_176 -> V_33 ;
V_33 -> V_42 -- ;
F_28 ( F_26 ( V_167 -> V_176 -> V_2 ) , V_43 ) ;
return F_136 ( V_167 , V_336 ) ;
}
static int
F_142 ( struct V_30 * V_31 ,
struct V_415 * V_416 )
{
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_416 -> V_417 = 2 ;
V_416 -> V_418 = V_33 -> V_85 ? 0 : 1 ;
V_416 -> V_120 = V_33 -> V_85 ? V_419 : V_420 ;
V_416 -> V_421 = sizeof( struct V_14 ) ;
memcpy ( V_416 -> V_422 , & V_33 -> V_35 ,
sizeof( struct V_14 ) ) ;
V_416 -> V_423 = F_122 ( ( unsigned long ) V_33 -> V_198 ,
sizeof( V_416 -> V_424 ) ) ;
memcpy ( V_416 -> V_424 , V_33 -> V_199 ,
V_416 -> V_423 ) ;
return 0 ;
}
static int
F_143 ( struct V_30 * V_31 )
{
struct V_166 * V_167 ;
int V_34 ;
struct V_26 * V_45 ;
int V_425 ;
if ( ! F_144 ( V_426 ) )
return - V_41 ;
V_425 = 0 ;
V_167 = F_39 ( V_175 , 1 , 32 , V_31 ) ;
if ( F_40 ( V_167 ) ) {
F_145 ( & V_427 ) ;
V_425 = 1 ;
V_167 = & V_428 -> V_167 ;
memset ( V_167 , 0 , sizeof( * V_167 ) ) ;
memset ( & V_428 -> V_45 , 0 ,
sizeof( V_428 -> V_45 ) ) ;
V_167 -> V_170 = & V_428 -> V_45 ;
V_167 -> V_29 = & V_428 -> V_29 ;
V_167 -> V_174 = V_175 ;
}
V_45 = V_167 -> V_170 ;
V_45 -> V_54 = V_429 ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_42 = 32 ;
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_167 -> V_29 ;
V_167 -> V_119 = V_31 ;
V_167 -> V_176 = V_31 ;
F_35 ( V_188 , & V_167 -> V_43 ) ;
F_32 ( V_365 , & V_167 -> V_43 ) ;
V_167 -> V_180 = 2 ;
V_167 -> V_178 = 2 * V_179 ;
V_167 -> V_181 = F_31 () ;
V_167 -> V_182 = V_183 ;
V_34 = F_36 ( V_167 ) ;
if ( ! V_34 )
F_35 ( V_332 , & V_31 -> V_43 ) ;
if ( V_425 )
F_55 ( & V_427 ) ;
else
F_42 ( V_167 , V_167 -> V_176 ) ;
return V_34 ;
}
static int
F_146 ( struct V_30 * V_31 )
{
struct V_166 * V_167 ;
int V_34 ;
struct V_26 * V_45 ;
int V_425 ;
if ( ! F_144 ( V_426 ) )
return - V_41 ;
V_425 = 0 ;
V_167 = F_39 ( V_175 , 1 , 32 , V_31 ) ;
if ( F_40 ( V_167 ) ) {
F_145 ( & V_427 ) ;
V_425 = 1 ;
V_167 = & V_428 -> V_167 ;
memset ( V_167 , 0 , sizeof( * V_167 ) ) ;
memset ( & V_428 -> V_45 , 0 ,
sizeof( V_428 -> V_45 ) ) ;
V_167 -> V_170 = & V_428 -> V_45 ;
V_167 -> V_29 = & V_428 -> V_29 ;
V_167 -> V_174 = V_175 ;
}
V_45 = V_167 -> V_170 ;
V_45 -> V_54 = V_430 ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_42 = 32 ;
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_167 -> V_29 ;
V_167 -> V_119 = V_31 ;
V_167 -> V_176 = V_31 ;
F_35 ( V_188 , & V_167 -> V_43 ) ;
F_32 ( V_365 , & V_167 -> V_43 ) ;
V_167 -> V_180 = 2 ;
V_167 -> V_178 = 2 * V_179 ;
V_167 -> V_181 = F_31 () ;
V_167 -> V_182 = V_183 ;
V_34 = F_36 ( V_167 ) ;
if ( ! V_34 )
F_32 ( V_332 , & V_31 -> V_43 ) ;
if ( V_425 )
F_55 ( & V_427 ) ;
else
F_42 ( V_167 , V_167 -> V_176 ) ;
return V_34 ;
}
static int
F_147 ( struct V_30 * V_31 )
{
struct V_166 * V_167 ;
int V_34 ;
struct V_26 * V_45 ;
int V_425 ;
if ( ! F_144 ( V_426 ) )
return - V_41 ;
V_425 = 0 ;
V_167 = F_39 ( V_175 , 1 , 32 , V_31 ) ;
if ( F_40 ( V_167 ) ) {
F_145 ( & V_427 ) ;
V_425 = 1 ;
V_167 = & V_428 -> V_167 ;
memset ( V_167 , 0 , sizeof( * V_167 ) ) ;
memset ( & V_428 -> V_45 , 0 ,
sizeof( V_428 -> V_45 ) ) ;
V_167 -> V_170 = & V_428 -> V_45 ;
V_167 -> V_29 = & V_428 -> V_29 ;
V_167 -> V_174 = V_175 ;
}
V_45 = V_167 -> V_170 ;
V_45 -> V_54 = V_431 ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_42 = 32 ;
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_167 -> V_29 ;
V_167 -> V_119 = V_31 ;
V_167 -> V_176 = V_31 ;
F_35 ( V_188 , & V_167 -> V_43 ) ;
F_32 ( V_365 , & V_167 -> V_43 ) ;
V_167 -> V_180 = 2 ;
V_167 -> V_178 = 2 * V_179 ;
V_167 -> V_181 = F_31 () ;
V_167 -> V_182 = V_183 ;
V_34 = F_36 ( V_167 ) ;
if ( ! V_34 )
F_32 ( V_332 , & V_31 -> V_43 ) ;
if ( V_425 )
F_55 ( & V_427 ) ;
else
F_42 ( V_167 , V_167 -> V_176 ) ;
return V_34 ;
}
static int F_148 ( struct V_30 * V_31 ,
void T_9 * V_432 )
{
struct V_166 * V_167 ;
int V_34 ;
struct V_26 * V_45 ;
int V_425 ;
struct V_433 V_434 ;
if ( ! F_144 ( V_426 ) )
return - V_41 ;
if ( F_149 ( & V_434 , V_432 , sizeof( V_434 ) ) )
return - V_435 ;
V_425 = 0 ;
V_167 = F_39 ( V_175 , 1 ,
sizeof( struct V_436 ) , V_31 ) ;
if ( F_40 ( V_167 ) ) {
F_145 ( & V_427 ) ;
V_425 = 1 ;
V_167 = & V_428 -> V_167 ;
memset ( V_167 , 0 , sizeof( * V_167 ) ) ;
memset ( & V_428 -> V_45 , 0 ,
sizeof( V_428 -> V_45 ) ) ;
V_167 -> V_170 = & V_428 -> V_45 ;
V_167 -> V_29 = & V_428 -> V_29 ;
V_167 -> V_174 = V_175 ;
}
V_45 = V_167 -> V_170 ;
V_45 -> V_54 = V_437 ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_42 = 12 ;
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_167 -> V_29 ;
V_167 -> V_119 = V_31 ;
V_167 -> V_176 = V_31 ;
F_35 ( V_188 , & V_167 -> V_43 ) ;
F_32 ( V_365 , & V_167 -> V_43 ) ;
F_32 ( V_189 , & V_167 -> V_43 ) ;
V_167 -> V_180 = 5 ;
V_167 -> V_178 = 10 * V_179 ;
V_167 -> V_181 = F_31 () ;
V_167 -> V_182 = V_183 ;
V_167 -> V_169 = V_434 . V_438 ;
V_34 = F_36 ( V_167 ) ;
if ( ! V_34 && V_434 . V_438 && ( V_167 -> V_169 != V_434 . V_438 ) )
V_34 = - V_258 ;
if ( ! V_34 ) {
V_434 . V_29 = * ( (struct V_436 * ) V_167 -> V_29 ) ;
if ( F_150 ( V_432 , & V_434 , sizeof( V_434 ) ) )
V_34 = - V_435 ;
}
if ( V_425 )
F_55 ( & V_427 ) ;
else
F_42 ( V_167 , V_167 -> V_176 ) ;
return V_34 ;
}
static int
F_151 ( struct V_30 * V_31 , void T_9 * V_432 )
{
struct V_226 * V_227 ;
struct V_439 * V_440 ;
struct V_166 * V_167 ;
struct V_26 * V_45 ;
int V_34 ;
V_167 = F_39 ( V_175 , 1 + 1 ,
( sizeof( struct V_226 ) +
sizeof( struct V_439 ) ) ,
V_31 ) ;
if ( F_40 ( V_167 ) ) {
F_18 ( V_7 , V_31 , L_1 ,
L_66 ) ;
return F_63 ( V_167 ) ;
}
V_167 -> V_119 = V_31 ;
V_167 -> V_176 = V_31 ;
V_167 -> V_180 = 0 ;
F_35 ( V_188 , & V_167 -> V_43 ) ;
V_167 -> V_178 = 10 * V_179 ;
V_227 = (struct V_226 * ) V_167 -> V_29 ;
memset ( V_227 , 0 , sizeof( struct V_226 ) ) ;
V_227 -> V_230 = V_231 ;
V_227 -> V_232 = 0x01 ;
V_227 -> V_441 [ 1 ] = 0x01 ;
V_45 = V_167 -> V_170 ;
V_45 -> V_54 = V_233 ;
V_45 -> V_42 = sizeof( struct V_226 ) ;
V_45 -> V_43 |= V_234 ;
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_227 ;
V_440 = (struct V_439 * ) ( V_227 + 1 ) ;
memset ( V_440 , 0 , sizeof( struct V_439 ) ) ;
V_45 ++ ;
V_45 -> V_54 = V_235 ;
V_45 -> V_42 = sizeof( struct V_439 ) ;
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_440 ;
V_167 -> V_181 = F_31 () ;
V_167 -> V_182 = V_183 ;
V_34 = F_41 ( V_167 ) ;
if ( V_34 == 0 ) {
V_227 = (struct V_226 * ) V_167 -> V_29 ;
V_440 = (struct V_439 * ) ( V_227 + 1 ) ;
if ( F_150 ( V_432 , V_440 ,
sizeof( struct V_439 ) ) )
V_34 = - V_435 ;
}
F_42 ( V_167 , V_167 -> V_176 ) ;
return V_34 ;
}
static int
F_152 ( struct V_30 * V_31 , void T_9 * V_432 )
{
struct V_32 * V_33 =
(struct V_32 * ) V_31 -> V_33 ;
struct V_442 V_70 = V_33 -> V_70 ;
int V_34 ;
if ( ! F_144 ( V_426 ) )
return - V_41 ;
if ( ! V_432 )
return - V_128 ;
V_34 = 0 ;
if ( F_150 ( V_432 , ( long * ) & V_70 ,
sizeof( struct V_442 ) ) )
V_34 = - V_435 ;
return V_34 ;
}
static int
F_153 ( struct V_30 * V_31 , void T_9 * V_432 )
{
struct V_32 * V_33 =
(struct V_32 * ) V_31 -> V_33 ;
struct V_442 V_70 ;
if ( ! F_144 ( V_426 ) )
return - V_41 ;
if ( ! V_432 )
return - V_128 ;
if ( F_149 ( & V_70 , V_432 , sizeof( struct V_442 ) ) )
return - V_435 ;
V_33 -> V_70 = V_70 ;
F_73 ( & V_31 -> V_2 -> V_82 ,
L_67 ,
V_33 -> V_70 . V_69 , V_33 -> V_70 . V_89 ) ;
return 0 ;
}
static int F_154 ( struct V_30 * V_31 , void T_9 * V_432 )
{
struct V_443 V_434 ;
char * V_444 , * V_445 ;
struct V_166 * V_167 ;
struct V_26 * V_45 ;
char V_446 , V_447 ;
int V_34 ;
if ( ! F_144 ( V_426 ) && ! F_144 ( V_448 ) )
return - V_41 ;
V_446 = V_447 = 0 ;
V_34 = - V_435 ;
if ( F_149 ( & V_434 , V_432 , sizeof( V_434 ) ) )
goto V_407;
if ( F_155 () || sizeof( long ) == 4 ) {
V_34 = - V_128 ;
if ( ( V_434 . V_444 >> 32 ) != 0 )
goto V_407;
if ( ( V_434 . V_445 >> 32 ) != 0 )
goto V_407;
V_434 . V_444 &= 0x7fffffffULL ;
V_434 . V_445 &= 0x7fffffffULL ;
}
V_444 = F_38 ( V_434 . V_449 , V_193 | V_194 ) ;
V_445 = F_38 ( V_434 . V_450 , V_193 | V_194 ) ;
if ( ! V_444 || ! V_445 ) {
V_34 = - V_195 ;
goto V_451;
}
V_34 = - V_435 ;
if ( F_149 ( V_444 ,
( void T_9 * ) ( unsigned long ) V_434 . V_444 ,
V_434 . V_449 ) )
goto V_451;
V_446 = V_444 [ 0 ] ;
V_447 = V_444 [ 1 ] ;
V_167 = F_39 ( V_175 , 2 , 0 , V_31 ) ;
if ( F_40 ( V_167 ) ) {
F_18 ( V_7 , V_31 , L_1 ,
L_66 ) ;
V_34 = F_63 ( V_167 ) ;
goto V_451;
}
V_167 -> V_119 = V_31 ;
V_167 -> V_176 = V_31 ;
V_167 -> V_180 = 3 ;
V_167 -> V_178 = 10 * V_179 ;
V_167 -> V_181 = F_31 () ;
V_167 -> V_182 = V_183 ;
V_45 = V_167 -> V_170 ;
V_45 -> V_54 = V_233 ;
V_45 -> V_42 = V_434 . V_449 ;
V_45 -> V_43 |= V_234 ;
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_444 ;
V_45 ++ ;
V_45 -> V_54 = V_235 ;
V_45 -> V_42 = V_434 . V_450 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_445 ;
V_34 = F_41 ( V_167 ) ;
if ( V_34 )
goto V_452;
V_34 = - V_435 ;
if ( F_150 ( ( void T_9 * ) ( unsigned long ) V_434 . V_445 ,
V_445 , V_434 . V_450 ) )
goto V_452;
V_34 = 0 ;
V_452:
F_42 ( V_167 , V_167 -> V_176 ) ;
V_451:
F_43 ( V_445 ) ;
F_43 ( V_444 ) ;
V_407:
F_18 ( V_7 , V_31 ,
L_68 ,
( int ) V_446 , ( int ) V_447 , V_34 ) ;
return V_34 ;
}
static int
F_156 ( struct V_253 * V_177 , unsigned int V_48 , void T_9 * V_432 )
{
struct V_30 * V_31 = V_177 -> V_267 ;
switch ( V_48 ) {
case V_453 :
return F_152 ( V_31 , V_432 ) ;
case V_454 :
return F_153 ( V_31 , V_432 ) ;
case V_455 :
return F_151 ( V_31 , V_432 ) ;
case V_456 :
return F_143 ( V_31 ) ;
case V_457 :
return F_146 ( V_31 ) ;
case V_458 :
return F_147 ( V_31 ) ;
case V_459 :
return F_148 ( V_31 , V_432 ) ;
case V_460 :
return F_154 ( V_31 , V_432 ) ;
default:
return - V_461 ;
}
}
static int
F_157 ( struct V_26 * V_462 , struct V_26 * V_463 , char * V_464 )
{
int V_465 , V_42 ;
char * V_466 ;
V_465 = 0 ;
while ( V_462 <= V_463 ) {
V_465 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_69 ,
from, ((int *) from)[0], ((int *) from)[1]) ;
if ( V_462 -> V_43 & V_363 )
V_466 = ( char * ) * ( ( V_172 * ) ( V_172 ) V_462 -> V_56 ) ;
else
V_466 = ( char * ) ( ( V_172 ) V_462 -> V_56 ) ;
for ( V_42 = 0 ; V_42 < V_462 -> V_42 && V_42 < 32 ; V_42 ++ ) {
if ( V_42 % 8 == 0 ) V_465 += sprintf ( V_464 + V_465 , L_70 ) ;
if ( V_42 % 4 == 0 ) V_465 += sprintf ( V_464 + V_465 , L_70 ) ;
V_465 += sprintf ( V_464 + V_465 , L_11 , V_466 [ V_42 ] ) ;
}
V_465 += sprintf ( V_464 + V_465 , L_71 ) ;
V_462 ++ ;
}
return V_465 ;
}
static void
F_158 ( struct V_30 * V_31 , struct V_290 * V_290 ,
char * V_467 )
{
T_10 * V_285 ;
T_10 * V_468 ;
V_285 = ( T_10 * ) F_85 ( V_290 ) ;
V_468 = ( T_10 * ) & V_290 -> V_326 ;
if ( V_285 ) {
F_18 ( V_469 , V_31 , L_72
L_73 ,
V_467 , * V_468 , * ( ( T_3 * ) ( V_468 + 1 ) ) ,
V_285 [ 0 ] , V_285 [ 1 ] , V_285 [ 2 ] , V_285 [ 3 ] ) ;
} else {
F_18 ( V_469 , V_31 , L_74 ,
V_467 , * V_468 , * ( ( T_3 * ) ( V_468 + 1 ) ) ,
L_75 ) ;
}
}
static void F_159 ( struct V_30 * V_31 ,
struct V_166 * V_336 , struct V_290 * V_290 )
{
char * V_464 ;
struct V_26 * V_470 , * V_471 , * V_472 , * V_462 , * V_463 ;
int V_465 , V_473 , V_474 ;
V_464 = ( char * ) F_160 ( V_224 ) ;
if ( V_464 == NULL ) {
F_18 ( V_7 , V_31 , L_1 ,
L_76 ) ;
return;
}
V_465 = sprintf (page, KERN_ERR PRINTK_HEADER
L_77 ,
dev_name(&device->cdev->dev)) ;
V_465 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_78
L_79 ,
req, scsw_cc(&irb->scsw), scsw_fctl(&irb->scsw),
scsw_actl(&irb->scsw), scsw_stctl(&irb->scsw),
scsw_dstat(&irb->scsw), scsw_cstat(&irb->scsw),
req ? req->intrc : 0 ) ;
V_465 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_80 ,
dev_name(&device->cdev->dev),
(void *) (addr_t) irb->scsw.cmd.cpa) ;
if ( V_290 -> V_475 . V_476 . V_477 . V_478 ) {
for ( V_473 = 0 ; V_473 < 4 ; V_473 ++ ) {
V_465 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_81 ,
(8 * sl), ((8 * sl) + 7)) ;
for ( V_474 = 0 ; V_474 < 8 ; V_474 ++ ) {
V_465 += sprintf ( V_464 + V_465 , L_82 ,
V_290 -> V_479 [ 8 * V_473 + V_474 ] ) ;
}
V_465 += sprintf ( V_464 + V_465 , L_71 ) ;
}
if ( V_290 -> V_479 [ 27 ] & V_329 ) {
sprintf (page + len, KERN_ERR PRINTK_HEADER
L_83
L_84 ,
irb->ecw[7] >> 4 , irb->ecw[7] & 0x0f ,
irb->ecw[1] & 0x10 ? L_47 : L_85 ) ;
} else {
sprintf (page + len, KERN_ERR PRINTK_HEADER
L_86
L_87 ,
irb->ecw[6] & 0x0f , irb->ecw[22] >> 4 ) ;
}
} else {
sprintf (page + len, KERN_ERR PRINTK_HEADER
L_88 ) ;
}
F_161 ( L_1 , V_464 ) ;
if ( V_336 ) {
V_470 = V_336 -> V_170 ;
for ( V_471 = V_470 ; V_471 -> V_43 & ( V_234 | V_480 ) ; V_471 ++ ) ;
V_463 = F_122 ( V_470 + 6 , V_471 ) ;
V_465 = sprintf (page, KERN_ERR PRINTK_HEADER
L_89 , req) ;
F_157 ( V_470 , V_463 , V_464 + V_465 ) ;
F_161 ( L_1 , V_464 ) ;
V_465 = 0 ;
V_462 = ++ V_463 ;
V_472 = (struct V_26 * ) ( V_172 )
V_290 -> V_326 . V_48 . V_481 ;
if ( V_462 < V_472 - 2 ) {
V_462 = V_472 - 2 ;
V_465 += sprintf (page, KERN_ERR PRINTK_HEADER L_90 ) ;
}
V_463 = F_122 ( V_472 + 1 , V_471 ) ;
V_465 += F_157 ( V_462 , V_463 , V_464 + V_465 ) ;
V_462 = F_162 ( V_462 , ++ V_463 ) ;
if ( V_462 < V_471 - 1 ) {
V_462 = V_471 - 1 ;
V_465 += sprintf (page + len, KERN_ERR PRINTK_HEADER L_90 ) ;
}
V_465 += F_157 ( V_462 , V_471 , V_464 + V_465 ) ;
if ( V_465 > 0 )
F_161 ( L_1 , V_464 ) ;
}
F_163 ( ( unsigned long ) V_464 ) ;
}
static void F_164 ( struct V_30 * V_31 ,
struct V_166 * V_336 , struct V_290 * V_290 )
{
char * V_464 ;
int V_465 , V_473 , V_474 , V_482 ;
struct V_483 * V_483 ;
T_7 * V_285 , * V_484 ;
V_464 = ( char * ) F_160 ( V_224 ) ;
if ( V_464 == NULL ) {
F_18 ( V_7 , V_31 , L_91 ,
L_92 ) ;
return;
}
V_465 = sprintf (page, KERN_ERR PRINTK_HEADER
L_77 ,
dev_name(&device->cdev->dev)) ;
V_465 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_78
L_93 ,
req, scsw_cc(&irb->scsw), scsw_fctl(&irb->scsw),
scsw_actl(&irb->scsw), scsw_stctl(&irb->scsw),
scsw_dstat(&irb->scsw), scsw_cstat(&irb->scsw),
irb->scsw.tm.fcxs, irb->scsw.tm.schxs,
req ? req->intrc : 0 ) ;
V_465 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_94 ,
dev_name(&device->cdev->dev),
(void *) (addr_t) irb->scsw.tm.tcw) ;
V_483 = NULL ;
V_285 = NULL ;
if ( V_290 -> V_326 . V_485 . V_409 && ( V_290 -> V_326 . V_485 . V_486 & 0x01 ) )
V_483 = F_165 (
(struct V_409 * ) ( unsigned long ) V_290 -> V_326 . V_485 . V_409 ) ;
if ( V_483 ) {
V_465 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_95 , tsb->length) ;
V_465 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_96 , tsb->flags) ;
V_465 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_97 , tsb->dcw_offset) ;
V_465 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_98 , tsb->count) ;
V_482 = V_483 -> V_42 - 28 ;
V_465 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_99 , residual) ;
switch ( V_483 -> V_43 & 0x07 ) {
case 1 :
V_465 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_100 ,
tsb->tsa.iostat.dev_time) ;
V_465 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_101 ,
tsb->tsa.iostat.def_time) ;
V_465 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_102 ,
tsb->tsa.iostat.queue_time) ;
V_465 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_103 ,
tsb->tsa.iostat.dev_busy_time) ;
V_465 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_104 ,
tsb->tsa.iostat.dev_act_time) ;
V_285 = V_483 -> V_487 . V_488 . V_285 ;
break;
case 2 :
V_465 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_105 , tsb->tsa.ddpc.rc) ;
for ( V_473 = 0 ; V_473 < 2 ; V_473 ++ ) {
V_465 += sprintf (page + len,
KERN_ERR PRINTK_HEADER
L_106 ,
(8 * sl), ((8 * sl) + 7)) ;
V_484 = V_483 -> V_487 . V_489 . V_484 ;
for ( V_474 = 0 ; V_474 < 8 ; V_474 ++ ) {
V_465 += sprintf ( V_464 + V_465 , L_82 ,
V_484 [ 8 * V_473 + V_474 ] ) ;
}
V_465 += sprintf ( V_464 + V_465 , L_71 ) ;
}
V_285 = V_483 -> V_487 . V_489 . V_285 ;
break;
case 3 :
V_465 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_107 ) ;
break;
}
if ( V_285 ) {
for ( V_473 = 0 ; V_473 < 4 ; V_473 ++ ) {
V_465 += sprintf (page + len,
KERN_ERR PRINTK_HEADER
L_81 ,
(8 * sl), ((8 * sl) + 7)) ;
for ( V_474 = 0 ; V_474 < 8 ; V_474 ++ ) {
V_465 += sprintf ( V_464 + V_465 , L_82 ,
V_285 [ 8 * V_473 + V_474 ] ) ;
}
V_465 += sprintf ( V_464 + V_465 , L_71 ) ;
}
if ( V_285 [ 27 ] & V_329 ) {
sprintf (page + len, KERN_ERR PRINTK_HEADER
L_83
L_84 ,
sense[7] >> 4 , sense[7] & 0x0f ,
sense[1] & 0x10 ? L_47 : L_85 ) ;
} else {
sprintf (page + len, KERN_ERR PRINTK_HEADER
L_86
L_87 ,
sense[6] & 0x0f , sense[22] >> 4 ) ;
}
} else {
sprintf (page + len, KERN_ERR PRINTK_HEADER
L_88 ) ;
}
} else {
sprintf (page + len, KERN_ERR PRINTK_HEADER
L_108 ) ;
}
F_161 ( L_1 , V_464 ) ;
F_163 ( ( unsigned long ) V_464 ) ;
}
static void F_166 ( struct V_30 * V_31 ,
struct V_166 * V_336 , struct V_290 * V_290 )
{
if ( F_167 ( & V_290 -> V_326 ) )
F_164 ( V_31 , V_336 , V_290 ) ;
else
F_159 ( V_31 , V_336 , V_290 ) ;
}
static int F_168 ( struct V_30 * V_31 )
{
F_97 ( V_31 ) ;
F_80 ( V_31 ) ;
return 0 ;
}
static int F_169 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
struct V_14 V_490 ;
int V_255 , V_34 ;
struct V_149 V_254 ;
unsigned long V_43 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_34 = F_46 ( V_31 ) ;
if ( V_34 )
goto V_491;
F_29 ( V_31 , & V_254 ) ;
V_34 = F_24 ( V_31 ) ;
F_25 ( F_26 ( V_31 -> V_2 ) , V_43 ) ;
if ( memcmp ( & V_33 -> V_134 , & V_254 , sizeof( struct V_149 ) ) != 0 )
F_15 ( & V_31 -> V_2 -> V_82 , L_109
L_110 ) ;
F_28 ( F_26 ( V_31 -> V_2 ) , V_43 ) ;
if ( V_34 )
goto V_491;
V_255 = F_75 ( V_31 ) ;
if ( V_255 < 0 )
return V_255 ;
if ( ! V_255 ) {
F_67 ( V_31 ) ;
F_76 ( V_31 ) ;
} else
F_77 ( V_31 ) ;
V_34 = F_46 ( V_31 ) ;
if ( V_34 )
goto V_491;
F_62 ( V_31 ) ;
V_34 = F_78 ( V_31 , V_175 ,
& V_490 , 64 ) ;
if ( V_34 ) {
F_3 ( V_7 , V_31 -> V_2 ,
L_43 , V_34 ) ;
goto V_491;
}
F_25 ( F_26 ( V_31 -> V_2 ) , V_43 ) ;
memcpy ( & V_33 -> V_35 , & V_490 , sizeof( V_490 ) ) ;
F_28 ( F_26 ( V_31 -> V_2 ) , V_43 ) ;
F_94 ( V_31 ) ;
return 0 ;
V_491:
return - 1 ;
}
static int F_170 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
int V_34 , V_492 ;
char V_493 [ 60 ] ;
struct V_149 V_134 ;
unsigned long V_43 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
F_25 ( F_26 ( V_31 -> V_2 ) , V_43 ) ;
V_492 = V_33 -> V_134 . V_162 ;
F_28 ( F_26 ( V_31 -> V_2 ) , V_43 ) ;
V_34 = F_46 ( V_31 ) ;
if ( V_34 )
goto V_491;
V_34 = F_24 ( V_31 ) ;
if ( V_34 )
goto V_491;
F_171 ( V_31 ) ;
F_29 ( V_31 , & V_134 ) ;
if ( V_492 != V_134 . V_162 ) {
if ( strlen ( V_134 . V_164 ) > 0 )
snprintf ( V_493 , sizeof( V_493 ) ,
L_111 , V_134 . V_152 , V_134 . V_154 ,
V_134 . V_156 , V_134 . V_162 , V_134 . V_164 ) ;
else
snprintf ( V_493 , sizeof( V_493 ) ,
L_112 , V_134 . V_152 , V_134 . V_154 ,
V_134 . V_156 , V_134 . V_162 ) ;
F_73 ( & V_31 -> V_2 -> V_82 ,
L_113
L_114 , V_493 ) ;
}
return 0 ;
V_491:
return - 1 ;
}
static int T_11
F_172 ( void )
{
int V_3 ;
F_173 ( V_8 . V_494 , 4 ) ;
V_428 = F_57 ( sizeof( * V_428 ) ,
V_193 | V_194 ) ;
if ( ! V_428 )
return - V_195 ;
V_225 = F_57 ( sizeof( * V_225 ) ,
V_193 | V_194 ) ;
if ( ! V_225 ) {
F_43 ( V_428 ) ;
return - V_195 ;
}
V_3 = F_174 ( & V_495 ) ;
if ( ! V_3 )
F_175 () ;
else {
F_43 ( V_225 ) ;
F_43 ( V_428 ) ;
}
return V_3 ;
}
static void T_12
F_176 ( void )
{
F_177 ( & V_495 ) ;
F_43 ( V_225 ) ;
F_43 ( V_428 ) ;
}
