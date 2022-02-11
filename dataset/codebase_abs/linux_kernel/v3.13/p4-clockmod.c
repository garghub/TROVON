static int F_1 ( unsigned int V_1 , unsigned int V_2 )
{
T_1 V_3 , V_4 ;
if ( ( V_2 > V_5 ) || ( V_2 == V_6 ) )
return - V_7 ;
F_2 ( V_1 , V_8 , & V_3 , & V_4 ) ;
if ( V_3 & 0x01 )
F_3 ( L_1 , V_1 ) ;
if ( V_9 [ V_1 ] &&
( V_2 == V_10 || V_2 == V_11 ) )
V_2 = V_12 ;
F_2 ( V_1 , V_13 , & V_3 , & V_4 ) ;
if ( V_2 == V_5 ) {
F_3 ( L_2 , V_1 ) ;
F_4 ( V_1 , V_13 , V_3 & ~ ( 1 << 4 ) , V_4 ) ;
} else {
F_3 ( L_3 ,
V_1 , ( ( 125 * V_2 ) / 10 ) ) ;
V_3 = ( V_3 & ~ 14 ) ;
V_3 = V_3 | ( 1 << 4 ) | ( ( V_2 & 0x7 ) << 1 ) ;
F_4 ( V_1 , V_13 , V_3 , V_4 ) ;
}
return 0 ;
}
static int F_5 ( struct V_14 * V_15 , unsigned int V_16 )
{
int V_17 ;
F_6 (i, policy->cpus)
F_1 ( V_17 , V_18 [ V_16 ] . V_19 ) ;
return 0 ;
}
static unsigned int F_7 ( struct V_20 * V_21 )
{
if ( V_21 -> V_22 == 0x06 ) {
if ( F_8 ( V_21 , V_23 ) )
F_9 (KERN_WARNING PFX L_4
L_5
L_6
L_7
L_8 ) ;
switch ( V_21 -> V_24 ) {
case 0x0E :
case 0x0F :
case 0x16 :
case 0x1C :
V_25 . V_26 |= V_27 ;
return F_10 ( V_28 ) ;
case 0x0D :
V_25 . V_26 |= V_27 ;
case 0x09 :
return F_10 ( V_29 ) ;
}
}
if ( V_21 -> V_22 != 0xF )
return 0 ;
V_25 . V_26 |= V_27 ;
if ( F_11 () == V_30 ) {
F_12 (KERN_WARNING PFX L_9
L_10
L_11
L_12
L_13 ) ;
return F_10 ( V_30 ) ;
}
return F_10 ( V_31 ) ;
}
static int F_13 ( struct V_14 * V_15 )
{
struct V_20 * V_21 = & F_14 ( V_15 -> V_1 ) ;
int V_32 = 0 ;
unsigned int V_17 ;
#ifdef F_15
F_16 ( V_15 -> V_33 , F_17 ( V_15 -> V_1 ) ) ;
#endif
V_32 = ( V_21 -> V_22 << 8 ) | ( V_21 -> V_24 << 4 ) | V_21 -> V_34 ;
switch ( V_32 ) {
case 0x0f07 :
case 0x0f0a :
case 0x0f11 :
case 0x0f12 :
V_9 [ V_15 -> V_1 ] = 1 ;
F_3 ( L_14 ) ;
}
if ( F_11 () == V_31 &&
V_21 -> V_24 < 2 ) {
F_1 ( V_15 -> V_1 , V_5 ) ;
F_18 () ;
}
V_35 = F_7 ( V_21 ) ;
if ( ! V_35 )
return - V_7 ;
for ( V_17 = 1 ; ( V_18 [ V_17 ] . V_36 != V_37 ) ; V_17 ++ ) {
if ( ( V_17 < 2 ) && ( V_9 [ V_15 -> V_1 ] ) )
V_18 [ V_17 ] . V_36 = V_38 ;
else
V_18 [ V_17 ] . V_36 = ( V_35 * V_17 ) / 8 ;
}
V_15 -> V_39 . V_40 = 10000001 ;
return F_19 ( V_15 , & V_18 [ 0 ] ) ;
}
static unsigned int F_20 ( unsigned int V_1 )
{
T_1 V_3 , V_4 ;
F_2 ( V_1 , V_13 , & V_3 , & V_4 ) ;
if ( V_3 & 0x10 ) {
V_3 = V_3 >> 1 ;
V_3 &= 0x7 ;
} else
V_3 = V_5 ;
if ( V_3 != V_5 )
return V_35 * V_3 / 8 ;
return V_35 ;
}
static int T_2 F_21 ( void )
{
int V_41 ;
if ( ! F_22 ( V_42 ) || ! F_23 ( V_43 ) )
return - V_44 ;
V_41 = F_24 ( & V_25 ) ;
if ( ! V_41 )
F_12 (KERN_INFO PFX L_15
L_16 ) ;
return V_41 ;
}
static void T_3 F_25 ( void )
{
F_26 ( & V_25 ) ;
}
