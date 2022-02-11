int F_1 ( struct V_1 * V_2 , void * V_3 )
{
int V_4 ;
F_2 ( & V_5 . V_6 ) ;
V_4 = F_3 ( V_2 ,
L_1
L_2
L_3
L_4
L_5
L_6
L_7
L_8
L_9
L_10
L_11
L_12
L_13
L_14
L_15
L_16
L_17
L_18 V_7 L_19
,
V_8 ,
V_9 ,
V_5 . V_10 ,
V_5 . V_11 ,
V_5 . V_12 ,
V_5 . V_13 ,
V_5 . V_14 ,
F_4 () - V_5 . V_15 ,
F_4 () - V_5 . V_16 ,
V_5 . V_17 ,
V_5 . V_18 ,
V_5 . V_19 ,
V_5 . V_20 ,
V_5 . V_21 ,
V_5 . V_22 ,
V_5 . V_23 ,
V_5 . V_24 ,
V_5 . V_25 , V_26
) ;
F_5 ( & V_5 . V_6 ) ;
return V_4 ;
}
static void F_6 ( long V_27 )
{
int V_28 , V_29 ;
int V_30 , V_31 ;
F_7 ( V_27 > 0 ) ;
F_7 ( V_27 <= V_5 . V_13 ) ;
F_7 ( V_5 . V_13 <= V_5 . V_12 ) ;
V_31 = ( V_5 . V_12 - 1 ) / V_9 ;
V_5 . V_13 -= V_27 ;
V_5 . V_12 -= V_27 ;
V_30 = V_5 . V_12 == 0 ? - 1 :
( ( V_5 . V_12 - 1 ) / V_9 ) ;
V_28 = V_5 . V_13 / V_9 ;
V_29 = V_5 . V_13 % V_9 ;
F_7 ( V_5 . V_32 [ V_28 ] ) ;
while ( V_27 -- ) {
F_7 ( V_5 . V_32 [ V_28 ] ) ;
F_7 ( V_5 . V_32 [ V_28 ] [ V_29 ] != NULL ) ;
F_8 ( V_5 . V_32 [ V_28 ] [ V_29 ] ) ;
V_5 . V_32 [ V_28 ] [ V_29 ] = NULL ;
if ( ++ V_29 == V_9 ) {
V_28 ++ ;
V_29 = 0 ;
}
}
while ( V_30 < V_31 ) {
F_7 ( V_5 . V_32 [ V_31 ] ) ;
F_9 ( V_5 . V_32 [ V_31 ] , V_33 ) ;
V_5 . V_32 [ V_31 ] = NULL ;
V_31 -- ;
}
}
static unsigned long F_10 ( struct V_34 * V_35 ,
struct V_36 * V_37 )
{
if ( F_11 ( F_4 () - V_5 . V_16 >
V_38 ) ) {
F_2 ( & V_5 . V_6 ) ;
V_5 . V_14 = V_39 ;
F_5 ( & V_5 . V_6 ) ;
}
F_7 ( V_5 . V_14 <= V_39 ) ;
return F_12 ( ( int ) V_5 . V_13 - V_40 , 0 ) *
( V_39 - V_5 . V_14 ) / V_39 ;
}
static unsigned long F_13 ( struct V_34 * V_35 ,
struct V_36 * V_37 )
{
F_2 ( & V_5 . V_6 ) ;
V_37 -> V_41 = F_14 (unsigned long, sc->nr_to_scan,
page_pools.epp_free_pages - PTLRPC_MAX_BRW_PAGES) ;
if ( V_37 -> V_41 > 0 ) {
F_6 ( V_37 -> V_41 ) ;
F_15 ( V_42 , L_20 ,
( long ) V_37 -> V_41 , V_5 . V_13 ) ;
V_5 . V_20 ++ ;
V_5 . V_15 = F_4 () ;
}
F_5 ( & V_5 . V_6 ) ;
if ( F_11 ( F_4 () - V_5 . V_16 >
V_38 ) ) {
F_2 ( & V_5 . V_6 ) ;
V_5 . V_14 = V_39 ;
F_5 ( & V_5 . V_6 ) ;
}
F_7 ( V_5 . V_14 <= V_39 ) ;
return V_37 -> V_41 ;
}
static inline
int F_16 ( unsigned long V_27 )
{
return ( int ) ( ( V_27 + V_9 - 1 ) / V_9 ) ;
}
static unsigned long F_17 ( struct V_43 * * * V_44 , int V_45 )
{
unsigned long V_46 = 0 ;
int V_47 , V_48 ;
for ( V_47 = 0 ; V_47 < V_45 ; V_47 ++ ) {
if ( V_44 [ V_47 ] ) {
for ( V_48 = 0 ; V_48 < V_9 ; V_48 ++ ) {
if ( V_44 [ V_47 ] [ V_48 ] ) {
F_8 ( V_44 [ V_47 ] [ V_48 ] ) ;
V_46 ++ ;
}
}
F_9 ( V_44 [ V_47 ] , V_33 ) ;
V_44 [ V_47 ] = NULL ;
}
}
return V_46 ;
}
static void F_18 ( struct V_43 * * * V_44 , int V_45 , int V_27 )
{
int V_49 ;
int V_50 , V_51 , V_52 , V_53 ;
int V_54 , V_55 ;
F_7 ( V_27 > 0 ) ;
F_7 ( V_5 . V_12 + V_27 <= V_5 . V_10 ) ;
F_7 ( F_16 ( V_27 ) == V_45 ) ;
F_7 ( V_5 . V_56 ) ;
F_2 ( & V_5 . V_6 ) ;
V_49 = V_5 . V_12 % V_9 ;
if ( V_49 != 0 )
V_49 = V_9 - V_49 ;
V_49 += V_5 . V_12 - V_5 . V_13 ;
V_50 = V_5 . V_13 / V_9 ;
V_52 = V_5 . V_13 % V_9 ;
V_51 = V_45 - 1 ;
V_53 = ( V_27 - 1 ) % V_9 ;
while ( V_49 ) {
F_7 ( V_5 . V_32 [ V_50 ] [ V_52 ] == NULL ) ;
F_7 ( V_44 [ V_51 ] [ V_53 ] != NULL ) ;
V_5 . V_32 [ V_50 ] [ V_52 ] = V_44 [ V_51 ] [ V_53 ] ;
V_44 [ V_51 ] [ V_53 ] = NULL ;
V_49 -- ;
if ( ++ V_52 == V_9 ) {
V_50 ++ ;
V_52 = 0 ;
}
if ( -- V_53 < 0 ) {
if ( V_51 == 0 )
break;
V_51 -- ;
V_53 = V_9 - 1 ;
}
}
V_54 = ( V_5 . V_12 + V_9 - 1 ) /
V_9 ;
V_55 = ( V_5 . V_12 + V_27 + V_9 - 1 ) /
V_9 ;
F_7 ( V_55 <= V_5 . V_11 ) ;
V_51 = 0 ;
while ( V_54 < V_55 ) {
F_7 ( V_5 . V_32 [ V_54 ] == NULL ) ;
F_7 ( V_51 < V_45 ) ;
F_7 ( V_44 [ V_51 ] != NULL ) ;
V_5 . V_32 [ V_54 ++ ] = V_44 [ V_51 ] ;
V_44 [ V_51 ++ ] = NULL ;
}
V_5 . V_12 += V_27 ;
V_5 . V_13 += V_27 ;
V_5 . V_23 = V_5 . V_13 ;
if ( V_5 . V_12 > V_5 . V_17 )
V_5 . V_17 = V_5 . V_12 ;
F_15 ( V_42 , L_21 , V_27 ,
V_5 . V_12 ) ;
F_5 ( & V_5 . V_6 ) ;
}
static int F_19 ( int V_27 )
{
static F_20 ( V_57 ) ;
struct V_43 * * * V_44 ;
int V_45 , V_58 = 0 ;
int V_47 , V_48 , V_4 = - V_59 ;
if ( V_27 < V_40 )
V_27 = V_40 ;
F_21 ( & V_57 ) ;
if ( V_27 + V_5 . V_12 > V_5 . V_10 )
V_27 = V_5 . V_10 - V_5 . V_12 ;
F_7 ( V_27 > 0 ) ;
V_5 . V_18 ++ ;
V_45 = F_16 ( V_27 ) ;
F_22 ( V_44 , V_45 * sizeof( * V_44 ) ) ;
if ( V_44 == NULL )
goto V_60;
for ( V_47 = 0 ; V_47 < V_45 ; V_47 ++ ) {
F_22 ( V_44 [ V_47 ] , V_33 ) ;
if ( V_44 [ V_47 ] == NULL )
goto V_61;
for ( V_48 = 0 ; V_48 < V_9 && V_58 < V_27 ; V_48 ++ ) {
V_44 [ V_47 ] [ V_48 ] = F_23 ( V_62 |
V_63 ) ;
if ( V_44 [ V_47 ] [ V_48 ] == NULL )
goto V_61;
V_58 ++ ;
}
}
F_7 ( V_58 == V_27 ) ;
F_18 ( V_44 , V_45 , V_27 ) ;
F_15 ( V_42 , L_22 , V_27 ) ;
V_4 = 0 ;
V_61:
F_17 ( V_44 , V_45 ) ;
F_9 ( V_44 , V_45 * sizeof( * V_44 ) ) ;
V_60:
if ( V_4 ) {
V_5 . V_19 ++ ;
F_24 ( L_23 , V_27 ) ;
}
F_25 ( & V_57 ) ;
return V_4 ;
}
static inline void F_26 ( void )
{
F_7 ( F_27 ( & V_5 . V_6 ) ) ;
F_7 ( V_5 . V_64 >= 0 ) ;
if ( F_11 ( V_5 . V_64 ) ) {
F_7 ( F_28 ( & V_5 . V_65 ) ) ;
F_29 ( & V_5 . V_65 ) ;
}
}
static int F_30 ( int V_66 , long V_67 )
{
if ( V_5 . V_56 ||
V_5 . V_12 == V_5 . V_10 )
return 0 ;
if ( V_5 . V_12 < V_66 )
return 1 ;
#if 0
if (now - page_pools.epp_last_shrink < 2)
return 0;
#endif
return 1 ;
}
int F_31 ( struct V_68 * V_69 )
{
T_1 V_70 ;
unsigned long V_71 = - 1 ;
T_2 V_72 = 0 ;
long V_67 ;
int V_28 , V_29 ;
int V_47 ;
F_7 ( V_69 -> V_73 > 0 ) ;
F_7 ( V_69 -> V_73 <= V_5 . V_10 ) ;
if ( V_69 -> V_74 != NULL )
return 0 ;
F_22 ( V_69 -> V_74 ,
V_69 -> V_73 * sizeof( * V_69 -> V_74 ) ) ;
if ( V_69 -> V_74 == NULL )
return - V_59 ;
F_2 ( & V_5 . V_6 ) ;
V_5 . V_21 ++ ;
V_75:
if ( F_11 ( V_5 . V_13 < V_69 -> V_73 ) ) {
if ( V_72 == 0 )
V_72 = F_32 () ;
V_67 = F_4 () ;
V_5 . V_22 ++ ;
V_5 . V_76 += V_69 -> V_73 ;
if ( F_30 ( V_69 -> V_73 , V_67 ) ) {
V_5 . V_56 = 1 ;
F_5 ( & V_5 . V_6 ) ;
F_19 ( V_5 . V_76 / 2 ) ;
F_2 ( & V_5 . V_6 ) ;
V_5 . V_56 = 0 ;
F_26 () ;
} else {
if ( ++ V_5 . V_64 >
V_5 . V_24 )
V_5 . V_24 =
V_5 . V_64 ;
F_33 ( V_77 ) ;
F_34 ( & V_70 , V_78 ) ;
F_35 ( & V_5 . V_65 , & V_70 ) ;
F_5 ( & V_5 . V_6 ) ;
F_36 () ;
F_37 ( & V_5 . V_65 , & V_70 ) ;
F_7 ( V_5 . V_64 > 0 ) ;
F_2 ( & V_5 . V_6 ) ;
V_5 . V_64 -- ;
}
F_7 ( V_5 . V_76 >= V_69 -> V_73 ) ;
V_5 . V_76 -= V_69 -> V_73 ;
V_71 = 0 ;
goto V_75;
}
if ( F_11 ( V_72 != 0 ) ) {
V_72 = F_32 () - V_72 ;
if ( V_72 > V_5 . V_25 )
V_5 . V_25 = V_72 ;
}
V_5 . V_13 -= V_69 -> V_73 ;
V_28 = V_5 . V_13 / V_9 ;
V_29 = V_5 . V_13 % V_9 ;
for ( V_47 = 0 ; V_47 < V_69 -> V_73 ; V_47 ++ ) {
F_7 ( V_5 . V_32 [ V_28 ] [ V_29 ] != NULL ) ;
V_69 -> V_74 [ V_47 ] . V_79 =
V_5 . V_32 [ V_28 ] [ V_29 ] ;
V_5 . V_32 [ V_28 ] [ V_29 ] = NULL ;
if ( ++ V_29 == V_9 ) {
V_28 ++ ;
V_29 = 0 ;
}
}
if ( V_5 . V_13 < V_5 . V_23 )
V_5 . V_23 = V_5 . V_13 ;
if ( V_71 == - 1 ) {
V_71 = V_5 . V_13 * V_39 /
V_5 . V_12 ;
}
V_5 . V_14 = ( V_5 . V_14 * V_80 +
V_71 ) /
( V_80 + 1 ) ;
V_5 . V_16 = F_4 () ;
F_5 ( & V_5 . V_6 ) ;
return 0 ;
}
void F_38 ( struct V_68 * V_69 )
{
int V_28 , V_29 ;
int V_47 ;
if ( V_69 -> V_74 == NULL )
return;
F_7 ( V_69 -> V_73 > 0 ) ;
F_2 ( & V_5 . V_6 ) ;
V_28 = V_5 . V_13 / V_9 ;
V_29 = V_5 . V_13 % V_9 ;
F_7 ( V_5 . V_13 + V_69 -> V_73 <=
V_5 . V_12 ) ;
F_7 ( V_5 . V_32 [ V_28 ] ) ;
for ( V_47 = 0 ; V_47 < V_69 -> V_73 ; V_47 ++ ) {
F_7 ( V_69 -> V_74 [ V_47 ] . V_79 != NULL ) ;
F_7 ( V_29 != 0 || V_5 . V_32 [ V_28 ] ) ;
F_7 ( V_5 . V_32 [ V_28 ] [ V_29 ] == NULL ) ;
V_5 . V_32 [ V_28 ] [ V_29 ] =
V_69 -> V_74 [ V_47 ] . V_79 ;
if ( ++ V_29 == V_9 ) {
V_28 ++ ;
V_29 = 0 ;
}
}
V_5 . V_13 += V_69 -> V_73 ;
F_26 () ;
F_5 ( & V_5 . V_6 ) ;
F_9 ( V_69 -> V_74 ,
V_69 -> V_73 * sizeof( * V_69 -> V_74 ) ) ;
V_69 -> V_74 = NULL ;
}
int F_39 ( void )
{
int V_81 = 0 ;
F_2 ( & V_5 . V_6 ) ;
if ( V_5 . V_56 == 0 && V_5 . V_12 == 0 ) {
V_5 . V_56 = 1 ;
V_81 = 1 ;
}
F_5 ( & V_5 . V_6 ) ;
if ( V_81 ) {
F_19 ( V_40 +
V_40 ) ;
F_2 ( & V_5 . V_6 ) ;
V_5 . V_56 = 0 ;
F_26 () ;
F_5 ( & V_5 . V_6 ) ;
}
return 0 ;
}
int F_40 ( void )
{
return 0 ;
}
static inline void F_41 ( void )
{
F_7 ( V_5 . V_11 ) ;
F_42 ( V_5 . V_32 ,
V_5 . V_11 *
sizeof( * V_5 . V_32 ) ) ;
}
static inline void F_43 ( void )
{
F_7 ( V_5 . V_11 ) ;
F_7 ( V_5 . V_32 ) ;
F_44 ( V_5 . V_32 ,
V_5 . V_11 *
sizeof( * V_5 . V_32 ) ) ;
}
int F_45 ( void )
{
V_5 . V_10 = V_8 / 8 ;
V_5 . V_11 = F_16 ( V_5 . V_10 ) ;
F_46 ( & V_5 . V_65 ) ;
V_5 . V_64 = 0 ;
V_5 . V_76 = 0 ;
V_5 . V_56 = 0 ;
V_5 . V_14 = 0 ;
V_5 . V_15 = F_4 () ;
V_5 . V_16 = F_4 () ;
F_47 ( & V_5 . V_6 ) ;
V_5 . V_12 = 0 ;
V_5 . V_13 = 0 ;
V_5 . V_17 = 0 ;
V_5 . V_18 = 0 ;
V_5 . V_19 = 0 ;
V_5 . V_20 = 0 ;
V_5 . V_21 = 0 ;
V_5 . V_22 = 0 ;
V_5 . V_23 = 0 ;
V_5 . V_24 = 0 ;
V_5 . V_25 = 0 ;
F_41 () ;
if ( V_5 . V_32 == NULL )
return - V_59 ;
F_48 ( & V_82 ) ;
return 0 ;
}
void F_49 ( void )
{
unsigned long V_46 , V_45 ;
F_7 ( V_5 . V_32 ) ;
F_7 ( V_5 . V_12 == V_5 . V_13 ) ;
F_50 ( & V_82 ) ;
V_45 = F_16 ( V_5 . V_12 ) ;
V_46 = F_17 ( V_5 . V_32 , V_45 ) ;
F_7 ( V_46 == V_5 . V_12 ) ;
F_43 () ;
if ( V_5 . V_21 > 0 ) {
F_15 ( V_42 ,
L_24
L_25
V_7 L_26 ,
V_5 . V_17 , V_5 . V_18 ,
V_5 . V_19 ,
V_5 . V_20 , V_5 . V_21 ,
V_5 . V_22 , V_5 . V_24 ,
V_5 . V_25 , V_26 ) ;
}
}
const char * F_51 ( T_3 V_83 )
{
return F_52 ( V_84 [ V_83 ] ) ;
}
T_3 F_53 ( const char * V_85 )
{
return F_54 ( V_85 ) ;
}
int F_55 ( struct V_86 * V_87 , int V_88 , int V_89 )
{
struct V_90 * V_91 ;
int V_92 = V_87 -> V_93 [ V_88 ] ;
V_91 = F_56 ( V_87 , V_88 , sizeof( * V_91 ) ) ;
if ( V_91 == NULL ) {
F_24 ( L_27 , V_92 ) ;
return - V_94 ;
}
if ( V_89 ) {
F_57 ( & V_91 -> V_95 ) ;
}
if ( F_11 ( V_91 -> V_96 != 0 ) ) {
F_24 ( L_28 , V_91 -> V_96 ) ;
return - V_97 ;
}
if ( F_11 ( V_91 -> V_98 >= V_99 ) ) {
F_24 ( L_29 , V_91 -> V_98 ) ;
return - V_97 ;
}
if ( F_11 ( V_91 -> V_100 != V_101 &&
V_91 -> V_100 != V_102 &&
V_91 -> V_100 != V_103 ) ) {
F_24 ( L_30 , V_91 -> V_100 ) ;
return - V_97 ;
}
return 0 ;
}
int F_58 ( struct V_68 * V_69 , T_3 V_104 ,
void * V_105 , int V_106 )
{
struct V_107 * V_108 ;
int V_109 ;
char V_110 [ 64 ] ;
unsigned int V_111 ;
int V_47 , V_112 ;
F_7 ( V_104 > V_113 && V_104 < V_114 ) ;
F_7 ( V_106 >= 4 ) ;
V_108 = F_59 ( V_84 [ V_104 ] , NULL , 0 ) ;
if ( F_60 ( V_108 ) ) {
F_24 ( L_31 ,
F_52 ( V_84 [ V_104 ] ) ) ;
return F_61 ( V_108 ) ;
}
V_109 = F_62 ( V_84 [ V_104 ] ) ;
for ( V_47 = 0 ; V_47 < V_69 -> V_73 ; V_47 ++ ) {
F_63 ( V_108 , V_69 -> V_115 [ V_47 ] . V_79 ,
V_69 -> V_115 [ V_47 ] . V_116 & ~ V_117 ,
V_69 -> V_115 [ V_47 ] . V_118 ) ;
}
if ( V_109 > V_106 ) {
V_111 = sizeof( V_110 ) ;
V_112 = F_64 ( V_108 , ( unsigned char * ) V_110 ,
& V_111 ) ;
memcpy ( V_105 , V_110 , V_106 ) ;
} else {
V_111 = V_106 ;
V_112 = F_64 ( V_108 , ( unsigned char * ) V_105 ,
& V_111 ) ;
}
if ( V_112 )
F_64 ( V_108 , NULL , NULL ) ;
return V_112 ;
}
