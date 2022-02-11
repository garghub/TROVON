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
F_36 ( & V_8 -> V_16 , V_30 + F_37 ( V_8 -> V_39 , V_27 ) ) ;
}
static long
F_38 ( void )
{
struct V_7 * V_8 , * V_40 ;
long V_41 = 0 ;
F_39 (rp, tmp, &lru_head, c_lru) {
if ( V_8 -> V_11 == V_42 )
continue;
if ( V_22 <= V_26 &&
F_40 ( V_37 , V_8 -> V_36 + V_38 ) )
break;
F_10 ( V_8 ) ;
V_41 ++ ;
}
if ( F_28 ( & V_25 ) )
F_41 ( & V_34 ) ;
else
F_42 ( V_43 , & V_34 , V_38 ) ;
return V_41 ;
}
static void
F_43 ( struct V_44 * V_45 )
{
F_17 ( & V_23 ) ;
F_38 () ;
F_18 ( & V_23 ) ;
}
static unsigned long
F_44 ( struct V_46 * V_47 , struct V_48 * V_49 )
{
unsigned long V_50 ;
F_17 ( & V_23 ) ;
V_50 = V_22 ;
F_18 ( & V_23 ) ;
return V_50 ;
}
static unsigned long
F_45 ( struct V_46 * V_47 , struct V_48 * V_49 )
{
unsigned long V_41 ;
F_17 ( & V_23 ) ;
V_41 = F_38 () ;
F_18 ( & V_23 ) ;
return V_41 ;
}
static T_1
F_46 ( struct V_51 * V_52 )
{
int V_53 ;
unsigned int V_54 ;
T_1 V_55 ;
struct V_56 * V_57 = & V_52 -> V_58 ;
const unsigned char * V_59 = V_57 -> V_60 [ 0 ] . V_19 ;
T_2 V_61 = F_3 ( T_2 , V_57 -> V_60 [ 0 ] . V_21 + V_57 -> V_62 ,
V_63 ) ;
T_2 V_64 = F_47 ( V_57 -> V_60 [ 0 ] . V_21 , V_61 ) ;
V_55 = F_48 ( V_59 , V_64 , 0 ) ;
V_61 -= V_64 ;
V_53 = V_57 -> V_65 / V_66 ;
V_54 = V_57 -> V_65 & ~ V_67 ;
while ( V_61 ) {
V_59 = F_49 ( V_57 -> V_68 [ V_53 ] ) + V_54 ;
V_64 = F_3 ( T_2 , V_66 - V_54 , V_61 ) ;
V_55 = F_48 ( V_59 , V_64 , V_55 ) ;
V_61 -= V_64 ;
V_54 = 0 ;
++ V_53 ;
}
return V_55 ;
}
static bool
F_50 ( struct V_51 * V_52 , T_1 V_55 , struct V_7 * V_8 )
{
if ( V_52 -> V_69 != V_8 -> V_39 || V_52 -> V_70 != V_8 -> V_71 ||
V_52 -> V_72 != V_8 -> V_73 || V_52 -> V_74 != V_8 -> V_75 ||
V_52 -> V_58 . V_64 != V_8 -> V_76 ||
! F_51 ( F_52 ( V_52 ) , (struct V_77 * ) & V_8 -> V_78 ) ||
F_53 ( F_52 ( V_52 ) ) != F_53 ( (struct V_77 * ) & V_8 -> V_78 ) )
return false ;
if ( V_55 != V_8 -> V_79 ) {
++ V_80 ;
return false ;
}
return true ;
}
static struct V_7 *
F_54 ( struct V_51 * V_52 , T_1 V_55 )
{
struct V_7 * V_8 , * V_81 = NULL ;
struct V_31 * V_82 ;
unsigned int V_83 = 0 ;
V_82 = & V_30 [ F_37 ( V_52 -> V_69 , V_27 ) ] ;
F_55 (rp, rh, c_hash) {
++ V_83 ;
if ( F_50 ( V_52 , V_55 , V_8 ) ) {
V_81 = V_8 ;
break;
}
}
if ( V_83 > V_84 ) {
V_84 = V_83 ;
V_85 = V_22 ;
} else if ( V_83 == V_84 ) {
V_85 = F_47 ( V_85 ,
V_22 ) ;
}
return V_81 ;
}
int
F_56 ( struct V_51 * V_52 )
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
V_55 = F_46 ( V_52 ) ;
V_8 = F_6 () ;
F_17 ( & V_23 ) ;
if ( F_57 ( V_8 ) ) {
++ V_22 ;
V_20 += sizeof( * V_8 ) ;
}
F_38 () ;
V_86 = F_54 ( V_52 , V_55 ) ;
if ( V_86 ) {
if ( F_57 ( V_8 ) )
F_10 ( V_8 ) ;
V_8 = V_86 ;
goto V_98;
}
if ( ! V_8 ) {
F_58 ( L_3 ) ;
goto V_99;
}
V_96 . V_100 ++ ;
V_52 -> V_95 = V_8 ;
V_8 -> V_11 = V_42 ;
V_8 -> V_39 = V_87 ;
V_8 -> V_71 = V_90 ;
F_59 ( (struct V_77 * ) & V_8 -> V_78 , F_52 ( V_52 ) ) ;
F_60 ( (struct V_77 * ) & V_8 -> V_78 , F_53 ( F_52 ( V_52 ) ) ) ;
V_8 -> V_73 = V_88 ;
V_8 -> V_75 = V_89 ;
V_8 -> V_76 = V_52 -> V_58 . V_64 ;
V_8 -> V_79 = V_55 ;
F_34 ( V_8 ) ;
F_31 ( V_8 ) ;
if ( V_8 -> V_13 == V_17 ) {
V_20 -= V_8 -> V_18 . V_21 ;
F_11 ( V_8 -> V_18 . V_19 ) ;
V_8 -> V_18 . V_19 = NULL ;
}
V_8 -> V_13 = V_14 ;
V_99:
F_18 ( & V_23 ) ;
return V_93 ;
V_98:
V_96 . V_101 ++ ;
V_91 = V_37 - V_8 -> V_36 ;
F_31 ( V_8 ) ;
V_93 = V_102 ;
if ( V_8 -> V_11 == V_42 || V_91 < V_103 )
goto V_99;
V_93 = V_94 ;
if ( ! V_52 -> V_104 && V_8 -> V_105 )
goto V_99;
switch ( V_8 -> V_13 ) {
case V_14 :
break;
case V_106 :
F_61 ( & V_52 -> V_107 . V_60 [ 0 ] , V_8 -> V_108 ) ;
V_93 = V_109 ;
break;
case V_17 :
if ( ! F_62 ( V_52 , & V_8 -> V_18 ) )
goto V_99;
V_93 = V_109 ;
break;
default:
F_24 ( V_110 L_4 , V_8 -> V_13 ) ;
F_10 ( V_8 ) ;
}
goto V_99;
}
void
F_63 ( struct V_51 * V_52 , int V_111 , T_3 * V_112 )
{
struct V_7 * V_8 = V_52 -> V_95 ;
struct V_113 * V_114 = & V_52 -> V_107 . V_60 [ 0 ] , * V_115 ;
int V_64 ;
T_2 V_116 = 0 ;
if ( ! V_8 )
return;
V_64 = V_114 -> V_21 - ( ( char * ) V_112 - ( char * ) V_114 -> V_19 ) ;
V_64 >>= 2 ;
if ( ! V_112 || V_64 > ( 256 >> 2 ) ) {
F_16 ( V_8 ) ;
return;
}
switch ( V_111 ) {
case V_106 :
if ( V_64 != 1 )
F_24 ( L_5 , V_64 ) ;
V_8 -> V_108 = * V_112 ;
break;
case V_17 :
V_115 = & V_8 -> V_18 ;
V_116 = V_64 << 2 ;
V_115 -> V_19 = F_64 ( V_116 , V_10 ) ;
if ( ! V_115 -> V_19 ) {
F_16 ( V_8 ) ;
return;
}
V_115 -> V_21 = V_116 ;
memcpy ( V_115 -> V_19 , V_112 , V_116 ) ;
break;
case V_14 :
F_16 ( V_8 ) ;
return;
}
F_17 ( & V_23 ) ;
V_20 += V_116 ;
F_31 ( V_8 ) ;
V_8 -> V_105 = V_52 -> V_104 ;
V_8 -> V_13 = V_111 ;
V_8 -> V_11 = V_117 ;
F_18 ( & V_23 ) ;
return;
}
static int
F_62 ( struct V_51 * V_52 , struct V_113 * V_118 )
{
struct V_113 * V_119 = & V_52 -> V_107 . V_60 [ 0 ] ;
if ( V_119 -> V_21 + V_118 -> V_21 > V_66 ) {
F_24 ( V_110 L_6 ,
V_118 -> V_21 ) ;
return 0 ;
}
memcpy ( ( char * ) V_119 -> V_19 + V_119 -> V_21 , V_118 -> V_19 , V_118 -> V_21 ) ;
V_119 -> V_21 += V_118 -> V_21 ;
return 1 ;
}
static int F_65 ( struct V_120 * V_121 , void * V_122 )
{
F_17 ( & V_23 ) ;
F_66 ( V_121 , L_7 , V_26 ) ;
F_66 ( V_121 , L_8 , V_22 ) ;
F_66 ( V_121 , L_9 , 1 << V_27 ) ;
F_66 ( V_121 , L_10 , V_20 ) ;
F_66 ( V_121 , L_11 , V_96 . V_101 ) ;
F_66 ( V_121 , L_12 , V_96 . V_100 ) ;
F_66 ( V_121 , L_13 , V_96 . V_97 ) ;
F_66 ( V_121 , L_14 , V_80 ) ;
F_66 ( V_121 , L_15 , V_84 ) ;
F_66 ( V_121 , L_16 , V_85 ) ;
F_18 ( & V_23 ) ;
return 0 ;
}
int F_67 ( struct V_123 * V_123 , struct V_124 * V_124 )
{
return F_68 ( V_124 , F_65 , NULL ) ;
}
