int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
unsigned long V_7 = 0 ;
if ( F_3 ( V_4 >= V_8 ) ) {
F_4 ( L_1 ) ;
return - V_9 ;
}
if ( V_3 ) {
if ( V_6 -> V_10 )
V_6 -> V_10 -> V_11 |= V_12 ;
} else {
if ( V_6 -> V_10 )
V_6 -> V_10 -> V_11 &= ~ V_12 ;
}
switch ( V_4 ) {
case V_13 :
case V_14 :
V_7 = F_5 ( 4 ) | V_15 ;
break;
case V_16 :
V_7 = F_5 ( 7 ) ;
break;
case V_17 :
V_7 = F_5 ( 2 ) ;
break;
}
if ( V_3 ) {
if ( V_7 ) {
V_7 |= F_6 ( V_18 ) ;
F_7 ( V_7 , V_18 ) ;
}
} else {
if ( V_7 ) {
V_7 = ~ V_7 & F_6 ( V_18 ) ;
F_7 ( V_7 , V_18 ) ;
}
}
return 0 ;
}
static void F_8 ( void )
{
unsigned int V_19 ;
F_7 ( 0x0 , F_9 ( 0x64 ) ) ;
F_7 ( 0x0 , F_9 ( 0x68 ) ) ;
V_19 = F_6 ( F_9 ( 0x1c ) ) ;
V_19 |= 0xf0 ;
F_7 ( V_19 , F_9 ( 0x1c ) ) ;
return ;
}
static void F_10 ( void )
{
unsigned int V_19 ;
F_7 ( 0x03003003 , F_9 ( 0x64 ) ) ;
F_7 ( 0x00303030 , F_9 ( 0x68 ) ) ;
V_19 = F_6 ( F_9 ( 0x1c ) ) ;
V_19 &= ~ ( 0xf0 ) ;
F_7 ( V_19 , F_9 ( 0x1c ) ) ;
return ;
}
static void F_11 ( void )
{
F_7 ( 0x0000a010 , V_20 ) ;
}
static void F_12 ( void )
{
unsigned int V_19 ;
F_7 ( 0xdffefffe , V_20 ) ;
V_19 = F_6 ( V_21 ) ;
V_19 |= ( 1 << 29 ) ;
F_7 ( V_19 , V_21 ) ;
return ;
}
void F_13 ( int V_22 )
{
T_1 V_23 , V_24 ;
V_23 = F_6 ( V_25 ) ;
V_24 = F_6 ( V_26 ) ;
V_24 &= ~ ( V_27 | V_28 | V_29
| V_30 | V_31 | ( 1 << 13 ) ) ;
V_23 &= ~ V_32 ;
switch ( V_22 ) {
case V_33 :
V_24 |= V_27 ;
V_24 |= V_31 ;
case V_34 :
V_24 |= V_27 ;
case V_35 :
V_24 |= V_29 ;
case V_36 :
V_24 |= V_30 ;
V_24 |= V_28 ;
V_23 |= V_37 ;
V_24 |= V_38 ;
case V_39 :
V_23 |= V_32 ;
V_23 &= ~ V_40 ;
V_23 |= F_14 ( 3 )
| V_41 ;
break;
case V_42 :
V_24 &= ~ V_38 ;
break;
}
V_24 |= ( 1 << 30 ) | ( 1 << 25 ) ;
F_7 ( V_23 , V_25 ) ;
F_7 ( V_24 , V_26 ) ;
}
static int F_15 ( T_2 V_22 )
{
int V_43 ;
V_43 = F_6 ( V_44 ) ;
if ( V_43 & ( 1 << 1 ) ) {
F_16 ( V_45 L_2 , V_46 ) ;
return - V_47 ;
}
V_43 = F_6 ( V_48 ) ;
V_43 |= ( ( 1 << 19 ) | ( 1 << 18 ) ) ;
F_7 ( V_43 , V_48 ) ;
F_11 () ;
F_8 () ;
F_16 ( V_49 L_3 , V_46 ) ;
F_17 () ;
F_16 ( V_49 L_4 , V_46 ) ;
F_12 () ;
F_10 () ;
return 0 ;
}
static int F_18 ( void )
{
F_13 ( V_33 ) ;
return 0 ;
}
static void F_19 ( void )
{
F_13 ( V_42 ) ;
}
static int F_20 ( T_2 V_22 )
{
return ( ( V_22 == V_50 ) || ( V_22 == V_51 ) ) ;
}
static int T_3 F_21 ( void )
{
T_1 V_24 ;
if ( ! F_22 () )
return - V_52 ;
F_23 ( & V_53 ) ;
F_7 ( 0x5 , V_54 ) ;
F_7 ( F_6 ( F_9 ( 0x8 ) ) & ~ ( 0x1 << 23 ) , F_9 ( 0x8 ) ) ;
V_24 = F_6 ( V_26 ) ;
V_24 &= ~ ( V_27 | V_28
| V_29 | V_30 | 1 << 13 ) ;
F_7 ( V_24 , V_26 ) ;
return 0 ;
}
