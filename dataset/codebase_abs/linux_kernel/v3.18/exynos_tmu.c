static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
switch ( V_5 -> V_7 ) {
case V_8 :
V_6 = ( V_3 - V_5 -> V_9 ) *
( V_2 -> V_10 - V_2 -> V_11 ) /
( V_5 -> V_12 - V_5 -> V_9 ) +
V_2 -> V_11 ;
break;
case V_13 :
V_6 = V_3 + V_2 -> V_11 - V_5 -> V_9 ;
break;
default:
V_6 = V_3 + V_5 -> V_14 ;
break;
}
return V_6 ;
}
static int F_2 ( struct V_1 * V_2 , T_1 V_6 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_3 ;
switch ( V_5 -> V_7 ) {
case V_8 :
V_3 = ( V_6 - V_2 -> V_11 ) *
( V_5 -> V_12 - V_5 -> V_9 ) /
( V_2 -> V_10 - V_2 -> V_11 ) +
V_5 -> V_9 ;
break;
case V_13 :
V_3 = V_6 - V_2 -> V_11 + V_5 -> V_9 ;
break;
default:
V_3 = V_6 - V_5 -> V_14 ;
break;
}
return V_3 ;
}
static void F_3 ( struct V_1 * V_2 )
{
const struct V_15 * V_16 = V_2 -> V_5 -> V_17 ;
unsigned int V_18 ;
V_18 = F_4 ( V_2 -> V_19 + V_16 -> V_20 ) ;
F_5 ( V_18 , V_2 -> V_19 + V_16 -> V_21 ) ;
}
static int F_6 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_7 ( V_23 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
const struct V_15 * V_16 = V_5 -> V_17 ;
unsigned int V_24 , V_25 = 0 , V_26 , V_27 ;
unsigned int V_28 = 0 , V_29 = 0 ;
int V_30 = 0 , V_31 , V_32 ;
F_8 ( & V_2 -> V_33 ) ;
F_9 ( V_2 -> V_34 ) ;
if ( ! F_10 ( V_2 -> V_35 ) )
F_9 ( V_2 -> V_35 ) ;
if ( F_11 ( V_5 , V_36 ) ) {
V_24 = F_12 ( V_2 -> V_19 + V_16 -> V_37 ) ;
if ( ! V_24 ) {
V_30 = - V_38 ;
goto V_39;
}
}
if ( F_11 ( V_5 , V_40 ) ) {
for ( V_32 = 0 ; V_32 < V_16 -> V_41 ; V_32 ++ ) {
if ( V_5 -> V_42 [ V_32 ] ) {
V_27 = F_4 ( V_2 -> V_19 +
V_16 -> V_43 [ V_32 ] ) ;
V_27 |= V_5 -> V_42 [ V_32 ] ;
F_5 ( V_27 , V_2 -> V_19 +
V_16 -> V_43 [ V_32 ] ) ;
}
}
}
if ( V_2 -> V_44 == V_45 ) {
switch ( V_2 -> V_46 ) {
case 0 :
V_25 = F_4 ( V_2 -> V_19 +
V_47 + V_16 -> V_48 ) ;
break;
case 1 :
V_25 = F_4 ( V_2 -> V_19 + V_16 -> V_48 ) ;
break;
case 2 :
V_25 = F_4 ( V_2 -> V_19 -
V_47 + V_16 -> V_48 ) ;
}
} else {
if ( V_2 -> V_44 == V_49 )
V_25 = F_4 ( V_2 -> V_50 +
V_16 -> V_48 ) ;
else
V_25 = F_4 ( V_2 -> V_19 + V_16 -> V_48 ) ;
}
V_2 -> V_11 = V_25 & V_51 ;
V_2 -> V_10 = ( ( V_25 >> V_52 ) &
V_51 ) ;
if ( ! V_2 -> V_11 ||
( V_5 -> V_53 > V_2 -> V_11 ) ||
( V_2 -> V_11 > V_5 -> V_54 ) )
V_2 -> V_11 = V_5 -> V_55 & V_51 ;
if ( ! V_2 -> V_10 )
V_2 -> V_10 =
( V_5 -> V_55 >> V_52 ) &
V_51 ;
V_28 = F_4 ( V_2 -> V_19 + V_16 -> V_56 ) ;
if ( V_2 -> V_44 == V_57 ) {
V_31 = F_1 ( V_2 , V_5 -> V_58 ) ;
F_13 ( V_31 ,
V_2 -> V_19 + V_16 -> V_59 ) ;
for ( V_32 = 0 ; V_32 < V_5 -> V_60 ; V_32 ++ )
F_13 ( V_5 -> V_61 [ V_32 ] , V_2 -> V_19 +
V_16 -> V_56 + V_32 * sizeof( V_16 -> V_56 ) ) ;
F_3 ( V_2 ) ;
} else {
for ( V_32 = 0 ; V_32 < V_5 -> V_60 ; V_32 ++ ) {
V_31 = F_1 ( V_2 ,
V_5 -> V_61 [ V_32 ] ) ;
V_28 &= ~ ( 0xff << 8 * V_32 ) ;
V_28 |= V_31 << 8 * V_32 ;
if ( V_5 -> V_62 ) {
V_31 = F_1 ( V_2 ,
V_5 -> V_61 [ V_32 ] -
V_5 -> V_62 ) ;
V_29 |= V_31 << 8 * V_32 ;
}
}
F_5 ( V_28 ,
V_2 -> V_19 + V_16 -> V_56 ) ;
F_5 ( V_29 ,
V_2 -> V_19 + V_16 -> V_63 ) ;
F_3 ( V_2 ) ;
V_32 = V_5 -> V_64 - 1 ;
if ( V_5 -> V_61 [ V_32 ] &&
( V_5 -> V_65 [ V_32 ] == V_66 ) ) {
V_31 = F_1 ( V_2 ,
V_5 -> V_61 [ V_32 ] ) ;
if ( V_32 == V_67 - 1 ) {
V_28 &= ~ ( 0xff << 8 * V_32 ) ;
V_28 |= V_31 << 8 * V_32 ;
F_5 ( V_28 ,
V_2 -> V_19 + V_16 -> V_56 ) ;
} else if ( V_32 == V_67 ) {
V_28 =
V_31 << V_16 -> V_68 ;
F_5 ( V_28 ,
V_2 -> V_19 + V_16 -> V_69 ) ;
}
V_26 = F_4 ( V_2 -> V_19 + V_16 -> V_70 ) ;
V_26 |= ( 1 << V_16 -> V_71 ) ;
F_5 ( V_26 , V_2 -> V_19 + V_16 -> V_70 ) ;
}
}
if ( V_16 -> V_72 && ! V_2 -> V_46 )
F_5 ( 0 , V_2 -> V_50 + V_16 -> V_72 ) ;
V_39:
F_14 ( V_2 -> V_34 ) ;
F_15 ( & V_2 -> V_33 ) ;
if ( ! F_10 ( V_2 -> V_35 ) )
F_14 ( V_2 -> V_35 ) ;
return V_30 ;
}
static void F_16 ( struct V_22 * V_23 , bool V_73 )
{
struct V_1 * V_2 = F_7 ( V_23 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
const struct V_15 * V_16 = V_5 -> V_17 ;
unsigned int V_26 , V_74 ;
F_8 ( & V_2 -> V_33 ) ;
F_9 ( V_2 -> V_34 ) ;
V_26 = F_4 ( V_2 -> V_19 + V_16 -> V_70 ) ;
if ( V_5 -> V_75 )
V_26 |= ( V_5 -> V_75 << V_16 -> V_76 ) ;
V_26 &= ~ ( V_77 << V_78 ) ;
V_26 |= V_5 -> V_79 << V_78 ;
V_26 &= ~ ( V_80 << V_81 ) ;
V_26 |= ( V_5 -> V_82 << V_81 ) ;
if ( V_5 -> V_83 ) {
V_26 &= ~ ( V_16 -> V_84 <<
V_16 -> V_85 ) ;
V_26 |= ( V_5 -> V_83 << V_16 -> V_85 ) ;
}
if ( V_73 ) {
V_26 |= ( 1 << V_86 ) ;
V_74 =
V_5 -> V_87 [ 3 ] << V_16 -> V_88 |
V_5 -> V_87 [ 2 ] << V_16 -> V_89 |
V_5 -> V_87 [ 1 ] << V_16 -> V_90 |
V_5 -> V_87 [ 0 ] << V_16 -> V_91 ;
if ( F_11 ( V_5 , V_92 ) )
V_74 |=
V_74 << V_16 -> V_93 ;
} else {
V_26 &= ~ ( 1 << V_86 ) ;
V_74 = 0 ;
}
F_5 ( V_74 , V_2 -> V_19 + V_16 -> V_94 ) ;
F_5 ( V_26 , V_2 -> V_19 + V_16 -> V_70 ) ;
F_14 ( V_2 -> V_34 ) ;
F_15 ( & V_2 -> V_33 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
const struct V_15 * V_16 = V_5 -> V_17 ;
T_1 V_6 ;
int V_3 ;
F_8 ( & V_2 -> V_33 ) ;
F_9 ( V_2 -> V_34 ) ;
V_6 = F_12 ( V_2 -> V_19 + V_16 -> V_95 ) ;
if ( V_2 -> V_44 == V_57 )
if ( V_6 < 75 || V_6 > 175 ) {
V_3 = - V_96 ;
goto V_39;
}
V_3 = F_2 ( V_2 , V_6 ) ;
V_39:
F_14 ( V_2 -> V_34 ) ;
F_15 ( & V_2 -> V_33 ) ;
return V_3 ;
}
static int F_18 ( void * V_97 , unsigned long V_3 )
{
struct V_1 * V_2 = V_97 ;
struct V_4 * V_5 = V_2 -> V_5 ;
const struct V_15 * V_16 = V_5 -> V_17 ;
unsigned int V_98 ;
int V_30 = - V_99 ;
if ( ! F_11 ( V_5 , V_100 ) )
goto V_39;
if ( V_3 && V_3 < V_101 )
goto V_39;
F_8 ( & V_2 -> V_33 ) ;
F_9 ( V_2 -> V_34 ) ;
V_98 = F_4 ( V_2 -> V_19 + V_16 -> V_102 ) ;
if ( V_3 ) {
V_3 /= V_101 ;
if ( F_11 ( V_5 , V_103 ) ) {
V_98 &= ~ ( V_104 << V_16 -> V_105 ) ;
V_98 |= ( V_106 << V_16 -> V_105 ) ;
}
V_98 &= ~ ( V_107 << V_16 -> V_108 ) ;
V_98 |= ( F_1 ( V_2 , V_3 ) << V_16 -> V_108 ) |
V_109 ;
} else {
V_98 &= ~ V_109 ;
}
F_5 ( V_98 , V_2 -> V_19 + V_16 -> V_102 ) ;
F_14 ( V_2 -> V_34 ) ;
F_15 ( & V_2 -> V_33 ) ;
return 0 ;
V_39:
return V_30 ;
}
static int F_18 ( void * V_97 , unsigned long V_3 )
{ return - V_99 ; }
static void F_19 ( struct V_110 * V_111 )
{
struct V_1 * V_2 = F_20 ( V_111 ,
struct V_1 , V_112 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
const struct V_15 * V_16 = V_5 -> V_17 ;
unsigned int V_113 ;
if ( ! F_10 ( V_2 -> V_35 ) )
F_9 ( V_2 -> V_35 ) ;
if ( V_16 -> V_114 ) {
V_113 = F_4 ( V_2 -> V_50 + V_16 -> V_114 ) ;
if ( ! ( ( V_113 >> V_2 -> V_46 ) & 0x1 ) )
goto V_39;
}
if ( ! F_10 ( V_2 -> V_35 ) )
F_14 ( V_2 -> V_35 ) ;
F_21 ( V_2 -> V_115 ) ;
F_8 ( & V_2 -> V_33 ) ;
F_9 ( V_2 -> V_34 ) ;
F_3 ( V_2 ) ;
F_14 ( V_2 -> V_34 ) ;
F_15 ( & V_2 -> V_33 ) ;
V_39:
F_22 ( V_2 -> V_116 ) ;
}
static T_2 F_23 ( int V_116 , void * V_46 )
{
struct V_1 * V_2 = V_46 ;
F_24 ( V_116 ) ;
F_25 ( & V_2 -> V_112 ) ;
return V_117 ;
}
static inline struct V_4 * F_26 (
struct V_22 * V_23 , int V_46 )
{
struct V_118 * V_119 ;
struct V_4 * V_120 ;
const struct V_121 * V_122 ;
V_122 = F_27 ( V_123 , V_23 -> V_124 . V_125 ) ;
if ( ! V_122 )
return NULL ;
V_119 = (struct V_118 * ) V_122 -> V_2 ;
if ( ! V_119 || V_46 >= V_119 -> V_126 )
return NULL ;
V_120 = V_119 -> V_120 ;
return (struct V_4 * ) ( V_120 + V_46 ) ;
}
static int F_28 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_7 ( V_23 ) ;
struct V_4 * V_5 ;
struct V_127 V_128 ;
int V_30 ;
if ( ! V_2 || ! V_23 -> V_124 . V_125 )
return - V_129 ;
V_2 -> V_130 = F_29 ( & V_23 -> V_124 , L_1 ) ;
if ( ! F_10 ( V_2 -> V_130 ) ) {
V_30 = F_30 ( V_2 -> V_130 ) ;
if ( V_30 ) {
F_31 ( & V_23 -> V_124 , L_2 ) ;
return V_30 ;
}
} else {
F_32 ( & V_23 -> V_124 , L_3 ) ;
}
V_2 -> V_46 = F_33 ( V_23 -> V_124 . V_125 , L_4 ) ;
if ( V_2 -> V_46 < 0 )
V_2 -> V_46 = 0 ;
V_2 -> V_116 = F_34 ( V_23 -> V_124 . V_125 , 0 ) ;
if ( V_2 -> V_116 <= 0 ) {
F_31 ( & V_23 -> V_124 , L_5 ) ;
return - V_129 ;
}
if ( F_35 ( V_23 -> V_124 . V_125 , 0 , & V_128 ) ) {
F_31 ( & V_23 -> V_124 , L_6 ) ;
return - V_129 ;
}
V_2 -> V_19 = F_36 ( & V_23 -> V_124 , V_128 . V_131 , F_37 ( & V_128 ) ) ;
if ( ! V_2 -> V_19 ) {
F_31 ( & V_23 -> V_124 , L_7 ) ;
return - V_132 ;
}
V_5 = F_26 ( V_23 , V_2 -> V_46 ) ;
if ( ! V_5 ) {
F_31 ( & V_23 -> V_124 , L_8 ) ;
return - V_129 ;
}
V_2 -> V_5 = V_5 ;
if ( ! F_11 ( V_5 , V_133 ) )
return 0 ;
if ( F_35 ( V_23 -> V_124 . V_125 , 1 , & V_128 ) ) {
F_31 ( & V_23 -> V_124 , L_9 ) ;
return - V_129 ;
}
V_2 -> V_50 = F_36 ( & V_23 -> V_124 , V_128 . V_131 ,
F_37 ( & V_128 ) ) ;
if ( ! V_2 -> V_50 ) {
F_31 ( & V_23 -> V_124 , L_7 ) ;
return - V_134 ;
}
return 0 ;
}
static int F_38 ( struct V_22 * V_23 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_135 * V_136 ;
int V_30 , V_32 ;
V_2 = F_39 ( & V_23 -> V_124 , sizeof( struct V_1 ) ,
V_137 ) ;
if ( ! V_2 )
return - V_134 ;
F_40 ( V_23 , V_2 ) ;
F_41 ( & V_2 -> V_33 ) ;
V_30 = F_28 ( V_23 ) ;
if ( V_30 )
return V_30 ;
V_5 = V_2 -> V_5 ;
F_42 ( & V_2 -> V_112 , F_19 ) ;
V_2 -> V_34 = F_43 ( & V_23 -> V_124 , L_10 ) ;
if ( F_10 ( V_2 -> V_34 ) ) {
F_31 ( & V_23 -> V_124 , L_11 ) ;
return F_44 ( V_2 -> V_34 ) ;
}
V_2 -> V_35 = F_43 ( & V_23 -> V_124 , L_12 ) ;
if ( F_10 ( V_2 -> V_35 ) ) {
if ( V_2 -> V_44 == V_49 ) {
F_31 ( & V_23 -> V_124 , L_13 ) ;
return F_44 ( V_2 -> V_35 ) ;
}
} else {
V_30 = F_45 ( V_2 -> V_35 ) ;
if ( V_30 ) {
F_31 ( & V_23 -> V_124 , L_11 ) ;
return V_30 ;
}
}
V_30 = F_45 ( V_2 -> V_34 ) ;
if ( V_30 ) {
F_31 ( & V_23 -> V_124 , L_11 ) ;
goto V_138;
}
if ( V_5 -> type == V_139 ||
V_5 -> type == V_57 ||
V_5 -> type == V_140 ||
V_5 -> type == V_141 ||
V_5 -> type == V_142 ||
V_5 -> type == V_49 ||
V_5 -> type == V_45 )
V_2 -> V_44 = V_5 -> type ;
else {
V_30 = - V_99 ;
F_31 ( & V_23 -> V_124 , L_14 ) ;
goto V_143;
}
V_30 = F_6 ( V_23 ) ;
if ( V_30 ) {
F_31 ( & V_23 -> V_124 , L_15 ) ;
goto V_143;
}
F_16 ( V_23 , true ) ;
V_136 = F_39 ( & V_23 -> V_124 ,
sizeof( struct V_135 ) , V_137 ) ;
if ( ! V_136 ) {
V_30 = - V_134 ;
goto V_143;
}
sprintf ( V_136 -> V_144 , L_16 , V_2 -> V_46 ) ;
V_136 -> V_145 = ( int ( * ) ( void * ) ) F_17 ;
V_136 -> V_146 =
( int (*) ( void * , unsigned long ) ) F_18 ;
V_136 -> V_147 = V_2 ;
V_136 -> V_148 . V_149 = V_5 -> V_87 [ 0 ] +
V_5 -> V_87 [ 1 ] + V_5 -> V_87 [ 2 ] +
V_5 -> V_87 [ 3 ] ;
for ( V_32 = 0 ; V_32 < V_136 -> V_148 . V_149 ; V_32 ++ ) {
V_136 -> V_148 . V_150 [ V_32 ] =
V_5 -> V_58 + V_5 -> V_61 [ V_32 ] ;
V_136 -> V_148 . V_151 [ V_32 ] =
V_5 -> V_65 [ V_32 ] ;
}
V_136 -> V_148 . V_152 = V_5 -> V_62 ;
V_136 -> V_153 . V_154 = V_5 -> V_155 ;
for ( V_32 = 0 ; V_32 < V_5 -> V_155 ; V_32 ++ ) {
V_136 -> V_153 . V_156 [ V_32 ] . V_157 =
V_5 -> V_158 [ V_32 ] . V_157 ;
V_136 -> V_153 . V_156 [ V_32 ] . V_159 =
V_5 -> V_158 [ V_32 ] . V_159 ;
}
V_136 -> V_124 = & V_23 -> V_124 ;
V_30 = F_46 ( V_136 ) ;
if ( V_30 ) {
F_31 ( & V_23 -> V_124 , L_17 ) ;
goto V_143;
}
V_2 -> V_115 = V_136 ;
V_30 = F_47 ( & V_23 -> V_124 , V_2 -> V_116 , F_23 ,
V_160 | V_161 , F_48 ( & V_23 -> V_124 ) , V_2 ) ;
if ( V_30 ) {
F_31 ( & V_23 -> V_124 , L_18 , V_2 -> V_116 ) ;
goto V_143;
}
return 0 ;
V_143:
F_49 ( V_2 -> V_34 ) ;
V_138:
if ( ! F_10 ( V_2 -> V_35 ) )
F_49 ( V_2 -> V_35 ) ;
return V_30 ;
}
static int F_50 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_7 ( V_23 ) ;
F_51 ( V_2 -> V_115 ) ;
F_16 ( V_23 , false ) ;
F_49 ( V_2 -> V_34 ) ;
if ( ! F_10 ( V_2 -> V_35 ) )
F_49 ( V_2 -> V_35 ) ;
if ( ! F_10 ( V_2 -> V_130 ) )
F_52 ( V_2 -> V_130 ) ;
return 0 ;
}
static int F_53 ( struct V_162 * V_124 )
{
F_16 ( F_54 ( V_124 ) , false ) ;
return 0 ;
}
static int F_55 ( struct V_162 * V_124 )
{
struct V_22 * V_23 = F_54 ( V_124 ) ;
F_6 ( V_23 ) ;
F_16 ( V_23 , true ) ;
return 0 ;
}
