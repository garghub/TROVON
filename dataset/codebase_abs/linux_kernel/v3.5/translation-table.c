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
F_20 ( V_25 ) ;
}
static void F_21 ( struct V_25 * V_25 )
{
if ( F_17 ( & V_25 -> V_24 . V_21 ) ) {
F_22 ( V_25 ) ;
F_23 ( & V_25 -> V_24 . V_27 ,
F_19 ) ;
}
}
static void F_24 ( struct V_28 * V_27 )
{
struct V_29 * V_30 ;
V_30 = F_2 ( V_27 , struct V_29 , V_27 ) ;
F_25 ( V_30 -> V_31 ) ;
F_20 ( V_30 ) ;
}
static void F_26 ( struct V_29 * V_30 )
{
F_27 ( & V_30 -> V_31 -> V_32 ) ;
F_23 ( & V_30 -> V_27 , F_24 ) ;
}
static void F_28 ( struct V_8 * V_8 , const T_2 * V_33 ,
T_2 V_34 )
{
struct V_35 * V_35 ;
V_35 = F_29 ( sizeof( * V_35 ) , V_36 ) ;
if ( ! V_35 )
return;
V_35 -> V_37 . V_34 = V_34 ;
memcpy ( V_35 -> V_37 . V_33 , V_33 , V_7 ) ;
F_30 ( & V_8 -> V_38 ) ;
F_31 ( & V_35 -> V_39 , & V_8 -> V_40 ) ;
F_32 ( & V_8 -> V_41 ) ;
F_33 ( & V_8 -> V_38 ) ;
F_34 ( & V_8 -> V_42 , 0 ) ;
}
int F_35 ( int V_43 )
{
return V_43 * sizeof( struct V_44 ) ;
}
static int F_36 ( struct V_8 * V_8 )
{
if ( V_8 -> V_23 )
return 1 ;
V_8 -> V_23 = F_37 ( 1024 ) ;
if ( ! V_8 -> V_23 )
return 0 ;
return 1 ;
}
void F_38 ( struct V_45 * V_46 , const T_2 * V_33 ,
int V_47 )
{
struct V_8 * V_8 = F_39 ( V_46 ) ;
struct V_22 * V_22 = NULL ;
struct V_25 * V_25 = NULL ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
struct V_29 * V_30 ;
int V_48 ;
V_22 = F_14 ( V_8 , V_33 ) ;
if ( V_22 ) {
V_22 -> V_49 = V_50 ;
V_22 -> V_24 . V_34 &= ~ V_51 ;
goto V_52;
}
V_22 = F_29 ( sizeof( * V_22 ) , V_36 ) ;
if ( ! V_22 )
goto V_52;
F_40 ( V_53 , V_8 ,
L_1 , V_33 ,
( T_2 ) F_41 ( & V_8 -> V_54 ) ) ;
memcpy ( V_22 -> V_24 . V_33 , V_33 , V_7 ) ;
V_22 -> V_24 . V_34 = V_55 ;
if ( F_42 ( V_47 ) )
V_22 -> V_24 . V_34 |= V_56 ;
F_34 ( & V_22 -> V_24 . V_21 , 2 ) ;
V_22 -> V_49 = V_50 ;
if ( F_11 ( V_33 , V_46 -> V_57 ) )
V_22 -> V_24 . V_34 |= V_58 ;
V_22 -> V_24 . V_34 |= V_59 ;
V_48 = F_43 ( V_8 -> V_23 , F_1 , F_8 ,
& V_22 -> V_24 ,
& V_22 -> V_24 . V_6 ) ;
if ( F_44 ( V_48 != 0 ) ) {
F_16 ( V_22 ) ;
goto V_52;
}
F_28 ( V_8 , V_33 , V_22 -> V_24 . V_34 ) ;
V_25 = F_15 ( V_8 , V_33 ) ;
if ( V_25 ) {
V_16 = & V_25 -> V_60 ;
F_9 () ;
F_10 (orig_entry, node, head, list) {
V_30 -> V_31 -> V_61 = true ;
F_45 ( V_8 , V_25 -> V_24 . V_33 ,
V_30 -> V_31 ) ;
}
F_13 () ;
V_25 -> V_24 . V_34 |= V_62 ;
V_25 -> V_63 = V_50 ;
}
V_52:
if ( V_22 )
F_16 ( V_22 ) ;
if ( V_25 )
F_21 ( V_25 ) ;
}
int F_46 ( struct V_8 * V_8 ,
unsigned char * V_64 , int V_65 )
{
int V_66 = 0 , V_67 = 0 ;
struct V_35 * V_68 , * V_69 ;
if ( V_65 > 0 )
V_67 = V_65 / F_35 ( 1 ) ;
F_30 ( & V_8 -> V_38 ) ;
F_34 ( & V_8 -> V_41 , 0 ) ;
F_47 (entry, safe, &bat_priv->tt_changes_list,
list) {
if ( V_66 < V_67 ) {
memcpy ( V_64 + F_35 ( V_66 ) ,
& V_68 -> V_37 , sizeof( struct V_44 ) ) ;
V_66 ++ ;
}
F_48 ( & V_68 -> V_39 ) ;
F_20 ( V_68 ) ;
}
F_33 ( & V_8 -> V_38 ) ;
F_30 ( & V_8 -> V_70 ) ;
F_20 ( V_8 -> V_71 ) ;
V_8 -> V_72 = 0 ;
V_8 -> V_71 = NULL ;
if ( V_65 > 0 ) {
V_8 -> V_71 = F_29 ( V_65 , V_36 ) ;
if ( V_8 -> V_71 ) {
memcpy ( V_8 -> V_71 , V_64 , V_65 ) ;
V_8 -> V_72 = V_65 ;
}
}
F_33 ( & V_8 -> V_70 ) ;
return V_67 ;
}
int F_49 ( struct V_73 * V_74 , void * V_75 )
{
struct V_45 * V_76 = (struct V_45 * ) V_74 -> V_77 ;
struct V_8 * V_8 = F_39 ( V_76 ) ;
struct V_12 * V_13 = V_8 -> V_23 ;
struct V_5 * V_5 ;
struct V_78 * V_79 ;
struct V_1 * V_2 ;
struct V_15 * V_16 ;
T_1 V_80 ;
int V_81 = 0 ;
V_79 = F_50 ( V_8 ) ;
if ( ! V_79 ) {
V_81 = F_51 ( V_74 ,
L_2 ,
V_76 -> V_82 ) ;
goto V_52;
}
if ( V_79 -> V_83 != V_84 ) {
V_81 = F_51 ( V_74 ,
L_3 ,
V_76 -> V_82 ) ;
goto V_52;
}
F_51 ( V_74 ,
L_4 ,
V_76 -> V_82 , ( T_2 ) F_41 ( & V_8 -> V_54 ) ) ;
for ( V_80 = 0 ; V_80 < V_13 -> V_19 ; V_80 ++ ) {
V_16 = & V_13 -> V_20 [ V_80 ] ;
F_9 () ;
F_10 (tt_common_entry, node,
head, hash_entry) {
F_51 ( V_74 , L_5 ,
V_5 -> V_33 ,
( V_5 -> V_34 &
V_62 ? 'R' : '.' ) ,
( V_5 -> V_34 &
V_58 ? 'P' : '.' ) ,
( V_5 -> V_34 &
V_59 ? 'N' : '.' ) ,
( V_5 -> V_34 &
V_51 ? 'X' : '.' ) ,
( V_5 -> V_34 &
V_56 ? 'W' : '.' ) ) ;
}
F_13 () ;
}
V_52:
if ( V_79 )
F_52 ( V_79 ) ;
return V_81 ;
}
static void F_53 ( struct V_8 * V_8 ,
struct V_22 * V_22 ,
T_3 V_34 , const char * V_85 )
{
F_28 ( V_8 , V_22 -> V_24 . V_33 ,
V_22 -> V_24 . V_34 | V_34 ) ;
V_22 -> V_24 . V_34 |= V_51 ;
F_40 ( V_53 , V_8 ,
L_6 ,
V_22 -> V_24 . V_33 , V_85 ) ;
}
void F_54 ( struct V_8 * V_8 , const T_2 * V_33 ,
const char * V_85 , bool V_86 )
{
struct V_22 * V_22 = NULL ;
V_22 = F_14 ( V_8 , V_33 ) ;
if ( ! V_22 )
goto V_52;
F_53 ( V_8 , V_22 , V_87 |
( V_86 ? V_62 : V_55 ) , V_85 ) ;
V_52:
if ( V_22 )
F_16 ( V_22 ) ;
}
static void F_55 ( struct V_8 * V_8 )
{
struct V_12 * V_13 = V_8 -> V_23 ;
struct V_22 * V_22 ;
struct V_5 * V_5 ;
struct V_1 * V_2 , * V_88 ;
struct V_15 * V_16 ;
T_4 * V_89 ;
T_1 V_80 ;
for ( V_80 = 0 ; V_80 < V_13 -> V_19 ; V_80 ++ ) {
V_16 = & V_13 -> V_20 [ V_80 ] ;
V_89 = & V_13 -> V_90 [ V_80 ] ;
F_30 ( V_89 ) ;
F_56 (tt_common_entry, node, node_tmp,
head, hash_entry) {
V_22 = F_2 ( V_5 ,
struct V_22 ,
V_24 ) ;
if ( V_22 -> V_24 . V_34 & V_58 )
continue;
if ( V_22 -> V_24 . V_34 & V_51 )
continue;
if ( ! F_57 ( V_22 -> V_49 ,
V_91 ) )
continue;
F_53 ( V_8 , V_22 ,
V_87 , L_7 ) ;
}
F_33 ( V_89 ) ;
}
}
static void F_58 ( struct V_8 * V_8 )
{
struct V_12 * V_13 ;
T_4 * V_89 ;
struct V_5 * V_5 ;
struct V_22 * V_22 ;
struct V_1 * V_2 , * V_88 ;
struct V_15 * V_16 ;
T_1 V_80 ;
if ( ! V_8 -> V_23 )
return;
V_13 = V_8 -> V_23 ;
for ( V_80 = 0 ; V_80 < V_13 -> V_19 ; V_80 ++ ) {
V_16 = & V_13 -> V_20 [ V_80 ] ;
V_89 = & V_13 -> V_90 [ V_80 ] ;
F_30 ( V_89 ) ;
F_56 (tt_common_entry, node, node_tmp,
head, hash_entry) {
F_59 ( V_2 ) ;
V_22 = F_2 ( V_5 ,
struct V_22 ,
V_24 ) ;
F_16 ( V_22 ) ;
}
F_33 ( V_89 ) ;
}
F_60 ( V_13 ) ;
V_8 -> V_23 = NULL ;
}
static int F_61 ( struct V_8 * V_8 )
{
if ( V_8 -> V_26 )
return 1 ;
V_8 -> V_26 = F_37 ( 1024 ) ;
if ( ! V_8 -> V_26 )
return 0 ;
return 1 ;
}
static void F_62 ( struct V_8 * V_8 )
{
struct V_35 * V_68 , * V_69 ;
F_30 ( & V_8 -> V_38 ) ;
F_47 (entry, safe, &bat_priv->tt_changes_list,
list) {
F_48 ( & V_68 -> V_39 ) ;
F_20 ( V_68 ) ;
}
F_34 ( & V_8 -> V_41 , 0 ) ;
F_33 ( & V_8 -> V_38 ) ;
}
static bool F_63 ( const struct V_25 * V_68 ,
const struct V_31 * V_31 )
{
struct V_29 * V_92 ;
const struct V_15 * V_16 ;
struct V_1 * V_2 ;
bool V_93 = false ;
F_9 () ;
V_16 = & V_68 -> V_60 ;
F_10 (tmp_orig_entry, node, head, list) {
if ( V_92 -> V_31 == V_31 ) {
V_93 = true ;
break;
}
}
F_13 () ;
return V_93 ;
}
static void F_64 ( struct V_25 * V_25 ,
struct V_31 * V_31 ,
int V_54 )
{
struct V_29 * V_30 ;
V_30 = F_65 ( sizeof( * V_30 ) , V_36 ) ;
if ( ! V_30 )
return;
F_66 ( & V_30 -> V_39 ) ;
F_32 ( & V_31 -> V_21 ) ;
F_32 ( & V_31 -> V_32 ) ;
V_30 -> V_31 = V_31 ;
V_30 -> V_54 = V_54 ;
F_30 ( & V_25 -> V_89 ) ;
F_67 ( & V_30 -> V_39 ,
& V_25 -> V_60 ) ;
F_33 ( & V_25 -> V_89 ) ;
}
int F_68 ( struct V_8 * V_8 , struct V_31 * V_31 ,
const unsigned char * V_94 , T_2 V_54 , bool V_86 ,
bool V_95 )
{
struct V_25 * V_25 = NULL ;
int V_81 = 0 ;
int V_48 ;
V_25 = F_15 ( V_8 , V_94 ) ;
if ( ! V_25 ) {
V_25 = F_65 ( sizeof( * V_25 ) ,
V_36 ) ;
if ( ! V_25 )
goto V_52;
memcpy ( V_25 -> V_24 . V_33 , V_94 , V_7 ) ;
V_25 -> V_24 . V_34 = V_55 ;
V_25 -> V_63 = 0 ;
F_34 ( & V_25 -> V_24 . V_21 , 2 ) ;
F_69 ( & V_25 -> V_60 ) ;
F_70 ( & V_25 -> V_89 ) ;
V_48 = F_43 ( V_8 -> V_26 , F_1 ,
F_8 , & V_25 -> V_24 ,
& V_25 -> V_24 . V_6 ) ;
if ( F_44 ( V_48 != 0 ) ) {
F_21 ( V_25 ) ;
goto V_96;
}
F_64 ( V_25 , V_31 , V_54 ) ;
} else {
if ( V_25 -> V_24 . V_34 & V_62 ) {
F_22 ( V_25 ) ;
V_25 -> V_24 . V_34 &= ~ V_62 ;
V_25 -> V_63 = 0 ;
}
if ( ! F_63 ( V_25 , V_31 ) )
F_64 ( V_25 , V_31 ,
V_54 ) ;
}
if ( V_95 )
V_25 -> V_24 . V_34 |= V_56 ;
F_40 ( V_53 , V_8 ,
L_8 ,
V_25 -> V_24 . V_33 , V_31 -> V_97 ) ;
V_96:
F_54 ( V_8 , V_25 -> V_24 . V_33 ,
L_9 , V_86 ) ;
V_81 = 1 ;
V_52:
if ( V_25 )
F_21 ( V_25 ) ;
return V_81 ;
}
static void F_71 ( struct V_25 * V_25 ,
struct V_73 * V_74 )
{
struct V_15 * V_16 ;
struct V_1 * V_2 ;
struct V_29 * V_30 ;
struct V_5 * V_5 ;
T_3 V_34 ;
T_2 V_98 ;
V_5 = & V_25 -> V_24 ;
V_16 = & V_25 -> V_60 ;
F_10 (orig_entry, node, head, list) {
V_34 = V_5 -> V_34 ;
V_98 = F_41 ( & V_30 -> V_31 -> V_98 ) ;
F_51 ( V_74 , L_10 ,
V_25 -> V_24 . V_33 , V_30 -> V_54 ,
V_30 -> V_31 -> V_97 , V_98 ,
( V_34 & V_62 ? 'R' : '.' ) ,
( V_34 & V_56 ? 'W' : '.' ) ) ;
}
}
int F_72 ( struct V_73 * V_74 , void * V_75 )
{
struct V_45 * V_76 = (struct V_45 * ) V_74 -> V_77 ;
struct V_8 * V_8 = F_39 ( V_76 ) ;
struct V_12 * V_13 = V_8 -> V_26 ;
struct V_5 * V_5 ;
struct V_25 * V_25 ;
struct V_78 * V_79 ;
struct V_1 * V_2 ;
struct V_15 * V_16 ;
T_1 V_80 ;
int V_81 = 0 ;
V_79 = F_50 ( V_8 ) ;
if ( ! V_79 ) {
V_81 = F_51 ( V_74 ,
L_2 ,
V_76 -> V_82 ) ;
goto V_52;
}
if ( V_79 -> V_83 != V_84 ) {
V_81 = F_51 ( V_74 ,
L_3 ,
V_76 -> V_82 ) ;
goto V_52;
}
F_51 ( V_74 ,
L_11 ,
V_76 -> V_82 ) ;
F_51 ( V_74 , L_12 ,
L_13 , L_14 , L_15 , L_16 , L_17 ) ;
for ( V_80 = 0 ; V_80 < V_13 -> V_19 ; V_80 ++ ) {
V_16 = & V_13 -> V_20 [ V_80 ] ;
F_9 () ;
F_10 (tt_common_entry, node,
head, hash_entry) {
V_25 = F_2 ( V_5 ,
struct V_25 ,
V_24 ) ;
F_71 ( V_25 , V_74 ) ;
}
F_13 () ;
}
V_52:
if ( V_79 )
F_52 ( V_79 ) ;
return V_81 ;
}
static void F_22 ( struct V_25 * V_25 )
{
struct V_15 * V_16 ;
struct V_1 * V_2 , * V_69 ;
struct V_29 * V_30 ;
F_30 ( & V_25 -> V_89 ) ;
V_16 = & V_25 -> V_60 ;
F_56 (orig_entry, node, safe, head, list) {
F_59 ( V_2 ) ;
F_26 ( V_30 ) ;
}
F_33 ( & V_25 -> V_89 ) ;
}
static void F_73 ( struct V_8 * V_8 ,
struct V_25 * V_25 ,
struct V_31 * V_31 ,
const char * V_85 )
{
struct V_15 * V_16 ;
struct V_1 * V_2 , * V_69 ;
struct V_29 * V_30 ;
F_30 ( & V_25 -> V_89 ) ;
V_16 = & V_25 -> V_60 ;
F_56 (orig_entry, node, safe, head, list) {
if ( V_30 -> V_31 == V_31 ) {
F_40 ( V_53 , V_8 ,
L_18 ,
V_31 -> V_97 , V_25 -> V_24 . V_33 ,
V_85 ) ;
F_59 ( V_2 ) ;
F_26 ( V_30 ) ;
}
}
F_33 ( & V_25 -> V_89 ) ;
}
static void F_74 ( struct V_8 * V_8 ,
struct V_25 * V_25 ,
const char * V_85 )
{
F_40 ( V_53 , V_8 ,
L_19 ,
V_25 -> V_24 . V_33 , V_85 ) ;
F_75 ( V_8 -> V_26 , F_1 , F_8 ,
V_25 -> V_24 . V_33 ) ;
F_21 ( V_25 ) ;
}
static void F_76 ( struct V_8 * V_8 ,
struct V_25 * V_25 ,
struct V_31 * V_31 ,
const char * V_85 )
{
bool V_99 = true ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
struct V_29 * V_30 ;
F_9 () ;
V_16 = & V_25 -> V_60 ;
F_10 (orig_entry, node, head, list) {
if ( V_30 -> V_31 != V_31 ) {
V_99 = false ;
break;
}
}
F_13 () ;
if ( V_99 ) {
V_25 -> V_24 . V_34 |= V_62 ;
V_25 -> V_63 = V_50 ;
} else
F_73 ( V_8 , V_25 ,
V_31 , V_85 ) ;
}
static void F_77 ( struct V_8 * V_8 ,
struct V_31 * V_31 ,
const unsigned char * V_33 ,
const char * V_85 , bool V_86 )
{
struct V_25 * V_25 = NULL ;
struct V_22 * V_22 = NULL ;
V_25 = F_15 ( V_8 , V_33 ) ;
if ( ! V_25 )
goto V_52;
if ( ! V_86 ) {
F_73 ( V_8 , V_25 , V_31 ,
V_85 ) ;
if ( F_78 ( & V_25 -> V_60 ) )
F_74 ( V_8 , V_25 ,
V_85 ) ;
goto V_52;
}
V_22 = F_14 ( V_8 ,
V_25 -> V_24 . V_33 ) ;
if ( V_22 ) {
F_22 ( V_25 ) ;
F_74 ( V_8 , V_25 , V_85 ) ;
} else
F_76 ( V_8 , V_25 , V_31 ,
V_85 ) ;
V_52:
if ( V_25 )
F_21 ( V_25 ) ;
if ( V_22 )
F_16 ( V_22 ) ;
}
void F_79 ( struct V_8 * V_8 ,
struct V_31 * V_31 , const char * V_85 )
{
struct V_25 * V_25 ;
struct V_5 * V_5 ;
T_1 V_80 ;
struct V_12 * V_13 = V_8 -> V_26 ;
struct V_1 * V_2 , * V_69 ;
struct V_15 * V_16 ;
T_4 * V_89 ;
if ( ! V_13 )
return;
for ( V_80 = 0 ; V_80 < V_13 -> V_19 ; V_80 ++ ) {
V_16 = & V_13 -> V_20 [ V_80 ] ;
V_89 = & V_13 -> V_90 [ V_80 ] ;
F_30 ( V_89 ) ;
F_56 (tt_common_entry, node, safe,
head, hash_entry) {
V_25 = F_2 ( V_5 ,
struct V_25 ,
V_24 ) ;
F_73 ( V_8 , V_25 ,
V_31 , V_85 ) ;
if ( F_78 ( & V_25 -> V_60 ) ) {
F_40 ( V_53 , V_8 ,
L_19 ,
V_25 -> V_24 . V_33 ,
V_85 ) ;
F_59 ( V_2 ) ;
F_21 ( V_25 ) ;
}
}
F_33 ( V_89 ) ;
}
V_31 -> V_100 = false ;
}
static void F_80 ( struct V_8 * V_8 )
{
struct V_12 * V_13 = V_8 -> V_26 ;
struct V_5 * V_5 ;
struct V_25 * V_25 ;
struct V_1 * V_2 , * V_88 ;
struct V_15 * V_16 ;
T_4 * V_89 ;
T_1 V_80 ;
for ( V_80 = 0 ; V_80 < V_13 -> V_19 ; V_80 ++ ) {
V_16 = & V_13 -> V_20 [ V_80 ] ;
V_89 = & V_13 -> V_90 [ V_80 ] ;
F_30 ( V_89 ) ;
F_56 (tt_common_entry, node, node_tmp,
head, hash_entry) {
V_25 = F_2 ( V_5 ,
struct V_25 ,
V_24 ) ;
if ( ! ( V_25 -> V_24 . V_34 & V_62 ) )
continue;
if ( ! F_57 ( V_25 -> V_63 ,
V_101 ) )
continue;
F_40 ( V_53 , V_8 ,
L_20 ,
V_25 -> V_24 . V_33 ) ;
F_59 ( V_2 ) ;
F_21 ( V_25 ) ;
}
F_33 ( V_89 ) ;
}
}
static void F_81 ( struct V_8 * V_8 )
{
struct V_12 * V_13 ;
T_4 * V_89 ;
struct V_5 * V_5 ;
struct V_25 * V_25 ;
struct V_1 * V_2 , * V_88 ;
struct V_15 * V_16 ;
T_1 V_80 ;
if ( ! V_8 -> V_26 )
return;
V_13 = V_8 -> V_26 ;
for ( V_80 = 0 ; V_80 < V_13 -> V_19 ; V_80 ++ ) {
V_16 = & V_13 -> V_20 [ V_80 ] ;
V_89 = & V_13 -> V_90 [ V_80 ] ;
F_30 ( V_89 ) ;
F_56 (tt_common_entry, node, node_tmp,
head, hash_entry) {
F_59 ( V_2 ) ;
V_25 = F_2 ( V_5 ,
struct V_25 ,
V_24 ) ;
F_21 ( V_25 ) ;
}
F_33 ( V_89 ) ;
}
F_60 ( V_13 ) ;
V_8 -> V_26 = NULL ;
}
static bool F_82 ( struct V_22 * V_22 ,
struct V_25 * V_25 )
{
bool V_81 = false ;
if ( V_22 -> V_24 . V_34 & V_56 &&
V_25 -> V_24 . V_34 & V_56 )
V_81 = true ;
return V_81 ;
}
struct V_31 * F_83 ( struct V_8 * V_8 ,
const T_2 * V_102 , const T_2 * V_33 )
{
struct V_22 * V_22 = NULL ;
struct V_25 * V_25 = NULL ;
struct V_31 * V_31 = NULL ;
struct V_103 * V_104 = NULL ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
struct V_29 * V_30 ;
int V_105 ;
if ( V_102 && F_41 ( & V_8 -> V_106 ) ) {
V_22 = F_14 ( V_8 , V_102 ) ;
if ( ! V_22 )
goto V_52;
}
V_25 = F_15 ( V_8 , V_33 ) ;
if ( ! V_25 )
goto V_52;
if ( V_22 && F_82 ( V_22 , V_25 ) )
goto V_52;
V_105 = 0 ;
F_9 () ;
V_16 = & V_25 -> V_60 ;
F_10 (orig_entry, node, head, list) {
V_104 = F_84 ( V_30 -> V_31 ) ;
if ( ! V_104 )
continue;
if ( V_104 -> V_107 > V_105 ) {
V_31 = V_30 -> V_31 ;
V_105 = V_104 -> V_107 ;
}
F_85 ( V_104 ) ;
}
if ( V_31 && ! F_12 ( & V_31 -> V_21 ) )
V_31 = NULL ;
F_13 () ;
V_52:
if ( V_25 )
F_21 ( V_25 ) ;
if ( V_22 )
F_16 ( V_22 ) ;
return V_31 ;
}
static T_3 F_86 ( struct V_8 * V_8 ,
struct V_31 * V_31 )
{
T_3 V_108 = 0 , V_109 ;
struct V_12 * V_13 = V_8 -> V_26 ;
struct V_5 * V_5 ;
struct V_25 * V_25 ;
struct V_1 * V_2 ;
struct V_15 * V_16 ;
T_1 V_80 ;
int V_110 ;
for ( V_80 = 0 ; V_80 < V_13 -> V_19 ; V_80 ++ ) {
V_16 = & V_13 -> V_20 [ V_80 ] ;
F_9 () ;
F_10 (tt_common_entry, node,
head, hash_entry) {
V_25 = F_2 ( V_5 ,
struct V_25 ,
V_24 ) ;
if ( V_25 -> V_24 . V_34 & V_62 )
continue;
if ( ! F_63 ( V_25 ,
V_31 ) )
continue;
V_109 = 0 ;
for ( V_110 = 0 ; V_110 < V_7 ; V_110 ++ )
V_109 = F_87 ( V_109 ,
V_25 -> V_24 . V_33 [ V_110 ] ) ;
V_108 ^= V_109 ;
}
F_13 () ;
}
return V_108 ;
}
T_3 F_88 ( struct V_8 * V_8 )
{
T_3 V_108 = 0 , V_109 ;
struct V_12 * V_13 = V_8 -> V_23 ;
struct V_5 * V_5 ;
struct V_1 * V_2 ;
struct V_15 * V_16 ;
T_1 V_80 ;
int V_110 ;
for ( V_80 = 0 ; V_80 < V_13 -> V_19 ; V_80 ++ ) {
V_16 = & V_13 -> V_20 [ V_80 ] ;
F_9 () ;
F_10 (tt_common_entry, node,
head, hash_entry) {
if ( V_5 -> V_34 & V_59 )
continue;
V_109 = 0 ;
for ( V_110 = 0 ; V_110 < V_7 ; V_110 ++ )
V_109 = F_87 ( V_109 ,
V_5 -> V_33 [ V_110 ] ) ;
V_108 ^= V_109 ;
}
F_13 () ;
}
return V_108 ;
}
static void F_89 ( struct V_8 * V_8 )
{
struct V_111 * V_2 , * V_69 ;
F_30 ( & V_8 -> V_112 ) ;
F_47 (node, safe, &bat_priv->tt_req_list, list) {
F_48 ( & V_2 -> V_39 ) ;
F_20 ( V_2 ) ;
}
F_33 ( & V_8 -> V_112 ) ;
}
static void F_90 ( struct V_8 * V_8 ,
struct V_31 * V_31 ,
const unsigned char * V_71 ,
T_2 V_113 )
{
T_3 V_72 = F_35 ( V_113 ) ;
F_30 ( & V_31 -> V_70 ) ;
if ( V_72 > 0 ) {
F_20 ( V_31 -> V_71 ) ;
V_31 -> V_72 = 0 ;
V_31 -> V_71 = F_29 ( V_72 , V_36 ) ;
if ( V_31 -> V_71 ) {
memcpy ( V_31 -> V_71 , V_71 , V_72 ) ;
V_31 -> V_72 = V_72 ;
}
}
F_33 ( & V_31 -> V_70 ) ;
}
static void F_91 ( struct V_8 * V_8 )
{
struct V_111 * V_2 , * V_69 ;
F_30 ( & V_8 -> V_112 ) ;
F_47 (node, safe, &bat_priv->tt_req_list, list) {
if ( F_57 ( V_2 -> V_114 , V_115 ) ) {
F_48 ( & V_2 -> V_39 ) ;
F_20 ( V_2 ) ;
}
}
F_33 ( & V_8 -> V_112 ) ;
}
static struct V_111 * F_92 ( struct V_8 * V_8 ,
struct V_31 * V_31 )
{
struct V_111 * V_116 , * V_111 = NULL ;
F_30 ( & V_8 -> V_112 ) ;
F_93 (tt_req_node_tmp, &bat_priv->tt_req_list, list) {
if ( F_11 ( V_116 , V_31 ) &&
! F_57 ( V_116 -> V_114 ,
V_115 ) )
goto V_117;
}
V_111 = F_29 ( sizeof( * V_111 ) , V_36 ) ;
if ( ! V_111 )
goto V_117;
memcpy ( V_111 -> V_33 , V_31 -> V_97 , V_7 ) ;
V_111 -> V_114 = V_50 ;
F_94 ( & V_111 -> V_39 , & V_8 -> V_118 ) ;
V_117:
F_33 ( & V_8 -> V_112 ) ;
return V_111 ;
}
static int F_95 ( const void * V_119 , const void * V_120 )
{
const struct V_5 * V_5 = V_119 ;
if ( V_5 -> V_34 & V_59 )
return 0 ;
return 1 ;
}
static int F_96 ( const void * V_119 , const void * V_120 )
{
const struct V_5 * V_5 = V_119 ;
const struct V_25 * V_25 ;
const struct V_31 * V_31 = V_120 ;
if ( V_5 -> V_34 & V_62 )
return 0 ;
V_25 = F_2 ( V_5 , struct V_25 ,
V_24 ) ;
return F_63 ( V_25 , V_31 ) ;
}
static struct V_121 * F_97 ( T_3 F_35 , T_2 V_54 ,
struct V_12 * V_13 ,
struct V_78 * V_79 ,
int (* F_98)( const void * ,
const void * ) ,
void * V_122 )
{
struct V_5 * V_5 ;
struct V_123 * V_124 ;
struct V_44 * V_44 ;
struct V_1 * V_2 ;
struct V_15 * V_16 ;
struct V_121 * V_125 = NULL ;
T_3 V_126 , V_127 ;
T_5 V_128 = sizeof( struct V_123 ) ;
T_1 V_80 ;
if ( V_128 + F_35 > V_79 -> V_46 -> V_129 ) {
F_35 = V_79 -> V_46 -> V_129 - V_128 ;
F_35 -= F_35 % sizeof( struct V_44 ) ;
}
V_126 = F_35 / sizeof( struct V_44 ) ;
V_125 = F_99 ( V_128 + F_35 + V_130 ) ;
if ( ! V_125 )
goto V_52;
F_100 ( V_125 , V_130 ) ;
V_124 = (struct V_123 * ) F_101 ( V_125 ,
V_128 + F_35 ) ;
V_124 -> V_54 = V_54 ;
V_44 = (struct V_44 * ) ( V_125 -> V_14 + V_128 ) ;
V_127 = 0 ;
F_9 () ;
for ( V_80 = 0 ; V_80 < V_13 -> V_19 ; V_80 ++ ) {
V_16 = & V_13 -> V_20 [ V_80 ] ;
F_10 (tt_common_entry, node,
head, hash_entry) {
if ( V_127 == V_126 )
break;
if ( ( F_98 ) && ( ! F_98 ( V_5 , V_122 ) ) )
continue;
memcpy ( V_44 -> V_33 , V_5 -> V_33 ,
V_7 ) ;
V_44 -> V_34 = V_55 ;
V_127 ++ ;
V_44 ++ ;
}
}
F_13 () ;
V_124 -> V_131 = F_102 ( V_127 ) ;
V_52:
return V_125 ;
}
static int F_103 ( struct V_8 * V_8 ,
struct V_31 * V_132 ,
T_2 V_54 , T_3 V_133 , bool V_134 )
{
struct V_121 * V_125 = NULL ;
struct V_123 * V_135 ;
struct V_103 * V_103 = NULL ;
struct V_78 * V_79 ;
struct V_111 * V_111 = NULL ;
int V_81 = 1 ;
V_79 = F_50 ( V_8 ) ;
if ( ! V_79 )
goto V_52;
V_111 = F_92 ( V_8 , V_132 ) ;
if ( ! V_111 )
goto V_52;
V_125 = F_99 ( sizeof( struct V_123 ) + V_130 ) ;
if ( ! V_125 )
goto V_52;
F_100 ( V_125 , V_130 ) ;
V_135 = (struct V_123 * ) F_101 ( V_125 ,
sizeof( struct V_123 ) ) ;
V_135 -> V_136 . V_137 = V_138 ;
V_135 -> V_136 . V_139 = V_140 ;
memcpy ( V_135 -> V_102 , V_79 -> V_76 -> V_57 , V_7 ) ;
memcpy ( V_135 -> V_141 , V_132 -> V_97 , V_7 ) ;
V_135 -> V_136 . V_142 = V_143 ;
V_135 -> V_54 = V_54 ;
V_135 -> V_131 = F_102 ( V_133 ) ;
V_135 -> V_34 = V_144 ;
if ( V_134 )
V_135 -> V_34 |= V_145 ;
V_103 = F_84 ( V_132 ) ;
if ( ! V_103 )
goto V_52;
F_40 ( V_53 , V_8 ,
L_21 ,
V_132 -> V_97 , V_103 -> V_33 ,
( V_134 ? 'F' : '.' ) ) ;
F_104 ( V_125 , V_103 -> V_146 , V_103 -> V_33 ) ;
V_81 = 0 ;
V_52:
if ( V_103 )
F_85 ( V_103 ) ;
if ( V_79 )
F_52 ( V_79 ) ;
if ( V_81 )
F_105 ( V_125 ) ;
if ( V_81 && V_111 ) {
F_30 ( & V_8 -> V_112 ) ;
F_48 ( & V_111 -> V_39 ) ;
F_33 ( & V_8 -> V_112 ) ;
F_20 ( V_111 ) ;
}
return V_81 ;
}
static bool F_106 ( struct V_8 * V_8 ,
struct V_123 * V_135 )
{
struct V_31 * V_147 = NULL , * V_148 = NULL ;
struct V_103 * V_103 = NULL ;
struct V_78 * V_79 = NULL ;
T_2 V_149 , V_150 , V_54 ;
int V_81 = false ;
unsigned char * V_71 ;
bool V_134 ;
T_3 F_35 , V_126 ;
struct V_121 * V_125 = NULL ;
struct V_123 * V_124 ;
F_40 ( V_53 , V_8 ,
L_22 ,
V_135 -> V_102 , V_135 -> V_54 , V_135 -> V_141 ,
( V_135 -> V_34 & V_145 ? 'F' : '.' ) ) ;
V_147 = F_107 ( V_8 , V_135 -> V_141 ) ;
if ( ! V_147 )
goto V_52;
V_148 = F_107 ( V_8 , V_135 -> V_102 ) ;
if ( ! V_148 )
goto V_52;
V_103 = F_84 ( V_148 ) ;
if ( ! V_103 )
goto V_52;
V_79 = F_50 ( V_8 ) ;
if ( ! V_79 )
goto V_52;
V_149 = ( T_2 ) F_41 ( & V_147 -> V_98 ) ;
V_150 = V_135 -> V_54 ;
if ( V_149 != V_150 ||
V_135 -> V_131 != V_147 -> V_133 )
goto V_52;
if ( V_135 -> V_34 & V_145 ||
! V_147 -> V_71 )
V_134 = true ;
else
V_134 = false ;
if ( ! V_134 ) {
F_30 ( & V_147 -> V_70 ) ;
F_35 = V_147 -> V_72 ;
V_126 = F_35 / sizeof( struct V_44 ) ;
V_125 = F_99 ( sizeof( struct V_123 ) +
F_35 + V_130 ) ;
if ( ! V_125 )
goto V_117;
F_100 ( V_125 , V_130 ) ;
V_124 = (struct V_123 * ) F_101 ( V_125 ,
sizeof( struct V_123 ) + F_35 ) ;
V_124 -> V_54 = V_150 ;
V_124 -> V_131 = F_102 ( V_126 ) ;
V_71 = V_125 -> V_14 + sizeof( struct V_123 ) ;
memcpy ( V_71 , V_147 -> V_71 ,
V_147 -> V_72 ) ;
F_33 ( & V_147 -> V_70 ) ;
} else {
F_35 = ( T_3 ) F_41 ( & V_147 -> V_32 ) *
sizeof( struct V_44 ) ;
V_54 = ( T_2 ) F_41 ( & V_147 -> V_98 ) ;
V_125 = F_97 ( F_35 , V_54 ,
V_8 -> V_26 ,
V_79 , F_96 ,
V_147 ) ;
if ( ! V_125 )
goto V_52;
V_124 = (struct V_123 * ) V_125 -> V_14 ;
}
V_124 -> V_136 . V_137 = V_138 ;
V_124 -> V_136 . V_139 = V_140 ;
V_124 -> V_136 . V_142 = V_143 ;
memcpy ( V_124 -> V_102 , V_147 -> V_97 , V_7 ) ;
memcpy ( V_124 -> V_141 , V_135 -> V_102 , V_7 ) ;
V_124 -> V_34 = V_151 ;
if ( V_134 )
V_124 -> V_34 |= V_145 ;
F_40 ( V_53 , V_8 ,
L_23 ,
V_148 -> V_97 , V_103 -> V_33 ,
V_147 -> V_97 , V_150 ) ;
F_104 ( V_125 , V_103 -> V_146 , V_103 -> V_33 ) ;
V_81 = true ;
goto V_52;
V_117:
F_33 ( & V_147 -> V_70 ) ;
V_52:
if ( V_148 )
F_25 ( V_148 ) ;
if ( V_147 )
F_25 ( V_147 ) ;
if ( V_103 )
F_85 ( V_103 ) ;
if ( V_79 )
F_52 ( V_79 ) ;
if ( ! V_81 )
F_105 ( V_125 ) ;
return V_81 ;
}
static bool F_108 ( struct V_8 * V_8 ,
struct V_123 * V_135 )
{
struct V_31 * V_31 = NULL ;
struct V_103 * V_103 = NULL ;
struct V_78 * V_79 = NULL ;
T_2 V_152 , V_150 , V_54 ;
int V_81 = false ;
unsigned char * V_71 ;
bool V_134 ;
T_3 F_35 , V_126 ;
struct V_121 * V_125 = NULL ;
struct V_123 * V_124 ;
F_40 ( V_53 , V_8 ,
L_24 ,
V_135 -> V_102 , V_135 -> V_54 ,
( V_135 -> V_34 & V_145 ? 'F' : '.' ) ) ;
V_152 = ( T_2 ) F_41 ( & V_8 -> V_54 ) ;
V_150 = V_135 -> V_54 ;
V_31 = F_107 ( V_8 , V_135 -> V_102 ) ;
if ( ! V_31 )
goto V_52;
V_103 = F_84 ( V_31 ) ;
if ( ! V_103 )
goto V_52;
V_79 = F_50 ( V_8 ) ;
if ( ! V_79 )
goto V_52;
if ( V_135 -> V_34 & V_145 || V_152 != V_150 ||
! V_8 -> V_71 )
V_134 = true ;
else
V_134 = false ;
if ( ! V_134 ) {
F_30 ( & V_8 -> V_70 ) ;
F_35 = V_8 -> V_72 ;
V_126 = F_35 / sizeof( struct V_44 ) ;
V_125 = F_99 ( sizeof( struct V_123 ) +
F_35 + V_130 ) ;
if ( ! V_125 )
goto V_117;
F_100 ( V_125 , V_130 ) ;
V_124 = (struct V_123 * ) F_101 ( V_125 ,
sizeof( struct V_123 ) + F_35 ) ;
V_124 -> V_54 = V_150 ;
V_124 -> V_131 = F_102 ( V_126 ) ;
V_71 = V_125 -> V_14 + sizeof( struct V_123 ) ;
memcpy ( V_71 , V_8 -> V_71 ,
V_8 -> V_72 ) ;
F_33 ( & V_8 -> V_70 ) ;
} else {
F_35 = ( T_3 ) F_41 ( & V_8 -> V_153 ) *
sizeof( struct V_44 ) ;
V_54 = ( T_2 ) F_41 ( & V_8 -> V_54 ) ;
V_125 = F_97 ( F_35 , V_54 ,
V_8 -> V_23 ,
V_79 , F_95 ,
NULL ) ;
if ( ! V_125 )
goto V_52;
V_124 = (struct V_123 * ) V_125 -> V_14 ;
}
V_124 -> V_136 . V_137 = V_138 ;
V_124 -> V_136 . V_139 = V_140 ;
V_124 -> V_136 . V_142 = V_143 ;
memcpy ( V_124 -> V_102 , V_79 -> V_76 -> V_57 , V_7 ) ;
memcpy ( V_124 -> V_141 , V_135 -> V_102 , V_7 ) ;
V_124 -> V_34 = V_151 ;
if ( V_134 )
V_124 -> V_34 |= V_145 ;
F_40 ( V_53 , V_8 ,
L_25 ,
V_31 -> V_97 , V_103 -> V_33 ,
( V_124 -> V_34 & V_145 ? 'F' : '.' ) ) ;
F_104 ( V_125 , V_103 -> V_146 , V_103 -> V_33 ) ;
V_81 = true ;
goto V_52;
V_117:
F_33 ( & V_8 -> V_70 ) ;
V_52:
if ( V_31 )
F_25 ( V_31 ) ;
if ( V_103 )
F_85 ( V_103 ) ;
if ( V_79 )
F_52 ( V_79 ) ;
if ( ! V_81 )
F_105 ( V_125 ) ;
return true ;
}
bool F_109 ( struct V_8 * V_8 ,
struct V_123 * V_135 )
{
if ( F_110 ( V_135 -> V_141 ) ) {
if ( F_111 ( V_8 , V_135 -> V_102 ) )
return true ;
return F_108 ( V_8 , V_135 ) ;
} else {
return F_106 ( V_8 , V_135 ) ;
}
}
static void F_112 ( struct V_8 * V_8 ,
struct V_31 * V_31 ,
struct V_44 * V_44 ,
T_3 V_113 , T_2 V_54 )
{
int V_80 ;
for ( V_80 = 0 ; V_80 < V_113 ; V_80 ++ ) {
if ( ( V_44 + V_80 ) -> V_34 & V_87 )
F_77 ( V_8 , V_31 ,
( V_44 + V_80 ) -> V_33 ,
L_26 ,
( V_44 + V_80 ) -> V_34 & V_62 ) ;
else
if ( ! F_68 ( V_8 , V_31 ,
( V_44 + V_80 ) -> V_33 , V_54 , false ,
( V_44 + V_80 ) -> V_34 &
V_56 ) )
return;
}
V_31 -> V_100 = true ;
}
static void F_113 ( struct V_8 * V_8 ,
struct V_123 * V_124 )
{
struct V_31 * V_31 = NULL ;
V_31 = F_107 ( V_8 , V_124 -> V_102 ) ;
if ( ! V_31 )
goto V_52;
F_79 ( V_8 , V_31 , L_27 ) ;
F_112 ( V_8 , V_31 ,
(struct V_44 * ) ( V_124 + 1 ) ,
V_124 -> V_131 , V_124 -> V_54 ) ;
F_30 ( & V_31 -> V_70 ) ;
F_20 ( V_31 -> V_71 ) ;
V_31 -> V_72 = 0 ;
V_31 -> V_71 = NULL ;
F_33 ( & V_31 -> V_70 ) ;
F_34 ( & V_31 -> V_98 , V_124 -> V_54 ) ;
V_52:
if ( V_31 )
F_25 ( V_31 ) ;
}
static void F_114 ( struct V_8 * V_8 ,
struct V_31 * V_31 ,
T_3 V_113 , T_2 V_54 ,
struct V_44 * V_44 )
{
F_112 ( V_8 , V_31 , V_44 , V_113 ,
V_54 ) ;
F_90 ( V_8 , V_31 , ( unsigned char * ) V_44 ,
V_113 ) ;
F_34 ( & V_31 -> V_98 , V_54 ) ;
}
bool F_115 ( struct V_8 * V_8 , const T_2 * V_33 )
{
struct V_22 * V_22 = NULL ;
bool V_81 = false ;
V_22 = F_14 ( V_8 , V_33 ) ;
if ( ! V_22 )
goto V_52;
if ( V_22 -> V_24 . V_34 & V_51 )
goto V_52;
V_81 = true ;
V_52:
if ( V_22 )
F_16 ( V_22 ) ;
return V_81 ;
}
void F_116 ( struct V_8 * V_8 ,
struct V_123 * V_124 )
{
struct V_111 * V_2 , * V_69 ;
struct V_31 * V_31 = NULL ;
F_40 ( V_53 , V_8 ,
L_28 ,
V_124 -> V_102 , V_124 -> V_54 , V_124 -> V_131 ,
( V_124 -> V_34 & V_145 ? 'F' : '.' ) ) ;
if ( F_111 ( V_8 , V_124 -> V_102 ) )
goto V_52;
V_31 = F_107 ( V_8 , V_124 -> V_102 ) ;
if ( ! V_31 )
goto V_52;
if ( V_124 -> V_34 & V_145 )
F_113 ( V_8 , V_124 ) ;
else
F_114 ( V_8 , V_31 , V_124 -> V_131 ,
V_124 -> V_54 ,
(struct V_44 * ) ( V_124 + 1 ) ) ;
F_30 ( & V_8 -> V_112 ) ;
F_47 (node, safe, &bat_priv->tt_req_list, list) {
if ( ! F_11 ( V_2 -> V_33 , V_124 -> V_102 ) )
continue;
F_48 ( & V_2 -> V_39 ) ;
F_20 ( V_2 ) ;
}
F_33 ( & V_8 -> V_112 ) ;
V_31 -> V_133 = F_86 ( V_8 , V_31 ) ;
V_31 -> V_61 = false ;
V_52:
if ( V_31 )
F_25 ( V_31 ) ;
}
int F_117 ( struct V_8 * V_8 )
{
if ( ! F_36 ( V_8 ) )
return 0 ;
if ( ! F_61 ( V_8 ) )
return 0 ;
F_3 ( V_8 ) ;
return 1 ;
}
static void F_118 ( struct V_8 * V_8 )
{
struct V_154 * V_2 , * V_69 ;
F_30 ( & V_8 -> V_155 ) ;
F_47 (node, safe, &bat_priv->tt_roam_list, list) {
F_48 ( & V_2 -> V_39 ) ;
F_20 ( V_2 ) ;
}
F_33 ( & V_8 -> V_155 ) ;
}
static void F_119 ( struct V_8 * V_8 )
{
struct V_154 * V_2 , * V_69 ;
F_30 ( & V_8 -> V_155 ) ;
F_47 (node, safe, &bat_priv->tt_roam_list, list) {
if ( ! F_57 ( V_2 -> V_156 , V_157 ) )
continue;
F_48 ( & V_2 -> V_39 ) ;
F_20 ( V_2 ) ;
}
F_33 ( & V_8 -> V_155 ) ;
}
static bool F_120 ( struct V_8 * V_8 ,
T_2 * V_158 )
{
struct V_154 * V_154 ;
bool V_81 = false ;
F_30 ( & V_8 -> V_155 ) ;
F_93 (tt_roam_node, &bat_priv->tt_roam_list, list) {
if ( ! F_11 ( V_154 -> V_33 , V_158 ) )
continue;
if ( F_57 ( V_154 -> V_156 , V_157 ) )
continue;
if ( ! F_121 ( & V_154 -> V_159 ) )
goto V_117;
V_81 = true ;
break;
}
if ( ! V_81 ) {
V_154 = F_29 ( sizeof( * V_154 ) , V_36 ) ;
if ( ! V_154 )
goto V_117;
V_154 -> V_156 = V_50 ;
F_34 ( & V_154 -> V_159 , V_160 - 1 ) ;
memcpy ( V_154 -> V_33 , V_158 , V_7 ) ;
F_94 ( & V_154 -> V_39 , & V_8 -> V_161 ) ;
V_81 = true ;
}
V_117:
F_33 ( & V_8 -> V_155 ) ;
return V_81 ;
}
static void F_45 ( struct V_8 * V_8 , T_2 * V_158 ,
struct V_31 * V_31 )
{
struct V_103 * V_103 = NULL ;
struct V_121 * V_125 = NULL ;
struct V_162 * V_162 ;
int V_81 = 1 ;
struct V_78 * V_79 ;
if ( ! F_120 ( V_8 , V_158 ) )
goto V_52;
V_125 = F_99 ( sizeof( struct V_162 ) + V_130 ) ;
if ( ! V_125 )
goto V_52;
F_100 ( V_125 , V_130 ) ;
V_162 = (struct V_162 * ) F_101 ( V_125 ,
sizeof( struct V_162 ) ) ;
V_162 -> V_136 . V_137 = V_163 ;
V_162 -> V_136 . V_139 = V_140 ;
V_162 -> V_136 . V_142 = V_143 ;
V_79 = F_50 ( V_8 ) ;
if ( ! V_79 )
goto V_52;
memcpy ( V_162 -> V_102 , V_79 -> V_76 -> V_57 , V_7 ) ;
F_52 ( V_79 ) ;
memcpy ( V_162 -> V_141 , V_31 -> V_97 , V_7 ) ;
memcpy ( V_162 -> V_158 , V_158 , V_7 ) ;
V_103 = F_84 ( V_31 ) ;
if ( ! V_103 )
goto V_52;
F_40 ( V_53 , V_8 ,
L_29 ,
V_31 -> V_97 , V_158 , V_103 -> V_33 ) ;
F_104 ( V_125 , V_103 -> V_146 , V_103 -> V_33 ) ;
V_81 = 0 ;
V_52:
if ( V_103 )
F_85 ( V_103 ) ;
if ( V_81 )
F_105 ( V_125 ) ;
return;
}
static void V_10 ( struct V_164 * V_165 )
{
struct V_166 * V_166 =
F_2 ( V_165 , struct V_166 , V_165 ) ;
struct V_8 * V_8 =
F_2 ( V_166 , struct V_8 , V_9 ) ;
F_55 ( V_8 ) ;
F_80 ( V_8 ) ;
F_91 ( V_8 ) ;
F_119 ( V_8 ) ;
F_3 ( V_8 ) ;
}
void F_122 ( struct V_8 * V_8 )
{
F_123 ( & V_8 -> V_9 ) ;
F_58 ( V_8 ) ;
F_81 ( V_8 ) ;
F_89 ( V_8 ) ;
F_62 ( V_8 ) ;
F_118 ( V_8 ) ;
F_20 ( V_8 -> V_71 ) ;
}
static T_3 F_124 ( struct V_12 * V_13 , T_3 V_34 ,
bool V_167 )
{
T_1 V_80 ;
T_3 V_168 = 0 ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
struct V_5 * V_5 ;
if ( ! V_13 )
goto V_52;
for ( V_80 = 0 ; V_80 < V_13 -> V_19 ; V_80 ++ ) {
V_16 = & V_13 -> V_20 [ V_80 ] ;
F_9 () ;
F_10 (tt_common_entry, node,
head, hash_entry) {
if ( V_167 ) {
if ( ( V_5 -> V_34 & V_34 ) == V_34 )
continue;
V_5 -> V_34 |= V_34 ;
} else {
if ( ! ( V_5 -> V_34 & V_34 ) )
continue;
V_5 -> V_34 &= ~ V_34 ;
}
V_168 ++ ;
}
F_13 () ;
}
V_52:
return V_168 ;
}
static void F_125 ( struct V_8 * V_8 )
{
struct V_12 * V_13 = V_8 -> V_23 ;
struct V_5 * V_5 ;
struct V_22 * V_22 ;
struct V_1 * V_2 , * V_88 ;
struct V_15 * V_16 ;
T_4 * V_89 ;
T_1 V_80 ;
if ( ! V_13 )
return;
for ( V_80 = 0 ; V_80 < V_13 -> V_19 ; V_80 ++ ) {
V_16 = & V_13 -> V_20 [ V_80 ] ;
V_89 = & V_13 -> V_90 [ V_80 ] ;
F_30 ( V_89 ) ;
F_56 (tt_common_entry, node, node_tmp,
head, hash_entry) {
if ( ! ( V_5 -> V_34 & V_51 ) )
continue;
F_40 ( V_53 , V_8 ,
L_30 ,
V_5 -> V_33 ) ;
F_27 ( & V_8 -> V_153 ) ;
F_59 ( V_2 ) ;
V_22 = F_2 ( V_5 ,
struct V_22 ,
V_24 ) ;
F_16 ( V_22 ) ;
}
F_33 ( V_89 ) ;
}
}
void F_126 ( struct V_8 * V_8 )
{
T_3 V_168 = F_124 ( V_8 -> V_23 ,
V_59 , false ) ;
F_127 ( V_168 , & V_8 -> V_153 ) ;
F_125 ( V_8 ) ;
F_32 ( & V_8 -> V_54 ) ;
F_40 ( V_53 , V_8 , L_31 ,
( T_2 ) F_41 ( & V_8 -> V_54 ) ) ;
V_8 -> V_61 = false ;
}
bool F_128 ( struct V_8 * V_8 , T_2 * V_102 , T_2 * V_141 )
{
struct V_22 * V_22 = NULL ;
struct V_25 * V_25 = NULL ;
bool V_81 = false ;
if ( ! F_41 ( & V_8 -> V_106 ) )
goto V_52;
V_22 = F_14 ( V_8 , V_141 ) ;
if ( ! V_22 )
goto V_52;
V_25 = F_15 ( V_8 , V_102 ) ;
if ( ! V_25 )
goto V_52;
if ( ! F_82 ( V_22 , V_25 ) )
goto V_52;
V_81 = true ;
V_52:
if ( V_25 )
F_21 ( V_25 ) ;
if ( V_22 )
F_16 ( V_22 ) ;
return V_81 ;
}
void F_129 ( struct V_8 * V_8 , struct V_31 * V_31 ,
const unsigned char * V_71 , T_2 V_113 ,
T_2 V_54 , T_3 V_133 )
{
T_2 V_149 = ( T_2 ) F_41 ( & V_31 -> V_98 ) ;
bool V_134 = true ;
if ( F_111 ( V_8 , V_31 -> V_97 ) )
return;
if ( ( ! V_31 -> V_100 && V_54 == 1 ) ||
V_54 - V_149 == 1 ) {
if ( ! V_113 ) {
V_134 = false ;
goto V_169;
}
F_114 ( V_8 , V_31 , V_113 , V_54 ,
(struct V_44 * ) V_71 ) ;
V_31 -> V_133 = F_86 ( V_8 , V_31 ) ;
if ( V_31 -> V_133 != V_133 )
goto V_169;
V_31 -> V_61 = false ;
} else {
if ( ! V_31 -> V_100 || V_54 != V_149 ||
V_31 -> V_133 != V_133 ) {
V_169:
F_40 ( V_53 , V_8 ,
L_32 ,
V_31 -> V_97 , V_54 , V_149 , V_133 ,
V_31 -> V_133 , V_113 ) ;
F_103 ( V_8 , V_31 , V_54 , V_133 ,
V_134 ) ;
return;
}
}
}
bool F_130 ( struct V_8 * V_8 , T_2 * V_33 )
{
struct V_25 * V_25 ;
bool V_81 = false ;
V_25 = F_15 ( V_8 , V_33 ) ;
if ( ! V_25 )
goto V_52;
V_81 = V_25 -> V_24 . V_34 & V_62 ;
F_21 ( V_25 ) ;
V_52:
return V_81 ;
}
