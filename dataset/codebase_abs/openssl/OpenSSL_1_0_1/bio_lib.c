T_1 * F_1 ( T_2 * V_1 )
{
T_1 * V_2 = NULL ;
V_2 = ( T_1 * ) F_2 ( sizeof( T_1 ) ) ;
if ( V_2 == NULL )
{
F_3 ( V_3 , V_4 ) ;
return ( NULL ) ;
}
if ( ! F_4 ( V_2 , V_1 ) )
{
F_5 ( V_2 ) ;
V_2 = NULL ;
}
return ( V_2 ) ;
}
int F_4 ( T_1 * V_5 , T_2 * V_1 )
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
F_6 ( V_19 , V_5 , & V_5 -> V_20 ) ;
if ( V_1 -> V_21 != NULL )
if ( ! V_1 -> V_21 ( V_5 ) )
{
F_7 ( V_19 , V_5 ,
& V_5 -> V_20 ) ;
return ( 0 ) ;
}
return ( 1 ) ;
}
int F_8 ( T_1 * V_22 )
{
int V_23 ;
if ( V_22 == NULL ) return ( 0 ) ;
V_23 = F_9 ( & V_22 -> V_16 , - 1 , V_24 ) ;
#ifdef F_10
F_10 ( L_1 , V_22 ) ;
#endif
if ( V_23 > 0 ) return ( 1 ) ;
#ifdef F_11
if ( V_23 < 0 )
{
fprintf ( V_25 , L_2 ) ;
abort () ;
}
#endif
if ( ( V_22 -> V_6 != NULL ) &&
( ( V_23 = ( int ) V_22 -> V_6 ( V_22 , V_26 , NULL , 0 , 0L , 1L ) ) <= 0 ) )
return ( V_23 ) ;
F_7 ( V_19 , V_22 , & V_22 -> V_20 ) ;
if ( ( V_22 -> V_1 == NULL ) || ( V_22 -> V_1 -> V_27 == NULL ) ) return ( 1 ) ;
V_22 -> V_1 -> V_27 ( V_22 ) ;
F_5 ( V_22 ) ;
return ( 1 ) ;
}
void F_12 ( T_1 * V_22 )
{ F_8 ( V_22 ) ; }
void F_13 ( T_1 * V_28 , int V_10 )
{
V_28 -> V_10 &= ~ V_10 ;
}
int F_14 ( const T_1 * V_28 , int V_10 )
{
return ( V_28 -> V_10 & V_10 ) ;
}
void F_15 ( T_1 * V_28 , int V_10 )
{
V_28 -> V_10 |= V_10 ;
}
void F_16 ( T_1 * V_28 , long (* F_17)( struct V_29 * , int , const char * , int , long , long ) )
{
V_28 -> V_6 = F_17 ;
}
void F_18 ( T_1 * V_28 , char * V_30 )
{
V_28 -> V_7 = V_30 ;
}
char * F_19 ( const T_1 * V_28 )
{
return V_28 -> V_7 ;
}
const char * F_20 ( const T_1 * V_28 )
{
return V_28 -> V_1 -> V_31 ;
}
int F_21 ( const T_1 * V_28 )
{
return V_28 -> V_1 -> type ;
}
int F_22 ( T_1 * V_28 , void * V_32 , int V_33 )
{
int V_23 ;
long (* F_17)( T_1 * , int , const char * , int , long , long );
if ( ( V_28 == NULL ) || ( V_28 -> V_1 == NULL ) || ( V_28 -> V_1 -> V_34 == NULL ) )
{
F_3 ( V_35 , V_36 ) ;
return ( - 2 ) ;
}
F_17 = V_28 -> V_6 ;
if ( ( F_17 != NULL ) &&
( ( V_23 = ( int ) F_17 ( V_28 , V_37 , V_32 , V_33 , 0L , 1L ) ) <= 0 ) )
return ( V_23 ) ;
if ( ! V_28 -> V_8 )
{
F_3 ( V_35 , V_38 ) ;
return ( - 2 ) ;
}
V_23 = V_28 -> V_1 -> V_34 ( V_28 , V_32 , V_33 ) ;
if ( V_23 > 0 ) V_28 -> V_17 += ( unsigned long ) V_23 ;
if ( F_17 != NULL )
V_23 = ( int ) F_17 ( V_28 , V_37 | V_39 , V_32 , V_33 ,
0L , ( long ) V_23 ) ;
return ( V_23 ) ;
}
int F_23 ( T_1 * V_28 , const void * V_40 , int V_41 )
{
int V_23 ;
long (* F_17)( T_1 * , int , const char * , int , long , long );
if ( V_28 == NULL )
return ( 0 ) ;
F_17 = V_28 -> V_6 ;
if ( ( V_28 -> V_1 == NULL ) || ( V_28 -> V_1 -> V_42 == NULL ) )
{
F_3 ( V_43 , V_36 ) ;
return ( - 2 ) ;
}
if ( ( F_17 != NULL ) &&
( ( V_23 = ( int ) F_17 ( V_28 , V_44 , V_40 , V_41 , 0L , 1L ) ) <= 0 ) )
return ( V_23 ) ;
if ( ! V_28 -> V_8 )
{
F_3 ( V_43 , V_38 ) ;
return ( - 2 ) ;
}
V_23 = V_28 -> V_1 -> V_42 ( V_28 , V_40 , V_41 ) ;
if ( V_23 > 0 ) V_28 -> V_18 += ( unsigned long ) V_23 ;
if ( F_17 != NULL )
V_23 = ( int ) F_17 ( V_28 , V_44 | V_39 , V_40 , V_41 ,
0L , ( long ) V_23 ) ;
return ( V_23 ) ;
}
int F_24 ( T_1 * V_28 , const char * V_40 )
{
int V_23 ;
long (* F_17)( T_1 * , int , const char * , int , long , long );
if ( ( V_28 == NULL ) || ( V_28 -> V_1 == NULL ) || ( V_28 -> V_1 -> V_45 == NULL ) )
{
F_3 ( V_46 , V_36 ) ;
return ( - 2 ) ;
}
F_17 = V_28 -> V_6 ;
if ( ( F_17 != NULL ) &&
( ( V_23 = ( int ) F_17 ( V_28 , V_47 , V_40 , 0 , 0L , 1L ) ) <= 0 ) )
return ( V_23 ) ;
if ( ! V_28 -> V_8 )
{
F_3 ( V_46 , V_38 ) ;
return ( - 2 ) ;
}
V_23 = V_28 -> V_1 -> V_45 ( V_28 , V_40 ) ;
if ( V_23 > 0 ) V_28 -> V_18 += ( unsigned long ) V_23 ;
if ( F_17 != NULL )
V_23 = ( int ) F_17 ( V_28 , V_47 | V_39 , V_40 , 0 ,
0L , ( long ) V_23 ) ;
return ( V_23 ) ;
}
int F_25 ( T_1 * V_28 , char * V_40 , int V_41 )
{
int V_23 ;
long (* F_17)( T_1 * , int , const char * , int , long , long );
if ( ( V_28 == NULL ) || ( V_28 -> V_1 == NULL ) || ( V_28 -> V_1 -> V_48 == NULL ) )
{
F_3 ( V_49 , V_36 ) ;
return ( - 2 ) ;
}
F_17 = V_28 -> V_6 ;
if ( ( F_17 != NULL ) &&
( ( V_23 = ( int ) F_17 ( V_28 , V_50 , V_40 , V_41 , 0L , 1L ) ) <= 0 ) )
return ( V_23 ) ;
if ( ! V_28 -> V_8 )
{
F_3 ( V_49 , V_38 ) ;
return ( - 2 ) ;
}
V_23 = V_28 -> V_1 -> V_48 ( V_28 , V_40 , V_41 ) ;
if ( F_17 != NULL )
V_23 = ( int ) F_17 ( V_28 , V_50 | V_39 , V_40 , V_41 ,
0L , ( long ) V_23 ) ;
return ( V_23 ) ;
}
int F_26 ( T_1 * V_28 , int V_51 , int V_52 )
{
if( V_51 < 0 )
V_51 = 0 ;
if( V_51 > V_52 )
V_51 = V_52 ;
while( V_51 -- )
if( F_24 ( V_28 , L_3 ) != 1 )
return 0 ;
return 1 ;
}
long F_27 ( T_1 * V_28 , int V_53 , long V_54 , int V_55 )
{
int V_23 ;
V_23 = V_55 ;
return ( F_28 ( V_28 , V_53 , V_54 , ( char * ) & V_23 ) ) ;
}
char * F_29 ( T_1 * V_28 , int V_53 , long V_54 )
{
char * V_56 = NULL ;
if ( F_28 ( V_28 , V_53 , V_54 , ( char * ) & V_56 ) <= 0 )
return ( NULL ) ;
else
return ( V_56 ) ;
}
long F_28 ( T_1 * V_28 , int V_53 , long V_54 , void * V_57 )
{
long V_2 ;
long (* F_17)( T_1 * , int , const char * , int , long , long );
if ( V_28 == NULL ) return ( 0 ) ;
if ( ( V_28 -> V_1 == NULL ) || ( V_28 -> V_1 -> V_58 == NULL ) )
{
F_3 ( V_59 , V_36 ) ;
return ( - 2 ) ;
}
F_17 = V_28 -> V_6 ;
if ( ( F_17 != NULL ) &&
( ( V_2 = F_17 ( V_28 , V_60 , V_57 , V_53 , V_54 , 1L ) ) <= 0 ) )
return ( V_2 ) ;
V_2 = V_28 -> V_1 -> V_58 ( V_28 , V_53 , V_54 , V_57 ) ;
if ( F_17 != NULL )
V_2 = F_17 ( V_28 , V_60 | V_39 , V_57 , V_53 ,
V_54 , V_2 ) ;
return ( V_2 ) ;
}
long F_30 ( T_1 * V_28 , int V_53 , void (* F_31)( struct V_29 * , int , const char * , int , long , long ) )
{
long V_2 ;
long (* F_17)( T_1 * , int , const char * , int , long , long );
if ( V_28 == NULL ) return ( 0 ) ;
if ( ( V_28 -> V_1 == NULL ) || ( V_28 -> V_1 -> V_61 == NULL ) )
{
F_3 ( V_62 , V_36 ) ;
return ( - 2 ) ;
}
F_17 = V_28 -> V_6 ;
if ( ( F_17 != NULL ) &&
( ( V_2 = F_17 ( V_28 , V_60 , ( void * ) & F_31 , V_53 , 0 , 1L ) ) <= 0 ) )
return ( V_2 ) ;
V_2 = V_28 -> V_1 -> V_61 ( V_28 , V_53 , F_31 ) ;
if ( F_17 != NULL )
V_2 = F_17 ( V_28 , V_60 | V_39 , ( void * ) & F_31 , V_53 ,
0 , V_2 ) ;
return ( V_2 ) ;
}
T_3 F_32 ( T_1 * V_5 )
{
return F_28 ( V_5 , V_63 , 0 , NULL ) ;
}
T_3 F_33 ( T_1 * V_5 )
{
return F_28 ( V_5 , V_64 , 0 , NULL ) ;
}
T_1 * F_34 ( T_1 * V_28 , T_1 * V_5 )
{
T_1 * V_65 ;
if ( V_28 == NULL ) return ( V_5 ) ;
V_65 = V_28 ;
while ( V_65 -> V_15 != NULL )
V_65 = V_65 -> V_15 ;
V_65 -> V_15 = V_5 ;
if ( V_5 != NULL )
V_5 -> V_14 = V_65 ;
F_28 ( V_28 , V_66 , 0 , V_65 ) ;
return ( V_28 ) ;
}
T_1 * F_35 ( T_1 * V_28 )
{
T_1 * V_2 ;
if ( V_28 == NULL ) return ( NULL ) ;
V_2 = V_28 -> V_15 ;
F_28 ( V_28 , V_67 , 0 , V_28 ) ;
if ( V_28 -> V_14 != NULL )
V_28 -> V_14 -> V_15 = V_28 -> V_15 ;
if ( V_28 -> V_15 != NULL )
V_28 -> V_15 -> V_14 = V_28 -> V_14 ;
V_28 -> V_15 = NULL ;
V_28 -> V_14 = NULL ;
return ( V_2 ) ;
}
T_1 * F_36 ( T_1 * V_5 , int * V_68 )
{
T_1 * V_28 , * V_69 ;
V_28 = V_69 = V_5 ;
for (; ; )
{
if ( ! F_37 ( V_28 ) ) break;
V_69 = V_28 ;
V_28 = V_28 -> V_15 ;
if ( V_28 == NULL ) break;
}
if ( V_68 != NULL ) * V_68 = V_69 -> V_11 ;
return ( V_69 ) ;
}
int F_38 ( T_1 * V_5 )
{
return ( V_5 -> V_11 ) ;
}
T_1 * F_39 ( T_1 * V_5 , int type )
{
int V_70 , V_71 ;
if( ! V_5 ) return NULL ;
V_71 = type & 0xff ;
do {
if ( V_5 -> V_1 != NULL )
{
V_70 = V_5 -> V_1 -> type ;
if ( ! V_71 )
{
if ( V_70 & type ) return ( V_5 ) ;
}
else if ( V_70 == type )
return ( V_5 ) ;
}
V_5 = V_5 -> V_15 ;
} while ( V_5 != NULL );
return ( NULL ) ;
}
T_1 * F_40 ( T_1 * V_28 )
{
if( ! V_28 ) return NULL ;
return V_28 -> V_15 ;
}
void F_41 ( T_1 * V_5 )
{
T_1 * V_28 ;
int V_72 ;
while ( V_5 != NULL )
{
V_28 = V_5 ;
V_72 = V_28 -> V_16 ;
V_5 = V_5 -> V_15 ;
F_8 ( V_28 ) ;
if ( V_72 > 1 ) break;
}
}
T_1 * F_42 ( T_1 * V_40 )
{
T_1 * V_2 = NULL , * V_73 = NULL , * V_5 , * V_74 ;
for ( V_5 = V_40 ; V_5 != NULL ; V_5 = V_5 -> V_15 )
{
if ( ( V_74 = F_1 ( V_5 -> V_1 ) ) == NULL ) goto V_75;
V_74 -> V_6 = V_5 -> V_6 ;
V_74 -> V_7 = V_5 -> V_7 ;
V_74 -> V_8 = V_5 -> V_8 ;
V_74 -> V_9 = V_5 -> V_9 ;
V_74 -> V_10 = V_5 -> V_10 ;
V_74 -> V_12 = V_5 -> V_12 ;
if ( ! F_43 ( V_5 , ( char * ) V_74 ) )
{
F_8 ( V_74 ) ;
goto V_75;
}
if ( ! F_44 ( V_19 , & V_74 -> V_20 ,
& V_5 -> V_20 ) )
goto V_75;
if ( V_2 == NULL )
{
V_73 = V_74 ;
V_2 = V_73 ;
}
else
{
F_34 ( V_73 , V_74 ) ;
V_73 = V_74 ;
}
}
return ( V_2 ) ;
V_75:
if ( V_2 != NULL )
F_8 ( V_2 ) ;
return ( NULL ) ;
}
void F_45 ( T_1 * V_28 )
{
F_15 ( V_28 , F_46 ( V_28 -> V_15 ) ) ;
V_28 -> V_11 = V_28 -> V_15 -> V_11 ;
}
int F_47 ( long V_76 , void * V_77 , T_4 * V_78 ,
T_5 * V_79 , T_6 * V_80 )
{
return F_48 ( V_19 , V_76 , V_77 ,
V_78 , V_79 , V_80 ) ;
}
int F_49 ( T_1 * V_5 , int V_81 , void * V_82 )
{
return ( F_50 ( & ( V_5 -> V_20 ) , V_81 , V_82 ) ) ;
}
void * F_51 ( T_1 * V_5 , int V_81 )
{
return ( F_52 ( & ( V_5 -> V_20 ) , V_81 ) ) ;
}
unsigned long F_53 ( T_1 * V_5 )
{
if( V_5 ) return V_5 -> V_17 ;
return 0 ;
}
unsigned long F_54 ( T_1 * V_5 )
{
if( V_5 ) return V_5 -> V_18 ;
return 0 ;
}
