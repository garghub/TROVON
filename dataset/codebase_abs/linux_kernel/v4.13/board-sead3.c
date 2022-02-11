static T_1 bool F_1 ( void )
{
T_2 V_1 ;
V_1 = F_2 ( ( void * ) V_2 ) ;
return ( V_1 & V_3 ) == V_4 ;
}
static T_1 int F_3 ( void * V_5 )
{
return F_4 ( V_5 , V_6 ) ;
}
static T_1 int F_5 ( void * V_5 )
{
const unsigned int V_7 = 2 ;
const unsigned int V_8 = 4 ;
const unsigned int V_9 = 6 ;
int V_10 , V_11 , V_12 , V_13 , V_14 , V_15 ;
T_2 V_16 , V_17 ;
V_16 = F_2 ( ( T_2 * ) V_18 ) ;
if ( V_16 & V_19 )
return 0 ;
V_10 = F_6 ( V_5 , - 1 , L_1 ) ;
if ( V_10 < 0 ) {
F_7 ( L_2 , V_10 ) ;
return V_10 ;
}
V_15 = F_8 ( V_5 , V_10 ) ;
if ( V_15 ) {
F_7 ( L_3 ) ;
return V_15 ;
}
V_11 = F_6 ( V_5 , - 1 ,
L_4 ) ;
if ( V_11 < 0 ) {
F_7 ( L_5 , V_11 ) ;
return V_11 ;
}
V_17 = F_9 ( V_5 , V_11 ) ;
if ( ! V_17 ) {
F_7 ( L_6 ) ;
return - V_20 ;
}
V_12 = F_6 ( V_5 , - 1 , L_7 ) ;
while ( V_12 >= 0 ) {
V_15 = F_10 ( V_5 , V_12 , L_8 ,
V_17 ) ;
if ( V_15 ) {
F_11 ( L_9 ,
V_15 ) ;
return V_15 ;
}
V_15 = F_10 ( V_5 , V_12 , L_10 ,
V_8 ) ;
if ( V_15 ) {
F_7 ( L_11 ,
V_15 ) ;
return V_15 ;
}
V_12 = F_6 ( V_5 , V_12 ,
L_7 ) ;
}
if ( V_12 != - V_21 ) {
F_7 ( L_12 , V_12 ) ;
return V_12 ;
}
V_13 = F_6 ( V_5 , - 1 , L_13 ) ;
if ( V_13 < 0 ) {
F_7 ( L_14 , V_13 ) ;
return V_13 ;
}
V_15 = F_10 ( V_5 , V_13 , L_8 , V_17 ) ;
if ( V_15 ) {
F_7 ( L_15 , V_15 ) ;
return V_15 ;
}
V_15 = F_10 ( V_5 , V_13 , L_10 , V_9 ) ;
if ( V_15 ) {
F_7 ( L_16 , V_15 ) ;
return V_15 ;
}
V_14 = F_6 ( V_5 , - 1 , L_17 ) ;
if ( V_14 < 0 ) {
F_7 ( L_18 , V_14 ) ;
return V_14 ;
}
V_15 = F_10 ( V_5 , V_14 , L_8 , V_17 ) ;
if ( V_15 ) {
F_7 ( L_19 , V_15 ) ;
return V_15 ;
}
V_15 = F_10 ( V_5 , V_14 , L_10 , V_7 ) ;
if ( V_15 ) {
F_7 ( L_20 , V_15 ) ;
return V_15 ;
}
return 0 ;
}
static T_1 const void * F_12 ( const void * V_5 ,
const void * V_22 )
{
static unsigned char V_23 [ 16 << 10 ] V_24 ;
int V_15 ;
if ( F_13 ( V_5 ) )
F_14 ( L_21 ) ;
F_15 ( F_16 ( V_5 , 0 , L_22 ) ) ;
F_17 () ;
V_15 = F_18 ( V_23 , sizeof( V_23 ) ,
V_5 , V_25 ) ;
if ( V_15 )
F_14 ( L_23 , V_15 ) ;
return V_23 ;
}
static T_1 unsigned int F_19 ( void )
{
void T_3 * V_26 = ( void T_3 * ) 0xbf000410 ;
unsigned int V_27 , V_28 , V_29 = 0 ;
unsigned long V_30 ;
F_20 ( V_30 ) ;
V_28 = F_21 ( V_26 ) & 0x2 ;
while ( ( F_21 ( V_26 ) & 0x2 ) == V_28 )
;
V_28 = V_28 ^ 0x2 ;
F_22 ( 0 ) ;
while ( V_29 < 100 ) {
while ( ( F_21 ( V_26 ) & 0x2 ) == V_28 )
;
V_28 = V_28 ^ 0x2 ;
V_29 ++ ;
}
V_27 = F_23 () ;
F_24 ( V_30 ) ;
return V_27 ;
}
