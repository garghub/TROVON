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
static int F_29 ( int * V_1 , int * V_2 )
{
return * V_1 - * V_2 ;
}
int F_30 ( T_3 * V_36 )
{
static int V_37 [] = {
V_38 ,
V_39 ,
V_40 ,
V_41 ,
V_42 ,
V_43
} ;
int V_44 ;
V_44 = F_31 ( F_32 ( V_36 ) ) ;
if ( V_44 == V_45 )
return 0 ;
if ( F_33 ( ( char * ) & V_44 , ( char * ) V_37 ,
sizeof( V_37 ) / sizeof( int ) , sizeof( int ) ,
( int ( * ) ( const void * , const void * ) ) F_29 ) )
return 1 ;
return 0 ;
}
static void F_4 ( T_2 * V_4 )
{
T_4 * V_46 ;
T_5 * V_47 ;
T_6 * V_48 ;
T_6 * V_49 ;
T_7 * V_50 ;
T_3 * V_36 ;
int V_20 ;
if( V_4 -> V_9 & V_10 ) return;
#ifndef F_34
F_35 ( V_4 , F_36 () , V_4 -> V_51 , NULL ) ;
#endif
if( ! F_37 ( F_38 ( V_4 ) , F_39 ( V_4 ) ) )
V_4 -> V_9 |= V_52 ;
if( ! F_40 ( V_4 ) ) V_4 -> V_9 |= V_53 ;
if( ( V_46 = F_41 ( V_4 , V_41 , NULL , NULL ) ) ) {
if( V_46 -> V_6 ) V_4 -> V_9 |= V_54 ;
if( V_46 -> V_55 ) {
if( ( V_46 -> V_55 -> type == V_56 )
|| ! V_46 -> V_6 ) {
V_4 -> V_9 |= V_57 ;
V_4 -> V_58 = 0 ;
} else V_4 -> V_58 = F_42 ( V_46 -> V_55 ) ;
} else V_4 -> V_58 = - 1 ;
F_43 ( V_46 ) ;
V_4 -> V_9 |= V_59 ;
}
if( ( V_47 = F_41 ( V_4 , V_43 , NULL , NULL ) ) ) {
if ( V_4 -> V_9 & V_54
|| F_44 ( V_4 , V_40 , 0 ) >= 0
|| F_44 ( V_4 , V_60 , 0 ) >= 0 ) {
V_4 -> V_9 |= V_57 ;
}
if ( V_47 -> V_61 ) {
V_4 -> V_62 =
F_42 ( V_47 -> V_61 ) ;
} else V_4 -> V_62 = - 1 ;
F_45 ( V_47 ) ;
V_4 -> V_9 |= V_63 ;
}
if( ( V_48 = F_41 ( V_4 , V_39 , NULL , NULL ) ) ) {
if( V_48 -> V_64 > 0 ) {
V_4 -> V_65 = V_48 -> V_66 [ 0 ] ;
if( V_48 -> V_64 > 1 )
V_4 -> V_65 |= V_48 -> V_66 [ 1 ] << 8 ;
} else V_4 -> V_65 = 0 ;
V_4 -> V_9 |= V_67 ;
F_46 ( V_48 ) ;
}
V_4 -> V_68 = 0 ;
if( ( V_50 = F_41 ( V_4 , V_42 , NULL , NULL ) ) ) {
V_4 -> V_9 |= V_69 ;
for( V_20 = 0 ; V_20 < F_47 ( V_50 ) ; V_20 ++ ) {
switch( F_31 ( F_48 ( V_50 , V_20 ) ) ) {
case V_70 :
V_4 -> V_68 |= V_71 ;
break;
case V_72 :
V_4 -> V_68 |= V_73 ;
break;
case V_74 :
V_4 -> V_68 |= V_75 ;
break;
case V_76 :
V_4 -> V_68 |= V_77 ;
break;
case V_78 :
case V_79 :
V_4 -> V_68 |= V_80 ;
break;
case V_81 :
V_4 -> V_68 |= V_82 ;
break;
case V_83 :
V_4 -> V_68 |= V_84 ;
break;
case V_85 :
V_4 -> V_68 |= V_86 ;
break;
}
}
F_49 ( V_50 , V_87 ) ;
}
if( ( V_49 = F_41 ( V_4 , V_38 , NULL , NULL ) ) ) {
if( V_49 -> V_64 > 0 ) V_4 -> V_88 = V_49 -> V_66 [ 0 ] ;
else V_4 -> V_88 = 0 ;
V_4 -> V_9 |= V_89 ;
F_46 ( V_49 ) ;
}
V_4 -> V_90 = F_41 ( V_4 , V_91 , NULL , NULL ) ;
V_4 -> V_92 = F_41 ( V_4 , V_93 , NULL , NULL ) ;
for ( V_20 = 0 ; V_20 < F_50 ( V_4 ) ; V_20 ++ )
{
V_36 = F_51 ( V_4 , V_20 ) ;
if ( ! F_52 ( V_36 ) )
continue;
if ( ! F_30 ( V_36 ) )
{
V_4 -> V_9 |= V_94 ;
break;
}
}
V_4 -> V_9 |= V_10 ;
}
static int F_53 ( const T_2 * V_4 )
{
if( F_54 ( V_4 , V_95 ) ) return 0 ;
if( V_4 -> V_9 & V_59 ) {
if( V_4 -> V_9 & V_54 ) return 1 ;
else return 0 ;
} else {
if( ( V_4 -> V_9 & V_96 ) == V_96 ) return 3 ;
else if ( V_4 -> V_9 & V_67 ) return 4 ;
else if ( V_4 -> V_9 & V_89
&& V_4 -> V_88 & V_97 ) return 5 ;
return 0 ;
}
}
int F_55 ( T_2 * V_4 )
{
if( ! ( V_4 -> V_9 & V_10 ) ) {
F_3 ( V_11 ) ;
F_4 ( V_4 ) ;
F_5 ( V_11 ) ;
}
return F_53 ( V_4 ) ;
}
static int F_56 ( const T_2 * V_4 )
{
int V_98 ;
V_98 = F_53 ( V_4 ) ;
if( ! V_98 ) return 0 ;
if( V_98 != 5 || V_4 -> V_88 & V_99 ) return V_98 ;
else return 0 ;
}
static int F_57 ( const T_1 * V_35 , const T_2 * V_4 , int V_6 )
{
if( F_58 ( V_4 , V_73 ) ) return 0 ;
if( V_6 ) return F_56 ( V_4 ) ;
if( F_54 ( V_4 , V_100 ) ) return 0 ;
if( F_59 ( V_4 , V_101 ) ) return 0 ;
return 1 ;
}
static int F_60 ( const T_1 * V_35 , const T_2 * V_4 , int V_6 )
{
if( F_58 ( V_4 , V_71 | V_80 ) ) return 0 ;
if( V_6 ) return F_56 ( V_4 ) ;
if( F_59 ( V_4 , V_102 ) ) return 0 ;
if( F_54 ( V_4 , V_100 | V_103 ) ) return 0 ;
return 1 ;
}
static int F_61 ( const T_1 * V_35 , const T_2 * V_4 , int V_6 )
{
int V_104 ;
V_104 = F_60 ( V_35 , V_4 , V_6 ) ;
if( ! V_104 || V_6 ) return V_104 ;
if( F_54 ( V_4 , V_103 ) ) return 0 ;
return V_104 ;
}
static int F_62 ( const T_2 * V_4 , int V_6 )
{
if( F_58 ( V_4 , V_75 ) ) return 0 ;
if( V_6 ) {
int V_98 ;
V_98 = F_53 ( V_4 ) ;
if( ! V_98 ) return 0 ;
if( V_98 != 5 || V_4 -> V_88 & V_105 ) return V_98 ;
else return 0 ;
}
if( V_4 -> V_9 & V_89 ) {
if( V_4 -> V_88 & V_106 ) return 1 ;
if( V_4 -> V_88 & V_101 ) return 2 ;
return 0 ;
}
return 1 ;
}
static int F_63 ( const T_1 * V_35 , const T_2 * V_4 , int V_6 )
{
int V_104 ;
V_104 = F_62 ( V_4 , V_6 ) ;
if( ! V_104 || V_6 ) return V_104 ;
if( F_54 ( V_4 , V_100 | V_107 ) ) return 0 ;
return V_104 ;
}
static int F_64 ( const T_1 * V_35 , const T_2 * V_4 , int V_6 )
{
int V_104 ;
V_104 = F_62 ( V_4 , V_6 ) ;
if( ! V_104 || V_6 ) return V_104 ;
if( F_54 ( V_4 , V_103 ) ) return 0 ;
return V_104 ;
}
static int F_65 ( const T_1 * V_35 , const T_2 * V_4 , int V_6 )
{
if( V_6 ) {
int V_98 ;
if( ( V_98 = F_53 ( V_4 ) ) != 2 ) return V_98 ;
else return 0 ;
}
if( F_54 ( V_4 , V_108 ) ) return 0 ;
return 1 ;
}
static int F_66 ( const T_1 * V_35 , const T_2 * V_4 , int V_6 )
{
if( V_6 ) return F_53 ( V_4 ) ;
return 1 ;
}
static int F_67 ( const T_1 * V_35 , const T_2 * V_4 , int V_6 )
{
return 1 ;
}
int F_68 ( T_2 * V_109 , T_2 * V_110 )
{
if( F_37 ( F_38 ( V_109 ) ,
F_39 ( V_110 ) ) )
return V_111 ;
F_4 ( V_109 ) ;
F_4 ( V_110 ) ;
if( V_110 -> V_92 ) {
if( V_110 -> V_92 -> V_112 && V_109 -> V_90 &&
F_69 ( V_110 -> V_92 -> V_112 , V_109 -> V_90 ) )
return V_113 ;
if( V_110 -> V_92 -> V_114 &&
F_70 ( F_71 ( V_109 ) ,
V_110 -> V_92 -> V_114 ) )
return V_115 ;
if( V_110 -> V_92 -> V_109 ) {
T_8 * V_116 ;
T_9 * V_117 ;
T_10 * V_118 = NULL ;
int V_20 ;
V_116 = V_110 -> V_92 -> V_109 ;
for( V_20 = 0 ; V_20 < F_72 ( V_116 ) ; V_20 ++ ) {
V_117 = F_73 ( V_116 , V_20 ) ;
if( V_117 -> type == V_119 ) {
V_118 = V_117 -> V_120 . V_121 ;
break;
}
}
if( V_118 && F_37 ( V_118 , F_39 ( V_109 ) ) )
return V_115 ;
}
}
if( V_110 -> V_9 & V_63 )
{
if( F_54 ( V_109 , V_100 ) )
return V_122 ;
}
else if( F_54 ( V_109 , V_95 ) )
return V_123 ;
return V_124 ;
}
