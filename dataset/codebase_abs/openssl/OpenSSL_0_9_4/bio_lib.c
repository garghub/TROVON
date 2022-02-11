T_1 * F_1 ( T_2 * V_1 )
{
T_1 * V_2 = NULL ;
V_2 = ( T_1 * ) Malloc ( sizeof( T_1 ) ) ;
if ( V_2 == NULL )
{
F_2 ( V_3 , V_4 ) ;
return ( NULL ) ;
}
if ( ! F_3 ( V_2 , V_1 ) )
{
Free ( V_2 ) ;
V_2 = NULL ;
}
return ( V_2 ) ;
}
int F_3 ( T_1 * V_5 , T_2 * V_1 )
{
V_5 -> V_1 = V_1 ;
V_5 -> V_6 = NULL ;
V_5 -> V_7 = NULL ;
V_5 -> V_8 = 0 ;
V_5 -> V_9 = 1 ;
V_5 -> V_10 = 0 ;
V_5 -> V_11 = 0 ;
V_5 -> V_12 = 0 ;
V_5 -> V_13 = NULL ;
V_5 -> V_14 = NULL ;
V_5 -> V_15 = NULL ;
V_5 -> V_16 = 1 ;
V_5 -> V_17 = 0L ;
V_5 -> V_18 = 0L ;
F_4 ( V_19 , ( char * ) V_5 , & V_5 -> V_20 ) ;
if ( V_1 -> V_21 != NULL )
if ( ! V_1 -> V_21 ( V_5 ) )
return ( 0 ) ;
return ( 1 ) ;
}
int F_5 ( T_1 * V_22 )
{
int V_2 = 0 , V_23 ;
if ( V_22 == NULL ) return ( 0 ) ;
V_23 = F_6 ( & V_22 -> V_16 , - 1 , V_24 ) ;
#ifdef F_7
F_7 ( L_1 , V_22 ) ;
#endif
if ( V_23 > 0 ) return ( 1 ) ;
#ifdef F_8
if ( V_23 < 0 )
{
fprintf ( V_25 , L_2 ) ;
abort () ;
}
#endif
if ( ( V_22 -> V_6 != NULL ) &&
( ( V_23 = ( int ) V_22 -> V_6 ( V_22 , V_26 , NULL , 0 , 0L , 1L ) ) <= 0 ) )
return ( V_23 ) ;
F_9 ( V_19 , ( char * ) V_22 , & V_22 -> V_20 ) ;
if ( ( V_22 -> V_1 == NULL ) || ( V_22 -> V_1 -> V_27 == NULL ) ) return ( 1 ) ;
V_2 = V_22 -> V_1 -> V_27 ( V_22 ) ;
Free ( V_22 ) ;
return ( 1 ) ;
}
int F_10 ( T_1 * V_28 , void * V_29 , int V_30 )
{
int V_23 ;
long (* F_11)();
if ( ( V_28 == NULL ) || ( V_28 -> V_1 == NULL ) || ( V_28 -> V_1 -> V_31 == NULL ) )
{
F_2 ( V_32 , V_33 ) ;
return ( - 2 ) ;
}
F_11 = V_28 -> V_6 ;
if ( ( F_11 != NULL ) &&
( ( V_23 = ( int ) F_11 ( V_28 , V_34 , V_29 , V_30 , 0L , 1L ) ) <= 0 ) )
return ( V_23 ) ;
if ( ! V_28 -> V_8 )
{
F_2 ( V_32 , V_35 ) ;
return ( - 2 ) ;
}
V_23 = V_28 -> V_1 -> V_31 ( V_28 , V_29 , V_30 ) ;
if ( V_23 > 0 ) V_28 -> V_17 += ( unsigned long ) V_23 ;
if ( F_11 != NULL )
V_23 = ( int ) F_11 ( V_28 , V_34 | V_36 , V_29 , V_30 ,
0L , ( long ) V_23 ) ;
return ( V_23 ) ;
}
int F_12 ( T_1 * V_28 , const char * V_37 , int V_38 )
{
int V_23 ;
long (* F_11)();
if ( V_28 == NULL )
return ( 0 ) ;
F_11 = V_28 -> V_6 ;
if ( ( V_28 -> V_1 == NULL ) || ( V_28 -> V_1 -> V_39 == NULL ) )
{
F_2 ( V_40 , V_33 ) ;
return ( - 2 ) ;
}
if ( ( F_11 != NULL ) &&
( ( V_23 = ( int ) F_11 ( V_28 , V_41 , V_37 , V_38 , 0L , 1L ) ) <= 0 ) )
return ( V_23 ) ;
if ( ! V_28 -> V_8 )
{
F_2 ( V_40 , V_35 ) ;
return ( - 2 ) ;
}
V_23 = V_28 -> V_1 -> V_39 ( V_28 , V_37 , V_38 ) ;
if ( V_23 > 0 ) V_28 -> V_18 += ( unsigned long ) V_23 ;
if ( V_28 -> V_16 <= 0 ) abort () ;
if ( F_11 != NULL )
V_23 = ( int ) F_11 ( V_28 , V_41 | V_36 , V_37 , V_38 ,
0L , ( long ) V_23 ) ;
return ( V_23 ) ;
}
int F_13 ( T_1 * V_28 , const char * V_37 )
{
int V_23 ;
long (* F_11)();
if ( ( V_28 == NULL ) || ( V_28 -> V_1 == NULL ) || ( V_28 -> V_1 -> V_42 == NULL ) )
{
F_2 ( V_43 , V_33 ) ;
return ( - 2 ) ;
}
F_11 = V_28 -> V_6 ;
if ( ( F_11 != NULL ) &&
( ( V_23 = ( int ) F_11 ( V_28 , V_44 , V_37 , 0 , 0L , 1L ) ) <= 0 ) )
return ( V_23 ) ;
if ( ! V_28 -> V_8 )
{
F_2 ( V_43 , V_35 ) ;
return ( - 2 ) ;
}
V_23 = V_28 -> V_1 -> V_42 ( V_28 , V_37 ) ;
if ( F_11 != NULL )
V_23 = ( int ) F_11 ( V_28 , V_44 | V_36 , V_37 , 0 ,
0L , ( long ) V_23 ) ;
return ( V_23 ) ;
}
int F_14 ( T_1 * V_28 , char * V_37 , int V_38 )
{
int V_23 ;
long (* F_11)();
if ( ( V_28 == NULL ) || ( V_28 -> V_1 == NULL ) || ( V_28 -> V_1 -> V_45 == NULL ) )
{
F_2 ( V_46 , V_33 ) ;
return ( - 2 ) ;
}
F_11 = V_28 -> V_6 ;
if ( ( F_11 != NULL ) &&
( ( V_23 = ( int ) F_11 ( V_28 , V_47 , V_37 , V_38 , 0L , 1L ) ) <= 0 ) )
return ( V_23 ) ;
if ( ! V_28 -> V_8 )
{
F_2 ( V_46 , V_35 ) ;
return ( - 2 ) ;
}
V_23 = V_28 -> V_1 -> V_45 ( V_28 , V_37 , V_38 ) ;
if ( F_11 != NULL )
V_23 = ( int ) F_11 ( V_28 , V_47 | V_36 , V_37 , V_38 ,
0L , ( long ) V_23 ) ;
return ( V_23 ) ;
}
long F_15 ( T_1 * V_28 , int V_48 , long V_49 , int V_50 )
{
int V_23 ;
V_23 = V_50 ;
return ( F_16 ( V_28 , V_48 , V_49 , ( char * ) & V_23 ) ) ;
}
char * F_17 ( T_1 * V_28 , int V_48 , long V_49 )
{
char * V_51 = NULL ;
if ( F_16 ( V_28 , V_48 , V_49 , ( char * ) & V_51 ) <= 0 )
return ( NULL ) ;
else
return ( V_51 ) ;
}
long F_16 ( T_1 * V_28 , int V_48 , long V_49 , void * V_52 )
{
long V_2 ;
long (* F_11)();
if ( V_28 == NULL ) return ( 0 ) ;
if ( ( V_28 -> V_1 == NULL ) || ( V_28 -> V_1 -> V_53 == NULL ) )
{
F_2 ( V_54 , V_33 ) ;
return ( - 2 ) ;
}
F_11 = V_28 -> V_6 ;
if ( ( F_11 != NULL ) &&
( ( V_2 = F_11 ( V_28 , V_55 , V_52 , V_48 , V_49 , 1L ) ) <= 0 ) )
return ( V_2 ) ;
V_2 = V_28 -> V_1 -> V_53 ( V_28 , V_48 , V_49 , V_52 ) ;
if ( F_11 != NULL )
V_2 = F_11 ( V_28 , V_55 | V_36 , V_52 , V_48 ,
V_49 , V_2 ) ;
return ( V_2 ) ;
}
T_3 F_18 ( T_1 * V_5 )
{
return F_16 ( V_5 , V_56 , 0 , NULL ) ;
}
T_3 F_19 ( T_1 * V_5 )
{
return F_16 ( V_5 , V_57 , 0 , NULL ) ;
}
T_1 * F_20 ( T_1 * V_28 , T_1 * V_5 )
{
T_1 * V_58 ;
if ( V_28 == NULL ) return ( V_5 ) ;
V_58 = V_28 ;
while ( V_58 -> V_15 != NULL )
V_58 = V_58 -> V_15 ;
V_58 -> V_15 = V_5 ;
if ( V_5 != NULL )
V_5 -> V_14 = V_58 ;
F_16 ( V_28 , V_59 , 0 , NULL ) ;
return ( V_28 ) ;
}
T_1 * F_21 ( T_1 * V_28 )
{
T_1 * V_2 ;
if ( V_28 == NULL ) return ( NULL ) ;
V_2 = V_28 -> V_15 ;
if ( V_28 -> V_14 != NULL )
V_28 -> V_14 -> V_15 = V_28 -> V_15 ;
if ( V_28 -> V_15 != NULL )
V_28 -> V_15 -> V_14 = V_28 -> V_14 ;
V_28 -> V_15 = NULL ;
V_28 -> V_14 = NULL ;
F_16 ( V_28 , V_60 , 0 , NULL ) ;
return ( V_2 ) ;
}
T_1 * F_22 ( T_1 * V_5 , int * V_61 )
{
T_1 * V_28 , * V_62 ;
V_28 = V_62 = V_5 ;
for (; ; )
{
if ( ! F_23 ( V_28 ) ) break;
V_62 = V_28 ;
V_28 = V_28 -> V_15 ;
if ( V_28 == NULL ) break;
}
if ( V_61 != NULL ) * V_61 = V_62 -> V_11 ;
return ( V_62 ) ;
}
int F_24 ( T_1 * V_5 )
{
return ( V_5 -> V_11 ) ;
}
T_1 * F_25 ( T_1 * V_5 , int type )
{
int V_63 , V_64 ;
V_64 = type & 0xff ;
do {
if ( V_5 -> V_1 != NULL )
{
V_63 = V_5 -> V_1 -> type ;
if ( ! V_64 )
{
if ( V_63 & type ) return ( V_5 ) ;
}
else if ( V_63 == type )
return ( V_5 ) ;
}
V_5 = V_5 -> V_15 ;
} while ( V_5 != NULL );
return ( NULL ) ;
}
void F_26 ( T_1 * V_5 )
{
T_1 * V_28 ;
int V_65 ;
while ( V_5 != NULL )
{
V_28 = V_5 ;
V_65 = V_28 -> V_16 ;
V_5 = V_5 -> V_15 ;
F_5 ( V_28 ) ;
if ( V_65 > 1 ) break;
}
}
T_1 * F_27 ( T_1 * V_37 )
{
T_1 * V_2 = NULL , * V_66 = NULL , * V_5 , * V_67 ;
for ( V_5 = V_37 ; V_5 != NULL ; V_5 = V_5 -> V_15 )
{
if ( ( V_67 = F_1 ( V_5 -> V_1 ) ) == NULL ) goto V_68;
V_67 -> V_6 = V_5 -> V_6 ;
V_67 -> V_7 = V_5 -> V_7 ;
V_67 -> V_8 = V_5 -> V_8 ;
V_67 -> V_9 = V_5 -> V_9 ;
V_67 -> V_10 = V_5 -> V_10 ;
V_67 -> V_12 = V_5 -> V_12 ;
if ( ! F_28 ( V_5 , ( char * ) V_67 ) )
{
F_5 ( V_67 ) ;
goto V_68;
}
if ( ! F_29 ( V_19 , & V_67 -> V_20 , & V_5 -> V_20 ) )
goto V_68;
if ( V_2 == NULL )
{
V_66 = V_67 ;
V_2 = V_66 ;
}
else
{
F_20 ( V_66 , V_67 ) ;
V_66 = V_67 ;
}
}
return ( V_2 ) ;
V_68:
if ( V_2 != NULL )
F_5 ( V_2 ) ;
return ( NULL ) ;
}
void F_30 ( T_1 * V_28 )
{
F_31 ( V_28 , F_32 ( V_28 -> V_15 ) ) ;
V_28 -> V_11 = V_28 -> V_15 -> V_11 ;
}
int F_33 ( long V_69 , char * V_70 , int (* F_34)() ,
int (* F_35)() , void (* F_36)() )
{
V_71 ++ ;
return ( F_37 ( V_71 - 1 , & V_19 ,
V_69 , V_70 , F_34 , F_35 , F_36 ) ) ;
}
int F_38 ( T_1 * V_5 , int V_72 , char * V_73 )
{
return ( F_39 ( & ( V_5 -> V_20 ) , V_72 , V_73 ) ) ;
}
char * F_40 ( T_1 * V_5 , int V_72 )
{
return ( F_41 ( & ( V_5 -> V_20 ) , V_72 ) ) ;
}
