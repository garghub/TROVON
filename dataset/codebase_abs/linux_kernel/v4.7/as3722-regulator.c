static int F_1 ( int V_1 , int V_2 ,
const int * V_3 , int V_4 )
{
int V_5 ;
for ( V_5 = V_4 - 1 ; V_5 >= 0 ; V_5 -- ) {
if ( ( V_1 <= V_3 [ V_5 ] ) && ( V_3 [ V_5 ] <= V_2 ) )
return V_5 ;
}
return - V_6 ;
}
static int F_2 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
struct V_11 * V_11 = V_10 -> V_11 ;
int V_12 = F_4 ( V_8 ) ;
T_1 V_13 ;
int V_14 ;
V_14 = F_5 ( V_11 , V_15 [ V_12 ] . V_16 , & V_13 ) ;
if ( V_14 < 0 ) {
F_6 ( V_10 -> V_17 , L_1 ,
V_15 [ V_12 ] . V_16 , V_14 ) ;
return V_14 ;
}
if ( V_13 & V_18 )
return 300000 ;
return 150000 ;
}
static int F_7 ( struct V_7 * V_8 ,
int V_1 , int V_2 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
struct V_11 * V_11 = V_10 -> V_11 ;
int V_12 = F_4 ( V_8 ) ;
int V_14 ;
T_1 V_19 = 0 ;
V_14 = F_1 ( V_1 , V_2 , V_20 ,
F_8 ( V_20 ) ) ;
if ( V_14 < 0 ) {
F_6 ( V_10 -> V_17 ,
L_2 ,
V_1 , V_2 ) ;
return V_14 ;
}
if ( V_14 )
V_19 = V_21 ;
return F_9 ( V_11 , V_15 [ V_12 ] . V_16 ,
V_18 , V_19 ) ;
}
static int F_10 ( struct V_9 * V_22 ,
int V_12 , T_2 V_23 )
{
struct V_11 * V_11 = V_22 -> V_11 ;
switch ( V_23 ) {
case V_24 :
case V_25 :
case V_26 :
case V_27 :
return F_9 ( V_11 ,
V_15 [ V_12 ] . V_16 ,
V_28 , V_23 ) ;
default:
return - V_6 ;
}
}
static int F_11 ( struct V_7 * V_8 )
{
return 150000 ;
}
static unsigned int F_12 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
struct V_11 * V_11 = V_10 -> V_11 ;
int V_12 = F_4 ( V_8 ) ;
T_1 V_13 ;
int V_14 ;
if ( ! V_15 [ V_12 ] . V_29 )
return - V_30 ;
V_14 = F_5 ( V_11 , V_15 [ V_12 ] . V_29 , & V_13 ) ;
if ( V_14 < 0 ) {
F_6 ( V_10 -> V_17 , L_1 ,
V_15 [ V_12 ] . V_29 , V_14 ) ;
return V_14 ;
}
if ( V_13 & V_15 [ V_12 ] . V_31 )
return V_32 ;
else
return V_33 ;
}
static int F_13 ( struct V_7 * V_8 ,
unsigned int V_23 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
struct V_11 * V_11 = V_10 -> V_11 ;
T_2 V_12 = F_4 ( V_8 ) ;
T_2 V_13 = 0 ;
int V_14 ;
if ( ! V_15 [ V_12 ] . V_29 )
return - V_34 ;
switch ( V_23 ) {
case V_32 :
V_13 = V_15 [ V_12 ] . V_31 ;
case V_33 :
break;
default:
return - V_6 ;
}
V_14 = F_9 ( V_11 , V_15 [ V_12 ] . V_29 ,
V_15 [ V_12 ] . V_31 , V_13 ) ;
if ( V_14 < 0 ) {
F_6 ( V_10 -> V_17 , L_3 ,
V_15 [ V_12 ] . V_29 , V_14 ) ;
return V_14 ;
}
return V_14 ;
}
static int F_14 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
struct V_11 * V_11 = V_10 -> V_11 ;
int V_12 = F_4 ( V_8 ) ;
T_1 V_13 , V_19 ;
int V_35 ;
int V_14 ;
switch ( V_12 ) {
case V_36 :
V_19 = V_37 ;
V_35 = V_38 ;
break;
case V_39 :
V_19 = V_37 ;
V_35 = V_40 ;
break;
case V_41 :
V_19 = V_42 ;
V_35 = V_43 ;
break;
default:
return - V_6 ;
}
V_14 = F_5 ( V_11 , V_19 , & V_13 ) ;
if ( V_14 < 0 ) {
F_6 ( V_10 -> V_17 , L_1 ,
V_19 , V_14 ) ;
return V_14 ;
}
V_13 &= V_35 ;
V_13 >>= F_15 ( V_35 ) - 1 ;
if ( V_13 == 3 )
return - V_6 ;
return V_44 [ V_13 ] ;
}
static int F_16 ( struct V_7 * V_8 ,
int V_1 , int V_2 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
struct V_11 * V_11 = V_10 -> V_11 ;
int V_12 = F_4 ( V_8 ) ;
int V_14 ;
int V_13 ;
int V_35 ;
T_1 V_19 ;
V_14 = F_1 ( V_1 , V_2 , V_44 ,
F_8 ( V_44 ) ) ;
if ( V_14 < 0 ) {
F_6 ( V_10 -> V_17 ,
L_2 ,
V_1 , V_2 ) ;
return V_14 ;
}
switch ( V_12 ) {
case V_36 :
V_19 = V_37 ;
V_35 = V_38 ;
break;
case V_39 :
V_19 = V_37 ;
V_35 = V_40 ;
break;
case V_41 :
V_19 = V_42 ;
V_35 = V_43 ;
break;
default:
return - V_6 ;
}
V_14 <<= F_15 ( V_35 ) - 1 ;
V_13 = V_14 & V_35 ;
return F_9 ( V_11 , V_19 , V_35 , V_13 ) ;
}
static bool F_17 ( struct V_9 * V_10 )
{
int V_45 ;
unsigned V_13 ;
V_45 = F_5 ( V_10 -> V_11 , V_46 , & V_13 ) ;
if ( V_45 < 0 ) {
F_6 ( V_10 -> V_17 , L_1 ,
V_46 , V_45 ) ;
return false ;
}
if ( V_13 & V_47 )
return true ;
return false ;
}
static int F_18 ( struct V_9 * V_10 , int V_12 ,
int V_48 )
{
int V_14 ;
unsigned int V_13 ;
if ( ( V_48 < V_49 ) ||
( V_48 > V_50 ) )
return - V_6 ;
V_13 = V_48 << ( F_15 ( V_15 [ V_12 ] . V_51 ) - 1 ) ;
V_14 = F_9 ( V_10 -> V_11 ,
V_15 [ V_12 ] . V_52 ,
V_15 [ V_12 ] . V_51 , V_13 ) ;
if ( V_14 < 0 )
F_6 ( V_10 -> V_17 , L_3 ,
V_15 [ V_12 ] . V_52 , V_14 ) ;
return V_14 ;
}
static int F_19 ( struct V_53 * V_54 ,
struct V_9 * V_10 )
{
struct V_55 * V_56 ;
struct V_57 * V_58 ;
T_1 V_59 ;
int V_12 ;
int V_14 ;
V_56 = F_20 ( V_54 -> V_17 . V_60 -> V_61 , L_4 ) ;
if ( ! V_56 ) {
F_6 ( & V_54 -> V_17 , L_5 ) ;
return - V_62 ;
}
V_54 -> V_17 . V_61 = V_56 ;
V_14 = F_21 ( & V_54 -> V_17 , V_56 , V_63 ,
F_8 ( V_63 ) ) ;
F_22 ( V_56 ) ;
if ( V_14 < 0 ) {
F_6 ( & V_54 -> V_17 , L_6 ,
V_14 ) ;
return V_14 ;
}
for ( V_12 = 0 ; V_12 < F_8 ( V_63 ) ; ++ V_12 ) {
struct V_55 * V_64 ;
V_58 = & V_10 -> V_65 [ V_12 ] ;
V_58 -> V_66 = V_63 [ V_12 ] . V_67 ;
V_64 = V_63 [ V_12 ] . V_61 ;
if ( ! V_58 -> V_66 || ! V_64 )
continue;
V_14 = F_23 ( V_64 , L_7 , & V_59 ) ;
if ( ! V_14 ) {
if ( V_59 < 3 )
V_58 -> V_68 = V_59 ;
else
F_24 ( & V_54 -> V_17 ,
L_8 ,
V_59 ) ;
}
V_58 -> V_69 =
F_25 ( V_64 , L_9 ) ;
}
return 0 ;
}
static int F_26 ( struct V_53 * V_54 )
{
struct V_11 * V_11 = F_27 ( V_54 -> V_17 . V_60 ) ;
struct V_9 * V_10 ;
struct V_57 * V_58 ;
struct V_7 * V_8 ;
struct V_70 V_71 = { } ;
const struct V_72 * V_73 ;
int V_12 ;
int V_14 ;
V_10 = F_28 ( & V_54 -> V_17 , sizeof( * V_10 ) ,
V_74 ) ;
if ( ! V_10 )
return - V_75 ;
V_10 -> V_17 = & V_54 -> V_17 ;
V_10 -> V_11 = V_11 ;
F_29 ( V_54 , V_10 ) ;
V_14 = F_19 ( V_54 , V_10 ) ;
if ( V_14 < 0 )
return V_14 ;
V_71 . V_17 = & V_54 -> V_17 ;
V_71 . V_76 = V_10 ;
V_71 . V_77 = V_11 -> V_77 ;
for ( V_12 = 0 ; V_12 < V_78 ; V_12 ++ ) {
V_58 = & V_10 -> V_65 [ V_12 ] ;
V_10 -> V_79 [ V_12 ] . V_80 = V_15 [ V_12 ] . V_80 ;
V_10 -> V_79 [ V_12 ] . V_81 = V_15 [ V_12 ] . V_82 ;
V_10 -> V_79 [ V_12 ] . V_12 = V_15 [ V_12 ] . V_83 ;
V_10 -> V_79 [ V_12 ] . V_84 =
V_15 [ V_12 ] . V_84 ;
V_10 -> V_79 [ V_12 ] . type = V_85 ;
V_10 -> V_79 [ V_12 ] . V_86 = V_87 ;
V_10 -> V_79 [ V_12 ] . V_88 =
V_15 [ V_12 ] . V_88 ;
V_10 -> V_79 [ V_12 ] . V_89 =
V_15 [ V_12 ] . V_89 ;
V_10 -> V_79 [ V_12 ] . V_16 = V_15 [ V_12 ] . V_16 ;
V_10 -> V_79 [ V_12 ] . V_90 =
V_15 [ V_12 ] . V_90 ;
switch ( V_12 ) {
case V_91 :
if ( V_58 -> V_68 )
V_73 = & V_92 ;
else
V_73 = & V_93 ;
V_10 -> V_79 [ V_12 ] . V_94 = 825000 ;
V_10 -> V_79 [ V_12 ] . V_95 = 25000 ;
V_10 -> V_79 [ V_12 ] . V_96 = 1 ;
V_10 -> V_79 [ V_12 ] . V_97 = 500 ;
break;
case V_98 :
if ( V_58 -> V_68 )
V_73 = & V_99 ;
else
V_73 = & V_100 ;
V_10 -> V_79 [ V_12 ] . V_94 = 620000 ;
V_10 -> V_79 [ V_12 ] . V_95 = 20000 ;
V_10 -> V_79 [ V_12 ] . V_96 = 1 ;
V_10 -> V_79 [ V_12 ] . V_97 = 500 ;
if ( V_58 -> V_69 ) {
V_14 = F_10 ( V_10 ,
V_12 , V_25 ) ;
if ( V_14 < 0 ) {
F_6 ( & V_54 -> V_17 ,
L_10 ,
V_14 ) ;
return V_14 ;
}
}
break;
case V_101 :
if ( V_58 -> V_68 )
V_73 = & V_102 ;
else
V_73 = & V_103 ;
V_10 -> V_79 [ V_12 ] . V_97 = 500 ;
V_10 -> V_79 [ V_12 ] . V_104 =
V_105 ;
V_10 -> V_79 [ V_12 ] . V_106 =
V_107 ;
V_10 -> V_79 [ V_12 ] . V_108 =
V_109 ;
V_10 -> V_79 [ V_12 ] . V_110 =
V_109 ;
V_10 -> V_79 [ V_12 ] . V_111 = V_112 ;
V_10 -> V_79 [ V_12 ] . V_113 =
F_8 ( V_112 ) ;
break;
case V_36 :
case V_39 :
case V_41 :
if ( V_58 -> V_68 )
V_73 = & V_114 ;
else
V_73 = & V_115 ;
if ( V_12 == V_36 &&
F_17 ( V_10 ) ) {
V_10 -> V_79 [ V_12 ] . V_84 =
V_116 + 1 ;
V_10 -> V_79 [ V_12 ] . V_94 = 410000 ;
} else {
V_10 -> V_79 [ V_12 ] . V_84 =
V_117 + 1 ,
V_10 -> V_79 [ V_12 ] . V_94 = 610000 ;
}
V_10 -> V_79 [ V_12 ] . V_95 = 10000 ;
V_10 -> V_79 [ V_12 ] . V_96 = 1 ;
V_10 -> V_79 [ V_12 ] . V_97 = 600 ;
break;
case V_118 :
case V_119 :
case V_120 :
case V_121 :
if ( V_58 -> V_68 )
V_73 = & V_122 ;
else
V_73 = & V_123 ;
V_10 -> V_79 [ V_12 ] . V_111 =
V_124 ;
V_10 -> V_79 [ V_12 ] . V_113 =
F_8 ( V_124 ) ;
break;
default:
if ( V_58 -> V_68 )
V_73 = & V_125 ;
else
V_73 = & V_126 ;
V_10 -> V_79 [ V_12 ] . V_97 = 500 ;
V_10 -> V_79 [ V_12 ] . V_111 = V_112 ;
V_10 -> V_79 [ V_12 ] . V_113 =
F_8 ( V_112 ) ;
break;
}
V_10 -> V_79 [ V_12 ] . V_73 = V_73 ;
V_71 . V_67 = V_58 -> V_66 ;
V_71 . V_61 = V_63 [ V_12 ] . V_61 ;
V_8 = F_30 ( & V_54 -> V_17 ,
& V_10 -> V_79 [ V_12 ] , & V_71 ) ;
if ( F_31 ( V_8 ) ) {
V_14 = F_32 ( V_8 ) ;
F_6 ( & V_54 -> V_17 , L_11 ,
V_12 , V_14 ) ;
return V_14 ;
}
V_10 -> V_127 [ V_12 ] = V_8 ;
if ( V_58 -> V_68 ) {
V_14 = F_33 ( V_8 ) ;
if ( V_14 < 0 ) {
F_6 ( & V_54 -> V_17 ,
L_12 ,
V_12 , V_14 ) ;
return V_14 ;
}
V_14 = F_18 ( V_10 , V_12 ,
V_58 -> V_68 ) ;
if ( V_14 < 0 ) {
F_6 ( & V_54 -> V_17 ,
L_13 , V_14 ) ;
return V_14 ;
}
}
}
return 0 ;
}
