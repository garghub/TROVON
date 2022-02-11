static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_4 ;
}
static inline int F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_5 ;
}
static inline int F_3 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_6 ;
}
static struct V_7 * F_4 ( struct V_8 * V_9 )
{
return F_5 ( V_9 , struct V_7 , V_9 ) ;
}
static inline bool F_6 ( struct V_7 * V_10 )
{
struct V_11 * V_12 ;
if ( ! F_7 ( & V_10 -> V_13 ) ) {
V_12 = F_8 ( & V_10 -> V_13 , struct V_11 ,
V_14 ) ;
if ( V_12 -> type == V_15 )
return true ;
}
return false ;
}
static void F_9 ( struct V_1 * V_2 , unsigned V_16 ,
unsigned V_17 )
{
F_10 ( V_16 , V_2 -> V_18 + V_17 ) ;
}
static unsigned F_11 ( struct V_1 * V_2 , unsigned V_17 )
{
return F_12 ( V_2 -> V_18 + V_17 ) ;
}
static int F_13 ( struct V_7 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
if ( F_3 ( V_2 ) )
return V_10 -> V_19 ;
else
return 0 ;
}
static inline int F_14 ( struct V_11 * V_20 )
{
struct V_7 * V_10 = F_4 ( V_20 -> V_12 . V_9 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_21 * V_22 = V_20 -> V_22 ;
unsigned long V_23 ;
V_23 = F_15 ( V_20 -> V_24 , F_16 ( V_22 ) ) ;
if ( V_20 -> V_24 != V_25 )
V_20 -> V_24 -= V_23 ;
if ( V_20 -> V_26 == V_27 )
F_9 ( V_2 , V_22 -> V_28 ,
F_17 ( V_10 -> V_29 ) ) ;
else
F_9 ( V_2 , V_22 -> V_28 ,
F_18 ( V_10 -> V_29 ) ) ;
F_9 ( V_2 , V_23 , F_19 ( V_10 -> V_29 ) ) ;
F_20 ( V_2 -> V_30 , L_1
L_2 , V_31 , V_10 -> V_29 ,
F_11 ( V_2 , F_17 ( V_10 -> V_29 ) ) ,
F_11 ( V_2 , F_18 ( V_10 -> V_29 ) ) ,
F_11 ( V_2 , F_19 ( V_10 -> V_29 ) ) ) ;
return V_23 ;
}
static void F_21 ( struct V_11 * V_20 )
{
struct V_7 * V_10 = F_4 ( V_20 -> V_12 . V_9 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_29 = V_10 -> V_29 ;
unsigned long V_32 ;
F_20 ( V_2 -> V_30 , L_3 , V_31 , V_29 ) ;
F_22 ( V_32 ) ;
F_9 ( V_2 , 1 << V_29 , V_33 ) ;
F_9 ( V_2 , F_11 ( V_2 , V_34 ) &
~ ( 1 << V_29 ) , V_34 ) ;
F_9 ( V_2 , F_11 ( V_2 , F_23 ( V_29 ) ) |
V_35 | V_36 , F_23 ( V_29 ) ) ;
if ( ! F_1 ( V_2 ) &&
V_20 -> V_22 && F_13 ( V_10 ) ) {
V_20 -> V_22 = F_24 ( V_20 -> V_22 ) ;
if ( V_20 -> V_22 ) {
T_1 V_37 ;
F_14 ( V_20 ) ;
V_37 = F_11 ( V_2 , F_23 ( V_29 ) ) ;
F_9 ( V_2 , V_37 | V_38 | V_36 ,
F_23 ( V_29 ) ) ;
}
}
F_25 ( V_32 ) ;
}
static void F_26 ( struct V_7 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_29 = V_10 -> V_29 ;
unsigned long V_32 ;
F_20 ( V_2 -> V_30 , L_3 , V_31 , V_29 ) ;
if ( F_13 ( V_10 ) )
F_27 ( & V_10 -> V_39 ) ;
F_22 ( V_32 ) ;
F_9 ( V_2 , F_11 ( V_2 , V_34 ) |
( 1 << V_29 ) , V_34 ) ;
F_9 ( V_2 , F_11 ( V_2 , F_23 ( V_29 ) ) &
~ V_35 , F_23 ( V_29 ) ) ;
F_9 ( V_2 , 1 << V_29 , V_33 ) ;
F_25 ( V_32 ) ;
}
static void F_28 ( unsigned long V_40 )
{
struct V_7 * V_10 = (struct V_7 * ) V_40 ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_29 = V_10 -> V_29 ;
F_9 ( V_2 , 0 , F_23 ( V_29 ) ) ;
F_29 ( & V_10 -> V_41 ) ;
F_20 ( V_2 -> V_30 , L_4 ,
V_10 -> V_29 ) ;
}
static T_2 F_30 ( int V_42 , void * V_43 )
{
struct V_1 * V_2 = V_43 ;
unsigned int V_44 ;
int V_45 , V_46 ;
int V_47 ;
V_46 = F_11 ( V_2 , V_33 ) ;
V_44 = F_11 ( V_2 , V_48 ) |
F_11 ( V_2 , V_49 ) |
F_11 ( V_2 , V_50 ) |
F_11 ( V_2 , V_51 ) ;
if ( ! V_44 )
return V_52 ;
F_9 ( V_2 , V_46 & V_44 , V_33 ) ;
for ( V_45 = 0 ; V_45 < V_53 ; V_45 ++ ) {
if ( ! ( V_44 & ( 1 << V_45 ) ) )
continue;
V_47 = 0 ;
if ( F_11 ( V_2 , V_48 ) & ( 1 << V_45 ) ) {
F_9 ( V_2 , 1 << V_45 , V_48 ) ;
V_47 |= V_54 ;
}
if ( F_11 ( V_2 , V_49 ) & ( 1 << V_45 ) ) {
F_9 ( V_2 , 1 << V_45 , V_49 ) ;
V_47 |= V_55 ;
}
if ( F_11 ( V_2 , V_50 ) & ( 1 << V_45 ) ) {
F_9 ( V_2 , 1 << V_45 , V_50 ) ;
V_47 |= V_56 ;
}
if ( F_11 ( V_2 , V_51 ) & ( 1 << V_45 ) ) {
F_9 ( V_2 , 1 << V_45 , V_51 ) ;
V_47 |= V_57 ;
}
F_29 ( & V_2 -> V_29 [ V_45 ] . V_41 ) ;
F_31 ( V_2 -> V_30 ,
L_5 , V_45 ,
V_47 & V_54 ? L_6 : L_7 ,
V_47 & V_55 ? L_8 : L_7 ,
V_47 & V_56 ? L_9 : L_7 ,
V_47 & V_57 ? L_10 : L_7 ) ;
}
return V_52 ;
}
static void F_32 ( struct V_7 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_58 = V_10 -> V_29 ;
struct V_11 * V_12 ;
unsigned long V_32 ;
F_33 ( & V_2 -> V_59 , V_32 ) ;
if ( F_7 ( & V_10 -> V_13 ) ) {
F_34 ( & V_2 -> V_59 , V_32 ) ;
goto V_60;
}
V_12 = F_8 ( & V_10 -> V_13 ,
struct V_11 ,
V_14 ) ;
F_34 ( & V_2 -> V_59 , V_32 ) ;
if ( V_12 -> V_22 ) {
T_1 V_37 ;
V_12 -> V_22 = F_24 ( V_12 -> V_22 ) ;
if ( V_12 -> V_22 ) {
F_14 ( V_12 ) ;
V_37 = F_11 ( V_2 , F_23 ( V_58 ) ) ;
if ( F_13 ( V_10 ) ) {
F_35 ( & V_10 -> V_39 ,
V_61 + F_36 ( 500 ) ) ;
V_37 |= V_35 | V_38 | V_36 ;
F_9 ( V_2 , V_37 , F_23 ( V_58 ) ) ;
} else {
F_9 ( V_2 , V_37 & ~ V_35 ,
F_23 ( V_58 ) ) ;
V_37 |= V_35 ;
}
F_9 ( V_2 , V_37 , F_23 ( V_58 ) ) ;
if ( F_6 ( V_10 ) )
F_29 ( & V_10 -> V_41 ) ;
return;
}
if ( F_13 ( V_10 ) ) {
F_27 ( & V_10 -> V_39 ) ;
return;
}
}
V_60:
F_9 ( V_2 , 0 , F_23 ( V_58 ) ) ;
F_29 ( & V_10 -> V_41 ) ;
}
static T_2 F_37 ( int V_42 , void * V_43 )
{
struct V_1 * V_2 = V_43 ;
int V_45 , V_46 ;
if ( ! F_1 ( V_2 ) )
F_30 ( V_42 , V_43 ) ;
V_46 = F_11 ( V_2 , V_33 ) ;
F_20 ( V_2 -> V_30 , L_11 , V_31 , V_46 ) ;
F_9 ( V_2 , V_46 , V_33 ) ;
for ( V_45 = 0 ; V_45 < V_53 ; V_45 ++ ) {
if ( V_46 & ( 1 << V_45 ) )
F_32 ( & V_2 -> V_29 [ V_45 ] ) ;
}
return V_52 ;
}
static int F_38 ( struct V_11 * V_20 )
{
struct V_7 * V_10 = F_4 ( V_20 -> V_12 . V_9 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_62 = - 1 ;
int V_45 ;
switch ( V_20 -> type ) {
case V_63 :
for ( V_45 = 0 ; V_45 < V_64 ; V_45 ++ ) {
if ( ( V_2 -> V_65 [ V_45 ] . V_66 > 0 ) &&
( ( V_2 -> V_65 [ V_45 ] . V_67 != V_20 -> V_68 ) ||
( V_2 -> V_65 [ V_45 ] . V_69 != V_20 -> V_70 ) ||
( V_2 -> V_65 [ V_45 ] . V_71 != V_20 -> V_72 ) ) )
continue;
V_62 = V_45 ;
break;
}
if ( V_62 < 0 )
return - V_73 ;
V_2 -> V_65 [ V_62 ] . V_67 = V_20 -> V_68 ;
V_2 -> V_65 [ V_62 ] . V_69 = V_20 -> V_70 ;
V_2 -> V_65 [ V_62 ] . V_71 = V_20 -> V_72 ;
V_2 -> V_65 [ V_62 ] . V_66 ++ ;
V_10 -> V_74 = V_62 ;
V_10 -> V_75 = true ;
if ( V_62 == V_76 ) {
V_20 -> V_77 &= ~ V_78 ;
V_20 -> V_79 &= ~ V_78 ;
F_9 ( V_2 , V_20 -> V_68 , V_80 ) ;
F_9 ( V_2 , V_20 -> V_70 , V_81 ) ;
F_9 ( V_2 , V_20 -> V_72 , V_82 ) ;
} else {
V_20 -> V_77 |= V_78 ;
V_20 -> V_79 |= V_78 ;
F_9 ( V_2 , V_20 -> V_68 , V_83 ) ;
F_9 ( V_2 , V_20 -> V_70 , V_84 ) ;
F_9 ( V_2 , V_20 -> V_72 , V_85 ) ;
}
case V_86 :
F_9 ( V_2 , V_20 -> V_87 , F_18 ( V_10 -> V_29 ) ) ;
F_9 ( V_2 , V_20 -> V_88 , F_17 ( V_10 -> V_29 ) ) ;
F_9 ( V_2 , V_20 -> V_77 | ( V_20 -> V_79 << 2 ) ,
F_23 ( V_10 -> V_29 ) ) ;
F_9 ( V_2 , V_20 -> V_24 , F_19 ( V_10 -> V_29 ) ) ;
F_20 ( V_2 -> V_30 ,
L_12 ,
V_31 , V_10 -> V_29 ,
( unsigned long long ) V_20 -> V_88 ,
( unsigned long long ) V_20 -> V_87 , V_20 -> V_24 ) ;
break;
case V_15 :
case V_89 :
if ( V_20 -> V_26 == V_27 ) {
F_9 ( V_2 , V_10 -> V_90 ,
F_18 ( V_10 -> V_29 ) ) ;
F_9 ( V_2 , V_10 -> V_91 ,
F_23 ( V_10 -> V_29 ) ) ;
F_20 ( V_2 -> V_30 ,
L_13 ,
V_31 , V_10 -> V_29 ,
V_20 -> V_22 , V_20 -> V_92 , V_20 -> V_24 ,
( unsigned long long ) V_10 -> V_90 ) ;
} else if ( V_20 -> V_26 == V_93 ) {
F_9 ( V_2 , V_10 -> V_90 ,
F_17 ( V_10 -> V_29 ) ) ;
F_9 ( V_2 , V_10 -> V_94 ,
F_23 ( V_10 -> V_29 ) ) ;
F_20 ( V_2 -> V_30 ,
L_14 ,
V_31 , V_10 -> V_29 ,
V_20 -> V_22 , V_20 -> V_92 , V_20 -> V_24 ,
( unsigned long long ) V_10 -> V_90 ) ;
} else {
F_39 ( V_2 -> V_30 , L_15 ,
V_31 , V_10 -> V_29 ) ;
return - V_95 ;
}
F_14 ( V_20 ) ;
break;
default:
return - V_95 ;
}
F_21 ( V_20 ) ;
return 0 ;
}
static void F_40 ( unsigned long V_40 )
{
struct V_7 * V_10 = ( void * ) V_40 ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_11 * V_12 ;
unsigned long V_32 ;
F_33 ( & V_2 -> V_59 , V_32 ) ;
if ( F_7 ( & V_10 -> V_13 ) ) {
F_34 ( & V_2 -> V_59 , V_32 ) ;
return;
}
V_12 = F_8 ( & V_10 -> V_13 , struct V_11 , V_14 ) ;
if ( F_6 ( V_10 ) )
goto V_60;
else
F_41 ( & V_12 -> V_12 ) ;
if ( V_10 -> V_75 ) {
V_2 -> V_65 [ V_10 -> V_74 ] . V_66 -- ;
V_10 -> V_75 = false ;
}
F_42 ( V_10 -> V_13 . V_96 , & V_10 -> V_97 ) ;
if ( ! F_7 ( & V_10 -> V_98 ) ) {
V_12 = F_8 ( & V_10 -> V_98 , struct V_11 ,
V_14 ) ;
F_42 ( V_10 -> V_98 . V_96 , & V_10 -> V_13 ) ;
if ( F_38 ( V_12 ) < 0 )
F_31 ( V_2 -> V_30 , L_16 ,
V_31 , V_10 -> V_29 ) ;
}
V_60:
F_34 ( & V_2 -> V_59 , V_32 ) ;
if ( V_12 -> V_12 . V_99 )
V_12 -> V_12 . V_99 ( V_12 -> V_12 . V_100 ) ;
}
static int F_43 ( struct V_8 * V_9 , enum V_101 V_102 ,
unsigned long V_103 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_104 * V_105 = ( void * ) V_103 ;
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned long V_32 ;
unsigned int V_106 = 0 ;
switch ( V_102 ) {
case V_107 :
F_26 ( V_10 ) ;
F_33 ( & V_2 -> V_59 , V_32 ) ;
F_44 ( & V_10 -> V_13 , & V_10 -> V_97 ) ;
F_44 ( & V_10 -> V_98 , & V_10 -> V_97 ) ;
F_34 ( & V_2 -> V_59 , V_32 ) ;
return 0 ;
case V_108 :
if ( V_105 -> V_26 == V_27 ) {
V_10 -> V_90 = V_105 -> V_109 ;
V_10 -> V_110 = V_105 -> V_111 ;
V_10 -> V_112 = V_105 -> V_113 ;
} else {
V_10 -> V_90 = V_105 -> V_114 ;
V_10 -> V_110 = V_105 -> V_115 ;
V_10 -> V_112 = V_105 -> V_116 ;
}
switch ( V_10 -> V_112 ) {
case V_117 :
V_106 = V_118 ;
break;
case V_119 :
V_106 = V_120 ;
break;
default:
case V_121 :
V_106 = V_122 ;
break;
}
V_10 -> V_19 = 0 ;
V_10 -> V_91 = ( V_106 | V_123 ) |
( ( V_122 | V_124 ) << 2 ) |
V_125 ;
V_10 -> V_94 =
( V_122 | V_124 ) |
( ( V_106 | V_123 ) << 2 ) | V_125 ;
F_9 ( V_2 , V_10 -> V_126 ,
F_45 ( V_10 -> V_29 ) ) ;
F_9 ( V_2 , V_10 -> V_110 *
V_10 -> V_112 , F_46 ( V_10 -> V_29 ) ) ;
return 0 ;
default:
return - V_127 ;
}
return - V_95 ;
}
static enum V_128 F_47 ( struct V_8 * V_9 ,
T_3 V_129 ,
struct V_130 * V_131 )
{
return F_48 ( V_9 , V_129 , V_131 ) ;
}
static T_3 F_49 ( struct V_132 * V_133 )
{
struct V_7 * V_10 = F_4 ( V_133 -> V_9 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
T_3 V_129 ;
unsigned long V_32 ;
F_33 ( & V_2 -> V_59 , V_32 ) ;
F_42 ( V_10 -> V_97 . V_96 , & V_10 -> V_98 ) ;
V_129 = F_50 ( V_133 ) ;
F_34 ( & V_2 -> V_59 , V_32 ) ;
return V_129 ;
}
static int F_51 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_134 * V_40 = V_9 -> V_135 ;
if ( V_40 != NULL )
V_10 -> V_126 = V_40 -> V_126 ;
while ( V_10 -> V_136 < V_137 ) {
struct V_11 * V_12 ;
V_12 = F_52 ( sizeof( * V_12 ) , V_138 ) ;
if ( ! V_12 )
break;
F_53 ( & V_12 -> V_12 , sizeof( struct V_132 ) ) ;
F_54 ( & V_12 -> V_12 , V_9 ) ;
V_12 -> V_12 . V_139 = F_49 ;
V_12 -> V_12 . V_32 = V_140 ;
V_12 -> V_141 = V_142 ;
F_55 ( & V_12 -> V_14 , & V_10 -> V_97 ) ;
V_10 -> V_136 ++ ;
}
if ( ! V_10 -> V_136 )
return - V_143 ;
return V_10 -> V_136 ;
}
static void F_56 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_11 * V_12 , * V_144 ;
unsigned long V_32 ;
F_33 ( & V_2 -> V_59 , V_32 ) ;
F_26 ( V_10 ) ;
F_44 ( & V_10 -> V_13 , & V_10 -> V_97 ) ;
F_44 ( & V_10 -> V_98 , & V_10 -> V_97 ) ;
F_34 ( & V_2 -> V_59 , V_32 ) ;
F_57 (desc, _desc, &imxdmac->ld_free, node) {
F_58 ( V_12 ) ;
V_10 -> V_136 -- ;
}
F_59 ( & V_10 -> V_97 ) ;
F_58 ( V_10 -> V_145 ) ;
V_10 -> V_145 = NULL ;
}
static struct V_132 * F_60 (
struct V_8 * V_9 , struct V_21 * V_146 ,
unsigned int V_147 , enum V_148 V_26 ,
unsigned long V_32 , void * V_149 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_21 * V_22 ;
int V_45 , V_150 = 0 ;
struct V_11 * V_12 ;
if ( F_7 ( & V_10 -> V_97 ) ||
F_6 ( V_10 ) )
return NULL ;
V_12 = F_8 ( & V_10 -> V_97 , struct V_11 , V_14 ) ;
F_61 (sgl, sg, sg_len, i) {
V_150 += F_16 ( V_22 ) ;
}
switch ( V_10 -> V_112 ) {
case V_121 :
if ( F_16 ( V_146 ) & 3 || V_146 -> V_28 & 3 )
return NULL ;
break;
case V_119 :
if ( F_16 ( V_146 ) & 1 || V_146 -> V_28 & 1 )
return NULL ;
break;
case V_117 :
break;
default:
return NULL ;
}
V_12 -> type = V_89 ;
V_12 -> V_22 = V_146 ;
V_12 -> V_92 = V_147 ;
V_12 -> V_24 = V_150 ;
V_12 -> V_26 = V_26 ;
if ( V_26 == V_27 ) {
V_12 -> V_87 = V_10 -> V_90 ;
} else {
V_12 -> V_88 = V_10 -> V_90 ;
}
V_12 -> V_12 . V_99 = NULL ;
V_12 -> V_12 . V_100 = NULL ;
return & V_12 -> V_12 ;
}
static struct V_132 * F_62 (
struct V_8 * V_9 , T_4 V_151 , T_5 V_152 ,
T_5 V_153 , enum V_148 V_26 ,
unsigned long V_32 , void * V_149 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_11 * V_12 ;
int V_45 ;
unsigned int V_154 = V_152 / V_153 ;
F_20 ( V_2 -> V_30 , L_17 ,
V_31 , V_10 -> V_29 , V_152 , V_153 ) ;
if ( F_7 ( & V_10 -> V_97 ) ||
F_6 ( V_10 ) )
return NULL ;
V_12 = F_8 ( & V_10 -> V_97 , struct V_11 , V_14 ) ;
F_58 ( V_10 -> V_145 ) ;
V_10 -> V_145 = F_63 ( V_154 + 1 ,
sizeof( struct V_21 ) , V_155 ) ;
if ( ! V_10 -> V_145 )
return NULL ;
F_64 ( V_10 -> V_145 , V_154 ) ;
for ( V_45 = 0 ; V_45 < V_154 ; V_45 ++ ) {
V_10 -> V_145 [ V_45 ] . V_156 = 0 ;
V_10 -> V_145 [ V_45 ] . V_17 = 0 ;
V_10 -> V_145 [ V_45 ] . V_28 = V_151 ;
F_16 ( & V_10 -> V_145 [ V_45 ] ) = V_153 ;
V_151 += V_153 ;
}
V_10 -> V_145 [ V_154 ] . V_17 = 0 ;
F_16 ( & V_10 -> V_145 [ V_154 ] ) = 0 ;
V_10 -> V_145 [ V_154 ] . V_156 =
( ( unsigned long ) V_10 -> V_145 | 0x01 ) & ~ 0x02 ;
V_12 -> type = V_15 ;
V_12 -> V_22 = V_10 -> V_145 ;
V_12 -> V_92 = V_154 ;
V_12 -> V_24 = V_25 ;
V_12 -> V_26 = V_26 ;
if ( V_26 == V_27 ) {
V_12 -> V_87 = V_10 -> V_90 ;
} else {
V_12 -> V_88 = V_10 -> V_90 ;
}
V_12 -> V_12 . V_99 = NULL ;
V_12 -> V_12 . V_100 = NULL ;
return & V_12 -> V_12 ;
}
static struct V_132 * F_65 (
struct V_8 * V_9 , T_4 V_88 ,
T_4 V_87 , T_5 V_24 , unsigned long V_32 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_11 * V_12 ;
F_20 ( V_2 -> V_30 , L_18 ,
V_31 , V_10 -> V_29 , ( unsigned long long ) V_87 ,
( unsigned long long ) V_88 , V_24 ) ;
if ( F_7 ( & V_10 -> V_97 ) ||
F_6 ( V_10 ) )
return NULL ;
V_12 = F_8 ( & V_10 -> V_97 , struct V_11 , V_14 ) ;
V_12 -> type = V_86 ;
V_12 -> V_87 = V_87 ;
V_12 -> V_88 = V_88 ;
V_12 -> V_24 = V_24 ;
V_12 -> V_26 = V_157 ;
V_12 -> V_79 = V_122 | V_124 ;
V_12 -> V_77 = V_122 | V_124 ;
V_12 -> V_12 . V_99 = NULL ;
V_12 -> V_12 . V_100 = NULL ;
return & V_12 -> V_12 ;
}
static struct V_132 * F_66 (
struct V_8 * V_9 , struct V_158 * V_159 ,
unsigned long V_32 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_11 * V_12 ;
F_20 ( V_2 -> V_30 , L_19
L_20 , V_31 ,
V_10 -> V_29 , ( unsigned long long ) V_159 -> V_160 ,
( unsigned long long ) V_159 -> V_161 ,
V_159 -> V_162 ? L_21 : L_22 , V_159 -> V_163 ? L_21 : L_22 ,
V_159 -> V_164 , V_159 -> V_165 ) ;
if ( F_7 ( & V_10 -> V_97 ) ||
F_6 ( V_10 ) )
return NULL ;
if ( V_159 -> V_165 != 1 || V_159 -> V_164 <= 0 || V_159 -> V_166 != V_157 )
return NULL ;
V_12 = F_8 ( & V_10 -> V_97 , struct V_11 , V_14 ) ;
V_12 -> type = V_63 ;
V_12 -> V_87 = V_159 -> V_160 ;
V_12 -> V_88 = V_159 -> V_161 ;
V_12 -> V_68 = V_159 -> V_146 [ 0 ] . V_167 ;
V_12 -> V_70 = V_159 -> V_164 ;
V_12 -> V_72 = V_159 -> V_146 [ 0 ] . V_168 + V_12 -> V_68 ;
V_12 -> V_24 = V_12 -> V_68 * V_12 -> V_70 ;
V_12 -> V_26 = V_157 ;
V_12 -> V_79 = V_122 ;
V_12 -> V_77 = V_122 ;
if ( V_159 -> V_162 )
V_12 -> V_77 |= V_169 ;
if ( V_159 -> V_163 )
V_12 -> V_79 |= V_169 ;
V_12 -> V_12 . V_99 = NULL ;
V_12 -> V_12 . V_100 = NULL ;
return & V_12 -> V_12 ;
}
static void F_67 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_11 * V_12 ;
unsigned long V_32 ;
F_33 ( & V_2 -> V_59 , V_32 ) ;
if ( F_7 ( & V_10 -> V_13 ) &&
! F_7 ( & V_10 -> V_98 ) ) {
V_12 = F_8 ( & V_10 -> V_98 ,
struct V_11 , V_14 ) ;
if ( F_38 ( V_12 ) < 0 ) {
F_31 ( V_2 -> V_30 ,
L_23 ,
V_31 , V_10 -> V_29 ) ;
} else {
F_42 ( V_10 -> V_98 . V_96 ,
& V_10 -> V_13 ) ;
}
}
F_34 ( & V_2 -> V_59 , V_32 ) ;
}
static bool F_68 ( struct V_8 * V_9 , void * V_170 )
{
struct V_171 * V_172 = V_170 ;
struct V_7 * V_173 = F_4 ( V_9 ) ;
if ( V_9 -> V_174 -> V_30 != V_172 -> V_2 -> V_30 )
return false ;
V_173 -> V_126 = V_172 -> V_175 ;
V_9 -> V_135 = NULL ;
return true ;
}
static struct V_8 * F_69 ( struct V_176 * V_177 ,
struct V_178 * V_179 )
{
int V_66 = V_177 -> V_180 ;
struct V_1 * V_2 = V_179 -> V_181 ;
struct V_171 V_172 = {
. V_2 = V_2 ,
} ;
if ( V_66 != 1 )
return NULL ;
V_172 . V_175 = V_177 -> args [ 0 ] ;
return F_70 ( V_2 -> V_182 . V_183 ,
F_68 , & V_172 ) ;
}
static int T_6 F_71 ( struct V_184 * V_185 )
{
struct V_1 * V_2 ;
struct V_186 * V_187 ;
const struct V_188 * V_189 ;
int V_190 , V_45 ;
int V_42 , V_191 ;
V_189 = F_72 ( V_192 , & V_185 -> V_30 ) ;
if ( V_189 )
V_185 -> V_193 = V_189 -> V_40 ;
V_2 = F_73 ( & V_185 -> V_30 , sizeof( * V_2 ) , V_138 ) ;
if ( ! V_2 )
return - V_143 ;
V_2 -> V_30 = & V_185 -> V_30 ;
V_2 -> V_3 = V_185 -> V_193 -> V_194 ;
V_187 = F_74 ( V_185 , V_195 , 0 ) ;
V_2 -> V_18 = F_75 ( & V_185 -> V_30 , V_187 ) ;
if ( F_76 ( V_2 -> V_18 ) )
return F_77 ( V_2 -> V_18 ) ;
V_42 = F_78 ( V_185 , 0 ) ;
if ( V_42 < 0 )
return V_42 ;
V_2 -> V_196 = F_79 ( & V_185 -> V_30 , L_24 ) ;
if ( F_76 ( V_2 -> V_196 ) )
return F_77 ( V_2 -> V_196 ) ;
V_2 -> V_197 = F_79 ( & V_185 -> V_30 , L_25 ) ;
if ( F_76 ( V_2 -> V_197 ) )
return F_77 ( V_2 -> V_197 ) ;
F_80 ( V_2 -> V_196 ) ;
F_80 ( V_2 -> V_197 ) ;
F_9 ( V_2 , V_198 , V_199 ) ;
if ( F_1 ( V_2 ) ) {
V_190 = F_81 ( & V_185 -> V_30 , V_42 ,
F_37 , 0 , L_26 , V_2 ) ;
if ( V_190 ) {
F_31 ( V_2 -> V_30 , L_27 ) ;
goto V_200;
}
V_191 = F_78 ( V_185 , 1 ) ;
if ( V_191 < 0 ) {
V_190 = V_191 ;
goto V_200;
}
V_190 = F_81 ( & V_185 -> V_30 , V_191 ,
F_30 , 0 , L_26 , V_2 ) ;
if ( V_190 ) {
F_31 ( V_2 -> V_30 , L_28 ) ;
goto V_200;
}
}
F_9 ( V_2 , V_201 , V_199 ) ;
F_9 ( V_2 , ( 1 << V_53 ) - 1 , V_33 ) ;
F_9 ( V_2 , ( 1 << V_53 ) - 1 , V_34 ) ;
F_59 ( & V_2 -> V_182 . V_202 ) ;
F_82 ( V_203 , V_2 -> V_182 . V_183 ) ;
F_82 ( V_204 , V_2 -> V_182 . V_183 ) ;
F_82 ( V_205 , V_2 -> V_182 . V_183 ) ;
F_82 ( V_206 , V_2 -> V_182 . V_183 ) ;
for ( V_45 = 0 ; V_45 < V_64 ; V_45 ++ )
V_2 -> V_65 [ V_45 ] . V_66 = 0 ;
F_83 ( & V_2 -> V_59 ) ;
for ( V_45 = 0 ; V_45 < V_53 ; V_45 ++ ) {
struct V_7 * V_10 = & V_2 -> V_29 [ V_45 ] ;
if ( ! F_1 ( V_2 ) ) {
V_190 = F_81 ( & V_185 -> V_30 , V_42 + V_45 ,
F_37 , 0 , L_26 , V_2 ) ;
if ( V_190 ) {
F_31 ( V_2 -> V_30 , L_29
L_30 ,
V_42 + V_45 , V_45 ) ;
goto V_200;
}
F_84 ( & V_10 -> V_39 ) ;
V_10 -> V_39 . V_207 = & F_28 ;
V_10 -> V_39 . V_40 = ( unsigned long ) V_10 ;
}
V_10 -> V_2 = V_2 ;
F_59 ( & V_10 -> V_98 ) ;
F_59 ( & V_10 -> V_97 ) ;
F_59 ( & V_10 -> V_13 ) ;
F_85 ( & V_10 -> V_41 , F_40 ,
( unsigned long ) V_10 ) ;
V_10 -> V_9 . V_174 = & V_2 -> V_182 ;
F_86 ( & V_10 -> V_9 ) ;
V_10 -> V_29 = V_45 ;
F_55 ( & V_10 -> V_9 . V_208 ,
& V_2 -> V_182 . V_202 ) ;
}
V_2 -> V_182 . V_30 = & V_185 -> V_30 ;
V_2 -> V_182 . V_209 = F_51 ;
V_2 -> V_182 . V_210 = F_56 ;
V_2 -> V_182 . V_211 = F_47 ;
V_2 -> V_182 . V_212 = F_60 ;
V_2 -> V_182 . V_213 = F_62 ;
V_2 -> V_182 . V_214 = F_65 ;
V_2 -> V_182 . V_215 = F_66 ;
V_2 -> V_182 . V_216 = F_43 ;
V_2 -> V_182 . V_217 = F_67 ;
F_87 ( V_185 , V_2 ) ;
V_2 -> V_182 . V_218 = 2 ;
V_2 -> V_182 . V_30 -> V_219 = & V_2 -> V_219 ;
F_88 ( V_2 -> V_182 . V_30 , 0xffffff ) ;
V_190 = F_89 ( & V_2 -> V_182 ) ;
if ( V_190 ) {
F_39 ( & V_185 -> V_30 , L_31 ) ;
goto V_200;
}
if ( V_185 -> V_30 . V_220 ) {
V_190 = F_90 ( V_185 -> V_30 . V_220 ,
F_69 , V_2 ) ;
if ( V_190 ) {
F_39 ( & V_185 -> V_30 , L_32 ) ;
goto V_221;
}
}
return 0 ;
V_221:
F_91 ( & V_2 -> V_182 ) ;
V_200:
F_92 ( V_2 -> V_196 ) ;
F_92 ( V_2 -> V_197 ) ;
return V_190 ;
}
static int F_93 ( struct V_184 * V_185 )
{
struct V_1 * V_2 = F_94 ( V_185 ) ;
F_91 ( & V_2 -> V_182 ) ;
if ( V_185 -> V_30 . V_220 )
F_95 ( V_185 -> V_30 . V_220 ) ;
F_92 ( V_2 -> V_196 ) ;
F_92 ( V_2 -> V_197 ) ;
return 0 ;
}
static int T_6 F_96 ( void )
{
return F_97 ( & V_222 , F_71 ) ;
}
