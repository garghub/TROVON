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
if ( V_8 -> V_13 == V_17 && V_8 -> V_18 . V_19 ) {
V_20 -= V_8 -> V_18 . V_21 ;
F_11 ( V_8 -> V_18 . V_19 ) ;
}
if ( ! F_12 ( & V_8 -> V_16 ) )
F_13 ( & V_8 -> V_16 ) ;
F_14 ( & V_8 -> V_15 ) ;
-- V_22 ;
V_20 -= sizeof( * V_8 ) ;
F_15 ( V_9 , V_8 ) ;
}
static void
F_16 ( struct V_7 * V_8 )
{
F_17 ( & V_23 ) ;
F_10 ( V_8 ) ;
F_18 ( & V_23 ) ;
}
int F_19 ( void )
{
unsigned int V_24 ;
F_8 ( & V_25 ) ;
V_26 = F_1 () ;
V_22 = 0 ;
V_24 = F_4 ( V_26 ) ;
V_27 = F_20 ( V_24 ) ;
F_21 ( & V_28 ) ;
V_9 = F_22 ( L_1 , sizeof( struct V_7 ) ,
0 , 0 , NULL ) ;
if ( ! V_9 )
goto V_29;
V_30 = F_23 ( V_24 , sizeof( struct V_31 ) , V_10 ) ;
if ( ! V_30 )
goto V_29;
return 0 ;
V_29:
F_24 ( V_32 L_2 ) ;
F_25 () ;
return - V_33 ;
}
void F_25 ( void )
{
struct V_7 * V_8 ;
F_26 ( & V_28 ) ;
F_27 ( & V_34 ) ;
while ( ! F_28 ( & V_25 ) ) {
V_8 = F_29 ( V_25 . V_35 , struct V_7 , V_15 ) ;
F_10 ( V_8 ) ;
}
F_11 ( V_30 ) ;
V_30 = NULL ;
if ( V_9 ) {
F_30 ( V_9 ) ;
V_9 = NULL ;
}
}
static void
F_31 ( struct V_7 * V_8 )
{
V_8 -> V_36 = V_37 ;
F_32 ( & V_8 -> V_15 , & V_25 ) ;
F_33 ( & V_34 , V_38 ) ;
}
static void
F_34 ( struct V_7 * V_8 )
{
F_35 ( & V_8 -> V_16 ) ;
F_36 ( & V_8 -> V_16 , V_30 +
F_37 ( ( V_39 V_40 ) V_8 -> V_41 , V_27 ) ) ;
}
static long
F_38 ( void )
{
struct V_7 * V_8 , * V_42 ;
long V_43 = 0 ;
F_39 (rp, tmp, &lru_head, c_lru) {
if ( V_8 -> V_11 == V_44 )
continue;
if ( V_22 <= V_26 &&
F_40 ( V_37 , V_8 -> V_36 + V_38 ) )
break;
F_10 ( V_8 ) ;
V_43 ++ ;
}
if ( F_28 ( & V_25 ) )
F_41 ( & V_34 ) ;
else
F_42 ( V_45 , & V_34 , V_38 ) ;
return V_43 ;
}
static void
F_43 ( struct V_46 * V_47 )
{
F_17 ( & V_23 ) ;
F_38 () ;
F_18 ( & V_23 ) ;
}
static unsigned long
F_44 ( struct V_48 * V_49 , struct V_50 * V_51 )
{
unsigned long V_52 ;
F_17 ( & V_23 ) ;
V_52 = V_22 ;
F_18 ( & V_23 ) ;
return V_52 ;
}
static unsigned long
F_45 ( struct V_48 * V_49 , struct V_50 * V_51 )
{
unsigned long V_43 ;
F_17 ( & V_23 ) ;
V_43 = F_38 () ;
F_18 ( & V_23 ) ;
return V_43 ;
}
static T_1
F_46 ( struct V_53 * V_54 )
{
int V_55 ;
unsigned int V_56 ;
T_1 V_57 ;
struct V_58 * V_59 = & V_54 -> V_60 ;
const unsigned char * V_61 = V_59 -> V_62 [ 0 ] . V_19 ;
T_2 V_63 = F_3 ( T_2 , V_59 -> V_62 [ 0 ] . V_21 + V_59 -> V_64 ,
V_65 ) ;
T_2 V_66 = F_47 ( V_59 -> V_62 [ 0 ] . V_21 , V_63 ) ;
V_57 = F_48 ( V_61 , V_66 , 0 ) ;
V_63 -= V_66 ;
V_55 = V_59 -> V_67 / V_68 ;
V_56 = V_59 -> V_67 & ~ V_69 ;
while ( V_63 ) {
V_61 = F_49 ( V_59 -> V_70 [ V_55 ] ) + V_56 ;
V_66 = F_3 ( T_2 , V_68 - V_56 , V_63 ) ;
V_57 = F_48 ( V_61 , V_66 , V_57 ) ;
V_63 -= V_66 ;
V_56 = 0 ;
++ V_55 ;
}
return V_57 ;
}
static bool
F_50 ( struct V_53 * V_54 , T_1 V_57 , struct V_7 * V_8 )
{
if ( V_54 -> V_71 != V_8 -> V_41 || V_54 -> V_72 != V_8 -> V_73 ||
V_54 -> V_74 != V_8 -> V_75 || V_54 -> V_76 != V_8 -> V_77 ||
V_54 -> V_60 . V_66 != V_8 -> V_78 ||
! F_51 ( F_52 ( V_54 ) , (struct V_79 * ) & V_8 -> V_80 ) ||
F_53 ( F_52 ( V_54 ) ) != F_53 ( (struct V_79 * ) & V_8 -> V_80 ) )
return false ;
if ( V_57 != V_8 -> V_81 ) {
++ V_82 ;
return false ;
}
return true ;
}
static struct V_7 *
F_54 ( struct V_53 * V_54 , T_1 V_57 )
{
struct V_7 * V_8 , * V_83 = NULL ;
struct V_31 * V_84 ;
unsigned int V_85 = 0 ;
V_84 = & V_30 [ F_37 ( ( V_39 V_40 ) V_54 -> V_71 , V_27 ) ] ;
F_55 (rp, rh, c_hash) {
++ V_85 ;
if ( F_50 ( V_54 , V_57 , V_8 ) ) {
V_83 = V_8 ;
break;
}
}
if ( V_85 > V_86 ) {
V_86 = V_85 ;
V_87 = V_22 ;
} else if ( V_85 == V_86 ) {
V_87 = F_47 ( V_87 ,
V_22 ) ;
}
return V_83 ;
}
int
F_56 ( struct V_53 * V_54 )
{
struct V_7 * V_8 , * V_88 ;
T_3 V_89 = V_54 -> V_71 ;
V_40 V_90 = V_54 -> V_74 ,
V_91 = V_54 -> V_76 ,
V_92 = V_54 -> V_72 ;
T_1 V_57 ;
unsigned long V_93 ;
int type = V_54 -> V_94 ;
int V_95 = V_96 ;
V_54 -> V_97 = NULL ;
if ( type == V_14 ) {
V_98 . V_99 ++ ;
return V_95 ;
}
V_57 = F_46 ( V_54 ) ;
V_8 = F_6 () ;
F_17 ( & V_23 ) ;
if ( F_57 ( V_8 ) ) {
++ V_22 ;
V_20 += sizeof( * V_8 ) ;
}
F_38 () ;
V_88 = F_54 ( V_54 , V_57 ) ;
if ( V_88 ) {
if ( F_57 ( V_8 ) )
F_10 ( V_8 ) ;
V_8 = V_88 ;
goto V_100;
}
if ( ! V_8 ) {
F_58 ( L_3 ) ;
goto V_101;
}
V_98 . V_102 ++ ;
V_54 -> V_97 = V_8 ;
V_8 -> V_11 = V_44 ;
V_8 -> V_41 = V_89 ;
V_8 -> V_73 = V_92 ;
F_59 ( (struct V_79 * ) & V_8 -> V_80 , F_52 ( V_54 ) ) ;
F_60 ( (struct V_79 * ) & V_8 -> V_80 , F_53 ( F_52 ( V_54 ) ) ) ;
V_8 -> V_75 = V_90 ;
V_8 -> V_77 = V_91 ;
V_8 -> V_78 = V_54 -> V_60 . V_66 ;
V_8 -> V_81 = V_57 ;
F_34 ( V_8 ) ;
F_31 ( V_8 ) ;
if ( V_8 -> V_13 == V_17 ) {
V_20 -= V_8 -> V_18 . V_21 ;
F_11 ( V_8 -> V_18 . V_19 ) ;
V_8 -> V_18 . V_19 = NULL ;
}
V_8 -> V_13 = V_14 ;
V_101:
F_18 ( & V_23 ) ;
return V_95 ;
V_100:
V_98 . V_103 ++ ;
V_93 = V_37 - V_8 -> V_36 ;
F_31 ( V_8 ) ;
V_95 = V_104 ;
if ( V_8 -> V_11 == V_44 || V_93 < V_105 )
goto V_101;
V_95 = V_96 ;
if ( ! V_54 -> V_106 && V_8 -> V_107 )
goto V_101;
switch ( V_8 -> V_13 ) {
case V_14 :
break;
case V_108 :
F_61 ( & V_54 -> V_109 . V_62 [ 0 ] , V_8 -> V_110 ) ;
V_95 = V_111 ;
break;
case V_17 :
if ( ! F_62 ( V_54 , & V_8 -> V_18 ) )
goto V_101;
V_95 = V_111 ;
break;
default:
F_24 ( V_112 L_4 , V_8 -> V_13 ) ;
F_10 ( V_8 ) ;
}
goto V_101;
}
void
F_63 ( struct V_53 * V_54 , int V_113 , T_3 * V_114 )
{
struct V_7 * V_8 = V_54 -> V_97 ;
struct V_115 * V_116 = & V_54 -> V_109 . V_62 [ 0 ] , * V_117 ;
int V_66 ;
T_2 V_118 = 0 ;
if ( ! V_8 )
return;
V_66 = V_116 -> V_21 - ( ( char * ) V_114 - ( char * ) V_116 -> V_19 ) ;
V_66 >>= 2 ;
if ( ! V_114 || V_66 > ( 256 >> 2 ) ) {
F_16 ( V_8 ) ;
return;
}
switch ( V_113 ) {
case V_108 :
if ( V_66 != 1 )
F_24 ( L_5 , V_66 ) ;
V_8 -> V_110 = * V_114 ;
break;
case V_17 :
V_117 = & V_8 -> V_18 ;
V_118 = V_66 << 2 ;
V_117 -> V_19 = F_64 ( V_118 , V_10 ) ;
if ( ! V_117 -> V_19 ) {
F_16 ( V_8 ) ;
return;
}
V_117 -> V_21 = V_118 ;
memcpy ( V_117 -> V_19 , V_114 , V_118 ) ;
break;
case V_14 :
F_16 ( V_8 ) ;
return;
}
F_17 ( & V_23 ) ;
V_20 += V_118 ;
F_31 ( V_8 ) ;
V_8 -> V_107 = V_54 -> V_106 ;
V_8 -> V_13 = V_113 ;
V_8 -> V_11 = V_119 ;
F_18 ( & V_23 ) ;
return;
}
static int
F_62 ( struct V_53 * V_54 , struct V_115 * V_120 )
{
struct V_115 * V_121 = & V_54 -> V_109 . V_62 [ 0 ] ;
if ( V_121 -> V_21 + V_120 -> V_21 > V_68 ) {
F_24 ( V_112 L_6 ,
V_120 -> V_21 ) ;
return 0 ;
}
memcpy ( ( char * ) V_121 -> V_19 + V_121 -> V_21 , V_120 -> V_19 , V_120 -> V_21 ) ;
V_121 -> V_21 += V_120 -> V_21 ;
return 1 ;
}
static int F_65 ( struct V_122 * V_123 , void * V_124 )
{
F_17 ( & V_23 ) ;
F_66 ( V_123 , L_7 , V_26 ) ;
F_66 ( V_123 , L_8 , V_22 ) ;
F_66 ( V_123 , L_9 , 1 << V_27 ) ;
F_66 ( V_123 , L_10 , V_20 ) ;
F_66 ( V_123 , L_11 , V_98 . V_103 ) ;
F_66 ( V_123 , L_12 , V_98 . V_102 ) ;
F_66 ( V_123 , L_13 , V_98 . V_99 ) ;
F_66 ( V_123 , L_14 , V_82 ) ;
F_66 ( V_123 , L_15 , V_86 ) ;
F_66 ( V_123 , L_16 , V_87 ) ;
F_18 ( & V_23 ) ;
return 0 ;
}
int F_67 ( struct V_125 * V_125 , struct V_126 * V_126 )
{
return F_68 ( V_126 , F_65 , NULL ) ;
}
