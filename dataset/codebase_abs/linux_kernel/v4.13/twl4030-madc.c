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
V_10 . type = V_19 ;
V_10 . V_20 = ! ( V_6 == V_21 ) ;
V_10 . V_22 = ( V_6 == V_23 ) ;
V_11 = F_4 ( & V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
* V_4 = V_10 . V_24 [ V_3 -> V_17 ] ;
return V_25 ;
}
static int F_5 ( struct V_7 * V_8 , T_1 V_26 )
{
T_2 V_4 ;
int V_11 ;
V_11 = F_6 ( V_27 , & V_4 , V_26 ) ;
if ( V_11 ) {
F_7 ( V_8 -> V_28 , L_1 , V_26 ) ;
return V_11 ;
}
return ( int ) ( V_4 >> 6 ) ;
}
static int F_8 ( int V_29 )
{
T_1 V_4 ;
int V_30 , V_31 , V_32 , V_33 , V_11 ;
V_32 = ( V_29 * V_34 ) / V_35 ;
V_11 = F_9 ( V_36 , & V_4 ,
V_37 ) ;
if ( V_11 < 0 )
return V_11 ;
V_31 = ( ( V_4 & V_38 ) + 1 ) * 10 ;
V_33 = V_32 * 1000 / V_31 ;
for ( V_30 = 58 ; V_30 >= 0 ; V_30 -- ) {
int V_39 = V_40 [ V_30 ] ;
if ( ( V_39 - V_33 ) >= 0 )
break;
}
return V_30 + 1 ;
}
static int F_10 ( int V_29 )
{
int V_11 ;
T_1 V_4 ;
V_11 = F_9 ( V_36 , & V_4 ,
V_41 ) ;
if ( V_11 )
return V_11 ;
if ( V_4 & V_42 )
return ( V_29 * V_43 ) / V_44 ;
else
return ( V_29 * V_43 ) / V_45 ;
}
static int F_11 ( struct V_7 * V_8 ,
T_1 V_46 , unsigned
long V_16 , int * V_47 ,
bool V_20 )
{
int V_48 = 0 ;
int V_49 ;
T_1 V_26 ;
F_12 (i, &channels, TWL4030_MADC_MAX_CHANNELS) {
V_26 = V_46 + ( 2 * V_49 ) ;
V_47 [ V_49 ] = F_5 ( V_8 , V_26 ) ;
if ( V_47 [ V_49 ] < 0 ) {
F_7 ( V_8 -> V_28 , L_2 ,
V_26 ) ;
return V_47 [ V_49 ] ;
}
if ( V_20 ) {
V_48 ++ ;
continue;
}
switch ( V_49 ) {
case 10 :
V_47 [ V_49 ] = F_10 ( V_47 [ V_49 ] ) ;
if ( V_47 [ V_49 ] < 0 ) {
F_7 ( V_8 -> V_28 , L_3 ) ;
return V_47 [ V_49 ] ;
} else {
V_48 ++ ;
V_47 [ V_49 ] = V_47 [ V_49 ] - 750 ;
}
break;
case 1 :
V_47 [ V_49 ] = F_8 ( V_47 [ V_49 ] ) ;
if ( V_47 [ V_49 ] < 0 ) {
F_7 ( V_8 -> V_28 , L_4 ) ;
return V_47 [ V_49 ] ;
} else {
V_47 [ V_49 ] -= 3 ;
V_48 ++ ;
}
break;
default:
V_48 ++ ;
V_47 [ V_49 ] = ( V_47 [ V_49 ] * 3 * 1000 *
V_50 [ V_49 ] . V_51 )
/ ( 2 * 1023 *
V_50 [ V_49 ] . V_52 ) ;
}
}
return V_48 ;
}
static int F_13 ( struct V_7 * V_8 , T_1 V_53 )
{
T_1 V_4 ;
int V_11 ;
V_11 = F_9 ( V_27 , & V_4 , V_8 -> V_54 ) ;
if ( V_11 ) {
F_7 ( V_8 -> V_28 , L_5 ,
V_8 -> V_54 ) ;
return V_11 ;
}
V_4 |= ( 1 << V_53 ) ;
V_11 = F_14 ( V_27 , V_4 , V_8 -> V_54 ) ;
if ( V_11 ) {
F_7 ( V_8 -> V_28 ,
L_6 , V_8 -> V_54 ) ;
return V_11 ;
}
return 0 ;
}
static T_3 F_15 ( int V_55 , void * V_56 )
{
struct V_7 * V_8 = V_56 ;
const struct V_57 * V_12 ;
T_1 V_58 , V_59 ;
int V_49 , V_60 , V_11 ;
struct V_9 * V_61 ;
F_16 ( & V_8 -> V_62 ) ;
V_11 = F_9 ( V_27 , & V_58 , V_8 -> V_63 ) ;
if ( V_11 ) {
F_7 ( V_8 -> V_28 , L_7 ,
V_8 -> V_63 ) ;
goto V_64;
}
V_11 = F_9 ( V_27 , & V_59 , V_8 -> V_54 ) ;
if ( V_11 ) {
F_7 ( V_8 -> V_28 , L_5 ,
V_8 -> V_54 ) ;
goto V_64;
}
V_58 &= ~ V_59 ;
for ( V_49 = 0 ; V_49 < V_65 ; V_49 ++ ) {
if ( ! ( V_58 & ( 1 << V_49 ) ) )
continue;
V_11 = F_13 ( V_8 , V_49 ) ;
if ( V_11 < 0 )
F_17 ( V_8 -> V_28 , L_8 , V_49 ) ;
V_8 -> V_66 [ V_49 ] . V_67 = 1 ;
}
for ( V_49 = 0 ; V_49 < V_65 ; V_49 ++ ) {
V_61 = & V_8 -> V_66 [ V_49 ] ;
if ( ! V_61 -> V_67 )
continue;
V_12 = & V_68 [ V_61 -> V_12 ] ;
V_60 = F_11 ( V_8 , V_12 -> V_69 ,
V_61 -> V_16 , V_61 -> V_24 , V_61 -> V_20 ) ;
V_61 -> V_67 = 0 ;
V_61 -> V_18 = 0 ;
}
F_18 ( & V_8 -> V_62 ) ;
return V_70 ;
V_64:
for ( V_49 = 0 ; V_49 < V_65 ; V_49 ++ ) {
V_61 = & V_8 -> V_66 [ V_49 ] ;
if ( V_61 -> V_18 == 0 )
continue;
V_12 = & V_68 [ V_61 -> V_12 ] ;
V_60 = F_11 ( V_8 , V_12 -> V_69 ,
V_61 -> V_16 , V_61 -> V_24 , V_61 -> V_20 ) ;
V_61 -> V_67 = 0 ;
V_61 -> V_18 = 0 ;
}
F_18 ( & V_8 -> V_62 ) ;
return V_70 ;
}
static int F_19 ( struct V_7 * V_8 ,
int V_71 )
{
const struct V_57 * V_12 ;
int V_11 = 0 ;
if ( V_71 != V_15 && V_71 != V_14 )
return - V_72 ;
V_12 = & V_68 [ V_71 ] ;
V_11 = F_14 ( V_27 , V_73 ,
V_12 -> V_74 ) ;
if ( V_11 ) {
F_7 ( V_8 -> V_28 , L_9 ,
V_12 -> V_74 ) ;
return V_11 ;
}
return 0 ;
}
static int F_20 ( struct V_7 * V_8 ,
unsigned int V_75 ,
T_1 V_76 )
{
unsigned long V_77 ;
int V_11 ;
V_77 = V_78 + F_21 ( V_75 ) ;
do {
T_1 V_26 ;
V_11 = F_9 ( V_27 , & V_26 , V_76 ) ;
if ( V_11 ) {
F_7 ( V_8 -> V_28 ,
L_10 ,
V_76 ) ;
return V_11 ;
}
if ( ! ( V_26 & V_79 ) && ( V_26 & V_80 ) )
return 0 ;
F_22 ( 500 , 2000 ) ;
} while ( ! F_23 ( V_78 , V_77 ) );
F_7 ( V_8 -> V_28 , L_11 ) ;
return - V_81 ;
}
static int F_4 ( struct V_9 * V_10 )
{
const struct V_57 * V_12 ;
int V_11 ;
if ( ! V_10 || ! V_82 )
return - V_83 ;
F_16 ( & V_82 -> V_62 ) ;
if ( V_10 -> V_12 < V_84 || V_10 -> V_12 > V_14 ) {
V_11 = - V_83 ;
goto V_85;
}
if ( V_82 -> V_66 [ V_10 -> V_12 ] . V_18 ) {
V_11 = - V_86 ;
goto V_85;
}
V_12 = & V_68 [ V_10 -> V_12 ] ;
V_11 = F_24 ( V_27 , V_10 -> V_16 , V_12 -> V_87 ) ;
if ( V_11 ) {
F_7 ( V_82 -> V_28 ,
L_12 , V_12 -> V_87 ) ;
goto V_85;
}
if ( V_10 -> V_22 ) {
V_11 = F_24 ( V_27 , V_10 -> V_16 ,
V_12 -> V_88 ) ;
if ( V_11 ) {
F_7 ( V_82 -> V_28 ,
L_13 ,
V_12 -> V_88 ) ;
goto V_85;
}
}
if ( V_10 -> V_12 == V_84 ) {
V_11 = - V_83 ;
goto V_85;
}
V_11 = F_19 ( V_82 , V_10 -> V_12 ) ;
if ( V_11 < 0 )
goto V_85;
V_82 -> V_66 [ V_10 -> V_12 ] . V_18 = 1 ;
V_11 = F_20 ( V_82 , 5 , V_12 -> V_74 ) ;
if ( V_11 ) {
V_82 -> V_66 [ V_10 -> V_12 ] . V_18 = 0 ;
goto V_85;
}
V_11 = F_11 ( V_82 , V_12 -> V_69 ,
V_10 -> V_16 , V_10 -> V_24 , V_10 -> V_20 ) ;
V_82 -> V_66 [ V_10 -> V_12 ] . V_18 = 0 ;
V_85:
F_18 ( & V_82 -> V_62 ) ;
return V_11 ;
}
static int F_25 ( struct V_7 * V_8 ,
int V_3 , int V_89 )
{
int V_11 ;
int V_90 ;
T_1 V_91 ;
V_11 = F_9 ( V_36 ,
& V_91 , V_41 ) ;
if ( V_11 ) {
F_7 ( V_8 -> V_28 , L_14 ,
V_41 ) ;
return V_11 ;
}
V_90 = V_3 ? V_92 : V_93 ;
if ( V_89 )
V_91 |= V_90 ;
else
V_91 &= ~ V_90 ;
V_11 = F_14 ( V_36 ,
V_91 , V_41 ) ;
if ( V_11 ) {
F_7 ( V_8 -> V_28 , L_15 ,
V_41 ) ;
return V_11 ;
}
return 0 ;
}
static int F_26 ( struct V_7 * V_8 , int V_89 )
{
T_1 V_91 ;
int V_11 ;
V_11 = F_9 ( V_36 ,
& V_91 , V_94 ) ;
if ( V_11 ) {
F_7 ( V_8 -> V_28 , L_16 ,
V_94 ) ;
return V_11 ;
}
if ( V_89 )
V_91 |= V_95 ;
else
V_91 &= ~ V_95 ;
V_11 = F_14 ( V_27 , V_91 , V_94 ) ;
if ( V_11 ) {
F_7 ( V_8 -> V_28 , L_17 ,
V_94 ) ;
return V_11 ;
}
return 0 ;
}
static int F_27 ( struct V_96 * V_97 )
{
struct V_7 * V_8 ;
struct V_98 * V_99 = F_28 ( & V_97 -> V_28 ) ;
struct V_100 * V_101 = V_97 -> V_28 . V_102 ;
int V_55 , V_11 ;
T_1 V_91 ;
struct V_1 * V_1 = NULL ;
if ( ! V_99 && ! V_101 ) {
F_7 ( & V_97 -> V_28 , L_18 ) ;
return - V_83 ;
}
V_1 = F_29 ( & V_97 -> V_28 , sizeof( * V_8 ) ) ;
if ( ! V_1 ) {
F_7 ( & V_97 -> V_28 , L_19 ) ;
return - V_103 ;
}
V_8 = F_2 ( V_1 ) ;
V_8 -> V_28 = & V_97 -> V_28 ;
V_1 -> V_104 = F_30 ( & V_97 -> V_28 ) ;
V_1 -> V_28 . V_105 = & V_97 -> V_28 ;
V_1 -> V_28 . V_102 = V_97 -> V_28 . V_102 ;
V_1 -> V_106 = & V_107 ;
V_1 -> V_108 = V_109 ;
V_1 -> V_16 = V_110 ;
V_1 -> V_111 = F_31 ( V_110 ) ;
if ( V_99 )
V_8 -> V_13 = ( V_99 -> V_112 != 1 ) ;
else
V_8 -> V_13 = F_32 ( V_101 ,
L_20 ) ;
V_8 -> V_54 = V_8 -> V_13 ? V_113 :
V_114 ;
V_8 -> V_63 = V_8 -> V_13 ? V_115 :
V_116 ;
V_11 = F_26 ( V_8 , 1 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_25 ( V_8 , 0 , 1 ) ;
if ( V_11 < 0 )
goto V_117;
V_11 = F_9 ( V_36 ,
& V_91 , V_41 ) ;
if ( V_11 ) {
F_7 ( & V_97 -> V_28 , L_21 ,
V_41 ) ;
goto V_64;
}
V_91 |= V_118 ;
V_11 = F_14 ( V_36 ,
V_91 , V_41 ) ;
if ( V_11 ) {
F_7 ( & V_97 -> V_28 , L_22 ,
V_41 ) ;
goto V_64;
}
V_11 = F_9 ( V_119 , & V_91 , V_120 ) ;
if ( V_11 ) {
F_7 ( & V_97 -> V_28 , L_23 ,
V_120 ) ;
goto V_64;
}
if ( ! ( V_91 & V_121 ) ) {
F_33 ( & V_97 -> V_28 , L_24 ) ;
V_91 |= V_121 ;
V_11 = F_14 ( V_119 , V_91 ,
V_120 ) ;
if ( V_11 ) {
F_7 ( & V_97 -> V_28 , L_25 ,
V_120 ) ;
goto V_64;
}
}
F_34 ( V_97 , V_1 ) ;
F_35 ( & V_8 -> V_62 ) ;
V_55 = F_36 ( V_97 , 0 ) ;
V_11 = F_37 ( & V_97 -> V_28 , V_55 , NULL ,
F_15 ,
V_122 | V_123 ,
L_26 , V_8 ) ;
if ( V_11 ) {
F_7 ( & V_97 -> V_28 , L_27 ) ;
goto V_64;
}
V_82 = V_8 ;
V_11 = F_9 ( V_124 , & V_91 ,
V_125 ) ;
if ( V_11 ) {
F_7 ( & V_97 -> V_28 , L_28 ,
V_125 ) ;
goto V_64;
}
V_91 |= V_126 ;
V_11 = F_14 ( V_124 , V_91 ,
V_125 ) ;
if ( V_11 ) {
F_7 ( & V_97 -> V_28 , L_29 ,
V_125 ) ;
goto V_64;
}
V_8 -> V_127 = F_38 ( V_8 -> V_28 , L_30 ) ;
if ( F_39 ( V_8 -> V_127 ) )
return - V_128 ;
V_11 = F_40 ( V_8 -> V_127 ) ;
if ( V_11 )
F_7 ( V_8 -> V_28 , L_31 ) ;
V_11 = F_41 ( V_1 ) ;
if ( V_11 ) {
F_7 ( & V_97 -> V_28 , L_32 ) ;
goto V_64;
}
return 0 ;
V_64:
F_25 ( V_8 , 0 , 0 ) ;
V_117:
F_26 ( V_8 , 0 ) ;
return V_11 ;
}
static int F_42 ( struct V_96 * V_97 )
{
struct V_1 * V_1 = F_43 ( V_97 ) ;
struct V_7 * V_8 = F_2 ( V_1 ) ;
F_44 ( V_1 ) ;
F_25 ( V_8 , 0 , 0 ) ;
F_26 ( V_8 , 0 ) ;
F_45 ( V_8 -> V_127 ) ;
return 0 ;
}
