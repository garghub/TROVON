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
F_44 ( L_1 ,
V_60 -> V_78 ,
F_42 ( & V_60 -> V_52 ) ) ;
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
memcmp ( V_78 , V_41 -> V_78 , V_56 ) == 0 ) {
if ( F_47 ( V_41 ) ) {
F_14 ( & V_41 -> V_82 ) ;
V_41 -> V_50 &= ~ V_83 ;
F_17 ( & V_41 -> V_82 ) ;
}
return V_41 ;
}
}
return NULL ;
}
struct V_40 * F_48 ( T_2 * V_78 , struct V_36 * V_37 )
{
return F_45 ( F_37 ( V_2 ) , V_78 , V_37 ) ;
}
struct V_40 * F_49 ( T_2 * V_78 , struct V_36 * V_37 )
{
return F_45 ( F_37 ( V_4 ) , V_78 , V_37 ) ;
}
struct V_40 * F_50 ( int V_84 , struct V_36 * V_37 )
{
struct V_1 * V_17 = F_37 ( V_2 ) ;
struct V_23 * V_81 ;
struct V_20 * V_21 ;
int V_6 ;
int V_85 = 0 ;
F_51 (tbl, p, node, i) {
if ( V_37 && V_81 -> V_41 -> V_37 != V_37 )
continue;
if ( V_85 ++ == V_84 ) {
if ( F_47 ( V_81 -> V_41 ) ) {
F_14 ( & V_81 -> V_41 -> V_82 ) ;
V_81 -> V_41 -> V_50 &= ~ V_83 ;
F_17 ( & V_81 -> V_41 -> V_82 ) ;
}
return V_81 -> V_41 ;
}
}
return NULL ;
}
static void F_52 ( struct V_86 * V_87 )
{
struct V_23 * V_81 = F_53 ( V_87 , struct V_23 , V_88 ) ;
F_8 ( V_81 ) ;
}
int F_54 ( struct V_40 * V_41 )
{
struct V_1 * V_17 ;
struct V_23 * V_24 , * V_89 ;
struct V_20 * V_79 ;
int V_90 ;
F_36 () ;
V_17 = F_37 ( V_2 ) ;
F_46 (gate, n, tbl->known_gates, list)
if ( V_24 -> V_41 == V_41 ) {
V_90 = - V_91 ;
goto V_92;
}
V_89 = F_7 ( sizeof( struct V_23 ) , V_8 ) ;
if ( ! V_89 ) {
V_90 = - V_34 ;
goto V_92;
}
V_41 -> V_93 = true ;
V_41 -> V_37 -> V_94 . V_95 . V_96 ++ ;
V_89 -> V_41 = V_41 ;
F_14 ( & V_17 -> V_16 ) ;
F_55 ( & V_89 -> V_26 , V_17 -> V_27 ) ;
F_17 ( & V_17 -> V_16 ) ;
F_38 () ;
F_44 ( L_2 ,
V_41 -> V_37 -> V_97 , V_41 -> V_78 ,
V_41 -> V_37 -> V_94 . V_95 . V_96 ) ;
return 0 ;
V_92:
F_38 () ;
return V_90 ;
}
static int F_56 ( struct V_1 * V_17 , struct V_40 * V_41 )
{
struct V_23 * V_24 ;
struct V_20 * V_21 , * V_22 ;
F_18 (gate, p, q, tbl->known_gates, list)
if ( V_24 -> V_41 == V_41 ) {
F_14 ( & V_17 -> V_16 ) ;
F_57 ( & V_24 -> V_26 ) ;
F_58 ( & V_24 -> V_88 , F_52 ) ;
F_17 ( & V_17 -> V_16 ) ;
V_41 -> V_37 -> V_94 . V_95 . V_96 -- ;
V_41 -> V_93 = false ;
F_44 ( L_3
L_4 , V_41 -> V_37 -> V_97 ,
V_41 -> V_78 , V_41 -> V_37 -> V_94 . V_95 . V_96 ) ;
break;
}
return 0 ;
}
int F_59 ( struct V_36 * V_37 )
{
return V_37 -> V_94 . V_95 . V_96 ;
}
int F_60 ( T_2 * V_78 , struct V_36 * V_37 )
{
struct V_98 * V_99 = & V_37 -> V_94 . V_95 ;
struct V_100 * V_101 = V_37 -> V_101 ;
struct V_1 * V_17 ;
struct V_40 * V_41 , * V_102 ;
struct V_23 * V_81 , * V_103 ;
struct V_10 * V_80 ;
struct V_20 * V_79 ;
int V_104 = 0 ;
int V_90 = 0 ;
T_1 V_105 ;
if ( memcmp ( V_78 , V_37 -> V_58 . V_35 , V_56 ) == 0 )
return - V_106 ;
if ( F_61 ( V_78 ) )
return - V_106 ;
if ( F_62 ( & V_37 -> V_94 . V_95 . V_107 , 1 , V_108 ) == 0 )
return - V_109 ;
V_90 = - V_34 ;
V_102 = F_7 ( sizeof( struct V_40 ) , V_8 ) ;
if ( ! V_102 )
goto V_110;
V_103 = F_6 ( sizeof( struct V_23 ) , V_8 ) ;
if ( ! V_103 )
goto V_111;
F_63 ( & V_3 ) ;
memcpy ( V_102 -> V_78 , V_78 , V_56 ) ;
V_102 -> V_37 = V_37 ;
V_102 -> V_50 = 0 ;
F_64 ( & V_102 -> V_52 ) ;
V_103 -> V_41 = V_102 ;
V_102 -> V_112 . V_54 = ( unsigned long ) V_102 ;
V_102 -> V_112 . V_113 = V_114 ;
V_102 -> V_115 = V_116 ;
F_11 ( & V_102 -> V_82 ) ;
F_65 ( & V_102 -> V_112 ) ;
V_17 = F_1 () ;
V_105 = F_23 ( V_78 , V_37 , V_17 ) ;
V_80 = & V_17 -> V_9 [ V_105 ] ;
F_14 ( & V_17 -> V_11 [ V_105 ] ) ;
V_90 = - V_91 ;
F_66 (node, n, bucket, list) {
V_41 = V_81 -> V_41 ;
if ( V_41 -> V_37 == V_37 && memcmp ( V_78 , V_41 -> V_78 , V_56 ) == 0 )
goto V_117;
}
F_55 ( & V_103 -> V_26 , V_80 ) ;
if ( F_67 ( & V_17 -> V_14 ) >=
V_17 -> V_30 * ( V_17 -> V_13 + 1 ) )
V_104 = 1 ;
V_118 ++ ;
F_17 ( & V_17 -> V_11 [ V_105 ] ) ;
F_68 ( & V_3 ) ;
if ( V_104 ) {
F_69 ( V_119 , & V_99 -> V_120 ) ;
F_70 ( & V_101 -> V_121 , & V_37 -> V_122 ) ;
}
return 0 ;
V_117:
F_17 ( & V_17 -> V_11 [ V_105 ] ) ;
F_68 ( & V_3 ) ;
F_8 ( V_103 ) ;
V_111:
F_8 ( V_102 ) ;
V_110:
F_16 ( & V_37 -> V_94 . V_95 . V_107 ) ;
return V_90 ;
}
static void F_71 ( struct V_86 * V_88 )
{
struct V_1 * V_17 = F_53 ( V_88 , struct V_1 , V_86 ) ;
F_13 ( V_17 , false ) ;
}
void F_72 ( void )
{
struct V_1 * V_28 , * V_7 ;
F_73 ( & V_3 ) ;
V_28 = F_1 () ;
V_7 = F_5 ( V_28 -> V_5 + 1 ) ;
if ( ! V_7 )
goto V_123;
if ( F_20 ( V_28 , V_7 ) < 0 ) {
F_12 ( V_7 ) ;
goto V_123;
}
F_26 ( V_2 , V_7 ) ;
F_58 ( & V_28 -> V_86 , F_71 ) ;
V_123:
F_74 ( & V_3 ) ;
}
void F_75 ( void )
{
struct V_1 * V_28 , * V_7 ;
F_73 ( & V_3 ) ;
V_28 = F_4 () ;
V_7 = F_5 ( V_28 -> V_5 + 1 ) ;
if ( ! V_7 )
goto V_123;
if ( F_20 ( V_28 , V_7 ) < 0 ) {
F_12 ( V_7 ) ;
goto V_123;
}
F_26 ( V_4 , V_7 ) ;
F_58 ( & V_28 -> V_86 , F_71 ) ;
V_123:
F_74 ( & V_3 ) ;
}
int F_76 ( T_2 * V_78 , T_2 * V_124 , struct V_36 * V_37 )
{
struct V_98 * V_99 = & V_37 -> V_94 . V_95 ;
struct V_100 * V_101 = V_37 -> V_101 ;
struct V_1 * V_17 ;
struct V_40 * V_41 , * V_102 ;
struct V_23 * V_81 , * V_103 ;
struct V_10 * V_80 ;
struct V_20 * V_79 ;
int V_104 = 0 ;
int V_90 = 0 ;
T_1 V_105 ;
if ( memcmp ( V_78 , V_37 -> V_58 . V_35 , V_56 ) == 0 )
return - V_106 ;
if ( F_61 ( V_78 ) )
return - V_106 ;
V_90 = - V_34 ;
V_102 = F_7 ( sizeof( struct V_40 ) , V_8 ) ;
if ( ! V_102 )
goto V_110;
V_103 = F_6 ( sizeof( struct V_23 ) , V_8 ) ;
if ( ! V_103 )
goto V_111;
F_63 ( & V_3 ) ;
memcpy ( V_102 -> V_78 , V_78 , V_56 ) ;
memcpy ( V_102 -> V_124 , V_124 , V_56 ) ;
V_102 -> V_37 = V_37 ;
V_102 -> V_50 = 0 ;
F_64 ( & V_102 -> V_52 ) ;
V_103 -> V_41 = V_102 ;
F_65 ( & V_102 -> V_112 ) ;
V_102 -> V_115 = V_116 ;
F_11 ( & V_102 -> V_82 ) ;
V_17 = F_4 () ;
V_105 = F_23 ( V_78 , V_37 , V_17 ) ;
V_80 = & V_17 -> V_9 [ V_105 ] ;
F_14 ( & V_17 -> V_11 [ V_105 ] ) ;
V_90 = - V_91 ;
F_66 (node, n, bucket, list) {
V_41 = V_81 -> V_41 ;
if ( V_41 -> V_37 == V_37 && memcmp ( V_78 , V_41 -> V_78 , V_56 ) == 0 )
goto V_117;
}
F_55 ( & V_103 -> V_26 , V_80 ) ;
if ( F_67 ( & V_17 -> V_14 ) >=
V_17 -> V_30 * ( V_17 -> V_13 + 1 ) )
V_104 = 1 ;
F_17 ( & V_17 -> V_11 [ V_105 ] ) ;
F_68 ( & V_3 ) ;
if ( V_104 ) {
F_69 ( V_125 , & V_99 -> V_120 ) ;
F_70 ( & V_101 -> V_121 , & V_37 -> V_122 ) ;
}
return 0 ;
V_117:
F_17 ( & V_17 -> V_11 [ V_105 ] ) ;
F_68 ( & V_3 ) ;
F_8 ( V_103 ) ;
V_111:
F_8 ( V_102 ) ;
V_110:
return V_90 ;
}
void F_77 ( struct V_42 * V_43 )
{
struct V_1 * V_17 ;
static const T_2 V_126 [ V_56 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
struct V_40 * V_41 ;
struct V_23 * V_81 ;
struct V_20 * V_21 ;
struct V_36 * V_37 = V_43 -> V_37 ;
int V_6 ;
T_3 V_127 = F_78 ( V_128 ) ;
F_36 () ;
V_17 = F_37 ( V_2 ) ;
F_51 (tbl, p, node, i) {
V_41 = V_81 -> V_41 ;
if ( F_37 ( V_41 -> V_51 ) == V_43 &&
V_41 -> V_50 & V_83 &&
! ( V_41 -> V_50 & V_129 ) ) {
F_14 ( & V_41 -> V_82 ) ;
V_41 -> V_50 &= ~ V_83 ;
++ V_41 -> V_130 ;
F_17 ( & V_41 -> V_82 ) ;
F_79 ( V_37 -> V_94 . V_95 . V_131 . V_132 ,
V_41 -> V_78 , F_80 ( V_41 -> V_130 ) ,
V_127 , V_126 , V_37 ) ;
}
}
F_38 () ;
}
static void F_81 ( struct V_86 * V_87 )
{
struct V_23 * V_81 = F_53 ( V_87 , struct V_23 , V_88 ) ;
struct V_36 * V_37 = V_81 -> V_41 -> V_37 ;
F_82 ( & V_81 -> V_41 -> V_112 ) ;
F_16 ( & V_37 -> V_94 . V_95 . V_107 ) ;
F_8 ( V_81 -> V_41 ) ;
F_8 ( V_81 ) ;
}
static void F_83 ( struct V_1 * V_17 , struct V_23 * V_81 )
{
struct V_40 * V_41 ;
V_41 = V_81 -> V_41 ;
F_84 ( & V_41 -> V_82 ) ;
V_41 -> V_50 |= V_133 ;
if ( V_41 -> V_93 )
F_56 ( V_17 , V_41 ) ;
F_57 ( & V_81 -> V_26 ) ;
F_58 ( & V_81 -> V_88 , F_81 ) ;
F_85 ( & V_41 -> V_82 ) ;
F_16 ( & V_17 -> V_14 ) ;
}
void F_86 ( struct V_42 * V_43 )
{
struct V_1 * V_17 ;
struct V_40 * V_41 ;
struct V_23 * V_81 ;
struct V_20 * V_21 ;
int V_6 ;
F_36 () ;
F_63 ( & V_3 ) ;
V_17 = F_1 () ;
F_51 (tbl, p, node, i) {
V_41 = V_81 -> V_41 ;
if ( F_37 ( V_41 -> V_51 ) == V_43 ) {
F_14 ( & V_17 -> V_11 [ V_6 ] ) ;
F_83 ( V_17 , V_81 ) ;
F_17 ( & V_17 -> V_11 [ V_6 ] ) ;
}
}
F_68 ( & V_3 ) ;
F_38 () ;
}
static void F_87 ( struct V_1 * V_17 ,
struct V_36 * V_37 )
{
struct V_40 * V_41 ;
struct V_23 * V_81 ;
struct V_20 * V_21 ;
int V_6 ;
F_88 ( ! F_89 () ) ;
F_51 (tbl, p, node, i) {
V_41 = V_81 -> V_41 ;
if ( V_41 -> V_37 != V_37 )
continue;
F_14 ( & V_17 -> V_11 [ V_6 ] ) ;
F_83 ( V_17 , V_81 ) ;
F_17 ( & V_17 -> V_11 [ V_6 ] ) ;
}
}
void F_90 ( struct V_36 * V_37 )
{
struct V_1 * V_17 ;
F_36 () ;
F_63 ( & V_3 ) ;
V_17 = F_1 () ;
F_87 ( V_17 , V_37 ) ;
V_17 = F_4 () ;
F_87 ( V_17 , V_37 ) ;
F_68 ( & V_3 ) ;
F_38 () ;
}
int F_91 ( T_2 * V_35 , struct V_36 * V_37 )
{
struct V_1 * V_17 ;
struct V_40 * V_41 ;
struct V_23 * V_81 ;
struct V_10 * V_80 ;
struct V_20 * V_79 ;
int V_105 ;
int V_90 = 0 ;
F_63 ( & V_3 ) ;
V_17 = F_1 () ;
V_105 = F_23 ( V_35 , V_37 , V_17 ) ;
V_80 = & V_17 -> V_9 [ V_105 ] ;
F_14 ( & V_17 -> V_11 [ V_105 ] ) ;
F_66 (node, n, bucket, list) {
V_41 = V_81 -> V_41 ;
if ( V_41 -> V_37 == V_37 &&
memcmp ( V_35 , V_41 -> V_78 , V_56 ) == 0 ) {
F_83 ( V_17 , V_81 ) ;
goto V_134;
}
}
V_90 = - V_135 ;
V_134:
V_118 ++ ;
F_17 ( & V_17 -> V_11 [ V_105 ] ) ;
F_68 ( & V_3 ) ;
return V_90 ;
}
void F_92 ( struct V_40 * V_41 )
{
if ( V_41 -> V_50 & V_83 )
F_93 ( V_41 -> V_37 -> V_101 ,
& V_41 -> V_52 ) ;
}
int F_94 ( struct V_40 * V_41 )
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
return - V_136 ;
F_46 (gate, n, known_gates, list) {
if ( V_24 -> V_41 -> V_37 != V_37 )
continue;
if ( V_24 -> V_41 -> V_50 & V_83 ) {
F_44 ( L_5 , V_24 -> V_41 -> V_78 ) ;
F_39 ( V_24 -> V_41 , V_72 , V_73 ) ;
V_72 = V_24 -> V_41 ;
V_73 = true ;
} else {
F_44 ( L_6 , V_24 -> V_41 ) ;
F_44 ( L_7 , V_24 -> V_41 -> V_50 ) ;
}
}
F_46 (gate, n, known_gates, list)
if ( V_24 -> V_41 -> V_37 == V_37 ) {
F_44 ( L_8 , V_24 -> V_41 -> V_78 ) ;
F_92 ( V_24 -> V_41 ) ;
}
return ( V_72 == V_41 ) ? - V_136 : 0 ;
}
void F_95 ( struct V_44 * V_45 ,
struct V_36 * V_37 )
{
F_96 ( V_45 ) ;
V_37 -> V_94 . V_95 . V_137 . V_138 ++ ;
}
void F_97 ( struct V_40 * V_41 )
{
struct V_44 * V_45 ;
while ( ( V_45 = F_98 ( & V_41 -> V_52 ) ) != NULL )
F_95 ( V_45 , V_41 -> V_37 ) ;
}
void F_99 ( struct V_40 * V_41 , struct V_42 * V_51 )
{
F_14 ( & V_41 -> V_82 ) ;
F_25 ( V_41 , V_51 ) ;
V_41 -> V_130 = 0xffff ;
V_41 -> V_139 = 0 ;
V_41 -> V_140 = 0 ;
V_41 -> V_115 = 0 ;
V_41 -> V_50 |= V_129 ;
F_100 ( V_41 ) ;
F_17 ( & V_41 -> V_82 ) ;
F_92 ( V_41 ) ;
}
static void F_101 ( struct V_20 * V_21 , bool V_18 )
{
struct V_40 * V_41 ;
struct V_23 * V_81 = F_102 ( V_21 , struct V_23 , V_26 ) ;
V_41 = V_81 -> V_41 ;
F_57 ( V_21 ) ;
if ( V_18 ) {
F_82 ( & V_41 -> V_112 ) ;
F_8 ( V_41 ) ;
}
F_8 ( V_81 ) ;
}
static int F_103 ( struct V_20 * V_21 , struct V_1 * V_7 )
{
struct V_40 * V_41 ;
struct V_23 * V_81 , * V_103 ;
T_1 V_105 ;
V_103 = F_6 ( sizeof( struct V_23 ) , V_8 ) ;
if ( V_103 == NULL )
return - V_34 ;
V_81 = F_102 ( V_21 , struct V_23 , V_26 ) ;
V_41 = V_81 -> V_41 ;
V_103 -> V_41 = V_41 ;
V_105 = F_23 ( V_41 -> V_78 , V_41 -> V_37 , V_7 ) ;
F_104 ( & V_103 -> V_26 ,
& V_7 -> V_9 [ V_105 ] ) ;
return 0 ;
}
int F_105 ( void )
{
struct V_1 * V_141 , * V_142 ;
int V_143 ;
V_141 = F_5 ( V_144 ) ;
if ( ! V_141 )
return - V_34 ;
V_141 -> V_25 = & F_101 ;
V_141 -> V_32 = & F_103 ;
V_141 -> V_30 = V_145 ;
V_141 -> V_27 = F_7 ( sizeof( struct V_10 ) , V_8 ) ;
if ( ! V_141 -> V_27 ) {
V_143 = - V_34 ;
goto V_146;
}
F_106 ( V_141 -> V_27 ) ;
V_142 = F_5 ( V_144 ) ;
if ( ! V_142 ) {
V_143 = - V_34 ;
goto V_146;
}
V_142 -> V_25 = & F_101 ;
V_142 -> V_32 = & F_103 ;
V_142 -> V_30 = V_145 ;
V_142 -> V_27 = F_7 ( sizeof( struct V_10 ) , V_8 ) ;
if ( ! V_142 -> V_27 ) {
V_143 = - V_34 ;
goto V_147;
}
F_106 ( V_142 -> V_27 ) ;
F_107 ( V_2 , V_141 ) ;
F_107 ( V_4 , V_142 ) ;
return 0 ;
V_147:
F_13 ( V_142 , true ) ;
V_146:
F_13 ( V_141 , true ) ;
return V_143 ;
}
void F_108 ( struct V_36 * V_37 )
{
struct V_1 * V_17 ;
struct V_40 * V_41 ;
struct V_23 * V_81 ;
struct V_20 * V_21 ;
int V_6 ;
F_36 () ;
V_17 = F_37 ( V_2 ) ;
F_51 (tbl, p, node, i) {
if ( V_81 -> V_41 -> V_37 != V_37 )
continue;
V_41 = V_81 -> V_41 ;
if ( ( ! ( V_41 -> V_50 & V_133 ) ) &&
( ! ( V_41 -> V_50 & V_129 ) ) &&
F_109 ( V_116 , V_41 -> V_115 + V_148 ) )
F_91 ( V_41 -> V_78 , V_41 -> V_37 ) ;
}
F_38 () ;
}
void F_110 ( void )
{
F_13 ( F_2 ( V_2 , 1 ) , true ) ;
F_13 ( F_2 ( V_4 , 1 ) , true ) ;
}
