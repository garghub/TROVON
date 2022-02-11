static unsigned int T_1 F_1 ( T_2 V_1 )
{
void T_3 * V_2 = F_2 ( V_1 , 4 ) ;
unsigned int V_3 ;
if ( ! V_2 )
return 0 ;
V_3 = F_3 ( V_2 ) ;
F_4 ( V_2 ) ;
return V_3 ;
}
static void F_5 ( unsigned int V_3 )
{
unsigned int V_4 = V_5 . V_6 ;
F_6 ( L_1 , V_5 . V_7 ) ;
if ( V_4 == 0x01 )
F_7 ( L_2 ) ;
else if ( V_4 >= 0xA0 )
F_7 ( L_3 , ( V_4 >> 4 ) - 0xA + 1 , V_4 & 0xf ) ;
else
F_7 ( L_4 ) ;
F_7 ( L_5 , V_3 ) ;
}
static unsigned int V_7 ( unsigned int V_3 )
{
return ( V_3 >> 8 ) & 0xffff ;
}
static void T_1 F_8 ( void )
{
unsigned int V_8 = F_9 () ;
unsigned int V_3 = 0 ;
T_2 V_1 = 0 ;
switch ( V_8 ) {
case 0x410fc090 :
case 0x411fc091 :
V_1 = 0x9001FFF4 ;
break;
case 0x412fc091 :
V_3 = F_1 ( 0x9001DBF4 ) ;
if ( V_7 ( V_3 ) == 0x8500 ||
V_7 ( V_3 ) == 0x8520 )
break;
V_1 = 0x9001FFF4 ;
break;
case 0x413fc090 :
V_1 = 0xFFFFDBF4 ;
break;
}
if ( V_1 )
V_3 = F_1 ( V_1 ) ;
if ( ! V_3 ) {
F_10 ( L_6 ) ;
F_11 () ;
}
V_5 . V_9 = V_3 >> 24 ;
V_5 . V_7 = V_7 ( V_3 ) ;
V_5 . V_6 = V_3 & 0xff ;
F_5 ( V_3 ) ;
}
static const char * T_1 F_12 ( void )
{
return F_13 ( V_10 , L_7 , V_5 . V_7 ) ;
}
static const char * T_1 F_14 ( void )
{
return F_13 ( V_10 , L_8 ) ;
}
static const char * T_1 F_15 ( void )
{
unsigned int V_4 = V_5 . V_6 ;
if ( V_4 == 0x01 )
return F_13 ( V_10 , L_9 , L_10 ) ;
else if ( V_4 >= 0xA0 )
return F_13 ( V_10 , L_11 ,
( V_4 >> 4 ) - 0xA + 1 , V_4 & 0xf ) ;
return F_13 ( V_10 , L_9 , L_4 ) ;
}
static T_4 F_16 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
char * V_15 )
{
if ( V_5 . V_9 == 0x00 )
return sprintf ( V_15 , L_12 ) ;
return sprintf ( V_15 , L_13 , V_5 . V_9 ) ;
}
static const char * F_17 ( struct V_16 * V_17 )
{
void T_3 * V_18 ;
void T_3 * V_19 ;
const char * V_20 ;
V_18 = F_18 ( V_17 , 0 ) ;
if ( ! V_18 )
return NULL ;
V_19 = V_18 + 0x1fc0 ;
F_19 ( V_19 , 0x14 ) ;
V_20 = F_13 ( V_10 , L_14 ,
F_3 ( ( V_21 * ) V_19 + 0 ) ,
F_3 ( ( V_21 * ) V_19 + 1 ) , F_3 ( ( V_21 * ) V_19 + 2 ) ,
F_3 ( ( V_21 * ) V_19 + 3 ) , F_3 ( ( V_21 * ) V_19 + 4 ) ) ;
F_4 ( V_18 ) ;
return V_20 ;
}
static void T_1 F_20 ( struct V_22 * V_23 ,
struct V_16 * V_17 )
{
V_23 -> V_24 = F_17 ( V_17 ) ;
V_23 -> V_25 = F_12 () ;
V_23 -> V_26 = F_14 () ;
V_23 -> V_6 = F_15 () ;
}
static int T_1 F_21 ( void )
{
struct V_11 * V_27 ;
struct V_28 * V_29 ;
struct V_22 * V_23 ;
struct V_16 * V_17 ;
V_17 = F_22 ( NULL , NULL , L_15 ) ;
if ( ! V_17 )
return 0 ;
F_8 () ;
V_23 = F_23 ( sizeof( * V_23 ) , V_10 ) ;
if ( ! V_23 )
return - V_30 ;
F_20 ( V_23 , V_17 ) ;
V_29 = F_24 ( V_23 ) ;
if ( F_25 ( V_29 ) ) {
F_26 ( V_23 ) ;
return F_27 ( V_29 ) ;
}
V_27 = F_28 ( V_29 ) ;
F_29 ( V_27 , & V_31 ) ;
return 0 ;
}
