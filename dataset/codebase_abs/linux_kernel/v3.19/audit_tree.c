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
V_15 -> V_24 . V_30 = V_31 ;
return V_15 ;
}
static inline struct V_32 * F_24 ( const struct V_33 * V_33 )
{
unsigned long V_34 = ( unsigned long ) V_33 / V_35 ;
return V_36 + V_34 % V_37 ;
}
static void F_25 ( struct V_14 * V_15 )
{
struct V_22 * V_23 = & V_15 -> V_24 ;
struct V_32 * V_9 ;
if ( ! V_23 -> V_33 )
return;
V_9 = F_24 ( V_23 -> V_33 ) ;
F_26 ( & V_15 -> V_27 , V_9 ) ;
}
struct V_14 * F_27 ( const struct V_33 * V_33 )
{
struct V_32 * V_9 = F_24 ( V_33 ) ;
struct V_14 * V_38 ;
F_28 (p, list, hash) {
if ( V_38 -> V_24 . V_33 == V_33 ) {
F_29 ( & V_38 -> V_19 ) ;
return V_38 ;
}
}
return NULL ;
}
int F_30 ( struct V_14 * V_15 , struct V_1 * V_3 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < V_15 -> V_5 ; V_34 ++ )
if ( V_15 -> V_17 [ V_34 ] . V_18 == V_3 )
return 1 ;
return 0 ;
}
static struct V_14 * F_31 ( struct V_26 * V_38 )
{
int V_29 = V_38 -> V_29 & ~ ( 1U << 31 ) ;
V_38 -= V_29 ;
return F_16 ( V_38 , struct V_14 , V_17 [ 0 ] ) ;
}
static void F_32 ( struct V_26 * V_38 )
{
struct V_14 * V_15 = F_31 ( V_38 ) ;
struct V_22 * V_23 = & V_15 -> V_24 ;
struct V_14 * V_39 = NULL ;
struct V_1 * V_18 ;
int V_25 = V_15 -> V_5 - 1 ;
int V_16 , V_40 ;
F_33 ( V_23 ) ;
F_34 ( & V_41 ) ;
if ( V_25 )
V_39 = F_19 ( V_25 ) ;
F_35 ( & V_23 -> V_42 ) ;
if ( V_15 -> V_43 || ! V_23 -> V_33 ) {
F_34 ( & V_23 -> V_42 ) ;
if ( V_39 )
F_11 ( V_39 ) ;
goto V_44;
}
V_18 = V_38 -> V_18 ;
if ( ! V_25 ) {
V_15 -> V_43 = 1 ;
F_35 ( & V_41 ) ;
F_36 ( & V_15 -> V_28 ) ;
if ( V_18 -> V_11 == V_15 )
V_18 -> V_11 = NULL ;
F_36 ( & V_38 -> V_9 ) ;
F_37 ( & V_15 -> V_27 ) ;
F_34 ( & V_41 ) ;
F_34 ( & V_23 -> V_42 ) ;
F_38 ( V_23 , V_45 ) ;
goto V_44;
}
if ( ! V_39 )
goto V_46;
F_39 ( & V_39 -> V_24 , V_23 ) ;
if ( F_40 ( & V_39 -> V_24 , V_39 -> V_24 . V_47 , V_39 -> V_24 . V_33 , NULL , 1 ) ) {
F_41 ( & V_39 -> V_24 ) ;
goto V_46;
}
V_15 -> V_43 = 1 ;
F_35 ( & V_41 ) ;
F_42 ( & V_15 -> V_28 , & V_39 -> V_28 ) ;
if ( V_18 -> V_11 == V_15 ) {
F_36 ( & V_18 -> V_10 ) ;
V_18 -> V_11 = NULL ;
}
for ( V_16 = V_40 = 0 ; V_40 <= V_25 ; V_16 ++ , V_40 ++ ) {
struct V_1 * V_2 ;
if ( & V_15 -> V_17 [ V_40 ] == V_38 ) {
F_36 ( & V_38 -> V_9 ) ;
V_16 -- ;
continue;
}
V_2 = V_15 -> V_17 [ V_40 ] . V_18 ;
V_39 -> V_17 [ V_16 ] . V_18 = V_2 ;
V_39 -> V_17 [ V_16 ] . V_29 = V_15 -> V_17 [ V_40 ] . V_29 - V_40 + V_16 ;
if ( ! V_2 )
continue;
F_5 ( V_2 ) ;
F_42 ( & V_15 -> V_17 [ V_40 ] . V_9 , & V_39 -> V_17 [ V_16 ] . V_9 ) ;
}
F_43 ( & V_15 -> V_27 , & V_39 -> V_27 ) ;
F_44 (owner, &new->trees, same_root)
V_18 -> V_11 = V_39 ;
F_34 ( & V_41 ) ;
F_34 ( & V_23 -> V_42 ) ;
F_38 ( V_23 , V_45 ) ;
F_41 ( & V_39 -> V_24 ) ;
goto V_44;
V_46:
F_35 ( & V_41 ) ;
if ( V_18 -> V_11 == V_15 ) {
F_36 ( & V_18 -> V_10 ) ;
V_18 -> V_11 = NULL ;
}
F_36 ( & V_38 -> V_9 ) ;
V_38 -> V_18 = NULL ;
F_7 ( V_18 ) ;
F_34 ( & V_41 ) ;
F_34 ( & V_23 -> V_42 ) ;
V_44:
F_41 ( V_23 ) ;
F_35 ( & V_41 ) ;
}
static int F_45 ( struct V_33 * V_33 , struct V_1 * V_3 )
{
struct V_22 * V_23 ;
struct V_14 * V_15 = F_19 ( 1 ) ;
if ( ! V_15 )
return - V_48 ;
V_23 = & V_15 -> V_24 ;
if ( F_40 ( V_23 , V_45 , V_33 , NULL , 0 ) ) {
F_41 ( V_23 ) ;
return - V_49 ;
}
F_35 ( & V_23 -> V_42 ) ;
F_35 ( & V_41 ) ;
if ( V_3 -> V_6 ) {
F_34 ( & V_41 ) ;
V_15 -> V_43 = 1 ;
F_34 ( & V_23 -> V_42 ) ;
F_38 ( V_23 , V_45 ) ;
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
F_34 ( & V_41 ) ;
F_34 ( & V_23 -> V_42 ) ;
F_41 ( V_23 ) ;
return 0 ;
}
static int F_47 ( struct V_33 * V_33 , struct V_1 * V_3 )
{
struct V_22 * V_50 , * V_51 ;
struct V_1 * V_18 ;
struct V_14 * V_15 , * V_52 ;
struct V_26 * V_38 ;
int V_34 ;
V_50 = F_48 ( V_45 , V_33 ) ;
if ( ! V_50 )
return F_45 ( V_33 , V_3 ) ;
V_52 = F_16 ( V_50 , struct V_14 , V_24 ) ;
F_35 ( & V_41 ) ;
for ( V_34 = 0 ; V_34 < V_52 -> V_5 ; V_34 ++ ) {
if ( V_52 -> V_17 [ V_34 ] . V_18 == V_3 ) {
F_34 ( & V_41 ) ;
F_41 ( V_50 ) ;
return 0 ;
}
}
F_34 ( & V_41 ) ;
V_15 = F_19 ( V_52 -> V_5 + 1 ) ;
if ( ! V_15 ) {
F_41 ( V_50 ) ;
return - V_48 ;
}
V_51 = & V_15 -> V_24 ;
F_35 ( & V_50 -> V_42 ) ;
if ( ! V_50 -> V_33 ) {
F_34 ( & V_50 -> V_42 ) ;
F_41 ( V_50 ) ;
F_11 ( V_15 ) ;
return - V_53 ;
}
F_39 ( V_51 , V_50 ) ;
if ( F_40 ( V_51 , V_51 -> V_47 , V_51 -> V_33 , NULL , 1 ) ) {
F_34 ( & V_50 -> V_42 ) ;
F_41 ( V_51 ) ;
F_41 ( V_50 ) ;
return - V_49 ;
}
F_35 ( & V_51 -> V_42 ) ;
F_35 ( & V_41 ) ;
if ( V_3 -> V_6 ) {
F_34 ( & V_41 ) ;
V_15 -> V_43 = 1 ;
F_34 ( & V_51 -> V_42 ) ;
F_34 ( & V_50 -> V_42 ) ;
F_38 ( V_51 , V_45 ) ;
F_41 ( V_51 ) ;
F_41 ( V_50 ) ;
return 0 ;
}
F_42 ( & V_52 -> V_28 , & V_15 -> V_28 ) ;
for ( V_34 = 0 , V_38 = V_15 -> V_17 ; V_34 < V_52 -> V_5 ; V_34 ++ , V_38 ++ ) {
struct V_1 * V_2 = V_52 -> V_17 [ V_34 ] . V_18 ;
V_38 -> V_18 = V_2 ;
V_38 -> V_29 = V_52 -> V_17 [ V_34 ] . V_29 ;
if ( ! V_2 )
continue;
F_5 ( V_2 ) ;
F_42 ( & V_52 -> V_17 [ V_34 ] . V_9 , & V_38 -> V_9 ) ;
}
V_38 -> V_29 = ( V_15 -> V_5 - 1 ) | ( 1U << 31 ) ;
V_38 -> V_18 = V_3 ;
F_5 ( V_3 ) ;
F_46 ( & V_38 -> V_9 , & V_3 -> V_7 ) ;
F_43 ( & V_52 -> V_27 , & V_15 -> V_27 ) ;
F_44 (owner, &chunk->trees, same_root)
V_18 -> V_11 = V_15 ;
V_52 -> V_43 = 1 ;
if ( ! V_3 -> V_11 ) {
V_3 -> V_11 = V_15 ;
F_46 ( & V_3 -> V_10 , & V_15 -> V_28 ) ;
}
F_34 ( & V_41 ) ;
F_34 ( & V_51 -> V_42 ) ;
F_34 ( & V_50 -> V_42 ) ;
F_38 ( V_50 , V_45 ) ;
F_41 ( V_51 ) ;
F_41 ( V_50 ) ;
return 0 ;
}
static void F_49 ( struct V_54 * V_55 )
{
struct V_56 * V_57 ;
V_57 = F_50 ( NULL , V_4 , V_58 ) ;
if ( F_51 ( ! V_57 ) )
return;
F_52 ( V_57 , L_1 ) ;
F_53 ( V_57 , L_2 ) ;
F_52 ( V_57 , L_3 ) ;
F_54 ( V_57 , V_55 -> V_3 -> V_12 ) ;
F_55 ( V_57 , V_55 -> V_59 ) ;
F_52 ( V_57 , L_4 , V_55 -> V_60 ) ;
F_56 ( V_57 ) ;
}
static void F_57 ( struct V_1 * V_3 )
{
struct V_54 * V_55 , * V_61 ;
struct V_62 * V_23 ;
F_58 (rule, next, &tree->rules, rlist) {
V_23 = F_16 ( V_55 , struct V_62 , V_55 ) ;
F_36 ( & V_55 -> V_63 ) ;
if ( V_55 -> V_3 ) {
F_49 ( V_55 ) ;
V_55 -> V_3 = NULL ;
F_37 ( & V_23 -> V_9 ) ;
F_59 ( & V_23 -> V_55 . V_9 ) ;
F_18 ( & V_23 -> V_21 , V_64 ) ;
}
}
}
static void F_60 ( struct V_1 * V_65 )
{
F_35 ( & V_41 ) ;
while ( ! F_61 ( & V_65 -> V_7 ) ) {
struct V_26 * V_38 ;
V_38 = F_62 ( V_65 -> V_7 . V_61 , struct V_26 , V_9 ) ;
F_32 ( V_38 ) ;
}
F_34 ( & V_41 ) ;
F_7 ( V_65 ) ;
}
static void F_63 ( struct V_1 * V_3 )
{
struct V_32 * V_38 , * V_66 ;
F_35 ( & V_41 ) ;
if ( V_3 -> V_6 ) {
F_34 ( & V_41 ) ;
return;
}
for ( V_38 = V_3 -> V_7 . V_61 ; V_38 != & V_3 -> V_7 ; V_38 = V_66 ) {
struct V_26 * V_26 = F_62 ( V_38 , struct V_26 , V_9 ) ;
V_66 = V_38 -> V_61 ;
if ( V_26 -> V_29 & ( 1U << 31 ) ) {
F_36 ( V_38 ) ;
F_46 ( V_38 , & V_3 -> V_7 ) ;
}
}
while ( ! F_61 ( & V_3 -> V_7 ) ) {
struct V_26 * V_26 ;
V_26 = F_62 ( V_3 -> V_7 . V_61 , struct V_26 , V_9 ) ;
if ( ! ( V_26 -> V_29 & ( 1U << 31 ) ) )
break;
F_32 ( V_26 ) ;
}
if ( ! V_3 -> V_11 && ! V_3 -> V_6 ) {
V_3 -> V_6 = 1 ;
F_34 ( & V_41 ) ;
F_64 ( & V_67 ) ;
F_57 ( V_3 ) ;
F_36 ( & V_3 -> V_9 ) ;
F_65 ( & V_67 ) ;
F_60 ( V_3 ) ;
} else {
F_34 ( & V_41 ) ;
}
}
int F_66 ( struct V_54 * V_55 )
{
struct V_1 * V_3 ;
V_3 = V_55 -> V_3 ;
if ( V_3 ) {
F_35 ( & V_41 ) ;
F_36 ( & V_55 -> V_63 ) ;
if ( F_61 ( & V_3 -> V_8 ) && ! V_3 -> V_6 ) {
V_3 -> V_11 = NULL ;
F_36 ( & V_3 -> V_10 ) ;
V_3 -> V_6 = 1 ;
F_67 ( & V_3 -> V_9 , & V_68 ) ;
V_55 -> V_3 = NULL ;
F_34 ( & V_41 ) ;
F_68 () ;
return 1 ;
}
V_55 -> V_3 = NULL ;
F_34 ( & V_41 ) ;
return 1 ;
}
return 0 ;
}
static int F_69 ( struct V_69 * V_70 , void * V_71 )
{
return V_70 -> V_72 -> V_73 == V_71 ;
}
void F_70 ( void )
{
struct V_32 V_74 ;
F_64 ( & V_67 ) ;
F_46 ( & V_74 , & V_75 ) ;
while ( V_74 . V_61 != & V_75 ) {
struct V_1 * V_3 ;
struct V_76 V_76 ;
struct V_69 * V_77 ;
struct V_26 * V_26 ;
int V_78 ;
V_3 = F_16 ( V_74 . V_61 , struct V_1 , V_9 ) ;
F_5 ( V_3 ) ;
F_59 ( & V_74 ) ;
F_46 ( & V_74 , & V_3 -> V_9 ) ;
F_65 ( & V_67 ) ;
V_78 = F_71 ( V_3 -> V_12 , 0 , & V_76 ) ;
if ( V_78 )
goto V_79;
V_77 = F_72 ( & V_76 ) ;
F_73 ( & V_76 ) ;
if ( F_74 ( V_77 ) )
goto V_79;
F_35 ( & V_41 ) ;
F_44 (node, &tree->chunks, list) {
struct V_14 * V_15 = F_31 ( V_26 ) ;
struct V_33 * V_33 = V_15 -> V_24 . V_33 ;
V_26 -> V_29 |= 1U << 31 ;
if ( F_75 ( F_69 , V_33 , V_77 ) )
V_26 -> V_29 &= ~ ( 1U << 31 ) ;
}
F_34 ( & V_41 ) ;
F_63 ( V_3 ) ;
F_76 ( V_77 ) ;
V_79:
F_7 ( V_3 ) ;
F_64 ( & V_67 ) ;
}
F_59 ( & V_74 ) ;
F_65 ( & V_67 ) ;
}
int F_77 ( struct V_54 * V_55 , char * V_12 , T_2 V_80 )
{
if ( V_12 [ 0 ] != '/' ||
V_55 -> V_60 != V_81 ||
V_80 != V_82 ||
V_55 -> V_83 || V_55 -> V_84 || V_55 -> V_3 )
return - V_85 ;
V_55 -> V_3 = F_1 ( V_12 ) ;
if ( ! V_55 -> V_3 )
return - V_48 ;
return 0 ;
}
void F_78 ( struct V_1 * V_3 )
{
F_7 ( V_3 ) ;
}
static int F_79 ( struct V_69 * V_70 , void * V_71 )
{
return F_47 ( V_70 -> V_72 -> V_73 , V_71 ) ;
}
int F_80 ( struct V_54 * V_55 )
{
struct V_1 * V_86 = V_55 -> V_3 , * V_3 ;
struct V_76 V_76 ;
struct V_69 * V_70 ;
int V_78 ;
V_55 -> V_3 = NULL ;
F_44 (tree, &tree_list, list) {
if ( ! strcmp ( V_86 -> V_12 , V_3 -> V_12 ) ) {
F_7 ( V_86 ) ;
V_55 -> V_3 = V_3 ;
F_46 ( & V_55 -> V_63 , & V_3 -> V_8 ) ;
return 0 ;
}
}
V_3 = V_86 ;
F_46 ( & V_3 -> V_9 , & V_75 ) ;
F_46 ( & V_55 -> V_63 , & V_3 -> V_8 ) ;
F_65 ( & V_67 ) ;
V_78 = F_71 ( V_3 -> V_12 , 0 , & V_76 ) ;
if ( V_78 )
goto V_87;
V_70 = F_72 ( & V_76 ) ;
F_73 ( & V_76 ) ;
if ( F_74 ( V_70 ) ) {
V_78 = F_81 ( V_70 ) ;
goto V_87;
}
F_5 ( V_3 ) ;
V_78 = F_75 ( F_79 , V_3 , V_70 ) ;
F_76 ( V_70 ) ;
if ( ! V_78 ) {
struct V_26 * V_26 ;
F_35 ( & V_41 ) ;
F_44 (node, &tree->chunks, list)
V_26 -> V_29 &= ~ ( 1U << 31 ) ;
F_34 ( & V_41 ) ;
} else {
F_63 ( V_3 ) ;
goto V_87;
}
F_64 ( & V_67 ) ;
if ( F_61 ( & V_55 -> V_63 ) ) {
F_7 ( V_3 ) ;
return - V_53 ;
}
V_55 -> V_3 = V_3 ;
F_7 ( V_3 ) ;
return 0 ;
V_87:
F_64 ( & V_67 ) ;
F_36 ( & V_3 -> V_9 ) ;
F_36 ( & V_3 -> V_8 ) ;
F_7 ( V_3 ) ;
return V_78 ;
}
int F_82 ( char * V_52 , char * V_39 )
{
struct V_32 V_74 , V_88 ;
int V_89 = 0 ;
struct V_76 V_90 , V_91 ;
struct V_69 * V_92 ;
int V_78 ;
V_78 = F_71 ( V_39 , 0 , & V_91 ) ;
if ( V_78 )
return V_78 ;
V_92 = F_72 ( & V_91 ) ;
F_73 ( & V_91 ) ;
if ( F_74 ( V_92 ) )
return F_81 ( V_92 ) ;
V_78 = F_71 ( V_52 , 0 , & V_90 ) ;
if ( V_78 ) {
F_76 ( V_92 ) ;
return V_78 ;
}
F_64 ( & V_67 ) ;
F_46 ( & V_88 , & V_75 ) ;
F_46 ( & V_74 , & V_88 ) ;
while ( V_74 . V_61 != & V_75 ) {
struct V_1 * V_3 ;
int V_93 = 0 ;
V_3 = F_16 ( V_74 . V_61 , struct V_1 , V_9 ) ;
F_5 ( V_3 ) ;
F_59 ( & V_74 ) ;
F_46 ( & V_74 , & V_3 -> V_9 ) ;
F_65 ( & V_67 ) ;
V_78 = F_71 ( V_3 -> V_12 , 0 , & V_91 ) ;
if ( ! V_78 ) {
V_93 = F_83 ( & V_90 , & V_91 ) ;
F_73 ( & V_91 ) ;
}
if ( ! V_93 ) {
F_7 ( V_3 ) ;
F_64 ( & V_67 ) ;
continue;
}
V_89 = F_75 ( F_79 , V_3 , V_92 ) ;
if ( V_89 ) {
F_7 ( V_3 ) ;
F_64 ( & V_67 ) ;
break;
}
F_64 ( & V_67 ) ;
F_35 ( & V_41 ) ;
if ( ! V_3 -> V_6 ) {
F_59 ( & V_3 -> V_9 ) ;
F_46 ( & V_3 -> V_9 , & V_75 ) ;
}
F_34 ( & V_41 ) ;
F_7 ( V_3 ) ;
}
while ( V_88 . V_94 != & V_75 ) {
struct V_1 * V_3 ;
V_3 = F_16 ( V_88 . V_94 , struct V_1 , V_9 ) ;
F_5 ( V_3 ) ;
F_59 ( & V_3 -> V_9 ) ;
F_46 ( & V_3 -> V_9 , & V_88 ) ;
F_65 ( & V_67 ) ;
if ( ! V_89 ) {
struct V_26 * V_26 ;
F_35 ( & V_41 ) ;
F_44 (node, &tree->chunks, list)
V_26 -> V_29 &= ~ ( 1U << 31 ) ;
F_34 ( & V_41 ) ;
} else {
F_63 ( V_3 ) ;
}
F_7 ( V_3 ) ;
F_64 ( & V_67 ) ;
}
F_59 ( & V_88 ) ;
F_59 ( & V_74 ) ;
F_65 ( & V_67 ) ;
F_73 ( & V_90 ) ;
F_76 ( V_92 ) ;
return V_89 ;
}
static int F_84 ( void * V_95 )
{
F_64 ( & V_96 ) ;
F_64 ( & V_67 ) ;
while ( ! F_61 ( & V_68 ) ) {
struct V_1 * V_65 ;
V_65 = F_62 ( V_68 . V_61 , struct V_1 , V_9 ) ;
F_36 ( & V_65 -> V_9 ) ;
F_65 ( & V_67 ) ;
F_60 ( V_65 ) ;
F_64 ( & V_67 ) ;
}
F_65 ( & V_67 ) ;
F_65 ( & V_96 ) ;
return 0 ;
}
static void F_68 ( void )
{
F_85 ( F_84 , NULL , L_5 ) ;
}
void F_86 ( struct V_32 * V_9 )
{
F_64 ( & V_96 ) ;
F_64 ( & V_67 ) ;
while ( ! F_61 ( V_9 ) ) {
struct V_1 * V_65 ;
V_65 = F_62 ( V_9 -> V_61 , struct V_1 , V_9 ) ;
F_57 ( V_65 ) ;
F_36 ( & V_65 -> V_9 ) ;
F_65 ( & V_67 ) ;
F_60 ( V_65 ) ;
F_64 ( & V_67 ) ;
}
F_65 ( & V_67 ) ;
F_65 ( & V_96 ) ;
}
static void F_87 ( struct V_14 * V_15 )
{
struct V_1 * V_18 ;
struct V_32 * V_97 = F_88 () ;
int V_98 = 0 ;
int V_34 ;
if ( V_15 -> V_43 )
return;
V_15 -> V_43 = 1 ;
F_64 ( & V_67 ) ;
F_35 ( & V_41 ) ;
while ( ! F_61 ( & V_15 -> V_28 ) ) {
V_18 = F_62 ( V_15 -> V_28 . V_61 ,
struct V_1 , V_10 ) ;
V_18 -> V_6 = 1 ;
V_18 -> V_11 = NULL ;
F_36 ( & V_18 -> V_10 ) ;
F_34 ( & V_41 ) ;
if ( ! V_97 ) {
F_57 ( V_18 ) ;
F_67 ( & V_18 -> V_9 , & V_68 ) ;
V_98 = 1 ;
} else {
F_67 ( & V_18 -> V_9 , V_97 ) ;
}
F_35 ( & V_41 ) ;
}
F_37 ( & V_15 -> V_27 ) ;
for ( V_34 = 0 ; V_34 < V_15 -> V_5 ; V_34 ++ )
F_36 ( & V_15 -> V_17 [ V_34 ] . V_9 ) ;
F_34 ( & V_41 ) ;
if ( V_98 )
F_68 () ;
F_65 ( & V_67 ) ;
}
static int F_89 ( struct V_99 * V_47 ,
struct V_33 * V_100 ,
struct V_22 * V_101 ,
struct V_22 * V_102 ,
T_2 V_30 , void * V_103 , int V_104 ,
const unsigned char * V_105 , T_2 V_106 )
{
return 0 ;
}
static void F_90 ( struct V_22 * V_23 , struct V_99 * V_47 )
{
struct V_14 * V_15 = F_16 ( V_23 , struct V_14 , V_24 ) ;
F_87 ( V_15 ) ;
F_91 ( F_92 ( & V_23 -> V_107 ) < 1 ) ;
}
static int T_3 F_93 ( void )
{
int V_16 ;
V_45 = F_94 ( & V_108 ) ;
if ( F_74 ( V_45 ) )
F_95 ( L_6 ) ;
for ( V_16 = 0 ; V_16 < V_37 ; V_16 ++ )
F_4 ( & V_36 [ V_16 ] ) ;
return 0 ;
}
