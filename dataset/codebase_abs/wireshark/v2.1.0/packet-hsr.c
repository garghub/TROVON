static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_5 * V_5 ;
T_3 * V_6 ;
T_1 * V_7 ;
T_6 V_8 ;
T_6 V_9 , V_10 ;
F_2 ( V_2 -> V_11 , V_12 , L_1 ) ;
F_2 ( V_2 -> V_11 , V_13 , L_2 ) ;
V_5 = F_3 ( V_3 , V_14 , V_1 , 0 , V_15 , V_16 ) ;
V_6 = F_4 ( V_5 , V_17 ) ;
F_3 ( V_6 , V_18 ,
V_1 , V_19 , V_20 , V_21 ) ;
F_3 ( V_6 , V_22 ,
V_1 , V_19 , V_20 , V_21 ) ;
F_3 ( V_6 , V_23 ,
V_1 , V_19 , V_20 , V_21 ) ;
V_9 = F_5 ( V_1 , V_19 ) & 0x0fff ;
V_10 = F_6 ( V_1 , 0 ) ;
if ( V_9 == V_10 ) {
F_7 ( V_6 , V_24 ,
V_1 , V_19 , V_20 , V_9 ,
L_3 , V_9 ) ;
} else {
F_7 ( V_6 , V_24 ,
V_1 , V_19 , V_20 , V_9 ,
L_4 , V_9 , V_10 ) ;
}
F_3 ( V_6 , V_25 ,
V_1 , V_26 , V_27 , V_21 ) ;
F_3 ( V_6 , V_28 ,
V_1 , V_15 , 2 , V_21 ) ;
V_7 = F_8 ( V_1 , V_15 + 2 ) ;
V_8 = F_5 ( V_1 , V_15 ) ;
if ( ! F_9 ( V_29 , V_8 , V_7 , V_2 , V_3 ) )
F_10 ( V_7 , V_2 , V_6 ) ;
return F_11 ( V_1 ) ;
}
void F_12 ( void )
{
static T_7 V_30 [] = {
{ & V_18 ,
{ L_5 , L_6 ,
V_31 , V_32 , NULL , 0xf000 ,
NULL , V_33 }
} ,
{ & V_22 ,
{ L_7 , L_8 ,
V_31 , V_32 , NULL , 0xe000 ,
NULL , V_33 }
} ,
{ & V_23 ,
{ L_9 , L_10 ,
V_31 , V_32 , F_13 ( V_34 ) , 0x1000 ,
NULL , V_33 }
} ,
{ & V_24 ,
{ L_11 , L_12 ,
V_31 , V_32 , NULL , 0x0fff ,
NULL , V_33 }
} ,
{ & V_25 ,
{ L_13 , L_14 ,
V_31 , V_32 , NULL , 0x00 ,
NULL , V_33 }
} ,
{ & V_28 ,
{ L_15 , L_16 ,
V_31 , V_35 , F_13 ( V_36 ) , 0x00 ,
NULL , V_33 }
}
} ;
static T_8 * V_37 [] = {
& V_17 ,
} ;
V_14 = F_14 ( L_17 ,
L_1 , L_18 ) ;
F_15 ( V_14 , V_30 , F_16 ( V_30 ) ) ;
F_17 ( V_37 , F_16 ( V_37 ) ) ;
}
void F_18 ( void )
{
T_9 V_38 ;
V_38 = F_19 ( F_1 , V_14 ) ;
F_20 ( L_19 , V_39 , V_38 ) ;
V_29 = F_21 ( L_19 ) ;
}
