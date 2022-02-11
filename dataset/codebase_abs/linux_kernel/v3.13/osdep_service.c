inline int F_1 ( int V_1 )
{
if ( V_1 >= 0 )
return V_2 ;
return V_3 ;
}
T_1 F_2 ( T_2 * V_4 )
{
int V_5 = 0 , V_6 = 0 ;
int V_7 ;
for ( V_7 = 0 ; V_7 <= strlen ( V_4 ) ; V_7 ++ ) {
if ( V_4 [ V_7 ] >= '0' && V_4 [ V_7 ] <= '9' )
V_5 = V_5 * 10 + V_4 [ V_7 ] - '0' ;
else if ( V_4 [ 0 ] == '-' && V_7 == 0 )
V_6 = 1 ;
else
break;
}
if ( V_6 == 1 )
V_5 = V_5 * - 1 ;
return V_5 ;
}
inline T_2 * F_3 ( T_1 V_8 )
{
T_2 * V_9 ;
V_9 = F_4 ( V_8 ) ;
return V_9 ;
}
inline T_2 * F_5 ( T_1 V_8 )
{
T_2 * V_9 ;
V_9 = F_3 ( V_8 ) ;
if ( V_9 != NULL )
memset ( V_9 , 0 , V_8 ) ;
return V_9 ;
}
inline void F_6 ( T_2 * V_9 , T_1 V_8 )
{
F_7 ( V_9 ) ;
}
T_2 * F_8 ( T_1 V_8 )
{
T_2 * V_9 = NULL ;
V_9 = F_9 ( V_8 , F_10 () ? V_10 : V_11 ) ;
return V_9 ;
}
T_2 * F_11 ( T_1 V_8 )
{
T_2 * V_9 = F_8 ( V_8 ) ;
if ( V_9 != NULL )
memset ( V_9 , 0 , V_8 ) ;
return V_9 ;
}
void * F_12 ( int V_12 , int V_13 , int V_14 )
{
int V_15 ;
void * * V_16 = ( void * * ) F_13 ( V_12 * sizeof( void * ) + V_12 * V_13 * V_14 ) ;
if ( V_16 == NULL ) {
F_14 ( L_1 , V_17 ) ;
return NULL ;
}
for ( V_15 = 0 ; V_15 < V_12 ; V_15 ++ )
V_16 [ V_15 ] = ( ( char * ) ( V_16 + V_12 ) ) + V_15 * V_13 * V_14 ;
return V_16 ;
}
void F_15 ( void * V_9 , int V_12 , int V_13 , int V_14 )
{
F_16 ( V_9 ) ;
}
int F_17 ( void * V_18 , void * V_19 , T_1 V_8 )
{
if ( ! ( memcmp ( V_18 , V_19 , V_8 ) ) )
return true ;
else
return false ;
}
void F_18 ( void * V_9 , int V_20 , T_1 V_8 )
{
memset ( V_9 , V_20 , V_8 ) ;
}
void F_19 ( struct V_21 * V_22 )
{
F_20 ( V_22 ) ;
}
T_1 F_21 ( struct V_21 * V_23 )
{
if ( F_22 ( V_23 ) )
return true ;
else
return false ;
}
void F_23 ( struct V_21 * V_24 , struct V_21 * V_23 )
{
F_24 ( V_24 , V_23 ) ;
}
void F_25 ( struct V_21 * V_24 , struct V_21 * V_23 )
{
F_26 ( V_24 , V_23 ) ;
}
void F_27 ( struct V_25 * V_26 , int V_27 )
{
F_28 ( V_26 , V_27 ) ;
}
void F_29 ( struct V_25 * V_26 )
{
}
void F_30 ( struct V_25 * V_26 )
{
F_31 ( V_26 ) ;
}
T_1 F_32 ( struct V_25 * V_26 )
{
if ( F_33 ( V_26 ) )
return V_3 ;
else
return V_2 ;
}
void F_34 ( struct V_28 * V_29 )
{
F_35 ( V_29 ) ;
}
void F_36 ( struct V_28 * V_29 )
{
F_37 ( V_29 ) ;
}
void F_38 ( T_3 * V_30 )
{
F_39 ( V_30 ) ;
}
void F_40 ( T_3 * V_30 )
{
}
void F_41 ( struct V_31 * V_32 )
{
F_19 ( & ( V_32 -> V_33 ) ) ;
F_38 ( & ( V_32 -> V_34 ) ) ;
}
T_1 F_42 ( struct V_31 * V_32 )
{
return F_21 ( & ( V_32 -> V_33 ) ) ;
}
T_1 F_43 ( struct V_21 * V_35 , struct V_21 * V_24 )
{
if ( V_35 == V_24 )
return true ;
else
return false ;
}
T_1 F_44 ( void )
{
return V_36 ;
}
inline T_1 F_45 ( T_1 V_37 )
{
return V_37 * 1000 / V_38 ;
}
inline T_1 F_46 ( T_1 V_39 )
{
return V_39 * V_38 / 1000 ;
}
inline T_4 F_47 ( T_1 V_40 )
{
return F_45 ( V_36 - V_40 ) ;
}
inline T_4 F_48 ( T_1 V_40 , T_1 V_41 )
{
return F_45 ( V_41 - V_40 ) ;
}
void F_49 ( int V_39 )
{
T_1 V_42 ;
V_42 = ( V_39 * V_38 ) / 1000 ;
if ( V_42 == 0 )
V_42 = 1 ;
F_50 ( V_43 ) ;
if ( F_51 ( V_42 ) != 0 )
return;
}
void F_52 ( int V_39 )
{
F_53 ( ( unsigned int ) V_39 ) ;
}
void F_54 ( int V_44 )
{
if ( 1 < ( V_44 / 1000 ) )
F_53 ( 1 ) ;
else
F_53 ( ( V_44 / 1000 ) + 1 ) ;
}
void F_55 ( int V_39 )
{
F_56 ( ( unsigned long ) V_39 ) ;
}
void F_57 ( int V_44 )
{
F_58 ( ( unsigned long ) V_44 ) ;
}
void F_59 ( void )
{
F_60 () ;
}
inline void F_61 ( void )
{
}
inline void F_62 ( void )
{
}
inline void F_63 ( void )
{
}
inline void F_64 ( void )
{
}
inline void F_65 ( T_5 * V_45 , int V_7 )
{
F_66 ( V_45 , V_7 ) ;
}
inline int F_67 ( T_5 * V_45 )
{
return F_68 ( V_45 ) ;
}
inline void F_69 ( T_5 * V_45 , int V_7 )
{
F_70 ( V_7 , V_45 ) ;
}
inline void F_71 ( T_5 * V_45 , int V_7 )
{
F_72 ( V_7 , V_45 ) ;
}
inline void F_73 ( T_5 * V_45 )
{
F_74 ( V_45 ) ;
}
inline void F_75 ( T_5 * V_45 )
{
F_76 ( V_45 ) ;
}
inline int F_77 ( T_5 * V_45 , int V_7 )
{
return F_78 ( V_7 , V_45 ) ;
}
inline int F_79 ( T_5 * V_45 , int V_7 )
{
return F_80 ( V_7 , V_45 ) ;
}
inline int F_81 ( T_5 * V_45 )
{
return F_82 ( V_45 ) ;
}
inline int F_83 ( T_5 * V_45 )
{
return F_84 ( V_45 ) ;
}
struct V_46 * F_85 ( int V_47 ,
void * V_48 )
{
struct V_46 * V_49 ;
struct V_50 * V_51 ;
V_49 = F_86 ( sizeof( struct V_50 ) , 4 ) ;
if ( ! V_49 )
goto RETURN;
V_51 = F_87 ( V_49 ) ;
V_51 -> V_52 = V_48 ;
V_51 -> V_47 = V_47 ;
RETURN:
return V_49 ;
}
struct V_46 * F_88 ( int V_47 )
{
struct V_46 * V_49 ;
struct V_50 * V_51 ;
V_49 = F_86 ( sizeof( struct V_50 ) , 4 ) ;
if ( ! V_49 )
goto RETURN;
V_51 = F_87 ( V_49 ) ;
V_51 -> V_52 = F_89 ( V_47 ) ;
if ( ! V_51 -> V_52 ) {
F_90 ( V_49 ) ;
V_49 = NULL ;
goto RETURN;
}
V_51 -> V_47 = V_47 ;
RETURN:
return V_49 ;
}
void F_91 ( struct V_46 * V_53 )
{
struct V_50 * V_51 ;
if ( ! V_53 )
goto RETURN;
V_51 = F_87 ( V_53 ) ;
if ( ! V_51 -> V_52 )
goto RETURN;
F_92 ( V_51 -> V_52 , V_51 -> V_47 ) ;
F_90 ( V_53 ) ;
RETURN:
return;
}
int F_93 ( struct V_54 * V_55 , const char * V_56 )
{
struct V_46 * V_49 ;
struct V_46 * V_57 ;
struct V_58 * V_59 ;
int V_60 ;
if ( ! V_55 )
goto error;
V_57 = V_55 -> V_49 ;
V_59 = & V_55 -> V_61 ;
if ( V_59 -> V_62 ) {
F_90 ( V_59 -> V_62 ) ;
V_59 -> V_62 = NULL ;
}
if ( ! F_94 () )
F_95 ( V_57 ) ;
else
F_96 ( V_57 ) ;
F_97 ( V_57 ) ;
V_59 -> V_62 = V_57 ;
V_49 = F_98 ( V_55 ) ;
if ( ! V_49 ) {
V_60 = - 1 ;
goto error;
}
F_99 ( V_49 , F_100 ( F_101 ( V_55 ) ) ) ;
F_102 ( V_49 , V_56 ) ;
memcpy ( V_49 -> V_63 , V_55 -> V_64 . V_65 , V_66 ) ;
if ( ! F_94 () )
V_60 = F_103 ( V_49 ) ;
else
V_60 = F_104 ( V_49 ) ;
if ( V_60 != 0 ) {
F_105 ( V_67 , V_68 ,
( L_2 ) ) ;
goto error;
}
F_106 ( V_49 ) ;
return 0 ;
error:
return - 1 ;
}
T_6 F_107 ( T_6 V_69 , T_6 V_70 )
{
return F_108 ( V_69 , V_70 ) ;
}
T_6 F_109 ( T_6 V_69 , T_6 V_70 )
{
F_108 ( V_69 , V_70 ) ;
return V_69 ;
}
void F_110 ( T_2 * * V_71 , T_1 * V_72 )
{
* V_72 = 0 ;
F_16 ( * V_71 ) ;
* V_71 = NULL ;
}
void F_111 ( T_2 * * V_71 , T_1 * V_72 , T_2 * V_19 , T_1 V_73 )
{
T_1 V_74 = 0 , V_75 = 0 ;
T_2 * V_76 = NULL ;
T_2 * V_77 = NULL ;
if ( ! V_71 || ! V_72 )
return;
if ( ! V_19 || ! V_73 )
goto V_78;
V_77 = F_112 ( V_73 ) ;
if ( V_77 ) {
V_75 = V_73 ;
memcpy ( V_77 , V_19 , V_75 ) ;
}
V_78:
V_76 = * V_71 ;
V_74 = * V_72 ;
* V_72 = 0 ;
* V_71 = V_77 ;
* V_72 = V_75 ;
F_16 ( V_76 ) ;
}
inline bool F_113 ( struct V_79 * V_80 )
{
return ( V_80 -> V_81 == V_80 -> V_82 - 1 ) ? true : false ;
}
inline bool F_114 ( struct V_79 * V_80 )
{
return ( V_80 -> V_81 == V_80 -> V_82 ) ? true : false ;
}
bool F_115 ( struct V_79 * V_80 , void * V_71 )
{
if ( F_113 ( V_80 ) )
return V_3 ;
if ( 0 )
F_116 ( L_3 , V_17 , V_80 -> V_81 ) ;
V_80 -> V_83 [ V_80 -> V_81 ] = V_71 ;
V_80 -> V_81 = ( V_80 -> V_81 + 1 ) % V_80 -> V_14 ;
return V_2 ;
}
void * F_117 ( struct V_79 * V_80 )
{
void * V_71 ;
if ( F_114 ( V_80 ) )
return NULL ;
if ( 0 )
F_116 ( L_3 , V_17 , V_80 -> V_82 ) ;
V_71 = V_80 -> V_83 [ V_80 -> V_82 ] ;
V_80 -> V_82 = ( V_80 -> V_82 + 1 ) % V_80 -> V_14 ;
return V_71 ;
}
struct V_79 * F_118 ( T_1 V_14 )
{
struct V_79 * V_80 ;
V_80 = (struct V_79 * ) F_112 ( sizeof( * V_80 ) +
sizeof( void * ) * V_14 ) ;
if ( V_80 ) {
V_80 -> V_81 = 0 ;
V_80 -> V_82 = 0 ;
V_80 -> V_14 = V_14 ;
}
return V_80 ;
}
