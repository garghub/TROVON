static int F_1 ( struct V_1 * V_2 ,
unsigned int type , unsigned int V_3 , int V_4 )
{
int V_5 = 0 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned long V_8 ;
if ( type != V_9 || V_4 < 0 )
return - V_10 ;
switch ( V_3 ) {
case V_11 :
V_4 = V_4 ? 1000 : 0 ;
break;
case V_12 :
break;
default:
return - V_10 ;
}
if ( V_4 == 0 ) {
F_3 ( V_7 -> V_13 , 0 , 0 ) ;
F_4 ( V_7 -> V_13 ) ;
} else {
V_8 = F_5 ( V_4 ) ;
V_5 = F_3 ( V_7 -> V_13 , V_8 / 2 , V_8 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_6 ( V_7 -> V_13 ) ;
if ( V_5 )
return V_5 ;
V_7 -> V_8 = V_8 ;
}
return 0 ;
}
static int T_1 F_7 ( struct V_14 * V_15 )
{
unsigned long V_16 = ( unsigned long ) V_15 -> V_17 . V_18 ;
struct V_6 * V_7 ;
int error ;
V_7 = F_8 ( sizeof( * V_7 ) , V_19 ) ;
if ( ! V_7 )
return - V_20 ;
V_7 -> V_13 = F_9 ( V_16 , L_1 ) ;
if ( F_10 ( V_7 -> V_13 ) ) {
error = F_11 ( V_7 -> V_13 ) ;
F_12 ( & V_15 -> V_17 , L_2 , error ) ;
goto V_21;
}
V_7 -> V_2 = F_13 () ;
if ( ! V_7 -> V_2 ) {
F_12 ( & V_15 -> V_17 , L_3 ) ;
error = - V_20 ;
goto V_22;
}
V_7 -> V_2 -> V_17 . V_23 = & V_15 -> V_17 ;
V_7 -> V_2 -> V_24 = L_4 ;
V_7 -> V_2 -> V_25 = L_5 ;
V_7 -> V_2 -> V_26 . V_27 = V_28 ;
V_7 -> V_2 -> V_26 . V_29 = 0x001f ;
V_7 -> V_2 -> V_26 . V_30 = 0x0001 ;
V_7 -> V_2 -> V_26 . V_31 = 0x0100 ;
V_7 -> V_2 -> V_32 [ 0 ] = F_14 ( V_9 ) ;
V_7 -> V_2 -> V_33 [ 0 ] = F_14 ( V_12 ) | F_14 ( V_11 ) ;
V_7 -> V_2 -> V_34 = F_1 ;
F_15 ( V_7 -> V_2 , V_7 ) ;
error = F_16 ( V_7 -> V_2 ) ;
if ( error ) {
F_12 ( & V_15 -> V_17 , L_6 , error ) ;
goto V_35;
}
F_17 ( V_15 , V_7 ) ;
return 0 ;
V_35:
F_18 ( V_7 -> V_2 ) ;
V_22:
F_19 ( V_7 -> V_13 ) ;
V_21:
F_20 ( V_7 ) ;
return error ;
}
static int T_2 F_21 ( struct V_14 * V_15 )
{
struct V_6 * V_7 = F_22 ( V_15 ) ;
F_17 ( V_15 , NULL ) ;
F_23 ( V_7 -> V_2 ) ;
F_4 ( V_7 -> V_13 ) ;
F_19 ( V_7 -> V_13 ) ;
F_20 ( V_7 ) ;
return 0 ;
}
static int F_24 ( struct V_36 * V_17 )
{
struct V_6 * V_7 = F_25 ( V_17 ) ;
if ( V_7 -> V_8 )
F_4 ( V_7 -> V_13 ) ;
return 0 ;
}
static int F_26 ( struct V_36 * V_17 )
{
struct V_6 * V_7 = F_25 ( V_17 ) ;
if ( V_7 -> V_8 ) {
F_3 ( V_7 -> V_13 , V_7 -> V_8 / 2 , V_7 -> V_8 ) ;
F_6 ( V_7 -> V_13 ) ;
}
return 0 ;
}
static int T_3 F_27 ( void )
{
return F_28 ( & V_37 ) ;
}
static void T_4 F_29 ( void )
{
F_30 ( & V_37 ) ;
}
