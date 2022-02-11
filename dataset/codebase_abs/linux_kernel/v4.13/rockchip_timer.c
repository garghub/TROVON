static inline struct V_1 * V_1 ( struct V_2 * V_3 )
{
return & F_1 ( V_3 , struct V_4 , V_3 ) -> V_5 ;
}
static inline void F_2 ( struct V_1 * V_5 )
{
F_3 ( V_6 , V_5 -> V_7 ) ;
}
static inline void F_4 ( struct V_1 * V_5 , T_1 V_8 )
{
F_3 ( V_9 | V_8 , V_5 -> V_7 ) ;
}
static void F_5 ( unsigned long V_10 ,
struct V_1 * V_5 )
{
F_3 ( V_10 , V_5 -> V_11 + V_12 ) ;
F_3 ( 0 , V_5 -> V_11 + V_13 ) ;
}
static void F_6 ( struct V_1 * V_5 )
{
F_3 ( 1 , V_5 -> V_11 + V_14 ) ;
}
static inline int F_7 ( unsigned long V_10 ,
struct V_2 * V_3 )
{
struct V_1 * V_5 = V_1 ( V_3 ) ;
F_2 ( V_5 ) ;
F_5 ( V_10 , V_5 ) ;
F_4 ( V_5 , V_15 |
V_16 ) ;
return 0 ;
}
static int F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = V_1 ( V_3 ) ;
F_2 ( V_5 ) ;
return 0 ;
}
static int F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = V_1 ( V_3 ) ;
F_2 ( V_5 ) ;
F_5 ( V_5 -> V_17 / V_18 - 1 , V_5 ) ;
F_4 ( V_5 , V_19 | V_16 ) ;
return 0 ;
}
static T_2 F_10 ( int V_20 , void * V_21 )
{
struct V_2 * V_3 = V_21 ;
struct V_1 * V_5 = V_1 ( V_3 ) ;
F_6 ( V_5 ) ;
if ( F_11 ( V_3 ) )
F_2 ( V_5 ) ;
V_3 -> V_22 ( V_3 ) ;
return V_23 ;
}
static T_3 T_4 F_12 ( void )
{
return ~ F_13 ( V_24 -> V_11 + V_25 ) ;
}
static int T_5
F_14 ( struct V_1 * V_5 , struct V_26 * V_27 )
{
struct V_28 * V_29 ;
struct V_28 * V_30 ;
int V_31 = - V_32 , V_20 ;
T_1 V_33 = V_34 ;
V_5 -> V_11 = F_15 ( V_27 , 0 ) ;
if ( ! V_5 -> V_11 ) {
F_16 ( L_1 , V_35 ) ;
return - V_36 ;
}
if ( F_17 ( V_27 , L_2 ) )
V_33 = V_37 ;
V_5 -> V_7 = V_5 -> V_11 + V_33 ;
V_30 = F_18 ( V_27 , L_3 ) ;
if ( F_19 ( V_30 ) ) {
V_31 = F_20 ( V_30 ) ;
F_16 ( L_4 , V_35 ) ;
goto V_38;
}
V_31 = F_21 ( V_30 ) ;
if ( V_31 ) {
F_16 ( L_5 , V_35 ) ;
goto V_38;
}
V_5 -> V_30 = V_30 ;
V_29 = F_18 ( V_27 , L_6 ) ;
if ( F_19 ( V_29 ) ) {
V_31 = F_20 ( V_29 ) ;
F_16 ( L_7 , V_35 ) ;
goto V_39;
}
V_31 = F_21 ( V_29 ) ;
if ( V_31 ) {
F_16 ( L_8 ) ;
goto V_39;
}
V_5 -> V_28 = V_29 ;
V_5 -> V_17 = F_22 ( V_29 ) ;
V_20 = F_23 ( V_27 , 0 ) ;
if ( ! V_20 ) {
V_31 = - V_32 ;
F_16 ( L_9 , V_35 ) ;
goto V_40;
}
V_5 -> V_20 = V_20 ;
F_6 ( V_5 ) ;
F_2 ( V_5 ) ;
return 0 ;
V_40:
F_24 ( V_29 ) ;
V_39:
F_24 ( V_30 ) ;
V_38:
F_25 ( V_5 -> V_11 ) ;
return V_31 ;
}
static void T_5 F_26 ( struct V_1 * V_5 )
{
F_24 ( V_5 -> V_28 ) ;
F_24 ( V_5 -> V_30 ) ;
F_25 ( V_5 -> V_11 ) ;
}
static int T_5 F_27 ( struct V_26 * V_27 )
{
struct V_2 * V_3 ;
int V_31 = - V_32 ;
V_4 = F_28 ( sizeof( struct V_4 ) , V_41 ) ;
if ( ! V_4 ) {
V_31 = - V_42 ;
goto V_43;
}
V_31 = F_14 ( & V_4 -> V_5 , V_27 ) ;
if ( V_31 )
goto V_44;
V_3 = & V_4 -> V_3 ;
V_3 -> V_45 = V_35 ;
V_3 -> V_46 = V_47 | V_48 |
V_49 ;
V_3 -> V_50 = F_7 ;
V_3 -> V_51 = F_8 ;
V_3 -> V_52 = F_9 ;
V_3 -> V_20 = V_4 -> V_5 . V_20 ;
V_3 -> V_53 = V_54 ;
V_3 -> V_55 = 250 ;
V_31 = F_29 ( V_4 -> V_5 . V_20 , F_10 , V_56 ,
V_35 , V_3 ) ;
if ( V_31 ) {
F_16 ( L_10 ,
V_35 , V_31 ) ;
goto V_40;
}
F_30 ( & V_4 -> V_3 ,
V_4 -> V_5 . V_17 , 1 , V_57 ) ;
return 0 ;
V_40:
F_26 ( & V_4 -> V_5 ) ;
V_44:
F_31 ( V_4 ) ;
V_43:
V_4 = F_32 ( V_31 ) ;
return V_31 ;
}
static int T_5 F_33 ( struct V_26 * V_27 )
{
int V_31 = - V_32 ;
V_24 = F_28 ( sizeof( struct V_1 ) , V_41 ) ;
if ( ! V_24 ) {
V_31 = - V_42 ;
goto V_43;
}
V_31 = F_14 ( V_24 , V_27 ) ;
if ( V_31 )
goto V_44;
F_5 ( V_57 , V_24 ) ;
F_4 ( V_24 , 0 ) ;
V_31 = F_34 ( V_24 -> V_11 + V_25 ,
V_35 , V_24 -> V_17 , 250 , 32 ,
V_58 ) ;
if ( V_31 ) {
F_16 ( L_11 ) ;
goto V_59;
}
F_35 ( F_12 , 32 , V_24 -> V_17 ) ;
return 0 ;
V_59:
F_26 ( V_24 ) ;
V_44:
F_31 ( V_24 ) ;
V_43:
V_24 = F_32 ( V_31 ) ;
return V_31 ;
}
static int T_5 F_36 ( struct V_26 * V_27 )
{
if ( ! V_4 )
return F_27 ( V_27 ) ;
if ( ! V_24 )
return F_33 ( V_27 ) ;
F_16 ( L_12 , V_35 ) ;
return - V_32 ;
}
