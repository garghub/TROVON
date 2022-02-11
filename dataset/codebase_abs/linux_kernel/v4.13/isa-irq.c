static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = 1 << ( V_2 -> V_4 & 7 ) ;
F_2 ( F_3 ( V_5 ) | V_3 , V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
unsigned int V_3 = 1 << ( V_2 -> V_4 & 7 ) ;
F_2 ( F_3 ( V_5 ) | V_3 , V_5 ) ;
F_2 ( 0x20 , V_6 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
unsigned int V_3 = 1 << ( V_2 -> V_4 & 7 ) ;
F_2 ( F_3 ( V_5 ) & ~ V_3 , V_5 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
unsigned int V_3 = 1 << ( V_2 -> V_4 & 7 ) ;
F_2 ( F_3 ( V_7 ) | V_3 , V_7 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
unsigned int V_3 = 1 << ( V_2 -> V_4 & 7 ) ;
F_2 ( F_3 ( V_7 ) | V_3 , V_7 ) ;
F_2 ( 0x62 , V_6 ) ;
F_2 ( 0x20 , V_8 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
unsigned int V_3 = 1 << ( V_2 -> V_4 & 7 ) ;
F_2 ( F_3 ( V_7 ) & ~ V_3 , V_7 ) ;
}
static void F_9 ( struct V_9 * V_10 )
{
unsigned int V_11 = * ( unsigned char * ) V_12 ;
if ( V_11 < F_10 ( 0 ) || V_11 >= F_10 ( 16 ) ) {
F_11 ( V_10 ) ;
return;
}
F_12 ( V_11 ) ;
}
void T_1 F_13 ( unsigned int V_13 )
{
unsigned int V_4 ;
F_2 ( 0x11 , V_6 ) ;
F_2 ( F_10 ( 0 ) , V_5 ) ;
F_2 ( 0x04 , V_5 ) ;
F_2 ( 0x01 , V_5 ) ;
F_2 ( 0xf5 , V_5 ) ;
F_2 ( 0x11 , V_8 ) ;
F_2 ( F_10 ( 8 ) , V_7 ) ;
F_2 ( 0x02 , V_7 ) ;
F_2 ( 0x01 , V_7 ) ;
F_2 ( 0xfa , V_7 ) ;
F_2 ( 0x0b , V_6 ) ;
F_2 ( 0x0b , V_8 ) ;
if ( F_3 ( V_5 ) == 0xf5 && F_3 ( V_7 ) == 0xfa ) {
F_2 ( 0xff , V_5 ) ;
F_2 ( 0xff , V_7 ) ;
} else {
F_14 ( V_14 L_1 ) ;
V_13 = ( unsigned int ) - 1 ;
}
if ( V_13 != ( unsigned int ) - 1 ) {
for ( V_4 = F_10 ( 0 ) ; V_4 < F_10 ( 8 ) ; V_4 ++ ) {
F_15 ( V_4 , & V_15 ,
V_16 ) ;
F_16 ( V_4 , V_17 | V_18 ) ;
}
for ( V_4 = F_10 ( 8 ) ; V_4 < F_10 ( 16 ) ; V_4 ++ ) {
F_15 ( V_4 , & V_19 ,
V_16 ) ;
F_16 ( V_4 , V_17 | V_18 ) ;
}
F_17 ( & V_20 , & V_21 ) ;
F_17 ( & V_20 , & V_22 ) ;
F_18 ( V_23 , & V_24 ) ;
F_19 ( V_13 , F_9 ) ;
if ( F_20 () )
F_21 ( F_10 ( 11 ) ,
V_17 | V_18 , V_25 ) ;
}
}
