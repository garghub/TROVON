static int F_1 ( const struct V_1 * V_2 , const void * V_3 )
{
const void * V_4 = F_2 ( V_2 , struct V_5 ,
V_6 ) ;
return ( memcmp ( V_4 , V_3 , V_7 ) == 0 ? 1 : 0 ) ;
}
static void F_3 ( struct V_8 * V_9 )
{
F_4 ( & V_9 -> V_10 , V_11 ) ;
F_5 ( V_12 , & V_9 -> V_10 ,
F_6 ( 5000 ) ) ;
}
static struct V_5 *
F_7 ( struct V_13 * V_14 , const void * V_15 )
{
struct V_16 * V_17 ;
struct V_1 * V_2 ;
struct V_5 * V_18 ;
struct V_5 * V_19 = NULL ;
T_1 V_20 ;
if ( ! V_14 )
return NULL ;
V_20 = F_8 ( V_15 , V_14 -> V_21 ) ;
V_17 = & V_14 -> V_22 [ V_20 ] ;
F_9 () ;
F_10 (tt_common_entry, node, head, hash_entry) {
if ( ! F_11 ( V_18 , V_15 ) )
continue;
if ( ! F_12 ( & V_18 -> V_23 ) )
continue;
V_19 = V_18 ;
break;
}
F_13 () ;
return V_19 ;
}
static struct V_24 *
F_14 ( struct V_8 * V_9 , const void * V_15 )
{
struct V_5 * V_18 ;
struct V_24 * V_25 = NULL ;
V_18 = F_7 ( V_9 -> V_26 , V_15 ) ;
if ( V_18 )
V_25 = F_2 ( V_18 ,
struct V_24 ,
V_27 ) ;
return V_25 ;
}
static struct V_28 *
F_15 ( struct V_8 * V_9 , const void * V_15 )
{
struct V_5 * V_18 ;
struct V_28 * V_29 = NULL ;
V_18 = F_7 ( V_9 -> V_30 , V_15 ) ;
if ( V_18 )
V_29 = F_2 ( V_18 ,
struct V_28 ,
V_27 ) ;
return V_29 ;
}
static void
F_16 ( struct V_24 * V_25 )
{
if ( F_17 ( & V_25 -> V_27 . V_23 ) )
F_18 ( V_25 , V_27 . V_31 ) ;
}
static void F_19 ( struct V_32 * V_31 )
{
struct V_5 * V_18 ;
struct V_28 * V_29 ;
V_18 = F_2 ( V_31 , struct V_5 , V_31 ) ;
V_29 = F_2 ( V_18 ,
struct V_28 , V_27 ) ;
F_20 ( V_29 ) ;
}
static void
F_21 ( struct V_28 * V_29 )
{
if ( F_17 ( & V_29 -> V_27 . V_23 ) ) {
F_22 ( V_29 ) ;
F_23 ( & V_29 -> V_27 . V_31 ,
F_19 ) ;
}
}
static void F_24 ( struct V_32 * V_31 )
{
struct V_33 * V_34 ;
V_34 = F_2 ( V_31 , struct V_33 , V_31 ) ;
F_25 ( V_34 -> V_35 ) ;
F_20 ( V_34 ) ;
}
static void
F_26 ( struct V_33 * V_34 )
{
F_27 ( & V_34 -> V_35 -> V_36 ) ;
F_23 ( & V_34 -> V_31 , F_24 ) ;
}
static void F_28 ( struct V_8 * V_9 ,
const T_2 * V_37 , T_2 V_38 )
{
struct V_39 * V_40 , * V_41 , * V_42 ;
bool V_43 = false ;
bool V_44 , V_45 ;
V_40 = F_29 ( sizeof( * V_40 ) , V_46 ) ;
if ( ! V_40 )
return;
V_40 -> V_47 . V_38 = V_38 ;
memcpy ( V_40 -> V_47 . V_37 , V_37 , V_7 ) ;
V_44 = V_38 & V_48 ;
F_30 ( & V_9 -> V_49 ) ;
F_31 (entry, safe, &bat_priv->tt_changes_list,
list) {
if ( ! F_11 ( V_41 -> V_47 . V_37 , V_37 ) )
continue;
V_45 = V_41 -> V_47 . V_38 & V_48 ;
if ( ! V_44 && V_45 )
goto V_50;
if ( V_44 && ! V_45 )
goto V_50;
continue;
V_50:
F_32 ( & V_41 -> V_51 ) ;
F_20 ( V_41 ) ;
F_20 ( V_40 ) ;
V_43 = true ;
goto V_52;
}
F_33 ( & V_40 -> V_51 , & V_9 -> V_53 ) ;
V_52:
F_34 ( & V_9 -> V_49 ) ;
if ( V_43 )
F_27 ( & V_9 -> V_54 ) ;
else
F_35 ( & V_9 -> V_54 ) ;
}
int F_36 ( int V_55 )
{
return V_55 * sizeof( struct V_56 ) ;
}
static int F_37 ( struct V_8 * V_9 )
{
if ( V_9 -> V_26 )
return 0 ;
V_9 -> V_26 = F_38 ( 1024 ) ;
if ( ! V_9 -> V_26 )
return - V_57 ;
return 0 ;
}
void F_39 ( struct V_58 * V_59 , const T_2 * V_37 ,
int V_60 )
{
struct V_8 * V_9 = F_40 ( V_59 ) ;
struct V_24 * V_25 = NULL ;
struct V_28 * V_29 = NULL ;
struct V_16 * V_17 ;
struct V_1 * V_2 ;
struct V_33 * V_34 ;
int V_61 ;
V_25 = F_14 ( V_9 , V_37 ) ;
if ( V_25 ) {
V_25 -> V_62 = V_63 ;
V_25 -> V_27 . V_38 &= ~ V_64 ;
goto V_65;
}
V_25 = F_29 ( sizeof( * V_25 ) , V_46 ) ;
if ( ! V_25 )
goto V_65;
F_41 ( V_66 , V_9 ,
L_1 , V_37 ,
( T_2 ) F_42 ( & V_9 -> V_67 ) ) ;
memcpy ( V_25 -> V_27 . V_37 , V_37 , V_7 ) ;
V_25 -> V_27 . V_38 = V_68 ;
if ( F_43 ( V_60 ) )
V_25 -> V_27 . V_38 |= V_69 ;
F_44 ( & V_25 -> V_27 . V_23 , 2 ) ;
V_25 -> V_62 = V_63 ;
if ( F_11 ( V_37 , V_59 -> V_70 ) )
V_25 -> V_27 . V_38 |= V_71 ;
V_25 -> V_27 . V_38 |= V_72 ;
V_61 = F_45 ( V_9 -> V_26 , F_1 ,
F_8 ,
& V_25 -> V_27 ,
& V_25 -> V_27 . V_6 ) ;
if ( F_46 ( V_61 != 0 ) ) {
F_16 ( V_25 ) ;
goto V_65;
}
F_28 ( V_9 , V_37 , V_25 -> V_27 . V_38 ) ;
V_29 = F_15 ( V_9 , V_37 ) ;
if ( V_29 ) {
V_17 = & V_29 -> V_73 ;
F_9 () ;
F_10 (orig_entry, node, head, list) {
V_34 -> V_35 -> V_74 = true ;
F_47 ( V_9 ,
V_29 -> V_27 . V_37 ,
V_34 -> V_35 ) ;
}
F_13 () ;
V_29 -> V_27 . V_38 |= V_75 ;
V_29 -> V_76 = V_63 ;
}
V_65:
if ( V_25 )
F_16 ( V_25 ) ;
if ( V_29 )
F_21 ( V_29 ) ;
}
static void F_48 ( unsigned char * * V_77 ,
int * V_78 ,
int V_79 ,
int V_80 )
{
unsigned char * V_81 ;
V_81 = F_29 ( V_80 , V_46 ) ;
if ( V_81 ) {
memcpy ( V_81 , * V_77 , V_79 ) ;
F_20 ( * V_77 ) ;
* V_77 = V_81 ;
* V_78 = V_80 ;
}
}
static void F_49 ( struct V_8 * V_9 ,
unsigned char * * V_77 ,
int * V_78 ,
int V_79 )
{
struct V_82 * V_83 ;
int V_84 ;
V_83 = F_50 ( V_9 ) ;
V_84 = V_79 ;
V_84 += F_36 ( F_42 ( & V_9 -> V_54 ) ) ;
if ( ( ! V_83 ) || ( V_84 > V_83 -> V_59 -> V_85 ) )
V_84 = V_79 ;
F_48 ( V_77 , V_78 ,
V_79 , V_84 ) ;
if ( V_83 )
F_51 ( V_83 ) ;
}
static int F_52 ( struct V_8 * V_9 ,
unsigned char * * V_77 ,
int * V_78 ,
int V_79 )
{
struct V_39 * V_41 , * V_42 ;
int V_86 = 0 , V_87 = 0 , V_88 ;
unsigned char * V_89 ;
F_49 ( V_9 , V_77 ,
V_78 , V_79 ) ;
V_88 = * V_78 - V_79 ;
V_89 = * V_77 + V_79 ;
if ( V_88 > 0 )
V_87 = V_88 / F_36 ( 1 ) ;
F_30 ( & V_9 -> V_49 ) ;
F_44 ( & V_9 -> V_54 , 0 ) ;
F_31 (entry, safe, &bat_priv->tt_changes_list,
list) {
if ( V_86 < V_87 ) {
memcpy ( V_89 + F_36 ( V_86 ) ,
& V_41 -> V_47 , sizeof( struct V_56 ) ) ;
V_86 ++ ;
}
F_32 ( & V_41 -> V_51 ) ;
F_20 ( V_41 ) ;
}
F_34 ( & V_9 -> V_49 ) ;
F_30 ( & V_9 -> V_90 ) ;
F_20 ( V_9 -> V_89 ) ;
V_9 -> V_91 = 0 ;
V_9 -> V_89 = NULL ;
if ( V_88 > 0 ) {
V_9 -> V_89 = F_29 ( V_88 , V_46 ) ;
if ( V_9 -> V_89 ) {
memcpy ( V_9 -> V_89 , V_89 , V_88 ) ;
V_9 -> V_91 = V_88 ;
}
}
F_34 ( & V_9 -> V_90 ) ;
return V_86 ;
}
int F_53 ( struct V_92 * V_93 , void * V_94 )
{
struct V_58 * V_95 = (struct V_58 * ) V_93 -> V_96 ;
struct V_8 * V_9 = F_40 ( V_95 ) ;
struct V_13 * V_14 = V_9 -> V_26 ;
struct V_5 * V_18 ;
struct V_82 * V_83 ;
struct V_1 * V_2 ;
struct V_16 * V_17 ;
T_1 V_97 ;
int V_98 = 0 ;
V_83 = F_50 ( V_9 ) ;
if ( ! V_83 ) {
V_98 = F_54 ( V_93 ,
L_2 ,
V_95 -> V_99 ) ;
goto V_65;
}
if ( V_83 -> V_100 != V_101 ) {
V_98 = F_54 ( V_93 ,
L_3 ,
V_95 -> V_99 ) ;
goto V_65;
}
F_54 ( V_93 ,
L_4 ,
V_95 -> V_99 , ( T_2 ) F_42 ( & V_9 -> V_67 ) ) ;
for ( V_97 = 0 ; V_97 < V_14 -> V_21 ; V_97 ++ ) {
V_17 = & V_14 -> V_22 [ V_97 ] ;
F_9 () ;
F_10 (tt_common_entry, node,
head, hash_entry) {
F_54 ( V_93 , L_5 ,
V_18 -> V_37 ,
( V_18 -> V_38 &
V_75 ? 'R' : '.' ) ,
( V_18 -> V_38 &
V_71 ? 'P' : '.' ) ,
( V_18 -> V_38 &
V_72 ? 'N' : '.' ) ,
( V_18 -> V_38 &
V_64 ? 'X' : '.' ) ,
( V_18 -> V_38 &
V_69 ? 'W' : '.' ) ) ;
}
F_13 () ;
}
V_65:
if ( V_83 )
F_51 ( V_83 ) ;
return V_98 ;
}
static void
F_55 ( struct V_8 * V_9 ,
struct V_24 * V_25 ,
T_3 V_38 , const char * V_102 )
{
F_28 ( V_9 , V_25 -> V_27 . V_37 ,
V_25 -> V_27 . V_38 | V_38 ) ;
V_25 -> V_27 . V_38 |= V_64 ;
F_41 ( V_66 , V_9 ,
L_6 ,
V_25 -> V_27 . V_37 , V_102 ) ;
}
void F_56 ( struct V_8 * V_9 , const T_2 * V_37 ,
const char * V_102 , bool V_103 )
{
struct V_24 * V_25 = NULL ;
T_3 V_38 ;
V_25 = F_14 ( V_9 , V_37 ) ;
if ( ! V_25 )
goto V_65;
V_38 = V_48 ;
if ( V_103 )
V_38 |= V_75 ;
F_55 ( V_9 , V_25 , V_38 , V_102 ) ;
V_65:
if ( V_25 )
F_16 ( V_25 ) ;
}
static void F_57 ( struct V_8 * V_9 ,
struct V_16 * V_17 )
{
struct V_24 * V_25 ;
struct V_5 * V_18 ;
struct V_1 * V_2 , * V_104 ;
F_58 (tt_common_entry, node, node_tmp, head,
hash_entry) {
V_25 = F_2 ( V_18 ,
struct V_24 ,
V_27 ) ;
if ( V_25 -> V_27 . V_38 & V_71 )
continue;
if ( V_25 -> V_27 . V_38 & V_64 )
continue;
if ( ! F_59 ( V_25 -> V_62 ,
V_105 ) )
continue;
F_55 ( V_9 , V_25 ,
V_48 , L_7 ) ;
}
}
static void F_60 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = V_9 -> V_26 ;
struct V_16 * V_17 ;
T_4 * V_106 ;
T_1 V_97 ;
for ( V_97 = 0 ; V_97 < V_14 -> V_21 ; V_97 ++ ) {
V_17 = & V_14 -> V_22 [ V_97 ] ;
V_106 = & V_14 -> V_107 [ V_97 ] ;
F_30 ( V_106 ) ;
F_57 ( V_9 , V_17 ) ;
F_34 ( V_106 ) ;
}
}
static void F_61 ( struct V_8 * V_9 )
{
struct V_13 * V_14 ;
T_4 * V_106 ;
struct V_5 * V_18 ;
struct V_24 * V_108 ;
struct V_1 * V_2 , * V_104 ;
struct V_16 * V_17 ;
T_1 V_97 ;
if ( ! V_9 -> V_26 )
return;
V_14 = V_9 -> V_26 ;
for ( V_97 = 0 ; V_97 < V_14 -> V_21 ; V_97 ++ ) {
V_17 = & V_14 -> V_22 [ V_97 ] ;
V_106 = & V_14 -> V_107 [ V_97 ] ;
F_30 ( V_106 ) ;
F_58 (tt_common_entry, node, node_tmp,
head, hash_entry) {
F_62 ( V_2 ) ;
V_108 = F_2 ( V_18 ,
struct V_24 ,
V_27 ) ;
F_16 ( V_108 ) ;
}
F_34 ( V_106 ) ;
}
F_63 ( V_14 ) ;
V_9 -> V_26 = NULL ;
}
static int F_64 ( struct V_8 * V_9 )
{
if ( V_9 -> V_30 )
return 0 ;
V_9 -> V_30 = F_38 ( 1024 ) ;
if ( ! V_9 -> V_30 )
return - V_57 ;
return 0 ;
}
static void F_65 ( struct V_8 * V_9 )
{
struct V_39 * V_41 , * V_42 ;
F_30 ( & V_9 -> V_49 ) ;
F_31 (entry, safe, &bat_priv->tt_changes_list,
list) {
F_32 ( & V_41 -> V_51 ) ;
F_20 ( V_41 ) ;
}
F_44 ( & V_9 -> V_54 , 0 ) ;
F_34 ( & V_9 -> V_49 ) ;
}
static bool
F_66 ( const struct V_28 * V_41 ,
const struct V_109 * V_35 )
{
struct V_33 * V_110 ;
const struct V_16 * V_17 ;
struct V_1 * V_2 ;
bool V_111 = false ;
F_9 () ;
V_17 = & V_41 -> V_73 ;
F_10 (tmp_orig_entry, node, head, list) {
if ( V_110 -> V_35 == V_35 ) {
V_111 = true ;
break;
}
}
F_13 () ;
return V_111 ;
}
static void
F_67 ( struct V_28 * V_29 ,
struct V_109 * V_35 , int V_67 )
{
struct V_33 * V_34 ;
V_34 = F_68 ( sizeof( * V_34 ) , V_46 ) ;
if ( ! V_34 )
return;
F_69 ( & V_34 -> V_51 ) ;
F_35 ( & V_35 -> V_23 ) ;
F_35 ( & V_35 -> V_36 ) ;
V_34 -> V_35 = V_35 ;
V_34 -> V_67 = V_67 ;
F_30 ( & V_29 -> V_106 ) ;
F_70 ( & V_34 -> V_51 ,
& V_29 -> V_73 ) ;
F_34 ( & V_29 -> V_106 ) ;
}
int F_71 ( struct V_8 * V_9 ,
struct V_109 * V_35 ,
const unsigned char * V_112 , T_2 V_38 ,
T_2 V_67 )
{
struct V_28 * V_29 = NULL ;
int V_98 = 0 ;
int V_61 ;
struct V_5 * V_27 ;
V_29 = F_15 ( V_9 , V_112 ) ;
if ( ! V_29 ) {
V_29 = F_68 ( sizeof( * V_29 ) , V_46 ) ;
if ( ! V_29 )
goto V_65;
V_27 = & V_29 -> V_27 ;
memcpy ( V_27 -> V_37 , V_112 , V_7 ) ;
V_27 -> V_38 = V_38 ;
V_29 -> V_76 = 0 ;
F_44 ( & V_27 -> V_23 , 2 ) ;
F_72 ( & V_29 -> V_73 ) ;
F_73 ( & V_29 -> V_106 ) ;
V_61 = F_45 ( V_9 -> V_30 ,
F_1 ,
F_8 , V_27 ,
& V_27 -> V_6 ) ;
if ( F_46 ( V_61 != 0 ) ) {
F_21 ( V_29 ) ;
goto V_113;
}
F_67 ( V_29 , V_35 ,
V_67 ) ;
} else {
if ( V_29 -> V_27 . V_38 & V_75 ) {
F_22 ( V_29 ) ;
V_29 -> V_27 . V_38 &= ~ V_75 ;
V_29 -> V_76 = 0 ;
}
if ( ! F_66 ( V_29 ,
V_35 ) )
F_67 ( V_29 ,
V_35 , V_67 ) ;
}
F_41 ( V_66 , V_9 ,
L_8 ,
V_29 -> V_27 . V_37 , V_35 -> V_114 ) ;
V_113:
F_56 ( V_9 , V_29 -> V_27 . V_37 ,
L_9 ,
V_38 & V_75 ) ;
V_98 = 1 ;
V_65:
if ( V_29 )
F_21 ( V_29 ) ;
return V_98 ;
}
static void
F_74 ( struct V_28 * V_29 ,
struct V_92 * V_93 )
{
struct V_16 * V_17 ;
struct V_1 * V_2 ;
struct V_33 * V_34 ;
struct V_5 * V_18 ;
T_3 V_38 ;
T_2 V_115 ;
V_18 = & V_29 -> V_27 ;
V_17 = & V_29 -> V_73 ;
F_10 (orig_entry, node, head, list) {
V_38 = V_18 -> V_38 ;
V_115 = F_42 ( & V_34 -> V_35 -> V_115 ) ;
F_54 ( V_93 , L_10 ,
V_29 -> V_27 . V_37 , V_34 -> V_67 ,
V_34 -> V_35 -> V_114 , V_115 ,
( V_38 & V_75 ? 'R' : '.' ) ,
( V_38 & V_69 ? 'W' : '.' ) ) ;
}
}
int F_75 ( struct V_92 * V_93 , void * V_94 )
{
struct V_58 * V_95 = (struct V_58 * ) V_93 -> V_96 ;
struct V_8 * V_9 = F_40 ( V_95 ) ;
struct V_13 * V_14 = V_9 -> V_30 ;
struct V_5 * V_18 ;
struct V_28 * V_116 ;
struct V_82 * V_83 ;
struct V_1 * V_2 ;
struct V_16 * V_17 ;
T_1 V_97 ;
int V_98 = 0 ;
V_83 = F_50 ( V_9 ) ;
if ( ! V_83 ) {
V_98 = F_54 ( V_93 ,
L_2 ,
V_95 -> V_99 ) ;
goto V_65;
}
if ( V_83 -> V_100 != V_101 ) {
V_98 = F_54 ( V_93 ,
L_3 ,
V_95 -> V_99 ) ;
goto V_65;
}
F_54 ( V_93 ,
L_11 ,
V_95 -> V_99 ) ;
F_54 ( V_93 , L_12 ,
L_13 , L_14 , L_15 , L_16 , L_17 ) ;
for ( V_97 = 0 ; V_97 < V_14 -> V_21 ; V_97 ++ ) {
V_17 = & V_14 -> V_22 [ V_97 ] ;
F_9 () ;
F_10 (tt_common_entry, node,
head, hash_entry) {
V_116 = F_2 ( V_18 ,
struct V_28 ,
V_27 ) ;
F_74 ( V_116 , V_93 ) ;
}
F_13 () ;
}
V_65:
if ( V_83 )
F_51 ( V_83 ) ;
return V_98 ;
}
static void
F_22 ( struct V_28 * V_29 )
{
struct V_16 * V_17 ;
struct V_1 * V_2 , * V_42 ;
struct V_33 * V_34 ;
F_30 ( & V_29 -> V_106 ) ;
V_17 = & V_29 -> V_73 ;
F_58 (orig_entry, node, safe, head, list) {
F_62 ( V_2 ) ;
F_26 ( V_34 ) ;
}
F_34 ( & V_29 -> V_106 ) ;
}
static void
F_76 ( struct V_8 * V_9 ,
struct V_28 * V_29 ,
struct V_109 * V_35 ,
const char * V_102 )
{
struct V_16 * V_17 ;
struct V_1 * V_2 , * V_42 ;
struct V_33 * V_34 ;
F_30 ( & V_29 -> V_106 ) ;
V_17 = & V_29 -> V_73 ;
F_58 (orig_entry, node, safe, head, list) {
if ( V_34 -> V_35 == V_35 ) {
F_41 ( V_66 , V_9 ,
L_18 ,
V_35 -> V_114 ,
V_29 -> V_27 . V_37 , V_102 ) ;
F_62 ( V_2 ) ;
F_26 ( V_34 ) ;
}
}
F_34 ( & V_29 -> V_106 ) ;
}
static void
F_77 ( struct V_8 * V_9 ,
struct V_28 * V_29 ,
const char * V_102 )
{
F_41 ( V_66 , V_9 ,
L_19 ,
V_29 -> V_27 . V_37 , V_102 ) ;
F_78 ( V_9 -> V_30 , F_1 ,
F_8 , V_29 -> V_27 . V_37 ) ;
F_21 ( V_29 ) ;
}
static void
F_79 ( struct V_8 * V_9 ,
struct V_28 * V_29 ,
struct V_109 * V_35 ,
const char * V_102 )
{
bool V_117 = true ;
struct V_16 * V_17 ;
struct V_1 * V_2 ;
struct V_33 * V_34 ;
F_9 () ;
V_17 = & V_29 -> V_73 ;
F_10 (orig_entry, node, head, list) {
if ( V_34 -> V_35 != V_35 ) {
V_117 = false ;
break;
}
}
F_13 () ;
if ( V_117 ) {
V_29 -> V_27 . V_38 |= V_75 ;
V_29 -> V_76 = V_63 ;
} else
F_76 ( V_9 , V_29 ,
V_35 , V_102 ) ;
}
static void F_80 ( struct V_8 * V_9 ,
struct V_109 * V_35 ,
const unsigned char * V_37 ,
const char * V_102 , bool V_103 )
{
struct V_28 * V_29 = NULL ;
struct V_24 * V_118 = NULL ;
V_29 = F_15 ( V_9 , V_37 ) ;
if ( ! V_29 )
goto V_65;
if ( ! V_103 ) {
F_76 ( V_9 , V_29 ,
V_35 , V_102 ) ;
if ( F_81 ( & V_29 -> V_73 ) )
F_77 ( V_9 , V_29 ,
V_102 ) ;
goto V_65;
}
V_118 = F_14 ( V_9 ,
V_29 -> V_27 . V_37 ) ;
if ( V_118 ) {
F_22 ( V_29 ) ;
F_77 ( V_9 , V_29 , V_102 ) ;
} else
F_79 ( V_9 , V_29 ,
V_35 , V_102 ) ;
V_65:
if ( V_29 )
F_21 ( V_29 ) ;
if ( V_118 )
F_16 ( V_118 ) ;
}
void F_82 ( struct V_8 * V_9 ,
struct V_109 * V_35 ,
const char * V_102 )
{
struct V_28 * V_116 ;
struct V_5 * V_18 ;
T_1 V_97 ;
struct V_13 * V_14 = V_9 -> V_30 ;
struct V_1 * V_2 , * V_42 ;
struct V_16 * V_17 ;
T_4 * V_106 ;
if ( ! V_14 )
return;
for ( V_97 = 0 ; V_97 < V_14 -> V_21 ; V_97 ++ ) {
V_17 = & V_14 -> V_22 [ V_97 ] ;
V_106 = & V_14 -> V_107 [ V_97 ] ;
F_30 ( V_106 ) ;
F_58 (tt_common_entry, node, safe,
head, hash_entry) {
V_116 = F_2 ( V_18 ,
struct V_28 ,
V_27 ) ;
F_76 ( V_9 , V_116 ,
V_35 , V_102 ) ;
if ( F_81 ( & V_116 -> V_73 ) ) {
F_41 ( V_66 , V_9 ,
L_19 ,
V_116 -> V_27 . V_37 , V_102 ) ;
F_62 ( V_2 ) ;
F_21 ( V_116 ) ;
}
}
F_34 ( V_106 ) ;
}
V_35 -> V_119 = false ;
}
static void F_83 ( struct V_8 * V_9 ,
struct V_16 * V_17 )
{
struct V_5 * V_18 ;
struct V_28 * V_29 ;
struct V_1 * V_2 , * V_104 ;
F_58 (tt_common_entry, node, node_tmp, head,
hash_entry) {
V_29 = F_2 ( V_18 ,
struct V_28 ,
V_27 ) ;
if ( ! ( V_29 -> V_27 . V_38 & V_75 ) )
continue;
if ( ! F_59 ( V_29 -> V_76 ,
V_120 ) )
continue;
F_41 ( V_66 , V_9 ,
L_20 ,
V_29 -> V_27 . V_37 ) ;
F_62 ( V_2 ) ;
F_21 ( V_29 ) ;
}
}
static void F_84 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = V_9 -> V_30 ;
struct V_16 * V_17 ;
T_4 * V_106 ;
T_1 V_97 ;
for ( V_97 = 0 ; V_97 < V_14 -> V_21 ; V_97 ++ ) {
V_17 = & V_14 -> V_22 [ V_97 ] ;
V_106 = & V_14 -> V_107 [ V_97 ] ;
F_30 ( V_106 ) ;
F_83 ( V_9 , V_17 ) ;
F_34 ( V_106 ) ;
}
}
static void F_85 ( struct V_8 * V_9 )
{
struct V_13 * V_14 ;
T_4 * V_106 ;
struct V_5 * V_18 ;
struct V_28 * V_116 ;
struct V_1 * V_2 , * V_104 ;
struct V_16 * V_17 ;
T_1 V_97 ;
if ( ! V_9 -> V_30 )
return;
V_14 = V_9 -> V_30 ;
for ( V_97 = 0 ; V_97 < V_14 -> V_21 ; V_97 ++ ) {
V_17 = & V_14 -> V_22 [ V_97 ] ;
V_106 = & V_14 -> V_107 [ V_97 ] ;
F_30 ( V_106 ) ;
F_58 (tt_common_entry, node, node_tmp,
head, hash_entry) {
F_62 ( V_2 ) ;
V_116 = F_2 ( V_18 ,
struct V_28 ,
V_27 ) ;
F_21 ( V_116 ) ;
}
F_34 ( V_106 ) ;
}
F_63 ( V_14 ) ;
V_9 -> V_30 = NULL ;
}
static bool
F_86 ( struct V_24 * V_25 ,
struct V_28 * V_29 )
{
bool V_98 = false ;
if ( V_25 -> V_27 . V_38 & V_69 &&
V_29 -> V_27 . V_38 & V_69 )
V_98 = true ;
return V_98 ;
}
struct V_109 * F_87 ( struct V_8 * V_9 ,
const T_2 * V_121 ,
const T_2 * V_37 )
{
struct V_24 * V_25 = NULL ;
struct V_28 * V_29 = NULL ;
struct V_109 * V_35 = NULL ;
struct V_122 * V_123 = NULL ;
struct V_16 * V_17 ;
struct V_1 * V_2 ;
struct V_33 * V_34 ;
int V_124 ;
if ( V_121 && F_42 ( & V_9 -> V_125 ) ) {
V_25 = F_14 ( V_9 , V_121 ) ;
if ( ! V_25 )
goto V_65;
}
V_29 = F_15 ( V_9 , V_37 ) ;
if ( ! V_29 )
goto V_65;
if ( V_25 &&
F_86 ( V_25 , V_29 ) )
goto V_65;
V_124 = 0 ;
F_9 () ;
V_17 = & V_29 -> V_73 ;
F_10 (orig_entry, node, head, list) {
V_123 = F_88 ( V_34 -> V_35 ) ;
if ( ! V_123 )
continue;
if ( V_123 -> V_126 > V_124 ) {
V_35 = V_34 -> V_35 ;
V_124 = V_123 -> V_126 ;
}
F_89 ( V_123 ) ;
}
if ( V_35 && ! F_12 ( & V_35 -> V_23 ) )
V_35 = NULL ;
F_13 () ;
V_65:
if ( V_29 )
F_21 ( V_29 ) ;
if ( V_25 )
F_16 ( V_25 ) ;
return V_35 ;
}
static T_3 F_90 ( struct V_8 * V_9 ,
struct V_109 * V_35 )
{
T_3 V_127 = 0 , V_128 ;
struct V_13 * V_14 = V_9 -> V_30 ;
struct V_5 * V_129 ;
struct V_28 * V_116 ;
struct V_1 * V_2 ;
struct V_16 * V_17 ;
T_1 V_97 ;
int V_130 ;
for ( V_97 = 0 ; V_97 < V_14 -> V_21 ; V_97 ++ ) {
V_17 = & V_14 -> V_22 [ V_97 ] ;
F_9 () ;
F_10 (tt_common, node, head, hash_entry) {
V_116 = F_2 ( V_129 ,
struct V_28 ,
V_27 ) ;
if ( V_129 -> V_38 & V_75 )
continue;
if ( ! F_66 ( V_116 ,
V_35 ) )
continue;
V_128 = 0 ;
for ( V_130 = 0 ; V_130 < V_7 ; V_130 ++ )
V_128 = F_91 ( V_128 ,
V_129 -> V_37 [ V_130 ] ) ;
V_127 ^= V_128 ;
}
F_13 () ;
}
return V_127 ;
}
static T_3 F_92 ( struct V_8 * V_9 )
{
T_3 V_127 = 0 , V_128 ;
struct V_13 * V_14 = V_9 -> V_26 ;
struct V_5 * V_129 ;
struct V_1 * V_2 ;
struct V_16 * V_17 ;
T_1 V_97 ;
int V_130 ;
for ( V_97 = 0 ; V_97 < V_14 -> V_21 ; V_97 ++ ) {
V_17 = & V_14 -> V_22 [ V_97 ] ;
F_9 () ;
F_10 (tt_common, node, head, hash_entry) {
if ( V_129 -> V_38 & V_72 )
continue;
V_128 = 0 ;
for ( V_130 = 0 ; V_130 < V_7 ; V_130 ++ )
V_128 = F_91 ( V_128 ,
V_129 -> V_37 [ V_130 ] ) ;
V_127 ^= V_128 ;
}
F_13 () ;
}
return V_127 ;
}
static void F_93 ( struct V_8 * V_9 )
{
struct V_131 * V_2 , * V_42 ;
F_30 ( & V_9 -> V_132 ) ;
F_31 (node, safe, &bat_priv->tt_req_list, list) {
F_32 ( & V_2 -> V_51 ) ;
F_20 ( V_2 ) ;
}
F_34 ( & V_9 -> V_132 ) ;
}
static void F_94 ( struct V_8 * V_9 ,
struct V_109 * V_35 ,
const unsigned char * V_89 ,
T_2 V_133 )
{
T_3 V_91 = F_36 ( V_133 ) ;
F_30 ( & V_35 -> V_90 ) ;
if ( V_91 > 0 ) {
F_20 ( V_35 -> V_89 ) ;
V_35 -> V_91 = 0 ;
V_35 -> V_89 = F_29 ( V_91 , V_46 ) ;
if ( V_35 -> V_89 ) {
memcpy ( V_35 -> V_89 , V_89 , V_91 ) ;
V_35 -> V_91 = V_91 ;
}
}
F_34 ( & V_35 -> V_90 ) ;
}
static void F_95 ( struct V_8 * V_9 )
{
struct V_131 * V_2 , * V_42 ;
F_30 ( & V_9 -> V_132 ) ;
F_31 (node, safe, &bat_priv->tt_req_list, list) {
if ( F_59 ( V_2 -> V_134 ,
V_135 ) ) {
F_32 ( & V_2 -> V_51 ) ;
F_20 ( V_2 ) ;
}
}
F_34 ( & V_9 -> V_132 ) ;
}
static struct V_131 *
F_96 ( struct V_8 * V_9 ,
struct V_109 * V_35 )
{
struct V_131 * V_136 , * V_137 = NULL ;
F_30 ( & V_9 -> V_132 ) ;
F_97 (tt_req_node_tmp, &bat_priv->tt_req_list, list) {
if ( F_11 ( V_136 , V_35 ) &&
! F_59 ( V_136 -> V_134 ,
V_135 ) )
goto V_52;
}
V_137 = F_29 ( sizeof( * V_137 ) , V_46 ) ;
if ( ! V_137 )
goto V_52;
memcpy ( V_137 -> V_37 , V_35 -> V_114 , V_7 ) ;
V_137 -> V_134 = V_63 ;
F_98 ( & V_137 -> V_51 , & V_9 -> V_138 ) ;
V_52:
F_34 ( & V_9 -> V_132 ) ;
return V_137 ;
}
static int F_99 ( const void * V_139 ,
const void * V_140 )
{
const struct V_5 * V_18 = V_139 ;
if ( V_18 -> V_38 & V_72 )
return 0 ;
return 1 ;
}
static int F_100 ( const void * V_139 ,
const void * V_140 )
{
const struct V_5 * V_18 = V_139 ;
const struct V_28 * V_29 ;
const struct V_109 * V_35 = V_140 ;
if ( V_18 -> V_38 & V_75 )
return 0 ;
V_29 = F_2 ( V_18 ,
struct V_28 ,
V_27 ) ;
return F_66 ( V_29 , V_35 ) ;
}
static struct V_141 *
F_101 ( T_3 V_142 , T_2 V_67 ,
struct V_13 * V_14 ,
struct V_82 * V_83 ,
int (* F_102)( const void * , const void * ) ,
void * V_143 )
{
struct V_5 * V_18 ;
struct V_144 * V_145 ;
struct V_56 * V_146 ;
struct V_1 * V_2 ;
struct V_16 * V_17 ;
struct V_141 * V_147 = NULL ;
T_3 V_148 , V_149 ;
T_5 V_150 = sizeof( struct V_144 ) ;
T_1 V_97 ;
T_6 V_151 ;
if ( V_150 + V_142 > V_83 -> V_59 -> V_85 ) {
V_142 = V_83 -> V_59 -> V_85 - V_150 ;
V_142 -= V_142 % sizeof( struct V_56 ) ;
}
V_148 = V_142 / sizeof( struct V_56 ) ;
V_151 = V_150 + V_142 ;
V_147 = F_103 ( V_151 + V_152 ) ;
if ( ! V_147 )
goto V_65;
F_104 ( V_147 , V_152 ) ;
V_145 = (struct V_144 * ) F_105 ( V_147 , V_151 ) ;
V_145 -> V_67 = V_67 ;
V_146 = (struct V_56 * ) ( V_147 -> V_15 + V_150 ) ;
V_149 = 0 ;
F_9 () ;
for ( V_97 = 0 ; V_97 < V_14 -> V_21 ; V_97 ++ ) {
V_17 = & V_14 -> V_22 [ V_97 ] ;
F_10 (tt_common_entry, node,
head, hash_entry) {
if ( V_149 == V_148 )
break;
if ( ( F_102 ) && ( ! F_102 ( V_18 , V_143 ) ) )
continue;
memcpy ( V_146 -> V_37 , V_18 -> V_37 ,
V_7 ) ;
V_146 -> V_38 = V_68 ;
V_149 ++ ;
V_146 ++ ;
}
}
F_13 () ;
V_145 -> V_153 = F_106 ( V_149 ) ;
V_65:
return V_147 ;
}
static int F_107 ( struct V_8 * V_9 ,
struct V_109 * V_154 ,
T_2 V_67 , T_3 V_155 ,
bool V_156 )
{
struct V_141 * V_147 = NULL ;
struct V_144 * V_157 ;
struct V_122 * V_158 = NULL ;
struct V_82 * V_83 ;
struct V_131 * V_137 = NULL ;
int V_98 = 1 ;
T_6 V_159 ;
V_83 = F_50 ( V_9 ) ;
if ( ! V_83 )
goto V_65;
V_137 = F_96 ( V_9 , V_154 ) ;
if ( ! V_137 )
goto V_65;
V_147 = F_103 ( sizeof( * V_157 ) + V_152 ) ;
if ( ! V_147 )
goto V_65;
F_104 ( V_147 , V_152 ) ;
V_159 = sizeof( * V_157 ) ;
V_157 = (struct V_144 * ) F_105 ( V_147 , V_159 ) ;
V_157 -> V_160 . V_161 = V_162 ;
V_157 -> V_160 . V_163 = V_164 ;
memcpy ( V_157 -> V_121 , V_83 -> V_95 -> V_70 , V_7 ) ;
memcpy ( V_157 -> V_165 , V_154 -> V_114 , V_7 ) ;
V_157 -> V_160 . V_166 = V_167 ;
V_157 -> V_67 = V_67 ;
V_157 -> V_153 = F_106 ( V_155 ) ;
V_157 -> V_38 = V_168 ;
if ( V_156 )
V_157 -> V_38 |= V_169 ;
V_158 = F_88 ( V_154 ) ;
if ( ! V_158 )
goto V_65;
F_41 ( V_66 , V_9 ,
L_21 ,
V_154 -> V_114 , V_158 -> V_37 ,
( V_156 ? 'F' : '.' ) ) ;
F_108 ( V_9 , V_170 ) ;
F_109 ( V_147 , V_158 -> V_171 , V_158 -> V_37 ) ;
V_98 = 0 ;
V_65:
if ( V_158 )
F_89 ( V_158 ) ;
if ( V_83 )
F_51 ( V_83 ) ;
if ( V_98 )
F_110 ( V_147 ) ;
if ( V_98 && V_137 ) {
F_30 ( & V_9 -> V_132 ) ;
F_32 ( & V_137 -> V_51 ) ;
F_34 ( & V_9 -> V_132 ) ;
F_20 ( V_137 ) ;
}
return V_98 ;
}
static bool
F_111 ( struct V_8 * V_9 ,
struct V_144 * V_157 )
{
struct V_109 * V_172 = NULL ;
struct V_109 * V_173 = NULL ;
struct V_122 * V_158 = NULL ;
struct V_82 * V_83 = NULL ;
T_2 V_174 , V_175 , V_67 ;
int V_98 = false ;
unsigned char * V_89 ;
bool V_156 ;
T_3 V_142 , V_148 ;
struct V_141 * V_147 = NULL ;
struct V_144 * V_145 ;
T_6 V_151 ;
F_41 ( V_66 , V_9 ,
L_22 ,
V_157 -> V_121 , V_157 -> V_67 , V_157 -> V_165 ,
( V_157 -> V_38 & V_169 ? 'F' : '.' ) ) ;
V_172 = F_112 ( V_9 , V_157 -> V_165 ) ;
if ( ! V_172 )
goto V_65;
V_173 = F_112 ( V_9 , V_157 -> V_121 ) ;
if ( ! V_173 )
goto V_65;
V_158 = F_88 ( V_173 ) ;
if ( ! V_158 )
goto V_65;
V_83 = F_50 ( V_9 ) ;
if ( ! V_83 )
goto V_65;
V_174 = ( T_2 ) F_42 ( & V_172 -> V_115 ) ;
V_175 = V_157 -> V_67 ;
if ( V_174 != V_175 ||
V_157 -> V_153 != F_106 ( V_172 -> V_155 ) )
goto V_65;
if ( V_157 -> V_38 & V_169 ||
! V_172 -> V_89 )
V_156 = true ;
else
V_156 = false ;
if ( ! V_156 ) {
F_30 ( & V_172 -> V_90 ) ;
V_142 = V_172 -> V_91 ;
V_148 = V_142 / sizeof( struct V_56 ) ;
V_151 = sizeof( * V_145 ) + V_142 ;
V_147 = F_103 ( V_151 + V_152 ) ;
if ( ! V_147 )
goto V_52;
F_104 ( V_147 , V_152 ) ;
V_145 = (struct V_144 * ) F_105 ( V_147 ,
V_151 ) ;
V_145 -> V_67 = V_175 ;
V_145 -> V_153 = F_106 ( V_148 ) ;
V_89 = V_147 -> V_15 + sizeof( * V_145 ) ;
memcpy ( V_89 , V_172 -> V_89 ,
V_172 -> V_91 ) ;
F_34 ( & V_172 -> V_90 ) ;
} else {
V_142 = ( T_3 ) F_42 ( & V_172 -> V_36 ) ;
V_142 *= sizeof( struct V_56 ) ;
V_67 = ( T_2 ) F_42 ( & V_172 -> V_115 ) ;
V_147 = F_101 ( V_142 , V_67 ,
V_9 -> V_30 ,
V_83 ,
F_100 ,
V_172 ) ;
if ( ! V_147 )
goto V_65;
V_145 = (struct V_144 * ) V_147 -> V_15 ;
}
V_145 -> V_160 . V_161 = V_162 ;
V_145 -> V_160 . V_163 = V_164 ;
V_145 -> V_160 . V_166 = V_167 ;
memcpy ( V_145 -> V_121 , V_172 -> V_114 , V_7 ) ;
memcpy ( V_145 -> V_165 , V_157 -> V_121 , V_7 ) ;
V_145 -> V_38 = V_176 ;
if ( V_156 )
V_145 -> V_38 |= V_169 ;
F_41 ( V_66 , V_9 ,
L_23 ,
V_173 -> V_114 , V_158 -> V_37 ,
V_172 -> V_114 , V_175 ) ;
F_108 ( V_9 , V_177 ) ;
F_109 ( V_147 , V_158 -> V_171 , V_158 -> V_37 ) ;
V_98 = true ;
goto V_65;
V_52:
F_34 ( & V_172 -> V_90 ) ;
V_65:
if ( V_173 )
F_25 ( V_173 ) ;
if ( V_172 )
F_25 ( V_172 ) ;
if ( V_158 )
F_89 ( V_158 ) ;
if ( V_83 )
F_51 ( V_83 ) ;
if ( ! V_98 )
F_110 ( V_147 ) ;
return V_98 ;
}
static bool
F_113 ( struct V_8 * V_9 ,
struct V_144 * V_157 )
{
struct V_109 * V_35 = NULL ;
struct V_122 * V_158 = NULL ;
struct V_82 * V_83 = NULL ;
T_2 V_178 , V_175 , V_67 ;
int V_98 = false ;
unsigned char * V_89 ;
bool V_156 ;
T_3 V_142 , V_148 ;
struct V_141 * V_147 = NULL ;
struct V_144 * V_145 ;
T_6 V_151 ;
F_41 ( V_66 , V_9 ,
L_24 ,
V_157 -> V_121 , V_157 -> V_67 ,
( V_157 -> V_38 & V_169 ? 'F' : '.' ) ) ;
V_178 = ( T_2 ) F_42 ( & V_9 -> V_67 ) ;
V_175 = V_157 -> V_67 ;
V_35 = F_112 ( V_9 , V_157 -> V_121 ) ;
if ( ! V_35 )
goto V_65;
V_158 = F_88 ( V_35 ) ;
if ( ! V_158 )
goto V_65;
V_83 = F_50 ( V_9 ) ;
if ( ! V_83 )
goto V_65;
if ( V_157 -> V_38 & V_169 || V_178 != V_175 ||
! V_9 -> V_89 )
V_156 = true ;
else
V_156 = false ;
if ( ! V_156 ) {
F_30 ( & V_9 -> V_90 ) ;
V_142 = V_9 -> V_91 ;
V_148 = V_142 / sizeof( struct V_56 ) ;
V_151 = sizeof( * V_145 ) + V_142 ;
V_147 = F_103 ( V_151 + V_152 ) ;
if ( ! V_147 )
goto V_52;
F_104 ( V_147 , V_152 ) ;
V_145 = (struct V_144 * ) F_105 ( V_147 ,
V_151 ) ;
V_145 -> V_67 = V_175 ;
V_145 -> V_153 = F_106 ( V_148 ) ;
V_89 = V_147 -> V_15 + sizeof( * V_145 ) ;
memcpy ( V_89 , V_9 -> V_89 ,
V_9 -> V_91 ) ;
F_34 ( & V_9 -> V_90 ) ;
} else {
V_142 = ( T_3 ) F_42 ( & V_9 -> V_179 ) ;
V_142 *= sizeof( struct V_56 ) ;
V_67 = ( T_2 ) F_42 ( & V_9 -> V_67 ) ;
V_147 = F_101 ( V_142 , V_67 ,
V_9 -> V_26 ,
V_83 ,
F_99 ,
NULL ) ;
if ( ! V_147 )
goto V_65;
V_145 = (struct V_144 * ) V_147 -> V_15 ;
}
V_145 -> V_160 . V_161 = V_162 ;
V_145 -> V_160 . V_163 = V_164 ;
V_145 -> V_160 . V_166 = V_167 ;
memcpy ( V_145 -> V_121 , V_83 -> V_95 -> V_70 , V_7 ) ;
memcpy ( V_145 -> V_165 , V_157 -> V_121 , V_7 ) ;
V_145 -> V_38 = V_176 ;
if ( V_156 )
V_145 -> V_38 |= V_169 ;
F_41 ( V_66 , V_9 ,
L_25 ,
V_35 -> V_114 , V_158 -> V_37 ,
( V_145 -> V_38 & V_169 ? 'F' : '.' ) ) ;
F_108 ( V_9 , V_177 ) ;
F_109 ( V_147 , V_158 -> V_171 , V_158 -> V_37 ) ;
V_98 = true ;
goto V_65;
V_52:
F_34 ( & V_9 -> V_90 ) ;
V_65:
if ( V_35 )
F_25 ( V_35 ) ;
if ( V_158 )
F_89 ( V_158 ) ;
if ( V_83 )
F_51 ( V_83 ) ;
if ( ! V_98 )
F_110 ( V_147 ) ;
return true ;
}
bool F_114 ( struct V_8 * V_9 ,
struct V_144 * V_157 )
{
if ( F_115 ( V_157 -> V_165 ) ) {
if ( F_116 ( V_9 , V_157 -> V_121 ) )
return true ;
return F_113 ( V_9 , V_157 ) ;
} else {
return F_111 ( V_9 , V_157 ) ;
}
}
static void F_117 ( struct V_8 * V_9 ,
struct V_109 * V_35 ,
struct V_56 * V_146 ,
T_3 V_133 , T_2 V_67 )
{
int V_97 ;
int V_180 ;
for ( V_97 = 0 ; V_97 < V_133 ; V_97 ++ ) {
if ( ( V_146 + V_97 ) -> V_38 & V_48 ) {
V_180 = ( V_146 + V_97 ) -> V_38 & V_75 ;
F_80 ( V_9 , V_35 ,
( V_146 + V_97 ) -> V_37 ,
L_26 ,
V_180 ) ;
} else {
if ( ! F_71 ( V_9 , V_35 ,
( V_146 + V_97 ) -> V_37 ,
( V_146 + V_97 ) -> V_38 , V_67 ) )
return;
}
}
V_35 -> V_119 = true ;
}
static void F_118 ( struct V_8 * V_9 ,
struct V_144 * V_145 )
{
struct V_109 * V_35 = NULL ;
V_35 = F_112 ( V_9 , V_145 -> V_121 ) ;
if ( ! V_35 )
goto V_65;
F_82 ( V_9 , V_35 , L_27 ) ;
F_117 ( V_9 , V_35 ,
(struct V_56 * ) ( V_145 + 1 ) ,
F_119 ( V_145 -> V_153 ) ,
V_145 -> V_67 ) ;
F_30 ( & V_35 -> V_90 ) ;
F_20 ( V_35 -> V_89 ) ;
V_35 -> V_91 = 0 ;
V_35 -> V_89 = NULL ;
F_34 ( & V_35 -> V_90 ) ;
F_44 ( & V_35 -> V_115 , V_145 -> V_67 ) ;
V_65:
if ( V_35 )
F_25 ( V_35 ) ;
}
static void F_120 ( struct V_8 * V_9 ,
struct V_109 * V_35 ,
T_3 V_133 , T_2 V_67 ,
struct V_56 * V_146 )
{
F_117 ( V_9 , V_35 , V_146 ,
V_133 , V_67 ) ;
F_94 ( V_9 , V_35 ,
( unsigned char * ) V_146 , V_133 ) ;
F_44 ( & V_35 -> V_115 , V_67 ) ;
}
bool F_121 ( struct V_8 * V_9 , const T_2 * V_37 )
{
struct V_24 * V_25 = NULL ;
bool V_98 = false ;
V_25 = F_14 ( V_9 , V_37 ) ;
if ( ! V_25 )
goto V_65;
if ( V_25 -> V_27 . V_38 & V_64 )
goto V_65;
V_98 = true ;
V_65:
if ( V_25 )
F_16 ( V_25 ) ;
return V_98 ;
}
void F_122 ( struct V_8 * V_9 ,
struct V_144 * V_145 )
{
struct V_131 * V_2 , * V_42 ;
struct V_109 * V_35 = NULL ;
struct V_56 * V_146 ;
F_41 ( V_66 , V_9 ,
L_28 ,
V_145 -> V_121 , V_145 -> V_67 ,
F_119 ( V_145 -> V_153 ) ,
( V_145 -> V_38 & V_169 ? 'F' : '.' ) ) ;
if ( F_116 ( V_9 , V_145 -> V_121 ) )
goto V_65;
V_35 = F_112 ( V_9 , V_145 -> V_121 ) ;
if ( ! V_35 )
goto V_65;
if ( V_145 -> V_38 & V_169 ) {
F_118 ( V_9 , V_145 ) ;
} else {
V_146 = (struct V_56 * ) ( V_145 + 1 ) ;
F_120 ( V_9 , V_35 ,
F_119 ( V_145 -> V_153 ) ,
V_145 -> V_67 , V_146 ) ;
}
F_30 ( & V_9 -> V_132 ) ;
F_31 (node, safe, &bat_priv->tt_req_list, list) {
if ( ! F_11 ( V_2 -> V_37 , V_145 -> V_121 ) )
continue;
F_32 ( & V_2 -> V_51 ) ;
F_20 ( V_2 ) ;
}
F_34 ( & V_9 -> V_132 ) ;
V_35 -> V_155 = F_90 ( V_9 , V_35 ) ;
V_35 -> V_74 = false ;
V_65:
if ( V_35 )
F_25 ( V_35 ) ;
}
int F_123 ( struct V_8 * V_9 )
{
int V_98 ;
V_98 = F_37 ( V_9 ) ;
if ( V_98 < 0 )
return V_98 ;
V_98 = F_64 ( V_9 ) ;
if ( V_98 < 0 )
return V_98 ;
F_3 ( V_9 ) ;
return 1 ;
}
static void F_124 ( struct V_8 * V_9 )
{
struct V_181 * V_2 , * V_42 ;
F_30 ( & V_9 -> V_182 ) ;
F_31 (node, safe, &bat_priv->tt_roam_list, list) {
F_32 ( & V_2 -> V_51 ) ;
F_20 ( V_2 ) ;
}
F_34 ( & V_9 -> V_182 ) ;
}
static void F_125 ( struct V_8 * V_9 )
{
struct V_181 * V_2 , * V_42 ;
F_30 ( & V_9 -> V_182 ) ;
F_31 (node, safe, &bat_priv->tt_roam_list, list) {
if ( ! F_59 ( V_2 -> V_183 ,
V_184 ) )
continue;
F_32 ( & V_2 -> V_51 ) ;
F_20 ( V_2 ) ;
}
F_34 ( & V_9 -> V_182 ) ;
}
static bool F_126 ( struct V_8 * V_9 ,
T_2 * V_185 )
{
struct V_181 * V_186 ;
bool V_98 = false ;
F_30 ( & V_9 -> V_182 ) ;
F_97 (tt_roam_node, &bat_priv->tt_roam_list, list) {
if ( ! F_11 ( V_186 -> V_37 , V_185 ) )
continue;
if ( F_59 ( V_186 -> V_183 ,
V_184 ) )
continue;
if ( ! F_127 ( & V_186 -> V_187 ) )
goto V_52;
V_98 = true ;
break;
}
if ( ! V_98 ) {
V_186 = F_29 ( sizeof( * V_186 ) , V_46 ) ;
if ( ! V_186 )
goto V_52;
V_186 -> V_183 = V_63 ;
F_44 ( & V_186 -> V_187 ,
V_188 - 1 ) ;
memcpy ( V_186 -> V_37 , V_185 , V_7 ) ;
F_98 ( & V_186 -> V_51 , & V_9 -> V_189 ) ;
V_98 = true ;
}
V_52:
F_34 ( & V_9 -> V_182 ) ;
return V_98 ;
}
static void F_47 ( struct V_8 * V_9 , T_2 * V_185 ,
struct V_109 * V_35 )
{
struct V_122 * V_158 = NULL ;
struct V_141 * V_147 = NULL ;
struct V_190 * V_191 ;
int V_98 = 1 ;
struct V_82 * V_83 ;
T_6 V_151 = sizeof( * V_191 ) ;
if ( ! F_126 ( V_9 , V_185 ) )
goto V_65;
V_147 = F_103 ( sizeof( * V_191 ) + V_152 ) ;
if ( ! V_147 )
goto V_65;
F_104 ( V_147 , V_152 ) ;
V_191 = (struct V_190 * ) F_105 ( V_147 , V_151 ) ;
V_191 -> V_160 . V_161 = V_192 ;
V_191 -> V_160 . V_163 = V_164 ;
V_191 -> V_160 . V_166 = V_167 ;
V_191 -> V_193 = 0 ;
V_83 = F_50 ( V_9 ) ;
if ( ! V_83 )
goto V_65;
memcpy ( V_191 -> V_121 , V_83 -> V_95 -> V_70 , V_7 ) ;
F_51 ( V_83 ) ;
memcpy ( V_191 -> V_165 , V_35 -> V_114 , V_7 ) ;
memcpy ( V_191 -> V_185 , V_185 , V_7 ) ;
V_158 = F_88 ( V_35 ) ;
if ( ! V_158 )
goto V_65;
F_41 ( V_66 , V_9 ,
L_29 ,
V_35 -> V_114 , V_185 , V_158 -> V_37 ) ;
F_108 ( V_9 , V_194 ) ;
F_109 ( V_147 , V_158 -> V_171 , V_158 -> V_37 ) ;
V_98 = 0 ;
V_65:
if ( V_158 )
F_89 ( V_158 ) ;
if ( V_98 )
F_110 ( V_147 ) ;
return;
}
static void V_11 ( struct V_195 * V_196 )
{
struct V_197 * V_197 ;
struct V_8 * V_9 ;
V_197 = F_2 ( V_196 , struct V_197 , V_196 ) ;
V_9 = F_2 ( V_197 , struct V_8 , V_10 ) ;
F_60 ( V_9 ) ;
F_84 ( V_9 ) ;
F_95 ( V_9 ) ;
F_125 ( V_9 ) ;
F_3 ( V_9 ) ;
}
void F_128 ( struct V_8 * V_9 )
{
F_129 ( & V_9 -> V_10 ) ;
F_61 ( V_9 ) ;
F_85 ( V_9 ) ;
F_93 ( V_9 ) ;
F_65 ( V_9 ) ;
F_124 ( V_9 ) ;
F_20 ( V_9 -> V_89 ) ;
}
static T_3 F_130 ( struct V_13 * V_14 ,
T_3 V_38 , bool V_198 )
{
T_1 V_97 ;
T_3 V_199 = 0 ;
struct V_16 * V_17 ;
struct V_1 * V_2 ;
struct V_5 * V_18 ;
if ( ! V_14 )
goto V_65;
for ( V_97 = 0 ; V_97 < V_14 -> V_21 ; V_97 ++ ) {
V_17 = & V_14 -> V_22 [ V_97 ] ;
F_9 () ;
F_10 (tt_common_entry, node,
head, hash_entry) {
if ( V_198 ) {
if ( ( V_18 -> V_38 & V_38 ) == V_38 )
continue;
V_18 -> V_38 |= V_38 ;
} else {
if ( ! ( V_18 -> V_38 & V_38 ) )
continue;
V_18 -> V_38 &= ~ V_38 ;
}
V_199 ++ ;
}
F_13 () ;
}
V_65:
return V_199 ;
}
static void F_131 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = V_9 -> V_26 ;
struct V_5 * V_129 ;
struct V_24 * V_108 ;
struct V_1 * V_2 , * V_104 ;
struct V_16 * V_17 ;
T_4 * V_106 ;
T_1 V_97 ;
if ( ! V_14 )
return;
for ( V_97 = 0 ; V_97 < V_14 -> V_21 ; V_97 ++ ) {
V_17 = & V_14 -> V_22 [ V_97 ] ;
V_106 = & V_14 -> V_107 [ V_97 ] ;
F_30 ( V_106 ) ;
F_58 (tt_common, node, node_tmp, head,
hash_entry) {
if ( ! ( V_129 -> V_38 & V_64 ) )
continue;
F_41 ( V_66 , V_9 ,
L_30 ,
V_129 -> V_37 ) ;
F_27 ( & V_9 -> V_179 ) ;
F_62 ( V_2 ) ;
V_108 = F_2 ( V_129 ,
struct V_24 ,
V_27 ) ;
F_16 ( V_108 ) ;
}
F_34 ( V_106 ) ;
}
}
static int F_132 ( struct V_8 * V_9 ,
unsigned char * * V_77 ,
int * V_78 , int V_200 )
{
T_3 V_199 = 0 ;
if ( F_42 ( & V_9 -> V_54 ) < 1 )
return - V_201 ;
V_199 = F_130 ( V_9 -> V_26 ,
V_72 , false ) ;
F_133 ( V_199 , & V_9 -> V_179 ) ;
F_131 ( V_9 ) ;
V_9 -> V_155 = F_92 ( V_9 ) ;
F_35 ( & V_9 -> V_67 ) ;
F_41 ( V_66 , V_9 ,
L_31 ,
( T_2 ) F_42 ( & V_9 -> V_67 ) ) ;
V_9 -> V_74 = false ;
F_44 ( & V_9 -> V_202 , V_203 ) ;
return F_52 ( V_9 , V_77 ,
V_78 , V_200 ) ;
}
int F_134 ( struct V_8 * V_9 ,
unsigned char * * V_77 , int * V_78 ,
int V_200 )
{
int V_133 ;
V_133 = F_132 ( V_9 , V_77 ,
V_78 ,
V_200 ) ;
if ( ( V_133 < 0 ) &&
( ! F_127 ( & V_9 -> V_202 ) ) ) {
F_48 ( V_77 , V_78 ,
V_200 , V_200 ) ;
V_133 = 0 ;
}
return V_133 ;
}
bool F_135 ( struct V_8 * V_9 , T_2 * V_121 ,
T_2 * V_165 )
{
struct V_24 * V_25 = NULL ;
struct V_28 * V_29 = NULL ;
bool V_98 = false ;
if ( ! F_42 ( & V_9 -> V_125 ) )
goto V_65;
V_25 = F_14 ( V_9 , V_165 ) ;
if ( ! V_25 )
goto V_65;
V_29 = F_15 ( V_9 , V_121 ) ;
if ( ! V_29 )
goto V_65;
if ( ! F_86 ( V_25 , V_29 ) )
goto V_65;
V_98 = true ;
V_65:
if ( V_29 )
F_21 ( V_29 ) ;
if ( V_25 )
F_16 ( V_25 ) ;
return V_98 ;
}
void F_136 ( struct V_8 * V_9 ,
struct V_109 * V_35 ,
const unsigned char * V_89 , T_2 V_133 ,
T_2 V_67 , T_3 V_155 )
{
T_2 V_174 = ( T_2 ) F_42 ( & V_35 -> V_115 ) ;
bool V_156 = true ;
struct V_56 * V_146 ;
if ( F_116 ( V_9 , V_35 -> V_114 ) )
return;
if ( ( ! V_35 -> V_119 && V_67 == 1 ) ||
V_67 - V_174 == 1 ) {
if ( ! V_133 ) {
V_156 = false ;
goto V_204;
}
V_146 = (struct V_56 * ) V_89 ;
F_120 ( V_9 , V_35 , V_133 ,
V_67 , V_146 ) ;
V_35 -> V_155 = F_90 ( V_9 , V_35 ) ;
if ( V_35 -> V_155 != V_155 )
goto V_204;
V_35 -> V_74 = false ;
} else {
if ( ! V_35 -> V_119 || V_67 != V_174 ||
V_35 -> V_155 != V_155 ) {
V_204:
F_41 ( V_66 , V_9 ,
L_32 ,
V_35 -> V_114 , V_67 , V_174 , V_155 ,
V_35 -> V_155 , V_133 ) ;
F_107 ( V_9 , V_35 , V_67 ,
V_155 , V_156 ) ;
return;
}
}
}
bool F_137 ( struct V_8 * V_9 ,
T_2 * V_37 )
{
struct V_28 * V_29 ;
bool V_98 = false ;
V_29 = F_15 ( V_9 , V_37 ) ;
if ( ! V_29 )
goto V_65;
V_98 = V_29 -> V_27 . V_38 & V_75 ;
F_21 ( V_29 ) ;
V_65:
return V_98 ;
}
