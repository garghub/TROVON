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
static void F_39 ( struct V_8 * V_9 ,
struct V_29 * V_59 ,
const char * V_60 )
{
F_40 ( V_61 , V_9 ,
L_1 ,
V_59 -> V_28 . V_38 , V_60 ) ;
F_41 ( V_9 -> V_10 . V_31 , F_1 ,
F_8 , V_59 -> V_28 . V_38 ) ;
F_21 ( V_59 ) ;
}
void F_42 ( struct V_62 * V_63 , const T_2 * V_38 ,
int V_64 )
{
struct V_8 * V_9 = F_43 ( V_63 ) ;
struct V_25 * V_65 ;
struct V_29 * V_59 ;
struct V_17 * V_18 ;
struct V_1 * V_2 ;
struct V_34 * V_35 ;
int V_66 ;
bool V_67 = false ;
V_65 = F_14 ( V_9 , V_38 ) ;
V_59 = F_15 ( V_9 , V_38 ) ;
if ( V_65 ) {
V_65 -> V_68 = V_69 ;
if ( V_65 -> V_28 . V_39 & V_70 ) {
F_40 ( V_61 , V_9 ,
L_2 , V_38 ) ;
V_65 -> V_28 . V_39 &= ~ V_70 ;
goto V_71;
}
if ( V_65 -> V_28 . V_39 & V_72 ) {
F_40 ( V_61 , V_9 ,
L_3 ,
V_38 ) ;
V_65 -> V_28 . V_39 &= ~ V_72 ;
V_67 = true ;
}
goto V_73;
}
V_65 = F_29 ( sizeof( * V_65 ) , V_47 ) ;
if ( ! V_65 )
goto V_74;
F_40 ( V_61 , V_9 ,
L_4 , V_38 ,
( T_2 ) F_44 ( & V_9 -> V_10 . V_75 ) ) ;
memcpy ( V_65 -> V_28 . V_38 , V_38 , V_7 ) ;
V_65 -> V_28 . V_39 = V_76 ;
if ( F_45 ( V_64 ) )
V_65 -> V_28 . V_39 |= V_77 ;
F_46 ( & V_65 -> V_28 . V_24 , 2 ) ;
V_65 -> V_68 = V_69 ;
V_65 -> V_28 . V_78 = V_65 -> V_68 ;
if ( F_11 ( V_38 , V_63 -> V_79 ) )
V_65 -> V_28 . V_39 |= V_80 ;
V_65 -> V_28 . V_39 |= V_81 ;
V_66 = F_47 ( V_9 -> V_10 . V_27 , F_1 ,
F_8 , & V_65 -> V_28 ,
& V_65 -> V_28 . V_6 ) ;
if ( F_48 ( V_66 != 0 ) ) {
F_16 ( V_65 ) ;
goto V_74;
}
V_71:
F_28 ( V_9 , V_38 , V_65 -> V_28 . V_39 ) ;
V_73:
if ( V_59 && ! ( V_59 -> V_28 . V_39 & V_72 ) ) {
V_18 = & V_59 -> V_82 ;
F_9 () ;
F_10 (orig_entry, node, head, list) {
F_49 ( V_9 , V_59 -> V_28 . V_38 ,
V_35 -> V_36 ) ;
}
F_13 () ;
if ( V_67 ) {
F_39 ( V_9 , V_59 ,
L_5 ) ;
V_59 = NULL ;
} else {
V_59 -> V_28 . V_39 |= V_72 ;
V_59 -> V_83 = V_69 ;
}
}
V_74:
if ( V_65 )
F_16 ( V_65 ) ;
if ( V_59 )
F_21 ( V_59 ) ;
}
static void F_50 ( unsigned char * * V_84 ,
int * V_85 ,
int V_86 ,
int V_87 )
{
unsigned char * V_88 ;
V_88 = F_29 ( V_87 , V_47 ) ;
if ( V_88 ) {
memcpy ( V_88 , * V_84 , V_86 ) ;
F_20 ( * V_84 ) ;
* V_84 = V_88 ;
* V_85 = V_87 ;
}
}
static void F_51 ( struct V_8 * V_9 ,
unsigned char * * V_84 ,
int * V_85 ,
int V_86 )
{
struct V_89 * V_90 ;
int V_91 ;
V_90 = F_52 ( V_9 ) ;
V_91 = V_86 ;
V_91 += F_36 ( F_44 ( & V_9 -> V_10 . V_55 ) ) ;
if ( ( ! V_90 ) || ( V_91 > V_90 -> V_63 -> V_92 ) )
V_91 = V_86 ;
F_50 ( V_84 , V_85 ,
V_86 , V_91 ) ;
if ( V_90 )
F_53 ( V_90 ) ;
}
static int F_54 ( struct V_8 * V_9 ,
unsigned char * * V_84 ,
int * V_85 ,
int V_86 )
{
struct V_40 * V_42 , * V_43 ;
int V_93 = 0 , V_94 = 0 , V_95 ;
unsigned char * V_96 ;
F_51 ( V_9 , V_84 ,
V_85 , V_86 ) ;
V_95 = * V_85 - V_86 ;
V_96 = * V_84 + V_86 ;
if ( V_95 > 0 )
V_94 = V_95 / F_36 ( 1 ) ;
F_30 ( & V_9 -> V_10 . V_50 ) ;
F_46 ( & V_9 -> V_10 . V_55 , 0 ) ;
F_31 (entry, safe, &bat_priv->tt.changes_list,
list) {
if ( V_93 < V_94 ) {
memcpy ( V_96 + F_36 ( V_93 ) ,
& V_42 -> V_48 , sizeof( struct V_57 ) ) ;
V_93 ++ ;
}
F_32 ( & V_42 -> V_52 ) ;
F_20 ( V_42 ) ;
}
F_34 ( & V_9 -> V_10 . V_50 ) ;
F_30 ( & V_9 -> V_10 . V_97 ) ;
F_20 ( V_9 -> V_10 . V_98 ) ;
V_9 -> V_10 . V_99 = 0 ;
V_9 -> V_10 . V_98 = NULL ;
if ( V_95 > 0 ) {
V_9 -> V_10 . V_98 = F_29 ( V_95 , V_47 ) ;
if ( V_9 -> V_10 . V_98 ) {
memcpy ( V_9 -> V_10 . V_98 , V_96 , V_95 ) ;
V_9 -> V_10 . V_99 = V_95 ;
}
}
F_34 ( & V_9 -> V_10 . V_97 ) ;
return V_93 ;
}
int F_55 ( struct V_100 * V_101 , void * V_102 )
{
struct V_62 * V_103 = (struct V_62 * ) V_101 -> V_104 ;
struct V_8 * V_9 = F_43 ( V_103 ) ;
struct V_14 * V_15 = V_9 -> V_10 . V_27 ;
struct V_5 * V_19 ;
struct V_89 * V_90 ;
struct V_1 * V_2 ;
struct V_17 * V_18 ;
T_1 V_105 ;
V_90 = F_56 ( V_101 ) ;
if ( ! V_90 )
goto V_74;
F_57 ( V_101 ,
L_6 ,
V_103 -> V_106 , ( T_2 ) F_44 ( & V_9 -> V_10 . V_75 ) ) ;
for ( V_105 = 0 ; V_105 < V_15 -> V_22 ; V_105 ++ ) {
V_18 = & V_15 -> V_23 [ V_105 ] ;
F_9 () ;
F_10 (tt_common_entry, node,
head, hash_entry) {
F_57 ( V_101 , L_7 ,
V_19 -> V_38 ,
( V_19 -> V_39 &
V_72 ? 'R' : '.' ) ,
( V_19 -> V_39 &
V_80 ? 'P' : '.' ) ,
( V_19 -> V_39 &
V_81 ? 'N' : '.' ) ,
( V_19 -> V_39 &
V_70 ? 'X' : '.' ) ,
( V_19 -> V_39 &
V_77 ? 'W' : '.' ) ) ;
}
F_13 () ;
}
V_74:
if ( V_90 )
F_53 ( V_90 ) ;
return 0 ;
}
static void
F_58 ( struct V_8 * V_9 ,
struct V_25 * V_26 ,
T_3 V_39 , const char * V_60 )
{
F_28 ( V_9 , V_26 -> V_28 . V_38 ,
V_26 -> V_28 . V_39 | V_39 ) ;
V_26 -> V_28 . V_39 |= V_70 ;
F_40 ( V_61 , V_9 ,
L_8 ,
V_26 -> V_28 . V_38 , V_60 ) ;
}
T_3 F_59 ( struct V_8 * V_9 ,
const T_2 * V_38 , const char * V_60 ,
bool V_107 )
{
struct V_25 * V_26 ;
T_3 V_39 , V_108 = V_76 ;
V_26 = F_14 ( V_9 , V_38 ) ;
if ( ! V_26 )
goto V_74;
V_108 = V_26 -> V_28 . V_39 ;
V_39 = V_49 ;
if ( V_107 ) {
V_39 |= V_72 ;
V_26 -> V_28 . V_39 |= V_72 ;
}
if ( ! ( V_26 -> V_28 . V_39 & V_81 ) ) {
F_58 ( V_9 , V_26 , V_39 ,
V_60 ) ;
goto V_74;
}
F_28 ( V_9 , V_26 -> V_28 . V_38 ,
V_108 | V_49 ) ;
F_60 ( & V_26 -> V_28 . V_6 ) ;
F_16 ( V_26 ) ;
V_74:
if ( V_26 )
F_16 ( V_26 ) ;
return V_108 ;
}
static void F_61 ( struct V_8 * V_9 ,
struct V_17 * V_18 )
{
struct V_25 * V_26 ;
struct V_5 * V_19 ;
struct V_1 * V_2 , * V_109 ;
F_62 (tt_common_entry, node, node_tmp, head,
hash_entry) {
V_26 = F_2 ( V_19 ,
struct V_25 ,
V_28 ) ;
if ( V_26 -> V_28 . V_39 & V_80 )
continue;
if ( V_26 -> V_28 . V_39 & V_70 )
continue;
if ( ! F_63 ( V_26 -> V_68 ,
V_110 ) )
continue;
F_58 ( V_9 , V_26 ,
V_49 , L_9 ) ;
}
}
static void F_64 ( struct V_8 * V_9 )
{
struct V_14 * V_15 = V_9 -> V_10 . V_27 ;
struct V_17 * V_18 ;
T_4 * V_111 ;
T_1 V_105 ;
for ( V_105 = 0 ; V_105 < V_15 -> V_22 ; V_105 ++ ) {
V_18 = & V_15 -> V_23 [ V_105 ] ;
V_111 = & V_15 -> V_112 [ V_105 ] ;
F_30 ( V_111 ) ;
F_61 ( V_9 , V_18 ) ;
F_34 ( V_111 ) ;
}
}
static void F_65 ( struct V_8 * V_9 )
{
struct V_14 * V_15 ;
T_4 * V_111 ;
struct V_5 * V_19 ;
struct V_25 * V_65 ;
struct V_1 * V_2 , * V_109 ;
struct V_17 * V_18 ;
T_1 V_105 ;
if ( ! V_9 -> V_10 . V_27 )
return;
V_15 = V_9 -> V_10 . V_27 ;
for ( V_105 = 0 ; V_105 < V_15 -> V_22 ; V_105 ++ ) {
V_18 = & V_15 -> V_23 [ V_105 ] ;
V_111 = & V_15 -> V_112 [ V_105 ] ;
F_30 ( V_111 ) ;
F_62 (tt_common_entry, node, node_tmp,
head, hash_entry) {
F_60 ( V_2 ) ;
V_65 = F_2 ( V_19 ,
struct V_25 ,
V_28 ) ;
F_16 ( V_65 ) ;
}
F_34 ( V_111 ) ;
}
F_66 ( V_15 ) ;
V_9 -> V_10 . V_27 = NULL ;
}
static int F_67 ( struct V_8 * V_9 )
{
if ( V_9 -> V_10 . V_31 )
return 0 ;
V_9 -> V_10 . V_31 = F_38 ( 1024 ) ;
if ( ! V_9 -> V_10 . V_31 )
return - V_58 ;
return 0 ;
}
static void F_68 ( struct V_8 * V_9 )
{
struct V_40 * V_42 , * V_43 ;
F_30 ( & V_9 -> V_10 . V_50 ) ;
F_31 (entry, safe, &bat_priv->tt.changes_list,
list) {
F_32 ( & V_42 -> V_52 ) ;
F_20 ( V_42 ) ;
}
F_46 ( & V_9 -> V_10 . V_55 , 0 ) ;
F_34 ( & V_9 -> V_10 . V_50 ) ;
}
static struct V_34 *
F_69 ( const struct V_29 * V_42 ,
const struct V_113 * V_36 )
{
struct V_34 * V_114 , * V_35 = NULL ;
const struct V_17 * V_18 ;
struct V_1 * V_2 ;
F_9 () ;
V_18 = & V_42 -> V_82 ;
F_10 (tmp_orig_entry, node, head, list) {
if ( V_114 -> V_36 != V_36 )
continue;
if ( ! F_12 ( & V_114 -> V_24 ) )
continue;
V_35 = V_114 ;
break;
}
F_13 () ;
return V_35 ;
}
static bool
F_70 ( const struct V_29 * V_42 ,
const struct V_113 * V_36 )
{
struct V_34 * V_35 ;
bool V_115 = false ;
V_35 = F_69 ( V_42 , V_36 ) ;
if ( V_35 ) {
V_115 = true ;
F_26 ( V_35 ) ;
}
return V_115 ;
}
static void
F_71 ( struct V_29 * V_59 ,
struct V_113 * V_36 , int V_116 )
{
struct V_34 * V_35 ;
V_35 = F_69 ( V_59 , V_36 ) ;
if ( V_35 ) {
V_35 -> V_116 = V_116 ;
goto V_74;
}
V_35 = F_72 ( sizeof( * V_35 ) , V_47 ) ;
if ( ! V_35 )
goto V_74;
F_73 ( & V_35 -> V_52 ) ;
F_35 ( & V_36 -> V_24 ) ;
F_35 ( & V_36 -> V_37 ) ;
V_35 -> V_36 = V_36 ;
V_35 -> V_116 = V_116 ;
F_46 ( & V_35 -> V_24 , 2 ) ;
F_30 ( & V_59 -> V_111 ) ;
F_74 ( & V_35 -> V_52 ,
& V_59 -> V_82 ) ;
F_34 ( & V_59 -> V_111 ) ;
V_74:
if ( V_35 )
F_26 ( V_35 ) ;
}
int F_75 ( struct V_8 * V_9 ,
struct V_113 * V_36 ,
const unsigned char * V_117 , T_2 V_39 ,
T_2 V_116 )
{
struct V_29 * V_30 ;
struct V_25 * V_26 ;
int V_118 = 0 ;
int V_66 ;
struct V_5 * V_28 ;
T_3 V_119 ;
V_30 = F_15 ( V_9 , V_117 ) ;
V_26 = F_14 ( V_9 , V_117 ) ;
if ( ( V_39 & V_120 ) && V_26 &&
! ( V_26 -> V_28 . V_39 & V_81 ) )
goto V_74;
if ( ! V_30 ) {
V_30 = F_72 ( sizeof( * V_30 ) , V_47 ) ;
if ( ! V_30 )
goto V_74;
V_28 = & V_30 -> V_28 ;
memcpy ( V_28 -> V_38 , V_117 , V_7 ) ;
V_28 -> V_39 = V_39 ;
V_30 -> V_83 = 0 ;
if ( V_39 & V_72 )
V_30 -> V_83 = V_69 ;
F_46 ( & V_28 -> V_24 , 2 ) ;
V_28 -> V_78 = V_69 ;
F_76 ( & V_30 -> V_82 ) ;
F_77 ( & V_30 -> V_111 ) ;
V_66 = F_47 ( V_9 -> V_10 . V_31 ,
F_1 ,
F_8 , V_28 ,
& V_28 -> V_6 ) ;
if ( F_48 ( V_66 != 0 ) ) {
F_21 ( V_30 ) ;
goto V_121;
}
} else {
V_28 = & V_30 -> V_28 ;
if ( V_39 & V_120 ) {
if ( ! ( V_28 -> V_39 & V_120 ) )
goto V_74;
if ( F_70 ( V_30 ,
V_36 ) )
goto V_121;
F_22 ( V_30 ) ;
goto V_122;
}
V_28 -> V_39 &= ~ V_120 ;
V_30 -> V_28 . V_39 |= V_39 ;
if ( V_28 -> V_39 & V_72 ) {
F_22 ( V_30 ) ;
V_28 -> V_39 &= ~ V_72 ;
V_30 -> V_83 = 0 ;
}
}
V_122:
F_71 ( V_30 , V_36 , V_116 ) ;
F_40 ( V_61 , V_9 ,
L_10 ,
V_28 -> V_38 , V_36 -> V_123 ) ;
V_118 = 1 ;
V_121:
V_119 = F_59 ( V_9 , V_117 ,
L_11 ,
! ! ( V_39 & V_72 ) ) ;
V_30 -> V_28 . V_39 |= V_119 & V_77 ;
if ( ! ( V_39 & V_72 ) )
V_30 -> V_28 . V_39 &= ~ V_72 ;
V_74:
if ( V_30 )
F_21 ( V_30 ) ;
if ( V_26 )
F_16 ( V_26 ) ;
return V_118 ;
}
static struct V_34 *
F_78 ( struct V_29 * V_30 )
{
struct V_124 * V_125 = NULL ;
struct V_17 * V_18 ;
struct V_1 * V_2 ;
struct V_34 * V_35 , * V_126 = NULL ;
int V_127 = 0 ;
V_18 = & V_30 -> V_82 ;
F_10 (orig_entry, node, head, list) {
V_125 = F_79 ( V_35 -> V_36 ) ;
if ( ! V_125 )
continue;
if ( V_125 -> V_128 > V_127 ) {
V_126 = V_35 ;
V_127 = V_125 -> V_128 ;
}
F_80 ( V_125 ) ;
}
return V_126 ;
}
static void
F_81 ( struct V_29 * V_30 ,
struct V_100 * V_101 )
{
struct V_17 * V_18 ;
struct V_1 * V_2 ;
struct V_34 * V_35 , * V_126 ;
struct V_5 * V_19 ;
T_3 V_39 ;
T_2 V_129 ;
V_19 = & V_30 -> V_28 ;
V_39 = V_19 -> V_39 ;
V_126 = F_78 ( V_30 ) ;
if ( V_126 ) {
V_129 = F_44 ( & V_126 -> V_36 -> V_129 ) ;
F_57 ( V_101 , L_12 ,
'*' , V_30 -> V_28 . V_38 ,
V_126 -> V_116 , V_126 -> V_36 -> V_123 ,
V_129 ,
( V_39 & V_72 ? 'R' : '.' ) ,
( V_39 & V_77 ? 'W' : '.' ) ,
( V_39 & V_120 ? 'T' : '.' ) ) ;
}
V_18 = & V_30 -> V_82 ;
F_10 (orig_entry, node, head, list) {
if ( V_126 == V_35 )
continue;
V_129 = F_44 ( & V_35 -> V_36 -> V_129 ) ;
F_57 ( V_101 , L_12 ,
'+' , V_30 -> V_28 . V_38 ,
V_35 -> V_116 , V_35 -> V_36 -> V_123 ,
V_129 ,
( V_39 & V_72 ? 'R' : '.' ) ,
( V_39 & V_77 ? 'W' : '.' ) ,
( V_39 & V_120 ? 'T' : '.' ) ) ;
}
}
int F_82 ( struct V_100 * V_101 , void * V_102 )
{
struct V_62 * V_103 = (struct V_62 * ) V_101 -> V_104 ;
struct V_8 * V_9 = F_43 ( V_103 ) ;
struct V_14 * V_15 = V_9 -> V_10 . V_31 ;
struct V_5 * V_19 ;
struct V_29 * V_59 ;
struct V_89 * V_90 ;
struct V_1 * V_2 ;
struct V_17 * V_18 ;
T_1 V_105 ;
V_90 = F_56 ( V_101 ) ;
if ( ! V_90 )
goto V_74;
F_57 ( V_101 ,
L_13 ,
V_103 -> V_106 ) ;
F_57 ( V_101 , L_14 ,
L_15 , L_16 , L_17 , L_18 , L_19 ) ;
for ( V_105 = 0 ; V_105 < V_15 -> V_22 ; V_105 ++ ) {
V_18 = & V_15 -> V_23 [ V_105 ] ;
F_9 () ;
F_10 (tt_common_entry, node,
head, hash_entry) {
V_59 = F_2 ( V_19 ,
struct V_29 ,
V_28 ) ;
F_81 ( V_59 , V_101 ) ;
}
F_13 () ;
}
V_74:
if ( V_90 )
F_53 ( V_90 ) ;
return 0 ;
}
static void
F_22 ( struct V_29 * V_30 )
{
struct V_17 * V_18 ;
struct V_1 * V_2 , * V_43 ;
struct V_34 * V_35 ;
F_30 ( & V_30 -> V_111 ) ;
V_18 = & V_30 -> V_82 ;
F_62 (orig_entry, node, safe, head, list) {
F_60 ( V_2 ) ;
F_26 ( V_35 ) ;
}
F_34 ( & V_30 -> V_111 ) ;
}
static void
F_83 ( struct V_8 * V_9 ,
struct V_29 * V_30 ,
struct V_113 * V_36 ,
const char * V_60 )
{
struct V_17 * V_18 ;
struct V_1 * V_2 , * V_43 ;
struct V_34 * V_35 ;
F_30 ( & V_30 -> V_111 ) ;
V_18 = & V_30 -> V_82 ;
F_62 (orig_entry, node, safe, head, list) {
if ( V_35 -> V_36 == V_36 ) {
F_40 ( V_61 , V_9 ,
L_20 ,
V_36 -> V_123 ,
V_30 -> V_28 . V_38 , V_60 ) ;
F_60 ( V_2 ) ;
F_26 ( V_35 ) ;
}
}
F_34 ( & V_30 -> V_111 ) ;
}
static void
F_84 ( struct V_8 * V_9 ,
struct V_29 * V_30 ,
struct V_113 * V_36 ,
const char * V_60 )
{
bool V_130 = true ;
struct V_17 * V_18 ;
struct V_1 * V_2 ;
struct V_34 * V_35 ;
F_9 () ;
V_18 = & V_30 -> V_82 ;
F_10 (orig_entry, node, head, list) {
if ( V_35 -> V_36 != V_36 ) {
V_130 = false ;
break;
}
}
F_13 () ;
if ( V_130 ) {
V_30 -> V_28 . V_39 |= V_72 ;
V_30 -> V_83 = V_69 ;
} else
F_83 ( V_9 , V_30 ,
V_36 , V_60 ) ;
}
static void F_85 ( struct V_8 * V_9 ,
struct V_113 * V_36 ,
const unsigned char * V_38 ,
const char * V_60 , bool V_107 )
{
struct V_29 * V_30 ;
struct V_25 * V_131 = NULL ;
V_30 = F_15 ( V_9 , V_38 ) ;
if ( ! V_30 )
goto V_74;
if ( ! V_107 ) {
F_83 ( V_9 , V_30 ,
V_36 , V_60 ) ;
if ( F_86 ( & V_30 -> V_82 ) )
F_39 ( V_9 , V_30 ,
V_60 ) ;
goto V_74;
}
V_131 = F_14 ( V_9 ,
V_30 -> V_28 . V_38 ) ;
if ( V_131 ) {
F_22 ( V_30 ) ;
F_39 ( V_9 , V_30 , V_60 ) ;
} else
F_84 ( V_9 , V_30 ,
V_36 , V_60 ) ;
V_74:
if ( V_30 )
F_21 ( V_30 ) ;
if ( V_131 )
F_16 ( V_131 ) ;
}
void F_87 ( struct V_8 * V_9 ,
struct V_113 * V_36 ,
const char * V_60 )
{
struct V_29 * V_59 ;
struct V_5 * V_19 ;
T_1 V_105 ;
struct V_14 * V_15 = V_9 -> V_10 . V_31 ;
struct V_1 * V_2 , * V_43 ;
struct V_17 * V_18 ;
T_4 * V_111 ;
if ( ! V_15 )
return;
for ( V_105 = 0 ; V_105 < V_15 -> V_22 ; V_105 ++ ) {
V_18 = & V_15 -> V_23 [ V_105 ] ;
V_111 = & V_15 -> V_112 [ V_105 ] ;
F_30 ( V_111 ) ;
F_62 (tt_common_entry, node, safe,
head, hash_entry) {
V_59 = F_2 ( V_19 ,
struct V_29 ,
V_28 ) ;
F_83 ( V_9 , V_59 ,
V_36 , V_60 ) ;
if ( F_86 ( & V_59 -> V_82 ) ) {
F_40 ( V_61 , V_9 ,
L_1 ,
V_59 -> V_28 . V_38 , V_60 ) ;
F_60 ( V_2 ) ;
F_21 ( V_59 ) ;
}
}
F_34 ( V_111 ) ;
}
V_36 -> V_132 = false ;
}
static bool F_88 ( struct V_29 * V_59 ,
char * * V_133 )
{
bool V_134 = false ;
unsigned long V_135 = V_136 ;
unsigned long V_137 = V_138 ;
if ( ( V_59 -> V_28 . V_39 & V_72 ) &&
F_63 ( V_59 -> V_83 , V_135 ) ) {
V_134 = true ;
* V_133 = L_21 ;
}
if ( ( V_59 -> V_28 . V_39 & V_120 ) &&
F_63 ( V_59 -> V_28 . V_78 , V_137 ) ) {
V_134 = true ;
* V_133 = L_22 ;
}
return V_134 ;
}
static void F_89 ( struct V_8 * V_9 )
{
struct V_14 * V_15 = V_9 -> V_10 . V_31 ;
struct V_17 * V_18 ;
struct V_1 * V_2 , * V_109 ;
T_4 * V_111 ;
T_1 V_105 ;
char * V_133 = NULL ;
struct V_5 * V_139 ;
struct V_29 * V_59 ;
for ( V_105 = 0 ; V_105 < V_15 -> V_22 ; V_105 ++ ) {
V_18 = & V_15 -> V_23 [ V_105 ] ;
V_111 = & V_15 -> V_112 [ V_105 ] ;
F_30 ( V_111 ) ;
F_62 (tt_common, node, node_tmp, head,
hash_entry) {
V_59 = F_2 ( V_139 ,
struct V_29 ,
V_28 ) ;
if ( ! F_88 ( V_59 , & V_133 ) )
continue;
F_40 ( V_61 , V_9 ,
L_23 ,
V_59 -> V_28 . V_38 , V_133 ) ;
F_60 ( V_2 ) ;
F_21 ( V_59 ) ;
}
F_34 ( V_111 ) ;
}
}
static void F_90 ( struct V_8 * V_9 )
{
struct V_14 * V_15 ;
T_4 * V_111 ;
struct V_5 * V_19 ;
struct V_29 * V_59 ;
struct V_1 * V_2 , * V_109 ;
struct V_17 * V_18 ;
T_1 V_105 ;
if ( ! V_9 -> V_10 . V_31 )
return;
V_15 = V_9 -> V_10 . V_31 ;
for ( V_105 = 0 ; V_105 < V_15 -> V_22 ; V_105 ++ ) {
V_18 = & V_15 -> V_23 [ V_105 ] ;
V_111 = & V_15 -> V_112 [ V_105 ] ;
F_30 ( V_111 ) ;
F_62 (tt_common_entry, node, node_tmp,
head, hash_entry) {
F_60 ( V_2 ) ;
V_59 = F_2 ( V_19 ,
struct V_29 ,
V_28 ) ;
F_21 ( V_59 ) ;
}
F_34 ( V_111 ) ;
}
F_66 ( V_15 ) ;
V_9 -> V_10 . V_31 = NULL ;
}
static bool
F_91 ( struct V_25 * V_26 ,
struct V_29 * V_30 )
{
bool V_118 = false ;
if ( V_26 -> V_28 . V_39 & V_77 &&
V_30 -> V_28 . V_39 & V_77 )
V_118 = true ;
return V_118 ;
}
struct V_113 * F_92 ( struct V_8 * V_9 ,
const T_2 * V_140 ,
const T_2 * V_38 )
{
struct V_25 * V_26 = NULL ;
struct V_29 * V_30 = NULL ;
struct V_113 * V_36 = NULL ;
struct V_34 * V_126 ;
if ( V_140 && F_44 ( & V_9 -> V_141 ) ) {
V_26 = F_14 ( V_9 , V_140 ) ;
if ( ! V_26 ||
( V_26 -> V_28 . V_39 & V_70 ) )
goto V_74;
}
V_30 = F_15 ( V_9 , V_38 ) ;
if ( ! V_30 )
goto V_74;
if ( V_26 &&
F_91 ( V_26 , V_30 ) )
goto V_74;
F_9 () ;
V_126 = F_78 ( V_30 ) ;
if ( V_126 )
V_36 = V_126 -> V_36 ;
if ( V_36 && ! F_12 ( & V_36 -> V_24 ) )
V_36 = NULL ;
F_13 () ;
V_74:
if ( V_30 )
F_21 ( V_30 ) ;
if ( V_26 )
F_16 ( V_26 ) ;
return V_36 ;
}
static T_3 F_93 ( struct V_8 * V_9 ,
struct V_113 * V_36 )
{
T_3 V_142 = 0 , V_143 ;
struct V_14 * V_15 = V_9 -> V_10 . V_31 ;
struct V_5 * V_139 ;
struct V_29 * V_59 ;
struct V_1 * V_2 ;
struct V_17 * V_18 ;
T_1 V_105 ;
int V_144 ;
for ( V_105 = 0 ; V_105 < V_15 -> V_22 ; V_105 ++ ) {
V_18 = & V_15 -> V_23 [ V_105 ] ;
F_9 () ;
F_10 (tt_common, node, head, hash_entry) {
V_59 = F_2 ( V_139 ,
struct V_29 ,
V_28 ) ;
if ( V_139 -> V_39 & V_72 )
continue;
if ( V_139 -> V_39 & V_120 )
continue;
if ( ! F_70 ( V_59 ,
V_36 ) )
continue;
V_143 = 0 ;
for ( V_144 = 0 ; V_144 < V_7 ; V_144 ++ )
V_143 = F_94 ( V_143 ,
V_139 -> V_38 [ V_144 ] ) ;
V_142 ^= V_143 ;
}
F_13 () ;
}
return V_142 ;
}
static T_3 F_95 ( struct V_8 * V_9 )
{
T_3 V_142 = 0 , V_143 ;
struct V_14 * V_15 = V_9 -> V_10 . V_27 ;
struct V_5 * V_139 ;
struct V_1 * V_2 ;
struct V_17 * V_18 ;
T_1 V_105 ;
int V_144 ;
for ( V_105 = 0 ; V_105 < V_15 -> V_22 ; V_105 ++ ) {
V_18 = & V_15 -> V_23 [ V_105 ] ;
F_9 () ;
F_10 (tt_common, node, head, hash_entry) {
if ( V_139 -> V_39 & V_81 )
continue;
V_143 = 0 ;
for ( V_144 = 0 ; V_144 < V_7 ; V_144 ++ )
V_143 = F_94 ( V_143 ,
V_139 -> V_38 [ V_144 ] ) ;
V_142 ^= V_143 ;
}
F_13 () ;
}
return V_142 ;
}
static void F_96 ( struct V_8 * V_9 )
{
struct V_145 * V_2 , * V_43 ;
F_30 ( & V_9 -> V_10 . V_146 ) ;
F_31 (node, safe, &bat_priv->tt.req_list, list) {
F_32 ( & V_2 -> V_52 ) ;
F_20 ( V_2 ) ;
}
F_34 ( & V_9 -> V_10 . V_146 ) ;
}
static void F_97 ( struct V_8 * V_9 ,
struct V_113 * V_36 ,
const unsigned char * V_96 ,
T_2 V_147 )
{
T_3 V_148 = F_36 ( V_147 ) ;
F_30 ( & V_36 -> V_149 ) ;
if ( V_148 > 0 ) {
F_20 ( V_36 -> V_96 ) ;
V_36 -> V_148 = 0 ;
V_36 -> V_96 = F_29 ( V_148 , V_47 ) ;
if ( V_36 -> V_96 ) {
memcpy ( V_36 -> V_96 , V_96 , V_148 ) ;
V_36 -> V_148 = V_148 ;
}
}
F_34 ( & V_36 -> V_149 ) ;
}
static void F_98 ( struct V_8 * V_9 )
{
struct V_145 * V_2 , * V_43 ;
F_30 ( & V_9 -> V_10 . V_146 ) ;
F_31 (node, safe, &bat_priv->tt.req_list, list) {
if ( F_63 ( V_2 -> V_150 ,
V_151 ) ) {
F_32 ( & V_2 -> V_52 ) ;
F_20 ( V_2 ) ;
}
}
F_34 ( & V_9 -> V_10 . V_146 ) ;
}
static struct V_145 *
F_99 ( struct V_8 * V_9 ,
struct V_113 * V_36 )
{
struct V_145 * V_152 , * V_153 = NULL ;
F_30 ( & V_9 -> V_10 . V_146 ) ;
F_100 (tt_req_node_tmp, &bat_priv->tt.req_list, list) {
if ( F_11 ( V_152 , V_36 ) &&
! F_63 ( V_152 -> V_150 ,
V_151 ) )
goto V_53;
}
V_153 = F_29 ( sizeof( * V_153 ) , V_47 ) ;
if ( ! V_153 )
goto V_53;
memcpy ( V_153 -> V_38 , V_36 -> V_123 , V_7 ) ;
V_153 -> V_150 = V_69 ;
F_101 ( & V_153 -> V_52 , & V_9 -> V_10 . V_154 ) ;
V_53:
F_34 ( & V_9 -> V_10 . V_146 ) ;
return V_153 ;
}
static int F_102 ( const void * V_155 ,
const void * V_156 )
{
const struct V_5 * V_19 = V_155 ;
if ( V_19 -> V_39 & V_81 )
return 0 ;
return 1 ;
}
static int F_103 ( const void * V_155 ,
const void * V_156 )
{
const struct V_5 * V_19 = V_155 ;
const struct V_29 * V_30 ;
const struct V_113 * V_36 = V_156 ;
if ( V_19 -> V_39 & V_72 ||
V_19 -> V_39 & V_120 )
return 0 ;
V_30 = F_2 ( V_19 ,
struct V_29 ,
V_28 ) ;
return F_70 ( V_30 , V_36 ) ;
}
static struct V_157 *
F_104 ( T_3 V_158 , T_2 V_116 ,
struct V_14 * V_15 ,
struct V_89 * V_90 ,
int (* F_105)( const void * , const void * ) ,
void * V_159 )
{
struct V_5 * V_19 ;
struct V_160 * V_161 ;
struct V_57 * V_162 ;
struct V_1 * V_2 ;
struct V_17 * V_18 ;
struct V_157 * V_163 = NULL ;
T_3 V_164 , V_165 ;
T_5 V_166 = sizeof( struct V_160 ) ;
T_1 V_105 ;
T_6 V_167 ;
if ( V_166 + V_158 > V_90 -> V_63 -> V_92 ) {
V_158 = V_90 -> V_63 -> V_92 - V_166 ;
V_158 -= V_158 % sizeof( struct V_57 ) ;
}
V_164 = V_158 / sizeof( struct V_57 ) ;
V_167 = V_166 + V_158 ;
V_163 = F_106 ( V_167 + V_168 + V_169 ) ;
if ( ! V_163 )
goto V_74;
F_107 ( V_163 , V_168 + V_169 ) ;
V_161 = (struct V_160 * ) F_108 ( V_163 , V_167 ) ;
V_161 -> V_116 = V_116 ;
V_162 = (struct V_57 * ) ( V_163 -> V_16 + V_166 ) ;
V_165 = 0 ;
F_9 () ;
for ( V_105 = 0 ; V_105 < V_15 -> V_22 ; V_105 ++ ) {
V_18 = & V_15 -> V_23 [ V_105 ] ;
F_10 (tt_common_entry, node,
head, hash_entry) {
if ( V_165 == V_164 )
break;
if ( ( F_105 ) && ( ! F_105 ( V_19 , V_159 ) ) )
continue;
memcpy ( V_162 -> V_38 , V_19 -> V_38 ,
V_7 ) ;
V_162 -> V_39 = V_19 -> V_39 ;
V_165 ++ ;
V_162 ++ ;
}
}
F_13 () ;
V_161 -> V_170 = F_109 ( V_165 ) ;
V_74:
return V_163 ;
}
static int F_110 ( struct V_8 * V_9 ,
struct V_113 * V_171 ,
T_2 V_116 , T_3 V_172 ,
bool V_173 )
{
struct V_157 * V_163 = NULL ;
struct V_160 * V_174 ;
struct V_89 * V_90 ;
struct V_145 * V_153 = NULL ;
int V_118 = 1 ;
T_6 V_175 ;
V_90 = F_52 ( V_9 ) ;
if ( ! V_90 )
goto V_74;
V_153 = F_99 ( V_9 , V_171 ) ;
if ( ! V_153 )
goto V_74;
V_163 = F_106 ( sizeof( * V_174 ) + V_168 + V_169 ) ;
if ( ! V_163 )
goto V_74;
F_107 ( V_163 , V_168 + V_169 ) ;
V_175 = sizeof( * V_174 ) ;
V_174 = (struct V_160 * ) F_108 ( V_163 , V_175 ) ;
V_174 -> V_176 . V_177 = V_178 ;
V_174 -> V_176 . V_179 = V_180 ;
memcpy ( V_174 -> V_140 , V_90 -> V_103 -> V_79 , V_7 ) ;
memcpy ( V_174 -> V_181 , V_171 -> V_123 , V_7 ) ;
V_174 -> V_176 . V_182 = V_183 ;
V_174 -> V_116 = V_116 ;
V_174 -> V_170 = F_109 ( V_172 ) ;
V_174 -> V_39 = V_184 ;
if ( V_173 )
V_174 -> V_39 |= V_185 ;
F_40 ( V_61 , V_9 , L_24 ,
V_171 -> V_123 , ( V_173 ? 'F' : '.' ) ) ;
F_111 ( V_9 , V_186 ) ;
if ( F_112 ( V_163 , V_171 , NULL ) )
V_118 = 0 ;
V_74:
if ( V_90 )
F_53 ( V_90 ) ;
if ( V_118 )
F_113 ( V_163 ) ;
if ( V_118 && V_153 ) {
F_30 ( & V_9 -> V_10 . V_146 ) ;
F_32 ( & V_153 -> V_52 ) ;
F_34 ( & V_9 -> V_10 . V_146 ) ;
F_20 ( V_153 ) ;
}
return V_118 ;
}
static bool
F_114 ( struct V_8 * V_9 ,
struct V_160 * V_174 )
{
struct V_113 * V_187 ;
struct V_113 * V_188 = NULL ;
struct V_89 * V_90 = NULL ;
T_2 V_189 , V_190 , V_116 ;
int V_118 = false ;
unsigned char * V_96 ;
bool V_173 ;
T_3 V_158 , V_164 ;
struct V_157 * V_163 = NULL ;
struct V_160 * V_161 ;
T_2 * V_191 ;
T_6 V_167 ;
F_40 ( V_61 , V_9 ,
L_25 ,
V_174 -> V_140 , V_174 -> V_116 , V_174 -> V_181 ,
( V_174 -> V_39 & V_185 ? 'F' : '.' ) ) ;
V_187 = F_115 ( V_9 , V_174 -> V_181 ) ;
if ( ! V_187 )
goto V_74;
V_188 = F_115 ( V_9 , V_174 -> V_140 ) ;
if ( ! V_188 )
goto V_74;
V_90 = F_52 ( V_9 ) ;
if ( ! V_90 )
goto V_74;
V_189 = ( T_2 ) F_44 ( & V_187 -> V_129 ) ;
V_190 = V_174 -> V_116 ;
if ( V_189 != V_190 ||
V_174 -> V_170 != F_109 ( V_187 -> V_172 ) )
goto V_74;
if ( V_174 -> V_39 & V_185 ||
! V_187 -> V_96 )
V_173 = true ;
else
V_173 = false ;
if ( ! V_173 ) {
F_30 ( & V_187 -> V_149 ) ;
V_158 = V_187 -> V_148 ;
V_164 = V_158 / sizeof( struct V_57 ) ;
V_167 = sizeof( * V_161 ) + V_158 ;
V_163 = F_106 ( V_167 + V_168 + V_169 ) ;
if ( ! V_163 )
goto V_53;
F_107 ( V_163 , V_168 + V_169 ) ;
V_191 = F_108 ( V_163 , V_167 ) ;
V_161 = (struct V_160 * ) V_191 ;
V_161 -> V_116 = V_190 ;
V_161 -> V_170 = F_109 ( V_164 ) ;
V_96 = V_163 -> V_16 + sizeof( * V_161 ) ;
memcpy ( V_96 , V_187 -> V_96 ,
V_187 -> V_148 ) ;
F_34 ( & V_187 -> V_149 ) ;
} else {
V_158 = ( T_3 ) F_44 ( & V_187 -> V_37 ) ;
V_158 *= sizeof( struct V_57 ) ;
V_116 = ( T_2 ) F_44 ( & V_187 -> V_129 ) ;
V_163 = F_104 ( V_158 , V_116 ,
V_9 -> V_10 . V_31 ,
V_90 ,
F_103 ,
V_187 ) ;
if ( ! V_163 )
goto V_74;
V_161 = (struct V_160 * ) V_163 -> V_16 ;
}
V_161 -> V_176 . V_177 = V_178 ;
V_161 -> V_176 . V_179 = V_180 ;
V_161 -> V_176 . V_182 = V_183 ;
memcpy ( V_161 -> V_140 , V_187 -> V_123 , V_7 ) ;
memcpy ( V_161 -> V_181 , V_174 -> V_140 , V_7 ) ;
V_161 -> V_39 = V_192 ;
if ( V_173 )
V_161 -> V_39 |= V_185 ;
F_40 ( V_61 , V_9 ,
L_26 ,
V_188 -> V_123 , V_187 -> V_123 , V_190 ) ;
F_111 ( V_9 , V_193 ) ;
if ( F_112 ( V_163 , V_188 , NULL ) )
V_118 = true ;
goto V_74;
V_53:
F_34 ( & V_187 -> V_149 ) ;
V_74:
if ( V_188 )
F_25 ( V_188 ) ;
if ( V_187 )
F_25 ( V_187 ) ;
if ( V_90 )
F_53 ( V_90 ) ;
if ( ! V_118 )
F_113 ( V_163 ) ;
return V_118 ;
}
static bool
F_116 ( struct V_8 * V_9 ,
struct V_160 * V_174 )
{
struct V_113 * V_36 ;
struct V_89 * V_90 = NULL ;
T_2 V_194 , V_190 , V_116 ;
int V_118 = false ;
unsigned char * V_96 ;
bool V_173 ;
T_3 V_158 , V_164 ;
struct V_157 * V_163 = NULL ;
struct V_160 * V_161 ;
T_2 * V_191 ;
T_6 V_167 ;
F_40 ( V_61 , V_9 ,
L_27 ,
V_174 -> V_140 , V_174 -> V_116 ,
( V_174 -> V_39 & V_185 ? 'F' : '.' ) ) ;
V_194 = ( T_2 ) F_44 ( & V_9 -> V_10 . V_75 ) ;
V_190 = V_174 -> V_116 ;
V_36 = F_115 ( V_9 , V_174 -> V_140 ) ;
if ( ! V_36 )
goto V_74;
V_90 = F_52 ( V_9 ) ;
if ( ! V_90 )
goto V_74;
if ( V_174 -> V_39 & V_185 || V_194 != V_190 ||
! V_9 -> V_10 . V_98 )
V_173 = true ;
else
V_173 = false ;
if ( ! V_173 ) {
F_30 ( & V_9 -> V_10 . V_97 ) ;
V_158 = V_9 -> V_10 . V_99 ;
V_164 = V_158 / sizeof( struct V_57 ) ;
V_167 = sizeof( * V_161 ) + V_158 ;
V_163 = F_106 ( V_167 + V_168 + V_169 ) ;
if ( ! V_163 )
goto V_53;
F_107 ( V_163 , V_168 + V_169 ) ;
V_191 = F_108 ( V_163 , V_167 ) ;
V_161 = (struct V_160 * ) V_191 ;
V_161 -> V_116 = V_190 ;
V_161 -> V_170 = F_109 ( V_164 ) ;
V_96 = V_163 -> V_16 + sizeof( * V_161 ) ;
memcpy ( V_96 , V_9 -> V_10 . V_98 ,
V_9 -> V_10 . V_99 ) ;
F_34 ( & V_9 -> V_10 . V_97 ) ;
} else {
V_158 = ( T_3 ) F_44 ( & V_9 -> V_10 . V_195 ) ;
V_158 *= sizeof( struct V_57 ) ;
V_116 = ( T_2 ) F_44 ( & V_9 -> V_10 . V_75 ) ;
V_163 = F_104 ( V_158 , V_116 ,
V_9 -> V_10 . V_27 ,
V_90 ,
F_102 ,
NULL ) ;
if ( ! V_163 )
goto V_74;
V_161 = (struct V_160 * ) V_163 -> V_16 ;
}
V_161 -> V_176 . V_177 = V_178 ;
V_161 -> V_176 . V_179 = V_180 ;
V_161 -> V_176 . V_182 = V_183 ;
memcpy ( V_161 -> V_140 , V_90 -> V_103 -> V_79 , V_7 ) ;
memcpy ( V_161 -> V_181 , V_174 -> V_140 , V_7 ) ;
V_161 -> V_39 = V_192 ;
if ( V_173 )
V_161 -> V_39 |= V_185 ;
F_40 ( V_61 , V_9 ,
L_28 ,
V_36 -> V_123 ,
( V_161 -> V_39 & V_185 ? 'F' : '.' ) ) ;
F_111 ( V_9 , V_193 ) ;
if ( F_112 ( V_163 , V_36 , NULL ) )
V_118 = true ;
goto V_74;
V_53:
F_34 ( & V_9 -> V_10 . V_97 ) ;
V_74:
if ( V_36 )
F_25 ( V_36 ) ;
if ( V_90 )
F_53 ( V_90 ) ;
if ( ! V_118 )
F_113 ( V_163 ) ;
return true ;
}
bool F_117 ( struct V_8 * V_9 ,
struct V_160 * V_174 )
{
if ( F_118 ( V_174 -> V_181 ) ) {
if ( F_119 ( V_9 , V_174 -> V_140 ) )
return true ;
return F_116 ( V_9 , V_174 ) ;
} else {
return F_114 ( V_9 , V_174 ) ;
}
}
static void F_120 ( struct V_8 * V_9 ,
struct V_113 * V_36 ,
struct V_57 * V_162 ,
T_3 V_147 , T_2 V_116 )
{
int V_105 ;
int V_196 ;
for ( V_105 = 0 ; V_105 < V_147 ; V_105 ++ ) {
if ( ( V_162 + V_105 ) -> V_39 & V_49 ) {
V_196 = ( V_162 + V_105 ) -> V_39 & V_72 ;
F_85 ( V_9 , V_36 ,
( V_162 + V_105 ) -> V_38 ,
L_29 ,
V_196 ) ;
} else {
if ( ! F_75 ( V_9 , V_36 ,
( V_162 + V_105 ) -> V_38 ,
( V_162 + V_105 ) -> V_39 , V_116 ) )
return;
}
}
V_36 -> V_132 = true ;
}
static void F_121 ( struct V_8 * V_9 ,
struct V_160 * V_161 )
{
struct V_113 * V_36 ;
V_36 = F_115 ( V_9 , V_161 -> V_140 ) ;
if ( ! V_36 )
goto V_74;
F_87 ( V_9 , V_36 , L_30 ) ;
F_120 ( V_9 , V_36 ,
(struct V_57 * ) ( V_161 + 1 ) ,
F_122 ( V_161 -> V_170 ) ,
V_161 -> V_116 ) ;
F_30 ( & V_36 -> V_149 ) ;
F_20 ( V_36 -> V_96 ) ;
V_36 -> V_148 = 0 ;
V_36 -> V_96 = NULL ;
F_34 ( & V_36 -> V_149 ) ;
F_46 ( & V_36 -> V_129 , V_161 -> V_116 ) ;
V_74:
if ( V_36 )
F_25 ( V_36 ) ;
}
static void F_123 ( struct V_8 * V_9 ,
struct V_113 * V_36 ,
T_3 V_147 , T_2 V_116 ,
struct V_57 * V_162 )
{
F_120 ( V_9 , V_36 , V_162 ,
V_147 , V_116 ) ;
F_97 ( V_9 , V_36 ,
( unsigned char * ) V_162 , V_147 ) ;
F_46 ( & V_36 -> V_129 , V_116 ) ;
}
bool F_124 ( struct V_8 * V_9 , const T_2 * V_38 )
{
struct V_25 * V_26 ;
bool V_118 = false ;
V_26 = F_14 ( V_9 , V_38 ) ;
if ( ! V_26 )
goto V_74;
if ( ( V_26 -> V_28 . V_39 & V_70 ) ||
( V_26 -> V_28 . V_39 & V_72 ) )
goto V_74;
V_118 = true ;
V_74:
if ( V_26 )
F_16 ( V_26 ) ;
return V_118 ;
}
void F_125 ( struct V_8 * V_9 ,
struct V_160 * V_161 )
{
struct V_145 * V_2 , * V_43 ;
struct V_113 * V_36 = NULL ;
struct V_57 * V_162 ;
F_40 ( V_61 , V_9 ,
L_31 ,
V_161 -> V_140 , V_161 -> V_116 ,
F_122 ( V_161 -> V_170 ) ,
( V_161 -> V_39 & V_185 ? 'F' : '.' ) ) ;
if ( F_119 ( V_9 , V_161 -> V_140 ) )
goto V_74;
V_36 = F_115 ( V_9 , V_161 -> V_140 ) ;
if ( ! V_36 )
goto V_74;
if ( V_161 -> V_39 & V_185 ) {
F_121 ( V_9 , V_161 ) ;
} else {
V_162 = (struct V_57 * ) ( V_161 + 1 ) ;
F_123 ( V_9 , V_36 ,
F_122 ( V_161 -> V_170 ) ,
V_161 -> V_116 , V_162 ) ;
}
F_30 ( & V_9 -> V_10 . V_146 ) ;
F_31 (node, safe, &bat_priv->tt.req_list, list) {
if ( ! F_11 ( V_2 -> V_38 , V_161 -> V_140 ) )
continue;
F_32 ( & V_2 -> V_52 ) ;
F_20 ( V_2 ) ;
}
F_34 ( & V_9 -> V_10 . V_146 ) ;
V_36 -> V_172 = F_93 ( V_9 , V_36 ) ;
V_74:
if ( V_36 )
F_25 ( V_36 ) ;
}
int F_126 ( struct V_8 * V_9 )
{
int V_118 ;
V_118 = F_37 ( V_9 ) ;
if ( V_118 < 0 )
return V_118 ;
V_118 = F_67 ( V_9 ) ;
if ( V_118 < 0 )
return V_118 ;
F_3 ( V_9 ) ;
return 1 ;
}
static void F_127 ( struct V_8 * V_9 )
{
struct V_197 * V_2 , * V_43 ;
F_30 ( & V_9 -> V_10 . V_198 ) ;
F_31 (node, safe, &bat_priv->tt.roam_list, list) {
F_32 ( & V_2 -> V_52 ) ;
F_20 ( V_2 ) ;
}
F_34 ( & V_9 -> V_10 . V_198 ) ;
}
static void F_128 ( struct V_8 * V_9 )
{
struct V_197 * V_2 , * V_43 ;
F_30 ( & V_9 -> V_10 . V_198 ) ;
F_31 (node, safe, &bat_priv->tt.roam_list, list) {
if ( ! F_63 ( V_2 -> V_199 ,
V_200 ) )
continue;
F_32 ( & V_2 -> V_52 ) ;
F_20 ( V_2 ) ;
}
F_34 ( & V_9 -> V_10 . V_198 ) ;
}
static bool F_129 ( struct V_8 * V_9 ,
T_2 * V_201 )
{
struct V_197 * V_202 ;
bool V_118 = false ;
F_30 ( & V_9 -> V_10 . V_198 ) ;
F_100 (tt_roam_node, &bat_priv->tt.roam_list, list) {
if ( ! F_11 ( V_202 -> V_38 , V_201 ) )
continue;
if ( F_63 ( V_202 -> V_199 ,
V_200 ) )
continue;
if ( ! F_130 ( & V_202 -> V_203 ) )
goto V_53;
V_118 = true ;
break;
}
if ( ! V_118 ) {
V_202 = F_29 ( sizeof( * V_202 ) , V_47 ) ;
if ( ! V_202 )
goto V_53;
V_202 -> V_199 = V_69 ;
F_46 ( & V_202 -> V_203 ,
V_204 - 1 ) ;
memcpy ( V_202 -> V_38 , V_201 , V_7 ) ;
F_101 ( & V_202 -> V_52 , & V_9 -> V_10 . V_205 ) ;
V_118 = true ;
}
V_53:
F_34 ( & V_9 -> V_10 . V_198 ) ;
return V_118 ;
}
static void F_49 ( struct V_8 * V_9 , T_2 * V_201 ,
struct V_113 * V_36 )
{
struct V_157 * V_163 = NULL ;
struct V_206 * V_207 ;
int V_118 = 1 ;
struct V_89 * V_90 ;
T_6 V_167 = sizeof( * V_207 ) ;
if ( ! F_129 ( V_9 , V_201 ) )
goto V_74;
V_163 = F_106 ( sizeof( * V_207 ) + V_168 + V_169 ) ;
if ( ! V_163 )
goto V_74;
F_107 ( V_163 , V_168 + V_169 ) ;
V_207 = (struct V_206 * ) F_108 ( V_163 , V_167 ) ;
V_207 -> V_176 . V_177 = V_208 ;
V_207 -> V_176 . V_179 = V_180 ;
V_207 -> V_176 . V_182 = V_183 ;
V_207 -> V_209 = 0 ;
V_90 = F_52 ( V_9 ) ;
if ( ! V_90 )
goto V_74;
memcpy ( V_207 -> V_140 , V_90 -> V_103 -> V_79 , V_7 ) ;
F_53 ( V_90 ) ;
memcpy ( V_207 -> V_181 , V_36 -> V_123 , V_7 ) ;
memcpy ( V_207 -> V_201 , V_201 , V_7 ) ;
F_40 ( V_61 , V_9 ,
L_32 ,
V_36 -> V_123 , V_201 ) ;
F_111 ( V_9 , V_210 ) ;
if ( F_112 ( V_163 , V_36 , NULL ) )
V_118 = 0 ;
V_74:
if ( V_118 && V_163 )
F_113 ( V_163 ) ;
return;
}
static void V_12 ( struct V_211 * V_11 )
{
struct V_212 * V_212 ;
struct V_213 * V_214 ;
struct V_8 * V_9 ;
V_212 = F_2 ( V_11 , struct V_212 , V_11 ) ;
V_214 = F_2 ( V_212 , struct V_213 , V_11 ) ;
V_9 = F_2 ( V_214 , struct V_8 , V_10 ) ;
F_64 ( V_9 ) ;
F_89 ( V_9 ) ;
F_98 ( V_9 ) ;
F_128 ( V_9 ) ;
F_3 ( V_9 ) ;
}
void F_131 ( struct V_8 * V_9 )
{
F_132 ( & V_9 -> V_10 . V_11 ) ;
F_65 ( V_9 ) ;
F_90 ( V_9 ) ;
F_96 ( V_9 ) ;
F_68 ( V_9 ) ;
F_127 ( V_9 ) ;
F_20 ( V_9 -> V_10 . V_98 ) ;
}
static T_3 F_133 ( struct V_14 * V_15 ,
T_3 V_39 , bool V_215 )
{
T_1 V_105 ;
T_3 V_216 = 0 ;
struct V_17 * V_18 ;
struct V_1 * V_2 ;
struct V_5 * V_19 ;
if ( ! V_15 )
goto V_74;
for ( V_105 = 0 ; V_105 < V_15 -> V_22 ; V_105 ++ ) {
V_18 = & V_15 -> V_23 [ V_105 ] ;
F_9 () ;
F_10 (tt_common_entry, node,
head, hash_entry) {
if ( V_215 ) {
if ( ( V_19 -> V_39 & V_39 ) == V_39 )
continue;
V_19 -> V_39 |= V_39 ;
} else {
if ( ! ( V_19 -> V_39 & V_39 ) )
continue;
V_19 -> V_39 &= ~ V_39 ;
}
V_216 ++ ;
}
F_13 () ;
}
V_74:
return V_216 ;
}
static void F_134 ( struct V_8 * V_9 )
{
struct V_14 * V_15 = V_9 -> V_10 . V_27 ;
struct V_5 * V_139 ;
struct V_25 * V_65 ;
struct V_1 * V_2 , * V_109 ;
struct V_17 * V_18 ;
T_4 * V_111 ;
T_1 V_105 ;
if ( ! V_15 )
return;
for ( V_105 = 0 ; V_105 < V_15 -> V_22 ; V_105 ++ ) {
V_18 = & V_15 -> V_23 [ V_105 ] ;
V_111 = & V_15 -> V_112 [ V_105 ] ;
F_30 ( V_111 ) ;
F_62 (tt_common, node, node_tmp, head,
hash_entry) {
if ( ! ( V_139 -> V_39 & V_70 ) )
continue;
F_40 ( V_61 , V_9 ,
L_33 ,
V_139 -> V_38 ) ;
F_27 ( & V_9 -> V_10 . V_195 ) ;
F_60 ( V_2 ) ;
V_65 = F_2 ( V_139 ,
struct V_25 ,
V_28 ) ;
F_16 ( V_65 ) ;
}
F_34 ( V_111 ) ;
}
}
static int F_135 ( struct V_8 * V_9 ,
unsigned char * * V_84 ,
int * V_85 , int V_217 )
{
T_3 V_216 = 0 ;
if ( F_44 ( & V_9 -> V_10 . V_55 ) < 1 )
return - V_218 ;
V_216 = F_133 ( V_9 -> V_10 . V_27 ,
V_81 , false ) ;
F_136 ( V_216 , & V_9 -> V_10 . V_195 ) ;
F_134 ( V_9 ) ;
V_9 -> V_10 . V_219 = F_95 ( V_9 ) ;
F_35 ( & V_9 -> V_10 . V_75 ) ;
F_40 ( V_61 , V_9 ,
L_34 ,
( T_2 ) F_44 ( & V_9 -> V_10 . V_75 ) ) ;
F_46 ( & V_9 -> V_10 . V_220 , V_221 ) ;
return F_54 ( V_9 , V_84 ,
V_85 , V_217 ) ;
}
int F_137 ( struct V_8 * V_9 ,
unsigned char * * V_84 , int * V_85 ,
int V_217 )
{
int V_147 ;
V_147 = F_135 ( V_9 , V_84 ,
V_85 ,
V_217 ) ;
if ( ( V_147 < 0 ) &&
( ! F_130 ( & V_9 -> V_10 . V_220 ) ) ) {
F_50 ( V_84 , V_85 ,
V_217 , V_217 ) ;
V_147 = 0 ;
}
return V_147 ;
}
bool F_138 ( struct V_8 * V_9 , T_2 * V_140 ,
T_2 * V_181 )
{
struct V_25 * V_26 = NULL ;
struct V_29 * V_30 = NULL ;
bool V_118 = false ;
if ( ! F_44 ( & V_9 -> V_141 ) )
goto V_74;
V_26 = F_14 ( V_9 , V_181 ) ;
if ( ! V_26 )
goto V_74;
V_30 = F_15 ( V_9 , V_140 ) ;
if ( ! V_30 )
goto V_74;
if ( ! F_91 ( V_26 , V_30 ) )
goto V_74;
V_118 = true ;
V_74:
if ( V_30 )
F_21 ( V_30 ) ;
if ( V_26 )
F_16 ( V_26 ) ;
return V_118 ;
}
void F_139 ( struct V_8 * V_9 ,
struct V_113 * V_36 ,
const unsigned char * V_96 , T_2 V_147 ,
T_2 V_116 , T_3 V_172 )
{
T_2 V_189 = ( T_2 ) F_44 ( & V_36 -> V_129 ) ;
bool V_173 = true ;
struct V_57 * V_162 ;
if ( F_119 ( V_9 , V_36 -> V_123 ) )
return;
if ( ( ! V_36 -> V_132 && V_116 == 1 ) ||
V_116 - V_189 == 1 ) {
if ( ! V_147 ) {
V_173 = false ;
goto V_222;
}
V_162 = (struct V_57 * ) V_96 ;
F_123 ( V_9 , V_36 , V_147 ,
V_116 , V_162 ) ;
V_36 -> V_172 = F_93 ( V_9 , V_36 ) ;
if ( V_36 -> V_172 != V_172 )
goto V_222;
} else {
if ( ! V_36 -> V_132 || V_116 != V_189 ||
V_36 -> V_172 != V_172 ) {
V_222:
F_40 ( V_61 , V_9 ,
L_35 ,
V_36 -> V_123 , V_116 , V_189 , V_172 ,
V_36 -> V_172 , V_147 ) ;
F_110 ( V_9 , V_36 , V_116 ,
V_172 , V_173 ) ;
return;
}
}
}
bool F_140 ( struct V_8 * V_9 ,
T_2 * V_38 )
{
struct V_29 * V_30 ;
bool V_118 = false ;
V_30 = F_15 ( V_9 , V_38 ) ;
if ( ! V_30 )
goto V_74;
V_118 = ! ! ( V_30 -> V_28 . V_39 & V_72 ) ;
F_21 ( V_30 ) ;
V_74:
return V_118 ;
}
bool F_141 ( struct V_8 * V_9 ,
T_2 * V_38 )
{
struct V_25 * V_26 ;
bool V_118 = false ;
V_26 = F_14 ( V_9 , V_38 ) ;
if ( ! V_26 )
goto V_74;
V_118 = V_26 -> V_28 . V_39 & V_72 ;
F_16 ( V_26 ) ;
V_74:
return V_118 ;
}
bool F_142 ( struct V_8 * V_9 ,
struct V_113 * V_36 ,
const unsigned char * V_38 )
{
bool V_118 = false ;
if ( F_119 ( V_9 , V_36 -> V_123 ) )
goto V_74;
if ( ! F_75 ( V_9 , V_36 , V_38 ,
V_120 ,
F_44 ( & V_36 -> V_129 ) ) )
goto V_74;
F_40 ( V_61 , V_9 ,
L_36 ,
V_38 , V_36 -> V_123 ) ;
V_118 = true ;
V_74:
return V_118 ;
}
