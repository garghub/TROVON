static int
F_1 ( T_1 * V_1 , T_2 * V_2 ,
T_3 * V_3 , void * T_4 V_4 )
{
T_5 V_5 ;
T_6 V_6 ;
T_6 V_7 ;
T_7 * V_8 ;
T_3 * V_9 ;
T_8 * V_10 ;
V_5 = F_2 ( V_1 ) ;
if ( V_5 < V_11 ) {
return 0 ;
}
V_6 = F_3 ( V_1 , 0 ) ;
V_7 = F_3 ( V_1 , 2 ) ;
if ( ( V_6 < 0x4000 ) || ( V_6 > 0xFFFE ) ) {
return 0 ;
}
if ( V_5 != V_11 + V_7 ) {
return 0 ;
}
F_4 ( V_2 -> V_12 , V_13 , L_1 ) ;
F_5 ( V_2 -> V_12 , V_14 , L_2 , V_6 ) ;
V_8 = F_6 ( V_3 , V_15 , V_1 , 0 , - 1 , V_16 ) ;
V_9 = F_7 ( V_8 , V_17 ) ;
F_8 ( V_9 , V_18 , V_1 , 0 , 2 , V_6 ) ;
F_8 ( V_9 , V_19 , V_1 , 2 , 2 , V_7 ) ;
if ( V_5 > V_11 ) {
T_1 * V_20 ;
T_5 V_21 , V_22 ;
V_22 = F_9 ( V_1 , V_11 ) ;
V_21 = F_10 ( V_1 ,
V_11 ) ;
if ( V_7 < V_21 ) {
V_21 = V_7 ;
}
V_20 = F_11 ( V_1 , V_11 , V_22 ,
V_21 ) ;
if ( ! F_12 ( V_23 ,
V_20 , V_2 , V_3 , & V_10 , NULL ) ) {
F_13 ( V_24 , V_20 , V_2 , V_3 ) ;
}
}
return F_2 ( V_1 ) ;
}
static T_5
F_14 ( T_2 * V_2 V_4 , T_1 * V_1 , int V_25 )
{
return ( T_5 ) F_3 ( V_1 , V_25 + 2 ) + V_11 ;
}
static int
F_15 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 )
{
F_16 ( V_1 , V_2 , V_3 , TRUE , V_11 ,
F_14 , F_1 , T_4 ) ;
return F_2 ( V_1 ) ;
}
static T_9
F_17 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_5 V_5 ;
T_6 V_6 ;
T_6 V_7 ;
V_5 = F_2 ( V_1 ) ;
if ( V_5 < V_11 ) {
return FALSE ;
}
V_6 = F_3 ( V_1 , 0 ) ;
V_7 = F_3 ( V_1 , 2 ) ;
if ( ( V_6 < 0x4000 ) || ( V_6 > 0xFFFE ) ) {
return FALSE ;
}
if ( V_5 != V_11 + V_7 ) {
return FALSE ;
}
return F_1 ( V_1 , V_2 , V_3 , NULL ) ;
}
void
F_18 ( void )
{
static T_10 V_26 [] = {
{ & V_18 ,
{ L_3 , L_4 , V_27 ,
V_28 , NULL , 0x0 , NULL , V_29 }
} ,
{ & V_19 ,
{ L_5 , L_6 , V_27 ,
V_30 , NULL , 0x0 , NULL , V_29 }
} ,
} ;
static T_11 * V_31 [] = {
& V_17 ,
} ;
V_15 = F_19 ( L_7 ,
L_8 , L_9 ) ;
F_20 ( L_9 , F_1 ,
V_15 ) ;
F_21 ( L_9 , & V_23 ) ;
F_22 ( V_15 , V_26 , F_23 ( V_26 ) ) ;
F_24 ( V_31 , F_23 ( V_31 ) ) ;
}
void
F_25 ( void )
{
T_12 V_32 ;
T_12 V_33 ;
V_32 = F_26 ( F_15 , V_15 ) ;
V_33 = F_27 ( L_9 ) ;
F_28 ( L_10 , V_32 ) ;
F_28 ( L_11 , V_33 ) ;
F_29 ( L_12 , F_17 , V_15 ) ;
V_24 = F_27 ( L_13 ) ;
}
