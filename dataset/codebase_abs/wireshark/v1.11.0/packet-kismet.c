static T_1
F_1 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 , void * T_5 V_4 )
{
T_1 V_5 ;
T_1 V_6 ;
T_4 * V_7 = NULL , * V_8 = NULL ;
T_6 * V_9 ;
T_6 * V_10 ;
T_7 V_11 = 0 ;
const T_8 * line ;
T_7 V_12 ;
int V_13 ;
int V_14 ;
int V_15 ;
const T_8 * V_16 ;
V_13 = F_2 ( V_1 , V_11 , - 1 , & V_12 , FALSE ) ;
line = F_3 ( V_1 , V_11 , V_13 ) ;
if ( V_13 < 8 ) {
return FALSE ;
} else {
for ( V_15 = 0 ; V_15 < 8 ; ++ V_15 ) {
if ( line [ V_15 ] < 32 || line [ V_15 ] > 128 )
return FALSE ;
}
}
F_4 ( V_2 -> V_17 , V_18 , L_1 ) ;
if ( V_2 -> V_19 == V_2 -> V_20 ) {
V_5 = TRUE ;
V_6 = FALSE ;
} else {
V_5 = FALSE ;
V_6 = F_5 ( line ) ;
}
if ( V_6 )
F_4 ( V_2 -> V_17 , V_21 , L_2 ) ;
else
F_6 ( V_2 -> V_17 , V_21 , L_3 ,
V_5 ? L_4 : L_5 ,
F_7 ( line , V_13 ) ) ;
if ( V_3 ) {
V_9 = F_8 ( V_3 , V_22 , V_1 , V_11 , - 1 , V_23 ) ;
V_7 = F_9 ( V_9 , V_24 ) ;
}
if ( V_6 ) {
F_10 ( V_25 , V_1 , V_2 , V_7 ) ;
return TRUE ;
}
if ( V_5 ) {
V_10 = F_11 ( V_7 ,
V_26 , V_1 , 0 , 0 , TRUE ) ;
} else {
V_10 = F_11 ( V_7 ,
V_27 , V_1 , 0 , 0 , TRUE ) ;
}
F_12 ( V_10 ) ;
while ( F_13 ( V_1 , V_11 ) ) {
V_13 = F_2 ( V_1 , V_11 , - 1 , & V_12 , FALSE ) ;
if ( V_13 ) {
V_9 = F_14 ( V_7 , V_1 , V_11 ,
V_12 - V_11 , L_6 ,
F_15 ( V_1 , V_11 ,
V_12 - V_11 - 1 ) ) ;
V_8 = F_9 ( V_9 , V_28 ) ;
V_14 = F_16 ( line , line + V_13 , & V_16 ) ;
if ( V_14 != 0 ) {
T_9 * V_29 ;
V_29 = F_17 ( F_18 () , V_1 , V_11 , V_14 ) ;
if ( V_5 ) {
} else {
if ( ! strncmp ( V_29 , L_7 , 7 ) ) {
V_11 += ( T_7 ) ( V_16 - line ) ;
V_13 -= ( int ) ( V_16 - line ) ;
line = V_16 ;
V_14 = F_16 ( line , line + V_13 , & V_16 ) ;
F_14 ( V_8 , V_1 , V_11 ,
V_14 , L_8 ,
F_7 ( line , V_14 ) ) ;
V_11 += ( T_7 ) ( V_16 - line ) ;
V_13 -= ( int ) ( V_16 - line ) ;
line = V_16 ;
V_14 = F_16 ( line , line + V_13 , & V_16 ) ;
F_14 ( V_8 , V_1 , V_11 ,
V_14 , L_9 ,
F_7 ( line , V_14 ) ) ;
V_11 += ( T_7 ) ( V_16 - line ) ;
V_13 -= ( int ) ( V_16 - line ) ;
line = V_16 ;
V_14 = F_16 ( line , line + V_13 , & V_16 ) ;
F_14 ( V_8 , V_1 , V_11 ,
V_14 , L_10 ,
F_7 ( line + 1 , V_14 - 2 ) ) ;
V_11 += ( T_7 ) ( V_16 - line ) ;
V_13 -= ( int ) ( V_16 - line ) ;
line = V_16 ;
V_14 = F_16 ( line , line + V_13 , & V_16 ) ;
F_14 ( V_8 , V_1 , V_11 ,
V_14 , L_11 ,
F_7 ( line , V_14 ) ) ;
V_11 += ( T_7 ) ( V_16 - line ) ;
V_13 -= ( int ) ( V_16 - line ) ;
line = V_16 ;
V_14 = F_16 ( line , line + V_13 , & V_16 ) ;
F_14 ( V_8 , V_1 , V_11 ,
V_14 , L_12 ,
F_7 ( line , V_14 ) ) ;
V_11 += ( T_7 ) ( V_16 - line ) ;
V_13 -= ( int ) ( V_16 - line ) ;
line = V_16 ;
V_14 = F_16 ( line , line + V_13 , & V_16 ) ;
F_14 ( V_8 , V_1 , V_11 ,
V_14 ,
L_13 ,
F_7 ( line , V_14 ) ) ;
}
if ( ! strncmp ( V_29 , L_14 , 5 ) ) {
T_10 V_30 ;
char * V_31 ;
V_11 += ( T_7 ) ( V_16 - line ) ;
V_13 -= ( int ) ( V_16 - line ) ;
line = V_16 ;
V_14 = F_16 ( line , line + V_13 , & V_16 ) ;
V_30 = atoi ( F_7 ( line , V_14 ) ) ;
V_31 = F_19 ( V_30 , V_32 , TRUE ) ;
F_14 ( V_8 , V_1 , V_11 ,
V_14 , L_15 , V_31 ) ;
}
}
line = V_16 ;
}
}
V_11 = V_12 ;
}
return TRUE ;
}
static T_1
F_5 ( const T_8 * T_5 )
{
if ( ! strncmp ( T_5 , L_16 , 1 ) )
return FALSE ;
if ( ! strncmp ( T_5 , L_17 , 1 ) )
return FALSE ;
return TRUE ;
}
void
F_20 ( void )
{
static T_11 V_33 [] = {
{ & V_27 ,
{ L_5 , L_18 , V_34 , V_35 ,
NULL , 0x0 , L_19 , V_36 } } ,
{ & V_26 ,
{ L_4 , L_20 , V_34 , V_35 ,
NULL , 0x0 , L_21 , V_36 } }
} ;
static T_7 * V_37 [] = {
& V_24 ,
& V_28 ,
} ;
T_12 * V_38 ;
V_22 = F_21 ( L_22 , L_23 , L_1 ) ;
F_22 ( V_22 , V_33 , F_23 ( V_33 ) ) ;
F_24 ( V_37 , F_23 ( V_37 ) ) ;
V_38 = F_25 ( V_22 , V_39 ) ;
F_26 ( V_38 , L_24 ,
L_25 ,
L_26
L_27 , 10 ,
& V_40 ) ;
}
void
V_39 ( void )
{
static T_1 V_41 = FALSE ;
static T_13 V_42 ;
static T_14 V_43 ;
if ( ! V_41 ) {
V_42 = F_27 ( F_1 , V_22 ) ;
V_25 = F_28 ( L_28 ) ;
V_41 = TRUE ;
} else {
F_29 ( L_24 , V_43 , V_42 ) ;
}
V_43 = V_40 ;
F_30 ( L_24 , V_40 , V_42 ) ;
}
