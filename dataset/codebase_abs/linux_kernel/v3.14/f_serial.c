static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_5 ) ;
}
static int F_3 ( struct V_2 * V_3 , unsigned V_6 , unsigned V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_3 -> V_11 -> V_10 ;
if ( V_8 -> V_4 . V_12 -> V_13 ) {
F_4 ( V_10 , L_1 , V_8 -> V_14 ) ;
F_5 ( & V_8 -> V_4 ) ;
}
if ( ! V_8 -> V_4 . V_12 -> V_15 || ! V_8 -> V_4 . V_16 -> V_15 ) {
F_4 ( V_10 , L_2 , V_8 -> V_14 ) ;
if ( F_6 ( V_10 -> V_17 , V_3 , V_8 -> V_4 . V_12 ) ||
F_6 ( V_10 -> V_17 , V_3 , V_8 -> V_4 . V_16 ) ) {
V_8 -> V_4 . V_12 -> V_15 = NULL ;
V_8 -> V_4 . V_16 -> V_15 = NULL ;
return - V_18 ;
}
}
F_7 ( & V_8 -> V_4 , V_8 -> V_14 ) ;
return 0 ;
}
static void F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_3 -> V_11 -> V_10 ;
F_4 ( V_10 , L_3 , V_8 -> V_14 ) ;
F_5 ( & V_8 -> V_4 ) ;
}
static int F_9 ( struct V_19 * V_20 , struct V_2 * V_3 )
{
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_21 ;
struct V_22 * V_23 ;
if ( V_24 [ 0 ] . V_25 == 0 ) {
V_21 = F_10 ( V_20 -> V_10 ) ;
if ( V_21 < 0 )
return V_21 ;
V_24 [ 0 ] . V_25 = V_21 ;
}
V_21 = F_11 ( V_20 , V_3 ) ;
if ( V_21 < 0 )
goto V_26;
V_8 -> V_27 = V_21 ;
V_28 . V_29 = V_21 ;
V_21 = - V_30 ;
V_23 = F_12 ( V_10 -> V_17 , & V_31 ) ;
if ( ! V_23 )
goto V_26;
V_8 -> V_4 . V_12 = V_23 ;
V_23 -> V_13 = V_10 ;
V_23 = F_12 ( V_10 -> V_17 , & V_32 ) ;
if ( ! V_23 )
goto V_26;
V_8 -> V_4 . V_16 = V_23 ;
V_23 -> V_13 = V_10 ;
V_33 . V_34 = V_31 . V_34 ;
V_35 . V_34 = V_32 . V_34 ;
V_36 . V_34 = V_31 . V_34 ;
V_37 . V_34 = V_32 . V_34 ;
V_21 = F_13 ( V_3 , V_38 , V_39 ,
V_40 ) ;
if ( V_21 )
goto V_26;
F_4 ( V_10 , L_4 ,
V_8 -> V_14 ,
F_14 ( V_20 -> V_10 -> V_17 ) ? L_5 :
F_15 ( V_20 -> V_10 -> V_17 ) ? L_6 : L_7 ,
V_8 -> V_4 . V_12 -> V_41 , V_8 -> V_4 . V_16 -> V_41 ) ;
return 0 ;
V_26:
if ( V_8 -> V_4 . V_16 )
V_8 -> V_4 . V_16 -> V_13 = NULL ;
if ( V_8 -> V_4 . V_12 )
V_8 -> V_4 . V_12 -> V_13 = NULL ;
ERROR ( V_10 , L_8 , V_3 -> V_41 , V_21 ) ;
return V_21 ;
}
static inline struct V_42 * F_16 ( struct V_43 * V_44 )
{
return F_2 ( F_17 ( V_44 ) , struct V_42 ,
V_45 . V_46 ) ;
}
static T_1 F_18 ( struct V_43 * V_44 ,
struct V_47 * V_48 ,
char * V_49 )
{
struct V_42 * V_50 = F_16 ( V_44 ) ;
struct V_51 * V_52 =
F_2 ( V_48 , struct V_51 , V_48 ) ;
T_1 V_53 = 0 ;
if ( V_52 -> V_54 )
V_53 = V_52 -> V_54 ( V_50 , V_49 ) ;
return V_53 ;
}
static void F_19 ( struct V_43 * V_44 )
{
struct V_42 * V_50 = F_16 ( V_44 ) ;
F_20 ( & V_50 -> V_45 ) ;
}
static T_1 F_21 ( struct V_42 * V_50 , char * V_49 )
{
return sprintf ( V_49 , L_9 , V_50 -> V_14 ) ;
}
static void F_22 ( struct V_55 * V_3 )
{
struct V_42 * V_50 ;
V_50 = F_2 ( V_3 , struct V_42 , V_45 ) ;
F_23 ( V_50 -> V_14 ) ;
F_24 ( V_50 ) ;
}
static struct V_55 * F_25 ( void )
{
struct V_42 * V_50 ;
int V_53 ;
V_50 = F_26 ( sizeof( * V_50 ) , V_56 ) ;
if ( ! V_50 )
return F_27 ( - V_57 ) ;
V_50 -> V_45 . V_58 = F_22 ;
V_53 = F_28 ( & V_50 -> V_14 ) ;
if ( V_53 ) {
F_24 ( V_50 ) ;
return F_27 ( V_53 ) ;
}
F_29 ( & V_50 -> V_45 . V_46 , L_10 ,
& V_59 ) ;
return & V_50 -> V_45 ;
}
static void F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_60 ;
V_60 = F_1 ( V_3 ) ;
F_24 ( V_60 ) ;
}
static void F_31 ( struct V_19 * V_20 , struct V_2 * V_3 )
{
F_32 ( V_3 ) ;
}
static struct V_2 * F_33 ( struct V_55 * V_61 )
{
struct V_1 * V_8 ;
struct V_42 * V_50 ;
V_8 = F_26 ( sizeof( * V_8 ) , V_56 ) ;
if ( ! V_8 )
return F_27 ( - V_57 ) ;
V_50 = F_2 ( V_61 , struct V_42 , V_45 ) ;
V_8 -> V_14 = V_50 -> V_14 ;
V_8 -> V_4 . V_5 . V_41 = L_11 ;
V_8 -> V_4 . V_5 . V_62 = V_63 ;
V_8 -> V_4 . V_5 . V_64 = F_9 ;
V_8 -> V_4 . V_5 . V_65 = F_31 ;
V_8 -> V_4 . V_5 . V_66 = F_3 ;
V_8 -> V_4 . V_5 . V_67 = F_8 ;
V_8 -> V_4 . V_5 . V_68 = F_30 ;
return & V_8 -> V_4 . V_5 ;
}
