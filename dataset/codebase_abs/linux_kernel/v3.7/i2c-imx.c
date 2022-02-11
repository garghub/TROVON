static int F_1 ( struct V_1 * V_2 , int V_3 )
{
unsigned long V_4 = V_5 ;
unsigned int V_6 ;
F_2 ( & V_2 -> V_7 . V_8 , L_1 , V_9 ) ;
while ( 1 ) {
V_6 = F_3 ( V_2 -> V_10 + V_11 ) ;
if ( V_3 && ( V_6 & V_12 ) )
break;
if ( ! V_3 && ! ( V_6 & V_12 ) )
break;
if ( F_4 ( V_5 , V_4 + F_5 ( 500 ) ) ) {
F_2 ( & V_2 -> V_7 . V_8 ,
L_2 , V_9 ) ;
return - V_13 ;
}
F_6 () ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 -> V_14 , V_2 -> V_15 & V_16 , V_17 / 10 ) ;
if ( F_9 ( ! ( V_2 -> V_15 & V_16 ) ) ) {
F_2 ( & V_2 -> V_7 . V_8 , L_3 , V_9 ) ;
return - V_13 ;
}
F_2 ( & V_2 -> V_7 . V_8 , L_4 , V_9 ) ;
V_2 -> V_15 = 0 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
if ( F_3 ( V_2 -> V_10 + V_11 ) & V_18 ) {
F_2 ( & V_2 -> V_7 . V_8 , L_5 , V_9 ) ;
return - V_19 ;
}
F_2 ( & V_2 -> V_7 . V_8 , L_6 , V_9 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
unsigned int V_6 = 0 ;
int V_20 ;
F_2 ( & V_2 -> V_7 . V_8 , L_1 , V_9 ) ;
F_12 ( V_2 -> V_21 ) ;
F_13 ( V_2 -> V_22 , V_2 -> V_10 + V_23 ) ;
F_13 ( 0 , V_2 -> V_10 + V_11 ) ;
F_13 ( V_24 , V_2 -> V_10 + V_25 ) ;
F_14 ( 50 ) ;
V_6 = F_3 ( V_2 -> V_10 + V_25 ) ;
V_6 |= V_26 ;
F_13 ( V_6 , V_2 -> V_10 + V_25 ) ;
V_20 = F_1 ( V_2 , 1 ) ;
if ( V_20 )
return V_20 ;
V_2 -> V_27 = 0 ;
V_6 |= V_28 | V_29 | V_30 ;
F_13 ( V_6 , V_2 -> V_10 + V_25 ) ;
return V_20 ;
}
static void F_15 ( struct V_1 * V_2 )
{
unsigned int V_6 = 0 ;
if ( ! V_2 -> V_27 ) {
F_2 ( & V_2 -> V_7 . V_8 , L_1 , V_9 ) ;
V_6 = F_3 ( V_2 -> V_10 + V_25 ) ;
V_6 &= ~ ( V_26 | V_29 ) ;
F_13 ( V_6 , V_2 -> V_10 + V_25 ) ;
}
if ( F_16 () ) {
F_14 ( V_2 -> V_31 ) ;
}
if ( ! V_2 -> V_27 ) {
F_1 ( V_2 , 0 ) ;
V_2 -> V_27 = 1 ;
}
F_13 ( 0 , V_2 -> V_10 + V_25 ) ;
F_17 ( V_2 -> V_21 ) ;
}
static void T_1 F_18 ( struct V_1 * V_2 ,
unsigned int V_32 )
{
unsigned int V_33 ;
unsigned int div ;
int V_34 ;
V_33 = F_19 ( V_2 -> V_21 ) ;
div = ( V_33 + V_32 - 1 ) / V_32 ;
if ( div < V_35 [ 0 ] [ 0 ] )
V_34 = 0 ;
else if ( div > V_35 [ F_20 ( V_35 ) - 1 ] [ 0 ] )
V_34 = F_20 ( V_35 ) - 1 ;
else
for ( V_34 = 0 ; V_35 [ V_34 ] [ 0 ] < div ; V_34 ++ ) ;
V_2 -> V_22 = V_35 [ V_34 ] [ 1 ] ;
V_2 -> V_31 = ( 500000U * V_35 [ V_34 ] [ 0 ]
+ ( V_33 / 2 ) - 1 ) / ( V_33 / 2 ) ;
#ifdef F_21
F_2 ( & V_2 -> V_7 . V_8 , L_7 ,
V_9 , V_33 , div ) ;
F_2 ( & V_2 -> V_7 . V_8 , L_8 ,
V_9 , V_35 [ V_34 ] [ 1 ] , V_35 [ V_34 ] [ 0 ] ) ;
#endif
}
static T_2 F_22 ( int V_36 , void * V_37 )
{
struct V_1 * V_2 = V_37 ;
unsigned int V_6 ;
V_6 = F_3 ( V_2 -> V_10 + V_11 ) ;
if ( V_6 & V_16 ) {
V_2 -> V_15 = V_6 ;
V_6 &= ~ V_16 ;
F_13 ( V_6 , V_2 -> V_10 + V_11 ) ;
F_23 ( & V_2 -> V_14 ) ;
return V_38 ;
}
return V_39 ;
}
static int F_24 ( struct V_1 * V_2 , struct V_40 * V_41 )
{
int V_34 , V_20 ;
F_2 ( & V_2 -> V_7 . V_8 , L_9 ,
V_9 , V_41 -> V_42 << 1 ) ;
F_13 ( V_41 -> V_42 << 1 , V_2 -> V_10 + V_43 ) ;
V_20 = F_7 ( V_2 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_10 ( V_2 ) ;
if ( V_20 )
return V_20 ;
F_2 ( & V_2 -> V_7 . V_8 , L_10 , V_9 ) ;
for ( V_34 = 0 ; V_34 < V_41 -> V_44 ; V_34 ++ ) {
F_2 ( & V_2 -> V_7 . V_8 ,
L_11 ,
V_9 , V_34 , V_41 -> V_45 [ V_34 ] ) ;
F_13 ( V_41 -> V_45 [ V_34 ] , V_2 -> V_10 + V_43 ) ;
V_20 = F_7 ( V_2 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_10 ( V_2 ) ;
if ( V_20 )
return V_20 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_40 * V_41 )
{
int V_34 , V_20 ;
unsigned int V_6 ;
F_2 ( & V_2 -> V_7 . V_8 ,
L_9 ,
V_9 , ( V_41 -> V_42 << 1 ) | 0x01 ) ;
F_13 ( ( V_41 -> V_42 << 1 ) | 0x01 , V_2 -> V_10 + V_43 ) ;
V_20 = F_7 ( V_2 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_10 ( V_2 ) ;
if ( V_20 )
return V_20 ;
F_2 ( & V_2 -> V_7 . V_8 , L_12 , V_9 ) ;
V_6 = F_3 ( V_2 -> V_10 + V_25 ) ;
V_6 &= ~ V_29 ;
if ( V_41 -> V_44 - 1 )
V_6 &= ~ V_30 ;
F_13 ( V_6 , V_2 -> V_10 + V_25 ) ;
F_3 ( V_2 -> V_10 + V_43 ) ;
F_2 ( & V_2 -> V_7 . V_8 , L_13 , V_9 ) ;
for ( V_34 = 0 ; V_34 < V_41 -> V_44 ; V_34 ++ ) {
V_20 = F_7 ( V_2 ) ;
if ( V_20 )
return V_20 ;
if ( V_34 == ( V_41 -> V_44 - 1 ) ) {
F_2 ( & V_2 -> V_7 . V_8 ,
L_14 , V_9 ) ;
V_6 = F_3 ( V_2 -> V_10 + V_25 ) ;
V_6 &= ~ ( V_26 | V_29 ) ;
F_13 ( V_6 , V_2 -> V_10 + V_25 ) ;
F_1 ( V_2 , 0 ) ;
V_2 -> V_27 = 1 ;
} else if ( V_34 == ( V_41 -> V_44 - 2 ) ) {
F_2 ( & V_2 -> V_7 . V_8 ,
L_15 , V_9 ) ;
V_6 = F_3 ( V_2 -> V_10 + V_25 ) ;
V_6 |= V_30 ;
F_13 ( V_6 , V_2 -> V_10 + V_25 ) ;
}
V_41 -> V_45 [ V_34 ] = F_3 ( V_2 -> V_10 + V_43 ) ;
F_2 ( & V_2 -> V_7 . V_8 ,
L_16 ,
V_9 , V_34 , V_41 -> V_45 [ V_34 ] ) ;
}
return 0 ;
}
static int F_26 ( struct V_46 * V_7 ,
struct V_40 * V_41 , int V_47 )
{
unsigned int V_34 , V_6 ;
int V_20 ;
struct V_1 * V_2 = F_27 ( V_7 ) ;
F_2 ( & V_2 -> V_7 . V_8 , L_1 , V_9 ) ;
V_20 = F_11 ( V_2 ) ;
if ( V_20 )
goto V_48;
for ( V_34 = 0 ; V_34 < V_47 ; V_34 ++ ) {
if ( V_34 ) {
F_2 ( & V_2 -> V_7 . V_8 ,
L_17 , V_9 ) ;
V_6 = F_3 ( V_2 -> V_10 + V_25 ) ;
V_6 |= V_49 ;
F_13 ( V_6 , V_2 -> V_10 + V_25 ) ;
V_20 = F_1 ( V_2 , 1 ) ;
if ( V_20 )
goto V_48;
}
F_2 ( & V_2 -> V_7 . V_8 ,
L_18 , V_9 , V_34 ) ;
#ifdef F_21
V_6 = F_3 ( V_2 -> V_10 + V_25 ) ;
F_2 ( & V_2 -> V_7 . V_8 , L_19
L_20 , V_9 ,
( V_6 & V_24 ? 1 : 0 ) , ( V_6 & V_28 ? 1 : 0 ) ,
( V_6 & V_26 ? 1 : 0 ) , ( V_6 & V_29 ? 1 : 0 ) ,
( V_6 & V_30 ? 1 : 0 ) , ( V_6 & V_49 ? 1 : 0 ) ) ;
V_6 = F_3 ( V_2 -> V_10 + V_11 ) ;
F_2 ( & V_2 -> V_7 . V_8 ,
L_21
L_22 , V_9 ,
( V_6 & V_50 ? 1 : 0 ) , ( V_6 & V_51 ? 1 : 0 ) ,
( V_6 & V_12 ? 1 : 0 ) , ( V_6 & V_52 ? 1 : 0 ) ,
( V_6 & V_53 ? 1 : 0 ) , ( V_6 & V_16 ? 1 : 0 ) ,
( V_6 & V_18 ? 1 : 0 ) ) ;
#endif
if ( V_41 [ V_34 ] . V_54 & V_55 )
V_20 = F_25 ( V_2 , & V_41 [ V_34 ] ) ;
else
V_20 = F_24 ( V_2 , & V_41 [ V_34 ] ) ;
if ( V_20 )
goto V_48;
}
V_48:
F_15 ( V_2 ) ;
F_2 ( & V_2 -> V_7 . V_8 , L_23 , V_9 ,
( V_20 < 0 ) ? L_24 : L_25 ,
( V_20 < 0 ) ? V_20 : V_47 ) ;
return ( V_20 < 0 ) ? V_20 : V_47 ;
}
static T_3 F_28 ( struct V_46 * V_7 )
{
return V_56 | V_57 ;
}
static int T_1 F_29 ( struct V_58 * V_59 )
{
struct V_1 * V_2 ;
struct V_60 * V_61 ;
struct V_62 * V_63 = V_59 -> V_8 . V_64 ;
struct V_65 * V_65 ;
void T_4 * V_10 ;
int V_36 , V_66 ;
T_3 V_67 ;
F_2 ( & V_59 -> V_8 , L_1 , V_9 ) ;
V_61 = F_30 ( V_59 , V_68 , 0 ) ;
if ( ! V_61 ) {
F_31 ( & V_59 -> V_8 , L_26 ) ;
return - V_69 ;
}
V_36 = F_32 ( V_59 , 0 ) ;
if ( V_36 < 0 ) {
F_31 ( & V_59 -> V_8 , L_27 ) ;
return - V_69 ;
}
V_10 = F_33 ( & V_59 -> V_8 , V_61 ) ;
if ( ! V_10 )
return - V_70 ;
V_2 = F_34 ( & V_59 -> V_8 , sizeof( struct V_1 ) ,
V_71 ) ;
if ( ! V_2 ) {
F_31 ( & V_59 -> V_8 , L_28 ) ;
return - V_72 ;
}
F_35 ( V_2 -> V_7 . V_73 , V_59 -> V_73 , sizeof( V_2 -> V_7 . V_73 ) ) ;
V_2 -> V_7 . V_74 = V_75 ;
V_2 -> V_7 . V_76 = & V_77 ;
V_2 -> V_7 . V_8 . V_78 = & V_59 -> V_8 ;
V_2 -> V_7 . V_79 = V_59 -> V_80 ;
V_2 -> V_7 . V_8 . V_81 = V_59 -> V_8 . V_81 ;
V_2 -> V_10 = V_10 ;
V_65 = F_36 ( & V_59 -> V_8 ) ;
if ( F_37 ( V_65 ) ) {
F_31 ( & V_59 -> V_8 , L_29 ) ;
return F_38 ( V_65 ) ;
}
V_2 -> V_21 = F_39 ( & V_59 -> V_8 , NULL ) ;
if ( F_37 ( V_2 -> V_21 ) ) {
F_31 ( & V_59 -> V_8 , L_30 ) ;
return F_38 ( V_2 -> V_21 ) ;
}
V_66 = F_40 ( & V_59 -> V_8 , V_36 , F_22 , 0 ,
V_59 -> V_73 , V_2 ) ;
if ( V_66 ) {
F_31 ( & V_59 -> V_8 , L_31 , V_36 ) ;
return V_66 ;
}
F_41 ( & V_2 -> V_14 ) ;
F_42 ( & V_2 -> V_7 , V_2 ) ;
V_67 = V_82 ;
V_66 = F_43 ( V_59 -> V_8 . V_81 ,
L_32 , & V_67 ) ;
if ( V_66 < 0 && V_63 && V_63 -> V_67 )
V_67 = V_63 -> V_67 ;
F_18 ( V_2 , V_67 ) ;
F_13 ( 0 , V_2 -> V_10 + V_25 ) ;
F_13 ( 0 , V_2 -> V_10 + V_11 ) ;
V_66 = F_44 ( & V_2 -> V_7 ) ;
if ( V_66 < 0 ) {
F_31 ( & V_59 -> V_8 , L_33 ) ;
return V_66 ;
}
F_45 ( & V_2 -> V_7 ) ;
F_46 ( V_59 , V_2 ) ;
F_2 ( & V_2 -> V_7 . V_8 , L_34 , V_36 ) ;
F_2 ( & V_2 -> V_7 . V_8 , L_35 ,
V_61 -> V_83 , V_61 -> V_84 ) ;
F_2 ( & V_2 -> V_7 . V_8 , L_36 ,
F_47 ( V_61 ) , V_61 -> V_83 ) ;
F_2 ( & V_2 -> V_7 . V_8 , L_37 ,
V_2 -> V_7 . V_73 ) ;
F_48 ( & V_2 -> V_7 . V_8 , L_38 ) ;
return 0 ;
}
static int T_5 F_49 ( struct V_58 * V_59 )
{
struct V_1 * V_2 = F_50 ( V_59 ) ;
F_2 ( & V_2 -> V_7 . V_8 , L_39 ) ;
F_51 ( & V_2 -> V_7 ) ;
F_46 ( V_59 , NULL ) ;
F_13 ( 0 , V_2 -> V_10 + V_85 ) ;
F_13 ( 0 , V_2 -> V_10 + V_23 ) ;
F_13 ( 0 , V_2 -> V_10 + V_25 ) ;
F_13 ( 0 , V_2 -> V_10 + V_11 ) ;
return 0 ;
}
static int T_1 F_52 ( void )
{
return F_53 ( & V_86 , F_29 ) ;
}
static void T_5 F_54 ( void )
{
F_55 ( & V_86 ) ;
}
