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
V_24 | V_25 , & V_26 ,
NULL , 0 ) ;
if ( V_17 ) {
F_8 ( V_2 -> V_27 , L_2 , V_17 ) ;
return V_17 ;
}
F_9 ( V_19 , & V_26 ) ;
F_10 ( & V_2 -> V_20 -> V_28 , L_3 ) ;
return V_17 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = V_2 -> V_31 ;
return F_12 ( V_30 , V_32 + V_30 -> V_33 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_34 * V_28 ;
struct V_35 * V_36 = V_2 -> V_37 -> V_36 ;
V_28 = F_14 ( V_36 ) ;
F_10 ( V_28 , L_4 ) ;
return 0 ;
}
static int F_15 ( struct V_38 * V_39 )
{
struct V_40 * V_41 = V_39 -> V_41 ;
V_41 -> V_42 . V_43 = V_15 ;
F_16 ( V_41 , 0 , V_9 ,
& V_44 ) ;
V_41 -> V_42 . V_45 = V_46 ;
F_17 ( V_41 , 0 , 16 , 16 ) ;
F_16 ( V_41 , 0 ,
V_7 , & V_47 ) ;
return 0 ;
}
static int F_18 ( struct V_38 * V_39 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_39 -> V_48 ;
struct V_29 * V_31 = V_2 -> V_31 ;
int V_17 ;
V_17 = F_19 ( V_31 ,
V_49 , 19200000 , V_50 ) ;
if ( V_17 < 0 )
F_8 ( V_31 -> V_27 , L_5 ) ;
V_17 = F_20 ( V_31 , 0 ,
V_51 , 0 , V_52 ) ;
if ( V_17 < 0 ) {
F_8 ( V_31 -> V_27 , L_6 , V_17 ) ;
return - V_53 ;
}
return V_17 ;
}
static int F_21 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_48 ;
struct V_29 * V_31 = V_2 -> V_31 ;
int V_17 ;
V_17 = F_20 ( V_31 , 0 ,
V_54 , 0 , 0 ) ;
if ( V_17 < 0 ) {
F_8 ( V_31 -> V_27 , L_7 , V_17 ) ;
return - V_53 ;
}
return V_17 ;
}
static int F_22 ( struct V_55 * V_56 )
{
V_57 . V_27 = & V_56 -> V_27 ;
return F_23 ( & V_56 -> V_27 , & V_57 ) ;
}
