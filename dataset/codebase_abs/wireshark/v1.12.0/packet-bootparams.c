static int
F_1 ( T_1 * V_1 , int V_2 , T_2 * V_3 , int V_4 )
{
T_3 type ;
T_3 V_5 ;
type = F_2 ( V_1 , V_2 ) ;
V_2 = F_3 ( V_1 , V_3 , V_6 , V_2 ) ;
switch( type ) {
case 1 :
V_5 = ( ( F_4 ( V_1 , V_2 + 3 ) & 0xff ) << 24 )
| ( ( F_4 ( V_1 , V_2 + 7 ) & 0xff ) << 16 )
| ( ( F_4 ( V_1 , V_2 + 11 ) & 0xff ) << 8 )
| ( ( F_4 ( V_1 , V_2 + 15 ) & 0xff ) ) ;
F_5 ( V_3 , V_4 , V_1 ,
V_2 , 16 , F_6 ( V_5 ) ) ;
V_2 += 16 ;
break;
default:
break;
}
return V_2 ;
}
static int
F_7 ( T_1 * V_1 , int V_2 , T_4 * T_5 V_7 , T_2 * V_3 , void * T_6 V_7 )
{
if ( V_3 )
{
V_2 = F_8 ( V_1 , V_3 , V_8 , V_2 , NULL ) ;
V_2 = F_8 ( V_1 , V_3 , V_9 , V_2 , NULL ) ;
}
return V_2 ;
}
static int
F_9 ( T_1 * V_1 , int V_2 , T_4 * T_5 V_7 , T_2 * V_3 , void * T_6 V_7 )
{
if ( V_3 )
{
V_2 = F_8 ( V_1 , V_3 , V_8 , V_2 , NULL ) ;
V_2 = F_1 ( V_1 , V_2 , V_3 , V_10 ) ;
V_2 = F_8 ( V_1 , V_3 , V_11 , V_2 , NULL ) ;
}
return V_2 ;
}
static int
F_10 ( T_1 * V_1 , int V_2 , T_4 * T_5 V_7 , T_2 * V_3 , void * T_6 V_7 )
{
if ( V_3 )
{
V_2 = F_1 ( V_1 , V_2 , V_3 , V_10 ) ;
}
return V_2 ;
}
static int
F_11 ( T_1 * V_1 , int V_2 , T_4 * T_5 V_7 , T_2 * V_3 , void * T_6 V_7 )
{
if ( V_3 )
{
V_2 = F_8 ( V_1 , V_3 , V_8 , V_2 , NULL ) ;
V_2 = F_8 ( V_1 , V_3 , V_12 , V_2 , NULL ) ;
V_2 = F_1 ( V_1 , V_2 , V_3 , V_13 ) ;
}
return V_2 ;
}
void
F_12 ( void )
{
static T_7 V_14 [] = {
{ & V_15 , {
L_1 , L_2 , V_16 , V_17 ,
F_13 ( V_18 ) , 0 , NULL , V_19 } } ,
{ & V_8 , {
L_3 , L_4 , V_20 , V_21 ,
NULL , 0 , NULL , V_19 } } ,
{ & V_12 , {
L_5 , L_6 , V_20 , V_21 ,
NULL , 0 , NULL , V_19 } } ,
{ & V_9 , {
L_7 , L_8 , V_20 , V_21 ,
NULL , 0 , NULL , V_19 } } ,
{ & V_11 , {
L_9 , L_10 , V_20 , V_21 ,
NULL , 0 , NULL , V_19 } } ,
{ & V_10 , {
L_11 , L_12 , V_22 , V_21 ,
NULL , 0 , L_13 , V_19 } } ,
{ & V_13 , {
L_14 , L_15 , V_22 , V_21 ,
NULL , 0 , NULL , V_19 } } ,
{ & V_6 , {
L_16 , L_17 , V_16 , V_17 ,
F_13 ( V_23 ) , 0 , NULL , V_19 } } ,
} ;
static T_8 * V_24 [] = {
& V_25 ,
} ;
V_26 = F_14 ( L_18 ,
L_19 , L_20 ) ;
F_15 ( V_26 , V_14 , F_16 ( V_14 ) ) ;
F_17 ( V_24 , F_16 ( V_24 ) ) ;
}
void
F_18 ( void )
{
F_19 ( V_26 , V_27 , V_25 ) ;
F_20 ( V_27 , 1 , V_28 , V_15 ) ;
}
