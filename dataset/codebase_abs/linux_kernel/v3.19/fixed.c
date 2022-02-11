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
if ( ( V_6 -> V_24 == - V_25 ) || ( V_6 -> V_24 == - V_26 ) )
return F_3 ( - V_26 ) ;
F_7 ( V_8 , L_3 , & V_6 -> V_27 ) ;
V_6 -> V_28 = F_8 ( V_8 , L_4 ) ;
V_6 -> V_29 = F_8 ( V_8 ,
L_5 ) ;
if ( F_9 ( V_8 , L_6 , NULL ) )
V_6 -> V_30 = L_7 ;
return V_6 ;
}
static int F_10 ( struct V_31 * V_32 )
{
struct V_1 * V_6 ;
struct V_33 * V_34 ;
struct V_35 V_36 = { } ;
int V_37 ;
V_34 = F_2 ( & V_32 -> V_3 , sizeof( struct V_33 ) ,
V_12 ) ;
if ( ! V_34 )
return - V_13 ;
if ( V_32 -> V_3 . V_9 ) {
V_6 = F_1 ( & V_32 -> V_3 ,
& V_34 -> V_5 ) ;
if ( F_11 ( V_6 ) )
return F_12 ( V_6 ) ;
} else {
V_6 = F_13 ( & V_32 -> V_3 ) ;
}
if ( ! V_6 )
return - V_13 ;
V_34 -> V_5 . V_18 = F_14 ( & V_32 -> V_3 ,
V_6 -> V_17 ,
V_12 ) ;
if ( V_34 -> V_5 . V_18 == NULL ) {
F_5 ( & V_32 -> V_3 , L_8 ) ;
return - V_13 ;
}
V_34 -> V_5 . type = V_38 ;
V_34 -> V_5 . V_39 = V_40 ;
V_34 -> V_5 . V_41 = & V_42 ;
V_34 -> V_5 . V_43 = V_6 -> V_27 ;
if ( V_6 -> V_30 ) {
V_34 -> V_5 . V_17 = F_14 ( & V_32 -> V_3 ,
V_6 -> V_30 ,
V_12 ) ;
if ( ! V_34 -> V_5 . V_17 ) {
F_5 ( & V_32 -> V_3 ,
L_9 ) ;
return - V_13 ;
}
}
if ( V_6 -> V_21 )
V_34 -> V_5 . V_44 = 1 ;
V_34 -> V_5 . V_45 = V_6 -> V_21 ;
if ( F_15 ( V_6 -> V_24 ) ) {
V_36 . V_46 = V_6 -> V_24 ;
if ( V_32 -> V_3 . V_9 )
V_36 . V_47 = true ;
}
V_36 . V_48 = ! V_6 -> V_28 ;
if ( V_6 -> V_23 ) {
if ( V_6 -> V_28 )
V_36 . V_49 |= V_50 ;
else
V_36 . V_49 |= V_51 ;
} else {
if ( V_6 -> V_28 )
V_36 . V_49 |= V_51 ;
else
V_36 . V_49 |= V_50 ;
}
if ( V_6 -> V_29 )
V_36 . V_49 |= V_52 ;
V_36 . V_3 = & V_32 -> V_3 ;
V_36 . V_11 = V_6 -> V_11 ;
V_36 . V_53 = V_34 ;
V_36 . V_9 = V_32 -> V_3 . V_9 ;
V_34 -> V_3 = F_16 ( & V_32 -> V_3 , & V_34 -> V_5 ,
& V_36 ) ;
if ( F_11 ( V_34 -> V_3 ) ) {
V_37 = F_12 ( V_34 -> V_3 ) ;
F_5 ( & V_32 -> V_3 , L_10 , V_37 ) ;
return V_37 ;
}
F_17 ( V_32 , V_34 ) ;
F_18 ( & V_32 -> V_3 , L_11 , V_34 -> V_5 . V_18 ,
V_34 -> V_5 . V_45 ) ;
return 0 ;
}
static int T_1 F_19 ( void )
{
return F_20 ( & V_54 ) ;
}
static void T_2 F_21 ( void )
{
F_22 ( & V_54 ) ;
}
