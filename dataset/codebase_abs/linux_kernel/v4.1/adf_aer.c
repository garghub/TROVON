static T_1 F_1 ( struct V_1 * V_2 ,
T_2 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( & V_2 -> V_6 , L_1 ) ;
if ( ! V_5 ) {
F_4 ( & V_2 -> V_6 , L_2 ) ;
return V_7 ;
}
if ( V_3 == V_8 ) {
F_4 ( & V_2 -> V_6 , L_3 ) ;
return V_7 ;
}
return V_9 ;
}
static void F_5 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_6 ( V_5 ) ;
struct V_1 * V_10 = V_2 -> V_11 -> V_12 ;
T_3 V_13 = 0 ;
F_3 ( & F_7 ( V_5 ) , L_4 ,
V_5 -> V_14 ) ;
if ( ! F_8 ( V_2 ) )
F_3 ( & F_7 ( V_5 ) ,
L_5 ) ;
F_9 ( V_10 , V_15 , & V_13 ) ;
V_13 |= V_16 ;
F_10 ( V_10 , V_15 , V_13 ) ;
F_11 ( 100 ) ;
V_13 &= ~ V_16 ;
F_10 ( V_10 , V_15 , V_13 ) ;
F_11 ( 100 ) ;
F_12 ( V_2 ) ;
F_13 ( V_2 ) ;
}
static void F_14 ( struct V_17 * V_18 )
{
struct V_19 * V_20 =
F_15 ( V_18 , struct V_19 , V_21 ) ;
struct V_4 * V_5 = V_20 -> V_5 ;
F_16 ( V_5 ) ;
F_17 ( V_5 ) ;
F_18 ( V_5 ) ;
F_5 ( V_5 ) ;
if ( F_19 ( V_5 ) || F_20 ( V_5 ) ) {
F_4 ( & F_7 ( V_5 ) , L_6 ) ;
F_21 ( V_20 ) ;
F_22 ( 1 , L_7 ) ;
return;
}
F_23 ( V_5 ) ;
F_24 ( V_22 , & V_5 -> V_23 ) ;
if ( V_20 -> V_24 == V_25 )
F_25 ( & V_20 -> V_26 ) ;
else
F_21 ( V_20 ) ;
}
static int F_26 ( struct V_4 * V_5 ,
enum V_27 V_24 )
{
struct V_19 * V_20 ;
if ( ! F_27 ( V_5 ) ||
F_28 ( V_22 , & V_5 -> V_23 ) )
return 0 ;
F_29 ( V_22 , & V_5 -> V_23 ) ;
V_20 = F_30 ( sizeof( * V_20 ) , V_28 ) ;
if ( ! V_20 )
return - V_29 ;
V_20 -> V_5 = V_5 ;
F_31 ( & V_20 -> V_26 ) ;
V_20 -> V_24 = V_24 ;
F_32 ( & V_20 -> V_21 , F_14 ) ;
F_33 ( V_30 , & V_20 -> V_21 ) ;
if ( V_24 == V_25 ) {
int V_31 = 0 ;
unsigned long V_32 = F_34 ( 10000 ) ;
unsigned long V_33 = F_35 (
& V_20 -> V_26 , V_32 ) ;
if ( ! V_33 ) {
F_4 ( & F_7 ( V_5 ) ,
L_8 ) ;
V_31 = - V_34 ;
}
F_21 ( V_20 ) ;
return V_31 ;
}
return 0 ;
}
static T_1 F_36 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_5 ) {
F_37 ( L_9 ) ;
return V_7 ;
}
F_38 ( V_2 ) ;
if ( F_26 ( V_5 , V_25 ) )
return V_7 ;
return V_35 ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_3 ( & V_2 -> V_6 , L_10 ) ;
F_3 ( & V_2 -> V_6 , L_11 ) ;
}
int F_40 ( struct V_4 * V_5 , struct V_36 * V_37 )
{
struct V_1 * V_2 = F_6 ( V_5 ) ;
V_37 -> V_38 = & V_39 ;
F_41 ( V_2 ) ;
return 0 ;
}
void F_42 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_6 ( V_5 ) ;
F_43 ( V_2 ) ;
}
int F_44 ( void )
{
V_30 = F_45 ( L_12 ) ;
return ! V_30 ? - V_34 : 0 ;
}
void F_46 ( void )
{
if ( V_30 )
F_47 ( V_30 ) ;
V_30 = NULL ;
}
