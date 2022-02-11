void F_1 ( void )
{
int V_1 = 0 ;
V_1 |= F_2 ( V_2 ) << 3 ;
V_1 |= F_2 ( V_3 ) << 5 ;
V_1 |= F_2 ( V_4 ) << 6 ;
F_3 ( V_5 , V_1 ) ;
if ( V_1 )
F_4 ( L_1 , V_1 ) ;
}
static void F_5 ( struct V_6 * V_7 )
{
unsigned int V_8 ;
V_8 = F_6 ( V_9 ) ;
V_8 &= ~ ( 1 << V_7 -> V_10 ) ;
F_3 ( V_9 , V_8 ) ;
}
static void F_7 ( struct V_6 * V_7 )
{
unsigned int V_8 ;
V_8 = F_6 ( V_9 ) ;
V_8 |= ( 1 << V_7 -> V_10 ) ;
F_3 ( V_9 , V_8 ) ;
}
static int F_8 ( struct V_11 * V_12 , unsigned int V_10 ,
T_1 V_13 )
{
switch ( V_10 ) {
case V_14 :
#ifdef F_9
case V_15 :
#endif
F_10 ( V_10 , & V_16 , V_17 ) ;
break;
default:
F_10 ( V_10 , & V_16 , V_18 ) ;
}
return 0 ;
}
static int T_2
F_11 ( struct V_19 * V_20 , struct V_19 * V_21 )
{
if ( V_21 )
F_12 ( L_2 ) ;
V_22 = F_13 ( V_20 , V_23 , 0 , 0 ,
& V_24 , NULL ) ;
if ( ! V_22 )
F_12 ( L_3 ) ;
F_14 ( V_22 ) ;
return 0 ;
}
void F_15 ( void )
{
unsigned long V_25 = F_16 () ;
if ( V_25 & V_26 )
V_25 |= V_27 ;
else if ( V_25 & V_28 )
V_25 |= V_29 ;
F_17 ( V_25 ) ;
}
