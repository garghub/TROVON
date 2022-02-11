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
F_10 ( V_8 ) ;
else
V_8 = NULL ;
F_11 ( V_7 , V_11 ) ;
return V_8 ;
}
static int F_12 ( T_1 * V_6 , T_2 * V_3 , int V_12 , int V_13 )
{
V_6 -> V_14 = V_12 ;
V_6 -> V_15 = ( V_3 != NULL ) ? V_3 : F_8 ( V_6 -> V_16 , V_12 ) ;
if ( V_13 != V_17 )
V_6 -> error = V_13 ;
return V_6 -> V_18 ( 0 , V_6 ) ;
}
static int F_13 ( T_1 * V_6 , int V_13 )
{
V_6 -> error = V_13 ;
return V_6 -> V_18 ( 0 , V_6 ) ;
}
static int F_14 ( T_1 * V_6 )
{
int V_9 ;
int V_19 = F_7 ( V_6 -> V_16 ) ;
if ( V_6 -> V_20 -> V_21 <= 0 )
return 1 ;
for ( V_9 = 0 ; V_9 < V_19 ; ++ V_9 ) {
T_2 * V_22 = F_8 ( V_6 -> V_16 , V_9 ) ;
if ( V_9 > 0 && ! F_15 ( V_6 , V_22 ) &&
F_12 ( V_6 , V_22 , V_9 , V_23 ) == 0 )
return 0 ;
if ( V_9 < V_19 - 1 && ! F_16 ( V_6 , V_22 ) &&
F_12 ( V_6 , V_22 , V_9 , V_24 ) == 0 )
return 0 ;
}
return 1 ;
}
static int F_17 ( T_1 * V_6 )
{
int V_13 ;
int V_1 ;
if ( ( V_1 = F_18 ( V_6 ) ) == 0 ||
( V_1 = F_19 ( V_6 ) ) == 0 ||
( V_1 = F_14 ( V_6 ) ) == 0 ||
( V_1 = F_20 ( V_6 ) ) == 0 ||
( V_1 = F_21 ( V_6 ) ) == 0 || 1 )
F_22 ( NULL , V_6 -> V_16 ) ;
if ( V_1 == 0 || ( V_1 = V_6 -> V_25 ( V_6 ) ) == 0 )
return V_1 ;
V_13 = F_23 ( & V_6 -> V_14 , NULL , V_6 -> V_16 ,
V_6 -> V_20 -> V_26 ) ;
if ( V_13 != V_17 ) {
if ( ( V_1 = F_12 ( V_6 , NULL , V_6 -> V_14 , V_13 ) ) == 0 )
return V_1 ;
}
V_1 = ( V_6 -> V_27 != NULL ) ? V_6 -> V_27 ( V_6 ) : F_24 ( V_6 ) ;
if ( ! V_1 )
return V_1 ;
#ifndef F_25
if ( ( V_1 = F_26 ( V_6 ) ) == 0 )
return V_1 ;
if ( ( V_1 = F_27 ( V_6 ) ) == 0 )
return V_1 ;
#endif
if ( V_6 -> V_20 -> V_26 & V_28 )
V_1 = V_6 -> V_29 ( V_6 ) ;
return V_1 ;
}
int F_28 ( T_1 * V_6 )
{
T_3 * V_30 = V_6 -> V_30 ;
int V_31 ;
if ( V_6 -> V_22 == NULL ) {
F_29 ( V_32 , V_33 ) ;
V_6 -> error = V_34 ;
return - 1 ;
}
if ( V_6 -> V_16 != NULL ) {
F_29 ( V_32 , V_35 ) ;
V_6 -> error = V_34 ;
return - 1 ;
}
if ( ( ( V_6 -> V_16 = F_30 () ) == NULL ) ||
( ! F_31 ( V_6 -> V_16 , V_6 -> V_22 ) ) ) {
F_29 ( V_32 , V_36 ) ;
V_6 -> error = V_37 ;
return - 1 ;
}
F_10 ( V_6 -> V_22 ) ;
V_6 -> V_38 = 1 ;
if ( ! F_15 ( V_6 , V_6 -> V_22 ) &&
! F_12 ( V_6 , V_6 -> V_22 , 0 , V_39 ) )
return 0 ;
if ( F_32 ( V_30 ) )
V_31 = F_33 ( V_6 ) ;
else
V_31 = F_17 ( V_6 ) ;
if ( V_31 <= 0 && V_6 -> error == V_17 )
V_6 -> error = V_40 ;
return V_31 ;
}
static int F_34 ( T_1 * V_6 , T_2 * V_3 , T_2 * V_41 )
{
int V_31 ;
if ( V_3 == V_41 )
return F_2 ( V_3 ) ;
V_31 = F_35 ( V_41 , V_3 ) ;
if ( V_31 == V_17 ) {
int V_9 ;
T_2 * V_42 ;
if ( F_2 ( V_3 ) && F_7 ( V_6 -> V_16 ) == 1 )
return 1 ;
for ( V_9 = 0 ; V_9 < F_7 ( V_6 -> V_16 ) ; V_9 ++ ) {
V_42 = F_8 ( V_6 -> V_16 , V_9 ) ;
if ( V_42 == V_41 || ! F_9 ( V_42 , V_41 ) ) {
V_31 = V_43 ;
break;
}
}
}
return ( V_31 == V_17 ) ;
}
static int F_36 ( T_2 * * V_41 , T_1 * V_6 , T_2 * V_3 )
{
* V_41 = F_37 ( V_6 , V_6 -> V_44 , V_3 ) ;
if ( * V_41 ) {
F_10 ( * V_41 ) ;
return 1 ;
} else
return 0 ;
}
int F_38 ( T_1 * V_6 , T_2 * V_3 , int V_45 , int V_12 ,
int V_46 )
{
int V_47 = V_48 ;
if ( V_12 >= V_6 -> V_38 && V_45 == V_6 -> V_20 -> V_45 )
V_47 = F_39 ( V_3 , V_6 -> V_20 -> V_49 , V_50 ) ;
switch ( V_47 ) {
case V_51 :
return 1 ;
case V_52 :
break;
default:
switch ( F_3 ( V_3 , V_45 , V_46 > 0 ) ) {
case 1 :
return 1 ;
case 0 :
break;
default:
if ( ( V_6 -> V_20 -> V_26 & V_53 ) == 0 )
return 1 ;
}
break;
}
return F_12 ( V_6 , V_3 , V_12 , V_54 ) ;
}
static int F_19 ( T_1 * V_6 )
{
int V_9 , V_46 , V_55 = 0 ;
T_2 * V_3 ;
int V_56 = 0 ;
int V_45 ;
int V_57 ;
int V_19 = F_7 ( V_6 -> V_16 ) ;
V_46 = - 1 ;
if ( V_6 -> V_58 ) {
V_57 = 0 ;
V_45 = V_59 ;
} else {
V_57 =
! ! ( V_6 -> V_20 -> V_26 & V_60 ) ;
V_45 = V_6 -> V_20 -> V_45 ;
}
for ( V_9 = 0 ; V_9 < V_19 ; V_9 ++ ) {
int V_31 ;
V_3 = F_8 ( V_6 -> V_16 , V_9 ) ;
if ( ! ( V_6 -> V_20 -> V_26 & V_61 )
&& ( V_3 -> V_4 & V_62 ) ) {
if ( ! F_12 ( V_6 , V_3 , V_9 ,
V_63 ) )
return 0 ;
}
if ( ! V_57 && ( V_3 -> V_4 & V_64 ) ) {
if ( ! F_12 ( V_6 , V_3 , V_9 ,
V_65 ) )
return 0 ;
}
V_31 = F_40 ( V_3 ) ;
switch ( V_46 ) {
case - 1 :
if ( ( V_6 -> V_20 -> V_26 & V_53 )
&& ( V_31 != 1 ) && ( V_31 != 0 ) ) {
V_31 = 0 ;
V_6 -> error = V_66 ;
} else
V_31 = 1 ;
break;
case 0 :
if ( V_31 != 0 ) {
V_31 = 0 ;
V_6 -> error = V_67 ;
} else
V_31 = 1 ;
break;
default:
if ( ( V_31 == 0 )
|| ( ( V_9 + 1 < V_19 || V_6 -> V_20 -> V_26 & V_53 )
&& ( V_31 != 1 ) ) ) {
V_31 = 0 ;
V_6 -> error = V_66 ;
} else
V_31 = 1 ;
break;
}
if ( V_31 == 0 && ! F_12 ( V_6 , V_3 , V_9 , V_17 ) )
return 0 ;
if ( V_45 > 0 && ! F_38 ( V_6 , V_3 , V_45 , V_9 , V_46 ) )
return 0 ;
if ( ( V_9 > 1 ) && ! ( V_3 -> V_4 & V_68 )
&& ( V_3 -> V_69 != - 1 )
&& ( V_55 > ( V_3 -> V_69 + V_56 + 1 ) ) ) {
if ( ! F_12 ( V_6 , V_3 , V_9 , V_70 ) )
return 0 ;
}
if ( ! ( V_3 -> V_4 & V_68 ) )
V_55 ++ ;
if ( V_3 -> V_4 & V_64 ) {
if ( V_3 -> V_71 != - 1 ) {
if ( V_56 > V_3 -> V_71 ) {
if ( ! F_12 ( V_6 , V_3 , V_9 ,
V_72 ) )
return 0 ;
}
V_56 = V_3 -> V_71 ;
}
V_56 ++ ;
V_46 = 0 ;
} else
V_46 = 1 ;
}
return 1 ;
}
static int F_20 ( T_1 * V_6 )
{
int V_9 ;
for ( V_9 = F_7 ( V_6 -> V_16 ) - 1 ; V_9 >= 0 ; V_9 -- ) {
T_2 * V_3 = F_8 ( V_6 -> V_16 , V_9 ) ;
int V_73 ;
if ( V_9 && ( V_3 -> V_4 & V_68 ) )
continue;
if ( V_3 -> V_4 & V_64 ) {
T_4 * V_74 = F_6 ( V_3 ) ;
T_4 * V_75 = F_41 ( V_3 ) ;
T_5 * V_76 = NULL ;
int V_77 = 0 ;
int V_13 = V_17 ;
int V_78 = F_42 ( V_74 ) - 1 ;
if ( V_78 < 1 ) {
V_13 = V_79 ;
goto V_80;
}
if ( F_42 ( V_74 )
!= F_42 ( V_75 ) + 1 ) {
V_13 = V_79 ;
goto V_80;
}
if ( F_43 ( F_44 ( V_74 ,
V_78 ) )
== F_43 ( F_44 ( V_74 ,
V_78 - 1 ) ) ) {
V_13 = V_79 ;
goto V_80;
}
V_74 = F_45 ( V_74 ) ;
if ( V_74 == NULL ) {
F_29 ( V_81 , V_36 ) ;
V_6 -> error = V_37 ;
return 0 ;
}
V_76 =
F_46 ( V_74 , V_78 ) ;
V_77 =
F_47 ( F_48 ( V_76 ) ) ;
if ( V_77 != V_82
|| F_49 ( V_74 , V_75 ) != 0 ) {
V_13 = V_79 ;
}
F_50 ( V_76 ) ;
F_51 ( V_74 ) ;
V_80:
if ( V_13 != V_17
&& ! F_12 ( V_6 , V_3 , V_9 , V_13 ) )
return 0 ;
}
for ( V_73 = F_7 ( V_6 -> V_16 ) - 1 ; V_73 > V_9 ; V_73 -- ) {
T_6 * V_83 = F_8 ( V_6 -> V_16 , V_73 ) -> V_83 ;
if ( V_83 ) {
int V_84 = F_52 ( V_3 , V_83 ) ;
if ( V_84 == V_17 && V_9 == 0 )
V_84 = F_53 ( V_3 , V_83 ) ;
switch ( V_84 ) {
case V_17 :
break;
case V_37 :
return 0 ;
default:
if ( ! F_12 ( V_6 , V_3 , V_9 , V_84 ) )
return 0 ;
break;
}
}
}
}
return 1 ;
}
static int F_54 ( T_1 * V_6 , int V_85 )
{
return F_12 ( V_6 , V_6 -> V_22 , 0 , V_85 ) ;
}
static int F_55 ( T_2 * V_3 , T_7 * V_86 )
{
int V_9 ;
int V_87 = F_56 ( V_86 -> V_88 ) ;
char * V_89 ;
if ( V_86 -> V_90 != NULL ) {
F_57 ( V_86 -> V_90 ) ;
V_86 -> V_90 = NULL ;
}
for ( V_9 = 0 ; V_9 < V_87 ; ++ V_9 ) {
V_89 = F_58 ( V_86 -> V_88 , V_9 ) ;
if ( F_59 ( V_3 , V_89 , 0 , V_86 -> V_91 , & V_86 -> V_90 ) > 0 )
return 1 ;
}
return V_87 == 0 ;
}
static int F_21 ( T_1 * V_6 )
{
T_7 * V_86 = V_6 -> V_20 ;
T_2 * V_3 = V_6 -> V_22 ;
if ( V_86 -> V_88 && F_55 ( V_3 , V_86 ) <= 0 ) {
if ( ! F_54 ( V_6 , V_92 ) )
return 0 ;
}
if ( V_86 -> V_93 && F_60 ( V_3 , V_86 -> V_93 , V_86 -> V_94 , 0 ) <= 0 ) {
if ( ! F_54 ( V_6 , V_95 ) )
return 0 ;
}
if ( V_86 -> V_96 && F_61 ( V_3 , V_86 -> V_96 , V_86 -> V_97 , 0 ) <= 0 ) {
if ( ! F_54 ( V_6 , V_98 ) )
return 0 ;
}
return 1 ;
}
static int F_62 ( T_1 * V_6 , int V_38 )
{
int V_9 ;
T_2 * V_3 = NULL ;
T_2 * V_99 ;
T_3 * V_30 = V_6 -> V_30 ;
int V_19 = F_7 ( V_6 -> V_16 ) ;
int V_49 ;
if ( F_63 ( V_30 ) && V_38 > 0 && V_38 < V_19 ) {
switch ( V_49 = F_64 ( V_6 , V_38 ) ) {
case V_51 :
case V_52 :
return V_49 ;
}
}
for ( V_9 = V_38 ; V_9 < V_19 ; V_9 ++ ) {
V_3 = F_8 ( V_6 -> V_16 , V_9 ) ;
V_49 = F_39 ( V_3 , V_6 -> V_20 -> V_49 , 0 ) ;
if ( V_49 == V_51 )
goto V_100;
if ( V_49 == V_52 )
goto V_101;
}
if ( V_38 < V_19 ) {
if ( V_6 -> V_20 -> V_26 & V_102 )
goto V_100;
return V_48 ;
}
if ( V_38 == V_19 && V_6 -> V_20 -> V_26 & V_102 ) {
V_9 = 0 ;
V_3 = F_8 ( V_6 -> V_16 , V_9 ) ;
V_99 = F_4 ( V_6 , V_3 ) ;
if ( ! V_99 )
return V_48 ;
V_49 = F_39 ( V_99 , V_6 -> V_20 -> V_49 , 0 ) ;
if ( V_49 == V_52 ) {
V_11 ( V_99 ) ;
goto V_101;
}
( void ) F_65 ( V_6 -> V_16 , 0 , V_99 ) ;
V_11 ( V_3 ) ;
V_6 -> V_38 = 0 ;
goto V_100;
}
return V_48 ;
V_101:
if ( ! F_12 ( V_6 , V_3 , V_9 , V_103 ) )
return V_52 ;
return V_48 ;
V_100:
if ( ! F_32 ( V_30 ) )
return V_51 ;
if ( V_30 -> V_104 < 0 )
V_30 -> V_104 = V_38 ;
if ( V_30 -> V_105 >= 0 )
return V_51 ;
return V_48 ;
}
static int V_25 ( T_1 * V_6 )
{
int V_9 = 0 , V_106 = 0 , V_1 = 0 ;
if ( ! ( V_6 -> V_20 -> V_26 & V_107 ) )
return 1 ;
if ( V_6 -> V_20 -> V_26 & V_108 )
V_106 = F_7 ( V_6 -> V_16 ) - 1 ;
else {
if ( V_6 -> V_58 )
return 1 ;
V_106 = 0 ;
}
for ( V_9 = 0 ; V_9 <= V_106 ; V_9 ++ ) {
V_6 -> V_14 = V_9 ;
V_1 = F_66 ( V_6 ) ;
if ( ! V_1 )
return V_1 ;
}
return 1 ;
}
static int F_66 ( T_1 * V_6 )
{
T_8 * V_109 = NULL , * V_110 = NULL ;
int V_1 = 0 ;
int V_111 = V_6 -> V_14 ;
T_2 * V_3 = F_8 ( V_6 -> V_16 , V_111 ) ;
V_6 -> V_15 = V_3 ;
V_6 -> V_112 = NULL ;
V_6 -> V_113 = 0 ;
V_6 -> V_114 = 0 ;
if ( V_3 -> V_4 & V_64 )
return 1 ;
while ( V_6 -> V_114 != V_115 ) {
unsigned int V_116 = V_6 -> V_114 ;
if ( V_6 -> V_117 )
V_1 = V_6 -> V_117 ( V_6 , & V_109 , V_3 ) ;
else
V_1 = F_67 ( V_6 , & V_109 , & V_110 , V_3 ) ;
if ( ! V_1 ) {
V_1 = F_13 ( V_6 , V_118 ) ;
goto V_119;
}
V_6 -> V_120 = V_109 ;
V_1 = V_6 -> V_121 ( V_6 , V_109 ) ;
if ( ! V_1 )
goto V_119;
if ( V_110 ) {
V_1 = V_6 -> V_121 ( V_6 , V_110 ) ;
if ( ! V_1 )
goto V_119;
V_1 = V_6 -> V_122 ( V_6 , V_110 , V_3 ) ;
if ( ! V_1 )
goto V_119;
} else
V_1 = 1 ;
if ( V_1 != 2 ) {
V_1 = V_6 -> V_122 ( V_6 , V_109 , V_3 ) ;
if ( ! V_1 )
goto V_119;
}
F_68 ( V_109 ) ;
F_68 ( V_110 ) ;
V_109 = NULL ;
V_110 = NULL ;
if ( V_116 == V_6 -> V_114 ) {
V_1 = F_13 ( V_6 , V_118 ) ;
goto V_119;
}
}
V_119:
F_68 ( V_109 ) ;
F_68 ( V_110 ) ;
V_6 -> V_120 = NULL ;
return V_1 ;
}
static int F_69 ( T_1 * V_6 , T_8 * V_109 , int V_123 )
{
T_9 * V_124 ;
int V_9 ;
if ( V_123 )
V_6 -> V_120 = V_109 ;
if ( V_6 -> V_20 -> V_26 & V_125 )
V_124 = & V_6 -> V_20 -> V_126 ;
else if ( V_6 -> V_20 -> V_26 & V_127 )
return 1 ;
else
V_124 = NULL ;
V_9 = F_70 ( F_71 ( V_109 ) , V_124 ) ;
if ( V_9 == 0 ) {
if ( ! V_123 )
return 0 ;
if ( ! F_13 ( V_6 , V_128 ) )
return 0 ;
}
if ( V_9 > 0 ) {
if ( ! V_123 )
return 0 ;
if ( ! F_13 ( V_6 , V_129 ) )
return 0 ;
}
if ( F_72 ( V_109 ) ) {
V_9 = F_70 ( F_72 ( V_109 ) , V_124 ) ;
if ( V_9 == 0 ) {
if ( ! V_123 )
return 0 ;
if ( ! F_13 ( V_6 , V_130 ) )
return 0 ;
}
if ( ( V_9 < 0 ) && ! ( V_6 -> V_113 & V_131 ) ) {
if ( ! V_123 )
return 0 ;
if ( ! F_13 ( V_6 , V_132 ) )
return 0 ;
}
}
if ( V_123 )
V_6 -> V_120 = NULL ;
return 1 ;
}
static int F_73 ( T_8 * V_133 , T_8 * V_134 , int V_135 )
{
T_10 * V_136 , * V_137 ;
int V_9 ;
V_9 = F_74 ( V_133 , V_135 , - 1 ) ;
if ( V_9 >= 0 ) {
if ( F_74 ( V_133 , V_135 , V_9 ) != - 1 )
return 0 ;
V_136 = F_75 ( F_76 ( V_133 , V_9 ) ) ;
} else
V_136 = NULL ;
V_9 = F_74 ( V_134 , V_135 , - 1 ) ;
if ( V_9 >= 0 ) {
if ( F_74 ( V_134 , V_135 , V_9 ) != - 1 )
return 0 ;
V_137 = F_75 ( F_76 ( V_134 , V_9 ) ) ;
} else
V_137 = NULL ;
if ( ! V_136 && ! V_137 )
return 1 ;
if ( ! V_136 || ! V_137 )
return 0 ;
if ( F_77 ( V_136 , V_137 ) )
return 0 ;
return 1 ;
}
static int F_78 ( T_8 * V_138 , T_8 * V_139 )
{
if ( ! V_138 -> V_140 )
return 0 ;
if ( ! V_139 -> V_141 )
return 0 ;
if ( F_49 ( F_79 ( V_139 ) , F_79 ( V_138 ) ) )
return 0 ;
if ( ! F_73 ( V_138 , V_139 , V_142 ) )
return 0 ;
if ( ! F_73 ( V_138 , V_139 , V_143 ) )
return 0 ;
if ( F_80 ( V_138 -> V_140 , V_139 -> V_141 ) > 0 )
return 0 ;
if ( F_80 ( V_138 -> V_141 , V_139 -> V_141 ) > 0 )
return 1 ;
return 0 ;
}
static int F_81 ( T_1 * V_6 , T_2 * * V_144 ,
unsigned int * V_145 , T_8 * V_109 , T_2 * V_3 )
{
int V_146 = 0 ;
unsigned int V_147 = * V_145 , V_148 ;
if ( V_109 -> V_149 & V_150 )
return 0 ;
if ( ! ( V_6 -> V_20 -> V_26 & V_151 ) ) {
if ( V_109 -> V_149 & ( V_152 | V_153 ) )
return 0 ;
} else if ( V_109 -> V_149 & V_153 ) {
if ( ! ( V_109 -> V_154 & ~ V_147 ) )
return 0 ;
}
else if ( V_109 -> V_140 )
return 0 ;
if ( F_49 ( F_41 ( V_3 ) , F_79 ( V_109 ) ) ) {
if ( ! ( V_109 -> V_149 & V_152 ) )
return 0 ;
} else
V_146 |= V_155 ;
if ( ! ( V_109 -> V_26 & V_62 ) )
V_146 |= V_156 ;
if ( F_69 ( V_6 , V_109 , 0 ) )
V_146 |= V_157 ;
F_82 ( V_6 , V_109 , V_144 , & V_146 ) ;
if ( ! ( V_146 & V_158 ) )
return 0 ;
if ( F_83 ( V_3 , V_109 , V_146 , & V_148 ) ) {
if ( ! ( V_148 & ~ V_147 ) )
return 0 ;
V_147 |= V_148 ;
V_146 |= V_159 ;
}
* V_145 = V_147 ;
return V_146 ;
}
static void F_82 ( T_1 * V_6 , T_8 * V_109 ,
T_2 * * V_144 , int * V_160 )
{
T_2 * V_161 = NULL ;
T_4 * V_162 = F_79 ( V_109 ) ;
int V_163 = V_6 -> V_14 ;
int V_9 ;
if ( V_163 != F_7 ( V_6 -> V_16 ) - 1 )
V_163 ++ ;
V_161 = F_8 ( V_6 -> V_16 , V_163 ) ;
if ( F_84 ( V_161 , V_109 -> V_164 ) == V_17 ) {
if ( * V_160 & V_155 ) {
* V_160 |= V_158 | V_165 ;
* V_144 = V_161 ;
return;
}
}
for ( V_163 ++ ; V_163 < F_7 ( V_6 -> V_16 ) ; V_163 ++ ) {
V_161 = F_8 ( V_6 -> V_16 , V_163 ) ;
if ( F_49 ( F_6 ( V_161 ) , V_162 ) )
continue;
if ( F_84 ( V_161 , V_109 -> V_164 ) == V_17 ) {
* V_160 |= V_158 | V_166 ;
* V_144 = V_161 ;
return;
}
}
if ( ! ( V_6 -> V_20 -> V_26 & V_151 ) )
return;
for ( V_9 = 0 ; V_9 < F_7 ( V_6 -> V_167 ) ; V_9 ++ ) {
V_161 = F_8 ( V_6 -> V_167 , V_9 ) ;
if ( F_49 ( F_6 ( V_161 ) , V_162 ) )
continue;
if ( F_84 ( V_161 , V_109 -> V_164 ) == V_17 ) {
* V_144 = V_161 ;
* V_160 |= V_158 ;
return;
}
}
}
static int F_85 ( T_1 * V_6 , T_2 * V_3 )
{
T_1 V_168 ;
int V_31 ;
if ( V_6 -> V_58 )
return 0 ;
if ( ! F_86 ( & V_168 , V_6 -> V_6 , V_3 , V_6 -> V_167 ) )
return - 1 ;
V_168 . V_169 = V_6 -> V_169 ;
F_87 ( & V_168 , V_6 -> V_20 ) ;
V_168 . V_58 = V_6 ;
V_168 . V_18 = V_6 -> V_18 ;
V_31 = F_28 ( & V_168 ) ;
if ( V_31 <= 0 )
goto V_13;
V_31 = F_88 ( V_6 , V_6 -> V_16 , V_168 . V_16 ) ;
V_13:
F_89 ( & V_168 ) ;
return V_31 ;
}
static int F_90 ( T_11 * V_133 , T_11 * V_134 )
{
T_4 * V_170 = NULL ;
T_12 * V_171 = NULL ;
T_13 * V_172 , * V_173 ;
int V_9 , V_73 ;
if ( ! V_133 || ! V_134 )
return 1 ;
if ( V_133 -> type == 1 ) {
if ( ! V_133 -> V_174 )
return 0 ;
if ( V_134 -> type == 1 ) {
if ( ! V_134 -> V_174 )
return 0 ;
if ( ! F_49 ( V_133 -> V_174 , V_134 -> V_174 ) )
return 1 ;
else
return 0 ;
}
V_170 = V_133 -> V_174 ;
V_171 = V_134 -> V_89 . V_175 ;
} else if ( V_134 -> type == 1 ) {
if ( ! V_134 -> V_174 )
return 0 ;
V_171 = V_133 -> V_89 . V_175 ;
V_170 = V_134 -> V_174 ;
}
if ( V_170 ) {
for ( V_9 = 0 ; V_9 < F_91 ( V_171 ) ; V_9 ++ ) {
V_172 = F_92 ( V_171 , V_9 ) ;
if ( V_172 -> type != V_176 )
continue;
if ( ! F_49 ( V_170 , V_172 -> V_177 . V_178 ) )
return 1 ;
}
return 0 ;
}
for ( V_9 = 0 ; V_9 < F_91 ( V_133 -> V_89 . V_175 ) ; V_9 ++ ) {
V_172 = F_92 ( V_133 -> V_89 . V_175 , V_9 ) ;
for ( V_73 = 0 ; V_73 < F_91 ( V_134 -> V_89 . V_175 ) ; V_73 ++ ) {
V_173 = F_92 ( V_134 -> V_89 . V_175 , V_73 ) ;
if ( ! F_93 ( V_172 , V_173 ) )
return 1 ;
}
}
return 0 ;
}
static int F_94 ( T_14 * V_179 , T_8 * V_109 , int V_146 )
{
int V_9 ;
T_4 * V_170 = F_79 ( V_109 ) ;
if ( ! V_179 -> V_180 )
return ! ! ( V_146 & V_155 ) ;
for ( V_9 = 0 ; V_9 < F_91 ( V_179 -> V_180 ) ; V_9 ++ ) {
T_13 * V_181 = F_92 ( V_179 -> V_180 , V_9 ) ;
if ( V_181 -> type != V_176 )
continue;
if ( ! F_49 ( V_181 -> V_177 . V_178 , V_170 ) )
return 1 ;
}
return 0 ;
}
static int F_83 ( T_2 * V_3 , T_8 * V_109 , int V_146 ,
unsigned int * V_145 )
{
int V_9 ;
if ( V_109 -> V_149 & V_182 )
return 0 ;
if ( V_3 -> V_4 & V_183 ) {
if ( V_109 -> V_149 & V_184 )
return 0 ;
} else {
if ( V_109 -> V_149 & V_185 )
return 0 ;
}
* V_145 = V_109 -> V_154 ;
for ( V_9 = 0 ; V_9 < F_95 ( V_3 -> V_186 ) ; V_9 ++ ) {
T_14 * V_179 = F_96 ( V_3 -> V_186 , V_9 ) ;
if ( F_94 ( V_179 , V_109 , V_146 ) ) {
if ( ! V_109 -> V_187 || F_90 ( V_179 -> V_188 , V_109 -> V_187 -> V_188 ) ) {
* V_145 &= V_179 -> V_189 ;
return 1 ;
}
}
}
if ( ( ! V_109 -> V_187 || ! V_109 -> V_187 -> V_188 )
&& ( V_146 & V_155 ) )
return 1 ;
return 0 ;
}
static int F_67 ( T_1 * V_6 ,
T_8 * * V_190 , T_8 * * V_191 , T_2 * V_3 )
{
int V_1 ;
T_2 * V_41 = NULL ;
int V_146 = 0 ;
unsigned int V_192 ;
T_8 * V_109 = NULL , * V_110 = NULL ;
F_5 ( T_8 ) * V_193 ;
T_4 * V_170 = F_41 ( V_3 ) ;
V_192 = V_6 -> V_114 ;
V_1 = F_97 ( V_6 , & V_109 , & V_110 ,
& V_41 , & V_146 , & V_192 , V_6 -> V_169 ) ;
if ( V_1 )
goto V_119;
V_193 = V_6 -> V_194 ( V_6 , V_170 ) ;
if ( ! V_193 && V_109 )
goto V_119;
F_97 ( V_6 , & V_109 , & V_110 , & V_41 , & V_146 , & V_192 , V_193 ) ;
F_98 ( V_193 , F_68 ) ;
V_119:
if ( V_109 ) {
V_6 -> V_112 = V_41 ;
V_6 -> V_113 = V_146 ;
V_6 -> V_114 = V_192 ;
* V_190 = V_109 ;
* V_191 = V_110 ;
return 1 ;
}
return 0 ;
}
static int V_121 ( T_1 * V_6 , T_8 * V_109 )
{
T_2 * V_41 = NULL ;
T_15 * V_195 = NULL ;
int V_111 = V_6 -> V_14 ;
int V_196 = F_7 ( V_6 -> V_16 ) - 1 ;
if ( V_6 -> V_112 )
V_41 = V_6 -> V_112 ;
else if ( V_111 < V_196 )
V_41 = F_8 ( V_6 -> V_16 , V_111 + 1 ) ;
else {
V_41 = F_8 ( V_6 -> V_16 , V_196 ) ;
if ( ! V_6 -> F_34 ( V_6 , V_41 , V_41 ) &&
! F_13 ( V_6 , V_197 ) )
return 0 ;
}
if ( V_41 == NULL )
return 1 ;
if ( ! V_109 -> V_140 ) {
if ( ( V_41 -> V_4 & V_198 ) &&
! ( V_41 -> V_199 & V_200 ) &&
! F_13 ( V_6 , V_201 ) )
return 0 ;
if ( ! ( V_6 -> V_113 & V_159 ) &&
! F_13 ( V_6 , V_202 ) )
return 0 ;
if ( ! ( V_6 -> V_113 & V_166 ) &&
F_85 ( V_6 , V_6 -> V_112 ) <= 0 &&
! F_13 ( V_6 , V_203 ) )
return 0 ;
if ( ( V_109 -> V_149 & V_150 ) &&
! F_13 ( V_6 , V_204 ) )
return 0 ;
}
if ( ! ( V_6 -> V_113 & V_157 ) &&
! F_69 ( V_6 , V_109 , 1 ) )
return 0 ;
V_195 = F_99 ( V_41 ) ;
if ( ! V_195 &&
! F_13 ( V_6 , V_205 ) )
return 0 ;
if ( V_195 ) {
int V_84 = F_100 ( V_109 , V_195 , V_6 -> V_20 -> V_26 ) ;
if ( V_84 != V_17 && ! F_13 ( V_6 , V_84 ) )
return 0 ;
if ( F_101 ( V_109 , V_195 ) <= 0 &&
! F_13 ( V_6 , V_206 ) )
return 0 ;
}
return 1 ;
}
static int V_122 ( T_1 * V_6 , T_8 * V_109 , T_2 * V_3 )
{
T_16 * V_207 ;
if ( ! ( V_6 -> V_20 -> V_26 & V_61 )
&& ( V_109 -> V_26 & V_62 ) &&
! F_13 ( V_6 , V_208 ) )
return 0 ;
if ( F_102 ( V_109 , & V_207 , V_3 ) ) {
if ( V_207 -> V_209 == V_210 )
return 2 ;
if ( ! F_13 ( V_6 , V_211 ) )
return 0 ;
}
return 1 ;
}
static int V_29 ( T_1 * V_6 )
{
int V_31 ;
if ( V_6 -> V_58 )
return 1 ;
if ( V_6 -> V_212 && ! F_31 ( V_6 -> V_16 , NULL ) ) {
F_29 ( V_213 , V_36 ) ;
V_6 -> error = V_37 ;
return 0 ;
}
V_31 = F_103 ( & V_6 -> V_214 , & V_6 -> V_215 , V_6 -> V_16 ,
V_6 -> V_20 -> V_216 , V_6 -> V_20 -> V_26 ) ;
if ( V_6 -> V_212 )
F_104 ( V_6 -> V_16 ) ;
if ( V_31 == V_217 ) {
F_29 ( V_213 , V_36 ) ;
V_6 -> error = V_37 ;
return 0 ;
}
if ( V_31 == V_218 ) {
int V_9 ;
for ( V_9 = 1 ; V_9 < F_7 ( V_6 -> V_16 ) ; V_9 ++ ) {
T_2 * V_3 = F_8 ( V_6 -> V_16 , V_9 ) ;
if ( ! ( V_3 -> V_4 & V_219 ) )
continue;
if ( ! F_12 ( V_6 , V_3 , V_9 ,
V_220 ) )
return 0 ;
}
return 1 ;
}
if ( V_31 == V_221 ) {
V_6 -> V_15 = NULL ;
V_6 -> error = V_222 ;
return V_6 -> V_18 ( 0 , V_6 ) ;
}
if ( V_31 != V_223 ) {
F_29 ( V_213 , V_224 ) ;
return 0 ;
}
if ( V_6 -> V_20 -> V_26 & V_225 ) {
V_6 -> V_15 = NULL ;
if ( ! V_6 -> V_18 ( 2 , V_6 ) )
return 0 ;
}
return 1 ;
}
int F_105 ( T_1 * V_6 , T_2 * V_3 , int V_12 )
{
T_9 * V_124 ;
int V_9 ;
if ( V_6 -> V_20 -> V_26 & V_125 )
V_124 = & V_6 -> V_20 -> V_126 ;
else if ( V_6 -> V_20 -> V_26 & V_127 )
return 1 ;
else
V_124 = NULL ;
V_9 = F_70 ( F_106 ( V_3 ) , V_124 ) ;
if ( V_9 >= 0 && V_12 < 0 )
return 0 ;
if ( V_9 == 0 && ! F_12 ( V_6 , V_3 , V_12 ,
V_226 ) )
return 0 ;
if ( V_9 > 0 && ! F_12 ( V_6 , V_3 , V_12 , V_227 ) )
return 0 ;
V_9 = F_70 ( F_107 ( V_3 ) , V_124 ) ;
if ( V_9 <= 0 && V_12 < 0 )
return 0 ;
if ( V_9 == 0 && ! F_12 ( V_6 , V_3 , V_12 ,
V_228 ) )
return 0 ;
if ( V_9 < 0 && ! F_12 ( V_6 , V_3 , V_12 , V_229 ) )
return 0 ;
return 1 ;
}
static int F_24 ( T_1 * V_6 )
{
int V_87 = F_7 ( V_6 -> V_16 ) - 1 ;
T_2 * V_230 = F_8 ( V_6 -> V_16 , V_87 ) ;
T_2 * V_231 ;
if ( V_6 -> V_212 ) {
V_231 = V_230 ;
V_230 = NULL ;
goto F_66;
}
if ( V_6 -> F_34 ( V_6 , V_230 , V_230 ) )
V_231 = V_230 ;
else {
if ( V_6 -> V_20 -> V_26 & V_102 ) {
V_231 = V_230 ;
goto F_66;
}
if ( V_87 <= 0 )
return F_12 ( V_6 , V_230 , 0 ,
V_232 ) ;
V_87 -- ;
V_6 -> V_14 = V_87 ;
V_231 = F_8 ( V_6 -> V_16 , V_87 ) ;
}
while ( V_87 >= 0 ) {
T_15 * V_233 ;
if ( V_231 != V_230 || ( V_6 -> V_20 -> V_26 & V_234 ) ) {
if ( ( V_233 = F_99 ( V_230 ) ) == NULL ) {
if ( ! F_12 ( V_6 , V_230 , V_230 != V_231 ? V_87 + 1 : V_87 ,
V_205 ) )
return 0 ;
} else if ( F_108 ( V_231 , V_233 ) <= 0 ) {
if ( ! F_12 ( V_6 , V_231 , V_87 ,
V_235 ) )
return 0 ;
}
}
F_66:
if ( ! F_105 ( V_6 , V_231 , V_87 ) )
return 0 ;
V_6 -> V_112 = V_230 ;
V_6 -> V_15 = V_231 ;
V_6 -> V_14 = V_87 ;
if ( ! V_6 -> V_18 ( 1 , V_6 ) )
return 0 ;
if ( -- V_87 >= 0 ) {
V_230 = V_231 ;
V_231 = F_8 ( V_6 -> V_16 , V_87 ) ;
}
}
return 1 ;
}
int F_109 ( const T_17 * V_236 )
{
return F_70 ( V_236 , NULL ) ;
}
int F_70 ( const T_17 * V_236 , T_9 * V_237 )
{
char * V_238 ;
T_17 V_239 ;
long V_240 ;
char V_241 [ 24 ] , V_242 [ 24 ] , * V_243 ;
int V_9 , V_73 , V_244 ;
V_243 = V_241 ;
V_244 = V_236 -> V_245 ;
V_238 = ( char * ) V_236 -> V_246 ;
if ( V_236 -> type == V_247 ) {
int V_248 = sizeof( L_1 ) - 1 ;
int V_249 = sizeof( L_2 ) - 1 ;
if ( V_244 < V_248 || V_244 > V_249 )
return 0 ;
memcpy ( V_243 , V_238 , 10 ) ;
V_243 += 10 ;
V_238 += 10 ;
V_244 -= 10 ;
} else {
int V_248 = sizeof( L_3 ) - 1 ;
int V_249 = sizeof( L_4 ) - 1 ;
if ( V_244 < V_248 || V_244 > V_249 )
return 0 ;
memcpy ( V_243 , V_238 , 12 ) ;
V_243 += 12 ;
V_238 += 12 ;
V_244 -= 12 ;
}
if ( ( * V_238 == 'Z' ) || ( * V_238 == '-' ) || ( * V_238 == '+' ) ) {
* ( V_243 ++ ) = '0' ;
* ( V_243 ++ ) = '0' ;
} else {
if ( V_244 < 2 )
return 0 ;
* ( V_243 ++ ) = * ( V_238 ++ ) ;
* ( V_243 ++ ) = * ( V_238 ++ ) ;
V_244 -= 2 ;
if ( V_244 && * V_238 == '.' ) {
V_238 ++ ;
V_244 -- ;
for ( V_9 = 0 ; V_9 < 3 && V_244 ; V_9 ++ , V_238 ++ , V_244 -- ) {
if ( * V_238 < '0' || * V_238 > '9' )
break;
}
}
}
* ( V_243 ++ ) = 'Z' ;
* ( V_243 ++ ) = '\0' ;
if ( ! V_244 )
return 0 ;
if ( * V_238 == 'Z' ) {
if ( V_244 != 1 )
return 0 ;
V_240 = 0 ;
} else {
if ( ( * V_238 != '+' ) && ( * V_238 != '-' ) )
return 0 ;
if ( V_244 != 5 )
return 0 ;
if ( V_238 [ 1 ] < '0' || V_238 [ 1 ] > '9' || V_238 [ 2 ] < '0' || V_238 [ 2 ] > '9' ||
V_238 [ 3 ] < '0' || V_238 [ 3 ] > '9' || V_238 [ 4 ] < '0' || V_238 [ 4 ] > '9' )
return 0 ;
V_240 = ( ( V_238 [ 1 ] - '0' ) * 10 + ( V_238 [ 2 ] - '0' ) ) * 60 ;
V_240 += ( V_238 [ 3 ] - '0' ) * 10 + ( V_238 [ 4 ] - '0' ) ;
if ( * V_238 == '-' )
V_240 = - V_240 ;
}
V_239 . type = V_236 -> type ;
V_239 . V_26 = 0 ;
V_239 . V_245 = sizeof( V_242 ) ;
V_239 . V_246 = ( unsigned char * ) V_242 ;
if ( F_110 ( & V_239 , V_240 * 60 , V_237 ) == NULL )
return 0 ;
if ( V_236 -> type == V_247 ) {
V_9 = ( V_241 [ 0 ] - '0' ) * 10 + ( V_241 [ 1 ] - '0' ) ;
if ( V_9 < 50 )
V_9 += 100 ;
V_73 = ( V_242 [ 0 ] - '0' ) * 10 + ( V_242 [ 1 ] - '0' ) ;
if ( V_73 < 50 )
V_73 += 100 ;
if ( V_9 < V_73 )
return - 1 ;
if ( V_9 > V_73 )
return 1 ;
}
V_9 = strcmp ( V_241 , V_242 ) ;
if ( V_9 == 0 )
return - 1 ;
else
return V_9 ;
}
T_17 * F_111 ( T_17 * V_250 , long V_251 )
{
return F_110 ( V_250 , V_251 , NULL ) ;
}
T_17 * F_110 ( T_17 * V_250 , long V_252 , T_9 * V_253 )
{
return F_112 ( V_250 , 0 , V_252 , V_253 ) ;
}
T_17 * F_112 ( T_17 * V_250 ,
int V_254 , long V_252 , T_9 * V_253 )
{
T_9 V_255 ;
if ( V_253 )
V_255 = * V_253 ;
else
time ( & V_255 ) ;
if ( V_250 && ! ( V_250 -> V_26 & V_256 ) ) {
if ( V_250 -> type == V_247 )
return F_113 ( V_250 , V_255 , V_254 , V_252 ) ;
if ( V_250 -> type == V_257 )
return F_114 ( V_250 , V_255 , V_254 , V_252 ) ;
}
return F_115 ( V_250 , V_255 , V_254 , V_252 ) ;
}
T_8 * F_116 ( T_8 * V_139 , T_8 * V_258 ,
T_15 * V_259 , const T_18 * V_260 , unsigned int V_26 )
{
T_8 * V_109 = NULL ;
int V_9 ;
F_5 ( T_16 ) * V_261 = NULL ;
if ( V_139 -> V_140 || V_258 -> V_140 ) {
F_29 ( V_262 , V_263 ) ;
return NULL ;
}
if ( ! V_139 -> V_141 || ! V_258 -> V_141 ) {
F_29 ( V_262 , V_264 ) ;
return NULL ;
}
if ( F_49 ( F_79 ( V_139 ) , F_79 ( V_258 ) ) ) {
F_29 ( V_262 , V_265 ) ;
return NULL ;
}
if ( ! F_73 ( V_139 , V_258 , V_142 ) ) {
F_29 ( V_262 , V_266 ) ;
return NULL ;
}
if ( ! F_73 ( V_139 , V_258 , V_143 ) ) {
F_29 ( V_262 , V_267 ) ;
return NULL ;
}
if ( F_80 ( V_258 -> V_141 , V_139 -> V_141 ) <= 0 ) {
F_29 ( V_262 , V_268 ) ;
return NULL ;
}
if ( V_259 && ( F_101 ( V_139 , V_259 ) <= 0 ||
F_101 ( V_258 , V_259 ) <= 0 ) ) {
F_29 ( V_262 , V_269 ) ;
return NULL ;
}
V_109 = F_117 () ;
if ( V_109 == NULL || ! F_118 ( V_109 , 1 ) )
goto V_270;
if ( ! F_119 ( V_109 , F_79 ( V_258 ) ) )
goto V_270;
if ( ! F_120 ( V_109 , F_71 ( V_258 ) ) )
goto V_270;
if ( ! F_121 ( V_109 , F_72 ( V_258 ) ) )
goto V_270;
if ( ! F_122 ( V_109 , V_271 , V_139 -> V_141 , 1 , 0 ) )
goto V_270;
for ( V_9 = 0 ; V_9 < F_123 ( V_258 ) ; V_9 ++ ) {
T_19 * V_272 ;
V_272 = F_76 ( V_258 , V_9 ) ;
if ( ! F_124 ( V_109 , V_272 , - 1 ) )
goto V_270;
}
V_261 = F_125 ( V_258 ) ;
for ( V_9 = 0 ; V_9 < F_126 ( V_261 ) ; V_9 ++ ) {
T_16 * V_273 , * V_274 ;
V_273 = F_127 ( V_261 , V_9 ) ;
if ( ! F_128 ( V_139 , & V_274 , & V_273 -> V_275 ) ) {
V_274 = F_129 ( V_273 ) ;
if ( ! V_274 )
goto V_270;
if ( ! F_130 ( V_109 , V_274 ) ) {
F_131 ( V_274 ) ;
goto V_270;
}
}
}
if ( V_259 && V_260 && ! F_132 ( V_109 , V_259 , V_260 ) )
goto V_270;
return V_109 ;
V_270:
F_29 ( V_262 , V_36 ) ;
F_68 ( V_109 ) ;
return NULL ;
}
int F_133 ( T_1 * V_6 , int V_276 , void * V_246 )
{
return F_134 ( & V_6 -> V_277 , V_276 , V_246 ) ;
}
void * F_135 ( T_1 * V_6 , int V_276 )
{
return F_136 ( & V_6 -> V_277 , V_276 ) ;
}
int F_137 ( T_1 * V_6 )
{
return V_6 -> error ;
}
void F_138 ( T_1 * V_6 , int V_13 )
{
V_6 -> error = V_13 ;
}
int F_139 ( T_1 * V_6 )
{
return V_6 -> V_14 ;
}
void F_140 ( T_1 * V_6 , int V_12 )
{
V_6 -> V_14 = V_12 ;
}
T_2 * F_141 ( T_1 * V_6 )
{
return V_6 -> V_15 ;
}
void F_142 ( T_1 * V_6 , T_2 * V_3 )
{
V_6 -> V_15 = V_3 ;
}
T_8 * F_143 ( T_1 * V_6 )
{
return V_6 -> V_120 ;
}
T_1 * F_144 ( T_1 * V_6 )
{
return V_6 -> V_58 ;
}
void F_145 ( T_1 * V_6 , T_2 * V_3 )
{
V_6 -> V_22 = V_3 ;
}
int F_146 ( T_1 * V_6 , int V_45 )
{
return F_147 ( V_6 , 0 , V_45 , 0 ) ;
}
int F_148 ( T_1 * V_6 , int V_49 )
{
return F_147 ( V_6 , 0 , 0 , V_49 ) ;
}
int F_147 ( T_1 * V_6 , int V_278 ,
int V_45 , int V_49 )
{
int V_276 ;
if ( ! V_45 )
V_45 = V_278 ;
if ( V_45 ) {
T_20 * V_279 ;
V_276 = F_149 ( V_45 ) ;
if ( V_276 == - 1 ) {
F_29 ( V_280 ,
V_281 ) ;
return 0 ;
}
V_279 = F_150 ( V_276 ) ;
if ( V_279 -> V_49 == V_282 ) {
V_276 = F_149 ( V_278 ) ;
if ( V_276 == - 1 ) {
F_29 ( V_280 ,
V_281 ) ;
return 0 ;
}
V_279 = F_150 ( V_276 ) ;
}
if ( ! V_49 )
V_49 = V_279 -> V_49 ;
}
if ( V_49 ) {
V_276 = F_151 ( V_49 ) ;
if ( V_276 == - 1 ) {
F_29 ( V_280 ,
V_283 ) ;
return 0 ;
}
}
if ( V_45 && ! V_6 -> V_20 -> V_45 )
V_6 -> V_20 -> V_45 = V_45 ;
if ( V_49 && ! V_6 -> V_20 -> V_49 )
V_6 -> V_20 -> V_49 = V_49 ;
return 1 ;
}
T_1 * F_152 ( void )
{
T_1 * V_6 = F_153 ( sizeof( * V_6 ) ) ;
if ( V_6 == NULL ) {
F_29 ( V_284 , V_36 ) ;
return NULL ;
}
return V_6 ;
}
void F_154 ( T_1 * V_6 )
{
if ( V_6 == NULL )
return;
F_89 ( V_6 ) ;
F_57 ( V_6 ) ;
}
void F_89 ( T_1 * V_6 )
{
if ( V_6 -> V_285 != NULL ) {
V_6 -> V_285 ( V_6 ) ;
V_6 -> V_285 = NULL ;
}
if ( V_6 -> V_20 != NULL ) {
if ( V_6 -> V_58 == NULL )
F_155 ( V_6 -> V_20 ) ;
V_6 -> V_20 = NULL ;
}
F_156 ( V_6 -> V_214 ) ;
V_6 -> V_214 = NULL ;
F_11 ( V_6 -> V_16 , V_11 ) ;
V_6 -> V_16 = NULL ;
F_157 ( V_286 , V_6 , & ( V_6 -> V_277 ) ) ;
memset ( & V_6 -> V_277 , 0 , sizeof( V_6 -> V_277 ) ) ;
}
void F_158 ( T_1 * V_6 , int V_12 )
{
F_159 ( V_6 -> V_20 , V_12 ) ;
}
void F_160 ( T_1 * V_6 , unsigned long V_26 )
{
F_161 ( V_6 -> V_20 , V_26 ) ;
}
void F_162 ( T_1 * V_6 , unsigned long V_26 ,
T_9 V_255 )
{
F_163 ( V_6 -> V_20 , V_255 ) ;
}
T_2 * F_164 ( T_1 * V_6 )
{
return V_6 -> V_22 ;
}
void F_165 ( T_1 * V_6 ,
T_21 V_18 )
{
V_6 -> V_18 = V_18 ;
}
T_21 F_166 ( T_1 * V_6 )
{
return V_6 -> V_18 ;
}
void F_167 ( T_1 * V_6 ,
T_22 V_27 )
{
V_6 -> V_27 = V_27 ;
}
T_22 F_168 ( T_1 * V_6 )
{
return V_6 -> V_27 ;
}
T_23 F_169 ( T_1 * V_6 )
{
return V_6 -> V_287 ;
}
T_24 F_170 ( T_1 * V_6 )
{
return V_6 -> F_34 ;
}
T_25 F_171 ( T_1 * V_6 )
{
return V_6 -> V_25 ;
}
T_26 F_172 ( T_1 * V_6 )
{
return V_6 -> V_117 ;
}
T_27 F_173 ( T_1 * V_6 )
{
return V_6 -> V_121 ;
}
T_28 F_174 ( T_1 * V_6 )
{
return V_6 -> V_122 ;
}
T_29 F_175 ( T_1 * V_6 )
{
return V_6 -> V_29 ;
}
T_30 F_176 ( T_1 * V_6 )
{
return V_6 -> V_10 ;
}
T_31 F_177 ( T_1 * V_6 )
{
return V_6 -> V_194 ;
}
T_32 F_178 ( T_1 * V_6 )
{
return V_6 -> V_285 ;
}
T_33 * F_179 ( T_1 * V_6 )
{
return V_6 -> V_214 ;
}
int F_180 ( T_1 * V_6 )
{
return V_6 -> V_215 ;
}
int F_181 ( T_1 * V_6 )
{
return V_6 -> V_38 ;
}
int F_182 ( T_1 * V_6 , const char * V_89 )
{
const T_7 * V_20 ;
V_20 = F_183 ( V_89 ) ;
if ( ! V_20 )
return 0 ;
return F_184 ( V_6 -> V_20 , V_20 ) ;
}
T_7 * F_185 ( T_1 * V_6 )
{
return V_6 -> V_20 ;
}
void F_87 ( T_1 * V_6 , T_7 * V_20 )
{
F_155 ( V_6 -> V_20 ) ;
V_6 -> V_20 = V_20 ;
}
void F_186 ( T_1 * V_6 , T_3 * V_30 )
{
V_6 -> V_30 = V_30 ;
}
static unsigned char * F_187 (
T_2 * V_22 ,
T_34 V_288 ,
unsigned int * V_289 )
{
unsigned char * V_290 = NULL ;
int V_291 ;
switch ( V_288 ) {
case V_292 :
V_291 = F_188 ( V_22 , & V_290 ) ;
break;
case V_293 :
V_291 = F_189 ( F_190 ( V_22 ) , & V_290 ) ;
break;
default:
F_29 ( V_294 , V_295 ) ;
return NULL ;
}
if ( V_291 < 0 || V_290 == NULL ) {
F_29 ( V_294 , V_36 ) ;
return NULL ;
}
* V_289 = ( unsigned int ) V_291 ;
return V_290 ;
}
static int F_191 ( T_1 * V_6 , T_2 * V_22 , int V_12 )
{
T_3 * V_30 = V_6 -> V_30 ;
unsigned V_296 = V_297 ;
unsigned V_288 = V_297 ;
unsigned V_298 = V_297 ;
unsigned V_299 = V_297 ;
unsigned char * V_300 = NULL ;
unsigned int V_289 = 0 ;
unsigned char V_301 [ V_302 ] ;
unsigned char * V_303 = NULL ;
unsigned int V_304 = 0 ;
int V_9 ;
int V_305 ;
int V_306 = 0 ;
T_35 * V_255 = NULL ;
T_36 V_307 ;
V_307 = ( V_12 == 0 ) ? V_308 : V_309 ;
if ( V_12 >= V_6 -> V_38 )
V_307 &= V_310 ;
if ( V_30 -> V_105 >= 0 )
V_307 &= ~ V_310 ;
V_305 = ( V_30 -> V_311 & V_307 ) ? F_192 ( V_30 -> V_312 ) : 0 ;
for ( V_9 = 0 ; V_306 == 0 && V_9 < V_305 ; ++ V_9 ) {
V_255 = F_193 ( V_30 -> V_312 , V_9 ) ;
if ( ( F_194 ( V_255 -> V_296 ) & V_307 ) == 0 )
continue;
if ( V_255 -> V_296 != V_296 ) {
V_296 = V_255 -> V_296 ;
V_299 = V_297 ;
V_298 = V_30 -> V_313 -> V_314 [ V_255 -> V_299 ] ;
}
if ( V_255 -> V_288 != V_288 ) {
V_288 = V_255 -> V_288 ;
F_57 ( V_300 ) ;
V_300 = F_187 ( V_22 , V_288 , & V_289 ) ;
if ( V_300 == NULL )
return - 1 ;
V_299 = V_297 ;
V_298 = V_30 -> V_313 -> V_314 [ V_255 -> V_299 ] ;
} else if ( V_255 -> V_299 != V_315 ) {
if ( V_30 -> V_313 -> V_314 [ V_255 -> V_299 ] < V_298 )
continue;
}
if ( V_255 -> V_299 != V_299 ) {
const T_18 * V_260 = V_30 -> V_313 -> V_316 [ V_299 = V_255 -> V_299 ] ;
V_303 = V_300 ;
V_304 = V_289 ;
if ( V_260 != NULL ) {
V_303 = V_301 ;
if ( ! F_195 ( V_300 , V_289 , V_303 , & V_304 , V_260 , 0 ) ) {
V_306 = - 1 ;
break;
}
}
}
if ( V_304 == V_255 -> V_317 &&
memcmp ( V_303 , V_255 -> V_246 , V_304 ) == 0 ) {
if ( F_194 ( V_296 ) & V_318 )
V_306 = 1 ;
if ( V_306 || V_30 -> V_105 < 0 ) {
V_30 -> V_105 = V_12 ;
V_30 -> V_319 = V_255 ;
F_57 ( V_30 -> V_320 ) ;
V_30 -> V_320 = V_22 ;
F_10 ( V_22 ) ;
}
break;
}
}
F_57 ( V_300 ) ;
return V_306 ;
}
static int F_64 ( T_1 * V_6 , int V_12 )
{
T_3 * V_30 = V_6 -> V_30 ;
int V_306 = 0 ;
T_2 * V_22 ;
if ( ! F_63 ( V_30 ) || V_12 == 0 )
return V_48 ;
V_22 = F_8 ( V_6 -> V_16 , V_12 ) ;
if ( V_22 != NULL && ( V_306 = F_191 ( V_6 , V_22 , V_12 ) ) < 0 )
return V_52 ;
if ( V_306 > 0 ) {
V_6 -> V_38 = V_12 - 1 ;
return V_51 ;
}
return V_48 ;
}
static int F_196 ( T_1 * V_6 )
{
T_3 * V_30 = V_6 -> V_30 ;
T_35 * V_255 ;
int V_19 = V_6 -> V_38 ;
T_2 * V_22 = F_8 ( V_6 -> V_16 , V_19 - 1 ) ;
int V_305 = F_192 ( V_30 -> V_312 ) ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_305 ; ++ V_9 ) {
V_255 = F_193 ( V_30 -> V_312 , V_9 ) ;
if ( V_255 -> V_296 != V_321 ||
V_255 -> V_288 != V_293 ||
V_255 -> V_299 != V_315 ||
F_108 ( V_22 , V_255 -> V_322 ) <= 0 )
continue;
V_11 ( V_30 -> V_320 ) ;
V_30 -> V_320 = NULL ;
V_6 -> V_212 = 1 ;
V_30 -> V_105 = V_19 - 1 ;
V_30 -> V_319 = V_255 ;
V_19 = F_7 ( V_6 -> V_16 ) ;
for (; V_19 > V_6 -> V_38 ; -- V_19 )
V_11 ( F_104 ( V_6 -> V_16 ) ) ;
return V_51 ;
}
return V_48 ;
}
static void F_197 ( T_3 * V_30 )
{
V_11 ( V_30 -> V_320 ) ;
V_30 -> V_320 = NULL ;
V_30 -> V_319 = NULL ;
V_30 -> V_105 = - 1 ;
V_30 -> V_104 = - 1 ;
}
static int F_198 ( T_1 * V_6 , T_2 * V_22 )
{
int V_13 = F_23 ( NULL , V_22 , NULL , V_6 -> V_20 -> V_26 ) ;
if ( V_13 == V_17 )
return 1 ;
return F_12 ( V_6 , V_22 , 0 , V_13 ) ;
}
static int F_33 ( T_1 * V_6 )
{
T_2 * V_22 = V_6 -> V_22 ;
T_3 * V_30 = V_6 -> V_30 ;
int V_306 ;
int V_119 ;
F_197 ( V_30 ) ;
V_306 = F_191 ( V_6 , V_6 -> V_22 , 0 ) ;
V_119 = V_306 != 0 || ( ! F_63 ( V_30 ) && V_30 -> V_105 < 0 ) ;
if ( V_119 )
F_22 ( NULL , V_6 -> V_16 ) ;
if ( V_306 > 0 ) {
if ( ! F_198 ( V_6 , V_22 ) )
return 0 ;
if ( ( V_30 -> V_26 & V_323 ) == 0 &&
! F_21 ( V_6 ) )
return 0 ;
V_6 -> V_14 = 0 ;
V_6 -> V_15 = V_22 ;
return V_6 -> V_18 ( 1 , V_6 ) ;
}
if ( V_306 < 0 ) {
V_6 -> V_14 = 0 ;
V_6 -> V_15 = V_22 ;
V_6 -> error = V_37 ;
return - 1 ;
}
if ( V_119 ) {
if ( ! F_198 ( V_6 , V_22 ) )
return 0 ;
return F_12 ( V_6 , V_22 , 0 , V_324 ) ;
}
return F_17 ( V_6 ) ;
}
static int V_287 ( T_2 * * V_41 , T_1 * V_6 , T_2 * V_22 )
{
F_5 ( T_2 ) * V_325 = V_6 -> V_16 ;
int V_1 ;
V_6 -> V_16 = NULL ;
V_1 = V_6 -> V_287 ( V_41 , V_6 , V_22 ) ;
V_6 -> V_16 = V_325 ;
return V_1 ;
}
static int F_18 ( T_1 * V_6 )
{
T_3 * V_30 = V_6 -> V_30 ;
int V_19 = F_7 ( V_6 -> V_16 ) ;
T_2 * V_22 = F_8 ( V_6 -> V_16 , V_19 - 1 ) ;
int V_326 = F_2 ( V_22 ) ;
F_5 ( T_2 ) * V_327 = NULL ;
unsigned int V_328 ;
int V_329 = 0 ;
int V_330 = 0 ;
int V_49 = V_48 ;
int V_331 = 0 ;
int V_12 ;
int V_1 = 0 ;
int V_9 ;
F_199 ( V_19 == 1 && V_6 -> V_38 == V_19 ) ;
#define F_200 (1 << 0)
#define F_201 (1 << 1)
#define F_202 (1 << 2)
V_328 = ( V_6 -> V_167 != NULL ) ? F_200 : 0 ;
if ( F_203 ( V_30 ) || ! F_204 ( V_30 ) ) {
if ( V_328 == 0 || V_6 -> V_20 -> V_26 & V_332 )
V_328 |= F_201 ;
else if ( ! ( V_6 -> V_20 -> V_26 & V_333 ) )
V_330 = 1 ;
V_329 = 1 ;
}
if ( V_6 -> V_167 && ( V_327 = F_205 ( V_6 -> V_167 ) ) == NULL ) {
F_29 ( V_334 , V_36 ) ;
V_6 -> error = V_37 ;
return 0 ;
}
if ( F_32 ( V_30 ) && V_30 -> V_7 != NULL ) {
if ( V_327 == NULL && ( V_327 = F_30 () ) == NULL ) {
F_29 ( V_334 , V_36 ) ;
V_6 -> error = V_37 ;
return 0 ;
}
for ( V_9 = 0 ; V_9 < F_7 ( V_30 -> V_7 ) ; ++ V_9 ) {
if ( ! F_31 ( V_327 , F_8 ( V_30 -> V_7 , V_9 ) ) ) {
F_206 ( V_327 ) ;
F_29 ( V_334 , V_36 ) ;
V_6 -> error = V_37 ;
return 0 ;
}
}
}
if ( V_6 -> V_20 -> V_12 > V_335 / 2 )
V_6 -> V_20 -> V_12 = V_335 / 2 ;
V_12 = V_6 -> V_20 -> V_12 + 1 ;
while ( V_328 != 0 ) {
T_2 * V_3 ;
T_2 * V_8 = NULL ;
if ( ( V_328 & F_201 ) != 0 ) {
V_9 = V_19 = F_7 ( V_6 -> V_16 ) ;
if ( ( V_328 & F_202 ) != 0 ) {
V_9 = V_331 ;
}
V_3 = F_8 ( V_6 -> V_16 , V_9 - 1 ) ;
V_1 = ( V_12 < V_19 ) ? 0 : V_287 ( & V_8 , V_6 , V_3 ) ;
if ( V_1 < 0 ) {
V_49 = V_52 ;
V_6 -> error = V_336 ;
V_328 = 0 ;
continue;
}
if ( V_1 > 0 ) {
if ( ( V_328 & F_202 ) != 0 ) {
F_199 ( V_19 > V_9 && V_9 > 0 && V_326 == 0 ) ;
V_328 &= ~ F_202 ;
for (; V_19 > V_9 ; -- V_19 )
V_11 ( F_104 ( V_6 -> V_16 ) ) ;
V_6 -> V_38 = V_19 ;
if ( F_32 ( V_30 ) &&
V_30 -> V_105 >= V_6 -> V_38 ) {
V_30 -> V_105 = - 1 ;
V_11 ( V_30 -> V_320 ) ;
V_30 -> V_320 = NULL ;
}
if ( F_32 ( V_30 ) &&
V_30 -> V_104 >= V_6 -> V_38 )
V_30 -> V_104 = - 1 ;
}
if ( V_326 == 0 ) {
if ( ! F_31 ( V_6 -> V_16 , V_3 = V_8 ) ) {
V_11 ( V_8 ) ;
F_29 ( V_334 , V_36 ) ;
V_49 = V_52 ;
V_6 -> error = V_37 ;
V_328 = 0 ;
continue;
}
V_326 = F_2 ( V_3 ) ;
} else if ( V_19 == V_6 -> V_38 ) {
if ( F_9 ( V_3 , V_8 ) != 0 ) {
V_11 ( V_8 ) ;
V_1 = 0 ;
} else {
V_11 ( V_3 ) ;
V_6 -> V_38 = -- V_19 ;
( void ) F_65 ( V_6 -> V_16 , V_19 , V_3 = V_8 ) ;
}
}
if ( V_1 ) {
F_199 ( V_6 -> V_38 <= V_19 ) ;
V_328 &= ~ F_200 ;
switch ( V_49 = F_62 ( V_6 , V_19 ) ) {
case V_51 :
case V_52 :
V_328 = 0 ;
continue;
}
if ( V_326 == 0 )
continue;
}
}
if ( ( V_328 & F_200 ) == 0 ) {
if ( ( V_328 & F_202 ) != 0 && -- V_331 > 0 )
continue;
if ( ! V_330 || ( V_328 & F_202 ) != 0 ||
V_6 -> V_38 < 2 )
break;
V_328 |= F_202 ;
V_331 = V_6 -> V_38 - 1 ;
V_326 = 0 ;
}
}
if ( ( V_328 & F_200 ) != 0 ) {
V_19 = F_7 ( V_6 -> V_16 ) ;
F_199 ( V_19 == V_6 -> V_38 ) ;
V_3 = F_8 ( V_6 -> V_16 , V_19 - 1 ) ;
V_8 = ( V_326 || V_12 < V_19 ) ? NULL : F_37 ( V_6 , V_327 , V_3 ) ;
if ( V_8 == NULL ) {
V_328 &= ~ F_200 ;
if ( V_329 )
V_328 |= F_201 ;
continue;
}
( void ) F_207 ( V_327 , V_8 ) ;
if ( ! F_31 ( V_6 -> V_16 , V_8 ) ) {
F_29 ( V_334 , V_36 ) ;
V_49 = V_52 ;
V_6 -> error = V_37 ;
V_328 = 0 ;
continue;
}
F_10 ( V_3 = V_8 ) ;
++ V_6 -> V_38 ;
V_326 = F_2 ( V_8 ) ;
switch ( V_49 = F_64 ( V_6 , V_6 -> V_38 - 1 ) ) {
case V_51 :
case V_52 :
V_328 = 0 ;
continue;
}
}
}
F_206 ( V_327 ) ;
V_19 = F_7 ( V_6 -> V_16 ) ;
if ( V_19 <= V_12 ) {
if ( V_49 == V_48 && F_208 ( V_30 ) )
V_49 = F_196 ( V_6 ) ;
if ( V_49 == V_48 && V_19 == V_6 -> V_38 )
V_49 = F_62 ( V_6 , V_19 ) ;
}
switch ( V_49 ) {
case V_51 :
return 1 ;
case V_52 :
return 0 ;
case V_48 :
default:
V_19 = F_7 ( V_6 -> V_16 ) ;
if ( V_19 > V_12 )
return F_12 ( V_6 , NULL , V_19 - 1 ,
V_337 ) ;
if ( F_32 ( V_30 ) &&
( ! F_203 ( V_30 ) || V_30 -> V_104 >= 0 ) )
return F_12 ( V_6 , NULL , V_19 - 1 , V_324 ) ;
if ( V_326 && F_7 ( V_6 -> V_16 ) == 1 )
return F_12 ( V_6 , NULL , V_19 - 1 ,
V_338 ) ;
if ( V_326 )
return F_12 ( V_6 , NULL , V_19 - 1 ,
V_339 ) ;
if ( V_6 -> V_38 < V_19 )
return F_12 ( V_6 , NULL , V_19 - 1 ,
V_340 ) ;
return F_12 ( V_6 , NULL , V_19 - 1 ,
V_341 ) ;
}
}
static int F_15 ( T_1 * V_6 , T_2 * V_22 )
{
T_15 * V_233 = F_99 ( V_22 ) ;
int V_342 = V_6 -> V_20 -> V_21 ;
if ( V_233 == NULL )
return 0 ;
if ( V_342 <= 0 )
return 1 ;
if ( V_342 > V_343 )
V_342 = V_343 ;
return F_209 ( V_233 ) >= V_344 [ V_342 - 1 ] ;
}
static int F_16 ( T_1 * V_6 , T_2 * V_22 )
{
int V_135 = F_210 ( V_22 ) ;
int V_345 = V_346 ;
int V_347 = - 1 ;
int V_342 = V_6 -> V_20 -> V_21 ;
if ( V_342 <= 0 )
return 1 ;
if ( V_342 > V_343 )
V_342 = V_343 ;
if ( V_135 && F_211 ( V_135 , & V_345 , NULL ) ) {
const T_18 * V_260 ;
if ( V_345 != V_346 && ( V_260 = F_212 ( V_345 ) ) != NULL )
V_347 = F_213 ( V_260 ) * 4 ;
}
return V_347 >= V_344 [ V_342 - 1 ] ;
}
