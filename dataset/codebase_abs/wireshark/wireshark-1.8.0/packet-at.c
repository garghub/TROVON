static T_1 F_1 ( T_2 * V_1 )
{
T_3 V_2 , V_3 ;
T_4 V_4 ;
V_3 = F_2 ( V_1 ) ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
V_4 = F_3 ( V_1 , V_2 ) ;
if ( ! ( isprint ( V_4 ) || ( V_4 == 0x0a ) || ( V_4 == 0x0d ) ) )
return ( FALSE ) ;
}
return ( TRUE ) ;
}
static T_1 F_4 ( T_2 * V_1 , T_5 * V_5 , T_6 * V_6 )
{
const T_7 V_7 [ 2 ] = { 0x0d , 0x0a } ;
const T_7 V_8 [ 3 ] = { 0x0d , 0x0d , 0x0a } ;
const T_7 V_9 [ 2 ] = { 'A' , 'T' } ;
if ( ( ( F_5 ( V_1 , 0 , V_7 , sizeof( V_7 ) ) == 0 ) ||
( F_5 ( V_1 , 0 , V_8 , sizeof( V_8 ) ) == 0 ) ||
( F_5 ( V_1 , 0 , V_9 , sizeof( V_9 ) ) == 0 ) ) &&
F_1 ( V_1 ) ) {
F_6 ( V_1 , V_5 , V_6 ) ;
return ( TRUE ) ;
}
return ( FALSE ) ;
}
static void F_6 ( T_2 * V_1 , T_5 * V_5 , T_6 * V_6 )
{
T_8 * V_10 ;
T_6 * V_11 ;
T_3 V_3 ;
V_3 = F_7 ( V_1 ) ;
F_8 ( V_5 -> V_12 , V_13 , L_1 ) ;
F_9 ( V_5 -> V_12 , V_14 , NULL , L_2 ,
F_10 ( V_1 , 0 , V_3 ) ) ;
if ( V_6 ) {
V_10 = F_11 ( V_6 , V_15 , V_1 , 0 , - 1 , V_16 ) ;
V_11 = F_12 ( V_10 , V_17 ) ;
F_11 ( V_11 , V_18 , V_1 , 0 , V_3 , V_19 | V_16 ) ;
F_13 ( V_10 , L_3 , F_10 ( V_1 , 0 , V_3 ) ) ;
}
}
void
F_14 ( void )
{
static T_9 V_20 [] = {
{ & V_18 ,
{ L_4 , L_5 , V_21 , V_22 ,
NULL , 0x0 , NULL , V_23 } }
} ;
static T_3 * V_24 [] = {
& V_17
} ;
V_15 = F_15 ( L_4 , L_6 , L_7 ) ;
F_16 ( V_15 , V_20 , F_17 ( V_20 ) ) ;
F_18 ( V_24 , F_17 ( V_24 ) ) ;
F_19 ( L_7 , F_6 , V_15 ) ;
}
void
F_20 ( void )
{
F_21 ( L_8 , F_4 , V_15 ) ;
F_21 ( L_9 , F_4 , V_15 ) ;
}
