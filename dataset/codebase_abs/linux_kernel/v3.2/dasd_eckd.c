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
static void F_33 ( struct V_166 * V_167 , void * V_29 )
{
struct V_26 * V_45 ;
T_2 * V_168 ;
if ( V_167 -> V_182 != V_185 ) {
V_45 = V_167 -> V_170 ;
V_168 = ( T_2 * ) ( ( V_172 ) V_45 -> V_56 ) ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
V_168 [ 0 ] = 0xE5 ;
V_168 [ 1 ] = 0xF1 ;
V_168 [ 2 ] = 0x4B ;
V_168 [ 3 ] = 0xF0 ;
}
F_34 ( V_167 , V_29 ) ;
}
static int F_35 ( struct V_30 * V_31 ,
struct V_166 * V_167 ,
T_2 * V_168 ,
T_2 V_169 )
{
struct V_186 * V_186 ;
int V_34 ;
V_186 = F_36 ( V_31 -> V_2 , V_187 ) ;
if ( ! V_186 || V_186 -> V_48 != V_171 )
return - V_188 ;
F_30 ( V_31 , V_167 , V_168 , V_169 ) ;
F_37 ( V_189 , & V_167 -> V_43 ) ;
F_32 ( V_190 , & V_167 -> V_43 ) ;
V_167 -> V_180 = 5 ;
V_167 -> V_191 = F_33 ;
V_34 = F_38 ( V_167 ) ;
return V_34 ;
}
static int F_39 ( struct V_30 * V_31 ,
void * * V_168 ,
int * V_192 , T_2 V_169 )
{
struct V_186 * V_186 ;
char * V_193 = NULL ;
int V_3 ;
struct V_166 * V_167 ;
V_186 = F_36 ( V_31 -> V_2 , V_187 ) ;
if ( ! V_186 || V_186 -> V_48 != V_171 ) {
V_3 = - V_188 ;
goto V_194;
}
V_193 = F_40 ( V_173 , V_195 | V_196 ) ;
if ( ! V_193 ) {
V_3 = - V_197 ;
goto V_194;
}
V_167 = F_41 ( V_175 , 1 ,
0 ,
V_31 ) ;
if ( F_42 ( V_167 ) ) {
F_18 ( V_7 , V_31 , L_1 ,
L_12 ) ;
V_3 = - V_197 ;
goto V_194;
}
F_30 ( V_31 , V_167 , V_193 , V_169 ) ;
V_167 -> V_191 = F_33 ;
V_3 = F_43 ( V_167 ) ;
F_44 ( V_167 , V_167 -> V_176 ) ;
if ( V_3 )
goto V_194;
* V_192 = V_173 ;
* V_168 = V_193 ;
return 0 ;
V_194:
F_45 ( V_193 ) ;
* V_168 = NULL ;
* V_192 = 0 ;
return V_3 ;
}
static int F_46 ( struct V_32 * V_33 )
{
struct V_198 * V_159 ;
int V_199 , V_42 ;
V_33 -> V_130 = NULL ;
V_33 -> V_159 = NULL ;
V_33 -> V_163 = NULL ;
V_33 -> V_151 = NULL ;
V_42 = V_33 -> V_200 / sizeof( struct V_198 ) ;
V_159 = (struct V_198 * ) V_33 -> V_201 ;
for ( V_199 = 0 ; V_199 < V_42 ; ++ V_199 ) {
if ( V_159 -> V_43 . V_202 == 1 && V_159 -> V_120 == 1 )
V_33 -> V_159 = V_159 ;
else if ( V_159 -> V_43 . V_202 == 1 && V_159 -> V_120 == 4 )
V_33 -> V_163 = (struct V_203 * ) V_159 ;
else if ( V_159 -> V_43 . V_202 == 2 )
V_33 -> V_151 = (struct V_204 * ) V_159 ;
else if ( V_159 -> V_43 . V_202 == 3 && V_159 -> V_205 == 1 )
V_33 -> V_130 = (struct V_206 * ) V_159 ;
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
static unsigned char F_47 ( void * V_201 , int V_200 )
{
struct V_204 * V_151 ;
int V_199 , V_42 , V_207 ;
V_42 = V_200 / sizeof( * V_151 ) ;
V_151 = (struct V_204 * ) V_201 ;
V_207 = 0 ;
for ( V_199 = 0 ; V_199 < V_42 ; ++ V_199 ) {
if ( V_151 -> V_43 . V_202 == 2 ) {
V_207 = 1 ;
break;
}
V_151 ++ ;
}
if ( V_207 )
return ( ( char * ) V_151 ) [ 18 ] & 0x07 ;
else
return 0 ;
}
static int F_48 ( struct V_30 * V_31 )
{
void * V_201 ;
int V_200 , V_208 ;
int V_34 ;
T_2 V_169 , V_209 ;
struct V_32 * V_33 ;
struct V_210 * V_211 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_211 = & V_31 -> V_211 ;
V_209 = F_49 ( V_31 -> V_2 ) ;
V_169 = 0x80 ;
V_208 = 0 ;
for ( V_169 = 0x80 ; V_169 ; V_169 >>= 1 ) {
if ( V_169 & V_209 ) {
V_34 = F_39 ( V_31 , & V_201 ,
& V_200 , V_169 ) ;
if ( V_34 && V_34 != - V_188 ) {
F_3 ( V_7 , V_31 -> V_2 ,
L_13
L_14 , V_34 ) ;
return V_34 ;
}
if ( V_201 == NULL ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_15
L_16 ) ;
V_211 -> V_209 |= V_169 ;
continue;
}
if ( ! V_208 ) {
F_45 ( V_33 -> V_201 ) ;
V_33 -> V_201 = V_201 ;
V_33 -> V_200 = V_200 ;
if ( F_46 ( V_33 ) ) {
V_33 -> V_201 = NULL ;
V_33 -> V_200 = 0 ;
F_45 ( V_201 ) ;
continue;
}
V_208 ++ ;
}
switch ( F_47 ( V_201 , V_200 ) ) {
case 0x02 :
V_211 -> V_212 |= V_169 ;
break;
case 0x03 :
V_211 -> V_213 |= V_169 ;
break;
}
V_211 -> V_209 |= V_169 ;
if ( V_201 != V_33 -> V_201 )
F_45 ( V_201 ) ;
}
}
return 0 ;
}
static int F_50 ( struct V_30 * V_31 , T_2 V_169 )
{
struct V_32 * V_33 ;
int V_214 ;
T_3 V_215 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
if ( V_33 -> V_215 ) {
V_214 = F_51 ( V_31 -> V_2 , V_169 ) ;
if ( ( V_214 < 0 ) ) {
F_52 ( & V_31 -> V_2 -> V_82 ,
L_17
L_18 ,
V_214 , V_169 ) ;
return V_214 ;
}
V_215 = V_214 * V_216 ;
if ( V_215 < V_33 -> V_215 ) {
F_52 ( & V_31 -> V_2 -> V_82 ,
L_19
L_20
L_21 , V_215 , V_169 ,
V_33 -> V_215 ) ;
return - V_41 ;
}
}
return 0 ;
}
static void F_53 ( struct V_217 * V_218 )
{
struct V_219 * V_29 ;
struct V_30 * V_31 ;
T_2 V_169 , V_209 , V_212 , V_213 , V_220 ;
unsigned long V_43 ;
int V_34 ;
V_29 = F_54 ( V_218 , struct V_219 , V_221 ) ;
V_31 = V_29 -> V_31 ;
if ( F_55 ( V_222 , & V_31 -> V_43 ) ) {
F_56 ( V_218 ) ;
return;
}
V_209 = 0 ;
V_212 = 0 ;
V_213 = 0 ;
V_220 = 0 ;
for ( V_169 = 0x80 ; V_169 ; V_169 >>= 1 ) {
if ( V_169 & V_29 -> V_223 ) {
memset ( V_29 -> V_168 , 0 , sizeof( V_29 -> V_168 ) ) ;
memset ( & V_29 -> V_167 , 0 , sizeof( V_29 -> V_167 ) ) ;
V_29 -> V_167 . V_170 = & V_29 -> V_45 ;
V_34 = F_35 ( V_31 , & V_29 -> V_167 ,
V_29 -> V_168 ,
V_169 ) ;
if ( ! V_34 ) {
switch ( F_47 ( V_29 -> V_168 ,
V_173 ) ) {
case 0x02 :
V_212 |= V_169 ;
break;
case 0x03 :
V_213 |= V_169 ;
break;
}
V_209 |= V_169 ;
} else if ( V_34 == - V_188 ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_22
L_23 ) ;
V_209 |= V_169 ;
} else if ( V_34 == - V_224 ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_24
L_25 ) ;
V_220 |= V_169 ;
} else {
F_52 ( & V_31 -> V_2 -> V_82 ,
L_26
L_27 , V_34 , V_169 ) ;
continue;
}
if ( F_50 ( V_31 , V_169 ) ) {
V_209 &= ~ V_169 ;
V_212 &= ~ V_169 ;
V_213 &= ~ V_169 ;
}
}
}
F_25 ( F_26 ( V_31 -> V_2 ) , V_43 ) ;
if ( ! V_31 -> V_211 . V_209 && V_209 ) {
V_31 -> V_211 . V_209 = V_209 ;
F_57 ( V_31 ) ;
} else
V_31 -> V_211 . V_209 |= V_209 ;
V_31 -> V_211 . V_212 |= V_212 ;
V_31 -> V_211 . V_213 |= V_213 ;
V_31 -> V_211 . V_223 |= V_220 ;
F_28 ( F_26 ( V_31 -> V_2 ) , V_43 ) ;
F_58 ( V_31 ) ;
if ( V_29 -> V_225 )
F_59 ( & V_226 ) ;
else
F_45 ( V_29 ) ;
}
static int F_60 ( struct V_30 * V_31 , T_2 V_169 )
{
struct V_219 * V_29 ;
V_29 = F_61 ( sizeof( * V_29 ) , V_227 | V_196 ) ;
if ( ! V_29 ) {
if ( F_62 ( & V_226 ) ) {
V_29 = V_228 ;
V_29 -> V_225 = 1 ;
} else
return - V_197 ;
} else {
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_29 -> V_225 = 0 ;
}
F_63 ( & V_29 -> V_221 , F_53 ) ;
F_64 ( V_31 ) ;
V_29 -> V_31 = V_31 ;
V_29 -> V_223 = V_169 ;
F_56 ( & V_29 -> V_221 ) ;
return 0 ;
}
static int F_65 ( struct V_30 * V_31 )
{
struct V_229 * V_230 ;
struct V_231 * V_232 ;
struct V_166 * V_167 ;
struct V_26 * V_45 ;
int V_34 ;
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
memset ( & V_33 -> V_232 , 0 , sizeof( struct V_231 ) ) ;
V_167 = F_41 ( V_175 , 1 + 1 ,
( sizeof( struct V_229 ) +
sizeof( struct V_231 ) ) ,
V_31 ) ;
if ( F_42 ( V_167 ) ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 , L_28
L_29 ) ;
return F_66 ( V_167 ) ;
}
V_167 -> V_119 = V_31 ;
V_167 -> V_176 = V_31 ;
V_167 -> V_177 = NULL ;
V_167 -> V_180 = 256 ;
V_167 -> V_178 = 10 * V_179 ;
V_230 = (struct V_229 * ) V_167 -> V_29 ;
memset ( V_230 , 0 , sizeof( struct V_229 ) ) ;
V_230 -> V_233 = V_234 ;
V_230 -> V_235 = 0x41 ;
V_45 = V_167 -> V_170 ;
V_45 -> V_54 = V_236 ;
V_45 -> V_42 = sizeof( struct V_229 ) ;
V_45 -> V_43 |= V_237 ;
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_230 ;
V_232 = (struct V_231 * ) ( V_230 + 1 ) ;
memset ( V_232 , 0 , sizeof( struct V_231 ) ) ;
V_45 ++ ;
V_45 -> V_54 = V_238 ;
V_45 -> V_42 = sizeof( struct V_231 ) ;
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_232 ;
V_167 -> V_181 = F_31 () ;
V_167 -> V_182 = V_183 ;
V_34 = F_43 ( V_167 ) ;
if ( V_34 == 0 ) {
V_230 = (struct V_229 * ) V_167 -> V_29 ;
V_232 = (struct V_231 * ) ( V_230 + 1 ) ;
memcpy ( & V_33 -> V_232 , V_232 ,
sizeof( struct V_231 ) ) ;
} else
F_52 ( & V_31 -> V_2 -> V_82 , L_30
L_31 , V_34 ) ;
F_44 ( V_167 , V_167 -> V_176 ) ;
return V_34 ;
}
static struct V_166 * F_67 ( struct V_30 * V_31 ,
int V_239 )
{
struct V_166 * V_167 ;
struct V_240 * V_241 ;
struct V_26 * V_45 ;
V_167 = F_41 ( V_175 , 1 ,
sizeof( struct V_240 ) ,
V_31 ) ;
if ( F_42 ( V_167 ) ) {
F_18 ( V_7 , V_31 , L_1 ,
L_32 ) ;
return V_167 ;
}
V_241 = (struct V_240 * ) V_167 -> V_29 ;
V_241 -> V_233 = V_242 ;
V_241 -> V_235 = 0xc0 ;
if ( V_239 ) {
V_241 -> V_235 |= 0x08 ;
V_241 -> V_243 [ 0 ] = 0x88 ;
}
V_45 = V_167 -> V_170 ;
V_45 -> V_54 = V_236 ;
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_241 ;
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
F_68 ( struct V_30 * V_31 , int V_239 )
{
struct V_166 * V_167 ;
int V_34 ;
V_167 = F_67 ( V_31 , V_239 ) ;
if ( F_42 ( V_167 ) )
return F_66 ( V_167 ) ;
V_34 = F_43 ( V_167 ) ;
if ( ! V_34 )
F_69 () ;
F_44 ( V_167 , V_167 -> V_176 ) ;
return V_34 ;
}
static void F_70 ( struct V_30 * V_31 )
{
int V_34 ;
struct V_32 * V_33 ;
int V_239 ;
if ( V_244 || V_245 )
V_239 = 0 ;
else
V_239 = 1 ;
V_34 = F_68 ( V_31 , V_239 ) ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
F_3 ( V_7 , V_31 -> V_2 , L_33
L_34 , V_33 -> V_134 . V_156 , V_34 ) ;
}
static T_3 F_71 ( struct V_30 * V_31 )
{
#if F_72 ( V_246 )
int V_247 , V_214 ;
int V_248 , V_249 , V_250 ;
struct V_32 * V_33 ;
if ( V_251 )
return 0 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_248 = V_252 . V_253 ;
V_249 = V_33 -> V_151 -> V_254 [ 7 ] & 0x04 ;
V_250 = V_33 -> V_232 . V_255 [ 40 ] & 0x80 ;
V_247 = V_248 && V_249 && V_250 ;
if ( ! V_247 )
return 0 ;
V_214 = F_51 ( V_31 -> V_2 , 0 ) ;
if ( V_214 < 0 ) {
F_52 ( & V_31 -> V_2 -> V_82 , L_35
L_36 ) ;
return 0 ;
} else
return V_214 * V_216 ;
#else
return 0 ;
#endif
}
static int
F_73 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
struct V_256 * V_177 ;
struct V_149 V_257 ;
int V_258 , V_34 , V_199 ;
int V_259 ;
unsigned long V_260 ;
if ( ! F_74 ( V_31 -> V_2 ) ) {
F_52 ( & V_31 -> V_2 -> V_82 ,
L_37 ) ;
return - V_261 ;
}
if ( ! F_75 ( V_31 -> V_2 ) ) {
F_76 ( & V_31 -> V_2 -> V_82 ,
L_38 ) ;
}
V_33 = (struct V_32 * ) V_31 -> V_33 ;
if ( ! V_33 ) {
V_33 = F_40 ( sizeof( * V_33 ) , V_195 | V_196 ) ;
if ( ! V_33 ) {
F_52 ( & V_31 -> V_2 -> V_82 ,
L_39
L_40 ) ;
return - V_197 ;
}
V_31 -> V_33 = ( void * ) V_33 ;
} else {
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
}
V_33 -> V_262 = - 1 ;
V_33 -> V_70 . V_69 = V_263 ;
V_33 -> V_70 . V_89 = 0 ;
V_34 = F_48 ( V_31 ) ;
if ( V_34 )
goto V_264;
V_31 -> V_265 = V_266 ;
if ( V_33 -> V_151 ) {
V_260 = 1 ;
for ( V_199 = 0 ; V_199 < V_33 -> V_151 -> V_267 . V_260 ; V_199 ++ )
V_260 = 10 * V_260 ;
V_260 = V_260 * V_33 -> V_151 -> V_267 . V_268 ;
if ( V_260 != 0 && V_260 <= V_269 )
V_31 -> V_265 = V_260 ;
}
V_34 = F_24 ( V_31 ) ;
if ( V_34 )
goto V_264;
F_29 ( V_31 , & V_257 ) ;
if ( V_257 . type == V_135 ) {
V_177 = F_77 () ;
if ( F_42 ( V_177 ) ) {
F_3 ( V_7 , V_31 -> V_2 , L_1 ,
L_41
L_42 ) ;
V_34 = F_66 ( V_177 ) ;
goto V_264;
}
V_31 -> V_177 = V_177 ;
V_177 -> V_270 = V_31 ;
}
V_258 = F_78 ( V_31 ) ;
if ( V_258 < 0 ) {
V_34 = V_258 ;
goto V_271;
}
if ( ! V_258 ) {
F_70 ( V_31 ) ;
F_79 ( V_31 ) ;
} else
F_80 ( V_31 ) ;
V_34 = F_48 ( V_31 ) ;
if ( V_34 )
goto V_272;
F_65 ( V_31 ) ;
V_34 = F_81 ( V_31 , V_175 ,
& V_33 -> V_35 , 64 ) ;
if ( V_34 ) {
F_3 ( V_7 , V_31 -> V_2 ,
L_43 , V_34 ) ;
goto V_272;
}
if ( ( V_31 -> V_232 & V_273 ) &&
! ( V_33 -> V_35 . V_36 . V_274 ) ) {
F_15 ( & V_31 -> V_2 -> V_82 , L_44
L_45 ) ;
V_34 = - V_128 ;
goto V_272;
}
if ( V_33 -> V_35 . V_275 == V_276 &&
V_33 -> V_35 . V_277 )
V_33 -> V_90 = V_33 -> V_35 . V_277 ;
else
V_33 -> V_90 = V_33 -> V_35 . V_275 ;
V_33 -> V_215 = F_71 ( V_31 ) ;
V_259 = F_82 ( V_31 ) ;
if ( V_259 )
F_32 ( V_278 , & V_31 -> V_43 ) ;
F_76 ( & V_31 -> V_2 -> V_82 , L_46
L_47 ,
V_33 -> V_35 . V_20 ,
V_33 -> V_35 . V_279 ,
V_33 -> V_35 . V_84 ,
V_33 -> V_35 . V_280 . V_281 ,
V_33 -> V_90 ,
V_33 -> V_35 . V_86 ,
V_33 -> V_35 . V_282 ,
V_259 ? L_48 : L_49 ) ;
return 0 ;
V_272:
F_83 ( V_31 ) ;
V_271:
F_84 ( V_31 -> V_177 ) ;
V_31 -> V_177 = NULL ;
V_264:
F_45 ( V_33 -> V_201 ) ;
F_45 ( V_31 -> V_33 ) ;
V_31 -> V_33 = NULL ;
return V_34 ;
}
static void F_85 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
F_83 ( V_31 ) ;
V_33 -> V_130 = NULL ;
V_33 -> V_159 = NULL ;
V_33 -> V_163 = NULL ;
V_33 -> V_151 = NULL ;
V_33 -> V_200 = 0 ;
F_45 ( V_33 -> V_201 ) ;
V_33 -> V_201 = NULL ;
}
static struct V_166 *
F_86 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
struct V_283 * V_284 ;
struct V_140 * V_285 ;
struct V_166 * V_167 ;
struct V_26 * V_45 ;
int V_286 , V_287 ;
int V_199 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_286 = 8 ;
V_287 = sizeof( struct V_28 ) + 2 * sizeof( struct V_140 ) ;
V_167 = F_41 ( V_175 , V_286 , V_287 , V_31 ) ;
if ( F_42 ( V_167 ) )
return V_167 ;
V_45 = V_167 -> V_170 ;
F_13 ( V_45 ++ , V_167 -> V_29 , 0 , 2 ,
V_65 , V_31 ) ;
V_285 = V_167 -> V_29 + sizeof( struct V_28 ) ;
V_45 [ - 1 ] . V_43 |= V_237 ;
V_126 ( V_45 ++ , V_285 ++ , 0 , 0 , 4 ,
V_65 , V_31 , 0 ) ;
V_284 = V_33 -> V_288 ;
for ( V_199 = 0 ; V_199 < 4 ; V_199 ++ ) {
V_45 [ - 1 ] . V_43 |= V_237 ;
V_45 -> V_54 = V_65 ;
V_45 -> V_43 = 0 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_284 ;
V_45 ++ ;
V_284 ++ ;
}
V_45 [ - 1 ] . V_43 |= V_237 ;
V_126 ( V_45 ++ , V_285 ++ , 2 , 0 , 1 ,
V_65 , V_31 , 0 ) ;
V_45 [ - 1 ] . V_43 |= V_237 ;
V_45 -> V_54 = V_65 ;
V_45 -> V_43 = 0 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_284 ;
V_167 -> V_177 = NULL ;
V_167 -> V_119 = V_31 ;
V_167 -> V_176 = V_31 ;
V_167 -> V_180 = 255 ;
V_167 -> V_181 = F_31 () ;
V_167 -> V_182 = V_183 ;
return V_167 ;
}
static int F_87 ( struct V_166 * V_289 )
{
char * V_290 ;
if ( V_289 -> V_182 == V_185 )
return V_291 ;
else if ( V_289 -> V_182 == V_292 ||
V_289 -> V_182 == V_293 ) {
V_290 = F_88 ( & V_289 -> V_294 ) ;
if ( V_290 && ( V_290 [ 1 ] & V_295 ) )
return V_296 ;
else
return V_297 ;
} else
return V_297 ;
}
static void F_89 ( struct V_166 * V_289 ,
void * V_29 )
{
struct V_32 * V_33 ;
struct V_30 * V_31 ;
V_31 = V_289 -> V_119 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_33 -> V_262 = F_87 ( V_289 ) ;
F_44 ( V_289 , V_31 ) ;
F_90 ( V_31 ) ;
}
static int F_91 ( struct V_256 * V_177 )
{
struct V_166 * V_289 ;
V_289 = F_86 ( V_177 -> V_270 ) ;
if ( F_42 ( V_289 ) )
return F_66 ( V_289 ) ;
V_289 -> V_191 = F_89 ;
V_289 -> V_298 = NULL ;
V_289 -> V_178 = 5 * V_179 ;
F_37 ( V_189 , & V_289 -> V_43 ) ;
V_289 -> V_180 = 0 ;
F_92 ( V_289 ) ;
return - V_224 ;
}
static int F_93 ( struct V_256 * V_177 )
{
struct V_30 * V_31 ;
struct V_32 * V_33 ;
struct V_283 * V_288 ;
unsigned int V_299 , V_145 ;
int V_182 , V_199 ;
struct V_166 * V_289 ;
V_31 = V_177 -> V_270 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_182 = V_33 -> V_262 ;
V_33 -> V_262 = - 1 ;
if ( V_182 == V_297 ) {
V_289 = F_86 ( V_31 ) ;
F_43 ( V_289 ) ;
V_182 = F_87 ( V_289 ) ;
F_44 ( V_289 , V_31 ) ;
}
if ( V_31 -> V_232 & V_273 ) {
V_177 -> V_300 = V_301 ;
V_145 = V_302 ;
V_177 -> V_303 = 3 ;
goto V_304;
}
if ( V_182 == V_296 ) {
F_52 ( & V_31 -> V_2 -> V_82 , L_50 ) ;
return - V_305 ;
} else if ( V_182 == V_297 ) {
F_15 ( & V_31 -> V_2 -> V_82 ,
L_51
L_52 ) ;
return - V_261 ;
}
V_33 -> V_85 = 1 ;
V_288 = NULL ;
for ( V_199 = 0 ; V_199 < 3 ; V_199 ++ ) {
if ( V_33 -> V_288 [ V_199 ] . V_16 != 4 ||
V_33 -> V_288 [ V_199 ] . V_17 != F_23 ( V_199 ) - 4 ) {
V_33 -> V_85 = 0 ;
break;
}
}
if ( V_199 == 3 )
V_288 = & V_33 -> V_288 [ 4 ] ;
if ( V_33 -> V_85 == 0 ) {
for ( V_199 = 0 ; V_199 < 5 ; V_199 ++ ) {
if ( ( V_33 -> V_288 [ V_199 ] . V_16 != 0 ) ||
( V_33 -> V_288 [ V_199 ] . V_17 !=
V_33 -> V_288 [ 0 ] . V_17 ) )
break;
}
if ( V_199 == 5 )
V_288 = & V_33 -> V_288 [ 0 ] ;
} else {
if ( V_33 -> V_288 [ 3 ] . V_117 == 1 )
F_52 ( & V_31 -> V_2 -> V_82 ,
L_53 ) ;
}
if ( V_288 != NULL && V_288 -> V_16 == 0 ) {
if ( F_94 ( V_288 -> V_17 ) == 0 )
V_177 -> V_300 = V_288 -> V_17 ;
}
if ( V_177 -> V_300 == 0 ) {
F_52 ( & V_31 -> V_2 -> V_82 ,
L_54 ) ;
return - V_305 ;
}
V_177 -> V_303 = 0 ;
for ( V_299 = 512 ; V_299 < V_177 -> V_300 ; V_299 = V_299 << 1 )
V_177 -> V_303 ++ ;
V_145 = F_9 ( & V_33 -> V_35 , 0 , V_177 -> V_300 ) ;
V_304:
V_177 -> V_306 = ( V_33 -> V_90 *
V_33 -> V_35 . V_86 *
V_145 ) ;
F_76 ( & V_31 -> V_2 -> V_82 ,
L_55
L_56 , ( V_177 -> V_300 >> 10 ) ,
( ( V_33 -> V_90 *
V_33 -> V_35 . V_86 *
V_145 * ( V_177 -> V_300 >> 9 ) ) >> 1 ) ,
( ( V_145 * V_177 -> V_300 ) >> 10 ) ,
V_33 -> V_85 ?
L_57 : L_58 ) ;
return 0 ;
}
static int F_95 ( struct V_256 * V_177 )
{
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_177 -> V_270 -> V_33 ;
if ( V_33 -> V_262 < 0 )
return F_91 ( V_177 ) ;
else
return F_93 ( V_177 ) ;
}
static int F_96 ( struct V_30 * V_31 )
{
return F_97 ( V_31 ) ;
}
static int F_98 ( struct V_30 * V_31 )
{
F_99 ( & V_31 -> V_307 ) ;
return F_100 ( V_31 ) ;
}
static int
F_101 ( struct V_256 * V_177 , struct V_308 * V_22 )
{
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_177 -> V_270 -> V_33 ;
if ( F_94 ( V_177 -> V_300 ) == 0 ) {
V_22 -> V_309 = F_9 ( & V_33 -> V_35 ,
0 , V_177 -> V_300 ) ;
}
V_22 -> V_310 = V_33 -> V_35 . V_275 ;
V_22 -> V_51 = V_33 -> V_35 . V_86 ;
return 0 ;
}
static struct V_166 *
F_102 ( struct V_30 * V_31 ,
struct V_311 * V_312 )
{
struct V_32 * V_33 ;
struct V_166 * V_313 ;
struct V_283 * V_314 ;
struct V_26 * V_45 ;
void * V_29 ;
int V_315 ;
struct V_21 V_316 ;
int V_286 , V_287 ;
int V_199 ;
int V_317 = 0 ;
int V_318 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_315 = F_9 ( & V_33 -> V_35 , 0 , V_312 -> V_121 ) ;
F_10 ( & V_316 ,
V_312 -> V_319 / V_33 -> V_35 . V_86 ,
V_312 -> V_319 % V_33 -> V_35 . V_86 ) ;
if ( V_312 -> V_319 >=
( V_33 -> V_90 * V_33 -> V_35 . V_86 ) ) {
F_52 ( & V_31 -> V_2 -> V_82 , L_59
L_60 , V_312 -> V_319 ) ;
return F_103 ( - V_128 ) ;
}
if ( V_312 -> V_319 > V_312 -> V_320 ) {
F_52 ( & V_31 -> V_2 -> V_82 , L_61
L_62 , V_312 -> V_319 ) ;
return F_103 ( - V_128 ) ;
}
if ( F_94 ( V_312 -> V_121 ) != 0 ) {
F_52 ( & V_31 -> V_2 -> V_82 ,
L_63 ,
V_312 -> V_121 ) ;
return F_103 ( - V_128 ) ;
}
if ( V_312 -> V_317 & 0x10 ) {
V_318 = 0 ;
V_317 = V_312 -> V_317 & ~ 0x10 ;
} else {
V_318 = 1 ;
V_317 = V_312 -> V_317 ;
}
switch ( V_317 ) {
case 0x00 :
case 0x08 :
V_286 = 2 + V_315 ;
V_287 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
V_315 * sizeof( struct V_283 ) ;
break;
case 0x01 :
case 0x09 :
V_286 = 3 + V_315 ;
V_287 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
sizeof( struct V_283 ) +
V_315 * sizeof( struct V_283 ) ;
break;
case 0x04 :
case 0x0c :
V_286 = 3 ;
V_287 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
sizeof( struct V_283 ) ;
break;
default:
F_52 ( & V_31 -> V_2 -> V_82 , L_64
L_65 , V_312 -> V_317 ) ;
return F_103 ( - V_128 ) ;
}
V_313 = F_41 ( V_175 , V_286 , V_287 , V_31 ) ;
if ( F_42 ( V_313 ) )
return V_313 ;
V_29 = V_313 -> V_29 ;
V_45 = V_313 -> V_170 ;
switch ( V_317 & ~ 0x08 ) {
case 0x00 :
F_13 ( V_45 ++ , (struct V_28 * ) V_29 ,
V_312 -> V_319 , V_312 -> V_319 ,
V_75 , V_31 ) ;
if ( V_318 )
( (struct V_28 * ) V_29 ) -> V_38 |= 0x04 ;
V_29 += sizeof( struct V_28 ) ;
V_45 [ - 1 ] . V_43 |= V_237 ;
V_126 ( V_45 ++ , (struct V_140 * ) V_29 ,
V_312 -> V_319 , 0 , V_315 ,
V_75 , V_31 ,
V_312 -> V_121 ) ;
V_29 += sizeof( struct V_140 ) ;
break;
case 0x01 :
F_13 ( V_45 ++ , (struct V_28 * ) V_29 ,
V_312 -> V_319 , V_312 -> V_319 ,
V_80 ,
V_31 ) ;
V_29 += sizeof( struct V_28 ) ;
V_45 [ - 1 ] . V_43 |= V_237 ;
V_126 ( V_45 ++ , (struct V_140 * ) V_29 ,
V_312 -> V_319 , 0 , V_315 + 1 ,
V_80 , V_31 ,
V_31 -> V_177 -> V_300 ) ;
V_29 += sizeof( struct V_140 ) ;
break;
case 0x04 :
F_13 ( V_45 ++ , (struct V_28 * ) V_29 ,
V_312 -> V_319 , V_312 -> V_319 ,
V_75 , V_31 ) ;
V_29 += sizeof( struct V_28 ) ;
V_45 [ - 1 ] . V_43 |= V_237 ;
V_126 ( V_45 ++ , (struct V_140 * ) V_29 ,
V_312 -> V_319 , 0 , 1 ,
V_75 , V_31 , 8 ) ;
V_29 += sizeof( struct V_140 ) ;
break;
}
if ( V_317 & 0x01 ) {
V_314 = (struct V_283 * ) V_29 ;
V_29 += sizeof( struct V_283 ) ;
V_314 -> V_23 = V_316 . V_23 ;
V_314 -> V_24 = V_316 . V_24 ;
V_314 -> V_117 = 0 ;
V_314 -> V_16 = 0 ;
V_314 -> V_17 = 8 ;
V_45 [ - 1 ] . V_43 |= V_237 ;
V_45 -> V_54 = V_80 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_314 ;
V_45 ++ ;
}
if ( ( V_317 & ~ 0x08 ) & 0x04 ) {
V_314 = (struct V_283 * ) V_29 ;
V_29 += sizeof( struct V_283 ) ;
V_314 -> V_23 = V_316 . V_23 ;
V_314 -> V_24 = V_316 . V_24 ;
V_314 -> V_117 = 1 ;
V_314 -> V_16 = 0 ;
V_314 -> V_17 = 0 ;
V_45 [ - 1 ] . V_43 |= V_237 ;
V_45 -> V_54 = V_75 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_314 ;
} else {
for ( V_199 = 0 ; V_199 < V_315 ; V_199 ++ ) {
V_314 = (struct V_283 * ) V_29 ;
V_29 += sizeof( struct V_283 ) ;
V_314 -> V_23 = V_316 . V_23 ;
V_314 -> V_24 = V_316 . V_24 ;
V_314 -> V_117 = V_199 + 1 ;
V_314 -> V_16 = 0 ;
V_314 -> V_17 = V_312 -> V_121 ;
if ( ( V_317 & 0x08 ) &&
V_312 -> V_319 == 0 ) {
if ( V_199 < 3 ) {
V_314 -> V_16 = 4 ;
V_314 -> V_17 = V_147 [ V_199 ] - 4 ;
}
}
if ( ( V_317 & 0x08 ) &&
V_312 -> V_319 == 1 ) {
V_314 -> V_16 = 44 ;
V_314 -> V_17 = V_148 - 44 ;
}
V_45 [ - 1 ] . V_43 |= V_237 ;
V_45 -> V_54 = V_75 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_42 = 8 ;
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_314 ;
V_45 ++ ;
}
}
V_313 -> V_119 = V_31 ;
V_313 -> V_176 = V_31 ;
V_313 -> V_180 = 256 ;
V_313 -> V_181 = F_31 () ;
V_313 -> V_182 = V_183 ;
return V_313 ;
}
static void F_104 ( struct V_166 * V_167 )
{
V_167 -> V_182 = V_183 ;
if ( V_167 -> V_177 && ( V_167 -> V_119 != V_167 -> V_177 -> V_270 ) ) {
F_105 ( V_167 ) ;
V_167 -> V_119 = V_167 -> V_177 -> V_270 ;
V_167 -> V_169 = V_167 -> V_177 -> V_270 -> V_211 . V_209 ;
}
}
static T_5
F_106 ( struct V_166 * V_167 )
{
struct V_30 * V_31 = (struct V_30 * ) V_167 -> V_119 ;
struct V_1 * V_2 = V_31 -> V_2 ;
switch ( V_2 -> V_321 . V_84 ) {
case 0x3990 :
case 0x2105 :
case 0x2107 :
case 0x1750 :
return V_322 ;
case 0x9343 :
case 0x3880 :
default:
return V_323 ;
}
}
static T_5
F_107 ( struct V_166 * V_167 )
{
return V_324 ;
}
static void F_108 ( struct V_30 * V_31 ,
struct V_166 * V_167 ,
struct V_294 * V_294 )
{
char V_66 ;
char * V_290 = NULL ;
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_66 = V_325 | V_326 | V_327 ;
if ( ( F_109 ( & V_294 -> V_328 ) & V_66 ) == V_66 ) {
if ( ! V_31 -> V_177 && V_33 -> V_329 &&
! F_55 ( V_330 , & V_31 -> V_43 ) &&
! F_55 ( V_222 , & V_31 -> V_43 ) ) {
F_100 ( V_31 ) ;
F_110 ( V_31 ) ;
}
F_111 ( V_31 ) ;
return;
}
V_290 = F_88 ( V_294 ) ;
if ( ! V_290 )
return;
if ( ( V_290 [ 27 ] & V_331 ) && ( V_290 [ 7 ] == 0x0D ) &&
( F_109 ( & V_294 -> V_328 ) & V_332 ) ) {
F_112 ( V_31 , V_294 ) ;
return;
}
if ( ! V_167 && ! ( V_290 [ 27 ] & V_331 ) &&
( ( V_290 [ 6 ] & V_333 ) == V_333 ) ) {
F_113 ( V_31 , V_290 ) ;
return;
}
if ( V_31 -> V_177 && ( V_290 [ 27 ] & V_331 ) &&
( V_290 [ 7 ] == 0x3F ) &&
( F_109 ( & V_294 -> V_328 ) & V_332 ) &&
F_55 ( V_334 , & V_31 -> V_43 ) ) {
if ( V_31 -> V_232 & V_335 )
F_32 ( V_336 , & V_31 -> V_43 ) ;
F_37 ( V_334 , & V_31 -> V_43 ) ;
F_15 ( & V_31 -> V_2 -> V_82 ,
L_66 ) ;
}
}
static struct V_166 * F_114 (
struct V_30 * V_119 ,
struct V_256 * V_177 ,
struct V_337 * V_338 ,
T_6 V_339 ,
T_6 V_340 ,
T_6 V_341 ,
T_6 V_342 ,
unsigned int V_343 ,
unsigned int V_344 ,
unsigned int V_145 ,
unsigned int V_121 )
{
struct V_32 * V_33 ;
unsigned long * V_345 ;
struct V_140 * V_285 ;
struct V_166 * V_167 ;
struct V_26 * V_45 ;
struct V_346 V_347 ;
struct V_348 * V_349 ;
char * V_350 ;
unsigned int V_351 ;
int V_42 , V_352 , V_286 , V_287 ;
T_6 V_146 ;
unsigned char V_48 , V_353 ;
int V_354 ;
struct V_30 * V_118 ;
V_118 = V_177 -> V_270 ;
V_33 = (struct V_32 * ) V_118 -> V_33 ;
if ( F_115 ( V_338 ) == V_355 )
V_48 = V_60 ;
else if ( F_115 ( V_338 ) == V_356 )
V_48 = V_72 ;
else
return F_103 ( - V_128 ) ;
V_42 = 0 ;
V_352 = 0 ;
F_116 (bv, req, iter) {
if ( V_349 -> V_357 & ( V_121 - 1 ) )
return F_103 ( - V_128 ) ;
V_42 += V_349 -> V_357 >> ( V_177 -> V_303 + 9 ) ;
#if F_72 ( V_246 )
if ( F_117 ( F_118 ( V_349 -> V_358 ) , V_349 -> V_357 ) )
V_352 += V_349 -> V_357 >> ( V_177 -> V_303 + 9 ) ;
#endif
}
if ( V_42 != V_340 - V_339 + 1 )
return F_103 ( - V_128 ) ;
V_354 = V_33 -> V_232 . V_255 [ 8 ] & 0x01 ;
if ( V_354 ) {
V_286 = 2 + V_42 ;
V_287 = sizeof( struct V_93 ) +
sizeof( struct V_140 ) +
V_352 * sizeof( unsigned long ) ;
} else {
V_286 = 2 + V_42 ;
V_287 = sizeof( struct V_28 ) +
sizeof( struct V_140 ) +
V_352 * sizeof( unsigned long ) ;
}
if ( V_33 -> V_85 && V_339 < 2 * V_145 ) {
if ( V_340 >= 2 * V_145 )
V_42 = 2 * V_145 - V_339 ;
V_286 += V_42 ;
V_287 += V_42 * sizeof( struct V_140 ) ;
}
V_167 = F_41 ( V_175 , V_286 , V_287 ,
V_119 ) ;
if ( F_42 ( V_167 ) )
return V_167 ;
V_45 = V_167 -> V_170 ;
if ( V_354 ) {
if ( F_21 ( V_45 ++ , V_167 -> V_29 , V_341 ,
V_342 , V_48 , V_118 , V_119 ) == - V_224 ) {
F_44 ( V_167 , V_119 ) ;
return F_103 ( - V_224 ) ;
}
V_345 = ( unsigned long * ) ( V_167 -> V_29 +
sizeof( struct V_93 ) ) ;
} else {
if ( F_13 ( V_45 ++ , V_167 -> V_29 , V_341 ,
V_342 , V_48 , V_119 ) == - V_224 ) {
F_44 ( V_167 , V_119 ) ;
return F_103 ( - V_224 ) ;
}
V_345 = ( unsigned long * ) ( V_167 -> V_29 +
sizeof( struct V_28 ) ) ;
}
V_285 = (struct V_140 * ) ( V_345 + V_352 ) ;
V_146 = V_339 ;
if ( V_33 -> V_85 == 0 || V_146 > 2 * V_145 ) {
V_45 [ - 1 ] . V_43 |= V_237 ;
V_126 ( V_45 ++ , V_285 ++ , V_341 , V_343 + 1 ,
V_340 - V_146 + 1 , V_48 , V_118 , V_121 ) ;
}
F_116 (bv, req, iter) {
V_350 = F_118 ( V_349 -> V_358 ) + V_349 -> V_359 ;
if ( V_360 ) {
char * V_361 = F_119 ( V_360 ,
V_196 | V_362 ) ;
if ( V_361 && F_115 ( V_338 ) == V_356 )
memcpy ( V_361 + V_349 -> V_359 , V_350 , V_349 -> V_357 ) ;
if ( V_361 )
V_350 = V_361 + V_349 -> V_359 ;
}
for ( V_351 = 0 ; V_351 < V_349 -> V_357 ; V_351 += V_121 ) {
T_6 V_363 = V_146 ;
unsigned int V_364 = F_120 ( V_363 , V_145 ) ;
V_353 = V_48 ;
V_42 = V_121 ;
if ( V_33 -> V_85 && V_146 < 2 * V_145 ) {
if ( F_22 ( V_145 , V_146 ) ) {
V_353 |= 0x8 ;
V_42 = F_23 ( V_146 ) ;
if ( V_42 < V_121 &&
F_115 ( V_338 ) == V_355 )
memset ( V_350 + V_42 , 0xe5 ,
V_121 - V_42 ) ;
}
V_45 [ - 1 ] . V_43 |= V_237 ;
V_126 ( V_45 ++ , V_285 ++ ,
V_363 , V_364 + 1 ,
1 , V_353 , V_118 , V_42 ) ;
}
if ( V_33 -> V_85 && V_146 == 2 * V_145 ) {
V_45 [ - 1 ] . V_43 |= V_237 ;
V_126 ( V_45 ++ , V_285 ++ ,
V_363 , V_364 + 1 ,
V_340 - V_146 + 1 ,
V_48 , V_118 , V_42 ) ;
}
V_45 [ - 1 ] . V_43 |= V_237 ;
V_45 -> V_54 = V_353 ;
V_45 -> V_42 = V_42 ;
if ( F_117 ( V_350 , V_121 ) ) {
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_345 ;
V_45 -> V_43 = V_365 ;
V_345 = F_121 ( V_345 , V_350 , V_121 ) ;
} else {
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_350 ;
V_45 -> V_43 = 0 ;
}
V_45 ++ ;
V_350 += V_121 ;
V_146 ++ ;
}
}
if ( F_122 ( V_338 ) ||
V_177 -> V_270 -> V_232 & V_366 )
F_32 ( V_367 , & V_167 -> V_43 ) ;
V_167 -> V_119 = V_119 ;
V_167 -> V_176 = V_119 ;
V_167 -> V_177 = V_177 ;
V_167 -> V_178 = V_119 -> V_265 * V_179 ;
V_167 -> V_169 = V_119 -> V_211 . V_213 ;
V_167 -> V_180 = 256 ;
V_167 -> V_181 = F_31 () ;
V_167 -> V_182 = V_183 ;
return V_167 ;
}
static struct V_166 * F_123 (
struct V_30 * V_119 ,
struct V_256 * V_177 ,
struct V_337 * V_338 ,
T_6 V_339 ,
T_6 V_340 ,
T_6 V_341 ,
T_6 V_342 ,
unsigned int V_343 ,
unsigned int V_344 ,
unsigned int V_145 ,
unsigned int V_121 )
{
unsigned long * V_345 ;
struct V_166 * V_167 ;
struct V_26 * V_45 ;
struct V_346 V_347 ;
struct V_348 * V_349 ;
char * V_350 , * V_368 ;
unsigned int V_352 , V_286 , V_287 ;
unsigned int V_100 ;
T_6 V_146 ;
unsigned char V_48 ;
struct V_30 * V_118 ;
unsigned int V_369 , V_42 , V_370 ;
unsigned int V_371 , V_372 , V_373 , V_374 ;
unsigned char V_375 , V_376 ;
T_6 V_363 ;
unsigned int V_364 ;
V_118 = V_177 -> V_270 ;
if ( F_115 ( V_338 ) == V_355 )
V_48 = V_113 ;
else if ( F_115 ( V_338 ) == V_356 )
V_48 = V_111 ;
else
return F_103 ( - V_128 ) ;
V_352 = V_340 - V_339 + 1 ;
V_369 = V_342 - V_341 + 1 ;
V_286 = 1 + V_369 ;
V_287 = sizeof( struct V_93 ) +
V_352 * sizeof( unsigned long long ) ;
V_167 = F_41 ( V_175 , V_286 , V_287 ,
V_119 ) ;
if ( F_42 ( V_167 ) )
return V_167 ;
V_45 = V_167 -> V_170 ;
if ( V_341 == V_342 )
V_100 = V_344 - V_343 + 1 ;
else
V_100 = V_344 + 1 ;
V_100 *= V_121 ;
if ( F_20 ( V_45 ++ , V_167 -> V_29 , V_341 ,
V_342 , V_48 , V_118 , V_119 ,
1 , V_343 + 1 ,
V_369 , V_121 ,
V_100 ) == - V_224 ) {
F_44 ( V_167 , V_119 ) ;
return F_103 ( - V_224 ) ;
}
V_345 = ( unsigned long * ) ( V_167 -> V_29 + sizeof( struct V_93 ) ) ;
V_146 = V_339 ;
V_375 = 1 ;
V_376 = 0 ;
V_374 = 0 ;
V_368 = NULL ;
V_371 = 0 ;
F_116 (bv, req, iter) {
V_350 = F_118 ( V_349 -> V_358 ) + V_349 -> V_359 ;
V_372 = V_349 -> V_357 ;
while ( V_372 ) {
if ( V_375 ) {
V_363 = V_146 ;
V_364 = F_120 ( V_363 , V_145 ) ;
V_370 = V_145 - V_364 ;
V_42 = F_124 ( ( V_340 - V_146 + 1 ) ,
( T_6 ) V_370 ) ;
V_374 = V_42 * V_121 ;
V_45 [ - 1 ] . V_43 |= V_237 ;
V_45 -> V_54 = V_48 ;
V_45 -> V_42 = V_374 ;
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_345 ;
V_45 -> V_43 = V_365 ;
V_45 ++ ;
V_146 += V_42 ;
V_375 = 0 ;
if ( ! V_368 )
V_368 = V_350 ;
}
if ( ! V_368 ) {
if ( F_14 ( V_350 ) & ( V_377 - 1 ) ) {
F_44 ( V_167 , V_119 ) ;
return F_103 ( - V_378 ) ;
} else
V_368 = V_350 ;
}
if ( ( V_368 + V_371 ) != V_350 ) {
F_44 ( V_167 , V_119 ) ;
return F_103 ( - V_378 ) ;
}
V_373 = F_124 ( V_372 , V_374 ) ;
V_372 -= V_373 ;
V_350 += V_373 ;
V_371 += V_373 ;
V_374 -= V_373 ;
if ( ! ( F_14 ( V_368 + V_371 ) & ( V_377 - 1 ) ) )
V_376 = 1 ;
if ( ! V_374 ) {
V_375 = 1 ;
V_376 = 1 ;
}
if ( V_376 ) {
V_345 = F_121 ( V_345 , V_368 ,
V_371 ) ;
V_368 = NULL ;
V_371 = 0 ;
V_376 = 0 ;
}
}
}
if ( F_122 ( V_338 ) ||
V_177 -> V_270 -> V_232 & V_366 )
F_32 ( V_367 , & V_167 -> V_43 ) ;
V_167 -> V_119 = V_119 ;
V_167 -> V_176 = V_119 ;
V_167 -> V_177 = V_177 ;
V_167 -> V_178 = V_119 -> V_265 * V_179 ;
V_167 -> V_169 = V_119 -> V_211 . V_213 ;
V_167 -> V_180 = 256 ;
V_167 -> V_181 = F_31 () ;
V_167 -> V_182 = V_183 ;
return V_167 ;
}
static int F_125 ( struct V_379 * V_379 ,
unsigned int V_46 , unsigned int V_47 , int V_48 ,
struct V_30 * V_118 ,
struct V_30 * V_119 ,
unsigned int V_98 , int V_42 ,
unsigned int V_121 ,
unsigned int V_380 ,
unsigned int V_100 ,
unsigned int V_145 )
{
struct V_93 V_94 ;
struct V_32 * V_122 , * V_123 ;
struct V_28 * V_124 ;
struct V_97 * V_125 ;
struct V_381 * V_381 ;
T_3 V_49 , V_50 ;
T_4 V_51 , V_52 , V_53 ;
T_7 V_382 ;
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
V_125 -> V_104 . V_383 = 0x01 ;
V_382 = V_384 ;
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
V_125 -> V_104 . V_383 = 0x2 ;
V_382 = V_127 ;
break;
default:
F_18 ( V_114 , V_118 ,
L_67 , V_48 ) ;
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
V_124 -> V_385 = 0x20 ;
V_124 -> V_386 = V_145 ;
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
V_125 -> V_104 . V_387 = 1 ;
V_125 -> V_104 . V_388 = 1 ;
V_125 -> V_106 = V_100 ;
V_125 -> V_389 = V_48 ;
V_125 -> V_42 = V_42 ;
V_125 -> V_101 = V_101 ;
F_10 ( & V_125 -> V_115 , V_49 , V_52 ) ;
V_125 -> V_116 . V_23 = V_125 -> V_115 . V_23 ;
V_125 -> V_116 . V_24 = V_125 -> V_115 . V_24 ;
V_125 -> V_116 . V_117 = V_98 ;
V_381 = F_126 ( V_379 , V_382 , 0 ,
& V_94 , sizeof( V_94 ) , V_380 ) ;
return F_42 ( V_381 ) ? F_66 ( V_381 ) : 0 ;
}
static struct V_166 * F_127 (
struct V_30 * V_119 ,
struct V_256 * V_177 ,
struct V_337 * V_338 ,
T_6 V_339 ,
T_6 V_340 ,
T_6 V_341 ,
T_6 V_342 ,
unsigned int V_343 ,
unsigned int V_344 ,
unsigned int V_145 ,
unsigned int V_121 )
{
struct V_166 * V_167 ;
struct V_346 V_347 ;
struct V_348 * V_349 ;
char * V_350 ;
unsigned int V_369 , V_390 ;
unsigned char V_48 ;
struct V_30 * V_118 ;
unsigned int V_100 ;
struct V_379 * V_379 ;
struct V_391 * V_392 = NULL ;
int V_393 ;
T_8 V_394 ;
T_7 V_395 ;
unsigned int V_372 , V_373 , V_374 ;
unsigned char V_375 ;
T_6 V_146 , V_363 ;
unsigned int V_396 ;
unsigned int V_42 , V_370 ;
V_118 = V_177 -> V_270 ;
if ( F_115 ( V_338 ) == V_355 ) {
V_48 = V_113 ;
V_393 = V_397 ;
} else if ( F_115 ( V_338 ) == V_356 ) {
V_48 = V_111 ;
V_393 = V_398 ;
} else
return F_103 ( - V_128 ) ;
V_369 = V_342 - V_341 + 1 ;
V_390 = 0 ;
F_116 (bv, req, iter) {
++ V_390 ;
}
if ( F_115 ( V_338 ) == V_356 )
V_390 += ( V_342 - V_341 ) ;
V_394 = F_128 ( 0 , V_390 , 0 ) ;
V_167 = F_41 ( V_175 , 0 , V_394 , V_119 ) ;
if ( F_42 ( V_167 ) )
return V_167 ;
if ( V_341 == V_342 )
V_100 = V_344 - V_343 + 1 ;
else
V_100 = V_344 + 1 ;
V_100 *= V_121 ;
V_379 = F_129 ( V_167 -> V_29 , V_394 , V_393 , 0 , V_390 , 0 ) ;
if ( F_42 ( V_379 ) ) {
F_44 ( V_167 , V_119 ) ;
return F_103 ( - V_128 ) ;
}
V_167 -> V_170 = F_130 ( V_379 ) ;
if ( F_125 ( V_379 , V_341 , V_342 ,
V_48 , V_118 , V_119 ,
V_343 + 1 ,
V_369 , V_121 ,
( V_340 - V_339 + 1 ) * V_121 ,
V_100 , V_145 ) == - V_224 ) {
F_44 ( V_167 , V_119 ) ;
return F_103 ( - V_224 ) ;
}
V_374 = 0 ;
if ( F_115 ( V_338 ) == V_356 ) {
V_375 = 1 ;
V_146 = V_339 ;
F_116 (bv, req, iter) {
V_350 = F_118 ( V_349 -> V_358 ) + V_349 -> V_359 ;
V_372 = V_349 -> V_357 ;
while ( V_372 ) {
if ( V_375 ) {
V_363 = V_146 ;
V_396 = F_120 ( V_363 , V_145 ) ;
V_370 = V_145 - V_396 ;
V_42 = F_124 ( ( V_340 - V_146 + 1 ) ,
( T_6 ) V_370 ) ;
V_374 = V_42 * V_121 ;
V_146 += V_42 ;
V_375 = 0 ;
}
V_373 = F_124 ( V_372 , V_374 ) ;
V_372 -= V_373 ;
V_374 -= V_373 ;
if ( ! V_374 ) {
V_375 = 1 ;
V_395 = V_399 ;
} else
V_395 = 0 ;
V_392 = F_131 ( V_379 , V_395 ,
V_350 , V_373 ) ;
if ( F_42 ( V_392 ) )
return F_103 ( - V_128 ) ;
V_350 += V_373 ;
}
}
} else {
F_116 (bv, req, iter) {
V_350 = F_118 ( V_349 -> V_358 ) + V_349 -> V_359 ;
V_392 = F_131 ( V_379 , 0x00 ,
V_350 , V_349 -> V_357 ) ;
if ( F_42 ( V_392 ) )
return F_103 ( - V_128 ) ;
}
}
V_392 -> V_43 |= V_400 ;
V_392 -> V_43 &= ~ V_399 ;
F_132 ( V_379 ) ;
if ( F_122 ( V_338 ) ||
V_177 -> V_270 -> V_232 & V_366 )
F_32 ( V_367 , & V_167 -> V_43 ) ;
V_167 -> V_401 = 1 ;
V_167 -> V_119 = V_119 ;
V_167 -> V_176 = V_119 ;
V_167 -> V_177 = V_177 ;
V_167 -> V_178 = V_119 -> V_265 * V_179 ;
V_167 -> V_169 = V_119 -> V_211 . V_213 ;
V_167 -> V_180 = 256 ;
V_167 -> V_181 = F_31 () ;
V_167 -> V_182 = V_183 ;
return V_167 ;
}
static struct V_166 * F_133 ( struct V_30 * V_119 ,
struct V_256 * V_177 ,
struct V_337 * V_338 )
{
int V_402 , V_403 ;
int V_354 ;
int V_404 ;
struct V_32 * V_33 ;
struct V_30 * V_118 ;
T_6 V_339 , V_340 ;
T_6 V_341 , V_342 ;
unsigned int V_343 , V_344 ;
unsigned int V_145 , V_121 ;
int V_405 ;
unsigned int V_406 ;
struct V_166 * V_167 ;
V_118 = V_177 -> V_270 ;
V_33 = (struct V_32 * ) V_118 -> V_33 ;
V_121 = V_177 -> V_300 ;
V_145 = F_9 ( & V_33 -> V_35 , 0 , V_121 ) ;
if ( V_145 == 0 )
return F_103 ( - V_128 ) ;
V_339 = V_341 = F_134 ( V_338 ) >> V_177 -> V_303 ;
V_343 = F_120 ( V_341 , V_145 ) ;
V_340 = V_342 =
( F_134 ( V_338 ) + F_135 ( V_338 ) - 1 ) >> V_177 -> V_303 ;
V_344 = F_120 ( V_342 , V_145 ) ;
V_405 = ( V_33 -> V_85 && V_339 < 2 * V_145 ) ;
V_404 = V_33 -> V_232 . V_255 [ 40 ] & 0x20 ;
V_406 = F_136 ( V_338 ) ;
if ( F_115 ( V_338 ) == V_356 )
V_406 += ( V_342 - V_341 ) * 4 ;
V_402 = V_33 -> V_232 . V_255 [ 9 ] & 0x20 ;
V_403 = V_33 -> V_232 . V_255 [ 12 ] & 0x40 ;
V_354 = V_33 -> V_232 . V_255 [ 8 ] & 0x01 ;
V_167 = NULL ;
if ( V_405 || V_360 ) {
} else if ( ( V_406 <= V_33 -> V_215 )
&& ( V_404 || ( V_341 == V_342 ) ) ) {
V_167 = F_127 ( V_119 , V_177 , V_338 ,
V_339 , V_340 ,
V_341 , V_342 ,
V_343 , V_344 ,
V_145 , V_121 ) ;
if ( F_42 ( V_167 ) && ( F_66 ( V_167 ) != - V_224 ) &&
( F_66 ( V_167 ) != - V_197 ) )
V_167 = NULL ;
} else if ( V_354 &&
( ( ( F_115 ( V_338 ) == V_355 ) && V_402 ) ||
( ( F_115 ( V_338 ) == V_356 ) && V_403 ) ) ) {
V_167 = F_123 ( V_119 , V_177 , V_338 ,
V_339 , V_340 ,
V_341 , V_342 ,
V_343 , V_344 ,
V_145 , V_121 ) ;
if ( F_42 ( V_167 ) && ( F_66 ( V_167 ) != - V_224 ) &&
( F_66 ( V_167 ) != - V_197 ) )
V_167 = NULL ;
}
if ( ! V_167 )
V_167 = F_114 ( V_119 , V_177 , V_338 ,
V_339 , V_340 ,
V_341 , V_342 ,
V_343 , V_344 ,
V_145 , V_121 ) ;
return V_167 ;
}
static struct V_166 * F_137 ( struct V_30 * V_119 ,
struct V_256 * V_177 ,
struct V_337 * V_338 )
{
unsigned long * V_345 ;
struct V_30 * V_118 ;
struct V_166 * V_167 ;
struct V_26 * V_45 ;
struct V_346 V_347 ;
struct V_348 * V_349 ;
char * V_350 ;
unsigned char V_48 ;
unsigned int V_369 ;
unsigned int V_372 , V_374 ;
unsigned int V_343 ;
unsigned int V_352 , V_286 , V_287 ;
T_6 V_341 , V_342 ;
unsigned int V_407 ;
if ( ( F_134 ( V_338 ) % V_408 ) != 0 ) {
V_167 = F_103 ( - V_128 ) ;
goto V_409;
}
if ( ( ( F_134 ( V_338 ) + F_135 ( V_338 ) ) %
V_408 ) != 0 ) {
V_167 = F_103 ( - V_128 ) ;
goto V_409;
}
V_341 = F_134 ( V_338 ) / V_408 ;
V_342 = ( F_134 ( V_338 ) + F_135 ( V_338 ) - 1 ) /
V_408 ;
V_369 = V_342 - V_341 + 1 ;
V_343 = 0 ;
V_118 = V_177 -> V_270 ;
if ( F_115 ( V_338 ) == V_355 )
V_48 = V_112 ;
else if ( F_115 ( V_338 ) == V_356 )
V_48 = V_107 ;
else {
V_167 = F_103 ( - V_128 ) ;
goto V_409;
}
V_352 = V_369 * V_302 ;
V_286 = 1 + V_369 ;
V_407 = sizeof( struct V_93 ) + 8 ;
V_287 = V_407 + V_352 * sizeof( unsigned long long ) ;
V_167 = F_41 ( V_175 , V_286 ,
V_287 , V_119 ) ;
if ( F_42 ( V_167 ) )
goto V_409;
V_45 = V_167 -> V_170 ;
if ( F_20 ( V_45 ++ , V_167 -> V_29 , V_341 , V_342 , V_48 ,
V_118 , V_119 , 1 , V_343 + 1 ,
V_369 , 0 , 0 ) == - V_224 ) {
F_44 ( V_167 , V_119 ) ;
V_167 = F_103 ( - V_224 ) ;
goto V_409;
}
V_345 = ( unsigned long * ) ( V_167 -> V_29 + V_407 ) ;
V_374 = 0 ;
F_116 (bv, req, iter) {
V_350 = F_118 ( V_349 -> V_358 ) + V_349 -> V_359 ;
V_372 = V_349 -> V_357 ;
if ( ! V_374 ) {
V_45 [ - 1 ] . V_43 |= V_237 ;
V_45 -> V_54 = V_48 ;
V_45 -> V_42 = 57326 ;
V_374 = 65536 ;
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_345 ;
V_45 -> V_43 |= V_365 ;
V_45 -> V_43 |= V_44 ;
V_45 ++ ;
}
V_374 -= V_372 ;
V_345 = F_121 ( V_345 , V_350 , V_372 ) ;
}
if ( F_122 ( V_338 ) ||
V_177 -> V_270 -> V_232 & V_366 )
F_32 ( V_367 , & V_167 -> V_43 ) ;
V_167 -> V_119 = V_119 ;
V_167 -> V_176 = V_119 ;
V_167 -> V_177 = V_177 ;
V_167 -> V_178 = V_119 -> V_265 * V_179 ;
V_167 -> V_169 = V_119 -> V_211 . V_213 ;
V_167 -> V_180 = 256 ;
V_167 -> V_181 = F_31 () ;
V_167 -> V_182 = V_183 ;
if ( F_42 ( V_167 ) && F_66 ( V_167 ) != - V_224 )
V_167 = NULL ;
V_409:
return V_167 ;
}
static int
F_138 ( struct V_166 * V_167 , struct V_337 * V_338 )
{
struct V_32 * V_33 ;
struct V_26 * V_45 ;
struct V_346 V_347 ;
struct V_348 * V_349 ;
char * V_350 , * V_56 ;
unsigned int V_121 , V_145 , V_351 ;
T_6 V_146 ;
int V_182 ;
if ( ! V_360 )
goto V_409;
V_33 = (struct V_32 * ) V_167 -> V_177 -> V_270 -> V_33 ;
V_121 = V_167 -> V_177 -> V_300 ;
V_145 = F_9 ( & V_33 -> V_35 , 0 , V_121 ) ;
V_146 = F_134 ( V_338 ) >> V_167 -> V_177 -> V_303 ;
V_45 = V_167 -> V_170 ;
V_45 ++ ;
if ( V_33 -> V_85 == 0 || V_146 > 2 * V_145 )
V_45 ++ ;
F_116 (bv, req, iter) {
V_350 = F_118 ( V_349 -> V_358 ) + V_349 -> V_359 ;
for ( V_351 = 0 ; V_351 < V_349 -> V_357 ; V_351 += V_121 ) {
if ( V_33 -> V_85 && V_146 <= 2 * V_145 )
V_45 ++ ;
if ( V_350 ) {
if ( V_45 -> V_43 & V_365 )
V_56 = * ( ( char * * ) ( ( V_172 ) V_45 -> V_56 ) ) ;
else
V_56 = ( char * ) ( ( V_172 ) V_45 -> V_56 ) ;
if ( V_350 != V_56 ) {
if ( F_115 ( V_338 ) == V_355 )
memcpy ( V_350 , V_56 , V_349 -> V_357 ) ;
F_139 ( V_360 ,
( void * ) ( ( V_172 ) V_56 & V_410 ) ) ;
}
V_350 = NULL ;
}
V_45 ++ ;
V_146 ++ ;
}
}
V_409:
V_182 = V_167 -> V_182 == V_185 ;
F_44 ( V_167 , V_167 -> V_176 ) ;
return V_182 ;
}
void F_105 ( struct V_166 * V_167 )
{
struct V_26 * V_45 ;
struct V_93 * V_94 ;
struct V_411 * V_411 ;
struct V_412 * V_412 ;
struct V_381 * V_381 ;
if ( V_167 -> V_401 == 1 ) {
V_411 = V_167 -> V_170 ;
V_412 = F_140 ( V_411 ) ;
V_381 = (struct V_381 * ) & V_412 -> V_413 [ 0 ] ;
V_94 = (struct V_93 * ) & V_381 -> V_414 [ 0 ] ;
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
static struct V_166 * F_141 ( struct V_30 * V_270 ,
struct V_256 * V_177 ,
struct V_337 * V_338 )
{
struct V_32 * V_33 ;
struct V_30 * V_119 ;
unsigned long V_43 ;
struct V_166 * V_167 ;
V_119 = F_142 ( V_270 ) ;
if ( ! V_119 )
V_119 = V_270 ;
V_33 = (struct V_32 * ) V_119 -> V_33 ;
if ( V_33 -> V_42 >= V_415 )
return F_103 ( - V_416 ) ;
F_25 ( F_26 ( V_119 -> V_2 ) , V_43 ) ;
V_33 -> V_42 ++ ;
if ( ( V_270 -> V_232 & V_273 ) )
V_167 = F_137 ( V_119 , V_177 , V_338 ) ;
else
V_167 = F_133 ( V_119 , V_177 , V_338 ) ;
if ( F_42 ( V_167 ) )
V_33 -> V_42 -- ;
F_28 ( F_26 ( V_119 -> V_2 ) , V_43 ) ;
return V_167 ;
}
static int F_143 ( struct V_166 * V_167 ,
struct V_337 * V_338 )
{
struct V_32 * V_33 ;
unsigned long V_43 ;
F_25 ( F_26 ( V_167 -> V_176 -> V_2 ) , V_43 ) ;
V_33 = (struct V_32 * ) V_167 -> V_176 -> V_33 ;
V_33 -> V_42 -- ;
F_28 ( F_26 ( V_167 -> V_176 -> V_2 ) , V_43 ) ;
return F_138 ( V_167 , V_338 ) ;
}
static int
F_144 ( struct V_30 * V_31 ,
struct V_417 * V_418 )
{
struct V_32 * V_33 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_418 -> V_419 = 2 ;
V_418 -> V_420 = V_33 -> V_85 ? 0 : 1 ;
V_418 -> V_120 = V_33 -> V_85 ? V_421 : V_422 ;
V_418 -> V_423 = sizeof( struct V_14 ) ;
memcpy ( V_418 -> V_424 , & V_33 -> V_35 ,
sizeof( struct V_14 ) ) ;
V_418 -> V_425 = F_124 ( ( unsigned long ) V_33 -> V_200 ,
sizeof( V_418 -> V_426 ) ) ;
memcpy ( V_418 -> V_426 , V_33 -> V_201 ,
V_418 -> V_425 ) ;
return 0 ;
}
static int
F_145 ( struct V_30 * V_31 )
{
struct V_166 * V_167 ;
int V_34 ;
struct V_26 * V_45 ;
int V_427 ;
if ( ! F_146 ( V_428 ) )
return - V_41 ;
V_427 = 0 ;
V_167 = F_41 ( V_175 , 1 , 32 , V_31 ) ;
if ( F_42 ( V_167 ) ) {
F_147 ( & V_429 ) ;
V_427 = 1 ;
V_167 = & V_430 -> V_167 ;
memset ( V_167 , 0 , sizeof( * V_167 ) ) ;
memset ( & V_430 -> V_45 , 0 ,
sizeof( V_430 -> V_45 ) ) ;
V_167 -> V_170 = & V_430 -> V_45 ;
V_167 -> V_29 = & V_430 -> V_29 ;
V_167 -> V_174 = V_175 ;
}
V_45 = V_167 -> V_170 ;
V_45 -> V_54 = V_431 ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_42 = 32 ;
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_167 -> V_29 ;
V_167 -> V_119 = V_31 ;
V_167 -> V_176 = V_31 ;
F_37 ( V_189 , & V_167 -> V_43 ) ;
F_32 ( V_367 , & V_167 -> V_43 ) ;
V_167 -> V_180 = 2 ;
V_167 -> V_178 = 2 * V_179 ;
V_167 -> V_181 = F_31 () ;
V_167 -> V_182 = V_183 ;
V_34 = F_38 ( V_167 ) ;
if ( ! V_34 )
F_37 ( V_334 , & V_31 -> V_43 ) ;
if ( V_427 )
F_59 ( & V_429 ) ;
else
F_44 ( V_167 , V_167 -> V_176 ) ;
return V_34 ;
}
static int
F_148 ( struct V_30 * V_31 )
{
struct V_166 * V_167 ;
int V_34 ;
struct V_26 * V_45 ;
int V_427 ;
if ( ! F_146 ( V_428 ) )
return - V_41 ;
V_427 = 0 ;
V_167 = F_41 ( V_175 , 1 , 32 , V_31 ) ;
if ( F_42 ( V_167 ) ) {
F_147 ( & V_429 ) ;
V_427 = 1 ;
V_167 = & V_430 -> V_167 ;
memset ( V_167 , 0 , sizeof( * V_167 ) ) ;
memset ( & V_430 -> V_45 , 0 ,
sizeof( V_430 -> V_45 ) ) ;
V_167 -> V_170 = & V_430 -> V_45 ;
V_167 -> V_29 = & V_430 -> V_29 ;
V_167 -> V_174 = V_175 ;
}
V_45 = V_167 -> V_170 ;
V_45 -> V_54 = V_432 ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_42 = 32 ;
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_167 -> V_29 ;
V_167 -> V_119 = V_31 ;
V_167 -> V_176 = V_31 ;
F_37 ( V_189 , & V_167 -> V_43 ) ;
F_32 ( V_367 , & V_167 -> V_43 ) ;
V_167 -> V_180 = 2 ;
V_167 -> V_178 = 2 * V_179 ;
V_167 -> V_181 = F_31 () ;
V_167 -> V_182 = V_183 ;
V_34 = F_38 ( V_167 ) ;
if ( ! V_34 )
F_32 ( V_334 , & V_31 -> V_43 ) ;
if ( V_427 )
F_59 ( & V_429 ) ;
else
F_44 ( V_167 , V_167 -> V_176 ) ;
return V_34 ;
}
static int
F_149 ( struct V_30 * V_31 )
{
struct V_166 * V_167 ;
int V_34 ;
struct V_26 * V_45 ;
int V_427 ;
if ( ! F_146 ( V_428 ) )
return - V_41 ;
V_427 = 0 ;
V_167 = F_41 ( V_175 , 1 , 32 , V_31 ) ;
if ( F_42 ( V_167 ) ) {
F_147 ( & V_429 ) ;
V_427 = 1 ;
V_167 = & V_430 -> V_167 ;
memset ( V_167 , 0 , sizeof( * V_167 ) ) ;
memset ( & V_430 -> V_45 , 0 ,
sizeof( V_430 -> V_45 ) ) ;
V_167 -> V_170 = & V_430 -> V_45 ;
V_167 -> V_29 = & V_430 -> V_29 ;
V_167 -> V_174 = V_175 ;
}
V_45 = V_167 -> V_170 ;
V_45 -> V_54 = V_433 ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_42 = 32 ;
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_167 -> V_29 ;
V_167 -> V_119 = V_31 ;
V_167 -> V_176 = V_31 ;
F_37 ( V_189 , & V_167 -> V_43 ) ;
F_32 ( V_367 , & V_167 -> V_43 ) ;
V_167 -> V_180 = 2 ;
V_167 -> V_178 = 2 * V_179 ;
V_167 -> V_181 = F_31 () ;
V_167 -> V_182 = V_183 ;
V_34 = F_38 ( V_167 ) ;
if ( ! V_34 )
F_32 ( V_334 , & V_31 -> V_43 ) ;
if ( V_427 )
F_59 ( & V_429 ) ;
else
F_44 ( V_167 , V_167 -> V_176 ) ;
return V_34 ;
}
static int F_150 ( struct V_30 * V_31 ,
void T_9 * V_434 )
{
struct V_166 * V_167 ;
int V_34 ;
struct V_26 * V_45 ;
int V_427 ;
struct V_435 V_436 ;
if ( ! F_146 ( V_428 ) )
return - V_41 ;
if ( F_151 ( & V_436 , V_434 , sizeof( V_436 ) ) )
return - V_437 ;
V_427 = 0 ;
V_167 = F_41 ( V_175 , 1 ,
sizeof( struct V_438 ) , V_31 ) ;
if ( F_42 ( V_167 ) ) {
F_147 ( & V_429 ) ;
V_427 = 1 ;
V_167 = & V_430 -> V_167 ;
memset ( V_167 , 0 , sizeof( * V_167 ) ) ;
memset ( & V_430 -> V_45 , 0 ,
sizeof( V_430 -> V_45 ) ) ;
V_167 -> V_170 = & V_430 -> V_45 ;
V_167 -> V_29 = & V_430 -> V_29 ;
V_167 -> V_174 = V_175 ;
}
V_45 = V_167 -> V_170 ;
V_45 -> V_54 = V_439 ;
V_45 -> V_43 |= V_44 ;
V_45 -> V_42 = 12 ;
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_167 -> V_29 ;
V_167 -> V_119 = V_31 ;
V_167 -> V_176 = V_31 ;
F_37 ( V_189 , & V_167 -> V_43 ) ;
F_32 ( V_367 , & V_167 -> V_43 ) ;
F_32 ( V_190 , & V_167 -> V_43 ) ;
V_167 -> V_180 = 5 ;
V_167 -> V_178 = 10 * V_179 ;
V_167 -> V_181 = F_31 () ;
V_167 -> V_182 = V_183 ;
V_167 -> V_169 = V_436 . V_440 ;
V_34 = F_38 ( V_167 ) ;
if ( ! V_34 && V_436 . V_440 && ( V_167 -> V_169 != V_436 . V_440 ) )
V_34 = - V_261 ;
if ( ! V_34 ) {
V_436 . V_29 = * ( (struct V_438 * ) V_167 -> V_29 ) ;
if ( F_152 ( V_434 , & V_436 , sizeof( V_436 ) ) )
V_34 = - V_437 ;
}
if ( V_427 )
F_59 ( & V_429 ) ;
else
F_44 ( V_167 , V_167 -> V_176 ) ;
return V_34 ;
}
static int
F_153 ( struct V_30 * V_31 , void T_9 * V_434 )
{
struct V_229 * V_230 ;
struct V_441 * V_442 ;
struct V_166 * V_167 ;
struct V_26 * V_45 ;
int V_34 ;
V_167 = F_41 ( V_175 , 1 + 1 ,
( sizeof( struct V_229 ) +
sizeof( struct V_441 ) ) ,
V_31 ) ;
if ( F_42 ( V_167 ) ) {
F_18 ( V_7 , V_31 , L_1 ,
L_68 ) ;
return F_66 ( V_167 ) ;
}
V_167 -> V_119 = V_31 ;
V_167 -> V_176 = V_31 ;
V_167 -> V_180 = 0 ;
F_37 ( V_189 , & V_167 -> V_43 ) ;
V_167 -> V_178 = 10 * V_179 ;
V_230 = (struct V_229 * ) V_167 -> V_29 ;
memset ( V_230 , 0 , sizeof( struct V_229 ) ) ;
V_230 -> V_233 = V_234 ;
V_230 -> V_235 = 0x01 ;
V_230 -> V_443 [ 1 ] = 0x01 ;
V_45 = V_167 -> V_170 ;
V_45 -> V_54 = V_236 ;
V_45 -> V_42 = sizeof( struct V_229 ) ;
V_45 -> V_43 |= V_237 ;
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_230 ;
V_442 = (struct V_441 * ) ( V_230 + 1 ) ;
memset ( V_442 , 0 , sizeof( struct V_441 ) ) ;
V_45 ++ ;
V_45 -> V_54 = V_238 ;
V_45 -> V_42 = sizeof( struct V_441 ) ;
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_442 ;
V_167 -> V_181 = F_31 () ;
V_167 -> V_182 = V_183 ;
V_34 = F_43 ( V_167 ) ;
if ( V_34 == 0 ) {
V_230 = (struct V_229 * ) V_167 -> V_29 ;
V_442 = (struct V_441 * ) ( V_230 + 1 ) ;
if ( F_152 ( V_434 , V_442 ,
sizeof( struct V_441 ) ) )
V_34 = - V_437 ;
}
F_44 ( V_167 , V_167 -> V_176 ) ;
return V_34 ;
}
static int
F_154 ( struct V_30 * V_31 , void T_9 * V_434 )
{
struct V_32 * V_33 =
(struct V_32 * ) V_31 -> V_33 ;
struct V_444 V_70 = V_33 -> V_70 ;
int V_34 ;
if ( ! F_146 ( V_428 ) )
return - V_41 ;
if ( ! V_434 )
return - V_128 ;
V_34 = 0 ;
if ( F_152 ( V_434 , ( long * ) & V_70 ,
sizeof( struct V_444 ) ) )
V_34 = - V_437 ;
return V_34 ;
}
static int
F_155 ( struct V_30 * V_31 , void T_9 * V_434 )
{
struct V_32 * V_33 =
(struct V_32 * ) V_31 -> V_33 ;
struct V_444 V_70 ;
if ( ! F_146 ( V_428 ) )
return - V_41 ;
if ( ! V_434 )
return - V_128 ;
if ( F_151 ( & V_70 , V_434 , sizeof( struct V_444 ) ) )
return - V_437 ;
V_33 -> V_70 = V_70 ;
F_76 ( & V_31 -> V_2 -> V_82 ,
L_69 ,
V_33 -> V_70 . V_69 , V_33 -> V_70 . V_89 ) ;
return 0 ;
}
static int F_156 ( struct V_30 * V_31 , void T_9 * V_434 )
{
struct V_445 V_436 ;
char * V_446 , * V_447 ;
struct V_166 * V_167 ;
struct V_26 * V_45 ;
char V_448 , V_449 ;
int V_34 ;
if ( ! F_146 ( V_428 ) && ! F_146 ( V_450 ) )
return - V_41 ;
V_448 = V_449 = 0 ;
V_34 = - V_437 ;
if ( F_151 ( & V_436 , V_434 , sizeof( V_436 ) ) )
goto V_409;
if ( F_157 () || sizeof( long ) == 4 ) {
V_34 = - V_128 ;
if ( ( V_436 . V_446 >> 32 ) != 0 )
goto V_409;
if ( ( V_436 . V_447 >> 32 ) != 0 )
goto V_409;
V_436 . V_446 &= 0x7fffffffULL ;
V_436 . V_447 &= 0x7fffffffULL ;
}
V_446 = F_40 ( V_436 . V_451 , V_195 | V_196 ) ;
V_447 = F_40 ( V_436 . V_452 , V_195 | V_196 ) ;
if ( ! V_446 || ! V_447 ) {
V_34 = - V_197 ;
goto V_453;
}
V_34 = - V_437 ;
if ( F_151 ( V_446 ,
( void T_9 * ) ( unsigned long ) V_436 . V_446 ,
V_436 . V_451 ) )
goto V_453;
V_448 = V_446 [ 0 ] ;
V_449 = V_446 [ 1 ] ;
V_167 = F_41 ( V_175 , 2 , 0 , V_31 ) ;
if ( F_42 ( V_167 ) ) {
F_18 ( V_7 , V_31 , L_1 ,
L_68 ) ;
V_34 = F_66 ( V_167 ) ;
goto V_453;
}
V_167 -> V_119 = V_31 ;
V_167 -> V_176 = V_31 ;
V_167 -> V_180 = 3 ;
V_167 -> V_178 = 10 * V_179 ;
V_167 -> V_181 = F_31 () ;
V_167 -> V_182 = V_183 ;
V_45 = V_167 -> V_170 ;
V_45 -> V_54 = V_236 ;
V_45 -> V_42 = V_436 . V_451 ;
V_45 -> V_43 |= V_237 ;
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_446 ;
V_45 ++ ;
V_45 -> V_54 = V_238 ;
V_45 -> V_42 = V_436 . V_452 ;
V_45 -> V_43 = V_44 ;
V_45 -> V_56 = ( T_1 ) ( V_172 ) V_447 ;
V_34 = F_43 ( V_167 ) ;
if ( V_34 )
goto V_454;
V_34 = - V_437 ;
if ( F_152 ( ( void T_9 * ) ( unsigned long ) V_436 . V_447 ,
V_447 , V_436 . V_452 ) )
goto V_454;
V_34 = 0 ;
V_454:
F_44 ( V_167 , V_167 -> V_176 ) ;
V_453:
F_45 ( V_447 ) ;
F_45 ( V_446 ) ;
V_409:
F_18 ( V_7 , V_31 ,
L_70 ,
( int ) V_448 , ( int ) V_449 , V_34 ) ;
return V_34 ;
}
static int
F_158 ( struct V_256 * V_177 , unsigned int V_48 , void T_9 * V_434 )
{
struct V_30 * V_31 = V_177 -> V_270 ;
switch ( V_48 ) {
case V_455 :
return F_154 ( V_31 , V_434 ) ;
case V_456 :
return F_155 ( V_31 , V_434 ) ;
case V_457 :
return F_153 ( V_31 , V_434 ) ;
case V_458 :
return F_145 ( V_31 ) ;
case V_459 :
return F_148 ( V_31 ) ;
case V_460 :
return F_149 ( V_31 ) ;
case V_461 :
return F_150 ( V_31 , V_434 ) ;
case V_462 :
return F_156 ( V_31 , V_434 ) ;
default:
return - V_463 ;
}
}
static int
F_159 ( struct V_26 * V_464 , struct V_26 * V_465 , char * V_466 )
{
int V_467 , V_42 ;
char * V_468 ;
V_467 = 0 ;
while ( V_464 <= V_465 ) {
V_467 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_71 ,
from, ((int *) from)[0], ((int *) from)[1]) ;
if ( V_464 -> V_43 & V_365 )
V_468 = ( char * ) * ( ( V_172 * ) ( V_172 ) V_464 -> V_56 ) ;
else
V_468 = ( char * ) ( ( V_172 ) V_464 -> V_56 ) ;
for ( V_42 = 0 ; V_42 < V_464 -> V_42 && V_42 < 32 ; V_42 ++ ) {
if ( V_42 % 8 == 0 ) V_467 += sprintf ( V_466 + V_467 , L_72 ) ;
if ( V_42 % 4 == 0 ) V_467 += sprintf ( V_466 + V_467 , L_72 ) ;
V_467 += sprintf ( V_466 + V_467 , L_11 , V_468 [ V_42 ] ) ;
}
V_467 += sprintf ( V_466 + V_467 , L_73 ) ;
V_464 ++ ;
}
return V_467 ;
}
static void
F_160 ( struct V_30 * V_31 , struct V_294 * V_294 ,
char * V_469 )
{
T_10 * V_290 ;
T_10 * V_470 ;
V_290 = ( T_10 * ) F_88 ( V_294 ) ;
V_470 = ( T_10 * ) & V_294 -> V_328 ;
if ( V_290 ) {
F_18 ( V_471 , V_31 , L_74
L_75 ,
V_469 , * V_470 , * ( ( T_3 * ) ( V_470 + 1 ) ) ,
V_290 [ 0 ] , V_290 [ 1 ] , V_290 [ 2 ] , V_290 [ 3 ] ) ;
} else {
F_18 ( V_471 , V_31 , L_76 ,
V_469 , * V_470 , * ( ( T_3 * ) ( V_470 + 1 ) ) ,
L_77 ) ;
}
}
static void F_161 ( struct V_30 * V_31 ,
struct V_166 * V_338 , struct V_294 * V_294 )
{
char * V_466 ;
struct V_26 * V_472 , * V_473 , * V_474 , * V_464 , * V_465 ;
int V_467 , V_475 , V_476 ;
V_466 = ( char * ) F_162 ( V_227 ) ;
if ( V_466 == NULL ) {
F_18 ( V_7 , V_31 , L_1 ,
L_78 ) ;
return;
}
V_467 = sprintf (page, KERN_ERR PRINTK_HEADER
L_79 ,
dev_name(&device->cdev->dev)) ;
V_467 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_80
L_81 ,
req, scsw_cc(&irb->scsw), scsw_fctl(&irb->scsw),
scsw_actl(&irb->scsw), scsw_stctl(&irb->scsw),
scsw_dstat(&irb->scsw), scsw_cstat(&irb->scsw),
req ? req->intrc : 0 ) ;
V_467 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_82 ,
dev_name(&device->cdev->dev),
(void *) (addr_t) irb->scsw.cmd.cpa) ;
if ( V_294 -> V_477 . V_478 . V_479 . V_480 ) {
for ( V_475 = 0 ; V_475 < 4 ; V_475 ++ ) {
V_467 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_83 ,
(8 * sl), ((8 * sl) + 7)) ;
for ( V_476 = 0 ; V_476 < 8 ; V_476 ++ ) {
V_467 += sprintf ( V_466 + V_467 , L_84 ,
V_294 -> V_481 [ 8 * V_475 + V_476 ] ) ;
}
V_467 += sprintf ( V_466 + V_467 , L_73 ) ;
}
if ( V_294 -> V_481 [ 27 ] & V_331 ) {
sprintf (page + len, KERN_ERR PRINTK_HEADER
L_85
L_86 ,
irb->ecw[7] >> 4 , irb->ecw[7] & 0x0f ,
irb->ecw[1] & 0x10 ? L_49 : L_87 ) ;
} else {
sprintf (page + len, KERN_ERR PRINTK_HEADER
L_88
L_89 ,
irb->ecw[6] & 0x0f , irb->ecw[22] >> 4 ) ;
}
} else {
sprintf (page + len, KERN_ERR PRINTK_HEADER
L_90 ) ;
}
F_163 ( L_1 , V_466 ) ;
if ( V_338 ) {
V_472 = V_338 -> V_170 ;
for ( V_473 = V_472 ; V_473 -> V_43 & ( V_237 | V_482 ) ; V_473 ++ ) ;
V_465 = F_124 ( V_472 + 6 , V_473 ) ;
V_467 = sprintf (page, KERN_ERR PRINTK_HEADER
L_91 , req) ;
F_159 ( V_472 , V_465 , V_466 + V_467 ) ;
F_163 ( L_1 , V_466 ) ;
V_467 = 0 ;
V_464 = ++ V_465 ;
V_474 = (struct V_26 * ) ( V_172 )
V_294 -> V_328 . V_48 . V_483 ;
if ( V_464 < V_474 - 2 ) {
V_464 = V_474 - 2 ;
V_467 += sprintf (page, KERN_ERR PRINTK_HEADER L_92 ) ;
}
V_465 = F_124 ( V_474 + 1 , V_473 ) ;
V_467 += F_159 ( V_464 , V_465 , V_466 + V_467 ) ;
V_464 = F_164 ( V_464 , ++ V_465 ) ;
if ( V_464 < V_473 - 1 ) {
V_464 = V_473 - 1 ;
V_467 += sprintf (page + len, KERN_ERR PRINTK_HEADER L_92 ) ;
}
V_467 += F_159 ( V_464 , V_473 , V_466 + V_467 ) ;
if ( V_467 > 0 )
F_163 ( L_1 , V_466 ) ;
}
F_165 ( ( unsigned long ) V_466 ) ;
}
static void F_166 ( struct V_30 * V_31 ,
struct V_166 * V_338 , struct V_294 * V_294 )
{
char * V_466 ;
int V_467 , V_475 , V_476 , V_484 ;
struct V_485 * V_485 ;
T_7 * V_290 , * V_486 ;
V_466 = ( char * ) F_162 ( V_227 ) ;
if ( V_466 == NULL ) {
F_18 ( V_7 , V_31 , L_93 ,
L_94 ) ;
return;
}
V_467 = sprintf (page, KERN_ERR PRINTK_HEADER
L_79 ,
dev_name(&device->cdev->dev)) ;
V_467 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_80
L_95 ,
req, scsw_cc(&irb->scsw), scsw_fctl(&irb->scsw),
scsw_actl(&irb->scsw), scsw_stctl(&irb->scsw),
scsw_dstat(&irb->scsw), scsw_cstat(&irb->scsw),
irb->scsw.tm.fcxs, irb->scsw.tm.schxs,
req ? req->intrc : 0 ) ;
V_467 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_96 ,
dev_name(&device->cdev->dev),
(void *) (addr_t) irb->scsw.tm.tcw) ;
V_485 = NULL ;
V_290 = NULL ;
if ( V_294 -> V_328 . V_487 . V_411 && ( V_294 -> V_328 . V_487 . V_488 & 0x01 ) )
V_485 = F_167 (
(struct V_411 * ) ( unsigned long ) V_294 -> V_328 . V_487 . V_411 ) ;
if ( V_485 ) {
V_467 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_97 , tsb->length) ;
V_467 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_98 , tsb->flags) ;
V_467 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_99 , tsb->dcw_offset) ;
V_467 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_100 , tsb->count) ;
V_484 = V_485 -> V_42 - 28 ;
V_467 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_101 , residual) ;
switch ( V_485 -> V_43 & 0x07 ) {
case 1 :
V_467 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_102 ,
tsb->tsa.iostat.dev_time) ;
V_467 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_103 ,
tsb->tsa.iostat.def_time) ;
V_467 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_104 ,
tsb->tsa.iostat.queue_time) ;
V_467 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_105 ,
tsb->tsa.iostat.dev_busy_time) ;
V_467 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_106 ,
tsb->tsa.iostat.dev_act_time) ;
V_290 = V_485 -> V_489 . V_490 . V_290 ;
break;
case 2 :
V_467 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_107 , tsb->tsa.ddpc.rc) ;
for ( V_475 = 0 ; V_475 < 2 ; V_475 ++ ) {
V_467 += sprintf (page + len,
KERN_ERR PRINTK_HEADER
L_108 ,
(8 * sl), ((8 * sl) + 7)) ;
V_486 = V_485 -> V_489 . V_491 . V_486 ;
for ( V_476 = 0 ; V_476 < 8 ; V_476 ++ ) {
V_467 += sprintf ( V_466 + V_467 , L_84 ,
V_486 [ 8 * V_475 + V_476 ] ) ;
}
V_467 += sprintf ( V_466 + V_467 , L_73 ) ;
}
V_290 = V_485 -> V_489 . V_491 . V_290 ;
break;
case 3 :
V_467 += sprintf (page + len, KERN_ERR PRINTK_HEADER
L_109 ) ;
break;
}
if ( V_290 ) {
for ( V_475 = 0 ; V_475 < 4 ; V_475 ++ ) {
V_467 += sprintf (page + len,
KERN_ERR PRINTK_HEADER
L_83 ,
(8 * sl), ((8 * sl) + 7)) ;
for ( V_476 = 0 ; V_476 < 8 ; V_476 ++ ) {
V_467 += sprintf ( V_466 + V_467 , L_84 ,
V_290 [ 8 * V_475 + V_476 ] ) ;
}
V_467 += sprintf ( V_466 + V_467 , L_73 ) ;
}
if ( V_290 [ 27 ] & V_331 ) {
sprintf (page + len, KERN_ERR PRINTK_HEADER
L_85
L_86 ,
sense[7] >> 4 , sense[7] & 0x0f ,
sense[1] & 0x10 ? L_49 : L_87 ) ;
} else {
sprintf (page + len, KERN_ERR PRINTK_HEADER
L_88
L_89 ,
sense[6] & 0x0f , sense[22] >> 4 ) ;
}
} else {
sprintf (page + len, KERN_ERR PRINTK_HEADER
L_90 ) ;
}
} else {
sprintf (page + len, KERN_ERR PRINTK_HEADER
L_110 ) ;
}
F_163 ( L_1 , V_466 ) ;
F_165 ( ( unsigned long ) V_466 ) ;
}
static void F_168 ( struct V_30 * V_31 ,
struct V_166 * V_338 , struct V_294 * V_294 )
{
if ( F_169 ( & V_294 -> V_328 ) )
F_166 ( V_31 , V_338 , V_294 ) ;
else
F_161 ( V_31 , V_338 , V_294 ) ;
}
static int F_170 ( struct V_30 * V_31 )
{
F_100 ( V_31 ) ;
F_83 ( V_31 ) ;
return 0 ;
}
static int F_171 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
struct V_14 V_492 ;
int V_258 , V_34 ;
struct V_149 V_257 ;
unsigned long V_43 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
V_34 = F_48 ( V_31 ) ;
if ( V_34 )
goto V_493;
F_29 ( V_31 , & V_257 ) ;
V_34 = F_24 ( V_31 ) ;
F_25 ( F_26 ( V_31 -> V_2 ) , V_43 ) ;
if ( memcmp ( & V_33 -> V_134 , & V_257 , sizeof( struct V_149 ) ) != 0 )
F_15 ( & V_31 -> V_2 -> V_82 , L_111
L_112 ) ;
F_28 ( F_26 ( V_31 -> V_2 ) , V_43 ) ;
if ( V_34 )
goto V_493;
V_258 = F_78 ( V_31 ) ;
if ( V_258 < 0 )
return V_258 ;
if ( ! V_258 ) {
F_70 ( V_31 ) ;
F_79 ( V_31 ) ;
} else
F_80 ( V_31 ) ;
V_34 = F_48 ( V_31 ) ;
if ( V_34 )
goto V_493;
F_65 ( V_31 ) ;
V_34 = F_81 ( V_31 , V_175 ,
& V_492 , 64 ) ;
if ( V_34 ) {
F_3 ( V_7 , V_31 -> V_2 ,
L_43 , V_34 ) ;
goto V_493;
}
F_25 ( F_26 ( V_31 -> V_2 ) , V_43 ) ;
memcpy ( & V_33 -> V_35 , & V_492 , sizeof( V_492 ) ) ;
F_28 ( F_26 ( V_31 -> V_2 ) , V_43 ) ;
F_97 ( V_31 ) ;
return 0 ;
V_493:
return - 1 ;
}
static int F_172 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
int V_34 , V_494 ;
char V_495 [ 60 ] ;
struct V_149 V_134 ;
unsigned long V_43 ;
V_33 = (struct V_32 * ) V_31 -> V_33 ;
F_25 ( F_26 ( V_31 -> V_2 ) , V_43 ) ;
V_494 = V_33 -> V_134 . V_162 ;
F_28 ( F_26 ( V_31 -> V_2 ) , V_43 ) ;
V_34 = F_48 ( V_31 ) ;
if ( V_34 )
goto V_493;
V_34 = F_24 ( V_31 ) ;
if ( V_34 )
goto V_493;
F_173 ( V_31 ) ;
F_29 ( V_31 , & V_134 ) ;
if ( V_494 != V_134 . V_162 ) {
if ( strlen ( V_134 . V_164 ) > 0 )
snprintf ( V_495 , sizeof( V_495 ) ,
L_113 , V_134 . V_152 , V_134 . V_154 ,
V_134 . V_156 , V_134 . V_162 , V_134 . V_164 ) ;
else
snprintf ( V_495 , sizeof( V_495 ) ,
L_114 , V_134 . V_152 , V_134 . V_154 ,
V_134 . V_156 , V_134 . V_162 ) ;
F_76 ( & V_31 -> V_2 -> V_82 ,
L_115
L_116 , V_495 ) ;
}
return 0 ;
V_493:
return - 1 ;
}
static int T_11
F_174 ( void )
{
int V_3 ;
F_175 ( V_8 . V_496 , 4 ) ;
V_430 = F_61 ( sizeof( * V_430 ) ,
V_195 | V_196 ) ;
if ( ! V_430 )
return - V_197 ;
V_228 = F_61 ( sizeof( * V_228 ) ,
V_195 | V_196 ) ;
if ( ! V_228 ) {
F_45 ( V_430 ) ;
return - V_197 ;
}
V_3 = F_176 ( & V_497 ) ;
if ( ! V_3 )
F_177 () ;
else {
F_45 ( V_228 ) ;
F_45 ( V_430 ) ;
}
return V_3 ;
}
static void T_12
F_178 ( void )
{
F_179 ( & V_497 ) ;
F_45 ( V_228 ) ;
F_45 ( V_430 ) ;
}
