static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_3 * V_4 = NULL ;
T_4 * V_5 = NULL ;
T_1 * V_6 = NULL ;
T_5 V_7 = 0 ;
if ( F_2 ( V_1 , 0 ) < 4 ) {
if ( V_3 )
F_3 ( V_3 , V_1 , 0 , - 1 ,
L_1 ) ;
return;
}
if ( F_4 ( V_1 , V_2 , V_3 ) )
return;
V_7 = F_5 ( V_1 , 2 ) ;
if ( V_3 ) {
V_5 = F_6 ( V_3 , V_8 ,
V_1 , 0 , 0 , TRUE ) ;
F_7 ( V_5 ) ;
V_5 = F_8 ( V_3 , V_9 ,
V_1 , 0 , 4 , V_10 ) ;
V_4 = F_9 ( V_5 , V_11 ) ;
if ( V_4 == NULL )
return;
F_10 ( V_4 ,
V_12 ,
V_1 , 2 , 2 , V_7 ,
L_2 ,
V_7 ) ;
}
V_6 = F_11 ( V_1 , 4 ) ;
{
T_6 V_13 = V_2 -> V_14 ;
F_12 ( V_15 , V_6 , V_2 , V_3 ) ;
V_2 -> V_14 = V_13 ;
}
}
static void
F_13 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_1 * V_6 = NULL ;
T_4 * V_5 = NULL ;
if ( V_3 ) {
V_5 = F_6 ( V_3 , V_16 , V_1 , 0 , 0 , TRUE ) ;
F_7 ( V_5 ) ;
}
V_6 = F_11 ( V_1 , 0 ) ;
{
T_6 V_13 = V_2 -> V_14 ;
F_12 ( V_15 , V_6 , V_2 , V_3 ) ;
V_2 -> V_14 = V_13 ;
}
}
static T_7
F_14 ( T_1 * V_1 V_17 )
{
const T_8 * V_18 = NULL ;
const T_8 * V_19 = NULL ;
if ( F_2 ( V_1 , 0 ) < 14 ) {
return FALSE ;
}
V_18 = F_15 ( V_1 , 0 ) ;
V_19 = F_15 ( V_1 , 6 ) ;
if ( V_18 && V_19 ) {
return TRUE ;
}
return FALSE ;
}
static void
F_16 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_9 V_20 = ( F_17 ( V_1 , 0 ) >> 4 ) & 0x0F ;
if ( F_14 ( V_1 ) ) {
F_12 ( V_21 , V_1 , V_2 , V_3 ) ;
}
if ( V_20 == 0 )
F_12 ( V_22 , V_1 , V_2 , V_3 ) ;
else
F_12 ( V_21 , V_1 , V_2 , V_3 ) ;
}
void
F_18 ( void )
{
static T_10 V_23 [] = {
{
& V_16 ,
{
L_3 ,
L_4 , V_24 ,
V_25 , NULL , 0x0 , NULL , V_26
}
} ,
{
& V_8 ,
{
L_5 ,
L_6 , V_24 ,
V_25 , NULL , 0x0 , NULL , V_26
}
} ,
{
& V_12 ,
{
L_7 ,
L_8 , V_27 ,
V_28 , NULL , 0x0 , NULL , V_26
}
}
} ;
static T_11 * V_29 [] = {
& V_11
} ;
V_9 =
F_19 ( L_9 ,
L_10 ,
L_11 ) ;
V_30 =
F_19 ( L_12 ,
L_12 ,
L_13 ) ;
V_31 =
F_19 ( L_14 ,
L_14 ,
L_15 ) ;
F_20 ( V_9 , V_23 , F_21 ( V_23 ) ) ;
F_22 ( V_29 , F_21 ( V_29 ) ) ;
F_23 ( L_16 , F_1 , V_9 ) ;
F_23 ( L_17 , F_13 ,
V_30 ) ;
F_23 ( L_18 , F_16 ,
V_31 ) ;
}
void
F_24 ( void )
{
T_12 V_32 ;
V_15 = F_25 ( L_19 ) ;
V_22 = F_25 ( L_16 ) ;
F_26 ( L_20 , V_33 , V_22 ) ;
V_21 = F_25 ( L_17 ) ;
F_26 ( L_20 , V_33 , V_21 ) ;
V_32 = F_25 ( L_18 ) ;
F_26 ( L_20 , V_33 , V_32 ) ;
}
