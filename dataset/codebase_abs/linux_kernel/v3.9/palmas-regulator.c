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
if ( V_13 -> V_30 [ V_14 ] )
V_29 = 2 ;
if ( V_28 == 0 )
return 0 ;
else if ( V_28 < 6 )
return 500000 * V_29 ;
else
return ( 490000 + ( ( V_28 - 5 ) * 10000 ) ) * V_29 ;
}
static int F_16 ( struct V_10 * V_31 ,
int V_32 , int V_33 )
{
struct V_12 * V_13 = F_9 ( V_31 ) ;
int V_14 = F_10 ( V_31 ) ;
int V_34 , V_35 ;
if ( V_32 == 0 )
return 0 ;
if ( V_13 -> V_30 [ V_14 ] ) {
if ( V_32 < 1000000 )
V_32 = 1000000 ;
V_34 = F_17 ( V_32 - 1000000 , 20000 ) + 6 ;
} else {
if ( V_32 < 500000 )
V_32 = 500000 ;
V_34 = F_17 ( V_32 - 500000 , 10000 ) + 6 ;
}
V_35 = F_15 ( V_31 , V_34 ) ;
if ( V_35 < V_32 || V_35 > V_33 )
return - V_27 ;
return V_34 ;
}
static int F_18 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_9 ( V_11 ) ;
int V_14 = F_10 ( V_11 ) ;
unsigned int V_2 ;
F_6 ( V_13 -> V_1 , V_15 [ V_14 ] . V_16 , & V_2 ) ;
V_2 &= V_36 ;
return ! ! ( V_2 ) ;
}
static int F_19 ( struct V_1 * V_1 , int V_14 ,
struct V_37 * V_38 )
{
unsigned int V_2 ;
unsigned int V_4 ;
int V_34 ;
V_4 = V_15 [ V_14 ] . V_16 ;
V_34 = F_1 ( V_1 , V_4 , & V_2 ) ;
if ( V_34 )
return V_34 ;
switch ( V_14 ) {
case V_39 :
if ( V_38 -> V_40 ) {
V_2 &= ~ V_41 ;
V_2 |= V_38 -> V_40 <<
V_42 ;
}
break;
default:
if ( V_38 -> V_43 )
V_2 |= V_44 ;
if ( V_38 -> V_45 )
V_2 |= V_46 ;
if ( V_38 -> V_40 ) {
V_2 &= ~ V_47 ;
V_2 |= V_38 -> V_40 <<
V_48 ;
}
}
V_34 = F_4 ( V_1 , V_4 , V_2 ) ;
if ( V_34 )
return V_34 ;
if ( V_15 [ V_14 ] . V_49 && V_38 -> V_50 ) {
V_4 = V_15 [ V_14 ] . V_49 ;
V_2 = V_38 -> V_50 & V_51 ;
V_34 = F_4 ( V_1 , V_4 , V_2 ) ;
if ( V_34 )
return V_34 ;
}
if ( V_15 [ V_14 ] . V_52 && V_38 -> V_53 ) {
V_4 = V_15 [ V_14 ] . V_52 ;
V_2 = V_38 -> V_53 ;
V_34 = F_4 ( V_1 , V_4 , V_2 ) ;
if ( V_34 )
return V_34 ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_1 , int V_14 ,
struct V_37 * V_38 )
{
unsigned int V_2 ;
unsigned int V_4 ;
int V_34 ;
V_4 = V_15 [ V_14 ] . V_16 ;
V_34 = F_6 ( V_1 , V_4 , & V_2 ) ;
if ( V_34 )
return V_34 ;
if ( V_38 -> V_43 )
V_2 |= V_54 ;
if ( V_38 -> V_40 )
V_2 |= V_55 ;
V_34 = F_7 ( V_1 , V_4 , V_2 ) ;
if ( V_34 )
return V_34 ;
return 0 ;
}
static void F_21 ( struct V_56 * V_11 ,
struct V_57 * V_58 ,
struct V_59 * V_60 )
{
struct V_57 * V_61 ;
T_1 V_62 ;
int V_63 , V_34 ;
V_58 = F_22 ( V_58 ) ;
V_61 = F_23 ( V_58 , L_1 ) ;
if ( ! V_61 ) {
F_24 ( V_11 , L_2 ) ;
return;
}
V_34 = F_25 ( V_11 , V_61 , V_64 ,
V_65 ) ;
F_26 ( V_61 ) ;
if ( V_34 < 0 ) {
F_27 ( V_11 , L_3 , V_34 ) ;
return;
}
for ( V_63 = 0 ; V_63 < V_65 ; V_63 ++ ) {
if ( ! V_64 [ V_63 ] . V_66 ||
! V_64 [ V_63 ] . V_67 )
continue;
V_60 -> V_68 [ V_63 ] = V_64 [ V_63 ] . V_66 ;
V_60 -> V_38 [ V_63 ] = F_28 ( V_11 ,
sizeof( struct V_37 ) , V_69 ) ;
V_34 = F_29 ( V_64 [ V_63 ] . V_67 ,
L_4 , & V_62 ) ;
if ( ! V_34 )
V_60 -> V_38 [ V_63 ] -> V_43 = V_62 ;
V_34 = F_29 ( V_64 [ V_63 ] . V_67 ,
L_5 , & V_62 ) ;
if ( ! V_34 )
V_60 -> V_38 [ V_63 ] -> V_45 = V_62 ;
V_34 = F_29 ( V_64 [ V_63 ] . V_67 ,
L_6 , & V_62 ) ;
if ( ! V_34 )
V_60 -> V_38 [ V_63 ] -> V_40 = V_62 ;
V_34 = F_29 ( V_64 [ V_63 ] . V_67 ,
L_7 , & V_62 ) ;
if ( ! V_34 )
V_60 -> V_38 [ V_63 ] -> V_50 = V_62 ;
V_34 = F_29 ( V_64 [ V_63 ] . V_67 ,
L_8 , & V_62 ) ;
if ( ! V_34 )
V_60 -> V_38 [ V_63 ] -> V_53 = V_62 ;
}
V_34 = F_29 ( V_58 , L_9 , & V_62 ) ;
if ( ! V_34 )
V_60 -> V_70 = V_62 ;
}
static int F_30 ( struct V_71 * V_72 )
{
struct V_1 * V_1 = F_31 ( V_72 -> V_11 . V_73 ) ;
struct V_59 * V_60 = V_72 -> V_11 . V_74 ;
struct V_57 * V_58 = V_72 -> V_11 . V_67 ;
struct V_10 * V_31 ;
struct V_75 V_76 = { } ;
struct V_12 * V_13 ;
struct V_37 * V_38 ;
int V_14 = 0 , V_34 ;
unsigned int V_4 , V_2 ;
if ( V_58 && ! V_60 ) {
V_60 = F_28 ( & V_72 -> V_11 , sizeof( * V_60 ) , V_69 ) ;
if ( ! V_60 )
return - V_77 ;
F_21 ( & V_72 -> V_11 , V_58 , V_60 ) ;
}
V_13 = F_28 ( & V_72 -> V_11 , sizeof( * V_13 ) , V_69 ) ;
if ( ! V_13 )
return - V_77 ;
V_13 -> V_11 = & V_72 -> V_11 ;
V_13 -> V_1 = V_1 ;
V_1 -> V_13 = V_13 ;
F_32 ( V_72 , V_13 ) ;
V_34 = F_1 ( V_1 , V_78 , & V_2 ) ;
if ( V_34 )
return V_34 ;
if ( V_2 & V_79 )
V_13 -> V_80 = 1 ;
if ( V_2 & V_81 )
V_13 -> V_82 = 1 ;
V_76 . V_6 = V_1 -> V_6 [ V_7 ] ;
V_76 . V_11 = & V_72 -> V_11 ;
V_76 . V_83 = V_13 ;
for ( V_14 = 0 ; V_14 < V_84 ; V_14 ++ ) {
switch ( V_14 ) {
case V_85 :
case V_86 :
if ( V_13 -> V_80 )
continue;
break;
case V_87 :
if ( ! V_13 -> V_80 )
continue;
break;
case V_88 :
case V_89 :
if ( V_13 -> V_82 )
continue;
break;
case V_90 :
if ( ! V_13 -> V_82 )
continue;
}
if ( V_60 && V_60 -> V_38 [ V_14 ] ) {
V_38 = V_60 -> V_38 [ V_14 ] ;
V_34 = F_19 ( V_1 , V_14 , V_38 ) ;
if ( V_34 )
goto V_91;
}
V_13 -> V_92 [ V_14 ] . V_93 = V_15 [ V_14 ] . V_93 ;
V_13 -> V_92 [ V_14 ] . V_14 = V_14 ;
switch ( V_14 ) {
case V_39 :
V_13 -> V_92 [ V_14 ] . V_94 = V_95 ;
V_13 -> V_92 [ V_14 ] . V_96 = & V_97 ;
V_13 -> V_92 [ V_14 ] . V_98 =
F_2 ( V_5 ,
V_99 ) ;
V_13 -> V_92 [ V_14 ] . V_100 = V_101 ;
V_13 -> V_92 [ V_14 ] . V_102 =
F_2 ( V_5 ,
V_103 ) ;
V_13 -> V_92 [ V_14 ] . V_104 = V_105 ;
V_13 -> V_92 [ V_14 ] . V_32 = 3750000 ;
V_13 -> V_92 [ V_14 ] . V_106 = 1250000 ;
break;
default:
V_4 = V_15 [ V_14 ] . V_52 ;
V_34 = F_1 ( V_13 -> V_1 , V_4 , & V_2 ) ;
if ( V_34 )
goto V_91;
if ( V_2 & V_107 )
V_13 -> V_30 [ V_14 ] = 1 ;
V_13 -> V_92 [ V_14 ] . V_96 = & V_108 ;
V_13 -> V_92 [ V_14 ] . V_94 = V_109 ;
V_13 -> V_92 [ V_14 ] . V_98 =
F_2 ( V_5 ,
V_15 [ V_14 ] . V_52 ) ;
V_13 -> V_92 [ V_14 ] . V_100 =
V_110 ;
}
V_13 -> V_92 [ V_14 ] . type = V_111 ;
V_13 -> V_92 [ V_14 ] . V_112 = V_113 ;
if ( V_60 )
V_76 . V_66 = V_60 -> V_68 [ V_14 ] ;
else
V_76 . V_66 = NULL ;
V_76 . V_67 = V_64 [ V_14 ] . V_67 ;
V_31 = F_33 ( & V_13 -> V_92 [ V_14 ] , & V_76 ) ;
if ( F_34 ( V_31 ) ) {
F_27 ( & V_72 -> V_11 ,
L_10 ,
V_72 -> V_93 ) ;
V_34 = F_35 ( V_31 ) ;
goto V_91;
}
V_13 -> V_31 [ V_14 ] = V_31 ;
}
for (; V_14 < V_65 ; V_14 ++ ) {
V_13 -> V_92 [ V_14 ] . V_93 = V_15 [ V_14 ] . V_93 ;
V_13 -> V_92 [ V_14 ] . V_14 = V_14 ;
V_13 -> V_92 [ V_14 ] . V_94 = V_114 ;
V_13 -> V_92 [ V_14 ] . V_96 = & V_115 ;
V_13 -> V_92 [ V_14 ] . type = V_111 ;
V_13 -> V_92 [ V_14 ] . V_112 = V_113 ;
V_13 -> V_92 [ V_14 ] . V_32 = 900000 ;
V_13 -> V_92 [ V_14 ] . V_106 = 50000 ;
V_13 -> V_92 [ V_14 ] . V_116 = 1 ;
V_13 -> V_92 [ V_14 ] . V_98 = F_2 ( V_9 ,
V_15 [ V_14 ] . V_52 ) ;
V_13 -> V_92 [ V_14 ] . V_100 = V_117 ;
V_13 -> V_92 [ V_14 ] . V_102 = F_2 ( V_9 ,
V_15 [ V_14 ] . V_16 ) ;
V_13 -> V_92 [ V_14 ] . V_104 = V_118 ;
if ( V_60 )
V_76 . V_66 = V_60 -> V_68 [ V_14 ] ;
else
V_76 . V_66 = NULL ;
V_76 . V_67 = V_64 [ V_14 ] . V_67 ;
V_31 = F_33 ( & V_13 -> V_92 [ V_14 ] , & V_76 ) ;
if ( F_34 ( V_31 ) ) {
F_27 ( & V_72 -> V_11 ,
L_10 ,
V_72 -> V_93 ) ;
V_34 = F_35 ( V_31 ) ;
goto V_91;
}
V_13 -> V_31 [ V_14 ] = V_31 ;
if ( V_60 ) {
V_38 = V_60 -> V_38 [ V_14 ] ;
if ( V_38 ) {
V_34 = F_20 ( V_1 , V_14 , V_38 ) ;
if ( V_34 ) {
F_36 ( V_13 -> V_31 [ V_14 ] ) ;
goto V_91;
}
}
}
}
return 0 ;
V_91:
while ( -- V_14 >= 0 )
F_36 ( V_13 -> V_31 [ V_14 ] ) ;
return V_34 ;
}
static int F_37 ( struct V_71 * V_72 )
{
struct V_12 * V_13 = F_38 ( V_72 ) ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_65 ; V_14 ++ )
F_36 ( V_13 -> V_31 [ V_14 ] ) ;
return 0 ;
}
static int T_2 F_39 ( void )
{
return F_40 ( & V_119 ) ;
}
static void T_3 F_41 ( void )
{
F_42 ( & V_119 ) ;
}
