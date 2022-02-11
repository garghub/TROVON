T_1 * F_1 ( void )
{
return V_1 ;
}
T_1 * F_2 ( void )
{
return V_2 ;
}
static void
F_3 ( T_1 * V_3 , T_1 * V_4 )
{
F_4 ( V_1 && V_2 ) ;
V_1 = V_3 ;
V_2 = V_4 ;
}
void
F_5 ( T_2 * T_3 V_5 , T_4 T_5 V_5 )
{
T_6 V_6 ;
V_6 = V_7 . V_8 ;
V_7 . V_8 ++ ;
switch ( F_6 () ) {
case V_9 :
break;
case V_10 :
V_7 . V_8 = V_6 ;
break;
case V_11 :
F_7 ( V_12 , V_13 ,
L_1 ) ;
V_7 . V_8 = V_6 ;
break;
}
}
void
F_8 ( T_2 * T_3 V_5 , T_4 T_5 V_5 )
{
T_6 V_6 ;
V_6 = V_7 . V_8 ;
V_7 . V_8 -- ;
switch ( F_6 () ) {
case V_9 :
break;
case V_10 :
V_7 . V_8 = V_6 ;
break;
case V_11 :
F_7 ( V_12 , V_13 ,
L_2 ) ;
V_7 . V_8 = V_6 ;
break;
}
}
void
F_9 ( T_2 * T_3 V_5 , T_4 T_5 V_5 )
{
T_6 V_6 ;
V_6 = V_7 . V_8 ;
V_7 . V_8 = 0 ;
switch ( F_6 () ) {
case V_9 :
break;
case V_10 :
V_7 . V_8 = V_6 ;
break;
case V_11 :
F_7 ( V_12 , V_13 ,
L_3 ) ;
V_7 . V_8 = V_6 ;
break;
}
}
T_7
F_10 ( T_8 * V_14 )
{
T_1 * V_15 , * V_16 ;
V_15 = F_11 ( V_14 ) ;
if ( V_15 == NULL ) {
F_7 ( V_12 , V_13 ,
L_4 ) ;
return FALSE ;
}
V_16 = F_12 ( V_15 ) ;
F_13 ( V_16 , V_17 ) ;
if ( V_16 == NULL ) {
F_7 ( V_12 , V_13 ,
L_5 ) ;
F_14 ( V_15 ) ;
return FALSE ;
}
return TRUE ;
}
static char *
F_15 ( char * V_18 )
{
char * V_19 ;
char * V_20 ;
char * V_21 ;
long V_22 ;
if ( V_7 . V_8 == 0 ) {
return F_16 ( V_18 ) ;
}
V_20 = F_16 ( V_18 ) ;
V_21 = strrchr ( V_20 , ' ' ) ;
* V_21 = '\0' ;
V_21 ++ ;
V_22 = strtol ( V_21 , NULL , 10 ) ;
V_22 += V_7 . V_8 ;
V_19 = F_17 ( L_6 , V_20 , V_22 ) ;
F_18 ( V_20 ) ;
return V_19 ;
}
T_9
F_6 ( void ) {
char * V_18 ;
T_1 * V_15 , * V_16 ;
T_1 * V_23 = NULL , * V_24 = NULL ;
V_18 = F_15 ( V_25 . V_18 ) ;
if ( V_18 == NULL ) {
F_7 ( V_12 , V_13 ,
L_7 ) ;
return V_10 ;
}
V_15 = F_11 ( V_18 ) ;
V_16 = F_12 ( V_15 ) ;
F_13 ( V_16 , V_17 ) ;
if ( V_15 == NULL || V_16 == NULL ) {
if ( V_15 != NULL )
F_14 ( V_15 ) ;
if ( V_16 != NULL )
F_14 ( V_16 ) ;
F_18 ( V_18 ) ;
return V_11 ;
}
F_19 ( V_15 ) ;
F_20 ( V_15 ) ;
V_23 = V_1 ;
V_24 = V_2 ;
F_3 ( V_15 , V_16 ) ;
F_21 () ;
F_22 () ;
if ( V_23 != NULL )
F_14 ( V_23 ) ;
if ( V_24 != NULL )
F_14 ( V_24 ) ;
F_18 ( V_18 ) ;
return V_9 ;
}
static void
F_23 ( const char * V_26 )
{
T_10 * V_27 ;
if ( V_26 != NULL && * V_26 == 0 ) return;
V_27 = F_24 () ;
if ( V_26 == NULL ) {
F_25 ( F_26 ( V_27 ) , L_8 , V_28 , NULL ) ;
} else {
T_2 * T_3 ;
T_1 * V_29 ;
T_11 * V_30 ;
T_12 * V_31 ;
T_3 = F_27 ( NULL ) ;
V_29 = F_11 ( V_26 ) ;
V_30 = F_28 ( T_3 ) ;
V_31 = F_29 ( V_30 , V_29 ) ;
if ( V_31 != NULL ) {
F_30 ( V_28 , V_26 , 128 ) ;
V_28 [ 127 ] = '\0' ;
F_25 ( F_26 ( V_27 ) , L_8 , V_28 , NULL ) ;
}
F_31 ( T_3 ) ;
F_14 ( V_29 ) ;
}
}
static char * F_32 ( void )
{
T_8 * V_32 = NULL ;
T_13 V_33 ;
memset ( & V_33 , 0 , sizeof V_33 ) ;
V_33 . V_34 = sizeof V_33 ;
if ( F_33 ( V_35 , V_33 . V_34 , & V_33 , 0 ) ) {
T_14 V_36 = F_34 ( 0 ) ;
double V_37 = 72.0 / F_35 ( V_36 , V_38 ) ;
int V_39 = ( int ) ( V_33 . V_40 . V_41 * V_37 ) ;
if ( V_39 < 0 ) V_39 = - V_39 ;
V_32 = F_17 ( L_9 , V_33 . V_40 . V_42 ,
V_39 ) ;
F_36 ( 0 , V_36 ) ;
}
return V_32 ;
}
static void F_37 ( void )
{
T_8 * V_32 ;
V_32 = F_32 () ;
if ( V_32 != NULL ) {
int V_43 = 0 ;
T_1 * V_29 ;
T_12 * V_31 ;
T_11 * V_30 ;
T_2 * T_3 ;
V_29 = F_11 ( V_32 ) ;
T_3 = F_27 ( NULL ) ;
V_30 = F_28 ( T_3 ) ;
V_31 = F_29 ( V_30 , V_29 ) ;
V_43 = ( V_31 != NULL ) ;
F_14 ( V_29 ) ;
F_38 ( F_26 ( V_30 ) ) ;
F_31 ( T_3 ) ;
if ( V_43 ) F_23 ( V_32 ) ;
F_18 ( V_32 ) ;
}
}
void F_39 ( void )
{
#ifdef F_40
F_37 () ;
#endif
V_1 = F_11 ( V_25 . V_18 ) ;
V_2 = F_12 ( V_1 ) ;
F_13 ( V_2 , V_17 ) ;
if ( V_1 == NULL || V_2 == NULL ) {
if ( V_1 == NULL ) {
fprintf ( V_44 , L_10 ,
V_25 . V_18 ) ;
} else {
F_14 ( V_1 ) ;
}
if ( V_2 == NULL ) {
fprintf ( V_44 , L_11
L_12 , V_25 . V_18 ) ;
} else {
F_14 ( V_2 ) ;
}
if ( ( V_1 = F_11 ( L_13 ) ) == NULL )
{
fprintf ( V_44 , L_14 ) ;
exit ( 1 ) ;
}
if ( ( V_2 = F_12 ( V_1 ) ) == NULL ) {
fprintf ( V_44 , L_15 ) ;
exit ( 1 ) ;
}
F_18 ( V_25 . V_18 ) ;
F_13 ( V_2 , V_17 ) ;
V_25 . V_18 = F_16 ( L_13 ) ;
}
F_3 ( V_1 , V_2 ) ;
}
