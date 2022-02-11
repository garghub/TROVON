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
struct V_48 V_49 ;
unsigned long V_50 ;
F_26 ( V_41 -> V_51 , V_43 ) ;
F_27 ( & V_49 ) ;
F_28 ( & V_41 -> V_52 . V_53 , V_50 ) ;
while ( ( V_45 = F_29 ( & V_41 -> V_52 ) ) != NULL ) {
V_47 = (struct V_46 * ) V_45 -> V_54 ;
memcpy ( V_47 -> V_55 , V_43 -> V_43 . V_35 , V_56 ) ;
memcpy ( V_47 -> V_57 , V_41 -> V_37 -> V_58 . V_35 , V_56 ) ;
F_30 ( & V_49 , V_45 ) ;
}
F_31 ( & V_49 , & V_41 -> V_52 ) ;
F_32 ( & V_41 -> V_52 . V_53 , V_50 ) ;
}
static void F_33 ( struct V_44 * V_45 , char * V_59 ,
struct V_40 * V_60 )
{
struct V_46 * V_47 ;
struct V_61 * V_62 ;
int V_63 , V_64 ;
char * V_51 ;
V_47 = (struct V_46 * ) V_45 -> V_54 ;
V_64 = F_34 ( V_47 -> V_65 ) ;
V_62 = (struct V_61 * ) ( V_45 -> V_54 + V_64 ) ;
if ( ! ( V_62 -> V_50 & V_66 ) ) {
V_63 = 6 ;
F_35 ( V_45 , 2 * V_56 ) ;
memmove ( V_45 -> V_54 , V_47 , V_64 + V_63 ) ;
V_47 = (struct V_46 * ) V_45 -> V_54 ;
V_62 = (struct V_61 * ) ( V_45 -> V_54 + V_64 ) ;
V_62 -> V_50 = V_67 ;
memcpy ( V_62 -> V_68 , V_47 -> V_69 , V_56 ) ;
memcpy ( V_62 -> V_70 , V_47 -> V_71 , V_56 ) ;
}
V_47 = (struct V_46 * ) V_45 -> V_54 ;
F_36 () ;
V_51 = F_37 ( V_60 -> V_51 ) -> V_43 . V_35 ;
memcpy ( V_47 -> V_55 , V_51 , V_56 ) ;
F_38 () ;
memcpy ( V_47 -> V_57 , V_60 -> V_37 -> V_58 . V_35 , V_56 ) ;
memcpy ( V_47 -> V_69 , V_59 , V_56 ) ;
}
static void F_39 ( struct V_40 * V_60 ,
struct V_40 * V_72 ,
bool V_73 )
{
struct V_44 * V_45 , * V_74 = NULL ;
struct V_48 V_75 , V_76 ;
unsigned long V_50 ;
int V_77 ;
F_40 ( V_60 == V_72 ) ;
F_40 ( ! V_60 -> V_51 ) ;
F_27 ( & V_75 ) ;
F_27 ( & V_76 ) ;
F_28 ( & V_72 -> V_52 . V_53 , V_50 ) ;
F_41 ( & V_72 -> V_52 , & V_76 ) ;
F_32 ( & V_72 -> V_52 . V_53 , V_50 ) ;
V_77 = F_42 ( & V_76 ) ;
while ( V_77 -- ) {
V_45 = F_29 ( & V_76 ) ;
if ( V_73 ) {
V_74 = F_43 ( V_45 , V_8 ) ;
if ( V_74 )
F_30 ( & V_76 , V_74 ) ;
}
F_33 ( V_45 , V_60 -> V_78 , V_60 ) ;
F_30 ( & V_75 , V_45 ) ;
}
F_28 ( & V_60 -> V_52 . V_53 , V_50 ) ;
F_31 ( & V_75 , & V_60 -> V_52 ) ;
F_44 ( V_60 -> V_37 , L_1 ,
V_60 -> V_78 , F_42 ( & V_60 -> V_52 ) ) ;
F_32 ( & V_60 -> V_52 . V_53 , V_50 ) ;
if ( ! V_73 )
return;
F_28 ( & V_72 -> V_52 . V_53 , V_50 ) ;
F_31 ( & V_76 , & V_72 -> V_52 ) ;
F_32 ( & V_72 -> V_52 . V_53 , V_50 ) ;
}
static struct V_40 * F_45 ( struct V_1 * V_17 , T_2 * V_78 ,
struct V_36 * V_37 )
{
struct V_40 * V_41 ;
struct V_20 * V_79 ;
struct V_10 * V_80 ;
struct V_23 * V_81 ;
V_80 = & V_17 -> V_9 [ F_23 ( V_78 , V_37 , V_17 ) ] ;
F_46 (node, n, bucket, list) {
V_41 = V_81 -> V_41 ;
if ( V_41 -> V_37 == V_37 &&
F_47 ( V_78 , V_41 -> V_78 ) ) {
if ( F_48 ( V_41 ) ) {
F_14 ( & V_41 -> V_82 ) ;
V_41 -> V_50 &= ~ V_83 ;
F_17 ( & V_41 -> V_82 ) ;
}
return V_41 ;
}
}
return NULL ;
}
struct V_40 * F_49 ( T_2 * V_78 , struct V_36 * V_37 )
{
return F_45 ( F_37 ( V_2 ) , V_78 , V_37 ) ;
}
struct V_40 * F_50 ( T_2 * V_78 , struct V_36 * V_37 )
{
return F_45 ( F_37 ( V_4 ) , V_78 , V_37 ) ;
}
struct V_40 * F_51 ( int V_84 , struct V_36 * V_37 )
{
struct V_1 * V_17 = F_37 ( V_2 ) ;
struct V_23 * V_81 ;
struct V_20 * V_21 ;
int V_6 ;
int V_85 = 0 ;
F_52 (tbl, p, node, i) {
if ( V_37 && V_81 -> V_41 -> V_37 != V_37 )
continue;
if ( V_85 ++ == V_84 ) {
if ( F_48 ( V_81 -> V_41 ) ) {
F_14 ( & V_81 -> V_41 -> V_82 ) ;
V_81 -> V_41 -> V_50 &= ~ V_83 ;
F_17 ( & V_81 -> V_41 -> V_82 ) ;
}
return V_81 -> V_41 ;
}
}
return NULL ;
}
int F_53 ( struct V_40 * V_41 )
{
struct V_1 * V_17 ;
struct V_23 * V_24 , * V_86 ;
struct V_20 * V_79 ;
int V_87 ;
F_36 () ;
V_17 = F_37 ( V_2 ) ;
F_46 (gate, n, tbl->known_gates, list)
if ( V_24 -> V_41 == V_41 ) {
V_87 = - V_88 ;
goto V_89;
}
V_86 = F_7 ( sizeof( struct V_23 ) , V_8 ) ;
if ( ! V_86 ) {
V_87 = - V_34 ;
goto V_89;
}
V_41 -> V_90 = true ;
V_41 -> V_37 -> V_91 . V_92 . V_93 ++ ;
V_86 -> V_41 = V_41 ;
F_14 ( & V_17 -> V_16 ) ;
F_54 ( & V_86 -> V_26 , V_17 -> V_27 ) ;
F_17 ( & V_17 -> V_16 ) ;
F_38 () ;
F_44 ( V_41 -> V_37 ,
L_2 ,
V_41 -> V_78 , V_41 -> V_37 -> V_91 . V_92 . V_93 ) ;
return 0 ;
V_89:
F_38 () ;
return V_87 ;
}
static int F_55 ( struct V_1 * V_17 , struct V_40 * V_41 )
{
struct V_23 * V_24 ;
struct V_20 * V_21 , * V_22 ;
F_18 (gate, p, q, tbl->known_gates, list)
if ( V_24 -> V_41 == V_41 ) {
F_14 ( & V_17 -> V_16 ) ;
F_56 ( & V_24 -> V_26 ) ;
F_57 ( V_24 , V_94 ) ;
F_17 ( & V_17 -> V_16 ) ;
V_41 -> V_37 -> V_91 . V_92 . V_93 -- ;
V_41 -> V_90 = false ;
F_44 ( V_41 -> V_37 ,
L_3 ,
V_41 -> V_78 , V_41 -> V_37 -> V_91 . V_92 . V_93 ) ;
break;
}
return 0 ;
}
int F_58 ( struct V_36 * V_37 )
{
return V_37 -> V_91 . V_92 . V_93 ;
}
int F_59 ( T_2 * V_78 , struct V_36 * V_37 )
{
struct V_95 * V_96 = & V_37 -> V_91 . V_92 ;
struct V_97 * V_98 = V_37 -> V_98 ;
struct V_1 * V_17 ;
struct V_40 * V_41 , * V_99 ;
struct V_23 * V_81 , * V_100 ;
struct V_10 * V_80 ;
struct V_20 * V_79 ;
int V_101 = 0 ;
int V_87 = 0 ;
T_1 V_102 ;
if ( F_47 ( V_78 , V_37 -> V_58 . V_35 ) )
return - V_103 ;
if ( F_60 ( V_78 ) )
return - V_103 ;
if ( F_61 ( & V_37 -> V_91 . V_92 . V_104 , 1 , V_105 ) == 0 )
return - V_106 ;
V_87 = - V_34 ;
V_99 = F_7 ( sizeof( struct V_40 ) , V_8 ) ;
if ( ! V_99 )
goto V_107;
V_100 = F_6 ( sizeof( struct V_23 ) , V_8 ) ;
if ( ! V_100 )
goto V_108;
F_62 ( & V_3 ) ;
memcpy ( V_99 -> V_78 , V_78 , V_56 ) ;
memset ( V_99 -> V_109 , 0xff , V_56 ) ;
V_99 -> V_110 = false ;
V_99 -> V_37 = V_37 ;
V_99 -> V_50 = 0 ;
F_63 ( & V_99 -> V_52 ) ;
V_100 -> V_41 = V_99 ;
V_99 -> V_111 . V_54 = ( unsigned long ) V_99 ;
V_99 -> V_111 . V_112 = V_113 ;
V_99 -> V_114 = V_115 ;
F_11 ( & V_99 -> V_82 ) ;
F_64 ( & V_99 -> V_111 ) ;
V_17 = F_1 () ;
V_102 = F_23 ( V_78 , V_37 , V_17 ) ;
V_80 = & V_17 -> V_9 [ V_102 ] ;
F_65 ( & V_17 -> V_11 [ V_102 ] ) ;
V_87 = - V_88 ;
F_66 (node, n, bucket, list) {
V_41 = V_81 -> V_41 ;
if ( V_41 -> V_37 == V_37 &&
F_47 ( V_78 , V_41 -> V_78 ) )
goto V_116;
}
F_54 ( & V_100 -> V_26 , V_80 ) ;
if ( F_67 ( & V_17 -> V_14 ) >=
V_17 -> V_30 * ( V_17 -> V_13 + 1 ) )
V_101 = 1 ;
V_117 ++ ;
F_68 ( & V_17 -> V_11 [ V_102 ] ) ;
F_69 ( & V_3 ) ;
if ( V_101 ) {
F_70 ( V_118 , & V_96 -> V_119 ) ;
F_71 ( & V_98 -> V_120 , & V_37 -> V_121 ) ;
}
return 0 ;
V_116:
F_68 ( & V_17 -> V_11 [ V_102 ] ) ;
F_69 ( & V_3 ) ;
F_8 ( V_100 ) ;
V_108:
F_8 ( V_99 ) ;
V_107:
F_16 ( & V_37 -> V_91 . V_92 . V_104 ) ;
return V_87 ;
}
static void F_72 ( struct V_122 * V_94 )
{
struct V_1 * V_17 = F_73 ( V_94 , struct V_1 , V_122 ) ;
F_13 ( V_17 , false ) ;
}
void F_74 ( void )
{
struct V_1 * V_28 , * V_7 ;
F_75 ( & V_3 ) ;
V_28 = F_1 () ;
V_7 = F_5 ( V_28 -> V_5 + 1 ) ;
if ( ! V_7 )
goto V_123;
if ( F_20 ( V_28 , V_7 ) < 0 ) {
F_12 ( V_7 ) ;
goto V_123;
}
F_26 ( V_2 , V_7 ) ;
F_76 ( & V_28 -> V_122 , F_72 ) ;
V_123:
F_77 ( & V_3 ) ;
}
void F_78 ( void )
{
struct V_1 * V_28 , * V_7 ;
F_75 ( & V_3 ) ;
V_28 = F_4 () ;
V_7 = F_5 ( V_28 -> V_5 + 1 ) ;
if ( ! V_7 )
goto V_123;
if ( F_20 ( V_28 , V_7 ) < 0 ) {
F_12 ( V_7 ) ;
goto V_123;
}
F_26 ( V_4 , V_7 ) ;
F_76 ( & V_28 -> V_122 , F_72 ) ;
V_123:
F_77 ( & V_3 ) ;
}
int F_79 ( T_2 * V_78 , T_2 * V_124 , struct V_36 * V_37 )
{
struct V_95 * V_96 = & V_37 -> V_91 . V_92 ;
struct V_97 * V_98 = V_37 -> V_98 ;
struct V_1 * V_17 ;
struct V_40 * V_41 , * V_99 ;
struct V_23 * V_81 , * V_100 ;
struct V_10 * V_80 ;
struct V_20 * V_79 ;
int V_101 = 0 ;
int V_87 = 0 ;
T_1 V_102 ;
if ( F_47 ( V_78 , V_37 -> V_58 . V_35 ) )
return - V_103 ;
if ( F_60 ( V_78 ) )
return - V_103 ;
V_87 = - V_34 ;
V_99 = F_7 ( sizeof( struct V_40 ) , V_8 ) ;
if ( ! V_99 )
goto V_107;
V_100 = F_6 ( sizeof( struct V_23 ) , V_8 ) ;
if ( ! V_100 )
goto V_108;
F_62 ( & V_3 ) ;
memcpy ( V_99 -> V_78 , V_78 , V_56 ) ;
memcpy ( V_99 -> V_124 , V_124 , V_56 ) ;
V_99 -> V_37 = V_37 ;
V_99 -> V_50 = 0 ;
F_63 ( & V_99 -> V_52 ) ;
V_100 -> V_41 = V_99 ;
F_64 ( & V_99 -> V_111 ) ;
V_99 -> V_114 = V_115 ;
F_11 ( & V_99 -> V_82 ) ;
V_17 = F_4 () ;
V_102 = F_23 ( V_78 , V_37 , V_17 ) ;
V_80 = & V_17 -> V_9 [ V_102 ] ;
F_65 ( & V_17 -> V_11 [ V_102 ] ) ;
V_87 = - V_88 ;
F_66 (node, n, bucket, list) {
V_41 = V_81 -> V_41 ;
if ( V_41 -> V_37 == V_37 &&
F_47 ( V_78 , V_41 -> V_78 ) )
goto V_116;
}
F_54 ( & V_100 -> V_26 , V_80 ) ;
if ( F_67 ( & V_17 -> V_14 ) >=
V_17 -> V_30 * ( V_17 -> V_13 + 1 ) )
V_101 = 1 ;
F_68 ( & V_17 -> V_11 [ V_102 ] ) ;
F_69 ( & V_3 ) ;
if ( V_101 ) {
F_70 ( V_125 , & V_96 -> V_119 ) ;
F_71 ( & V_98 -> V_120 , & V_37 -> V_121 ) ;
}
return 0 ;
V_116:
F_68 ( & V_17 -> V_11 [ V_102 ] ) ;
F_69 ( & V_3 ) ;
F_8 ( V_100 ) ;
V_108:
F_8 ( V_99 ) ;
V_107:
return V_87 ;
}
void F_80 ( struct V_42 * V_43 )
{
struct V_1 * V_17 ;
static const T_2 V_126 [ V_56 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
struct V_40 * V_41 ;
struct V_23 * V_81 ;
struct V_20 * V_21 ;
struct V_36 * V_37 = V_43 -> V_37 ;
int V_6 ;
T_3 V_127 = F_81 ( V_128 ) ;
F_36 () ;
V_17 = F_37 ( V_2 ) ;
F_52 (tbl, p, node, i) {
V_41 = V_81 -> V_41 ;
if ( F_37 ( V_41 -> V_51 ) == V_43 &&
V_41 -> V_50 & V_83 &&
! ( V_41 -> V_50 & V_129 ) ) {
F_14 ( & V_41 -> V_82 ) ;
V_41 -> V_50 &= ~ V_83 ;
++ V_41 -> V_130 ;
F_17 ( & V_41 -> V_82 ) ;
F_82 ( V_37 -> V_91 . V_92 . V_131 . V_132 ,
V_41 -> V_78 , F_83 ( V_41 -> V_130 ) ,
V_127 , V_126 , V_37 ) ;
}
}
F_38 () ;
}
static void F_84 ( struct V_122 * V_133 )
{
struct V_23 * V_81 = F_73 ( V_133 , struct V_23 , V_94 ) ;
struct V_36 * V_37 = V_81 -> V_41 -> V_37 ;
F_85 ( & V_81 -> V_41 -> V_111 ) ;
F_16 ( & V_37 -> V_91 . V_92 . V_104 ) ;
F_8 ( V_81 -> V_41 ) ;
F_8 ( V_81 ) ;
}
static void F_86 ( struct V_1 * V_17 , struct V_23 * V_81 )
{
struct V_40 * V_41 ;
V_41 = V_81 -> V_41 ;
F_65 ( & V_41 -> V_82 ) ;
V_41 -> V_50 |= V_134 ;
if ( V_41 -> V_90 )
F_55 ( V_17 , V_41 ) ;
F_56 ( & V_81 -> V_26 ) ;
F_76 ( & V_81 -> V_94 , F_84 ) ;
F_68 ( & V_41 -> V_82 ) ;
F_16 ( & V_17 -> V_14 ) ;
}
void F_87 ( struct V_42 * V_43 )
{
struct V_1 * V_17 ;
struct V_40 * V_41 ;
struct V_23 * V_81 ;
struct V_20 * V_21 ;
int V_6 ;
F_36 () ;
F_62 ( & V_3 ) ;
V_17 = F_1 () ;
F_52 (tbl, p, node, i) {
V_41 = V_81 -> V_41 ;
if ( F_37 ( V_41 -> V_51 ) == V_43 ) {
F_65 ( & V_17 -> V_11 [ V_6 ] ) ;
F_86 ( V_17 , V_81 ) ;
F_68 ( & V_17 -> V_11 [ V_6 ] ) ;
}
}
F_69 ( & V_3 ) ;
F_38 () ;
}
static void F_88 ( struct V_1 * V_17 ,
struct V_36 * V_37 )
{
struct V_40 * V_41 ;
struct V_23 * V_81 ;
struct V_20 * V_21 ;
int V_6 ;
F_89 ( ! F_90 () ) ;
F_52 (tbl, p, node, i) {
V_41 = V_81 -> V_41 ;
if ( V_41 -> V_37 != V_37 )
continue;
F_14 ( & V_17 -> V_11 [ V_6 ] ) ;
F_86 ( V_17 , V_81 ) ;
F_17 ( & V_17 -> V_11 [ V_6 ] ) ;
}
}
void F_91 ( struct V_36 * V_37 )
{
struct V_1 * V_17 ;
F_36 () ;
F_62 ( & V_3 ) ;
V_17 = F_1 () ;
F_88 ( V_17 , V_37 ) ;
V_17 = F_4 () ;
F_88 ( V_17 , V_37 ) ;
F_69 ( & V_3 ) ;
F_38 () ;
}
int F_92 ( T_2 * V_35 , struct V_36 * V_37 )
{
struct V_1 * V_17 ;
struct V_40 * V_41 ;
struct V_23 * V_81 ;
struct V_10 * V_80 ;
struct V_20 * V_79 ;
int V_102 ;
int V_87 = 0 ;
F_62 ( & V_3 ) ;
V_17 = F_1 () ;
V_102 = F_23 ( V_35 , V_37 , V_17 ) ;
V_80 = & V_17 -> V_9 [ V_102 ] ;
F_65 ( & V_17 -> V_11 [ V_102 ] ) ;
F_66 (node, n, bucket, list) {
V_41 = V_81 -> V_41 ;
if ( V_41 -> V_37 == V_37 &&
F_47 ( V_35 , V_41 -> V_78 ) ) {
F_86 ( V_17 , V_81 ) ;
goto V_135;
}
}
V_87 = - V_136 ;
V_135:
V_117 ++ ;
F_68 ( & V_17 -> V_11 [ V_102 ] ) ;
F_69 ( & V_3 ) ;
return V_87 ;
}
void F_93 ( struct V_40 * V_41 )
{
if ( V_41 -> V_50 & V_83 )
F_94 ( V_41 -> V_37 -> V_98 ,
& V_41 -> V_52 ) ;
}
int F_95 ( struct V_40 * V_41 )
{
struct V_36 * V_37 = V_41 -> V_37 ;
struct V_20 * V_79 ;
struct V_1 * V_17 ;
struct V_40 * V_72 = V_41 ;
struct V_23 * V_24 = NULL ;
bool V_73 = false ;
struct V_10 * V_27 ;
F_36 () ;
V_17 = F_37 ( V_2 ) ;
V_27 = V_17 -> V_27 ;
F_38 () ;
if ( ! V_27 )
return - V_137 ;
F_46 (gate, n, known_gates, list) {
if ( V_24 -> V_41 -> V_37 != V_37 )
continue;
if ( V_24 -> V_41 -> V_50 & V_83 ) {
F_44 ( V_37 , L_4 , V_24 -> V_41 -> V_78 ) ;
F_39 ( V_24 -> V_41 , V_72 , V_73 ) ;
V_72 = V_24 -> V_41 ;
V_73 = true ;
} else {
F_44 ( V_37 ,
L_5 ,
V_24 -> V_41 , V_24 -> V_41 -> V_50 ) ;
}
}
F_46 (gate, n, known_gates, list)
if ( V_24 -> V_41 -> V_37 == V_37 ) {
F_44 ( V_37 , L_6 , V_24 -> V_41 -> V_78 ) ;
F_93 ( V_24 -> V_41 ) ;
}
return ( V_72 == V_41 ) ? - V_137 : 0 ;
}
void F_96 ( struct V_44 * V_45 ,
struct V_36 * V_37 )
{
F_97 ( V_45 ) ;
V_37 -> V_91 . V_92 . V_138 . V_139 ++ ;
}
void F_98 ( struct V_40 * V_41 )
{
struct V_44 * V_45 ;
while ( ( V_45 = F_99 ( & V_41 -> V_52 ) ) != NULL )
F_96 ( V_45 , V_41 -> V_37 ) ;
}
void F_100 ( struct V_40 * V_41 , struct V_42 * V_51 )
{
F_14 ( & V_41 -> V_82 ) ;
F_25 ( V_41 , V_51 ) ;
V_41 -> V_130 = 0xffff ;
V_41 -> V_140 = 0 ;
V_41 -> V_141 = 0 ;
V_41 -> V_114 = 0 ;
V_41 -> V_50 |= V_129 ;
F_101 ( V_41 ) ;
F_17 ( & V_41 -> V_82 ) ;
F_93 ( V_41 ) ;
}
static void F_102 ( struct V_20 * V_21 , bool V_18 )
{
struct V_40 * V_41 ;
struct V_23 * V_81 = F_103 ( V_21 , struct V_23 , V_26 ) ;
V_41 = V_81 -> V_41 ;
F_56 ( V_21 ) ;
if ( V_18 ) {
F_85 ( & V_41 -> V_111 ) ;
F_8 ( V_41 ) ;
}
F_8 ( V_81 ) ;
}
static int F_104 ( struct V_20 * V_21 , struct V_1 * V_7 )
{
struct V_40 * V_41 ;
struct V_23 * V_81 , * V_100 ;
T_1 V_102 ;
V_100 = F_6 ( sizeof( struct V_23 ) , V_8 ) ;
if ( V_100 == NULL )
return - V_34 ;
V_81 = F_103 ( V_21 , struct V_23 , V_26 ) ;
V_41 = V_81 -> V_41 ;
V_100 -> V_41 = V_41 ;
V_102 = F_23 ( V_41 -> V_78 , V_41 -> V_37 , V_7 ) ;
F_105 ( & V_100 -> V_26 ,
& V_7 -> V_9 [ V_102 ] ) ;
return 0 ;
}
int F_106 ( void )
{
struct V_1 * V_142 , * V_143 ;
int V_144 ;
V_142 = F_5 ( V_145 ) ;
if ( ! V_142 )
return - V_34 ;
V_142 -> V_25 = & F_102 ;
V_142 -> V_32 = & F_104 ;
V_142 -> V_30 = V_146 ;
V_142 -> V_27 = F_7 ( sizeof( struct V_10 ) , V_8 ) ;
if ( ! V_142 -> V_27 ) {
V_144 = - V_34 ;
goto V_147;
}
F_107 ( V_142 -> V_27 ) ;
V_143 = F_5 ( V_145 ) ;
if ( ! V_143 ) {
V_144 = - V_34 ;
goto V_147;
}
V_143 -> V_25 = & F_102 ;
V_143 -> V_32 = & F_104 ;
V_143 -> V_30 = V_146 ;
V_143 -> V_27 = F_7 ( sizeof( struct V_10 ) , V_8 ) ;
if ( ! V_143 -> V_27 ) {
V_144 = - V_34 ;
goto V_148;
}
F_107 ( V_143 -> V_27 ) ;
F_108 ( V_2 , V_142 ) ;
F_108 ( V_4 , V_143 ) ;
return 0 ;
V_148:
F_13 ( V_143 , true ) ;
V_147:
F_13 ( V_142 , true ) ;
return V_144 ;
}
void F_109 ( struct V_36 * V_37 )
{
struct V_1 * V_17 ;
struct V_40 * V_41 ;
struct V_23 * V_81 ;
struct V_20 * V_21 ;
int V_6 ;
F_36 () ;
V_17 = F_37 ( V_2 ) ;
F_52 (tbl, p, node, i) {
if ( V_81 -> V_41 -> V_37 != V_37 )
continue;
V_41 = V_81 -> V_41 ;
if ( ( ! ( V_41 -> V_50 & V_134 ) ) &&
( ! ( V_41 -> V_50 & V_129 ) ) &&
F_110 ( V_115 , V_41 -> V_114 + V_149 ) )
F_92 ( V_41 -> V_78 , V_41 -> V_37 ) ;
}
F_38 () ;
}
void F_111 ( void )
{
F_13 ( F_2 ( V_2 , 1 ) , true ) ;
F_13 ( F_2 ( V_4 , 1 ) , true ) ;
}
