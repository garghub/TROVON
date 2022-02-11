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
V_17 , V_2 -> V_19 -> V_73 , V_2 -> V_19 -> type ) ;
F_31 ( & V_62 -> V_47 ) ;
return - V_69 ;
}
F_31 ( & V_62 -> V_47 ) ;
V_27 = V_2 -> V_19 -> V_31 -> V_72 ( V_2 -> V_19 , V_2 , V_71 , V_20 ) ;
return V_27 ;
}
static void * F_72 ( struct V_1 * V_2 )
{
void * V_74 ;
if ( V_2 -> V_50 ) {
V_2 -> V_50 ++ ;
return V_2 -> V_74 ;
}
V_74 = V_2 -> V_19 -> V_31 -> V_75 ( V_2 -> V_19 , V_2 ) ;
if ( F_18 ( V_74 == NULL ,
L_6 ) )
return F_15 ( - V_37 ) ;
if ( F_19 ( V_74 ) )
return V_74 ;
V_2 -> V_74 = V_74 ;
V_2 -> V_50 ++ ;
return V_74 ;
}
static void * F_73 ( struct V_60 * V_63 )
{
struct V_1 * V_2 = V_63 -> V_2 ;
void * V_74 ;
if ( V_63 -> V_50 ) {
V_63 -> V_50 ++ ;
return V_2 -> V_74 ;
}
V_74 = F_72 ( V_2 ) ;
if ( F_19 ( V_74 ) )
return V_74 ;
V_63 -> V_50 ++ ;
return V_74 ;
}
static void F_74 ( struct V_1 * V_2 )
{
V_2 -> V_50 -- ;
if ( ! V_2 -> V_50 ) {
V_2 -> V_19 -> V_31 -> V_51 ( V_2 -> V_19 , V_2 ) ;
V_2 -> V_74 = NULL ;
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
void * V_74 ;
F_30 ( & V_62 -> V_47 ) ;
if ( ! F_60 ( V_62 , V_63 ) ) {
F_9 ( L_8 ,
V_17 ) ;
F_31 ( & V_62 -> V_47 ) ;
return F_15 ( - V_37 ) ;
}
V_2 = V_63 -> V_2 ;
if ( ! V_63 -> V_2 -> V_19 -> V_31 -> V_75 ) {
F_9 ( L_9 ,
V_17 ) ;
F_31 ( & V_62 -> V_47 ) ;
return F_15 ( - V_69 ) ;
}
F_30 ( & V_2 -> V_47 ) ;
V_74 = F_73 ( V_63 ) ;
F_31 ( & V_2 -> V_47 ) ;
F_31 ( & V_62 -> V_47 ) ;
return V_74 ;
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
static int F_77 ( struct V_76 * V_77 , void * V_78 )
{
struct V_61 * V_62 = V_77 -> V_79 ;
struct V_9 * V_67 ;
T_1 V_80 [ V_81 ] = { 0 } ;
const char * V_82 [ V_81 ] = { NULL } ;
int V_26 ;
F_30 ( & V_62 -> V_47 ) ;
for ( V_67 = F_78 ( & V_62 -> V_66 ) ; V_67 ; V_67 = F_79 ( V_67 ) ) {
struct V_60 * V_63 = F_8 ( V_67 , struct V_60 ,
V_14 ) ;
unsigned int V_65 = V_63 -> V_2 -> V_19 -> V_65 ;
if ( ! V_82 [ V_65 ] )
V_82 [ V_65 ] = V_63 -> V_2 -> V_19 -> V_73 ;
V_80 [ V_65 ] += V_63 -> V_2 -> V_35 ;
}
F_31 ( & V_62 -> V_47 ) ;
F_80 ( V_77 , L_10 , L_11 , L_12 ) ;
for ( V_26 = 0 ; V_26 < V_81 ; V_26 ++ ) {
if ( ! V_82 [ V_26 ] )
continue;
F_80 ( V_77 , L_13 , V_82 [ V_26 ] , V_80 [ V_26 ] ) ;
}
return 0 ;
}
static int F_81 ( struct V_83 * V_83 , struct V_84 * V_84 )
{
return F_82 ( V_84 , F_77 , V_83 -> V_85 ) ;
}
static int F_83 ( const struct V_86 * V_87 ,
const unsigned char * V_73 )
{
int V_88 = - 1 ;
struct V_9 * V_14 ;
for ( V_14 = F_78 ( V_87 ) ; V_14 ; V_14 = F_79 ( V_14 ) ) {
struct V_61 * V_62 = F_8 ( V_14 , struct V_61 ,
V_14 ) ;
if ( strcmp ( V_62 -> V_73 , V_73 ) )
continue;
V_88 = F_84 ( V_88 , V_62 -> V_89 ) ;
}
return V_88 + 1 ;
}
struct V_61 * F_85 ( struct V_7 * V_8 ,
const char * V_73 )
{
struct V_61 * V_62 ;
struct V_54 * V_55 ;
struct V_9 * * V_10 ;
struct V_9 * V_12 = NULL ;
struct V_61 * V_13 ;
T_3 V_59 ;
if ( ! V_73 ) {
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
V_62 -> V_73 = F_91 ( V_73 , V_28 ) ;
if ( ! V_62 -> V_73 )
goto V_93;
F_92 ( & V_8 -> V_47 ) ;
V_62 -> V_89 = F_83 ( & V_8 -> V_94 , V_73 ) ;
V_62 -> V_95 = F_93 (
V_28 , L_15 , V_73 , V_62 -> V_89 ) ;
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
F_20 ( V_62 -> V_73 ) ;
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
F_20 ( V_62 -> V_73 ) ;
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
return V_2 -> V_74 + V_136 * V_39 ;
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
void * V_74 ;
if ( ! V_2 -> V_19 -> V_31 -> V_75 ) {
F_9 ( L_26 ,
V_17 ) ;
return - V_69 ;
}
F_30 ( & V_2 -> V_47 ) ;
V_74 = F_72 ( V_2 ) ;
F_31 ( & V_2 -> V_47 ) ;
return F_127 ( V_74 ) ;
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
F_130 ( V_139 ) ;
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
V_139 . V_31 = & V_140 ;
V_139 . V_35 = V_2 -> V_35 ;
V_139 . V_3 = V_141 ;
V_139 . V_108 = V_2 ;
V_107 = F_131 ( & V_139 ) ;
if ( F_19 ( V_107 ) ) {
F_41 ( V_2 ) ;
return V_107 ;
}
return V_107 ;
}
int F_132 ( struct V_61 * V_62 , struct V_60 * V_63 )
{
struct V_106 * V_107 ;
int V_142 ;
V_107 = F_129 ( V_62 , V_63 ) ;
if ( F_19 ( V_107 ) )
return F_133 ( V_107 ) ;
V_142 = F_134 ( V_107 , V_143 ) ;
if ( V_142 < 0 )
F_135 ( V_107 ) ;
return V_142 ;
}
struct V_60 * F_136 ( struct V_61 * V_62 , int V_142 )
{
struct V_106 * V_107 ;
struct V_1 * V_2 ;
struct V_60 * V_63 ;
int V_27 ;
V_107 = F_137 ( V_142 ) ;
if ( F_19 ( V_107 ) )
return F_21 ( V_107 ) ;
if ( V_107 -> V_31 != & V_140 ) {
F_9 ( L_28 ,
V_17 ) ;
F_135 ( V_107 ) ;
return F_15 ( - V_37 ) ;
}
V_2 = V_107 -> V_108 ;
F_30 ( & V_62 -> V_47 ) ;
V_63 = F_57 ( V_62 , V_2 ) ;
if ( ! F_19 ( V_63 ) ) {
F_55 ( V_63 ) ;
F_31 ( & V_62 -> V_47 ) ;
goto V_144;
}
F_31 ( & V_62 -> V_47 ) ;
V_63 = F_48 ( V_62 , V_2 ) ;
if ( F_19 ( V_63 ) )
goto V_144;
F_30 ( & V_62 -> V_47 ) ;
V_27 = F_62 ( V_62 , V_63 ) ;
F_31 ( & V_62 -> V_47 ) ;
if ( V_27 ) {
F_56 ( V_63 ) ;
V_63 = F_15 ( V_27 ) ;
}
V_144:
F_135 ( V_107 ) ;
return V_63 ;
}
static int F_138 ( struct V_61 * V_62 , int V_142 )
{
struct V_106 * V_107 ;
struct V_1 * V_2 ;
V_107 = F_137 ( V_142 ) ;
if ( F_19 ( V_107 ) )
return F_133 ( V_107 ) ;
if ( V_107 -> V_31 != & V_140 ) {
F_9 ( L_29 ,
V_17 ) ;
F_135 ( V_107 ) ;
return - V_37 ;
}
V_2 = V_107 -> V_108 ;
F_108 ( NULL , V_2 -> V_22 -> V_145 ,
V_2 -> V_22 -> V_146 , V_147 ) ;
F_135 ( V_107 ) ;
return 0 ;
}
static unsigned int F_139 ( unsigned int V_148 )
{
switch ( V_148 ) {
case V_149 :
case V_150 :
case V_151 :
return V_152 ;
default:
return F_140 ( V_148 ) ;
}
}
static long F_141 ( struct V_84 * V_153 , unsigned int V_148 , unsigned long V_154 )
{
struct V_61 * V_62 = V_153 -> V_155 ;
struct V_7 * V_8 = V_62 -> V_8 ;
struct V_60 * V_156 = NULL ;
int V_27 = 0 ;
unsigned int V_110 ;
union {
struct V_157 V_142 ;
struct V_158 V_159 ;
struct V_160 V_63 ;
struct V_161 V_162 ;
} V_163 ;
V_110 = F_139 ( V_148 ) ;
if ( F_142 ( V_148 ) > sizeof( V_163 ) )
return - V_37 ;
if ( V_110 & V_152 )
if ( F_143 ( & V_163 , ( void V_164 * ) V_154 , F_142 ( V_148 ) ) )
return - V_165 ;
switch ( V_148 ) {
case V_166 :
{
struct V_60 * V_63 ;
V_63 = F_65 ( V_62 , V_163 . V_159 . V_20 ,
V_163 . V_159 . V_21 ,
V_163 . V_159 . V_68 ,
V_163 . V_159 . V_3 ) ;
if ( F_19 ( V_63 ) )
return F_133 ( V_63 ) ;
V_163 . V_159 . V_63 = V_63 -> V_65 ;
V_156 = V_63 ;
break;
}
case V_150 :
{
struct V_60 * V_63 ;
V_63 = F_58 ( V_62 , V_163 . V_63 . V_63 ) ;
if ( F_19 ( V_63 ) )
return F_133 ( V_63 ) ;
F_70 ( V_62 , V_63 ) ;
F_56 ( V_63 ) ;
break;
}
case V_167 :
case V_168 :
{
struct V_60 * V_63 ;
V_63 = F_58 ( V_62 , V_163 . V_63 . V_63 ) ;
if ( F_19 ( V_63 ) )
return F_133 ( V_63 ) ;
V_163 . V_142 . V_142 = F_132 ( V_62 , V_63 ) ;
F_56 ( V_63 ) ;
if ( V_163 . V_142 . V_142 < 0 )
V_27 = V_163 . V_142 . V_142 ;
break;
}
case V_169 :
{
struct V_60 * V_63 ;
V_63 = F_136 ( V_62 , V_163 . V_142 . V_142 ) ;
if ( F_19 ( V_63 ) )
V_27 = F_133 ( V_63 ) ;
else
V_163 . V_63 . V_63 = V_63 -> V_65 ;
break;
}
case V_149 :
{
V_27 = F_138 ( V_62 , V_163 . V_142 . V_142 ) ;
break;
}
case V_151 :
{
if ( ! V_8 -> V_170 )
return - V_171 ;
V_27 = V_8 -> V_170 ( V_62 , V_163 . V_162 . V_148 ,
V_163 . V_162 . V_154 ) ;
break;
}
default:
return - V_171 ;
}
if ( V_110 & V_172 ) {
if ( F_144 ( ( void V_164 * ) V_154 , & V_163 , F_142 ( V_148 ) ) ) {
if ( V_156 )
F_70 ( V_62 , V_156 ) ;
return - V_165 ;
}
}
return V_27 ;
}
static int F_145 ( struct V_83 * V_83 , struct V_84 * V_84 )
{
struct V_61 * V_62 = V_84 -> V_155 ;
F_66 ( L_17 , V_17 , __LINE__ ) ;
F_97 ( V_62 ) ;
return 0 ;
}
static int F_146 ( struct V_83 * V_83 , struct V_84 * V_84 )
{
struct V_173 * V_174 = V_84 -> V_155 ;
struct V_7 * V_8 = F_36 ( V_174 , struct V_7 , V_8 ) ;
struct V_61 * V_62 ;
char V_175 [ 64 ] ;
F_66 ( L_17 , V_17 , __LINE__ ) ;
snprintf ( V_175 , 64 , L_30 , F_47 ( V_56 -> V_57 ) ) ;
V_62 = F_85 ( V_8 , V_175 ) ;
if ( F_19 ( V_62 ) )
return F_133 ( V_62 ) ;
V_84 -> V_155 = V_62 ;
return 0 ;
}
static T_1 F_147 ( struct V_61 * V_62 ,
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
static int F_148 ( struct V_76 * V_77 , void * V_78 )
{
struct V_18 * V_19 = V_77 -> V_79 ;
struct V_7 * V_8 = V_19 -> V_8 ;
struct V_9 * V_67 ;
T_1 V_176 = 0 ;
T_1 V_177 = 0 ;
F_80 ( V_77 , L_31 , L_32 , L_33 , L_34 ) ;
F_149 ( V_77 , L_35 ) ;
for ( V_67 = F_78 ( & V_8 -> V_94 ) ; V_67 ; V_67 = F_79 ( V_67 ) ) {
struct V_61 * V_62 = F_8 ( V_67 , struct V_61 ,
V_14 ) ;
T_1 V_35 = F_147 ( V_62 , V_19 -> V_65 ) ;
if ( ! V_35 )
continue;
if ( V_62 -> V_55 ) {
char V_58 [ V_178 ] ;
F_46 ( V_58 , V_62 -> V_55 ) ;
F_80 ( V_77 , L_36 , V_58 ,
V_62 -> V_59 , V_35 ) ;
} else {
F_80 ( V_77 , L_36 , V_62 -> V_73 ,
V_62 -> V_59 , V_35 ) ;
}
}
F_149 ( V_77 , L_35 ) ;
F_149 ( V_77 , L_37 ) ;
F_30 ( & V_8 -> V_48 ) ;
for ( V_67 = F_78 ( & V_8 -> V_11 ) ; V_67 ; V_67 = F_79 ( V_67 ) ) {
struct V_1 * V_2 = F_8 ( V_67 , struct V_1 ,
V_14 ) ;
if ( V_2 -> V_19 -> V_65 != V_19 -> V_65 )
continue;
V_176 += V_2 -> V_35 ;
if ( ! V_2 -> V_53 ) {
F_80 ( V_77 , L_38 ,
V_2 -> V_58 , V_2 -> V_59 ,
V_2 -> V_35 , V_2 -> V_50 ,
F_150 ( & V_2 -> V_30 . V_179 ) ) ;
V_177 += V_2 -> V_35 ;
}
}
F_31 ( & V_8 -> V_48 ) ;
F_149 ( V_77 , L_35 ) ;
F_80 ( V_77 , L_39 , L_40 ,
V_177 ) ;
F_80 ( V_77 , L_39 , L_41 , V_176 ) ;
if ( V_19 -> V_3 & V_33 )
F_80 ( V_77 , L_39 , L_42 ,
V_19 -> V_180 ) ;
F_149 ( V_77 , L_35 ) ;
if ( V_19 -> V_181 )
V_19 -> V_181 ( V_19 , V_77 , V_78 ) ;
return 0 ;
}
static int F_151 ( struct V_83 * V_83 , struct V_84 * V_84 )
{
return F_82 ( V_84 , F_148 , V_83 -> V_85 ) ;
}
static int F_152 ( void * V_163 , T_4 V_182 )
{
struct V_18 * V_19 = V_163 ;
struct V_183 V_184 ;
int V_185 ;
V_184 . V_186 = - 1 ;
V_184 . V_187 = 0 ;
if ( ! V_182 )
return 0 ;
V_185 = V_19 -> V_188 . V_189 ( & V_19 -> V_188 , & V_184 ) ;
V_184 . V_187 = V_185 ;
V_19 -> V_188 . V_189 ( & V_19 -> V_188 , & V_184 ) ;
return 0 ;
}
static int F_153 ( void * V_163 , T_4 * V_182 )
{
struct V_18 * V_19 = V_163 ;
struct V_183 V_184 ;
int V_185 ;
V_184 . V_186 = - 1 ;
V_184 . V_187 = 0 ;
V_185 = V_19 -> V_188 . V_189 ( & V_19 -> V_188 , & V_184 ) ;
* V_182 = V_185 ;
return 0 ;
}
void F_154 ( struct V_7 * V_8 , struct V_18 * V_19 )
{
struct V_190 * V_191 ;
if ( ! V_19 -> V_31 -> V_32 || ! V_19 -> V_31 -> free || ! V_19 -> V_31 -> V_36 ||
! V_19 -> V_31 -> V_49 )
F_9 ( L_43 ,
V_17 ) ;
F_155 ( & V_19 -> V_192 ) ;
V_19 -> V_180 = 0 ;
if ( V_19 -> V_3 & V_33 )
F_156 ( V_19 ) ;
if ( ( V_19 -> V_3 & V_33 ) || V_19 -> V_31 -> V_189 )
F_157 ( V_19 ) ;
V_19 -> V_8 = V_8 ;
F_92 ( & V_8 -> V_47 ) ;
F_158 ( & V_19 -> V_14 , - V_19 -> V_65 ) ;
F_159 ( & V_19 -> V_14 , & V_8 -> V_193 ) ;
V_191 = F_95 ( V_19 -> V_73 , 0664 ,
V_8 -> V_194 , V_19 ,
& V_195 ) ;
if ( ! V_191 ) {
char V_100 [ 256 ] , * V_101 ;
V_101 = F_96 ( V_8 -> V_194 , V_100 , 256 ) ;
F_9 ( L_44 ,
V_101 , V_19 -> V_73 ) ;
}
#ifdef F_160
if ( V_19 -> V_188 . V_189 ) {
char V_175 [ 64 ] ;
snprintf ( V_175 , 64 , L_45 , V_19 -> V_73 ) ;
V_191 = F_95 (
V_175 , 0644 , V_8 -> V_194 , V_19 ,
& V_196 ) ;
if ( ! V_191 ) {
char V_100 [ 256 ] , * V_101 ;
V_101 = F_96 ( V_8 -> V_194 , V_100 , 256 ) ;
F_9 ( L_46 ,
V_101 , V_175 ) ;
}
}
#endif
F_94 ( & V_8 -> V_47 ) ;
}
struct V_7 * F_161 ( long (* V_170)
( struct V_61 * V_62 ,
unsigned int V_148 ,
unsigned long V_154 ) )
{
struct V_7 * V_197 ;
int V_27 ;
V_197 = F_14 ( sizeof( struct V_7 ) , V_28 ) ;
if ( ! V_197 )
return F_15 ( - V_29 ) ;
V_197 -> V_8 . V_198 = V_199 ;
V_197 -> V_8 . V_73 = L_47 ;
V_197 -> V_8 . V_200 = & V_201 ;
V_197 -> V_8 . V_12 = NULL ;
V_27 = F_162 ( & V_197 -> V_8 ) ;
if ( V_27 ) {
F_9 ( L_48 ) ;
F_20 ( V_197 ) ;
return F_15 ( V_27 ) ;
}
V_197 -> V_97 = F_163 ( L_47 , NULL ) ;
if ( ! V_197 -> V_97 ) {
F_9 ( L_49 ) ;
goto V_202;
}
V_197 -> V_194 = F_163 ( L_50 , V_197 -> V_97 ) ;
if ( ! V_197 -> V_194 ) {
F_9 ( L_51 ) ;
goto V_202;
}
V_197 -> V_98 = F_163 ( L_52 ,
V_197 -> V_97 ) ;
if ( ! V_197 -> V_98 )
F_9 ( L_53 ) ;
V_202:
V_197 -> V_170 = V_170 ;
V_197 -> V_11 = V_92 ;
F_27 ( & V_197 -> V_48 ) ;
F_164 ( & V_197 -> V_47 ) ;
F_165 ( & V_197 -> V_193 ) ;
V_197 -> V_94 = V_92 ;
return V_197 ;
}
void F_166 ( struct V_7 * V_8 )
{
F_167 ( & V_8 -> V_8 ) ;
F_99 ( V_8 -> V_97 ) ;
F_20 ( V_8 ) ;
}
void T_5 F_168 ( struct V_203 * V_163 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_163 -> V_204 ; V_26 ++ ) {
if ( V_163 -> V_193 [ V_26 ] . V_35 == 0 )
continue;
if ( V_163 -> V_193 [ V_26 ] . V_205 == 0 ) {
T_6 V_206 ;
V_206 = F_169 ( V_163 -> V_193 [ V_26 ] . V_35 ,
V_163 -> V_193 [ V_26 ] . V_21 ,
V_207 ) ;
if ( ! V_206 ) {
F_9 ( L_54 ,
V_17 , V_26 ) ;
continue;
}
V_163 -> V_193 [ V_26 ] . V_205 = V_206 ;
} else {
int V_27 = F_170 ( V_163 -> V_193 [ V_26 ] . V_205 ,
V_163 -> V_193 [ V_26 ] . V_35 ) ;
if ( V_27 )
F_9 ( L_55 ,
V_163 -> V_193 [ V_26 ] . V_35 ,
V_163 -> V_193 [ V_26 ] . V_205 ) ;
}
F_171 ( L_56 , V_17 ,
V_163 -> V_193 [ V_26 ] . V_73 ,
V_163 -> V_193 [ V_26 ] . V_205 ,
V_163 -> V_193 [ V_26 ] . V_35 ) ;
}
}
