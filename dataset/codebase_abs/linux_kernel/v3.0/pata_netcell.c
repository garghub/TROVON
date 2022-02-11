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
static int V_12 ;
static const struct V_13 V_14 = {
. V_15 = V_16 ,
. V_17 = V_18 ,
. V_19 = V_20 ,
. V_21 = V_22 ,
. V_23 = & V_24 ,
} ;
const struct V_13 * V_25 [] = { & V_14 , NULL } ;
int V_26 ;
if ( ! V_12 ++ )
F_4 ( V_27 , & V_9 -> V_28 ,
L_1 V_29 L_2 ) ;
V_26 = F_5 ( V_9 ) ;
if ( V_26 )
return V_26 ;
F_6 ( V_9 ) ;
return F_7 ( V_9 , V_25 , & V_30 , NULL , 0 ) ;
}
static int T_2 F_8 ( void )
{
return F_9 ( & V_31 ) ;
}
static void T_3 F_10 ( void )
{
F_11 ( & V_31 ) ;
}
