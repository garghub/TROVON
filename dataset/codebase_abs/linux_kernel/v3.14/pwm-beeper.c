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
static int F_7 ( struct V_14 * V_15 )
{
unsigned long V_16 = ( unsigned long ) F_8 ( & V_15 -> V_17 ) ;
struct V_6 * V_7 ;
int error ;
V_7 = F_9 ( sizeof( * V_7 ) , V_18 ) ;
if ( ! V_7 )
return - V_19 ;
V_7 -> V_13 = F_10 ( & V_15 -> V_17 , NULL ) ;
if ( F_11 ( V_7 -> V_13 ) ) {
F_12 ( & V_15 -> V_17 , L_1 ) ;
V_7 -> V_13 = F_13 ( V_16 , L_2 ) ;
}
if ( F_11 ( V_7 -> V_13 ) ) {
error = F_14 ( V_7 -> V_13 ) ;
F_15 ( & V_15 -> V_17 , L_3 , error ) ;
goto V_20;
}
V_7 -> V_2 = F_16 () ;
if ( ! V_7 -> V_2 ) {
F_15 ( & V_15 -> V_17 , L_4 ) ;
error = - V_19 ;
goto V_21;
}
V_7 -> V_2 -> V_17 . V_22 = & V_15 -> V_17 ;
V_7 -> V_2 -> V_23 = L_5 ;
V_7 -> V_2 -> V_24 = L_6 ;
V_7 -> V_2 -> V_25 . V_26 = V_27 ;
V_7 -> V_2 -> V_25 . V_28 = 0x001f ;
V_7 -> V_2 -> V_25 . V_29 = 0x0001 ;
V_7 -> V_2 -> V_25 . V_30 = 0x0100 ;
V_7 -> V_2 -> V_31 [ 0 ] = F_17 ( V_9 ) ;
V_7 -> V_2 -> V_32 [ 0 ] = F_17 ( V_12 ) | F_17 ( V_11 ) ;
V_7 -> V_2 -> V_33 = F_1 ;
F_18 ( V_7 -> V_2 , V_7 ) ;
error = F_19 ( V_7 -> V_2 ) ;
if ( error ) {
F_15 ( & V_15 -> V_17 , L_7 , error ) ;
goto V_34;
}
F_20 ( V_15 , V_7 ) ;
return 0 ;
V_34:
F_21 ( V_7 -> V_2 ) ;
V_21:
F_22 ( V_7 -> V_13 ) ;
V_20:
F_23 ( V_7 ) ;
return error ;
}
static int F_24 ( struct V_14 * V_15 )
{
struct V_6 * V_7 = F_25 ( V_15 ) ;
F_26 ( V_7 -> V_2 ) ;
F_4 ( V_7 -> V_13 ) ;
F_22 ( V_7 -> V_13 ) ;
F_23 ( V_7 ) ;
return 0 ;
}
static int F_27 ( struct V_35 * V_17 )
{
struct V_6 * V_7 = F_28 ( V_17 ) ;
if ( V_7 -> V_8 )
F_4 ( V_7 -> V_13 ) ;
return 0 ;
}
static int F_29 ( struct V_35 * V_17 )
{
struct V_6 * V_7 = F_28 ( V_17 ) ;
if ( V_7 -> V_8 ) {
F_3 ( V_7 -> V_13 , V_7 -> V_8 / 2 , V_7 -> V_8 ) ;
F_6 ( V_7 -> V_13 ) ;
}
return 0 ;
}
