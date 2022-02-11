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
V_2 &= ~ V_17 ;
V_2 >>= V_18 ;
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
int V_37 , V_38 ;
V_37 = ( ( V_35 - 500000 ) / 10000 ) + 1 ;
if ( V_37 < 0 )
return V_37 ;
V_38 = F_15 ( V_34 , V_37 ) ;
if ( V_38 < V_35 || V_38 > V_36 )
return - V_27 ;
return V_37 ;
}
static int F_19 ( struct V_10 * V_11 ,
unsigned V_28 )
{
return 3750000 + ( V_28 * 1250000 ) ;
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
static int F_22 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_9 ( V_11 ) ;
int V_14 = F_10 ( V_11 ) ;
int V_28 ;
unsigned int V_2 ;
unsigned int V_4 ;
V_4 = V_15 [ V_14 ] . V_31 ;
F_6 ( V_13 -> V_1 , V_4 , & V_2 ) ;
V_28 = V_2 & V_40 ;
if ( V_28 > 49 )
V_28 = 49 ;
return V_28 ;
}
static int F_23 ( struct V_10 * V_11 ,
unsigned V_28 )
{
struct V_12 * V_13 = F_9 ( V_11 ) ;
int V_14 = F_10 ( V_11 ) ;
unsigned int V_2 = 0 ;
unsigned int V_4 ;
V_4 = V_15 [ V_14 ] . V_31 ;
V_2 = V_28 ;
F_7 ( V_13 -> V_1 , V_4 , V_2 ) ;
return 0 ;
}
static int F_24 ( struct V_10 * V_34 ,
int V_35 , int V_36 )
{
int V_37 , V_38 ;
V_37 = ( ( V_35 - 900000 ) / 50000 ) + 1 ;
if ( V_37 < 0 )
return V_37 ;
V_38 = F_21 ( V_34 , V_37 ) ;
if ( V_38 < V_35 || V_38 > V_36 )
return - V_27 ;
return V_37 ;
}
static int F_25 ( struct V_1 * V_1 , int V_14 ,
struct V_41 * V_42 )
{
unsigned int V_2 ;
unsigned int V_4 ;
int V_37 ;
V_4 = V_15 [ V_14 ] . V_16 ;
V_37 = F_1 ( V_1 , V_4 , & V_2 ) ;
if ( V_37 )
return V_37 ;
if ( V_14 != V_43 ) {
if ( V_42 -> V_44 )
V_2 |= V_45 ;
if ( V_42 -> V_46 )
V_2 |= V_47 ;
if ( V_42 -> V_48 ) {
V_2 &= ~ V_49 ;
V_2 |= V_42 -> V_48 <<
V_50 ;
}
} else {
if ( V_42 -> V_48 ) {
V_2 &= ~ V_51 ;
V_2 |= V_42 -> V_48 <<
V_52 ;
}
}
V_37 = F_4 ( V_1 , V_4 , V_2 ) ;
if ( V_37 )
return V_37 ;
if ( V_15 [ V_14 ] . V_53 && V_42 -> V_54 ) {
V_4 = V_15 [ V_14 ] . V_53 ;
V_2 = V_42 -> V_54 & V_55 ;
V_37 = F_4 ( V_1 , V_4 , V_2 ) ;
if ( V_37 )
return V_37 ;
}
if ( V_15 [ V_14 ] . V_31 && V_42 -> V_56 ) {
V_4 = V_15 [ V_14 ] . V_31 ;
V_2 = V_42 -> V_56 ;
V_37 = F_4 ( V_1 , V_4 , V_2 ) ;
if ( V_37 )
return V_37 ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_1 , int V_14 ,
struct V_41 * V_42 )
{
unsigned int V_2 ;
unsigned int V_4 ;
int V_37 ;
V_4 = V_15 [ V_14 ] . V_16 ;
V_37 = F_1 ( V_1 , V_4 , & V_2 ) ;
if ( V_37 )
return V_37 ;
if ( V_42 -> V_44 )
V_2 |= V_57 ;
if ( V_42 -> V_48 )
V_2 |= V_58 ;
V_37 = F_4 ( V_1 , V_4 , V_2 ) ;
if ( V_37 )
return V_37 ;
return 0 ;
}
static T_1 int F_27 ( struct V_59 * V_60 )
{
struct V_1 * V_1 = F_28 ( V_60 -> V_11 . V_61 ) ;
struct V_62 * V_63 = V_60 -> V_11 . V_64 ;
struct V_10 * V_34 ;
struct V_65 V_66 = { } ;
struct V_12 * V_13 ;
struct V_41 * V_42 ;
int V_14 = 0 , V_37 ;
unsigned int V_4 , V_2 ;
if ( ! V_63 )
return - V_27 ;
if ( ! V_63 -> V_67 )
return - V_27 ;
V_13 = F_29 ( & V_60 -> V_11 , sizeof( * V_13 ) , V_68 ) ;
if ( ! V_13 )
return - V_69 ;
V_13 -> V_11 = & V_60 -> V_11 ;
V_13 -> V_1 = V_1 ;
V_1 -> V_13 = V_13 ;
F_30 ( V_60 , V_13 ) ;
V_37 = F_1 ( V_1 , V_70 , & V_2 ) ;
if ( V_37 )
goto V_71;
if ( V_2 & V_72 )
V_13 -> V_73 = 1 ;
if ( V_2 & V_74 )
V_13 -> V_75 = 1 ;
V_66 . V_6 = V_1 -> V_6 [ V_7 ] ;
V_66 . V_11 = & V_60 -> V_11 ;
V_66 . V_76 = V_13 ;
for ( V_14 = 0 ; V_14 < V_77 ; V_14 ++ ) {
switch ( V_14 ) {
case V_78 :
case V_79 :
if ( V_13 -> V_73 )
continue;
break;
case V_80 :
if ( ! V_13 -> V_73 )
continue;
break;
case V_81 :
case V_82 :
if ( V_13 -> V_75 )
continue;
break;
case V_83 :
if ( ! V_13 -> V_75 )
continue;
}
V_13 -> V_84 [ V_14 ] . V_85 = V_15 [ V_14 ] . V_85 ;
V_13 -> V_84 [ V_14 ] . V_14 = V_14 ;
if ( V_14 != V_43 ) {
V_13 -> V_84 [ V_14 ] . V_86 = & V_87 ;
V_13 -> V_84 [ V_14 ] . V_88 = V_89 ;
} else {
V_13 -> V_84 [ V_14 ] . V_88 = V_90 ;
V_13 -> V_84 [ V_14 ] . V_86 = & V_91 ;
V_13 -> V_84 [ V_14 ] . V_92 = V_93 ;
V_13 -> V_84 [ V_14 ] . V_94 = V_95 ;
V_13 -> V_84 [ V_14 ] . V_96 =
F_2 ( V_5 ,
V_97 ) ;
V_13 -> V_84 [ V_14 ] . V_98 = V_99 ;
}
V_13 -> V_84 [ V_14 ] . type = V_100 ;
V_13 -> V_84 [ V_14 ] . V_101 = V_102 ;
if ( V_63 && V_63 -> V_42 ) {
V_42 = V_63 -> V_42 [ V_14 ] ;
if ( V_42 ) {
V_37 = F_25 ( V_1 , V_14 , V_42 ) ;
if ( V_37 )
goto V_71;
}
}
if ( V_14 != V_43 ) {
V_4 = V_15 [ V_14 ] . V_31 ;
V_37 = F_1 ( V_13 -> V_1 , V_4 , & V_2 ) ;
if ( V_37 )
goto V_71;
if ( V_2 & V_33 )
V_13 -> V_30 [ V_14 ] = 1 ;
}
if ( V_63 && V_63 -> V_67 )
V_66 . V_103 = V_63 -> V_67 [ V_14 ] ;
else
V_66 . V_103 = NULL ;
V_34 = F_31 ( & V_13 -> V_84 [ V_14 ] , & V_66 ) ;
if ( F_32 ( V_34 ) ) {
F_33 ( & V_60 -> V_11 ,
L_1 ,
V_60 -> V_85 ) ;
V_37 = F_34 ( V_34 ) ;
goto V_71;
}
V_13 -> V_34 [ V_14 ] = V_34 ;
}
for (; V_14 < V_104 ; V_14 ++ ) {
V_13 -> V_84 [ V_14 ] . V_85 = V_15 [ V_14 ] . V_85 ;
V_13 -> V_84 [ V_14 ] . V_14 = V_14 ;
V_13 -> V_84 [ V_14 ] . V_88 = V_105 ;
V_13 -> V_84 [ V_14 ] . V_86 = & V_106 ;
V_13 -> V_84 [ V_14 ] . type = V_100 ;
V_13 -> V_84 [ V_14 ] . V_101 = V_102 ;
V_13 -> V_84 [ V_14 ] . V_96 = F_2 ( V_9 ,
V_15 [ V_14 ] . V_16 ) ;
V_13 -> V_84 [ V_14 ] . V_98 = V_107 ;
if ( V_63 && V_63 -> V_67 )
V_66 . V_103 = V_63 -> V_67 [ V_14 ] ;
else
V_66 . V_103 = NULL ;
V_34 = F_31 ( & V_13 -> V_84 [ V_14 ] , & V_66 ) ;
if ( F_32 ( V_34 ) ) {
F_33 ( & V_60 -> V_11 ,
L_1 ,
V_60 -> V_85 ) ;
V_37 = F_34 ( V_34 ) ;
goto V_71;
}
V_13 -> V_34 [ V_14 ] = V_34 ;
if ( V_63 -> V_42 ) {
V_42 = V_63 -> V_42 [ V_14 ] ;
if ( V_42 ) {
V_37 = F_26 ( V_1 , V_14 , V_42 ) ;
if ( V_37 )
goto V_71;
}
}
}
return 0 ;
V_71:
while ( -- V_14 >= 0 )
F_35 ( V_13 -> V_34 [ V_14 ] ) ;
return V_37 ;
}
static int T_2 F_36 ( struct V_59 * V_60 )
{
struct V_12 * V_13 = F_37 ( V_60 ) ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_104 ; V_14 ++ )
F_35 ( V_13 -> V_34 [ V_14 ] ) ;
return 0 ;
}
static int T_3 F_38 ( void )
{
return F_39 ( & V_108 ) ;
}
static void T_4 F_40 ( void )
{
F_41 ( & V_108 ) ;
}
