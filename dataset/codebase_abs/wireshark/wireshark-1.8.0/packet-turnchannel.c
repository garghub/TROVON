static int
F_1 ( T_1 * V_1 , T_2 * V_2 ,
T_3 * V_3 )
{
T_4 V_4 ;
T_5 V_5 ;
T_5 V_6 ;
T_6 * V_7 ;
T_3 * V_8 ;
V_4 = F_2 ( V_1 ) ;
if ( V_4 < V_9 ) {
return 0 ;
}
V_5 = F_3 ( V_1 , 0 ) ;
V_6 = F_3 ( V_1 , 2 ) ;
if ( ( V_5 < 0x4000 ) || ( V_5 > 0xFFFE ) ) {
return 0 ;
}
if ( V_4 != V_9 + V_6 ) {
return 0 ;
}
F_4 ( V_2 -> V_10 , V_11 , L_1 ) ;
if ( F_5 ( V_2 -> V_10 , V_12 ) )
F_6 ( V_2 -> V_10 , V_12 , L_2 , V_5 ) ;
V_7 = F_7 ( V_3 , V_13 , V_1 , 0 , - 1 , V_14 ) ;
V_8 = F_8 ( V_7 , V_15 ) ;
F_9 ( V_8 , V_16 , V_1 , 0 , 2 , V_5 ) ;
F_9 ( V_8 , V_17 , V_1 , 2 , 2 , V_6 ) ;
if ( V_4 > V_9 ) {
T_1 * V_18 ;
T_4 V_19 , V_20 ;
V_20 = F_10 ( V_1 , V_9 ) ;
V_19 = F_11 ( V_1 ,
V_9 ) ;
if ( V_6 < V_19 ) {
V_19 = V_6 ;
}
V_18 = F_12 ( V_1 , V_9 , V_20 ,
V_19 ) ;
if ( ! F_13 ( V_21 ,
V_18 , V_2 , V_3 ) ) {
F_14 ( V_22 , V_18 , V_2 , V_3 ) ;
}
}
return F_2 ( V_1 ) ;
}
static void
F_15 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
F_1 ( V_1 , V_2 , V_3 ) ;
}
static T_4
F_16 ( T_2 * V_2 V_23 , T_1 * V_1 , int V_24 )
{
return ( T_4 ) F_3 ( V_1 , V_24 + 2 ) + V_9 ;
}
static void
F_17 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
F_18 ( V_1 , V_2 , V_3 , TRUE , V_9 ,
F_16 , F_15 ) ;
}
static T_7
F_19 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 V_4 ;
T_5 V_5 ;
T_5 V_6 ;
V_4 = F_2 ( V_1 ) ;
if ( V_4 < V_9 ) {
return FALSE ;
}
V_5 = F_3 ( V_1 , 0 ) ;
V_6 = F_3 ( V_1 , 2 ) ;
if ( ( V_5 < 0x4000 ) || ( V_5 > 0xFFFE ) ) {
return FALSE ;
}
if ( V_4 != V_9 + V_6 ) {
return FALSE ;
}
return F_1 ( V_1 , V_2 , V_3 ) ;
}
void
F_20 ( void )
{
static T_8 V_25 [] = {
{ & V_16 ,
{ L_3 , L_4 , V_26 ,
V_27 , NULL , 0x0 , NULL , V_28 }
} ,
{ & V_17 ,
{ L_5 , L_6 , V_26 ,
V_29 , NULL , 0x0 , NULL , V_28 }
} ,
} ;
static T_9 * V_30 [] = {
& V_15 ,
} ;
V_13 = F_21 ( L_7 ,
L_8 , L_9 ) ;
F_22 ( L_9 , F_1 ,
V_13 ) ;
F_23 ( L_9 , & V_21 ) ;
F_24 ( V_13 , V_25 , F_25 ( V_25 ) ) ;
F_26 ( V_30 , F_25 ( V_30 ) ) ;
}
void
F_27 ( void )
{
T_10 V_31 ;
T_10 V_32 ;
V_31 = F_28 ( F_17 , V_13 ) ;
V_32 = F_29 ( L_9 ) ;
F_30 ( L_10 , V_31 ) ;
F_30 ( L_11 , V_32 ) ;
F_31 ( L_12 , F_19 , V_13 ) ;
F_31 ( L_13 , F_19 , V_13 ) ;
V_22 = F_29 ( L_14 ) ;
}
