static void
F_1 (
T_1 * V_1 ,
const int V_2 ,
T_2 * V_3 ,
T_3 V_4 )
{
T_4 V_5 = F_2 ( V_3 , V_4 ) ;
char * V_6 = ( char * ) F_3 ( F_4 () , V_7 ) ;
T_5 V_8 , V_9 , V_10 , V_11 , V_12 ;
V_12 = ( T_5 ) ( V_5 % F_5 ( 1000000000 ) ) ;
V_8 = ( T_5 ) ( V_5 / F_5 ( 1000000000 ) ) ;
V_9 = V_8 / 3600 ;
V_10 = ( V_8 % 3600 ) / 60 ;
V_11 = V_8 % 60 ;
F_6 ( V_6 , V_7 ,
L_1 ,
V_9 , V_10 , V_11 , V_12 ) ;
F_7 ( V_1 , V_2 , V_3 , V_4 , 8 , V_6 ) ;
}
static void
F_8 (
T_6 * V_6 ,
T_5 V_13 )
{
F_6 ( V_6 , V_7 ,
L_2 ,
F_9 ( V_13 , V_14 , L_3 ) ,
V_13 ) ;
}
static void
F_10 (
T_6 * V_6 ,
T_5 V_13 )
{
F_6 ( V_6 , V_7 ,
L_2 ,
F_9 ( V_13 ,
V_15 ,
L_3 ) ,
V_13 ) ;
}
static void
F_11 (
T_6 * V_6 ,
T_5 V_13 )
{
F_6 ( V_6 , V_7 ,
L_2 ,
F_9 ( V_13 ,
V_16 ,
L_3 ) ,
V_13 ) ;
}
static void
F_12 (
T_6 * V_6 ,
T_5 V_13 )
{
F_6 ( V_6 , V_7 ,
L_2 ,
F_9 ( V_13 , V_17 , L_3 ) ,
V_13 ) ;
}
static void
F_13 (
T_6 * V_6 ,
T_5 V_13 )
{
F_6 ( V_6 , V_7 ,
L_2 ,
F_9 ( V_13 , V_18 , L_3 ) ,
V_13 ) ;
}
static void
F_14 (
char * V_6 ,
T_5 V_13 )
{
F_6 ( V_6 , V_7 ,
L_2 ,
F_9 ( V_13 , V_19 , L_3 ) ,
V_13 ) ;
}
static void
F_15 (
char * V_6 ,
T_5 V_13 )
{
F_6 ( V_6 , V_7 ,
L_2 ,
F_9 ( V_13 , V_20 , L_3 ) ,
V_13 ) ;
}
static void
F_16 (
char * V_6 ,
T_5 V_13 )
{
F_6 ( V_6 , V_7 ,
L_2 ,
F_9 ( V_13 , V_21 , L_3 ) ,
V_13 ) ;
}
static void
F_17 (
char * V_6 ,
T_5 V_13 )
{
F_6 ( V_6 , V_7 ,
L_2 ,
F_9 ( V_13 , V_22 , L_3 ) ,
V_13 ) ;
}
static void
F_18 (
char * V_6 ,
T_5 V_13 )
{
F_6 ( V_6 , V_7 ,
L_2 ,
F_9 ( V_13 , V_23 , L_3 ) ,
V_13 ) ;
}
static void
F_19 (
char * V_6 ,
T_5 V_13 )
{
F_6 ( V_6 , V_7 ,
L_2 ,
F_9 ( V_13 , V_24 , L_3 ) ,
V_13 ) ;
}
static void
F_20 (
char * V_6 ,
T_5 V_13 )
{
F_6 ( V_6 , V_7 ,
L_2 ,
F_9 ( V_13 , V_25 , L_3 ) ,
V_13 ) ;
}
static void
F_21 (
char * V_6 ,
T_5 V_13 )
{
F_6 ( V_6 , V_7 ,
L_2 ,
F_9 ( V_13 , V_26 , L_3 ) ,
V_13 ) ;
}
static void
F_22 (
char * V_6 ,
T_5 V_13 )
{
if ( V_13 == 0x7fffffff ) {
F_6 ( V_6 , V_7 , L_4 , L_5 ) ;
} else {
F_6 ( V_6 , V_7 ,
L_6 ,
V_13 / 10000 , V_13 % 10000 ) ;
}
}
static void
F_23 (
char * V_6 ,
T_5 V_13 )
{
F_6 ( V_6 , V_7 ,
L_2 ,
F_9 ( V_13 ,
V_27 ,
L_3 ) ,
V_13 ) ;
}
static void
F_24 (
char * V_6 ,
T_5 V_13 )
{
F_6 ( V_6 , V_7 ,
L_2 ,
F_9 ( V_13 ,
V_28 ,
L_3 ) ,
V_13 ) ;
}
static void
F_25 (
char * V_6 ,
T_5 V_13 )
{
F_6 ( V_6 , V_7 ,
L_2 ,
F_9 ( V_13 , V_29 , L_3 ) ,
V_13 ) ;
}
static void
F_26 (
T_6 * V_6 ,
T_5 V_13 )
{
T_5 V_9 ;
T_5 V_10 ;
T_5 V_11 ;
switch ( V_13 ) {
case 0 :
F_6 ( V_6 , V_7 , L_7 , V_13 ) ;
break;
case 99998 :
F_6 ( V_6 , V_7 , L_8 , V_13 ) ;
break;
case 99999 :
F_6 ( V_6 , V_7 , L_9 , V_13 ) ;
break;
default:
V_9 = V_13 / 3600 ;
V_10 = ( V_13 % 3600 ) / 60 ;
V_11 = V_13 % 60 ;
F_6 ( V_6 , V_7 ,
L_10 ,
V_9 , V_10 , V_11 ,
V_13 ) ;
break;
}
}
static void
F_27 (
char * V_6 ,
T_5 V_13 )
{
F_6 ( V_6 , V_7 ,
L_2 ,
F_9 ( V_13 ,
V_30 ,
L_3 ) ,
V_13 ) ;
}
static int
F_28 (
T_2 * V_3 ,
T_7 * V_31 ,
T_1 * V_1 ,
void * T_8 V_32 )
{
T_9 * V_33 ;
T_1 * V_34 = NULL ;
const char * V_35 ;
T_10 V_36 ;
T_11 V_37 ;
int V_4 = 0 ;
V_37 = F_29 ( V_3 , V_4 ) ;
V_36 = F_30 ( V_3 ) ;
if ( V_37 == 'U' && ( V_36 == 79 || V_36 == 80 ) ) {
V_37 = 'R' ;
}
if ( V_37 == 'M' && V_36 == 28 ) {
V_37 = 'm' ;
}
V_35 = F_31 ( V_37 , V_14 , L_11 ) ;
F_32 ( V_31 -> V_38 , V_39 , L_12 ) ;
F_33 ( V_31 -> V_38 , V_40 , V_35 ) ;
if ( V_1 ) {
V_33 = F_34 ( V_1 ,
V_41 ,
V_3 , 0 , - 1 , V_42 ) ;
V_34 = F_35 ( V_33 , V_43 ) ;
F_36 ( V_33 , L_13 , V_35 ) ;
F_34 ( V_34 , V_44 ,
V_3 , V_4 , 1 , V_42 ) ;
V_4 += 1 ;
switch ( V_37 ) {
case 'O' :
F_34 ( V_34 ,
V_45 ,
V_3 , V_4 , 14 ,
V_46 | V_42 ) ;
V_4 += 14 ;
F_34 ( V_34 ,
V_47 ,
V_3 , V_4 , 1 ,
V_48 ) ;
V_4 += 1 ;
F_34 ( V_34 ,
V_49 ,
V_3 , V_4 , 4 ,
V_48 ) ;
V_4 += 4 ;
F_34 ( V_34 ,
V_50 ,
V_3 , V_4 , 8 ,
V_46 | V_42 ) ;
V_4 += 8 ;
F_34 ( V_34 ,
V_51 ,
V_3 , V_4 , 4 ,
V_48 ) ;
V_4 += 4 ;
F_34 ( V_34 ,
V_52 ,
V_3 , V_4 , 4 ,
V_48 ) ;
V_4 += 4 ;
F_34 ( V_34 ,
V_53 ,
V_3 , V_4 , 4 ,
V_46 | V_42 ) ;
V_4 += 4 ;
F_34 ( V_34 ,
V_54 ,
V_3 , V_4 , 1 ,
V_48 ) ;
V_4 += 1 ;
F_34 ( V_34 ,
V_55 ,
V_3 , V_4 , 1 ,
V_48 ) ;
V_4 += 1 ;
F_34 ( V_34 ,
V_56 ,
V_3 , V_4 , 1 ,
V_48 ) ;
V_4 += 1 ;
F_34 ( V_34 ,
V_57 ,
V_3 , V_4 , 4 ,
V_48 ) ;
V_4 += 4 ;
F_34 ( V_34 ,
V_58 ,
V_3 , V_4 , 1 ,
V_48 ) ;
V_4 += 1 ;
if ( V_36 >= 49 ) {
F_34 ( V_34 ,
V_59 ,
V_3 , V_4 , 1 ,
V_48 ) ;
V_4 += 1 ;
}
break;
case 'A' :
F_1 ( V_34 ,
V_60 ,
V_3 , V_4 ) ;
V_4 += 8 ;
F_34 ( V_34 ,
V_45 ,
V_3 , V_4 , 14 ,
V_46 | V_42 ) ;
V_4 += 14 ;
F_34 ( V_34 ,
V_47 ,
V_3 , V_4 , 1 ,
V_48 ) ;
V_4 += 1 ;
F_34 ( V_34 ,
V_49 ,
V_3 , V_4 , 4 ,
V_48 ) ;
V_4 += 4 ;
F_34 ( V_34 ,
V_50 ,
V_3 , V_4 , 8 ,
V_46 | V_42 ) ;
V_4 += 8 ;
F_34 ( V_34 ,
V_51 ,
V_3 , V_4 , 4 ,
V_48 ) ;
V_4 += 4 ;
F_34 ( V_34 ,
V_52 ,
V_3 , V_4 , 4 ,
V_48 ) ;
V_4 += 4 ;
F_34 ( V_34 ,
V_53 ,
V_3 , V_4 , 4 ,
V_46 | V_42 ) ;
V_4 += 4 ;
F_34 ( V_34 ,
V_54 ,
V_3 , V_4 , 1 ,
V_48 ) ;
V_4 += 1 ;
F_34 ( V_34 ,
V_61 ,
V_3 , V_4 , 8 ,
V_48 ) ;
V_4 += 8 ;
F_34 ( V_34 ,
V_55 ,
V_3 , V_4 , 1 ,
V_48 ) ;
V_4 += 1 ;
F_34 ( V_34 ,
V_56 ,
V_3 , V_4 , 1 ,
V_48 ) ;
V_4 += 1 ;
F_34 ( V_34 ,
V_57 ,
V_3 , V_4 , 4 ,
V_48 ) ;
V_4 += 4 ;
F_34 ( V_34 ,
V_58 ,
V_3 , V_4 , 1 ,
V_48 ) ;
V_4 += 1 ;
F_34 ( V_34 ,
V_62 ,
V_3 , V_4 , 1 ,
V_48 ) ;
V_4 += 1 ;
if ( V_36 >= 66 ) {
F_34 ( V_34 ,
V_63 ,
V_3 , V_4 , 1 ,
V_48 ) ;
V_4 += 1 ;
}
break;
case 'U' :
F_34 ( V_34 ,
V_64 ,
V_3 , V_4 , 14 ,
V_46 | V_42 ) ;
V_4 += 14 ;
F_34 ( V_34 ,
V_65 ,
V_3 , V_4 , 14 ,
V_46 | V_42 ) ;
V_4 += 14 ;
F_34 ( V_34 ,
V_49 ,
V_3 , V_4 , 4 ,
V_48 ) ;
V_4 += 4 ;
F_34 ( V_34 ,
V_51 ,
V_3 , V_4 , 4 ,
V_48 ) ;
V_4 += 4 ;
F_34 ( V_34 ,
V_52 ,
V_3 , V_4 , 4 ,
V_48 ) ;
V_4 += 4 ;
F_34 ( V_34 ,
V_54 ,
V_3 , V_4 , 1 ,
V_48 ) ;
V_4 += 1 ;
F_34 ( V_34 ,
V_56 ,
V_3 , V_4 , 1 ,
V_48 ) ;
V_4 += 1 ;
F_34 ( V_34 ,
V_57 ,
V_3 , V_4 , 4 ,
V_48 ) ;
V_4 += 4 ;
break;
case 'X' :
F_34 ( V_34 ,
V_45 ,
V_3 , V_4 , 14 ,
V_46 | V_42 ) ;
V_4 += 14 ;
F_34 ( V_34 ,
V_49 ,
V_3 , V_4 , 4 ,
V_48 ) ;
V_4 += 4 ;
break;
case 'M' :
F_34 ( V_34 ,
V_45 ,
V_3 , V_4 , 14 ,
V_46 | V_42 ) ;
V_4 += 14 ;
F_34 ( V_34 ,
V_47 ,
V_3 , V_4 , 1 ,
V_48 ) ;
V_4 += 1 ;
F_34 ( V_34 ,
V_49 ,
V_3 , V_4 , 4 ,
V_48 ) ;
V_4 += 4 ;
break;
case 'S' :
F_1 ( V_34 ,
V_60 ,
V_3 , V_4 ) ;
V_4 += 8 ;
F_34 ( V_34 ,
V_66 ,
V_3 , V_4 , 1 ,
V_46 ) ;
V_4 += 1 ;
break;
case 'R' :
F_1 ( V_34 ,
V_60 ,
V_3 , V_4 ) ;
V_4 += 8 ;
F_34 ( V_34 ,
V_65 ,
V_3 , V_4 , 14 ,
V_46 | V_42 ) ;
V_4 += 14 ;
F_34 ( V_34 ,
V_47 ,
V_3 , V_4 , 1 ,
V_48 ) ;
V_4 += 1 ;
F_34 ( V_34 ,
V_49 ,
V_3 , V_4 , 4 ,
V_48 ) ;
V_4 += 4 ;
F_34 ( V_34 ,
V_50 ,
V_3 , V_4 , 8 ,
V_46 | V_42 ) ;
V_4 += 8 ;
F_34 ( V_34 ,
V_51 ,
V_3 , V_4 , 4 ,
V_48 ) ;
V_4 += 4 ;
F_34 ( V_34 ,
V_52 ,
V_3 , V_4 , 4 ,
V_48 ) ;
V_4 += 4 ;
F_34 ( V_34 ,
V_53 ,
V_3 , V_4 , 4 ,
V_46 | V_42 ) ;
V_4 += 4 ;
F_34 ( V_34 ,
V_54 ,
V_3 , V_4 , 1 ,
V_48 ) ;
V_4 += 1 ;
F_34 ( V_34 ,
V_61 ,
V_3 , V_4 , 8 ,
V_48 ) ;
V_4 += 8 ;
F_34 ( V_34 ,
V_55 ,
V_3 , V_4 , 1 ,
V_48 ) ;
V_4 += 1 ;
F_34 ( V_34 ,
V_56 ,
V_3 , V_4 , 1 ,
V_48 ) ;
V_4 += 1 ;
F_34 ( V_34 ,
V_57 ,
V_3 , V_4 , 4 ,
V_48 ) ;
V_4 += 4 ;
F_34 ( V_34 ,
V_58 ,
V_3 , V_4 , 1 ,
V_48 ) ;
V_4 += 1 ;
F_34 ( V_34 ,
V_62 ,
V_3 , V_4 , 1 ,
V_48 ) ;
V_4 += 1 ;
F_34 ( V_34 ,
V_67 ,
V_3 , V_4 , 14 ,
V_46 | V_42 ) ;
V_4 += 14 ;
if ( V_36 >= 80 ) {
F_34 ( V_34 ,
V_63 ,
V_3 , V_4 , 1 ,
V_48 ) ;
V_4 += 1 ;
}
break;
case 'C' :
F_1 ( V_34 ,
V_60 ,
V_3 , V_4 ) ;
V_4 += 8 ;
F_34 ( V_34 ,
V_45 ,
V_3 , V_4 , 14 ,
V_46 | V_42 ) ;
V_4 += 14 ;
F_34 ( V_34 ,
V_68 ,
V_3 , V_4 , 4 ,
V_48 ) ;
V_4 += 4 ;
F_34 ( V_34 ,
V_69 ,
V_3 , V_4 , 1 ,
V_48 ) ;
V_4 += 1 ;
break;
case 'D' :
F_1 ( V_34 ,
V_60 ,
V_3 , V_4 ) ;
V_4 += 8 ;
F_34 ( V_34 ,
V_45 ,
V_3 , V_4 , 14 ,
V_46 | V_42 ) ;
V_4 += 14 ;
F_34 ( V_34 ,
V_68 ,
V_3 , V_4 , 4 ,
V_48 ) ;
V_4 += 4 ;
F_34 ( V_34 ,
V_69 ,
V_3 , V_4 , 1 ,
V_48 ) ;
V_4 += 1 ;
F_34 ( V_34 ,
V_70 ,
V_3 , V_4 , 4 ,
V_48 ) ;
V_4 += 4 ;
F_34 ( V_34 ,
V_71 ,
V_3 , V_4 , 4 ,
V_48 ) ;
V_4 += 4 ;
F_34 ( V_34 ,
V_72 ,
V_3 , V_4 , 1 ,
V_48 ) ;
V_4 += 1 ;
break;
case 'E' :
F_1 ( V_34 ,
V_60 ,
V_3 , V_4 ) ;
V_4 += 8 ;
F_34 ( V_34 ,
V_45 ,
V_3 , V_4 , 14 ,
V_46 | V_42 ) ;
V_4 += 14 ;
F_34 ( V_34 ,
V_73 ,
V_3 , V_4 , 4 ,
V_48 ) ;
V_4 += 4 ;
F_34 ( V_34 ,
V_71 ,
V_3 , V_4 , 4 ,
V_48 ) ;
V_4 += 4 ;
F_34 ( V_34 ,
V_72 ,
V_3 , V_4 , 1 ,
V_48 ) ;
V_4 += 1 ;
F_34 ( V_34 ,
V_74 ,
V_3 , V_4 , 8 ,
V_48 ) ;
V_4 += 8 ;
break;
case 'B' :
F_1 ( V_34 ,
V_60 ,
V_3 , V_4 ) ;
V_4 += 8 ;
F_34 ( V_34 ,
V_45 ,
V_3 , V_4 , 14 ,
V_46 | V_42 ) ;
V_4 += 14 ;
F_34 ( V_34 ,
V_74 ,
V_3 , V_4 , 8 ,
V_48 ) ;
V_4 += 8 ;
F_34 ( V_34 ,
V_75 ,
V_3 , V_4 , 1 ,
V_48 ) ;
V_4 += 1 ;
break;
case 'F' :
F_1 ( V_34 ,
V_60 ,
V_3 , V_4 ) ;
V_4 += 8 ;
F_34 ( V_34 ,
V_45 ,
V_3 , V_4 , 14 ,
V_46 | V_42 ) ;
V_4 += 14 ;
F_34 ( V_34 ,
V_73 ,
V_3 , V_4 , 4 ,
V_48 ) ;
V_4 += 4 ;
F_34 ( V_34 ,
V_71 ,
V_3 , V_4 , 4 ,
V_48 ) ;
V_4 += 4 ;
F_34 ( V_34 ,
V_72 ,
V_3 , V_4 , 1 ,
V_48 ) ;
V_4 += 1 ;
F_34 ( V_34 ,
V_74 ,
V_3 , V_4 , 8 ,
V_48 ) ;
V_4 += 8 ;
F_34 ( V_34 ,
V_76 ,
V_3 , V_4 , 1 ,
V_48 ) ;
V_4 += 1 ;
break;
case 'G' :
F_1 ( V_34 ,
V_60 ,
V_3 , V_4 ) ;
V_4 += 8 ;
F_34 ( V_34 ,
V_45 ,
V_3 , V_4 , 14 ,
V_46 | V_42 ) ;
V_4 += 14 ;
F_34 ( V_34 ,
V_73 ,
V_3 , V_4 , 4 ,
V_48 ) ;
V_4 += 4 ;
F_34 ( V_34 ,
V_71 ,
V_3 , V_4 , 4 ,
V_48 ) ;
V_4 += 4 ;
F_34 ( V_34 ,
V_72 ,
V_3 , V_4 , 1 ,
V_48 ) ;
V_4 += 1 ;
F_34 ( V_34 ,
V_74 ,
V_3 , V_4 , 8 ,
V_48 ) ;
V_4 += 8 ;
F_34 ( V_34 ,
V_77 ,
V_3 , V_4 , 4 ,
V_48 ) ;
V_4 += 4 ;
F_34 ( V_34 ,
V_78 ,
V_3 , V_4 , 1 ,
V_48 ) ;
V_4 += 1 ;
break;
case 'K' :
F_1 ( V_34 ,
V_60 ,
V_3 , V_4 ) ;
V_4 += 8 ;
F_34 ( V_34 ,
V_45 ,
V_3 , V_4 , 14 ,
V_46 | V_42 ) ;
V_4 += 14 ;
F_34 ( V_34 ,
V_74 ,
V_3 , V_4 , 8 ,
V_48 ) ;
V_4 += 8 ;
F_34 ( V_34 ,
V_79 ,
V_3 , V_4 , 4 ,
V_48 ) ;
V_4 += 4 ;
F_34 ( V_34 ,
V_80 ,
V_3 , V_4 , 1 ,
V_48 ) ;
V_4 += 1 ;
break;
case 'J' :
F_1 ( V_34 ,
V_60 ,
V_3 , V_4 ) ;
V_4 += 8 ;
F_34 ( V_34 ,
V_45 ,
V_3 , V_4 , 14 ,
V_46 | V_42 ) ;
V_4 += 14 ;
F_34 ( V_34 ,
V_81 ,
V_3 , V_4 , 1 ,
V_48 ) ;
V_4 += 1 ;
break;
case 'P' :
F_1 ( V_34 ,
V_60 ,
V_3 , V_4 ) ;
V_4 += 8 ;
F_34 ( V_34 ,
V_45 ,
V_3 , V_4 , 14 ,
V_46 | V_42 ) ;
V_4 += 14 ;
break;
case 'I' :
F_1 ( V_34 ,
V_60 ,
V_3 , V_4 ) ;
V_4 += 8 ;
F_34 ( V_34 ,
V_45 ,
V_3 , V_4 , 14 ,
V_46 | V_42 ) ;
V_4 += 14 ;
break;
case 'T' :
F_1 ( V_34 ,
V_60 ,
V_3 , V_4 ) ;
V_4 += 8 ;
F_34 ( V_34 ,
V_45 ,
V_3 , V_4 , 14 ,
V_46 | V_42 ) ;
V_4 += 14 ;
F_34 ( V_34 ,
V_51 ,
V_3 , V_4 , 4 ,
V_48 ) ;
V_4 += 4 ;
F_34 ( V_34 ,
V_54 ,
V_3 , V_4 , 1 ,
V_48 ) ;
V_4 += 1 ;
F_34 ( V_34 ,
V_61 ,
V_3 , V_4 , 8 ,
V_48 ) ;
V_4 += 8 ;
break;
case 'm' :
F_1 ( V_34 ,
V_60 ,
V_3 , V_4 ) ;
V_4 += 8 ;
F_34 ( V_34 ,
V_45 ,
V_3 , V_4 , 14 ,
V_46 | V_42 ) ;
V_4 += 14 ;
F_34 ( V_34 ,
V_47 ,
V_3 , V_4 , 1 ,
V_48 ) ;
V_4 += 1 ;
F_34 ( V_34 ,
V_49 ,
V_3 , V_4 , 4 ,
V_48 ) ;
V_4 += 4 ;
break;
default:
F_34 ( V_1 ,
V_82 ,
V_3 , V_4 , - 1 , V_42 ) ;
V_4 += V_36 - 1 ;
break;
}
}
return V_4 ;
}
static void
F_37 ( void )
{
F_38 ( L_14 , V_83 , V_84 ) ;
F_39 ( V_83 ) ;
V_83 = F_40 ( V_85 ) ;
F_41 ( L_14 , V_83 , V_84 ) ;
}
static T_12
F_42 (
T_2 * V_3 ,
T_7 * V_31 ,
T_1 * V_1 ,
void * T_8 V_32 )
{
T_11 V_86 = F_29 ( V_3 , 0 ) ;
T_13 V_87 = F_30 ( V_3 ) ;
switch ( V_86 ) {
case 'O' :
if ( V_87 != 48 && V_87 != 49 ) {
return FALSE ;
}
break;
case 'U' :
if ( V_87 != 47 && V_87 != 79 && V_87 != 80 ) {
return FALSE ;
}
break;
case 'X' :
if ( V_87 != 19 ) {
return FALSE ;
}
break;
case 'M' :
if ( V_87 != 20 && V_87 != 28 ) {
return FALSE ;
}
break;
case 'S' :
if ( V_87 != 10 ) {
return FALSE ;
}
break;
case 'A' :
if ( V_87 != 65 && V_87 != 66 ) {
return FALSE ;
}
break;
case 'C' :
if ( V_87 != 28 ) {
return FALSE ;
}
break;
case 'D' :
if ( V_87 != 37 ) {
return FALSE ;
}
break;
case 'E' :
if ( V_87 != 40 ) {
return FALSE ;
}
break;
case 'F' :
if ( V_87 != 41 ) {
return FALSE ;
}
break;
case 'G' :
if ( V_87 != 45 ) {
return FALSE ;
}
break;
case 'B' :
if ( V_87 != 32 ) {
return FALSE ;
}
break;
case 'K' :
if ( V_87 != 36 ) {
return FALSE ;
}
break;
case 'J' :
if ( V_87 != 24 ) {
return FALSE ;
}
break;
case 'P' :
if ( V_87 != 23 ) {
return FALSE ;
}
break;
case 'I' :
if ( V_87 != 23 ) {
return FALSE ;
}
break;
case 'T' :
if ( V_87 != 36 ) {
return FALSE ;
}
break;
default:
return FALSE ;
}
F_28 ( V_3 , V_31 , V_1 , NULL ) ;
return TRUE ;
}
void
F_43 ( void )
{
T_14 * V_88 ;
static T_15 V_2 [] = {
{ & V_63 ,
{ L_15 , L_16 ,
V_89 , V_90 , F_44 ( F_10 ) , 0x0 ,
NULL , V_91 } } ,
{ & V_75 ,
{ L_17 , L_18 ,
V_89 , V_90 , F_44 ( F_11 ) , 0x0 ,
NULL , V_91 } } ,
{ & V_47 ,
{ L_19 , L_20 ,
V_89 , V_90 , F_44 ( F_12 ) , 0x0 ,
NULL , V_91 } } ,
{ & V_69 ,
{ L_21 , L_22 ,
V_89 , V_90 , F_44 ( F_13 ) , 0x0 ,
NULL , V_91 } } ,
{ & V_55 ,
{ L_23 , L_24 ,
V_89 , V_90 , F_44 ( F_14 ) , 0x0 ,
NULL , V_91 } } ,
{ & V_58 ,
{ L_25 , L_26 ,
V_89 , V_90 , F_44 ( F_15 ) , 0x0 ,
NULL , V_91 } } ,
{ & V_59 ,
{ L_27 , L_28 ,
V_89 , V_90 , F_44 ( F_16 ) , 0x0 ,
NULL , V_91 } } ,
{ & V_68 ,
{ L_29 , L_30 ,
V_92 , V_93 , NULL , 0x0 ,
NULL , V_91 } } ,
{ & V_54 ,
{ L_31 , L_32 ,
V_89 , V_90 , F_44 ( F_17 ) , 0x0 ,
NULL , V_91 } } ,
{ & V_66 ,
{ L_33 , L_34 ,
V_89 , V_90 , F_44 ( F_18 ) , 0x0 ,
NULL , V_91 } } ,
{ & V_73 ,
{ L_35 , L_36 ,
V_92 , V_93 , NULL , 0x0 ,
NULL , V_91 } } ,
{ & V_71 ,
{ L_37 , L_38 ,
V_92 , V_90 , F_44 ( F_22 ) , 0x0 ,
NULL , V_91 } } ,
{ & V_64 ,
{ L_39 , L_40 ,
V_94 , V_95 , NULL , 0x0 ,
NULL , V_91 } } ,
{ & V_53 ,
{ L_41 , L_42 ,
V_94 , V_95 , NULL , 0x0 ,
NULL , V_91 } } ,
{ & V_56 ,
{ L_43 , L_44 ,
V_89 , V_90 , F_44 ( F_19 ) , 0x0 ,
NULL , V_91 } } ,
{ & V_72 ,
{ L_45 , L_46 ,
V_89 , V_90 , F_44 ( F_20 ) , 0x0 ,
NULL , V_91 } } ,
{ & V_74 ,
{ L_47 , L_48 ,
V_96 , V_93 , NULL , 0x0 ,
NULL , V_91 } } ,
{ & V_82 ,
{ L_49 , L_50 ,
V_97 , V_95 , NULL , 0x0 ,
NULL , V_91 } } ,
{ & V_57 ,
{ L_51 , L_52 ,
V_92 , V_93 , NULL , 0x0 ,
NULL , V_91 } } ,
{ & V_79 ,
{ L_53 , L_54 ,
V_92 , V_90 , F_44 ( F_22 ) , 0x0 ,
NULL , V_91 } } ,
{ & V_61 ,
{ L_55 , L_56 ,
V_96 , V_93 , NULL , 0x0 ,
NULL , V_91 } } ,
{ & V_62 ,
{ L_57 , L_58 ,
V_89 , V_90 , F_44 ( F_21 ) , 0x0 ,
NULL , V_91 } } ,
{ & V_45 ,
{ L_59 , L_60 ,
V_94 , V_95 , NULL , 0x0 ,
NULL , V_91 } } ,
{ & V_44 ,
{ L_61 , L_62 ,
V_89 , V_90 , F_44 ( F_8 ) , 0x0 ,
NULL , V_91 } } ,
{ & V_67 ,
{ L_63 , L_64 ,
V_94 , V_95 , NULL , 0x0 ,
NULL , V_91 } } ,
{ & V_51 ,
{ L_65 , L_66 ,
V_92 , V_90 , F_44 ( F_22 ) , 0x0 ,
NULL , V_91 } } ,
{ & V_80 ,
{ L_67 , L_68 ,
V_89 , V_90 , F_44 ( F_23 ) , 0x0 ,
NULL , V_91 } } ,
{ & V_70 ,
{ L_69 ,
L_70 ,
V_92 , V_93 , NULL , 0x0 ,
NULL , V_91 } } ,
{ & V_77 ,
{ L_71 , L_72 ,
V_92 , V_90 , F_44 ( F_22 ) , 0x0 ,
NULL , V_91 } } ,
{ & V_78 ,
{ L_73 , L_74 ,
V_92 , V_90 , F_44 ( F_24 ) , 0x0 ,
NULL , V_91 } } ,
{ & V_81 ,
{ L_75 , L_76 ,
V_89 , V_90 , F_44 ( F_25 ) , 0x0 ,
NULL , V_91 } } ,
{ & V_65 ,
{ L_77 , L_78 ,
V_94 , V_95 , NULL , 0x0 ,
NULL , V_91 } } ,
{ & V_49 ,
{ L_79 , L_80 ,
V_92 , V_93 , NULL , 0x0 ,
NULL , V_91 } } ,
{ & V_50 ,
{ L_81 , L_82 ,
V_94 , V_95 , NULL , 0x0 ,
NULL , V_91 } } ,
{ & V_52 ,
{ L_83 , L_84 ,
V_92 , V_90 , F_44 ( F_26 ) , 0x0 ,
NULL , V_91 } } ,
{ & V_60 ,
{ L_85 , L_86 ,
V_94 , V_95 , NULL , 0x0 ,
NULL , V_91 } } ,
{ & V_76 ,
{ L_87 , L_88 ,
V_89 , V_90 , F_44 ( F_27 ) , 0x0 ,
NULL , V_91 } }
} ;
static T_3 * V_98 [] = {
& V_43
} ;
V_41 = F_45 ( L_12 , L_12 , L_89 ) ;
F_46 ( V_41 , V_2 , F_47 ( V_2 ) ) ;
F_48 ( V_98 , F_47 ( V_98 ) ) ;
V_88 = F_49 ( V_41 , F_37 ) ;
F_50 ( V_88 ,
L_14 ,
L_90 ,
L_91 ,
& V_85 ,
65535 ) ;
V_83 = F_51 () ;
}
void
F_52 ( void )
{
V_84 = F_53 ( F_28 , V_41 ) ;
F_54 ( L_92 , F_42 , L_93 , L_94 , V_41 , V_99 ) ;
}
