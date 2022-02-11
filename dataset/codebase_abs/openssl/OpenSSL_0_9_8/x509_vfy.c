static int F_1 ( int V_1 , T_1 * V_2 )
{
return V_1 ;
}
int F_2 ( T_1 * V_3 )
{
T_2 * V_4 , * V_5 , * V_6 = NULL ;
T_3 * V_7 ;
int V_8 = 0 ;
T_4 * V_9 = V_3 -> V_9 ;
int V_10 , V_11 , V_1 = 0 ;
int V_12 ;
int (* F_3)( int V_13 , T_1 * V_14 );
F_4 ( T_2 ) * V_15 = NULL ;
if ( V_3 -> V_16 == NULL )
{
F_5 ( V_17 , V_18 ) ;
return - 1 ;
}
F_3 = V_3 -> V_19 ;
if ( V_3 -> V_20 == NULL )
{
if ( ( ( V_3 -> V_20 = F_6 () ) == NULL ) ||
( ! F_7 ( V_3 -> V_20 , V_3 -> V_16 ) ) )
{
F_5 ( V_17 , V_21 ) ;
goto V_22;
}
F_8 ( & V_3 -> V_16 -> V_23 , 1 , V_24 ) ;
V_3 -> V_25 = 1 ;
}
if ( V_3 -> V_26 != NULL
&& ( V_15 = F_9 ( V_3 -> V_26 ) ) == NULL )
{
F_5 ( V_17 , V_21 ) ;
goto V_22;
}
V_12 = F_10 ( V_3 -> V_20 ) ;
V_4 = F_11 ( V_3 -> V_20 , V_12 - 1 ) ;
V_10 = V_9 -> V_10 ;
for (; ; )
{
if ( V_10 < V_12 ) break;
V_7 = F_12 ( V_4 ) ;
if ( V_3 -> V_27 ( V_3 , V_4 , V_4 ) ) break;
if ( V_3 -> V_26 != NULL )
{
V_5 = F_13 ( V_3 , V_15 , V_4 ) ;
if ( V_5 != NULL )
{
if ( ! F_7 ( V_3 -> V_20 , V_5 ) )
{
F_5 ( V_17 , V_21 ) ;
goto V_22;
}
F_8 ( & V_5 -> V_23 , 1 , V_24 ) ;
F_14 ( V_15 , V_5 ) ;
V_3 -> V_25 ++ ;
V_4 = V_5 ;
V_12 ++ ;
continue;
}
}
break;
}
V_11 = F_10 ( V_3 -> V_20 ) ;
V_4 = F_11 ( V_3 -> V_20 , V_11 - 1 ) ;
V_7 = F_15 ( V_4 ) ;
if ( V_3 -> V_27 ( V_3 , V_4 , V_4 ) )
{
if ( F_10 ( V_3 -> V_20 ) == 1 )
{
V_1 = V_3 -> V_28 ( & V_5 , V_3 , V_4 ) ;
if ( ( V_1 <= 0 ) || F_16 ( V_4 , V_5 ) )
{
V_3 -> error = V_29 ;
V_3 -> V_30 = V_4 ;
V_3 -> V_31 = V_11 - 1 ;
if ( V_1 == 1 ) F_17 ( V_5 ) ;
V_8 = 1 ;
V_1 = F_3 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_22;
}
else
{
F_17 ( V_4 ) ;
V_4 = V_5 ;
F_18 ( V_3 -> V_20 , V_11 - 1 , V_4 ) ;
V_3 -> V_25 = 0 ;
}
}
else
{
V_6 = F_19 ( V_3 -> V_20 ) ;
V_3 -> V_25 -- ;
V_12 -- ;
V_4 = F_11 ( V_3 -> V_20 , V_12 - 1 ) ;
}
}
for (; ; )
{
if ( V_10 < V_12 ) break;
V_7 = F_12 ( V_4 ) ;
if ( V_3 -> V_27 ( V_3 , V_4 , V_4 ) ) break;
V_1 = V_3 -> V_28 ( & V_5 , V_3 , V_4 ) ;
if ( V_1 < 0 ) return V_1 ;
if ( V_1 == 0 ) break;
V_4 = V_5 ;
if ( ! F_7 ( V_3 -> V_20 , V_4 ) )
{
F_17 ( V_5 ) ;
F_5 ( V_17 , V_21 ) ;
return 0 ;
}
V_12 ++ ;
}
V_7 = F_12 ( V_4 ) ;
if ( ! V_3 -> V_27 ( V_3 , V_4 , V_4 ) )
{
if ( ( V_6 == NULL ) || ! V_3 -> V_27 ( V_3 , V_4 , V_6 ) )
{
if ( V_3 -> V_25 >= V_12 )
V_3 -> error = V_32 ;
else
V_3 -> error = V_33 ;
V_3 -> V_30 = V_4 ;
}
else
{
F_7 ( V_3 -> V_20 , V_6 ) ;
V_12 ++ ;
V_3 -> V_25 = V_12 ;
V_3 -> V_30 = V_6 ;
V_3 -> error = V_34 ;
V_6 = NULL ;
}
V_3 -> V_31 = V_12 - 1 ;
V_8 = 1 ;
V_1 = F_3 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_22;
}
V_1 = F_20 ( V_3 ) ;
if ( ! V_1 ) goto V_22;
if ( V_9 -> V_35 > 0 ) V_1 = F_21 ( V_3 ) ;
if ( ! V_1 ) goto V_22;
F_22 ( NULL , V_3 -> V_20 ) ;
V_1 = V_3 -> V_36 ( V_3 ) ;
if( ! V_1 ) goto V_22;
if ( V_3 -> V_37 != NULL )
V_1 = V_3 -> V_37 ( V_3 ) ;
else
V_1 = F_23 ( V_3 ) ;
if( ! V_1 ) goto V_22;
if ( ! V_8 && ( V_3 -> V_9 -> V_38 & V_39 ) )
V_1 = V_3 -> V_40 ( V_3 ) ;
if( ! V_1 ) goto V_22;
if ( 0 )
{
V_22:
F_22 ( NULL , V_3 -> V_20 ) ;
}
if ( V_15 != NULL ) F_24 ( V_15 ) ;
if ( V_6 != NULL ) F_17 ( V_6 ) ;
return V_1 ;
}
static int V_27 ( T_1 * V_3 , T_2 * V_4 , T_2 * V_41 )
{
int V_42 ;
V_42 = F_25 ( V_41 , V_4 ) ;
if ( V_42 == V_43 )
return 1 ;
if ( ! ( V_3 -> V_9 -> V_38 & V_44 ) )
return 0 ;
V_3 -> error = V_42 ;
V_3 -> V_30 = V_4 ;
V_3 -> V_45 = V_41 ;
return V_3 -> V_19 ( 0 , V_3 ) ;
return 0 ;
}
static int F_26 ( T_2 * * V_41 , T_1 * V_3 , T_2 * V_4 )
{
* V_41 = F_13 ( V_3 , V_3 -> V_46 , V_4 ) ;
if ( * V_41 )
{
F_8 ( & ( * V_41 ) -> V_23 , 1 , V_24 ) ;
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
int V_11 , V_1 = 0 , V_47 ;
T_2 * V_4 ;
int (* F_3)( int V_13 , T_1 * V_14 );
int V_48 = 0 ;
int V_49 =
! ! ( V_3 -> V_9 -> V_38 & V_50 ) ;
F_3 = V_3 -> V_19 ;
V_47 = - 1 ;
if ( getenv ( L_1 ) )
V_49 = 1 ;
for ( V_11 = 0 ; V_11 < V_3 -> V_25 ; V_11 ++ )
{
int V_42 ;
V_4 = F_11 ( V_3 -> V_20 , V_11 ) ;
if ( ! ( V_3 -> V_9 -> V_38 & V_51 )
&& ( V_4 -> V_52 & V_53 ) )
{
V_3 -> error = V_54 ;
V_3 -> V_31 = V_11 ;
V_3 -> V_30 = V_4 ;
V_1 = F_3 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_22;
}
if ( ! V_49 && ( V_4 -> V_52 & V_55 ) )
{
V_3 -> error = V_56 ;
V_3 -> V_31 = V_11 ;
V_3 -> V_30 = V_4 ;
V_1 = F_3 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_22;
}
V_42 = F_28 ( V_4 ) ;
switch( V_47 )
{
case - 1 :
if ( ( V_3 -> V_9 -> V_38 & V_57 )
&& ( V_42 != 1 ) && ( V_42 != 0 ) )
{
V_42 = 0 ;
V_3 -> error = V_58 ;
}
else
V_42 = 1 ;
break;
case 0 :
if ( V_42 != 0 )
{
V_42 = 0 ;
V_3 -> error = V_59 ;
}
else
V_42 = 1 ;
break;
default:
if ( ( V_42 == 0 )
|| ( ( V_3 -> V_9 -> V_38 & V_57 )
&& ( V_42 != 1 ) ) )
{
V_42 = 0 ;
V_3 -> error = V_58 ;
}
else
V_42 = 1 ;
break;
}
if ( V_42 == 0 )
{
V_3 -> V_31 = V_11 ;
V_3 -> V_30 = V_4 ;
V_1 = F_3 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_22;
}
if ( V_3 -> V_9 -> V_60 > 0 )
{
V_42 = F_29 ( V_4 , V_3 -> V_9 -> V_60 ,
V_47 > 0 ) ;
if ( ( V_42 == 0 )
|| ( ( V_3 -> V_9 -> V_38 & V_57 )
&& ( V_42 != 1 ) ) )
{
V_3 -> error = V_61 ;
V_3 -> V_31 = V_11 ;
V_3 -> V_30 = V_4 ;
V_1 = F_3 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_22;
}
}
if ( ( V_11 > 1 ) && ( V_4 -> V_62 != - 1 )
&& ( V_11 > ( V_4 -> V_62 + V_48 + 1 ) ) )
{
V_3 -> error = V_63 ;
V_3 -> V_31 = V_11 ;
V_3 -> V_30 = V_4 ;
V_1 = F_3 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_22;
}
if ( V_4 -> V_52 & V_55 )
{
if ( V_4 -> V_64 != - 1 && V_11 > V_4 -> V_64 )
{
V_3 -> error =
V_65 ;
V_3 -> V_31 = V_11 ;
V_3 -> V_30 = V_4 ;
V_1 = F_3 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_22;
}
V_48 ++ ;
V_47 = 0 ;
}
else
V_47 = 1 ;
}
V_1 = 1 ;
V_22:
return V_1 ;
#endif
}
static int F_21 ( T_1 * V_3 )
{
#ifdef F_27
return 1 ;
#else
int V_11 , V_1 ;
T_2 * V_4 ;
int (* F_3)( int V_13 , T_1 * V_14 );
F_3 = V_3 -> V_19 ;
V_11 = F_10 ( V_3 -> V_20 ) - 1 ;
V_4 = F_11 ( V_3 -> V_20 , V_11 ) ;
V_1 = F_30 ( V_4 , V_3 -> V_9 -> V_35 , 0 ) ;
if ( V_1 == V_66 )
return 1 ;
V_3 -> V_31 = V_11 ;
V_3 -> V_30 = V_4 ;
if ( V_1 == V_67 )
V_3 -> error = V_68 ;
else
V_3 -> error = V_69 ;
V_1 = F_3 ( 0 , V_3 ) ;
return V_1 ;
#endif
}
static int V_36 ( T_1 * V_3 )
{
int V_11 , V_70 , V_1 ;
if ( ! ( V_3 -> V_9 -> V_38 & V_71 ) )
return 1 ;
if ( V_3 -> V_9 -> V_38 & V_72 )
V_70 = F_10 ( V_3 -> V_20 ) - 1 ;
else
V_70 = 0 ;
for( V_11 = 0 ; V_11 <= V_70 ; V_11 ++ )
{
V_3 -> V_31 = V_11 ;
V_1 = F_31 ( V_3 ) ;
if ( ! V_1 ) return V_1 ;
}
return 1 ;
}
static int F_31 ( T_1 * V_3 )
{
T_5 * V_73 = NULL ;
T_2 * V_4 ;
int V_1 , V_74 ;
V_74 = V_3 -> V_31 ;
V_4 = F_11 ( V_3 -> V_20 , V_74 ) ;
V_3 -> V_30 = V_4 ;
V_1 = V_3 -> V_75 ( V_3 , & V_73 , V_4 ) ;
if( ! V_1 )
{
V_3 -> error = V_76 ;
V_1 = V_3 -> V_19 ( 0 , V_3 ) ;
goto V_77;
}
V_3 -> V_78 = V_73 ;
V_1 = V_3 -> V_79 ( V_3 , V_73 ) ;
if ( ! V_1 ) goto V_77;
V_1 = V_3 -> V_80 ( V_3 , V_73 , V_4 ) ;
V_77:
V_3 -> V_78 = NULL ;
F_32 ( V_73 ) ;
return V_1 ;
}
static int F_33 ( T_1 * V_3 , T_5 * V_73 , int V_81 )
{
T_6 * V_82 ;
int V_11 ;
V_3 -> V_78 = V_73 ;
if ( V_3 -> V_9 -> V_38 & V_83 )
V_82 = & V_3 -> V_9 -> V_84 ;
else
V_82 = NULL ;
V_11 = F_34 ( F_35 ( V_73 ) , V_82 ) ;
if ( V_11 == 0 )
{
V_3 -> error = V_85 ;
if ( ! V_81 || ! V_3 -> V_19 ( 0 , V_3 ) )
return 0 ;
}
if ( V_11 > 0 )
{
V_3 -> error = V_86 ;
if ( ! V_81 || ! V_3 -> V_19 ( 0 , V_3 ) )
return 0 ;
}
if( F_36 ( V_73 ) )
{
V_11 = F_34 ( F_36 ( V_73 ) , V_82 ) ;
if ( V_11 == 0 )
{
V_3 -> error = V_87 ;
if ( ! V_81 || ! V_3 -> V_19 ( 0 , V_3 ) )
return 0 ;
}
if ( V_11 < 0 )
{
V_3 -> error = V_88 ;
if ( ! V_81 || ! V_3 -> V_19 ( 0 , V_3 ) )
return 0 ;
}
}
V_3 -> V_78 = NULL ;
return 1 ;
}
static int V_75 ( T_1 * V_3 , T_5 * * V_89 , T_2 * V_4 )
{
int V_1 ;
T_5 * V_73 = NULL ;
T_7 V_90 ;
T_3 * V_91 ;
V_91 = F_12 ( V_4 ) ;
V_1 = F_37 ( V_3 , & V_73 , V_91 , V_3 -> V_92 ) ;
if ( V_1 )
{
* V_89 = V_73 ;
return 1 ;
}
V_1 = F_38 ( V_3 , V_93 , V_91 , & V_90 ) ;
if ( ! V_1 )
{
if ( V_73 )
{
* V_89 = V_73 ;
return 1 ;
}
return 0 ;
}
* V_89 = V_90 . V_94 . V_73 ;
if ( V_73 )
F_32 ( V_73 ) ;
return 1 ;
}
static int V_79 ( T_1 * V_3 , T_5 * V_73 )
{
T_2 * V_41 = NULL ;
T_8 * V_95 = NULL ;
int V_1 = 0 , V_96 , V_74 ;
V_74 = V_3 -> V_31 ;
V_96 = F_10 ( V_3 -> V_20 ) - 1 ;
if( V_74 < V_96 )
V_41 = F_11 ( V_3 -> V_20 , V_74 + 1 ) ;
else
{
V_41 = F_11 ( V_3 -> V_20 , V_96 ) ;
if( ! V_3 -> V_27 ( V_3 , V_41 , V_41 ) )
{
V_3 -> error = V_97 ;
V_1 = V_3 -> V_19 ( 0 , V_3 ) ;
if( ! V_1 ) goto V_77;
}
}
if( V_41 )
{
if ( ( V_41 -> V_52 & V_98 ) &&
! ( V_41 -> V_99 & V_100 ) )
{
V_3 -> error = V_101 ;
V_1 = V_3 -> V_19 ( 0 , V_3 ) ;
if( ! V_1 ) goto V_77;
}
V_95 = F_39 ( V_41 ) ;
if( ! V_95 )
{
V_3 -> error = V_102 ;
V_1 = V_3 -> V_19 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_77;
}
else
{
if( F_40 ( V_73 , V_95 ) <= 0 )
{
V_3 -> error = V_103 ;
V_1 = V_3 -> V_19 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_77;
}
}
}
V_1 = F_33 ( V_3 , V_73 , 1 ) ;
if ( ! V_1 )
goto V_77;
V_1 = 1 ;
V_77:
F_41 ( V_95 ) ;
return V_1 ;
}
static int V_80 ( T_1 * V_3 , T_5 * V_73 , T_2 * V_4 )
{
int V_104 , V_1 ;
T_9 V_105 ;
F_4 ( V_106 ) * V_107 ;
V_106 * V_108 ;
V_105 . V_109 = F_42 ( V_4 ) ;
if ( ! F_43 ( V_73 -> V_73 -> V_110 ) )
{
F_44 ( V_111 ) ;
F_45 ( V_73 -> V_73 -> V_110 ) ;
F_46 ( V_111 ) ;
}
V_104 = F_47 ( V_73 -> V_73 -> V_110 , & V_105 ) ;
if( V_104 >= 0 )
{
V_3 -> error = V_112 ;
V_1 = V_3 -> V_19 ( 0 , V_3 ) ;
if ( ! V_1 ) return 0 ;
}
if ( V_3 -> V_9 -> V_38 & V_51 )
return 1 ;
V_107 = V_73 -> V_73 -> V_113 ;
for ( V_104 = 0 ; V_104 < F_48 ( V_107 ) ; V_104 ++ )
{
V_108 = F_49 ( V_107 , V_104 ) ;
if ( V_108 -> V_114 > 0 )
{
V_3 -> error =
V_115 ;
V_1 = V_3 -> V_19 ( 0 , V_3 ) ;
if( ! V_1 ) return 0 ;
break;
}
}
return 1 ;
}
static int V_40 ( T_1 * V_3 )
{
int V_42 ;
V_42 = F_50 ( & V_3 -> V_116 , & V_3 -> V_117 , V_3 -> V_20 ,
V_3 -> V_9 -> V_118 , V_3 -> V_9 -> V_38 ) ;
if ( V_42 == 0 )
{
F_5 ( V_119 , V_21 ) ;
return 0 ;
}
if ( V_42 == - 1 )
{
T_2 * V_4 ;
int V_11 ;
for ( V_11 = 1 ; V_11 < F_10 ( V_3 -> V_20 ) ; V_11 ++ )
{
V_4 = F_11 ( V_3 -> V_20 , V_11 ) ;
if ( ! ( V_4 -> V_52 & V_120 ) )
continue;
V_3 -> V_30 = V_4 ;
V_3 -> error = V_121 ;
V_42 = V_3 -> V_19 ( 0 , V_3 ) ;
}
return 1 ;
}
if ( V_42 == - 2 )
{
V_3 -> V_30 = NULL ;
V_3 -> error = V_122 ;
return V_3 -> V_19 ( 0 , V_3 ) ;
}
if ( V_3 -> V_9 -> V_38 & V_123 )
{
V_3 -> V_30 = NULL ;
V_3 -> error = V_43 ;
if ( ! V_3 -> V_19 ( 2 , V_3 ) )
return 0 ;
}
return 1 ;
}
static int F_51 ( T_1 * V_3 , T_2 * V_4 )
{
T_6 * V_82 ;
int V_11 ;
if ( V_3 -> V_9 -> V_38 & V_83 )
V_82 = & V_3 -> V_9 -> V_84 ;
else
V_82 = NULL ;
V_11 = F_34 ( F_52 ( V_4 ) , V_82 ) ;
if ( V_11 == 0 )
{
V_3 -> error = V_124 ;
V_3 -> V_30 = V_4 ;
if ( ! V_3 -> V_19 ( 0 , V_3 ) )
return 0 ;
}
if ( V_11 > 0 )
{
V_3 -> error = V_125 ;
V_3 -> V_30 = V_4 ;
if ( ! V_3 -> V_19 ( 0 , V_3 ) )
return 0 ;
}
V_11 = F_34 ( F_53 ( V_4 ) , V_82 ) ;
if ( V_11 == 0 )
{
V_3 -> error = V_126 ;
V_3 -> V_30 = V_4 ;
if ( ! V_3 -> V_19 ( 0 , V_3 ) )
return 0 ;
}
if ( V_11 < 0 )
{
V_3 -> error = V_127 ;
V_3 -> V_30 = V_4 ;
if ( ! V_3 -> V_19 ( 0 , V_3 ) )
return 0 ;
}
return 1 ;
}
static int F_23 ( T_1 * V_3 )
{
int V_1 = 0 , V_128 ;
T_2 * V_129 , * V_130 ;
T_8 * V_131 = NULL ;
int (* F_3)( int V_13 , T_1 * V_14 );
F_3 = V_3 -> V_19 ;
V_128 = F_10 ( V_3 -> V_20 ) ;
V_3 -> V_31 = V_128 - 1 ;
V_128 -- ;
V_130 = F_11 ( V_3 -> V_20 , V_128 ) ;
if ( V_3 -> V_27 ( V_3 , V_130 , V_130 ) )
V_129 = V_130 ;
else
{
if ( V_128 <= 0 )
{
V_3 -> error = V_132 ;
V_3 -> V_30 = V_130 ;
V_1 = F_3 ( 0 , V_3 ) ;
goto V_22;
}
else
{
V_128 -- ;
V_3 -> V_31 = V_128 ;
V_129 = F_11 ( V_3 -> V_20 , V_128 ) ;
}
}
while ( V_128 >= 0 )
{
V_3 -> V_31 = V_128 ;
if ( ! V_129 -> V_133 )
{
if ( ( V_131 = F_39 ( V_130 ) ) == NULL )
{
V_3 -> error = V_102 ;
V_3 -> V_30 = V_130 ;
V_1 = (* F_3)( 0 , V_3 ) ;
if ( ! V_1 ) goto V_22;
}
else if ( F_54 ( V_129 , V_131 ) <= 0 )
{
V_3 -> error = V_134 ;
V_3 -> V_30 = V_129 ;
V_1 = (* F_3)( 0 , V_3 ) ;
if ( ! V_1 )
{
F_41 ( V_131 ) ;
goto V_22;
}
}
F_41 ( V_131 ) ;
V_131 = NULL ;
}
V_129 -> V_133 = 1 ;
V_1 = F_51 ( V_3 , V_129 ) ;
if ( ! V_1 )
goto V_22;
V_3 -> V_45 = V_130 ;
V_3 -> V_30 = V_129 ;
V_1 = (* F_3)( 1 , V_3 ) ;
if ( ! V_1 ) goto V_22;
V_128 -- ;
if ( V_128 >= 0 )
{
V_130 = V_129 ;
V_129 = F_11 ( V_3 -> V_20 , V_128 ) ;
}
}
V_1 = 1 ;
V_22:
return V_1 ;
}
int F_55 ( T_10 * V_135 )
{
return F_34 ( V_135 , NULL ) ;
}
int F_34 ( T_10 * V_135 , T_6 * V_136 )
{
char * V_137 ;
T_10 V_138 ;
long V_139 ;
char V_140 [ 24 ] , V_141 [ 24 ] , * V_142 ;
int V_11 , V_143 ;
V_142 = V_140 ;
V_11 = V_135 -> V_144 ;
V_137 = ( char * ) V_135 -> V_94 ;
if ( V_135 -> type == V_145 )
{
if ( ( V_11 < 11 ) || ( V_11 > 17 ) ) return 0 ;
memcpy ( V_142 , V_137 , 10 ) ;
V_142 += 10 ;
V_137 += 10 ;
}
else
{
if ( V_11 < 13 ) return 0 ;
memcpy ( V_142 , V_137 , 12 ) ;
V_142 += 12 ;
V_137 += 12 ;
}
if ( ( * V_137 == 'Z' ) || ( * V_137 == '-' ) || ( * V_137 == '+' ) )
{ * ( V_142 ++ ) = '0' ; * ( V_142 ++ ) = '0' ; }
else
{
* ( V_142 ++ ) = * ( V_137 ++ ) ;
* ( V_142 ++ ) = * ( V_137 ++ ) ;
if ( * V_137 == '.' )
{
V_137 ++ ;
while ( ( * V_137 >= '0' ) && ( * V_137 <= '9' ) ) V_137 ++ ;
}
}
* ( V_142 ++ ) = 'Z' ;
* ( V_142 ++ ) = '\0' ;
if ( * V_137 == 'Z' )
V_139 = 0 ;
else
{
if ( ( * V_137 != '+' ) && ( * V_137 != '-' ) )
return 0 ;
V_139 = ( ( V_137 [ 1 ] - '0' ) * 10 + ( V_137 [ 2 ] - '0' ) ) * 60 ;
V_139 += ( V_137 [ 3 ] - '0' ) * 10 + ( V_137 [ 4 ] - '0' ) ;
if ( * V_137 == '-' )
V_139 = - V_139 ;
}
V_138 . type = V_135 -> type ;
V_138 . V_144 = sizeof( V_141 ) ;
V_138 . V_94 = ( unsigned char * ) V_141 ;
if ( F_56 ( & V_138 , - V_139 * 60 , V_136 ) == NULL )
return 0 ;
if ( V_135 -> type == V_145 )
{
V_11 = ( V_140 [ 0 ] - '0' ) * 10 + ( V_140 [ 1 ] - '0' ) ;
if ( V_11 < 50 ) V_11 += 100 ;
V_143 = ( V_141 [ 0 ] - '0' ) * 10 + ( V_141 [ 1 ] - '0' ) ;
if ( V_143 < 50 ) V_143 += 100 ;
if ( V_11 < V_143 ) return - 1 ;
if ( V_11 > V_143 ) return 1 ;
}
V_11 = strcmp ( V_140 , V_141 ) ;
if ( V_11 == 0 )
return - 1 ;
else
return V_11 ;
}
T_10 * F_57 ( T_10 * V_146 , long V_147 )
{
return F_56 ( V_146 , V_147 , NULL ) ;
}
T_10 * F_56 ( T_10 * V_146 , long V_147 , T_6 * V_148 )
{
T_6 V_149 ;
int type = - 1 ;
if ( V_148 ) V_149 = * V_148 ;
else time ( & V_149 ) ;
V_149 += V_147 ;
if ( V_146 ) type = V_146 -> type ;
if ( type == V_145 ) return F_58 ( V_146 , V_149 ) ;
if ( type == V_150 ) return F_59 ( V_146 , V_149 ) ;
return F_60 ( V_146 , V_149 ) ;
}
int F_61 ( long V_151 , void * V_152 , T_11 * V_153 ,
T_12 * V_154 , T_13 * V_155 )
{
return F_62 ( V_156 , V_151 , V_152 ,
V_153 , V_154 , V_155 ) ;
}
int F_63 ( T_1 * V_3 , int V_104 , void * V_94 )
{
return F_64 ( & V_3 -> V_157 , V_104 , V_94 ) ;
}
void * F_65 ( T_1 * V_3 , int V_104 )
{
return F_66 ( & V_3 -> V_157 , V_104 ) ;
}
int F_67 ( T_1 * V_3 )
{
return V_3 -> error ;
}
void F_68 ( T_1 * V_3 , int V_77 )
{
V_3 -> error = V_77 ;
}
int F_69 ( T_1 * V_3 )
{
return V_3 -> V_31 ;
}
T_2 * F_70 ( T_1 * V_3 )
{
return V_3 -> V_30 ;
}
int F_71 ( T_1 * V_3 , int V_60 )
{
return F_72 ( V_3 , 0 , V_60 , 0 ) ;
}
int F_73 ( T_1 * V_3 , int V_35 )
{
return F_72 ( V_3 , 0 , 0 , V_35 ) ;
}
int F_72 ( T_1 * V_3 , int V_158 ,
int V_60 , int V_35 )
{
int V_104 ;
if ( ! V_60 ) V_60 = V_158 ;
if ( V_60 )
{
T_14 * V_159 ;
V_104 = F_74 ( V_60 ) ;
if ( V_104 == - 1 )
{
F_5 ( V_160 ,
V_161 ) ;
return 0 ;
}
V_159 = F_75 ( V_104 ) ;
if ( V_159 -> V_35 == V_162 )
{
V_104 = F_74 ( V_158 ) ;
if ( V_104 == - 1 )
{
F_5 ( V_160 ,
V_161 ) ;
return 0 ;
}
V_159 = F_75 ( V_104 ) ;
}
if ( ! V_35 ) V_35 = V_159 -> V_35 ;
}
if ( V_35 )
{
V_104 = F_76 ( V_35 ) ;
if ( V_104 == - 1 )
{
F_5 ( V_160 ,
V_163 ) ;
return 0 ;
}
}
if ( V_60 && ! V_3 -> V_9 -> V_60 ) V_3 -> V_9 -> V_60 = V_60 ;
if ( V_35 && ! V_3 -> V_9 -> V_35 ) V_3 -> V_9 -> V_35 = V_35 ;
return 1 ;
}
T_1 * F_77 ( void )
{
T_1 * V_3 ;
V_3 = ( T_1 * ) F_78 ( sizeof( T_1 ) ) ;
if ( ! V_3 )
{
F_5 ( V_164 , V_21 ) ;
return NULL ;
}
memset ( V_3 , 0 , sizeof( T_1 ) ) ;
return V_3 ;
}
void F_79 ( T_1 * V_3 )
{
F_80 ( V_3 ) ;
F_81 ( V_3 ) ;
}
void F_80 ( T_1 * V_3 )
{
if ( V_3 -> V_165 ) V_3 -> V_165 ( V_3 ) ;
F_82 ( V_3 -> V_9 ) ;
if ( V_3 -> V_116 )
F_83 ( V_3 -> V_116 ) ;
if ( V_3 -> V_20 != NULL )
{
F_84 ( V_3 -> V_20 , F_17 ) ;
V_3 -> V_20 = NULL ;
}
F_85 ( V_156 , V_3 , & ( V_3 -> V_157 ) ) ;
memset ( & V_3 -> V_157 , 0 , sizeof( V_166 ) ) ;
}
void F_86 ( T_1 * V_3 , int V_10 )
{
F_87 ( V_3 -> V_9 , V_10 ) ;
}
void F_88 ( T_1 * V_3 , unsigned long V_38 )
{
F_89 ( V_3 -> V_9 , V_38 ) ;
}
void F_90 ( T_1 * V_3 , unsigned long V_38 , T_6 V_149 )
{
F_91 ( V_3 -> V_9 , V_149 ) ;
}
void F_92 ( T_1 * V_3 ,
int (* V_19)( int , T_1 * ) )
{
V_3 -> V_19 = V_19 ;
}
T_15 * F_93 ( T_1 * V_3 )
{
return V_3 -> V_116 ;
}
int F_94 ( T_1 * V_3 )
{
return V_3 -> V_117 ;
}
int F_95 ( T_1 * V_3 , const char * V_167 )
{
const T_4 * V_9 ;
V_9 = F_96 ( V_167 ) ;
if ( ! V_9 )
return 0 ;
return F_97 ( V_3 -> V_9 , V_9 ) ;
}
T_4 * F_98 ( T_1 * V_3 )
{
return V_3 -> V_9 ;
}
void F_99 ( T_1 * V_3 , T_4 * V_9 )
{
if ( V_3 -> V_9 )
F_82 ( V_3 -> V_9 ) ;
V_3 -> V_9 = V_9 ;
}
