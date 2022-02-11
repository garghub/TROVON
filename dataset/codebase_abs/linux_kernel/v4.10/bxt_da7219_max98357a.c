static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ,
V_7 ) ;
struct V_5 * V_8 = F_2 ( V_4 ,
V_9 ) ;
struct V_10 * V_11 = F_3 ( V_4 , V_12 ) ;
V_6 -> V_13 = V_6 -> V_14 = 48000 ;
V_8 -> V_13 = V_8 -> V_14 = V_15 ;
F_4 ( V_11 ) ;
F_5 ( V_11 , V_16 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_17 ;
struct V_18 * V_19 = V_2 -> V_19 ;
V_17 = F_7 ( V_2 -> V_20 , L_1 ,
V_21 | V_22 | V_23 |
V_24 | V_25 | V_26 ,
& V_27 , NULL , 0 ) ;
if ( V_17 ) {
F_8 ( V_2 -> V_28 , L_2 , V_17 ) ;
return V_17 ;
}
F_9 ( V_19 , & V_27 ) ;
F_10 ( & V_2 -> V_20 -> V_29 , L_3 ) ;
return V_17 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = V_2 -> V_32 ;
return F_12 ( V_31 , V_33 + V_31 -> V_34 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_35 * V_29 ;
struct V_36 * V_37 = V_2 -> V_38 -> V_37 ;
V_29 = F_14 ( V_37 ) ;
F_10 ( V_29 , L_4 ) ;
return 0 ;
}
static int F_15 ( struct V_39 * V_40 )
{
struct V_41 * V_42 = V_40 -> V_42 ;
V_42 -> V_43 . V_44 = V_15 ;
F_16 ( V_42 , 0 , V_9 ,
& V_45 ) ;
V_42 -> V_43 . V_46 = V_47 ;
F_17 ( V_42 , 0 , 16 , 16 ) ;
F_16 ( V_42 , 0 ,
V_7 , & V_48 ) ;
return 0 ;
}
static int F_18 ( struct V_39 * V_40 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_40 -> V_49 ;
struct V_30 * V_32 = V_2 -> V_32 ;
int V_17 ;
V_17 = F_19 ( V_32 ,
V_50 , 19200000 , V_51 ) ;
if ( V_17 < 0 )
F_8 ( V_32 -> V_28 , L_5 ) ;
V_17 = F_20 ( V_32 , 0 ,
V_52 , 0 , V_53 ) ;
if ( V_17 < 0 ) {
F_8 ( V_32 -> V_28 , L_6 , V_17 ) ;
return - V_54 ;
}
return V_17 ;
}
static int F_21 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_49 ;
struct V_30 * V_32 = V_2 -> V_32 ;
int V_17 ;
V_17 = F_20 ( V_32 , 0 ,
V_55 , 0 , 0 ) ;
if ( V_17 < 0 ) {
F_8 ( V_32 -> V_28 , L_7 , V_17 ) ;
return - V_54 ;
}
return V_17 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_8 = F_2 ( V_4 ,
V_9 ) ;
if ( F_23 ( V_4 ) == 2 )
V_8 -> V_13 = V_8 -> V_14 = 2 ;
else
V_8 -> V_13 = V_8 -> V_14 = 4 ;
return 0 ;
}
static int F_24 ( struct V_39 * V_40 )
{
struct V_41 * V_42 = V_40 -> V_42 ;
V_42 -> V_43 . V_56 = V_42 -> V_43 . V_44 = V_57 ;
F_16 ( V_42 , 0 , V_9 ,
& V_58 ) ;
return F_16 ( V_40 -> V_42 , 0 ,
V_7 , & V_48 ) ;
}
static int F_25 ( struct V_39 * V_40 )
{
return F_16 ( V_40 -> V_42 , 0 ,
V_7 ,
& V_59 ) ;
}
static int F_26 ( struct V_60 * V_61 )
{
V_62 . V_28 = & V_61 -> V_28 ;
return F_27 ( & V_61 -> V_28 , & V_62 ) ;
}
