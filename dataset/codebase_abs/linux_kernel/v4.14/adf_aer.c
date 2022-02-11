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
if ( ! V_10 )
V_10 = V_2 ;
if ( ! F_7 ( V_2 ) )
F_3 ( & F_8 ( V_5 ) ,
L_4 ) ;
F_3 ( & F_8 ( V_5 ) , L_5 ) ;
F_9 ( V_10 , V_14 , & V_13 ) ;
V_13 |= V_15 ;
F_10 ( V_10 , V_14 , V_13 ) ;
F_11 ( 100 ) ;
V_13 &= ~ V_15 ;
F_10 ( V_10 , V_14 , V_13 ) ;
F_11 ( 100 ) ;
}
void F_12 ( struct V_4 * V_5 )
{
F_13 ( F_6 ( V_5 ) ) ;
}
void F_14 ( struct V_4 * V_5 )
{
struct V_16 * V_17 = V_5 -> V_17 ;
struct V_1 * V_2 = F_6 ( V_5 ) ;
if ( V_17 -> V_18 ) {
F_3 ( & F_8 ( V_5 ) , L_6 ,
V_5 -> V_19 ) ;
V_17 -> V_18 ( V_5 ) ;
F_15 ( V_2 ) ;
F_16 ( V_2 ) ;
}
}
static void F_17 ( struct V_20 * V_21 )
{
struct V_22 * V_23 =
F_18 ( V_21 , struct V_22 , V_24 ) ;
struct V_4 * V_5 = V_23 -> V_5 ;
F_19 ( V_5 ) ;
F_20 ( V_5 ) ;
F_21 ( V_5 ) ;
if ( F_22 ( V_5 ) || F_23 ( V_5 ) ) {
F_4 ( & F_8 ( V_5 ) , L_7 ) ;
F_24 ( V_23 ) ;
F_25 ( 1 , L_8 ) ;
return;
}
F_26 ( V_5 ) ;
F_27 ( V_25 , & V_5 -> V_26 ) ;
if ( V_23 -> V_27 == V_28 )
F_28 ( & V_23 -> V_29 ) ;
else
F_24 ( V_23 ) ;
}
static int F_29 ( struct V_4 * V_5 ,
enum V_30 V_27 )
{
struct V_22 * V_23 ;
if ( ! F_30 ( V_5 ) ||
F_31 ( V_25 , & V_5 -> V_26 ) )
return 0 ;
F_32 ( V_25 , & V_5 -> V_26 ) ;
V_23 = F_33 ( sizeof( * V_23 ) , V_31 ) ;
if ( ! V_23 )
return - V_32 ;
V_23 -> V_5 = V_5 ;
F_34 ( & V_23 -> V_29 ) ;
V_23 -> V_27 = V_27 ;
F_35 ( & V_23 -> V_24 , F_17 ) ;
F_36 ( V_33 , & V_23 -> V_24 ) ;
if ( V_27 == V_28 ) {
int V_34 = 0 ;
unsigned long V_35 = F_37 ( 10000 ) ;
unsigned long V_36 = F_38 (
& V_23 -> V_29 , V_35 ) ;
if ( ! V_36 ) {
F_4 ( & F_8 ( V_5 ) ,
L_9 ) ;
V_34 = - V_37 ;
}
F_24 ( V_23 ) ;
return V_34 ;
}
return 0 ;
}
static T_1 F_39 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_5 ) {
F_40 ( L_10 ) ;
return V_7 ;
}
F_41 ( V_2 ) ;
if ( F_29 ( V_5 , V_28 ) )
return V_7 ;
return V_38 ;
}
static void F_42 ( struct V_1 * V_2 )
{
F_3 ( & V_2 -> V_6 , L_11 ) ;
F_3 ( & V_2 -> V_6 , L_12 ) ;
}
int F_43 ( struct V_4 * V_5 , struct V_39 * V_40 )
{
struct V_1 * V_2 = F_6 ( V_5 ) ;
V_40 -> V_41 = & V_42 ;
F_44 ( V_2 ) ;
return 0 ;
}
void F_45 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_6 ( V_5 ) ;
F_46 ( V_2 ) ;
}
int F_47 ( void )
{
V_33 = F_48 ( L_13 ,
V_43 , 0 ) ;
return ! V_33 ? - V_37 : 0 ;
}
void F_49 ( void )
{
if ( V_33 )
F_50 ( V_33 ) ;
V_33 = NULL ;
}
