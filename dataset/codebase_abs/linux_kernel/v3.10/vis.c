static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 , * V_9 ;
V_4 = F_2 ( V_2 , struct V_3 , V_10 ) ;
V_6 = V_4 -> V_6 ;
F_3 ( & V_4 -> V_11 ) ;
F_4 ( & V_6 -> V_12 . V_13 ) ;
F_5 (entry, tmp, &info->recv_list, list) {
F_6 ( & V_8 -> V_14 ) ;
F_7 ( V_8 ) ;
}
F_8 ( & V_6 -> V_12 . V_13 ) ;
F_9 ( V_4 -> V_15 ) ;
F_7 ( V_4 ) ;
}
static int F_10 ( const struct V_16 * V_17 , const void * V_18 )
{
const struct V_3 * V_19 , * V_20 ;
const struct V_21 * V_22 , * V_23 ;
V_19 = F_2 ( V_17 , struct V_3 , V_24 ) ;
V_20 = V_18 ;
V_22 = (struct V_21 * ) V_19 -> V_15 -> V_25 ;
V_23 = (struct V_21 * ) V_20 -> V_15 -> V_25 ;
return F_11 ( V_22 -> V_26 , V_23 -> V_26 ) ;
}
static T_1 F_12 ( const void * V_25 , T_1 V_27 )
{
const struct V_3 * V_28 = V_25 ;
const struct V_21 * V_29 ;
const unsigned char * V_30 ;
T_1 V_31 = 0 ;
T_2 V_32 ;
V_29 = (struct V_21 * ) V_28 -> V_15 -> V_25 ;
V_30 = V_29 -> V_26 ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ ) {
V_31 += V_30 [ V_32 ] ;
V_31 += ( V_31 << 10 ) ;
V_31 ^= ( V_31 >> 6 ) ;
}
V_31 += ( V_31 << 3 ) ;
V_31 ^= ( V_31 >> 11 ) ;
V_31 += ( V_31 << 15 ) ;
return V_31 % V_27 ;
}
static struct V_3 *
F_13 ( struct V_5 * V_6 , const void * V_25 )
{
struct V_34 * V_31 = V_6 -> V_12 . V_31 ;
struct V_35 * V_36 ;
struct V_3 * V_28 , * V_37 = NULL ;
T_1 V_38 ;
if ( ! V_31 )
return NULL ;
V_38 = F_12 ( V_25 , V_31 -> V_27 ) ;
V_36 = & V_31 -> V_39 [ V_38 ] ;
F_14 () ;
F_15 (vis_info, head, hash_entry) {
if ( ! F_10 ( & V_28 -> V_24 , V_25 ) )
continue;
V_37 = V_28 ;
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
F_18 (entry, if_list, list) {
if ( F_11 ( V_8 -> V_44 , V_40 ) )
return;
}
V_8 = F_19 ( sizeof( * V_8 ) , V_45 ) ;
if ( ! V_8 )
return;
memcpy ( V_8 -> V_44 , V_40 , V_33 ) ;
V_8 -> V_42 = V_42 ;
F_20 ( & V_8 -> V_14 , V_41 ) ;
}
static void F_21 ( struct V_46 * V_47 ,
const struct V_35 * V_41 )
{
struct V_43 * V_8 ;
F_18 (entry, if_list, list) {
if ( V_8 -> V_42 )
F_22 ( V_47 , L_1 ) ;
else
F_23 ( V_47 , L_2 , V_8 -> V_44 ) ;
}
}
static T_4
F_24 ( struct V_46 * V_47 ,
const struct V_48 * V_8 ,
const T_3 * V_49 , bool V_42 )
{
if ( V_42 && V_8 -> V_50 == 0 )
return F_23 ( V_47 , L_3 , V_8 -> V_51 ) ;
else if ( F_11 ( V_8 -> V_49 , V_49 ) )
return F_23 ( V_47 , L_4 , V_8 -> V_51 ,
V_8 -> V_50 ) ;
return 0 ;
}
static void
F_25 ( struct V_35 * V_14 ,
struct V_21 * V_29 ,
struct V_48 * V_52 )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < V_29 -> V_52 ; V_32 ++ ) {
if ( V_52 [ V_32 ] . V_50 == 0 )
continue;
if ( F_11 ( V_52 [ V_32 ] . V_49 , V_29 -> V_26 ) )
continue;
F_17 ( V_52 [ V_32 ] . V_49 , V_14 , false ) ;
}
}
static void F_26 ( struct V_46 * V_47 ,
struct V_35 * V_14 ,
struct V_21 * V_29 ,
struct V_48 * V_52 )
{
int V_32 ;
struct V_43 * V_8 ;
F_18 (entry, list, list) {
F_23 ( V_47 , L_5 , V_8 -> V_44 ) ;
for ( V_32 = 0 ; V_32 < V_29 -> V_52 ; V_32 ++ )
F_24 ( V_47 , & V_52 [ V_32 ] ,
V_8 -> V_44 , V_8 -> V_42 ) ;
if ( F_11 ( V_8 -> V_44 , V_29 -> V_26 ) )
F_21 ( V_47 , V_14 ) ;
F_22 ( V_47 , L_6 ) ;
}
}
static void F_27 ( struct V_46 * V_47 ,
const struct V_35 * V_36 )
{
struct V_3 * V_4 ;
struct V_21 * V_29 ;
T_3 * V_53 ;
struct V_48 * V_52 ;
struct V_43 * V_8 ;
struct V_16 * V_54 ;
F_28 ( V_55 ) ;
F_15 (info, head, hash_entry) {
V_29 = (struct V_21 * ) V_4 -> V_15 -> V_25 ;
V_53 = ( T_3 * ) V_29 + sizeof( * V_29 ) ;
V_52 = (struct V_48 * ) V_53 ;
F_17 ( V_29 -> V_26 , & V_55 ,
true ) ;
F_25 ( & V_55 , V_29 ,
V_52 ) ;
F_26 ( V_47 , & V_55 , V_29 ,
V_52 ) ;
F_29 (entry, n, &vis_if_list, list) {
F_30 ( & V_8 -> V_14 ) ;
F_7 ( V_8 ) ;
}
}
}
int F_31 ( struct V_46 * V_47 , void * V_56 )
{
struct V_57 * V_58 ;
struct V_35 * V_36 ;
struct V_59 * V_60 = (struct V_59 * ) V_47 -> V_61 ;
struct V_5 * V_6 = F_32 ( V_60 ) ;
struct V_34 * V_31 = V_6 -> V_12 . V_31 ;
T_1 V_32 ;
int V_62 = 0 ;
int V_63 = F_33 ( & V_6 -> V_64 ) ;
V_58 = F_34 ( V_6 ) ;
if ( ! V_58 )
goto V_65;
if ( V_63 == V_66 )
goto V_65;
F_4 ( & V_6 -> V_12 . V_67 ) ;
for ( V_32 = 0 ; V_32 < V_31 -> V_27 ; V_32 ++ ) {
V_36 = & V_31 -> V_39 [ V_32 ] ;
F_27 ( V_47 , V_36 ) ;
}
F_8 ( & V_6 -> V_12 . V_67 ) ;
V_65:
if ( V_58 )
F_35 ( V_58 ) ;
return V_62 ;
}
static void F_36 ( struct V_5 * V_6 ,
struct V_3 * V_4 )
{
if ( F_37 ( & V_4 -> V_11 ) ) {
F_38 ( & V_4 -> V_10 ) ;
F_39 ( & V_4 -> V_11 , & V_6 -> V_12 . V_11 ) ;
}
}
static void F_40 ( struct V_3 * V_4 )
{
if ( ! F_37 ( & V_4 -> V_11 ) ) {
F_3 ( & V_4 -> V_11 ) ;
F_41 ( & V_4 -> V_10 , F_1 ) ;
}
}
static void F_42 ( struct V_5 * V_6 ,
struct V_68 * V_69 , const char * V_70 )
{
struct V_7 * V_8 ;
V_8 = F_19 ( sizeof( * V_8 ) , V_45 ) ;
if ( ! V_8 )
return;
memcpy ( V_8 -> V_70 , V_70 , V_33 ) ;
F_4 ( & V_6 -> V_12 . V_13 ) ;
F_39 ( & V_8 -> V_14 , V_69 ) ;
F_8 ( & V_6 -> V_12 . V_13 ) ;
}
static int F_43 ( struct V_5 * V_6 ,
const struct V_68 * V_69 ,
const char * V_70 )
{
const struct V_7 * V_8 ;
F_4 ( & V_6 -> V_12 . V_13 ) ;
F_44 (entry, recv_list, list) {
if ( F_11 ( V_8 -> V_70 , V_70 ) ) {
F_8 ( & V_6 -> V_12 . V_13 ) ;
return 1 ;
}
}
F_8 ( & V_6 -> V_12 . V_13 ) ;
return 0 ;
}
static struct V_3 *
F_45 ( struct V_5 * V_6 ,
struct V_21 * V_71 , int V_72 ,
int * V_73 , int V_74 )
{
struct V_3 * V_4 , * V_75 ;
struct V_21 * V_76 , * V_77 ;
struct V_3 V_78 ;
struct V_21 * V_29 ;
struct V_79 * V_80 ;
int V_81 ;
T_2 V_82 ;
T_2 V_83 ;
* V_73 = 0 ;
if ( ! V_6 -> V_12 . V_31 )
return NULL ;
V_78 . V_15 = F_46 ( sizeof( * V_76 ) ) ;
if ( ! V_78 . V_15 )
return NULL ;
V_82 = sizeof( * V_76 ) ;
V_80 = V_78 . V_15 ;
V_76 = (struct V_21 * ) F_47 ( V_80 , V_82 ) ;
memcpy ( V_76 -> V_26 , V_71 -> V_26 , V_33 ) ;
V_75 = F_13 ( V_6 , & V_78 ) ;
F_9 ( V_78 . V_15 ) ;
if ( V_75 ) {
V_80 = V_75 -> V_15 ;
V_77 = (struct V_21 * ) V_80 -> V_25 ;
if ( ! F_48 ( F_49 ( V_71 -> V_84 ) ,
F_49 ( V_77 -> V_84 ) ) ) {
if ( V_77 -> V_84 == V_71 -> V_84 ) {
F_42 ( V_6 ,
& V_75 -> V_69 ,
V_71 -> V_85 ) ;
return V_75 ;
} else {
return NULL ;
}
}
F_50 ( V_6 -> V_12 . V_31 , F_10 ,
F_12 , V_75 ) ;
F_40 ( V_75 ) ;
F_41 ( & V_75 -> V_10 , F_1 ) ;
}
V_4 = F_19 ( sizeof( * V_4 ) , V_45 ) ;
if ( ! V_4 )
return NULL ;
V_82 = sizeof( * V_29 ) + V_72 ;
V_4 -> V_15 = F_46 ( V_82 + V_86 + V_87 ) ;
if ( ! V_4 -> V_15 ) {
F_7 ( V_4 ) ;
return NULL ;
}
F_51 ( V_4 -> V_15 , V_86 + V_87 ) ;
V_29 = (struct V_21 * ) F_47 ( V_4 -> V_15 , V_82 ) ;
F_52 ( & V_4 -> V_10 ) ;
F_53 ( & V_4 -> V_11 ) ;
F_53 ( & V_4 -> V_69 ) ;
V_4 -> V_88 = V_89 ;
V_4 -> V_6 = V_6 ;
memcpy ( V_29 , V_71 , V_82 ) ;
* V_73 = 1 ;
if ( V_74 )
memcpy ( V_29 -> V_90 , V_91 , V_33 ) ;
V_83 = V_72 / sizeof( struct V_48 ) ;
if ( V_29 -> V_52 > V_83 )
V_29 -> V_52 = V_83 ;
F_42 ( V_6 , & V_4 -> V_69 , V_29 -> V_85 ) ;
V_81 = F_54 ( V_6 -> V_12 . V_31 , F_10 ,
F_12 , V_4 ,
& V_4 -> V_24 ) ;
if ( V_81 != 0 ) {
F_41 ( & V_4 -> V_10 , F_1 ) ;
V_4 = NULL ;
}
return V_4 ;
}
void F_55 ( struct V_5 * V_6 ,
struct V_21 * V_71 ,
int V_72 )
{
struct V_3 * V_4 ;
int V_73 , V_74 ;
int V_63 = F_33 ( & V_6 -> V_64 ) ;
V_74 = ( V_63 == V_92 ) ;
F_4 ( & V_6 -> V_12 . V_67 ) ;
V_4 = F_45 ( V_6 , V_71 , V_72 ,
& V_73 , V_74 ) ;
if ( ! V_4 )
goto V_93;
if ( V_63 == V_92 && V_73 )
F_36 ( V_6 , V_4 ) ;
V_93:
F_8 ( & V_6 -> V_12 . V_67 ) ;
}
void F_56 ( struct V_5 * V_6 ,
struct V_21 * V_71 ,
int V_72 )
{
struct V_3 * V_4 ;
struct V_21 * V_29 ;
int V_73 ;
int V_63 = F_33 ( & V_6 -> V_64 ) ;
int V_94 = 0 ;
if ( F_57 ( V_71 -> V_90 ) )
return;
if ( V_63 == V_92 &&
F_58 ( V_6 , V_71 -> V_90 ) )
V_94 = 1 ;
F_4 ( & V_6 -> V_12 . V_67 ) ;
V_4 = F_45 ( V_6 , V_71 , V_72 ,
& V_73 , V_94 ) ;
if ( ! V_4 )
goto V_93;
V_29 = (struct V_21 * ) V_4 -> V_15 -> V_25 ;
if ( V_94 && V_73 ) {
V_29 -> V_95 = V_92 ;
F_36 ( V_6 , V_4 ) ;
} else if ( ! F_58 ( V_6 , V_29 -> V_90 ) ) {
F_36 ( V_6 , V_4 ) ;
}
V_93:
F_8 ( & V_6 -> V_12 . V_67 ) ;
}
static int F_59 ( struct V_5 * V_6 ,
struct V_3 * V_4 )
{
struct V_34 * V_31 = V_6 -> V_96 ;
struct V_97 * V_98 ;
struct V_35 * V_36 ;
struct V_99 * V_100 ;
struct V_21 * V_29 ;
int V_101 = - 1 ;
T_1 V_32 ;
V_29 = (struct V_21 * ) V_4 -> V_15 -> V_25 ;
for ( V_32 = 0 ; V_32 < V_31 -> V_27 ; V_32 ++ ) {
V_36 = & V_31 -> V_39 [ V_32 ] ;
F_14 () ;
F_15 (orig_node, head, hash_entry) {
V_98 = F_60 ( V_100 ) ;
if ( ! V_98 )
continue;
if ( ( V_100 -> V_102 & V_103 ) &&
( V_98 -> V_104 > V_101 ) ) {
V_101 = V_98 -> V_104 ;
memcpy ( V_29 -> V_90 , V_100 -> V_105 ,
V_33 ) ;
}
F_61 ( V_98 ) ;
}
F_16 () ;
}
return V_101 ;
}
static bool F_62 ( const struct V_3 * V_4 )
{
const struct V_21 * V_29 ;
T_2 V_106 ;
V_29 = (struct V_21 * ) V_4 -> V_15 -> V_25 ;
V_106 = V_107 / sizeof( struct V_48 ) ;
if ( V_106 < V_29 -> V_52 + 1 )
return true ;
return false ;
}
static int F_63 ( struct V_5 * V_6 )
{
struct V_34 * V_31 = V_6 -> V_96 ;
struct V_35 * V_36 ;
struct V_99 * V_100 ;
struct V_97 * V_98 ;
struct V_3 * V_4 = V_6 -> V_12 . V_108 ;
struct V_21 * V_29 ;
struct V_48 * V_8 ;
struct V_109 * V_110 ;
T_3 * V_111 ;
int V_101 = - 1 ;
T_1 V_32 ;
V_4 -> V_88 = V_89 ;
V_29 = (struct V_21 * ) V_4 -> V_15 -> V_25 ;
V_29 -> V_95 = F_33 ( & V_6 -> V_64 ) ;
memcpy ( V_29 -> V_90 , V_91 , V_33 ) ;
V_29 -> V_112 . V_113 = V_114 ;
V_29 -> V_84 = F_64 ( F_49 ( V_29 -> V_84 ) + 1 ) ;
V_29 -> V_52 = 0 ;
V_29 -> V_115 = 0 ;
F_65 ( V_4 -> V_15 , sizeof( * V_29 ) ) ;
if ( V_29 -> V_95 == V_66 ) {
V_101 = F_59 ( V_6 , V_4 ) ;
if ( V_101 < 0 )
return V_101 ;
}
for ( V_32 = 0 ; V_32 < V_31 -> V_27 ; V_32 ++ ) {
V_36 = & V_31 -> V_39 [ V_32 ] ;
F_14 () ;
F_15 (orig_node, head, hash_entry) {
V_98 = F_60 ( V_100 ) ;
if ( ! V_98 )
continue;
if ( ! F_11 ( V_98 -> V_44 , V_100 -> V_105 ) )
goto V_116;
if ( V_98 -> V_117 -> V_118 != V_119 )
goto V_116;
if ( V_98 -> V_104 < 1 )
goto V_116;
V_111 = F_47 ( V_4 -> V_15 , sizeof( * V_8 ) ) ;
V_8 = (struct V_48 * ) V_111 ;
memcpy ( V_8 -> V_49 ,
V_98 -> V_117 -> V_60 -> V_120 ,
V_33 ) ;
memcpy ( V_8 -> V_51 , V_100 -> V_105 , V_33 ) ;
V_8 -> V_50 = V_98 -> V_104 ;
V_29 -> V_52 ++ ;
V_116:
F_61 ( V_98 ) ;
if ( F_62 ( V_4 ) )
goto V_121;
}
F_16 () ;
}
V_31 = V_6 -> V_122 . V_123 ;
for ( V_32 = 0 ; V_32 < V_31 -> V_27 ; V_32 ++ ) {
V_36 = & V_31 -> V_39 [ V_32 ] ;
F_14 () ;
F_15 (tt_common_entry, head,
hash_entry) {
V_111 = F_47 ( V_4 -> V_15 , sizeof( * V_8 ) ) ;
V_8 = (struct V_48 * ) V_111 ;
memset ( V_8 -> V_49 , 0 , V_33 ) ;
memcpy ( V_8 -> V_51 , V_110 -> V_44 , V_33 ) ;
V_8 -> V_50 = 0 ;
V_29 -> V_52 ++ ;
if ( F_62 ( V_4 ) )
goto V_121;
}
F_16 () ;
}
return 0 ;
V_121:
F_16 () ;
return 0 ;
}
static void F_66 ( struct V_5 * V_6 )
{
T_1 V_32 ;
struct V_34 * V_31 = V_6 -> V_12 . V_31 ;
struct V_16 * V_124 ;
struct V_35 * V_36 ;
struct V_3 * V_4 ;
for ( V_32 = 0 ; V_32 < V_31 -> V_27 ; V_32 ++ ) {
V_36 = & V_31 -> V_39 [ V_32 ] ;
F_29 (info, node_tmp,
head, hash_entry) {
if ( V_4 == V_6 -> V_12 . V_108 )
continue;
if ( F_67 ( V_4 -> V_88 ,
V_125 ) ) {
F_30 ( & V_4 -> V_24 ) ;
F_40 ( V_4 ) ;
F_41 ( & V_4 -> V_10 , F_1 ) ;
}
}
}
}
static void F_68 ( struct V_5 * V_6 ,
struct V_3 * V_4 )
{
struct V_34 * V_31 = V_6 -> V_96 ;
struct V_35 * V_36 ;
struct V_99 * V_100 ;
struct V_21 * V_29 ;
struct V_79 * V_126 ;
T_1 V_32 ;
V_29 = (struct V_21 * ) V_4 -> V_15 -> V_25 ;
for ( V_32 = 0 ; V_32 < V_31 -> V_27 ; V_32 ++ ) {
V_36 = & V_31 -> V_39 [ V_32 ] ;
F_14 () ;
F_15 (orig_node, head, hash_entry) {
if ( ! ( V_100 -> V_102 & V_103 ) )
continue;
if ( F_43 ( V_6 , & V_4 -> V_69 ,
V_100 -> V_105 ) )
continue;
memcpy ( V_29 -> V_90 , V_100 -> V_105 , V_33 ) ;
V_126 = F_69 ( V_4 -> V_15 , V_45 ) ;
if ( ! V_126 )
continue;
if ( ! F_70 ( V_126 , V_100 , NULL ) )
F_9 ( V_126 ) ;
}
F_16 () ;
}
}
static void F_71 ( struct V_5 * V_6 ,
struct V_3 * V_4 )
{
struct V_99 * V_100 ;
struct V_79 * V_126 ;
struct V_21 * V_29 ;
V_29 = (struct V_21 * ) V_4 -> V_15 -> V_25 ;
V_100 = F_72 ( V_6 , V_29 -> V_90 ) ;
if ( ! V_100 )
goto V_65;
V_126 = F_69 ( V_4 -> V_15 , V_45 ) ;
if ( ! V_126 )
goto V_65;
if ( ! F_70 ( V_126 , V_100 , NULL ) )
F_9 ( V_126 ) ;
V_65:
if ( V_100 )
F_73 ( V_100 ) ;
}
static void F_74 ( struct V_5 * V_6 ,
struct V_3 * V_4 )
{
struct V_57 * V_58 ;
struct V_21 * V_29 ;
V_58 = F_34 ( V_6 ) ;
if ( ! V_58 )
goto V_65;
V_29 = (struct V_21 * ) V_4 -> V_15 -> V_25 ;
if ( V_29 -> V_112 . V_113 < 2 ) {
F_75 ( L_7 ) ;
goto V_65;
}
memcpy ( V_29 -> V_85 , V_58 -> V_60 -> V_120 , V_33 ) ;
V_29 -> V_112 . V_113 -- ;
if ( F_57 ( V_29 -> V_90 ) )
F_68 ( V_6 , V_4 ) ;
else
F_71 ( V_6 , V_4 ) ;
V_29 -> V_112 . V_113 ++ ;
V_65:
if ( V_58 )
F_35 ( V_58 ) ;
}
static void F_76 ( struct V_127 * V_128 )
{
struct V_129 * V_129 ;
struct V_5 * V_6 ;
struct V_130 * V_131 ;
struct V_3 * V_4 ;
V_129 = F_2 ( V_128 , struct V_129 , V_128 ) ;
V_131 = F_2 ( V_129 , struct V_130 , V_128 ) ;
V_6 = F_2 ( V_131 , struct V_5 , V_12 ) ;
F_4 ( & V_6 -> V_12 . V_67 ) ;
F_66 ( V_6 ) ;
if ( F_63 ( V_6 ) == 0 ) {
F_36 ( V_6 , V_6 -> V_12 . V_108 ) ;
}
while ( ! F_37 ( & V_6 -> V_12 . V_11 ) ) {
V_4 = F_77 ( & V_6 -> V_12 . V_11 ,
F_78 ( * V_4 ) , V_11 ) ;
F_38 ( & V_4 -> V_10 ) ;
F_8 ( & V_6 -> V_12 . V_67 ) ;
F_74 ( V_6 , V_4 ) ;
F_4 ( & V_6 -> V_12 . V_67 ) ;
F_40 ( V_4 ) ;
F_41 ( & V_4 -> V_10 , F_1 ) ;
}
F_8 ( & V_6 -> V_12 . V_67 ) ;
F_79 ( V_132 , & V_6 -> V_12 . V_128 ,
F_80 ( V_133 ) ) ;
}
int F_81 ( struct V_5 * V_6 )
{
struct V_21 * V_29 ;
int V_81 ;
unsigned int V_82 ;
unsigned long V_88 ;
struct V_79 * V_80 ;
if ( V_6 -> V_12 . V_31 )
return 0 ;
F_4 ( & V_6 -> V_12 . V_67 ) ;
V_6 -> V_12 . V_31 = F_82 ( 256 ) ;
if ( ! V_6 -> V_12 . V_31 ) {
F_83 ( L_8 ) ;
goto V_134;
}
F_84 ( V_6 -> V_12 . V_31 ,
& V_135 ) ;
V_6 -> V_12 . V_108 = F_19 ( V_107 , V_45 ) ;
if ( ! V_6 -> V_12 . V_108 )
goto V_134;
V_82 = sizeof( * V_29 ) + V_107 ;
V_82 += V_86 + V_87 ;
V_6 -> V_12 . V_108 -> V_15 = F_46 ( V_82 ) ;
if ( ! V_6 -> V_12 . V_108 -> V_15 )
goto V_136;
F_51 ( V_6 -> V_12 . V_108 -> V_15 , V_86 + V_87 ) ;
V_80 = V_6 -> V_12 . V_108 -> V_15 ;
V_29 = (struct V_21 * ) F_47 ( V_80 , sizeof( * V_29 ) ) ;
V_88 = V_89 - F_80 ( V_133 ) ;
V_6 -> V_12 . V_108 -> V_88 = V_88 ;
F_53 ( & V_6 -> V_12 . V_108 -> V_69 ) ;
F_53 ( & V_6 -> V_12 . V_108 -> V_11 ) ;
F_52 ( & V_6 -> V_12 . V_108 -> V_10 ) ;
V_6 -> V_12 . V_108 -> V_6 = V_6 ;
V_29 -> V_112 . V_137 = V_138 ;
V_29 -> V_112 . V_139 = V_140 ;
V_29 -> V_112 . V_113 = V_114 ;
V_29 -> V_84 = 0 ;
V_29 -> V_115 = 0 ;
V_29 -> V_52 = 0 ;
F_53 ( & V_6 -> V_12 . V_11 ) ;
V_81 = F_54 ( V_6 -> V_12 . V_31 , F_10 ,
F_12 ,
V_6 -> V_12 . V_108 ,
& V_6 -> V_12 . V_108 -> V_24 ) ;
if ( V_81 != 0 ) {
F_83 ( L_9 ) ;
F_41 ( & V_6 -> V_12 . V_108 -> V_10 , F_1 ) ;
goto V_134;
}
F_8 ( & V_6 -> V_12 . V_67 ) ;
F_85 ( & V_6 -> V_12 . V_128 , F_76 ) ;
F_79 ( V_132 , & V_6 -> V_12 . V_128 ,
F_80 ( V_133 ) ) ;
return 0 ;
V_136:
F_7 ( V_6 -> V_12 . V_108 ) ;
V_6 -> V_12 . V_108 = NULL ;
V_134:
F_8 ( & V_6 -> V_12 . V_67 ) ;
F_86 ( V_6 ) ;
return - V_141 ;
}
static void F_87 ( struct V_16 * V_17 , void * V_142 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_17 , struct V_3 , V_24 ) ;
F_40 ( V_4 ) ;
F_41 ( & V_4 -> V_10 , F_1 ) ;
}
void F_86 ( struct V_5 * V_6 )
{
if ( ! V_6 -> V_12 . V_31 )
return;
F_88 ( & V_6 -> V_12 . V_128 ) ;
F_4 ( & V_6 -> V_12 . V_67 ) ;
F_89 ( V_6 -> V_12 . V_31 , F_87 , NULL ) ;
V_6 -> V_12 . V_31 = NULL ;
V_6 -> V_12 . V_108 = NULL ;
F_8 ( & V_6 -> V_12 . V_67 ) ;
}
