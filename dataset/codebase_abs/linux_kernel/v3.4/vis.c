static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
struct V_6 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 , * V_9 ;
F_3 ( & V_4 -> V_10 ) ;
F_4 ( & V_6 -> V_11 ) ;
F_5 (entry, tmp, &info->recv_list, list) {
F_6 ( & V_8 -> V_12 ) ;
F_7 ( V_8 ) ;
}
F_8 ( & V_6 -> V_11 ) ;
F_9 ( V_4 -> V_13 ) ;
F_7 ( V_4 ) ;
}
static int F_10 ( const struct V_14 * V_15 , const void * V_16 )
{
const struct V_3 * V_17 , * V_18 ;
const struct V_19 * V_20 , * V_21 ;
V_17 = F_2 ( V_15 , struct V_3 , V_22 ) ;
V_18 = V_16 ;
V_20 = (struct V_19 * ) V_17 -> V_13 -> V_23 ;
V_21 = (struct V_19 * ) V_18 -> V_13 -> V_23 ;
return F_11 ( V_20 -> V_24 , V_21 -> V_24 ) ;
}
static T_1 F_12 ( const void * V_23 , T_1 V_25 )
{
const struct V_3 * V_3 = V_23 ;
const struct V_19 * V_26 ;
const unsigned char * V_27 ;
T_1 V_28 = 0 ;
T_2 V_29 ;
V_26 = (struct V_19 * ) V_3 -> V_13 -> V_23 ;
V_27 = V_26 -> V_24 ;
for ( V_29 = 0 ; V_29 < V_30 ; V_29 ++ ) {
V_28 += V_27 [ V_29 ] ;
V_28 += ( V_28 << 10 ) ;
V_28 ^= ( V_28 >> 6 ) ;
}
V_28 += ( V_28 << 3 ) ;
V_28 ^= ( V_28 >> 11 ) ;
V_28 += ( V_28 << 15 ) ;
return V_28 % V_25 ;
}
static struct V_3 * F_13 ( struct V_6 * V_6 ,
const void * V_23 )
{
struct V_31 * V_28 = V_6 -> V_32 ;
struct V_33 * V_34 ;
struct V_14 * V_15 ;
struct V_3 * V_3 , * V_35 = NULL ;
T_1 V_36 ;
if ( ! V_28 )
return NULL ;
V_36 = F_12 ( V_23 , V_28 -> V_25 ) ;
V_34 = & V_28 -> V_37 [ V_36 ] ;
F_14 () ;
F_15 (vis_info, node, head, hash_entry) {
if ( ! F_10 ( V_15 , V_23 ) )
continue;
V_35 = V_3 ;
break;
}
F_16 () ;
return V_35 ;
}
static void F_17 ( const T_3 * V_38 ,
struct V_33 * V_39 ,
bool V_40 )
{
struct V_41 * V_8 ;
struct V_14 * V_42 ;
F_18 (entry, pos, if_list, list) {
if ( F_11 ( V_8 -> V_43 , V_38 ) )
return;
}
V_8 = F_19 ( sizeof( * V_8 ) , V_44 ) ;
if ( ! V_8 )
return;
memcpy ( V_8 -> V_43 , V_38 , V_30 ) ;
V_8 -> V_40 = V_40 ;
F_20 ( & V_8 -> V_12 , V_39 ) ;
}
static T_4 F_21 ( char * V_45 ,
const struct V_33 * V_39 )
{
struct V_41 * V_8 ;
struct V_14 * V_42 ;
T_2 V_46 = 0 ;
F_18 (entry, pos, if_list, list) {
if ( V_8 -> V_40 )
V_46 += sprintf ( V_45 + V_46 , L_1 ) ;
else
V_46 += sprintf ( V_45 + V_46 , L_2 , V_8 -> V_43 ) ;
}
return V_46 ;
}
static T_2 F_22 ( struct V_33 * V_39 )
{
struct V_41 * V_8 ;
struct V_14 * V_42 ;
T_2 V_47 = 0 ;
F_18 (entry, pos, if_list, list) {
if ( V_8 -> V_40 )
V_47 += 9 ;
else
V_47 += 23 ;
}
return V_47 ;
}
static T_4 F_23 ( char * V_45 ,
const struct V_48 * V_8 ,
const T_3 * V_49 , bool V_40 )
{
if ( V_40 && V_8 -> V_50 == 0 )
return sprintf ( V_45 , L_3 , V_8 -> V_51 ) ;
else if ( F_11 ( V_8 -> V_49 , V_49 ) )
return sprintf ( V_45 , L_4 , V_8 -> V_51 ,
V_8 -> V_50 ) ;
return 0 ;
}
int F_24 ( struct V_52 * V_53 , void * V_54 )
{
struct V_55 * V_56 ;
struct V_14 * V_15 ;
struct V_33 * V_34 ;
struct V_3 * V_4 ;
struct V_19 * V_26 ;
struct V_48 * V_57 ;
struct V_58 * V_59 = (struct V_58 * ) V_53 -> V_60 ;
struct V_6 * V_6 = F_25 ( V_59 ) ;
struct V_31 * V_28 = V_6 -> V_32 ;
F_26 ( V_61 ) ;
struct V_41 * V_8 ;
struct V_14 * V_42 , * V_62 ;
T_1 V_29 ;
int V_63 , V_64 = 0 ;
int V_65 = F_27 ( & V_6 -> V_66 ) ;
T_2 V_67 , V_68 ;
char * V_45 ;
int V_69 ;
V_56 = F_28 ( V_6 ) ;
if ( ! V_56 )
goto V_70;
if ( V_65 == V_71 )
goto V_70;
V_68 = 1 ;
F_4 ( & V_6 -> V_72 ) ;
for ( V_29 = 0 ; V_29 < V_28 -> V_25 ; V_29 ++ ) {
V_34 = & V_28 -> V_37 [ V_29 ] ;
F_14 () ;
F_15 (info, node, head, hash_entry) {
V_26 = (struct V_19 * ) V_4 -> V_13 -> V_23 ;
V_57 = (struct V_48 * )
( ( char * ) V_26 + sizeof( * V_26 ) ) ;
for ( V_63 = 0 ; V_63 < V_26 -> V_57 ; V_63 ++ ) {
if ( V_57 [ V_63 ] . V_50 == 0 )
continue;
V_69 =
F_11 ( V_57 [ V_63 ] . V_49 , V_26 -> V_24 ) ;
F_17 ( V_57 [ V_63 ] . V_49 ,
& V_61 ,
V_69 ) ;
}
F_18 (entry, pos, &vis_if_list, list) {
V_68 += 18 + 26 * V_26 -> V_57 ;
if ( F_11 ( V_8 -> V_43 , V_26 -> V_24 ) )
V_68 +=
F_22 ( & V_61 ) ;
V_68 += 1 ;
}
F_29 (entry, pos, n, &vis_if_list,
list) {
F_30 ( & V_8 -> V_12 ) ;
F_7 ( V_8 ) ;
}
}
F_16 () ;
}
V_45 = F_19 ( V_68 , V_44 ) ;
if ( ! V_45 ) {
F_8 ( & V_6 -> V_72 ) ;
V_64 = - V_73 ;
goto V_70;
}
V_45 [ 0 ] = '\0' ;
V_67 = 0 ;
for ( V_29 = 0 ; V_29 < V_28 -> V_25 ; V_29 ++ ) {
V_34 = & V_28 -> V_37 [ V_29 ] ;
F_14 () ;
F_15 (info, node, head, hash_entry) {
V_26 = (struct V_19 * ) V_4 -> V_13 -> V_23 ;
V_57 = (struct V_48 * )
( ( char * ) V_26 + sizeof( * V_26 ) ) ;
for ( V_63 = 0 ; V_63 < V_26 -> V_57 ; V_63 ++ ) {
if ( V_57 [ V_63 ] . V_50 == 0 )
continue;
V_69 =
F_11 ( V_57 [ V_63 ] . V_49 , V_26 -> V_24 ) ;
F_17 ( V_57 [ V_63 ] . V_49 ,
& V_61 ,
V_69 ) ;
}
F_18 (entry, pos, &vis_if_list, list) {
V_67 += sprintf ( V_45 + V_67 , L_5 ,
V_8 -> V_43 ) ;
for ( V_63 = 0 ; V_63 < V_26 -> V_57 ; V_63 ++ )
V_67 += F_23 (
V_45 + V_67 ,
& V_57 [ V_63 ] ,
V_8 -> V_43 ,
V_8 -> V_40 ) ;
if ( F_11 ( V_8 -> V_43 , V_26 -> V_24 ) )
V_67 +=
F_21 ( V_45 + V_67 ,
& V_61 ) ;
V_67 += sprintf ( V_45 + V_67 , L_6 ) ;
}
F_29 (entry, pos, n, &vis_if_list,
list) {
F_30 ( & V_8 -> V_12 ) ;
F_7 ( V_8 ) ;
}
}
F_16 () ;
}
F_8 ( & V_6 -> V_72 ) ;
F_31 ( V_53 , L_7 , V_45 ) ;
F_7 ( V_45 ) ;
V_70:
if ( V_56 )
F_32 ( V_56 ) ;
return V_64 ;
}
static void F_33 ( struct V_6 * V_6 , struct V_3 * V_4 )
{
if ( F_34 ( & V_4 -> V_10 ) ) {
F_35 ( & V_4 -> V_5 ) ;
F_36 ( & V_4 -> V_10 , & V_6 -> V_74 ) ;
}
}
static void F_37 ( struct V_3 * V_4 )
{
if ( ! F_34 ( & V_4 -> V_10 ) ) {
F_3 ( & V_4 -> V_10 ) ;
F_38 ( & V_4 -> V_5 , F_1 ) ;
}
}
static void F_39 ( struct V_6 * V_6 ,
struct V_75 * V_76 , const char * V_77 )
{
struct V_7 * V_8 ;
V_8 = F_19 ( sizeof( * V_8 ) , V_44 ) ;
if ( ! V_8 )
return;
memcpy ( V_8 -> V_77 , V_77 , V_30 ) ;
F_4 ( & V_6 -> V_11 ) ;
F_36 ( & V_8 -> V_12 , V_76 ) ;
F_8 ( & V_6 -> V_11 ) ;
}
static int F_40 ( struct V_6 * V_6 ,
const struct V_75 * V_76 , const char * V_77 )
{
const struct V_7 * V_8 ;
F_4 ( & V_6 -> V_11 ) ;
F_41 (entry, recv_list, list) {
if ( F_11 ( V_8 -> V_77 , V_77 ) ) {
F_8 ( & V_6 -> V_11 ) ;
return 1 ;
}
}
F_8 ( & V_6 -> V_11 ) ;
return 0 ;
}
static struct V_3 * F_42 ( struct V_6 * V_6 ,
struct V_19 * V_19 ,
int V_78 , int * V_79 ,
int V_80 )
{
struct V_3 * V_4 , * V_81 ;
struct V_19 * V_82 , * V_83 ;
struct V_3 V_84 ;
struct V_19 * V_26 ;
int V_85 ;
* V_79 = 0 ;
if ( ! V_6 -> V_32 )
return NULL ;
V_84 . V_13 = F_43 ( sizeof( * V_82 ) ) ;
if ( ! V_84 . V_13 )
return NULL ;
V_82 = (struct V_19 * ) F_44 ( V_84 . V_13 ,
sizeof( * V_82 ) ) ;
memcpy ( V_82 -> V_24 , V_19 -> V_24 , V_30 ) ;
V_81 = F_13 ( V_6 , & V_84 ) ;
F_9 ( V_84 . V_13 ) ;
if ( V_81 ) {
V_83 = (struct V_19 * ) V_81 -> V_13 -> V_23 ;
if ( ! F_45 ( F_46 ( V_19 -> V_86 ) ,
F_46 ( V_83 -> V_86 ) ) ) {
if ( V_83 -> V_86 == V_19 -> V_86 ) {
F_39 ( V_6 , & V_81 -> V_76 ,
V_19 -> V_87 ) ;
return V_81 ;
} else {
return NULL ;
}
}
F_47 ( V_6 -> V_32 , F_10 , F_12 ,
V_81 ) ;
F_37 ( V_81 ) ;
F_38 ( & V_81 -> V_5 , F_1 ) ;
}
V_4 = F_19 ( sizeof( * V_4 ) , V_44 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_13 = F_43 ( sizeof( * V_26 ) + V_78 +
sizeof( struct V_88 ) ) ;
if ( ! V_4 -> V_13 ) {
F_7 ( V_4 ) ;
return NULL ;
}
F_48 ( V_4 -> V_13 , sizeof( struct V_88 ) ) ;
V_26 = (struct V_19 * ) F_44 ( V_4 -> V_13 , sizeof( * V_26 )
+ V_78 ) ;
F_49 ( & V_4 -> V_5 ) ;
F_50 ( & V_4 -> V_10 ) ;
F_50 ( & V_4 -> V_76 ) ;
V_4 -> V_89 = V_90 ;
V_4 -> V_6 = V_6 ;
memcpy ( V_26 , V_19 , sizeof( * V_26 ) + V_78 ) ;
* V_79 = 1 ;
if ( V_80 )
memcpy ( V_26 -> V_91 , V_92 , V_30 ) ;
if ( V_26 -> V_57 * sizeof( struct V_48 ) > V_78 )
V_26 -> V_57 = V_78 / sizeof( struct V_48 ) ;
F_39 ( V_6 , & V_4 -> V_76 , V_26 -> V_87 ) ;
V_85 = F_51 ( V_6 -> V_32 , F_10 , F_12 ,
V_4 , & V_4 -> V_22 ) ;
if ( V_85 != 0 ) {
F_38 ( & V_4 -> V_5 , F_1 ) ;
V_4 = NULL ;
}
return V_4 ;
}
void F_52 ( struct V_6 * V_6 ,
struct V_19 * V_19 ,
int V_78 )
{
struct V_3 * V_4 ;
int V_79 , V_80 ;
int V_65 = F_27 ( & V_6 -> V_66 ) ;
V_80 = ( V_65 == V_93 ) ;
F_4 ( & V_6 -> V_72 ) ;
V_4 = F_42 ( V_6 , V_19 , V_78 ,
& V_79 , V_80 ) ;
if ( ! V_4 )
goto V_94;
if ( V_65 == V_93 && V_79 )
F_33 ( V_6 , V_4 ) ;
V_94:
F_8 ( & V_6 -> V_72 ) ;
}
void F_53 ( struct V_6 * V_6 ,
struct V_19 * V_19 ,
int V_78 )
{
struct V_3 * V_4 ;
struct V_19 * V_26 ;
int V_79 ;
int V_65 = F_27 ( & V_6 -> V_66 ) ;
int V_95 = 0 ;
if ( F_54 ( V_19 -> V_91 ) )
return;
if ( V_65 == V_93 &&
F_55 ( V_19 -> V_91 ) )
V_95 = 1 ;
F_4 ( & V_6 -> V_72 ) ;
V_4 = F_42 ( V_6 , V_19 , V_78 ,
& V_79 , V_95 ) ;
if ( ! V_4 )
goto V_94;
V_26 = (struct V_19 * ) V_4 -> V_13 -> V_23 ;
if ( V_95 && V_79 ) {
V_26 -> V_96 = V_93 ;
F_33 ( V_6 , V_4 ) ;
} else if ( ! F_55 ( V_26 -> V_91 ) ) {
F_33 ( V_6 , V_4 ) ;
}
V_94:
F_8 ( & V_6 -> V_72 ) ;
}
static int F_56 ( struct V_6 * V_6 ,
struct V_3 * V_4 )
{
struct V_31 * V_28 = V_6 -> V_97 ;
struct V_98 * V_99 ;
struct V_14 * V_15 ;
struct V_33 * V_34 ;
struct V_100 * V_100 ;
struct V_19 * V_26 ;
int V_101 = - 1 ;
T_1 V_29 ;
V_26 = (struct V_19 * ) V_4 -> V_13 -> V_23 ;
for ( V_29 = 0 ; V_29 < V_28 -> V_25 ; V_29 ++ ) {
V_34 = & V_28 -> V_37 [ V_29 ] ;
F_14 () ;
F_15 (orig_node, node, head, hash_entry) {
V_99 = F_57 ( V_100 ) ;
if ( ! V_99 )
continue;
if ( ( V_100 -> V_102 & V_103 ) &&
( V_99 -> V_104 > V_101 ) ) {
V_101 = V_99 -> V_104 ;
memcpy ( V_26 -> V_91 , V_100 -> V_105 ,
V_30 ) ;
}
F_58 ( V_99 ) ;
}
F_16 () ;
}
return V_101 ;
}
static bool F_59 ( const struct V_3 * V_4 )
{
const struct V_19 * V_26 ;
V_26 = (struct V_19 * ) V_4 -> V_13 -> V_23 ;
if ( V_106 / sizeof( struct V_48 )
< V_26 -> V_57 + 1 )
return true ;
return false ;
}
static int F_60 ( struct V_6 * V_6 )
{
struct V_31 * V_28 = V_6 -> V_97 ;
struct V_14 * V_15 ;
struct V_33 * V_34 ;
struct V_100 * V_100 ;
struct V_98 * V_99 ;
struct V_3 * V_4 = V_6 -> V_107 ;
struct V_19 * V_26 = (struct V_19 * ) V_4 -> V_13 -> V_23 ;
struct V_48 * V_8 ;
struct V_108 * V_108 ;
int V_101 = - 1 ;
T_1 V_29 ;
V_4 -> V_89 = V_90 ;
V_26 -> V_96 = F_27 ( & V_6 -> V_66 ) ;
memcpy ( V_26 -> V_91 , V_92 , V_30 ) ;
V_26 -> V_109 . V_110 = V_111 ;
V_26 -> V_86 = F_61 ( F_46 ( V_26 -> V_86 ) + 1 ) ;
V_26 -> V_57 = 0 ;
F_62 ( V_4 -> V_13 , sizeof( * V_26 ) ) ;
if ( V_26 -> V_96 == V_71 ) {
V_101 = F_56 ( V_6 , V_4 ) ;
if ( V_101 < 0 )
return - 1 ;
}
for ( V_29 = 0 ; V_29 < V_28 -> V_25 ; V_29 ++ ) {
V_34 = & V_28 -> V_37 [ V_29 ] ;
F_14 () ;
F_15 (orig_node, node, head, hash_entry) {
V_99 = F_57 ( V_100 ) ;
if ( ! V_99 )
continue;
if ( ! F_11 ( V_99 -> V_43 , V_100 -> V_105 ) )
goto V_112;
if ( V_99 -> V_113 -> V_114 != V_115 )
goto V_112;
if ( V_99 -> V_104 < 1 )
goto V_112;
V_8 = (struct V_48 * )
F_44 ( V_4 -> V_13 , sizeof( * V_8 ) ) ;
memcpy ( V_8 -> V_49 ,
V_99 -> V_113 -> V_59 -> V_116 ,
V_30 ) ;
memcpy ( V_8 -> V_51 , V_100 -> V_105 , V_30 ) ;
V_8 -> V_50 = V_99 -> V_104 ;
V_26 -> V_57 ++ ;
V_112:
F_58 ( V_99 ) ;
if ( F_59 ( V_4 ) )
goto V_117;
}
F_16 () ;
}
V_28 = V_6 -> V_118 ;
for ( V_29 = 0 ; V_29 < V_28 -> V_25 ; V_29 ++ ) {
V_34 = & V_28 -> V_37 [ V_29 ] ;
F_14 () ;
F_15 (tt_common_entry, node, head,
hash_entry) {
V_8 = (struct V_48 * )
F_44 ( V_4 -> V_13 ,
sizeof( * V_8 ) ) ;
memset ( V_8 -> V_49 , 0 , V_30 ) ;
memcpy ( V_8 -> V_51 , V_108 -> V_43 , V_30 ) ;
V_8 -> V_50 = 0 ;
V_26 -> V_57 ++ ;
if ( F_59 ( V_4 ) )
goto V_117;
}
F_16 () ;
}
return 0 ;
V_117:
F_16 () ;
return 0 ;
}
static void F_63 ( struct V_6 * V_6 )
{
T_1 V_29 ;
struct V_31 * V_28 = V_6 -> V_32 ;
struct V_14 * V_15 , * V_119 ;
struct V_33 * V_34 ;
struct V_3 * V_4 ;
for ( V_29 = 0 ; V_29 < V_28 -> V_25 ; V_29 ++ ) {
V_34 = & V_28 -> V_37 [ V_29 ] ;
F_29 (info, node, node_tmp,
head, hash_entry) {
if ( V_4 == V_6 -> V_107 )
continue;
if ( F_64 ( V_4 -> V_89 , V_120 ) ) {
F_30 ( V_15 ) ;
F_37 ( V_4 ) ;
F_38 ( & V_4 -> V_5 , F_1 ) ;
}
}
}
}
static void F_65 ( struct V_6 * V_6 ,
struct V_3 * V_4 )
{
struct V_98 * V_99 ;
struct V_31 * V_28 = V_6 -> V_97 ;
struct V_14 * V_15 ;
struct V_33 * V_34 ;
struct V_100 * V_100 ;
struct V_19 * V_26 ;
struct V_121 * V_122 ;
struct V_55 * V_55 ;
T_3 V_123 [ V_30 ] ;
T_1 V_29 ;
V_26 = (struct V_19 * ) V_4 -> V_13 -> V_23 ;
for ( V_29 = 0 ; V_29 < V_28 -> V_25 ; V_29 ++ ) {
V_34 = & V_28 -> V_37 [ V_29 ] ;
F_14 () ;
F_15 (orig_node, node, head, hash_entry) {
if ( ! ( V_100 -> V_102 & V_103 ) )
continue;
V_99 = F_57 ( V_100 ) ;
if ( ! V_99 )
continue;
if ( F_40 ( V_6 , & V_4 -> V_76 ,
V_100 -> V_105 ) ) {
F_58 ( V_99 ) ;
continue;
}
memcpy ( V_26 -> V_91 , V_100 -> V_105 , V_30 ) ;
V_55 = V_99 -> V_113 ;
memcpy ( V_123 , V_99 -> V_43 , V_30 ) ;
F_58 ( V_99 ) ;
V_122 = F_66 ( V_4 -> V_13 , V_44 ) ;
if ( V_122 )
F_67 ( V_122 , V_55 , V_123 ) ;
}
F_16 () ;
}
}
static void F_68 ( struct V_6 * V_6 ,
struct V_3 * V_4 )
{
struct V_100 * V_100 ;
struct V_98 * V_99 = NULL ;
struct V_121 * V_122 ;
struct V_19 * V_26 ;
V_26 = (struct V_19 * ) V_4 -> V_13 -> V_23 ;
V_100 = F_69 ( V_6 , V_26 -> V_91 ) ;
if ( ! V_100 )
goto V_70;
V_99 = F_57 ( V_100 ) ;
if ( ! V_99 )
goto V_70;
V_122 = F_66 ( V_4 -> V_13 , V_44 ) ;
if ( V_122 )
F_67 ( V_122 , V_99 -> V_113 , V_99 -> V_43 ) ;
V_70:
if ( V_99 )
F_58 ( V_99 ) ;
if ( V_100 )
F_70 ( V_100 ) ;
}
static void F_71 ( struct V_6 * V_6 , struct V_3 * V_4 )
{
struct V_55 * V_56 ;
struct V_19 * V_26 ;
V_56 = F_28 ( V_6 ) ;
if ( ! V_56 )
goto V_70;
V_26 = (struct V_19 * ) V_4 -> V_13 -> V_23 ;
if ( V_26 -> V_109 . V_110 < 2 ) {
F_72 ( L_8 ) ;
goto V_70;
}
memcpy ( V_26 -> V_87 , V_56 -> V_59 -> V_116 , V_30 ) ;
V_26 -> V_109 . V_110 -- ;
if ( F_54 ( V_26 -> V_91 ) )
F_65 ( V_6 , V_4 ) ;
else
F_68 ( V_6 , V_4 ) ;
V_26 -> V_109 . V_110 ++ ;
V_70:
if ( V_56 )
F_32 ( V_56 ) ;
}
static void F_73 ( struct V_124 * V_125 )
{
struct V_126 * V_126 =
F_2 ( V_125 , struct V_126 , V_125 ) ;
struct V_6 * V_6 =
F_2 ( V_126 , struct V_6 , V_127 ) ;
struct V_3 * V_4 ;
F_4 ( & V_6 -> V_72 ) ;
F_63 ( V_6 ) ;
if ( F_60 ( V_6 ) == 0 ) {
F_33 ( V_6 , V_6 -> V_107 ) ;
}
while ( ! F_34 ( & V_6 -> V_74 ) ) {
V_4 = F_74 ( & V_6 -> V_74 ,
F_75 ( * V_4 ) , V_10 ) ;
F_35 ( & V_4 -> V_5 ) ;
F_8 ( & V_6 -> V_72 ) ;
F_71 ( V_6 , V_4 ) ;
F_4 ( & V_6 -> V_72 ) ;
F_37 ( V_4 ) ;
F_38 ( & V_4 -> V_5 , F_1 ) ;
}
F_8 ( & V_6 -> V_72 ) ;
F_76 ( V_6 ) ;
}
int F_77 ( struct V_6 * V_6 )
{
struct V_19 * V_26 ;
int V_85 ;
if ( V_6 -> V_32 )
return 1 ;
F_4 ( & V_6 -> V_72 ) ;
V_6 -> V_32 = F_78 ( 256 ) ;
if ( ! V_6 -> V_32 ) {
F_79 ( L_9 ) ;
goto V_128;
}
V_6 -> V_107 = F_19 ( V_106 , V_44 ) ;
if ( ! V_6 -> V_107 )
goto V_128;
V_6 -> V_107 -> V_13 = F_43 ( sizeof( * V_26 ) +
V_106 +
sizeof( struct V_88 ) ) ;
if ( ! V_6 -> V_107 -> V_13 )
goto F_1;
F_48 ( V_6 -> V_107 -> V_13 , sizeof( struct V_88 ) ) ;
V_26 = (struct V_19 * ) F_44 ( V_6 -> V_107 -> V_13 ,
sizeof( * V_26 ) ) ;
V_6 -> V_107 -> V_89 = V_90 -
F_80 ( V_129 ) ;
F_50 ( & V_6 -> V_107 -> V_76 ) ;
F_50 ( & V_6 -> V_107 -> V_10 ) ;
F_49 ( & V_6 -> V_107 -> V_5 ) ;
V_6 -> V_107 -> V_6 = V_6 ;
V_26 -> V_109 . V_130 = V_131 ;
V_26 -> V_109 . V_132 = V_133 ;
V_26 -> V_109 . V_110 = V_111 ;
V_26 -> V_86 = 0 ;
V_26 -> V_57 = 0 ;
F_50 ( & V_6 -> V_74 ) ;
V_85 = F_51 ( V_6 -> V_32 , F_10 , F_12 ,
V_6 -> V_107 ,
& V_6 -> V_107 -> V_22 ) ;
if ( V_85 != 0 ) {
F_79 ( L_10 ) ;
F_38 ( & V_6 -> V_107 -> V_5 , F_1 ) ;
goto V_128;
}
F_8 ( & V_6 -> V_72 ) ;
F_76 ( V_6 ) ;
return 1 ;
F_1:
F_7 ( V_6 -> V_107 ) ;
V_6 -> V_107 = NULL ;
V_128:
F_8 ( & V_6 -> V_72 ) ;
F_81 ( V_6 ) ;
return 0 ;
}
static void F_82 ( struct V_14 * V_15 , void * V_134 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_15 , struct V_3 , V_22 ) ;
F_37 ( V_4 ) ;
F_38 ( & V_4 -> V_5 , F_1 ) ;
}
void F_81 ( struct V_6 * V_6 )
{
if ( ! V_6 -> V_32 )
return;
F_83 ( & V_6 -> V_127 ) ;
F_4 ( & V_6 -> V_72 ) ;
F_84 ( V_6 -> V_32 , F_82 , NULL ) ;
V_6 -> V_32 = NULL ;
V_6 -> V_107 = NULL ;
F_8 ( & V_6 -> V_72 ) ;
}
static void F_76 ( struct V_6 * V_6 )
{
F_85 ( & V_6 -> V_127 , F_73 ) ;
F_86 ( V_135 , & V_6 -> V_127 ,
F_80 ( V_129 ) ) ;
}
