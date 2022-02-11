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
V_1 = V_3 -> V_33 ( V_3 ) ;
if( ! V_1 ) goto V_18;
if ( V_3 -> V_34 != NULL )
V_1 = V_3 -> V_34 ( V_3 ) ;
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
static int V_23 ( T_1 * V_3 , T_2 * V_4 , T_2 * V_35 )
{
int V_36 ;
V_36 = F_25 ( V_35 , V_4 ) ;
if ( V_36 == V_37 )
return 1 ;
if ( ! ( V_3 -> V_38 & V_39 ) )
return 0 ;
V_3 -> error = V_36 ;
V_3 -> V_26 = V_4 ;
V_3 -> V_40 = V_35 ;
return V_3 -> V_15 ( 0 , V_3 ) ;
return 0 ;
}
static int F_26 ( T_2 * * V_35 , T_1 * V_3 , T_2 * V_4 )
{
* V_35 = F_13 ( V_3 , V_3 -> V_41 , V_4 ) ;
if ( * V_35 )
{
F_8 ( & ( * V_35 ) -> V_19 , 1 , V_20 ) ;
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
for ( V_9 = 0 ; V_9 < V_3 -> V_21 ; V_9 ++ )
{
V_4 = F_11 ( V_3 -> V_16 , V_9 ) ;
if ( ! ( V_3 -> V_38 & V_42 )
&& ( V_4 -> V_43 & V_44 ) )
{
V_3 -> error = V_45 ;
V_3 -> V_27 = V_9 ;
V_3 -> V_26 = V_4 ;
V_1 = F_3 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_18;
}
if ( ! F_28 ( V_4 , V_3 -> V_31 , V_9 ) )
{
if ( V_9 )
V_3 -> error = V_46 ;
else
V_3 -> error = V_47 ;
V_3 -> V_27 = V_9 ;
V_3 -> V_26 = V_4 ;
V_1 = F_3 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_18;
}
if ( ( V_9 > 1 ) && ( V_4 -> V_48 != - 1 )
&& ( V_9 > ( V_4 -> V_48 + 1 ) ) )
{
V_3 -> error = V_49 ;
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
V_9 = F_10 ( V_3 -> V_16 ) - 1 ;
V_4 = F_11 ( V_3 -> V_16 , V_9 ) ;
V_1 = F_29 ( V_4 , V_3 -> V_32 , 0 ) ;
if ( V_1 == V_50 )
return 1 ;
V_3 -> V_27 = V_9 ;
V_3 -> V_26 = V_4 ;
if ( V_1 == V_51 )
V_3 -> error = V_52 ;
else
V_3 -> error = V_53 ;
V_1 = F_3 ( 0 , V_3 ) ;
return V_1 ;
#endif
}
static int V_33 ( T_1 * V_3 )
{
int V_9 , V_54 , V_1 ;
if ( ! ( V_3 -> V_38 & V_55 ) )
return 1 ;
if ( V_3 -> V_38 & V_56 )
V_54 = 0 ;
else
V_54 = F_10 ( V_3 -> V_16 ) - 1 ;
for( V_9 = 0 ; V_9 <= V_54 ; V_9 ++ )
{
V_3 -> V_27 = V_9 ;
V_1 = F_30 ( V_3 ) ;
if ( ! V_1 ) return V_1 ;
}
return 1 ;
}
static int F_30 ( T_1 * V_3 )
{
T_4 * V_57 = NULL ;
T_2 * V_4 ;
int V_1 , V_58 ;
V_58 = V_3 -> V_27 ;
V_4 = F_11 ( V_3 -> V_16 , V_58 ) ;
V_3 -> V_26 = V_4 ;
V_1 = V_3 -> V_59 ( V_3 , & V_57 , V_4 ) ;
if( ! V_1 )
{
V_3 -> error = V_60 ;
V_1 = V_3 -> V_15 ( 0 , V_3 ) ;
goto V_61;
}
V_3 -> V_62 = V_57 ;
V_1 = V_3 -> V_63 ( V_3 , V_57 ) ;
if ( ! V_1 ) goto V_61;
V_1 = V_3 -> V_64 ( V_3 , V_57 , V_4 ) ;
V_61:
V_3 -> V_62 = NULL ;
F_31 ( V_57 ) ;
return V_1 ;
}
static int V_59 ( T_1 * V_3 , T_4 * * V_57 , T_2 * V_4 )
{
int V_1 ;
T_5 V_65 ;
V_1 = F_32 ( V_3 , V_66 , F_12 ( V_4 ) , & V_65 ) ;
if ( ! V_1 ) return 0 ;
* V_57 = V_65 . V_67 . V_57 ;
return 1 ;
}
static int V_63 ( T_1 * V_3 , T_4 * V_57 )
{
T_2 * V_35 = NULL ;
T_6 * V_68 = NULL ;
int V_1 = 0 , V_69 , V_58 , V_9 ;
T_7 * V_70 ;
V_58 = V_3 -> V_27 ;
V_69 = F_10 ( V_3 -> V_16 ) - 1 ;
if( V_58 < V_69 )
V_35 = F_11 ( V_3 -> V_16 , V_58 + 1 ) ;
else
{
V_35 = F_11 ( V_3 -> V_16 , V_69 ) ;
if( ! V_3 -> V_23 ( V_3 , V_35 , V_35 ) )
{
V_3 -> error = V_71 ;
V_1 = V_3 -> V_15 ( 0 , V_3 ) ;
if( ! V_1 ) goto V_61;
}
}
if( V_35 )
{
V_68 = F_33 ( V_35 ) ;
if( ! V_68 )
{
V_3 -> error = V_72 ;
V_1 = V_3 -> V_15 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_61;
}
else
{
if( F_34 ( V_57 , V_68 ) <= 0 )
{
V_3 -> error = V_73 ;
V_1 = V_3 -> V_15 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_61;
}
}
}
if ( V_3 -> V_38 & V_74 )
V_70 = & V_3 -> V_75 ;
else
V_70 = NULL ;
V_9 = F_35 ( F_36 ( V_57 ) , V_70 ) ;
if ( V_9 == 0 )
{
V_3 -> error = V_76 ;
V_1 = V_3 -> V_15 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_61;
}
if ( V_9 > 0 )
{
V_3 -> error = V_77 ;
V_1 = V_3 -> V_15 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_61;
}
if( F_37 ( V_57 ) )
{
V_9 = F_35 ( F_37 ( V_57 ) , V_70 ) ;
if ( V_9 == 0 )
{
V_3 -> error = V_78 ;
V_1 = V_3 -> V_15 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_61;
}
if ( V_9 < 0 )
{
V_3 -> error = V_79 ;
V_1 = V_3 -> V_15 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_61;
}
}
V_1 = 1 ;
V_61:
F_38 ( V_68 ) ;
return V_1 ;
}
static int V_64 ( T_1 * V_3 , T_4 * V_57 , T_2 * V_4 )
{
int V_80 , V_1 ;
T_8 V_81 ;
V_81 . V_82 = F_39 ( V_4 ) ;
V_80 = F_40 ( V_57 -> V_57 -> V_83 , & V_81 ) ;
if( V_80 == - 1 ) return 1 ;
V_3 -> error = V_84 ;
V_1 = V_3 -> V_15 ( 0 , V_3 ) ;
return V_1 ;
}
static int F_23 ( T_1 * V_3 )
{
int V_9 , V_1 = 0 , V_85 ;
T_2 * V_86 , * V_87 ;
T_6 * V_88 = NULL ;
T_7 * V_70 ;
int (* F_3)();
F_3 = V_3 -> V_15 ;
V_85 = F_10 ( V_3 -> V_16 ) ;
V_3 -> V_27 = V_85 - 1 ;
V_85 -- ;
V_87 = F_11 ( V_3 -> V_16 , V_85 ) ;
if ( V_3 -> V_38 & V_74 )
V_70 = & V_3 -> V_75 ;
else
V_70 = NULL ;
if ( V_3 -> V_23 ( V_3 , V_87 , V_87 ) )
V_86 = V_87 ;
else
{
if ( V_85 <= 0 )
{
V_3 -> error = V_89 ;
V_3 -> V_26 = V_87 ;
V_1 = F_3 ( 0 , V_3 ) ;
goto V_18;
}
else
{
V_85 -- ;
V_3 -> V_27 = V_85 ;
V_86 = F_11 ( V_3 -> V_16 , V_85 ) ;
}
}
while ( V_85 >= 0 )
{
V_3 -> V_27 = V_85 ;
if ( ! V_86 -> V_90 )
{
if ( ( V_88 = F_33 ( V_87 ) ) == NULL )
{
V_3 -> error = V_72 ;
V_3 -> V_26 = V_87 ;
V_1 = (* F_3)( 0 , V_3 ) ;
if ( ! V_1 ) goto V_18;
}
if ( F_41 ( V_86 , V_88 ) <= 0 )
{
V_3 -> error = V_91 ;
V_3 -> V_26 = V_86 ;
V_1 = (* F_3)( 0 , V_3 ) ;
if ( ! V_1 )
{
F_38 ( V_88 ) ;
goto V_18;
}
}
F_38 ( V_88 ) ;
V_88 = NULL ;
V_9 = F_35 ( F_42 ( V_86 ) , V_70 ) ;
if ( V_9 == 0 )
{
V_3 -> error = V_92 ;
V_3 -> V_26 = V_86 ;
V_1 = (* F_3)( 0 , V_3 ) ;
if ( ! V_1 ) goto V_18;
}
if ( V_9 > 0 )
{
V_3 -> error = V_93 ;
V_3 -> V_26 = V_86 ;
V_1 = (* F_3)( 0 , V_3 ) ;
if ( ! V_1 ) goto V_18;
}
V_86 -> V_90 = 1 ;
}
V_9 = F_35 ( F_43 ( V_86 ) , V_70 ) ;
if ( V_9 == 0 )
{
V_3 -> error = V_94 ;
V_3 -> V_26 = V_86 ;
V_1 = (* F_3)( 0 , V_3 ) ;
if ( ! V_1 ) goto V_18;
}
if ( V_9 < 0 )
{
V_3 -> error = V_95 ;
V_3 -> V_26 = V_86 ;
V_1 = (* F_3)( 0 , V_3 ) ;
if ( ! V_1 ) goto V_18;
}
V_3 -> V_26 = V_86 ;
V_1 = (* F_3)( 1 , V_3 ) ;
if ( ! V_1 ) goto V_18;
V_85 -- ;
if ( V_85 >= 0 )
{
V_87 = V_86 ;
V_86 = F_11 ( V_3 -> V_16 , V_85 ) ;
}
}
V_1 = 1 ;
V_18:
return V_1 ;
}
int F_44 ( T_9 * V_96 )
{
return F_35 ( V_96 , NULL ) ;
}
int F_35 ( T_9 * V_96 , T_7 * V_97 )
{
char * V_98 ;
T_9 V_99 ;
long V_100 ;
char V_101 [ 24 ] , V_102 [ 24 ] , * V_103 ;
int V_9 , V_104 ;
V_103 = V_101 ;
V_9 = V_96 -> V_105 ;
V_98 = ( char * ) V_96 -> V_67 ;
if ( V_96 -> type == V_106 )
{
if ( ( V_9 < 11 ) || ( V_9 > 17 ) ) return 0 ;
memcpy ( V_103 , V_98 , 10 ) ;
V_103 += 10 ;
V_98 += 10 ;
}
else
{
if ( V_9 < 13 ) return 0 ;
memcpy ( V_103 , V_98 , 12 ) ;
V_103 += 12 ;
V_98 += 12 ;
}
if ( ( * V_98 == 'Z' ) || ( * V_98 == '-' ) || ( * V_98 == '+' ) )
{ * ( V_103 ++ ) = '0' ; * ( V_103 ++ ) = '0' ; }
else
{
* ( V_103 ++ ) = * ( V_98 ++ ) ;
* ( V_103 ++ ) = * ( V_98 ++ ) ;
if ( * V_98 == '.' )
{
V_98 ++ ;
while ( ( * V_98 >= '0' ) && ( * V_98 <= '9' ) ) V_98 ++ ;
}
}
* ( V_103 ++ ) = 'Z' ;
* ( V_103 ++ ) = '\0' ;
if ( * V_98 == 'Z' )
V_100 = 0 ;
else
{
if ( ( * V_98 != '+' ) && ( V_98 [ 5 ] != '-' ) )
return 0 ;
V_100 = ( ( V_98 [ 1 ] - '0' ) * 10 + ( V_98 [ 2 ] - '0' ) ) * 60 ;
V_100 += ( V_98 [ 3 ] - '0' ) * 10 + ( V_98 [ 4 ] - '0' ) ;
if ( * V_98 == '-' )
V_100 = - V_100 ;
}
V_99 . type = V_96 -> type ;
V_99 . V_105 = sizeof( V_102 ) ;
V_99 . V_67 = ( unsigned char * ) V_102 ;
F_45 ( & V_99 , - V_100 * 60 , V_97 ) ;
if ( V_96 -> type == V_106 )
{
V_9 = ( V_101 [ 0 ] - '0' ) * 10 + ( V_101 [ 1 ] - '0' ) ;
if ( V_9 < 50 ) V_9 += 100 ;
V_104 = ( V_102 [ 0 ] - '0' ) * 10 + ( V_102 [ 1 ] - '0' ) ;
if ( V_104 < 50 ) V_104 += 100 ;
if ( V_9 < V_104 ) return - 1 ;
if ( V_9 > V_104 ) return 1 ;
}
V_9 = strcmp ( V_101 , V_102 ) ;
if ( V_9 == 0 )
return - 1 ;
else
return V_9 ;
}
T_9 * F_46 ( T_9 * V_107 , long V_108 )
{
return F_45 ( V_107 , V_108 , NULL ) ;
}
T_9 * F_45 ( T_9 * V_107 , long V_108 , T_7 * V_109 )
{
T_7 V_110 ;
int type = - 1 ;
if ( V_109 ) V_110 = * V_109 ;
else time ( & V_110 ) ;
V_110 += V_108 ;
if ( V_107 ) type = V_107 -> type ;
if ( type == V_106 ) return F_47 ( V_107 , V_110 ) ;
if ( type == V_111 ) return F_48 ( V_107 , V_110 ) ;
return F_49 ( V_107 , V_110 ) ;
}
int F_50 ( long V_112 , void * V_113 , T_10 * V_114 ,
T_11 * V_115 , T_12 * V_116 )
{
return F_51 ( V_117 , V_112 , V_113 ,
V_114 , V_115 , V_116 ) ;
}
int F_52 ( T_1 * V_3 , int V_80 , void * V_67 )
{
return F_53 ( & V_3 -> V_118 , V_80 , V_67 ) ;
}
void * F_54 ( T_1 * V_3 , int V_80 )
{
return F_55 ( & V_3 -> V_118 , V_80 ) ;
}
int F_56 ( T_1 * V_3 )
{
return V_3 -> error ;
}
void F_57 ( T_1 * V_3 , int V_61 )
{
V_3 -> error = V_61 ;
}
int F_58 ( T_1 * V_3 )
{
return V_3 -> V_27 ;
}
T_2 * F_59 ( T_1 * V_3 )
{
return V_3 -> V_26 ;
}
int F_60 ( T_1 * V_3 , int V_31 )
{
return F_61 ( V_3 , 0 , V_31 , 0 ) ;
}
int F_62 ( T_1 * V_3 , int V_32 )
{
return F_61 ( V_3 , 0 , 0 , V_32 ) ;
}
int F_61 ( T_1 * V_3 , int V_119 ,
int V_31 , int V_32 )
{
int V_80 ;
if ( ! V_31 ) V_31 = V_119 ;
if ( V_31 )
{
T_13 * V_120 ;
V_80 = F_63 ( V_31 ) ;
if ( V_80 == - 1 )
{
F_5 ( V_121 ,
V_122 ) ;
return 0 ;
}
V_120 = F_64 ( V_80 ) ;
if ( V_120 -> V_32 == V_123 )
{
V_80 = F_63 ( V_119 ) ;
if ( V_80 == - 1 )
{
F_5 ( V_121 ,
V_122 ) ;
return 0 ;
}
V_120 = F_64 ( V_80 ) ;
}
if ( ! V_32 ) V_32 = V_120 -> V_32 ;
}
if ( V_32 )
{
V_80 = F_65 ( V_32 ) ;
if ( V_80 == - 1 )
{
F_5 ( V_121 ,
V_124 ) ;
return 0 ;
}
}
if ( V_31 && ! V_3 -> V_31 ) V_3 -> V_31 = V_31 ;
if ( V_32 && ! V_3 -> V_32 ) V_3 -> V_32 = V_32 ;
return 1 ;
}
T_1 * F_66 ( void )
{
T_1 * V_3 ;
V_3 = ( T_1 * ) F_67 ( sizeof( T_1 ) ) ;
if ( ! V_3 )
{
F_5 ( V_125 , V_17 ) ;
return NULL ;
}
memset ( V_3 , 0 , sizeof( T_1 ) ) ;
return V_3 ;
}
void F_68 ( T_1 * V_3 )
{
F_69 ( V_3 ) ;
F_70 ( V_3 ) ;
}
void F_69 ( T_1 * V_3 )
{
if ( V_3 -> V_126 ) V_3 -> V_126 ( V_3 ) ;
if ( V_3 -> V_16 != NULL )
{
F_71 ( V_3 -> V_16 , F_17 ) ;
V_3 -> V_16 = NULL ;
}
F_72 ( V_117 , V_3 , & ( V_3 -> V_118 ) ) ;
memset ( & V_3 -> V_118 , 0 , sizeof( V_127 ) ) ;
}
void F_73 ( T_1 * V_3 , long V_38 )
{
V_3 -> V_38 |= V_38 ;
}
void F_74 ( T_1 * V_3 , long V_38 , T_7 V_110 )
{
V_3 -> V_75 = V_110 ;
V_3 -> V_38 |= V_74 ;
}
void F_75 ( T_1 * V_3 ,
int (* V_15)( int , T_1 * ) )
{
V_3 -> V_15 = V_15 ;
}
