static int F_1 ( int V_1 , T_1 * V_2 )
{
return ( V_1 ) ;
}
int F_2 ( T_1 * V_3 )
{
T_2 * V_4 , * V_5 , * V_6 = NULL ;
T_3 * V_7 ;
T_4 V_8 ;
int V_9 , V_10 , V_1 = 0 ;
int V_11 ;
int (* F_3)();
F_4 ( T_2 ) * V_12 = NULL ;
if ( V_3 -> V_13 == NULL )
{
F_5 ( V_14 , V_15 ) ;
return ( - 1 ) ;
}
F_3 = V_3 -> V_3 -> V_16 ;
if ( F_3 == NULL ) F_3 = F_1 ;
if ( V_3 -> V_17 == NULL )
{
if ( ( ( V_3 -> V_17 = F_6 () ) == NULL ) ||
( ! F_7 ( V_3 -> V_17 , V_3 -> V_13 ) ) )
{
F_5 ( V_14 , V_18 ) ;
goto V_19;
}
F_8 ( & V_3 -> V_13 -> V_20 , 1 , V_21 ) ;
V_3 -> V_22 = 1 ;
}
if ( V_3 -> V_23 != NULL
&& ( V_12 = F_9 ( V_3 -> V_23 ) ) == NULL )
{
F_5 ( V_14 , V_18 ) ;
goto V_19;
}
V_11 = F_10 ( V_3 -> V_17 ) ;
V_4 = F_11 ( V_3 -> V_17 , V_11 - 1 ) ;
V_9 = V_3 -> V_9 ;
for (; ; )
{
if ( V_9 < V_11 ) break;
V_7 = F_12 ( V_4 ) ;
if ( F_13 ( F_14 ( V_4 ) , V_7 ) == 0 )
break;
if ( V_3 -> V_23 != NULL )
{
V_5 = F_15 ( V_12 , V_7 ) ;
if ( V_5 != NULL )
{
if ( ! F_7 ( V_3 -> V_17 , V_5 ) )
{
F_5 ( V_14 , V_18 ) ;
goto V_19;
}
F_8 ( & V_5 -> V_20 , 1 , V_21 ) ;
F_16 ( V_12 , V_5 ) ;
V_3 -> V_22 ++ ;
V_4 = V_5 ;
V_11 ++ ;
continue;
}
}
break;
}
V_10 = F_10 ( V_3 -> V_17 ) ;
V_4 = F_11 ( V_3 -> V_17 , V_10 - 1 ) ;
V_7 = F_14 ( V_4 ) ;
if ( F_13 ( V_7 , F_12 ( V_4 ) )
== 0 )
{
if ( F_10 ( V_3 -> V_17 ) == 1 )
{
V_1 = F_17 ( V_3 , V_24 , V_7 , & V_8 ) ;
if ( ( V_1 != V_24 ) || F_18 ( V_4 , V_8 . V_25 . V_26 ) )
{
V_3 -> error = V_27 ;
V_3 -> V_28 = V_4 ;
V_3 -> V_29 = V_10 - 1 ;
if( V_1 == V_24 ) F_19 ( & V_8 ) ;
V_1 = F_3 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_19;
}
else
{
F_20 ( V_4 ) ;
V_4 = V_8 . V_25 . V_26 ;
F_21 ( V_3 -> V_17 , V_10 - 1 , V_4 ) ;
V_3 -> V_22 = 0 ;
}
}
else
{
V_6 = F_22 ( V_3 -> V_17 ) ;
V_3 -> V_22 -- ;
V_11 -- ;
V_4 = F_11 ( V_3 -> V_17 , V_11 - 1 ) ;
}
}
for (; ; )
{
if ( V_9 < V_11 ) break;
V_7 = F_12 ( V_4 ) ;
if ( F_13 ( F_14 ( V_4 ) , V_7 ) == 0 )
break;
V_1 = F_17 ( V_3 , V_24 , V_7 , & V_8 ) ;
if ( V_1 != V_24 )
{
if ( V_1 == V_30 )
{
F_19 ( & V_8 ) ;
F_5 ( V_14 , V_31 ) ;
return ( V_1 ) ;
}
else if ( V_1 != V_32 )
{
F_19 ( & V_8 ) ;
return ( V_1 ) ;
}
break;
}
V_4 = V_8 . V_25 . V_26 ;
if ( ! F_7 ( V_3 -> V_17 , V_8 . V_25 . V_26 ) )
{
F_19 ( & V_8 ) ;
F_5 ( V_14 , V_18 ) ;
return ( 0 ) ;
}
V_11 ++ ;
}
V_7 = F_12 ( V_4 ) ;
if ( F_13 ( F_14 ( V_4 ) , V_7 ) != 0 )
{
if ( ( V_6 == NULL ) || ( F_13 ( F_14 ( V_6 ) , V_7 ) != 0 ) )
{
if ( V_3 -> V_22 >= V_11 )
V_3 -> error = V_33 ;
else
V_3 -> error = V_34 ;
V_3 -> V_28 = V_4 ;
}
else
{
F_7 ( V_3 -> V_17 , V_6 ) ;
V_11 ++ ;
V_3 -> V_22 = V_11 ;
V_3 -> V_28 = V_6 ;
V_3 -> error = V_35 ;
V_6 = NULL ;
}
V_3 -> V_29 = V_11 - 1 ;
V_1 = F_3 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_19;
}
if( V_3 -> V_36 > 0 ) V_1 = F_23 ( V_3 ) ;
if( ! V_1 ) goto V_19;
if( V_3 -> V_37 > 0 ) V_1 = F_24 ( V_3 ) ;
if( ! V_1 ) goto V_19;
F_25 ( NULL , V_3 -> V_17 ) ;
if ( V_3 -> V_3 -> V_38 != NULL )
V_1 = V_3 -> V_3 -> V_38 ( V_3 ) ;
else
V_1 = F_26 ( V_3 ) ;
if ( 0 )
{
V_19:
F_25 ( NULL , V_3 -> V_17 ) ;
}
if ( V_12 != NULL ) F_27 ( V_12 ) ;
if ( V_6 != NULL ) F_20 ( V_6 ) ;
return ( V_1 ) ;
}
static int F_23 ( T_1 * V_3 )
{
#ifdef F_28
return 1 ;
#else
int V_10 , V_1 = 0 ;
T_2 * V_4 ;
int (* F_3)();
F_3 = V_3 -> V_3 -> V_16 ;
if ( F_3 == NULL ) F_3 = F_1 ;
for( V_10 = 0 ; V_10 < V_3 -> V_22 ; V_10 ++ ) {
V_4 = F_11 ( V_3 -> V_17 , V_10 ) ;
if( ! F_29 ( V_4 , V_3 -> V_36 , V_10 ) ) {
if( V_10 ) V_3 -> error = V_39 ;
else V_3 -> error = V_40 ;
V_3 -> V_29 = V_10 ;
V_3 -> V_28 = V_4 ;
V_1 = F_3 ( 0 , V_3 ) ;
if( ! V_1 ) goto V_19;
}
if( ( V_10 > 1 ) && ( V_4 -> V_41 != - 1 )
&& ( V_10 > ( V_4 -> V_41 + 1 ) ) ) {
V_3 -> error = V_42 ;
V_3 -> V_29 = V_10 ;
V_3 -> V_28 = V_4 ;
V_1 = F_3 ( 0 , V_3 ) ;
if( ! V_1 ) goto V_19;
}
}
V_1 = 1 ;
V_19:
return ( V_1 ) ;
#endif
}
static int F_24 ( T_1 * V_3 )
{
#ifdef F_28
return 1 ;
#else
int V_10 , V_1 ;
T_2 * V_4 ;
int (* F_3)();
F_3 = V_3 -> V_3 -> V_16 ;
if ( F_3 == NULL ) F_3 = F_1 ;
V_10 = F_10 ( V_3 -> V_17 ) - 1 ;
V_4 = F_11 ( V_3 -> V_17 , V_10 ) ;
V_1 = F_30 ( V_4 , V_3 -> V_37 , 0 ) ;
if( V_1 == V_43 ) return 1 ;
V_3 -> V_29 = F_10 ( V_3 -> V_17 ) - 1 ;
V_3 -> V_28 = V_4 ;
if( V_1 == V_44 ) V_3 -> error = V_45 ;
else V_3 -> error = V_46 ;
V_1 = F_3 ( 0 , V_3 ) ;
return ( V_1 ) ;
#endif
}
static int F_26 ( T_1 * V_3 )
{
int V_10 , V_1 = 0 , V_47 ;
T_2 * V_48 , * V_49 ;
T_5 * V_50 = NULL ;
int (* F_3)();
F_3 = V_3 -> V_3 -> V_16 ;
if ( F_3 == NULL ) F_3 = F_1 ;
V_47 = F_10 ( V_3 -> V_17 ) ;
V_3 -> V_29 = V_47 - 1 ;
V_47 -- ;
V_49 = F_11 ( V_3 -> V_17 , V_47 ) ;
if ( F_13 ( F_14 ( V_49 ) ,
F_12 ( V_49 ) ) == 0 )
V_48 = V_49 ;
else
{
if ( V_47 <= 0 )
{
V_3 -> error = V_51 ;
V_3 -> V_28 = V_49 ;
V_1 = F_3 ( 0 , V_3 ) ;
goto V_19;
}
else
{
V_47 -- ;
V_3 -> V_29 = V_47 ;
V_48 = F_11 ( V_3 -> V_17 , V_47 ) ;
}
}
while ( V_47 >= 0 )
{
V_3 -> V_29 = V_47 ;
if ( ! V_48 -> V_52 )
{
if ( ( V_50 = F_31 ( V_49 ) ) == NULL )
{
V_3 -> error = V_53 ;
V_3 -> V_28 = V_49 ;
V_1 = (* F_3)( 0 , V_3 ) ;
if ( ! V_1 ) goto V_19;
}
if ( F_32 ( V_48 , V_50 ) <= 0 )
{
F_33 ( V_50 ) ;
V_3 -> error = V_54 ;
V_3 -> V_28 = V_48 ;
V_1 = (* F_3)( 0 , V_3 ) ;
if ( ! V_1 ) goto V_19;
}
F_33 ( V_50 ) ;
V_50 = NULL ;
V_10 = F_34 ( F_35 ( V_48 ) ) ;
if ( V_10 == 0 )
{
V_3 -> error = V_55 ;
V_3 -> V_28 = V_48 ;
V_1 = (* F_3)( 0 , V_3 ) ;
if ( ! V_1 ) goto V_19;
}
if ( V_10 > 0 )
{
V_3 -> error = V_56 ;
V_3 -> V_28 = V_48 ;
V_1 = (* F_3)( 0 , V_3 ) ;
if ( ! V_1 ) goto V_19;
}
V_48 -> V_52 = 1 ;
}
V_10 = F_34 ( F_36 ( V_48 ) ) ;
if ( V_10 == 0 )
{
V_3 -> error = V_57 ;
V_3 -> V_28 = V_48 ;
V_1 = (* F_3)( 0 , V_3 ) ;
if ( ! V_1 ) goto V_19;
}
if ( V_10 < 0 )
{
V_3 -> error = V_58 ;
V_3 -> V_28 = V_48 ;
V_1 = (* F_3)( 0 , V_3 ) ;
if ( ! V_1 ) goto V_19;
}
V_3 -> V_28 = V_48 ;
V_1 = (* F_3)( 1 , V_3 ) ;
if ( ! V_1 ) goto V_19;
V_47 -- ;
if ( V_47 >= 0 )
{
V_49 = V_48 ;
V_48 = F_11 ( V_3 -> V_17 , V_47 ) ;
}
}
V_1 = 1 ;
V_19:
return ( V_1 ) ;
}
int F_34 ( T_6 * V_59 )
{
char * V_60 ;
T_6 V_61 ;
T_7 V_62 ;
char V_63 [ 24 ] , V_64 [ 24 ] , * V_65 ;
int V_10 , V_66 ;
V_65 = V_63 ;
V_10 = V_59 -> V_67 ;
V_60 = ( char * ) V_59 -> V_25 ;
if ( ( V_10 < 11 ) || ( V_10 > 17 ) ) return ( 0 ) ;
memcpy ( V_65 , V_60 , 10 ) ;
V_65 += 10 ;
V_60 += 10 ;
if ( ( * V_60 == 'Z' ) || ( * V_60 == '-' ) || ( * V_60 == '+' ) )
{ * ( V_65 ++ ) = '0' ; * ( V_65 ++ ) = '0' ; }
else { * ( V_65 ++ ) = * ( V_60 ++ ) ; * ( V_65 ++ ) = * ( V_60 ++ ) ; }
* ( V_65 ++ ) = 'Z' ;
* ( V_65 ++ ) = '\0' ;
if ( * V_60 == 'Z' )
V_62 = 0 ;
else
{
if ( ( * V_60 != '+' ) && ( V_60 [ 5 ] != '-' ) )
return ( 0 ) ;
V_62 = ( ( V_60 [ 1 ] - '0' ) * 10 + ( V_60 [ 2 ] - '0' ) ) * 60 ;
V_62 += ( V_60 [ 3 ] - '0' ) * 10 + ( V_60 [ 4 ] - '0' ) ;
if ( * V_60 == '-' )
V_62 = - V_62 ;
}
V_61 . type = V_68 ;
V_61 . V_67 = sizeof( V_64 ) ;
V_61 . V_25 = ( unsigned char * ) V_64 ;
F_37 ( & V_61 , - V_62 * 60 ) ;
V_10 = ( V_63 [ 0 ] - '0' ) * 10 + ( V_63 [ 1 ] - '0' ) ;
if ( V_10 < 50 ) V_10 += 100 ;
V_66 = ( V_64 [ 0 ] - '0' ) * 10 + ( V_64 [ 1 ] - '0' ) ;
if ( V_66 < 50 ) V_66 += 100 ;
if ( V_10 < V_66 ) return ( - 1 ) ;
if ( V_10 > V_66 ) return ( 1 ) ;
V_10 = strcmp ( V_63 , V_64 ) ;
if ( V_10 == 0 )
return ( - 1 ) ;
else
return ( V_10 ) ;
}
T_6 * F_37 ( T_6 * V_69 , long V_70 )
{
T_7 V_71 ;
time ( & V_71 ) ;
V_71 += V_70 ;
return ( F_38 ( V_69 , V_71 ) ) ;
}
int F_39 ( T_8 * V_3 , T_2 * V_4 )
{
T_4 * V_8 , * V_72 ;
int V_73 = 1 ;
if ( V_4 == NULL ) return ( 0 ) ;
V_8 = ( T_4 * ) Malloc ( sizeof( T_4 ) ) ;
if ( V_8 == NULL )
{
F_5 ( V_74 , V_18 ) ;
return ( 0 ) ;
}
V_8 -> type = V_24 ;
V_8 -> V_25 . V_26 = V_4 ;
F_40 ( V_75 ) ;
F_41 ( V_8 ) ;
V_72 = ( T_4 * ) F_42 ( V_3 -> V_76 , V_8 ) ;
if ( V_72 != NULL )
{
F_43 ( V_3 -> V_76 , V_8 ) ;
F_19 ( V_8 ) ;
Free ( V_8 ) ;
F_42 ( V_3 -> V_76 , V_72 ) ;
F_5 ( V_74 , V_77 ) ;
V_73 = 0 ;
}
F_44 ( V_75 ) ;
return ( V_73 ) ;
}
int F_45 ( T_8 * V_3 , T_9 * V_4 )
{
T_4 * V_8 , * V_72 ;
int V_73 = 1 ;
if ( V_4 == NULL ) return ( 0 ) ;
V_8 = ( T_4 * ) Malloc ( sizeof( T_4 ) ) ;
if ( V_8 == NULL )
{
F_5 ( V_78 , V_18 ) ;
return ( 0 ) ;
}
V_8 -> type = V_79 ;
V_8 -> V_25 . V_80 = V_4 ;
F_40 ( V_75 ) ;
F_41 ( V_8 ) ;
V_72 = ( T_4 * ) F_42 ( V_3 -> V_76 , V_8 ) ;
if ( V_72 != NULL )
{
F_43 ( V_3 -> V_76 , V_8 ) ;
F_19 ( V_8 ) ;
Free ( V_8 ) ;
F_42 ( V_3 -> V_76 , V_72 ) ;
F_5 ( V_78 , V_77 ) ;
V_73 = 0 ;
}
F_44 ( V_75 ) ;
return ( V_73 ) ;
}
int F_46 ( long V_81 , void * V_82 , T_10 * V_83 ,
T_11 * V_84 , T_12 * V_85 )
{
V_86 ++ ;
return ( F_47 ( V_86 - 1 ,
& V_87 ,
V_81 , V_82 , V_83 , V_84 , V_85 ) ) ;
}
int F_48 ( T_1 * V_3 , int V_88 , void * V_25 )
{
return ( F_49 ( & V_3 -> V_89 , V_88 , V_25 ) ) ;
}
void * F_50 ( T_1 * V_3 , int V_88 )
{
return ( F_51 ( & V_3 -> V_89 , V_88 ) ) ;
}
int F_52 ( T_1 * V_3 )
{
return ( V_3 -> error ) ;
}
void F_53 ( T_1 * V_3 , int V_90 )
{
V_3 -> error = V_90 ;
}
int F_54 ( T_1 * V_3 )
{
return ( V_3 -> V_29 ) ;
}
T_2 * F_55 ( T_1 * V_3 )
{
return ( V_3 -> V_28 ) ;
}
int F_56 ( T_1 * V_3 , int V_36 )
{
return F_57 ( V_3 , 0 , V_36 , 0 ) ;
}
int F_58 ( T_1 * V_3 , int V_37 )
{
return F_57 ( V_3 , 0 , 0 , V_37 ) ;
}
int F_57 ( T_1 * V_3 , int V_91 ,
int V_36 , int V_37 )
{
int V_88 ;
if( ! V_36 ) V_36 = V_91 ;
if( V_36 ) {
V_88 = F_59 ( V_36 ) ;
if( V_88 == - 1 ) {
F_5 ( V_92 ,
V_93 ) ;
return 0 ;
}
if( ! V_37 ) {
T_13 * V_94 ;
V_94 = F_60 ( V_88 ) ;
V_37 = V_94 -> V_37 ;
}
}
if( V_37 ) {
V_88 = F_61 ( V_37 ) ;
if( V_88 == - 1 ) {
F_5 ( V_92 ,
V_95 ) ;
return 0 ;
}
}
if( V_36 ) V_3 -> V_36 = V_36 ;
if( V_37 ) V_3 -> V_37 = V_37 ;
return 1 ;
}
