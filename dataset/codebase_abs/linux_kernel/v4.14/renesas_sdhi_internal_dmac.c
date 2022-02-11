static void
F_1 ( struct V_1 * V_2 ,
int V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static void
F_3 ( struct V_1 * V_2 , bool V_6 )
{
if ( ! V_2 -> V_7 || ! V_2 -> V_8 )
return;
if ( ! V_6 )
F_1 ( V_2 , V_9 ,
V_10 ) ;
if ( V_2 -> V_11 -> V_6 )
V_2 -> V_11 -> V_6 ( V_2 , V_6 ) ;
}
static void
F_4 ( struct V_1 * V_2 ) {
T_1 V_4 = V_12 | V_13 ;
F_3 ( V_2 , false ) ;
F_1 ( V_2 , V_14 ,
V_15 & ~ V_4 ) ;
F_1 ( V_2 , V_14 ,
V_15 | V_4 ) ;
F_3 ( V_2 , true ) ;
}
static void
F_5 ( struct V_1 * V_2 ) {
F_6 ( & V_2 -> V_16 ) ;
}
static void
F_7 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
struct V_19 * V_20 = V_2 -> V_21 ;
T_2 V_22 = V_23 | V_24 ;
enum V_25 V_26 ;
int V_27 ;
T_2 V_28 ;
F_8 ( V_2 -> V_29 > 1 ) ;
if ( ! F_9 ( V_20 -> V_30 , 8 ) )
goto V_31;
if ( V_18 -> V_32 & V_33 ) {
V_22 |= V_34 ;
V_26 = V_35 ;
V_28 = V_36 ;
} else {
V_22 |= V_37 ;
V_26 = V_38 ;
V_28 = V_39 ;
}
V_27 = F_10 ( & V_2 -> V_40 -> V_41 , V_20 , V_2 -> V_29 , V_26 ) ;
if ( V_27 == 0 )
goto V_31;
F_3 ( V_2 , true ) ;
F_11 ( V_2 , V_28 ) ;
F_1 ( V_2 , V_42 ,
V_22 ) ;
F_1 ( V_2 , V_43 ,
V_20 -> V_44 ) ;
return;
V_31:
V_2 -> V_31 = true ;
F_3 ( V_2 , false ) ;
}
static void F_12 ( unsigned long V_45 )
{
struct V_1 * V_2 = (struct V_1 * ) V_45 ;
F_13 ( V_2 , V_46 ) ;
F_1 ( V_2 , V_47 ,
V_48 ) ;
}
static void F_14 ( unsigned long V_45 )
{
struct V_1 * V_2 = (struct V_1 * ) V_45 ;
enum V_25 V_26 ;
F_15 ( & V_2 -> V_49 ) ;
if ( ! V_2 -> V_18 )
goto V_50;
if ( V_2 -> V_18 -> V_32 & V_33 )
V_26 = V_35 ;
else
V_26 = V_38 ;
F_3 ( V_2 , false ) ;
F_16 ( & V_2 -> V_40 -> V_41 , V_2 -> V_21 , V_2 -> V_29 , V_26 ) ;
F_17 ( V_2 ) ;
V_50:
F_18 ( & V_2 -> V_49 ) ;
}
static void
F_19 ( struct V_1 * V_2 ,
struct V_51 * V_52 )
{
V_2 -> V_8 = V_2 -> V_7 = ( void * ) 0xdeadbeaf ;
F_20 ( & V_2 -> V_16 ,
F_14 ,
( unsigned long ) V_2 ) ;
F_20 ( & V_2 -> V_53 ,
F_12 ,
( unsigned long ) V_2 ) ;
}
static void
F_21 ( struct V_1 * V_2 )
{
V_2 -> V_8 = V_2 -> V_7 = NULL ;
}
static int F_22 ( struct V_54 * V_40 )
{
if ( ! F_23 ( V_55 ) )
return - V_56 ;
return F_24 ( V_40 , & V_57 ) ;
}
