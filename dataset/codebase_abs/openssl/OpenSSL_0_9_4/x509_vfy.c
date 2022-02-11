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
if ( F_13 ( F_14 ( V_4 ) , F_12 ( V_4 ) )
== 0 )
{
if ( F_10 ( V_3 -> V_17 ) == 1 )
{
V_3 -> error = V_24 ;
V_3 -> V_25 = V_4 ;
V_3 -> V_26 = V_10 - 1 ;
V_1 = F_3 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_19;
}
else
{
V_6 = F_17 ( V_3 -> V_17 ) ;
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
V_1 = F_18 ( V_3 , V_27 , V_7 , & V_8 ) ;
if ( V_1 != V_27 )
{
if ( V_1 == V_28 )
{
F_19 ( & V_8 ) ;
F_5 ( V_14 , V_29 ) ;
return ( V_1 ) ;
}
else if ( V_1 != V_30 )
{
F_19 ( & V_8 ) ;
return ( V_1 ) ;
}
break;
}
V_4 = V_8 . V_31 . V_32 ;
if ( ! F_7 ( V_3 -> V_17 , V_8 . V_31 . V_32 ) )
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
V_3 -> V_25 = V_4 ;
}
else
{
F_7 ( V_3 -> V_17 , V_6 ) ;
V_11 ++ ;
V_3 -> V_22 = V_11 ;
V_3 -> V_25 = V_6 ;
V_3 -> error = V_35 ;
V_6 = NULL ;
}
V_3 -> V_26 = V_11 - 1 ;
V_1 = F_3 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_19;
}
F_20 ( NULL , V_3 -> V_17 ) ;
if ( V_3 -> V_3 -> V_36 != NULL )
V_1 = V_3 -> V_3 -> V_36 ( V_3 ) ;
else
V_1 = F_21 ( V_3 ) ;
if ( 0 )
{
V_19:
F_20 ( NULL , V_3 -> V_17 ) ;
}
if ( V_12 != NULL ) F_22 ( V_12 ) ;
if ( V_6 != NULL ) F_23 ( V_6 ) ;
return ( V_1 ) ;
}
static int F_21 ( T_1 * V_3 )
{
int V_10 , V_1 = 0 , V_37 ;
T_2 * V_38 , * V_39 ;
T_5 * V_40 = NULL ;
int (* F_3)();
F_3 = V_3 -> V_3 -> V_16 ;
if ( F_3 == NULL ) F_3 = F_1 ;
V_37 = F_10 ( V_3 -> V_17 ) ;
V_3 -> V_26 = V_37 - 1 ;
V_37 -- ;
V_39 = F_11 ( V_3 -> V_17 , V_37 ) ;
if ( F_13 ( F_14 ( V_39 ) ,
F_12 ( V_39 ) ) == 0 )
V_38 = V_39 ;
else
{
if ( V_37 <= 0 )
{
V_3 -> error = V_41 ;
V_3 -> V_25 = V_39 ;
V_1 = F_3 ( 0 , V_3 ) ;
goto V_19;
}
else
{
V_37 -- ;
V_3 -> V_26 = V_37 ;
V_38 = F_11 ( V_3 -> V_17 , V_37 ) ;
}
}
while ( V_37 >= 0 )
{
V_3 -> V_26 = V_37 ;
if ( ! V_38 -> V_42 )
{
if ( ( V_40 = F_24 ( V_39 ) ) == NULL )
{
V_3 -> error = V_43 ;
V_3 -> V_25 = V_39 ;
V_1 = (* F_3)( 0 , V_3 ) ;
if ( ! V_1 ) goto V_19;
}
if ( F_25 ( V_38 , V_40 ) <= 0 )
{
F_26 ( V_40 ) ;
V_3 -> error = V_44 ;
V_3 -> V_25 = V_38 ;
V_1 = (* F_3)( 0 , V_3 ) ;
if ( ! V_1 ) goto V_19;
}
F_26 ( V_40 ) ;
V_40 = NULL ;
V_10 = F_27 ( F_28 ( V_38 ) ) ;
if ( V_10 == 0 )
{
V_3 -> error = V_45 ;
V_3 -> V_25 = V_38 ;
V_1 = (* F_3)( 0 , V_3 ) ;
if ( ! V_1 ) goto V_19;
}
if ( V_10 > 0 )
{
V_3 -> error = V_46 ;
V_3 -> V_25 = V_38 ;
V_1 = (* F_3)( 0 , V_3 ) ;
if ( ! V_1 ) goto V_19;
}
V_38 -> V_42 = 1 ;
}
V_10 = F_27 ( F_29 ( V_38 ) ) ;
if ( V_10 == 0 )
{
V_3 -> error = V_47 ;
V_3 -> V_25 = V_38 ;
V_1 = (* F_3)( 0 , V_3 ) ;
if ( ! V_1 ) goto V_19;
}
if ( V_10 < 0 )
{
V_3 -> error = V_48 ;
V_3 -> V_25 = V_38 ;
V_1 = (* F_3)( 0 , V_3 ) ;
if ( ! V_1 ) goto V_19;
}
V_3 -> V_25 = V_38 ;
V_1 = (* F_3)( 1 , V_3 ) ;
if ( ! V_1 ) goto V_19;
V_37 -- ;
if ( V_37 >= 0 )
{
V_39 = V_38 ;
V_38 = F_11 ( V_3 -> V_17 , V_37 ) ;
}
}
V_1 = 1 ;
V_19:
return ( V_1 ) ;
}
int F_27 ( T_6 * V_49 )
{
char * V_50 ;
T_6 V_51 ;
T_7 V_52 ;
char V_53 [ 24 ] , V_54 [ 24 ] , * V_55 ;
int V_10 , V_56 ;
V_55 = V_53 ;
V_10 = V_49 -> V_57 ;
V_50 = ( char * ) V_49 -> V_31 ;
if ( ( V_10 < 11 ) || ( V_10 > 17 ) ) return ( 0 ) ;
memcpy ( V_55 , V_50 , 10 ) ;
V_55 += 10 ;
V_50 += 10 ;
if ( ( * V_50 == 'Z' ) || ( * V_50 == '-' ) || ( * V_50 == '+' ) )
{ * ( V_55 ++ ) = '0' ; * ( V_55 ++ ) = '0' ; }
else { * ( V_55 ++ ) = * ( V_50 ++ ) ; * ( V_55 ++ ) = * ( V_50 ++ ) ; }
* ( V_55 ++ ) = 'Z' ;
* ( V_55 ++ ) = '\0' ;
if ( * V_50 == 'Z' )
V_52 = 0 ;
else
{
if ( ( * V_50 != '+' ) && ( V_50 [ 5 ] != '-' ) )
return ( 0 ) ;
V_52 = ( ( V_50 [ 1 ] - '0' ) * 10 + ( V_50 [ 2 ] - '0' ) ) * 60 ;
V_52 += ( V_50 [ 3 ] - '0' ) * 10 + ( V_50 [ 4 ] - '0' ) ;
if ( * V_50 == '-' )
V_52 = - V_52 ;
}
V_51 . type = V_58 ;
V_51 . V_57 = sizeof( V_54 ) ;
V_51 . V_31 = ( unsigned char * ) V_54 ;
F_30 ( & V_51 , - V_52 ) ;
V_10 = ( V_53 [ 0 ] - '0' ) * 10 + ( V_53 [ 1 ] - '0' ) ;
if ( V_10 < 50 ) V_10 += 100 ;
V_56 = ( V_54 [ 0 ] - '0' ) * 10 + ( V_54 [ 1 ] - '0' ) ;
if ( V_56 < 50 ) V_56 += 100 ;
if ( V_10 < V_56 ) return ( - 1 ) ;
if ( V_10 > V_56 ) return ( 1 ) ;
V_10 = strcmp ( V_53 , V_54 ) ;
if ( V_10 == 0 )
return ( - 1 ) ;
else
return ( V_10 ) ;
}
T_6 * F_30 ( T_6 * V_59 , long V_60 )
{
T_7 V_61 ;
time ( & V_61 ) ;
V_61 += V_60 ;
return ( F_31 ( V_59 , V_61 ) ) ;
}
int F_32 ( T_8 * V_3 , T_2 * V_4 )
{
T_4 * V_8 , * V_62 ;
int V_63 = 1 ;
if ( V_4 == NULL ) return ( 0 ) ;
V_8 = ( T_4 * ) Malloc ( sizeof( T_4 ) ) ;
if ( V_8 == NULL )
{
F_5 ( V_64 , V_18 ) ;
return ( 0 ) ;
}
V_8 -> type = V_27 ;
V_8 -> V_31 . V_32 = V_4 ;
F_33 ( V_65 ) ;
F_34 ( V_8 ) ;
V_62 = ( T_4 * ) F_35 ( V_3 -> V_66 , ( char * ) V_8 ) ;
if ( V_62 != NULL )
{
F_36 ( V_3 -> V_66 , ( char * ) V_8 ) ;
F_19 ( V_8 ) ;
Free ( V_8 ) ;
F_35 ( V_3 -> V_66 , ( char * ) V_62 ) ;
F_5 ( V_64 , V_67 ) ;
V_63 = 0 ;
}
F_37 ( V_65 ) ;
return ( V_63 ) ;
}
int F_38 ( T_8 * V_3 , T_9 * V_4 )
{
T_4 * V_8 , * V_62 ;
int V_63 = 1 ;
if ( V_4 == NULL ) return ( 0 ) ;
V_8 = ( T_4 * ) Malloc ( sizeof( T_4 ) ) ;
if ( V_8 == NULL )
{
F_5 ( V_68 , V_18 ) ;
return ( 0 ) ;
}
V_8 -> type = V_69 ;
V_8 -> V_31 . V_70 = V_4 ;
F_33 ( V_65 ) ;
F_34 ( V_8 ) ;
V_62 = ( T_4 * ) F_35 ( V_3 -> V_66 , ( char * ) V_8 ) ;
if ( V_62 != NULL )
{
F_36 ( V_3 -> V_66 , ( char * ) V_8 ) ;
F_19 ( V_8 ) ;
Free ( V_8 ) ;
F_35 ( V_3 -> V_66 , ( char * ) V_62 ) ;
F_5 ( V_68 , V_67 ) ;
V_63 = 0 ;
}
F_37 ( V_65 ) ;
return ( V_63 ) ;
}
int F_39 ( long V_71 , char * V_72 , int (* F_40)() ,
int (* F_41)() , void (* F_42)() )
{
V_73 ++ ;
return ( F_43 ( V_73 - 1 ,
& V_74 ,
V_71 , V_72 , F_40 , F_41 , F_42 ) ) ;
}
int F_44 ( T_1 * V_3 , int V_75 , void * V_31 )
{
return ( F_45 ( & V_3 -> V_76 , V_75 , V_31 ) ) ;
}
void * F_46 ( T_1 * V_3 , int V_75 )
{
return ( F_47 ( & V_3 -> V_76 , V_75 ) ) ;
}
int F_48 ( T_1 * V_3 )
{
return ( V_3 -> error ) ;
}
void F_49 ( T_1 * V_3 , int V_77 )
{
V_3 -> error = V_77 ;
}
int F_50 ( T_1 * V_3 )
{
return ( V_3 -> V_26 ) ;
}
T_2 * F_51 ( T_1 * V_3 )
{
return ( V_3 -> V_25 ) ;
}
void F_52 ( T_1 * V_3 , T_2 * V_4 )
{
V_3 -> V_13 = V_4 ;
}
