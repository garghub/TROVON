static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
int V_11 , V_12 = 0 ;
T_1 V_13 = F_2 ( V_4 ) ;
unsigned int V_14 = F_3 ( V_4 ) ;
unsigned int V_15 = F_4 ( V_4 ) ;
T_2 V_16 ;
for ( V_11 = 0 ; V_11 < F_5 ( V_17 ) ; V_11 ++ ) {
if ( V_14 == V_17 [ V_11 ] . V_14 &&
V_13 == V_17 [ V_11 ] . V_13 &&
V_15 == V_17 [ V_11 ] . V_15 ) {
V_12 = 1 ;
break;
}
}
if ( ! V_12 )
return - V_18 ;
F_6 ( V_9 , 0 , 0 , 14750000 , V_17 [ V_11 ] . V_19 ) ;
V_16 = V_20 | V_21 |
V_22 ;
F_7 ( V_9 , V_16 ) ;
F_7 ( V_10 , V_16 ) ;
switch ( V_15 ) {
case 2 :
F_8 ( V_10 , 0xffffffc , 0xffffffc , 2 , 0 ) ;
break;
case 1 :
F_8 ( V_10 , 0xffffffe , 0xffffffe , 1 , 0 ) ;
break;
default:
return - V_18 ;
}
F_9 ( V_9 , V_23 ,
V_17 [ V_11 ] . V_19 , V_24 ) ;
F_10 ( V_9 , V_25 ,
V_17 [ V_11 ] . V_26 ) ;
F_10 ( V_9 ,
V_27 , V_17 [ V_11 ] . V_28 ) ;
F_10 ( V_9 ,
V_29 , V_17 [ V_11 ] . V_28 ) ;
F_10 ( V_9 ,
V_30 , V_17 [ V_11 ] . V_31 ) ;
F_10 ( V_9 ,
V_32 , V_17 [ V_11 ] . V_31 ) ;
return 0 ;
}
static int F_11 ( struct V_5 * V_6 )
{
struct V_33 * V_34 = V_6 -> V_34 ;
struct V_35 * V_36 = & V_34 -> V_36 ;
F_12 ( V_34 , L_1 , V_37 , & V_38 ) ;
F_13 ( & V_38 , F_5 ( V_39 ) ,
V_39 ) ;
F_14 ( V_34 , V_40 , & V_38 , V_37 ) ;
F_12 ( V_34 , L_2 ,
V_41 | V_42 , & V_43 ) ;
F_13 ( & V_43 , F_5 ( V_44 ) ,
V_44 ) ;
F_15 ( V_34 , & V_43 , V_41 ,
V_42 ) ;
F_16 ( V_36 , L_3 ) ;
return 0 ;
}
static int T_3 F_17 ( void )
{
int V_45 ;
unsigned int V_46 , V_47 ;
V_46 = V_48 |
V_49 |
F_18 ( V_50 ) |
V_51 |
F_19 ( V_50 ) ;
V_47 = F_20 ( V_50 ) ;
F_21 ( V_52 , V_46 , V_47 ) ;
V_46 = V_48 ;
V_47 = F_20 ( V_52 ) ;
F_21 ( V_50 , V_46 , V_47 ) ;
V_53 = F_22 ( L_4 , - 1 ) ;
if ( ! V_53 )
return - V_54 ;
F_23 ( V_53 , & V_55 ) ;
V_45 = F_24 ( V_53 ) ;
if ( V_45 )
F_25 ( V_53 ) ;
return V_45 ;
}
static void T_4 F_26 ( void )
{
F_27 ( V_53 ) ;
}
