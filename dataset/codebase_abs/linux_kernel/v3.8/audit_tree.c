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
F_23 ( & V_15 -> V_24 , F_17 ) ;
return V_15 ;
}
static inline struct V_30 * F_24 ( const struct V_31 * V_31 )
{
unsigned long V_32 = ( unsigned long ) V_31 / V_33 ;
return V_34 + V_32 % V_35 ;
}
static void F_25 ( struct V_14 * V_15 )
{
struct V_22 * V_23 = & V_15 -> V_24 ;
struct V_30 * V_9 ;
if ( ! V_23 -> V_16 . V_31 )
return;
V_9 = F_24 ( V_23 -> V_16 . V_31 ) ;
F_26 ( & V_15 -> V_27 , V_9 ) ;
}
struct V_14 * F_27 ( const struct V_31 * V_31 )
{
struct V_30 * V_9 = F_24 ( V_31 ) ;
struct V_14 * V_36 ;
F_28 (p, list, hash) {
if ( V_36 -> V_24 . V_16 . V_31 == V_31 ) {
F_29 ( & V_36 -> V_19 ) ;
return V_36 ;
}
}
return NULL ;
}
int F_30 ( struct V_14 * V_15 , struct V_1 * V_3 )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < V_15 -> V_5 ; V_32 ++ )
if ( V_15 -> V_17 [ V_32 ] . V_18 == V_3 )
return 1 ;
return 0 ;
}
static struct V_14 * F_31 ( struct V_26 * V_36 )
{
int V_29 = V_36 -> V_29 & ~ ( 1U << 31 ) ;
V_36 -= V_29 ;
return F_16 ( V_36 , struct V_14 , V_17 [ 0 ] ) ;
}
static void F_32 ( struct V_26 * V_36 )
{
struct V_14 * V_15 = F_31 ( V_36 ) ;
struct V_22 * V_23 = & V_15 -> V_24 ;
struct V_14 * V_37 = NULL ;
struct V_1 * V_18 ;
int V_25 = V_15 -> V_5 - 1 ;
int V_16 , V_38 ;
F_33 ( V_23 ) ;
F_34 ( & V_39 ) ;
if ( V_25 )
V_37 = F_19 ( V_25 ) ;
F_35 ( & V_23 -> V_40 ) ;
if ( V_15 -> V_41 || ! V_23 -> V_16 . V_31 ) {
F_34 ( & V_23 -> V_40 ) ;
if ( V_37 )
F_11 ( V_37 ) ;
goto V_42;
}
V_18 = V_36 -> V_18 ;
if ( ! V_25 ) {
V_15 -> V_41 = 1 ;
F_35 ( & V_39 ) ;
F_36 ( & V_15 -> V_28 ) ;
if ( V_18 -> V_11 == V_15 )
V_18 -> V_11 = NULL ;
F_36 ( & V_36 -> V_9 ) ;
F_37 ( & V_15 -> V_27 ) ;
F_34 ( & V_39 ) ;
F_34 ( & V_23 -> V_40 ) ;
F_38 ( V_23 , V_43 ) ;
goto V_42;
}
if ( ! V_37 )
goto V_44;
F_39 ( & V_37 -> V_24 , V_23 ) ;
if ( F_40 ( & V_37 -> V_24 , V_37 -> V_24 . V_45 , V_37 -> V_24 . V_16 . V_31 , NULL , 1 ) ) {
F_41 ( & V_37 -> V_24 ) ;
goto V_44;
}
V_15 -> V_41 = 1 ;
F_35 ( & V_39 ) ;
F_42 ( & V_15 -> V_28 , & V_37 -> V_28 ) ;
if ( V_18 -> V_11 == V_15 ) {
F_36 ( & V_18 -> V_10 ) ;
V_18 -> V_11 = NULL ;
}
for ( V_16 = V_38 = 0 ; V_38 <= V_25 ; V_16 ++ , V_38 ++ ) {
struct V_1 * V_2 ;
if ( & V_15 -> V_17 [ V_38 ] == V_36 ) {
F_36 ( & V_36 -> V_9 ) ;
V_16 -- ;
continue;
}
V_2 = V_15 -> V_17 [ V_38 ] . V_18 ;
V_37 -> V_17 [ V_16 ] . V_18 = V_2 ;
V_37 -> V_17 [ V_16 ] . V_29 = V_15 -> V_17 [ V_38 ] . V_29 - V_38 + V_16 ;
if ( ! V_2 )
continue;
F_5 ( V_2 ) ;
F_42 ( & V_15 -> V_17 [ V_38 ] . V_9 , & V_37 -> V_17 [ V_16 ] . V_9 ) ;
}
F_43 ( & V_15 -> V_27 , & V_37 -> V_27 ) ;
F_44 (owner, &new->trees, same_root)
V_18 -> V_11 = V_37 ;
F_34 ( & V_39 ) ;
F_34 ( & V_23 -> V_40 ) ;
F_38 ( V_23 , V_43 ) ;
F_41 ( & V_37 -> V_24 ) ;
goto V_42;
V_44:
F_35 ( & V_39 ) ;
if ( V_18 -> V_11 == V_15 ) {
F_36 ( & V_18 -> V_10 ) ;
V_18 -> V_11 = NULL ;
}
F_36 ( & V_36 -> V_9 ) ;
V_36 -> V_18 = NULL ;
F_7 ( V_18 ) ;
F_34 ( & V_39 ) ;
F_34 ( & V_23 -> V_40 ) ;
V_42:
F_41 ( V_23 ) ;
F_35 ( & V_39 ) ;
}
static int F_45 ( struct V_31 * V_31 , struct V_1 * V_3 )
{
struct V_22 * V_23 ;
struct V_14 * V_15 = F_19 ( 1 ) ;
if ( ! V_15 )
return - V_46 ;
V_23 = & V_15 -> V_24 ;
if ( F_40 ( V_23 , V_43 , V_31 , NULL , 0 ) ) {
F_41 ( V_23 ) ;
return - V_47 ;
}
F_35 ( & V_23 -> V_40 ) ;
F_35 ( & V_39 ) ;
if ( V_3 -> V_6 ) {
F_34 ( & V_39 ) ;
V_15 -> V_41 = 1 ;
F_34 ( & V_23 -> V_40 ) ;
F_38 ( V_23 , V_43 ) ;
F_41 ( V_23 ) ;
return 0 ;
}
V_15 -> V_17 [ 0 ] . V_29 = ( 1U << 31 ) ;
V_15 -> V_17 [ 0 ] . V_18 = V_3 ;
F_5 ( V_3 ) ;
F_46 ( & V_15 -> V_17 [ 0 ] . V_9 , & V_3 -> V_7 ) ;
if ( ! V_3 -> V_11 ) {
V_3 -> V_11 = V_15 ;
F_46 ( & V_3 -> V_10 , & V_15 -> V_28 ) ;
}
F_25 ( V_15 ) ;
F_34 ( & V_39 ) ;
F_34 ( & V_23 -> V_40 ) ;
F_41 ( V_23 ) ;
return 0 ;
}
static int F_47 ( struct V_31 * V_31 , struct V_1 * V_3 )
{
struct V_22 * V_48 , * V_49 ;
struct V_1 * V_18 ;
struct V_14 * V_15 , * V_50 ;
struct V_26 * V_36 ;
int V_32 ;
V_48 = F_48 ( V_43 , V_31 ) ;
if ( ! V_48 )
return F_45 ( V_31 , V_3 ) ;
V_50 = F_16 ( V_48 , struct V_14 , V_24 ) ;
F_35 ( & V_39 ) ;
for ( V_32 = 0 ; V_32 < V_50 -> V_5 ; V_32 ++ ) {
if ( V_50 -> V_17 [ V_32 ] . V_18 == V_3 ) {
F_34 ( & V_39 ) ;
F_41 ( V_48 ) ;
return 0 ;
}
}
F_34 ( & V_39 ) ;
V_15 = F_19 ( V_50 -> V_5 + 1 ) ;
if ( ! V_15 ) {
F_41 ( V_48 ) ;
return - V_46 ;
}
V_49 = & V_15 -> V_24 ;
F_35 ( & V_48 -> V_40 ) ;
if ( ! V_48 -> V_16 . V_31 ) {
F_34 ( & V_48 -> V_40 ) ;
F_41 ( V_48 ) ;
F_11 ( V_15 ) ;
return - V_51 ;
}
F_39 ( V_49 , V_48 ) ;
if ( F_40 ( V_49 , V_49 -> V_45 , V_49 -> V_16 . V_31 , NULL , 1 ) ) {
F_34 ( & V_48 -> V_40 ) ;
F_41 ( V_49 ) ;
F_41 ( V_48 ) ;
return - V_47 ;
}
F_35 ( & V_49 -> V_40 ) ;
F_35 ( & V_39 ) ;
if ( V_3 -> V_6 ) {
F_34 ( & V_39 ) ;
V_15 -> V_41 = 1 ;
F_34 ( & V_49 -> V_40 ) ;
F_34 ( & V_48 -> V_40 ) ;
F_38 ( V_49 , V_43 ) ;
F_41 ( V_49 ) ;
F_41 ( V_48 ) ;
return 0 ;
}
F_42 ( & V_50 -> V_28 , & V_15 -> V_28 ) ;
for ( V_32 = 0 , V_36 = V_15 -> V_17 ; V_32 < V_50 -> V_5 ; V_32 ++ , V_36 ++ ) {
struct V_1 * V_2 = V_50 -> V_17 [ V_32 ] . V_18 ;
V_36 -> V_18 = V_2 ;
V_36 -> V_29 = V_50 -> V_17 [ V_32 ] . V_29 ;
if ( ! V_2 )
continue;
F_5 ( V_2 ) ;
F_42 ( & V_50 -> V_17 [ V_32 ] . V_9 , & V_36 -> V_9 ) ;
}
V_36 -> V_29 = ( V_15 -> V_5 - 1 ) | ( 1U << 31 ) ;
V_36 -> V_18 = V_3 ;
F_5 ( V_3 ) ;
F_46 ( & V_36 -> V_9 , & V_3 -> V_7 ) ;
F_43 ( & V_50 -> V_27 , & V_15 -> V_27 ) ;
F_44 (owner, &chunk->trees, same_root)
V_18 -> V_11 = V_15 ;
V_50 -> V_41 = 1 ;
if ( ! V_3 -> V_11 ) {
V_3 -> V_11 = V_15 ;
F_46 ( & V_3 -> V_10 , & V_15 -> V_28 ) ;
}
F_34 ( & V_39 ) ;
F_34 ( & V_49 -> V_40 ) ;
F_34 ( & V_48 -> V_40 ) ;
F_38 ( V_48 , V_43 ) ;
F_41 ( V_49 ) ;
F_41 ( V_48 ) ;
return 0 ;
}
static void F_49 ( struct V_52 * V_53 )
{
struct V_54 * V_55 ;
V_55 = F_50 ( NULL , V_4 , V_56 ) ;
if ( F_51 ( ! V_55 ) )
return;
F_52 ( V_55 , L_1 ) ;
F_53 ( V_55 , L_2 ) ;
F_52 ( V_55 , L_3 ) ;
F_54 ( V_55 , V_53 -> V_3 -> V_12 ) ;
F_55 ( V_55 , V_53 -> V_57 ) ;
F_52 ( V_55 , L_4 , V_53 -> V_58 ) ;
F_56 ( V_55 ) ;
}
static void F_57 ( struct V_1 * V_3 )
{
struct V_52 * V_53 , * V_59 ;
struct V_60 * V_23 ;
F_58 (rule, next, &tree->rules, rlist) {
V_23 = F_16 ( V_53 , struct V_60 , V_53 ) ;
F_36 ( & V_53 -> V_61 ) ;
if ( V_53 -> V_3 ) {
F_49 ( V_53 ) ;
V_53 -> V_3 = NULL ;
F_37 ( & V_23 -> V_9 ) ;
F_59 ( & V_23 -> V_53 . V_9 ) ;
F_18 ( & V_23 -> V_21 , V_62 ) ;
}
}
}
static void F_60 ( struct V_1 * V_63 )
{
F_35 ( & V_39 ) ;
while ( ! F_61 ( & V_63 -> V_7 ) ) {
struct V_26 * V_36 ;
V_36 = F_62 ( V_63 -> V_7 . V_59 , struct V_26 , V_9 ) ;
F_32 ( V_36 ) ;
}
F_34 ( & V_39 ) ;
F_7 ( V_63 ) ;
}
static void F_63 ( struct V_1 * V_3 )
{
struct V_30 * V_36 , * V_64 ;
F_35 ( & V_39 ) ;
if ( V_3 -> V_6 ) {
F_34 ( & V_39 ) ;
return;
}
for ( V_36 = V_3 -> V_7 . V_59 ; V_36 != & V_3 -> V_7 ; V_36 = V_64 ) {
struct V_26 * V_26 = F_62 ( V_36 , struct V_26 , V_9 ) ;
V_64 = V_36 -> V_59 ;
if ( V_26 -> V_29 & ( 1U << 31 ) ) {
F_36 ( V_36 ) ;
F_46 ( V_36 , & V_3 -> V_7 ) ;
}
}
while ( ! F_61 ( & V_3 -> V_7 ) ) {
struct V_26 * V_26 ;
V_26 = F_62 ( V_3 -> V_7 . V_59 , struct V_26 , V_9 ) ;
if ( ! ( V_26 -> V_29 & ( 1U << 31 ) ) )
break;
F_32 ( V_26 ) ;
}
if ( ! V_3 -> V_11 && ! V_3 -> V_6 ) {
V_3 -> V_6 = 1 ;
F_34 ( & V_39 ) ;
F_64 ( & V_65 ) ;
F_57 ( V_3 ) ;
F_36 ( & V_3 -> V_9 ) ;
F_65 ( & V_65 ) ;
F_60 ( V_3 ) ;
} else {
F_34 ( & V_39 ) ;
}
}
int F_66 ( struct V_52 * V_53 )
{
struct V_1 * V_3 ;
V_3 = V_53 -> V_3 ;
if ( V_3 ) {
F_35 ( & V_39 ) ;
F_36 ( & V_53 -> V_61 ) ;
if ( F_61 ( & V_3 -> V_8 ) && ! V_3 -> V_6 ) {
V_3 -> V_11 = NULL ;
F_36 ( & V_3 -> V_10 ) ;
V_3 -> V_6 = 1 ;
F_67 ( & V_3 -> V_9 , & V_66 ) ;
V_53 -> V_3 = NULL ;
F_34 ( & V_39 ) ;
F_68 () ;
return 1 ;
}
V_53 -> V_3 = NULL ;
F_34 ( & V_39 ) ;
return 1 ;
}
return 0 ;
}
static int F_69 ( struct V_67 * V_68 , void * V_69 )
{
return V_68 -> V_70 -> V_71 == V_69 ;
}
void F_70 ( void )
{
struct V_30 V_72 ;
F_64 ( & V_65 ) ;
F_46 ( & V_72 , & V_73 ) ;
while ( V_72 . V_59 != & V_73 ) {
struct V_1 * V_3 ;
struct V_74 V_74 ;
struct V_67 * V_75 ;
struct V_26 * V_26 ;
int V_76 ;
V_3 = F_16 ( V_72 . V_59 , struct V_1 , V_9 ) ;
F_5 ( V_3 ) ;
F_59 ( & V_72 ) ;
F_46 ( & V_72 , & V_3 -> V_9 ) ;
F_65 ( & V_65 ) ;
V_76 = F_71 ( V_3 -> V_12 , 0 , & V_74 ) ;
if ( V_76 )
goto V_77;
V_75 = F_72 ( & V_74 ) ;
F_73 ( & V_74 ) ;
if ( F_74 ( V_75 ) )
goto V_77;
F_35 ( & V_39 ) ;
F_44 (node, &tree->chunks, list) {
struct V_14 * V_15 = F_31 ( V_26 ) ;
struct V_31 * V_31 = V_15 -> V_24 . V_16 . V_31 ;
V_26 -> V_29 |= 1U << 31 ;
if ( F_75 ( F_69 , V_31 , V_75 ) )
V_26 -> V_29 &= ~ ( 1U << 31 ) ;
}
F_34 ( & V_39 ) ;
F_63 ( V_3 ) ;
F_7 ( V_3 ) ;
F_76 ( V_75 ) ;
V_77:
F_64 ( & V_65 ) ;
}
F_59 ( & V_72 ) ;
F_65 ( & V_65 ) ;
}
int F_77 ( struct V_52 * V_53 , char * V_12 , T_2 V_78 )
{
if ( V_12 [ 0 ] != '/' ||
V_53 -> V_58 != V_79 ||
V_78 != V_80 ||
V_53 -> V_81 || V_53 -> V_82 || V_53 -> V_3 )
return - V_83 ;
V_53 -> V_3 = F_1 ( V_12 ) ;
if ( ! V_53 -> V_3 )
return - V_46 ;
return 0 ;
}
void F_78 ( struct V_1 * V_3 )
{
F_7 ( V_3 ) ;
}
static int F_79 ( struct V_67 * V_68 , void * V_69 )
{
return F_47 ( V_68 -> V_70 -> V_71 , V_69 ) ;
}
int F_80 ( struct V_52 * V_53 )
{
struct V_1 * V_84 = V_53 -> V_3 , * V_3 ;
struct V_74 V_74 ;
struct V_67 * V_68 ;
int V_76 ;
F_44 (tree, &tree_list, list) {
if ( ! strcmp ( V_84 -> V_12 , V_3 -> V_12 ) ) {
F_7 ( V_84 ) ;
V_53 -> V_3 = V_3 ;
F_46 ( & V_53 -> V_61 , & V_3 -> V_8 ) ;
return 0 ;
}
}
V_3 = V_84 ;
F_46 ( & V_3 -> V_9 , & V_73 ) ;
F_46 ( & V_53 -> V_61 , & V_3 -> V_8 ) ;
F_65 ( & V_65 ) ;
V_76 = F_71 ( V_3 -> V_12 , 0 , & V_74 ) ;
if ( V_76 )
goto V_85;
V_68 = F_72 ( & V_74 ) ;
F_73 ( & V_74 ) ;
if ( F_74 ( V_68 ) ) {
V_76 = F_81 ( V_68 ) ;
goto V_85;
}
F_5 ( V_3 ) ;
V_76 = F_75 ( F_79 , V_3 , V_68 ) ;
F_76 ( V_68 ) ;
if ( ! V_76 ) {
struct V_26 * V_26 ;
F_35 ( & V_39 ) ;
F_44 (node, &tree->chunks, list)
V_26 -> V_29 &= ~ ( 1U << 31 ) ;
F_34 ( & V_39 ) ;
} else {
F_63 ( V_3 ) ;
goto V_85;
}
F_64 ( & V_65 ) ;
if ( F_61 ( & V_53 -> V_61 ) ) {
F_7 ( V_3 ) ;
return - V_51 ;
}
V_53 -> V_3 = V_3 ;
F_7 ( V_3 ) ;
return 0 ;
V_85:
F_64 ( & V_65 ) ;
F_36 ( & V_3 -> V_9 ) ;
F_36 ( & V_3 -> V_8 ) ;
F_7 ( V_3 ) ;
return V_76 ;
}
int F_82 ( char * V_50 , char * V_37 )
{
struct V_30 V_72 , V_86 ;
int V_87 = 0 ;
struct V_74 V_88 , V_89 ;
struct V_67 * V_90 ;
int V_76 ;
V_76 = F_71 ( V_37 , 0 , & V_89 ) ;
if ( V_76 )
return V_76 ;
V_90 = F_72 ( & V_89 ) ;
F_73 ( & V_89 ) ;
if ( F_74 ( V_90 ) )
return F_81 ( V_90 ) ;
V_76 = F_71 ( V_50 , 0 , & V_88 ) ;
if ( V_76 ) {
F_76 ( V_90 ) ;
return V_76 ;
}
F_64 ( & V_65 ) ;
F_46 ( & V_86 , & V_73 ) ;
F_46 ( & V_72 , & V_86 ) ;
while ( V_72 . V_59 != & V_73 ) {
struct V_1 * V_3 ;
int V_91 = 0 ;
V_3 = F_16 ( V_72 . V_59 , struct V_1 , V_9 ) ;
F_5 ( V_3 ) ;
F_59 ( & V_72 ) ;
F_46 ( & V_72 , & V_3 -> V_9 ) ;
F_65 ( & V_65 ) ;
V_76 = F_71 ( V_3 -> V_12 , 0 , & V_89 ) ;
if ( ! V_76 ) {
V_91 = F_83 ( & V_88 , & V_89 ) ;
F_73 ( & V_89 ) ;
}
if ( ! V_91 ) {
F_7 ( V_3 ) ;
F_64 ( & V_65 ) ;
continue;
}
V_87 = F_75 ( F_79 , V_3 , V_90 ) ;
if ( V_87 ) {
F_7 ( V_3 ) ;
F_64 ( & V_65 ) ;
break;
}
F_64 ( & V_65 ) ;
F_35 ( & V_39 ) ;
if ( ! V_3 -> V_6 ) {
F_59 ( & V_3 -> V_9 ) ;
F_46 ( & V_3 -> V_9 , & V_73 ) ;
}
F_34 ( & V_39 ) ;
F_7 ( V_3 ) ;
}
while ( V_86 . V_92 != & V_73 ) {
struct V_1 * V_3 ;
V_3 = F_16 ( V_86 . V_92 , struct V_1 , V_9 ) ;
F_5 ( V_3 ) ;
F_59 ( & V_3 -> V_9 ) ;
F_46 ( & V_3 -> V_9 , & V_86 ) ;
F_65 ( & V_65 ) ;
if ( ! V_87 ) {
struct V_26 * V_26 ;
F_35 ( & V_39 ) ;
F_44 (node, &tree->chunks, list)
V_26 -> V_29 &= ~ ( 1U << 31 ) ;
F_34 ( & V_39 ) ;
} else {
F_63 ( V_3 ) ;
}
F_7 ( V_3 ) ;
F_64 ( & V_65 ) ;
}
F_59 ( & V_86 ) ;
F_59 ( & V_72 ) ;
F_65 ( & V_65 ) ;
F_73 ( & V_88 ) ;
F_76 ( V_90 ) ;
return V_87 ;
}
static int F_84 ( void * V_93 )
{
F_64 ( & V_94 ) ;
F_64 ( & V_65 ) ;
while ( ! F_61 ( & V_66 ) ) {
struct V_1 * V_63 ;
V_63 = F_62 ( V_66 . V_59 , struct V_1 , V_9 ) ;
F_36 ( & V_63 -> V_9 ) ;
F_65 ( & V_65 ) ;
F_60 ( V_63 ) ;
F_64 ( & V_65 ) ;
}
F_65 ( & V_65 ) ;
F_65 ( & V_94 ) ;
return 0 ;
}
static void F_68 ( void )
{
F_85 ( F_84 , NULL , L_5 ) ;
}
void F_86 ( struct V_30 * V_9 )
{
F_64 ( & V_94 ) ;
F_64 ( & V_65 ) ;
while ( ! F_61 ( V_9 ) ) {
struct V_1 * V_63 ;
V_63 = F_62 ( V_9 -> V_59 , struct V_1 , V_9 ) ;
F_57 ( V_63 ) ;
F_36 ( & V_63 -> V_9 ) ;
F_65 ( & V_65 ) ;
F_60 ( V_63 ) ;
F_64 ( & V_65 ) ;
}
F_65 ( & V_65 ) ;
F_65 ( & V_94 ) ;
}
static void F_87 ( struct V_14 * V_15 )
{
struct V_1 * V_18 ;
struct V_30 * V_95 = F_88 () ;
int V_96 = 0 ;
int V_32 ;
if ( V_15 -> V_41 )
return;
V_15 -> V_41 = 1 ;
F_64 ( & V_65 ) ;
F_35 ( & V_39 ) ;
while ( ! F_61 ( & V_15 -> V_28 ) ) {
V_18 = F_62 ( V_15 -> V_28 . V_59 ,
struct V_1 , V_10 ) ;
V_18 -> V_6 = 1 ;
V_18 -> V_11 = NULL ;
F_36 ( & V_18 -> V_10 ) ;
F_34 ( & V_39 ) ;
if ( ! V_95 ) {
F_57 ( V_18 ) ;
F_67 ( & V_18 -> V_9 , & V_66 ) ;
V_96 = 1 ;
} else {
F_67 ( & V_18 -> V_9 , V_95 ) ;
}
F_35 ( & V_39 ) ;
}
F_37 ( & V_15 -> V_27 ) ;
for ( V_32 = 0 ; V_32 < V_15 -> V_5 ; V_32 ++ )
F_36 ( & V_15 -> V_17 [ V_32 ] . V_9 ) ;
F_34 ( & V_39 ) ;
if ( V_96 )
F_68 () ;
F_65 ( & V_65 ) ;
}
static int F_89 ( struct V_97 * V_45 ,
struct V_22 * V_98 ,
struct V_22 * V_99 ,
struct V_100 * V_101 )
{
F_90 () ;
return - V_102 ;
}
static void F_91 ( struct V_22 * V_23 , struct V_97 * V_45 )
{
struct V_14 * V_15 = F_16 ( V_23 , struct V_14 , V_24 ) ;
F_87 ( V_15 ) ;
F_92 ( F_93 ( & V_23 -> V_103 ) < 1 ) ;
}
static bool F_94 ( struct V_97 * V_45 , struct V_31 * V_31 ,
struct V_22 * V_98 ,
struct V_22 * V_104 ,
T_3 V_105 , void * V_106 , int V_107 )
{
return false ;
}
static int T_4 F_95 ( void )
{
int V_16 ;
V_43 = F_96 ( & V_108 ) ;
if ( F_74 ( V_43 ) )
F_97 ( L_6 ) ;
for ( V_16 = 0 ; V_16 < V_35 ; V_16 ++ )
F_4 ( & V_34 [ V_16 ] ) ;
return 0 ;
}
