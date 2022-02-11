static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 ,
V_3 ) ;
}
static inline struct V_1 *
F_3 ( struct V_4 * V_5 )
{
return F_2 ( V_5 , struct V_1 ,
V_5 ) ;
}
static int F_4 ( struct V_2 * V_3 )
{
struct V_1 * V_6 =
F_1 ( V_3 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
return F_5 ( V_8 -> V_9 ) ;
}
static int F_6 ( struct V_2 * V_3 ,
struct V_10 * V_11 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_12 = V_11 -> V_13 - V_11 -> V_14 ;
T_1 V_15 = V_11 -> V_16 - V_11 -> V_17 ;
unsigned long V_18 = V_11 -> clock * 1000 ;
long V_19 ;
F_7 ( L_1 ) ;
if ( V_12 < 1 )
return V_20 ;
if ( V_12 > 0x3ff )
return V_21 ;
if ( ( V_11 -> V_22 < 1 ) || ( V_11 -> V_23 < 1 ) )
return V_24 ;
if ( ( V_11 -> V_22 > 0x7ff ) || ( V_11 -> V_23 > 0xfff ) )
return V_25 ;
F_7 ( L_2 ) ;
if ( V_15 < 1 )
return V_26 ;
if ( V_15 > 0x3ff )
return V_27 ;
if ( ( V_11 -> V_28 < 1 ) || ( V_11 -> V_29 < 1 ) )
return V_30 ;
if ( ( V_11 -> V_28 > 0x7ff ) || ( V_11 -> V_29 > 0xfff ) )
return V_31 ;
F_7 ( L_3 ) ;
V_19 = F_8 ( V_8 -> V_32 , V_18 ) ;
if ( V_19 < V_18 )
return V_33 ;
if ( V_19 > V_18 )
return V_34 ;
F_7 ( L_4 ) ;
return V_35 ;
}
static void
F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
F_10 ( V_8 -> V_9 ) ;
F_11 ( V_3 ) ;
}
static void F_12 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
F_7 ( L_5 ) ;
if ( ! F_13 ( V_8 -> V_9 ) )
F_14 ( V_8 -> V_9 ) ;
F_15 ( V_8 , 0 ) ;
if ( ! F_13 ( V_8 -> V_9 ) )
F_16 ( V_8 -> V_9 ) ;
}
static void F_17 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
F_7 ( L_6 ) ;
if ( ! F_13 ( V_8 -> V_9 ) )
F_18 ( V_8 -> V_9 ) ;
F_19 ( V_8 , 0 ) ;
if ( ! F_13 ( V_8 -> V_9 ) )
F_20 ( V_8 -> V_9 ) ;
}
static void F_21 ( struct V_4 * V_5 ,
struct V_10 * V_11 ,
struct V_10 * V_36 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
F_22 ( V_8 , V_11 ) ;
F_23 ( V_8 , 0 , V_5 ) ;
F_24 ( V_8 -> V_32 , 120 ) ;
}
static void F_25 ( struct V_4 * V_5 )
{
F_26 ( V_5 ) ;
}
int F_27 ( struct V_37 * V_38 , struct V_7 * V_8 )
{
struct V_4 * V_5 ;
struct V_39 * V_40 ;
struct V_1 * V_6 ;
int V_41 ;
V_6 = F_28 ( V_38 -> V_42 , sizeof( * V_6 ) , V_43 ) ;
if ( ! V_6 )
return - V_44 ;
V_6 -> V_8 = V_8 ;
V_5 = & V_6 -> V_5 ;
V_41 = F_29 ( V_8 -> V_42 -> V_45 , 1 , 0 ,
& V_8 -> V_9 , & V_40 ) ;
if ( V_41 ) {
F_30 ( V_38 -> V_42 , L_7 ) ;
return 0 ;
}
F_31 ( & V_6 -> V_5 ,
& V_46 ) ;
V_41 = F_32 ( V_38 ,
& V_6 -> V_5 ,
& V_47 ,
V_48 ,
NULL ) ;
if ( V_41 ) {
F_33 ( V_38 -> V_42 , L_8 ) ;
goto V_49;
}
V_6 -> V_5 . V_50 = F_34 ( F_35 ( & V_8 -> V_51 -> V_51 ) ) ;
if ( V_8 -> V_9 ) {
F_36 ( & V_6 -> V_3 ,
& V_52 ) ;
V_41 = F_37 ( V_38 , & V_6 -> V_3 ,
& V_53 ,
V_54 ) ;
if ( V_41 ) {
F_33 ( V_38 -> V_42 , L_9 ) ;
goto V_55;
}
F_38 ( & V_6 -> V_3 ,
& V_6 -> V_5 ) ;
V_41 = F_39 ( V_8 -> V_9 , & V_6 -> V_3 ) ;
if ( V_41 ) {
F_33 ( V_38 -> V_42 , L_10 ) ;
goto V_55;
}
}
if ( V_40 ) {
V_41 = F_40 ( V_5 , V_40 , NULL ) ;
if ( V_41 ) {
F_33 ( V_38 -> V_42 , L_11 ) ;
goto V_55;
}
}
return 0 ;
V_55:
F_26 ( & V_6 -> V_5 ) ;
V_49:
return V_41 ;
}
