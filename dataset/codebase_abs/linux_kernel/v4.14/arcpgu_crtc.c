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
static enum V_18 F_7 ( struct V_1 * V_2 ,
const struct V_19 * V_20 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
long V_21 , V_22 = V_20 -> clock * 1000 ;
long V_23 = V_22 / 200 ;
V_21 = F_8 ( V_4 -> V_24 , V_22 ) ;
if ( ( F_9 ( V_21 , V_22 ) - F_10 ( V_21 , V_22 ) < V_23 ) && ( V_21 > 0 ) )
return V_25 ;
return V_26 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_19 * V_27 = & V_2 -> V_8 -> V_28 ;
T_2 V_29 ;
F_5 ( V_4 , V_30 ,
F_12 ( V_27 -> V_31 , V_27 -> V_32 ) ) ;
F_5 ( V_4 , V_33 ,
F_12 ( V_27 -> V_34 - V_27 -> V_35 ,
V_27 -> V_36 - V_27 -> V_35 ) ) ;
F_5 ( V_4 , V_37 ,
F_12 ( V_27 -> V_38 - V_27 -> V_39 ,
V_27 -> V_40 - V_27 -> V_39 ) ) ;
F_5 ( V_4 , V_41 ,
F_12 ( V_27 -> V_42 - V_27 -> V_43 ,
V_27 -> V_44 - V_27 -> V_45 ) ) ;
V_29 = F_6 ( V_4 , V_16 ) ;
if ( V_27 -> V_46 & V_47 )
V_29 |= V_48 << V_49 ;
else
V_29 &= ~ ( V_48 << V_49 ) ;
if ( V_27 -> V_46 & V_50 )
V_29 |= V_51 << V_52 ;
else
V_29 &= ~ ( V_51 << V_52 ) ;
F_5 ( V_4 , V_16 , V_29 ) ;
F_5 ( V_4 , V_53 , 0 ) ;
F_5 ( V_4 , V_54 , 1 ) ;
F_1 ( V_2 ) ;
F_13 ( V_4 -> V_24 , V_27 -> V_55 * 1000 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_56 * V_57 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_15 ( V_4 -> V_24 ) ;
F_5 ( V_4 , V_16 ,
F_6 ( V_4 , V_16 ) |
V_58 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_56 * V_57 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_2 -> V_7 -> V_6 )
return;
F_17 ( V_4 -> V_24 ) ;
F_5 ( V_4 , V_16 ,
F_6 ( V_4 , V_16 ) &
~ V_58 ) ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_56 * V_8 )
{
struct V_59 * V_60 = V_2 -> V_8 -> V_60 ;
if ( V_60 ) {
V_2 -> V_8 -> V_60 = NULL ;
F_19 ( & V_2 -> V_61 -> V_62 ) ;
F_20 ( V_2 , V_60 ) ;
F_21 ( & V_2 -> V_61 -> V_62 ) ;
}
}
static void F_22 ( struct V_63 * V_64 ,
struct V_65 * V_8 )
{
struct V_3 * V_4 ;
struct V_66 * V_67 ;
if ( ! V_64 -> V_8 -> V_2 || ! V_64 -> V_8 -> V_6 )
return;
V_4 = F_2 ( V_64 -> V_8 -> V_2 ) ;
V_67 = F_23 ( V_64 -> V_8 -> V_6 , 0 ) ;
F_5 ( V_4 , V_68 , V_67 -> V_69 ) ;
}
static void F_24 ( struct V_63 * V_64 )
{
F_25 ( V_64 ) ;
F_26 ( V_64 ) ;
}
static struct V_63 * F_27 ( struct V_70 * V_71 )
{
struct V_3 * V_4 = V_71 -> V_72 ;
struct V_63 * V_64 = NULL ;
T_2 V_73 [ F_3 ( V_13 ) ] , V_12 ;
int V_74 ;
V_64 = F_28 ( V_71 -> V_61 , sizeof( * V_64 ) , V_75 ) ;
if ( ! V_64 )
return F_29 ( - V_76 ) ;
for ( V_12 = 0 ; V_12 < F_3 ( V_13 ) ; V_12 ++ )
V_73 [ V_12 ] = V_13 [ V_12 ] . V_14 ;
V_74 = F_30 ( V_71 , V_64 , 0xff , & V_77 ,
V_73 , F_3 ( V_73 ) ,
NULL ,
V_78 , NULL ) ;
if ( V_74 )
return F_29 ( V_74 ) ;
F_31 ( V_64 , & V_79 ) ;
V_4 -> V_64 = V_64 ;
return V_64 ;
}
int F_32 ( struct V_70 * V_71 )
{
struct V_3 * V_4 = V_71 -> V_72 ;
struct V_63 * V_7 ;
int V_74 ;
V_7 = F_27 ( V_71 ) ;
if ( F_33 ( V_7 ) )
return F_34 ( V_7 ) ;
V_74 = F_35 ( V_71 , & V_4 -> V_2 , V_7 , NULL ,
& V_80 , NULL ) ;
if ( V_74 ) {
F_24 ( V_7 ) ;
return V_74 ;
}
F_36 ( & V_4 -> V_2 , & V_81 ) ;
return 0 ;
}
