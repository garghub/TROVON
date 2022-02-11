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
struct V_36 * V_37 = V_41 -> V_37 ;
F_26 ( V_41 -> V_51 , V_43 ) ;
F_27 ( & V_49 ) ;
F_28 ( & V_41 -> V_52 . V_53 , V_50 ) ;
while ( ( V_45 = F_29 ( & V_41 -> V_52 ) ) != NULL ) {
V_47 = (struct V_46 * ) V_45 -> V_54 ;
memcpy ( V_47 -> V_55 , V_43 -> V_43 . V_35 , V_56 ) ;
F_30 ( V_45 , F_31 ( V_37 , V_45 ) ) ;
F_32 ( V_37 , V_45 ) ;
F_33 ( & V_49 , V_45 ) ;
}
F_34 ( & V_49 , & V_41 -> V_52 ) ;
F_35 ( & V_41 -> V_52 . V_53 , V_50 ) ;
}
static void F_36 ( struct V_44 * V_45 , char * V_57 ,
struct V_40 * V_58 )
{
struct V_46 * V_47 ;
struct V_59 * V_60 ;
int V_61 , V_62 ;
char * V_51 ;
V_47 = (struct V_46 * ) V_45 -> V_54 ;
V_62 = F_37 ( V_47 -> V_63 ) ;
V_60 = (struct V_59 * ) ( V_45 -> V_54 + V_62 ) ;
if ( ! ( V_60 -> V_50 & V_64 ) ) {
V_61 = 6 ;
F_38 ( V_45 , 2 * V_56 ) ;
memmove ( V_45 -> V_54 , V_47 , V_62 + V_61 ) ;
V_47 = (struct V_46 * ) V_45 -> V_54 ;
V_60 = (struct V_59 * ) ( V_45 -> V_54 + V_62 ) ;
V_60 -> V_50 = V_65 ;
memcpy ( V_60 -> V_66 , V_47 -> V_67 , V_56 ) ;
memcpy ( V_60 -> V_68 , V_47 -> V_69 , V_56 ) ;
}
V_47 = (struct V_46 * ) V_45 -> V_54 ;
F_39 () ;
V_51 = F_40 ( V_58 -> V_51 ) -> V_43 . V_35 ;
memcpy ( V_47 -> V_55 , V_51 , V_56 ) ;
F_41 () ;
memcpy ( V_47 -> V_67 , V_57 , V_56 ) ;
}
static void F_42 ( struct V_40 * V_58 ,
struct V_40 * V_70 ,
bool V_71 )
{
struct V_44 * V_45 , * V_72 = NULL ;
struct V_48 V_73 , V_74 ;
unsigned long V_50 ;
int V_75 ;
F_43 ( V_58 == V_70 ) ;
F_43 ( ! V_58 -> V_51 ) ;
F_27 ( & V_73 ) ;
F_27 ( & V_74 ) ;
F_28 ( & V_70 -> V_52 . V_53 , V_50 ) ;
F_44 ( & V_70 -> V_52 , & V_74 ) ;
F_35 ( & V_70 -> V_52 . V_53 , V_50 ) ;
V_75 = F_45 ( & V_74 ) ;
while ( V_75 -- ) {
V_45 = F_29 ( & V_74 ) ;
if ( V_71 ) {
V_72 = F_46 ( V_45 , V_8 ) ;
if ( V_72 )
F_33 ( & V_74 , V_72 ) ;
}
F_36 ( V_45 , V_58 -> V_76 , V_58 ) ;
F_33 ( & V_73 , V_45 ) ;
}
F_28 ( & V_58 -> V_52 . V_53 , V_50 ) ;
F_34 ( & V_73 , & V_58 -> V_52 ) ;
F_47 ( L_1 ,
V_58 -> V_76 ,
F_45 ( & V_58 -> V_52 ) ) ;
F_35 ( & V_58 -> V_52 . V_53 , V_50 ) ;
if ( ! V_71 )
return;
F_28 ( & V_70 -> V_52 . V_53 , V_50 ) ;
F_34 ( & V_74 , & V_70 -> V_52 ) ;
F_35 ( & V_70 -> V_52 . V_53 , V_50 ) ;
}
static struct V_40 * F_48 ( struct V_1 * V_17 , T_2 * V_76 ,
struct V_36 * V_37 )
{
struct V_40 * V_41 ;
struct V_20 * V_77 ;
struct V_10 * V_78 ;
struct V_23 * V_79 ;
V_78 = & V_17 -> V_9 [ F_23 ( V_76 , V_37 , V_17 ) ] ;
F_49 (node, n, bucket, list) {
V_41 = V_79 -> V_41 ;
if ( V_41 -> V_37 == V_37 &&
memcmp ( V_76 , V_41 -> V_76 , V_56 ) == 0 ) {
if ( F_50 ( V_41 ) ) {
F_14 ( & V_41 -> V_80 ) ;
V_41 -> V_50 &= ~ V_81 ;
F_17 ( & V_41 -> V_80 ) ;
}
return V_41 ;
}
}
return NULL ;
}
struct V_40 * F_51 ( T_2 * V_76 , struct V_36 * V_37 )
{
return F_48 ( F_40 ( V_2 ) , V_76 , V_37 ) ;
}
struct V_40 * F_52 ( T_2 * V_76 , struct V_36 * V_37 )
{
return F_48 ( F_40 ( V_4 ) , V_76 , V_37 ) ;
}
struct V_40 * F_53 ( int V_82 , struct V_36 * V_37 )
{
struct V_1 * V_17 = F_40 ( V_2 ) ;
struct V_23 * V_79 ;
struct V_20 * V_21 ;
int V_6 ;
int V_83 = 0 ;
F_54 (tbl, p, node, i) {
if ( V_37 && V_79 -> V_41 -> V_37 != V_37 )
continue;
if ( V_83 ++ == V_82 ) {
if ( F_50 ( V_79 -> V_41 ) ) {
F_14 ( & V_79 -> V_41 -> V_80 ) ;
V_79 -> V_41 -> V_50 &= ~ V_81 ;
F_17 ( & V_79 -> V_41 -> V_80 ) ;
}
return V_79 -> V_41 ;
}
}
return NULL ;
}
static void F_55 ( struct V_84 * V_85 )
{
struct V_23 * V_79 = F_56 ( V_85 , struct V_23 , V_86 ) ;
F_8 ( V_79 ) ;
}
static int F_57 ( struct V_1 * V_17 , struct V_40 * V_41 )
{
struct V_23 * V_24 , * V_87 ;
struct V_20 * V_77 ;
int V_88 ;
F_39 () ;
V_17 = F_40 ( V_17 ) ;
F_49 (gate, n, tbl->known_gates, list)
if ( V_24 -> V_41 == V_41 ) {
V_88 = - V_89 ;
goto V_90;
}
V_87 = F_7 ( sizeof( struct V_23 ) , V_8 ) ;
if ( ! V_87 ) {
V_88 = - V_34 ;
goto V_90;
}
V_41 -> V_91 = true ;
V_41 -> V_37 -> V_92 . V_93 . V_94 ++ ;
V_87 -> V_41 = V_41 ;
F_14 ( & V_17 -> V_16 ) ;
F_58 ( & V_87 -> V_26 , V_17 -> V_27 ) ;
F_17 ( & V_17 -> V_16 ) ;
F_41 () ;
F_47 ( L_2 ,
V_41 -> V_37 -> V_95 , V_41 -> V_76 ,
V_41 -> V_37 -> V_92 . V_93 . V_94 ) ;
return 0 ;
V_90:
F_41 () ;
return V_88 ;
}
static int F_59 ( struct V_1 * V_17 , struct V_40 * V_41 )
{
struct V_23 * V_24 ;
struct V_20 * V_21 , * V_22 ;
V_17 = F_40 ( V_17 ) ;
F_18 (gate, p, q, tbl->known_gates, list)
if ( V_24 -> V_41 == V_41 ) {
F_14 ( & V_17 -> V_16 ) ;
F_60 ( & V_24 -> V_26 ) ;
F_61 ( & V_24 -> V_86 , F_55 ) ;
F_17 ( & V_17 -> V_16 ) ;
V_41 -> V_37 -> V_92 . V_93 . V_94 -- ;
V_41 -> V_91 = false ;
F_47 ( L_3
L_4 , V_41 -> V_37 -> V_95 ,
V_41 -> V_76 , V_41 -> V_37 -> V_92 . V_93 . V_94 ) ;
break;
}
return 0 ;
}
int F_62 ( struct V_40 * V_41 )
{
return F_57 ( V_2 , V_41 ) ;
}
int F_63 ( struct V_36 * V_37 )
{
return V_37 -> V_92 . V_93 . V_94 ;
}
int F_64 ( T_2 * V_76 , struct V_36 * V_37 )
{
struct V_96 * V_97 = & V_37 -> V_92 . V_93 ;
struct V_98 * V_99 = V_37 -> V_99 ;
struct V_1 * V_17 ;
struct V_40 * V_41 , * V_100 ;
struct V_23 * V_79 , * V_101 ;
struct V_10 * V_78 ;
struct V_20 * V_77 ;
int V_102 = 0 ;
int V_88 = 0 ;
T_1 V_103 ;
if ( memcmp ( V_76 , V_37 -> V_104 . V_35 , V_56 ) == 0 )
return - V_105 ;
if ( F_65 ( V_76 ) )
return - V_105 ;
if ( F_66 ( & V_37 -> V_92 . V_93 . V_106 , 1 , V_107 ) == 0 )
return - V_108 ;
V_88 = - V_34 ;
V_100 = F_7 ( sizeof( struct V_40 ) , V_8 ) ;
if ( ! V_100 )
goto V_109;
V_101 = F_6 ( sizeof( struct V_23 ) , V_8 ) ;
if ( ! V_101 )
goto V_110;
F_67 ( & V_3 ) ;
memcpy ( V_100 -> V_76 , V_76 , V_56 ) ;
V_100 -> V_37 = V_37 ;
V_100 -> V_50 = 0 ;
F_68 ( & V_100 -> V_52 ) ;
V_101 -> V_41 = V_100 ;
V_100 -> V_111 . V_54 = ( unsigned long ) V_100 ;
V_100 -> V_111 . V_112 = V_113 ;
V_100 -> V_114 = V_115 ;
F_11 ( & V_100 -> V_80 ) ;
F_69 ( & V_100 -> V_111 ) ;
V_17 = F_1 () ;
V_103 = F_23 ( V_76 , V_37 , V_17 ) ;
V_78 = & V_17 -> V_9 [ V_103 ] ;
F_14 ( & V_17 -> V_11 [ V_103 ] ) ;
V_88 = - V_89 ;
F_70 (node, n, bucket, list) {
V_41 = V_79 -> V_41 ;
if ( V_41 -> V_37 == V_37 && memcmp ( V_76 , V_41 -> V_76 , V_56 ) == 0 )
goto V_116;
}
F_58 ( & V_101 -> V_26 , V_78 ) ;
if ( F_71 ( & V_17 -> V_14 ) >=
V_17 -> V_30 * ( V_17 -> V_13 + 1 ) )
V_102 = 1 ;
V_117 ++ ;
F_17 ( & V_17 -> V_11 [ V_103 ] ) ;
F_72 ( & V_3 ) ;
if ( V_102 ) {
F_73 ( V_118 , & V_97 -> V_119 ) ;
F_74 ( & V_99 -> V_120 , & V_37 -> V_121 ) ;
}
return 0 ;
V_116:
F_17 ( & V_17 -> V_11 [ V_103 ] ) ;
F_72 ( & V_3 ) ;
F_8 ( V_101 ) ;
V_110:
F_8 ( V_100 ) ;
V_109:
F_16 ( & V_37 -> V_92 . V_93 . V_106 ) ;
return V_88 ;
}
static void F_75 ( struct V_84 * V_86 )
{
struct V_1 * V_17 = F_56 ( V_86 , struct V_1 , V_84 ) ;
F_13 ( V_17 , false ) ;
}
void F_76 ( void )
{
struct V_1 * V_28 , * V_7 ;
F_77 ( & V_3 ) ;
V_28 = F_1 () ;
V_7 = F_5 ( V_28 -> V_5 + 1 ) ;
if ( ! V_7 )
goto V_122;
if ( F_20 ( V_28 , V_7 ) < 0 ) {
F_12 ( V_7 ) ;
goto V_122;
}
F_26 ( V_2 , V_7 ) ;
F_61 ( & V_28 -> V_84 , F_75 ) ;
V_122:
F_78 ( & V_3 ) ;
}
void F_79 ( void )
{
struct V_1 * V_28 , * V_7 ;
F_77 ( & V_3 ) ;
V_28 = F_4 () ;
V_7 = F_5 ( V_28 -> V_5 + 1 ) ;
if ( ! V_7 )
goto V_122;
if ( F_20 ( V_28 , V_7 ) < 0 ) {
F_12 ( V_7 ) ;
goto V_122;
}
F_26 ( V_4 , V_7 ) ;
F_61 ( & V_28 -> V_84 , F_75 ) ;
V_122:
F_78 ( & V_3 ) ;
}
int F_80 ( T_2 * V_76 , T_2 * V_123 , struct V_36 * V_37 )
{
struct V_96 * V_97 = & V_37 -> V_92 . V_93 ;
struct V_98 * V_99 = V_37 -> V_99 ;
struct V_1 * V_17 ;
struct V_40 * V_41 , * V_100 ;
struct V_23 * V_79 , * V_101 ;
struct V_10 * V_78 ;
struct V_20 * V_77 ;
int V_102 = 0 ;
int V_88 = 0 ;
T_1 V_103 ;
if ( memcmp ( V_76 , V_37 -> V_104 . V_35 , V_56 ) == 0 )
return - V_105 ;
if ( F_65 ( V_76 ) )
return - V_105 ;
V_88 = - V_34 ;
V_100 = F_7 ( sizeof( struct V_40 ) , V_8 ) ;
if ( ! V_100 )
goto V_109;
V_101 = F_6 ( sizeof( struct V_23 ) , V_8 ) ;
if ( ! V_101 )
goto V_110;
F_67 ( & V_3 ) ;
memcpy ( V_100 -> V_76 , V_76 , V_56 ) ;
memcpy ( V_100 -> V_123 , V_123 , V_56 ) ;
V_100 -> V_37 = V_37 ;
V_100 -> V_50 = 0 ;
F_68 ( & V_100 -> V_52 ) ;
V_101 -> V_41 = V_100 ;
F_69 ( & V_100 -> V_111 ) ;
V_100 -> V_114 = V_115 ;
F_11 ( & V_100 -> V_80 ) ;
V_17 = F_4 () ;
V_103 = F_23 ( V_76 , V_37 , V_17 ) ;
V_78 = & V_17 -> V_9 [ V_103 ] ;
F_14 ( & V_17 -> V_11 [ V_103 ] ) ;
V_88 = - V_89 ;
F_70 (node, n, bucket, list) {
V_41 = V_79 -> V_41 ;
if ( V_41 -> V_37 == V_37 && memcmp ( V_76 , V_41 -> V_76 , V_56 ) == 0 )
goto V_116;
}
F_58 ( & V_101 -> V_26 , V_78 ) ;
if ( F_71 ( & V_17 -> V_14 ) >=
V_17 -> V_30 * ( V_17 -> V_13 + 1 ) )
V_102 = 1 ;
F_17 ( & V_17 -> V_11 [ V_103 ] ) ;
F_72 ( & V_3 ) ;
if ( V_102 ) {
F_73 ( V_124 , & V_97 -> V_119 ) ;
F_74 ( & V_99 -> V_120 , & V_37 -> V_121 ) ;
}
return 0 ;
V_116:
F_17 ( & V_17 -> V_11 [ V_103 ] ) ;
F_72 ( & V_3 ) ;
F_8 ( V_101 ) ;
V_110:
F_8 ( V_100 ) ;
V_109:
return V_88 ;
}
void F_81 ( struct V_42 * V_43 )
{
struct V_1 * V_17 ;
static const T_2 V_125 [ V_56 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
struct V_40 * V_41 ;
struct V_23 * V_79 ;
struct V_20 * V_21 ;
struct V_36 * V_37 = V_43 -> V_37 ;
int V_6 ;
T_3 V_126 = F_82 ( V_127 ) ;
F_39 () ;
V_17 = F_40 ( V_2 ) ;
F_54 (tbl, p, node, i) {
V_41 = V_79 -> V_41 ;
if ( F_40 ( V_41 -> V_51 ) == V_43 &&
V_41 -> V_50 & V_81 &&
! ( V_41 -> V_50 & V_128 ) ) {
F_14 ( & V_41 -> V_80 ) ;
V_41 -> V_50 &= ~ V_81 ;
++ V_41 -> V_129 ;
F_17 ( & V_41 -> V_80 ) ;
F_83 ( V_37 -> V_92 . V_93 . V_130 . V_131 ,
V_41 -> V_76 , F_84 ( V_41 -> V_129 ) ,
V_126 , V_125 , V_37 ) ;
}
}
F_41 () ;
}
static void F_85 ( struct V_84 * V_85 )
{
struct V_23 * V_79 = F_56 ( V_85 , struct V_23 , V_86 ) ;
struct V_36 * V_37 = V_79 -> V_41 -> V_37 ;
F_86 ( & V_79 -> V_41 -> V_111 ) ;
F_16 ( & V_37 -> V_92 . V_93 . V_106 ) ;
F_8 ( V_79 -> V_41 ) ;
F_8 ( V_79 ) ;
}
static void F_87 ( struct V_1 * V_17 , struct V_23 * V_79 )
{
struct V_40 * V_41 ;
V_41 = V_79 -> V_41 ;
F_88 ( & V_41 -> V_80 ) ;
V_41 -> V_50 |= V_132 ;
if ( V_41 -> V_91 )
F_59 ( V_17 , V_41 ) ;
F_60 ( & V_79 -> V_26 ) ;
F_61 ( & V_79 -> V_86 , F_85 ) ;
F_89 ( & V_41 -> V_80 ) ;
F_16 ( & V_17 -> V_14 ) ;
}
void F_90 ( struct V_42 * V_43 )
{
struct V_1 * V_17 ;
struct V_40 * V_41 ;
struct V_23 * V_79 ;
struct V_20 * V_21 ;
int V_6 ;
F_39 () ;
F_67 ( & V_3 ) ;
V_17 = F_1 () ;
F_54 (tbl, p, node, i) {
V_41 = V_79 -> V_41 ;
if ( F_40 ( V_41 -> V_51 ) == V_43 ) {
F_14 ( & V_17 -> V_11 [ V_6 ] ) ;
F_87 ( V_17 , V_79 ) ;
F_17 ( & V_17 -> V_11 [ V_6 ] ) ;
}
}
F_72 ( & V_3 ) ;
F_41 () ;
}
static void F_91 ( struct V_1 * V_17 ,
struct V_36 * V_37 )
{
struct V_40 * V_41 ;
struct V_23 * V_79 ;
struct V_20 * V_21 ;
int V_6 ;
F_92 ( ! F_93 () ) ;
F_54 (tbl, p, node, i) {
V_41 = V_79 -> V_41 ;
if ( V_41 -> V_37 != V_37 )
continue;
F_14 ( & V_17 -> V_11 [ V_6 ] ) ;
F_87 ( V_17 , V_79 ) ;
F_17 ( & V_17 -> V_11 [ V_6 ] ) ;
}
}
void F_94 ( struct V_36 * V_37 )
{
struct V_1 * V_17 ;
F_39 () ;
F_67 ( & V_3 ) ;
V_17 = F_1 () ;
F_91 ( V_17 , V_37 ) ;
V_17 = F_4 () ;
F_91 ( V_17 , V_37 ) ;
F_72 ( & V_3 ) ;
F_41 () ;
}
int F_95 ( T_2 * V_35 , struct V_36 * V_37 )
{
struct V_1 * V_17 ;
struct V_40 * V_41 ;
struct V_23 * V_79 ;
struct V_10 * V_78 ;
struct V_20 * V_77 ;
int V_103 ;
int V_88 = 0 ;
F_67 ( & V_3 ) ;
V_17 = F_1 () ;
V_103 = F_23 ( V_35 , V_37 , V_17 ) ;
V_78 = & V_17 -> V_9 [ V_103 ] ;
F_14 ( & V_17 -> V_11 [ V_103 ] ) ;
F_70 (node, n, bucket, list) {
V_41 = V_79 -> V_41 ;
if ( V_41 -> V_37 == V_37 &&
memcmp ( V_35 , V_41 -> V_76 , V_56 ) == 0 ) {
F_87 ( V_17 , V_79 ) ;
goto V_133;
}
}
V_88 = - V_134 ;
V_133:
V_117 ++ ;
F_17 ( & V_17 -> V_11 [ V_103 ] ) ;
F_72 ( & V_3 ) ;
return V_88 ;
}
void F_96 ( struct V_40 * V_41 )
{
if ( V_41 -> V_50 & V_81 )
F_97 ( V_41 -> V_37 -> V_99 ,
& V_41 -> V_52 ) ;
}
int F_98 ( struct V_40 * V_41 )
{
struct V_36 * V_37 = V_41 -> V_37 ;
struct V_20 * V_77 ;
struct V_1 * V_17 ;
struct V_40 * V_70 = V_41 ;
struct V_23 * V_24 = NULL ;
bool V_71 = false ;
struct V_10 * V_27 ;
F_39 () ;
V_17 = F_40 ( V_2 ) ;
V_27 = V_17 -> V_27 ;
F_41 () ;
if ( ! V_27 )
return - V_135 ;
F_49 (gate, n, known_gates, list) {
if ( V_24 -> V_41 -> V_37 != V_37 )
continue;
if ( V_24 -> V_41 -> V_50 & V_81 ) {
F_47 ( L_5 , V_24 -> V_41 -> V_76 ) ;
F_42 ( V_24 -> V_41 , V_70 , V_71 ) ;
V_70 = V_24 -> V_41 ;
V_71 = true ;
} else {
F_47 ( L_6 , V_24 -> V_41 ) ;
F_47 ( L_7 , V_24 -> V_41 -> V_50 ) ;
}
}
F_49 (gate, n, known_gates, list)
if ( V_24 -> V_41 -> V_37 == V_37 ) {
F_47 ( L_8 , V_24 -> V_41 -> V_76 ) ;
F_96 ( V_24 -> V_41 ) ;
}
return ( V_70 == V_41 ) ? - V_135 : 0 ;
}
void F_99 ( struct V_44 * V_45 ,
struct V_36 * V_37 )
{
struct V_46 * V_47 = (struct V_46 * ) V_45 -> V_54 ;
struct V_40 * V_41 ;
T_1 V_129 = 0 ;
T_3 V_126 = F_82 ( V_136 ) ;
if ( memcmp ( V_47 -> V_69 , V_37 -> V_104 . V_35 , V_56 ) != 0 ) {
T_2 * V_137 , * V_138 ;
V_138 = V_47 -> V_67 ;
V_137 = V_47 -> V_55 ;
F_39 () ;
V_41 = F_51 ( V_138 , V_37 ) ;
if ( V_41 ) {
F_14 ( & V_41 -> V_80 ) ;
V_129 = ++ V_41 -> V_129 ;
F_17 ( & V_41 -> V_80 ) ;
}
F_41 () ;
F_83 ( V_37 -> V_92 . V_93 . V_130 . V_131 , V_45 -> V_54 ,
F_84 ( V_129 ) , V_126 , V_137 , V_37 ) ;
}
F_100 ( V_45 ) ;
V_37 -> V_92 . V_93 . V_139 . V_140 ++ ;
}
void F_101 ( struct V_40 * V_41 )
{
struct V_44 * V_45 ;
while ( ( V_45 = F_102 ( & V_41 -> V_52 ) ) != NULL )
F_99 ( V_45 , V_41 -> V_37 ) ;
}
void F_103 ( struct V_40 * V_41 , struct V_42 * V_51 )
{
F_14 ( & V_41 -> V_80 ) ;
F_25 ( V_41 , V_51 ) ;
V_41 -> V_129 = 0xffff ;
V_41 -> V_141 = 0 ;
V_41 -> V_142 = 0 ;
V_41 -> V_114 = 0 ;
V_41 -> V_50 |= V_128 ;
F_104 ( V_41 ) ;
F_17 ( & V_41 -> V_80 ) ;
F_96 ( V_41 ) ;
}
static void F_105 ( struct V_20 * V_21 , bool V_18 )
{
struct V_40 * V_41 ;
struct V_23 * V_79 = F_106 ( V_21 , struct V_23 , V_26 ) ;
V_41 = V_79 -> V_41 ;
F_60 ( V_21 ) ;
if ( V_18 ) {
F_86 ( & V_41 -> V_111 ) ;
F_8 ( V_41 ) ;
}
F_8 ( V_79 ) ;
}
static int F_107 ( struct V_20 * V_21 , struct V_1 * V_7 )
{
struct V_40 * V_41 ;
struct V_23 * V_79 , * V_101 ;
T_1 V_103 ;
V_101 = F_6 ( sizeof( struct V_23 ) , V_8 ) ;
if ( V_101 == NULL )
return - V_34 ;
V_79 = F_106 ( V_21 , struct V_23 , V_26 ) ;
V_41 = V_79 -> V_41 ;
V_101 -> V_41 = V_41 ;
V_103 = F_23 ( V_41 -> V_76 , V_41 -> V_37 , V_7 ) ;
F_108 ( & V_101 -> V_26 ,
& V_7 -> V_9 [ V_103 ] ) ;
return 0 ;
}
int F_109 ( void )
{
struct V_1 * V_143 , * V_144 ;
int V_145 ;
V_143 = F_5 ( V_146 ) ;
if ( ! V_143 )
return - V_34 ;
V_143 -> V_25 = & F_105 ;
V_143 -> V_32 = & F_107 ;
V_143 -> V_30 = V_147 ;
V_143 -> V_27 = F_7 ( sizeof( struct V_10 ) , V_8 ) ;
if ( ! V_143 -> V_27 ) {
V_145 = - V_34 ;
goto V_148;
}
F_110 ( V_143 -> V_27 ) ;
V_144 = F_5 ( V_146 ) ;
if ( ! V_144 ) {
V_145 = - V_34 ;
goto V_148;
}
V_144 -> V_25 = & F_105 ;
V_144 -> V_32 = & F_107 ;
V_144 -> V_30 = V_147 ;
V_144 -> V_27 = F_7 ( sizeof( struct V_10 ) , V_8 ) ;
if ( ! V_144 -> V_27 ) {
V_145 = - V_34 ;
goto V_149;
}
F_110 ( V_144 -> V_27 ) ;
F_111 ( V_2 , V_143 ) ;
F_111 ( V_4 , V_144 ) ;
return 0 ;
V_149:
F_13 ( V_144 , true ) ;
V_148:
F_13 ( V_143 , true ) ;
return V_145 ;
}
void F_112 ( struct V_36 * V_37 )
{
struct V_1 * V_17 ;
struct V_40 * V_41 ;
struct V_23 * V_79 ;
struct V_20 * V_21 ;
int V_6 ;
F_39 () ;
V_17 = F_40 ( V_2 ) ;
F_54 (tbl, p, node, i) {
if ( V_79 -> V_41 -> V_37 != V_37 )
continue;
V_41 = V_79 -> V_41 ;
if ( ( ! ( V_41 -> V_50 & V_132 ) ) &&
( ! ( V_41 -> V_50 & V_128 ) ) &&
F_113 ( V_115 , V_41 -> V_114 + V_150 ) )
F_95 ( V_41 -> V_76 , V_41 -> V_37 ) ;
}
F_41 () ;
}
void F_114 ( void )
{
F_13 ( F_2 ( V_2 , 1 ) , true ) ;
F_13 ( F_2 ( V_4 , 1 ) , true ) ;
}
