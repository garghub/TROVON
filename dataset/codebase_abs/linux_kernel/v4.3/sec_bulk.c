int F_1 ( struct V_1 * V_2 , void * V_3 )
{
F_2 ( & V_4 . V_5 ) ;
F_3 ( V_2 ,
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
L_18 V_6 L_19 ,
V_7 ,
V_8 ,
V_4 . V_9 ,
V_4 . V_10 ,
V_4 . V_11 ,
V_4 . V_12 ,
V_4 . V_13 ,
F_4 () - V_4 . V_14 ,
F_4 () - V_4 . V_15 ,
V_4 . V_16 ,
V_4 . V_17 ,
V_4 . V_18 ,
V_4 . V_19 ,
V_4 . V_20 ,
V_4 . V_21 ,
V_4 . V_22 ,
V_4 . V_23 ,
V_4 . V_24 ,
V_25 ) ;
F_5 ( & V_4 . V_5 ) ;
return 0 ;
}
static void F_6 ( long V_26 )
{
int V_27 , V_28 ;
int V_29 , V_30 ;
F_7 ( V_26 > 0 ) ;
F_7 ( V_26 <= V_4 . V_12 ) ;
F_7 ( V_4 . V_12 <= V_4 . V_11 ) ;
V_30 = ( V_4 . V_11 - 1 ) / V_8 ;
V_4 . V_12 -= V_26 ;
V_4 . V_11 -= V_26 ;
V_29 = V_4 . V_11 == 0 ? - 1 :
( ( V_4 . V_11 - 1 ) / V_8 ) ;
V_27 = V_4 . V_12 / V_8 ;
V_28 = V_4 . V_12 % V_8 ;
F_7 ( V_4 . V_31 [ V_27 ] ) ;
while ( V_26 -- ) {
F_7 ( V_4 . V_31 [ V_27 ] ) ;
F_7 ( V_4 . V_31 [ V_27 ] [ V_28 ] != NULL ) ;
F_8 ( V_4 . V_31 [ V_27 ] [ V_28 ] ) ;
V_4 . V_31 [ V_27 ] [ V_28 ] = NULL ;
if ( ++ V_28 == V_8 ) {
V_27 ++ ;
V_28 = 0 ;
}
}
while ( V_29 < V_30 ) {
F_7 ( V_4 . V_31 [ V_30 ] ) ;
F_9 ( V_4 . V_31 [ V_30 ] ) ;
V_4 . V_31 [ V_30 ] = NULL ;
V_30 -- ;
}
}
static unsigned long F_10 ( struct V_32 * V_33 ,
struct V_34 * V_35 )
{
if ( F_11 ( F_4 () - V_4 . V_15 >
V_36 ) ) {
F_2 ( & V_4 . V_5 ) ;
V_4 . V_13 = V_37 ;
F_5 ( & V_4 . V_5 ) ;
}
F_7 ( V_4 . V_13 <= V_37 ) ;
return F_12 ( ( int ) V_4 . V_12 - V_38 , 0 ) *
( V_37 - V_4 . V_13 ) / V_37 ;
}
static unsigned long F_13 ( struct V_32 * V_33 ,
struct V_34 * V_35 )
{
F_2 ( & V_4 . V_5 ) ;
V_35 -> V_39 = F_14 (unsigned long, sc->nr_to_scan,
page_pools.epp_free_pages - PTLRPC_MAX_BRW_PAGES) ;
if ( V_35 -> V_39 > 0 ) {
F_6 ( V_35 -> V_39 ) ;
F_15 ( V_40 , L_20 ,
( long ) V_35 -> V_39 , V_4 . V_12 ) ;
V_4 . V_19 ++ ;
V_4 . V_14 = F_4 () ;
}
F_5 ( & V_4 . V_5 ) ;
if ( F_11 ( F_4 () - V_4 . V_15 >
V_36 ) ) {
F_2 ( & V_4 . V_5 ) ;
V_4 . V_13 = V_37 ;
F_5 ( & V_4 . V_5 ) ;
}
F_7 ( V_4 . V_13 <= V_37 ) ;
return V_35 -> V_39 ;
}
static inline
int F_16 ( unsigned long V_26 )
{
return ( int ) ( ( V_26 + V_8 - 1 ) / V_8 ) ;
}
static unsigned long F_17 ( struct V_41 * * * V_42 , int V_43 )
{
unsigned long V_44 = 0 ;
int V_45 , V_46 ;
for ( V_45 = 0 ; V_45 < V_43 ; V_45 ++ ) {
if ( V_42 [ V_45 ] ) {
for ( V_46 = 0 ; V_46 < V_8 ; V_46 ++ ) {
if ( V_42 [ V_45 ] [ V_46 ] ) {
F_8 ( V_42 [ V_45 ] [ V_46 ] ) ;
V_44 ++ ;
}
}
F_9 ( V_42 [ V_45 ] ) ;
V_42 [ V_45 ] = NULL ;
}
}
return V_44 ;
}
static void F_18 ( struct V_41 * * * V_42 , int V_43 , int V_26 )
{
int V_47 ;
int V_48 , V_49 , V_50 , V_51 ;
int V_52 , V_53 ;
F_7 ( V_26 > 0 ) ;
F_7 ( V_4 . V_11 + V_26 <= V_4 . V_9 ) ;
F_7 ( F_16 ( V_26 ) == V_43 ) ;
F_7 ( V_4 . V_54 ) ;
F_2 ( & V_4 . V_5 ) ;
V_47 = V_4 . V_11 % V_8 ;
if ( V_47 != 0 )
V_47 = V_8 - V_47 ;
V_47 += V_4 . V_11 - V_4 . V_12 ;
V_48 = V_4 . V_12 / V_8 ;
V_50 = V_4 . V_12 % V_8 ;
V_49 = V_43 - 1 ;
V_51 = ( V_26 - 1 ) % V_8 ;
while ( V_47 ) {
F_7 ( V_4 . V_31 [ V_48 ] [ V_50 ] == NULL ) ;
F_7 ( V_42 [ V_49 ] [ V_51 ] != NULL ) ;
V_4 . V_31 [ V_48 ] [ V_50 ] = V_42 [ V_49 ] [ V_51 ] ;
V_42 [ V_49 ] [ V_51 ] = NULL ;
V_47 -- ;
if ( ++ V_50 == V_8 ) {
V_48 ++ ;
V_50 = 0 ;
}
if ( -- V_51 < 0 ) {
if ( V_49 == 0 )
break;
V_49 -- ;
V_51 = V_8 - 1 ;
}
}
V_52 = ( V_4 . V_11 + V_8 - 1 ) /
V_8 ;
V_53 = ( V_4 . V_11 + V_26 + V_8 - 1 )
/ V_8 ;
F_7 ( V_53 <= V_4 . V_10 ) ;
V_49 = 0 ;
while ( V_52 < V_53 ) {
F_7 ( V_4 . V_31 [ V_52 ] == NULL ) ;
F_7 ( V_49 < V_43 ) ;
F_7 ( V_42 [ V_49 ] != NULL ) ;
V_4 . V_31 [ V_52 ++ ] = V_42 [ V_49 ] ;
V_42 [ V_49 ++ ] = NULL ;
}
V_4 . V_11 += V_26 ;
V_4 . V_12 += V_26 ;
V_4 . V_22 = V_4 . V_12 ;
if ( V_4 . V_11 > V_4 . V_16 )
V_4 . V_16 = V_4 . V_11 ;
F_15 ( V_40 , L_21 , V_26 ,
V_4 . V_11 ) ;
F_5 ( & V_4 . V_5 ) ;
}
static int F_19 ( int V_26 )
{
static F_20 ( V_55 ) ;
struct V_41 * * * V_42 ;
int V_43 , V_56 = 0 ;
int V_45 , V_46 , V_57 = - V_58 ;
if ( V_26 < V_38 )
V_26 = V_38 ;
F_21 ( & V_55 ) ;
if ( V_26 + V_4 . V_11 > V_4 . V_9 )
V_26 = V_4 . V_9 - V_4 . V_11 ;
F_7 ( V_26 > 0 ) ;
V_4 . V_17 ++ ;
V_43 = F_16 ( V_26 ) ;
V_42 = F_22 ( V_43 , sizeof( * V_42 ) , V_59 ) ;
if ( V_42 == NULL )
goto V_60;
for ( V_45 = 0 ; V_45 < V_43 ; V_45 ++ ) {
V_42 [ V_45 ] = F_23 ( V_61 , V_59 ) ;
if ( ! V_42 [ V_45 ] )
goto V_62;
for ( V_46 = 0 ; V_46 < V_8 && V_56 < V_26 ; V_46 ++ ) {
V_42 [ V_45 ] [ V_46 ] = F_24 ( V_59 |
V_63 ) ;
if ( V_42 [ V_45 ] [ V_46 ] == NULL )
goto V_62;
V_56 ++ ;
}
}
F_7 ( V_56 == V_26 ) ;
F_18 ( V_42 , V_43 , V_26 ) ;
F_15 ( V_40 , L_22 , V_26 ) ;
V_57 = 0 ;
V_62:
F_17 ( V_42 , V_43 ) ;
F_9 ( V_42 ) ;
V_60:
if ( V_57 ) {
V_4 . V_18 ++ ;
F_25 ( L_23 , V_26 ) ;
}
F_26 ( & V_55 ) ;
return V_57 ;
}
static inline void F_27 ( void )
{
F_28 ( & V_4 . V_5 ) ;
F_7 ( V_4 . V_64 >= 0 ) ;
if ( F_11 ( V_4 . V_64 ) ) {
F_7 ( F_29 ( & V_4 . V_65 ) ) ;
F_30 ( & V_4 . V_65 ) ;
}
}
static int F_31 ( int V_66 , long V_67 )
{
if ( V_4 . V_54 ||
V_4 . V_11 == V_4 . V_9 )
return 0 ;
if ( V_4 . V_11 < V_66 )
return 1 ;
#if 0
if (now - page_pools.epp_last_shrink < 2)
return 0;
#endif
return 1 ;
}
int F_32 ( struct V_68 * V_69 )
{
T_1 V_70 ;
unsigned long V_71 = - 1 ;
unsigned long V_72 = 0 ;
long V_67 ;
int V_27 , V_28 ;
int V_45 ;
F_7 ( V_69 -> V_73 > 0 ) ;
F_7 ( V_69 -> V_73 <= V_4 . V_9 ) ;
if ( V_69 -> V_74 != NULL )
return 0 ;
V_69 -> V_74 = F_22 ( V_69 -> V_73 ,
sizeof( * V_69 -> V_74 ) , V_59 ) ;
if ( V_69 -> V_74 == NULL )
return - V_58 ;
F_2 ( & V_4 . V_5 ) ;
V_4 . V_20 ++ ;
V_75:
if ( F_11 ( V_4 . V_12 < V_69 -> V_73 ) ) {
if ( V_72 == 0 )
V_72 = F_33 () ;
V_67 = F_4 () ;
V_4 . V_21 ++ ;
V_4 . V_76 += V_69 -> V_73 ;
if ( F_31 ( V_69 -> V_73 , V_67 ) ) {
V_4 . V_54 = 1 ;
F_5 ( & V_4 . V_5 ) ;
F_19 ( V_4 . V_76 / 2 ) ;
F_2 ( & V_4 . V_5 ) ;
V_4 . V_54 = 0 ;
F_27 () ;
} else {
if ( ++ V_4 . V_64 >
V_4 . V_23 )
V_4 . V_23 =
V_4 . V_64 ;
F_34 ( V_77 ) ;
F_35 ( & V_70 , V_78 ) ;
F_36 ( & V_4 . V_65 , & V_70 ) ;
F_5 ( & V_4 . V_5 ) ;
F_37 () ;
F_38 ( & V_4 . V_65 , & V_70 ) ;
F_7 ( V_4 . V_64 > 0 ) ;
F_2 ( & V_4 . V_5 ) ;
V_4 . V_64 -- ;
}
F_7 ( V_4 . V_76 >= V_69 -> V_73 ) ;
V_4 . V_76 -= V_69 -> V_73 ;
V_71 = 0 ;
goto V_75;
}
if ( F_11 ( V_72 != 0 ) ) {
V_72 = F_33 () - V_72 ;
if ( V_72 > V_4 . V_24 )
V_4 . V_24 = V_72 ;
}
V_4 . V_12 -= V_69 -> V_73 ;
V_27 = V_4 . V_12 / V_8 ;
V_28 = V_4 . V_12 % V_8 ;
for ( V_45 = 0 ; V_45 < V_69 -> V_73 ; V_45 ++ ) {
F_7 ( V_4 . V_31 [ V_27 ] [ V_28 ] != NULL ) ;
V_69 -> V_74 [ V_45 ] . V_79 =
V_4 . V_31 [ V_27 ] [ V_28 ] ;
V_4 . V_31 [ V_27 ] [ V_28 ] = NULL ;
if ( ++ V_28 == V_8 ) {
V_27 ++ ;
V_28 = 0 ;
}
}
if ( V_4 . V_12 < V_4 . V_22 )
V_4 . V_22 = V_4 . V_12 ;
if ( V_71 == - 1 ) {
V_71 = V_4 . V_12 * V_37 /
V_4 . V_11 ;
}
V_4 . V_13 = ( V_4 . V_13 * V_80 +
V_71 ) /
( V_80 + 1 ) ;
V_4 . V_15 = F_4 () ;
F_5 ( & V_4 . V_5 ) ;
return 0 ;
}
void F_39 ( struct V_68 * V_69 )
{
int V_27 , V_28 ;
int V_45 ;
if ( V_69 -> V_74 == NULL )
return;
F_7 ( V_69 -> V_73 > 0 ) ;
F_2 ( & V_4 . V_5 ) ;
V_27 = V_4 . V_12 / V_8 ;
V_28 = V_4 . V_12 % V_8 ;
F_7 ( V_4 . V_12 + V_69 -> V_73 <=
V_4 . V_11 ) ;
F_7 ( V_4 . V_31 [ V_27 ] ) ;
for ( V_45 = 0 ; V_45 < V_69 -> V_73 ; V_45 ++ ) {
F_7 ( V_69 -> V_74 [ V_45 ] . V_79 != NULL ) ;
F_7 ( V_28 != 0 || V_4 . V_31 [ V_27 ] ) ;
F_7 ( V_4 . V_31 [ V_27 ] [ V_28 ] == NULL ) ;
V_4 . V_31 [ V_27 ] [ V_28 ] =
V_69 -> V_74 [ V_45 ] . V_79 ;
if ( ++ V_28 == V_8 ) {
V_27 ++ ;
V_28 = 0 ;
}
}
V_4 . V_12 += V_69 -> V_73 ;
F_27 () ;
F_5 ( & V_4 . V_5 ) ;
F_9 ( V_69 -> V_74 ) ;
V_69 -> V_74 = NULL ;
}
int F_40 ( void )
{
int V_81 = 0 ;
F_2 ( & V_4 . V_5 ) ;
if ( V_4 . V_54 == 0 && V_4 . V_11 == 0 ) {
V_4 . V_54 = 1 ;
V_81 = 1 ;
}
F_5 ( & V_4 . V_5 ) ;
if ( V_81 ) {
F_19 ( V_38 +
V_38 ) ;
F_2 ( & V_4 . V_5 ) ;
V_4 . V_54 = 0 ;
F_27 () ;
F_5 ( & V_4 . V_5 ) ;
}
return 0 ;
}
int F_41 ( void )
{
return 0 ;
}
static inline void F_42 ( void )
{
F_7 ( V_4 . V_10 ) ;
V_4 . V_31 =
F_43 ( V_4 . V_10 *
sizeof( * V_4 . V_31 ) ,
V_59 ) ;
}
static inline void F_44 ( void )
{
F_7 ( V_4 . V_10 ) ;
F_7 ( V_4 . V_31 ) ;
F_45 ( V_4 . V_31 ) ;
}
int F_46 ( void )
{
V_4 . V_9 = V_7 / 8 ;
V_4 . V_10 = F_16 ( V_4 . V_9 ) ;
F_47 ( & V_4 . V_65 ) ;
V_4 . V_64 = 0 ;
V_4 . V_76 = 0 ;
V_4 . V_54 = 0 ;
V_4 . V_13 = 0 ;
V_4 . V_14 = F_4 () ;
V_4 . V_15 = F_4 () ;
F_48 ( & V_4 . V_5 ) ;
V_4 . V_11 = 0 ;
V_4 . V_12 = 0 ;
V_4 . V_16 = 0 ;
V_4 . V_17 = 0 ;
V_4 . V_18 = 0 ;
V_4 . V_19 = 0 ;
V_4 . V_20 = 0 ;
V_4 . V_21 = 0 ;
V_4 . V_22 = 0 ;
V_4 . V_23 = 0 ;
V_4 . V_24 = 0 ;
F_42 () ;
if ( V_4 . V_31 == NULL )
return - V_58 ;
F_49 ( & V_82 ) ;
return 0 ;
}
void F_50 ( void )
{
unsigned long V_44 , V_43 ;
F_7 ( V_4 . V_31 ) ;
F_7 ( V_4 . V_11 == V_4 . V_12 ) ;
F_51 ( & V_82 ) ;
V_43 = F_16 ( V_4 . V_11 ) ;
V_44 = F_17 ( V_4 . V_31 , V_43 ) ;
F_7 ( V_44 == V_4 . V_11 ) ;
F_44 () ;
if ( V_4 . V_20 > 0 ) {
F_15 ( V_40 ,
L_24
V_6 L_25 ,
V_4 . V_16 , V_4 . V_17 ,
V_4 . V_18 ,
V_4 . V_19 , V_4 . V_20 ,
V_4 . V_21 , V_4 . V_23 ,
V_4 . V_24 , V_25 ) ;
}
}
const char * F_52 ( T_2 V_83 )
{
return F_53 ( V_84 [ V_83 ] ) ;
}
T_2 F_54 ( const char * V_85 )
{
return F_55 ( V_85 ) ;
}
int F_56 ( struct V_86 * V_87 , int V_88 , int V_89 )
{
struct V_90 * V_91 ;
int V_92 = V_87 -> V_93 [ V_88 ] ;
V_91 = F_57 ( V_87 , V_88 , sizeof( * V_91 ) ) ;
if ( V_91 == NULL ) {
F_25 ( L_26 , V_92 ) ;
return - V_94 ;
}
if ( V_89 )
F_58 ( & V_91 -> V_95 ) ;
if ( F_11 ( V_91 -> V_96 != 0 ) ) {
F_25 ( L_27 , V_91 -> V_96 ) ;
return - V_97 ;
}
if ( F_11 ( V_91 -> V_98 >= V_99 ) ) {
F_25 ( L_28 , V_91 -> V_98 ) ;
return - V_97 ;
}
if ( F_11 ( V_91 -> V_100 != V_101 &&
V_91 -> V_100 != V_102 &&
V_91 -> V_100 != V_103 ) ) {
F_25 ( L_29 , V_91 -> V_100 ) ;
return - V_97 ;
}
return 0 ;
}
int F_59 ( struct V_68 * V_69 , T_2 V_104 ,
void * V_105 , int V_106 )
{
struct V_107 * V_108 ;
int V_109 ;
char V_110 [ 64 ] ;
unsigned int V_111 ;
int V_45 , V_112 ;
F_7 ( V_104 > V_113 && V_104 < V_114 ) ;
F_7 ( V_106 >= 4 ) ;
V_108 = F_60 ( V_84 [ V_104 ] , NULL , 0 ) ;
if ( F_61 ( V_108 ) ) {
F_25 ( L_30 ,
F_53 ( V_84 [ V_104 ] ) ) ;
return F_62 ( V_108 ) ;
}
V_109 = F_63 ( V_84 [ V_104 ] ) ;
for ( V_45 = 0 ; V_45 < V_69 -> V_73 ; V_45 ++ ) {
F_64 ( V_108 , V_69 -> V_115 [ V_45 ] . V_79 ,
V_69 -> V_115 [ V_45 ] . V_116 & ~ V_117 ,
V_69 -> V_115 [ V_45 ] . V_118 ) ;
}
if ( V_109 > V_106 ) {
V_111 = sizeof( V_110 ) ;
V_112 = F_65 ( V_108 , ( unsigned char * ) V_110 ,
& V_111 ) ;
memcpy ( V_105 , V_110 , V_106 ) ;
} else {
V_111 = V_106 ;
V_112 = F_65 ( V_108 , ( unsigned char * ) V_105 ,
& V_111 ) ;
}
if ( V_112 )
F_65 ( V_108 , NULL , NULL ) ;
return V_112 ;
}
