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
int V_29 = 0 ;
V_30 = F_1 () ;
F_21 ( & V_23 , 0 ) ;
V_27 = F_4 ( V_30 ) ;
V_8 = F_22 ( V_27 ) ;
V_29 = F_23 ( & V_31 ) ;
if ( V_29 )
return V_29 ;
V_11 = F_24 ( L_1 , sizeof( struct V_9 ) ,
0 , 0 , NULL ) ;
if ( ! V_11 )
goto V_32;
V_33 = F_25 ( V_27 , sizeof( * V_33 ) , V_12 ) ;
if ( ! V_33 )
goto V_32;
for ( V_28 = 0 ; V_28 < V_27 ; V_28 ++ ) {
F_11 ( & V_33 [ V_28 ] . V_34 ) ;
F_26 ( & V_33 [ V_28 ] . V_26 ) ;
}
V_35 = V_27 ;
return 0 ;
V_32:
F_27 ( V_36 L_2 ) ;
F_28 () ;
return - V_37 ;
}
void F_28 ( void )
{
struct V_9 * V_10 ;
unsigned int V_28 ;
F_29 ( & V_31 ) ;
F_30 ( & V_38 ) ;
for ( V_28 = 0 ; V_28 < V_35 ; V_28 ++ ) {
struct V_39 * V_40 = & V_33 [ V_28 ] . V_34 ;
while ( ! F_31 ( V_40 ) ) {
V_10 = F_32 ( V_40 , struct V_9 , V_17 ) ;
F_12 ( V_10 ) ;
}
}
F_13 ( V_33 ) ;
V_33 = NULL ;
V_35 = 0 ;
if ( V_11 ) {
F_33 ( V_11 ) ;
V_11 = NULL ;
}
}
static void
F_34 ( struct V_24 * V_25 , struct V_9 * V_10 )
{
V_10 -> V_41 = V_42 ;
F_35 ( & V_10 -> V_17 , & V_25 -> V_34 ) ;
F_36 ( & V_38 , V_43 ) ;
}
static long
F_37 ( struct V_24 * V_25 )
{
struct V_9 * V_10 , * V_44 ;
long V_45 = 0 ;
F_38 (rp, tmp, &b->lru_head, c_lru) {
if ( V_10 -> V_13 == V_46 )
continue;
if ( F_39 ( & V_23 ) <= V_30 &&
F_40 ( V_42 , V_10 -> V_41 + V_43 ) )
break;
F_12 ( V_10 ) ;
V_45 ++ ;
}
return V_45 ;
}
static long
F_41 ( void )
{
unsigned int V_28 ;
long V_45 = 0 ;
bool V_47 = true ;
for ( V_28 = 0 ; V_28 < V_35 ; V_28 ++ ) {
struct V_24 * V_25 = & V_33 [ V_28 ] ;
if ( F_31 ( & V_25 -> V_34 ) )
continue;
F_18 ( & V_25 -> V_26 ) ;
V_45 += F_37 ( V_25 ) ;
if ( ! F_31 ( & V_25 -> V_34 ) )
V_47 = false ;
F_19 ( & V_25 -> V_26 ) ;
}
if ( ! V_47 )
F_42 ( V_48 , & V_38 , V_43 ) ;
return V_45 ;
}
static void
F_43 ( struct V_49 * V_50 )
{
F_41 () ;
}
static unsigned long
F_44 ( struct V_51 * V_52 , struct V_53 * V_54 )
{
return F_39 ( & V_23 ) ;
}
static unsigned long
F_45 ( struct V_51 * V_52 , struct V_53 * V_54 )
{
return F_41 () ;
}
static T_3
F_46 ( struct V_55 * V_56 )
{
int V_57 ;
unsigned int V_58 ;
T_3 V_59 ;
struct V_60 * V_61 = & V_56 -> V_62 ;
const unsigned char * V_63 = V_61 -> V_40 [ 0 ] . V_20 ;
T_4 V_64 = F_3 ( T_4 , V_61 -> V_40 [ 0 ] . V_22 + V_61 -> V_65 ,
V_66 ) ;
T_4 V_67 = F_47 ( V_61 -> V_40 [ 0 ] . V_22 , V_64 ) ;
V_59 = F_48 ( V_63 , V_67 , 0 ) ;
V_64 -= V_67 ;
V_57 = V_61 -> V_68 / V_69 ;
V_58 = V_61 -> V_68 & ~ V_70 ;
while ( V_64 ) {
V_63 = F_49 ( V_61 -> V_71 [ V_57 ] ) + V_58 ;
V_67 = F_3 ( T_4 , V_69 - V_58 , V_64 ) ;
V_59 = F_48 ( V_63 , V_67 , V_59 ) ;
V_64 -= V_67 ;
V_58 = 0 ;
++ V_57 ;
}
return V_59 ;
}
static bool
F_50 ( struct V_55 * V_56 , T_3 V_59 , struct V_9 * V_10 )
{
if ( V_56 -> V_72 != V_10 -> V_73 )
return false ;
if ( V_59 != V_10 -> V_74 ) {
++ V_75 ;
return false ;
}
if ( V_56 -> V_76 != V_10 -> V_77 ||
V_56 -> V_78 != V_10 -> V_79 ||
V_56 -> V_80 != V_10 -> V_81 ||
V_56 -> V_62 . V_67 != V_10 -> V_82 ||
! F_51 ( F_52 ( V_56 ) , (struct V_83 * ) & V_10 -> V_84 ) ||
F_53 ( F_52 ( V_56 ) ) != F_53 ( (struct V_83 * ) & V_10 -> V_84 ) )
return false ;
return true ;
}
static struct V_9 *
F_54 ( struct V_24 * V_25 , struct V_55 * V_56 ,
T_3 V_59 )
{
struct V_9 * V_10 , * V_85 = NULL ;
struct V_39 * V_86 = & V_25 -> V_34 ;
unsigned int V_87 = 0 ;
F_55 (rp, rh, c_lru) {
++ V_87 ;
if ( F_50 ( V_56 , V_59 , V_10 ) ) {
V_85 = V_10 ;
break;
}
}
if ( V_87 > V_88 ) {
V_88 = V_87 ;
V_89 = F_39 ( & V_23 ) ;
} else if ( V_87 == V_88 ) {
V_89 = F_3 (unsigned int,
longest_chain_cachesize,
atomic_read(&num_drc_entries)) ;
}
return V_85 ;
}
int
F_56 ( struct V_55 * V_56 )
{
struct V_9 * V_10 , * V_90 ;
T_2 V_7 = V_56 -> V_72 ;
T_1 V_91 = V_56 -> V_78 ,
V_92 = V_56 -> V_80 ,
V_93 = V_56 -> V_76 ;
T_3 V_59 ;
T_1 V_94 = F_6 ( V_7 ) ;
struct V_24 * V_25 = & V_33 [ V_94 ] ;
unsigned long V_95 ;
int type = V_56 -> V_96 ;
int V_97 = V_98 ;
V_56 -> V_99 = NULL ;
if ( type == V_16 ) {
V_100 . V_101 ++ ;
return V_97 ;
}
V_59 = F_46 ( V_56 ) ;
V_10 = F_9 () ;
F_18 ( & V_25 -> V_26 ) ;
if ( F_57 ( V_10 ) ) {
F_58 ( & V_23 ) ;
V_21 += sizeof( * V_10 ) ;
}
F_37 ( V_25 ) ;
V_90 = F_54 ( V_25 , V_56 , V_59 ) ;
if ( V_90 ) {
if ( F_57 ( V_10 ) )
F_12 ( V_10 ) ;
V_10 = V_90 ;
goto V_102;
}
if ( ! V_10 ) {
F_59 ( L_3 ) ;
goto V_103;
}
V_100 . V_104 ++ ;
V_56 -> V_99 = V_10 ;
V_10 -> V_13 = V_46 ;
V_10 -> V_73 = V_7 ;
V_10 -> V_77 = V_93 ;
F_60 ( (struct V_83 * ) & V_10 -> V_84 , F_52 ( V_56 ) ) ;
F_61 ( (struct V_83 * ) & V_10 -> V_84 , F_53 ( F_52 ( V_56 ) ) ) ;
V_10 -> V_79 = V_91 ;
V_10 -> V_81 = V_92 ;
V_10 -> V_82 = V_56 -> V_62 . V_67 ;
V_10 -> V_74 = V_59 ;
F_34 ( V_25 , V_10 ) ;
if ( V_10 -> V_15 == V_18 ) {
V_21 -= V_10 -> V_19 . V_22 ;
F_13 ( V_10 -> V_19 . V_20 ) ;
V_10 -> V_19 . V_20 = NULL ;
}
V_10 -> V_15 = V_16 ;
V_103:
F_19 ( & V_25 -> V_26 ) ;
return V_97 ;
V_102:
V_100 . V_105 ++ ;
V_95 = V_42 - V_10 -> V_41 ;
F_34 ( V_25 , V_10 ) ;
V_97 = V_106 ;
if ( V_10 -> V_13 == V_46 || V_95 < V_107 )
goto V_103;
V_97 = V_98 ;
if ( ! F_62 ( V_108 , & V_56 -> V_109 ) && V_10 -> V_110 )
goto V_103;
switch ( V_10 -> V_15 ) {
case V_16 :
break;
case V_111 :
F_63 ( & V_56 -> V_112 . V_40 [ 0 ] , V_10 -> V_113 ) ;
V_97 = V_114 ;
break;
case V_18 :
if ( ! F_64 ( V_56 , & V_10 -> V_19 ) )
goto V_103;
V_97 = V_114 ;
break;
default:
F_27 ( V_115 L_4 , V_10 -> V_15 ) ;
F_12 ( V_10 ) ;
}
goto V_103;
}
void
F_65 ( struct V_55 * V_56 , int V_116 , T_2 * V_117 )
{
struct V_9 * V_10 = V_56 -> V_99 ;
struct V_118 * V_119 = & V_56 -> V_112 . V_40 [ 0 ] , * V_120 ;
T_1 V_94 ;
struct V_24 * V_25 ;
int V_67 ;
T_4 V_121 = 0 ;
if ( ! V_10 )
return;
V_94 = F_6 ( V_10 -> V_73 ) ;
V_25 = & V_33 [ V_94 ] ;
V_67 = V_119 -> V_22 - ( ( char * ) V_117 - ( char * ) V_119 -> V_20 ) ;
V_67 >>= 2 ;
if ( ! V_117 || V_67 > ( 256 >> 2 ) ) {
F_17 ( V_25 , V_10 ) ;
return;
}
switch ( V_116 ) {
case V_111 :
if ( V_67 != 1 )
F_27 ( L_5 , V_67 ) ;
V_10 -> V_113 = * V_117 ;
break;
case V_18 :
V_120 = & V_10 -> V_19 ;
V_121 = V_67 << 2 ;
V_120 -> V_20 = F_66 ( V_121 , V_12 ) ;
if ( ! V_120 -> V_20 ) {
F_17 ( V_25 , V_10 ) ;
return;
}
V_120 -> V_22 = V_121 ;
memcpy ( V_120 -> V_20 , V_117 , V_121 ) ;
break;
case V_16 :
F_17 ( V_25 , V_10 ) ;
return;
}
F_18 ( & V_25 -> V_26 ) ;
V_21 += V_121 ;
F_34 ( V_25 , V_10 ) ;
V_10 -> V_110 = F_62 ( V_108 , & V_56 -> V_109 ) ;
V_10 -> V_15 = V_116 ;
V_10 -> V_13 = V_122 ;
F_19 ( & V_25 -> V_26 ) ;
return;
}
static int
F_64 ( struct V_55 * V_56 , struct V_118 * V_123 )
{
struct V_118 * V_124 = & V_56 -> V_112 . V_40 [ 0 ] ;
if ( V_124 -> V_22 + V_123 -> V_22 > V_69 ) {
F_27 ( V_115 L_6 ,
V_123 -> V_22 ) ;
return 0 ;
}
memcpy ( ( char * ) V_124 -> V_20 + V_124 -> V_22 , V_123 -> V_20 , V_123 -> V_22 ) ;
V_124 -> V_22 += V_123 -> V_22 ;
return 1 ;
}
static int F_67 ( struct V_125 * V_126 , void * V_127 )
{
F_68 ( V_126 , L_7 , V_30 ) ;
F_68 ( V_126 , L_8 ,
F_39 ( & V_23 ) ) ;
F_68 ( V_126 , L_9 , 1 << V_8 ) ;
F_68 ( V_126 , L_10 , V_21 ) ;
F_68 ( V_126 , L_11 , V_100 . V_105 ) ;
F_68 ( V_126 , L_12 , V_100 . V_104 ) ;
F_68 ( V_126 , L_13 , V_100 . V_101 ) ;
F_68 ( V_126 , L_14 , V_75 ) ;
F_68 ( V_126 , L_15 , V_88 ) ;
F_68 ( V_126 , L_16 , V_89 ) ;
return 0 ;
}
int F_69 ( struct V_128 * V_128 , struct V_129 * V_129 )
{
return F_70 ( V_129 , F_67 , NULL ) ;
}
