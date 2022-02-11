static unsigned long F_1 ( void )
{
unsigned long V_1 = F_2 () ;
if ( ! ( V_1 & V_2 ) || ( V_1 & V_3 ) )
V_1 &= ~ V_2 ;
return V_1 ;
}
static void F_3 ( unsigned long V_1 )
{
if ( V_1 & V_2 )
V_1 &= ~ V_3 ;
else
V_1 |= V_3 ;
F_4 ( V_1 ) ;
}
static void F_5 ( void )
{
unsigned long V_1 = F_2 () ;
F_4 ( ( V_1 & ~ V_2 ) | V_3 ) ;
}
static void F_6 ( void )
{
unsigned long V_1 = F_2 () ;
F_4 ( ( V_1 | V_2 ) & ( ~ V_3 ) ) ;
}
static unsigned T_1 F_7 ( T_2 type , T_3 V_4 , void * V_5 ,
unsigned long V_6 , unsigned V_7 )
{
switch ( type ) {
case F_8 ( V_8 . V_9 ) :
case F_8 ( V_8 . V_10 ) :
case F_8 ( V_8 . V_11 ) :
case F_8 ( V_8 . V_12 ) :
return F_9 ( type , V_4 , V_5 , V_6 , V_7 ) ;
default:
return F_10 ( type , V_4 , V_5 , V_6 , V_7 ) ;
}
}
static void T_4 F_11 ( void )
{
void T_5 * V_13 ;
unsigned int V_14 , V_15 , V_16 ;
V_16 = F_12 ( 0 , 0x1f , 0 , V_17 ) ;
V_13 = F_13 ( V_16 , 8 ) ;
V_14 = F_14 ( V_13 ) ;
V_15 = F_14 ( V_13 + 4 ) ;
F_15 ( V_18 L_1 ,
V_14 , V_15 ) ;
if ( V_14 & V_15 & ( 1 << 4 ) ) {
V_8 . V_10 = F_16 ( F_5 ) ;
V_8 . V_9 = F_16 ( F_6 ) ;
V_8 . V_11 = F_16 ( F_1 ) ;
V_8 . V_12 = F_16 ( F_3 ) ;
V_19 . V_20 = F_7 ;
V_15 &= ~ ( 1 << 4 ) ;
F_17 ( V_15 , V_13 + 4 ) ;
V_15 = F_14 ( V_13 + 4 ) ;
F_15 ( V_18 L_2 , V_15 ) ;
}
F_18 ( V_13 , 8 ) ;
}
static void T_4 F_11 ( void )
{
}
static void T_4 F_19 ( void )
{
V_21 = 0 ;
if ( ! F_20 () )
return;
if ( F_12 ( 0 , 0x1f , 0 , V_22 ) ==
( V_23 | ( V_24 << 16 ) ) )
V_21 = 1 ;
}
int F_21 ( void )
{
if ( V_21 != - 1 )
return V_21 ;
else {
F_22 ( 1 ) ;
return 0 ;
}
}
static void T_4 F_19 ( void )
{
}
int F_21 ( void )
{
return 0 ;
}
void T_4 F_23 ( void )
{
F_19 () ;
if ( ! F_21 () )
return;
F_11 () ;
return;
}
