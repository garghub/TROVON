static int F_1 ( struct V_1 * V_1 ,
const struct V_2 * V_3 ,
int * V_4 , int * V_5 , long V_6 )
{
struct V_7 * V_8 = F_2 ( V_1 ) ;
int V_9 ;
if ( V_6 != V_10 )
return - V_11 ;
if ( V_3 -> V_12 > V_13 )
return - V_11 ;
V_9 = F_3 ( & V_8 -> V_14 ) ;
if ( ! V_9 )
return - V_15 ;
F_4 ( V_8 -> V_16 ) ;
F_5 ( V_17 ,
V_8 -> V_18 + V_19 + V_20 ) ;
F_5 ( 0xff , V_8 -> V_18 + V_21 + V_20 ) ;
F_5 ( V_3 -> V_12 , V_8 -> V_18 + V_22 ) ;
F_5 ( 0 , V_8 -> V_18 + F_6 ( 0 ) ) ;
F_5 ( F_7 ( 0 ) ,
V_8 -> V_18 + V_19 + V_23 ) ;
F_5 ( 1 << 0 , V_8 -> V_18 + V_21 + V_23 ) ;
V_9 = F_8 ( & V_8 -> V_16 , V_24 ) ;
if ( ! V_9 )
V_9 = - V_25 ;
if ( V_9 < 0 )
goto V_26;
* V_4 = F_9 ( V_8 -> V_18 + F_6 ( 0 ) ) & V_27 ;
V_9 = V_28 ;
V_26:
F_5 ( F_7 ( 0 ) ,
V_8 -> V_18 + V_19 + V_20 ) ;
F_10 ( & V_8 -> V_14 ) ;
return V_9 ;
}
static T_1 F_11 ( int V_29 , void * V_30 )
{
struct V_1 * V_31 = V_30 ;
struct V_7 * V_8 = F_2 ( V_31 ) ;
unsigned long V_32 = F_9 ( V_8 -> V_18 + V_19 ) ;
if ( ! ( V_32 & V_33 ) )
return V_34 ;
if ( F_12 ( V_31 ) )
F_13 ( V_31 -> V_35 , F_14 () ) ;
else if ( V_32 & F_15 ( 0 ) )
F_16 ( & V_8 -> V_16 ) ;
F_5 ( V_32 & V_33 ,
V_8 -> V_18 + V_19 + V_20 ) ;
return V_36 ;
}
static T_1 F_17 ( int V_29 , void * V_37 )
{
struct V_38 * V_39 = V_37 ;
struct V_1 * V_31 = V_39 -> V_40 ;
struct V_7 * V_8 = F_2 ( V_31 ) ;
struct V_41 * V_42 = V_31 -> V_42 ;
const T_2 V_43 = V_44 |
( ( V_45 - 1 ) << V_46 ) ;
int V_47 , V_48 = 0 ;
F_18 (i, iio->active_scan_mask, iio->masklength) {
V_8 -> V_42 [ V_48 ] = F_9 ( V_8 -> V_18 + F_6 ( V_48 ) ) ;
F_5 ( V_43 , V_8 -> V_18 + F_6 ( V_48 ) ) ;
V_8 -> V_42 [ V_48 ] &= V_27 ;
V_8 -> V_42 [ V_48 ] /= V_45 ;
V_48 ++ ;
}
if ( V_31 -> V_49 ) {
T_3 * V_50 = ( T_3 * ) ( ( V_51 * ) V_8 -> V_42 +
F_19 ( V_48 , sizeof( T_3 ) ) ) ;
* V_50 = V_39 -> V_50 ;
}
F_20 ( V_42 , ( V_51 * ) V_8 -> V_42 ) ;
F_21 ( V_31 -> V_35 ) ;
return V_36 ;
}
static int F_22 ( struct V_52 * V_35 , bool V_53 )
{
struct V_1 * V_31 = V_35 -> V_54 ;
struct V_7 * V_8 = F_2 ( V_31 ) ;
const T_2 V_55 = V_53 ? V_23 : V_20 ;
F_5 ( V_56 , V_8 -> V_18 + F_23 ( 0 ) + V_55 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_31 )
{
int V_9 ;
struct V_52 * V_35 ;
V_35 = F_25 ( L_1 , V_31 -> V_57 , V_31 -> V_58 ) ;
if ( V_35 == NULL )
return - V_59 ;
V_35 -> V_60 . V_61 = V_31 -> V_60 . V_61 ;
V_35 -> V_54 = V_31 ;
V_35 -> V_62 = & V_63 ;
V_9 = F_26 ( V_35 ) ;
if ( V_9 ) {
F_27 ( V_35 ) ;
return V_9 ;
}
V_31 -> V_35 = V_35 ;
return 0 ;
}
static void F_28 ( struct V_1 * V_31 )
{
F_29 ( V_31 -> V_35 ) ;
F_27 ( V_31 -> V_35 ) ;
}
static int F_30 ( struct V_1 * V_31 )
{
struct V_7 * V_8 = F_2 ( V_31 ) ;
struct V_41 * V_42 = V_31 -> V_42 ;
int V_9 = 0 , V_3 , V_64 = 0 , V_65 = 0 ;
T_2 V_66 = 0 ;
T_2 V_67 = 0 ;
const T_2 V_43 = V_44 |
( ( V_45 - 1 ) << V_46 ) ;
const int V_68 = F_31 ( V_42 -> V_69 , V_13 ) ;
if ( ! V_68 )
return - V_11 ;
V_9 = F_3 ( & V_8 -> V_14 ) ;
if ( ! V_9 )
return - V_15 ;
V_8 -> V_42 = F_32 ( V_68 * sizeof( * V_8 -> V_42 ) , V_70 ) ;
if ( ! V_8 -> V_42 ) {
V_9 = - V_59 ;
goto V_71;
}
V_9 = F_33 ( V_31 ) ;
if ( V_9 < 0 )
goto V_72;
F_5 ( V_17 ,
V_8 -> V_18 + V_19 + V_20 ) ;
F_5 ( 0xff , V_8 -> V_18 + V_21 + V_20 ) ;
F_18 (chan, buffer->scan_mask, LRADC_MAX_TOTAL_CHANS) {
V_66 |= V_3 << F_34 ( V_64 ) ;
V_67 |= F_7 ( V_64 ) ;
F_5 ( V_43 , V_8 -> V_18 + F_6 ( V_64 ) ) ;
V_65 |= 1 << V_64 ;
V_64 ++ ;
} ;
F_5 ( V_73 | V_56 ,
V_8 -> V_18 + F_23 ( 0 ) + V_20 ) ;
F_5 ( V_66 , V_8 -> V_18 + V_22 ) ;
F_5 ( V_67 , V_8 -> V_18 + V_19 + V_23 ) ;
F_5 ( V_65 << V_74 ,
V_8 -> V_18 + F_23 ( 0 ) + V_23 ) ;
return 0 ;
V_72:
F_35 ( V_8 -> V_42 ) ;
V_71:
F_10 ( & V_8 -> V_14 ) ;
return V_9 ;
}
static int F_36 ( struct V_1 * V_31 )
{
struct V_7 * V_8 = F_2 ( V_31 ) ;
F_5 ( V_73 | V_56 ,
V_8 -> V_18 + F_23 ( 0 ) + V_20 ) ;
F_5 ( 0xff , V_8 -> V_18 + V_21 + V_20 ) ;
F_5 ( V_17 ,
V_8 -> V_18 + V_19 + V_20 ) ;
F_35 ( V_8 -> V_42 ) ;
F_10 ( & V_8 -> V_14 ) ;
return 0 ;
}
static bool F_37 ( struct V_1 * V_31 ,
const unsigned long * V_75 )
{
const int V_76 = F_31 ( V_75 , V_31 -> V_77 ) ;
return V_76 <= V_78 ;
}
static void F_38 ( struct V_7 * V_8 )
{
int V_47 ;
const T_2 V_79 =
( V_80 << V_81 ) ;
F_39 ( V_8 -> V_18 ) ;
for ( V_47 = 0 ; V_47 < V_82 ; V_47 ++ )
F_5 ( V_79 | ( 1 << ( V_83 + V_47 ) ) ,
V_8 -> V_18 + F_23 ( V_47 ) ) ;
F_5 ( 0 , V_8 -> V_18 + V_84 ) ;
}
static void F_40 ( struct V_7 * V_8 )
{
int V_47 ;
F_5 ( V_17 ,
V_8 -> V_18 + V_19 + V_20 ) ;
for ( V_47 = 0 ; V_47 < V_82 ; V_47 ++ )
F_5 ( 0 , V_8 -> V_18 + F_23 ( V_47 ) ) ;
}
static int T_4 F_41 ( struct V_85 * V_86 )
{
struct V_87 * V_60 = & V_86 -> V_60 ;
struct V_7 * V_8 ;
struct V_1 * V_31 ;
struct V_88 * V_89 ;
int V_9 = 0 ;
int V_47 ;
V_31 = F_42 ( sizeof( * V_8 ) ) ;
if ( ! V_31 ) {
F_43 ( V_60 , L_2 ) ;
return - V_59 ;
}
V_8 = F_2 ( V_31 ) ;
V_89 = F_44 ( V_86 , V_90 , 0 ) ;
V_8 -> V_60 = & V_86 -> V_60 ;
V_8 -> V_18 = F_45 ( V_60 , V_89 ) ;
if ( ! V_8 -> V_18 ) {
V_9 = - V_91 ;
goto V_92;
}
for ( V_47 = 0 ; V_47 < 13 ; V_47 ++ ) {
V_8 -> V_29 [ V_47 ] = F_46 ( V_86 , V_47 ) ;
if ( V_8 -> V_29 [ V_47 ] < 0 ) {
V_9 = - V_11 ;
goto V_92;
}
V_9 = F_47 ( V_60 , V_8 -> V_29 [ V_47 ] ,
F_11 , 0 ,
V_93 [ V_47 ] , V_31 ) ;
if ( V_9 )
goto V_92;
}
F_48 ( V_86 , V_31 ) ;
F_49 ( & V_8 -> V_16 ) ;
F_50 ( & V_8 -> V_14 ) ;
V_31 -> V_57 = V_86 -> V_57 ;
V_31 -> V_60 . V_61 = & V_86 -> V_60 ;
V_31 -> V_94 = & V_95 ;
V_31 -> V_96 = V_97 ;
V_31 -> V_98 = V_99 ;
V_31 -> V_100 = F_51 ( V_99 ) ;
V_9 = F_52 ( V_31 , & V_101 ,
& F_17 ,
& V_102 ) ;
if ( V_9 )
goto V_92;
V_9 = F_24 ( V_31 ) ;
if ( V_9 )
goto V_103;
V_9 = F_53 ( V_31 ) ;
if ( V_9 ) {
F_43 ( V_60 , L_3 ) ;
goto V_104;
}
F_38 ( V_8 ) ;
return 0 ;
V_104:
F_28 ( V_31 ) ;
V_103:
F_54 ( V_31 ) ;
V_92:
F_55 ( V_31 ) ;
return V_9 ;
}
static int T_5 F_56 ( struct V_85 * V_86 )
{
struct V_1 * V_31 = F_57 ( V_86 ) ;
struct V_7 * V_8 = F_2 ( V_31 ) ;
F_40 ( V_8 ) ;
F_58 ( V_31 ) ;
F_54 ( V_31 ) ;
F_28 ( V_31 ) ;
F_55 ( V_31 ) ;
return 0 ;
}
