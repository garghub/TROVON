static inline void F_1 ( int V_1 )
{
V_2 [ V_1 ] . F_2 ( V_2 [ V_1 ] . V_3 ) ;
}
static T_1 F_3 ( int V_4 , void * V_3 )
{
unsigned long V_5 ;
unsigned int V_1 ;
V_5 = F_4 ( V_6 ) ;
F_5 ( V_5 & ~ 0x00ff0003 , V_6 ) ;
V_5 &= V_5 >> 8 ;
if ( V_5 & 1 )
F_1 ( V_7 ) ;
if ( V_5 & 2 )
F_1 ( V_8 ) ;
V_5 >>= 16 ;
while ( V_5 ) {
V_1 = F_6 ( V_5 ) ;
V_5 &= V_5 - 1 ;
F_1 ( V_1 + V_9 ) ;
}
return V_10 ;
}
static void F_7 ( unsigned int V_11 )
{
unsigned long V_5 ;
V_5 = F_4 ( V_6 ) ;
V_5 &= ~ ( 1 << ( ( V_11 > 1 ) ? V_11 + 22 : V_11 + 8 ) ) ;
F_5 ( V_5 , V_6 ) ;
}
static void F_8 ( unsigned int V_11 )
{
unsigned long V_5 ;
V_5 = F_4 ( V_6 ) ;
V_5 |= ( 1 << ( ( V_11 > 1 ) ? V_11 + 22 : V_11 + 8 ) ) ;
F_5 ( V_5 , V_6 ) ;
}
int F_9 ( unsigned int V_11 , void (* F_2)( void * ) ,
void * V_3 )
{
if ( ( V_11 > 9 ) || ! F_2 )
return - V_12 ;
if ( V_2 [ V_11 ] . F_2 )
return - V_13 ;
V_2 [ V_11 ] . F_2 = F_2 ;
V_2 [ V_11 ] . V_3 = V_3 ;
F_8 ( V_11 ) ;
return 0 ;
}
void F_10 ( unsigned int V_11 )
{
if ( F_11 ( V_11 < 10 ) ) {
F_7 ( V_11 ) ;
V_2 [ V_11 ] . F_2 = NULL ;
V_2 [ V_11 ] . V_3 = NULL ;
}
}
static int T_2 F_12 ( void )
{
unsigned long V_14 ;
int V_15 ;
V_2 = F_13 ( 10 * sizeof( struct V_16 ) ,
V_17 ) ;
if ( ! V_2 )
return - V_18 ;
#ifdef F_14
V_15 = F_15 ( 0 , L_1 ) ;
if ( V_15 < 0 )
F_16 ( V_19 L_2 ) ;
#endif
F_5 ( 0 , V_6 ) ;
F_5 ( 0 , V_20 ) ;
F_5 ( 0x94000000 , V_21 ) ;
V_14 = F_4 ( V_22 ) ;
F_5 ( V_14 | V_23 | V_24 , V_22 ) ;
V_15 = F_17 ( V_25 , F_3 , 0 ,
L_3 , NULL ) ;
if ( V_15 )
goto V_26;
V_15 = F_17 ( V_27 , F_3 , 0 ,
L_4 , NULL ) ;
if ( V_15 )
goto V_28;
V_15 = F_17 ( V_29 , F_3 , 0 ,
L_5 , NULL ) ;
if ( V_15 == 0 )
return V_15 ;
F_18 ( V_27 , 0 ) ;
V_28: F_18 ( V_25 , 0 ) ;
V_26: F_19 ( V_2 ) ;
return V_15 ;
}
