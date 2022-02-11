static unsigned int
F_1 ( void )
{
unsigned int V_1 ;
unsigned long V_2 = V_3 - V_4 ;
V_1 = ( 16 * F_2 ( V_2 ) ) << ( V_5 - 10 ) ;
return F_3 (unsigned int, limit, 256*1024 ) ;
}
static unsigned int
F_4 ( unsigned int V_1 )
{
return F_5 ( V_1 / V_6 ) ;
}
static T_1
F_6 ( T_2 V_7 )
{
return F_7 ( F_8 ( V_7 ) , V_8 ) ;
}
static struct V_9 *
F_9 ( void )
{
struct V_9 * V_10 ;
V_10 = F_10 ( V_11 , V_12 ) ;
if ( V_10 ) {
V_10 -> V_13 = V_14 ;
V_10 -> V_15 = V_16 ;
F_11 ( & V_10 -> V_17 ) ;
}
return V_10 ;
}
static void
F_12 ( struct V_9 * V_10 )
{
if ( V_10 -> V_15 == V_18 && V_10 -> V_19 . V_20 ) {
V_21 -= V_10 -> V_19 . V_22 ;
F_13 ( V_10 -> V_19 . V_20 ) ;
}
F_14 ( & V_10 -> V_17 ) ;
F_15 ( & V_23 ) ;
V_21 -= sizeof( * V_10 ) ;
F_16 ( V_11 , V_10 ) ;
}
static void
F_17 ( struct V_24 * V_25 , struct V_9 * V_10 )
{
F_18 ( & V_25 -> V_26 ) ;
F_12 ( V_10 ) ;
F_19 ( & V_25 -> V_26 ) ;
}
int F_20 ( void )
{
unsigned int V_27 ;
unsigned int V_28 ;
V_29 = F_1 () ;
F_21 ( & V_23 , 0 ) ;
V_27 = F_4 ( V_29 ) ;
V_8 = F_22 ( V_27 ) ;
F_23 ( & V_30 ) ;
V_11 = F_24 ( L_1 , sizeof( struct V_9 ) ,
0 , 0 , NULL ) ;
if ( ! V_11 )
goto V_31;
V_32 = F_25 ( V_27 , sizeof( * V_32 ) , V_12 ) ;
if ( ! V_32 )
goto V_31;
for ( V_28 = 0 ; V_28 < V_27 ; V_28 ++ ) {
F_11 ( & V_32 [ V_28 ] . V_33 ) ;
F_26 ( & V_32 [ V_28 ] . V_26 ) ;
}
V_34 = V_27 ;
return 0 ;
V_31:
F_27 ( V_35 L_2 ) ;
F_28 () ;
return - V_36 ;
}
void F_28 ( void )
{
struct V_9 * V_10 ;
unsigned int V_28 ;
F_29 ( & V_30 ) ;
F_30 ( & V_37 ) ;
for ( V_28 = 0 ; V_28 < V_34 ; V_28 ++ ) {
struct V_38 * V_39 = & V_32 [ V_28 ] . V_33 ;
while ( ! F_31 ( V_39 ) ) {
V_10 = F_32 ( V_39 , struct V_9 , V_17 ) ;
F_12 ( V_10 ) ;
}
}
F_13 ( V_32 ) ;
V_32 = NULL ;
V_34 = 0 ;
if ( V_11 ) {
F_33 ( V_11 ) ;
V_11 = NULL ;
}
}
static void
F_34 ( struct V_24 * V_25 , struct V_9 * V_10 )
{
V_10 -> V_40 = V_41 ;
F_35 ( & V_10 -> V_17 , & V_25 -> V_33 ) ;
F_36 ( & V_37 , V_42 ) ;
}
static long
F_37 ( struct V_24 * V_25 )
{
struct V_9 * V_10 , * V_43 ;
long V_44 = 0 ;
F_38 (rp, tmp, &b->lru_head, c_lru) {
if ( V_10 -> V_13 == V_45 )
continue;
if ( F_39 ( & V_23 ) <= V_29 &&
F_40 ( V_41 , V_10 -> V_40 + V_42 ) )
break;
F_12 ( V_10 ) ;
V_44 ++ ;
}
return V_44 ;
}
static long
F_41 ( void )
{
unsigned int V_28 ;
long V_44 = 0 ;
bool V_46 = true ;
for ( V_28 = 0 ; V_28 < V_34 ; V_28 ++ ) {
struct V_24 * V_25 = & V_32 [ V_28 ] ;
if ( F_31 ( & V_25 -> V_33 ) )
continue;
F_18 ( & V_25 -> V_26 ) ;
V_44 += F_37 ( V_25 ) ;
if ( ! F_31 ( & V_25 -> V_33 ) )
V_46 = false ;
F_19 ( & V_25 -> V_26 ) ;
}
if ( ! V_46 )
F_42 ( V_47 , & V_37 , V_42 ) ;
return V_44 ;
}
static void
F_43 ( struct V_48 * V_49 )
{
F_41 () ;
}
static unsigned long
F_44 ( struct V_50 * V_51 , struct V_52 * V_53 )
{
return F_39 ( & V_23 ) ;
}
static unsigned long
F_45 ( struct V_50 * V_51 , struct V_52 * V_53 )
{
return F_41 () ;
}
static T_3
F_46 ( struct V_54 * V_55 )
{
int V_56 ;
unsigned int V_57 ;
T_3 V_58 ;
struct V_59 * V_60 = & V_55 -> V_61 ;
const unsigned char * V_62 = V_60 -> V_39 [ 0 ] . V_20 ;
T_4 V_63 = F_3 ( T_4 , V_60 -> V_39 [ 0 ] . V_22 + V_60 -> V_64 ,
V_65 ) ;
T_4 V_66 = F_47 ( V_60 -> V_39 [ 0 ] . V_22 , V_63 ) ;
V_58 = F_48 ( V_62 , V_66 , 0 ) ;
V_63 -= V_66 ;
V_56 = V_60 -> V_67 / V_68 ;
V_57 = V_60 -> V_67 & ~ V_69 ;
while ( V_63 ) {
V_62 = F_49 ( V_60 -> V_70 [ V_56 ] ) + V_57 ;
V_66 = F_3 ( T_4 , V_68 - V_57 , V_63 ) ;
V_58 = F_48 ( V_62 , V_66 , V_58 ) ;
V_63 -= V_66 ;
V_57 = 0 ;
++ V_56 ;
}
return V_58 ;
}
static bool
F_50 ( struct V_54 * V_55 , T_3 V_58 , struct V_9 * V_10 )
{
if ( V_55 -> V_71 != V_10 -> V_72 )
return false ;
if ( V_58 != V_10 -> V_73 ) {
++ V_74 ;
return false ;
}
if ( V_55 -> V_75 != V_10 -> V_76 ||
V_55 -> V_77 != V_10 -> V_78 ||
V_55 -> V_79 != V_10 -> V_80 ||
V_55 -> V_61 . V_66 != V_10 -> V_81 ||
! F_51 ( F_52 ( V_55 ) , (struct V_82 * ) & V_10 -> V_83 ) ||
F_53 ( F_52 ( V_55 ) ) != F_53 ( (struct V_82 * ) & V_10 -> V_83 ) )
return false ;
return true ;
}
static struct V_9 *
F_54 ( struct V_24 * V_25 , struct V_54 * V_55 ,
T_3 V_58 )
{
struct V_9 * V_10 , * V_84 = NULL ;
struct V_38 * V_85 = & V_25 -> V_33 ;
unsigned int V_86 = 0 ;
F_55 (rp, rh, c_lru) {
++ V_86 ;
if ( F_50 ( V_55 , V_58 , V_10 ) ) {
V_84 = V_10 ;
break;
}
}
if ( V_86 > V_87 ) {
V_87 = V_86 ;
V_88 = F_39 ( & V_23 ) ;
} else if ( V_86 == V_87 ) {
V_88 = F_3 (unsigned int,
longest_chain_cachesize,
atomic_read(&num_drc_entries)) ;
}
return V_84 ;
}
int
F_56 ( struct V_54 * V_55 )
{
struct V_9 * V_10 , * V_89 ;
T_2 V_7 = V_55 -> V_71 ;
T_1 V_90 = V_55 -> V_77 ,
V_91 = V_55 -> V_79 ,
V_92 = V_55 -> V_75 ;
T_3 V_58 ;
T_1 V_93 = F_6 ( V_7 ) ;
struct V_24 * V_25 = & V_32 [ V_93 ] ;
unsigned long V_94 ;
int type = V_55 -> V_95 ;
int V_96 = V_97 ;
V_55 -> V_98 = NULL ;
if ( type == V_16 ) {
V_99 . V_100 ++ ;
return V_96 ;
}
V_58 = F_46 ( V_55 ) ;
V_10 = F_9 () ;
F_18 ( & V_25 -> V_26 ) ;
if ( F_57 ( V_10 ) ) {
F_58 ( & V_23 ) ;
V_21 += sizeof( * V_10 ) ;
}
F_37 ( V_25 ) ;
V_89 = F_54 ( V_25 , V_55 , V_58 ) ;
if ( V_89 ) {
if ( F_57 ( V_10 ) )
F_12 ( V_10 ) ;
V_10 = V_89 ;
goto V_101;
}
if ( ! V_10 ) {
F_59 ( L_3 ) ;
goto V_102;
}
V_99 . V_103 ++ ;
V_55 -> V_98 = V_10 ;
V_10 -> V_13 = V_45 ;
V_10 -> V_72 = V_7 ;
V_10 -> V_76 = V_92 ;
F_60 ( (struct V_82 * ) & V_10 -> V_83 , F_52 ( V_55 ) ) ;
F_61 ( (struct V_82 * ) & V_10 -> V_83 , F_53 ( F_52 ( V_55 ) ) ) ;
V_10 -> V_78 = V_90 ;
V_10 -> V_80 = V_91 ;
V_10 -> V_81 = V_55 -> V_61 . V_66 ;
V_10 -> V_73 = V_58 ;
F_34 ( V_25 , V_10 ) ;
if ( V_10 -> V_15 == V_18 ) {
V_21 -= V_10 -> V_19 . V_22 ;
F_13 ( V_10 -> V_19 . V_20 ) ;
V_10 -> V_19 . V_20 = NULL ;
}
V_10 -> V_15 = V_16 ;
V_102:
F_19 ( & V_25 -> V_26 ) ;
return V_96 ;
V_101:
V_99 . V_104 ++ ;
V_94 = V_41 - V_10 -> V_40 ;
F_34 ( V_25 , V_10 ) ;
V_96 = V_105 ;
if ( V_10 -> V_13 == V_45 || V_94 < V_106 )
goto V_102;
V_96 = V_97 ;
if ( ! V_55 -> V_107 && V_10 -> V_108 )
goto V_102;
switch ( V_10 -> V_15 ) {
case V_16 :
break;
case V_109 :
F_62 ( & V_55 -> V_110 . V_39 [ 0 ] , V_10 -> V_111 ) ;
V_96 = V_112 ;
break;
case V_18 :
if ( ! F_63 ( V_55 , & V_10 -> V_19 ) )
goto V_102;
V_96 = V_112 ;
break;
default:
F_27 ( V_113 L_4 , V_10 -> V_15 ) ;
F_12 ( V_10 ) ;
}
goto V_102;
}
void
F_64 ( struct V_54 * V_55 , int V_114 , T_2 * V_115 )
{
struct V_9 * V_10 = V_55 -> V_98 ;
struct V_116 * V_117 = & V_55 -> V_110 . V_39 [ 0 ] , * V_118 ;
T_1 V_93 ;
struct V_24 * V_25 ;
int V_66 ;
T_4 V_119 = 0 ;
if ( ! V_10 )
return;
V_93 = F_6 ( V_10 -> V_72 ) ;
V_25 = & V_32 [ V_93 ] ;
V_66 = V_117 -> V_22 - ( ( char * ) V_115 - ( char * ) V_117 -> V_20 ) ;
V_66 >>= 2 ;
if ( ! V_115 || V_66 > ( 256 >> 2 ) ) {
F_17 ( V_25 , V_10 ) ;
return;
}
switch ( V_114 ) {
case V_109 :
if ( V_66 != 1 )
F_27 ( L_5 , V_66 ) ;
V_10 -> V_111 = * V_115 ;
break;
case V_18 :
V_118 = & V_10 -> V_19 ;
V_119 = V_66 << 2 ;
V_118 -> V_20 = F_65 ( V_119 , V_12 ) ;
if ( ! V_118 -> V_20 ) {
F_17 ( V_25 , V_10 ) ;
return;
}
V_118 -> V_22 = V_119 ;
memcpy ( V_118 -> V_20 , V_115 , V_119 ) ;
break;
case V_16 :
F_17 ( V_25 , V_10 ) ;
return;
}
F_18 ( & V_25 -> V_26 ) ;
V_21 += V_119 ;
F_34 ( V_25 , V_10 ) ;
V_10 -> V_108 = V_55 -> V_107 ;
V_10 -> V_15 = V_114 ;
V_10 -> V_13 = V_120 ;
F_19 ( & V_25 -> V_26 ) ;
return;
}
static int
F_63 ( struct V_54 * V_55 , struct V_116 * V_121 )
{
struct V_116 * V_122 = & V_55 -> V_110 . V_39 [ 0 ] ;
if ( V_122 -> V_22 + V_121 -> V_22 > V_68 ) {
F_27 ( V_113 L_6 ,
V_121 -> V_22 ) ;
return 0 ;
}
memcpy ( ( char * ) V_122 -> V_20 + V_122 -> V_22 , V_121 -> V_20 , V_121 -> V_22 ) ;
V_122 -> V_22 += V_121 -> V_22 ;
return 1 ;
}
static int F_66 ( struct V_123 * V_124 , void * V_125 )
{
F_67 ( V_124 , L_7 , V_29 ) ;
F_67 ( V_124 , L_8 ,
F_39 ( & V_23 ) ) ;
F_67 ( V_124 , L_9 , 1 << V_8 ) ;
F_67 ( V_124 , L_10 , V_21 ) ;
F_67 ( V_124 , L_11 , V_99 . V_104 ) ;
F_67 ( V_124 , L_12 , V_99 . V_103 ) ;
F_67 ( V_124 , L_13 , V_99 . V_100 ) ;
F_67 ( V_124 , L_14 , V_74 ) ;
F_67 ( V_124 , L_15 , V_87 ) ;
F_67 ( V_124 , L_16 , V_88 ) ;
return 0 ;
}
int F_68 ( struct V_126 * V_126 , struct V_127 * V_127 )
{
return F_69 ( V_127 , F_66 , NULL ) ;
}
