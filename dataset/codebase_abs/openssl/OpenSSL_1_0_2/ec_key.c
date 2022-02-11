T_1 * F_1 ( void )
{
T_1 * V_1 ;
V_1 = ( T_1 * ) F_2 ( sizeof( T_1 ) ) ;
if ( V_1 == NULL ) {
F_3 ( V_2 , V_3 ) ;
return ( NULL ) ;
}
V_1 -> V_4 = 1 ;
V_1 -> V_5 = 0 ;
V_1 -> V_6 = NULL ;
V_1 -> V_7 = NULL ;
V_1 -> V_8 = NULL ;
V_1 -> V_9 = 0 ;
V_1 -> V_10 = V_11 ;
V_1 -> V_12 = 1 ;
V_1 -> V_13 = NULL ;
return ( V_1 ) ;
}
T_1 * F_4 ( int V_14 )
{
T_1 * V_1 = F_1 () ;
if ( V_1 == NULL )
return NULL ;
V_1 -> V_6 = F_5 ( V_14 ) ;
if ( V_1 -> V_6 == NULL ) {
F_6 ( V_1 ) ;
return NULL ;
}
return V_1 ;
}
void F_6 ( T_1 * V_15 )
{
int V_16 ;
if ( V_15 == NULL )
return;
V_16 = F_7 ( & V_15 -> V_12 , - 1 , V_17 ) ;
#ifdef F_8
F_8 ( L_1 , V_15 ) ;
#endif
if ( V_16 > 0 )
return;
#ifdef F_9
if ( V_16 < 0 ) {
fprintf ( V_18 , L_2 ) ;
abort () ;
}
#endif
if ( V_15 -> V_6 != NULL )
F_10 ( V_15 -> V_6 ) ;
if ( V_15 -> V_7 != NULL )
F_11 ( V_15 -> V_7 ) ;
if ( V_15 -> V_8 != NULL )
F_12 ( V_15 -> V_8 ) ;
F_13 ( & V_15 -> V_13 ) ;
F_14 ( ( void * ) V_15 , sizeof( T_1 ) ) ;
F_15 ( V_15 ) ;
}
T_1 * F_16 ( T_1 * V_19 , const T_1 * V_20 )
{
T_2 * V_21 ;
if ( V_19 == NULL || V_20 == NULL ) {
F_3 ( V_22 , V_23 ) ;
return NULL ;
}
if ( V_20 -> V_6 ) {
const T_3 * V_24 = F_17 ( V_20 -> V_6 ) ;
if ( V_19 -> V_6 )
F_10 ( V_19 -> V_6 ) ;
V_19 -> V_6 = F_18 ( V_24 ) ;
if ( V_19 -> V_6 == NULL )
return NULL ;
if ( ! F_19 ( V_19 -> V_6 , V_20 -> V_6 ) )
return NULL ;
}
if ( V_20 -> V_7 && V_20 -> V_6 ) {
if ( V_19 -> V_7 )
F_11 ( V_19 -> V_7 ) ;
V_19 -> V_7 = F_20 ( V_20 -> V_6 ) ;
if ( V_19 -> V_7 == NULL )
return NULL ;
if ( ! F_21 ( V_19 -> V_7 , V_20 -> V_7 ) )
return NULL ;
}
if ( V_20 -> V_8 ) {
if ( V_19 -> V_8 == NULL ) {
V_19 -> V_8 = F_22 () ;
if ( V_19 -> V_8 == NULL )
return NULL ;
}
if ( ! F_23 ( V_19 -> V_8 , V_20 -> V_8 ) )
return NULL ;
}
F_13 ( & V_19 -> V_13 ) ;
for ( V_21 = V_20 -> V_13 ; V_21 != NULL ; V_21 = V_21 -> V_25 ) {
void * V_26 = V_21 -> V_27 ( V_21 -> V_28 ) ;
if ( V_26 == NULL )
return 0 ;
if ( ! F_24
( & V_19 -> V_13 , V_26 , V_21 -> V_27 , V_21 -> V_29 ,
V_21 -> V_30 ) )
return 0 ;
}
V_19 -> V_9 = V_20 -> V_9 ;
V_19 -> V_10 = V_20 -> V_10 ;
V_19 -> V_4 = V_20 -> V_4 ;
V_19 -> V_5 = V_20 -> V_5 ;
return V_19 ;
}
T_1 * F_25 ( const T_1 * V_31 )
{
T_1 * V_1 = F_1 () ;
if ( V_1 == NULL )
return NULL ;
if ( F_16 ( V_1 , V_31 ) == NULL ) {
F_6 ( V_1 ) ;
return NULL ;
}
return V_1 ;
}
int F_26 ( T_1 * V_15 )
{
int V_16 = F_7 ( & V_15 -> V_12 , 1 , V_17 ) ;
#ifdef F_8
F_8 ( L_1 , V_15 ) ;
#endif
#ifdef F_9
if ( V_16 < 2 ) {
fprintf ( V_18 , L_3 ) ;
abort () ;
}
#endif
return ( ( V_16 > 1 ) ? 1 : 0 ) ;
}
int F_27 ( T_1 * V_32 )
{
int V_33 = 0 ;
T_4 * V_34 = NULL ;
T_5 * V_8 = NULL , * V_35 = NULL ;
T_6 * V_7 = NULL ;
#ifdef F_28
if ( F_29 () )
return F_30 ( V_32 ) ;
#endif
if ( ! V_32 || ! V_32 -> V_6 ) {
F_3 ( V_36 , V_23 ) ;
return 0 ;
}
if ( ( V_35 = F_22 () ) == NULL )
goto V_37;
if ( ( V_34 = F_31 () ) == NULL )
goto V_37;
if ( V_32 -> V_8 == NULL ) {
V_8 = F_22 () ;
if ( V_8 == NULL )
goto V_37;
} else
V_8 = V_32 -> V_8 ;
if ( ! F_32 ( V_32 -> V_6 , V_35 , V_34 ) )
goto V_37;
do
if ( ! F_33 ( V_8 , V_35 ) )
goto V_37;
while ( F_34 ( V_8 ) ) ;
if ( V_32 -> V_7 == NULL ) {
V_7 = F_20 ( V_32 -> V_6 ) ;
if ( V_7 == NULL )
goto V_37;
} else
V_7 = V_32 -> V_7 ;
if ( ! F_35 ( V_32 -> V_6 , V_7 , V_8 , NULL , NULL , V_34 ) )
goto V_37;
V_32 -> V_8 = V_8 ;
V_32 -> V_7 = V_7 ;
V_33 = 1 ;
V_37:
if ( V_35 )
F_36 ( V_35 ) ;
if ( V_7 != NULL && V_32 -> V_7 == NULL )
F_11 ( V_7 ) ;
if ( V_8 != NULL && V_32 -> V_8 == NULL )
F_36 ( V_8 ) ;
if ( V_34 != NULL )
F_37 ( V_34 ) ;
return ( V_33 ) ;
}
int F_38 ( const T_1 * V_32 )
{
int V_33 = 0 ;
T_4 * V_34 = NULL ;
const T_5 * V_35 = NULL ;
T_6 * V_38 = NULL ;
if ( ! V_32 || ! V_32 -> V_6 || ! V_32 -> V_7 ) {
F_3 ( V_39 , V_23 ) ;
return 0 ;
}
if ( F_39 ( V_32 -> V_6 , V_32 -> V_7 ) ) {
F_3 ( V_39 , V_40 ) ;
goto V_37;
}
if ( ( V_34 = F_31 () ) == NULL )
goto V_37;
if ( ( V_38 = F_20 ( V_32 -> V_6 ) ) == NULL )
goto V_37;
if ( ! F_40 ( V_32 -> V_6 , V_32 -> V_7 , V_34 ) ) {
F_3 ( V_39 , V_41 ) ;
goto V_37;
}
V_35 = & V_32 -> V_6 -> V_35 ;
if ( F_34 ( V_35 ) ) {
F_3 ( V_39 , V_42 ) ;
goto V_37;
}
if ( ! F_35 ( V_32 -> V_6 , V_38 , NULL , V_32 -> V_7 , V_35 , V_34 ) ) {
F_3 ( V_39 , V_43 ) ;
goto V_37;
}
if ( ! F_39 ( V_32 -> V_6 , V_38 ) ) {
F_3 ( V_39 , V_44 ) ;
goto V_37;
}
if ( V_32 -> V_8 ) {
if ( F_41 ( V_32 -> V_8 , V_35 ) >= 0 ) {
F_3 ( V_39 , V_44 ) ;
goto V_37;
}
if ( ! F_35 ( V_32 -> V_6 , V_38 , V_32 -> V_8 ,
NULL , NULL , V_34 ) ) {
F_3 ( V_39 , V_43 ) ;
goto V_37;
}
if ( F_42 ( V_32 -> V_6 , V_38 , V_32 -> V_7 , V_34 ) != 0 ) {
F_3 ( V_39 , V_45 ) ;
goto V_37;
}
}
V_33 = 1 ;
V_37:
if ( V_34 != NULL )
F_37 ( V_34 ) ;
if ( V_38 != NULL )
F_11 ( V_38 ) ;
return ( V_33 ) ;
}
int F_43 ( T_1 * V_46 , T_5 * V_47 ,
T_5 * V_48 )
{
T_4 * V_34 = NULL ;
T_5 * V_49 , * V_50 ;
T_6 * V_38 = NULL ;
int V_33 = 0 , V_51 , V_52 = 0 ;
if ( ! V_46 || ! V_46 -> V_6 || ! V_47 || ! V_48 ) {
F_3 ( V_53 ,
V_23 ) ;
return 0 ;
}
V_34 = F_31 () ;
if ( ! V_34 )
goto V_37;
V_38 = F_20 ( V_46 -> V_6 ) ;
if ( ! V_38 )
goto V_37;
V_51 = F_44 ( F_17 ( V_46 -> V_6 ) ) ;
if ( V_51 == V_54 )
V_52 = 1 ;
V_49 = F_45 ( V_34 ) ;
V_50 = F_45 ( V_34 ) ;
#ifndef F_46
if ( V_52 ) {
if ( ! F_47 ( V_46 -> V_6 , V_38 ,
V_47 , V_48 , V_34 ) )
goto V_37;
if ( ! F_48 ( V_46 -> V_6 , V_38 ,
V_49 , V_50 , V_34 ) )
goto V_37;
} else
#endif
{
if ( ! F_49 ( V_46 -> V_6 , V_38 ,
V_47 , V_48 , V_34 ) )
goto V_37;
if ( ! F_50 ( V_46 -> V_6 , V_38 ,
V_49 , V_50 , V_34 ) )
goto V_37;
}
if ( F_41 ( V_47 , V_49 ) || F_41 ( V_48 , V_50 ) ) {
F_3 ( V_53 ,
V_55 ) ;
goto V_37;
}
if ( ! F_51 ( V_46 , V_38 ) )
goto V_37;
if ( F_38 ( V_46 ) == 0 )
goto V_37;
V_33 = 1 ;
V_37:
if ( V_34 )
F_37 ( V_34 ) ;
if ( V_38 )
F_11 ( V_38 ) ;
return V_33 ;
}
const T_7 * F_52 ( const T_1 * V_46 )
{
return V_46 -> V_6 ;
}
int F_53 ( T_1 * V_46 , const T_7 * V_6 )
{
if ( V_46 -> V_6 != NULL )
F_10 ( V_46 -> V_6 ) ;
V_46 -> V_6 = F_54 ( V_6 ) ;
return ( V_46 -> V_6 == NULL ) ? 0 : 1 ;
}
const T_5 * F_55 ( const T_1 * V_46 )
{
return V_46 -> V_8 ;
}
int F_56 ( T_1 * V_46 , const T_5 * V_8 )
{
if ( V_46 -> V_8 )
F_12 ( V_46 -> V_8 ) ;
V_46 -> V_8 = F_57 ( V_8 ) ;
return ( V_46 -> V_8 == NULL ) ? 0 : 1 ;
}
const T_6 * F_58 ( const T_1 * V_46 )
{
return V_46 -> V_7 ;
}
int F_51 ( T_1 * V_46 , const T_6 * V_7 )
{
if ( V_46 -> V_7 != NULL )
F_11 ( V_46 -> V_7 ) ;
V_46 -> V_7 = F_59 ( V_7 , V_46 -> V_6 ) ;
return ( V_46 -> V_7 == NULL ) ? 0 : 1 ;
}
unsigned int F_60 ( const T_1 * V_46 )
{
return V_46 -> V_9 ;
}
void F_61 ( T_1 * V_46 , unsigned int V_5 )
{
V_46 -> V_9 = V_5 ;
}
T_8 F_62 ( const T_1 * V_46 )
{
return V_46 -> V_10 ;
}
void F_63 ( T_1 * V_46 , T_8 V_56 )
{
V_46 -> V_10 = V_56 ;
if ( V_46 -> V_6 != NULL )
F_64 ( V_46 -> V_6 , V_56 ) ;
}
void * F_65 ( T_1 * V_46 ,
void * (* V_27) ( void * ) ,
void (* V_29) ( void * ) ,
void (* V_30) ( void * ) )
{
void * V_1 ;
F_66 ( V_17 ) ;
V_1 =
F_67 ( V_46 -> V_13 , V_27 , V_29 ,
V_30 ) ;
F_68 ( V_17 ) ;
return V_1 ;
}
void * F_69 ( T_1 * V_46 , void * V_28 ,
void * (* V_27) ( void * ) ,
void (* V_29) ( void * ) ,
void (* V_30) ( void * ) )
{
T_2 * V_57 ;
F_70 ( V_17 ) ;
V_57 =
F_67 ( V_46 -> V_13 , V_27 , V_29 ,
V_30 ) ;
if ( V_57 == NULL )
F_24 ( & V_46 -> V_13 , V_28 , V_27 , V_29 ,
V_30 ) ;
F_71 ( V_17 ) ;
return V_57 ;
}
void F_72 ( T_1 * V_46 , int V_58 )
{
if ( V_46 -> V_6 != NULL )
F_73 ( V_46 -> V_6 , V_58 ) ;
}
int F_74 ( T_1 * V_46 , T_4 * V_34 )
{
if ( V_46 -> V_6 == NULL )
return 0 ;
return F_75 ( V_46 -> V_6 , V_34 ) ;
}
int F_76 ( const T_1 * V_46 )
{
return V_46 -> V_5 ;
}
void F_77 ( T_1 * V_46 , int V_5 )
{
V_46 -> V_5 |= V_5 ;
}
void F_78 ( T_1 * V_46 , int V_5 )
{
V_46 -> V_5 &= ~ V_5 ;
}
