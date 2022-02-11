static int F_1 ( void )
{
void T_1 * V_1 = F_2 ( V_2 ) ;
T_2 V_3 = F_3 ( V_1 + V_4 ) & 0xff ;
switch ( V_3 ) {
case 0x0 :
return V_5 ;
case 0x10 :
return V_6 ;
default:
return V_7 ;
}
}
int F_4 ( void )
{
if ( ! F_5 () )
return - V_8 ;
if ( V_9 == - 1 )
V_9 = F_1 () ;
return V_9 ;
}
static int T_3 F_6 ( void )
{
if ( ! F_5 () )
return 0 ;
if ( F_4 () < V_6 &&
( V_10 & V_11 ) ) {
V_10 &= ~ V_11 ;
F_7 ( L_1 ) ;
}
return 0 ;
}
static int F_8 ( void )
{
void T_1 * V_1 = F_2 ( V_12 ) ;
T_2 V_3 = F_3 ( V_1 + V_4 ) & 0xff ;
switch ( V_3 ) {
case 0x0 :
return V_13 ;
case 0x2 :
return V_5 ;
case 0x3 :
return V_14 ;
default:
return V_7 ;
}
}
int F_9 ( void )
{
if ( ! F_10 () )
return - V_8 ;
if ( V_9 == - 1 )
V_9 = F_8 () ;
return V_9 ;
}
static int F_11 ( void )
{
void T_1 * V_15 = F_12 ( V_16 , V_17 ) ;
T_2 V_3 ;
if ( ! V_15 ) {
V_9 = - V_8 ;
return 0 ;
}
V_3 = F_3 ( V_15 + V_18 ) ;
V_3 &= 0xff ;
F_13 ( V_15 ) ;
if ( V_3 == 0x0 )
return V_13 ;
else if ( V_3 == 0x1 )
return V_19 ;
return 0 ;
}
int F_14 ( void )
{
if ( ! F_15 () )
return - V_8 ;
if ( V_9 == - 1 )
V_9 = F_11 () ;
return V_9 ;
}
static int T_3 F_16 ( void )
{
unsigned int V_20 ;
void T_1 * V_21 ;
if ( F_5 () || F_10 () ) {
if ( F_5 () )
V_21 = F_2 ( V_22 ) ;
else
V_21 = F_17 ( V_23 ) ;
F_18 ( 0x0 , V_21 + 0x40 ) ;
F_18 ( 0x0 , V_21 + 0x44 ) ;
F_18 ( 0x0 , V_21 + 0x48 ) ;
F_18 ( 0x0 , V_21 + 0x4C ) ;
V_20 = F_19 ( V_21 + 0x50 ) & 0x00FFFFFF ;
F_18 ( V_20 , V_21 + 0x50 ) ;
if ( F_5 () )
V_21 = F_2 ( V_24 ) ;
else
V_21 = F_17 ( V_25 ) ;
F_18 ( 0x0 , V_21 + 0x40 ) ;
F_18 ( 0x0 , V_21 + 0x44 ) ;
F_18 ( 0x0 , V_21 + 0x48 ) ;
F_18 ( 0x0 , V_21 + 0x4C ) ;
V_20 = F_19 ( V_21 + 0x50 ) & 0x00FFFFFF ;
F_18 ( V_20 , V_21 + 0x50 ) ;
}
return 0 ;
}
