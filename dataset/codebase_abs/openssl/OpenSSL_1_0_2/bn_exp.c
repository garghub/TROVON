int F_1 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 , T_2 * V_4 )
{
int V_5 , V_6 , V_7 = 0 ;
T_1 * V_8 , * V_9 ;
if ( F_2 ( V_3 , V_10 ) != 0 ) {
F_3 ( V_11 , V_12 ) ;
return - 1 ;
}
F_4 ( V_4 ) ;
if ( ( V_1 == V_2 ) || ( V_1 == V_3 ) )
V_9 = F_5 ( V_4 ) ;
else
V_9 = V_1 ;
V_8 = F_5 ( V_4 ) ;
if ( V_9 == NULL || V_8 == NULL )
goto V_13;
if ( F_6 ( V_8 , V_2 ) == NULL )
goto V_13;
V_6 = F_7 ( V_3 ) ;
if ( F_8 ( V_3 ) ) {
if ( F_6 ( V_9 , V_2 ) == NULL )
goto V_13;
} else {
if ( ! F_9 ( V_9 ) )
goto V_13;
}
for ( V_5 = 1 ; V_5 < V_6 ; V_5 ++ ) {
if ( ! F_10 ( V_8 , V_8 , V_4 ) )
goto V_13;
if ( F_11 ( V_3 , V_5 ) ) {
if ( ! F_12 ( V_9 , V_9 , V_8 , V_4 ) )
goto V_13;
}
}
V_7 = 1 ;
V_13:
if ( V_1 != V_9 )
F_6 ( V_1 , V_9 ) ;
F_13 ( V_4 ) ;
F_14 ( V_1 ) ;
return ( V_7 ) ;
}
int F_15 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 , const T_1 * V_14 ,
T_2 * V_4 )
{
int V_7 ;
F_14 ( V_2 ) ;
F_14 ( V_3 ) ;
F_14 ( V_14 ) ;
#define F_16
#define F_17
#define F_18
#ifdef F_16
if ( F_8 ( V_14 ) ) {
# ifdef F_17
if ( V_2 -> V_15 == 1 && ! V_2 -> V_16
&& ( F_2 ( V_3 , V_10 ) == 0 ) ) {
T_3 V_17 = V_2 -> V_18 [ 0 ] ;
V_7 = F_19 ( V_1 , V_17 , V_3 , V_14 , V_4 , NULL ) ;
} else
# endif
V_7 = F_20 ( V_1 , V_2 , V_3 , V_14 , V_4 , NULL ) ;
} else
#endif
#ifdef F_18
{
V_7 = F_21 ( V_1 , V_2 , V_3 , V_14 , V_4 ) ;
}
#else
{
V_7 = F_22 ( V_1 , V_2 , V_3 , V_14 , V_4 ) ;
}
#endif
F_14 ( V_1 ) ;
return ( V_7 ) ;
}
int F_21 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 ,
const T_1 * V_14 , T_2 * V_4 )
{
int V_5 , V_19 , V_6 , V_7 = 0 , V_20 , V_21 , V_22 , V_23 ;
int V_24 = 1 ;
T_1 * V_25 ;
T_1 * V_26 [ V_27 ] ;
T_4 V_28 ;
if ( F_2 ( V_3 , V_10 ) != 0 ) {
F_3 ( V_29 , V_12 ) ;
return - 1 ;
}
V_6 = F_7 ( V_3 ) ;
if ( V_6 == 0 ) {
V_7 = F_9 ( V_1 ) ;
return V_7 ;
}
F_4 ( V_4 ) ;
V_25 = F_5 ( V_4 ) ;
V_26 [ 0 ] = F_5 ( V_4 ) ;
if ( ! V_25 || ! V_26 [ 0 ] )
goto V_13;
F_23 ( & V_28 ) ;
if ( V_14 -> V_16 ) {
if ( ! F_6 ( V_25 , V_14 ) )
goto V_13;
V_25 -> V_16 = 0 ;
if ( F_24 ( & V_28 , V_25 , V_4 ) <= 0 )
goto V_13;
} else {
if ( F_24 ( & V_28 , V_14 , V_4 ) <= 0 )
goto V_13;
}
if ( ! F_25 ( V_26 [ 0 ] , V_2 , V_14 , V_4 ) )
goto V_13;
if ( F_26 ( V_26 [ 0 ] ) ) {
F_27 ( V_1 ) ;
V_7 = 1 ;
goto V_13;
}
V_22 = F_28 ( V_6 ) ;
if ( V_22 > 1 ) {
if ( ! F_29 ( V_25 , V_26 [ 0 ] , V_26 [ 0 ] , & V_28 , V_4 ) )
goto V_13;
V_19 = 1 << ( V_22 - 1 ) ;
for ( V_5 = 1 ; V_5 < V_19 ; V_5 ++ ) {
if ( ( ( V_26 [ V_5 ] = F_5 ( V_4 ) ) == NULL ) ||
! F_29 ( V_26 [ V_5 ] , V_26 [ V_5 - 1 ] , V_25 , & V_28 , V_4 ) )
goto V_13;
}
}
V_24 = 1 ;
V_23 = 0 ;
V_20 = V_6 - 1 ;
V_21 = 0 ;
if ( ! F_9 ( V_1 ) )
goto V_13;
for (; ; ) {
if ( F_11 ( V_3 , V_20 ) == 0 ) {
if ( ! V_24 )
if ( ! F_29 ( V_1 , V_1 , V_1 , & V_28 , V_4 ) )
goto V_13;
if ( V_20 == 0 )
break;
V_20 -- ;
continue;
}
V_19 = V_20 ;
V_23 = 1 ;
V_21 = 0 ;
for ( V_5 = 1 ; V_5 < V_22 ; V_5 ++ ) {
if ( V_20 - V_5 < 0 )
break;
if ( F_11 ( V_3 , V_20 - V_5 ) ) {
V_23 <<= ( V_5 - V_21 ) ;
V_23 |= 1 ;
V_21 = V_5 ;
}
}
V_19 = V_21 + 1 ;
if ( ! V_24 )
for ( V_5 = 0 ; V_5 < V_19 ; V_5 ++ ) {
if ( ! F_29 ( V_1 , V_1 , V_1 , & V_28 , V_4 ) )
goto V_13;
}
if ( ! F_29 ( V_1 , V_1 , V_26 [ V_23 >> 1 ] , & V_28 , V_4 ) )
goto V_13;
V_20 -= V_21 + 1 ;
V_23 = 0 ;
V_24 = 0 ;
if ( V_20 < 0 )
break;
}
V_7 = 1 ;
V_13:
F_13 ( V_4 ) ;
F_30 ( & V_28 ) ;
F_14 ( V_1 ) ;
return ( V_7 ) ;
}
int F_20 ( T_1 * V_9 , const T_1 * V_2 , const T_1 * V_3 ,
const T_1 * V_14 , T_2 * V_4 , T_5 * V_30 )
{
int V_5 , V_19 , V_6 , V_7 = 0 , V_20 , V_21 , V_22 , V_23 ;
int V_24 = 1 ;
T_1 * V_18 , * V_1 ;
const T_1 * V_25 ;
T_1 * V_26 [ V_27 ] ;
T_5 * V_31 = NULL ;
if ( F_2 ( V_3 , V_10 ) != 0 ) {
return F_31 ( V_9 , V_2 , V_3 , V_14 , V_4 , V_30 ) ;
}
F_14 ( V_2 ) ;
F_14 ( V_3 ) ;
F_14 ( V_14 ) ;
if ( ! F_8 ( V_14 ) ) {
F_3 ( V_32 , V_33 ) ;
return ( 0 ) ;
}
V_6 = F_7 ( V_3 ) ;
if ( V_6 == 0 ) {
V_7 = F_9 ( V_9 ) ;
return V_7 ;
}
F_4 ( V_4 ) ;
V_18 = F_5 ( V_4 ) ;
V_1 = F_5 ( V_4 ) ;
V_26 [ 0 ] = F_5 ( V_4 ) ;
if ( ! V_18 || ! V_1 || ! V_26 [ 0 ] )
goto V_13;
if ( V_30 != NULL )
V_31 = V_30 ;
else {
if ( ( V_31 = F_32 () ) == NULL )
goto V_13;
if ( ! F_33 ( V_31 , V_14 , V_4 ) )
goto V_13;
}
if ( V_2 -> V_16 || F_34 ( V_2 , V_14 ) >= 0 ) {
if ( ! F_25 ( V_26 [ 0 ] , V_2 , V_14 , V_4 ) )
goto V_13;
V_25 = V_26 [ 0 ] ;
} else
V_25 = V_2 ;
if ( F_26 ( V_25 ) ) {
F_27 ( V_9 ) ;
V_7 = 1 ;
goto V_13;
}
if ( ! F_35 ( V_26 [ 0 ] , V_25 , V_31 , V_4 ) )
goto V_13;
V_22 = F_28 ( V_6 ) ;
if ( V_22 > 1 ) {
if ( ! F_36 ( V_18 , V_26 [ 0 ] , V_26 [ 0 ] , V_31 , V_4 ) )
goto V_13;
V_19 = 1 << ( V_22 - 1 ) ;
for ( V_5 = 1 ; V_5 < V_19 ; V_5 ++ ) {
if ( ( ( V_26 [ V_5 ] = F_5 ( V_4 ) ) == NULL ) ||
! F_36 ( V_26 [ V_5 ] , V_26 [ V_5 - 1 ] , V_18 , V_31 , V_4 ) )
goto V_13;
}
}
V_24 = 1 ;
V_23 = 0 ;
V_20 = V_6 - 1 ;
V_21 = 0 ;
#if 1
V_19 = V_14 -> V_15 ;
if ( V_14 -> V_18 [ V_19 - 1 ] & ( ( ( T_3 ) 1 ) << ( V_34 - 1 ) ) ) {
if ( F_37 ( V_1 , V_19 ) == NULL )
goto V_13;
V_1 -> V_18 [ 0 ] = ( 0 - V_14 -> V_18 [ 0 ] ) & V_35 ;
for ( V_5 = 1 ; V_5 < V_19 ; V_5 ++ )
V_1 -> V_18 [ V_5 ] = ( ~ V_14 -> V_18 [ V_5 ] ) & V_35 ;
V_1 -> V_15 = V_19 ;
F_38 ( V_1 ) ;
} else
#endif
if ( ! F_35 ( V_1 , F_39 () , V_31 , V_4 ) )
goto V_13;
for (; ; ) {
if ( F_11 ( V_3 , V_20 ) == 0 ) {
if ( ! V_24 ) {
if ( ! F_36 ( V_1 , V_1 , V_1 , V_31 , V_4 ) )
goto V_13;
}
if ( V_20 == 0 )
break;
V_20 -- ;
continue;
}
V_19 = V_20 ;
V_23 = 1 ;
V_21 = 0 ;
for ( V_5 = 1 ; V_5 < V_22 ; V_5 ++ ) {
if ( V_20 - V_5 < 0 )
break;
if ( F_11 ( V_3 , V_20 - V_5 ) ) {
V_23 <<= ( V_5 - V_21 ) ;
V_23 |= 1 ;
V_21 = V_5 ;
}
}
V_19 = V_21 + 1 ;
if ( ! V_24 )
for ( V_5 = 0 ; V_5 < V_19 ; V_5 ++ ) {
if ( ! F_36 ( V_1 , V_1 , V_1 , V_31 , V_4 ) )
goto V_13;
}
if ( ! F_36 ( V_1 , V_1 , V_26 [ V_23 >> 1 ] , V_31 , V_4 ) )
goto V_13;
V_20 -= V_21 + 1 ;
V_23 = 0 ;
V_24 = 0 ;
if ( V_20 < 0 )
break;
}
#if F_40 ( V_36 )
if ( V_37 [ 0 ] & ( V_38 | V_39 ) ) {
V_19 = V_31 -> V_40 . V_15 ;
V_26 [ 0 ] -> V_18 [ 0 ] = 1 ;
for ( V_5 = 1 ; V_5 < V_19 ; V_5 ++ )
V_26 [ 0 ] -> V_18 [ V_5 ] = 0 ;
V_26 [ 0 ] -> V_15 = V_19 ;
if ( ! F_36 ( V_9 , V_1 , V_26 [ 0 ] , V_31 , V_4 ) )
goto V_13;
} else
#endif
if ( ! F_41 ( V_9 , V_1 , V_31 , V_4 ) )
goto V_13;
V_7 = 1 ;
V_13:
if ( ( V_30 == NULL ) && ( V_31 != NULL ) )
F_42 ( V_31 ) ;
F_13 ( V_4 ) ;
F_14 ( V_9 ) ;
return ( V_7 ) ;
}
static T_3 F_43 ( const T_1 * V_2 , int V_41 )
{
T_3 V_7 = 0 ;
int V_42 ;
V_42 = V_41 / V_34 ;
V_41 %= V_34 ;
if ( V_42 >= 0 && V_42 < V_2 -> V_15 ) {
V_7 = V_2 -> V_18 [ V_42 ] & V_35 ;
if ( V_41 ) {
V_7 >>= V_41 ;
if ( ++ V_42 < V_2 -> V_15 )
V_7 |= V_2 -> V_18 [ V_42 ] << ( V_34 - V_41 ) ;
}
}
return V_7 & V_35 ;
}
static int F_44 ( const T_1 * V_43 , int V_15 ,
unsigned char * V_44 , int V_45 ,
int V_46 )
{
T_6 V_5 , V_19 ;
if ( V_15 > V_43 -> V_15 )
V_15 = V_43 -> V_15 ;
for ( V_5 = 0 , V_19 = V_45 ; V_5 < V_15 * sizeof V_43 -> V_18 [ 0 ] ; V_5 ++ , V_19 += V_46 ) {
V_44 [ V_19 ] = ( ( unsigned char * ) V_43 -> V_18 ) [ V_5 ] ;
}
return 1 ;
}
static int F_45 ( T_1 * V_43 , int V_15 ,
unsigned char * V_44 , int V_45 ,
int V_46 )
{
T_6 V_5 , V_19 ;
if ( F_37 ( V_43 , V_15 ) == NULL )
return 0 ;
for ( V_5 = 0 , V_19 = V_45 ; V_5 < V_15 * sizeof V_43 -> V_18 [ 0 ] ; V_5 ++ , V_19 += V_46 ) {
( ( unsigned char * ) V_43 -> V_18 ) [ V_5 ] = V_44 [ V_19 ] ;
}
V_43 -> V_15 = V_15 ;
F_38 ( V_43 ) ;
return 1 ;
}
int F_31 ( T_1 * V_9 , const T_1 * V_2 , const T_1 * V_3 ,
const T_1 * V_14 , T_2 * V_4 ,
T_5 * V_30 )
{
int V_5 , V_6 , V_7 = 0 , V_22 , V_23 ;
int V_15 ;
T_5 * V_31 = NULL ;
int V_47 ;
unsigned char * V_48 = NULL ;
int V_49 = 0 ;
unsigned char * V_50 = NULL ;
T_1 V_51 , V_52 ;
#if F_40 ( V_36 )
unsigned int V_53 = 0 ;
#endif
F_14 ( V_2 ) ;
F_14 ( V_3 ) ;
F_14 ( V_14 ) ;
V_15 = V_14 -> V_15 ;
if ( ! ( V_14 -> V_18 [ 0 ] & 1 ) ) {
F_3 ( V_54 , V_33 ) ;
return ( 0 ) ;
}
V_6 = F_7 ( V_3 ) ;
if ( V_6 == 0 ) {
V_7 = F_9 ( V_9 ) ;
return V_7 ;
}
F_4 ( V_4 ) ;
if ( V_30 != NULL )
V_31 = V_30 ;
else {
if ( ( V_31 = F_32 () ) == NULL )
goto V_13;
if ( ! F_33 ( V_31 , V_14 , V_4 ) )
goto V_13;
}
#ifdef F_46
if ( ( 16 == V_2 -> V_15 ) && ( 16 == V_3 -> V_15 ) && ( F_7 ( V_14 ) == 1024 )
&& F_47 () ) {
if ( NULL == F_37 ( V_9 , 16 ) )
goto V_13;
F_48 ( V_9 -> V_18 , V_2 -> V_18 , V_3 -> V_18 , V_14 -> V_18 , V_31 -> V_55 . V_18 ,
V_31 -> V_56 [ 0 ] ) ;
V_9 -> V_15 = 16 ;
V_9 -> V_16 = 0 ;
F_38 ( V_9 ) ;
V_7 = 1 ;
goto V_13;
} else if ( ( 8 == V_2 -> V_15 ) && ( 8 == V_3 -> V_15 ) && ( F_7 ( V_14 ) == 512 ) ) {
if ( NULL == F_37 ( V_9 , 8 ) )
goto V_13;
F_49 ( V_9 -> V_18 , V_2 -> V_18 , V_3 -> V_18 , V_14 -> V_18 , V_31 -> V_56 [ 0 ] , V_31 -> V_55 . V_18 ) ;
V_9 -> V_15 = 8 ;
V_9 -> V_16 = 0 ;
F_38 ( V_9 ) ;
V_7 = 1 ;
goto V_13;
}
#endif
V_22 = F_50 ( V_6 ) ;
#if F_40 ( V_36 )
if ( V_22 >= 5 && ( V_15 & 15 ) == 0 && V_15 <= 64 &&
( V_37 [ 1 ] & ( V_57 | V_58 ) ) ==
( V_57 | V_58 ) && ( V_53 = V_37 [ 0 ] ) )
V_22 = 5 ;
else
#endif
#if F_40 ( V_59 )
if ( V_22 >= 5 ) {
V_22 = 5 ;
if ( ( V_15 & 7 ) == 0 )
V_49 += 2 * V_15 * sizeof( V_14 -> V_18 [ 0 ] ) ;
}
#endif
( void ) 0 ;
V_47 = 1 << V_22 ;
V_49 += sizeof( V_14 -> V_18 [ 0 ] ) * ( V_15 * V_47 +
( ( 2 * V_15 ) >
V_47 ? ( 2 * V_15 ) : V_47 ) ) ;
#ifdef F_51
if ( V_49 < 3072 )
V_48 =
F_51 ( V_49 + V_60 ) ;
else
#endif
if ( ( V_48 =
( unsigned char * ) F_52 ( V_49 +
V_60 ) )
== NULL )
goto V_13;
V_50 = F_53 ( V_48 ) ;
memset ( V_50 , 0 , V_49 ) ;
#ifdef F_51
if ( V_49 < 3072 )
V_48 = NULL ;
#endif
V_51 . V_18 = ( T_3 * ) ( V_50 + sizeof( V_14 -> V_18 [ 0 ] ) * V_15 * V_47 ) ;
V_52 . V_18 = V_51 . V_18 + V_15 ;
V_51 . V_15 = V_52 . V_15 = 0 ;
V_51 . V_61 = V_52 . V_61 = V_15 ;
V_51 . V_16 = V_52 . V_16 = 0 ;
V_51 . V_62 = V_52 . V_62 = V_63 ;
#if 1
if ( V_14 -> V_18 [ V_15 - 1 ] & ( ( ( T_3 ) 1 ) << ( V_34 - 1 ) ) ) {
V_51 . V_18 [ 0 ] = ( 0 - V_14 -> V_18 [ 0 ] ) & V_35 ;
for ( V_5 = 1 ; V_5 < V_15 ; V_5 ++ )
V_51 . V_18 [ V_5 ] = ( ~ V_14 -> V_18 [ V_5 ] ) & V_35 ;
V_51 . V_15 = V_15 ;
} else
#endif
if ( ! F_35 ( & V_51 , F_39 () , V_31 , V_4 ) )
goto V_13;
if ( V_2 -> V_16 || F_34 ( V_2 , V_14 ) >= 0 ) {
if ( ! F_54 ( & V_52 , V_2 , V_14 , V_4 ) )
goto V_13;
if ( ! F_35 ( & V_52 , & V_52 , V_31 , V_4 ) )
goto V_13;
} else if ( ! F_35 ( & V_52 , V_2 , V_31 , V_4 ) )
goto V_13;
#if F_40 ( V_36 )
if ( V_53 ) {
typedef int (* F_55) ( T_3 * V_64 , const T_3 * V_65 ,
const T_3 * V_56 , const void * V_66 ,
int V_67 , int V_6 );
int V_68 ( T_3 * V_64 , const T_3 * V_65 ,
const T_3 * V_56 , const void * V_66 ,
int V_67 , int V_6 ) ;
int V_69 ( T_3 * V_64 , const T_3 * V_65 ,
const T_3 * V_56 , const void * V_66 ,
int V_67 , int V_6 ) ;
int V_70 ( T_3 * V_64 , const T_3 * V_65 ,
const T_3 * V_56 , const void * V_66 ,
int V_67 , int V_6 ) ;
int V_71 ( T_3 * V_64 , const T_3 * V_65 ,
const T_3 * V_56 , const void * V_66 ,
int V_67 , int V_6 ) ;
static const F_55 V_72 [ 4 ] = {
V_68 , V_69 ,
V_70 , V_71
} ;
F_55 V_73 = V_72 [ V_15 / 16 - 1 ] ;
typedef int (* F_56) ( T_3 * V_74 , const T_3 * V_75 ,
const void * V_76 , const T_3 * V_65 ,
const T_3 * V_56 );
int V_77 ( T_3 * V_74 , const T_3 * V_75 , const void * V_76 ,
const T_3 * V_65 , const T_3 * V_56 ) ;
int V_78 ( T_3 * V_74 , const T_3 * V_75 ,
const void * V_76 , const T_3 * V_65 ,
const T_3 * V_56 ) ;
int V_79 ( T_3 * V_74 , const T_3 * V_75 ,
const void * V_76 , const T_3 * V_65 ,
const T_3 * V_56 ) ;
int V_80 ( T_3 * V_74 , const T_3 * V_75 ,
const void * V_76 , const T_3 * V_65 ,
const T_3 * V_56 ) ;
static const F_56 V_81 [ 4 ] = {
V_77 , V_78 ,
V_79 , V_80
} ;
F_56 V_82 = V_81 [ V_15 / 16 - 1 ] ;
void V_83 ( T_3 * V_74 , const T_3 * V_75 ,
const void * V_76 , const T_3 * V_65 ,
const T_3 * V_56 , int V_84 ) ;
void V_85 ( T_3 * V_74 , const T_3 * V_75 ,
const void * V_76 , const T_3 * V_65 ,
const T_3 * V_56 , int V_84 ) ;
void V_86 ( T_3 * V_74 , const T_3 * V_75 ,
const void * V_66 , const T_3 * V_65 ,
const T_3 * V_56 , int V_84 , int V_67 ) ;
void V_87 ( const T_3 * V_88 , T_6 V_84 ,
void * V_66 , T_6 V_67 ) ;
void V_89 ( T_3 * V_90 , T_6 V_84 ,
void * V_66 , T_6 V_67 ) ;
void V_91 ( T_3 * V_92 , T_3 * V_93 , T_6 V_84 ) ;
T_3 * V_65 = V_31 -> V_40 . V_18 , * V_56 = V_31 -> V_56 ;
int V_94 = 5 * ( 6 - ( V_15 / 16 - 1 ) ) ;
for ( V_5 = V_52 . V_15 ; V_5 < V_15 ; V_5 ++ )
V_52 . V_18 [ V_5 ] = 0 ;
for ( V_5 = V_51 . V_15 ; V_5 < V_15 ; V_5 ++ )
V_51 . V_18 [ V_5 ] = 0 ;
V_87 ( V_51 . V_18 , V_15 , V_50 , 0 ) ;
V_87 ( V_52 . V_18 , V_15 , V_50 , 1 ) ;
if ( ! (* V_82) ( V_51 . V_18 , V_52 . V_18 , V_52 . V_18 , V_65 , V_56 ) &&
! (* V_82) ( V_51 . V_18 , V_52 . V_18 , V_52 . V_18 , V_65 , V_56 ) )
V_83 ( V_51 . V_18 , V_52 . V_18 , V_52 . V_18 , V_65 , V_56 , V_15 ) ;
V_87 ( V_51 . V_18 , V_15 , V_50 , 2 ) ;
for ( V_5 = 3 ; V_5 < 32 ; V_5 ++ ) {
if ( ! (* V_82) ( V_51 . V_18 , V_51 . V_18 , V_52 . V_18 , V_65 , V_56 ) &&
! (* V_82) ( V_51 . V_18 , V_51 . V_18 , V_52 . V_18 , V_65 , V_56 ) )
V_83 ( V_51 . V_18 , V_51 . V_18 , V_52 . V_18 , V_65 , V_56 , V_15 ) ;
V_87 ( V_51 . V_18 , V_15 , V_50 , V_5 ) ;
}
V_65 = F_51 ( V_15 * sizeof( T_3 ) ) ;
V_15 /= 2 ;
V_91 ( V_65 , V_31 -> V_40 . V_18 , V_15 ) ;
V_6 -- ;
for ( V_23 = 0 , V_5 = V_6 % 5 ; V_5 >= 0 ; V_5 -- , V_6 -- )
V_23 = ( V_23 << 1 ) + F_11 ( V_3 , V_6 ) ;
V_89 ( V_51 . V_18 , V_15 , V_50 , V_23 ) ;
while ( V_6 >= 0 ) {
if ( V_6 < V_94 )
V_94 = V_6 + 1 ;
V_6 -= V_94 ;
V_23 = F_43 ( V_3 , V_6 + 1 ) ;
if ( (* V_73) ( V_51 . V_18 , V_65 , V_56 , V_50 , V_23 , V_94 ) )
continue;
if ( (* V_73) ( V_51 . V_18 , V_65 , V_56 , V_50 , V_23 , V_94 ) )
continue;
V_6 += V_94 - 5 ;
V_23 >>= V_94 - 5 ;
V_23 &= 31 ;
V_85 ( V_51 . V_18 , V_51 . V_18 , V_51 . V_18 , V_65 , V_56 , V_15 ) ;
V_85 ( V_51 . V_18 , V_51 . V_18 , V_51 . V_18 , V_65 , V_56 , V_15 ) ;
V_85 ( V_51 . V_18 , V_51 . V_18 , V_51 . V_18 , V_65 , V_56 , V_15 ) ;
V_85 ( V_51 . V_18 , V_51 . V_18 , V_51 . V_18 , V_65 , V_56 , V_15 ) ;
V_85 ( V_51 . V_18 , V_51 . V_18 , V_51 . V_18 , V_65 , V_56 , V_15 ) ;
V_86 ( V_51 . V_18 , V_51 . V_18 , V_50 , V_65 , V_56 , V_15 ,
V_23 ) ;
}
V_91 ( V_51 . V_18 , V_51 . V_18 , V_15 ) ;
V_15 *= 2 ;
V_51 . V_15 = V_15 ;
F_38 ( & V_51 ) ;
F_57 ( V_65 , V_15 * sizeof( T_3 ) ) ;
} else
#endif
#if F_40 ( V_59 )
if ( V_22 == 5 && V_15 > 1 ) {
void V_95 ( T_3 * V_74 , const T_3 * V_75 ,
const void * V_66 , const T_3 * V_65 ,
const T_3 * V_56 , int V_84 , int V_67 ) ;
void V_96 ( const T_3 * V_88 , T_6 V_84 ,
void * V_66 , T_6 V_67 ) ;
void V_97 ( T_3 * V_90 , T_6 V_84 , void * V_66 , T_6 V_67 ) ;
void V_98 ( T_3 * V_74 , const T_3 * V_75 ,
const void * V_66 , const T_3 * V_65 ,
const T_3 * V_56 , int V_84 , int V_67 ) ;
int V_99 ( const T_3 * V_75 , int V_100 ) ;
int V_101 ( T_3 * V_74 , const T_3 * V_75 ,
const T_3 * V_102 , const T_3 * V_65 ,
const T_3 * V_56 , int V_84 ) ;
T_3 * V_65 = V_31 -> V_40 . V_18 , * V_56 = V_31 -> V_56 , * V_103 ;
for ( V_5 = V_52 . V_15 ; V_5 < V_15 ; V_5 ++ )
V_52 . V_18 [ V_5 ] = 0 ;
for ( V_5 = V_51 . V_15 ; V_5 < V_15 ; V_5 ++ )
V_51 . V_18 [ V_5 ] = 0 ;
if ( V_15 & 7 )
V_103 = V_65 ;
else
for ( V_103 = V_52 . V_18 + V_15 , V_5 = 0 ; V_5 < V_15 ; V_5 ++ )
V_103 [ 2 * V_5 ] = V_65 [ V_5 ] ;
V_96 ( V_51 . V_18 , V_15 , V_50 , 0 ) ;
V_96 ( V_52 . V_18 , V_52 . V_15 , V_50 , 1 ) ;
F_58 ( V_51 . V_18 , V_52 . V_18 , V_52 . V_18 , V_65 , V_56 , V_15 ) ;
V_96 ( V_51 . V_18 , V_15 , V_50 , 2 ) ;
# if 0
for (i = 3; i < 32; i++) {
bn_mul_mont_gather5(tmp.d, am.d, powerbuf, np2, n0, top, i - 1);
bn_scatter5(tmp.d, top, powerbuf, i);
}
# else
for ( V_5 = 4 ; V_5 < 32 ; V_5 *= 2 ) {
F_58 ( V_51 . V_18 , V_51 . V_18 , V_51 . V_18 , V_65 , V_56 , V_15 ) ;
V_96 ( V_51 . V_18 , V_15 , V_50 , V_5 ) ;
}
for ( V_5 = 3 ; V_5 < 8 ; V_5 += 2 ) {
int V_19 ;
V_95 ( V_51 . V_18 , V_52 . V_18 , V_50 , V_103 , V_56 , V_15 , V_5 - 1 ) ;
V_96 ( V_51 . V_18 , V_15 , V_50 , V_5 ) ;
for ( V_19 = 2 * V_5 ; V_19 < 32 ; V_19 *= 2 ) {
F_58 ( V_51 . V_18 , V_51 . V_18 , V_51 . V_18 , V_65 , V_56 , V_15 ) ;
V_96 ( V_51 . V_18 , V_15 , V_50 , V_19 ) ;
}
}
for (; V_5 < 16 ; V_5 += 2 ) {
V_95 ( V_51 . V_18 , V_52 . V_18 , V_50 , V_103 , V_56 , V_15 , V_5 - 1 ) ;
V_96 ( V_51 . V_18 , V_15 , V_50 , V_5 ) ;
F_58 ( V_51 . V_18 , V_51 . V_18 , V_51 . V_18 , V_65 , V_56 , V_15 ) ;
V_96 ( V_51 . V_18 , V_15 , V_50 , 2 * V_5 ) ;
}
for (; V_5 < 32 ; V_5 += 2 ) {
V_95 ( V_51 . V_18 , V_52 . V_18 , V_50 , V_103 , V_56 , V_15 , V_5 - 1 ) ;
V_96 ( V_51 . V_18 , V_15 , V_50 , V_5 ) ;
}
# endif
V_6 -- ;
for ( V_23 = 0 , V_5 = V_6 % 5 ; V_5 >= 0 ; V_5 -- , V_6 -- )
V_23 = ( V_23 << 1 ) + F_11 ( V_3 , V_6 ) ;
V_97 ( V_51 . V_18 , V_15 , V_50 , V_23 ) ;
if ( V_15 & 7 )
while ( V_6 >= 0 ) {
for ( V_23 = 0 , V_5 = 0 ; V_5 < 5 ; V_5 ++ , V_6 -- )
V_23 = ( V_23 << 1 ) + F_11 ( V_3 , V_6 ) ;
F_58 ( V_51 . V_18 , V_51 . V_18 , V_51 . V_18 , V_65 , V_56 , V_15 ) ;
F_58 ( V_51 . V_18 , V_51 . V_18 , V_51 . V_18 , V_65 , V_56 , V_15 ) ;
F_58 ( V_51 . V_18 , V_51 . V_18 , V_51 . V_18 , V_65 , V_56 , V_15 ) ;
F_58 ( V_51 . V_18 , V_51 . V_18 , V_51 . V_18 , V_65 , V_56 , V_15 ) ;
F_58 ( V_51 . V_18 , V_51 . V_18 , V_51 . V_18 , V_65 , V_56 , V_15 ) ;
V_95 ( V_51 . V_18 , V_51 . V_18 , V_50 , V_65 , V_56 , V_15 ,
V_23 ) ;
} else {
while ( V_6 >= 0 ) {
V_23 = V_99 ( V_3 -> V_18 , V_6 - 4 ) ;
V_6 -= 5 ;
V_98 ( V_51 . V_18 , V_51 . V_18 , V_50 , V_103 , V_56 , V_15 , V_23 ) ;
}
}
V_7 = V_101 ( V_51 . V_18 , V_51 . V_18 , NULL , V_103 , V_56 , V_15 ) ;
V_51 . V_15 = V_15 ;
F_38 ( & V_51 ) ;
if ( V_7 ) {
if ( ! F_6 ( V_9 , & V_51 ) )
V_7 = 0 ;
goto V_13;
}
} else
#endif
{
if ( ! F_44 ( & V_51 , V_15 , V_50 , 0 , V_47 ) )
goto V_13;
if ( ! F_44 ( & V_52 , V_15 , V_50 , 1 , V_47 ) )
goto V_13;
if ( V_22 > 1 ) {
if ( ! F_36 ( & V_51 , & V_52 , & V_52 , V_31 , V_4 ) )
goto V_13;
if ( ! F_44
( & V_51 , V_15 , V_50 , 2 , V_47 ) )
goto V_13;
for ( V_5 = 3 ; V_5 < V_47 ; V_5 ++ ) {
if ( ! F_36 ( & V_51 , & V_52 , & V_51 , V_31 , V_4 ) )
goto V_13;
if ( ! F_44
( & V_51 , V_15 , V_50 , V_5 , V_47 ) )
goto V_13;
}
}
V_6 -- ;
for ( V_23 = 0 , V_5 = V_6 % V_22 ; V_5 >= 0 ; V_5 -- , V_6 -- )
V_23 = ( V_23 << 1 ) + F_11 ( V_3 , V_6 ) ;
if ( ! F_45
( & V_51 , V_15 , V_50 , V_23 , V_47 ) )
goto V_13;
while ( V_6 >= 0 ) {
V_23 = 0 ;
for ( V_5 = 0 ; V_5 < V_22 ; V_5 ++ , V_6 -- ) {
if ( ! F_36 ( & V_51 , & V_51 , & V_51 , V_31 , V_4 ) )
goto V_13;
V_23 = ( V_23 << 1 ) + F_11 ( V_3 , V_6 ) ;
}
if ( ! F_45
( & V_52 , V_15 , V_50 , V_23 , V_47 ) )
goto V_13;
if ( ! F_36 ( & V_51 , & V_51 , & V_52 , V_31 , V_4 ) )
goto V_13;
}
}
#if F_40 ( V_36 )
if ( V_37 [ 0 ] & ( V_38 | V_39 ) ) {
V_52 . V_18 [ 0 ] = 1 ;
for ( V_5 = 1 ; V_5 < V_15 ; V_5 ++ )
V_52 . V_18 [ V_5 ] = 0 ;
if ( ! F_36 ( V_9 , & V_51 , & V_52 , V_31 , V_4 ) )
goto V_13;
} else
#endif
if ( ! F_41 ( V_9 , & V_51 , V_31 , V_4 ) )
goto V_13;
V_7 = 1 ;
V_13:
if ( ( V_30 == NULL ) && ( V_31 != NULL ) )
F_42 ( V_31 ) ;
if ( V_50 != NULL ) {
F_57 ( V_50 , V_49 ) ;
if ( V_48 )
F_59 ( V_48 ) ;
}
F_13 ( V_4 ) ;
return ( V_7 ) ;
}
int F_19 ( T_1 * V_9 , T_3 V_2 , const T_1 * V_3 ,
const T_1 * V_14 , T_2 * V_4 , T_5 * V_30 )
{
T_5 * V_31 = NULL ;
int V_43 , V_6 , V_7 = 0 ;
int V_104 ;
T_3 V_105 , V_106 ;
T_1 * V_18 , * V_1 , * V_107 ;
T_1 * V_108 ;
#define F_60 ( V_1 , V_105 , V_14 ) \
(BN_mul_word(r, (w)) && \
( \
(BN_mod(t, r, m, ctx) && (swap_tmp = r, r = t, t = swap_tmp, 1))))
#define F_61 ( V_1 , V_105 , V_31 ) \
(BN_set_word(r, (w)) && BN_to_montgomery(r, r, (mont), ctx))
if ( F_2 ( V_3 , V_10 ) != 0 ) {
F_3 ( V_109 , V_12 ) ;
return - 1 ;
}
F_14 ( V_3 ) ;
F_14 ( V_14 ) ;
if ( ! F_8 ( V_14 ) ) {
F_3 ( V_109 , V_33 ) ;
return ( 0 ) ;
}
if ( V_14 -> V_15 == 1 )
V_2 %= V_14 -> V_18 [ 0 ] ;
V_6 = F_7 ( V_3 ) ;
if ( V_6 == 0 ) {
if ( F_62 ( V_14 ) ) {
V_7 = 1 ;
F_27 ( V_9 ) ;
} else
V_7 = F_9 ( V_9 ) ;
return V_7 ;
}
if ( V_2 == 0 ) {
F_27 ( V_9 ) ;
V_7 = 1 ;
return V_7 ;
}
F_4 ( V_4 ) ;
V_18 = F_5 ( V_4 ) ;
V_1 = F_5 ( V_4 ) ;
V_107 = F_5 ( V_4 ) ;
if ( V_18 == NULL || V_1 == NULL || V_107 == NULL )
goto V_13;
if ( V_30 != NULL )
V_31 = V_30 ;
else {
if ( ( V_31 = F_32 () ) == NULL )
goto V_13;
if ( ! F_33 ( V_31 , V_14 , V_4 ) )
goto V_13;
}
V_104 = 1 ;
V_105 = V_2 ;
for ( V_43 = V_6 - 2 ; V_43 >= 0 ; V_43 -- ) {
V_106 = V_105 * V_105 ;
if ( ( V_106 / V_105 ) != V_105 ) {
if ( V_104 ) {
if ( ! F_61 ( V_1 , V_105 , V_31 ) )
goto V_13;
V_104 = 0 ;
} else {
if ( ! F_60 ( V_1 , V_105 , V_14 ) )
goto V_13;
}
V_106 = 1 ;
}
V_105 = V_106 ;
if ( ! V_104 ) {
if ( ! F_36 ( V_1 , V_1 , V_1 , V_31 , V_4 ) )
goto V_13;
}
if ( F_11 ( V_3 , V_43 ) ) {
V_106 = V_105 * V_2 ;
if ( ( V_106 / V_2 ) != V_105 ) {
if ( V_104 ) {
if ( ! F_61 ( V_1 , V_105 , V_31 ) )
goto V_13;
V_104 = 0 ;
} else {
if ( ! F_60 ( V_1 , V_105 , V_14 ) )
goto V_13;
}
V_106 = V_2 ;
}
V_105 = V_106 ;
}
}
if ( V_105 != 1 ) {
if ( V_104 ) {
if ( ! F_61 ( V_1 , V_105 , V_31 ) )
goto V_13;
V_104 = 0 ;
} else {
if ( ! F_60 ( V_1 , V_105 , V_14 ) )
goto V_13;
}
}
if ( V_104 ) {
if ( ! F_9 ( V_9 ) )
goto V_13;
} else {
if ( ! F_41 ( V_9 , V_1 , V_31 , V_4 ) )
goto V_13;
}
V_7 = 1 ;
V_13:
if ( ( V_30 == NULL ) && ( V_31 != NULL ) )
F_42 ( V_31 ) ;
F_13 ( V_4 ) ;
F_14 ( V_9 ) ;
return ( V_7 ) ;
}
int F_22 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 ,
const T_1 * V_14 , T_2 * V_4 )
{
int V_5 , V_19 , V_6 , V_7 = 0 , V_20 , V_21 , V_22 , V_23 ;
int V_24 = 1 ;
T_1 * V_18 ;
T_1 * V_26 [ V_27 ] ;
if ( F_2 ( V_3 , V_10 ) != 0 ) {
F_3 ( V_110 , V_12 ) ;
return - 1 ;
}
V_6 = F_7 ( V_3 ) ;
if ( V_6 == 0 ) {
V_7 = F_9 ( V_1 ) ;
return V_7 ;
}
F_4 ( V_4 ) ;
V_18 = F_5 ( V_4 ) ;
V_26 [ 0 ] = F_5 ( V_4 ) ;
if ( ! V_18 || ! V_26 [ 0 ] )
goto V_13;
if ( ! F_25 ( V_26 [ 0 ] , V_2 , V_14 , V_4 ) )
goto V_13;
if ( F_26 ( V_26 [ 0 ] ) ) {
F_27 ( V_1 ) ;
V_7 = 1 ;
goto V_13;
}
V_22 = F_28 ( V_6 ) ;
if ( V_22 > 1 ) {
if ( ! F_63 ( V_18 , V_26 [ 0 ] , V_26 [ 0 ] , V_14 , V_4 ) )
goto V_13;
V_19 = 1 << ( V_22 - 1 ) ;
for ( V_5 = 1 ; V_5 < V_19 ; V_5 ++ ) {
if ( ( ( V_26 [ V_5 ] = F_5 ( V_4 ) ) == NULL ) ||
! F_63 ( V_26 [ V_5 ] , V_26 [ V_5 - 1 ] , V_18 , V_14 , V_4 ) )
goto V_13;
}
}
V_24 = 1 ;
V_23 = 0 ;
V_20 = V_6 - 1 ;
V_21 = 0 ;
if ( ! F_9 ( V_1 ) )
goto V_13;
for (; ; ) {
if ( F_11 ( V_3 , V_20 ) == 0 ) {
if ( ! V_24 )
if ( ! F_63 ( V_1 , V_1 , V_1 , V_14 , V_4 ) )
goto V_13;
if ( V_20 == 0 )
break;
V_20 -- ;
continue;
}
V_19 = V_20 ;
V_23 = 1 ;
V_21 = 0 ;
for ( V_5 = 1 ; V_5 < V_22 ; V_5 ++ ) {
if ( V_20 - V_5 < 0 )
break;
if ( F_11 ( V_3 , V_20 - V_5 ) ) {
V_23 <<= ( V_5 - V_21 ) ;
V_23 |= 1 ;
V_21 = V_5 ;
}
}
V_19 = V_21 + 1 ;
if ( ! V_24 )
for ( V_5 = 0 ; V_5 < V_19 ; V_5 ++ ) {
if ( ! F_63 ( V_1 , V_1 , V_1 , V_14 , V_4 ) )
goto V_13;
}
if ( ! F_63 ( V_1 , V_1 , V_26 [ V_23 >> 1 ] , V_14 , V_4 ) )
goto V_13;
V_20 -= V_21 + 1 ;
V_23 = 0 ;
V_24 = 0 ;
if ( V_20 < 0 )
break;
}
V_7 = 1 ;
V_13:
F_13 ( V_4 ) ;
F_14 ( V_1 ) ;
return ( V_7 ) ;
}
