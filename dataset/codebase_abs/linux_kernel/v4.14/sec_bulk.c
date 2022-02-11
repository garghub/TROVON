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
L_18
L_19 ,
V_6 ,
V_7 ,
V_4 . V_8 ,
V_4 . V_9 ,
V_4 . V_10 ,
V_4 . V_11 ,
V_4 . V_12 ,
( long ) ( F_4 () - V_4 . V_13 ) ,
( long ) ( F_4 () - V_4 . V_14 ) ,
V_4 . V_15 ,
V_4 . V_16 ,
V_4 . V_17 ,
V_4 . V_18 ,
V_4 . V_19 ,
V_4 . V_20 ,
V_4 . V_21 ,
V_4 . V_22 ,
V_4 . V_23 ,
F_5 ( V_24 ) ,
V_4 . V_25 ) ;
F_6 ( & V_4 . V_5 ) ;
return 0 ;
}
static void F_7 ( long V_26 )
{
int V_27 , V_28 ;
int V_29 , V_30 ;
F_8 ( V_26 > 0 ) ;
F_8 ( V_26 <= V_4 . V_11 ) ;
F_8 ( V_4 . V_11 <= V_4 . V_10 ) ;
V_30 = ( V_4 . V_10 - 1 ) / V_7 ;
V_4 . V_11 -= V_26 ;
V_4 . V_10 -= V_26 ;
V_29 = V_4 . V_10 == 0 ? - 1 :
( ( V_4 . V_10 - 1 ) / V_7 ) ;
V_27 = V_4 . V_11 / V_7 ;
V_28 = V_4 . V_11 % V_7 ;
F_8 ( V_4 . V_31 [ V_27 ] ) ;
while ( V_26 -- ) {
F_8 ( V_4 . V_31 [ V_27 ] ) ;
F_8 ( V_4 . V_31 [ V_27 ] [ V_28 ] ) ;
F_9 ( V_4 . V_31 [ V_27 ] [ V_28 ] ) ;
V_4 . V_31 [ V_27 ] [ V_28 ] = NULL ;
if ( ++ V_28 == V_7 ) {
V_27 ++ ;
V_28 = 0 ;
}
}
while ( V_29 < V_30 ) {
F_8 ( V_4 . V_31 [ V_30 ] ) ;
F_10 ( V_4 . V_31 [ V_30 ] ) ;
V_4 . V_31 [ V_30 ] = NULL ;
V_30 -- ;
}
}
static unsigned long F_11 ( struct V_32 * V_33 ,
struct V_34 * V_35 )
{
if ( F_12 ( F_4 () - V_4 . V_14 >
V_36 ) ) {
F_2 ( & V_4 . V_5 ) ;
V_4 . V_12 = V_37 ;
F_6 ( & V_4 . V_5 ) ;
}
F_8 ( V_4 . V_12 <= V_37 ) ;
return F_13 ( ( int ) V_4 . V_11 - V_38 , 0 ) *
( V_37 - V_4 . V_12 ) / V_37 ;
}
static unsigned long F_14 ( struct V_32 * V_33 ,
struct V_34 * V_35 )
{
F_2 ( & V_4 . V_5 ) ;
V_35 -> V_39 = F_15 (unsigned long, sc->nr_to_scan,
page_pools.epp_free_pages - PTLRPC_MAX_BRW_PAGES) ;
if ( V_35 -> V_39 > 0 ) {
F_7 ( V_35 -> V_39 ) ;
F_16 ( V_40 , L_20 ,
( long ) V_35 -> V_39 , V_4 . V_11 ) ;
V_4 . V_18 ++ ;
V_4 . V_13 = F_4 () ;
}
F_6 ( & V_4 . V_5 ) ;
if ( F_12 ( F_4 () - V_4 . V_14 >
V_36 ) ) {
F_2 ( & V_4 . V_5 ) ;
V_4 . V_12 = V_37 ;
F_6 ( & V_4 . V_5 ) ;
}
F_8 ( V_4 . V_12 <= V_37 ) ;
return V_35 -> V_39 ;
}
static inline
int F_17 ( unsigned long V_26 )
{
return ( int ) F_18 ( V_26 , V_7 ) ;
}
static unsigned long F_19 ( struct V_41 * * * V_42 , int V_43 )
{
unsigned long V_44 = 0 ;
int V_45 , V_46 ;
for ( V_45 = 0 ; V_45 < V_43 ; V_45 ++ ) {
if ( V_42 [ V_45 ] ) {
for ( V_46 = 0 ; V_46 < V_7 ; V_46 ++ ) {
if ( V_42 [ V_45 ] [ V_46 ] ) {
F_9 ( V_42 [ V_45 ] [ V_46 ] ) ;
V_44 ++ ;
}
}
F_10 ( V_42 [ V_45 ] ) ;
V_42 [ V_45 ] = NULL ;
}
}
return V_44 ;
}
static inline void F_20 ( void )
{
F_21 ( & V_4 . V_5 ) ;
if ( F_12 ( V_4 . V_47 ) ) {
F_8 ( F_22 ( & V_4 . V_48 ) ) ;
F_23 ( & V_4 . V_48 ) ;
}
}
int F_24 ( void )
{
return V_4 . V_11 ;
}
int F_25 ( void )
{
return ( V_4 . V_10 == V_4 . V_8 ) ;
}
void F_26 ( struct V_49 * V_50 )
{
int V_27 , V_28 ;
int V_45 ;
F_8 ( F_27 ( V_50 -> V_51 ) ) ;
if ( ! F_28 ( V_50 ) )
return;
F_8 ( V_50 -> V_52 > 0 ) ;
F_2 ( & V_4 . V_5 ) ;
V_27 = V_4 . V_11 / V_7 ;
V_28 = V_4 . V_11 % V_7 ;
F_8 ( V_4 . V_11 + V_50 -> V_52 <=
V_4 . V_10 ) ;
F_8 ( V_4 . V_31 [ V_27 ] ) ;
for ( V_45 = 0 ; V_45 < V_50 -> V_52 ; V_45 ++ ) {
F_8 ( F_29 ( V_50 , V_45 ) . V_53 ) ;
F_8 ( V_28 != 0 || V_4 . V_31 [ V_27 ] ) ;
F_8 ( ! V_4 . V_31 [ V_27 ] [ V_28 ] ) ;
V_4 . V_31 [ V_27 ] [ V_28 ] =
F_29 ( V_50 , V_45 ) . V_53 ;
if ( ++ V_28 == V_7 ) {
V_27 ++ ;
V_28 = 0 ;
}
}
V_4 . V_11 += V_50 -> V_52 ;
F_20 () ;
F_6 ( & V_4 . V_5 ) ;
F_10 ( F_28 ( V_50 ) ) ;
F_28 ( V_50 ) = NULL ;
}
static inline void F_30 ( void )
{
F_8 ( V_4 . V_9 ) ;
V_4 . V_31 =
F_31 ( V_4 . V_9 *
sizeof( * V_4 . V_31 ) ,
V_54 ) ;
}
static inline void F_32 ( void )
{
F_8 ( V_4 . V_9 ) ;
F_8 ( V_4 . V_31 ) ;
F_33 ( V_4 . V_31 ) ;
}
int F_34 ( void )
{
V_4 . V_8 = V_6 / 8 ;
V_4 . V_9 = F_17 ( V_4 . V_8 ) ;
F_35 ( & V_4 . V_48 ) ;
V_4 . V_47 = 0 ;
V_4 . V_55 = 0 ;
V_4 . V_56 = 0 ;
V_4 . V_12 = 0 ;
V_4 . V_13 = F_4 () ;
V_4 . V_14 = F_4 () ;
F_36 ( & V_4 . V_5 ) ;
V_4 . V_10 = 0 ;
V_4 . V_11 = 0 ;
V_4 . V_15 = 0 ;
V_4 . V_16 = 0 ;
V_4 . V_17 = 0 ;
V_4 . V_18 = 0 ;
V_4 . V_19 = 0 ;
V_4 . V_20 = 0 ;
V_4 . V_21 = 0 ;
V_4 . V_22 = 0 ;
V_4 . V_23 = 0 ;
V_4 . V_25 = 0 ;
F_30 () ;
if ( ! V_4 . V_31 )
return - V_57 ;
F_37 ( & V_58 ) ;
return 0 ;
}
void F_38 ( void )
{
unsigned long V_44 , V_43 ;
F_8 ( V_4 . V_31 ) ;
F_8 ( V_4 . V_10 == V_4 . V_11 ) ;
F_39 ( & V_58 ) ;
V_43 = F_17 ( V_4 . V_10 ) ;
V_44 = F_19 ( V_4 . V_31 , V_43 ) ;
F_8 ( V_44 == V_4 . V_10 ) ;
F_32 () ;
if ( V_4 . V_19 > 0 ) {
F_16 ( V_40 ,
L_21 ,
V_4 . V_15 , V_4 . V_16 ,
V_4 . V_17 ,
V_4 . V_18 , V_4 . V_19 ,
V_4 . V_20 , V_4 . V_22 ,
V_4 . V_23 ,
F_5 ( V_24 ) ,
V_4 . V_25 ) ;
}
}
const char * F_40 ( T_1 V_59 )
{
return F_41 ( V_60 [ V_59 ] ) ;
}
T_1 F_42 ( const char * V_61 )
{
return F_43 ( V_61 ) ;
}
int F_44 ( struct V_62 * V_63 , int V_64 , int V_65 )
{
struct V_66 * V_67 ;
int V_68 = V_63 -> V_69 [ V_64 ] ;
V_67 = F_45 ( V_63 , V_64 , sizeof( * V_67 ) ) ;
if ( ! V_67 ) {
F_46 ( L_22 , V_68 ) ;
return - V_70 ;
}
if ( V_65 )
F_47 ( & V_67 -> V_71 ) ;
if ( F_12 ( V_67 -> V_72 != 0 ) ) {
F_46 ( L_23 , V_67 -> V_72 ) ;
return - V_73 ;
}
if ( F_12 ( V_67 -> V_74 >= V_75 ) ) {
F_46 ( L_24 , V_67 -> V_74 ) ;
return - V_73 ;
}
if ( F_12 ( V_67 -> V_76 != V_77 &&
V_67 -> V_76 != V_78 &&
V_67 -> V_76 != V_79 ) ) {
F_46 ( L_25 , V_67 -> V_76 ) ;
return - V_73 ;
}
return 0 ;
}
int F_48 ( struct V_49 * V_50 , T_1 V_80 ,
void * V_81 , int V_82 )
{
struct V_83 * V_84 ;
int V_85 ;
unsigned int V_86 ;
int V_45 , V_87 ;
F_8 ( V_80 > V_88 && V_80 < V_89 ) ;
F_8 ( V_82 >= 4 ) ;
V_84 = F_49 ( V_60 [ V_80 ] , NULL , 0 ) ;
if ( F_50 ( V_84 ) ) {
F_46 ( L_26 ,
F_41 ( V_60 [ V_80 ] ) ) ;
return F_51 ( V_84 ) ;
}
V_85 = F_52 ( V_60 [ V_80 ] ) ;
for ( V_45 = 0 ; V_45 < V_50 -> V_52 ; V_45 ++ ) {
F_53 ( V_84 ,
F_54 ( V_50 , V_45 ) . V_53 ,
F_54 ( V_50 , V_45 ) . V_90 &
~ V_91 ,
F_54 ( V_50 , V_45 ) . V_92 ) ;
}
if ( V_85 > V_82 ) {
unsigned char V_93 [ V_94 ] ;
V_86 = sizeof( V_93 ) ;
F_55 ( V_86 >= V_85 , L_27 ,
V_86 , V_85 ) ;
V_87 = F_56 ( V_84 , V_93 , & V_86 ) ;
memcpy ( V_81 , V_93 , V_82 ) ;
} else {
V_86 = V_82 ;
V_87 = F_56 ( V_84 , V_81 , & V_86 ) ;
}
return V_87 ;
}
