static void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 = V_2 -> V_3 ;
if ( V_3 ) {
F_2 ( V_2 -> V_4 , V_3 / 2 , V_3 ) ;
F_3 ( V_2 -> V_4 ) ;
} else
F_4 ( V_2 -> V_4 ) ;
}
static void F_5 ( struct V_5 * V_6 )
{
struct V_1 * V_2 =
F_6 ( V_6 , struct V_1 , V_6 ) ;
F_1 ( V_2 ) ;
}
static int F_7 ( struct V_7 * V_8 ,
unsigned int type , unsigned int V_9 , int V_10 )
{
struct V_1 * V_2 = F_8 ( V_8 ) ;
if ( type != V_11 || V_10 < 0 )
return - V_12 ;
switch ( V_9 ) {
case V_13 :
V_10 = V_10 ? 1000 : 0 ;
break;
case V_14 :
break;
default:
return - V_12 ;
}
if ( V_10 == 0 )
V_2 -> V_3 = 0 ;
else
V_2 -> V_3 = F_9 ( V_10 ) ;
F_10 ( & V_2 -> V_6 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_12 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_3 )
F_4 ( V_2 -> V_4 ) ;
}
static void F_13 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_8 ( V_8 ) ;
F_11 ( V_2 ) ;
}
static int F_14 ( struct V_15 * V_16 )
{
unsigned long V_17 = ( unsigned long ) F_15 ( & V_16 -> V_18 ) ;
struct V_1 * V_2 ;
int error ;
V_2 = F_16 ( sizeof( * V_2 ) , V_19 ) ;
if ( ! V_2 )
return - V_20 ;
V_2 -> V_4 = F_17 ( & V_16 -> V_18 , NULL ) ;
if ( F_18 ( V_2 -> V_4 ) ) {
F_19 ( & V_16 -> V_18 , L_1 ) ;
V_2 -> V_4 = F_20 ( V_17 , L_2 ) ;
}
if ( F_18 ( V_2 -> V_4 ) ) {
error = F_21 ( V_2 -> V_4 ) ;
F_22 ( & V_16 -> V_18 , L_3 , error ) ;
goto V_21;
}
F_23 ( V_2 -> V_4 ) ;
F_24 ( & V_2 -> V_6 , F_5 ) ;
V_2 -> V_8 = F_25 () ;
if ( ! V_2 -> V_8 ) {
F_22 ( & V_16 -> V_18 , L_4 ) ;
error = - V_20 ;
goto V_22;
}
V_2 -> V_8 -> V_18 . V_23 = & V_16 -> V_18 ;
V_2 -> V_8 -> V_24 = L_5 ;
V_2 -> V_8 -> V_25 = L_6 ;
V_2 -> V_8 -> V_26 . V_27 = V_28 ;
V_2 -> V_8 -> V_26 . V_29 = 0x001f ;
V_2 -> V_8 -> V_26 . V_30 = 0x0001 ;
V_2 -> V_8 -> V_26 . V_31 = 0x0100 ;
V_2 -> V_8 -> V_32 [ 0 ] = F_26 ( V_11 ) ;
V_2 -> V_8 -> V_33 [ 0 ] = F_26 ( V_14 ) | F_26 ( V_13 ) ;
V_2 -> V_8 -> V_34 = F_7 ;
V_2 -> V_8 -> V_35 = F_13 ;
F_27 ( V_2 -> V_8 , V_2 ) ;
error = F_28 ( V_2 -> V_8 ) ;
if ( error ) {
F_22 ( & V_16 -> V_18 , L_7 , error ) ;
goto V_36;
}
F_29 ( V_16 , V_2 ) ;
return 0 ;
V_36:
F_30 ( V_2 -> V_8 ) ;
V_22:
F_31 ( V_2 -> V_4 ) ;
V_21:
F_32 ( V_2 ) ;
return error ;
}
static int F_33 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_34 ( V_16 ) ;
F_35 ( V_2 -> V_8 ) ;
F_31 ( V_2 -> V_4 ) ;
F_32 ( V_2 ) ;
return 0 ;
}
static int T_1 F_36 ( struct V_37 * V_18 )
{
struct V_1 * V_2 = F_37 ( V_18 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int T_1 F_38 ( struct V_37 * V_18 )
{
struct V_1 * V_2 = F_37 ( V_18 ) ;
if ( V_2 -> V_3 )
F_1 ( V_2 ) ;
return 0 ;
}
