static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_10 = F_2 ( V_6 -> V_11 [ 0 ] ) ;
unsigned int V_12 = F_3 ( V_6 -> V_11 [ 0 ] ) ;
unsigned int V_13 = ( V_10 + 1 ) % V_4 -> V_14 ;
unsigned int V_15 [ 32 ] ;
unsigned int V_16 ;
int V_17 ;
if ( V_6 -> V_18 == 1 ) {
V_8 -> V_19 = V_6 -> V_18 ;
return 0 ;
}
V_15 [ 0 ] = V_6 -> V_11 [ 0 ] ;
for ( V_17 = 1 ; V_17 < V_6 -> V_18 ; V_17 ++ ) {
unsigned int V_20 = F_2 ( V_6 -> V_11 [ V_17 ] ) ;
unsigned int V_21 = F_3 ( V_6 -> V_11 [ V_17 ] ) ;
if ( V_6 -> V_11 [ 0 ] == V_6 -> V_11 [ V_17 ] )
break;
if ( V_21 == V_22 && ( V_20 & 1 ) ) {
F_4 ( V_2 -> V_23 ,
L_1 ) ;
return - V_24 ;
}
if ( V_12 == V_22 )
V_13 = ( V_13 + 1 ) % V_4 -> V_14 ;
if ( V_20 != V_13 ) {
F_4 ( V_2 -> V_23 ,
L_2 ,
V_17 , V_20 , V_13 , V_10 ) ;
return - V_24 ;
}
V_15 [ V_17 ] = V_6 -> V_11 [ V_17 ] ;
V_12 = V_21 ;
}
V_16 = V_17 ;
for ( V_17 = 0 ; V_17 < V_6 -> V_18 ; V_17 ++ ) {
if ( V_6 -> V_11 [ V_17 ] != V_15 [ V_17 % V_16 ] ) {
F_4 ( V_2 -> V_23 ,
L_3 ,
V_17 , F_2 ( V_15 [ V_17 ] ) ,
F_5 ( V_15 [ V_17 ] ) ,
F_3 ( V_15 [ V_17 ] ) ,
F_2 ( V_6 -> V_11 [ V_17 % V_16 ] ) ,
F_5 ( V_6 -> V_11 [ V_17 % V_16 ] ) ,
F_3 ( V_15 [ V_17 % V_16 ] ) ) ;
return - V_24 ;
}
}
V_8 -> V_19 = V_16 ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int * V_11 ,
unsigned int V_14 ,
unsigned int V_16 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_25 = F_2 ( V_11 [ 0 ] ) ;
unsigned int V_26 = F_2 ( V_11 [ V_16 - 1 ] ) ;
unsigned int V_17 ;
for ( V_17 = 0 ; V_17 < V_16 ; V_17 ++ ) {
unsigned int V_20 = F_2 ( V_11 [ V_17 ] ) ;
unsigned int V_27 = F_5 ( V_11 [ V_17 ] ) ;
unsigned int V_21 = F_3 ( V_11 [ V_17 ] ) ;
unsigned int V_28 = 0 ;
if ( V_21 == V_22 )
V_28 |= V_29 ;
if ( F_7 ( V_4 , V_27 ) ) {
V_28 |= V_30 ;
V_27 -= V_8 -> V_31 ;
}
V_28 |= F_8 ( V_27 ) ;
F_9 ( F_10 ( V_20 ) , V_2 -> V_32 + V_33 ) ;
F_9 ( V_28 , V_2 -> V_32 + V_34 ) ;
V_8 -> V_35 [ V_17 ] = V_20 ;
}
for ( ; V_17 < V_14 ; V_17 ++ )
V_8 -> V_35 [ V_17 ] = F_2 ( V_11 [ V_17 ] ) ;
V_8 -> V_36 = F_11 ( V_25 ) |
F_12 ( V_26 ) ;
F_9 ( V_8 -> V_36 , V_2 -> V_32 + V_33 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_37 * V_38 ,
unsigned long V_39 )
{
unsigned int V_40 ;
V_40 = F_14 ( V_2 -> V_32 + V_41 ) ;
if ( ( V_40 & V_42 ) == 0 )
return 0 ;
return - V_43 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_44 ,
unsigned int * V_45 )
{
const struct V_46 * V_47 = V_2 -> V_48 ;
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_49 ;
unsigned int V_20 ;
V_49 = F_14 ( V_2 -> V_32 + V_50 ) ;
if ( ! V_47 -> V_51 ) {
V_20 = V_49 >> 12 ;
if ( V_20 != V_8 -> V_35 [ V_44 ] ) {
F_4 ( V_2 -> V_23 ,
L_4 ,
V_20 , V_8 -> V_35 [ V_44 ] ) ;
return - V_52 ;
}
}
* V_45 = V_49 & V_4 -> V_53 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_37 * V_38 ,
unsigned int * V_54 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
int V_55 = 0 ;
int V_17 ;
V_8 -> V_56 |= V_57 ;
F_9 ( V_8 -> V_56 , V_2 -> V_32 + V_58 ) ;
F_17 ( 0 , V_2 -> V_32 + V_59 ) ;
F_17 ( 0 , V_2 -> V_32 + V_60 ) ;
F_6 ( V_2 , V_4 , & V_38 -> V_61 , 1 , 1 ) ;
for ( V_17 = 0 ; V_17 < V_38 -> V_62 ; V_17 ++ ) {
unsigned int V_45 ;
F_9 ( 0 , V_2 -> V_32 + V_63 ) ;
V_55 = F_18 ( V_2 , V_4 , V_38 , F_13 , 0 ) ;
if ( V_55 )
break;
V_55 = F_15 ( V_2 , V_4 , 0 , & V_45 ) ;
if ( V_55 )
break;
V_54 [ V_17 ] = V_45 ;
}
V_8 -> V_56 &= ~ V_57 ;
F_9 ( V_8 -> V_56 , V_2 -> V_32 + V_58 ) ;
F_17 ( 0 , V_2 -> V_32 + V_59 ) ;
F_17 ( 0 , V_2 -> V_32 + V_60 ) ;
return V_55 ? V_55 : V_38 -> V_62 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
V_8 -> V_56 &= V_64 ;
F_9 ( V_8 -> V_56 , V_2 -> V_32 + V_58 ) ;
F_20 ( V_2 -> V_65 , 1 , 2 , false ) ;
F_17 ( 0 , V_2 -> V_32 + V_59 ) ;
F_17 ( 0 , V_2 -> V_32 + V_60 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_66 -> V_6 ;
unsigned int V_40 ;
unsigned int V_45 ;
int V_55 ;
V_40 = F_14 ( V_2 -> V_32 + V_41 ) ;
if ( V_40 & V_42 ) {
F_22 ( V_2 -> V_23 , L_5 , V_40 ) ;
V_4 -> V_66 -> V_67 |= V_68 ;
return;
}
if ( V_40 & V_69 ) {
F_22 ( V_2 -> V_23 ,
L_6 , V_40 ) ;
V_4 -> V_66 -> V_67 |= V_68 ;
return;
}
F_17 ( 0 , V_2 -> V_32 + V_60 ) ;
for (; ! ( F_14 ( V_2 -> V_32 + V_41 ) & V_42 ) ; ) {
V_55 = F_15 ( V_2 , V_4 , V_4 -> V_66 -> V_44 , & V_45 ) ;
if ( V_55 ) {
V_4 -> V_66 -> V_67 |= V_68 ;
break;
}
F_23 ( V_4 , & V_45 , 1 ) ;
if ( V_6 -> V_70 == V_71 &&
V_4 -> V_66 -> V_72 >= V_6 -> V_73 ) {
V_4 -> V_66 -> V_67 |= V_74 ;
break;
}
}
F_17 ( 0 , V_2 -> V_32 + V_60 ) ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_75 * V_66 = V_4 -> V_66 ;
struct V_5 * V_6 = & V_66 -> V_6 ;
unsigned int V_40 ;
int V_17 ;
V_40 = F_14 ( V_2 -> V_32 + V_41 ) ;
if ( ! ( V_40 & V_76 ) ) {
F_22 ( V_2 -> V_23 , L_7 ) ;
V_66 -> V_67 |= V_68 ;
return;
}
if ( V_40 & V_69 ) {
F_22 ( V_2 -> V_23 ,
L_8 ) ;
V_66 -> V_67 |= V_68 ;
return;
}
for ( V_17 = 0 ; V_17 < V_8 -> V_77 ; V_17 ++ ) {
unsigned int V_45 ;
int V_55 ;
V_55 = F_15 ( V_2 , V_4 , V_4 -> V_66 -> V_44 , & V_45 ) ;
if ( V_55 ) {
V_4 -> V_66 -> V_67 |= V_68 ;
break;
}
if ( ! F_23 ( V_4 , & V_45 , 1 ) )
break;
if ( V_6 -> V_70 == V_71 &&
V_66 -> V_72 >= V_6 -> V_73 ) {
V_66 -> V_67 |= V_74 ;
break;
}
}
F_17 ( 0 , V_2 -> V_32 + V_60 ) ;
}
static T_1 F_25 ( int V_78 , void * V_79 )
{
struct V_1 * V_2 = V_79 ;
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
if ( ! V_2 -> V_80 )
return V_81 ;
V_4 = V_2 -> V_82 ;
V_6 = & V_4 -> V_66 -> V_6 ;
if ( ! ( F_14 ( V_2 -> V_32 + V_41 ) & V_83 ) )
return V_81 ;
if ( V_8 -> V_84 ) {
V_8 -> V_84 = 0 ;
V_8 -> V_56 &= V_64 ;
V_8 -> V_56 |= V_57 ;
F_9 ( V_8 -> V_56 , V_2 -> V_32 + V_58 ) ;
V_8 -> V_56 = V_8 -> V_85 ;
F_17 ( 0 , V_2 -> V_32 + V_59 ) ;
F_17 ( 0 , V_2 -> V_32 + V_60 ) ;
F_9 ( V_8 -> V_36 , V_2 -> V_32 + V_33 ) ;
F_9 ( V_8 -> V_56 , V_2 -> V_32 + V_58 ) ;
F_20 ( V_2 -> V_65 , 1 , 2 , true ) ;
return V_86 ;
}
if ( V_6 -> V_87 & V_88 )
F_21 ( V_2 , V_4 ) ;
else
F_24 ( V_2 , V_4 ) ;
F_26 ( V_2 , V_4 ) ;
return V_86 ;
}
static int F_27 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_5 * V_6 = & V_4 -> V_66 -> V_6 ;
F_6 ( V_2 , V_4 , V_6 -> V_11 , V_6 -> V_18 ,
V_8 -> V_19 ) ;
F_17 ( 0 , V_2 -> V_32 + V_59 ) ;
F_17 ( 0 , V_2 -> V_32 + V_60 ) ;
V_8 -> V_56 &= V_64 ;
if ( ( V_6 -> V_87 & V_88 ) == 0 )
V_8 -> V_56 |= V_89 ;
if ( V_6 -> V_90 == V_91 ) {
F_28 ( V_2 -> V_65 ) ;
V_8 -> V_56 |= V_92 | V_93 ;
if ( V_6 -> V_94 == V_95 ) {
V_8 -> V_85 = V_8 -> V_56 ;
V_8 -> V_56 &= ~ ( V_92 |
V_89 |
V_96 ) ;
V_8 -> V_56 |= V_97 ;
V_8 -> V_84 = 1 ;
} else {
V_8 -> V_84 = 0 ;
}
F_9 ( V_8 -> V_56 , V_2 -> V_32 + V_58 ) ;
if ( V_6 -> V_94 == V_98 )
F_20 ( V_2 -> V_65 , 1 , 2 , true ) ;
} else {
V_8 -> V_56 |= V_97 | V_93 ;
F_9 ( V_8 -> V_56 , V_2 -> V_32 + V_58 ) ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_99 = 0 ;
V_99 |= F_30 ( & V_6 -> V_94 , V_98 | V_95 ) ;
V_99 |= F_30 ( & V_6 -> V_100 , V_101 ) ;
V_99 |= F_30 ( & V_6 -> V_90 ,
V_91 | V_95 ) ;
V_99 |= F_30 ( & V_6 -> V_102 , V_71 ) ;
V_99 |= F_30 ( & V_6 -> V_70 , V_71 | V_103 ) ;
if ( V_99 )
return 1 ;
V_99 |= F_31 ( V_6 -> V_94 ) ;
V_99 |= F_31 ( V_6 -> V_90 ) ;
V_99 |= F_31 ( V_6 -> V_70 ) ;
if ( V_99 )
return 2 ;
V_99 |= F_32 ( & V_6 -> V_104 , 0 ) ;
V_99 |= F_32 ( & V_6 -> V_105 , 0 ) ;
if ( V_6 -> V_90 == V_91 )
V_99 |= F_33 ( & V_6 -> V_106 , 10000 ) ;
else
V_99 |= F_32 ( & V_6 -> V_106 , 0 ) ;
V_99 |= F_32 ( & V_6 -> V_107 ,
V_6 -> V_18 ) ;
if ( V_6 -> V_70 == V_71 )
V_99 |= F_33 ( & V_6 -> V_73 , 1 ) ;
else
V_99 |= F_32 ( & V_6 -> V_73 , 0 ) ;
if ( V_99 )
return 3 ;
if ( V_6 -> V_90 == V_91 ) {
unsigned int V_108 = V_6 -> V_106 ;
F_34 ( V_2 -> V_65 , & V_108 , V_6 -> V_87 ) ;
V_99 |= F_32 ( & V_6 -> V_106 , V_108 ) ;
}
if ( V_99 )
return 4 ;
V_99 |= F_1 ( V_2 , V_4 , V_6 ) ;
if ( V_99 )
return 5 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_37 * V_38 ,
unsigned int * V_54 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_20 = F_2 ( V_38 -> V_61 ) ;
unsigned int V_27 = F_5 ( V_38 -> V_61 ) ;
unsigned int V_45 = V_4 -> V_109 [ V_20 ] ;
int V_17 ;
V_8 -> V_110 &= ~ F_36 ( V_20 ) ;
V_8 -> V_110 |= F_37 ( V_20 , V_27 ) ;
F_9 ( V_8 -> V_110 , V_2 -> V_32 + V_111 ) ;
for ( V_17 = 0 ; V_17 < V_38 -> V_62 ; V_17 ++ ) {
V_45 = V_54 [ V_17 ] ;
F_9 ( V_45 , V_2 -> V_32 + F_38 ( V_20 ) ) ;
}
V_4 -> V_109 [ V_20 ] = V_45 ;
return V_38 -> V_62 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_37 * V_38 ,
unsigned int * V_54 )
{
V_54 [ 1 ] = F_14 ( V_2 -> V_32 + V_112 ) ;
return V_38 -> V_62 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_37 * V_38 ,
unsigned int * V_54 )
{
if ( F_41 ( V_4 , V_54 ) )
F_9 ( V_4 -> V_113 , V_2 -> V_32 + V_114 ) ;
V_54 [ 1 ] = V_4 -> V_113 ;
return V_38 -> V_62 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_37 * V_38 ,
unsigned int * V_54 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
switch ( V_54 [ 0 ] ) {
case V_115 :
switch ( V_54 [ 1 ] ) {
case 0 :
V_8 -> V_85 &= ~ V_64 ;
break;
case 1 :
V_8 -> V_85 |= V_64 ;
break;
default:
return - V_24 ;
}
F_9 ( V_8 -> V_85 , V_2 -> V_32 + V_58 ) ;
break;
case V_116 :
if ( V_8 -> V_85 & V_64 ) {
V_54 [ 1 ] = 1 ;
V_54 [ 2 ] = 0 ;
} else {
V_54 [ 1 ] = 0 ;
V_54 [ 2 ] = V_117 ;
}
break;
default:
return - V_24 ;
}
return V_38 -> V_62 ;
}
static void F_43 ( struct V_1 * V_2 )
{
const struct V_46 * V_47 = V_2 -> V_48 ;
F_9 ( 0 , V_2 -> V_32 + V_58 ) ;
F_17 ( 0 , V_2 -> V_32 + V_59 ) ;
F_17 ( 0 , V_2 -> V_32 + V_60 ) ;
if ( V_47 -> V_118 ) {
F_17 ( 0 , V_2 -> V_32 + V_111 ) ;
F_9 ( 0 , V_2 -> V_32 + F_38 ( 0 ) ) ;
F_9 ( 0 , V_2 -> V_32 + F_38 ( 1 ) ) ;
}
F_9 ( 0 , V_2 -> V_32 + V_114 ) ;
}
static int F_44 ( struct V_1 * V_2 ,
unsigned long V_39 )
{
struct V_119 * V_120 = F_45 ( V_2 ) ;
const struct V_46 * V_47 = NULL ;
struct V_7 * V_8 ;
struct V_3 * V_4 ;
int V_55 , V_121 , V_122 ;
int V_17 ;
if ( V_39 < F_46 ( V_123 ) )
V_47 = & V_123 [ V_39 ] ;
if ( ! V_47 )
return - V_124 ;
V_2 -> V_48 = V_47 ;
V_2 -> V_125 = V_47 -> V_126 ;
V_8 = F_47 ( V_2 , sizeof( * V_8 ) ) ;
if ( ! V_8 )
return - V_127 ;
V_55 = F_48 ( V_2 ) ;
if ( V_55 )
return V_55 ;
V_2 -> V_32 = F_49 ( V_120 , 2 ) ;
V_2 -> V_65 = F_50 ( V_2 -> V_32 + V_128 ,
V_129 , V_130 , 0 ) ;
if ( ! V_2 -> V_65 )
return - V_127 ;
V_122 = 1 ;
if ( V_47 -> V_118 )
V_122 ++ ;
if ( ! V_47 -> V_51 ) {
V_122 += 3 ;
}
V_55 = F_51 ( V_2 , V_122 ) ;
if ( V_55 )
return V_55 ;
F_43 ( V_2 ) ;
if ( V_120 -> V_78 ) {
V_55 = F_52 ( V_120 -> V_78 , F_25 ,
V_131 , V_2 -> V_125 , V_2 ) ;
if ( V_55 == 0 )
V_2 -> V_78 = V_120 -> V_78 ;
}
V_121 = 0 ;
V_4 = & V_2 -> V_132 [ V_121 ++ ] ;
V_4 -> type = V_133 ;
V_4 -> V_134 = V_135 | V_136 ;
if ( ! V_47 -> V_137 )
V_4 -> V_134 |= V_138 ;
V_4 -> V_14 = V_47 -> V_51 ? 32 : 16 ;
V_4 -> V_53 = 0x0fff ;
V_4 -> V_139 = V_47 -> V_140 ;
V_4 -> V_141 = F_16 ;
if ( V_2 -> V_78 ) {
V_2 -> V_82 = V_4 ;
V_4 -> V_134 |= V_142 ;
V_4 -> V_143 = V_4 -> V_14 ;
V_4 -> V_144 = F_29 ;
V_4 -> V_145 = F_27 ;
V_4 -> V_146 = F_19 ;
}
for ( V_17 = 0 ; V_17 < V_4 -> V_139 -> V_147 ; V_17 ++ ) {
if ( F_7 ( V_4 , V_17 ) ) {
V_8 -> V_31 = V_17 ;
break;
}
}
if ( V_47 -> V_118 ) {
V_4 = & V_2 -> V_132 [ V_121 ++ ] ;
V_4 -> type = V_148 ;
V_4 -> V_134 = V_149 | V_136 ;
V_4 -> V_14 = 2 ;
V_4 -> V_53 = 0x0fff ;
V_4 -> V_139 = & V_150 ;
V_4 -> V_151 = F_35 ;
V_55 = F_53 ( V_4 ) ;
if ( V_55 )
return V_55 ;
}
if ( ! V_47 -> V_51 ) {
V_4 = & V_2 -> V_132 [ V_121 ++ ] ;
V_4 -> type = V_152 ;
V_4 -> V_134 = V_135 ;
V_4 -> V_14 = 16 ;
V_4 -> V_53 = 1 ;
V_4 -> V_139 = & V_153 ;
V_4 -> V_154 = F_39 ;
V_4 = & V_2 -> V_132 [ V_121 ++ ] ;
V_4 -> type = V_155 ;
V_4 -> V_134 = V_149 ;
V_4 -> V_14 = 16 ;
V_4 -> V_53 = 1 ;
V_4 -> V_139 = & V_153 ;
V_4 -> V_154 = F_40 ;
V_4 = & V_2 -> V_132 [ V_121 ++ ] ;
F_54 ( V_4 , V_2 -> V_65 ) ;
V_2 -> V_65 -> V_156 = F_42 ;
F_55 ( V_2 -> V_65 , 1 , true ) ;
F_55 ( V_2 -> V_65 , 2 , true ) ;
}
V_8 -> V_77 = ( V_47 -> V_137 ) ? 512 : 2048 ;
return 0 ;
}
static int F_56 ( struct V_119 * V_2 ,
const struct V_157 * V_158 )
{
return F_57 ( V_2 , & V_159 ,
V_158 -> V_160 ) ;
}
