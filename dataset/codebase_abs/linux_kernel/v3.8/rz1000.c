static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
if ( ! F_2 ( V_2 , 0x40 , & V_3 ) &&
! F_3 ( V_2 , 0x40 , V_3 & 0xdfff ) ) {
F_4 ( V_4 L_1
L_2 , F_5 ( V_2 ) ) ;
return 0 ;
} else {
F_4 ( V_4 L_3
L_2 , F_5 ( V_2 ) ) ;
return 1 ;
}
}
static int F_6 ( struct V_1 * V_2 , const struct V_5 * V_6 )
{
struct V_7 V_8 = V_9 ;
int V_10 ;
V_10 = F_7 ( V_2 ) ;
if ( V_10 )
return V_10 ;
if ( F_1 ( V_2 ) ) {
V_8 . V_11 |= V_12 ;
V_8 . V_11 |= V_13 ;
}
return F_8 ( V_2 , & V_8 , NULL ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_10 ( V_2 ) ;
F_11 ( V_2 ) ;
}
static int T_2 F_12 ( void )
{
return F_13 ( & V_14 ) ;
}
static void T_3 F_14 ( void )
{
F_15 ( & V_14 ) ;
}
