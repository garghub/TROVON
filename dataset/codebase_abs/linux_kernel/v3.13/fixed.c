static struct V_1 *
F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_5 * V_6 = V_3 -> V_7 ;
const T_1 * V_8 ;
struct V_9 * V_10 ;
V_4 = F_2 ( V_3 , sizeof( struct V_1 ) ,
V_11 ) ;
if ( ! V_4 )
return F_3 ( - V_12 ) ;
V_4 -> V_10 = F_4 ( V_3 , V_3 -> V_7 ) ;
if ( ! V_4 -> V_10 )
return F_3 ( - V_13 ) ;
V_10 = V_4 -> V_10 ;
V_10 -> V_14 . V_15 = 0 ;
V_4 -> V_16 = V_10 -> V_14 . V_17 ;
if ( V_10 -> V_14 . V_18 == V_10 -> V_14 . V_19 ) {
V_4 -> V_20 = V_10 -> V_14 . V_18 ;
} else {
F_5 ( V_3 ,
L_1 ) ;
return F_3 ( - V_13 ) ;
}
if ( V_10 -> V_14 . V_21 )
V_4 -> V_22 = true ;
V_4 -> V_23 = F_6 ( V_6 , L_2 , 0 ) ;
if ( ( V_4 -> V_23 == - V_24 ) || ( V_4 -> V_23 == - V_25 ) )
return F_3 ( - V_25 ) ;
V_8 = F_7 ( V_6 , L_3 , NULL ) ;
if ( V_8 )
V_4 -> V_26 = F_8 ( * V_8 ) ;
if ( F_9 ( V_6 , L_4 , NULL ) )
V_4 -> V_27 = true ;
if ( F_9 ( V_6 , L_5 , NULL ) )
V_4 -> V_28 = true ;
if ( F_9 ( V_6 , L_6 , NULL ) )
V_4 -> V_29 = L_7 ;
return V_4 ;
}
static int F_10 ( struct V_30 * V_31 )
{
struct V_1 * V_4 ;
struct V_32 * V_33 ;
struct V_34 V_35 = { } ;
int V_36 ;
if ( V_31 -> V_3 . V_7 ) {
V_4 = F_1 ( & V_31 -> V_3 ) ;
if ( F_11 ( V_4 ) )
return F_12 ( V_4 ) ;
} else {
V_4 = F_13 ( & V_31 -> V_3 ) ;
}
if ( ! V_4 )
return - V_12 ;
V_33 = F_2 ( & V_31 -> V_3 , sizeof( struct V_32 ) ,
V_11 ) ;
if ( V_33 == NULL ) {
F_5 ( & V_31 -> V_3 , L_8 ) ;
V_36 = - V_12 ;
goto V_37;
}
V_33 -> V_38 . V_17 = F_14 ( V_4 -> V_16 , V_11 ) ;
if ( V_33 -> V_38 . V_17 == NULL ) {
F_5 ( & V_31 -> V_3 , L_9 ) ;
V_36 = - V_12 ;
goto V_37;
}
V_33 -> V_38 . type = V_39 ;
V_33 -> V_38 . V_40 = V_41 ;
V_33 -> V_38 . V_42 = & V_43 ;
V_33 -> V_38 . V_44 = V_4 -> V_26 ;
if ( V_4 -> V_29 ) {
V_33 -> V_38 . V_16 = F_14 ( V_4 -> V_29 ,
V_11 ) ;
if ( ! V_33 -> V_38 . V_16 ) {
F_5 ( & V_31 -> V_3 ,
L_10 ) ;
V_36 = - V_12 ;
goto V_45;
}
}
if ( V_4 -> V_20 )
V_33 -> V_38 . V_46 = 1 ;
V_33 -> V_38 . V_47 = V_4 -> V_20 ;
if ( V_4 -> V_23 >= 0 )
V_35 . V_48 = V_4 -> V_23 ;
V_35 . V_49 = ! V_4 -> V_27 ;
if ( V_4 -> V_22 ) {
if ( V_4 -> V_27 )
V_35 . V_50 |= V_51 ;
else
V_35 . V_50 |= V_52 ;
} else {
if ( V_4 -> V_27 )
V_35 . V_50 |= V_52 ;
else
V_35 . V_50 |= V_51 ;
}
if ( V_4 -> V_28 )
V_35 . V_50 |= V_53 ;
V_35 . V_3 = & V_31 -> V_3 ;
V_35 . V_10 = V_4 -> V_10 ;
V_35 . V_54 = V_33 ;
V_35 . V_7 = V_31 -> V_3 . V_7 ;
V_33 -> V_3 = F_15 ( & V_33 -> V_38 , & V_35 ) ;
if ( F_11 ( V_33 -> V_3 ) ) {
V_36 = F_12 ( V_33 -> V_3 ) ;
F_5 ( & V_31 -> V_3 , L_11 , V_36 ) ;
goto V_55;
}
F_16 ( V_31 , V_33 ) ;
F_17 ( & V_31 -> V_3 , L_12 , V_33 -> V_38 . V_17 ,
V_33 -> V_38 . V_47 ) ;
return 0 ;
V_55:
F_18 ( V_33 -> V_38 . V_16 ) ;
V_45:
F_18 ( V_33 -> V_38 . V_17 ) ;
V_37:
return V_36 ;
}
static int F_19 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = F_20 ( V_31 ) ;
F_21 ( V_33 -> V_3 ) ;
F_18 ( V_33 -> V_38 . V_16 ) ;
F_18 ( V_33 -> V_38 . V_17 ) ;
return 0 ;
}
static int T_2 F_22 ( void )
{
return F_23 ( & V_56 ) ;
}
static void T_3 F_24 ( void )
{
F_25 ( & V_56 ) ;
}
