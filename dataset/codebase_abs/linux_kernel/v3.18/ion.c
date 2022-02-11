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
return F_21 ( V_23 ) ;
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
return F_59 ( & V_62 -> V_64 , V_63 -> V_65 ) == V_63 ;
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
return F_21 ( V_2 ) ;
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
if ( ! V_63 -> V_50 ) {
F_64 ( 1 , L_7 , V_17 ) ;
return;
}
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
F_9 ( L_8 ,
V_17 ) ;
F_31 ( & V_62 -> V_47 ) ;
return F_15 ( - V_37 ) ;
}
V_2 = V_63 -> V_2 ;
if ( ! V_63 -> V_2 -> V_19 -> V_31 -> V_74 ) {
F_9 ( L_9 ,
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
F_80 ( V_76 , L_10 , L_11 , L_12 ) ;
for ( V_26 = 0 ; V_26 < V_80 ; V_26 ++ ) {
if ( ! V_81 [ V_26 ] )
continue;
F_80 ( V_76 , L_13 , V_81 [ V_26 ] , V_79 [ V_26 ] ) ;
}
return 0 ;
}
static int F_81 ( struct V_83 * V_83 , struct V_84 * V_84 )
{
return F_82 ( V_84 , F_77 , V_83 -> V_85 ) ;
}
static int F_83 ( const struct V_86 * V_87 ,
const unsigned char * V_82 )
{
int V_88 = - 1 ;
struct V_9 * V_14 ;
for ( V_14 = F_78 ( V_87 ) ; V_14 ; V_14 = F_79 ( V_14 ) ) {
struct V_61 * V_62 = F_8 ( V_14 , struct V_61 ,
V_14 ) ;
if ( strcmp ( V_62 -> V_82 , V_82 ) )
continue;
V_88 = F_84 ( V_88 , V_62 -> V_89 ) ;
}
return V_88 + 1 ;
}
struct V_61 * F_85 ( struct V_7 * V_8 ,
const char * V_82 )
{
struct V_61 * V_62 ;
struct V_54 * V_55 ;
struct V_9 * * V_10 ;
struct V_9 * V_12 = NULL ;
struct V_61 * V_13 ;
T_3 V_59 ;
if ( ! V_82 ) {
F_9 ( L_14 , V_17 ) ;
return F_15 ( - V_37 ) ;
}
F_86 ( V_56 -> V_57 ) ;
F_87 ( V_56 -> V_57 ) ;
V_59 = F_47 ( V_56 -> V_57 ) ;
if ( V_56 -> V_57 -> V_3 & V_90 ) {
F_88 ( V_56 -> V_57 ) ;
V_55 = NULL ;
} else {
V_55 = V_56 -> V_57 ;
}
F_89 ( V_56 -> V_57 ) ;
V_62 = F_14 ( sizeof( struct V_61 ) , V_28 ) ;
if ( ! V_62 )
goto V_91;
V_62 -> V_8 = V_8 ;
V_62 -> V_66 = V_92 ;
F_90 ( & V_62 -> V_64 ) ;
F_27 ( & V_62 -> V_47 ) ;
V_62 -> V_55 = V_55 ;
V_62 -> V_59 = V_59 ;
V_62 -> V_82 = F_91 ( V_82 , V_28 ) ;
if ( ! V_62 -> V_82 )
goto V_93;
F_92 ( & V_8 -> V_47 ) ;
V_62 -> V_89 = F_83 ( & V_8 -> V_94 , V_82 ) ;
V_62 -> V_95 = F_93 (
V_28 , L_15 , V_82 , V_62 -> V_89 ) ;
if ( ! V_62 -> V_95 ) {
F_94 ( & V_8 -> V_47 ) ;
goto V_96;
}
V_10 = & V_8 -> V_94 . V_9 ;
while ( * V_10 ) {
V_12 = * V_10 ;
V_13 = F_8 ( V_12 , struct V_61 , V_14 ) ;
if ( V_62 < V_13 )
V_10 = & ( * V_10 ) -> V_15 ;
else if ( V_62 > V_13 )
V_10 = & ( * V_10 ) -> V_16 ;
}
F_11 ( & V_62 -> V_14 , V_12 , V_10 ) ;
F_12 ( & V_62 -> V_14 , & V_8 -> V_94 ) ;
V_62 -> V_97 = F_95 ( V_62 -> V_95 , 0664 ,
V_8 -> V_98 ,
V_62 , & V_99 ) ;
if ( ! V_62 -> V_97 ) {
char V_100 [ 256 ] , * V_101 ;
V_101 = F_96 ( V_8 -> V_98 , V_100 , 256 ) ;
F_9 ( L_16 ,
V_101 , V_62 -> V_95 ) ;
}
F_94 ( & V_8 -> V_47 ) ;
return V_62 ;
V_96:
F_20 ( V_62 -> V_82 ) ;
V_93:
F_20 ( V_62 ) ;
V_91:
if ( V_55 )
F_88 ( V_56 -> V_57 ) ;
return F_15 ( - V_29 ) ;
}
void F_97 ( struct V_61 * V_62 )
{
struct V_7 * V_8 = V_62 -> V_8 ;
struct V_9 * V_67 ;
F_66 ( L_17 , V_17 , __LINE__ ) ;
while ( ( V_67 = F_78 ( & V_62 -> V_66 ) ) ) {
struct V_60 * V_63 = F_8 ( V_67 , struct V_60 ,
V_14 ) ;
F_50 ( & V_63 -> V_30 ) ;
}
F_98 ( & V_62 -> V_64 ) ;
F_92 ( & V_8 -> V_47 ) ;
if ( V_62 -> V_55 )
F_88 ( V_62 -> V_55 ) ;
F_37 ( & V_62 -> V_14 , & V_8 -> V_94 ) ;
F_99 ( V_62 -> V_97 ) ;
F_94 ( & V_8 -> V_47 ) ;
F_20 ( V_62 -> V_95 ) ;
F_20 ( V_62 -> V_82 ) ;
F_20 ( V_62 ) ;
}
struct V_22 * F_100 ( struct V_61 * V_62 ,
struct V_60 * V_63 )
{
struct V_1 * V_2 ;
struct V_22 * V_23 ;
F_30 ( & V_62 -> V_47 ) ;
if ( ! F_60 ( V_62 , V_63 ) ) {
F_9 ( L_18 ,
V_17 ) ;
F_31 ( & V_62 -> V_47 ) ;
return F_15 ( - V_37 ) ;
}
V_2 = V_63 -> V_2 ;
V_23 = V_2 -> V_22 ;
F_31 ( & V_62 -> V_47 ) ;
return V_23 ;
}
static struct V_22 * F_101 ( struct V_102 * V_103 ,
enum V_104 V_105 )
{
struct V_106 * V_107 = V_103 -> V_107 ;
struct V_1 * V_2 = V_107 -> V_108 ;
F_102 ( V_2 , V_103 -> V_8 , V_105 ) ;
return V_2 -> V_22 ;
}
static void F_103 ( struct V_102 * V_103 ,
struct V_22 * V_23 ,
enum V_104 V_105 )
{
}
void F_104 ( struct V_109 * V_8 , struct V_6 * V_6 ,
T_1 V_35 , enum V_104 V_110 )
{
struct V_24 V_25 ;
F_105 ( & V_25 , 1 ) ;
F_106 ( & V_25 , V_6 , V_35 , 0 ) ;
F_28 ( & V_25 ) = F_107 ( V_6 ) ;
F_108 ( V_8 , & V_25 , 1 , V_110 ) ;
}
static void F_102 ( struct V_1 * V_2 ,
struct V_109 * V_8 ,
enum V_104 V_110 )
{
struct V_111 * V_112 ;
int V_42 = F_22 ( V_2 -> V_35 ) / V_39 ;
int V_26 ;
F_66 ( L_19 , V_17 ,
V_8 ? F_109 ( V_8 ) : L_20 ) ;
if ( ! F_1 ( V_2 ) )
return;
F_30 ( & V_2 -> V_47 ) ;
for ( V_26 = 0 ; V_26 < V_42 ; V_26 ++ ) {
struct V_6 * V_6 = V_2 -> V_42 [ V_26 ] ;
if ( F_4 ( V_6 ) )
F_104 ( V_8 , F_3 ( V_6 ) ,
V_39 , V_110 ) ;
F_6 ( V_2 -> V_42 + V_26 ) ;
}
F_110 (vma_list, &buffer->vmas, list) {
struct V_113 * V_114 = V_112 -> V_114 ;
F_111 ( V_114 , V_114 -> V_115 , V_114 -> V_116 - V_114 -> V_115 ,
NULL ) ;
}
F_31 ( & V_2 -> V_47 ) ;
}
static int F_112 ( struct V_113 * V_114 , struct V_117 * V_118 )
{
struct V_1 * V_2 = V_114 -> V_119 ;
unsigned long V_120 ;
int V_27 ;
F_30 ( & V_2 -> V_47 ) ;
F_5 ( V_2 -> V_42 + V_118 -> V_121 ) ;
F_45 ( ! V_2 -> V_42 || ! V_2 -> V_42 [ V_118 -> V_121 ] ) ;
V_120 = F_113 ( F_3 ( V_2 -> V_42 [ V_118 -> V_121 ] ) ) ;
V_27 = F_114 ( V_114 , ( unsigned long ) V_118 -> V_122 , V_120 ) ;
F_31 ( & V_2 -> V_47 ) ;
if ( V_27 )
return V_123 ;
return V_124 ;
}
static void F_115 ( struct V_113 * V_114 )
{
struct V_1 * V_2 = V_114 -> V_119 ;
struct V_111 * V_112 ;
V_112 = F_116 ( sizeof( struct V_111 ) , V_28 ) ;
if ( ! V_112 )
return;
V_112 -> V_114 = V_114 ;
F_30 ( & V_2 -> V_47 ) ;
F_117 ( & V_112 -> V_125 , & V_2 -> V_46 ) ;
F_31 ( & V_2 -> V_47 ) ;
F_66 ( L_21 , V_17 , V_114 ) ;
}
static void F_118 ( struct V_113 * V_114 )
{
struct V_1 * V_2 = V_114 -> V_119 ;
struct V_111 * V_112 , * V_126 ;
F_66 ( L_22 , V_17 ) ;
F_30 ( & V_2 -> V_47 ) ;
F_119 (vma_list, tmp, &buffer->vmas, list) {
if ( V_112 -> V_114 != V_114 )
continue;
F_120 ( & V_112 -> V_125 ) ;
F_20 ( V_112 ) ;
F_66 ( L_23 , V_17 , V_114 ) ;
break;
}
F_31 ( & V_2 -> V_47 ) ;
}
static int F_121 ( struct V_106 * V_107 , struct V_113 * V_114 )
{
struct V_1 * V_2 = V_107 -> V_108 ;
int V_27 = 0 ;
if ( ! V_2 -> V_19 -> V_31 -> V_127 ) {
F_9 ( L_24 ,
V_17 ) ;
return - V_37 ;
}
if ( F_1 ( V_2 ) ) {
V_114 -> V_128 |= V_129 | V_130 | V_131 |
V_132 ;
V_114 -> V_119 = V_2 ;
V_114 -> V_133 = & V_134 ;
F_115 ( V_114 ) ;
return 0 ;
}
if ( ! ( V_2 -> V_3 & V_4 ) )
V_114 -> V_135 = F_122 ( V_114 -> V_135 ) ;
F_30 ( & V_2 -> V_47 ) ;
V_27 = V_2 -> V_19 -> V_31 -> V_127 ( V_2 -> V_19 , V_2 , V_114 ) ;
F_31 ( & V_2 -> V_47 ) ;
if ( V_27 )
F_9 ( L_25 ,
V_17 ) ;
return V_27 ;
}
static void F_123 ( struct V_106 * V_107 )
{
struct V_1 * V_2 = V_107 -> V_108 ;
F_41 ( V_2 ) ;
}
static void * F_124 ( struct V_106 * V_107 , unsigned long V_136 )
{
struct V_1 * V_2 = V_107 -> V_108 ;
return V_2 -> V_73 + V_136 * V_39 ;
}
static void F_125 ( struct V_106 * V_107 , unsigned long V_136 ,
void * V_137 )
{
}
static int F_126 ( struct V_106 * V_107 , T_1 V_138 ,
T_1 V_20 ,
enum V_104 V_105 )
{
struct V_1 * V_2 = V_107 -> V_108 ;
void * V_73 ;
if ( ! V_2 -> V_19 -> V_31 -> V_74 ) {
F_9 ( L_26 ,
V_17 ) ;
return - V_69 ;
}
F_30 ( & V_2 -> V_47 ) ;
V_73 = F_72 ( V_2 ) ;
F_31 ( & V_2 -> V_47 ) ;
return F_127 ( V_73 ) ;
}
static void F_128 ( struct V_106 * V_107 , T_1 V_138 ,
T_1 V_20 ,
enum V_104 V_105 )
{
struct V_1 * V_2 = V_107 -> V_108 ;
F_30 ( & V_2 -> V_47 ) ;
F_74 ( V_2 ) ;
F_31 ( & V_2 -> V_47 ) ;
}
struct V_106 * F_129 ( struct V_61 * V_62 ,
struct V_60 * V_63 )
{
struct V_1 * V_2 ;
struct V_106 * V_107 ;
bool V_70 ;
F_30 ( & V_62 -> V_47 ) ;
V_70 = F_60 ( V_62 , V_63 ) ;
if ( ! V_70 ) {
F_64 ( 1 , L_27 , V_17 ) ;
F_31 ( & V_62 -> V_47 ) ;
return F_15 ( - V_37 ) ;
}
V_2 = V_63 -> V_2 ;
F_39 ( V_2 ) ;
F_31 ( & V_62 -> V_47 ) ;
V_107 = F_130 ( V_2 , & V_139 , V_2 -> V_35 , V_140 ,
NULL ) ;
if ( F_19 ( V_107 ) ) {
F_41 ( V_2 ) ;
return V_107 ;
}
return V_107 ;
}
int F_131 ( struct V_61 * V_62 , struct V_60 * V_63 )
{
struct V_106 * V_107 ;
int V_141 ;
V_107 = F_129 ( V_62 , V_63 ) ;
if ( F_19 ( V_107 ) )
return F_132 ( V_107 ) ;
V_141 = F_133 ( V_107 , V_142 ) ;
if ( V_141 < 0 )
F_134 ( V_107 ) ;
return V_141 ;
}
struct V_60 * F_135 ( struct V_61 * V_62 , int V_141 )
{
struct V_106 * V_107 ;
struct V_1 * V_2 ;
struct V_60 * V_63 ;
int V_27 ;
V_107 = F_136 ( V_141 ) ;
if ( F_19 ( V_107 ) )
return F_21 ( V_107 ) ;
if ( V_107 -> V_31 != & V_139 ) {
F_9 ( L_28 ,
V_17 ) ;
F_134 ( V_107 ) ;
return F_15 ( - V_37 ) ;
}
V_2 = V_107 -> V_108 ;
F_30 ( & V_62 -> V_47 ) ;
V_63 = F_57 ( V_62 , V_2 ) ;
if ( ! F_19 ( V_63 ) ) {
F_55 ( V_63 ) ;
F_31 ( & V_62 -> V_47 ) ;
goto V_143;
}
F_31 ( & V_62 -> V_47 ) ;
V_63 = F_48 ( V_62 , V_2 ) ;
if ( F_19 ( V_63 ) )
goto V_143;
F_30 ( & V_62 -> V_47 ) ;
V_27 = F_62 ( V_62 , V_63 ) ;
F_31 ( & V_62 -> V_47 ) ;
if ( V_27 ) {
F_56 ( V_63 ) ;
V_63 = F_15 ( V_27 ) ;
}
V_143:
F_134 ( V_107 ) ;
return V_63 ;
}
static int F_137 ( struct V_61 * V_62 , int V_141 )
{
struct V_106 * V_107 ;
struct V_1 * V_2 ;
V_107 = F_136 ( V_141 ) ;
if ( F_19 ( V_107 ) )
return F_132 ( V_107 ) ;
if ( V_107 -> V_31 != & V_139 ) {
F_9 ( L_29 ,
V_17 ) ;
F_134 ( V_107 ) ;
return - V_37 ;
}
V_2 = V_107 -> V_108 ;
F_108 ( NULL , V_2 -> V_22 -> V_144 ,
V_2 -> V_22 -> V_145 , V_146 ) ;
F_134 ( V_107 ) ;
return 0 ;
}
static unsigned int F_138 ( unsigned int V_147 )
{
switch ( V_147 ) {
case V_148 :
case V_149 :
case V_150 :
return V_151 ;
default:
return F_139 ( V_147 ) ;
}
}
static long F_140 ( struct V_84 * V_152 , unsigned int V_147 , unsigned long V_153 )
{
struct V_61 * V_62 = V_152 -> V_154 ;
struct V_7 * V_8 = V_62 -> V_8 ;
struct V_60 * V_155 = NULL ;
int V_27 = 0 ;
unsigned int V_110 ;
union {
struct V_156 V_141 ;
struct V_157 V_158 ;
struct V_159 V_63 ;
struct V_160 V_161 ;
} V_162 ;
V_110 = F_138 ( V_147 ) ;
if ( F_141 ( V_147 ) > sizeof( V_162 ) )
return - V_37 ;
if ( V_110 & V_151 )
if ( F_142 ( & V_162 , ( void V_163 * ) V_153 , F_141 ( V_147 ) ) )
return - V_164 ;
switch ( V_147 ) {
case V_165 :
{
struct V_60 * V_63 ;
V_63 = F_65 ( V_62 , V_162 . V_158 . V_20 ,
V_162 . V_158 . V_21 ,
V_162 . V_158 . V_68 ,
V_162 . V_158 . V_3 ) ;
if ( F_19 ( V_63 ) )
return F_132 ( V_63 ) ;
V_162 . V_158 . V_63 = V_63 -> V_65 ;
V_155 = V_63 ;
break;
}
case V_149 :
{
struct V_60 * V_63 ;
V_63 = F_58 ( V_62 , V_162 . V_63 . V_63 ) ;
if ( F_19 ( V_63 ) )
return F_132 ( V_63 ) ;
F_70 ( V_62 , V_63 ) ;
F_56 ( V_63 ) ;
break;
}
case V_166 :
case V_167 :
{
struct V_60 * V_63 ;
V_63 = F_58 ( V_62 , V_162 . V_63 . V_63 ) ;
if ( F_19 ( V_63 ) )
return F_132 ( V_63 ) ;
V_162 . V_141 . V_141 = F_131 ( V_62 , V_63 ) ;
F_56 ( V_63 ) ;
if ( V_162 . V_141 . V_141 < 0 )
V_27 = V_162 . V_141 . V_141 ;
break;
}
case V_168 :
{
struct V_60 * V_63 ;
V_63 = F_135 ( V_62 , V_162 . V_141 . V_141 ) ;
if ( F_19 ( V_63 ) )
V_27 = F_132 ( V_63 ) ;
else
V_162 . V_63 . V_63 = V_63 -> V_65 ;
break;
}
case V_148 :
{
V_27 = F_137 ( V_62 , V_162 . V_141 . V_141 ) ;
break;
}
case V_150 :
{
if ( ! V_8 -> V_169 )
return - V_170 ;
V_27 = V_8 -> V_169 ( V_62 , V_162 . V_161 . V_147 ,
V_162 . V_161 . V_153 ) ;
break;
}
default:
return - V_170 ;
}
if ( V_110 & V_171 ) {
if ( F_143 ( ( void V_163 * ) V_153 , & V_162 , F_141 ( V_147 ) ) ) {
if ( V_155 )
F_70 ( V_62 , V_155 ) ;
return - V_164 ;
}
}
return V_27 ;
}
static int F_144 ( struct V_83 * V_83 , struct V_84 * V_84 )
{
struct V_61 * V_62 = V_84 -> V_154 ;
F_66 ( L_17 , V_17 , __LINE__ ) ;
F_97 ( V_62 ) ;
return 0 ;
}
static int F_145 ( struct V_83 * V_83 , struct V_84 * V_84 )
{
struct V_172 * V_173 = V_84 -> V_154 ;
struct V_7 * V_8 = F_36 ( V_173 , struct V_7 , V_8 ) ;
struct V_61 * V_62 ;
char V_174 [ 64 ] ;
F_66 ( L_17 , V_17 , __LINE__ ) ;
snprintf ( V_174 , 64 , L_30 , F_47 ( V_56 -> V_57 ) ) ;
V_62 = F_85 ( V_8 , V_174 ) ;
if ( F_19 ( V_62 ) )
return F_132 ( V_62 ) ;
V_84 -> V_154 = V_62 ;
return 0 ;
}
static T_1 F_146 ( struct V_61 * V_62 ,
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
static int F_147 ( struct V_75 * V_76 , void * V_77 )
{
struct V_18 * V_19 = V_76 -> V_78 ;
struct V_7 * V_8 = V_19 -> V_8 ;
struct V_9 * V_67 ;
T_1 V_175 = 0 ;
T_1 V_176 = 0 ;
F_80 ( V_76 , L_31 , L_32 , L_33 , L_34 ) ;
F_148 ( V_76 , L_35 ) ;
for ( V_67 = F_78 ( & V_8 -> V_94 ) ; V_67 ; V_67 = F_79 ( V_67 ) ) {
struct V_61 * V_62 = F_8 ( V_67 , struct V_61 ,
V_14 ) ;
T_1 V_35 = F_146 ( V_62 , V_19 -> V_65 ) ;
if ( ! V_35 )
continue;
if ( V_62 -> V_55 ) {
char V_58 [ V_177 ] ;
F_46 ( V_58 , V_62 -> V_55 ) ;
F_80 ( V_76 , L_36 , V_58 ,
V_62 -> V_59 , V_35 ) ;
} else {
F_80 ( V_76 , L_36 , V_62 -> V_82 ,
V_62 -> V_59 , V_35 ) ;
}
}
F_148 ( V_76 , L_35 ) ;
F_148 ( V_76 , L_37 ) ;
F_30 ( & V_8 -> V_48 ) ;
for ( V_67 = F_78 ( & V_8 -> V_11 ) ; V_67 ; V_67 = F_79 ( V_67 ) ) {
struct V_1 * V_2 = F_8 ( V_67 , struct V_1 ,
V_14 ) ;
if ( V_2 -> V_19 -> V_65 != V_19 -> V_65 )
continue;
V_175 += V_2 -> V_35 ;
if ( ! V_2 -> V_53 ) {
F_80 ( V_76 , L_38 ,
V_2 -> V_58 , V_2 -> V_59 ,
V_2 -> V_35 , V_2 -> V_50 ,
F_149 ( & V_2 -> V_30 . V_178 ) ) ;
V_176 += V_2 -> V_35 ;
}
}
F_31 ( & V_8 -> V_48 ) ;
F_148 ( V_76 , L_35 ) ;
F_80 ( V_76 , L_39 , L_40 ,
V_176 ) ;
F_80 ( V_76 , L_39 , L_41 , V_175 ) ;
if ( V_19 -> V_3 & V_33 )
F_80 ( V_76 , L_39 , L_42 ,
V_19 -> V_179 ) ;
F_148 ( V_76 , L_35 ) ;
if ( V_19 -> V_180 )
V_19 -> V_180 ( V_19 , V_76 , V_77 ) ;
return 0 ;
}
static int F_150 ( struct V_83 * V_83 , struct V_84 * V_84 )
{
return F_82 ( V_84 , F_147 , V_83 -> V_85 ) ;
}
static int F_151 ( void * V_162 , T_4 V_181 )
{
struct V_18 * V_19 = V_162 ;
struct V_182 V_183 ;
int V_184 ;
V_183 . V_185 = - 1 ;
V_183 . V_186 = 0 ;
if ( ! V_181 )
return 0 ;
V_184 = V_19 -> V_187 . V_188 ( & V_19 -> V_187 , & V_183 ) ;
V_183 . V_186 = V_184 ;
V_19 -> V_187 . V_188 ( & V_19 -> V_187 , & V_183 ) ;
return 0 ;
}
static int F_152 ( void * V_162 , T_4 * V_181 )
{
struct V_18 * V_19 = V_162 ;
struct V_182 V_183 ;
int V_184 ;
V_183 . V_185 = - 1 ;
V_183 . V_186 = 0 ;
V_184 = V_19 -> V_187 . V_188 ( & V_19 -> V_187 , & V_183 ) ;
* V_181 = V_184 ;
return 0 ;
}
void F_153 ( struct V_7 * V_8 , struct V_18 * V_19 )
{
struct V_189 * V_190 ;
if ( ! V_19 -> V_31 -> V_32 || ! V_19 -> V_31 -> free || ! V_19 -> V_31 -> V_36 ||
! V_19 -> V_31 -> V_49 )
F_9 ( L_43 ,
V_17 ) ;
if ( V_19 -> V_3 & V_33 )
F_154 ( V_19 ) ;
if ( ( V_19 -> V_3 & V_33 ) || V_19 -> V_31 -> V_188 )
F_155 ( V_19 ) ;
V_19 -> V_8 = V_8 ;
F_92 ( & V_8 -> V_47 ) ;
F_156 ( & V_19 -> V_14 , - V_19 -> V_65 ) ;
F_157 ( & V_19 -> V_14 , & V_8 -> V_191 ) ;
V_190 = F_95 ( V_19 -> V_82 , 0664 ,
V_8 -> V_192 , V_19 ,
& V_193 ) ;
if ( ! V_190 ) {
char V_100 [ 256 ] , * V_101 ;
V_101 = F_96 ( V_8 -> V_192 , V_100 , 256 ) ;
F_9 ( L_44 ,
V_101 , V_19 -> V_82 ) ;
}
#ifdef F_158
if ( V_19 -> V_187 . V_188 ) {
char V_174 [ 64 ] ;
snprintf ( V_174 , 64 , L_45 , V_19 -> V_82 ) ;
V_190 = F_95 (
V_174 , 0644 , V_8 -> V_192 , V_19 ,
& V_194 ) ;
if ( ! V_190 ) {
char V_100 [ 256 ] , * V_101 ;
V_101 = F_96 ( V_8 -> V_192 , V_100 , 256 ) ;
F_9 ( L_46 ,
V_101 , V_174 ) ;
}
}
#endif
F_94 ( & V_8 -> V_47 ) ;
}
struct V_7 * F_159 ( long (* V_169)
( struct V_61 * V_62 ,
unsigned int V_147 ,
unsigned long V_153 ) )
{
struct V_7 * V_195 ;
int V_27 ;
V_195 = F_14 ( sizeof( struct V_7 ) , V_28 ) ;
if ( ! V_195 )
return F_15 ( - V_29 ) ;
V_195 -> V_8 . V_196 = V_197 ;
V_195 -> V_8 . V_82 = L_47 ;
V_195 -> V_8 . V_198 = & V_199 ;
V_195 -> V_8 . V_12 = NULL ;
V_27 = F_160 ( & V_195 -> V_8 ) ;
if ( V_27 ) {
F_9 ( L_48 ) ;
return F_15 ( V_27 ) ;
}
V_195 -> V_97 = F_161 ( L_47 , NULL ) ;
if ( ! V_195 -> V_97 ) {
F_9 ( L_49 ) ;
goto V_200;
}
V_195 -> V_192 = F_161 ( L_50 , V_195 -> V_97 ) ;
if ( ! V_195 -> V_192 ) {
F_9 ( L_51 ) ;
goto V_200;
}
V_195 -> V_98 = F_161 ( L_52 ,
V_195 -> V_97 ) ;
if ( ! V_195 -> V_98 )
F_9 ( L_53 ) ;
V_200:
V_195 -> V_169 = V_169 ;
V_195 -> V_11 = V_92 ;
F_27 ( & V_195 -> V_48 ) ;
F_162 ( & V_195 -> V_47 ) ;
F_163 ( & V_195 -> V_191 ) ;
V_195 -> V_94 = V_92 ;
return V_195 ;
}
void F_164 ( struct V_7 * V_8 )
{
F_165 ( & V_8 -> V_8 ) ;
F_99 ( V_8 -> V_97 ) ;
F_20 ( V_8 ) ;
}
void T_5 F_166 ( struct V_201 * V_162 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_162 -> V_202 ; V_26 ++ ) {
if ( V_162 -> V_191 [ V_26 ] . V_35 == 0 )
continue;
if ( V_162 -> V_191 [ V_26 ] . V_203 == 0 ) {
T_6 V_204 ;
V_204 = F_167 ( V_162 -> V_191 [ V_26 ] . V_35 ,
V_162 -> V_191 [ V_26 ] . V_21 ,
V_205 ) ;
if ( ! V_204 ) {
F_9 ( L_54 ,
V_17 , V_26 ) ;
continue;
}
V_162 -> V_191 [ V_26 ] . V_203 = V_204 ;
} else {
int V_27 = F_168 ( V_162 -> V_191 [ V_26 ] . V_203 ,
V_162 -> V_191 [ V_26 ] . V_35 ) ;
if ( V_27 )
F_9 ( L_55 ,
V_162 -> V_191 [ V_26 ] . V_35 ,
V_162 -> V_191 [ V_26 ] . V_203 ) ;
}
F_169 ( L_56 , V_17 ,
V_162 -> V_191 [ V_26 ] . V_82 ,
V_162 -> V_191 [ V_26 ] . V_203 ,
V_162 -> V_191 [ V_26 ] . V_35 ) ;
}
}
