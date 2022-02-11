static int F_1 ( unsigned int V_1 , unsigned int V_2 )
{
T_1 V_3 , V_4 ;
if ( ! F_2 ( V_1 ) ||
( V_2 > V_5 ) || ( V_2 == V_6 ) )
return - V_7 ;
F_3 ( V_1 , V_8 , & V_3 , & V_4 ) ;
if ( V_3 & 0x01 )
F_4 ( L_1 , V_1 ) ;
if ( V_9 [ V_1 ] &&
( V_2 == V_10 || V_2 == V_11 ) )
V_2 = V_12 ;
F_3 ( V_1 , V_13 , & V_3 , & V_4 ) ;
if ( V_2 == V_5 ) {
F_4 ( L_2 , V_1 ) ;
F_5 ( V_1 , V_13 , V_3 & ~ ( 1 << 4 ) , V_4 ) ;
} else {
F_4 ( L_3 ,
V_1 , ( ( 125 * V_2 ) / 10 ) ) ;
V_3 = ( V_3 & ~ 14 ) ;
V_3 = V_3 | ( 1 << 4 ) | ( ( V_2 & 0x7 ) << 1 ) ;
F_5 ( V_1 , V_13 , V_3 , V_4 ) ;
}
return 0 ;
}
static int F_6 ( struct V_14 * V_15 ,
unsigned int V_16 ,
unsigned int V_17 )
{
unsigned int V_2 = V_6 ;
struct V_18 V_19 ;
int V_20 ;
if ( F_7 ( V_15 , & V_21 [ 0 ] ,
V_16 , V_17 , & V_2 ) )
return - V_7 ;
V_19 . V_22 = F_8 ( V_15 -> V_1 ) ;
V_19 . V_23 = V_24 * V_21 [ V_2 ] . V_25 / 8 ;
if ( V_19 . V_23 == V_19 . V_22 )
return 0 ;
F_9 (i, policy->cpus) {
V_19 . V_1 = V_20 ;
F_10 ( & V_19 , V_26 ) ;
}
F_9 (i, policy->cpus)
F_1 ( V_20 , V_21 [ V_2 ] . V_25 ) ;
F_9 (i, policy->cpus) {
V_19 . V_1 = V_20 ;
F_10 ( & V_19 , V_27 ) ;
}
return 0 ;
}
static int F_11 ( struct V_14 * V_15 )
{
return F_12 ( V_15 , & V_21 [ 0 ] ) ;
}
static unsigned int F_13 ( struct V_28 * V_29 )
{
if ( V_29 -> V_30 == 0x06 ) {
if ( F_14 ( V_29 , V_31 ) )
F_15 (KERN_WARNING PFX L_4
L_5
L_6
L_7
L_8 ) ;
switch ( V_29 -> V_32 ) {
case 0x0E :
case 0x0F :
case 0x16 :
case 0x1C :
V_33 . V_34 |= V_35 ;
return F_16 ( V_36 ) ;
case 0x0D :
V_33 . V_34 |= V_35 ;
case 0x09 :
return F_16 ( V_37 ) ;
}
}
if ( V_29 -> V_30 != 0xF )
return 0 ;
V_33 . V_34 |= V_35 ;
if ( F_17 () == V_38 ) {
F_18 (KERN_WARNING PFX L_9
L_10
L_11
L_12
L_13 ) ;
return F_16 ( V_38 ) ;
}
return F_16 ( V_39 ) ;
}
static int F_19 ( struct V_14 * V_15 )
{
struct V_28 * V_29 = & F_20 ( V_15 -> V_1 ) ;
int V_40 = 0 ;
unsigned int V_20 ;
#ifdef F_21
F_22 ( V_15 -> V_41 , F_23 ( V_15 -> V_1 ) ) ;
#endif
V_40 = ( V_29 -> V_30 << 8 ) | ( V_29 -> V_32 << 4 ) | V_29 -> V_42 ;
switch ( V_40 ) {
case 0x0f07 :
case 0x0f0a :
case 0x0f11 :
case 0x0f12 :
V_9 [ V_15 -> V_1 ] = 1 ;
F_4 ( L_14 ) ;
}
if ( F_17 () == V_39 &&
V_29 -> V_32 < 2 ) {
F_1 ( V_15 -> V_1 , V_5 ) ;
F_24 () ;
}
V_24 = F_13 ( V_29 ) ;
if ( ! V_24 )
return - V_7 ;
for ( V_20 = 1 ; ( V_21 [ V_20 ] . V_43 != V_44 ) ; V_20 ++ ) {
if ( ( V_20 < 2 ) && ( V_9 [ V_15 -> V_1 ] ) )
V_21 [ V_20 ] . V_43 = V_45 ;
else
V_21 [ V_20 ] . V_43 = ( V_24 * V_20 ) / 8 ;
}
F_25 ( V_21 , V_15 -> V_1 ) ;
V_15 -> V_46 . V_47 = 10000001 ;
V_15 -> V_48 = V_24 ;
return F_26 ( V_15 , & V_21 [ 0 ] ) ;
}
static int F_27 ( struct V_14 * V_15 )
{
F_28 ( V_15 -> V_1 ) ;
return 0 ;
}
static unsigned int F_8 ( unsigned int V_1 )
{
T_1 V_3 , V_4 ;
F_3 ( V_1 , V_13 , & V_3 , & V_4 ) ;
if ( V_3 & 0x10 ) {
V_3 = V_3 >> 1 ;
V_3 &= 0x7 ;
} else
V_3 = V_5 ;
if ( V_3 != V_5 )
return V_24 * V_3 / 8 ;
return V_24 ;
}
static int T_2 F_29 ( void )
{
struct V_28 * V_29 = & F_20 ( 0 ) ;
int V_49 ;
if ( V_29 -> V_50 != V_51 )
return - V_52 ;
if ( ! F_30 ( V_29 , V_53 ) ||
! F_30 ( V_29 , V_54 ) )
return - V_52 ;
V_49 = F_31 ( & V_33 ) ;
if ( ! V_49 )
F_18 (KERN_INFO PFX L_15
L_16 ) ;
return V_49 ;
}
static void T_3 F_32 ( void )
{
F_33 ( & V_33 ) ;
}
