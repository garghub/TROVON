T_1 F_1 ( void * V_1 ,
const T_2 * V_2 ,
long V_3 ,
T_3 * V_4 ,
int * V_5 )
{
T_4 V_6 ;
T_5 * V_7 = ( T_5 * ) V_1 ;
V_6 = fwrite ( V_2 , V_3 , 1 , V_7 ) ;
if ( V_6 != 1 ) {
if ( ferror ( V_7 ) ) {
* V_5 = V_8 ;
} else {
* V_5 = 0 ;
}
return FALSE ;
}
( * V_4 ) += V_3 ;
return TRUE ;
}
T_1
F_2 ( T_6 V_9 , void * V_1 , int V_10 , int V_11 , T_1 V_12 , T_3 * V_4 , int * V_5 )
{
struct V_13 V_14 ;
V_14 . V_15 = V_12 ? V_16 : V_17 ;
V_14 . V_18 = 2 ;
V_14 . V_19 = 4 ;
V_14 . V_20 = 0 ;
V_14 . V_21 = 0 ;
V_14 . V_11 = V_11 ;
V_14 . V_22 = V_10 ;
return V_9 ( V_1 , ( const T_2 * ) & V_14 , sizeof( V_14 ) , V_4 , V_5 ) ;
}
T_1
F_3 ( T_6 V_9 , void * V_1 ,
T_7 V_23 , T_8 V_24 ,
T_8 V_25 , T_8 V_26 ,
const T_2 * V_27 ,
T_3 * V_4 , int * V_5 )
{
struct V_28 V_29 ;
V_29 . V_30 = ( T_8 ) V_23 ;
V_29 . V_31 = V_24 ;
V_29 . V_32 = V_25 ;
V_29 . V_33 = V_26 ;
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_29 , sizeof( V_29 ) , V_4 , V_5 ) )
return FALSE ;
return V_9 ( V_1 , V_27 , V_25 , V_4 , V_5 ) ;
}
T_1
F_4 ( T_6 V_9 , void * V_1 ,
const char * V_34 ,
const char * V_35 ,
const char * V_36 ,
const char * V_37 ,
T_3 V_38 ,
T_3 * V_4 ,
int * V_5 )
{
struct V_39 V_39 ;
struct V_40 V_40 ;
T_8 V_41 ;
const T_8 V_42 = 0 ;
T_1 V_43 = FALSE ;
V_41 = sizeof( struct V_39 ) +
sizeof( T_8 ) ;
if ( ( V_34 != NULL ) && ( strlen ( V_34 ) > 0 ) && ( strlen ( V_34 ) < V_44 ) ) {
V_41 += ( T_8 ) ( sizeof( struct V_40 ) +
( V_45 ) F_5 ( strlen ( V_34 ) ) ) ;
V_43 = TRUE ;
}
if ( ( V_35 != NULL ) && ( strlen ( V_35 ) > 0 ) && ( strlen ( V_35 ) < V_44 ) ) {
V_41 += ( T_8 ) ( sizeof( struct V_40 ) +
( V_45 ) F_5 ( strlen ( V_35 ) ) ) ;
V_43 = TRUE ;
}
if ( ( V_36 != NULL ) && ( strlen ( V_36 ) > 0 ) && ( strlen ( V_36 ) < V_44 ) ) {
V_41 += ( T_8 ) ( sizeof( struct V_40 ) +
( V_45 ) F_5 ( strlen ( V_36 ) ) ) ;
V_43 = TRUE ;
}
if ( ( V_37 != NULL ) && ( strlen ( V_37 ) > 0 ) && ( strlen ( V_37 ) < V_44 ) ) {
V_41 += ( T_8 ) ( sizeof( struct V_40 ) +
( V_45 ) F_5 ( strlen ( V_37 ) ) ) ;
V_43 = TRUE ;
}
if ( V_43 ) {
V_41 += ( T_8 ) sizeof( struct V_40 ) ;
}
V_39 . V_46 = V_47 ;
V_39 . V_41 = V_41 ;
V_39 . V_48 = V_49 ;
V_39 . V_50 = V_51 ;
V_39 . V_52 = V_53 ;
V_39 . V_38 = V_38 ;
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_39 , sizeof( struct V_39 ) , V_4 , V_5 ) )
return FALSE ;
if ( ( V_34 != NULL ) && ( strlen ( V_34 ) > 0 ) && ( strlen ( V_34 ) < V_44 ) ) {
V_40 . type = V_54 ;
V_40 . V_55 = ( V_45 ) strlen ( V_34 ) ;
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_40 , sizeof( struct V_40 ) , V_4 , V_5 ) )
return FALSE ;
if ( ! V_9 ( V_1 , ( const T_2 * ) V_34 , ( int ) strlen ( V_34 ) , V_4 , V_5 ) )
return FALSE ;
if ( strlen ( V_34 ) % 4 ) {
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_42 , 4 - strlen ( V_34 ) % 4 , V_4 , V_5 ) )
return FALSE ;
}
}
if ( ( V_35 != NULL ) && ( strlen ( V_35 ) > 0 ) && ( strlen ( V_35 ) < V_44 ) ) {
V_40 . type = V_56 ;
V_40 . V_55 = ( V_45 ) strlen ( V_35 ) ;
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_40 , sizeof( struct V_40 ) , V_4 , V_5 ) )
return FALSE ;
if ( ! V_9 ( V_1 , ( const T_2 * ) V_35 , ( int ) strlen ( V_35 ) , V_4 , V_5 ) )
return FALSE ;
if ( ( strlen ( V_35 ) + 1 ) % 4 ) {
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_42 , 4 - strlen ( V_35 ) % 4 , V_4 , V_5 ) )
return FALSE ;
}
}
if ( ( V_36 != NULL ) && ( strlen ( V_36 ) > 0 ) && ( strlen ( V_36 ) < V_44 ) ) {
V_40 . type = V_57 ;
V_40 . V_55 = ( V_45 ) strlen ( V_36 ) ;
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_40 , sizeof( struct V_40 ) , V_4 , V_5 ) )
return FALSE ;
if ( ! V_9 ( V_1 , ( const T_2 * ) V_36 , ( int ) strlen ( V_36 ) , V_4 , V_5 ) )
return FALSE ;
if ( strlen ( V_36 ) % 4 ) {
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_42 , 4 - strlen ( V_36 ) % 4 , V_4 , V_5 ) )
return FALSE ;
}
}
if ( ( V_37 != NULL ) && ( strlen ( V_37 ) > 0 ) && ( strlen ( V_37 ) < V_44 ) ) {
V_40 . type = V_58 ;
V_40 . V_55 = ( V_45 ) strlen ( V_37 ) ;
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_40 , sizeof( struct V_40 ) , V_4 , V_5 ) )
return FALSE ;
if ( ! V_9 ( V_1 , ( const T_2 * ) V_37 , ( int ) strlen ( V_37 ) , V_4 , V_5 ) )
return FALSE ;
if ( strlen ( V_37 ) % 4 ) {
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_42 , 4 - strlen ( V_37 ) % 4 , V_4 , V_5 ) )
return FALSE ;
}
}
if ( V_43 ) {
V_40 . type = V_59 ;
V_40 . V_55 = 0 ;
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_40 , sizeof( struct V_40 ) , V_4 , V_5 ) )
return FALSE ;
}
return V_9 ( V_1 , ( const T_2 * ) & V_41 , sizeof( T_8 ) , V_4 , V_5 ) ;
}
T_1
F_6 ( T_6 V_9 , void * V_1 ,
const char * V_34 ,
const char * V_60 ,
const char * V_61 ,
const char * V_62 ,
const char * V_36 ,
int V_63 ,
int V_64 ,
T_3 * V_4 ,
T_3 V_65 ,
T_2 V_66 ,
int * V_5 )
{
struct V_67 V_67 ;
struct V_40 V_40 ;
T_8 V_41 ;
const T_8 V_42 = 0 ;
T_1 V_43 = FALSE ;
V_41 = ( T_8 ) ( sizeof( struct V_67 ) + sizeof( T_8 ) ) ;
if ( ( V_34 != NULL ) && ( strlen ( V_34 ) > 0 ) && ( strlen ( V_34 ) < V_44 ) ) {
V_41 += ( T_8 ) ( sizeof( struct V_40 ) +
( V_45 ) F_5 ( strlen ( V_34 ) ) ) ;
V_43 = TRUE ;
}
if ( ( V_60 != NULL ) && ( strlen ( V_60 ) > 0 ) && ( strlen ( V_60 ) < V_44 ) ) {
V_41 += ( T_8 ) ( sizeof( struct V_40 ) +
( V_45 ) F_5 ( strlen ( V_60 ) ) ) ;
V_43 = TRUE ;
}
if ( ( V_61 != NULL ) && ( strlen ( V_61 ) > 0 ) && ( strlen ( V_61 ) < V_44 ) ) {
V_41 += ( T_8 ) ( sizeof( struct V_40 ) +
( V_45 ) F_5 ( strlen ( V_61 ) ) ) ;
V_43 = TRUE ;
}
if ( V_65 != 0 ) {
V_41 += ( T_8 ) ( sizeof( struct V_40 ) +
sizeof( T_3 ) ) ;
V_43 = TRUE ;
}
if ( V_66 != 0 ) {
V_41 += ( T_8 ) ( sizeof( struct V_40 ) +
sizeof( struct V_40 ) ) ;
V_43 = TRUE ;
}
if ( ( V_62 != NULL ) && ( strlen ( V_62 ) > 0 ) && ( strlen ( V_62 ) < V_44 ) ) {
V_41 += ( T_8 ) ( sizeof( struct V_40 ) +
( V_45 ) ( F_5 ( strlen ( V_62 ) + 1 ) ) ) ;
V_43 = TRUE ;
}
if ( ( V_36 != NULL ) && ( strlen ( V_36 ) > 0 ) && ( strlen ( V_36 ) < V_44 ) ) {
V_41 += ( T_8 ) ( sizeof( struct V_40 ) +
( V_45 ) F_5 ( strlen ( V_36 ) ) ) ;
V_43 = TRUE ;
}
if ( V_43 ) {
V_41 += ( T_8 ) sizeof( struct V_40 ) ;
}
V_67 . V_46 = V_68 ;
V_67 . V_41 = V_41 ;
V_67 . V_63 = V_63 ;
V_67 . V_69 = 0 ;
V_67 . V_64 = V_64 ;
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_67 , sizeof( struct V_67 ) , V_4 , V_5 ) )
return FALSE ;
if ( ( V_34 != NULL ) && ( strlen ( V_34 ) > 0 ) && ( strlen ( V_34 ) < V_44 ) ) {
V_40 . type = V_54 ;
V_40 . V_55 = ( V_45 ) strlen ( V_34 ) ;
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_40 , sizeof( struct V_40 ) , V_4 , V_5 ) )
return FALSE ;
if ( ! V_9 ( V_1 , ( const T_2 * ) V_34 , ( int ) strlen ( V_34 ) , V_4 , V_5 ) )
return FALSE ;
if ( strlen ( V_34 ) % 4 ) {
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_42 , 4 - strlen ( V_34 ) % 4 , V_4 , V_5 ) )
return FALSE ;
}
}
if ( ( V_60 != NULL ) && ( strlen ( V_60 ) > 0 ) && ( strlen ( V_60 ) < V_44 ) ) {
V_40 . type = V_70 ;
V_40 . V_55 = ( V_45 ) strlen ( V_60 ) ;
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_40 , sizeof( struct V_40 ) , V_4 , V_5 ) )
return FALSE ;
if ( ! V_9 ( V_1 , ( const T_2 * ) V_60 , ( int ) strlen ( V_60 ) , V_4 , V_5 ) )
return FALSE ;
if ( strlen ( V_60 ) % 4 ) {
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_42 , 4 - strlen ( V_60 ) % 4 , V_4 , V_5 ) )
return FALSE ;
}
}
if ( ( V_61 != NULL ) && ( strlen ( V_61 ) > 0 ) && ( strlen ( V_61 ) < V_44 ) ) {
V_40 . type = V_71 ;
V_40 . V_55 = ( V_45 ) strlen ( V_61 ) ;
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_40 , sizeof( struct V_40 ) , V_4 , V_5 ) )
return FALSE ;
if ( ! V_9 ( V_1 , ( const T_2 * ) V_61 , ( int ) strlen ( V_61 ) , V_4 , V_5 ) )
return FALSE ;
if ( strlen ( V_61 ) % 4 ) {
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_42 , 4 - strlen ( V_61 ) % 4 , V_4 , V_5 ) )
return FALSE ;
}
}
if ( V_65 != 0 ) {
V_40 . type = V_72 ;
V_40 . V_55 = sizeof( T_3 ) ;
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_40 , sizeof( struct V_40 ) , V_4 , V_5 ) )
return FALSE ;
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_65 , sizeof( T_3 ) , V_4 , V_5 ) )
return FALSE ;
}
if ( V_66 != 0 ) {
V_40 . type = V_73 ;
V_40 . V_55 = sizeof( T_2 ) ;
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_40 , sizeof( struct V_40 ) , V_4 , V_5 ) )
return FALSE ;
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_66 , sizeof( T_2 ) , V_4 , V_5 ) )
return FALSE ;
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_42 , 3 , V_4 , V_5 ) )
return FALSE ;
}
if ( ( V_62 != NULL ) && ( strlen ( V_62 ) > 0 ) && ( strlen ( V_62 ) < V_44 ) ) {
V_40 . type = V_74 ;
V_40 . V_55 = ( V_45 ) ( strlen ( V_62 ) + 1 ) ;
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_40 , sizeof( struct V_40 ) , V_4 , V_5 ) )
return FALSE ;
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_42 , 1 , V_4 , V_5 ) )
return FALSE ;
if ( ! V_9 ( V_1 , ( const T_2 * ) V_62 , ( int ) strlen ( V_62 ) , V_4 , V_5 ) )
return FALSE ;
if ( ( strlen ( V_62 ) + 1 ) % 4 ) {
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_42 , 4 - ( strlen ( V_62 ) + 1 ) % 4 , V_4 , V_5 ) )
return FALSE ;
}
}
if ( ( V_36 != NULL ) && ( strlen ( V_36 ) > 0 ) && ( strlen ( V_36 ) < V_44 ) ) {
V_40 . type = V_75 ;
V_40 . V_55 = ( V_45 ) strlen ( V_36 ) ;
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_40 , sizeof( struct V_40 ) , V_4 , V_5 ) )
return FALSE ;
if ( ! V_9 ( V_1 , ( const T_2 * ) V_36 , ( int ) strlen ( V_36 ) , V_4 , V_5 ) )
return FALSE ;
if ( strlen ( V_36 ) % 4 ) {
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_42 , 4 - strlen ( V_36 ) % 4 , V_4 , V_5 ) )
return FALSE ;
}
}
if ( V_43 ) {
V_40 . type = V_59 ;
V_40 . V_55 = 0 ;
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_40 , sizeof( struct V_40 ) , V_4 , V_5 ) )
return FALSE ;
}
return V_9 ( V_1 , ( const T_2 * ) & V_41 , sizeof( T_8 ) , V_4 , V_5 ) ;
}
T_1
F_7 ( T_6 V_9 , void * V_1 ,
const char * V_34 ,
T_7 V_23 , T_8 V_24 ,
T_8 V_25 , T_8 V_26 ,
T_8 V_76 ,
T_9 V_77 ,
const T_2 * V_27 ,
T_8 V_78 ,
T_3 * V_4 ,
int * V_5 )
{
struct V_79 V_79 ;
struct V_40 V_40 ;
T_8 V_41 ;
T_3 V_80 ;
T_1 V_43 = FALSE ;
const T_8 V_42 = 0 ;
V_41 = ( T_8 ) ( sizeof( struct V_79 ) +
F_5 ( V_25 ) +
sizeof( T_8 ) ) ;
if ( ( V_34 != NULL ) && ( strlen ( V_34 ) > 0 ) && ( strlen ( V_34 ) < V_44 ) ) {
V_41 += ( T_8 ) ( sizeof( struct V_40 ) +
( V_45 ) F_5 ( strlen ( V_34 ) ) ) ;
V_43 = TRUE ;
}
if ( V_78 != 0 ) {
V_41 += ( T_8 ) ( sizeof( struct V_40 ) +
sizeof( T_8 ) ) ;
V_43 = TRUE ;
}
if ( V_43 ) {
V_41 += ( T_8 ) sizeof( struct V_40 ) ;
}
V_80 = ( T_3 ) V_23 * V_77 + ( T_3 ) V_24 ;
V_79 . V_46 = V_81 ;
V_79 . V_41 = V_41 ;
V_79 . V_76 = V_76 ;
V_79 . V_82 = ( T_8 ) ( ( V_80 >> 32 ) & 0xffffffff ) ;
V_79 . V_83 = ( T_8 ) ( V_80 & 0xffffffff ) ;
V_79 . V_84 = V_25 ;
V_79 . V_85 = V_26 ;
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_79 , sizeof( struct V_79 ) , V_4 , V_5 ) )
return FALSE ;
if ( ! V_9 ( V_1 , V_27 , V_25 , V_4 , V_5 ) )
return FALSE ;
if ( V_25 % 4 ) {
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_42 , 4 - V_25 % 4 , V_4 , V_5 ) )
return FALSE ;
}
if ( ( V_34 != NULL ) && ( strlen ( V_34 ) > 0 ) && ( strlen ( V_34 ) < V_44 ) ) {
V_40 . type = V_54 ;
V_40 . V_55 = ( V_45 ) strlen ( V_34 ) ;
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_40 , sizeof( struct V_40 ) , V_4 , V_5 ) )
return FALSE ;
if ( ! V_9 ( V_1 , ( const T_2 * ) V_34 , ( int ) strlen ( V_34 ) , V_4 , V_5 ) )
return FALSE ;
if ( strlen ( V_34 ) % 4 ) {
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_42 , 4 - strlen ( V_34 ) % 4 , V_4 , V_5 ) )
return FALSE ;
}
}
if ( V_78 != 0 ) {
V_40 . type = V_86 ;
V_40 . V_55 = sizeof( T_8 ) ;
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_40 , sizeof( struct V_40 ) , V_4 , V_5 ) )
return FALSE ;
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_78 , sizeof( T_8 ) , V_4 , V_5 ) )
return FALSE ;
V_40 . type = V_59 ;
V_40 . V_55 = 0 ;
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_40 , sizeof( struct V_40 ) , V_4 , V_5 ) )
return FALSE ;
}
return V_9 ( V_1 , ( const T_2 * ) & V_41 , sizeof( T_8 ) , V_4 , V_5 ) ;
}
T_1
F_8 ( T_6 V_9 , void * V_1 ,
T_8 V_76 ,
T_3 * V_4 ,
const char * V_34 ,
T_3 V_87 ,
T_3 V_88 ,
T_3 V_89 ,
T_3 V_90 ,
int * V_5 )
{
struct V_91 V_91 ;
#ifdef F_9
T_10 V_92 ;
#else
struct V_93 V_92 ;
#endif
struct V_40 V_40 ;
T_8 V_41 ;
T_3 V_80 ;
T_1 V_43 = FALSE ;
const T_8 V_42 = 0 ;
#ifdef F_9
F_10 ( & V_92 ) ;
V_80 = ( ( ( T_3 ) ( T_8 ) V_92 . V_94 ) << 32 ) +
( T_8 ) V_92 . V_95 ;
V_80 /= 10 ;
V_80 -= F_11 ( 11644473600000000U ) ;
#else
F_12 ( & V_92 , NULL ) ;
V_80 = ( T_3 ) ( V_92 . V_96 ) * 1000000 +
( T_3 ) ( V_92 . V_97 ) ;
#endif
V_41 = ( T_8 ) ( sizeof( struct V_91 ) + sizeof( T_8 ) ) ;
if ( V_89 != V_98 ) {
V_41 += ( T_8 ) ( sizeof( struct V_40 ) +
sizeof( T_3 ) ) ;
V_43 = TRUE ;
}
if ( V_90 != V_98 ) {
V_41 += ( T_8 ) ( sizeof( struct V_40 ) +
sizeof( T_3 ) ) ;
V_43 = TRUE ;
}
if ( ( V_34 != NULL ) && ( strlen ( V_34 ) > 0 ) && ( strlen ( V_34 ) < V_44 ) ) {
V_41 += ( T_8 ) ( sizeof( struct V_40 ) +
( V_45 ) F_5 ( strlen ( V_34 ) ) ) ;
V_43 = TRUE ;
}
if ( V_87 != 0 ) {
V_41 += ( T_8 ) ( sizeof( struct V_40 ) +
sizeof( T_3 ) ) ;
V_43 = TRUE ;
}
if ( V_88 != 0 ) {
V_41 += ( T_8 ) ( sizeof( struct V_40 ) +
sizeof( T_3 ) ) ;
V_43 = TRUE ;
}
if ( V_43 ) {
V_41 += ( T_8 ) sizeof( struct V_40 ) ;
}
V_91 . V_46 = V_99 ;
V_91 . V_41 = V_41 ;
V_91 . V_76 = V_76 ;
V_91 . V_82 = ( T_8 ) ( ( V_80 >> 32 ) & 0xffffffff ) ;
V_91 . V_83 = ( T_8 ) ( V_80 & 0xffffffff ) ;
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_91 , sizeof( struct V_91 ) , V_4 , V_5 ) )
return FALSE ;
if ( ( V_34 != NULL ) && ( strlen ( V_34 ) > 0 ) && ( strlen ( V_34 ) < V_44 ) ) {
V_40 . type = V_54 ;
V_40 . V_55 = ( V_45 ) strlen ( V_34 ) ;
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_40 , sizeof( struct V_40 ) , V_4 , V_5 ) )
return FALSE ;
if ( ! V_9 ( V_1 , ( const T_2 * ) V_34 , ( int ) strlen ( V_34 ) , V_4 , V_5 ) )
return FALSE ;
if ( strlen ( V_34 ) % 4 ) {
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_42 , 4 - strlen ( V_34 ) % 4 , V_4 , V_5 ) )
return FALSE ;
}
}
if ( V_87 != 0 ) {
T_8 V_100 , V_101 ;
V_40 . type = V_102 ;
V_40 . V_55 = sizeof( T_3 ) ;
V_100 = ( T_8 ) ( ( V_87 >> 32 ) & 0xffffffff ) ;
V_101 = ( T_8 ) ( V_87 & 0xffffffff ) ;
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_40 , sizeof( struct V_40 ) , V_4 , V_5 ) )
return FALSE ;
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_100 , sizeof( T_8 ) , V_4 , V_5 ) )
return FALSE ;
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_101 , sizeof( T_8 ) , V_4 , V_5 ) )
return FALSE ;
}
if ( V_88 != 0 ) {
T_8 V_100 , V_101 ;
V_40 . type = V_103 ;
V_40 . V_55 = sizeof( T_3 ) ;
V_100 = ( T_8 ) ( ( V_88 >> 32 ) & 0xffffffff ) ;
V_101 = ( T_8 ) ( V_88 & 0xffffffff ) ;
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_40 , sizeof( struct V_40 ) , V_4 , V_5 ) )
return FALSE ;
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_100 , sizeof( T_8 ) , V_4 , V_5 ) )
return FALSE ;
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_101 , sizeof( T_8 ) , V_4 , V_5 ) )
return FALSE ;
}
if ( V_89 != V_98 ) {
V_40 . type = V_104 ;
V_40 . V_55 = sizeof( T_3 ) ;
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_40 , sizeof( struct V_40 ) , V_4 , V_5 ) )
return FALSE ;
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_89 , sizeof( T_3 ) , V_4 , V_5 ) )
return FALSE ;
}
if ( V_90 != V_98 ) {
V_40 . type = V_105 ;
V_40 . V_55 = sizeof( T_3 ) ;
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_40 , sizeof( struct V_40 ) , V_4 , V_5 ) )
return FALSE ;
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_90 , sizeof( T_3 ) , V_4 , V_5 ) )
return FALSE ;
}
if ( V_43 ) {
V_40 . type = V_59 ;
V_40 . V_55 = 0 ;
if ( ! V_9 ( V_1 , ( const T_2 * ) & V_40 , sizeof( struct V_40 ) , V_4 , V_5 ) )
return FALSE ;
}
return V_9 ( V_1 , ( const T_2 * ) & V_41 , sizeof( T_8 ) , V_4 , V_5 ) ;
}
