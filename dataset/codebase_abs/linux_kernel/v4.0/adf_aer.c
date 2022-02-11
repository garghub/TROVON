static T_1 F_1 ( struct V_1 * V_2 ,
T_2 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( L_1 ) ;
if ( ! V_5 ) {
F_4 ( L_2 ) ;
return V_6 ;
}
if ( V_3 == V_7 ) {
F_4 ( L_3 ) ;
return V_6 ;
}
return V_8 ;
}
static void F_5 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_6 ( V_5 ) ;
struct V_1 * V_9 = V_2 -> V_10 -> V_11 ;
T_3 V_12 = 0 ;
F_3 ( L_4 , V_5 -> V_13 ) ;
if ( ! F_7 ( V_2 ) )
F_3 ( L_5 ) ;
F_8 ( V_9 , V_14 , & V_12 ) ;
V_12 |= V_15 ;
F_9 ( V_9 , V_14 , V_12 ) ;
F_10 ( 100 ) ;
V_12 &= ~ V_15 ;
F_9 ( V_9 , V_14 , V_12 ) ;
F_10 ( 100 ) ;
F_11 ( V_2 ) ;
F_12 ( V_2 ) ;
}
static void F_13 ( struct V_16 * V_17 )
{
struct V_18 * V_19 =
F_14 ( V_17 , struct V_18 , V_20 ) ;
struct V_4 * V_5 = V_19 -> V_5 ;
F_15 ( V_5 ) ;
F_16 ( V_5 ) ;
F_17 ( V_5 ) ;
F_5 ( V_5 ) ;
if ( F_18 ( V_5 ) || F_19 ( V_5 ) ) {
F_20 ( & F_21 ( V_5 ) , L_6 ) ;
F_22 ( V_19 ) ;
F_23 ( 1 , L_7 ) ;
return;
}
F_24 ( V_5 ) ;
F_25 ( V_21 , & V_5 -> V_22 ) ;
if ( V_19 -> V_23 == V_24 )
F_26 ( & V_19 -> V_25 ) ;
else
F_22 ( V_19 ) ;
}
static int F_27 ( struct V_4 * V_5 ,
enum V_26 V_23 )
{
struct V_18 * V_19 ;
if ( ! F_28 ( V_5 ) ||
F_29 ( V_21 , & V_5 -> V_22 ) )
return 0 ;
F_30 ( V_21 , & V_5 -> V_22 ) ;
V_19 = F_31 ( sizeof( * V_19 ) , V_27 ) ;
if ( ! V_19 )
return - V_28 ;
V_19 -> V_5 = V_5 ;
F_32 ( & V_19 -> V_25 ) ;
V_19 -> V_23 = V_23 ;
F_33 ( & V_19 -> V_20 , F_13 ) ;
F_34 ( V_29 , & V_19 -> V_20 ) ;
if ( V_23 == V_24 ) {
int V_30 = 0 ;
unsigned long V_31 = F_35 ( 10000 ) ;
unsigned long V_32 = F_36 (
& V_19 -> V_25 , V_31 ) ;
if ( ! V_32 ) {
F_4 ( L_8 ) ;
V_30 = - V_33 ;
}
F_22 ( V_19 ) ;
return V_30 ;
}
return 0 ;
}
static T_1 F_37 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_5 ) {
F_4 ( L_2 ) ;
return V_6 ;
}
F_38 ( V_2 ) ;
if ( F_27 ( V_5 , V_24 ) )
return V_6 ;
return V_34 ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_3 ( L_9 ) ;
F_3 ( L_10 ) ;
}
int F_40 ( struct V_4 * V_5 , struct V_35 * V_36 )
{
struct V_1 * V_2 = F_6 ( V_5 ) ;
V_36 -> V_37 = & V_38 ;
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
V_29 = F_45 ( L_11 ) ;
return ( V_29 == NULL ) ? - V_33 : 0 ;
}
void F_46 ( void )
{
if ( V_29 )
F_47 ( V_29 ) ;
V_29 = NULL ;
}
