static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_5 ) ;
}
static int F_3 ( struct V_2 * V_3 , unsigned V_6 , unsigned V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_3 -> V_11 -> V_10 ;
struct V_12 * V_13 ;
if ( V_8 -> V_4 . V_14 -> V_15 ) {
F_4 ( V_10 , L_1 ) ;
F_5 ( & V_8 -> V_4 ) ;
}
F_4 ( V_10 , L_2 ) ;
if ( F_6 ( V_10 -> V_16 , V_3 , V_8 -> V_4 . V_14 ) ||
F_6 ( V_10 -> V_16 , V_3 , V_8 -> V_4 . V_17 ) ) {
V_8 -> V_4 . V_14 -> V_18 = NULL ;
V_8 -> V_4 . V_17 -> V_18 = NULL ;
return - V_19 ;
}
V_13 = F_7 ( & V_8 -> V_4 ) ;
return F_8 ( V_13 ) ;
}
static void F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_3 -> V_11 -> V_10 ;
F_4 ( V_10 , L_3 ) ;
F_5 ( & V_8 -> V_4 ) ;
}
static int
F_10 ( struct V_20 * V_21 , struct V_2 * V_3 )
{
struct V_9 * V_10 = V_21 -> V_10 ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_22 * V_23 ;
int V_24 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
V_28 = F_2 ( V_3 -> V_29 , struct V_27 , V_30 ) ;
if ( ! V_28 -> V_31 ) {
F_11 ( & V_28 -> V_32 ) ;
F_12 ( V_28 -> V_13 , V_10 -> V_16 ) ;
V_24 = F_13 ( V_28 -> V_13 ) ;
F_14 ( & V_28 -> V_32 ) ;
if ( V_24 )
return V_24 ;
V_28 -> V_31 = true ;
}
V_23 = F_15 ( V_10 , V_33 ,
F_16 ( V_34 ) ) ;
if ( F_17 ( V_23 ) )
return F_18 ( V_23 ) ;
V_35 . V_36 = V_23 [ 0 ] . V_37 ;
V_38 . V_39 = V_23 [ 1 ] . V_37 ;
V_24 = F_19 ( V_21 , V_3 ) ;
if ( V_24 < 0 )
goto V_40;
V_35 . V_41 = V_24 ;
V_24 = - V_42 ;
V_26 = F_20 ( V_10 -> V_16 , & V_43 ) ;
if ( ! V_26 )
goto V_40;
V_8 -> V_4 . V_14 = V_26 ;
V_26 = F_20 ( V_10 -> V_16 , & V_44 ) ;
if ( ! V_26 )
goto V_40;
V_8 -> V_4 . V_17 = V_26 ;
V_45 . V_46 = V_43 . V_46 ;
V_47 . V_46 =
V_44 . V_46 ;
V_48 . V_46 = V_43 . V_46 ;
V_49 . V_46 =
V_44 . V_46 ;
V_24 = F_21 ( V_3 , V_50 , V_51 ,
V_52 ) ;
if ( V_24 )
goto V_40;
F_4 ( V_10 , L_4 ,
F_22 ( V_21 -> V_10 -> V_16 ) ? L_5 :
F_23 ( V_21 -> V_10 -> V_16 ) ? L_6 : L_7 ,
V_8 -> V_4 . V_14 -> V_53 , V_8 -> V_4 . V_17 -> V_53 ) ;
return 0 ;
V_40:
ERROR ( V_10 , L_8 , V_3 -> V_53 , V_24 ) ;
return V_24 ;
}
static inline struct V_27 * F_24 ( struct V_54 * V_55 )
{
return F_2 ( F_25 ( V_55 ) , struct V_27 ,
V_30 . V_56 ) ;
}
static void F_26 ( struct V_57 * V_3 )
{
struct V_27 * V_58 ;
V_58 = F_2 ( V_3 , struct V_27 , V_30 ) ;
if ( V_58 -> V_31 )
F_27 ( F_28 ( V_58 -> V_13 ) ) ;
else
F_29 ( V_58 -> V_13 ) ;
F_30 ( V_58 ) ;
}
static struct V_57 * F_31 ( void )
{
struct V_27 * V_58 ;
V_58 = F_32 ( sizeof( * V_58 ) , V_59 ) ;
if ( ! V_58 )
return F_33 ( - V_60 ) ;
F_34 ( & V_58 -> V_32 ) ;
V_58 -> V_30 . V_61 = F_26 ;
V_58 -> V_13 = F_35 () ;
if ( F_17 ( V_58 -> V_13 ) ) {
struct V_12 * V_13 = V_58 -> V_13 ;
F_30 ( V_58 ) ;
return F_36 ( V_13 ) ;
}
F_37 ( & V_58 -> V_30 . V_56 , L_9 ,
& V_62 ) ;
return & V_58 -> V_30 ;
}
static void F_38 ( struct V_2 * V_3 )
{
struct V_1 * V_63 ;
V_63 = F_1 ( V_3 ) ;
F_30 ( V_63 ) ;
}
static void F_39 ( struct V_20 * V_21 , struct V_2 * V_3 )
{
V_34 [ 0 ] . V_37 = 0 ;
F_40 ( V_3 ) ;
}
static struct V_2 * F_41 ( struct V_57 * V_29 )
{
struct V_1 * V_8 ;
struct V_27 * V_58 ;
int V_24 ;
V_8 = F_32 ( sizeof( * V_8 ) , V_59 ) ;
if ( ! V_8 )
return F_33 ( - V_60 ) ;
V_58 = F_2 ( V_29 , struct V_27 , V_30 ) ;
F_11 ( & V_58 -> V_32 ) ;
V_58 -> V_64 ++ ;
V_24 = F_42 ( V_58 -> V_13 , V_8 -> V_65 ,
sizeof( V_8 -> V_65 ) ) ;
if ( V_24 < 12 ) {
F_30 ( V_8 ) ;
F_14 ( & V_58 -> V_32 ) ;
return F_33 ( - V_19 ) ;
}
V_34 [ 1 ] . V_66 = V_8 -> V_65 ;
V_8 -> V_4 . V_67 = F_28 ( V_58 -> V_13 ) ;
F_14 ( & V_58 -> V_32 ) ;
V_8 -> V_4 . V_68 = V_69 ;
V_8 -> V_4 . V_5 . V_53 = L_10 ;
V_8 -> V_4 . V_5 . V_70 = F_10 ;
V_8 -> V_4 . V_5 . V_71 = F_39 ;
V_8 -> V_4 . V_5 . V_72 = F_3 ;
V_8 -> V_4 . V_5 . V_73 = F_9 ;
V_8 -> V_4 . V_5 . V_74 = F_38 ;
return & V_8 -> V_4 . V_5 ;
}
