static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 V_4 ;
T_3 * V_5 , * V_6 ;
T_5 * V_7 , * V_8 ;
T_6 V_9 = 0 ;
const T_7 * line ;
T_6 V_10 ;
int V_11 ;
int V_12 ;
const T_7 * V_13 ;
F_2 ( V_2 -> V_14 , V_15 , L_1 ) ;
V_11 = F_3 ( V_1 , V_9 , - 1 , & V_10 , V_16 ) ;
line = F_4 ( V_1 , V_9 , V_11 ) ;
if ( V_2 -> V_17 == V_2 -> V_18 )
V_4 = TRUE ;
else
V_4 = FALSE ;
F_5 ( V_2 -> V_14 , V_19 , L_2 ,
V_4 ? L_3 : L_4 ,
F_6 ( line , V_11 ) ) ;
if ( V_3 ) {
V_7 = F_7 ( V_3 , V_20 , V_1 , V_9 , - 1 ,
V_21 ) ;
V_5 = F_8 ( V_7 , V_22 ) ;
if ( V_4 ) {
V_8 = F_9 ( V_5 ,
V_23 , V_1 , 0 , 0 , TRUE ) ;
F_10 ( V_8 ) ;
} else {
V_8 = F_9 ( V_5 ,
V_24 , V_1 , 0 , 0 , TRUE ) ;
F_10 ( V_8 ) ;
}
V_7 = F_11 ( V_5 , V_1 , V_9 ,
V_10 - V_9 , L_5 ,
F_12 ( V_1 , V_9 , V_10 - V_9 ) ) ;
V_6 = F_8 ( V_7 , V_25 ) ;
V_12 = F_13 ( line , line + V_11 , & V_13 ) ;
if ( V_12 != 0 ) {
if ( V_4 ) {
F_11 ( V_6 , V_1 , V_9 ,
V_12 , L_6 ,
F_6 ( line , V_12 ) ) ;
} else {
F_11 ( V_6 , V_1 , V_9 ,
V_12 , L_7 ,
F_6 ( line , V_12 ) ) ;
}
V_9 += ( int ) ( V_13 - line ) ;
V_11 -= ( int ) ( V_13 - line ) ;
line = V_13 ;
}
if ( V_11 != 0 ) {
if ( V_4 ) {
F_11 ( V_6 , V_1 , V_9 ,
V_11 , L_8 ,
F_6 ( line , V_11 ) ) ;
} else {
F_11 ( V_6 , V_1 , V_9 ,
V_11 , L_9 ,
F_6 ( line , V_11 ) ) ;
}
}
}
}
void
F_14 ( void )
{
static T_8 V_26 [] = {
{ & V_24 ,
{ L_4 , L_10 ,
V_27 , V_28 , NULL , 0x0 ,
L_11 , V_29 } } ,
{ & V_23 ,
{ L_3 , L_12 ,
V_27 , V_28 , NULL , 0x0 ,
L_13 , V_29 } }
} ;
static T_6 * V_30 [] = {
& V_22 ,
& V_25 ,
} ;
V_20 = F_15 ( L_14 ,
L_1 , L_15 ) ;
F_16 ( V_20 , V_26 , F_17 ( V_26 ) ) ;
F_18 ( V_30 , F_17 ( V_30 ) ) ;
}
void
F_19 ( void )
{
T_9 V_31 ;
V_31 = F_20 ( F_1 , V_20 ) ;
F_21 ( L_16 , V_32 , V_31 ) ;
}
