static void F_1 ( void )
{
F_2 ( V_1 , V_2 ) ;
}
static int F_3 ( void )
{
T_1 V_3 ;
V_3 = F_4 ( V_2 ) ;
return ! ! ( V_3 & V_1 ) ;
return 0 ;
}
static int F_5 ( struct V_4 * V_5 )
{
unsigned int V_6 ;
T_1 V_3 ;
struct V_7 * V_8 ;
V_8 = F_6 ( V_9 ,
V_10 , NULL ) ;
if ( ! V_8 ) {
F_7 ( V_11 L_1 ) ;
return 1 ;
}
F_8 ( V_8 , 0x95 , & V_3 ) ;
F_9 ( V_8 , 0x95 , V_3 | 0x0c ) ;
F_8 ( V_8 , 0xe3 , & V_3 ) ;
F_9 ( V_8 , 0xe3 , V_3 | 0x04 ) ;
F_8 ( V_8 , 0xe4 , & V_3 ) ;
F_9 ( V_8 , 0xe4 , V_3 | 0x08 ) ;
F_8 ( V_8 , 0xe1 , & V_3 ) ;
F_9 ( V_8 , 0xe1 , V_3 & ~ V_1 ) ;
F_8 ( V_8 , 0xe0 , & V_3 ) ;
F_9 ( V_8 , 0xe0 , V_3 & ~ V_1 ) ;
F_1 () ;
F_2 ( F_4 ( V_12 ) | V_1 , V_12 ) ;
V_5 -> V_13 = ( F_10 ( V_14 ) & 0x1000 ) ?
V_15 : V_16 ;
V_5 -> V_17 = V_5 -> V_13 ;
F_11 ( V_8 ) ;
V_6 = V_18 . V_19 ;
if ( F_12 ( V_6 , & V_20 , V_21 , L_2 , V_5 ) ) {
F_7 (KERN_ERR PREFIX L_3 , irq) ;
return 1 ;
}
return 0 ;
}
static void F_13 ( int V_22 , int V_23 )
{
unsigned char V_3 ;
unsigned int V_24 = 0x26 ;
F_2 ( V_24 , 0x3c4 ) ;
V_3 = F_4 ( 0x3c5 ) ;
if ( V_23 )
V_3 |= 0x20 ;
else
V_3 &= ~ 0x20 ;
if ( V_22 )
V_3 |= 0x10 ;
else
V_3 &= ~ 0x10 ;
V_3 |= 0x01 ;
F_2 ( V_24 , 0x3c4 ) ;
F_2 ( V_3 , 0x3c5 ) ;
}
static void F_14 ( void )
{
int V_25 ;
F_13 ( 1 , 1 ) ;
for ( V_25 = 0 ; V_25 < 16 ; V_25 ++ ) {
F_15 ( 5 ) ;
F_13 ( 1 , 0 ) ;
F_15 ( 5 ) ;
F_13 ( 1 , 1 ) ;
}
F_15 ( 5 ) ;
F_2 ( F_4 ( V_12 ) | V_1 , V_12 ) ;
}
static void F_16 ( int V_26 )
{
F_17 ( F_18 ( 1 ) , V_26 ) ;
}
static T_2 F_19 ( void )
{
T_2 V_27 ;
if ( ! F_3 () )
return - 1 ;
V_27 = F_20 ( F_21 ( 10 ) ) ;
V_27 |= F_20 ( F_21 ( 11 ) ) << 1 ;
F_1 () ;
return V_27 ;
}
