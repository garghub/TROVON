static int F_1 ( const struct V_1 * V_2 , const void * V_3 )
{
const void * V_4 = F_2 ( V_2 , struct V_5 ,
V_6 ) ;
return ( memcmp ( V_4 , V_3 , V_7 ) == 0 ? 1 : 0 ) ;
}
static void F_3 ( struct V_8 * V_8 )
{
F_4 ( & V_8 -> V_9 , V_10 ) ;
F_5 ( V_11 , & V_8 -> V_9 ,
F_6 ( 5000 ) ) ;
}
static struct V_5 * F_7 ( struct V_12 * V_13 ,
const void * V_14 )
{
struct V_15 * V_16 ;
struct V_1 * V_2 ;
struct V_5 * V_5 , * V_17 = NULL ;
T_1 V_18 ;
if ( ! V_13 )
return NULL ;
V_18 = F_8 ( V_14 , V_13 -> V_19 ) ;
V_16 = & V_13 -> V_20 [ V_18 ] ;
F_9 () ;
F_10 (tt_common_entry, node, head, hash_entry) {
if ( ! F_11 ( V_5 , V_14 ) )
continue;
if ( ! F_12 ( & V_5 -> V_21 ) )
continue;
V_17 = V_5 ;
break;
}
F_13 () ;
return V_17 ;
}
static struct V_22 * F_14 ( struct V_8 * V_8 ,
const void * V_14 )
{
struct V_5 * V_5 ;
struct V_22 * V_22 = NULL ;
V_5 = F_7 ( V_8 -> V_23 , V_14 ) ;
if ( V_5 )
V_22 = F_2 ( V_5 ,
struct V_22 , V_24 ) ;
return V_22 ;
}
static struct V_25 * F_15 ( struct V_8 * V_8 ,
const void * V_14 )
{
struct V_5 * V_5 ;
struct V_25 * V_25 = NULL ;
V_5 = F_7 ( V_8 -> V_26 , V_14 ) ;
if ( V_5 )
V_25 = F_2 ( V_5 ,
struct V_25 , V_24 ) ;
return V_25 ;
}
static void F_16 ( struct V_22 * V_22 )
{
if ( F_17 ( & V_22 -> V_24 . V_21 ) )
F_18 ( V_22 , V_24 . V_27 ) ;
}
static void F_19 ( struct V_28 * V_27 )
{
struct V_5 * V_5 ;
struct V_25 * V_25 ;
V_5 = F_2 ( V_27 , struct V_5 , V_27 ) ;
V_25 = F_2 ( V_5 , struct V_25 ,
V_24 ) ;
if ( V_25 -> V_29 )
F_20 ( V_25 -> V_29 ) ;
F_21 ( V_25 ) ;
}
static void F_22 ( struct V_25 * V_25 )
{
if ( F_17 ( & V_25 -> V_24 . V_21 ) )
F_23 ( & V_25 -> V_24 . V_27 ,
F_19 ) ;
}
static void F_24 ( struct V_8 * V_8 , const T_2 * V_30 ,
T_2 V_31 )
{
struct V_32 * V_32 ;
V_32 = F_25 ( sizeof( * V_32 ) , V_33 ) ;
if ( ! V_32 )
return;
V_32 -> V_34 . V_31 = V_31 ;
memcpy ( V_32 -> V_34 . V_30 , V_30 , V_7 ) ;
F_26 ( & V_8 -> V_35 ) ;
F_27 ( & V_32 -> V_36 , & V_8 -> V_37 ) ;
F_28 ( & V_8 -> V_38 ) ;
F_29 ( & V_8 -> V_35 ) ;
F_30 ( & V_8 -> V_39 , 0 ) ;
}
int F_31 ( int V_40 )
{
return V_40 * sizeof( struct V_41 ) ;
}
static int F_32 ( struct V_8 * V_8 )
{
if ( V_8 -> V_23 )
return 1 ;
V_8 -> V_23 = F_33 ( 1024 ) ;
if ( ! V_8 -> V_23 )
return 0 ;
return 1 ;
}
void F_34 ( struct V_42 * V_43 , const T_2 * V_30 ,
int V_44 )
{
struct V_8 * V_8 = F_35 ( V_43 ) ;
struct V_22 * V_22 = NULL ;
struct V_25 * V_25 = NULL ;
int V_45 ;
V_22 = F_14 ( V_8 , V_30 ) ;
if ( V_22 ) {
V_22 -> V_46 = V_47 ;
goto V_48;
}
V_22 = F_25 ( sizeof( * V_22 ) , V_33 ) ;
if ( ! V_22 )
goto V_48;
F_36 ( V_49 , V_8 ,
L_1 , V_30 ,
( T_2 ) F_37 ( & V_8 -> V_50 ) ) ;
memcpy ( V_22 -> V_24 . V_30 , V_30 , V_7 ) ;
V_22 -> V_24 . V_31 = V_51 ;
if ( F_38 ( V_44 ) )
V_22 -> V_24 . V_31 |= V_52 ;
F_30 ( & V_22 -> V_24 . V_21 , 2 ) ;
V_22 -> V_46 = V_47 ;
if ( F_11 ( V_30 , V_43 -> V_53 ) )
V_22 -> V_24 . V_31 |= V_54 ;
V_22 -> V_24 . V_31 |= V_55 ;
V_45 = F_39 ( V_8 -> V_23 , F_1 , F_8 ,
& V_22 -> V_24 ,
& V_22 -> V_24 . V_6 ) ;
if ( F_40 ( V_45 != 0 ) ) {
F_16 ( V_22 ) ;
goto V_48;
}
F_24 ( V_8 , V_30 , V_22 -> V_24 . V_31 ) ;
V_25 = F_15 ( V_8 , V_30 ) ;
if ( V_25 ) {
V_25 -> V_29 -> V_56 = true ;
V_25 -> V_24 . V_31 |= V_57 ;
V_25 -> V_58 = V_47 ;
F_41 ( V_8 , V_25 -> V_24 . V_30 ,
V_25 -> V_29 ) ;
}
V_48:
if ( V_22 )
F_16 ( V_22 ) ;
if ( V_25 )
F_22 ( V_25 ) ;
}
int F_42 ( struct V_8 * V_8 ,
unsigned char * V_59 , int V_60 )
{
int V_61 = 0 , V_62 = 0 ;
struct V_32 * V_63 , * V_64 ;
if ( V_60 > 0 )
V_62 = V_60 / F_31 ( 1 ) ;
F_26 ( & V_8 -> V_35 ) ;
F_30 ( & V_8 -> V_38 , 0 ) ;
F_43 (entry, safe, &bat_priv->tt_changes_list,
list) {
if ( V_61 < V_62 ) {
memcpy ( V_59 + F_31 ( V_61 ) ,
& V_63 -> V_34 , sizeof( struct V_41 ) ) ;
V_61 ++ ;
}
F_44 ( & V_63 -> V_36 ) ;
F_21 ( V_63 ) ;
}
F_29 ( & V_8 -> V_35 ) ;
F_26 ( & V_8 -> V_65 ) ;
F_21 ( V_8 -> V_66 ) ;
V_8 -> V_67 = 0 ;
V_8 -> V_66 = NULL ;
if ( V_60 > 0 ) {
V_8 -> V_66 = F_25 ( V_60 , V_33 ) ;
if ( V_8 -> V_66 ) {
memcpy ( V_8 -> V_66 , V_59 , V_60 ) ;
V_8 -> V_67 = V_60 ;
}
}
F_29 ( & V_8 -> V_65 ) ;
return V_62 ;
}
int F_45 ( struct V_68 * V_69 , void * V_70 )
{
struct V_42 * V_71 = (struct V_42 * ) V_69 -> V_72 ;
struct V_8 * V_8 = F_35 ( V_71 ) ;
struct V_12 * V_13 = V_8 -> V_23 ;
struct V_5 * V_5 ;
struct V_73 * V_74 ;
struct V_1 * V_2 ;
struct V_15 * V_16 ;
T_1 V_75 ;
int V_76 = 0 ;
V_74 = F_46 ( V_8 ) ;
if ( ! V_74 ) {
V_76 = F_47 ( V_69 ,
L_2 ,
V_71 -> V_77 ) ;
goto V_48;
}
if ( V_74 -> V_78 != V_79 ) {
V_76 = F_47 ( V_69 ,
L_3 ,
V_71 -> V_77 ) ;
goto V_48;
}
F_47 ( V_69 ,
L_4 ,
V_71 -> V_77 , ( T_2 ) F_37 ( & V_8 -> V_50 ) ) ;
for ( V_75 = 0 ; V_75 < V_13 -> V_19 ; V_75 ++ ) {
V_16 = & V_13 -> V_20 [ V_75 ] ;
F_9 () ;
F_10 (tt_common_entry, node,
head, hash_entry) {
F_47 ( V_69 , L_5 ,
V_5 -> V_30 ,
( V_5 -> V_31 &
V_57 ? 'R' : '.' ) ,
( V_5 -> V_31 &
V_54 ? 'P' : '.' ) ,
( V_5 -> V_31 &
V_55 ? 'N' : '.' ) ,
( V_5 -> V_31 &
V_80 ? 'X' : '.' ) ,
( V_5 -> V_31 &
V_52 ? 'W' : '.' ) ) ;
}
F_13 () ;
}
V_48:
if ( V_74 )
F_48 ( V_74 ) ;
return V_76 ;
}
static void F_49 ( struct V_8 * V_8 ,
struct V_22 * V_22 ,
T_3 V_31 , const char * V_81 )
{
F_24 ( V_8 , V_22 -> V_24 . V_30 ,
V_22 -> V_24 . V_31 | V_31 ) ;
V_22 -> V_24 . V_31 |= V_80 ;
F_36 ( V_49 , V_8 ,
L_6 ,
V_22 -> V_24 . V_30 , V_81 ) ;
}
void F_50 ( struct V_8 * V_8 , const T_2 * V_30 ,
const char * V_81 , bool V_82 )
{
struct V_22 * V_22 = NULL ;
V_22 = F_14 ( V_8 , V_30 ) ;
if ( ! V_22 )
goto V_48;
F_49 ( V_8 , V_22 , V_83 |
( V_82 ? V_57 : V_51 ) , V_81 ) ;
V_48:
if ( V_22 )
F_16 ( V_22 ) ;
}
static void F_51 ( struct V_8 * V_8 )
{
struct V_12 * V_13 = V_8 -> V_23 ;
struct V_22 * V_22 ;
struct V_5 * V_5 ;
struct V_1 * V_2 , * V_84 ;
struct V_15 * V_16 ;
T_4 * V_85 ;
T_1 V_75 ;
for ( V_75 = 0 ; V_75 < V_13 -> V_19 ; V_75 ++ ) {
V_16 = & V_13 -> V_20 [ V_75 ] ;
V_85 = & V_13 -> V_86 [ V_75 ] ;
F_26 ( V_85 ) ;
F_52 (tt_common_entry, node, node_tmp,
head, hash_entry) {
V_22 = F_2 ( V_5 ,
struct V_22 ,
V_24 ) ;
if ( V_22 -> V_24 . V_31 & V_54 )
continue;
if ( V_22 -> V_24 . V_31 & V_80 )
continue;
if ( ! F_53 ( V_22 -> V_46 ,
V_87 ) )
continue;
F_49 ( V_8 , V_22 ,
V_83 , L_7 ) ;
}
F_29 ( V_85 ) ;
}
}
static void F_54 ( struct V_8 * V_8 )
{
struct V_12 * V_13 ;
T_4 * V_85 ;
struct V_5 * V_5 ;
struct V_22 * V_22 ;
struct V_1 * V_2 , * V_84 ;
struct V_15 * V_16 ;
T_1 V_75 ;
if ( ! V_8 -> V_23 )
return;
V_13 = V_8 -> V_23 ;
for ( V_75 = 0 ; V_75 < V_13 -> V_19 ; V_75 ++ ) {
V_16 = & V_13 -> V_20 [ V_75 ] ;
V_85 = & V_13 -> V_86 [ V_75 ] ;
F_26 ( V_85 ) ;
F_52 (tt_common_entry, node, node_tmp,
head, hash_entry) {
F_55 ( V_2 ) ;
V_22 = F_2 ( V_5 ,
struct V_22 ,
V_24 ) ;
F_16 ( V_22 ) ;
}
F_29 ( V_85 ) ;
}
F_56 ( V_13 ) ;
V_8 -> V_23 = NULL ;
}
static int F_57 ( struct V_8 * V_8 )
{
if ( V_8 -> V_26 )
return 1 ;
V_8 -> V_26 = F_33 ( 1024 ) ;
if ( ! V_8 -> V_26 )
return 0 ;
return 1 ;
}
static void F_58 ( struct V_8 * V_8 )
{
struct V_32 * V_63 , * V_64 ;
F_26 ( & V_8 -> V_35 ) ;
F_43 (entry, safe, &bat_priv->tt_changes_list,
list) {
F_44 ( & V_63 -> V_36 ) ;
F_21 ( V_63 ) ;
}
F_30 ( & V_8 -> V_38 , 0 ) ;
F_29 ( & V_8 -> V_35 ) ;
}
int F_59 ( struct V_8 * V_8 , struct V_29 * V_29 ,
const unsigned char * V_88 , T_2 V_50 , bool V_82 ,
bool V_89 )
{
struct V_25 * V_25 ;
struct V_29 * V_90 ;
int V_76 = 0 ;
int V_45 ;
V_25 = F_15 ( V_8 , V_88 ) ;
if ( ! V_25 ) {
V_25 =
F_25 ( sizeof( * V_25 ) ,
V_33 ) ;
if ( ! V_25 )
goto V_48;
memcpy ( V_25 -> V_24 . V_30 , V_88 , V_7 ) ;
V_25 -> V_24 . V_31 = V_51 ;
F_30 ( & V_25 -> V_24 . V_21 , 2 ) ;
F_28 ( & V_29 -> V_21 ) ;
V_25 -> V_29 = V_29 ;
V_25 -> V_50 = V_50 ;
V_25 -> V_58 = 0 ;
V_45 = F_39 ( V_8 -> V_26 , F_1 ,
F_8 , & V_25 -> V_24 ,
& V_25 -> V_24 . V_6 ) ;
if ( F_40 ( V_45 != 0 ) ) {
F_22 ( V_25 ) ;
goto V_91;
}
F_28 ( & V_29 -> V_92 ) ;
} else {
if ( V_25 -> V_29 != V_29 ) {
F_60 ( & V_25 -> V_29 -> V_92 ) ;
V_90 = V_25 -> V_29 ;
F_28 ( & V_29 -> V_21 ) ;
V_25 -> V_29 = V_29 ;
F_20 ( V_90 ) ;
F_28 ( & V_29 -> V_92 ) ;
}
V_25 -> V_24 . V_31 = V_51 ;
V_25 -> V_50 = V_50 ;
V_25 -> V_58 = 0 ;
}
if ( V_89 )
V_25 -> V_24 . V_31 |= V_52 ;
F_36 ( V_49 , V_8 ,
L_8 ,
V_25 -> V_24 . V_30 , V_29 -> V_93 ) ;
V_91:
F_50 ( V_8 , V_25 -> V_24 . V_30 ,
L_9 , V_82 ) ;
V_76 = 1 ;
V_48:
if ( V_25 )
F_22 ( V_25 ) ;
return V_76 ;
}
int F_61 ( struct V_68 * V_69 , void * V_70 )
{
struct V_42 * V_71 = (struct V_42 * ) V_69 -> V_72 ;
struct V_8 * V_8 = F_35 ( V_71 ) ;
struct V_12 * V_13 = V_8 -> V_26 ;
struct V_5 * V_5 ;
struct V_25 * V_25 ;
struct V_73 * V_74 ;
struct V_1 * V_2 ;
struct V_15 * V_16 ;
T_1 V_75 ;
int V_76 = 0 ;
V_74 = F_46 ( V_8 ) ;
if ( ! V_74 ) {
V_76 = F_47 ( V_69 ,
L_2 ,
V_71 -> V_77 ) ;
goto V_48;
}
if ( V_74 -> V_78 != V_79 ) {
V_76 = F_47 ( V_69 ,
L_3 ,
V_71 -> V_77 ) ;
goto V_48;
}
F_47 ( V_69 ,
L_10 ,
V_71 -> V_77 ) ;
F_47 ( V_69 , L_11 ,
L_12 , L_13 , L_14 , L_15 , L_16 ) ;
for ( V_75 = 0 ; V_75 < V_13 -> V_19 ; V_75 ++ ) {
V_16 = & V_13 -> V_20 [ V_75 ] ;
F_9 () ;
F_10 (tt_common_entry, node,
head, hash_entry) {
V_25 = F_2 ( V_5 ,
struct V_25 ,
V_24 ) ;
F_47 ( V_69 ,
L_17 ,
V_25 -> V_24 . V_30 ,
V_25 -> V_50 ,
V_25 -> V_29 -> V_93 ,
( T_2 ) F_37 (
& V_25 -> V_29 ->
V_94 ) ,
( V_25 -> V_24 . V_31 &
V_57 ? 'R' : '.' ) ,
( V_25 -> V_24 . V_31 &
V_52 ? 'W' : '.' ) ) ;
}
F_13 () ;
}
V_48:
if ( V_74 )
F_48 ( V_74 ) ;
return V_76 ;
}
static void F_62 ( struct V_8 * V_8 ,
struct V_25 * V_25 ,
const char * V_81 )
{
if ( ! V_25 )
goto V_48;
F_36 ( V_49 , V_8 ,
L_18 ,
V_25 -> V_24 . V_30 , V_25 -> V_29 -> V_93 ,
V_81 ) ;
F_60 ( & V_25 -> V_29 -> V_92 ) ;
F_63 ( V_8 -> V_26 , F_1 , F_8 ,
V_25 -> V_24 . V_30 ) ;
V_48:
if ( V_25 )
F_22 ( V_25 ) ;
}
void F_64 ( struct V_8 * V_8 ,
struct V_29 * V_29 , const unsigned char * V_30 ,
const char * V_81 , bool V_82 )
{
struct V_25 * V_25 = NULL ;
struct V_22 * V_22 = NULL ;
V_25 = F_15 ( V_8 , V_30 ) ;
if ( ! V_25 || V_25 -> V_29 != V_29 )
goto V_48;
if ( ! V_82 )
goto V_95;
V_22 = F_14 ( V_8 ,
V_25 -> V_24 . V_30 ) ;
if ( ! V_22 ) {
V_25 -> V_24 . V_31 |= V_57 ;
V_25 -> V_58 = V_47 ;
goto V_48;
}
V_95:
F_62 ( V_8 , V_25 , V_81 ) ;
V_48:
if ( V_25 )
F_22 ( V_25 ) ;
if ( V_22 )
F_16 ( V_22 ) ;
}
void F_65 ( struct V_8 * V_8 ,
struct V_29 * V_29 , const char * V_81 )
{
struct V_25 * V_25 ;
struct V_5 * V_5 ;
T_1 V_75 ;
struct V_12 * V_13 = V_8 -> V_26 ;
struct V_1 * V_2 , * V_64 ;
struct V_15 * V_16 ;
T_4 * V_85 ;
if ( ! V_13 )
return;
for ( V_75 = 0 ; V_75 < V_13 -> V_19 ; V_75 ++ ) {
V_16 = & V_13 -> V_20 [ V_75 ] ;
V_85 = & V_13 -> V_86 [ V_75 ] ;
F_26 ( V_85 ) ;
F_52 (tt_common_entry, node, safe,
head, hash_entry) {
V_25 = F_2 ( V_5 ,
struct V_25 ,
V_24 ) ;
if ( V_25 -> V_29 == V_29 ) {
F_36 ( V_49 , V_8 ,
L_18 ,
V_25 -> V_24 . V_30 ,
V_25 -> V_29 -> V_93 ,
V_81 ) ;
F_55 ( V_2 ) ;
F_22 ( V_25 ) ;
}
}
F_29 ( V_85 ) ;
}
F_30 ( & V_29 -> V_92 , 0 ) ;
V_29 -> V_96 = false ;
}
static void F_66 ( struct V_8 * V_8 )
{
struct V_12 * V_13 = V_8 -> V_26 ;
struct V_5 * V_5 ;
struct V_25 * V_25 ;
struct V_1 * V_2 , * V_84 ;
struct V_15 * V_16 ;
T_4 * V_85 ;
T_1 V_75 ;
for ( V_75 = 0 ; V_75 < V_13 -> V_19 ; V_75 ++ ) {
V_16 = & V_13 -> V_20 [ V_75 ] ;
V_85 = & V_13 -> V_86 [ V_75 ] ;
F_26 ( V_85 ) ;
F_52 (tt_common_entry, node, node_tmp,
head, hash_entry) {
V_25 = F_2 ( V_5 ,
struct V_25 ,
V_24 ) ;
if ( ! ( V_25 -> V_24 . V_31 & V_57 ) )
continue;
if ( ! F_53 ( V_25 -> V_58 ,
V_97 ) )
continue;
F_36 ( V_49 , V_8 ,
L_19 ,
V_25 -> V_24 . V_30 ) ;
F_60 ( & V_25 -> V_29 -> V_92 ) ;
F_55 ( V_2 ) ;
F_22 ( V_25 ) ;
}
F_29 ( V_85 ) ;
}
}
static void F_67 ( struct V_8 * V_8 )
{
struct V_12 * V_13 ;
T_4 * V_85 ;
struct V_5 * V_5 ;
struct V_25 * V_25 ;
struct V_1 * V_2 , * V_84 ;
struct V_15 * V_16 ;
T_1 V_75 ;
if ( ! V_8 -> V_26 )
return;
V_13 = V_8 -> V_26 ;
for ( V_75 = 0 ; V_75 < V_13 -> V_19 ; V_75 ++ ) {
V_16 = & V_13 -> V_20 [ V_75 ] ;
V_85 = & V_13 -> V_86 [ V_75 ] ;
F_26 ( V_85 ) ;
F_52 (tt_common_entry, node, node_tmp,
head, hash_entry) {
F_55 ( V_2 ) ;
V_25 = F_2 ( V_5 ,
struct V_25 ,
V_24 ) ;
F_22 ( V_25 ) ;
}
F_29 ( V_85 ) ;
}
F_56 ( V_13 ) ;
V_8 -> V_26 = NULL ;
}
static bool F_68 ( struct V_22 * V_22 ,
struct V_25 * V_25 )
{
bool V_76 = false ;
if ( V_22 -> V_24 . V_31 & V_52 &&
V_25 -> V_24 . V_31 & V_52 )
V_76 = true ;
return V_76 ;
}
struct V_29 * F_69 ( struct V_8 * V_8 ,
const T_2 * V_98 , const T_2 * V_30 )
{
struct V_22 * V_22 = NULL ;
struct V_25 * V_25 = NULL ;
struct V_29 * V_29 = NULL ;
if ( V_98 && F_37 ( & V_8 -> V_99 ) ) {
V_22 = F_14 ( V_8 , V_98 ) ;
if ( ! V_22 )
goto V_48;
}
V_25 = F_15 ( V_8 , V_30 ) ;
if ( ! V_25 )
goto V_48;
if ( V_22 && F_68 ( V_22 , V_25 ) )
goto V_48;
if ( ! F_12 ( & V_25 -> V_29 -> V_21 ) )
goto V_48;
V_29 = V_25 -> V_29 ;
V_48:
if ( V_25 )
F_22 ( V_25 ) ;
if ( V_22 )
F_16 ( V_22 ) ;
return V_29 ;
}
T_3 F_70 ( struct V_8 * V_8 , struct V_29 * V_29 )
{
T_3 V_100 = 0 , V_101 ;
struct V_12 * V_13 = V_8 -> V_26 ;
struct V_5 * V_5 ;
struct V_25 * V_25 ;
struct V_1 * V_2 ;
struct V_15 * V_16 ;
T_1 V_75 ;
int V_102 ;
for ( V_75 = 0 ; V_75 < V_13 -> V_19 ; V_75 ++ ) {
V_16 = & V_13 -> V_20 [ V_75 ] ;
F_9 () ;
F_10 (tt_common_entry, node,
head, hash_entry) {
V_25 = F_2 ( V_5 ,
struct V_25 ,
V_24 ) ;
if ( F_11 ( V_25 -> V_29 ,
V_29 ) ) {
if ( V_5 -> V_31 & V_57 )
continue;
V_101 = 0 ;
for ( V_102 = 0 ; V_102 < V_7 ; V_102 ++ )
V_101 = F_71 ( V_101 ,
V_5 -> V_30 [ V_102 ] ) ;
V_100 ^= V_101 ;
}
}
F_13 () ;
}
return V_100 ;
}
T_3 F_72 ( struct V_8 * V_8 )
{
T_3 V_100 = 0 , V_101 ;
struct V_12 * V_13 = V_8 -> V_23 ;
struct V_5 * V_5 ;
struct V_1 * V_2 ;
struct V_15 * V_16 ;
T_1 V_75 ;
int V_102 ;
for ( V_75 = 0 ; V_75 < V_13 -> V_19 ; V_75 ++ ) {
V_16 = & V_13 -> V_20 [ V_75 ] ;
F_9 () ;
F_10 (tt_common_entry, node,
head, hash_entry) {
if ( V_5 -> V_31 & V_55 )
continue;
V_101 = 0 ;
for ( V_102 = 0 ; V_102 < V_7 ; V_102 ++ )
V_101 = F_71 ( V_101 ,
V_5 -> V_30 [ V_102 ] ) ;
V_100 ^= V_101 ;
}
F_13 () ;
}
return V_100 ;
}
static void F_73 ( struct V_8 * V_8 )
{
struct V_103 * V_2 , * V_64 ;
F_26 ( & V_8 -> V_104 ) ;
F_43 (node, safe, &bat_priv->tt_req_list, list) {
F_44 ( & V_2 -> V_36 ) ;
F_21 ( V_2 ) ;
}
F_29 ( & V_8 -> V_104 ) ;
}
void F_74 ( struct V_8 * V_8 , struct V_29 * V_29 ,
const unsigned char * V_66 , T_2 V_105 )
{
T_3 V_67 = F_31 ( V_105 ) ;
F_26 ( & V_29 -> V_65 ) ;
if ( V_67 > 0 ) {
F_21 ( V_29 -> V_66 ) ;
V_29 -> V_67 = 0 ;
V_29 -> V_66 = F_25 ( V_67 , V_33 ) ;
if ( V_29 -> V_66 ) {
memcpy ( V_29 -> V_66 , V_66 , V_67 ) ;
V_29 -> V_67 = V_67 ;
}
}
F_29 ( & V_29 -> V_65 ) ;
}
static void F_75 ( struct V_8 * V_8 )
{
struct V_103 * V_2 , * V_64 ;
F_26 ( & V_8 -> V_104 ) ;
F_43 (node, safe, &bat_priv->tt_req_list, list) {
if ( F_53 ( V_2 -> V_106 , V_107 ) ) {
F_44 ( & V_2 -> V_36 ) ;
F_21 ( V_2 ) ;
}
}
F_29 ( & V_8 -> V_104 ) ;
}
static struct V_103 * F_76 ( struct V_8 * V_8 ,
struct V_29 * V_29 )
{
struct V_103 * V_108 , * V_103 = NULL ;
F_26 ( & V_8 -> V_104 ) ;
F_77 (tt_req_node_tmp, &bat_priv->tt_req_list, list) {
if ( F_11 ( V_108 , V_29 ) &&
! F_53 ( V_108 -> V_106 ,
V_107 ) )
goto V_109;
}
V_103 = F_25 ( sizeof( * V_103 ) , V_33 ) ;
if ( ! V_103 )
goto V_109;
memcpy ( V_103 -> V_30 , V_29 -> V_93 , V_7 ) ;
V_103 -> V_106 = V_47 ;
F_78 ( & V_103 -> V_36 , & V_8 -> V_110 ) ;
V_109:
F_29 ( & V_8 -> V_104 ) ;
return V_103 ;
}
static int F_79 ( const void * V_111 , const void * V_112 )
{
const struct V_5 * V_5 = V_111 ;
if ( V_5 -> V_31 & V_55 )
return 0 ;
return 1 ;
}
static int F_80 ( const void * V_111 , const void * V_112 )
{
const struct V_5 * V_5 = V_111 ;
const struct V_25 * V_25 ;
const struct V_29 * V_29 = V_112 ;
if ( V_5 -> V_31 & V_57 )
return 0 ;
V_25 = F_2 ( V_5 , struct V_25 ,
V_24 ) ;
return ( V_25 -> V_29 == V_29 ) ;
}
static struct V_113 * F_81 ( T_3 F_31 , T_2 V_50 ,
struct V_12 * V_13 ,
struct V_73 * V_74 ,
int (* F_82)( const void * ,
const void * ) ,
void * V_114 )
{
struct V_5 * V_5 ;
struct V_115 * V_116 ;
struct V_41 * V_41 ;
struct V_1 * V_2 ;
struct V_15 * V_16 ;
struct V_113 * V_117 = NULL ;
T_3 V_118 , V_119 ;
T_5 V_120 = sizeof( struct V_115 ) ;
T_1 V_75 ;
if ( V_120 + F_31 > V_74 -> V_43 -> V_121 ) {
F_31 = V_74 -> V_43 -> V_121 - V_120 ;
F_31 -= F_31 % sizeof( struct V_41 ) ;
}
V_118 = F_31 / sizeof( struct V_41 ) ;
V_117 = F_83 ( V_120 + F_31 + V_122 ) ;
if ( ! V_117 )
goto V_48;
F_84 ( V_117 , V_122 ) ;
V_116 = (struct V_115 * ) F_85 ( V_117 ,
V_120 + F_31 ) ;
V_116 -> V_50 = V_50 ;
V_41 = (struct V_41 * ) ( V_117 -> V_14 + V_120 ) ;
V_119 = 0 ;
F_9 () ;
for ( V_75 = 0 ; V_75 < V_13 -> V_19 ; V_75 ++ ) {
V_16 = & V_13 -> V_20 [ V_75 ] ;
F_10 (tt_common_entry, node,
head, hash_entry) {
if ( V_119 == V_118 )
break;
if ( ( F_82 ) && ( ! F_82 ( V_5 , V_114 ) ) )
continue;
memcpy ( V_41 -> V_30 , V_5 -> V_30 ,
V_7 ) ;
V_41 -> V_31 = V_51 ;
V_119 ++ ;
V_41 ++ ;
}
}
F_13 () ;
V_116 -> V_123 = F_86 ( V_119 ) ;
V_48:
return V_117 ;
}
static int F_87 ( struct V_8 * V_8 ,
struct V_29 * V_124 ,
T_2 V_50 , T_3 V_125 , bool V_126 )
{
struct V_113 * V_117 = NULL ;
struct V_115 * V_127 ;
struct V_128 * V_128 = NULL ;
struct V_73 * V_74 ;
struct V_103 * V_103 = NULL ;
int V_76 = 1 ;
V_74 = F_46 ( V_8 ) ;
if ( ! V_74 )
goto V_48;
V_103 = F_76 ( V_8 , V_124 ) ;
if ( ! V_103 )
goto V_48;
V_117 = F_83 ( sizeof( struct V_115 ) + V_122 ) ;
if ( ! V_117 )
goto V_48;
F_84 ( V_117 , V_122 ) ;
V_127 = (struct V_115 * ) F_85 ( V_117 ,
sizeof( struct V_115 ) ) ;
V_127 -> V_129 . V_130 = V_131 ;
V_127 -> V_129 . V_132 = V_133 ;
memcpy ( V_127 -> V_98 , V_74 -> V_71 -> V_53 , V_7 ) ;
memcpy ( V_127 -> V_134 , V_124 -> V_93 , V_7 ) ;
V_127 -> V_129 . V_135 = V_136 ;
V_127 -> V_50 = V_50 ;
V_127 -> V_123 = V_125 ;
V_127 -> V_31 = V_137 ;
if ( V_126 )
V_127 -> V_31 |= V_138 ;
V_128 = F_88 ( V_124 ) ;
if ( ! V_128 )
goto V_48;
F_36 ( V_49 , V_8 ,
L_20 ,
V_124 -> V_93 , V_128 -> V_30 ,
( V_126 ? 'F' : '.' ) ) ;
F_89 ( V_117 , V_128 -> V_139 , V_128 -> V_30 ) ;
V_76 = 0 ;
V_48:
if ( V_128 )
F_90 ( V_128 ) ;
if ( V_74 )
F_48 ( V_74 ) ;
if ( V_76 )
F_91 ( V_117 ) ;
if ( V_76 && V_103 ) {
F_26 ( & V_8 -> V_104 ) ;
F_44 ( & V_103 -> V_36 ) ;
F_29 ( & V_8 -> V_104 ) ;
F_21 ( V_103 ) ;
}
return V_76 ;
}
static bool F_92 ( struct V_8 * V_8 ,
struct V_115 * V_127 )
{
struct V_29 * V_140 = NULL , * V_141 = NULL ;
struct V_128 * V_128 = NULL ;
struct V_73 * V_74 = NULL ;
T_2 V_142 , V_143 , V_50 ;
int V_76 = false ;
unsigned char * V_66 ;
bool V_126 ;
T_3 F_31 , V_118 ;
struct V_113 * V_117 = NULL ;
struct V_115 * V_116 ;
F_36 ( V_49 , V_8 ,
L_21 ,
V_127 -> V_98 , V_127 -> V_50 , V_127 -> V_134 ,
( V_127 -> V_31 & V_138 ? 'F' : '.' ) ) ;
V_140 = F_93 ( V_8 , V_127 -> V_134 ) ;
if ( ! V_140 )
goto V_48;
V_141 = F_93 ( V_8 , V_127 -> V_98 ) ;
if ( ! V_141 )
goto V_48;
V_128 = F_88 ( V_141 ) ;
if ( ! V_128 )
goto V_48;
V_74 = F_46 ( V_8 ) ;
if ( ! V_74 )
goto V_48;
V_142 = ( T_2 ) F_37 ( & V_140 -> V_94 ) ;
V_143 = V_127 -> V_50 ;
if ( V_142 != V_143 ||
V_127 -> V_123 != V_140 -> V_125 )
goto V_48;
if ( V_127 -> V_31 & V_138 ||
! V_140 -> V_66 )
V_126 = true ;
else
V_126 = false ;
if ( ! V_126 ) {
F_26 ( & V_140 -> V_65 ) ;
F_31 = V_140 -> V_67 ;
V_118 = F_31 / sizeof( struct V_41 ) ;
V_117 = F_83 ( sizeof( struct V_115 ) +
F_31 + V_122 ) ;
if ( ! V_117 )
goto V_109;
F_84 ( V_117 , V_122 ) ;
V_116 = (struct V_115 * ) F_85 ( V_117 ,
sizeof( struct V_115 ) + F_31 ) ;
V_116 -> V_50 = V_143 ;
V_116 -> V_123 = F_86 ( V_118 ) ;
V_66 = V_117 -> V_14 + sizeof( struct V_115 ) ;
memcpy ( V_66 , V_140 -> V_66 ,
V_140 -> V_67 ) ;
F_29 ( & V_140 -> V_65 ) ;
} else {
F_31 = ( T_3 ) F_37 ( & V_140 -> V_92 ) *
sizeof( struct V_41 ) ;
V_50 = ( T_2 ) F_37 ( & V_140 -> V_94 ) ;
V_117 = F_81 ( F_31 , V_50 ,
V_8 -> V_26 ,
V_74 , F_80 ,
V_140 ) ;
if ( ! V_117 )
goto V_48;
V_116 = (struct V_115 * ) V_117 -> V_14 ;
}
V_116 -> V_129 . V_130 = V_131 ;
V_116 -> V_129 . V_132 = V_133 ;
V_116 -> V_129 . V_135 = V_136 ;
memcpy ( V_116 -> V_98 , V_140 -> V_93 , V_7 ) ;
memcpy ( V_116 -> V_134 , V_127 -> V_98 , V_7 ) ;
V_116 -> V_31 = V_144 ;
if ( V_126 )
V_116 -> V_31 |= V_138 ;
F_36 ( V_49 , V_8 ,
L_22 ,
V_141 -> V_93 , V_128 -> V_30 ,
V_140 -> V_93 , V_143 ) ;
F_89 ( V_117 , V_128 -> V_139 , V_128 -> V_30 ) ;
V_76 = true ;
goto V_48;
V_109:
F_29 ( & V_140 -> V_65 ) ;
V_48:
if ( V_141 )
F_20 ( V_141 ) ;
if ( V_140 )
F_20 ( V_140 ) ;
if ( V_128 )
F_90 ( V_128 ) ;
if ( V_74 )
F_48 ( V_74 ) ;
if ( ! V_76 )
F_91 ( V_117 ) ;
return V_76 ;
}
static bool F_94 ( struct V_8 * V_8 ,
struct V_115 * V_127 )
{
struct V_29 * V_29 = NULL ;
struct V_128 * V_128 = NULL ;
struct V_73 * V_74 = NULL ;
T_2 V_145 , V_143 , V_50 ;
int V_76 = false ;
unsigned char * V_66 ;
bool V_126 ;
T_3 F_31 , V_118 ;
struct V_113 * V_117 = NULL ;
struct V_115 * V_116 ;
F_36 ( V_49 , V_8 ,
L_23 ,
V_127 -> V_98 , V_127 -> V_50 ,
( V_127 -> V_31 & V_138 ? 'F' : '.' ) ) ;
V_145 = ( T_2 ) F_37 ( & V_8 -> V_50 ) ;
V_143 = V_127 -> V_50 ;
V_29 = F_93 ( V_8 , V_127 -> V_98 ) ;
if ( ! V_29 )
goto V_48;
V_128 = F_88 ( V_29 ) ;
if ( ! V_128 )
goto V_48;
V_74 = F_46 ( V_8 ) ;
if ( ! V_74 )
goto V_48;
if ( V_127 -> V_31 & V_138 || V_145 != V_143 ||
! V_8 -> V_66 )
V_126 = true ;
else
V_126 = false ;
if ( ! V_126 ) {
F_26 ( & V_8 -> V_65 ) ;
F_31 = V_8 -> V_67 ;
V_118 = F_31 / sizeof( struct V_41 ) ;
V_117 = F_83 ( sizeof( struct V_115 ) +
F_31 + V_122 ) ;
if ( ! V_117 )
goto V_109;
F_84 ( V_117 , V_122 ) ;
V_116 = (struct V_115 * ) F_85 ( V_117 ,
sizeof( struct V_115 ) + F_31 ) ;
V_116 -> V_50 = V_143 ;
V_116 -> V_123 = F_86 ( V_118 ) ;
V_66 = V_117 -> V_14 + sizeof( struct V_115 ) ;
memcpy ( V_66 , V_8 -> V_66 ,
V_8 -> V_67 ) ;
F_29 ( & V_8 -> V_65 ) ;
} else {
F_31 = ( T_3 ) F_37 ( & V_8 -> V_146 ) *
sizeof( struct V_41 ) ;
V_50 = ( T_2 ) F_37 ( & V_8 -> V_50 ) ;
V_117 = F_81 ( F_31 , V_50 ,
V_8 -> V_23 ,
V_74 , F_79 ,
NULL ) ;
if ( ! V_117 )
goto V_48;
V_116 = (struct V_115 * ) V_117 -> V_14 ;
}
V_116 -> V_129 . V_130 = V_131 ;
V_116 -> V_129 . V_132 = V_133 ;
V_116 -> V_129 . V_135 = V_136 ;
memcpy ( V_116 -> V_98 , V_74 -> V_71 -> V_53 , V_7 ) ;
memcpy ( V_116 -> V_134 , V_127 -> V_98 , V_7 ) ;
V_116 -> V_31 = V_144 ;
if ( V_126 )
V_116 -> V_31 |= V_138 ;
F_36 ( V_49 , V_8 ,
L_24 ,
V_29 -> V_93 , V_128 -> V_30 ,
( V_116 -> V_31 & V_138 ? 'F' : '.' ) ) ;
F_89 ( V_117 , V_128 -> V_139 , V_128 -> V_30 ) ;
V_76 = true ;
goto V_48;
V_109:
F_29 ( & V_8 -> V_65 ) ;
V_48:
if ( V_29 )
F_20 ( V_29 ) ;
if ( V_128 )
F_90 ( V_128 ) ;
if ( V_74 )
F_48 ( V_74 ) ;
if ( ! V_76 )
F_91 ( V_117 ) ;
return true ;
}
bool F_95 ( struct V_8 * V_8 ,
struct V_115 * V_127 )
{
if ( F_96 ( V_127 -> V_134 ) )
return F_94 ( V_8 , V_127 ) ;
else
return F_92 ( V_8 , V_127 ) ;
}
static void F_97 ( struct V_8 * V_8 ,
struct V_29 * V_29 ,
struct V_41 * V_41 ,
T_3 V_105 , T_2 V_50 )
{
int V_75 ;
for ( V_75 = 0 ; V_75 < V_105 ; V_75 ++ ) {
if ( ( V_41 + V_75 ) -> V_31 & V_83 )
F_64 ( V_8 , V_29 ,
( V_41 + V_75 ) -> V_30 ,
L_25 ,
( V_41 + V_75 ) -> V_31 & V_57 ) ;
else
if ( ! F_59 ( V_8 , V_29 ,
( V_41 + V_75 ) -> V_30 , V_50 , false ,
( V_41 + V_75 ) -> V_31 &
V_52 ) )
return;
}
V_29 -> V_96 = true ;
}
static void F_98 ( struct V_8 * V_8 ,
struct V_115 * V_116 )
{
struct V_29 * V_29 = NULL ;
V_29 = F_93 ( V_8 , V_116 -> V_98 ) ;
if ( ! V_29 )
goto V_48;
F_65 ( V_8 , V_29 , L_26 ) ;
F_97 ( V_8 , V_29 ,
(struct V_41 * ) ( V_116 + 1 ) ,
V_116 -> V_123 , V_116 -> V_50 ) ;
F_26 ( & V_29 -> V_65 ) ;
F_21 ( V_29 -> V_66 ) ;
V_29 -> V_67 = 0 ;
V_29 -> V_66 = NULL ;
F_29 ( & V_29 -> V_65 ) ;
F_30 ( & V_29 -> V_94 , V_116 -> V_50 ) ;
V_48:
if ( V_29 )
F_20 ( V_29 ) ;
}
static void F_99 ( struct V_8 * V_8 ,
struct V_29 * V_29 ,
T_3 V_105 , T_2 V_50 ,
struct V_41 * V_41 )
{
F_97 ( V_8 , V_29 , V_41 , V_105 ,
V_50 ) ;
F_74 ( V_8 , V_29 , ( unsigned char * ) V_41 ,
V_105 ) ;
F_30 ( & V_29 -> V_94 , V_50 ) ;
}
bool F_100 ( struct V_8 * V_8 , const T_2 * V_30 )
{
struct V_22 * V_22 = NULL ;
bool V_76 = false ;
V_22 = F_14 ( V_8 , V_30 ) ;
if ( ! V_22 )
goto V_48;
if ( V_22 -> V_24 . V_31 & V_80 )
goto V_48;
V_76 = true ;
V_48:
if ( V_22 )
F_16 ( V_22 ) ;
return V_76 ;
}
void F_101 ( struct V_8 * V_8 ,
struct V_115 * V_116 )
{
struct V_103 * V_2 , * V_64 ;
struct V_29 * V_29 = NULL ;
F_36 ( V_49 , V_8 ,
L_27 ,
V_116 -> V_98 , V_116 -> V_50 , V_116 -> V_123 ,
( V_116 -> V_31 & V_138 ? 'F' : '.' ) ) ;
V_29 = F_93 ( V_8 , V_116 -> V_98 ) ;
if ( ! V_29 )
goto V_48;
if ( V_116 -> V_31 & V_138 )
F_98 ( V_8 , V_116 ) ;
else
F_99 ( V_8 , V_29 , V_116 -> V_123 ,
V_116 -> V_50 ,
(struct V_41 * ) ( V_116 + 1 ) ) ;
F_26 ( & V_8 -> V_104 ) ;
F_43 (node, safe, &bat_priv->tt_req_list, list) {
if ( ! F_11 ( V_2 -> V_30 , V_116 -> V_98 ) )
continue;
F_44 ( & V_2 -> V_36 ) ;
F_21 ( V_2 ) ;
}
F_29 ( & V_8 -> V_104 ) ;
V_29 -> V_125 = F_70 ( V_8 , V_29 ) ;
V_29 -> V_56 = false ;
V_48:
if ( V_29 )
F_20 ( V_29 ) ;
}
int F_102 ( struct V_8 * V_8 )
{
if ( ! F_32 ( V_8 ) )
return 0 ;
if ( ! F_57 ( V_8 ) )
return 0 ;
F_3 ( V_8 ) ;
return 1 ;
}
static void F_103 ( struct V_8 * V_8 )
{
struct V_147 * V_2 , * V_64 ;
F_26 ( & V_8 -> V_148 ) ;
F_43 (node, safe, &bat_priv->tt_roam_list, list) {
F_44 ( & V_2 -> V_36 ) ;
F_21 ( V_2 ) ;
}
F_29 ( & V_8 -> V_148 ) ;
}
static void F_104 ( struct V_8 * V_8 )
{
struct V_147 * V_2 , * V_64 ;
F_26 ( & V_8 -> V_148 ) ;
F_43 (node, safe, &bat_priv->tt_roam_list, list) {
if ( ! F_53 ( V_2 -> V_149 , V_150 ) )
continue;
F_44 ( & V_2 -> V_36 ) ;
F_21 ( V_2 ) ;
}
F_29 ( & V_8 -> V_148 ) ;
}
static bool F_105 ( struct V_8 * V_8 ,
T_2 * V_151 )
{
struct V_147 * V_147 ;
bool V_76 = false ;
F_26 ( & V_8 -> V_148 ) ;
F_77 (tt_roam_node, &bat_priv->tt_roam_list, list) {
if ( ! F_11 ( V_147 -> V_30 , V_151 ) )
continue;
if ( F_53 ( V_147 -> V_149 , V_150 ) )
continue;
if ( ! F_106 ( & V_147 -> V_152 ) )
goto V_109;
V_76 = true ;
break;
}
if ( ! V_76 ) {
V_147 = F_25 ( sizeof( * V_147 ) , V_33 ) ;
if ( ! V_147 )
goto V_109;
V_147 -> V_149 = V_47 ;
F_30 ( & V_147 -> V_152 , V_153 - 1 ) ;
memcpy ( V_147 -> V_30 , V_151 , V_7 ) ;
F_78 ( & V_147 -> V_36 , & V_8 -> V_154 ) ;
V_76 = true ;
}
V_109:
F_29 ( & V_8 -> V_148 ) ;
return V_76 ;
}
void F_41 ( struct V_8 * V_8 , T_2 * V_151 ,
struct V_29 * V_29 )
{
struct V_128 * V_128 = NULL ;
struct V_113 * V_117 = NULL ;
struct V_155 * V_155 ;
int V_76 = 1 ;
struct V_73 * V_74 ;
if ( ! F_105 ( V_8 , V_151 ) )
goto V_48;
V_117 = F_83 ( sizeof( struct V_155 ) + V_122 ) ;
if ( ! V_117 )
goto V_48;
F_84 ( V_117 , V_122 ) ;
V_155 = (struct V_155 * ) F_85 ( V_117 ,
sizeof( struct V_155 ) ) ;
V_155 -> V_129 . V_130 = V_156 ;
V_155 -> V_129 . V_132 = V_133 ;
V_155 -> V_129 . V_135 = V_136 ;
V_74 = F_46 ( V_8 ) ;
if ( ! V_74 )
goto V_48;
memcpy ( V_155 -> V_98 , V_74 -> V_71 -> V_53 , V_7 ) ;
F_48 ( V_74 ) ;
memcpy ( V_155 -> V_134 , V_29 -> V_93 , V_7 ) ;
memcpy ( V_155 -> V_151 , V_151 , V_7 ) ;
V_128 = F_88 ( V_29 ) ;
if ( ! V_128 )
goto V_48;
F_36 ( V_49 , V_8 ,
L_28 ,
V_29 -> V_93 , V_151 , V_128 -> V_30 ) ;
F_89 ( V_117 , V_128 -> V_139 , V_128 -> V_30 ) ;
V_76 = 0 ;
V_48:
if ( V_128 )
F_90 ( V_128 ) ;
if ( V_76 )
F_91 ( V_117 ) ;
return;
}
static void V_10 ( struct V_157 * V_158 )
{
struct V_159 * V_159 =
F_2 ( V_158 , struct V_159 , V_158 ) ;
struct V_8 * V_8 =
F_2 ( V_159 , struct V_8 , V_9 ) ;
F_51 ( V_8 ) ;
F_66 ( V_8 ) ;
F_75 ( V_8 ) ;
F_104 ( V_8 ) ;
F_3 ( V_8 ) ;
}
void F_107 ( struct V_8 * V_8 )
{
F_108 ( & V_8 -> V_9 ) ;
F_54 ( V_8 ) ;
F_67 ( V_8 ) ;
F_73 ( V_8 ) ;
F_58 ( V_8 ) ;
F_103 ( V_8 ) ;
F_21 ( V_8 -> V_66 ) ;
}
static T_3 F_109 ( struct V_12 * V_13 , T_3 V_31 ,
bool V_160 )
{
T_1 V_75 ;
T_3 V_161 = 0 ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
struct V_5 * V_5 ;
if ( ! V_13 )
goto V_48;
for ( V_75 = 0 ; V_75 < V_13 -> V_19 ; V_75 ++ ) {
V_16 = & V_13 -> V_20 [ V_75 ] ;
F_9 () ;
F_10 (tt_common_entry, node,
head, hash_entry) {
if ( V_160 ) {
if ( ( V_5 -> V_31 & V_31 ) == V_31 )
continue;
V_5 -> V_31 |= V_31 ;
} else {
if ( ! ( V_5 -> V_31 & V_31 ) )
continue;
V_5 -> V_31 &= ~ V_31 ;
}
V_161 ++ ;
}
F_13 () ;
}
V_48:
return V_161 ;
}
static void F_110 ( struct V_8 * V_8 )
{
struct V_12 * V_13 = V_8 -> V_23 ;
struct V_5 * V_5 ;
struct V_22 * V_22 ;
struct V_1 * V_2 , * V_84 ;
struct V_15 * V_16 ;
T_4 * V_85 ;
T_1 V_75 ;
if ( ! V_13 )
return;
for ( V_75 = 0 ; V_75 < V_13 -> V_19 ; V_75 ++ ) {
V_16 = & V_13 -> V_20 [ V_75 ] ;
V_85 = & V_13 -> V_86 [ V_75 ] ;
F_26 ( V_85 ) ;
F_52 (tt_common_entry, node, node_tmp,
head, hash_entry) {
if ( ! ( V_5 -> V_31 & V_80 ) )
continue;
F_36 ( V_49 , V_8 ,
L_29 ,
V_5 -> V_30 ) ;
F_60 ( & V_8 -> V_146 ) ;
F_55 ( V_2 ) ;
V_22 = F_2 ( V_5 ,
struct V_22 ,
V_24 ) ;
F_16 ( V_22 ) ;
}
F_29 ( V_85 ) ;
}
}
void F_111 ( struct V_8 * V_8 )
{
T_3 V_161 = F_109 ( V_8 -> V_23 ,
V_55 , false ) ;
F_112 ( V_161 , & V_8 -> V_146 ) ;
F_110 ( V_8 ) ;
F_28 ( & V_8 -> V_50 ) ;
V_8 -> V_56 = false ;
}
bool F_113 ( struct V_8 * V_8 , T_2 * V_98 , T_2 * V_134 )
{
struct V_22 * V_22 = NULL ;
struct V_25 * V_25 = NULL ;
bool V_76 = true ;
if ( ! F_37 ( & V_8 -> V_99 ) )
return false ;
V_22 = F_14 ( V_8 , V_134 ) ;
if ( ! V_22 )
goto V_48;
V_25 = F_15 ( V_8 , V_98 ) ;
if ( ! V_25 )
goto V_48;
if ( F_68 ( V_22 , V_25 ) )
goto V_48;
V_76 = false ;
V_48:
if ( V_25 )
F_22 ( V_25 ) ;
if ( V_22 )
F_16 ( V_22 ) ;
return V_76 ;
}
void F_114 ( struct V_8 * V_8 , struct V_29 * V_29 ,
const unsigned char * V_66 , T_2 V_105 ,
T_2 V_50 , T_3 V_125 )
{
T_2 V_142 = ( T_2 ) F_37 ( & V_29 -> V_94 ) ;
bool V_126 = true ;
if ( ( ! V_29 -> V_96 && V_50 == 1 ) ||
V_50 - V_142 == 1 ) {
if ( ! V_105 ) {
V_126 = false ;
goto V_162;
}
F_99 ( V_8 , V_29 , V_105 , V_50 ,
(struct V_41 * ) V_66 ) ;
V_29 -> V_125 = F_70 ( V_8 , V_29 ) ;
if ( V_29 -> V_125 != V_125 )
goto V_162;
V_29 -> V_56 = false ;
} else {
if ( ! V_29 -> V_96 || V_50 != V_142 ||
V_29 -> V_125 != V_125 ) {
V_162:
F_36 ( V_49 , V_8 ,
L_30 ,
V_29 -> V_93 , V_50 , V_142 , V_125 ,
V_29 -> V_125 , V_105 ) ;
F_87 ( V_8 , V_29 , V_50 , V_125 ,
V_126 ) ;
return;
}
}
}
