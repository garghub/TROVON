static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_6 = V_2 -> V_7 -> V_8 -> V_6 ;
T_1 V_9 = V_6 -> V_10 -> V_10 ;
struct V_11 * V_10 = NULL ;
int V_12 ;
for ( V_12 = 0 ; V_12 < F_3 ( V_13 ) ; V_12 ++ ) {
if ( V_13 [ V_12 ] . V_14 == V_9 )
V_10 = & V_13 [ V_12 ] ;
}
if ( F_4 ( ! V_10 ) )
return;
if ( V_10 -> V_14 == V_15 )
F_5 ( V_4 , V_16 ,
F_6 ( V_4 , V_16 ) |
V_17 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_18 * V_19 = & V_2 -> V_8 -> V_20 ;
T_2 V_21 ;
F_5 ( V_4 , V_22 ,
F_8 ( V_19 -> V_23 , V_19 -> V_24 ) ) ;
F_5 ( V_4 , V_25 ,
F_8 ( V_19 -> V_26 - V_19 -> V_27 ,
V_19 -> V_28 - V_19 -> V_27 ) ) ;
F_5 ( V_4 , V_29 ,
F_8 ( V_19 -> V_30 - V_19 -> V_31 ,
V_19 -> V_32 - V_19 -> V_31 ) ) ;
F_5 ( V_4 , V_33 ,
F_8 ( V_19 -> V_34 - V_19 -> V_35 ,
V_19 -> V_36 - V_19 -> V_37 ) ) ;
V_21 = F_6 ( V_4 , V_16 ) ;
if ( V_19 -> V_38 & V_39 )
V_21 |= V_40 << V_41 ;
else
V_21 &= ~ ( V_40 << V_41 ) ;
if ( V_19 -> V_38 & V_42 )
V_21 |= V_43 << V_44 ;
else
V_21 &= ~ ( V_43 << V_44 ) ;
F_5 ( V_4 , V_16 , V_21 ) ;
F_5 ( V_4 , V_45 , 0 ) ;
F_5 ( V_4 , V_46 , 1 ) ;
F_1 ( V_2 ) ;
F_9 ( V_4 -> V_47 , V_19 -> V_48 * 1000 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_11 ( V_4 -> V_47 ) ;
F_5 ( V_4 , V_16 ,
F_6 ( V_4 , V_16 ) |
V_49 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_2 -> V_7 -> V_6 )
return;
F_13 ( V_4 -> V_47 ) ;
F_5 ( V_4 , V_16 ,
F_6 ( V_4 , V_16 ) &
~ V_49 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_50 * V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_18 * V_51 = & V_8 -> V_20 ;
long V_52 , V_53 = V_51 -> clock * 1000 ;
V_52 = F_15 ( V_4 -> V_47 , V_53 ) ;
if ( V_52 != V_53 )
return - V_54 ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_50 * V_8 )
{
struct V_55 * V_56 = V_2 -> V_8 -> V_56 ;
if ( V_56 ) {
V_2 -> V_8 -> V_56 = NULL ;
F_17 ( & V_2 -> V_57 -> V_58 ) ;
F_18 ( V_2 , V_56 ) ;
F_19 ( & V_2 -> V_57 -> V_58 ) ;
}
}
static void F_20 ( struct V_59 * V_60 ,
struct V_61 * V_8 )
{
struct V_3 * V_4 ;
struct V_62 * V_63 ;
if ( ! V_60 -> V_8 -> V_2 || ! V_60 -> V_8 -> V_6 )
return;
V_4 = F_2 ( V_60 -> V_8 -> V_2 ) ;
V_63 = F_21 ( V_60 -> V_8 -> V_6 , 0 ) ;
F_5 ( V_4 , V_64 , V_63 -> V_65 ) ;
}
static void F_22 ( struct V_59 * V_60 )
{
F_23 ( V_60 ) ;
F_24 ( V_60 ) ;
}
static struct V_59 * F_25 ( struct V_66 * V_67 )
{
struct V_3 * V_4 = V_67 -> V_68 ;
struct V_59 * V_60 = NULL ;
T_2 V_69 [ F_3 ( V_13 ) ] , V_12 ;
int V_70 ;
V_60 = F_26 ( V_67 -> V_57 , sizeof( * V_60 ) , V_71 ) ;
if ( ! V_60 )
return F_27 ( - V_72 ) ;
for ( V_12 = 0 ; V_12 < F_3 ( V_13 ) ; V_12 ++ )
V_69 [ V_12 ] = V_13 [ V_12 ] . V_14 ;
V_70 = F_28 ( V_67 , V_60 , 0xff , & V_73 ,
V_69 , F_3 ( V_69 ) ,
V_74 , NULL ) ;
if ( V_70 )
return F_27 ( V_70 ) ;
F_29 ( V_60 , & V_75 ) ;
V_4 -> V_60 = V_60 ;
return V_60 ;
}
int F_30 ( struct V_66 * V_67 )
{
struct V_3 * V_4 = V_67 -> V_68 ;
struct V_59 * V_7 ;
int V_70 ;
V_7 = F_25 ( V_67 ) ;
if ( F_31 ( V_7 ) )
return F_32 ( V_7 ) ;
V_70 = F_33 ( V_67 , & V_4 -> V_2 , V_7 , NULL ,
& V_76 , NULL ) ;
if ( V_70 ) {
F_22 ( V_7 ) ;
return V_70 ;
}
F_34 ( & V_4 -> V_2 , & V_77 ) ;
return 0 ;
}
