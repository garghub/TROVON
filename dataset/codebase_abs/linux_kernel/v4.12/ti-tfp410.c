static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_1 *
F_3 ( struct V_4 * V_5 )
{
return F_2 ( V_5 , struct V_1 , V_5 ) ;
}
static int F_4 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
struct V_7 * V_7 ;
int V_8 ;
if ( ! V_6 -> V_9 )
goto V_10;
V_7 = F_5 ( V_5 , V_6 -> V_9 ) ;
if ( ! V_7 ) {
F_6 ( L_1 ) ;
goto V_10;
}
F_7 ( V_5 , V_7 ) ;
return F_8 ( V_5 , V_7 ) ;
V_10:
V_8 = F_9 ( V_5 , 1920 , 1200 ) ;
F_10 ( V_5 , 1024 , 768 ) ;
return V_8 ;
}
static enum V_11
F_11 ( struct V_4 * V_5 , bool V_12 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
if ( V_6 -> V_13 ) {
if ( F_12 ( V_6 -> V_13 ) )
return V_14 ;
else
return V_15 ;
}
if ( V_6 -> V_9 ) {
if ( F_13 ( V_6 -> V_9 ) )
return V_14 ;
else
return V_15 ;
}
return V_16 ;
}
static int F_14 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_8 ;
if ( ! V_3 -> V_17 ) {
F_15 ( V_6 -> V_18 , L_2 ) ;
return - V_19 ;
}
if ( V_6 -> V_13 )
V_6 -> V_5 . V_20 = V_21 ;
F_16 ( & V_6 -> V_5 ,
& V_22 ) ;
V_8 = F_17 ( V_3 -> V_18 , & V_6 -> V_5 ,
& V_23 , V_24 ) ;
if ( V_8 ) {
F_15 ( V_6 -> V_18 , L_3 , V_8 ) ;
return V_8 ;
}
F_18 ( & V_6 -> V_5 ,
V_3 -> V_17 ) ;
return 0 ;
}
static void F_19 ( struct V_25 * V_26 )
{
struct V_1 * V_6 ;
V_6 = F_2 ( V_26 , struct V_1 , V_27 . V_26 ) ;
if ( V_6 -> V_3 . V_18 )
F_20 ( V_6 -> V_3 . V_18 ) ;
}
static T_1 F_21 ( int V_28 , void * V_29 )
{
struct V_1 * V_6 = V_29 ;
F_22 ( V_30 , & V_6 -> V_27 ,
F_23 ( V_31 ) ) ;
return V_32 ;
}
static int F_24 ( struct V_1 * V_6 )
{
struct V_33 * V_34 , * V_35 ;
int V_8 = 0 ;
V_34 = F_25 ( V_6 -> V_18 -> V_36 , 1 , - 1 ) ;
if ( ! V_34 )
return - V_19 ;
V_6 -> V_13 = F_26 ( & V_34 -> V_37 ,
L_4 , 0 , V_38 , L_5 ) ;
if ( F_27 ( V_6 -> V_13 ) ) {
V_8 = F_28 ( V_6 -> V_13 ) ;
V_6 -> V_13 = NULL ;
if ( V_8 == - V_39 )
V_8 = 0 ;
else
goto V_40;
}
V_35 = F_29 ( V_34 , L_6 , 0 ) ;
if ( ! V_35 )
goto V_40;
V_6 -> V_9 = F_30 ( V_35 ) ;
if ( V_6 -> V_9 )
F_31 ( V_6 -> V_18 , L_7 ) ;
else
V_8 = - V_41 ;
F_32 ( V_35 ) ;
V_40:
F_32 ( V_34 ) ;
return V_8 ;
}
static int F_33 ( struct V_42 * V_18 )
{
struct V_1 * V_6 ;
int V_8 ;
if ( ! V_18 -> V_36 ) {
F_15 ( V_18 , L_8 ) ;
return - V_43 ;
}
V_6 = F_34 ( V_18 , sizeof( * V_6 ) , V_44 ) ;
if ( ! V_6 )
return - V_45 ;
F_35 ( V_18 , V_6 ) ;
V_6 -> V_3 . V_46 = & V_47 ;
V_6 -> V_3 . V_36 = V_18 -> V_36 ;
V_6 -> V_18 = V_18 ;
V_8 = F_24 ( V_6 ) ;
if ( V_8 )
goto V_40;
if ( V_6 -> V_13 ) {
F_36 ( & V_6 -> V_27 , F_19 ) ;
V_8 = F_37 ( V_18 , F_38 ( V_6 -> V_13 ) ,
NULL , F_21 , V_48 |
V_49 | V_50 ,
L_9 , V_6 ) ;
if ( V_8 ) {
F_39 ( L_10 ) ;
goto V_40;
}
}
V_8 = F_40 ( & V_6 -> V_3 ) ;
if ( V_8 ) {
F_15 ( V_18 , L_11 , V_8 ) ;
goto V_40;
}
return 0 ;
V_40:
F_41 ( V_6 -> V_9 ) ;
if ( V_6 -> V_13 )
F_42 ( V_6 -> V_13 ) ;
return V_8 ;
}
static int F_43 ( struct V_42 * V_18 )
{
struct V_1 * V_6 = F_44 ( V_18 ) ;
F_45 ( & V_6 -> V_27 ) ;
F_46 ( & V_6 -> V_3 ) ;
if ( V_6 -> V_9 )
F_41 ( V_6 -> V_9 ) ;
if ( V_6 -> V_13 )
F_42 ( V_6 -> V_13 ) ;
return 0 ;
}
static int F_47 ( struct V_51 * V_52 )
{
return F_33 ( & V_52 -> V_18 ) ;
}
static int F_48 ( struct V_51 * V_52 )
{
return F_43 ( & V_52 -> V_18 ) ;
}
static int F_49 ( struct V_53 * V_54 ,
const struct V_55 * V_56 )
{
int V_57 ;
if ( ! V_54 -> V_18 . V_36 ||
F_50 ( V_54 -> V_18 . V_36 , L_12 , & V_57 ) ) {
F_15 ( & V_54 -> V_18 ,
L_13 ) ;
return - V_43 ;
}
return F_33 ( & V_54 -> V_18 ) ;
}
static int F_51 ( struct V_53 * V_54 )
{
return F_43 ( & V_54 -> V_18 ) ;
}
static int T_2 F_52 ( void )
{
int V_8 ;
#if F_53 ( V_58 )
V_8 = F_54 ( & V_59 ) ;
if ( V_8 )
F_55 ( L_14 ,
V_60 , V_8 ) ;
else
V_61 . V_62 = 1 ;
#endif
V_8 = F_56 ( & V_63 ) ;
if ( V_8 )
F_55 ( L_15 ,
V_60 , V_8 ) ;
else
V_61 . V_64 = 1 ;
if ( V_61 . V_62 ||
V_61 . V_64 )
return 0 ;
return V_8 ;
}
static void T_3 F_57 ( void )
{
#if F_53 ( V_58 )
if ( V_61 . V_62 )
F_58 ( & V_59 ) ;
#endif
if ( V_61 . V_64 )
F_59 ( & V_63 ) ;
}
