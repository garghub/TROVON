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
F_11 ( T_9 * V_22 )
{
F_12 ( V_22 , L_11 ) ;
#ifdef F_13
F_12 ( V_22 , L_12 ) ;
#ifdef F_14
F_12 ( V_22 , F_14 ) ;
#else
F_12 ( V_22 , L_13 ) ;
#endif
#else
F_12 ( V_22 , L_14 ) ;
#endif
}
static void
F_15 ( T_9 * V_22 )
{
#if F_16 ( F_13 ) && ! F_16 ( V_23 )
F_17 ( V_22 , L_15 , F_18 () ) ;
#endif
}
int
main ( int V_24 , char * V_25 [] )
{
T_9 * V_26 ;
T_9 * V_27 ;
T_3 * V_3 = NULL ;
T_4 * V_4 = NULL ;
struct V_5 V_28 ;
T_5 V_7 ;
int V_9 ;
T_6 * V_10 ;
T_10 V_29 ;
const struct V_5 * V_6 ;
T_11 V_30 = 0 ;
T_12 V_31 = TRUE ;
T_11 V_32 ;
T_13 * V_33 = NULL ;
T_14 * V_34 = NULL ;
T_15 * V_35 = NULL ;
T_16 * V_36 ;
T_2 * V_37 = NULL ;
int V_38 ;
F_19 (cast-qual)
static const struct V_39 V_40 [] = {
{ ( char * ) L_16 , V_41 , NULL , 'h' } ,
{ ( char * ) L_17 , V_41 , NULL , 'v' } ,
{ 0 , 0 , 0 , 0 }
} ;
F_20 (cast-qual)
int V_42 ;
char * V_8 ;
const char * V_43 ;
V_26 = F_21 ( NULL , F_11 ) ;
V_27 = F_22 ( F_15 ) ;
F_23 ( L_18
L_1
L_19
L_1
L_19 ,
F_24 () , V_26 -> V_22 , V_27 -> V_22 ) ;
while ( ( V_38 = F_25 ( V_24 , V_25 , L_20 , V_40 , NULL ) ) != - 1 ) {
switch ( V_38 ) {
case 'n' :
V_31 = FALSE ;
break;
case 'h' :
printf ( L_18
L_21
L_22 ,
F_24 () ) ;
F_1 ( stdout ) ;
exit ( 0 ) ;
case 'v' :
F_26 ( L_23 , V_26 , V_27 ) ;
F_27 ( V_26 , TRUE ) ;
F_27 ( V_27 , TRUE ) ;
exit ( 0 ) ;
case '?' :
F_1 ( V_13 ) ;
exit ( 1 ) ;
}
}
V_42 = V_24 - V_44 ;
if ( V_42 == 2 ) {
V_8 = V_25 [ V_44 ] ;
V_43 = V_25 [ V_44 + 1 ] ;
}
else {
F_1 ( V_13 ) ;
exit ( 1 ) ;
}
V_3 = F_28 ( V_8 , V_45 , & V_9 , & V_10 , TRUE ) ;
if ( V_3 == NULL ) {
fprintf ( V_13 , L_24 , V_8 ,
F_5 ( V_9 ) ) ;
if ( V_10 != NULL ) {
fprintf ( V_13 , L_9 , V_10 ) ;
F_6 ( V_10 ) ;
}
exit ( 1 ) ;
}
F_3 ( L_25 , F_29 ( V_3 ) ) ;
V_33 = F_30 ( V_3 ) ;
V_34 = F_31 ( V_3 ) ;
V_35 = F_32 ( V_3 ) ;
if ( strcmp ( V_43 , L_26 ) == 0 ) {
V_4 = F_33 ( F_29 ( V_3 ) , F_34 ( V_3 ) ,
65535 , FALSE , V_33 , V_34 , V_35 , & V_9 ) ;
V_43 = L_27 ;
} else {
V_4 = F_35 ( V_43 , F_29 ( V_3 ) , F_34 ( V_3 ) ,
65535 , FALSE , V_33 , V_34 , V_35 , & V_9 ) ;
}
F_6 ( V_34 ) ;
V_34 = NULL ;
if ( V_4 == NULL ) {
fprintf ( V_13 , L_28 ,
V_43 , F_5 ( V_9 ) ) ;
F_36 ( V_33 ) ;
F_37 ( V_35 ) ;
exit ( 1 ) ;
}
V_36 = F_38 () ;
while ( F_39 ( V_3 , & V_9 , & V_10 , & V_29 ) ) {
T_2 * V_46 ;
V_6 = F_40 ( V_3 ) ;
V_46 = F_41 ( T_2 ) ;
V_46 -> V_47 = V_36 -> V_48 + 1 ;
V_46 -> V_12 = V_29 ;
if ( V_6 -> V_49 & V_50 ) {
V_46 -> V_15 = V_6 -> V_14 ;
} else {
F_42 ( & V_46 -> V_15 ) ;
}
if ( V_37 && F_9 ( & V_46 , & V_37 ) < 0 ) {
V_30 ++ ;
}
F_43 ( V_36 , V_46 ) ;
V_37 = V_46 ;
}
if ( V_9 != 0 ) {
fprintf ( V_13 ,
L_29 ,
V_8 , F_5 ( V_9 ) ) ;
if ( V_10 != NULL ) {
fprintf ( V_13 , L_9 , V_10 ) ;
F_6 ( V_10 ) ;
}
}
printf ( L_30 , V_36 -> V_48 , V_30 ) ;
if ( V_30 > 0 ) {
F_44 ( V_36 , F_9 ) ;
}
F_45 ( & V_28 ) ;
F_46 ( & V_7 , 1500 ) ;
for ( V_32 = 0 ; V_32 < V_36 -> V_48 ; V_32 ++ ) {
T_2 * V_2 = ( T_2 * ) V_36 -> V_51 [ V_32 ] ;
if ( V_31 || ( V_30 > 0 ) ) {
F_2 ( V_2 , V_3 , V_4 , & V_28 , & V_7 , V_8 ) ;
}
F_47 ( T_2 , V_2 ) ;
}
F_48 ( & V_28 ) ;
F_49 ( & V_7 ) ;
if ( ! V_31 && ( V_30 == 0 ) ) {
printf ( L_31 ) ;
}
F_50 ( V_36 , TRUE ) ;
if ( ! F_51 ( V_4 , & V_9 ) ) {
fprintf ( V_13 , L_32 , V_43 ,
F_5 ( V_9 ) ) ;
F_36 ( V_33 ) ;
F_37 ( V_35 ) ;
exit ( 1 ) ;
}
F_36 ( V_33 ) ;
F_37 ( V_35 ) ;
F_52 ( V_3 ) ;
return 0 ;
}
