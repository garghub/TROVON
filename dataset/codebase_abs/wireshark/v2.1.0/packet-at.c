static T_1 F_1 ( T_2 * V_1 )
{
T_3 V_2 , V_3 ;
T_4 V_4 ;
V_3 = F_2 ( V_1 ) ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
V_4 = F_3 ( V_1 , V_2 ) ;
if ( ! ( F_4 ( V_4 ) || ( V_4 == 0x0a ) || ( V_4 == 0x0d ) ) )
return ( FALSE ) ;
}
return ( TRUE ) ;
}
static int F_5 ( T_2 * V_1 , T_5 * V_5 , T_6 * V_6 , void * T_7 V_7 )
{
T_8 * V_8 ;
T_6 * V_9 ;
T_9 * string ;
string = F_6 ( V_1 , 0 , F_2 ( V_1 ) ) ;
F_7 ( V_5 -> V_10 , V_11 , L_1 , L_2 ) ;
F_8 ( V_5 -> V_10 , V_12 , NULL , L_3 , string ) ;
V_8 = F_9 ( V_6 , V_13 , V_1 , 0 , - 1 , V_14 ) ;
F_10 ( V_8 , L_4 , string ) ;
V_9 = F_11 ( V_8 , V_15 ) ;
F_9 ( V_9 , V_16 , V_1 , 0 , F_12 ( V_1 ) , V_17 | V_14 ) ;
return F_2 ( V_1 ) ;
}
static T_1 F_13 ( T_2 * V_1 , T_5 * V_5 , T_6 * V_6 , void * T_7 )
{
const T_9 V_18 [ 2 ] = { 0x0d , 0x0a } ;
const T_9 V_19 [ 3 ] = { 0x0d , 0x0d , 0x0a } ;
const T_9 V_20 [ 2 ] = { 'A' , 'T' } ;
if ( ( ( F_14 ( V_1 , 0 , V_18 , sizeof( V_18 ) ) == 0 ) ||
( F_14 ( V_1 , 0 , V_19 , sizeof( V_19 ) ) == 0 ) ||
( F_14 ( V_1 , 0 , V_20 , sizeof( V_20 ) ) == 0 ) ) &&
F_1 ( V_1 ) ) {
F_5 ( V_1 , V_5 , V_6 , T_7 ) ;
return ( TRUE ) ;
}
return ( FALSE ) ;
}
void
F_15 ( void )
{
static T_10 V_21 [] = {
{ & V_16 ,
{ L_5 , L_6 , V_22 , V_23 ,
NULL , 0x0 , NULL , V_24 } }
} ;
static T_3 * V_25 [] = {
& V_15
} ;
V_13 = F_16 ( L_5 , L_2 , L_7 ) ;
F_17 ( V_13 , V_21 , F_18 ( V_21 ) ) ;
F_19 ( V_25 , F_18 ( V_25 ) ) ;
F_20 ( L_7 , F_5 , V_13 ) ;
}
void
F_21 ( void )
{
F_22 ( L_8 , F_13 , L_9 , L_10 , V_13 , V_26 ) ;
F_22 ( L_11 , F_13 , L_12 , L_13 , V_13 , V_26 ) ;
}
