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
int F_2 ( struct V_7 * V_7 , T_1 V_3 , int V_8 , T_2 * V_9 )
{
return F_3 ( V_7 -> V_10 , V_3 , V_9 , V_8 ) ;
}
static int F_4 ( struct V_7 * V_7 )
{
const struct V_11 V_12 = {
. V_13 = L_1 ,
. V_14 = V_7 ,
. V_15 = sizeof( * V_7 ) ,
} ;
return F_5 ( V_7 -> V_2 , - 1 , & V_12 , 1 , NULL , 0 , NULL ) ;
}
static int F_6 ( struct V_7 * V_7 ,
struct V_16 * V_17 )
{
unsigned int V_3 ;
int V_18 ;
F_7 ( V_7 -> V_2 , V_7 ) ;
V_18 = F_8 ( V_7 -> V_10 , V_19 , & V_3 ) ;
if ( V_18 != 0 ) {
F_9 ( V_7 -> V_2 , L_2 ) ;
return - V_20 ;
}
if ( V_3 != 0x6172 ) {
F_9 ( V_7 -> V_2 , L_3 ,
V_3 ) ;
return - V_21 ;
}
V_18 = F_8 ( V_7 -> V_10 , V_22 , & V_3 ) ;
if ( V_18 != 0 ) {
F_9 ( V_7 -> V_2 , L_4 , V_18 ) ;
return V_18 ;
}
V_3 = ( V_3 & V_23 ) >> V_24 ;
F_10 ( V_7 -> V_2 , L_5 , V_3 ) ;
V_18 = F_4 ( V_7 ) ;
if ( V_18 != 0 ) {
F_9 ( V_7 -> V_2 , L_6 ) ;
return V_18 ;
}
if ( V_17 && V_17 -> V_25 ) {
V_18 = V_17 -> V_25 ( V_7 -> V_2 ) ;
if ( V_18 != 0 ) {
F_9 ( V_7 -> V_2 , L_7 ,
V_18 ) ;
return V_18 ;
}
} else
F_11 ( V_7 -> V_2 , L_8 ) ;
return 0 ;
}
void F_12 ( struct V_7 * V_7 )
{
F_13 ( V_7 -> V_10 , & V_26 ) ;
}
static int F_14 ( struct V_27 * V_28 ,
const struct V_29 * V_30 )
{
struct V_7 * V_7 ;
V_7 = F_15 ( & V_28 -> V_2 , sizeof( struct V_7 ) , V_31 ) ;
if ( ! V_7 )
return - V_32 ;
V_7 -> V_10 = F_16 ( V_28 , & V_26 ) ;
if ( F_17 ( V_7 -> V_10 ) )
return F_18 ( V_7 -> V_10 ) ;
V_7 -> V_2 = & V_28 -> V_2 ;
F_19 ( V_28 , V_7 ) ;
return F_6 ( V_7 , F_20 ( & V_28 -> V_2 ) ) ;
}
static int T_3 F_21 ( void )
{
int V_18 = - V_21 ;
#if F_22 ( V_33 )
V_18 = F_23 ( & V_34 ) ;
if ( V_18 != 0 )
F_24 ( L_9 , V_18 ) ;
#endif
return V_18 ;
}
static void T_4 F_25 ( void )
{
#if F_22 ( V_33 )
F_26 ( & V_34 ) ;
#endif
}
