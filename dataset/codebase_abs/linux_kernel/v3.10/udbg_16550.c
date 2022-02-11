static void F_1 ( void )
{
if ( V_1 ) {
while ( ( F_2 ( & V_1 -> V_2 ) & V_3 ) == 0 )
;
}
}
static void F_3 ( char V_4 )
{
if ( V_1 ) {
if ( V_4 == '\n' )
F_3 ( '\r' ) ;
F_1 () ;
F_4 ( & V_1 -> V_5 , V_4 ) ;
}
}
static int F_5 ( void )
{
if ( V_1 ) {
if ( ( F_2 ( & V_1 -> V_2 ) & V_6 ) != 0 )
return F_2 ( & V_1 -> V_7 ) ;
else
return - 1 ;
}
return - 1 ;
}
static int F_6 ( void )
{
if ( V_1 ) {
while ( ( F_2 ( & V_1 -> V_2 ) & V_6 ) == 0 )
;
return F_2 ( & V_1 -> V_7 ) ;
}
return - 1 ;
}
void F_7 ( void T_1 * V_8 , unsigned int V_9 ,
unsigned int clock )
{
unsigned int V_10 , V_11 ;
if ( clock == 0 )
clock = 1843200 ;
if ( V_9 == 0 )
V_9 = 9600 ;
V_11 = clock / 16 ;
V_10 = V_11 / V_9 ;
if ( V_8 ) {
V_1 = (struct V_12 T_1 * ) V_8 ;
F_4 ( & V_1 -> V_13 , 0x00 ) ;
F_4 ( & V_1 -> V_14 , 0xff ) ;
F_4 ( & V_1 -> V_14 , 0x00 ) ;
F_4 ( & V_1 -> V_13 , V_15 ) ;
F_4 ( & V_1 -> V_10 , V_10 & 0xff ) ;
F_4 ( & V_1 -> V_16 , V_10 >> 8 ) ;
F_4 ( & V_1 -> V_13 , 0x03 ) ;
F_4 ( & V_1 -> V_17 , 0x03 ) ;
F_4 ( & V_1 -> V_18 , 0x07 ) ;
V_19 = F_3 ;
V_20 = F_1 ;
V_21 = F_6 ;
V_22 = F_5 ;
}
}
unsigned int F_8 ( void T_1 * V_8 , unsigned int clock )
{
unsigned int V_10 , V_16 , V_23 , V_24 , V_9 ;
T_2 V_25 ;
struct V_12 T_1 * V_26 = V_8 ;
V_25 = F_2 ( & V_26 -> V_13 ) ;
F_4 ( & V_26 -> V_13 , V_15 ) ;
V_10 = F_2 ( & V_26 -> V_10 ) ;
V_16 = F_2 ( & V_26 -> V_16 ) ;
V_23 = V_16 << 8 | V_10 ;
if ( F_2 ( & V_26 -> V_17 ) & 0x80 )
V_24 = 4 ;
else
V_24 = 1 ;
F_4 ( & V_26 -> V_13 , V_25 ) ;
V_9 = ( clock / V_24 ) / ( V_23 * 16 ) ;
if ( V_9 > ( clock / 16 ) )
V_9 = 9600 ;
return V_9 ;
}
void F_9 ( void )
{
if ( V_1 ) {
while ( ( F_10 ( & V_1 -> V_2 ) & V_3 ) == 0 )
;
}
}
void F_11 ( char V_4 )
{
if ( V_1 ) {
if ( V_4 == '\n' )
F_11 ( '\r' ) ;
F_9 () ;
F_12 ( V_4 , & V_1 -> V_5 ) ; F_13 () ;
}
}
void T_3 F_14 ( void )
{
V_1 = (struct V_12 T_1 * ) 0xf40003f8 ;
V_19 = F_11 ;
V_20 = F_9 ;
V_21 = NULL ;
V_22 = NULL ;
}
void F_15 ( void )
{
if ( V_1 ) {
while ( ( F_16 ( & V_1 -> V_2 ) & V_3 ) == 0 )
;
}
}
void F_17 ( char V_4 )
{
if ( V_1 ) {
if ( V_4 == '\n' )
F_17 ( '\r' ) ;
F_15 () ;
F_18 ( V_4 , & V_1 -> V_5 ) ; F_13 () ;
}
}
void F_19 ( void )
{
V_1 = (struct V_12 T_1 * ) 0xfcff03f8UL ;
V_19 = F_17 ;
V_20 = F_15 ;
V_21 = NULL ;
V_22 = NULL ;
}
static void F_20 ( void )
{
if ( V_1 ) {
while ( ( F_21 ( & V_1 -> V_2 ) & V_3 ) == 0 )
;
}
}
static void F_22 ( char V_4 )
{
if ( V_1 ) {
if ( V_4 == '\n' )
F_22 ( '\r' ) ;
F_20 () ;
F_23 ( V_4 , & V_1 -> V_5 ) ; F_13 () ;
}
}
static int F_24 ( void )
{
if ( V_1 ) {
while ( ( F_21 ( & V_1 -> V_2 ) & V_6 ) == 0 )
;
return F_21 ( & V_1 -> V_7 ) ;
}
return - 1 ;
}
void T_3 F_25 ( void )
{
V_1 =
(struct V_12 T_1 * ) V_27 ;
V_19 = F_22 ;
V_20 = F_20 ;
V_21 = F_24 ;
}
static void F_26 ( void )
{
if ( V_1 ) {
while ( ( F_10 ( & V_1 -> V_2 ) & V_3 ) == 0 )
;
}
}
static void F_27 ( char V_4 )
{
if ( V_1 ) {
if ( V_4 == '\n' )
F_27 ( '\r' ) ;
F_26 () ;
F_12 ( V_4 , & V_1 -> V_5 ) ; F_13 () ;
}
}
static int F_28 ( void )
{
if ( V_1 ) {
while ( ( F_10 ( & V_1 -> V_2 ) & V_6 ) == 0 )
;
return F_10 ( & V_1 -> V_7 ) ;
}
return - 1 ;
}
void T_3 F_29 ( void )
{
V_1 = (struct V_12 T_1 * )
V_28 ;
V_19 = F_27 ;
V_20 = F_26 ;
V_21 = F_28 ;
V_22 = NULL ;
}
static void F_30 ( void )
{
if ( V_1 ) {
while ( ( F_31 ( & V_1 -> V_2 ) & V_3 ) == 0 )
;
}
}
static void F_32 ( char V_4 )
{
if ( V_1 ) {
if ( V_4 == '\n' )
F_32 ( '\r' ) ;
F_30 () ;
F_33 ( V_4 , & V_1 -> V_5 ) ; F_13 () ;
}
}
static int F_34 ( void )
{
if ( V_1 ) {
while ( ( F_31 ( & V_1 -> V_2 ) & V_6 ) == 0 )
;
return F_31 ( & V_1 -> V_7 ) ;
}
return - 1 ;
}
static int F_35 ( void )
{
if ( V_1 )
if ( F_31 ( & V_1 -> V_2 ) & V_6 )
return F_31 ( & V_1 -> V_7 ) ;
return - 1 ;
}
void T_3 F_36 ( void )
{
V_1 = (struct V_12 T_1 * ) V_29 ;
F_7 ( V_1 , 57600 , 50000000 ) ;
V_19 = F_32 ;
V_20 = F_30 ;
V_21 = F_34 ;
V_22 = F_35 ;
}
