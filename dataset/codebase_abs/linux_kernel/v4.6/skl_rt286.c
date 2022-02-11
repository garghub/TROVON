static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = V_2 -> V_7 -> V_6 ;
V_4 = F_2 ( V_6 ) ;
F_3 ( V_4 , L_1 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
int V_10 ;
V_10 = F_5 ( V_2 -> V_11 , L_2 ,
V_12 | V_13 ,
& V_14 ,
V_15 , F_6 ( V_15 ) ) ;
if ( V_10 )
return V_10 ;
F_7 ( V_9 , & V_14 ) ;
F_3 ( & V_2 -> V_11 -> V_4 , L_3 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
return F_9 ( V_17 , V_19 + V_17 -> V_20 ) ;
}
static int F_10 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_24 ;
V_24 -> V_25 . V_26 = 2 ;
F_11 ( V_24 , 0 , V_27 ,
& V_28 ) ;
V_24 -> V_25 . V_29 = V_30 ;
F_12 ( V_24 , 0 , 16 , 16 ) ;
F_11 ( V_24 , 0 ,
V_31 , & V_32 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
struct V_35 * V_36 = F_14 ( V_34 ,
V_31 ) ;
struct V_35 * V_37 = F_14 ( V_34 ,
V_27 ) ;
struct V_38 * V_39 = F_15 ( V_34 , V_40 ) ;
V_36 -> V_41 = V_36 -> V_42 = 48000 ;
V_37 -> V_41 = V_37 -> V_42 = 2 ;
F_16 ( V_39 ) ;
F_17 ( V_39 , V_43 ) ;
return 0 ;
}
static int F_18 ( struct V_21 * V_22 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 = V_22 -> V_44 ;
struct V_16 * V_18 = V_2 -> V_18 ;
int V_10 ;
V_10 = F_19 ( V_18 , V_45 , 24000000 ,
V_46 ) ;
if ( V_10 < 0 )
F_20 ( V_2 -> V_47 , L_4 , V_10 ) ;
return V_10 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
struct V_35 * V_37 = F_14 ( V_34 ,
V_27 ) ;
if ( F_22 ( V_34 ) == 2 )
V_37 -> V_41 = V_37 -> V_42 = 2 ;
else
V_37 -> V_41 = V_37 -> V_42 = 4 ;
return 0 ;
}
static int F_23 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_24 ;
V_24 -> V_25 . V_26 = 4 ;
F_11 ( V_24 , 0 , V_27 ,
& V_48 ) ;
return F_11 ( V_22 -> V_24 , 0 ,
V_31 , & V_32 ) ;
}
static int F_24 ( struct V_49 * V_50 )
{
V_51 . V_47 = & V_50 -> V_47 ;
return F_25 ( & V_50 -> V_47 , & V_51 ) ;
}
