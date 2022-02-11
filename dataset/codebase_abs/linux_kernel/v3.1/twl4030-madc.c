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
long V_28 , int * V_29 )
{
int V_30 = 0 , V_31 = 0 , V_32 ;
T_1 V_3 ;
F_7 (i, &channels, TWL4030_MADC_MAX_CHANNELS) {
V_3 = V_27 + 2 * V_32 ;
V_29 [ V_32 ] = F_1 ( V_2 , V_3 ) ;
if ( V_29 [ V_32 ] < 0 ) {
F_3 ( V_2 -> V_8 ,
L_3 , V_3 ) ;
V_31 ++ ;
continue;
}
switch ( V_32 ) {
case 10 :
V_29 [ V_32 ] = F_5 ( V_29 [ V_32 ] ) ;
if ( V_29 [ V_32 ] < 0 ) {
F_3 ( V_2 -> V_8 , L_4 ) ;
V_31 ++ ;
} else {
V_30 ++ ;
V_29 [ V_32 ] = V_29 [ V_32 ] - 750 ;
}
break;
case 1 :
V_29 [ V_32 ] = F_4 ( V_29 [ V_32 ] ) ;
if ( V_29 [ V_32 ] < 0 ) {
F_3 ( V_2 -> V_8 , L_5 ) ;
V_31 ++ ;
} else {
V_29 [ V_32 ] -= 3 ;
V_30 ++ ;
}
break;
default:
V_30 ++ ;
V_29 [ V_32 ] = ( V_29 [ V_32 ] * 3 * 1000 *
V_33 [ V_32 ] . V_34 )
/ ( 2 * 1023 *
V_33 [ V_32 ] . V_35 ) ;
}
}
if ( V_31 )
F_3 ( V_2 -> V_8 , L_6 , V_31 ) ;
return V_30 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_36 )
{
T_1 V_10 ;
int V_6 ;
V_6 = F_2 ( V_7 , & V_10 , V_2 -> V_37 ) ;
if ( V_6 ) {
F_3 ( V_2 -> V_8 , L_7 ,
V_2 -> V_37 ) ;
return V_6 ;
}
V_10 &= ~ ( 1 << V_36 ) ;
V_6 = F_9 ( V_7 , V_10 , V_2 -> V_37 ) ;
if ( V_6 ) {
F_3 ( V_2 -> V_8 ,
L_8 , V_2 -> V_37 ) ;
return V_6 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_36 )
{
T_1 V_10 ;
int V_6 ;
V_6 = F_2 ( V_7 , & V_10 , V_2 -> V_37 ) ;
if ( V_6 ) {
F_3 ( V_2 -> V_8 , L_7 ,
V_2 -> V_37 ) ;
return V_6 ;
}
V_10 |= ( 1 << V_36 ) ;
V_6 = F_9 ( V_7 , V_10 , V_2 -> V_37 ) ;
if ( V_6 ) {
F_3 ( V_2 -> V_8 ,
L_8 , V_2 -> V_37 ) ;
return V_6 ;
}
return 0 ;
}
static T_2 F_11 ( int V_38 , void * V_39 )
{
struct V_1 * V_2 = V_39 ;
const struct V_40 * V_41 ;
T_1 V_42 , V_43 ;
int V_32 , V_44 , V_6 ;
struct V_45 * V_46 ;
F_12 ( & V_2 -> V_47 ) ;
V_6 = F_2 ( V_7 , & V_42 , V_2 -> V_48 ) ;
if ( V_6 ) {
F_3 ( V_2 -> V_8 , L_9 ,
V_2 -> V_48 ) ;
goto V_49;
}
V_6 = F_2 ( V_7 , & V_43 , V_2 -> V_37 ) ;
if ( V_6 ) {
F_3 ( V_2 -> V_8 , L_7 ,
V_2 -> V_37 ) ;
goto V_49;
}
V_42 &= ~ V_43 ;
for ( V_32 = 0 ; V_32 < V_50 ; V_32 ++ ) {
if ( ! ( V_42 & ( 1 << V_32 ) ) )
continue;
V_6 = F_10 ( V_2 , V_32 ) ;
if ( V_6 < 0 )
F_13 ( V_2 -> V_8 , L_10 , V_32 ) ;
V_2 -> V_51 [ V_32 ] . V_52 = 1 ;
}
for ( V_32 = 0 ; V_32 < V_50 ; V_32 ++ ) {
V_46 = & V_2 -> V_51 [ V_32 ] ;
if ( ! V_46 -> V_52 )
continue;
V_41 = & V_53 [ V_46 -> V_41 ] ;
V_44 = F_6 ( V_2 , V_41 -> V_54 ,
V_46 -> V_28 , V_46 -> V_55 ) ;
if ( V_46 -> V_56 != NULL ) {
V_46 -> V_56 ( V_44 , V_46 -> V_28 , V_46 -> V_55 ) ;
V_46 -> V_56 = NULL ;
}
V_46 -> V_52 = 0 ;
V_46 -> V_57 = 0 ;
}
F_14 ( & V_2 -> V_47 ) ;
return V_58 ;
V_49:
for ( V_32 = 0 ; V_32 < V_50 ; V_32 ++ ) {
V_46 = & V_2 -> V_51 [ V_32 ] ;
if ( V_46 -> V_57 == 0 )
continue;
V_41 = & V_53 [ V_46 -> V_41 ] ;
V_44 = F_6 ( V_2 , V_41 -> V_54 ,
V_46 -> V_28 , V_46 -> V_55 ) ;
if ( V_46 -> V_56 != NULL ) {
V_46 -> V_56 ( V_44 , V_46 -> V_28 , V_46 -> V_55 ) ;
V_46 -> V_56 = NULL ;
}
V_46 -> V_52 = 0 ;
V_46 -> V_57 = 0 ;
}
F_14 ( & V_2 -> V_47 ) ;
return V_58 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_45 * V_59 )
{
struct V_45 * V_60 ;
int V_6 ;
V_60 = & V_2 -> V_51 [ V_59 -> V_41 ] ;
memcpy ( V_60 , V_59 , sizeof( * V_59 ) ) ;
V_6 = F_8 ( V_2 , V_59 -> V_41 ) ;
if ( V_6 < 0 ) {
F_3 ( V_2 -> V_8 , L_11 ) ;
return V_6 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
int V_61 )
{
const struct V_40 * V_41 ;
int V_6 = 0 ;
V_41 = & V_53 [ V_61 ] ;
switch ( V_61 ) {
case V_62 :
case V_63 :
V_6 = F_9 ( V_7 ,
V_64 , V_41 -> V_65 ) ;
if ( V_6 ) {
F_3 ( V_2 -> V_8 ,
L_12 ,
V_41 -> V_65 ) ;
return V_6 ;
}
break;
default:
break;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
unsigned int V_66 ,
T_1 V_67 )
{
unsigned long V_68 ;
int V_6 ;
V_68 = V_69 + F_18 ( V_66 ) ;
do {
T_1 V_3 ;
V_6 = F_2 ( V_7 , & V_3 , V_67 ) ;
if ( V_6 ) {
F_3 ( V_2 -> V_8 ,
L_13 ,
V_67 ) ;
return V_6 ;
}
if ( ! ( V_3 & V_70 ) && ( V_3 & V_71 ) )
return 0 ;
F_19 ( 500 , 2000 ) ;
} while ( ! F_20 ( V_69 , V_68 ) );
F_3 ( V_2 -> V_8 , L_14 ) ;
return - V_72 ;
}
int F_21 ( struct V_45 * V_59 )
{
const struct V_40 * V_41 ;
T_1 V_73 , V_74 ;
int V_6 ;
if ( ! V_59 || ! V_75 )
return - V_76 ;
F_12 ( & V_75 -> V_47 ) ;
if ( V_59 -> V_41 < V_77 || V_59 -> V_41 > V_63 ) {
V_6 = - V_76 ;
goto V_78;
}
if ( V_75 -> V_51 [ V_59 -> V_41 ] . V_57 ) {
V_6 = - V_79 ;
goto V_78;
}
V_73 = ( V_59 -> V_28 >> 8 ) & 0xff ;
V_74 = V_59 -> V_28 & 0xff ;
V_41 = & V_53 [ V_59 -> V_41 ] ;
V_6 = F_9 ( V_7 , V_73 , V_41 -> V_80 + 1 ) ;
if ( V_6 ) {
F_3 ( V_75 -> V_8 ,
L_15 , V_41 -> V_80 + 1 ) ;
goto V_78;
}
V_6 = F_9 ( V_7 , V_74 , V_41 -> V_80 ) ;
if ( V_6 ) {
F_3 ( V_75 -> V_8 ,
L_15 , V_41 -> V_80 + 1 ) ;
goto V_78;
}
if ( V_59 -> V_81 ) {
V_6 = F_9 ( V_7 ,
V_73 , V_41 -> V_82 + 1 ) ;
if ( V_6 ) {
F_3 ( V_75 -> V_8 ,
L_16 ,
V_41 -> V_82 + 1 ) ;
goto V_78;
}
V_6 = F_9 ( V_7 ,
V_74 , V_41 -> V_82 ) ;
if ( V_6 ) {
F_3 ( V_75 -> V_8 ,
L_17 ,
V_41 -> V_80 + 1 ) ;
goto V_78;
}
}
if ( V_59 -> type == V_83 && V_59 -> V_56 != NULL ) {
V_6 = F_15 ( V_75 , V_59 ) ;
if ( V_6 < 0 )
goto V_78;
V_6 = F_16 ( V_75 , V_59 -> V_41 ) ;
if ( V_6 < 0 )
goto V_78;
V_75 -> V_51 [ V_59 -> V_41 ] . V_57 = 1 ;
V_6 = 0 ;
goto V_78;
}
if ( V_59 -> V_41 == V_77 ) {
V_6 = - V_76 ;
goto V_78;
}
V_6 = F_16 ( V_75 , V_59 -> V_41 ) ;
if ( V_6 < 0 )
goto V_78;
V_75 -> V_51 [ V_59 -> V_41 ] . V_57 = 1 ;
V_6 = F_17 ( V_75 , 5 , V_41 -> V_65 ) ;
if ( V_6 ) {
V_75 -> V_51 [ V_59 -> V_41 ] . V_57 = 0 ;
goto V_78;
}
V_6 = F_6 ( V_75 , V_41 -> V_54 ,
V_59 -> V_28 , V_59 -> V_55 ) ;
V_75 -> V_51 [ V_59 -> V_41 ] . V_57 = 0 ;
V_78:
F_14 ( & V_75 -> V_47 ) ;
return V_6 ;
}
int F_22 ( int V_84 )
{
struct V_45 V_59 ;
int V_11 = 0 ;
int V_6 ;
V_59 . V_28 = ( 1 << V_84 ) ;
V_59 . V_41 = V_63 ;
V_59 . V_57 = 0 ;
V_59 . V_56 = NULL ;
V_6 = F_21 ( & V_59 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_59 . V_55 [ V_84 ] > 0 )
V_11 = V_59 . V_55 [ V_84 ] ;
return V_11 ;
}
static int F_23 ( struct V_1 * V_2 ,
int V_85 , int V_86 )
{
int V_6 ;
T_1 V_87 ;
V_6 = F_2 ( V_17 ,
& V_87 , V_22 ) ;
if ( V_6 ) {
F_3 ( V_2 -> V_8 , L_18 ,
V_22 ) ;
return V_6 ;
}
if ( V_86 )
V_87 |= V_85 ? V_19 : V_88 ;
else
V_87 &= V_85 ? ~ V_19 : ~ V_88 ;
V_6 = F_9 ( V_17 ,
V_87 , V_22 ) ;
if ( V_6 ) {
F_3 ( V_2 -> V_8 , L_19 ,
V_22 ) ;
return V_6 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , int V_86 )
{
T_1 V_87 ;
int V_6 ;
V_6 = F_2 ( V_17 ,
& V_87 , V_89 ) ;
if ( V_6 ) {
F_3 ( V_2 -> V_8 , L_20 ,
V_89 ) ;
return V_6 ;
}
if ( V_86 )
V_87 |= V_90 ;
else
V_87 &= ~ V_90 ;
V_6 = F_9 ( V_7 , V_87 , V_89 ) ;
if ( V_6 ) {
F_3 ( V_2 -> V_8 , L_21 ,
V_89 ) ;
return V_6 ;
}
return 0 ;
}
static int T_3 F_25 ( struct V_91 * V_92 )
{
struct V_1 * V_2 ;
struct V_93 * V_94 = V_92 -> V_8 . V_95 ;
int V_6 ;
T_1 V_87 ;
if ( ! V_94 ) {
F_3 ( & V_92 -> V_8 , L_22 ) ;
return - V_76 ;
}
V_2 = F_26 ( sizeof( * V_2 ) , V_96 ) ;
if ( ! V_2 )
return - V_97 ;
V_2 -> V_8 = & V_92 -> V_8 ;
V_2 -> V_37 = ( V_94 -> V_98 == 1 ) ?
V_99 : V_100 ;
V_2 -> V_48 = ( V_94 -> V_98 == 1 ) ?
V_101 : V_102 ;
V_6 = F_24 ( V_2 , 1 ) ;
if ( V_6 < 0 )
goto V_103;
V_6 = F_23 ( V_2 , 0 , 1 ) ;
if ( V_6 < 0 )
goto V_104;
V_6 = F_2 ( V_17 ,
& V_87 , V_22 ) ;
if ( V_6 ) {
F_3 ( & V_92 -> V_8 , L_23 ,
V_22 ) ;
goto V_49;
}
V_87 |= V_105 ;
V_6 = F_9 ( V_17 ,
V_87 , V_22 ) ;
if ( V_6 ) {
F_3 ( & V_92 -> V_8 , L_24 ,
V_22 ) ;
goto V_49;
}
F_27 ( V_92 , V_2 ) ;
F_28 ( & V_2 -> V_47 ) ;
V_6 = F_29 ( F_30 ( V_92 , 0 ) , NULL ,
F_11 ,
V_106 , L_25 , V_2 ) ;
if ( V_6 ) {
F_13 ( & V_92 -> V_8 , L_26 ) ;
goto V_107;
}
V_75 = V_2 ;
return 0 ;
V_107:
F_27 ( V_92 , NULL ) ;
V_49:
F_23 ( V_2 , 0 , 0 ) ;
V_104:
F_24 ( V_2 , 0 ) ;
V_103:
F_31 ( V_2 ) ;
return V_6 ;
}
static int T_4 F_32 ( struct V_91 * V_92 )
{
struct V_1 * V_2 = F_33 ( V_92 ) ;
F_34 ( F_30 ( V_92 , 0 ) , V_2 ) ;
F_27 ( V_92 , NULL ) ;
F_23 ( V_2 , 0 , 0 ) ;
F_24 ( V_2 , 0 ) ;
F_31 ( V_2 ) ;
return 0 ;
}
static int T_5 F_35 ( void )
{
return F_36 ( & V_108 ) ;
}
static void T_6 F_37 ( void )
{
F_38 ( & V_108 ) ;
}
