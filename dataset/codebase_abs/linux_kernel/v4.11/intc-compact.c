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
static int F_8 ( struct V_10 * V_11 , unsigned int V_12 ,
T_1 V_13 )
{
switch ( V_13 ) {
case V_3 :
F_9 ( V_12 ) ;
F_10 ( V_12 , & V_14 , V_15 ) ;
break;
default:
F_10 ( V_12 , & V_14 , V_16 ) ;
}
return 0 ;
}
static int T_2
F_11 ( struct V_17 * V_18 , struct V_17 * V_19 )
{
struct V_10 * V_20 ;
if ( V_19 )
F_12 ( L_2 ) ;
V_20 = F_13 ( V_18 , V_21 ,
& V_22 , NULL ) ;
if ( ! V_20 )
F_12 ( L_3 ) ;
F_14 ( V_20 ) ;
return 0 ;
}
void F_15 ( void )
{
unsigned long V_23 = F_16 () ;
if ( V_23 & V_24 )
V_23 |= V_25 ;
else if ( V_23 & V_26 )
V_23 |= V_27 ;
F_17 ( V_23 ) ;
}
