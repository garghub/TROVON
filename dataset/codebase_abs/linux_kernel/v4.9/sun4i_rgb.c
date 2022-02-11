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
static enum V_38
F_9 ( struct V_2 * V_3 , bool V_39 )
{
return V_40 ;
}
static void
F_10 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_10 ;
F_11 ( V_10 -> V_11 ) ;
F_12 ( V_3 ) ;
}
static int F_13 ( struct V_4 * V_5 ,
struct V_41 * V_42 ,
struct V_43 * V_44 )
{
return 0 ;
}
static void F_14 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_10 ;
F_7 ( L_5 ) ;
if ( ! F_15 ( V_10 -> V_11 ) )
F_16 ( V_10 -> V_11 ) ;
F_17 ( V_10 , 0 ) ;
if ( ! F_15 ( V_10 -> V_11 ) )
F_18 ( V_10 -> V_11 ) ;
}
static void F_19 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_10 ;
F_7 ( L_6 ) ;
if ( ! F_15 ( V_10 -> V_11 ) )
F_20 ( V_10 -> V_11 ) ;
F_21 ( V_10 , 0 ) ;
if ( ! F_15 ( V_10 -> V_11 ) )
F_22 ( V_10 -> V_11 ) ;
}
static void F_23 ( struct V_4 * V_5 ,
struct V_12 * V_13 ,
struct V_12 * V_45 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_10 ;
F_24 ( V_10 , V_13 ) ;
F_25 ( V_10 -> V_34 , V_13 -> V_46 * 1000 ) ;
F_26 ( V_10 -> V_34 , 120 ) ;
}
static void F_27 ( struct V_4 * V_5 )
{
F_28 ( V_5 ) ;
}
int F_29 ( struct V_47 * V_48 )
{
struct V_7 * V_8 = V_48 -> V_49 ;
struct V_9 * V_10 = V_8 -> V_10 ;
struct V_4 * V_5 ;
struct V_1 * V_6 ;
int V_50 ;
V_6 = F_30 ( V_48 -> V_51 , sizeof( * V_6 ) , V_52 ) ;
if ( ! V_6 )
return - V_53 ;
V_6 -> V_8 = V_8 ;
V_5 = & V_6 -> V_5 ;
V_10 -> V_11 = F_31 ( V_10 -> V_51 -> V_54 ) ;
V_5 -> V_55 = F_32 ( V_10 -> V_51 -> V_54 ) ;
if ( F_15 ( V_10 -> V_11 ) && F_15 ( V_5 -> V_55 ) ) {
F_33 ( V_48 -> V_51 , L_7 ) ;
return 0 ;
}
F_34 ( & V_6 -> V_5 ,
& V_56 ) ;
V_50 = F_35 ( V_48 ,
& V_6 -> V_5 ,
& V_57 ,
V_58 ,
NULL ) ;
if ( V_50 ) {
F_36 ( V_48 -> V_51 , L_8 ) ;
goto V_59;
}
V_6 -> V_5 . V_60 = F_37 ( 0 ) ;
if ( ! F_15 ( V_10 -> V_11 ) ) {
F_38 ( & V_6 -> V_3 ,
& V_61 ) ;
V_50 = F_39 ( V_48 , & V_6 -> V_3 ,
& V_62 ,
V_63 ) ;
if ( V_50 ) {
F_36 ( V_48 -> V_51 , L_9 ) ;
goto V_64;
}
F_40 ( & V_6 -> V_3 ,
& V_6 -> V_5 ) ;
V_50 = F_41 ( V_10 -> V_11 , & V_6 -> V_3 ) ;
if ( V_50 ) {
F_36 ( V_48 -> V_51 , L_10 ) ;
goto V_64;
}
}
if ( ! F_15 ( V_5 -> V_55 ) ) {
V_5 -> V_55 -> V_5 = & V_6 -> V_5 ;
V_50 = F_42 ( V_48 , V_5 -> V_55 ) ;
if ( V_50 ) {
F_36 ( V_48 -> V_51 , L_11 ) ;
goto V_64;
}
} else {
V_5 -> V_55 = NULL ;
}
return 0 ;
V_64:
F_28 ( & V_6 -> V_5 ) ;
V_59:
return V_50 ;
}
