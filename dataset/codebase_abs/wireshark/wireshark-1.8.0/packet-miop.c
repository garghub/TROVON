static T_1
F_1 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 ) {
T_5 V_4 ;
V_4 = F_2 ( V_1 ) ;
if ( V_4 < V_5 )
{
return FALSE ;
}
if ( F_3 ( V_1 , 0 , V_6 , 4 ) != 0 )
return FALSE ;
if ( V_2 -> V_7 != V_8 )
return FALSE ;
F_4 ( V_1 , V_2 , V_3 ) ;
return TRUE ;
}
static void F_4 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 ) {
T_5 V_9 = 0 ;
T_4 * V_10 = NULL ;
T_6 * V_11 ;
T_7 V_12 ;
T_5 V_13 ;
T_5 V_14 ;
T_7 V_15 ;
T_8 V_16 ;
T_5 V_17 ;
T_5 V_18 ;
T_5 V_19 ;
T_9 V_20 ;
T_10 * V_21 = F_5 ( L_1 ) ;
F_6 ( V_2 -> V_22 , V_23 , V_6 ) ;
F_7 ( V_2 -> V_22 , V_24 ) ;
V_12 = F_8 ( V_1 , 4 ) ;
V_13 = ( ( V_12 & 0xf0 ) >> 4 ) ;
V_14 = ( V_12 & 0x0f ) ;
if ( V_12 != 16 )
{
F_9 ( V_2 -> V_22 , V_24 , L_2 ,
V_13 , V_14 ) ;
if ( V_3 )
{
V_11 = F_10 ( V_3 , V_25 , V_1 , 0 , - 1 , V_26 ) ;
V_10 = F_11 ( V_11 , V_27 ) ;
F_12 ( V_10 , V_1 , 0 , - 1 ,
L_2 ,
V_13 , V_14 ) ;
F_13 ( V_2 , V_11 , V_28 , V_29 ,
L_3 ,
V_13 , V_14 ) ;
}
return;
}
V_15 = F_8 ( V_1 , 5 ) ;
V_19 = ( V_15 & 0x01 ) ? V_30 : V_31 ;
if ( V_19 == V_31 ) {
V_16 = F_14 ( V_1 , 6 ) ;
V_17 = F_15 ( V_1 , 8 ) ;
V_18 = F_15 ( V_1 , 12 ) ;
V_20 = F_15 ( V_1 , 16 ) ;
}
else {
V_16 = F_16 ( V_1 , 6 ) ;
V_17 = F_17 ( V_1 , 8 ) ;
V_18 = F_17 ( V_1 , 12 ) ;
V_20 = F_17 ( V_1 , 16 ) ;
}
F_9 ( V_2 -> V_22 , V_24 , L_4 ,
V_13 , V_14 , V_16 ,
V_17 + 1 ,
V_18 ) ;
if ( V_3 )
{
V_11 = F_10 ( V_3 , V_25 , V_1 , 0 , - 1 , V_26 ) ;
V_10 = F_11 ( V_11 , V_27 ) ;
F_10 ( V_10 , V_32 , V_1 , V_9 , 4 , V_33 | V_26 ) ;
V_9 += 4 ;
F_18 ( V_10 , V_34 , V_1 , V_9 , 1 , V_12 ,
L_5 , V_13 , V_14 ) ;
V_9 ++ ;
if ( V_15 & 0x01 ) {
F_19 ( V_21 , L_6 ) ;
}
if ( V_15 & 0x02 ) {
F_20 ( V_21 , L_7 ,
V_21 -> V_35 ? L_8 : L_9 , L_10 ) ;
}
F_21 ( V_10 , V_36 , V_1 , V_9 , 1 ,
V_15 , L_11 , V_15 , V_21 -> V_37 ) ;
V_9 ++ ;
F_10 ( V_10 , V_38 , V_1 , V_9 , 2 , V_19 ) ;
V_9 += 2 ;
F_10 ( V_10 , V_39 , V_1 , V_9 , 4 , V_19 ) ;
V_9 += 4 ;
F_10 ( V_10 , V_40 , V_1 , V_9 , 4 , V_19 ) ;
V_9 += 4 ;
V_11 = F_10 ( V_10 , V_41 , V_1 , V_9 , 4 , V_19 ) ;
if ( V_20 >= V_42 ) {
F_13 ( V_2 , V_11 , V_43 , V_29 ,
L_12 ,
V_20 , V_42 ) ;
return;
}
V_9 += 4 ;
F_10 ( V_10 , V_44 , V_1 , V_9 , V_20 ,
V_19 ) ;
if ( V_17 == 0 ) {
T_2 * V_45 ;
V_9 += V_20 ;
V_45 = F_22 ( V_1 , V_9 ) ;
F_23 ( V_45 , V_2 , V_3 ) ;
}
}
}
void F_24 ( void ) {
static T_11 V_46 [] = {
{ & V_32 ,
{ L_13 , L_14 , V_47 , V_48 , NULL , 0x0 ,
L_15 , V_49 } } ,
{ & V_34 ,
{ L_16 , L_17 , V_50 , V_51 , NULL , 0x0 ,
L_18 , V_49 } } ,
{ & V_36 ,
{ L_19 , L_20 , V_50 , V_52 , NULL , 0x0 ,
L_21 , V_49 } } ,
{ & V_38 ,
{ L_22 , L_23 , V_53 , V_54 , NULL , 0x0 ,
L_24 , V_49 } } ,
{ & V_39 ,
{ L_25 , L_26 , V_55 , V_54 , NULL , 0x0 ,
L_27 , V_49 } } ,
{ & V_40 ,
{ L_28 , L_29 , V_55 , V_54 , NULL , 0x0 ,
L_30 , V_49 } } ,
{ & V_41 ,
{ L_31 , L_32 , V_55 , V_54 , NULL , 0x0 ,
L_33 , V_49 } } ,
{ & V_44 ,
{ L_34 , L_35 , V_56 , V_48 , NULL , 0x0 ,
L_36 , V_49 } } ,
} ;
static T_12 * V_57 [] = {
& V_27
} ;
V_25 = F_25 ( L_37 , L_38 ,
L_39 ) ;
F_26 ( V_25 , V_46 , F_27 ( V_46 ) ) ;
F_28 ( V_57 , F_27 ( V_57 ) ) ;
F_29 ( L_39 , F_4 , V_25 ) ;
}
void F_30 ( void ) {
T_13 V_58 ;
V_58 = F_31 ( L_39 ) ;
F_32 ( L_40 , V_58 ) ;
F_33 ( L_41 , F_1 , V_25 ) ;
}
