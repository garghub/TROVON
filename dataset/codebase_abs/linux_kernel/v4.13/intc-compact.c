void F_1 ( void )
{
unsigned int V_1 = 0 , V_2 ;
V_1 |= F_2 ( V_3 ) << V_4 ;
F_3 ( V_5 , V_1 ) ;
if ( V_1 )
F_4 ( L_1 , V_1 ) ;
for ( V_2 = V_4 ; V_2 < V_6 ; V_2 ++ ) {
unsigned int V_7 ;
V_7 = F_5 ( V_8 ) ;
V_7 &= ~ ( 1 << V_2 ) ;
F_3 ( V_8 , V_7 ) ;
}
}
static void F_6 ( struct V_9 * V_10 )
{
unsigned int V_7 ;
V_7 = F_5 ( V_8 ) ;
V_7 &= ~ ( 1 << V_10 -> V_11 ) ;
F_3 ( V_8 , V_7 ) ;
}
static void F_7 ( struct V_9 * V_10 )
{
unsigned int V_7 ;
V_7 = F_5 ( V_8 ) ;
V_7 |= ( 1 << V_10 -> V_11 ) ;
F_3 ( V_8 , V_7 ) ;
}
static int F_8 ( struct V_12 * V_13 , unsigned int V_14 ,
T_1 V_15 )
{
switch ( V_15 ) {
case V_4 :
F_9 ( V_14 ) ;
F_10 ( V_14 , & V_16 , V_17 ) ;
break;
default:
F_10 ( V_14 , & V_16 , V_18 ) ;
}
return 0 ;
}
static int T_2
F_11 ( struct V_19 * V_20 , struct V_19 * V_21 )
{
struct V_12 * V_22 ;
if ( V_21 )
F_12 ( L_2 ) ;
V_22 = F_13 ( V_20 , V_6 ,
& V_23 , NULL ) ;
if ( ! V_22 )
F_12 ( L_3 ) ;
F_14 ( V_22 ) ;
return 0 ;
}
void F_15 ( void )
{
unsigned long V_24 = F_16 () ;
if ( V_24 & V_25 )
V_24 |= V_26 ;
else if ( V_24 & V_27 )
V_24 |= V_28 ;
F_17 ( V_24 ) ;
}
