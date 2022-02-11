static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 , * V_9 ;
V_4 = F_2 ( V_2 , struct V_3 , V_10 ) ;
V_6 = V_4 -> V_6 ;
F_3 ( & V_4 -> V_11 ) ;
F_4 ( & V_6 -> V_12 ) ;
F_5 (entry, tmp, &info->recv_list, list) {
F_6 ( & V_8 -> V_13 ) ;
F_7 ( V_8 ) ;
}
F_8 ( & V_6 -> V_12 ) ;
F_9 ( V_4 -> V_14 ) ;
F_7 ( V_4 ) ;
}
static int F_10 ( const struct V_15 * V_16 , const void * V_17 )
{
const struct V_3 * V_18 , * V_19 ;
const struct V_20 * V_21 , * V_22 ;
V_18 = F_2 ( V_16 , struct V_3 , V_23 ) ;
V_19 = V_17 ;
V_21 = (struct V_20 * ) V_18 -> V_14 -> V_24 ;
V_22 = (struct V_20 * ) V_19 -> V_14 -> V_24 ;
return F_11 ( V_21 -> V_25 , V_22 -> V_25 ) ;
}
static T_1 F_12 ( const void * V_24 , T_1 V_26 )
{
const struct V_3 * V_27 = V_24 ;
const struct V_20 * V_28 ;
const unsigned char * V_29 ;
T_1 V_30 = 0 ;
T_2 V_31 ;
V_28 = (struct V_20 * ) V_27 -> V_14 -> V_24 ;
V_29 = V_28 -> V_25 ;
for ( V_31 = 0 ; V_31 < V_32 ; V_31 ++ ) {
V_30 += V_29 [ V_31 ] ;
V_30 += ( V_30 << 10 ) ;
V_30 ^= ( V_30 >> 6 ) ;
}
V_30 += ( V_30 << 3 ) ;
V_30 ^= ( V_30 >> 11 ) ;
V_30 += ( V_30 << 15 ) ;
return V_30 % V_26 ;
}
static struct V_3 *
F_13 ( struct V_5 * V_6 , const void * V_24 )
{
struct V_33 * V_30 = V_6 -> V_34 ;
struct V_35 * V_36 ;
struct V_15 * V_16 ;
struct V_3 * V_27 , * V_37 = NULL ;
T_1 V_38 ;
if ( ! V_30 )
return NULL ;
V_38 = F_12 ( V_24 , V_30 -> V_26 ) ;
V_36 = & V_30 -> V_39 [ V_38 ] ;
F_14 () ;
F_15 (vis_info, node, head, hash_entry) {
if ( ! F_10 ( V_16 , V_24 ) )
continue;
V_37 = V_27 ;
break;
}
F_16 () ;
return V_37 ;
}
static void F_17 ( const T_3 * V_40 ,
struct V_35 * V_41 ,
bool V_42 )
{
struct V_43 * V_8 ;
struct V_15 * V_44 ;
F_18 (entry, pos, if_list, list) {
if ( F_11 ( V_8 -> V_45 , V_40 ) )
return;
}
V_8 = F_19 ( sizeof( * V_8 ) , V_46 ) ;
if ( ! V_8 )
return;
memcpy ( V_8 -> V_45 , V_40 , V_32 ) ;
V_8 -> V_42 = V_42 ;
F_20 ( & V_8 -> V_13 , V_41 ) ;
}
static void F_21 ( struct V_47 * V_48 ,
const struct V_35 * V_41 )
{
struct V_43 * V_8 ;
struct V_15 * V_44 ;
F_18 (entry, pos, if_list, list) {
if ( V_8 -> V_42 )
F_22 ( V_48 , L_1 ) ;
else
F_22 ( V_48 , L_2 , V_8 -> V_45 ) ;
}
}
static T_4
F_23 ( struct V_47 * V_48 ,
const struct V_49 * V_8 ,
const T_3 * V_50 , bool V_42 )
{
if ( V_42 && V_8 -> V_51 == 0 )
return F_22 ( V_48 , L_3 , V_8 -> V_52 ) ;
else if ( F_11 ( V_8 -> V_50 , V_50 ) )
return F_22 ( V_48 , L_4 , V_8 -> V_52 ,
V_8 -> V_51 ) ;
return 0 ;
}
static void
F_24 ( struct V_35 * V_13 ,
struct V_20 * V_28 ,
struct V_49 * V_53 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_28 -> V_53 ; V_31 ++ ) {
if ( V_53 [ V_31 ] . V_51 == 0 )
continue;
if ( F_11 ( V_53 [ V_31 ] . V_50 , V_28 -> V_25 ) )
continue;
F_17 ( V_53 [ V_31 ] . V_50 , V_13 , false ) ;
}
}
static void F_25 ( struct V_47 * V_48 ,
struct V_35 * V_13 ,
struct V_20 * V_28 ,
struct V_49 * V_53 )
{
int V_31 ;
struct V_43 * V_8 ;
struct V_15 * V_44 ;
F_18 (entry, pos, list, list) {
F_22 ( V_48 , L_5 , V_8 -> V_45 ) ;
for ( V_31 = 0 ; V_31 < V_28 -> V_53 ; V_31 ++ )
F_23 ( V_48 , & V_53 [ V_31 ] ,
V_8 -> V_45 , V_8 -> V_42 ) ;
if ( F_11 ( V_8 -> V_45 , V_28 -> V_25 ) )
F_21 ( V_48 , V_13 ) ;
F_22 ( V_48 , L_6 ) ;
}
}
static void F_26 ( struct V_47 * V_48 ,
const struct V_35 * V_36 )
{
struct V_15 * V_16 ;
struct V_3 * V_4 ;
struct V_20 * V_28 ;
T_3 * V_54 ;
struct V_49 * V_53 ;
struct V_43 * V_8 ;
struct V_15 * V_44 , * V_55 ;
F_27 ( V_56 ) ;
F_15 (info, node, head, hash_entry) {
V_28 = (struct V_20 * ) V_4 -> V_14 -> V_24 ;
V_54 = ( T_3 * ) V_28 + sizeof( * V_28 ) ;
V_53 = (struct V_49 * ) V_54 ;
F_17 ( V_28 -> V_25 , & V_56 ,
true ) ;
F_24 ( & V_56 , V_28 ,
V_53 ) ;
F_25 ( V_48 , & V_56 , V_28 ,
V_53 ) ;
F_28 (entry, pos, n, &vis_if_list, list) {
F_29 ( & V_8 -> V_13 ) ;
F_7 ( V_8 ) ;
}
}
}
int F_30 ( struct V_47 * V_48 , void * V_57 )
{
struct V_58 * V_59 ;
struct V_35 * V_36 ;
struct V_60 * V_61 = (struct V_60 * ) V_48 -> V_62 ;
struct V_5 * V_6 = F_31 ( V_61 ) ;
struct V_33 * V_30 = V_6 -> V_34 ;
T_1 V_31 ;
int V_63 = 0 ;
int V_64 = F_32 ( & V_6 -> V_65 ) ;
V_59 = F_33 ( V_6 ) ;
if ( ! V_59 )
goto V_66;
if ( V_64 == V_67 )
goto V_66;
F_4 ( & V_6 -> V_68 ) ;
for ( V_31 = 0 ; V_31 < V_30 -> V_26 ; V_31 ++ ) {
V_36 = & V_30 -> V_39 [ V_31 ] ;
F_26 ( V_48 , V_36 ) ;
}
F_8 ( & V_6 -> V_68 ) ;
V_66:
if ( V_59 )
F_34 ( V_59 ) ;
return V_63 ;
}
static void F_35 ( struct V_5 * V_6 ,
struct V_3 * V_4 )
{
if ( F_36 ( & V_4 -> V_11 ) ) {
F_37 ( & V_4 -> V_10 ) ;
F_38 ( & V_4 -> V_11 , & V_6 -> V_69 ) ;
}
}
static void F_39 ( struct V_3 * V_4 )
{
if ( ! F_36 ( & V_4 -> V_11 ) ) {
F_3 ( & V_4 -> V_11 ) ;
F_40 ( & V_4 -> V_10 , F_1 ) ;
}
}
static void F_41 ( struct V_5 * V_6 ,
struct V_70 * V_71 , const char * V_72 )
{
struct V_7 * V_8 ;
V_8 = F_19 ( sizeof( * V_8 ) , V_46 ) ;
if ( ! V_8 )
return;
memcpy ( V_8 -> V_72 , V_72 , V_32 ) ;
F_4 ( & V_6 -> V_12 ) ;
F_38 ( & V_8 -> V_13 , V_71 ) ;
F_8 ( & V_6 -> V_12 ) ;
}
static int F_42 ( struct V_5 * V_6 ,
const struct V_70 * V_71 ,
const char * V_72 )
{
const struct V_7 * V_8 ;
F_4 ( & V_6 -> V_12 ) ;
F_43 (entry, recv_list, list) {
if ( F_11 ( V_8 -> V_72 , V_72 ) ) {
F_8 ( & V_6 -> V_12 ) ;
return 1 ;
}
}
F_8 ( & V_6 -> V_12 ) ;
return 0 ;
}
static struct V_3 *
F_44 ( struct V_5 * V_6 ,
struct V_20 * V_73 , int V_74 ,
int * V_75 , int V_76 )
{
struct V_3 * V_4 , * V_77 ;
struct V_20 * V_78 , * V_79 ;
struct V_3 V_80 ;
struct V_20 * V_28 ;
struct V_81 * V_82 ;
int V_83 ;
T_2 V_84 ;
T_2 V_85 ;
* V_75 = 0 ;
if ( ! V_6 -> V_34 )
return NULL ;
V_80 . V_14 = F_45 ( sizeof( * V_78 ) ) ;
if ( ! V_80 . V_14 )
return NULL ;
V_84 = sizeof( * V_78 ) ;
V_82 = V_80 . V_14 ;
V_78 = (struct V_20 * ) F_46 ( V_82 , V_84 ) ;
memcpy ( V_78 -> V_25 , V_73 -> V_25 , V_32 ) ;
V_77 = F_13 ( V_6 , & V_80 ) ;
F_9 ( V_80 . V_14 ) ;
if ( V_77 ) {
V_82 = V_77 -> V_14 ;
V_79 = (struct V_20 * ) V_82 -> V_24 ;
if ( ! F_47 ( F_48 ( V_73 -> V_86 ) ,
F_48 ( V_79 -> V_86 ) ) ) {
if ( V_79 -> V_86 == V_73 -> V_86 ) {
F_41 ( V_6 ,
& V_77 -> V_71 ,
V_73 -> V_87 ) ;
return V_77 ;
} else {
return NULL ;
}
}
F_49 ( V_6 -> V_34 , F_10 ,
F_12 , V_77 ) ;
F_39 ( V_77 ) ;
F_40 ( & V_77 -> V_10 , F_1 ) ;
}
V_4 = F_19 ( sizeof( * V_4 ) , V_46 ) ;
if ( ! V_4 )
return NULL ;
V_84 = sizeof( * V_28 ) + V_74 ;
V_4 -> V_14 = F_45 ( V_84 + V_88 ) ;
if ( ! V_4 -> V_14 ) {
F_7 ( V_4 ) ;
return NULL ;
}
F_50 ( V_4 -> V_14 , V_88 ) ;
V_28 = (struct V_20 * ) F_46 ( V_4 -> V_14 , V_84 ) ;
F_51 ( & V_4 -> V_10 ) ;
F_52 ( & V_4 -> V_11 ) ;
F_52 ( & V_4 -> V_71 ) ;
V_4 -> V_89 = V_90 ;
V_4 -> V_6 = V_6 ;
memcpy ( V_28 , V_73 , V_84 ) ;
* V_75 = 1 ;
if ( V_76 )
memcpy ( V_28 -> V_91 , V_92 , V_32 ) ;
V_85 = V_74 / sizeof( struct V_49 ) ;
if ( V_28 -> V_53 > V_85 )
V_28 -> V_53 = V_85 ;
F_41 ( V_6 , & V_4 -> V_71 , V_28 -> V_87 ) ;
V_83 = F_53 ( V_6 -> V_34 , F_10 ,
F_12 , V_4 ,
& V_4 -> V_23 ) ;
if ( V_83 != 0 ) {
F_40 ( & V_4 -> V_10 , F_1 ) ;
V_4 = NULL ;
}
return V_4 ;
}
void F_54 ( struct V_5 * V_6 ,
struct V_20 * V_73 ,
int V_74 )
{
struct V_3 * V_4 ;
int V_75 , V_76 ;
int V_64 = F_32 ( & V_6 -> V_65 ) ;
V_76 = ( V_64 == V_93 ) ;
F_4 ( & V_6 -> V_68 ) ;
V_4 = F_44 ( V_6 , V_73 , V_74 ,
& V_75 , V_76 ) ;
if ( ! V_4 )
goto V_94;
if ( V_64 == V_93 && V_75 )
F_35 ( V_6 , V_4 ) ;
V_94:
F_8 ( & V_6 -> V_68 ) ;
}
void F_55 ( struct V_5 * V_6 ,
struct V_20 * V_73 ,
int V_74 )
{
struct V_3 * V_4 ;
struct V_20 * V_28 ;
int V_75 ;
int V_64 = F_32 ( & V_6 -> V_65 ) ;
int V_95 = 0 ;
if ( F_56 ( V_73 -> V_91 ) )
return;
if ( V_64 == V_93 &&
F_57 ( V_73 -> V_91 ) )
V_95 = 1 ;
F_4 ( & V_6 -> V_68 ) ;
V_4 = F_44 ( V_6 , V_73 , V_74 ,
& V_75 , V_95 ) ;
if ( ! V_4 )
goto V_94;
V_28 = (struct V_20 * ) V_4 -> V_14 -> V_24 ;
if ( V_95 && V_75 ) {
V_28 -> V_96 = V_93 ;
F_35 ( V_6 , V_4 ) ;
} else if ( ! F_57 ( V_28 -> V_91 ) ) {
F_35 ( V_6 , V_4 ) ;
}
V_94:
F_8 ( & V_6 -> V_68 ) ;
}
static int F_58 ( struct V_5 * V_6 ,
struct V_3 * V_4 )
{
struct V_33 * V_30 = V_6 -> V_97 ;
struct V_98 * V_99 ;
struct V_15 * V_16 ;
struct V_35 * V_36 ;
struct V_100 * V_101 ;
struct V_20 * V_28 ;
int V_102 = - 1 ;
T_1 V_31 ;
V_28 = (struct V_20 * ) V_4 -> V_14 -> V_24 ;
for ( V_31 = 0 ; V_31 < V_30 -> V_26 ; V_31 ++ ) {
V_36 = & V_30 -> V_39 [ V_31 ] ;
F_14 () ;
F_15 (orig_node, node, head, hash_entry) {
V_99 = F_59 ( V_101 ) ;
if ( ! V_99 )
continue;
if ( ( V_101 -> V_103 & V_104 ) &&
( V_99 -> V_105 > V_102 ) ) {
V_102 = V_99 -> V_105 ;
memcpy ( V_28 -> V_91 , V_101 -> V_106 ,
V_32 ) ;
}
F_60 ( V_99 ) ;
}
F_16 () ;
}
return V_102 ;
}
static bool F_61 ( const struct V_3 * V_4 )
{
const struct V_20 * V_28 ;
T_2 V_107 ;
V_28 = (struct V_20 * ) V_4 -> V_14 -> V_24 ;
V_107 = V_108 / sizeof( struct V_49 ) ;
if ( V_107 < V_28 -> V_53 + 1 )
return true ;
return false ;
}
static int F_62 ( struct V_5 * V_6 )
{
struct V_33 * V_30 = V_6 -> V_97 ;
struct V_15 * V_16 ;
struct V_35 * V_36 ;
struct V_100 * V_101 ;
struct V_98 * V_99 ;
struct V_3 * V_4 = V_6 -> V_109 ;
struct V_20 * V_28 ;
struct V_49 * V_8 ;
struct V_110 * V_111 ;
int V_102 = - 1 ;
T_1 V_31 ;
V_4 -> V_89 = V_90 ;
V_28 = (struct V_20 * ) V_4 -> V_14 -> V_24 ;
V_28 -> V_96 = F_32 ( & V_6 -> V_65 ) ;
memcpy ( V_28 -> V_91 , V_92 , V_32 ) ;
V_28 -> V_112 . V_113 = V_114 ;
V_28 -> V_86 = F_63 ( F_48 ( V_28 -> V_86 ) + 1 ) ;
V_28 -> V_53 = 0 ;
V_28 -> V_115 = 0 ;
F_64 ( V_4 -> V_14 , sizeof( * V_28 ) ) ;
if ( V_28 -> V_96 == V_67 ) {
V_102 = F_58 ( V_6 , V_4 ) ;
if ( V_102 < 0 )
return V_102 ;
}
for ( V_31 = 0 ; V_31 < V_30 -> V_26 ; V_31 ++ ) {
V_36 = & V_30 -> V_39 [ V_31 ] ;
F_14 () ;
F_15 (orig_node, node, head, hash_entry) {
V_99 = F_59 ( V_101 ) ;
if ( ! V_99 )
continue;
if ( ! F_11 ( V_99 -> V_45 , V_101 -> V_106 ) )
goto V_116;
if ( V_99 -> V_117 -> V_118 != V_119 )
goto V_116;
if ( V_99 -> V_105 < 1 )
goto V_116;
V_8 = (struct V_49 * )
F_46 ( V_4 -> V_14 , sizeof( * V_8 ) ) ;
memcpy ( V_8 -> V_50 ,
V_99 -> V_117 -> V_61 -> V_120 ,
V_32 ) ;
memcpy ( V_8 -> V_52 , V_101 -> V_106 , V_32 ) ;
V_8 -> V_51 = V_99 -> V_105 ;
V_28 -> V_53 ++ ;
V_116:
F_60 ( V_99 ) ;
if ( F_61 ( V_4 ) )
goto V_121;
}
F_16 () ;
}
V_30 = V_6 -> V_122 ;
for ( V_31 = 0 ; V_31 < V_30 -> V_26 ; V_31 ++ ) {
V_36 = & V_30 -> V_39 [ V_31 ] ;
F_14 () ;
F_15 (tt_common_entry, node, head,
hash_entry) {
V_8 = (struct V_49 * )
F_46 ( V_4 -> V_14 ,
sizeof( * V_8 ) ) ;
memset ( V_8 -> V_50 , 0 , V_32 ) ;
memcpy ( V_8 -> V_52 , V_111 -> V_45 , V_32 ) ;
V_8 -> V_51 = 0 ;
V_28 -> V_53 ++ ;
if ( F_61 ( V_4 ) )
goto V_121;
}
F_16 () ;
}
return 0 ;
V_121:
F_16 () ;
return 0 ;
}
static void F_65 ( struct V_5 * V_6 )
{
T_1 V_31 ;
struct V_33 * V_30 = V_6 -> V_34 ;
struct V_15 * V_16 , * V_123 ;
struct V_35 * V_36 ;
struct V_3 * V_4 ;
for ( V_31 = 0 ; V_31 < V_30 -> V_26 ; V_31 ++ ) {
V_36 = & V_30 -> V_39 [ V_31 ] ;
F_28 (info, node, node_tmp,
head, hash_entry) {
if ( V_4 == V_6 -> V_109 )
continue;
if ( F_66 ( V_4 -> V_89 ,
V_124 ) ) {
F_29 ( V_16 ) ;
F_39 ( V_4 ) ;
F_40 ( & V_4 -> V_10 , F_1 ) ;
}
}
}
}
static void F_67 ( struct V_5 * V_6 ,
struct V_3 * V_4 )
{
struct V_98 * V_99 ;
struct V_33 * V_30 = V_6 -> V_97 ;
struct V_15 * V_16 ;
struct V_35 * V_36 ;
struct V_100 * V_101 ;
struct V_20 * V_28 ;
struct V_81 * V_125 ;
struct V_58 * V_126 ;
T_3 V_127 [ V_32 ] ;
T_1 V_31 ;
V_28 = (struct V_20 * ) V_4 -> V_14 -> V_24 ;
for ( V_31 = 0 ; V_31 < V_30 -> V_26 ; V_31 ++ ) {
V_36 = & V_30 -> V_39 [ V_31 ] ;
F_14 () ;
F_15 (orig_node, node, head, hash_entry) {
if ( ! ( V_101 -> V_103 & V_104 ) )
continue;
V_99 = F_59 ( V_101 ) ;
if ( ! V_99 )
continue;
if ( F_42 ( V_6 , & V_4 -> V_71 ,
V_101 -> V_106 ) ) {
F_60 ( V_99 ) ;
continue;
}
memcpy ( V_28 -> V_91 , V_101 -> V_106 , V_32 ) ;
V_126 = V_99 -> V_117 ;
memcpy ( V_127 , V_99 -> V_45 , V_32 ) ;
F_60 ( V_99 ) ;
V_125 = F_68 ( V_4 -> V_14 , V_46 ) ;
if ( V_125 )
F_69 ( V_125 , V_126 ,
V_127 ) ;
}
F_16 () ;
}
}
static void F_70 ( struct V_5 * V_6 ,
struct V_3 * V_4 )
{
struct V_100 * V_101 ;
struct V_98 * V_99 = NULL ;
struct V_81 * V_125 ;
struct V_20 * V_28 ;
V_28 = (struct V_20 * ) V_4 -> V_14 -> V_24 ;
V_101 = F_71 ( V_6 , V_28 -> V_91 ) ;
if ( ! V_101 )
goto V_66;
V_99 = F_59 ( V_101 ) ;
if ( ! V_99 )
goto V_66;
V_125 = F_68 ( V_4 -> V_14 , V_46 ) ;
if ( V_125 )
F_69 ( V_125 , V_99 -> V_117 , V_99 -> V_45 ) ;
V_66:
if ( V_99 )
F_60 ( V_99 ) ;
if ( V_101 )
F_72 ( V_101 ) ;
}
static void F_73 ( struct V_5 * V_6 ,
struct V_3 * V_4 )
{
struct V_58 * V_59 ;
struct V_20 * V_28 ;
V_59 = F_33 ( V_6 ) ;
if ( ! V_59 )
goto V_66;
V_28 = (struct V_20 * ) V_4 -> V_14 -> V_24 ;
if ( V_28 -> V_112 . V_113 < 2 ) {
F_74 ( L_7 ) ;
goto V_66;
}
memcpy ( V_28 -> V_87 , V_59 -> V_61 -> V_120 , V_32 ) ;
V_28 -> V_112 . V_113 -- ;
if ( F_56 ( V_28 -> V_91 ) )
F_67 ( V_6 , V_4 ) ;
else
F_70 ( V_6 , V_4 ) ;
V_28 -> V_112 . V_113 ++ ;
V_66:
if ( V_59 )
F_34 ( V_59 ) ;
}
static void F_75 ( struct V_128 * V_129 )
{
struct V_130 * V_130 =
F_2 ( V_129 , struct V_130 , V_129 ) ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
V_6 = F_2 ( V_130 , struct V_5 , V_131 ) ;
F_4 ( & V_6 -> V_68 ) ;
F_65 ( V_6 ) ;
if ( F_62 ( V_6 ) == 0 ) {
F_35 ( V_6 , V_6 -> V_109 ) ;
}
while ( ! F_36 ( & V_6 -> V_69 ) ) {
V_4 = F_76 ( & V_6 -> V_69 ,
F_77 ( * V_4 ) , V_11 ) ;
F_37 ( & V_4 -> V_10 ) ;
F_8 ( & V_6 -> V_68 ) ;
F_73 ( V_6 , V_4 ) ;
F_4 ( & V_6 -> V_68 ) ;
F_39 ( V_4 ) ;
F_40 ( & V_4 -> V_10 , F_1 ) ;
}
F_8 ( & V_6 -> V_68 ) ;
F_78 ( V_6 ) ;
}
int F_79 ( struct V_5 * V_6 )
{
struct V_20 * V_28 ;
int V_83 ;
unsigned int V_84 ;
unsigned long V_89 ;
struct V_81 * V_82 ;
if ( V_6 -> V_34 )
return 0 ;
F_4 ( & V_6 -> V_68 ) ;
V_6 -> V_34 = F_80 ( 256 ) ;
if ( ! V_6 -> V_34 ) {
F_81 ( L_8 ) ;
goto V_132;
}
V_6 -> V_109 = F_19 ( V_108 , V_46 ) ;
if ( ! V_6 -> V_109 )
goto V_132;
V_84 = sizeof( * V_28 ) + V_108 + V_88 ;
V_6 -> V_109 -> V_14 = F_45 ( V_84 ) ;
if ( ! V_6 -> V_109 -> V_14 )
goto V_133;
F_50 ( V_6 -> V_109 -> V_14 , V_88 ) ;
V_82 = V_6 -> V_109 -> V_14 ;
V_28 = (struct V_20 * ) F_46 ( V_82 , sizeof( * V_28 ) ) ;
V_89 = V_90 - F_82 ( V_134 ) ;
V_6 -> V_109 -> V_89 = V_89 ;
F_52 ( & V_6 -> V_109 -> V_71 ) ;
F_52 ( & V_6 -> V_109 -> V_11 ) ;
F_51 ( & V_6 -> V_109 -> V_10 ) ;
V_6 -> V_109 -> V_6 = V_6 ;
V_28 -> V_112 . V_135 = V_136 ;
V_28 -> V_112 . V_137 = V_138 ;
V_28 -> V_112 . V_113 = V_114 ;
V_28 -> V_86 = 0 ;
V_28 -> V_115 = 0 ;
V_28 -> V_53 = 0 ;
F_52 ( & V_6 -> V_69 ) ;
V_83 = F_53 ( V_6 -> V_34 , F_10 ,
F_12 ,
V_6 -> V_109 ,
& V_6 -> V_109 -> V_23 ) ;
if ( V_83 != 0 ) {
F_81 ( L_9 ) ;
F_40 ( & V_6 -> V_109 -> V_10 , F_1 ) ;
goto V_132;
}
F_8 ( & V_6 -> V_68 ) ;
F_78 ( V_6 ) ;
return 0 ;
V_133:
F_7 ( V_6 -> V_109 ) ;
V_6 -> V_109 = NULL ;
V_132:
F_8 ( & V_6 -> V_68 ) ;
F_83 ( V_6 ) ;
return - V_139 ;
}
static void F_84 ( struct V_15 * V_16 , void * V_140 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_16 , struct V_3 , V_23 ) ;
F_39 ( V_4 ) ;
F_40 ( & V_4 -> V_10 , F_1 ) ;
}
void F_83 ( struct V_5 * V_6 )
{
if ( ! V_6 -> V_34 )
return;
F_85 ( & V_6 -> V_131 ) ;
F_4 ( & V_6 -> V_68 ) ;
F_86 ( V_6 -> V_34 , F_84 , NULL ) ;
V_6 -> V_34 = NULL ;
V_6 -> V_109 = NULL ;
F_8 ( & V_6 -> V_68 ) ;
}
static void F_78 ( struct V_5 * V_6 )
{
F_87 ( & V_6 -> V_131 , F_75 ) ;
F_88 ( V_141 , & V_6 -> V_131 ,
F_82 ( V_134 ) ) ;
}
