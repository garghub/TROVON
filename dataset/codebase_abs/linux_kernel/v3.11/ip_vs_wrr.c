static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
int V_6 = 0 ;
F_2 (dest, &svc->destinations, n_list) {
V_5 = F_3 ( & V_4 -> V_5 ) ;
if ( V_5 > 0 ) {
if ( V_6 > 0 )
V_6 = F_4 ( V_5 , V_6 ) ;
else
V_6 = V_5 ;
}
}
return V_6 ? V_6 : 1 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_7 , V_5 = 0 ;
F_2 (dest, &svc->destinations, n_list) {
V_7 = F_3 ( & V_4 -> V_5 ) ;
if ( V_7 > V_5 )
V_5 = V_7 ;
}
return V_5 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
V_9 = F_7 ( sizeof( struct V_8 ) , V_10 ) ;
if ( V_9 == NULL )
return - V_11 ;
V_9 -> V_12 = F_8 ( & V_2 -> V_13 , struct V_3 , V_14 ) ;
V_9 -> V_15 = F_1 ( V_2 ) ;
V_9 -> V_16 = F_5 ( V_2 ) - ( V_9 -> V_15 - 1 ) ;
V_9 -> V_17 = V_9 -> V_16 ;
V_2 -> V_18 = V_9 ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_18 ;
F_10 ( V_9 , V_19 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_8 * V_9 = V_2 -> V_18 ;
F_12 ( & V_2 -> V_20 ) ;
V_9 -> V_12 = F_8 ( & V_2 -> V_13 , struct V_3 , V_14 ) ;
V_9 -> V_15 = F_1 ( V_2 ) ;
V_9 -> V_16 = F_5 ( V_2 ) - ( V_9 -> V_15 - 1 ) ;
if ( V_9 -> V_17 > V_9 -> V_16 || ! V_9 -> V_17 )
V_9 -> V_17 = V_9 -> V_16 ;
else if ( V_9 -> V_15 > 1 )
V_9 -> V_17 = ( V_9 -> V_17 / V_9 -> V_15 ) * V_9 -> V_15 + 1 ;
F_13 ( & V_2 -> V_20 ) ;
return 0 ;
}
static struct V_3 *
F_14 ( struct V_1 * V_2 , const struct V_21 * V_22 ,
struct V_23 * V_24 )
{
struct V_3 * V_4 , * V_25 , * V_26 = NULL ;
struct V_8 * V_9 = V_2 -> V_18 ;
bool V_27 = false , V_28 = false ;
F_15 ( 6 , L_1 , V_29 ) ;
F_12 ( & V_2 -> V_20 ) ;
V_4 = V_9 -> V_12 ;
if ( V_9 -> V_16 == 0 )
goto V_30;
V_25 = V_4 ;
while ( 1 ) {
F_16 (dest,
&svc->destinations,
n_list) {
if ( ! ( V_4 -> V_31 & V_32 ) &&
F_3 ( & V_4 -> V_5 ) >= V_9 -> V_17 )
goto V_33;
if ( V_4 == V_26 )
goto V_34;
}
V_9 -> V_17 -= V_9 -> V_15 ;
if ( V_9 -> V_17 <= 0 ) {
V_9 -> V_17 = V_9 -> V_16 ;
if ( V_27 ||
& V_25 -> V_14 == & V_2 -> V_13 )
goto V_34;
V_28 = true ;
}
V_27 = V_9 -> V_17 <= V_9 -> V_15 ;
if ( V_27 && V_28 &&
& V_25 -> V_14 != & V_2 -> V_13 ) {
V_26 = V_25 ;
}
}
V_33:
F_17 ( 6 , L_2
L_3 ,
F_18 ( V_2 -> V_35 , & V_4 -> V_36 ) , F_19 ( V_4 -> V_37 ) ,
F_3 ( & V_4 -> V_38 ) ,
F_3 ( & V_4 -> V_39 ) ,
F_3 ( & V_4 -> V_5 ) ) ;
V_9 -> V_12 = V_4 ;
V_40:
F_13 ( & V_2 -> V_20 ) ;
return V_4 ;
V_30:
V_9 -> V_12 = V_4 ;
V_4 = NULL ;
F_20 ( V_2 , L_4 ) ;
goto V_40;
V_34:
V_9 -> V_12 = V_4 ;
V_4 = NULL ;
F_20 ( V_2 , L_5
L_6 ) ;
goto V_40;
}
static int T_1 F_21 ( void )
{
return F_22 ( & V_41 ) ;
}
static void T_2 F_23 ( void )
{
F_24 ( & V_41 ) ;
F_25 () ;
}
