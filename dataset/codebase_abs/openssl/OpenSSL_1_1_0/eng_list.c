static void F_1 ( void )
{
T_1 * V_1 = V_2 ;
while ( V_1 != NULL ) {
F_2 ( V_1 ) ;
V_1 = V_2 ;
}
return;
}
static int F_3 ( T_1 * V_3 )
{
int V_4 = 0 ;
T_1 * V_1 = NULL ;
if ( V_3 == NULL ) {
F_4 ( V_5 , V_6 ) ;
return 0 ;
}
V_1 = V_2 ;
while ( V_1 && ! V_4 ) {
V_4 = ( strcmp ( V_1 -> V_7 , V_3 -> V_7 ) == 0 ) ;
V_1 = V_1 -> V_8 ;
}
if ( V_4 ) {
F_4 ( V_5 , V_9 ) ;
return 0 ;
}
if ( V_2 == NULL ) {
if ( V_10 ) {
F_4 ( V_5 , V_11 ) ;
return 0 ;
}
V_2 = V_3 ;
V_3 -> V_12 = NULL ;
F_5 ( F_1 ) ;
} else {
if ( ( V_10 == NULL ) || ( V_10 -> V_8 != NULL ) ) {
F_4 ( V_5 , V_11 ) ;
return 0 ;
}
V_10 -> V_8 = V_3 ;
V_3 -> V_12 = V_10 ;
}
V_3 -> V_13 ++ ;
F_6 ( V_3 , 0 , 1 ) ;
V_10 = V_3 ;
V_3 -> V_8 = NULL ;
return 1 ;
}
static int F_7 ( T_1 * V_3 )
{
T_1 * V_1 ;
if ( V_3 == NULL ) {
F_4 ( V_14 , V_6 ) ;
return 0 ;
}
V_1 = V_2 ;
while ( V_1 && ( V_1 != V_3 ) )
V_1 = V_1 -> V_8 ;
if ( V_1 == NULL ) {
F_4 ( V_14 ,
V_15 ) ;
return 0 ;
}
if ( V_3 -> V_8 )
V_3 -> V_8 -> V_12 = V_3 -> V_12 ;
if ( V_3 -> V_12 )
V_3 -> V_12 -> V_8 = V_3 -> V_8 ;
if ( V_2 == V_3 )
V_2 = V_3 -> V_8 ;
if ( V_10 == V_3 )
V_10 = V_3 -> V_12 ;
F_8 ( V_3 , 0 ) ;
return 1 ;
}
T_1 * F_9 ( void )
{
T_1 * V_16 ;
if ( ! F_10 ( & V_17 , V_18 ) ) {
F_4 ( V_19 , V_20 ) ;
return NULL ;
}
F_11 ( V_21 ) ;
V_16 = V_2 ;
if ( V_16 ) {
V_16 -> V_13 ++ ;
F_6 ( V_16 , 0 , 1 ) ;
}
F_12 ( V_21 ) ;
return V_16 ;
}
T_1 * F_13 ( void )
{
T_1 * V_16 ;
if ( ! F_10 ( & V_17 , V_18 ) ) {
F_4 ( V_22 , V_20 ) ;
return NULL ;
}
F_11 ( V_21 ) ;
V_16 = V_10 ;
if ( V_16 ) {
V_16 -> V_13 ++ ;
F_6 ( V_16 , 0 , 1 ) ;
}
F_12 ( V_21 ) ;
return V_16 ;
}
T_1 * F_14 ( T_1 * V_3 )
{
T_1 * V_16 = NULL ;
if ( V_3 == NULL ) {
F_4 ( V_23 , V_6 ) ;
return 0 ;
}
F_11 ( V_21 ) ;
V_16 = V_3 -> V_8 ;
if ( V_16 ) {
V_16 -> V_13 ++ ;
F_6 ( V_16 , 0 , 1 ) ;
}
F_12 ( V_21 ) ;
F_15 ( V_3 ) ;
return V_16 ;
}
T_1 * F_16 ( T_1 * V_3 )
{
T_1 * V_16 = NULL ;
if ( V_3 == NULL ) {
F_4 ( V_24 , V_6 ) ;
return 0 ;
}
F_11 ( V_21 ) ;
V_16 = V_3 -> V_12 ;
if ( V_16 ) {
V_16 -> V_13 ++ ;
F_6 ( V_16 , 0 , 1 ) ;
}
F_12 ( V_21 ) ;
F_15 ( V_3 ) ;
return V_16 ;
}
int F_17 ( T_1 * V_3 )
{
int V_25 = 1 ;
if ( V_3 == NULL ) {
F_4 ( V_26 , V_6 ) ;
return 0 ;
}
if ( ( V_3 -> V_7 == NULL ) || ( V_3 -> V_27 == NULL ) ) {
F_4 ( V_26 , V_28 ) ;
return 0 ;
}
F_11 ( V_21 ) ;
if ( ! F_3 ( V_3 ) ) {
F_4 ( V_26 , V_11 ) ;
V_25 = 0 ;
}
F_12 ( V_21 ) ;
return V_25 ;
}
int F_2 ( T_1 * V_3 )
{
int V_25 = 1 ;
if ( V_3 == NULL ) {
F_4 ( V_29 , V_6 ) ;
return 0 ;
}
F_11 ( V_21 ) ;
if ( ! F_7 ( V_3 ) ) {
F_4 ( V_29 , V_11 ) ;
V_25 = 0 ;
}
F_12 ( V_21 ) ;
return V_25 ;
}
static void F_18 ( T_1 * V_30 , const T_1 * V_31 )
{
V_30 -> V_7 = V_31 -> V_7 ;
V_30 -> V_27 = V_31 -> V_27 ;
#ifndef F_19
V_30 -> V_32 = V_31 -> V_32 ;
#endif
#ifndef F_20
V_30 -> V_33 = V_31 -> V_33 ;
#endif
#ifndef F_21
V_30 -> V_34 = V_31 -> V_34 ;
#endif
#ifndef F_22
V_30 -> V_35 = V_31 -> V_35 ;
#endif
V_30 -> V_36 = V_31 -> V_36 ;
V_30 -> V_37 = V_31 -> V_37 ;
V_30 -> V_38 = V_31 -> V_38 ;
V_30 -> V_39 = V_31 -> V_39 ;
V_30 -> V_40 = V_31 -> V_40 ;
V_30 -> V_41 = V_31 -> V_41 ;
V_30 -> V_42 = V_31 -> V_42 ;
V_30 -> V_43 = V_31 -> V_43 ;
V_30 -> V_44 = V_31 -> V_44 ;
V_30 -> V_45 = V_31 -> V_45 ;
V_30 -> V_46 = V_31 -> V_46 ;
V_30 -> V_47 = V_31 -> V_47 ;
}
T_1 * F_23 ( const char * V_7 )
{
T_1 * V_1 ;
char * V_48 = NULL ;
if ( V_7 == NULL ) {
F_4 ( V_49 , V_6 ) ;
return NULL ;
}
if ( ! F_10 ( & V_17 , V_18 ) ) {
F_4 ( V_49 , V_20 ) ;
return NULL ;
}
F_11 ( V_21 ) ;
V_1 = V_2 ;
while ( V_1 && ( strcmp ( V_7 , V_1 -> V_7 ) != 0 ) )
V_1 = V_1 -> V_8 ;
if ( V_1 != NULL ) {
if ( V_1 -> V_47 & V_50 ) {
T_1 * V_51 = F_24 () ;
if ( V_51 == NULL )
V_1 = NULL ;
else {
F_18 ( V_51 , V_1 ) ;
V_1 = V_51 ;
}
} else {
V_1 -> V_13 ++ ;
F_6 ( V_1 , 0 , 1 ) ;
}
}
F_12 ( V_21 ) ;
if ( V_1 != NULL )
return V_1 ;
if ( strcmp ( V_7 , L_1 ) ) {
if ( ( V_48 = getenv ( L_2 ) ) == 0 )
V_48 = V_52 ;
V_1 = F_23 ( L_1 ) ;
if ( ! V_1 || ! F_25 ( V_1 , L_3 , V_7 , 0 ) ||
! F_25 ( V_1 , L_4 , L_5 , 0 ) ||
! F_25 ( V_1 , L_6 ,
V_48 , 0 ) ||
! F_25 ( V_1 , L_7 , L_8 , 0 ) ||
! F_25 ( V_1 , L_9 , NULL , 0 ) )
goto V_53;
return V_1 ;
}
V_53:
F_15 ( V_1 ) ;
F_4 ( V_49 , V_54 ) ;
F_26 ( 2 , L_10 , V_7 ) ;
return NULL ;
}
int F_27 ( T_1 * V_3 )
{
int V_55 ;
if ( V_3 == NULL ) {
F_4 ( V_56 , V_6 ) ;
return 0 ;
}
F_28 ( & V_3 -> V_13 , 1 , & V_55 , V_21 ) ;
return 1 ;
}
