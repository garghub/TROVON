static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_10 * V_11 = F_2 ( V_9 ) ;
if ( F_3 ( V_5 ) )
F_4 ( 70 ) ;
F_5 ( V_11 -> V_12 ,
F_3 ( V_5 ) ) ;
return 0 ;
}
static int F_6 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = F_7 ( V_16 ,
V_19 ) ;
struct V_17 * V_20 = F_7 ( V_16 ,
V_21 ) ;
V_18 -> V_22 = V_18 -> V_23 = 48000 ;
V_20 -> V_22 = V_20 -> V_23 = 2 ;
F_8 ( & V_16 -> V_24 [ V_25 -
V_26 ] ,
V_27 ) ;
return 0 ;
}
static int F_9 ( struct V_28 * V_29 ,
struct V_15 * V_16 )
{
struct V_13 * V_14 = V_29 -> V_30 ;
struct V_31 * V_32 = V_14 -> V_32 ;
int V_33 ;
V_33 = F_10 ( V_32 , V_34 , 24576000 ,
V_35 ) ;
if ( V_33 < 0 ) {
F_11 ( V_14 -> V_36 , L_1 ) ;
return V_33 ;
}
return V_33 ;
}
static int F_12 ( struct V_13 * V_14 )
{
struct V_37 * V_38 = F_13 ( V_14 -> V_39 -> V_36 ) ;
struct V_40 * V_41 = V_38 -> V_42 ;
int V_33 ;
V_33 = F_14 ( V_41 , V_43 ,
V_44 ,
V_45 , 9 ) ;
if ( V_33 < 0 ) {
F_11 ( V_14 -> V_36 , L_2 ) ;
return V_33 ;
}
return 0 ;
}
static int F_15 ( struct V_13 * V_14 )
{
struct V_10 * V_11 =
F_2 ( V_14 -> V_9 ) ;
struct V_46 * V_47 = V_14 -> V_47 ;
struct V_6 * V_7 = F_16 ( V_47 ) ;
F_17 ( V_47 , V_48 |
V_49 | V_50 ,
V_51 ) ;
V_11 -> V_12 = F_18 ( V_47 -> V_36 , L_3 ,
V_52 ) ;
if ( F_19 ( V_11 -> V_12 ) ) {
F_11 ( V_47 -> V_36 , L_4 ) ;
return F_20 ( V_11 -> V_12 ) ;
}
if ( ! F_21 ( V_14 -> V_9 , L_5 ,
V_53 , & V_54 ,
& V_55 , 1 ) ) {
V_56 . V_57 = V_47 -> V_36 ;
if ( F_22 ( & V_54 , 1 ,
& V_56 ) )
F_11 ( V_47 -> V_36 , L_6 ) ;
} else {
F_11 ( V_47 -> V_36 , L_7 ) ;
}
if ( ! F_21 ( V_14 -> V_9 , L_8 ,
V_58 , & V_59 ,
& V_60 , 1 ) ) {
V_61 . V_57 = V_47 -> V_36 ;
if ( F_22 ( & V_59 , 1 , & V_61 ) )
F_11 ( V_47 -> V_36 , L_9 ) ;
} else {
F_11 ( V_47 -> V_36 , L_10 ) ;
}
V_11 -> V_47 = V_47 ;
F_23 ( V_7 , L_11 ) ;
return 0 ;
}
static int F_24 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_2 ( V_9 ) ;
struct V_6 * V_7 ;
if ( V_11 -> V_47 ) {
V_7 = F_16 ( V_11 -> V_47 ) ;
F_25 ( V_7 , L_11 ) ;
}
return 0 ;
}
static int F_26 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_2 ( V_9 ) ;
struct V_6 * V_7 ;
if ( V_11 -> V_47 ) {
V_7 = F_16 ( V_11 -> V_47 ) ;
F_23 ( V_7 , L_11 ) ;
}
return 0 ;
}
static int F_27 ( struct V_62 * V_63 )
{
struct V_10 * V_11 ;
V_64 . V_36 = & V_63 -> V_36 ;
V_11 = F_28 ( & V_63 -> V_36 , sizeof( struct V_10 ) ,
V_65 ) ;
if ( ! V_11 ) {
F_11 ( & V_63 -> V_36 , L_12 ) ;
return - V_66 ;
}
F_29 ( & V_64 , V_11 ) ;
return F_30 ( & V_63 -> V_36 , & V_64 ) ;
}
