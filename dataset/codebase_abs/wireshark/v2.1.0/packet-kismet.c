static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_5 V_5 ;
T_5 V_6 ;
T_3 * V_7 = NULL , * V_8 = NULL ;
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
return 0 ;
} else {
for ( V_15 = 0 ; V_15 < 8 ; ++ V_15 ) {
if ( line [ V_15 ] < 32 || line [ V_15 ] > 128 )
return 0 ;
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
F_10 ( V_1 , V_2 , V_7 ) ;
return F_11 ( V_1 ) ;
}
if ( V_5 ) {
V_10 = F_12 ( V_7 ,
V_25 , V_1 , 0 , 0 , TRUE ) ;
} else {
V_10 = F_12 ( V_7 ,
V_26 , V_1 , 0 , 0 , TRUE ) ;
}
F_13 ( V_10 ) ;
while ( F_14 ( V_1 , V_11 ) ) {
V_13 = F_2 ( V_1 , V_11 , - 1 , & V_12 , FALSE ) ;
if ( V_13 ) {
V_8 = F_15 ( V_7 , V_1 , V_11 ,
V_12 - V_11 , V_27 , NULL ,
F_16 ( V_1 , V_11 ,
V_12 - V_11 - 1 ) ) ;
V_14 = F_17 ( line , line + V_13 , & V_16 ) ;
if ( V_14 != 0 ) {
T_9 * V_28 ;
V_28 = F_18 ( F_19 () , V_1 , V_11 , V_14 , V_29 ) ;
if ( V_5 ) {
} else {
if ( ! strncmp ( V_28 , L_6 , 7 ) ) {
V_11 += ( T_7 ) ( V_16 - line ) ;
V_13 -= ( int ) ( V_16 - line ) ;
line = V_16 ;
V_14 = F_17 ( line , line + V_13 , & V_16 ) ;
F_20 ( V_8 , V_30 , V_1 , V_11 ,
V_14 , F_7 ( line , V_14 ) ) ;
V_11 += ( T_7 ) ( V_16 - line ) ;
V_13 -= ( int ) ( V_16 - line ) ;
line = V_16 ;
V_14 = F_17 ( line , line + V_13 , & V_16 ) ;
F_20 ( V_8 , V_31 , V_1 , V_11 ,
V_14 , F_7 ( line , V_14 ) ) ;
V_11 += ( T_7 ) ( V_16 - line ) ;
V_13 -= ( int ) ( V_16 - line ) ;
line = V_16 ;
V_14 = F_17 ( line , line + V_13 , & V_16 ) ;
F_20 ( V_8 , V_32 , V_1 , V_11 ,
V_14 , F_7 ( line + 1 , V_14 - 2 ) ) ;
V_11 += ( T_7 ) ( V_16 - line ) ;
V_13 -= ( int ) ( V_16 - line ) ;
line = V_16 ;
V_14 = F_17 ( line , line + V_13 , & V_16 ) ;
F_20 ( V_8 , V_33 , V_1 , V_11 ,
V_14 , F_7 ( line , V_14 ) ) ;
V_11 += ( T_7 ) ( V_16 - line ) ;
V_13 -= ( int ) ( V_16 - line ) ;
line = V_16 ;
V_14 = F_17 ( line , line + V_13 , & V_16 ) ;
F_20 ( V_8 , V_34 , V_1 , V_11 ,
V_14 , F_7 ( line , V_14 ) ) ;
V_11 += ( T_7 ) ( V_16 - line ) ;
V_13 -= ( int ) ( V_16 - line ) ;
line = V_16 ;
V_14 = F_17 ( line , line + V_13 , & V_16 ) ;
F_20 ( V_8 , V_35 , V_1 , V_11 ,
V_14 , F_7 ( line , V_14 ) ) ;
}
if ( ! strncmp ( V_28 , L_7 , 5 ) ) {
T_10 V_36 ;
char * V_37 ;
V_11 += ( T_7 ) ( V_16 - line ) ;
V_13 -= ( int ) ( V_16 - line ) ;
line = V_16 ;
V_14 = F_17 ( line , line + V_13 , & V_16 ) ;
V_36 . V_38 = atoi ( F_7 ( line , V_14 ) ) ;
V_36 . V_39 = 0 ;
V_37 = F_21 ( F_19 () , V_36 . V_38 , V_40 , TRUE ) ;
F_22 ( V_8 , V_41 , V_1 , V_11 , V_14 , & V_36 , L_8 , V_37 ) ;
}
}
line = V_16 ;
}
}
V_11 = V_12 ;
}
return F_11 ( V_1 ) ;
}
static T_5
F_5 ( const T_8 * T_4 )
{
if ( ! strncmp ( T_4 , L_9 , 1 ) )
return FALSE ;
if ( ! strncmp ( T_4 , L_10 , 1 ) )
return FALSE ;
return TRUE ;
}
void
F_23 ( void )
{
static T_11 V_42 [] = {
{ & V_26 ,
{ L_5 , L_11 , V_43 , V_44 ,
NULL , 0x0 , L_12 , V_45 } } ,
{ & V_25 ,
{ L_4 , L_13 , V_43 , V_44 ,
NULL , 0x0 , L_14 , V_45 } } ,
{ & V_30 ,
{ L_15 , L_16 , V_46 , V_44 ,
NULL , 0x0 , NULL , V_45 } } ,
{ & V_31 ,
{ L_17 , L_18 , V_46 , V_44 ,
NULL , 0x0 , NULL , V_45 } } ,
{ & V_32 ,
{ L_19 , L_20 , V_46 , V_44 ,
NULL , 0x0 , NULL , V_45 } } ,
{ & V_33 ,
{ L_21 , L_22 , V_46 , V_44 ,
NULL , 0x0 , NULL , V_45 } } ,
{ & V_34 ,
{ L_23 , L_24 , V_46 , V_44 ,
NULL , 0x0 , NULL , V_45 } } ,
{ & V_35 ,
{ L_25 , L_26 , V_46 , V_44 ,
NULL , 0x0 , NULL , V_45 } } ,
{ & V_41 ,
{ L_27 , L_28 , V_47 , V_40 ,
NULL , 0x0 , NULL , V_45 } } ,
} ;
static T_7 * V_48 [] = {
& V_24 ,
& V_27 ,
} ;
T_12 * V_49 ;
V_22 = F_24 ( L_29 , L_30 , L_1 ) ;
F_25 ( V_22 , V_42 , F_26 ( V_42 ) ) ;
F_27 ( V_48 , F_26 ( V_48 ) ) ;
V_49 = F_28 ( V_22 , V_50 ) ;
F_29 ( V_49 , L_31 ,
L_32 ,
L_33
L_34 , 10 ,
& V_51 ) ;
}
void
V_50 ( void )
{
static T_5 V_52 = FALSE ;
static T_13 V_53 ;
static T_14 V_54 ;
if ( ! V_52 ) {
V_53 = F_30 ( F_1 , V_22 ) ;
V_52 = TRUE ;
} else {
F_31 ( L_31 , V_54 , V_53 ) ;
}
V_54 = V_51 ;
F_32 ( L_31 , V_51 , V_53 ) ;
}
