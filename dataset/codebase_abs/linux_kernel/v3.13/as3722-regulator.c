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
static int F_17 ( struct V_9 * V_10 , int V_12 ,
int V_45 )
{
int V_14 ;
unsigned int V_13 ;
if ( ( V_45 < V_46 ) ||
( V_45 > V_47 ) )
return - V_6 ;
V_13 = V_45 << ( F_15 ( V_15 [ V_12 ] . V_48 ) - 1 ) ;
V_14 = F_9 ( V_10 -> V_11 ,
V_15 [ V_12 ] . V_49 ,
V_15 [ V_12 ] . V_48 , V_13 ) ;
if ( V_14 < 0 )
F_6 ( V_10 -> V_17 , L_3 ,
V_15 [ V_12 ] . V_49 , V_14 ) ;
return V_14 ;
}
static int F_18 ( struct V_50 * V_51 ,
struct V_9 * V_10 )
{
struct V_52 * V_53 ;
struct V_54 * V_55 ;
T_1 V_56 ;
int V_12 ;
int V_14 ;
V_53 = F_19 ( V_51 -> V_17 . V_57 -> V_58 , L_4 ) ;
if ( ! V_53 ) {
F_6 ( & V_51 -> V_17 , L_5 ) ;
return - V_59 ;
}
V_51 -> V_17 . V_58 = V_53 ;
V_14 = F_20 ( & V_51 -> V_17 , V_53 , V_60 ,
F_8 ( V_60 ) ) ;
if ( V_14 < 0 ) {
F_6 ( & V_51 -> V_17 , L_6 ,
V_14 ) ;
return V_14 ;
}
for ( V_12 = 0 ; V_12 < F_8 ( V_60 ) ; ++ V_12 ) {
struct V_52 * V_61 ;
V_55 = & V_10 -> V_62 [ V_12 ] ;
V_55 -> V_63 = V_60 [ V_12 ] . V_64 ;
V_61 = V_60 [ V_12 ] . V_58 ;
if ( ! V_55 -> V_63 || ! V_61 )
continue;
V_14 = F_21 ( V_61 , L_7 , & V_56 ) ;
if ( ! V_14 ) {
if ( V_56 < 3 )
V_55 -> V_65 = V_56 ;
else
F_22 ( & V_51 -> V_17 ,
L_8 ,
V_56 ) ;
}
V_55 -> V_66 =
F_23 ( V_61 , L_9 ) ;
}
return 0 ;
}
static int F_24 ( struct V_50 * V_51 )
{
struct V_11 * V_11 = F_25 ( V_51 -> V_17 . V_57 ) ;
struct V_9 * V_10 ;
struct V_54 * V_55 ;
struct V_7 * V_8 ;
struct V_67 V_68 = { } ;
struct V_69 * V_70 ;
int V_12 ;
int V_14 ;
V_10 = F_26 ( & V_51 -> V_17 , sizeof( * V_10 ) ,
V_71 ) ;
if ( ! V_10 )
return - V_72 ;
V_10 -> V_17 = & V_51 -> V_17 ;
V_10 -> V_11 = V_11 ;
F_27 ( V_51 , V_10 ) ;
V_14 = F_18 ( V_51 , V_10 ) ;
if ( V_14 < 0 )
return V_14 ;
V_68 . V_17 = & V_51 -> V_17 ;
V_68 . V_73 = V_10 ;
V_68 . V_74 = V_11 -> V_74 ;
for ( V_12 = 0 ; V_12 < V_75 ; V_12 ++ ) {
V_55 = & V_10 -> V_62 [ V_12 ] ;
V_10 -> V_76 [ V_12 ] . V_77 = V_15 [ V_12 ] . V_77 ;
V_10 -> V_76 [ V_12 ] . V_78 = V_15 [ V_12 ] . V_79 ;
V_10 -> V_76 [ V_12 ] . V_12 = V_15 [ V_12 ] . V_80 ;
V_10 -> V_76 [ V_12 ] . V_81 =
V_15 [ V_12 ] . V_81 ;
V_10 -> V_76 [ V_12 ] . type = V_82 ;
V_10 -> V_76 [ V_12 ] . V_83 = V_84 ;
V_10 -> V_76 [ V_12 ] . V_85 =
V_15 [ V_12 ] . V_85 ;
V_10 -> V_76 [ V_12 ] . V_86 =
V_15 [ V_12 ] . V_86 ;
V_10 -> V_76 [ V_12 ] . V_16 = V_15 [ V_12 ] . V_16 ;
V_10 -> V_76 [ V_12 ] . V_87 =
V_15 [ V_12 ] . V_87 ;
switch ( V_12 ) {
case V_88 :
if ( V_55 -> V_65 )
V_70 = & V_89 ;
else
V_70 = & V_90 ;
V_10 -> V_76 [ V_12 ] . V_91 = 825000 ;
V_10 -> V_76 [ V_12 ] . V_92 = 25000 ;
V_10 -> V_76 [ V_12 ] . V_93 = 1 ;
V_10 -> V_76 [ V_12 ] . V_94 = 500 ;
break;
case V_95 :
if ( V_55 -> V_65 )
V_70 = & V_96 ;
else
V_70 = & V_97 ;
V_10 -> V_76 [ V_12 ] . V_91 = 620000 ;
V_10 -> V_76 [ V_12 ] . V_92 = 20000 ;
V_10 -> V_76 [ V_12 ] . V_93 = 1 ;
V_10 -> V_76 [ V_12 ] . V_94 = 500 ;
if ( V_55 -> V_66 ) {
V_14 = F_10 ( V_10 ,
V_12 , V_25 ) ;
if ( V_14 < 0 ) {
F_6 ( & V_51 -> V_17 ,
L_10 ,
V_14 ) ;
return V_14 ;
}
}
break;
case V_36 :
case V_39 :
case V_41 :
if ( V_55 -> V_65 )
V_70 = & V_98 ;
else
V_70 = & V_99 ;
V_10 -> V_76 [ V_12 ] . V_91 = 610000 ;
V_10 -> V_76 [ V_12 ] . V_92 = 10000 ;
V_10 -> V_76 [ V_12 ] . V_93 = 1 ;
break;
case V_100 :
case V_101 :
case V_102 :
case V_103 :
if ( V_55 -> V_65 )
V_70 = & V_104 ;
else
V_70 = & V_105 ;
V_10 -> V_76 [ V_12 ] . V_106 =
V_107 ;
V_10 -> V_76 [ V_12 ] . V_108 =
F_8 ( V_107 ) ;
break;
default:
if ( V_55 -> V_65 )
V_70 = & V_109 ;
else
V_70 = & V_110 ;
V_10 -> V_76 [ V_12 ] . V_91 = 825000 ;
V_10 -> V_76 [ V_12 ] . V_92 = 25000 ;
V_10 -> V_76 [ V_12 ] . V_93 = 1 ;
V_10 -> V_76 [ V_12 ] . V_94 = 500 ;
V_10 -> V_76 [ V_12 ] . V_106 = V_111 ;
V_10 -> V_76 [ V_12 ] . V_108 =
F_8 ( V_111 ) ;
break;
}
V_10 -> V_76 [ V_12 ] . V_70 = V_70 ;
V_68 . V_64 = V_55 -> V_63 ;
V_68 . V_58 = V_60 [ V_12 ] . V_58 ;
V_8 = F_28 ( & V_51 -> V_17 ,
& V_10 -> V_76 [ V_12 ] , & V_68 ) ;
if ( F_29 ( V_8 ) ) {
V_14 = F_30 ( V_8 ) ;
F_6 ( & V_51 -> V_17 , L_11 ,
V_12 , V_14 ) ;
return V_14 ;
}
V_10 -> V_112 [ V_12 ] = V_8 ;
if ( V_55 -> V_65 ) {
V_14 = F_31 ( V_8 ) ;
if ( V_14 < 0 ) {
F_6 ( & V_51 -> V_17 ,
L_12 ,
V_12 , V_14 ) ;
return V_14 ;
}
V_14 = F_17 ( V_10 , V_12 ,
V_55 -> V_65 ) ;
if ( V_14 < 0 ) {
F_6 ( & V_51 -> V_17 ,
L_13 , V_14 ) ;
return V_14 ;
}
}
}
return 0 ;
}
