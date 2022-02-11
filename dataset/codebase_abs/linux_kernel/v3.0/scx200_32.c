static void T_1 F_1 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < 2 ; ++ V_1 )
V_2 [ V_1 ] = F_2 ( V_3 + 0x10 * V_1 ) ;
}
static int T_1 F_3 ( struct V_4 * V_5 , const struct V_6 * V_7 )
{
unsigned V_8 ;
if ( V_5 -> V_9 == V_10 ||
V_5 -> V_9 == V_11 ) {
V_8 = F_4 ( V_5 , 0 ) ;
F_5 (KERN_INFO NAME L_1 , base) ;
if ( ! F_6 ( V_8 , V_12 , L_2 ) ) {
F_5 (KERN_ERR NAME L_3 ) ;
return - V_13 ;
}
V_3 = V_8 ;
F_1 () ;
} else {
if ( F_7 ( V_14 ) ) {
V_15 = V_14 ;
} else {
F_8 ( V_5 , V_16 , & V_8 ) ;
if ( F_7 ( V_8 ) ) {
V_15 = V_8 ;
} else {
F_5 (KERN_WARNING NAME L_4 ) ;
return - V_17 ;
}
}
F_5 (KERN_INFO NAME L_5 , scx200_cb_base) ;
}
return 0 ;
}
T_2 F_9 ( unsigned V_18 , T_2 V_19 , T_2 V_20 )
{
T_2 V_21 , V_22 ;
F_10 ( & V_23 ) ;
F_11 ( V_18 , V_3 + 0x20 ) ;
V_21 = F_2 ( V_3 + 0x24 ) ;
V_22 = ( V_21 & V_19 ) | V_20 ;
F_11 ( V_22 , V_3 + 0x24 ) ;
F_12 ( & V_23 ) ;
return V_21 ;
}
static int T_3 F_13 ( void )
{
F_5 (KERN_INFO NAME L_6 ) ;
return F_14 ( & V_24 ) ;
}
static void T_4 F_15 ( void )
{
F_16 ( & V_24 ) ;
F_17 ( V_3 , V_12 ) ;
}
