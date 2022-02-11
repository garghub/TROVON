static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 = V_2 -> V_6 -> V_7 -> V_8 -> V_5 ;
struct V_9 * V_10 = NULL ;
int V_11 ;
for ( V_11 = 0 ; V_11 < F_3 ( V_12 ) ; V_11 ++ ) {
if ( V_12 [ V_11 ] . V_13 == V_5 )
V_10 = & V_12 [ V_11 ] ;
}
if ( F_4 ( ! V_10 ) )
return;
if ( V_10 -> V_13 == V_14 )
F_5 ( V_4 , V_15 ,
F_6 ( V_4 , V_15 ) |
V_16 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_17 * V_18 = & V_2 -> V_7 -> V_19 ;
T_2 V_20 ;
F_5 ( V_4 , V_21 ,
F_8 ( V_18 -> V_22 , V_18 -> V_23 ) ) ;
F_5 ( V_4 , V_24 ,
F_8 ( V_18 -> V_25 - V_18 -> V_26 ,
V_18 -> V_27 - V_18 -> V_26 ) ) ;
F_5 ( V_4 , V_28 ,
F_8 ( V_18 -> V_29 - V_18 -> V_30 ,
V_18 -> V_31 - V_18 -> V_30 ) ) ;
F_5 ( V_4 , V_32 ,
F_8 ( V_18 -> V_33 - V_18 -> V_34 ,
V_18 -> V_35 - V_18 -> V_36 ) ) ;
V_20 = F_6 ( V_4 , V_15 ) ;
if ( V_18 -> V_37 & V_38 )
V_20 |= V_39 << V_40 ;
else
V_20 &= ~ ( V_39 << V_40 ) ;
if ( V_18 -> V_37 & V_41 )
V_20 |= V_42 << V_43 ;
else
V_20 &= ~ ( V_42 << V_43 ) ;
F_5 ( V_4 , V_15 , V_20 ) ;
F_5 ( V_4 , V_44 , 0 ) ;
F_5 ( V_4 , V_45 , 1 ) ;
F_1 ( V_2 ) ;
F_9 ( V_4 -> V_46 , V_18 -> V_47 * 1000 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_11 ( V_4 -> V_46 ) ;
F_5 ( V_4 , V_15 ,
F_6 ( V_4 , V_15 ) |
V_48 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_2 -> V_6 -> V_8 )
return;
F_13 ( V_4 -> V_46 ) ;
F_5 ( V_4 , V_15 ,
F_6 ( V_4 , V_15 ) &
~ V_48 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_49 * V_7 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_17 * V_50 = & V_7 -> V_19 ;
long V_51 , V_52 = V_50 -> clock * 1000 ;
V_51 = F_15 ( V_4 -> V_46 , V_52 ) ;
if ( V_51 != V_52 )
return - V_53 ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_49 * V_7 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_37 ;
if ( V_2 -> V_7 -> V_54 ) {
struct V_55 * V_54 = V_2 -> V_7 -> V_54 ;
V_2 -> V_7 -> V_54 = NULL ;
V_54 -> V_56 = F_17 ( V_2 ) ;
F_4 ( F_18 ( V_2 ) != 0 ) ;
F_19 ( & V_2 -> V_57 -> V_58 , V_37 ) ;
F_20 ( & V_54 -> V_59 . V_60 , & V_4 -> V_61 ) ;
F_21 ( & V_2 -> V_57 -> V_58 , V_37 ) ;
}
}
static void F_22 ( struct V_62 * V_63 ,
struct V_64 * V_7 )
{
struct V_3 * V_4 ;
struct V_65 * V_66 ;
if ( ! V_63 -> V_7 -> V_2 || ! V_63 -> V_7 -> V_8 )
return;
V_4 = F_2 ( V_63 -> V_7 -> V_2 ) ;
V_66 = F_23 ( V_63 -> V_7 -> V_8 , 0 ) ;
F_5 ( V_4 , V_67 , V_66 -> V_68 ) ;
}
static void F_24 ( struct V_62 * V_63 )
{
F_25 ( V_63 ) ;
F_26 ( V_63 ) ;
}
static struct V_62 * F_27 ( struct V_69 * V_70 )
{
struct V_3 * V_4 = V_70 -> V_71 ;
struct V_62 * V_63 = NULL ;
T_2 V_72 [ F_3 ( V_12 ) ] , V_11 ;
int V_73 ;
V_63 = F_28 ( V_70 -> V_57 , sizeof( * V_63 ) , V_74 ) ;
if ( ! V_63 )
return F_29 ( - V_75 ) ;
for ( V_11 = 0 ; V_11 < F_3 ( V_12 ) ; V_11 ++ )
V_72 [ V_11 ] = V_12 [ V_11 ] . V_13 ;
V_73 = F_30 ( V_70 , V_63 , 0xff , & V_76 ,
V_72 , F_3 ( V_72 ) ,
V_77 , NULL ) ;
if ( V_73 )
return F_29 ( V_73 ) ;
F_31 ( V_63 , & V_78 ) ;
V_4 -> V_63 = V_63 ;
return V_63 ;
}
int F_32 ( struct V_69 * V_70 )
{
struct V_3 * V_4 = V_70 -> V_71 ;
struct V_62 * V_6 ;
int V_73 ;
V_6 = F_27 ( V_70 ) ;
if ( F_33 ( V_6 ) )
return F_34 ( V_6 ) ;
V_73 = F_35 ( V_70 , & V_4 -> V_2 , V_6 , NULL ,
& V_79 , NULL ) ;
if ( V_73 ) {
F_24 ( V_6 ) ;
return V_73 ;
}
F_36 ( & V_4 -> V_2 , & V_80 ) ;
return 0 ;
}
