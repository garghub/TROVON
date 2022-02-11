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
F_10 ( V_25 , V_1 , V_2 , V_7 ) ;
return F_11 ( V_1 ) ;
}
if ( V_5 ) {
V_10 = F_12 ( V_7 ,
V_26 , V_1 , 0 , 0 , TRUE ) ;
} else {
V_10 = F_12 ( V_7 ,
V_27 , V_1 , 0 , 0 , TRUE ) ;
}
F_13 ( V_10 ) ;
while ( F_14 ( V_1 , V_11 ) ) {
V_13 = F_2 ( V_1 , V_11 , - 1 , & V_12 , FALSE ) ;
if ( V_13 ) {
V_8 = F_15 ( V_7 , V_1 , V_11 ,
V_12 - V_11 , V_28 , NULL ,
F_16 ( V_1 , V_11 ,
V_12 - V_11 - 1 ) ) ;
V_14 = F_17 ( line , line + V_13 , & V_16 ) ;
if ( V_14 != 0 ) {
T_9 * V_29 ;
V_29 = F_18 ( F_19 () , V_1 , V_11 , V_14 , V_30 ) ;
if ( V_5 ) {
} else {
if ( ! strncmp ( V_29 , L_6 , 7 ) ) {
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
V_14 , F_7 ( line , V_14 ) ) ;
V_11 += ( T_7 ) ( V_16 - line ) ;
V_13 -= ( int ) ( V_16 - line ) ;
line = V_16 ;
V_14 = F_17 ( line , line + V_13 , & V_16 ) ;
F_20 ( V_8 , V_33 , V_1 , V_11 ,
V_14 , F_7 ( line + 1 , V_14 - 2 ) ) ;
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
V_11 += ( T_7 ) ( V_16 - line ) ;
V_13 -= ( int ) ( V_16 - line ) ;
line = V_16 ;
V_14 = F_17 ( line , line + V_13 , & V_16 ) ;
F_20 ( V_8 , V_36 , V_1 , V_11 ,
V_14 , F_7 ( line , V_14 ) ) ;
}
if ( ! strncmp ( V_29 , L_7 , 5 ) ) {
T_10 V_37 ;
char * V_38 ;
V_11 += ( T_7 ) ( V_16 - line ) ;
V_13 -= ( int ) ( V_16 - line ) ;
line = V_16 ;
V_14 = F_17 ( line , line + V_13 , & V_16 ) ;
V_37 . V_39 = atoi ( F_7 ( line , V_14 ) ) ;
V_37 . V_40 = 0 ;
V_38 = F_21 ( F_19 () , V_37 . V_39 , V_41 , TRUE ) ;
F_22 ( V_8 , V_42 , V_1 , V_11 , V_14 , & V_37 , L_8 , V_38 ) ;
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
static T_11 V_43 [] = {
{ & V_27 ,
{ L_5 , L_11 , V_44 , V_45 ,
NULL , 0x0 , L_12 , V_46 } } ,
{ & V_26 ,
{ L_4 , L_13 , V_44 , V_45 ,
NULL , 0x0 , L_14 , V_46 } } ,
{ & V_31 ,
{ L_15 , L_16 , V_47 , V_45 ,
NULL , 0x0 , NULL , V_46 } } ,
{ & V_32 ,
{ L_17 , L_18 , V_47 , V_45 ,
NULL , 0x0 , NULL , V_46 } } ,
{ & V_33 ,
{ L_19 , L_20 , V_47 , V_45 ,
NULL , 0x0 , NULL , V_46 } } ,
{ & V_34 ,
{ L_21 , L_22 , V_47 , V_45 ,
NULL , 0x0 , NULL , V_46 } } ,
{ & V_35 ,
{ L_23 , L_24 , V_47 , V_45 ,
NULL , 0x0 , NULL , V_46 } } ,
{ & V_36 ,
{ L_25 , L_26 , V_47 , V_45 ,
NULL , 0x0 , NULL , V_46 } } ,
{ & V_42 ,
{ L_27 , L_28 , V_48 , V_41 ,
NULL , 0x0 , NULL , V_46 } } ,
} ;
static T_7 * V_49 [] = {
& V_24 ,
& V_28 ,
} ;
T_12 * V_50 ;
V_22 = F_24 ( L_29 , L_30 , L_1 ) ;
F_25 ( V_22 , V_43 , F_26 ( V_43 ) ) ;
F_27 ( V_49 , F_26 ( V_49 ) ) ;
V_50 = F_28 ( V_22 , V_51 ) ;
F_29 ( V_50 , L_31 ,
L_32 ,
L_33
L_34 , 10 ,
& V_52 ) ;
}
void
V_51 ( void )
{
static T_5 V_53 = FALSE ;
static T_13 V_54 ;
static T_14 V_55 ;
if ( ! V_53 ) {
V_54 = F_30 ( F_1 , V_22 ) ;
V_25 = F_31 ( L_35 ) ;
V_53 = TRUE ;
} else {
F_32 ( L_31 , V_55 , V_54 ) ;
}
V_55 = V_52 ;
F_33 ( L_31 , V_52 , V_54 ) ;
}
