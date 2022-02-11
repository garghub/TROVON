static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_5 * V_5 , * V_6 ;
T_3 * V_7 , * V_8 ;
T_6 V_9 ;
T_7 V_10 = 0 ;
const T_8 * line ;
T_7 V_11 ;
int V_12 ;
int V_13 ;
const T_8 * V_14 ;
F_2 ( V_2 -> V_15 , V_16 , L_1 ) ;
if ( V_2 -> V_17 == V_2 -> V_18 )
V_9 = TRUE ;
else
V_9 = FALSE ;
V_12 = F_3 ( V_1 , V_10 , - 1 , & V_11 , FALSE ) ;
line = F_4 ( V_1 , V_10 , V_12 ) ;
F_5 ( V_2 -> V_15 , V_19 , L_2 ,
V_9 ? L_3 : L_4 ,
F_6 ( F_7 () , line , V_12 ) ) ;
if ( V_3 ) {
V_5 = F_8 ( V_3 , V_20 , V_1 , 0 , - 1 , V_21 ) ;
V_7 = F_9 ( V_5 , V_22 ) ;
if ( V_9 ) {
V_6 = F_10 ( V_7 , V_23 , V_1 , 0 , 0 , TRUE ) ;
} else {
V_6 = F_10 ( V_7 , V_24 , V_1 , 0 , 0 , TRUE ) ;
}
F_11 ( V_6 ) ;
V_5 = F_12 ( V_7 , V_1 , V_10 , V_11 - V_10 ) ;
V_8 = F_9 ( V_5 , V_25 ) ;
V_13 = F_13 ( line , line + V_12 , & V_14 ) ;
if ( V_13 != 0 ) {
if ( V_9 ) {
F_14 ( V_8 , V_26 , V_1 , V_10 ,
V_13 , F_6 ( F_7 () , line , V_13 ) ) ;
} else {
F_14 ( V_8 , V_27 , V_1 , V_10 ,
V_13 , F_6 ( F_7 () , line , V_13 ) ) ;
}
V_10 += ( T_7 ) ( V_14 - line ) ;
V_12 -= ( int ) ( V_14 - line ) ;
line = V_14 ;
}
if ( V_12 != 0 ) {
if ( V_9 ) {
F_14 ( V_8 , V_28 , V_1 , V_10 ,
V_12 , F_6 ( F_7 () , line , V_12 ) ) ;
} else {
F_14 ( V_8 , V_29 , V_1 , V_10 ,
V_12 , F_6 ( F_7 () , line , V_12 ) ) ;
}
}
}
return F_15 ( V_1 ) ;
}
void
F_16 ( void )
{
static T_9 V_30 [] = {
{ & V_24 ,
{ L_4 , L_5 , V_31 , V_32 , NULL , 0x0 , L_6 , V_33 }
} ,
{ & V_23 ,
{ L_3 , L_7 , V_31 , V_32 , NULL , 0x0 , L_8 , V_33 }
} ,
{ & V_27 ,
{ L_9 , L_10 , V_34 , V_32 , NULL , 0x0 , NULL , V_33 }
} ,
{ & V_29 ,
{ L_11 , L_12 , V_34 , V_32 , NULL , 0x0 , NULL , V_33 }
} ,
{ & V_26 ,
{ L_13 , L_14 , V_34 , V_32 , NULL , 0x0 , NULL , V_33 }
} ,
{ & V_28 ,
{ L_15 , L_16 , V_34 , V_32 , NULL , 0x0 , NULL , V_33 }
} ,
} ;
static T_7 * V_35 [] = {
& V_22 ,
& V_25 ,
} ;
V_20 = F_17 ( L_17 ,
L_1 , L_18 ) ;
F_18 ( V_20 , V_30 , F_19 ( V_30 ) ) ;
F_20 ( V_35 , F_19 ( V_35 ) ) ;
}
void
F_21 ( void )
{
T_10 V_36 ;
V_36 = F_22 ( F_1 , V_20 ) ;
F_23 ( L_19 , V_37 , V_36 ) ;
}
