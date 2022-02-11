static struct V_1 *
F_1 ( struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_1 * V_6 ;
struct V_7 * V_8 = V_3 -> V_9 ;
struct V_10 * V_11 ;
V_6 = F_2 ( V_3 , sizeof( struct V_1 ) ,
V_12 ) ;
if ( ! V_6 )
return F_3 ( - V_13 ) ;
V_6 -> V_11 = F_4 ( V_3 , V_3 -> V_9 , V_5 ) ;
if ( ! V_6 -> V_11 )
return F_3 ( - V_14 ) ;
V_11 = V_6 -> V_11 ;
V_11 -> V_15 . V_16 = 0 ;
V_6 -> V_17 = V_11 -> V_15 . V_18 ;
if ( V_11 -> V_15 . V_19 == V_11 -> V_15 . V_20 ) {
V_6 -> V_21 = V_11 -> V_15 . V_19 ;
} else {
F_5 ( V_3 ,
L_1 ) ;
return F_3 ( - V_14 ) ;
}
if ( V_11 -> V_15 . V_22 )
V_6 -> V_23 = true ;
V_6 -> V_24 = F_6 ( V_8 , L_2 , 0 ) ;
if ( ( V_6 -> V_24 < 0 ) && ( V_6 -> V_24 != - V_25 ) )
return F_3 ( V_6 -> V_24 ) ;
F_7 ( V_8 , L_3 , & V_6 -> V_26 ) ;
V_6 -> V_27 = F_8 ( V_8 , L_4 ) ;
V_6 -> V_28 = F_8 ( V_8 ,
L_5 ) ;
if ( F_9 ( V_8 , L_6 , NULL ) )
V_6 -> V_29 = L_7 ;
return V_6 ;
}
static int F_10 ( struct V_30 * V_31 )
{
struct V_1 * V_6 ;
struct V_32 * V_33 ;
struct V_34 V_35 = { } ;
int V_36 ;
V_33 = F_2 ( & V_31 -> V_3 , sizeof( struct V_32 ) ,
V_12 ) ;
if ( ! V_33 )
return - V_13 ;
if ( V_31 -> V_3 . V_9 ) {
V_6 = F_1 ( & V_31 -> V_3 ,
& V_33 -> V_5 ) ;
if ( F_11 ( V_6 ) )
return F_12 ( V_6 ) ;
} else {
V_6 = F_13 ( & V_31 -> V_3 ) ;
}
if ( ! V_6 )
return - V_13 ;
V_33 -> V_5 . V_18 = F_14 ( & V_31 -> V_3 ,
V_6 -> V_17 ,
V_12 ) ;
if ( V_33 -> V_5 . V_18 == NULL ) {
F_5 ( & V_31 -> V_3 , L_8 ) ;
return - V_13 ;
}
V_33 -> V_5 . type = V_37 ;
V_33 -> V_5 . V_38 = V_39 ;
V_33 -> V_5 . V_40 = & V_41 ;
V_33 -> V_5 . V_42 = V_6 -> V_26 ;
if ( V_6 -> V_29 ) {
V_33 -> V_5 . V_17 = F_14 ( & V_31 -> V_3 ,
V_6 -> V_29 ,
V_12 ) ;
if ( ! V_33 -> V_5 . V_17 ) {
F_5 ( & V_31 -> V_3 ,
L_9 ) ;
return - V_13 ;
}
}
if ( V_6 -> V_21 )
V_33 -> V_5 . V_43 = 1 ;
V_33 -> V_5 . V_44 = V_6 -> V_21 ;
if ( F_15 ( V_6 -> V_24 ) ) {
V_35 . V_45 = V_6 -> V_24 ;
if ( V_31 -> V_3 . V_9 )
V_35 . V_46 = true ;
}
V_35 . V_47 = ! V_6 -> V_27 ;
if ( V_6 -> V_23 ) {
if ( V_6 -> V_27 )
V_35 . V_48 |= V_49 ;
else
V_35 . V_48 |= V_50 ;
} else {
if ( V_6 -> V_27 )
V_35 . V_48 |= V_50 ;
else
V_35 . V_48 |= V_49 ;
}
if ( V_6 -> V_28 )
V_35 . V_48 |= V_51 ;
V_35 . V_3 = & V_31 -> V_3 ;
V_35 . V_11 = V_6 -> V_11 ;
V_35 . V_52 = V_33 ;
V_35 . V_9 = V_31 -> V_3 . V_9 ;
V_33 -> V_3 = F_16 ( & V_31 -> V_3 , & V_33 -> V_5 ,
& V_35 ) ;
if ( F_11 ( V_33 -> V_3 ) ) {
V_36 = F_12 ( V_33 -> V_3 ) ;
F_5 ( & V_31 -> V_3 , L_10 , V_36 ) ;
return V_36 ;
}
F_17 ( V_31 , V_33 ) ;
F_18 ( & V_31 -> V_3 , L_11 , V_33 -> V_5 . V_18 ,
V_33 -> V_5 . V_44 ) ;
return 0 ;
}
static int T_1 F_19 ( void )
{
return F_20 ( & V_53 ) ;
}
static void T_2 F_21 ( void )
{
F_22 ( & V_53 ) ;
}
