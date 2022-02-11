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
void F_5 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_6 ( V_5 ) ;
struct V_1 * V_10 = V_2 -> V_11 -> V_12 ;
T_3 V_13 = 0 ;
if ( V_5 -> V_14 )
return;
F_3 ( & F_7 ( V_5 ) , L_4 ,
V_5 -> V_15 ) ;
if ( ! V_10 )
V_10 = V_2 ;
if ( ! F_8 ( V_2 ) )
F_3 ( & F_7 ( V_5 ) ,
L_5 ) ;
F_9 ( V_10 , V_16 , & V_13 ) ;
V_13 |= V_17 ;
F_10 ( V_10 , V_16 , V_13 ) ;
F_11 ( 100 ) ;
V_13 &= ~ V_17 ;
F_10 ( V_10 , V_16 , V_13 ) ;
F_11 ( 100 ) ;
F_12 ( V_2 ) ;
F_13 ( V_2 ) ;
}
static void F_14 ( struct V_18 * V_19 )
{
struct V_20 * V_21 =
F_15 ( V_19 , struct V_20 , V_22 ) ;
struct V_4 * V_5 = V_21 -> V_5 ;
F_16 ( V_5 ) ;
F_17 ( V_5 ) ;
F_18 ( V_5 ) ;
F_5 ( V_5 ) ;
if ( F_19 ( V_5 ) || F_20 ( V_5 ) ) {
F_4 ( & F_7 ( V_5 ) , L_6 ) ;
F_21 ( V_21 ) ;
F_22 ( 1 , L_7 ) ;
return;
}
F_23 ( V_5 ) ;
F_24 ( V_23 , & V_5 -> V_24 ) ;
if ( V_21 -> V_25 == V_26 )
F_25 ( & V_21 -> V_27 ) ;
else
F_21 ( V_21 ) ;
}
static int F_26 ( struct V_4 * V_5 ,
enum V_28 V_25 )
{
struct V_20 * V_21 ;
if ( ! F_27 ( V_5 ) ||
F_28 ( V_23 , & V_5 -> V_24 ) )
return 0 ;
F_29 ( V_23 , & V_5 -> V_24 ) ;
V_21 = F_30 ( sizeof( * V_21 ) , V_29 ) ;
if ( ! V_21 )
return - V_30 ;
V_21 -> V_5 = V_5 ;
F_31 ( & V_21 -> V_27 ) ;
V_21 -> V_25 = V_25 ;
F_32 ( & V_21 -> V_22 , F_14 ) ;
F_33 ( V_31 , & V_21 -> V_22 ) ;
if ( V_25 == V_26 ) {
int V_32 = 0 ;
unsigned long V_33 = F_34 ( 10000 ) ;
unsigned long V_34 = F_35 (
& V_21 -> V_27 , V_33 ) ;
if ( ! V_34 ) {
F_4 ( & F_7 ( V_5 ) ,
L_8 ) ;
V_32 = - V_35 ;
}
F_21 ( V_21 ) ;
return V_32 ;
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
if ( F_26 ( V_5 , V_26 ) )
return V_7 ;
return V_36 ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_3 ( & V_2 -> V_6 , L_10 ) ;
F_3 ( & V_2 -> V_6 , L_11 ) ;
}
int F_40 ( struct V_4 * V_5 , struct V_37 * V_38 )
{
struct V_1 * V_2 = F_6 ( V_5 ) ;
V_38 -> V_39 = & V_40 ;
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
V_31 = F_45 ( L_12 ) ;
return ! V_31 ? - V_35 : 0 ;
}
void F_46 ( void )
{
if ( V_31 )
F_47 ( V_31 ) ;
V_31 = NULL ;
}
