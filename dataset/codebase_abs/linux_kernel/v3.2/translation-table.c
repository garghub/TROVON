static int F_1 ( const struct V_1 * V_2 , const void * V_3 )
{
const void * V_4 = F_2 ( V_2 , struct V_5 ,
V_6 ) ;
return ( memcmp ( V_4 , V_3 , V_7 ) == 0 ? 1 : 0 ) ;
}
static int F_3 ( const struct V_1 * V_2 , const void * V_3 )
{
const void * V_4 = F_2 ( V_2 , struct V_8 ,
V_6 ) ;
return ( memcmp ( V_4 , V_3 , V_7 ) == 0 ? 1 : 0 ) ;
}
static void F_4 ( struct V_9 * V_9 )
{
F_5 ( & V_9 -> V_10 , V_11 ) ;
F_6 ( V_12 , & V_9 -> V_10 ,
F_7 ( 5000 ) ) ;
}
static struct V_5 * F_8 ( struct V_9 * V_9 ,
const void * V_13 )
{
struct V_14 * V_15 = V_9 -> V_16 ;
struct V_17 * V_18 ;
struct V_1 * V_2 ;
struct V_5 * V_5 , * V_19 = NULL ;
int V_20 ;
if ( ! V_15 )
return NULL ;
V_20 = F_9 ( V_13 , V_15 -> V_21 ) ;
V_18 = & V_15 -> V_22 [ V_20 ] ;
F_10 () ;
F_11 (tt_local_entry, node, head, hash_entry) {
if ( ! F_12 ( V_5 , V_13 ) )
continue;
if ( ! F_13 ( & V_5 -> V_23 ) )
continue;
V_19 = V_5 ;
break;
}
F_14 () ;
return V_19 ;
}
static struct V_8 * F_15 ( struct V_9 * V_9 ,
const void * V_13 )
{
struct V_14 * V_15 = V_9 -> V_24 ;
struct V_17 * V_18 ;
struct V_1 * V_2 ;
struct V_8 * V_8 ;
struct V_8 * V_25 = NULL ;
int V_20 ;
if ( ! V_15 )
return NULL ;
V_20 = F_9 ( V_13 , V_15 -> V_21 ) ;
V_18 = & V_15 -> V_22 [ V_20 ] ;
F_10 () ;
F_11 (tt_global_entry, node, head, hash_entry) {
if ( ! F_12 ( V_8 , V_13 ) )
continue;
if ( ! F_13 ( & V_8 -> V_23 ) )
continue;
V_25 = V_8 ;
break;
}
F_14 () ;
return V_25 ;
}
static bool F_16 ( unsigned long V_26 , unsigned long V_27 )
{
unsigned long V_28 ;
V_28 = V_26 + F_7 ( V_27 ) ;
return F_17 ( V_29 , V_28 ) ;
}
static void F_18 ( struct V_5 * V_5 )
{
if ( F_19 ( & V_5 -> V_23 ) )
F_20 ( V_5 , V_30 ) ;
}
static void F_21 ( struct V_31 * V_30 )
{
struct V_8 * V_8 ;
V_8 = F_2 ( V_30 , struct V_8 , V_30 ) ;
if ( V_8 -> V_32 )
F_22 ( V_8 -> V_32 ) ;
F_23 ( V_8 ) ;
}
static void F_24 ( struct V_8 * V_8 )
{
if ( F_19 ( & V_8 -> V_23 ) )
F_25 ( & V_8 -> V_30 , F_21 ) ;
}
static void F_26 ( struct V_9 * V_9 , const T_1 * V_33 ,
T_1 V_34 )
{
struct V_35 * V_35 ;
V_35 = F_27 ( sizeof( * V_35 ) , V_36 ) ;
if ( ! V_35 )
return;
V_35 -> V_37 . V_34 = V_34 ;
memcpy ( V_35 -> V_37 . V_33 , V_33 , V_7 ) ;
F_28 ( & V_9 -> V_38 ) ;
F_29 ( & V_35 -> V_39 , & V_9 -> V_40 ) ;
F_30 ( & V_9 -> V_41 ) ;
F_31 ( & V_9 -> V_38 ) ;
F_32 ( & V_9 -> V_42 , 0 ) ;
}
int F_33 ( int V_43 )
{
return V_43 * sizeof( struct V_44 ) ;
}
static int F_34 ( struct V_9 * V_9 )
{
if ( V_9 -> V_16 )
return 1 ;
V_9 -> V_16 = F_35 ( 1024 ) ;
if ( ! V_9 -> V_16 )
return 0 ;
return 1 ;
}
void F_36 ( struct V_45 * V_46 , const T_1 * V_33 ,
int V_47 )
{
struct V_9 * V_9 = F_37 ( V_46 ) ;
struct V_5 * V_5 = NULL ;
struct V_8 * V_8 = NULL ;
V_5 = F_8 ( V_9 , V_33 ) ;
if ( V_5 ) {
V_5 -> V_48 = V_29 ;
goto V_49;
}
V_5 = F_27 ( sizeof( * V_5 ) , V_36 ) ;
if ( ! V_5 )
goto V_49;
F_38 ( V_50 , V_9 ,
L_1 , V_33 ,
( T_1 ) F_39 ( & V_9 -> V_51 ) ) ;
memcpy ( V_5 -> V_33 , V_33 , V_7 ) ;
V_5 -> V_48 = V_29 ;
V_5 -> V_34 = V_52 ;
if ( F_40 ( V_47 ) )
V_5 -> V_34 |= V_53 ;
F_32 ( & V_5 -> V_23 , 2 ) ;
if ( F_12 ( V_33 , V_46 -> V_54 ) )
V_5 -> V_34 |= V_55 ;
F_26 ( V_9 , V_33 , V_5 -> V_34 ) ;
V_5 -> V_34 |= V_56 ;
F_41 ( V_9 -> V_16 , F_1 , F_9 ,
V_5 , & V_5 -> V_6 ) ;
V_8 = F_15 ( V_9 , V_33 ) ;
if ( V_8 ) {
V_8 -> V_32 -> V_57 = true ;
V_8 -> V_34 |= V_58 ;
V_8 -> V_59 = V_29 ;
F_42 ( V_9 , V_8 -> V_33 ,
V_8 -> V_32 ) ;
}
V_49:
if ( V_5 )
F_18 ( V_5 ) ;
if ( V_8 )
F_24 ( V_8 ) ;
}
int F_43 ( struct V_9 * V_9 ,
unsigned char * V_60 , int V_61 )
{
int V_62 = 0 , V_63 = 0 ;
struct V_35 * V_64 , * V_65 ;
if ( V_61 > 0 )
V_63 = V_61 / F_33 ( 1 ) ;
F_28 ( & V_9 -> V_38 ) ;
F_32 ( & V_9 -> V_41 , 0 ) ;
F_44 (entry, safe, &bat_priv->tt_changes_list,
list) {
if ( V_62 < V_63 ) {
memcpy ( V_60 + F_33 ( V_62 ) ,
& V_64 -> V_37 , sizeof( struct V_44 ) ) ;
V_62 ++ ;
}
F_45 ( & V_64 -> V_39 ) ;
F_23 ( V_64 ) ;
}
F_31 ( & V_9 -> V_38 ) ;
F_28 ( & V_9 -> V_66 ) ;
F_23 ( V_9 -> V_67 ) ;
V_9 -> V_68 = 0 ;
V_9 -> V_67 = NULL ;
if ( V_61 > 0 ) {
V_9 -> V_67 = F_27 ( V_61 , V_36 ) ;
if ( V_9 -> V_67 ) {
memcpy ( V_9 -> V_67 , V_60 , V_61 ) ;
V_9 -> V_68 = V_61 ;
}
}
F_31 ( & V_9 -> V_66 ) ;
return V_63 ;
}
int F_46 ( struct V_69 * V_70 , void * V_71 )
{
struct V_45 * V_72 = (struct V_45 * ) V_70 -> V_73 ;
struct V_9 * V_9 = F_37 ( V_72 ) ;
struct V_14 * V_15 = V_9 -> V_16 ;
struct V_5 * V_5 ;
struct V_74 * V_75 ;
struct V_1 * V_2 ;
struct V_17 * V_18 ;
T_2 V_76 , V_77 ;
char * V_60 ;
int V_78 , V_79 = 0 ;
V_75 = F_47 ( V_9 ) ;
if ( ! V_75 ) {
V_79 = F_48 ( V_70 , L_2
L_3 ,
V_72 -> V_80 ) ;
goto V_49;
}
if ( V_75 -> V_81 != V_82 ) {
V_79 = F_48 ( V_70 , L_2
L_4 ,
V_72 -> V_80 ) ;
goto V_49;
}
F_48 ( V_70 , L_5
L_6 ,
V_72 -> V_80 , ( T_1 ) F_39 ( & V_9 -> V_51 ) ) ;
V_76 = 1 ;
for ( V_78 = 0 ; V_78 < V_15 -> V_21 ; V_78 ++ ) {
V_18 = & V_15 -> V_22 [ V_78 ] ;
F_10 () ;
F_49 (node, head)
V_76 += 29 ;
F_14 () ;
}
V_60 = F_27 ( V_76 , V_36 ) ;
if ( ! V_60 ) {
V_79 = - V_83 ;
goto V_49;
}
V_60 [ 0 ] = '\0' ;
V_77 = 0 ;
for ( V_78 = 0 ; V_78 < V_15 -> V_21 ; V_78 ++ ) {
V_18 = & V_15 -> V_22 [ V_78 ] ;
F_10 () ;
F_11 (tt_local_entry, node,
head, hash_entry) {
V_77 += snprintf ( V_60 + V_77 , 30 , L_7
L_8 ,
V_5 -> V_33 ,
( V_5 -> V_34 &
V_58 ? 'R' : '.' ) ,
( V_5 -> V_34 &
V_55 ? 'P' : '.' ) ,
( V_5 -> V_34 &
V_56 ? 'N' : '.' ) ,
( V_5 -> V_34 &
V_84 ? 'X' : '.' ) ,
( V_5 -> V_34 &
V_53 ? 'W' : '.' ) ) ;
}
F_14 () ;
}
F_48 ( V_70 , L_9 , V_60 ) ;
F_23 ( V_60 ) ;
V_49:
if ( V_75 )
F_50 ( V_75 ) ;
return V_79 ;
}
static void F_51 ( struct V_9 * V_9 ,
struct V_5 * V_5 ,
T_3 V_34 )
{
F_26 ( V_9 , V_5 -> V_33 ,
V_5 -> V_34 | V_34 ) ;
V_5 -> V_34 |= V_84 ;
}
void F_52 ( struct V_9 * V_9 , const T_1 * V_33 ,
const char * V_85 , bool V_86 )
{
struct V_5 * V_5 = NULL ;
V_5 = F_8 ( V_9 , V_33 ) ;
if ( ! V_5 )
goto V_49;
F_51 ( V_9 , V_5 , V_87 |
( V_86 ? V_58 : V_52 ) ) ;
F_38 ( V_50 , V_9 , L_10
L_11 , V_5 -> V_33 , V_85 ) ;
V_49:
if ( V_5 )
F_18 ( V_5 ) ;
}
static void F_53 ( struct V_9 * V_9 )
{
struct V_14 * V_15 = V_9 -> V_16 ;
struct V_5 * V_5 ;
struct V_1 * V_2 , * V_88 ;
struct V_17 * V_18 ;
T_4 * V_89 ;
int V_78 ;
for ( V_78 = 0 ; V_78 < V_15 -> V_21 ; V_78 ++ ) {
V_18 = & V_15 -> V_22 [ V_78 ] ;
V_89 = & V_15 -> V_90 [ V_78 ] ;
F_28 ( V_89 ) ;
F_54 (tt_local_entry, node, node_tmp,
head, hash_entry) {
if ( V_5 -> V_34 & V_55 )
continue;
if ( V_5 -> V_34 & V_84 )
continue;
if ( ! F_16 ( V_5 -> V_48 ,
V_91 * 1000 ) )
continue;
F_51 ( V_9 , V_5 ,
V_87 ) ;
F_38 ( V_50 , V_9 , L_12
L_13 ,
V_5 -> V_33 ) ;
}
F_31 ( V_89 ) ;
}
}
static void F_55 ( struct V_9 * V_9 )
{
struct V_14 * V_15 ;
T_4 * V_89 ;
struct V_5 * V_5 ;
struct V_1 * V_2 , * V_88 ;
struct V_17 * V_18 ;
int V_78 ;
if ( ! V_9 -> V_16 )
return;
V_15 = V_9 -> V_16 ;
for ( V_78 = 0 ; V_78 < V_15 -> V_21 ; V_78 ++ ) {
V_18 = & V_15 -> V_22 [ V_78 ] ;
V_89 = & V_15 -> V_90 [ V_78 ] ;
F_28 ( V_89 ) ;
F_54 (tt_local_entry, node, node_tmp,
head, hash_entry) {
F_56 ( V_2 ) ;
F_18 ( V_5 ) ;
}
F_31 ( V_89 ) ;
}
F_57 ( V_15 ) ;
V_9 -> V_16 = NULL ;
}
static int F_58 ( struct V_9 * V_9 )
{
if ( V_9 -> V_24 )
return 1 ;
V_9 -> V_24 = F_35 ( 1024 ) ;
if ( ! V_9 -> V_24 )
return 0 ;
return 1 ;
}
static void F_59 ( struct V_9 * V_9 )
{
struct V_35 * V_64 , * V_65 ;
F_28 ( & V_9 -> V_38 ) ;
F_44 (entry, safe, &bat_priv->tt_changes_list,
list) {
F_45 ( & V_64 -> V_39 ) ;
F_23 ( V_64 ) ;
}
F_32 ( & V_9 -> V_41 , 0 ) ;
F_31 ( & V_9 -> V_38 ) ;
}
int F_60 ( struct V_9 * V_9 , struct V_32 * V_32 ,
const unsigned char * V_92 , T_1 V_51 , bool V_86 ,
bool V_93 )
{
struct V_8 * V_8 ;
struct V_32 * V_94 ;
int V_79 = 0 ;
V_8 = F_15 ( V_9 , V_92 ) ;
if ( ! V_8 ) {
V_8 =
F_27 ( sizeof( * V_8 ) ,
V_36 ) ;
if ( ! V_8 )
goto V_49;
memcpy ( V_8 -> V_33 , V_92 , V_7 ) ;
F_30 ( & V_32 -> V_23 ) ;
V_8 -> V_32 = V_32 ;
V_8 -> V_51 = V_51 ;
V_8 -> V_34 = V_52 ;
V_8 -> V_59 = 0 ;
F_32 ( & V_8 -> V_23 , 2 ) ;
F_41 ( V_9 -> V_24 , F_3 ,
F_9 , V_8 ,
& V_8 -> V_6 ) ;
F_30 ( & V_32 -> V_95 ) ;
} else {
if ( V_8 -> V_32 != V_32 ) {
F_61 ( & V_8 -> V_32 -> V_95 ) ;
V_94 = V_8 -> V_32 ;
F_30 ( & V_32 -> V_23 ) ;
V_8 -> V_32 = V_32 ;
F_22 ( V_94 ) ;
F_30 ( & V_32 -> V_95 ) ;
}
V_8 -> V_51 = V_51 ;
V_8 -> V_34 = V_52 ;
V_8 -> V_59 = 0 ;
}
if ( V_93 )
V_8 -> V_34 |= V_53 ;
F_38 ( V_50 , V_9 ,
L_14 ,
V_8 -> V_33 , V_32 -> V_96 ) ;
F_52 ( V_9 , V_8 -> V_33 ,
L_15 , V_86 ) ;
V_79 = 1 ;
V_49:
if ( V_8 )
F_24 ( V_8 ) ;
return V_79 ;
}
int F_62 ( struct V_69 * V_70 , void * V_71 )
{
struct V_45 * V_72 = (struct V_45 * ) V_70 -> V_73 ;
struct V_9 * V_9 = F_37 ( V_72 ) ;
struct V_14 * V_15 = V_9 -> V_24 ;
struct V_8 * V_8 ;
struct V_74 * V_75 ;
struct V_1 * V_2 ;
struct V_17 * V_18 ;
T_2 V_76 , V_77 ;
char * V_60 ;
int V_78 , V_79 = 0 ;
V_75 = F_47 ( V_9 ) ;
if ( ! V_75 ) {
V_79 = F_48 ( V_70 , L_16
L_17 ,
V_72 -> V_80 ) ;
goto V_49;
}
if ( V_75 -> V_81 != V_82 ) {
V_79 = F_48 ( V_70 , L_2
L_4 ,
V_72 -> V_80 ) ;
goto V_49;
}
F_48 ( V_70 ,
L_18 ,
V_72 -> V_80 ) ;
F_48 ( V_70 , L_19 ,
L_20 , L_21 , L_22 , L_23 , L_24 ) ;
V_76 = 1 ;
for ( V_78 = 0 ; V_78 < V_15 -> V_21 ; V_78 ++ ) {
V_18 = & V_15 -> V_22 [ V_78 ] ;
F_10 () ;
F_49 (node, head)
V_76 += 67 ;
F_14 () ;
}
V_60 = F_27 ( V_76 , V_36 ) ;
if ( ! V_60 ) {
V_79 = - V_83 ;
goto V_49;
}
V_60 [ 0 ] = '\0' ;
V_77 = 0 ;
for ( V_78 = 0 ; V_78 < V_15 -> V_21 ; V_78 ++ ) {
V_18 = & V_15 -> V_22 [ V_78 ] ;
F_10 () ;
F_11 (tt_global_entry, node,
head, hash_entry) {
V_77 += snprintf ( V_60 + V_77 , 69 ,
L_25
L_26 , V_8 -> V_33 ,
V_8 -> V_51 ,
V_8 -> V_32 -> V_96 ,
( T_1 ) F_39 (
& V_8 -> V_32 ->
V_97 ) ,
( V_8 -> V_34 &
V_58 ? 'R' : '.' ) ,
( V_8 -> V_34 &
V_84 ? 'X' : '.' ) ,
( V_8 -> V_34 &
V_53 ? 'W' : '.' ) ) ;
}
F_14 () ;
}
F_48 ( V_70 , L_9 , V_60 ) ;
F_23 ( V_60 ) ;
V_49:
if ( V_75 )
F_50 ( V_75 ) ;
return V_79 ;
}
static void F_63 ( struct V_9 * V_9 ,
struct V_8 * V_8 ,
const char * V_85 )
{
if ( ! V_8 )
goto V_49;
F_38 ( V_50 , V_9 ,
L_27 ,
V_8 -> V_33 , V_8 -> V_32 -> V_96 ,
V_85 ) ;
F_61 ( & V_8 -> V_32 -> V_95 ) ;
F_64 ( V_9 -> V_24 , F_3 , F_9 ,
V_8 -> V_33 ) ;
V_49:
if ( V_8 )
F_24 ( V_8 ) ;
}
void F_65 ( struct V_9 * V_9 ,
struct V_32 * V_32 , const unsigned char * V_33 ,
const char * V_85 , bool V_86 )
{
struct V_8 * V_8 = NULL ;
struct V_5 * V_5 = NULL ;
V_8 = F_15 ( V_9 , V_33 ) ;
if ( ! V_8 )
goto V_49;
if ( V_8 -> V_32 == V_32 ) {
if ( V_86 ) {
V_5 = F_8 ( V_9 ,
V_8 -> V_33 ) ;
if ( ! V_5 ) {
V_8 -> V_34 |= V_58 ;
V_8 -> V_59 = V_29 ;
goto V_49;
}
}
F_63 ( V_9 , V_8 , V_85 ) ;
}
V_49:
if ( V_8 )
F_24 ( V_8 ) ;
if ( V_5 )
F_18 ( V_5 ) ;
}
void F_66 ( struct V_9 * V_9 ,
struct V_32 * V_32 , const char * V_85 )
{
struct V_8 * V_8 ;
int V_78 ;
struct V_14 * V_15 = V_9 -> V_24 ;
struct V_1 * V_2 , * V_65 ;
struct V_17 * V_18 ;
T_4 * V_89 ;
if ( ! V_15 )
return;
for ( V_78 = 0 ; V_78 < V_15 -> V_21 ; V_78 ++ ) {
V_18 = & V_15 -> V_22 [ V_78 ] ;
V_89 = & V_15 -> V_90 [ V_78 ] ;
F_28 ( V_89 ) ;
F_54 (tt_global_entry, node, safe,
head, hash_entry) {
if ( V_8 -> V_32 == V_32 ) {
F_38 ( V_50 , V_9 ,
L_28
L_29 ,
V_8 -> V_33 ,
V_8 -> V_32 -> V_96 ) ;
F_56 ( V_2 ) ;
F_24 ( V_8 ) ;
}
}
F_31 ( V_89 ) ;
}
F_32 ( & V_32 -> V_95 , 0 ) ;
}
static void F_67 ( struct V_9 * V_9 )
{
struct V_14 * V_15 = V_9 -> V_24 ;
struct V_8 * V_8 ;
struct V_1 * V_2 , * V_88 ;
struct V_17 * V_18 ;
T_4 * V_89 ;
int V_78 ;
for ( V_78 = 0 ; V_78 < V_15 -> V_21 ; V_78 ++ ) {
V_18 = & V_15 -> V_22 [ V_78 ] ;
V_89 = & V_15 -> V_90 [ V_78 ] ;
F_28 ( V_89 ) ;
F_54 (tt_global_entry, node, node_tmp,
head, hash_entry) {
if ( ! ( V_8 -> V_34 & V_58 ) )
continue;
if ( ! F_16 ( V_8 -> V_59 ,
V_98 * 1000 ) )
continue;
F_38 ( V_50 , V_9 , L_30
L_31 ,
V_8 -> V_33 ) ;
F_61 ( & V_8 -> V_32 -> V_95 ) ;
F_56 ( V_2 ) ;
F_24 ( V_8 ) ;
}
F_31 ( V_89 ) ;
}
}
static void F_68 ( struct V_9 * V_9 )
{
struct V_14 * V_15 ;
T_4 * V_89 ;
struct V_8 * V_8 ;
struct V_1 * V_2 , * V_88 ;
struct V_17 * V_18 ;
int V_78 ;
if ( ! V_9 -> V_24 )
return;
V_15 = V_9 -> V_24 ;
for ( V_78 = 0 ; V_78 < V_15 -> V_21 ; V_78 ++ ) {
V_18 = & V_15 -> V_22 [ V_78 ] ;
V_89 = & V_15 -> V_90 [ V_78 ] ;
F_28 ( V_89 ) ;
F_54 (tt_global_entry, node, node_tmp,
head, hash_entry) {
F_56 ( V_2 ) ;
F_24 ( V_8 ) ;
}
F_31 ( V_89 ) ;
}
F_57 ( V_15 ) ;
V_9 -> V_24 = NULL ;
}
static bool F_69 ( struct V_5 * V_5 ,
struct V_8 * V_8 )
{
bool V_79 = false ;
if ( V_5 -> V_34 & V_53 &&
V_8 -> V_34 & V_53 )
V_79 = true ;
return V_79 ;
}
struct V_32 * F_70 ( struct V_9 * V_9 ,
const T_1 * V_99 , const T_1 * V_33 )
{
struct V_5 * V_5 = NULL ;
struct V_8 * V_8 = NULL ;
struct V_32 * V_32 = NULL ;
if ( V_99 && F_39 ( & V_9 -> V_100 ) ) {
V_5 = F_8 ( V_9 , V_99 ) ;
if ( ! V_5 )
goto V_49;
}
V_8 = F_15 ( V_9 , V_33 ) ;
if ( ! V_8 )
goto V_49;
if ( V_5 && F_69 ( V_5 , V_8 ) )
goto V_49;
if ( ! F_13 ( & V_8 -> V_32 -> V_23 ) )
goto V_49;
if ( V_8 -> V_34 & V_84 )
goto V_49;
V_32 = V_8 -> V_32 ;
V_49:
if ( V_8 )
F_24 ( V_8 ) ;
if ( V_5 )
F_18 ( V_5 ) ;
return V_32 ;
}
T_3 F_71 ( struct V_9 * V_9 , struct V_32 * V_32 )
{
T_3 V_101 = 0 , V_102 ;
struct V_14 * V_15 = V_9 -> V_24 ;
struct V_8 * V_8 ;
struct V_1 * V_2 ;
struct V_17 * V_18 ;
int V_78 , V_103 ;
for ( V_78 = 0 ; V_78 < V_15 -> V_21 ; V_78 ++ ) {
V_18 = & V_15 -> V_22 [ V_78 ] ;
F_10 () ;
F_11 (tt_global_entry, node,
head, hash_entry) {
if ( F_12 ( V_8 -> V_32 ,
V_32 ) ) {
if ( V_8 -> V_34 & V_58 )
continue;
V_102 = 0 ;
for ( V_103 = 0 ; V_103 < V_7 ; V_103 ++ )
V_102 = F_72 ( V_102 ,
V_8 -> V_33 [ V_103 ] ) ;
V_101 ^= V_102 ;
}
}
F_14 () ;
}
return V_101 ;
}
T_3 F_73 ( struct V_9 * V_9 )
{
T_3 V_101 = 0 , V_102 ;
struct V_14 * V_15 = V_9 -> V_16 ;
struct V_5 * V_5 ;
struct V_1 * V_2 ;
struct V_17 * V_18 ;
int V_78 , V_103 ;
for ( V_78 = 0 ; V_78 < V_15 -> V_21 ; V_78 ++ ) {
V_18 = & V_15 -> V_22 [ V_78 ] ;
F_10 () ;
F_11 (tt_local_entry, node,
head, hash_entry) {
if ( V_5 -> V_34 & V_56 )
continue;
V_102 = 0 ;
for ( V_103 = 0 ; V_103 < V_7 ; V_103 ++ )
V_102 = F_72 ( V_102 ,
V_5 -> V_33 [ V_103 ] ) ;
V_101 ^= V_102 ;
}
F_14 () ;
}
return V_101 ;
}
static void F_74 ( struct V_9 * V_9 )
{
struct V_104 * V_2 , * V_65 ;
F_28 ( & V_9 -> V_105 ) ;
F_44 (node, safe, &bat_priv->tt_req_list, list) {
F_45 ( & V_2 -> V_39 ) ;
F_23 ( V_2 ) ;
}
F_31 ( & V_9 -> V_105 ) ;
}
void F_75 ( struct V_9 * V_9 , struct V_32 * V_32 ,
const unsigned char * V_67 , T_1 V_106 )
{
T_3 V_68 = F_33 ( V_106 ) ;
F_28 ( & V_32 -> V_66 ) ;
if ( V_68 > 0 ) {
F_23 ( V_32 -> V_67 ) ;
V_32 -> V_68 = 0 ;
V_32 -> V_67 = F_27 ( V_68 , V_36 ) ;
if ( V_32 -> V_67 ) {
memcpy ( V_32 -> V_67 , V_67 , V_68 ) ;
V_32 -> V_68 = V_68 ;
}
}
F_31 ( & V_32 -> V_66 ) ;
}
static void F_76 ( struct V_9 * V_9 )
{
struct V_104 * V_2 , * V_65 ;
F_28 ( & V_9 -> V_105 ) ;
F_44 (node, safe, &bat_priv->tt_req_list, list) {
if ( F_16 ( V_2 -> V_107 ,
V_108 * 1000 ) ) {
F_45 ( & V_2 -> V_39 ) ;
F_23 ( V_2 ) ;
}
}
F_31 ( & V_9 -> V_105 ) ;
}
static struct V_104 * F_77 ( struct V_9 * V_9 ,
struct V_32 * V_32 )
{
struct V_104 * V_109 , * V_104 = NULL ;
F_28 ( & V_9 -> V_105 ) ;
F_78 (tt_req_node_tmp, &bat_priv->tt_req_list, list) {
if ( F_12 ( V_109 , V_32 ) &&
! F_16 ( V_109 -> V_107 ,
V_108 * 1000 ) )
goto V_110;
}
V_104 = F_27 ( sizeof( * V_104 ) , V_36 ) ;
if ( ! V_104 )
goto V_110;
memcpy ( V_104 -> V_33 , V_32 -> V_96 , V_7 ) ;
V_104 -> V_107 = V_29 ;
F_79 ( & V_104 -> V_39 , & V_9 -> V_111 ) ;
V_110:
F_31 ( & V_9 -> V_105 ) ;
return V_104 ;
}
static int F_80 ( const void * V_112 , const void * V_113 )
{
const struct V_5 * V_5 = V_112 ;
if ( V_5 -> V_34 & V_56 )
return 0 ;
return 1 ;
}
static int F_81 ( const void * V_112 , const void * V_113 )
{
const struct V_8 * V_8 = V_112 ;
const struct V_32 * V_32 = V_113 ;
if ( V_8 -> V_34 & V_58 )
return 0 ;
return ( V_8 -> V_32 == V_32 ) ;
}
static struct V_114 * F_82 ( T_3 F_33 , T_1 V_51 ,
struct V_14 * V_15 ,
struct V_74 * V_75 ,
int (* F_83)( const void * ,
const void * ) ,
void * V_115 )
{
struct V_5 * V_5 ;
struct V_116 * V_117 ;
struct V_44 * V_44 ;
struct V_1 * V_2 ;
struct V_17 * V_18 ;
struct V_114 * V_118 = NULL ;
T_3 V_119 , V_120 ;
T_5 V_121 = sizeof( struct V_116 ) ;
int V_78 ;
if ( V_121 + F_33 > V_75 -> V_46 -> V_122 ) {
F_33 = V_75 -> V_46 -> V_122 - V_121 ;
F_33 -= F_33 % sizeof( struct V_44 ) ;
}
V_119 = F_33 / sizeof( struct V_44 ) ;
V_118 = F_84 ( V_121 + F_33 + V_123 ) ;
if ( ! V_118 )
goto V_49;
F_85 ( V_118 , V_123 ) ;
V_117 = (struct V_116 * ) F_86 ( V_118 ,
V_121 + F_33 ) ;
V_117 -> V_51 = V_51 ;
V_44 = (struct V_44 * ) ( V_118 -> V_13 + V_121 ) ;
V_120 = 0 ;
F_10 () ;
for ( V_78 = 0 ; V_78 < V_15 -> V_21 ; V_78 ++ ) {
V_18 = & V_15 -> V_22 [ V_78 ] ;
F_11 (tt_local_entry, node,
head, hash_entry) {
if ( V_120 == V_119 )
break;
if ( ( F_83 ) && ( ! F_83 ( V_5 , V_115 ) ) )
continue;
memcpy ( V_44 -> V_33 , V_5 -> V_33 , V_7 ) ;
V_44 -> V_34 = V_52 ;
V_120 ++ ;
V_44 ++ ;
}
}
F_14 () ;
V_117 -> V_124 = F_87 ( V_120 ) ;
V_49:
return V_118 ;
}
static int F_88 ( struct V_9 * V_9 ,
struct V_32 * V_125 ,
T_1 V_51 , T_3 V_126 , bool V_127 )
{
struct V_114 * V_118 = NULL ;
struct V_116 * V_128 ;
struct V_129 * V_129 = NULL ;
struct V_74 * V_75 ;
struct V_104 * V_104 = NULL ;
int V_79 = 1 ;
V_75 = F_47 ( V_9 ) ;
if ( ! V_75 )
goto V_49;
V_104 = F_77 ( V_9 , V_125 ) ;
if ( ! V_104 )
goto V_49;
V_118 = F_84 ( sizeof( struct V_116 ) + V_123 ) ;
if ( ! V_118 )
goto V_49;
F_85 ( V_118 , V_123 ) ;
V_128 = (struct V_116 * ) F_86 ( V_118 ,
sizeof( struct V_116 ) ) ;
V_128 -> V_130 = V_131 ;
V_128 -> V_132 = V_133 ;
memcpy ( V_128 -> V_99 , V_75 -> V_72 -> V_54 , V_7 ) ;
memcpy ( V_128 -> V_134 , V_125 -> V_96 , V_7 ) ;
V_128 -> V_135 = V_136 ;
V_128 -> V_51 = V_51 ;
V_128 -> V_124 = V_126 ;
V_128 -> V_34 = V_137 ;
if ( V_127 )
V_128 -> V_34 |= V_138 ;
V_129 = F_89 ( V_125 ) ;
if ( ! V_129 )
goto V_49;
F_38 ( V_50 , V_9 , L_32
L_33 , V_125 -> V_96 , V_129 -> V_33 ,
( V_127 ? 'F' : '.' ) ) ;
F_90 ( V_118 , V_129 -> V_139 , V_129 -> V_33 ) ;
V_79 = 0 ;
V_49:
if ( V_129 )
F_91 ( V_129 ) ;
if ( V_75 )
F_50 ( V_75 ) ;
if ( V_79 )
F_92 ( V_118 ) ;
if ( V_79 && V_104 ) {
F_28 ( & V_9 -> V_105 ) ;
F_45 ( & V_104 -> V_39 ) ;
F_31 ( & V_9 -> V_105 ) ;
F_23 ( V_104 ) ;
}
return V_79 ;
}
static bool F_93 ( struct V_9 * V_9 ,
struct V_116 * V_128 )
{
struct V_32 * V_140 = NULL , * V_141 = NULL ;
struct V_129 * V_129 = NULL ;
struct V_74 * V_75 = NULL ;
T_1 V_142 , V_143 , V_51 ;
int V_79 = false ;
unsigned char * V_67 ;
bool V_127 ;
T_3 F_33 , V_119 ;
struct V_114 * V_118 = NULL ;
struct V_116 * V_117 ;
F_38 ( V_50 , V_9 ,
L_34
L_35 , V_128 -> V_99 ,
V_128 -> V_51 , V_128 -> V_134 ,
( V_128 -> V_34 & V_138 ? 'F' : '.' ) ) ;
V_140 = F_94 ( V_9 , V_128 -> V_134 ) ;
if ( ! V_140 )
goto V_49;
V_141 = F_94 ( V_9 , V_128 -> V_99 ) ;
if ( ! V_141 )
goto V_49;
V_129 = F_89 ( V_141 ) ;
if ( ! V_129 )
goto V_49;
V_75 = F_47 ( V_9 ) ;
if ( ! V_75 )
goto V_49;
V_142 = ( T_1 ) F_39 ( & V_140 -> V_97 ) ;
V_143 = V_128 -> V_51 ;
if ( V_142 != V_143 ||
V_128 -> V_124 != V_140 -> V_126 )
goto V_49;
if ( V_128 -> V_34 & V_138 ||
! V_140 -> V_67 )
V_127 = true ;
else
V_127 = false ;
if ( ! V_127 ) {
F_28 ( & V_140 -> V_66 ) ;
F_33 = V_140 -> V_68 ;
V_119 = F_33 / sizeof( struct V_44 ) ;
V_118 = F_84 ( sizeof( struct V_116 ) +
F_33 + V_123 ) ;
if ( ! V_118 )
goto V_110;
F_85 ( V_118 , V_123 ) ;
V_117 = (struct V_116 * ) F_86 ( V_118 ,
sizeof( struct V_116 ) + F_33 ) ;
V_117 -> V_51 = V_143 ;
V_117 -> V_124 = F_87 ( V_119 ) ;
V_67 = V_118 -> V_13 + sizeof( struct V_116 ) ;
memcpy ( V_67 , V_140 -> V_67 ,
V_140 -> V_68 ) ;
F_31 ( & V_140 -> V_66 ) ;
} else {
F_33 = ( T_3 ) F_39 ( & V_140 -> V_95 ) *
sizeof( struct V_44 ) ;
V_51 = ( T_1 ) F_39 ( & V_140 -> V_97 ) ;
V_118 = F_82 ( F_33 , V_51 ,
V_9 -> V_24 ,
V_75 , F_81 ,
V_140 ) ;
if ( ! V_118 )
goto V_49;
V_117 = (struct V_116 * ) V_118 -> V_13 ;
}
V_117 -> V_130 = V_131 ;
V_117 -> V_132 = V_133 ;
V_117 -> V_135 = V_136 ;
memcpy ( V_117 -> V_99 , V_140 -> V_96 , V_7 ) ;
memcpy ( V_117 -> V_134 , V_128 -> V_99 , V_7 ) ;
V_117 -> V_34 = V_144 ;
if ( V_127 )
V_117 -> V_34 |= V_138 ;
F_38 ( V_50 , V_9 ,
L_36 ,
V_141 -> V_96 , V_129 -> V_33 ,
V_140 -> V_96 , V_143 ) ;
F_90 ( V_118 , V_129 -> V_139 , V_129 -> V_33 ) ;
V_79 = true ;
goto V_49;
V_110:
F_31 ( & V_140 -> V_66 ) ;
V_49:
if ( V_141 )
F_22 ( V_141 ) ;
if ( V_140 )
F_22 ( V_140 ) ;
if ( V_129 )
F_91 ( V_129 ) ;
if ( V_75 )
F_50 ( V_75 ) ;
if ( ! V_79 )
F_92 ( V_118 ) ;
return V_79 ;
}
static bool F_95 ( struct V_9 * V_9 ,
struct V_116 * V_128 )
{
struct V_32 * V_32 = NULL ;
struct V_129 * V_129 = NULL ;
struct V_74 * V_75 = NULL ;
T_1 V_145 , V_143 , V_51 ;
int V_79 = false ;
unsigned char * V_67 ;
bool V_127 ;
T_3 F_33 , V_119 ;
struct V_114 * V_118 = NULL ;
struct V_116 * V_117 ;
F_38 ( V_50 , V_9 ,
L_34
L_37 , V_128 -> V_99 ,
V_128 -> V_51 ,
( V_128 -> V_34 & V_138 ? 'F' : '.' ) ) ;
V_145 = ( T_1 ) F_39 ( & V_9 -> V_51 ) ;
V_143 = V_128 -> V_51 ;
V_32 = F_94 ( V_9 , V_128 -> V_99 ) ;
if ( ! V_32 )
goto V_49;
V_129 = F_89 ( V_32 ) ;
if ( ! V_129 )
goto V_49;
V_75 = F_47 ( V_9 ) ;
if ( ! V_75 )
goto V_49;
if ( V_128 -> V_34 & V_138 || V_145 != V_143 ||
! V_9 -> V_67 )
V_127 = true ;
else
V_127 = false ;
if ( ! V_127 ) {
F_28 ( & V_9 -> V_66 ) ;
F_33 = V_9 -> V_68 ;
V_119 = F_33 / sizeof( struct V_44 ) ;
V_118 = F_84 ( sizeof( struct V_116 ) +
F_33 + V_123 ) ;
if ( ! V_118 )
goto V_110;
F_85 ( V_118 , V_123 ) ;
V_117 = (struct V_116 * ) F_86 ( V_118 ,
sizeof( struct V_116 ) + F_33 ) ;
V_117 -> V_51 = V_143 ;
V_117 -> V_124 = F_87 ( V_119 ) ;
V_67 = V_118 -> V_13 + sizeof( struct V_116 ) ;
memcpy ( V_67 , V_9 -> V_67 ,
V_9 -> V_68 ) ;
F_31 ( & V_9 -> V_66 ) ;
} else {
F_33 = ( T_3 ) F_39 ( & V_9 -> V_146 ) *
sizeof( struct V_44 ) ;
V_51 = ( T_1 ) F_39 ( & V_9 -> V_51 ) ;
V_118 = F_82 ( F_33 , V_51 ,
V_9 -> V_16 ,
V_75 , F_80 ,
NULL ) ;
if ( ! V_118 )
goto V_49;
V_117 = (struct V_116 * ) V_118 -> V_13 ;
}
V_117 -> V_130 = V_131 ;
V_117 -> V_132 = V_133 ;
V_117 -> V_135 = V_136 ;
memcpy ( V_117 -> V_99 , V_75 -> V_72 -> V_54 , V_7 ) ;
memcpy ( V_117 -> V_134 , V_128 -> V_99 , V_7 ) ;
V_117 -> V_34 = V_144 ;
if ( V_127 )
V_117 -> V_34 |= V_138 ;
F_38 ( V_50 , V_9 ,
L_38 ,
V_32 -> V_96 , V_129 -> V_33 ,
( V_117 -> V_34 & V_138 ? 'F' : '.' ) ) ;
F_90 ( V_118 , V_129 -> V_139 , V_129 -> V_33 ) ;
V_79 = true ;
goto V_49;
V_110:
F_31 ( & V_9 -> V_66 ) ;
V_49:
if ( V_32 )
F_22 ( V_32 ) ;
if ( V_129 )
F_91 ( V_129 ) ;
if ( V_75 )
F_50 ( V_75 ) ;
if ( ! V_79 )
F_92 ( V_118 ) ;
return true ;
}
bool F_96 ( struct V_9 * V_9 ,
struct V_116 * V_128 )
{
if ( F_97 ( V_128 -> V_134 ) )
return F_95 ( V_9 , V_128 ) ;
else
return F_93 ( V_9 , V_128 ) ;
}
static void F_98 ( struct V_9 * V_9 ,
struct V_32 * V_32 ,
struct V_44 * V_44 ,
T_3 V_106 , T_1 V_51 )
{
int V_78 ;
for ( V_78 = 0 ; V_78 < V_106 ; V_78 ++ ) {
if ( ( V_44 + V_78 ) -> V_34 & V_87 )
F_65 ( V_9 , V_32 ,
( V_44 + V_78 ) -> V_33 ,
L_39 ,
( V_44 + V_78 ) -> V_34 & V_58 ) ;
else
if ( ! F_60 ( V_9 , V_32 ,
( V_44 + V_78 ) -> V_33 , V_51 , false ,
( V_44 + V_78 ) -> V_34 &
V_53 ) )
return;
}
}
static void F_99 ( struct V_9 * V_9 ,
struct V_116 * V_117 )
{
struct V_32 * V_32 = NULL ;
V_32 = F_100 ( V_9 , V_117 -> V_99 ) ;
if ( ! V_32 )
goto V_49;
F_66 ( V_9 , V_32 , L_40 ) ;
F_98 ( V_9 , V_32 ,
(struct V_44 * ) ( V_117 + 1 ) ,
V_117 -> V_124 , V_117 -> V_51 ) ;
F_28 ( & V_32 -> V_66 ) ;
F_23 ( V_32 -> V_67 ) ;
V_32 -> V_68 = 0 ;
V_32 -> V_67 = NULL ;
F_31 ( & V_32 -> V_66 ) ;
F_32 ( & V_32 -> V_97 , V_117 -> V_51 ) ;
V_49:
if ( V_32 )
F_22 ( V_32 ) ;
}
static void F_101 ( struct V_9 * V_9 ,
struct V_32 * V_32 ,
T_3 V_106 , T_1 V_51 ,
struct V_44 * V_44 )
{
F_98 ( V_9 , V_32 , V_44 , V_106 ,
V_51 ) ;
F_75 ( V_9 , V_32 , ( unsigned char * ) V_44 ,
V_106 ) ;
F_32 ( & V_32 -> V_97 , V_51 ) ;
}
bool F_102 ( struct V_9 * V_9 , const T_1 * V_33 )
{
struct V_5 * V_5 = NULL ;
bool V_79 = false ;
V_5 = F_8 ( V_9 , V_33 ) ;
if ( ! V_5 )
goto V_49;
if ( V_5 -> V_34 & V_84 )
goto V_49;
V_79 = true ;
V_49:
if ( V_5 )
F_18 ( V_5 ) ;
return V_79 ;
}
void F_103 ( struct V_9 * V_9 ,
struct V_116 * V_117 )
{
struct V_104 * V_2 , * V_65 ;
struct V_32 * V_32 = NULL ;
F_38 ( V_50 , V_9 , L_41
L_42 ,
V_117 -> V_99 , V_117 -> V_51 ,
V_117 -> V_124 ,
( V_117 -> V_34 & V_138 ? 'F' : '.' ) ) ;
V_32 = F_100 ( V_9 , V_117 -> V_99 ) ;
if ( ! V_32 )
goto V_49;
if ( V_117 -> V_34 & V_138 )
F_99 ( V_9 , V_117 ) ;
else
F_101 ( V_9 , V_32 , V_117 -> V_124 ,
V_117 -> V_51 ,
(struct V_44 * ) ( V_117 + 1 ) ) ;
F_28 ( & V_9 -> V_105 ) ;
F_44 (node, safe, &bat_priv->tt_req_list, list) {
if ( ! F_12 ( V_2 -> V_33 , V_117 -> V_99 ) )
continue;
F_45 ( & V_2 -> V_39 ) ;
F_23 ( V_2 ) ;
}
F_31 ( & V_9 -> V_105 ) ;
V_32 -> V_126 = F_71 ( V_9 , V_32 ) ;
V_32 -> V_57 = false ;
V_49:
if ( V_32 )
F_22 ( V_32 ) ;
}
int F_104 ( struct V_9 * V_9 )
{
if ( ! F_34 ( V_9 ) )
return 0 ;
if ( ! F_58 ( V_9 ) )
return 0 ;
F_4 ( V_9 ) ;
return 1 ;
}
static void F_105 ( struct V_9 * V_9 )
{
struct V_147 * V_2 , * V_65 ;
F_28 ( & V_9 -> V_148 ) ;
F_44 (node, safe, &bat_priv->tt_roam_list, list) {
F_45 ( & V_2 -> V_39 ) ;
F_23 ( V_2 ) ;
}
F_31 ( & V_9 -> V_148 ) ;
}
static void F_106 ( struct V_9 * V_9 )
{
struct V_147 * V_2 , * V_65 ;
F_28 ( & V_9 -> V_148 ) ;
F_44 (node, safe, &bat_priv->tt_roam_list, list) {
if ( ! F_16 ( V_2 -> V_149 ,
V_150 * 1000 ) )
continue;
F_45 ( & V_2 -> V_39 ) ;
F_23 ( V_2 ) ;
}
F_31 ( & V_9 -> V_148 ) ;
}
static bool F_107 ( struct V_9 * V_9 ,
T_1 * V_151 )
{
struct V_147 * V_147 ;
bool V_79 = false ;
F_28 ( & V_9 -> V_148 ) ;
F_78 (tt_roam_node, &bat_priv->tt_roam_list, list) {
if ( ! F_12 ( V_147 -> V_33 , V_151 ) )
continue;
if ( F_16 ( V_147 -> V_149 ,
V_150 * 1000 ) )
continue;
if ( ! F_108 ( & V_147 -> V_152 ) )
goto V_110;
V_79 = true ;
break;
}
if ( ! V_79 ) {
V_147 = F_27 ( sizeof( * V_147 ) , V_36 ) ;
if ( ! V_147 )
goto V_110;
V_147 -> V_149 = V_29 ;
F_32 ( & V_147 -> V_152 , V_153 - 1 ) ;
memcpy ( V_147 -> V_33 , V_151 , V_7 ) ;
F_79 ( & V_147 -> V_39 , & V_9 -> V_154 ) ;
V_79 = true ;
}
V_110:
F_31 ( & V_9 -> V_148 ) ;
return V_79 ;
}
void F_42 ( struct V_9 * V_9 , T_1 * V_151 ,
struct V_32 * V_32 )
{
struct V_129 * V_129 = NULL ;
struct V_114 * V_118 = NULL ;
struct V_155 * V_155 ;
int V_79 = 1 ;
struct V_74 * V_75 ;
if ( ! F_107 ( V_9 , V_151 ) )
goto V_49;
V_118 = F_84 ( sizeof( struct V_155 ) + V_123 ) ;
if ( ! V_118 )
goto V_49;
F_85 ( V_118 , V_123 ) ;
V_155 = (struct V_155 * ) F_86 ( V_118 ,
sizeof( struct V_155 ) ) ;
V_155 -> V_130 = V_156 ;
V_155 -> V_132 = V_133 ;
V_155 -> V_135 = V_136 ;
V_75 = F_47 ( V_9 ) ;
if ( ! V_75 )
goto V_49;
memcpy ( V_155 -> V_99 , V_75 -> V_72 -> V_54 , V_7 ) ;
F_50 ( V_75 ) ;
memcpy ( V_155 -> V_134 , V_32 -> V_96 , V_7 ) ;
memcpy ( V_155 -> V_151 , V_151 , V_7 ) ;
V_129 = F_89 ( V_32 ) ;
if ( ! V_129 )
goto V_49;
F_38 ( V_50 , V_9 ,
L_43 ,
V_32 -> V_96 , V_151 , V_129 -> V_33 ) ;
F_90 ( V_118 , V_129 -> V_139 , V_129 -> V_33 ) ;
V_79 = 0 ;
V_49:
if ( V_129 )
F_91 ( V_129 ) ;
if ( V_79 )
F_92 ( V_118 ) ;
return;
}
static void V_11 ( struct V_157 * V_158 )
{
struct V_159 * V_159 =
F_2 ( V_158 , struct V_159 , V_158 ) ;
struct V_9 * V_9 =
F_2 ( V_159 , struct V_9 , V_10 ) ;
F_53 ( V_9 ) ;
F_67 ( V_9 ) ;
F_76 ( V_9 ) ;
F_106 ( V_9 ) ;
F_4 ( V_9 ) ;
}
void F_109 ( struct V_9 * V_9 )
{
F_110 ( & V_9 -> V_10 ) ;
F_55 ( V_9 ) ;
F_68 ( V_9 ) ;
F_74 ( V_9 ) ;
F_59 ( V_9 ) ;
F_105 ( V_9 ) ;
F_23 ( V_9 -> V_67 ) ;
}
static void F_111 ( struct V_9 * V_9 , T_3 V_34 )
{
int V_78 ;
struct V_14 * V_15 = V_9 -> V_16 ;
struct V_17 * V_18 ;
struct V_1 * V_2 ;
struct V_5 * V_5 ;
if ( ! V_15 )
return;
for ( V_78 = 0 ; V_78 < V_15 -> V_21 ; V_78 ++ ) {
V_18 = & V_15 -> V_22 [ V_78 ] ;
F_10 () ;
F_11 (tt_local_entry, node,
head, hash_entry) {
if ( ! ( V_5 -> V_34 & V_34 ) )
continue;
V_5 -> V_34 &= ~ V_34 ;
F_30 ( & V_9 -> V_146 ) ;
}
F_14 () ;
}
}
static void F_112 ( struct V_9 * V_9 )
{
struct V_14 * V_15 = V_9 -> V_16 ;
struct V_5 * V_5 ;
struct V_1 * V_2 , * V_88 ;
struct V_17 * V_18 ;
T_4 * V_89 ;
int V_78 ;
if ( ! V_15 )
return;
for ( V_78 = 0 ; V_78 < V_15 -> V_21 ; V_78 ++ ) {
V_18 = & V_15 -> V_22 [ V_78 ] ;
V_89 = & V_15 -> V_90 [ V_78 ] ;
F_28 ( V_89 ) ;
F_54 (tt_local_entry, node, node_tmp,
head, hash_entry) {
if ( ! ( V_5 -> V_34 & V_84 ) )
continue;
F_38 ( V_50 , V_9 , L_44
L_45 , V_5 -> V_33 ) ;
F_61 ( & V_9 -> V_146 ) ;
F_56 ( V_2 ) ;
F_18 ( V_5 ) ;
}
F_31 ( V_89 ) ;
}
}
void F_113 ( struct V_9 * V_9 )
{
F_111 ( V_9 , V_56 ) ;
F_112 ( V_9 ) ;
F_30 ( & V_9 -> V_51 ) ;
V_9 -> V_57 = false ;
}
bool F_114 ( struct V_9 * V_9 , T_1 * V_99 , T_1 * V_134 )
{
struct V_5 * V_5 = NULL ;
struct V_8 * V_8 = NULL ;
bool V_79 = true ;
if ( ! F_39 ( & V_9 -> V_100 ) )
return false ;
V_5 = F_8 ( V_9 , V_134 ) ;
if ( ! V_5 )
goto V_49;
V_8 = F_15 ( V_9 , V_99 ) ;
if ( ! V_8 )
goto V_49;
if ( F_69 ( V_5 , V_8 ) )
goto V_49;
V_79 = false ;
V_49:
if ( V_8 )
F_24 ( V_8 ) ;
if ( V_5 )
F_18 ( V_5 ) ;
return V_79 ;
}
void F_115 ( struct V_9 * V_9 , struct V_32 * V_32 ,
const unsigned char * V_67 , T_1 V_106 ,
T_1 V_51 , T_3 V_126 )
{
T_1 V_142 = ( T_1 ) F_39 ( & V_32 -> V_97 ) ;
bool V_127 = true ;
if ( V_51 - V_142 == 1 ) {
if ( ! V_106 ) {
V_127 = false ;
goto V_160;
}
F_101 ( V_9 , V_32 , V_106 , V_51 ,
(struct V_44 * ) V_67 ) ;
V_32 -> V_126 = F_71 ( V_9 , V_32 ) ;
if ( V_32 -> V_126 != V_126 )
goto V_160;
V_32 -> V_57 = false ;
} else {
if ( V_51 != V_142 || V_32 -> V_126 != V_126 ) {
V_160:
F_38 ( V_50 , V_9 , L_46
L_47
L_48
L_49 , V_32 -> V_96 , V_51 ,
V_142 , V_126 , V_32 -> V_126 ,
V_106 ) ;
F_88 ( V_9 , V_32 , V_51 , V_126 ,
V_127 ) ;
return;
}
}
}
