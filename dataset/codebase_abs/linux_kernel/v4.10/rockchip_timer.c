static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline void T_1 * F_3 ( struct V_2 * V_3 )
{
return F_1 ( V_3 ) -> V_4 ;
}
static inline void T_1 * F_4 ( struct V_2 * V_3 )
{
return F_1 ( V_3 ) -> V_5 ;
}
static inline void F_5 ( struct V_2 * V_3 )
{
F_6 ( V_6 , F_4 ( V_3 ) ) ;
}
static inline void F_7 ( struct V_2 * V_3 , T_2 V_7 )
{
F_6 ( V_8 | V_9 | V_7 ,
F_4 ( V_3 ) ) ;
}
static void F_8 ( unsigned long V_10 ,
struct V_2 * V_3 )
{
F_6 ( V_10 , F_3 ( V_3 ) + V_11 ) ;
F_6 ( 0 , F_3 ( V_3 ) + V_12 ) ;
}
static void F_9 ( struct V_2 * V_3 )
{
F_6 ( 1 , F_3 ( V_3 ) + V_13 ) ;
}
static inline int F_10 ( unsigned long V_10 ,
struct V_2 * V_3 )
{
F_5 ( V_3 ) ;
F_8 ( V_10 , V_3 ) ;
F_7 ( V_3 , V_14 ) ;
return 0 ;
}
static int F_11 ( struct V_2 * V_3 )
{
F_5 ( V_3 ) ;
return 0 ;
}
static int F_12 ( struct V_2 * V_3 )
{
F_5 ( V_3 ) ;
F_8 ( F_1 ( V_3 ) -> V_15 / V_16 - 1 , V_3 ) ;
F_7 ( V_3 , V_17 ) ;
return 0 ;
}
static T_3 F_13 ( int V_18 , void * V_19 )
{
struct V_2 * V_3 = V_19 ;
F_9 ( V_3 ) ;
if ( F_14 ( V_3 ) )
F_5 ( V_3 ) ;
V_3 -> V_20 ( V_3 ) ;
return V_21 ;
}
static int T_4 F_15 ( struct V_22 * V_23 , T_2 V_24 )
{
struct V_2 * V_3 = & V_1 . V_3 ;
struct V_25 * V_26 ;
struct V_25 * V_27 ;
int V_28 = - V_29 , V_18 ;
V_1 . V_4 = F_16 ( V_23 , 0 ) ;
if ( ! V_1 . V_4 ) {
F_17 ( L_1 , V_30 ) ;
return - V_31 ;
}
V_1 . V_5 = V_1 . V_4 + V_24 ;
V_27 = F_18 ( V_23 , L_2 ) ;
if ( F_19 ( V_27 ) ) {
V_28 = F_20 ( V_27 ) ;
F_17 ( L_3 , V_30 ) ;
goto V_32;
}
V_28 = F_21 ( V_27 ) ;
if ( V_28 ) {
F_17 ( L_4 , V_30 ) ;
goto V_32;
}
V_26 = F_18 ( V_23 , L_5 ) ;
if ( F_19 ( V_26 ) ) {
V_28 = F_20 ( V_26 ) ;
F_17 ( L_6 , V_30 ) ;
goto V_33;
}
V_28 = F_21 ( V_26 ) ;
if ( V_28 ) {
F_17 ( L_7 ) ;
goto V_33;
}
V_1 . V_15 = F_22 ( V_26 ) ;
V_18 = F_23 ( V_23 , 0 ) ;
if ( ! V_18 ) {
V_28 = - V_29 ;
F_17 ( L_8 , V_30 ) ;
goto V_34;
}
V_3 -> V_35 = V_30 ;
V_3 -> V_36 = V_37 | V_38 |
V_39 ;
V_3 -> V_40 = F_10 ;
V_3 -> V_41 = F_11 ;
V_3 -> V_42 = F_12 ;
V_3 -> V_18 = V_18 ;
V_3 -> V_43 = V_44 ;
V_3 -> V_45 = 250 ;
F_9 ( V_3 ) ;
F_5 ( V_3 ) ;
V_28 = F_24 ( V_18 , F_13 , V_46 , V_30 , V_3 ) ;
if ( V_28 ) {
F_17 ( L_9 , V_30 , V_28 ) ;
goto V_34;
}
F_25 ( V_3 , V_1 . V_15 , 1 , V_47 ) ;
return 0 ;
V_34:
F_26 ( V_26 ) ;
V_33:
F_26 ( V_27 ) ;
V_32:
F_27 ( V_1 . V_4 ) ;
return V_28 ;
}
static int T_4 F_28 ( struct V_22 * V_23 )
{
return F_15 ( V_23 , V_48 ) ;
}
static int T_4 F_29 ( struct V_22 * V_23 )
{
return F_15 ( V_23 , V_49 ) ;
}
