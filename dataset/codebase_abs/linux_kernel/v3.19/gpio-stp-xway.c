static void F_1 ( struct V_1 * V_2 , unsigned V_3 , int V_4 )
{
struct V_5 * V_6 =
F_2 ( V_2 , struct V_5 , V_2 ) ;
if ( V_4 )
V_6 -> V_7 |= F_3 ( V_3 ) ;
else
V_6 -> V_7 &= ~ F_3 ( V_3 ) ;
F_4 ( V_6 -> V_8 , V_6 -> V_7 , V_9 ) ;
F_5 ( V_6 -> V_8 , 0 , V_10 , V_11 ) ;
}
static int F_6 ( struct V_1 * V_2 , unsigned V_3 , int V_4 )
{
F_1 ( V_2 , V_3 , V_4 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_5 * V_6 =
F_2 ( V_2 , struct V_5 , V_2 ) ;
if ( ( V_3 < 8 ) && ( V_6 -> V_12 & F_3 ( V_3 ) ) ) {
F_8 ( V_2 -> V_13 , L_1 , V_3 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_9 ( struct V_5 * V_6 )
{
F_4 ( V_6 -> V_8 , 0 , V_15 ) ;
F_4 ( V_6 -> V_8 , 0 , V_9 ) ;
F_4 ( V_6 -> V_8 , 0 , V_16 ) ;
F_4 ( V_6 -> V_8 , V_10 , V_11 ) ;
F_4 ( V_6 -> V_8 , 0 , V_17 ) ;
F_5 ( V_6 -> V_8 , V_18 ,
V_6 -> V_19 , V_11 ) ;
F_5 ( V_6 -> V_8 , V_20 ,
V_6 -> V_21 , V_17 ) ;
F_5 ( V_6 -> V_8 ,
V_22 << V_23 ,
V_6 -> V_24 << V_23 ,
V_11 ) ;
F_5 ( V_6 -> V_8 ,
V_25 << V_26 ,
V_6 -> V_27 << V_26 ,
V_11 ) ;
F_5 ( V_6 -> V_8 ,
V_25 << V_28 ,
V_6 -> V_29 << V_28 ,
V_17 ) ;
V_6 -> V_12 = ( V_6 -> V_29 << 5 ) | ( V_6 -> V_27 << 2 ) | V_6 -> V_24 ;
if ( V_6 -> V_12 )
F_5 ( V_6 -> V_8 , V_30 ,
V_31 , V_17 ) ;
return 0 ;
}
static int F_10 ( struct V_32 * V_33 )
{
struct V_34 * V_35 ;
const T_1 * V_7 , * V_21 , * V_24 , * V_36 ;
struct V_5 * V_6 ;
struct V_37 * V_37 ;
int V_38 = 0 ;
V_6 = F_11 ( & V_33 -> V_13 , sizeof( * V_6 ) , V_39 ) ;
if ( ! V_6 )
return - V_40 ;
V_35 = F_12 ( V_33 , V_41 , 0 ) ;
V_6 -> V_8 = F_13 ( & V_33 -> V_13 , V_35 ) ;
if ( F_14 ( V_6 -> V_8 ) )
return F_15 ( V_6 -> V_8 ) ;
V_6 -> V_2 . V_13 = & V_33 -> V_13 ;
V_6 -> V_2 . V_42 = L_2 ;
V_6 -> V_2 . V_43 = F_6 ;
V_6 -> V_2 . V_44 = F_1 ;
V_6 -> V_2 . V_45 = F_7 ;
V_6 -> V_2 . V_46 = - 1 ;
V_6 -> V_2 . V_47 = V_48 ;
V_7 = F_16 ( V_33 -> V_13 . V_49 , L_3 , NULL ) ;
if ( V_7 )
V_6 -> V_7 = F_17 ( * V_7 ) ;
V_21 = F_16 ( V_33 -> V_13 . V_49 , L_4 , NULL ) ;
if ( V_21 )
V_6 -> V_21 = F_17 ( * V_21 ) & V_20 ;
else
V_6 -> V_21 = V_50 ;
V_6 -> V_2 . V_51 = F_18 ( V_6 -> V_21 ) * 8 ;
V_24 = F_16 ( V_33 -> V_13 . V_49 , L_5 , NULL ) ;
if ( V_24 )
V_6 -> V_24 = F_17 ( * V_24 ) & V_22 ;
if ( F_19 ( L_6 ) ||
F_19 ( L_7 ) ||
F_19 ( L_8 ) ) {
V_36 = F_16 ( V_33 -> V_13 . V_49 , L_9 , NULL ) ;
if ( V_36 )
V_6 -> V_27 = F_17 ( * V_36 ) & V_25 ;
V_36 = F_16 ( V_33 -> V_13 . V_49 , L_10 , NULL ) ;
if ( V_36 )
V_6 -> V_29 = F_17 ( * V_36 ) & V_25 ;
}
if ( ! F_20 ( V_33 -> V_13 . V_49 , L_11 , NULL ) )
V_6 -> V_19 = V_52 ;
V_37 = F_21 ( & V_33 -> V_13 , NULL ) ;
if ( F_14 ( V_37 ) ) {
F_8 ( & V_33 -> V_13 , L_12 ) ;
return F_15 ( V_37 ) ;
}
F_22 ( V_37 ) ;
V_38 = F_9 ( V_6 ) ;
if ( ! V_38 )
V_38 = F_23 ( & V_6 -> V_2 ) ;
if ( ! V_38 )
F_24 ( & V_33 -> V_13 , L_13 ) ;
return V_38 ;
}
static int T_2 F_25 ( void )
{
return F_26 ( & V_53 ) ;
}
