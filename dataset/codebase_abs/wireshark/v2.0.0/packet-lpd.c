static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_3 * V_4 ;
T_4 * V_5 , * V_6 ;
enum V_7 V_8 ;
T_5 V_9 ;
T_6 V_10 ;
F_2 ( V_2 -> V_11 , V_12 , L_1 ) ;
F_3 ( V_2 -> V_11 , V_13 ) ;
V_9 = F_4 ( V_1 , 0 ) ;
if ( F_5 ( V_1 ) == 1 ) {
V_8 = V_14 ;
}
else if ( V_9 <= 9 ) {
V_8 = V_15 ;
}
else {
V_8 = V_16 ;
}
if ( V_8 == V_15 && V_9 != 0 ) {
F_6 ( V_2 -> V_11 , V_13 , F_7 ( V_9 , V_17 , L_2 ) ) ;
}
else if ( V_8 == V_14 ) {
F_2 ( V_2 -> V_11 , V_13 , L_3 ) ;
}
else {
F_2 ( V_2 -> V_11 , V_13 , L_4 ) ;
}
V_5 = F_8 ( V_3 , V_18 , V_1 , 0 , - 1 , V_19 ) ;
V_4 = F_9 ( V_5 , V_20 ) ;
if ( V_8 == V_14 ) {
V_6 = F_10 ( V_4 , V_21 ,
V_1 , 0 , 0 , TRUE ) ;
} else {
V_6 = F_10 ( V_4 , V_22 ,
V_1 , 0 , 0 , TRUE ) ;
}
F_11 ( V_6 ) ;
if ( V_8 == V_15 ) {
V_10 = F_12 ( V_1 , 1 ) ;
if ( V_9 <= 9 && V_10 != - 1 ) {
F_13 ( V_4 , V_23 , V_1 , 0 , 1 , V_9 ,
L_5 , F_7 ( V_9 , V_17 , L_2 ) ) ;
F_8 ( V_4 , V_24 , V_1 , 1 , V_10 , V_25 | V_19 ) ;
}
else {
F_14 ( V_26 , V_1 , V_2 , V_4 ) ;
}
}
else if ( V_8 == V_14 ) {
if ( V_9 <= 3 ) {
F_8 ( V_4 , V_27 , V_1 , 0 , 1 , V_28 ) ;
}
else {
F_14 ( V_26 , V_1 , V_2 , V_4 ) ;
}
}
else {
F_14 ( V_26 , V_1 , V_2 , V_4 ) ;
}
}
static T_6
F_12 ( T_1 * V_1 , int V_29 )
{
int V_30 ;
V_30 = F_15 ( V_1 , V_29 , - 1 , '\0' ) ;
if ( V_30 == - 1 )
V_30 = F_15 ( V_1 , V_29 , - 1 , '\n' ) ;
if ( V_30 == - 1 )
return - 1 ;
return V_30 - V_29 ;
}
void
F_16 ( void )
{
static T_7 V_31 [] = {
{ & V_21 ,
{ L_6 , L_7 ,
V_32 , V_33 , NULL , 0x0 ,
L_8 , V_34 } } ,
{ & V_22 ,
{ L_9 , L_10 ,
V_32 , V_33 , NULL , 0x0 ,
L_11 , V_34 } } ,
{ & V_23 ,
{ L_12 , L_13 ,
V_35 , V_36 , F_17 ( V_17 ) , 0x0 ,
NULL , V_34 } } ,
{ & V_24 ,
{ L_14 , L_15 ,
V_37 , V_33 , NULL , 0x0 ,
NULL , V_34 } } ,
{ & V_27 ,
{ L_6 , L_16 ,
V_35 , V_36 , F_17 ( V_38 ) , 0x0 ,
NULL , V_34 } } ,
} ;
static T_6 * V_39 [] = {
& V_20 ,
} ;
V_18 = F_18 ( L_17 , L_1 , L_18 ) ;
F_19 ( V_18 , V_31 , F_20 ( V_31 ) ) ;
F_21 ( V_39 , F_20 ( V_39 ) ) ;
}
void
F_22 ( void )
{
T_8 V_40 ;
V_40 = F_23 ( F_1 , V_18 ) ;
F_24 ( L_19 , V_41 , V_40 ) ;
V_26 = F_25 ( L_20 ) ;
}
