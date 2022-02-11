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
static struct V_7 *
F_6 ( void )
{
struct V_7 * V_8 ;
V_8 = F_7 ( V_9 , V_10 ) ;
if ( V_8 ) {
V_8 -> V_11 = V_12 ;
V_8 -> V_13 = V_14 ;
F_8 ( & V_8 -> V_15 ) ;
F_9 ( & V_8 -> V_16 ) ;
}
return V_8 ;
}
static void
F_10 ( struct V_7 * V_8 )
{
F_11 ( & V_8 -> V_16 ) ;
F_12 ( & V_8 -> V_15 ) ;
}
static void
F_13 ( struct V_7 * V_8 )
{
if ( V_8 -> V_13 == V_17 && V_8 -> V_18 . V_19 ) {
V_20 -= V_8 -> V_18 . V_21 ;
F_14 ( V_8 -> V_18 . V_19 ) ;
}
if ( ! F_15 ( & V_8 -> V_16 ) )
F_16 ( & V_8 -> V_16 ) ;
F_17 ( & V_8 -> V_15 ) ;
-- V_22 ;
V_20 -= sizeof( * V_8 ) ;
F_18 ( V_9 , V_8 ) ;
}
static void
F_19 ( struct V_7 * V_8 )
{
F_20 ( & V_23 ) ;
F_13 ( V_8 ) ;
F_21 ( & V_23 ) ;
}
int F_22 ( void )
{
unsigned int V_24 ;
F_8 ( & V_25 ) ;
V_26 = F_1 () ;
V_22 = 0 ;
V_24 = F_4 ( V_26 ) ;
V_27 = F_23 ( V_24 ) ;
F_24 ( & V_28 ) ;
V_9 = F_25 ( L_1 , sizeof( struct V_7 ) ,
0 , 0 , NULL ) ;
if ( ! V_9 )
goto V_29;
V_30 = F_26 ( V_24 , sizeof( struct V_31 ) , V_10 ) ;
if ( ! V_30 )
goto V_29;
return 0 ;
V_29:
F_27 ( V_32 L_2 ) ;
F_28 () ;
return - V_33 ;
}
void F_28 ( void )
{
struct V_7 * V_8 ;
F_29 ( & V_28 ) ;
F_30 ( & V_34 ) ;
while ( ! F_31 ( & V_25 ) ) {
V_8 = F_32 ( V_25 . V_35 , struct V_7 , V_15 ) ;
F_13 ( V_8 ) ;
}
F_14 ( V_30 ) ;
V_30 = NULL ;
if ( V_9 ) {
F_33 ( V_9 ) ;
V_9 = NULL ;
}
}
static void
F_34 ( struct V_7 * V_8 )
{
V_8 -> V_36 = V_37 ;
F_35 ( & V_8 -> V_15 , & V_25 ) ;
F_36 ( & V_34 , V_38 ) ;
}
static void
F_37 ( struct V_7 * V_8 )
{
F_11 ( & V_8 -> V_16 ) ;
F_38 ( & V_8 -> V_16 , V_30 + F_39 ( V_8 -> V_39 , V_27 ) ) ;
}
static inline bool
F_40 ( struct V_7 * V_8 )
{
return V_8 -> V_11 != V_40 &&
F_41 ( V_37 , V_8 -> V_36 + V_38 ) ;
}
static long
F_42 ( void )
{
struct V_7 * V_8 , * V_41 ;
long V_42 = 0 ;
F_43 (rp, tmp, &lru_head, c_lru) {
if ( ! F_40 ( V_8 ) &&
V_22 <= V_26 )
break;
F_13 ( V_8 ) ;
V_42 ++ ;
}
if ( F_31 ( & V_25 ) )
F_44 ( & V_34 ) ;
else
F_45 ( V_43 , & V_34 , V_38 ) ;
return V_42 ;
}
static void
F_46 ( struct V_44 * V_45 )
{
F_20 ( & V_23 ) ;
F_42 () ;
F_21 ( & V_23 ) ;
}
static unsigned long
F_47 ( struct V_46 * V_47 , struct V_48 * V_49 )
{
unsigned long V_50 ;
F_20 ( & V_23 ) ;
V_50 = V_22 ;
F_21 ( & V_23 ) ;
return V_50 ;
}
static unsigned long
F_48 ( struct V_46 * V_47 , struct V_48 * V_49 )
{
unsigned long V_42 ;
F_20 ( & V_23 ) ;
V_42 = F_42 () ;
F_21 ( & V_23 ) ;
return V_42 ;
}
static T_1
F_49 ( struct V_51 * V_52 )
{
int V_53 ;
unsigned int V_54 ;
T_1 V_55 ;
struct V_56 * V_57 = & V_52 -> V_58 ;
const unsigned char * V_59 = V_57 -> V_60 [ 0 ] . V_19 ;
T_2 V_61 = F_3 ( T_2 , V_57 -> V_60 [ 0 ] . V_21 + V_57 -> V_62 ,
V_63 ) ;
T_2 V_64 = F_50 ( V_57 -> V_60 [ 0 ] . V_21 , V_61 ) ;
V_55 = F_51 ( V_59 , V_64 , 0 ) ;
V_61 -= V_64 ;
V_53 = V_57 -> V_65 / V_66 ;
V_54 = V_57 -> V_65 & ~ V_67 ;
while ( V_61 ) {
V_59 = F_52 ( V_57 -> V_68 [ V_53 ] ) + V_54 ;
V_64 = F_3 ( T_2 , V_66 - V_54 , V_61 ) ;
V_55 = F_51 ( V_59 , V_64 , V_55 ) ;
V_61 -= V_64 ;
V_54 = 0 ;
++ V_53 ;
}
return V_55 ;
}
static bool
F_53 ( struct V_51 * V_52 , T_1 V_55 , struct V_7 * V_8 )
{
if ( V_52 -> V_69 != V_8 -> V_39 || V_52 -> V_70 != V_8 -> V_71 ||
V_52 -> V_72 != V_8 -> V_73 || V_52 -> V_74 != V_8 -> V_75 ||
V_52 -> V_58 . V_64 != V_8 -> V_76 ||
! F_54 ( F_55 ( V_52 ) , (struct V_77 * ) & V_8 -> V_78 ) ||
F_56 ( F_55 ( V_52 ) ) != F_56 ( (struct V_77 * ) & V_8 -> V_78 ) )
return false ;
if ( V_55 != V_8 -> V_79 ) {
++ V_80 ;
return false ;
}
return true ;
}
static struct V_7 *
F_57 ( struct V_51 * V_52 , T_1 V_55 )
{
struct V_7 * V_8 , * V_81 = NULL ;
struct V_31 * V_82 ;
unsigned int V_83 = 0 ;
V_82 = & V_30 [ F_39 ( V_52 -> V_69 , V_27 ) ] ;
F_58 (rp, rh, c_hash) {
++ V_83 ;
if ( F_53 ( V_52 , V_55 , V_8 ) ) {
V_81 = V_8 ;
break;
}
}
if ( V_83 > V_84 ) {
V_84 = V_83 ;
V_85 = V_22 ;
} else if ( V_83 == V_84 ) {
V_85 = F_50 ( V_85 ,
V_22 ) ;
}
return V_81 ;
}
int
F_59 ( struct V_51 * V_52 )
{
struct V_7 * V_8 , * V_86 ;
T_3 V_87 = V_52 -> V_69 ;
T_4 V_88 = V_52 -> V_72 ,
V_89 = V_52 -> V_74 ,
V_90 = V_52 -> V_70 ;
T_1 V_55 ;
unsigned long V_91 ;
int type = V_52 -> V_92 ;
int V_93 = V_94 ;
V_52 -> V_95 = NULL ;
if ( type == V_14 ) {
V_96 . V_97 ++ ;
return V_93 ;
}
V_55 = F_49 ( V_52 ) ;
F_20 ( & V_23 ) ;
if ( ! F_31 ( & V_25 ) ) {
V_8 = F_60 ( & V_25 , struct V_7 , V_15 ) ;
if ( F_40 ( V_8 ) ||
V_22 >= V_26 ) {
F_10 ( V_8 ) ;
F_42 () ;
goto V_98;
}
}
F_21 ( & V_23 ) ;
V_8 = F_6 () ;
F_20 ( & V_23 ) ;
if ( F_61 ( V_8 ) ) {
++ V_22 ;
V_20 += sizeof( * V_8 ) ;
}
V_98:
V_86 = F_57 ( V_52 , V_55 ) ;
if ( V_86 ) {
if ( F_61 ( V_8 ) )
F_13 ( V_8 ) ;
V_8 = V_86 ;
goto V_99;
}
if ( ! V_8 ) {
F_62 ( L_3 ) ;
goto V_100;
}
if ( V_22 >= V_26 )
F_13 ( F_60 ( & V_25 ,
struct V_7 , V_15 ) ) ;
V_96 . V_101 ++ ;
V_52 -> V_95 = V_8 ;
V_8 -> V_11 = V_40 ;
V_8 -> V_39 = V_87 ;
V_8 -> V_71 = V_90 ;
F_63 ( (struct V_77 * ) & V_8 -> V_78 , F_55 ( V_52 ) ) ;
F_64 ( (struct V_77 * ) & V_8 -> V_78 , F_56 ( F_55 ( V_52 ) ) ) ;
V_8 -> V_73 = V_88 ;
V_8 -> V_75 = V_89 ;
V_8 -> V_76 = V_52 -> V_58 . V_64 ;
V_8 -> V_79 = V_55 ;
F_37 ( V_8 ) ;
F_34 ( V_8 ) ;
if ( V_8 -> V_13 == V_17 ) {
V_20 -= V_8 -> V_18 . V_21 ;
F_14 ( V_8 -> V_18 . V_19 ) ;
V_8 -> V_18 . V_19 = NULL ;
}
V_8 -> V_13 = V_14 ;
V_100:
F_21 ( & V_23 ) ;
return V_93 ;
V_99:
V_96 . V_102 ++ ;
V_91 = V_37 - V_8 -> V_36 ;
F_34 ( V_8 ) ;
V_93 = V_103 ;
if ( V_8 -> V_11 == V_40 || V_91 < V_104 )
goto V_100;
V_93 = V_94 ;
if ( ! V_52 -> V_105 && V_8 -> V_106 )
goto V_100;
switch ( V_8 -> V_13 ) {
case V_14 :
break;
case V_107 :
F_65 ( & V_52 -> V_108 . V_60 [ 0 ] , V_8 -> V_109 ) ;
V_93 = V_110 ;
break;
case V_17 :
if ( ! F_66 ( V_52 , & V_8 -> V_18 ) )
goto V_100;
V_93 = V_110 ;
break;
default:
F_27 ( V_111 L_4 , V_8 -> V_13 ) ;
F_13 ( V_8 ) ;
}
goto V_100;
}
void
F_67 ( struct V_51 * V_52 , int V_112 , T_3 * V_113 )
{
struct V_7 * V_8 = V_52 -> V_95 ;
struct V_114 * V_115 = & V_52 -> V_108 . V_60 [ 0 ] , * V_116 ;
int V_64 ;
T_2 V_117 = 0 ;
if ( ! V_8 )
return;
V_64 = V_115 -> V_21 - ( ( char * ) V_113 - ( char * ) V_115 -> V_19 ) ;
V_64 >>= 2 ;
if ( ! V_113 || V_64 > ( 256 >> 2 ) ) {
F_19 ( V_8 ) ;
return;
}
switch ( V_112 ) {
case V_107 :
if ( V_64 != 1 )
F_27 ( L_5 , V_64 ) ;
V_8 -> V_109 = * V_113 ;
break;
case V_17 :
V_116 = & V_8 -> V_18 ;
V_117 = V_64 << 2 ;
V_116 -> V_19 = F_68 ( V_117 , V_10 ) ;
if ( ! V_116 -> V_19 ) {
F_19 ( V_8 ) ;
return;
}
V_116 -> V_21 = V_117 ;
memcpy ( V_116 -> V_19 , V_113 , V_117 ) ;
break;
case V_14 :
F_19 ( V_8 ) ;
return;
}
F_20 ( & V_23 ) ;
V_20 += V_117 ;
F_34 ( V_8 ) ;
V_8 -> V_106 = V_52 -> V_105 ;
V_8 -> V_13 = V_112 ;
V_8 -> V_11 = V_118 ;
F_21 ( & V_23 ) ;
return;
}
static int
F_66 ( struct V_51 * V_52 , struct V_114 * V_119 )
{
struct V_114 * V_120 = & V_52 -> V_108 . V_60 [ 0 ] ;
if ( V_120 -> V_21 + V_119 -> V_21 > V_66 ) {
F_27 ( V_111 L_6 ,
V_119 -> V_21 ) ;
return 0 ;
}
memcpy ( ( char * ) V_120 -> V_19 + V_120 -> V_21 , V_119 -> V_19 , V_119 -> V_21 ) ;
V_120 -> V_21 += V_119 -> V_21 ;
return 1 ;
}
static int F_69 ( struct V_121 * V_122 , void * V_123 )
{
F_20 ( & V_23 ) ;
F_70 ( V_122 , L_7 , V_26 ) ;
F_70 ( V_122 , L_8 , V_22 ) ;
F_70 ( V_122 , L_9 , 1 << V_27 ) ;
F_70 ( V_122 , L_10 , V_20 ) ;
F_70 ( V_122 , L_11 , V_96 . V_102 ) ;
F_70 ( V_122 , L_12 , V_96 . V_101 ) ;
F_70 ( V_122 , L_13 , V_96 . V_97 ) ;
F_70 ( V_122 , L_14 , V_80 ) ;
F_70 ( V_122 , L_15 , V_84 ) ;
F_70 ( V_122 , L_16 , V_85 ) ;
F_21 ( & V_23 ) ;
return 0 ;
}
int F_71 ( struct V_124 * V_124 , struct V_125 * V_125 )
{
return F_72 ( V_125 , F_69 , NULL ) ;
}
