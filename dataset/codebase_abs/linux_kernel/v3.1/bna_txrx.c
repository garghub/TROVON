static struct V_1 *
F_1 ( struct V_2 * V_3 , enum V_4 V_5 ,
int V_6 )
{
struct V_1 * V_7 ;
struct V_8 * V_9 ;
F_2 (qe, &ib_mod->intr_active_q) {
V_7 = (struct V_1 * ) V_9 ;
if ( ( V_7 -> V_5 == V_5 ) &&
( V_7 -> V_6 == V_6 ) ) {
V_7 -> V_10 ++ ;
return V_7 ;
}
}
if ( F_3 ( & V_3 -> V_11 ) )
return NULL ;
F_4 ( & V_3 -> V_11 , & V_7 ) ;
F_5 ( & V_7 -> V_9 ) ;
V_7 -> V_10 = 1 ;
V_7 -> V_5 = V_5 ;
V_7 -> V_6 = V_6 ;
F_6 ( & V_7 -> V_9 , & V_3 -> V_12 ) ;
return V_7 ;
}
static void
F_7 ( struct V_2 * V_3 ,
struct V_1 * V_7 )
{
V_7 -> V_10 -- ;
if ( V_7 -> V_10 == 0 ) {
V_7 -> V_13 = NULL ;
F_8 ( & V_7 -> V_9 ) ;
F_5 ( & V_7 -> V_9 ) ;
F_6 ( & V_7 -> V_9 , & V_3 -> V_11 ) ;
}
}
void
F_9 ( struct V_2 * V_3 , struct V_14 * V_14 ,
struct V_15 * V_16 )
{
int V_17 ;
int V_18 ;
int V_19 ;
T_1 V_20 ;
struct V_21 * V_22 ;
unsigned long V_23 ;
V_3 -> V_14 = V_14 ;
V_3 -> V_13 = (struct V_24 * )
V_16 [ V_25 ] . V_26 . V_27 . V_28 [ 0 ] . V_29 ;
V_3 -> V_7 = (struct V_1 * )
V_16 [ V_30 ] . V_26 . V_27 . V_28 [ 0 ] . V_29 ;
V_3 -> V_31 = (struct V_32 * )
V_16 [ V_33 ] . V_26 . V_27 . V_28 [ 0 ] . V_29 ;
F_10 ( & V_3 -> V_34 ) ;
F_10 ( & V_3 -> V_11 ) ;
F_10 ( & V_3 -> V_12 ) ;
for ( V_17 = 0 ; V_17 < V_35 ; V_17 ++ )
F_10 ( & V_3 -> V_36 [ V_17 ] ) ;
for ( V_17 = 0 ; V_17 < V_37 ; V_17 ++ ) {
V_3 -> V_13 [ V_17 ] . V_38 = V_17 ;
V_3 -> V_13 [ V_17 ] . V_39 =
V_16 [ V_40 ] . V_26 . V_27 . V_28 [ V_17 ] . V_29 ;
V_3 -> V_13 [ V_17 ] . V_41 . V_42 =
V_16 [ V_40 ] . V_26 . V_27 . V_28 [ V_17 ] . V_43 . V_42 ;
V_3 -> V_13 [ V_17 ] . V_41 . V_44 =
V_16 [ V_40 ] . V_26 . V_27 . V_28 [ V_17 ] . V_43 . V_44 ;
V_22 = (struct V_21 * ) 0 ;
V_23 = ( unsigned long ) ( & V_22 [ V_17 >> 1 ] . V_45 [ ( V_17 & 0x1 )
* ( 0x20 >> 2 ) ] ) ;
V_3 -> V_13 [ V_17 ] . V_46 . V_47 = V_23 +
F_11 ( V_14 -> V_48 . V_49 ) ;
F_5 ( & V_3 -> V_13 [ V_17 ] . V_9 ) ;
F_6 ( & V_3 -> V_13 [ V_17 ] . V_9 , & V_3 -> V_34 ) ;
F_5 ( & V_3 -> V_7 [ V_17 ] . V_9 ) ;
F_6 ( & V_3 -> V_7 [ V_17 ] . V_9 , & V_3 -> V_11 ) ;
}
V_19 = 0 ;
V_20 = 0 ;
for ( V_17 = 0 ; V_17 < V_35 ; V_17 ++ ) {
for ( V_18 = 0 ; V_18 < V_50 [ V_17 ] . V_51 ; V_18 ++ ) {
F_5 ( & V_3 -> V_31 [ V_19 ] ) ;
V_3 -> V_31 [ V_19 ] . V_52 =
V_50 [ V_17 ] . V_53 ;
V_3 -> V_31 [ V_19 ] . V_54 = V_20 ;
F_6 ( & V_3 -> V_31 [ V_19 ] . V_9 ,
& V_3 -> V_36 [ V_17 ] ) ;
V_19 ++ ;
V_20 += V_50 [ V_17 ] . V_53 ;
}
}
}
void
F_12 ( struct V_2 * V_3 )
{
int V_17 ;
int V_18 ;
struct V_8 * V_9 ;
V_17 = 0 ;
F_2 (qe, &ib_mod->ib_free_q)
V_17 ++ ;
V_17 = 0 ;
F_2 (qe, &ib_mod->intr_free_q)
V_17 ++ ;
for ( V_17 = 0 ; V_17 < V_35 ; V_17 ++ ) {
V_18 = 0 ;
F_2 (qe, &ib_mod->ibidx_seg_pool[i])
V_18 ++ ;
}
V_3 -> V_14 = NULL ;
}
static struct V_24 *
F_13 ( struct V_2 * V_3 ,
enum V_4 V_5 ,
int V_6 )
{
struct V_24 * V_13 ;
struct V_1 * V_7 ;
if ( V_5 == V_55 )
V_6 = ( 1 << V_6 ) ;
V_7 = F_1 ( V_3 , V_5 , V_6 ) ;
if ( V_7 == NULL )
return NULL ;
if ( V_7 -> V_13 ) {
if ( V_7 -> V_13 -> V_10 == V_56 ) {
F_7 ( V_3 , V_7 ) ;
return NULL ;
}
V_7 -> V_13 -> V_10 ++ ;
return V_7 -> V_13 ;
}
if ( F_3 ( & V_3 -> V_34 ) ) {
F_7 ( V_3 , V_7 ) ;
return NULL ;
}
F_4 ( & V_3 -> V_34 , & V_13 ) ;
F_5 ( & V_13 -> V_9 ) ;
V_13 -> V_10 = 1 ;
V_13 -> V_57 = 0 ;
V_13 -> V_58 = 0 ;
V_13 -> V_7 = V_7 ;
V_13 -> V_31 = NULL ;
V_7 -> V_13 = V_13 ;
V_13 -> V_14 = V_3 -> V_14 ;
return V_13 ;
}
static void
F_14 ( struct V_2 * V_3 , struct V_24 * V_13 )
{
F_7 ( V_3 , V_13 -> V_7 ) ;
V_13 -> V_10 -- ;
if ( V_13 -> V_10 == 0 ) {
V_13 -> V_7 = NULL ;
V_13 -> V_14 = NULL ;
F_6 ( & V_13 -> V_9 , & V_3 -> V_34 ) ;
}
}
static int
F_15 ( struct V_24 * V_13 )
{
struct V_2 * V_3 = & V_13 -> V_14 -> V_3 ;
struct V_32 * V_31 ;
int V_59 ;
int V_60 ;
int V_61 ;
F_16 ( V_13 -> V_58 , V_59 ) ;
if ( V_59 == V_56 )
return - 1 ;
F_17 ( ( V_13 -> V_58 | ( 1 << V_59 ) ) , V_60 ) ;
if ( V_13 -> V_31 && ( V_60 <= V_13 -> V_31 -> V_52 ) ) {
V_13 -> V_58 |= ( 1 << V_59 ) ;
return V_59 ;
}
if ( V_13 -> V_57 )
return - 1 ;
F_18 ( V_60 , V_61 ) ;
while ( 1 ) {
if ( V_61 == V_35 )
return - 1 ;
if ( ! F_3 ( & V_3 -> V_36 [ V_61 ] ) )
break;
V_61 ++ ;
}
F_4 ( & V_3 -> V_36 [ V_61 ] , & V_31 ) ;
F_5 ( & V_31 -> V_9 ) ;
if ( V_13 -> V_31 ) {
F_18 ( V_13 -> V_31 -> V_52 , V_61 ) ;
F_6 ( & V_13 -> V_31 -> V_9 , & V_3 -> V_36 [ V_61 ] ) ;
}
V_13 -> V_31 = V_31 ;
V_13 -> V_58 |= ( 1 << V_59 ) ;
return V_59 ;
}
static void
F_19 ( struct V_24 * V_13 , int V_59 )
{
struct V_2 * V_3 = & V_13 -> V_14 -> V_3 ;
struct V_32 * V_31 ;
int V_60 ;
int V_62 ;
int V_63 ;
V_13 -> V_58 &= ~ ( 1 << V_59 ) ;
if ( V_13 -> V_57 )
return;
F_17 ( V_13 -> V_58 , V_60 ) ;
if ( ! V_60 ) {
F_18 ( V_13 -> V_31 -> V_52 , V_62 ) ;
F_6 ( & V_13 -> V_31 -> V_9 ,
& V_3 -> V_36 [ V_62 ] ) ;
V_13 -> V_31 = NULL ;
return;
}
F_18 ( V_60 , V_63 ) ;
F_18 ( V_13 -> V_31 -> V_52 , V_62 ) ;
while ( V_63 < V_62 ) {
if ( ! F_3 ( & V_3 -> V_36 [ V_63 ] ) )
break;
V_63 ++ ;
}
if ( V_63 < V_62 ) {
F_4 ( & V_3 -> V_36 [ V_63 ] , & V_31 ) ;
F_5 ( & V_31 -> V_9 ) ;
F_6 ( & V_13 -> V_31 -> V_9 ,
& V_3 -> V_36 [ V_62 ] ) ;
V_13 -> V_31 = V_31 ;
}
}
static int
F_20 ( struct V_24 * V_13 , struct F_20 * V_64 )
{
if ( V_13 -> V_57 )
return - 1 ;
V_13 -> V_64 . V_65 = V_64 -> V_65 ;
V_13 -> V_64 . V_66 = V_64 -> V_66 ;
V_13 -> V_64 . V_67 = V_64 -> V_67 ;
V_13 -> V_64 . V_68 = V_64 -> V_68 ;
V_13 -> V_64 . V_68 |= V_69 ;
if ( V_13 -> V_7 -> V_5 == V_70 )
V_13 -> V_64 . V_68 |= V_71 ;
return 0 ;
}
static void
F_21 ( struct V_24 * V_13 )
{
struct V_72 V_73 ;
struct V_72 * V_74 ;
T_2 V_75 ;
T_2 V_76 ;
int V_17 ;
void T_3 * V_77 ;
unsigned long V_23 ;
V_13 -> V_57 ++ ;
if ( V_13 -> V_57 > 1 )
return;
V_73 . V_78 = ( T_2 ) ( V_13 -> V_41 . V_42 ) ;
V_73 . V_79 = ( T_2 ) ( V_13 -> V_41 . V_44 ) ;
V_73 . V_80 = ( ( ( T_2 )
V_13 -> V_64 . V_65 << 16 ) |
( ( T_2 ) V_13 -> V_64 . V_68 << 8 ) |
( V_13 -> V_7 -> V_6 ) ) ;
V_73 . V_81 =
( ( T_2 )
( V_13 -> V_64 . V_66 & 0xf ) << 16 ) |
( ( T_2 ) V_13 -> V_31 -> V_52 << 8 ) |
( V_13 -> V_31 -> V_54 ) ;
V_73 . V_82 = ( ( T_2 )
V_13 -> V_64 . V_67 << 24 ) ;
V_75 = F_22 ( V_83 + V_13 -> V_14 -> V_84 ,
V_85 ) ;
F_23 ( V_75 , V_13 -> V_14 -> V_86 . V_87 ) ;
V_77 = F_24 ( V_13 -> V_14 -> V_48 . V_49 ,
V_85 ) ;
V_74 = (struct V_72 * ) 0 ;
V_23 = ( unsigned long ) & V_74 [ V_13 -> V_38 ] . V_78 ;
F_23 ( F_25 ( V_73 . V_78 ) , V_77 + V_23 ) ;
V_23 = ( unsigned long ) & V_74 [ V_13 -> V_38 ] . V_79 ;
F_23 ( F_25 ( V_73 . V_79 ) , V_77 + V_23 ) ;
V_23 = ( unsigned long ) & V_74 [ V_13 -> V_38 ] . V_80 ;
F_23 ( V_73 . V_80 , V_77 + V_23 ) ;
V_23 = ( unsigned long ) & V_74 [ V_13 -> V_38 ] . V_81 ;
F_23 ( V_73 . V_81 , V_77 + V_23 ) ;
V_23 = ( unsigned long ) & V_74 [ V_13 -> V_38 ] . V_82 ;
F_23 ( V_73 . V_82 , V_77 + V_23 ) ;
V_13 -> V_46 . V_88 = F_26 (
( T_2 ) V_13 -> V_64 . V_65 , 0 ) ;
V_75 = F_22 ( V_83 + V_13 -> V_14 -> V_84 ,
V_89 ) ;
F_23 ( V_75 , V_13 -> V_14 -> V_86 . V_87 ) ;
V_77 = F_24 ( V_13 -> V_14 -> V_48 . V_49 ,
V_89 ) ;
for ( V_17 = 0 ; V_17 < V_13 -> V_31 -> V_52 ; V_17 ++ ) {
V_23 = ( unsigned long )
( ( V_13 -> V_31 -> V_54 + V_17 ) * V_90 ) ;
F_23 ( 0 , V_77 + V_23 ) ;
}
if ( V_13 -> V_7 -> V_5 == V_55 ) {
F_27 ( V_13 -> V_14 , V_76 ) ;
V_76 &= ~ ( V_13 -> V_7 -> V_6 ) ;
F_28 ( V_13 -> V_14 , V_76 ) ;
}
}
static void
F_29 ( struct V_24 * V_13 )
{
T_2 V_76 ;
V_13 -> V_57 -- ;
if ( V_13 -> V_57 == 0 ) {
F_23 ( V_91 ,
V_13 -> V_46 . V_47 ) ;
if ( V_13 -> V_7 -> V_5 == V_55 ) {
F_27 ( V_13 -> V_14 , V_76 ) ;
V_76 |= ( V_13 -> V_7 -> V_6 ) ;
F_28 ( V_13 -> V_14 , V_76 ) ;
}
}
}
static void
F_30 ( struct V_24 * V_13 )
{
V_13 -> V_57 = 0 ;
}
static void
F_31 ( struct V_92 * V_93 )
{
F_32 ( V_93 , V_94 ) ;
}
static void
F_33 ( struct V_92 * V_93 , enum V_95 V_96 )
{
switch ( V_96 ) {
case V_97 :
F_34 ( V_93 , V_98 ) ;
break;
case V_99 :
F_34 ( V_93 , F_33 ) ;
break;
case V_100 :
break;
case V_101 :
F_35 ( V_93 , V_94 ) ;
break;
case V_102 :
case V_103 :
case V_104 :
break;
case V_105 :
V_93 -> V_106 = V_107 ;
F_36 ( V_93 , V_94 ) ;
break;
case V_108 :
V_93 -> V_106 = V_109 ;
F_37 ( V_93 , V_94 ) ;
break;
default:
F_38 ( V_96 ) ;
}
}
static void
F_39 ( struct V_92 * V_93 )
{
F_40 ( V_93 ) ;
F_41 ( V_93 ) ;
F_42 ( V_93 ) ;
}
static void
V_98 ( struct V_92 * V_93 , enum V_95 V_96 )
{
switch ( V_96 ) {
case V_99 :
F_43 ( V_93 , V_110 ) ;
F_34 ( V_93 , V_111 ) ;
break;
case V_100 :
F_35 ( V_93 , V_94 ) ;
F_43 ( V_93 , V_112 ) ;
F_34 ( V_93 , F_33 ) ;
break;
case V_101 :
break;
case V_102 :
if ( ( V_93 -> V_113 != NULL ) &&
( V_93 -> V_114 == 0 ) )
V_93 -> V_114 = 1 ;
if ( V_93 -> V_115 == V_116 )
V_93 -> V_117 |= V_118 ;
V_93 -> V_117 |= V_119 ;
F_34 ( V_93 , V_120 ) ;
break;
case V_105 :
case V_108 :
V_93 -> V_117 |= V_121 ;
break;
default:
F_38 ( V_96 ) ;
}
}
static void
F_44 ( struct V_92 * V_93 )
{
if ( ! F_45 ( V_93 ) ) {
F_34 ( V_93 , V_122 ) ;
}
}
static void
V_120 ( struct V_92 * V_93 , enum V_95 V_96 )
{
switch ( V_96 ) {
case V_99 :
F_43 ( V_93 , V_110 ) ;
F_34 ( V_93 , V_123 ) ;
break;
case V_100 :
F_46 ( V_93 ) ;
F_35 ( V_93 , V_94 ) ;
F_43 ( V_93 , V_112 ) ;
F_34 ( V_93 , F_33 ) ;
break;
case V_101 :
break;
case V_104 :
if ( ! F_45 ( V_93 ) ) {
F_35 ( V_93 , V_94 ) ;
F_34 ( V_93 , V_122 ) ;
}
break;
case V_105 :
case V_108 :
V_93 -> V_117 |= V_121 ;
break;
default:
F_38 ( V_96 ) ;
}
}
static void
F_47 ( struct V_92 * V_93 )
{
F_43 ( V_93 , V_94 ) ;
if ( V_93 -> V_117 & V_121 ) {
if ( V_93 -> V_106 == V_107 )
F_48 ( V_93 , V_105 ) ;
else
F_48 ( V_93 , V_108 ) ;
}
}
static void
V_122 ( struct V_92 * V_93 , enum V_95 V_96 )
{
switch ( V_96 ) {
case V_99 :
F_34 ( V_93 , V_123 ) ;
F_48 ( V_93 , V_104 ) ;
break;
case V_100 :
F_46 ( V_93 ) ;
F_34 ( V_93 , F_33 ) ;
break;
case V_101 :
F_34 ( V_93 , V_120 ) ;
break;
case V_105 :
F_34 ( V_93 , V_124 ) ;
break;
case V_108 :
F_34 ( V_93 , V_125 ) ;
break;
default:
F_38 ( V_96 ) ;
}
}
static void
F_49 ( struct V_92 * V_93 )
{
}
static void
V_123 ( struct V_92 * V_93 , enum V_95 V_96 )
{
switch ( V_96 ) {
case V_100 :
F_46 ( V_93 ) ;
F_34 ( V_93 , F_33 ) ;
break;
case V_104 :
if ( ! F_50 ( V_93 ) ) {
F_34 ( V_93 , V_111 ) ;
F_51 ( V_93 ) ;
}
break;
default:
F_38 ( V_96 ) ;
}
}
static void
F_52 ( struct V_92 * V_93 )
{
}
static void
V_111 ( struct V_92 * V_93 , enum V_95 V_96 )
{
switch ( V_96 ) {
case V_100 :
F_34 ( V_93 , F_33 ) ;
break;
case V_102 :
F_51 ( V_93 ) ;
break;
case V_103 :
F_34 ( V_93 , V_126 ) ;
break;
case V_105 :
V_93 -> V_106 = V_107 ;
break;
case V_108 :
V_93 -> V_106 = V_109 ;
break;
default:
F_38 ( V_96 ) ;
}
}
static void
F_53 ( struct V_92 * V_93 )
{
V_93 -> V_117 &=
~ ( V_121 | V_127 ) ;
F_54 ( V_93 ) ;
}
static void
V_124 ( struct V_92 * V_93 , enum V_95 V_96 )
{
switch ( V_96 ) {
case V_100 :
F_36 ( V_93 , V_112 ) ;
F_34 ( V_93 , F_33 ) ;
break;
case V_103 :
V_93 -> V_106 = V_107 ;
F_36 ( V_93 , V_94 ) ;
F_34 ( V_93 , V_122 ) ;
break;
default:
F_38 ( V_96 ) ;
}
}
static void
F_55 ( struct V_92 * V_93 )
{
V_93 -> V_117 &= ~ ( V_121 ) ;
V_93 -> V_117 |= V_127 ;
F_56 ( V_93 ) ;
}
static void
V_125 ( struct V_92 * V_93 , enum V_95 V_96 )
{
switch ( V_96 ) {
case V_100 :
F_37 ( V_93 , V_112 ) ;
F_34 ( V_93 , F_33 ) ;
break;
case V_102 :
V_93 -> V_106 = V_109 ;
F_37 ( V_93 , V_94 ) ;
F_34 ( V_93 , V_122 ) ;
break;
default:
F_38 ( V_96 ) ;
}
}
static void
F_57 ( struct V_92 * V_93 )
{
F_58 ( V_93 ) ;
}
static void
V_126 ( struct V_92 * V_93 , enum V_95 V_96 )
{
switch ( V_96 ) {
case V_100 :
case V_128 :
F_34 ( V_93 , F_33 ) ;
break;
default:
F_38 ( V_96 ) ;
}
}
static void
F_56 ( struct V_92 * V_93 )
{
struct V_129 V_130 ;
T_2 V_131 [ 2 ] = { 0 , 0 } ;
if ( V_93 -> V_132 < 32 )
V_131 [ 0 ] = 1 << V_93 -> V_132 ;
else
V_131 [ 1 ] = 1 << ( V_93 -> V_132 - 32 ) ;
F_59 ( V_130 . V_133 , V_134 , V_135 , 0 ) ;
V_130 . V_136 [ 0 ] = F_25 ( V_131 [ 0 ] ) ;
V_130 . V_136 [ 1 ] = F_25 ( V_131 [ 1 ] ) ;
V_130 . V_137 = 1 ;
F_60 ( & V_93 -> V_138 , & V_130 , sizeof( V_130 ) ,
V_139 , V_93 ) ;
F_61 ( V_93 -> V_140 -> V_14 , & V_93 -> V_138 ) ;
}
static void
F_54 ( struct V_92 * V_93 )
{
struct V_129 V_130 ;
T_2 V_131 [ 2 ] = { 0 , 0 } ;
if ( V_93 -> V_132 < 32 )
V_131 [ 0 ] = 1 << V_93 -> V_132 ;
else
V_131 [ 1 ] = 1 << ( V_93 -> V_132 - 32 ) ;
F_59 ( V_130 . V_133 , V_134 , V_135 , 0 ) ;
V_130 . V_136 [ 0 ] = F_25 ( V_131 [ 0 ] ) ;
V_130 . V_136 [ 1 ] = F_25 ( V_131 [ 1 ] ) ;
V_130 . V_137 = 0 ;
F_60 ( & V_93 -> V_138 , & V_130 , sizeof( V_130 ) ,
V_141 , V_93 ) ;
F_61 ( V_93 -> V_140 -> V_14 , & V_93 -> V_138 ) ;
}
static void
F_40 ( struct V_92 * V_93 )
{
T_2 V_17 ;
struct V_142 * V_143 ;
struct V_144 * V_145 ;
struct V_14 * V_14 = V_93 -> V_140 -> V_14 ;
void T_3 * V_77 ;
unsigned long V_23 ;
V_77 = F_24 ( V_14 -> V_48 . V_49 ,
V_146 ) ;
V_143 = (struct V_142 * ) 0 ;
if ( V_93 -> V_68 & V_147 ) {
F_23 ( F_22 ( V_148 +
V_14 -> V_84 , V_146 ) ,
V_14 -> V_86 . V_87 ) ;
V_23 = ( unsigned long ) & V_143 [ 0 ] . V_149 ;
F_23 ( 0 , V_77 + V_23 ) ;
for ( V_17 = 0 ; V_17 < V_150 ; V_17 ++ ) {
V_23 = ( unsigned long )
& V_143 [ 0 ] . V_151 [ ( V_150 - 1 ) - V_17 ] ;
F_23 ( F_25 ( V_93 -> V_152 . V_153 [ V_17 ] ) ,
V_77 + V_23 ) ;
}
V_23 = ( unsigned long ) & V_143 [ 0 ] . V_149 ;
F_23 ( V_93 -> V_152 . V_154 | V_93 -> V_152 . V_155 ,
V_77 + V_23 ) ;
}
F_23 ( F_22 (
V_156 + ( V_14 -> V_84 * 2 ) ,
V_157 ) ,
V_14 -> V_86 . V_87 ) ;
V_77 = F_24 ( V_14 -> V_48 . V_49 ,
V_157 ) ;
V_145 = (struct V_144 * ) 0 ;
V_23 = ( unsigned long ) & V_145 [ V_93 -> V_132 ] . V_158 ;
F_23 ( V_93 -> V_68 & V_147 ,
V_77 + V_23 ) ;
V_23 = ( unsigned long ) & V_145 [ V_93 -> V_132 ] . V_159 ;
F_23 ( ( V_93 -> V_68 & V_160 ) | 0x80 ,
V_77 + V_23 ) ;
V_23 = ( unsigned long ) & V_145 [ V_93 -> V_132 ] . V_161 ;
F_23 ( ( V_93 -> V_162 -> V_163 << 16 ) |
( V_93 -> V_164 << 8 ) |
( V_93 -> V_165 . V_166 & V_167 ) | V_93 -> V_168 ,
V_77 + V_23 ) ;
V_23 = ( unsigned long ) & V_145 [ V_93 -> V_132 ] . V_169 ;
F_23 ( ( ( T_2 ) V_93 -> V_170 << 16 ) |
( V_93 -> V_68 &
( V_171 |
V_172 |
V_173 ) ) |
( V_93 -> V_165 . V_166 & ~ V_167 ) |
V_93 -> V_165 . V_174 ,
V_77 + V_23 ) ;
}
void
F_62 ( struct V_92 * V_93 , enum V_175 V_176 )
{
struct V_14 * V_14 = V_93 -> V_140 -> V_14 ;
int V_17 ;
F_23 ( F_22 ( V_156 +
( V_14 -> V_84 * 2 ) , V_177 ) ,
V_14 -> V_86 . V_87 ) ;
if ( V_176 == V_116 ) {
for ( V_17 = 0 ; V_17 <= V_178 / 32 ; V_17 ++ ) {
F_23 ( V_93 -> V_179 [ V_17 ] ,
F_63
( V_14 -> V_48 . V_49 , V_93 -> V_132 ,
V_17 * 32 ) ) ;
}
} else {
for ( V_17 = 0 ; V_17 <= V_178 / 32 ; V_17 ++ ) {
F_23 ( 0xffffffff ,
F_63
( V_14 -> V_48 . V_49 , V_93 -> V_132 ,
V_17 * 32 ) ) ;
}
}
}
static void
F_41 ( struct V_92 * V_93 )
{
struct V_14 * V_14 = V_93 -> V_140 -> V_14 ;
struct V_180 * V_181 ;
int V_17 ;
void T_3 * V_77 ;
unsigned long V_23 ;
V_77 = F_24 ( V_14 -> V_48 . V_49 ,
V_182 ) ;
V_181 = (struct V_180 * ) 0 ;
F_23 ( F_22 ( V_183 + V_14 -> V_84 ,
V_182 ) ,
V_14 -> V_86 . V_87 ) ;
for ( V_17 = 0 ; V_17 < V_93 -> V_162 -> V_184 ; V_17 ++ ) {
V_23 = ( unsigned long ) & V_181 [ V_17 + V_93 -> V_162 -> V_163 ] ;
F_23 ( V_93 -> V_162 -> V_185 [ V_17 ] . V_186 << 6 |
V_93 -> V_162 -> V_185 [ V_17 ] . V_187 ,
V_77 + V_23 ) ;
}
}
static void
F_58 ( struct V_92 * V_93 )
{
struct V_188 V_130 ;
T_2 V_131 [ 2 ] = { 0 , 0 } ;
if ( V_93 -> V_132 < 32 )
V_131 [ 0 ] = 1 << V_93 -> V_132 ;
else
V_131 [ 1 ] = 1 << ( V_93 -> V_132 - 32 ) ;
F_59 ( V_130 . V_133 , V_134 , V_189 , 0 ) ;
V_130 . V_190 = 0 ;
V_130 . V_191 [ 0 ] = 0 ;
V_130 . V_191 [ 1 ] = 0 ;
V_130 . V_136 [ 0 ] = F_25 ( V_131 [ 0 ] ) ;
V_130 . V_136 [ 1 ] = F_25 ( V_131 [ 1 ] ) ;
F_60 ( & V_93 -> V_138 , & V_130 , sizeof( V_130 ) ,
V_192 , V_93 ) ;
F_61 ( V_93 -> V_140 -> V_14 , & V_93 -> V_138 ) ;
}
static void
F_42 ( struct V_92 * V_93 )
{
if ( V_93 -> V_106 == V_107 )
F_48 ( V_93 , V_102 ) ;
else {
V_93 -> V_117 |= V_127 ;
F_56 ( V_93 ) ;
}
}
static void
V_139 ( void * V_193 , int V_176 )
{
struct V_92 * V_93 = (struct V_92 * ) V_193 ;
F_5 ( & V_93 -> V_138 . V_9 ) ;
F_48 ( V_93 , V_102 ) ;
}
static void
F_51 ( struct V_92 * V_93 )
{
if ( V_93 -> V_106 == V_107 )
F_48 ( V_93 , V_103 ) ;
else
V_93 -> V_117 &= ~ V_127 ;
F_54 ( V_93 ) ;
}
static void
V_141 ( void * V_193 , int V_176 )
{
struct V_92 * V_93 = (struct V_92 * ) V_193 ;
F_5 ( & V_93 -> V_138 . V_9 ) ;
F_48 ( V_93 , V_103 ) ;
}
void
F_64 ( void * V_193 , int V_176 )
{
struct V_92 * V_93 = (struct V_92 * ) V_193 ;
F_5 ( & V_93 -> V_138 . V_9 ) ;
F_48 ( V_93 , V_104 ) ;
}
static void
V_192 ( void * V_193 , int V_176 )
{
struct V_92 * V_93 = (struct V_92 * ) V_193 ;
F_5 ( & V_93 -> V_138 . V_9 ) ;
F_48 ( V_93 , V_128 ) ;
}
void
F_65 ( struct V_92 * V_93 , T_1 V_194 ,
const struct V_195 * V_196 )
{
struct V_197 V_198 ;
F_59 ( V_198 . V_133 , V_134 , V_194 , 0 ) ;
V_198 . V_132 = V_93 -> V_132 ;
memcpy ( & V_198 . V_196 , ( void * ) & V_196 -> V_199 , V_200 ) ;
F_60 ( & V_93 -> V_138 , & V_198 , sizeof( V_198 ) ,
F_64 , V_93 ) ;
F_61 ( V_93 -> V_140 -> V_14 , & V_93 -> V_138 ) ;
}
static int
F_66 ( struct V_92 * V_93 )
{
struct V_195 * V_201 = NULL ;
struct V_8 * V_9 ;
if ( ! F_3 ( & V_93 -> V_202 ) ) {
F_4 ( & V_93 -> V_202 , & V_9 ) ;
F_5 ( V_9 ) ;
V_201 = (struct V_195 * ) V_9 ;
F_65 ( V_93 , V_203 , V_201 ) ;
F_6 ( & V_201 -> V_9 , & V_93 -> V_204 ) ;
return 1 ;
}
if ( ! F_3 ( & V_93 -> V_205 ) ) {
F_4 ( & V_93 -> V_205 , & V_9 ) ;
F_5 ( V_9 ) ;
V_201 = (struct V_195 * ) V_9 ;
F_65 ( V_93 , V_206 , V_201 ) ;
F_67 ( & V_93 -> V_140 -> V_14 -> V_207 , V_201 ) ;
return 1 ;
}
return 0 ;
}
static int
F_68 ( struct V_92 * V_93 )
{
if ( V_93 -> V_117 & V_119 ) {
V_93 -> V_117 &= ~ V_119 ;
if ( ! ( V_93 -> V_208 & V_209 ) )
F_62 ( V_93 , V_93 -> V_210 ) ;
}
if ( V_93 -> V_117 & V_118 ) {
V_93 -> V_117 &= ~ V_118 ;
if ( V_93 -> V_115 == V_211 ) {
V_93 -> V_68 &= ~ V_147 ;
F_41 ( V_93 ) ;
F_40 ( V_93 ) ;
} else {
V_93 -> V_68 |= V_147 ;
F_41 ( V_93 ) ;
F_40 ( V_93 ) ;
}
}
return 0 ;
}
static int
F_45 ( struct V_92 * V_93 )
{
if ( V_93 -> V_114 > 0 ) {
F_65 ( V_93 , V_212 ,
V_93 -> V_113 ) ;
V_93 -> V_114 -- ;
return 1 ;
}
if ( F_69 ( V_93 ) )
return 1 ;
if ( F_66 ( V_93 ) )
return 1 ;
if ( F_70 ( V_93 ) )
return 1 ;
if ( F_71 ( V_93 ) )
return 1 ;
if ( F_68 ( V_93 ) )
return 1 ;
return 0 ;
}
static int
F_72 ( struct V_92 * V_93 )
{
struct V_195 * V_201 = NULL ;
struct V_8 * V_9 ;
if ( ! F_3 ( & V_93 -> V_205 ) ) {
F_4 ( & V_93 -> V_205 , & V_9 ) ;
F_5 ( V_9 ) ;
V_201 = (struct V_195 * ) V_9 ;
F_65 ( V_93 , V_206 , V_201 ) ;
F_67 ( & V_93 -> V_140 -> V_14 -> V_207 , V_201 ) ;
return 1 ;
}
if ( ! F_3 ( & V_93 -> V_204 ) ) {
F_4 ( & V_93 -> V_204 , & V_9 ) ;
F_5 ( V_9 ) ;
V_201 = (struct V_195 * ) V_9 ;
F_65 ( V_93 , V_206 , V_201 ) ;
F_6 ( & V_201 -> V_9 , & V_93 -> V_202 ) ;
return 1 ;
}
return 0 ;
}
static int
F_50 ( struct V_92 * V_93 )
{
if ( F_73 ( V_93 ) )
return 1 ;
if ( F_72 ( V_93 ) )
return 1 ;
if ( V_93 -> V_114 > 0 )
V_93 -> V_114 = 0 ;
if ( F_74 ( V_93 ) )
return 1 ;
if ( F_75 ( V_93 ) )
return 1 ;
return 0 ;
}
static void
F_76 ( struct V_92 * V_93 )
{
struct V_8 * V_9 ;
struct V_195 * V_201 ;
while ( ! F_3 ( & V_93 -> V_204 ) ) {
F_4 ( & V_93 -> V_204 , & V_9 ) ;
F_5 ( V_9 ) ;
F_6 ( V_9 , & V_93 -> V_202 ) ;
}
while ( ! F_3 ( & V_93 -> V_205 ) ) {
F_4 ( & V_93 -> V_205 , & V_9 ) ;
F_5 ( V_9 ) ;
V_201 = (struct V_195 * ) V_9 ;
F_67 ( & V_93 -> V_140 -> V_14 -> V_207 , V_201 ) ;
}
}
static void
F_46 ( struct V_92 * V_93 )
{
F_77 ( V_93 ) ;
F_76 ( V_93 ) ;
V_93 -> V_114 = 0 ;
F_78 ( V_93 ) ;
F_79 ( V_93 ) ;
}
static void
F_80 ( struct V_92 * V_93 ,
struct V_213 * V_140 ,
struct V_214 * V_215 )
{
struct V_8 * V_9 ;
struct V_216 * V_217 ;
V_93 -> V_140 = V_140 ;
F_10 ( & V_93 -> V_218 ) ;
F_10 ( & V_93 -> V_219 ) ;
V_93 -> V_114 = 0 ;
F_10 ( & V_93 -> V_220 ) ;
V_93 -> V_113 = NULL ;
F_10 ( & V_93 -> V_202 ) ;
F_10 ( & V_93 -> V_205 ) ;
F_10 ( & V_93 -> V_204 ) ;
F_5 ( & V_93 -> V_138 . V_9 ) ;
if ( V_215 -> V_221 == V_116 )
V_93 -> V_68 |= V_173 ;
V_93 -> V_106 = ( V_215 -> V_222 ) ?
V_107 : V_109 ;
F_81 ( V_93 , V_140 , V_215 ) ;
V_93 -> V_162 = F_82 ( & V_93 -> V_140 -> V_14 -> V_223 ,
V_215 -> V_224 ) ;
F_2 (qe, &rx->rxp_q) {
V_217 = (struct V_216 * ) V_9 ;
if ( V_215 -> V_225 == V_226 )
V_93 -> V_168 = V_217 -> V_227 . V_228 . V_229 -> V_230 ;
else
V_93 -> V_168 = V_217 -> V_227 . V_231 . V_232 -> V_230 ;
break;
}
V_93 -> V_210 = V_211 ;
memset ( V_93 -> V_179 , 0 ,
( sizeof( T_2 ) * ( ( V_178 + 1 ) / 32 ) ) ) ;
V_93 -> V_179 [ 0 ] |= 1 ;
F_34 ( V_93 , F_33 ) ;
}
static void
F_83 ( struct V_92 * V_93 )
{
struct V_14 * V_14 = V_93 -> V_140 -> V_14 ;
struct V_195 * V_201 ;
F_84 ( & V_93 -> V_140 -> V_14 -> V_223 , V_93 -> V_162 ) ;
V_93 -> V_162 = NULL ;
V_93 -> V_114 = 0 ;
while ( ! F_3 ( & V_93 -> V_218 ) ) {
F_4 ( & V_93 -> V_218 , & V_201 ) ;
F_5 ( & V_201 -> V_9 ) ;
F_85 ( & V_93 -> V_140 -> V_14 -> V_233 , V_201 ) ;
}
if ( V_93 -> V_113 ) {
F_5 ( & V_93 -> V_113 -> V_9 ) ;
F_85 ( & V_93 -> V_140 -> V_14 -> V_233 ,
V_93 -> V_113 ) ;
V_93 -> V_113 = NULL ;
}
while ( ! F_3 ( & V_93 -> V_202 ) ) {
F_4 ( & V_93 -> V_202 , & V_201 ) ;
F_5 ( & V_201 -> V_9 ) ;
F_67 ( & V_93 -> V_140 -> V_14 -> V_207 , V_201 ) ;
}
if ( F_86 ( V_93 -> V_234 ,
V_93 -> V_235 ) ) {
F_87 ( ! ( V_14 -> V_236 == V_93 -> V_132 ) ) ;
F_88 ( V_93 -> V_234 ,
V_93 -> V_235 ) ;
V_14 -> V_236 = V_237 ;
}
F_87 ( V_93 -> V_208 & V_209 ) ;
if ( F_89 ( V_93 -> V_234 ,
V_93 -> V_235 ) ) {
F_90 ( V_93 -> V_234 ,
V_93 -> V_235 ) ;
}
F_87 ( V_93 -> V_208 & V_238 ) ;
V_93 -> V_140 = NULL ;
}
static void
F_91 ( struct V_213 * V_140 , enum V_239 V_176 )
{
F_48 ( V_140 , V_240 ) ;
if ( V_140 -> V_93 . V_132 < 32 )
V_140 -> V_14 -> V_241 . V_242 [ 0 ] |= ( ( T_2 ) 1 << V_140 -> V_93 . V_132 ) ;
else
V_140 -> V_14 -> V_241 . V_242 [ 1 ] |= ( ( T_2 )
1 << ( V_140 -> V_93 . V_132 - 32 ) ) ;
}
static void
F_92 ( struct V_92 * V_93 )
{
V_93 -> V_243 = F_91 ;
V_93 -> V_244 = V_93 -> V_140 ;
V_93 -> V_117 &= ~ V_245 ;
F_48 ( V_93 , V_97 ) ;
}
static void
F_93 ( struct V_213 * V_140 , enum V_239 V_176 )
{
F_48 ( V_140 , V_246 ) ;
if ( V_140 -> V_93 . V_132 < 32 )
V_140 -> V_14 -> V_241 . V_242 [ 0 ] &= ~ ( T_2 ) 1 << V_140 -> V_93 . V_132 ;
else
V_140 -> V_14 -> V_241 . V_242 [ 1 ] &= ~ ( T_2 )
1 << ( V_140 -> V_93 . V_132 - 32 ) ;
}
static void
F_94 ( struct V_92 * V_93 )
{
V_93 -> V_247 = F_93 ;
V_93 -> V_248 = V_93 -> V_140 ;
F_48 ( V_93 , V_99 ) ;
}
static void
F_95 ( struct V_92 * V_93 )
{
V_93 -> V_117 |= V_245 ;
F_48 ( V_93 , V_100 ) ;
}
int
F_96 ( struct V_92 * V_93 )
{
return F_97 ( V_249 , V_93 -> V_250 ) ;
}
enum V_239
F_98 ( struct V_213 * V_140 , T_1 * V_251 ,
void (* F_99)( struct V_252 * , struct V_213 * ,
enum V_239 ) )
{
struct V_92 * V_93 = & V_140 -> V_93 ;
if ( V_93 -> V_113 == NULL ) {
V_93 -> V_113 =
F_100 ( & V_93 -> V_140 -> V_14 -> V_233 ) ;
if ( V_93 -> V_113 == NULL )
return V_253 ;
F_5 ( & V_93 -> V_113 -> V_9 ) ;
}
memcpy ( V_93 -> V_113 -> V_199 , V_251 , V_200 ) ;
V_93 -> V_114 ++ ;
V_93 -> V_254 = F_99 ;
V_93 -> V_255 = V_140 -> V_14 -> V_252 ;
F_48 ( V_93 , V_101 ) ;
return V_94 ;
}
enum V_239
F_101 ( struct V_213 * V_140 , T_1 * V_199 ,
void (* F_99)( struct V_252 * , struct V_213 * ,
enum V_239 ) )
{
struct V_92 * V_93 = & V_140 -> V_93 ;
struct V_8 * V_9 ;
struct V_195 * V_201 ;
F_2 (qe, &rxf->mcast_active_q) {
V_201 = (struct V_195 * ) V_9 ;
if ( F_102 ( V_201 -> V_199 , V_199 ) ) {
if ( F_99 )
(* F_99)( V_140 -> V_14 -> V_252 , V_140 , V_94 ) ;
return V_94 ;
}
}
F_2 (qe, &rxf->mcast_pending_add_q) {
V_201 = (struct V_195 * ) V_9 ;
if ( F_102 ( V_201 -> V_199 , V_199 ) ) {
if ( F_99 )
(* F_99)( V_140 -> V_14 -> V_252 , V_140 , V_94 ) ;
return V_94 ;
}
}
V_201 = F_103 ( & V_93 -> V_140 -> V_14 -> V_207 ) ;
if ( V_201 == NULL )
return V_256 ;
F_5 ( & V_201 -> V_9 ) ;
memcpy ( V_201 -> V_199 , V_199 , V_200 ) ;
F_6 ( & V_201 -> V_9 , & V_93 -> V_202 ) ;
V_93 -> V_254 = F_99 ;
V_93 -> V_255 = V_140 -> V_14 -> V_252 ;
F_48 ( V_93 , V_101 ) ;
return V_94 ;
}
enum V_239
F_104 ( struct V_213 * V_140 , int V_19 , T_1 * V_257 ,
void (* F_99)( struct V_252 * , struct V_213 * ,
enum V_239 ) )
{
struct V_92 * V_93 = & V_140 -> V_93 ;
struct V_8 V_8 ;
struct V_8 * V_9 ;
T_1 * V_258 ;
struct V_195 * V_201 ;
struct V_195 * V_259 ;
int V_260 ;
int V_261 ;
int V_262 = 0 ;
int V_17 ;
F_10 ( & V_8 ) ;
for ( V_17 = 0 , V_258 = V_257 ; V_17 < V_19 ; V_17 ++ ) {
V_201 = F_103 ( & V_93 -> V_140 -> V_14 -> V_207 ) ;
if ( V_201 == NULL )
goto V_263;
F_5 ( & V_201 -> V_9 ) ;
memcpy ( V_201 -> V_199 , V_258 , V_200 ) ;
F_6 ( & V_201 -> V_9 , & V_8 ) ;
V_258 += V_200 ;
}
while ( ! F_3 ( & V_8 ) ) {
F_4 ( & V_8 , & V_9 ) ;
V_201 = (struct V_195 * ) V_9 ;
F_5 ( & V_201 -> V_9 ) ;
V_260 = 0 ;
F_2 (qe, &rxf->mcast_active_q) {
V_259 = (struct V_195 * ) V_9 ;
if ( F_102 ( V_259 -> V_199 , V_201 -> V_199 ) ) {
F_67 ( & V_93 -> V_140 -> V_14 -> V_207 ,
V_201 ) ;
V_260 = 1 ;
break;
}
}
if ( V_260 )
continue;
F_2 (qe, &rxf->mcast_pending_add_q) {
V_259 = (struct V_195 * ) V_9 ;
if ( F_102 ( V_259 -> V_199 , V_201 -> V_199 ) ) {
F_67 ( & V_93 -> V_140 -> V_14 -> V_207 ,
V_201 ) ;
V_260 = 1 ;
break;
}
}
if ( V_260 )
continue;
V_262 = 1 ;
F_6 ( & V_201 -> V_9 , & V_93 -> V_202 ) ;
}
while ( ! F_3 ( & V_93 -> V_202 ) ) {
F_4 ( & V_93 -> V_202 , & V_9 ) ;
V_201 = (struct V_195 * ) V_9 ;
F_5 ( & V_201 -> V_9 ) ;
for ( V_17 = 0 , V_258 = V_257 , V_261 = 1 ; V_17 < V_19 ; V_17 ++ ) {
if ( F_102 ( V_258 , V_201 -> V_199 ) ) {
V_261 = 0 ;
break;
}
V_258 += V_200 ;
}
if ( V_261 )
F_67 ( & V_93 -> V_140 -> V_14 -> V_207 , V_201 ) ;
else
F_6 ( & V_201 -> V_9 , & V_8 ) ;
}
while ( ! F_3 ( & V_8 ) ) {
F_4 ( & V_8 , & V_9 ) ;
V_201 = (struct V_195 * ) V_9 ;
F_5 ( & V_201 -> V_9 ) ;
F_6 ( & V_201 -> V_9 , & V_93 -> V_202 ) ;
}
while ( ! F_3 ( & V_93 -> V_204 ) ) {
F_4 ( & V_93 -> V_204 , & V_9 ) ;
V_201 = (struct V_195 * ) V_9 ;
F_5 ( & V_201 -> V_9 ) ;
for ( V_17 = 0 , V_258 = V_257 , V_261 = 1 ; V_17 < V_19 ; V_17 ++ ) {
if ( F_102 ( V_258 , V_201 -> V_199 ) ) {
V_261 = 0 ;
break;
}
V_258 += V_200 ;
}
if ( V_261 ) {
F_6 ( & V_201 -> V_9 , & V_93 -> V_205 ) ;
V_262 = 1 ;
} else {
F_6 ( & V_201 -> V_9 , & V_8 ) ;
}
}
while ( ! F_3 ( & V_8 ) ) {
F_4 ( & V_8 , & V_9 ) ;
V_201 = (struct V_195 * ) V_9 ;
F_5 ( & V_201 -> V_9 ) ;
F_6 ( & V_201 -> V_9 , & V_93 -> V_204 ) ;
}
if ( V_262 ) {
V_93 -> V_254 = F_99 ;
V_93 -> V_255 = V_140 -> V_14 -> V_252 ;
F_48 ( V_93 , V_101 ) ;
} else if ( F_99 )
(* F_99)( V_140 -> V_14 -> V_252 , V_140 , V_94 ) ;
return V_94 ;
V_263:
while ( ! F_3 ( & V_8 ) ) {
F_4 ( & V_8 , & V_9 ) ;
V_201 = (struct V_195 * ) V_9 ;
F_5 ( & V_201 -> V_9 ) ;
F_67 ( & V_93 -> V_140 -> V_14 -> V_207 , V_201 ) ;
}
return V_256 ;
}
void
F_105 ( struct V_213 * V_140 , int V_264 )
{
struct V_92 * V_93 = & V_140 -> V_93 ;
int V_265 = ( V_264 >> 5 ) ;
int V_266 = ( 1 << ( V_264 & 0x1F ) ) ;
V_93 -> V_179 [ V_265 ] |= V_266 ;
if ( V_93 -> V_210 == V_116 ) {
V_93 -> V_117 |= V_119 ;
F_48 ( V_93 , V_101 ) ;
}
}
void
F_106 ( struct V_213 * V_140 , int V_264 )
{
struct V_92 * V_93 = & V_140 -> V_93 ;
int V_265 = ( V_264 >> 5 ) ;
int V_266 = ( 1 << ( V_264 & 0x1F ) ) ;
V_93 -> V_179 [ V_265 ] &= ~ V_266 ;
if ( V_93 -> V_210 == V_116 ) {
V_93 -> V_117 |= V_119 ;
F_48 ( V_93 , V_101 ) ;
}
}
static void F_107 ( struct V_213 * V_140 )
{
struct V_216 * V_217 ;
struct V_8 * V_267 ;
F_2 (qe_rxp, &rx->rxp_q) {
V_217 = (struct V_216 * ) V_267 ;
V_140 -> V_268 ( V_140 -> V_14 -> V_252 , V_217 -> V_269 . V_270 ) ;
}
F_108 ( V_140 , V_94 ) ;
}
static void F_109 ( struct V_213 * V_140 ,
enum V_271 V_96 )
{
switch ( V_96 ) {
case V_272 :
F_34 ( V_140 , V_273 ) ;
break;
case V_274 :
F_108 ( V_140 , V_94 ) ;
break;
case V_275 :
break;
default:
F_38 ( V_96 ) ;
break;
}
}
static void F_110 ( struct V_213 * V_140 )
{
struct V_216 * V_217 ;
struct V_8 * V_267 ;
struct V_276 * V_277 = NULL , * V_278 = NULL ;
F_111 ( V_140 ) ;
F_2 (qe_rxp, &rx->rxp_q) {
V_217 = (struct V_216 * ) V_267 ;
F_21 ( V_217 -> V_269 . V_13 ) ;
F_112 ( V_217 , V_277 , V_278 ) ;
V_277 -> V_279 = F_113 ( & V_140 -> V_14 -> V_280 ) ;
F_114 ( V_277 ) ;
V_140 -> V_281 ( V_140 -> V_14 -> V_252 , V_277 -> V_282 ) ;
if ( V_278 ) {
F_114 ( V_278 ) ;
V_140 -> V_281 ( V_140 -> V_14 -> V_252 , V_278 -> V_282 ) ;
}
F_115 ( & V_217 -> V_269 ) ;
}
F_92 ( & V_140 -> V_93 ) ;
}
static void V_273 ( struct V_213 * V_140 ,
enum V_271 V_96 )
{
switch ( V_96 ) {
case V_274 :
F_34 ( V_140 , V_283 ) ;
break;
case V_275 :
F_34 ( V_140 , F_109 ) ;
F_116 ( V_140 ) ;
F_95 ( & V_140 -> V_93 ) ;
break;
case V_240 :
F_34 ( V_140 , V_284 ) ;
break;
default:
F_38 ( V_96 ) ;
break;
}
}
void
F_117 ( struct V_213 * V_140 )
{
struct V_216 * V_217 ;
struct V_8 * V_267 ;
F_2 (qe_rxp, &rx->rxp_q) {
V_217 = (struct V_216 * ) V_267 ;
F_118 ( & V_217 -> V_269 . V_13 -> V_46 , 0 ) ;
}
F_119 ( & V_140 -> V_14 -> V_280 . V_285 ) ;
}
void
V_284 ( struct V_213 * V_140 , enum V_271 V_96 )
{
switch ( V_96 ) {
case V_275 :
F_120 ( & V_140 -> V_14 -> V_280 . V_285 ) ;
F_34 ( V_140 , F_109 ) ;
F_116 ( V_140 ) ;
F_95 ( & V_140 -> V_93 ) ;
break;
case V_274 :
F_120 ( & V_140 -> V_14 -> V_280 . V_285 ) ;
F_34 ( V_140 , V_283 ) ;
break;
default:
F_38 ( V_96 ) ;
break;
}
}
void
F_121 ( struct V_213 * V_140 )
{
F_94 ( & V_140 -> V_93 ) ;
}
void
V_283 ( struct V_213 * V_140 , enum V_271 V_96 )
{
switch ( V_96 ) {
case V_246 :
F_34 ( V_140 , V_286 ) ;
break;
case V_240 :
break;
case V_275 :
F_34 ( V_140 , F_109 ) ;
F_116 ( V_140 ) ;
F_95 ( & V_140 -> V_93 ) ;
break;
default:
F_38 ( V_96 ) ;
break;
}
}
void
F_122 ( struct V_213 * V_140 )
{
struct V_216 * V_217 = NULL ;
struct V_276 * V_277 = NULL ;
struct V_276 * V_278 = NULL ;
struct V_8 * V_9 ;
T_2 V_287 [ 2 ] = { 0 , 0 } ;
F_123 ( & V_140 -> V_288 ) ;
F_2 (qe, &rx->rxp_q) {
V_217 = (struct V_216 * ) V_9 ;
F_112 ( V_217 , V_277 , V_278 ) ;
if ( V_277 -> V_230 < 32 )
V_287 [ 0 ] |= ( ( T_2 ) 1 << V_277 -> V_230 ) ;
else
V_287 [ 1 ] |= ( ( T_2 ) 1 << ( V_277 -> V_230 - 32 ) ) ;
if ( V_278 ) {
if ( V_278 -> V_230 < 32 )
V_287 [ 0 ] |= ( ( T_2 ) 1 << V_278 -> V_230 ) ;
else
V_287 [ 1 ] |= ( ( T_2 )
1 << ( V_278 -> V_230 - 32 ) ) ;
}
}
F_124 ( V_217 , V_287 ) ;
}
void
V_286 ( struct V_213 * V_140 , enum V_271 V_96 )
{
struct V_216 * V_217 = NULL ;
struct V_8 * V_9 ;
switch ( V_96 ) {
case V_289 :
F_2 (qe, &rx->rxp_q) {
V_217 = (struct V_216 * ) V_9 ;
F_29 ( V_217 -> V_269 . V_13 ) ;
}
case V_275 :
F_34 ( V_140 , F_109 ) ;
break;
default:
F_38 ( V_96 ) ;
break;
}
}
void
F_124 ( struct V_216 * V_217 , T_2 * V_290 )
{
struct V_291 V_130 ;
F_59 ( V_130 . V_133 , V_134 , V_292 , 0 ) ;
V_130 . V_293 [ 0 ] = F_25 ( V_290 [ 0 ] ) ;
V_130 . V_293 [ 1 ] = F_25 ( V_290 [ 1 ] ) ;
F_60 ( & V_217 -> V_138 , & V_130 , sizeof( V_130 ) ,
V_294 , V_217 ) ;
F_61 ( V_217 -> V_140 -> V_14 , & V_217 -> V_138 ) ;
}
void
F_114 ( struct V_276 * V_227 )
{
struct V_295 * V_296 ;
struct V_297 V_298 , * V_299 ;
struct V_300 V_301 ;
struct V_302 * V_303 ;
T_2 V_75 ;
struct V_14 * V_14 = V_227 -> V_140 -> V_14 ;
void T_3 * V_77 ;
unsigned long V_23 ;
V_303 = & V_227 -> V_303 ;
V_301 = * ( (struct V_300 * ) ( V_303 -> V_304 ) ) ;
V_298 . V_305 = V_303 -> V_306 . V_42 ;
V_298 . V_307 = V_303 -> V_306 . V_44 ;
V_298 . V_308 = V_301 . V_42 ;
V_298 . V_309 = V_301 . V_44 ;
V_298 . V_310 = ( ( T_2 ) V_303 -> V_311 << 16 ) | 0x0 ;
V_298 . V_312 = ( ( T_2 ) ( V_313 >> 2 ) << 16 ) |
( V_303 -> V_314 >> 2 ) ;
V_298 . V_315 =
( ( T_2 ) ( V_227 -> V_217 -> V_269 . V_316 & 0xff ) << 16 ) | 0x0 ;
V_298 . V_317 = ( ( T_2 ) V_227 -> V_279 << 16 ) |
V_318 ;
V_298 . V_319 = 0x0 | ( 0x3 << 8 ) ;
V_75 = F_22 ( V_83 + V_14 -> V_84 ,
V_320 ) ;
F_23 ( V_75 , V_14 -> V_86 . V_87 ) ;
V_77 = F_24 ( V_14 -> V_48 . V_49 ,
V_320 ) ;
V_296 = (struct V_295 * ) 0 ;
V_299 = & V_296 [ V_227 -> V_230 ] . V_227 ;
V_23 = ( unsigned long ) & V_299 -> V_305 ;
F_23 ( F_25 ( V_298 . V_305 ) , V_77 + V_23 ) ;
V_23 = ( unsigned long ) & V_299 -> V_307 ;
F_23 ( F_25 ( V_298 . V_307 ) , V_77 + V_23 ) ;
V_23 = ( unsigned long ) & V_299 -> V_308 ;
F_23 ( F_25 ( V_298 . V_308 ) , V_77 + V_23 ) ;
V_23 = ( unsigned long ) & V_299 -> V_309 ;
F_23 ( F_25 ( V_298 . V_309 ) , V_77 + V_23 ) ;
V_23 = ( unsigned long ) & V_299 -> V_310 ;
F_23 ( V_298 . V_310 , V_77 + V_23 ) ;
V_23 = ( unsigned long ) & V_299 -> V_312 ;
F_23 ( V_298 . V_312 , V_77 + V_23 ) ;
V_23 = ( unsigned long ) & V_299 -> V_315 ;
F_23 ( V_298 . V_315 , V_77 + V_23 ) ;
V_23 = ( unsigned long ) & V_299 -> V_317 ;
F_23 ( V_298 . V_317 , V_77 + V_23 ) ;
V_23 = ( unsigned long ) & V_299 -> V_319 ;
F_23 ( V_298 . V_319 , V_77 + V_23 ) ;
V_227 -> V_282 -> V_321 = 0 ;
V_227 -> V_282 -> V_322 = 0 ;
}
void
F_115 ( struct V_323 * V_269 )
{
struct V_324 V_325 , * V_326 ;
const struct V_302 * V_303 ;
struct V_300 V_301 ;
T_2 V_75 ;
struct V_14 * V_14 = V_269 -> V_140 -> V_14 ;
void T_3 * V_77 ;
unsigned long V_23 ;
V_303 = & V_269 -> V_303 ;
V_301 = * ( (struct V_300 * ) ( V_303 -> V_304 ) ) ;
V_325 . V_305 = V_303 -> V_306 . V_42 ;
V_325 . V_307 = V_303 -> V_306 . V_44 ;
V_325 . V_308 = V_301 . V_42 ;
V_325 . V_309 = V_301 . V_44 ;
V_325 . V_310 = ( V_303 -> V_311 << 16 ) | 0x0 ;
V_325 . V_312 =
( ( T_2 ) ( V_327 >> 2 ) << 16 ) | ( V_303 -> V_314 >> 2 ) ;
V_325 . V_328 = ( ( ( ( T_2 ) V_269 -> V_329 ) << 24 ) |
( ( T_2 ) ( V_269 -> V_13 -> V_38 & 0xff ) << 16 ) | 0x0 ) ;
V_325 . V_330 = V_318 ;
V_75 = F_22 ( V_83 + V_14 -> V_84 ,
V_331 ) ;
F_23 ( V_75 , V_14 -> V_86 . V_87 ) ;
V_77 = F_24 ( V_14 -> V_48 . V_49 ,
V_331 ) ;
V_326 = (struct V_324 * ) 0 ;
V_23 = ( unsigned long ) & V_326 [ V_269 -> V_316 ] . V_305 ;
F_23 ( F_25 ( V_325 . V_305 ) , V_77 + V_23 ) ;
V_23 = ( unsigned long ) & V_326 [ V_269 -> V_316 ] . V_307 ;
F_23 ( F_25 ( V_325 . V_307 ) , V_77 + V_23 ) ;
V_23 = ( unsigned long ) & V_326 [ V_269 -> V_316 ] . V_308 ;
F_23 ( F_25 ( V_325 . V_308 ) , V_77 + V_23 ) ;
V_23 = ( unsigned long ) & V_326 [ V_269 -> V_316 ] . V_309 ;
F_23 ( F_25 ( V_325 . V_309 ) , V_77 + V_23 ) ;
V_23 = ( unsigned long ) & V_326 [ V_269 -> V_316 ] . V_310 ;
F_23 ( V_325 . V_310 , V_77 + V_23 ) ;
V_23 = ( unsigned long ) & V_326 [ V_269 -> V_316 ] . V_312 ;
F_23 ( V_325 . V_312 , V_77 + V_23 ) ;
V_23 = ( unsigned long ) & V_326 [ V_269 -> V_316 ] . V_328 ;
F_23 ( V_325 . V_328 , V_77 + V_23 ) ;
V_23 = ( unsigned long ) & V_326 [ V_269 -> V_316 ] . V_330 ;
F_23 ( V_325 . V_330 , V_77 + V_23 ) ;
V_269 -> V_270 -> V_321 = 0 ;
* ( V_269 -> V_270 -> V_332 ) = 0 ;
}
void
F_111 ( struct V_213 * V_140 )
{
struct V_8 * V_267 ;
struct V_216 * V_217 ;
struct V_276 * V_277 = NULL ;
struct V_276 * V_278 = NULL ;
int V_20 ;
V_20 = 0 ;
F_2 (qe_rxp, &rx->rxp_q) {
V_217 = (struct V_216 * ) V_267 ;
F_112 ( V_217 , V_277 , V_278 ) ;
V_140 -> V_93 . V_162 -> V_185 [ V_20 ] . V_186 = V_277 -> V_230 ;
V_140 -> V_93 . V_162 -> V_185 [ V_20 ] . V_187 =
( V_278 ? V_278 -> V_230 : 0 ) ;
V_20 ++ ;
}
}
static int
F_125 ( struct V_333 * V_241 ,
struct V_214 * V_334 )
{
if ( ( V_241 -> V_335 == 0 ) ||
( V_241 -> V_336 == 0 ) ||
( V_241 -> V_337 == 0 ) )
return 0 ;
if ( V_334 -> V_225 == V_226 ) {
if ( ( V_241 -> V_336 < V_334 -> V_224 ) ||
( V_241 -> V_337 < V_334 -> V_224 ) )
return 0 ;
} else {
if ( ( V_241 -> V_336 < V_334 -> V_224 ) ||
( V_241 -> V_337 < ( 2 * V_334 -> V_224 ) ) )
return 0 ;
}
if ( ! F_126 ( & V_241 -> V_14 -> V_223 , V_334 -> V_224 ) )
return 0 ;
return 1 ;
}
static struct V_276 *
F_127 ( struct V_333 * V_241 )
{
struct V_276 * V_227 = NULL ;
struct V_8 * V_9 = NULL ;
F_4 ( & V_241 -> V_338 , & V_9 ) ;
if ( V_9 ) {
V_241 -> V_337 -- ;
V_227 = (struct V_276 * ) V_9 ;
}
return V_227 ;
}
static void
F_128 ( struct V_333 * V_241 , struct V_276 * V_227 )
{
F_5 ( & V_227 -> V_9 ) ;
F_6 ( & V_227 -> V_9 , & V_241 -> V_338 ) ;
V_241 -> V_337 ++ ;
}
static struct V_216 *
F_129 ( struct V_333 * V_241 )
{
struct V_8 * V_9 = NULL ;
struct V_216 * V_217 = NULL ;
F_4 ( & V_241 -> V_339 , & V_9 ) ;
if ( V_9 ) {
V_241 -> V_336 -- ;
V_217 = (struct V_216 * ) V_9 ;
}
return V_217 ;
}
static void
F_130 ( struct V_333 * V_241 , struct V_216 * V_217 )
{
F_5 ( & V_217 -> V_9 ) ;
F_6 ( & V_217 -> V_9 , & V_241 -> V_339 ) ;
V_241 -> V_336 ++ ;
}
static struct V_213 *
F_131 ( struct V_333 * V_241 )
{
struct V_8 * V_9 = NULL ;
struct V_213 * V_140 = NULL ;
F_4 ( & V_241 -> V_340 , & V_9 ) ;
if ( V_9 ) {
V_241 -> V_335 -- ;
V_140 = (struct V_213 * ) V_9 ;
F_5 ( V_9 ) ;
F_6 ( & V_140 -> V_9 , & V_241 -> V_341 ) ;
}
return V_140 ;
}
static void
F_132 ( struct V_333 * V_241 , struct V_213 * V_140 )
{
F_5 ( & V_140 -> V_9 ) ;
F_6 ( & V_140 -> V_9 , & V_241 -> V_340 ) ;
V_241 -> V_335 ++ ;
}
static void
F_133 ( struct V_213 * V_140 , struct V_14 * V_14 )
{
V_140 -> V_14 = V_14 ;
V_140 -> V_342 = 0 ;
F_10 ( & V_140 -> V_343 ) ;
V_140 -> V_288 . V_344 = V_345 ;
V_140 -> V_288 . V_346 = V_140 ;
V_140 -> V_288 . V_347 = 0 ;
V_140 -> V_247 = NULL ;
V_140 -> V_248 = NULL ;
}
static void
F_134 ( struct V_216 * V_217 ,
struct V_276 * V_277 ,
struct V_276 * V_278 )
{
switch ( V_217 -> type ) {
case V_226 :
V_217 -> V_227 . V_228 . V_229 = V_277 ;
V_217 -> V_227 . V_228 . V_348 = NULL ;
break;
case V_349 :
V_217 -> V_227 . V_231 . V_232 = V_277 ;
V_217 -> V_227 . V_231 . V_350 = V_278 ;
break;
case V_351 :
V_217 -> V_227 . V_352 . V_353 = V_277 ;
V_217 -> V_227 . V_352 . V_354 = V_278 ;
break;
default:
break;
}
}
static void
F_135 ( struct V_276 * V_227 ,
struct V_216 * V_217 ,
T_2 V_311 ,
T_2 V_314 ,
struct V_355 * V_356 ,
struct V_355 * V_357 ,
struct V_355 * V_358 )
{
int V_17 ;
V_227 -> V_303 . V_306 . V_42 = V_356 -> V_43 . V_42 ;
V_227 -> V_303 . V_306 . V_44 = V_356 -> V_43 . V_44 ;
V_227 -> V_303 . V_304 = V_356 -> V_29 ;
V_227 -> V_303 . V_311 = V_311 ;
V_227 -> V_303 . V_314 = V_314 ;
V_227 -> V_282 -> V_359 = ( void * * ) V_357 -> V_29 ;
for ( V_17 = 0 ; V_17 < V_227 -> V_303 . V_311 ; V_17 ++ ) {
V_227 -> V_282 -> V_359 [ V_17 ] = V_358 [ V_17 ] . V_29 ;
( (struct V_300 * ) V_227 -> V_303 . V_304 ) [ V_17 ] . V_42 =
V_358 [ V_17 ] . V_43 . V_42 ;
( (struct V_300 * ) V_227 -> V_303 . V_304 ) [ V_17 ] . V_44 =
V_358 [ V_17 ] . V_43 . V_44 ;
}
}
static void
F_136 ( struct V_216 * V_217 ,
T_2 V_311 ,
T_2 V_314 ,
struct V_355 * V_356 ,
struct V_355 * V_357 ,
struct V_355 * V_358 )
{
int V_17 ;
V_217 -> V_269 . V_303 . V_306 . V_42 = V_356 -> V_43 . V_42 ;
V_217 -> V_269 . V_303 . V_306 . V_44 = V_356 -> V_43 . V_44 ;
V_217 -> V_269 . V_303 . V_304 = V_356 -> V_29 ;
V_217 -> V_269 . V_303 . V_311 = V_311 ;
V_217 -> V_269 . V_303 . V_314 = V_314 ;
V_217 -> V_269 . V_270 -> V_359 = ( void * * ) V_357 -> V_29 ;
for ( V_17 = 0 ; V_17 < V_217 -> V_269 . V_303 . V_311 ; V_17 ++ ) {
V_217 -> V_269 . V_270 -> V_359 [ V_17 ] = V_358 [ V_17 ] . V_29 ;
( (struct V_300 * ) V_217 -> V_269 . V_303 . V_304 ) [ V_17 ] . V_42 =
V_358 [ V_17 ] . V_43 . V_42 ;
( (struct V_300 * ) V_217 -> V_269 . V_303 . V_304 ) [ V_17 ] . V_44 =
V_358 [ V_17 ] . V_43 . V_44 ;
}
}
static void
F_137 ( struct V_213 * V_140 , struct V_216 * V_217 )
{
F_6 ( & V_217 -> V_9 , & V_140 -> V_343 ) ;
}
static void
F_138 ( struct V_333 * V_241 )
{
F_10 ( & V_241 -> V_340 ) ;
F_10 ( & V_241 -> V_338 ) ;
F_10 ( & V_241 -> V_339 ) ;
F_10 ( & V_241 -> V_341 ) ;
V_241 -> V_335 = 0 ;
V_241 -> V_337 = 0 ;
V_241 -> V_336 = 0 ;
}
static void
F_139 ( struct V_213 * V_140 , int V_360 )
{
F_5 ( & V_140 -> V_9 ) ;
F_10 ( & V_140 -> V_343 ) ;
V_140 -> V_14 = NULL ;
V_140 -> V_93 . V_132 = V_360 ;
F_5 ( & V_140 -> V_138 . V_9 ) ;
V_140 -> V_247 = NULL ;
V_140 -> V_248 = NULL ;
}
void
V_294 ( void * V_193 , int V_176 )
{
struct V_216 * V_217 = (struct V_216 * ) V_193 ;
F_140 ( & V_217 -> V_140 -> V_288 ) ;
}
void
V_345 ( void * V_193 )
{
struct V_213 * V_140 = (struct V_213 * ) V_193 ;
F_48 ( V_140 , V_289 ) ;
}
static void
F_141 ( void * V_193 , struct V_213 * V_140 ,
enum V_239 V_176 )
{
struct V_333 * V_241 = (struct V_333 * ) V_193 ;
F_140 ( & V_241 -> V_361 ) ;
}
static void
F_142 ( void * V_193 )
{
struct V_333 * V_241 = (struct V_333 * ) V_193 ;
if ( V_241 -> V_247 )
V_241 -> V_247 ( & V_241 -> V_14 -> V_280 , V_94 ) ;
V_241 -> V_247 = NULL ;
}
static void
F_143 ( struct V_213 * V_140 )
{
V_140 -> V_342 |= V_362 ;
if ( V_140 -> V_342 & V_363 )
F_48 ( V_140 , V_272 ) ;
}
static void
F_144 ( struct V_213 * V_140 )
{
V_140 -> V_342 &= ~ V_362 ;
if ( V_140 -> V_250 == ( V_364 ) F_109 )
F_141 ( & V_140 -> V_14 -> V_241 , V_140 , V_94 ) ;
else {
V_140 -> V_247 = F_141 ;
V_140 -> V_248 = & V_140 -> V_14 -> V_241 ;
F_48 ( V_140 , V_274 ) ;
}
}
static void
F_145 ( struct V_213 * V_140 )
{
V_140 -> V_342 &= ~ V_362 ;
V_140 -> V_342 |= V_365 ;
F_48 ( V_140 , V_275 ) ;
}
void
F_146 ( struct V_333 * V_241 , enum V_366 type )
{
struct V_213 * V_140 ;
struct V_8 * V_9 ;
V_241 -> V_367 |= V_368 ;
if ( type == V_369 )
V_241 -> V_367 |= V_370 ;
F_2 (qe, &rx_mod->rx_active_q) {
V_140 = (struct V_213 * ) V_9 ;
if ( V_140 -> type == type )
F_143 ( V_140 ) ;
}
}
void
F_147 ( struct V_333 * V_241 , enum V_366 type )
{
struct V_213 * V_140 ;
struct V_8 * V_9 ;
V_241 -> V_367 &= ~ V_368 ;
V_241 -> V_367 &= ~ V_370 ;
V_241 -> V_247 = V_371 ;
F_2 (qe, &rx_mod->rx_active_q) {
V_140 = (struct V_213 * ) V_9 ;
if ( V_140 -> type == type )
F_123 ( & V_241 -> V_361 ) ;
}
if ( V_241 -> V_361 . V_347 == 0 ) {
V_241 -> V_247 ( & V_241 -> V_14 -> V_280 , V_94 ) ;
V_241 -> V_247 = NULL ;
return;
}
F_2 (qe, &rx_mod->rx_active_q) {
V_140 = (struct V_213 * ) V_9 ;
if ( V_140 -> type == type )
F_144 ( V_140 ) ;
}
}
void
F_148 ( struct V_333 * V_241 )
{
struct V_213 * V_140 ;
struct V_8 * V_9 ;
V_241 -> V_367 &= ~ V_368 ;
V_241 -> V_367 &= ~ V_370 ;
F_2 (qe, &rx_mod->rx_active_q) {
V_140 = (struct V_213 * ) V_9 ;
F_145 ( V_140 ) ;
}
}
void F_149 ( struct V_333 * V_241 , struct V_14 * V_14 ,
struct V_15 * V_16 )
{
int V_265 ;
struct V_213 * V_372 ;
struct V_216 * V_373 ;
struct V_276 * V_374 ;
V_241 -> V_14 = V_14 ;
V_241 -> V_367 = 0 ;
V_241 -> V_140 = (struct V_213 * )
V_16 [ V_375 ] . V_26 . V_27 . V_28 [ 0 ] . V_29 ;
V_241 -> V_217 = (struct V_216 * )
V_16 [ V_376 ] . V_26 . V_27 . V_28 [ 0 ] . V_29 ;
V_241 -> V_227 = (struct V_276 * )
V_16 [ V_377 ] . V_26 . V_27 . V_28 [ 0 ] . V_29 ;
F_138 ( V_241 ) ;
for ( V_265 = 0 ; V_265 < V_378 ; V_265 ++ ) {
V_372 = & V_241 -> V_140 [ V_265 ] ;
F_139 ( V_372 , V_265 ) ;
F_6 ( & V_372 -> V_9 , & V_241 -> V_340 ) ;
V_241 -> V_335 ++ ;
}
for ( V_265 = 0 ; V_265 < V_378 ; V_265 ++ ) {
V_373 = & V_241 -> V_217 [ V_265 ] ;
V_373 -> V_269 . V_316 = V_265 ;
F_5 ( & V_373 -> V_9 ) ;
F_6 ( & V_373 -> V_9 , & V_241 -> V_339 ) ;
V_241 -> V_336 ++ ;
}
for ( V_265 = 0 ; V_265 < V_378 ; V_265 ++ ) {
V_374 = & V_241 -> V_227 [ V_265 ] ;
V_374 -> V_230 = V_265 ;
F_5 ( & V_374 -> V_9 ) ;
F_6 ( & V_374 -> V_9 , & V_241 -> V_338 ) ;
V_241 -> V_337 ++ ;
}
V_241 -> V_361 . V_344 = F_142 ;
V_241 -> V_361 . V_346 = V_241 ;
V_241 -> V_361 . V_347 = 0 ;
}
void
F_150 ( struct V_333 * V_241 )
{
struct V_8 * V_9 ;
int V_17 ;
V_17 = 0 ;
F_2 (qe, &rx_mod->rx_free_q)
V_17 ++ ;
V_17 = 0 ;
F_2 (qe, &rx_mod->rxp_free_q)
V_17 ++ ;
V_17 = 0 ;
F_2 (qe, &rx_mod->rxq_free_q)
V_17 ++ ;
V_241 -> V_14 = NULL ;
}
int
F_151 ( struct V_213 * V_140 )
{
return F_97 ( V_379 , V_140 -> V_250 ) ;
}
void
F_152 ( struct V_214 * V_380 , struct V_15 * V_16 )
{
T_2 V_381 , V_382 , V_383 ;
T_2 V_384 , V_385 , V_386 ;
struct V_387 * V_27 ;
T_2 V_388 ;
T_2 V_389 ;
T_2 V_390 ;
V_390 = V_380 -> V_391 ;
V_389 = ( ( V_380 -> V_225 == V_226 ) ? 0 : V_380 -> V_391 ) ;
V_388 = V_390 + V_389 ;
F_153 ( V_388 ) ;
V_381 = V_388 * V_327 ;
V_381 = F_154 ( V_381 , V_392 ) ;
V_384 = F_155 ( V_381 ) ;
F_153 ( V_390 ) ;
V_383 = V_390 * V_313 ;
V_383 = F_154 ( V_383 , V_392 ) ;
V_386 = F_155 ( V_383 ) ;
if ( V_226 != V_380 -> V_225 ) {
F_153 ( V_389 ) ;
V_382 = V_389 * V_313 ;
V_382 = F_154 ( V_382 , V_392 ) ;
V_385 = F_155 ( V_382 ) ;
} else {
V_385 = 0 ;
}
V_16 [ V_393 ] . V_394 = V_395 ;
V_27 = & V_16 [ V_393 ] . V_26 . V_27 ;
V_27 -> V_396 = V_397 ;
V_27 -> V_398 = sizeof( struct V_399 ) ;
V_27 -> V_400 = V_380 -> V_224 ;
V_16 [ V_401 ] . V_394 = V_395 ;
V_27 = & V_16 [ V_401 ] . V_26 . V_27 ;
V_27 -> V_396 = V_397 ;
V_27 -> V_398 = sizeof( struct V_402 ) ;
V_27 -> V_400 = F_156 ( V_380 ) ;
V_16 [ V_403 ] . V_394 = V_395 ;
V_27 = & V_16 [ V_403 ] . V_26 . V_27 ;
V_27 -> V_396 = V_404 ;
V_27 -> V_398 = V_384 * sizeof( struct V_300 ) ;
V_27 -> V_400 = V_380 -> V_224 ;
V_16 [ V_405 ] . V_394 = V_395 ;
V_27 = & V_16 [ V_405 ] . V_26 . V_27 ;
V_27 -> V_396 = V_397 ;
V_27 -> V_398 = V_384 * sizeof( void * ) ;
V_27 -> V_400 = V_380 -> V_224 ;
V_16 [ V_406 ] . V_394 = V_395 ;
V_27 = & V_16 [ V_406 ] . V_26 . V_27 ;
V_27 -> V_396 = V_404 ;
V_27 -> V_398 = V_392 ;
V_27 -> V_400 = V_384 * V_380 -> V_224 ;
V_16 [ V_407 ] . V_394 = V_395 ;
V_27 = & V_16 [ V_407 ] . V_26 . V_27 ;
V_27 -> V_396 = V_404 ;
V_27 -> V_398 = V_386 * sizeof( struct V_300 ) ;
V_27 -> V_400 = V_380 -> V_224 ;
V_16 [ V_408 ] . V_394 = V_395 ;
V_27 = & V_16 [ V_408 ] . V_26 . V_27 ;
V_27 -> V_396 = V_397 ;
V_27 -> V_398 = V_386 * sizeof( void * ) ;
V_27 -> V_400 = V_380 -> V_224 ;
V_16 [ V_409 ] . V_394 = V_395 ;
V_27 = & V_16 [ V_409 ] . V_26 . V_27 ;
V_27 -> V_396 = V_404 ;
V_27 -> V_398 = V_392 ;
V_27 -> V_400 = V_386 * V_380 -> V_224 ;
V_16 [ V_410 ] . V_394 = V_395 ;
V_27 = & V_16 [ V_410 ] . V_26 . V_27 ;
V_27 -> V_396 = V_404 ;
V_27 -> V_398 = V_385 * sizeof( struct V_300 ) ;
V_27 -> V_400 = ( V_385 ? V_380 -> V_224 : 0 ) ;
V_16 [ V_411 ] . V_394 = V_395 ;
V_27 = & V_16 [ V_411 ] . V_26 . V_27 ;
V_27 -> V_396 = V_397 ;
V_27 -> V_398 = V_385 * sizeof( void * ) ;
V_27 -> V_400 = ( V_385 ? V_380 -> V_224 : 0 ) ;
V_16 [ V_412 ] . V_394 = V_395 ;
V_27 = & V_16 [ V_412 ] . V_26 . V_27 ;
V_27 -> V_396 = V_404 ;
V_27 -> V_398 = ( V_385 ? V_392 : 0 ) ;
V_27 -> V_400 = ( V_385 ? ( V_385 * V_380 -> V_224 ) : 0 ) ;
V_16 [ V_413 ] . V_394 = V_414 ;
V_16 [ V_413 ] . V_26 . V_415 . V_5 = V_70 ;
V_16 [ V_413 ] . V_26 . V_415 . V_400 = V_380 -> V_224 ;
}
struct V_213 *
F_157 ( struct V_14 * V_14 , struct V_252 * V_252 ,
struct V_214 * V_334 ,
struct V_416 * V_417 ,
struct V_15 * V_16 ,
void * V_418 )
{
struct V_333 * V_241 = & V_14 -> V_241 ;
struct V_213 * V_140 ;
struct V_216 * V_217 ;
struct V_276 * V_277 ;
struct V_276 * V_278 ;
struct V_419 * V_415 ;
T_2 V_311 ;
struct V_355 * V_420 ;
struct V_355 * V_421 ;
struct V_355 * V_422 ;
struct V_355 * V_423 ;
struct V_355 * V_424 ;
struct V_355 * V_425 ;
struct V_355 * V_426 ;
struct V_355 * V_427 ;
struct V_355 * V_428 ;
struct V_355 * V_429 ;
struct V_355 * V_430 ;
struct V_355 * V_431 ;
int V_17 , V_432 = 0 , V_433 = 0 , V_434 = 0 ;
int V_386 , V_385 , V_435 ;
struct F_20 V_436 ;
if ( ! F_125 ( V_241 , V_334 ) )
return NULL ;
V_415 = & V_16 [ V_413 ] . V_26 . V_415 ;
V_420 = & V_16 [ V_393 ] . V_26 . V_27 . V_28 [ 0 ] ;
V_421 = & V_16 [ V_401 ] . V_26 . V_27 . V_28 [ 0 ] ;
V_422 = & V_16 [ V_437 ] . V_26 . V_27 . V_28 [ 0 ] ;
V_423 = & V_16 [ V_403 ] . V_26 . V_27 . V_28 [ 0 ] ;
V_424 = & V_16 [ V_405 ] . V_26 . V_27 . V_28 [ 0 ] ;
V_425 = & V_16 [ V_406 ] . V_26 . V_27 . V_28 [ 0 ] ;
V_426 = & V_16 [ V_410 ] . V_26 . V_27 . V_28 [ 0 ] ;
V_427 = & V_16 [ V_407 ] . V_26 . V_27 . V_28 [ 0 ] ;
V_428 = & V_16 [ V_411 ] . V_26 . V_27 . V_28 [ 0 ] ;
V_429 = & V_16 [ V_408 ] . V_26 . V_27 . V_28 [ 0 ] ;
V_430 = & V_16 [ V_412 ] . V_26 . V_27 . V_28 [ 0 ] ;
V_431 = & V_16 [ V_409 ] . V_26 . V_27 . V_28 [ 0 ] ;
V_311 = V_16 [ V_406 ] . V_26 . V_27 . V_400 /
V_334 -> V_224 ;
V_386 = V_16 [ V_409 ] . V_26 . V_27 . V_400 /
V_334 -> V_224 ;
V_385 = V_16 [ V_412 ] . V_26 . V_27 . V_400 /
V_334 -> V_224 ;
V_140 = F_131 ( V_241 ) ;
F_133 ( V_140 , V_14 ) ;
V_140 -> V_418 = V_418 ;
V_140 -> type = V_334 -> V_438 ;
V_140 -> V_439 = V_417 -> V_439 ;
V_140 -> V_440 = V_417 -> V_440 ;
V_140 -> V_441 = V_417 -> V_441 ;
V_140 -> V_442 = V_417 -> V_442 ;
V_140 -> V_268 = V_417 -> V_268 ;
V_140 -> V_281 = V_417 -> V_281 ;
if ( V_140 -> V_14 -> V_241 . V_367 & V_368 ) {
switch ( V_140 -> type ) {
case V_443 :
if ( ! ( V_140 -> V_14 -> V_241 . V_367 &
V_370 ) )
V_140 -> V_342 |= V_362 ;
break;
case V_369 :
if ( V_140 -> V_14 -> V_241 . V_367 & V_370 )
V_140 -> V_342 |= V_362 ;
break;
}
}
for ( V_17 = 0 , V_435 = 0 ; V_17 < V_334 -> V_224 ; V_17 ++ ) {
V_217 = F_129 ( V_241 ) ;
V_217 -> type = V_334 -> V_225 ;
V_217 -> V_140 = V_140 ;
V_217 -> V_269 . V_140 = V_140 ;
V_277 = F_127 ( V_241 ) ;
if ( V_226 == V_334 -> V_225 )
V_278 = NULL ;
else
V_278 = F_127 ( V_241 ) ;
if ( 1 == V_415 -> V_400 ) {
V_217 -> V_269 . V_13 = F_13 ( & V_14 -> V_3 ,
V_415 -> V_5 ,
V_415 -> V_444 [ 0 ] . V_6 ) ;
V_217 -> V_6 = V_415 -> V_444 [ 0 ] . V_6 ;
} else {
V_217 -> V_269 . V_13 = F_13 ( & V_14 -> V_3 ,
V_415 -> V_5 ,
V_415 -> V_444 [ V_17 ] . V_6 ) ;
V_217 -> V_6 = V_415 -> V_444 [ V_17 ] . V_6 ;
}
V_217 -> V_269 . V_329 = F_15 ( V_217 -> V_269 . V_13 ) ;
V_436 . V_65 = V_445 ;
V_436 . V_67 = V_446 ;
V_436 . V_66 = V_447 ;
V_436 . V_68 = V_448 ;
F_20 ( V_217 -> V_269 . V_13 , & V_436 ) ;
F_134 ( V_217 , V_277 , V_278 ) ;
F_137 ( V_140 , V_217 ) ;
V_277 -> V_140 = V_140 ;
V_277 -> V_217 = V_217 ;
V_277 -> V_282 = (struct V_402 * ) V_421 [ V_435 ] . V_29 ;
F_158 ( V_277 , V_217 , V_334 -> V_391 , V_14 , 0 ,
( void * ) V_422 [ V_435 ] . V_29 ) ;
V_435 ++ ;
( V_277 ) -> V_449 = ( V_277 ) -> V_450 = 0 ;
( V_277 ) -> V_451 = ( V_277 ) -> V_452 = 0 ;
F_135 ( V_277 , V_217 , V_386 , V_392 ,
& V_427 [ V_17 ] , & V_429 [ V_17 ] , & V_431 [ V_433 ] ) ;
V_277 -> V_282 -> V_453 = V_433 ;
V_277 -> V_282 -> V_311 = V_386 ;
V_433 += V_386 ;
if ( V_140 -> V_439 )
V_140 -> V_439 ( V_252 , V_277 -> V_282 ) ;
if ( V_278 ) {
V_278 -> V_140 = V_140 ;
V_278 -> V_217 = V_217 ;
V_278 -> V_282 = (struct V_402 * ) V_421 [ V_435 ] . V_29 ;
F_158 ( V_278 , V_217 , V_334 -> V_391 , V_14 , 1 ,
( void * ) V_422 [ V_435 ] . V_29 ) ;
V_435 ++ ;
( V_278 ) -> V_279 = ( V_334 ) -> V_454 ;
( V_278 ) -> V_449 = ( V_278 ) -> V_450 = 0 ;
( V_278 ) -> V_451 =
( V_278 ) -> V_452 = 0 ;
F_135 ( V_278 , V_217 , V_385 , V_392 ,
& V_426 [ V_17 ] , & V_428 [ V_17 ] ,
& V_430 [ V_434 ] ) ;
V_278 -> V_282 -> V_453 = V_434 ;
V_278 -> V_282 -> V_311 = V_385 ;
V_434 += V_385 ;
if ( V_140 -> V_439 )
V_140 -> V_439 ( V_252 , V_278 -> V_282 ) ;
}
V_217 -> V_269 . V_270 = (struct V_399 * ) V_420 [ V_17 ] . V_29 ;
F_136 ( V_217 , V_311 , V_392 ,
& V_423 [ V_17 ] , & V_424 [ V_17 ] , & V_425 [ V_432 ] ) ;
V_217 -> V_269 . V_270 -> V_453 = V_432 ;
V_217 -> V_269 . V_270 -> V_311 = V_311 ;
V_432 += V_311 ;
V_217 -> V_269 . V_270 -> V_455 . V_456 = 0 ;
V_217 -> V_269 . V_270 -> V_455 . V_457 = 0 ;
V_217 -> V_269 . V_270 -> V_321 = 0 ;
V_217 -> V_269 . V_270 -> V_391 = V_334 -> V_391 +
( ( V_334 -> V_225 == V_226 ) ?
0 : V_334 -> V_391 ) ;
V_217 -> V_269 . V_270 -> V_458 = & V_217 -> V_269 . V_13 -> V_46 ;
V_217 -> V_269 . V_270 -> V_282 [ 0 ] = V_277 -> V_282 ;
if ( V_278 )
V_217 -> V_269 . V_270 -> V_282 [ 1 ] = V_278 -> V_282 ;
V_217 -> V_269 . V_270 -> V_269 = & V_217 -> V_269 ;
V_217 -> V_269 . V_270 -> V_252 = V_14 -> V_252 ;
V_217 -> V_269 . V_270 -> V_332 =
( ( volatile T_2 * ) V_217 -> V_269 . V_13 -> V_39 +
( V_217 -> V_269 . V_329 * V_90 ) ) ;
* ( V_217 -> V_269 . V_270 -> V_332 ) = 0 ;
V_217 -> V_269 . V_270 -> V_5 = V_415 -> V_5 ;
V_217 -> V_269 . V_270 -> V_459 = ( V_415 -> V_400 == 1 ) ?
V_415 -> V_444 [ 0 ] . V_6 :
V_415 -> V_444 [ V_17 ] . V_6 ;
V_217 -> V_269 . V_270 -> V_460 =
V_217 -> V_269 . V_13 -> V_64 . V_65 ;
V_217 -> V_269 . V_270 -> V_360 = V_17 ;
if ( V_140 -> V_441 )
V_140 -> V_441 ( V_252 , V_217 -> V_269 . V_270 ) ;
}
F_80 ( & V_140 -> V_93 , V_140 , V_334 ) ;
F_34 ( V_140 , F_109 ) ;
return V_140 ;
}
void
F_159 ( struct V_213 * V_140 )
{
struct V_333 * V_241 = & V_140 -> V_14 -> V_241 ;
struct V_2 * V_3 = & V_140 -> V_14 -> V_3 ;
struct V_276 * V_277 = NULL ;
struct V_276 * V_278 = NULL ;
struct V_216 * V_217 ;
struct V_8 * V_9 ;
F_83 ( & V_140 -> V_93 ) ;
while ( ! F_3 ( & V_140 -> V_343 ) ) {
F_4 ( & V_140 -> V_343 , & V_217 ) ;
F_112 ( V_217 , V_277 , V_278 ) ;
if ( V_140 -> V_440 )
V_140 -> V_440 ( V_140 -> V_14 -> V_252 , V_277 -> V_282 ) ;
V_277 -> V_282 = NULL ;
V_277 -> V_217 = NULL ;
V_277 -> V_140 = NULL ;
F_128 ( V_241 , V_277 ) ;
if ( V_278 ) {
if ( V_140 -> V_440 )
V_140 -> V_440 ( V_140 -> V_14 -> V_252 , V_278 -> V_282 ) ;
V_278 -> V_282 = NULL ;
V_278 -> V_217 = NULL ;
V_278 -> V_140 = NULL ;
F_128 ( V_241 , V_278 ) ;
}
V_217 -> V_227 . V_231 . V_232 = NULL ;
V_217 -> V_227 . V_231 . V_350 = NULL ;
if ( V_217 -> V_269 . V_13 ) {
if ( V_217 -> V_269 . V_329 != 0xff )
F_19 ( V_217 -> V_269 . V_13 ,
V_217 -> V_269 . V_329 ) ;
F_14 ( V_3 , V_217 -> V_269 . V_13 ) ;
V_217 -> V_269 . V_13 = NULL ;
}
if ( V_140 -> V_442 )
V_140 -> V_442 ( V_140 -> V_14 -> V_252 , V_217 -> V_269 . V_270 ) ;
V_217 -> V_269 . V_270 = NULL ;
V_217 -> V_140 = NULL ;
F_130 ( V_241 , V_217 ) ;
}
F_2 (qe, &rx_mod->rx_active_q) {
if ( V_9 == & V_140 -> V_9 ) {
F_8 ( & V_140 -> V_9 ) ;
F_5 ( & V_140 -> V_9 ) ;
break;
}
}
V_140 -> V_14 = NULL ;
V_140 -> V_418 = NULL ;
F_132 ( V_241 , V_140 ) ;
}
void
F_160 ( struct V_213 * V_140 )
{
if ( V_140 -> V_250 != ( V_461 ) F_109 )
return;
V_140 -> V_342 |= V_363 ;
if ( V_140 -> V_342 & V_362 )
F_48 ( V_140 , V_272 ) ;
}
void
F_161 ( struct V_213 * V_140 , enum V_462 type ,
void (* F_99)( void * , struct V_213 * ,
enum V_239 ) )
{
if ( type == V_463 ) {
(* F_99)( V_140 -> V_14 -> V_252 , V_140 , V_94 ) ;
} else {
V_140 -> V_247 = F_99 ;
V_140 -> V_248 = V_140 -> V_14 -> V_252 ;
V_140 -> V_342 &= ~ V_363 ;
F_48 ( V_140 , V_274 ) ;
}
}
static void
F_162 ( struct V_464 * V_465 )
{
struct V_466 * V_467 ;
struct V_8 * V_9 ;
F_2 (qe, &tx->txq_q) {
V_467 = (struct V_466 * ) V_9 ;
( V_465 -> V_468 ) ( V_465 -> V_14 -> V_252 , V_467 -> V_469 ) ;
}
F_163 ( V_465 , V_94 ) ;
}
static void
F_164 ( struct V_464 * V_465 , enum V_470 V_96 )
{
switch ( V_96 ) {
case V_471 :
F_34 ( V_465 , V_472 ) ;
break;
case V_473 :
F_34 ( V_465 , F_164 ) ;
break;
case V_474 :
break;
case V_475 :
F_165 ( V_465 , V_94 ) ;
break;
case V_476 :
break;
default:
F_38 ( V_96 ) ;
}
}
static void
F_166 ( struct V_464 * V_465 )
{
struct V_466 * V_467 ;
struct V_8 * V_9 ;
F_167 ( V_465 ) ;
F_2 (qe, &tx->txq_q) {
V_467 = (struct V_466 * ) V_9 ;
F_118 ( & V_467 -> V_13 -> V_46 , 0 ) ;
}
}
static void
V_472 ( struct V_464 * V_465 , enum V_470 V_96 )
{
struct V_466 * V_467 ;
struct V_8 * V_9 ;
switch ( V_96 ) {
case V_473 :
F_34 ( V_465 , V_477 ) ;
F_168 ( V_465 ) ;
break;
case V_474 :
F_2 (qe, &tx->txq_q) {
V_467 = (struct V_466 * ) V_9 ;
F_30 ( V_467 -> V_13 ) ;
( V_465 -> V_478 ) ( V_465 -> V_14 -> V_252 , V_467 -> V_469 ) ;
}
F_34 ( V_465 , F_164 ) ;
break;
case V_475 :
F_34 ( V_465 , V_479 ) ;
break;
default:
F_38 ( V_96 ) ;
}
}
static void
F_169 ( struct V_464 * V_465 )
{
}
static void
V_477 ( struct V_464 * V_465 , enum V_470 V_96 )
{
struct V_466 * V_467 ;
struct V_8 * V_9 ;
switch ( V_96 ) {
case V_474 :
F_34 ( V_465 , F_164 ) ;
break;
case V_476 :
F_2 (qe, &tx->txq_q) {
V_467 = (struct V_466 * ) V_9 ;
F_29 ( V_467 -> V_13 ) ;
}
F_34 ( V_465 , V_480 ) ;
break;
case V_475 :
break;
default:
F_38 ( V_96 ) ;
}
}
static void
F_170 ( struct V_464 * V_465 )
{
F_168 ( V_465 ) ;
}
static void
V_479 ( struct V_464 * V_465 , enum V_470 V_96 )
{
struct V_466 * V_467 ;
struct V_8 * V_9 ;
switch ( V_96 ) {
case V_473 :
F_34 ( V_465 , V_477 ) ;
break;
case V_474 :
F_165 ( V_465 , V_112 ) ;
F_34 ( V_465 , F_164 ) ;
break;
case V_476 :
F_2 (qe, &tx->txq_q) {
V_467 = (struct V_466 * ) V_9 ;
F_29 ( V_467 -> V_13 ) ;
( V_465 -> V_468 ) ( V_465 -> V_14 -> V_252 , V_467 -> V_469 ) ;
}
F_165 ( V_465 , V_94 ) ;
F_34 ( V_465 , V_472 ) ;
break;
case V_475 :
break;
default:
F_38 ( V_96 ) ;
}
}
static void
F_171 ( struct V_464 * V_465 )
{
F_172 ( V_465 ) ;
}
static void
V_480 ( struct V_464 * V_465 , enum V_470 V_96 )
{
switch ( V_96 ) {
case V_474 :
case V_481 :
F_34 ( V_465 , F_164 ) ;
break;
default:
F_38 ( V_96 ) ;
}
}
static void
F_173 ( struct V_464 * V_465 , struct V_466 * V_467 )
{
struct V_295 * V_296 ;
struct V_482 V_483 ;
struct V_482 * V_484 ;
struct V_300 V_301 ;
T_2 V_75 ;
void T_3 * V_77 ;
unsigned long V_23 ;
V_483 . V_305 = V_467 -> V_303 . V_306 . V_42 ;
V_483 . V_307 = V_467 -> V_303 . V_306 . V_44 ;
V_301 = * ( (struct V_300 * ) ( V_467 -> V_303 . V_304 ) ) ;
V_483 . V_308 = V_301 . V_42 ;
V_483 . V_309 = V_301 . V_44 ;
V_483 . V_310 = ( V_467 -> V_303 . V_311 << 16 ) | 0x0 ;
V_483 . V_312 = ( ( T_2 ) ( V_485 >> 2 ) << 16 ) |
( V_467 -> V_303 . V_314 >> 2 ) ;
V_483 . V_328 = ( ( ( ( T_2 ) V_467 -> V_329 ) << 24 ) |
( ( T_2 ) ( V_467 -> V_13 -> V_38 & 0xff ) << 16 ) | 0x0 ) ;
V_483 . V_486 = V_318 ;
V_483 . V_487 = ( ( ( V_465 -> V_488 . V_489 & 0x3f ) << 3 ) |
( V_467 -> V_490 & 0x7 ) ) ;
V_483 . V_491 =
( ( ( ( T_2 ) V_492 & 0xfff ) << 12 ) |
( V_492 & 0xfff ) ) ;
V_75 = F_22 ( V_83 + V_465 -> V_14 -> V_84 ,
V_320 ) ;
F_23 ( V_75 , V_465 -> V_14 -> V_86 . V_87 ) ;
V_77 = F_24 ( V_465 -> V_14 -> V_48 . V_49 ,
V_320 ) ;
V_296 = (struct V_295 * ) 0 ;
V_484 = & V_296 [ V_467 -> V_493 ] . V_467 ;
V_23 = ( unsigned long ) & V_484 -> V_305 ;
F_23 ( F_25 ( V_483 . V_305 ) , V_77 + V_23 ) ;
V_23 = ( unsigned long ) & V_484 -> V_307 ;
F_23 ( F_25 ( V_483 . V_307 ) , V_77 + V_23 ) ;
V_23 = ( unsigned long ) & V_484 -> V_308 ;
F_23 ( F_25 ( V_483 . V_308 ) , V_77 + V_23 ) ;
V_23 = ( unsigned long ) & V_484 -> V_309 ;
F_23 ( F_25 ( V_483 . V_309 ) , V_77 + V_23 ) ;
V_23 = ( unsigned long ) & V_484 -> V_310 ;
F_23 ( V_483 . V_310 , V_77 + V_23 ) ;
V_23 = ( unsigned long ) & V_484 -> V_312 ;
F_23 ( V_483 . V_312 , V_77 + V_23 ) ;
V_23 = ( unsigned long ) & V_484 -> V_328 ;
F_23 ( V_483 . V_328 , V_77 + V_23 ) ;
V_23 = ( unsigned long ) & V_484 -> V_486 ;
F_23 ( V_483 . V_486 , V_77 + V_23 ) ;
V_23 = ( unsigned long ) & V_484 -> V_487 ;
F_23 ( V_483 . V_487 , V_77 + V_23 ) ;
V_23 = ( unsigned long ) & V_484 -> V_491 ;
F_23 ( V_483 . V_491 , V_77 + V_23 ) ;
V_467 -> V_469 -> V_321 = 0 ;
V_467 -> V_469 -> V_322 = 0 ;
* ( V_467 -> V_469 -> V_494 ) = 0 ;
}
static void
F_174 ( struct V_464 * V_465 , struct V_466 * V_467 )
{
struct V_291 V_130 ;
T_2 V_495 [ 2 ] = { 0 , 0 } ;
if ( V_467 -> V_493 < 32 )
V_495 [ 0 ] = ( T_2 ) 1 << V_467 -> V_493 ;
else
V_495 [ 1 ] = ( T_2 ) 1 << ( V_467 -> V_493 - 32 ) ;
memset ( & V_130 , 0 , sizeof( V_130 ) ) ;
V_130 . V_133 . V_496 = V_134 ;
V_130 . V_133 . V_497 = V_498 ;
V_130 . V_133 . V_499 . V_500 . V_501 = 0 ;
V_130 . V_293 [ 0 ] = F_25 ( V_495 [ 0 ] ) ;
V_130 . V_293 [ 1 ] = F_25 ( V_495 [ 1 ] ) ;
F_60 ( & V_465 -> V_138 , & V_130 , sizeof( V_130 ) ,
V_502 , V_465 ) ;
F_61 ( V_465 -> V_14 , & V_465 -> V_138 ) ;
}
static void
F_175 ( struct V_464 * V_465 )
{
struct V_503 * V_504 ;
struct V_505 * V_488 = & V_465 -> V_488 ;
void T_3 * V_77 ;
unsigned long V_23 ;
F_23 ( F_22 ( V_156 +
( V_465 -> V_14 -> V_84 * 2 ) , V_506 ) ,
V_465 -> V_14 -> V_86 . V_87 ) ;
V_77 = F_24 ( V_465 -> V_14 -> V_48 . V_49 ,
V_506 ) ;
V_504 = (struct V_503 * ) 0 ;
V_23 = ( unsigned long ) & V_504 [ V_488 -> V_489 ] . V_507 ;
F_23 ( ( ( T_2 ) V_488 -> V_508 << 16 ) | V_488 -> V_68 ,
V_77 + V_23 ) ;
if ( V_465 -> V_488 . V_489 < 32 )
V_465 -> V_14 -> V_509 . V_510 [ 0 ] |= ( ( T_2 ) 1 << V_465 -> V_488 . V_489 ) ;
else
V_465 -> V_14 -> V_509 . V_510 [ 1 ] |= ( ( T_2 )
1 << ( V_465 -> V_488 . V_489 - 32 ) ) ;
}
static void
F_176 ( struct V_464 * V_465 )
{
struct V_503 * V_504 ;
T_2 V_511 ;
T_2 V_512 ;
struct V_505 * V_488 = & V_465 -> V_488 ;
void T_3 * V_77 ;
unsigned long V_23 ;
V_511 = F_22 ( V_156 +
( V_465 -> V_14 -> V_84 * 2 ) , V_506 ) ;
F_23 ( V_511 , V_465 -> V_14 -> V_86 . V_87 ) ;
V_77 = F_24 ( V_465 -> V_14 -> V_48 . V_49 ,
V_506 ) ;
V_504 = (struct V_503 * ) 0 ;
V_23 = ( unsigned long ) & V_504 [ V_488 -> V_489 ] . V_507 ;
V_512 = F_177 ( V_77 + V_23 ) ;
V_512 &= ~ V_513 ;
F_23 ( V_512 , V_77 + V_23 ) ;
if ( V_465 -> V_488 . V_489 < 32 )
V_465 -> V_14 -> V_509 . V_510 [ 0 ] &= ~ ( ( T_2 ) 1 << V_465 -> V_488 . V_489 ) ;
else
V_465 -> V_14 -> V_509 . V_510 [ 0 ] &= ~ ( ( T_2 )
1 << ( V_465 -> V_488 . V_489 - 32 ) ) ;
}
static void
F_172 ( struct V_464 * V_465 )
{
struct V_188 V_130 ;
T_2 V_510 [ 2 ] = { 0 , 0 } ;
if ( V_465 -> V_488 . V_489 < 32 )
V_510 [ 0 ] = ( ( T_2 ) 1 << V_465 -> V_488 . V_489 ) ;
else
V_510 [ 1 ] = ( ( T_2 ) 1 << ( V_465 -> V_488 . V_489 - 32 ) ) ;
F_59 ( V_130 . V_133 , V_134 , V_189 , 0 ) ;
V_130 . V_190 = 0 ;
V_130 . V_136 [ 0 ] = 0 ;
V_130 . V_136 [ 1 ] = 0 ;
V_130 . V_191 [ 0 ] = F_25 ( V_510 [ 0 ] ) ;
V_130 . V_191 [ 1 ] = F_25 ( V_510 [ 1 ] ) ;
F_60 ( & V_465 -> V_138 , & V_130 , sizeof( V_130 ) ,
V_514 , V_465 ) ;
F_61 ( V_465 -> V_14 , & V_465 -> V_138 ) ;
}
static void
F_167 ( struct V_464 * V_465 )
{
struct V_466 * V_467 ;
struct V_8 * V_9 ;
F_2 (qe, &tx->txq_q) {
V_467 = (struct V_466 * ) V_9 ;
F_21 ( V_467 -> V_13 ) ;
F_173 ( V_465 , V_467 ) ;
}
F_175 ( V_465 ) ;
F_2 (qe, &tx->txq_q) {
V_467 = (struct V_466 * ) V_9 ;
V_467 -> V_469 -> V_490 = V_467 -> V_490 ;
( V_465 -> V_515 ) ( V_465 -> V_14 -> V_252 , V_467 -> V_469 ) ;
}
}
static void
F_168 ( struct V_464 * V_465 )
{
struct V_466 * V_467 ;
struct V_8 * V_9 ;
F_2 (qe, &tx->txq_q) {
V_467 = (struct V_466 * ) V_9 ;
( V_465 -> V_478 ) ( V_465 -> V_14 -> V_252 , V_467 -> V_469 ) ;
}
F_176 ( V_465 ) ;
F_2 (qe, &tx->txq_q) {
V_467 = (struct V_466 * ) V_9 ;
F_123 ( & V_465 -> V_516 ) ;
}
F_2 (qe, &tx->txq_q) {
V_467 = (struct V_466 * ) V_9 ;
F_174 ( V_465 , V_467 ) ;
}
}
static void
F_178 ( struct V_466 * V_467 , int V_311 , int V_314 ,
struct V_355 * V_356 ,
struct V_355 * V_357 ,
struct V_355 * V_358 )
{
int V_17 ;
V_467 -> V_303 . V_306 . V_42 = V_356 -> V_43 . V_42 ;
V_467 -> V_303 . V_306 . V_44 = V_356 -> V_43 . V_44 ;
V_467 -> V_303 . V_304 = V_356 -> V_29 ;
V_467 -> V_303 . V_311 = V_311 ;
V_467 -> V_303 . V_314 = V_314 ;
V_467 -> V_469 -> V_359 = ( void * * ) V_357 -> V_29 ;
for ( V_17 = 0 ; V_17 < V_311 ; V_17 ++ ) {
V_467 -> V_469 -> V_359 [ V_17 ] = V_358 [ V_17 ] . V_29 ;
( (struct V_300 * ) V_467 -> V_303 . V_304 ) [ V_17 ] . V_42 =
V_358 [ V_17 ] . V_43 . V_42 ;
( (struct V_300 * ) V_467 -> V_303 . V_304 ) [ V_17 ] . V_44 =
V_358 [ V_17 ] . V_43 . V_44 ;
}
}
static void
F_179 ( struct V_464 * V_465 )
{
struct V_517 * V_509 = & V_465 -> V_14 -> V_509 ;
struct V_466 * V_467 ;
struct V_2 * V_3 = & V_465 -> V_14 -> V_3 ;
struct V_8 * V_9 ;
while ( ! F_3 ( & V_465 -> V_518 ) ) {
F_4 ( & V_465 -> V_518 , & V_467 ) ;
F_5 ( & V_467 -> V_9 ) ;
if ( V_467 -> V_13 ) {
if ( V_467 -> V_329 != - 1 )
F_19 ( V_467 -> V_13 ,
V_467 -> V_329 ) ;
F_14 ( V_3 , V_467 -> V_13 ) ;
V_467 -> V_13 = NULL ;
}
V_467 -> V_469 = NULL ;
V_467 -> V_465 = NULL ;
F_6 ( & V_467 -> V_9 , & V_509 -> V_519 ) ;
}
F_2 (qe, &tx_mod->tx_active_q) {
if ( V_9 == & V_465 -> V_9 ) {
F_8 ( & V_465 -> V_9 ) ;
F_5 ( & V_465 -> V_9 ) ;
break;
}
}
V_465 -> V_14 = NULL ;
V_465 -> V_418 = NULL ;
F_6 ( & V_465 -> V_9 , & V_509 -> V_520 ) ;
}
static void
V_502 ( void * V_193 , int V_176 )
{
struct V_464 * V_465 = (struct V_464 * ) V_193 ;
F_5 ( & V_465 -> V_138 . V_9 ) ;
F_140 ( & V_465 -> V_516 ) ;
}
static void
F_180 ( void * V_193 )
{
struct V_464 * V_465 = (struct V_464 * ) V_193 ;
F_48 ( V_465 , V_476 ) ;
}
static void
V_514 ( void * V_193 , int V_176 )
{
struct V_464 * V_465 = (struct V_464 * ) V_193 ;
F_5 ( & V_465 -> V_138 . V_9 ) ;
F_48 ( V_465 , V_481 ) ;
}
static void
F_181 ( struct V_464 * V_465 )
{
V_465 -> V_367 |= V_521 ;
if ( V_465 -> V_367 & V_522 )
F_48 ( V_465 , V_471 ) ;
}
static void
F_182 ( struct V_464 * V_465 )
{
V_465 -> V_247 = V_523 ;
V_465 -> V_248 = & V_465 -> V_14 -> V_509 ;
V_465 -> V_367 &= ~ V_521 ;
F_48 ( V_465 , V_473 ) ;
}
static void
F_183 ( struct V_464 * V_465 )
{
V_465 -> V_367 &= ~ V_521 ;
F_48 ( V_465 , V_474 ) ;
}
static void
F_184 ( struct V_464 * V_465 , int V_524 )
{
struct V_466 * V_467 ;
struct V_8 * V_9 ;
F_2 (qe, &tx->txq_q) {
V_467 = (struct V_466 * ) V_9 ;
V_467 -> V_490 = V_524 ;
}
F_48 ( V_465 , V_475 ) ;
}
static void
F_185 ( struct V_464 * V_465 , int V_525 )
{
if ( V_525 )
V_465 -> V_367 |= V_526 ;
else
V_465 -> V_367 &= ~ V_526 ;
}
static void
V_523 ( void * V_193 , struct V_464 * V_465 ,
enum V_239 V_176 )
{
struct V_517 * V_509 = (struct V_517 * ) V_193 ;
F_140 ( & V_509 -> V_527 ) ;
}
static void
F_186 ( void * V_193 )
{
struct V_517 * V_509 = (struct V_517 * ) V_193 ;
if ( V_509 -> V_247 )
V_509 -> V_247 ( & V_509 -> V_14 -> V_280 , V_94 ) ;
V_509 -> V_247 = NULL ;
}
void
F_187 ( int V_528 , int V_529 , struct V_15 * V_16 )
{
T_2 V_530 ;
T_2 V_311 ;
struct V_387 * V_27 ;
V_16 [ V_531 ] . V_394 = V_395 ;
V_27 = & V_16 [ V_531 ] . V_26 . V_27 ;
V_27 -> V_396 = V_397 ;
V_27 -> V_398 = sizeof( struct V_532 ) ;
V_27 -> V_400 = V_528 ;
V_530 = V_529 * V_485 ;
V_530 = F_154 ( V_530 , V_392 ) ;
V_311 = V_530 >> V_533 ;
V_16 [ V_534 ] . V_394 = V_395 ;
V_27 = & V_16 [ V_534 ] . V_26 . V_27 ;
V_27 -> V_396 = V_404 ;
V_27 -> V_398 = V_311 * sizeof( struct V_300 ) ;
V_27 -> V_400 = V_528 ;
V_16 [ V_535 ] . V_394 = V_395 ;
V_27 = & V_16 [ V_535 ] . V_26 . V_27 ;
V_27 -> V_396 = V_397 ;
V_27 -> V_398 = V_311 * sizeof( void * ) ;
V_27 -> V_400 = V_528 ;
V_16 [ V_536 ] . V_394 = V_395 ;
V_27 = & V_16 [ V_536 ] . V_26 . V_27 ;
V_27 -> V_396 = V_404 ;
V_27 -> V_398 = V_392 ;
V_27 -> V_400 = V_528 * V_311 ;
V_16 [ V_537 ] . V_394 = V_414 ;
V_16 [ V_537 ] . V_26 . V_415 . V_5 =
V_70 ;
V_16 [ V_537 ] . V_26 . V_415 . V_400 = V_528 ;
}
struct V_464 *
F_188 ( struct V_14 * V_14 , struct V_252 * V_252 ,
struct V_538 * V_539 ,
struct V_540 * V_541 ,
struct V_15 * V_16 , void * V_418 )
{
struct V_419 * V_415 ;
struct V_517 * V_509 = & V_14 -> V_509 ;
struct V_464 * V_465 ;
struct V_466 * V_467 ;
struct V_8 * V_9 ;
struct V_2 * V_3 = & V_14 -> V_3 ;
struct V_21 * V_22 ;
struct F_20 V_64 ;
int V_311 ;
int V_314 ;
int V_453 ;
int V_17 ;
unsigned long V_23 ;
V_415 = & V_16 [ V_537 ] . V_26 . V_415 ;
V_311 = ( V_16 [ V_536 ] . V_26 . V_27 . V_400 ) /
V_539 -> V_528 ;
V_314 = V_16 [ V_536 ] . V_26 . V_27 . V_398 ;
if ( ( V_415 -> V_400 != 1 ) && ( V_415 -> V_400 != V_539 -> V_528 ) )
return NULL ;
if ( F_3 ( & V_509 -> V_520 ) )
return NULL ;
F_4 ( & V_509 -> V_520 , & V_465 ) ;
F_5 ( & V_465 -> V_9 ) ;
F_10 ( & V_465 -> V_518 ) ;
for ( V_17 = 0 ; V_17 < V_539 -> V_528 ; V_17 ++ ) {
if ( F_3 ( & V_509 -> V_519 ) )
goto V_263;
F_4 ( & V_509 -> V_519 , & V_467 ) ;
F_5 ( & V_467 -> V_9 ) ;
F_6 ( & V_467 -> V_9 , & V_465 -> V_518 ) ;
V_467 -> V_13 = NULL ;
V_467 -> V_329 = - 1 ;
V_467 -> V_465 = V_465 ;
}
V_17 = 0 ;
F_2 (qe, &tx->txq_q) {
V_467 = (struct V_466 * ) V_9 ;
if ( V_415 -> V_400 == 1 )
V_467 -> V_13 = F_13 ( V_3 , V_415 -> V_5 ,
V_415 -> V_444 [ 0 ] . V_6 ) ;
else
V_467 -> V_13 = F_13 ( V_3 , V_415 -> V_5 ,
V_415 -> V_444 [ V_17 ] . V_6 ) ;
if ( V_467 -> V_13 == NULL )
goto V_263;
V_467 -> V_329 = F_15 ( V_467 -> V_13 ) ;
if ( V_467 -> V_329 == - 1 )
goto V_263;
V_17 ++ ;
}
V_465 -> V_542 = V_541 -> V_542 ;
V_465 -> V_543 = V_541 -> V_543 ;
V_465 -> V_478 = V_541 -> V_478 ;
V_465 -> V_515 = V_541 -> V_515 ;
V_465 -> V_468 = V_541 -> V_468 ;
F_6 ( & V_465 -> V_9 , & V_509 -> V_544 ) ;
V_465 -> V_14 = V_14 ;
V_465 -> V_418 = V_418 ;
V_465 -> V_516 . V_344 = F_180 ;
V_465 -> V_516 . V_346 = V_465 ;
V_465 -> V_516 . V_347 = 0 ;
V_465 -> type = V_539 -> V_545 ;
V_465 -> V_367 = 0 ;
if ( V_465 -> V_14 -> V_509 . V_367 & V_546 ) {
switch ( V_465 -> type ) {
case V_547 :
if ( ! ( V_465 -> V_14 -> V_509 . V_367 &
V_548 ) )
V_465 -> V_367 |= V_521 ;
break;
case V_549 :
if ( V_465 -> V_14 -> V_509 . V_367 & V_548 )
V_465 -> V_367 |= V_521 ;
break;
}
}
if ( V_465 -> V_14 -> V_509 . V_525 )
V_465 -> V_367 |= V_526 ;
V_17 = 0 ;
V_453 = 0 ;
F_2 (qe, &tx->txq_q) {
V_467 = (struct V_466 * ) V_9 ;
V_467 -> V_490 = V_509 -> V_490 ;
V_467 -> V_469 = (struct V_532 * )
V_16 [ V_531 ] . V_26 . V_27 . V_28 [ V_17 ] . V_29 ;
V_467 -> V_550 = 0 ;
V_467 -> V_551 = 0 ;
V_64 . V_65 = V_552 ;
V_64 . V_66 = 0 ;
V_64 . V_67 = V_553 ;
V_64 . V_68 = ( V_554 |
V_448 |
V_555 ) ;
F_20 ( V_467 -> V_13 , & V_64 ) ;
V_467 -> V_469 -> V_321 = 0 ;
V_467 -> V_469 -> V_322 = 0 ;
V_467 -> V_469 -> V_494 = ( volatile T_2 * )
( ( volatile T_1 * ) V_467 -> V_13 -> V_39 +
( V_467 -> V_329 * V_90 ) ) ;
* ( V_467 -> V_469 -> V_494 ) = 0 ;
V_467 -> V_469 -> V_391 = V_539 -> V_529 ;
V_467 -> V_469 -> V_556 = ( void * )
V_16 [ V_557 ] . V_26 . V_27 . V_28 [ V_17 ] . V_29 ;
V_22 = (struct V_21 * ) 0 ;
V_23 = ( unsigned long ) & V_22 [ V_467 -> V_493 ] . V_467 [ 0 ] ;
V_467 -> V_469 -> V_558 = V_23 +
F_11 ( V_14 -> V_48 . V_49 ) ;
V_467 -> V_469 -> V_458 = & V_467 -> V_13 -> V_46 ;
V_467 -> V_469 -> V_5 = V_415 -> V_5 ;
V_467 -> V_469 -> V_459 = ( V_415 -> V_400 == 1 ) ?
V_415 -> V_444 [ 0 ] . V_6 :
V_415 -> V_444 [ V_17 ] . V_6 ;
V_467 -> V_469 -> V_467 = V_467 ;
V_467 -> V_469 -> V_252 = V_252 ;
V_467 -> V_469 -> V_360 = V_17 ;
F_178 ( V_467 , V_311 , V_314 ,
& V_16 [ V_534 ] . V_26 . V_27 . V_28 [ V_17 ] ,
& V_16 [ V_535 ] . V_26 . V_27 . V_28 [ V_17 ] ,
& V_16 [ V_536 ] .
V_26 . V_27 . V_28 [ V_453 ] ) ;
V_467 -> V_469 -> V_453 = V_453 ;
V_467 -> V_469 -> V_311 = V_311 ;
V_453 += V_311 ;
if ( V_465 -> V_542 )
( V_465 -> V_542 ) ( V_14 -> V_252 , V_467 -> V_469 ) ;
V_17 ++ ;
}
V_465 -> V_488 . V_68 = V_513 | V_559 ;
V_465 -> V_488 . V_508 = 0 ;
F_5 ( & V_465 -> V_138 . V_9 ) ;
F_34 ( V_465 , F_164 ) ;
return V_465 ;
V_263:
F_179 ( V_465 ) ;
return NULL ;
}
void
F_189 ( struct V_464 * V_465 )
{
if ( V_465 -> V_543 ) {
struct V_466 * V_467 ;
struct V_8 * V_9 ;
F_2 (qe, &tx->txq_q) {
V_467 = (struct V_466 * ) V_9 ;
( V_465 -> V_543 ) ( V_465 -> V_14 -> V_252 , V_467 -> V_469 ) ;
}
}
F_179 ( V_465 ) ;
}
void
F_190 ( struct V_464 * V_465 )
{
if ( V_465 -> V_250 != ( V_461 ) F_164 )
return;
V_465 -> V_367 |= V_522 ;
if ( V_465 -> V_367 & V_521 )
F_48 ( V_465 , V_471 ) ;
}
void
F_191 ( struct V_464 * V_465 , enum V_462 type ,
void (* F_99)( void * , struct V_464 * , enum V_239 ) )
{
if ( type == V_463 ) {
(* F_99)( V_465 -> V_14 -> V_252 , V_465 , V_94 ) ;
return;
}
V_465 -> V_247 = F_99 ;
V_465 -> V_248 = V_465 -> V_14 -> V_252 ;
V_465 -> V_367 &= ~ V_522 ;
F_48 ( V_465 , V_473 ) ;
}
int
F_192 ( struct V_464 * V_465 )
{
return F_97 ( V_560 , V_465 -> V_250 ) ;
}
void
F_193 ( struct V_517 * V_509 , struct V_14 * V_14 ,
struct V_15 * V_16 )
{
int V_17 ;
V_509 -> V_14 = V_14 ;
V_509 -> V_367 = 0 ;
V_509 -> V_465 = (struct V_464 * )
V_16 [ V_561 ] . V_26 . V_27 . V_28 [ 0 ] . V_29 ;
V_509 -> V_467 = (struct V_466 * )
V_16 [ V_562 ] . V_26 . V_27 . V_28 [ 0 ] . V_29 ;
F_10 ( & V_509 -> V_520 ) ;
F_10 ( & V_509 -> V_544 ) ;
F_10 ( & V_509 -> V_519 ) ;
for ( V_17 = 0 ; V_17 < V_563 ; V_17 ++ ) {
V_509 -> V_465 [ V_17 ] . V_488 . V_489 = V_17 ;
F_5 ( & V_509 -> V_465 [ V_17 ] . V_9 ) ;
F_6 ( & V_509 -> V_465 [ V_17 ] . V_9 , & V_509 -> V_520 ) ;
V_509 -> V_467 [ V_17 ] . V_493 = V_17 ;
F_5 ( & V_509 -> V_467 [ V_17 ] . V_9 ) ;
F_6 ( & V_509 -> V_467 [ V_17 ] . V_9 , & V_509 -> V_519 ) ;
}
V_509 -> V_527 . V_344 = F_186 ;
V_509 -> V_527 . V_346 = V_509 ;
V_509 -> V_527 . V_347 = 0 ;
}
void
F_194 ( struct V_517 * V_509 )
{
struct V_8 * V_9 ;
int V_17 ;
V_17 = 0 ;
F_2 (qe, &tx_mod->tx_free_q)
V_17 ++ ;
V_17 = 0 ;
F_2 (qe, &tx_mod->txq_free_q)
V_17 ++ ;
V_509 -> V_14 = NULL ;
}
void
F_195 ( struct V_517 * V_509 , enum V_564 type )
{
struct V_464 * V_465 ;
struct V_8 * V_9 ;
V_509 -> V_367 |= V_546 ;
if ( type == V_549 )
V_509 -> V_367 |= V_548 ;
F_2 (qe, &tx_mod->tx_active_q) {
V_465 = (struct V_464 * ) V_9 ;
if ( V_465 -> type == type )
F_181 ( V_465 ) ;
}
}
void
F_196 ( struct V_517 * V_509 , enum V_564 type )
{
struct V_464 * V_465 ;
struct V_8 * V_9 ;
V_509 -> V_367 &= ~ V_546 ;
V_509 -> V_367 &= ~ V_548 ;
V_509 -> V_247 = V_565 ;
F_2 (qe, &tx_mod->tx_active_q) {
V_465 = (struct V_464 * ) V_9 ;
if ( V_465 -> type == type )
F_123 ( & V_509 -> V_527 ) ;
}
if ( V_509 -> V_527 . V_347 == 0 ) {
V_509 -> V_247 ( & V_509 -> V_14 -> V_280 , V_94 ) ;
V_509 -> V_247 = NULL ;
return;
}
F_2 (qe, &tx_mod->tx_active_q) {
V_465 = (struct V_464 * ) V_9 ;
if ( V_465 -> type == type )
F_182 ( V_465 ) ;
}
}
void
F_197 ( struct V_517 * V_509 )
{
struct V_464 * V_465 ;
struct V_8 * V_9 ;
V_509 -> V_367 &= ~ V_546 ;
V_509 -> V_367 &= ~ V_548 ;
F_2 (qe, &tx_mod->tx_active_q) {
V_465 = (struct V_464 * ) V_9 ;
F_183 ( V_465 ) ;
}
}
void
F_198 ( struct V_517 * V_509 , int V_524 )
{
struct V_464 * V_465 ;
struct V_8 * V_9 ;
if ( V_524 != V_509 -> V_490 ) {
V_509 -> V_490 = V_524 ;
F_2 (qe, &tx_mod->tx_active_q) {
V_465 = (struct V_464 * ) V_9 ;
F_184 ( V_465 , V_524 ) ;
}
}
}
void
F_199 ( struct V_517 * V_509 , int V_525 )
{
struct V_464 * V_465 ;
struct V_8 * V_9 ;
V_509 -> V_525 = V_525 ;
F_2 (qe, &tx_mod->tx_active_q) {
V_465 = (struct V_464 * ) V_9 ;
F_185 ( V_465 , V_525 ) ;
}
}
