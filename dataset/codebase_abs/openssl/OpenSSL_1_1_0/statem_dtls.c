static T_1 * F_1 ( unsigned long V_1 ,
int V_2 )
{
T_1 * V_3 = NULL ;
unsigned char * V_4 = NULL ;
unsigned char * V_5 = NULL ;
V_3 = F_2 ( sizeof( * V_3 ) ) ;
if ( V_3 == NULL )
return NULL ;
if ( V_1 ) {
V_4 = F_2 ( V_1 ) ;
if ( V_4 == NULL ) {
F_3 ( V_3 ) ;
return NULL ;
}
}
V_3 -> V_6 = V_4 ;
if ( V_2 ) {
V_5 = F_4 ( F_5 ( V_1 ) ) ;
if ( V_5 == NULL ) {
F_3 ( V_4 ) ;
F_3 ( V_3 ) ;
return NULL ;
}
}
V_3 -> V_2 = V_5 ;
return V_3 ;
}
void F_6 ( T_1 * V_3 )
{
if ( ! V_3 )
return;
if ( V_3 -> V_7 . V_8 ) {
F_7 ( V_3 -> V_7 .
V_9 . V_10 ) ;
F_8 ( V_3 -> V_7 . V_9 . V_11 ) ;
}
F_3 ( V_3 -> V_6 ) ;
F_3 ( V_3 -> V_2 ) ;
F_3 ( V_3 ) ;
}
int F_9 ( T_2 * V_12 , int type )
{
int V_13 ;
unsigned int V_14 ;
int V_15 = 1 ;
unsigned int V_16 , V_17 , V_18 , V_19 , V_20 ;
if ( ! F_10 ( V_12 ) )
return - 1 ;
if ( V_12 -> V_21 -> V_22 < F_11 ( V_12 ) )
return - 1 ;
if ( V_12 -> V_23 == 0 && type == V_24 )
F_12 ( V_12 -> V_25 ==
( int ) V_12 -> V_21 -> V_26 . V_27 + V_28 ) ;
if ( V_12 -> V_11 ) {
if ( V_12 -> V_10
&& ( F_13 ( F_14 ( V_12 -> V_10 ) ) &
V_29 ) != 0 )
V_18 = 0 ;
else
V_18 = F_15 ( V_12 -> V_11 ) ;
} else
V_18 = 0 ;
if ( V_12 -> V_10 &&
( F_16 ( V_12 -> V_10 ) == V_30 ) )
V_19 = 2 * F_17 ( V_12 -> V_10 ) ;
else
V_19 = 0 ;
V_17 = 0 ;
V_12 -> V_31 = V_32 ;
while ( V_12 -> V_25 > 0 ) {
if ( type == V_24 && V_12 -> V_23 != 0 ) {
if ( V_17 > 0 ) {
if ( V_12 -> V_23 <= V_28 ) {
return - 1 ;
}
V_12 -> V_23 -= V_28 ;
V_12 -> V_25 += V_28 ;
} else {
V_17 = V_12 -> V_21 -> V_26 . V_17 ;
}
}
V_20 = F_18 ( V_12 -> V_33 ) + V_34
+ V_18 + V_19 ;
if ( V_12 -> V_21 -> V_22 > V_20 )
V_14 = V_12 -> V_21 -> V_22 - V_20 ;
else
V_14 = 0 ;
if ( V_14 <= V_28 ) {
V_13 = F_19 ( V_12 -> V_33 ) ;
if ( V_13 <= 0 ) {
V_12 -> V_31 = V_35 ;
return V_13 ;
}
V_20 = V_34 + V_18 + V_19 ;
if ( V_12 -> V_21 -> V_22 > V_20 + V_28 ) {
V_14 = V_12 -> V_21 -> V_22 - V_20 ;
} else {
return - 1 ;
}
}
if ( ( ( unsigned int ) V_12 -> V_25 ) > V_14 )
V_16 = V_14 ;
else
V_16 = V_12 -> V_25 ;
if ( V_16 > V_36 )
V_16 = V_36 ;
if ( type == V_24 ) {
if ( V_16 < V_28 ) {
return - 1 ;
}
F_20 ( V_12 , V_17 , V_16 - V_28 ) ;
F_21 ( V_12 ,
( unsigned char * ) & V_12 -> V_37 ->
V_38 [ V_12 -> V_23 ] ) ;
}
V_13 = F_22 ( V_12 , type , & V_12 -> V_37 -> V_38 [ V_12 -> V_23 ] , V_16 ) ;
if ( V_13 < 0 ) {
if ( V_15 && F_23 ( F_24 ( V_12 ) ,
V_39 , 0 , NULL ) > 0 ) {
if ( ! ( F_25 ( V_12 ) & V_40 ) ) {
if ( ! F_10 ( V_12 ) )
return - 1 ;
V_15 = 0 ;
} else
return - 1 ;
} else {
return ( - 1 ) ;
}
} else {
F_12 ( V_16 == ( unsigned int ) V_13 ) ;
if ( type == V_24 && ! V_12 -> V_21 -> V_41 ) {
unsigned char * V_42 =
( unsigned char * ) & V_12 -> V_37 -> V_38 [ V_12 -> V_23 ] ;
const struct V_43 * V_44 = & V_12 -> V_21 -> V_26 ;
int V_45 ;
if ( V_17 == 0 && V_12 -> V_46 != V_47 ) {
* V_42 ++ = V_44 -> type ;
F_26 ( V_44 -> V_27 , V_42 ) ;
F_27 ( V_44 -> V_48 , V_42 ) ;
F_26 ( 0 , V_42 ) ;
F_26 ( V_44 -> V_27 , V_42 ) ;
V_42 -= V_28 ;
V_45 = V_13 ;
} else {
V_42 += V_28 ;
V_45 = V_13 - V_28 ;
}
if ( ! F_28 ( V_12 , V_42 , V_45 ) )
return - 1 ;
}
if ( V_13 == V_12 -> V_25 ) {
if ( V_12 -> V_49 )
V_12 -> V_49 ( 1 , V_12 -> V_46 , type , V_12 -> V_37 -> V_38 ,
( V_50 ) ( V_12 -> V_23 + V_12 -> V_25 ) , V_12 ,
V_12 -> V_51 ) ;
V_12 -> V_23 = 0 ;
V_12 -> V_25 = 0 ;
return ( 1 ) ;
}
V_12 -> V_23 += V_13 ;
V_12 -> V_25 -= V_13 ;
V_13 -= V_28 ;
V_17 += V_13 ;
F_20 ( V_12 , V_17 , 0 ) ;
}
}
return ( 0 ) ;
}
int F_29 ( T_2 * V_12 , int * V_52 , unsigned long * V_16 )
{
struct V_43 * V_44 ;
unsigned char * V_42 ;
unsigned long V_27 ;
int V_53 ;
long V_54 ;
V_44 = & V_12 -> V_21 -> V_55 ;
memset ( V_44 , 0 , sizeof( * V_44 ) ) ;
V_56:
V_53 = F_30 ( V_12 , & V_54 ) ;
if ( V_54 == V_57 || V_54 == V_58 ) {
goto V_56;
} else if ( V_54 <= 0 && ! V_53 ) {
return 0 ;
}
* V_52 = V_12 -> V_59 -> V_60 . V_61 ;
V_42 = ( unsigned char * ) V_12 -> V_37 -> V_38 ;
if ( * V_52 == V_62 ) {
if ( V_12 -> V_49 ) {
V_12 -> V_49 ( 0 , V_12 -> V_46 , V_63 ,
V_42 , 1 , V_12 , V_12 -> V_51 ) ;
}
* V_16 = ( unsigned long ) V_54 ;
return 1 ;
}
V_27 = V_44 -> V_27 ;
* ( V_42 ++ ) = V_44 -> type ;
F_26 ( V_27 , V_42 ) ;
F_27 ( V_44 -> V_48 , V_42 ) ;
F_26 ( 0 , V_42 ) ;
F_26 ( V_27 , V_42 ) ;
if ( V_12 -> V_46 != V_47 ) {
V_42 -= V_28 ;
V_27 += V_28 ;
}
if ( ! F_28 ( V_12 , V_42 , V_27 ) )
return 0 ;
if ( V_12 -> V_49 )
V_12 -> V_49 ( 0 , V_12 -> V_46 , V_24 ,
V_42 , V_27 , V_12 , V_12 -> V_51 ) ;
memset ( V_44 , 0 , sizeof( * V_44 ) ) ;
V_12 -> V_21 -> V_64 ++ ;
V_12 -> V_65 = V_12 -> V_37 -> V_38 + V_28 ;
* V_16 = V_12 -> V_25 ;
return 1 ;
}
static int F_31 ( T_2 * V_12 , struct V_43 * V_44 )
{
V_50 V_17 , V_1 , V_27 ;
V_27 = V_44 -> V_27 ;
V_17 = V_44 -> V_17 ;
V_1 = V_44 -> V_1 ;
if ( ( V_17 + V_1 ) > V_27 ) {
F_32 ( V_66 , V_67 ) ;
return V_68 ;
}
if ( V_12 -> V_21 -> V_55 . V_17 == 0 ) {
if ( ! F_33 ( V_12 -> V_37 , V_27 + V_28 ) ) {
F_32 ( V_66 , V_69 ) ;
return V_70 ;
}
V_12 -> V_59 -> V_60 . V_71 = V_27 ;
V_12 -> V_21 -> V_55 . V_27 = V_27 ;
V_12 -> V_59 -> V_60 . V_61 = V_44 -> type ;
V_12 -> V_21 -> V_55 . type = V_44 -> type ;
V_12 -> V_21 -> V_55 . V_48 = V_44 -> V_48 ;
} else if ( V_27 != V_12 -> V_21 -> V_55 . V_27 ) {
F_32 ( V_66 , V_67 ) ;
return V_68 ;
}
return 0 ;
}
static int F_34 ( T_2 * V_12 , int * V_53 )
{
T_3 * V_72 ;
T_1 * V_3 ;
int V_73 ;
* V_53 = 0 ;
do {
V_72 = F_35 ( V_12 -> V_21 -> V_74 ) ;
if ( V_72 == NULL )
return 0 ;
V_3 = ( T_1 * ) V_72 -> V_38 ;
if ( V_3 -> V_7 . V_48 < V_12 -> V_21 -> V_64 ) {
F_36 ( V_12 -> V_21 -> V_74 ) ;
F_6 ( V_3 ) ;
F_37 ( V_72 ) ;
V_72 = NULL ;
V_3 = NULL ;
}
} while ( V_72 == NULL );
if ( V_3 -> V_2 != NULL )
return 0 ;
if ( V_12 -> V_21 -> V_64 == V_3 -> V_7 . V_48 ) {
unsigned long V_1 = V_3 -> V_7 . V_1 ;
F_36 ( V_12 -> V_21 -> V_74 ) ;
V_73 = F_31 ( V_12 , & V_3 -> V_7 ) ;
if ( V_73 == 0 ) {
unsigned char * V_42 =
( unsigned char * ) V_12 -> V_37 -> V_38 + V_28 ;
memcpy ( & V_42 [ V_3 -> V_7 . V_17 ] , V_3 -> V_6 ,
V_3 -> V_7 . V_1 ) ;
}
F_6 ( V_3 ) ;
F_37 ( V_72 ) ;
if ( V_73 == 0 ) {
* V_53 = 1 ;
return V_1 ;
}
F_38 ( V_12 , V_75 , V_73 ) ;
V_12 -> V_25 = 0 ;
* V_53 = 0 ;
return - 1 ;
} else
return 0 ;
}
static unsigned long F_39 ( const T_2 * V_12 )
{
unsigned long V_76 =
V_28 + V_77 ;
if ( V_76 < ( unsigned long ) V_12 -> V_78 )
return V_12 -> V_78 ;
return V_76 ;
}
static int
F_40 ( T_2 * V_12 , const struct V_43 * V_44 , int * V_53 )
{
T_1 * V_3 = NULL ;
T_3 * V_72 = NULL ;
int V_79 = - 1 , V_80 ;
unsigned char V_81 [ 8 ] ;
unsigned long V_1 = V_44 -> V_1 ;
if ( ( V_44 -> V_17 + V_1 ) > V_44 -> V_27 ||
V_44 -> V_27 > F_39 ( V_12 ) )
goto V_82;
if ( V_1 == 0 )
return V_58 ;
memset ( V_81 , 0 , sizeof( V_81 ) ) ;
V_81 [ 6 ] = ( unsigned char ) ( V_44 -> V_48 >> 8 ) ;
V_81 [ 7 ] = ( unsigned char ) V_44 -> V_48 ;
V_72 = F_41 ( V_12 -> V_21 -> V_74 , V_81 ) ;
if ( V_72 == NULL ) {
V_3 = F_1 ( V_44 -> V_27 , 1 ) ;
if ( V_3 == NULL )
goto V_82;
memcpy ( & ( V_3 -> V_7 ) , V_44 , sizeof( * V_44 ) ) ;
V_3 -> V_7 . V_1 = V_3 -> V_7 . V_27 ;
V_3 -> V_7 . V_17 = 0 ;
} else {
V_3 = ( T_1 * ) V_72 -> V_38 ;
if ( V_3 -> V_7 . V_27 != V_44 -> V_27 ) {
V_72 = NULL ;
V_3 = NULL ;
goto V_82;
}
}
if ( V_3 -> V_2 == NULL ) {
unsigned char V_83 [ 256 ] ;
while ( V_1 ) {
V_79 = V_12 -> V_84 -> V_85 ( V_12 , V_24 , NULL ,
V_83 ,
V_1 >
sizeof( V_83 ) ? sizeof( V_83 ) :
V_1 , 0 ) ;
if ( V_79 <= 0 )
goto V_82;
V_1 -= V_79 ;
}
return V_58 ;
}
V_79 = V_12 -> V_84 -> V_85 ( V_12 , V_24 , NULL ,
V_3 -> V_6 + V_44 -> V_17 ,
V_1 , 0 ) ;
if ( ( unsigned long ) V_79 != V_1 )
V_79 = - 1 ;
if ( V_79 <= 0 )
goto V_82;
F_42 ( V_3 -> V_2 , ( long ) V_44 -> V_17 ,
( long ) ( V_44 -> V_17 + V_1 ) ) ;
F_43 ( V_3 -> V_2 , ( long ) V_44 -> V_27 ,
V_80 ) ;
if ( V_80 ) {
F_3 ( V_3 -> V_2 ) ;
V_3 -> V_2 = NULL ;
}
if ( V_72 == NULL ) {
V_72 = F_44 ( V_81 , V_3 ) ;
if ( V_72 == NULL ) {
V_79 = - 1 ;
goto V_82;
}
V_72 = F_45 ( V_12 -> V_21 -> V_74 , V_72 ) ;
F_12 ( V_72 != NULL ) ;
}
return V_58 ;
V_82:
if ( V_72 == NULL )
F_6 ( V_3 ) ;
* V_53 = 0 ;
return V_79 ;
}
static int
F_46 ( T_2 * V_12 , const struct V_43 * V_44 ,
int * V_53 )
{
int V_79 = - 1 ;
T_1 * V_3 = NULL ;
T_3 * V_72 = NULL ;
unsigned char V_81 [ 8 ] ;
unsigned long V_1 = V_44 -> V_1 ;
if ( ( V_44 -> V_17 + V_1 ) > V_44 -> V_27 )
goto V_82;
memset ( V_81 , 0 , sizeof( V_81 ) ) ;
V_81 [ 6 ] = ( unsigned char ) ( V_44 -> V_48 >> 8 ) ;
V_81 [ 7 ] = ( unsigned char ) V_44 -> V_48 ;
V_72 = F_41 ( V_12 -> V_21 -> V_74 , V_81 ) ;
if ( V_72 != NULL && V_1 != V_44 -> V_27 )
V_72 = NULL ;
if ( V_44 -> V_48 <= V_12 -> V_21 -> V_64 ||
V_44 -> V_48 > V_12 -> V_21 -> V_64 + 10 || V_72 != NULL ||
( V_12 -> V_21 -> V_64 == 0 && V_44 -> type == V_86 ) ) {
unsigned char V_83 [ 256 ] ;
while ( V_1 ) {
V_79 = V_12 -> V_84 -> V_85 ( V_12 , V_24 , NULL ,
V_83 ,
V_1 >
sizeof( V_83 ) ? sizeof( V_83 ) :
V_1 , 0 ) ;
if ( V_79 <= 0 )
goto V_82;
V_1 -= V_79 ;
}
} else {
if ( V_1 != V_44 -> V_27 )
return F_40 ( V_12 , V_44 , V_53 ) ;
if ( V_1 > F_39 ( V_12 ) )
goto V_82;
V_3 = F_1 ( V_1 , 0 ) ;
if ( V_3 == NULL )
goto V_82;
memcpy ( & ( V_3 -> V_7 ) , V_44 , sizeof( * V_44 ) ) ;
if ( V_1 ) {
V_79 = V_12 -> V_84 -> V_85 ( V_12 , V_24 , NULL ,
V_3 -> V_6 , V_1 , 0 ) ;
if ( ( unsigned long ) V_79 != V_1 )
V_79 = - 1 ;
if ( V_79 <= 0 )
goto V_82;
}
V_72 = F_44 ( V_81 , V_3 ) ;
if ( V_72 == NULL )
goto V_82;
V_72 = F_45 ( V_12 -> V_21 -> V_74 , V_72 ) ;
F_12 ( V_72 != NULL ) ;
}
return V_58 ;
V_82:
if ( V_72 == NULL )
F_6 ( V_3 ) ;
* V_53 = 0 ;
return V_79 ;
}
static int F_30 ( T_2 * V_12 , long * V_16 )
{
unsigned char V_87 [ V_28 ] ;
unsigned long V_88 , V_17 , V_1 ;
int V_79 , V_73 , V_89 ;
struct V_43 V_44 ;
int V_53 ;
V_90:
if ( ( V_1 = F_34 ( V_12 , & V_53 ) ) || V_53 ) {
if ( V_53 )
V_12 -> V_25 = V_1 ;
* V_16 = V_1 ;
return V_53 ;
}
V_79 = V_12 -> V_84 -> V_85 ( V_12 , V_24 , & V_89 , V_87 ,
V_28 , 0 ) ;
if ( V_79 <= 0 ) {
V_12 -> V_31 = V_91 ;
* V_16 = V_79 ;
return 0 ;
}
if ( V_89 == V_63 ) {
if ( V_87 [ 0 ] != V_92 ) {
V_73 = V_93 ;
F_32 ( V_94 ,
V_95 ) ;
goto V_96;
}
memcpy ( V_12 -> V_37 -> V_38 , V_87 , V_79 ) ;
V_12 -> V_25 = V_79 - 1 ;
V_12 -> V_65 = V_12 -> V_37 -> V_38 + 1 ;
V_12 -> V_59 -> V_60 . V_61 = V_62 ;
V_12 -> V_59 -> V_60 . V_71 = V_79 - 1 ;
* V_16 = V_79 - 1 ;
return 1 ;
}
if ( V_79 != V_28 ) {
V_73 = V_93 ;
F_32 ( V_94 , V_97 ) ;
goto V_96;
}
F_47 ( V_87 , & V_44 ) ;
V_88 = V_44 . V_27 ;
V_17 = V_44 . V_17 ;
V_1 = V_44 . V_1 ;
if ( V_1 > F_48 ( & V_12 -> V_98 ) ) {
V_73 = V_99 ;
F_32 ( V_94 , V_100 ) ;
goto V_96;
}
if ( V_44 . V_48 != V_12 -> V_21 -> V_64 ) {
* V_16 = F_46 ( V_12 , & V_44 , & V_53 ) ;
return V_53 ;
}
if ( V_1 && V_1 < V_88 ) {
* V_16 = F_40 ( V_12 , & V_44 , & V_53 ) ;
return V_53 ;
}
if ( ! V_12 -> V_101 && V_12 -> V_21 -> V_55 . V_17 == 0 &&
V_87 [ 0 ] == V_102 ) {
if ( V_87 [ 1 ] == 0 && V_87 [ 2 ] == 0 && V_87 [ 3 ] == 0 ) {
if ( V_12 -> V_49 )
V_12 -> V_49 ( 0 , V_12 -> V_46 , V_24 ,
V_87 , V_28 , V_12 ,
V_12 -> V_51 ) ;
V_12 -> V_25 = 0 ;
goto V_90;
} else {
V_73 = V_93 ;
F_32 ( V_94 ,
V_97 ) ;
goto V_96;
}
}
if ( ( V_73 = F_31 ( V_12 , & V_44 ) ) )
goto V_96;
if ( V_1 > 0 ) {
unsigned char * V_42 =
( unsigned char * ) V_12 -> V_37 -> V_38 + V_28 ;
V_79 = V_12 -> V_84 -> V_85 ( V_12 , V_24 , NULL ,
& V_42 [ V_17 ] , V_1 , 0 ) ;
if ( V_79 <= 0 ) {
V_12 -> V_31 = V_91 ;
* V_16 = V_79 ;
return 0 ;
}
} else
V_79 = 0 ;
if ( V_79 != ( int ) V_1 ) {
V_73 = V_99 ;
F_32 ( V_94 , V_99 ) ;
goto V_96;
}
* V_16 = V_12 -> V_25 = V_1 ;
return 1 ;
V_96:
F_38 ( V_12 , V_75 , V_73 ) ;
V_12 -> V_25 = 0 ;
* V_16 = - 1 ;
return 0 ;
}
int F_49 ( T_2 * V_12 )
{
unsigned char * V_42 ;
V_42 = ( unsigned char * ) V_12 -> V_37 -> V_38 ;
* V_42 ++ = V_92 ;
V_12 -> V_21 -> V_103 = V_12 -> V_21 -> V_104 ;
V_12 -> V_25 = V_105 ;
if ( V_12 -> V_46 == V_47 ) {
V_12 -> V_21 -> V_104 ++ ;
F_27 ( V_12 -> V_21 -> V_103 , V_42 ) ;
V_12 -> V_25 += 2 ;
}
V_12 -> V_23 = 0 ;
F_50 ( V_12 , V_92 , 0 ,
V_12 -> V_21 -> V_103 , 0 , 0 ) ;
if ( ! F_51 ( V_12 , 1 ) ) {
F_32 ( V_106 , V_107 ) ;
return 0 ;
}
return 1 ;
}
T_4 F_52 ( T_2 * V_12 )
{
int V_13 ;
V_13 = F_53 ( F_24 ( V_12 ) ) ;
if ( V_13 < 0 )
return V_108 ;
if ( V_13 == 0 ) {
V_12 -> V_59 -> V_109 = 2 ;
V_12 -> V_31 = V_91 ;
F_54 ( F_55 ( V_12 ) ) ;
F_56 ( F_55 ( V_12 ) ) ;
return V_110 ;
}
return V_111 ;
}
int F_57 ( T_2 * V_12 , int V_112 )
{
if ( V_112 > 0 ) {
F_32 ( V_113 , V_107 ) ;
return 1 ;
}
if ( ! F_58 ( V_12 ) ) {
return V_112 ;
}
#ifndef F_59
if ( ! F_60 ( V_12 ) && ! V_12 -> V_114 )
#else
if ( ! F_60 ( V_12 ) )
#endif
{
F_61 ( F_55 ( V_12 ) , V_115 ) ;
return V_112 ;
}
return F_62 ( V_12 ) ;
}
int F_63 ( unsigned short V_48 , int V_8 )
{
return V_48 * 2 - V_8 ;
}
int F_64 ( T_2 * V_12 )
{
T_5 * V_116 = V_12 -> V_21 -> V_117 ;
T_6 V_118 ;
T_3 * V_72 ;
T_1 * V_3 ;
int V_119 = 0 ;
V_118 = F_65 ( V_116 ) ;
for ( V_72 = F_66 ( & V_118 ) ; V_72 != NULL ; V_72 = F_66 ( & V_118 ) ) {
V_3 = ( T_1 * ) V_72 -> V_38 ;
if ( F_67 ( V_12 , ( unsigned short )
F_63
( V_3 -> V_7 . V_48 ,
V_3 -> V_7 . V_8 ) , & V_119 ) <= 0 )
return - 1 ;
}
return 1 ;
}
int F_51 ( T_2 * V_12 , int V_8 )
{
T_3 * V_72 ;
T_1 * V_3 ;
unsigned char V_81 [ 8 ] ;
F_12 ( V_12 -> V_23 == 0 ) ;
V_3 = F_1 ( V_12 -> V_25 , 0 ) ;
if ( V_3 == NULL )
return 0 ;
memcpy ( V_3 -> V_6 , V_12 -> V_37 -> V_38 , V_12 -> V_25 ) ;
if ( V_8 ) {
F_12 ( V_12 -> V_21 -> V_26 . V_27 +
( ( V_12 -> V_46 ==
V_47 ) ? 3 : V_105 )
== ( unsigned int ) V_12 -> V_25 ) ;
} else {
F_12 ( V_12 -> V_21 -> V_26 . V_27 +
V_28 == ( unsigned int ) V_12 -> V_25 ) ;
}
V_3 -> V_7 . V_27 = V_12 -> V_21 -> V_26 . V_27 ;
V_3 -> V_7 . V_48 = V_12 -> V_21 -> V_26 . V_48 ;
V_3 -> V_7 . type = V_12 -> V_21 -> V_26 . type ;
V_3 -> V_7 . V_17 = 0 ;
V_3 -> V_7 . V_1 = V_12 -> V_21 -> V_26 . V_27 ;
V_3 -> V_7 . V_8 = V_8 ;
V_3 -> V_7 . V_9 . V_10 = V_12 -> V_10 ;
V_3 -> V_7 . V_9 . V_11 = V_12 -> V_11 ;
V_3 -> V_7 . V_9 . V_120 = V_12 -> V_120 ;
V_3 -> V_7 . V_9 . V_121 = V_12 -> V_121 ;
V_3 -> V_7 . V_9 . V_122 =
F_68 ( & V_12 -> V_98 ) ;
memset ( V_81 , 0 , sizeof( V_81 ) ) ;
V_81 [ 6 ] =
( unsigned
char ) ( F_63 ( V_3 -> V_7 . V_48 ,
V_3 -> V_7 . V_8 ) >> 8 ) ;
V_81 [ 7 ] =
( unsigned
char ) ( F_63 ( V_3 -> V_7 . V_48 ,
V_3 -> V_7 . V_8 ) ) ;
V_72 = F_44 ( V_81 , V_3 ) ;
if ( V_72 == NULL ) {
F_6 ( V_3 ) ;
return 0 ;
}
F_45 ( V_12 -> V_21 -> V_117 , V_72 ) ;
return 1 ;
}
int F_67 ( T_2 * V_12 , unsigned short V_48 , int * V_119 )
{
int V_13 ;
T_3 * V_72 ;
T_1 * V_3 ;
unsigned long V_123 ;
unsigned char V_81 [ 8 ] ;
struct V_124 V_125 ;
memset ( V_81 , 0 , sizeof( V_81 ) ) ;
V_81 [ 6 ] = ( unsigned char ) ( V_48 >> 8 ) ;
V_81 [ 7 ] = ( unsigned char ) V_48 ;
V_72 = F_41 ( V_12 -> V_21 -> V_117 , V_81 ) ;
if ( V_72 == NULL ) {
F_32 ( V_126 , V_107 ) ;
* V_119 = 0 ;
return 0 ;
}
* V_119 = 1 ;
V_3 = ( T_1 * ) V_72 -> V_38 ;
if ( V_3 -> V_7 . V_8 )
V_123 = V_105 ;
else
V_123 = V_28 ;
memcpy ( V_12 -> V_37 -> V_38 , V_3 -> V_6 ,
V_3 -> V_7 . V_27 + V_123 ) ;
V_12 -> V_25 = V_3 -> V_7 . V_27 + V_123 ;
F_50 ( V_12 , V_3 -> V_7 . type ,
V_3 -> V_7 . V_27 ,
V_3 -> V_7 . V_48 , 0 ,
V_3 -> V_7 . V_1 ) ;
V_125 . V_10 = V_12 -> V_10 ;
V_125 . V_11 = V_12 -> V_11 ;
V_125 . V_120 = V_12 -> V_120 ;
V_125 . V_121 = V_12 -> V_121 ;
V_125 . V_122 = F_68 ( & V_12 -> V_98 ) ;
V_12 -> V_21 -> V_41 = 1 ;
V_12 -> V_10 = V_3 -> V_7 . V_9 . V_10 ;
V_12 -> V_11 = V_3 -> V_7 . V_9 . V_11 ;
V_12 -> V_120 = V_3 -> V_7 . V_9 . V_120 ;
V_12 -> V_121 = V_3 -> V_7 . V_9 . V_121 ;
F_69 ( & V_12 -> V_98 ,
V_3 -> V_7 .
V_9 . V_122 ) ;
V_13 = F_9 ( V_12 , V_3 -> V_7 . V_8 ?
V_63 : V_24 ) ;
V_12 -> V_10 = V_125 . V_10 ;
V_12 -> V_11 = V_125 . V_11 ;
V_12 -> V_120 = V_125 . V_120 ;
V_12 -> V_121 = V_125 . V_121 ;
F_69 ( & V_12 -> V_98 , V_125 . V_122 ) ;
V_12 -> V_21 -> V_41 = 0 ;
( void ) F_19 ( V_12 -> V_33 ) ;
return V_13 ;
}
void F_70 ( T_2 * V_12 ,
unsigned char V_52 , unsigned long V_16 ,
unsigned long V_17 , unsigned long V_1 )
{
if ( V_17 == 0 ) {
V_12 -> V_21 -> V_103 = V_12 -> V_21 -> V_104 ;
V_12 -> V_21 -> V_104 ++ ;
}
F_50 ( V_12 , V_52 , V_16 , V_12 -> V_21 -> V_103 ,
V_17 , V_1 ) ;
}
static void
F_50 ( T_2 * V_12 , unsigned char V_52 ,
unsigned long V_16 , unsigned short V_127 ,
unsigned long V_17 , unsigned long V_1 )
{
struct V_43 * V_44 = & V_12 -> V_21 -> V_26 ;
V_44 -> type = V_52 ;
V_44 -> V_27 = V_16 ;
V_44 -> V_48 = V_127 ;
V_44 -> V_17 = V_17 ;
V_44 -> V_1 = V_1 ;
}
static void
F_20 ( T_2 * V_12 , unsigned long V_17 , unsigned long V_1 )
{
struct V_43 * V_44 = & V_12 -> V_21 -> V_26 ;
V_44 -> V_17 = V_17 ;
V_44 -> V_1 = V_1 ;
}
static unsigned char * F_21 ( T_2 * V_12 , unsigned char * V_42 )
{
struct V_43 * V_44 = & V_12 -> V_21 -> V_26 ;
* V_42 ++ = V_44 -> type ;
F_26 ( V_44 -> V_27 , V_42 ) ;
F_27 ( V_44 -> V_48 , V_42 ) ;
F_26 ( V_44 -> V_17 , V_42 ) ;
F_26 ( V_44 -> V_1 , V_42 ) ;
return V_42 ;
}
void F_47 ( unsigned char * V_38 , struct V_43 * V_44 )
{
memset ( V_44 , 0 , sizeof( * V_44 ) ) ;
V_44 -> type = * ( V_38 ++ ) ;
F_71 ( V_38 , V_44 -> V_27 ) ;
F_72 ( V_38 , V_44 -> V_48 ) ;
F_71 ( V_38 , V_44 -> V_17 ) ;
F_71 ( V_38 , V_44 -> V_1 ) ;
}
