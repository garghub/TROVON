static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
int V_9 , V_10 ;
for ( V_9 = 0 ; V_9 < F_3 ( V_3 -> V_11 ) ; V_9 ++ )
V_3 -> V_11 [ V_9 ] . V_12 = V_9 ;
V_10 = F_4 ( V_8 , V_3 -> V_11 , 1 , V_9 ) ;
if ( V_10 < 0 )
return V_10 ;
V_3 -> V_13 = V_10 ;
V_2 -> V_14 = true ;
V_2 -> V_15 = V_3 -> V_11 [ 0 ] . V_16 ;
V_2 -> V_17 = ( V_3 -> V_13 > 1 ) ? V_3 -> V_11 [ 1 ] . V_16
: V_3 -> V_11 [ 0 ] . V_16 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
int V_10 ;
V_10 = F_6 ( V_8 ) ;
if ( V_10 )
return V_10 ;
V_2 -> V_17 = V_8 -> V_18 ;
V_2 -> V_15 = V_8 -> V_18 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_10 ;
V_10 = F_1 ( V_2 ) ;
if ( ! V_10 )
return 0 ;
F_8 ( V_6 , L_1 , V_10 ) ;
V_10 = F_5 ( V_2 ) ;
if ( ! V_10 )
return 0 ;
F_8 ( V_6 , L_2 , V_10 ) ;
return V_10 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
if ( V_3 -> V_13 )
F_10 ( V_8 ) ;
else if ( V_2 -> V_15 )
F_11 ( V_8 ) ;
V_2 -> V_17 = 0 ;
V_2 -> V_15 = 0 ;
}
static int F_12 ( struct V_7 * V_8 , const struct V_19 * V_20 )
{
struct V_1 * V_2 ;
struct V_3 * V_3 ;
struct V_5 * V_6 = & V_8 -> V_6 ;
void T_1 * const * V_21 ;
int V_22 ;
int V_10 ;
V_10 = - V_23 ;
V_2 = F_13 ( V_6 ) ;
if ( ! V_2 )
goto V_24;
V_3 = F_14 ( V_6 , sizeof( * V_3 ) , V_25 ) ;
if ( ! V_3 )
goto V_24;
V_2 -> V_4 = V_3 ;
V_2 -> V_26 = (struct V_27 * ) V_20 -> V_28 ;
if ( ! V_2 -> V_26 ) {
V_10 = - V_29 ;
F_15 ( V_6 , L_3 ) ;
goto V_24;
}
V_10 = F_16 ( V_8 ) ;
if ( V_10 ) {
F_15 ( V_6 , L_4 , V_10 ) ;
goto V_24;
}
V_22 = F_17 ( V_8 , V_30 ) ;
V_10 = F_18 ( V_8 , V_22 , L_5 ) ;
if ( V_10 ) {
F_15 ( V_6 , L_6 , V_10 ) ;
goto V_24;
}
V_21 = F_19 ( V_8 ) ;
if ( ! V_21 ) {
F_15 ( V_6 , L_7 ) ;
V_10 = - V_23 ;
goto V_24;
}
V_2 -> V_31 = V_21 [ V_2 -> V_26 -> V_32 ] ;
if ( ! V_2 -> V_31 ) {
F_15 ( V_6 , L_8 ) ;
V_10 = - V_23 ;
goto V_24;
}
V_10 = F_7 ( V_2 ) ;
if ( V_10 )
goto V_24;
F_20 ( V_8 ) ;
V_10 = F_21 ( V_6 , F_22 ( 48 ) ) ;
if ( V_10 ) {
V_10 = F_21 ( V_6 , F_22 ( 32 ) ) ;
if ( V_10 ) {
F_15 ( V_6 , L_9 ,
V_10 ) ;
goto V_24;
}
}
F_23 ( V_6 , V_2 ) ;
V_10 = F_24 ( V_2 ) ;
if ( V_10 )
goto V_24;
F_8 ( V_6 , L_10 ) ;
return 0 ;
V_24:
F_8 ( V_6 , L_11 ) ;
return V_10 ;
}
static void F_25 ( struct V_7 * V_8 )
{
struct V_5 * V_6 = & V_8 -> V_6 ;
struct V_1 * V_2 = F_26 ( V_6 ) ;
if ( ! V_2 )
return;
F_27 ( V_2 ) ;
F_9 ( V_2 ) ;
F_8 ( V_6 , L_12 ) ;
}
static int F_28 ( struct V_7 * V_8 , T_2 V_33 )
{
struct V_5 * V_6 = & V_8 -> V_6 ;
struct V_1 * V_2 = F_26 ( V_6 ) ;
return F_29 ( V_2 , V_33 ) ;
}
static int F_30 ( struct V_7 * V_8 )
{
struct V_5 * V_6 = & V_8 -> V_6 ;
struct V_1 * V_2 = F_26 ( V_6 ) ;
return F_31 ( V_2 ) ;
}
int F_32 ( void )
{
return F_33 ( & V_34 ) ;
}
void F_34 ( void )
{
F_35 ( & V_34 ) ;
}
