static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
int V_10 = 0 , V_11 = 0 , V_12 = 0 ;
if ( ! V_8 ) {
F_2 ( V_2 -> V_13 ,
L_1 ) ;
return - V_14 ;
}
V_12 = F_3 ( V_8 ,
V_15 ,
V_16 ,
V_16 ) ;
if ( V_12 < 0 )
goto V_17;
V_12 = F_3 ( V_8 , V_18 ,
V_19 , V_19 ) ;
if ( V_12 < 0 )
goto V_17;
V_12 = F_3 ( V_8 , V_20 ,
( V_21 | V_22 ) ,
( V_21 | V_22 ) ) ;
if ( V_12 < 0 )
goto V_17;
V_11 = ( V_23 | V_24 |
V_25 | V_26 ) ;
if ( V_4 && ( V_4 -> V_27 == 0 ) )
V_10 = ( V_23 | V_24 |
V_25 | V_26 ) ;
else
V_10 = ( V_23 | V_25 |
V_26 ) ;
V_12 = F_3 ( V_8 , V_28 , V_11 , V_10 ) ;
if ( V_12 < 0 )
goto V_17;
F_4 ( V_2 -> V_13 , L_2 ) ;
return 0 ;
V_17:
F_4 ( V_2 -> V_13 , L_3 ) ;
return V_12 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_7 ;
unsigned long V_29 = V_30 | V_31 ;
int V_10 , V_11 , V_12 = - V_14 ;
if ( ! V_8 || ! V_2 -> V_32 ) {
F_6 ( V_2 -> V_13 , L_4 ) ;
return - V_14 ;
}
V_11 =
V_33 | V_34 |
V_35 ;
V_10 = V_34 ;
V_12 = F_3 ( V_8 , V_36 , V_11 , V_10 ) ;
if ( V_12 < 0 )
goto V_17;
V_12 =
F_7 ( V_2 -> V_7 , V_2 -> V_32 , V_29 , - 1 ,
V_2 -> V_37 , & V_2 -> V_38 ) ;
V_17:
return V_12 ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_32 , V_2 -> V_38 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_39 * V_40 = V_2 -> V_40 ;
V_6 = V_2 -> V_6 ;
if ( V_6 -> V_41 ) {
V_6 -> V_42 =
F_11 ( V_40 -> V_43 , V_6 -> V_41 ) ;
V_6 -> V_44 =
F_12 ( V_6 -> V_42 ,
& V_45 ) ;
F_13 ( V_6 -> V_42 , V_2 ) ;
} else
F_4 ( V_2 -> V_13 ,
L_5 ) ;
if ( V_6 -> V_46 ) {
V_6 -> V_47 = F_11 ( V_40 -> V_43 ,
V_6 -> V_46 ) ;
V_6 -> V_9 =
F_12 ( V_6 -> V_47 ,
& V_45 ) ;
F_13 ( V_6 -> V_47 , V_2 ) ;
} else
F_4 ( V_2 -> V_13 ,
L_6 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
F_15 ( V_2 -> V_7 ) ;
F_16 ( V_2 -> V_40 ) ;
V_6 = V_2 -> V_6 ;
if ( V_6 -> V_42 ) {
F_15 ( V_6 -> V_44 ) ;
F_16 ( V_6 -> V_42 ) ;
}
if ( V_6 -> V_47 ) {
F_15 ( V_6 -> V_9 ) ;
F_16 ( V_6 -> V_47 ) ;
}
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_12 , V_48 ;
unsigned int V_49 ;
V_12 = F_18 ( V_2 -> V_7 , V_50 , & V_49 ) ;
if ( V_12 < 0 ) {
F_6 ( V_2 -> V_13 , L_7 , V_12 ) ;
goto V_17;
}
V_48 = V_49 & V_51 ;
if ( ( V_48 >= V_52 ) && ( V_48 <= V_53 ) ) {
V_2 -> V_54 = V_49 ;
F_4 ( V_2 -> V_13 ,
L_8 , V_49 ) ;
} else {
F_6 ( V_2 -> V_13 ,
L_9 , V_49 ) ;
V_12 = - V_14 ;
goto V_17;
}
V_12 = F_18 ( V_2 -> V_7 , V_55 , & V_49 ) ;
if ( V_12 < 0 ) {
F_6 ( V_2 -> V_13 , L_10 , V_12 ) ;
goto V_17;
}
if ( V_49 & V_56 ) {
if ( V_4 && V_4 -> V_57 )
V_4 -> V_57 -> V_58 = 1 ;
}
V_12 = F_1 ( V_2 , V_4 ) ;
if ( V_12 < 0 ) {
F_6 ( V_2 -> V_13 , L_11 , V_59 ) ;
goto V_17;
}
V_2 -> V_37 = & V_60 ;
V_12 = F_5 ( V_2 ) ;
if ( V_12 < 0 ) {
F_6 ( V_2 -> V_13 , L_12 , V_59 ) ;
goto V_17;
}
V_12 =
F_19 ( V_2 -> V_13 , 0 , & V_61 [ 0 ] ,
F_20 ( V_61 ) , & V_62 [ 0 ] , 0 ,
NULL ) ;
if ( V_12 < 0 ) {
F_6 ( V_2 -> V_13 , L_13 ) ;
goto V_63;
} else
F_4 ( V_2 -> V_13 , L_14 , V_59 ) ;
if ( V_4 && V_4 -> V_57 ) {
V_64 [ 0 ] . V_65 = V_4 -> V_57 ;
V_64 [ 0 ] . V_66 = sizeof( struct V_67 ) ;
V_12 = F_19 ( V_2 -> V_13 , 0 , & V_64 [ 0 ] ,
F_20 ( V_64 ) , NULL , 0 , NULL ) ;
if ( V_12 < 0 ) {
F_6 ( V_2 -> V_13 , L_15 ) ;
goto V_63;
} else
F_4 ( V_2 -> V_13 ,
L_16 , V_59 ) ;
}
return 0 ;
V_63:
F_21 ( V_2 -> V_13 ) ;
F_8 ( V_2 ) ;
V_17:
return V_12 ;
}
static int F_22 ( struct V_39 * V_40 ,
const struct V_68 * V_69 )
{
int V_12 = 0 ;
struct V_1 * V_2 ;
struct V_3 * V_4 = V_40 -> V_13 . V_65 ;
struct V_5 * V_6 ;
V_12 = F_23 ( V_40 , V_69 ) ;
if ( V_12 ) {
F_6 ( & V_40 -> V_13 , L_17 ) ;
goto V_70;
}
V_2 = F_24 ( V_40 ) ;
V_6 =
F_25 ( & V_40 -> V_13 , sizeof( struct V_5 ) ,
V_71 ) ;
if ( ! V_6 ) {
V_12 = - V_72 ;
goto V_73;
}
V_6 -> V_41 = V_4 -> V_41 ;
V_6 -> V_46 = V_4 -> V_46 ;
V_2 -> V_6 = V_6 ;
V_12 = F_17 ( V_2 , V_4 ) ;
if ( V_12 ) {
F_6 ( V_2 -> V_13 , L_18 , V_59 , V_2 -> V_69 ) ;
goto V_73;
}
V_12 = F_10 ( V_2 ) ;
if ( V_12 ) {
F_6 ( & V_40 -> V_13 , L_19 ) ;
goto V_74;
}
if ( V_4 -> V_75 )
V_4 -> V_75 ( V_2 , V_4 ) ;
V_74:
F_21 ( V_2 -> V_13 ) ;
F_8 ( V_2 ) ;
V_73:
F_26 () ;
V_70:
return V_12 ;
}
static int F_27 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_24 ( V_40 ) ;
F_21 ( V_2 -> V_13 ) ;
F_8 ( V_2 ) ;
F_14 ( V_2 ) ;
F_26 () ;
return 0 ;
}
static int T_1 F_28 ( void )
{
return F_29 ( & V_76 ) ;
}
static void T_2 F_30 ( void )
{
F_31 ( & V_76 ) ;
}
