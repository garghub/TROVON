static inline struct V_1 * F_1 ( void )
{
return F_2 ( V_2 ,
F_3 ( & V_3 ) ) ;
}
static inline struct V_1 * F_4 ( void )
{
return F_2 ( V_4 ,
F_3 ( & V_3 ) ) ;
}
static struct V_1 * F_5 ( int V_5 )
{
int V_6 ;
struct V_1 * V_7 ;
V_7 = F_6 ( sizeof( struct V_1 ) , V_8 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_9 = F_7 ( sizeof( struct V_10 ) *
( 1 << V_5 ) , V_8 ) ;
if ( ! V_7 -> V_9 ) {
F_8 ( V_7 ) ;
return NULL ;
}
V_7 -> V_11 = F_6 ( sizeof( V_12 ) *
( 1 << V_5 ) , V_8 ) ;
if ( ! V_7 -> V_11 ) {
F_8 ( V_7 -> V_9 ) ;
F_8 ( V_7 ) ;
return NULL ;
}
V_7 -> V_5 = V_5 ;
V_7 -> V_13 = ( 1 << V_5 ) - 1 ;
F_9 ( & V_7 -> V_14 , 0 ) ;
F_10 ( & V_7 -> V_15 ,
sizeof( V_7 -> V_15 ) ) ;
for ( V_6 = 0 ; V_6 <= V_7 -> V_13 ; V_6 ++ )
F_11 ( & V_7 -> V_11 [ V_6 ] ) ;
F_11 ( & V_7 -> V_16 ) ;
return V_7 ;
}
static void F_12 ( struct V_1 * V_17 )
{
F_8 ( V_17 -> V_9 ) ;
F_8 ( V_17 -> V_11 ) ;
F_8 ( V_17 ) ;
}
static void F_13 ( struct V_1 * V_17 , bool V_18 )
{
struct V_10 * V_19 ;
struct V_20 * V_21 , * V_22 ;
struct V_23 * V_24 ;
int V_6 ;
V_19 = V_17 -> V_9 ;
for ( V_6 = 0 ; V_6 <= V_17 -> V_13 ; V_6 ++ ) {
F_14 ( & V_17 -> V_11 [ V_6 ] ) ;
F_15 (p, q, &mesh_hash[i]) {
V_17 -> V_25 ( V_21 , V_18 ) ;
F_16 ( & V_17 -> V_14 ) ;
}
F_17 ( & V_17 -> V_11 [ V_6 ] ) ;
}
if ( V_18 ) {
F_14 ( & V_17 -> V_16 ) ;
F_18 (gate, p, q,
tbl->known_gates, list) {
F_19 ( & V_24 -> V_26 ) ;
F_8 ( V_24 ) ;
}
F_8 ( V_17 -> V_27 ) ;
F_17 ( & V_17 -> V_16 ) ;
}
F_12 ( V_17 ) ;
}
static int F_20 ( struct V_1 * V_28 ,
struct V_1 * V_7 )
{
struct V_10 * V_29 ;
struct V_20 * V_21 , * V_22 ;
int V_6 ;
if ( F_21 ( & V_28 -> V_14 )
< V_28 -> V_30 * ( V_28 -> V_13 + 1 ) )
return - V_31 ;
V_7 -> V_25 = V_28 -> V_25 ;
V_7 -> V_30 = V_28 -> V_30 ;
V_7 -> V_32 = V_28 -> V_32 ;
V_7 -> V_27 = V_28 -> V_27 ;
F_9 ( & V_7 -> V_14 , F_21 ( & V_28 -> V_14 ) ) ;
V_29 = V_28 -> V_9 ;
for ( V_6 = 0 ; V_6 <= V_28 -> V_13 ; V_6 ++ )
F_22 (p, &oldhash[i])
if ( V_28 -> V_32 ( V_21 , V_7 ) < 0 )
goto V_33;
return 0 ;
V_33:
for ( V_6 = 0 ; V_6 <= V_7 -> V_13 ; V_6 ++ ) {
F_15 (p, q, &newtbl->hash_buckets[i])
V_28 -> V_25 ( V_21 , 0 ) ;
}
return - V_34 ;
}
static T_1 F_23 ( T_2 * V_35 , struct V_36 * V_37 ,
struct V_1 * V_17 )
{
return F_24 ( * ( T_1 * ) ( V_35 + 2 ) , V_37 -> V_38 -> V_39 , V_17 -> V_15 )
& V_17 -> V_13 ;
}
void F_25 ( struct V_40 * V_41 , struct V_42 * V_43 )
{
struct V_44 * V_45 ;
struct V_46 * V_47 ;
unsigned long V_48 ;
F_26 ( V_41 -> V_49 , V_43 ) ;
F_27 ( & V_41 -> V_50 . V_51 , V_48 ) ;
F_28 (&mpath->frame_queue, skb) {
V_47 = (struct V_46 * ) V_45 -> V_52 ;
memcpy ( V_47 -> V_53 , V_43 -> V_43 . V_35 , V_54 ) ;
memcpy ( V_47 -> V_55 , V_41 -> V_37 -> V_56 . V_35 , V_54 ) ;
}
F_29 ( & V_41 -> V_50 . V_51 , V_48 ) ;
}
static void F_30 ( struct V_44 * V_45 , char * V_57 ,
struct V_40 * V_58 )
{
struct V_46 * V_47 ;
struct V_59 * V_60 ;
int V_61 , V_62 ;
char * V_49 ;
V_47 = (struct V_46 * ) V_45 -> V_52 ;
V_62 = F_31 ( V_47 -> V_63 ) ;
V_60 = (struct V_59 * ) ( V_45 -> V_52 + V_62 ) ;
if ( ! ( V_60 -> V_48 & V_64 ) ) {
V_61 = 6 ;
F_32 ( V_45 , 2 * V_54 ) ;
memmove ( V_45 -> V_52 , V_47 , V_62 + V_61 ) ;
V_47 = (struct V_46 * ) V_45 -> V_52 ;
V_60 = (struct V_59 * ) ( V_45 -> V_52 + V_62 ) ;
V_60 -> V_48 = V_65 ;
memcpy ( V_60 -> V_66 , V_47 -> V_67 , V_54 ) ;
memcpy ( V_60 -> V_68 , V_47 -> V_69 , V_54 ) ;
}
V_47 = (struct V_46 * ) V_45 -> V_52 ;
F_33 () ;
V_49 = F_34 ( V_58 -> V_49 ) -> V_43 . V_35 ;
memcpy ( V_47 -> V_53 , V_49 , V_54 ) ;
F_35 () ;
memcpy ( V_47 -> V_55 , V_58 -> V_37 -> V_56 . V_35 , V_54 ) ;
memcpy ( V_47 -> V_67 , V_57 , V_54 ) ;
}
static void F_36 ( struct V_40 * V_58 ,
struct V_40 * V_70 ,
bool V_71 )
{
struct V_44 * V_45 , * V_72 , * V_73 ;
struct V_74 V_75 ;
unsigned long V_48 ;
F_37 ( V_58 == V_70 ) ;
F_37 ( ! V_58 -> V_49 ) ;
F_38 ( & V_75 ) ;
F_27 ( & V_70 -> V_50 . V_51 , V_48 ) ;
F_39 ( & V_70 -> V_50 , & V_75 ) ;
F_29 ( & V_70 -> V_50 . V_51 , V_48 ) ;
F_40 (&failq, fskb, tmp) {
if ( F_41 ( & V_58 -> V_50 ) >=
V_76 ) {
F_42 ( V_58 -> V_37 , L_1 ) ;
break;
}
V_45 = F_43 ( V_72 , V_8 ) ;
if ( F_44 ( ! V_45 ) )
break;
F_30 ( V_45 , V_58 -> V_77 , V_58 ) ;
F_45 ( & V_58 -> V_50 , V_45 ) ;
if ( V_71 )
continue;
F_46 ( V_72 , & V_75 ) ;
F_47 ( V_72 ) ;
}
F_42 ( V_58 -> V_37 , L_2 ,
V_58 -> V_77 , F_41 ( & V_58 -> V_50 ) ) ;
if ( ! V_71 )
return;
F_27 ( & V_70 -> V_50 . V_51 , V_48 ) ;
F_48 ( & V_75 , & V_70 -> V_50 ) ;
F_29 ( & V_70 -> V_50 . V_51 , V_48 ) ;
}
static struct V_40 * F_49 ( struct V_1 * V_17 , T_2 * V_77 ,
struct V_36 * V_37 )
{
struct V_40 * V_41 ;
struct V_20 * V_78 ;
struct V_10 * V_79 ;
struct V_23 * V_80 ;
V_79 = & V_17 -> V_9 [ F_23 ( V_77 , V_37 , V_17 ) ] ;
F_50 (node, n, bucket, list) {
V_41 = V_80 -> V_41 ;
if ( V_41 -> V_37 == V_37 &&
F_51 ( V_77 , V_41 -> V_77 ) ) {
if ( F_52 ( V_41 ) ) {
F_14 ( & V_41 -> V_81 ) ;
V_41 -> V_48 &= ~ V_82 ;
F_17 ( & V_41 -> V_81 ) ;
}
return V_41 ;
}
}
return NULL ;
}
struct V_40 * F_53 ( T_2 * V_77 , struct V_36 * V_37 )
{
return F_49 ( F_34 ( V_2 ) , V_77 , V_37 ) ;
}
struct V_40 * F_54 ( T_2 * V_77 , struct V_36 * V_37 )
{
return F_49 ( F_34 ( V_4 ) , V_77 , V_37 ) ;
}
struct V_40 * F_55 ( int V_83 , struct V_36 * V_37 )
{
struct V_1 * V_17 = F_34 ( V_2 ) ;
struct V_23 * V_80 ;
struct V_20 * V_21 ;
int V_6 ;
int V_84 = 0 ;
F_56 (tbl, p, node, i) {
if ( V_37 && V_80 -> V_41 -> V_37 != V_37 )
continue;
if ( V_84 ++ == V_83 ) {
if ( F_52 ( V_80 -> V_41 ) ) {
F_14 ( & V_80 -> V_41 -> V_81 ) ;
V_80 -> V_41 -> V_48 &= ~ V_82 ;
F_17 ( & V_80 -> V_41 -> V_81 ) ;
}
return V_80 -> V_41 ;
}
}
return NULL ;
}
int F_57 ( struct V_40 * V_41 )
{
struct V_1 * V_17 ;
struct V_23 * V_24 , * V_85 ;
struct V_20 * V_78 ;
int V_86 ;
F_33 () ;
V_17 = F_34 ( V_2 ) ;
F_50 (gate, n, tbl->known_gates, list)
if ( V_24 -> V_41 == V_41 ) {
V_86 = - V_87 ;
goto V_88;
}
V_85 = F_7 ( sizeof( struct V_23 ) , V_8 ) ;
if ( ! V_85 ) {
V_86 = - V_34 ;
goto V_88;
}
V_41 -> V_89 = true ;
V_41 -> V_37 -> V_90 . V_91 . V_92 ++ ;
V_85 -> V_41 = V_41 ;
F_14 ( & V_17 -> V_16 ) ;
F_58 ( & V_85 -> V_26 , V_17 -> V_27 ) ;
F_17 ( & V_17 -> V_16 ) ;
F_35 () ;
F_42 ( V_41 -> V_37 ,
L_3 ,
V_41 -> V_77 , V_41 -> V_37 -> V_90 . V_91 . V_92 ) ;
return 0 ;
V_88:
F_35 () ;
return V_86 ;
}
static int F_59 ( struct V_1 * V_17 , struct V_40 * V_41 )
{
struct V_23 * V_24 ;
struct V_20 * V_21 , * V_22 ;
F_18 (gate, p, q, tbl->known_gates, list)
if ( V_24 -> V_41 == V_41 ) {
F_14 ( & V_17 -> V_16 ) ;
F_60 ( & V_24 -> V_26 ) ;
F_61 ( V_24 , V_93 ) ;
F_17 ( & V_17 -> V_16 ) ;
V_41 -> V_37 -> V_90 . V_91 . V_92 -- ;
V_41 -> V_89 = false ;
F_42 ( V_41 -> V_37 ,
L_4 ,
V_41 -> V_77 , V_41 -> V_37 -> V_90 . V_91 . V_92 ) ;
break;
}
return 0 ;
}
int F_62 ( struct V_36 * V_37 )
{
return V_37 -> V_90 . V_91 . V_92 ;
}
int F_63 ( T_2 * V_77 , struct V_36 * V_37 )
{
struct V_94 * V_95 = & V_37 -> V_90 . V_91 ;
struct V_96 * V_97 = V_37 -> V_97 ;
struct V_1 * V_17 ;
struct V_40 * V_41 , * V_98 ;
struct V_23 * V_80 , * V_99 ;
struct V_10 * V_79 ;
struct V_20 * V_78 ;
int V_100 = 0 ;
int V_86 = 0 ;
T_1 V_101 ;
if ( F_51 ( V_77 , V_37 -> V_56 . V_35 ) )
return - V_102 ;
if ( F_64 ( V_77 ) )
return - V_102 ;
if ( F_65 ( & V_37 -> V_90 . V_91 . V_103 , 1 , V_104 ) == 0 )
return - V_105 ;
V_86 = - V_34 ;
V_98 = F_7 ( sizeof( struct V_40 ) , V_8 ) ;
if ( ! V_98 )
goto V_106;
V_99 = F_6 ( sizeof( struct V_23 ) , V_8 ) ;
if ( ! V_99 )
goto V_107;
F_66 ( & V_3 ) ;
memcpy ( V_98 -> V_77 , V_77 , V_54 ) ;
F_67 ( V_98 -> V_108 ) ;
V_98 -> V_109 = false ;
V_98 -> V_37 = V_37 ;
V_98 -> V_48 = 0 ;
F_68 ( & V_98 -> V_50 ) ;
V_99 -> V_41 = V_98 ;
V_98 -> V_110 . V_52 = ( unsigned long ) V_98 ;
V_98 -> V_110 . V_111 = V_112 ;
V_98 -> V_113 = V_114 ;
F_11 ( & V_98 -> V_81 ) ;
F_69 ( & V_98 -> V_110 ) ;
V_17 = F_1 () ;
V_101 = F_23 ( V_77 , V_37 , V_17 ) ;
V_79 = & V_17 -> V_9 [ V_101 ] ;
F_70 ( & V_17 -> V_11 [ V_101 ] ) ;
V_86 = - V_87 ;
F_71 (node, n, bucket, list) {
V_41 = V_80 -> V_41 ;
if ( V_41 -> V_37 == V_37 &&
F_51 ( V_77 , V_41 -> V_77 ) )
goto V_115;
}
F_58 ( & V_99 -> V_26 , V_79 ) ;
if ( F_72 ( & V_17 -> V_14 ) >=
V_17 -> V_30 * ( V_17 -> V_13 + 1 ) )
V_100 = 1 ;
V_116 ++ ;
F_73 ( & V_17 -> V_11 [ V_101 ] ) ;
F_74 ( & V_3 ) ;
if ( V_100 ) {
F_75 ( V_117 , & V_95 -> V_118 ) ;
F_76 ( & V_97 -> V_119 , & V_37 -> V_120 ) ;
}
return 0 ;
V_115:
F_73 ( & V_17 -> V_11 [ V_101 ] ) ;
F_74 ( & V_3 ) ;
F_8 ( V_99 ) ;
V_107:
F_8 ( V_98 ) ;
V_106:
F_16 ( & V_37 -> V_90 . V_91 . V_103 ) ;
return V_86 ;
}
static void F_77 ( struct V_121 * V_93 )
{
struct V_1 * V_17 = F_78 ( V_93 , struct V_1 , V_121 ) ;
F_13 ( V_17 , false ) ;
}
void F_79 ( void )
{
struct V_1 * V_28 , * V_7 ;
F_80 ( & V_3 ) ;
V_28 = F_1 () ;
V_7 = F_5 ( V_28 -> V_5 + 1 ) ;
if ( ! V_7 )
goto V_122;
if ( F_20 ( V_28 , V_7 ) < 0 ) {
F_12 ( V_7 ) ;
goto V_122;
}
F_26 ( V_2 , V_7 ) ;
F_81 ( & V_28 -> V_121 , F_77 ) ;
V_122:
F_82 ( & V_3 ) ;
}
void F_83 ( void )
{
struct V_1 * V_28 , * V_7 ;
F_80 ( & V_3 ) ;
V_28 = F_4 () ;
V_7 = F_5 ( V_28 -> V_5 + 1 ) ;
if ( ! V_7 )
goto V_122;
if ( F_20 ( V_28 , V_7 ) < 0 ) {
F_12 ( V_7 ) ;
goto V_122;
}
F_26 ( V_4 , V_7 ) ;
F_81 ( & V_28 -> V_121 , F_77 ) ;
V_122:
F_82 ( & V_3 ) ;
}
int F_84 ( T_2 * V_77 , T_2 * V_123 , struct V_36 * V_37 )
{
struct V_94 * V_95 = & V_37 -> V_90 . V_91 ;
struct V_96 * V_97 = V_37 -> V_97 ;
struct V_1 * V_17 ;
struct V_40 * V_41 , * V_98 ;
struct V_23 * V_80 , * V_99 ;
struct V_10 * V_79 ;
struct V_20 * V_78 ;
int V_100 = 0 ;
int V_86 = 0 ;
T_1 V_101 ;
if ( F_51 ( V_77 , V_37 -> V_56 . V_35 ) )
return - V_102 ;
if ( F_64 ( V_77 ) )
return - V_102 ;
V_86 = - V_34 ;
V_98 = F_7 ( sizeof( struct V_40 ) , V_8 ) ;
if ( ! V_98 )
goto V_106;
V_99 = F_6 ( sizeof( struct V_23 ) , V_8 ) ;
if ( ! V_99 )
goto V_107;
F_66 ( & V_3 ) ;
memcpy ( V_98 -> V_77 , V_77 , V_54 ) ;
memcpy ( V_98 -> V_123 , V_123 , V_54 ) ;
V_98 -> V_37 = V_37 ;
V_98 -> V_48 = 0 ;
F_68 ( & V_98 -> V_50 ) ;
V_99 -> V_41 = V_98 ;
F_69 ( & V_98 -> V_110 ) ;
V_98 -> V_113 = V_114 ;
F_11 ( & V_98 -> V_81 ) ;
V_17 = F_4 () ;
V_101 = F_23 ( V_77 , V_37 , V_17 ) ;
V_79 = & V_17 -> V_9 [ V_101 ] ;
F_70 ( & V_17 -> V_11 [ V_101 ] ) ;
V_86 = - V_87 ;
F_71 (node, n, bucket, list) {
V_41 = V_80 -> V_41 ;
if ( V_41 -> V_37 == V_37 &&
F_51 ( V_77 , V_41 -> V_77 ) )
goto V_115;
}
F_58 ( & V_99 -> V_26 , V_79 ) ;
if ( F_72 ( & V_17 -> V_14 ) >=
V_17 -> V_30 * ( V_17 -> V_13 + 1 ) )
V_100 = 1 ;
F_73 ( & V_17 -> V_11 [ V_101 ] ) ;
F_74 ( & V_3 ) ;
if ( V_100 ) {
F_75 ( V_124 , & V_95 -> V_118 ) ;
F_76 ( & V_97 -> V_119 , & V_37 -> V_120 ) ;
}
return 0 ;
V_115:
F_73 ( & V_17 -> V_11 [ V_101 ] ) ;
F_74 ( & V_3 ) ;
F_8 ( V_99 ) ;
V_107:
F_8 ( V_98 ) ;
V_106:
return V_86 ;
}
void F_85 ( struct V_42 * V_43 )
{
struct V_1 * V_17 ;
static const T_2 V_125 [ V_54 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
struct V_40 * V_41 ;
struct V_23 * V_80 ;
struct V_20 * V_21 ;
struct V_36 * V_37 = V_43 -> V_37 ;
int V_6 ;
T_3 V_126 = F_86 ( V_127 ) ;
F_33 () ;
V_17 = F_34 ( V_2 ) ;
F_56 (tbl, p, node, i) {
V_41 = V_80 -> V_41 ;
if ( F_34 ( V_41 -> V_49 ) == V_43 &&
V_41 -> V_48 & V_82 &&
! ( V_41 -> V_48 & V_128 ) ) {
F_14 ( & V_41 -> V_81 ) ;
V_41 -> V_48 &= ~ V_82 ;
++ V_41 -> V_129 ;
F_17 ( & V_41 -> V_81 ) ;
F_87 ( V_37 -> V_90 . V_91 . V_130 . V_131 ,
V_41 -> V_77 , F_88 ( V_41 -> V_129 ) ,
V_126 , V_125 , V_37 ) ;
}
}
F_35 () ;
}
static void F_89 ( struct V_121 * V_132 )
{
struct V_23 * V_80 = F_78 ( V_132 , struct V_23 , V_93 ) ;
struct V_36 * V_37 = V_80 -> V_41 -> V_37 ;
F_90 ( & V_80 -> V_41 -> V_110 ) ;
F_16 ( & V_37 -> V_90 . V_91 . V_103 ) ;
F_8 ( V_80 -> V_41 ) ;
F_8 ( V_80 ) ;
}
static void F_91 ( struct V_1 * V_17 , struct V_23 * V_80 )
{
struct V_40 * V_41 ;
V_41 = V_80 -> V_41 ;
F_70 ( & V_41 -> V_81 ) ;
V_41 -> V_48 |= V_133 ;
if ( V_41 -> V_89 )
F_59 ( V_17 , V_41 ) ;
F_60 ( & V_80 -> V_26 ) ;
F_81 ( & V_80 -> V_93 , F_89 ) ;
F_73 ( & V_41 -> V_81 ) ;
F_16 ( & V_17 -> V_14 ) ;
}
void F_92 ( struct V_42 * V_43 )
{
struct V_1 * V_17 ;
struct V_40 * V_41 ;
struct V_23 * V_80 ;
struct V_20 * V_21 ;
int V_6 ;
F_33 () ;
F_66 ( & V_3 ) ;
V_17 = F_1 () ;
F_56 (tbl, p, node, i) {
V_41 = V_80 -> V_41 ;
if ( F_34 ( V_41 -> V_49 ) == V_43 ) {
F_70 ( & V_17 -> V_11 [ V_6 ] ) ;
F_91 ( V_17 , V_80 ) ;
F_73 ( & V_17 -> V_11 [ V_6 ] ) ;
}
}
F_74 ( & V_3 ) ;
F_35 () ;
}
static void F_93 ( struct V_1 * V_17 ,
struct V_36 * V_37 )
{
struct V_40 * V_41 ;
struct V_23 * V_80 ;
struct V_20 * V_21 ;
int V_6 ;
F_44 ( ! F_94 () ) ;
F_56 (tbl, p, node, i) {
V_41 = V_80 -> V_41 ;
if ( V_41 -> V_37 != V_37 )
continue;
F_14 ( & V_17 -> V_11 [ V_6 ] ) ;
F_91 ( V_17 , V_80 ) ;
F_17 ( & V_17 -> V_11 [ V_6 ] ) ;
}
}
void F_95 ( struct V_36 * V_37 )
{
struct V_1 * V_17 ;
F_33 () ;
F_66 ( & V_3 ) ;
V_17 = F_1 () ;
F_93 ( V_17 , V_37 ) ;
V_17 = F_4 () ;
F_93 ( V_17 , V_37 ) ;
F_74 ( & V_3 ) ;
F_35 () ;
}
int F_96 ( T_2 * V_35 , struct V_36 * V_37 )
{
struct V_1 * V_17 ;
struct V_40 * V_41 ;
struct V_23 * V_80 ;
struct V_10 * V_79 ;
struct V_20 * V_78 ;
int V_101 ;
int V_86 = 0 ;
F_66 ( & V_3 ) ;
V_17 = F_1 () ;
V_101 = F_23 ( V_35 , V_37 , V_17 ) ;
V_79 = & V_17 -> V_9 [ V_101 ] ;
F_70 ( & V_17 -> V_11 [ V_101 ] ) ;
F_71 (node, n, bucket, list) {
V_41 = V_80 -> V_41 ;
if ( V_41 -> V_37 == V_37 &&
F_51 ( V_35 , V_41 -> V_77 ) ) {
F_91 ( V_17 , V_80 ) ;
goto V_134;
}
}
V_86 = - V_135 ;
V_134:
V_116 ++ ;
F_73 ( & V_17 -> V_11 [ V_101 ] ) ;
F_74 ( & V_3 ) ;
return V_86 ;
}
void F_97 ( struct V_40 * V_41 )
{
if ( V_41 -> V_48 & V_82 )
F_98 ( V_41 -> V_37 -> V_97 ,
& V_41 -> V_50 ) ;
}
int F_99 ( struct V_40 * V_41 )
{
struct V_36 * V_37 = V_41 -> V_37 ;
struct V_20 * V_78 ;
struct V_1 * V_17 ;
struct V_40 * V_70 = V_41 ;
struct V_23 * V_24 = NULL ;
bool V_71 = false ;
struct V_10 * V_27 ;
F_33 () ;
V_17 = F_34 ( V_2 ) ;
V_27 = V_17 -> V_27 ;
F_35 () ;
if ( ! V_27 )
return - V_136 ;
F_50 (gate, n, known_gates, list) {
if ( V_24 -> V_41 -> V_37 != V_37 )
continue;
if ( V_24 -> V_41 -> V_48 & V_82 ) {
F_42 ( V_37 , L_5 , V_24 -> V_41 -> V_77 ) ;
F_36 ( V_24 -> V_41 , V_70 , V_71 ) ;
V_70 = V_24 -> V_41 ;
V_71 = true ;
} else {
F_42 ( V_37 ,
L_6 ,
V_24 -> V_41 , V_24 -> V_41 -> V_48 ) ;
}
}
F_50 (gate, n, known_gates, list)
if ( V_24 -> V_41 -> V_37 == V_37 ) {
F_42 ( V_37 , L_7 , V_24 -> V_41 -> V_77 ) ;
F_97 ( V_24 -> V_41 ) ;
}
return ( V_70 == V_41 ) ? - V_136 : 0 ;
}
void F_100 ( struct V_44 * V_45 ,
struct V_36 * V_37 )
{
F_47 ( V_45 ) ;
V_37 -> V_90 . V_91 . V_137 . V_138 ++ ;
}
void F_101 ( struct V_40 * V_41 )
{
struct V_44 * V_45 ;
while ( ( V_45 = F_102 ( & V_41 -> V_50 ) ) != NULL )
F_100 ( V_45 , V_41 -> V_37 ) ;
}
void F_103 ( struct V_40 * V_41 , struct V_42 * V_49 )
{
F_14 ( & V_41 -> V_81 ) ;
F_25 ( V_41 , V_49 ) ;
V_41 -> V_129 = 0xffff ;
V_41 -> V_139 = 0 ;
V_41 -> V_140 = 0 ;
V_41 -> V_113 = 0 ;
V_41 -> V_48 |= V_128 ;
F_104 ( V_41 ) ;
F_17 ( & V_41 -> V_81 ) ;
F_97 ( V_41 ) ;
}
static void F_105 ( struct V_20 * V_21 , bool V_18 )
{
struct V_40 * V_41 ;
struct V_23 * V_80 = F_106 ( V_21 , struct V_23 , V_26 ) ;
V_41 = V_80 -> V_41 ;
F_60 ( V_21 ) ;
if ( V_18 ) {
F_90 ( & V_41 -> V_110 ) ;
F_8 ( V_41 ) ;
}
F_8 ( V_80 ) ;
}
static int F_107 ( struct V_20 * V_21 , struct V_1 * V_7 )
{
struct V_40 * V_41 ;
struct V_23 * V_80 , * V_99 ;
T_1 V_101 ;
V_99 = F_6 ( sizeof( struct V_23 ) , V_8 ) ;
if ( V_99 == NULL )
return - V_34 ;
V_80 = F_106 ( V_21 , struct V_23 , V_26 ) ;
V_41 = V_80 -> V_41 ;
V_99 -> V_41 = V_41 ;
V_101 = F_23 ( V_41 -> V_77 , V_41 -> V_37 , V_7 ) ;
F_108 ( & V_99 -> V_26 ,
& V_7 -> V_9 [ V_101 ] ) ;
return 0 ;
}
int F_109 ( void )
{
struct V_1 * V_141 , * V_142 ;
int V_143 ;
V_141 = F_5 ( V_144 ) ;
if ( ! V_141 )
return - V_34 ;
V_141 -> V_25 = & F_105 ;
V_141 -> V_32 = & F_107 ;
V_141 -> V_30 = V_145 ;
V_141 -> V_27 = F_7 ( sizeof( struct V_10 ) , V_8 ) ;
if ( ! V_141 -> V_27 ) {
V_143 = - V_34 ;
goto V_146;
}
F_110 ( V_141 -> V_27 ) ;
V_142 = F_5 ( V_144 ) ;
if ( ! V_142 ) {
V_143 = - V_34 ;
goto V_146;
}
V_142 -> V_25 = & F_105 ;
V_142 -> V_32 = & F_107 ;
V_142 -> V_30 = V_145 ;
V_142 -> V_27 = F_7 ( sizeof( struct V_10 ) , V_8 ) ;
if ( ! V_142 -> V_27 ) {
V_143 = - V_34 ;
goto V_147;
}
F_110 ( V_142 -> V_27 ) ;
F_111 ( V_2 , V_141 ) ;
F_111 ( V_4 , V_142 ) ;
return 0 ;
V_147:
F_13 ( V_142 , true ) ;
V_146:
F_13 ( V_141 , true ) ;
return V_143 ;
}
void F_112 ( struct V_36 * V_37 )
{
struct V_1 * V_17 ;
struct V_40 * V_41 ;
struct V_23 * V_80 ;
struct V_20 * V_21 ;
int V_6 ;
F_33 () ;
V_17 = F_34 ( V_2 ) ;
F_56 (tbl, p, node, i) {
if ( V_80 -> V_41 -> V_37 != V_37 )
continue;
V_41 = V_80 -> V_41 ;
if ( ( ! ( V_41 -> V_48 & V_133 ) ) &&
( ! ( V_41 -> V_48 & V_128 ) ) &&
F_113 ( V_114 , V_41 -> V_113 + V_148 ) )
F_96 ( V_41 -> V_77 , V_41 -> V_37 ) ;
}
F_35 () ;
}
void F_114 ( void )
{
F_13 ( F_2 ( V_2 , 1 ) , true ) ;
F_13 ( F_2 ( V_4 , 1 ) , true ) ;
}
