static void
F_1 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_1 , V_3 , L_1 ,
( ( float ) V_2 / 8388607.0 ) * 90 , V_2 ) ;
}
static void
F_3 ( T_1 * V_1 , T_2 V_2 )
{
T_3 V_4 = ( T_3 ) V_2 ;
F_2 ( V_1 , V_3 , L_2 ,
( ( float ) V_4 / 8388608.0 ) * 180 , V_4 ) ;
}
static void
F_4 ( T_1 * V_1 , T_2 V_2 )
{
double V_5 = 10 * ( pow ( 1.1 , ( double ) V_2 ) - 1 ) ;
if ( V_5 < 1000 ) {
F_2 ( V_1 , V_3 , L_3 , V_5 , V_2 ) ;
} else {
F_2 ( V_1 , V_3 , L_4 , V_5 / 1000 , V_2 ) ;
}
}
static void
F_5 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_1 , V_3 , L_5 , 2 * V_2 , V_2 ) ;
}
static void
F_6 ( T_1 * V_1 , T_2 V_2 )
{
if ( V_2 == 0 ) {
F_2 ( V_1 , V_3 , L_6 ) ;
} else {
F_2 ( V_1 , V_3 , L_7 , V_2 ) ;
}
}
static void
F_7 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_1 , V_3 , L_8 , V_2 ) ;
}
static void
F_8 ( T_1 * V_1 , T_2 V_2 )
{
double V_5 = 45 * ( pow ( 1.025 , ( double ) V_2 ) - 1 ) ;
F_2 ( V_1 , V_3 , L_3 , V_5 , V_2 ) ;
}
static void
F_9 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_1 , V_3 , L_9 , 5 * V_2 , V_2 ) ;
}
static void
F_10 ( T_1 * V_1 , T_2 V_2 )
{
T_3 V_6 = 3 * ( ( T_3 ) V_2 - 8192 ) ;
F_2 ( V_1 , V_3 , L_10 , V_6 , V_2 ) ;
}
static void
F_11 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_1 , V_3 , L_11 , 3 * V_2 , V_2 ) ;
}
static void
F_12 ( T_1 * V_1 , T_2 V_2 )
{
if ( V_2 == 0 ) {
F_2 ( V_1 , V_3 , L_12 ) ;
} else if ( V_2 < 2260 ) {
F_2 ( V_1 , V_3 , L_13 , 15391 - 5 * ( V_2 - 1 ) , 15391 - 5 * V_2 , V_2 ) ;
} else if ( V_2 < 6355 ) {
F_2 ( V_1 , V_3 , L_13 , 6356 - V_2 , 6355 - V_2 , V_2 ) ;
} else if ( V_2 == 6355 ) {
F_2 ( V_1 , V_3 , L_14 ) ;
} else if ( V_2 < 10452 ) {
F_2 ( V_1 , V_3 , L_15 , V_2 - 6356 , V_2 - 6355 , V_2 ) ;
} else if ( V_2 < 12711 ) {
F_2 ( V_1 , V_3 , L_15 , 5 * ( V_2 - 1 ) - 48159 , 5 * V_2 - 48159 , V_2 ) ;
} else {
F_2 ( V_1 , V_3 , L_16 ) ;
}
}
static void
F_13 ( T_1 * V_1 , T_2 V_2 )
{
double V_7 = 0.5 * ( pow ( 1.14 , ( double ) V_2 ) - 1 ) ;
F_2 ( V_1 , V_3 , L_17 , V_7 , V_2 ) ;
}
static void
F_14 ( T_1 * V_1 , T_2 V_2 )
{
float V_8 = ( ( float ) V_2 ) / 4 ;
F_2 ( V_1 , V_3 , L_17 , V_8 , V_2 ) ;
}
static void
F_15 ( T_1 * V_1 , T_2 V_2 )
{
double V_9 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 30 ) ;
F_2 ( V_1 , V_3 , L_18 , V_9 , ( T_3 ) V_2 ) ;
}
static void
F_16 ( T_1 * V_1 , T_2 V_2 )
{
double V_10 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 30 ) ;
F_2 ( V_1 , V_3 , L_19 , V_10 , ( T_3 ) V_2 ) ;
}
static void
F_17 ( T_1 * V_1 , T_2 V_2 )
{
double V_10 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 27 ) ;
F_2 ( V_1 , V_3 , L_20 , V_10 , ( T_3 ) V_2 ) ;
}
static void
F_18 ( T_1 * V_1 , T_2 V_2 )
{
double V_10 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 24 ) ;
F_2 ( V_1 , V_3 , L_20 , V_10 , ( T_3 ) V_2 ) ;
}
static void
F_19 ( T_1 * V_1 , T_2 V_2 )
{
double V_11 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , 11 ) ;
F_2 ( V_1 , V_3 , L_19 , V_11 , ( T_3 ) V_2 ) ;
}
static void
F_20 ( T_1 * V_1 , T_2 V_2 )
{
double V_11 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , 14 ) ;
F_2 ( V_1 , V_3 , L_20 , V_11 , ( T_3 ) V_2 ) ;
}
static void
F_21 ( T_1 * V_1 , T_2 V_2 )
{
double V_11 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , 16 ) ;
F_2 ( V_1 , V_3 , L_20 , V_11 , ( T_3 ) V_2 ) ;
}
static void
F_22 ( T_1 * V_1 , T_2 V_2 )
{
double V_12 = ( double ) V_2 * pow ( 2 , - 2 ) ;
F_2 ( V_1 , V_3 , L_21 , V_12 , V_2 ) ;
}
static void
F_23 ( T_1 * V_1 , T_2 V_2 )
{
double V_12 = ( double ) V_2 * pow ( 2 , - 8 ) ;
F_2 ( V_1 , V_3 , L_22 , V_12 , V_2 ) ;
}
static void
F_24 ( T_1 * V_1 , T_2 V_2 )
{
double V_12 = ( double ) V_2 * pow ( 2 , - 15 ) ;
F_2 ( V_1 , V_3 , L_23 , V_12 , V_2 ) ;
}
static void
F_25 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_1 , V_3 , L_24 , 16 * V_2 , V_2 ) ;
}
static void
F_26 ( T_1 * V_1 , T_2 V_2 )
{
double V_13 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 20 ) ;
F_2 ( V_1 , V_3 , L_25 , V_13 , ( T_3 ) V_2 ) ;
}
static void
F_27 ( T_1 * V_1 , T_2 V_2 )
{
double V_14 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 21 ) ;
F_2 ( V_1 , V_3 , L_26 , V_14 , ( T_3 ) V_2 ) ;
}
static void
F_28 ( T_1 * V_1 , T_2 V_2 )
{
double V_15 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 24 ) ;
F_2 ( V_1 , V_3 , L_19 , V_15 , ( T_3 ) V_2 ) ;
}
static void
F_29 ( T_1 * V_1 , T_2 V_2 )
{
double V_16 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 25 ) ;
F_2 ( V_1 , V_3 , L_27 , V_16 , ( T_3 ) V_2 ) ;
}
static void
F_30 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_1 , V_3 , L_24 , V_2 * 16 , V_2 ) ;
}
static void
F_31 ( T_1 * V_1 , T_2 V_2 )
{
double V_17 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 35 ) ;
F_2 ( V_1 , V_3 , L_19 , V_17 , ( T_3 ) V_2 ) ;
}
static void
F_32 ( T_1 * V_1 , T_2 V_2 )
{
double V_18 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 51 ) ;
F_2 ( V_1 , V_3 , L_18 , V_18 , ( T_3 ) V_2 ) ;
}
static void
F_33 ( T_1 * V_1 , T_2 V_2 )
{
double V_19 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 68 ) ;
F_2 ( V_1 , V_3 , L_28 , V_19 , ( T_3 ) V_2 ) ;
}
static void
F_34 ( T_1 * V_1 , T_2 V_2 )
{
double V_20 = ( ( double ) ( T_3 ) V_2 ) * 0.32 ;
F_2 ( V_1 , V_3 , L_29 , V_20 , ( T_3 ) V_2 ) ;
}
static void
F_35 ( T_1 * V_1 , T_2 V_2 )
{
double V_21 = ( ( double ) ( T_3 ) V_2 ) * 0.032 ;
F_2 ( V_1 , V_3 , L_30 , V_21 , ( T_3 ) V_2 ) ;
}
static void
F_36 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_1 , V_3 , L_31 , 60 * V_2 , V_2 ) ;
}
static void
F_37 ( T_1 * V_1 , T_2 V_2 )
{
double V_22 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 59 ) ;
F_2 ( V_1 , V_3 , L_28 , V_22 , ( T_3 ) V_2 ) ;
}
static void
F_38 ( T_1 * V_1 , T_2 V_2 )
{
double V_23 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 46 ) ;
F_2 ( V_1 , V_3 , L_18 , V_23 , ( T_3 ) V_2 ) ;
}
static void
F_39 ( T_1 * V_1 , T_2 V_2 )
{
double V_24 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 34 ) ;
F_2 ( V_1 , V_3 , L_19 , V_24 , ( T_3 ) V_2 ) ;
}
static void
F_40 ( T_1 * V_1 , T_2 V_2 )
{
double V_25 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 32 ) ;
F_2 ( V_1 , V_3 , L_19 , V_25 , ( T_3 ) V_2 ) ;
}
static void
F_41 ( T_1 * V_1 , T_2 V_2 )
{
if ( V_2 < 50 ) {
F_2 ( V_1 , V_3 , L_32 , V_2 , V_2 ) ;
} else if ( V_2 < 75 ) {
F_2 ( V_1 , V_3 , L_32 , 50 + ( ( V_2 - 50 ) * 2 ) , V_2 ) ;
} else if ( V_2 < 100 ) {
F_2 ( V_1 , V_3 , L_32 , 100 + ( ( V_2 - 75 ) * 4 ) , V_2 ) ;
} else if ( V_2 < 126 ) {
F_2 ( V_1 , V_3 , L_32 , 200 + ( ( V_2 - 100 ) * 16 ) , V_2 ) ;
} else if ( V_2 < 255 ) {
F_2 ( V_1 , V_3 , L_33 , V_2 ) ;
} else {
F_2 ( V_1 , V_3 , L_34 ) ;
}
}
static void
F_42 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_1 , V_3 , L_24 , 16 * V_2 , V_2 ) ;
}
static void
F_43 ( T_1 * V_1 , T_2 V_2 )
{
double V_26 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 55 ) ;
F_2 ( V_1 , V_3 , L_28 , V_26 , ( T_3 ) V_2 ) ;
}
static void
F_44 ( T_1 * V_1 , T_2 V_2 )
{
double V_27 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 43 ) ;
F_2 ( V_1 , V_3 , L_18 , V_27 , ( T_3 ) V_2 ) ;
}
static void
F_45 ( T_1 * V_1 , T_2 V_2 )
{
double V_28 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 31 ) ;
F_2 ( V_1 , V_3 , L_18 , V_28 , ( T_3 ) V_2 ) ;
}
static void
F_46 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_1 , V_3 , L_24 , 300 * V_2 , V_2 ) ;
}
static void
F_47 ( T_1 * V_1 , T_2 V_2 )
{
double V_29 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 60 ) ;
F_2 ( V_1 , V_3 , L_28 , V_29 , ( T_3 ) V_2 ) ;
}
static void
F_48 ( T_1 * V_1 , T_2 V_2 )
{
double V_30 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 48 ) ;
F_2 ( V_1 , V_3 , L_18 , V_30 , ( T_3 ) V_2 ) ;
}
static void
F_49 ( T_1 * V_1 , T_2 V_2 )
{
double V_31 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 35 ) ;
F_2 ( V_1 , V_3 , L_19 , V_31 , ( T_3 ) V_2 ) ;
}
static void
F_50 ( T_1 * V_1 , T_2 V_2 )
{
double V_32 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 30 ) ;
F_2 ( V_1 , V_3 , L_19 , V_32 , ( T_3 ) V_2 ) ;
}
static void
F_51 ( T_1 * V_1 , T_2 V_2 )
{
double V_33 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 40 ) ;
F_2 ( V_1 , V_3 , L_35 , V_33 , ( T_3 ) V_2 ) ;
}
static void
F_52 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_1 , V_3 , L_24 , 16 * V_2 , V_2 ) ;
}
static void
F_53 ( T_1 * V_1 , T_2 V_2 )
{
double V_34 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 31 ) ;
F_2 ( V_1 , V_3 , L_19 , V_34 , ( T_3 ) V_2 ) ;
}
static void
F_54 ( T_1 * V_1 , T_2 V_2 )
{
double V_35 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 40 ) ;
F_2 ( V_1 , V_3 , L_18 , V_35 , ( T_3 ) V_2 ) ;
}
static void
F_55 ( T_1 * V_1 , T_2 V_2 )
{
if ( V_2 < 25 ) {
F_2 ( V_1 , V_3 , L_36 , V_2 , V_2 ) ;
} else if ( V_2 < 31 ) {
F_2 ( V_1 , V_3 , L_37 , V_2 - 23 , V_2 ) ;
} else {
F_2 ( V_1 , V_3 , L_38 , V_2 ) ;
}
}
static void
F_56 ( T_1 * V_1 , T_2 V_2 )
{
double V_36 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , 3 ) ;
F_2 ( V_1 , V_3 , L_19 , V_36 , ( T_3 ) V_2 ) ;
}
static void
F_57 ( T_1 * V_1 , T_2 V_2 )
{
double V_37 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 33 ) ;
F_2 ( V_1 , V_3 , L_19 , V_37 , ( T_3 ) V_2 ) ;
}
static void
F_58 ( T_1 * V_1 , T_2 V_2 )
{
double V_38 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 50 ) ;
F_2 ( V_1 , V_3 , L_18 , V_38 , ( T_3 ) V_2 ) ;
}
static void
F_59 ( T_1 * V_1 , T_2 V_2 )
{
double V_39 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 66 ) ;
F_2 ( V_1 , V_3 , L_28 , V_39 , ( T_3 ) V_2 ) ;
}
static void
F_60 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_1 , V_3 , L_39 , ( float ) ( ( T_3 ) V_2 ) * 0.1 , ( T_3 ) V_2 ) ;
}
static void
F_61 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_1 , V_3 , L_24 , 60 * V_2 , V_2 ) ;
}
static void
F_62 ( T_1 * V_1 , T_2 V_2 )
{
double V_40 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 31 ) ;
F_2 ( V_1 , V_3 , L_40 , V_40 , ( T_3 ) V_2 ) ;
}
static void
F_63 ( T_1 * V_1 , T_2 V_2 )
{
double V_41 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 43 ) ;
F_2 ( V_1 , V_3 , L_41 , V_41 , ( T_3 ) V_2 ) ;
}
static void
F_64 ( T_1 * V_1 , T_2 V_2 )
{
double V_42 = ( double ) V_2 * pow ( 2 , - 33 ) ;
F_2 ( V_1 , V_3 , L_42 , V_42 , V_2 ) ;
}
static void
F_65 ( T_1 * V_1 , T_2 V_2 )
{
double V_43 = ( double ) V_2 * pow ( 2 , - 19 ) ;
F_2 ( V_1 , V_3 , L_43 , V_43 , V_2 ) ;
}
static void
F_66 ( T_1 * V_1 , T_2 V_2 )
{
double V_44 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 5 ) ;
F_2 ( V_1 , V_3 , L_44 , V_44 , ( T_3 ) V_2 ) ;
}
static void
F_67 ( T_1 * V_1 , T_2 V_2 )
{
double V_45 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 29 ) ;
F_2 ( V_1 , V_3 , L_45 , V_45 , ( T_3 ) V_2 ) ;
}
static void
F_68 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_1 , V_3 , L_24 , 16 * V_2 , V_2 ) ;
}
static void
F_69 ( T_1 * V_1 , T_2 V_2 )
{
double V_46 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 31 ) ;
F_2 ( V_1 , V_3 , L_40 , V_46 , ( T_3 ) V_2 ) ;
}
static void
F_70 ( T_1 * V_1 , T_2 V_2 )
{
double V_47 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 43 ) ;
F_2 ( V_1 , V_3 , L_41 , V_47 , ( T_3 ) V_2 ) ;
}
static void
F_71 ( T_1 * V_1 , T_2 V_2 )
{
double V_48 = ( double ) V_2 * pow ( 2 , - 33 ) ;
F_2 ( V_1 , V_3 , L_42 , V_48 , V_2 ) ;
}
static void
F_72 ( T_1 * V_1 , T_2 V_2 )
{
double V_49 = ( double ) V_2 * pow ( 2 , - 19 ) ;
F_2 ( V_1 , V_3 , L_43 , V_49 , V_2 ) ;
}
static void
F_73 ( T_1 * V_1 , T_2 V_2 )
{
double V_50 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 5 ) ;
F_2 ( V_1 , V_3 , L_44 , V_50 , ( T_3 ) V_2 ) ;
}
static void
F_74 ( T_1 * V_1 , T_2 V_2 )
{
double V_51 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 29 ) ;
F_2 ( V_1 , V_3 , L_45 , V_51 , ( T_3 ) V_2 ) ;
}
static void
F_75 ( T_1 * V_1 , T_2 V_2 )
{
double V_52 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 9 ) ;
F_2 ( V_1 , V_3 , L_44 , V_52 , ( T_3 ) V_2 ) ;
}
static void
F_76 ( T_1 * V_1 , T_2 V_2 )
{
double V_53 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 21 ) ;
F_2 ( V_1 , V_3 , L_46 , V_53 , ( T_3 ) V_2 ) ;
}
static void
F_77 ( T_1 * V_1 , T_2 V_2 )
{
double V_54 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 44 ) ;
F_2 ( V_1 , V_3 , L_41 , V_54 , ( T_3 ) V_2 ) ;
}
static void
F_78 ( T_1 * V_1 , T_2 V_2 )
{
double V_55 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 57 ) ;
F_2 ( V_1 , V_3 , L_47 , V_55 , ( T_3 ) V_2 ) ;
}
static void
F_79 ( T_1 * V_1 , T_2 V_2 )
{
double V_56 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 44 ) ;
F_2 ( V_1 , V_3 , L_41 , V_56 , ( T_3 ) V_2 ) ;
}
static void
F_80 ( T_1 * V_1 , T_2 V_2 )
{
double V_57 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 30 ) ;
F_2 ( V_1 , V_3 , L_45 , V_57 , ( T_3 ) V_2 ) ;
}
static void
F_81 ( T_1 * V_1 , T_2 V_2 )
{
double V_58 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 8 ) ;
F_2 ( V_1 , V_3 , L_44 , V_58 , ( T_3 ) V_2 ) ;
}
static void
F_82 ( T_1 * V_1 , T_2 V_2 )
{
double V_59 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 11 ) ;
F_2 ( V_1 , V_3 , L_48 , V_59 , ( T_3 ) V_2 ) ;
}
static void
F_83 ( T_1 * V_1 , T_2 V_2 )
{
double V_60 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 20 ) ;
F_2 ( V_1 , V_3 , L_49 , V_60 , ( T_3 ) V_2 ) ;
}
static void
F_84 ( T_1 * V_1 , T_2 V_2 )
{
double V_61 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 30 ) ;
F_2 ( V_1 , V_3 , L_50 , V_61 , ( T_3 ) V_2 ) ;
}
static void
F_85 ( T_1 * V_1 , T_2 V_2 )
{
double V_62 = ( double ) ( ( T_3 ) V_2 ) * 0.08 ;
F_2 ( V_1 , V_3 , L_29 , V_62 , ( T_3 ) V_2 ) ;
}
static void
F_86 ( T_1 * V_1 , T_2 V_2 )
{
double V_63 = ( double ) ( ( T_3 ) V_2 ) * 0.4 ;
F_2 ( V_1 , V_3 , L_29 , V_63 , ( T_3 ) V_2 ) ;
}
static void
F_87 ( T_1 * V_1 , T_2 V_2 )
{
double V_64 = ( double ) ( ( T_3 ) V_2 ) * 0.000625 ;
F_2 ( V_1 , V_3 , L_30 , V_64 , ( T_3 ) V_2 ) ;
}
static void
F_88 ( T_1 * V_1 , T_2 V_2 )
{
double V_65 = ( double ) ( ( T_3 ) V_2 ) * 0.004 ;
F_2 ( V_1 , V_3 , L_30 , V_65 , ( T_3 ) V_2 ) ;
}
static void
F_89 ( T_1 * V_1 , T_2 V_2 )
{
double V_66 = ( double ) ( ( T_3 ) V_2 ) * 0.0000125 ;
F_2 ( V_1 , V_3 , L_51 , V_66 , ( T_3 ) V_2 ) ;
}
static void
F_90 ( T_1 * V_1 , T_2 V_2 )
{
double V_67 = ( double ) ( ( T_3 ) V_2 ) * 0.0000625 ;
F_2 ( V_1 , V_3 , L_51 , V_67 , ( T_3 ) V_2 ) ;
}
static void
F_91 ( T_1 * V_1 , T_2 V_2 )
{
double V_68 = ( double ) V_2 * pow ( 2 , - 19 ) ;
F_2 ( V_1 , V_3 , L_43 , V_68 , V_2 ) ;
}
static void
F_92 ( T_1 * V_1 , T_2 V_2 )
{
double V_69 = ( double ) V_2 * pow ( 2 , - 33 ) ;
F_2 ( V_1 , V_3 , L_42 , V_69 , V_2 ) ;
}
static void
F_93 ( T_1 * V_1 , T_2 V_2 )
{
double V_70 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 31 ) ;
F_2 ( V_1 , V_3 , L_40 , V_70 , ( T_3 ) V_2 ) ;
}
static void
F_94 ( T_1 * V_1 , T_2 V_2 )
{
double V_71 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 43 ) ;
F_2 ( V_1 , V_3 , L_41 , V_71 , ( T_3 ) V_2 ) ;
}
static void
F_95 ( T_1 * V_1 , T_2 V_2 )
{
double V_72 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 31 ) ;
F_2 ( V_1 , V_3 , L_45 , V_72 , ( T_3 ) V_2 ) ;
}
static void
F_96 ( T_1 * V_1 , T_2 V_2 )
{
double V_73 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 6 ) ;
F_2 ( V_1 , V_3 , L_45 , V_73 , ( T_3 ) V_2 ) ;
}
static void
F_97 ( T_1 * V_1 , T_2 V_2 )
{
double V_74 = ( double ) ( ( T_3 ) V_2 ) * 0.5 ;
F_2 ( V_1 , V_3 , L_30 , V_74 , ( T_3 ) V_2 ) ;
}
static void
F_98 ( T_1 * V_1 , T_2 V_2 )
{
double V_75 = ( double ) ( ( T_3 ) ( V_2 - 42 ) ) / 210 ;
F_2 ( V_1 , V_3 , L_52 , V_75 , V_2 ) ;
}
static void
F_99 ( T_1 * V_1 , T_2 V_2 )
{
double V_76 = ( double ) V_2 * pow ( 2 , - 10 ) ;
F_2 ( V_1 , V_3 , L_53 , V_76 , V_2 ) ;
}
static void
F_100 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_1 , V_3 , L_1 , ( float ) V_2 * 0.703125 , V_2 ) ;
}
static void
F_101 ( T_1 * V_1 , T_2 V_2 )
{
double V_77 = ( double ) V_2 * pow ( 2 , - 16 ) ;
F_2 ( V_1 , V_3 , L_42 , V_77 , V_2 ) ;
}
static void
F_102 ( T_1 * V_1 , T_2 V_2 )
{
double V_78 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 14 ) ;
F_2 ( V_1 , V_3 , L_40 , V_78 , ( T_3 ) V_2 ) ;
}
static void
F_103 ( T_1 * V_1 , T_2 V_2 )
{
double V_79 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 33 ) ;
F_2 ( V_1 , V_3 , L_41 , V_79 , ( T_3 ) V_2 ) ;
}
static void
F_104 ( T_1 * V_1 , T_2 V_2 )
{
double V_80 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 9 ) ;
F_2 ( V_1 , V_3 , L_54 , V_80 , ( T_3 ) V_2 ) ;
}
static void
F_105 ( T_1 * V_1 , T_2 V_2 )
{
double V_81 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 15 ) ;
F_2 ( V_1 , V_3 , L_40 , V_81 , ( T_3 ) V_2 ) ;
}
static void
F_106 ( T_1 * V_1 , T_2 V_2 )
{
double V_82 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 19 ) ;
F_2 ( V_1 , V_3 , L_19 , V_82 , ( T_3 ) V_2 ) ;
}
static void
F_107 ( T_1 * V_1 , T_2 V_2 )
{
double V_83 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 38 ) ;
F_2 ( V_1 , V_3 , L_18 , V_83 , ( T_3 ) V_2 ) ;
}
static void
F_108 ( T_1 * V_1 , T_2 V_2 )
{
double V_84 = ( double ) V_2 * pow ( 2 , - 21 ) ;
F_2 ( V_1 , V_3 , L_42 , V_84 , V_2 ) ;
}
static void
F_109 ( T_1 * V_1 , T_2 V_2 )
{
double V_85 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 19 ) ;
F_2 ( V_1 , V_3 , L_40 , V_85 , ( T_3 ) V_2 ) ;
}
static void
F_110 ( T_1 * V_1 , T_2 V_2 )
{
double V_86 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 38 ) ;
F_2 ( V_1 , V_3 , L_41 , V_86 , ( T_3 ) V_2 ) ;
}
static void
F_111 ( T_1 * V_1 , T_2 V_2 )
{
double V_87 = ( double ) V_2 * pow ( 2 , - 11 ) ;
F_2 ( V_1 , V_3 , L_43 , V_87 , V_2 ) ;
}
static void
F_112 ( T_1 * V_1 , T_2 V_2 )
{
double V_88 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 23 ) ;
F_2 ( V_1 , V_3 , L_40 , V_88 , ( T_3 ) V_2 ) ;
}
static void
F_113 ( T_1 * V_1 , T_2 V_2 )
{
double V_89 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 20 ) ;
F_2 ( V_1 , V_3 , L_19 , V_89 , ( T_3 ) V_2 ) ;
}
static void
F_114 ( T_1 * V_1 , T_2 V_2 )
{
double V_90 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 38 ) ;
F_2 ( V_1 , V_3 , L_18 , V_90 , ( T_3 ) V_2 ) ;
}
static void
F_115 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_1 , V_3 , L_55 , 512 * ( V_91 ) V_2 , ( V_91 ) V_2 ) ;
}
static void
F_116 ( T_1 * V_1 , T_2 V_2 )
{
double V_92 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 6 ) ;
F_2 ( V_1 , V_3 , L_40 , V_92 , ( T_3 ) V_2 ) ;
}
static void
F_117 ( T_1 * V_1 , T_2 V_2 )
{
double V_93 = ( double ) V_2 * pow ( 2 , - 16 ) ;
F_2 ( V_1 , V_3 , L_42 , V_93 , V_2 ) ;
}
static void
F_118 ( T_1 * V_1 , T_2 V_2 )
{
double V_94 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 14 ) ;
F_2 ( V_1 , V_3 , L_40 , V_94 , ( T_3 ) V_2 ) ;
}
static void
F_119 ( T_1 * V_1 , T_2 V_2 )
{
double V_95 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 33 ) ;
F_2 ( V_1 , V_3 , L_41 , V_95 , ( T_3 ) V_2 ) ;
}
static void
F_120 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_1 , V_3 , L_56 , ( float ) V_2 * 0.0625 , V_2 ) ;
}
static void
F_121 ( T_1 * V_1 , T_2 V_2 )
{
double V_96 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 15 ) ;
F_2 ( V_1 , V_3 , L_40 , V_96 , ( T_3 ) V_2 ) ;
}
static void
F_122 ( T_1 * V_1 , T_2 V_2 )
{
double V_97 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 20 ) ;
F_2 ( V_1 , V_3 , L_19 , V_97 , ( T_3 ) V_2 ) ;
}
static void
F_123 ( T_1 * V_1 , T_2 V_2 )
{
double V_98 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 37 ) ;
F_2 ( V_1 , V_3 , L_18 , V_98 , ( T_3 ) V_2 ) ;
}
static void
F_124 ( T_1 * V_1 , T_2 V_2 )
{
double V_99 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 20 ) ;
F_2 ( V_1 , V_3 , L_40 , V_99 , ( T_3 ) V_2 ) ;
}
static void
F_125 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_1 , V_3 , L_57 , ( float ) V_2 * 0.03125 , V_2 ) ;
}
static void
F_126 ( T_1 * V_1 , T_2 V_2 )
{
double V_100 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 9 ) ;
F_2 ( V_1 , V_3 , L_58 , V_100 , ( T_3 ) V_2 ) ;
}
static void
F_127 ( T_1 * V_1 , T_2 V_2 )
{
double V_101 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 14 ) ;
F_2 ( V_1 , V_3 , L_58 , V_101 , ( T_3 ) V_2 ) ;
}
static void
F_128 ( T_1 * V_1 , T_2 V_2 )
{
double V_102 = ( double ) V_2 * pow ( 2 , - 20 ) ;
F_2 ( V_1 , V_3 , L_42 , V_102 , ( T_3 ) V_2 ) ;
}
static void
F_129 ( T_1 * V_1 , T_2 V_2 )
{
double V_103 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 15 ) ;
F_2 ( V_1 , V_3 , L_40 , V_103 , ( T_3 ) V_2 ) ;
}
static void
F_130 ( T_1 * V_1 , T_2 V_2 )
{
double V_104 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 18 ) ;
F_2 ( V_1 , V_3 , L_19 , V_104 , ( T_3 ) V_2 ) ;
}
static void
F_131 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_1 , V_3 , L_59 , ( T_3 ) V_2 * 2.6 , ( T_3 ) V_2 ) ;
}
static void
F_132 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_1 , V_3 , L_60 , ( T_3 ) V_2 * 26 , ( T_3 ) V_2 ) ;
}
static void
F_133 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_1 , V_3 , L_61 , ( T_3 ) V_2 * 10 , ( T_3 ) V_2 ) ;
}
static void
F_134 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_1 , V_3 , L_30 , ( T_3 ) V_2 * 40.96 , ( T_3 ) V_2 ) ;
}
static void
F_135 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_1 , V_3 , L_31 , V_2 * 64 , V_2 ) ;
}
static void
F_136 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_1 , V_3 , L_24 , V_2 * 4096 , V_2 ) ;
}
static void
F_137 ( T_1 * V_1 , T_2 V_2 )
{
double V_105 = ( double ) V_2 * pow ( 2 , - 11 ) ;
F_2 ( V_1 , V_3 , L_43 , V_105 , V_2 ) ;
}
static void
F_138 ( T_1 * V_1 , T_2 V_2 )
{
double V_106 = ( double ) V_2 * pow ( 2 , - 21 ) ;
F_2 ( V_1 , V_3 , L_43 , V_106 , V_2 ) ;
}
static void
F_139 ( T_1 * V_1 , T_2 V_2 )
{
double V_107 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 23 ) ;
F_2 ( V_1 , V_3 , L_40 , V_107 , ( T_3 ) V_2 ) ;
}
static void
F_140 ( T_1 * V_1 , T_2 V_2 )
{
double V_108 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 38 ) ;
F_2 ( V_1 , V_3 , L_41 , V_108 , ( T_3 ) V_2 ) ;
}
static void
F_141 ( T_1 * V_1 , T_2 V_2 )
{
double V_109 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 19 ) ;
F_2 ( V_1 , V_3 , L_40 , V_109 , ( T_3 ) V_2 ) ;
}
static void
F_142 ( T_1 * V_1 , T_2 V_2 )
{
double V_110 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 20 ) ;
F_2 ( V_1 , V_3 , L_19 , V_110 , ( T_3 ) V_2 ) ;
}
static void
F_143 ( T_1 * V_1 , T_2 V_2 )
{
double V_111 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 38 ) ;
F_2 ( V_1 , V_3 , L_18 , V_111 , ( T_3 ) V_2 ) ;
}
static void
F_144 ( T_1 * V_1 , T_2 V_2 )
{
double V_112 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 50 ) ;
F_2 ( V_1 , V_3 , L_18 , V_112 , ( T_3 ) V_2 ) ;
}
static void
F_145 ( T_1 * V_1 , T_2 V_2 )
{
double V_113 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 30 ) ;
F_2 ( V_1 , V_3 , L_19 , V_113 , ( T_3 ) V_2 ) ;
}
static void
F_146 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_1 , V_3 , L_24 , V_2 * 4096 , V_2 ) ;
}
static void
F_147 ( T_1 * V_1 , T_2 V_2 )
{
if ( ( T_3 ) V_2 == - 4096 ) {
F_2 ( V_1 , V_3 , L_62 , ( T_3 ) V_2 ) ;
} else {
F_2 ( V_1 , V_3 , L_44 , ( float ) ( ( T_3 ) V_2 ) * 0.1 , ( T_3 ) V_2 ) ;
}
}
static void
F_148 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_1 , V_3 , L_44 , ( float ) ( ( T_3 ) V_2 ) * 0.125 , ( T_3 ) V_2 ) ;
}
static void
F_149 ( T_1 * V_1 , T_2 V_2 )
{
double V_114 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 31 ) ;
F_2 ( V_1 , V_3 , L_19 , V_114 , ( T_3 ) V_2 ) ;
}
static void
F_150 ( T_1 * V_1 , T_2 V_2 )
{
double V_115 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 10 ) ;
F_2 ( V_1 , V_3 , L_19 , V_115 , ( T_3 ) V_2 ) ;
}
static void
F_151 ( T_1 * V_1 , T_2 V_2 )
{
double V_116 = ( double ) ( ( T_3 ) V_2 ) * pow ( 2 , - 16 ) ;
F_2 ( V_1 , V_3 , L_63 , V_116 , ( T_3 ) V_2 ) ;
}
static void
F_152 ( T_1 * V_1 , T_2 V_2 )
{
double V_76 = ( double ) V_2 * pow ( 2 , - 21 ) ;
F_2 ( V_1 , V_3 , L_53 , V_76 , V_2 ) ;
}
static void
F_153 ( T_1 * V_1 , T_2 V_2 )
{
T_4 V_117 = V_2 & 0x07 ;
T_4 V_118 = ( V_2 & 0x38 ) >> 3 ;
T_4 V_119 = ( V_2 - 1 ) & 0x07 ;
T_4 V_120 = ( ( V_2 - 1 ) & 0x38 ) >> 3 ;
if ( V_2 == 0 ) {
F_2 ( V_1 , V_3 , L_64 ) ;
} else if ( V_2 < 63 ) {
F_2 ( V_1 , V_3 , L_65 , 0.5 * ( 1 + V_119 / 8 ) * pow ( 2 , V_120 ) ,
0.5 * ( 1 + V_117 / 8 ) * pow ( 2 , V_118 ) , V_2 ) ;
} else {
F_2 ( V_1 , V_3 , L_66 ) ;
}
}
static void
F_154 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_1 , V_3 , L_46 , ( T_3 ) V_2 * 0.04 , ( T_3 ) V_2 ) ;
}
static void
F_155 ( T_1 * V_1 , T_2 V_2 )
{
double V_121 = ( double ) V_2 * pow ( 2 , - 10 ) ;
F_2 ( V_1 , V_3 , L_67 , V_121 , V_2 ) ;
}
static void
F_156 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_1 , V_3 , L_68 , V_2 - 140 , V_2 ) ;
}
static void
F_157 ( T_1 * V_1 , T_2 V_2 )
{
if ( V_2 == 0 ) {
F_2 ( V_1 , V_3 , L_69 ) ;
} else if ( V_2 < 34 ) {
F_2 ( V_1 , V_3 , L_70 , ( ( float ) V_2 / 2 ) - 20 , ( ( ( float ) V_2 + 1 ) / 2 ) - 20 , V_2 ) ;
} else {
F_2 ( V_1 , V_3 , L_71 ) ;
}
}
static void
F_158 ( T_1 * V_1 , T_2 V_2 )
{
if ( V_2 == 0 ) {
F_2 ( V_1 , V_3 , L_72 ) ;
} else if ( V_2 < 2048 ) {
F_2 ( V_1 , V_3 , L_73 , V_2 * 2 , ( V_2 + 1 ) * 2 , V_2 ) ;
} else if ( V_2 < 4095 ) {
F_2 ( V_1 , V_3 , L_73 , ( V_2 * 8 ) - 12288 , ( ( V_2 + 1 ) * 8 ) - 12288 , V_2 ) ;
} else {
F_2 ( V_1 , V_3 , L_74 ) ;
}
}
static int F_159 ( T_5 * V_122 , T_6 * V_123 , T_7 * V_124 , void * T_8 V_125 ) {
T_7 * V_126 ;
T_9 * V_127 ;
V_127 = F_160 ( V_124 , V_128 , V_122 , 0 , - 1 , V_129 ) ;
F_161 ( V_123 -> V_130 , V_131 , L_75 , L_76 ) ;
V_126 = F_162 ( V_127 , V_132 ) ;
return F_163 ( V_122 , V_123 , V_126 , NULL ) ;
}
void F_164 ( void ) {
static T_10 V_133 [] = {
#include "packet-lpp-hfarr.c"
{ & V_134 ,
{ L_77 , L_78 ,
V_135 , V_136 , F_165 ( V_137 ) , 0 ,
NULL , V_138 } } ,
{ & V_139 ,
{ L_79 , L_80 ,
V_135 , V_136 , F_165 ( V_137 ) , 0 ,
NULL , V_138 } } ,
{ & V_140 ,
{ L_77 , L_81 ,
V_135 , V_136 , F_165 ( V_137 ) , 0 ,
NULL , V_138 } } ,
{ & V_141 ,
{ L_79 , L_82 ,
V_135 , V_136 , F_165 ( V_137 ) , 0 ,
NULL , V_138 } } ,
{ & V_142 ,
{ L_83 , L_84 ,
V_135 , V_136 , F_165 ( V_137 ) , 0 ,
NULL , V_138 } } ,
{ & V_143 ,
{ L_85 , L_86 ,
V_144 , V_145 , F_166 ( & V_146 ) , 0 ,
NULL , V_138 } } ,
{ & V_147 ,
{ L_87 , L_88 ,
V_144 , V_145 , F_166 ( & V_148 ) , 0 ,
NULL , V_138 } } ,
{ & V_149 ,
{ L_89 , L_90 ,
V_144 , V_145 , F_166 ( & V_148 ) , 0 ,
NULL , V_138 } } ,
{ & V_150 ,
{ L_91 , L_92 ,
V_144 , V_145 , F_166 ( & V_151 ) , 0 ,
NULL , V_138 } }
} ;
static V_91 * V_152 [] = {
& V_132 ,
& V_153 ,
& V_154 ,
& V_155 ,
& V_156 ,
& V_157 ,
#include "packet-lpp-ettarr.c"
} ;
V_128 = F_167 ( V_158 , V_159 , V_160 ) ;
F_168 ( L_93 , F_159 , V_128 ) ;
F_169 ( V_128 , V_133 , F_170 ( V_133 ) ) ;
F_171 ( V_152 , F_170 ( V_152 ) ) ;
}
void
F_172 ( void )
{
V_161 = F_173 ( L_94 ) ;
}
