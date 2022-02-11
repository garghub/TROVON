static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
if ( V_5 -> V_7 == V_8 )
return V_3 ;
if ( V_2 -> V_9 == V_10 )
if ( V_3 < 25 || V_3 > 125 ) {
V_6 = - V_11 ;
goto V_12;
}
switch ( V_5 -> V_13 ) {
case V_14 :
V_6 = ( V_3 - V_5 -> V_15 ) *
( V_2 -> V_16 - V_2 -> V_17 ) /
( V_5 -> V_18 - V_5 -> V_15 ) +
V_2 -> V_17 ;
break;
case V_19 :
V_6 = V_3 + V_2 -> V_17 - V_5 -> V_15 ;
break;
default:
V_6 = V_3 + V_5 -> V_20 ;
break;
}
V_12:
return V_6 ;
}
static int F_2 ( struct V_1 * V_2 , T_1 V_6 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_3 ;
if ( V_5 -> V_7 == V_8 )
return V_6 ;
if ( V_2 -> V_9 == V_10 )
if ( V_6 < 75 || V_6 > 175 ) {
V_3 = - V_21 ;
goto V_12;
}
switch ( V_5 -> V_13 ) {
case V_14 :
V_3 = ( V_6 - V_2 -> V_17 ) *
( V_5 -> V_18 - V_5 -> V_15 ) /
( V_2 -> V_16 - V_2 -> V_17 ) +
V_5 -> V_15 ;
break;
case V_19 :
V_3 = V_6 - V_2 -> V_17 + V_5 -> V_15 ;
break;
default:
V_3 = V_6 - V_5 -> V_20 ;
break;
}
V_12:
return V_3 ;
}
static int F_3 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_4 ( V_23 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
const struct V_24 * V_25 = V_5 -> V_26 ;
unsigned int V_27 , V_28 = 0 , V_29 ;
unsigned int V_30 = 0 , V_31 = 0 ;
int V_32 = 0 , V_33 , V_34 , V_35 = 0 ;
F_5 ( & V_2 -> V_36 ) ;
F_6 ( V_2 -> V_37 ) ;
if ( F_7 ( V_5 , V_38 ) ) {
V_27 = F_8 ( V_2 -> V_39 + V_25 -> V_40 ) ;
if ( ! V_27 ) {
V_32 = - V_41 ;
goto V_12;
}
}
if ( F_7 ( V_5 , V_42 ) )
F_9 ( 1 , V_2 -> V_39 + V_25 -> V_43 ) ;
if ( V_5 -> V_7 == V_8 )
goto V_44;
if ( V_2 -> V_9 == V_45 ) {
switch ( V_2 -> V_46 ) {
case 0 :
V_28 = F_10 ( V_2 -> V_39 +
V_47 + V_25 -> V_48 ) ;
break;
case 1 :
V_28 = F_10 ( V_2 -> V_39 + V_25 -> V_48 ) ;
break;
case 2 :
V_28 = F_10 ( V_2 -> V_39 -
V_47 + V_25 -> V_48 ) ;
}
} else {
V_28 = F_10 ( V_2 -> V_39 + V_25 -> V_48 ) ;
}
V_2 -> V_17 = V_28 & V_49 ;
V_2 -> V_16 = ( ( V_28 >> V_25 -> V_50 ) &
V_49 ) ;
if ( ! V_2 -> V_17 ||
( V_5 -> V_51 > V_2 -> V_17 ) ||
( V_2 -> V_17 > V_5 -> V_52 ) )
V_2 -> V_17 = V_5 -> V_53 & V_49 ;
if ( ! V_2 -> V_16 )
V_2 -> V_16 =
( V_5 -> V_53 >> V_25 -> V_50 ) &
V_49 ;
V_44:
if ( V_5 -> V_54 > V_55 ) {
F_11 ( & V_23 -> V_56 , L_1 ) ;
goto V_12;
}
for ( V_34 = 0 ; V_34 < V_5 -> V_54 ; V_34 ++ ) {
if ( ! V_5 -> V_57 [ V_34 ] )
continue;
if ( ( V_5 -> V_58 [ V_34 ] == V_59 ) &&
( ! V_5 -> V_57 [ V_5 -> V_54 - 1 ] ) ) {
F_11 ( & V_23 -> V_56 , L_2 ) ;
V_32 = - V_11 ;
goto V_12;
}
if ( ! ( V_5 -> V_58 [ V_34 ] == V_59 ) )
V_35 ++ ;
}
if ( V_2 -> V_9 == V_10 ) {
V_33 = F_1 ( V_2 , V_5 -> V_60 ) ;
if ( V_33 < 0 ) {
V_32 = V_33 ;
goto V_12;
}
F_12 ( V_33 ,
V_2 -> V_39 + V_25 -> V_61 ) ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ )
F_12 ( V_5 -> V_57 [ V_34 ] , V_2 -> V_39 +
V_25 -> V_62 + V_34 * sizeof( V_25 -> V_62 ) ) ;
F_13 ( V_25 -> V_63 , V_2 -> V_39 + V_25 -> V_64 ) ;
} else {
for ( V_34 = 0 ;
V_34 < V_35 && V_34 < V_65 ; V_34 ++ ) {
V_33 = F_1 ( V_2 ,
V_5 -> V_57 [ V_34 ] ) ;
if ( V_33 < 0 ) {
V_32 = V_33 ;
goto V_12;
}
V_30 |= V_33 << 8 * V_34 ;
if ( V_5 -> V_66 ) {
V_33 = F_1 ( V_2 ,
V_5 -> V_57 [ V_34 ] -
V_5 -> V_66 ) ;
if ( V_33 > 0 )
V_31 |=
V_33 << 8 * V_34 ;
}
}
F_13 ( V_30 ,
V_2 -> V_39 + V_25 -> V_62 ) ;
F_13 ( V_31 ,
V_2 -> V_39 + V_25 -> V_67 ) ;
F_13 ( ( V_25 -> V_63 << V_25 -> V_68 ) |
( V_25 -> V_69 << V_25 -> V_70 ) ,
V_2 -> V_39 + V_25 -> V_64 ) ;
V_34 = V_5 -> V_54 - 1 ;
if ( V_5 -> V_57 [ V_34 ] &&
( V_5 -> V_58 [ V_34 ] == V_59 ) ) {
V_33 = F_1 ( V_2 ,
V_5 -> V_57 [ V_34 ] ) ;
if ( V_33 < 0 ) {
V_32 = V_33 ;
goto V_12;
}
if ( V_34 == V_65 - 1 ) {
V_30 |= V_33 << 8 * V_34 ;
F_13 ( V_30 ,
V_2 -> V_39 + V_25 -> V_62 ) ;
} else if ( V_34 == V_65 ) {
V_30 =
V_33 << V_25 -> V_71 ;
F_13 ( V_30 ,
V_2 -> V_39 + V_25 -> V_72 ) ;
}
V_29 = F_10 ( V_2 -> V_39 + V_25 -> V_73 ) ;
V_29 |= ( 1 << V_25 -> V_74 ) ;
F_13 ( V_29 , V_2 -> V_39 + V_25 -> V_73 ) ;
}
}
if ( V_25 -> V_75 && ! V_2 -> V_46 )
F_13 ( 0 , V_2 -> V_76 + V_25 -> V_75 ) ;
V_12:
F_14 ( V_2 -> V_37 ) ;
F_15 ( & V_2 -> V_36 ) ;
return V_32 ;
}
static void F_16 ( struct V_22 * V_23 , bool V_77 )
{
struct V_1 * V_2 = F_4 ( V_23 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
const struct V_24 * V_25 = V_5 -> V_26 ;
unsigned int V_29 , V_78 , V_79 ;
F_5 ( & V_2 -> V_36 ) ;
F_6 ( V_2 -> V_37 ) ;
V_29 = F_10 ( V_2 -> V_39 + V_25 -> V_73 ) ;
if ( V_5 -> V_80 )
V_29 |= ( V_5 -> V_80 << V_25 -> V_81 ) ;
if ( V_5 -> V_82 ) {
V_29 &= ~ ( V_25 -> V_83 << V_25 -> V_84 ) ;
V_29 |= V_5 -> V_82 << V_25 -> V_84 ;
}
if ( V_5 -> V_85 ) {
V_29 &= ~ ( V_25 -> V_86 << V_25 -> V_87 ) ;
V_29 |= ( V_5 -> V_85 << V_25 -> V_87 ) ;
}
if ( V_5 -> V_88 ) {
V_29 &= ~ ( V_25 -> V_89 <<
V_25 -> V_90 ) ;
V_29 |= ( V_5 -> V_88 << V_25 -> V_90 ) ;
}
if ( V_5 -> V_7 == V_8 ) {
V_29 &= ~ ( V_25 -> V_91 << V_25 -> V_92 ) ;
V_79 = 0 ;
switch ( V_5 -> V_13 ) {
case V_14 :
V_79 = 3 ;
break;
case V_93 :
V_79 = 2 ;
break;
case V_94 :
V_79 = 1 ;
break;
case V_95 :
break;
default:
F_11 ( & V_23 -> V_56 , L_3 ) ;
}
V_29 |= V_79 << V_25 -> V_92 ;
}
if ( V_77 ) {
V_29 |= ( 1 << V_25 -> V_96 ) ;
V_78 =
V_5 -> V_97 [ 3 ] << V_25 -> V_98 |
V_5 -> V_97 [ 2 ] << V_25 -> V_99 |
V_5 -> V_97 [ 1 ] << V_25 -> V_100 |
V_5 -> V_97 [ 0 ] << V_25 -> V_101 ;
if ( F_7 ( V_5 , V_102 ) )
V_78 |=
V_78 << V_25 -> V_103 ;
} else {
V_29 &= ~ ( 1 << V_25 -> V_96 ) ;
V_78 = 0 ;
}
F_13 ( V_78 , V_2 -> V_39 + V_25 -> V_104 ) ;
F_13 ( V_29 , V_2 -> V_39 + V_25 -> V_73 ) ;
F_14 ( V_2 -> V_37 ) ;
F_15 ( & V_2 -> V_36 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
const struct V_24 * V_25 = V_5 -> V_26 ;
T_1 V_6 ;
int V_3 ;
F_5 ( & V_2 -> V_36 ) ;
F_6 ( V_2 -> V_37 ) ;
V_6 = F_8 ( V_2 -> V_39 + V_25 -> V_105 ) ;
V_3 = F_2 ( V_2 , V_6 ) ;
F_14 ( V_2 -> V_37 ) ;
F_15 ( & V_2 -> V_36 ) ;
return V_3 ;
}
static int F_18 ( void * V_106 , unsigned long V_3 )
{
struct V_1 * V_2 = V_106 ;
struct V_4 * V_5 = V_2 -> V_5 ;
const struct V_24 * V_25 = V_5 -> V_26 ;
unsigned int V_107 ;
int V_32 = - V_11 ;
if ( ! F_7 ( V_5 , V_108 ) )
goto V_12;
if ( V_3 && V_3 < V_109 )
goto V_12;
F_5 ( & V_2 -> V_36 ) ;
F_6 ( V_2 -> V_37 ) ;
V_107 = F_10 ( V_2 -> V_39 + V_25 -> V_110 ) ;
if ( V_3 ) {
V_3 /= V_109 ;
if ( F_7 ( V_5 , V_111 ) ) {
V_107 &= ~ ( V_112 << V_25 -> V_113 ) ;
V_107 |= ( V_114 << V_25 -> V_113 ) ;
}
V_107 &= ~ ( V_115 << V_25 -> V_116 ) ;
V_107 |= ( F_1 ( V_2 , V_3 ) << V_25 -> V_116 ) |
V_117 ;
} else {
V_107 &= ~ V_117 ;
}
F_13 ( V_107 , V_2 -> V_39 + V_25 -> V_110 ) ;
F_14 ( V_2 -> V_37 ) ;
F_15 ( & V_2 -> V_36 ) ;
return 0 ;
V_12:
return V_32 ;
}
static int F_18 ( void * V_106 , unsigned long V_3 )
{ return - V_11 ; }
static void F_19 ( struct V_118 * V_119 )
{
struct V_1 * V_2 = F_20 ( V_119 ,
struct V_1 , V_120 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
const struct V_24 * V_25 = V_5 -> V_26 ;
unsigned int V_121 , V_122 ;
if ( V_25 -> V_123 ) {
V_122 = F_10 ( V_2 -> V_76 + V_25 -> V_123 ) ;
if ( ! ( ( V_122 >> V_2 -> V_46 ) & 0x1 ) )
goto V_12;
}
F_21 ( V_2 -> V_124 ) ;
F_5 ( & V_2 -> V_36 ) ;
F_6 ( V_2 -> V_37 ) ;
V_121 = F_10 ( V_2 -> V_39 + V_25 -> V_125 ) ;
F_13 ( V_121 , V_2 -> V_39 + V_25 -> V_64 ) ;
F_14 ( V_2 -> V_37 ) ;
F_15 ( & V_2 -> V_36 ) ;
V_12:
F_22 ( V_2 -> V_126 ) ;
}
static T_2 F_23 ( int V_126 , void * V_46 )
{
struct V_1 * V_2 = V_46 ;
F_24 ( V_126 ) ;
F_25 ( & V_2 -> V_120 ) ;
return V_127 ;
}
static inline struct V_4 * F_26 (
struct V_22 * V_23 , int V_46 )
{
struct V_128 * V_129 ;
struct V_4 * V_130 ;
const struct V_131 * V_132 ;
V_132 = F_27 ( V_133 , V_23 -> V_56 . V_134 ) ;
if ( ! V_132 )
return NULL ;
V_129 = (struct V_128 * ) V_132 -> V_2 ;
if ( ! V_129 || V_46 >= V_129 -> V_135 )
return NULL ;
V_130 = V_129 -> V_130 ;
return (struct V_4 * ) ( V_130 + V_46 ) ;
}
static int F_28 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_4 ( V_23 ) ;
struct V_4 * V_5 ;
struct V_136 V_137 ;
int V_32 ;
if ( ! V_2 || ! V_23 -> V_56 . V_134 )
return - V_138 ;
V_2 -> V_139 = F_29 ( & V_23 -> V_56 , L_4 ) ;
if ( ! F_30 ( V_2 -> V_139 ) ) {
V_32 = F_31 ( V_2 -> V_139 ) ;
if ( V_32 ) {
F_11 ( & V_23 -> V_56 , L_5 ) ;
return V_32 ;
}
} else {
F_32 ( & V_23 -> V_56 , L_6 ) ;
}
V_2 -> V_46 = F_33 ( V_23 -> V_56 . V_134 , L_7 ) ;
if ( V_2 -> V_46 < 0 )
V_2 -> V_46 = 0 ;
V_2 -> V_126 = F_34 ( V_23 -> V_56 . V_134 , 0 ) ;
if ( V_2 -> V_126 <= 0 ) {
F_11 ( & V_23 -> V_56 , L_8 ) ;
return - V_138 ;
}
if ( F_35 ( V_23 -> V_56 . V_134 , 0 , & V_137 ) ) {
F_11 ( & V_23 -> V_56 , L_9 ) ;
return - V_138 ;
}
V_2 -> V_39 = F_36 ( & V_23 -> V_56 , V_137 . V_140 , F_37 ( & V_137 ) ) ;
if ( ! V_2 -> V_39 ) {
F_11 ( & V_23 -> V_56 , L_10 ) ;
return - V_141 ;
}
V_5 = F_26 ( V_23 , V_2 -> V_46 ) ;
if ( ! V_5 ) {
F_11 ( & V_23 -> V_56 , L_11 ) ;
return - V_138 ;
}
V_2 -> V_5 = V_5 ;
if ( ! F_7 ( V_5 , V_142 ) )
return 0 ;
if ( F_35 ( V_23 -> V_56 . V_134 , 1 , & V_137 ) ) {
F_11 ( & V_23 -> V_56 , L_12 ) ;
return - V_138 ;
}
V_2 -> V_76 = F_36 ( & V_23 -> V_56 , V_137 . V_140 ,
F_37 ( & V_137 ) ) ;
if ( ! V_2 -> V_76 ) {
F_11 ( & V_23 -> V_56 , L_10 ) ;
return - V_143 ;
}
return 0 ;
}
static int F_38 ( struct V_22 * V_23 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_144 * V_145 ;
int V_32 , V_34 ;
V_2 = F_39 ( & V_23 -> V_56 , sizeof( struct V_1 ) ,
V_146 ) ;
if ( ! V_2 ) {
F_11 ( & V_23 -> V_56 , L_13 ) ;
return - V_143 ;
}
F_40 ( V_23 , V_2 ) ;
F_41 ( & V_2 -> V_36 ) ;
V_32 = F_28 ( V_23 ) ;
if ( V_32 )
return V_32 ;
V_5 = V_2 -> V_5 ;
F_42 ( & V_2 -> V_120 , F_19 ) ;
V_2 -> V_37 = F_43 ( & V_23 -> V_56 , L_14 ) ;
if ( F_30 ( V_2 -> V_37 ) ) {
F_11 ( & V_23 -> V_56 , L_15 ) ;
return F_44 ( V_2 -> V_37 ) ;
}
V_32 = F_45 ( V_2 -> V_37 ) ;
if ( V_32 )
return V_32 ;
if ( V_5 -> type == V_10 ||
V_5 -> type == V_147 ||
V_5 -> type == V_148 ||
V_5 -> type == V_45 )
V_2 -> V_9 = V_5 -> type ;
else {
V_32 = - V_11 ;
F_11 ( & V_23 -> V_56 , L_16 ) ;
goto V_149;
}
V_32 = F_3 ( V_23 ) ;
if ( V_32 ) {
F_11 ( & V_23 -> V_56 , L_17 ) ;
goto V_149;
}
F_16 ( V_23 , true ) ;
V_145 = F_39 ( & V_23 -> V_56 ,
sizeof( struct V_144 ) , V_146 ) ;
if ( ! V_145 ) {
F_11 ( & V_23 -> V_56 , L_18 ) ;
V_32 = - V_143 ;
goto V_149;
}
sprintf ( V_145 -> V_150 , L_19 , V_2 -> V_46 ) ;
V_145 -> V_151 = ( int ( * ) ( void * ) ) F_17 ;
V_145 -> V_152 =
( int (*) ( void * , unsigned long ) ) F_18 ;
V_145 -> V_153 = V_2 ;
V_145 -> V_154 . V_155 = V_5 -> V_97 [ 0 ] +
V_5 -> V_97 [ 1 ] + V_5 -> V_97 [ 2 ] +
V_5 -> V_97 [ 3 ] ;
for ( V_34 = 0 ; V_34 < V_145 -> V_154 . V_155 ; V_34 ++ ) {
V_145 -> V_154 . V_156 [ V_34 ] =
V_5 -> V_60 + V_5 -> V_57 [ V_34 ] ;
V_145 -> V_154 . V_157 [ V_34 ] =
V_5 -> V_58 [ V_34 ] ;
}
V_145 -> V_154 . V_158 = V_5 -> V_66 ;
V_145 -> V_159 . V_160 = V_5 -> V_161 ;
for ( V_34 = 0 ; V_34 < V_5 -> V_161 ; V_34 ++ ) {
V_145 -> V_159 . V_162 [ V_34 ] . V_163 =
V_5 -> V_164 [ V_34 ] . V_163 ;
V_145 -> V_159 . V_162 [ V_34 ] . V_165 =
V_5 -> V_164 [ V_34 ] . V_165 ;
}
V_145 -> V_56 = & V_23 -> V_56 ;
V_32 = F_46 ( V_145 ) ;
if ( V_32 ) {
F_11 ( & V_23 -> V_56 , L_20 ) ;
goto V_149;
}
V_2 -> V_124 = V_145 ;
V_32 = F_47 ( & V_23 -> V_56 , V_2 -> V_126 , F_23 ,
V_166 | V_167 , F_48 ( & V_23 -> V_56 ) , V_2 ) ;
if ( V_32 ) {
F_11 ( & V_23 -> V_56 , L_21 , V_2 -> V_126 ) ;
goto V_149;
}
return 0 ;
V_149:
F_49 ( V_2 -> V_37 ) ;
return V_32 ;
}
static int F_50 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_4 ( V_23 ) ;
F_16 ( V_23 , false ) ;
F_51 ( V_2 -> V_124 ) ;
F_49 ( V_2 -> V_37 ) ;
if ( ! F_30 ( V_2 -> V_139 ) )
F_52 ( V_2 -> V_139 ) ;
return 0 ;
}
static int F_53 ( struct V_168 * V_56 )
{
F_16 ( F_54 ( V_56 ) , false ) ;
return 0 ;
}
static int F_55 ( struct V_168 * V_56 )
{
struct V_22 * V_23 = F_54 ( V_56 ) ;
F_3 ( V_23 ) ;
F_16 ( V_23 , true ) ;
return 0 ;
}
