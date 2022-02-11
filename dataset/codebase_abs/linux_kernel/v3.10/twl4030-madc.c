static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 , V_5 ;
int V_6 ;
V_6 = F_2 ( V_7 , & V_4 , V_3 + 1 ) ;
if ( V_6 ) {
F_3 ( V_2 -> V_8 , L_1 ,
V_3 + 1 ) ;
return V_6 ;
}
V_6 = F_2 ( V_7 , & V_5 , V_3 ) ;
if ( V_6 ) {
F_3 ( V_2 -> V_8 , L_2 , V_3 ) ;
return V_6 ;
}
return ( int ) ( ( ( V_4 << 8 ) | V_5 ) >> 6 ) ;
}
static int F_4 ( int V_9 )
{
T_1 V_10 ;
int V_11 , V_12 , V_13 , V_14 , V_6 ;
V_13 = ( V_9 * V_15 ) / V_16 ;
V_6 = F_2 ( V_17 , & V_10 ,
V_18 ) ;
if ( V_6 < 0 )
return V_6 ;
V_12 = ( ( V_10 & V_19 ) + 1 ) * 10 ;
V_14 = V_13 * 1000 / V_12 ;
for ( V_11 = 58 ; V_11 >= 0 ; V_11 -- ) {
int V_20 = V_21 [ V_11 ] ;
if ( ( V_20 - V_14 ) >= 0 )
break;
}
return V_11 + 1 ;
}
static int F_5 ( int V_9 )
{
int V_6 ;
T_1 V_10 ;
V_6 = F_2 ( V_17 , & V_10 ,
V_22 ) ;
if ( V_6 )
return V_6 ;
if ( V_10 & V_23 )
return ( V_9 * V_24 ) / V_25 ;
else
return ( V_9 * V_24 ) / V_26 ;
}
static int F_6 ( struct V_1 * V_2 ,
T_1 V_27 , unsigned
long V_28 , int * V_29 ,
bool V_30 )
{
int V_31 = 0 , V_32 = 0 , V_33 ;
T_1 V_3 ;
F_7 (i, &channels, TWL4030_MADC_MAX_CHANNELS) {
V_3 = V_27 + 2 * V_33 ;
V_29 [ V_33 ] = F_1 ( V_2 , V_3 ) ;
if ( V_29 [ V_33 ] < 0 ) {
F_3 ( V_2 -> V_8 ,
L_3 , V_3 ) ;
V_32 ++ ;
continue;
}
if ( V_30 ) {
V_31 ++ ;
continue;
}
switch ( V_33 ) {
case 10 :
V_29 [ V_33 ] = F_5 ( V_29 [ V_33 ] ) ;
if ( V_29 [ V_33 ] < 0 ) {
F_3 ( V_2 -> V_8 , L_4 ) ;
V_32 ++ ;
} else {
V_31 ++ ;
V_29 [ V_33 ] = V_29 [ V_33 ] - 750 ;
}
break;
case 1 :
V_29 [ V_33 ] = F_4 ( V_29 [ V_33 ] ) ;
if ( V_29 [ V_33 ] < 0 ) {
F_3 ( V_2 -> V_8 , L_5 ) ;
V_32 ++ ;
} else {
V_29 [ V_33 ] -= 3 ;
V_31 ++ ;
}
break;
default:
V_31 ++ ;
V_29 [ V_33 ] = ( V_29 [ V_33 ] * 3 * 1000 *
V_34 [ V_33 ] . V_35 )
/ ( 2 * 1023 *
V_34 [ V_33 ] . V_36 ) ;
}
}
if ( V_32 )
F_3 ( V_2 -> V_8 , L_6 , V_32 ) ;
return V_31 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_37 )
{
T_1 V_10 ;
int V_6 ;
V_6 = F_2 ( V_7 , & V_10 , V_2 -> V_38 ) ;
if ( V_6 ) {
F_3 ( V_2 -> V_8 , L_7 ,
V_2 -> V_38 ) ;
return V_6 ;
}
V_10 &= ~ ( 1 << V_37 ) ;
V_6 = F_9 ( V_7 , V_10 , V_2 -> V_38 ) ;
if ( V_6 ) {
F_3 ( V_2 -> V_8 ,
L_8 , V_2 -> V_38 ) ;
return V_6 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_37 )
{
T_1 V_10 ;
int V_6 ;
V_6 = F_2 ( V_7 , & V_10 , V_2 -> V_38 ) ;
if ( V_6 ) {
F_3 ( V_2 -> V_8 , L_7 ,
V_2 -> V_38 ) ;
return V_6 ;
}
V_10 |= ( 1 << V_37 ) ;
V_6 = F_9 ( V_7 , V_10 , V_2 -> V_38 ) ;
if ( V_6 ) {
F_3 ( V_2 -> V_8 ,
L_8 , V_2 -> V_38 ) ;
return V_6 ;
}
return 0 ;
}
static T_2 F_11 ( int V_39 , void * V_40 )
{
struct V_1 * V_2 = V_40 ;
const struct V_41 * V_42 ;
T_1 V_43 , V_44 ;
int V_33 , V_45 , V_6 ;
struct V_46 * V_47 ;
F_12 ( & V_2 -> V_48 ) ;
V_6 = F_2 ( V_7 , & V_43 , V_2 -> V_49 ) ;
if ( V_6 ) {
F_3 ( V_2 -> V_8 , L_9 ,
V_2 -> V_49 ) ;
goto V_50;
}
V_6 = F_2 ( V_7 , & V_44 , V_2 -> V_38 ) ;
if ( V_6 ) {
F_3 ( V_2 -> V_8 , L_7 ,
V_2 -> V_38 ) ;
goto V_50;
}
V_43 &= ~ V_44 ;
for ( V_33 = 0 ; V_33 < V_51 ; V_33 ++ ) {
if ( ! ( V_43 & ( 1 << V_33 ) ) )
continue;
V_6 = F_10 ( V_2 , V_33 ) ;
if ( V_6 < 0 )
F_13 ( V_2 -> V_8 , L_10 , V_33 ) ;
V_2 -> V_52 [ V_33 ] . V_53 = 1 ;
}
for ( V_33 = 0 ; V_33 < V_51 ; V_33 ++ ) {
V_47 = & V_2 -> V_52 [ V_33 ] ;
if ( ! V_47 -> V_53 )
continue;
V_42 = & V_54 [ V_47 -> V_42 ] ;
V_45 = F_6 ( V_2 , V_42 -> V_55 ,
V_47 -> V_28 , V_47 -> V_56 , V_47 -> V_30 ) ;
if ( V_47 -> V_57 != NULL ) {
V_47 -> V_57 ( V_45 , V_47 -> V_28 , V_47 -> V_56 ) ;
V_47 -> V_57 = NULL ;
}
V_47 -> V_53 = 0 ;
V_47 -> V_58 = 0 ;
}
F_14 ( & V_2 -> V_48 ) ;
return V_59 ;
V_50:
for ( V_33 = 0 ; V_33 < V_51 ; V_33 ++ ) {
V_47 = & V_2 -> V_52 [ V_33 ] ;
if ( V_47 -> V_58 == 0 )
continue;
V_42 = & V_54 [ V_47 -> V_42 ] ;
V_45 = F_6 ( V_2 , V_42 -> V_55 ,
V_47 -> V_28 , V_47 -> V_56 , V_47 -> V_30 ) ;
if ( V_47 -> V_57 != NULL ) {
V_47 -> V_57 ( V_45 , V_47 -> V_28 , V_47 -> V_56 ) ;
V_47 -> V_57 = NULL ;
}
V_47 -> V_53 = 0 ;
V_47 -> V_58 = 0 ;
}
F_14 ( & V_2 -> V_48 ) ;
return V_59 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_46 * V_60 )
{
struct V_46 * V_61 ;
int V_6 ;
V_61 = & V_2 -> V_52 [ V_60 -> V_42 ] ;
memcpy ( V_61 , V_60 , sizeof( * V_60 ) ) ;
V_6 = F_8 ( V_2 , V_60 -> V_42 ) ;
if ( V_6 < 0 ) {
F_3 ( V_2 -> V_8 , L_11 ) ;
return V_6 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
int V_62 )
{
const struct V_41 * V_42 ;
int V_6 = 0 ;
V_42 = & V_54 [ V_62 ] ;
switch ( V_62 ) {
case V_63 :
case V_64 :
V_6 = F_9 ( V_7 ,
V_65 , V_42 -> V_66 ) ;
if ( V_6 ) {
F_3 ( V_2 -> V_8 ,
L_12 ,
V_42 -> V_66 ) ;
return V_6 ;
}
break;
default:
break;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
unsigned int V_67 ,
T_1 V_68 )
{
unsigned long V_69 ;
int V_6 ;
V_69 = V_70 + F_18 ( V_67 ) ;
do {
T_1 V_3 ;
V_6 = F_2 ( V_7 , & V_3 , V_68 ) ;
if ( V_6 ) {
F_3 ( V_2 -> V_8 ,
L_13 ,
V_68 ) ;
return V_6 ;
}
if ( ! ( V_3 & V_71 ) && ( V_3 & V_72 ) )
return 0 ;
F_19 ( 500 , 2000 ) ;
} while ( ! F_20 ( V_70 , V_69 ) );
F_3 ( V_2 -> V_8 , L_14 ) ;
return - V_73 ;
}
int F_21 ( struct V_46 * V_60 )
{
const struct V_41 * V_42 ;
T_1 V_74 , V_75 ;
int V_6 ;
if ( ! V_60 || ! V_76 )
return - V_77 ;
F_12 ( & V_76 -> V_48 ) ;
if ( V_60 -> V_42 < V_78 || V_60 -> V_42 > V_64 ) {
V_6 = - V_77 ;
goto V_79;
}
if ( V_76 -> V_52 [ V_60 -> V_42 ] . V_58 ) {
V_6 = - V_80 ;
goto V_79;
}
V_74 = ( V_60 -> V_28 >> 8 ) & 0xff ;
V_75 = V_60 -> V_28 & 0xff ;
V_42 = & V_54 [ V_60 -> V_42 ] ;
V_6 = F_9 ( V_7 , V_74 , V_42 -> V_81 + 1 ) ;
if ( V_6 ) {
F_3 ( V_76 -> V_8 ,
L_15 , V_42 -> V_81 + 1 ) ;
goto V_79;
}
V_6 = F_9 ( V_7 , V_75 , V_42 -> V_81 ) ;
if ( V_6 ) {
F_3 ( V_76 -> V_8 ,
L_15 , V_42 -> V_81 + 1 ) ;
goto V_79;
}
if ( V_60 -> V_82 ) {
V_6 = F_9 ( V_7 ,
V_74 , V_42 -> V_83 + 1 ) ;
if ( V_6 ) {
F_3 ( V_76 -> V_8 ,
L_16 ,
V_42 -> V_83 + 1 ) ;
goto V_79;
}
V_6 = F_9 ( V_7 ,
V_75 , V_42 -> V_83 ) ;
if ( V_6 ) {
F_3 ( V_76 -> V_8 ,
L_17 ,
V_42 -> V_81 + 1 ) ;
goto V_79;
}
}
if ( V_60 -> type == V_84 && V_60 -> V_57 != NULL ) {
V_6 = F_15 ( V_76 , V_60 ) ;
if ( V_6 < 0 )
goto V_79;
V_6 = F_16 ( V_76 , V_60 -> V_42 ) ;
if ( V_6 < 0 )
goto V_79;
V_76 -> V_52 [ V_60 -> V_42 ] . V_58 = 1 ;
V_6 = 0 ;
goto V_79;
}
if ( V_60 -> V_42 == V_78 ) {
V_6 = - V_77 ;
goto V_79;
}
V_6 = F_16 ( V_76 , V_60 -> V_42 ) ;
if ( V_6 < 0 )
goto V_79;
V_76 -> V_52 [ V_60 -> V_42 ] . V_58 = 1 ;
V_6 = F_17 ( V_76 , 5 , V_42 -> V_66 ) ;
if ( V_6 ) {
V_76 -> V_52 [ V_60 -> V_42 ] . V_58 = 0 ;
goto V_79;
}
V_6 = F_6 ( V_76 , V_42 -> V_55 ,
V_60 -> V_28 , V_60 -> V_56 , V_60 -> V_30 ) ;
V_76 -> V_52 [ V_60 -> V_42 ] . V_58 = 0 ;
V_79:
F_14 ( & V_76 -> V_48 ) ;
return V_6 ;
}
int F_22 ( int V_85 )
{
struct V_46 V_60 ;
int V_11 = 0 ;
int V_6 ;
V_60 . V_28 = ( 1 << V_85 ) ;
V_60 . V_42 = V_64 ;
V_60 . V_58 = 0 ;
V_60 . V_57 = NULL ;
V_6 = F_21 ( & V_60 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_60 . V_56 [ V_85 ] > 0 )
V_11 = V_60 . V_56 [ V_85 ] ;
return V_11 ;
}
static int F_23 ( struct V_1 * V_2 ,
int V_86 , int V_87 )
{
int V_6 ;
T_1 V_88 ;
V_6 = F_2 ( V_17 ,
& V_88 , V_22 ) ;
if ( V_6 ) {
F_3 ( V_2 -> V_8 , L_18 ,
V_22 ) ;
return V_6 ;
}
if ( V_87 )
V_88 |= V_86 ? V_19 : V_89 ;
else
V_88 &= V_86 ? ~ V_19 : ~ V_89 ;
V_6 = F_9 ( V_17 ,
V_88 , V_22 ) ;
if ( V_6 ) {
F_3 ( V_2 -> V_8 , L_19 ,
V_22 ) ;
return V_6 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , int V_87 )
{
T_1 V_88 ;
int V_6 ;
V_6 = F_2 ( V_17 ,
& V_88 , V_90 ) ;
if ( V_6 ) {
F_3 ( V_2 -> V_8 , L_20 ,
V_90 ) ;
return V_6 ;
}
if ( V_87 )
V_88 |= V_91 ;
else
V_88 &= ~ V_91 ;
V_6 = F_9 ( V_7 , V_88 , V_90 ) ;
if ( V_6 ) {
F_3 ( V_2 -> V_8 , L_21 ,
V_90 ) ;
return V_6 ;
}
return 0 ;
}
static int F_25 ( struct V_92 * V_93 )
{
struct V_1 * V_2 ;
struct V_94 * V_95 = V_93 -> V_8 . V_96 ;
int V_6 ;
T_1 V_88 ;
if ( ! V_95 ) {
F_3 ( & V_93 -> V_8 , L_22 ) ;
return - V_77 ;
}
V_2 = F_26 ( sizeof( * V_2 ) , V_97 ) ;
if ( ! V_2 )
return - V_98 ;
V_2 -> V_8 = & V_93 -> V_8 ;
V_2 -> V_38 = ( V_95 -> V_99 == 1 ) ?
V_100 : V_101 ;
V_2 -> V_49 = ( V_95 -> V_99 == 1 ) ?
V_102 : V_103 ;
V_6 = F_24 ( V_2 , 1 ) ;
if ( V_6 < 0 )
goto V_104;
V_6 = F_23 ( V_2 , 0 , 1 ) ;
if ( V_6 < 0 )
goto V_105;
V_6 = F_2 ( V_17 ,
& V_88 , V_22 ) ;
if ( V_6 ) {
F_3 ( & V_93 -> V_8 , L_23 ,
V_22 ) ;
goto V_50;
}
V_88 |= V_106 ;
V_6 = F_9 ( V_17 ,
V_88 , V_22 ) ;
if ( V_6 ) {
F_3 ( & V_93 -> V_8 , L_24 ,
V_22 ) ;
goto V_50;
}
V_6 = F_2 ( V_107 , & V_88 , V_108 ) ;
if ( V_6 ) {
F_3 ( & V_93 -> V_8 , L_25 ,
V_108 ) ;
goto V_50;
}
if ( ! ( V_88 & V_109 ) ) {
F_27 ( & V_93 -> V_8 , L_26 ) ;
V_88 |= V_109 ;
V_6 = F_9 ( V_107 , V_88 ,
V_108 ) ;
if ( V_6 ) {
F_3 ( & V_93 -> V_8 , L_27 ,
V_108 ) ;
goto V_50;
}
}
F_28 ( V_93 , V_2 ) ;
F_29 ( & V_2 -> V_48 ) ;
V_6 = F_30 ( F_31 ( V_93 , 0 ) , NULL ,
F_11 ,
V_110 , L_28 , V_2 ) ;
if ( V_6 ) {
F_13 ( & V_93 -> V_8 , L_29 ) ;
goto V_111;
}
V_76 = V_2 ;
return 0 ;
V_111:
F_28 ( V_93 , NULL ) ;
V_50:
F_23 ( V_2 , 0 , 0 ) ;
V_105:
F_24 ( V_2 , 0 ) ;
V_104:
F_32 ( V_2 ) ;
return V_6 ;
}
static int F_33 ( struct V_92 * V_93 )
{
struct V_1 * V_2 = F_34 ( V_93 ) ;
F_35 ( F_31 ( V_93 , 0 ) , V_2 ) ;
F_28 ( V_93 , NULL ) ;
F_23 ( V_2 , 0 , 0 ) ;
F_24 ( V_2 , 0 ) ;
F_32 ( V_2 ) ;
return 0 ;
}
