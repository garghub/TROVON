static void
F_1 ( T_1 * V_1 , T_1 * V_2 )
{
printf ( L_1
L_2
L_3
L_2
L_3
L_2
L_3 ,
F_2 () , F_3 () ,
V_1 -> V_3 , V_2 -> V_3 ) ;
}
static void
F_4 ( T_2 * V_4 )
{
fprintf ( V_4 , L_2 ) ;
fprintf ( V_4 , L_4 ) ;
fprintf ( V_4 , L_2 ) ;
fprintf ( V_4 , L_5 ) ;
fprintf ( V_4 , L_6 ) ;
fprintf ( V_4 , L_7 ) ;
}
static void
F_5 ( T_3 * V_5 , T_4 * V_6 , T_5 * V_7 , T_6 * V_8 ,
const char * V_9 )
{
int V_10 ;
T_7 * V_11 ;
struct V_12 V_13 ;
memset ( & V_13 , 0 , sizeof( struct V_12 ) ) ;
F_6 ( L_8 V_14 L_9 ,
V_5 -> V_15 ) ;
if ( ! F_7 ( V_6 , V_5 -> V_15 , & V_13 , V_8 , & V_10 , & V_11 ) ) {
if ( V_10 != 0 ) {
fprintf ( V_16 ,
L_10 ,
V_9 , F_8 ( V_10 ) ) ;
switch ( V_10 ) {
case V_17 :
case V_18 :
case V_19 :
fprintf ( V_16 , L_11 , V_11 ) ;
F_9 ( V_11 ) ;
break;
}
exit ( 1 ) ;
}
}
V_13 . V_20 = V_5 -> time ;
if ( ! F_10 ( V_7 , & V_13 , F_11 ( V_8 ) , & V_10 ) ) {
fprintf ( V_16 , L_12 ,
F_8 ( V_10 ) ) ;
exit ( 1 ) ;
}
}
static int
F_12 ( T_8 V_21 , T_8 V_22 )
{
const T_3 * V_23 = * ( const T_3 * const * ) V_21 ;
const T_3 * V_24 = * ( const T_3 * const * ) V_22 ;
const T_9 * V_25 = & V_23 -> time ;
const T_9 * V_26 = & V_24 -> time ;
return F_13 ( V_25 , V_26 ) ;
}
static void
F_14 ( T_1 * V_3 )
{
F_15 ( V_3 , L_13 ) ;
#ifdef F_16
F_15 ( V_3 , L_14 ) ;
#ifdef F_17
F_15 ( V_3 , F_17 ) ;
#else
F_15 ( V_3 , L_15 ) ;
#endif
#else
F_15 ( V_3 , L_16 ) ;
#endif
}
static void
F_18 ( T_1 * V_3 )
{
#if F_19 ( F_16 ) && ! F_19 ( V_27 )
F_20 ( V_3 , L_17 , F_21 () ) ;
#endif
}
int
main ( int V_28 , char * V_29 [] )
{
T_1 * V_1 ;
T_1 * V_2 ;
T_4 * V_6 = NULL ;
T_5 * V_7 = NULL ;
T_6 V_8 ;
int V_10 ;
T_7 * V_11 ;
T_10 V_30 ;
const struct V_12 * V_13 ;
T_11 V_31 = 0 ;
T_12 V_32 = TRUE ;
T_11 V_33 ;
T_13 * V_34 ;
T_14 * V_35 ;
T_15 * V_36 ;
T_3 * V_37 = NULL ;
int V_38 ;
static const struct V_39 V_40 [] = {
{ ( char * ) L_18 , V_41 , NULL , 'h' } ,
{ ( char * ) L_19 , V_41 , NULL , 'v' } ,
{ 0 , 0 , 0 , 0 }
} ;
int V_42 ;
char * V_9 ;
char * V_43 ;
V_1 = F_22 ( L_20 ) ;
F_23 ( V_1 , NULL , F_14 ) ;
V_2 = F_22 ( L_21 ) ;
F_24 ( V_2 , F_18 ) ;
F_25 ( L_1
L_2
L_3
L_2
L_3 ,
F_2 () , V_1 -> V_3 , V_2 -> V_3 ) ;
while ( ( V_38 = F_26 ( V_28 , V_29 , L_22 , V_40 , NULL ) ) != - 1 ) {
switch ( V_38 ) {
case 'n' :
V_32 = FALSE ;
break;
case 'h' :
printf ( L_1
L_23
L_24 ,
F_2 () ) ;
F_4 ( stdout ) ;
exit ( 0 ) ;
case 'v' :
F_1 ( V_1 , V_2 ) ;
F_27 ( V_1 , TRUE ) ;
F_27 ( V_2 , TRUE ) ;
exit ( 0 ) ;
case '?' :
F_4 ( V_16 ) ;
exit ( 1 ) ;
}
}
V_42 = V_28 - V_44 ;
if ( V_42 == 2 ) {
V_9 = V_29 [ V_44 ] ;
V_43 = V_29 [ V_44 + 1 ] ;
}
else {
F_4 ( V_16 ) ;
exit ( 1 ) ;
}
V_6 = F_28 ( V_9 , V_45 , & V_10 , & V_11 , TRUE ) ;
if ( V_6 == NULL ) {
fprintf ( V_16 , L_25 , V_9 ,
F_8 ( V_10 ) ) ;
switch ( V_10 ) {
case V_17 :
case V_18 :
case V_19 :
fprintf ( V_16 , L_11 , V_11 ) ;
F_9 ( V_11 ) ;
break;
}
exit ( 1 ) ;
}
F_6 ( L_26 , F_29 ( V_6 ) ) ;
V_34 = F_30 ( V_6 ) ;
V_35 = F_31 ( V_6 ) ;
V_7 = F_32 ( V_43 , F_29 ( V_6 ) , F_33 ( V_6 ) ,
65535 , FALSE , V_34 , V_35 , & V_10 ) ;
F_9 ( V_35 ) ;
if ( V_7 == NULL ) {
fprintf ( V_16 , L_27 ,
V_43 , F_8 ( V_10 ) ) ;
F_9 ( V_34 ) ;
exit ( 1 ) ;
}
V_36 = F_34 () ;
while ( F_35 ( V_6 , & V_10 , & V_11 , & V_30 ) ) {
T_3 * V_46 ;
V_13 = F_36 ( V_6 ) ;
V_46 = F_37 ( T_3 ) ;
V_46 -> V_47 = V_36 -> V_48 + 1 ;
V_46 -> V_15 = V_30 ;
if ( V_13 -> V_49 & V_50 ) {
V_46 -> time = V_13 -> V_20 ;
} else {
F_38 ( & V_46 -> time ) ;
}
if ( V_37 && F_12 ( & V_46 , & V_37 ) < 0 ) {
V_31 ++ ;
}
F_39 ( V_36 , V_46 ) ;
V_37 = V_46 ;
}
if ( V_10 != 0 ) {
fprintf ( V_16 ,
L_28 ,
V_9 , F_8 ( V_10 ) ) ;
switch ( V_10 ) {
case V_17 :
case V_18 :
case V_19 :
fprintf ( V_16 , L_11 , V_11 ) ;
F_9 ( V_11 ) ;
break;
}
}
printf ( L_29 , V_36 -> V_48 , V_31 ) ;
if ( V_31 > 0 ) {
F_40 ( V_36 , F_12 ) ;
}
F_41 ( & V_8 , 1500 ) ;
for ( V_33 = 0 ; V_33 < V_36 -> V_48 ; V_33 ++ ) {
T_3 * V_5 = ( T_3 * ) V_36 -> V_51 [ V_33 ] ;
if ( V_32 || ( V_31 > 0 ) ) {
F_5 ( V_5 , V_6 , V_7 , & V_8 , V_9 ) ;
}
F_42 ( T_3 , V_5 ) ;
}
F_43 ( & V_8 ) ;
if ( ! V_32 && ( V_31 == 0 ) ) {
printf ( L_30 ) ;
}
F_44 ( V_36 , TRUE ) ;
if ( ! F_45 ( V_7 , & V_10 ) ) {
fprintf ( V_16 , L_31 , V_43 ,
F_8 ( V_10 ) ) ;
F_9 ( V_34 ) ;
exit ( 1 ) ;
}
F_9 ( V_34 ) ;
F_46 ( V_6 ) ;
return 0 ;
}
