static int F_1 ( const T_1 * const * V_1 ,
const T_1 * const * V_2 )
{
return ( * V_1 ) -> V_3 - ( * V_2 ) -> V_3 ;
}
int F_2 ( T_2 * V_4 , int V_5 , int V_6 )
{
int V_7 ;
const T_1 * V_8 ;
if( ! ( V_4 -> V_9 & V_10 ) ) {
F_3 ( V_11 ) ;
F_4 ( V_4 ) ;
F_5 ( V_11 ) ;
}
if( V_5 == - 1 ) return 1 ;
V_7 = F_6 ( V_5 ) ;
if( V_7 == - 1 ) return - 1 ;
V_8 = F_7 ( V_7 ) ;
return V_8 -> V_12 ( V_8 , V_4 , V_6 ) ;
}
int F_8 ( int * V_13 , int V_3 )
{
if( F_6 ( V_3 ) == - 1 ) {
F_9 ( V_14 , V_15 ) ;
return 0 ;
}
* V_13 = V_3 ;
return 1 ;
}
int F_10 ( void )
{
if( ! V_16 ) return V_17 ;
return F_11 ( V_16 ) + V_17 ;
}
T_1 * F_7 ( int V_7 )
{
if( V_7 < 0 ) return NULL ;
if( V_7 < ( int ) V_17 ) return V_18 + V_7 ;
return F_12 ( V_16 , V_7 - V_17 ) ;
}
int F_13 ( char * V_19 )
{
int V_20 ;
T_1 * V_21 ;
for( V_20 = 0 ; V_20 < F_10 () ; V_20 ++ ) {
V_21 = F_7 ( V_20 ) ;
if( ! strcmp ( V_21 -> V_19 , V_19 ) ) return V_20 ;
}
return - 1 ;
}
int F_6 ( int V_3 )
{
T_1 V_22 ;
int V_7 ;
if( ( V_3 >= V_23 ) && ( V_3 <= V_24 ) )
return V_3 - V_23 ;
V_22 . V_3 = V_3 ;
if( ! V_16 ) return - 1 ;
V_7 = F_14 ( V_16 , & V_22 ) ;
if( V_7 == - 1 ) return - 1 ;
return V_7 + V_17 ;
}
int F_15 ( int V_5 , int V_25 , int V_26 ,
int (* F_16)( const T_1 * , const T_2 * , int ) ,
char * V_27 , char * V_19 , void * V_28 )
{
int V_7 ;
T_1 * V_29 ;
V_26 &= ~ V_30 ;
V_26 |= V_31 ;
V_7 = F_6 ( V_5 ) ;
if( V_7 == - 1 ) {
if( ! ( V_29 = F_17 ( sizeof( T_1 ) ) ) ) {
F_9 ( V_32 , V_33 ) ;
return 0 ;
}
V_29 -> V_26 = V_30 ;
} else V_29 = F_7 ( V_7 ) ;
if( V_29 -> V_26 & V_31 ) {
F_18 ( V_29 -> V_27 ) ;
F_18 ( V_29 -> V_19 ) ;
}
V_29 -> V_27 = F_19 ( V_27 ) ;
V_29 -> V_19 = F_19 ( V_19 ) ;
if( ! V_29 -> V_27 || ! V_29 -> V_19 ) {
F_9 ( V_32 , V_33 ) ;
return 0 ;
}
V_29 -> V_26 &= V_30 ;
V_29 -> V_26 |= V_26 ;
V_29 -> V_3 = V_5 ;
V_29 -> V_25 = V_25 ;
V_29 -> V_12 = F_16 ;
V_29 -> V_34 = V_28 ;
if( V_7 == - 1 ) {
if( ! V_16 && ! ( V_16 = F_20 ( F_1 ) ) ) {
F_9 ( V_32 , V_33 ) ;
return 0 ;
}
if ( ! F_21 ( V_16 , V_29 ) ) {
F_9 ( V_32 , V_33 ) ;
return 0 ;
}
}
return 1 ;
}
static void F_22 ( T_1 * V_13 )
{
if( ! V_13 ) return;
if ( V_13 -> V_26 & V_30 )
{
if ( V_13 -> V_26 & V_31 ) {
F_18 ( V_13 -> V_27 ) ;
F_18 ( V_13 -> V_19 ) ;
}
F_18 ( V_13 ) ;
}
}
void F_23 ( void )
{
unsigned int V_20 ;
F_24 ( V_16 , F_22 ) ;
for( V_20 = 0 ; V_20 < V_17 ; V_20 ++ ) F_22 ( V_18 + V_20 ) ;
V_16 = NULL ;
}
int F_25 ( T_1 * V_35 )
{
return V_35 -> V_3 ;
}
char * F_26 ( T_1 * V_35 )
{
return V_35 -> V_27 ;
}
char * F_27 ( T_1 * V_35 )
{
return V_35 -> V_19 ;
}
int F_28 ( T_1 * V_35 )
{
return V_35 -> V_25 ;
}
static int F_29 ( const int * V_1 , const int * V_2 )
{
return * V_1 - * V_2 ;
}
int F_30 ( T_3 * V_36 )
{
static const int V_37 [] = {
V_38 ,
V_39 ,
V_40 ,
V_41 ,
V_42 ,
V_43 ,
#ifndef F_31
V_44 ,
V_45 ,
#endif
V_46 ,
V_47 ,
V_48 ,
V_49 ,
V_50
} ;
int V_51 = F_32 ( F_33 ( V_36 ) ) ;
if ( V_51 == V_52 )
return 0 ;
if ( F_34 ( & V_51 , V_37 ,
sizeof( V_37 ) / sizeof( int ) ) )
return 1 ;
return 0 ;
}
static void F_35 ( T_2 * V_4 , T_4 * V_53 )
{
T_5 * V_54 = NULL ;
int V_20 ;
if ( V_53 -> V_55 )
{
if ( V_53 -> V_55 -> V_56 > 0 )
V_53 -> V_57 = V_53 -> V_55 -> V_58 [ 0 ] ;
if ( V_53 -> V_55 -> V_56 > 1 )
V_53 -> V_57 |= ( V_53 -> V_55 -> V_58 [ 1 ] << 8 ) ;
V_53 -> V_57 &= V_59 ;
}
else
V_53 -> V_57 = V_59 ;
if ( ! V_53 -> V_60 || ( V_53 -> V_60 -> type != 1 ) )
return;
for ( V_20 = 0 ; V_20 < F_36 ( V_53 -> V_61 ) ; V_20 ++ )
{
T_6 * V_62 = F_37 ( V_53 -> V_61 , V_20 ) ;
if ( V_62 -> type == V_63 )
{
V_54 = V_62 -> V_64 . V_65 ;
break;
}
}
if ( ! V_54 )
V_54 = F_38 ( V_4 ) ;
F_39 ( V_53 -> V_60 , V_54 ) ;
}
static void F_40 ( T_2 * V_4 )
{
int V_20 ;
V_4 -> V_66 = F_41 ( V_4 , V_67 , NULL , NULL ) ;
for ( V_20 = 0 ; V_20 < F_42 ( V_4 -> V_66 ) ; V_20 ++ )
F_35 ( V_4 , F_43 ( V_4 -> V_66 , V_20 ) ) ;
}
static void F_4 ( T_2 * V_4 )
{
T_7 * V_68 ;
T_8 * V_69 ;
T_9 * V_70 ;
T_9 * V_71 ;
T_10 * V_72 ;
T_3 * V_36 ;
int V_20 ;
if( V_4 -> V_9 & V_10 ) return;
#ifndef F_44
F_45 ( V_4 , F_46 () , V_4 -> V_73 , NULL ) ;
#endif
if( ! F_47 ( F_48 ( V_4 ) , F_38 ( V_4 ) ) )
V_4 -> V_9 |= V_74 ;
if( ! F_49 ( V_4 ) ) V_4 -> V_9 |= V_75 ;
if( ( V_68 = F_41 ( V_4 , V_41 , NULL , NULL ) ) ) {
if( V_68 -> V_6 ) V_4 -> V_9 |= V_76 ;
if( V_68 -> V_77 ) {
if( ( V_68 -> V_77 -> type == V_78 )
|| ! V_68 -> V_6 ) {
V_4 -> V_9 |= V_79 ;
V_4 -> V_80 = 0 ;
} else V_4 -> V_80 = F_50 ( V_68 -> V_77 ) ;
} else V_4 -> V_80 = - 1 ;
F_51 ( V_68 ) ;
V_4 -> V_9 |= V_81 ;
}
if( ( V_69 = F_41 ( V_4 , V_47 , NULL , NULL ) ) ) {
if ( V_4 -> V_9 & V_76
|| F_52 ( V_4 , V_40 , 0 ) >= 0
|| F_52 ( V_4 , V_82 , 0 ) >= 0 ) {
V_4 -> V_9 |= V_79 ;
}
if ( V_69 -> V_83 ) {
V_4 -> V_84 =
F_50 ( V_69 -> V_83 ) ;
} else V_4 -> V_84 = - 1 ;
F_53 ( V_69 ) ;
V_4 -> V_9 |= V_85 ;
}
if( ( V_70 = F_41 ( V_4 , V_39 , NULL , NULL ) ) ) {
if( V_70 -> V_56 > 0 ) {
V_4 -> V_86 = V_70 -> V_58 [ 0 ] ;
if( V_70 -> V_56 > 1 )
V_4 -> V_86 |= V_70 -> V_58 [ 1 ] << 8 ;
} else V_4 -> V_86 = 0 ;
V_4 -> V_9 |= V_87 ;
F_54 ( V_70 ) ;
}
V_4 -> V_88 = 0 ;
if( ( V_72 = F_41 ( V_4 , V_43 , NULL , NULL ) ) ) {
V_4 -> V_9 |= V_89 ;
for( V_20 = 0 ; V_20 < F_55 ( V_72 ) ; V_20 ++ ) {
switch( F_32 ( F_56 ( V_72 , V_20 ) ) ) {
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
}
}
F_57 ( V_72 , V_107 ) ;
}
if( ( V_71 = F_41 ( V_4 , V_38 , NULL , NULL ) ) ) {
if( V_71 -> V_56 > 0 ) V_4 -> V_108 = V_71 -> V_58 [ 0 ] ;
else V_4 -> V_108 = 0 ;
V_4 -> V_9 |= V_109 ;
F_54 ( V_71 ) ;
}
V_4 -> V_110 = F_41 ( V_4 , V_111 , NULL , NULL ) ;
V_4 -> V_112 = F_41 ( V_4 , V_113 , NULL , NULL ) ;
V_4 -> V_114 = F_41 ( V_4 , V_40 , NULL , NULL ) ;
V_4 -> V_115 = F_41 ( V_4 , V_48 , & V_20 , NULL ) ;
if ( ! V_4 -> V_115 && ( V_20 != - 1 ) )
V_4 -> V_9 |= V_79 ;
F_40 ( V_4 ) ;
#ifndef F_31
V_4 -> V_116 = F_41 ( V_4 , V_44 , NULL , NULL ) ;
V_4 -> V_117 = F_41 ( V_4 , V_45 ,
NULL , NULL ) ;
#endif
for ( V_20 = 0 ; V_20 < F_58 ( V_4 ) ; V_20 ++ )
{
V_36 = F_59 ( V_4 , V_20 ) ;
if ( ! F_60 ( V_36 ) )
continue;
if ( F_32 ( F_33 ( V_36 ) )
== V_118 )
V_4 -> V_9 |= V_119 ;
if ( ! F_30 ( V_36 ) )
{
V_4 -> V_9 |= V_120 ;
break;
}
}
V_4 -> V_9 |= V_10 ;
}
static int F_61 ( const T_2 * V_4 )
{
if( F_62 ( V_4 , V_121 ) ) return 0 ;
if( V_4 -> V_9 & V_81 ) {
if( V_4 -> V_9 & V_76 ) return 1 ;
else return 0 ;
} else {
if( ( V_4 -> V_9 & V_122 ) == V_122 ) return 3 ;
else if ( V_4 -> V_9 & V_87 ) return 4 ;
else if ( V_4 -> V_9 & V_109
&& V_4 -> V_108 & V_123 ) return 5 ;
return 0 ;
}
}
int F_63 ( T_2 * V_4 )
{
if( ! ( V_4 -> V_9 & V_10 ) ) {
F_3 ( V_11 ) ;
F_4 ( V_4 ) ;
F_5 ( V_11 ) ;
}
return F_61 ( V_4 ) ;
}
static int F_64 ( const T_2 * V_4 )
{
int V_124 ;
V_124 = F_61 ( V_4 ) ;
if( ! V_124 ) return 0 ;
if( V_124 != 5 || V_4 -> V_108 & V_125 ) return V_124 ;
else return 0 ;
}
static int F_65 ( const T_1 * V_35 , const T_2 * V_4 , int V_6 )
{
if( F_66 ( V_4 , V_93 ) ) return 0 ;
if( V_6 ) return F_64 ( V_4 ) ;
if( F_62 ( V_4 , V_126 ) ) return 0 ;
if( F_67 ( V_4 , V_127 ) ) return 0 ;
return 1 ;
}
static int F_68 ( const T_1 * V_35 , const T_2 * V_4 , int V_6 )
{
if( F_66 ( V_4 , V_91 | V_100 ) ) return 0 ;
if( V_6 ) return F_64 ( V_4 ) ;
if( F_67 ( V_4 , V_128 ) ) return 0 ;
if( F_62 ( V_4 , V_126 | V_129 ) ) return 0 ;
return 1 ;
}
static int F_69 ( const T_1 * V_35 , const T_2 * V_4 , int V_6 )
{
int V_130 ;
V_130 = F_68 ( V_35 , V_4 , V_6 ) ;
if( ! V_130 || V_6 ) return V_130 ;
if( F_62 ( V_4 , V_129 ) ) return 0 ;
return V_130 ;
}
static int F_70 ( const T_2 * V_4 , int V_6 )
{
if( F_66 ( V_4 , V_95 ) ) return 0 ;
if( V_6 ) {
int V_124 ;
V_124 = F_61 ( V_4 ) ;
if( ! V_124 ) return 0 ;
if( V_124 != 5 || V_4 -> V_108 & V_131 ) return V_124 ;
else return 0 ;
}
if( V_4 -> V_9 & V_109 ) {
if( V_4 -> V_108 & V_132 ) return 1 ;
if( V_4 -> V_108 & V_127 ) return 2 ;
return 0 ;
}
return 1 ;
}
static int F_71 ( const T_1 * V_35 , const T_2 * V_4 , int V_6 )
{
int V_130 ;
V_130 = F_70 ( V_4 , V_6 ) ;
if( ! V_130 || V_6 ) return V_130 ;
if( F_62 ( V_4 , V_126 | V_133 ) ) return 0 ;
return V_130 ;
}
static int F_72 ( const T_1 * V_35 , const T_2 * V_4 , int V_6 )
{
int V_130 ;
V_130 = F_70 ( V_4 , V_6 ) ;
if( ! V_130 || V_6 ) return V_130 ;
if( F_62 ( V_4 , V_129 ) ) return 0 ;
return V_130 ;
}
static int F_73 ( const T_1 * V_35 , const T_2 * V_4 , int V_6 )
{
if( V_6 ) {
int V_124 ;
if( ( V_124 = F_61 ( V_4 ) ) != 2 ) return V_124 ;
else return 0 ;
}
if( F_62 ( V_4 , V_134 ) ) return 0 ;
return 1 ;
}
static int F_74 ( const T_1 * V_35 , const T_2 * V_4 , int V_6 )
{
if( V_6 ) return F_61 ( V_4 ) ;
return 1 ;
}
static int F_75 ( const T_1 * V_35 , const T_2 * V_4 ,
int V_6 )
{
int V_135 ;
if ( V_6 ) return F_61 ( V_4 ) ;
if ( ( V_4 -> V_9 & V_87 )
&& ( ( V_4 -> V_86 & ~ ( V_133 | V_126 ) ) ||
! ( V_4 -> V_86 & ( V_133 | V_126 ) ) ) )
return 0 ;
if ( ! ( V_4 -> V_9 & V_89 ) || V_4 -> V_88 != V_104 )
return 0 ;
V_135 = F_52 ( ( T_2 * ) V_4 , V_43 , 0 ) ;
if ( V_135 >= 0 )
{
T_3 * V_136 = F_59 ( ( T_2 * ) V_4 , V_135 ) ;
if ( ! F_60 ( V_136 ) )
return 0 ;
}
return 1 ;
}
static int F_76 ( const T_1 * V_35 , const T_2 * V_4 , int V_6 )
{
return 1 ;
}
int F_77 ( T_2 * V_137 , T_2 * V_138 )
{
if( F_47 ( F_48 ( V_137 ) ,
F_38 ( V_138 ) ) )
return V_139 ;
F_4 ( V_137 ) ;
F_4 ( V_138 ) ;
if( V_138 -> V_112 )
{
int V_130 = F_78 ( V_137 , V_138 -> V_112 ) ;
if ( V_130 != V_140 )
return V_130 ;
}
if( V_138 -> V_9 & V_85 )
{
if( F_62 ( V_137 , V_126 ) )
return V_141 ;
}
else if( F_62 ( V_137 , V_121 ) )
return V_142 ;
return V_140 ;
}
int F_78 ( T_2 * V_137 , T_11 * V_112 )
{
if( ! V_112 )
return V_140 ;
if( V_112 -> V_143 && V_137 -> V_110 &&
F_79 ( V_112 -> V_143 , V_137 -> V_110 ) )
return V_144 ;
if( V_112 -> V_145 &&
F_80 ( F_81 ( V_137 ) , V_112 -> V_145 ) )
return V_146 ;
if( V_112 -> V_137 )
{
T_12 * V_147 ;
T_6 * V_62 ;
T_5 * V_148 = NULL ;
int V_20 ;
V_147 = V_112 -> V_137 ;
for( V_20 = 0 ; V_20 < F_36 ( V_147 ) ; V_20 ++ )
{
V_62 = F_37 ( V_147 , V_20 ) ;
if( V_62 -> type == V_63 )
{
V_148 = V_62 -> V_64 . V_149 ;
break;
}
}
if( V_148 && F_47 ( V_148 , F_38 ( V_137 ) ) )
return V_146 ;
}
return V_140 ;
}
