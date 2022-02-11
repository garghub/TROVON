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
V_9 -> V_12 = & V_2 -> V_13 ;
V_9 -> V_14 = 0 ;
V_9 -> V_15 = F_5 ( V_2 ) ;
V_9 -> V_16 = F_1 ( V_2 ) ;
V_2 -> V_17 = V_9 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_17 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_17 ;
V_9 -> V_12 = & V_2 -> V_13 ;
V_9 -> V_15 = F_5 ( V_2 ) ;
V_9 -> V_16 = F_1 ( V_2 ) ;
if ( V_9 -> V_14 > V_9 -> V_15 )
V_9 -> V_14 = 0 ;
return 0 ;
}
static struct V_3 *
F_11 ( struct V_1 * V_2 , const struct V_18 * V_19 )
{
struct V_3 * V_4 ;
struct V_8 * V_9 = V_2 -> V_17 ;
struct V_20 * V_21 ;
F_12 ( 6 , L_1 , V_22 ) ;
F_13 ( & V_2 -> V_23 ) ;
V_21 = V_9 -> V_12 ;
while ( 1 ) {
if ( V_9 -> V_12 == & V_2 -> V_13 ) {
if ( V_9 -> V_12 == V_9 -> V_12 -> V_24 ) {
F_14 ( V_2 ,
L_2
L_3 ) ;
V_4 = NULL ;
goto V_25;
}
V_9 -> V_12 = V_2 -> V_13 . V_24 ;
V_9 -> V_14 -= V_9 -> V_16 ;
if ( V_9 -> V_14 <= 0 ) {
V_9 -> V_14 = V_9 -> V_15 ;
if ( V_9 -> V_14 == 0 ) {
V_9 -> V_12 = & V_2 -> V_13 ;
F_14 ( V_2 ,
L_4 ) ;
V_4 = NULL ;
goto V_25;
}
}
} else
V_9 -> V_12 = V_9 -> V_12 -> V_24 ;
if ( V_9 -> V_12 != & V_2 -> V_13 ) {
V_4 = F_15 ( V_9 -> V_12 , struct V_3 , V_26 ) ;
if ( ! ( V_4 -> V_27 & V_28 ) &&
F_3 ( & V_4 -> V_5 ) >= V_9 -> V_14 ) {
break;
}
}
if ( V_9 -> V_12 == V_21 && V_9 -> V_14 == V_9 -> V_16 ) {
V_4 = NULL ;
F_14 ( V_2 ,
L_2
L_5 ) ;
goto V_25;
}
}
F_16 ( 6 , L_6
L_7 ,
F_17 ( V_2 -> V_29 , & V_4 -> V_30 ) , F_18 ( V_4 -> V_31 ) ,
F_3 ( & V_4 -> V_32 ) ,
F_3 ( & V_4 -> V_33 ) ,
F_3 ( & V_4 -> V_5 ) ) ;
V_25:
F_19 ( & V_2 -> V_23 ) ;
return V_4 ;
}
static int T_1 F_20 ( void )
{
return F_21 ( & V_34 ) ;
}
static void T_2 F_22 ( void )
{
F_23 ( & V_34 ) ;
}
