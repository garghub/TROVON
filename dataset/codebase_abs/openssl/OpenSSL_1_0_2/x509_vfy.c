static int F_1 ( int V_1 , T_1 * V_2 )
{
return V_1 ;
}
static int F_2 ( T_2 * V_3 )
{
F_3 ( V_3 , - 1 , 0 ) ;
if ( V_3 -> V_4 & V_5 )
return 1 ;
else
return 0 ;
}
static T_2 * F_4 ( T_1 * V_6 , T_2 * V_3 )
{
F_5 ( T_2 ) * V_7 ;
T_2 * V_8 = NULL ;
int V_9 ;
V_7 = V_6 -> V_10 ( V_6 , F_6 ( V_3 ) ) ;
if ( V_7 == NULL )
return NULL ;
for ( V_9 = 0 ; V_9 < F_7 ( V_7 ) ; V_9 ++ ) {
V_8 = F_8 ( V_7 , V_9 ) ;
if ( ! F_9 ( V_8 , V_3 ) )
break;
}
if ( V_9 < F_7 ( V_7 ) )
F_10 ( & V_8 -> V_11 , 1 , V_12 ) ;
else
V_8 = NULL ;
F_11 ( V_7 , V_13 ) ;
return V_8 ;
}
int F_12 ( T_1 * V_6 )
{
T_2 * V_3 , * V_8 , * V_14 = NULL ;
int V_15 = 0 ;
T_3 * V_16 = V_6 -> V_16 ;
int V_17 , V_9 , V_1 = 0 ;
int V_18 ;
int (* F_13) ( int V_19 , T_1 * V_20 );
F_5 ( T_2 ) * V_21 = NULL ;
if ( V_6 -> V_22 == NULL ) {
F_14 ( V_23 , V_24 ) ;
return - 1 ;
}
F_13 = V_6 -> V_25 ;
if ( V_6 -> V_26 == NULL ) {
if ( ( ( V_6 -> V_26 = F_15 () ) == NULL ) ||
( ! F_16 ( V_6 -> V_26 , V_6 -> V_22 ) ) ) {
F_14 ( V_23 , V_27 ) ;
goto V_28;
}
F_10 ( & V_6 -> V_22 -> V_11 , 1 , V_12 ) ;
V_6 -> V_29 = 1 ;
}
if ( V_6 -> V_30 != NULL
&& ( V_21 = F_17 ( V_6 -> V_30 ) ) == NULL ) {
F_14 ( V_23 , V_27 ) ;
goto V_28;
}
V_18 = F_7 ( V_6 -> V_26 ) ;
V_3 = F_8 ( V_6 -> V_26 , V_18 - 1 ) ;
V_17 = V_16 -> V_17 ;
for (; ; ) {
if ( V_17 < V_18 )
break;
if ( F_2 ( V_3 ) )
break;
if ( V_6 -> V_16 -> V_31 & V_32 ) {
V_1 = V_6 -> V_33 ( & V_8 , V_6 , V_3 ) ;
if ( V_1 < 0 )
return V_1 ;
if ( V_1 > 0 ) {
V_13 ( V_8 ) ;
break;
}
}
if ( V_6 -> V_30 != NULL ) {
V_8 = F_18 ( V_6 , V_21 , V_3 ) ;
if ( V_8 != NULL ) {
if ( ! F_16 ( V_6 -> V_26 , V_8 ) ) {
F_14 ( V_23 , V_27 ) ;
goto V_28;
}
F_10 ( & V_8 -> V_11 , 1 , V_12 ) ;
( void ) F_19 ( V_21 , V_8 ) ;
V_6 -> V_29 ++ ;
V_3 = V_8 ;
V_18 ++ ;
continue;
}
}
break;
}
V_9 = F_7 ( V_6 -> V_26 ) ;
V_3 = F_8 ( V_6 -> V_26 , V_9 - 1 ) ;
if ( F_2 ( V_3 ) ) {
if ( F_7 ( V_6 -> V_26 ) == 1 ) {
V_1 = V_6 -> V_33 ( & V_8 , V_6 , V_3 ) ;
if ( ( V_1 <= 0 ) || F_9 ( V_3 , V_8 ) ) {
V_6 -> error = V_34 ;
V_6 -> V_35 = V_3 ;
V_6 -> V_36 = V_9 - 1 ;
if ( V_1 == 1 )
V_13 ( V_8 ) ;
V_15 = 1 ;
V_1 = F_13 ( 0 , V_6 ) ;
if ( ! V_1 )
goto V_28;
} else {
V_13 ( V_3 ) ;
V_3 = V_8 ;
( void ) F_20 ( V_6 -> V_26 , V_9 - 1 , V_3 ) ;
V_6 -> V_29 = 0 ;
}
} else {
V_14 = F_21 ( V_6 -> V_26 ) ;
V_6 -> V_29 -- ;
V_18 -- ;
V_3 = F_8 ( V_6 -> V_26 , V_18 - 1 ) ;
}
}
for (; ; ) {
if ( V_17 < V_18 )
break;
if ( F_2 ( V_3 ) )
break;
V_1 = V_6 -> V_33 ( & V_8 , V_6 , V_3 ) ;
if ( V_1 < 0 )
return V_1 ;
if ( V_1 == 0 )
break;
V_3 = V_8 ;
if ( ! F_16 ( V_6 -> V_26 , V_3 ) ) {
V_13 ( V_8 ) ;
F_14 ( V_23 , V_27 ) ;
return 0 ;
}
V_18 ++ ;
}
V_9 = F_22 ( V_6 ) ;
if ( V_9 == V_37 )
goto V_28;
if ( V_9 != V_38 && ! V_15 ) {
if ( ( V_14 == NULL ) || ! V_6 -> V_39 ( V_6 , V_3 , V_14 ) ) {
if ( V_6 -> V_29 >= V_18 )
V_6 -> error = V_40 ;
else
V_6 -> error = V_41 ;
V_6 -> V_35 = V_3 ;
} else {
F_16 ( V_6 -> V_26 , V_14 ) ;
V_18 ++ ;
V_6 -> V_29 = V_18 ;
V_6 -> V_35 = V_14 ;
V_6 -> error = V_42 ;
V_14 = NULL ;
}
V_6 -> V_36 = V_18 - 1 ;
V_15 = 1 ;
V_1 = F_13 ( 0 , V_6 ) ;
if ( ! V_1 )
goto V_28;
}
V_1 = F_23 ( V_6 ) ;
if ( ! V_1 )
goto V_28;
V_1 = F_24 ( V_6 ) ;
if ( ! V_1 )
goto V_28;
V_1 = F_25 ( V_6 ) ;
if ( ! V_1 )
goto V_28;
F_26 ( NULL , V_6 -> V_26 ) ;
V_1 = V_6 -> V_43 ( V_6 ) ;
if ( ! V_1 )
goto V_28;
V_9 = F_27 ( & V_6 -> V_36 , NULL , V_6 -> V_26 ,
V_6 -> V_16 -> V_31 ) ;
if ( V_9 != V_44 ) {
V_6 -> error = V_9 ;
V_6 -> V_35 = F_8 ( V_6 -> V_26 , V_6 -> V_36 ) ;
V_1 = F_13 ( 0 , V_6 ) ;
if ( ! V_1 )
goto V_28;
}
if ( V_6 -> V_45 != NULL )
V_1 = V_6 -> V_45 ( V_6 ) ;
else
V_1 = F_28 ( V_6 ) ;
if ( ! V_1 )
goto V_28;
#ifndef F_29
V_1 = F_30 ( V_6 ) ;
if ( ! V_1 )
goto V_28;
V_1 = F_31 ( V_6 ) ;
if ( ! V_1 )
goto V_28;
#endif
if ( ! V_15 && ( V_6 -> V_16 -> V_31 & V_46 ) )
V_1 = V_6 -> V_47 ( V_6 ) ;
if ( ! V_1 )
goto V_28;
if ( 0 ) {
V_28:
F_26 ( NULL , V_6 -> V_26 ) ;
}
if ( V_21 != NULL )
F_32 ( V_21 ) ;
if ( V_14 != NULL )
V_13 ( V_14 ) ;
return V_1 ;
}
static int V_39 ( T_1 * V_6 , T_2 * V_3 , T_2 * V_48 )
{
int V_49 ;
V_49 = F_33 ( V_48 , V_3 ) ;
if ( V_49 == V_44 )
return 1 ;
if ( ! ( V_6 -> V_16 -> V_31 & V_50 ) )
return 0 ;
V_6 -> error = V_49 ;
V_6 -> V_35 = V_3 ;
V_6 -> V_51 = V_48 ;
return V_6 -> V_25 ( 0 , V_6 ) ;
}
static int F_34 ( T_2 * * V_48 , T_1 * V_6 , T_2 * V_3 )
{
* V_48 = F_18 ( V_6 , V_6 -> V_52 , V_3 ) ;
if ( * V_48 ) {
F_10 ( & ( * V_48 ) -> V_11 , 1 , V_12 ) ;
return 1 ;
} else
return 0 ;
}
static int F_23 ( T_1 * V_6 )
{
#ifdef F_35
return 1 ;
#else
int V_9 , V_1 = 0 , V_53 , V_54 = 0 ;
T_2 * V_3 ;
int (* F_13) ( int V_19 , T_1 * V_20 );
int V_55 = 0 ;
int V_56 ;
int V_57 ;
F_13 = V_6 -> V_25 ;
V_53 = - 1 ;
if ( V_6 -> V_58 ) {
V_57 = 0 ;
V_56 = V_59 ;
} else {
V_57 =
! ! ( V_6 -> V_16 -> V_31 & V_60 ) ;
if ( getenv ( L_1 ) )
V_57 = 1 ;
V_56 = V_6 -> V_16 -> V_56 ;
}
for ( V_9 = 0 ; V_9 < V_6 -> V_29 ; V_9 ++ ) {
int V_49 ;
V_3 = F_8 ( V_6 -> V_26 , V_9 ) ;
if ( ! ( V_6 -> V_16 -> V_31 & V_61 )
&& ( V_3 -> V_4 & V_62 ) ) {
V_6 -> error = V_63 ;
V_6 -> V_36 = V_9 ;
V_6 -> V_35 = V_3 ;
V_1 = F_13 ( 0 , V_6 ) ;
if ( ! V_1 )
goto V_28;
}
if ( ! V_57 && ( V_3 -> V_4 & V_64 ) ) {
V_6 -> error = V_65 ;
V_6 -> V_36 = V_9 ;
V_6 -> V_35 = V_3 ;
V_1 = F_13 ( 0 , V_6 ) ;
if ( ! V_1 )
goto V_28;
}
V_49 = F_36 ( V_3 ) ;
switch ( V_53 ) {
case - 1 :
if ( ( V_6 -> V_16 -> V_31 & V_66 )
&& ( V_49 != 1 ) && ( V_49 != 0 ) ) {
V_49 = 0 ;
V_6 -> error = V_67 ;
} else
V_49 = 1 ;
break;
case 0 :
if ( V_49 != 0 ) {
V_49 = 0 ;
V_6 -> error = V_68 ;
} else
V_49 = 1 ;
break;
default:
if ( ( V_49 == 0 )
|| ( ( V_6 -> V_16 -> V_31 & V_66 )
&& ( V_49 != 1 ) ) ) {
V_49 = 0 ;
V_6 -> error = V_67 ;
} else
V_49 = 1 ;
break;
}
if ( V_49 == 0 ) {
V_6 -> V_36 = V_9 ;
V_6 -> V_35 = V_3 ;
V_1 = F_13 ( 0 , V_6 ) ;
if ( ! V_1 )
goto V_28;
}
if ( V_6 -> V_16 -> V_56 > 0 ) {
V_49 = F_3 ( V_3 , V_56 , V_53 > 0 ) ;
if ( ( V_49 == 0 )
|| ( ( V_6 -> V_16 -> V_31 & V_66 )
&& ( V_49 != 1 ) ) ) {
V_6 -> error = V_69 ;
V_6 -> V_36 = V_9 ;
V_6 -> V_35 = V_3 ;
V_1 = F_13 ( 0 , V_6 ) ;
if ( ! V_1 )
goto V_28;
}
}
if ( ( V_9 > 1 ) && ! ( V_3 -> V_4 & V_70 )
&& ( V_3 -> V_71 != - 1 )
&& ( V_54 > ( V_3 -> V_71 + V_55 + 1 ) ) ) {
V_6 -> error = V_72 ;
V_6 -> V_36 = V_9 ;
V_6 -> V_35 = V_3 ;
V_1 = F_13 ( 0 , V_6 ) ;
if ( ! V_1 )
goto V_28;
}
if ( ! ( V_3 -> V_4 & V_70 ) )
V_54 ++ ;
if ( V_3 -> V_4 & V_64 ) {
if ( V_3 -> V_73 != - 1 && V_9 > V_3 -> V_73 ) {
V_6 -> error = V_74 ;
V_6 -> V_36 = V_9 ;
V_6 -> V_35 = V_3 ;
V_1 = F_13 ( 0 , V_6 ) ;
if ( ! V_1 )
goto V_28;
}
V_55 ++ ;
V_53 = 0 ;
} else
V_53 = 1 ;
}
V_1 = 1 ;
V_28:
return V_1 ;
#endif
}
static int F_24 ( T_1 * V_6 )
{
T_2 * V_3 ;
int V_9 , V_75 , V_76 ;
for ( V_9 = F_7 ( V_6 -> V_26 ) - 1 ; V_9 >= 0 ; V_9 -- ) {
V_3 = F_8 ( V_6 -> V_26 , V_9 ) ;
if ( V_9 && ( V_3 -> V_4 & V_70 ) )
continue;
for ( V_75 = F_7 ( V_6 -> V_26 ) - 1 ; V_75 > V_9 ; V_75 -- ) {
T_4 * V_77 = F_8 ( V_6 -> V_26 , V_75 ) -> V_77 ;
if ( V_77 ) {
V_76 = F_37 ( V_3 , V_77 ) ;
if ( V_76 != V_44 ) {
V_6 -> error = V_76 ;
V_6 -> V_36 = V_9 ;
V_6 -> V_35 = V_3 ;
if ( ! V_6 -> V_25 ( 0 , V_6 ) )
return 0 ;
}
}
}
}
return 1 ;
}
static int F_38 ( T_1 * V_6 , int V_78 )
{
V_6 -> error = V_78 ;
V_6 -> V_35 = V_6 -> V_22 ;
V_6 -> V_36 = 0 ;
return V_6 -> V_25 ( 0 , V_6 ) ;
}
static int F_39 ( T_2 * V_3 , T_5 * V_79 )
{
int V_9 ;
int V_80 = F_40 ( V_79 -> V_81 ) ;
char * V_82 ;
for ( V_9 = 0 ; V_9 < V_80 ; ++ V_9 ) {
V_82 = F_41 ( V_79 -> V_81 , V_9 ) ;
if ( F_42 ( V_3 , V_82 , 0 , V_79 -> V_83 , & V_79 -> V_84 ) > 0 )
return 1 ;
}
return V_80 == 0 ;
}
static int F_25 ( T_1 * V_6 )
{
T_3 * V_85 = V_6 -> V_16 ;
T_5 * V_79 = V_85 -> V_79 ;
T_2 * V_3 = V_6 -> V_22 ;
if ( V_79 -> V_81 && F_39 ( V_3 , V_79 ) <= 0 ) {
if ( ! F_38 ( V_6 , V_86 ) )
return 0 ;
}
if ( V_79 -> V_87 && F_43 ( V_3 , V_79 -> V_87 , V_79 -> V_88 , 0 ) <= 0 ) {
if ( ! F_38 ( V_6 , V_89 ) )
return 0 ;
}
if ( V_79 -> V_90 && F_44 ( V_3 , V_79 -> V_90 , V_79 -> V_91 , 0 ) <= 0 ) {
if ( ! F_38 ( V_6 , V_92 ) )
return 0 ;
}
return 1 ;
}
static int F_22 ( T_1 * V_6 )
{
int V_9 , V_1 ;
T_2 * V_3 = NULL ;
int (* F_13) ( int V_19 , T_1 * V_20 );
F_13 = V_6 -> V_25 ;
for ( V_9 = V_6 -> V_29 ; V_9 < F_7 ( V_6 -> V_26 ) ; V_9 ++ ) {
V_3 = F_8 ( V_6 -> V_26 , V_9 ) ;
V_1 = F_45 ( V_3 , V_6 -> V_16 -> V_93 , 0 ) ;
if ( V_1 == V_38 )
return V_38 ;
if ( V_1 == V_37 ) {
V_6 -> V_36 = V_9 ;
V_6 -> V_35 = V_3 ;
V_6 -> error = V_94 ;
V_1 = F_13 ( 0 , V_6 ) ;
if ( ! V_1 )
return V_37 ;
}
}
if ( V_6 -> V_16 -> V_31 & V_95 ) {
T_2 * V_96 ;
if ( V_6 -> V_29 < F_7 ( V_6 -> V_26 ) )
return V_38 ;
V_3 = F_8 ( V_6 -> V_26 , 0 ) ;
V_96 = F_4 ( V_6 , V_3 ) ;
if ( V_96 ) {
( void ) F_20 ( V_6 -> V_26 , 0 , V_96 ) ;
V_13 ( V_3 ) ;
V_6 -> V_29 = 0 ;
return V_38 ;
}
}
return V_97 ;
}
static int V_43 ( T_1 * V_6 )
{
int V_9 , V_98 , V_1 ;
if ( ! ( V_6 -> V_16 -> V_31 & V_99 ) )
return 1 ;
if ( V_6 -> V_16 -> V_31 & V_100 )
V_98 = F_7 ( V_6 -> V_26 ) - 1 ;
else {
if ( V_6 -> V_58 )
return 1 ;
V_98 = 0 ;
}
for ( V_9 = 0 ; V_9 <= V_98 ; V_9 ++ ) {
V_6 -> V_36 = V_9 ;
V_1 = F_46 ( V_6 ) ;
if ( ! V_1 )
return V_1 ;
}
return 1 ;
}
static int F_46 ( T_1 * V_6 )
{
T_6 * V_101 = NULL , * V_102 = NULL ;
T_2 * V_3 ;
int V_1 , V_103 ;
unsigned int V_104 ;
V_103 = V_6 -> V_36 ;
V_3 = F_8 ( V_6 -> V_26 , V_103 ) ;
V_6 -> V_35 = V_3 ;
V_6 -> V_51 = NULL ;
V_6 -> V_105 = 0 ;
V_6 -> V_106 = 0 ;
while ( V_6 -> V_106 != V_107 ) {
V_104 = V_6 -> V_106 ;
if ( V_6 -> V_108 )
V_1 = V_6 -> V_108 ( V_6 , & V_101 , V_3 ) ;
else
V_1 = F_47 ( V_6 , & V_101 , & V_102 , V_3 ) ;
if ( ! V_1 ) {
V_6 -> error = V_109 ;
V_1 = V_6 -> V_25 ( 0 , V_6 ) ;
goto V_110;
}
V_6 -> V_111 = V_101 ;
V_1 = V_6 -> V_112 ( V_6 , V_101 ) ;
if ( ! V_1 )
goto V_110;
if ( V_102 ) {
V_1 = V_6 -> V_112 ( V_6 , V_102 ) ;
if ( ! V_1 )
goto V_110;
V_1 = V_6 -> V_113 ( V_6 , V_102 , V_3 ) ;
if ( ! V_1 )
goto V_110;
} else
V_1 = 1 ;
if ( V_1 != 2 ) {
V_1 = V_6 -> V_113 ( V_6 , V_101 , V_3 ) ;
if ( ! V_1 )
goto V_110;
}
F_48 ( V_101 ) ;
F_48 ( V_102 ) ;
V_101 = NULL ;
V_102 = NULL ;
if ( V_104 == V_6 -> V_106 ) {
V_6 -> error = V_109 ;
V_1 = V_6 -> V_25 ( 0 , V_6 ) ;
goto V_110;
}
}
V_110:
F_48 ( V_101 ) ;
F_48 ( V_102 ) ;
V_6 -> V_111 = NULL ;
return V_1 ;
}
static int F_49 ( T_1 * V_6 , T_6 * V_101 , int V_114 )
{
T_7 * V_115 ;
int V_9 ;
if ( V_114 )
V_6 -> V_111 = V_101 ;
if ( V_6 -> V_16 -> V_31 & V_116 )
V_115 = & V_6 -> V_16 -> V_117 ;
else
V_115 = NULL ;
V_9 = F_50 ( F_51 ( V_101 ) , V_115 ) ;
if ( V_9 == 0 ) {
if ( ! V_114 )
return 0 ;
V_6 -> error = V_118 ;
if ( ! V_6 -> V_25 ( 0 , V_6 ) )
return 0 ;
}
if ( V_9 > 0 ) {
if ( ! V_114 )
return 0 ;
V_6 -> error = V_119 ;
if ( ! V_6 -> V_25 ( 0 , V_6 ) )
return 0 ;
}
if ( F_52 ( V_101 ) ) {
V_9 = F_50 ( F_52 ( V_101 ) , V_115 ) ;
if ( V_9 == 0 ) {
if ( ! V_114 )
return 0 ;
V_6 -> error = V_120 ;
if ( ! V_6 -> V_25 ( 0 , V_6 ) )
return 0 ;
}
if ( ( V_9 < 0 ) && ! ( V_6 -> V_105 & V_121 ) ) {
if ( ! V_114 )
return 0 ;
V_6 -> error = V_122 ;
if ( ! V_6 -> V_25 ( 0 , V_6 ) )
return 0 ;
}
}
if ( V_114 )
V_6 -> V_111 = NULL ;
return 1 ;
}
static int F_53 ( T_6 * V_123 , T_6 * V_124 , int V_125 )
{
T_8 * V_126 , * V_127 ;
int V_9 ;
V_9 = F_54 ( V_123 , V_125 , - 1 ) ;
if ( V_9 >= 0 ) {
if ( F_54 ( V_123 , V_125 , V_9 ) != - 1 )
return 0 ;
V_126 = F_55 ( F_56 ( V_123 , V_9 ) ) ;
} else
V_126 = NULL ;
V_9 = F_54 ( V_124 , V_125 , - 1 ) ;
if ( V_9 >= 0 ) {
if ( F_54 ( V_124 , V_125 , V_9 ) != - 1 )
return 0 ;
V_127 = F_55 ( F_56 ( V_124 , V_9 ) ) ;
} else
V_127 = NULL ;
if ( ! V_126 && ! V_127 )
return 1 ;
if ( ! V_126 || ! V_127 )
return 0 ;
if ( F_57 ( V_126 , V_127 ) )
return 0 ;
return 1 ;
}
static int F_58 ( T_6 * V_128 , T_6 * V_129 )
{
if ( ! V_128 -> V_130 )
return 0 ;
if ( ! V_129 -> V_131 )
return 0 ;
if ( F_59 ( F_60 ( V_129 ) , F_60 ( V_128 ) ) )
return 0 ;
if ( ! F_53 ( V_128 , V_129 , V_132 ) )
return 0 ;
if ( ! F_53 ( V_128 , V_129 , V_133 ) )
return 0 ;
if ( F_61 ( V_128 -> V_130 , V_129 -> V_131 ) > 0 )
return 0 ;
if ( F_61 ( V_128 -> V_131 , V_129 -> V_131 ) > 0 )
return 1 ;
return 0 ;
}
static int F_62 ( T_1 * V_6 , T_2 * * V_134 ,
unsigned int * V_135 , T_6 * V_101 , T_2 * V_3 )
{
int V_136 = 0 ;
unsigned int V_137 = * V_135 , V_138 ;
if ( V_101 -> V_139 & V_140 )
return 0 ;
if ( ! ( V_6 -> V_16 -> V_31 & V_141 ) ) {
if ( V_101 -> V_139 & ( V_142 | V_143 ) )
return 0 ;
} else if ( V_101 -> V_139 & V_143 ) {
if ( ! ( V_101 -> V_144 & ~ V_137 ) )
return 0 ;
}
else if ( V_101 -> V_130 )
return 0 ;
if ( F_59 ( F_63 ( V_3 ) , F_60 ( V_101 ) ) ) {
if ( ! ( V_101 -> V_139 & V_142 ) )
return 0 ;
} else
V_136 |= V_145 ;
if ( ! ( V_101 -> V_31 & V_62 ) )
V_136 |= V_146 ;
if ( F_49 ( V_6 , V_101 , 0 ) )
V_136 |= V_147 ;
F_64 ( V_6 , V_101 , V_134 , & V_136 ) ;
if ( ! ( V_136 & V_148 ) )
return 0 ;
if ( F_65 ( V_3 , V_101 , V_136 , & V_138 ) ) {
if ( ! ( V_138 & ~ V_137 ) )
return 0 ;
V_137 |= V_138 ;
V_136 |= V_149 ;
}
* V_135 = V_137 ;
return V_136 ;
}
static void F_64 ( T_1 * V_6 , T_6 * V_101 ,
T_2 * * V_134 , int * V_150 )
{
T_2 * V_151 = NULL ;
T_9 * V_152 = F_60 ( V_101 ) ;
int V_153 = V_6 -> V_36 ;
int V_9 ;
if ( V_153 != F_7 ( V_6 -> V_26 ) - 1 )
V_153 ++ ;
V_151 = F_8 ( V_6 -> V_26 , V_153 ) ;
if ( F_66 ( V_151 , V_101 -> V_154 ) == V_44 ) {
if ( * V_150 & V_145 ) {
* V_150 |= V_148 | V_155 ;
* V_134 = V_151 ;
return;
}
}
for ( V_153 ++ ; V_153 < F_7 ( V_6 -> V_26 ) ; V_153 ++ ) {
V_151 = F_8 ( V_6 -> V_26 , V_153 ) ;
if ( F_59 ( F_6 ( V_151 ) , V_152 ) )
continue;
if ( F_66 ( V_151 , V_101 -> V_154 ) == V_44 ) {
* V_150 |= V_148 | V_156 ;
* V_134 = V_151 ;
return;
}
}
if ( ! ( V_6 -> V_16 -> V_31 & V_141 ) )
return;
for ( V_9 = 0 ; V_9 < F_7 ( V_6 -> V_30 ) ; V_9 ++ ) {
V_151 = F_8 ( V_6 -> V_30 , V_9 ) ;
if ( F_59 ( F_6 ( V_151 ) , V_152 ) )
continue;
if ( F_66 ( V_151 , V_101 -> V_154 ) == V_44 ) {
* V_134 = V_151 ;
* V_150 |= V_148 ;
return;
}
}
}
static int F_67 ( T_1 * V_6 , T_2 * V_3 )
{
T_1 V_157 ;
int V_49 ;
if ( V_6 -> V_58 )
return 0 ;
if ( ! F_68 ( & V_157 , V_6 -> V_6 , V_3 , V_6 -> V_30 ) )
return - 1 ;
V_157 . V_158 = V_6 -> V_158 ;
F_69 ( & V_157 , V_6 -> V_16 ) ;
V_157 . V_58 = V_6 ;
V_157 . V_25 = V_6 -> V_25 ;
V_49 = F_12 ( & V_157 ) ;
if ( V_49 <= 0 )
goto V_110;
V_49 = F_70 ( V_6 , V_6 -> V_26 , V_157 . V_26 ) ;
V_110:
F_71 ( & V_157 ) ;
return V_49 ;
}
static int F_72 ( T_10 * V_123 , T_10 * V_124 )
{
T_9 * V_159 = NULL ;
T_11 * V_160 = NULL ;
T_12 * V_161 , * V_162 ;
int V_9 , V_75 ;
if ( ! V_123 || ! V_124 )
return 1 ;
if ( V_123 -> type == 1 ) {
if ( ! V_123 -> V_163 )
return 0 ;
if ( V_124 -> type == 1 ) {
if ( ! V_124 -> V_163 )
return 0 ;
if ( ! F_59 ( V_123 -> V_163 , V_124 -> V_163 ) )
return 1 ;
else
return 0 ;
}
V_159 = V_123 -> V_163 ;
V_160 = V_124 -> V_82 . V_164 ;
} else if ( V_124 -> type == 1 ) {
if ( ! V_124 -> V_163 )
return 0 ;
V_160 = V_123 -> V_82 . V_164 ;
V_159 = V_124 -> V_163 ;
}
if ( V_159 ) {
for ( V_9 = 0 ; V_9 < F_73 ( V_160 ) ; V_9 ++ ) {
V_161 = F_74 ( V_160 , V_9 ) ;
if ( V_161 -> type != V_165 )
continue;
if ( ! F_59 ( V_159 , V_161 -> V_166 . V_167 ) )
return 1 ;
}
return 0 ;
}
for ( V_9 = 0 ; V_9 < F_73 ( V_123 -> V_82 . V_164 ) ; V_9 ++ ) {
V_161 = F_74 ( V_123 -> V_82 . V_164 , V_9 ) ;
for ( V_75 = 0 ; V_75 < F_73 ( V_124 -> V_82 . V_164 ) ; V_75 ++ ) {
V_162 = F_74 ( V_124 -> V_82 . V_164 , V_75 ) ;
if ( ! F_75 ( V_161 , V_162 ) )
return 1 ;
}
}
return 0 ;
}
static int F_76 ( T_13 * V_168 , T_6 * V_101 , int V_136 )
{
int V_9 ;
T_9 * V_159 = F_60 ( V_101 ) ;
if ( ! V_168 -> V_169 )
return ! ! ( V_136 & V_145 ) ;
for ( V_9 = 0 ; V_9 < F_73 ( V_168 -> V_169 ) ; V_9 ++ ) {
T_12 * V_170 = F_74 ( V_168 -> V_169 , V_9 ) ;
if ( V_170 -> type != V_165 )
continue;
if ( ! F_59 ( V_170 -> V_166 . V_167 , V_159 ) )
return 1 ;
}
return 0 ;
}
static int F_65 ( T_2 * V_3 , T_6 * V_101 , int V_136 ,
unsigned int * V_135 )
{
int V_9 ;
if ( V_101 -> V_139 & V_171 )
return 0 ;
if ( V_3 -> V_4 & V_172 ) {
if ( V_101 -> V_139 & V_173 )
return 0 ;
} else {
if ( V_101 -> V_139 & V_174 )
return 0 ;
}
* V_135 = V_101 -> V_144 ;
for ( V_9 = 0 ; V_9 < F_77 ( V_3 -> V_175 ) ; V_9 ++ ) {
T_13 * V_168 = F_78 ( V_3 -> V_175 , V_9 ) ;
if ( F_76 ( V_168 , V_101 , V_136 ) ) {
if ( ! V_101 -> V_176 || F_72 ( V_168 -> V_177 , V_101 -> V_176 -> V_177 ) ) {
* V_135 &= V_168 -> V_178 ;
return 1 ;
}
}
}
if ( ( ! V_101 -> V_176 || ! V_101 -> V_176 -> V_177 )
&& ( V_136 & V_145 ) )
return 1 ;
return 0 ;
}
static int F_47 ( T_1 * V_6 ,
T_6 * * V_179 , T_6 * * V_180 , T_2 * V_3 )
{
int V_1 ;
T_2 * V_48 = NULL ;
int V_136 = 0 ;
unsigned int V_181 ;
T_6 * V_101 = NULL , * V_102 = NULL ;
F_5 ( T_6 ) * V_182 ;
T_9 * V_159 = F_63 ( V_3 ) ;
V_181 = V_6 -> V_106 ;
V_1 = F_79 ( V_6 , & V_101 , & V_102 ,
& V_48 , & V_136 , & V_181 , V_6 -> V_158 ) ;
if ( V_1 )
goto V_183;
V_182 = V_6 -> V_184 ( V_6 , V_159 ) ;
if ( ! V_182 && V_101 )
goto V_183;
F_79 ( V_6 , & V_101 , & V_102 , & V_48 , & V_136 , & V_181 , V_182 ) ;
F_80 ( V_182 , F_48 ) ;
V_183:
if ( V_101 ) {
V_6 -> V_51 = V_48 ;
V_6 -> V_105 = V_136 ;
V_6 -> V_106 = V_181 ;
* V_179 = V_101 ;
* V_180 = V_102 ;
return 1 ;
}
return 0 ;
}
static int V_112 ( T_1 * V_6 , T_6 * V_101 )
{
T_2 * V_48 = NULL ;
T_14 * V_185 = NULL ;
int V_1 = 0 , V_186 , V_103 ;
V_103 = V_6 -> V_36 ;
V_186 = F_7 ( V_6 -> V_26 ) - 1 ;
if ( V_6 -> V_51 )
V_48 = V_6 -> V_51 ;
else if ( V_103 < V_186 )
V_48 = F_8 ( V_6 -> V_26 , V_103 + 1 ) ;
else {
V_48 = F_8 ( V_6 -> V_26 , V_186 ) ;
if ( ! V_6 -> V_39 ( V_6 , V_48 , V_48 ) ) {
V_6 -> error = V_187 ;
V_1 = V_6 -> V_25 ( 0 , V_6 ) ;
if ( ! V_1 )
goto V_110;
}
}
if ( V_48 ) {
if ( ! V_101 -> V_130 ) {
if ( ( V_48 -> V_4 & V_188 ) &&
! ( V_48 -> V_189 & V_190 ) ) {
V_6 -> error = V_191 ;
V_1 = V_6 -> V_25 ( 0 , V_6 ) ;
if ( ! V_1 )
goto V_110;
}
if ( ! ( V_6 -> V_105 & V_149 ) ) {
V_6 -> error = V_192 ;
V_1 = V_6 -> V_25 ( 0 , V_6 ) ;
if ( ! V_1 )
goto V_110;
}
if ( ! ( V_6 -> V_105 & V_156 ) ) {
if ( F_67 ( V_6 , V_6 -> V_51 ) <= 0 ) {
V_6 -> error = V_193 ;
V_1 = V_6 -> V_25 ( 0 , V_6 ) ;
if ( ! V_1 )
goto V_110;
}
}
if ( V_101 -> V_139 & V_140 ) {
V_6 -> error = V_194 ;
V_1 = V_6 -> V_25 ( 0 , V_6 ) ;
if ( ! V_1 )
goto V_110;
}
}
if ( ! ( V_6 -> V_105 & V_147 ) ) {
V_1 = F_49 ( V_6 , V_101 , 1 ) ;
if ( ! V_1 )
goto V_110;
}
V_185 = F_81 ( V_48 ) ;
if ( ! V_185 ) {
V_6 -> error = V_195 ;
V_1 = V_6 -> V_25 ( 0 , V_6 ) ;
if ( ! V_1 )
goto V_110;
} else {
int V_76 ;
V_76 = F_82 ( V_101 , V_185 , V_6 -> V_16 -> V_31 ) ;
if ( V_76 != V_44 ) {
V_6 -> error = V_76 ;
V_1 = V_6 -> V_25 ( 0 , V_6 ) ;
if ( ! V_1 )
goto V_110;
}
if ( F_83 ( V_101 , V_185 ) <= 0 ) {
V_6 -> error = V_196 ;
V_1 = V_6 -> V_25 ( 0 , V_6 ) ;
if ( ! V_1 )
goto V_110;
}
}
}
V_1 = 1 ;
V_110:
F_84 ( V_185 ) ;
return V_1 ;
}
static int V_113 ( T_1 * V_6 , T_6 * V_101 , T_2 * V_3 )
{
int V_1 ;
T_15 * V_197 ;
if ( ! ( V_6 -> V_16 -> V_31 & V_61 )
&& ( V_101 -> V_31 & V_62 ) ) {
V_6 -> error = V_198 ;
V_1 = V_6 -> V_25 ( 0 , V_6 ) ;
if ( ! V_1 )
return 0 ;
}
if ( F_85 ( V_101 , & V_197 , V_3 ) ) {
if ( V_197 -> V_199 == V_200 )
return 2 ;
V_6 -> error = V_201 ;
V_1 = V_6 -> V_25 ( 0 , V_6 ) ;
if ( ! V_1 )
return 0 ;
}
return 1 ;
}
static int V_47 ( T_1 * V_6 )
{
int V_49 ;
if ( V_6 -> V_58 )
return 1 ;
V_49 = F_86 ( & V_6 -> V_202 , & V_6 -> V_203 , V_6 -> V_26 ,
V_6 -> V_16 -> V_204 , V_6 -> V_16 -> V_31 ) ;
if ( V_49 == 0 ) {
F_14 ( V_205 , V_27 ) ;
return 0 ;
}
if ( V_49 == - 1 ) {
T_2 * V_3 ;
int V_9 ;
for ( V_9 = 1 ; V_9 < F_7 ( V_6 -> V_26 ) ; V_9 ++ ) {
V_3 = F_8 ( V_6 -> V_26 , V_9 ) ;
if ( ! ( V_3 -> V_4 & V_206 ) )
continue;
V_6 -> V_35 = V_3 ;
V_6 -> error = V_207 ;
if ( ! V_6 -> V_25 ( 0 , V_6 ) )
return 0 ;
}
return 1 ;
}
if ( V_49 == - 2 ) {
V_6 -> V_35 = NULL ;
V_6 -> error = V_208 ;
return V_6 -> V_25 ( 0 , V_6 ) ;
}
if ( V_6 -> V_16 -> V_31 & V_209 ) {
V_6 -> V_35 = NULL ;
V_6 -> error = V_44 ;
if ( ! V_6 -> V_25 ( 2 , V_6 ) )
return 0 ;
}
return 1 ;
}
static int F_87 ( T_1 * V_6 , T_2 * V_3 )
{
T_7 * V_115 ;
int V_9 ;
if ( V_6 -> V_16 -> V_31 & V_116 )
V_115 = & V_6 -> V_16 -> V_117 ;
else
V_115 = NULL ;
V_9 = F_50 ( F_88 ( V_3 ) , V_115 ) ;
if ( V_9 == 0 ) {
V_6 -> error = V_210 ;
V_6 -> V_35 = V_3 ;
if ( ! V_6 -> V_25 ( 0 , V_6 ) )
return 0 ;
}
if ( V_9 > 0 ) {
V_6 -> error = V_211 ;
V_6 -> V_35 = V_3 ;
if ( ! V_6 -> V_25 ( 0 , V_6 ) )
return 0 ;
}
V_9 = F_50 ( F_89 ( V_3 ) , V_115 ) ;
if ( V_9 == 0 ) {
V_6 -> error = V_212 ;
V_6 -> V_35 = V_3 ;
if ( ! V_6 -> V_25 ( 0 , V_6 ) )
return 0 ;
}
if ( V_9 < 0 ) {
V_6 -> error = V_213 ;
V_6 -> V_35 = V_3 ;
if ( ! V_6 -> V_25 ( 0 , V_6 ) )
return 0 ;
}
return 1 ;
}
static int F_28 ( T_1 * V_6 )
{
int V_1 = 0 , V_80 ;
T_2 * V_214 , * V_215 ;
T_14 * V_216 = NULL ;
int (* F_13) ( int V_19 , T_1 * V_20 );
F_13 = V_6 -> V_25 ;
V_80 = F_7 ( V_6 -> V_26 ) ;
V_6 -> V_36 = V_80 - 1 ;
V_80 -- ;
V_215 = F_8 ( V_6 -> V_26 , V_80 ) ;
if ( V_6 -> V_39 ( V_6 , V_215 , V_215 ) )
V_214 = V_215 ;
else {
if ( V_6 -> V_16 -> V_31 & V_95 ) {
V_214 = V_215 ;
goto F_46;
}
if ( V_80 <= 0 ) {
V_6 -> error = V_217 ;
V_6 -> V_35 = V_215 ;
V_1 = F_13 ( 0 , V_6 ) ;
goto V_28;
} else {
V_80 -- ;
V_6 -> V_36 = V_80 ;
V_214 = F_8 ( V_6 -> V_26 , V_80 ) ;
}
}
while ( V_80 >= 0 ) {
V_6 -> V_36 = V_80 ;
if ( ! V_214 -> V_218
&& ( V_214 != V_215
|| ( V_6 -> V_16 -> V_31 & V_219 ) ) ) {
if ( ( V_216 = F_81 ( V_215 ) ) == NULL ) {
V_6 -> error = V_195 ;
V_6 -> V_35 = V_215 ;
V_1 = (* F_13) ( 0 , V_6 ) ;
if ( ! V_1 )
goto V_28;
} else if ( F_90 ( V_214 , V_216 ) <= 0 ) {
V_6 -> error = V_220 ;
V_6 -> V_35 = V_214 ;
V_1 = (* F_13) ( 0 , V_6 ) ;
if ( ! V_1 ) {
F_84 ( V_216 ) ;
goto V_28;
}
}
F_84 ( V_216 ) ;
V_216 = NULL ;
}
V_214 -> V_218 = 1 ;
F_46:
V_1 = F_87 ( V_6 , V_214 ) ;
if ( ! V_1 )
goto V_28;
V_6 -> V_51 = V_215 ;
V_6 -> V_35 = V_214 ;
V_1 = (* F_13) ( 1 , V_6 ) ;
if ( ! V_1 )
goto V_28;
V_80 -- ;
if ( V_80 >= 0 ) {
V_215 = V_214 ;
V_214 = F_8 ( V_6 -> V_26 , V_80 ) ;
}
}
V_1 = 1 ;
V_28:
return V_1 ;
}
int F_91 ( const T_16 * V_221 )
{
return F_50 ( V_221 , NULL ) ;
}
int F_50 ( const T_16 * V_221 , T_7 * V_222 )
{
char * V_223 ;
T_16 V_224 ;
long V_225 ;
char V_226 [ 24 ] , V_227 [ 24 ] , * V_228 ;
int V_9 , V_75 ;
V_228 = V_226 ;
V_9 = V_221 -> V_229 ;
V_223 = ( char * ) V_221 -> V_230 ;
if ( V_221 -> type == V_231 ) {
if ( ( V_9 < 11 ) || ( V_9 > 17 ) )
return 0 ;
memcpy ( V_228 , V_223 , 10 ) ;
V_228 += 10 ;
V_223 += 10 ;
} else {
if ( V_9 < 13 )
return 0 ;
memcpy ( V_228 , V_223 , 12 ) ;
V_228 += 12 ;
V_223 += 12 ;
}
if ( ( * V_223 == 'Z' ) || ( * V_223 == '-' ) || ( * V_223 == '+' ) ) {
* ( V_228 ++ ) = '0' ;
* ( V_228 ++ ) = '0' ;
} else {
* ( V_228 ++ ) = * ( V_223 ++ ) ;
* ( V_228 ++ ) = * ( V_223 ++ ) ;
if ( * V_223 == '.' ) {
V_223 ++ ;
while ( ( * V_223 >= '0' ) && ( * V_223 <= '9' ) )
V_223 ++ ;
}
}
* ( V_228 ++ ) = 'Z' ;
* ( V_228 ++ ) = '\0' ;
if ( * V_223 == 'Z' )
V_225 = 0 ;
else {
if ( ( * V_223 != '+' ) && ( * V_223 != '-' ) )
return 0 ;
V_225 = ( ( V_223 [ 1 ] - '0' ) * 10 + ( V_223 [ 2 ] - '0' ) ) * 60 ;
V_225 += ( V_223 [ 3 ] - '0' ) * 10 + ( V_223 [ 4 ] - '0' ) ;
if ( * V_223 == '-' )
V_225 = - V_225 ;
}
V_224 . type = V_221 -> type ;
V_224 . V_31 = 0 ;
V_224 . V_229 = sizeof( V_227 ) ;
V_224 . V_230 = ( unsigned char * ) V_227 ;
if ( F_92 ( & V_224 , V_225 * 60 , V_222 ) == NULL )
return 0 ;
if ( V_221 -> type == V_231 ) {
V_9 = ( V_226 [ 0 ] - '0' ) * 10 + ( V_226 [ 1 ] - '0' ) ;
if ( V_9 < 50 )
V_9 += 100 ;
V_75 = ( V_227 [ 0 ] - '0' ) * 10 + ( V_227 [ 1 ] - '0' ) ;
if ( V_75 < 50 )
V_75 += 100 ;
if ( V_9 < V_75 )
return - 1 ;
if ( V_9 > V_75 )
return 1 ;
}
V_9 = strcmp ( V_226 , V_227 ) ;
if ( V_9 == 0 )
return - 1 ;
else
return V_9 ;
}
T_16 * F_93 ( T_16 * V_232 , long V_233 )
{
return F_92 ( V_232 , V_233 , NULL ) ;
}
T_16 * F_92 ( T_16 * V_232 , long V_234 , T_7 * V_235 )
{
return F_94 ( V_232 , 0 , V_234 , V_235 ) ;
}
T_16 * F_94 ( T_16 * V_232 ,
int V_236 , long V_234 , T_7 * V_235 )
{
T_7 V_237 ;
if ( V_235 )
V_237 = * V_235 ;
else
time ( & V_237 ) ;
if ( V_232 && ! ( V_232 -> V_31 & V_238 ) ) {
if ( V_232 -> type == V_231 )
return F_95 ( V_232 , V_237 , V_236 , V_234 ) ;
if ( V_232 -> type == V_239 )
return F_96 ( V_232 , V_237 , V_236 , V_234 ) ;
}
return F_97 ( V_232 , V_237 , V_236 , V_234 ) ;
}
T_6 * F_98 ( T_6 * V_129 , T_6 * V_240 ,
T_14 * V_241 , const T_17 * V_242 , unsigned int V_31 )
{
T_6 * V_101 = NULL ;
int V_9 ;
F_5 ( T_15 ) * V_243 = NULL ;
if ( V_129 -> V_130 || V_240 -> V_130 ) {
F_14 ( V_244 , V_245 ) ;
return NULL ;
}
if ( ! V_129 -> V_131 || ! V_240 -> V_131 ) {
F_14 ( V_244 , V_246 ) ;
return NULL ;
}
if ( F_59 ( F_60 ( V_129 ) , F_60 ( V_240 ) ) ) {
F_14 ( V_244 , V_247 ) ;
return NULL ;
}
if ( ! F_53 ( V_129 , V_240 , V_132 ) ) {
F_14 ( V_244 , V_248 ) ;
return NULL ;
}
if ( ! F_53 ( V_129 , V_240 , V_133 ) ) {
F_14 ( V_244 , V_249 ) ;
return NULL ;
}
if ( F_61 ( V_240 -> V_131 , V_129 -> V_131 ) <= 0 ) {
F_14 ( V_244 , V_250 ) ;
return NULL ;
}
if ( V_241 && ( F_83 ( V_129 , V_241 ) <= 0 ||
F_83 ( V_240 , V_241 ) <= 0 ) ) {
F_14 ( V_244 , V_251 ) ;
return NULL ;
}
V_101 = F_99 () ;
if ( ! V_101 || ! F_100 ( V_101 , 1 ) )
goto V_252;
if ( ! F_101 ( V_101 , F_60 ( V_240 ) ) )
goto V_252;
if ( ! F_102 ( V_101 , F_51 ( V_240 ) ) )
goto V_252;
if ( ! F_103 ( V_101 , F_52 ( V_240 ) ) )
goto V_252;
if ( ! F_104 ( V_101 , V_253 , V_129 -> V_131 , 1 , 0 ) )
goto V_252;
for ( V_9 = 0 ; V_9 < F_105 ( V_240 ) ; V_9 ++ ) {
T_18 * V_254 ;
V_254 = F_56 ( V_240 , V_9 ) ;
if ( ! F_106 ( V_101 , V_254 , - 1 ) )
goto V_252;
}
V_243 = F_107 ( V_240 ) ;
for ( V_9 = 0 ; V_9 < F_108 ( V_243 ) ; V_9 ++ ) {
T_15 * V_255 , * V_256 ;
V_255 = F_109 ( V_243 , V_9 ) ;
if ( ! F_110 ( V_129 , & V_256 , V_255 -> V_257 ) ) {
V_256 = F_111 ( V_255 ) ;
if ( ! V_256 )
goto V_252;
if ( ! F_112 ( V_101 , V_256 ) ) {
F_113 ( V_256 ) ;
goto V_252;
}
}
}
if ( V_241 && V_242 && ! F_114 ( V_101 , V_241 , V_242 ) )
goto V_252;
return V_101 ;
V_252:
F_14 ( V_244 , V_27 ) ;
if ( V_101 )
F_48 ( V_101 ) ;
return NULL ;
}
int F_115 ( long V_258 , void * V_259 ,
T_19 * V_260 ,
T_20 * V_261 ,
T_21 * V_262 )
{
return F_116 ( V_263 , V_258 , V_259 ,
V_260 , V_261 , V_262 ) ;
}
int F_117 ( T_1 * V_6 , int V_264 , void * V_230 )
{
return F_118 ( & V_6 -> V_265 , V_264 , V_230 ) ;
}
void * F_119 ( T_1 * V_6 , int V_264 )
{
return F_120 ( & V_6 -> V_265 , V_264 ) ;
}
int F_121 ( T_1 * V_6 )
{
return V_6 -> error ;
}
void F_122 ( T_1 * V_6 , int V_110 )
{
V_6 -> error = V_110 ;
}
int F_123 ( T_1 * V_6 )
{
return V_6 -> V_36 ;
}
T_2 * F_124 ( T_1 * V_6 )
{
return V_6 -> V_35 ;
}
T_6 * F_125 ( T_1 * V_6 )
{
return V_6 -> V_111 ;
}
T_1 * F_126 ( T_1 * V_6 )
{
return V_6 -> V_58 ;
}
void F_127 ( T_1 * V_6 , T_2 * V_3 )
{
V_6 -> V_22 = V_3 ;
}
int F_128 ( T_1 * V_6 , int V_56 )
{
return F_129 ( V_6 , 0 , V_56 , 0 ) ;
}
int F_130 ( T_1 * V_6 , int V_93 )
{
return F_129 ( V_6 , 0 , 0 , V_93 ) ;
}
int F_129 ( T_1 * V_6 , int V_266 ,
int V_56 , int V_93 )
{
int V_264 ;
if ( ! V_56 )
V_56 = V_266 ;
if ( V_56 ) {
T_22 * V_267 ;
V_264 = F_131 ( V_56 ) ;
if ( V_264 == - 1 ) {
F_14 ( V_268 ,
V_269 ) ;
return 0 ;
}
V_267 = F_132 ( V_264 ) ;
if ( V_267 -> V_93 == V_270 ) {
V_264 = F_131 ( V_266 ) ;
if ( V_264 == - 1 ) {
F_14 ( V_268 ,
V_269 ) ;
return 0 ;
}
V_267 = F_132 ( V_264 ) ;
}
if ( ! V_93 )
V_93 = V_267 -> V_93 ;
}
if ( V_93 ) {
V_264 = F_133 ( V_93 ) ;
if ( V_264 == - 1 ) {
F_14 ( V_268 ,
V_271 ) ;
return 0 ;
}
}
if ( V_56 && ! V_6 -> V_16 -> V_56 )
V_6 -> V_16 -> V_56 = V_56 ;
if ( V_93 && ! V_6 -> V_16 -> V_93 )
V_6 -> V_16 -> V_93 = V_93 ;
return 1 ;
}
T_1 * F_134 ( void )
{
T_1 * V_6 ;
V_6 = ( T_1 * ) F_135 ( sizeof( T_1 ) ) ;
if ( ! V_6 ) {
F_14 ( V_272 , V_27 ) ;
return NULL ;
}
memset ( V_6 , 0 , sizeof( T_1 ) ) ;
return V_6 ;
}
void F_136 ( T_1 * V_6 )
{
F_71 ( V_6 ) ;
F_137 ( V_6 ) ;
}
void F_71 ( T_1 * V_6 )
{
if ( V_6 -> V_273 )
V_6 -> V_273 ( V_6 ) ;
if ( V_6 -> V_16 != NULL ) {
if ( V_6 -> V_58 == NULL )
F_138 ( V_6 -> V_16 ) ;
V_6 -> V_16 = NULL ;
}
if ( V_6 -> V_202 != NULL ) {
F_139 ( V_6 -> V_202 ) ;
V_6 -> V_202 = NULL ;
}
if ( V_6 -> V_26 != NULL ) {
F_11 ( V_6 -> V_26 , V_13 ) ;
V_6 -> V_26 = NULL ;
}
F_140 ( V_263 , V_6 , & ( V_6 -> V_265 ) ) ;
memset ( & V_6 -> V_265 , 0 , sizeof( V_274 ) ) ;
}
void F_141 ( T_1 * V_6 , int V_17 )
{
F_142 ( V_6 -> V_16 , V_17 ) ;
}
void F_143 ( T_1 * V_6 , unsigned long V_31 )
{
F_144 ( V_6 -> V_16 , V_31 ) ;
}
void F_145 ( T_1 * V_6 , unsigned long V_31 ,
T_7 V_237 )
{
F_146 ( V_6 -> V_16 , V_237 ) ;
}
void F_147 ( T_1 * V_6 ,
int (* V_25) ( int , T_1 * ) )
{
V_6 -> V_25 = V_25 ;
}
T_23 * F_148 ( T_1 * V_6 )
{
return V_6 -> V_202 ;
}
int F_149 ( T_1 * V_6 )
{
return V_6 -> V_203 ;
}
int F_150 ( T_1 * V_6 , const char * V_82 )
{
const T_3 * V_16 ;
V_16 = F_151 ( V_82 ) ;
if ( ! V_16 )
return 0 ;
return F_152 ( V_6 -> V_16 , V_16 ) ;
}
T_3 * F_153 ( T_1 * V_6 )
{
return V_6 -> V_16 ;
}
void F_69 ( T_1 * V_6 , T_3 * V_16 )
{
if ( V_6 -> V_16 )
F_138 ( V_6 -> V_16 ) ;
V_6 -> V_16 = V_16 ;
}
