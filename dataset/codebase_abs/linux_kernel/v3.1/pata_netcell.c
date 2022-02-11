static unsigned int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 * V_5 )
{
unsigned int V_6 = F_2 ( V_2 , V_4 , V_5 ) ;
if ( V_6 == 0 )
V_5 [ V_7 ] |= 0x4000 ;
return V_6 ;
}
static int F_3 ( struct V_8 * V_9 , const struct V_10 * V_11 )
{
static const struct V_12 V_13 = {
. V_14 = V_15 ,
. V_16 = V_17 ,
. V_18 = V_19 ,
. V_20 = V_21 ,
. V_22 = & V_23 ,
} ;
const struct V_12 * V_24 [] = { & V_13 , NULL } ;
int V_25 ;
F_4 ( & V_9 -> V_26 , V_27 ) ;
V_25 = F_5 ( V_9 ) ;
if ( V_25 )
return V_25 ;
F_6 ( V_9 ) ;
return F_7 ( V_9 , V_24 , & V_28 , NULL , 0 ) ;
}
static int T_2 F_8 ( void )
{
return F_9 ( & V_29 ) ;
}
static void T_3 F_10 ( void )
{
F_11 ( & V_29 ) ;
}
