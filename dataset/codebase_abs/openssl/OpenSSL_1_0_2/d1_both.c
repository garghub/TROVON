static T_1 * F_1 ( unsigned long V_1 ,
int V_2 )
{
T_1 * V_3 = NULL ;
unsigned char * V_4 = NULL ;
unsigned char * V_5 = NULL ;
V_3 = ( T_1 * ) F_2 ( sizeof( T_1 ) ) ;
if ( V_3 == NULL )
return NULL ;
if ( V_1 ) {
V_4 = ( unsigned char * ) F_2 ( V_1 ) ;
if ( V_4 == NULL ) {
F_3 ( V_3 ) ;
return NULL ;
}
}
V_3 -> V_6 = V_4 ;
if ( V_2 ) {
V_5 =
( unsigned char * ) F_2 ( F_4 ( V_1 ) ) ;
if ( V_5 == NULL ) {
if ( V_4 != NULL )
F_3 ( V_4 ) ;
F_3 ( V_3 ) ;
return NULL ;
}
memset ( V_5 , 0 , F_4 ( V_1 ) ) ;
}
V_3 -> V_2 = V_5 ;
return V_3 ;
}
void F_5 ( T_1 * V_3 )
{
if ( V_3 -> V_7 . V_8 ) {
F_6 ( V_3 -> V_7 .
V_9 . V_10 ) ;
F_7 ( V_3 -> V_7 .
V_9 . V_11 ) ;
}
if ( V_3 -> V_6 )
F_3 ( V_3 -> V_6 ) ;
if ( V_3 -> V_2 )
F_3 ( V_3 -> V_2 ) ;
F_3 ( V_3 ) ;
}
static int F_8 ( T_2 * V_12 )
{
if ( V_12 -> V_13 -> V_14 ) {
V_12 -> V_13 -> V_15 =
V_12 -> V_13 -> V_14 - F_9 ( F_10 ( V_12 ) ) ;
V_12 -> V_13 -> V_14 = 0 ;
}
if ( V_12 -> V_13 -> V_15 < F_11 ( V_12 ) ) {
if ( ! ( F_12 ( V_12 ) & V_16 ) ) {
V_12 -> V_13 -> V_15 =
F_13 ( F_10 ( V_12 ) , V_17 , 0 , NULL ) ;
if ( V_12 -> V_13 -> V_15 < F_11 ( V_12 ) ) {
V_12 -> V_13 -> V_15 = F_11 ( V_12 ) ;
F_13 ( F_10 ( V_12 ) , V_18 ,
V_12 -> V_13 -> V_15 , NULL ) ;
}
} else
return 0 ;
}
return 1 ;
}
int F_14 ( T_2 * V_12 , int type )
{
int V_19 ;
unsigned int V_20 ;
int V_21 = 1 ;
unsigned int V_22 , V_23 , V_24 , V_25 , V_26 ;
if ( ! F_8 ( V_12 ) )
return - 1 ;
F_15 ( V_12 -> V_13 -> V_15 >= F_11 ( V_12 ) ) ;
if ( V_12 -> V_27 == 0 && type == V_28 )
F_15 ( V_12 -> V_29 ==
( int ) V_12 -> V_13 -> V_30 . V_31 +
V_32 ) ;
if ( V_12 -> V_11 ) {
if ( V_12 -> V_10
&& F_16 ( V_12 -> V_10 ) == V_33 )
V_24 = 0 ;
else
V_24 = F_17 ( V_12 -> V_11 ) ;
} else
V_24 = 0 ;
if ( V_12 -> V_10 &&
( F_16 ( V_12 -> V_10 ) == V_34 ) )
V_25 = 2 * F_18 ( V_12 -> V_10 -> V_35 ) ;
else
V_25 = 0 ;
V_23 = 0 ;
while ( V_12 -> V_29 > 0 ) {
V_26 = F_19 ( F_10 ( V_12 ) ) + V_36
+ V_24 + V_25 ;
if ( V_12 -> V_13 -> V_15 > V_26 )
V_20 = V_12 -> V_13 -> V_15 - V_26 ;
else
V_20 = 0 ;
if ( V_20 <= V_32 ) {
V_19 = F_20 ( F_10 ( V_12 ) ) ;
if ( V_19 <= 0 )
return V_19 ;
V_26 = V_36 + V_24 + V_25 ;
if ( V_12 -> V_13 -> V_15 > V_26 + V_32 ) {
V_20 = V_12 -> V_13 -> V_15 - V_26 ;
} else {
return - 1 ;
}
}
if ( ( ( unsigned int ) V_12 -> V_29 ) > V_20 )
V_22 = V_20 ;
else
V_22 = V_12 -> V_29 ;
if ( V_22 > V_37 )
V_22 = V_37 ;
if ( type == V_28 ) {
if ( V_12 -> V_27 != 0 ) {
F_15 ( V_12 -> V_27 > V_32 ) ;
V_12 -> V_27 -= V_32 ;
V_12 -> V_29 += V_32 ;
if ( ( ( unsigned int ) V_12 -> V_29 ) > V_20 )
V_22 = V_20 ;
else
V_22 = V_12 -> V_29 ;
}
if ( V_22 > V_37 )
V_22 = V_37 ;
if ( V_22 < V_32 ) {
return - 1 ;
}
F_21 ( V_12 , V_23 ,
V_22 - V_32 ) ;
F_22 ( V_12 ,
( unsigned char * ) & V_12 -> V_38 ->
V_39 [ V_12 -> V_27 ] ) ;
}
V_19 = F_23 ( V_12 , type , & V_12 -> V_38 -> V_39 [ V_12 -> V_27 ] ,
V_22 ) ;
if ( V_19 < 0 ) {
if ( V_21 && F_13 ( F_10 ( V_12 ) ,
V_40 , 0 , NULL ) > 0 ) {
if ( ! ( F_12 ( V_12 ) & V_16 ) ) {
if ( ! F_8 ( V_12 ) )
return - 1 ;
V_21 = 0 ;
} else
return - 1 ;
} else {
return ( - 1 ) ;
}
} else {
F_15 ( V_22 == ( unsigned int ) V_19 ) ;
if ( type == V_28 && ! V_12 -> V_13 -> V_41 ) {
unsigned char * V_42 =
( unsigned char * ) & V_12 -> V_38 -> V_39 [ V_12 -> V_27 ] ;
const struct V_43 * V_44 = & V_12 -> V_13 -> V_30 ;
int V_45 ;
if ( V_23 == 0 && V_12 -> V_46 != V_47 ) {
* V_42 ++ = V_44 -> type ;
F_24 ( V_44 -> V_31 , V_42 ) ;
F_25 ( V_44 -> V_48 , V_42 ) ;
F_24 ( 0 , V_42 ) ;
F_24 ( V_44 -> V_31 , V_42 ) ;
V_42 -= V_32 ;
V_45 = V_19 ;
} else {
V_42 += V_32 ;
V_45 = V_19 - V_32 ;
}
F_26 ( V_12 , V_42 , V_45 ) ;
}
if ( V_19 == V_12 -> V_29 ) {
if ( V_12 -> V_49 )
V_12 -> V_49 ( 1 , V_12 -> V_46 , type , V_12 -> V_38 -> V_39 ,
( V_50 ) ( V_12 -> V_27 + V_12 -> V_29 ) , V_12 ,
V_12 -> V_51 ) ;
V_12 -> V_27 = 0 ;
V_12 -> V_29 = 0 ;
return ( 1 ) ;
}
V_12 -> V_27 += V_19 ;
V_12 -> V_29 -= V_19 ;
V_23 += ( V_19 -= V_32 ) ;
}
}
return ( 0 ) ;
}
long F_27 ( T_2 * V_12 , int V_52 , int V_53 , int V_54 , long V_55 , int * V_56 )
{
int V_57 , V_58 ;
struct V_43 * V_44 ;
unsigned char * V_42 ;
unsigned long V_31 ;
if ( V_12 -> V_59 -> V_60 . V_61 ) {
V_12 -> V_59 -> V_60 . V_61 = 0 ;
if ( ( V_54 >= 0 ) && ( V_12 -> V_59 -> V_60 . V_62 != V_54 ) ) {
V_58 = V_63 ;
F_28 ( V_64 , V_65 ) ;
goto V_66;
}
* V_56 = 1 ;
V_12 -> V_67 = V_12 -> V_38 -> V_39 + V_32 ;
V_12 -> V_29 = ( int ) V_12 -> V_59 -> V_60 . V_68 ;
return V_12 -> V_29 ;
}
V_44 = & V_12 -> V_13 -> V_69 ;
memset ( V_44 , 0x00 , sizeof( struct V_43 ) ) ;
V_70:
V_57 = F_29 ( V_12 , V_52 , V_53 , V_55 , V_56 ) ;
if ( V_57 == V_71 || V_57 == V_72 ) {
goto V_70;
} else if ( V_57 <= 0 && ! * V_56 ) {
return V_57 ;
}
V_42 = ( unsigned char * ) V_12 -> V_38 -> V_39 ;
V_31 = V_44 -> V_31 ;
* ( V_42 ++ ) = V_44 -> type ;
F_24 ( V_31 , V_42 ) ;
F_25 ( V_44 -> V_48 , V_42 ) ;
F_24 ( 0 , V_42 ) ;
F_24 ( V_31 , V_42 ) ;
if ( V_12 -> V_46 != V_47 ) {
V_42 -= V_32 ;
V_31 += V_32 ;
}
F_26 ( V_12 , V_42 , V_31 ) ;
if ( V_12 -> V_49 )
V_12 -> V_49 ( 0 , V_12 -> V_46 , V_28 ,
V_42 , V_31 , V_12 , V_12 -> V_51 ) ;
memset ( V_44 , 0x00 , sizeof( struct V_43 ) ) ;
if ( ! V_12 -> V_13 -> V_73 )
V_12 -> V_13 -> V_74 ++ ;
V_12 -> V_67 = V_12 -> V_38 -> V_39 + V_32 ;
return V_12 -> V_29 ;
V_66:
F_30 ( V_12 , V_75 , V_58 ) ;
* V_56 = 0 ;
return - 1 ;
}
static int F_31 ( T_2 * V_12 , struct V_43 * V_44 ,
int V_55 )
{
V_50 V_23 , V_1 , V_31 ;
V_31 = V_44 -> V_31 ;
V_23 = V_44 -> V_23 ;
V_1 = V_44 -> V_1 ;
if ( ( V_23 + V_1 ) > V_31 ) {
F_28 ( V_76 , V_77 ) ;
return V_78 ;
}
if ( ( V_23 + V_1 ) > ( unsigned long ) V_55 ) {
F_28 ( V_76 , V_77 ) ;
return V_78 ;
}
if ( V_12 -> V_13 -> V_69 . V_23 == 0 ) {
if ( ! F_32
( V_12 -> V_38 , V_31 + V_32 ) ) {
F_28 ( V_76 , V_79 ) ;
return V_80 ;
}
V_12 -> V_59 -> V_60 . V_68 = V_31 ;
V_12 -> V_13 -> V_69 . V_31 = V_31 ;
V_12 -> V_59 -> V_60 . V_62 = V_44 -> type ;
V_12 -> V_13 -> V_69 . type = V_44 -> type ;
V_12 -> V_13 -> V_69 . V_48 = V_44 -> V_48 ;
} else if ( V_31 != V_12 -> V_13 -> V_69 . V_31 ) {
F_28 ( V_76 , V_77 ) ;
return V_78 ;
}
return 0 ;
}
static int F_33 ( T_2 * V_12 , long V_55 , int * V_56 )
{
T_3 * V_81 ;
T_1 * V_3 ;
int V_58 ;
* V_56 = 0 ;
V_81 = F_34 ( V_12 -> V_13 -> V_82 ) ;
if ( V_81 == NULL )
return 0 ;
V_3 = ( T_1 * ) V_81 -> V_39 ;
if ( V_3 -> V_2 != NULL )
return 0 ;
if ( V_12 -> V_13 -> V_74 == V_3 -> V_7 . V_48 ) {
unsigned long V_1 = V_3 -> V_7 . V_1 ;
F_35 ( V_12 -> V_13 -> V_82 ) ;
V_58 = F_31 ( V_12 , & V_3 -> V_7 , V_55 ) ;
if ( V_58 == 0 ) {
unsigned char * V_42 =
( unsigned char * ) V_12 -> V_38 -> V_39 + V_32 ;
memcpy ( & V_42 [ V_3 -> V_7 . V_23 ] , V_3 -> V_6 ,
V_3 -> V_7 . V_1 ) ;
}
F_5 ( V_3 ) ;
F_36 ( V_81 ) ;
if ( V_58 == 0 ) {
* V_56 = 1 ;
return V_1 ;
}
F_30 ( V_12 , V_75 , V_58 ) ;
V_12 -> V_29 = 0 ;
* V_56 = 0 ;
return - 1 ;
} else
return 0 ;
}
static unsigned long F_37 ( const T_2 * V_12 )
{
unsigned long V_83 =
V_32 + V_84 ;
if ( V_83 < ( unsigned long ) V_12 -> V_85 )
return V_12 -> V_85 ;
return V_83 ;
}
static int
F_38 ( T_2 * V_12 , const struct V_43 * V_44 , int * V_56 )
{
T_1 * V_3 = NULL ;
T_3 * V_81 = NULL ;
int V_57 = - 1 , V_86 ;
unsigned char V_87 [ 8 ] ;
unsigned long V_1 = V_44 -> V_1 ;
if ( ( V_44 -> V_23 + V_1 ) > V_44 -> V_31 ||
V_44 -> V_31 > F_37 ( V_12 ) )
goto V_88;
if ( V_1 == 0 )
return V_72 ;
memset ( V_87 , 0 , sizeof( V_87 ) ) ;
V_87 [ 6 ] = ( unsigned char ) ( V_44 -> V_48 >> 8 ) ;
V_87 [ 7 ] = ( unsigned char ) V_44 -> V_48 ;
V_81 = F_39 ( V_12 -> V_13 -> V_82 , V_87 ) ;
if ( V_81 == NULL ) {
V_3 = F_1 ( V_44 -> V_31 , 1 ) ;
if ( V_3 == NULL )
goto V_88;
memcpy ( & ( V_3 -> V_7 ) , V_44 , sizeof( * V_44 ) ) ;
V_3 -> V_7 . V_1 = V_3 -> V_7 . V_31 ;
V_3 -> V_7 . V_23 = 0 ;
} else {
V_3 = ( T_1 * ) V_81 -> V_39 ;
if ( V_3 -> V_7 . V_31 != V_44 -> V_31 ) {
V_81 = NULL ;
V_3 = NULL ;
goto V_88;
}
}
if ( V_3 -> V_2 == NULL ) {
unsigned char V_89 [ 256 ] ;
while ( V_1 ) {
V_57 = V_12 -> V_90 -> V_91 ( V_12 , V_28 ,
V_89 ,
V_1 >
sizeof( V_89 ) ? sizeof( V_89 ) :
V_1 , 0 ) ;
if ( V_57 <= 0 )
goto V_88;
V_1 -= V_57 ;
}
return V_72 ;
}
V_57 = V_12 -> V_90 -> V_91 ( V_12 , V_28 ,
V_3 -> V_6 + V_44 -> V_23 ,
V_1 , 0 ) ;
if ( ( unsigned long ) V_57 != V_1 )
V_57 = - 1 ;
if ( V_57 <= 0 )
goto V_88;
F_40 ( V_3 -> V_2 , ( long ) V_44 -> V_23 ,
( long ) ( V_44 -> V_23 + V_1 ) ) ;
F_41 ( V_3 -> V_2 , ( long ) V_44 -> V_31 ,
V_86 ) ;
if ( V_86 ) {
F_3 ( V_3 -> V_2 ) ;
V_3 -> V_2 = NULL ;
}
if ( V_81 == NULL ) {
V_81 = F_42 ( V_87 , V_3 ) ;
if ( V_81 == NULL ) {
V_57 = - 1 ;
goto V_88;
}
V_81 = F_43 ( V_12 -> V_13 -> V_82 , V_81 ) ;
F_15 ( V_81 != NULL ) ;
}
return V_72 ;
V_88:
if ( V_3 != NULL && V_81 == NULL )
F_5 ( V_3 ) ;
* V_56 = 0 ;
return V_57 ;
}
static int
F_44 ( T_2 * V_12 , const struct V_43 * V_44 ,
int * V_56 )
{
int V_57 = - 1 ;
T_1 * V_3 = NULL ;
T_3 * V_81 = NULL ;
unsigned char V_87 [ 8 ] ;
unsigned long V_1 = V_44 -> V_1 ;
if ( ( V_44 -> V_23 + V_1 ) > V_44 -> V_31 )
goto V_88;
memset ( V_87 , 0 , sizeof( V_87 ) ) ;
V_87 [ 6 ] = ( unsigned char ) ( V_44 -> V_48 >> 8 ) ;
V_87 [ 7 ] = ( unsigned char ) V_44 -> V_48 ;
V_81 = F_39 ( V_12 -> V_13 -> V_82 , V_87 ) ;
if ( V_81 != NULL && V_1 != V_44 -> V_31 )
V_81 = NULL ;
if ( V_44 -> V_48 <= V_12 -> V_13 -> V_74 ||
V_44 -> V_48 > V_12 -> V_13 -> V_74 + 10 || V_81 != NULL ||
( V_12 -> V_13 -> V_74 == 0 && V_44 -> type == V_92 ) )
{
unsigned char V_89 [ 256 ] ;
while ( V_1 ) {
V_57 = V_12 -> V_90 -> V_91 ( V_12 , V_28 ,
V_89 ,
V_1 >
sizeof( V_89 ) ? sizeof( V_89 ) :
V_1 , 0 ) ;
if ( V_57 <= 0 )
goto V_88;
V_1 -= V_57 ;
}
} else {
if ( V_1 != V_44 -> V_31 )
return F_38 ( V_12 , V_44 , V_56 ) ;
if ( V_1 > F_37 ( V_12 ) )
goto V_88;
V_3 = F_1 ( V_1 , 0 ) ;
if ( V_3 == NULL )
goto V_88;
memcpy ( & ( V_3 -> V_7 ) , V_44 , sizeof( * V_44 ) ) ;
if ( V_1 ) {
V_57 = V_12 -> V_90 -> V_91 ( V_12 , V_28 ,
V_3 -> V_6 , V_1 , 0 ) ;
if ( ( unsigned long ) V_57 != V_1 )
V_57 = - 1 ;
if ( V_57 <= 0 )
goto V_88;
}
V_81 = F_42 ( V_87 , V_3 ) ;
if ( V_81 == NULL )
goto V_88;
V_81 = F_43 ( V_12 -> V_13 -> V_82 , V_81 ) ;
F_15 ( V_81 != NULL ) ;
}
return V_72 ;
V_88:
if ( V_3 != NULL && V_81 == NULL )
F_5 ( V_3 ) ;
* V_56 = 0 ;
return V_57 ;
}
static long
F_29 ( T_2 * V_12 , int V_52 , int V_53 , long V_55 , int * V_56 )
{
unsigned char V_93 [ V_32 ] ;
unsigned long V_22 , V_23 , V_1 ;
int V_57 , V_58 ;
struct V_43 V_44 ;
V_94:
if ( ( V_1 = F_33 ( V_12 , V_55 , V_56 ) ) || * V_56 ) {
if ( * V_56 )
V_12 -> V_29 = V_1 ;
return V_1 ;
}
V_57 = V_12 -> V_90 -> V_91 ( V_12 , V_28 , V_93 ,
V_32 , 0 ) ;
if ( V_57 <= 0 ) {
V_12 -> V_95 = V_96 ;
* V_56 = 0 ;
return V_57 ;
}
if ( V_57 != V_32 ) {
V_58 = V_63 ;
F_28 ( V_97 , V_65 ) ;
goto V_66;
}
F_45 ( V_93 , & V_44 ) ;
if ( V_44 . V_48 != V_12 -> V_13 -> V_74
&& ! ( V_12 -> V_13 -> V_73 && V_44 . V_48 == 1 ) )
return F_44 ( V_12 , & V_44 , V_56 ) ;
V_22 = V_44 . V_31 ;
V_23 = V_44 . V_23 ;
V_1 = V_44 . V_1 ;
if ( V_1 && V_1 < V_22 )
return F_38 ( V_12 , & V_44 , V_56 ) ;
if ( ! V_12 -> V_98 && V_12 -> V_13 -> V_69 . V_23 == 0 &&
V_93 [ 0 ] == V_99 ) {
if ( V_93 [ 1 ] == 0 && V_93 [ 2 ] == 0 && V_93 [ 3 ] == 0 ) {
if ( V_12 -> V_49 )
V_12 -> V_49 ( 0 , V_12 -> V_46 , V_28 ,
V_93 , V_32 , V_12 ,
V_12 -> V_51 ) ;
V_12 -> V_29 = 0 ;
goto V_94;
} else {
V_58 = V_63 ;
F_28 ( V_97 ,
V_65 ) ;
goto V_66;
}
}
if ( ( V_58 = F_31 ( V_12 , & V_44 , V_55 ) ) )
goto V_66;
V_12 -> V_100 = V_53 ;
if ( V_1 > 0 ) {
unsigned char * V_42 =
( unsigned char * ) V_12 -> V_38 -> V_39 + V_32 ;
V_57 = V_12 -> V_90 -> V_91 ( V_12 , V_28 ,
& V_42 [ V_23 ] , V_1 , 0 ) ;
if ( V_57 <= 0 ) {
V_12 -> V_95 = V_96 ;
* V_56 = 0 ;
return V_57 ;
}
} else
V_57 = 0 ;
if ( V_57 != ( int ) V_1 ) {
V_58 = V_101 ;
F_28 ( V_97 , V_101 ) ;
goto V_66;
}
* V_56 = 1 ;
V_12 -> V_29 = V_1 ;
return V_1 ;
V_66:
F_30 ( V_12 , V_75 , V_58 ) ;
V_12 -> V_29 = 0 ;
* V_56 = 0 ;
return ( - 1 ) ;
}
int F_46 ( T_2 * V_12 , int V_102 , int V_103 )
{
unsigned char * V_42 ;
if ( V_12 -> V_100 == V_102 ) {
V_42 = ( unsigned char * ) V_12 -> V_38 -> V_39 ;
* V_42 ++ = V_104 ;
V_12 -> V_13 -> V_105 = V_12 -> V_13 -> V_106 ;
V_12 -> V_29 = V_107 ;
if ( V_12 -> V_46 == V_47 ) {
V_12 -> V_13 -> V_106 ++ ;
F_25 ( V_12 -> V_13 -> V_105 , V_42 ) ;
V_12 -> V_29 += 2 ;
}
V_12 -> V_27 = 0 ;
F_47 ( V_12 , V_104 , 0 ,
V_12 -> V_13 -> V_105 , 0 , 0 ) ;
F_48 ( V_12 , 1 ) ;
V_12 -> V_100 = V_103 ;
}
return ( F_14 ( V_12 , V_108 ) ) ;
}
int F_49 ( T_2 * V_12 , int V_109 )
{
if ( V_109 > 0 ) {
fprintf ( V_110 , L_1 , __FILE__ , __LINE__ ) ;
return 1 ;
}
if ( ! F_50 ( V_12 ) ) {
return V_109 ;
}
#ifndef F_51
if ( ! F_52 ( V_12 ) && ! V_12 -> V_111 )
#else
if ( ! F_52 ( V_12 ) )
#endif
{
F_53 ( F_54 ( V_12 ) , V_112 ) ;
return V_109 ;
}
#if 0
item = pqueue_peek(state->rcvd_records);
if (item) {
} else
#endif
#if 0
if (state->timeout.read_timeouts >= DTLS1_TMO_READ_COUNT)
ssl3_send_alert(s, SSL3_AL_WARNING,
DTLS1_AD_MISSING_HANDSHAKE_MESSAGE);
#endif
return F_55 ( V_12 ) ;
}
int F_56 ( unsigned short V_48 , int V_8 )
{
return V_48 * 2 - V_8 ;
}
int F_57 ( T_2 * V_12 )
{
T_4 V_113 = V_12 -> V_13 -> V_114 ;
T_5 V_115 ;
T_3 * V_81 ;
T_1 * V_3 ;
int V_116 = 0 ;
V_115 = F_58 ( V_113 ) ;
for ( V_81 = F_59 ( & V_115 ) ; V_81 != NULL ; V_81 = F_59 ( & V_115 ) ) {
V_3 = ( T_1 * ) V_81 -> V_39 ;
if ( F_60 ( V_12 , ( unsigned short )
F_56
( V_3 -> V_7 . V_48 ,
V_3 -> V_7 . V_8 ) , 0 ,
& V_116 ) <= 0 && V_116 ) {
fprintf ( V_110 , L_2 ) ;
return - 1 ;
}
}
return 1 ;
}
int F_48 ( T_2 * V_12 , int V_8 )
{
T_3 * V_81 ;
T_1 * V_3 ;
unsigned char V_87 [ 8 ] ;
F_15 ( V_12 -> V_27 == 0 ) ;
V_3 = F_1 ( V_12 -> V_29 , 0 ) ;
if ( ! V_3 )
return 0 ;
memcpy ( V_3 -> V_6 , V_12 -> V_38 -> V_39 , V_12 -> V_29 ) ;
if ( V_8 ) {
F_15 ( V_12 -> V_13 -> V_30 . V_31 +
V_107 == ( unsigned int ) V_12 -> V_29 ) ;
} else {
F_15 ( V_12 -> V_13 -> V_30 . V_31 +
V_32 == ( unsigned int ) V_12 -> V_29 ) ;
}
V_3 -> V_7 . V_31 = V_12 -> V_13 -> V_30 . V_31 ;
V_3 -> V_7 . V_48 = V_12 -> V_13 -> V_30 . V_48 ;
V_3 -> V_7 . type = V_12 -> V_13 -> V_30 . type ;
V_3 -> V_7 . V_23 = 0 ;
V_3 -> V_7 . V_1 = V_12 -> V_13 -> V_30 . V_31 ;
V_3 -> V_7 . V_8 = V_8 ;
V_3 -> V_7 . V_9 . V_10 = V_12 -> V_10 ;
V_3 -> V_7 . V_9 . V_11 = V_12 -> V_11 ;
V_3 -> V_7 . V_9 . V_117 = V_12 -> V_117 ;
V_3 -> V_7 . V_9 . V_118 = V_12 -> V_118 ;
V_3 -> V_7 . V_9 . V_119 = V_12 -> V_13 -> V_120 ;
memset ( V_87 , 0 , sizeof( V_87 ) ) ;
V_87 [ 6 ] =
( unsigned
char ) ( F_56 ( V_3 -> V_7 . V_48 ,
V_3 -> V_7 . V_8 ) >> 8 ) ;
V_87 [ 7 ] =
( unsigned
char ) ( F_56 ( V_3 -> V_7 . V_48 ,
V_3 -> V_7 . V_8 ) ) ;
V_81 = F_42 ( V_87 , V_3 ) ;
if ( V_81 == NULL ) {
F_5 ( V_3 ) ;
return 0 ;
}
#if 0
fprintf(stderr, "buffered messge: \ttype = %xx\n", msg_buf->type);
fprintf(stderr, "\t\t\t\t\tlen = %d\n", msg_buf->len);
fprintf(stderr, "\t\t\t\t\tseq_num = %d\n", msg_buf->seq_num);
#endif
F_43 ( V_12 -> V_13 -> V_114 , V_81 ) ;
return 1 ;
}
int
F_60 ( T_2 * V_12 , unsigned short V_48 , unsigned long V_23 ,
int * V_116 )
{
int V_19 ;
T_3 * V_81 ;
T_1 * V_3 ;
unsigned long V_121 ;
unsigned char V_87 [ 8 ] ;
struct V_122 V_123 ;
unsigned char V_124 [ 8 ] ;
memset ( V_87 , 0 , sizeof( V_87 ) ) ;
V_87 [ 6 ] = ( unsigned char ) ( V_48 >> 8 ) ;
V_87 [ 7 ] = ( unsigned char ) V_48 ;
V_81 = F_39 ( V_12 -> V_13 -> V_114 , V_87 ) ;
if ( V_81 == NULL ) {
fprintf ( V_110 , L_3 , V_48 ) ;
* V_116 = 0 ;
return 0 ;
}
* V_116 = 1 ;
V_3 = ( T_1 * ) V_81 -> V_39 ;
if ( V_3 -> V_7 . V_8 )
V_121 = V_107 ;
else
V_121 = V_32 ;
memcpy ( V_12 -> V_38 -> V_39 , V_3 -> V_6 ,
V_3 -> V_7 . V_31 + V_121 ) ;
V_12 -> V_29 = V_3 -> V_7 . V_31 + V_121 ;
F_47 ( V_12 , V_3 -> V_7 . type ,
V_3 -> V_7 . V_31 ,
V_3 -> V_7 . V_48 , 0 ,
V_3 -> V_7 . V_1 ) ;
V_123 . V_10 = V_12 -> V_10 ;
V_123 . V_11 = V_12 -> V_11 ;
V_123 . V_117 = V_12 -> V_117 ;
V_123 . V_118 = V_12 -> V_118 ;
V_123 . V_119 = V_12 -> V_13 -> V_120 ;
V_123 . V_119 = V_12 -> V_13 -> V_120 ;
V_12 -> V_13 -> V_41 = 1 ;
V_12 -> V_10 = V_3 -> V_7 . V_9 . V_10 ;
V_12 -> V_11 = V_3 -> V_7 . V_9 . V_11 ;
V_12 -> V_117 = V_3 -> V_7 . V_9 . V_117 ;
V_12 -> V_118 = V_3 -> V_7 . V_9 . V_118 ;
V_12 -> V_13 -> V_120 = V_3 -> V_7 . V_9 . V_119 ;
if ( V_3 -> V_7 . V_9 . V_119 ==
V_123 . V_119 - 1 ) {
memcpy ( V_124 , V_12 -> V_59 -> V_125 ,
sizeof( V_12 -> V_59 -> V_125 ) ) ;
memcpy ( V_12 -> V_59 -> V_125 , V_12 -> V_13 -> V_126 ,
sizeof( V_12 -> V_59 -> V_125 ) ) ;
}
V_19 = F_14 ( V_12 , V_3 -> V_7 . V_8 ?
V_108 : V_28 ) ;
V_12 -> V_10 = V_123 . V_10 ;
V_12 -> V_11 = V_123 . V_11 ;
V_12 -> V_117 = V_123 . V_117 ;
V_12 -> V_118 = V_123 . V_118 ;
V_12 -> V_13 -> V_120 = V_123 . V_119 ;
if ( V_3 -> V_7 . V_9 . V_119 ==
V_123 . V_119 - 1 ) {
memcpy ( V_12 -> V_13 -> V_126 , V_12 -> V_59 -> V_125 ,
sizeof( V_12 -> V_59 -> V_125 ) ) ;
memcpy ( V_12 -> V_59 -> V_125 , V_124 ,
sizeof( V_12 -> V_59 -> V_125 ) ) ;
}
V_12 -> V_13 -> V_41 = 0 ;
( void ) F_20 ( F_10 ( V_12 ) ) ;
return V_19 ;
}
void F_61 ( T_2 * V_12 )
{
T_3 * V_81 ;
for ( V_81 = F_35 ( V_12 -> V_13 -> V_114 ) ;
V_81 != NULL ; V_81 = F_35 ( V_12 -> V_13 -> V_114 ) ) {
F_5 ( ( T_1 * ) V_81 -> V_39 ) ;
F_36 ( V_81 ) ;
}
}
unsigned char * F_62 ( T_2 * V_12 , unsigned char * V_42 ,
unsigned char V_54 , unsigned long V_22 ,
unsigned long V_23 ,
unsigned long V_1 )
{
if ( V_23 == 0 && ! V_12 -> V_13 -> V_73 ) {
V_12 -> V_13 -> V_105 = V_12 -> V_13 -> V_106 ;
V_12 -> V_13 -> V_106 ++ ;
}
F_47 ( V_12 , V_54 , V_22 , V_12 -> V_13 -> V_105 ,
V_23 , V_1 ) ;
return V_42 += V_32 ;
}
static void
F_47 ( T_2 * V_12 , unsigned char V_54 ,
unsigned long V_22 , unsigned short V_127 ,
unsigned long V_23 , unsigned long V_1 )
{
struct V_43 * V_44 = & V_12 -> V_13 -> V_30 ;
V_44 -> type = V_54 ;
V_44 -> V_31 = V_22 ;
V_44 -> V_48 = V_127 ;
V_44 -> V_23 = V_23 ;
V_44 -> V_1 = V_1 ;
}
static void
F_21 ( T_2 * V_12 , unsigned long V_23 ,
unsigned long V_1 )
{
struct V_43 * V_44 = & V_12 -> V_13 -> V_30 ;
V_44 -> V_23 = V_23 ;
V_44 -> V_1 = V_1 ;
}
static unsigned char * F_22 ( T_2 * V_12 , unsigned char * V_42 )
{
struct V_43 * V_44 = & V_12 -> V_13 -> V_30 ;
* V_42 ++ = V_44 -> type ;
F_24 ( V_44 -> V_31 , V_42 ) ;
F_25 ( V_44 -> V_48 , V_42 ) ;
F_24 ( V_44 -> V_23 , V_42 ) ;
F_24 ( V_44 -> V_1 , V_42 ) ;
return V_42 ;
}
unsigned int F_63 ( void )
{
return ( V_128 [ ( sizeof( V_128 ) /
sizeof( V_128 [ 0 ] ) ) - 1 ] ) ;
}
unsigned int F_11 ( T_2 * V_12 )
{
return F_63 () - F_9 ( F_10 ( V_12 ) ) ;
}
void
F_45 ( unsigned char * V_39 , struct V_43 * V_44 )
{
memset ( V_44 , 0x00 , sizeof( struct V_43 ) ) ;
V_44 -> type = * ( V_39 ++ ) ;
F_64 ( V_39 , V_44 -> V_31 ) ;
F_65 ( V_39 , V_44 -> V_48 ) ;
F_64 ( V_39 , V_44 -> V_23 ) ;
F_64 ( V_39 , V_44 -> V_1 ) ;
}
void F_66 ( unsigned char * V_39 , struct V_129 * V_130 )
{
memset ( V_130 , 0x00 , sizeof( struct V_129 ) ) ;
V_130 -> type = * ( V_39 ++ ) ;
}
int F_67 ( T_2 * V_12 )
{
int V_19 ;
#ifndef F_68
if ( F_69 ( F_10 ( V_12 ) ) &&
! ( V_12 -> V_131 & V_132 ) ) {
V_19 = F_70 ( F_10 ( V_12 ) ) ;
if ( V_19 < 0 )
return - 1 ;
if ( V_19 == 0 )
F_13 ( F_10 ( V_12 ) , V_133 , 1 ,
NULL ) ;
}
#endif
V_19 = F_71 ( V_12 ) ;
#ifndef F_68
F_13 ( F_10 ( V_12 ) , V_133 , 0 , NULL ) ;
#endif
return V_19 ;
}
int F_72 ( T_2 * V_12 )
{
unsigned char * V_42 = & V_12 -> V_59 -> V_134 . V_39 [ 0 ] , * V_135 ;
unsigned short V_136 ;
unsigned int V_137 ;
unsigned int V_138 = 16 ;
if ( V_12 -> V_49 )
V_12 -> V_49 ( 0 , V_12 -> V_46 , V_139 ,
& V_12 -> V_59 -> V_134 . V_39 [ 0 ] , V_12 -> V_59 -> V_134 . V_140 ,
V_12 , V_12 -> V_51 ) ;
if ( 1 + 2 + 16 > V_12 -> V_59 -> V_134 . V_140 )
return 0 ;
if ( V_12 -> V_59 -> V_134 . V_140 > V_141 )
return 0 ;
V_136 = * V_42 ++ ;
F_65 ( V_42 , V_137 ) ;
if ( 1 + 2 + V_137 + 16 > V_12 -> V_59 -> V_134 . V_140 )
return 0 ;
V_135 = V_42 ;
if ( V_136 == V_142 ) {
unsigned char * V_143 , * V_144 ;
unsigned int V_145 = 1 +
2 +
V_137 + V_138 ;
int V_146 ;
if ( V_145 > V_141 )
return 0 ;
V_143 = F_2 ( V_145 ) ;
V_144 = V_143 ;
* V_144 ++ = V_147 ;
F_25 ( V_137 , V_144 ) ;
memcpy ( V_144 , V_135 , V_137 ) ;
V_144 += V_137 ;
F_73 ( V_144 , V_138 ) ;
V_146 = F_23 ( V_12 , V_139 , V_143 , V_145 ) ;
if ( V_146 >= 0 && V_12 -> V_49 )
V_12 -> V_49 ( 1 , V_12 -> V_46 , V_139 ,
V_143 , V_145 , V_12 , V_12 -> V_51 ) ;
F_3 ( V_143 ) ;
if ( V_146 < 0 )
return V_146 ;
} else if ( V_136 == V_147 ) {
unsigned int V_48 ;
F_65 ( V_135 , V_48 ) ;
if ( V_137 == 18 && V_48 == V_12 -> V_148 ) {
F_74 ( V_12 ) ;
V_12 -> V_148 ++ ;
V_12 -> V_111 = 0 ;
}
}
return 0 ;
}
int F_75 ( T_2 * V_12 )
{
unsigned char * V_4 , * V_42 ;
int V_19 ;
unsigned int V_137 = 18 ;
unsigned int V_138 = 16 ;
if ( ! ( V_12 -> V_149 & V_150 ) ||
V_12 -> V_149 & V_151 ) {
F_28 ( V_152 , V_153 ) ;
return - 1 ;
}
if ( V_12 -> V_111 ) {
F_28 ( V_152 , V_154 ) ;
return - 1 ;
}
if ( F_52 ( V_12 ) || V_12 -> V_155 ) {
F_28 ( V_152 , V_65 ) ;
return - 1 ;
}
F_15 ( V_137 + V_138 <= 16381 ) ;
V_4 = F_2 ( 1 + 2 + V_137 + V_138 ) ;
V_42 = V_4 ;
* V_42 ++ = V_142 ;
F_25 ( V_137 , V_42 ) ;
F_25 ( V_12 -> V_148 , V_42 ) ;
F_73 ( V_42 , 16 ) ;
V_42 += 16 ;
F_73 ( V_42 , V_138 ) ;
V_19 = F_23 ( V_12 , V_139 , V_4 , 3 + V_137 + V_138 ) ;
if ( V_19 >= 0 ) {
if ( V_12 -> V_49 )
V_12 -> V_49 ( 1 , V_12 -> V_46 , V_139 ,
V_4 , 3 + V_137 + V_138 ,
V_12 , V_12 -> V_51 ) ;
F_76 ( V_12 ) ;
V_12 -> V_111 = 1 ;
}
F_3 ( V_4 ) ;
return V_19 ;
}
