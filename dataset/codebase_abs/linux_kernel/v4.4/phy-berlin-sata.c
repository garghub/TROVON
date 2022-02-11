static inline void F_1 ( void T_1 * V_1 ,
T_2 V_2 , T_2 V_3 , T_2 V_4 , T_2 V_5 )
{
T_2 V_6 ;
F_2 ( V_2 + V_3 , V_1 + V_7 ) ;
V_6 = F_3 ( V_1 + V_8 ) ;
V_6 &= ~ V_4 ;
V_6 |= V_5 ;
F_2 ( V_6 , V_1 + V_8 ) ;
}
static int F_4 ( struct V_9 * V_9 )
{
struct V_10 * V_11 = F_5 ( V_9 ) ;
struct V_12 * V_13 = F_6 ( V_9 -> V_14 . V_15 ) ;
void T_1 * V_1 = V_13 -> V_16 + 0x60 + ( V_11 -> V_17 * 0x80 ) ;
int V_18 = 0 ;
T_2 V_6 ;
F_7 ( V_13 -> V_19 ) ;
F_8 ( & V_13 -> V_20 ) ;
F_2 ( V_21 , V_13 -> V_16 + V_22 ) ;
V_6 = F_3 ( V_13 -> V_16 + V_23 ) ;
V_6 &= ~ V_11 -> V_24 ;
F_2 ( V_6 , V_13 -> V_16 + V_23 ) ;
F_2 ( V_25 , V_13 -> V_16 + V_22 ) ;
V_6 = F_3 ( V_13 -> V_16 + V_23 ) ;
V_6 |= V_26 | V_27 ;
F_2 ( V_6 , V_13 -> V_16 + V_23 ) ;
F_1 ( V_1 , V_13 -> V_2 , 0x01 ,
0x00ff , V_28 | V_29 ) ;
F_1 ( V_1 , V_13 -> V_2 , 0x25 ,
0x0c00 , V_30 ) ;
F_1 ( V_1 , V_13 -> V_2 , 0x23 ,
0x0c00 , V_31 ) ;
F_1 ( V_1 , V_13 -> V_2 , 0x02 ,
0x0000 , V_32 ) ;
V_6 = F_3 ( V_1 + V_33 ) ;
V_6 &= ~ F_9 ( 7 , 4 ) ;
V_6 |= 0x30 ;
F_2 ( V_6 , V_1 + V_33 ) ;
F_10 ( & V_13 -> V_20 ) ;
F_11 ( V_13 -> V_19 ) ;
return V_18 ;
}
static int F_12 ( struct V_9 * V_9 )
{
struct V_10 * V_11 = F_5 ( V_9 ) ;
struct V_12 * V_13 = F_6 ( V_9 -> V_14 . V_15 ) ;
T_2 V_6 ;
F_7 ( V_13 -> V_19 ) ;
F_8 ( & V_13 -> V_20 ) ;
F_2 ( V_21 , V_13 -> V_16 + V_22 ) ;
V_6 = F_3 ( V_13 -> V_16 + V_23 ) ;
V_6 |= V_11 -> V_24 ;
F_2 ( V_6 , V_13 -> V_16 + V_23 ) ;
F_10 ( & V_13 -> V_20 ) ;
F_11 ( V_13 -> V_19 ) ;
return 0 ;
}
static struct V_9 * F_13 ( struct V_34 * V_14 ,
struct V_35 * args )
{
struct V_12 * V_13 = F_6 ( V_14 ) ;
int V_36 ;
if ( F_14 ( args -> args [ 0 ] >= V_13 -> V_37 ) )
return F_15 ( - V_38 ) ;
for ( V_36 = 0 ; V_36 < V_13 -> V_37 ; V_36 ++ ) {
if ( V_13 -> V_39 [ V_36 ] -> V_17 == args -> args [ 0 ] )
break;
}
if ( V_36 == V_13 -> V_37 )
return F_15 ( - V_38 ) ;
return V_13 -> V_39 [ V_36 ] -> V_9 ;
}
static int F_16 ( struct V_40 * V_41 )
{
struct V_34 * V_14 = & V_41 -> V_14 ;
struct V_42 * V_43 ;
struct V_9 * V_9 ;
struct V_44 * V_44 ;
struct V_12 * V_13 ;
struct V_45 * V_46 ;
int V_18 , V_36 = 0 ;
T_2 V_47 ;
V_13 = F_17 ( V_14 , sizeof( * V_13 ) , V_48 ) ;
if ( ! V_13 )
return - V_49 ;
V_46 = F_18 ( V_41 , V_50 , 0 ) ;
if ( ! V_46 )
return - V_51 ;
V_13 -> V_16 = F_19 ( V_14 , V_46 -> V_52 , F_20 ( V_46 ) ) ;
if ( ! V_13 -> V_16 )
return - V_49 ;
V_13 -> V_19 = F_21 ( V_14 , NULL ) ;
if ( F_22 ( V_13 -> V_19 ) )
return F_23 ( V_13 -> V_19 ) ;
V_13 -> V_37 = F_24 ( V_14 -> V_53 ) ;
if ( V_13 -> V_37 == 0 )
return - V_38 ;
V_13 -> V_39 = F_25 ( V_14 , V_13 -> V_37 , sizeof( * V_13 -> V_39 ) ,
V_48 ) ;
if ( ! V_13 -> V_39 )
return - V_49 ;
if ( F_26 ( V_14 -> V_53 , L_1 ) )
V_13 -> V_2 = V_54 ;
else
V_13 -> V_2 = V_55 ;
F_27 ( V_14 , V_13 ) ;
F_28 ( & V_13 -> V_20 ) ;
F_29 (dev->of_node, child) {
struct V_10 * V_56 ;
if ( F_30 ( V_43 , L_2 , & V_47 ) ) {
F_31 ( V_14 , L_3 ,
V_43 -> V_57 ) ;
V_18 = - V_51 ;
goto V_58;
}
if ( V_47 >= F_32 ( V_59 ) ) {
F_31 ( V_14 , L_4 , V_43 -> V_57 ) ;
V_18 = - V_51 ;
goto V_58;
}
V_56 = F_17 ( V_14 , sizeof( * V_56 ) , V_48 ) ;
if ( ! V_56 ) {
V_18 = - V_49 ;
goto V_58;
}
V_9 = F_33 ( V_14 , NULL , & V_60 ) ;
if ( F_22 ( V_9 ) ) {
F_31 ( V_14 , L_5 , V_47 ) ;
V_18 = F_23 ( V_9 ) ;
goto V_58;
}
V_56 -> V_9 = V_9 ;
V_56 -> V_24 = V_59 [ V_47 ] ;
V_56 -> V_17 = V_47 ;
F_34 ( V_9 , V_56 ) ;
V_13 -> V_39 [ V_36 ++ ] = V_56 ;
F_12 ( V_9 ) ;
}
V_44 =
F_35 ( V_14 , F_13 ) ;
return F_36 ( V_44 ) ;
V_58:
F_37 ( V_43 ) ;
return V_18 ;
}
