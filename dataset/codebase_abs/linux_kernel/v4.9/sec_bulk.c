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
L_18 ,
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
F_5 ( V_24 ) ) ;
F_6 ( & V_4 . V_5 ) ;
return 0 ;
}
static void F_7 ( long V_25 )
{
int V_26 , V_27 ;
int V_28 , V_29 ;
F_8 ( V_25 > 0 ) ;
F_8 ( V_25 <= V_4 . V_11 ) ;
F_8 ( V_4 . V_11 <= V_4 . V_10 ) ;
V_29 = ( V_4 . V_10 - 1 ) / V_7 ;
V_4 . V_11 -= V_25 ;
V_4 . V_10 -= V_25 ;
V_28 = V_4 . V_10 == 0 ? - 1 :
( ( V_4 . V_10 - 1 ) / V_7 ) ;
V_26 = V_4 . V_11 / V_7 ;
V_27 = V_4 . V_11 % V_7 ;
F_8 ( V_4 . V_30 [ V_26 ] ) ;
while ( V_25 -- ) {
F_8 ( V_4 . V_30 [ V_26 ] ) ;
F_8 ( V_4 . V_30 [ V_26 ] [ V_27 ] ) ;
F_9 ( V_4 . V_30 [ V_26 ] [ V_27 ] ) ;
V_4 . V_30 [ V_26 ] [ V_27 ] = NULL ;
if ( ++ V_27 == V_7 ) {
V_26 ++ ;
V_27 = 0 ;
}
}
while ( V_28 < V_29 ) {
F_8 ( V_4 . V_30 [ V_29 ] ) ;
F_10 ( V_4 . V_30 [ V_29 ] ) ;
V_4 . V_30 [ V_29 ] = NULL ;
V_29 -- ;
}
}
static unsigned long F_11 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
if ( F_12 ( F_4 () - V_4 . V_14 >
V_35 ) ) {
F_2 ( & V_4 . V_5 ) ;
V_4 . V_12 = V_36 ;
F_6 ( & V_4 . V_5 ) ;
}
F_8 ( V_4 . V_12 <= V_36 ) ;
return F_13 ( ( int ) V_4 . V_11 - V_37 , 0 ) *
( V_36 - V_4 . V_12 ) / V_36 ;
}
static unsigned long F_14 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
F_2 ( & V_4 . V_5 ) ;
V_34 -> V_38 = F_15 (unsigned long, sc->nr_to_scan,
page_pools.epp_free_pages - PTLRPC_MAX_BRW_PAGES) ;
if ( V_34 -> V_38 > 0 ) {
F_7 ( V_34 -> V_38 ) ;
F_16 ( V_39 , L_19 ,
( long ) V_34 -> V_38 , V_4 . V_11 ) ;
V_4 . V_18 ++ ;
V_4 . V_13 = F_4 () ;
}
F_6 ( & V_4 . V_5 ) ;
if ( F_12 ( F_4 () - V_4 . V_14 >
V_35 ) ) {
F_2 ( & V_4 . V_5 ) ;
V_4 . V_12 = V_36 ;
F_6 ( & V_4 . V_5 ) ;
}
F_8 ( V_4 . V_12 <= V_36 ) ;
return V_34 -> V_38 ;
}
static inline
int F_17 ( unsigned long V_25 )
{
return ( int ) ( ( V_25 + V_7 - 1 ) / V_7 ) ;
}
static unsigned long F_18 ( struct V_40 * * * V_41 , int V_42 )
{
unsigned long V_43 = 0 ;
int V_44 , V_45 ;
for ( V_44 = 0 ; V_44 < V_42 ; V_44 ++ ) {
if ( V_41 [ V_44 ] ) {
for ( V_45 = 0 ; V_45 < V_7 ; V_45 ++ ) {
if ( V_41 [ V_44 ] [ V_45 ] ) {
F_9 ( V_41 [ V_44 ] [ V_45 ] ) ;
V_43 ++ ;
}
}
F_10 ( V_41 [ V_44 ] ) ;
V_41 [ V_44 ] = NULL ;
}
}
return V_43 ;
}
static inline void F_19 ( void )
{
F_20 ( & V_4 . V_5 ) ;
if ( F_12 ( V_4 . V_46 ) ) {
F_8 ( F_21 ( & V_4 . V_47 ) ) ;
F_22 ( & V_4 . V_47 ) ;
}
}
void F_23 ( struct V_48 * V_49 )
{
int V_26 , V_27 ;
int V_44 ;
if ( ! V_49 -> V_50 )
return;
F_8 ( V_49 -> V_51 > 0 ) ;
F_2 ( & V_4 . V_5 ) ;
V_26 = V_4 . V_11 / V_7 ;
V_27 = V_4 . V_11 % V_7 ;
F_8 ( V_4 . V_11 + V_49 -> V_51 <=
V_4 . V_10 ) ;
F_8 ( V_4 . V_30 [ V_26 ] ) ;
for ( V_44 = 0 ; V_44 < V_49 -> V_51 ; V_44 ++ ) {
F_8 ( V_49 -> V_50 [ V_44 ] . V_52 ) ;
F_8 ( V_27 != 0 || V_4 . V_30 [ V_26 ] ) ;
F_8 ( ! V_4 . V_30 [ V_26 ] [ V_27 ] ) ;
V_4 . V_30 [ V_26 ] [ V_27 ] =
V_49 -> V_50 [ V_44 ] . V_52 ;
if ( ++ V_27 == V_7 ) {
V_26 ++ ;
V_27 = 0 ;
}
}
V_4 . V_11 += V_49 -> V_51 ;
F_19 () ;
F_6 ( & V_4 . V_5 ) ;
F_10 ( V_49 -> V_50 ) ;
V_49 -> V_50 = NULL ;
}
static inline void F_24 ( void )
{
F_8 ( V_4 . V_9 ) ;
V_4 . V_30 =
F_25 ( V_4 . V_9 *
sizeof( * V_4 . V_30 ) ,
V_53 ) ;
}
static inline void F_26 ( void )
{
F_8 ( V_4 . V_9 ) ;
F_8 ( V_4 . V_30 ) ;
F_27 ( V_4 . V_30 ) ;
}
int F_28 ( void )
{
V_4 . V_8 = V_6 / 8 ;
V_4 . V_9 = F_17 ( V_4 . V_8 ) ;
F_29 ( & V_4 . V_47 ) ;
V_4 . V_46 = 0 ;
V_4 . V_54 = 0 ;
V_4 . V_55 = 0 ;
V_4 . V_12 = 0 ;
V_4 . V_13 = F_4 () ;
V_4 . V_14 = F_4 () ;
F_30 ( & V_4 . V_5 ) ;
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
F_24 () ;
if ( ! V_4 . V_30 )
return - V_56 ;
F_31 ( & V_57 ) ;
return 0 ;
}
void F_32 ( void )
{
unsigned long V_43 , V_42 ;
F_8 ( V_4 . V_30 ) ;
F_8 ( V_4 . V_10 == V_4 . V_11 ) ;
F_33 ( & V_57 ) ;
V_42 = F_17 ( V_4 . V_10 ) ;
V_43 = F_18 ( V_4 . V_30 , V_42 ) ;
F_8 ( V_43 == V_4 . V_10 ) ;
F_26 () ;
if ( V_4 . V_19 > 0 ) {
F_16 ( V_39 ,
L_20 ,
V_4 . V_15 , V_4 . V_16 ,
V_4 . V_17 ,
V_4 . V_18 , V_4 . V_19 ,
V_4 . V_20 , V_4 . V_22 ,
V_4 . V_23 ,
F_5 ( V_24 ) ) ;
}
}
const char * F_34 ( T_1 V_58 )
{
return F_35 ( V_59 [ V_58 ] ) ;
}
T_1 F_36 ( const char * V_60 )
{
return F_37 ( V_60 ) ;
}
int F_38 ( struct V_61 * V_62 , int V_63 , int V_64 )
{
struct V_65 * V_66 ;
int V_67 = V_62 -> V_68 [ V_63 ] ;
V_66 = F_39 ( V_62 , V_63 , sizeof( * V_66 ) ) ;
if ( ! V_66 ) {
F_40 ( L_21 , V_67 ) ;
return - V_69 ;
}
if ( V_64 )
F_41 ( & V_66 -> V_70 ) ;
if ( F_12 ( V_66 -> V_71 != 0 ) ) {
F_40 ( L_22 , V_66 -> V_71 ) ;
return - V_72 ;
}
if ( F_12 ( V_66 -> V_73 >= V_74 ) ) {
F_40 ( L_23 , V_66 -> V_73 ) ;
return - V_72 ;
}
if ( F_12 ( V_66 -> V_75 != V_76 &&
V_66 -> V_75 != V_77 &&
V_66 -> V_75 != V_78 ) ) {
F_40 ( L_24 , V_66 -> V_75 ) ;
return - V_72 ;
}
return 0 ;
}
int F_42 ( struct V_48 * V_49 , T_1 V_79 ,
void * V_80 , int V_81 )
{
struct V_82 * V_83 ;
int V_84 ;
unsigned int V_85 ;
int V_44 , V_86 ;
F_8 ( V_79 > V_87 && V_79 < V_88 ) ;
F_8 ( V_81 >= 4 ) ;
V_83 = F_43 ( V_59 [ V_79 ] , NULL , 0 ) ;
if ( F_44 ( V_83 ) ) {
F_40 ( L_25 ,
F_35 ( V_59 [ V_79 ] ) ) ;
return F_45 ( V_83 ) ;
}
V_84 = F_46 ( V_59 [ V_79 ] ) ;
for ( V_44 = 0 ; V_44 < V_49 -> V_51 ; V_44 ++ ) {
F_47 ( V_83 , V_49 -> V_89 [ V_44 ] . V_52 ,
V_49 -> V_89 [ V_44 ] . V_90 &
~ V_91 ,
V_49 -> V_89 [ V_44 ] . V_92 ) ;
}
if ( V_84 > V_81 ) {
unsigned char V_93 [ V_94 ] ;
V_85 = sizeof( V_93 ) ;
F_48 ( V_85 >= V_84 , L_26 ,
V_85 , V_84 ) ;
V_86 = F_49 ( V_83 , V_93 , & V_85 ) ;
memcpy ( V_80 , V_93 , V_81 ) ;
} else {
V_85 = V_81 ;
V_86 = F_49 ( V_83 , V_80 , & V_85 ) ;
}
return V_86 ;
}
