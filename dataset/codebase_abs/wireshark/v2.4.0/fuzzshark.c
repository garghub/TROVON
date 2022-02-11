static void
F_1 ( const char * V_1 , T_1 V_2 )
{
fprintf ( V_3 , L_1 ) ;
vfprintf ( V_3 , V_1 , V_2 ) ;
fprintf ( V_3 , L_2 ) ;
}
static void
F_2 ( const char * V_4 , int V_5 , T_2 V_6 )
{
fprintf ( V_3 , L_1 ) ;
fprintf ( V_3 , F_3 ( V_5 , V_6 ) , V_4 ) ;
fprintf ( V_3 , L_2 ) ;
}
static void
F_4 ( const char * V_4 , int V_5 )
{
F_5 ( L_3 , V_4 , F_6 ( V_5 ) ) ;
}
static void
F_7 ( const char * V_4 , int V_5 )
{
F_5 ( L_4 , V_4 , F_6 ( V_5 ) ) ;
}
static void
F_8 ( const char * V_1 , T_1 V_2 )
{
vfprintf ( V_3 , V_1 , V_2 ) ;
fprintf ( V_3 , L_2 ) ;
}
static const T_3 *
F_9 ( void * T_4 V_7 , T_5 T_6 V_7 )
{
static T_3 V_8 ;
return & V_8 ;
}
static T_7 *
F_10 ( void )
{
T_7 * V_9 = F_11 () ;
V_9 -> V_10 = F_9 ;
V_9 -> V_11 = NULL ;
V_9 -> V_12 = NULL ;
V_9 -> V_13 = NULL ;
return V_9 ;
}
static int
F_12 ( int T_8 V_7 , char * * V_14 )
{
T_9 * V_15 ;
T_9 * V_16 ;
char * V_17 ;
char * V_18 = NULL ;
T_10 * V_19 ;
int V_20 = V_21 ;
#if F_13 ( V_22 )
T_11 V_23 = NULL ;
#endif
F_14 ( F_1 , F_8 ) ;
F_15 () ;
#if 0
relinquish_special_privs_perm();
#endif
V_17 = F_16 ( V_14 [ 0 ] , F_12 ) ;
if ( V_17 != NULL )
fprintf ( V_3 , L_5 , V_17 ) ;
V_15 = F_17 ( NULL , V_24 ) ;
V_16 = F_18 ( V_25 ) ;
F_19 ( L_6
L_2
L_7
L_2
L_7 ,
F_20 () ,
V_15 -> V_26 ,
V_16 -> V_26 ) ;
F_21 ( V_15 , TRUE ) ;
F_21 ( V_16 , TRUE ) ;
F_22 ( F_1 , F_1 ,
F_2 , F_4 , F_7 ) ;
F_23 ( V_27 ) ;
F_24 ( V_28 ) ;
F_25 ( V_29 ) ;
F_26 () ;
#ifdef F_27
F_28 () ;
F_29 ( V_30 ) ;
F_30 () ;
#endif
if ( ! F_31 ( V_31 , V_32 , NULL , NULL ) )
{
V_20 = V_33 ;
goto V_34;
}
V_19 = F_32 () ;
if ( ! F_33 ( & V_18 , NULL ) )
{
fprintf ( V_3 , L_8 , V_18 ) ;
F_34 ( V_18 ) ;
}
F_35 () ;
F_36 ( & V_35 , V_19 -> V_36 , TRUE ) ;
#if F_13 ( V_37 ) && F_13 ( V_22 )
# define F_37 1
fprintf ( V_3 , L_9 , V_22 , V_37 ) ;
{
T_12 * V_38 = F_38 ( F_39 ( V_37 ) ) ;
while ( V_38 )
{
T_11 V_39 = ( T_11 ) V_38 -> T_4 ;
const char * V_40 = F_40 ( F_41 ( V_39 ) ) ;
if ( ! strcmp ( V_40 , V_22 ) )
V_23 = V_39 ;
V_38 = V_38 -> V_41 ;
}
}
#elif F_13 ( V_22 )
# define F_37 2
fprintf ( V_3 , L_10 , V_22 ) ;
V_23 = F_42 ( V_22 ) ;
#endif
#ifdef F_37
F_43 ( V_23 != NULL ) ;
F_44 ( V_23 ) ;
#endif
V_42 = F_10 () ;
V_43 = F_45 ( V_42 , TRUE , FALSE ) ;
return 0 ;
V_34:
F_46 () ;
F_47 () ;
#ifdef F_27
F_48 () ;
#endif
return V_20 ;
}
int
F_49 ( T_13 * V_44 , T_14 V_45 )
{
static T_5 V_46 = 0 ;
T_15 * V_47 = V_43 ;
T_5 V_48 = ( T_5 ) V_45 ;
struct V_49 V_50 ;
T_16 V_51 ;
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
V_50 . V_52 = V_53 ;
V_50 . V_54 = V_48 ;
V_50 . V_48 = V_48 ;
V_50 . V_55 = V_56 ;
V_50 . V_57 = V_58 | V_59 ;
F_50 ( & V_51 , ++ V_46 , & V_50 , 0 , 0 ) ;
F_51 ( V_47 , V_60 , & V_50 , F_52 ( V_44 , V_48 , V_48 ) , & V_51 , NULL ) ;
F_53 ( & V_51 ) ;
F_54 ( V_47 ) ;
return 0 ;
}
int
F_55 ( int * T_8 , char * * * V_14 )
{
int V_20 ;
V_20 = F_12 ( * T_8 , * V_14 ) ;
if ( V_20 != 0 )
exit ( V_20 ) ;
return 0 ;
}
