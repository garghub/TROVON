int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
unsigned long V_4 = 0 ;
int V_5 = V_2 -> V_5 ;
switch ( V_5 ) {
case V_6 :
case V_7 :
V_4 = F_2 ( 4 ) | V_8 ;
break;
case V_9 :
V_4 = F_2 ( 7 ) ;
break;
case V_10 :
V_4 = F_2 ( 2 ) ;
break;
}
if ( V_3 ) {
if ( V_4 ) {
V_4 |= F_3 ( V_11 ) ;
F_4 ( V_4 , V_11 ) ;
}
} else {
if ( V_4 ) {
V_4 = ~ V_4 & F_3 ( V_11 ) ;
F_4 ( V_4 , V_11 ) ;
}
}
return 0 ;
}
static void F_5 ( void )
{
unsigned int V_12 ;
F_4 ( 0x0 , F_6 ( 0x64 ) ) ;
F_4 ( 0x0 , F_6 ( 0x68 ) ) ;
V_12 = F_3 ( F_6 ( 0x1c ) ) ;
V_12 |= 0xf0 ;
F_4 ( V_12 , F_6 ( 0x1c ) ) ;
return ;
}
static void F_7 ( void )
{
unsigned int V_12 ;
F_4 ( 0x03003003 , F_6 ( 0x64 ) ) ;
F_4 ( 0x00303030 , F_6 ( 0x68 ) ) ;
V_12 = F_3 ( F_6 ( 0x1c ) ) ;
V_12 &= ~ ( 0xf0 ) ;
F_4 ( V_12 , F_6 ( 0x1c ) ) ;
return ;
}
static void F_8 ( void )
{
F_4 ( 0x0000a010 , V_13 ) ;
}
static void F_9 ( void )
{
unsigned int V_12 ;
F_4 ( 0xdffefffe , V_13 ) ;
V_12 = F_3 ( V_14 ) ;
V_12 |= ( 1 << 29 ) ;
F_4 ( V_12 , V_14 ) ;
return ;
}
void F_10 ( int V_15 )
{
T_1 V_16 , V_17 ;
V_16 = F_3 ( V_18 ) ;
V_17 = F_3 ( V_19 ) ;
V_17 &= ~ ( V_20 | V_21 | V_22
| V_23 | V_24 | ( 1 << 13 ) ) ;
V_16 &= ~ V_25 ;
switch ( V_15 ) {
case V_26 :
V_17 |= V_20 ;
V_17 |= V_24 ;
case V_27 :
V_17 |= V_20 ;
case V_28 :
V_17 |= V_22 ;
case V_29 :
V_17 |= V_23 ;
V_17 |= V_21 ;
V_16 |= V_30 ;
V_17 |= V_31 ;
case V_32 :
V_16 |= V_25 ;
V_16 &= ~ V_33 ;
V_16 |= F_11 ( 3 )
| V_34 ;
break;
case V_35 :
V_17 &= ~ V_31 ;
break;
}
V_17 |= ( 1 << 30 ) | ( 1 << 25 ) ;
F_4 ( V_16 , V_18 ) ;
F_4 ( V_17 , V_19 ) ;
}
static int F_12 ( T_2 V_15 )
{
int V_36 ;
V_36 = F_3 ( V_37 ) ;
if ( V_36 & ( 1 << 1 ) ) {
F_13 ( V_38 L_1 , V_39 ) ;
return - V_40 ;
}
V_36 = F_3 ( V_41 ) ;
V_36 |= ( ( 1 << 19 ) | ( 1 << 18 ) ) ;
F_4 ( V_36 , V_41 ) ;
F_8 () ;
F_5 () ;
F_13 ( V_42 L_2 , V_39 ) ;
F_14 () ;
F_13 ( V_42 L_3 , V_39 ) ;
F_9 () ;
F_7 () ;
return 0 ;
}
static int F_15 ( void )
{
F_10 ( V_26 ) ;
return 0 ;
}
static void F_16 ( void )
{
F_10 ( V_35 ) ;
}
static int F_17 ( T_2 V_15 )
{
return ( ( V_15 == V_43 ) || ( V_15 == V_44 ) ) ;
}
static int T_3 F_18 ( void )
{
T_1 V_17 ;
if ( ! F_19 () )
return - V_45 ;
F_20 ( & V_46 ) ;
F_4 ( 0x5 , V_47 ) ;
F_4 ( F_3 ( F_6 ( 0x8 ) ) & ~ ( 0x1 << 23 ) , F_6 ( 0x8 ) ) ;
V_17 = F_3 ( V_19 ) ;
V_17 &= ~ ( V_20 | V_21
| V_22 | V_23 | 1 << 13 ) ;
F_4 ( V_17 , V_19 ) ;
return 0 ;
}
