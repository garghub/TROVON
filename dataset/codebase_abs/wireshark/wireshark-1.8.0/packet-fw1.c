static void
F_1 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_2 ; V_1 ++ ) {
F_2 ( V_3 [ V_1 ] ) ;
}
V_2 = 0 ;
}
static void
F_3 ( T_1 * V_4 , T_2 * V_5 , T_3 * V_6 )
{
T_4 * V_7 ;
T_3 * volatile V_8 = NULL ;
char V_9 ;
char V_10 ;
char * V_11 ;
T_5 V_12 = 10 ;
T_6 V_13 ;
T_7 * V_14 ;
int V_1 ;
T_8 V_15 ;
static const char V_16 [] = L_1 ;
V_14 = F_4 ( V_16 ) ;
F_5 ( V_5 -> V_17 , V_18 , L_2 ) ;
F_6 ( V_5 -> V_17 , V_19 ) ;
V_9 = F_7 ( V_4 , 0 ) ;
if ( ! V_20 )
V_10 = ' ' ;
else
V_10 = F_7 ( V_4 , 1 ) ;
if ( V_21 )
V_12 = 6 ;
V_11 = F_8 ( V_12 + 1 ) ;
F_9 ( V_4 , 2 , V_12 + 1 , V_11 ) ;
V_15 = FALSE ;
for ( V_1 = 0 ; V_1 < V_2 ; V_1 ++ ) {
if ( strcmp ( V_3 [ V_1 ] , V_11 ) == 0 ) {
V_15 = TRUE ;
break;
}
}
if ( ! V_15 && V_2 < V_22 ) {
V_3 [ V_2 ] = F_10 ( V_11 ) ;
V_2 ++ ;
}
for ( V_1 = 0 ; V_1 < V_2 ; V_1 ++ ) {
if ( strcmp ( V_3 [ V_1 ] , V_11 ) == 0 ) {
F_11 ( V_14 , L_3 ,
V_9 == 'i' ? 'i' : ( V_9 == 'O' ? 'O' : ' ' ) ,
( V_9 == 'i' || V_9 == 'O' ) ? V_10 : ' ' ,
V_3 [ V_1 ] ,
V_9 == 'I' ? 'I' : ( V_9 == 'o' ? 'o' : ' ' ) ,
( V_9 == 'I' || V_9 == 'o' ) ? V_10 : ' '
) ;
} else {
F_11 ( V_14 , L_4 , V_3 [ V_1 ] ) ;
}
}
if ( F_12 ( V_5 -> V_17 , V_23 ) )
F_13 ( V_5 -> V_17 , V_23 , V_14 -> V_24 + sizeof( V_16 ) + 1 ) ;
if ( V_6 ) {
if ( ! V_25 )
V_7 = F_14 ( V_6 , V_26 , V_4 , 0 , V_27 , L_5 , V_16 ) ;
else
V_7 = F_14 ( V_6 , V_26 , V_4 , 0 , V_27 , L_5 , V_14 -> V_24 ) ;
V_8 = F_15 ( V_7 , V_28 ) ;
F_16 ( V_8 , V_29 , V_4 , 0 , 1 , V_30 | V_31 ) ;
if ( V_20 )
F_16 ( V_8 , V_32 , V_4 , 1 , 1 , V_30 | V_31 ) ;
F_16 ( V_8 , V_33 , V_4 , 2 , V_12 , V_30 | V_31 ) ;
if ( V_21 )
F_16 ( V_8 , V_34 , V_4 , 8 , 4 , V_35 ) ;
}
V_13 = F_17 ( V_4 , 12 ) ;
F_18 ( V_13 , V_4 , V_27 , V_5 , V_6 , V_8 , V_36 , V_37 , 0 ) ;
}
void
F_19 ( void )
{
static T_9 V_38 [] = {
{ & V_29 ,
{ L_6 , L_7 , V_39 , V_40 , NULL , 0x0 ,
NULL , V_41 } } ,
{ & V_32 ,
{ L_8 , L_9 , V_39 , V_40 , NULL , 0x0 ,
NULL , V_41 } } ,
{ & V_33 ,
{ L_10 , L_11 , V_39 , V_40 , NULL , 0x0 ,
NULL , V_41 } } ,
{ & V_34 ,
{ L_12 , L_13 , V_42 , V_43 , NULL , 0x0 ,
NULL , V_41 } } ,
{ & V_36 ,
{ L_14 , L_15 , V_44 , V_45 , F_20 ( V_46 ) , 0x0 ,
NULL , V_41 } } ,
} ;
static T_10 * V_47 [] = {
& V_28 ,
} ;
T_11 * V_48 ;
int V_1 ;
V_26 = F_21 ( L_16 , L_17 , L_18 ) ;
F_22 ( V_26 , V_38 , F_23 ( V_38 ) ) ;
F_24 ( V_47 , F_23 ( V_47 ) ) ;
V_48 = F_25 ( V_26 , NULL ) ;
F_26 ( V_48 , L_19 ,
L_20 ,
L_21 ,
& V_25 ) ;
F_26 ( V_48 , L_22 ,
L_23 ,
L_24 ,
& V_21 ) ;
F_26 ( V_48 , L_25 ,
L_26 ,
L_27 ,
& V_20 ) ;
F_27 ( L_18 , F_3 , V_26 ) ;
for ( V_1 = 0 ; V_1 < V_2 ; V_1 ++ ) {
V_3 [ V_1 ] = NULL ;
}
F_28 ( F_1 ) ;
}
