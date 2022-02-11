T_1 unsigned long F_1 ( void )
{
unsigned long V_1 = F_2 () ;
if ( ! ( V_1 & V_2 ) || ( V_1 & V_3 ) )
V_1 &= ~ V_2 ;
return V_1 ;
}
T_2 void F_3 ( unsigned long V_1 )
{
if ( V_1 & V_2 )
V_1 &= ~ V_3 ;
else
V_1 |= V_3 ;
F_4 ( V_1 ) ;
}
T_1 void F_5 ( void )
{
unsigned long V_1 = F_2 () ;
F_4 ( ( V_1 & ~ V_2 ) | V_3 ) ;
}
T_1 void F_6 ( void )
{
unsigned long V_1 = F_2 () ;
F_4 ( ( V_1 | V_2 ) & ( ~ V_3 ) ) ;
}
static unsigned T_3 F_7 ( T_4 type , T_5 V_4 , void * V_5 ,
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
static void T_6 F_11 ( void )
{
void T_7 * V_13 ;
unsigned int V_14 , V_15 , V_16 ;
V_16 = F_12 ( 0 , 0x1f , 0 , V_17 ) ;
V_13 = F_13 ( V_16 , 8 ) ;
V_14 = F_14 ( V_13 ) ;
V_15 = F_14 ( V_13 + 4 ) ;
F_15 ( V_18 L_1 ,
V_14 , V_15 ) ;
#ifdef F_16
if ( V_14 & V_15 & F_17 ( 8 ) ) {
V_15 &= ~ F_17 ( 8 ) ;
#ifdef F_18
V_19 = 1 ;
#endif
}
#endif
if ( V_14 & V_15 & ( 1 << 4 ) ) {
V_8 . V_10 = F_19 ( F_5 ) ;
V_8 . V_9 = F_19 ( F_6 ) ;
V_8 . V_11 = F_19 ( F_1 ) ;
V_8 . V_12 = F_19 ( F_3 ) ;
V_20 . V_21 = F_7 ;
V_15 &= ~ ( 1 << 4 ) ;
}
F_20 ( V_15 , V_13 + 4 ) ;
V_15 = F_14 ( V_13 + 4 ) ;
F_21 ( L_2 , V_15 ) ;
F_22 ( V_13 , 8 ) ;
}
static void T_6 F_11 ( void )
{
}
static void T_6 F_23 ( void )
{
V_22 = 0 ;
if ( ! F_24 () )
return;
if ( F_12 ( 0 , 0x1f , 0 , V_23 ) ==
( V_24 | ( V_25 << 16 ) ) )
V_22 = 1 ;
}
int F_25 ( void )
{
if ( V_22 != - 1 )
return V_22 ;
else {
F_26 ( 1 ) ;
return 0 ;
}
}
static void T_6 F_23 ( void )
{
}
int F_25 ( void )
{
return 0 ;
}
static void T_6 F_27 ( void )
{
#if ! F_28 ( V_26 ) && F_28 ( F_16 )
void T_7 * V_13 ;
unsigned int V_16 , V_27 , V_28 , V_29 ;
if ( V_30 != V_31 )
return;
V_16 = F_12 ( 0 , 0x1f , 0 , V_17 ) ;
V_13 = F_13 ( V_16 + V_32 , 4 ) ;
if ( F_29 ( ! V_13 ) )
return;
V_27 = F_14 ( V_13 ) ;
V_28 = ( V_27 >> 16 ) & 0x7 ;
if ( ! V_28 )
V_28 = 8 ;
V_29 = ( V_27 & ( ( 1 << V_28 ) - 1 ) ) + 1 ;
F_21 ( L_3 ,
V_29 ) ;
V_30 = V_29 ;
F_22 ( V_13 , 4 ) ;
#endif
}
static int F_30 ( int V_33 , int V_34 )
{
return F_31 () >> V_34 ;
}
static void F_32 ( int V_35 , struct V_36 * V_37 ,
const struct V_36 * V_38 )
{
F_33 ( V_37 ) ;
}
static void F_34 ( void )
{
V_39 -> V_40 = F_30 ;
V_39 -> V_41 = F_32 ;
}
void T_6 F_35 ( void )
{
F_23 () ;
if ( ! F_25 () )
return;
V_42 . V_43 = F_34 ;
F_27 () ;
F_11 () ;
return;
}
