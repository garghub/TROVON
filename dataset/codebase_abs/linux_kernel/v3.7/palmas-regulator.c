static int F_1 ( struct V_1 * V_1 , unsigned int V_2 ,
unsigned int * V_3 )
{
unsigned int V_4 ;
V_4 = F_2 ( V_5 , V_2 ) ;
return F_3 ( V_1 -> V_6 [ V_7 ] , V_4 , V_3 ) ;
}
static int F_4 ( struct V_1 * V_1 , unsigned int V_2 ,
unsigned int V_8 )
{
unsigned int V_4 ;
V_4 = F_2 ( V_5 , V_2 ) ;
return F_5 ( V_1 -> V_6 [ V_7 ] , V_4 , V_8 ) ;
}
static int F_6 ( struct V_1 * V_1 , unsigned int V_2 ,
unsigned int * V_3 )
{
unsigned int V_4 ;
V_4 = F_2 ( V_9 , V_2 ) ;
return F_3 ( V_1 -> V_6 [ V_7 ] , V_4 , V_3 ) ;
}
static int F_7 ( struct V_1 * V_1 , unsigned int V_2 ,
unsigned int V_8 )
{
unsigned int V_4 ;
V_4 = F_2 ( V_9 , V_2 ) ;
return F_5 ( V_1 -> V_6 [ V_7 ] , V_4 , V_8 ) ;
}
static int F_8 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_9 ( V_11 ) ;
int V_14 = F_10 ( V_11 ) ;
unsigned int V_2 ;
F_1 ( V_13 -> V_1 , V_15 [ V_14 ] . V_16 , & V_2 ) ;
V_2 &= V_17 ;
V_2 >>= V_18 ;
return ! ! ( V_2 ) ;
}
static int F_11 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_9 ( V_11 ) ;
int V_14 = F_10 ( V_11 ) ;
unsigned int V_2 ;
F_1 ( V_13 -> V_1 , V_15 [ V_14 ] . V_16 , & V_2 ) ;
V_2 &= ~ V_19 ;
V_2 |= V_20 ;
F_4 ( V_13 -> V_1 , V_15 [ V_14 ] . V_16 , V_2 ) ;
return 0 ;
}
static int F_12 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_9 ( V_11 ) ;
int V_14 = F_10 ( V_11 ) ;
unsigned int V_2 ;
F_1 ( V_13 -> V_1 , V_15 [ V_14 ] . V_16 , & V_2 ) ;
V_2 &= ~ V_19 ;
F_4 ( V_13 -> V_1 , V_15 [ V_14 ] . V_16 , V_2 ) ;
return 0 ;
}
static int F_13 ( struct V_10 * V_11 , unsigned int V_21 )
{
struct V_12 * V_13 = F_9 ( V_11 ) ;
int V_14 = F_10 ( V_11 ) ;
unsigned int V_2 ;
F_1 ( V_13 -> V_1 , V_15 [ V_14 ] . V_16 , & V_2 ) ;
V_2 &= ~ V_19 ;
switch ( V_21 ) {
case V_22 :
V_2 |= V_20 ;
break;
case V_23 :
V_2 |= V_24 ;
break;
case V_25 :
V_2 |= V_26 ;
break;
default:
return - V_27 ;
}
F_4 ( V_13 -> V_1 , V_15 [ V_14 ] . V_16 , V_2 ) ;
return 0 ;
}
static unsigned int F_14 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_9 ( V_11 ) ;
int V_14 = F_10 ( V_11 ) ;
unsigned int V_2 ;
F_1 ( V_13 -> V_1 , V_15 [ V_14 ] . V_16 , & V_2 ) ;
V_2 &= V_17 ;
V_2 >>= V_18 ;
switch ( V_2 ) {
case V_20 :
return V_22 ;
case V_24 :
return V_23 ;
case V_26 :
return V_25 ;
}
return 0 ;
}
static int F_15 ( struct V_10 * V_11 ,
unsigned V_28 )
{
struct V_12 * V_13 = F_9 ( V_11 ) ;
int V_14 = F_10 ( V_11 ) ;
int V_29 = 1 ;
if ( ! V_28 )
return 0 ;
if ( V_13 -> V_30 [ V_14 ] )
V_29 = 2 ;
return ( 490000 + ( V_28 * 10000 ) ) * V_29 ;
}
static int F_16 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_9 ( V_11 ) ;
int V_14 = F_10 ( V_11 ) ;
int V_28 ;
unsigned int V_2 ;
unsigned int V_4 ;
V_4 = V_15 [ V_14 ] . V_31 ;
F_1 ( V_13 -> V_1 , V_4 , & V_2 ) ;
V_28 = V_2 & V_32 ;
if ( ( V_28 > 0 ) && ( V_28 < 6 ) )
V_28 = 6 ;
if ( ! V_28 )
V_28 = 5 ;
if ( V_28 > 121 )
V_28 = 121 ;
V_28 -= 5 ;
return V_28 ;
}
static int F_17 ( struct V_10 * V_11 ,
unsigned V_28 )
{
struct V_12 * V_13 = F_9 ( V_11 ) ;
int V_14 = F_10 ( V_11 ) ;
unsigned int V_2 = 0 ;
unsigned int V_4 ;
V_4 = V_15 [ V_14 ] . V_31 ;
if ( V_13 -> V_30 [ V_14 ] )
V_2 |= V_33 ;
if ( V_28 )
V_2 |= V_28 + 5 ;
F_4 ( V_13 -> V_1 , V_4 , V_2 ) ;
return 0 ;
}
static int F_18 ( struct V_10 * V_34 ,
int V_35 , int V_36 )
{
struct V_12 * V_13 = F_9 ( V_34 ) ;
int V_14 = F_10 ( V_34 ) ;
int V_37 , V_38 ;
if ( V_35 == 0 )
return 0 ;
if ( V_13 -> V_30 [ V_14 ] ) {
if ( V_35 < 1000000 )
V_35 = 1000000 ;
V_37 = F_19 ( V_35 - 1000000 , 20000 ) + 1 ;
} else {
if ( V_35 < 500000 )
V_35 = 500000 ;
V_37 = F_19 ( V_35 - 500000 , 10000 ) + 1 ;
}
V_38 = F_15 ( V_34 , V_37 ) ;
if ( V_38 < V_35 || V_38 > V_36 )
return - V_27 ;
return V_37 ;
}
static int F_20 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_9 ( V_11 ) ;
int V_14 = F_10 ( V_11 ) ;
unsigned int V_2 ;
F_6 ( V_13 -> V_1 , V_15 [ V_14 ] . V_16 , & V_2 ) ;
V_2 &= V_39 ;
return ! ! ( V_2 ) ;
}
static int F_21 ( struct V_10 * V_11 ,
unsigned V_28 )
{
if ( ! V_28 )
return 0 ;
return 850000 + ( V_28 * 50000 ) ;
}
static int F_22 ( struct V_10 * V_34 ,
int V_35 , int V_36 )
{
int V_37 , V_38 ;
if ( V_35 == 0 )
return 0 ;
if ( V_35 < 900000 )
V_35 = 900000 ;
V_37 = F_19 ( V_35 - 900000 , 50000 ) + 1 ;
V_38 = F_21 ( V_34 , V_37 ) ;
if ( V_38 < V_35 || V_38 > V_36 )
return - V_27 ;
return V_37 ;
}
static int F_23 ( struct V_1 * V_1 , int V_14 ,
struct V_40 * V_41 )
{
unsigned int V_2 ;
unsigned int V_4 ;
int V_37 ;
V_4 = V_15 [ V_14 ] . V_16 ;
V_37 = F_1 ( V_1 , V_4 , & V_2 ) ;
if ( V_37 )
return V_37 ;
switch ( V_14 ) {
case V_42 :
if ( V_41 -> V_43 ) {
V_2 &= ~ V_44 ;
V_2 |= V_41 -> V_43 <<
V_45 ;
}
break;
default:
if ( V_41 -> V_46 )
V_2 |= V_47 ;
if ( V_41 -> V_48 )
V_2 |= V_49 ;
if ( V_41 -> V_43 ) {
V_2 &= ~ V_50 ;
V_2 |= V_41 -> V_43 <<
V_51 ;
}
}
V_37 = F_4 ( V_1 , V_4 , V_2 ) ;
if ( V_37 )
return V_37 ;
if ( V_15 [ V_14 ] . V_52 && V_41 -> V_53 ) {
V_4 = V_15 [ V_14 ] . V_52 ;
V_2 = V_41 -> V_53 & V_54 ;
V_37 = F_4 ( V_1 , V_4 , V_2 ) ;
if ( V_37 )
return V_37 ;
}
if ( V_15 [ V_14 ] . V_31 && V_41 -> V_55 ) {
V_4 = V_15 [ V_14 ] . V_31 ;
V_2 = V_41 -> V_55 ;
V_37 = F_4 ( V_1 , V_4 , V_2 ) ;
if ( V_37 )
return V_37 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_1 , int V_14 ,
struct V_40 * V_41 )
{
unsigned int V_2 ;
unsigned int V_4 ;
int V_37 ;
V_4 = V_15 [ V_14 ] . V_16 ;
V_37 = F_6 ( V_1 , V_4 , & V_2 ) ;
if ( V_37 )
return V_37 ;
if ( V_41 -> V_46 )
V_2 |= V_56 ;
if ( V_41 -> V_43 )
V_2 |= V_57 ;
V_37 = F_7 ( V_1 , V_4 , V_2 ) ;
if ( V_37 )
return V_37 ;
return 0 ;
}
static void T_1 F_25 ( struct V_58 * V_11 ,
struct V_59 * V_60 ,
struct V_61 * V_62 )
{
struct V_59 * V_63 ;
T_2 V_64 ;
int V_65 , V_37 ;
V_63 = F_26 ( V_60 , L_1 ) ;
if ( ! V_63 ) {
F_27 ( V_11 , L_2 ) ;
return;
}
V_37 = F_28 ( V_11 , V_63 , V_66 ,
V_67 ) ;
if ( V_37 < 0 ) {
F_29 ( V_11 , L_3 , V_37 ) ;
return;
}
for ( V_65 = 0 ; V_65 < V_67 ; V_65 ++ ) {
if ( ! V_66 [ V_65 ] . V_68 ||
! V_66 [ V_65 ] . V_69 )
continue;
V_62 -> V_70 [ V_65 ] = V_66 [ V_65 ] . V_68 ;
V_62 -> V_41 [ V_65 ] = F_30 ( V_11 ,
sizeof( struct V_40 ) , V_71 ) ;
V_37 = F_31 ( V_66 [ V_65 ] . V_69 ,
L_4 , & V_64 ) ;
if ( ! V_37 )
V_62 -> V_41 [ V_65 ] -> V_46 = V_64 ;
V_37 = F_31 ( V_66 [ V_65 ] . V_69 ,
L_5 , & V_64 ) ;
if ( ! V_37 )
V_62 -> V_41 [ V_65 ] -> V_48 = V_64 ;
V_37 = F_31 ( V_66 [ V_65 ] . V_69 ,
L_6 , & V_64 ) ;
if ( ! V_37 )
V_62 -> V_41 [ V_65 ] -> V_43 = V_64 ;
V_37 = F_31 ( V_66 [ V_65 ] . V_69 ,
L_4 , & V_64 ) ;
if ( ! V_37 )
V_62 -> V_41 [ V_65 ] -> V_46 = V_64 ;
V_37 = F_31 ( V_66 [ V_65 ] . V_69 ,
L_7 , & V_64 ) ;
if ( ! V_37 )
V_62 -> V_41 [ V_65 ] -> V_53 = V_64 ;
V_37 = F_31 ( V_66 [ V_65 ] . V_69 ,
L_8 , & V_64 ) ;
if ( ! V_37 )
V_62 -> V_41 [ V_65 ] -> V_55 = V_64 ;
}
V_37 = F_31 ( V_60 , L_9 , & V_64 ) ;
if ( ! V_37 )
V_62 -> V_72 = V_64 ;
}
static T_1 int F_32 ( struct V_73 * V_74 )
{
struct V_1 * V_1 = F_33 ( V_74 -> V_11 . V_75 ) ;
struct V_61 * V_62 = V_74 -> V_11 . V_76 ;
struct V_59 * V_60 = V_74 -> V_11 . V_69 ;
struct V_10 * V_34 ;
struct V_77 V_78 = { } ;
struct V_12 * V_13 ;
struct V_40 * V_41 ;
int V_14 = 0 , V_37 ;
unsigned int V_4 , V_2 ;
if ( V_60 && ! V_62 ) {
V_62 = F_30 ( & V_74 -> V_11 , sizeof( * V_62 ) , V_71 ) ;
if ( ! V_62 )
return - V_79 ;
F_25 ( & V_74 -> V_11 , V_60 , V_62 ) ;
}
V_13 = F_30 ( & V_74 -> V_11 , sizeof( * V_13 ) , V_71 ) ;
if ( ! V_13 )
return - V_79 ;
V_13 -> V_11 = & V_74 -> V_11 ;
V_13 -> V_1 = V_1 ;
V_1 -> V_13 = V_13 ;
F_34 ( V_74 , V_13 ) ;
V_37 = F_1 ( V_1 , V_80 , & V_2 ) ;
if ( V_37 )
return V_37 ;
if ( V_2 & V_81 )
V_13 -> V_82 = 1 ;
if ( V_2 & V_83 )
V_13 -> V_84 = 1 ;
V_78 . V_6 = V_1 -> V_6 [ V_7 ] ;
V_78 . V_11 = & V_74 -> V_11 ;
V_78 . V_85 = V_13 ;
for ( V_14 = 0 ; V_14 < V_86 ; V_14 ++ ) {
switch ( V_14 ) {
case V_87 :
case V_88 :
if ( V_13 -> V_82 )
continue;
break;
case V_89 :
if ( ! V_13 -> V_82 )
continue;
break;
case V_90 :
case V_91 :
if ( V_13 -> V_84 )
continue;
break;
case V_92 :
if ( ! V_13 -> V_84 )
continue;
}
V_13 -> V_93 [ V_14 ] . V_94 = V_15 [ V_14 ] . V_94 ;
V_13 -> V_93 [ V_14 ] . V_14 = V_14 ;
switch ( V_14 ) {
case V_42 :
V_13 -> V_93 [ V_14 ] . V_95 = V_96 ;
V_13 -> V_93 [ V_14 ] . V_97 = & V_98 ;
V_13 -> V_93 [ V_14 ] . V_99 =
F_2 ( V_5 ,
V_100 ) ;
V_13 -> V_93 [ V_14 ] . V_101 = V_102 ;
V_13 -> V_93 [ V_14 ] . V_103 =
F_2 ( V_5 ,
V_104 ) ;
V_13 -> V_93 [ V_14 ] . V_105 = V_106 ;
V_13 -> V_93 [ V_14 ] . V_35 = 3750000 ;
V_13 -> V_93 [ V_14 ] . V_107 = 1250000 ;
break;
default:
V_13 -> V_93 [ V_14 ] . V_97 = & V_108 ;
V_13 -> V_93 [ V_14 ] . V_95 = V_109 ;
}
V_13 -> V_93 [ V_14 ] . type = V_110 ;
V_13 -> V_93 [ V_14 ] . V_111 = V_112 ;
if ( V_62 ) {
V_41 = V_62 -> V_41 [ V_14 ] ;
if ( V_41 ) {
V_37 = F_23 ( V_1 , V_14 , V_41 ) ;
if ( V_37 )
goto V_113;
}
}
if ( V_14 != V_42 ) {
V_4 = V_15 [ V_14 ] . V_31 ;
V_37 = F_1 ( V_13 -> V_1 , V_4 , & V_2 ) ;
if ( V_37 )
goto V_113;
if ( V_2 & V_33 )
V_13 -> V_30 [ V_14 ] = 1 ;
}
if ( V_62 )
V_78 . V_68 = V_62 -> V_70 [ V_14 ] ;
else
V_78 . V_68 = NULL ;
V_78 . V_69 = V_66 [ V_14 ] . V_69 ;
V_34 = F_35 ( & V_13 -> V_93 [ V_14 ] , & V_78 ) ;
if ( F_36 ( V_34 ) ) {
F_29 ( & V_74 -> V_11 ,
L_10 ,
V_74 -> V_94 ) ;
V_37 = F_37 ( V_34 ) ;
goto V_113;
}
V_13 -> V_34 [ V_14 ] = V_34 ;
}
for (; V_14 < V_67 ; V_14 ++ ) {
V_13 -> V_93 [ V_14 ] . V_94 = V_15 [ V_14 ] . V_94 ;
V_13 -> V_93 [ V_14 ] . V_14 = V_14 ;
V_13 -> V_93 [ V_14 ] . V_95 = V_114 ;
V_13 -> V_93 [ V_14 ] . V_97 = & V_115 ;
V_13 -> V_93 [ V_14 ] . type = V_110 ;
V_13 -> V_93 [ V_14 ] . V_111 = V_112 ;
V_13 -> V_93 [ V_14 ] . V_99 = F_2 ( V_9 ,
V_15 [ V_14 ] . V_31 ) ;
V_13 -> V_93 [ V_14 ] . V_101 = V_116 ;
V_13 -> V_93 [ V_14 ] . V_103 = F_2 ( V_9 ,
V_15 [ V_14 ] . V_16 ) ;
V_13 -> V_93 [ V_14 ] . V_105 = V_117 ;
if ( V_62 )
V_78 . V_68 = V_62 -> V_70 [ V_14 ] ;
else
V_78 . V_68 = NULL ;
V_78 . V_69 = V_66 [ V_14 ] . V_69 ;
V_34 = F_35 ( & V_13 -> V_93 [ V_14 ] , & V_78 ) ;
if ( F_36 ( V_34 ) ) {
F_29 ( & V_74 -> V_11 ,
L_10 ,
V_74 -> V_94 ) ;
V_37 = F_37 ( V_34 ) ;
goto V_113;
}
V_13 -> V_34 [ V_14 ] = V_34 ;
if ( V_62 ) {
V_41 = V_62 -> V_41 [ V_14 ] ;
if ( V_41 ) {
V_37 = F_24 ( V_1 , V_14 , V_41 ) ;
if ( V_37 ) {
F_38 ( V_13 -> V_34 [ V_14 ] ) ;
goto V_113;
}
}
}
}
return 0 ;
V_113:
while ( -- V_14 >= 0 )
F_38 ( V_13 -> V_34 [ V_14 ] ) ;
return V_37 ;
}
static int T_3 F_39 ( struct V_73 * V_74 )
{
struct V_12 * V_13 = F_40 ( V_74 ) ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_67 ; V_14 ++ )
F_38 ( V_13 -> V_34 [ V_14 ] ) ;
return 0 ;
}
static int T_4 F_41 ( void )
{
return F_42 ( & V_118 ) ;
}
static void T_5 F_43 ( void )
{
F_44 ( & V_118 ) ;
}
