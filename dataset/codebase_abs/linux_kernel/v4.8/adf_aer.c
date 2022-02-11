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
struct V_1 * V_2 = F_6 ( V_5 ) ;
T_4 V_16 = 0 ;
int V_17 = 0 ;
F_3 ( & F_8 ( V_5 ) , L_6 ) ;
V_17 = F_13 ( V_2 ) ;
if ( ! V_17 ) {
F_4 ( & F_8 ( V_5 ) , L_7 ) ;
return;
}
F_9 ( V_2 , V_17 + V_18 , & V_16 ) ;
V_16 |= V_19 ;
F_10 ( V_2 , V_17 + V_18 , V_16 ) ;
F_11 ( 100 ) ;
}
void F_14 ( struct V_4 * V_5 )
{
struct V_20 * V_21 = V_5 -> V_21 ;
struct V_1 * V_2 = F_6 ( V_5 ) ;
if ( V_21 -> V_22 ) {
F_3 ( & F_8 ( V_5 ) , L_8 ,
V_5 -> V_23 ) ;
V_21 -> V_22 ( V_5 ) ;
F_15 ( V_2 ) ;
F_16 ( V_2 ) ;
}
}
static void F_17 ( struct V_24 * V_25 )
{
struct V_26 * V_27 =
F_18 ( V_25 , struct V_26 , V_28 ) ;
struct V_4 * V_5 = V_27 -> V_5 ;
F_19 ( V_5 ) ;
F_20 ( V_5 ) ;
F_21 ( V_5 ) ;
if ( F_22 ( V_5 ) || F_23 ( V_5 ) ) {
F_4 ( & F_8 ( V_5 ) , L_7 ) ;
F_24 ( V_27 ) ;
F_25 ( 1 , L_9 ) ;
return;
}
F_26 ( V_5 ) ;
F_27 ( V_29 , & V_5 -> V_30 ) ;
if ( V_27 -> V_31 == V_32 )
F_28 ( & V_27 -> V_33 ) ;
else
F_24 ( V_27 ) ;
}
static int F_29 ( struct V_4 * V_5 ,
enum V_34 V_31 )
{
struct V_26 * V_27 ;
if ( ! F_30 ( V_5 ) ||
F_31 ( V_29 , & V_5 -> V_30 ) )
return 0 ;
F_32 ( V_29 , & V_5 -> V_30 ) ;
V_27 = F_33 ( sizeof( * V_27 ) , V_35 ) ;
if ( ! V_27 )
return - V_36 ;
V_27 -> V_5 = V_5 ;
F_34 ( & V_27 -> V_33 ) ;
V_27 -> V_31 = V_31 ;
F_35 ( & V_27 -> V_28 , F_17 ) ;
F_36 ( V_37 , & V_27 -> V_28 ) ;
if ( V_31 == V_32 ) {
int V_38 = 0 ;
unsigned long V_39 = F_37 ( 10000 ) ;
unsigned long V_40 = F_38 (
& V_27 -> V_33 , V_39 ) ;
if ( ! V_40 ) {
F_4 ( & F_8 ( V_5 ) ,
L_10 ) ;
V_38 = - V_41 ;
}
F_24 ( V_27 ) ;
return V_38 ;
}
return 0 ;
}
static T_1 F_39 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_5 ) {
F_40 ( L_11 ) ;
return V_7 ;
}
F_41 ( V_2 ) ;
if ( F_29 ( V_5 , V_32 ) )
return V_7 ;
return V_42 ;
}
static void F_42 ( struct V_1 * V_2 )
{
F_3 ( & V_2 -> V_6 , L_12 ) ;
F_3 ( & V_2 -> V_6 , L_13 ) ;
}
int F_43 ( struct V_4 * V_5 , struct V_43 * V_44 )
{
struct V_1 * V_2 = F_6 ( V_5 ) ;
V_44 -> V_45 = & V_46 ;
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
V_37 = F_48 ( L_14 ,
V_47 , 0 ) ;
return ! V_37 ? - V_41 : 0 ;
}
void F_49 ( void )
{
if ( V_37 )
F_50 ( V_37 ) ;
V_37 = NULL ;
}
