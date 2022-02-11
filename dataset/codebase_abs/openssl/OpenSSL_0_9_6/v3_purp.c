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
int F_8 ( void )
{
if( ! V_13 ) return V_14 ;
return F_9 ( V_13 ) + V_14 ;
}
T_1 * F_7 ( int V_7 )
{
if( V_7 < 0 ) return NULL ;
if( V_7 < V_14 ) return V_15 + V_7 ;
return F_10 ( V_13 , V_7 - V_14 ) ;
}
int F_11 ( char * V_16 )
{
int V_17 ;
T_1 * V_18 ;
for( V_17 = 0 ; V_17 < F_8 () ; V_17 ++ ) {
V_18 = F_7 ( V_17 ) ;
if( ! strcmp ( V_18 -> V_16 , V_16 ) ) return V_17 ;
}
return - 1 ;
}
int F_6 ( int V_3 )
{
T_1 V_19 ;
int V_7 ;
if( ( V_3 >= V_20 ) && ( V_3 <= V_21 ) )
return V_3 - V_20 ;
V_19 . V_3 = V_3 ;
if( ! V_13 ) return - 1 ;
V_7 = F_12 ( V_13 , & V_19 ) ;
if( V_7 == - 1 ) return - 1 ;
return V_7 + V_14 ;
}
int F_13 ( int V_5 , int V_22 , int V_23 ,
int (* F_14)( const T_1 * , const T_2 * , int ) ,
char * V_24 , char * V_16 , void * V_25 )
{
int V_7 ;
T_1 * V_26 ;
V_23 &= ~ V_27 ;
V_23 |= V_28 ;
V_7 = F_6 ( V_5 ) ;
if( V_7 == - 1 ) {
if( ! ( V_26 = F_15 ( sizeof( T_1 ) ) ) ) {
F_16 ( V_29 , V_30 ) ;
return 0 ;
}
V_26 -> V_23 = V_27 ;
} else V_26 = F_7 ( V_7 ) ;
if( V_26 -> V_23 & V_28 ) {
F_17 ( V_26 -> V_24 ) ;
F_17 ( V_26 -> V_16 ) ;
}
V_26 -> V_24 = F_18 ( V_24 ) ;
V_26 -> V_16 = F_18 ( V_16 ) ;
if( ! V_26 -> V_24 || ! V_26 -> V_16 ) {
F_16 ( V_29 , V_30 ) ;
return 0 ;
}
V_26 -> V_23 &= V_27 ;
V_26 -> V_23 |= V_23 ;
V_26 -> V_3 = V_5 ;
V_26 -> V_22 = V_22 ;
V_26 -> V_12 = F_14 ;
V_26 -> V_31 = V_25 ;
if( V_7 == - 1 ) {
if( ! V_13 && ! ( V_13 = F_19 ( F_1 ) ) ) {
F_16 ( V_29 , V_30 ) ;
return 0 ;
}
if ( ! F_20 ( V_13 , V_26 ) ) {
F_16 ( V_29 , V_30 ) ;
return 0 ;
}
}
return 1 ;
}
static void F_21 ( T_1 * V_32 )
{
if( ! V_32 ) return;
if ( V_32 -> V_23 & V_27 )
{
if ( V_32 -> V_23 & V_28 ) {
F_17 ( V_32 -> V_24 ) ;
F_17 ( V_32 -> V_16 ) ;
}
F_17 ( V_32 ) ;
}
}
void F_22 ( void )
{
int V_17 ;
F_23 ( V_13 , F_21 ) ;
for( V_17 = 0 ; V_17 < V_14 ; V_17 ++ ) F_21 ( V_15 + V_17 ) ;
V_13 = NULL ;
}
int F_24 ( T_1 * V_33 )
{
return V_33 -> V_3 ;
}
char * F_25 ( T_1 * V_33 )
{
return V_33 -> V_24 ;
}
char * F_26 ( T_1 * V_33 )
{
return V_33 -> V_16 ;
}
int F_27 ( T_1 * V_33 )
{
return V_33 -> V_22 ;
}
static void F_4 ( T_2 * V_4 )
{
T_3 * V_34 ;
T_4 * V_35 ;
T_4 * V_36 ;
F_28 ( V_37 ) * V_38 ;
int V_17 ;
if( V_4 -> V_9 & V_10 ) return;
#ifndef F_29
F_30 ( V_4 , F_31 () , V_4 -> V_39 , NULL ) ;
#endif
if( ! F_32 ( F_33 ( V_4 ) , F_34 ( V_4 ) ) )
V_4 -> V_9 |= V_40 ;
if( ! F_35 ( V_4 ) ) V_4 -> V_9 |= V_41 ;
if( ( V_34 = F_36 ( V_4 , V_42 , NULL , NULL ) ) ) {
if( V_34 -> V_6 ) V_4 -> V_9 |= V_43 ;
if( V_34 -> V_44 ) {
if( ( V_34 -> V_44 -> type == V_45 )
|| ! V_34 -> V_6 ) {
V_4 -> V_9 |= V_46 ;
V_4 -> V_47 = 0 ;
} else V_4 -> V_47 = F_37 ( V_34 -> V_44 ) ;
} else V_4 -> V_47 = - 1 ;
F_38 ( V_34 ) ;
V_4 -> V_9 |= V_48 ;
}
if( ( V_35 = F_36 ( V_4 , V_49 , NULL , NULL ) ) ) {
if( V_35 -> V_50 > 0 ) {
V_4 -> V_51 = V_35 -> V_52 [ 0 ] ;
if( V_35 -> V_50 > 1 )
V_4 -> V_51 |= V_35 -> V_52 [ 1 ] << 8 ;
} else V_4 -> V_51 = 0 ;
V_4 -> V_9 |= V_53 ;
F_39 ( V_35 ) ;
}
V_4 -> V_54 = 0 ;
if( ( V_38 = F_36 ( V_4 , V_55 , NULL , NULL ) ) ) {
V_4 -> V_9 |= V_56 ;
for( V_17 = 0 ; V_17 < F_40 ( V_38 ) ; V_17 ++ ) {
switch( F_41 ( F_42 ( V_38 , V_17 ) ) ) {
case V_57 :
V_4 -> V_54 |= V_58 ;
break;
case V_59 :
V_4 -> V_54 |= V_60 ;
break;
case V_61 :
V_4 -> V_54 |= V_62 ;
break;
case V_63 :
V_4 -> V_54 |= V_64 ;
break;
case V_65 :
case V_66 :
V_4 -> V_54 |= V_67 ;
}
}
F_43 ( V_38 , V_68 ) ;
}
if( ( V_36 = F_36 ( V_4 , V_69 , NULL , NULL ) ) ) {
if( V_36 -> V_50 > 0 ) V_4 -> V_70 = V_36 -> V_52 [ 0 ] ;
else V_4 -> V_70 = 0 ;
V_4 -> V_9 |= V_71 ;
F_39 ( V_36 ) ;
}
V_4 -> V_72 = F_36 ( V_4 , V_73 , NULL , NULL ) ;
V_4 -> V_74 = F_36 ( V_4 , V_75 , NULL , NULL ) ;
V_4 -> V_9 |= V_10 ;
}
static int F_44 ( const T_2 * V_4 )
{
if( F_45 ( V_4 , V_76 ) ) return 0 ;
if( V_4 -> V_9 & V_48 ) {
if( V_4 -> V_9 & V_43 ) return 1 ;
else return 0 ;
} else {
if( ( V_4 -> V_9 & V_77 ) == V_77 ) return 3 ;
else return 2 ;
}
}
static int F_46 ( const T_2 * V_4 )
{
int V_78 ;
V_78 = F_44 ( V_4 ) ;
if( ! V_78 ) return 0 ;
if( V_4 -> V_9 & V_71 ) {
if( V_4 -> V_70 & V_79 ) return V_78 ;
return 0 ;
}
if( V_78 != 2 ) return V_78 ;
else return 0 ;
}
static int F_47 ( const T_1 * V_33 , const T_2 * V_4 , int V_6 )
{
if( F_48 ( V_4 , V_60 ) ) return 0 ;
if( V_6 ) return F_46 ( V_4 ) ;
if( F_45 ( V_4 , V_80 ) ) return 0 ;
if( F_49 ( V_4 , V_81 ) ) return 0 ;
return 1 ;
}
static int F_50 ( const T_1 * V_33 , const T_2 * V_4 , int V_6 )
{
if( F_48 ( V_4 , V_58 | V_67 ) ) return 0 ;
if( V_6 ) return F_46 ( V_4 ) ;
if( F_49 ( V_4 , V_82 ) ) return 0 ;
if( F_45 ( V_4 , V_80 | V_83 ) ) return 0 ;
return 1 ;
}
static int F_51 ( const T_1 * V_33 , const T_2 * V_4 , int V_6 )
{
int V_84 ;
V_84 = F_50 ( V_33 , V_4 , V_6 ) ;
if( ! V_84 || V_6 ) return V_84 ;
if( F_45 ( V_4 , V_83 ) ) return 0 ;
return V_84 ;
}
static int F_52 ( const T_2 * V_4 , int V_6 )
{
if( F_48 ( V_4 , V_62 ) ) return 0 ;
if( V_6 ) {
int V_78 ;
V_78 = F_44 ( V_4 ) ;
if( ! V_78 ) return 0 ;
if( V_4 -> V_9 & V_71 ) {
if( V_4 -> V_70 & V_85 ) return V_78 ;
return 0 ;
}
if( V_78 != 2 ) return V_78 ;
else return 0 ;
}
if( V_4 -> V_9 & V_71 ) {
if( V_4 -> V_70 & V_86 ) return 1 ;
if( V_4 -> V_70 & V_81 ) return 2 ;
return 0 ;
}
return 1 ;
}
static int F_53 ( const T_1 * V_33 , const T_2 * V_4 , int V_6 )
{
int V_84 ;
V_84 = F_52 ( V_4 , V_6 ) ;
if( ! V_84 || V_6 ) return V_84 ;
if( F_45 ( V_4 , V_80 ) ) return 0 ;
return V_84 ;
}
static int F_54 ( const T_1 * V_33 , const T_2 * V_4 , int V_6 )
{
int V_84 ;
V_84 = F_52 ( V_4 , V_6 ) ;
if( ! V_84 || V_6 ) return V_84 ;
if( F_45 ( V_4 , V_83 ) ) return 0 ;
return V_84 ;
}
static int F_55 ( const T_1 * V_33 , const T_2 * V_4 , int V_6 )
{
if( V_6 ) {
int V_78 ;
if( ( V_78 = F_44 ( V_4 ) ) != 2 ) return V_78 ;
else return 0 ;
}
if( F_45 ( V_4 , V_87 ) ) return 0 ;
return 1 ;
}
static int F_56 ( const T_1 * V_33 , const T_2 * V_4 , int V_6 )
{
return 1 ;
}
int F_57 ( T_2 * V_88 , T_2 * V_89 )
{
if( F_32 ( F_33 ( V_88 ) ,
F_34 ( V_89 ) ) )
return V_90 ;
F_4 ( V_88 ) ;
F_4 ( V_89 ) ;
if( V_89 -> V_74 ) {
if( V_89 -> V_74 -> V_91 && V_88 -> V_72 &&
F_58 ( V_89 -> V_74 -> V_91 , V_88 -> V_72 ) )
return V_92 ;
if( V_89 -> V_74 -> V_93 &&
F_59 ( F_60 ( V_88 ) ,
V_89 -> V_74 -> V_93 ) )
return V_94 ;
if( V_89 -> V_74 -> V_88 ) {
F_28 ( V_95 ) * V_96 ;
V_95 * V_97 ;
T_5 * V_98 = NULL ;
int V_17 ;
V_96 = V_89 -> V_74 -> V_88 ;
for( V_17 = 0 ; V_17 < F_61 ( V_96 ) ; V_17 ++ ) {
V_97 = F_62 ( V_96 , V_17 ) ;
if( V_97 -> type == V_99 ) {
V_98 = V_97 -> V_100 . V_101 ;
break;
}
}
if( V_98 && F_32 ( V_98 , F_34 ( V_88 ) ) )
return V_94 ;
}
}
if( F_45 ( V_88 , V_76 ) ) return V_102 ;
return V_103 ;
}
