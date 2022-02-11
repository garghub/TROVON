static int F_1 ( int V_1 , T_1 * V_2 )
{
return V_1 ;
}
int F_2 ( T_1 * V_3 )
{
T_2 * V_4 , * V_5 , * V_6 = NULL ;
T_3 * V_7 ;
int V_8 , V_9 , V_1 = 0 ;
int V_10 ;
int (* F_3)();
F_4 ( T_2 ) * V_11 = NULL ;
if ( V_3 -> V_12 == NULL )
{
F_5 ( V_13 , V_14 ) ;
return - 1 ;
}
F_3 = V_3 -> V_15 ;
if ( F_3 == NULL ) F_3 = F_1 ;
if ( V_3 -> V_16 == NULL )
{
if ( ( ( V_3 -> V_16 = F_6 () ) == NULL ) ||
( ! F_7 ( V_3 -> V_16 , V_3 -> V_12 ) ) )
{
F_5 ( V_13 , V_17 ) ;
goto V_18;
}
F_8 ( & V_3 -> V_12 -> V_19 , 1 , V_20 ) ;
V_3 -> V_21 = 1 ;
}
if ( V_3 -> V_22 != NULL
&& ( V_11 = F_9 ( V_3 -> V_22 ) ) == NULL )
{
F_5 ( V_13 , V_17 ) ;
goto V_18;
}
V_10 = F_10 ( V_3 -> V_16 ) ;
V_4 = F_11 ( V_3 -> V_16 , V_10 - 1 ) ;
V_8 = V_3 -> V_8 ;
for (; ; )
{
if ( V_8 < V_10 ) break;
V_7 = F_12 ( V_4 ) ;
if ( V_3 -> V_23 ( V_3 , V_4 , V_4 ) ) break;
if ( V_3 -> V_22 != NULL )
{
V_5 = F_13 ( V_3 , V_11 , V_4 ) ;
if ( V_5 != NULL )
{
if ( ! F_7 ( V_3 -> V_16 , V_5 ) )
{
F_5 ( V_13 , V_17 ) ;
goto V_18;
}
F_8 ( & V_5 -> V_19 , 1 , V_20 ) ;
F_14 ( V_11 , V_5 ) ;
V_3 -> V_21 ++ ;
V_4 = V_5 ;
V_10 ++ ;
continue;
}
}
break;
}
V_9 = F_10 ( V_3 -> V_16 ) ;
V_4 = F_11 ( V_3 -> V_16 , V_9 - 1 ) ;
V_7 = F_15 ( V_4 ) ;
if ( V_3 -> V_23 ( V_3 , V_4 , V_4 ) )
{
if ( F_10 ( V_3 -> V_16 ) == 1 )
{
V_1 = V_3 -> V_24 ( & V_5 , V_3 , V_4 ) ;
if ( ( V_1 <= 0 ) || F_16 ( V_4 , V_5 ) )
{
V_3 -> error = V_25 ;
V_3 -> V_26 = V_4 ;
V_3 -> V_27 = V_9 - 1 ;
if ( V_1 == 1 ) F_17 ( V_5 ) ;
V_1 = F_3 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_18;
}
else
{
F_17 ( V_4 ) ;
V_4 = V_5 ;
F_18 ( V_3 -> V_16 , V_9 - 1 , V_4 ) ;
V_3 -> V_21 = 0 ;
}
}
else
{
V_6 = F_19 ( V_3 -> V_16 ) ;
V_3 -> V_21 -- ;
V_10 -- ;
V_4 = F_11 ( V_3 -> V_16 , V_10 - 1 ) ;
}
}
for (; ; )
{
if ( V_8 < V_10 ) break;
V_7 = F_12 ( V_4 ) ;
if ( V_3 -> V_23 ( V_3 , V_4 , V_4 ) ) break;
V_1 = V_3 -> V_24 ( & V_5 , V_3 , V_4 ) ;
if ( V_1 < 0 ) return V_1 ;
if ( V_1 == 0 ) break;
V_4 = V_5 ;
if ( ! F_7 ( V_3 -> V_16 , V_4 ) )
{
F_17 ( V_5 ) ;
F_5 ( V_13 , V_17 ) ;
return 0 ;
}
V_10 ++ ;
}
V_7 = F_12 ( V_4 ) ;
if ( ! V_3 -> V_23 ( V_3 , V_4 , V_4 ) )
{
if ( ( V_6 == NULL ) || ! V_3 -> V_23 ( V_3 , V_4 , V_6 ) )
{
if ( V_3 -> V_21 >= V_10 )
V_3 -> error = V_28 ;
else
V_3 -> error = V_29 ;
V_3 -> V_26 = V_4 ;
}
else
{
F_7 ( V_3 -> V_16 , V_6 ) ;
V_10 ++ ;
V_3 -> V_21 = V_10 ;
V_3 -> V_26 = V_6 ;
V_3 -> error = V_30 ;
V_6 = NULL ;
}
V_3 -> V_27 = V_10 - 1 ;
V_1 = F_3 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_18;
}
if ( V_3 -> V_31 > 0 ) V_1 = F_20 ( V_3 ) ;
if ( ! V_1 ) goto V_18;
if ( V_3 -> V_32 > 0 ) V_1 = F_21 ( V_3 ) ;
if ( ! V_1 ) goto V_18;
F_22 ( NULL , V_3 -> V_16 ) ;
if ( V_3 -> V_33 != NULL )
V_1 = V_3 -> V_33 ( V_3 ) ;
else
V_1 = F_23 ( V_3 ) ;
if ( 0 )
{
V_18:
F_22 ( NULL , V_3 -> V_16 ) ;
}
if ( V_11 != NULL ) F_24 ( V_11 ) ;
if ( V_6 != NULL ) F_17 ( V_6 ) ;
return V_1 ;
}
static int V_23 ( T_1 * V_3 , T_2 * V_4 , T_2 * V_34 )
{
int V_35 ;
V_35 = F_25 ( V_34 , V_4 ) ;
if ( V_35 == V_36 )
return 1 ;
if ( ! ( V_3 -> V_37 & V_38 ) )
return 0 ;
V_3 -> error = V_35 ;
V_3 -> V_26 = V_4 ;
V_3 -> V_39 = V_34 ;
if ( V_3 -> V_15 )
return V_3 -> V_15 ( 0 , V_3 ) ;
return 0 ;
}
static int F_26 ( T_2 * * V_34 , T_1 * V_3 , T_2 * V_4 )
{
* V_34 = F_13 ( V_3 , V_3 -> V_40 , V_4 ) ;
if ( * V_34 )
{
F_8 ( & ( * V_34 ) -> V_19 , 1 , V_20 ) ;
return 1 ;
}
else
return 0 ;
}
static int F_20 ( T_1 * V_3 )
{
#ifdef F_27
return 1 ;
#else
int V_9 , V_1 = 0 ;
T_2 * V_4 ;
int (* F_3)();
F_3 = V_3 -> V_15 ;
if ( F_3 == NULL ) F_3 = F_1 ;
for ( V_9 = 0 ; V_9 < V_3 -> V_21 ; V_9 ++ )
{
V_4 = F_11 ( V_3 -> V_16 , V_9 ) ;
if ( ! F_28 ( V_4 , V_3 -> V_31 , V_9 ) )
{
if ( V_9 )
V_3 -> error = V_41 ;
else
V_3 -> error = V_42 ;
V_3 -> V_27 = V_9 ;
V_3 -> V_26 = V_4 ;
V_1 = F_3 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_18;
}
if ( ( V_9 > 1 ) && ( V_4 -> V_43 != - 1 )
&& ( V_9 > ( V_4 -> V_43 + 1 ) ) )
{
V_3 -> error = V_44 ;
V_3 -> V_27 = V_9 ;
V_3 -> V_26 = V_4 ;
V_1 = F_3 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_18;
}
}
V_1 = 1 ;
V_18:
return V_1 ;
#endif
}
static int F_21 ( T_1 * V_3 )
{
#ifdef F_27
return 1 ;
#else
int V_9 , V_1 ;
T_2 * V_4 ;
int (* F_3)();
F_3 = V_3 -> V_15 ;
if ( F_3 == NULL ) F_3 = F_1 ;
V_9 = F_10 ( V_3 -> V_16 ) - 1 ;
V_4 = F_11 ( V_3 -> V_16 , V_9 ) ;
V_1 = F_29 ( V_4 , V_3 -> V_32 , 0 ) ;
if ( V_1 == V_45 )
return 1 ;
V_3 -> V_27 = F_10 ( V_3 -> V_16 ) - 1 ;
V_3 -> V_26 = V_4 ;
if ( V_1 == V_46 )
V_3 -> error = V_47 ;
else
V_3 -> error = V_48 ;
V_1 = F_3 ( 0 , V_3 ) ;
return V_1 ;
#endif
}
static int F_23 ( T_1 * V_3 )
{
int V_9 , V_1 = 0 , V_49 ;
T_2 * V_50 , * V_51 ;
T_4 * V_52 = NULL ;
T_5 * V_53 ;
int (* F_3)();
F_3 = V_3 -> V_15 ;
if ( F_3 == NULL ) F_3 = F_1 ;
V_49 = F_10 ( V_3 -> V_16 ) ;
V_3 -> V_27 = V_49 - 1 ;
V_49 -- ;
V_51 = F_11 ( V_3 -> V_16 , V_49 ) ;
if ( V_3 -> V_37 & V_54 )
V_53 = & V_3 -> V_55 ;
else
V_53 = NULL ;
if ( V_3 -> V_23 ( V_3 , V_51 , V_51 ) )
V_50 = V_51 ;
else
{
if ( V_49 <= 0 )
{
V_3 -> error = V_56 ;
V_3 -> V_26 = V_51 ;
V_1 = F_3 ( 0 , V_3 ) ;
goto V_18;
}
else
{
V_49 -- ;
V_3 -> V_27 = V_49 ;
V_50 = F_11 ( V_3 -> V_16 , V_49 ) ;
}
}
while ( V_49 >= 0 )
{
V_3 -> V_27 = V_49 ;
if ( ! V_50 -> V_57 )
{
if ( ( V_52 = F_30 ( V_51 ) ) == NULL )
{
V_3 -> error = V_58 ;
V_3 -> V_26 = V_51 ;
V_1 = (* F_3)( 0 , V_3 ) ;
if ( ! V_1 ) goto V_18;
}
if ( F_31 ( V_50 , V_52 ) <= 0 )
{
V_3 -> error = V_59 ;
V_3 -> V_26 = V_50 ;
V_1 = (* F_3)( 0 , V_3 ) ;
if ( ! V_1 )
{
F_32 ( V_52 ) ;
goto V_18;
}
}
F_32 ( V_52 ) ;
V_52 = NULL ;
V_9 = F_33 ( F_34 ( V_50 ) , V_53 ) ;
if ( V_9 == 0 )
{
V_3 -> error = V_60 ;
V_3 -> V_26 = V_50 ;
V_1 = (* F_3)( 0 , V_3 ) ;
if ( ! V_1 ) goto V_18;
}
if ( V_9 > 0 )
{
V_3 -> error = V_61 ;
V_3 -> V_26 = V_50 ;
V_1 = (* F_3)( 0 , V_3 ) ;
if ( ! V_1 ) goto V_18;
}
V_50 -> V_57 = 1 ;
}
V_9 = F_33 ( F_35 ( V_50 ) , V_53 ) ;
if ( V_9 == 0 )
{
V_3 -> error = V_62 ;
V_3 -> V_26 = V_50 ;
V_1 = (* F_3)( 0 , V_3 ) ;
if ( ! V_1 ) goto V_18;
}
if ( V_9 < 0 )
{
V_3 -> error = V_63 ;
V_3 -> V_26 = V_50 ;
V_1 = (* F_3)( 0 , V_3 ) ;
if ( ! V_1 ) goto V_18;
}
V_3 -> V_26 = V_50 ;
V_1 = (* F_3)( 1 , V_3 ) ;
if ( ! V_1 ) goto V_18;
V_49 -- ;
if ( V_49 >= 0 )
{
V_51 = V_50 ;
V_50 = F_11 ( V_3 -> V_16 , V_49 ) ;
}
}
V_1 = 1 ;
V_18:
return V_1 ;
}
int F_36 ( T_6 * V_64 )
{
return F_33 ( V_64 , NULL ) ;
}
int F_33 ( T_6 * V_64 , T_5 * V_65 )
{
char * V_66 ;
T_6 V_67 ;
T_5 V_68 ;
char V_69 [ 24 ] , V_70 [ 24 ] , * V_71 ;
int V_9 , V_72 ;
V_71 = V_69 ;
V_9 = V_64 -> V_73 ;
V_66 = ( char * ) V_64 -> V_74 ;
if ( V_64 -> type == V_75 )
{
if ( ( V_9 < 11 ) || ( V_9 > 17 ) ) return 0 ;
memcpy ( V_71 , V_66 , 10 ) ;
V_71 += 10 ;
V_66 += 10 ;
}
else
{
if ( V_9 < 13 ) return 0 ;
memcpy ( V_71 , V_66 , 12 ) ;
V_71 += 12 ;
V_66 += 12 ;
}
if ( ( * V_66 == 'Z' ) || ( * V_66 == '-' ) || ( * V_66 == '+' ) )
{ * ( V_71 ++ ) = '0' ; * ( V_71 ++ ) = '0' ; }
else
{
* ( V_71 ++ ) = * ( V_66 ++ ) ;
* ( V_71 ++ ) = * ( V_66 ++ ) ;
if ( * V_66 == '.' )
{
V_66 ++ ;
while ( ( * V_66 >= '0' ) && ( * V_66 <= '9' ) ) V_66 ++ ;
}
}
* ( V_71 ++ ) = 'Z' ;
* ( V_71 ++ ) = '\0' ;
if ( * V_66 == 'Z' )
V_68 = 0 ;
else
{
if ( ( * V_66 != '+' ) && ( V_66 [ 5 ] != '-' ) )
return 0 ;
V_68 = ( ( V_66 [ 1 ] - '0' ) * 10 + ( V_66 [ 2 ] - '0' ) ) * 60 ;
V_68 += ( V_66 [ 3 ] - '0' ) * 10 + ( V_66 [ 4 ] - '0' ) ;
if ( * V_66 == '-' )
V_68 = - V_68 ;
}
V_67 . type = V_64 -> type ;
V_67 . V_73 = sizeof( V_70 ) ;
V_67 . V_74 = ( unsigned char * ) V_70 ;
F_37 ( & V_67 , - V_68 * 60 , V_65 ) ;
if ( V_64 -> type == V_75 )
{
V_9 = ( V_69 [ 0 ] - '0' ) * 10 + ( V_69 [ 1 ] - '0' ) ;
if ( V_9 < 50 ) V_9 += 100 ;
V_72 = ( V_70 [ 0 ] - '0' ) * 10 + ( V_70 [ 1 ] - '0' ) ;
if ( V_72 < 50 ) V_72 += 100 ;
if ( V_9 < V_72 ) return - 1 ;
if ( V_9 > V_72 ) return 1 ;
}
V_9 = strcmp ( V_69 , V_70 ) ;
if ( V_9 == 0 )
return - 1 ;
else
return V_9 ;
}
T_6 * F_38 ( T_6 * V_76 , long V_77 )
{
return F_37 ( V_76 , V_77 , NULL ) ;
}
T_6 * F_37 ( T_6 * V_76 , long V_77 , T_5 * V_78 )
{
T_5 V_79 ;
if ( V_78 ) V_79 = * V_78 ;
else time ( & V_79 ) ;
V_79 += V_77 ;
if ( ! V_76 ) return F_39 ( V_76 , V_79 ) ;
if ( V_76 -> type == V_75 ) return F_40 ( V_76 , V_79 ) ;
return F_41 ( V_76 , V_79 ) ;
}
int F_42 ( long V_80 , void * V_81 , T_7 * V_82 ,
T_8 * V_83 , T_9 * V_84 )
{
V_85 ++ ;
return F_43 ( V_85 - 1 ,
& V_86 ,
V_80 , V_81 , V_82 , V_83 , V_84 ) ;
}
int F_44 ( T_1 * V_3 , int V_87 , void * V_74 )
{
return F_45 ( & V_3 -> V_88 , V_87 , V_74 ) ;
}
void * F_46 ( T_1 * V_3 , int V_87 )
{
return F_47 ( & V_3 -> V_88 , V_87 ) ;
}
int F_48 ( T_1 * V_3 )
{
return V_3 -> error ;
}
void F_49 ( T_1 * V_3 , int V_89 )
{
V_3 -> error = V_89 ;
}
int F_50 ( T_1 * V_3 )
{
return V_3 -> V_27 ;
}
T_2 * F_51 ( T_1 * V_3 )
{
return V_3 -> V_26 ;
}
int F_52 ( T_1 * V_3 , int V_31 )
{
return F_53 ( V_3 , 0 , V_31 , 0 ) ;
}
int F_54 ( T_1 * V_3 , int V_32 )
{
return F_53 ( V_3 , 0 , 0 , V_32 ) ;
}
int F_53 ( T_1 * V_3 , int V_90 ,
int V_31 , int V_32 )
{
int V_87 ;
if ( ! V_31 ) V_31 = V_90 ;
if ( V_31 )
{
T_10 * V_91 ;
V_87 = F_55 ( V_31 ) ;
if ( V_87 == - 1 )
{
F_5 ( V_92 ,
V_93 ) ;
return 0 ;
}
V_91 = F_56 ( V_87 ) ;
if ( V_91 -> V_32 == V_94 )
{
V_87 = F_55 ( V_90 ) ;
if ( V_87 == - 1 )
{
F_5 ( V_92 ,
V_93 ) ;
return 0 ;
}
V_91 = F_56 ( V_87 ) ;
}
if ( ! V_32 ) V_32 = V_91 -> V_32 ;
}
if ( V_32 )
{
V_87 = F_57 ( V_32 ) ;
if ( V_87 == - 1 )
{
F_5 ( V_92 ,
V_95 ) ;
return 0 ;
}
}
if ( V_31 ) V_3 -> V_31 = V_31 ;
if ( V_32 ) V_3 -> V_32 = V_32 ;
return 1 ;
}
T_1 * F_58 ( void )
{
T_1 * V_3 ;
V_3 = ( T_1 * ) F_59 ( sizeof( T_1 ) ) ;
if ( V_3 ) memset ( V_3 , 0 , sizeof( T_1 ) ) ;
return V_3 ;
}
void F_60 ( T_1 * V_3 )
{
F_61 ( V_3 ) ;
F_62 ( V_3 ) ;
}
void F_61 ( T_1 * V_3 )
{
if ( V_3 -> V_96 ) V_3 -> V_96 ( V_3 ) ;
if ( V_3 -> V_16 != NULL )
{
F_63 ( V_3 -> V_16 , F_17 ) ;
V_3 -> V_16 = NULL ;
}
F_64 ( V_86 , V_3 , & ( V_3 -> V_88 ) ) ;
memset ( & V_3 -> V_88 , 0 , sizeof( V_97 ) ) ;
}
void F_65 ( T_1 * V_3 , long V_37 )
{
V_3 -> V_37 |= V_37 ;
}
void F_66 ( T_1 * V_3 , long V_37 , T_5 V_79 )
{
V_3 -> V_55 = V_79 ;
V_3 -> V_37 |= V_54 ;
}
