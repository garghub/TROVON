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
if( V_7 < V_17 ) return V_18 + V_7 ;
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
int V_20 ;
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
V_42
} ;
int V_43 ;
V_43 = F_31 ( F_32 ( V_36 ) ) ;
if ( V_43 == V_44 )
return 0 ;
if ( F_33 ( ( char * ) & V_43 , ( char * ) V_37 ,
sizeof( V_37 ) / sizeof( int ) , sizeof( int ) ,
( int ( * ) ( const void * , const void * ) ) F_29 ) )
return 1 ;
return 0 ;
}
static void F_4 ( T_2 * V_4 )
{
T_4 * V_45 ;
T_5 * V_46 ;
T_5 * V_47 ;
T_6 * V_48 ;
T_3 * V_36 ;
int V_20 ;
if( V_4 -> V_9 & V_10 ) return;
#ifndef F_34
F_35 ( V_4 , F_36 () , V_4 -> V_49 , NULL ) ;
#endif
if( ! F_37 ( F_38 ( V_4 ) , F_39 ( V_4 ) ) )
V_4 -> V_9 |= V_50 ;
if( ! F_40 ( V_4 ) ) V_4 -> V_9 |= V_51 ;
if( ( V_45 = F_41 ( V_4 , V_41 , NULL , NULL ) ) ) {
if( V_45 -> V_6 ) V_4 -> V_9 |= V_52 ;
if( V_45 -> V_53 ) {
if( ( V_45 -> V_53 -> type == V_54 )
|| ! V_45 -> V_6 ) {
V_4 -> V_9 |= V_55 ;
V_4 -> V_56 = 0 ;
} else V_4 -> V_56 = F_42 ( V_45 -> V_53 ) ;
} else V_4 -> V_56 = - 1 ;
F_43 ( V_45 ) ;
V_4 -> V_9 |= V_57 ;
}
if( ( V_46 = F_41 ( V_4 , V_39 , NULL , NULL ) ) ) {
if( V_46 -> V_58 > 0 ) {
V_4 -> V_59 = V_46 -> V_60 [ 0 ] ;
if( V_46 -> V_58 > 1 )
V_4 -> V_59 |= V_46 -> V_60 [ 1 ] << 8 ;
} else V_4 -> V_59 = 0 ;
V_4 -> V_9 |= V_61 ;
F_44 ( V_46 ) ;
}
V_4 -> V_62 = 0 ;
if( ( V_48 = F_41 ( V_4 , V_42 , NULL , NULL ) ) ) {
V_4 -> V_9 |= V_63 ;
for( V_20 = 0 ; V_20 < F_45 ( V_48 ) ; V_20 ++ ) {
switch( F_31 ( F_46 ( V_48 , V_20 ) ) ) {
case V_64 :
V_4 -> V_62 |= V_65 ;
break;
case V_66 :
V_4 -> V_62 |= V_67 ;
break;
case V_68 :
V_4 -> V_62 |= V_69 ;
break;
case V_70 :
V_4 -> V_62 |= V_71 ;
break;
case V_72 :
case V_73 :
V_4 -> V_62 |= V_74 ;
break;
case V_75 :
V_4 -> V_62 |= V_76 ;
break;
case V_77 :
V_4 -> V_62 |= V_78 ;
break;
}
}
F_47 ( V_48 , V_79 ) ;
}
if( ( V_47 = F_41 ( V_4 , V_38 , NULL , NULL ) ) ) {
if( V_47 -> V_58 > 0 ) V_4 -> V_80 = V_47 -> V_60 [ 0 ] ;
else V_4 -> V_80 = 0 ;
V_4 -> V_9 |= V_81 ;
F_44 ( V_47 ) ;
}
V_4 -> V_82 = F_41 ( V_4 , V_83 , NULL , NULL ) ;
V_4 -> V_84 = F_41 ( V_4 , V_85 , NULL , NULL ) ;
for ( V_20 = 0 ; V_20 < F_48 ( V_4 ) ; V_20 ++ )
{
V_36 = F_49 ( V_4 , V_20 ) ;
if ( ! F_50 ( V_36 ) )
continue;
if ( ! F_30 ( V_36 ) )
{
V_4 -> V_9 |= V_86 ;
break;
}
}
V_4 -> V_9 |= V_10 ;
}
static int F_51 ( const T_2 * V_4 )
{
if( F_52 ( V_4 , V_87 ) ) return 0 ;
if( V_4 -> V_9 & V_57 ) {
if( V_4 -> V_9 & V_52 ) return 1 ;
else return 0 ;
} else {
if( ( V_4 -> V_9 & V_88 ) == V_88 ) return 3 ;
else if ( V_4 -> V_9 & V_61 ) return 3 ;
else return 2 ;
}
}
static int F_53 ( const T_2 * V_4 )
{
int V_89 ;
V_89 = F_51 ( V_4 ) ;
if( ! V_89 ) return 0 ;
if( V_4 -> V_9 & V_81 ) {
if( V_4 -> V_80 & V_90 ) return V_89 ;
return 0 ;
}
if( V_89 != 2 ) return V_89 ;
else return 0 ;
}
static int F_54 ( const T_1 * V_35 , const T_2 * V_4 , int V_6 )
{
if( F_55 ( V_4 , V_67 ) ) return 0 ;
if( V_6 ) return F_53 ( V_4 ) ;
if( F_52 ( V_4 , V_91 ) ) return 0 ;
if( F_56 ( V_4 , V_92 ) ) return 0 ;
return 1 ;
}
static int F_57 ( const T_1 * V_35 , const T_2 * V_4 , int V_6 )
{
if( F_55 ( V_4 , V_65 | V_74 ) ) return 0 ;
if( V_6 ) return F_53 ( V_4 ) ;
if( F_56 ( V_4 , V_93 ) ) return 0 ;
if( F_52 ( V_4 , V_91 | V_94 ) ) return 0 ;
return 1 ;
}
static int F_58 ( const T_1 * V_35 , const T_2 * V_4 , int V_6 )
{
int V_95 ;
V_95 = F_57 ( V_35 , V_4 , V_6 ) ;
if( ! V_95 || V_6 ) return V_95 ;
if( F_52 ( V_4 , V_94 ) ) return 0 ;
return V_95 ;
}
static int F_59 ( const T_2 * V_4 , int V_6 )
{
if( F_55 ( V_4 , V_69 ) ) return 0 ;
if( V_6 ) {
int V_89 ;
V_89 = F_51 ( V_4 ) ;
if( ! V_89 ) return 0 ;
if( V_4 -> V_9 & V_81 ) {
if( V_4 -> V_80 & V_96 ) return V_89 ;
return 0 ;
}
if( V_89 != 2 ) return V_89 ;
else return 0 ;
}
if( V_4 -> V_9 & V_81 ) {
if( V_4 -> V_80 & V_97 ) return 1 ;
if( V_4 -> V_80 & V_92 ) return 2 ;
return 0 ;
}
return 1 ;
}
static int F_60 ( const T_1 * V_35 , const T_2 * V_4 , int V_6 )
{
int V_95 ;
V_95 = F_59 ( V_4 , V_6 ) ;
if( ! V_95 || V_6 ) return V_95 ;
if( F_52 ( V_4 , V_91 | V_98 ) ) return 0 ;
return V_95 ;
}
static int F_61 ( const T_1 * V_35 , const T_2 * V_4 , int V_6 )
{
int V_95 ;
V_95 = F_59 ( V_4 , V_6 ) ;
if( ! V_95 || V_6 ) return V_95 ;
if( F_52 ( V_4 , V_94 ) ) return 0 ;
return V_95 ;
}
static int F_62 ( const T_1 * V_35 , const T_2 * V_4 , int V_6 )
{
if( V_6 ) {
int V_89 ;
if( ( V_89 = F_51 ( V_4 ) ) != 2 ) return V_89 ;
else return 0 ;
}
if( F_52 ( V_4 , V_99 ) ) return 0 ;
return 1 ;
}
static int F_63 ( const T_1 * V_35 , const T_2 * V_4 , int V_6 )
{
if( V_6 ) {
int V_89 ;
V_89 = F_51 ( V_4 ) ;
if( V_89 != 2 ) return V_89 ;
if( V_4 -> V_9 & V_81 ) {
if( V_4 -> V_80 & V_100 ) return V_89 ;
return 0 ;
}
return 0 ;
}
return 1 ;
}
static int F_64 ( const T_1 * V_35 , const T_2 * V_4 , int V_6 )
{
return 1 ;
}
int F_65 ( T_2 * V_101 , T_2 * V_102 )
{
if( F_37 ( F_38 ( V_101 ) ,
F_39 ( V_102 ) ) )
return V_103 ;
F_4 ( V_101 ) ;
F_4 ( V_102 ) ;
if( V_102 -> V_84 ) {
if( V_102 -> V_84 -> V_104 && V_101 -> V_82 &&
F_66 ( V_102 -> V_84 -> V_104 , V_101 -> V_82 ) )
return V_105 ;
if( V_102 -> V_84 -> V_106 &&
F_67 ( F_68 ( V_101 ) ,
V_102 -> V_84 -> V_106 ) )
return V_107 ;
if( V_102 -> V_84 -> V_101 ) {
T_7 * V_108 ;
T_8 * V_109 ;
T_9 * V_110 = NULL ;
int V_20 ;
V_108 = V_102 -> V_84 -> V_101 ;
for( V_20 = 0 ; V_20 < F_69 ( V_108 ) ; V_20 ++ ) {
V_109 = F_70 ( V_108 , V_20 ) ;
if( V_109 -> type == V_111 ) {
V_110 = V_109 -> V_112 . V_113 ;
break;
}
}
if( V_110 && F_37 ( V_110 , F_39 ( V_101 ) ) )
return V_107 ;
}
}
if( F_52 ( V_101 , V_87 ) ) return V_114 ;
return V_115 ;
}
