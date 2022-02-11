static int
F_1 ( T_1 * V_1 , T_2 * V_2 ,
T_3 * V_3 , void * T_4 V_4 )
{
T_5 V_5 ;
T_6 V_6 ;
T_6 V_7 ;
T_7 * V_8 ;
T_3 * V_9 ;
V_5 = F_2 ( V_1 ) ;
if ( V_5 < V_10 ) {
return 0 ;
}
V_6 = F_3 ( V_1 , 0 ) ;
V_7 = F_3 ( V_1 , 2 ) ;
if ( ( V_6 < 0x4000 ) || ( V_6 > 0xFFFE ) ) {
return 0 ;
}
if ( V_5 != V_10 + V_7 ) {
return 0 ;
}
F_4 ( V_2 -> V_11 , V_12 , L_1 ) ;
if ( F_5 ( V_2 -> V_11 , V_13 ) )
F_6 ( V_2 -> V_11 , V_13 , L_2 , V_6 ) ;
V_8 = F_7 ( V_3 , V_14 , V_1 , 0 , - 1 , V_15 ) ;
V_9 = F_8 ( V_8 , V_16 ) ;
F_9 ( V_9 , V_17 , V_1 , 0 , 2 , V_6 ) ;
F_9 ( V_9 , V_18 , V_1 , 2 , 2 , V_7 ) ;
if ( V_5 > V_10 ) {
T_1 * V_19 ;
T_5 V_20 , V_21 ;
V_21 = F_10 ( V_1 , V_10 ) ;
V_20 = F_11 ( V_1 ,
V_10 ) ;
if ( V_7 < V_20 ) {
V_20 = V_7 ;
}
V_19 = F_12 ( V_1 , V_10 , V_21 ,
V_20 ) ;
if ( ! F_13 ( V_22 ,
V_19 , V_2 , V_3 , NULL ) ) {
F_14 ( V_23 , V_19 , V_2 , V_3 ) ;
}
}
return F_2 ( V_1 ) ;
}
static void
F_15 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
F_1 ( V_1 , V_2 , V_3 , NULL ) ;
}
static T_5
F_16 ( T_2 * V_2 V_4 , T_1 * V_1 , int V_24 )
{
return ( T_5 ) F_3 ( V_1 , V_24 + 2 ) + V_10 ;
}
static void
F_17 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
F_18 ( V_1 , V_2 , V_3 , TRUE , V_10 ,
F_16 , F_15 ) ;
}
static T_8
F_19 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_5 V_5 ;
T_6 V_6 ;
T_6 V_7 ;
V_5 = F_2 ( V_1 ) ;
if ( V_5 < V_10 ) {
return FALSE ;
}
V_6 = F_3 ( V_1 , 0 ) ;
V_7 = F_3 ( V_1 , 2 ) ;
if ( ( V_6 < 0x4000 ) || ( V_6 > 0xFFFE ) ) {
return FALSE ;
}
if ( V_5 != V_10 + V_7 ) {
return FALSE ;
}
return F_1 ( V_1 , V_2 , V_3 , NULL ) ;
}
void
F_20 ( void )
{
static T_9 V_25 [] = {
{ & V_17 ,
{ L_3 , L_4 , V_26 ,
V_27 , NULL , 0x0 , NULL , V_28 }
} ,
{ & V_18 ,
{ L_5 , L_6 , V_26 ,
V_29 , NULL , 0x0 , NULL , V_28 }
} ,
} ;
static T_10 * V_30 [] = {
& V_16 ,
} ;
V_14 = F_21 ( L_7 ,
L_8 , L_9 ) ;
F_22 ( L_9 , F_1 ,
V_14 ) ;
F_23 ( L_9 , & V_22 ) ;
F_24 ( V_14 , V_25 , F_25 ( V_25 ) ) ;
F_26 ( V_30 , F_25 ( V_30 ) ) ;
}
void
F_27 ( void )
{
T_11 V_31 ;
T_11 V_32 ;
V_31 = F_28 ( F_17 , V_14 ) ;
V_32 = F_29 ( L_9 ) ;
F_30 ( L_10 , V_31 ) ;
F_30 ( L_11 , V_32 ) ;
F_31 ( L_12 , F_19 , V_14 ) ;
V_23 = F_29 ( L_13 ) ;
}
