static int F_1 ( struct V_1 * V_2 , struct V_3 * * V_4 )
{
struct V_3 * V_5 ;
F_2 (dev, link, ENABLED) {
V_5 -> V_6 = V_7 ;
V_5 -> V_8 = V_7 ;
V_5 -> V_9 = V_10 ;
V_5 -> V_11 |= V_12 ;
F_3 ( V_5 , V_13 , L_1 ) ;
}
return 0 ;
}
static int F_4 ( struct V_14 * V_15 )
{
T_1 V_16 ;
if ( F_5 ( V_15 , 0x40 , & V_16 ) != 0 )
return - 1 ;
V_16 &= 0xDFFF ;
if ( F_6 ( V_15 , 0x40 , V_16 ) != 0 )
return - 1 ;
F_7 (KERN_INFO DRV_NAME L_2 ) ;
return 0 ;
}
static int F_8 ( struct V_14 * V_15 , const struct V_17 * V_18 )
{
static const struct V_19 V_20 = {
. V_11 = V_21 ,
. V_22 = V_23 ,
. V_24 = & V_25
} ;
const struct V_19 * V_26 [] = { & V_20 , NULL } ;
F_9 (KERN_DEBUG DRV_NAME L_3 DRV_VERSION L_4 ) ;
if ( F_4 ( V_15 ) == 0 )
return F_10 ( V_15 , V_26 , & V_27 , NULL , 0 ) ;
F_7 (KERN_ERR DRV_NAME L_5 ) ;
return - V_28 ;
}
static int F_11 ( struct V_14 * V_15 )
{
struct V_29 * V_30 = F_12 ( & V_15 -> V_5 ) ;
int V_31 ;
V_31 = F_13 ( V_15 ) ;
if ( V_31 )
return V_31 ;
if ( F_4 ( V_15 ) )
F_14 ( L_6 ) ;
F_15 ( V_30 ) ;
return 0 ;
}
static int T_2 F_16 ( void )
{
return F_17 ( & V_32 ) ;
}
static void T_3 F_18 ( void )
{
F_19 ( & V_32 ) ;
}
