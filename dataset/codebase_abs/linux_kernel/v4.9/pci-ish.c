static void F_1 ( struct V_1 * V_2 , char * V_3 , ... )
{
if ( F_2 () ) {
T_1 args ;
char V_4 [ 100 ] ;
va_start ( args , V_3 ) ;
vsnprintf ( V_4 , sizeof( V_4 ) , V_3 , args ) ;
va_end ( args ) ;
F_3 ( V_4 ) ;
}
}
static int F_4 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_5 ( V_2 ) ;
if ( V_5 ) {
F_6 ( V_2 -> V_6 , L_1 ) ;
return V_5 ;
}
V_5 = F_7 ( V_2 ) ;
if ( V_5 ) {
F_6 ( V_2 -> V_6 , L_2 ) ;
return V_5 ;
}
return 0 ;
}
static int F_8 ( struct V_7 * V_8 , const struct V_9 * V_10 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
int V_5 ;
V_5 = F_9 ( V_8 ) ;
if ( V_5 ) {
F_6 ( & V_8 -> V_2 , L_3 ) ;
return V_5 ;
}
F_10 ( V_8 ) ;
V_5 = F_11 ( V_8 , V_13 ) ;
if ( V_5 ) {
F_6 ( & V_8 -> V_2 , L_4 ) ;
goto V_14;
}
V_2 = F_12 ( V_8 ) ;
if ( ! V_2 ) {
V_5 = - V_15 ;
goto V_16;
}
V_12 = F_13 ( V_2 ) ;
V_2 -> V_17 = F_1 ;
V_12 -> V_18 = F_14 ( V_8 , 0 , 0 ) ;
if ( ! V_12 -> V_18 ) {
F_6 ( & V_8 -> V_2 , L_5 ) ;
V_5 = - V_15 ;
goto V_19;
}
V_2 -> V_8 = V_8 ;
V_8 -> V_20 |= V_21 ;
V_5 = F_15 ( V_8 -> V_22 , V_23 , V_24 ,
V_13 , V_2 ) ;
if ( V_5 ) {
F_6 ( & V_8 -> V_2 , L_6 ,
V_8 -> V_22 ) ;
goto V_19;
}
F_16 ( V_2 -> V_6 , V_2 ) ;
F_17 ( & V_2 -> V_25 ) ;
F_17 ( & V_2 -> V_26 ) ;
V_5 = F_4 ( V_2 ) ;
if ( V_5 )
goto V_27;
return 0 ;
V_27:
V_27 ( V_8 -> V_22 , V_2 ) ;
V_19:
F_18 ( V_8 , V_12 -> V_18 ) ;
F_19 ( V_2 ) ;
V_16:
F_20 ( V_8 ) ;
V_14:
F_21 ( V_8 ) ;
F_22 ( V_8 ) ;
F_6 ( & V_8 -> V_2 , L_7 ) ;
return V_5 ;
}
static void F_23 ( struct V_7 * V_8 )
{
struct V_1 * V_28 = F_24 ( V_8 ) ;
struct V_11 * V_12 = F_13 ( V_28 ) ;
F_25 ( V_28 , false ) ;
F_26 ( V_28 ) ;
V_27 ( V_8 -> V_22 , V_28 ) ;
F_18 ( V_8 , V_12 -> V_18 ) ;
F_20 ( V_8 ) ;
F_21 ( V_8 ) ;
F_22 ( V_8 ) ;
F_19 ( V_28 ) ;
}
static void F_27 ( struct V_29 * V_30 )
{
struct V_7 * V_8 = F_28 ( V_31 ) ;
struct V_1 * V_2 = F_24 ( V_8 ) ;
int V_5 ;
F_29 ( V_2 ) ;
if ( V_2 -> V_32 )
V_5 = F_30 ( V_2 -> V_26 ,
! V_2 -> V_32 ,
F_31 ( 50 ) ) ;
if ( V_2 -> V_32 )
F_4 ( V_2 ) ;
}
static int F_32 ( struct V_33 * V_33 )
{
struct V_7 * V_8 = F_28 ( V_33 ) ;
struct V_1 * V_2 = F_24 ( V_8 ) ;
F_33 ( V_8 -> V_22 ) ;
if ( V_2 -> V_34 )
return 0 ;
V_2 -> V_32 = 0 ;
V_2 -> V_34 = 1 ;
F_34 ( V_2 ) ;
if ( V_2 -> V_34 )
F_30 ( V_2 -> V_25 ,
! V_2 -> V_34 ,
F_31 ( 25 ) ) ;
return 0 ;
}
static int F_35 ( struct V_33 * V_33 )
{
struct V_7 * V_8 = F_28 ( V_33 ) ;
struct V_1 * V_2 = F_24 ( V_8 ) ;
V_31 = V_33 ;
V_2 -> V_32 = 1 ;
F_36 ( V_8 -> V_22 ) ;
F_37 ( & V_35 ) ;
return 0 ;
}
