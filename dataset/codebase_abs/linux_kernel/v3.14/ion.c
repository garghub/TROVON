bool F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 & V_4 ) &&
! ( V_2 -> V_3 & V_5 ) ;
}
bool F_2 ( struct V_1 * V_2 )
{
return ! ! ( V_2 -> V_3 & V_4 ) ;
}
static inline struct V_6 * F_3 ( struct V_6 * V_6 )
{
return (struct V_6 * ) ( ( unsigned long ) V_6 & ~ ( 1UL ) ) ;
}
static inline bool F_4 ( struct V_6 * V_6 )
{
return ! ! ( ( unsigned long ) V_6 & 1UL ) ;
}
static inline void F_5 ( struct V_6 * * V_6 )
{
* V_6 = (struct V_6 * ) ( ( unsigned long ) ( * V_6 ) | 1UL ) ;
}
static inline void F_6 ( struct V_6 * * V_6 )
{
* V_6 = (struct V_6 * ) ( ( unsigned long ) ( * V_6 ) & ~ ( 1UL ) ) ;
}
static void F_7 ( struct V_7 * V_8 ,
struct V_1 * V_2 )
{
struct V_9 * * V_10 = & V_8 -> V_11 . V_9 ;
struct V_9 * V_12 = NULL ;
struct V_1 * V_13 ;
while ( * V_10 ) {
V_12 = * V_10 ;
V_13 = F_8 ( V_12 , struct V_1 , V_14 ) ;
if ( V_2 < V_13 ) {
V_10 = & ( * V_10 ) -> V_15 ;
} else if ( V_2 > V_13 ) {
V_10 = & ( * V_10 ) -> V_16 ;
} else {
F_9 ( L_1 , V_17 ) ;
F_10 () ;
}
}
F_11 ( & V_2 -> V_14 , V_12 , V_10 ) ;
F_12 ( & V_2 -> V_14 , & V_8 -> V_11 ) ;
}
static struct V_1 * F_13 ( struct V_18 * V_19 ,
struct V_7 * V_8 ,
unsigned long V_20 ,
unsigned long V_21 ,
unsigned long V_3 )
{
struct V_1 * V_2 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
int V_26 , V_27 ;
V_2 = F_14 ( sizeof( struct V_1 ) , V_28 ) ;
if ( ! V_2 )
return F_15 ( - V_29 ) ;
V_2 -> V_19 = V_19 ;
V_2 -> V_3 = V_3 ;
F_16 ( & V_2 -> V_30 ) ;
V_27 = V_19 -> V_31 -> V_32 ( V_19 , V_2 , V_20 , V_21 , V_3 ) ;
if ( V_27 ) {
if ( ! ( V_19 -> V_3 & V_33 ) )
goto V_34;
F_17 ( V_19 , 0 ) ;
V_27 = V_19 -> V_31 -> V_32 ( V_19 , V_2 , V_20 , V_21 ,
V_3 ) ;
if ( V_27 )
goto V_34;
}
V_2 -> V_8 = V_8 ;
V_2 -> V_35 = V_20 ;
V_23 = V_19 -> V_31 -> V_36 ( V_19 , V_2 ) ;
if ( F_18 ( V_23 == NULL ,
L_2 ) )
V_23 = F_15 ( - V_37 ) ;
if ( F_19 ( V_23 ) ) {
V_19 -> V_31 -> free ( V_2 ) ;
F_20 ( V_2 ) ;
return F_15 ( F_21 ( V_23 ) ) ;
}
V_2 -> V_22 = V_23 ;
if ( F_1 ( V_2 ) ) {
int V_38 = F_22 ( V_2 -> V_35 ) / V_39 ;
struct V_24 * V_25 ;
int V_26 , V_40 , V_41 = 0 ;
V_2 -> V_42 = F_23 ( sizeof( struct V_6 * ) * V_38 ) ;
if ( ! V_2 -> V_42 ) {
V_27 = - V_29 ;
goto V_43;
}
F_24 (table->sgl, sg, table->nents, i) {
struct V_6 * V_6 = F_25 ( V_25 ) ;
for ( V_40 = 0 ; V_40 < V_25 -> V_44 / V_39 ; V_40 ++ )
V_2 -> V_42 [ V_41 ++ ] = V_6 ++ ;
}
if ( V_27 )
goto V_45;
}
V_2 -> V_8 = V_8 ;
V_2 -> V_35 = V_20 ;
F_26 ( & V_2 -> V_46 ) ;
F_27 ( & V_2 -> V_47 ) ;
F_24 (buffer->sg_table->sgl, sg, buffer->sg_table->nents, i)
F_28 ( V_25 ) = F_29 ( V_25 ) ;
F_30 ( & V_8 -> V_48 ) ;
F_7 ( V_8 , V_2 ) ;
F_31 ( & V_8 -> V_48 ) ;
return V_2 ;
V_45:
V_19 -> V_31 -> V_49 ( V_19 , V_2 ) ;
V_19 -> V_31 -> free ( V_2 ) ;
V_43:
if ( V_2 -> V_42 )
F_32 ( V_2 -> V_42 ) ;
V_34:
F_20 ( V_2 ) ;
return F_15 ( V_27 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
if ( F_34 ( V_2 -> V_50 > 0 ) )
V_2 -> V_19 -> V_31 -> V_51 ( V_2 -> V_19 , V_2 ) ;
V_2 -> V_19 -> V_31 -> V_49 ( V_2 -> V_19 , V_2 ) ;
V_2 -> V_19 -> V_31 -> free ( V_2 ) ;
if ( V_2 -> V_42 )
F_32 ( V_2 -> V_42 ) ;
F_20 ( V_2 ) ;
}
static void F_35 ( struct V_52 * V_52 )
{
struct V_1 * V_2 = F_36 ( V_52 , struct V_1 , V_30 ) ;
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_7 * V_8 = V_2 -> V_8 ;
F_30 ( & V_8 -> V_48 ) ;
F_37 ( & V_2 -> V_14 , & V_8 -> V_11 ) ;
F_31 ( & V_8 -> V_48 ) ;
if ( V_19 -> V_3 & V_33 )
F_38 ( V_19 , V_2 ) ;
else
F_33 ( V_2 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_40 ( & V_2 -> V_30 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
return F_42 ( & V_2 -> V_30 , F_35 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
F_30 ( & V_2 -> V_47 ) ;
V_2 -> V_53 ++ ;
F_31 ( & V_2 -> V_47 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_30 ( & V_2 -> V_47 ) ;
V_2 -> V_53 -- ;
F_45 ( V_2 -> V_53 < 0 ) ;
if ( ! V_2 -> V_53 ) {
struct V_54 * V_55 ;
V_55 = V_56 -> V_57 ;
F_46 ( V_2 -> V_58 , V_55 ) ;
V_2 -> V_59 = F_47 ( V_55 ) ;
}
F_31 ( & V_2 -> V_47 ) ;
}
static struct V_60 * F_48 ( struct V_61 * V_62 ,
struct V_1 * V_2 )
{
struct V_60 * V_63 ;
V_63 = F_14 ( sizeof( struct V_60 ) , V_28 ) ;
if ( ! V_63 )
return F_15 ( - V_29 ) ;
F_16 ( & V_63 -> V_30 ) ;
F_49 ( & V_63 -> V_14 ) ;
V_63 -> V_62 = V_62 ;
F_39 ( V_2 ) ;
F_43 ( V_2 ) ;
V_63 -> V_2 = V_2 ;
return V_63 ;
}
static void F_50 ( struct V_52 * V_52 )
{
struct V_60 * V_63 = F_36 ( V_52 , struct V_60 , V_30 ) ;
struct V_61 * V_62 = V_63 -> V_62 ;
struct V_1 * V_2 = V_63 -> V_2 ;
F_30 ( & V_2 -> V_47 ) ;
while ( V_63 -> V_50 )
F_51 ( V_63 ) ;
F_31 ( & V_2 -> V_47 ) ;
F_52 ( & V_62 -> V_64 , V_63 -> V_65 ) ;
if ( ! F_53 ( & V_63 -> V_14 ) )
F_37 ( & V_63 -> V_14 , & V_62 -> V_66 ) ;
F_44 ( V_2 ) ;
F_41 ( V_2 ) ;
F_20 ( V_63 ) ;
}
struct V_1 * F_54 ( struct V_60 * V_63 )
{
return V_63 -> V_2 ;
}
static void F_55 ( struct V_60 * V_63 )
{
F_40 ( & V_63 -> V_30 ) ;
}
static int F_56 ( struct V_60 * V_63 )
{
struct V_61 * V_62 = V_63 -> V_62 ;
int V_27 ;
F_30 ( & V_62 -> V_47 ) ;
V_27 = F_42 ( & V_63 -> V_30 , F_50 ) ;
F_31 ( & V_62 -> V_47 ) ;
return V_27 ;
}
static struct V_60 * F_57 ( struct V_61 * V_62 ,
struct V_1 * V_2 )
{
struct V_9 * V_67 = V_62 -> V_66 . V_9 ;
while ( V_67 ) {
struct V_60 * V_13 = F_8 ( V_67 , struct V_60 , V_14 ) ;
if ( V_2 < V_13 -> V_2 )
V_67 = V_67 -> V_15 ;
else if ( V_2 > V_13 -> V_2 )
V_67 = V_67 -> V_16 ;
else
return V_13 ;
}
return F_15 ( - V_37 ) ;
}
static struct V_60 * F_58 ( struct V_61 * V_62 ,
int V_65 )
{
struct V_60 * V_63 ;
F_30 ( & V_62 -> V_47 ) ;
V_63 = F_59 ( & V_62 -> V_64 , V_65 ) ;
if ( V_63 )
F_55 ( V_63 ) ;
F_31 ( & V_62 -> V_47 ) ;
return V_63 ? V_63 : F_15 ( - V_37 ) ;
}
static bool F_60 ( struct V_61 * V_62 ,
struct V_60 * V_63 )
{
F_34 ( ! F_61 ( & V_62 -> V_47 ) ) ;
return ( F_59 ( & V_62 -> V_64 , V_63 -> V_65 ) == V_63 ) ;
}
static int F_62 ( struct V_61 * V_62 , struct V_60 * V_63 )
{
int V_65 ;
struct V_9 * * V_10 = & V_62 -> V_66 . V_9 ;
struct V_9 * V_12 = NULL ;
struct V_60 * V_13 ;
V_65 = F_63 ( & V_62 -> V_64 , V_63 , 1 , 0 , V_28 ) ;
if ( V_65 < 0 )
return V_65 ;
V_63 -> V_65 = V_65 ;
while ( * V_10 ) {
V_12 = * V_10 ;
V_13 = F_8 ( V_12 , struct V_60 , V_14 ) ;
if ( V_63 -> V_2 < V_13 -> V_2 )
V_10 = & ( * V_10 ) -> V_15 ;
else if ( V_63 -> V_2 > V_13 -> V_2 )
V_10 = & ( * V_10 ) -> V_16 ;
else
F_64 ( 1 , L_1 , V_17 ) ;
}
F_11 ( & V_63 -> V_14 , V_12 , V_10 ) ;
F_12 ( & V_63 -> V_14 , & V_62 -> V_66 ) ;
return 0 ;
}
struct V_60 * F_65 ( struct V_61 * V_62 , T_1 V_20 ,
T_1 V_21 , unsigned int V_68 ,
unsigned int V_3 )
{
struct V_60 * V_63 ;
struct V_7 * V_8 = V_62 -> V_8 ;
struct V_1 * V_2 = NULL ;
struct V_18 * V_19 ;
int V_27 ;
F_66 ( L_3 , V_17 ,
V_20 , V_21 , V_68 , V_3 ) ;
V_20 = F_22 ( V_20 ) ;
if ( ! V_20 )
return F_15 ( - V_37 ) ;
F_67 ( & V_8 -> V_47 ) ;
F_68 (heap, &dev->heaps, node) {
if ( ! ( ( 1 << V_19 -> V_65 ) & V_68 ) )
continue;
V_2 = F_13 ( V_19 , V_8 , V_20 , V_21 , V_3 ) ;
if ( ! F_19 ( V_2 ) )
break;
}
F_69 ( & V_8 -> V_47 ) ;
if ( V_2 == NULL )
return F_15 ( - V_69 ) ;
if ( F_19 ( V_2 ) )
return F_15 ( F_21 ( V_2 ) ) ;
V_63 = F_48 ( V_62 , V_2 ) ;
F_41 ( V_2 ) ;
if ( F_19 ( V_63 ) )
return V_63 ;
F_30 ( & V_62 -> V_47 ) ;
V_27 = F_62 ( V_62 , V_63 ) ;
F_31 ( & V_62 -> V_47 ) ;
if ( V_27 ) {
F_56 ( V_63 ) ;
V_63 = F_15 ( V_27 ) ;
}
return V_63 ;
}
void F_70 ( struct V_61 * V_62 , struct V_60 * V_63 )
{
bool V_70 ;
F_45 ( V_62 != V_63 -> V_62 ) ;
F_30 ( & V_62 -> V_47 ) ;
V_70 = F_60 ( V_62 , V_63 ) ;
if ( ! V_70 ) {
F_64 ( 1 , L_4 , V_17 ) ;
F_31 ( & V_62 -> V_47 ) ;
return;
}
F_31 ( & V_62 -> V_47 ) ;
F_56 ( V_63 ) ;
}
int F_71 ( struct V_61 * V_62 , struct V_60 * V_63 ,
T_2 * V_71 , T_1 * V_20 )
{
struct V_1 * V_2 ;
int V_27 ;
F_30 ( & V_62 -> V_47 ) ;
if ( ! F_60 ( V_62 , V_63 ) ) {
F_31 ( & V_62 -> V_47 ) ;
return - V_37 ;
}
V_2 = V_63 -> V_2 ;
if ( ! V_2 -> V_19 -> V_31 -> V_72 ) {
F_9 ( L_5 ,
V_17 ) ;
F_31 ( & V_62 -> V_47 ) ;
return - V_69 ;
}
F_31 ( & V_62 -> V_47 ) ;
V_27 = V_2 -> V_19 -> V_31 -> V_72 ( V_2 -> V_19 , V_2 , V_71 , V_20 ) ;
return V_27 ;
}
static void * F_72 ( struct V_1 * V_2 )
{
void * V_73 ;
if ( V_2 -> V_50 ) {
V_2 -> V_50 ++ ;
return V_2 -> V_73 ;
}
V_73 = V_2 -> V_19 -> V_31 -> V_74 ( V_2 -> V_19 , V_2 ) ;
if ( F_18 ( V_73 == NULL ,
L_6 ) )
return F_15 ( - V_37 ) ;
if ( F_19 ( V_73 ) )
return V_73 ;
V_2 -> V_73 = V_73 ;
V_2 -> V_50 ++ ;
return V_73 ;
}
static void * F_73 ( struct V_60 * V_63 )
{
struct V_1 * V_2 = V_63 -> V_2 ;
void * V_73 ;
if ( V_63 -> V_50 ) {
V_63 -> V_50 ++ ;
return V_2 -> V_73 ;
}
V_73 = F_72 ( V_2 ) ;
if ( F_19 ( V_73 ) )
return V_73 ;
V_63 -> V_50 ++ ;
return V_73 ;
}
static void F_74 ( struct V_1 * V_2 )
{
V_2 -> V_50 -- ;
if ( ! V_2 -> V_50 ) {
V_2 -> V_19 -> V_31 -> V_51 ( V_2 -> V_19 , V_2 ) ;
V_2 -> V_73 = NULL ;
}
}
static void F_51 ( struct V_60 * V_63 )
{
struct V_1 * V_2 = V_63 -> V_2 ;
V_63 -> V_50 -- ;
if ( ! V_63 -> V_50 )
F_74 ( V_2 ) ;
}
void * F_75 ( struct V_61 * V_62 , struct V_60 * V_63 )
{
struct V_1 * V_2 ;
void * V_73 ;
F_30 ( & V_62 -> V_47 ) ;
if ( ! F_60 ( V_62 , V_63 ) ) {
F_9 ( L_7 ,
V_17 ) ;
F_31 ( & V_62 -> V_47 ) ;
return F_15 ( - V_37 ) ;
}
V_2 = V_63 -> V_2 ;
if ( ! V_63 -> V_2 -> V_19 -> V_31 -> V_74 ) {
F_9 ( L_8 ,
V_17 ) ;
F_31 ( & V_62 -> V_47 ) ;
return F_15 ( - V_69 ) ;
}
F_30 ( & V_2 -> V_47 ) ;
V_73 = F_73 ( V_63 ) ;
F_31 ( & V_2 -> V_47 ) ;
F_31 ( & V_62 -> V_47 ) ;
return V_73 ;
}
void F_76 ( struct V_61 * V_62 , struct V_60 * V_63 )
{
struct V_1 * V_2 ;
F_30 ( & V_62 -> V_47 ) ;
V_2 = V_63 -> V_2 ;
F_30 ( & V_2 -> V_47 ) ;
F_51 ( V_63 ) ;
F_31 ( & V_2 -> V_47 ) ;
F_31 ( & V_62 -> V_47 ) ;
}
static int F_77 ( struct V_75 * V_76 , void * V_77 )
{
struct V_61 * V_62 = V_76 -> V_78 ;
struct V_9 * V_67 ;
T_1 V_79 [ V_80 ] = { 0 } ;
const char * V_81 [ V_80 ] = { NULL } ;
int V_26 ;
F_30 ( & V_62 -> V_47 ) ;
for ( V_67 = F_78 ( & V_62 -> V_66 ) ; V_67 ; V_67 = F_79 ( V_67 ) ) {
struct V_60 * V_63 = F_8 ( V_67 , struct V_60 ,
V_14 ) ;
unsigned int V_65 = V_63 -> V_2 -> V_19 -> V_65 ;
if ( ! V_81 [ V_65 ] )
V_81 [ V_65 ] = V_63 -> V_2 -> V_19 -> V_82 ;
V_79 [ V_65 ] += V_63 -> V_2 -> V_35 ;
}
F_31 ( & V_62 -> V_47 ) ;
F_80 ( V_76 , L_9 , L_10 , L_11 ) ;
for ( V_26 = 0 ; V_26 < V_80 ; V_26 ++ ) {
if ( ! V_81 [ V_26 ] )
continue;
F_80 ( V_76 , L_12 , V_81 [ V_26 ] , V_79 [ V_26 ] ) ;
}
return 0 ;
}
static int F_81 ( struct V_83 * V_83 , struct V_84 * V_84 )
{
return F_82 ( V_84 , F_77 , V_83 -> V_85 ) ;
}
struct V_61 * F_83 ( struct V_7 * V_8 ,
const char * V_82 )
{
struct V_61 * V_62 ;
struct V_54 * V_55 ;
struct V_9 * * V_10 ;
struct V_9 * V_12 = NULL ;
struct V_61 * V_13 ;
char V_86 [ 64 ] ;
T_3 V_59 ;
F_84 ( V_56 -> V_57 ) ;
F_85 ( V_56 -> V_57 ) ;
V_59 = F_47 ( V_56 -> V_57 ) ;
if ( V_56 -> V_57 -> V_3 & V_87 ) {
F_86 ( V_56 -> V_57 ) ;
V_55 = NULL ;
} else {
V_55 = V_56 -> V_57 ;
}
F_87 ( V_56 -> V_57 ) ;
V_62 = F_14 ( sizeof( struct V_61 ) , V_28 ) ;
if ( ! V_62 ) {
if ( V_55 )
F_86 ( V_56 -> V_57 ) ;
return F_15 ( - V_29 ) ;
}
V_62 -> V_8 = V_8 ;
V_62 -> V_66 = V_88 ;
F_88 ( & V_62 -> V_64 ) ;
F_27 ( & V_62 -> V_47 ) ;
V_62 -> V_82 = V_82 ;
V_62 -> V_55 = V_55 ;
V_62 -> V_59 = V_59 ;
F_89 ( & V_8 -> V_47 ) ;
V_10 = & V_8 -> V_89 . V_9 ;
while ( * V_10 ) {
V_12 = * V_10 ;
V_13 = F_8 ( V_12 , struct V_61 , V_14 ) ;
if ( V_62 < V_13 )
V_10 = & ( * V_10 ) -> V_15 ;
else if ( V_62 > V_13 )
V_10 = & ( * V_10 ) -> V_16 ;
}
F_11 ( & V_62 -> V_14 , V_12 , V_10 ) ;
F_12 ( & V_62 -> V_14 , & V_8 -> V_89 ) ;
snprintf ( V_86 , 64 , L_13 , V_62 -> V_59 ) ;
V_62 -> V_90 = F_90 ( V_86 , 0664 ,
V_8 -> V_90 , V_62 ,
& V_91 ) ;
F_91 ( & V_8 -> V_47 ) ;
return V_62 ;
}
void F_92 ( struct V_61 * V_62 )
{
struct V_7 * V_8 = V_62 -> V_8 ;
struct V_9 * V_67 ;
F_66 ( L_14 , V_17 , __LINE__ ) ;
while ( ( V_67 = F_78 ( & V_62 -> V_66 ) ) ) {
struct V_60 * V_63 = F_8 ( V_67 , struct V_60 ,
V_14 ) ;
F_50 ( & V_63 -> V_30 ) ;
}
F_93 ( & V_62 -> V_64 ) ;
F_89 ( & V_8 -> V_47 ) ;
if ( V_62 -> V_55 )
F_86 ( V_62 -> V_55 ) ;
F_37 ( & V_62 -> V_14 , & V_8 -> V_89 ) ;
F_94 ( V_62 -> V_90 ) ;
F_91 ( & V_8 -> V_47 ) ;
F_20 ( V_62 ) ;
}
struct V_22 * F_95 ( struct V_61 * V_62 ,
struct V_60 * V_63 )
{
struct V_1 * V_2 ;
struct V_22 * V_23 ;
F_30 ( & V_62 -> V_47 ) ;
if ( ! F_60 ( V_62 , V_63 ) ) {
F_9 ( L_15 ,
V_17 ) ;
F_31 ( & V_62 -> V_47 ) ;
return F_15 ( - V_37 ) ;
}
V_2 = V_63 -> V_2 ;
V_23 = V_2 -> V_22 ;
F_31 ( & V_62 -> V_47 ) ;
return V_23 ;
}
static struct V_22 * F_96 ( struct V_92 * V_93 ,
enum V_94 V_95 )
{
struct V_96 * V_97 = V_93 -> V_97 ;
struct V_1 * V_2 = V_97 -> V_98 ;
F_97 ( V_2 , V_93 -> V_8 , V_95 ) ;
return V_2 -> V_22 ;
}
static void F_98 ( struct V_92 * V_93 ,
struct V_22 * V_23 ,
enum V_94 V_95 )
{
}
void F_99 ( struct V_99 * V_8 , struct V_6 * V_6 ,
T_1 V_35 , enum V_94 V_100 )
{
struct V_24 V_25 ;
F_100 ( & V_25 , 1 ) ;
F_101 ( & V_25 , V_6 , V_35 , 0 ) ;
F_28 ( & V_25 ) = F_102 ( V_6 ) ;
F_103 ( V_8 , & V_25 , 1 , V_100 ) ;
}
static void F_97 ( struct V_1 * V_2 ,
struct V_99 * V_8 ,
enum V_94 V_100 )
{
struct V_101 * V_102 ;
int V_42 = F_22 ( V_2 -> V_35 ) / V_39 ;
int V_26 ;
F_66 ( L_16 , V_17 ,
V_8 ? F_104 ( V_8 ) : L_17 ) ;
if ( ! F_1 ( V_2 ) )
return;
F_30 ( & V_2 -> V_47 ) ;
for ( V_26 = 0 ; V_26 < V_42 ; V_26 ++ ) {
struct V_6 * V_6 = V_2 -> V_42 [ V_26 ] ;
if ( F_4 ( V_6 ) )
F_99 ( V_8 , F_3 ( V_6 ) ,
V_39 , V_100 ) ;
F_6 ( V_2 -> V_42 + V_26 ) ;
}
F_105 (vma_list, &buffer->vmas, list) {
struct V_103 * V_104 = V_102 -> V_104 ;
F_106 ( V_104 , V_104 -> V_105 , V_104 -> V_106 - V_104 -> V_105 ,
NULL ) ;
}
F_31 ( & V_2 -> V_47 ) ;
}
static int F_107 ( struct V_103 * V_104 , struct V_107 * V_108 )
{
struct V_1 * V_2 = V_104 -> V_109 ;
unsigned long V_110 ;
int V_27 ;
F_30 ( & V_2 -> V_47 ) ;
F_5 ( V_2 -> V_42 + V_108 -> V_111 ) ;
F_45 ( ! V_2 -> V_42 || ! V_2 -> V_42 [ V_108 -> V_111 ] ) ;
V_110 = F_108 ( F_3 ( V_2 -> V_42 [ V_108 -> V_111 ] ) ) ;
V_27 = F_109 ( V_104 , ( unsigned long ) V_108 -> V_112 , V_110 ) ;
F_31 ( & V_2 -> V_47 ) ;
if ( V_27 )
return V_113 ;
return V_114 ;
}
static void F_110 ( struct V_103 * V_104 )
{
struct V_1 * V_2 = V_104 -> V_109 ;
struct V_101 * V_102 ;
V_102 = F_111 ( sizeof( struct V_101 ) , V_28 ) ;
if ( ! V_102 )
return;
V_102 -> V_104 = V_104 ;
F_30 ( & V_2 -> V_47 ) ;
F_112 ( & V_102 -> V_115 , & V_2 -> V_46 ) ;
F_31 ( & V_2 -> V_47 ) ;
F_66 ( L_18 , V_17 , V_104 ) ;
}
static void F_113 ( struct V_103 * V_104 )
{
struct V_1 * V_2 = V_104 -> V_109 ;
struct V_101 * V_102 , * V_116 ;
F_66 ( L_19 , V_17 ) ;
F_30 ( & V_2 -> V_47 ) ;
F_114 (vma_list, tmp, &buffer->vmas, list) {
if ( V_102 -> V_104 != V_104 )
continue;
F_115 ( & V_102 -> V_115 ) ;
F_20 ( V_102 ) ;
F_66 ( L_20 , V_17 , V_104 ) ;
break;
}
F_31 ( & V_2 -> V_47 ) ;
}
static int F_116 ( struct V_96 * V_97 , struct V_103 * V_104 )
{
struct V_1 * V_2 = V_97 -> V_98 ;
int V_27 = 0 ;
if ( ! V_2 -> V_19 -> V_31 -> V_117 ) {
F_9 ( L_21
L_22 , V_17 ) ;
return - V_37 ;
}
if ( F_1 ( V_2 ) ) {
V_104 -> V_118 |= V_119 | V_120 | V_121 |
V_122 ;
V_104 -> V_109 = V_2 ;
V_104 -> V_123 = & V_124 ;
F_110 ( V_104 ) ;
return 0 ;
}
if ( ! ( V_2 -> V_3 & V_4 ) )
V_104 -> V_125 = F_117 ( V_104 -> V_125 ) ;
F_30 ( & V_2 -> V_47 ) ;
V_27 = V_2 -> V_19 -> V_31 -> V_117 ( V_2 -> V_19 , V_2 , V_104 ) ;
F_31 ( & V_2 -> V_47 ) ;
if ( V_27 )
F_9 ( L_23 ,
V_17 ) ;
return V_27 ;
}
static void F_118 ( struct V_96 * V_97 )
{
struct V_1 * V_2 = V_97 -> V_98 ;
F_41 ( V_2 ) ;
}
static void * F_119 ( struct V_96 * V_97 , unsigned long V_126 )
{
struct V_1 * V_2 = V_97 -> V_98 ;
return V_2 -> V_73 + V_126 * V_39 ;
}
static void F_120 ( struct V_96 * V_97 , unsigned long V_126 ,
void * V_127 )
{
return;
}
static int F_121 ( struct V_96 * V_97 , T_1 V_128 ,
T_1 V_20 ,
enum V_94 V_95 )
{
struct V_1 * V_2 = V_97 -> V_98 ;
void * V_73 ;
if ( ! V_2 -> V_19 -> V_31 -> V_74 ) {
F_9 ( L_24 ,
V_17 ) ;
return - V_69 ;
}
F_30 ( & V_2 -> V_47 ) ;
V_73 = F_72 ( V_2 ) ;
F_31 ( & V_2 -> V_47 ) ;
if ( F_19 ( V_73 ) )
return F_21 ( V_73 ) ;
return 0 ;
}
static void F_122 ( struct V_96 * V_97 , T_1 V_128 ,
T_1 V_20 ,
enum V_94 V_95 )
{
struct V_1 * V_2 = V_97 -> V_98 ;
F_30 ( & V_2 -> V_47 ) ;
F_74 ( V_2 ) ;
F_31 ( & V_2 -> V_47 ) ;
}
struct V_96 * F_123 ( struct V_61 * V_62 ,
struct V_60 * V_63 )
{
struct V_1 * V_2 ;
struct V_96 * V_97 ;
bool V_70 ;
F_30 ( & V_62 -> V_47 ) ;
V_70 = F_60 ( V_62 , V_63 ) ;
if ( ! V_70 ) {
F_64 ( 1 , L_25 , V_17 ) ;
F_31 ( & V_62 -> V_47 ) ;
return F_15 ( - V_37 ) ;
}
V_2 = V_63 -> V_2 ;
F_39 ( V_2 ) ;
F_31 ( & V_62 -> V_47 ) ;
V_97 = F_124 ( V_2 , & V_129 , V_2 -> V_35 , V_130 ) ;
if ( F_19 ( V_97 ) ) {
F_41 ( V_2 ) ;
return V_97 ;
}
return V_97 ;
}
int F_125 ( struct V_61 * V_62 , struct V_60 * V_63 )
{
struct V_96 * V_97 ;
int V_131 ;
V_97 = F_123 ( V_62 , V_63 ) ;
if ( F_19 ( V_97 ) )
return F_21 ( V_97 ) ;
V_131 = F_126 ( V_97 , V_132 ) ;
if ( V_131 < 0 )
F_127 ( V_97 ) ;
return V_131 ;
}
struct V_60 * F_128 ( struct V_61 * V_62 , int V_131 )
{
struct V_96 * V_97 ;
struct V_1 * V_2 ;
struct V_60 * V_63 ;
int V_27 ;
V_97 = F_129 ( V_131 ) ;
if ( F_19 ( V_97 ) )
return F_15 ( F_21 ( V_97 ) ) ;
if ( V_97 -> V_31 != & V_129 ) {
F_9 ( L_26 ,
V_17 ) ;
F_127 ( V_97 ) ;
return F_15 ( - V_37 ) ;
}
V_2 = V_97 -> V_98 ;
F_30 ( & V_62 -> V_47 ) ;
V_63 = F_57 ( V_62 , V_2 ) ;
if ( ! F_19 ( V_63 ) ) {
F_55 ( V_63 ) ;
F_31 ( & V_62 -> V_47 ) ;
goto V_133;
}
F_31 ( & V_62 -> V_47 ) ;
V_63 = F_48 ( V_62 , V_2 ) ;
if ( F_19 ( V_63 ) )
goto V_133;
F_30 ( & V_62 -> V_47 ) ;
V_27 = F_62 ( V_62 , V_63 ) ;
F_31 ( & V_62 -> V_47 ) ;
if ( V_27 ) {
F_56 ( V_63 ) ;
V_63 = F_15 ( V_27 ) ;
}
V_133:
F_127 ( V_97 ) ;
return V_63 ;
}
static int F_130 ( struct V_61 * V_62 , int V_131 )
{
struct V_96 * V_97 ;
struct V_1 * V_2 ;
V_97 = F_129 ( V_131 ) ;
if ( F_19 ( V_97 ) )
return F_21 ( V_97 ) ;
if ( V_97 -> V_31 != & V_129 ) {
F_9 ( L_27 ,
V_17 ) ;
F_127 ( V_97 ) ;
return - V_37 ;
}
V_2 = V_97 -> V_98 ;
F_103 ( NULL , V_2 -> V_22 -> V_134 ,
V_2 -> V_22 -> V_135 , V_136 ) ;
F_127 ( V_97 ) ;
return 0 ;
}
static unsigned int F_131 ( unsigned int V_137 )
{
switch ( V_137 ) {
case V_138 :
case V_139 :
case V_140 :
return V_141 ;
default:
return F_132 ( V_137 ) ;
}
}
static long F_133 ( struct V_84 * V_142 , unsigned int V_137 , unsigned long V_143 )
{
struct V_61 * V_62 = V_142 -> V_144 ;
struct V_7 * V_8 = V_62 -> V_8 ;
struct V_60 * V_145 = NULL ;
int V_27 = 0 ;
unsigned int V_100 ;
union {
struct V_146 V_131 ;
struct V_147 V_148 ;
struct V_149 V_63 ;
struct V_150 V_151 ;
} V_152 ;
V_100 = F_131 ( V_137 ) ;
if ( F_134 ( V_137 ) > sizeof( V_152 ) )
return - V_37 ;
if ( V_100 & V_141 )
if ( F_135 ( & V_152 , ( void V_153 * ) V_143 , F_134 ( V_137 ) ) )
return - V_154 ;
switch ( V_137 ) {
case V_155 :
{
struct V_60 * V_63 ;
V_63 = F_65 ( V_62 , V_152 . V_148 . V_20 ,
V_152 . V_148 . V_21 ,
V_152 . V_148 . V_68 ,
V_152 . V_148 . V_3 ) ;
if ( F_19 ( V_63 ) )
return F_21 ( V_63 ) ;
V_152 . V_148 . V_63 = V_63 -> V_65 ;
V_145 = V_63 ;
break;
}
case V_139 :
{
struct V_60 * V_63 ;
V_63 = F_58 ( V_62 , V_152 . V_63 . V_63 ) ;
if ( F_19 ( V_63 ) )
return F_21 ( V_63 ) ;
F_70 ( V_62 , V_63 ) ;
F_56 ( V_63 ) ;
break;
}
case V_156 :
case V_157 :
{
struct V_60 * V_63 ;
V_63 = F_58 ( V_62 , V_152 . V_63 . V_63 ) ;
if ( F_19 ( V_63 ) )
return F_21 ( V_63 ) ;
V_152 . V_131 . V_131 = F_125 ( V_62 , V_63 ) ;
F_56 ( V_63 ) ;
if ( V_152 . V_131 . V_131 < 0 )
V_27 = V_152 . V_131 . V_131 ;
break;
}
case V_158 :
{
struct V_60 * V_63 ;
V_63 = F_128 ( V_62 , V_152 . V_131 . V_131 ) ;
if ( F_19 ( V_63 ) )
V_27 = F_21 ( V_63 ) ;
else
V_152 . V_63 . V_63 = V_63 -> V_65 ;
break;
}
case V_138 :
{
V_27 = F_130 ( V_62 , V_152 . V_131 . V_131 ) ;
break;
}
case V_140 :
{
if ( ! V_8 -> V_159 )
return - V_160 ;
V_27 = V_8 -> V_159 ( V_62 , V_152 . V_151 . V_137 ,
V_152 . V_151 . V_143 ) ;
break;
}
default:
return - V_160 ;
}
if ( V_100 & V_161 ) {
if ( F_136 ( ( void V_153 * ) V_143 , & V_152 , F_134 ( V_137 ) ) ) {
if ( V_145 )
F_70 ( V_62 , V_145 ) ;
return - V_154 ;
}
}
return V_27 ;
}
static int F_137 ( struct V_83 * V_83 , struct V_84 * V_84 )
{
struct V_61 * V_62 = V_84 -> V_144 ;
F_66 ( L_14 , V_17 , __LINE__ ) ;
F_92 ( V_62 ) ;
return 0 ;
}
static int F_138 ( struct V_83 * V_83 , struct V_84 * V_84 )
{
struct V_162 * V_163 = V_84 -> V_144 ;
struct V_7 * V_8 = F_36 ( V_163 , struct V_7 , V_8 ) ;
struct V_61 * V_62 ;
F_66 ( L_14 , V_17 , __LINE__ ) ;
V_62 = F_83 ( V_8 , L_28 ) ;
if ( F_19 ( V_62 ) )
return F_21 ( V_62 ) ;
V_84 -> V_144 = V_62 ;
return 0 ;
}
static T_1 F_139 ( struct V_61 * V_62 ,
unsigned int V_65 )
{
T_1 V_35 = 0 ;
struct V_9 * V_67 ;
F_30 ( & V_62 -> V_47 ) ;
for ( V_67 = F_78 ( & V_62 -> V_66 ) ; V_67 ; V_67 = F_79 ( V_67 ) ) {
struct V_60 * V_63 = F_8 ( V_67 ,
struct V_60 ,
V_14 ) ;
if ( V_63 -> V_2 -> V_19 -> V_65 == V_65 )
V_35 += V_63 -> V_2 -> V_35 ;
}
F_31 ( & V_62 -> V_47 ) ;
return V_35 ;
}
static int F_140 ( struct V_75 * V_76 , void * V_77 )
{
struct V_18 * V_19 = V_76 -> V_78 ;
struct V_7 * V_8 = V_19 -> V_8 ;
struct V_9 * V_67 ;
T_1 V_164 = 0 ;
T_1 V_165 = 0 ;
F_80 ( V_76 , L_29 , L_30 , L_31 , L_32 ) ;
F_80 ( V_76 , L_33 ) ;
for ( V_67 = F_78 ( & V_8 -> V_89 ) ; V_67 ; V_67 = F_79 ( V_67 ) ) {
struct V_61 * V_62 = F_8 ( V_67 , struct V_61 ,
V_14 ) ;
T_1 V_35 = F_139 ( V_62 , V_19 -> V_65 ) ;
if ( ! V_35 )
continue;
if ( V_62 -> V_55 ) {
char V_58 [ V_166 ] ;
F_46 ( V_58 , V_62 -> V_55 ) ;
F_80 ( V_76 , L_34 , V_58 ,
V_62 -> V_59 , V_35 ) ;
} else {
F_80 ( V_76 , L_34 , V_62 -> V_82 ,
V_62 -> V_59 , V_35 ) ;
}
}
F_80 ( V_76 , L_33 ) ;
F_80 ( V_76 , L_35
L_36 ) ;
F_30 ( & V_8 -> V_48 ) ;
for ( V_67 = F_78 ( & V_8 -> V_11 ) ; V_67 ; V_67 = F_79 ( V_67 ) ) {
struct V_1 * V_2 = F_8 ( V_67 , struct V_1 ,
V_14 ) ;
if ( V_2 -> V_19 -> V_65 != V_19 -> V_65 )
continue;
V_164 += V_2 -> V_35 ;
if ( ! V_2 -> V_53 ) {
F_80 ( V_76 , L_37 ,
V_2 -> V_58 , V_2 -> V_59 ,
V_2 -> V_35 , V_2 -> V_50 ,
F_141 ( & V_2 -> V_30 . V_167 ) ) ;
V_165 += V_2 -> V_35 ;
}
}
F_31 ( & V_8 -> V_48 ) ;
F_80 ( V_76 , L_33 ) ;
F_80 ( V_76 , L_38 , L_39 ,
V_165 ) ;
F_80 ( V_76 , L_38 , L_40 , V_164 ) ;
if ( V_19 -> V_3 & V_33 )
F_80 ( V_76 , L_38 , L_41 ,
V_19 -> V_168 ) ;
F_80 ( V_76 , L_33 ) ;
if ( V_19 -> V_169 )
V_19 -> V_169 ( V_19 , V_76 , V_77 ) ;
return 0 ;
}
static int F_142 ( struct V_83 * V_83 , struct V_84 * V_84 )
{
return F_82 ( V_84 , F_140 , V_83 -> V_85 ) ;
}
static int F_143 ( void * V_152 , T_4 V_170 )
{
struct V_18 * V_19 = V_152 ;
struct V_171 V_172 ;
int V_173 ;
V_172 . V_174 = - 1 ;
V_172 . V_175 = 0 ;
if ( ! V_170 )
return 0 ;
V_173 = V_19 -> V_176 . V_177 ( & V_19 -> V_176 , & V_172 ) ;
V_172 . V_175 = V_173 ;
V_19 -> V_176 . V_177 ( & V_19 -> V_176 , & V_172 ) ;
return 0 ;
}
static int F_144 ( void * V_152 , T_4 * V_170 )
{
struct V_18 * V_19 = V_152 ;
struct V_171 V_172 ;
int V_173 ;
V_172 . V_174 = - 1 ;
V_172 . V_175 = 0 ;
V_173 = V_19 -> V_176 . V_177 ( & V_19 -> V_176 , & V_172 ) ;
* V_170 = V_173 ;
return 0 ;
}
void F_145 ( struct V_7 * V_8 , struct V_18 * V_19 )
{
if ( ! V_19 -> V_31 -> V_32 || ! V_19 -> V_31 -> free || ! V_19 -> V_31 -> V_36 ||
! V_19 -> V_31 -> V_49 )
F_9 ( L_42 ,
V_17 ) ;
if ( V_19 -> V_3 & V_33 )
F_146 ( V_19 ) ;
V_19 -> V_8 = V_8 ;
F_89 ( & V_8 -> V_47 ) ;
F_147 ( & V_19 -> V_14 , - V_19 -> V_65 ) ;
F_148 ( & V_19 -> V_14 , & V_8 -> V_178 ) ;
F_90 ( V_19 -> V_82 , 0664 , V_8 -> V_90 , V_19 ,
& V_179 ) ;
#ifdef F_149
if ( V_19 -> V_176 . V_177 ) {
char V_86 [ 64 ] ;
snprintf ( V_86 , 64 , L_43 , V_19 -> V_82 ) ;
F_90 ( V_86 , 0644 , V_8 -> V_90 , V_19 ,
& V_180 ) ;
}
#endif
F_91 ( & V_8 -> V_47 ) ;
}
struct V_7 * F_150 ( long (* V_159)
( struct V_61 * V_62 ,
unsigned int V_137 ,
unsigned long V_143 ) )
{
struct V_7 * V_181 ;
int V_27 ;
V_181 = F_14 ( sizeof( struct V_7 ) , V_28 ) ;
if ( ! V_181 )
return F_15 ( - V_29 ) ;
V_181 -> V_8 . V_182 = V_183 ;
V_181 -> V_8 . V_82 = L_44 ;
V_181 -> V_8 . V_184 = & V_185 ;
V_181 -> V_8 . V_12 = NULL ;
V_27 = F_151 ( & V_181 -> V_8 ) ;
if ( V_27 ) {
F_9 ( L_45 ) ;
return F_15 ( V_27 ) ;
}
V_181 -> V_90 = F_152 ( L_44 , NULL ) ;
if ( ! V_181 -> V_90 )
F_9 ( L_46 ) ;
V_181 -> V_159 = V_159 ;
V_181 -> V_11 = V_88 ;
F_27 ( & V_181 -> V_48 ) ;
F_153 ( & V_181 -> V_47 ) ;
F_154 ( & V_181 -> V_178 ) ;
V_181 -> V_89 = V_88 ;
return V_181 ;
}
void F_155 ( struct V_7 * V_8 )
{
F_156 ( & V_8 -> V_8 ) ;
F_20 ( V_8 ) ;
}
void T_5 F_157 ( struct V_186 * V_152 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_152 -> V_187 ; V_26 ++ ) {
if ( V_152 -> V_178 [ V_26 ] . V_35 == 0 )
continue;
if ( V_152 -> V_178 [ V_26 ] . V_188 == 0 ) {
T_6 V_189 ;
V_189 = F_158 ( V_152 -> V_178 [ V_26 ] . V_35 ,
V_152 -> V_178 [ V_26 ] . V_21 ,
V_190 ) ;
if ( ! V_189 ) {
F_9 ( L_47
L_48 ,
V_17 , V_26 ) ;
continue;
}
V_152 -> V_178 [ V_26 ] . V_188 = V_189 ;
} else {
int V_27 = F_159 ( V_152 -> V_178 [ V_26 ] . V_188 ,
V_152 -> V_178 [ V_26 ] . V_35 ) ;
if ( V_27 )
F_9 ( L_49 ,
V_152 -> V_178 [ V_26 ] . V_35 ,
V_152 -> V_178 [ V_26 ] . V_188 ) ;
}
F_160 ( L_50 , V_17 ,
V_152 -> V_178 [ V_26 ] . V_82 ,
V_152 -> V_178 [ V_26 ] . V_188 ,
V_152 -> V_178 [ V_26 ] . V_35 ) ;
}
}
