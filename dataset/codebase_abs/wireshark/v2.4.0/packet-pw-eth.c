static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_1 * V_5 ;
T_5 V_6 ;
if ( F_2 ( V_1 , 0 ) < 4 ) {
return 0 ;
}
if ( F_3 ( V_1 , V_2 , V_3 ) )
return F_4 ( V_1 ) ;
V_6 = F_5 ( V_1 , 2 ) ;
if ( V_3 ) {
T_3 * V_7 ;
T_6 * V_8 ;
V_8 = F_6 ( V_3 , V_9 ,
V_1 , 0 , 0 , TRUE ) ;
F_7 ( V_8 ) ;
V_8 = F_8 ( V_3 , V_10 ,
V_1 , 0 , 4 , V_11 ) ;
V_7 = F_9 ( V_8 , V_12 ) ;
F_10 ( V_7 ,
V_13 ,
V_1 , 2 , 2 , V_6 ,
L_1 ,
V_6 ) ;
}
V_5 = F_11 ( V_1 , 4 ) ;
{
F_12 ( V_14 , V_5 , V_2 , V_3 ) ;
}
return F_4 ( V_1 ) ;
}
static int
F_13 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_1 * V_5 ;
if ( V_3 ) {
T_6 * V_8 ;
V_8 = F_6 ( V_3 , V_15 , V_1 , 0 , 0 , TRUE ) ;
F_7 ( V_8 ) ;
}
V_5 = F_11 ( V_1 , 0 ) ;
F_12 ( V_14 , V_5 , V_2 , V_3 ) ;
return F_4 ( V_1 ) ;
}
static T_7
F_14 ( T_1 * V_1 V_4 )
{
const T_8 * V_16 ;
const T_8 * V_17 ;
if ( F_2 ( V_1 , 0 ) < 14 ) {
return FALSE ;
}
V_16 = F_15 ( V_1 , 0 ) ;
V_17 = F_15 ( V_1 , 6 ) ;
if ( V_16 && V_17 ) {
return TRUE ;
}
return FALSE ;
}
static int
F_16 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_9 V_18 = ( F_17 ( V_1 , 0 ) >> 4 ) & 0x0F ;
if ( F_14 ( V_1 ) )
F_12 ( V_19 , V_1 , V_2 , V_3 ) ;
else if ( V_18 == 0 )
F_12 ( V_20 , V_1 , V_2 , V_3 ) ;
else
F_12 ( V_19 , V_1 , V_2 , V_3 ) ;
return F_4 ( V_1 ) ;
}
void
F_18 ( void )
{
static T_10 V_21 [] = {
{
& V_15 ,
{
L_2 ,
L_3 , V_22 ,
V_23 , NULL , 0x0 , NULL , V_24
}
} ,
{
& V_9 ,
{
L_4 ,
L_5 , V_22 ,
V_23 , NULL , 0x0 , NULL , V_24
}
} ,
{
& V_13 ,
{
L_6 ,
L_7 , V_25 ,
V_26 , NULL , 0x0 , NULL , V_24
}
}
} ;
static T_11 * V_27 [] = {
& V_12
} ;
V_10 =
F_19 ( L_8 ,
L_9 ,
L_10 ) ;
V_28 =
F_19 ( L_11 ,
L_11 ,
L_12 ) ;
V_29 =
F_19 ( L_13 ,
L_13 ,
L_14 ) ;
F_20 ( V_10 , V_21 , F_21 ( V_21 ) ) ;
F_22 ( V_27 , F_21 ( V_27 ) ) ;
V_20 = F_23 ( L_15 , F_1 , V_10 ) ;
V_19 = F_23 ( L_16 , F_13 , V_28 ) ;
V_30 = F_23 ( L_17 , F_16 ,
V_29 ) ;
}
void
F_24 ( void )
{
V_14 = F_25 ( L_18 , V_10 ) ;
F_26 ( L_19 , V_20 ) ;
F_26 ( L_19 , V_19 ) ;
F_26 ( L_19 , V_30 ) ;
}
