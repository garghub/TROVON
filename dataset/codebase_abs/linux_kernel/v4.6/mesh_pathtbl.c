static inline bool F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 & V_4 ) &&
F_2 ( V_5 , V_2 -> V_6 ) &&
! ( V_2 -> V_3 & V_7 ) ;
}
static inline struct V_8 * F_3 (
struct V_8 T_1 * V_9 )
{
return F_4 ( V_9 ,
F_5 ( & V_10 ) ) ;
}
static inline struct V_8 * F_6 ( void )
{
return F_3 ( V_11 ) ;
}
static inline struct V_8 * F_7 ( void )
{
return F_3 ( V_12 ) ;
}
static struct V_8 * F_8 ( int V_13 )
{
int V_14 ;
struct V_8 * V_15 ;
V_15 = F_9 ( sizeof( struct V_8 ) , V_16 ) ;
if ( ! V_15 )
return NULL ;
V_15 -> V_17 = F_10 ( sizeof( struct V_18 ) *
( 1 << V_13 ) , V_16 ) ;
if ( ! V_15 -> V_17 ) {
F_11 ( V_15 ) ;
return NULL ;
}
V_15 -> V_19 = F_9 ( sizeof( V_20 ) *
( 1 << V_13 ) , V_16 ) ;
if ( ! V_15 -> V_19 ) {
F_11 ( V_15 -> V_17 ) ;
F_11 ( V_15 ) ;
return NULL ;
}
V_15 -> V_13 = V_13 ;
V_15 -> V_21 = ( 1 << V_13 ) - 1 ;
F_12 ( & V_15 -> V_22 , 0 ) ;
F_13 ( & V_15 -> V_23 ,
sizeof( V_15 -> V_23 ) ) ;
for ( V_14 = 0 ; V_14 <= V_15 -> V_21 ; V_14 ++ )
F_14 ( & V_15 -> V_19 [ V_14 ] ) ;
F_14 ( & V_15 -> V_24 ) ;
return V_15 ;
}
static void F_15 ( struct V_8 * V_25 )
{
F_11 ( V_25 -> V_17 ) ;
F_11 ( V_25 -> V_19 ) ;
F_11 ( V_25 ) ;
}
static void F_16 ( struct V_8 * V_25 , bool V_26 )
{
struct V_18 * V_27 ;
struct V_28 * V_29 , * V_30 ;
struct V_31 * V_32 ;
int V_14 ;
V_27 = V_25 -> V_17 ;
for ( V_14 = 0 ; V_14 <= V_25 -> V_21 ; V_14 ++ ) {
F_17 ( & V_25 -> V_19 [ V_14 ] ) ;
F_18 (p, q, &mesh_hash[i]) {
V_25 -> V_33 ( V_29 , V_26 ) ;
F_19 ( & V_25 -> V_22 ) ;
}
F_20 ( & V_25 -> V_19 [ V_14 ] ) ;
}
if ( V_26 ) {
F_17 ( & V_25 -> V_24 ) ;
F_21 (gate, q,
tbl->known_gates, list) {
F_22 ( & V_32 -> V_34 ) ;
F_11 ( V_32 ) ;
}
F_11 ( V_25 -> V_35 ) ;
F_20 ( & V_25 -> V_24 ) ;
}
F_15 ( V_25 ) ;
}
static int F_23 ( struct V_8 * V_36 ,
struct V_8 * V_15 )
{
struct V_18 * V_37 ;
struct V_28 * V_29 , * V_30 ;
int V_14 ;
if ( F_24 ( & V_36 -> V_22 )
< V_38 * ( V_36 -> V_21 + 1 ) )
return - V_39 ;
V_15 -> V_33 = V_36 -> V_33 ;
V_15 -> V_40 = V_36 -> V_40 ;
V_15 -> V_35 = V_36 -> V_35 ;
F_12 ( & V_15 -> V_22 , F_24 ( & V_36 -> V_22 ) ) ;
V_37 = V_36 -> V_17 ;
for ( V_14 = 0 ; V_14 <= V_36 -> V_21 ; V_14 ++ )
F_25 (p, &oldhash[i])
if ( V_36 -> V_40 ( V_29 , V_15 ) < 0 )
goto V_41;
return 0 ;
V_41:
for ( V_14 = 0 ; V_14 <= V_15 -> V_21 ; V_14 ++ ) {
F_18 (p, q, &newtbl->hash_buckets[i])
V_36 -> V_33 ( V_29 , 0 ) ;
}
return - V_42 ;
}
static T_2 F_26 ( const T_3 * V_43 , struct V_44 * V_45 ,
struct V_8 * V_25 )
{
return F_27 ( * ( T_2 * ) ( V_43 + 2 ) , V_45 -> V_46 -> V_47 ,
V_25 -> V_23 ) & V_25 -> V_21 ;
}
void F_28 ( struct V_1 * V_2 , struct V_48 * V_49 )
{
struct V_50 * V_51 ;
struct V_52 * V_53 ;
unsigned long V_3 ;
F_29 ( V_2 -> V_54 , V_49 ) ;
F_30 ( & V_2 -> V_55 . V_56 , V_3 ) ;
F_31 (&mpath->frame_queue, skb) {
V_53 = (struct V_52 * ) V_51 -> V_57 ;
memcpy ( V_53 -> V_58 , V_49 -> V_49 . V_43 , V_59 ) ;
memcpy ( V_53 -> V_60 , V_2 -> V_45 -> V_61 . V_43 , V_59 ) ;
F_32 ( V_49 -> V_45 , V_49 , V_53 ) ;
}
F_33 ( & V_2 -> V_55 . V_56 , V_3 ) ;
}
static void F_34 ( struct V_50 * V_51 , char * V_62 ,
struct V_1 * V_63 )
{
struct V_52 * V_53 ;
struct V_64 * V_65 ;
int V_66 , V_67 ;
char * V_54 ;
V_53 = (struct V_52 * ) V_51 -> V_57 ;
V_67 = F_35 ( V_53 -> V_68 ) ;
V_65 = (struct V_64 * ) ( V_51 -> V_57 + V_67 ) ;
if ( ! ( V_65 -> V_3 & V_69 ) ) {
V_66 = 6 ;
F_36 ( V_51 , 2 * V_59 ) ;
memmove ( V_51 -> V_57 , V_53 , V_67 + V_66 ) ;
V_53 = (struct V_52 * ) V_51 -> V_57 ;
V_65 = (struct V_64 * ) ( V_51 -> V_57 + V_67 ) ;
V_65 -> V_3 = V_70 ;
memcpy ( V_65 -> V_71 , V_53 -> V_72 , V_59 ) ;
memcpy ( V_65 -> V_73 , V_53 -> V_74 , V_59 ) ;
}
V_53 = (struct V_52 * ) V_51 -> V_57 ;
F_37 () ;
V_54 = F_38 ( V_63 -> V_54 ) -> V_49 . V_43 ;
memcpy ( V_53 -> V_58 , V_54 , V_59 ) ;
F_39 () ;
memcpy ( V_53 -> V_60 , V_63 -> V_45 -> V_61 . V_43 , V_59 ) ;
memcpy ( V_53 -> V_72 , V_62 , V_59 ) ;
}
static void F_40 ( struct V_1 * V_63 ,
struct V_1 * V_75 ,
bool V_76 )
{
struct V_50 * V_51 , * V_77 , * V_78 ;
struct V_79 V_80 ;
unsigned long V_3 ;
if ( F_41 ( V_63 == V_75 ) )
return;
if ( F_41 ( ! V_63 -> V_54 ) )
return;
F_42 ( & V_80 ) ;
F_30 ( & V_75 -> V_55 . V_56 , V_3 ) ;
F_43 ( & V_75 -> V_55 , & V_80 ) ;
F_33 ( & V_75 -> V_55 . V_56 , V_3 ) ;
F_44 (&failq, fskb, tmp) {
if ( F_45 ( & V_63 -> V_55 ) >=
V_81 ) {
F_46 ( V_63 -> V_45 , L_1 ) ;
break;
}
V_51 = F_47 ( V_77 , V_16 ) ;
if ( F_41 ( ! V_51 ) )
break;
F_34 ( V_51 , V_63 -> V_82 , V_63 ) ;
F_48 ( & V_63 -> V_55 , V_51 ) ;
if ( V_76 )
continue;
F_49 ( V_77 , & V_80 ) ;
F_50 ( V_77 ) ;
}
F_46 ( V_63 -> V_45 , L_2 ,
V_63 -> V_82 , F_45 ( & V_63 -> V_55 ) ) ;
if ( ! V_76 )
return;
F_30 ( & V_75 -> V_55 . V_56 , V_3 ) ;
F_51 ( & V_80 , & V_75 -> V_55 ) ;
F_33 ( & V_75 -> V_55 . V_56 , V_3 ) ;
}
static struct V_1 * F_52 ( struct V_8 * V_25 , const T_3 * V_82 ,
struct V_44 * V_45 )
{
struct V_1 * V_2 ;
struct V_18 * V_83 ;
struct V_31 * V_84 ;
V_83 = & V_25 -> V_17 [ F_26 ( V_82 , V_45 , V_25 ) ] ;
F_53 (node, bucket, list) {
V_2 = V_84 -> V_2 ;
if ( V_2 -> V_45 == V_45 &&
F_54 ( V_82 , V_2 -> V_82 ) ) {
if ( F_1 ( V_2 ) ) {
F_17 ( & V_2 -> V_85 ) ;
V_2 -> V_3 &= ~ V_4 ;
F_20 ( & V_2 -> V_85 ) ;
}
return V_2 ;
}
}
return NULL ;
}
struct V_1 *
F_55 ( struct V_44 * V_45 , const T_3 * V_82 )
{
return F_52 ( F_38 ( V_11 ) , V_82 , V_45 ) ;
}
struct V_1 *
F_56 ( struct V_44 * V_45 , const T_3 * V_82 )
{
return F_52 ( F_38 ( V_12 ) , V_82 , V_45 ) ;
}
struct V_1 *
F_57 ( struct V_44 * V_45 , int V_86 )
{
struct V_8 * V_25 = F_38 ( V_11 ) ;
struct V_31 * V_84 ;
int V_14 ;
int V_87 = 0 ;
F_58 (tbl, node, i) {
if ( V_45 && V_84 -> V_2 -> V_45 != V_45 )
continue;
if ( V_87 ++ == V_86 ) {
if ( F_1 ( V_84 -> V_2 ) ) {
F_17 ( & V_84 -> V_2 -> V_85 ) ;
V_84 -> V_2 -> V_3 &= ~ V_4 ;
F_20 ( & V_84 -> V_2 -> V_85 ) ;
}
return V_84 -> V_2 ;
}
}
return NULL ;
}
struct V_1 *
F_59 ( struct V_44 * V_45 , int V_86 )
{
struct V_8 * V_25 = F_38 ( V_12 ) ;
struct V_31 * V_84 ;
int V_14 ;
int V_87 = 0 ;
F_58 (tbl, node, i) {
if ( V_45 && V_84 -> V_2 -> V_45 != V_45 )
continue;
if ( V_87 ++ == V_86 )
return V_84 -> V_2 ;
}
return NULL ;
}
int F_60 ( struct V_1 * V_2 )
{
struct V_8 * V_25 ;
struct V_31 * V_32 , * V_88 ;
int V_89 ;
F_37 () ;
V_25 = F_38 ( V_11 ) ;
F_53 (gate, tbl->known_gates, list)
if ( V_32 -> V_2 == V_2 ) {
V_89 = - V_90 ;
goto V_91;
}
V_88 = F_10 ( sizeof( struct V_31 ) , V_16 ) ;
if ( ! V_88 ) {
V_89 = - V_42 ;
goto V_91;
}
V_2 -> V_92 = true ;
V_2 -> V_45 -> V_93 . V_94 . V_95 ++ ;
V_88 -> V_2 = V_2 ;
F_17 ( & V_25 -> V_24 ) ;
F_61 ( & V_88 -> V_34 , V_25 -> V_35 ) ;
F_20 ( & V_25 -> V_24 ) ;
F_46 ( V_2 -> V_45 ,
L_3 ,
V_2 -> V_82 , V_2 -> V_45 -> V_93 . V_94 . V_95 ) ;
V_89 = 0 ;
V_91:
F_39 () ;
return V_89 ;
}
static void F_62 ( struct V_8 * V_25 , struct V_1 * V_2 )
{
struct V_31 * V_32 ;
struct V_28 * V_30 ;
F_21 (gate, q, tbl->known_gates, list) {
if ( V_32 -> V_2 != V_2 )
continue;
F_17 ( & V_25 -> V_24 ) ;
F_63 ( & V_32 -> V_34 ) ;
F_64 ( V_32 , V_96 ) ;
F_20 ( & V_25 -> V_24 ) ;
V_2 -> V_45 -> V_93 . V_94 . V_95 -- ;
V_2 -> V_92 = false ;
F_46 ( V_2 -> V_45 ,
L_4 ,
V_2 -> V_82 , V_2 -> V_45 -> V_93 . V_94 . V_95 ) ;
break;
}
}
int F_65 ( struct V_44 * V_45 )
{
return V_45 -> V_93 . V_94 . V_95 ;
}
struct V_1 * F_66 ( struct V_44 * V_45 ,
const T_3 * V_82 )
{
struct V_97 * V_98 = & V_45 -> V_93 . V_94 ;
struct V_99 * V_100 = V_45 -> V_100 ;
struct V_8 * V_25 ;
struct V_1 * V_2 , * V_101 ;
struct V_31 * V_84 , * V_102 ;
struct V_18 * V_83 ;
int V_103 = 0 ;
int V_89 ;
T_2 V_104 ;
if ( F_54 ( V_82 , V_45 -> V_61 . V_43 ) )
return F_67 ( - V_105 ) ;
if ( F_68 ( V_82 ) )
return F_67 ( - V_105 ) ;
if ( F_69 ( & V_45 -> V_93 . V_94 . V_106 , 1 , V_107 ) == 0 )
return F_67 ( - V_108 ) ;
F_70 ( & V_10 ) ;
V_25 = F_6 () ;
V_104 = F_26 ( V_82 , V_45 , V_25 ) ;
V_83 = & V_25 -> V_17 [ V_104 ] ;
F_71 ( & V_25 -> V_19 [ V_104 ] ) ;
F_72 (node, bucket, list) {
V_2 = V_84 -> V_2 ;
if ( V_2 -> V_45 == V_45 &&
F_54 ( V_82 , V_2 -> V_82 ) )
goto V_109;
}
V_89 = - V_42 ;
V_101 = F_10 ( sizeof( struct V_1 ) , V_16 ) ;
if ( ! V_101 )
goto V_110;
V_102 = F_9 ( sizeof( struct V_31 ) , V_16 ) ;
if ( ! V_102 )
goto V_111;
memcpy ( V_101 -> V_82 , V_82 , V_59 ) ;
F_73 ( V_101 -> V_112 ) ;
V_101 -> V_113 = false ;
V_101 -> V_45 = V_45 ;
V_101 -> V_3 = 0 ;
F_74 ( & V_101 -> V_55 ) ;
V_102 -> V_2 = V_101 ;
V_101 -> V_114 . V_57 = ( unsigned long ) V_101 ;
V_101 -> V_114 . V_115 = V_116 ;
V_101 -> V_6 = V_5 ;
F_14 ( & V_101 -> V_85 ) ;
F_75 ( & V_101 -> V_114 ) ;
F_61 ( & V_102 -> V_34 , V_83 ) ;
if ( F_76 ( & V_25 -> V_22 ) >=
V_38 * ( V_25 -> V_21 + 1 ) )
V_103 = 1 ;
V_117 ++ ;
if ( V_103 ) {
F_77 ( V_118 , & V_98 -> V_119 ) ;
F_78 ( & V_100 -> V_120 , & V_45 -> V_121 ) ;
}
V_2 = V_101 ;
V_109:
F_79 ( & V_25 -> V_19 [ V_104 ] ) ;
F_80 ( & V_10 ) ;
return V_2 ;
V_111:
F_11 ( V_101 ) ;
V_110:
F_19 ( & V_45 -> V_93 . V_94 . V_106 ) ;
F_79 ( & V_25 -> V_19 [ V_104 ] ) ;
F_80 ( & V_10 ) ;
return F_67 ( V_89 ) ;
}
static void F_81 ( struct V_122 * V_96 )
{
struct V_8 * V_25 = F_82 ( V_96 , struct V_8 , V_122 ) ;
F_16 ( V_25 , false ) ;
}
void F_83 ( void )
{
struct V_8 * V_36 , * V_15 ;
F_84 ( & V_10 ) ;
V_36 = F_6 () ;
V_15 = F_8 ( V_36 -> V_13 + 1 ) ;
if ( ! V_15 )
goto V_123;
if ( F_23 ( V_36 , V_15 ) < 0 ) {
F_15 ( V_15 ) ;
goto V_123;
}
F_29 ( V_11 , V_15 ) ;
F_85 ( & V_36 -> V_122 , F_81 ) ;
V_123:
F_86 ( & V_10 ) ;
}
void F_87 ( void )
{
struct V_8 * V_36 , * V_15 ;
F_84 ( & V_10 ) ;
V_36 = F_7 () ;
V_15 = F_8 ( V_36 -> V_13 + 1 ) ;
if ( ! V_15 )
goto V_123;
if ( F_23 ( V_36 , V_15 ) < 0 ) {
F_15 ( V_15 ) ;
goto V_123;
}
F_29 ( V_12 , V_15 ) ;
F_85 ( & V_36 -> V_122 , F_81 ) ;
V_123:
F_86 ( & V_10 ) ;
}
int F_88 ( struct V_44 * V_45 ,
const T_3 * V_82 , const T_3 * V_124 )
{
struct V_97 * V_98 = & V_45 -> V_93 . V_94 ;
struct V_99 * V_100 = V_45 -> V_100 ;
struct V_8 * V_25 ;
struct V_1 * V_2 , * V_101 ;
struct V_31 * V_84 , * V_102 ;
struct V_18 * V_83 ;
int V_103 = 0 ;
int V_89 = 0 ;
T_2 V_104 ;
if ( F_54 ( V_82 , V_45 -> V_61 . V_43 ) )
return - V_105 ;
if ( F_68 ( V_82 ) )
return - V_105 ;
V_89 = - V_42 ;
V_101 = F_10 ( sizeof( struct V_1 ) , V_16 ) ;
if ( ! V_101 )
goto V_110;
V_102 = F_9 ( sizeof( struct V_31 ) , V_16 ) ;
if ( ! V_102 )
goto V_111;
F_70 ( & V_10 ) ;
memcpy ( V_101 -> V_82 , V_82 , V_59 ) ;
memcpy ( V_101 -> V_124 , V_124 , V_59 ) ;
V_101 -> V_45 = V_45 ;
V_101 -> V_3 = 0 ;
F_74 ( & V_101 -> V_55 ) ;
V_102 -> V_2 = V_101 ;
F_75 ( & V_101 -> V_114 ) ;
V_101 -> V_6 = V_5 ;
F_14 ( & V_101 -> V_85 ) ;
V_25 = F_7 () ;
V_104 = F_26 ( V_82 , V_45 , V_25 ) ;
V_83 = & V_25 -> V_17 [ V_104 ] ;
F_71 ( & V_25 -> V_19 [ V_104 ] ) ;
V_89 = - V_90 ;
F_72 (node, bucket, list) {
V_2 = V_84 -> V_2 ;
if ( V_2 -> V_45 == V_45 &&
F_54 ( V_82 , V_2 -> V_82 ) )
goto V_125;
}
F_61 ( & V_102 -> V_34 , V_83 ) ;
if ( F_76 ( & V_25 -> V_22 ) >=
V_38 * ( V_25 -> V_21 + 1 ) )
V_103 = 1 ;
F_79 ( & V_25 -> V_19 [ V_104 ] ) ;
F_80 ( & V_10 ) ;
V_126 ++ ;
if ( V_103 ) {
F_77 ( V_127 , & V_98 -> V_119 ) ;
F_78 ( & V_100 -> V_120 , & V_45 -> V_121 ) ;
}
return 0 ;
V_125:
F_79 ( & V_25 -> V_19 [ V_104 ] ) ;
F_80 ( & V_10 ) ;
F_11 ( V_102 ) ;
V_111:
F_11 ( V_101 ) ;
V_110:
return V_89 ;
}
void F_89 ( struct V_48 * V_49 )
{
struct V_8 * V_25 ;
static const T_3 V_128 [ V_59 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
struct V_1 * V_2 ;
struct V_31 * V_84 ;
struct V_44 * V_45 = V_49 -> V_45 ;
int V_14 ;
F_37 () ;
V_25 = F_38 ( V_11 ) ;
F_58 (tbl, node, i) {
V_2 = V_84 -> V_2 ;
if ( F_90 ( V_2 -> V_54 ) == V_49 &&
V_2 -> V_3 & V_4 &&
! ( V_2 -> V_3 & V_7 ) ) {
F_17 ( & V_2 -> V_85 ) ;
V_2 -> V_3 &= ~ V_4 ;
++ V_2 -> V_129 ;
F_20 ( & V_2 -> V_85 ) ;
F_91 ( V_45 ,
V_45 -> V_93 . V_94 . V_130 . V_131 ,
V_2 -> V_82 , V_2 -> V_129 ,
V_132 , V_128 ) ;
}
}
F_39 () ;
}
static void F_92 ( struct V_122 * V_133 )
{
struct V_31 * V_84 = F_82 ( V_133 , struct V_31 , V_96 ) ;
F_93 ( & V_84 -> V_2 -> V_114 ) ;
F_11 ( V_84 -> V_2 ) ;
F_11 ( V_84 ) ;
}
static void F_94 ( struct V_8 * V_25 , struct V_31 * V_84 )
{
struct V_1 * V_2 = V_84 -> V_2 ;
struct V_44 * V_45 = V_84 -> V_2 -> V_45 ;
F_71 ( & V_2 -> V_85 ) ;
V_2 -> V_3 |= V_134 ;
if ( V_2 -> V_92 )
F_62 ( V_25 , V_2 ) ;
F_63 ( & V_84 -> V_34 ) ;
F_85 ( & V_84 -> V_96 , F_92 ) ;
F_79 ( & V_2 -> V_85 ) ;
F_19 ( & V_45 -> V_93 . V_94 . V_106 ) ;
F_19 ( & V_25 -> V_22 ) ;
}
void F_95 ( struct V_48 * V_49 )
{
struct V_8 * V_25 ;
struct V_1 * V_2 ;
struct V_31 * V_84 ;
int V_14 ;
F_37 () ;
F_70 ( & V_10 ) ;
V_25 = F_6 () ;
F_58 (tbl, node, i) {
V_2 = V_84 -> V_2 ;
if ( F_90 ( V_2 -> V_54 ) == V_49 ) {
F_71 ( & V_25 -> V_19 [ V_14 ] ) ;
F_94 ( V_25 , V_84 ) ;
F_79 ( & V_25 -> V_19 [ V_14 ] ) ;
}
}
F_80 ( & V_10 ) ;
F_39 () ;
}
static void F_96 ( struct V_44 * V_45 ,
const T_3 * V_135 )
{
struct V_8 * V_25 ;
struct V_1 * V_124 ;
struct V_31 * V_84 ;
int V_14 ;
F_37 () ;
F_70 ( & V_10 ) ;
V_25 = F_7 () ;
F_58 (tbl, node, i) {
V_124 = V_84 -> V_2 ;
if ( F_54 ( V_124 -> V_124 , V_135 ) ) {
F_71 ( & V_25 -> V_19 [ V_14 ] ) ;
F_94 ( V_25 , V_84 ) ;
F_79 ( & V_25 -> V_19 [ V_14 ] ) ;
}
}
F_80 ( & V_10 ) ;
F_39 () ;
}
static void F_97 ( struct V_8 * V_25 ,
struct V_44 * V_45 )
{
struct V_1 * V_2 ;
struct V_31 * V_84 ;
int V_14 ;
F_41 ( ! F_98 () ) ;
F_58 (tbl, node, i) {
V_2 = V_84 -> V_2 ;
if ( V_2 -> V_45 != V_45 )
continue;
F_17 ( & V_25 -> V_19 [ V_14 ] ) ;
F_94 ( V_25 , V_84 ) ;
F_20 ( & V_25 -> V_19 [ V_14 ] ) ;
}
}
void F_99 ( struct V_44 * V_45 )
{
struct V_8 * V_25 ;
F_37 () ;
F_70 ( & V_10 ) ;
V_25 = F_6 () ;
F_97 ( V_25 , V_45 ) ;
V_25 = F_7 () ;
F_97 ( V_25 , V_45 ) ;
F_80 ( & V_10 ) ;
F_39 () ;
}
static int F_100 ( struct V_8 T_1 * V_136 ,
struct V_44 * V_45 ,
const T_3 * V_43 )
{
struct V_8 * V_25 ;
struct V_1 * V_2 ;
struct V_31 * V_84 ;
struct V_18 * V_83 ;
int V_104 ;
int V_89 = 0 ;
V_25 = F_3 ( V_136 ) ;
V_104 = F_26 ( V_43 , V_45 , V_25 ) ;
V_83 = & V_25 -> V_17 [ V_104 ] ;
F_71 ( & V_25 -> V_19 [ V_104 ] ) ;
F_72 (node, bucket, list) {
V_2 = V_84 -> V_2 ;
if ( V_2 -> V_45 == V_45 &&
F_54 ( V_43 , V_2 -> V_82 ) ) {
F_94 ( V_25 , V_84 ) ;
goto V_137;
}
}
V_89 = - V_138 ;
V_137:
F_79 ( & V_25 -> V_19 [ V_104 ] ) ;
return V_89 ;
}
int F_101 ( struct V_44 * V_45 , const T_3 * V_43 )
{
int V_89 = 0 ;
F_96 ( V_45 , V_43 ) ;
F_70 ( & V_10 ) ;
V_89 = F_100 ( V_11 , V_45 , V_43 ) ;
V_117 ++ ;
F_80 ( & V_10 ) ;
return V_89 ;
}
static int F_102 ( struct V_44 * V_45 , const T_3 * V_43 )
{
int V_89 = 0 ;
F_70 ( & V_10 ) ;
V_89 = F_100 ( V_12 , V_45 , V_43 ) ;
V_126 ++ ;
F_80 ( & V_10 ) ;
return V_89 ;
}
void F_103 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 & V_4 )
F_104 ( V_2 -> V_45 -> V_100 ,
& V_2 -> V_55 ) ;
}
int F_105 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_45 ;
struct V_8 * V_25 ;
struct V_1 * V_75 = V_2 ;
struct V_31 * V_32 = NULL ;
bool V_76 = false ;
struct V_18 * V_35 ;
F_37 () ;
V_25 = F_38 ( V_11 ) ;
V_35 = V_25 -> V_35 ;
F_39 () ;
if ( ! V_35 )
return - V_139 ;
F_53 (gate, known_gates, list) {
if ( V_32 -> V_2 -> V_45 != V_45 )
continue;
if ( V_32 -> V_2 -> V_3 & V_4 ) {
F_46 ( V_45 , L_5 , V_32 -> V_2 -> V_82 ) ;
F_40 ( V_32 -> V_2 , V_75 , V_76 ) ;
V_75 = V_32 -> V_2 ;
V_76 = true ;
} else {
F_46 ( V_45 ,
L_6 ,
V_32 -> V_2 -> V_82 , V_32 -> V_2 -> V_3 ) ;
}
}
F_53 (gate, known_gates, list)
if ( V_32 -> V_2 -> V_45 == V_45 ) {
F_46 ( V_45 , L_7 , V_32 -> V_2 -> V_82 ) ;
F_103 ( V_32 -> V_2 ) ;
}
return ( V_75 == V_2 ) ? - V_139 : 0 ;
}
void F_106 ( struct V_44 * V_45 ,
struct V_50 * V_51 )
{
F_50 ( V_51 ) ;
V_45 -> V_93 . V_94 . V_140 . V_141 ++ ;
}
void F_107 ( struct V_1 * V_2 )
{
struct V_50 * V_51 ;
while ( ( V_51 = F_108 ( & V_2 -> V_55 ) ) != NULL )
F_106 ( V_2 -> V_45 , V_51 ) ;
}
void F_109 ( struct V_1 * V_2 , struct V_48 * V_54 )
{
F_17 ( & V_2 -> V_85 ) ;
F_28 ( V_2 , V_54 ) ;
V_2 -> V_129 = 0xffff ;
V_2 -> V_142 = 0 ;
V_2 -> V_143 = 0 ;
V_2 -> V_6 = 0 ;
V_2 -> V_3 |= V_7 ;
F_110 ( V_2 ) ;
F_20 ( & V_2 -> V_85 ) ;
F_103 ( V_2 ) ;
}
static void F_111 ( struct V_28 * V_29 , bool V_26 )
{
struct V_1 * V_2 ;
struct V_31 * V_84 = F_112 ( V_29 , struct V_31 , V_34 ) ;
V_2 = V_84 -> V_2 ;
F_63 ( V_29 ) ;
if ( V_26 ) {
F_93 ( & V_2 -> V_114 ) ;
F_11 ( V_2 ) ;
}
F_11 ( V_84 ) ;
}
static int F_113 ( struct V_28 * V_29 , struct V_8 * V_15 )
{
struct V_1 * V_2 ;
struct V_31 * V_84 , * V_102 ;
T_2 V_104 ;
V_102 = F_9 ( sizeof( struct V_31 ) , V_16 ) ;
if ( V_102 == NULL )
return - V_42 ;
V_84 = F_112 ( V_29 , struct V_31 , V_34 ) ;
V_2 = V_84 -> V_2 ;
V_102 -> V_2 = V_2 ;
V_104 = F_26 ( V_2 -> V_82 , V_2 -> V_45 , V_15 ) ;
F_114 ( & V_102 -> V_34 ,
& V_15 -> V_17 [ V_104 ] ) ;
return 0 ;
}
int F_115 ( void )
{
struct V_8 * V_144 , * V_145 ;
int V_146 ;
V_144 = F_8 ( V_147 ) ;
if ( ! V_144 )
return - V_42 ;
V_144 -> V_33 = & F_111 ;
V_144 -> V_40 = & F_113 ;
V_144 -> V_35 = F_10 ( sizeof( struct V_18 ) , V_16 ) ;
if ( ! V_144 -> V_35 ) {
V_146 = - V_42 ;
goto V_148;
}
F_116 ( V_144 -> V_35 ) ;
V_145 = F_8 ( V_147 ) ;
if ( ! V_145 ) {
V_146 = - V_42 ;
goto V_148;
}
V_145 -> V_33 = & F_111 ;
V_145 -> V_40 = & F_113 ;
V_145 -> V_35 = F_10 ( sizeof( struct V_18 ) , V_16 ) ;
if ( ! V_145 -> V_35 ) {
V_146 = - V_42 ;
goto V_149;
}
F_116 ( V_145 -> V_35 ) ;
F_117 ( V_11 , V_144 ) ;
F_117 ( V_12 , V_145 ) ;
return 0 ;
V_149:
F_16 ( V_145 , true ) ;
V_148:
F_16 ( V_144 , true ) ;
return V_146 ;
}
void F_118 ( struct V_44 * V_45 )
{
struct V_8 * V_25 ;
struct V_1 * V_2 ;
struct V_31 * V_84 ;
int V_14 ;
F_37 () ;
V_25 = F_38 ( V_11 ) ;
F_58 (tbl, node, i) {
if ( V_84 -> V_2 -> V_45 != V_45 )
continue;
V_2 = V_84 -> V_2 ;
if ( ( ! ( V_2 -> V_3 & V_134 ) ) &&
( ! ( V_2 -> V_3 & V_7 ) ) &&
F_2 ( V_5 , V_2 -> V_6 + V_150 ) )
F_101 ( V_2 -> V_45 , V_2 -> V_82 ) ;
}
V_25 = F_38 ( V_12 ) ;
F_58 (tbl, node, i) {
if ( V_84 -> V_2 -> V_45 != V_45 )
continue;
V_2 = V_84 -> V_2 ;
if ( ( ! ( V_2 -> V_3 & V_7 ) ) &&
F_2 ( V_5 , V_2 -> V_6 + V_150 ) )
F_102 ( V_2 -> V_45 , V_2 -> V_82 ) ;
}
F_39 () ;
}
void F_119 ( void )
{
F_16 ( F_4 ( V_11 , 1 ) , true ) ;
F_16 ( F_4 ( V_12 , 1 ) , true ) ;
}
