static int F_1 ( int V_1 , T_1 * V_2 )
{
return V_1 ;
}
int F_2 ( T_1 * V_3 )
{
T_2 * V_4 , * V_5 , * V_6 = NULL ;
int V_7 = 0 ;
T_3 * V_8 = V_3 -> V_8 ;
int V_9 , V_10 , V_1 = 0 ;
int V_11 ;
int (* F_3)( int V_12 , T_1 * V_13 );
F_4 ( T_2 ) * V_14 = NULL ;
if ( V_3 -> V_15 == NULL )
{
F_5 ( V_16 , V_17 ) ;
return - 1 ;
}
F_3 = V_3 -> V_18 ;
if ( V_3 -> V_19 == NULL )
{
if ( ( ( V_3 -> V_19 = F_6 () ) == NULL ) ||
( ! F_7 ( V_3 -> V_19 , V_3 -> V_15 ) ) )
{
F_5 ( V_16 , V_20 ) ;
goto V_21;
}
F_8 ( & V_3 -> V_15 -> V_22 , 1 , V_23 ) ;
V_3 -> V_24 = 1 ;
}
if ( V_3 -> V_25 != NULL
&& ( V_14 = F_9 ( V_3 -> V_25 ) ) == NULL )
{
F_5 ( V_16 , V_20 ) ;
goto V_21;
}
V_11 = F_10 ( V_3 -> V_19 ) ;
V_4 = F_11 ( V_3 -> V_19 , V_11 - 1 ) ;
V_9 = V_8 -> V_9 ;
for (; ; )
{
if ( V_9 < V_11 ) break;
if ( V_3 -> V_26 ( V_3 , V_4 , V_4 ) ) break;
if ( V_3 -> V_25 != NULL )
{
V_5 = F_12 ( V_3 , V_14 , V_4 ) ;
if ( V_5 != NULL )
{
if ( ! F_7 ( V_3 -> V_19 , V_5 ) )
{
F_5 ( V_16 , V_20 ) ;
goto V_21;
}
F_8 ( & V_5 -> V_22 , 1 , V_23 ) ;
( void ) F_13 ( V_14 , V_5 ) ;
V_3 -> V_24 ++ ;
V_4 = V_5 ;
V_11 ++ ;
continue;
}
}
break;
}
V_10 = F_10 ( V_3 -> V_19 ) ;
V_4 = F_11 ( V_3 -> V_19 , V_10 - 1 ) ;
if ( V_3 -> V_26 ( V_3 , V_4 , V_4 ) )
{
if ( F_10 ( V_3 -> V_19 ) == 1 )
{
V_1 = V_3 -> V_27 ( & V_5 , V_3 , V_4 ) ;
if ( ( V_1 <= 0 ) || F_14 ( V_4 , V_5 ) )
{
V_3 -> error = V_28 ;
V_3 -> V_29 = V_4 ;
V_3 -> V_30 = V_10 - 1 ;
if ( V_1 == 1 ) F_15 ( V_5 ) ;
V_7 = 1 ;
V_1 = F_3 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_21;
}
else
{
F_15 ( V_4 ) ;
V_4 = V_5 ;
( void ) F_16 ( V_3 -> V_19 , V_10 - 1 , V_4 ) ;
V_3 -> V_24 = 0 ;
}
}
else
{
V_6 = F_17 ( V_3 -> V_19 ) ;
V_3 -> V_24 -- ;
V_11 -- ;
V_4 = F_11 ( V_3 -> V_19 , V_11 - 1 ) ;
}
}
for (; ; )
{
if ( V_9 < V_11 ) break;
if ( V_3 -> V_26 ( V_3 , V_4 , V_4 ) ) break;
V_1 = V_3 -> V_27 ( & V_5 , V_3 , V_4 ) ;
if ( V_1 < 0 ) return V_1 ;
if ( V_1 == 0 ) break;
V_4 = V_5 ;
if ( ! F_7 ( V_3 -> V_19 , V_4 ) )
{
F_15 ( V_5 ) ;
F_5 ( V_16 , V_20 ) ;
return 0 ;
}
V_11 ++ ;
}
if ( ! V_3 -> V_26 ( V_3 , V_4 , V_4 ) )
{
if ( ( V_6 == NULL ) || ! V_3 -> V_26 ( V_3 , V_4 , V_6 ) )
{
if ( V_3 -> V_24 >= V_11 )
V_3 -> error = V_31 ;
else
V_3 -> error = V_32 ;
V_3 -> V_29 = V_4 ;
}
else
{
F_7 ( V_3 -> V_19 , V_6 ) ;
V_11 ++ ;
V_3 -> V_24 = V_11 ;
V_3 -> V_29 = V_6 ;
V_3 -> error = V_33 ;
V_6 = NULL ;
}
V_3 -> V_30 = V_11 - 1 ;
V_7 = 1 ;
V_1 = F_3 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_21;
}
V_1 = F_18 ( V_3 ) ;
if ( ! V_1 ) goto V_21;
V_1 = F_19 ( V_3 ) ;
if ( ! V_1 ) goto V_21;
if ( V_8 -> V_34 > 0 ) V_1 = F_20 ( V_3 ) ;
if ( ! V_1 ) goto V_21;
F_21 ( NULL , V_3 -> V_19 ) ;
V_1 = V_3 -> V_35 ( V_3 ) ;
if( ! V_1 ) goto V_21;
if ( V_3 -> V_36 != NULL )
V_1 = V_3 -> V_36 ( V_3 ) ;
else
V_1 = F_22 ( V_3 ) ;
if( ! V_1 ) goto V_21;
#ifndef F_23
V_1 = F_24 ( V_3 ) ;
if ( ! V_1 ) goto V_21;
V_1 = F_25 ( V_3 ) ;
if ( ! V_1 ) goto V_21;
#endif
if ( ! V_7 && ( V_3 -> V_8 -> V_37 & V_38 ) )
V_1 = V_3 -> V_39 ( V_3 ) ;
if( ! V_1 ) goto V_21;
if ( 0 )
{
V_21:
F_21 ( NULL , V_3 -> V_19 ) ;
}
if ( V_14 != NULL ) F_26 ( V_14 ) ;
if ( V_6 != NULL ) F_15 ( V_6 ) ;
return V_1 ;
}
static int V_26 ( T_1 * V_3 , T_2 * V_4 , T_2 * V_40 )
{
int V_41 ;
V_41 = F_27 ( V_40 , V_4 ) ;
if ( V_41 == V_42 )
return 1 ;
if ( ! ( V_3 -> V_8 -> V_37 & V_43 ) )
return 0 ;
V_3 -> error = V_41 ;
V_3 -> V_29 = V_4 ;
V_3 -> V_44 = V_40 ;
return V_3 -> V_18 ( 0 , V_3 ) ;
return 0 ;
}
static int F_28 ( T_2 * * V_40 , T_1 * V_3 , T_2 * V_4 )
{
* V_40 = F_12 ( V_3 , V_3 -> V_45 , V_4 ) ;
if ( * V_40 )
{
F_8 ( & ( * V_40 ) -> V_22 , 1 , V_23 ) ;
return 1 ;
}
else
return 0 ;
}
static int F_18 ( T_1 * V_3 )
{
#ifdef F_29
return 1 ;
#else
int V_10 , V_1 = 0 , V_46 , V_47 = 0 ;
T_2 * V_4 ;
int (* F_3)( int V_12 , T_1 * V_13 );
int V_48 = 0 ;
int V_49 ;
int V_50 ;
F_3 = V_3 -> V_18 ;
V_46 = - 1 ;
if ( V_3 -> V_51 )
{
V_50 = 0 ;
V_49 = V_52 ;
}
else
{
V_50 =
! ! ( V_3 -> V_8 -> V_37 & V_53 ) ;
if ( getenv ( L_1 ) )
V_50 = 1 ;
V_49 = V_3 -> V_8 -> V_49 ;
}
for ( V_10 = 0 ; V_10 < V_3 -> V_24 ; V_10 ++ )
{
int V_41 ;
V_4 = F_11 ( V_3 -> V_19 , V_10 ) ;
if ( ! ( V_3 -> V_8 -> V_37 & V_54 )
&& ( V_4 -> V_55 & V_56 ) )
{
V_3 -> error = V_57 ;
V_3 -> V_30 = V_10 ;
V_3 -> V_29 = V_4 ;
V_1 = F_3 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_21;
}
if ( ! V_50 && ( V_4 -> V_55 & V_58 ) )
{
V_3 -> error = V_59 ;
V_3 -> V_30 = V_10 ;
V_3 -> V_29 = V_4 ;
V_1 = F_3 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_21;
}
V_41 = F_30 ( V_4 ) ;
switch( V_46 )
{
case - 1 :
if ( ( V_3 -> V_8 -> V_37 & V_60 )
&& ( V_41 != 1 ) && ( V_41 != 0 ) )
{
V_41 = 0 ;
V_3 -> error = V_61 ;
}
else
V_41 = 1 ;
break;
case 0 :
if ( V_41 != 0 )
{
V_41 = 0 ;
V_3 -> error = V_62 ;
}
else
V_41 = 1 ;
break;
default:
if ( ( V_41 == 0 )
|| ( ( V_3 -> V_8 -> V_37 & V_60 )
&& ( V_41 != 1 ) ) )
{
V_41 = 0 ;
V_3 -> error = V_61 ;
}
else
V_41 = 1 ;
break;
}
if ( V_41 == 0 )
{
V_3 -> V_30 = V_10 ;
V_3 -> V_29 = V_4 ;
V_1 = F_3 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_21;
}
if ( V_3 -> V_8 -> V_49 > 0 )
{
V_41 = F_31 ( V_4 , V_49 , V_46 > 0 ) ;
if ( ( V_41 == 0 )
|| ( ( V_3 -> V_8 -> V_37 & V_60 )
&& ( V_41 != 1 ) ) )
{
V_3 -> error = V_63 ;
V_3 -> V_30 = V_10 ;
V_3 -> V_29 = V_4 ;
V_1 = F_3 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_21;
}
}
if ( ( V_10 > 1 ) && ! ( V_4 -> V_55 & V_64 )
&& ( V_4 -> V_65 != - 1 )
&& ( V_47 > ( V_4 -> V_65 + V_48 + 1 ) ) )
{
V_3 -> error = V_66 ;
V_3 -> V_30 = V_10 ;
V_3 -> V_29 = V_4 ;
V_1 = F_3 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_21;
}
if ( ! ( V_4 -> V_55 & V_64 ) )
V_47 ++ ;
if ( V_4 -> V_55 & V_58 )
{
if ( V_4 -> V_67 != - 1 && V_10 > V_4 -> V_67 )
{
V_3 -> error =
V_68 ;
V_3 -> V_30 = V_10 ;
V_3 -> V_29 = V_4 ;
V_1 = F_3 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_21;
}
V_48 ++ ;
V_46 = 0 ;
}
else
V_46 = 1 ;
}
V_1 = 1 ;
V_21:
return V_1 ;
#endif
}
static int F_19 ( T_1 * V_3 )
{
T_2 * V_4 ;
int V_10 , V_69 , V_70 ;
for ( V_10 = F_10 ( V_3 -> V_19 ) - 1 ; V_10 >= 0 ; V_10 -- )
{
V_4 = F_11 ( V_3 -> V_19 , V_10 ) ;
if ( V_10 && ( V_4 -> V_55 & V_64 ) )
continue;
for ( V_69 = F_10 ( V_3 -> V_19 ) - 1 ; V_69 > V_10 ; V_69 -- )
{
T_4 * V_71 = F_11 ( V_3 -> V_19 , V_69 ) -> V_71 ;
if ( V_71 )
{
V_70 = F_32 ( V_4 , V_71 ) ;
if ( V_70 != V_42 )
{
V_3 -> error = V_70 ;
V_3 -> V_30 = V_10 ;
V_3 -> V_29 = V_4 ;
if ( ! V_3 -> V_18 ( 0 , V_3 ) )
return 0 ;
}
}
}
}
return 1 ;
}
static int F_20 ( T_1 * V_3 )
{
#ifdef F_29
return 1 ;
#else
int V_10 , V_1 ;
T_2 * V_4 ;
int (* F_3)( int V_12 , T_1 * V_13 );
F_3 = V_3 -> V_18 ;
V_10 = F_10 ( V_3 -> V_19 ) - 1 ;
V_4 = F_11 ( V_3 -> V_19 , V_10 ) ;
V_1 = F_33 ( V_4 , V_3 -> V_8 -> V_34 , 0 ) ;
if ( V_1 == V_72 )
return 1 ;
V_3 -> V_30 = V_10 ;
V_3 -> V_29 = V_4 ;
if ( V_1 == V_73 )
V_3 -> error = V_74 ;
else
V_3 -> error = V_75 ;
V_1 = F_3 ( 0 , V_3 ) ;
return V_1 ;
#endif
}
static int V_35 ( T_1 * V_3 )
{
int V_10 , V_76 , V_1 ;
if ( ! ( V_3 -> V_8 -> V_37 & V_77 ) )
return 1 ;
if ( V_3 -> V_8 -> V_37 & V_78 )
V_76 = F_10 ( V_3 -> V_19 ) - 1 ;
else
{
if ( V_3 -> V_51 )
return 1 ;
V_76 = 0 ;
}
for( V_10 = 0 ; V_10 <= V_76 ; V_10 ++ )
{
V_3 -> V_30 = V_10 ;
V_1 = F_34 ( V_3 ) ;
if ( ! V_1 ) return V_1 ;
}
return 1 ;
}
static int F_34 ( T_1 * V_3 )
{
T_5 * V_79 = NULL , * V_80 = NULL ;
T_2 * V_4 ;
int V_1 , V_81 ;
V_81 = V_3 -> V_30 ;
V_4 = F_11 ( V_3 -> V_19 , V_81 ) ;
V_3 -> V_29 = V_4 ;
V_3 -> V_44 = NULL ;
V_3 -> V_82 = 0 ;
V_3 -> V_83 = 0 ;
while ( V_3 -> V_83 != V_84 )
{
if ( V_3 -> V_85 )
V_1 = V_3 -> V_85 ( V_3 , & V_79 , V_4 ) ;
else
V_1 = F_35 ( V_3 , & V_79 , & V_80 , V_4 ) ;
if( ! V_1 )
{
V_3 -> error = V_86 ;
V_1 = V_3 -> V_18 ( 0 , V_3 ) ;
goto V_87;
}
V_3 -> V_88 = V_79 ;
V_1 = V_3 -> V_89 ( V_3 , V_79 ) ;
if ( ! V_1 )
goto V_87;
if ( V_80 )
{
V_1 = V_3 -> V_89 ( V_3 , V_80 ) ;
if ( ! V_1 )
goto V_87;
V_1 = V_3 -> V_90 ( V_3 , V_80 , V_4 ) ;
if ( ! V_1 )
goto V_87;
}
else
V_1 = 1 ;
if ( V_1 != 2 )
{
V_1 = V_3 -> V_90 ( V_3 , V_79 , V_4 ) ;
if ( ! V_1 )
goto V_87;
}
F_36 ( V_79 ) ;
F_36 ( V_80 ) ;
V_79 = NULL ;
V_80 = NULL ;
}
V_87:
F_36 ( V_79 ) ;
F_36 ( V_80 ) ;
V_3 -> V_88 = NULL ;
return V_1 ;
}
static int F_37 ( T_1 * V_3 , T_5 * V_79 , int V_91 )
{
T_6 * V_92 ;
int V_10 ;
if ( V_91 )
V_3 -> V_88 = V_79 ;
if ( V_3 -> V_8 -> V_37 & V_93 )
V_92 = & V_3 -> V_8 -> V_94 ;
else
V_92 = NULL ;
V_10 = F_38 ( F_39 ( V_79 ) , V_92 ) ;
if ( V_10 == 0 )
{
if ( ! V_91 )
return 0 ;
V_3 -> error = V_95 ;
if ( ! V_3 -> V_18 ( 0 , V_3 ) )
return 0 ;
}
if ( V_10 > 0 )
{
if ( ! V_91 )
return 0 ;
V_3 -> error = V_96 ;
if ( ! V_3 -> V_18 ( 0 , V_3 ) )
return 0 ;
}
if( F_40 ( V_79 ) )
{
V_10 = F_38 ( F_40 ( V_79 ) , V_92 ) ;
if ( V_10 == 0 )
{
if ( ! V_91 )
return 0 ;
V_3 -> error = V_97 ;
if ( ! V_3 -> V_18 ( 0 , V_3 ) )
return 0 ;
}
if ( ( V_10 < 0 ) && ! ( V_3 -> V_82 & V_98 ) )
{
if ( ! V_91 )
return 0 ;
V_3 -> error = V_99 ;
if ( ! V_3 -> V_18 ( 0 , V_3 ) )
return 0 ;
}
}
if ( V_91 )
V_3 -> V_88 = NULL ;
return 1 ;
}
static int F_41 ( T_5 * V_100 , T_5 * V_101 , int V_102 )
{
T_7 * V_103 , * V_104 ;
int V_10 ;
V_10 = F_42 ( V_100 , V_102 , 0 ) ;
if ( V_10 >= 0 )
{
if ( F_42 ( V_100 , V_102 , V_10 ) != - 1 )
return 0 ;
V_103 = F_43 ( F_44 ( V_100 , V_10 ) ) ;
}
else
V_103 = NULL ;
V_10 = F_42 ( V_101 , V_102 , 0 ) ;
if ( V_10 >= 0 )
{
if ( F_42 ( V_101 , V_102 , V_10 ) != - 1 )
return 0 ;
V_104 = F_43 ( F_44 ( V_101 , V_10 ) ) ;
}
else
V_104 = NULL ;
if ( ! V_103 && ! V_104 )
return 1 ;
if ( ! V_103 || ! V_104 )
return 0 ;
if ( F_45 ( V_103 , V_104 ) )
return 0 ;
return 1 ;
}
static int F_46 ( T_5 * V_105 , T_5 * V_106 )
{
if ( ! V_105 -> V_107 )
return 0 ;
if ( ! V_106 -> V_108 )
return 0 ;
if ( F_47 ( F_48 ( V_106 ) ,
F_48 ( V_105 ) ) )
return 0 ;
if ( ! F_41 ( V_105 , V_106 , V_109 ) )
return 0 ;
if ( ! F_41 ( V_105 , V_106 , V_110 ) )
return 0 ;
if ( F_49 ( V_105 -> V_107 , V_106 -> V_108 ) > 0 )
return 0 ;
if ( F_49 ( V_105 -> V_108 , V_106 -> V_108 ) > 0 )
return 1 ;
return 0 ;
}
static int F_50 ( T_1 * V_3 , T_2 * * V_111 ,
unsigned int * V_112 ,
T_5 * V_79 , T_2 * V_4 )
{
int V_113 = 0 ;
unsigned int V_114 = * V_112 , V_115 ;
if ( V_79 -> V_116 & V_117 )
return 0 ;
if ( ! ( V_3 -> V_8 -> V_37 & V_118 ) )
{
if ( V_79 -> V_116 & ( V_119 | V_120 ) )
return 0 ;
}
else if ( V_79 -> V_116 & V_120 )
{
if ( ! ( V_79 -> V_121 & ~ V_114 ) )
return 0 ;
}
else if ( V_79 -> V_107 )
return 0 ;
if ( F_47 ( F_51 ( V_4 ) , F_48 ( V_79 ) ) )
{
if ( ! ( V_79 -> V_116 & V_119 ) )
return 0 ;
}
else
V_113 |= V_122 ;
if ( ! ( V_79 -> V_37 & V_56 ) )
V_113 |= V_123 ;
if ( F_37 ( V_3 , V_79 , 0 ) )
V_113 |= V_124 ;
F_52 ( V_3 , V_79 , V_111 , & V_113 ) ;
if ( ! ( V_113 & V_125 ) )
return 0 ;
if ( F_53 ( V_4 , V_79 , V_113 , & V_115 ) )
{
if ( ! ( V_115 & ~ V_114 ) )
return 0 ;
V_114 |= V_115 ;
V_113 |= V_126 ;
}
* V_112 = V_114 ;
return V_113 ;
}
static void F_52 ( T_1 * V_3 , T_5 * V_79 ,
T_2 * * V_111 , int * V_127 )
{
T_2 * V_128 = NULL ;
T_8 * V_129 = F_48 ( V_79 ) ;
int V_130 = V_3 -> V_30 ;
int V_10 ;
if ( V_130 != F_10 ( V_3 -> V_19 ) - 1 )
V_130 ++ ;
V_128 = F_11 ( V_3 -> V_19 , V_130 ) ;
if ( F_54 ( V_128 , V_79 -> V_131 ) == V_42 )
{
if ( * V_127 & V_122 )
{
* V_127 |= V_125 | V_132 ;
* V_111 = V_128 ;
return;
}
}
for ( V_130 ++ ; V_130 < F_10 ( V_3 -> V_19 ) ; V_130 ++ )
{
V_128 = F_11 ( V_3 -> V_19 , V_130 ) ;
if ( F_47 ( F_55 ( V_128 ) , V_129 ) )
continue;
if ( F_54 ( V_128 , V_79 -> V_131 ) == V_42 )
{
* V_127 |= V_125 | V_133 ;
* V_111 = V_128 ;
return;
}
}
if ( ! ( V_3 -> V_8 -> V_37 & V_118 ) )
return;
for ( V_10 = 0 ; V_10 < F_10 ( V_3 -> V_25 ) ; V_10 ++ )
{
V_128 = F_11 ( V_3 -> V_25 , V_10 ) ;
if ( F_47 ( F_55 ( V_128 ) , V_129 ) )
continue;
if ( F_54 ( V_128 , V_79 -> V_131 ) == V_42 )
{
* V_111 = V_128 ;
* V_127 |= V_125 ;
return;
}
}
}
static int F_56 ( T_1 * V_3 , T_2 * V_4 )
{
T_1 V_134 ;
int V_41 ;
if ( V_3 -> V_51 )
return 0 ;
if ( ! F_57 ( & V_134 , V_3 -> V_3 , V_4 , V_3 -> V_25 ) )
return - 1 ;
V_134 . V_135 = V_3 -> V_135 ;
F_58 ( & V_134 , V_3 -> V_8 ) ;
V_134 . V_51 = V_3 ;
V_134 . V_18 = V_3 -> V_18 ;
V_41 = F_2 ( & V_134 ) ;
if ( V_41 <= 0 )
goto V_87;
V_41 = F_59 ( V_3 , V_3 -> V_19 , V_134 . V_19 ) ;
V_87:
F_60 ( & V_134 ) ;
return V_41 ;
}
static int F_61 ( T_9 * V_100 , T_9 * V_101 )
{
T_8 * V_136 = NULL ;
T_10 * V_137 = NULL ;
T_11 * V_138 , * V_139 ;
int V_10 , V_69 ;
if ( ! V_100 || ! V_101 )
return 1 ;
if ( V_100 -> type == 1 )
{
if ( ! V_100 -> V_140 )
return 0 ;
if ( V_101 -> type == 1 )
{
if ( ! V_101 -> V_140 )
return 0 ;
if ( ! F_47 ( V_100 -> V_140 , V_101 -> V_140 ) )
return 1 ;
else
return 0 ;
}
V_136 = V_100 -> V_140 ;
V_137 = V_101 -> V_141 . V_142 ;
}
else if ( V_101 -> type == 1 )
{
if ( ! V_101 -> V_140 )
return 0 ;
V_137 = V_100 -> V_141 . V_142 ;
V_136 = V_101 -> V_140 ;
}
if ( V_136 )
{
for ( V_10 = 0 ; V_10 < F_62 ( V_137 ) ; V_10 ++ )
{
V_138 = F_63 ( V_137 , V_10 ) ;
if ( V_138 -> type != V_143 )
continue;
if ( ! F_47 ( V_136 , V_138 -> V_144 . V_145 ) )
return 1 ;
}
return 0 ;
}
for ( V_10 = 0 ; V_10 < F_62 ( V_100 -> V_141 . V_142 ) ; V_10 ++ )
{
V_138 = F_63 ( V_100 -> V_141 . V_142 , V_10 ) ;
for ( V_69 = 0 ; V_69 < F_62 ( V_101 -> V_141 . V_142 ) ; V_69 ++ )
{
V_139 = F_63 ( V_101 -> V_141 . V_142 , V_69 ) ;
if ( ! F_64 ( V_138 , V_139 ) )
return 1 ;
}
}
return 0 ;
}
static int F_65 ( T_12 * V_146 , T_5 * V_79 , int V_113 )
{
int V_10 ;
T_8 * V_136 = F_48 ( V_79 ) ;
if ( ! V_146 -> V_147 )
return ! ! ( V_113 & V_122 ) ;
for ( V_10 = 0 ; V_10 < F_62 ( V_146 -> V_147 ) ; V_10 ++ )
{
T_11 * V_148 = F_63 ( V_146 -> V_147 , V_10 ) ;
if ( V_148 -> type != V_143 )
continue;
if ( ! F_47 ( V_148 -> V_144 . V_145 , V_136 ) )
return 1 ;
}
return 0 ;
}
static int F_53 ( T_2 * V_4 , T_5 * V_79 , int V_113 ,
unsigned int * V_112 )
{
int V_10 ;
if ( V_79 -> V_116 & V_149 )
return 0 ;
if ( V_4 -> V_55 & V_150 )
{
if ( V_79 -> V_116 & V_151 )
return 0 ;
}
else
{
if ( V_79 -> V_116 & V_152 )
return 0 ;
}
* V_112 = V_79 -> V_121 ;
for ( V_10 = 0 ; V_10 < F_66 ( V_4 -> V_153 ) ; V_10 ++ )
{
T_12 * V_146 = F_67 ( V_4 -> V_153 , V_10 ) ;
if ( F_65 ( V_146 , V_79 , V_113 ) )
{
if ( ! V_79 -> V_154 ||
F_61 ( V_146 -> V_155 , V_79 -> V_154 -> V_155 ) )
{
* V_112 &= V_146 -> V_156 ;
return 1 ;
}
}
}
if ( ( ! V_79 -> V_154 || ! V_79 -> V_154 -> V_155 ) && ( V_113 & V_122 ) )
return 1 ;
return 0 ;
}
static int F_35 ( T_1 * V_3 ,
T_5 * * V_157 , T_5 * * V_158 , T_2 * V_4 )
{
int V_1 ;
T_2 * V_40 = NULL ;
int V_113 = 0 ;
unsigned int V_159 ;
T_5 * V_79 = NULL , * V_80 = NULL ;
F_4 ( T_5 ) * V_160 ;
T_8 * V_136 = F_51 ( V_4 ) ;
V_159 = V_3 -> V_83 ;
V_1 = F_68 ( V_3 , & V_79 , & V_80 ,
& V_40 , & V_113 , & V_159 , V_3 -> V_135 ) ;
if ( V_1 )
goto V_161;
V_160 = V_3 -> V_162 ( V_3 , V_136 ) ;
if ( ! V_160 && V_79 )
goto V_161;
F_68 ( V_3 , & V_79 , & V_80 , & V_40 , & V_113 , & V_159 , V_160 ) ;
F_69 ( V_160 , F_36 ) ;
V_161:
if ( V_79 )
{
V_3 -> V_44 = V_40 ;
V_3 -> V_82 = V_113 ;
V_3 -> V_83 = V_159 ;
* V_157 = V_79 ;
* V_158 = V_80 ;
return 1 ;
}
return 0 ;
}
static int V_89 ( T_1 * V_3 , T_5 * V_79 )
{
T_2 * V_40 = NULL ;
T_13 * V_163 = NULL ;
int V_1 = 0 , V_164 , V_81 ;
V_81 = V_3 -> V_30 ;
V_164 = F_10 ( V_3 -> V_19 ) - 1 ;
if ( V_3 -> V_44 )
V_40 = V_3 -> V_44 ;
else if ( V_81 < V_164 )
V_40 = F_11 ( V_3 -> V_19 , V_81 + 1 ) ;
else
{
V_40 = F_11 ( V_3 -> V_19 , V_164 ) ;
if( ! V_3 -> V_26 ( V_3 , V_40 , V_40 ) )
{
V_3 -> error = V_165 ;
V_1 = V_3 -> V_18 ( 0 , V_3 ) ;
if( ! V_1 ) goto V_87;
}
}
if( V_40 )
{
if ( ! V_79 -> V_107 )
{
if ( ( V_40 -> V_55 & V_166 ) &&
! ( V_40 -> V_167 & V_168 ) )
{
V_3 -> error = V_169 ;
V_1 = V_3 -> V_18 ( 0 , V_3 ) ;
if( ! V_1 ) goto V_87;
}
if ( ! ( V_3 -> V_82 & V_126 ) )
{
V_3 -> error = V_170 ;
V_1 = V_3 -> V_18 ( 0 , V_3 ) ;
if( ! V_1 ) goto V_87;
}
if ( ! ( V_3 -> V_82 & V_133 ) )
{
if ( F_56 ( V_3 , V_3 -> V_44 ) <= 0 )
{
V_3 -> error = V_171 ;
V_1 = V_3 -> V_18 ( 0 , V_3 ) ;
if( ! V_1 ) goto V_87;
}
}
if ( V_79 -> V_116 & V_117 )
{
V_3 -> error = V_172 ;
V_1 = V_3 -> V_18 ( 0 , V_3 ) ;
if( ! V_1 ) goto V_87;
}
}
if ( ! ( V_3 -> V_82 & V_124 ) )
{
V_1 = F_37 ( V_3 , V_79 , 1 ) ;
if ( ! V_1 )
goto V_87;
}
V_163 = F_70 ( V_40 ) ;
if( ! V_163 )
{
V_3 -> error = V_173 ;
V_1 = V_3 -> V_18 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_87;
}
else
{
if( F_71 ( V_79 , V_163 ) <= 0 )
{
V_3 -> error = V_174 ;
V_1 = V_3 -> V_18 ( 0 , V_3 ) ;
if ( ! V_1 ) goto V_87;
}
}
}
V_1 = 1 ;
V_87:
F_72 ( V_163 ) ;
return V_1 ;
}
static int V_90 ( T_1 * V_3 , T_5 * V_79 , T_2 * V_4 )
{
int V_1 ;
T_14 * V_175 ;
if ( V_79 -> V_37 & V_56 )
{
if ( V_3 -> V_8 -> V_37 & V_54 )
return 1 ;
V_3 -> error = V_176 ;
V_1 = V_3 -> V_18 ( 0 , V_3 ) ;
if( ! V_1 )
return 0 ;
}
if ( F_73 ( V_79 , & V_175 , V_4 ) )
{
if ( V_175 -> V_177 == V_178 )
return 2 ;
V_3 -> error = V_179 ;
V_1 = V_3 -> V_18 ( 0 , V_3 ) ;
if ( ! V_1 )
return 0 ;
}
return 1 ;
}
static int V_39 ( T_1 * V_3 )
{
int V_41 ;
if ( V_3 -> V_51 )
return 1 ;
V_41 = F_74 ( & V_3 -> V_180 , & V_3 -> V_181 , V_3 -> V_19 ,
V_3 -> V_8 -> V_182 , V_3 -> V_8 -> V_37 ) ;
if ( V_41 == 0 )
{
F_5 ( V_183 , V_20 ) ;
return 0 ;
}
if ( V_41 == - 1 )
{
T_2 * V_4 ;
int V_10 ;
for ( V_10 = 1 ; V_10 < F_10 ( V_3 -> V_19 ) ; V_10 ++ )
{
V_4 = F_11 ( V_3 -> V_19 , V_10 ) ;
if ( ! ( V_4 -> V_55 & V_184 ) )
continue;
V_3 -> V_29 = V_4 ;
V_3 -> error = V_185 ;
if( ! V_3 -> V_18 ( 0 , V_3 ) )
return 0 ;
}
return 1 ;
}
if ( V_41 == - 2 )
{
V_3 -> V_29 = NULL ;
V_3 -> error = V_186 ;
return V_3 -> V_18 ( 0 , V_3 ) ;
}
if ( V_3 -> V_8 -> V_37 & V_187 )
{
V_3 -> V_29 = NULL ;
V_3 -> error = V_42 ;
if ( ! V_3 -> V_18 ( 2 , V_3 ) )
return 0 ;
}
return 1 ;
}
static int F_75 ( T_1 * V_3 , T_2 * V_4 )
{
T_6 * V_92 ;
int V_10 ;
if ( V_3 -> V_8 -> V_37 & V_93 )
V_92 = & V_3 -> V_8 -> V_94 ;
else
V_92 = NULL ;
V_10 = F_38 ( F_76 ( V_4 ) , V_92 ) ;
if ( V_10 == 0 )
{
V_3 -> error = V_188 ;
V_3 -> V_29 = V_4 ;
if ( ! V_3 -> V_18 ( 0 , V_3 ) )
return 0 ;
}
if ( V_10 > 0 )
{
V_3 -> error = V_189 ;
V_3 -> V_29 = V_4 ;
if ( ! V_3 -> V_18 ( 0 , V_3 ) )
return 0 ;
}
V_10 = F_38 ( F_77 ( V_4 ) , V_92 ) ;
if ( V_10 == 0 )
{
V_3 -> error = V_190 ;
V_3 -> V_29 = V_4 ;
if ( ! V_3 -> V_18 ( 0 , V_3 ) )
return 0 ;
}
if ( V_10 < 0 )
{
V_3 -> error = V_191 ;
V_3 -> V_29 = V_4 ;
if ( ! V_3 -> V_18 ( 0 , V_3 ) )
return 0 ;
}
return 1 ;
}
static int F_22 ( T_1 * V_3 )
{
int V_1 = 0 , V_192 ;
T_2 * V_193 , * V_194 ;
T_13 * V_195 = NULL ;
int (* F_3)( int V_12 , T_1 * V_13 );
F_3 = V_3 -> V_18 ;
V_192 = F_10 ( V_3 -> V_19 ) ;
V_3 -> V_30 = V_192 - 1 ;
V_192 -- ;
V_194 = F_11 ( V_3 -> V_19 , V_192 ) ;
if ( V_3 -> V_26 ( V_3 , V_194 , V_194 ) )
V_193 = V_194 ;
else
{
if ( V_192 <= 0 )
{
V_3 -> error = V_196 ;
V_3 -> V_29 = V_194 ;
V_1 = F_3 ( 0 , V_3 ) ;
goto V_21;
}
else
{
V_192 -- ;
V_3 -> V_30 = V_192 ;
V_193 = F_11 ( V_3 -> V_19 , V_192 ) ;
}
}
while ( V_192 >= 0 )
{
V_3 -> V_30 = V_192 ;
if ( ! V_193 -> V_197 && ( V_193 != V_194 || ( V_3 -> V_8 -> V_37 & V_198 ) ) )
{
if ( ( V_195 = F_70 ( V_194 ) ) == NULL )
{
V_3 -> error = V_173 ;
V_3 -> V_29 = V_194 ;
V_1 = (* F_3)( 0 , V_3 ) ;
if ( ! V_1 ) goto V_21;
}
else if ( F_78 ( V_193 , V_195 ) <= 0 )
{
V_3 -> error = V_199 ;
V_3 -> V_29 = V_193 ;
V_1 = (* F_3)( 0 , V_3 ) ;
if ( ! V_1 )
{
F_72 ( V_195 ) ;
goto V_21;
}
}
F_72 ( V_195 ) ;
V_195 = NULL ;
}
V_193 -> V_197 = 1 ;
V_1 = F_75 ( V_3 , V_193 ) ;
if ( ! V_1 )
goto V_21;
V_3 -> V_44 = V_194 ;
V_3 -> V_29 = V_193 ;
V_1 = (* F_3)( 1 , V_3 ) ;
if ( ! V_1 ) goto V_21;
V_192 -- ;
if ( V_192 >= 0 )
{
V_194 = V_193 ;
V_193 = F_11 ( V_3 -> V_19 , V_192 ) ;
}
}
V_1 = 1 ;
V_21:
return V_1 ;
}
int F_79 ( const T_15 * V_200 )
{
return F_38 ( V_200 , NULL ) ;
}
int F_38 ( const T_15 * V_200 , T_6 * V_201 )
{
char * V_202 ;
T_15 V_203 ;
long V_204 ;
char V_205 [ 24 ] , V_206 [ 24 ] , * V_207 ;
int V_10 , V_69 ;
V_207 = V_205 ;
V_10 = V_200 -> V_208 ;
V_202 = ( char * ) V_200 -> V_209 ;
if ( V_200 -> type == V_210 )
{
if ( ( V_10 < 11 ) || ( V_10 > 17 ) ) return 0 ;
memcpy ( V_207 , V_202 , 10 ) ;
V_207 += 10 ;
V_202 += 10 ;
}
else
{
if ( V_10 < 13 ) return 0 ;
memcpy ( V_207 , V_202 , 12 ) ;
V_207 += 12 ;
V_202 += 12 ;
}
if ( ( * V_202 == 'Z' ) || ( * V_202 == '-' ) || ( * V_202 == '+' ) )
{ * ( V_207 ++ ) = '0' ; * ( V_207 ++ ) = '0' ; }
else
{
* ( V_207 ++ ) = * ( V_202 ++ ) ;
* ( V_207 ++ ) = * ( V_202 ++ ) ;
if ( * V_202 == '.' )
{
V_202 ++ ;
while ( ( * V_202 >= '0' ) && ( * V_202 <= '9' ) ) V_202 ++ ;
}
}
* ( V_207 ++ ) = 'Z' ;
* ( V_207 ++ ) = '\0' ;
if ( * V_202 == 'Z' )
V_204 = 0 ;
else
{
if ( ( * V_202 != '+' ) && ( * V_202 != '-' ) )
return 0 ;
V_204 = ( ( V_202 [ 1 ] - '0' ) * 10 + ( V_202 [ 2 ] - '0' ) ) * 60 ;
V_204 += ( V_202 [ 3 ] - '0' ) * 10 + ( V_202 [ 4 ] - '0' ) ;
if ( * V_202 == '-' )
V_204 = - V_204 ;
}
V_203 . type = V_200 -> type ;
V_203 . V_37 = 0 ;
V_203 . V_208 = sizeof( V_206 ) ;
V_203 . V_209 = ( unsigned char * ) V_206 ;
if ( F_80 ( & V_203 , V_204 * 60 , V_201 ) == NULL )
return 0 ;
if ( V_200 -> type == V_210 )
{
V_10 = ( V_205 [ 0 ] - '0' ) * 10 + ( V_205 [ 1 ] - '0' ) ;
if ( V_10 < 50 ) V_10 += 100 ;
V_69 = ( V_206 [ 0 ] - '0' ) * 10 + ( V_206 [ 1 ] - '0' ) ;
if ( V_69 < 50 ) V_69 += 100 ;
if ( V_10 < V_69 ) return - 1 ;
if ( V_10 > V_69 ) return 1 ;
}
V_10 = strcmp ( V_205 , V_206 ) ;
if ( V_10 == 0 )
return - 1 ;
else
return V_10 ;
}
T_15 * F_81 ( T_15 * V_211 , long V_212 )
{
return F_80 ( V_211 , V_212 , NULL ) ;
}
T_15 * F_80 ( T_15 * V_211 , long V_213 , T_6 * V_214 )
{
return F_82 ( V_211 , 0 , V_213 , V_214 ) ;
}
T_15 * F_82 ( T_15 * V_211 ,
int V_215 , long V_213 , T_6 * V_214 )
{
T_6 V_216 ;
if ( V_214 ) V_216 = * V_214 ;
else time ( & V_216 ) ;
if ( V_211 && ! ( V_211 -> V_37 & V_217 ) )
{
if ( V_211 -> type == V_210 )
return F_83 ( V_211 , V_216 , V_215 , V_213 ) ;
if ( V_211 -> type == V_218 )
return F_84 ( V_211 , V_216 , V_215 ,
V_213 ) ;
}
return F_85 ( V_211 , V_216 , V_215 , V_213 ) ;
}
int F_86 ( long V_219 , void * V_220 , T_16 * V_221 ,
T_17 * V_222 , T_18 * V_223 )
{
return F_87 ( V_224 , V_219 , V_220 ,
V_221 , V_222 , V_223 ) ;
}
int F_88 ( T_1 * V_3 , int V_225 , void * V_209 )
{
return F_89 ( & V_3 -> V_226 , V_225 , V_209 ) ;
}
void * F_90 ( T_1 * V_3 , int V_225 )
{
return F_91 ( & V_3 -> V_226 , V_225 ) ;
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
return V_3 -> V_30 ;
}
T_2 * F_95 ( T_1 * V_3 )
{
return V_3 -> V_29 ;
}
T_5 * F_96 ( T_1 * V_3 )
{
return V_3 -> V_88 ;
}
T_1 * F_97 ( T_1 * V_3 )
{
return V_3 -> V_51 ;
}
void F_98 ( T_1 * V_3 , T_2 * V_4 )
{
V_3 -> V_15 = V_4 ;
}
int F_99 ( T_1 * V_3 , int V_49 )
{
return F_100 ( V_3 , 0 , V_49 , 0 ) ;
}
int F_101 ( T_1 * V_3 , int V_34 )
{
return F_100 ( V_3 , 0 , 0 , V_34 ) ;
}
int F_100 ( T_1 * V_3 , int V_227 ,
int V_49 , int V_34 )
{
int V_225 ;
if ( ! V_49 ) V_49 = V_227 ;
if ( V_49 )
{
T_19 * V_228 ;
V_225 = F_102 ( V_49 ) ;
if ( V_225 == - 1 )
{
F_5 ( V_229 ,
V_230 ) ;
return 0 ;
}
V_228 = F_103 ( V_225 ) ;
if ( V_228 -> V_34 == V_231 )
{
V_225 = F_102 ( V_227 ) ;
if ( V_225 == - 1 )
{
F_5 ( V_229 ,
V_230 ) ;
return 0 ;
}
V_228 = F_103 ( V_225 ) ;
}
if ( ! V_34 ) V_34 = V_228 -> V_34 ;
}
if ( V_34 )
{
V_225 = F_104 ( V_34 ) ;
if ( V_225 == - 1 )
{
F_5 ( V_229 ,
V_232 ) ;
return 0 ;
}
}
if ( V_49 && ! V_3 -> V_8 -> V_49 ) V_3 -> V_8 -> V_49 = V_49 ;
if ( V_34 && ! V_3 -> V_8 -> V_34 ) V_3 -> V_8 -> V_34 = V_34 ;
return 1 ;
}
T_1 * F_105 ( void )
{
T_1 * V_3 ;
V_3 = ( T_1 * ) F_106 ( sizeof( T_1 ) ) ;
if ( ! V_3 )
{
F_5 ( V_233 , V_20 ) ;
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
if ( V_3 -> V_234 ) V_3 -> V_234 ( V_3 ) ;
if ( V_3 -> V_8 != NULL )
{
if ( V_3 -> V_51 == NULL )
F_109 ( V_3 -> V_8 ) ;
V_3 -> V_8 = NULL ;
}
if ( V_3 -> V_180 != NULL )
{
F_110 ( V_3 -> V_180 ) ;
V_3 -> V_180 = NULL ;
}
if ( V_3 -> V_19 != NULL )
{
F_111 ( V_3 -> V_19 , F_15 ) ;
V_3 -> V_19 = NULL ;
}
F_112 ( V_224 , V_3 , & ( V_3 -> V_226 ) ) ;
memset ( & V_3 -> V_226 , 0 , sizeof( V_235 ) ) ;
}
void F_113 ( T_1 * V_3 , int V_9 )
{
F_114 ( V_3 -> V_8 , V_9 ) ;
}
void F_115 ( T_1 * V_3 , unsigned long V_37 )
{
F_116 ( V_3 -> V_8 , V_37 ) ;
}
void F_117 ( T_1 * V_3 , unsigned long V_37 , T_6 V_216 )
{
F_118 ( V_3 -> V_8 , V_216 ) ;
}
void F_119 ( T_1 * V_3 ,
int (* V_18)( int , T_1 * ) )
{
V_3 -> V_18 = V_18 ;
}
T_20 * F_120 ( T_1 * V_3 )
{
return V_3 -> V_180 ;
}
int F_121 ( T_1 * V_3 )
{
return V_3 -> V_181 ;
}
int F_122 ( T_1 * V_3 , const char * V_141 )
{
const T_3 * V_8 ;
V_8 = F_123 ( V_141 ) ;
if ( ! V_8 )
return 0 ;
return F_124 ( V_3 -> V_8 , V_8 ) ;
}
T_3 * F_125 ( T_1 * V_3 )
{
return V_3 -> V_8 ;
}
void F_58 ( T_1 * V_3 , T_3 * V_8 )
{
if ( V_3 -> V_8 )
F_109 ( V_3 -> V_8 ) ;
V_3 -> V_8 = V_8 ;
}
