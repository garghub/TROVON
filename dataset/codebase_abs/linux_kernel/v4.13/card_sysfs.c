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
T_2 V_18 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_18 = F_6 ( V_7 , V_19 ) ;
return sprintf ( V_5 , L_7 , V_18 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
T_2 V_20 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_20 = F_6 ( V_7 , V_21 ) ;
return sprintf ( V_5 , L_7 , V_20 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
T_2 V_20 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_20 = F_6 ( V_7 , V_22 ) ;
return sprintf ( V_5 , L_7 , V_20 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
T_2 V_23 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_23 = F_14 ( V_7 ) ;
return sprintf ( V_5 , L_8 , V_23 ) ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
int V_24 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_24 = F_6 ( V_7 , V_25 ) & 0x1 ;
return sprintf ( V_5 , L_9 , V_24 ) ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
int V_26 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
switch ( ( V_7 -> V_27 & 0xc ) >> 2 ) {
case 0x2 :
V_26 = 0 ;
break;
case 0x3 :
V_26 = 1 ;
break;
default:
V_26 = - 1 ;
break;
}
return sprintf ( V_5 , L_9 , V_26 ) ;
}
static T_1 F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_4 V_28 )
{
int V_29 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( F_18 ( V_5 , 0 , & V_29 ) < 0 )
return - V_30 ;
switch ( V_29 ) {
case 0x0 :
V_7 -> V_27 = 0x78 ;
break;
case 0x1 :
V_7 -> V_27 = 0x7c ;
break;
default:
return - V_30 ;
}
F_19 ( V_7 , V_31 , V_7 -> V_27 ) ;
return V_28 ;
}
static T_1 F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_4 V_28 )
{
int V_32 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( F_18 ( V_5 , 0 , & V_32 ) < 0 )
return - V_30 ;
if ( V_32 == 0x1 ) {
if ( V_7 -> V_10 == V_33 ||
V_7 -> V_10 == V_34 )
V_7 -> V_10 = V_35 ;
else
return - V_36 ;
} else {
return - V_30 ;
}
return V_28 ;
}
static T_5 F_21 ( struct V_37 * V_38 ,
struct V_39 * V_4 , int V_40 )
{
unsigned int V_41 ;
struct V_1 * V_2 = F_22 ( V_38 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_5 V_42 = V_4 -> V_42 ;
if ( F_23 ( V_7 ) )
return V_42 ;
for ( V_41 = 0 ; V_43 [ V_41 ] != NULL ; V_41 ++ )
if ( V_43 [ V_41 ] == V_4 )
return V_42 ;
return 0 ;
}
