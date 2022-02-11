static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 ,
T_1 V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 V_12 ;
int V_13 ;
F_2 ( & V_12 , V_14 , false ) ;
V_7 = (struct V_6 * ) V_12 . V_5 ;
F_3 ( V_7 -> V_3 , V_15 ,
V_16 , V_3 ) ;
F_3 ( V_7 -> V_17 , V_18 ,
V_19 , V_4 ) ;
F_4 ( V_7 -> V_20 , V_21 , 1 ) ;
F_3 ( V_7 -> V_20 , V_22 ,
V_23 , 1 ) ;
F_3 ( V_7 -> V_20 , V_24 ,
V_25 , V_26 ) ;
V_7 -> V_27 = F_5 ( V_5 ) ;
V_13 = F_6 ( & V_9 -> V_28 , & V_12 , 1 ) ;
if ( V_13 ) {
F_7 ( & V_9 -> V_29 -> V_30 ,
L_1 ,
V_13 ) ;
return V_13 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 V_12 ;
int V_13 ;
F_2 ( & V_12 , V_14 , true ) ;
V_7 = (struct V_6 * ) V_12 . V_5 ;
F_3 ( V_7 -> V_3 , V_15 ,
V_16 , V_3 ) ;
F_3 ( V_7 -> V_17 , V_18 ,
V_19 , V_4 ) ;
F_4 ( V_7 -> V_20 , V_21 , 1 ) ;
F_3 ( V_7 -> V_20 , V_22 ,
V_23 , 1 ) ;
F_3 ( V_7 -> V_20 , V_24 ,
V_25 , V_31 ) ;
V_13 = F_6 ( & V_9 -> V_28 , & V_12 , 1 ) ;
if ( V_13 ) {
F_7 ( & V_9 -> V_29 -> V_30 ,
L_2 ,
V_13 ) ;
return V_13 ;
}
if ( F_9 ( F_10 ( V_7 -> V_32 ) , V_33 ) ) {
F_7 ( & V_9 -> V_29 -> V_30 , L_3 ) ;
return - V_34 ;
}
return F_10 ( V_7 -> V_35 ) ;
}
int F_11 ( struct V_8 * V_9 )
{
struct V_36 * V_37 = & V_9 -> V_28 . V_37 ;
struct V_38 * V_39 ;
struct V_1 * V_40 ;
int V_13 ;
if ( V_9 -> V_28 . V_37 . V_41 >= V_42 )
return 0 ;
V_40 = F_12 ( & V_9 -> V_29 -> V_30 ) ;
if ( ! V_40 )
return - V_43 ;
V_40 -> V_44 = L_4 ;
V_40 -> V_45 = F_8 ;
V_40 -> V_46 = F_1 ;
snprintf ( V_40 -> V_47 , V_48 , L_5 , L_6 ,
F_13 ( & V_9 -> V_29 -> V_30 ) ) ;
V_40 -> V_49 = & V_9 -> V_29 -> V_30 ;
V_40 -> V_10 = V_9 ;
V_40 -> V_50 = ~ ( 1 << V_37 -> V_41 ) ;
V_13 = F_14 ( V_40 ) ;
if ( V_13 ) {
F_7 ( V_40 -> V_49 ,
L_7 , V_13 ) ;
return V_13 ;
}
V_39 = F_15 ( V_40 , V_37 -> V_41 ) ;
if ( ! V_39 ) {
F_7 ( V_40 -> V_49 , L_8 ) ;
F_16 ( V_40 ) ;
return - V_34 ;
}
V_37 -> V_39 = V_39 ;
V_37 -> V_40 = V_40 ;
return 0 ;
}
static void F_17 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = * ( ( void * * ) F_18 ( V_52 ) ) ;
struct V_55 * V_56 = F_19 ( V_54 ) ;
struct V_8 * V_9 = V_56 -> V_57 ;
int V_58 , V_59 ;
int V_13 ;
V_59 = V_52 -> V_39 -> V_59 ;
V_58 = V_52 -> V_39 -> V_58 ;
V_13 = F_20 ( V_9 , V_59 , V_58 ) ;
if ( V_13 )
F_21 ( V_52 , L_9 ) ;
}
int F_22 ( struct V_8 * V_9 )
{
struct V_51 * V_52 = V_9 -> V_56 [ 0 ] . V_60 . V_52 ;
struct V_38 * V_39 = V_9 -> V_28 . V_37 . V_39 ;
int V_13 ;
if ( ! V_39 )
return 0 ;
V_13 = F_23 ( V_52 , V_39 ,
F_17 ,
V_61 ) ;
if ( V_13 ) {
F_21 ( V_52 , L_10 ) ;
return V_13 ;
}
F_24 ( V_39 ) ;
return 0 ;
}
void F_25 ( struct V_8 * V_9 )
{
struct V_51 * V_52 = V_9 -> V_56 [ 0 ] . V_60 . V_52 ;
struct V_38 * V_39 = V_52 -> V_39 ;
if ( ! V_39 )
return;
F_26 ( V_39 ) ;
F_27 ( V_39 ) ;
}
