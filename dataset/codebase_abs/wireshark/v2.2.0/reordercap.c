static void
F_1 ( T_1 * V_1 )
{
fprintf ( V_1 , L_1 ) ;
fprintf ( V_1 , L_2 ) ;
fprintf ( V_1 , L_1 ) ;
fprintf ( V_1 , L_3 ) ;
fprintf ( V_1 , L_4 ) ;
fprintf ( V_1 , L_5 ) ;
}
static void
F_2 ( T_2 * V_2 , T_3 * V_3 , T_4 * V_4 ,
struct V_5 * V_6 , T_5 * V_7 , const char * V_8 )
{
int V_9 ;
T_6 * V_10 ;
F_3 ( L_6 V_11 L_7 ,
V_2 -> V_12 ) ;
if ( ! F_4 ( V_3 , V_2 -> V_12 , V_6 , V_7 , & V_9 , & V_10 ) ) {
if ( V_9 != 0 ) {
fprintf ( V_13 ,
L_8 ,
V_8 , F_5 ( V_9 ) ) ;
if ( V_10 != NULL ) {
fprintf ( V_13 , L_9 , V_10 ) ;
F_6 ( V_10 ) ;
}
exit ( 1 ) ;
}
}
V_6 -> V_14 = V_2 -> V_15 ;
if ( ! F_7 ( V_4 , V_6 , F_8 ( V_7 ) , & V_9 , & V_10 ) ) {
fprintf ( V_13 , L_10 ,
F_5 ( V_9 ) ) ;
if ( V_10 != NULL ) {
fprintf ( V_13 , L_9 , V_10 ) ;
F_6 ( V_10 ) ;
}
exit ( 1 ) ;
}
}
static int
F_9 ( T_7 V_16 , T_7 V_17 )
{
const T_2 * V_18 = * ( const T_2 * const * ) V_16 ;
const T_2 * V_19 = * ( const T_2 * const * ) V_17 ;
const T_8 * V_20 = & V_18 -> V_15 ;
const T_8 * V_21 = & V_19 -> V_15 ;
return F_10 ( V_20 , V_21 ) ;
}
static void
F_11 ( const char * T_9 V_22 , T_10 T_11 V_22 )
{
return;
}
int
main ( int V_23 , char * V_24 [] )
{
T_12 * V_25 ;
T_12 * V_26 ;
T_3 * V_3 = NULL ;
T_4 * V_4 = NULL ;
struct V_5 V_27 ;
T_5 V_7 ;
int V_9 ;
T_6 * V_10 ;
T_13 V_28 ;
const struct V_5 * V_6 ;
T_14 V_29 = 0 ;
T_15 V_30 = TRUE ;
T_14 V_31 ;
T_16 * V_32 = NULL ;
T_17 * V_33 = NULL ;
T_16 * V_34 = NULL ;
T_18 * V_35 ;
T_2 * V_36 = NULL ;
int V_37 ;
static const struct V_38 V_39 [] = {
{ L_11 , V_40 , NULL , 'h' } ,
{ L_12 , V_40 , NULL , 'v' } ,
{ 0 , 0 , 0 , 0 }
} ;
int V_41 ;
char * V_8 ;
const char * V_42 ;
#ifdef F_12
char * V_43 ;
#endif
V_25 = F_13 ( NULL , NULL ) ;
V_26 = F_14 ( NULL ) ;
F_15 ( L_13
L_1
L_14
L_1
L_14 ,
F_16 () , V_25 -> V_44 , V_26 -> V_44 ) ;
F_17 () ;
F_18 () ;
#ifdef F_12
if ( ( V_43 = F_19 ( V_24 [ 0 ] , main ) ) ) {
F_20 ( L_15 , V_43 ) ;
F_6 ( V_43 ) ;
} else {
F_21 () ;
F_22 ( F_11 , NULL , NULL , NULL ) ;
F_23 () ;
F_24 () ;
}
#endif
while ( ( V_37 = F_25 ( V_23 , V_24 , L_16 , V_39 , NULL ) ) != - 1 ) {
switch ( V_37 ) {
case 'n' :
V_30 = FALSE ;
break;
case 'h' :
printf ( L_13
L_17
L_18 ,
F_16 () ) ;
F_1 ( stdout ) ;
exit ( 0 ) ;
case 'v' :
F_26 ( L_19 , V_25 , V_26 ) ;
F_27 ( V_25 , TRUE ) ;
F_27 ( V_26 , TRUE ) ;
exit ( 0 ) ;
case '?' :
F_1 ( V_13 ) ;
exit ( 1 ) ;
}
}
V_41 = V_23 - V_45 ;
if ( V_41 == 2 ) {
V_8 = V_24 [ V_45 ] ;
V_42 = V_24 [ V_45 + 1 ] ;
}
else {
F_1 ( V_13 ) ;
exit ( 1 ) ;
}
V_3 = F_28 ( V_8 , V_46 , & V_9 , & V_10 , TRUE ) ;
if ( V_3 == NULL ) {
fprintf ( V_13 , L_20 , V_8 ,
F_5 ( V_9 ) ) ;
if ( V_10 != NULL ) {
fprintf ( V_13 , L_9 , V_10 ) ;
F_6 ( V_10 ) ;
}
exit ( 1 ) ;
}
F_3 ( L_21 , F_29 ( V_3 ) ) ;
V_32 = F_30 ( V_3 ) ;
V_33 = F_31 ( V_3 ) ;
V_34 = F_32 ( V_3 ) ;
if ( strcmp ( V_42 , L_22 ) == 0 ) {
V_4 = F_33 ( F_29 ( V_3 ) , F_34 ( V_3 ) ,
65535 , FALSE , V_32 , V_33 , V_34 , & V_9 ) ;
V_42 = L_23 ;
} else {
V_4 = F_35 ( V_42 , F_29 ( V_3 ) , F_34 ( V_3 ) ,
65535 , FALSE , V_32 , V_33 , V_34 , & V_9 ) ;
}
F_6 ( V_33 ) ;
V_33 = NULL ;
if ( V_4 == NULL ) {
fprintf ( V_13 , L_24 ,
V_42 , F_5 ( V_9 ) ) ;
F_36 ( V_32 ) ;
F_36 ( V_34 ) ;
exit ( 1 ) ;
}
V_35 = F_37 () ;
while ( F_38 ( V_3 , & V_9 , & V_10 , & V_28 ) ) {
T_2 * V_47 ;
V_6 = F_39 ( V_3 ) ;
V_47 = F_40 ( T_2 ) ;
V_47 -> V_48 = V_35 -> V_49 + 1 ;
V_47 -> V_12 = V_28 ;
if ( V_6 -> V_50 & V_51 ) {
V_47 -> V_15 = V_6 -> V_14 ;
} else {
F_41 ( & V_47 -> V_15 ) ;
}
if ( V_36 && F_9 ( & V_47 , & V_36 ) < 0 ) {
V_29 ++ ;
}
F_42 ( V_35 , V_47 ) ;
V_36 = V_47 ;
}
if ( V_9 != 0 ) {
fprintf ( V_13 ,
L_25 ,
V_8 , F_5 ( V_9 ) ) ;
if ( V_10 != NULL ) {
fprintf ( V_13 , L_9 , V_10 ) ;
F_6 ( V_10 ) ;
}
}
printf ( L_26 , V_35 -> V_49 , V_29 ) ;
if ( V_29 > 0 ) {
F_43 ( V_35 , F_9 ) ;
}
F_44 ( & V_27 ) ;
F_45 ( & V_7 , 1500 ) ;
for ( V_31 = 0 ; V_31 < V_35 -> V_49 ; V_31 ++ ) {
T_2 * V_2 = ( T_2 * ) V_35 -> V_52 [ V_31 ] ;
if ( V_30 || ( V_29 > 0 ) ) {
F_2 ( V_2 , V_3 , V_4 , & V_27 , & V_7 , V_8 ) ;
}
F_46 ( T_2 , V_2 ) ;
}
F_47 ( & V_27 ) ;
F_48 ( & V_7 ) ;
if ( ! V_30 && ( V_29 == 0 ) ) {
printf ( L_27 ) ;
}
F_49 ( V_35 , TRUE ) ;
if ( ! F_50 ( V_4 , & V_9 ) ) {
fprintf ( V_13 , L_28 , V_42 ,
F_5 ( V_9 ) ) ;
F_36 ( V_32 ) ;
F_36 ( V_34 ) ;
exit ( 1 ) ;
}
F_36 ( V_32 ) ;
F_36 ( V_34 ) ;
F_51 ( V_3 ) ;
return 0 ;
}
