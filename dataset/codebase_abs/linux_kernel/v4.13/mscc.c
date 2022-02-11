static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
V_4 = F_2 ( V_2 , V_5 , V_3 ) ;
return V_4 ;
}
static int F_3 ( struct V_1 * V_2 ,
T_1 V_6 ,
T_1 V_7 )
{
int V_4 ;
T_2 V_8 ;
F_4 ( & V_2 -> V_9 ) ;
V_8 = F_5 ( V_2 , V_10 ) ;
if ( V_6 ) {
V_8 &= ~ V_11 ;
V_8 |= ( ( ( T_2 ) V_7 << V_12 ) &
V_11 ) ;
} else {
V_8 &= ~ V_13 ;
V_8 |= ( ( T_2 ) V_7 & V_13 ) ;
}
V_4 = F_2 ( V_2 , V_10 , V_8 ) ;
F_6 ( & V_2 -> V_9 ) ;
return V_4 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 * V_14 )
{
T_2 V_8 ;
V_8 = F_5 ( V_2 , V_15 ) ;
if ( V_8 & V_16 )
* V_14 = V_17 ;
else
* V_14 = V_18 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_14 )
{
int V_4 ;
T_2 V_8 ;
V_8 = F_5 ( V_2 , V_19 ) ;
if ( ( V_14 == V_18 ) || ( V_14 == V_17 ) ) {
V_8 |= ( V_20 |
V_21 |
V_22 ) ;
} else {
V_8 &= ~ ( V_20 |
V_21 |
V_22 ) ;
}
V_4 = F_2 ( V_2 , V_19 , V_8 ) ;
if ( V_4 != 0 )
return V_4 ;
V_4 = F_1 ( V_2 , V_23 ) ;
if ( V_4 != 0 )
return V_4 ;
V_8 = F_5 ( V_2 , V_24 ) ;
V_8 &= ~ ( V_25 ) ;
if ( V_14 == V_18 )
V_8 |= V_26 ;
else if ( V_14 == V_17 )
V_8 |= V_27 ;
V_4 = F_2 ( V_2 , V_24 , V_8 ) ;
if ( V_4 != 0 )
return V_4 ;
V_4 = F_1 ( V_2 , V_28 ) ;
if ( V_4 != 0 )
return V_4 ;
return F_9 ( V_2 ) ;
}
static int F_10 ( struct V_1 * V_2 , T_1 * V_29 )
{
int V_4 ;
T_2 V_8 ;
V_4 = F_1 ( V_2 , V_23 ) ;
if ( V_4 != 0 )
goto V_30;
V_8 = F_5 ( V_2 , V_31 ) ;
V_8 &= V_32 ;
if ( ! ( V_8 & V_33 ) )
* V_29 = V_34 ;
else
* V_29 = ( ( V_8 & ~ V_33 ) >> V_35 ) + 2 ;
V_4 = F_1 ( V_2 , V_28 ) ;
V_30:
return V_4 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_29 )
{
int V_4 ;
T_2 V_8 ;
if ( V_29 == V_36 ) {
V_29 = ( ( 1 << V_35 ) | V_33 ) ;
} else if ( V_29 > V_37 || V_29 == 1 ) {
F_12 ( V_2 , L_1 ) ;
return - V_38 ;
} else if ( V_29 ) {
V_29 = ( ( ( V_29 - 2 ) << V_35 ) | V_33 ) ;
}
V_4 = F_1 ( V_2 , V_23 ) ;
if ( V_4 != 0 )
goto V_30;
V_8 = F_5 ( V_2 , V_31 ) ;
V_8 &= ~ ( V_32 ) ;
V_8 |= V_29 ;
V_4 = F_2 ( V_2 , V_31 , V_8 ) ;
if ( V_4 != 0 )
goto V_30;
V_4 = F_1 ( V_2 , V_28 ) ;
V_30:
return V_4 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_39 * V_40 )
{
int V_4 ;
T_2 V_8 ;
T_1 V_41 ;
T_2 V_42 [ 3 ] = { 0 , 0 , 0 } ;
struct V_39 * V_43 = V_40 ;
T_1 * V_44 = V_2 -> V_45 -> V_46 ;
F_4 ( & V_2 -> V_9 ) ;
V_4 = F_1 ( V_2 , V_47 ) ;
if ( V_4 != 0 )
goto V_48;
if ( V_40 -> V_49 & V_50 ) {
for ( V_41 = 0 ; V_41 < F_14 ( V_42 ) ; V_41 ++ )
V_42 [ V_41 ] = V_44 [ 5 - ( V_41 * 2 + 1 ) ] << 8 |
V_44 [ 5 - V_41 * 2 ] ;
F_2 ( V_2 , V_51 , V_42 [ 0 ] ) ;
F_2 ( V_2 , V_52 , V_42 [ 1 ] ) ;
F_2 ( V_2 , V_53 , V_42 [ 2 ] ) ;
} else {
F_2 ( V_2 , V_51 , 0 ) ;
F_2 ( V_2 , V_52 , 0 ) ;
F_2 ( V_2 , V_53 , 0 ) ;
}
if ( V_43 -> V_49 & V_54 ) {
for ( V_41 = 0 ; V_41 < F_14 ( V_42 ) ; V_41 ++ )
V_42 [ V_41 ] = V_43 -> V_55 [ 5 - ( V_41 * 2 + 1 ) ] << 8 |
V_43 -> V_55 [ 5 - V_41 * 2 ] ;
F_2 ( V_2 , V_56 , V_42 [ 0 ] ) ;
F_2 ( V_2 , V_57 , V_42 [ 1 ] ) ;
F_2 ( V_2 , V_58 , V_42 [ 2 ] ) ;
} else {
F_2 ( V_2 , V_56 , 0 ) ;
F_2 ( V_2 , V_57 , 0 ) ;
F_2 ( V_2 , V_58 , 0 ) ;
}
V_8 = F_5 ( V_2 , V_59 ) ;
if ( V_43 -> V_49 & V_54 )
V_8 |= V_60 ;
else
V_8 &= ~ V_60 ;
F_2 ( V_2 , V_59 , V_8 ) ;
V_4 = F_1 ( V_2 , V_28 ) ;
if ( V_4 != 0 )
goto V_48;
if ( V_40 -> V_49 & V_50 ) {
V_8 = F_5 ( V_2 , V_61 ) ;
V_8 |= V_62 ;
V_4 = F_2 ( V_2 , V_61 , V_8 ) ;
if ( V_4 != 0 )
goto V_48;
} else {
V_8 = F_5 ( V_2 , V_61 ) ;
V_8 &= ( ~ V_62 ) ;
V_4 = F_2 ( V_2 , V_61 , V_8 ) ;
if ( V_4 != 0 )
goto V_48;
}
V_8 = F_5 ( V_2 , V_63 ) ;
V_48:
F_6 ( & V_2 -> V_9 ) ;
return V_4 ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_39 * V_40 )
{
int V_4 ;
T_2 V_8 ;
T_1 V_41 ;
T_2 V_42 [ 3 ] = { 0 , 0 , 0 } ;
struct V_39 * V_43 = V_40 ;
F_4 ( & V_2 -> V_9 ) ;
V_4 = F_1 ( V_2 , V_47 ) ;
if ( V_4 != 0 )
goto V_48;
V_8 = F_5 ( V_2 , V_59 ) ;
if ( V_8 & V_60 )
V_43 -> V_49 |= V_54 ;
if ( V_43 -> V_49 & V_54 ) {
V_42 [ 0 ] = F_5 ( V_2 , V_56 ) ;
V_42 [ 1 ] = F_5 ( V_2 , V_57 ) ;
V_42 [ 2 ] = F_5 ( V_2 , V_58 ) ;
for ( V_41 = 0 ; V_41 < F_14 ( V_42 ) ; V_41 ++ ) {
V_43 -> V_55 [ 5 - V_41 * 2 ] = V_42 [ V_41 ] & 0x00ff ;
V_43 -> V_55 [ 5 - ( V_41 * 2 + 1 ) ] = ( V_42 [ V_41 ] & 0xff00 )
>> 8 ;
}
}
V_4 = F_1 ( V_2 , V_28 ) ;
V_48:
F_6 ( & V_2 -> V_9 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
T_1 V_64 ;
T_2 V_65 ;
int V_4 , V_41 , V_66 ;
struct V_67 * V_68 = & V_2 -> V_69 . V_68 ;
struct V_70 * V_71 = V_68 -> V_71 ;
T_1 V_72 = F_14 ( V_73 [ 0 ] . V_74 ) ;
if ( ! V_71 )
return - V_75 ;
V_4 = F_17 ( V_71 , L_2 , & V_65 ) ;
if ( V_4 != 0 )
V_65 = V_76 ;
V_4 = F_18 ( V_71 , L_3 , & V_64 ) ;
if ( V_4 != 0 )
V_64 = 0 ;
for ( V_41 = 0 ; V_41 < F_14 ( V_73 ) ; V_41 ++ )
if ( V_73 [ V_41 ] . V_77 == V_65 )
for ( V_66 = 0 ; V_66 < V_72 ; V_66 ++ )
if ( V_73 [ V_41 ] . V_74 [ V_66 ] == V_64 )
return ( V_72 - V_66 - 1 ) ;
return - V_78 ;
}
static int F_19 ( struct V_1 * V_2 ,
char * V_79 ,
T_1 V_80 )
{
struct V_67 * V_68 = & V_2 -> V_69 . V_68 ;
struct V_70 * V_71 = V_68 -> V_71 ;
T_1 V_81 ;
int V_82 ;
if ( ! V_71 )
return - V_75 ;
V_81 = V_80 ;
V_82 = F_18 ( V_71 , V_79 , & V_81 ) ;
if ( ! V_82 && ( V_81 > 15 || V_81 == 7 || V_81 == 11 ) ) {
F_12 ( V_2 , L_4 , V_79 ) ;
return - V_78 ;
}
return V_81 ;
}
static int F_16 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
char * V_79 ,
T_1 V_80 )
{
return V_80 ;
}
static int F_20 ( struct V_1 * V_2 , T_1 V_83 )
{
int V_4 ;
T_2 V_8 ;
F_4 ( & V_2 -> V_9 ) ;
V_4 = F_1 ( V_2 , V_47 ) ;
if ( V_4 != 0 )
goto V_48;
V_8 = F_5 ( V_2 , V_59 ) ;
V_8 &= ~ ( V_84 ) ;
V_8 |= ( V_83 << V_85 ) ;
V_4 = F_2 ( V_2 , V_59 , V_8 ) ;
if ( V_4 != 0 )
goto V_48;
V_4 = F_1 ( V_2 , V_28 ) ;
V_48:
F_6 ( & V_2 -> V_9 ) ;
return V_4 ;
}
static int F_21 ( struct V_1 * V_2 ,
T_3 V_86 )
{
int V_4 ;
T_2 V_8 ;
F_4 ( & V_2 -> V_9 ) ;
V_8 = F_5 ( V_2 , V_87 ) ;
V_8 &= ~ ( V_88 ) ;
switch ( V_86 ) {
case V_89 :
V_8 |= ( V_90 << V_91 ) ;
break;
case V_92 :
V_8 |= ( V_93 << V_91 ) ;
break;
case V_94 :
case V_95 :
V_8 |= ( V_96 << V_91 ) ;
break;
default:
V_4 = - V_78 ;
goto V_48;
}
V_4 = F_2 ( V_2 , V_87 , V_8 ) ;
if ( V_4 != 0 )
goto V_48;
V_4 = F_22 ( V_2 ) ;
V_48:
F_6 ( & V_2 -> V_9 ) ;
return V_4 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_4 ;
T_2 V_8 ;
V_2 -> V_97 = V_98 ;
F_4 ( & V_2 -> V_9 ) ;
V_4 = F_1 ( V_2 , V_47 ) ;
if ( V_4 != 0 )
goto V_48;
V_8 = F_5 ( V_2 , V_99 ) ;
V_8 &= ~ ( V_100 ) ;
V_8 |= ( V_101 << V_102 ) ;
F_2 ( V_2 , V_99 , V_8 ) ;
V_4 = F_1 ( V_2 , V_28 ) ;
V_48:
F_6 ( & V_2 -> V_9 ) ;
return V_4 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_103 * V_104 , void * V_105 )
{
switch ( V_104 -> V_106 ) {
case V_107 :
return F_10 ( V_2 , ( T_1 * ) V_105 ) ;
default:
return - V_78 ;
}
}
static int F_25 ( struct V_1 * V_2 ,
struct V_103 * V_104 ,
const void * V_105 )
{
switch ( V_104 -> V_106 ) {
case V_107 :
return F_11 ( V_2 , * ( T_1 * ) V_105 ) ;
default:
return - V_78 ;
}
}
static int F_26 ( struct V_1 * V_2 )
{
int V_4 ;
struct V_108 * V_109 = V_2 -> V_110 ;
V_4 = F_23 ( V_2 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_21 ( V_2 , V_2 -> V_86 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_20 ( V_2 , V_109 -> V_111 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_3 ( V_2 , 1 , V_109 -> V_112 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_3 ( V_2 , 0 , V_109 -> V_113 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_27 ( V_2 ) ;
return V_4 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_4 = 0 ;
if ( V_2 -> V_114 == V_115 )
V_4 = F_5 ( V_2 , V_63 ) ;
return ( V_4 < 0 ) ? V_4 : 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_4 ;
if ( V_2 -> V_114 == V_115 ) {
V_4 = F_2 ( V_2 , V_61 ,
V_116 ) ;
} else {
V_4 = F_2 ( V_2 , V_61 , 0 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_5 ( V_2 , V_63 ) ;
}
return V_4 ;
}
static int F_30 ( struct V_1 * V_2 )
{
int V_4 ;
V_4 = F_8 ( V_2 , V_2 -> V_97 ) ;
if ( V_4 < 0 )
return V_4 ;
return F_31 ( V_2 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_4 ;
V_4 = F_7 ( V_2 , & V_2 -> V_14 ) ;
if ( V_4 < 0 )
return V_4 ;
return F_33 ( V_2 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_108 * V_109 ;
int V_111 ;
int V_81 ;
V_111 = F_16 ( V_2 ) ;
if ( V_111 < 0 )
return V_111 ;
V_109 = F_35 ( & V_2 -> V_69 . V_68 , sizeof( * V_109 ) , V_117 ) ;
if ( ! V_109 )
return - V_118 ;
V_2 -> V_110 = V_109 ;
V_109 -> V_111 = V_111 ;
V_81 = F_19 ( V_2 , L_5 ,
V_119 ) ;
if ( V_81 < 0 )
return V_81 ;
V_109 -> V_113 = V_81 ;
V_81 = F_19 ( V_2 , L_6 ,
V_120 ) ;
if ( V_81 < 0 )
return V_81 ;
V_109 -> V_112 = V_81 ;
return 0 ;
}
