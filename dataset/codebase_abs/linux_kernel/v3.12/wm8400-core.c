static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
return true ;
default:
return false ;
}
}
T_1 F_2 ( struct V_7 * V_7 , T_2 V_3 )
{
unsigned int V_8 ;
int V_9 ;
V_9 = F_3 ( V_7 -> V_10 , V_3 , & V_8 ) ;
if ( V_9 < 0 )
return V_9 ;
return V_8 ;
}
int F_4 ( struct V_7 * V_7 , T_2 V_3 , int V_11 , T_1 * V_12 )
{
return F_5 ( V_7 -> V_10 , V_3 , V_12 , V_11 ) ;
}
static int F_6 ( struct V_7 * V_7 )
{
struct V_13 V_14 = {
. V_15 = L_1 ,
. V_16 = V_7 ,
. V_17 = sizeof( * V_7 ) ,
} ;
return F_7 ( V_7 -> V_2 , - 1 , & V_14 , 1 , NULL , 0 , NULL ) ;
}
static int F_8 ( struct V_7 * V_7 ,
struct V_18 * V_19 )
{
unsigned int V_3 ;
int V_9 ;
F_9 ( V_7 -> V_2 , V_7 ) ;
V_9 = F_3 ( V_7 -> V_10 , V_20 , & V_3 ) ;
if ( V_9 != 0 ) {
F_10 ( V_7 -> V_2 , L_2 ) ;
return - V_21 ;
}
if ( V_3 != 0x6172 ) {
F_10 ( V_7 -> V_2 , L_3 ,
V_3 ) ;
return - V_22 ;
}
V_9 = F_3 ( V_7 -> V_10 , V_23 , & V_3 ) ;
if ( V_9 != 0 ) {
F_10 ( V_7 -> V_2 , L_4 , V_9 ) ;
return V_9 ;
}
V_3 = ( V_3 & V_24 ) >> V_25 ;
F_11 ( V_7 -> V_2 , L_5 , V_3 ) ;
V_9 = F_6 ( V_7 ) ;
if ( V_9 != 0 ) {
F_10 ( V_7 -> V_2 , L_6 ) ;
goto V_26;
}
if ( V_19 && V_19 -> V_27 ) {
V_9 = V_19 -> V_27 ( V_7 -> V_2 ) ;
if ( V_9 != 0 ) {
F_10 ( V_7 -> V_2 , L_7 ,
V_9 ) ;
goto V_26;
}
} else
F_12 ( V_7 -> V_2 , L_8 ) ;
return 0 ;
V_26:
F_13 ( V_7 -> V_2 ) ;
return V_9 ;
}
static void F_14 ( struct V_7 * V_7 )
{
F_13 ( V_7 -> V_2 ) ;
}
void F_15 ( struct V_7 * V_7 )
{
F_16 ( V_7 -> V_10 , & V_28 ) ;
}
static int F_17 ( struct V_29 * V_30 ,
const struct V_31 * V_32 )
{
struct V_7 * V_7 ;
int V_9 ;
V_7 = F_18 ( & V_30 -> V_2 , sizeof( struct V_7 ) , V_33 ) ;
if ( V_7 == NULL ) {
V_9 = - V_34 ;
goto V_35;
}
V_7 -> V_10 = F_19 ( V_30 , & V_28 ) ;
if ( F_20 ( V_7 -> V_10 ) ) {
V_9 = F_21 ( V_7 -> V_10 ) ;
goto V_35;
}
V_7 -> V_2 = & V_30 -> V_2 ;
F_22 ( V_30 , V_7 ) ;
V_9 = F_8 ( V_7 , F_23 ( & V_30 -> V_2 ) ) ;
if ( V_9 != 0 )
goto V_35;
return 0 ;
V_35:
return V_9 ;
}
static int F_24 ( struct V_29 * V_30 )
{
struct V_7 * V_7 = F_25 ( V_30 ) ;
F_14 ( V_7 ) ;
return 0 ;
}
static int T_3 F_26 ( void )
{
int V_9 = - V_22 ;
#if F_27 ( V_36 ) || F_27 ( V_37 )
V_9 = F_28 ( & V_38 ) ;
if ( V_9 != 0 )
F_29 ( L_9 , V_9 ) ;
#endif
return V_9 ;
}
static void T_4 F_30 ( void )
{
#if F_27 ( V_36 ) || F_27 ( V_37 )
F_31 ( & V_38 ) ;
#endif
}
