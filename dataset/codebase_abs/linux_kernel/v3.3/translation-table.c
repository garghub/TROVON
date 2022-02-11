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
static bool F_16 ( unsigned long V_27 , unsigned long V_28 )
{
unsigned long V_29 ;
V_29 = V_27 + F_6 ( V_28 ) ;
return F_17 ( V_30 , V_29 ) ;
}
static void F_18 ( struct V_22 * V_22 )
{
if ( F_19 ( & V_22 -> V_24 . V_21 ) )
F_20 ( V_22 , V_24 . V_31 ) ;
}
static void F_21 ( struct V_32 * V_31 )
{
struct V_5 * V_5 ;
struct V_25 * V_25 ;
V_5 = F_2 ( V_31 , struct V_5 , V_31 ) ;
V_25 = F_2 ( V_5 , struct V_25 ,
V_24 ) ;
if ( V_25 -> V_33 )
F_22 ( V_25 -> V_33 ) ;
F_23 ( V_25 ) ;
}
static void F_24 ( struct V_25 * V_25 )
{
if ( F_19 ( & V_25 -> V_24 . V_21 ) )
F_25 ( & V_25 -> V_24 . V_31 ,
F_21 ) ;
}
static void F_26 ( struct V_8 * V_8 , const T_2 * V_34 ,
T_2 V_35 )
{
struct V_36 * V_36 ;
V_36 = F_27 ( sizeof( * V_36 ) , V_37 ) ;
if ( ! V_36 )
return;
V_36 -> V_38 . V_35 = V_35 ;
memcpy ( V_36 -> V_38 . V_34 , V_34 , V_7 ) ;
F_28 ( & V_8 -> V_39 ) ;
F_29 ( & V_36 -> V_40 , & V_8 -> V_41 ) ;
F_30 ( & V_8 -> V_42 ) ;
F_31 ( & V_8 -> V_39 ) ;
F_32 ( & V_8 -> V_43 , 0 ) ;
}
int F_33 ( int V_44 )
{
return V_44 * sizeof( struct V_45 ) ;
}
static int F_34 ( struct V_8 * V_8 )
{
if ( V_8 -> V_23 )
return 1 ;
V_8 -> V_23 = F_35 ( 1024 ) ;
if ( ! V_8 -> V_23 )
return 0 ;
return 1 ;
}
void F_36 ( struct V_46 * V_47 , const T_2 * V_34 ,
int V_48 )
{
struct V_8 * V_8 = F_37 ( V_47 ) ;
struct V_22 * V_22 = NULL ;
struct V_25 * V_25 = NULL ;
int V_49 ;
V_22 = F_14 ( V_8 , V_34 ) ;
if ( V_22 ) {
V_22 -> V_50 = V_30 ;
goto V_51;
}
V_22 = F_27 ( sizeof( * V_22 ) , V_37 ) ;
if ( ! V_22 )
goto V_51;
F_38 ( V_52 , V_8 ,
L_1 , V_34 ,
( T_2 ) F_39 ( & V_8 -> V_53 ) ) ;
memcpy ( V_22 -> V_24 . V_34 , V_34 , V_7 ) ;
V_22 -> V_24 . V_35 = V_54 ;
if ( F_40 ( V_48 ) )
V_22 -> V_24 . V_35 |= V_55 ;
F_32 ( & V_22 -> V_24 . V_21 , 2 ) ;
V_22 -> V_50 = V_30 ;
if ( F_11 ( V_34 , V_47 -> V_56 ) )
V_22 -> V_24 . V_35 |= V_57 ;
V_49 = F_41 ( V_8 -> V_23 , F_1 , F_8 ,
& V_22 -> V_24 ,
& V_22 -> V_24 . V_6 ) ;
if ( F_42 ( V_49 != 0 ) ) {
F_18 ( V_22 ) ;
goto V_51;
}
F_26 ( V_8 , V_34 , V_22 -> V_24 . V_35 ) ;
V_22 -> V_24 . V_35 |= V_58 ;
V_25 = F_15 ( V_8 , V_34 ) ;
if ( V_25 ) {
V_25 -> V_33 -> V_59 = true ;
V_25 -> V_24 . V_35 |= V_60 ;
V_25 -> V_61 = V_30 ;
F_43 ( V_8 , V_25 -> V_24 . V_34 ,
V_25 -> V_33 ) ;
}
V_51:
if ( V_22 )
F_18 ( V_22 ) ;
if ( V_25 )
F_24 ( V_25 ) ;
}
int F_44 ( struct V_8 * V_8 ,
unsigned char * V_62 , int V_63 )
{
int V_64 = 0 , V_65 = 0 ;
struct V_36 * V_66 , * V_67 ;
if ( V_63 > 0 )
V_65 = V_63 / F_33 ( 1 ) ;
F_28 ( & V_8 -> V_39 ) ;
F_32 ( & V_8 -> V_42 , 0 ) ;
F_45 (entry, safe, &bat_priv->tt_changes_list,
list) {
if ( V_64 < V_65 ) {
memcpy ( V_62 + F_33 ( V_64 ) ,
& V_66 -> V_38 , sizeof( struct V_45 ) ) ;
V_64 ++ ;
}
F_46 ( & V_66 -> V_40 ) ;
F_23 ( V_66 ) ;
}
F_31 ( & V_8 -> V_39 ) ;
F_28 ( & V_8 -> V_68 ) ;
F_23 ( V_8 -> V_69 ) ;
V_8 -> V_70 = 0 ;
V_8 -> V_69 = NULL ;
if ( V_63 > 0 ) {
V_8 -> V_69 = F_27 ( V_63 , V_37 ) ;
if ( V_8 -> V_69 ) {
memcpy ( V_8 -> V_69 , V_62 , V_63 ) ;
V_8 -> V_70 = V_63 ;
}
}
F_31 ( & V_8 -> V_68 ) ;
return V_65 ;
}
int F_47 ( struct V_71 * V_72 , void * V_73 )
{
struct V_46 * V_74 = (struct V_46 * ) V_72 -> V_75 ;
struct V_8 * V_8 = F_37 ( V_74 ) ;
struct V_12 * V_13 = V_8 -> V_23 ;
struct V_5 * V_5 ;
struct V_76 * V_77 ;
struct V_1 * V_2 ;
struct V_15 * V_16 ;
T_1 V_78 ;
int V_79 = 0 ;
V_77 = F_48 ( V_8 ) ;
if ( ! V_77 ) {
V_79 = F_49 ( V_72 , L_2
L_3 ,
V_74 -> V_80 ) ;
goto V_51;
}
if ( V_77 -> V_81 != V_82 ) {
V_79 = F_49 ( V_72 , L_2
L_4 ,
V_74 -> V_80 ) ;
goto V_51;
}
F_49 ( V_72 , L_5
L_6 ,
V_74 -> V_80 , ( T_2 ) F_39 ( & V_8 -> V_53 ) ) ;
for ( V_78 = 0 ; V_78 < V_13 -> V_19 ; V_78 ++ ) {
V_16 = & V_13 -> V_20 [ V_78 ] ;
F_9 () ;
F_10 (tt_common_entry, node,
head, hash_entry) {
F_49 ( V_72 , L_7 ,
V_5 -> V_34 ,
( V_5 -> V_35 &
V_60 ? 'R' : '.' ) ,
( V_5 -> V_35 &
V_57 ? 'P' : '.' ) ,
( V_5 -> V_35 &
V_58 ? 'N' : '.' ) ,
( V_5 -> V_35 &
V_83 ? 'X' : '.' ) ,
( V_5 -> V_35 &
V_55 ? 'W' : '.' ) ) ;
}
F_13 () ;
}
V_51:
if ( V_77 )
F_50 ( V_77 ) ;
return V_79 ;
}
static void F_51 ( struct V_8 * V_8 ,
struct V_22 * V_22 ,
T_3 V_35 )
{
F_26 ( V_8 , V_22 -> V_24 . V_34 ,
V_22 -> V_24 . V_35 | V_35 ) ;
V_22 -> V_24 . V_35 |= V_83 ;
}
void F_52 ( struct V_8 * V_8 , const T_2 * V_34 ,
const char * V_84 , bool V_85 )
{
struct V_22 * V_22 = NULL ;
V_22 = F_14 ( V_8 , V_34 ) ;
if ( ! V_22 )
goto V_51;
F_51 ( V_8 , V_22 , V_86 |
( V_85 ? V_60 : V_54 ) ) ;
F_38 ( V_52 , V_8 , L_8
L_9 , V_22 -> V_24 . V_34 , V_84 ) ;
V_51:
if ( V_22 )
F_18 ( V_22 ) ;
}
static void F_53 ( struct V_8 * V_8 )
{
struct V_12 * V_13 = V_8 -> V_23 ;
struct V_22 * V_22 ;
struct V_5 * V_5 ;
struct V_1 * V_2 , * V_87 ;
struct V_15 * V_16 ;
T_4 * V_88 ;
T_1 V_78 ;
for ( V_78 = 0 ; V_78 < V_13 -> V_19 ; V_78 ++ ) {
V_16 = & V_13 -> V_20 [ V_78 ] ;
V_88 = & V_13 -> V_89 [ V_78 ] ;
F_28 ( V_88 ) ;
F_54 (tt_common_entry, node, node_tmp,
head, hash_entry) {
V_22 = F_2 ( V_5 ,
struct V_22 ,
V_24 ) ;
if ( V_22 -> V_24 . V_35 & V_57 )
continue;
if ( V_22 -> V_24 . V_35 & V_83 )
continue;
if ( ! F_16 ( V_22 -> V_50 ,
V_90 * 1000 ) )
continue;
F_51 ( V_8 , V_22 ,
V_86 ) ;
F_38 ( V_52 , V_8 , L_10
L_11 ,
V_22 -> V_24 . V_34 ) ;
}
F_31 ( V_88 ) ;
}
}
static void F_55 ( struct V_8 * V_8 )
{
struct V_12 * V_13 ;
T_4 * V_88 ;
struct V_5 * V_5 ;
struct V_22 * V_22 ;
struct V_1 * V_2 , * V_87 ;
struct V_15 * V_16 ;
T_1 V_78 ;
if ( ! V_8 -> V_23 )
return;
V_13 = V_8 -> V_23 ;
for ( V_78 = 0 ; V_78 < V_13 -> V_19 ; V_78 ++ ) {
V_16 = & V_13 -> V_20 [ V_78 ] ;
V_88 = & V_13 -> V_89 [ V_78 ] ;
F_28 ( V_88 ) ;
F_54 (tt_common_entry, node, node_tmp,
head, hash_entry) {
F_56 ( V_2 ) ;
V_22 = F_2 ( V_5 ,
struct V_22 ,
V_24 ) ;
F_18 ( V_22 ) ;
}
F_31 ( V_88 ) ;
}
F_57 ( V_13 ) ;
V_8 -> V_23 = NULL ;
}
static int F_58 ( struct V_8 * V_8 )
{
if ( V_8 -> V_26 )
return 1 ;
V_8 -> V_26 = F_35 ( 1024 ) ;
if ( ! V_8 -> V_26 )
return 0 ;
return 1 ;
}
static void F_59 ( struct V_8 * V_8 )
{
struct V_36 * V_66 , * V_67 ;
F_28 ( & V_8 -> V_39 ) ;
F_45 (entry, safe, &bat_priv->tt_changes_list,
list) {
F_46 ( & V_66 -> V_40 ) ;
F_23 ( V_66 ) ;
}
F_32 ( & V_8 -> V_42 , 0 ) ;
F_31 ( & V_8 -> V_39 ) ;
}
int F_60 ( struct V_8 * V_8 , struct V_33 * V_33 ,
const unsigned char * V_91 , T_2 V_53 , bool V_85 ,
bool V_92 )
{
struct V_25 * V_25 ;
struct V_33 * V_93 ;
int V_79 = 0 ;
int V_49 ;
V_25 = F_15 ( V_8 , V_91 ) ;
if ( ! V_25 ) {
V_25 =
F_27 ( sizeof( * V_25 ) ,
V_37 ) ;
if ( ! V_25 )
goto V_51;
memcpy ( V_25 -> V_24 . V_34 , V_91 , V_7 ) ;
V_25 -> V_24 . V_35 = V_54 ;
F_32 ( & V_25 -> V_24 . V_21 , 2 ) ;
F_30 ( & V_33 -> V_21 ) ;
V_25 -> V_33 = V_33 ;
V_25 -> V_53 = V_53 ;
V_25 -> V_61 = 0 ;
V_49 = F_41 ( V_8 -> V_26 , F_1 ,
F_8 , & V_25 -> V_24 ,
& V_25 -> V_24 . V_6 ) ;
if ( F_42 ( V_49 != 0 ) ) {
F_24 ( V_25 ) ;
goto V_94;
}
F_30 ( & V_33 -> V_95 ) ;
} else {
if ( V_25 -> V_33 != V_33 ) {
F_61 ( & V_25 -> V_33 -> V_95 ) ;
V_93 = V_25 -> V_33 ;
F_30 ( & V_33 -> V_21 ) ;
V_25 -> V_33 = V_33 ;
F_22 ( V_93 ) ;
F_30 ( & V_33 -> V_95 ) ;
}
V_25 -> V_24 . V_35 = V_54 ;
V_25 -> V_53 = V_53 ;
V_25 -> V_61 = 0 ;
}
if ( V_92 )
V_25 -> V_24 . V_35 |= V_55 ;
F_38 ( V_52 , V_8 ,
L_12 ,
V_25 -> V_24 . V_34 , V_33 -> V_96 ) ;
V_94:
F_52 ( V_8 , V_25 -> V_24 . V_34 ,
L_13 , V_85 ) ;
V_79 = 1 ;
V_51:
if ( V_25 )
F_24 ( V_25 ) ;
return V_79 ;
}
int F_62 ( struct V_71 * V_72 , void * V_73 )
{
struct V_46 * V_74 = (struct V_46 * ) V_72 -> V_75 ;
struct V_8 * V_8 = F_37 ( V_74 ) ;
struct V_12 * V_13 = V_8 -> V_26 ;
struct V_5 * V_5 ;
struct V_25 * V_25 ;
struct V_76 * V_77 ;
struct V_1 * V_2 ;
struct V_15 * V_16 ;
T_1 V_78 ;
int V_79 = 0 ;
V_77 = F_48 ( V_8 ) ;
if ( ! V_77 ) {
V_79 = F_49 ( V_72 , L_14
L_15 ,
V_74 -> V_80 ) ;
goto V_51;
}
if ( V_77 -> V_81 != V_82 ) {
V_79 = F_49 ( V_72 , L_2
L_4 ,
V_74 -> V_80 ) ;
goto V_51;
}
F_49 ( V_72 ,
L_16 ,
V_74 -> V_80 ) ;
F_49 ( V_72 , L_17 ,
L_18 , L_19 , L_20 , L_21 , L_22 ) ;
for ( V_78 = 0 ; V_78 < V_13 -> V_19 ; V_78 ++ ) {
V_16 = & V_13 -> V_20 [ V_78 ] ;
F_9 () ;
F_10 (tt_common_entry, node,
head, hash_entry) {
V_25 = F_2 ( V_5 ,
struct V_25 ,
V_24 ) ;
F_49 ( V_72 , L_23
L_24 ,
V_25 -> V_24 . V_34 ,
V_25 -> V_53 ,
V_25 -> V_33 -> V_96 ,
( T_2 ) F_39 (
& V_25 -> V_33 ->
V_97 ) ,
( V_25 -> V_24 . V_35 &
V_60 ? 'R' : '.' ) ,
( V_25 -> V_24 . V_35 &
V_83 ? 'X' : '.' ) ,
( V_25 -> V_24 . V_35 &
V_55 ? 'W' : '.' ) ) ;
}
F_13 () ;
}
V_51:
if ( V_77 )
F_50 ( V_77 ) ;
return V_79 ;
}
static void F_63 ( struct V_8 * V_8 ,
struct V_25 * V_25 ,
const char * V_84 )
{
if ( ! V_25 )
goto V_51;
F_38 ( V_52 , V_8 ,
L_25 ,
V_25 -> V_24 . V_34 , V_25 -> V_33 -> V_96 ,
V_84 ) ;
F_61 ( & V_25 -> V_33 -> V_95 ) ;
F_64 ( V_8 -> V_26 , F_1 , F_8 ,
V_25 -> V_24 . V_34 ) ;
V_51:
if ( V_25 )
F_24 ( V_25 ) ;
}
void F_65 ( struct V_8 * V_8 ,
struct V_33 * V_33 , const unsigned char * V_34 ,
const char * V_84 , bool V_85 )
{
struct V_25 * V_25 = NULL ;
struct V_22 * V_22 = NULL ;
V_25 = F_15 ( V_8 , V_34 ) ;
if ( ! V_25 )
goto V_51;
if ( V_25 -> V_33 == V_33 ) {
if ( V_85 ) {
V_22 = F_14 ( V_8 ,
V_25 -> V_24 . V_34 ) ;
if ( ! V_22 ) {
V_25 -> V_24 . V_35 |= V_60 ;
V_25 -> V_61 = V_30 ;
goto V_51;
}
}
F_63 ( V_8 , V_25 , V_84 ) ;
}
V_51:
if ( V_25 )
F_24 ( V_25 ) ;
if ( V_22 )
F_18 ( V_22 ) ;
}
void F_66 ( struct V_8 * V_8 ,
struct V_33 * V_33 , const char * V_84 )
{
struct V_25 * V_25 ;
struct V_5 * V_5 ;
T_1 V_78 ;
struct V_12 * V_13 = V_8 -> V_26 ;
struct V_1 * V_2 , * V_67 ;
struct V_15 * V_16 ;
T_4 * V_88 ;
if ( ! V_13 )
return;
for ( V_78 = 0 ; V_78 < V_13 -> V_19 ; V_78 ++ ) {
V_16 = & V_13 -> V_20 [ V_78 ] ;
V_88 = & V_13 -> V_89 [ V_78 ] ;
F_28 ( V_88 ) ;
F_54 (tt_common_entry, node, safe,
head, hash_entry) {
V_25 = F_2 ( V_5 ,
struct V_25 ,
V_24 ) ;
if ( V_25 -> V_33 == V_33 ) {
F_38 ( V_52 , V_8 ,
L_26
L_27 ,
V_25 -> V_24 . V_34 ,
V_25 -> V_33 -> V_96 ,
V_84 ) ;
F_56 ( V_2 ) ;
F_24 ( V_25 ) ;
}
}
F_31 ( V_88 ) ;
}
F_32 ( & V_33 -> V_95 , 0 ) ;
}
static void F_67 ( struct V_8 * V_8 )
{
struct V_12 * V_13 = V_8 -> V_26 ;
struct V_5 * V_5 ;
struct V_25 * V_25 ;
struct V_1 * V_2 , * V_87 ;
struct V_15 * V_16 ;
T_4 * V_88 ;
T_1 V_78 ;
for ( V_78 = 0 ; V_78 < V_13 -> V_19 ; V_78 ++ ) {
V_16 = & V_13 -> V_20 [ V_78 ] ;
V_88 = & V_13 -> V_89 [ V_78 ] ;
F_28 ( V_88 ) ;
F_54 (tt_common_entry, node, node_tmp,
head, hash_entry) {
V_25 = F_2 ( V_5 ,
struct V_25 ,
V_24 ) ;
if ( ! ( V_25 -> V_24 . V_35 & V_60 ) )
continue;
if ( ! F_16 ( V_25 -> V_61 ,
V_98 * 1000 ) )
continue;
F_38 ( V_52 , V_8 , L_28
L_29 ,
V_25 -> V_24 . V_34 ) ;
F_61 ( & V_25 -> V_33 -> V_95 ) ;
F_56 ( V_2 ) ;
F_24 ( V_25 ) ;
}
F_31 ( V_88 ) ;
}
}
static void F_68 ( struct V_8 * V_8 )
{
struct V_12 * V_13 ;
T_4 * V_88 ;
struct V_5 * V_5 ;
struct V_25 * V_25 ;
struct V_1 * V_2 , * V_87 ;
struct V_15 * V_16 ;
T_1 V_78 ;
if ( ! V_8 -> V_26 )
return;
V_13 = V_8 -> V_26 ;
for ( V_78 = 0 ; V_78 < V_13 -> V_19 ; V_78 ++ ) {
V_16 = & V_13 -> V_20 [ V_78 ] ;
V_88 = & V_13 -> V_89 [ V_78 ] ;
F_28 ( V_88 ) ;
F_54 (tt_common_entry, node, node_tmp,
head, hash_entry) {
F_56 ( V_2 ) ;
V_25 = F_2 ( V_5 ,
struct V_25 ,
V_24 ) ;
F_24 ( V_25 ) ;
}
F_31 ( V_88 ) ;
}
F_57 ( V_13 ) ;
V_8 -> V_26 = NULL ;
}
static bool F_69 ( struct V_22 * V_22 ,
struct V_25 * V_25 )
{
bool V_79 = false ;
if ( V_22 -> V_24 . V_35 & V_55 &&
V_25 -> V_24 . V_35 & V_55 )
V_79 = true ;
return V_79 ;
}
struct V_33 * F_70 ( struct V_8 * V_8 ,
const T_2 * V_99 , const T_2 * V_34 )
{
struct V_22 * V_22 = NULL ;
struct V_25 * V_25 = NULL ;
struct V_33 * V_33 = NULL ;
if ( V_99 && F_39 ( & V_8 -> V_100 ) ) {
V_22 = F_14 ( V_8 , V_99 ) ;
if ( ! V_22 )
goto V_51;
}
V_25 = F_15 ( V_8 , V_34 ) ;
if ( ! V_25 )
goto V_51;
if ( V_22 && F_69 ( V_22 , V_25 ) )
goto V_51;
if ( ! F_12 ( & V_25 -> V_33 -> V_21 ) )
goto V_51;
if ( V_25 -> V_24 . V_35 & V_83 )
goto V_51;
V_33 = V_25 -> V_33 ;
V_51:
if ( V_25 )
F_24 ( V_25 ) ;
if ( V_22 )
F_18 ( V_22 ) ;
return V_33 ;
}
T_3 F_71 ( struct V_8 * V_8 , struct V_33 * V_33 )
{
T_3 V_101 = 0 , V_102 ;
struct V_12 * V_13 = V_8 -> V_26 ;
struct V_5 * V_5 ;
struct V_25 * V_25 ;
struct V_1 * V_2 ;
struct V_15 * V_16 ;
T_1 V_78 ;
int V_103 ;
for ( V_78 = 0 ; V_78 < V_13 -> V_19 ; V_78 ++ ) {
V_16 = & V_13 -> V_20 [ V_78 ] ;
F_9 () ;
F_10 (tt_common_entry, node,
head, hash_entry) {
V_25 = F_2 ( V_5 ,
struct V_25 ,
V_24 ) ;
if ( F_11 ( V_25 -> V_33 ,
V_33 ) ) {
if ( V_5 -> V_35 & V_60 )
continue;
V_102 = 0 ;
for ( V_103 = 0 ; V_103 < V_7 ; V_103 ++ )
V_102 = F_72 ( V_102 ,
V_5 -> V_34 [ V_103 ] ) ;
V_101 ^= V_102 ;
}
}
F_13 () ;
}
return V_101 ;
}
T_3 F_73 ( struct V_8 * V_8 )
{
T_3 V_101 = 0 , V_102 ;
struct V_12 * V_13 = V_8 -> V_23 ;
struct V_5 * V_5 ;
struct V_1 * V_2 ;
struct V_15 * V_16 ;
T_1 V_78 ;
int V_103 ;
for ( V_78 = 0 ; V_78 < V_13 -> V_19 ; V_78 ++ ) {
V_16 = & V_13 -> V_20 [ V_78 ] ;
F_9 () ;
F_10 (tt_common_entry, node,
head, hash_entry) {
if ( V_5 -> V_35 & V_58 )
continue;
V_102 = 0 ;
for ( V_103 = 0 ; V_103 < V_7 ; V_103 ++ )
V_102 = F_72 ( V_102 ,
V_5 -> V_34 [ V_103 ] ) ;
V_101 ^= V_102 ;
}
F_13 () ;
}
return V_101 ;
}
static void F_74 ( struct V_8 * V_8 )
{
struct V_104 * V_2 , * V_67 ;
F_28 ( & V_8 -> V_105 ) ;
F_45 (node, safe, &bat_priv->tt_req_list, list) {
F_46 ( & V_2 -> V_40 ) ;
F_23 ( V_2 ) ;
}
F_31 ( & V_8 -> V_105 ) ;
}
void F_75 ( struct V_8 * V_8 , struct V_33 * V_33 ,
const unsigned char * V_69 , T_2 V_106 )
{
T_3 V_70 = F_33 ( V_106 ) ;
F_28 ( & V_33 -> V_68 ) ;
if ( V_70 > 0 ) {
F_23 ( V_33 -> V_69 ) ;
V_33 -> V_70 = 0 ;
V_33 -> V_69 = F_27 ( V_70 , V_37 ) ;
if ( V_33 -> V_69 ) {
memcpy ( V_33 -> V_69 , V_69 , V_70 ) ;
V_33 -> V_70 = V_70 ;
}
}
F_31 ( & V_33 -> V_68 ) ;
}
static void F_76 ( struct V_8 * V_8 )
{
struct V_104 * V_2 , * V_67 ;
F_28 ( & V_8 -> V_105 ) ;
F_45 (node, safe, &bat_priv->tt_req_list, list) {
if ( F_16 ( V_2 -> V_107 ,
V_108 * 1000 ) ) {
F_46 ( & V_2 -> V_40 ) ;
F_23 ( V_2 ) ;
}
}
F_31 ( & V_8 -> V_105 ) ;
}
static struct V_104 * F_77 ( struct V_8 * V_8 ,
struct V_33 * V_33 )
{
struct V_104 * V_109 , * V_104 = NULL ;
F_28 ( & V_8 -> V_105 ) ;
F_78 (tt_req_node_tmp, &bat_priv->tt_req_list, list) {
if ( F_11 ( V_109 , V_33 ) &&
! F_16 ( V_109 -> V_107 ,
V_108 * 1000 ) )
goto V_110;
}
V_104 = F_27 ( sizeof( * V_104 ) , V_37 ) ;
if ( ! V_104 )
goto V_110;
memcpy ( V_104 -> V_34 , V_33 -> V_96 , V_7 ) ;
V_104 -> V_107 = V_30 ;
F_79 ( & V_104 -> V_40 , & V_8 -> V_111 ) ;
V_110:
F_31 ( & V_8 -> V_105 ) ;
return V_104 ;
}
static int F_80 ( const void * V_112 , const void * V_113 )
{
const struct V_5 * V_5 = V_112 ;
if ( V_5 -> V_35 & V_58 )
return 0 ;
return 1 ;
}
static int F_81 ( const void * V_112 , const void * V_113 )
{
const struct V_5 * V_5 = V_112 ;
const struct V_25 * V_25 ;
const struct V_33 * V_33 = V_113 ;
if ( V_5 -> V_35 & V_60 )
return 0 ;
V_25 = F_2 ( V_5 , struct V_25 ,
V_24 ) ;
return ( V_25 -> V_33 == V_33 ) ;
}
static struct V_114 * F_82 ( T_3 F_33 , T_2 V_53 ,
struct V_12 * V_13 ,
struct V_76 * V_77 ,
int (* F_83)( const void * ,
const void * ) ,
void * V_115 )
{
struct V_5 * V_5 ;
struct V_116 * V_117 ;
struct V_45 * V_45 ;
struct V_1 * V_2 ;
struct V_15 * V_16 ;
struct V_114 * V_118 = NULL ;
T_3 V_119 , V_120 ;
T_5 V_121 = sizeof( struct V_116 ) ;
T_1 V_78 ;
if ( V_121 + F_33 > V_77 -> V_47 -> V_122 ) {
F_33 = V_77 -> V_47 -> V_122 - V_121 ;
F_33 -= F_33 % sizeof( struct V_45 ) ;
}
V_119 = F_33 / sizeof( struct V_45 ) ;
V_118 = F_84 ( V_121 + F_33 + V_123 ) ;
if ( ! V_118 )
goto V_51;
F_85 ( V_118 , V_123 ) ;
V_117 = (struct V_116 * ) F_86 ( V_118 ,
V_121 + F_33 ) ;
V_117 -> V_53 = V_53 ;
V_45 = (struct V_45 * ) ( V_118 -> V_14 + V_121 ) ;
V_120 = 0 ;
F_9 () ;
for ( V_78 = 0 ; V_78 < V_13 -> V_19 ; V_78 ++ ) {
V_16 = & V_13 -> V_20 [ V_78 ] ;
F_10 (tt_common_entry, node,
head, hash_entry) {
if ( V_120 == V_119 )
break;
if ( ( F_83 ) && ( ! F_83 ( V_5 , V_115 ) ) )
continue;
memcpy ( V_45 -> V_34 , V_5 -> V_34 ,
V_7 ) ;
V_45 -> V_35 = V_54 ;
V_120 ++ ;
V_45 ++ ;
}
}
F_13 () ;
V_117 -> V_124 = F_87 ( V_120 ) ;
V_51:
return V_118 ;
}
static int F_88 ( struct V_8 * V_8 ,
struct V_33 * V_125 ,
T_2 V_53 , T_3 V_126 , bool V_127 )
{
struct V_114 * V_118 = NULL ;
struct V_116 * V_128 ;
struct V_129 * V_129 = NULL ;
struct V_76 * V_77 ;
struct V_104 * V_104 = NULL ;
int V_79 = 1 ;
V_77 = F_48 ( V_8 ) ;
if ( ! V_77 )
goto V_51;
V_104 = F_77 ( V_8 , V_125 ) ;
if ( ! V_104 )
goto V_51;
V_118 = F_84 ( sizeof( struct V_116 ) + V_123 ) ;
if ( ! V_118 )
goto V_51;
F_85 ( V_118 , V_123 ) ;
V_128 = (struct V_116 * ) F_86 ( V_118 ,
sizeof( struct V_116 ) ) ;
V_128 -> V_130 = V_131 ;
V_128 -> V_132 = V_133 ;
memcpy ( V_128 -> V_99 , V_77 -> V_74 -> V_56 , V_7 ) ;
memcpy ( V_128 -> V_134 , V_125 -> V_96 , V_7 ) ;
V_128 -> V_135 = V_136 ;
V_128 -> V_53 = V_53 ;
V_128 -> V_124 = V_126 ;
V_128 -> V_35 = V_137 ;
if ( V_127 )
V_128 -> V_35 |= V_138 ;
V_129 = F_89 ( V_125 ) ;
if ( ! V_129 )
goto V_51;
F_38 ( V_52 , V_8 , L_30
L_31 , V_125 -> V_96 , V_129 -> V_34 ,
( V_127 ? 'F' : '.' ) ) ;
F_90 ( V_118 , V_129 -> V_139 , V_129 -> V_34 ) ;
V_79 = 0 ;
V_51:
if ( V_129 )
F_91 ( V_129 ) ;
if ( V_77 )
F_50 ( V_77 ) ;
if ( V_79 )
F_92 ( V_118 ) ;
if ( V_79 && V_104 ) {
F_28 ( & V_8 -> V_105 ) ;
F_46 ( & V_104 -> V_40 ) ;
F_31 ( & V_8 -> V_105 ) ;
F_23 ( V_104 ) ;
}
return V_79 ;
}
static bool F_93 ( struct V_8 * V_8 ,
struct V_116 * V_128 )
{
struct V_33 * V_140 = NULL , * V_141 = NULL ;
struct V_129 * V_129 = NULL ;
struct V_76 * V_77 = NULL ;
T_2 V_142 , V_143 , V_53 ;
int V_79 = false ;
unsigned char * V_69 ;
bool V_127 ;
T_3 F_33 , V_119 ;
struct V_114 * V_118 = NULL ;
struct V_116 * V_117 ;
F_38 ( V_52 , V_8 ,
L_32
L_33 , V_128 -> V_99 ,
V_128 -> V_53 , V_128 -> V_134 ,
( V_128 -> V_35 & V_138 ? 'F' : '.' ) ) ;
V_140 = F_94 ( V_8 , V_128 -> V_134 ) ;
if ( ! V_140 )
goto V_51;
V_141 = F_94 ( V_8 , V_128 -> V_99 ) ;
if ( ! V_141 )
goto V_51;
V_129 = F_89 ( V_141 ) ;
if ( ! V_129 )
goto V_51;
V_77 = F_48 ( V_8 ) ;
if ( ! V_77 )
goto V_51;
V_142 = ( T_2 ) F_39 ( & V_140 -> V_97 ) ;
V_143 = V_128 -> V_53 ;
if ( V_142 != V_143 ||
V_128 -> V_124 != V_140 -> V_126 )
goto V_51;
if ( V_128 -> V_35 & V_138 ||
! V_140 -> V_69 )
V_127 = true ;
else
V_127 = false ;
if ( ! V_127 ) {
F_28 ( & V_140 -> V_68 ) ;
F_33 = V_140 -> V_70 ;
V_119 = F_33 / sizeof( struct V_45 ) ;
V_118 = F_84 ( sizeof( struct V_116 ) +
F_33 + V_123 ) ;
if ( ! V_118 )
goto V_110;
F_85 ( V_118 , V_123 ) ;
V_117 = (struct V_116 * ) F_86 ( V_118 ,
sizeof( struct V_116 ) + F_33 ) ;
V_117 -> V_53 = V_143 ;
V_117 -> V_124 = F_87 ( V_119 ) ;
V_69 = V_118 -> V_14 + sizeof( struct V_116 ) ;
memcpy ( V_69 , V_140 -> V_69 ,
V_140 -> V_70 ) ;
F_31 ( & V_140 -> V_68 ) ;
} else {
F_33 = ( T_3 ) F_39 ( & V_140 -> V_95 ) *
sizeof( struct V_45 ) ;
V_53 = ( T_2 ) F_39 ( & V_140 -> V_97 ) ;
V_118 = F_82 ( F_33 , V_53 ,
V_8 -> V_26 ,
V_77 , F_81 ,
V_140 ) ;
if ( ! V_118 )
goto V_51;
V_117 = (struct V_116 * ) V_118 -> V_14 ;
}
V_117 -> V_130 = V_131 ;
V_117 -> V_132 = V_133 ;
V_117 -> V_135 = V_136 ;
memcpy ( V_117 -> V_99 , V_140 -> V_96 , V_7 ) ;
memcpy ( V_117 -> V_134 , V_128 -> V_99 , V_7 ) ;
V_117 -> V_35 = V_144 ;
if ( V_127 )
V_117 -> V_35 |= V_138 ;
F_38 ( V_52 , V_8 ,
L_34 ,
V_141 -> V_96 , V_129 -> V_34 ,
V_140 -> V_96 , V_143 ) ;
F_90 ( V_118 , V_129 -> V_139 , V_129 -> V_34 ) ;
V_79 = true ;
goto V_51;
V_110:
F_31 ( & V_140 -> V_68 ) ;
V_51:
if ( V_141 )
F_22 ( V_141 ) ;
if ( V_140 )
F_22 ( V_140 ) ;
if ( V_129 )
F_91 ( V_129 ) ;
if ( V_77 )
F_50 ( V_77 ) ;
if ( ! V_79 )
F_92 ( V_118 ) ;
return V_79 ;
}
static bool F_95 ( struct V_8 * V_8 ,
struct V_116 * V_128 )
{
struct V_33 * V_33 = NULL ;
struct V_129 * V_129 = NULL ;
struct V_76 * V_77 = NULL ;
T_2 V_145 , V_143 , V_53 ;
int V_79 = false ;
unsigned char * V_69 ;
bool V_127 ;
T_3 F_33 , V_119 ;
struct V_114 * V_118 = NULL ;
struct V_116 * V_117 ;
F_38 ( V_52 , V_8 ,
L_32
L_35 , V_128 -> V_99 ,
V_128 -> V_53 ,
( V_128 -> V_35 & V_138 ? 'F' : '.' ) ) ;
V_145 = ( T_2 ) F_39 ( & V_8 -> V_53 ) ;
V_143 = V_128 -> V_53 ;
V_33 = F_94 ( V_8 , V_128 -> V_99 ) ;
if ( ! V_33 )
goto V_51;
V_129 = F_89 ( V_33 ) ;
if ( ! V_129 )
goto V_51;
V_77 = F_48 ( V_8 ) ;
if ( ! V_77 )
goto V_51;
if ( V_128 -> V_35 & V_138 || V_145 != V_143 ||
! V_8 -> V_69 )
V_127 = true ;
else
V_127 = false ;
if ( ! V_127 ) {
F_28 ( & V_8 -> V_68 ) ;
F_33 = V_8 -> V_70 ;
V_119 = F_33 / sizeof( struct V_45 ) ;
V_118 = F_84 ( sizeof( struct V_116 ) +
F_33 + V_123 ) ;
if ( ! V_118 )
goto V_110;
F_85 ( V_118 , V_123 ) ;
V_117 = (struct V_116 * ) F_86 ( V_118 ,
sizeof( struct V_116 ) + F_33 ) ;
V_117 -> V_53 = V_143 ;
V_117 -> V_124 = F_87 ( V_119 ) ;
V_69 = V_118 -> V_14 + sizeof( struct V_116 ) ;
memcpy ( V_69 , V_8 -> V_69 ,
V_8 -> V_70 ) ;
F_31 ( & V_8 -> V_68 ) ;
} else {
F_33 = ( T_3 ) F_39 ( & V_8 -> V_146 ) *
sizeof( struct V_45 ) ;
V_53 = ( T_2 ) F_39 ( & V_8 -> V_53 ) ;
V_118 = F_82 ( F_33 , V_53 ,
V_8 -> V_23 ,
V_77 , F_80 ,
NULL ) ;
if ( ! V_118 )
goto V_51;
V_117 = (struct V_116 * ) V_118 -> V_14 ;
}
V_117 -> V_130 = V_131 ;
V_117 -> V_132 = V_133 ;
V_117 -> V_135 = V_136 ;
memcpy ( V_117 -> V_99 , V_77 -> V_74 -> V_56 , V_7 ) ;
memcpy ( V_117 -> V_134 , V_128 -> V_99 , V_7 ) ;
V_117 -> V_35 = V_144 ;
if ( V_127 )
V_117 -> V_35 |= V_138 ;
F_38 ( V_52 , V_8 ,
L_36 ,
V_33 -> V_96 , V_129 -> V_34 ,
( V_117 -> V_35 & V_138 ? 'F' : '.' ) ) ;
F_90 ( V_118 , V_129 -> V_139 , V_129 -> V_34 ) ;
V_79 = true ;
goto V_51;
V_110:
F_31 ( & V_8 -> V_68 ) ;
V_51:
if ( V_33 )
F_22 ( V_33 ) ;
if ( V_129 )
F_91 ( V_129 ) ;
if ( V_77 )
F_50 ( V_77 ) ;
if ( ! V_79 )
F_92 ( V_118 ) ;
return true ;
}
bool F_96 ( struct V_8 * V_8 ,
struct V_116 * V_128 )
{
if ( F_97 ( V_128 -> V_134 ) )
return F_95 ( V_8 , V_128 ) ;
else
return F_93 ( V_8 , V_128 ) ;
}
static void F_98 ( struct V_8 * V_8 ,
struct V_33 * V_33 ,
struct V_45 * V_45 ,
T_3 V_106 , T_2 V_53 )
{
int V_78 ;
for ( V_78 = 0 ; V_78 < V_106 ; V_78 ++ ) {
if ( ( V_45 + V_78 ) -> V_35 & V_86 )
F_65 ( V_8 , V_33 ,
( V_45 + V_78 ) -> V_34 ,
L_37 ,
( V_45 + V_78 ) -> V_35 & V_60 ) ;
else
if ( ! F_60 ( V_8 , V_33 ,
( V_45 + V_78 ) -> V_34 , V_53 , false ,
( V_45 + V_78 ) -> V_35 &
V_55 ) )
return;
}
}
static void F_99 ( struct V_8 * V_8 ,
struct V_116 * V_117 )
{
struct V_33 * V_33 = NULL ;
V_33 = F_94 ( V_8 , V_117 -> V_99 ) ;
if ( ! V_33 )
goto V_51;
F_66 ( V_8 , V_33 , L_38 ) ;
F_98 ( V_8 , V_33 ,
(struct V_45 * ) ( V_117 + 1 ) ,
V_117 -> V_124 , V_117 -> V_53 ) ;
F_28 ( & V_33 -> V_68 ) ;
F_23 ( V_33 -> V_69 ) ;
V_33 -> V_70 = 0 ;
V_33 -> V_69 = NULL ;
F_31 ( & V_33 -> V_68 ) ;
F_32 ( & V_33 -> V_97 , V_117 -> V_53 ) ;
V_51:
if ( V_33 )
F_22 ( V_33 ) ;
}
static void F_100 ( struct V_8 * V_8 ,
struct V_33 * V_33 ,
T_3 V_106 , T_2 V_53 ,
struct V_45 * V_45 )
{
F_98 ( V_8 , V_33 , V_45 , V_106 ,
V_53 ) ;
F_75 ( V_8 , V_33 , ( unsigned char * ) V_45 ,
V_106 ) ;
F_32 ( & V_33 -> V_97 , V_53 ) ;
}
bool F_101 ( struct V_8 * V_8 , const T_2 * V_34 )
{
struct V_22 * V_22 = NULL ;
bool V_79 = false ;
V_22 = F_14 ( V_8 , V_34 ) ;
if ( ! V_22 )
goto V_51;
if ( V_22 -> V_24 . V_35 & V_83 )
goto V_51;
V_79 = true ;
V_51:
if ( V_22 )
F_18 ( V_22 ) ;
return V_79 ;
}
void F_102 ( struct V_8 * V_8 ,
struct V_116 * V_117 )
{
struct V_104 * V_2 , * V_67 ;
struct V_33 * V_33 = NULL ;
F_38 ( V_52 , V_8 , L_39
L_40 ,
V_117 -> V_99 , V_117 -> V_53 ,
V_117 -> V_124 ,
( V_117 -> V_35 & V_138 ? 'F' : '.' ) ) ;
V_33 = F_94 ( V_8 , V_117 -> V_99 ) ;
if ( ! V_33 )
goto V_51;
if ( V_117 -> V_35 & V_138 )
F_99 ( V_8 , V_117 ) ;
else
F_100 ( V_8 , V_33 , V_117 -> V_124 ,
V_117 -> V_53 ,
(struct V_45 * ) ( V_117 + 1 ) ) ;
F_28 ( & V_8 -> V_105 ) ;
F_45 (node, safe, &bat_priv->tt_req_list, list) {
if ( ! F_11 ( V_2 -> V_34 , V_117 -> V_99 ) )
continue;
F_46 ( & V_2 -> V_40 ) ;
F_23 ( V_2 ) ;
}
F_31 ( & V_8 -> V_105 ) ;
V_33 -> V_126 = F_71 ( V_8 , V_33 ) ;
V_33 -> V_59 = false ;
V_51:
if ( V_33 )
F_22 ( V_33 ) ;
}
int F_103 ( struct V_8 * V_8 )
{
if ( ! F_34 ( V_8 ) )
return 0 ;
if ( ! F_58 ( V_8 ) )
return 0 ;
F_3 ( V_8 ) ;
return 1 ;
}
static void F_104 ( struct V_8 * V_8 )
{
struct V_147 * V_2 , * V_67 ;
F_28 ( & V_8 -> V_148 ) ;
F_45 (node, safe, &bat_priv->tt_roam_list, list) {
F_46 ( & V_2 -> V_40 ) ;
F_23 ( V_2 ) ;
}
F_31 ( & V_8 -> V_148 ) ;
}
static void F_105 ( struct V_8 * V_8 )
{
struct V_147 * V_2 , * V_67 ;
F_28 ( & V_8 -> V_148 ) ;
F_45 (node, safe, &bat_priv->tt_roam_list, list) {
if ( ! F_16 ( V_2 -> V_149 ,
V_150 * 1000 ) )
continue;
F_46 ( & V_2 -> V_40 ) ;
F_23 ( V_2 ) ;
}
F_31 ( & V_8 -> V_148 ) ;
}
static bool F_106 ( struct V_8 * V_8 ,
T_2 * V_151 )
{
struct V_147 * V_147 ;
bool V_79 = false ;
F_28 ( & V_8 -> V_148 ) ;
F_78 (tt_roam_node, &bat_priv->tt_roam_list, list) {
if ( ! F_11 ( V_147 -> V_34 , V_151 ) )
continue;
if ( F_16 ( V_147 -> V_149 ,
V_150 * 1000 ) )
continue;
if ( ! F_107 ( & V_147 -> V_152 ) )
goto V_110;
V_79 = true ;
break;
}
if ( ! V_79 ) {
V_147 = F_27 ( sizeof( * V_147 ) , V_37 ) ;
if ( ! V_147 )
goto V_110;
V_147 -> V_149 = V_30 ;
F_32 ( & V_147 -> V_152 , V_153 - 1 ) ;
memcpy ( V_147 -> V_34 , V_151 , V_7 ) ;
F_79 ( & V_147 -> V_40 , & V_8 -> V_154 ) ;
V_79 = true ;
}
V_110:
F_31 ( & V_8 -> V_148 ) ;
return V_79 ;
}
void F_43 ( struct V_8 * V_8 , T_2 * V_151 ,
struct V_33 * V_33 )
{
struct V_129 * V_129 = NULL ;
struct V_114 * V_118 = NULL ;
struct V_155 * V_155 ;
int V_79 = 1 ;
struct V_76 * V_77 ;
if ( ! F_106 ( V_8 , V_151 ) )
goto V_51;
V_118 = F_84 ( sizeof( struct V_155 ) + V_123 ) ;
if ( ! V_118 )
goto V_51;
F_85 ( V_118 , V_123 ) ;
V_155 = (struct V_155 * ) F_86 ( V_118 ,
sizeof( struct V_155 ) ) ;
V_155 -> V_130 = V_156 ;
V_155 -> V_132 = V_133 ;
V_155 -> V_135 = V_136 ;
V_77 = F_48 ( V_8 ) ;
if ( ! V_77 )
goto V_51;
memcpy ( V_155 -> V_99 , V_77 -> V_74 -> V_56 , V_7 ) ;
F_50 ( V_77 ) ;
memcpy ( V_155 -> V_134 , V_33 -> V_96 , V_7 ) ;
memcpy ( V_155 -> V_151 , V_151 , V_7 ) ;
V_129 = F_89 ( V_33 ) ;
if ( ! V_129 )
goto V_51;
F_38 ( V_52 , V_8 ,
L_41 ,
V_33 -> V_96 , V_151 , V_129 -> V_34 ) ;
F_90 ( V_118 , V_129 -> V_139 , V_129 -> V_34 ) ;
V_79 = 0 ;
V_51:
if ( V_129 )
F_91 ( V_129 ) ;
if ( V_79 )
F_92 ( V_118 ) ;
return;
}
static void V_10 ( struct V_157 * V_158 )
{
struct V_159 * V_159 =
F_2 ( V_158 , struct V_159 , V_158 ) ;
struct V_8 * V_8 =
F_2 ( V_159 , struct V_8 , V_9 ) ;
F_53 ( V_8 ) ;
F_67 ( V_8 ) ;
F_76 ( V_8 ) ;
F_105 ( V_8 ) ;
F_3 ( V_8 ) ;
}
void F_108 ( struct V_8 * V_8 )
{
F_109 ( & V_8 -> V_9 ) ;
F_55 ( V_8 ) ;
F_68 ( V_8 ) ;
F_74 ( V_8 ) ;
F_59 ( V_8 ) ;
F_104 ( V_8 ) ;
F_23 ( V_8 -> V_69 ) ;
}
static T_3 F_110 ( struct V_12 * V_13 , T_3 V_35 ,
bool V_160 )
{
T_1 V_78 ;
T_3 V_161 = 0 ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
struct V_5 * V_5 ;
if ( ! V_13 )
goto V_51;
for ( V_78 = 0 ; V_78 < V_13 -> V_19 ; V_78 ++ ) {
V_16 = & V_13 -> V_20 [ V_78 ] ;
F_9 () ;
F_10 (tt_common_entry, node,
head, hash_entry) {
if ( V_160 ) {
if ( ( V_5 -> V_35 & V_35 ) == V_35 )
continue;
V_5 -> V_35 |= V_35 ;
} else {
if ( ! ( V_5 -> V_35 & V_35 ) )
continue;
V_5 -> V_35 &= ~ V_35 ;
}
V_161 ++ ;
}
F_13 () ;
}
V_51:
return V_161 ;
}
static void F_111 ( struct V_8 * V_8 )
{
struct V_12 * V_13 = V_8 -> V_23 ;
struct V_5 * V_5 ;
struct V_22 * V_22 ;
struct V_1 * V_2 , * V_87 ;
struct V_15 * V_16 ;
T_4 * V_88 ;
T_1 V_78 ;
if ( ! V_13 )
return;
for ( V_78 = 0 ; V_78 < V_13 -> V_19 ; V_78 ++ ) {
V_16 = & V_13 -> V_20 [ V_78 ] ;
V_88 = & V_13 -> V_89 [ V_78 ] ;
F_28 ( V_88 ) ;
F_54 (tt_common_entry, node, node_tmp,
head, hash_entry) {
if ( ! ( V_5 -> V_35 & V_83 ) )
continue;
F_38 ( V_52 , V_8 , L_42
L_43 , V_5 -> V_34 ) ;
F_61 ( & V_8 -> V_146 ) ;
F_56 ( V_2 ) ;
V_22 = F_2 ( V_5 ,
struct V_22 ,
V_24 ) ;
F_18 ( V_22 ) ;
}
F_31 ( V_88 ) ;
}
}
void F_112 ( struct V_8 * V_8 )
{
T_3 V_161 = F_110 ( V_8 -> V_23 ,
V_58 , false ) ;
F_113 ( V_161 , & V_8 -> V_146 ) ;
F_111 ( V_8 ) ;
F_30 ( & V_8 -> V_53 ) ;
V_8 -> V_59 = false ;
}
bool F_114 ( struct V_8 * V_8 , T_2 * V_99 , T_2 * V_134 )
{
struct V_22 * V_22 = NULL ;
struct V_25 * V_25 = NULL ;
bool V_79 = true ;
if ( ! F_39 ( & V_8 -> V_100 ) )
return false ;
V_22 = F_14 ( V_8 , V_134 ) ;
if ( ! V_22 )
goto V_51;
V_25 = F_15 ( V_8 , V_99 ) ;
if ( ! V_25 )
goto V_51;
if ( F_69 ( V_22 , V_25 ) )
goto V_51;
V_79 = false ;
V_51:
if ( V_25 )
F_24 ( V_25 ) ;
if ( V_22 )
F_18 ( V_22 ) ;
return V_79 ;
}
void F_115 ( struct V_8 * V_8 , struct V_33 * V_33 ,
const unsigned char * V_69 , T_2 V_106 ,
T_2 V_53 , T_3 V_126 )
{
T_2 V_142 = ( T_2 ) F_39 ( & V_33 -> V_97 ) ;
bool V_127 = true ;
if ( V_53 - V_142 == 1 ) {
if ( ! V_106 ) {
V_127 = false ;
goto V_162;
}
F_100 ( V_8 , V_33 , V_106 , V_53 ,
(struct V_45 * ) V_69 ) ;
V_33 -> V_126 = F_71 ( V_8 , V_33 ) ;
if ( V_33 -> V_126 != V_126 )
goto V_162;
V_33 -> V_59 = false ;
} else {
if ( V_53 != V_142 || V_33 -> V_126 != V_126 ) {
V_162:
F_38 ( V_52 , V_8 , L_44
L_45
L_46
L_47 , V_33 -> V_96 , V_53 ,
V_142 , V_126 , V_33 -> V_126 ,
V_106 ) ;
F_88 ( V_8 , V_33 , V_53 , V_126 ,
V_127 ) ;
return;
}
}
}
