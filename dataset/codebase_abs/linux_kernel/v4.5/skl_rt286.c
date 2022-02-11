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
F_3 ( & V_2 -> V_11 -> V_4 , L_4 ) ;
return 0 ;
}
static int F_8 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_19 ;
V_19 -> V_20 . V_21 = 2 ;
F_9 ( V_19 , 0 , V_22 ,
& V_23 ) ;
V_19 -> V_20 . V_24 = V_25 ;
F_10 ( V_19 , 0 , 16 , 16 ) ;
F_9 ( V_19 , 0 ,
V_26 , & V_27 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
struct V_30 * V_31 = F_12 ( V_29 ,
V_26 ) ;
struct V_30 * V_32 = F_12 ( V_29 ,
V_22 ) ;
struct V_33 * V_34 = F_13 ( V_29 , V_35 ) ;
V_31 -> V_36 = V_31 -> V_37 = 48000 ;
V_32 -> V_36 = V_32 -> V_37 = 2 ;
F_14 ( V_34 ) ;
F_15 ( V_34 , V_38 ) ;
return 0 ;
}
static int F_16 ( struct V_16 * V_17 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 = V_17 -> V_39 ;
struct V_40 * V_41 = V_2 -> V_41 ;
int V_10 ;
V_10 = F_17 ( V_41 , V_42 , 24000000 ,
V_43 ) ;
if ( V_10 < 0 )
F_18 ( V_2 -> V_44 , L_5 , V_10 ) ;
return V_10 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
struct V_30 * V_32 = F_12 ( V_29 ,
V_22 ) ;
if ( F_20 ( V_29 ) == 2 )
V_32 -> V_36 = V_32 -> V_37 = 2 ;
else
V_32 -> V_36 = V_32 -> V_37 = 4 ;
return 0 ;
}
static int F_21 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_19 ;
V_19 -> V_20 . V_21 = 4 ;
F_9 ( V_19 , 0 , V_22 ,
& V_45 ) ;
return F_9 ( V_17 -> V_19 , 0 ,
V_26 , & V_27 ) ;
}
static int F_22 ( struct V_46 * V_47 )
{
V_48 . V_44 = & V_47 -> V_44 ;
return F_23 ( & V_47 -> V_44 , & V_48 ) ;
}
