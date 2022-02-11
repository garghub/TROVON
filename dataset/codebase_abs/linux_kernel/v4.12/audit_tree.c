static struct V_1 * F_1 ( const char * V_2 )
{
struct V_1 * V_3 ;
V_3 = F_2 ( sizeof( struct V_1 ) + strlen ( V_2 ) + 1 , V_4 ) ;
if ( V_3 ) {
F_3 ( & V_3 -> V_5 , 1 ) ;
V_3 -> V_6 = 0 ;
F_4 ( & V_3 -> V_7 ) ;
F_4 ( & V_3 -> V_8 ) ;
F_4 ( & V_3 -> V_9 ) ;
F_4 ( & V_3 -> V_10 ) ;
V_3 -> V_11 = NULL ;
strcpy ( V_3 -> V_12 , V_2 ) ;
}
return V_3 ;
}
static inline void F_5 ( struct V_1 * V_3 )
{
F_6 ( & V_3 -> V_5 ) ;
}
static inline void F_7 ( struct V_1 * V_3 )
{
if ( F_8 ( & V_3 -> V_5 ) )
F_9 ( V_3 , V_13 ) ;
}
const char * F_10 ( struct V_1 * V_3 )
{
return V_3 -> V_12 ;
}
static void F_11 ( struct V_14 * V_15 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_15 -> V_5 ; V_16 ++ ) {
if ( V_15 -> V_17 [ V_16 ] . V_18 )
F_7 ( V_15 -> V_17 [ V_16 ] . V_18 ) ;
}
F_12 ( V_15 ) ;
}
void F_13 ( struct V_14 * V_15 )
{
if ( F_14 ( & V_15 -> V_19 ) )
F_11 ( V_15 ) ;
}
static void F_15 ( struct V_20 * V_21 )
{
struct V_14 * V_15 = F_16 ( V_21 , struct V_14 , V_13 ) ;
F_13 ( V_15 ) ;
}
static void F_17 ( struct V_22 * V_23 )
{
struct V_14 * V_15 = F_16 ( V_23 , struct V_14 , V_24 ) ;
F_18 ( & V_15 -> V_13 , F_15 ) ;
}
static struct V_14 * F_19 ( int V_5 )
{
struct V_14 * V_15 ;
T_1 V_25 ;
int V_16 ;
V_25 = F_20 ( struct V_14 , V_17 ) + V_5 * sizeof( struct V_26 ) ;
V_15 = F_21 ( V_25 , V_4 ) ;
if ( ! V_15 )
return NULL ;
F_4 ( & V_15 -> V_27 ) ;
F_4 ( & V_15 -> V_28 ) ;
V_15 -> V_5 = V_5 ;
F_22 ( & V_15 -> V_19 , 1 ) ;
for ( V_16 = 0 ; V_16 < V_5 ; V_16 ++ ) {
F_4 ( & V_15 -> V_17 [ V_16 ] . V_9 ) ;
V_15 -> V_17 [ V_16 ] . V_29 = V_16 ;
}
F_23 ( & V_15 -> V_24 , V_30 ) ;
V_15 -> V_24 . V_31 = V_32 ;
return V_15 ;
}
static unsigned long F_24 ( const struct V_33 * V_33 )
{
return ( unsigned long ) V_33 ;
}
static unsigned long F_25 ( struct V_14 * V_15 )
{
if ( F_26 ( ! V_15 -> V_24 . V_34 ) )
return 0 ;
return ( unsigned long ) V_15 -> V_24 . V_34 -> V_33 ;
}
static inline struct V_35 * F_27 ( unsigned long V_36 )
{
unsigned long V_37 = V_36 / V_38 ;
return V_39 + V_37 % V_40 ;
}
static void F_28 ( struct V_14 * V_15 )
{
unsigned long V_36 = F_25 ( V_15 ) ;
struct V_35 * V_9 ;
if ( ! ( V_15 -> V_24 . V_41 & V_42 ) )
return;
V_9 = F_27 ( V_36 ) ;
F_29 ( & V_15 -> V_27 , V_9 ) ;
}
struct V_14 * F_30 ( const struct V_33 * V_33 )
{
unsigned long V_36 = F_24 ( V_33 ) ;
struct V_35 * V_9 = F_27 ( V_36 ) ;
struct V_14 * V_43 ;
F_31 (p, list, hash) {
if ( F_25 ( V_43 ) == V_36 ) {
F_32 ( & V_43 -> V_19 ) ;
return V_43 ;
}
}
return NULL ;
}
bool F_33 ( struct V_14 * V_15 , struct V_1 * V_3 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_15 -> V_5 ; V_37 ++ )
if ( V_15 -> V_17 [ V_37 ] . V_18 == V_3 )
return true ;
return false ;
}
static struct V_14 * F_34 ( struct V_26 * V_43 )
{
int V_29 = V_43 -> V_29 & ~ ( 1U << 31 ) ;
V_43 -= V_29 ;
return F_16 ( V_43 , struct V_14 , V_17 [ 0 ] ) ;
}
static void F_35 ( struct V_26 * V_43 )
{
struct V_14 * V_15 = F_34 ( V_43 ) ;
struct V_22 * V_23 = & V_15 -> V_24 ;
struct V_14 * V_44 = NULL ;
struct V_1 * V_18 ;
int V_25 = V_15 -> V_5 - 1 ;
int V_16 , V_45 ;
F_36 ( V_23 ) ;
F_37 ( & V_46 ) ;
if ( V_25 )
V_44 = F_19 ( V_25 ) ;
F_38 ( & V_23 -> V_47 -> V_48 ) ;
F_39 ( & V_23 -> V_49 ) ;
if ( V_15 -> V_50 || ! ( V_23 -> V_41 & V_42 ) ) {
F_37 ( & V_23 -> V_49 ) ;
F_40 ( & V_23 -> V_47 -> V_48 ) ;
if ( V_44 )
F_41 ( & V_44 -> V_24 ) ;
goto V_51;
}
V_18 = V_43 -> V_18 ;
if ( ! V_25 ) {
V_15 -> V_50 = 1 ;
F_39 ( & V_46 ) ;
F_42 ( & V_15 -> V_28 ) ;
if ( V_18 -> V_11 == V_15 )
V_18 -> V_11 = NULL ;
F_42 ( & V_43 -> V_9 ) ;
F_43 ( & V_15 -> V_27 ) ;
F_37 ( & V_46 ) ;
F_37 ( & V_23 -> V_49 ) ;
F_40 ( & V_23 -> V_47 -> V_48 ) ;
F_44 ( V_23 , V_30 ) ;
goto V_51;
}
if ( ! V_44 )
goto V_52;
if ( F_45 ( & V_44 -> V_24 , V_23 -> V_34 -> V_33 ,
NULL , 1 ) ) {
F_41 ( & V_44 -> V_24 ) ;
goto V_52;
}
V_15 -> V_50 = 1 ;
F_39 ( & V_46 ) ;
F_46 ( & V_15 -> V_28 , & V_44 -> V_28 ) ;
if ( V_18 -> V_11 == V_15 ) {
F_42 ( & V_18 -> V_10 ) ;
V_18 -> V_11 = NULL ;
}
for ( V_16 = V_45 = 0 ; V_45 <= V_25 ; V_16 ++ , V_45 ++ ) {
struct V_1 * V_2 ;
if ( & V_15 -> V_17 [ V_45 ] == V_43 ) {
F_42 ( & V_43 -> V_9 ) ;
V_16 -- ;
continue;
}
V_2 = V_15 -> V_17 [ V_45 ] . V_18 ;
V_44 -> V_17 [ V_16 ] . V_18 = V_2 ;
V_44 -> V_17 [ V_16 ] . V_29 = V_15 -> V_17 [ V_45 ] . V_29 - V_45 + V_16 ;
if ( ! V_2 )
continue;
F_5 ( V_2 ) ;
F_46 ( & V_15 -> V_17 [ V_45 ] . V_9 , & V_44 -> V_17 [ V_16 ] . V_9 ) ;
}
F_47 ( & V_15 -> V_27 , & V_44 -> V_27 ) ;
F_48 (owner, &new->trees, same_root)
V_18 -> V_11 = V_44 ;
F_37 ( & V_46 ) ;
F_37 ( & V_23 -> V_49 ) ;
F_40 ( & V_23 -> V_47 -> V_48 ) ;
F_44 ( V_23 , V_30 ) ;
F_41 ( & V_44 -> V_24 ) ;
goto V_51;
V_52:
F_39 ( & V_46 ) ;
if ( V_18 -> V_11 == V_15 ) {
F_42 ( & V_18 -> V_10 ) ;
V_18 -> V_11 = NULL ;
}
F_42 ( & V_43 -> V_9 ) ;
V_43 -> V_18 = NULL ;
F_7 ( V_18 ) ;
F_37 ( & V_46 ) ;
F_37 ( & V_23 -> V_49 ) ;
F_40 ( & V_23 -> V_47 -> V_48 ) ;
V_51:
F_41 ( V_23 ) ;
F_39 ( & V_46 ) ;
}
static int F_49 ( struct V_33 * V_33 , struct V_1 * V_3 )
{
struct V_22 * V_23 ;
struct V_14 * V_15 = F_19 ( 1 ) ;
if ( ! V_15 )
return - V_53 ;
V_23 = & V_15 -> V_24 ;
if ( F_50 ( V_23 , V_33 , NULL , 0 ) ) {
F_41 ( V_23 ) ;
return - V_54 ;
}
F_39 ( & V_23 -> V_49 ) ;
F_39 ( & V_46 ) ;
if ( V_3 -> V_6 ) {
F_37 ( & V_46 ) ;
V_15 -> V_50 = 1 ;
F_37 ( & V_23 -> V_49 ) ;
F_44 ( V_23 , V_30 ) ;
F_41 ( V_23 ) ;
return 0 ;
}
V_15 -> V_17 [ 0 ] . V_29 = ( 1U << 31 ) ;
V_15 -> V_17 [ 0 ] . V_18 = V_3 ;
F_5 ( V_3 ) ;
F_51 ( & V_15 -> V_17 [ 0 ] . V_9 , & V_3 -> V_7 ) ;
if ( ! V_3 -> V_11 ) {
V_3 -> V_11 = V_15 ;
F_51 ( & V_3 -> V_10 , & V_15 -> V_28 ) ;
}
F_28 ( V_15 ) ;
F_37 ( & V_46 ) ;
F_37 ( & V_23 -> V_49 ) ;
F_41 ( V_23 ) ;
return 0 ;
}
static int F_52 ( struct V_33 * V_33 , struct V_1 * V_3 )
{
struct V_22 * V_55 , * V_56 ;
struct V_1 * V_18 ;
struct V_14 * V_15 , * V_57 ;
struct V_26 * V_43 ;
int V_37 ;
V_55 = F_53 ( & V_33 -> V_58 ,
V_30 ) ;
if ( ! V_55 )
return F_49 ( V_33 , V_3 ) ;
V_57 = F_16 ( V_55 , struct V_14 , V_24 ) ;
F_39 ( & V_46 ) ;
for ( V_37 = 0 ; V_37 < V_57 -> V_5 ; V_37 ++ ) {
if ( V_57 -> V_17 [ V_37 ] . V_18 == V_3 ) {
F_37 ( & V_46 ) ;
F_41 ( V_55 ) ;
return 0 ;
}
}
F_37 ( & V_46 ) ;
V_15 = F_19 ( V_57 -> V_5 + 1 ) ;
if ( ! V_15 ) {
F_41 ( V_55 ) ;
return - V_53 ;
}
V_56 = & V_15 -> V_24 ;
F_38 ( & V_55 -> V_47 -> V_48 ) ;
F_39 ( & V_55 -> V_49 ) ;
if ( ! ( V_55 -> V_41 & V_42 ) ) {
F_37 ( & V_55 -> V_49 ) ;
F_40 ( & V_55 -> V_47 -> V_48 ) ;
F_41 ( V_55 ) ;
F_41 ( & V_15 -> V_24 ) ;
return - V_59 ;
}
if ( F_45 ( V_56 ,
V_55 -> V_34 -> V_33 , NULL , 1 ) ) {
F_37 ( & V_55 -> V_49 ) ;
F_40 ( & V_55 -> V_47 -> V_48 ) ;
F_41 ( V_56 ) ;
F_41 ( V_55 ) ;
return - V_54 ;
}
F_39 ( & V_56 -> V_49 ) ;
F_39 ( & V_46 ) ;
if ( V_3 -> V_6 ) {
F_37 ( & V_46 ) ;
V_15 -> V_50 = 1 ;
F_37 ( & V_56 -> V_49 ) ;
F_37 ( & V_55 -> V_49 ) ;
F_40 ( & V_55 -> V_47 -> V_48 ) ;
F_44 ( V_56 , V_30 ) ;
F_41 ( V_56 ) ;
F_41 ( V_55 ) ;
return 0 ;
}
F_46 ( & V_57 -> V_28 , & V_15 -> V_28 ) ;
for ( V_37 = 0 , V_43 = V_15 -> V_17 ; V_37 < V_57 -> V_5 ; V_37 ++ , V_43 ++ ) {
struct V_1 * V_2 = V_57 -> V_17 [ V_37 ] . V_18 ;
V_43 -> V_18 = V_2 ;
V_43 -> V_29 = V_57 -> V_17 [ V_37 ] . V_29 ;
if ( ! V_2 )
continue;
F_5 ( V_2 ) ;
F_46 ( & V_57 -> V_17 [ V_37 ] . V_9 , & V_43 -> V_9 ) ;
}
V_43 -> V_29 = ( V_15 -> V_5 - 1 ) | ( 1U << 31 ) ;
V_43 -> V_18 = V_3 ;
F_5 ( V_3 ) ;
F_51 ( & V_43 -> V_9 , & V_3 -> V_7 ) ;
F_47 ( & V_57 -> V_27 , & V_15 -> V_27 ) ;
F_48 (owner, &chunk->trees, same_root)
V_18 -> V_11 = V_15 ;
V_57 -> V_50 = 1 ;
if ( ! V_3 -> V_11 ) {
V_3 -> V_11 = V_15 ;
F_51 ( & V_3 -> V_10 , & V_15 -> V_28 ) ;
}
F_37 ( & V_46 ) ;
F_37 ( & V_56 -> V_49 ) ;
F_37 ( & V_55 -> V_49 ) ;
F_40 ( & V_55 -> V_47 -> V_48 ) ;
F_44 ( V_55 , V_30 ) ;
F_41 ( V_56 ) ;
F_41 ( V_55 ) ;
return 0 ;
}
static void F_54 ( struct V_60 * V_61 )
{
struct V_62 * V_63 ;
V_63 = F_55 ( NULL , V_4 , V_64 ) ;
if ( F_56 ( ! V_63 ) )
return;
F_57 ( V_63 , L_1 ) ;
F_57 ( V_63 , L_2 ) ;
F_58 ( V_63 , V_61 -> V_3 -> V_12 ) ;
F_59 ( V_63 , V_61 -> V_65 ) ;
F_57 ( V_63 , L_3 , V_61 -> V_66 ) ;
F_60 ( V_63 ) ;
}
static void F_61 ( struct V_1 * V_3 )
{
struct V_60 * V_61 , * V_67 ;
struct V_68 * V_23 ;
F_62 (rule, next, &tree->rules, rlist) {
V_23 = F_16 ( V_61 , struct V_68 , V_61 ) ;
F_42 ( & V_61 -> V_69 ) ;
if ( V_61 -> V_3 ) {
F_54 ( V_61 ) ;
if ( V_23 -> V_61 . V_70 )
F_63 ( V_23 -> V_61 . V_70 ) ;
V_61 -> V_3 = NULL ;
F_43 ( & V_23 -> V_9 ) ;
F_64 ( & V_23 -> V_61 . V_9 ) ;
F_18 ( & V_23 -> V_21 , V_71 ) ;
}
}
}
static void F_65 ( struct V_1 * V_72 )
{
F_39 ( & V_46 ) ;
while ( ! F_66 ( & V_72 -> V_7 ) ) {
struct V_26 * V_43 ;
V_43 = F_67 ( V_72 -> V_7 . V_67 , struct V_26 , V_9 ) ;
F_35 ( V_43 ) ;
}
F_37 ( & V_46 ) ;
F_7 ( V_72 ) ;
}
static void F_68 ( struct V_1 * V_3 )
{
struct V_35 * V_43 , * V_73 ;
F_39 ( & V_46 ) ;
if ( V_3 -> V_6 ) {
F_37 ( & V_46 ) ;
return;
}
for ( V_43 = V_3 -> V_7 . V_67 ; V_43 != & V_3 -> V_7 ; V_43 = V_73 ) {
struct V_26 * V_26 = F_67 ( V_43 , struct V_26 , V_9 ) ;
V_73 = V_43 -> V_67 ;
if ( V_26 -> V_29 & ( 1U << 31 ) ) {
F_42 ( V_43 ) ;
F_51 ( V_43 , & V_3 -> V_7 ) ;
}
}
while ( ! F_66 ( & V_3 -> V_7 ) ) {
struct V_26 * V_26 ;
V_26 = F_67 ( V_3 -> V_7 . V_67 , struct V_26 , V_9 ) ;
if ( ! ( V_26 -> V_29 & ( 1U << 31 ) ) )
break;
F_35 ( V_26 ) ;
}
if ( ! V_3 -> V_11 && ! V_3 -> V_6 ) {
V_3 -> V_6 = 1 ;
F_37 ( & V_46 ) ;
F_38 ( & V_74 ) ;
F_61 ( V_3 ) ;
F_42 ( & V_3 -> V_9 ) ;
F_40 ( & V_74 ) ;
F_65 ( V_3 ) ;
} else {
F_37 ( & V_46 ) ;
}
}
int F_69 ( struct V_60 * V_61 )
{
struct V_1 * V_3 ;
V_3 = V_61 -> V_3 ;
if ( V_3 ) {
F_39 ( & V_46 ) ;
F_42 ( & V_61 -> V_69 ) ;
if ( F_66 ( & V_3 -> V_8 ) && ! V_3 -> V_6 ) {
V_3 -> V_11 = NULL ;
F_42 ( & V_3 -> V_10 ) ;
V_3 -> V_6 = 1 ;
F_70 ( & V_3 -> V_9 , & V_75 ) ;
V_61 -> V_3 = NULL ;
F_37 ( & V_46 ) ;
F_71 () ;
return 1 ;
}
V_61 -> V_3 = NULL ;
F_37 ( & V_46 ) ;
return 1 ;
}
return 0 ;
}
static int F_72 ( struct V_76 * V_77 , void * V_78 )
{
return F_24 ( F_73 ( V_77 -> V_79 ) ) ==
( unsigned long ) V_78 ;
}
void F_74 ( void )
{
struct V_35 V_80 ;
F_38 ( & V_74 ) ;
F_51 ( & V_80 , & V_81 ) ;
while ( V_80 . V_67 != & V_81 ) {
struct V_1 * V_3 ;
struct V_82 V_82 ;
struct V_76 * V_83 ;
struct V_26 * V_26 ;
int V_84 ;
V_3 = F_16 ( V_80 . V_67 , struct V_1 , V_9 ) ;
F_5 ( V_3 ) ;
F_64 ( & V_80 ) ;
F_51 ( & V_80 , & V_3 -> V_9 ) ;
F_40 ( & V_74 ) ;
V_84 = F_75 ( V_3 -> V_12 , 0 , & V_82 ) ;
if ( V_84 )
goto V_85;
V_83 = F_76 ( & V_82 ) ;
F_77 ( & V_82 ) ;
if ( F_78 ( V_83 ) )
goto V_85;
F_39 ( & V_46 ) ;
F_48 (node, &tree->chunks, list) {
struct V_14 * V_15 = F_34 ( V_26 ) ;
V_26 -> V_29 |= 1U << 31 ;
if ( F_79 ( F_72 ,
( void * ) F_25 ( V_15 ) ,
V_83 ) )
V_26 -> V_29 &= ~ ( 1U << 31 ) ;
}
F_37 ( & V_46 ) ;
F_68 ( V_3 ) ;
F_80 ( V_83 ) ;
V_85:
F_7 ( V_3 ) ;
F_38 ( & V_74 ) ;
}
F_64 ( & V_80 ) ;
F_40 ( & V_74 ) ;
}
int F_81 ( struct V_60 * V_61 , char * V_12 , T_2 V_86 )
{
if ( V_12 [ 0 ] != '/' ||
V_61 -> V_66 != V_87 ||
V_86 != V_88 ||
V_61 -> V_89 || V_61 -> V_90 || V_61 -> V_3 )
return - V_91 ;
V_61 -> V_3 = F_1 ( V_12 ) ;
if ( ! V_61 -> V_3 )
return - V_53 ;
return 0 ;
}
void F_82 ( struct V_1 * V_3 )
{
F_7 ( V_3 ) ;
}
static int F_83 ( struct V_76 * V_77 , void * V_78 )
{
return F_52 ( F_73 ( V_77 -> V_79 ) , V_78 ) ;
}
static int F_84 ( void * V_92 )
{
for (; ; ) {
if ( F_66 ( & V_75 ) ) {
F_85 ( V_93 ) ;
F_86 () ;
}
F_38 ( & V_94 ) ;
F_38 ( & V_74 ) ;
while ( ! F_66 ( & V_75 ) ) {
struct V_1 * V_72 ;
V_72 = F_67 ( V_75 . V_67 ,
struct V_1 , V_9 ) ;
F_42 ( & V_72 -> V_9 ) ;
F_40 ( & V_74 ) ;
F_65 ( V_72 ) ;
F_38 ( & V_74 ) ;
}
F_40 ( & V_74 ) ;
F_40 ( & V_94 ) ;
}
return 0 ;
}
static int F_87 ( void )
{
if ( V_95 )
return 0 ;
V_95 = F_88 ( F_84 , NULL ,
L_4 ) ;
if ( F_78 ( V_95 ) ) {
F_89 ( L_5 ) ;
V_95 = NULL ;
return - V_53 ;
}
return 0 ;
}
int F_90 ( struct V_60 * V_61 )
{
struct V_1 * V_96 = V_61 -> V_3 , * V_3 ;
struct V_82 V_82 ;
struct V_76 * V_77 ;
int V_84 ;
V_61 -> V_3 = NULL ;
F_48 (tree, &tree_list, list) {
if ( ! strcmp ( V_96 -> V_12 , V_3 -> V_12 ) ) {
F_7 ( V_96 ) ;
V_61 -> V_3 = V_3 ;
F_51 ( & V_61 -> V_69 , & V_3 -> V_8 ) ;
return 0 ;
}
}
V_3 = V_96 ;
F_51 ( & V_3 -> V_9 , & V_81 ) ;
F_51 ( & V_61 -> V_69 , & V_3 -> V_8 ) ;
F_40 ( & V_74 ) ;
if ( F_56 ( ! V_95 ) ) {
V_84 = F_87 () ;
if ( V_84 )
goto V_97;
}
V_84 = F_75 ( V_3 -> V_12 , 0 , & V_82 ) ;
if ( V_84 )
goto V_97;
V_77 = F_76 ( & V_82 ) ;
F_77 ( & V_82 ) ;
if ( F_78 ( V_77 ) ) {
V_84 = F_91 ( V_77 ) ;
goto V_97;
}
F_5 ( V_3 ) ;
V_84 = F_79 ( F_83 , V_3 , V_77 ) ;
F_80 ( V_77 ) ;
if ( ! V_84 ) {
struct V_26 * V_26 ;
F_39 ( & V_46 ) ;
F_48 (node, &tree->chunks, list)
V_26 -> V_29 &= ~ ( 1U << 31 ) ;
F_37 ( & V_46 ) ;
} else {
F_68 ( V_3 ) ;
goto V_97;
}
F_38 ( & V_74 ) ;
if ( F_66 ( & V_61 -> V_69 ) ) {
F_7 ( V_3 ) ;
return - V_59 ;
}
V_61 -> V_3 = V_3 ;
F_7 ( V_3 ) ;
return 0 ;
V_97:
F_38 ( & V_74 ) ;
F_42 ( & V_3 -> V_9 ) ;
F_42 ( & V_3 -> V_8 ) ;
F_7 ( V_3 ) ;
return V_84 ;
}
int F_92 ( char * V_57 , char * V_44 )
{
struct V_35 V_80 , V_98 ;
int V_99 = 0 ;
struct V_82 V_100 , V_101 ;
struct V_76 * V_102 ;
int V_84 ;
V_84 = F_75 ( V_44 , 0 , & V_101 ) ;
if ( V_84 )
return V_84 ;
V_102 = F_76 ( & V_101 ) ;
F_77 ( & V_101 ) ;
if ( F_78 ( V_102 ) )
return F_91 ( V_102 ) ;
V_84 = F_75 ( V_57 , 0 , & V_100 ) ;
if ( V_84 ) {
F_80 ( V_102 ) ;
return V_84 ;
}
F_38 ( & V_74 ) ;
F_51 ( & V_98 , & V_81 ) ;
F_51 ( & V_80 , & V_98 ) ;
while ( V_80 . V_67 != & V_81 ) {
struct V_1 * V_3 ;
int V_103 = 0 ;
V_3 = F_16 ( V_80 . V_67 , struct V_1 , V_9 ) ;
F_5 ( V_3 ) ;
F_64 ( & V_80 ) ;
F_51 ( & V_80 , & V_3 -> V_9 ) ;
F_40 ( & V_74 ) ;
V_84 = F_75 ( V_3 -> V_12 , 0 , & V_101 ) ;
if ( ! V_84 ) {
V_103 = F_93 ( & V_100 , & V_101 ) ;
F_77 ( & V_101 ) ;
}
if ( ! V_103 ) {
F_7 ( V_3 ) ;
F_38 ( & V_74 ) ;
continue;
}
V_99 = F_79 ( F_83 , V_3 , V_102 ) ;
if ( V_99 ) {
F_7 ( V_3 ) ;
F_38 ( & V_74 ) ;
break;
}
F_38 ( & V_74 ) ;
F_39 ( & V_46 ) ;
if ( ! V_3 -> V_6 ) {
F_64 ( & V_3 -> V_9 ) ;
F_51 ( & V_3 -> V_9 , & V_81 ) ;
}
F_37 ( & V_46 ) ;
F_7 ( V_3 ) ;
}
while ( V_98 . V_104 != & V_81 ) {
struct V_1 * V_3 ;
V_3 = F_16 ( V_98 . V_104 , struct V_1 , V_9 ) ;
F_5 ( V_3 ) ;
F_64 ( & V_3 -> V_9 ) ;
F_51 ( & V_3 -> V_9 , & V_98 ) ;
F_40 ( & V_74 ) ;
if ( ! V_99 ) {
struct V_26 * V_26 ;
F_39 ( & V_46 ) ;
F_48 (node, &tree->chunks, list)
V_26 -> V_29 &= ~ ( 1U << 31 ) ;
F_37 ( & V_46 ) ;
} else {
F_68 ( V_3 ) ;
}
F_7 ( V_3 ) ;
F_38 ( & V_74 ) ;
}
F_64 ( & V_98 ) ;
F_64 ( & V_80 ) ;
F_40 ( & V_74 ) ;
F_77 ( & V_100 ) ;
F_80 ( V_102 ) ;
return V_99 ;
}
static void F_71 ( void )
{
F_94 ( V_95 ) ;
}
void F_95 ( struct V_35 * V_9 )
{
F_38 ( & V_94 ) ;
F_38 ( & V_74 ) ;
while ( ! F_66 ( V_9 ) ) {
struct V_1 * V_72 ;
V_72 = F_67 ( V_9 -> V_67 , struct V_1 , V_9 ) ;
F_61 ( V_72 ) ;
F_42 ( & V_72 -> V_9 ) ;
F_40 ( & V_74 ) ;
F_65 ( V_72 ) ;
F_38 ( & V_74 ) ;
}
F_40 ( & V_74 ) ;
F_40 ( & V_94 ) ;
}
static void F_96 ( struct V_14 * V_15 )
{
struct V_1 * V_18 ;
struct V_35 * V_105 = F_97 () ;
int V_106 = 0 ;
int V_37 ;
if ( V_15 -> V_50 )
return;
V_15 -> V_50 = 1 ;
F_38 ( & V_74 ) ;
F_39 ( & V_46 ) ;
while ( ! F_66 ( & V_15 -> V_28 ) ) {
V_18 = F_67 ( V_15 -> V_28 . V_67 ,
struct V_1 , V_10 ) ;
V_18 -> V_6 = 1 ;
V_18 -> V_11 = NULL ;
F_42 ( & V_18 -> V_10 ) ;
F_37 ( & V_46 ) ;
if ( ! V_105 ) {
F_61 ( V_18 ) ;
F_70 ( & V_18 -> V_9 , & V_75 ) ;
V_106 = 1 ;
} else {
F_70 ( & V_18 -> V_9 , V_105 ) ;
}
F_39 ( & V_46 ) ;
}
F_43 ( & V_15 -> V_27 ) ;
for ( V_37 = 0 ; V_37 < V_15 -> V_5 ; V_37 ++ )
F_42 ( & V_15 -> V_17 [ V_37 ] . V_9 ) ;
F_37 ( & V_46 ) ;
F_40 ( & V_74 ) ;
if ( V_106 )
F_71 () ;
}
static int F_98 ( struct V_107 * V_47 ,
struct V_33 * V_108 ,
struct V_22 * V_109 ,
struct V_22 * V_110 ,
T_2 V_31 , const void * V_111 , int V_112 ,
const unsigned char * V_113 , T_2 V_114 ,
struct V_115 * V_116 )
{
return 0 ;
}
static void F_99 ( struct V_22 * V_23 , struct V_107 * V_47 )
{
struct V_14 * V_15 = F_16 ( V_23 , struct V_14 , V_24 ) ;
F_96 ( V_15 ) ;
F_100 ( F_101 ( & V_23 -> V_117 ) < 1 ) ;
}
static int T_3 F_102 ( void )
{
int V_16 ;
V_30 = F_103 ( & V_118 ) ;
if ( F_78 ( V_30 ) )
F_104 ( L_6 ) ;
for ( V_16 = 0 ; V_16 < V_40 ; V_16 ++ )
F_4 ( & V_39 [ V_16 ] ) ;
return 0 ;
}
