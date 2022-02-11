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
static void F_3 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
struct V_7 V_8 ;
T_1 V_2 ;
V_8 . V_9 = F_1 ( 0 ) ;
V_8 . V_10 = V_11 [ V_6 ] . V_12 ;
F_4 ( V_5 , & V_8 , V_13 ) ;
F_5 ( L_3 ,
V_11 [ V_6 ] . V_12 ) ;
F_6 () ;
V_2 = * V_3 & ~ 0x03 ;
* V_3 = V_2 | V_11 [ V_6 ] . V_14 ;
F_7 () ;
F_4 ( V_5 , & V_8 , V_15 ) ;
}
static int F_8 ( struct V_4 * V_5 )
{
return F_9 ( V_5 , & V_11 [ 0 ] ) ;
}
static int F_10 ( struct V_4 * V_5 ,
unsigned int V_16 ,
unsigned int V_17 )
{
unsigned int V_18 = 0 ;
if ( F_11 ( V_5 , V_11 ,
V_16 , V_17 , & V_18 ) )
return - V_19 ;
F_3 ( V_5 , V_18 ) ;
return 0 ;
}
static int F_12 ( struct V_4 * V_5 )
{
struct V_20 * V_21 = & F_13 ( 0 ) ;
int V_22 ;
if ( V_21 -> V_23 != V_24 ||
V_21 -> V_25 != 4 || V_21 -> V_26 != 9 )
return - V_27 ;
V_5 -> V_28 . V_29 = 1000000 ;
V_5 -> V_30 = F_1 ( 0 ) ;
V_22 = F_14 ( V_5 , V_11 ) ;
if ( V_22 )
return V_22 ;
F_15 ( V_11 , V_5 -> V_1 ) ;
return 0 ;
}
static int F_16 ( struct V_4 * V_5 )
{
F_17 ( V_5 -> V_1 ) ;
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
