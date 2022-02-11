static int F_1 ( const T_1 * const * V_1 , const T_1 * const * V_2 )
{
return ( * V_1 ) -> V_3 - ( * V_2 ) -> V_3 ;
}
int F_2 ( T_2 * V_4 , int V_5 , int V_6 )
{
int V_7 ;
const T_1 * V_8 ;
if ( ! ( V_4 -> V_9 & V_10 ) ) {
F_3 ( V_4 -> V_11 ) ;
F_4 ( V_4 ) ;
F_5 ( V_4 -> V_11 ) ;
}
if ( V_5 == - 1 )
return 1 ;
V_7 = F_6 ( V_5 ) ;
if ( V_7 == - 1 )
return - 1 ;
V_8 = F_7 ( V_7 ) ;
return V_8 -> V_12 ( V_8 , V_4 , V_6 ) ;
}
int F_8 ( int * V_13 , int V_3 )
{
if ( F_6 ( V_3 ) == - 1 ) {
F_9 ( V_14 , V_15 ) ;
return 0 ;
}
* V_13 = V_3 ;
return 1 ;
}
int F_10 ( void )
{
if ( ! V_16 )
return V_17 ;
return F_11 ( V_16 ) + V_17 ;
}
T_1 * F_7 ( int V_7 )
{
if ( V_7 < 0 )
return NULL ;
if ( V_7 < ( int ) V_17 )
return V_18 + V_7 ;
return F_12 ( V_16 , V_7 - V_17 ) ;
}
int F_13 ( const char * V_19 )
{
int V_20 ;
T_1 * V_21 ;
for ( V_20 = 0 ; V_20 < F_10 () ; V_20 ++ ) {
V_21 = F_7 ( V_20 ) ;
if ( strcmp ( V_21 -> V_19 , V_19 ) == 0 )
return V_20 ;
}
return - 1 ;
}
int F_6 ( int V_3 )
{
T_1 V_22 ;
int V_7 ;
if ( ( V_3 >= V_23 ) && ( V_3 <= V_24 ) )
return V_3 - V_23 ;
V_22 . V_3 = V_3 ;
if ( ! V_16 )
return - 1 ;
V_7 = F_14 ( V_16 , & V_22 ) ;
if ( V_7 == - 1 )
return - 1 ;
return V_7 + V_17 ;
}
int F_15 ( int V_5 , int V_25 , int V_26 ,
int (* F_16) ( const T_1 * , const T_2 * , int ) ,
const char * V_27 , const char * V_19 , void * V_28 )
{
int V_7 ;
T_1 * V_29 ;
V_26 &= ~ V_30 ;
V_26 |= V_31 ;
V_7 = F_6 ( V_5 ) ;
if ( V_7 == - 1 ) {
if ( ( V_29 = F_17 ( sizeof( * V_29 ) ) ) == NULL ) {
F_9 ( V_32 , V_33 ) ;
return 0 ;
}
V_29 -> V_26 = V_30 ;
} else
V_29 = F_7 ( V_7 ) ;
if ( V_29 -> V_26 & V_31 ) {
F_18 ( V_29 -> V_27 ) ;
F_18 ( V_29 -> V_19 ) ;
}
V_29 -> V_27 = F_19 ( V_27 ) ;
V_29 -> V_19 = F_19 ( V_19 ) ;
if ( ! V_29 -> V_27 || ! V_29 -> V_19 ) {
F_9 ( V_32 , V_33 ) ;
goto V_34;
}
V_29 -> V_26 &= V_30 ;
V_29 -> V_26 |= V_26 ;
V_29 -> V_3 = V_5 ;
V_29 -> V_25 = V_25 ;
V_29 -> V_12 = F_16 ;
V_29 -> V_35 = V_28 ;
if ( V_7 == - 1 ) {
if ( V_16 == NULL
&& ( V_16 = F_20 ( F_1 ) ) == NULL ) {
F_9 ( V_32 , V_33 ) ;
goto V_34;
}
if ( ! F_21 ( V_16 , V_29 ) ) {
F_9 ( V_32 , V_33 ) ;
goto V_34;
}
}
return 1 ;
V_34:
if ( V_7 == - 1 ) {
F_18 ( V_29 -> V_27 ) ;
F_18 ( V_29 -> V_19 ) ;
F_18 ( V_29 ) ;
}
return 0 ;
}
static void F_22 ( T_1 * V_13 )
{
if ( ! V_13 )
return;
if ( V_13 -> V_26 & V_30 ) {
if ( V_13 -> V_26 & V_31 ) {
F_18 ( V_13 -> V_27 ) ;
F_18 ( V_13 -> V_19 ) ;
}
F_18 ( V_13 ) ;
}
}
void F_23 ( void )
{
F_24 ( V_16 , F_22 ) ;
V_16 = NULL ;
}
int F_25 ( const T_1 * V_36 )
{
return V_36 -> V_3 ;
}
char * F_26 ( const T_1 * V_36 )
{
return V_36 -> V_27 ;
}
char * F_27 ( const T_1 * V_36 )
{
return V_36 -> V_19 ;
}
int F_28 ( const T_1 * V_36 )
{
return V_36 -> V_25 ;
}
static int F_29 ( const int * V_1 , const int * V_2 )
{
return * V_1 - * V_2 ;
}
int F_30 ( T_3 * V_37 )
{
static const int V_38 [] = {
V_39 ,
V_40 ,
V_41 ,
V_42 ,
V_43 ,
V_44 ,
#ifndef F_31
V_45 ,
V_46 ,
#endif
V_47 ,
V_48 ,
V_49 ,
V_50 ,
V_51
} ;
int V_52 = F_32 ( F_33 ( V_37 ) ) ;
if ( V_52 == V_53 )
return 0 ;
if ( F_34 ( & V_52 , V_38 , F_35 ( V_38 ) ) )
return 1 ;
return 0 ;
}
static void F_36 ( T_2 * V_4 , T_4 * V_54 )
{
T_5 * V_55 = NULL ;
int V_20 ;
if ( V_54 -> V_56 ) {
if ( V_54 -> V_56 -> V_57 > 0 )
V_54 -> V_58 = V_54 -> V_56 -> V_59 [ 0 ] ;
if ( V_54 -> V_56 -> V_57 > 1 )
V_54 -> V_58 |= ( V_54 -> V_56 -> V_59 [ 1 ] << 8 ) ;
V_54 -> V_58 &= V_60 ;
} else
V_54 -> V_58 = V_60 ;
if ( ! V_54 -> V_61 || ( V_54 -> V_61 -> type != 1 ) )
return;
for ( V_20 = 0 ; V_20 < F_37 ( V_54 -> V_62 ) ; V_20 ++ ) {
T_6 * V_63 = F_38 ( V_54 -> V_62 , V_20 ) ;
if ( V_63 -> type == V_64 ) {
V_55 = V_63 -> V_65 . V_66 ;
break;
}
}
if ( ! V_55 )
V_55 = F_39 ( V_4 ) ;
F_40 ( V_54 -> V_61 , V_55 ) ;
}
static void F_41 ( T_2 * V_4 )
{
int V_20 ;
V_4 -> V_67 = F_42 ( V_4 , V_68 , NULL , NULL ) ;
for ( V_20 = 0 ; V_20 < F_43 ( V_4 -> V_67 ) ; V_20 ++ )
F_36 ( V_4 , F_44 ( V_4 -> V_67 , V_20 ) ) ;
}
static void F_4 ( T_2 * V_4 )
{
T_7 * V_69 ;
T_8 * V_70 ;
T_9 * V_71 ;
T_9 * V_72 ;
T_10 * V_73 ;
T_3 * V_37 ;
int V_20 ;
if ( V_4 -> V_9 & V_10 )
return;
F_45 ( V_4 , F_46 () , V_4 -> V_74 , NULL ) ;
if ( ! F_47 ( V_4 ) )
V_4 -> V_9 |= V_75 ;
if ( ( V_69 = F_42 ( V_4 , V_42 , NULL , NULL ) ) ) {
if ( V_69 -> V_6 )
V_4 -> V_9 |= V_76 ;
if ( V_69 -> V_77 ) {
if ( ( V_69 -> V_77 -> type == V_78 )
|| ! V_69 -> V_6 ) {
V_4 -> V_9 |= V_79 ;
V_4 -> V_80 = 0 ;
} else
V_4 -> V_80 = F_48 ( V_69 -> V_77 ) ;
} else
V_4 -> V_80 = - 1 ;
F_49 ( V_69 ) ;
V_4 -> V_9 |= V_81 ;
}
if ( ( V_70 = F_42 ( V_4 , V_48 , NULL , NULL ) ) ) {
if ( V_4 -> V_9 & V_76
|| F_50 ( V_4 , V_41 , - 1 ) >= 0
|| F_50 ( V_4 , V_82 , - 1 ) >= 0 ) {
V_4 -> V_9 |= V_79 ;
}
if ( V_70 -> V_83 ) {
V_4 -> V_84 = F_48 ( V_70 -> V_83 ) ;
} else
V_4 -> V_84 = - 1 ;
F_51 ( V_70 ) ;
V_4 -> V_9 |= V_85 ;
}
if ( ( V_71 = F_42 ( V_4 , V_40 , NULL , NULL ) ) ) {
if ( V_71 -> V_57 > 0 ) {
V_4 -> V_86 = V_71 -> V_59 [ 0 ] ;
if ( V_71 -> V_57 > 1 )
V_4 -> V_86 |= V_71 -> V_59 [ 1 ] << 8 ;
} else
V_4 -> V_86 = 0 ;
V_4 -> V_9 |= V_87 ;
F_52 ( V_71 ) ;
}
V_4 -> V_88 = 0 ;
if ( ( V_73 = F_42 ( V_4 , V_44 , NULL , NULL ) ) ) {
V_4 -> V_9 |= V_89 ;
for ( V_20 = 0 ; V_20 < F_53 ( V_73 ) ; V_20 ++ ) {
switch ( F_32 ( F_54 ( V_73 , V_20 ) ) ) {
case V_90 :
V_4 -> V_88 |= V_91 ;
break;
case V_92 :
V_4 -> V_88 |= V_93 ;
break;
case V_94 :
V_4 -> V_88 |= V_95 ;
break;
case V_96 :
V_4 -> V_88 |= V_97 ;
break;
case V_98 :
case V_99 :
V_4 -> V_88 |= V_100 ;
break;
case V_101 :
V_4 -> V_88 |= V_102 ;
break;
case V_103 :
V_4 -> V_88 |= V_104 ;
break;
case V_105 :
V_4 -> V_88 |= V_106 ;
break;
case V_107 :
V_4 -> V_88 |= V_108 ;
break;
}
}
F_55 ( V_73 , V_109 ) ;
}
if ( ( V_72 = F_42 ( V_4 , V_39 , NULL , NULL ) ) ) {
if ( V_72 -> V_57 > 0 )
V_4 -> V_110 = V_72 -> V_59 [ 0 ] ;
else
V_4 -> V_110 = 0 ;
V_4 -> V_9 |= V_111 ;
F_52 ( V_72 ) ;
}
V_4 -> V_112 = F_42 ( V_4 , V_113 , NULL , NULL ) ;
V_4 -> V_114 = F_42 ( V_4 , V_115 , NULL , NULL ) ;
if ( ! F_56 ( F_57 ( V_4 ) , F_39 ( V_4 ) ) ) {
V_4 -> V_9 |= V_116 ;
if ( F_58 ( V_4 , V_4 -> V_114 ) == V_117 &&
! F_59 ( V_4 , V_118 ) )
V_4 -> V_9 |= V_119 ;
}
V_4 -> V_120 = F_42 ( V_4 , V_41 , NULL , NULL ) ;
V_4 -> V_121 = F_42 ( V_4 , V_49 , & V_20 , NULL ) ;
if ( ! V_4 -> V_121 && ( V_20 != - 1 ) )
V_4 -> V_9 |= V_79 ;
F_41 ( V_4 ) ;
#ifndef F_31
V_4 -> V_122 = F_42 ( V_4 , V_45 , NULL , NULL ) ;
V_4 -> V_123 = F_42 ( V_4 , V_46 ,
NULL , NULL ) ;
#endif
for ( V_20 = 0 ; V_20 < F_60 ( V_4 ) ; V_20 ++ ) {
V_37 = F_61 ( V_4 , V_20 ) ;
if ( F_32 ( F_33 ( V_37 ) )
== V_124 )
V_4 -> V_9 |= V_125 ;
if ( ! F_62 ( V_37 ) )
continue;
if ( ! F_30 ( V_37 ) ) {
V_4 -> V_9 |= V_126 ;
break;
}
}
V_4 -> V_9 |= V_10 ;
}
static int F_63 ( const T_2 * V_4 )
{
if ( F_59 ( V_4 , V_118 ) )
return 0 ;
if ( V_4 -> V_9 & V_81 ) {
if ( V_4 -> V_9 & V_76 )
return 1 ;
else
return 0 ;
} else {
if ( ( V_4 -> V_9 & V_127 ) == V_127 )
return 3 ;
else if ( V_4 -> V_9 & V_87 )
return 4 ;
else if ( V_4 -> V_9 & V_111 && V_4 -> V_110 & V_128 )
return 5 ;
return 0 ;
}
}
void F_64 ( T_2 * V_4 )
{
V_4 -> V_9 |= V_85 ;
}
void F_65 ( T_2 * V_4 , long V_129 )
{
V_4 -> V_84 = V_129 ;
}
int F_66 ( T_2 * V_4 )
{
if ( ! ( V_4 -> V_9 & V_10 ) ) {
F_3 ( V_4 -> V_11 ) ;
F_4 ( V_4 ) ;
F_5 ( V_4 -> V_11 ) ;
}
return F_63 ( V_4 ) ;
}
static int F_67 ( const T_2 * V_4 )
{
int V_130 ;
V_130 = F_63 ( V_4 ) ;
if ( ! V_130 )
return 0 ;
if ( V_130 != 5 || V_4 -> V_110 & V_131 )
return V_130 ;
else
return 0 ;
}
static int F_68 ( const T_1 * V_36 , const T_2 * V_4 ,
int V_6 )
{
if ( F_69 ( V_4 , V_93 ) )
return 0 ;
if ( V_6 )
return F_67 ( V_4 ) ;
if ( F_59 ( V_4 , V_132 | V_133 ) )
return 0 ;
if ( F_70 ( V_4 , V_134 ) )
return 0 ;
return 1 ;
}
static int F_71 ( const T_1 * V_36 , const T_2 * V_4 ,
int V_6 )
{
if ( F_69 ( V_4 , V_91 | V_100 ) )
return 0 ;
if ( V_6 )
return F_67 ( V_4 ) ;
if ( F_70 ( V_4 , V_135 ) )
return 0 ;
if ( F_59 ( V_4 , V_136 ) )
return 0 ;
return 1 ;
}
static int F_72 ( const T_1 * V_36 , const T_2 * V_4 ,
int V_6 )
{
int V_137 ;
V_137 = F_71 ( V_36 , V_4 , V_6 ) ;
if ( ! V_137 || V_6 )
return V_137 ;
if ( F_59 ( V_4 , V_138 ) )
return 0 ;
return V_137 ;
}
static int F_73 ( const T_2 * V_4 , int V_6 )
{
if ( F_69 ( V_4 , V_95 ) )
return 0 ;
if ( V_6 ) {
int V_130 ;
V_130 = F_63 ( V_4 ) ;
if ( ! V_130 )
return 0 ;
if ( V_130 != 5 || V_4 -> V_110 & V_139 )
return V_130 ;
else
return 0 ;
}
if ( V_4 -> V_9 & V_111 ) {
if ( V_4 -> V_110 & V_140 )
return 1 ;
if ( V_4 -> V_110 & V_134 )
return 2 ;
return 0 ;
}
return 1 ;
}
static int F_74 ( const T_1 * V_36 , const T_2 * V_4 ,
int V_6 )
{
int V_137 ;
V_137 = F_73 ( V_4 , V_6 ) ;
if ( ! V_137 || V_6 )
return V_137 ;
if ( F_59 ( V_4 , V_132 | V_141 ) )
return 0 ;
return V_137 ;
}
static int F_75 ( const T_1 * V_36 , const T_2 * V_4 ,
int V_6 )
{
int V_137 ;
V_137 = F_73 ( V_4 , V_6 ) ;
if ( ! V_137 || V_6 )
return V_137 ;
if ( F_59 ( V_4 , V_138 ) )
return 0 ;
return V_137 ;
}
static int F_76 ( const T_1 * V_36 , const T_2 * V_4 ,
int V_6 )
{
if ( V_6 ) {
int V_130 ;
if ( ( V_130 = F_63 ( V_4 ) ) != 2 )
return V_130 ;
else
return 0 ;
}
if ( F_59 ( V_4 , V_142 ) )
return 0 ;
return 1 ;
}
static int F_77 ( const T_1 * V_36 , const T_2 * V_4 , int V_6 )
{
if ( V_6 )
return F_63 ( V_4 ) ;
return 1 ;
}
static int F_78 ( const T_1 * V_36 , const T_2 * V_4 ,
int V_6 )
{
int V_143 ;
if ( V_6 )
return F_63 ( V_4 ) ;
if ( ( V_4 -> V_9 & V_87 )
&& ( ( V_4 -> V_86 & ~ ( V_141 | V_132 ) ) ||
! ( V_4 -> V_86 & ( V_141 | V_132 ) ) ) )
return 0 ;
if ( ! ( V_4 -> V_9 & V_89 ) || V_4 -> V_88 != V_104 )
return 0 ;
V_143 = F_50 ( V_4 , V_44 , - 1 ) ;
if ( V_143 >= 0 ) {
T_3 * V_144 = F_61 ( ( T_2 * ) V_4 , V_143 ) ;
if ( ! F_62 ( V_144 ) )
return 0 ;
}
return 1 ;
}
static int F_79 ( const T_1 * V_36 , const T_2 * V_4 , int V_6 )
{
return 1 ;
}
int F_80 ( T_2 * V_145 , T_2 * V_146 )
{
if ( F_56 ( F_57 ( V_145 ) ,
F_39 ( V_146 ) ) )
return V_147 ;
F_4 ( V_145 ) ;
F_4 ( V_146 ) ;
if ( V_146 -> V_114 ) {
int V_137 = F_58 ( V_145 , V_146 -> V_114 ) ;
if ( V_137 != V_117 )
return V_137 ;
}
if ( V_146 -> V_9 & V_85 ) {
if ( F_59 ( V_145 , V_132 ) )
return V_148 ;
} else if ( F_59 ( V_145 , V_118 ) )
return V_149 ;
return V_117 ;
}
int F_58 ( T_2 * V_145 , T_11 * V_114 )
{
if ( ! V_114 )
return V_117 ;
if ( V_114 -> V_150 && V_145 -> V_112 &&
F_81 ( V_114 -> V_150 , V_145 -> V_112 ) )
return V_151 ;
if ( V_114 -> V_152 &&
F_82 ( F_83 ( V_145 ) , V_114 -> V_152 ) )
return V_153 ;
if ( V_114 -> V_145 ) {
T_12 * V_154 ;
T_6 * V_63 ;
T_5 * V_155 = NULL ;
int V_20 ;
V_154 = V_114 -> V_145 ;
for ( V_20 = 0 ; V_20 < F_37 ( V_154 ) ; V_20 ++ ) {
V_63 = F_38 ( V_154 , V_20 ) ;
if ( V_63 -> type == V_64 ) {
V_155 = V_63 -> V_65 . V_156 ;
break;
}
}
if ( V_155 && F_56 ( V_155 , F_39 ( V_145 ) ) )
return V_153 ;
}
return V_117 ;
}
T_13 F_84 ( T_2 * V_4 )
{
F_2 ( V_4 , - 1 , - 1 ) ;
return V_4 -> V_9 ;
}
T_13 F_85 ( T_2 * V_4 )
{
F_2 ( V_4 , - 1 , - 1 ) ;
if ( V_4 -> V_9 & V_87 )
return V_4 -> V_86 ;
return V_157 ;
}
T_13 F_86 ( T_2 * V_4 )
{
F_2 ( V_4 , - 1 , - 1 ) ;
if ( V_4 -> V_9 & V_89 )
return V_4 -> V_88 ;
return V_157 ;
}
const T_14 * F_87 ( T_2 * V_4 )
{
F_2 ( V_4 , - 1 , - 1 ) ;
return V_4 -> V_112 ;
}
long F_88 ( T_2 * V_4 )
{
if ( F_2 ( V_4 , - 1 , - 1 ) != 1
|| ( V_4 -> V_9 & V_81 ) == 0 )
return - 1 ;
return V_4 -> V_80 ;
}
long F_89 ( T_2 * V_4 )
{
if ( F_2 ( V_4 , - 1 , - 1 ) != 1
|| ( V_4 -> V_9 & V_85 ) == 0 )
return - 1 ;
return V_4 -> V_84 ;
}
