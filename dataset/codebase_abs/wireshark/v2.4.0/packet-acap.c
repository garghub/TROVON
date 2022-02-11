static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_5 V_5 ;
T_3 * V_6 , * V_7 ;
T_6 * V_8 , * V_9 ;
T_7 V_10 = 0 ;
const T_8 * line ;
T_7 V_11 ;
int V_12 ;
int V_13 ;
const T_8 * V_14 ;
if ( ! F_2 ( F_3 ( V_1 , V_10 ) ) ) {
return 0 ;
}
F_4 ( V_2 -> V_15 , V_16 , L_1 ) ;
V_12 = F_5 ( V_1 , V_10 , - 1 , & V_11 , FALSE ) ;
line = F_6 ( V_1 , V_10 , V_12 ) ;
if ( V_2 -> V_17 == V_2 -> V_18 )
V_5 = TRUE ;
else
V_5 = FALSE ;
F_7 ( V_2 -> V_15 , V_19 , L_2 ,
V_5 ? L_3 : L_4 ,
F_8 ( F_9 () , line , V_12 ) ) ;
if ( V_3 ) {
V_8 = F_10 ( V_3 , V_20 , V_1 , V_10 , - 1 ,
V_21 ) ;
V_6 = F_11 ( V_8 , V_22 ) ;
if ( V_5 ) {
V_9 = F_12 ( V_6 ,
& V_23 , V_1 , 0 , 0 , TRUE ) ;
F_13 ( V_9 ) ;
} else {
V_9 = F_12 ( V_6 ,
& V_24 , V_1 , 0 , 0 , TRUE ) ;
F_13 ( V_9 ) ;
}
V_8 = F_14 ( V_6 , V_1 , V_10 , V_11 - V_10 ) ;
V_7 = F_11 ( V_8 , V_25 ) ;
V_13 = F_15 ( line , line + V_12 , & V_14 ) ;
if ( V_13 != 0 ) {
if ( V_5 ) {
F_16 ( V_7 , & V_26 , V_1 , V_10 ,
V_13 , F_8 ( F_9 () , line , V_13 ) ) ;
} else {
F_16 ( V_7 , & V_27 , V_1 , V_10 ,
V_13 , F_8 ( F_9 () , line , V_13 ) ) ;
}
V_10 += ( int ) ( V_14 - line ) ;
V_12 -= ( int ) ( V_14 - line ) ;
line = V_14 ;
}
if ( V_12 != 0 ) {
if ( V_5 ) {
F_16 ( V_7 , & V_28 , V_1 , V_10 ,
V_12 , F_8 ( F_9 () , line , V_12 ) ) ;
} else {
F_16 ( V_7 , & V_29 , V_1 , V_10 ,
V_12 , F_8 ( F_9 () , line , V_12 ) ) ;
}
}
}
return F_17 ( V_1 ) ;
}
void
F_18 ( void )
{
#ifndef F_19
static T_9 * V_30 [] = {
& V_24 ,
& V_23 ,
& V_26 ,
& V_27 ,
& V_28 ,
& V_29 ,
} ;
#endif
static T_7 * V_31 [] = {
& V_22 ,
& V_25 ,
} ;
int V_32 ;
V_32 = F_20 ( L_5 ,
L_1 , L_6 ) ;
V_20 = F_21 ( V_32 ) ;
F_22 ( V_32 , V_30 , F_23 ( V_30 ) ) ;
F_24 ( V_31 , F_23 ( V_31 ) ) ;
V_33 = F_25 ( F_1 , V_32 ) ;
}
void
F_26 ( void )
{
F_27 ( L_7 , V_34 , V_33 ) ;
}
