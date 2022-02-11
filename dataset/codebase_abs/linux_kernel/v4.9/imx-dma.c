static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_4 ;
}
static inline int F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_5 ;
}
static struct V_6 * F_3 ( struct V_7 * V_8 )
{
return F_4 ( V_8 , struct V_6 , V_8 ) ;
}
static inline bool F_5 ( struct V_6 * V_9 )
{
struct V_10 * V_11 ;
if ( ! F_6 ( & V_9 -> V_12 ) ) {
V_11 = F_7 ( & V_9 -> V_12 , struct V_10 ,
V_13 ) ;
if ( V_11 -> type == V_14 )
return true ;
}
return false ;
}
static void F_8 ( struct V_1 * V_2 , unsigned V_15 ,
unsigned V_16 )
{
F_9 ( V_15 , V_2 -> V_17 + V_16 ) ;
}
static unsigned F_10 ( struct V_1 * V_2 , unsigned V_16 )
{
return F_11 ( V_2 -> V_17 + V_16 ) ;
}
static int F_12 ( struct V_6 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
if ( F_2 ( V_2 ) )
return V_9 -> V_18 ;
else
return 0 ;
}
static inline int F_13 ( struct V_10 * V_19 )
{
struct V_6 * V_9 = F_3 ( V_19 -> V_11 . V_8 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_20 * V_21 = V_19 -> V_21 ;
unsigned long V_22 ;
V_22 = F_14 ( V_19 -> V_23 , F_15 ( V_21 ) ) ;
if ( V_19 -> V_23 != V_24 )
V_19 -> V_23 -= V_22 ;
if ( V_19 -> V_25 == V_26 )
F_8 ( V_2 , V_21 -> V_27 ,
F_16 ( V_9 -> V_28 ) ) ;
else
F_8 ( V_2 , V_21 -> V_27 ,
F_17 ( V_9 -> V_28 ) ) ;
F_8 ( V_2 , V_22 , F_18 ( V_9 -> V_28 ) ) ;
F_19 ( V_2 -> V_29 , L_1
L_2 , V_30 , V_9 -> V_28 ,
F_10 ( V_2 , F_16 ( V_9 -> V_28 ) ) ,
F_10 ( V_2 , F_17 ( V_9 -> V_28 ) ) ,
F_10 ( V_2 , F_18 ( V_9 -> V_28 ) ) ) ;
return V_22 ;
}
static void F_20 ( struct V_10 * V_19 )
{
struct V_6 * V_9 = F_3 ( V_19 -> V_11 . V_8 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
int V_28 = V_9 -> V_28 ;
unsigned long V_31 ;
F_19 ( V_2 -> V_29 , L_3 , V_30 , V_28 ) ;
F_21 ( V_31 ) ;
F_8 ( V_2 , 1 << V_28 , V_32 ) ;
F_8 ( V_2 , F_10 ( V_2 , V_33 ) &
~ ( 1 << V_28 ) , V_33 ) ;
F_8 ( V_2 , F_10 ( V_2 , F_22 ( V_28 ) ) |
V_34 | V_35 , F_22 ( V_28 ) ) ;
if ( ! F_1 ( V_2 ) &&
V_19 -> V_21 && F_12 ( V_9 ) ) {
V_19 -> V_21 = F_23 ( V_19 -> V_21 ) ;
if ( V_19 -> V_21 ) {
T_1 V_36 ;
F_13 ( V_19 ) ;
V_36 = F_10 ( V_2 , F_22 ( V_28 ) ) ;
F_8 ( V_2 , V_36 | V_37 | V_35 ,
F_22 ( V_28 ) ) ;
}
}
F_24 ( V_31 ) ;
}
static void F_25 ( struct V_6 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
int V_28 = V_9 -> V_28 ;
unsigned long V_31 ;
F_19 ( V_2 -> V_29 , L_3 , V_30 , V_28 ) ;
if ( F_12 ( V_9 ) )
F_26 ( & V_9 -> V_38 ) ;
F_21 ( V_31 ) ;
F_8 ( V_2 , F_10 ( V_2 , V_33 ) |
( 1 << V_28 ) , V_33 ) ;
F_8 ( V_2 , F_10 ( V_2 , F_22 ( V_28 ) ) &
~ V_34 , F_22 ( V_28 ) ) ;
F_8 ( V_2 , 1 << V_28 , V_32 ) ;
F_24 ( V_31 ) ;
}
static void F_27 ( unsigned long V_39 )
{
struct V_6 * V_9 = (struct V_6 * ) V_39 ;
struct V_1 * V_2 = V_9 -> V_2 ;
int V_28 = V_9 -> V_28 ;
F_8 ( V_2 , 0 , F_22 ( V_28 ) ) ;
F_28 ( & V_9 -> V_40 ) ;
F_19 ( V_2 -> V_29 , L_4 ,
V_9 -> V_28 ) ;
}
static T_2 F_29 ( int V_41 , void * V_42 )
{
struct V_1 * V_2 = V_42 ;
unsigned int V_43 ;
int V_44 , V_45 ;
int V_46 ;
V_45 = F_10 ( V_2 , V_32 ) ;
V_43 = F_10 ( V_2 , V_47 ) |
F_10 ( V_2 , V_48 ) |
F_10 ( V_2 , V_49 ) |
F_10 ( V_2 , V_50 ) ;
if ( ! V_43 )
return V_51 ;
F_8 ( V_2 , V_45 & V_43 , V_32 ) ;
for ( V_44 = 0 ; V_44 < V_52 ; V_44 ++ ) {
if ( ! ( V_43 & ( 1 << V_44 ) ) )
continue;
V_46 = 0 ;
if ( F_10 ( V_2 , V_47 ) & ( 1 << V_44 ) ) {
F_8 ( V_2 , 1 << V_44 , V_47 ) ;
V_46 |= V_53 ;
}
if ( F_10 ( V_2 , V_48 ) & ( 1 << V_44 ) ) {
F_8 ( V_2 , 1 << V_44 , V_48 ) ;
V_46 |= V_54 ;
}
if ( F_10 ( V_2 , V_49 ) & ( 1 << V_44 ) ) {
F_8 ( V_2 , 1 << V_44 , V_49 ) ;
V_46 |= V_55 ;
}
if ( F_10 ( V_2 , V_50 ) & ( 1 << V_44 ) ) {
F_8 ( V_2 , 1 << V_44 , V_50 ) ;
V_46 |= V_56 ;
}
F_28 ( & V_2 -> V_28 [ V_44 ] . V_40 ) ;
F_30 ( V_2 -> V_29 ,
L_5 , V_44 ,
V_46 & V_53 ? L_6 : L_7 ,
V_46 & V_54 ? L_8 : L_7 ,
V_46 & V_55 ? L_9 : L_7 ,
V_46 & V_56 ? L_10 : L_7 ) ;
}
return V_51 ;
}
static void F_31 ( struct V_6 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
int V_57 = V_9 -> V_28 ;
struct V_10 * V_11 ;
unsigned long V_31 ;
F_32 ( & V_2 -> V_58 , V_31 ) ;
if ( F_6 ( & V_9 -> V_12 ) ) {
F_33 ( & V_2 -> V_58 , V_31 ) ;
goto V_59;
}
V_11 = F_7 ( & V_9 -> V_12 ,
struct V_10 ,
V_13 ) ;
F_33 ( & V_2 -> V_58 , V_31 ) ;
if ( V_11 -> V_21 ) {
T_1 V_36 ;
V_11 -> V_21 = F_23 ( V_11 -> V_21 ) ;
if ( V_11 -> V_21 ) {
F_13 ( V_11 ) ;
V_36 = F_10 ( V_2 , F_22 ( V_57 ) ) ;
if ( F_12 ( V_9 ) ) {
F_34 ( & V_9 -> V_38 ,
V_60 + F_35 ( 500 ) ) ;
V_36 |= V_34 | V_37 | V_35 ;
F_8 ( V_2 , V_36 , F_22 ( V_57 ) ) ;
} else {
F_8 ( V_2 , V_36 & ~ V_34 ,
F_22 ( V_57 ) ) ;
V_36 |= V_34 ;
}
F_8 ( V_2 , V_36 , F_22 ( V_57 ) ) ;
if ( F_5 ( V_9 ) )
F_28 ( & V_9 -> V_40 ) ;
return;
}
if ( F_12 ( V_9 ) ) {
F_26 ( & V_9 -> V_38 ) ;
return;
}
}
V_59:
F_8 ( V_2 , 0 , F_22 ( V_57 ) ) ;
F_28 ( & V_9 -> V_40 ) ;
}
static T_2 F_36 ( int V_41 , void * V_42 )
{
struct V_1 * V_2 = V_42 ;
int V_44 , V_45 ;
if ( ! F_1 ( V_2 ) )
F_29 ( V_41 , V_42 ) ;
V_45 = F_10 ( V_2 , V_32 ) ;
F_19 ( V_2 -> V_29 , L_11 , V_30 , V_45 ) ;
F_8 ( V_2 , V_45 , V_32 ) ;
for ( V_44 = 0 ; V_44 < V_52 ; V_44 ++ ) {
if ( V_45 & ( 1 << V_44 ) )
F_31 ( & V_2 -> V_28 [ V_44 ] ) ;
}
return V_51 ;
}
static int F_37 ( struct V_10 * V_19 )
{
struct V_6 * V_9 = F_3 ( V_19 -> V_11 . V_8 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
int V_61 = - 1 ;
int V_44 ;
switch ( V_19 -> type ) {
case V_62 :
for ( V_44 = 0 ; V_44 < V_63 ; V_44 ++ ) {
if ( ( V_2 -> V_64 [ V_44 ] . V_65 > 0 ) &&
( ( V_2 -> V_64 [ V_44 ] . V_66 != V_19 -> V_67 ) ||
( V_2 -> V_64 [ V_44 ] . V_68 != V_19 -> V_69 ) ||
( V_2 -> V_64 [ V_44 ] . V_70 != V_19 -> V_71 ) ) )
continue;
V_61 = V_44 ;
break;
}
if ( V_61 < 0 )
return - V_72 ;
V_2 -> V_64 [ V_61 ] . V_66 = V_19 -> V_67 ;
V_2 -> V_64 [ V_61 ] . V_68 = V_19 -> V_69 ;
V_2 -> V_64 [ V_61 ] . V_70 = V_19 -> V_71 ;
V_2 -> V_64 [ V_61 ] . V_65 ++ ;
V_9 -> V_73 = V_61 ;
V_9 -> V_74 = true ;
if ( V_61 == V_75 ) {
V_19 -> V_76 &= ~ V_77 ;
V_19 -> V_78 &= ~ V_77 ;
F_8 ( V_2 , V_19 -> V_67 , V_79 ) ;
F_8 ( V_2 , V_19 -> V_69 , V_80 ) ;
F_8 ( V_2 , V_19 -> V_71 , V_81 ) ;
} else {
V_19 -> V_76 |= V_77 ;
V_19 -> V_78 |= V_77 ;
F_8 ( V_2 , V_19 -> V_67 , V_82 ) ;
F_8 ( V_2 , V_19 -> V_69 , V_83 ) ;
F_8 ( V_2 , V_19 -> V_71 , V_84 ) ;
}
case V_85 :
F_8 ( V_2 , V_19 -> V_86 , F_17 ( V_9 -> V_28 ) ) ;
F_8 ( V_2 , V_19 -> V_87 , F_16 ( V_9 -> V_28 ) ) ;
F_8 ( V_2 , V_19 -> V_76 | ( V_19 -> V_78 << 2 ) ,
F_22 ( V_9 -> V_28 ) ) ;
F_8 ( V_2 , V_19 -> V_23 , F_18 ( V_9 -> V_28 ) ) ;
F_19 ( V_2 -> V_29 ,
L_12 ,
V_30 , V_9 -> V_28 ,
( unsigned long long ) V_19 -> V_87 ,
( unsigned long long ) V_19 -> V_86 , V_19 -> V_23 ) ;
break;
case V_14 :
case V_88 :
if ( V_19 -> V_25 == V_26 ) {
F_8 ( V_2 , V_9 -> V_89 ,
F_17 ( V_9 -> V_28 ) ) ;
F_8 ( V_2 , V_9 -> V_90 ,
F_22 ( V_9 -> V_28 ) ) ;
F_19 ( V_2 -> V_29 ,
L_13 ,
V_30 , V_9 -> V_28 ,
V_19 -> V_21 , V_19 -> V_91 , V_19 -> V_23 ,
( unsigned long long ) V_9 -> V_89 ) ;
} else if ( V_19 -> V_25 == V_92 ) {
F_8 ( V_2 , V_9 -> V_89 ,
F_16 ( V_9 -> V_28 ) ) ;
F_8 ( V_2 , V_9 -> V_93 ,
F_22 ( V_9 -> V_28 ) ) ;
F_19 ( V_2 -> V_29 ,
L_14 ,
V_30 , V_9 -> V_28 ,
V_19 -> V_21 , V_19 -> V_91 , V_19 -> V_23 ,
( unsigned long long ) V_9 -> V_89 ) ;
} else {
F_38 ( V_2 -> V_29 , L_15 ,
V_30 , V_9 -> V_28 ) ;
return - V_94 ;
}
F_13 ( V_19 ) ;
break;
default:
return - V_94 ;
}
F_20 ( V_19 ) ;
return 0 ;
}
static void F_39 ( unsigned long V_39 )
{
struct V_6 * V_9 = ( void * ) V_39 ;
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_10 * V_11 ;
unsigned long V_31 ;
F_32 ( & V_2 -> V_58 , V_31 ) ;
if ( F_6 ( & V_9 -> V_12 ) ) {
F_33 ( & V_2 -> V_58 , V_31 ) ;
return;
}
V_11 = F_7 ( & V_9 -> V_12 , struct V_10 , V_13 ) ;
if ( F_5 ( V_9 ) )
goto V_59;
else
F_40 ( & V_11 -> V_11 ) ;
if ( V_9 -> V_74 ) {
V_2 -> V_64 [ V_9 -> V_73 ] . V_65 -- ;
V_9 -> V_74 = false ;
}
F_41 ( V_9 -> V_12 . V_95 , & V_9 -> V_96 ) ;
if ( ! F_6 ( & V_9 -> V_97 ) ) {
V_11 = F_7 ( & V_9 -> V_97 , struct V_10 ,
V_13 ) ;
F_41 ( V_9 -> V_97 . V_95 , & V_9 -> V_12 ) ;
if ( F_37 ( V_11 ) < 0 )
F_30 ( V_2 -> V_29 , L_16 ,
V_30 , V_9 -> V_28 ) ;
}
V_59:
F_33 ( & V_2 -> V_58 , V_31 ) ;
F_42 ( & V_11 -> V_11 , NULL ) ;
}
static int F_43 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_3 ( V_8 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
unsigned long V_31 ;
F_25 ( V_9 ) ;
F_32 ( & V_2 -> V_58 , V_31 ) ;
F_44 ( & V_9 -> V_12 , & V_9 -> V_96 ) ;
F_44 ( & V_9 -> V_97 , & V_9 -> V_96 ) ;
F_33 ( & V_2 -> V_58 , V_31 ) ;
return 0 ;
}
static int F_45 ( struct V_7 * V_8 ,
struct V_98 * V_99 )
{
struct V_6 * V_9 = F_3 ( V_8 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
unsigned int V_100 = 0 ;
if ( V_99 -> V_25 == V_26 ) {
V_9 -> V_89 = V_99 -> V_101 ;
V_9 -> V_102 = V_99 -> V_103 ;
V_9 -> V_104 = V_99 -> V_105 ;
} else {
V_9 -> V_89 = V_99 -> V_106 ;
V_9 -> V_102 = V_99 -> V_107 ;
V_9 -> V_104 = V_99 -> V_108 ;
}
switch ( V_9 -> V_104 ) {
case V_109 :
V_100 = V_110 ;
break;
case V_111 :
V_100 = V_112 ;
break;
default:
case V_113 :
V_100 = V_114 ;
break;
}
V_9 -> V_18 = 0 ;
V_9 -> V_90 = ( V_100 | V_115 ) |
( ( V_114 | V_116 ) << 2 ) |
V_117 ;
V_9 -> V_93 =
( V_114 | V_116 ) |
( ( V_100 | V_115 ) << 2 ) | V_117 ;
F_8 ( V_2 , V_9 -> V_118 ,
F_46 ( V_9 -> V_28 ) ) ;
F_8 ( V_2 , V_9 -> V_102 *
V_9 -> V_104 , F_47 ( V_9 -> V_28 ) ) ;
return 0 ;
}
static enum V_119 F_48 ( struct V_7 * V_8 ,
T_3 V_120 ,
struct V_121 * V_122 )
{
return F_49 ( V_8 , V_120 , V_122 ) ;
}
static T_3 F_50 ( struct V_123 * V_124 )
{
struct V_6 * V_9 = F_3 ( V_124 -> V_8 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
T_3 V_120 ;
unsigned long V_31 ;
F_32 ( & V_2 -> V_58 , V_31 ) ;
F_41 ( V_9 -> V_96 . V_95 , & V_9 -> V_97 ) ;
V_120 = F_51 ( V_124 ) ;
F_33 ( & V_2 -> V_58 , V_31 ) ;
return V_120 ;
}
static int F_52 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_3 ( V_8 ) ;
struct V_125 * V_39 = V_8 -> V_126 ;
if ( V_39 != NULL )
V_9 -> V_118 = V_39 -> V_118 ;
while ( V_9 -> V_127 < V_128 ) {
struct V_10 * V_11 ;
V_11 = F_53 ( sizeof( * V_11 ) , V_129 ) ;
if ( ! V_11 )
break;
F_54 ( & V_11 -> V_11 , sizeof( struct V_123 ) ) ;
F_55 ( & V_11 -> V_11 , V_8 ) ;
V_11 -> V_11 . V_130 = F_50 ;
V_11 -> V_11 . V_31 = V_131 ;
V_11 -> V_132 = V_133 ;
F_56 ( & V_11 -> V_13 , & V_9 -> V_96 ) ;
V_9 -> V_127 ++ ;
}
if ( ! V_9 -> V_127 )
return - V_134 ;
return V_9 -> V_127 ;
}
static void F_57 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_3 ( V_8 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_10 * V_11 , * V_135 ;
unsigned long V_31 ;
F_32 ( & V_2 -> V_58 , V_31 ) ;
F_25 ( V_9 ) ;
F_44 ( & V_9 -> V_12 , & V_9 -> V_96 ) ;
F_44 ( & V_9 -> V_97 , & V_9 -> V_96 ) ;
F_33 ( & V_2 -> V_58 , V_31 ) ;
F_58 (desc, _desc, &imxdmac->ld_free, node) {
F_59 ( V_11 ) ;
V_9 -> V_127 -- ;
}
F_60 ( & V_9 -> V_96 ) ;
F_59 ( V_9 -> V_136 ) ;
V_9 -> V_136 = NULL ;
}
static struct V_123 * F_61 (
struct V_7 * V_8 , struct V_20 * V_137 ,
unsigned int V_138 , enum V_139 V_25 ,
unsigned long V_31 , void * V_140 )
{
struct V_6 * V_9 = F_3 ( V_8 ) ;
struct V_20 * V_21 ;
int V_44 , V_141 = 0 ;
struct V_10 * V_11 ;
if ( F_6 ( & V_9 -> V_96 ) ||
F_5 ( V_9 ) )
return NULL ;
V_11 = F_7 ( & V_9 -> V_96 , struct V_10 , V_13 ) ;
F_62 (sgl, sg, sg_len, i) {
V_141 += F_15 ( V_21 ) ;
}
switch ( V_9 -> V_104 ) {
case V_113 :
if ( F_15 ( V_137 ) & 3 || V_137 -> V_27 & 3 )
return NULL ;
break;
case V_111 :
if ( F_15 ( V_137 ) & 1 || V_137 -> V_27 & 1 )
return NULL ;
break;
case V_109 :
break;
default:
return NULL ;
}
V_11 -> type = V_88 ;
V_11 -> V_21 = V_137 ;
V_11 -> V_91 = V_138 ;
V_11 -> V_23 = V_141 ;
V_11 -> V_25 = V_25 ;
if ( V_25 == V_26 ) {
V_11 -> V_86 = V_9 -> V_89 ;
} else {
V_11 -> V_87 = V_9 -> V_89 ;
}
V_11 -> V_11 . V_142 = NULL ;
V_11 -> V_11 . V_143 = NULL ;
return & V_11 -> V_11 ;
}
static struct V_123 * F_63 (
struct V_7 * V_8 , T_4 V_144 , T_5 V_145 ,
T_5 V_146 , enum V_139 V_25 ,
unsigned long V_31 )
{
struct V_6 * V_9 = F_3 ( V_8 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_10 * V_11 ;
int V_44 ;
unsigned int V_147 = V_145 / V_146 ;
F_19 ( V_2 -> V_29 , L_17 ,
V_30 , V_9 -> V_28 , V_145 , V_146 ) ;
if ( F_6 ( & V_9 -> V_96 ) ||
F_5 ( V_9 ) )
return NULL ;
V_11 = F_7 ( & V_9 -> V_96 , struct V_10 , V_13 ) ;
F_59 ( V_9 -> V_136 ) ;
V_9 -> V_136 = F_64 ( V_147 + 1 ,
sizeof( struct V_20 ) , V_148 ) ;
if ( ! V_9 -> V_136 )
return NULL ;
F_65 ( V_9 -> V_136 , V_147 ) ;
for ( V_44 = 0 ; V_44 < V_147 ; V_44 ++ ) {
V_9 -> V_136 [ V_44 ] . V_149 = 0 ;
V_9 -> V_136 [ V_44 ] . V_16 = 0 ;
V_9 -> V_136 [ V_44 ] . V_27 = V_144 ;
F_15 ( & V_9 -> V_136 [ V_44 ] ) = V_146 ;
V_144 += V_146 ;
}
V_9 -> V_136 [ V_147 ] . V_16 = 0 ;
F_15 ( & V_9 -> V_136 [ V_147 ] ) = 0 ;
V_9 -> V_136 [ V_147 ] . V_149 =
( ( unsigned long ) V_9 -> V_136 | 0x01 ) & ~ 0x02 ;
V_11 -> type = V_14 ;
V_11 -> V_21 = V_9 -> V_136 ;
V_11 -> V_91 = V_147 ;
V_11 -> V_23 = V_24 ;
V_11 -> V_25 = V_25 ;
if ( V_25 == V_26 ) {
V_11 -> V_86 = V_9 -> V_89 ;
} else {
V_11 -> V_87 = V_9 -> V_89 ;
}
V_11 -> V_11 . V_142 = NULL ;
V_11 -> V_11 . V_143 = NULL ;
return & V_11 -> V_11 ;
}
static struct V_123 * F_66 (
struct V_7 * V_8 , T_4 V_87 ,
T_4 V_86 , T_5 V_23 , unsigned long V_31 )
{
struct V_6 * V_9 = F_3 ( V_8 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_10 * V_11 ;
F_19 ( V_2 -> V_29 , L_18 ,
V_30 , V_9 -> V_28 , ( unsigned long long ) V_86 ,
( unsigned long long ) V_87 , V_23 ) ;
if ( F_6 ( & V_9 -> V_96 ) ||
F_5 ( V_9 ) )
return NULL ;
V_11 = F_7 ( & V_9 -> V_96 , struct V_10 , V_13 ) ;
V_11 -> type = V_85 ;
V_11 -> V_86 = V_86 ;
V_11 -> V_87 = V_87 ;
V_11 -> V_23 = V_23 ;
V_11 -> V_25 = V_150 ;
V_11 -> V_78 = V_114 | V_116 ;
V_11 -> V_76 = V_114 | V_116 ;
V_11 -> V_11 . V_142 = NULL ;
V_11 -> V_11 . V_143 = NULL ;
return & V_11 -> V_11 ;
}
static struct V_123 * F_67 (
struct V_7 * V_8 , struct V_151 * V_152 ,
unsigned long V_31 )
{
struct V_6 * V_9 = F_3 ( V_8 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_10 * V_11 ;
F_19 ( V_2 -> V_29 , L_19
L_20 , V_30 ,
V_9 -> V_28 , ( unsigned long long ) V_152 -> V_153 ,
( unsigned long long ) V_152 -> V_154 ,
V_152 -> V_155 ? L_21 : L_22 , V_152 -> V_156 ? L_21 : L_22 ,
V_152 -> V_157 , V_152 -> V_158 ) ;
if ( F_6 ( & V_9 -> V_96 ) ||
F_5 ( V_9 ) )
return NULL ;
if ( V_152 -> V_158 != 1 || V_152 -> V_157 <= 0 || V_152 -> V_159 != V_150 )
return NULL ;
V_11 = F_7 ( & V_9 -> V_96 , struct V_10 , V_13 ) ;
V_11 -> type = V_62 ;
V_11 -> V_86 = V_152 -> V_153 ;
V_11 -> V_87 = V_152 -> V_154 ;
V_11 -> V_67 = V_152 -> V_137 [ 0 ] . V_160 ;
V_11 -> V_69 = V_152 -> V_157 ;
V_11 -> V_71 = V_152 -> V_137 [ 0 ] . V_161 + V_11 -> V_67 ;
V_11 -> V_23 = V_11 -> V_67 * V_11 -> V_69 ;
V_11 -> V_25 = V_150 ;
V_11 -> V_78 = V_114 ;
V_11 -> V_76 = V_114 ;
if ( V_152 -> V_155 )
V_11 -> V_76 |= V_162 ;
if ( V_152 -> V_156 )
V_11 -> V_78 |= V_162 ;
V_11 -> V_11 . V_142 = NULL ;
V_11 -> V_11 . V_143 = NULL ;
return & V_11 -> V_11 ;
}
static void F_68 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_3 ( V_8 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_10 * V_11 ;
unsigned long V_31 ;
F_32 ( & V_2 -> V_58 , V_31 ) ;
if ( F_6 ( & V_9 -> V_12 ) &&
! F_6 ( & V_9 -> V_97 ) ) {
V_11 = F_7 ( & V_9 -> V_97 ,
struct V_10 , V_13 ) ;
if ( F_37 ( V_11 ) < 0 ) {
F_30 ( V_2 -> V_29 ,
L_23 ,
V_30 , V_9 -> V_28 ) ;
} else {
F_41 ( V_9 -> V_97 . V_95 ,
& V_9 -> V_12 ) ;
}
}
F_33 ( & V_2 -> V_58 , V_31 ) ;
}
static bool F_69 ( struct V_7 * V_8 , void * V_163 )
{
struct V_164 * V_165 = V_163 ;
struct V_6 * V_166 = F_3 ( V_8 ) ;
if ( V_8 -> V_167 -> V_29 != V_165 -> V_2 -> V_29 )
return false ;
V_166 -> V_118 = V_165 -> V_168 ;
V_8 -> V_126 = NULL ;
return true ;
}
static struct V_7 * F_70 ( struct V_169 * V_170 ,
struct V_171 * V_172 )
{
int V_65 = V_170 -> V_173 ;
struct V_1 * V_2 = V_172 -> V_174 ;
struct V_164 V_165 = {
. V_2 = V_2 ,
} ;
if ( V_65 != 1 )
return NULL ;
V_165 . V_168 = V_170 -> args [ 0 ] ;
return F_71 ( V_2 -> V_175 . V_176 ,
F_69 , & V_165 ) ;
}
static int T_6 F_72 ( struct V_177 * V_178 )
{
struct V_1 * V_2 ;
struct V_179 * V_180 ;
const struct V_181 * V_182 ;
int V_183 , V_44 ;
int V_41 , V_184 ;
V_182 = F_73 ( V_185 , & V_178 -> V_29 ) ;
if ( V_182 )
V_178 -> V_186 = V_182 -> V_39 ;
V_2 = F_74 ( & V_178 -> V_29 , sizeof( * V_2 ) , V_129 ) ;
if ( ! V_2 )
return - V_134 ;
V_2 -> V_29 = & V_178 -> V_29 ;
V_2 -> V_3 = V_178 -> V_186 -> V_187 ;
V_180 = F_75 ( V_178 , V_188 , 0 ) ;
V_2 -> V_17 = F_76 ( & V_178 -> V_29 , V_180 ) ;
if ( F_77 ( V_2 -> V_17 ) )
return F_78 ( V_2 -> V_17 ) ;
V_41 = F_79 ( V_178 , 0 ) ;
if ( V_41 < 0 )
return V_41 ;
V_2 -> V_189 = F_80 ( & V_178 -> V_29 , L_24 ) ;
if ( F_77 ( V_2 -> V_189 ) )
return F_78 ( V_2 -> V_189 ) ;
V_2 -> V_190 = F_80 ( & V_178 -> V_29 , L_25 ) ;
if ( F_77 ( V_2 -> V_190 ) )
return F_78 ( V_2 -> V_190 ) ;
V_183 = F_81 ( V_2 -> V_189 ) ;
if ( V_183 )
return V_183 ;
V_183 = F_81 ( V_2 -> V_190 ) ;
if ( V_183 )
goto V_191;
F_8 ( V_2 , V_192 , V_193 ) ;
if ( F_1 ( V_2 ) ) {
V_183 = F_82 ( & V_178 -> V_29 , V_41 ,
F_36 , 0 , L_26 , V_2 ) ;
if ( V_183 ) {
F_30 ( V_2 -> V_29 , L_27 ) ;
goto V_194;
}
V_2 -> V_41 = V_41 ;
V_184 = F_79 ( V_178 , 1 ) ;
if ( V_184 < 0 ) {
V_183 = V_184 ;
goto V_194;
}
V_183 = F_82 ( & V_178 -> V_29 , V_184 ,
F_29 , 0 , L_26 , V_2 ) ;
if ( V_183 ) {
F_30 ( V_2 -> V_29 , L_28 ) ;
goto V_194;
}
V_2 -> V_184 = V_184 ;
}
F_8 ( V_2 , V_195 , V_193 ) ;
F_8 ( V_2 , ( 1 << V_52 ) - 1 , V_32 ) ;
F_8 ( V_2 , ( 1 << V_52 ) - 1 , V_33 ) ;
F_60 ( & V_2 -> V_175 . V_196 ) ;
F_83 ( V_197 , V_2 -> V_175 . V_176 ) ;
F_83 ( V_198 , V_2 -> V_175 . V_176 ) ;
F_83 ( V_199 , V_2 -> V_175 . V_176 ) ;
F_83 ( V_200 , V_2 -> V_175 . V_176 ) ;
for ( V_44 = 0 ; V_44 < V_63 ; V_44 ++ )
V_2 -> V_64 [ V_44 ] . V_65 = 0 ;
F_84 ( & V_2 -> V_58 ) ;
for ( V_44 = 0 ; V_44 < V_52 ; V_44 ++ ) {
struct V_6 * V_9 = & V_2 -> V_28 [ V_44 ] ;
if ( ! F_1 ( V_2 ) ) {
V_183 = F_82 ( & V_178 -> V_29 , V_41 + V_44 ,
F_36 , 0 , L_26 , V_2 ) ;
if ( V_183 ) {
F_30 ( V_2 -> V_29 , L_29
L_30 ,
V_41 + V_44 , V_44 ) ;
goto V_194;
}
V_9 -> V_41 = V_41 + V_44 ;
F_85 ( & V_9 -> V_38 ) ;
V_9 -> V_38 . V_201 = & F_27 ;
V_9 -> V_38 . V_39 = ( unsigned long ) V_9 ;
}
V_9 -> V_2 = V_2 ;
F_60 ( & V_9 -> V_97 ) ;
F_60 ( & V_9 -> V_96 ) ;
F_60 ( & V_9 -> V_12 ) ;
F_86 ( & V_9 -> V_40 , F_39 ,
( unsigned long ) V_9 ) ;
V_9 -> V_8 . V_167 = & V_2 -> V_175 ;
F_87 ( & V_9 -> V_8 ) ;
V_9 -> V_28 = V_44 ;
F_56 ( & V_9 -> V_8 . V_202 ,
& V_2 -> V_175 . V_196 ) ;
}
V_2 -> V_175 . V_29 = & V_178 -> V_29 ;
V_2 -> V_175 . V_203 = F_52 ;
V_2 -> V_175 . V_204 = F_57 ;
V_2 -> V_175 . V_205 = F_48 ;
V_2 -> V_175 . V_206 = F_61 ;
V_2 -> V_175 . V_207 = F_63 ;
V_2 -> V_175 . V_208 = F_66 ;
V_2 -> V_175 . V_209 = F_67 ;
V_2 -> V_175 . V_210 = F_45 ;
V_2 -> V_175 . V_211 = F_43 ;
V_2 -> V_175 . V_212 = F_68 ;
F_88 ( V_178 , V_2 ) ;
V_2 -> V_175 . V_213 = V_214 ;
V_2 -> V_175 . V_29 -> V_215 = & V_2 -> V_215 ;
F_89 ( V_2 -> V_175 . V_29 , 0xffffff ) ;
V_183 = F_90 ( & V_2 -> V_175 ) ;
if ( V_183 ) {
F_38 ( & V_178 -> V_29 , L_31 ) ;
goto V_194;
}
if ( V_178 -> V_29 . V_216 ) {
V_183 = F_91 ( V_178 -> V_29 . V_216 ,
F_70 , V_2 ) ;
if ( V_183 ) {
F_38 ( & V_178 -> V_29 , L_32 ) ;
goto V_217;
}
}
return 0 ;
V_217:
F_92 ( & V_2 -> V_175 ) ;
V_194:
F_93 ( V_2 -> V_190 ) ;
V_191:
F_93 ( V_2 -> V_189 ) ;
return V_183 ;
}
static void F_94 ( struct V_177 * V_178 , struct V_1 * V_2 )
{
int V_44 ;
if ( F_1 ( V_2 ) ) {
F_95 ( V_2 -> V_41 ) ;
F_95 ( V_2 -> V_184 ) ;
}
for ( V_44 = 0 ; V_44 < V_52 ; V_44 ++ ) {
struct V_6 * V_9 = & V_2 -> V_28 [ V_44 ] ;
if ( ! F_1 ( V_2 ) )
F_95 ( V_9 -> V_41 ) ;
F_96 ( & V_9 -> V_40 ) ;
}
}
static int F_97 ( struct V_177 * V_178 )
{
struct V_1 * V_2 = F_98 ( V_178 ) ;
F_94 ( V_178 , V_2 ) ;
F_92 ( & V_2 -> V_175 ) ;
if ( V_178 -> V_29 . V_216 )
F_99 ( V_178 -> V_29 . V_216 ) ;
F_93 ( V_2 -> V_189 ) ;
F_93 ( V_2 -> V_190 ) ;
return 0 ;
}
static int T_6 F_100 ( void )
{
return F_101 ( & V_218 , F_72 ) ;
}
