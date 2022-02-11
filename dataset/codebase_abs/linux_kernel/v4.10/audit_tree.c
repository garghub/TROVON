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
bool F_30 ( struct V_14 * V_15 , struct V_1 * V_3 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < V_15 -> V_5 ; V_34 ++ )
if ( V_15 -> V_17 [ V_34 ] . V_18 == V_3 )
return true ;
return false ;
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
F_35 ( & V_23 -> V_42 -> V_43 ) ;
F_36 ( & V_23 -> V_44 ) ;
if ( V_15 -> V_45 || ! V_23 -> V_33 ) {
F_34 ( & V_23 -> V_44 ) ;
F_37 ( & V_23 -> V_42 -> V_43 ) ;
if ( V_39 )
F_11 ( V_39 ) ;
goto V_46;
}
V_18 = V_38 -> V_18 ;
if ( ! V_25 ) {
V_15 -> V_45 = 1 ;
F_36 ( & V_41 ) ;
F_38 ( & V_15 -> V_28 ) ;
if ( V_18 -> V_11 == V_15 )
V_18 -> V_11 = NULL ;
F_38 ( & V_38 -> V_9 ) ;
F_39 ( & V_15 -> V_27 ) ;
F_34 ( & V_41 ) ;
F_34 ( & V_23 -> V_44 ) ;
F_37 ( & V_23 -> V_42 -> V_43 ) ;
F_40 ( V_23 , V_47 ) ;
goto V_46;
}
if ( ! V_39 )
goto V_48;
if ( F_41 ( & V_39 -> V_24 , V_23 -> V_42 , V_23 -> V_33 ,
NULL , 1 ) ) {
F_42 ( & V_39 -> V_24 ) ;
goto V_48;
}
V_15 -> V_45 = 1 ;
F_36 ( & V_41 ) ;
F_43 ( & V_15 -> V_28 , & V_39 -> V_28 ) ;
if ( V_18 -> V_11 == V_15 ) {
F_38 ( & V_18 -> V_10 ) ;
V_18 -> V_11 = NULL ;
}
for ( V_16 = V_40 = 0 ; V_40 <= V_25 ; V_16 ++ , V_40 ++ ) {
struct V_1 * V_2 ;
if ( & V_15 -> V_17 [ V_40 ] == V_38 ) {
F_38 ( & V_38 -> V_9 ) ;
V_16 -- ;
continue;
}
V_2 = V_15 -> V_17 [ V_40 ] . V_18 ;
V_39 -> V_17 [ V_16 ] . V_18 = V_2 ;
V_39 -> V_17 [ V_16 ] . V_29 = V_15 -> V_17 [ V_40 ] . V_29 - V_40 + V_16 ;
if ( ! V_2 )
continue;
F_5 ( V_2 ) ;
F_43 ( & V_15 -> V_17 [ V_40 ] . V_9 , & V_39 -> V_17 [ V_16 ] . V_9 ) ;
}
F_44 ( & V_15 -> V_27 , & V_39 -> V_27 ) ;
F_45 (owner, &new->trees, same_root)
V_18 -> V_11 = V_39 ;
F_34 ( & V_41 ) ;
F_34 ( & V_23 -> V_44 ) ;
F_37 ( & V_23 -> V_42 -> V_43 ) ;
F_40 ( V_23 , V_47 ) ;
F_42 ( & V_39 -> V_24 ) ;
goto V_46;
V_48:
F_36 ( & V_41 ) ;
if ( V_18 -> V_11 == V_15 ) {
F_38 ( & V_18 -> V_10 ) ;
V_18 -> V_11 = NULL ;
}
F_38 ( & V_38 -> V_9 ) ;
V_38 -> V_18 = NULL ;
F_7 ( V_18 ) ;
F_34 ( & V_41 ) ;
F_34 ( & V_23 -> V_44 ) ;
F_37 ( & V_23 -> V_42 -> V_43 ) ;
V_46:
F_42 ( V_23 ) ;
F_36 ( & V_41 ) ;
}
static int F_46 ( struct V_33 * V_33 , struct V_1 * V_3 )
{
struct V_22 * V_23 ;
struct V_14 * V_15 = F_19 ( 1 ) ;
if ( ! V_15 )
return - V_49 ;
V_23 = & V_15 -> V_24 ;
if ( F_47 ( V_23 , V_47 , V_33 , NULL , 0 ) ) {
F_42 ( V_23 ) ;
return - V_50 ;
}
F_36 ( & V_23 -> V_44 ) ;
F_36 ( & V_41 ) ;
if ( V_3 -> V_6 ) {
F_34 ( & V_41 ) ;
V_15 -> V_45 = 1 ;
F_34 ( & V_23 -> V_44 ) ;
F_40 ( V_23 , V_47 ) ;
F_42 ( V_23 ) ;
return 0 ;
}
V_15 -> V_17 [ 0 ] . V_29 = ( 1U << 31 ) ;
V_15 -> V_17 [ 0 ] . V_18 = V_3 ;
F_5 ( V_3 ) ;
F_48 ( & V_15 -> V_17 [ 0 ] . V_9 , & V_3 -> V_7 ) ;
if ( ! V_3 -> V_11 ) {
V_3 -> V_11 = V_15 ;
F_48 ( & V_3 -> V_10 , & V_15 -> V_28 ) ;
}
F_25 ( V_15 ) ;
F_34 ( & V_41 ) ;
F_34 ( & V_23 -> V_44 ) ;
F_42 ( V_23 ) ;
return 0 ;
}
static int F_49 ( struct V_33 * V_33 , struct V_1 * V_3 )
{
struct V_22 * V_51 , * V_52 ;
struct V_1 * V_18 ;
struct V_14 * V_15 , * V_53 ;
struct V_26 * V_38 ;
int V_34 ;
V_51 = F_50 ( V_47 , V_33 ) ;
if ( ! V_51 )
return F_46 ( V_33 , V_3 ) ;
V_53 = F_16 ( V_51 , struct V_14 , V_24 ) ;
F_36 ( & V_41 ) ;
for ( V_34 = 0 ; V_34 < V_53 -> V_5 ; V_34 ++ ) {
if ( V_53 -> V_17 [ V_34 ] . V_18 == V_3 ) {
F_34 ( & V_41 ) ;
F_42 ( V_51 ) ;
return 0 ;
}
}
F_34 ( & V_41 ) ;
V_15 = F_19 ( V_53 -> V_5 + 1 ) ;
if ( ! V_15 ) {
F_42 ( V_51 ) ;
return - V_49 ;
}
V_52 = & V_15 -> V_24 ;
F_35 ( & V_51 -> V_42 -> V_43 ) ;
F_36 ( & V_51 -> V_44 ) ;
if ( ! V_51 -> V_33 ) {
F_34 ( & V_51 -> V_44 ) ;
F_37 ( & V_51 -> V_42 -> V_43 ) ;
F_42 ( V_51 ) ;
F_11 ( V_15 ) ;
return - V_54 ;
}
if ( F_41 ( V_52 , V_51 -> V_42 ,
V_51 -> V_33 , NULL , 1 ) ) {
F_34 ( & V_51 -> V_44 ) ;
F_37 ( & V_51 -> V_42 -> V_43 ) ;
F_42 ( V_52 ) ;
F_42 ( V_51 ) ;
return - V_50 ;
}
F_36 ( & V_52 -> V_44 ) ;
F_36 ( & V_41 ) ;
if ( V_3 -> V_6 ) {
F_34 ( & V_41 ) ;
V_15 -> V_45 = 1 ;
F_34 ( & V_52 -> V_44 ) ;
F_34 ( & V_51 -> V_44 ) ;
F_37 ( & V_51 -> V_42 -> V_43 ) ;
F_40 ( V_52 , V_47 ) ;
F_42 ( V_52 ) ;
F_42 ( V_51 ) ;
return 0 ;
}
F_43 ( & V_53 -> V_28 , & V_15 -> V_28 ) ;
for ( V_34 = 0 , V_38 = V_15 -> V_17 ; V_34 < V_53 -> V_5 ; V_34 ++ , V_38 ++ ) {
struct V_1 * V_2 = V_53 -> V_17 [ V_34 ] . V_18 ;
V_38 -> V_18 = V_2 ;
V_38 -> V_29 = V_53 -> V_17 [ V_34 ] . V_29 ;
if ( ! V_2 )
continue;
F_5 ( V_2 ) ;
F_43 ( & V_53 -> V_17 [ V_34 ] . V_9 , & V_38 -> V_9 ) ;
}
V_38 -> V_29 = ( V_15 -> V_5 - 1 ) | ( 1U << 31 ) ;
V_38 -> V_18 = V_3 ;
F_5 ( V_3 ) ;
F_48 ( & V_38 -> V_9 , & V_3 -> V_7 ) ;
F_44 ( & V_53 -> V_27 , & V_15 -> V_27 ) ;
F_45 (owner, &chunk->trees, same_root)
V_18 -> V_11 = V_15 ;
V_53 -> V_45 = 1 ;
if ( ! V_3 -> V_11 ) {
V_3 -> V_11 = V_15 ;
F_48 ( & V_3 -> V_10 , & V_15 -> V_28 ) ;
}
F_34 ( & V_41 ) ;
F_34 ( & V_52 -> V_44 ) ;
F_34 ( & V_51 -> V_44 ) ;
F_37 ( & V_51 -> V_42 -> V_43 ) ;
F_40 ( V_51 , V_47 ) ;
F_42 ( V_52 ) ;
F_42 ( V_51 ) ;
return 0 ;
}
static void F_51 ( struct V_55 * V_56 )
{
struct V_57 * V_58 ;
V_58 = F_52 ( NULL , V_4 , V_59 ) ;
if ( F_53 ( ! V_58 ) )
return;
F_54 ( V_58 , L_1 ) ;
F_54 ( V_58 , L_2 ) ;
F_55 ( V_58 , V_56 -> V_3 -> V_12 ) ;
F_56 ( V_58 , V_56 -> V_60 ) ;
F_54 ( V_58 , L_3 , V_56 -> V_61 ) ;
F_57 ( V_58 ) ;
}
static void F_58 ( struct V_1 * V_3 )
{
struct V_55 * V_56 , * V_62 ;
struct V_63 * V_23 ;
F_59 (rule, next, &tree->rules, rlist) {
V_23 = F_16 ( V_56 , struct V_63 , V_56 ) ;
F_38 ( & V_56 -> V_64 ) ;
if ( V_56 -> V_3 ) {
F_51 ( V_56 ) ;
if ( V_23 -> V_56 . V_65 )
F_60 ( V_23 -> V_56 . V_65 ) ;
V_56 -> V_3 = NULL ;
F_39 ( & V_23 -> V_9 ) ;
F_61 ( & V_23 -> V_56 . V_9 ) ;
F_18 ( & V_23 -> V_21 , V_66 ) ;
}
}
}
static void F_62 ( struct V_1 * V_67 )
{
F_36 ( & V_41 ) ;
while ( ! F_63 ( & V_67 -> V_7 ) ) {
struct V_26 * V_38 ;
V_38 = F_64 ( V_67 -> V_7 . V_62 , struct V_26 , V_9 ) ;
F_32 ( V_38 ) ;
}
F_34 ( & V_41 ) ;
F_7 ( V_67 ) ;
}
static void F_65 ( struct V_1 * V_3 )
{
struct V_32 * V_38 , * V_68 ;
F_36 ( & V_41 ) ;
if ( V_3 -> V_6 ) {
F_34 ( & V_41 ) ;
return;
}
for ( V_38 = V_3 -> V_7 . V_62 ; V_38 != & V_3 -> V_7 ; V_38 = V_68 ) {
struct V_26 * V_26 = F_64 ( V_38 , struct V_26 , V_9 ) ;
V_68 = V_38 -> V_62 ;
if ( V_26 -> V_29 & ( 1U << 31 ) ) {
F_38 ( V_38 ) ;
F_48 ( V_38 , & V_3 -> V_7 ) ;
}
}
while ( ! F_63 ( & V_3 -> V_7 ) ) {
struct V_26 * V_26 ;
V_26 = F_64 ( V_3 -> V_7 . V_62 , struct V_26 , V_9 ) ;
if ( ! ( V_26 -> V_29 & ( 1U << 31 ) ) )
break;
F_32 ( V_26 ) ;
}
if ( ! V_3 -> V_11 && ! V_3 -> V_6 ) {
V_3 -> V_6 = 1 ;
F_34 ( & V_41 ) ;
F_35 ( & V_69 ) ;
F_58 ( V_3 ) ;
F_38 ( & V_3 -> V_9 ) ;
F_37 ( & V_69 ) ;
F_62 ( V_3 ) ;
} else {
F_34 ( & V_41 ) ;
}
}
int F_66 ( struct V_55 * V_56 )
{
struct V_1 * V_3 ;
V_3 = V_56 -> V_3 ;
if ( V_3 ) {
F_36 ( & V_41 ) ;
F_38 ( & V_56 -> V_64 ) ;
if ( F_63 ( & V_3 -> V_8 ) && ! V_3 -> V_6 ) {
V_3 -> V_11 = NULL ;
F_38 ( & V_3 -> V_10 ) ;
V_3 -> V_6 = 1 ;
F_67 ( & V_3 -> V_9 , & V_70 ) ;
V_56 -> V_3 = NULL ;
F_34 ( & V_41 ) ;
F_68 () ;
return 1 ;
}
V_56 -> V_3 = NULL ;
F_34 ( & V_41 ) ;
return 1 ;
}
return 0 ;
}
static int F_69 ( struct V_71 * V_72 , void * V_73 )
{
return F_70 ( V_72 -> V_74 ) == V_73 ;
}
void F_71 ( void )
{
struct V_32 V_75 ;
F_35 ( & V_69 ) ;
F_48 ( & V_75 , & V_76 ) ;
while ( V_75 . V_62 != & V_76 ) {
struct V_1 * V_3 ;
struct V_77 V_77 ;
struct V_71 * V_78 ;
struct V_26 * V_26 ;
int V_79 ;
V_3 = F_16 ( V_75 . V_62 , struct V_1 , V_9 ) ;
F_5 ( V_3 ) ;
F_61 ( & V_75 ) ;
F_48 ( & V_75 , & V_3 -> V_9 ) ;
F_37 ( & V_69 ) ;
V_79 = F_72 ( V_3 -> V_12 , 0 , & V_77 ) ;
if ( V_79 )
goto V_80;
V_78 = F_73 ( & V_77 ) ;
F_74 ( & V_77 ) ;
if ( F_75 ( V_78 ) )
goto V_80;
F_36 ( & V_41 ) ;
F_45 (node, &tree->chunks, list) {
struct V_14 * V_15 = F_31 ( V_26 ) ;
struct V_33 * V_33 = V_15 -> V_24 . V_33 ;
V_26 -> V_29 |= 1U << 31 ;
if ( F_76 ( F_69 , V_33 , V_78 ) )
V_26 -> V_29 &= ~ ( 1U << 31 ) ;
}
F_34 ( & V_41 ) ;
F_65 ( V_3 ) ;
F_77 ( V_78 ) ;
V_80:
F_7 ( V_3 ) ;
F_35 ( & V_69 ) ;
}
F_61 ( & V_75 ) ;
F_37 ( & V_69 ) ;
}
int F_78 ( struct V_55 * V_56 , char * V_12 , T_2 V_81 )
{
if ( V_12 [ 0 ] != '/' ||
V_56 -> V_61 != V_82 ||
V_81 != V_83 ||
V_56 -> V_84 || V_56 -> V_85 || V_56 -> V_3 )
return - V_86 ;
V_56 -> V_3 = F_1 ( V_12 ) ;
if ( ! V_56 -> V_3 )
return - V_49 ;
return 0 ;
}
void F_79 ( struct V_1 * V_3 )
{
F_7 ( V_3 ) ;
}
static int F_80 ( struct V_71 * V_72 , void * V_73 )
{
return F_49 ( F_70 ( V_72 -> V_74 ) , V_73 ) ;
}
static int F_81 ( void * V_87 )
{
for (; ; ) {
if ( F_63 ( & V_70 ) ) {
F_82 ( V_88 ) ;
F_83 () ;
}
F_35 ( & V_89 ) ;
F_35 ( & V_69 ) ;
while ( ! F_63 ( & V_70 ) ) {
struct V_1 * V_67 ;
V_67 = F_64 ( V_70 . V_62 ,
struct V_1 , V_9 ) ;
F_38 ( & V_67 -> V_9 ) ;
F_37 ( & V_69 ) ;
F_62 ( V_67 ) ;
F_35 ( & V_69 ) ;
}
F_37 ( & V_69 ) ;
F_37 ( & V_89 ) ;
}
return 0 ;
}
static int F_84 ( void )
{
if ( V_90 )
return 0 ;
V_90 = F_85 ( F_81 , NULL ,
L_4 ) ;
if ( F_75 ( V_90 ) ) {
F_86 ( L_5 ) ;
V_90 = NULL ;
return - V_49 ;
}
return 0 ;
}
int F_87 ( struct V_55 * V_56 )
{
struct V_1 * V_91 = V_56 -> V_3 , * V_3 ;
struct V_77 V_77 ;
struct V_71 * V_72 ;
int V_79 ;
V_56 -> V_3 = NULL ;
F_45 (tree, &tree_list, list) {
if ( ! strcmp ( V_91 -> V_12 , V_3 -> V_12 ) ) {
F_7 ( V_91 ) ;
V_56 -> V_3 = V_3 ;
F_48 ( & V_56 -> V_64 , & V_3 -> V_8 ) ;
return 0 ;
}
}
V_3 = V_91 ;
F_48 ( & V_3 -> V_9 , & V_76 ) ;
F_48 ( & V_56 -> V_64 , & V_3 -> V_8 ) ;
F_37 ( & V_69 ) ;
if ( F_53 ( ! V_90 ) ) {
V_79 = F_84 () ;
if ( V_79 )
goto V_92;
}
V_79 = F_72 ( V_3 -> V_12 , 0 , & V_77 ) ;
if ( V_79 )
goto V_92;
V_72 = F_73 ( & V_77 ) ;
F_74 ( & V_77 ) ;
if ( F_75 ( V_72 ) ) {
V_79 = F_88 ( V_72 ) ;
goto V_92;
}
F_5 ( V_3 ) ;
V_79 = F_76 ( F_80 , V_3 , V_72 ) ;
F_77 ( V_72 ) ;
if ( ! V_79 ) {
struct V_26 * V_26 ;
F_36 ( & V_41 ) ;
F_45 (node, &tree->chunks, list)
V_26 -> V_29 &= ~ ( 1U << 31 ) ;
F_34 ( & V_41 ) ;
} else {
F_65 ( V_3 ) ;
goto V_92;
}
F_35 ( & V_69 ) ;
if ( F_63 ( & V_56 -> V_64 ) ) {
F_7 ( V_3 ) ;
return - V_54 ;
}
V_56 -> V_3 = V_3 ;
F_7 ( V_3 ) ;
return 0 ;
V_92:
F_35 ( & V_69 ) ;
F_38 ( & V_3 -> V_9 ) ;
F_38 ( & V_3 -> V_8 ) ;
F_7 ( V_3 ) ;
return V_79 ;
}
int F_89 ( char * V_53 , char * V_39 )
{
struct V_32 V_75 , V_93 ;
int V_94 = 0 ;
struct V_77 V_95 , V_96 ;
struct V_71 * V_97 ;
int V_79 ;
V_79 = F_72 ( V_39 , 0 , & V_96 ) ;
if ( V_79 )
return V_79 ;
V_97 = F_73 ( & V_96 ) ;
F_74 ( & V_96 ) ;
if ( F_75 ( V_97 ) )
return F_88 ( V_97 ) ;
V_79 = F_72 ( V_53 , 0 , & V_95 ) ;
if ( V_79 ) {
F_77 ( V_97 ) ;
return V_79 ;
}
F_35 ( & V_69 ) ;
F_48 ( & V_93 , & V_76 ) ;
F_48 ( & V_75 , & V_93 ) ;
while ( V_75 . V_62 != & V_76 ) {
struct V_1 * V_3 ;
int V_98 = 0 ;
V_3 = F_16 ( V_75 . V_62 , struct V_1 , V_9 ) ;
F_5 ( V_3 ) ;
F_61 ( & V_75 ) ;
F_48 ( & V_75 , & V_3 -> V_9 ) ;
F_37 ( & V_69 ) ;
V_79 = F_72 ( V_3 -> V_12 , 0 , & V_96 ) ;
if ( ! V_79 ) {
V_98 = F_90 ( & V_95 , & V_96 ) ;
F_74 ( & V_96 ) ;
}
if ( ! V_98 ) {
F_7 ( V_3 ) ;
F_35 ( & V_69 ) ;
continue;
}
V_94 = F_76 ( F_80 , V_3 , V_97 ) ;
if ( V_94 ) {
F_7 ( V_3 ) ;
F_35 ( & V_69 ) ;
break;
}
F_35 ( & V_69 ) ;
F_36 ( & V_41 ) ;
if ( ! V_3 -> V_6 ) {
F_61 ( & V_3 -> V_9 ) ;
F_48 ( & V_3 -> V_9 , & V_76 ) ;
}
F_34 ( & V_41 ) ;
F_7 ( V_3 ) ;
}
while ( V_93 . V_99 != & V_76 ) {
struct V_1 * V_3 ;
V_3 = F_16 ( V_93 . V_99 , struct V_1 , V_9 ) ;
F_5 ( V_3 ) ;
F_61 ( & V_3 -> V_9 ) ;
F_48 ( & V_3 -> V_9 , & V_93 ) ;
F_37 ( & V_69 ) ;
if ( ! V_94 ) {
struct V_26 * V_26 ;
F_36 ( & V_41 ) ;
F_45 (node, &tree->chunks, list)
V_26 -> V_29 &= ~ ( 1U << 31 ) ;
F_34 ( & V_41 ) ;
} else {
F_65 ( V_3 ) ;
}
F_7 ( V_3 ) ;
F_35 ( & V_69 ) ;
}
F_61 ( & V_93 ) ;
F_61 ( & V_75 ) ;
F_37 ( & V_69 ) ;
F_74 ( & V_95 ) ;
F_77 ( V_97 ) ;
return V_94 ;
}
static void F_68 ( void )
{
F_91 ( V_90 ) ;
}
void F_92 ( struct V_32 * V_9 )
{
F_35 ( & V_89 ) ;
F_35 ( & V_69 ) ;
while ( ! F_63 ( V_9 ) ) {
struct V_1 * V_67 ;
V_67 = F_64 ( V_9 -> V_62 , struct V_1 , V_9 ) ;
F_58 ( V_67 ) ;
F_38 ( & V_67 -> V_9 ) ;
F_37 ( & V_69 ) ;
F_62 ( V_67 ) ;
F_35 ( & V_69 ) ;
}
F_37 ( & V_69 ) ;
F_37 ( & V_89 ) ;
}
static void F_93 ( struct V_14 * V_15 )
{
struct V_1 * V_18 ;
struct V_32 * V_100 = F_94 () ;
int V_101 = 0 ;
int V_34 ;
if ( V_15 -> V_45 )
return;
V_15 -> V_45 = 1 ;
F_35 ( & V_69 ) ;
F_36 ( & V_41 ) ;
while ( ! F_63 ( & V_15 -> V_28 ) ) {
V_18 = F_64 ( V_15 -> V_28 . V_62 ,
struct V_1 , V_10 ) ;
V_18 -> V_6 = 1 ;
V_18 -> V_11 = NULL ;
F_38 ( & V_18 -> V_10 ) ;
F_34 ( & V_41 ) ;
if ( ! V_100 ) {
F_58 ( V_18 ) ;
F_67 ( & V_18 -> V_9 , & V_70 ) ;
V_101 = 1 ;
} else {
F_67 ( & V_18 -> V_9 , V_100 ) ;
}
F_36 ( & V_41 ) ;
}
F_39 ( & V_15 -> V_27 ) ;
for ( V_34 = 0 ; V_34 < V_15 -> V_5 ; V_34 ++ )
F_38 ( & V_15 -> V_17 [ V_34 ] . V_9 ) ;
F_34 ( & V_41 ) ;
F_37 ( & V_69 ) ;
if ( V_101 )
F_68 () ;
}
static int F_95 ( struct V_102 * V_42 ,
struct V_33 * V_103 ,
struct V_22 * V_104 ,
struct V_22 * V_105 ,
T_2 V_30 , const void * V_106 , int V_107 ,
const unsigned char * V_108 , T_2 V_109 )
{
return 0 ;
}
static void F_96 ( struct V_22 * V_23 , struct V_102 * V_42 )
{
struct V_14 * V_15 = F_16 ( V_23 , struct V_14 , V_24 ) ;
F_93 ( V_15 ) ;
F_97 ( F_98 ( & V_23 -> V_110 ) < 1 ) ;
}
static int T_3 F_99 ( void )
{
int V_16 ;
V_47 = F_100 ( & V_111 ) ;
if ( F_75 ( V_47 ) )
F_101 ( L_6 ) ;
for ( V_16 = 0 ; V_16 < V_37 ; V_16 ++ )
F_4 ( & V_36 [ V_16 ] ) ;
return 0 ;
}
