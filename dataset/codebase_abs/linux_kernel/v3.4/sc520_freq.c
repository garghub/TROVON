static unsigned int F_1 ( unsigned int V_1 )
{
T_1 V_2 = * V_3 ;
switch ( V_2 & 0x03 ) {
default:
F_2 (KERN_ERR PFX L_1
L_2 , clockspeed_reg) ;
case 0x01 :
return 100000 ;
case 0x02 :
return 133000 ;
}
}
static void F_3 ( unsigned int V_4 )
{
struct V_5 V_6 ;
T_1 V_2 ;
V_6 . V_7 = F_1 ( 0 ) ;
V_6 . V_8 = V_9 [ V_4 ] . V_10 ;
V_6 . V_1 = 0 ;
F_4 ( & V_6 , V_11 ) ;
F_5 ( L_3 ,
V_9 [ V_4 ] . V_10 ) ;
F_6 () ;
V_2 = * V_3 & ~ 0x03 ;
* V_3 = V_2 | V_9 [ V_4 ] . V_12 ;
F_7 () ;
F_4 ( & V_6 , V_13 ) ;
}
static int F_8 ( struct V_14 * V_15 )
{
return F_9 ( V_15 , & V_9 [ 0 ] ) ;
}
static int F_10 ( struct V_14 * V_15 ,
unsigned int V_16 ,
unsigned int V_17 )
{
unsigned int V_18 = 0 ;
if ( F_11 ( V_15 , V_9 ,
V_16 , V_17 , & V_18 ) )
return - V_19 ;
F_3 ( V_18 ) ;
return 0 ;
}
static int F_12 ( struct V_14 * V_15 )
{
struct V_20 * V_21 = & F_13 ( 0 ) ;
int V_22 ;
if ( V_21 -> V_23 != V_24 ||
V_21 -> V_25 != 4 || V_21 -> V_26 != 9 )
return - V_27 ;
V_15 -> V_28 . V_29 = 1000000 ;
V_15 -> V_30 = F_1 ( 0 ) ;
V_22 = F_14 ( V_15 , V_9 ) ;
if ( V_22 )
return V_22 ;
F_15 ( V_9 , V_15 -> V_1 ) ;
return 0 ;
}
static int F_16 ( struct V_14 * V_15 )
{
F_17 ( V_15 -> V_1 ) ;
return 0 ;
}
static int T_2 F_18 ( void )
{
int V_31 ;
if ( ! F_19 ( V_32 ) )
return - V_27 ;
V_3 = F_20 ( ( unsigned long ) ( V_33 + V_34 ) , 1 ) ;
if ( ! V_3 ) {
F_2 ( V_35 L_4 ) ;
return - V_36 ;
}
V_31 = F_21 ( & V_37 ) ;
if ( V_31 )
F_22 ( V_3 ) ;
return V_31 ;
}
static void T_3 F_23 ( void )
{
F_24 ( & V_37 ) ;
F_22 ( V_3 ) ;
}
