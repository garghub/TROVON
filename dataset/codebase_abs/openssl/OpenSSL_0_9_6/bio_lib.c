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
return ( 0 ) ;
return ( 1 ) ;
}
int F_7 ( T_1 * V_22 )
{
int V_2 = 0 , V_23 ;
if ( V_22 == NULL ) return ( 0 ) ;
V_23 = F_8 ( & V_22 -> V_16 , - 1 , V_24 ) ;
#ifdef F_9
F_9 ( L_1 , V_22 ) ;
#endif
if ( V_23 > 0 ) return ( 1 ) ;
#ifdef F_10
if ( V_23 < 0 )
{
fprintf ( V_25 , L_2 ) ;
abort () ;
}
#endif
if ( ( V_22 -> V_6 != NULL ) &&
( ( V_23 = ( int ) V_22 -> V_6 ( V_22 , V_26 , NULL , 0 , 0L , 1L ) ) <= 0 ) )
return ( V_23 ) ;
F_11 ( V_19 , V_22 , & V_22 -> V_20 ) ;
if ( ( V_22 -> V_1 == NULL ) || ( V_22 -> V_1 -> V_27 == NULL ) ) return ( 1 ) ;
V_2 = V_22 -> V_1 -> V_27 ( V_22 ) ;
F_5 ( V_22 ) ;
return ( 1 ) ;
}
void F_12 ( T_1 * V_22 )
{ F_7 ( V_22 ) ; }
int F_13 ( T_1 * V_28 , void * V_29 , int V_30 )
{
int V_23 ;
long (* F_14)();
if ( ( V_28 == NULL ) || ( V_28 -> V_1 == NULL ) || ( V_28 -> V_1 -> V_31 == NULL ) )
{
F_3 ( V_32 , V_33 ) ;
return ( - 2 ) ;
}
F_14 = V_28 -> V_6 ;
if ( ( F_14 != NULL ) &&
( ( V_23 = ( int ) F_14 ( V_28 , V_34 , V_29 , V_30 , 0L , 1L ) ) <= 0 ) )
return ( V_23 ) ;
if ( ! V_28 -> V_8 )
{
F_3 ( V_32 , V_35 ) ;
return ( - 2 ) ;
}
V_23 = V_28 -> V_1 -> V_31 ( V_28 , V_29 , V_30 ) ;
if ( V_23 > 0 ) V_28 -> V_17 += ( unsigned long ) V_23 ;
if ( F_14 != NULL )
V_23 = ( int ) F_14 ( V_28 , V_34 | V_36 , V_29 , V_30 ,
0L , ( long ) V_23 ) ;
return ( V_23 ) ;
}
int F_15 ( T_1 * V_28 , const void * V_37 , int V_38 )
{
int V_23 ;
long (* F_14)();
if ( V_28 == NULL )
return ( 0 ) ;
F_14 = V_28 -> V_6 ;
if ( ( V_28 -> V_1 == NULL ) || ( V_28 -> V_1 -> V_39 == NULL ) )
{
F_3 ( V_40 , V_33 ) ;
return ( - 2 ) ;
}
if ( ( F_14 != NULL ) &&
( ( V_23 = ( int ) F_14 ( V_28 , V_41 , V_37 , V_38 , 0L , 1L ) ) <= 0 ) )
return ( V_23 ) ;
if ( ! V_28 -> V_8 )
{
F_3 ( V_40 , V_35 ) ;
return ( - 2 ) ;
}
V_23 = V_28 -> V_1 -> V_39 ( V_28 , V_37 , V_38 ) ;
if ( V_23 > 0 ) V_28 -> V_18 += ( unsigned long ) V_23 ;
if ( F_14 != NULL )
V_23 = ( int ) F_14 ( V_28 , V_41 | V_36 , V_37 , V_38 ,
0L , ( long ) V_23 ) ;
return ( V_23 ) ;
}
int F_16 ( T_1 * V_28 , const char * V_37 )
{
int V_23 ;
long (* F_14)();
if ( ( V_28 == NULL ) || ( V_28 -> V_1 == NULL ) || ( V_28 -> V_1 -> V_42 == NULL ) )
{
F_3 ( V_43 , V_33 ) ;
return ( - 2 ) ;
}
F_14 = V_28 -> V_6 ;
if ( ( F_14 != NULL ) &&
( ( V_23 = ( int ) F_14 ( V_28 , V_44 , V_37 , 0 , 0L , 1L ) ) <= 0 ) )
return ( V_23 ) ;
if ( ! V_28 -> V_8 )
{
F_3 ( V_43 , V_35 ) ;
return ( - 2 ) ;
}
V_23 = V_28 -> V_1 -> V_42 ( V_28 , V_37 ) ;
if ( V_23 > 0 ) V_28 -> V_18 += ( unsigned long ) V_23 ;
if ( F_14 != NULL )
V_23 = ( int ) F_14 ( V_28 , V_44 | V_36 , V_37 , 0 ,
0L , ( long ) V_23 ) ;
return ( V_23 ) ;
}
int F_17 ( T_1 * V_28 , char * V_37 , int V_38 )
{
int V_23 ;
long (* F_14)();
if ( ( V_28 == NULL ) || ( V_28 -> V_1 == NULL ) || ( V_28 -> V_1 -> V_45 == NULL ) )
{
F_3 ( V_46 , V_33 ) ;
return ( - 2 ) ;
}
F_14 = V_28 -> V_6 ;
if ( ( F_14 != NULL ) &&
( ( V_23 = ( int ) F_14 ( V_28 , V_47 , V_37 , V_38 , 0L , 1L ) ) <= 0 ) )
return ( V_23 ) ;
if ( ! V_28 -> V_8 )
{
F_3 ( V_46 , V_35 ) ;
return ( - 2 ) ;
}
V_23 = V_28 -> V_1 -> V_45 ( V_28 , V_37 , V_38 ) ;
if ( F_14 != NULL )
V_23 = ( int ) F_14 ( V_28 , V_47 | V_36 , V_37 , V_38 ,
0L , ( long ) V_23 ) ;
return ( V_23 ) ;
}
long F_18 ( T_1 * V_28 , int V_48 , long V_49 , int V_50 )
{
int V_23 ;
V_23 = V_50 ;
return ( F_19 ( V_28 , V_48 , V_49 , ( char * ) & V_23 ) ) ;
}
char * F_20 ( T_1 * V_28 , int V_48 , long V_49 )
{
char * V_51 = NULL ;
if ( F_19 ( V_28 , V_48 , V_49 , ( char * ) & V_51 ) <= 0 )
return ( NULL ) ;
else
return ( V_51 ) ;
}
long F_19 ( T_1 * V_28 , int V_48 , long V_49 , void * V_52 )
{
long V_2 ;
long (* F_14)();
if ( V_28 == NULL ) return ( 0 ) ;
if ( ( V_28 -> V_1 == NULL ) || ( V_28 -> V_1 -> V_53 == NULL ) )
{
F_3 ( V_54 , V_33 ) ;
return ( - 2 ) ;
}
F_14 = V_28 -> V_6 ;
if ( ( F_14 != NULL ) &&
( ( V_2 = F_14 ( V_28 , V_55 , V_52 , V_48 , V_49 , 1L ) ) <= 0 ) )
return ( V_2 ) ;
V_2 = V_28 -> V_1 -> V_53 ( V_28 , V_48 , V_49 , V_52 ) ;
if ( F_14 != NULL )
V_2 = F_14 ( V_28 , V_55 | V_36 , V_52 , V_48 ,
V_49 , V_2 ) ;
return ( V_2 ) ;
}
long F_21 ( T_1 * V_28 , int V_48 , void (* F_22)( struct V_56 * , int , const char * , int , long , long ) )
{
long V_2 ;
long (* F_14)();
if ( V_28 == NULL ) return ( 0 ) ;
if ( ( V_28 -> V_1 == NULL ) || ( V_28 -> V_1 -> V_57 == NULL ) )
{
F_3 ( V_54 , V_33 ) ;
return ( - 2 ) ;
}
F_14 = V_28 -> V_6 ;
if ( ( F_14 != NULL ) &&
( ( V_2 = F_14 ( V_28 , V_55 , ( void * ) & F_22 , V_48 , 0 , 1L ) ) <= 0 ) )
return ( V_2 ) ;
V_2 = V_28 -> V_1 -> V_57 ( V_28 , V_48 , F_22 ) ;
if ( F_14 != NULL )
V_2 = F_14 ( V_28 , V_55 | V_36 , ( void * ) & F_22 , V_48 ,
0 , V_2 ) ;
return ( V_2 ) ;
}
T_3 F_23 ( T_1 * V_5 )
{
return F_19 ( V_5 , V_58 , 0 , NULL ) ;
}
T_3 F_24 ( T_1 * V_5 )
{
return F_19 ( V_5 , V_59 , 0 , NULL ) ;
}
T_1 * F_25 ( T_1 * V_28 , T_1 * V_5 )
{
T_1 * V_60 ;
if ( V_28 == NULL ) return ( V_5 ) ;
V_60 = V_28 ;
while ( V_60 -> V_15 != NULL )
V_60 = V_60 -> V_15 ;
V_60 -> V_15 = V_5 ;
if ( V_5 != NULL )
V_5 -> V_14 = V_60 ;
F_19 ( V_28 , V_61 , 0 , NULL ) ;
return ( V_28 ) ;
}
T_1 * F_26 ( T_1 * V_28 )
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
F_19 ( V_28 , V_62 , 0 , NULL ) ;
return ( V_2 ) ;
}
T_1 * F_27 ( T_1 * V_5 , int * V_63 )
{
T_1 * V_28 , * V_64 ;
V_28 = V_64 = V_5 ;
for (; ; )
{
if ( ! F_28 ( V_28 ) ) break;
V_64 = V_28 ;
V_28 = V_28 -> V_15 ;
if ( V_28 == NULL ) break;
}
if ( V_63 != NULL ) * V_63 = V_64 -> V_11 ;
return ( V_64 ) ;
}
int F_29 ( T_1 * V_5 )
{
return ( V_5 -> V_11 ) ;
}
T_1 * F_30 ( T_1 * V_5 , int type )
{
int V_65 , V_66 ;
if( ! V_5 ) return NULL ;
V_66 = type & 0xff ;
do {
if ( V_5 -> V_1 != NULL )
{
V_65 = V_5 -> V_1 -> type ;
if ( ! V_66 )
{
if ( V_65 & type ) return ( V_5 ) ;
}
else if ( V_65 == type )
return ( V_5 ) ;
}
V_5 = V_5 -> V_15 ;
} while ( V_5 != NULL );
return ( NULL ) ;
}
T_1 * F_31 ( T_1 * V_28 )
{
if( ! V_28 ) return NULL ;
return V_28 -> V_15 ;
}
void F_32 ( T_1 * V_5 )
{
T_1 * V_28 ;
int V_67 ;
while ( V_5 != NULL )
{
V_28 = V_5 ;
V_67 = V_28 -> V_16 ;
V_5 = V_5 -> V_15 ;
F_7 ( V_28 ) ;
if ( V_67 > 1 ) break;
}
}
T_1 * F_33 ( T_1 * V_37 )
{
T_1 * V_2 = NULL , * V_68 = NULL , * V_5 , * V_69 ;
for ( V_5 = V_37 ; V_5 != NULL ; V_5 = V_5 -> V_15 )
{
if ( ( V_69 = F_1 ( V_5 -> V_1 ) ) == NULL ) goto V_70;
V_69 -> V_6 = V_5 -> V_6 ;
V_69 -> V_7 = V_5 -> V_7 ;
V_69 -> V_8 = V_5 -> V_8 ;
V_69 -> V_9 = V_5 -> V_9 ;
V_69 -> V_10 = V_5 -> V_10 ;
V_69 -> V_12 = V_5 -> V_12 ;
if ( ! F_34 ( V_5 , ( char * ) V_69 ) )
{
F_7 ( V_69 ) ;
goto V_70;
}
if ( ! F_35 ( V_19 , & V_69 -> V_20 , & V_5 -> V_20 ) )
goto V_70;
if ( V_2 == NULL )
{
V_68 = V_69 ;
V_2 = V_68 ;
}
else
{
F_25 ( V_68 , V_69 ) ;
V_68 = V_69 ;
}
}
return ( V_2 ) ;
V_70:
if ( V_2 != NULL )
F_7 ( V_2 ) ;
return ( NULL ) ;
}
void F_36 ( T_1 * V_28 )
{
F_37 ( V_28 , F_38 ( V_28 -> V_15 ) ) ;
V_28 -> V_11 = V_28 -> V_15 -> V_11 ;
}
int F_39 ( long V_71 , void * V_72 , T_4 * V_73 ,
T_5 * V_74 , T_6 * V_75 )
{
V_76 ++ ;
return ( F_40 ( V_76 - 1 , & V_19 ,
V_71 , V_72 , V_73 , V_74 , V_75 ) ) ;
}
int F_41 ( T_1 * V_5 , int V_77 , void * V_78 )
{
return ( F_42 ( & ( V_5 -> V_20 ) , V_77 , V_78 ) ) ;
}
void * F_43 ( T_1 * V_5 , int V_77 )
{
return ( F_44 ( & ( V_5 -> V_20 ) , V_77 ) ) ;
}
unsigned long F_45 ( T_1 * V_5 )
{
if( V_5 ) return V_5 -> V_17 ;
return 0 ;
}
unsigned long F_46 ( T_1 * V_5 )
{
if( V_5 ) return V_5 -> V_18 ;
return 0 ;
}
