static T_1 F_1 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 , void * T_5 V_4 )
{
T_6 * V_5 = NULL ;
T_6 * V_6 = NULL ;
T_4 * V_7 = NULL ;
T_7 V_8 = 0 ;
T_8 V_9 ;
T_7 V_10 ;
if ( F_2 ( V_1 ) < 16 ) {
return FALSE ;
}
V_10 = F_3 ( V_1 , 0 ) ;
if ( V_10 != V_11 ) {
return FALSE ;
}
F_4 ( V_2 -> V_12 , V_13 , L_1 ) ;
F_5 ( V_2 -> V_12 , V_14 , L_2 , F_3 ( V_1 , 4 ) ) ;
if ( V_3 ) {
V_5 = F_6 ( V_3 , V_15 , V_1 , 0 , - 1 , V_16 ) ;
V_7 = F_7 ( V_5 , V_17 ) ;
F_6 ( V_7 , V_18 , V_1 , V_8 , 4 , V_19 ) ;
V_8 += 4 ;
F_6 ( V_7 , V_20 , V_1 , V_8 , 4 , V_19 ) ;
V_8 += 4 ;
V_9 . V_21 = F_3 ( V_1 , V_8 ) ;
V_6 = F_6 ( V_7 , V_22 , V_1 , V_8 , 4 , V_19 ) ;
F_8 ( V_6 ) ;
V_8 += 4 ;
V_9 . V_23 = F_3 ( V_1 , V_8 ) * 1000 ;
V_6 = F_6 ( V_7 , V_24 , V_1 , V_8 , 4 , V_19 ) ;
F_8 ( V_6 ) ;
V_8 += 4 ;
F_9 ( V_7 , V_25 , V_1 , V_8 - 8 , 8 , & V_9 ) ;
if ( F_10 ( V_1 , V_8 ) )
F_11 ( V_26 , F_12 ( V_1 , V_8 ) , V_2 ,
V_7 ) ;
}
return TRUE ;
}
void F_13 ( void )
{
static T_9 V_27 [] = {
{ & V_18 ,
{
L_3 , L_4 ,
V_28 , V_29 , NULL , 0x0 ,
L_5 , V_30
}
} ,
{ & V_20 ,
{
L_6 , L_7 ,
V_28 , V_31 , NULL , 0x0 ,
NULL , V_30
}
} ,
{ & V_22 ,
{
L_8 , L_9 ,
V_28 , V_31 , NULL , 0x0 ,
L_10 , V_30
}
} ,
{ & V_24 ,
{
L_11 , L_12 ,
V_28 , V_31 , NULL , 0x0 ,
L_13 , V_30
}
} ,
{ & V_25 ,
{
L_14 , L_15 ,
V_32 , V_33 , NULL , 0x0 ,
NULL , V_30
}
}
} ;
static T_10 * V_34 [] = {
& V_17
} ;
V_15 = F_14 ( L_16 , L_1 , L_17 ) ;
F_15 ( V_15 , V_27 , F_16 ( V_27 ) ) ;
F_17 ( V_34 , F_16 ( V_34 ) ) ;
}
void F_18 ( void )
{
F_19 ( L_18 , F_1 , V_15 ) ;
V_26 = F_20 ( L_19 ) ;
}
