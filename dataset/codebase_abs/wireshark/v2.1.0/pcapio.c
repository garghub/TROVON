static T_1
F_1 ( T_2 * V_1 , const T_3 * V_2 , T_4 V_3 ,
T_5 * V_4 , int * V_5 )
{
T_4 V_6 ;
V_6 = fwrite ( V_2 , V_3 , 1 , V_1 ) ;
if ( V_6 != 1 ) {
if ( ferror ( V_1 ) ) {
* V_5 = V_7 ;
} else {
* V_5 = 0 ;
}
return FALSE ;
}
( * V_4 ) += V_3 ;
return TRUE ;
}
T_1
F_2 ( T_2 * V_1 , int V_8 , int V_9 , T_1 V_10 , T_5 * V_4 , int * V_5 )
{
struct V_11 V_12 ;
V_12 . V_13 = V_10 ? V_14 : V_15 ;
V_12 . V_16 = 2 ;
V_12 . V_17 = 4 ;
V_12 . V_18 = 0 ;
V_12 . V_19 = 0 ;
V_12 . V_9 = V_9 ;
V_12 . V_20 = V_8 ;
return F_1 ( V_1 , ( const T_3 * ) & V_12 , sizeof( V_12 ) , V_4 , V_5 ) ;
}
T_1
F_3 ( T_2 * V_1 ,
T_6 V_21 , T_7 V_22 ,
T_7 V_23 , T_7 V_24 ,
const T_3 * V_25 ,
T_5 * V_4 , int * V_5 )
{
struct V_26 V_27 ;
V_27 . V_28 = ( T_7 ) V_21 ;
V_27 . V_29 = V_22 ;
V_27 . V_30 = V_23 ;
V_27 . V_31 = V_24 ;
if ( ! F_1 ( V_1 , ( const T_3 * ) & V_27 , sizeof( V_27 ) , V_4 , V_5 ) )
return FALSE ;
return F_1 ( V_1 , V_25 , V_23 , V_4 , V_5 ) ;
}
static T_7
F_4 ( const char * V_32 )
{
if ( ( V_32 != NULL ) && ( strlen ( V_32 ) > 0 ) && ( strlen ( V_32 ) < V_33 ) ) {
return ( T_7 ) ( sizeof( struct V_34 ) +
( V_35 ) F_5 ( strlen ( V_32 ) ) ) ;
}
return 0 ;
}
static T_1
F_6 ( T_2 * V_1 ,
V_35 V_36 , const char * V_32 ,
T_5 * V_4 , int * V_5 )
{
T_4 V_37 ;
struct V_34 V_34 ;
const T_7 V_38 = 0 ;
if ( V_32 == NULL )
return TRUE ;
V_37 = strlen ( V_32 ) ;
if ( ( V_37 > 0 ) && ( V_37 < V_33 ) ) {
V_34 . type = V_36 ;
V_34 . V_39 = ( V_35 ) V_37 ;
if ( ! F_1 ( V_1 , ( const T_3 * ) & V_34 , sizeof( struct V_34 ) , V_4 , V_5 ) )
return FALSE ;
if ( ! F_1 ( V_1 , ( const T_3 * ) V_32 , ( int ) V_37 , V_4 , V_5 ) )
return FALSE ;
if ( V_37 % 4 ) {
if ( ! F_1 ( V_1 , ( const T_3 * ) & V_38 , 4 - V_37 % 4 , V_4 , V_5 ) )
return FALSE ;
}
}
return TRUE ;
}
T_1
F_7 ( T_2 * V_1 ,
const char * V_40 ,
const char * V_41 ,
const char * V_42 ,
const char * V_43 ,
T_5 V_44 ,
T_5 * V_4 ,
int * V_5 )
{
struct V_45 V_45 ;
struct V_34 V_34 ;
T_7 V_46 ;
T_7 V_47 ;
V_46 = sizeof( struct V_45 ) +
sizeof( T_7 ) ;
V_47 = 0 ;
V_47 += F_4 ( V_40 ) ;
V_47 += F_4 ( V_41 ) ;
V_47 += F_4 ( V_42 ) ;
V_47 += F_4 ( V_43 ) ;
if ( V_47 != 0 ) {
V_47 += ( T_7 ) sizeof( struct V_34 ) ;
}
V_46 += V_47 ;
V_45 . V_48 = V_49 ;
V_45 . V_46 = V_46 ;
V_45 . V_50 = V_51 ;
V_45 . V_52 = V_53 ;
V_45 . V_54 = V_55 ;
V_45 . V_44 = V_44 ;
if ( ! F_1 ( V_1 , ( const T_3 * ) & V_45 , sizeof( struct V_45 ) , V_4 , V_5 ) )
return FALSE ;
if ( ! F_6 ( V_1 , V_56 , V_40 ,
V_4 , V_5 ) )
return FALSE ;
if ( ! F_6 ( V_1 , V_57 , V_41 ,
V_4 , V_5 ) )
return FALSE ;
if ( ! F_6 ( V_1 , V_58 , V_42 ,
V_4 , V_5 ) )
return FALSE ;
if ( ! F_6 ( V_1 , V_59 , V_43 ,
V_4 , V_5 ) )
return FALSE ;
if ( V_47 != 0 ) {
V_34 . type = V_60 ;
V_34 . V_39 = 0 ;
if ( ! F_1 ( V_1 , ( const T_3 * ) & V_34 , sizeof( struct V_34 ) , V_4 , V_5 ) )
return FALSE ;
}
return F_1 ( V_1 , ( const T_3 * ) & V_46 , sizeof( T_7 ) , V_4 , V_5 ) ;
}
T_1
F_8 ( T_2 * V_1 ,
const char * V_40 ,
const char * V_61 ,
const char * V_62 ,
const char * V_63 ,
const char * V_42 ,
int V_64 ,
int V_65 ,
T_5 * V_4 ,
T_5 V_66 ,
T_3 V_67 ,
int * V_5 )
{
struct V_68 V_68 ;
struct V_34 V_34 ;
T_7 V_46 ;
T_7 V_47 ;
const T_7 V_38 = 0 ;
V_46 = ( T_7 ) ( sizeof( struct V_68 ) + sizeof( T_7 ) ) ;
V_47 = 0 ;
V_47 += F_4 ( V_40 ) ;
V_47 += F_4 ( V_61 ) ;
V_47 += F_4 ( V_62 ) ;
if ( V_66 != 0 ) {
V_47 += ( T_7 ) ( sizeof( struct V_34 ) +
sizeof( T_5 ) ) ;
}
if ( V_67 != 0 ) {
V_47 += ( T_7 ) ( sizeof( struct V_34 ) +
sizeof( struct V_34 ) ) ;
}
if ( ( V_63 != NULL ) && ( strlen ( V_63 ) > 0 ) && ( strlen ( V_63 ) < V_33 ) ) {
V_47 += ( T_7 ) ( sizeof( struct V_34 ) +
( V_35 ) ( F_5 ( strlen ( V_63 ) + 1 ) ) ) ;
}
V_47 += F_4 ( V_42 ) ;
if ( V_47 != 0 ) {
V_47 += ( T_7 ) sizeof( struct V_34 ) ;
}
V_46 += V_47 ;
V_68 . V_48 = V_69 ;
V_68 . V_46 = V_46 ;
V_68 . V_64 = V_64 ;
V_68 . V_70 = 0 ;
V_68 . V_65 = V_65 ;
if ( ! F_1 ( V_1 , ( const T_3 * ) & V_68 , sizeof( struct V_68 ) , V_4 , V_5 ) )
return FALSE ;
if ( ! F_6 ( V_1 , V_56 , V_40 ,
V_4 , V_5 ) )
return FALSE ;
if ( ! F_6 ( V_1 , V_71 , V_61 ,
V_4 , V_5 ) )
return FALSE ;
if ( ! F_6 ( V_1 , V_72 , V_62 ,
V_4 , V_5 ) )
return FALSE ;
if ( V_66 != 0 ) {
V_34 . type = V_73 ;
V_34 . V_39 = sizeof( T_5 ) ;
if ( ! F_1 ( V_1 , ( const T_3 * ) & V_34 , sizeof( struct V_34 ) , V_4 , V_5 ) )
return FALSE ;
if ( ! F_1 ( V_1 , ( const T_3 * ) & V_66 , sizeof( T_5 ) , V_4 , V_5 ) )
return FALSE ;
}
if ( V_67 != 0 ) {
V_34 . type = V_74 ;
V_34 . V_39 = sizeof( T_3 ) ;
if ( ! F_1 ( V_1 , ( const T_3 * ) & V_34 , sizeof( struct V_34 ) , V_4 , V_5 ) )
return FALSE ;
if ( ! F_1 ( V_1 , ( const T_3 * ) & V_67 , sizeof( T_3 ) , V_4 , V_5 ) )
return FALSE ;
if ( ! F_1 ( V_1 , ( const T_3 * ) & V_38 , 3 , V_4 , V_5 ) )
return FALSE ;
}
if ( ( V_63 != NULL ) && ( strlen ( V_63 ) > 0 ) && ( strlen ( V_63 ) < V_33 - 1 ) ) {
V_34 . type = V_75 ;
V_34 . V_39 = ( V_35 ) ( strlen ( V_63 ) + 1 ) ;
if ( ! F_1 ( V_1 , ( const T_3 * ) & V_34 , sizeof( struct V_34 ) , V_4 , V_5 ) )
return FALSE ;
if ( ! F_1 ( V_1 , ( const T_3 * ) & V_38 , 1 , V_4 , V_5 ) )
return FALSE ;
if ( ! F_1 ( V_1 , ( const T_3 * ) V_63 , ( int ) strlen ( V_63 ) , V_4 , V_5 ) )
return FALSE ;
if ( ( strlen ( V_63 ) + 1 ) % 4 ) {
if ( ! F_1 ( V_1 , ( const T_3 * ) & V_38 , 4 - ( strlen ( V_63 ) + 1 ) % 4 , V_4 , V_5 ) )
return FALSE ;
}
}
if ( ! F_6 ( V_1 , V_76 , V_42 ,
V_4 , V_5 ) )
return FALSE ;
if ( V_47 != 0 ) {
V_34 . type = V_60 ;
V_34 . V_39 = 0 ;
if ( ! F_1 ( V_1 , ( const T_3 * ) & V_34 , sizeof( struct V_34 ) , V_4 , V_5 ) )
return FALSE ;
}
return F_1 ( V_1 , ( const T_3 * ) & V_46 , sizeof( T_7 ) , V_4 , V_5 ) ;
}
T_1
F_9 ( T_2 * V_1 ,
const char * V_40 ,
T_6 V_21 , T_7 V_22 ,
T_7 V_23 , T_7 V_24 ,
T_7 V_77 ,
T_8 V_78 ,
const T_3 * V_25 ,
T_7 V_79 ,
T_5 * V_4 ,
int * V_5 )
{
struct V_80 V_80 ;
struct V_34 V_34 ;
T_7 V_46 ;
T_5 V_81 ;
T_7 V_47 ;
const T_7 V_38 = 0 ;
V_46 = ( T_7 ) ( sizeof( struct V_80 ) +
F_5 ( V_23 ) +
sizeof( T_7 ) ) ;
V_47 = 0 ;
V_47 += F_4 ( V_40 ) ;
if ( V_79 != 0 ) {
V_47 += ( T_7 ) ( sizeof( struct V_34 ) +
sizeof( T_7 ) ) ;
}
if ( V_47 != 0 ) {
V_47 += ( T_7 ) sizeof( struct V_34 ) ;
}
V_46 += V_47 ;
V_81 = ( T_5 ) V_21 * V_78 + ( T_5 ) V_22 ;
V_80 . V_48 = V_82 ;
V_80 . V_46 = V_46 ;
V_80 . V_77 = V_77 ;
V_80 . V_83 = ( T_7 ) ( ( V_81 >> 32 ) & 0xffffffff ) ;
V_80 . V_84 = ( T_7 ) ( V_81 & 0xffffffff ) ;
V_80 . V_85 = V_23 ;
V_80 . V_86 = V_24 ;
if ( ! F_1 ( V_1 , ( const T_3 * ) & V_80 , sizeof( struct V_80 ) , V_4 , V_5 ) )
return FALSE ;
if ( ! F_1 ( V_1 , V_25 , V_23 , V_4 , V_5 ) )
return FALSE ;
if ( V_23 % 4 ) {
if ( ! F_1 ( V_1 , ( const T_3 * ) & V_38 , 4 - V_23 % 4 , V_4 , V_5 ) )
return FALSE ;
}
if ( ! F_6 ( V_1 , V_56 , V_40 ,
V_4 , V_5 ) )
return FALSE ;
if ( V_79 != 0 ) {
V_34 . type = V_87 ;
V_34 . V_39 = sizeof( T_7 ) ;
if ( ! F_1 ( V_1 , ( const T_3 * ) & V_34 , sizeof( struct V_34 ) , V_4 , V_5 ) )
return FALSE ;
if ( ! F_1 ( V_1 , ( const T_3 * ) & V_79 , sizeof( T_7 ) , V_4 , V_5 ) )
return FALSE ;
}
if ( V_47 != 0 ) {
V_34 . type = V_60 ;
V_34 . V_39 = 0 ;
if ( ! F_1 ( V_1 , ( const T_3 * ) & V_34 , sizeof( struct V_34 ) , V_4 , V_5 ) )
return FALSE ;
}
return F_1 ( V_1 , ( const T_3 * ) & V_46 , sizeof( T_7 ) , V_4 , V_5 ) ;
}
T_1
F_10 ( T_2 * V_1 ,
T_7 V_77 ,
T_5 * V_4 ,
const char * V_40 ,
T_5 V_88 ,
T_5 V_89 ,
T_5 V_90 ,
T_5 V_91 ,
int * V_5 )
{
struct V_92 V_92 ;
#ifdef F_11
T_9 V_93 ;
#else
struct V_94 V_93 ;
#endif
struct V_34 V_34 ;
T_7 V_46 ;
T_7 V_47 ;
T_5 V_81 ;
#ifdef F_11
F_12 ( & V_93 ) ;
V_81 = ( ( ( T_5 ) ( T_7 ) V_93 . V_95 ) << 32 ) +
( T_7 ) V_93 . V_96 ;
V_81 /= 10 ;
V_81 -= F_13 ( 11644473600000000 ) ;
#else
F_14 ( & V_93 , NULL ) ;
V_81 = ( T_5 ) ( V_93 . V_97 ) * 1000000 +
( T_5 ) ( V_93 . V_98 ) ;
#endif
V_46 = ( T_7 ) ( sizeof( struct V_92 ) + sizeof( T_7 ) ) ;
V_47 = 0 ;
if ( V_90 != V_99 ) {
V_47 += ( T_7 ) ( sizeof( struct V_34 ) +
sizeof( T_5 ) ) ;
}
if ( V_91 != V_99 ) {
V_47 += ( T_7 ) ( sizeof( struct V_34 ) +
sizeof( T_5 ) ) ;
}
V_47 += F_4 ( V_40 ) ;
if ( V_88 != 0 ) {
V_47 += ( T_7 ) ( sizeof( struct V_34 ) +
sizeof( T_5 ) ) ;
}
if ( V_89 != 0 ) {
V_47 += ( T_7 ) ( sizeof( struct V_34 ) +
sizeof( T_5 ) ) ;
}
if ( V_47 != 0 ) {
V_47 += ( T_7 ) sizeof( struct V_34 ) ;
}
V_46 += V_47 ;
V_92 . V_48 = V_100 ;
V_92 . V_46 = V_46 ;
V_92 . V_77 = V_77 ;
V_92 . V_83 = ( T_7 ) ( ( V_81 >> 32 ) & 0xffffffff ) ;
V_92 . V_84 = ( T_7 ) ( V_81 & 0xffffffff ) ;
if ( ! F_1 ( V_1 , ( const T_3 * ) & V_92 , sizeof( struct V_92 ) , V_4 , V_5 ) )
return FALSE ;
if ( ! F_6 ( V_1 , V_56 , V_40 ,
V_4 , V_5 ) )
return FALSE ;
if ( V_88 != 0 ) {
T_7 V_101 , V_102 ;
V_34 . type = V_103 ;
V_34 . V_39 = sizeof( T_5 ) ;
V_101 = ( T_7 ) ( ( V_88 >> 32 ) & 0xffffffff ) ;
V_102 = ( T_7 ) ( V_88 & 0xffffffff ) ;
if ( ! F_1 ( V_1 , ( const T_3 * ) & V_34 , sizeof( struct V_34 ) , V_4 , V_5 ) )
return FALSE ;
if ( ! F_1 ( V_1 , ( const T_3 * ) & V_101 , sizeof( T_7 ) , V_4 , V_5 ) )
return FALSE ;
if ( ! F_1 ( V_1 , ( const T_3 * ) & V_102 , sizeof( T_7 ) , V_4 , V_5 ) )
return FALSE ;
}
if ( V_89 != 0 ) {
T_7 V_101 , V_102 ;
V_34 . type = V_104 ;
V_34 . V_39 = sizeof( T_5 ) ;
V_101 = ( T_7 ) ( ( V_89 >> 32 ) & 0xffffffff ) ;
V_102 = ( T_7 ) ( V_89 & 0xffffffff ) ;
if ( ! F_1 ( V_1 , ( const T_3 * ) & V_34 , sizeof( struct V_34 ) , V_4 , V_5 ) )
return FALSE ;
if ( ! F_1 ( V_1 , ( const T_3 * ) & V_101 , sizeof( T_7 ) , V_4 , V_5 ) )
return FALSE ;
if ( ! F_1 ( V_1 , ( const T_3 * ) & V_102 , sizeof( T_7 ) , V_4 , V_5 ) )
return FALSE ;
}
if ( V_90 != V_99 ) {
V_34 . type = V_105 ;
V_34 . V_39 = sizeof( T_5 ) ;
if ( ! F_1 ( V_1 , ( const T_3 * ) & V_34 , sizeof( struct V_34 ) , V_4 , V_5 ) )
return FALSE ;
if ( ! F_1 ( V_1 , ( const T_3 * ) & V_90 , sizeof( T_5 ) , V_4 , V_5 ) )
return FALSE ;
}
if ( V_91 != V_99 ) {
V_34 . type = V_106 ;
V_34 . V_39 = sizeof( T_5 ) ;
if ( ! F_1 ( V_1 , ( const T_3 * ) & V_34 , sizeof( struct V_34 ) , V_4 , V_5 ) )
return FALSE ;
if ( ! F_1 ( V_1 , ( const T_3 * ) & V_91 , sizeof( T_5 ) , V_4 , V_5 ) )
return FALSE ;
}
if ( V_47 != 0 ) {
V_34 . type = V_60 ;
V_34 . V_39 = 0 ;
if ( ! F_1 ( V_1 , ( const T_3 * ) & V_34 , sizeof( struct V_34 ) , V_4 , V_5 ) )
return FALSE ;
}
return F_1 ( V_1 , ( const T_3 * ) & V_46 , sizeof( T_7 ) , V_4 , V_5 ) ;
}
