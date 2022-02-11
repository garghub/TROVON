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
default:
break;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
unsigned int V_23 ;
int V_24 ;
V_24 = F_7 ( V_9 -> V_12 , V_25 , & V_23 ) ;
if ( V_24 != 0 ) {
F_8 ( V_7 -> V_10 , L_1 , V_24 ) ;
return V_24 ;
}
V_23 = ( V_23 & V_26 ) >> V_27 ;
return F_9 ( V_2 , V_4 , V_5 , V_23 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_28 * V_29 = F_11 ( V_7 ) ;
struct V_9 * V_9 = V_29 -> V_9 ;
unsigned int V_30 = F_12 ( V_7 , V_31 ) ;
const struct V_32 * V_33 ;
int V_34 ;
switch ( V_2 -> V_35 ) {
case V_36 :
if ( V_30 & V_37 ) {
V_33 = V_38 ;
V_34 = F_4 ( V_38 ) ;
} else {
V_33 = V_39 ;
V_34 = F_4 ( V_39 ) ;
V_29 -> V_40 += 10 ;
}
break;
case V_41 :
if ( V_30 & V_42 ) {
V_33 = V_43 ;
V_34 = F_4 ( V_43 ) ;
} else {
V_33 = V_44 ;
V_34 = F_4 ( V_44 ) ;
V_29 -> V_40 += 10 ;
}
break;
default:
return 0 ;
}
return F_13 ( V_9 -> V_12 , V_33 , V_34 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_28 * V_29 = F_11 ( V_7 ) ;
unsigned int V_30 = F_12 ( V_7 , V_31 ) ;
switch ( V_2 -> V_35 ) {
case V_36 :
if ( ! ( V_30 & V_37 ) ) {
F_15 ( V_7 , V_45 ,
V_46 , V_46 ) ;
F_15 ( V_7 , V_45 ,
V_46 , 0 ) ;
V_29 -> V_47 += 27 ;
}
break;
case V_41 :
if ( ! ( V_30 & V_42 ) ) {
F_15 ( V_7 , V_45 ,
V_48 , V_48 ) ;
F_15 ( V_7 , V_45 ,
V_48 , 0 ) ;
V_29 -> V_47 += 27 ;
}
break;
default:
break;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_28 * V_29 = F_11 ( V_7 ) ;
switch ( V_29 -> V_9 -> V_17 ) {
case 0 ... 3 :
break;
default:
switch ( V_5 ) {
case V_49 :
F_10 ( V_2 ) ;
break;
case V_50 :
F_14 ( V_2 ) ;
break;
default:
break;
}
break;
}
return F_17 ( V_2 , V_4 , V_5 ) ;
}
static int F_18 ( struct V_9 * V_9 , int V_51 )
{
unsigned int V_21 = V_52 + V_51 * 4 ;
int V_24 ;
V_24 = F_19 ( V_9 -> V_12 , V_21 , 0x80 ) ;
if ( V_24 )
F_8 ( V_9 -> V_10 , L_2 ,
V_21 , V_24 ) ;
return V_24 ;
}
static int F_20 ( struct V_3 * V_4 ,
struct V_53 * V_54 )
{
struct V_6 * V_7 = F_21 ( V_4 ) ;
struct V_55 * V_8 = F_22 ( V_7 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
struct V_56 * V_57 =
(struct V_56 * ) V_4 -> V_58 ;
unsigned int V_59 , V_60 ;
unsigned int V_61 = ( 0x1 << V_57 -> V_35 ) | ( 0x1 << V_57 -> V_62 ) ;
unsigned int V_63 = ( ! ! V_54 -> V_64 . integer . V_64 [ 0 ] ) << V_57 -> V_35 ;
unsigned int V_65 = ( ! ! V_54 -> V_64 . integer . V_64 [ 1 ] ) << V_57 -> V_62 ;
unsigned int V_66 , V_67 ;
unsigned int V_68 , V_69 ;
int V_24 ;
F_23 ( V_8 ) ;
V_24 = F_7 ( V_9 -> V_12 , V_70 , & V_59 ) ;
if ( V_24 ) {
F_8 ( V_9 -> V_10 , L_3 , V_24 ) ;
goto V_71;
}
V_24 = F_7 ( V_9 -> V_12 , V_31 , & V_60 ) ;
if ( V_24 ) {
F_8 ( V_9 -> V_10 , L_4 , V_24 ) ;
goto V_71;
}
V_66 = V_60 & ( 1 << V_57 -> V_35 ) ;
V_67 = V_60 & ( 1 << V_57 -> V_62 ) ;
V_68 = V_59 & ( 1 << V_57 -> V_62 ) ;
V_69 = V_59 & ( 1 << V_57 -> V_35 ) ;
if ( ( V_68 && V_63 != V_66 ) || ( V_69 && V_65 != V_67 ) ) {
F_8 ( V_9 -> V_10 , L_5 ) ;
V_24 = - V_72 ;
goto V_71;
}
V_24 = F_24 ( V_9 -> V_12 , V_31 ,
V_61 , V_63 | V_65 ) ;
if ( V_24 ) {
F_8 ( V_9 -> V_10 , L_6 , V_24 ) ;
goto V_71;
}
if ( ! V_63 && V_66 )
F_18 ( V_9 , V_57 -> V_35 ) ;
if ( ! V_65 && V_67 )
F_18 ( V_9 , V_57 -> V_62 ) ;
V_71:
F_25 ( V_8 ) ;
return V_24 ;
}
static int F_26 ( struct V_3 * V_4 ,
struct V_53 * V_54 )
{
struct V_6 * V_7 = F_21 ( V_4 ) ;
struct V_55 * V_8 = F_22 ( V_7 ) ;
int V_24 ;
F_23 ( V_8 ) ;
V_24 = F_27 ( V_4 , V_54 ) ;
F_25 ( V_8 ) ;
return V_24 ;
}
static int F_28 ( struct V_3 * V_4 ,
struct V_53 * V_54 )
{
struct V_6 * V_7 = F_21 ( V_4 ) ;
struct V_55 * V_8 = F_22 ( V_7 ) ;
int V_24 ;
F_23 ( V_8 ) ;
V_24 = F_29 ( V_4 , V_54 ) ;
F_25 ( V_8 ) ;
return V_24 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_28 * V_29 = F_11 ( V_7 ) ;
struct V_73 * V_74 = F_11 ( V_7 ) ;
struct V_9 * V_9 = V_29 -> V_9 ;
unsigned int V_21 , V_61 ;
struct V_32 V_75 [] = {
{ 0x80 , 0x3 } ,
{ 0x35d , 0 } ,
{ 0x80 , 0x0 } ,
} ;
V_21 = V_76 + ( ( V_2 -> V_35 ^ 0x1 ) * 4 ) ;
V_61 = V_77 ;
switch ( V_5 ) {
case V_78 :
V_74 -> V_79 |= 0x3 << ( ( V_2 -> V_35 ^ 0x1 ) * 2 ) ;
V_74 -> V_80 ++ ;
V_74 -> V_81 ++ ;
return 0 ;
case V_49 :
V_74 -> V_82 [ V_2 -> V_35 ] = F_12 ( V_7 , V_21 ) ;
F_15 ( V_7 , V_21 , V_61 ,
0x40 << V_83 ) ;
V_74 -> V_80 -- ;
if ( V_74 -> V_80 == 0 ) {
V_75 [ 1 ] . V_22 = V_74 -> V_79 ;
F_31 ( V_9 -> V_12 ,
V_75 ,
F_4 ( V_75 ) ) ;
F_32 ( 55 ) ;
V_74 -> V_79 = 0 ;
}
break;
case V_20 :
F_15 ( V_7 , V_21 , V_61 ,
V_74 -> V_82 [ V_2 -> V_35 ] ) ;
V_74 -> V_81 -- ;
if ( V_74 -> V_81 == 0 )
F_31 ( V_9 -> V_12 ,
V_75 ,
F_4 ( V_75 ) ) ;
break;
default:
break;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_28 * V_29 = F_11 ( V_7 ) ;
struct V_9 * V_9 = V_29 -> V_9 ;
switch ( V_9 -> V_17 ) {
case 0 ... 4 :
if ( F_34 ( V_7 , V_2 -> V_35 ) )
F_30 ( V_2 , V_4 , V_5 ) ;
break;
default:
break;
}
return F_35 ( V_2 , V_4 , V_5 ) ;
}
static int F_36 ( struct V_6 * V_7 , int V_84 , int V_85 ,
unsigned int V_86 , unsigned int V_87 )
{
struct V_73 * V_74 = F_11 ( V_7 ) ;
switch ( V_84 ) {
case V_88 :
return F_37 ( & V_74 -> V_89 [ 0 ] , V_85 , V_86 , V_87 ) ;
case V_90 :
return F_37 ( & V_74 -> V_89 [ 1 ] , V_85 , V_86 , V_87 ) ;
case V_91 :
return F_38 ( & V_74 -> V_89 [ 0 ] , V_85 , V_86 ,
V_87 ) ;
case V_92 :
return F_38 ( & V_74 -> V_89 [ 1 ] , V_85 , V_86 ,
V_87 ) ;
default:
return - V_93 ;
}
}
static int F_39 ( struct V_94 * V_95 )
{
struct V_96 * V_97 = V_95 -> V_98 ;
struct V_73 * V_29 = F_11 ( V_97 -> V_7 ) ;
struct V_9 * V_9 = V_29 -> V_99 . V_9 ;
int V_100 ;
if ( strcmp ( V_97 -> V_101 -> V_102 , L_7 ) == 0 ) {
V_100 = 2 ;
} else if ( strcmp ( V_97 -> V_101 -> V_102 , L_8 ) == 0 ) {
V_100 = 0 ;
} else {
F_8 ( V_9 -> V_10 ,
L_9 ,
V_97 -> V_101 -> V_102 ) ;
return - V_93 ;
}
return F_40 ( & V_29 -> V_99 . V_103 [ V_100 ] , V_95 ) ;
}
static T_1 F_41 ( int V_104 , void * V_105 )
{
struct V_73 * V_29 = V_105 ;
struct V_9 * V_9 = V_29 -> V_99 . V_9 ;
struct V_106 V_107 ;
int V_108 = 0 ;
int V_15 , V_24 ;
for ( V_15 = 0 ; V_15 < V_109 ; ++ V_15 ) {
V_24 = F_42 ( & V_29 -> V_99 . V_103 [ V_15 ] ) ;
if ( V_24 != - V_110 )
V_108 ++ ;
if ( V_24 == V_111 ) {
V_107 . V_99 = V_15 ;
F_43 ( V_9 ,
V_112 ,
& V_107 ) ;
}
}
if ( ! V_108 ) {
F_8 ( V_9 -> V_10 , L_10 ) ;
return V_113 ;
}
return V_114 ;
}
static int F_44 ( struct V_6 * V_7 )
{
struct V_55 * V_8 = F_22 ( V_7 ) ;
struct V_73 * V_29 = F_11 ( V_7 ) ;
struct V_9 * V_9 = V_29 -> V_99 . V_9 ;
int V_15 , V_24 ;
V_29 -> V_99 . V_9 -> V_8 = V_8 ;
F_45 ( V_7 ) ;
F_46 ( V_7 ) ;
F_47 ( V_7 ) ;
F_48 ( V_7 ) ;
V_24 = F_49 ( V_9 , V_115 ,
L_11 , F_41 ,
V_29 ) ;
if ( V_24 != 0 ) {
F_8 ( V_7 -> V_10 , L_12 , V_24 ) ;
return V_24 ;
}
for ( V_15 = 0 ; V_15 < V_109 ; ++ V_15 ) {
V_24 = F_50 ( & V_29 -> V_99 . V_103 [ V_15 ] , V_7 ) ;
if ( V_24 )
goto V_116;
}
V_24 = F_51 ( V_7 ,
V_117 ,
V_109 ) ;
if ( V_24 )
goto V_116;
F_52 ( V_8 , L_13 ) ;
return 0 ;
V_116:
for ( -- V_15 ; V_15 >= 0 ; -- V_15 )
F_53 ( & V_29 -> V_99 . V_103 [ V_15 ] , V_7 ) ;
F_54 ( V_9 , V_115 , V_29 ) ;
return V_24 ;
}
static int F_55 ( struct V_6 * V_7 )
{
struct V_73 * V_29 = F_11 ( V_7 ) ;
struct V_9 * V_9 = V_29 -> V_99 . V_9 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_109 ; ++ V_15 )
F_53 ( & V_29 -> V_99 . V_103 [ V_15 ] , V_7 ) ;
V_29 -> V_99 . V_9 -> V_8 = NULL ;
F_54 ( V_9 , V_115 , V_29 ) ;
F_56 ( V_7 ) ;
return 0 ;
}
static struct V_12 * F_57 ( struct V_118 * V_10 )
{
struct V_73 * V_29 = F_3 ( V_10 ) ;
return V_29 -> V_99 . V_9 -> V_12 ;
}
static int F_58 ( struct V_119 * V_120 )
{
struct V_9 * V_9 = F_3 ( V_120 -> V_10 . V_11 ) ;
struct V_73 * V_74 ;
int V_15 , V_24 ;
V_74 = F_59 ( & V_120 -> V_10 , sizeof( struct V_73 ) ,
V_121 ) ;
if ( V_74 == NULL )
return - V_122 ;
F_60 ( V_120 , V_74 ) ;
V_74 -> V_99 . V_9 = V_9 ;
V_74 -> V_99 . V_123 = 8 ;
for ( V_15 = 0 ; V_15 < V_109 ; V_15 ++ ) {
V_74 -> V_99 . V_103 [ V_15 ] . V_124 = L_14 ;
V_74 -> V_99 . V_103 [ V_15 ] . V_125 = V_15 + 1 ;
V_74 -> V_99 . V_103 [ V_15 ] . type = V_126 ;
V_74 -> V_99 . V_103 [ V_15 ] . V_10 = V_9 -> V_10 ;
V_74 -> V_99 . V_103 [ V_15 ] . V_12 = V_9 -> V_12 ;
V_74 -> V_99 . V_103 [ V_15 ] . V_127 = V_128
+ ( 0x100 * V_15 ) ;
V_74 -> V_99 . V_103 [ V_15 ] . V_129 = V_130 [ V_15 ] ;
V_74 -> V_99 . V_103 [ V_15 ] . V_131
= F_4 ( V_132 ) ;
V_24 = F_61 ( & V_74 -> V_99 . V_103 [ V_15 ] ) ;
if ( V_24 != 0 )
return V_24 ;
}
for ( V_15 = 0 ; V_15 < F_4 ( V_74 -> V_89 ) ; V_15 ++ )
V_74 -> V_89 [ V_15 ] . V_133 = 3 ;
F_62 ( V_9 , 1 , V_134 - 1 ,
V_135 , V_136 ,
& V_74 -> V_89 [ 0 ] ) ;
F_62 ( V_9 , 2 , V_137 - 1 ,
V_138 , V_139 ,
& V_74 -> V_89 [ 1 ] ) ;
F_24 ( V_9 -> V_12 , V_140 ,
V_141 , 0x11 ) ;
F_24 ( V_9 -> V_12 , V_142 ,
V_143 , 0x12 ) ;
for ( V_15 = 0 ; V_15 < F_4 ( V_144 ) ; V_15 ++ )
F_63 ( & V_74 -> V_99 , V_15 ) ;
for ( V_15 = 0 ; V_15 < F_4 ( V_145 ) ; V_15 ++ )
F_24 ( V_9 -> V_12 , V_145 [ V_15 ] ,
V_146 , V_146 ) ;
F_64 ( & V_120 -> V_10 ) ;
F_65 ( & V_120 -> V_10 ) ;
V_24 = F_66 ( & V_120 -> V_10 , & V_147 ) ;
if ( V_24 < 0 ) {
F_8 ( & V_120 -> V_10 , L_15 , V_24 ) ;
return V_24 ;
}
V_24 = F_67 ( & V_120 -> V_10 , & V_148 ,
V_144 , F_4 ( V_144 ) ) ;
if ( V_24 < 0 ) {
F_8 ( & V_120 -> V_10 , L_16 , V_24 ) ;
F_68 ( & V_120 -> V_10 ) ;
}
return V_24 ;
}
static int F_69 ( struct V_119 * V_120 )
{
struct V_73 * V_74 = F_70 ( V_120 ) ;
int V_15 ;
F_68 ( & V_120 -> V_10 ) ;
F_71 ( & V_120 -> V_10 ) ;
F_72 ( & V_120 -> V_10 ) ;
for ( V_15 = 0 ; V_15 < V_109 ; V_15 ++ )
F_73 ( & V_74 -> V_99 . V_103 [ V_15 ] ) ;
return 0 ;
}
