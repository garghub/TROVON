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
struct V_5 * V_6 , T_5 * V_7 , const char * V_8 ,
const char * V_9 )
{
int V_10 ;
T_6 * V_11 ;
F_3 ( L_6 V_12 L_7 ,
V_2 -> V_13 ) ;
if ( ! F_4 ( V_3 , V_2 -> V_13 , V_6 , V_7 , & V_10 , & V_11 ) ) {
if ( V_10 != 0 ) {
fprintf ( V_14 ,
L_8 ,
V_8 ) ;
F_5 ( L_9 , V_8 , V_10 , V_11 ) ;
exit ( 1 ) ;
}
}
V_6 -> V_15 = V_2 -> V_16 ;
if ( ! F_6 ( V_4 , V_6 , F_7 ( V_7 ) , & V_10 , & V_11 ) ) {
F_8 ( L_9 , V_8 , V_9 , V_10 ,
V_11 , V_2 -> V_17 ,
F_9 ( V_3 ) ) ;
exit ( 1 ) ;
}
}
static int
F_10 ( T_7 V_18 , T_7 V_19 )
{
const T_2 * V_20 = * ( const T_2 * const * ) V_18 ;
const T_2 * V_21 = * ( const T_2 * const * ) V_19 ;
const T_8 * V_22 = & V_20 -> V_16 ;
const T_8 * V_23 = & V_21 -> V_16 ;
return F_11 ( V_22 , V_23 ) ;
}
static void
F_12 ( const char * V_24 , T_9 V_25 )
{
fprintf ( V_14 , L_10 ) ;
vfprintf ( V_14 , V_24 , V_25 ) ;
fprintf ( V_14 , L_1 ) ;
}
int
main ( int V_26 , char * V_27 [] )
{
T_10 * V_28 ;
T_10 * V_29 ;
char * V_30 ;
T_3 * V_3 = NULL ;
T_4 * V_4 = NULL ;
struct V_5 V_31 ;
T_5 V_7 ;
int V_10 ;
T_6 * V_11 ;
T_11 V_32 ;
const struct V_5 * V_6 ;
T_12 V_33 = 0 ;
T_13 V_34 = TRUE ;
T_12 V_35 ;
T_14 * V_36 = NULL ;
T_15 * V_37 = NULL ;
T_14 * V_38 = NULL ;
int V_39 = V_40 ;
T_16 * V_41 ;
T_2 * V_42 = NULL ;
int V_43 ;
static const struct V_44 V_45 [] = {
{ L_11 , V_46 , NULL , 'h' } ,
{ L_12 , V_46 , NULL , 'v' } ,
{ 0 , 0 , 0 , 0 }
} ;
int V_47 ;
char * V_8 ;
const char * V_9 ;
V_28 = F_13 ( NULL , NULL ) ;
V_29 = F_14 ( NULL ) ;
F_15 ( L_13
L_1
L_14
L_1
L_14 ,
F_16 () , V_28 -> V_48 , V_29 -> V_48 ) ;
F_17 ( V_28 , TRUE ) ;
F_17 ( V_29 , TRUE ) ;
F_18 () ;
V_30 = F_19 ( V_27 [ 0 ] , main ) ;
if ( V_30 != NULL ) {
fprintf ( V_14 ,
L_15 ,
V_30 ) ;
F_20 ( V_30 ) ;
}
F_21 () ;
#ifdef F_22
F_23 ( F_12 , F_12 ,
NULL , NULL , NULL ) ;
F_24 ( V_49 ) ;
F_25 () ;
#endif
while ( ( V_43 = F_26 ( V_26 , V_27 , L_16 , V_45 , NULL ) ) != - 1 ) {
switch ( V_43 ) {
case 'n' :
V_34 = FALSE ;
break;
case 'h' :
printf ( L_13
L_17
L_18 ,
F_16 () ) ;
F_1 ( stdout ) ;
goto V_50;
case 'v' :
V_28 = F_13 ( NULL , NULL ) ;
V_29 = F_14 ( NULL ) ;
F_27 ( L_19 , V_28 , V_29 ) ;
F_17 ( V_28 , TRUE ) ;
F_17 ( V_29 , TRUE ) ;
goto V_50;
case '?' :
F_1 ( V_14 ) ;
V_39 = V_51 ;
goto V_50;
}
}
V_47 = V_26 - V_52 ;
if ( V_47 == 2 ) {
V_8 = V_27 [ V_52 ] ;
V_9 = V_27 [ V_52 + 1 ] ;
}
else {
F_1 ( V_14 ) ;
V_39 = V_51 ;
goto V_50;
}
V_3 = F_28 ( V_8 , V_53 , & V_10 , & V_11 , TRUE ) ;
if ( V_3 == NULL ) {
F_29 ( L_9 , V_8 , V_10 , V_11 ) ;
V_39 = V_54 ;
goto V_50;
}
F_3 ( L_20 , F_9 ( V_3 ) ) ;
V_36 = F_30 ( V_3 ) ;
V_37 = F_31 ( V_3 ) ;
V_38 = F_32 ( V_3 ) ;
if ( strcmp ( V_9 , L_21 ) == 0 ) {
V_4 = F_33 ( F_9 ( V_3 ) , F_34 ( V_3 ) ,
F_35 ( V_3 ) , FALSE , V_36 , V_37 , V_38 , & V_10 ) ;
} else {
V_4 = F_36 ( V_9 , F_9 ( V_3 ) , F_34 ( V_3 ) ,
F_35 ( V_3 ) , FALSE , V_36 , V_37 , V_38 , & V_10 ) ;
}
F_20 ( V_37 ) ;
V_37 = NULL ;
if ( V_4 == NULL ) {
F_37 ( L_9 , V_9 , V_10 ,
F_9 ( V_3 ) ) ;
F_38 ( V_36 ) ;
F_38 ( V_38 ) ;
V_39 = V_55 ;
goto V_50;
}
V_41 = F_39 () ;
while ( F_40 ( V_3 , & V_10 , & V_11 , & V_32 ) ) {
T_2 * V_56 ;
V_6 = F_41 ( V_3 ) ;
V_56 = F_42 ( T_2 ) ;
V_56 -> V_17 = V_41 -> V_57 + 1 ;
V_56 -> V_13 = V_32 ;
if ( V_6 -> V_58 & V_59 ) {
V_56 -> V_16 = V_6 -> V_15 ;
} else {
F_43 ( & V_56 -> V_16 ) ;
}
if ( V_42 && F_10 ( & V_56 , & V_42 ) < 0 ) {
V_33 ++ ;
}
F_44 ( V_41 , V_56 ) ;
V_42 = V_56 ;
}
if ( V_10 != 0 ) {
F_5 ( L_9 , V_8 , V_10 , V_11 ) ;
}
printf ( L_22 , V_41 -> V_57 , V_33 ) ;
if ( V_33 > 0 ) {
F_45 ( V_41 , F_10 ) ;
}
F_46 ( & V_31 ) ;
F_47 ( & V_7 , 1500 ) ;
for ( V_35 = 0 ; V_35 < V_41 -> V_57 ; V_35 ++ ) {
T_2 * V_2 = ( T_2 * ) V_41 -> V_60 [ V_35 ] ;
if ( V_34 || ( V_33 > 0 ) ) {
F_2 ( V_2 , V_3 , V_4 , & V_31 , & V_7 , V_8 , V_9 ) ;
}
F_48 ( T_2 , V_2 ) ;
}
F_49 ( & V_31 ) ;
F_50 ( & V_7 ) ;
if ( ! V_34 && ( V_33 == 0 ) ) {
printf ( L_23 ) ;
}
F_51 ( V_41 , TRUE ) ;
if ( ! F_52 ( V_4 , & V_10 ) ) {
F_53 ( V_9 , V_10 ) ;
F_38 ( V_36 ) ;
F_38 ( V_38 ) ;
V_39 = V_55 ;
goto V_50;
}
F_38 ( V_36 ) ;
F_38 ( V_38 ) ;
F_54 ( V_3 ) ;
V_50:
F_55 () ;
F_56 () ;
#ifdef F_22
F_57 () ;
#endif
return V_39 ;
}
