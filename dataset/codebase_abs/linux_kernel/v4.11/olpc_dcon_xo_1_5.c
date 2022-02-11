static void F_1 ( void )
{
F_2 ( V_1 , V_2 ) ;
}
static int F_3 ( void )
{
T_1 V_3 ;
V_3 = F_4 ( V_2 ) ;
return ! ! ( V_3 & V_1 ) ;
}
static int F_5 ( struct V_4 * V_5 )
{
unsigned int V_6 ;
F_1 () ;
F_2 ( F_4 ( V_7 ) | V_1 , V_7 ) ;
V_5 -> V_8 = ( F_6 ( V_9 ) & 0x1000 ) ?
V_10 : V_11 ;
V_5 -> V_12 = V_5 -> V_8 ;
V_6 = V_13 . V_14 ;
if ( F_7 ( V_6 , & V_15 , V_16 , L_1 , V_5 ) ) {
F_8 ( L_2 , V_6 ) ;
return 1 ;
}
return 0 ;
}
static void F_9 ( int V_17 , int V_18 )
{
unsigned char V_3 ;
unsigned int V_19 = 0x26 ;
F_2 ( V_19 , 0x3c4 ) ;
V_3 = F_4 ( 0x3c5 ) ;
if ( V_18 )
V_3 |= 0x20 ;
else
V_3 &= ~ 0x20 ;
if ( V_17 )
V_3 |= 0x10 ;
else
V_3 &= ~ 0x10 ;
V_3 |= 0x01 ;
F_2 ( V_19 , 0x3c4 ) ;
F_2 ( V_3 , 0x3c5 ) ;
}
static void F_10 ( void )
{
int V_20 ;
F_9 ( 1 , 1 ) ;
for ( V_20 = 0 ; V_20 < 16 ; V_20 ++ ) {
F_11 ( 5 ) ;
F_9 ( 1 , 0 ) ;
F_11 ( 5 ) ;
F_9 ( 1 , 1 ) ;
}
F_11 ( 5 ) ;
F_2 ( F_4 ( V_7 ) | V_1 , V_7 ) ;
}
static void F_12 ( int V_21 )
{
F_13 ( F_14 ( 1 ) , V_21 ) ;
}
static int F_15 ( T_1 * V_22 )
{
if ( ! F_3 () )
return - 1 ;
* V_22 = F_16 ( F_17 ( 10 ) ) ;
* V_22 |= F_16 ( F_17 ( 11 ) ) << 1 ;
F_1 () ;
return 0 ;
}
