static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_5 ) ;
}
static int F_3 ( struct V_2 * V_3 , unsigned V_6 , unsigned V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_3 -> V_11 -> V_10 ;
if ( V_8 -> V_4 . V_12 -> V_13 ) {
F_4 ( & V_10 -> V_14 -> V_15 ,
L_1 , V_8 -> V_16 ) ;
F_5 ( & V_8 -> V_4 ) ;
}
if ( ! V_8 -> V_4 . V_12 -> V_17 || ! V_8 -> V_4 . V_18 -> V_17 ) {
F_4 ( & V_10 -> V_14 -> V_15 ,
L_2 , V_8 -> V_16 ) ;
if ( F_6 ( V_10 -> V_14 , V_3 , V_8 -> V_4 . V_12 ) ||
F_6 ( V_10 -> V_14 , V_3 , V_8 -> V_4 . V_18 ) ) {
V_8 -> V_4 . V_12 -> V_17 = NULL ;
V_8 -> V_4 . V_18 -> V_17 = NULL ;
return - V_19 ;
}
}
F_7 ( & V_8 -> V_4 , V_8 -> V_16 ) ;
return 0 ;
}
static void F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_3 -> V_11 -> V_10 ;
F_4 ( & V_10 -> V_14 -> V_15 ,
L_3 , V_8 -> V_16 ) ;
F_5 ( & V_8 -> V_4 ) ;
}
static int F_9 ( struct V_20 * V_21 , struct V_2 * V_3 )
{
struct V_9 * V_10 = V_21 -> V_10 ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_22 ;
struct V_23 * V_24 ;
if ( V_25 [ 0 ] . V_26 == 0 ) {
V_22 = F_10 ( V_21 -> V_10 ) ;
if ( V_22 < 0 )
return V_22 ;
V_25 [ 0 ] . V_26 = V_22 ;
}
V_22 = F_11 ( V_21 , V_3 ) ;
if ( V_22 < 0 )
goto V_27;
V_8 -> V_28 = V_22 ;
V_29 . V_30 = V_22 ;
V_22 = - V_31 ;
V_24 = F_12 ( V_10 -> V_14 , & V_32 ) ;
if ( ! V_24 )
goto V_27;
V_8 -> V_4 . V_12 = V_24 ;
V_24 -> V_13 = V_10 ;
V_24 = F_12 ( V_10 -> V_14 , & V_33 ) ;
if ( ! V_24 )
goto V_27;
V_8 -> V_4 . V_18 = V_24 ;
V_24 -> V_13 = V_10 ;
V_34 . V_35 = V_32 . V_35 ;
V_36 . V_35 = V_33 . V_35 ;
V_37 . V_35 = V_32 . V_35 ;
V_38 . V_35 = V_33 . V_35 ;
V_22 = F_13 ( V_3 , V_39 , V_40 ,
V_41 ) ;
if ( V_22 )
goto V_27;
F_4 ( & V_10 -> V_14 -> V_15 , L_4 ,
V_8 -> V_16 ,
F_14 ( V_21 -> V_10 -> V_14 ) ? L_5 :
F_15 ( V_21 -> V_10 -> V_14 ) ? L_6 : L_7 ,
V_8 -> V_4 . V_12 -> V_42 , V_8 -> V_4 . V_18 -> V_42 ) ;
return 0 ;
V_27:
if ( V_8 -> V_4 . V_18 )
V_8 -> V_4 . V_18 -> V_13 = NULL ;
if ( V_8 -> V_4 . V_12 )
V_8 -> V_4 . V_12 -> V_13 = NULL ;
ERROR ( V_10 , L_8 , V_3 -> V_42 , V_22 ) ;
return V_22 ;
}
static inline struct V_43 * F_16 ( struct V_44 * V_45 )
{
return F_2 ( F_17 ( V_45 ) , struct V_43 ,
V_46 . V_47 ) ;
}
static T_1 F_18 ( struct V_44 * V_45 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_43 * V_51 = F_16 ( V_45 ) ;
struct V_52 * V_53 =
F_2 ( V_49 , struct V_52 , V_49 ) ;
T_1 V_54 = 0 ;
if ( V_53 -> V_55 )
V_54 = V_53 -> V_55 ( V_51 , V_50 ) ;
return V_54 ;
}
static void F_19 ( struct V_44 * V_45 )
{
struct V_43 * V_51 = F_16 ( V_45 ) ;
F_20 ( & V_51 -> V_46 ) ;
}
static T_1 F_21 ( struct V_43 * V_51 , char * V_50 )
{
return sprintf ( V_50 , L_9 , V_51 -> V_16 ) ;
}
static void F_22 ( struct V_56 * V_3 )
{
struct V_43 * V_51 ;
V_51 = F_2 ( V_3 , struct V_43 , V_46 ) ;
F_23 ( V_51 -> V_16 ) ;
F_24 ( V_51 ) ;
}
static struct V_56 * F_25 ( void )
{
struct V_43 * V_51 ;
int V_54 ;
V_51 = F_26 ( sizeof( * V_51 ) , V_57 ) ;
if ( ! V_51 )
return F_27 ( - V_58 ) ;
V_51 -> V_46 . V_59 = F_22 ;
V_54 = F_28 ( & V_51 -> V_16 ) ;
if ( V_54 ) {
F_24 ( V_51 ) ;
return F_27 ( V_54 ) ;
}
F_29 ( & V_51 -> V_46 . V_47 , L_10 ,
& V_60 ) ;
return & V_51 -> V_46 ;
}
static void F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_61 ;
V_61 = F_1 ( V_3 ) ;
F_24 ( V_61 ) ;
}
static void F_31 ( struct V_20 * V_21 , struct V_2 * V_3 )
{
F_32 ( V_3 ) ;
}
static struct V_2 * F_33 ( struct V_56 * V_62 )
{
struct V_1 * V_8 ;
struct V_43 * V_51 ;
V_8 = F_26 ( sizeof( * V_8 ) , V_57 ) ;
if ( ! V_8 )
return F_27 ( - V_58 ) ;
V_51 = F_2 ( V_62 , struct V_43 , V_46 ) ;
V_8 -> V_16 = V_51 -> V_16 ;
V_8 -> V_4 . V_5 . V_42 = L_11 ;
V_8 -> V_4 . V_5 . V_63 = V_64 ;
V_8 -> V_4 . V_5 . V_65 = F_9 ;
V_8 -> V_4 . V_5 . V_66 = F_31 ;
V_8 -> V_4 . V_5 . V_67 = F_3 ;
V_8 -> V_4 . V_5 . V_68 = F_8 ;
V_8 -> V_4 . V_5 . V_69 = F_30 ;
return & V_8 -> V_4 . V_5 ;
}
