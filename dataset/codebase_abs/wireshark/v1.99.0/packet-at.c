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
static T_1 F_5 ( T_2 * V_1 , T_5 * V_5 , T_6 * V_6 , void * T_7 V_7 )
{
const T_8 V_8 [ 2 ] = { 0x0d , 0x0a } ;
const T_8 V_9 [ 3 ] = { 0x0d , 0x0d , 0x0a } ;
const T_8 V_10 [ 2 ] = { 'A' , 'T' } ;
if ( ( ( F_6 ( V_1 , 0 , V_8 , sizeof( V_8 ) ) == 0 ) ||
( F_6 ( V_1 , 0 , V_9 , sizeof( V_9 ) ) == 0 ) ||
( F_6 ( V_1 , 0 , V_10 , sizeof( V_10 ) ) == 0 ) ) &&
F_1 ( V_1 ) ) {
F_7 ( V_1 , V_5 , V_6 ) ;
return ( TRUE ) ;
}
return ( FALSE ) ;
}
static void F_7 ( T_2 * V_1 , T_5 * V_5 , T_6 * V_6 )
{
T_9 * V_11 ;
T_6 * V_12 ;
T_3 V_3 ;
V_3 = F_8 ( V_1 ) ;
F_9 ( V_5 -> V_13 , V_14 , L_1 , L_2 ) ;
F_10 ( V_5 -> V_13 , V_15 , NULL , L_3 ,
F_11 ( V_1 , 0 , V_3 ) ) ;
if ( V_6 ) {
V_11 = F_12 ( V_6 , V_16 , V_1 , 0 , - 1 , V_17 ) ;
V_12 = F_13 ( V_11 , V_18 ) ;
F_12 ( V_12 , V_19 , V_1 , 0 , V_3 , V_20 | V_17 ) ;
F_14 ( V_11 , L_4 , F_11 ( V_1 , 0 , V_3 ) ) ;
}
}
void
F_15 ( void )
{
static T_10 V_21 [] = {
{ & V_19 ,
{ L_5 , L_6 , V_22 , V_23 ,
NULL , 0x0 , NULL , V_24 } }
} ;
static T_3 * V_25 [] = {
& V_18
} ;
V_16 = F_16 ( L_5 , L_2 , L_7 ) ;
F_17 ( V_16 , V_21 , F_18 ( V_21 ) ) ;
F_19 ( V_25 , F_18 ( V_25 ) ) ;
F_20 ( L_7 , F_7 , V_16 ) ;
}
void
F_21 ( void )
{
F_22 ( L_8 , F_5 , V_16 ) ;
F_22 ( L_9 , F_5 , V_16 ) ;
}
