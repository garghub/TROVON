static struct V_1 *
F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_8 * V_9 ;
V_4 = F_2 ( V_3 , sizeof( struct V_1 ) ,
V_10 ) ;
if ( ! V_4 )
return F_3 ( - V_11 ) ;
V_4 -> V_9 = F_4 ( V_3 , V_3 -> V_7 ) ;
if ( ! V_4 -> V_9 )
return F_3 ( - V_12 ) ;
V_9 = V_4 -> V_9 ;
V_9 -> V_13 . V_14 = 0 ;
V_4 -> V_15 = V_9 -> V_13 . V_16 ;
if ( V_9 -> V_13 . V_17 == V_9 -> V_13 . V_18 ) {
V_4 -> V_19 = V_9 -> V_13 . V_17 ;
} else {
F_5 ( V_3 ,
L_1 ) ;
return F_3 ( - V_12 ) ;
}
if ( V_9 -> V_13 . V_20 )
V_4 -> V_21 = true ;
V_4 -> V_22 = F_6 ( V_6 , L_2 , 0 ) ;
if ( ( V_4 -> V_22 == - V_23 ) || ( V_4 -> V_22 == - V_24 ) )
return F_3 ( - V_24 ) ;
F_7 ( V_6 , L_3 , & V_4 -> V_25 ) ;
V_4 -> V_26 = F_8 ( V_6 , L_4 ) ;
V_4 -> V_27 = F_8 ( V_6 ,
L_5 ) ;
if ( F_9 ( V_6 , L_6 , NULL ) )
V_4 -> V_28 = L_7 ;
return V_4 ;
}
static int F_10 ( struct V_29 * V_30 )
{
struct V_1 * V_4 ;
struct V_31 * V_32 ;
struct V_33 V_34 = { } ;
int V_35 ;
if ( V_30 -> V_3 . V_7 ) {
V_4 = F_1 ( & V_30 -> V_3 ) ;
if ( F_11 ( V_4 ) )
return F_12 ( V_4 ) ;
} else {
V_4 = F_13 ( & V_30 -> V_3 ) ;
}
if ( ! V_4 )
return - V_11 ;
V_32 = F_2 ( & V_30 -> V_3 , sizeof( struct V_31 ) ,
V_10 ) ;
if ( ! V_32 )
return - V_11 ;
V_32 -> V_36 . V_16 = F_14 ( & V_30 -> V_3 ,
V_4 -> V_15 ,
V_10 ) ;
if ( V_32 -> V_36 . V_16 == NULL ) {
F_5 ( & V_30 -> V_3 , L_8 ) ;
return - V_11 ;
}
V_32 -> V_36 . type = V_37 ;
V_32 -> V_36 . V_38 = V_39 ;
V_32 -> V_36 . V_40 = & V_41 ;
V_32 -> V_36 . V_42 = V_4 -> V_25 ;
if ( V_4 -> V_28 ) {
V_32 -> V_36 . V_15 = F_14 ( & V_30 -> V_3 ,
V_4 -> V_28 ,
V_10 ) ;
if ( ! V_32 -> V_36 . V_15 ) {
F_5 ( & V_30 -> V_3 ,
L_9 ) ;
return - V_11 ;
}
}
if ( V_4 -> V_19 )
V_32 -> V_36 . V_43 = 1 ;
V_32 -> V_36 . V_44 = V_4 -> V_19 ;
if ( V_4 -> V_22 >= 0 )
V_34 . V_45 = V_4 -> V_22 ;
V_34 . V_46 = ! V_4 -> V_26 ;
if ( V_4 -> V_21 ) {
if ( V_4 -> V_26 )
V_34 . V_47 |= V_48 ;
else
V_34 . V_47 |= V_49 ;
} else {
if ( V_4 -> V_26 )
V_34 . V_47 |= V_49 ;
else
V_34 . V_47 |= V_48 ;
}
if ( V_4 -> V_27 )
V_34 . V_47 |= V_50 ;
V_34 . V_3 = & V_30 -> V_3 ;
V_34 . V_9 = V_4 -> V_9 ;
V_34 . V_51 = V_32 ;
V_34 . V_7 = V_30 -> V_3 . V_7 ;
V_32 -> V_3 = F_15 ( & V_30 -> V_3 , & V_32 -> V_36 ,
& V_34 ) ;
if ( F_11 ( V_32 -> V_3 ) ) {
V_35 = F_12 ( V_32 -> V_3 ) ;
F_5 ( & V_30 -> V_3 , L_10 , V_35 ) ;
return V_35 ;
}
F_16 ( V_30 , V_32 ) ;
F_17 ( & V_30 -> V_3 , L_11 , V_32 -> V_36 . V_16 ,
V_32 -> V_36 . V_44 ) ;
return 0 ;
}
static int T_1 F_18 ( void )
{
return F_19 ( & V_52 ) ;
}
static void T_2 F_20 ( void )
{
F_21 ( & V_52 ) ;
}
