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
struct V_9 * V_10 = V_8 -> V_10 ;
return F_5 ( V_10 -> V_11 ) ;
}
static int F_6 ( struct V_2 * V_3 ,
struct V_12 * V_13 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_10 ;
T_1 V_14 = V_13 -> V_15 - V_13 -> V_16 ;
T_1 V_17 = V_13 -> V_18 - V_13 -> V_19 ;
unsigned long V_20 = V_13 -> clock * 1000 ;
long V_21 ;
F_7 ( L_1 ) ;
if ( V_14 < 1 )
return V_22 ;
if ( V_14 > 0x3ff )
return V_23 ;
if ( ( V_13 -> V_24 < 1 ) || ( V_13 -> V_25 < 1 ) )
return V_26 ;
if ( ( V_13 -> V_24 > 0x7ff ) || ( V_13 -> V_25 > 0xfff ) )
return V_27 ;
F_7 ( L_2 ) ;
if ( V_17 < 1 )
return V_28 ;
if ( V_17 > 0x3ff )
return V_29 ;
if ( ( V_13 -> V_30 < 1 ) || ( V_13 -> V_31 < 1 ) )
return V_32 ;
if ( ( V_13 -> V_30 > 0x7ff ) || ( V_13 -> V_31 > 0xfff ) )
return V_33 ;
F_7 ( L_3 ) ;
V_21 = F_8 ( V_10 -> V_34 , V_20 ) ;
if ( V_21 < V_20 )
return V_35 ;
if ( V_21 > V_20 )
return V_36 ;
F_7 ( L_4 ) ;
return V_37 ;
}
static void
F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_10 ;
F_10 ( V_10 -> V_11 ) ;
F_11 ( V_3 ) ;
}
static int F_12 ( struct V_4 * V_5 ,
struct V_38 * V_39 ,
struct V_40 * V_41 )
{
return 0 ;
}
static void F_13 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_10 ;
F_7 ( L_5 ) ;
if ( ! F_14 ( V_10 -> V_11 ) )
F_15 ( V_10 -> V_11 ) ;
F_16 ( V_10 , 0 ) ;
if ( ! F_14 ( V_10 -> V_11 ) )
F_17 ( V_10 -> V_11 ) ;
}
static void F_18 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_10 ;
F_7 ( L_6 ) ;
if ( ! F_14 ( V_10 -> V_11 ) )
F_19 ( V_10 -> V_11 ) ;
F_20 ( V_10 , 0 ) ;
if ( ! F_14 ( V_10 -> V_11 ) )
F_21 ( V_10 -> V_11 ) ;
}
static void F_22 ( struct V_4 * V_5 ,
struct V_12 * V_13 ,
struct V_12 * V_42 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_10 ;
F_23 ( V_10 , V_13 ) ;
F_24 ( V_10 -> V_34 , V_13 -> V_43 * 1000 ) ;
F_25 ( V_10 -> V_34 , 120 ) ;
}
static void F_26 ( struct V_4 * V_5 )
{
F_27 ( V_5 ) ;
}
int F_28 ( struct V_44 * V_45 )
{
struct V_7 * V_8 = V_45 -> V_46 ;
struct V_9 * V_10 = V_8 -> V_10 ;
struct V_4 * V_5 ;
struct V_47 * V_48 ;
struct V_1 * V_6 ;
int V_49 ;
V_6 = F_29 ( V_45 -> V_50 , sizeof( * V_6 ) , V_51 ) ;
if ( ! V_6 )
return - V_52 ;
V_6 -> V_8 = V_8 ;
V_5 = & V_6 -> V_5 ;
V_10 -> V_11 = F_30 ( V_10 -> V_50 -> V_53 ) ;
V_48 = F_31 ( V_10 -> V_50 -> V_53 ) ;
if ( F_14 ( V_10 -> V_11 ) && F_14 ( V_48 ) ) {
F_32 ( V_45 -> V_50 , L_7 ) ;
return 0 ;
}
F_33 ( & V_6 -> V_5 ,
& V_54 ) ;
V_49 = F_34 ( V_45 ,
& V_6 -> V_5 ,
& V_55 ,
V_56 ,
NULL ) ;
if ( V_49 ) {
F_35 ( V_45 -> V_50 , L_8 ) ;
goto V_57;
}
V_6 -> V_5 . V_58 = F_36 ( 0 ) ;
if ( ! F_14 ( V_10 -> V_11 ) ) {
F_37 ( & V_6 -> V_3 ,
& V_59 ) ;
V_49 = F_38 ( V_45 , & V_6 -> V_3 ,
& V_60 ,
V_61 ) ;
if ( V_49 ) {
F_35 ( V_45 -> V_50 , L_9 ) ;
goto V_62;
}
F_39 ( & V_6 -> V_3 ,
& V_6 -> V_5 ) ;
V_49 = F_40 ( V_10 -> V_11 , & V_6 -> V_3 ) ;
if ( V_49 ) {
F_35 ( V_45 -> V_50 , L_10 ) ;
goto V_62;
}
}
if ( ! F_14 ( V_48 ) ) {
V_49 = F_41 ( V_5 , V_48 , NULL ) ;
if ( V_49 ) {
F_35 ( V_45 -> V_50 , L_11 ) ;
goto V_62;
}
}
return 0 ;
V_62:
F_27 ( & V_6 -> V_5 ) ;
V_57:
return V_49 ;
}
