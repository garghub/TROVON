static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
int V_4 ;
int V_5 = - V_6 ;
F_2 () ;
V_4 = F_3 ( V_1 -> V_7 ) ;
if ( V_4 < V_8 ) {
if ( V_9 > 0 ) {
V_5 = - V_10 ;
} else {
V_9 ++ ;
V_5 = 0 ;
}
}
F_4 () ;
return V_5 ;
}
static int F_5 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
int V_4 ;
V_4 = F_3 ( V_1 -> V_7 ) ;
if ( V_4 < V_8 ) {
V_9 -- ;
}
return 0 ;
}
static long F_6 ( struct V_2 * V_3 , unsigned int V_11 , unsigned long V_12 )
{
unsigned int V_13 ;
static unsigned int V_14 = 0 ;
if ( V_11 & 0x01 ) {
if ( F_7 ( & V_13 , ( int * ) V_12 , sizeof( int ) ) ) {
return - V_15 ;
}
}
switch ( V_11 ) {
case V_16 :
V_14 = V_13 ;
break;
case V_17 :
F_8 ( ( unsigned char ) ( 0x0ff & V_13 ) , V_14 ) ;
break;
case V_18 :
if ( V_14 & 0x01 ) {
return - V_15 ;
}
F_9 ( ( unsigned short int ) ( 0x0ffff & V_13 ) , V_14 ) ;
break;
case V_19 :
if ( V_14 & 0x03 ) {
return - V_15 ;
}
F_10 ( V_13 , V_14 ) ;
break;
case V_20 :
V_13 = F_11 ( V_14 ) ;
break;
case V_21 :
if ( V_14 & 0x01 ) {
return - V_15 ;
}
V_13 = F_12 ( V_14 ) ;
break;
case V_22 :
if ( V_14 & 0x03 ) {
return - V_15 ;
}
V_13 = F_13 ( V_14 ) ;
break;
default:
return - V_15 ;
break;
}
if ( ( V_11 & 0x01 ) == 0 ) {
if ( F_14 ( ( int * ) V_12 , & V_13 , sizeof( int ) ) ) {
return - V_15 ;
}
}
return 0 ;
}
static int T_1 F_15 ( void )
{
int error ;
F_16 ( V_23 L_1 ) ;
V_9 = 0 ;
if ( ( error = F_17 ( & V_24 , 0 , V_8 , L_2 ) ) < 0 ) {
F_16 ( V_25
L_3 ,
error ) ;
return 1 ;
}
V_26 = F_18 () ;
V_26 -> V_27 = & V_28 ;
error = F_19 ( V_26 , V_24 , V_8 ) ;
if ( error ) {
F_16 ( V_25
L_4 , error ) ;
return 1 ;
}
return 0 ;
}
static void T_2 F_20 ( void )
{
F_21 ( V_26 ) ;
F_22 ( V_24 , V_8 ) ;
}
