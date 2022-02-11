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
static int F_6 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_23 * V_24 = F_7 ( V_7 ) ;
struct V_9 * V_9 = V_24 -> V_9 ;
unsigned int V_25 = F_8 ( V_7 , V_26 ) ;
const struct V_27 * V_28 ;
int V_29 ;
switch ( V_2 -> V_30 ) {
case V_31 :
if ( V_25 & V_32 ) {
V_28 = V_33 ;
V_29 = F_4 ( V_33 ) ;
} else {
V_28 = V_34 ;
V_29 = F_4 ( V_34 ) ;
V_24 -> V_35 += 10 ;
}
break;
case V_36 :
if ( V_25 & V_37 ) {
V_28 = V_38 ;
V_29 = F_4 ( V_38 ) ;
} else {
V_28 = V_39 ;
V_29 = F_4 ( V_39 ) ;
V_24 -> V_35 += 10 ;
}
break;
default:
return 0 ;
}
return F_9 ( V_9 -> V_12 , V_28 , V_29 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_23 * V_24 = F_7 ( V_7 ) ;
unsigned int V_25 = F_8 ( V_7 , V_26 ) ;
switch ( V_2 -> V_30 ) {
case V_31 :
if ( ! ( V_25 & V_32 ) ) {
F_11 ( V_7 , V_40 ,
V_41 , V_41 ) ;
F_11 ( V_7 , V_40 ,
V_41 , 0 ) ;
V_24 -> V_42 += 27 ;
}
break;
case V_36 :
if ( ! ( V_25 & V_37 ) ) {
F_11 ( V_7 , V_40 ,
V_43 , V_43 ) ;
F_11 ( V_7 , V_40 ,
V_43 , 0 ) ;
V_24 -> V_42 += 27 ;
}
break;
default:
break;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_23 * V_24 = F_7 ( V_7 ) ;
switch ( V_24 -> V_9 -> V_17 ) {
case 0 ... 3 :
break;
default:
switch ( V_5 ) {
case V_44 :
F_6 ( V_2 ) ;
break;
case V_45 :
F_10 ( V_2 ) ;
break;
default:
break;
}
break;
}
return F_13 ( V_2 , V_4 , V_5 ) ;
}
static int F_14 ( struct V_9 * V_9 , int V_46 )
{
unsigned int V_21 = V_47 + V_46 * 4 ;
int V_48 ;
V_48 = F_15 ( V_9 -> V_12 , V_21 , 0x80 ) ;
if ( V_48 )
F_16 ( V_9 -> V_10 , L_1 ,
V_21 , V_48 ) ;
return V_48 ;
}
static int F_17 ( struct V_3 * V_4 ,
struct V_49 * V_50 )
{
struct V_6 * V_7 = F_18 ( V_4 ) ;
struct V_51 * V_8 = F_19 ( V_7 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
struct V_52 * V_53 =
(struct V_52 * ) V_4 -> V_54 ;
unsigned int V_55 , V_56 ;
unsigned int V_57 = ( 0x1 << V_53 -> V_30 ) | ( 0x1 << V_53 -> V_58 ) ;
unsigned int V_59 = ( ! ! V_50 -> V_60 . integer . V_60 [ 0 ] ) << V_53 -> V_30 ;
unsigned int V_61 = ( ! ! V_50 -> V_60 . integer . V_60 [ 1 ] ) << V_53 -> V_58 ;
unsigned int V_62 , V_63 ;
unsigned int V_64 , V_65 ;
int V_48 ;
F_20 ( V_8 ) ;
V_48 = F_21 ( V_9 -> V_12 , V_66 , & V_55 ) ;
if ( V_48 ) {
F_16 ( V_9 -> V_10 , L_2 , V_48 ) ;
goto V_67;
}
V_48 = F_21 ( V_9 -> V_12 , V_26 , & V_56 ) ;
if ( V_48 ) {
F_16 ( V_9 -> V_10 , L_3 , V_48 ) ;
goto V_67;
}
V_62 = V_56 & ( 1 << V_53 -> V_30 ) ;
V_63 = V_56 & ( 1 << V_53 -> V_58 ) ;
V_64 = V_55 & ( 1 << V_53 -> V_58 ) ;
V_65 = V_55 & ( 1 << V_53 -> V_30 ) ;
if ( ( V_64 && V_59 != V_62 ) || ( V_65 && V_61 != V_63 ) ) {
F_16 ( V_9 -> V_10 , L_4 ) ;
V_48 = - V_68 ;
goto V_67;
}
V_48 = F_22 ( V_9 -> V_12 , V_26 ,
V_57 , V_59 | V_61 ) ;
if ( V_48 ) {
F_16 ( V_9 -> V_10 , L_5 , V_48 ) ;
goto V_67;
}
if ( ! V_59 && V_62 )
F_14 ( V_9 , V_53 -> V_30 ) ;
if ( ! V_61 && V_63 )
F_14 ( V_9 , V_53 -> V_58 ) ;
V_67:
F_23 ( V_8 ) ;
return V_48 ;
}
static int F_24 ( struct V_3 * V_4 ,
struct V_49 * V_50 )
{
struct V_6 * V_7 = F_18 ( V_4 ) ;
struct V_51 * V_8 = F_19 ( V_7 ) ;
int V_48 ;
F_20 ( V_8 ) ;
V_48 = F_25 ( V_4 , V_50 ) ;
F_23 ( V_8 ) ;
return V_48 ;
}
static int F_26 ( struct V_3 * V_4 ,
struct V_49 * V_50 )
{
struct V_6 * V_7 = F_18 ( V_4 ) ;
struct V_51 * V_8 = F_19 ( V_7 ) ;
int V_48 ;
F_20 ( V_8 ) ;
V_48 = F_27 ( V_4 , V_50 ) ;
F_23 ( V_8 ) ;
return V_48 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_23 * V_24 = F_7 ( V_7 ) ;
struct V_69 * V_70 = F_7 ( V_7 ) ;
struct V_9 * V_9 = V_24 -> V_9 ;
unsigned int V_21 , V_57 ;
struct V_27 V_71 [] = {
{ 0x80 , 0x3 } ,
{ 0x35d , 0 } ,
{ 0x80 , 0x0 } ,
} ;
V_21 = V_72 + ( ( V_2 -> V_30 ^ 0x1 ) * 4 ) ;
V_57 = V_73 ;
switch ( V_5 ) {
case V_74 :
V_70 -> V_75 |= 0x3 << ( ( V_2 -> V_30 ^ 0x1 ) * 2 ) ;
V_70 -> V_76 ++ ;
V_70 -> V_77 ++ ;
return 0 ;
case V_44 :
V_70 -> V_78 [ V_2 -> V_30 ] = F_8 ( V_7 , V_21 ) ;
F_11 ( V_7 , V_21 , V_57 ,
0x40 << V_79 ) ;
V_70 -> V_76 -- ;
if ( V_70 -> V_76 == 0 ) {
V_71 [ 1 ] . V_22 = V_70 -> V_75 ;
F_29 ( V_9 -> V_12 ,
V_71 ,
F_4 ( V_71 ) ) ;
F_30 ( 55 ) ;
V_70 -> V_75 = 0 ;
}
break;
case V_20 :
F_11 ( V_7 , V_21 , V_57 ,
V_70 -> V_78 [ V_2 -> V_30 ] ) ;
V_70 -> V_77 -- ;
if ( V_70 -> V_77 == 0 )
F_29 ( V_9 -> V_12 ,
V_71 ,
F_4 ( V_71 ) ) ;
break;
default:
break;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_23 * V_24 = F_7 ( V_7 ) ;
struct V_9 * V_9 = V_24 -> V_9 ;
switch ( V_9 -> V_17 ) {
case 0 ... 4 :
if ( F_32 ( V_7 , V_2 -> V_30 ) )
F_28 ( V_2 , V_4 , V_5 ) ;
break;
default:
break;
}
return F_33 ( V_2 , V_4 , V_5 ) ;
}
static int F_34 ( struct V_6 * V_7 , int V_80 , int V_81 ,
unsigned int V_82 , unsigned int V_83 )
{
struct V_69 * V_70 = F_7 ( V_7 ) ;
switch ( V_80 ) {
case V_84 :
return F_35 ( & V_70 -> V_85 [ 0 ] , V_81 , V_82 , V_83 ) ;
case V_86 :
return F_35 ( & V_70 -> V_85 [ 1 ] , V_81 , V_82 , V_83 ) ;
case V_87 :
return F_36 ( & V_70 -> V_85 [ 0 ] , V_81 , V_82 ,
V_83 ) ;
case V_88 :
return F_36 ( & V_70 -> V_85 [ 1 ] , V_81 , V_82 ,
V_83 ) ;
default:
return - V_89 ;
}
}
static int F_37 ( struct V_90 * V_91 )
{
struct V_92 * V_93 = V_91 -> V_94 ;
struct V_69 * V_24 = F_7 ( V_93 -> V_7 ) ;
struct V_9 * V_9 = V_24 -> V_95 . V_9 ;
int V_96 ;
if ( strcmp ( V_93 -> V_97 -> V_98 , L_6 ) == 0 ) {
V_96 = 2 ;
} else {
F_16 ( V_9 -> V_10 ,
L_7 ,
V_93 -> V_97 -> V_98 ) ;
return - V_89 ;
}
return F_38 ( & V_24 -> V_95 . V_99 [ V_96 ] , V_91 ) ;
}
static T_1 F_39 ( int V_100 , void * V_101 )
{
struct V_69 * V_102 = V_101 ;
int V_48 ;
V_48 = F_40 ( & V_102 -> V_95 . V_99 [ 2 ] ) ;
if ( V_48 == - V_103 )
return V_104 ;
return V_105 ;
}
static int F_41 ( struct V_6 * V_7 )
{
struct V_51 * V_8 = F_19 ( V_7 ) ;
struct V_69 * V_24 = F_7 ( V_7 ) ;
struct V_9 * V_9 = V_24 -> V_95 . V_9 ;
int V_15 , V_48 ;
V_24 -> V_95 . V_9 -> V_8 = V_8 ;
F_42 ( V_7 ) ;
F_43 ( V_7 ) ;
F_44 ( V_7 ) ;
V_48 = F_45 ( V_9 , V_106 ,
L_8 , F_39 ,
V_24 ) ;
if ( V_48 != 0 ) {
F_16 ( V_7 -> V_10 , L_9 , V_48 ) ;
return V_48 ;
}
for ( V_15 = 0 ; V_15 < V_107 ; ++ V_15 ) {
V_48 = F_46 ( & V_24 -> V_95 . V_99 [ V_15 ] , V_7 ) ;
if ( V_48 )
goto V_108;
}
V_48 = F_47 ( V_7 ,
V_109 ,
V_107 ) ;
if ( V_48 )
goto V_108;
F_48 ( V_8 , L_10 ) ;
return 0 ;
V_108:
for ( -- V_15 ; V_15 >= 0 ; -- V_15 )
F_49 ( & V_24 -> V_95 . V_99 [ V_15 ] , V_7 ) ;
F_50 ( V_9 , V_106 , V_24 ) ;
return V_48 ;
}
static int F_51 ( struct V_6 * V_7 )
{
struct V_69 * V_24 = F_7 ( V_7 ) ;
struct V_9 * V_9 = V_24 -> V_95 . V_9 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_107 ; ++ V_15 )
F_49 ( & V_24 -> V_95 . V_99 [ V_15 ] , V_7 ) ;
V_24 -> V_95 . V_9 -> V_8 = NULL ;
F_50 ( V_9 , V_106 , V_24 ) ;
return 0 ;
}
static struct V_12 * F_52 ( struct V_110 * V_10 )
{
struct V_69 * V_24 = F_3 ( V_10 ) ;
return V_24 -> V_95 . V_9 -> V_12 ;
}
static int F_53 ( struct V_111 * V_112 )
{
struct V_9 * V_9 = F_3 ( V_112 -> V_10 . V_11 ) ;
struct V_69 * V_70 ;
int V_15 , V_48 ;
V_70 = F_54 ( & V_112 -> V_10 , sizeof( struct V_69 ) ,
V_113 ) ;
if ( V_70 == NULL )
return - V_114 ;
F_55 ( V_112 , V_70 ) ;
V_70 -> V_95 . V_9 = V_9 ;
V_70 -> V_95 . V_115 = 8 ;
for ( V_15 = 0 ; V_15 < V_107 ; V_15 ++ ) {
V_70 -> V_95 . V_99 [ V_15 ] . V_116 = L_11 ;
V_70 -> V_95 . V_99 [ V_15 ] . V_117 = V_15 + 1 ;
V_70 -> V_95 . V_99 [ V_15 ] . type = V_118 ;
V_70 -> V_95 . V_99 [ V_15 ] . V_10 = V_9 -> V_10 ;
V_70 -> V_95 . V_99 [ V_15 ] . V_12 = V_9 -> V_12 ;
V_70 -> V_95 . V_99 [ V_15 ] . V_119 = V_120
+ ( 0x100 * V_15 ) ;
V_70 -> V_95 . V_99 [ V_15 ] . V_121 = V_122 [ V_15 ] ;
V_70 -> V_95 . V_99 [ V_15 ] . V_123
= F_4 ( V_124 ) ;
V_48 = F_56 ( & V_70 -> V_95 . V_99 [ V_15 ] ) ;
if ( V_48 != 0 )
return V_48 ;
}
for ( V_15 = 0 ; V_15 < F_4 ( V_70 -> V_85 ) ; V_15 ++ )
V_70 -> V_85 [ V_15 ] . V_125 = 3 ;
F_57 ( V_9 , 1 , V_126 - 1 ,
V_127 , V_128 ,
& V_70 -> V_85 [ 0 ] ) ;
F_57 ( V_9 , 2 , V_129 - 1 ,
V_130 , V_131 ,
& V_70 -> V_85 [ 1 ] ) ;
F_22 ( V_9 -> V_12 , V_132 ,
V_133 , 0x11 ) ;
F_22 ( V_9 -> V_12 , V_134 ,
V_135 , 0x12 ) ;
for ( V_15 = 0 ; V_15 < F_4 ( V_136 ) ; V_15 ++ )
F_58 ( & V_70 -> V_95 , V_15 ) ;
for ( V_15 = 0 ; V_15 < F_4 ( V_137 ) ; V_15 ++ )
F_22 ( V_9 -> V_12 , V_137 [ V_15 ] ,
V_138 , V_138 ) ;
F_59 ( & V_112 -> V_10 ) ;
F_60 ( & V_112 -> V_10 ) ;
V_48 = F_61 ( & V_112 -> V_10 , & V_139 ) ;
if ( V_48 < 0 ) {
F_16 ( & V_112 -> V_10 , L_12 , V_48 ) ;
goto error;
}
V_48 = F_62 ( & V_112 -> V_10 , & V_140 ,
V_136 , F_4 ( V_136 ) ) ;
if ( V_48 < 0 ) {
F_16 ( & V_112 -> V_10 , L_13 , V_48 ) ;
F_63 ( & V_112 -> V_10 ) ;
}
error:
return V_48 ;
}
static int F_64 ( struct V_111 * V_112 )
{
F_63 ( & V_112 -> V_10 ) ;
F_65 ( & V_112 -> V_10 ) ;
F_66 ( & V_112 -> V_10 ) ;
return 0 ;
}
