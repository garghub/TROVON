static const char * F_1 ( T_1 V_1 )
{
switch ( ( V_1 >> 16 ) & 0xff ) {
case 0x00 :
return L_1 ;
case 0x01 :
return L_2 ;
case 0x03 :
return L_3 ;
case 0x04 :
return L_4 ;
case 0x08 :
return L_5 ;
default:
return L_6 ;
}
}
static const char * F_2 ( T_1 V_1 )
{
switch ( ( V_1 >> 12 ) & 0xf ) {
case 0x01 :
return L_7 ;
case 0x02 :
return L_8 ;
case 0x03 :
return L_9 ;
case 0x04 :
return L_10 ;
default:
return L_6 ;
}
}
static T_2 F_3 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
char * V_6 )
{
return sprintf ( V_6 , L_11 , V_7 >> 24 ) ;
}
static T_2 F_4 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
char * V_6 )
{
return sprintf ( V_6 , L_12 , F_1 ( V_7 ) ) ;
}
static T_2 F_5 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
char * V_6 )
{
return sprintf ( V_6 , L_12 , F_2 ( V_7 ) ) ;
}
static T_2 F_6 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
char * V_6 )
{
return sprintf ( V_6 , L_11 , ( V_7 >> 4 ) & 0xFF ) ;
}
static int T_3 F_7 ( void )
{
static struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_2 * V_3 ;
T_1 V_16 ;
int V_17 ;
V_15 = F_8 ( NULL , V_18 ) ;
if ( ! V_15 )
return - V_19 ;
V_9 = F_9 ( V_15 ) ;
if ( F_10 ( V_9 ) )
return F_11 ( V_9 ) ;
V_17 = F_12 ( V_9 , V_20 ,
& V_16 ) ;
if ( V_17 )
return - V_19 ;
V_7 = V_16 ;
V_13 = F_13 ( sizeof( * V_13 ) , V_21 ) ;
if ( ! V_13 )
return - V_22 ;
V_13 -> V_23 = L_13 ;
V_13 -> V_24 = L_13 ;
V_13 -> V_25 = L_14 ;
V_11 = F_14 ( V_13 ) ;
if ( F_10 ( V_11 ) ) {
F_15 ( V_13 ) ;
return - V_19 ;
}
V_3 = F_16 ( V_11 ) ;
F_17 ( V_3 , & V_26 ) ;
F_17 ( V_3 , & V_27 ) ;
F_17 ( V_3 , & V_28 ) ;
F_17 ( V_3 , & V_29 ) ;
F_18 ( V_3 , L_15 ) ;
F_18 ( V_3 , L_16 , ( V_16 >> 24 ) ) ;
F_18 ( V_3 , L_17 , F_1 ( V_16 ) ) ;
F_18 ( V_3 , L_18 , F_2 ( V_16 ) ) ;
F_18 ( V_3 , L_19 , ( V_16 >> 4 ) & 0xFF ) ;
F_18 ( V_3 , L_20 , ( 'A' + ( V_16 & 0x03 ) ) ) ;
return 0 ;
}
