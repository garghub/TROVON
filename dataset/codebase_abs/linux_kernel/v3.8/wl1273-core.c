static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
T_1 V_7 [ 2 ] ;
int V_8 ;
V_8 = F_2 ( V_6 , V_3 , sizeof( V_7 ) , V_7 ) ;
if ( V_8 != 2 ) {
F_3 ( & V_6 -> V_9 , L_1 , V_10 , V_3 ) ;
return - V_11 ;
}
* V_4 = ( T_2 ) V_7 [ 0 ] << 8 | V_7 [ 1 ] ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_12 , T_2 V_13 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
T_1 V_14 [] = { ( V_13 >> 8 ) & 0xff , V_13 & 0xff } ;
int V_8 ;
V_8 = F_5 ( V_6 , V_12 , sizeof( V_14 ) , V_14 ) ;
if ( V_8 ) {
F_3 ( & V_6 -> V_9 , L_2 , V_10 , V_12 ) ;
return V_8 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 * V_15 , T_2 V_16 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_17 V_18 ;
int V_8 ;
V_18 . V_19 = V_6 -> V_19 ;
V_18 . V_20 = 0 ;
V_18 . V_14 = V_15 ;
V_18 . V_16 = V_16 ;
V_8 = F_7 ( V_6 -> V_21 , & V_18 , 1 ) ;
if ( V_8 != 1 ) {
F_3 ( & V_6 -> V_9 , L_3 , V_10 ) ;
return - V_11 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned int V_22 )
{
int V_8 = 0 ;
if ( V_2 -> V_23 == V_24 ||
V_2 -> V_23 == V_25 )
return - V_26 ;
if ( V_2 -> V_23 == V_27 && V_22 == V_28 ) {
V_8 = F_4 ( V_2 , V_29 ,
V_30 ) ;
if ( V_8 )
goto V_31;
V_8 = F_4 ( V_2 , V_32 ,
V_2 -> V_33 ) ;
if ( V_8 )
goto V_31;
V_8 = F_4 ( V_2 , V_34 ,
V_35 ) ;
if ( V_8 )
goto V_31;
} else if ( V_2 -> V_23 == V_27 &&
V_22 == V_36 ) {
V_8 = F_4 ( V_2 , V_34 ,
V_37 ) ;
if ( V_8 )
goto V_31;
} else if ( V_2 -> V_23 == V_38 &&
V_22 == V_28 ) {
V_8 = F_4 ( V_2 , V_32 ,
V_2 -> V_33 ) ;
if ( V_8 )
goto V_31;
V_8 = F_4 ( V_2 , V_39 ,
V_40 ) ;
if ( V_8 )
goto V_31;
} else if ( V_2 -> V_23 == V_38 &&
V_22 == V_36 ) {
V_8 = F_4 ( V_2 , V_39 ,
V_41 ) ;
if ( V_8 )
goto V_31;
}
V_2 -> V_42 = V_22 ;
V_31:
return V_8 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned int V_43 )
{
int V_8 ;
if ( V_43 > V_44 )
return - V_45 ;
if ( V_2 -> V_43 == V_43 )
return 0 ;
V_8 = F_4 ( V_2 , V_46 , V_43 ) ;
if ( V_8 )
return V_8 ;
V_2 -> V_43 = V_43 ;
return 0 ;
}
static int F_10 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_11 ( V_6 ) ;
F_12 ( & V_6 -> V_9 , L_4 , V_10 ) ;
F_13 ( & V_6 -> V_9 ) ;
F_14 ( V_2 ) ;
return 0 ;
}
static int F_15 ( struct V_5 * V_6 ,
const struct V_47 * V_48 )
{
struct V_49 * V_50 = V_6 -> V_9 . V_51 ;
struct V_1 * V_2 ;
struct V_52 * V_53 ;
int V_54 = 0 ;
int V_8 = 0 ;
F_12 ( & V_6 -> V_9 , L_4 , V_10 ) ;
if ( ! V_50 ) {
F_3 ( & V_6 -> V_9 , L_5 ) ;
return - V_45 ;
}
if ( ! ( V_50 -> V_54 & V_55 ) ) {
F_3 ( & V_6 -> V_9 , L_6 ) ;
return - V_45 ;
}
V_2 = F_16 ( sizeof( * V_2 ) , V_56 ) ;
if ( ! V_2 )
return - V_57 ;
V_2 -> V_50 = V_50 ;
V_2 -> V_6 = V_6 ;
F_17 ( & V_2 -> V_58 ) ;
F_18 ( V_6 , V_2 ) ;
F_12 ( & V_6 -> V_9 , L_7 , V_10 ) ;
V_53 = & V_2 -> V_59 [ V_54 ] ;
V_53 -> V_60 = L_8 ;
V_53 -> V_51 = & V_2 ;
V_53 -> V_61 = sizeof( V_2 ) ;
V_54 ++ ;
V_2 -> V_62 = F_1 ;
V_2 -> V_63 = F_4 ;
V_2 -> V_64 = F_6 ;
V_2 -> V_65 = F_8 ;
V_2 -> V_66 = F_9 ;
if ( V_50 -> V_54 & V_67 ) {
V_53 = & V_2 -> V_59 [ V_54 ] ;
F_12 ( & V_6 -> V_9 , L_9 , V_10 ) ;
V_53 -> V_60 = L_10 ;
V_53 -> V_51 = & V_2 ;
V_53 -> V_61 = sizeof( V_2 ) ;
V_54 ++ ;
}
F_12 ( & V_6 -> V_9 , L_11 ,
V_10 , V_54 ) ;
V_8 = F_19 ( & V_6 -> V_9 , - 1 , V_2 -> V_59 ,
V_54 , NULL , 0 , NULL ) ;
if ( V_8 )
goto V_68;
return 0 ;
V_68:
V_50 -> V_69 () ;
F_14 ( V_2 ) ;
F_12 ( & V_6 -> V_9 , L_4 , V_10 ) ;
return V_8 ;
}
static int T_3 F_20 ( void )
{
int V_8 ;
V_8 = F_21 ( & V_70 ) ;
if ( V_8 ) {
F_22 ( V_71
L_12 ) ;
return V_8 ;
}
return V_8 ;
}
static void T_4 F_23 ( void )
{
F_24 ( & V_70 ) ;
}
