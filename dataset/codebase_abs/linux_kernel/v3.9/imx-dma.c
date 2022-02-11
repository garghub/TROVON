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
F_31 ( V_58
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
int V_59 = V_10 -> V_29 ;
struct V_11 * V_12 ;
F_33 ( & V_2 -> V_60 ) ;
if ( F_7 ( & V_10 -> V_13 ) ) {
F_34 ( & V_2 -> V_60 ) ;
goto V_61;
}
V_12 = F_8 ( & V_10 -> V_13 ,
struct V_11 ,
V_14 ) ;
F_34 ( & V_2 -> V_60 ) ;
if ( V_12 -> V_22 ) {
T_1 V_37 ;
V_12 -> V_22 = F_24 ( V_12 -> V_22 ) ;
if ( V_12 -> V_22 ) {
F_14 ( V_12 ) ;
V_37 = F_11 ( V_2 , F_23 ( V_59 ) ) ;
if ( F_13 ( V_10 ) ) {
F_35 ( & V_10 -> V_39 ,
V_62 + F_36 ( 500 ) ) ;
V_37 |= V_35 | V_38 | V_36 ;
F_9 ( V_2 , V_37 , F_23 ( V_59 ) ) ;
} else {
F_9 ( V_2 , V_37 & ~ V_35 ,
F_23 ( V_59 ) ) ;
V_37 |= V_35 ;
}
F_9 ( V_2 , V_37 , F_23 ( V_59 ) ) ;
if ( F_6 ( V_10 ) )
F_29 ( & V_10 -> V_41 ) ;
return;
}
if ( F_13 ( V_10 ) ) {
F_27 ( & V_10 -> V_39 ) ;
return;
}
}
V_61:
F_9 ( V_2 , 0 , F_23 ( V_59 ) ) ;
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
unsigned long V_32 ;
int V_63 = - 1 ;
int V_45 ;
switch ( V_20 -> type ) {
case V_64 :
F_39 ( & V_2 -> V_60 , V_32 ) ;
for ( V_45 = 0 ; V_45 < V_65 ; V_45 ++ ) {
if ( ( V_2 -> V_66 [ V_45 ] . V_67 > 0 ) &&
( ( V_2 -> V_66 [ V_45 ] . V_68 != V_20 -> V_69 ) ||
( V_2 -> V_66 [ V_45 ] . V_70 != V_20 -> V_71 ) ||
( V_2 -> V_66 [ V_45 ] . V_72 != V_20 -> V_73 ) ) )
continue;
V_63 = V_45 ;
break;
}
if ( V_63 < 0 ) {
F_40 ( & V_2 -> V_60 , V_32 ) ;
return - V_74 ;
}
V_2 -> V_66 [ V_63 ] . V_68 = V_20 -> V_69 ;
V_2 -> V_66 [ V_63 ] . V_70 = V_20 -> V_71 ;
V_2 -> V_66 [ V_63 ] . V_72 = V_20 -> V_73 ;
V_2 -> V_66 [ V_63 ] . V_67 ++ ;
V_10 -> V_75 = V_63 ;
V_10 -> V_76 = true ;
F_40 ( & V_2 -> V_60 , V_32 ) ;
if ( V_63 == V_77 ) {
V_20 -> V_78 &= ~ V_79 ;
V_20 -> V_80 &= ~ V_79 ;
F_9 ( V_2 , V_20 -> V_69 , V_81 ) ;
F_9 ( V_2 , V_20 -> V_71 , V_82 ) ;
F_9 ( V_2 , V_20 -> V_73 , V_83 ) ;
} else {
V_20 -> V_78 |= V_79 ;
V_20 -> V_80 |= V_79 ;
F_9 ( V_2 , V_20 -> V_69 , V_84 ) ;
F_9 ( V_2 , V_20 -> V_71 , V_85 ) ;
F_9 ( V_2 , V_20 -> V_73 , V_86 ) ;
}
case V_87 :
F_9 ( V_2 , V_20 -> V_88 , F_18 ( V_10 -> V_29 ) ) ;
F_9 ( V_2 , V_20 -> V_89 , F_17 ( V_10 -> V_29 ) ) ;
F_9 ( V_2 , V_20 -> V_78 | ( V_20 -> V_80 << 2 ) ,
F_23 ( V_10 -> V_29 ) ) ;
F_9 ( V_2 , V_20 -> V_24 , F_19 ( V_10 -> V_29 ) ) ;
F_20 ( V_2 -> V_30 , L_12
L_13 , V_31 , V_10 -> V_29 ,
V_20 -> V_89 , V_20 -> V_88 , V_20 -> V_24 ) ;
break;
case V_15 :
case V_90 :
if ( V_20 -> V_26 == V_27 ) {
F_9 ( V_2 , V_10 -> V_91 ,
F_18 ( V_10 -> V_29 ) ) ;
F_9 ( V_2 , V_10 -> V_92 ,
F_23 ( V_10 -> V_29 ) ) ;
F_20 ( V_2 -> V_30 , L_14
L_15 ,
V_31 , V_10 -> V_29 , V_20 -> V_22 , V_20 -> V_93 ,
V_20 -> V_24 , V_10 -> V_91 ) ;
} else if ( V_20 -> V_26 == V_94 ) {
F_9 ( V_2 , V_10 -> V_91 ,
F_17 ( V_10 -> V_29 ) ) ;
F_9 ( V_2 , V_10 -> V_95 ,
F_23 ( V_10 -> V_29 ) ) ;
F_20 ( V_2 -> V_30 , L_14
L_16 ,
V_31 , V_10 -> V_29 , V_20 -> V_22 , V_20 -> V_93 ,
V_20 -> V_24 , V_10 -> V_91 ) ;
} else {
F_41 ( V_2 -> V_30 , L_17 ,
V_31 , V_10 -> V_29 ) ;
return - V_96 ;
}
F_14 ( V_20 ) ;
break;
default:
return - V_96 ;
}
F_21 ( V_20 ) ;
return 0 ;
}
static void F_42 ( unsigned long V_40 )
{
struct V_7 * V_10 = ( void * ) V_40 ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_11 * V_12 ;
F_33 ( & V_2 -> V_60 ) ;
if ( F_7 ( & V_10 -> V_13 ) ) {
goto V_61;
}
V_12 = F_8 ( & V_10 -> V_13 , struct V_11 , V_14 ) ;
if ( V_12 -> V_12 . V_97 )
V_12 -> V_12 . V_97 ( V_12 -> V_12 . V_98 ) ;
if ( F_6 ( V_10 ) )
goto V_61;
else
F_43 ( & V_12 -> V_12 ) ;
if ( V_10 -> V_76 ) {
V_2 -> V_66 [ V_10 -> V_75 ] . V_67 -- ;
V_10 -> V_76 = false ;
}
F_44 ( V_10 -> V_13 . V_99 , & V_10 -> V_100 ) ;
if ( ! F_7 ( & V_10 -> V_101 ) ) {
V_12 = F_8 ( & V_10 -> V_101 , struct V_11 ,
V_14 ) ;
F_44 ( V_10 -> V_101 . V_99 , & V_10 -> V_13 ) ;
if ( F_38 ( V_12 ) < 0 )
F_45 ( V_2 -> V_30 , L_18 ,
V_31 , V_10 -> V_29 ) ;
}
V_61:
F_34 ( & V_2 -> V_60 ) ;
}
static int F_46 ( struct V_8 * V_9 , enum V_102 V_103 ,
unsigned long V_104 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_105 * V_106 = ( void * ) V_104 ;
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned long V_32 ;
unsigned int V_107 = 0 ;
switch ( V_103 ) {
case V_108 :
F_26 ( V_10 ) ;
F_39 ( & V_2 -> V_60 , V_32 ) ;
F_47 ( & V_10 -> V_13 , & V_10 -> V_100 ) ;
F_47 ( & V_10 -> V_101 , & V_10 -> V_100 ) ;
F_40 ( & V_2 -> V_60 , V_32 ) ;
return 0 ;
case V_109 :
if ( V_106 -> V_26 == V_27 ) {
V_10 -> V_91 = V_106 -> V_110 ;
V_10 -> V_111 = V_106 -> V_112 ;
V_10 -> V_113 = V_106 -> V_114 ;
} else {
V_10 -> V_91 = V_106 -> V_115 ;
V_10 -> V_111 = V_106 -> V_116 ;
V_10 -> V_113 = V_106 -> V_117 ;
}
switch ( V_10 -> V_113 ) {
case V_118 :
V_107 = V_119 ;
break;
case V_120 :
V_107 = V_121 ;
break;
default:
case V_122 :
V_107 = V_123 ;
break;
}
V_10 -> V_19 = 0 ;
V_10 -> V_92 = ( V_107 | V_124 ) |
( ( V_123 | V_125 ) << 2 ) |
V_126 ;
V_10 -> V_95 =
( V_123 | V_125 ) |
( ( V_107 | V_124 ) << 2 ) | V_126 ;
F_9 ( V_2 , V_10 -> V_127 ,
F_48 ( V_10 -> V_29 ) ) ;
F_9 ( V_2 , V_10 -> V_111 *
V_10 -> V_113 , F_49 ( V_10 -> V_29 ) ) ;
return 0 ;
default:
return - V_128 ;
}
return - V_96 ;
}
static enum V_129 F_50 ( struct V_8 * V_9 ,
T_3 V_130 ,
struct V_131 * V_132 )
{
return F_51 ( V_9 , V_130 , V_132 ) ;
}
static T_3 F_52 ( struct V_133 * V_134 )
{
struct V_7 * V_10 = F_4 ( V_134 -> V_9 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
T_3 V_130 ;
unsigned long V_32 ;
F_39 ( & V_2 -> V_60 , V_32 ) ;
F_44 ( V_10 -> V_100 . V_99 , & V_10 -> V_101 ) ;
V_130 = F_53 ( V_134 ) ;
F_40 ( & V_2 -> V_60 , V_32 ) ;
return V_130 ;
}
static int F_54 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_135 * V_40 = V_9 -> V_136 ;
if ( V_40 != NULL )
V_10 -> V_127 = V_40 -> V_127 ;
while ( V_10 -> V_137 < V_138 ) {
struct V_11 * V_12 ;
V_12 = F_55 ( sizeof( * V_12 ) , V_139 ) ;
if ( ! V_12 )
break;
F_56 ( & V_12 -> V_12 , sizeof( struct V_133 ) ) ;
F_57 ( & V_12 -> V_12 , V_9 ) ;
V_12 -> V_12 . V_140 = F_52 ;
V_12 -> V_12 . V_32 = V_141 ;
V_12 -> V_142 = V_143 ;
F_58 ( & V_12 -> V_14 , & V_10 -> V_100 ) ;
V_10 -> V_137 ++ ;
}
if ( ! V_10 -> V_137 )
return - V_144 ;
return V_10 -> V_137 ;
}
static void F_59 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_11 * V_12 , * V_145 ;
unsigned long V_32 ;
F_39 ( & V_2 -> V_60 , V_32 ) ;
F_26 ( V_10 ) ;
F_47 ( & V_10 -> V_13 , & V_10 -> V_100 ) ;
F_47 ( & V_10 -> V_101 , & V_10 -> V_100 ) ;
F_40 ( & V_2 -> V_60 , V_32 ) ;
F_60 (desc, _desc, &imxdmac->ld_free, node) {
F_61 ( V_12 ) ;
V_10 -> V_137 -- ;
}
F_62 ( & V_10 -> V_100 ) ;
if ( V_10 -> V_146 ) {
F_61 ( V_10 -> V_146 ) ;
V_10 -> V_146 = NULL ;
}
}
static struct V_133 * F_63 (
struct V_8 * V_9 , struct V_21 * V_147 ,
unsigned int V_148 , enum V_149 V_26 ,
unsigned long V_32 , void * V_150 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_21 * V_22 ;
int V_45 , V_151 = 0 ;
struct V_11 * V_12 ;
if ( F_7 ( & V_10 -> V_100 ) ||
F_6 ( V_10 ) )
return NULL ;
V_12 = F_8 ( & V_10 -> V_100 , struct V_11 , V_14 ) ;
F_64 (sgl, sg, sg_len, i) {
V_151 += F_16 ( V_22 ) ;
}
switch ( V_10 -> V_113 ) {
case V_122 :
if ( F_16 ( V_147 ) & 3 || V_147 -> V_28 & 3 )
return NULL ;
break;
case V_120 :
if ( F_16 ( V_147 ) & 1 || V_147 -> V_28 & 1 )
return NULL ;
break;
case V_118 :
break;
default:
return NULL ;
}
V_12 -> type = V_90 ;
V_12 -> V_22 = V_147 ;
V_12 -> V_93 = V_148 ;
V_12 -> V_24 = V_151 ;
V_12 -> V_26 = V_26 ;
if ( V_26 == V_27 ) {
V_12 -> V_88 = V_10 -> V_91 ;
} else {
V_12 -> V_89 = V_10 -> V_91 ;
}
V_12 -> V_12 . V_97 = NULL ;
V_12 -> V_12 . V_98 = NULL ;
return & V_12 -> V_12 ;
}
static struct V_133 * F_65 (
struct V_8 * V_9 , T_4 V_152 , T_5 V_153 ,
T_5 V_154 , enum V_149 V_26 ,
unsigned long V_32 , void * V_150 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_11 * V_12 ;
int V_45 ;
unsigned int V_155 = V_153 / V_154 ;
F_20 ( V_2 -> V_30 , L_19 ,
V_31 , V_10 -> V_29 , V_153 , V_154 ) ;
if ( F_7 ( & V_10 -> V_100 ) ||
F_6 ( V_10 ) )
return NULL ;
V_12 = F_8 ( & V_10 -> V_100 , struct V_11 , V_14 ) ;
if ( V_10 -> V_146 )
F_61 ( V_10 -> V_146 ) ;
V_10 -> V_146 = F_66 ( V_155 + 1 ,
sizeof( struct V_21 ) , V_139 ) ;
if ( ! V_10 -> V_146 )
return NULL ;
F_67 ( V_10 -> V_146 , V_155 ) ;
for ( V_45 = 0 ; V_45 < V_155 ; V_45 ++ ) {
V_10 -> V_146 [ V_45 ] . V_156 = 0 ;
V_10 -> V_146 [ V_45 ] . V_17 = 0 ;
V_10 -> V_146 [ V_45 ] . V_28 = V_152 ;
F_16 ( & V_10 -> V_146 [ V_45 ] ) = V_154 ;
V_152 += V_154 ;
}
V_10 -> V_146 [ V_155 ] . V_17 = 0 ;
F_16 ( & V_10 -> V_146 [ V_155 ] ) = 0 ;
V_10 -> V_146 [ V_155 ] . V_156 =
( ( unsigned long ) V_10 -> V_146 | 0x01 ) & ~ 0x02 ;
V_12 -> type = V_15 ;
V_12 -> V_22 = V_10 -> V_146 ;
V_12 -> V_93 = V_155 ;
V_12 -> V_24 = V_25 ;
V_12 -> V_26 = V_26 ;
if ( V_26 == V_27 ) {
V_12 -> V_88 = V_10 -> V_91 ;
} else {
V_12 -> V_89 = V_10 -> V_91 ;
}
V_12 -> V_12 . V_97 = NULL ;
V_12 -> V_12 . V_98 = NULL ;
return & V_12 -> V_12 ;
}
static struct V_133 * F_68 (
struct V_8 * V_9 , T_4 V_89 ,
T_4 V_88 , T_5 V_24 , unsigned long V_32 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_11 * V_12 ;
F_20 ( V_2 -> V_30 , L_20 ,
V_31 , V_10 -> V_29 , V_88 , V_89 , V_24 ) ;
if ( F_7 ( & V_10 -> V_100 ) ||
F_6 ( V_10 ) )
return NULL ;
V_12 = F_8 ( & V_10 -> V_100 , struct V_11 , V_14 ) ;
V_12 -> type = V_87 ;
V_12 -> V_88 = V_88 ;
V_12 -> V_89 = V_89 ;
V_12 -> V_24 = V_24 ;
V_12 -> V_26 = V_157 ;
V_12 -> V_80 = V_123 | V_125 ;
V_12 -> V_78 = V_123 | V_125 ;
V_12 -> V_12 . V_97 = NULL ;
V_12 -> V_12 . V_98 = NULL ;
return & V_12 -> V_12 ;
}
static struct V_133 * F_69 (
struct V_8 * V_9 , struct V_158 * V_159 ,
unsigned long V_32 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_11 * V_12 ;
F_20 ( V_2 -> V_30 , L_21
L_22 , V_31 ,
V_10 -> V_29 , V_159 -> V_160 , V_159 -> V_161 ,
V_159 -> V_162 ? L_23 : L_24 , V_159 -> V_163 ? L_23 : L_24 ,
V_159 -> V_164 , V_159 -> V_165 ) ;
if ( F_7 ( & V_10 -> V_100 ) ||
F_6 ( V_10 ) )
return NULL ;
if ( V_159 -> V_165 != 1 || V_159 -> V_164 <= 0 || V_159 -> V_166 != V_157 )
return NULL ;
V_12 = F_8 ( & V_10 -> V_100 , struct V_11 , V_14 ) ;
V_12 -> type = V_64 ;
V_12 -> V_88 = V_159 -> V_160 ;
V_12 -> V_89 = V_159 -> V_161 ;
V_12 -> V_69 = V_159 -> V_147 [ 0 ] . V_167 ;
V_12 -> V_71 = V_159 -> V_164 ;
V_12 -> V_73 = V_159 -> V_147 [ 0 ] . V_168 + V_12 -> V_69 ;
V_12 -> V_24 = V_12 -> V_69 * V_12 -> V_71 ;
V_12 -> V_26 = V_157 ;
V_12 -> V_80 = V_123 ;
V_12 -> V_78 = V_123 ;
if ( V_159 -> V_162 )
V_12 -> V_78 |= V_169 ;
if ( V_159 -> V_163 )
V_12 -> V_80 |= V_169 ;
V_12 -> V_12 . V_97 = NULL ;
V_12 -> V_12 . V_98 = NULL ;
return & V_12 -> V_12 ;
}
static void F_70 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_4 ( V_9 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_11 * V_12 ;
unsigned long V_32 ;
F_39 ( & V_2 -> V_60 , V_32 ) ;
if ( F_7 ( & V_10 -> V_13 ) &&
! F_7 ( & V_10 -> V_101 ) ) {
V_12 = F_8 ( & V_10 -> V_101 ,
struct V_11 , V_14 ) ;
if ( F_38 ( V_12 ) < 0 ) {
F_45 ( V_2 -> V_30 ,
L_25 ,
V_31 , V_10 -> V_29 ) ;
} else {
F_44 ( V_10 -> V_101 . V_99 ,
& V_10 -> V_13 ) ;
}
}
F_40 ( & V_2 -> V_60 , V_32 ) ;
}
static int T_6 F_71 ( struct V_170 * V_171 )
{
struct V_1 * V_2 ;
struct V_172 * V_173 ;
int V_174 , V_45 ;
int V_42 , V_175 ;
V_2 = F_72 ( & V_171 -> V_30 , sizeof( * V_2 ) , V_139 ) ;
if ( ! V_2 )
return - V_144 ;
V_2 -> V_3 = V_171 -> V_176 -> V_177 ;
V_173 = F_73 ( V_171 , V_178 , 0 ) ;
V_2 -> V_18 = F_74 ( & V_171 -> V_30 , V_173 ) ;
if ( F_75 ( V_2 -> V_18 ) )
return F_76 ( V_2 -> V_18 ) ;
V_42 = F_77 ( V_171 , 0 ) ;
if ( V_42 < 0 )
return V_42 ;
V_2 -> V_179 = F_78 ( & V_171 -> V_30 , L_26 ) ;
if ( F_75 ( V_2 -> V_179 ) )
return F_76 ( V_2 -> V_179 ) ;
V_2 -> V_180 = F_78 ( & V_171 -> V_30 , L_27 ) ;
if ( F_75 ( V_2 -> V_180 ) )
return F_76 ( V_2 -> V_180 ) ;
F_79 ( V_2 -> V_179 ) ;
F_79 ( V_2 -> V_180 ) ;
F_9 ( V_2 , V_181 , V_182 ) ;
if ( F_1 ( V_2 ) ) {
V_174 = F_80 ( & V_171 -> V_30 , V_42 ,
F_37 , 0 , L_28 , V_2 ) ;
if ( V_174 ) {
F_45 ( V_2 -> V_30 , L_29 ) ;
goto V_183;
}
V_175 = F_77 ( V_171 , 1 ) ;
if ( V_175 < 0 ) {
V_174 = V_175 ;
goto V_183;
}
V_174 = F_80 ( & V_171 -> V_30 , V_175 ,
F_30 , 0 , L_28 , V_2 ) ;
if ( V_174 ) {
F_45 ( V_2 -> V_30 , L_30 ) ;
goto V_183;
}
}
F_9 ( V_2 , V_184 , V_182 ) ;
F_9 ( V_2 , ( 1 << V_53 ) - 1 , V_33 ) ;
F_9 ( V_2 , ( 1 << V_53 ) - 1 , V_34 ) ;
F_62 ( & V_2 -> V_185 . V_186 ) ;
F_81 ( V_187 , V_2 -> V_185 . V_188 ) ;
F_81 ( V_189 , V_2 -> V_185 . V_188 ) ;
F_81 ( V_190 , V_2 -> V_185 . V_188 ) ;
F_81 ( V_191 , V_2 -> V_185 . V_188 ) ;
for ( V_45 = 0 ; V_45 < V_65 ; V_45 ++ )
V_2 -> V_66 [ V_45 ] . V_67 = 0 ;
F_82 ( & V_2 -> V_60 ) ;
for ( V_45 = 0 ; V_45 < V_53 ; V_45 ++ ) {
struct V_7 * V_10 = & V_2 -> V_29 [ V_45 ] ;
if ( ! F_1 ( V_2 ) ) {
V_174 = F_80 ( & V_171 -> V_30 , V_42 + V_45 ,
F_37 , 0 , L_28 , V_2 ) ;
if ( V_174 ) {
F_45 ( V_2 -> V_30 , L_31
L_32 ,
V_42 + V_45 , V_45 ) ;
goto V_183;
}
F_83 ( & V_10 -> V_39 ) ;
V_10 -> V_39 . V_192 = & F_28 ;
V_10 -> V_39 . V_40 = ( unsigned long ) V_10 ;
}
V_10 -> V_2 = V_2 ;
F_62 ( & V_10 -> V_101 ) ;
F_62 ( & V_10 -> V_100 ) ;
F_62 ( & V_10 -> V_13 ) ;
F_84 ( & V_10 -> V_41 , F_42 ,
( unsigned long ) V_10 ) ;
V_10 -> V_9 . V_193 = & V_2 -> V_185 ;
F_85 ( & V_10 -> V_9 ) ;
V_10 -> V_29 = V_45 ;
F_58 ( & V_10 -> V_9 . V_194 ,
& V_2 -> V_185 . V_186 ) ;
}
V_2 -> V_30 = & V_171 -> V_30 ;
V_2 -> V_185 . V_30 = & V_171 -> V_30 ;
V_2 -> V_185 . V_195 = F_54 ;
V_2 -> V_185 . V_196 = F_59 ;
V_2 -> V_185 . V_197 = F_50 ;
V_2 -> V_185 . V_198 = F_63 ;
V_2 -> V_185 . V_199 = F_65 ;
V_2 -> V_185 . V_200 = F_68 ;
V_2 -> V_185 . V_201 = F_69 ;
V_2 -> V_185 . V_202 = F_46 ;
V_2 -> V_185 . V_203 = F_70 ;
F_86 ( V_171 , V_2 ) ;
V_2 -> V_185 . V_204 = 2 ;
V_2 -> V_185 . V_30 -> V_205 = & V_2 -> V_205 ;
F_87 ( V_2 -> V_185 . V_30 , 0xffffff ) ;
V_174 = F_88 ( & V_2 -> V_185 ) ;
if ( V_174 ) {
F_41 ( & V_171 -> V_30 , L_33 ) ;
goto V_183;
}
return 0 ;
V_183:
F_89 ( V_2 -> V_179 ) ;
F_89 ( V_2 -> V_180 ) ;
return V_174 ;
}
static int T_7 F_90 ( struct V_170 * V_171 )
{
struct V_1 * V_2 = F_91 ( V_171 ) ;
F_92 ( & V_2 -> V_185 ) ;
F_89 ( V_2 -> V_179 ) ;
F_89 ( V_2 -> V_180 ) ;
return 0 ;
}
static int T_6 F_93 ( void )
{
return F_94 ( & V_206 , F_71 ) ;
}
