static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
V_4 = F_2 ( V_2 , V_5 , V_3 ) ;
return V_4 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 * V_6 )
{
T_2 V_7 ;
V_7 = F_4 ( V_2 , V_8 ) ;
if ( V_7 & V_9 )
* V_6 = V_10 ;
else
* V_6 = V_11 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_6 )
{
int V_4 ;
T_2 V_7 ;
V_7 = F_4 ( V_2 , V_12 ) ;
if ( ( V_6 == V_11 ) || ( V_6 == V_10 ) ) {
V_7 |= ( V_13 |
V_14 |
V_15 ) ;
} else {
V_7 &= ~ ( V_13 |
V_14 |
V_15 ) ;
}
V_4 = F_2 ( V_2 , V_12 , V_7 ) ;
if ( V_4 != 0 )
return V_4 ;
V_4 = F_1 ( V_2 , V_16 ) ;
if ( V_4 != 0 )
return V_4 ;
V_7 = F_4 ( V_2 , V_17 ) ;
V_7 &= ~ ( V_18 ) ;
if ( V_6 == V_11 )
V_7 |= V_19 ;
else if ( V_6 == V_10 )
V_7 |= V_20 ;
V_4 = F_2 ( V_2 , V_17 , V_7 ) ;
if ( V_4 != 0 )
return V_4 ;
V_4 = F_1 ( V_2 , V_21 ) ;
if ( V_4 != 0 )
return V_4 ;
return F_6 ( V_2 ) ;
}
static int F_7 ( struct V_1 * V_2 , T_1 * V_22 )
{
int V_4 ;
T_2 V_7 ;
V_4 = F_1 ( V_2 , V_16 ) ;
if ( V_4 != 0 )
goto V_23;
V_7 = F_4 ( V_2 , V_24 ) ;
V_7 &= V_25 ;
if ( ! ( V_7 & V_26 ) )
* V_22 = V_27 ;
else
* V_22 = ( ( V_7 & ~ V_26 ) >> V_28 ) + 2 ;
V_4 = F_1 ( V_2 , V_21 ) ;
V_23:
return V_4 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_22 )
{
int V_4 ;
T_2 V_7 ;
if ( V_22 == V_29 ) {
V_22 = ( ( 1 << V_28 ) | V_26 ) ;
} else if ( V_22 > V_30 || V_22 == 1 ) {
F_9 ( V_2 , L_1 ) ;
return - V_31 ;
} else if ( V_22 ) {
V_22 = ( ( ( V_22 - 2 ) << V_28 ) | V_26 ) ;
}
V_4 = F_1 ( V_2 , V_16 ) ;
if ( V_4 != 0 )
goto V_23;
V_7 = F_4 ( V_2 , V_24 ) ;
V_7 &= ~ ( V_25 ) ;
V_7 |= V_22 ;
V_4 = F_2 ( V_2 , V_24 , V_7 ) ;
if ( V_4 != 0 )
goto V_23;
V_4 = F_1 ( V_2 , V_21 ) ;
V_23:
return V_4 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
int V_4 ;
T_2 V_7 ;
T_1 V_34 ;
T_2 V_35 [ 3 ] = { 0 , 0 , 0 } ;
struct V_32 * V_36 = V_33 ;
T_1 * V_37 = V_2 -> V_38 -> V_39 ;
F_11 ( & V_2 -> V_40 ) ;
V_4 = F_1 ( V_2 , V_41 ) ;
if ( V_4 != 0 )
goto V_42;
if ( V_33 -> V_43 & V_44 ) {
for ( V_34 = 0 ; V_34 < F_12 ( V_35 ) ; V_34 ++ )
V_35 [ V_34 ] = V_37 [ 5 - ( V_34 * 2 + 1 ) ] << 8 |
V_37 [ 5 - V_34 * 2 ] ;
F_2 ( V_2 , V_45 , V_35 [ 0 ] ) ;
F_2 ( V_2 , V_46 , V_35 [ 1 ] ) ;
F_2 ( V_2 , V_47 , V_35 [ 2 ] ) ;
} else {
F_2 ( V_2 , V_45 , 0 ) ;
F_2 ( V_2 , V_46 , 0 ) ;
F_2 ( V_2 , V_47 , 0 ) ;
}
if ( V_36 -> V_43 & V_48 ) {
for ( V_34 = 0 ; V_34 < F_12 ( V_35 ) ; V_34 ++ )
V_35 [ V_34 ] = V_36 -> V_49 [ 5 - ( V_34 * 2 + 1 ) ] << 8 |
V_36 -> V_49 [ 5 - V_34 * 2 ] ;
F_2 ( V_2 , V_50 , V_35 [ 0 ] ) ;
F_2 ( V_2 , V_51 , V_35 [ 1 ] ) ;
F_2 ( V_2 , V_52 , V_35 [ 2 ] ) ;
} else {
F_2 ( V_2 , V_50 , 0 ) ;
F_2 ( V_2 , V_51 , 0 ) ;
F_2 ( V_2 , V_52 , 0 ) ;
}
V_7 = F_4 ( V_2 , V_53 ) ;
if ( V_36 -> V_43 & V_48 )
V_7 |= V_54 ;
else
V_7 &= ~ V_54 ;
F_2 ( V_2 , V_53 , V_7 ) ;
V_4 = F_1 ( V_2 , V_21 ) ;
if ( V_4 != 0 )
goto V_42;
if ( V_33 -> V_43 & V_44 ) {
V_7 = F_4 ( V_2 , V_55 ) ;
V_7 |= V_56 ;
V_4 = F_2 ( V_2 , V_55 , V_7 ) ;
if ( V_4 != 0 )
goto V_42;
} else {
V_7 = F_4 ( V_2 , V_55 ) ;
V_7 &= ( ~ V_56 ) ;
V_4 = F_2 ( V_2 , V_55 , V_7 ) ;
if ( V_4 != 0 )
goto V_42;
}
V_7 = F_4 ( V_2 , V_57 ) ;
V_42:
F_13 ( & V_2 -> V_40 ) ;
return V_4 ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
int V_4 ;
T_2 V_7 ;
T_1 V_34 ;
T_2 V_35 [ 3 ] = { 0 , 0 , 0 } ;
struct V_32 * V_36 = V_33 ;
F_11 ( & V_2 -> V_40 ) ;
V_4 = F_1 ( V_2 , V_41 ) ;
if ( V_4 != 0 )
goto V_42;
V_7 = F_4 ( V_2 , V_53 ) ;
if ( V_7 & V_54 )
V_36 -> V_43 |= V_48 ;
if ( V_36 -> V_43 & V_48 ) {
V_35 [ 0 ] = F_4 ( V_2 , V_50 ) ;
V_35 [ 1 ] = F_4 ( V_2 , V_51 ) ;
V_35 [ 2 ] = F_4 ( V_2 , V_52 ) ;
for ( V_34 = 0 ; V_34 < F_12 ( V_35 ) ; V_34 ++ ) {
V_36 -> V_49 [ 5 - V_34 * 2 ] = V_35 [ V_34 ] & 0x00ff ;
V_36 -> V_49 [ 5 - ( V_34 * 2 + 1 ) ] = ( V_35 [ V_34 ] & 0xff00 )
>> 8 ;
}
}
V_4 = F_1 ( V_2 , V_21 ) ;
V_42:
F_13 ( & V_2 -> V_40 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
T_1 V_58 ;
T_2 V_59 ;
int V_4 , V_34 , V_60 ;
struct V_61 * V_62 = & V_2 -> V_63 . V_62 ;
struct V_64 * V_65 = V_62 -> V_65 ;
T_1 V_66 = F_12 ( V_67 [ 0 ] . V_68 ) ;
if ( ! V_65 )
return - V_69 ;
V_4 = F_16 ( V_65 , L_2 , & V_59 ) ;
if ( V_4 != 0 )
V_59 = V_70 ;
V_4 = F_17 ( V_65 , L_3 , & V_58 ) ;
if ( V_4 != 0 )
V_58 = 0 ;
for ( V_34 = 0 ; V_34 < F_12 ( V_67 ) ; V_34 ++ )
if ( V_67 [ V_34 ] . V_71 == V_59 )
for ( V_60 = 0 ; V_60 < V_66 ; V_60 ++ )
if ( V_67 [ V_34 ] . V_68 [ V_60 ] == V_58 )
return ( V_66 - V_60 - 1 ) ;
return - V_72 ;
}
static int F_15 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , T_1 V_73 )
{
int V_4 ;
T_2 V_7 ;
F_11 ( & V_2 -> V_40 ) ;
V_4 = F_1 ( V_2 , V_41 ) ;
if ( V_4 != 0 )
goto V_42;
V_7 = F_4 ( V_2 , V_53 ) ;
V_7 &= ~ ( V_74 ) ;
V_7 |= ( V_73 << V_75 ) ;
V_4 = F_2 ( V_2 , V_53 , V_7 ) ;
if ( V_4 != 0 )
goto V_42;
V_4 = F_1 ( V_2 , V_21 ) ;
V_42:
F_13 ( & V_2 -> V_40 ) ;
return V_4 ;
}
static int F_19 ( struct V_1 * V_2 ,
T_3 V_76 )
{
int V_4 ;
T_2 V_7 ;
F_11 ( & V_2 -> V_40 ) ;
V_7 = F_4 ( V_2 , V_77 ) ;
V_7 &= ~ ( V_78 ) ;
switch ( V_76 ) {
case V_79 :
V_7 |= ( V_80 << V_81 ) ;
break;
case V_82 :
V_7 |= ( V_83 << V_81 ) ;
break;
case V_84 :
case V_85 :
V_7 |= ( V_86 << V_81 ) ;
break;
default:
V_4 = - V_72 ;
goto V_42;
}
V_4 = F_2 ( V_2 , V_77 , V_7 ) ;
if ( V_4 != 0 )
goto V_42;
V_4 = F_20 ( V_2 ) ;
V_42:
F_13 ( & V_2 -> V_40 ) ;
return V_4 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_4 ;
T_2 V_7 ;
V_2 -> V_87 = V_88 ;
F_11 ( & V_2 -> V_40 ) ;
V_4 = F_1 ( V_2 , V_41 ) ;
if ( V_4 != 0 )
goto V_42;
V_7 = F_4 ( V_2 , V_89 ) ;
V_7 &= ~ ( V_90 ) ;
V_7 |= ( V_91 << V_92 ) ;
F_2 ( V_2 , V_89 , V_7 ) ;
V_4 = F_1 ( V_2 , V_21 ) ;
V_42:
F_13 ( & V_2 -> V_40 ) ;
return V_4 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_93 * V_94 , void * V_95 )
{
switch ( V_94 -> V_96 ) {
case V_97 :
return F_7 ( V_2 , ( T_1 * ) V_95 ) ;
default:
return - V_72 ;
}
}
static int F_23 ( struct V_1 * V_2 ,
struct V_93 * V_94 ,
const void * V_95 )
{
switch ( V_94 -> V_96 ) {
case V_97 :
return F_8 ( V_2 , * ( T_1 * ) V_95 ) ;
default:
return - V_72 ;
}
}
static int F_24 ( struct V_1 * V_2 )
{
int V_4 ;
struct V_98 * V_99 = V_2 -> V_100 ;
V_4 = F_21 ( V_2 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_19 ( V_2 , V_2 -> V_76 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_18 ( V_2 , V_99 -> V_101 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_25 ( V_2 ) ;
return V_4 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_4 = 0 ;
if ( V_2 -> V_102 == V_103 )
V_4 = F_4 ( V_2 , V_57 ) ;
return ( V_4 < 0 ) ? V_4 : 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_4 ;
if ( V_2 -> V_102 == V_103 ) {
V_4 = F_2 ( V_2 , V_55 ,
V_104 ) ;
} else {
V_4 = F_2 ( V_2 , V_55 , 0 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_4 ( V_2 , V_57 ) ;
}
return V_4 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_4 ;
V_4 = F_5 ( V_2 , V_2 -> V_87 ) ;
if ( V_4 < 0 )
return V_4 ;
return F_29 ( V_2 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
int V_4 ;
V_4 = F_3 ( V_2 , & V_2 -> V_6 ) ;
if ( V_4 < 0 )
return V_4 ;
return F_31 ( V_2 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_101 ;
struct V_98 * V_99 ;
V_101 = F_15 ( V_2 ) ;
if ( V_101 < 0 )
return V_101 ;
V_99 = F_33 ( & V_2 -> V_63 . V_62 , sizeof( * V_99 ) , V_105 ) ;
if ( ! V_99 )
return - V_106 ;
V_2 -> V_100 = V_99 ;
V_99 -> V_101 = V_101 ;
return 0 ;
}
