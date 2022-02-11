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
F_4 ( V_19 , V_5 , & V_5 -> V_20 ) ;
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
F_9 ( V_19 , V_22 , & V_22 -> V_20 ) ;
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
long F_18 ( T_1 * V_28 , int V_48 , void (* F_19)() )
{
long V_2 ;
long (* F_11)();
if ( V_28 == NULL ) return ( 0 ) ;
if ( ( V_28 -> V_1 == NULL ) || ( V_28 -> V_1 -> V_56 == NULL ) )
{
F_2 ( V_54 , V_33 ) ;
return ( - 2 ) ;
}
F_11 = V_28 -> V_6 ;
if ( ( F_11 != NULL ) &&
( ( V_2 = F_11 ( V_28 , V_55 , ( void * ) & F_19 , V_48 , 0 , 1L ) ) <= 0 ) )
return ( V_2 ) ;
V_2 = V_28 -> V_1 -> V_56 ( V_28 , V_48 , F_19 ) ;
if ( F_11 != NULL )
V_2 = F_11 ( V_28 , V_55 | V_36 , ( void * ) & F_19 , V_48 ,
0 , V_2 ) ;
return ( V_2 ) ;
}
T_3 F_20 ( T_1 * V_5 )
{
return F_16 ( V_5 , V_57 , 0 , NULL ) ;
}
T_3 F_21 ( T_1 * V_5 )
{
return F_16 ( V_5 , V_58 , 0 , NULL ) ;
}
T_1 * F_22 ( T_1 * V_28 , T_1 * V_5 )
{
T_1 * V_59 ;
if ( V_28 == NULL ) return ( V_5 ) ;
V_59 = V_28 ;
while ( V_59 -> V_15 != NULL )
V_59 = V_59 -> V_15 ;
V_59 -> V_15 = V_5 ;
if ( V_5 != NULL )
V_5 -> V_14 = V_59 ;
F_16 ( V_28 , V_60 , 0 , NULL ) ;
return ( V_28 ) ;
}
T_1 * F_23 ( T_1 * V_28 )
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
F_16 ( V_28 , V_61 , 0 , NULL ) ;
return ( V_2 ) ;
}
T_1 * F_24 ( T_1 * V_5 , int * V_62 )
{
T_1 * V_28 , * V_63 ;
V_28 = V_63 = V_5 ;
for (; ; )
{
if ( ! F_25 ( V_28 ) ) break;
V_63 = V_28 ;
V_28 = V_28 -> V_15 ;
if ( V_28 == NULL ) break;
}
if ( V_62 != NULL ) * V_62 = V_63 -> V_11 ;
return ( V_63 ) ;
}
int F_26 ( T_1 * V_5 )
{
return ( V_5 -> V_11 ) ;
}
T_1 * F_27 ( T_1 * V_5 , int type )
{
int V_64 , V_65 ;
V_65 = type & 0xff ;
do {
if ( V_5 -> V_1 != NULL )
{
V_64 = V_5 -> V_1 -> type ;
if ( ! V_65 )
{
if ( V_64 & type ) return ( V_5 ) ;
}
else if ( V_64 == type )
return ( V_5 ) ;
}
V_5 = V_5 -> V_15 ;
} while ( V_5 != NULL );
return ( NULL ) ;
}
void F_28 ( T_1 * V_5 )
{
T_1 * V_28 ;
int V_66 ;
while ( V_5 != NULL )
{
V_28 = V_5 ;
V_66 = V_28 -> V_16 ;
V_5 = V_5 -> V_15 ;
F_5 ( V_28 ) ;
if ( V_66 > 1 ) break;
}
}
T_1 * F_29 ( T_1 * V_37 )
{
T_1 * V_2 = NULL , * V_67 = NULL , * V_5 , * V_68 ;
for ( V_5 = V_37 ; V_5 != NULL ; V_5 = V_5 -> V_15 )
{
if ( ( V_68 = F_1 ( V_5 -> V_1 ) ) == NULL ) goto V_69;
V_68 -> V_6 = V_5 -> V_6 ;
V_68 -> V_7 = V_5 -> V_7 ;
V_68 -> V_8 = V_5 -> V_8 ;
V_68 -> V_9 = V_5 -> V_9 ;
V_68 -> V_10 = V_5 -> V_10 ;
V_68 -> V_12 = V_5 -> V_12 ;
if ( ! F_30 ( V_5 , ( char * ) V_68 ) )
{
F_5 ( V_68 ) ;
goto V_69;
}
if ( ! F_31 ( V_19 , & V_68 -> V_20 , & V_5 -> V_20 ) )
goto V_69;
if ( V_2 == NULL )
{
V_67 = V_68 ;
V_2 = V_67 ;
}
else
{
F_22 ( V_67 , V_68 ) ;
V_67 = V_68 ;
}
}
return ( V_2 ) ;
V_69:
if ( V_2 != NULL )
F_5 ( V_2 ) ;
return ( NULL ) ;
}
void F_32 ( T_1 * V_28 )
{
F_33 ( V_28 , F_34 ( V_28 -> V_15 ) ) ;
V_28 -> V_11 = V_28 -> V_15 -> V_11 ;
}
int F_35 ( long V_70 , void * V_71 , T_4 * V_72 ,
T_5 * V_73 , T_6 * V_74 )
{
V_75 ++ ;
return ( F_36 ( V_75 - 1 , & V_19 ,
V_70 , V_71 , V_72 , V_73 , V_74 ) ) ;
}
int F_37 ( T_1 * V_5 , int V_76 , void * V_77 )
{
return ( F_38 ( & ( V_5 -> V_20 ) , V_76 , V_77 ) ) ;
}
void * F_39 ( T_1 * V_5 , int V_76 )
{
return ( F_40 ( & ( V_5 -> V_20 ) , V_76 ) ) ;
}
unsigned long F_41 ( T_1 * V_5 )
{
if( V_5 ) return V_5 -> V_17 ;
return 0 ;
}
unsigned long F_42 ( T_1 * V_5 )
{
if( V_5 ) return V_5 -> V_18 ;
return 0 ;
}
