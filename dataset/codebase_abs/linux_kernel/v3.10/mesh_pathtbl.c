static inline bool F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 & V_4 ) &&
F_2 ( V_5 , V_2 -> V_6 ) &&
! ( V_2 -> V_3 & V_7 ) ;
}
static inline struct V_8 * F_3 ( void )
{
return F_4 ( V_9 ,
F_5 ( & V_10 ) ) ;
}
static inline struct V_8 * F_6 ( void )
{
return F_4 ( V_11 ,
F_5 ( & V_10 ) ) ;
}
static struct V_8 * F_7 ( int V_12 )
{
int V_13 ;
struct V_8 * V_14 ;
V_14 = F_8 ( sizeof( struct V_8 ) , V_15 ) ;
if ( ! V_14 )
return NULL ;
V_14 -> V_16 = F_9 ( sizeof( struct V_17 ) *
( 1 << V_12 ) , V_15 ) ;
if ( ! V_14 -> V_16 ) {
F_10 ( V_14 ) ;
return NULL ;
}
V_14 -> V_18 = F_8 ( sizeof( V_19 ) *
( 1 << V_12 ) , V_15 ) ;
if ( ! V_14 -> V_18 ) {
F_10 ( V_14 -> V_16 ) ;
F_10 ( V_14 ) ;
return NULL ;
}
V_14 -> V_12 = V_12 ;
V_14 -> V_20 = ( 1 << V_12 ) - 1 ;
F_11 ( & V_14 -> V_21 , 0 ) ;
F_12 ( & V_14 -> V_22 ,
sizeof( V_14 -> V_22 ) ) ;
for ( V_13 = 0 ; V_13 <= V_14 -> V_20 ; V_13 ++ )
F_13 ( & V_14 -> V_18 [ V_13 ] ) ;
F_13 ( & V_14 -> V_23 ) ;
return V_14 ;
}
static void F_14 ( struct V_8 * V_24 )
{
F_10 ( V_24 -> V_16 ) ;
F_10 ( V_24 -> V_18 ) ;
F_10 ( V_24 ) ;
}
static void F_15 ( struct V_8 * V_24 , bool V_25 )
{
struct V_17 * V_26 ;
struct V_27 * V_28 , * V_29 ;
struct V_30 * V_31 ;
int V_13 ;
V_26 = V_24 -> V_16 ;
for ( V_13 = 0 ; V_13 <= V_24 -> V_20 ; V_13 ++ ) {
F_16 ( & V_24 -> V_18 [ V_13 ] ) ;
F_17 (p, q, &mesh_hash[i]) {
V_24 -> V_32 ( V_28 , V_25 ) ;
F_18 ( & V_24 -> V_21 ) ;
}
F_19 ( & V_24 -> V_18 [ V_13 ] ) ;
}
if ( V_25 ) {
F_16 ( & V_24 -> V_23 ) ;
F_20 (gate, q,
tbl->known_gates, list) {
F_21 ( & V_31 -> V_33 ) ;
F_10 ( V_31 ) ;
}
F_10 ( V_24 -> V_34 ) ;
F_19 ( & V_24 -> V_23 ) ;
}
F_14 ( V_24 ) ;
}
static int F_22 ( struct V_8 * V_35 ,
struct V_8 * V_14 )
{
struct V_17 * V_36 ;
struct V_27 * V_28 , * V_29 ;
int V_13 ;
if ( F_23 ( & V_35 -> V_21 )
< V_35 -> V_37 * ( V_35 -> V_20 + 1 ) )
return - V_38 ;
V_14 -> V_32 = V_35 -> V_32 ;
V_14 -> V_37 = V_35 -> V_37 ;
V_14 -> V_39 = V_35 -> V_39 ;
V_14 -> V_34 = V_35 -> V_34 ;
F_11 ( & V_14 -> V_21 , F_23 ( & V_35 -> V_21 ) ) ;
V_36 = V_35 -> V_16 ;
for ( V_13 = 0 ; V_13 <= V_35 -> V_20 ; V_13 ++ )
F_24 (p, &oldhash[i])
if ( V_35 -> V_39 ( V_28 , V_14 ) < 0 )
goto V_40;
return 0 ;
V_40:
for ( V_13 = 0 ; V_13 <= V_14 -> V_20 ; V_13 ++ ) {
F_17 (p, q, &newtbl->hash_buckets[i])
V_35 -> V_32 ( V_28 , 0 ) ;
}
return - V_41 ;
}
static T_1 F_25 ( const T_2 * V_42 , struct V_43 * V_44 ,
struct V_8 * V_24 )
{
return F_26 ( * ( T_1 * ) ( V_42 + 2 ) , V_44 -> V_45 -> V_46 ,
V_24 -> V_22 ) & V_24 -> V_20 ;
}
void F_27 ( struct V_1 * V_2 , struct V_47 * V_48 )
{
struct V_49 * V_50 ;
struct V_51 * V_52 ;
unsigned long V_3 ;
F_28 ( V_2 -> V_53 , V_48 ) ;
F_29 ( & V_2 -> V_54 . V_55 , V_3 ) ;
F_30 (&mpath->frame_queue, skb) {
V_52 = (struct V_51 * ) V_50 -> V_56 ;
memcpy ( V_52 -> V_57 , V_48 -> V_48 . V_42 , V_58 ) ;
memcpy ( V_52 -> V_59 , V_2 -> V_44 -> V_60 . V_42 , V_58 ) ;
F_31 ( V_48 -> V_44 , V_48 , V_52 ) ;
}
F_32 ( & V_2 -> V_54 . V_55 , V_3 ) ;
}
static void F_33 ( struct V_49 * V_50 , char * V_61 ,
struct V_1 * V_62 )
{
struct V_51 * V_52 ;
struct V_63 * V_64 ;
int V_65 , V_66 ;
char * V_53 ;
V_52 = (struct V_51 * ) V_50 -> V_56 ;
V_66 = F_34 ( V_52 -> V_67 ) ;
V_64 = (struct V_63 * ) ( V_50 -> V_56 + V_66 ) ;
if ( ! ( V_64 -> V_3 & V_68 ) ) {
V_65 = 6 ;
F_35 ( V_50 , 2 * V_58 ) ;
memmove ( V_50 -> V_56 , V_52 , V_66 + V_65 ) ;
V_52 = (struct V_51 * ) V_50 -> V_56 ;
V_64 = (struct V_63 * ) ( V_50 -> V_56 + V_66 ) ;
V_64 -> V_3 = V_69 ;
memcpy ( V_64 -> V_70 , V_52 -> V_71 , V_58 ) ;
memcpy ( V_64 -> V_72 , V_52 -> V_73 , V_58 ) ;
}
V_52 = (struct V_51 * ) V_50 -> V_56 ;
F_36 () ;
V_53 = F_37 ( V_62 -> V_53 ) -> V_48 . V_42 ;
memcpy ( V_52 -> V_57 , V_53 , V_58 ) ;
F_38 () ;
memcpy ( V_52 -> V_59 , V_62 -> V_44 -> V_60 . V_42 , V_58 ) ;
memcpy ( V_52 -> V_71 , V_61 , V_58 ) ;
}
static void F_39 ( struct V_1 * V_62 ,
struct V_1 * V_74 ,
bool V_75 )
{
struct V_49 * V_50 , * V_76 , * V_77 ;
struct V_78 V_79 ;
unsigned long V_3 ;
F_40 ( V_62 == V_74 ) ;
F_40 ( ! V_62 -> V_53 ) ;
F_41 ( & V_79 ) ;
F_29 ( & V_74 -> V_54 . V_55 , V_3 ) ;
F_42 ( & V_74 -> V_54 , & V_79 ) ;
F_32 ( & V_74 -> V_54 . V_55 , V_3 ) ;
F_43 (&failq, fskb, tmp) {
if ( F_44 ( & V_62 -> V_54 ) >=
V_80 ) {
F_45 ( V_62 -> V_44 , L_1 ) ;
break;
}
V_50 = F_46 ( V_76 , V_15 ) ;
if ( F_47 ( ! V_50 ) )
break;
F_33 ( V_50 , V_62 -> V_81 , V_62 ) ;
F_48 ( & V_62 -> V_54 , V_50 ) ;
if ( V_75 )
continue;
F_49 ( V_76 , & V_79 ) ;
F_50 ( V_76 ) ;
}
F_45 ( V_62 -> V_44 , L_2 ,
V_62 -> V_81 , F_44 ( & V_62 -> V_54 ) ) ;
if ( ! V_75 )
return;
F_29 ( & V_74 -> V_54 . V_55 , V_3 ) ;
F_51 ( & V_79 , & V_74 -> V_54 ) ;
F_32 ( & V_74 -> V_54 . V_55 , V_3 ) ;
}
static struct V_1 * F_52 ( struct V_8 * V_24 , const T_2 * V_81 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 ;
struct V_17 * V_82 ;
struct V_30 * V_83 ;
V_82 = & V_24 -> V_16 [ F_25 ( V_81 , V_44 , V_24 ) ] ;
F_53 (node, bucket, list) {
V_2 = V_83 -> V_2 ;
if ( V_2 -> V_44 == V_44 &&
F_54 ( V_81 , V_2 -> V_81 ) ) {
if ( F_1 ( V_2 ) ) {
F_16 ( & V_2 -> V_84 ) ;
V_2 -> V_3 &= ~ V_4 ;
F_19 ( & V_2 -> V_84 ) ;
}
return V_2 ;
}
}
return NULL ;
}
struct V_1 *
F_55 ( struct V_43 * V_44 , const T_2 * V_81 )
{
return F_52 ( F_37 ( V_9 ) , V_81 , V_44 ) ;
}
struct V_1 *
F_56 ( struct V_43 * V_44 , const T_2 * V_81 )
{
return F_52 ( F_37 ( V_11 ) , V_81 , V_44 ) ;
}
struct V_1 *
F_57 ( struct V_43 * V_44 , int V_85 )
{
struct V_8 * V_24 = F_37 ( V_9 ) ;
struct V_30 * V_83 ;
int V_13 ;
int V_86 = 0 ;
F_58 (tbl, node, i) {
if ( V_44 && V_83 -> V_2 -> V_44 != V_44 )
continue;
if ( V_86 ++ == V_85 ) {
if ( F_1 ( V_83 -> V_2 ) ) {
F_16 ( & V_83 -> V_2 -> V_84 ) ;
V_83 -> V_2 -> V_3 &= ~ V_4 ;
F_19 ( & V_83 -> V_2 -> V_84 ) ;
}
return V_83 -> V_2 ;
}
}
return NULL ;
}
int F_59 ( struct V_1 * V_2 )
{
struct V_8 * V_24 ;
struct V_30 * V_31 , * V_87 ;
int V_88 ;
F_36 () ;
V_24 = F_37 ( V_9 ) ;
F_53 (gate, tbl->known_gates, list)
if ( V_31 -> V_2 == V_2 ) {
V_88 = - V_89 ;
goto V_90;
}
V_87 = F_9 ( sizeof( struct V_30 ) , V_15 ) ;
if ( ! V_87 ) {
V_88 = - V_41 ;
goto V_90;
}
V_2 -> V_91 = true ;
V_2 -> V_44 -> V_92 . V_93 . V_94 ++ ;
V_87 -> V_2 = V_2 ;
F_16 ( & V_24 -> V_23 ) ;
F_60 ( & V_87 -> V_33 , V_24 -> V_34 ) ;
F_19 ( & V_24 -> V_23 ) ;
F_45 ( V_2 -> V_44 ,
L_3 ,
V_2 -> V_81 , V_2 -> V_44 -> V_92 . V_93 . V_94 ) ;
V_88 = 0 ;
V_90:
F_38 () ;
return V_88 ;
}
static void F_61 ( struct V_8 * V_24 , struct V_1 * V_2 )
{
struct V_30 * V_31 ;
struct V_27 * V_29 ;
F_20 (gate, q, tbl->known_gates, list) {
if ( V_31 -> V_2 != V_2 )
continue;
F_16 ( & V_24 -> V_23 ) ;
F_62 ( & V_31 -> V_33 ) ;
F_63 ( V_31 , V_95 ) ;
F_19 ( & V_24 -> V_23 ) ;
V_2 -> V_44 -> V_92 . V_93 . V_94 -- ;
V_2 -> V_91 = false ;
F_45 ( V_2 -> V_44 ,
L_4 ,
V_2 -> V_81 , V_2 -> V_44 -> V_92 . V_93 . V_94 ) ;
break;
}
}
int F_64 ( struct V_43 * V_44 )
{
return V_44 -> V_92 . V_93 . V_94 ;
}
struct V_1 * F_65 ( struct V_43 * V_44 ,
const T_2 * V_81 )
{
struct V_96 * V_97 = & V_44 -> V_92 . V_93 ;
struct V_98 * V_99 = V_44 -> V_99 ;
struct V_8 * V_24 ;
struct V_1 * V_2 , * V_100 ;
struct V_30 * V_83 , * V_101 ;
struct V_17 * V_82 ;
int V_102 = 0 ;
int V_88 ;
T_1 V_103 ;
if ( F_54 ( V_81 , V_44 -> V_60 . V_42 ) )
return F_66 ( - V_104 ) ;
if ( F_67 ( V_81 ) )
return F_66 ( - V_104 ) ;
if ( F_68 ( & V_44 -> V_92 . V_93 . V_105 , 1 , V_106 ) == 0 )
return F_66 ( - V_107 ) ;
F_69 ( & V_10 ) ;
V_24 = F_3 () ;
V_103 = F_25 ( V_81 , V_44 , V_24 ) ;
V_82 = & V_24 -> V_16 [ V_103 ] ;
F_70 ( & V_24 -> V_18 [ V_103 ] ) ;
F_71 (node, bucket, list) {
V_2 = V_83 -> V_2 ;
if ( V_2 -> V_44 == V_44 &&
F_54 ( V_81 , V_2 -> V_81 ) )
goto V_108;
}
V_88 = - V_41 ;
V_100 = F_9 ( sizeof( struct V_1 ) , V_15 ) ;
if ( ! V_100 )
goto V_109;
V_101 = F_8 ( sizeof( struct V_30 ) , V_15 ) ;
if ( ! V_101 )
goto V_110;
memcpy ( V_100 -> V_81 , V_81 , V_58 ) ;
F_72 ( V_100 -> V_111 ) ;
V_100 -> V_112 = false ;
V_100 -> V_44 = V_44 ;
V_100 -> V_3 = 0 ;
F_73 ( & V_100 -> V_54 ) ;
V_101 -> V_2 = V_100 ;
V_100 -> V_113 . V_56 = ( unsigned long ) V_100 ;
V_100 -> V_113 . V_114 = V_115 ;
V_100 -> V_6 = V_5 ;
F_13 ( & V_100 -> V_84 ) ;
F_74 ( & V_100 -> V_113 ) ;
F_60 ( & V_101 -> V_33 , V_82 ) ;
if ( F_75 ( & V_24 -> V_21 ) >=
V_24 -> V_37 * ( V_24 -> V_20 + 1 ) )
V_102 = 1 ;
V_116 ++ ;
if ( V_102 ) {
F_76 ( V_117 , & V_97 -> V_118 ) ;
F_77 ( & V_99 -> V_119 , & V_44 -> V_120 ) ;
}
V_2 = V_100 ;
V_108:
F_78 ( & V_24 -> V_18 [ V_103 ] ) ;
F_79 ( & V_10 ) ;
return V_2 ;
V_110:
F_10 ( V_100 ) ;
V_109:
F_18 ( & V_44 -> V_92 . V_93 . V_105 ) ;
F_78 ( & V_24 -> V_18 [ V_103 ] ) ;
F_79 ( & V_10 ) ;
return F_66 ( V_88 ) ;
}
static void F_80 ( struct V_121 * V_95 )
{
struct V_8 * V_24 = F_81 ( V_95 , struct V_8 , V_121 ) ;
F_15 ( V_24 , false ) ;
}
void F_82 ( void )
{
struct V_8 * V_35 , * V_14 ;
F_83 ( & V_10 ) ;
V_35 = F_3 () ;
V_14 = F_7 ( V_35 -> V_12 + 1 ) ;
if ( ! V_14 )
goto V_122;
if ( F_22 ( V_35 , V_14 ) < 0 ) {
F_14 ( V_14 ) ;
goto V_122;
}
F_28 ( V_9 , V_14 ) ;
F_84 ( & V_35 -> V_121 , F_80 ) ;
V_122:
F_85 ( & V_10 ) ;
}
void F_86 ( void )
{
struct V_8 * V_35 , * V_14 ;
F_83 ( & V_10 ) ;
V_35 = F_6 () ;
V_14 = F_7 ( V_35 -> V_12 + 1 ) ;
if ( ! V_14 )
goto V_122;
if ( F_22 ( V_35 , V_14 ) < 0 ) {
F_14 ( V_14 ) ;
goto V_122;
}
F_28 ( V_11 , V_14 ) ;
F_84 ( & V_35 -> V_121 , F_80 ) ;
V_122:
F_85 ( & V_10 ) ;
}
int F_87 ( struct V_43 * V_44 ,
const T_2 * V_81 , const T_2 * V_123 )
{
struct V_96 * V_97 = & V_44 -> V_92 . V_93 ;
struct V_98 * V_99 = V_44 -> V_99 ;
struct V_8 * V_24 ;
struct V_1 * V_2 , * V_100 ;
struct V_30 * V_83 , * V_101 ;
struct V_17 * V_82 ;
int V_102 = 0 ;
int V_88 = 0 ;
T_1 V_103 ;
if ( F_54 ( V_81 , V_44 -> V_60 . V_42 ) )
return - V_104 ;
if ( F_67 ( V_81 ) )
return - V_104 ;
V_88 = - V_41 ;
V_100 = F_9 ( sizeof( struct V_1 ) , V_15 ) ;
if ( ! V_100 )
goto V_109;
V_101 = F_8 ( sizeof( struct V_30 ) , V_15 ) ;
if ( ! V_101 )
goto V_110;
F_69 ( & V_10 ) ;
memcpy ( V_100 -> V_81 , V_81 , V_58 ) ;
memcpy ( V_100 -> V_123 , V_123 , V_58 ) ;
V_100 -> V_44 = V_44 ;
V_100 -> V_3 = 0 ;
F_73 ( & V_100 -> V_54 ) ;
V_101 -> V_2 = V_100 ;
F_74 ( & V_100 -> V_113 ) ;
V_100 -> V_6 = V_5 ;
F_13 ( & V_100 -> V_84 ) ;
V_24 = F_6 () ;
V_103 = F_25 ( V_81 , V_44 , V_24 ) ;
V_82 = & V_24 -> V_16 [ V_103 ] ;
F_70 ( & V_24 -> V_18 [ V_103 ] ) ;
V_88 = - V_89 ;
F_71 (node, bucket, list) {
V_2 = V_83 -> V_2 ;
if ( V_2 -> V_44 == V_44 &&
F_54 ( V_81 , V_2 -> V_81 ) )
goto V_124;
}
F_60 ( & V_101 -> V_33 , V_82 ) ;
if ( F_75 ( & V_24 -> V_21 ) >=
V_24 -> V_37 * ( V_24 -> V_20 + 1 ) )
V_102 = 1 ;
F_78 ( & V_24 -> V_18 [ V_103 ] ) ;
F_79 ( & V_10 ) ;
if ( V_102 ) {
F_76 ( V_125 , & V_97 -> V_118 ) ;
F_77 ( & V_99 -> V_119 , & V_44 -> V_120 ) ;
}
return 0 ;
V_124:
F_78 ( & V_24 -> V_18 [ V_103 ] ) ;
F_79 ( & V_10 ) ;
F_10 ( V_101 ) ;
V_110:
F_10 ( V_100 ) ;
V_109:
return V_88 ;
}
void F_88 ( struct V_47 * V_48 )
{
struct V_8 * V_24 ;
static const T_2 V_126 [ V_58 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
struct V_1 * V_2 ;
struct V_30 * V_83 ;
struct V_43 * V_44 = V_48 -> V_44 ;
int V_13 ;
T_3 V_127 = F_89 ( V_128 ) ;
F_36 () ;
V_24 = F_37 ( V_9 ) ;
F_58 (tbl, node, i) {
V_2 = V_83 -> V_2 ;
if ( F_37 ( V_2 -> V_53 ) == V_48 &&
V_2 -> V_3 & V_4 &&
! ( V_2 -> V_3 & V_7 ) ) {
F_16 ( & V_2 -> V_84 ) ;
V_2 -> V_3 &= ~ V_4 ;
++ V_2 -> V_129 ;
F_19 ( & V_2 -> V_84 ) ;
F_90 ( V_44 ,
V_44 -> V_92 . V_93 . V_130 . V_131 ,
V_2 -> V_81 , F_91 ( V_2 -> V_129 ) ,
V_127 , V_126 ) ;
}
}
F_38 () ;
}
static void F_92 ( struct V_121 * V_132 )
{
struct V_30 * V_83 = F_81 ( V_132 , struct V_30 , V_95 ) ;
struct V_43 * V_44 = V_83 -> V_2 -> V_44 ;
F_93 ( & V_83 -> V_2 -> V_113 ) ;
F_18 ( & V_44 -> V_92 . V_93 . V_105 ) ;
F_10 ( V_83 -> V_2 ) ;
F_10 ( V_83 ) ;
}
static void F_94 ( struct V_8 * V_24 , struct V_30 * V_83 )
{
struct V_1 * V_2 ;
V_2 = V_83 -> V_2 ;
F_70 ( & V_2 -> V_84 ) ;
V_2 -> V_3 |= V_133 ;
if ( V_2 -> V_91 )
F_61 ( V_24 , V_2 ) ;
F_62 ( & V_83 -> V_33 ) ;
F_84 ( & V_83 -> V_95 , F_92 ) ;
F_78 ( & V_2 -> V_84 ) ;
F_18 ( & V_24 -> V_21 ) ;
}
void F_95 ( struct V_47 * V_48 )
{
struct V_8 * V_24 ;
struct V_1 * V_2 ;
struct V_30 * V_83 ;
int V_13 ;
F_36 () ;
F_69 ( & V_10 ) ;
V_24 = F_3 () ;
F_58 (tbl, node, i) {
V_2 = V_83 -> V_2 ;
if ( F_37 ( V_2 -> V_53 ) == V_48 ) {
F_70 ( & V_24 -> V_18 [ V_13 ] ) ;
F_94 ( V_24 , V_83 ) ;
F_78 ( & V_24 -> V_18 [ V_13 ] ) ;
}
}
F_79 ( & V_10 ) ;
F_38 () ;
}
static void F_96 ( struct V_8 * V_24 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 ;
struct V_30 * V_83 ;
int V_13 ;
F_47 ( ! F_97 () ) ;
F_58 (tbl, node, i) {
V_2 = V_83 -> V_2 ;
if ( V_2 -> V_44 != V_44 )
continue;
F_16 ( & V_24 -> V_18 [ V_13 ] ) ;
F_94 ( V_24 , V_83 ) ;
F_19 ( & V_24 -> V_18 [ V_13 ] ) ;
}
}
void F_98 ( struct V_43 * V_44 )
{
struct V_8 * V_24 ;
F_36 () ;
F_69 ( & V_10 ) ;
V_24 = F_3 () ;
F_96 ( V_24 , V_44 ) ;
V_24 = F_6 () ;
F_96 ( V_24 , V_44 ) ;
F_79 ( & V_10 ) ;
F_38 () ;
}
int F_99 ( struct V_43 * V_44 , const T_2 * V_42 )
{
struct V_8 * V_24 ;
struct V_1 * V_2 ;
struct V_30 * V_83 ;
struct V_17 * V_82 ;
int V_103 ;
int V_88 = 0 ;
F_69 ( & V_10 ) ;
V_24 = F_3 () ;
V_103 = F_25 ( V_42 , V_44 , V_24 ) ;
V_82 = & V_24 -> V_16 [ V_103 ] ;
F_70 ( & V_24 -> V_18 [ V_103 ] ) ;
F_71 (node, bucket, list) {
V_2 = V_83 -> V_2 ;
if ( V_2 -> V_44 == V_44 &&
F_54 ( V_42 , V_2 -> V_81 ) ) {
F_94 ( V_24 , V_83 ) ;
goto V_134;
}
}
V_88 = - V_135 ;
V_134:
V_116 ++ ;
F_78 ( & V_24 -> V_18 [ V_103 ] ) ;
F_79 ( & V_10 ) ;
return V_88 ;
}
void F_100 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 & V_4 )
F_101 ( V_2 -> V_44 -> V_99 ,
& V_2 -> V_54 ) ;
}
int F_102 ( struct V_1 * V_2 )
{
struct V_43 * V_44 = V_2 -> V_44 ;
struct V_8 * V_24 ;
struct V_1 * V_74 = V_2 ;
struct V_30 * V_31 = NULL ;
bool V_75 = false ;
struct V_17 * V_34 ;
F_36 () ;
V_24 = F_37 ( V_9 ) ;
V_34 = V_24 -> V_34 ;
F_38 () ;
if ( ! V_34 )
return - V_136 ;
F_53 (gate, known_gates, list) {
if ( V_31 -> V_2 -> V_44 != V_44 )
continue;
if ( V_31 -> V_2 -> V_3 & V_4 ) {
F_45 ( V_44 , L_5 , V_31 -> V_2 -> V_81 ) ;
F_39 ( V_31 -> V_2 , V_74 , V_75 ) ;
V_74 = V_31 -> V_2 ;
V_75 = true ;
} else {
F_45 ( V_44 ,
L_6 ,
V_31 -> V_2 , V_31 -> V_2 -> V_3 ) ;
}
}
F_53 (gate, known_gates, list)
if ( V_31 -> V_2 -> V_44 == V_44 ) {
F_45 ( V_44 , L_7 , V_31 -> V_2 -> V_81 ) ;
F_100 ( V_31 -> V_2 ) ;
}
return ( V_74 == V_2 ) ? - V_136 : 0 ;
}
void F_103 ( struct V_43 * V_44 ,
struct V_49 * V_50 )
{
F_50 ( V_50 ) ;
V_44 -> V_92 . V_93 . V_137 . V_138 ++ ;
}
void F_104 ( struct V_1 * V_2 )
{
struct V_49 * V_50 ;
while ( ( V_50 = F_105 ( & V_2 -> V_54 ) ) != NULL )
F_103 ( V_2 -> V_44 , V_50 ) ;
}
void F_106 ( struct V_1 * V_2 , struct V_47 * V_53 )
{
F_16 ( & V_2 -> V_84 ) ;
F_27 ( V_2 , V_53 ) ;
V_2 -> V_129 = 0xffff ;
V_2 -> V_139 = 0 ;
V_2 -> V_140 = 0 ;
V_2 -> V_6 = 0 ;
V_2 -> V_3 |= V_7 ;
F_107 ( V_2 ) ;
F_19 ( & V_2 -> V_84 ) ;
F_100 ( V_2 ) ;
}
static void F_108 ( struct V_27 * V_28 , bool V_25 )
{
struct V_1 * V_2 ;
struct V_30 * V_83 = F_109 ( V_28 , struct V_30 , V_33 ) ;
V_2 = V_83 -> V_2 ;
F_62 ( V_28 ) ;
if ( V_25 ) {
F_93 ( & V_2 -> V_113 ) ;
F_10 ( V_2 ) ;
}
F_10 ( V_83 ) ;
}
static int F_110 ( struct V_27 * V_28 , struct V_8 * V_14 )
{
struct V_1 * V_2 ;
struct V_30 * V_83 , * V_101 ;
T_1 V_103 ;
V_101 = F_8 ( sizeof( struct V_30 ) , V_15 ) ;
if ( V_101 == NULL )
return - V_41 ;
V_83 = F_109 ( V_28 , struct V_30 , V_33 ) ;
V_2 = V_83 -> V_2 ;
V_101 -> V_2 = V_2 ;
V_103 = F_25 ( V_2 -> V_81 , V_2 -> V_44 , V_14 ) ;
F_111 ( & V_101 -> V_33 ,
& V_14 -> V_16 [ V_103 ] ) ;
return 0 ;
}
int F_112 ( void )
{
struct V_8 * V_141 , * V_142 ;
int V_143 ;
V_141 = F_7 ( V_144 ) ;
if ( ! V_141 )
return - V_41 ;
V_141 -> V_32 = & F_108 ;
V_141 -> V_39 = & F_110 ;
V_141 -> V_37 = V_145 ;
V_141 -> V_34 = F_9 ( sizeof( struct V_17 ) , V_15 ) ;
if ( ! V_141 -> V_34 ) {
V_143 = - V_41 ;
goto V_146;
}
F_113 ( V_141 -> V_34 ) ;
V_142 = F_7 ( V_144 ) ;
if ( ! V_142 ) {
V_143 = - V_41 ;
goto V_146;
}
V_142 -> V_32 = & F_108 ;
V_142 -> V_39 = & F_110 ;
V_142 -> V_37 = V_145 ;
V_142 -> V_34 = F_9 ( sizeof( struct V_17 ) , V_15 ) ;
if ( ! V_142 -> V_34 ) {
V_143 = - V_41 ;
goto V_147;
}
F_113 ( V_142 -> V_34 ) ;
F_114 ( V_9 , V_141 ) ;
F_114 ( V_11 , V_142 ) ;
return 0 ;
V_147:
F_15 ( V_142 , true ) ;
V_146:
F_15 ( V_141 , true ) ;
return V_143 ;
}
void F_115 ( struct V_43 * V_44 )
{
struct V_8 * V_24 ;
struct V_1 * V_2 ;
struct V_30 * V_83 ;
int V_13 ;
F_36 () ;
V_24 = F_37 ( V_9 ) ;
F_58 (tbl, node, i) {
if ( V_83 -> V_2 -> V_44 != V_44 )
continue;
V_2 = V_83 -> V_2 ;
if ( ( ! ( V_2 -> V_3 & V_133 ) ) &&
( ! ( V_2 -> V_3 & V_7 ) ) &&
F_2 ( V_5 , V_2 -> V_6 + V_148 ) )
F_99 ( V_2 -> V_44 , V_2 -> V_81 ) ;
}
F_38 () ;
}
void F_116 ( void )
{
F_15 ( F_4 ( V_9 , 1 ) , true ) ;
F_15 ( F_4 ( V_11 , 1 ) , true ) ;
}
