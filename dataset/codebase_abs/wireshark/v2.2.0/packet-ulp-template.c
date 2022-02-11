static void
F_1 ( T_1 * V_1 , T_2 V_2 )
{
if ( V_2 == 15 ) {
F_2 ( V_1 , V_3 , L_1 ) ;
} else {
double V_4 = ( 0.1 * pow ( 2 , ( double ) V_2 ) ) ;
F_2 ( V_1 , V_3 , L_2 , V_4 , V_2 ) ;
}
}
static void
F_3 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_1 , V_3 , L_3 , 4 * V_2 , V_2 ) ;
}
static void
F_4 ( T_1 * V_1 , T_2 V_2 )
{
double V_5 = ( ( double ) V_2 * 90 ) / pow ( 2 , 23 ) ;
F_2 ( V_1 , V_3 , L_4 , V_5 , V_2 ) ;
}
static void
F_5 ( T_1 * V_1 , T_2 V_2 )
{
double V_6 = ( ( double ) ( V_7 ) V_2 * 360 ) / pow ( 2 , 24 ) ;
F_2 ( V_1 , V_3 , L_4 , V_6 , V_2 ) ;
}
static void
F_6 ( T_1 * V_1 , T_2 V_2 )
{
if ( V_2 == 0 ) {
F_2 ( V_1 , V_3 , L_5 ) ;
} else if ( V_2 == 63 ) {
F_2 ( V_1 , V_3 , L_6 ) ;
} else {
F_2 ( V_1 , V_3 , L_7 , - 111 + V_2 , - 110 + V_2 , V_2 ) ;
}
}
static void
F_7 ( T_1 * V_1 , T_2 V_2 )
{
if ( V_2 == 0 ) {
F_2 ( V_1 , V_3 , L_8 ) ;
} else if ( V_2 == 76 ) {
F_2 ( V_1 , V_3 , L_9 ) ;
} else if ( V_2 > 76 ) {
F_2 ( V_1 , V_3 , L_10 , V_2 ) ;
} else {
F_2 ( V_1 , V_3 , L_11 , - 101 + V_2 , - 100 + V_2 , V_2 ) ;
}
}
static void
F_8 ( T_1 * V_1 , T_2 V_2 )
{
if ( V_2 == 0 ) {
F_2 ( V_1 , V_3 , L_12 ) ;
} else if ( V_2 == 91 ) {
F_2 ( V_1 , V_3 , L_13 ) ;
} else if ( V_2 > 91 ) {
F_2 ( V_1 , V_3 , L_10 , V_2 ) ;
} else {
F_2 ( V_1 , V_3 , L_14 , - 116 + V_2 , - 115 + V_2 , V_2 ) ;
}
}
static void
F_9 ( T_1 * V_1 , T_2 V_2 )
{
if ( V_2 == 0 ) {
F_2 ( V_1 , V_3 , L_15 ) ;
} else if ( V_2 == 49 ) {
F_2 ( V_1 , V_3 , L_16 ) ;
} else if ( V_2 > 49 ) {
F_2 ( V_1 , V_3 , L_10 , V_2 ) ;
} else {
F_2 ( V_1 , V_3 , L_17 , - 24.5 + ( ( float ) V_2 / 2 ) , - 24 + ( ( float ) V_2 / 2 ) , V_2 ) ;
}
}
static void
F_10 ( T_1 * V_1 , T_2 V_2 )
{
if ( V_2 == 123 ) {
F_2 ( V_1 , V_3 , L_18 ) ;
} else if ( V_2 > 123 ) {
F_2 ( V_1 , V_3 , L_19 , - 244 + V_2 , - 243 + V_2 , V_2 ) ;
} else if ( V_2 == 91 ) {
F_2 ( V_1 , V_3 , L_20 ) ;
} else if ( V_2 < 91 ) {
F_2 ( V_1 , V_3 , L_21 , - 116 + V_2 , - 115 + V_2 , V_2 ) ;
} else {
F_2 ( V_1 , V_3 , L_10 , V_2 ) ;
}
}
static void
F_11 ( T_1 * V_1 , T_2 V_2 )
{
double V_8 = 10 * ( pow ( 1.1 , ( double ) V_2 ) - 1 ) ;
if ( V_8 < 1000 ) {
F_2 ( V_1 , V_3 , L_22 , V_8 , V_2 ) ;
} else {
F_2 ( V_1 , V_3 , L_23 , V_8 / 1000 , V_2 ) ;
}
}
static void
F_12 ( T_1 * V_1 , T_2 V_2 )
{
double V_8 = 45 * ( pow ( 1.025 , ( double ) V_2 ) - 1 ) ;
F_2 ( V_1 , V_3 , L_22 , V_8 , V_2 ) ;
}
static void
F_13 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_1 , V_3 , L_2 , pow ( 2 , ( double ) V_2 ) , V_2 ) ;
}
static void
F_14 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_1 , V_3 , L_24 , 0.01 * V_2 , V_2 ) ;
}
static void
F_15 ( T_1 * V_1 , T_2 V_2 )
{
if ( V_2 == 0 ) {
F_2 ( V_1 , V_3 , L_25 ) ;
} else if ( V_2 == 97 ) {
F_2 ( V_1 , V_3 , L_26 ) ;
} else {
F_2 ( V_1 , V_3 , L_27 , - 141 + V_2 , - 140 + V_2 , V_2 ) ;
}
}
static void
F_16 ( T_1 * V_1 , T_2 V_2 )
{
if ( V_2 == 0 ) {
F_2 ( V_1 , V_3 , L_28 ) ;
} else if ( V_2 == 64 ) {
F_2 ( V_1 , V_3 , L_29 ) ;
} else {
F_2 ( V_1 , V_3 , L_30 , - 20 + ( ( float ) V_2 / 2 ) , - 19.5 + ( ( float ) V_2 / 2 ) , V_2 ) ;
}
}
static void
F_17 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_1 , V_3 , L_31 , V_2 ? L_32 : L_33 , V_2 ) ;
}
static void
F_18 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_1 , V_3 , L_34 , 0.1 * V_2 , V_2 ) ;
}
static void
F_19 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_1 , V_3 , L_35 , 0.01 * V_2 , V_2 ) ;
}
static void
F_20 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_1 , V_3 , L_36 , - 103.75 + ( 0.25 * V_2 ) , V_2 ) ;
}
static void
F_21 ( T_1 * V_1 , T_2 V_2 )
{
double V_8 = 0.0022 * ( pow ( 1.18 , ( double ) V_2 ) - 1 ) ;
F_2 ( V_1 , V_3 , L_37 , V_8 , V_2 ) ;
}
static void
F_22 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_1 , V_3 , L_35 , 0.25 * V_2 , V_2 ) ;
}
static void
F_23 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( V_1 , V_3 , L_38 ,
( ( float ) V_2 / 8388607.0 ) * 90 , V_2 ) ;
}
static void
F_24 ( T_1 * V_1 , T_2 V_2 )
{
V_7 V_6 = ( V_7 ) V_2 ;
F_2 ( V_1 , V_3 , L_39 ,
( ( float ) V_6 / 8388608.0 ) * 180 , V_6 ) ;
}
static T_3 * F_25 ( T_4 * V_9 )
{
if ( V_9 -> V_10 == NULL ) {
V_9 -> V_10 = F_26 ( F_27 () , T_3 ) ;
}
return ( T_3 * ) V_9 -> V_10 ;
}
static T_5
F_28 ( T_6 * T_7 V_11 , T_8 * V_12 , int V_13 , void * T_9 V_11 )
{
return F_29 ( V_12 , V_13 ) ;
}
static int
F_30 ( T_8 * V_12 , T_6 * T_7 , T_10 * V_14 , void * T_9 )
{
F_31 ( V_12 , T_7 , V_14 , V_15 , V_16 ,
F_28 , V_17 , T_9 ) ;
return F_32 ( V_12 ) ;
}
void F_33 ( void ) {
static T_11 V_18 [] = {
#include "packet-ulp-hfarr.c"
{ & V_19 ,
{ L_40 , L_41 ,
V_20 , V_21 , NULL , 0 ,
NULL , V_22 } } ,
{ & V_23 ,
{ L_42 , L_43 ,
V_24 , 16 , F_34 ( & V_25 ) , 0x8000 ,
NULL , V_22 } } ,
{ & V_26 ,
{ L_44 , L_45 ,
V_24 , 16 , F_34 ( & V_25 ) , 0x4000 ,
NULL , V_22 } } ,
{ & V_27 ,
{ L_46 , L_47 ,
V_24 , 16 , F_34 ( & V_25 ) , 0x2000 ,
NULL , V_22 } } ,
{ & V_28 ,
{ L_48 , L_49 ,
V_24 , 16 , F_34 ( & V_25 ) , 0x1000 ,
NULL , V_22 } } ,
{ & V_29 ,
{ L_50 , L_51 ,
V_24 , 16 , F_34 ( & V_25 ) , 0x0800 ,
NULL , V_22 } } ,
{ & V_30 ,
{ L_52 , L_53 ,
V_31 , V_32 , NULL , 0x07ff ,
NULL , V_22 } } ,
} ;
static T_12 * V_33 [] = {
& V_34 ,
& V_35 ,
& V_36 ,
& V_37 ,
#include "packet-ulp-ettarr.c"
} ;
T_13 * V_38 ;
V_39 = F_35 ( V_40 , V_41 , V_42 ) ;
V_43 = F_36 ( L_54 , F_30 , V_39 ) ;
F_37 ( V_39 , V_18 , F_38 ( V_18 ) ) ;
F_39 ( V_33 , F_38 ( V_33 ) ) ;
V_38 = F_40 ( V_39 , V_44 ) ;
F_41 ( V_38 , L_55 ,
L_56 ,
L_57
L_58 ,
& V_15 ) ;
F_42 ( V_38 , L_59 ,
L_60 ,
L_61 ,
10 ,
& V_45 ) ;
F_42 ( V_38 , L_62 ,
L_63 ,
L_64 ,
10 ,
& V_46 ) ;
}
void
V_44 ( void )
{
static T_14 V_47 = FALSE ;
static T_15 V_48 ;
static T_5 V_49 , V_50 ;
if ( ! V_47 ) {
F_43 ( L_65 , L_66 , V_43 ) ;
F_43 ( L_65 , L_67 , V_43 ) ;
V_48 = F_44 ( V_17 , V_39 ) ;
V_51 = F_45 ( L_68 , V_39 ) ;
V_52 = F_45 ( L_69 , V_39 ) ;
V_47 = TRUE ;
} else {
F_46 ( L_59 , V_49 , V_43 ) ;
F_46 ( L_62 , V_50 , V_48 ) ;
}
V_49 = V_45 ;
F_47 ( L_59 , V_45 , V_43 ) ;
V_50 = V_46 ;
F_47 ( L_62 , V_46 , V_48 ) ;
}
