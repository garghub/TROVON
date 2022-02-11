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
static int T_1 F_10 ( struct V_32 * V_33 )
{
struct V_34 * V_35 = F_11 ( V_33 , V_36 , 0 ) ;
const T_2 * V_7 , * V_21 , * V_24 , * V_37 ;
struct V_5 * V_6 ;
struct V_38 * V_38 ;
int V_39 = 0 ;
if ( ! V_35 ) {
F_8 ( & V_33 -> V_13 , L_2 ) ;
return - V_40 ;
}
V_6 = F_12 ( & V_33 -> V_13 , sizeof( * V_6 ) , V_41 ) ;
if ( ! V_6 )
return - V_42 ;
V_6 -> V_8 = F_13 ( & V_33 -> V_13 , V_35 ) ;
if ( ! V_6 -> V_8 ) {
F_8 ( & V_33 -> V_13 , L_3 ) ;
return - V_42 ;
}
V_6 -> V_2 . V_13 = & V_33 -> V_13 ;
V_6 -> V_2 . V_43 = L_4 ;
V_6 -> V_2 . V_44 = F_6 ;
V_6 -> V_2 . V_45 = F_1 ;
V_6 -> V_2 . V_46 = F_7 ;
V_6 -> V_2 . V_47 = - 1 ;
V_6 -> V_2 . V_48 = V_49 ;
V_7 = F_14 ( V_33 -> V_13 . V_50 , L_5 , NULL ) ;
if ( V_7 )
V_6 -> V_7 = F_15 ( * V_7 ) ;
V_21 = F_14 ( V_33 -> V_13 . V_50 , L_6 , NULL ) ;
if ( V_21 )
V_6 -> V_21 = F_15 ( * V_21 ) & V_20 ;
else
V_6 -> V_21 = V_51 ;
V_6 -> V_2 . V_52 = F_16 ( V_6 -> V_21 ) * 8 ;
V_24 = F_14 ( V_33 -> V_13 . V_50 , L_7 , NULL ) ;
if ( V_24 )
V_6 -> V_24 = F_15 ( * V_24 ) & V_22 ;
if ( F_17 ( L_8 ) ||
F_17 ( L_9 ) ||
F_17 ( L_10 ) ) {
V_37 = F_14 ( V_33 -> V_13 . V_50 , L_11 , NULL ) ;
if ( V_37 )
V_6 -> V_27 = F_15 ( * V_37 ) & V_25 ;
V_37 = F_14 ( V_33 -> V_13 . V_50 , L_12 , NULL ) ;
if ( V_37 )
V_6 -> V_29 = F_15 ( * V_37 ) & V_25 ;
}
if ( ! F_18 ( V_33 -> V_13 . V_50 , L_13 , NULL ) )
V_6 -> V_19 = V_53 ;
V_38 = F_19 ( & V_33 -> V_13 , NULL ) ;
if ( F_20 ( V_38 ) ) {
F_8 ( & V_33 -> V_13 , L_14 ) ;
return F_21 ( V_38 ) ;
}
F_22 ( V_38 ) ;
V_39 = F_9 ( V_6 ) ;
if ( ! V_39 )
V_39 = F_23 ( & V_6 -> V_2 ) ;
if ( ! V_39 )
F_24 ( & V_33 -> V_13 , L_15 ) ;
return V_39 ;
}
int T_3 F_25 ( void )
{
return F_26 ( & V_54 ) ;
}
