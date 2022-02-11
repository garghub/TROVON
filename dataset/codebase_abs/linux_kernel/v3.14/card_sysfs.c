static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
const char * V_8 [ V_9 ] = { L_1 , L_2 , L_3 } ;
return sprintf ( V_5 , L_4 , V_8 [ V_7 -> V_10 ] ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
char V_11 [ 5 ] ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_4 ( V_7 , V_11 , sizeof( V_11 ) ) ;
return sprintf ( V_5 , L_4 , V_11 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
T_2 V_12 , V_13 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_12 = F_6 ( V_7 , V_14 ) ;
V_13 = F_6 ( V_7 , V_15 ) ;
return sprintf ( V_5 , L_5 , V_12 , V_13 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
T_3 V_16 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_16 = F_8 ( V_7 ) ;
return sprintf ( V_5 , L_4 , ( V_16 >= F_9 ( V_17 ) ) ?
L_6 : V_17 [ V_16 ] ) ;
}
static T_1 F_10 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
return sprintf ( V_5 , L_4 , V_18 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
T_2 V_19 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_19 = F_6 ( V_7 , V_20 ) ;
return sprintf ( V_5 , L_7 , V_19 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
T_2 V_21 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_21 = F_6 ( V_7 , V_22 ) ;
return sprintf ( V_5 , L_7 , V_21 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
T_2 V_21 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_21 = F_6 ( V_7 , V_23 ) ;
return sprintf ( V_5 , L_7 , V_21 ) ;
}
static T_1 F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
T_2 V_24 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_24 = F_15 ( V_7 ) ;
return sprintf ( V_5 , L_8 , V_24 ) ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
int V_25 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_25 = F_6 ( V_7 , V_26 ) & 0x1 ;
return sprintf ( V_5 , L_9 , V_25 ) ;
}
static T_1 F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
int V_27 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
switch ( ( V_7 -> V_28 & 0xc ) >> 2 ) {
case 0x2 :
V_27 = 0 ;
break;
case 0x3 :
V_27 = 1 ;
break;
default:
V_27 = - 1 ;
break;
}
return sprintf ( V_5 , L_9 , V_27 ) ;
}
static T_1 F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_4 V_29 )
{
int V_30 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( F_19 ( V_5 , 0 , & V_30 ) < 0 )
return - V_31 ;
switch ( V_30 ) {
case 0x0 :
V_7 -> V_28 = 0x78 ;
break;
case 0x1 :
V_7 -> V_28 = 0x7c ;
break;
default:
return - V_31 ;
}
F_20 ( V_7 , V_32 , V_7 -> V_28 ) ;
return V_29 ;
}
static T_5 F_21 ( struct V_33 * V_34 ,
struct V_35 * V_4 , int V_36 )
{
unsigned int V_37 ;
struct V_1 * V_2 = F_22 ( V_34 , struct V_1 , V_34 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_5 V_38 = V_4 -> V_38 ;
if ( F_23 ( V_7 ) )
return V_38 ;
for ( V_37 = 0 ; V_39 [ V_37 ] != NULL ; V_37 ++ )
if ( V_39 [ V_37 ] == V_4 )
return V_38 ;
return 0 ;
}
