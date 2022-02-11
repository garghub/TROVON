static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
struct V_12 * V_12 = V_9 -> V_12 ;
const struct V_13 * V_14 = NULL ;
int V_15 , V_16 ;
switch ( V_9 -> V_17 ) {
case 3 :
V_14 = V_18 ;
V_16 = F_4 ( V_18 ) ;
break;
default:
V_14 = V_19 ;
V_16 = F_4 ( V_19 ) ;
break;
}
switch ( V_5 ) {
case V_20 :
if ( V_14 )
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ )
F_5 ( V_12 , V_14 [ V_15 ] . V_21 ,
V_14 [ V_15 ] . V_22 ) ;
break;
case V_23 :
case V_24 :
return F_6 ( V_2 , V_4 , V_5 ) ;
default:
break;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
unsigned int V_25 ;
int V_26 ;
V_26 = F_8 ( V_9 -> V_12 , V_27 , & V_25 ) ;
if ( V_26 != 0 ) {
F_9 ( V_7 -> V_10 , L_1 , V_26 ) ;
return V_26 ;
}
V_25 = ( V_25 & V_28 ) >> V_29 ;
return F_10 ( V_2 , V_4 , V_5 , V_25 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_30 * V_31 = F_12 ( V_7 ) ;
struct V_9 * V_9 = V_31 -> V_9 ;
unsigned int V_32 = F_13 ( V_7 , V_33 ) ;
const struct V_34 * V_35 ;
int V_36 ;
switch ( V_2 -> V_37 ) {
case V_38 :
if ( V_32 & V_39 ) {
V_35 = V_40 ;
V_36 = F_4 ( V_40 ) ;
} else {
V_35 = V_41 ;
V_36 = F_4 ( V_41 ) ;
V_31 -> V_42 += 10 ;
}
break;
case V_43 :
if ( V_32 & V_44 ) {
V_35 = V_45 ;
V_36 = F_4 ( V_45 ) ;
} else {
V_35 = V_46 ;
V_36 = F_4 ( V_46 ) ;
V_31 -> V_42 += 10 ;
}
break;
default:
return 0 ;
}
return F_14 ( V_9 -> V_12 , V_35 , V_36 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_30 * V_31 = F_12 ( V_7 ) ;
unsigned int V_32 = F_13 ( V_7 , V_33 ) ;
switch ( V_2 -> V_37 ) {
case V_38 :
if ( ! ( V_32 & V_39 ) ) {
F_16 ( V_7 , V_47 ,
V_48 , V_48 ) ;
F_16 ( V_7 , V_47 ,
V_48 , 0 ) ;
V_31 -> V_49 += 27 ;
}
break;
case V_43 :
if ( ! ( V_32 & V_44 ) ) {
F_16 ( V_7 , V_47 ,
V_50 , V_50 ) ;
F_16 ( V_7 , V_47 ,
V_50 , 0 ) ;
V_31 -> V_49 += 27 ;
}
break;
default:
break;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_30 * V_31 = F_12 ( V_7 ) ;
switch ( V_31 -> V_9 -> V_17 ) {
case 0 ... 3 :
break;
default:
switch ( V_5 ) {
case V_23 :
F_11 ( V_2 ) ;
break;
case V_51 :
F_15 ( V_2 ) ;
break;
default:
break;
}
break;
}
return F_18 ( V_2 , V_4 , V_5 ) ;
}
static int F_19 ( struct V_9 * V_9 , int V_52 )
{
unsigned int V_21 = V_53 + V_52 * 4 ;
int V_26 ;
V_26 = F_20 ( V_9 -> V_12 , V_21 , 0x80 ) ;
if ( V_26 )
F_9 ( V_9 -> V_10 , L_2 ,
V_21 , V_26 ) ;
return V_26 ;
}
static int F_21 ( struct V_3 * V_4 ,
struct V_54 * V_55 )
{
struct V_6 * V_7 = F_22 ( V_4 ) ;
struct V_56 * V_8 = F_23 ( V_7 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
struct V_57 * V_58 =
(struct V_57 * ) V_4 -> V_59 ;
unsigned int V_60 , V_61 ;
unsigned int V_62 = ( 0x1 << V_58 -> V_37 ) | ( 0x1 << V_58 -> V_63 ) ;
unsigned int V_64 = ( ! ! V_55 -> V_65 . integer . V_65 [ 0 ] ) << V_58 -> V_37 ;
unsigned int V_66 = ( ! ! V_55 -> V_65 . integer . V_65 [ 1 ] ) << V_58 -> V_63 ;
unsigned int V_67 , V_68 ;
unsigned int V_69 , V_70 ;
int V_26 ;
F_24 ( V_8 ) ;
V_26 = F_8 ( V_9 -> V_12 , V_71 , & V_60 ) ;
if ( V_26 ) {
F_9 ( V_9 -> V_10 , L_3 , V_26 ) ;
goto V_72;
}
V_26 = F_8 ( V_9 -> V_12 , V_33 , & V_61 ) ;
if ( V_26 ) {
F_9 ( V_9 -> V_10 , L_4 , V_26 ) ;
goto V_72;
}
V_67 = V_61 & ( 1 << V_58 -> V_37 ) ;
V_68 = V_61 & ( 1 << V_58 -> V_63 ) ;
V_69 = V_60 & ( 1 << V_58 -> V_63 ) ;
V_70 = V_60 & ( 1 << V_58 -> V_37 ) ;
if ( ( V_69 && V_64 != V_67 ) || ( V_70 && V_66 != V_68 ) ) {
F_9 ( V_9 -> V_10 , L_5 ) ;
V_26 = - V_73 ;
goto V_72;
}
V_26 = F_25 ( V_9 -> V_12 , V_33 ,
V_62 , V_64 | V_66 ) ;
if ( V_26 ) {
F_9 ( V_9 -> V_10 , L_6 , V_26 ) ;
goto V_72;
}
if ( ! V_64 && V_67 )
F_19 ( V_9 , V_58 -> V_37 ) ;
if ( ! V_66 && V_68 )
F_19 ( V_9 , V_58 -> V_63 ) ;
V_72:
F_26 ( V_8 ) ;
return V_26 ;
}
static int F_27 ( struct V_3 * V_4 ,
struct V_54 * V_55 )
{
struct V_6 * V_7 = F_22 ( V_4 ) ;
struct V_56 * V_8 = F_23 ( V_7 ) ;
int V_26 ;
F_24 ( V_8 ) ;
V_26 = F_28 ( V_4 , V_55 ) ;
F_26 ( V_8 ) ;
return V_26 ;
}
static int F_29 ( struct V_3 * V_4 ,
struct V_54 * V_55 )
{
struct V_6 * V_7 = F_22 ( V_4 ) ;
struct V_56 * V_8 = F_23 ( V_7 ) ;
int V_26 ;
F_24 ( V_8 ) ;
V_26 = F_30 ( V_4 , V_55 ) ;
F_26 ( V_8 ) ;
return V_26 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_30 * V_31 = F_12 ( V_7 ) ;
struct V_74 * V_75 = F_12 ( V_7 ) ;
struct V_9 * V_9 = V_31 -> V_9 ;
unsigned int V_21 , V_62 ;
struct V_34 V_76 [] = {
{ 0x80 , 0x3 } ,
{ 0x35d , 0 } ,
{ 0x80 , 0x0 } ,
} ;
V_21 = V_77 + ( ( V_2 -> V_37 ^ 0x1 ) * 4 ) ;
V_62 = V_78 ;
switch ( V_5 ) {
case V_79 :
V_75 -> V_80 |= 0x3 << ( ( V_2 -> V_37 ^ 0x1 ) * 2 ) ;
V_75 -> V_81 ++ ;
V_75 -> V_82 ++ ;
return 0 ;
case V_23 :
V_75 -> V_83 [ V_2 -> V_37 ] = F_13 ( V_7 , V_21 ) ;
F_16 ( V_7 , V_21 , V_62 ,
0x40 << V_84 ) ;
V_75 -> V_81 -- ;
if ( V_75 -> V_81 == 0 ) {
V_76 [ 1 ] . V_22 = V_75 -> V_80 ;
F_32 ( V_9 -> V_12 ,
V_76 ,
F_4 ( V_76 ) ) ;
F_33 ( 55 ) ;
V_75 -> V_80 = 0 ;
}
break;
case V_20 :
F_16 ( V_7 , V_21 , V_62 ,
V_75 -> V_83 [ V_2 -> V_37 ] ) ;
V_75 -> V_82 -- ;
if ( V_75 -> V_82 == 0 )
F_32 ( V_9 -> V_12 ,
V_76 ,
F_4 ( V_76 ) ) ;
break;
default:
break;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_30 * V_31 = F_12 ( V_7 ) ;
struct V_9 * V_9 = V_31 -> V_9 ;
switch ( V_9 -> V_17 ) {
case 0 ... 4 :
if ( F_35 ( V_7 , V_2 -> V_37 ) )
F_31 ( V_2 , V_4 , V_5 ) ;
break;
default:
break;
}
return F_36 ( V_2 , V_4 , V_5 ) ;
}
static int F_37 ( struct V_6 * V_7 , int V_85 , int V_86 ,
unsigned int V_87 , unsigned int V_88 )
{
struct V_74 * V_75 = F_12 ( V_7 ) ;
switch ( V_85 ) {
case V_89 :
return F_38 ( & V_75 -> V_90 [ 0 ] , V_86 , V_87 , V_88 ) ;
case V_91 :
return F_38 ( & V_75 -> V_90 [ 1 ] , V_86 , V_87 , V_88 ) ;
case V_92 :
return F_39 ( & V_75 -> V_90 [ 0 ] , V_86 , V_87 ,
V_88 ) ;
case V_93 :
return F_39 ( & V_75 -> V_90 [ 1 ] , V_86 , V_87 ,
V_88 ) ;
default:
return - V_94 ;
}
}
static int F_40 ( struct V_95 * V_96 )
{
struct V_97 * V_98 = V_96 -> V_99 ;
struct V_74 * V_31 = F_41 ( V_98 -> V_100 ) ;
struct V_9 * V_9 = V_31 -> V_101 . V_9 ;
int V_102 ;
if ( strcmp ( V_98 -> V_103 -> V_104 , L_7 ) == 0 ) {
V_102 = 2 ;
} else if ( strcmp ( V_98 -> V_103 -> V_104 , L_8 ) == 0 ) {
V_102 = 0 ;
} else {
F_9 ( V_9 -> V_10 ,
L_9 ,
V_98 -> V_103 -> V_104 ) ;
return - V_94 ;
}
return F_42 ( & V_31 -> V_101 . V_105 [ V_102 ] , V_96 ) ;
}
static T_1 F_43 ( int V_106 , void * V_107 )
{
struct V_74 * V_31 = V_107 ;
struct V_9 * V_9 = V_31 -> V_101 . V_9 ;
struct V_108 V_109 ;
int V_110 = 0 ;
int V_15 , V_26 ;
for ( V_15 = 0 ; V_15 < V_111 ; ++ V_15 ) {
V_26 = F_44 ( & V_31 -> V_101 . V_105 [ V_15 ] ) ;
if ( V_26 != - V_112 )
V_110 ++ ;
if ( V_26 == V_113 ) {
V_109 . V_101 = V_15 ;
F_45 ( V_9 ,
V_114 ,
& V_109 ) ;
}
}
if ( ! V_110 ) {
F_9 ( V_9 -> V_10 , L_10 ) ;
return V_115 ;
}
return V_116 ;
}
static int F_46 ( struct V_6 * V_7 )
{
struct V_56 * V_8 = F_23 ( V_7 ) ;
struct V_117 * V_118 = F_47 ( V_8 ) ;
struct V_74 * V_31 = F_12 ( V_7 ) ;
int V_15 , V_26 ;
V_31 -> V_101 . V_9 -> V_8 = V_8 ;
V_26 = F_48 ( V_7 ) ;
if ( V_26 < 0 )
return V_26 ;
F_49 ( V_7 ) ;
F_50 ( V_7 ) ;
F_51 ( V_7 ) ;
for ( V_15 = 0 ; V_15 < V_111 ; ++ V_15 ) {
V_26 = F_52 ( & V_31 -> V_101 . V_105 [ V_15 ] , V_7 ) ;
if ( V_26 )
goto V_119;
}
V_26 = F_53 ( V_7 ,
V_120 ,
V_111 ) ;
if ( V_26 )
goto V_119;
F_54 ( V_118 , L_11 ) ;
return 0 ;
V_119:
for ( -- V_15 ; V_15 >= 0 ; -- V_15 )
F_55 ( & V_31 -> V_101 . V_105 [ V_15 ] , V_7 ) ;
return V_26 ;
}
static int F_56 ( struct V_6 * V_7 )
{
struct V_74 * V_31 = F_12 ( V_7 ) ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_111 ; ++ V_15 )
F_55 ( & V_31 -> V_101 . V_105 [ V_15 ] , V_7 ) ;
V_31 -> V_101 . V_9 -> V_8 = NULL ;
return 0 ;
}
static struct V_12 * F_57 ( struct V_121 * V_10 )
{
struct V_74 * V_31 = F_3 ( V_10 ) ;
return V_31 -> V_101 . V_9 -> V_12 ;
}
static int F_58 ( struct V_122 * V_123 )
{
struct V_9 * V_9 = F_3 ( V_123 -> V_10 . V_11 ) ;
struct V_74 * V_75 ;
int V_15 , V_26 ;
V_75 = F_59 ( & V_123 -> V_10 , sizeof( struct V_74 ) ,
V_124 ) ;
if ( V_75 == NULL )
return - V_125 ;
F_60 ( V_123 , V_75 ) ;
V_75 -> V_101 . V_9 = V_9 ;
V_75 -> V_101 . V_126 = 8 ;
for ( V_15 = 0 ; V_15 < V_111 ; V_15 ++ ) {
V_75 -> V_101 . V_105 [ V_15 ] . V_127 = L_12 ;
V_75 -> V_101 . V_105 [ V_15 ] . V_128 = V_15 + 1 ;
V_75 -> V_101 . V_105 [ V_15 ] . type = V_129 ;
V_75 -> V_101 . V_105 [ V_15 ] . V_10 = V_9 -> V_10 ;
V_75 -> V_101 . V_105 [ V_15 ] . V_12 = V_9 -> V_12 ;
V_75 -> V_101 . V_105 [ V_15 ] . V_130 = V_131
+ ( 0x100 * V_15 ) ;
V_75 -> V_101 . V_105 [ V_15 ] . V_132 = V_133 [ V_15 ] ;
V_75 -> V_101 . V_105 [ V_15 ] . V_134
= F_4 ( V_135 ) ;
V_26 = F_61 ( & V_75 -> V_101 . V_105 [ V_15 ] ) ;
if ( V_26 != 0 )
return V_26 ;
}
for ( V_15 = 0 ; V_15 < F_4 ( V_75 -> V_90 ) ; V_15 ++ )
V_75 -> V_90 [ V_15 ] . V_136 = 3 ;
F_62 ( V_9 , 1 , V_137 - 1 ,
V_138 , V_139 ,
& V_75 -> V_90 [ 0 ] ) ;
F_62 ( V_9 , 2 , V_140 - 1 ,
V_141 , V_142 ,
& V_75 -> V_90 [ 1 ] ) ;
F_25 ( V_9 -> V_12 , V_143 ,
V_144 , 0x11 ) ;
F_25 ( V_9 -> V_12 , V_145 ,
V_146 , 0x12 ) ;
for ( V_15 = 0 ; V_15 < F_4 ( V_147 ) ; V_15 ++ )
F_63 ( & V_75 -> V_101 , V_15 ) ;
for ( V_15 = 0 ; V_15 < F_4 ( V_148 ) ; V_15 ++ )
F_25 ( V_9 -> V_12 , V_148 [ V_15 ] ,
V_149 , V_149 ) ;
F_64 ( & V_123 -> V_10 ) ;
F_65 ( & V_123 -> V_10 ) ;
V_26 = F_66 ( V_9 , V_150 ,
L_13 , F_43 ,
V_75 ) ;
if ( V_26 != 0 ) {
F_9 ( & V_123 -> V_10 , L_14 , V_26 ) ;
return V_26 ;
}
V_26 = F_67 ( V_9 ) ;
if ( V_26 < 0 )
goto V_151;
V_26 = F_68 ( & V_123 -> V_10 , & V_152 ) ;
if ( V_26 < 0 ) {
F_9 ( & V_123 -> V_10 , L_15 , V_26 ) ;
goto V_153;
}
V_26 = F_69 ( & V_123 -> V_10 , & V_154 ,
V_147 , F_4 ( V_147 ) ) ;
if ( V_26 < 0 ) {
F_9 ( & V_123 -> V_10 , L_16 , V_26 ) ;
goto V_155;
}
return V_26 ;
V_155:
F_70 ( & V_123 -> V_10 ) ;
V_153:
F_71 ( V_9 ) ;
V_151:
F_72 ( V_9 , V_150 , V_75 ) ;
return V_26 ;
}
static int F_73 ( struct V_122 * V_123 )
{
struct V_74 * V_75 = F_74 ( V_123 ) ;
struct V_9 * V_9 = V_75 -> V_101 . V_9 ;
int V_15 ;
F_70 ( & V_123 -> V_10 ) ;
F_75 ( & V_123 -> V_10 ) ;
F_76 ( & V_123 -> V_10 ) ;
for ( V_15 = 0 ; V_15 < V_111 ; V_15 ++ )
F_77 ( & V_75 -> V_101 . V_105 [ V_15 ] ) ;
F_71 ( V_9 ) ;
F_72 ( V_9 , V_150 , V_75 ) ;
return 0 ;
}
