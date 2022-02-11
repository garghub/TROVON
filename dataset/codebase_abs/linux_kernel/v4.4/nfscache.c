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
for ( V_28 = 0 ; V_28 < V_35 ; V_28 ++ ) {
struct V_38 * V_39 = & V_33 [ V_28 ] . V_34 ;
while ( ! F_30 ( V_39 ) ) {
V_10 = F_31 ( V_39 , struct V_9 , V_17 ) ;
F_12 ( V_10 ) ;
}
}
F_13 ( V_33 ) ;
V_33 = NULL ;
V_35 = 0 ;
F_32 ( V_11 ) ;
V_11 = NULL ;
}
static void
F_33 ( struct V_24 * V_25 , struct V_9 * V_10 )
{
V_10 -> V_40 = V_41 ;
F_34 ( & V_10 -> V_17 , & V_25 -> V_34 ) ;
}
static long
F_35 ( struct V_24 * V_25 )
{
struct V_9 * V_10 , * V_42 ;
long V_43 = 0 ;
F_36 (rp, tmp, &b->lru_head, c_lru) {
if ( V_10 -> V_13 == V_44 )
continue;
if ( F_37 ( & V_23 ) <= V_30 &&
F_38 ( V_41 , V_10 -> V_40 + V_45 ) )
break;
F_12 ( V_10 ) ;
V_43 ++ ;
}
return V_43 ;
}
static long
F_39 ( void )
{
unsigned int V_28 ;
long V_43 = 0 ;
for ( V_28 = 0 ; V_28 < V_35 ; V_28 ++ ) {
struct V_24 * V_25 = & V_33 [ V_28 ] ;
if ( F_30 ( & V_25 -> V_34 ) )
continue;
F_18 ( & V_25 -> V_26 ) ;
V_43 += F_35 ( V_25 ) ;
F_19 ( & V_25 -> V_26 ) ;
}
return V_43 ;
}
static unsigned long
F_40 ( struct V_46 * V_47 , struct V_48 * V_49 )
{
return F_37 ( & V_23 ) ;
}
static unsigned long
F_41 ( struct V_46 * V_47 , struct V_48 * V_49 )
{
return F_39 () ;
}
static T_3
F_42 ( struct V_50 * V_51 )
{
int V_52 ;
unsigned int V_53 ;
T_3 V_54 ;
struct V_55 * V_56 = & V_51 -> V_57 ;
const unsigned char * V_58 = V_56 -> V_39 [ 0 ] . V_20 ;
T_4 V_59 = F_3 ( T_4 , V_56 -> V_39 [ 0 ] . V_22 + V_56 -> V_60 ,
V_61 ) ;
T_4 V_62 = F_43 ( V_56 -> V_39 [ 0 ] . V_22 , V_59 ) ;
V_54 = F_44 ( V_58 , V_62 , 0 ) ;
V_59 -= V_62 ;
V_52 = V_56 -> V_63 / V_64 ;
V_53 = V_56 -> V_63 & ~ V_65 ;
while ( V_59 ) {
V_58 = F_45 ( V_56 -> V_66 [ V_52 ] ) + V_53 ;
V_62 = F_3 ( T_4 , V_64 - V_53 , V_59 ) ;
V_54 = F_44 ( V_58 , V_62 , V_54 ) ;
V_59 -= V_62 ;
V_53 = 0 ;
++ V_52 ;
}
return V_54 ;
}
static bool
F_46 ( struct V_50 * V_51 , T_3 V_54 , struct V_9 * V_10 )
{
if ( V_51 -> V_67 != V_10 -> V_68 )
return false ;
if ( V_54 != V_10 -> V_69 ) {
++ V_70 ;
return false ;
}
if ( V_51 -> V_71 != V_10 -> V_72 ||
V_51 -> V_73 != V_10 -> V_74 ||
V_51 -> V_75 != V_10 -> V_76 ||
V_51 -> V_57 . V_62 != V_10 -> V_77 ||
! F_47 ( F_48 ( V_51 ) , (struct V_78 * ) & V_10 -> V_79 ) ||
F_49 ( F_48 ( V_51 ) ) != F_49 ( (struct V_78 * ) & V_10 -> V_79 ) )
return false ;
return true ;
}
static struct V_9 *
F_50 ( struct V_24 * V_25 , struct V_50 * V_51 ,
T_3 V_54 )
{
struct V_9 * V_10 , * V_80 = NULL ;
struct V_38 * V_81 = & V_25 -> V_34 ;
unsigned int V_82 = 0 ;
F_51 (rp, rh, c_lru) {
++ V_82 ;
if ( F_46 ( V_51 , V_54 , V_10 ) ) {
V_80 = V_10 ;
break;
}
}
if ( V_82 > V_83 ) {
V_83 = V_82 ;
V_84 = F_37 ( & V_23 ) ;
} else if ( V_82 == V_83 ) {
V_84 = F_3 (unsigned int,
longest_chain_cachesize,
atomic_read(&num_drc_entries)) ;
}
return V_80 ;
}
int
F_52 ( struct V_50 * V_51 )
{
struct V_9 * V_10 , * V_85 ;
T_2 V_7 = V_51 -> V_67 ;
T_1 V_86 = V_51 -> V_73 ,
V_87 = V_51 -> V_75 ,
V_88 = V_51 -> V_71 ;
T_3 V_54 ;
T_1 V_89 = F_6 ( V_7 ) ;
struct V_24 * V_25 = & V_33 [ V_89 ] ;
unsigned long V_90 ;
int type = V_51 -> V_91 ;
int V_92 = V_93 ;
V_51 -> V_94 = NULL ;
if ( type == V_16 ) {
V_95 . V_96 ++ ;
return V_92 ;
}
V_54 = F_42 ( V_51 ) ;
V_10 = F_9 () ;
F_18 ( & V_25 -> V_26 ) ;
if ( F_53 ( V_10 ) ) {
F_54 ( & V_23 ) ;
V_21 += sizeof( * V_10 ) ;
}
F_35 ( V_25 ) ;
V_85 = F_50 ( V_25 , V_51 , V_54 ) ;
if ( V_85 ) {
if ( F_53 ( V_10 ) )
F_12 ( V_10 ) ;
V_10 = V_85 ;
goto V_97;
}
if ( ! V_10 ) {
F_55 ( L_3 ) ;
goto V_98;
}
V_95 . V_99 ++ ;
V_51 -> V_94 = V_10 ;
V_10 -> V_13 = V_44 ;
V_10 -> V_68 = V_7 ;
V_10 -> V_72 = V_88 ;
F_56 ( (struct V_78 * ) & V_10 -> V_79 , F_48 ( V_51 ) ) ;
F_57 ( (struct V_78 * ) & V_10 -> V_79 , F_49 ( F_48 ( V_51 ) ) ) ;
V_10 -> V_74 = V_86 ;
V_10 -> V_76 = V_87 ;
V_10 -> V_77 = V_51 -> V_57 . V_62 ;
V_10 -> V_69 = V_54 ;
F_33 ( V_25 , V_10 ) ;
if ( V_10 -> V_15 == V_18 ) {
V_21 -= V_10 -> V_19 . V_22 ;
F_13 ( V_10 -> V_19 . V_20 ) ;
V_10 -> V_19 . V_20 = NULL ;
}
V_10 -> V_15 = V_16 ;
V_98:
F_19 ( & V_25 -> V_26 ) ;
return V_92 ;
V_97:
V_95 . V_100 ++ ;
V_90 = V_41 - V_10 -> V_40 ;
F_33 ( V_25 , V_10 ) ;
V_92 = V_101 ;
if ( V_10 -> V_13 == V_44 || V_90 < V_102 )
goto V_98;
V_92 = V_93 ;
if ( ! F_58 ( V_103 , & V_51 -> V_104 ) && V_10 -> V_105 )
goto V_98;
switch ( V_10 -> V_15 ) {
case V_16 :
break;
case V_106 :
F_59 ( & V_51 -> V_107 . V_39 [ 0 ] , V_10 -> V_108 ) ;
V_92 = V_109 ;
break;
case V_18 :
if ( ! F_60 ( V_51 , & V_10 -> V_19 ) )
goto V_98;
V_92 = V_109 ;
break;
default:
F_27 ( V_110 L_4 , V_10 -> V_15 ) ;
F_12 ( V_10 ) ;
}
goto V_98;
}
void
F_61 ( struct V_50 * V_51 , int V_111 , T_2 * V_112 )
{
struct V_9 * V_10 = V_51 -> V_94 ;
struct V_113 * V_114 = & V_51 -> V_107 . V_39 [ 0 ] , * V_115 ;
T_1 V_89 ;
struct V_24 * V_25 ;
int V_62 ;
T_4 V_116 = 0 ;
if ( ! V_10 )
return;
V_89 = F_6 ( V_10 -> V_68 ) ;
V_25 = & V_33 [ V_89 ] ;
V_62 = V_114 -> V_22 - ( ( char * ) V_112 - ( char * ) V_114 -> V_20 ) ;
V_62 >>= 2 ;
if ( ! V_112 || V_62 > ( 256 >> 2 ) ) {
F_17 ( V_25 , V_10 ) ;
return;
}
switch ( V_111 ) {
case V_106 :
if ( V_62 != 1 )
F_27 ( L_5 , V_62 ) ;
V_10 -> V_108 = * V_112 ;
break;
case V_18 :
V_115 = & V_10 -> V_19 ;
V_116 = V_62 << 2 ;
V_115 -> V_20 = F_62 ( V_116 , V_12 ) ;
if ( ! V_115 -> V_20 ) {
F_17 ( V_25 , V_10 ) ;
return;
}
V_115 -> V_22 = V_116 ;
memcpy ( V_115 -> V_20 , V_112 , V_116 ) ;
break;
case V_16 :
F_17 ( V_25 , V_10 ) ;
return;
}
F_18 ( & V_25 -> V_26 ) ;
V_21 += V_116 ;
F_33 ( V_25 , V_10 ) ;
V_10 -> V_105 = F_58 ( V_103 , & V_51 -> V_104 ) ;
V_10 -> V_15 = V_111 ;
V_10 -> V_13 = V_117 ;
F_19 ( & V_25 -> V_26 ) ;
return;
}
static int
F_60 ( struct V_50 * V_51 , struct V_113 * V_118 )
{
struct V_113 * V_119 = & V_51 -> V_107 . V_39 [ 0 ] ;
if ( V_119 -> V_22 + V_118 -> V_22 > V_64 ) {
F_27 ( V_110 L_6 ,
V_118 -> V_22 ) ;
return 0 ;
}
memcpy ( ( char * ) V_119 -> V_20 + V_119 -> V_22 , V_118 -> V_20 , V_118 -> V_22 ) ;
V_119 -> V_22 += V_118 -> V_22 ;
return 1 ;
}
static int F_63 ( struct V_120 * V_121 , void * V_122 )
{
F_64 ( V_121 , L_7 , V_30 ) ;
F_64 ( V_121 , L_8 ,
F_37 ( & V_23 ) ) ;
F_64 ( V_121 , L_9 , 1 << V_8 ) ;
F_64 ( V_121 , L_10 , V_21 ) ;
F_64 ( V_121 , L_11 , V_95 . V_100 ) ;
F_64 ( V_121 , L_12 , V_95 . V_99 ) ;
F_64 ( V_121 , L_13 , V_95 . V_96 ) ;
F_64 ( V_121 , L_14 , V_70 ) ;
F_64 ( V_121 , L_15 , V_83 ) ;
F_64 ( V_121 , L_16 , V_84 ) ;
return 0 ;
}
int F_65 ( struct V_123 * V_123 , struct V_124 * V_124 )
{
return F_66 ( V_124 , F_63 , NULL ) ;
}
