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
static struct V_4 *
F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_6 =
F_1 ( V_3 ) ;
return & V_6 -> V_5 ;
}
static enum V_38
F_10 ( struct V_2 * V_3 , bool V_39 )
{
return V_40 ;
}
static void
F_11 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_10 ;
F_12 ( V_10 -> V_11 ) ;
F_13 ( V_3 ) ;
}
static int F_14 ( struct V_4 * V_5 ,
struct V_41 * V_42 ,
struct V_43 * V_44 )
{
return 0 ;
}
static void F_15 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_10 ;
F_7 ( L_5 ) ;
F_16 ( V_10 -> V_11 ) ;
F_17 ( V_10 , 0 ) ;
}
static void F_18 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_10 ;
F_7 ( L_6 ) ;
F_19 ( V_10 , 0 ) ;
F_20 ( V_10 -> V_11 ) ;
}
static void F_21 ( struct V_4 * V_5 ,
struct V_12 * V_13 ,
struct V_12 * V_45 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_10 ;
F_22 ( V_10 , V_13 ) ;
F_23 ( V_10 -> V_34 , V_13 -> V_46 * 1000 ) ;
F_24 ( V_10 -> V_34 , 120 ) ;
}
static void F_25 ( struct V_4 * V_5 )
{
F_26 ( V_5 ) ;
}
int F_27 ( struct V_47 * V_48 )
{
struct V_7 * V_8 = V_48 -> V_49 ;
struct V_9 * V_10 = V_8 -> V_10 ;
struct V_1 * V_6 ;
int V_50 ;
if ( F_28 ( V_10 -> V_11 ) )
return - V_51 ;
V_6 = F_29 ( V_48 -> V_52 , sizeof( * V_6 ) , V_53 ) ;
if ( ! V_6 )
return - V_54 ;
V_6 -> V_8 = V_8 ;
F_30 ( & V_6 -> V_5 ,
& V_55 ) ;
V_50 = F_31 ( V_48 ,
& V_6 -> V_5 ,
& V_56 ,
V_57 ,
NULL ) ;
if ( V_50 ) {
F_32 ( V_48 -> V_52 , L_7 ) ;
goto V_58;
}
V_6 -> V_5 . V_59 = F_33 ( 0 ) ;
F_34 ( & V_6 -> V_3 ,
& V_60 ) ;
V_50 = F_35 ( V_48 , & V_6 -> V_3 ,
& V_61 ,
V_62 ) ;
if ( V_50 ) {
F_32 ( V_48 -> V_52 , L_8 ) ;
goto V_63;
}
F_36 ( & V_6 -> V_3 , & V_6 -> V_5 ) ;
F_37 ( V_10 -> V_11 , & V_6 -> V_3 ) ;
return 0 ;
V_63:
F_26 ( & V_6 -> V_5 ) ;
V_58:
return V_50 ;
}
