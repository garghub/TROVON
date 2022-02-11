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
for ( V_11 = 0 ; V_11 < F_5 ( V_16 ) ; V_11 ++ ) {
if ( V_14 == V_16 [ V_11 ] . V_14 &&
V_13 == V_16 [ V_11 ] . V_13 &&
V_15 == V_16 [ V_11 ] . V_15 ) {
V_12 = 1 ;
break;
}
}
if ( ! V_12 )
return - V_17 ;
F_6 ( V_9 , 0 , 0 , 14750000 , V_16 [ V_11 ] . V_18 ) ;
switch ( V_15 ) {
case 2 :
F_7 ( V_10 , 0x3 , 0x3 , 2 , 0 ) ;
break;
case 1 :
F_7 ( V_10 , 0x1 , 0x1 , 1 , 0 ) ;
break;
default:
return - V_17 ;
}
F_8 ( V_9 , V_19 ,
V_16 [ V_11 ] . V_18 , V_20 ) ;
F_9 ( V_9 , V_21 ,
V_16 [ V_11 ] . V_22 ) ;
F_9 ( V_9 ,
V_23 , V_16 [ V_11 ] . V_24 ) ;
F_9 ( V_9 ,
V_25 , V_16 [ V_11 ] . V_24 ) ;
F_9 ( V_9 ,
V_26 , V_16 [ V_11 ] . V_27 ) ;
F_9 ( V_9 ,
V_28 , V_16 [ V_11 ] . V_27 ) ;
return 0 ;
}
static int F_10 ( struct V_5 * V_6 )
{
struct V_29 * V_30 = V_6 -> V_30 ;
struct V_31 * V_32 = & V_30 -> V_32 ;
F_11 ( V_30 , L_1 , V_33 , & V_34 ) ;
F_12 ( & V_34 , F_5 ( V_35 ) ,
V_35 ) ;
F_13 ( V_30 , V_36 , & V_34 , V_33 ) ;
F_11 ( V_30 , L_2 ,
V_37 | V_38 , & V_39 ) ;
F_12 ( & V_39 , F_5 ( V_40 ) ,
V_40 ) ;
F_14 ( V_30 , & V_39 , V_37 ,
V_38 ) ;
F_15 ( V_32 , L_3 ) ;
return 0 ;
}
static int T_2 F_16 ( void )
{
int V_41 ;
unsigned int V_42 , V_43 ;
V_42 = V_44 |
V_45 |
F_17 ( V_46 ) |
V_47 |
F_18 ( V_46 ) ;
V_43 = F_19 ( V_46 ) ;
F_20 ( V_48 , V_42 , V_43 ) ;
V_42 = V_44 ;
V_43 = F_19 ( V_48 ) ;
F_20 ( V_46 , V_42 , V_43 ) ;
V_49 = F_21 ( L_4 , - 1 ) ;
if ( ! V_49 )
return - V_50 ;
F_22 ( V_49 , & V_51 ) ;
V_41 = F_23 ( V_49 ) ;
if ( V_41 )
F_24 ( V_49 ) ;
return V_41 ;
}
static void T_3 F_25 ( void )
{
F_26 ( V_49 ) ;
}
