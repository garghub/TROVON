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
F_9 ( V_10 , & V_15 , V_16 ) ;
break;
default:
F_9 ( V_10 , & V_15 , V_17 ) ;
}
return 0 ;
}
static int T_2
F_10 ( struct V_18 * V_19 , struct V_18 * V_20 )
{
if ( V_20 )
F_11 ( L_2 ) ;
V_21 = F_12 ( V_19 , V_22 , 0 , 0 ,
& V_23 , NULL ) ;
if ( ! V_21 )
F_11 ( L_3 ) ;
F_13 ( V_21 ) ;
return 0 ;
}
void F_14 ( void )
{
unsigned long V_24 = F_15 () ;
if ( V_24 & V_25 )
V_24 |= V_26 ;
else if ( V_24 & V_27 )
V_24 |= V_28 ;
F_16 ( V_24 ) ;
}
