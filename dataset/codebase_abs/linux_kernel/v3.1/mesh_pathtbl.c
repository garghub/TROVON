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
return V_7 ;
}
static void F_12 ( struct V_1 * V_16 )
{
F_8 ( V_16 -> V_9 ) ;
F_8 ( V_16 -> V_11 ) ;
F_8 ( V_16 ) ;
}
static void F_13 ( struct V_1 * V_16 , bool V_17 )
{
struct V_10 * V_18 ;
struct V_19 * V_20 , * V_21 ;
int V_6 ;
V_18 = V_16 -> V_9 ;
for ( V_6 = 0 ; V_6 <= V_16 -> V_13 ; V_6 ++ ) {
F_14 ( & V_16 -> V_11 [ V_6 ] ) ;
F_15 (p, q, &mesh_hash[i]) {
V_16 -> V_22 ( V_20 , V_17 ) ;
F_16 ( & V_16 -> V_14 ) ;
}
F_17 ( & V_16 -> V_11 [ V_6 ] ) ;
}
F_12 ( V_16 ) ;
}
static int F_18 ( struct V_1 * V_23 ,
struct V_1 * V_7 )
{
struct V_10 * V_24 ;
struct V_19 * V_20 , * V_21 ;
int V_6 ;
if ( F_19 ( & V_23 -> V_14 )
< V_23 -> V_25 * ( V_23 -> V_13 + 1 ) )
return - V_26 ;
V_7 -> V_22 = V_23 -> V_22 ;
V_7 -> V_25 = V_23 -> V_25 ;
V_7 -> V_27 = V_23 -> V_27 ;
F_9 ( & V_7 -> V_14 , F_19 ( & V_23 -> V_14 ) ) ;
V_24 = V_23 -> V_9 ;
for ( V_6 = 0 ; V_6 <= V_23 -> V_13 ; V_6 ++ )
F_20 (p, &oldhash[i])
if ( V_23 -> V_27 ( V_20 , V_7 ) < 0 )
goto V_28;
return 0 ;
V_28:
for ( V_6 = 0 ; V_6 <= V_7 -> V_13 ; V_6 ++ ) {
F_15 (p, q, &newtbl->hash_buckets[i])
V_23 -> V_22 ( V_20 , 0 ) ;
}
return - V_29 ;
}
static T_1 F_21 ( T_2 * V_30 , struct V_31 * V_32 ,
struct V_1 * V_16 )
{
return F_22 ( * ( T_1 * ) ( V_30 + 2 ) , V_32 -> V_33 -> V_34 , V_16 -> V_15 )
& V_16 -> V_13 ;
}
void F_23 ( struct V_35 * V_36 , struct V_37 * V_38 )
{
struct V_39 * V_40 ;
struct V_41 * V_42 ;
struct V_43 V_44 ;
unsigned long V_45 ;
F_24 ( V_36 -> V_46 , V_38 ) ;
F_25 ( & V_44 ) ;
F_26 ( & V_36 -> V_47 . V_48 , V_45 ) ;
while ( ( V_40 = F_27 ( & V_36 -> V_47 ) ) != NULL ) {
V_42 = (struct V_41 * ) V_40 -> V_49 ;
memcpy ( V_42 -> V_50 , V_38 -> V_38 . V_30 , V_51 ) ;
F_28 ( & V_44 , V_40 ) ;
}
F_29 ( & V_44 , & V_36 -> V_47 ) ;
F_30 ( & V_36 -> V_47 . V_48 , V_45 ) ;
}
struct V_35 * F_31 ( T_2 * V_52 , struct V_31 * V_32 )
{
struct V_35 * V_36 ;
struct V_19 * V_53 ;
struct V_10 * V_54 ;
struct V_1 * V_16 ;
struct V_55 * V_56 ;
V_16 = F_32 ( V_2 ) ;
V_54 = & V_16 -> V_9 [ F_21 ( V_52 , V_32 , V_16 ) ] ;
F_33 (node, n, bucket, list) {
V_36 = V_56 -> V_36 ;
if ( V_36 -> V_32 == V_32 &&
memcmp ( V_52 , V_36 -> V_52 , V_51 ) == 0 ) {
if ( F_34 ( V_36 ) ) {
F_14 ( & V_36 -> V_57 ) ;
if ( F_34 ( V_36 ) )
V_36 -> V_45 &= ~ V_58 ;
F_17 ( & V_36 -> V_57 ) ;
}
return V_36 ;
}
}
return NULL ;
}
struct V_35 * F_35 ( T_2 * V_52 , struct V_31 * V_32 )
{
struct V_35 * V_36 ;
struct V_19 * V_53 ;
struct V_10 * V_54 ;
struct V_1 * V_16 ;
struct V_55 * V_56 ;
V_16 = F_32 ( V_4 ) ;
V_54 = & V_16 -> V_9 [ F_21 ( V_52 , V_32 , V_16 ) ] ;
F_33 (node, n, bucket, list) {
V_36 = V_56 -> V_36 ;
if ( V_36 -> V_32 == V_32 &&
memcmp ( V_52 , V_36 -> V_52 , V_51 ) == 0 ) {
if ( F_34 ( V_36 ) ) {
F_14 ( & V_36 -> V_57 ) ;
if ( F_34 ( V_36 ) )
V_36 -> V_45 &= ~ V_58 ;
F_17 ( & V_36 -> V_57 ) ;
}
return V_36 ;
}
}
return NULL ;
}
struct V_35 * F_36 ( int V_59 , struct V_31 * V_32 )
{
struct V_1 * V_16 = F_32 ( V_2 ) ;
struct V_55 * V_56 ;
struct V_19 * V_20 ;
int V_6 ;
int V_60 = 0 ;
F_37 (tbl, p, node, i) {
if ( V_32 && V_56 -> V_36 -> V_32 != V_32 )
continue;
if ( V_60 ++ == V_59 ) {
if ( F_34 ( V_56 -> V_36 ) ) {
F_14 ( & V_56 -> V_36 -> V_57 ) ;
if ( F_34 ( V_56 -> V_36 ) )
V_56 -> V_36 -> V_45 &= ~ V_58 ;
F_17 ( & V_56 -> V_36 -> V_57 ) ;
}
return V_56 -> V_36 ;
}
}
return NULL ;
}
int F_38 ( T_2 * V_52 , struct V_31 * V_32 )
{
struct V_61 * V_62 = & V_32 -> V_63 . V_64 ;
struct V_65 * V_66 = V_32 -> V_66 ;
struct V_1 * V_16 ;
struct V_35 * V_36 , * V_67 ;
struct V_55 * V_56 , * V_68 ;
struct V_10 * V_54 ;
struct V_19 * V_53 ;
int V_69 = 0 ;
int V_70 = 0 ;
T_1 V_71 ;
if ( memcmp ( V_52 , V_32 -> V_72 . V_30 , V_51 ) == 0 )
return - V_73 ;
if ( F_39 ( V_52 ) )
return - V_73 ;
if ( F_40 ( & V_32 -> V_63 . V_64 . V_74 , 1 , V_75 ) == 0 )
return - V_76 ;
V_70 = - V_29 ;
V_67 = F_7 ( sizeof( struct V_35 ) , V_8 ) ;
if ( ! V_67 )
goto V_77;
V_68 = F_6 ( sizeof( struct V_55 ) , V_8 ) ;
if ( ! V_68 )
goto V_78;
F_41 ( & V_3 ) ;
memcpy ( V_67 -> V_52 , V_52 , V_51 ) ;
V_67 -> V_32 = V_32 ;
V_67 -> V_45 = 0 ;
F_42 ( & V_67 -> V_47 ) ;
V_68 -> V_36 = V_67 ;
V_67 -> V_79 . V_49 = ( unsigned long ) V_67 ;
V_67 -> V_79 . V_80 = V_81 ;
V_67 -> V_82 = V_83 ;
F_11 ( & V_67 -> V_57 ) ;
F_43 ( & V_67 -> V_79 ) ;
V_16 = F_1 () ;
V_71 = F_21 ( V_52 , V_32 , V_16 ) ;
V_54 = & V_16 -> V_9 [ V_71 ] ;
F_14 ( & V_16 -> V_11 [ V_71 ] ) ;
V_70 = - V_84 ;
F_44 (node, n, bucket, list) {
V_36 = V_56 -> V_36 ;
if ( V_36 -> V_32 == V_32 && memcmp ( V_52 , V_36 -> V_52 , V_51 ) == 0 )
goto V_85;
}
F_45 ( & V_68 -> V_86 , V_54 ) ;
if ( F_46 ( & V_16 -> V_14 ) >=
V_16 -> V_25 * ( V_16 -> V_13 + 1 ) )
V_69 = 1 ;
V_87 ++ ;
F_17 ( & V_16 -> V_11 [ V_71 ] ) ;
F_47 ( & V_3 ) ;
if ( V_69 ) {
F_48 ( V_88 , & V_62 -> V_89 ) ;
F_49 ( & V_66 -> V_90 , & V_32 -> V_91 ) ;
}
return 0 ;
V_85:
F_17 ( & V_16 -> V_11 [ V_71 ] ) ;
F_47 ( & V_3 ) ;
F_8 ( V_68 ) ;
V_78:
F_8 ( V_67 ) ;
V_77:
F_16 ( & V_32 -> V_63 . V_64 . V_74 ) ;
return V_70 ;
}
static void F_50 ( struct V_92 * V_93 )
{
struct V_1 * V_16 = F_51 ( V_93 , struct V_1 , V_92 ) ;
F_13 ( V_16 , false ) ;
}
void F_52 ( void )
{
struct V_1 * V_23 , * V_7 ;
F_53 ( & V_3 ) ;
V_23 = F_1 () ;
V_7 = F_5 ( V_23 -> V_5 + 1 ) ;
if ( ! V_7 )
goto V_94;
if ( F_18 ( V_23 , V_7 ) < 0 ) {
F_12 ( V_7 ) ;
goto V_94;
}
F_24 ( V_2 , V_7 ) ;
F_54 ( & V_23 -> V_92 , F_50 ) ;
V_94:
F_55 ( & V_3 ) ;
}
void F_56 ( void )
{
struct V_1 * V_23 , * V_7 ;
F_53 ( & V_3 ) ;
V_23 = F_4 () ;
V_7 = F_5 ( V_23 -> V_5 + 1 ) ;
if ( ! V_7 )
goto V_94;
if ( F_18 ( V_23 , V_7 ) < 0 ) {
F_12 ( V_7 ) ;
goto V_94;
}
F_24 ( V_4 , V_7 ) ;
F_54 ( & V_23 -> V_92 , F_50 ) ;
V_94:
F_55 ( & V_3 ) ;
}
int F_57 ( T_2 * V_52 , T_2 * V_95 , struct V_31 * V_32 )
{
struct V_61 * V_62 = & V_32 -> V_63 . V_64 ;
struct V_65 * V_66 = V_32 -> V_66 ;
struct V_1 * V_16 ;
struct V_35 * V_36 , * V_67 ;
struct V_55 * V_56 , * V_68 ;
struct V_10 * V_54 ;
struct V_19 * V_53 ;
int V_69 = 0 ;
int V_70 = 0 ;
T_1 V_71 ;
if ( memcmp ( V_52 , V_32 -> V_72 . V_30 , V_51 ) == 0 )
return - V_73 ;
if ( F_39 ( V_52 ) )
return - V_73 ;
V_70 = - V_29 ;
V_67 = F_7 ( sizeof( struct V_35 ) , V_8 ) ;
if ( ! V_67 )
goto V_77;
V_68 = F_6 ( sizeof( struct V_55 ) , V_8 ) ;
if ( ! V_68 )
goto V_78;
F_41 ( & V_3 ) ;
memcpy ( V_67 -> V_52 , V_52 , V_51 ) ;
memcpy ( V_67 -> V_95 , V_95 , V_51 ) ;
V_67 -> V_32 = V_32 ;
V_67 -> V_45 = 0 ;
F_42 ( & V_67 -> V_47 ) ;
V_68 -> V_36 = V_67 ;
V_67 -> V_82 = V_83 ;
F_11 ( & V_67 -> V_57 ) ;
V_16 = F_4 () ;
V_71 = F_21 ( V_52 , V_32 , V_16 ) ;
V_54 = & V_16 -> V_9 [ V_71 ] ;
F_14 ( & V_16 -> V_11 [ V_71 ] ) ;
V_70 = - V_84 ;
F_44 (node, n, bucket, list) {
V_36 = V_56 -> V_36 ;
if ( V_36 -> V_32 == V_32 && memcmp ( V_52 , V_36 -> V_52 , V_51 ) == 0 )
goto V_85;
}
F_45 ( & V_68 -> V_86 , V_54 ) ;
if ( F_46 ( & V_16 -> V_14 ) >=
V_16 -> V_25 * ( V_16 -> V_13 + 1 ) )
V_69 = 1 ;
F_17 ( & V_16 -> V_11 [ V_71 ] ) ;
F_47 ( & V_3 ) ;
if ( V_69 ) {
F_48 ( V_96 , & V_62 -> V_89 ) ;
F_49 ( & V_66 -> V_90 , & V_32 -> V_91 ) ;
}
return 0 ;
V_85:
F_17 ( & V_16 -> V_11 [ V_71 ] ) ;
F_47 ( & V_3 ) ;
F_8 ( V_68 ) ;
V_78:
F_8 ( V_67 ) ;
V_77:
return V_70 ;
}
void F_58 ( struct V_37 * V_38 )
{
struct V_1 * V_16 ;
static const T_2 V_97 [ V_51 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
struct V_35 * V_36 ;
struct V_55 * V_56 ;
struct V_19 * V_20 ;
struct V_31 * V_32 = V_38 -> V_32 ;
int V_6 ;
F_59 () ;
V_16 = F_32 ( V_2 ) ;
F_37 (tbl, p, node, i) {
V_36 = V_56 -> V_36 ;
F_14 ( & V_36 -> V_57 ) ;
if ( F_32 ( V_36 -> V_46 ) == V_38 &&
V_36 -> V_45 & V_58 &&
! ( V_36 -> V_45 & V_98 ) ) {
V_36 -> V_45 &= ~ V_58 ;
++ V_36 -> V_99 ;
F_17 ( & V_36 -> V_57 ) ;
F_60 ( V_32 -> V_63 . V_64 . V_100 . V_101 ,
V_36 -> V_52 , F_61 ( V_36 -> V_99 ) ,
F_62 ( V_102 ) ,
V_97 , V_32 ) ;
} else
F_17 ( & V_36 -> V_57 ) ;
}
F_63 () ;
}
void F_64 ( struct V_37 * V_38 )
{
struct V_1 * V_16 ;
struct V_35 * V_36 ;
struct V_55 * V_56 ;
struct V_19 * V_20 ;
int V_6 ;
F_59 () ;
V_16 = F_32 ( V_2 ) ;
F_37 (tbl, p, node, i) {
V_36 = V_56 -> V_36 ;
if ( F_32 ( V_36 -> V_46 ) == V_38 )
F_65 ( V_36 -> V_52 , V_36 -> V_32 ) ;
}
F_63 () ;
}
void F_66 ( struct V_31 * V_32 )
{
struct V_1 * V_16 ;
struct V_35 * V_36 ;
struct V_55 * V_56 ;
struct V_19 * V_20 ;
int V_6 ;
F_59 () ;
V_16 = F_32 ( V_2 ) ;
F_37 (tbl, p, node, i) {
V_36 = V_56 -> V_36 ;
if ( V_36 -> V_32 == V_32 )
F_65 ( V_36 -> V_52 , V_36 -> V_32 ) ;
}
F_63 () ;
}
static void F_67 ( struct V_92 * V_103 )
{
struct V_55 * V_56 = F_51 ( V_103 , struct V_55 , V_93 ) ;
struct V_31 * V_32 = V_56 -> V_36 -> V_32 ;
F_68 ( & V_56 -> V_36 -> V_79 ) ;
F_16 ( & V_32 -> V_63 . V_64 . V_74 ) ;
F_8 ( V_56 -> V_36 ) ;
F_8 ( V_56 ) ;
}
int F_65 ( T_2 * V_30 , struct V_31 * V_32 )
{
struct V_1 * V_16 ;
struct V_35 * V_36 ;
struct V_55 * V_56 ;
struct V_10 * V_54 ;
struct V_19 * V_53 ;
int V_71 ;
int V_70 = 0 ;
F_41 ( & V_3 ) ;
V_16 = F_1 () ;
V_71 = F_21 ( V_30 , V_32 , V_16 ) ;
V_54 = & V_16 -> V_9 [ V_71 ] ;
F_14 ( & V_16 -> V_11 [ V_71 ] ) ;
F_44 (node, n, bucket, list) {
V_36 = V_56 -> V_36 ;
if ( V_36 -> V_32 == V_32 &&
memcmp ( V_30 , V_36 -> V_52 , V_51 ) == 0 ) {
F_69 ( & V_36 -> V_57 ) ;
V_36 -> V_45 |= V_104 ;
F_70 ( & V_56 -> V_86 ) ;
F_54 ( & V_56 -> V_93 , F_67 ) ;
F_16 ( & V_16 -> V_14 ) ;
F_71 ( & V_36 -> V_57 ) ;
goto V_105;
}
}
V_70 = - V_106 ;
V_105:
V_87 ++ ;
F_17 ( & V_16 -> V_11 [ V_71 ] ) ;
F_47 ( & V_3 ) ;
return V_70 ;
}
void F_72 ( struct V_35 * V_36 )
{
if ( V_36 -> V_45 & V_58 )
F_73 ( V_36 -> V_32 -> V_66 ,
& V_36 -> V_47 ) ;
}
void F_74 ( struct V_39 * V_40 ,
struct V_31 * V_32 )
{
struct V_41 * V_42 = (struct V_41 * ) V_40 -> V_49 ;
struct V_35 * V_36 ;
T_1 V_99 = 0 ;
if ( memcmp ( V_42 -> V_107 , V_32 -> V_72 . V_30 , V_51 ) != 0 ) {
T_2 * V_108 , * V_109 ;
V_109 = V_42 -> V_110 ;
V_108 = V_42 -> V_50 ;
V_36 = F_31 ( V_109 , V_32 ) ;
if ( V_36 )
V_99 = ++ V_36 -> V_99 ;
F_60 ( V_32 -> V_63 . V_64 . V_100 . V_101 , V_40 -> V_49 ,
F_61 ( V_99 ) ,
F_62 ( V_111 ) , V_108 , V_32 ) ;
}
F_75 ( V_40 ) ;
V_32 -> V_63 . V_64 . V_112 . V_113 ++ ;
}
void F_76 ( struct V_35 * V_36 )
{
struct V_39 * V_40 ;
while ( ( V_40 = F_77 ( & V_36 -> V_47 ) ) &&
( V_36 -> V_45 & V_58 ) )
F_74 ( V_40 , V_36 -> V_32 ) ;
}
void F_78 ( struct V_35 * V_36 , struct V_37 * V_46 )
{
F_14 ( & V_36 -> V_57 ) ;
F_23 ( V_36 , V_46 ) ;
V_36 -> V_99 = 0xffff ;
V_36 -> V_114 = 0 ;
V_36 -> V_115 = 0 ;
V_36 -> V_82 = 0 ;
V_36 -> V_45 |= V_98 ;
F_79 ( V_36 ) ;
F_17 ( & V_36 -> V_57 ) ;
F_72 ( V_36 ) ;
}
static void F_80 ( struct V_19 * V_20 , bool V_17 )
{
struct V_35 * V_36 ;
struct V_55 * V_56 = F_81 ( V_20 , struct V_55 , V_86 ) ;
V_36 = V_56 -> V_36 ;
F_70 ( V_20 ) ;
if ( V_17 ) {
F_68 ( & V_36 -> V_79 ) ;
F_8 ( V_36 ) ;
}
F_8 ( V_56 ) ;
}
static int F_82 ( struct V_19 * V_20 , struct V_1 * V_7 )
{
struct V_35 * V_36 ;
struct V_55 * V_56 , * V_68 ;
T_1 V_71 ;
V_68 = F_6 ( sizeof( struct V_55 ) , V_8 ) ;
if ( V_68 == NULL )
return - V_29 ;
V_56 = F_81 ( V_20 , struct V_55 , V_86 ) ;
V_36 = V_56 -> V_36 ;
V_68 -> V_36 = V_36 ;
V_71 = F_21 ( V_36 -> V_52 , V_36 -> V_32 , V_7 ) ;
F_83 ( & V_68 -> V_86 ,
& V_7 -> V_9 [ V_71 ] ) ;
return 0 ;
}
int F_84 ( void )
{
struct V_1 * V_116 , * V_117 ;
V_116 = F_5 ( V_118 ) ;
if ( ! V_116 )
return - V_29 ;
V_116 -> V_22 = & F_80 ;
V_116 -> V_27 = & F_82 ;
V_116 -> V_25 = V_119 ;
V_117 = F_5 ( V_118 ) ;
if ( ! V_117 ) {
F_13 ( V_116 , true ) ;
return - V_29 ;
}
V_117 -> V_22 = & F_80 ;
V_117 -> V_27 = & F_82 ;
V_117 -> V_25 = V_119 ;
F_85 ( V_2 , V_116 ) ;
F_85 ( V_4 , V_117 ) ;
return 0 ;
}
void F_86 ( struct V_31 * V_32 )
{
struct V_1 * V_16 ;
struct V_35 * V_36 ;
struct V_55 * V_56 ;
struct V_19 * V_20 ;
int V_6 ;
F_59 () ;
V_16 = F_32 ( V_2 ) ;
F_37 (tbl, p, node, i) {
if ( V_56 -> V_36 -> V_32 != V_32 )
continue;
V_36 = V_56 -> V_36 ;
F_14 ( & V_36 -> V_57 ) ;
if ( ( ! ( V_36 -> V_45 & V_104 ) ) &&
( ! ( V_36 -> V_45 & V_98 ) ) &&
F_87 ( V_83 , V_36 -> V_82 + V_120 ) ) {
F_17 ( & V_36 -> V_57 ) ;
F_65 ( V_36 -> V_52 , V_36 -> V_32 ) ;
} else
F_17 ( & V_36 -> V_57 ) ;
}
F_63 () ;
}
void F_88 ( void )
{
F_13 ( F_89 ( V_2 ) , true ) ;
F_13 ( F_89 ( V_4 ) , true ) ;
}
