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
T_3 V_12 = 0 , V_13 = 0 ;
int V_14 = 0 ;
F_3 ( L_4 , V_5 -> V_15 ) ;
F_7 ( V_2 , V_16 , & V_12 ) ;
V_14 = V_12 & V_17 ;
if ( V_14 ) {
int V_18 = 0 ;
do {
F_8 ( 100 ) ;
F_7 ( V_2 , V_16 , & V_12 ) ;
V_14 = V_12 & V_17 ;
} while ( V_14 && V_18 ++ < 10 );
}
if ( V_14 )
F_3 ( L_5 ) ;
F_7 ( V_9 , V_19 , & V_13 ) ;
V_13 |= V_20 ;
F_9 ( V_9 , V_19 , V_13 ) ;
F_8 ( 100 ) ;
V_13 &= ~ V_20 ;
F_9 ( V_9 , V_19 , V_13 ) ;
F_8 ( 100 ) ;
F_10 ( V_2 ) ;
F_11 ( V_2 ) ;
}
static void F_12 ( struct V_21 * V_22 )
{
struct V_23 * V_24 =
F_13 ( V_22 , struct V_23 , V_25 ) ;
struct V_4 * V_5 = V_24 -> V_5 ;
F_14 ( V_5 ) ;
F_15 ( V_5 ) ;
F_5 ( V_5 ) ;
if ( F_16 ( V_5 ) ) {
F_17 ( & F_18 ( V_5 ) , L_6 ) ;
F_19 ( V_24 ) ;
F_20 ( 1 , L_7 ) ;
return;
}
F_21 ( V_5 ) ;
F_22 ( V_26 , & V_5 -> V_27 ) ;
if ( V_24 -> V_28 == V_29 )
F_23 ( & V_24 -> V_30 ) ;
else
F_19 ( V_24 ) ;
}
static int F_24 ( struct V_4 * V_5 ,
enum V_31 V_28 )
{
struct V_23 * V_24 ;
if ( F_25 ( V_5 ) &&
! F_26 ( V_26 , & V_5 -> V_27 ) )
return 0 ;
F_27 ( V_26 , & V_5 -> V_27 ) ;
V_24 = F_28 ( sizeof( * V_24 ) , V_32 ) ;
if ( ! V_24 )
return - V_33 ;
V_24 -> V_5 = V_5 ;
F_29 ( & V_24 -> V_30 ) ;
V_24 -> V_28 = V_28 ;
F_30 ( & V_24 -> V_25 , F_12 ) ;
F_31 ( V_34 , & V_24 -> V_25 ) ;
if ( V_28 == V_29 ) {
int V_35 = 0 ;
unsigned long V_36 = F_32 ( 10000 ) ;
unsigned long V_37 = F_33 (
& V_24 -> V_30 , V_36 ) ;
if ( ! V_37 ) {
F_4 ( L_8 ) ;
V_35 = - V_38 ;
}
F_19 ( V_24 ) ;
return V_35 ;
}
return 0 ;
}
static T_1 F_34 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_5 ) {
F_4 ( L_2 ) ;
return V_6 ;
}
F_35 ( V_2 ) ;
if ( F_24 ( V_5 , V_29 ) )
return V_6 ;
return V_39 ;
}
static void F_36 ( struct V_1 * V_2 )
{
F_3 ( L_9 ) ;
F_3 ( L_10 ) ;
}
int F_37 ( struct V_4 * V_5 , struct V_40 * V_41 )
{
struct V_1 * V_2 = F_6 ( V_5 ) ;
V_41 -> V_42 = & V_43 ;
F_38 ( V_2 ) ;
return 0 ;
}
void F_39 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_6 ( V_5 ) ;
F_40 ( V_2 ) ;
}
int F_41 ( void )
{
V_34 = F_42 ( L_11 ) ;
return ( V_34 == NULL ) ? - V_38 : 0 ;
}
void F_43 ( void )
{
if ( V_34 )
F_44 ( V_34 ) ;
V_34 = NULL ;
}
