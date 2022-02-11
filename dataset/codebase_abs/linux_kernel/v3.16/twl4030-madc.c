static int F_1 ( struct V_1 * V_1 ,
const struct V_2 * V_3 ,
int * V_4 , int * V_5 , long V_6 )
{
struct V_7 * V_8 = F_2 ( V_1 ) ;
struct V_9 V_10 ;
int V_11 ;
V_10 . V_12 = V_8 -> V_13 ? V_14 : V_15 ;
V_10 . V_16 = F_3 ( V_3 -> V_17 ) ;
V_10 . V_18 = false ;
V_10 . V_19 = NULL ;
V_10 . type = V_20 ;
V_10 . V_21 = ! ( V_6 == V_22 ) ;
V_10 . V_23 = ( V_6 == V_24 ) ;
V_11 = F_4 ( & V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
* V_4 = V_10 . V_25 [ V_3 -> V_17 ] ;
return V_26 ;
}
static int F_5 ( struct V_7 * V_8 , T_1 V_27 )
{
T_2 V_4 ;
int V_11 ;
V_11 = F_6 ( V_28 , & V_4 , V_27 ) ;
if ( V_11 ) {
F_7 ( V_8 -> V_29 , L_1 , V_27 ) ;
return V_11 ;
}
return ( int ) ( V_4 >> 6 ) ;
}
static int F_8 ( int V_30 )
{
T_1 V_4 ;
int V_31 , V_32 , V_33 , V_34 , V_11 ;
V_33 = ( V_30 * V_35 ) / V_36 ;
V_11 = F_9 ( V_37 , & V_4 ,
V_38 ) ;
if ( V_11 < 0 )
return V_11 ;
V_32 = ( ( V_4 & V_39 ) + 1 ) * 10 ;
V_34 = V_33 * 1000 / V_32 ;
for ( V_31 = 58 ; V_31 >= 0 ; V_31 -- ) {
int V_40 = V_41 [ V_31 ] ;
if ( ( V_40 - V_34 ) >= 0 )
break;
}
return V_31 + 1 ;
}
static int F_10 ( int V_30 )
{
int V_11 ;
T_1 V_4 ;
V_11 = F_9 ( V_37 , & V_4 ,
V_42 ) ;
if ( V_11 )
return V_11 ;
if ( V_4 & V_43 )
return ( V_30 * V_44 ) / V_45 ;
else
return ( V_30 * V_44 ) / V_46 ;
}
static int F_11 ( struct V_7 * V_8 ,
T_1 V_47 , unsigned
long V_16 , int * V_48 ,
bool V_21 )
{
int V_49 = 0 ;
int V_50 ;
T_1 V_27 ;
F_12 (i, &channels, TWL4030_MADC_MAX_CHANNELS) {
V_27 = V_47 + ( 2 * V_50 ) ;
V_48 [ V_50 ] = F_5 ( V_8 , V_27 ) ;
if ( V_48 [ V_50 ] < 0 ) {
F_7 ( V_8 -> V_29 , L_2 ,
V_27 ) ;
return V_48 [ V_50 ] ;
}
if ( V_21 ) {
V_49 ++ ;
continue;
}
switch ( V_50 ) {
case 10 :
V_48 [ V_50 ] = F_10 ( V_48 [ V_50 ] ) ;
if ( V_48 [ V_50 ] < 0 ) {
F_7 ( V_8 -> V_29 , L_3 ) ;
return V_48 [ V_50 ] ;
} else {
V_49 ++ ;
V_48 [ V_50 ] = V_48 [ V_50 ] - 750 ;
}
break;
case 1 :
V_48 [ V_50 ] = F_8 ( V_48 [ V_50 ] ) ;
if ( V_48 [ V_50 ] < 0 ) {
F_7 ( V_8 -> V_29 , L_4 ) ;
return V_48 [ V_50 ] ;
} else {
V_48 [ V_50 ] -= 3 ;
V_49 ++ ;
}
break;
default:
V_49 ++ ;
V_48 [ V_50 ] = ( V_48 [ V_50 ] * 3 * 1000 *
V_51 [ V_50 ] . V_52 )
/ ( 2 * 1023 *
V_51 [ V_50 ] . V_53 ) ;
}
}
return V_49 ;
}
static int F_13 ( struct V_7 * V_8 , T_1 V_54 )
{
T_1 V_4 ;
int V_11 ;
V_11 = F_9 ( V_28 , & V_4 , V_8 -> V_55 ) ;
if ( V_11 ) {
F_7 ( V_8 -> V_29 , L_5 ,
V_8 -> V_55 ) ;
return V_11 ;
}
V_4 &= ~ ( 1 << V_54 ) ;
V_11 = F_14 ( V_28 , V_4 , V_8 -> V_55 ) ;
if ( V_11 ) {
F_7 ( V_8 -> V_29 ,
L_6 , V_8 -> V_55 ) ;
return V_11 ;
}
return 0 ;
}
static int F_15 ( struct V_7 * V_8 , T_1 V_54 )
{
T_1 V_4 ;
int V_11 ;
V_11 = F_9 ( V_28 , & V_4 , V_8 -> V_55 ) ;
if ( V_11 ) {
F_7 ( V_8 -> V_29 , L_5 ,
V_8 -> V_55 ) ;
return V_11 ;
}
V_4 |= ( 1 << V_54 ) ;
V_11 = F_14 ( V_28 , V_4 , V_8 -> V_55 ) ;
if ( V_11 ) {
F_7 ( V_8 -> V_29 ,
L_6 , V_8 -> V_55 ) ;
return V_11 ;
}
return 0 ;
}
static T_3 F_16 ( int V_56 , void * V_57 )
{
struct V_7 * V_8 = V_57 ;
const struct V_58 * V_12 ;
T_1 V_59 , V_60 ;
int V_50 , V_61 , V_11 ;
struct V_9 * V_62 ;
F_17 ( & V_8 -> V_63 ) ;
V_11 = F_9 ( V_28 , & V_59 , V_8 -> V_64 ) ;
if ( V_11 ) {
F_7 ( V_8 -> V_29 , L_7 ,
V_8 -> V_64 ) ;
goto V_65;
}
V_11 = F_9 ( V_28 , & V_60 , V_8 -> V_55 ) ;
if ( V_11 ) {
F_7 ( V_8 -> V_29 , L_5 ,
V_8 -> V_55 ) ;
goto V_65;
}
V_59 &= ~ V_60 ;
for ( V_50 = 0 ; V_50 < V_66 ; V_50 ++ ) {
if ( ! ( V_59 & ( 1 << V_50 ) ) )
continue;
V_11 = F_15 ( V_8 , V_50 ) ;
if ( V_11 < 0 )
F_18 ( V_8 -> V_29 , L_8 , V_50 ) ;
V_8 -> V_67 [ V_50 ] . V_68 = 1 ;
}
for ( V_50 = 0 ; V_50 < V_66 ; V_50 ++ ) {
V_62 = & V_8 -> V_67 [ V_50 ] ;
if ( ! V_62 -> V_68 )
continue;
V_12 = & V_69 [ V_62 -> V_12 ] ;
V_61 = F_11 ( V_8 , V_12 -> V_70 ,
V_62 -> V_16 , V_62 -> V_25 , V_62 -> V_21 ) ;
if ( V_62 -> V_19 != NULL ) {
V_62 -> V_19 ( V_61 , V_62 -> V_16 , V_62 -> V_25 ) ;
V_62 -> V_19 = NULL ;
}
V_62 -> V_68 = 0 ;
V_62 -> V_18 = 0 ;
}
F_19 ( & V_8 -> V_63 ) ;
return V_71 ;
V_65:
for ( V_50 = 0 ; V_50 < V_66 ; V_50 ++ ) {
V_62 = & V_8 -> V_67 [ V_50 ] ;
if ( V_62 -> V_18 == 0 )
continue;
V_12 = & V_69 [ V_62 -> V_12 ] ;
V_61 = F_11 ( V_8 , V_12 -> V_70 ,
V_62 -> V_16 , V_62 -> V_25 , V_62 -> V_21 ) ;
if ( V_62 -> V_19 != NULL ) {
V_62 -> V_19 ( V_61 , V_62 -> V_16 , V_62 -> V_25 ) ;
V_62 -> V_19 = NULL ;
}
V_62 -> V_68 = 0 ;
V_62 -> V_18 = 0 ;
}
F_19 ( & V_8 -> V_63 ) ;
return V_71 ;
}
static int F_20 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_9 * V_72 ;
int V_11 ;
V_72 = & V_8 -> V_67 [ V_10 -> V_12 ] ;
memcpy ( V_72 , V_10 , sizeof( * V_10 ) ) ;
V_11 = F_13 ( V_8 , V_10 -> V_12 ) ;
if ( V_11 < 0 ) {
F_7 ( V_8 -> V_29 , L_9 ) ;
return V_11 ;
}
return 0 ;
}
static int F_21 ( struct V_7 * V_8 ,
int V_73 )
{
const struct V_58 * V_12 ;
int V_11 = 0 ;
if ( V_73 != V_15 && V_73 != V_14 )
return - V_74 ;
V_12 = & V_69 [ V_73 ] ;
V_11 = F_14 ( V_28 , V_75 ,
V_12 -> V_76 ) ;
if ( V_11 ) {
F_7 ( V_8 -> V_29 , L_10 ,
V_12 -> V_76 ) ;
return V_11 ;
}
return 0 ;
}
static int F_22 ( struct V_7 * V_8 ,
unsigned int V_77 ,
T_1 V_78 )
{
unsigned long V_79 ;
int V_11 ;
V_79 = V_80 + F_23 ( V_77 ) ;
do {
T_1 V_27 ;
V_11 = F_9 ( V_28 , & V_27 , V_78 ) ;
if ( V_11 ) {
F_7 ( V_8 -> V_29 ,
L_11 ,
V_78 ) ;
return V_11 ;
}
if ( ! ( V_27 & V_81 ) && ( V_27 & V_82 ) )
return 0 ;
F_24 ( 500 , 2000 ) ;
} while ( ! F_25 ( V_80 , V_79 ) );
F_7 ( V_8 -> V_29 , L_12 ) ;
return - V_83 ;
}
int F_4 ( struct V_9 * V_10 )
{
const struct V_58 * V_12 ;
int V_11 ;
if ( ! V_10 || ! V_84 )
return - V_85 ;
F_17 ( & V_84 -> V_63 ) ;
if ( V_10 -> V_12 < V_86 || V_10 -> V_12 > V_14 ) {
V_11 = - V_85 ;
goto V_87;
}
if ( V_84 -> V_67 [ V_10 -> V_12 ] . V_18 ) {
V_11 = - V_88 ;
goto V_87;
}
V_12 = & V_69 [ V_10 -> V_12 ] ;
V_11 = F_26 ( V_28 , V_10 -> V_16 , V_12 -> V_89 ) ;
if ( V_11 ) {
F_7 ( V_84 -> V_29 ,
L_13 , V_12 -> V_89 ) ;
goto V_87;
}
if ( V_10 -> V_23 ) {
V_11 = F_26 ( V_28 , V_10 -> V_16 ,
V_12 -> V_90 ) ;
if ( V_11 ) {
F_7 ( V_84 -> V_29 ,
L_14 ,
V_12 -> V_90 ) ;
goto V_87;
}
}
if ( V_10 -> type == V_91 && V_10 -> V_19 != NULL ) {
V_11 = F_20 ( V_84 , V_10 ) ;
if ( V_11 < 0 )
goto V_87;
V_11 = F_21 ( V_84 , V_10 -> V_12 ) ;
if ( V_11 < 0 )
goto V_87;
V_84 -> V_67 [ V_10 -> V_12 ] . V_18 = 1 ;
V_11 = 0 ;
goto V_87;
}
if ( V_10 -> V_12 == V_86 ) {
V_11 = - V_85 ;
goto V_87;
}
V_11 = F_21 ( V_84 , V_10 -> V_12 ) ;
if ( V_11 < 0 )
goto V_87;
V_84 -> V_67 [ V_10 -> V_12 ] . V_18 = 1 ;
V_11 = F_22 ( V_84 , 5 , V_12 -> V_76 ) ;
if ( V_11 ) {
V_84 -> V_67 [ V_10 -> V_12 ] . V_18 = 0 ;
goto V_87;
}
V_11 = F_11 ( V_84 , V_12 -> V_70 ,
V_10 -> V_16 , V_10 -> V_25 , V_10 -> V_21 ) ;
V_84 -> V_67 [ V_10 -> V_12 ] . V_18 = 0 ;
V_87:
F_19 ( & V_84 -> V_63 ) ;
return V_11 ;
}
int F_27 ( int V_92 )
{
struct V_9 V_10 ;
int V_31 = 0 ;
int V_11 ;
V_10 . V_16 = ( 1 << V_92 ) ;
V_10 . V_12 = V_14 ;
V_10 . V_18 = 0 ;
V_10 . V_21 = 0 ;
V_10 . V_19 = NULL ;
V_11 = F_4 ( & V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_10 . V_25 [ V_92 ] > 0 )
V_31 = V_10 . V_25 [ V_92 ] ;
return V_31 ;
}
static int F_28 ( struct V_7 * V_8 ,
int V_3 , int V_93 )
{
int V_11 ;
int V_94 ;
T_1 V_95 ;
V_11 = F_9 ( V_37 ,
& V_95 , V_42 ) ;
if ( V_11 ) {
F_7 ( V_8 -> V_29 , L_15 ,
V_42 ) ;
return V_11 ;
}
V_94 = V_3 ? V_39 : V_96 ;
if ( V_93 )
V_95 |= V_94 ;
else
V_95 &= ~ V_94 ;
V_11 = F_14 ( V_37 ,
V_95 , V_42 ) ;
if ( V_11 ) {
F_7 ( V_8 -> V_29 , L_16 ,
V_42 ) ;
return V_11 ;
}
return 0 ;
}
static int F_29 ( struct V_7 * V_8 , int V_93 )
{
T_1 V_95 ;
int V_11 ;
V_11 = F_9 ( V_37 ,
& V_95 , V_97 ) ;
if ( V_11 ) {
F_7 ( V_8 -> V_29 , L_17 ,
V_97 ) ;
return V_11 ;
}
if ( V_93 )
V_95 |= V_98 ;
else
V_95 &= ~ V_98 ;
V_11 = F_14 ( V_28 , V_95 , V_97 ) ;
if ( V_11 ) {
F_7 ( V_8 -> V_29 , L_18 ,
V_97 ) ;
return V_11 ;
}
return 0 ;
}
static int F_30 ( struct V_99 * V_100 )
{
struct V_7 * V_8 ;
struct V_101 * V_102 = F_31 ( & V_100 -> V_29 ) ;
struct V_103 * V_104 = V_100 -> V_29 . V_105 ;
int V_56 , V_11 ;
T_1 V_95 ;
struct V_1 * V_1 = NULL ;
if ( ! V_102 && ! V_104 ) {
F_7 ( & V_100 -> V_29 , L_19 ) ;
return - V_85 ;
}
V_1 = F_32 ( & V_100 -> V_29 , sizeof( * V_8 ) ) ;
if ( ! V_1 ) {
F_7 ( & V_100 -> V_29 , L_20 ) ;
return - V_106 ;
}
V_8 = F_2 ( V_1 ) ;
V_8 -> V_29 = & V_100 -> V_29 ;
V_1 -> V_107 = F_33 ( & V_100 -> V_29 ) ;
V_1 -> V_29 . V_108 = & V_100 -> V_29 ;
V_1 -> V_29 . V_105 = V_100 -> V_29 . V_105 ;
V_1 -> V_109 = & V_110 ;
V_1 -> V_111 = V_112 ;
V_1 -> V_16 = V_113 ;
V_1 -> V_114 = F_34 ( V_113 ) ;
if ( V_102 )
V_8 -> V_13 = ( V_102 -> V_115 != 1 ) ;
else
V_8 -> V_13 = F_35 ( V_104 ,
L_21 ) ;
V_8 -> V_55 = V_8 -> V_13 ? V_116 :
V_117 ;
V_8 -> V_64 = V_8 -> V_13 ? V_118 :
V_119 ;
V_11 = F_29 ( V_8 , 1 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_28 ( V_8 , 0 , 1 ) ;
if ( V_11 < 0 )
goto V_120;
V_11 = F_9 ( V_37 ,
& V_95 , V_42 ) ;
if ( V_11 ) {
F_7 ( & V_100 -> V_29 , L_22 ,
V_42 ) ;
goto V_65;
}
V_95 |= V_121 ;
V_11 = F_14 ( V_37 ,
V_95 , V_42 ) ;
if ( V_11 ) {
F_7 ( & V_100 -> V_29 , L_23 ,
V_42 ) ;
goto V_65;
}
V_11 = F_9 ( V_122 , & V_95 , V_123 ) ;
if ( V_11 ) {
F_7 ( & V_100 -> V_29 , L_24 ,
V_123 ) ;
goto V_65;
}
if ( ! ( V_95 & V_124 ) ) {
F_36 ( & V_100 -> V_29 , L_25 ) ;
V_95 |= V_124 ;
V_11 = F_14 ( V_122 , V_95 ,
V_123 ) ;
if ( V_11 ) {
F_7 ( & V_100 -> V_29 , L_26 ,
V_123 ) ;
goto V_65;
}
}
F_37 ( V_100 , V_1 ) ;
F_38 ( & V_8 -> V_63 ) ;
V_56 = F_39 ( V_100 , 0 ) ;
V_11 = F_40 ( & V_100 -> V_29 , V_56 , NULL ,
F_16 ,
V_125 , L_27 , V_8 ) ;
if ( V_11 ) {
F_7 ( & V_100 -> V_29 , L_28 ) ;
goto V_65;
}
V_84 = V_8 ;
V_11 = F_41 ( V_1 ) ;
if ( V_11 ) {
F_7 ( & V_100 -> V_29 , L_29 ) ;
goto V_65;
}
return 0 ;
V_65:
F_28 ( V_8 , 0 , 0 ) ;
V_120:
F_29 ( V_8 , 0 ) ;
return V_11 ;
}
static int F_42 ( struct V_99 * V_100 )
{
struct V_1 * V_1 = F_43 ( V_100 ) ;
struct V_7 * V_8 = F_2 ( V_1 ) ;
F_44 ( V_1 ) ;
F_28 ( V_8 , 0 , 0 ) ;
F_29 ( V_8 , 0 ) ;
return 0 ;
}
