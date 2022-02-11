T_1 *
F_1 ( int V_1 , int * V_2 )
{
T_1 * V_3 ;
V_3 = fdopen ( V_1 , L_1 ) ;
if ( V_3 == NULL ) {
* V_2 = V_4 ;
}
return V_3 ;
}
T_2
F_2 ( T_1 * V_3 , int V_5 , int V_6 , T_2 V_7 , long * V_8 , int * V_2 )
{
struct V_9 V_10 ;
T_3 V_11 ;
V_10 . V_12 = V_7 ? V_13 : V_14 ;
V_10 . V_15 = 2 ;
V_10 . V_16 = 4 ;
V_10 . V_17 = 0 ;
V_10 . V_18 = 0 ;
V_10 . V_6 = V_6 ;
V_10 . V_19 = V_5 ;
V_11 = fwrite ( & V_10 , 1 , sizeof( V_10 ) , V_3 ) ;
if ( V_11 != sizeof( V_10 ) ) {
if ( V_11 == 0 && ferror ( V_3 ) )
* V_2 = V_4 ;
else
* V_2 = 0 ;
return FALSE ;
}
* V_8 += sizeof( V_10 ) ;
return TRUE ;
}
T_2
F_3 ( T_1 * V_3 , const struct V_20 * V_21 , const T_4 * V_22 ,
long * V_8 , int * V_2 )
{
struct V_23 V_24 ;
T_3 V_11 ;
V_24 . V_25 = V_21 -> V_26 . V_27 ;
V_24 . V_28 = V_21 -> V_26 . V_29 ;
V_24 . V_30 = V_21 -> V_31 ;
V_24 . V_32 = V_21 -> V_33 ;
V_11 = fwrite ( & V_24 , 1 , sizeof V_24 , V_3 ) ;
if ( V_11 != sizeof V_24 ) {
if ( V_11 == 0 && ferror ( V_3 ) )
* V_2 = V_4 ;
else
* V_2 = 0 ;
return FALSE ;
}
* V_8 += sizeof V_24 ;
V_11 = fwrite ( V_22 , 1 , V_21 -> V_31 , V_3 ) ;
if ( V_11 != V_21 -> V_31 ) {
if ( V_11 == 0 && ferror ( V_3 ) )
* V_2 = V_4 ;
else
* V_2 = 0 ;
return FALSE ;
}
* V_8 += V_21 -> V_31 ;
return TRUE ;
}
T_2
F_4 ( T_1 * V_3 ,
const char * V_34 ,
const char * V_35 ,
const char * V_36 ,
const char * V_37 ,
T_5 V_38 ,
long * V_8 ,
int * V_2 )
{
struct V_39 V_39 ;
struct V_40 V_40 ;
T_6 V_41 ;
const T_6 V_42 = 0 ;
T_2 V_43 = FALSE ;
V_41 = sizeof( struct V_39 ) +
sizeof( T_6 ) ;
if ( ( V_34 != NULL ) && ( strlen ( V_34 ) > 0 ) && ( strlen ( V_34 ) < V_44 ) ) {
V_41 += sizeof( struct V_40 ) +
( V_45 ) F_5 ( strlen ( V_34 ) ) ;
V_43 = TRUE ;
}
if ( ( V_35 != NULL ) && ( strlen ( V_35 ) > 0 ) && ( strlen ( V_35 ) < V_44 ) ) {
V_41 += sizeof( struct V_40 ) +
( V_45 ) F_5 ( strlen ( V_35 ) ) ;
V_43 = TRUE ;
}
if ( ( V_36 != NULL ) && ( strlen ( V_36 ) > 0 ) && ( strlen ( V_36 ) < V_44 ) ) {
V_41 += sizeof( struct V_40 ) +
( V_45 ) F_5 ( strlen ( V_36 ) ) ;
V_43 = TRUE ;
}
if ( ( V_37 != NULL ) && ( strlen ( V_37 ) > 0 ) && ( strlen ( V_37 ) < V_44 ) ) {
V_41 += sizeof( struct V_40 ) +
( V_45 ) F_5 ( strlen ( V_37 ) ) ;
V_43 = TRUE ;
}
if ( V_43 ) {
V_41 += sizeof( struct V_40 ) ;
}
V_39 . V_46 = V_47 ;
V_39 . V_41 = V_41 ;
V_39 . V_48 = V_49 ;
V_39 . V_50 = V_51 ;
V_39 . V_52 = V_53 ;
V_39 . V_38 = V_38 ;
F_6 ( V_3 , & V_39 , sizeof( struct V_39 ) , * V_8 , V_2 ) ;
if ( ( V_34 != NULL ) && ( strlen ( V_34 ) > 0 ) && ( strlen ( V_34 ) < V_44 ) ) {
V_40 . type = V_54 ;
V_40 . V_55 = ( V_45 ) strlen ( V_34 ) ;
F_6 ( V_3 , & V_40 , sizeof( struct V_40 ) , * V_8 , V_2 ) ;
F_6 ( V_3 , V_34 , strlen ( V_34 ) , * V_8 , V_2 ) ;
if ( strlen ( V_34 ) % 4 ) {
F_6 ( V_3 , & V_42 , 4 - strlen ( V_34 ) % 4 , * V_8 , V_2 ) ;
}
}
if ( ( V_35 != NULL ) && ( strlen ( V_35 ) > 0 ) && ( strlen ( V_35 ) < V_44 ) ) {
V_40 . type = V_56 ;
V_40 . V_55 = ( V_45 ) strlen ( V_35 ) ;
F_6 ( V_3 , & V_40 , sizeof( struct V_40 ) , * V_8 , V_2 ) ;
F_6 ( V_3 , V_35 , strlen ( V_35 ) , * V_8 , V_2 ) ;
if ( ( strlen ( V_35 ) + 1 ) % 4 ) {
F_6 ( V_3 , & V_42 , 4 - strlen ( V_35 ) % 4 , * V_8 , V_2 ) ;
}
}
if ( ( V_36 != NULL ) && ( strlen ( V_36 ) > 0 ) && ( strlen ( V_36 ) < V_44 ) ) {
V_40 . type = V_57 ;
V_40 . V_55 = ( V_45 ) strlen ( V_36 ) ;
F_6 ( V_3 , & V_40 , sizeof( struct V_40 ) , * V_8 , V_2 ) ;
F_6 ( V_3 , V_36 , strlen ( V_36 ) , * V_8 , V_2 ) ;
if ( strlen ( V_36 ) % 4 ) {
F_6 ( V_3 , & V_42 , 4 - strlen ( V_36 ) % 4 , * V_8 , V_2 ) ;
}
}
if ( ( V_37 != NULL ) && ( strlen ( V_37 ) > 0 ) && ( strlen ( V_37 ) < V_44 ) ) {
V_40 . type = V_58 ;
V_40 . V_55 = ( V_45 ) strlen ( V_37 ) ;
F_6 ( V_3 , & V_40 , sizeof( struct V_40 ) , * V_8 , V_2 ) ;
F_6 ( V_3 , V_37 , strlen ( V_37 ) , * V_8 , V_2 ) ;
if ( strlen ( V_37 ) % 4 ) {
F_6 ( V_3 , & V_42 , 4 - strlen ( V_37 ) % 4 , * V_8 , V_2 ) ;
}
}
if ( V_43 ) {
V_40 . type = V_59 ;
V_40 . V_55 = 0 ;
F_6 ( V_3 , & V_40 , sizeof( struct V_40 ) , * V_8 , V_2 ) ;
}
F_6 ( V_3 , & V_41 , sizeof( T_6 ) , * V_8 , V_2 ) ;
return TRUE ;
}
T_2
F_7 ( T_1 * V_3 ,
const char * V_34 ,
const char * V_60 ,
const char * V_61 ,
const char * V_62 ,
const char * V_36 ,
int V_63 ,
int V_64 ,
long * V_8 ,
T_5 V_65 ,
T_7 V_66 ,
int * V_2 )
{
struct V_67 V_67 ;
struct V_40 V_40 ;
T_6 V_41 ;
const T_6 V_42 = 0 ;
T_2 V_43 = FALSE ;
V_41 = sizeof( struct V_67 ) + sizeof( T_6 ) ;
if ( ( V_34 != NULL ) && ( strlen ( V_34 ) > 0 ) && ( strlen ( V_34 ) < V_44 ) ) {
V_41 += sizeof( struct V_40 ) +
( V_45 ) F_5 ( strlen ( V_34 ) ) ;
V_43 = TRUE ;
}
if ( ( V_60 != NULL ) && ( strlen ( V_60 ) > 0 ) && ( strlen ( V_60 ) < V_44 ) ) {
V_41 += sizeof( struct V_40 ) +
( V_45 ) F_5 ( strlen ( V_60 ) ) ;
V_43 = TRUE ;
}
if ( ( V_61 != NULL ) && ( strlen ( V_61 ) > 0 ) && ( strlen ( V_61 ) < V_44 ) ) {
V_41 += sizeof( struct V_40 ) +
( V_45 ) F_5 ( strlen ( V_61 ) ) ;
V_43 = TRUE ;
}
if ( V_65 != 0 ) {
V_41 += sizeof( struct V_40 ) + sizeof( T_5 ) ;
V_43 = TRUE ;
}
if ( V_66 != 0 ) {
V_41 += sizeof( struct V_40 ) + sizeof( struct V_40 ) ;
V_43 = TRUE ;
}
if ( ( V_62 != NULL ) && ( strlen ( V_62 ) > 0 ) && ( strlen ( V_62 ) < V_44 ) ) {
V_41 += sizeof( struct V_40 ) +
( V_45 ) ( F_5 ( strlen ( V_62 ) + 1 ) ) ;
V_43 = TRUE ;
}
if ( ( V_36 != NULL ) && ( strlen ( V_36 ) > 0 ) && ( strlen ( V_36 ) < V_44 ) ) {
V_41 += sizeof( struct V_40 ) +
( V_45 ) F_5 ( strlen ( V_36 ) ) ;
V_43 = TRUE ;
}
if ( V_43 ) {
V_41 += sizeof( struct V_40 ) ;
}
V_67 . V_46 = V_68 ;
V_67 . V_41 = V_41 ;
V_67 . V_63 = V_63 ;
V_67 . V_69 = 0 ;
V_67 . V_64 = V_64 ;
F_6 ( V_3 , & V_67 , sizeof( struct V_67 ) , * V_8 , V_2 ) ;
if ( ( V_34 != NULL ) && ( strlen ( V_34 ) > 0 ) && ( strlen ( V_34 ) < V_44 ) ) {
V_40 . type = V_54 ;
V_40 . V_55 = ( V_45 ) strlen ( V_34 ) ;
F_6 ( V_3 , & V_40 , sizeof( struct V_40 ) , * V_8 , V_2 ) ;
F_6 ( V_3 , V_34 , strlen ( V_34 ) , * V_8 , V_2 ) ;
if ( strlen ( V_34 ) % 4 ) {
F_6 ( V_3 , & V_42 , 4 - strlen ( V_34 ) % 4 , * V_8 , V_2 ) ;
}
}
if ( ( V_60 != NULL ) && ( strlen ( V_60 ) > 0 ) && ( strlen ( V_60 ) < V_44 ) ) {
V_40 . type = V_70 ;
V_40 . V_55 = ( V_45 ) strlen ( V_60 ) ;
F_6 ( V_3 , & V_40 , sizeof( struct V_40 ) , * V_8 , V_2 ) ;
F_6 ( V_3 , V_60 , strlen ( V_60 ) , * V_8 , V_2 ) ;
if ( strlen ( V_60 ) % 4 ) {
F_6 ( V_3 , & V_42 , 4 - strlen ( V_60 ) % 4 , * V_8 , V_2 ) ;
}
}
if ( ( V_61 != NULL ) && ( strlen ( V_61 ) > 0 ) && ( strlen ( V_61 ) < V_44 ) ) {
V_40 . type = V_71 ;
V_40 . V_55 = ( V_45 ) strlen ( V_61 ) ;
F_6 ( V_3 , & V_40 , sizeof( struct V_40 ) , * V_8 , V_2 ) ;
F_6 ( V_3 , V_61 , strlen ( V_61 ) , * V_8 , V_2 ) ;
if ( strlen ( V_61 ) % 4 ) {
F_6 ( V_3 , & V_42 , 4 - strlen ( V_61 ) % 4 , * V_8 , V_2 ) ;
}
}
if ( V_65 != 0 ) {
V_40 . type = V_72 ;
V_40 . V_55 = sizeof( T_5 ) ;
F_6 ( V_3 , & V_40 , sizeof( struct V_40 ) , * V_8 , V_2 ) ;
F_6 ( V_3 , & V_65 , sizeof( T_5 ) , * V_8 , V_2 ) ;
}
if ( V_66 != 0 ) {
V_40 . type = V_73 ;
V_40 . V_55 = sizeof( T_7 ) ;
F_6 ( V_3 , & V_40 , sizeof( struct V_40 ) , * V_8 , V_2 ) ;
F_6 ( V_3 , & V_66 , sizeof( T_7 ) , * V_8 , V_2 ) ;
F_6 ( V_3 , & V_42 , 3 , * V_8 , V_2 ) ;
}
if ( ( V_62 != NULL ) && ( strlen ( V_62 ) > 0 ) && ( strlen ( V_62 ) < V_44 ) ) {
V_40 . type = V_74 ;
V_40 . V_55 = ( V_45 ) ( strlen ( V_62 ) + 1 ) ;
F_6 ( V_3 , & V_40 , sizeof( struct V_40 ) , * V_8 , V_2 ) ;
F_6 ( V_3 , & V_42 , 1 , * V_8 , V_2 ) ;
F_6 ( V_3 , V_62 , strlen ( V_62 ) , * V_8 , V_2 ) ;
if ( ( strlen ( V_62 ) + 1 ) % 4 ) {
F_6 ( V_3 , & V_42 , 4 - ( strlen ( V_62 ) + 1 ) % 4 , * V_8 , V_2 ) ;
}
}
if ( ( V_36 != NULL ) && ( strlen ( V_36 ) > 0 ) && ( strlen ( V_36 ) < V_44 ) ) {
V_40 . type = V_75 ;
V_40 . V_55 = ( V_45 ) strlen ( V_36 ) ;
F_6 ( V_3 , & V_40 , sizeof( struct V_40 ) , * V_8 , V_2 ) ;
F_6 ( V_3 , V_36 , strlen ( V_36 ) , * V_8 , V_2 ) ;
if ( strlen ( V_36 ) % 4 ) {
F_6 ( V_3 , & V_42 , 4 - strlen ( V_36 ) % 4 , * V_8 , V_2 ) ;
}
}
if ( V_43 ) {
V_40 . type = V_59 ;
V_40 . V_55 = 0 ;
F_6 ( V_3 , & V_40 , sizeof( struct V_40 ) , * V_8 , V_2 ) ;
}
F_6 ( V_3 , & V_41 , sizeof( T_6 ) , * V_8 , V_2 ) ;
return TRUE ;
}
T_2
F_8 ( T_1 * V_3 ,
const struct V_20 * V_21 ,
T_6 V_76 ,
T_8 V_77 ,
const T_4 * V_22 ,
long * V_8 ,
int * V_2 )
{
struct V_78 V_78 ;
T_6 V_41 ;
T_5 V_79 ;
const T_6 V_42 = 0 ;
V_41 = sizeof( struct V_78 ) +
F_5 ( V_21 -> V_31 ) +
sizeof( T_6 ) ;
V_79 = ( T_5 ) ( V_21 -> V_26 . V_27 ) * V_77 +
( T_5 ) ( V_21 -> V_26 . V_29 ) ;
V_78 . V_46 = V_80 ;
V_78 . V_41 = V_41 ;
V_78 . V_76 = V_76 ;
V_78 . V_81 = ( T_6 ) ( ( V_79 >> 32 ) & 0xffffffff ) ;
V_78 . V_82 = ( T_6 ) ( V_79 & 0xffffffff ) ;
V_78 . V_83 = V_21 -> V_31 ;
V_78 . V_84 = V_21 -> V_33 ;
F_6 ( V_3 , & V_78 , sizeof( struct V_78 ) , * V_8 , V_2 ) ;
F_6 ( V_3 , V_22 , V_21 -> V_31 , * V_8 , V_2 ) ;
if ( V_21 -> V_31 % 4 ) {
F_6 ( V_3 , & V_42 , 4 - V_21 -> V_31 % 4 , * V_8 , V_2 ) ;
}
F_6 ( V_3 , & V_41 , sizeof( T_6 ) , * V_8 , V_2 ) ;
return TRUE ;
}
T_2
F_9 ( T_1 * V_3 ,
T_6 V_76 ,
long * V_8 ,
const char * V_34 ,
T_5 V_85 ,
T_5 V_86 ,
T_5 V_87 ,
T_5 V_88 ,
int * V_2 )
{
struct V_89 V_89 ;
#ifdef F_10
T_9 V_90 ;
#else
struct V_91 V_90 ;
#endif
struct V_40 V_40 ;
T_6 V_41 ;
T_5 V_79 ;
T_2 V_43 = FALSE ;
const T_6 V_42 = 0 ;
#ifdef F_10
F_11 ( & V_90 ) ;
V_79 = ( ( ( T_5 ) ( T_6 ) V_90 . V_92 ) << 32 ) +
( T_6 ) V_90 . V_93 ;
V_79 /= 10 ;
V_79 -= F_12 ( 11644473600000000U ) ;
#else
F_13 ( & V_90 , NULL ) ;
V_79 = ( T_5 ) ( V_90 . V_27 ) * 1000000 +
( T_5 ) ( V_90 . V_29 ) ;
#endif
V_41 = sizeof( struct V_89 ) + sizeof( T_6 ) ;
if ( V_87 != V_94 ) {
V_41 += sizeof( struct V_40 ) + sizeof( T_5 ) ;
V_43 = TRUE ;
}
if ( V_88 != V_94 ) {
V_41 += sizeof( struct V_40 ) + sizeof( T_5 ) ;
V_43 = TRUE ;
}
if ( ( V_34 != NULL ) && ( strlen ( V_34 ) > 0 ) && ( strlen ( V_34 ) < V_44 ) ) {
V_41 += sizeof( struct V_40 ) +
( V_45 ) F_5 ( strlen ( V_34 ) ) ;
V_43 = TRUE ;
}
if ( V_85 != 0 ) {
V_41 += sizeof( struct V_40 ) + sizeof( T_5 ) ;
V_43 = TRUE ;
}
if ( V_86 != 0 ) {
V_41 += sizeof( struct V_40 ) + sizeof( T_5 ) ;
V_43 = TRUE ;
}
if ( V_43 ) {
V_41 += sizeof( struct V_40 ) ;
}
V_89 . V_46 = V_95 ;
V_89 . V_41 = V_41 ;
V_89 . V_76 = V_76 ;
V_89 . V_81 = ( T_6 ) ( ( V_79 >> 32 ) & 0xffffffff ) ;
V_89 . V_82 = ( T_6 ) ( V_79 & 0xffffffff ) ;
F_6 ( V_3 , & V_89 , sizeof( struct V_89 ) , * V_8 , V_2 ) ;
if ( ( V_34 != NULL ) && ( strlen ( V_34 ) > 0 ) && ( strlen ( V_34 ) < V_44 ) ) {
V_40 . type = V_54 ;
V_40 . V_55 = ( V_45 ) strlen ( V_34 ) ;
F_6 ( V_3 , & V_40 , sizeof( struct V_40 ) , * V_8 , V_2 ) ;
F_6 ( V_3 , V_34 , strlen ( V_34 ) , * V_8 , V_2 ) ;
if ( strlen ( V_34 ) % 4 ) {
F_6 ( V_3 , & V_42 , 4 - strlen ( V_34 ) % 4 , * V_8 , V_2 ) ;
}
}
if ( V_85 != 0 ) {
T_6 V_96 , V_97 ;
V_40 . type = V_98 ;
V_40 . V_55 = sizeof( T_5 ) ;
V_96 = ( T_6 ) ( ( V_85 >> 32 ) & 0xffffffff ) ;
V_97 = ( T_6 ) ( V_85 & 0xffffffff ) ;
F_6 ( V_3 , & V_40 , sizeof( struct V_40 ) , * V_8 , V_2 ) ;
F_6 ( V_3 , & V_96 , sizeof( T_6 ) , * V_8 , V_2 ) ;
F_6 ( V_3 , & V_97 , sizeof( T_6 ) , * V_8 , V_2 ) ;
}
if ( V_86 != 0 ) {
T_6 V_96 , V_97 ;
V_40 . type = V_99 ;
V_40 . V_55 = sizeof( T_5 ) ;
V_96 = ( T_6 ) ( ( V_86 >> 32 ) & 0xffffffff ) ;
V_97 = ( T_6 ) ( V_86 & 0xffffffff ) ;
F_6 ( V_3 , & V_40 , sizeof( struct V_40 ) , * V_8 , V_2 ) ;
F_6 ( V_3 , & V_96 , sizeof( T_6 ) , * V_8 , V_2 ) ;
F_6 ( V_3 , & V_97 , sizeof( T_6 ) , * V_8 , V_2 ) ;
}
if ( V_87 != V_94 ) {
V_40 . type = V_100 ;
V_40 . V_55 = sizeof( T_5 ) ;
F_6 ( V_3 , & V_40 , sizeof( struct V_40 ) , * V_8 , V_2 ) ;
F_6 ( V_3 , & V_87 , sizeof( T_5 ) , * V_8 , V_2 ) ;
}
if ( V_88 != V_94 ) {
V_40 . type = V_101 ;
V_40 . V_55 = sizeof( T_5 ) ;
F_6 ( V_3 , & V_40 , sizeof( struct V_40 ) , * V_8 , V_2 ) ;
F_6 ( V_3 , & V_88 , sizeof( T_5 ) , * V_8 , V_2 ) ;
}
if ( V_43 ) {
V_40 . type = V_59 ;
V_40 . V_55 = 0 ;
F_6 ( V_3 , & V_40 , sizeof( struct V_40 ) , * V_8 , V_2 ) ;
}
F_6 ( V_3 , & V_41 , sizeof( T_6 ) , * V_8 , V_2 ) ;
return TRUE ;
}
T_2
F_14 ( T_1 * V_22 , int * V_2 )
{
if ( fflush ( V_22 ) == V_102 ) {
if ( V_2 != NULL )
* V_2 = V_4 ;
return FALSE ;
}
return TRUE ;
}
T_2
F_15 ( T_1 * V_22 , int * V_2 )
{
if ( fclose ( V_22 ) == V_102 ) {
if ( V_2 != NULL )
* V_2 = V_4 ;
return FALSE ;
}
return TRUE ;
}
