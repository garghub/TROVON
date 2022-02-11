void F_1 ( void )
{
V_1 = true ;
}
static inline void F_2 ( void )
{
V_2 = V_1 ;
}
static inline void F_3 ( void )
{
V_2 = false ;
}
static inline void F_4 ( void * V_3 )
{
if ( V_2 )
F_5 ( ( unsigned long ) V_3 , 1 ) ;
}
static inline void F_6 ( void * V_3 )
{
if ( V_2 )
F_7 ( ( unsigned long ) V_3 , 1 ) ;
}
static inline void F_2 ( void ) {}
static inline void F_3 ( void ) {}
static inline void F_4 ( void * V_3 ) {}
static inline void F_6 ( void * V_3 ) {}
void T_1 F_8 ( void )
{
V_4 = V_5 * V_6 ;
}
void T_1 F_9 ( void )
{
V_7 = ( ( V_8 * 2 ) / 5 ) * V_6 ;
}
static void * F_10 ( T_2 V_9 , int V_10 )
{
void * V_11 ;
V_11 = ( void * ) F_11 ( V_9 ) ;
if ( V_10 )
while ( V_11 && F_12 ( F_13 ( V_11 ) ) ) {
F_14 ( F_13 ( V_11 ) ) ;
V_12 ++ ;
V_11 = ( void * ) F_11 ( V_9 ) ;
}
if ( V_11 ) {
F_14 ( F_13 ( V_11 ) ) ;
F_15 ( F_13 ( V_11 ) ) ;
}
return V_11 ;
}
static void * F_16 ( T_2 V_9 )
{
if ( V_13 ) {
void * V_14 = V_13 ;
V_13 = V_13 -> V_15 ;
memset ( V_14 , 0 , V_6 ) ;
return V_14 ;
}
return F_10 ( V_9 , V_16 ) ;
}
unsigned long F_17 ( T_2 V_9 )
{
return ( unsigned long ) F_16 ( V_9 ) ;
}
static struct V_17 * F_18 ( T_2 V_9 )
{
struct V_17 * V_17 ;
V_17 = F_19 ( V_9 ) ;
if ( V_17 ) {
F_14 ( V_17 ) ;
F_15 ( V_17 ) ;
}
return V_17 ;
}
static void F_20 ( void * V_3 )
{
struct V_18 * V_19 = V_3 ;
V_19 -> V_15 = V_13 ;
V_13 = V_19 ;
}
static inline void F_21 ( void * V_20 , int V_21 )
{
struct V_17 * V_17 ;
F_22 ( ! F_23 ( V_20 ) ) ;
V_17 = F_13 ( V_20 ) ;
F_24 ( V_17 ) ;
if ( V_21 )
F_25 ( V_17 ) ;
F_26 ( V_17 ) ;
}
static inline void F_27 ( struct V_18 * V_22 ,
int V_23 )
{
while ( V_22 ) {
struct V_18 * V_19 = V_22 -> V_15 ;
F_21 ( V_22 , V_23 ) ;
V_22 = V_19 ;
}
}
static void F_28 ( struct V_24 * V_25 , T_2 V_9 ,
int V_10 )
{
V_25 -> V_26 = NULL ;
V_25 -> V_27 = V_28 ;
V_25 -> V_9 = V_9 ;
V_25 -> V_10 = V_10 ;
}
static void * F_29 ( struct V_24 * V_25 , unsigned int V_29 )
{
void * V_14 ;
if ( V_28 - V_25 -> V_27 < V_29 ) {
struct V_18 * V_19 ;
V_19 = V_25 -> V_10 ? F_16 ( V_25 -> V_9 ) :
F_10 ( V_25 -> V_9 , V_30 ) ;
if ( ! V_19 )
return NULL ;
V_19 -> V_15 = V_25 -> V_26 ;
V_25 -> V_26 = V_19 ;
V_25 -> V_27 = 0 ;
}
V_14 = V_25 -> V_26 -> V_31 + V_25 -> V_27 ;
V_25 -> V_27 += V_29 ;
return V_14 ;
}
static struct V_32 * F_30 ( T_2 V_9 , int V_10 ,
struct V_24 * V_25 ,
struct V_33 * V_22 )
{
struct V_32 * V_34 ;
V_34 = F_29 ( V_25 , sizeof( struct V_32 ) ) ;
if ( ! V_34 )
return NULL ;
V_34 -> V_31 = F_10 ( V_9 , V_10 ) ;
if ( ! V_34 -> V_31 )
return NULL ;
F_31 ( & V_34 -> V_22 , V_22 ) ;
return V_34 ;
}
static int F_32 ( struct V_35 * V_36 , T_2 V_9 ,
int V_10 , struct V_24 * V_25 )
{
struct V_32 * V_34 , * V_37 , * * V_38 ;
unsigned int V_39 , V_40 ;
int V_41 ;
V_40 = V_36 -> V_42 ;
V_39 = 0 ;
while ( V_40 ) {
V_39 += 1 ;
V_40 >>= V_43 ;
}
for ( V_41 = V_36 -> V_44 ; V_41 < V_39 ; V_41 ++ ) {
V_34 = F_30 ( V_9 , V_10 , V_25 ,
& V_36 -> V_45 ) ;
if ( ! V_34 )
return - V_46 ;
V_34 -> V_31 [ 0 ] = ( unsigned long ) V_36 -> V_47 ;
V_36 -> V_47 = V_34 ;
V_36 -> V_44 += 1 ;
}
V_37 = F_30 ( V_9 , V_10 , V_25 , & V_36 -> V_48 ) ;
if ( ! V_37 )
return - V_46 ;
V_34 = V_36 -> V_47 ;
V_38 = & V_36 -> V_47 ;
V_40 = V_36 -> V_42 ;
for ( V_41 = V_36 -> V_44 ; V_41 > 0 ; V_41 -- ) {
int V_49 ;
if ( ! V_34 ) {
V_34 = F_30 ( V_9 , V_10 , V_25 ,
& V_36 -> V_45 ) ;
if ( ! V_34 )
return - V_46 ;
* V_38 = V_34 ;
}
V_49 = V_40 >> ( ( V_41 - 1 ) * V_43 ) ;
V_49 &= V_50 ;
V_38 = (struct V_32 * * ) & ( ( * V_38 ) -> V_31 [ V_49 ] ) ;
V_34 = * V_38 ;
}
V_36 -> V_42 += 1 ;
* V_38 = V_37 ;
return 0 ;
}
static struct V_35 * F_33 ( T_2 V_9 ,
int V_10 ,
struct V_24 * V_25 ,
unsigned long V_51 ,
unsigned long V_52 )
{
struct V_35 * V_36 ;
unsigned int V_41 , V_53 ;
unsigned long V_54 ;
V_54 = V_52 - V_51 ;
V_36 = F_29 ( V_25 , sizeof( struct V_35 ) ) ;
if ( ! V_36 )
return NULL ;
F_34 ( & V_36 -> V_45 ) ;
F_34 ( & V_36 -> V_48 ) ;
V_36 -> V_55 = V_51 ;
V_36 -> V_56 = V_52 ;
V_53 = F_35 ( V_54 , V_57 ) ;
for ( V_41 = 0 ; V_41 < V_53 ; V_41 ++ ) {
if ( F_32 ( V_36 , V_9 , V_10 , V_25 ) ) {
F_36 ( V_36 , V_58 ) ;
return NULL ;
}
}
return V_36 ;
}
static void F_36 ( struct V_35 * V_36 ,
int V_21 )
{
struct V_32 * V_34 ;
F_37 (node, &zone->nodes, list)
F_21 ( V_34 -> V_31 , V_21 ) ;
F_37 (node, &zone->leaves, list)
F_21 ( V_34 -> V_31 , V_21 ) ;
}
static void F_38 ( struct V_59 * V_60 )
{
V_60 -> V_61 . V_36 = F_39 ( V_60 -> V_62 . V_15 , struct V_35 ,
V_22 ) ;
V_60 -> V_61 . V_34 = F_39 ( V_60 -> V_61 . V_36 -> V_48 . V_15 ,
struct V_32 , V_22 ) ;
V_60 -> V_61 . V_63 = 0 ;
V_60 -> V_61 . V_64 = 0 ;
}
static void F_40 ( struct V_33 * V_22 )
{
struct V_65 * V_66 , * V_67 ;
F_41 (ext, aux, list, hook) {
F_42 ( & V_66 -> V_68 ) ;
F_43 ( V_66 ) ;
}
}
static int F_44 ( struct V_33 * V_22 , T_2 V_9 )
{
struct V_36 * V_36 ;
F_34 ( V_22 ) ;
F_45 (zone) {
unsigned long V_69 , V_70 ;
struct V_65 * V_66 , * V_61 , * V_67 ;
V_69 = V_36 -> V_71 ;
V_70 = F_46 ( V_36 ) ;
F_37 (ext, list, hook)
if ( V_69 <= V_66 -> V_52 )
break;
if ( & V_66 -> V_68 == V_22 || V_70 < V_66 -> V_51 ) {
struct V_65 * V_72 ;
V_72 = F_47 ( sizeof( struct V_65 ) , V_9 ) ;
if ( ! V_72 ) {
F_40 ( V_22 ) ;
return - V_46 ;
}
V_72 -> V_51 = V_69 ;
V_72 -> V_52 = V_70 ;
F_31 ( & V_72 -> V_68 , & V_66 -> V_68 ) ;
continue;
}
if ( V_69 < V_66 -> V_51 )
V_66 -> V_51 = V_69 ;
if ( V_70 > V_66 -> V_52 )
V_66 -> V_52 = V_70 ;
V_61 = V_66 ;
F_48 (cur, aux, list, hook) {
if ( V_70 < V_61 -> V_51 )
break;
if ( V_70 < V_61 -> V_52 )
V_66 -> V_52 = V_61 -> V_52 ;
F_42 ( & V_61 -> V_68 ) ;
F_43 ( V_61 ) ;
}
}
return 0 ;
}
static int F_49 ( struct V_59 * V_60 , T_2 V_9 ,
int V_10 )
{
struct V_24 V_25 ;
struct V_33 V_73 ;
struct V_65 * V_66 ;
int error ;
F_28 ( & V_25 , V_9 , V_10 ) ;
F_34 ( & V_60 -> V_62 ) ;
error = F_44 ( & V_73 , V_9 ) ;
if ( error )
return error ;
F_37 (ext, &mem_extents, hook) {
struct V_35 * V_36 ;
V_36 = F_33 ( V_9 , V_10 , & V_25 ,
V_66 -> V_51 , V_66 -> V_52 ) ;
if ( ! V_36 ) {
error = - V_46 ;
goto Error;
}
F_31 ( & V_36 -> V_22 , & V_60 -> V_62 ) ;
}
V_60 -> V_74 = V_25 . V_26 ;
F_38 ( V_60 ) ;
Exit:
F_40 ( & V_73 ) ;
return error ;
Error:
V_60 -> V_74 = V_25 . V_26 ;
F_50 ( V_60 , V_58 ) ;
goto Exit;
}
static void F_50 ( struct V_59 * V_60 , int V_21 )
{
struct V_35 * V_36 ;
F_37 (zone, &bm->zones, list)
F_36 ( V_36 , V_21 ) ;
F_27 ( V_60 -> V_74 , V_21 ) ;
F_34 ( & V_60 -> V_62 ) ;
}
static int F_51 ( struct V_59 * V_60 , unsigned long V_75 ,
void * * V_20 , unsigned int * V_76 )
{
struct V_35 * V_77 , * V_36 ;
struct V_32 * V_34 ;
int V_41 , V_40 ;
V_36 = V_60 -> V_61 . V_36 ;
if ( V_75 >= V_36 -> V_55 && V_75 < V_36 -> V_56 )
goto V_78;
V_36 = NULL ;
F_37 (curr, &bm->zones, list) {
if ( V_75 >= V_77 -> V_55 && V_75 < V_77 -> V_56 ) {
V_36 = V_77 ;
break;
}
}
if ( ! V_36 )
return - V_79 ;
V_78:
V_34 = V_60 -> V_61 . V_34 ;
if ( ( ( V_75 - V_36 -> V_55 ) & ~ V_80 ) == V_60 -> V_61 . V_63 )
goto V_81;
V_34 = V_36 -> V_47 ;
V_40 = ( V_75 - V_36 -> V_55 ) >> V_82 ;
for ( V_41 = V_36 -> V_44 ; V_41 > 0 ; V_41 -- ) {
int V_49 ;
V_49 = V_40 >> ( ( V_41 - 1 ) * V_43 ) ;
V_49 &= V_50 ;
F_22 ( V_34 -> V_31 [ V_49 ] == 0 ) ;
V_34 = (struct V_32 * ) V_34 -> V_31 [ V_49 ] ;
}
V_81:
V_60 -> V_61 . V_36 = V_36 ;
V_60 -> V_61 . V_34 = V_34 ;
V_60 -> V_61 . V_63 = ( V_75 - V_36 -> V_55 ) & ~ V_80 ;
* V_20 = V_34 -> V_31 ;
* V_76 = ( V_75 - V_36 -> V_55 ) & V_80 ;
return 0 ;
}
static void F_52 ( struct V_59 * V_60 , unsigned long V_75 )
{
void * V_20 ;
unsigned int V_83 ;
int error ;
error = F_51 ( V_60 , V_75 , & V_20 , & V_83 ) ;
F_22 ( error ) ;
F_53 ( V_83 , V_20 ) ;
}
static int F_54 ( struct V_59 * V_60 , unsigned long V_75 )
{
void * V_20 ;
unsigned int V_83 ;
int error ;
error = F_51 ( V_60 , V_75 , & V_20 , & V_83 ) ;
if ( ! error )
F_53 ( V_83 , V_20 ) ;
return error ;
}
static void F_55 ( struct V_59 * V_60 , unsigned long V_75 )
{
void * V_20 ;
unsigned int V_83 ;
int error ;
error = F_51 ( V_60 , V_75 , & V_20 , & V_83 ) ;
F_22 ( error ) ;
F_56 ( V_83 , V_20 ) ;
}
static void F_57 ( struct V_59 * V_60 )
{
int V_83 ;
V_83 = F_58 ( V_60 -> V_61 . V_64 - 1 , 0 ) ;
F_56 ( V_83 , V_60 -> V_61 . V_34 -> V_31 ) ;
}
static int F_59 ( struct V_59 * V_60 , unsigned long V_75 )
{
void * V_20 ;
unsigned int V_83 ;
int error ;
error = F_51 ( V_60 , V_75 , & V_20 , & V_83 ) ;
F_22 ( error ) ;
return F_60 ( V_83 , V_20 ) ;
}
static bool F_61 ( struct V_59 * V_60 , unsigned long V_75 )
{
void * V_20 ;
unsigned int V_83 ;
return ! F_51 ( V_60 , V_75 , & V_20 , & V_83 ) ;
}
static bool F_62 ( struct V_59 * V_60 )
{
if ( ! F_63 ( & V_60 -> V_61 . V_34 -> V_22 , & V_60 -> V_61 . V_36 -> V_48 ) ) {
V_60 -> V_61 . V_34 = F_39 ( V_60 -> V_61 . V_34 -> V_22 . V_15 ,
struct V_32 , V_22 ) ;
V_60 -> V_61 . V_63 += V_57 ;
V_60 -> V_61 . V_64 = 0 ;
F_64 () ;
return true ;
}
if ( ! F_63 ( & V_60 -> V_61 . V_36 -> V_22 , & V_60 -> V_62 ) ) {
V_60 -> V_61 . V_36 = F_39 ( V_60 -> V_61 . V_36 -> V_22 . V_15 ,
struct V_35 , V_22 ) ;
V_60 -> V_61 . V_34 = F_39 ( V_60 -> V_61 . V_36 -> V_48 . V_15 ,
struct V_32 , V_22 ) ;
V_60 -> V_61 . V_63 = 0 ;
V_60 -> V_61 . V_64 = 0 ;
return true ;
}
return false ;
}
static unsigned long F_65 ( struct V_59 * V_60 )
{
unsigned long V_84 , V_75 , V_54 ;
int V_83 ;
do {
V_54 = V_60 -> V_61 . V_36 -> V_56 - V_60 -> V_61 . V_36 -> V_55 ;
V_84 = F_66 ( V_54 - V_60 -> V_61 . V_63 , V_57 ) ;
V_83 = F_67 ( V_60 -> V_61 . V_34 -> V_31 , V_84 ,
V_60 -> V_61 . V_64 ) ;
if ( V_83 < V_84 ) {
V_75 = V_60 -> V_61 . V_36 -> V_55 + V_60 -> V_61 . V_63 + V_83 ;
V_60 -> V_61 . V_64 = V_83 + 1 ;
return V_75 ;
}
} while ( F_62 ( V_60 ) );
return V_85 ;
}
static void F_68 ( struct V_35 * V_36 )
{
struct V_32 * V_34 ;
F_37 (node, &zone->nodes, list)
F_20 ( V_34 -> V_31 ) ;
F_37 (node, &zone->leaves, list)
F_20 ( V_34 -> V_31 ) ;
}
static void F_69 ( struct V_59 * V_60 )
{
struct V_35 * V_36 ;
struct V_18 * V_74 ;
F_37 (zone, &bm->zones, list)
F_68 ( V_36 ) ;
V_74 = V_60 -> V_74 ;
while ( V_74 ) {
struct V_18 * V_19 = V_74 ;
V_74 = V_19 -> V_15 ;
F_20 ( V_19 ) ;
}
}
void T_1 F_70 ( unsigned long V_55 ,
unsigned long V_56 , int V_86 )
{
struct V_87 * V_88 ;
if ( V_55 >= V_56 )
return;
if ( ! F_71 ( & V_89 ) ) {
V_88 = F_39 ( V_89 . V_90 ,
struct V_87 , V_22 ) ;
if ( V_88 -> V_56 == V_55 ) {
V_88 -> V_56 = V_56 ;
goto V_91;
}
}
if ( V_86 ) {
V_88 = F_72 ( sizeof( struct V_87 ) , V_92 ) ;
F_22 ( ! V_88 ) ;
} else {
V_88 = F_73 ( sizeof( struct V_87 ) , 0 ) ;
}
V_88 -> V_55 = V_55 ;
V_88 -> V_56 = V_56 ;
F_31 ( & V_88 -> V_22 , & V_89 ) ;
V_91:
F_74 ( V_93 L_1 ,
( unsigned long long ) V_55 << V_94 ,
( ( unsigned long long ) V_56 << V_94 ) - 1 ) ;
}
void F_15 ( struct V_17 * V_17 )
{
if ( V_95 )
F_52 ( V_95 , F_75 ( V_17 ) ) ;
}
static int F_12 ( struct V_17 * V_17 )
{
return V_95 ?
F_59 ( V_95 , F_75 ( V_17 ) ) : 0 ;
}
void F_25 ( struct V_17 * V_17 )
{
if ( V_95 )
F_55 ( V_95 , F_75 ( V_17 ) ) ;
}
static void F_14 ( struct V_17 * V_17 )
{
if ( V_96 )
F_52 ( V_96 , F_75 ( V_17 ) ) ;
}
int F_76 ( struct V_17 * V_17 )
{
return V_96 ?
F_59 ( V_96 , F_75 ( V_17 ) ) : 0 ;
}
static void F_24 ( struct V_17 * V_17 )
{
if ( V_96 )
F_55 ( V_96 , F_75 ( V_17 ) ) ;
}
static void F_77 ( struct V_59 * V_60 )
{
struct V_87 * V_88 ;
if ( F_71 ( & V_89 ) )
return;
F_37 (region, &nosave_regions, list) {
unsigned long V_75 ;
F_78 ( L_2 ,
( unsigned long long ) V_88 -> V_55 << V_94 ,
( ( unsigned long long ) V_88 -> V_56 << V_94 )
- 1 ) ;
for ( V_75 = V_88 -> V_55 ; V_75 < V_88 -> V_56 ; V_75 ++ )
if ( F_79 ( V_75 ) ) {
F_54 ( V_60 , V_75 ) ;
}
}
}
int F_80 ( void )
{
struct V_59 * V_97 , * V_98 ;
int error = 0 ;
if ( V_96 && V_95 )
return 0 ;
else
F_22 ( V_96 || V_95 ) ;
V_97 = F_47 ( sizeof( struct V_59 ) , V_92 ) ;
if ( ! V_97 )
return - V_46 ;
error = F_49 ( V_97 , V_92 , V_30 ) ;
if ( error )
goto V_99;
V_98 = F_47 ( sizeof( struct V_59 ) , V_92 ) ;
if ( ! V_98 )
goto V_100;
error = F_49 ( V_98 , V_92 , V_30 ) ;
if ( error )
goto V_101;
V_96 = V_97 ;
V_95 = V_98 ;
F_77 ( V_96 ) ;
F_78 ( L_3 ) ;
return 0 ;
V_101:
F_43 ( V_98 ) ;
V_100:
F_50 ( V_97 , V_58 ) ;
V_99:
F_43 ( V_97 ) ;
return - V_46 ;
}
void F_81 ( void )
{
struct V_59 * V_97 , * V_98 ;
if ( F_82 ( ! ( V_96 && V_95 ) ) )
return;
V_97 = V_96 ;
V_98 = V_95 ;
V_96 = NULL ;
V_95 = NULL ;
F_50 ( V_97 , V_58 ) ;
F_43 ( V_97 ) ;
F_50 ( V_98 , V_58 ) ;
F_43 ( V_98 ) ;
F_78 ( L_4 ) ;
}
void F_83 ( void )
{
#ifdef F_84
struct V_59 * V_60 = V_95 ;
unsigned long V_75 ;
if ( F_82 ( ! ( V_95 ) ) )
return;
F_38 ( V_60 ) ;
V_75 = F_65 ( V_60 ) ;
while ( V_75 != V_85 ) {
if ( F_79 ( V_75 ) )
F_85 ( F_86 ( V_75 ) ) ;
V_75 = F_65 ( V_60 ) ;
}
F_38 ( V_60 ) ;
F_87 ( L_5 ) ;
#endif
}
unsigned int F_88 ( struct V_36 * V_36 )
{
unsigned int V_47 , V_45 ;
V_47 = V_45 = F_35 ( V_36 -> V_102 , V_57 ) ;
V_47 += F_35 ( V_47 * sizeof( struct V_32 ) ,
V_28 ) ;
while ( V_45 > 1 ) {
V_45 = F_35 ( V_45 , V_103 ) ;
V_47 += V_45 ;
}
return 2 * V_47 ;
}
static unsigned int F_89 ( void )
{
struct V_36 * V_36 ;
unsigned int V_104 = 0 ;
F_45 (zone)
if ( F_90 ( V_36 ) )
V_104 += F_91 ( V_36 , V_105 ) ;
return V_104 ;
}
static struct V_17 * F_92 ( struct V_36 * V_36 , unsigned long V_75 )
{
struct V_17 * V_17 ;
if ( ! F_79 ( V_75 ) )
return NULL ;
V_17 = F_86 ( V_75 ) ;
if ( F_93 ( V_17 ) != V_36 )
return NULL ;
F_22 ( ! F_94 ( V_17 ) ) ;
if ( F_76 ( V_17 ) || F_12 ( V_17 ) ||
F_95 ( V_17 ) )
return NULL ;
if ( F_96 ( V_17 ) )
return NULL ;
return V_17 ;
}
static unsigned int F_97 ( void )
{
struct V_36 * V_36 ;
unsigned int V_106 = 0 ;
F_45 (zone) {
unsigned long V_75 , V_107 ;
if ( ! F_90 ( V_36 ) )
continue;
F_98 ( V_36 ) ;
V_107 = F_46 ( V_36 ) ;
for ( V_75 = V_36 -> V_71 ; V_75 < V_107 ; V_75 ++ )
if ( F_92 ( V_36 , V_75 ) )
V_106 ++ ;
}
return V_106 ;
}
static inline void * F_92 ( struct V_36 * V_108 , unsigned long V_109 )
{
return NULL ;
}
static struct V_17 * F_99 ( struct V_36 * V_36 , unsigned long V_75 )
{
struct V_17 * V_17 ;
if ( ! F_79 ( V_75 ) )
return NULL ;
V_17 = F_86 ( V_75 ) ;
if ( F_93 ( V_17 ) != V_36 )
return NULL ;
F_22 ( F_94 ( V_17 ) ) ;
if ( F_76 ( V_17 ) || F_12 ( V_17 ) )
return NULL ;
if ( F_95 ( V_17 )
&& ( ! F_100 ( V_17 ) || F_101 ( V_75 ) ) )
return NULL ;
if ( F_96 ( V_17 ) )
return NULL ;
return V_17 ;
}
static unsigned int F_102 ( void )
{
struct V_36 * V_36 ;
unsigned long V_75 , V_107 ;
unsigned int V_106 = 0 ;
F_45 (zone) {
if ( F_90 ( V_36 ) )
continue;
F_98 ( V_36 ) ;
V_107 = F_46 ( V_36 ) ;
for ( V_75 = V_36 -> V_71 ; V_75 < V_107 ; V_75 ++ )
if ( F_99 ( V_36 , V_75 ) )
V_106 ++ ;
}
return V_106 ;
}
static inline void F_103 ( long * V_38 , long * V_110 )
{
int V_106 ;
for ( V_106 = V_6 / sizeof( long ) ; V_106 ; V_106 -- )
* V_38 ++ = * V_110 ++ ;
}
static void F_104 ( void * V_38 , struct V_17 * V_111 )
{
if ( F_100 ( V_111 ) ) {
F_103 ( V_38 , V_3 ( V_111 ) ) ;
} else {
F_105 ( V_111 , 1 , 1 ) ;
F_103 ( V_38 , V_3 ( V_111 ) ) ;
F_105 ( V_111 , 1 , 0 ) ;
}
}
static inline struct V_17 * F_106 ( struct V_36 * V_36 , unsigned long V_75 )
{
return F_90 ( V_36 ) ?
F_92 ( V_36 , V_75 ) : F_99 ( V_36 , V_75 ) ;
}
static void F_107 ( unsigned long V_112 , unsigned long V_113 )
{
struct V_17 * V_111 , * V_114 ;
void * V_110 , * V_38 ;
V_111 = F_86 ( V_113 ) ;
V_114 = F_86 ( V_112 ) ;
if ( F_94 ( V_111 ) ) {
V_110 = F_108 ( V_111 ) ;
V_38 = F_108 ( V_114 ) ;
F_103 ( V_38 , V_110 ) ;
F_109 ( V_38 ) ;
F_109 ( V_110 ) ;
} else {
if ( F_94 ( V_114 ) ) {
F_104 ( V_115 , V_111 ) ;
V_38 = F_108 ( V_114 ) ;
F_110 ( V_38 , V_115 ) ;
F_109 ( V_38 ) ;
} else {
F_104 ( V_3 ( V_114 ) , V_111 ) ;
}
}
}
static inline void F_107 ( unsigned long V_112 , unsigned long V_113 )
{
F_104 ( V_3 ( F_86 ( V_112 ) ) ,
F_86 ( V_113 ) ) ;
}
static void F_111 ( struct V_59 * V_116 ,
struct V_59 * V_117 )
{
struct V_36 * V_36 ;
unsigned long V_75 ;
F_45 (zone) {
unsigned long V_107 ;
F_98 ( V_36 ) ;
V_107 = F_46 ( V_36 ) ;
for ( V_75 = V_36 -> V_71 ; V_75 < V_107 ; V_75 ++ )
if ( F_106 ( V_36 , V_75 ) )
F_52 ( V_117 , V_75 ) ;
}
F_38 ( V_117 ) ;
F_38 ( V_116 ) ;
for(; ; ) {
V_75 = F_65 ( V_117 ) ;
if ( F_112 ( V_75 == V_85 ) )
break;
F_107 ( F_65 ( V_116 ) , V_75 ) ;
}
}
void F_113 ( void )
{
unsigned long V_118 , V_119 ;
if ( ! V_96 || ! V_95 )
goto V_120;
F_38 ( V_96 ) ;
F_38 ( V_95 ) ;
V_121:
V_119 = F_65 ( V_95 ) ;
V_118 = F_65 ( V_96 ) ;
do {
if ( V_118 < V_119 )
V_118 = F_65 ( V_96 ) ;
if ( V_119 < V_118 )
V_119 = F_65 ( V_95 ) ;
} while ( V_118 != V_119 );
if ( V_119 != V_85 && F_79 ( V_119 ) ) {
struct V_17 * V_17 = F_86 ( V_119 ) ;
F_57 ( V_96 ) ;
F_57 ( V_95 ) ;
F_6 ( V_3 ( V_17 ) ) ;
F_26 ( V_17 ) ;
goto V_121;
}
V_120:
V_122 = 0 ;
V_123 = 0 ;
V_124 = NULL ;
V_115 = NULL ;
V_125 = 0 ;
V_126 = 0 ;
F_3 () ;
}
static unsigned long F_114 ( unsigned long V_127 , T_2 V_128 )
{
unsigned long V_129 = 0 ;
while ( V_127 > 0 ) {
struct V_17 * V_17 ;
V_17 = F_18 ( V_128 ) ;
if ( ! V_17 )
break;
F_52 ( & V_116 , F_75 ( V_17 ) ) ;
if ( F_94 ( V_17 ) )
V_126 ++ ;
else
V_125 ++ ;
V_127 -- ;
V_129 ++ ;
}
return V_129 ;
}
static unsigned long F_115 ( unsigned long V_127 ,
unsigned long V_130 )
{
unsigned long V_131 ;
if ( V_130 <= V_125 )
return 0 ;
V_131 = V_130 - V_125 ;
if ( V_127 < V_131 )
V_131 = V_127 ;
return F_114 ( V_131 , V_132 ) ;
}
static unsigned long F_116 ( unsigned long V_127 )
{
return F_114 ( V_127 , V_132 | V_133 ) ;
}
static unsigned long F_117 ( T_3 V_134 , T_3 V_135 , T_3 V_136 )
{
V_134 *= V_135 ;
F_118 ( V_134 , V_136 ) ;
return ( unsigned long ) V_134 ;
}
static unsigned long F_119 ( unsigned long V_127 ,
unsigned long V_137 ,
unsigned long V_138 )
{
unsigned long V_131 = F_117 ( V_127 , V_137 , V_138 ) ;
return F_114 ( V_131 , V_132 | V_133 ) ;
}
static inline unsigned long F_116 ( unsigned long V_127 )
{
return 0 ;
}
static inline unsigned long F_119 ( unsigned long V_127 ,
unsigned long V_137 ,
unsigned long V_138 )
{
return 0 ;
}
static unsigned long F_120 ( void )
{
unsigned long V_139 , V_140 , V_141 , free ;
V_139 = F_102 () ;
if ( V_125 >= V_139 ) {
V_140 = V_125 - V_139 ;
V_139 = 0 ;
} else {
V_140 = 0 ;
V_139 -= V_125 ;
}
V_139 += F_97 () ;
if ( V_126 >= V_139 ) {
V_141 = V_126 - V_139 ;
} else {
V_141 = 0 ;
V_139 -= V_126 ;
if ( V_140 > V_139 )
V_140 -= V_139 ;
else
V_140 = 0 ;
}
free = V_140 + V_141 ;
F_38 ( & V_116 ) ;
while ( V_140 > 0 || V_141 > 0 ) {
unsigned long V_75 = F_65 ( & V_116 ) ;
struct V_17 * V_17 = F_86 ( V_75 ) ;
if ( F_94 ( V_17 ) ) {
if ( ! V_141 )
continue;
V_141 -- ;
V_126 -- ;
} else {
if ( ! V_140 )
continue;
V_140 -- ;
V_125 -- ;
}
F_55 ( & V_116 , V_75 ) ;
F_24 ( V_17 ) ;
F_25 ( V_17 ) ;
F_26 ( V_17 ) ;
}
return free ;
}
static unsigned long F_121 ( unsigned long V_142 )
{
unsigned long V_29 ;
V_29 = F_122 ( V_143 )
+ F_122 ( V_144 )
+ F_122 ( V_145 )
+ F_122 ( V_146 )
+ F_122 ( V_147 )
- F_122 ( V_148 ) ;
return V_142 <= V_29 ? 0 : V_142 - V_29 ;
}
int F_123 ( void )
{
struct V_36 * V_36 ;
unsigned long V_142 , V_29 , V_149 , V_150 , V_137 , V_54 = 0 ;
unsigned long V_131 , V_151 , V_152 , V_130 ;
T_4 V_51 , V_153 ;
int error ;
F_74 ( V_93 L_6 ) ;
V_51 = F_124 () ;
error = F_49 ( & V_117 , V_132 , V_30 ) ;
if ( error )
goto V_154;
error = F_49 ( & V_116 , V_132 , V_30 ) ;
if ( error )
goto V_154;
V_125 = 0 ;
V_126 = 0 ;
V_151 = F_97 () ;
V_142 = F_102 () ;
V_150 = V_142 ;
V_142 += V_151 ;
V_137 = V_151 ;
V_29 = 0 ;
F_45 (zone) {
V_29 += F_88 ( V_36 ) ;
if ( F_90 ( V_36 ) )
V_137 += F_91 ( V_36 , V_105 ) ;
else
V_150 += F_91 ( V_36 , V_105 ) ;
}
V_130 = V_150 ;
V_150 += V_137 ;
V_150 -= V_155 ;
V_29 += F_125 ( V_142 ) ;
V_149 = ( V_150 - ( V_29 + V_156 ) ) / 2
- 2 * F_35 ( V_4 , V_6 ) ;
V_29 = F_35 ( V_7 , V_6 ) ;
if ( V_29 > V_149 )
V_29 = V_149 ;
if ( V_29 >= V_142 ) {
V_54 = F_116 ( V_151 ) ;
V_54 += F_115 ( V_142 - V_54 , V_130 ) ;
goto V_120;
}
V_54 = F_121 ( V_142 ) ;
if ( V_130 > V_54 )
V_130 -= V_54 ;
else
V_130 = 0 ;
if ( V_29 < V_54 )
V_29 = F_126 (unsigned long, pages, max_size) ;
F_127 ( V_142 - V_29 ) ;
V_152 = F_116 ( V_137 / 2 ) ;
V_131 = V_150 - V_149 ;
if ( V_131 > V_152 )
V_131 -= V_152 ;
else
V_131 = 0 ;
V_54 = F_115 ( V_131 , V_130 ) ;
if ( V_54 < V_131 ) {
V_131 -= V_54 ;
V_54 += V_152 ;
V_152 = F_116 ( V_131 ) ;
if ( V_152 < V_131 )
goto V_154;
V_54 += V_152 ;
V_131 = ( V_150 - V_54 ) - V_29 ;
V_54 += F_116 ( V_131 ) ;
} else {
V_131 = V_149 - V_29 ;
V_29 = F_119 ( V_131 , V_137 , V_150 ) ;
V_152 += V_29 ;
V_131 -= V_29 ;
V_29 = F_115 ( V_131 , V_130 ) ;
V_152 += F_116 ( V_131 - V_29 ) ;
V_54 += V_152 + V_29 ;
}
V_54 -= F_120 () ;
V_120:
V_153 = F_124 () ;
F_74 ( V_157 L_7 , V_54 ) ;
F_128 ( V_51 , V_153 , V_54 , L_8 ) ;
return 0 ;
V_154:
F_74 ( V_157 L_9 ) ;
F_113 () ;
return - V_46 ;
}
static unsigned int F_129 ( unsigned int V_158 )
{
unsigned int V_159 = F_89 () + V_126 ;
if ( V_159 >= V_158 )
V_158 = 0 ;
else
V_158 -= V_159 ;
return V_158 ;
}
static unsigned int F_129 ( unsigned int V_158 ) { return 0 ; }
static int F_130 ( unsigned int V_127 , unsigned int V_158 )
{
struct V_36 * V_36 ;
unsigned int free = V_125 ;
F_45 (zone)
if ( ! F_90 ( V_36 ) )
free += F_91 ( V_36 , V_105 ) ;
V_127 += F_129 ( V_158 ) ;
F_78 ( L_10 ,
V_127 , V_156 , free ) ;
return free > V_127 + V_156 ;
}
static inline int F_131 ( int V_10 )
{
V_115 = F_10 ( V_160 | V_161 , V_10 ) ;
return V_115 ? 0 : - V_46 ;
}
static inline unsigned int F_132 ( struct V_59 * V_60 ,
unsigned int V_158 )
{
unsigned int V_162 = F_89 () ;
if ( V_162 > V_158 )
V_162 = V_158 ;
V_158 -= V_162 ;
while ( V_162 -- > 0 ) {
struct V_17 * V_17 ;
V_17 = F_18 ( V_133 | V_163 ) ;
F_52 ( V_60 , F_75 ( V_17 ) ) ;
}
return V_158 ;
}
static inline int F_131 ( int V_10 ) { return 0 ; }
static inline unsigned int F_132 ( struct V_59 * V_60 ,
unsigned int V_106 ) { return 0 ; }
static int F_133 ( struct V_59 * V_116 ,
unsigned int V_127 , unsigned int V_158 )
{
if ( V_158 > 0 ) {
if ( F_131 ( V_30 ) )
goto V_154;
if ( V_158 > V_126 ) {
V_158 -= V_126 ;
V_127 += F_132 ( V_116 , V_158 ) ;
}
}
if ( V_127 > V_125 ) {
V_127 -= V_125 ;
while ( V_127 -- > 0 ) {
struct V_17 * V_17 ;
V_17 = F_18 ( V_160 | V_161 ) ;
if ( ! V_17 )
goto V_154;
F_52 ( V_116 , F_75 ( V_17 ) ) ;
}
}
return 0 ;
V_154:
F_113 () ;
return - V_46 ;
}
T_5 T_6 int F_134 ( void )
{
unsigned int V_127 , V_158 ;
F_74 ( V_93 L_11 ) ;
F_135 ( NULL ) ;
V_127 = F_102 () ;
V_158 = F_97 () ;
F_74 ( V_93 L_12 , V_127 + V_158 ) ;
if ( ! F_130 ( V_127 , V_158 ) ) {
F_74 ( V_164 L_13 ) ;
return - V_46 ;
}
if ( F_133 ( & V_116 , V_127 , V_158 ) ) {
F_74 ( V_164 L_14 ) ;
return - V_46 ;
}
F_135 ( NULL ) ;
F_111 ( & V_116 , & V_117 ) ;
V_127 += V_158 ;
V_122 = V_127 ;
V_123 = F_35 ( V_127 * sizeof( long ) , V_6 ) ;
F_74 ( V_93 L_15 ,
V_127 ) ;
return 0 ;
}
static int F_136 ( struct V_165 * V_166 )
{
memcpy ( & V_166 -> V_167 , F_137 () , sizeof( struct V_168 ) ) ;
V_166 -> V_169 = V_170 ;
return 0 ;
}
static char * F_138 ( struct V_165 * V_166 )
{
if ( V_166 -> V_169 != V_170 )
return L_16 ;
if ( strcmp ( V_166 -> V_167 . V_171 , F_137 () -> V_171 ) )
return L_17 ;
if ( strcmp ( V_166 -> V_167 . V_172 , F_137 () -> V_172 ) )
return L_18 ;
if ( strcmp ( V_166 -> V_167 . V_173 , F_137 () -> V_173 ) )
return L_19 ;
if ( strcmp ( V_166 -> V_167 . V_174 , F_137 () -> V_174 ) )
return L_20 ;
return NULL ;
}
unsigned long F_139 ( void )
{
return V_122 + V_123 + 1 ;
}
static int F_140 ( struct V_165 * V_166 )
{
memset ( V_166 , 0 , sizeof( struct V_165 ) ) ;
V_166 -> V_175 = F_141 () ;
V_166 -> V_176 = V_122 ;
V_166 -> V_54 = F_139 () ;
V_166 -> V_29 = V_166 -> V_54 ;
V_166 -> V_29 <<= V_94 ;
return F_136 ( V_166 ) ;
}
static inline void F_142 ( unsigned long * V_177 , struct V_59 * V_60 )
{
int V_178 ;
for ( V_178 = 0 ; V_178 < V_6 / sizeof( long ) ; V_178 ++ ) {
V_177 [ V_178 ] = F_65 ( V_60 ) ;
if ( F_112 ( V_177 [ V_178 ] == V_85 ) )
break;
F_143 ( V_177 + V_178 ) ;
}
}
int F_144 ( struct V_179 * V_180 )
{
if ( V_180 -> V_61 > V_123 + V_122 )
return 0 ;
if ( ! V_115 ) {
V_115 = F_10 ( V_160 , V_30 ) ;
if ( ! V_115 )
return - V_46 ;
}
if ( ! V_180 -> V_61 ) {
int error ;
error = F_140 ( (struct V_165 * ) V_115 ) ;
if ( error )
return error ;
V_180 -> V_115 = V_115 ;
F_38 ( & V_117 ) ;
F_38 ( & V_116 ) ;
} else if ( V_180 -> V_61 <= V_123 ) {
F_145 ( V_115 ) ;
F_142 ( V_115 , & V_117 ) ;
} else {
struct V_17 * V_17 ;
V_17 = F_86 ( F_65 ( & V_116 ) ) ;
if ( F_94 ( V_17 ) ) {
void * V_181 ;
V_181 = F_108 ( V_17 ) ;
F_110 ( V_115 , V_181 ) ;
F_109 ( V_181 ) ;
V_180 -> V_115 = V_115 ;
} else {
V_180 -> V_115 = V_3 ( V_17 ) ;
}
}
V_180 -> V_61 ++ ;
return V_6 ;
}
static void F_146 ( struct V_59 * V_38 ,
struct V_59 * V_110 )
{
unsigned long V_75 ;
F_38 ( V_110 ) ;
V_75 = F_65 ( V_110 ) ;
while ( V_75 != V_85 ) {
F_52 ( V_38 , V_75 ) ;
V_75 = F_65 ( V_110 ) ;
}
}
static void F_147 ( struct V_59 * V_60 )
{
unsigned long V_75 ;
F_38 ( V_95 ) ;
V_75 = F_65 ( V_95 ) ;
while ( V_75 != V_85 ) {
F_57 ( V_95 ) ;
V_75 = F_65 ( V_95 ) ;
}
F_146 ( V_95 , V_60 ) ;
V_12 = 0 ;
}
static int F_148 ( struct V_165 * V_166 )
{
char * V_182 ;
V_182 = F_138 ( V_166 ) ;
if ( ! V_182 && V_166 -> V_175 != F_141 () )
V_182 = L_21 ;
if ( V_182 ) {
F_74 ( V_164 L_22 , V_182 ) ;
return - V_183 ;
}
return 0 ;
}
static int F_149 ( struct V_165 * V_166 )
{
int error ;
V_124 = NULL ;
error = F_148 ( V_166 ) ;
if ( ! error ) {
V_122 = V_166 -> V_176 ;
V_123 = V_166 -> V_54 - V_166 -> V_176 - 1 ;
}
return error ;
}
static int F_150 ( unsigned long * V_177 , struct V_59 * V_60 )
{
int V_178 ;
for ( V_178 = 0 ; V_178 < V_6 / sizeof( long ) ; V_178 ++ ) {
if ( F_112 ( V_177 [ V_178 ] == V_85 ) )
break;
F_151 ( V_177 + V_178 ) ;
if ( F_79 ( V_177 [ V_178 ] ) && F_61 ( V_60 , V_177 [ V_178 ] ) )
F_52 ( V_60 , V_177 [ V_178 ] ) ;
else
return - V_79 ;
}
return 0 ;
}
static unsigned int F_152 ( struct V_59 * V_60 )
{
unsigned long V_75 ;
unsigned int V_104 = 0 ;
F_38 ( V_60 ) ;
V_75 = F_65 ( V_60 ) ;
while ( V_75 != V_85 ) {
if ( F_94 ( F_86 ( V_75 ) ) )
V_104 ++ ;
V_75 = F_65 ( V_60 ) ;
}
return V_104 ;
}
static int F_153 ( struct V_59 * V_60 ,
unsigned int * V_184 )
{
unsigned int V_162 ;
if ( F_49 ( V_60 , V_160 , V_16 ) )
return - V_46 ;
if ( F_131 ( V_16 ) )
return - V_46 ;
V_162 = F_89 () ;
if ( V_162 > * V_184 )
V_162 = * V_184 ;
else
* V_184 = V_162 ;
V_185 = 0 ;
while ( V_162 -- > 0 ) {
struct V_17 * V_17 ;
V_17 = F_19 ( V_133 ) ;
if ( ! F_12 ( V_17 ) ) {
F_52 ( V_60 , F_75 ( V_17 ) ) ;
V_185 ++ ;
}
F_14 ( V_17 ) ;
F_15 ( V_17 ) ;
}
F_38 ( V_60 ) ;
V_186 = V_60 ;
return 0 ;
}
static void * F_154 ( struct V_17 * V_17 ,
struct V_24 * V_25 )
{
struct V_187 * V_188 ;
void * V_181 ;
if ( F_76 ( V_17 ) && F_12 ( V_17 ) ) {
V_189 = V_17 ;
return V_115 ;
}
V_188 = F_29 ( V_25 , sizeof( struct V_187 ) ) ;
if ( ! V_188 ) {
F_113 () ;
return F_155 ( - V_46 ) ;
}
V_188 -> V_190 = V_17 ;
if ( V_185 > 0 ) {
struct V_17 * V_191 ;
V_181 = V_115 ;
V_191 = F_86 ( F_65 ( V_186 ) ) ;
V_185 -- ;
V_189 = V_191 ;
V_188 -> F_110 = V_191 ;
} else {
V_181 = V_13 ;
V_13 = V_13 -> V_15 ;
V_188 -> F_110 = F_13 ( V_181 ) ;
}
V_188 -> V_15 = V_192 ;
V_192 = V_188 ;
return V_181 ;
}
static void F_156 ( void )
{
if ( V_189 ) {
void * V_38 ;
V_38 = F_108 ( V_189 ) ;
F_110 ( V_38 , V_115 ) ;
F_109 ( V_38 ) ;
V_189 = NULL ;
}
}
static inline int F_157 ( void )
{
return ! V_189 ;
}
static inline void F_158 ( void )
{
if ( V_186 )
F_50 ( V_186 , V_58 ) ;
if ( V_115 )
F_21 ( V_115 , V_58 ) ;
}
static unsigned int F_152 ( struct V_59 * V_60 ) { return 0 ; }
static inline int F_153 ( struct V_59 * V_60 ,
unsigned int * V_184 ) { return 0 ; }
static inline void * F_154 ( struct V_17 * V_17 ,
struct V_24 * V_25 )
{
return F_155 ( - V_193 ) ;
}
static inline void F_156 ( void ) {}
static inline int F_157 ( void ) { return 1 ; }
static inline void F_158 ( void ) {}
static int F_159 ( struct V_59 * V_194 , struct V_59 * V_60 )
{
unsigned int V_127 , V_158 ;
struct V_18 * V_19 ;
int error ;
F_21 ( V_115 , V_58 ) ;
V_115 = NULL ;
V_158 = F_152 ( V_60 ) ;
F_147 ( V_60 ) ;
error = F_49 ( V_194 , V_160 , V_16 ) ;
if ( error )
goto Free;
F_146 ( V_194 , V_60 ) ;
F_50 ( V_60 , V_195 ) ;
if ( V_158 > 0 ) {
error = F_153 ( V_60 , & V_158 ) ;
if ( error )
goto Free;
}
V_127 = V_122 - V_158 - V_12 ;
V_127 = F_35 ( V_127 , V_196 ) ;
while ( V_127 > 0 ) {
V_19 = F_10 ( V_160 , V_16 ) ;
if ( ! V_19 ) {
error = - V_46 ;
goto Free;
}
V_19 -> V_15 = V_13 ;
V_13 = V_19 ;
V_127 -- ;
}
V_127 = V_122 - V_158 - V_12 ;
while ( V_127 > 0 ) {
V_19 = (struct V_18 * ) F_11 ( V_160 ) ;
if ( ! V_19 ) {
error = - V_46 ;
goto Free;
}
if ( ! F_12 ( F_13 ( V_19 ) ) ) {
V_19 -> V_15 = V_13 ;
V_13 = V_19 ;
}
F_14 ( F_13 ( V_19 ) ) ;
F_15 ( F_13 ( V_19 ) ) ;
V_127 -- ;
}
return 0 ;
Free:
F_113 () ;
return error ;
}
static void * F_160 ( struct V_59 * V_60 , struct V_24 * V_25 )
{
struct V_188 * V_188 ;
struct V_17 * V_17 ;
unsigned long V_75 = F_65 ( V_60 ) ;
if ( V_75 == V_85 )
return F_155 ( - V_79 ) ;
V_17 = F_86 ( V_75 ) ;
if ( F_94 ( V_17 ) )
return F_154 ( V_17 , V_25 ) ;
if ( F_76 ( V_17 ) && F_12 ( V_17 ) )
return V_3 ( V_17 ) ;
V_188 = F_29 ( V_25 , sizeof( struct V_188 ) ) ;
if ( ! V_188 ) {
F_113 () ;
return F_155 ( - V_46 ) ;
}
V_188 -> V_197 = V_3 ( V_17 ) ;
V_188 -> V_198 = V_13 ;
V_13 = V_13 -> V_15 ;
V_188 -> V_15 = V_124 ;
V_124 = V_188 ;
return V_188 -> V_198 ;
}
int F_161 ( struct V_179 * V_180 )
{
static struct V_24 V_25 ;
int error = 0 ;
if ( V_180 -> V_61 > 1 && V_180 -> V_61 > V_123 + V_122 )
return 0 ;
V_180 -> V_199 = 1 ;
if ( ! V_180 -> V_61 ) {
if ( ! V_115 )
V_115 = F_10 ( V_160 , V_30 ) ;
if ( ! V_115 )
return - V_46 ;
V_180 -> V_115 = V_115 ;
} else if ( V_180 -> V_61 == 1 ) {
error = F_149 ( V_115 ) ;
if ( error )
return error ;
V_13 = NULL ;
error = F_49 ( & V_116 , V_160 , V_30 ) ;
if ( error )
return error ;
error = F_162 ( V_122 ) ;
if ( error )
return error ;
F_2 () ;
} else if ( V_180 -> V_61 <= V_123 + 1 ) {
error = F_150 ( V_115 , & V_116 ) ;
if ( error )
return error ;
if ( V_180 -> V_61 == V_123 + 1 ) {
error = F_159 ( & V_117 , & V_116 ) ;
if ( error )
return error ;
F_28 ( & V_25 , V_160 , V_16 ) ;
F_38 ( & V_117 ) ;
V_124 = NULL ;
V_180 -> V_115 = F_160 ( & V_117 , & V_25 ) ;
V_180 -> V_199 = 0 ;
if ( F_163 ( V_180 -> V_115 ) )
return F_164 ( V_180 -> V_115 ) ;
}
} else {
F_156 () ;
F_165 ( V_180 -> V_115 ) ;
F_4 ( V_180 -> V_115 ) ;
V_180 -> V_115 = F_160 ( & V_117 , & V_25 ) ;
if ( F_163 ( V_180 -> V_115 ) )
return F_164 ( V_180 -> V_115 ) ;
if ( V_180 -> V_115 != V_115 )
V_180 -> V_199 = 0 ;
}
V_180 -> V_61 ++ ;
return V_6 ;
}
void F_166 ( struct V_179 * V_180 )
{
F_156 () ;
F_165 ( V_180 -> V_115 ) ;
F_167 () ;
F_4 ( V_180 -> V_115 ) ;
if ( V_180 -> V_61 > 1 && V_180 -> V_61 > V_123 + V_122 ) {
F_69 ( & V_117 ) ;
F_158 () ;
}
}
int F_168 ( struct V_179 * V_180 )
{
return ! ( ! V_122 || ! F_157 () ||
V_180 -> V_61 <= V_123 + V_122 ) ;
}
static inline void F_169 ( struct V_17 * V_200 , struct V_17 * V_201 ,
void * V_177 )
{
void * V_202 , * V_203 ;
V_202 = F_108 ( V_200 ) ;
V_203 = F_108 ( V_201 ) ;
F_110 ( V_177 , V_202 ) ;
F_110 ( V_202 , V_203 ) ;
F_110 ( V_203 , V_177 ) ;
F_109 ( V_203 ) ;
F_109 ( V_202 ) ;
}
int F_170 ( void )
{
struct V_187 * V_188 = V_192 ;
void * V_177 ;
if ( ! V_188 )
return 0 ;
V_177 = F_10 ( V_160 , V_16 ) ;
if ( ! V_177 )
return - V_46 ;
while ( V_188 ) {
F_169 ( V_188 -> F_110 , V_188 -> V_190 , V_177 ) ;
V_188 = V_188 -> V_15 ;
}
F_21 ( V_177 , V_58 ) ;
return 0 ;
}
