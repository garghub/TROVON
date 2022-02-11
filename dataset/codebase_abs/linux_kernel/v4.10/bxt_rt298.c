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
int V_10 = 0 ;
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
static int F_10 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 = F_11 ( V_22 ,
V_25 ) ;
struct V_23 * V_26 = F_11 ( V_22 ,
V_27 ) ;
struct V_28 * V_29 = F_12 ( V_22 , V_30 ) ;
V_24 -> V_31 = V_24 -> V_32 = 48000 ;
V_26 -> V_31 = V_26 -> V_32 = 2 ;
F_13 ( V_29 ) ;
F_14 ( V_29 , V_33 ) ;
return 0 ;
}
static int F_15 ( struct V_34 * V_35 ,
struct V_21 * V_22 )
{
struct V_1 * V_2 = V_35 -> V_36 ;
struct V_16 * V_18 = V_2 -> V_18 ;
int V_10 ;
V_10 = F_16 ( V_18 , V_37 ,
19200000 , V_38 ) ;
if ( V_10 < 0 ) {
F_17 ( V_2 -> V_39 , L_4 ) ;
return V_10 ;
}
return V_10 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_23 * V_26 = F_11 ( V_22 ,
V_27 ) ;
if ( F_19 ( V_22 ) == 2 )
V_26 -> V_31 = V_26 -> V_32 = 2 ;
else
V_26 -> V_31 = V_26 -> V_32 = 4 ;
return 0 ;
}
static int F_20 ( struct V_34 * V_35 )
{
struct V_40 * V_41 = V_35 -> V_41 ;
V_41 -> V_42 . V_43 = 4 ;
F_21 ( V_41 , 0 , V_27 ,
& V_44 ) ;
return F_21 ( V_35 -> V_41 , 0 ,
V_25 , & V_45 ) ;
}
static int F_22 ( struct V_34 * V_35 )
{
struct V_40 * V_41 = V_35 -> V_41 ;
V_41 -> V_42 . V_43 = 2 ;
F_21 ( V_41 , 0 , V_27 ,
& V_46 ) ;
F_21 ( V_41 , 0 ,
V_25 , & V_45 ) ;
return 0 ;
}
static int F_23 ( struct V_47 * V_48 )
{
V_49 . V_39 = & V_48 -> V_39 ;
return F_24 ( & V_48 -> V_39 , & V_49 ) ;
}
