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
return F_8 ( V_13 ) ? F_9 ( V_13 ) : 0 ;
}
static void F_10 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_3 -> V_11 -> V_10 ;
F_4 ( V_10 , L_3 ) ;
F_5 ( & V_8 -> V_4 ) ;
}
static int
F_11 ( struct V_20 * V_21 , struct V_2 * V_3 )
{
struct V_9 * V_10 = V_21 -> V_10 ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_22 * V_23 ;
int V_24 ;
struct V_25 * V_26 ;
#ifndef F_12
struct V_27 * V_28 ;
V_28 = F_2 ( V_3 -> V_29 , struct V_27 , V_30 ) ;
if ( ! V_28 -> V_31 ) {
F_13 ( & V_28 -> V_32 ) ;
F_14 ( V_28 -> V_13 , V_10 -> V_16 ) ;
V_24 = F_15 ( V_28 -> V_13 ) ;
F_16 ( & V_28 -> V_32 ) ;
if ( V_24 )
return V_24 ;
V_28 -> V_31 = true ;
}
#endif
V_23 = F_17 ( V_10 , V_33 ,
F_18 ( V_34 ) ) ;
if ( F_8 ( V_23 ) )
return F_9 ( V_23 ) ;
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
V_26 -> V_15 = V_10 ;
V_26 = F_20 ( V_10 -> V_16 , & V_44 ) ;
if ( ! V_26 )
goto V_40;
V_8 -> V_4 . V_17 = V_26 ;
V_26 -> V_15 = V_10 ;
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
F_24 ( V_3 ) ;
if ( V_8 -> V_4 . V_17 )
V_8 -> V_4 . V_17 -> V_15 = NULL ;
if ( V_8 -> V_4 . V_14 )
V_8 -> V_4 . V_14 -> V_15 = NULL ;
ERROR ( V_10 , L_8 , V_3 -> V_53 , V_24 ) ;
return V_24 ;
}
static void
F_25 ( struct V_20 * V_21 , struct V_2 * V_3 )
{
V_34 [ 0 ] . V_37 = 0 ;
F_24 ( V_3 ) ;
F_26 ( F_1 ( V_3 ) ) ;
}
int F_27 ( struct V_20 * V_21 , T_1 V_54 [ V_55 ] ,
struct V_56 * V_57 )
{
struct V_1 * V_8 ;
int V_24 ;
V_8 = F_28 ( sizeof *V_8 , V_58 ) ;
if ( ! V_8 )
return - V_59 ;
snprintf ( V_8 -> V_54 , sizeof V_8 -> V_54 , L_9 , V_54 ) ;
V_34 [ 1 ] . V_60 = V_8 -> V_54 ;
V_8 -> V_4 . V_61 = V_57 ;
V_8 -> V_4 . V_62 = V_63 ;
V_8 -> V_4 . V_5 . V_53 = L_10 ;
V_8 -> V_4 . V_5 . V_64 = F_11 ;
V_8 -> V_4 . V_5 . V_65 = F_25 ;
V_8 -> V_4 . V_5 . V_66 = F_3 ;
V_8 -> V_4 . V_5 . V_67 = F_10 ;
V_24 = F_29 ( V_21 , & V_8 -> V_4 . V_5 ) ;
if ( V_24 )
F_26 ( V_8 ) ;
return V_24 ;
}
static inline struct V_27 * F_30 ( struct V_68 * V_69 )
{
return F_2 ( F_31 ( V_69 ) , struct V_27 ,
V_30 . V_70 ) ;
}
static void F_32 ( struct V_71 * V_3 )
{
struct V_27 * V_72 ;
V_72 = F_2 ( V_3 , struct V_27 , V_30 ) ;
if ( V_72 -> V_31 )
F_33 ( F_34 ( V_72 -> V_13 ) ) ;
else
F_35 ( V_72 -> V_13 ) ;
F_26 ( V_72 ) ;
}
static struct V_71 * F_36 ( void )
{
struct V_27 * V_72 ;
V_72 = F_28 ( sizeof( * V_72 ) , V_58 ) ;
if ( ! V_72 )
return F_37 ( - V_59 ) ;
F_38 ( & V_72 -> V_32 ) ;
V_72 -> V_30 . V_73 = F_32 ;
V_72 -> V_13 = F_39 () ;
if ( F_8 ( V_72 -> V_13 ) ) {
struct V_12 * V_13 = V_72 -> V_13 ;
F_26 ( V_72 ) ;
return F_40 ( V_13 ) ;
}
F_41 ( & V_72 -> V_30 . V_70 , L_11 ,
& V_74 ) ;
return & V_72 -> V_30 ;
}
static void F_42 ( struct V_2 * V_3 )
{
struct V_1 * V_75 ;
V_75 = F_1 ( V_3 ) ;
F_26 ( V_75 ) ;
}
static void F_43 ( struct V_20 * V_21 , struct V_2 * V_3 )
{
V_34 [ 0 ] . V_37 = 0 ;
F_24 ( V_3 ) ;
}
static struct V_2 * F_44 ( struct V_71 * V_29 )
{
struct V_1 * V_8 ;
struct V_27 * V_72 ;
int V_24 ;
V_8 = F_28 ( sizeof( * V_8 ) , V_58 ) ;
if ( ! V_8 )
return F_37 ( - V_59 ) ;
V_72 = F_2 ( V_29 , struct V_27 , V_30 ) ;
F_13 ( & V_72 -> V_32 ) ;
V_72 -> V_76 ++ ;
V_24 = F_45 ( V_72 -> V_13 , V_8 -> V_54 ,
sizeof( V_8 -> V_54 ) ) ;
if ( V_24 < 12 ) {
F_26 ( V_8 ) ;
F_16 ( & V_72 -> V_32 ) ;
return F_37 ( - V_19 ) ;
}
V_34 [ 1 ] . V_60 = V_8 -> V_54 ;
V_8 -> V_4 . V_61 = F_34 ( V_72 -> V_13 ) ;
F_16 ( & V_72 -> V_32 ) ;
V_8 -> V_4 . V_62 = V_63 ;
V_8 -> V_4 . V_5 . V_53 = L_10 ;
V_8 -> V_4 . V_5 . V_64 = F_11 ;
V_8 -> V_4 . V_5 . V_65 = F_43 ;
V_8 -> V_4 . V_5 . V_66 = F_3 ;
V_8 -> V_4 . V_5 . V_67 = F_10 ;
V_8 -> V_4 . V_5 . V_77 = F_42 ;
return & V_8 -> V_4 . V_5 ;
}
