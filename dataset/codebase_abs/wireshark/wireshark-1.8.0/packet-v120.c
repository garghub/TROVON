static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_3 * V_4 , * V_5 , * V_6 ;
T_4 * V_7 ;
int V_8 ;
int V_9 ;
char * V_10 ;
int V_11 ;
T_5 V_12 , V_13 ;
T_6 V_14 ;
T_1 * V_15 ;
V_10 = F_2 ( 80 ) ;
F_3 ( V_2 -> V_16 , V_17 , L_1 ) ;
F_4 ( V_2 -> V_16 , V_18 ) ;
V_12 = F_5 ( V_1 , 0 ) ;
if( F_6 ( V_2 -> V_16 , V_19 ) )
F_7 ( V_2 -> V_16 , V_19 , L_2 , V_12 ) ;
V_13 = F_5 ( V_1 , 1 ) ;
if ( ( ( V_12 & 0x01 ) != 0x00 ) && ( ( V_13 & 0x01 ) != 0x01 ) )
{
F_3 ( V_2 -> V_16 , V_18 , L_3 ) ;
if ( V_3 )
F_8 ( V_3 , V_20 , V_1 , 0 , - 1 ,
L_3 ) ;
return;
}
if ( V_2 -> V_21 == V_22 ) {
V_8 = ( V_12 & 0x02 ) ? FALSE : TRUE ;
F_3 ( V_2 -> V_16 , V_23 , L_4 ) ;
F_3 ( V_2 -> V_16 , V_19 , L_5 ) ;
} else {
V_8 = ( V_12 & 0x02 ) ? TRUE : FALSE ;
F_3 ( V_2 -> V_16 , V_23 , L_5 ) ;
F_3 ( V_2 -> V_16 , V_19 , L_4 ) ;
}
if ( V_3 ) {
V_7 = F_8 ( V_3 , V_20 , V_1 , 0 , - 1 , L_1 ) ;
V_4 = F_9 ( V_7 , V_24 ) ;
V_9 = V_13 << 8 | V_12 ;
F_10 ( V_10 , 80 , L_6 ,
( ( V_12 & 0xfc ) << 5 ) | ( ( V_13 & 0xfe ) >> 1 ) ,
V_12 & 0x02 ? L_7 : L_8 ) ;
V_5 = F_11 ( V_4 , V_1 ,
0 , 2 ,
L_9 , V_10 ) ;
V_6 = F_9 ( V_5 , V_25 ) ;
F_11 ( V_6 , V_1 , 0 , 2 , L_10 ,
F_12 ( V_9 , 0x0002 , 2 * 8 ,
L_11 , L_12 ) ) ;
F_10 ( V_10 , 80 , L_13 , ( ( V_12 & 0xfc ) << 5 ) | ( ( V_13 & 0xfe ) >> 1 ) ) ;
F_11 ( V_6 , V_1 , 0 , 2 , L_10 ,
F_13 ( V_9 , 0xfefc , 2 * 8 , V_10 ) ) ;
F_11 ( V_6 , V_1 , 0 , 2 , L_10 ,
F_12 ( V_9 , 0x0001 , 2 * 8 ,
L_14 , L_15 ) ) ;
F_11 ( V_6 , V_1 , 0 , 2 , L_10 ,
F_12 ( V_9 , 0x0100 , 2 * 8 ,
L_16 , L_17 ) ) ;
}
else {
V_4 = NULL ;
V_7 = NULL ;
}
V_14 = F_14 ( V_1 , 2 , V_2 , V_4 , V_26 ,
V_27 , & V_28 , & V_29 ,
NULL , NULL , V_8 , TRUE , FALSE ) ;
if ( V_3 ) {
V_11 = 2 + F_15 ( V_14 , TRUE ) ;
if ( F_16 ( V_1 , V_11 , 1 ) )
V_11 += F_17 ( V_1 , V_11 , V_4 ) ;
F_18 ( V_7 , V_11 ) ;
V_15 = F_19 ( V_1 , V_11 ) ;
F_20 ( V_30 , V_15 , V_2 , V_4 ) ;
}
}
static int
F_17 ( T_1 * V_1 , int V_31 , T_3 * V_3 )
{
char * V_10 ;
int V_32 , V_33 ;
int V_34 ;
T_3 * V_35 , * V_5 ;
T_5 V_12 ;
V_10 = F_2 ( 80 ) ;
V_12 = F_5 ( V_1 , V_31 ) ;
if ( V_12 & 0x80 ) {
V_32 = 1 ;
V_34 = V_12 ;
} else {
V_32 = 2 ;
V_34 = V_12 | F_5 ( V_1 , V_31 + 1 ) << 8 ;
}
V_33 = V_32 * 8 ;
F_10 ( V_10 , 80 , L_18 , V_12 & 0x02 ? 1 : 0 ,
V_12 & 0x01 ? 1 : 0 ) ;
V_5 = F_11 ( V_3 , V_1 ,
V_31 , V_32 ,
L_19 , V_10 , V_12 ) ;
V_35 = F_9 ( V_5 , V_36 ) ;
F_11 ( V_35 , V_1 , V_31 , V_32 , L_10 ,
F_12 ( V_34 , 0x80 , V_33 ,
L_20 , L_21 ) ) ;
F_11 ( V_35 , V_1 , V_31 , V_32 , L_10 ,
F_12 ( V_34 , 0x40 , V_33 ,
L_22 , L_23 ) ) ;
F_10 ( V_10 , 80 , L_24 , ( V_34 & 0x0c ) >> 2 ) ;
F_11 ( V_35 , V_1 , V_31 , V_32 , L_10 ,
F_13 ( V_34 , 0x0c , V_33 , V_10 ) ) ;
F_11 ( V_35 , V_1 , V_31 , V_32 , L_10 ,
F_12 ( V_34 , 0x02 , V_33 ,
L_25 , L_26 ) ) ;
F_11 ( V_35 , V_1 , V_31 , V_32 , L_10 ,
F_12 ( V_34 , 0x01 , V_33 ,
L_27 , L_28 ) ) ;
if ( V_32 == 2 ) {
F_11 ( V_35 , V_1 , V_31 , V_32 ,
F_12 ( V_34 , 0x8000 , V_33 ,
L_29 , L_30 ) , NULL ) ;
F_11 ( V_35 , V_1 , V_31 , V_32 ,
F_12 ( V_34 , 0x4000 , V_33 ,
L_31 , L_32 ) , NULL ) ;
F_11 ( V_35 , V_1 , V_31 , V_32 ,
F_12 ( V_34 , 0x2000 , V_33 ,
L_33 , L_34 ) , NULL ) ;
F_11 ( V_35 , V_1 , V_31 , V_32 ,
F_12 ( V_34 , 0x1000 , V_33 ,
L_35 , L_36 ) , NULL ) ;
}
return V_32 ;
}
void
F_21 ( void )
{
static T_7 V_37 [] = {
{ & V_38 ,
{ L_37 , L_38 , V_39 , V_40 , NULL ,
0x0 , NULL , V_41 } } ,
{ & V_26 ,
{ L_39 , L_40 , V_39 , V_40 , NULL , 0x0 ,
NULL , V_41 } } ,
{ & V_42 ,
{ L_41 , L_42 , V_39 , V_43 ,
NULL , V_44 , NULL , V_41 } } ,
{ & V_45 ,
{ L_43 , L_44 , V_39 , V_43 ,
NULL , V_46 , NULL , V_41 } } ,
{ & V_47 ,
{ L_45 , L_46 , V_48 , 8 ,
F_22 ( & V_49 ) , V_50 , NULL , V_41 } } ,
{ & V_51 ,
{ L_45 , L_46 , V_48 , 16 ,
F_22 ( & V_49 ) , V_52 , NULL , V_41 } } ,
{ & V_53 ,
{ L_47 , L_48 , V_48 , 8 ,
F_22 ( & V_49 ) , V_50 , NULL , V_41 } } ,
{ & V_54 ,
{ L_47 , L_48 , V_48 , 16 ,
F_22 ( & V_49 ) , V_52 , NULL , V_41 } } ,
{ & V_55 ,
{ L_49 , L_50 , V_39 , V_40 ,
F_23 ( V_56 ) , V_57 , NULL , V_41 } } ,
{ & V_58 ,
{ L_12 , L_51 , V_59 , V_40 ,
F_23 ( V_60 ) , V_61 , NULL , V_41 } } ,
{ & V_62 ,
{ L_11 , L_52 , V_59 , V_40 ,
F_23 ( V_63 ) , V_61 , NULL , V_41 } } ,
{ & V_64 ,
{ L_53 , L_54 , V_39 , V_40 ,
F_23 ( V_65 ) , V_66 , NULL , V_41 } } ,
{ & V_67 ,
{ L_53 , L_54 , V_59 , V_40 ,
F_23 ( V_65 ) , V_68 , NULL , V_41 } } ,
{ & V_69 ,
{ L_53 , L_54 , V_39 , V_40 ,
F_23 ( V_65 ) , V_68 , NULL , V_41 } } ,
{ & V_70 ,
{ L_55 , L_56 , V_71 , V_72 , NULL , 0x0 ,
NULL , V_41 } } ,
} ;
static T_8 * V_73 [] = {
& V_24 ,
& V_25 ,
& V_27 ,
& V_36 ,
} ;
V_20 = F_24 ( L_57 ,
L_1 , L_58 ) ;
F_25 ( V_20 , V_37 , F_26 ( V_37 ) ) ;
F_27 ( V_73 , F_26 ( V_73 ) ) ;
F_28 ( L_58 , F_1 , V_20 ) ;
}
void
F_29 ( void )
{
V_30 = F_30 ( L_59 ) ;
}
