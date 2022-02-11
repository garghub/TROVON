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
( void ) F_14 ( V_15 , V_5 ) ;
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
( void ) F_18 ( V_3 -> V_20 , V_11 - 1 , V_4 ) ;
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
V_1 = F_21 ( V_3 ) ;
if ( ! V_1 ) goto V_22;
if ( V_9 -> V_35 > 0 ) V_1 = F_22 ( V_3 ) ;
if ( ! V_1 ) goto V_22;
F_23 ( NULL , V_3 -> V_20 ) ;
V_1 = V_3 -> V_36 ( V_3 ) ;
if( ! V_1 ) goto V_22;
if ( V_3 -> V_37 != NULL )
V_1 = V_3 -> V_37 ( V_3 ) ;
else
V_1 = F_24 ( V_3 ) ;
if( ! V_1 ) goto V_22;
#ifndef F_25
V_1 = F_26 ( V_3 ) ;
if ( ! V_1 ) goto V_22;
V_1 = F_27 ( V_3 ) ;
if ( ! V_1 ) goto V_22;
#endif
if ( ! V_8 && ( V_3 -> V_9 -> V_38 & V_39 ) )
V_1 = V_3 -> V_40 ( V_3 ) ;
if( ! V_1 ) goto V_22;
if ( 0 )
{
V_22:
F_23 ( NULL , V_3 -> V_20 ) ;
}
if ( V_15 != NULL ) F_28 ( V_15 ) ;
if ( V_6 != NULL ) F_17 ( V_6 ) ;
return V_1 ;
}
static int V_27 ( T_1 * V_3 , T_2 * V_4 , T_2 * V_41 )
{
int V_42 ;
V_42 = F_29 ( V_41 , V_4 ) ;
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
static int F_30 ( T_2 * * V_41 , T_1 * V_3 , T_2 * V_4 )
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
#ifdef F_31
return 1 ;
#else
int V_11 , V_1 = 0 , V_47 , V_48 = 0 ;
T_2 * V_4 ;
int (* F_3)( int V_13 , T_1 * V_14 );
int V_49 = 0 ;
int V_50 ;
int V_51 ;
F_3 = V_3 -> V_19 ;
V_47 = - 1 ;
if ( V_3 -> V_52 )
{
V_51 = 0 ;
V_50 = V_53 ;
}
else
{
V_51 =
! ! ( V_3 -> V_9 -> V_38 & V_54 ) ;
if ( getenv ( L_1 ) )
V_51 = 1 ;
V_50 = V_3 -> V_9 -> V_50 ;
}
for ( V_11 = 0 ; V_11 < V_3 -> V_25 ; V_11 ++ )
{
int V_42 ;
V_4 = F_11 ( V_3 -> V_20 , V_11 ) ;
if ( ! ( V_3 -> V_9 -> V_38 & V_55 )
&& ( V_4 -> V_56 & V_57 ) )
{
V_3 -> error = V_58 ;
V_3 -> V_31 = V_11 ;
V_3 -> V_30 = V_4 ;
V_1 = F_3 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_22;
}
if ( ! V_51 && ( V_4 -> V_56 & V_59 ) )
{
V_3 -> error = V_60 ;
V_3 -> V_31 = V_11 ;
V_3 -> V_30 = V_4 ;
V_1 = F_3 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_22;
}
V_42 = F_32 ( V_4 ) ;
switch( V_47 )
{
case - 1 :
if ( ( V_3 -> V_9 -> V_38 & V_61 )
&& ( V_42 != 1 ) && ( V_42 != 0 ) )
{
V_42 = 0 ;
V_3 -> error = V_62 ;
}
else
V_42 = 1 ;
break;
case 0 :
if ( V_42 != 0 )
{
V_42 = 0 ;
V_3 -> error = V_63 ;
}
else
V_42 = 1 ;
break;
default:
if ( ( V_42 == 0 )
|| ( ( V_3 -> V_9 -> V_38 & V_61 )
&& ( V_42 != 1 ) ) )
{
V_42 = 0 ;
V_3 -> error = V_62 ;
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
if ( V_3 -> V_9 -> V_50 > 0 )
{
V_42 = F_33 ( V_4 , V_50 , V_47 > 0 ) ;
if ( ( V_42 == 0 )
|| ( ( V_3 -> V_9 -> V_38 & V_61 )
&& ( V_42 != 1 ) ) )
{
V_3 -> error = V_64 ;
V_3 -> V_31 = V_11 ;
V_3 -> V_30 = V_4 ;
V_1 = F_3 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_22;
}
}
if ( ( V_11 > 1 ) && ! ( V_4 -> V_56 & V_65 )
&& ( V_4 -> V_66 != - 1 )
&& ( V_48 > ( V_4 -> V_66 + V_49 + 1 ) ) )
{
V_3 -> error = V_67 ;
V_3 -> V_31 = V_11 ;
V_3 -> V_30 = V_4 ;
V_1 = F_3 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_22;
}
if ( ! ( V_4 -> V_56 & V_65 ) )
V_48 ++ ;
if ( V_4 -> V_56 & V_59 )
{
if ( V_4 -> V_68 != - 1 && V_11 > V_4 -> V_68 )
{
V_3 -> error =
V_69 ;
V_3 -> V_31 = V_11 ;
V_3 -> V_30 = V_4 ;
V_1 = F_3 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_22;
}
V_49 ++ ;
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
T_2 * V_4 ;
int V_11 , V_70 , V_71 ;
for ( V_11 = F_10 ( V_3 -> V_20 ) - 1 ; V_11 >= 0 ; V_11 -- )
{
V_4 = F_11 ( V_3 -> V_20 , V_11 ) ;
if ( V_11 && ( V_4 -> V_56 & V_65 ) )
continue;
for ( V_70 = F_10 ( V_3 -> V_20 ) - 1 ; V_70 > V_11 ; V_70 -- )
{
T_5 * V_72 = F_11 ( V_3 -> V_20 , V_70 ) -> V_72 ;
if ( V_72 )
{
V_71 = F_34 ( V_4 , V_72 ) ;
if ( V_71 != V_43 )
{
V_3 -> error = V_71 ;
V_3 -> V_31 = V_11 ;
V_3 -> V_30 = V_4 ;
if ( ! V_3 -> V_19 ( 0 , V_3 ) )
return 0 ;
}
}
}
}
return 1 ;
}
static int F_22 ( T_1 * V_3 )
{
#ifdef F_31
return 1 ;
#else
int V_11 , V_1 ;
T_2 * V_4 ;
int (* F_3)( int V_13 , T_1 * V_14 );
F_3 = V_3 -> V_19 ;
V_11 = F_10 ( V_3 -> V_20 ) - 1 ;
V_4 = F_11 ( V_3 -> V_20 , V_11 ) ;
V_1 = F_35 ( V_4 , V_3 -> V_9 -> V_35 , 0 ) ;
if ( V_1 == V_73 )
return 1 ;
V_3 -> V_31 = V_11 ;
V_3 -> V_30 = V_4 ;
if ( V_1 == V_74 )
V_3 -> error = V_75 ;
else
V_3 -> error = V_76 ;
V_1 = F_3 ( 0 , V_3 ) ;
return V_1 ;
#endif
}
static int V_36 ( T_1 * V_3 )
{
int V_11 , V_77 , V_1 ;
if ( ! ( V_3 -> V_9 -> V_38 & V_78 ) )
return 1 ;
if ( V_3 -> V_9 -> V_38 & V_79 )
V_77 = F_10 ( V_3 -> V_20 ) - 1 ;
else
{
if ( V_3 -> V_52 )
return 1 ;
V_77 = 0 ;
}
for( V_11 = 0 ; V_11 <= V_77 ; V_11 ++ )
{
V_3 -> V_31 = V_11 ;
V_1 = F_36 ( V_3 ) ;
if ( ! V_1 ) return V_1 ;
}
return 1 ;
}
static int F_36 ( T_1 * V_3 )
{
T_6 * V_80 = NULL , * V_81 = NULL ;
T_2 * V_4 ;
int V_1 , V_82 ;
V_82 = V_3 -> V_31 ;
V_4 = F_11 ( V_3 -> V_20 , V_82 ) ;
V_3 -> V_30 = V_4 ;
V_3 -> V_45 = NULL ;
V_3 -> V_83 = 0 ;
while ( V_3 -> V_83 != V_84 )
{
if ( V_3 -> V_85 )
V_1 = V_3 -> V_85 ( V_3 , & V_80 , V_4 ) ;
else
V_1 = F_37 ( V_3 , & V_80 , & V_81 , V_4 ) ;
if( ! V_1 )
{
V_3 -> error = V_86 ;
V_1 = V_3 -> V_19 ( 0 , V_3 ) ;
goto V_87;
}
V_3 -> V_88 = V_80 ;
V_1 = V_3 -> V_89 ( V_3 , V_80 ) ;
if ( ! V_1 )
goto V_87;
if ( V_81 )
{
V_1 = V_3 -> V_89 ( V_3 , V_81 ) ;
if ( ! V_1 )
goto V_87;
V_1 = V_3 -> V_90 ( V_3 , V_81 , V_4 ) ;
if ( ! V_1 )
goto V_87;
}
else
V_1 = 1 ;
if ( V_1 != 2 )
{
V_1 = V_3 -> V_90 ( V_3 , V_80 , V_4 ) ;
if ( ! V_1 )
goto V_87;
}
F_38 ( V_80 ) ;
F_38 ( V_81 ) ;
V_80 = NULL ;
V_81 = NULL ;
}
V_87:
F_38 ( V_80 ) ;
F_38 ( V_81 ) ;
V_3 -> V_88 = NULL ;
return V_1 ;
}
static int F_39 ( T_1 * V_3 , T_6 * V_80 , int V_91 )
{
T_7 * V_92 ;
int V_11 ;
if ( V_91 )
V_3 -> V_88 = V_80 ;
if ( V_3 -> V_9 -> V_38 & V_93 )
V_92 = & V_3 -> V_9 -> V_94 ;
else
V_92 = NULL ;
V_11 = F_40 ( F_41 ( V_80 ) , V_92 ) ;
if ( V_11 == 0 )
{
if ( ! V_91 )
return 0 ;
V_3 -> error = V_95 ;
if ( ! V_3 -> V_19 ( 0 , V_3 ) )
return 0 ;
}
if ( V_11 > 0 )
{
if ( ! V_91 )
return 0 ;
V_3 -> error = V_96 ;
if ( ! V_3 -> V_19 ( 0 , V_3 ) )
return 0 ;
}
if( F_42 ( V_80 ) )
{
V_11 = F_40 ( F_42 ( V_80 ) , V_92 ) ;
if ( V_11 == 0 )
{
if ( ! V_91 )
return 0 ;
V_3 -> error = V_97 ;
if ( ! V_3 -> V_19 ( 0 , V_3 ) )
return 0 ;
}
if ( ( V_11 < 0 ) && ! ( V_3 -> V_98 & V_99 ) )
{
if ( ! V_91 )
return 0 ;
V_3 -> error = V_100 ;
if ( ! V_3 -> V_19 ( 0 , V_3 ) )
return 0 ;
}
}
if ( V_91 )
V_3 -> V_88 = NULL ;
return 1 ;
}
static int F_43 ( T_6 * V_101 , T_6 * V_102 , int V_103 )
{
T_8 * V_104 , * V_105 ;
int V_11 ;
V_11 = F_44 ( V_101 , V_103 , 0 ) ;
if ( V_11 >= 0 )
{
if ( F_44 ( V_101 , V_103 , V_11 ) != - 1 )
return 0 ;
V_104 = F_45 ( F_46 ( V_101 , V_11 ) ) ;
}
else
V_104 = NULL ;
V_11 = F_44 ( V_102 , V_103 , 0 ) ;
if ( V_11 >= 0 )
{
if ( F_44 ( V_102 , V_103 , V_11 ) != - 1 )
return 0 ;
V_105 = F_45 ( F_46 ( V_102 , V_11 ) ) ;
}
else
V_105 = NULL ;
if ( ! V_104 && ! V_105 )
return 1 ;
if ( ! V_104 || ! V_105 )
return 0 ;
if ( F_47 ( V_104 , V_105 ) )
return 0 ;
return 1 ;
}
static int F_48 ( T_6 * V_106 , T_6 * V_107 )
{
if ( ! V_106 -> V_108 )
return 0 ;
if ( ! V_107 -> V_109 )
return 0 ;
if ( F_49 ( F_50 ( V_107 ) ,
F_50 ( V_106 ) ) )
return 0 ;
if ( ! F_43 ( V_106 , V_107 , V_110 ) )
return 0 ;
if ( ! F_43 ( V_106 , V_107 , V_111 ) )
return 0 ;
if ( F_51 ( V_106 -> V_108 , V_107 -> V_109 ) > 0 )
return 0 ;
if ( F_51 ( V_106 -> V_109 , V_107 -> V_109 ) > 0 )
return 1 ;
return 0 ;
}
static int F_52 ( T_1 * V_3 , T_2 * * V_112 ,
unsigned int * V_113 ,
T_6 * V_80 , T_2 * V_4 )
{
int V_114 = 0 ;
unsigned int V_115 = * V_113 , V_116 ;
if ( V_80 -> V_117 & V_118 )
return 0 ;
if ( ! ( V_3 -> V_9 -> V_38 & V_119 ) )
{
if ( V_80 -> V_117 & ( V_120 | V_121 ) )
return 0 ;
}
else if ( V_80 -> V_117 & V_121 )
{
if ( ! ( V_80 -> V_122 & ~ V_115 ) )
return 0 ;
}
else if ( V_80 -> V_108 )
return 0 ;
if ( F_49 ( F_12 ( V_4 ) , F_50 ( V_80 ) ) )
{
if ( ! ( V_80 -> V_117 & V_120 ) )
return 0 ;
}
else
V_114 |= V_123 ;
if ( ! ( V_80 -> V_38 & V_57 ) )
V_114 |= V_124 ;
if ( F_39 ( V_3 , V_80 , 0 ) )
V_114 |= V_125 ;
F_53 ( V_3 , V_80 , V_112 , & V_114 ) ;
if ( ! ( V_114 & V_126 ) )
return 0 ;
if ( F_54 ( V_4 , V_80 , V_114 , & V_116 ) )
{
if ( ! ( V_116 & ~ V_115 ) )
return 0 ;
V_115 |= V_116 ;
V_114 |= V_127 ;
}
* V_113 = V_115 ;
return V_114 ;
}
static void F_53 ( T_1 * V_3 , T_6 * V_80 ,
T_2 * * V_112 , int * V_128 )
{
T_2 * V_129 = NULL ;
T_3 * V_130 = F_50 ( V_80 ) ;
int V_131 = V_3 -> V_31 ;
int V_11 ;
if ( V_131 != F_10 ( V_3 -> V_20 ) - 1 )
V_131 ++ ;
V_129 = F_11 ( V_3 -> V_20 , V_131 ) ;
if ( F_55 ( V_129 , V_80 -> V_132 ) == V_43 )
{
if ( * V_128 & V_123 )
{
* V_128 |= V_126 | V_133 ;
* V_112 = V_129 ;
return;
}
}
for ( V_131 ++ ; V_131 < F_10 ( V_3 -> V_20 ) ; V_131 ++ )
{
V_129 = F_11 ( V_3 -> V_20 , V_131 ) ;
if ( F_49 ( F_15 ( V_129 ) , V_130 ) )
continue;
if ( F_55 ( V_129 , V_80 -> V_132 ) == V_43 )
{
* V_128 |= V_126 | V_134 ;
* V_112 = V_129 ;
return;
}
}
if ( ! ( V_3 -> V_9 -> V_38 & V_119 ) )
return;
for ( V_11 = 0 ; V_11 < F_10 ( V_3 -> V_26 ) ; V_11 ++ )
{
V_129 = F_11 ( V_3 -> V_26 , V_11 ) ;
if ( F_49 ( F_15 ( V_129 ) , V_130 ) )
continue;
if ( F_55 ( V_129 , V_80 -> V_132 ) == V_43 )
{
* V_112 = V_129 ;
* V_128 |= V_126 ;
return;
}
}
}
static int F_56 ( T_1 * V_3 , T_2 * V_4 )
{
T_1 V_135 ;
int V_42 ;
if ( V_3 -> V_52 )
return 0 ;
if ( ! F_57 ( & V_135 , V_3 -> V_3 , V_4 , V_3 -> V_26 ) )
return - 1 ;
V_135 . V_136 = V_3 -> V_136 ;
F_58 ( & V_135 , V_3 -> V_9 ) ;
V_135 . V_52 = V_3 ;
V_135 . V_19 = V_3 -> V_19 ;
V_42 = F_2 ( & V_135 ) ;
if ( V_42 <= 0 )
goto V_87;
V_42 = F_59 ( V_3 , V_3 -> V_20 , V_135 . V_20 ) ;
V_87:
F_60 ( & V_135 ) ;
return V_42 ;
}
static int F_61 ( T_9 * V_101 , T_9 * V_102 )
{
T_3 * V_137 = NULL ;
T_10 * V_138 = NULL ;
T_11 * V_139 , * V_140 ;
int V_11 , V_70 ;
if ( ! V_101 || ! V_102 )
return 1 ;
if ( V_101 -> type == 1 )
{
if ( ! V_101 -> V_141 )
return 0 ;
if ( V_102 -> type == 1 )
{
if ( ! V_102 -> V_141 )
return 0 ;
if ( ! F_49 ( V_101 -> V_141 , V_102 -> V_141 ) )
return 1 ;
else
return 0 ;
}
V_137 = V_101 -> V_141 ;
V_138 = V_102 -> V_142 . V_143 ;
}
else if ( V_102 -> type == 1 )
{
if ( ! V_102 -> V_141 )
return 0 ;
V_138 = V_101 -> V_142 . V_143 ;
V_137 = V_102 -> V_141 ;
}
if ( V_137 )
{
for ( V_11 = 0 ; V_11 < F_62 ( V_138 ) ; V_11 ++ )
{
V_139 = F_63 ( V_138 , V_11 ) ;
if ( V_139 -> type != V_144 )
continue;
if ( ! F_49 ( V_137 , V_139 -> V_145 . V_146 ) )
return 1 ;
}
return 0 ;
}
for ( V_11 = 0 ; V_11 < F_62 ( V_101 -> V_142 . V_143 ) ; V_11 ++ )
{
V_139 = F_63 ( V_101 -> V_142 . V_143 , V_11 ) ;
for ( V_70 = 0 ; V_70 < F_62 ( V_102 -> V_142 . V_143 ) ; V_70 ++ )
{
V_140 = F_63 ( V_102 -> V_142 . V_143 , V_70 ) ;
if ( ! F_64 ( V_139 , V_140 ) )
return 1 ;
}
}
return 0 ;
}
static int F_65 ( T_12 * V_147 , T_6 * V_80 , int V_114 )
{
int V_11 ;
T_3 * V_137 = F_50 ( V_80 ) ;
if ( ! V_147 -> V_148 )
return ! ! ( V_114 & V_123 ) ;
for ( V_11 = 0 ; V_11 < F_62 ( V_147 -> V_148 ) ; V_11 ++ )
{
T_11 * V_149 = F_63 ( V_147 -> V_148 , V_11 ) ;
if ( V_149 -> type != V_144 )
continue;
if ( ! F_49 ( V_149 -> V_145 . V_146 , V_137 ) )
return 1 ;
}
return 0 ;
}
static int F_54 ( T_2 * V_4 , T_6 * V_80 , int V_114 ,
unsigned int * V_113 )
{
int V_11 ;
if ( V_80 -> V_117 & V_150 )
return 0 ;
if ( V_4 -> V_56 & V_151 )
{
if ( V_80 -> V_117 & V_152 )
return 0 ;
}
else
{
if ( V_80 -> V_117 & V_153 )
return 0 ;
}
* V_113 = V_80 -> V_122 ;
for ( V_11 = 0 ; V_11 < F_66 ( V_4 -> V_154 ) ; V_11 ++ )
{
T_12 * V_147 = F_67 ( V_4 -> V_154 , V_11 ) ;
if ( F_65 ( V_147 , V_80 , V_114 ) )
{
if ( ! V_80 -> V_155 ||
F_61 ( V_147 -> V_156 , V_80 -> V_155 -> V_156 ) )
{
* V_113 &= V_147 -> V_157 ;
return 1 ;
}
}
}
if ( ( ! V_80 -> V_155 || ! V_80 -> V_155 -> V_156 ) && ( V_114 & V_123 ) )
return 1 ;
return 0 ;
}
static int F_37 ( T_1 * V_3 ,
T_6 * * V_158 , T_6 * * V_159 , T_2 * V_4 )
{
int V_1 ;
T_2 * V_41 = NULL ;
int V_114 = 0 ;
unsigned int V_160 ;
T_6 * V_80 = NULL , * V_81 = NULL ;
F_4 ( T_6 ) * V_161 ;
T_3 * V_137 = F_12 ( V_4 ) ;
V_160 = V_3 -> V_83 ;
V_1 = F_68 ( V_3 , & V_80 , & V_81 ,
& V_41 , & V_114 , & V_160 , V_3 -> V_136 ) ;
if ( V_1 )
goto V_162;
V_161 = V_3 -> V_163 ( V_3 , V_137 ) ;
if ( ! V_161 && V_80 )
goto V_162;
F_68 ( V_3 , & V_80 , & V_81 , & V_41 , & V_114 , & V_160 , V_161 ) ;
F_69 ( V_161 , F_38 ) ;
V_162:
if ( V_80 )
{
V_3 -> V_45 = V_41 ;
V_3 -> V_98 = V_114 ;
V_3 -> V_83 = V_160 ;
* V_158 = V_80 ;
* V_159 = V_81 ;
return 1 ;
}
return 0 ;
}
static int V_89 ( T_1 * V_3 , T_6 * V_80 )
{
T_2 * V_41 = NULL ;
T_13 * V_164 = NULL ;
int V_1 = 0 , V_165 , V_82 ;
V_82 = V_3 -> V_31 ;
V_165 = F_10 ( V_3 -> V_20 ) - 1 ;
if ( V_3 -> V_45 )
V_41 = V_3 -> V_45 ;
else if ( V_82 < V_165 )
V_41 = F_11 ( V_3 -> V_20 , V_82 + 1 ) ;
else
{
V_41 = F_11 ( V_3 -> V_20 , V_165 ) ;
if( ! V_3 -> V_27 ( V_3 , V_41 , V_41 ) )
{
V_3 -> error = V_166 ;
V_1 = V_3 -> V_19 ( 0 , V_3 ) ;
if( ! V_1 ) goto V_87;
}
}
if( V_41 )
{
if ( ! V_80 -> V_108 )
{
if ( ( V_41 -> V_56 & V_167 ) &&
! ( V_41 -> V_168 & V_169 ) )
{
V_3 -> error = V_170 ;
V_1 = V_3 -> V_19 ( 0 , V_3 ) ;
if( ! V_1 ) goto V_87;
}
if ( ! ( V_3 -> V_98 & V_127 ) )
{
V_3 -> error = V_171 ;
V_1 = V_3 -> V_19 ( 0 , V_3 ) ;
if( ! V_1 ) goto V_87;
}
if ( ! ( V_3 -> V_98 & V_134 ) )
{
if ( F_56 ( V_3 , V_3 -> V_45 ) <= 0 )
{
V_3 -> error = V_172 ;
V_1 = V_3 -> V_19 ( 0 , V_3 ) ;
if( ! V_1 ) goto V_87;
}
}
if ( V_80 -> V_117 & V_118 )
{
V_3 -> error = V_173 ;
V_1 = V_3 -> V_19 ( 0 , V_3 ) ;
if( ! V_1 ) goto V_87;
}
}
if ( ! ( V_3 -> V_98 & V_125 ) )
{
V_1 = F_39 ( V_3 , V_80 , 1 ) ;
if ( ! V_1 )
goto V_87;
}
V_164 = F_70 ( V_41 ) ;
if( ! V_164 )
{
V_3 -> error = V_174 ;
V_1 = V_3 -> V_19 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_87;
}
else
{
if( F_71 ( V_80 , V_164 ) <= 0 )
{
V_3 -> error = V_175 ;
V_1 = V_3 -> V_19 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_87;
}
}
}
V_1 = 1 ;
V_87:
F_72 ( V_164 ) ;
return V_1 ;
}
static int V_90 ( T_1 * V_3 , T_6 * V_80 , T_2 * V_4 )
{
int V_1 ;
T_14 * V_176 ;
if ( V_80 -> V_38 & V_57 )
{
if ( V_3 -> V_9 -> V_38 & V_55 )
return 1 ;
V_3 -> error = V_177 ;
V_1 = V_3 -> V_19 ( 0 , V_3 ) ;
if( ! V_1 )
return 0 ;
}
if ( F_73 ( V_80 , & V_176 , V_4 ) )
{
if ( V_176 -> V_178 == V_179 )
return 2 ;
V_3 -> error = V_180 ;
V_1 = V_3 -> V_19 ( 0 , V_3 ) ;
if ( ! V_1 )
return 0 ;
}
return 1 ;
}
static int V_40 ( T_1 * V_3 )
{
int V_42 ;
if ( V_3 -> V_52 )
return 1 ;
V_42 = F_74 ( & V_3 -> V_181 , & V_3 -> V_182 , V_3 -> V_20 ,
V_3 -> V_9 -> V_183 , V_3 -> V_9 -> V_38 ) ;
if ( V_42 == 0 )
{
F_5 ( V_184 , V_21 ) ;
return 0 ;
}
if ( V_42 == - 1 )
{
T_2 * V_4 ;
int V_11 ;
for ( V_11 = 1 ; V_11 < F_10 ( V_3 -> V_20 ) ; V_11 ++ )
{
V_4 = F_11 ( V_3 -> V_20 , V_11 ) ;
if ( ! ( V_4 -> V_56 & V_185 ) )
continue;
V_3 -> V_30 = V_4 ;
V_3 -> error = V_186 ;
if( ! V_3 -> V_19 ( 0 , V_3 ) )
return 0 ;
}
return 1 ;
}
if ( V_42 == - 2 )
{
V_3 -> V_30 = NULL ;
V_3 -> error = V_187 ;
return V_3 -> V_19 ( 0 , V_3 ) ;
}
if ( V_3 -> V_9 -> V_38 & V_188 )
{
V_3 -> V_30 = NULL ;
V_3 -> error = V_43 ;
if ( ! V_3 -> V_19 ( 2 , V_3 ) )
return 0 ;
}
return 1 ;
}
static int F_75 ( T_1 * V_3 , T_2 * V_4 )
{
T_7 * V_92 ;
int V_11 ;
if ( V_3 -> V_9 -> V_38 & V_93 )
V_92 = & V_3 -> V_9 -> V_94 ;
else
V_92 = NULL ;
V_11 = F_40 ( F_76 ( V_4 ) , V_92 ) ;
if ( V_11 == 0 )
{
V_3 -> error = V_189 ;
V_3 -> V_30 = V_4 ;
if ( ! V_3 -> V_19 ( 0 , V_3 ) )
return 0 ;
}
if ( V_11 > 0 )
{
V_3 -> error = V_190 ;
V_3 -> V_30 = V_4 ;
if ( ! V_3 -> V_19 ( 0 , V_3 ) )
return 0 ;
}
V_11 = F_40 ( F_77 ( V_4 ) , V_92 ) ;
if ( V_11 == 0 )
{
V_3 -> error = V_191 ;
V_3 -> V_30 = V_4 ;
if ( ! V_3 -> V_19 ( 0 , V_3 ) )
return 0 ;
}
if ( V_11 < 0 )
{
V_3 -> error = V_192 ;
V_3 -> V_30 = V_4 ;
if ( ! V_3 -> V_19 ( 0 , V_3 ) )
return 0 ;
}
return 1 ;
}
static int F_24 ( T_1 * V_3 )
{
int V_1 = 0 , V_193 ;
T_2 * V_194 , * V_195 ;
T_13 * V_196 = NULL ;
int (* F_3)( int V_13 , T_1 * V_14 );
F_3 = V_3 -> V_19 ;
V_193 = F_10 ( V_3 -> V_20 ) ;
V_3 -> V_31 = V_193 - 1 ;
V_193 -- ;
V_195 = F_11 ( V_3 -> V_20 , V_193 ) ;
if ( V_3 -> V_27 ( V_3 , V_195 , V_195 ) )
V_194 = V_195 ;
else
{
if ( V_193 <= 0 )
{
V_3 -> error = V_197 ;
V_3 -> V_30 = V_195 ;
V_1 = F_3 ( 0 , V_3 ) ;
goto V_22;
}
else
{
V_193 -- ;
V_3 -> V_31 = V_193 ;
V_194 = F_11 ( V_3 -> V_20 , V_193 ) ;
}
}
while ( V_193 >= 0 )
{
V_3 -> V_31 = V_193 ;
if ( ! V_194 -> V_198 && ( V_194 != V_195 || ( V_3 -> V_9 -> V_38 & V_199 ) ) )
{
if ( ( V_196 = F_70 ( V_195 ) ) == NULL )
{
V_3 -> error = V_174 ;
V_3 -> V_30 = V_195 ;
V_1 = (* F_3)( 0 , V_3 ) ;
if ( ! V_1 ) goto V_22;
}
else if ( F_78 ( V_194 , V_196 ) <= 0 )
{
V_3 -> error = V_200 ;
V_3 -> V_30 = V_194 ;
V_1 = (* F_3)( 0 , V_3 ) ;
if ( ! V_1 )
{
F_72 ( V_196 ) ;
goto V_22;
}
}
F_72 ( V_196 ) ;
V_196 = NULL ;
}
V_194 -> V_198 = 1 ;
V_1 = F_75 ( V_3 , V_194 ) ;
if ( ! V_1 )
goto V_22;
V_3 -> V_45 = V_195 ;
V_3 -> V_30 = V_194 ;
V_1 = (* F_3)( 1 , V_3 ) ;
if ( ! V_1 ) goto V_22;
V_193 -- ;
if ( V_193 >= 0 )
{
V_195 = V_194 ;
V_194 = F_11 ( V_3 -> V_20 , V_193 ) ;
}
}
V_1 = 1 ;
V_22:
return V_1 ;
}
int F_79 ( const T_15 * V_201 )
{
return F_40 ( V_201 , NULL ) ;
}
int F_40 ( const T_15 * V_201 , T_7 * V_202 )
{
char * V_203 ;
T_15 V_204 ;
long V_205 ;
char V_206 [ 24 ] , V_207 [ 24 ] , * V_208 ;
int V_11 , V_70 ;
V_208 = V_206 ;
V_11 = V_201 -> V_209 ;
V_203 = ( char * ) V_201 -> V_210 ;
if ( V_201 -> type == V_211 )
{
if ( ( V_11 < 11 ) || ( V_11 > 17 ) ) return 0 ;
memcpy ( V_208 , V_203 , 10 ) ;
V_208 += 10 ;
V_203 += 10 ;
}
else
{
if ( V_11 < 13 ) return 0 ;
memcpy ( V_208 , V_203 , 12 ) ;
V_208 += 12 ;
V_203 += 12 ;
}
if ( ( * V_203 == 'Z' ) || ( * V_203 == '-' ) || ( * V_203 == '+' ) )
{ * ( V_208 ++ ) = '0' ; * ( V_208 ++ ) = '0' ; }
else
{
* ( V_208 ++ ) = * ( V_203 ++ ) ;
* ( V_208 ++ ) = * ( V_203 ++ ) ;
if ( * V_203 == '.' )
{
V_203 ++ ;
while ( ( * V_203 >= '0' ) && ( * V_203 <= '9' ) ) V_203 ++ ;
}
}
* ( V_208 ++ ) = 'Z' ;
* ( V_208 ++ ) = '\0' ;
if ( * V_203 == 'Z' )
V_205 = 0 ;
else
{
if ( ( * V_203 != '+' ) && ( * V_203 != '-' ) )
return 0 ;
V_205 = ( ( V_203 [ 1 ] - '0' ) * 10 + ( V_203 [ 2 ] - '0' ) ) * 60 ;
V_205 += ( V_203 [ 3 ] - '0' ) * 10 + ( V_203 [ 4 ] - '0' ) ;
if ( * V_203 == '-' )
V_205 = - V_205 ;
}
V_204 . type = V_201 -> type ;
V_204 . V_38 = 0 ;
V_204 . V_209 = sizeof( V_207 ) ;
V_204 . V_210 = ( unsigned char * ) V_207 ;
if ( F_80 ( & V_204 , - V_205 * 60 , V_202 ) == NULL )
return 0 ;
if ( V_201 -> type == V_211 )
{
V_11 = ( V_206 [ 0 ] - '0' ) * 10 + ( V_206 [ 1 ] - '0' ) ;
if ( V_11 < 50 ) V_11 += 100 ;
V_70 = ( V_207 [ 0 ] - '0' ) * 10 + ( V_207 [ 1 ] - '0' ) ;
if ( V_70 < 50 ) V_70 += 100 ;
if ( V_11 < V_70 ) return - 1 ;
if ( V_11 > V_70 ) return 1 ;
}
V_11 = strcmp ( V_206 , V_207 ) ;
if ( V_11 == 0 )
return - 1 ;
else
return V_11 ;
}
T_15 * F_81 ( T_15 * V_212 , long V_213 )
{
return F_80 ( V_212 , V_213 , NULL ) ;
}
T_15 * F_80 ( T_15 * V_212 , long V_214 , T_7 * V_215 )
{
return F_82 ( V_212 , 0 , V_214 , V_215 ) ;
}
T_15 * F_82 ( T_15 * V_212 ,
int V_216 , long V_214 , T_7 * V_215 )
{
T_7 V_217 ;
if ( V_215 ) V_217 = * V_215 ;
else time ( & V_217 ) ;
if ( V_212 && ! ( V_212 -> V_38 & V_218 ) )
{
if ( V_212 -> type == V_211 )
return F_83 ( V_212 , V_217 , V_216 , V_214 ) ;
if ( V_212 -> type == V_219 )
return F_84 ( V_212 , V_217 , V_216 ,
V_214 ) ;
}
return F_85 ( V_212 , V_217 , V_216 , V_214 ) ;
}
int F_86 ( long V_220 , void * V_221 , T_16 * V_222 ,
T_17 * V_223 , T_18 * V_224 )
{
return F_87 ( V_225 , V_220 , V_221 ,
V_222 , V_223 , V_224 ) ;
}
int F_88 ( T_1 * V_3 , int V_226 , void * V_210 )
{
return F_89 ( & V_3 -> V_227 , V_226 , V_210 ) ;
}
void * F_90 ( T_1 * V_3 , int V_226 )
{
return F_91 ( & V_3 -> V_227 , V_226 ) ;
}
int F_92 ( T_1 * V_3 )
{
return V_3 -> error ;
}
void F_93 ( T_1 * V_3 , int V_87 )
{
V_3 -> error = V_87 ;
}
int F_94 ( T_1 * V_3 )
{
return V_3 -> V_31 ;
}
T_2 * F_95 ( T_1 * V_3 )
{
return V_3 -> V_30 ;
}
T_6 * F_96 ( T_1 * V_3 )
{
return V_3 -> V_88 ;
}
T_1 * F_97 ( T_1 * V_3 )
{
return V_3 -> V_52 ;
}
void F_98 ( T_1 * V_3 , T_2 * V_4 )
{
V_3 -> V_16 = V_4 ;
}
int F_99 ( T_1 * V_3 , int V_50 )
{
return F_100 ( V_3 , 0 , V_50 , 0 ) ;
}
int F_101 ( T_1 * V_3 , int V_35 )
{
return F_100 ( V_3 , 0 , 0 , V_35 ) ;
}
int F_100 ( T_1 * V_3 , int V_228 ,
int V_50 , int V_35 )
{
int V_226 ;
if ( ! V_50 ) V_50 = V_228 ;
if ( V_50 )
{
T_19 * V_229 ;
V_226 = F_102 ( V_50 ) ;
if ( V_226 == - 1 )
{
F_5 ( V_230 ,
V_231 ) ;
return 0 ;
}
V_229 = F_103 ( V_226 ) ;
if ( V_229 -> V_35 == V_232 )
{
V_226 = F_102 ( V_228 ) ;
if ( V_226 == - 1 )
{
F_5 ( V_230 ,
V_231 ) ;
return 0 ;
}
V_229 = F_103 ( V_226 ) ;
}
if ( ! V_35 ) V_35 = V_229 -> V_35 ;
}
if ( V_35 )
{
V_226 = F_104 ( V_35 ) ;
if ( V_226 == - 1 )
{
F_5 ( V_230 ,
V_233 ) ;
return 0 ;
}
}
if ( V_50 && ! V_3 -> V_9 -> V_50 ) V_3 -> V_9 -> V_50 = V_50 ;
if ( V_35 && ! V_3 -> V_9 -> V_35 ) V_3 -> V_9 -> V_35 = V_35 ;
return 1 ;
}
T_1 * F_105 ( void )
{
T_1 * V_3 ;
V_3 = ( T_1 * ) F_106 ( sizeof( T_1 ) ) ;
if ( ! V_3 )
{
F_5 ( V_234 , V_21 ) ;
return NULL ;
}
memset ( V_3 , 0 , sizeof( T_1 ) ) ;
return V_3 ;
}
void F_107 ( T_1 * V_3 )
{
F_60 ( V_3 ) ;
F_108 ( V_3 ) ;
}
void F_60 ( T_1 * V_3 )
{
if ( V_3 -> V_235 ) V_3 -> V_235 ( V_3 ) ;
if ( V_3 -> V_9 != NULL )
{
if ( V_3 -> V_52 == NULL )
F_109 ( V_3 -> V_9 ) ;
V_3 -> V_9 = NULL ;
}
if ( V_3 -> V_181 != NULL )
{
F_110 ( V_3 -> V_181 ) ;
V_3 -> V_181 = NULL ;
}
if ( V_3 -> V_20 != NULL )
{
F_111 ( V_3 -> V_20 , F_17 ) ;
V_3 -> V_20 = NULL ;
}
F_112 ( V_225 , V_3 , & ( V_3 -> V_227 ) ) ;
memset ( & V_3 -> V_227 , 0 , sizeof( V_236 ) ) ;
}
void F_113 ( T_1 * V_3 , int V_10 )
{
F_114 ( V_3 -> V_9 , V_10 ) ;
}
void F_115 ( T_1 * V_3 , unsigned long V_38 )
{
F_116 ( V_3 -> V_9 , V_38 ) ;
}
void F_117 ( T_1 * V_3 , unsigned long V_38 , T_7 V_217 )
{
F_118 ( V_3 -> V_9 , V_217 ) ;
}
void F_119 ( T_1 * V_3 ,
int (* V_19)( int , T_1 * ) )
{
V_3 -> V_19 = V_19 ;
}
T_20 * F_120 ( T_1 * V_3 )
{
return V_3 -> V_181 ;
}
int F_121 ( T_1 * V_3 )
{
return V_3 -> V_182 ;
}
int F_122 ( T_1 * V_3 , const char * V_142 )
{
const T_4 * V_9 ;
V_9 = F_123 ( V_142 ) ;
if ( ! V_9 )
return 0 ;
return F_124 ( V_3 -> V_9 , V_9 ) ;
}
T_4 * F_125 ( T_1 * V_3 )
{
return V_3 -> V_9 ;
}
void F_58 ( T_1 * V_3 , T_4 * V_9 )
{
if ( V_3 -> V_9 )
F_109 ( V_3 -> V_9 ) ;
V_3 -> V_9 = V_9 ;
}
