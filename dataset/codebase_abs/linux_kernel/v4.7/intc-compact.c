void F_1 ( void )
{
int V_1 = 0 ;
V_1 |= F_2 ( V_2 ) << V_3 ;
F_3 ( V_4 , V_1 ) ;
if ( V_1 )
F_4 ( L_1 , V_1 ) ;
}
static void F_5 ( struct V_5 * V_6 )
{
unsigned int V_7 ;
V_7 = F_6 ( V_8 ) ;
V_7 &= ~ ( 1 << V_6 -> V_9 ) ;
F_3 ( V_8 , V_7 ) ;
}
static void F_7 ( struct V_5 * V_6 )
{
unsigned int V_7 ;
V_7 = F_6 ( V_8 ) ;
V_7 |= ( 1 << V_6 -> V_9 ) ;
F_3 ( V_8 , V_7 ) ;
}
static int F_8 ( struct V_10 * V_11 , unsigned int V_9 ,
T_1 V_12 )
{
switch ( V_12 ) {
case V_3 :
F_9 ( V_9 ) ;
F_10 ( V_9 , & V_13 , V_14 ) ;
break;
default:
F_10 ( V_9 , & V_13 , V_15 ) ;
}
return 0 ;
}
static int T_2
F_11 ( struct V_16 * V_17 , struct V_16 * V_18 )
{
struct V_10 * V_19 ;
if ( V_18 )
F_12 ( L_2 ) ;
V_19 = F_13 ( V_17 , V_20 ,
& V_21 , NULL ) ;
if ( ! V_19 )
F_12 ( L_3 ) ;
F_14 ( V_19 ) ;
return 0 ;
}
void F_15 ( void )
{
unsigned long V_22 = F_16 () ;
if ( V_22 & V_23 )
V_22 |= V_24 ;
else if ( V_22 & V_25 )
V_22 |= V_26 ;
F_17 ( V_22 ) ;
}
