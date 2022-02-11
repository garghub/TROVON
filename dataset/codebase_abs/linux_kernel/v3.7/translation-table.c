static int F_1 ( const struct V_1 * V_2 , const void * V_3 )
{
const void * V_4 = F_2 ( V_2 , struct V_5 ,
V_6 ) ;
return ( memcmp ( V_4 , V_3 , V_7 ) == 0 ? 1 : 0 ) ;
}
static void F_3 ( struct V_8 * V_9 )
{
F_4 ( & V_9 -> V_10 . V_11 , V_12 ) ;
F_5 ( V_13 , & V_9 -> V_10 . V_11 ,
F_6 ( 5000 ) ) ;
}
static struct V_5 *
F_7 ( struct V_14 * V_15 , const void * V_16 )
{
struct V_17 * V_18 ;
struct V_1 * V_2 ;
struct V_5 * V_19 ;
struct V_5 * V_20 = NULL ;
T_1 V_21 ;
if ( ! V_15 )
return NULL ;
V_21 = F_8 ( V_16 , V_15 -> V_22 ) ;
V_18 = & V_15 -> V_23 [ V_21 ] ;
F_9 () ;
F_10 (tt_common_entry, node, head, hash_entry) {
if ( ! F_11 ( V_19 , V_16 ) )
continue;
if ( ! F_12 ( & V_19 -> V_24 ) )
continue;
V_20 = V_19 ;
break;
}
F_13 () ;
return V_20 ;
}
static struct V_25 *
F_14 ( struct V_8 * V_9 , const void * V_16 )
{
struct V_5 * V_19 ;
struct V_25 * V_26 = NULL ;
V_19 = F_7 ( V_9 -> V_10 . V_27 , V_16 ) ;
if ( V_19 )
V_26 = F_2 ( V_19 ,
struct V_25 ,
V_28 ) ;
return V_26 ;
}
static struct V_29 *
F_15 ( struct V_8 * V_9 , const void * V_16 )
{
struct V_5 * V_19 ;
struct V_29 * V_30 = NULL ;
V_19 = F_7 ( V_9 -> V_10 . V_31 , V_16 ) ;
if ( V_19 )
V_30 = F_2 ( V_19 ,
struct V_29 ,
V_28 ) ;
return V_30 ;
}
static void
F_16 ( struct V_25 * V_26 )
{
if ( F_17 ( & V_26 -> V_28 . V_24 ) )
F_18 ( V_26 , V_28 . V_32 ) ;
}
static void F_19 ( struct V_33 * V_32 )
{
struct V_5 * V_19 ;
struct V_29 * V_30 ;
V_19 = F_2 ( V_32 , struct V_5 , V_32 ) ;
V_30 = F_2 ( V_19 ,
struct V_29 , V_28 ) ;
F_20 ( V_30 ) ;
}
static void
F_21 ( struct V_29 * V_30 )
{
if ( F_17 ( & V_30 -> V_28 . V_24 ) ) {
F_22 ( V_30 ) ;
F_23 ( & V_30 -> V_28 . V_32 ,
F_19 ) ;
}
}
static void F_24 ( struct V_33 * V_32 )
{
struct V_34 * V_35 ;
V_35 = F_2 ( V_32 , struct V_34 , V_32 ) ;
F_25 ( V_35 -> V_36 ) ;
F_20 ( V_35 ) ;
}
static void
F_26 ( struct V_34 * V_35 )
{
if ( ! F_17 ( & V_35 -> V_24 ) )
return;
F_27 ( & V_35 -> V_36 -> V_37 ) ;
F_23 ( & V_35 -> V_32 , F_24 ) ;
}
static void F_28 ( struct V_8 * V_9 ,
const T_2 * V_38 , T_2 V_39 )
{
struct V_40 * V_41 , * V_42 , * V_43 ;
bool V_44 = false ;
bool V_45 , V_46 ;
V_41 = F_29 ( sizeof( * V_41 ) , V_47 ) ;
if ( ! V_41 )
return;
V_41 -> V_48 . V_39 = V_39 ;
memcpy ( V_41 -> V_48 . V_38 , V_38 , V_7 ) ;
V_45 = V_39 & V_49 ;
F_30 ( & V_9 -> V_10 . V_50 ) ;
F_31 (entry, safe, &bat_priv->tt.changes_list,
list) {
if ( ! F_11 ( V_42 -> V_48 . V_38 , V_38 ) )
continue;
V_46 = V_42 -> V_48 . V_39 & V_49 ;
if ( ! V_45 && V_46 )
goto V_51;
if ( V_45 && ! V_46 )
goto V_51;
continue;
V_51:
F_32 ( & V_42 -> V_52 ) ;
F_20 ( V_42 ) ;
F_20 ( V_41 ) ;
V_44 = true ;
goto V_53;
}
F_33 ( & V_41 -> V_52 , & V_9 -> V_10 . V_54 ) ;
V_53:
F_34 ( & V_9 -> V_10 . V_50 ) ;
if ( V_44 )
F_27 ( & V_9 -> V_10 . V_55 ) ;
else
F_35 ( & V_9 -> V_10 . V_55 ) ;
}
int F_36 ( int V_56 )
{
return V_56 * sizeof( struct V_57 ) ;
}
static int F_37 ( struct V_8 * V_9 )
{
if ( V_9 -> V_10 . V_27 )
return 0 ;
V_9 -> V_10 . V_27 = F_38 ( 1024 ) ;
if ( ! V_9 -> V_10 . V_27 )
return - V_58 ;
return 0 ;
}
void F_39 ( struct V_59 * V_60 , const T_2 * V_38 ,
int V_61 )
{
struct V_8 * V_9 = F_40 ( V_60 ) ;
struct V_25 * V_26 = NULL ;
struct V_29 * V_30 = NULL ;
struct V_17 * V_18 ;
struct V_1 * V_2 ;
struct V_34 * V_35 ;
int V_62 ;
V_26 = F_14 ( V_9 , V_38 ) ;
if ( V_26 ) {
V_26 -> V_63 = V_64 ;
V_26 -> V_28 . V_39 &= ~ V_65 ;
goto V_66;
}
V_26 = F_29 ( sizeof( * V_26 ) , V_47 ) ;
if ( ! V_26 )
goto V_66;
F_41 ( V_67 , V_9 ,
L_1 , V_38 ,
( T_2 ) F_42 ( & V_9 -> V_10 . V_68 ) ) ;
memcpy ( V_26 -> V_28 . V_38 , V_38 , V_7 ) ;
V_26 -> V_28 . V_39 = V_69 ;
if ( F_43 ( V_61 ) )
V_26 -> V_28 . V_39 |= V_70 ;
F_44 ( & V_26 -> V_28 . V_24 , 2 ) ;
V_26 -> V_63 = V_64 ;
V_26 -> V_28 . V_71 = V_26 -> V_63 ;
if ( F_11 ( V_38 , V_60 -> V_72 ) )
V_26 -> V_28 . V_39 |= V_73 ;
V_26 -> V_28 . V_39 |= V_74 ;
V_62 = F_45 ( V_9 -> V_10 . V_27 , F_1 ,
F_8 ,
& V_26 -> V_28 ,
& V_26 -> V_28 . V_6 ) ;
if ( F_46 ( V_62 != 0 ) ) {
F_16 ( V_26 ) ;
goto V_66;
}
F_28 ( V_9 , V_38 , V_26 -> V_28 . V_39 ) ;
V_30 = F_15 ( V_9 , V_38 ) ;
if ( V_30 ) {
V_18 = & V_30 -> V_75 ;
F_9 () ;
F_10 (orig_entry, node, head, list) {
V_35 -> V_36 -> V_76 = true ;
F_47 ( V_9 ,
V_30 -> V_28 . V_38 ,
V_35 -> V_36 ) ;
}
F_13 () ;
V_30 -> V_28 . V_39 |= V_77 ;
V_30 -> V_78 = V_64 ;
}
V_66:
if ( V_26 )
F_16 ( V_26 ) ;
if ( V_30 )
F_21 ( V_30 ) ;
}
static void F_48 ( unsigned char * * V_79 ,
int * V_80 ,
int V_81 ,
int V_82 )
{
unsigned char * V_83 ;
V_83 = F_29 ( V_82 , V_47 ) ;
if ( V_83 ) {
memcpy ( V_83 , * V_79 , V_81 ) ;
F_20 ( * V_79 ) ;
* V_79 = V_83 ;
* V_80 = V_82 ;
}
}
static void F_49 ( struct V_8 * V_9 ,
unsigned char * * V_79 ,
int * V_80 ,
int V_81 )
{
struct V_84 * V_85 ;
int V_86 ;
V_85 = F_50 ( V_9 ) ;
V_86 = V_81 ;
V_86 += F_36 ( F_42 ( & V_9 -> V_10 . V_55 ) ) ;
if ( ( ! V_85 ) || ( V_86 > V_85 -> V_60 -> V_87 ) )
V_86 = V_81 ;
F_48 ( V_79 , V_80 ,
V_81 , V_86 ) ;
if ( V_85 )
F_51 ( V_85 ) ;
}
static int F_52 ( struct V_8 * V_9 ,
unsigned char * * V_79 ,
int * V_80 ,
int V_81 )
{
struct V_40 * V_42 , * V_43 ;
int V_88 = 0 , V_89 = 0 , V_90 ;
unsigned char * V_91 ;
F_49 ( V_9 , V_79 ,
V_80 , V_81 ) ;
V_90 = * V_80 - V_81 ;
V_91 = * V_79 + V_81 ;
if ( V_90 > 0 )
V_89 = V_90 / F_36 ( 1 ) ;
F_30 ( & V_9 -> V_10 . V_50 ) ;
F_44 ( & V_9 -> V_10 . V_55 , 0 ) ;
F_31 (entry, safe, &bat_priv->tt.changes_list,
list) {
if ( V_88 < V_89 ) {
memcpy ( V_91 + F_36 ( V_88 ) ,
& V_42 -> V_48 , sizeof( struct V_57 ) ) ;
V_88 ++ ;
}
F_32 ( & V_42 -> V_52 ) ;
F_20 ( V_42 ) ;
}
F_34 ( & V_9 -> V_10 . V_50 ) ;
F_30 ( & V_9 -> V_10 . V_92 ) ;
F_20 ( V_9 -> V_10 . V_93 ) ;
V_9 -> V_10 . V_94 = 0 ;
V_9 -> V_10 . V_93 = NULL ;
if ( V_90 > 0 ) {
V_9 -> V_10 . V_93 = F_29 ( V_90 , V_47 ) ;
if ( V_9 -> V_10 . V_93 ) {
memcpy ( V_9 -> V_10 . V_93 , V_91 , V_90 ) ;
V_9 -> V_10 . V_94 = V_90 ;
}
}
F_34 ( & V_9 -> V_10 . V_92 ) ;
return V_88 ;
}
int F_53 ( struct V_95 * V_96 , void * V_97 )
{
struct V_59 * V_98 = (struct V_59 * ) V_96 -> V_99 ;
struct V_8 * V_9 = F_40 ( V_98 ) ;
struct V_14 * V_15 = V_9 -> V_10 . V_27 ;
struct V_5 * V_19 ;
struct V_84 * V_85 ;
struct V_1 * V_2 ;
struct V_17 * V_18 ;
T_1 V_100 ;
int V_101 = 0 ;
V_85 = F_50 ( V_9 ) ;
if ( ! V_85 ) {
V_101 = F_54 ( V_96 ,
L_2 ,
V_98 -> V_102 ) ;
goto V_66;
}
if ( V_85 -> V_103 != V_104 ) {
V_101 = F_54 ( V_96 ,
L_3 ,
V_98 -> V_102 ) ;
goto V_66;
}
F_54 ( V_96 ,
L_4 ,
V_98 -> V_102 , ( T_2 ) F_42 ( & V_9 -> V_10 . V_68 ) ) ;
for ( V_100 = 0 ; V_100 < V_15 -> V_22 ; V_100 ++ ) {
V_18 = & V_15 -> V_23 [ V_100 ] ;
F_9 () ;
F_10 (tt_common_entry, node,
head, hash_entry) {
F_54 ( V_96 , L_5 ,
V_19 -> V_38 ,
( V_19 -> V_39 &
V_77 ? 'R' : '.' ) ,
( V_19 -> V_39 &
V_73 ? 'P' : '.' ) ,
( V_19 -> V_39 &
V_74 ? 'N' : '.' ) ,
( V_19 -> V_39 &
V_65 ? 'X' : '.' ) ,
( V_19 -> V_39 &
V_70 ? 'W' : '.' ) ) ;
}
F_13 () ;
}
V_66:
if ( V_85 )
F_51 ( V_85 ) ;
return V_101 ;
}
static void
F_55 ( struct V_8 * V_9 ,
struct V_25 * V_26 ,
T_3 V_39 , const char * V_105 )
{
F_28 ( V_9 , V_26 -> V_28 . V_38 ,
V_26 -> V_28 . V_39 | V_39 ) ;
V_26 -> V_28 . V_39 |= V_65 ;
F_41 ( V_67 , V_9 ,
L_6 ,
V_26 -> V_28 . V_38 , V_105 ) ;
}
void F_56 ( struct V_8 * V_9 , const T_2 * V_38 ,
const char * V_105 , bool V_106 )
{
struct V_25 * V_26 = NULL ;
T_3 V_39 ;
V_26 = F_14 ( V_9 , V_38 ) ;
if ( ! V_26 )
goto V_66;
V_39 = V_49 ;
if ( V_106 )
V_39 |= V_77 ;
F_55 ( V_9 , V_26 , V_39 , V_105 ) ;
V_66:
if ( V_26 )
F_16 ( V_26 ) ;
}
static void F_57 ( struct V_8 * V_9 ,
struct V_17 * V_18 )
{
struct V_25 * V_26 ;
struct V_5 * V_19 ;
struct V_1 * V_2 , * V_107 ;
F_58 (tt_common_entry, node, node_tmp, head,
hash_entry) {
V_26 = F_2 ( V_19 ,
struct V_25 ,
V_28 ) ;
if ( V_26 -> V_28 . V_39 & V_73 )
continue;
if ( V_26 -> V_28 . V_39 & V_65 )
continue;
if ( ! F_59 ( V_26 -> V_63 ,
V_108 ) )
continue;
F_55 ( V_9 , V_26 ,
V_49 , L_7 ) ;
}
}
static void F_60 ( struct V_8 * V_9 )
{
struct V_14 * V_15 = V_9 -> V_10 . V_27 ;
struct V_17 * V_18 ;
T_4 * V_109 ;
T_1 V_100 ;
for ( V_100 = 0 ; V_100 < V_15 -> V_22 ; V_100 ++ ) {
V_18 = & V_15 -> V_23 [ V_100 ] ;
V_109 = & V_15 -> V_110 [ V_100 ] ;
F_30 ( V_109 ) ;
F_57 ( V_9 , V_18 ) ;
F_34 ( V_109 ) ;
}
}
static void F_61 ( struct V_8 * V_9 )
{
struct V_14 * V_15 ;
T_4 * V_109 ;
struct V_5 * V_19 ;
struct V_25 * V_111 ;
struct V_1 * V_2 , * V_107 ;
struct V_17 * V_18 ;
T_1 V_100 ;
if ( ! V_9 -> V_10 . V_27 )
return;
V_15 = V_9 -> V_10 . V_27 ;
for ( V_100 = 0 ; V_100 < V_15 -> V_22 ; V_100 ++ ) {
V_18 = & V_15 -> V_23 [ V_100 ] ;
V_109 = & V_15 -> V_110 [ V_100 ] ;
F_30 ( V_109 ) ;
F_58 (tt_common_entry, node, node_tmp,
head, hash_entry) {
F_62 ( V_2 ) ;
V_111 = F_2 ( V_19 ,
struct V_25 ,
V_28 ) ;
F_16 ( V_111 ) ;
}
F_34 ( V_109 ) ;
}
F_63 ( V_15 ) ;
V_9 -> V_10 . V_27 = NULL ;
}
static int F_64 ( struct V_8 * V_9 )
{
if ( V_9 -> V_10 . V_31 )
return 0 ;
V_9 -> V_10 . V_31 = F_38 ( 1024 ) ;
if ( ! V_9 -> V_10 . V_31 )
return - V_58 ;
return 0 ;
}
static void F_65 ( struct V_8 * V_9 )
{
struct V_40 * V_42 , * V_43 ;
F_30 ( & V_9 -> V_10 . V_50 ) ;
F_31 (entry, safe, &bat_priv->tt.changes_list,
list) {
F_32 ( & V_42 -> V_52 ) ;
F_20 ( V_42 ) ;
}
F_44 ( & V_9 -> V_10 . V_55 , 0 ) ;
F_34 ( & V_9 -> V_10 . V_50 ) ;
}
static struct V_34 *
F_66 ( const struct V_29 * V_42 ,
const struct V_112 * V_36 )
{
struct V_34 * V_113 , * V_35 = NULL ;
const struct V_17 * V_18 ;
struct V_1 * V_2 ;
F_9 () ;
V_18 = & V_42 -> V_75 ;
F_10 (tmp_orig_entry, node, head, list) {
if ( V_113 -> V_36 != V_36 )
continue;
if ( ! F_12 ( & V_113 -> V_24 ) )
continue;
V_35 = V_113 ;
break;
}
F_13 () ;
return V_35 ;
}
static bool
F_67 ( const struct V_29 * V_42 ,
const struct V_112 * V_36 )
{
struct V_34 * V_35 ;
bool V_114 = false ;
V_35 = F_66 ( V_42 , V_36 ) ;
if ( V_35 ) {
V_114 = true ;
F_26 ( V_35 ) ;
}
return V_114 ;
}
static void
F_68 ( struct V_29 * V_115 ,
struct V_112 * V_36 , int V_116 )
{
struct V_34 * V_35 ;
V_35 = F_66 ( V_115 , V_36 ) ;
if ( V_35 ) {
V_35 -> V_116 = V_116 ;
goto V_66;
}
V_35 = F_69 ( sizeof( * V_35 ) , V_47 ) ;
if ( ! V_35 )
goto V_66;
F_70 ( & V_35 -> V_52 ) ;
F_35 ( & V_36 -> V_24 ) ;
F_35 ( & V_36 -> V_37 ) ;
V_35 -> V_36 = V_36 ;
V_35 -> V_116 = V_116 ;
F_44 ( & V_35 -> V_24 , 2 ) ;
F_30 ( & V_115 -> V_109 ) ;
F_71 ( & V_35 -> V_52 ,
& V_115 -> V_75 ) ;
F_34 ( & V_115 -> V_109 ) ;
V_66:
if ( V_35 )
F_26 ( V_35 ) ;
}
int F_72 ( struct V_8 * V_9 ,
struct V_112 * V_36 ,
const unsigned char * V_117 , T_2 V_39 ,
T_2 V_116 )
{
struct V_29 * V_30 = NULL ;
int V_101 = 0 ;
int V_62 ;
struct V_5 * V_28 ;
V_30 = F_15 ( V_9 , V_117 ) ;
if ( ! V_30 ) {
V_30 = F_69 ( sizeof( * V_30 ) , V_47 ) ;
if ( ! V_30 )
goto V_66;
V_28 = & V_30 -> V_28 ;
memcpy ( V_28 -> V_38 , V_117 , V_7 ) ;
V_28 -> V_39 = V_39 ;
V_30 -> V_78 = 0 ;
F_44 ( & V_28 -> V_24 , 2 ) ;
V_28 -> V_71 = V_64 ;
F_73 ( & V_30 -> V_75 ) ;
F_74 ( & V_30 -> V_109 ) ;
V_62 = F_45 ( V_9 -> V_10 . V_31 ,
F_1 ,
F_8 , V_28 ,
& V_28 -> V_6 ) ;
if ( F_46 ( V_62 != 0 ) ) {
F_21 ( V_30 ) ;
goto V_118;
}
} else {
if ( V_39 & V_119 )
goto V_66;
V_30 -> V_28 . V_39 &= ~ V_119 ;
V_30 -> V_28 . V_39 |= V_39 ;
if ( V_30 -> V_28 . V_39 & V_77 ) {
F_22 ( V_30 ) ;
V_30 -> V_28 . V_39 &= ~ V_77 ;
V_30 -> V_78 = 0 ;
}
}
F_68 ( V_30 , V_36 , V_116 ) ;
F_41 ( V_67 , V_9 ,
L_8 ,
V_30 -> V_28 . V_38 , V_36 -> V_120 ) ;
V_118:
F_56 ( V_9 , V_30 -> V_28 . V_38 ,
L_9 ,
V_39 & V_77 ) ;
V_101 = 1 ;
V_66:
if ( V_30 )
F_21 ( V_30 ) ;
return V_101 ;
}
static void
F_75 ( struct V_29 * V_30 ,
struct V_95 * V_96 )
{
struct V_17 * V_18 ;
struct V_1 * V_2 ;
struct V_34 * V_35 ;
struct V_5 * V_19 ;
T_3 V_39 ;
T_2 V_121 ;
V_19 = & V_30 -> V_28 ;
V_18 = & V_30 -> V_75 ;
F_10 (orig_entry, node, head, list) {
V_39 = V_19 -> V_39 ;
V_121 = F_42 ( & V_35 -> V_36 -> V_121 ) ;
F_54 ( V_96 , L_10 ,
V_30 -> V_28 . V_38 , V_35 -> V_116 ,
V_35 -> V_36 -> V_120 , V_121 ,
( V_39 & V_77 ? 'R' : '.' ) ,
( V_39 & V_70 ? 'W' : '.' ) ,
( V_39 & V_119 ? 'T' : '.' ) ) ;
}
}
int F_76 ( struct V_95 * V_96 , void * V_97 )
{
struct V_59 * V_98 = (struct V_59 * ) V_96 -> V_99 ;
struct V_8 * V_9 = F_40 ( V_98 ) ;
struct V_14 * V_15 = V_9 -> V_10 . V_31 ;
struct V_5 * V_19 ;
struct V_29 * V_115 ;
struct V_84 * V_85 ;
struct V_1 * V_2 ;
struct V_17 * V_18 ;
T_1 V_100 ;
int V_101 = 0 ;
V_85 = F_50 ( V_9 ) ;
if ( ! V_85 ) {
V_101 = F_54 ( V_96 ,
L_2 ,
V_98 -> V_102 ) ;
goto V_66;
}
if ( V_85 -> V_103 != V_104 ) {
V_101 = F_54 ( V_96 ,
L_3 ,
V_98 -> V_102 ) ;
goto V_66;
}
F_54 ( V_96 ,
L_11 ,
V_98 -> V_102 ) ;
F_54 ( V_96 , L_12 ,
L_13 , L_14 , L_15 , L_16 , L_17 ) ;
for ( V_100 = 0 ; V_100 < V_15 -> V_22 ; V_100 ++ ) {
V_18 = & V_15 -> V_23 [ V_100 ] ;
F_9 () ;
F_10 (tt_common_entry, node,
head, hash_entry) {
V_115 = F_2 ( V_19 ,
struct V_29 ,
V_28 ) ;
F_75 ( V_115 , V_96 ) ;
}
F_13 () ;
}
V_66:
if ( V_85 )
F_51 ( V_85 ) ;
return V_101 ;
}
static void
F_22 ( struct V_29 * V_30 )
{
struct V_17 * V_18 ;
struct V_1 * V_2 , * V_43 ;
struct V_34 * V_35 ;
F_30 ( & V_30 -> V_109 ) ;
V_18 = & V_30 -> V_75 ;
F_58 (orig_entry, node, safe, head, list) {
F_62 ( V_2 ) ;
F_26 ( V_35 ) ;
}
F_34 ( & V_30 -> V_109 ) ;
}
static void
F_77 ( struct V_8 * V_9 ,
struct V_29 * V_30 ,
struct V_112 * V_36 ,
const char * V_105 )
{
struct V_17 * V_18 ;
struct V_1 * V_2 , * V_43 ;
struct V_34 * V_35 ;
F_30 ( & V_30 -> V_109 ) ;
V_18 = & V_30 -> V_75 ;
F_58 (orig_entry, node, safe, head, list) {
if ( V_35 -> V_36 == V_36 ) {
F_41 ( V_67 , V_9 ,
L_18 ,
V_36 -> V_120 ,
V_30 -> V_28 . V_38 , V_105 ) ;
F_62 ( V_2 ) ;
F_26 ( V_35 ) ;
}
}
F_34 ( & V_30 -> V_109 ) ;
}
static void
F_78 ( struct V_8 * V_9 ,
struct V_29 * V_30 ,
const char * V_105 )
{
F_41 ( V_67 , V_9 ,
L_19 ,
V_30 -> V_28 . V_38 , V_105 ) ;
F_79 ( V_9 -> V_10 . V_31 , F_1 ,
F_8 , V_30 -> V_28 . V_38 ) ;
F_21 ( V_30 ) ;
}
static void
F_80 ( struct V_8 * V_9 ,
struct V_29 * V_30 ,
struct V_112 * V_36 ,
const char * V_105 )
{
bool V_122 = true ;
struct V_17 * V_18 ;
struct V_1 * V_2 ;
struct V_34 * V_35 ;
F_9 () ;
V_18 = & V_30 -> V_75 ;
F_10 (orig_entry, node, head, list) {
if ( V_35 -> V_36 != V_36 ) {
V_122 = false ;
break;
}
}
F_13 () ;
if ( V_122 ) {
V_30 -> V_28 . V_39 |= V_77 ;
V_30 -> V_78 = V_64 ;
} else
F_77 ( V_9 , V_30 ,
V_36 , V_105 ) ;
}
static void F_81 ( struct V_8 * V_9 ,
struct V_112 * V_36 ,
const unsigned char * V_38 ,
const char * V_105 , bool V_106 )
{
struct V_29 * V_30 = NULL ;
struct V_25 * V_123 = NULL ;
V_30 = F_15 ( V_9 , V_38 ) ;
if ( ! V_30 )
goto V_66;
if ( ! V_106 ) {
F_77 ( V_9 , V_30 ,
V_36 , V_105 ) ;
if ( F_82 ( & V_30 -> V_75 ) )
F_78 ( V_9 , V_30 ,
V_105 ) ;
goto V_66;
}
V_123 = F_14 ( V_9 ,
V_30 -> V_28 . V_38 ) ;
if ( V_123 ) {
F_22 ( V_30 ) ;
F_78 ( V_9 , V_30 , V_105 ) ;
} else
F_80 ( V_9 , V_30 ,
V_36 , V_105 ) ;
V_66:
if ( V_30 )
F_21 ( V_30 ) ;
if ( V_123 )
F_16 ( V_123 ) ;
}
void F_83 ( struct V_8 * V_9 ,
struct V_112 * V_36 ,
const char * V_105 )
{
struct V_29 * V_115 ;
struct V_5 * V_19 ;
T_1 V_100 ;
struct V_14 * V_15 = V_9 -> V_10 . V_31 ;
struct V_1 * V_2 , * V_43 ;
struct V_17 * V_18 ;
T_4 * V_109 ;
if ( ! V_15 )
return;
for ( V_100 = 0 ; V_100 < V_15 -> V_22 ; V_100 ++ ) {
V_18 = & V_15 -> V_23 [ V_100 ] ;
V_109 = & V_15 -> V_110 [ V_100 ] ;
F_30 ( V_109 ) ;
F_58 (tt_common_entry, node, safe,
head, hash_entry) {
V_115 = F_2 ( V_19 ,
struct V_29 ,
V_28 ) ;
F_77 ( V_9 , V_115 ,
V_36 , V_105 ) ;
if ( F_82 ( & V_115 -> V_75 ) ) {
F_41 ( V_67 , V_9 ,
L_19 ,
V_115 -> V_28 . V_38 , V_105 ) ;
F_62 ( V_2 ) ;
F_21 ( V_115 ) ;
}
}
F_34 ( V_109 ) ;
}
V_36 -> V_124 = false ;
}
static bool F_84 ( struct V_29 * V_115 ,
char * * V_125 )
{
bool V_126 = false ;
unsigned long V_127 = V_128 ;
unsigned long V_129 = V_130 ;
if ( ( V_115 -> V_28 . V_39 & V_77 ) &&
F_59 ( V_115 -> V_78 , V_127 ) ) {
V_126 = true ;
* V_125 = L_20 ;
}
if ( ( V_115 -> V_28 . V_39 & V_119 ) &&
F_59 ( V_115 -> V_28 . V_71 , V_129 ) ) {
V_126 = true ;
* V_125 = L_21 ;
}
return V_126 ;
}
static void F_85 ( struct V_8 * V_9 )
{
struct V_14 * V_15 = V_9 -> V_10 . V_31 ;
struct V_17 * V_18 ;
struct V_1 * V_2 , * V_107 ;
T_4 * V_109 ;
T_1 V_100 ;
char * V_125 = NULL ;
struct V_5 * V_131 ;
struct V_29 * V_115 ;
for ( V_100 = 0 ; V_100 < V_15 -> V_22 ; V_100 ++ ) {
V_18 = & V_15 -> V_23 [ V_100 ] ;
V_109 = & V_15 -> V_110 [ V_100 ] ;
F_30 ( V_109 ) ;
F_58 (tt_common, node, node_tmp, head,
hash_entry) {
V_115 = F_2 ( V_131 ,
struct V_29 ,
V_28 ) ;
if ( ! F_84 ( V_115 , & V_125 ) )
continue;
F_41 ( V_67 , V_9 ,
L_22 ,
V_115 -> V_28 . V_38 , V_125 ) ;
F_62 ( V_2 ) ;
F_21 ( V_115 ) ;
}
F_34 ( V_109 ) ;
}
}
static void F_86 ( struct V_8 * V_9 )
{
struct V_14 * V_15 ;
T_4 * V_109 ;
struct V_5 * V_19 ;
struct V_29 * V_115 ;
struct V_1 * V_2 , * V_107 ;
struct V_17 * V_18 ;
T_1 V_100 ;
if ( ! V_9 -> V_10 . V_31 )
return;
V_15 = V_9 -> V_10 . V_31 ;
for ( V_100 = 0 ; V_100 < V_15 -> V_22 ; V_100 ++ ) {
V_18 = & V_15 -> V_23 [ V_100 ] ;
V_109 = & V_15 -> V_110 [ V_100 ] ;
F_30 ( V_109 ) ;
F_58 (tt_common_entry, node, node_tmp,
head, hash_entry) {
F_62 ( V_2 ) ;
V_115 = F_2 ( V_19 ,
struct V_29 ,
V_28 ) ;
F_21 ( V_115 ) ;
}
F_34 ( V_109 ) ;
}
F_63 ( V_15 ) ;
V_9 -> V_10 . V_31 = NULL ;
}
static bool
F_87 ( struct V_25 * V_26 ,
struct V_29 * V_30 )
{
bool V_101 = false ;
if ( V_26 -> V_28 . V_39 & V_70 &&
V_30 -> V_28 . V_39 & V_70 )
V_101 = true ;
return V_101 ;
}
struct V_112 * F_88 ( struct V_8 * V_9 ,
const T_2 * V_132 ,
const T_2 * V_38 )
{
struct V_25 * V_26 = NULL ;
struct V_29 * V_30 = NULL ;
struct V_112 * V_36 = NULL ;
struct V_133 * V_134 = NULL ;
struct V_17 * V_18 ;
struct V_1 * V_2 ;
struct V_34 * V_35 ;
int V_135 ;
if ( V_132 && F_42 ( & V_9 -> V_136 ) ) {
V_26 = F_14 ( V_9 , V_132 ) ;
if ( ! V_26 )
goto V_66;
}
V_30 = F_15 ( V_9 , V_38 ) ;
if ( ! V_30 )
goto V_66;
if ( V_26 &&
F_87 ( V_26 , V_30 ) )
goto V_66;
V_135 = 0 ;
F_9 () ;
V_18 = & V_30 -> V_75 ;
F_10 (orig_entry, node, head, list) {
V_134 = F_89 ( V_35 -> V_36 ) ;
if ( ! V_134 )
continue;
if ( V_134 -> V_137 > V_135 ) {
V_36 = V_35 -> V_36 ;
V_135 = V_134 -> V_137 ;
}
F_90 ( V_134 ) ;
}
if ( V_36 && ! F_12 ( & V_36 -> V_24 ) )
V_36 = NULL ;
F_13 () ;
V_66:
if ( V_30 )
F_21 ( V_30 ) ;
if ( V_26 )
F_16 ( V_26 ) ;
return V_36 ;
}
static T_3 F_91 ( struct V_8 * V_9 ,
struct V_112 * V_36 )
{
T_3 V_138 = 0 , V_139 ;
struct V_14 * V_15 = V_9 -> V_10 . V_31 ;
struct V_5 * V_131 ;
struct V_29 * V_115 ;
struct V_1 * V_2 ;
struct V_17 * V_18 ;
T_1 V_100 ;
int V_140 ;
for ( V_100 = 0 ; V_100 < V_15 -> V_22 ; V_100 ++ ) {
V_18 = & V_15 -> V_23 [ V_100 ] ;
F_9 () ;
F_10 (tt_common, node, head, hash_entry) {
V_115 = F_2 ( V_131 ,
struct V_29 ,
V_28 ) ;
if ( V_131 -> V_39 & V_77 )
continue;
if ( V_131 -> V_39 & V_119 )
continue;
if ( ! F_67 ( V_115 ,
V_36 ) )
continue;
V_139 = 0 ;
for ( V_140 = 0 ; V_140 < V_7 ; V_140 ++ )
V_139 = F_92 ( V_139 ,
V_131 -> V_38 [ V_140 ] ) ;
V_138 ^= V_139 ;
}
F_13 () ;
}
return V_138 ;
}
static T_3 F_93 ( struct V_8 * V_9 )
{
T_3 V_138 = 0 , V_139 ;
struct V_14 * V_15 = V_9 -> V_10 . V_27 ;
struct V_5 * V_131 ;
struct V_1 * V_2 ;
struct V_17 * V_18 ;
T_1 V_100 ;
int V_140 ;
for ( V_100 = 0 ; V_100 < V_15 -> V_22 ; V_100 ++ ) {
V_18 = & V_15 -> V_23 [ V_100 ] ;
F_9 () ;
F_10 (tt_common, node, head, hash_entry) {
if ( V_131 -> V_39 & V_74 )
continue;
V_139 = 0 ;
for ( V_140 = 0 ; V_140 < V_7 ; V_140 ++ )
V_139 = F_92 ( V_139 ,
V_131 -> V_38 [ V_140 ] ) ;
V_138 ^= V_139 ;
}
F_13 () ;
}
return V_138 ;
}
static void F_94 ( struct V_8 * V_9 )
{
struct V_141 * V_2 , * V_43 ;
F_30 ( & V_9 -> V_10 . V_142 ) ;
F_31 (node, safe, &bat_priv->tt.req_list, list) {
F_32 ( & V_2 -> V_52 ) ;
F_20 ( V_2 ) ;
}
F_34 ( & V_9 -> V_10 . V_142 ) ;
}
static void F_95 ( struct V_8 * V_9 ,
struct V_112 * V_36 ,
const unsigned char * V_91 ,
T_2 V_143 )
{
T_3 V_144 = F_36 ( V_143 ) ;
F_30 ( & V_36 -> V_145 ) ;
if ( V_144 > 0 ) {
F_20 ( V_36 -> V_91 ) ;
V_36 -> V_144 = 0 ;
V_36 -> V_91 = F_29 ( V_144 , V_47 ) ;
if ( V_36 -> V_91 ) {
memcpy ( V_36 -> V_91 , V_91 , V_144 ) ;
V_36 -> V_144 = V_144 ;
}
}
F_34 ( & V_36 -> V_145 ) ;
}
static void F_96 ( struct V_8 * V_9 )
{
struct V_141 * V_2 , * V_43 ;
F_30 ( & V_9 -> V_10 . V_142 ) ;
F_31 (node, safe, &bat_priv->tt.req_list, list) {
if ( F_59 ( V_2 -> V_146 ,
V_147 ) ) {
F_32 ( & V_2 -> V_52 ) ;
F_20 ( V_2 ) ;
}
}
F_34 ( & V_9 -> V_10 . V_142 ) ;
}
static struct V_141 *
F_97 ( struct V_8 * V_9 ,
struct V_112 * V_36 )
{
struct V_141 * V_148 , * V_149 = NULL ;
F_30 ( & V_9 -> V_10 . V_142 ) ;
F_98 (tt_req_node_tmp, &bat_priv->tt.req_list, list) {
if ( F_11 ( V_148 , V_36 ) &&
! F_59 ( V_148 -> V_146 ,
V_147 ) )
goto V_53;
}
V_149 = F_29 ( sizeof( * V_149 ) , V_47 ) ;
if ( ! V_149 )
goto V_53;
memcpy ( V_149 -> V_38 , V_36 -> V_120 , V_7 ) ;
V_149 -> V_146 = V_64 ;
F_99 ( & V_149 -> V_52 , & V_9 -> V_10 . V_150 ) ;
V_53:
F_34 ( & V_9 -> V_10 . V_142 ) ;
return V_149 ;
}
static int F_100 ( const void * V_151 ,
const void * V_152 )
{
const struct V_5 * V_19 = V_151 ;
if ( V_19 -> V_39 & V_74 )
return 0 ;
return 1 ;
}
static int F_101 ( const void * V_151 ,
const void * V_152 )
{
const struct V_5 * V_19 = V_151 ;
const struct V_29 * V_30 ;
const struct V_112 * V_36 = V_152 ;
if ( V_19 -> V_39 & V_77 ||
V_19 -> V_39 & V_119 )
return 0 ;
V_30 = F_2 ( V_19 ,
struct V_29 ,
V_28 ) ;
return F_67 ( V_30 , V_36 ) ;
}
static struct V_153 *
F_102 ( T_3 V_154 , T_2 V_116 ,
struct V_14 * V_15 ,
struct V_84 * V_85 ,
int (* F_103)( const void * , const void * ) ,
void * V_155 )
{
struct V_5 * V_19 ;
struct V_156 * V_157 ;
struct V_57 * V_158 ;
struct V_1 * V_2 ;
struct V_17 * V_18 ;
struct V_153 * V_159 = NULL ;
T_3 V_160 , V_161 ;
T_5 V_162 = sizeof( struct V_156 ) ;
T_1 V_100 ;
T_6 V_163 ;
if ( V_162 + V_154 > V_85 -> V_60 -> V_87 ) {
V_154 = V_85 -> V_60 -> V_87 - V_162 ;
V_154 -= V_154 % sizeof( struct V_57 ) ;
}
V_160 = V_154 / sizeof( struct V_57 ) ;
V_163 = V_162 + V_154 ;
V_159 = F_104 ( V_163 + V_164 ) ;
if ( ! V_159 )
goto V_66;
F_105 ( V_159 , V_164 ) ;
V_157 = (struct V_156 * ) F_106 ( V_159 , V_163 ) ;
V_157 -> V_116 = V_116 ;
V_158 = (struct V_57 * ) ( V_159 -> V_16 + V_162 ) ;
V_161 = 0 ;
F_9 () ;
for ( V_100 = 0 ; V_100 < V_15 -> V_22 ; V_100 ++ ) {
V_18 = & V_15 -> V_23 [ V_100 ] ;
F_10 (tt_common_entry, node,
head, hash_entry) {
if ( V_161 == V_160 )
break;
if ( ( F_103 ) && ( ! F_103 ( V_19 , V_155 ) ) )
continue;
memcpy ( V_158 -> V_38 , V_19 -> V_38 ,
V_7 ) ;
V_158 -> V_39 = V_19 -> V_39 ;
V_161 ++ ;
V_158 ++ ;
}
}
F_13 () ;
V_157 -> V_165 = F_107 ( V_161 ) ;
V_66:
return V_159 ;
}
static int F_108 ( struct V_8 * V_9 ,
struct V_112 * V_166 ,
T_2 V_116 , T_3 V_167 ,
bool V_168 )
{
struct V_153 * V_159 = NULL ;
struct V_156 * V_169 ;
struct V_133 * V_170 = NULL ;
struct V_84 * V_85 ;
struct V_141 * V_149 = NULL ;
int V_101 = 1 ;
T_6 V_171 ;
V_85 = F_50 ( V_9 ) ;
if ( ! V_85 )
goto V_66;
V_149 = F_97 ( V_9 , V_166 ) ;
if ( ! V_149 )
goto V_66;
V_159 = F_104 ( sizeof( * V_169 ) + V_164 ) ;
if ( ! V_159 )
goto V_66;
F_105 ( V_159 , V_164 ) ;
V_171 = sizeof( * V_169 ) ;
V_169 = (struct V_156 * ) F_106 ( V_159 , V_171 ) ;
V_169 -> V_172 . V_173 = V_174 ;
V_169 -> V_172 . V_175 = V_176 ;
memcpy ( V_169 -> V_132 , V_85 -> V_98 -> V_72 , V_7 ) ;
memcpy ( V_169 -> V_177 , V_166 -> V_120 , V_7 ) ;
V_169 -> V_172 . V_178 = V_179 ;
V_169 -> V_116 = V_116 ;
V_169 -> V_165 = F_107 ( V_167 ) ;
V_169 -> V_39 = V_180 ;
if ( V_168 )
V_169 -> V_39 |= V_181 ;
V_170 = F_89 ( V_166 ) ;
if ( ! V_170 )
goto V_66;
F_41 ( V_67 , V_9 ,
L_23 ,
V_166 -> V_120 , V_170 -> V_38 ,
( V_168 ? 'F' : '.' ) ) ;
F_109 ( V_9 , V_182 ) ;
F_110 ( V_159 , V_170 -> V_183 , V_170 -> V_38 ) ;
V_101 = 0 ;
V_66:
if ( V_170 )
F_90 ( V_170 ) ;
if ( V_85 )
F_51 ( V_85 ) ;
if ( V_101 )
F_111 ( V_159 ) ;
if ( V_101 && V_149 ) {
F_30 ( & V_9 -> V_10 . V_142 ) ;
F_32 ( & V_149 -> V_52 ) ;
F_34 ( & V_9 -> V_10 . V_142 ) ;
F_20 ( V_149 ) ;
}
return V_101 ;
}
static bool
F_112 ( struct V_8 * V_9 ,
struct V_156 * V_169 )
{
struct V_112 * V_184 = NULL ;
struct V_112 * V_185 = NULL ;
struct V_133 * V_170 = NULL ;
struct V_84 * V_85 = NULL ;
T_2 V_186 , V_187 , V_116 ;
int V_101 = false ;
unsigned char * V_91 ;
bool V_168 ;
T_3 V_154 , V_160 ;
struct V_153 * V_159 = NULL ;
struct V_156 * V_157 ;
T_2 * V_188 ;
T_6 V_163 ;
F_41 ( V_67 , V_9 ,
L_24 ,
V_169 -> V_132 , V_169 -> V_116 , V_169 -> V_177 ,
( V_169 -> V_39 & V_181 ? 'F' : '.' ) ) ;
V_184 = F_113 ( V_9 , V_169 -> V_177 ) ;
if ( ! V_184 )
goto V_66;
V_185 = F_113 ( V_9 , V_169 -> V_132 ) ;
if ( ! V_185 )
goto V_66;
V_170 = F_89 ( V_185 ) ;
if ( ! V_170 )
goto V_66;
V_85 = F_50 ( V_9 ) ;
if ( ! V_85 )
goto V_66;
V_186 = ( T_2 ) F_42 ( & V_184 -> V_121 ) ;
V_187 = V_169 -> V_116 ;
if ( V_186 != V_187 ||
V_169 -> V_165 != F_107 ( V_184 -> V_167 ) )
goto V_66;
if ( V_169 -> V_39 & V_181 ||
! V_184 -> V_91 )
V_168 = true ;
else
V_168 = false ;
if ( ! V_168 ) {
F_30 ( & V_184 -> V_145 ) ;
V_154 = V_184 -> V_144 ;
V_160 = V_154 / sizeof( struct V_57 ) ;
V_163 = sizeof( * V_157 ) + V_154 ;
V_159 = F_104 ( V_163 + V_164 ) ;
if ( ! V_159 )
goto V_53;
F_105 ( V_159 , V_164 ) ;
V_188 = F_106 ( V_159 , V_163 ) ;
V_157 = (struct V_156 * ) V_188 ;
V_157 -> V_116 = V_187 ;
V_157 -> V_165 = F_107 ( V_160 ) ;
V_91 = V_159 -> V_16 + sizeof( * V_157 ) ;
memcpy ( V_91 , V_184 -> V_91 ,
V_184 -> V_144 ) ;
F_34 ( & V_184 -> V_145 ) ;
} else {
V_154 = ( T_3 ) F_42 ( & V_184 -> V_37 ) ;
V_154 *= sizeof( struct V_57 ) ;
V_116 = ( T_2 ) F_42 ( & V_184 -> V_121 ) ;
V_159 = F_102 ( V_154 , V_116 ,
V_9 -> V_10 . V_31 ,
V_85 ,
F_101 ,
V_184 ) ;
if ( ! V_159 )
goto V_66;
V_157 = (struct V_156 * ) V_159 -> V_16 ;
}
V_157 -> V_172 . V_173 = V_174 ;
V_157 -> V_172 . V_175 = V_176 ;
V_157 -> V_172 . V_178 = V_179 ;
memcpy ( V_157 -> V_132 , V_184 -> V_120 , V_7 ) ;
memcpy ( V_157 -> V_177 , V_169 -> V_132 , V_7 ) ;
V_157 -> V_39 = V_189 ;
if ( V_168 )
V_157 -> V_39 |= V_181 ;
F_41 ( V_67 , V_9 ,
L_25 ,
V_185 -> V_120 , V_170 -> V_38 ,
V_184 -> V_120 , V_187 ) ;
F_109 ( V_9 , V_190 ) ;
F_110 ( V_159 , V_170 -> V_183 , V_170 -> V_38 ) ;
V_101 = true ;
goto V_66;
V_53:
F_34 ( & V_184 -> V_145 ) ;
V_66:
if ( V_185 )
F_25 ( V_185 ) ;
if ( V_184 )
F_25 ( V_184 ) ;
if ( V_170 )
F_90 ( V_170 ) ;
if ( V_85 )
F_51 ( V_85 ) ;
if ( ! V_101 )
F_111 ( V_159 ) ;
return V_101 ;
}
static bool
F_114 ( struct V_8 * V_9 ,
struct V_156 * V_169 )
{
struct V_112 * V_36 = NULL ;
struct V_133 * V_170 = NULL ;
struct V_84 * V_85 = NULL ;
T_2 V_191 , V_187 , V_116 ;
int V_101 = false ;
unsigned char * V_91 ;
bool V_168 ;
T_3 V_154 , V_160 ;
struct V_153 * V_159 = NULL ;
struct V_156 * V_157 ;
T_2 * V_188 ;
T_6 V_163 ;
F_41 ( V_67 , V_9 ,
L_26 ,
V_169 -> V_132 , V_169 -> V_116 ,
( V_169 -> V_39 & V_181 ? 'F' : '.' ) ) ;
V_191 = ( T_2 ) F_42 ( & V_9 -> V_10 . V_68 ) ;
V_187 = V_169 -> V_116 ;
V_36 = F_113 ( V_9 , V_169 -> V_132 ) ;
if ( ! V_36 )
goto V_66;
V_170 = F_89 ( V_36 ) ;
if ( ! V_170 )
goto V_66;
V_85 = F_50 ( V_9 ) ;
if ( ! V_85 )
goto V_66;
if ( V_169 -> V_39 & V_181 || V_191 != V_187 ||
! V_9 -> V_10 . V_93 )
V_168 = true ;
else
V_168 = false ;
if ( ! V_168 ) {
F_30 ( & V_9 -> V_10 . V_92 ) ;
V_154 = V_9 -> V_10 . V_94 ;
V_160 = V_154 / sizeof( struct V_57 ) ;
V_163 = sizeof( * V_157 ) + V_154 ;
V_159 = F_104 ( V_163 + V_164 ) ;
if ( ! V_159 )
goto V_53;
F_105 ( V_159 , V_164 ) ;
V_188 = F_106 ( V_159 , V_163 ) ;
V_157 = (struct V_156 * ) V_188 ;
V_157 -> V_116 = V_187 ;
V_157 -> V_165 = F_107 ( V_160 ) ;
V_91 = V_159 -> V_16 + sizeof( * V_157 ) ;
memcpy ( V_91 , V_9 -> V_10 . V_93 ,
V_9 -> V_10 . V_94 ) ;
F_34 ( & V_9 -> V_10 . V_92 ) ;
} else {
V_154 = ( T_3 ) F_42 ( & V_9 -> V_10 . V_192 ) ;
V_154 *= sizeof( struct V_57 ) ;
V_116 = ( T_2 ) F_42 ( & V_9 -> V_10 . V_68 ) ;
V_159 = F_102 ( V_154 , V_116 ,
V_9 -> V_10 . V_27 ,
V_85 ,
F_100 ,
NULL ) ;
if ( ! V_159 )
goto V_66;
V_157 = (struct V_156 * ) V_159 -> V_16 ;
}
V_157 -> V_172 . V_173 = V_174 ;
V_157 -> V_172 . V_175 = V_176 ;
V_157 -> V_172 . V_178 = V_179 ;
memcpy ( V_157 -> V_132 , V_85 -> V_98 -> V_72 , V_7 ) ;
memcpy ( V_157 -> V_177 , V_169 -> V_132 , V_7 ) ;
V_157 -> V_39 = V_189 ;
if ( V_168 )
V_157 -> V_39 |= V_181 ;
F_41 ( V_67 , V_9 ,
L_27 ,
V_36 -> V_120 , V_170 -> V_38 ,
( V_157 -> V_39 & V_181 ? 'F' : '.' ) ) ;
F_109 ( V_9 , V_190 ) ;
F_110 ( V_159 , V_170 -> V_183 , V_170 -> V_38 ) ;
V_101 = true ;
goto V_66;
V_53:
F_34 ( & V_9 -> V_10 . V_92 ) ;
V_66:
if ( V_36 )
F_25 ( V_36 ) ;
if ( V_170 )
F_90 ( V_170 ) ;
if ( V_85 )
F_51 ( V_85 ) ;
if ( ! V_101 )
F_111 ( V_159 ) ;
return true ;
}
bool F_115 ( struct V_8 * V_9 ,
struct V_156 * V_169 )
{
if ( F_116 ( V_169 -> V_177 ) ) {
if ( F_117 ( V_9 , V_169 -> V_132 ) )
return true ;
return F_114 ( V_9 , V_169 ) ;
} else {
return F_112 ( V_9 , V_169 ) ;
}
}
static void F_118 ( struct V_8 * V_9 ,
struct V_112 * V_36 ,
struct V_57 * V_158 ,
T_3 V_143 , T_2 V_116 )
{
int V_100 ;
int V_193 ;
for ( V_100 = 0 ; V_100 < V_143 ; V_100 ++ ) {
if ( ( V_158 + V_100 ) -> V_39 & V_49 ) {
V_193 = ( V_158 + V_100 ) -> V_39 & V_77 ;
F_81 ( V_9 , V_36 ,
( V_158 + V_100 ) -> V_38 ,
L_28 ,
V_193 ) ;
} else {
if ( ! F_72 ( V_9 , V_36 ,
( V_158 + V_100 ) -> V_38 ,
( V_158 + V_100 ) -> V_39 , V_116 ) )
return;
}
}
V_36 -> V_124 = true ;
}
static void F_119 ( struct V_8 * V_9 ,
struct V_156 * V_157 )
{
struct V_112 * V_36 = NULL ;
V_36 = F_113 ( V_9 , V_157 -> V_132 ) ;
if ( ! V_36 )
goto V_66;
F_83 ( V_9 , V_36 , L_29 ) ;
F_118 ( V_9 , V_36 ,
(struct V_57 * ) ( V_157 + 1 ) ,
F_120 ( V_157 -> V_165 ) ,
V_157 -> V_116 ) ;
F_30 ( & V_36 -> V_145 ) ;
F_20 ( V_36 -> V_91 ) ;
V_36 -> V_144 = 0 ;
V_36 -> V_91 = NULL ;
F_34 ( & V_36 -> V_145 ) ;
F_44 ( & V_36 -> V_121 , V_157 -> V_116 ) ;
V_66:
if ( V_36 )
F_25 ( V_36 ) ;
}
static void F_121 ( struct V_8 * V_9 ,
struct V_112 * V_36 ,
T_3 V_143 , T_2 V_116 ,
struct V_57 * V_158 )
{
F_118 ( V_9 , V_36 , V_158 ,
V_143 , V_116 ) ;
F_95 ( V_9 , V_36 ,
( unsigned char * ) V_158 , V_143 ) ;
F_44 ( & V_36 -> V_121 , V_116 ) ;
}
bool F_122 ( struct V_8 * V_9 , const T_2 * V_38 )
{
struct V_25 * V_26 = NULL ;
bool V_101 = false ;
V_26 = F_14 ( V_9 , V_38 ) ;
if ( ! V_26 )
goto V_66;
if ( V_26 -> V_28 . V_39 & V_65 )
goto V_66;
V_101 = true ;
V_66:
if ( V_26 )
F_16 ( V_26 ) ;
return V_101 ;
}
void F_123 ( struct V_8 * V_9 ,
struct V_156 * V_157 )
{
struct V_141 * V_2 , * V_43 ;
struct V_112 * V_36 = NULL ;
struct V_57 * V_158 ;
F_41 ( V_67 , V_9 ,
L_30 ,
V_157 -> V_132 , V_157 -> V_116 ,
F_120 ( V_157 -> V_165 ) ,
( V_157 -> V_39 & V_181 ? 'F' : '.' ) ) ;
if ( F_117 ( V_9 , V_157 -> V_132 ) )
goto V_66;
V_36 = F_113 ( V_9 , V_157 -> V_132 ) ;
if ( ! V_36 )
goto V_66;
if ( V_157 -> V_39 & V_181 ) {
F_119 ( V_9 , V_157 ) ;
} else {
V_158 = (struct V_57 * ) ( V_157 + 1 ) ;
F_121 ( V_9 , V_36 ,
F_120 ( V_157 -> V_165 ) ,
V_157 -> V_116 , V_158 ) ;
}
F_30 ( & V_9 -> V_10 . V_142 ) ;
F_31 (node, safe, &bat_priv->tt.req_list, list) {
if ( ! F_11 ( V_2 -> V_38 , V_157 -> V_132 ) )
continue;
F_32 ( & V_2 -> V_52 ) ;
F_20 ( V_2 ) ;
}
F_34 ( & V_9 -> V_10 . V_142 ) ;
V_36 -> V_167 = F_91 ( V_9 , V_36 ) ;
V_36 -> V_76 = false ;
V_66:
if ( V_36 )
F_25 ( V_36 ) ;
}
int F_124 ( struct V_8 * V_9 )
{
int V_101 ;
V_101 = F_37 ( V_9 ) ;
if ( V_101 < 0 )
return V_101 ;
V_101 = F_64 ( V_9 ) ;
if ( V_101 < 0 )
return V_101 ;
F_3 ( V_9 ) ;
return 1 ;
}
static void F_125 ( struct V_8 * V_9 )
{
struct V_194 * V_2 , * V_43 ;
F_30 ( & V_9 -> V_10 . V_195 ) ;
F_31 (node, safe, &bat_priv->tt.roam_list, list) {
F_32 ( & V_2 -> V_52 ) ;
F_20 ( V_2 ) ;
}
F_34 ( & V_9 -> V_10 . V_195 ) ;
}
static void F_126 ( struct V_8 * V_9 )
{
struct V_194 * V_2 , * V_43 ;
F_30 ( & V_9 -> V_10 . V_195 ) ;
F_31 (node, safe, &bat_priv->tt.roam_list, list) {
if ( ! F_59 ( V_2 -> V_196 ,
V_197 ) )
continue;
F_32 ( & V_2 -> V_52 ) ;
F_20 ( V_2 ) ;
}
F_34 ( & V_9 -> V_10 . V_195 ) ;
}
static bool F_127 ( struct V_8 * V_9 ,
T_2 * V_198 )
{
struct V_194 * V_199 ;
bool V_101 = false ;
F_30 ( & V_9 -> V_10 . V_195 ) ;
F_98 (tt_roam_node, &bat_priv->tt.roam_list, list) {
if ( ! F_11 ( V_199 -> V_38 , V_198 ) )
continue;
if ( F_59 ( V_199 -> V_196 ,
V_197 ) )
continue;
if ( ! F_128 ( & V_199 -> V_200 ) )
goto V_53;
V_101 = true ;
break;
}
if ( ! V_101 ) {
V_199 = F_29 ( sizeof( * V_199 ) , V_47 ) ;
if ( ! V_199 )
goto V_53;
V_199 -> V_196 = V_64 ;
F_44 ( & V_199 -> V_200 ,
V_201 - 1 ) ;
memcpy ( V_199 -> V_38 , V_198 , V_7 ) ;
F_99 ( & V_199 -> V_52 , & V_9 -> V_10 . V_202 ) ;
V_101 = true ;
}
V_53:
F_34 ( & V_9 -> V_10 . V_195 ) ;
return V_101 ;
}
static void F_47 ( struct V_8 * V_9 , T_2 * V_198 ,
struct V_112 * V_36 )
{
struct V_133 * V_170 = NULL ;
struct V_153 * V_159 = NULL ;
struct V_203 * V_204 ;
int V_101 = 1 ;
struct V_84 * V_85 ;
T_6 V_163 = sizeof( * V_204 ) ;
if ( ! F_127 ( V_9 , V_198 ) )
goto V_66;
V_159 = F_104 ( sizeof( * V_204 ) + V_164 ) ;
if ( ! V_159 )
goto V_66;
F_105 ( V_159 , V_164 ) ;
V_204 = (struct V_203 * ) F_106 ( V_159 , V_163 ) ;
V_204 -> V_172 . V_173 = V_205 ;
V_204 -> V_172 . V_175 = V_176 ;
V_204 -> V_172 . V_178 = V_179 ;
V_204 -> V_206 = 0 ;
V_85 = F_50 ( V_9 ) ;
if ( ! V_85 )
goto V_66;
memcpy ( V_204 -> V_132 , V_85 -> V_98 -> V_72 , V_7 ) ;
F_51 ( V_85 ) ;
memcpy ( V_204 -> V_177 , V_36 -> V_120 , V_7 ) ;
memcpy ( V_204 -> V_198 , V_198 , V_7 ) ;
V_170 = F_89 ( V_36 ) ;
if ( ! V_170 )
goto V_66;
F_41 ( V_67 , V_9 ,
L_31 ,
V_36 -> V_120 , V_198 , V_170 -> V_38 ) ;
F_109 ( V_9 , V_207 ) ;
F_110 ( V_159 , V_170 -> V_183 , V_170 -> V_38 ) ;
V_101 = 0 ;
V_66:
if ( V_170 )
F_90 ( V_170 ) ;
if ( V_101 )
F_111 ( V_159 ) ;
return;
}
static void V_12 ( struct V_208 * V_11 )
{
struct V_209 * V_209 ;
struct V_210 * V_211 ;
struct V_8 * V_9 ;
V_209 = F_2 ( V_11 , struct V_209 , V_11 ) ;
V_211 = F_2 ( V_209 , struct V_210 , V_11 ) ;
V_9 = F_2 ( V_211 , struct V_8 , V_10 ) ;
F_60 ( V_9 ) ;
F_85 ( V_9 ) ;
F_96 ( V_9 ) ;
F_126 ( V_9 ) ;
F_3 ( V_9 ) ;
}
void F_129 ( struct V_8 * V_9 )
{
F_130 ( & V_9 -> V_10 . V_11 ) ;
F_61 ( V_9 ) ;
F_86 ( V_9 ) ;
F_94 ( V_9 ) ;
F_65 ( V_9 ) ;
F_125 ( V_9 ) ;
F_20 ( V_9 -> V_10 . V_93 ) ;
}
static T_3 F_131 ( struct V_14 * V_15 ,
T_3 V_39 , bool V_212 )
{
T_1 V_100 ;
T_3 V_213 = 0 ;
struct V_17 * V_18 ;
struct V_1 * V_2 ;
struct V_5 * V_19 ;
if ( ! V_15 )
goto V_66;
for ( V_100 = 0 ; V_100 < V_15 -> V_22 ; V_100 ++ ) {
V_18 = & V_15 -> V_23 [ V_100 ] ;
F_9 () ;
F_10 (tt_common_entry, node,
head, hash_entry) {
if ( V_212 ) {
if ( ( V_19 -> V_39 & V_39 ) == V_39 )
continue;
V_19 -> V_39 |= V_39 ;
} else {
if ( ! ( V_19 -> V_39 & V_39 ) )
continue;
V_19 -> V_39 &= ~ V_39 ;
}
V_213 ++ ;
}
F_13 () ;
}
V_66:
return V_213 ;
}
static void F_132 ( struct V_8 * V_9 )
{
struct V_14 * V_15 = V_9 -> V_10 . V_27 ;
struct V_5 * V_131 ;
struct V_25 * V_111 ;
struct V_1 * V_2 , * V_107 ;
struct V_17 * V_18 ;
T_4 * V_109 ;
T_1 V_100 ;
if ( ! V_15 )
return;
for ( V_100 = 0 ; V_100 < V_15 -> V_22 ; V_100 ++ ) {
V_18 = & V_15 -> V_23 [ V_100 ] ;
V_109 = & V_15 -> V_110 [ V_100 ] ;
F_30 ( V_109 ) ;
F_58 (tt_common, node, node_tmp, head,
hash_entry) {
if ( ! ( V_131 -> V_39 & V_65 ) )
continue;
F_41 ( V_67 , V_9 ,
L_32 ,
V_131 -> V_38 ) ;
F_27 ( & V_9 -> V_10 . V_192 ) ;
F_62 ( V_2 ) ;
V_111 = F_2 ( V_131 ,
struct V_25 ,
V_28 ) ;
F_16 ( V_111 ) ;
}
F_34 ( V_109 ) ;
}
}
static int F_133 ( struct V_8 * V_9 ,
unsigned char * * V_79 ,
int * V_80 , int V_214 )
{
T_3 V_213 = 0 ;
if ( F_42 ( & V_9 -> V_10 . V_55 ) < 1 )
return - V_215 ;
V_213 = F_131 ( V_9 -> V_10 . V_27 ,
V_74 , false ) ;
F_134 ( V_213 , & V_9 -> V_10 . V_192 ) ;
F_132 ( V_9 ) ;
V_9 -> V_10 . V_216 = F_93 ( V_9 ) ;
F_35 ( & V_9 -> V_10 . V_68 ) ;
F_41 ( V_67 , V_9 ,
L_33 ,
( T_2 ) F_42 ( & V_9 -> V_10 . V_68 ) ) ;
V_9 -> V_10 . V_217 = false ;
F_44 ( & V_9 -> V_10 . V_218 , V_219 ) ;
return F_52 ( V_9 , V_79 ,
V_80 , V_214 ) ;
}
int F_135 ( struct V_8 * V_9 ,
unsigned char * * V_79 , int * V_80 ,
int V_214 )
{
int V_143 ;
V_143 = F_133 ( V_9 , V_79 ,
V_80 ,
V_214 ) ;
if ( ( V_143 < 0 ) &&
( ! F_128 ( & V_9 -> V_10 . V_218 ) ) ) {
F_48 ( V_79 , V_80 ,
V_214 , V_214 ) ;
V_143 = 0 ;
}
return V_143 ;
}
bool F_136 ( struct V_8 * V_9 , T_2 * V_132 ,
T_2 * V_177 )
{
struct V_25 * V_26 = NULL ;
struct V_29 * V_30 = NULL ;
bool V_101 = false ;
if ( ! F_42 ( & V_9 -> V_136 ) )
goto V_66;
V_26 = F_14 ( V_9 , V_177 ) ;
if ( ! V_26 )
goto V_66;
V_30 = F_15 ( V_9 , V_132 ) ;
if ( ! V_30 )
goto V_66;
if ( ! F_87 ( V_26 , V_30 ) )
goto V_66;
V_101 = true ;
V_66:
if ( V_30 )
F_21 ( V_30 ) ;
if ( V_26 )
F_16 ( V_26 ) ;
return V_101 ;
}
void F_137 ( struct V_8 * V_9 ,
struct V_112 * V_36 ,
const unsigned char * V_91 , T_2 V_143 ,
T_2 V_116 , T_3 V_167 )
{
T_2 V_186 = ( T_2 ) F_42 ( & V_36 -> V_121 ) ;
bool V_168 = true ;
struct V_57 * V_158 ;
if ( F_117 ( V_9 , V_36 -> V_120 ) )
return;
if ( ( ! V_36 -> V_124 && V_116 == 1 ) ||
V_116 - V_186 == 1 ) {
if ( ! V_143 ) {
V_168 = false ;
goto V_220;
}
V_158 = (struct V_57 * ) V_91 ;
F_121 ( V_9 , V_36 , V_143 ,
V_116 , V_158 ) ;
V_36 -> V_167 = F_91 ( V_9 , V_36 ) ;
if ( V_36 -> V_167 != V_167 )
goto V_220;
V_36 -> V_76 = false ;
} else {
if ( ! V_36 -> V_124 || V_116 != V_186 ||
V_36 -> V_167 != V_167 ) {
V_220:
F_41 ( V_67 , V_9 ,
L_34 ,
V_36 -> V_120 , V_116 , V_186 , V_167 ,
V_36 -> V_167 , V_143 ) ;
F_108 ( V_9 , V_36 , V_116 ,
V_167 , V_168 ) ;
return;
}
}
}
bool F_138 ( struct V_8 * V_9 ,
T_2 * V_38 )
{
struct V_29 * V_30 ;
bool V_101 = false ;
V_30 = F_15 ( V_9 , V_38 ) ;
if ( ! V_30 )
goto V_66;
V_101 = V_30 -> V_28 . V_39 & V_77 ;
F_21 ( V_30 ) ;
V_66:
return V_101 ;
}
bool F_139 ( struct V_8 * V_9 ,
struct V_112 * V_36 ,
const unsigned char * V_38 )
{
bool V_101 = false ;
if ( F_117 ( V_9 , V_36 -> V_120 ) )
goto V_66;
if ( ! F_72 ( V_9 , V_36 , V_38 ,
V_119 ,
F_42 ( & V_36 -> V_121 ) ) )
goto V_66;
F_41 ( V_67 , V_9 ,
L_35 ,
V_38 , V_36 -> V_120 ) ;
V_101 = true ;
V_66:
return V_101 ;
}
