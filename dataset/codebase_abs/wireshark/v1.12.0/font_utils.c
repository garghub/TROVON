T_1 * F_1 ( void )
{
return V_1 ;
}
static void
F_2 ( T_1 * V_2 )
{
F_3 ( V_1 ) ;
V_1 = V_2 ;
}
void
F_4 ( T_2 * T_3 V_3 , T_4 T_5 V_3 )
{
T_6 V_4 ;
V_4 = V_5 . V_6 ;
V_5 . V_6 ++ ;
switch ( F_5 () ) {
case V_7 :
break;
case V_8 :
V_5 . V_6 = V_4 ;
break;
case V_9 :
F_6 ( V_10 , V_11 ,
L_1 ) ;
V_5 . V_6 = V_4 ;
break;
}
}
void
F_7 ( T_2 * T_3 V_3 , T_4 T_5 V_3 )
{
T_6 V_4 ;
V_4 = V_5 . V_6 ;
V_5 . V_6 -- ;
switch ( F_5 () ) {
case V_7 :
break;
case V_8 :
V_5 . V_6 = V_4 ;
break;
case V_9 :
F_6 ( V_10 , V_11 ,
L_2 ) ;
V_5 . V_6 = V_4 ;
break;
}
}
void
F_8 ( T_2 * T_3 V_3 , T_4 T_5 V_3 )
{
T_6 V_4 ;
V_4 = V_5 . V_6 ;
V_5 . V_6 = 0 ;
switch ( F_5 () ) {
case V_7 :
break;
case V_8 :
V_5 . V_6 = V_4 ;
break;
case V_9 :
F_6 ( V_10 , V_11 ,
L_3 ) ;
V_5 . V_6 = V_4 ;
break;
}
}
T_7
F_9 ( T_8 * V_12 )
{
T_1 * V_13 ;
V_13 = F_10 ( V_12 ) ;
if ( V_13 == NULL ) {
F_6 ( V_10 , V_11 ,
L_4 ) ;
return FALSE ;
}
return TRUE ;
}
static char *
F_11 ( char * V_14 )
{
char * V_15 ;
char * V_16 ;
char * V_17 ;
long V_18 ;
if ( V_5 . V_6 == 0 ) {
return F_12 ( V_14 ) ;
}
V_16 = F_12 ( V_14 ) ;
V_17 = strrchr ( V_16 , ' ' ) ;
* V_17 = '\0' ;
V_17 ++ ;
V_18 = strtol ( V_17 , NULL , 10 ) ;
V_18 += V_5 . V_6 ;
V_15 = F_13 ( L_5 , V_16 , V_18 ) ;
F_14 ( V_16 ) ;
return V_15 ;
}
T_9
F_5 ( void ) {
char * V_14 ;
T_1 * V_13 ;
T_1 * V_19 = NULL ;
V_14 = F_11 ( V_20 . V_21 ) ;
if ( V_14 == NULL ) {
F_6 ( V_10 , V_11 ,
L_6 ) ;
return V_8 ;
}
V_13 = F_10 ( V_14 ) ;
if ( V_13 == NULL ) {
F_14 ( V_14 ) ;
return V_9 ;
}
F_15 ( V_13 ) ;
F_16 ( V_13 ) ;
V_19 = V_1 ;
F_2 ( V_13 ) ;
F_17 () ;
F_18 () ;
if ( V_19 != NULL )
F_19 ( V_19 ) ;
F_14 ( V_14 ) ;
return V_7 ;
}
static void
F_20 ( const char * V_22 )
{
T_10 * V_23 ;
if ( V_22 != NULL && * V_22 == 0 ) return;
V_23 = F_21 () ;
if ( V_22 == NULL ) {
F_22 ( F_23 ( V_23 ) , L_7 , V_24 , NULL ) ;
} else {
T_2 * T_3 ;
T_1 * V_25 ;
T_11 * V_26 ;
T_12 * V_27 ;
T_3 = F_24 ( NULL ) ;
V_25 = F_10 ( V_22 ) ;
V_26 = F_25 ( T_3 ) ;
V_27 = F_26 ( V_26 , V_25 ) ;
if ( V_27 != NULL ) {
F_27 ( V_24 , V_22 , 128 ) ;
V_24 [ 127 ] = '\0' ;
F_22 ( F_23 ( V_23 ) , L_7 , V_24 , NULL ) ;
}
F_28 ( T_3 ) ;
F_19 ( V_25 ) ;
}
}
static char * F_29 ( void )
{
T_8 * V_28 = NULL ;
T_13 V_29 ;
memset ( & V_29 , 0 , sizeof V_29 ) ;
V_29 . V_30 = sizeof V_29 ;
if ( F_30 ( V_31 , V_29 . V_30 , & V_29 , 0 ) ) {
T_14 V_32 = F_31 ( 0 ) ;
double V_33 = 72.0 / F_32 ( V_32 , V_34 ) ;
int V_35 = ( int ) ( V_29 . V_36 . V_37 * V_33 ) ;
if ( V_35 < 0 ) V_35 = - V_35 ;
V_28 = F_13 ( L_8 , V_29 . V_36 . V_38 ,
V_35 ) ;
F_33 ( 0 , V_32 ) ;
}
return V_28 ;
}
static void F_34 ( void )
{
T_8 * V_28 ;
V_28 = F_29 () ;
if ( V_28 != NULL ) {
int V_39 ;
T_1 * V_25 ;
T_12 * V_27 ;
T_11 * V_26 ;
T_2 * T_3 ;
V_25 = F_10 ( V_28 ) ;
T_3 = F_24 ( NULL ) ;
V_26 = F_25 ( T_3 ) ;
V_27 = F_26 ( V_26 , V_25 ) ;
V_39 = ( V_27 != NULL ) ;
F_19 ( V_25 ) ;
F_35 ( F_23 ( V_26 ) ) ;
F_28 ( T_3 ) ;
if ( V_39 ) F_20 ( V_28 ) ;
F_14 ( V_28 ) ;
}
}
void F_36 ( void )
{
#ifdef F_37
F_34 () ;
#endif
V_1 = F_10 ( V_20 . V_21 ) ;
if ( V_1 == NULL ) {
fprintf ( V_40 , L_9 ,
V_20 . V_21 ) ;
if ( ( V_1 = F_10 ( L_10 ) ) == NULL )
{
fprintf ( V_40 , L_11 ) ;
exit ( 1 ) ;
}
F_14 ( V_20 . V_21 ) ;
V_20 . V_21 = F_12 ( L_10 ) ;
}
F_2 ( V_1 ) ;
}
