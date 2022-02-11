static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline bool F_3 ( struct V_1 * V_4 )
{
struct V_5 * V_6 ;
if ( ! F_4 ( & V_4 -> V_7 ) ) {
V_6 = F_5 ( & V_4 -> V_7 , struct V_5 ,
V_8 ) ;
if ( V_6 -> type == V_9 )
return true ;
}
return false ;
}
static void F_6 ( struct V_10 * V_11 , unsigned V_12 ,
unsigned V_13 )
{
F_7 ( V_12 , V_11 -> V_14 + V_13 ) ;
}
static unsigned F_8 ( struct V_10 * V_11 , unsigned V_13 )
{
return F_9 ( V_11 -> V_14 + V_13 ) ;
}
static int F_10 ( struct V_1 * V_4 )
{
if ( F_11 () )
return V_4 -> V_15 ;
else
return 0 ;
}
static inline int F_12 ( struct V_5 * V_16 )
{
struct V_1 * V_4 = F_1 ( V_16 -> V_6 . V_3 ) ;
struct V_10 * V_11 = V_4 -> V_11 ;
struct V_17 * V_18 = V_16 -> V_18 ;
unsigned long V_19 ;
V_19 = F_13 ( V_16 -> V_20 , F_14 ( V_18 ) ) ;
if ( V_16 -> V_20 != V_21 )
V_16 -> V_20 -= V_19 ;
if ( V_16 -> V_22 == V_23 )
F_6 ( V_11 , V_18 -> V_24 ,
F_15 ( V_4 -> V_25 ) ) ;
else
F_6 ( V_11 , V_18 -> V_24 ,
F_16 ( V_4 -> V_25 ) ) ;
F_6 ( V_11 , V_19 , F_17 ( V_4 -> V_25 ) ) ;
F_18 ( V_11 -> V_26 , L_1
L_2 , V_27 , V_4 -> V_25 ,
F_8 ( V_11 , F_15 ( V_4 -> V_25 ) ) ,
F_8 ( V_11 , F_16 ( V_4 -> V_25 ) ) ,
F_8 ( V_11 , F_17 ( V_4 -> V_25 ) ) ) ;
return V_19 ;
}
static void F_19 ( struct V_5 * V_16 )
{
struct V_1 * V_4 = F_1 ( V_16 -> V_6 . V_3 ) ;
struct V_10 * V_11 = V_4 -> V_11 ;
int V_25 = V_4 -> V_25 ;
unsigned long V_28 ;
F_18 ( V_11 -> V_26 , L_3 , V_27 , V_25 ) ;
F_20 ( V_28 ) ;
F_6 ( V_11 , 1 << V_25 , V_29 ) ;
F_6 ( V_11 , F_8 ( V_11 , V_30 ) &
~ ( 1 << V_25 ) , V_30 ) ;
F_6 ( V_11 , F_8 ( V_11 , F_21 ( V_25 ) ) |
V_31 | V_32 , F_21 ( V_25 ) ) ;
if ( ( F_22 () || F_11 () ) &&
V_16 -> V_18 && F_10 ( V_4 ) ) {
V_16 -> V_18 = F_23 ( V_16 -> V_18 ) ;
if ( V_16 -> V_18 ) {
T_1 V_33 ;
F_12 ( V_16 ) ;
V_33 = F_8 ( V_11 , F_21 ( V_25 ) ) ;
F_6 ( V_11 , V_33 | V_34 | V_32 ,
F_21 ( V_25 ) ) ;
}
}
F_24 ( V_28 ) ;
}
static void F_25 ( struct V_1 * V_4 )
{
struct V_10 * V_11 = V_4 -> V_11 ;
int V_25 = V_4 -> V_25 ;
unsigned long V_28 ;
F_18 ( V_11 -> V_26 , L_3 , V_27 , V_25 ) ;
if ( F_10 ( V_4 ) )
F_26 ( & V_4 -> V_35 ) ;
F_20 ( V_28 ) ;
F_6 ( V_11 , F_8 ( V_11 , V_30 ) |
( 1 << V_25 ) , V_30 ) ;
F_6 ( V_11 , F_8 ( V_11 , F_21 ( V_25 ) ) &
~ V_31 , F_21 ( V_25 ) ) ;
F_6 ( V_11 , 1 << V_25 , V_29 ) ;
F_24 ( V_28 ) ;
}
static void F_27 ( unsigned long V_36 )
{
struct V_1 * V_4 = (struct V_1 * ) V_36 ;
struct V_10 * V_11 = V_4 -> V_11 ;
int V_25 = V_4 -> V_25 ;
F_6 ( V_11 , 0 , F_21 ( V_25 ) ) ;
F_28 ( & V_4 -> V_37 ) ;
F_18 ( V_11 -> V_26 , L_4 ,
V_4 -> V_25 ) ;
}
static T_2 F_29 ( int V_38 , void * V_39 )
{
struct V_10 * V_11 = V_39 ;
unsigned int V_40 ;
int V_41 , V_42 ;
int V_43 ;
V_42 = F_8 ( V_11 , V_29 ) ;
V_40 = F_8 ( V_11 , V_44 ) |
F_8 ( V_11 , V_45 ) |
F_8 ( V_11 , V_46 ) |
F_8 ( V_11 , V_47 ) ;
if ( ! V_40 )
return V_48 ;
F_6 ( V_11 , V_42 & V_40 , V_29 ) ;
for ( V_41 = 0 ; V_41 < V_49 ; V_41 ++ ) {
if ( ! ( V_40 & ( 1 << V_41 ) ) )
continue;
V_43 = 0 ;
if ( F_8 ( V_11 , V_44 ) & ( 1 << V_41 ) ) {
F_6 ( V_11 , 1 << V_41 , V_44 ) ;
V_43 |= V_50 ;
}
if ( F_8 ( V_11 , V_45 ) & ( 1 << V_41 ) ) {
F_6 ( V_11 , 1 << V_41 , V_45 ) ;
V_43 |= V_51 ;
}
if ( F_8 ( V_11 , V_46 ) & ( 1 << V_41 ) ) {
F_6 ( V_11 , 1 << V_41 , V_46 ) ;
V_43 |= V_52 ;
}
if ( F_8 ( V_11 , V_47 ) & ( 1 << V_41 ) ) {
F_6 ( V_11 , 1 << V_41 , V_47 ) ;
V_43 |= V_53 ;
}
F_28 ( & V_11 -> V_25 [ V_41 ] . V_37 ) ;
F_30 ( V_54
L_5 , V_41 ,
V_43 & V_50 ? L_6 : L_7 ,
V_43 & V_51 ? L_8 : L_7 ,
V_43 & V_52 ? L_9 : L_7 ,
V_43 & V_53 ? L_10 : L_7 ) ;
}
return V_48 ;
}
static void F_31 ( struct V_1 * V_4 )
{
struct V_10 * V_11 = V_4 -> V_11 ;
int V_55 = V_4 -> V_25 ;
struct V_5 * V_6 ;
F_32 ( & V_11 -> V_56 ) ;
if ( F_4 ( & V_4 -> V_7 ) ) {
F_33 ( & V_11 -> V_56 ) ;
goto V_57;
}
V_6 = F_5 ( & V_4 -> V_7 ,
struct V_5 ,
V_8 ) ;
F_33 ( & V_11 -> V_56 ) ;
if ( V_6 -> V_18 ) {
T_1 V_33 ;
V_6 -> V_18 = F_23 ( V_6 -> V_18 ) ;
if ( V_6 -> V_18 ) {
F_12 ( V_6 ) ;
V_33 = F_8 ( V_11 , F_21 ( V_55 ) ) ;
if ( F_10 ( V_4 ) ) {
F_34 ( & V_4 -> V_35 ,
V_58 + F_35 ( 500 ) ) ;
V_33 |= V_31 | V_34 | V_32 ;
F_6 ( V_11 , V_33 , F_21 ( V_55 ) ) ;
} else {
F_6 ( V_11 , V_33 & ~ V_31 ,
F_21 ( V_55 ) ) ;
V_33 |= V_31 ;
}
F_6 ( V_11 , V_33 , F_21 ( V_55 ) ) ;
if ( F_3 ( V_4 ) )
F_28 ( & V_4 -> V_37 ) ;
return;
}
if ( F_10 ( V_4 ) ) {
F_26 ( & V_4 -> V_35 ) ;
return;
}
}
V_57:
F_6 ( V_11 , 0 , F_21 ( V_55 ) ) ;
F_28 ( & V_4 -> V_37 ) ;
}
static T_2 F_36 ( int V_38 , void * V_39 )
{
struct V_10 * V_11 = V_39 ;
int V_41 , V_42 ;
if ( F_22 () || F_11 () )
F_29 ( V_38 , V_39 ) ;
V_42 = F_8 ( V_11 , V_29 ) ;
F_18 ( V_11 -> V_26 , L_11 , V_27 , V_42 ) ;
F_6 ( V_11 , V_42 , V_29 ) ;
for ( V_41 = 0 ; V_41 < V_49 ; V_41 ++ ) {
if ( V_42 & ( 1 << V_41 ) )
F_31 ( & V_11 -> V_25 [ V_41 ] ) ;
}
return V_48 ;
}
static int F_37 ( struct V_5 * V_16 )
{
struct V_1 * V_4 = F_1 ( V_16 -> V_6 . V_3 ) ;
struct V_10 * V_11 = V_4 -> V_11 ;
unsigned long V_28 ;
int V_59 = - 1 ;
int V_41 ;
switch ( V_16 -> type ) {
case V_60 :
F_38 ( & V_11 -> V_56 , V_28 ) ;
for ( V_41 = 0 ; V_41 < V_61 ; V_41 ++ ) {
if ( ( V_11 -> V_62 [ V_41 ] . V_63 > 0 ) &&
( ( V_11 -> V_62 [ V_41 ] . V_64 != V_16 -> V_65 ) ||
( V_11 -> V_62 [ V_41 ] . V_66 != V_16 -> V_67 ) ||
( V_11 -> V_62 [ V_41 ] . V_68 != V_16 -> V_69 ) ) )
continue;
V_59 = V_41 ;
break;
}
if ( V_59 < 0 )
return - V_70 ;
V_11 -> V_62 [ V_59 ] . V_64 = V_16 -> V_65 ;
V_11 -> V_62 [ V_59 ] . V_66 = V_16 -> V_67 ;
V_11 -> V_62 [ V_59 ] . V_68 = V_16 -> V_69 ;
V_11 -> V_62 [ V_59 ] . V_63 ++ ;
V_4 -> V_71 = V_59 ;
V_4 -> V_72 = true ;
F_39 ( & V_11 -> V_56 , V_28 ) ;
if ( V_59 == V_73 ) {
V_16 -> V_74 &= ~ V_75 ;
V_16 -> V_76 &= ~ V_75 ;
F_6 ( V_11 , V_16 -> V_65 , V_77 ) ;
F_6 ( V_11 , V_16 -> V_67 , V_78 ) ;
F_6 ( V_11 , V_16 -> V_69 , V_79 ) ;
} else {
V_16 -> V_74 |= V_75 ;
V_16 -> V_76 |= V_75 ;
F_6 ( V_11 , V_16 -> V_65 , V_80 ) ;
F_6 ( V_11 , V_16 -> V_67 , V_81 ) ;
F_6 ( V_11 , V_16 -> V_69 , V_82 ) ;
}
case V_83 :
F_6 ( V_11 , V_16 -> V_84 , F_16 ( V_4 -> V_25 ) ) ;
F_6 ( V_11 , V_16 -> V_85 , F_15 ( V_4 -> V_25 ) ) ;
F_6 ( V_11 , V_16 -> V_74 | ( V_16 -> V_76 << 2 ) ,
F_21 ( V_4 -> V_25 ) ) ;
F_6 ( V_11 , V_16 -> V_20 , F_17 ( V_4 -> V_25 ) ) ;
F_18 ( V_11 -> V_26 , L_12
L_13 , V_27 , V_4 -> V_25 ,
V_16 -> V_85 , V_16 -> V_84 , V_16 -> V_20 ) ;
break;
case V_9 :
case V_86 :
if ( V_16 -> V_22 == V_23 ) {
F_6 ( V_11 , V_4 -> V_87 ,
F_16 ( V_4 -> V_25 ) ) ;
F_6 ( V_11 , V_4 -> V_88 ,
F_21 ( V_4 -> V_25 ) ) ;
F_18 ( V_11 -> V_26 , L_14
L_15 ,
V_27 , V_4 -> V_25 , V_16 -> V_18 , V_16 -> V_89 ,
V_16 -> V_20 , V_4 -> V_87 ) ;
} else if ( V_16 -> V_22 == V_90 ) {
F_6 ( V_11 , V_4 -> V_87 ,
F_15 ( V_4 -> V_25 ) ) ;
F_6 ( V_11 , V_4 -> V_91 ,
F_21 ( V_4 -> V_25 ) ) ;
F_18 ( V_11 -> V_26 , L_14
L_16 ,
V_27 , V_4 -> V_25 , V_16 -> V_18 , V_16 -> V_89 ,
V_16 -> V_20 , V_4 -> V_87 ) ;
} else {
F_40 ( V_11 -> V_26 , L_17 ,
V_27 , V_4 -> V_25 ) ;
return - V_92 ;
}
F_12 ( V_16 ) ;
break;
default:
return - V_92 ;
}
F_19 ( V_16 ) ;
return 0 ;
}
static void F_41 ( unsigned long V_36 )
{
struct V_1 * V_4 = ( void * ) V_36 ;
struct V_10 * V_11 = V_4 -> V_11 ;
struct V_5 * V_6 ;
F_32 ( & V_11 -> V_56 ) ;
if ( F_4 ( & V_4 -> V_7 ) ) {
goto V_57;
}
V_6 = F_5 ( & V_4 -> V_7 , struct V_5 , V_8 ) ;
if ( V_6 -> V_6 . V_93 )
V_6 -> V_6 . V_93 ( V_6 -> V_6 . V_94 ) ;
if ( F_3 ( V_4 ) )
goto V_57;
else
F_42 ( & V_6 -> V_6 ) ;
if ( V_4 -> V_72 ) {
V_11 -> V_62 [ V_4 -> V_71 ] . V_63 -- ;
V_4 -> V_72 = false ;
}
F_43 ( V_4 -> V_7 . V_95 , & V_4 -> V_96 ) ;
if ( ! F_4 ( & V_4 -> V_97 ) ) {
V_6 = F_5 ( & V_4 -> V_97 , struct V_5 ,
V_8 ) ;
F_43 ( V_4 -> V_97 . V_95 , & V_4 -> V_7 ) ;
if ( F_37 ( V_6 ) < 0 )
F_44 ( V_11 -> V_26 , L_18 ,
V_27 , V_4 -> V_25 ) ;
}
V_57:
F_33 ( & V_11 -> V_56 ) ;
}
static int F_45 ( struct V_2 * V_3 , enum V_98 V_99 ,
unsigned long V_100 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_101 * V_102 = ( void * ) V_100 ;
struct V_10 * V_11 = V_4 -> V_11 ;
unsigned long V_28 ;
unsigned int V_103 = 0 ;
switch ( V_99 ) {
case V_104 :
F_25 ( V_4 ) ;
F_38 ( & V_11 -> V_56 , V_28 ) ;
F_46 ( & V_4 -> V_7 , & V_4 -> V_96 ) ;
F_46 ( & V_4 -> V_97 , & V_4 -> V_96 ) ;
F_39 ( & V_11 -> V_56 , V_28 ) ;
return 0 ;
case V_105 :
if ( V_102 -> V_22 == V_23 ) {
V_4 -> V_87 = V_102 -> V_106 ;
V_4 -> V_107 = V_102 -> V_108 ;
V_4 -> V_109 = V_102 -> V_110 ;
} else {
V_4 -> V_87 = V_102 -> V_111 ;
V_4 -> V_107 = V_102 -> V_112 ;
V_4 -> V_109 = V_102 -> V_113 ;
}
switch ( V_4 -> V_109 ) {
case V_114 :
V_103 = V_115 ;
break;
case V_116 :
V_103 = V_117 ;
break;
default:
case V_118 :
V_103 = V_119 ;
break;
}
V_4 -> V_15 = 1 ;
if ( ! F_10 ( V_4 ) )
return - V_92 ;
V_4 -> V_88 = ( V_103 | V_120 ) |
( ( V_119 | V_121 ) << 2 ) |
V_122 ;
V_4 -> V_91 =
( V_119 | V_121 ) |
( ( V_103 | V_120 ) << 2 ) | V_122 ;
F_6 ( V_11 , V_4 -> V_123 ,
F_47 ( V_4 -> V_25 ) ) ;
F_6 ( V_11 , V_4 -> V_107 *
V_4 -> V_109 , F_48 ( V_4 -> V_25 ) ) ;
return 0 ;
default:
return - V_124 ;
}
return - V_92 ;
}
static enum V_125 F_49 ( struct V_2 * V_3 ,
T_3 V_126 ,
struct V_127 * V_128 )
{
return F_50 ( V_3 , V_126 , V_128 ) ;
}
static T_3 F_51 ( struct V_129 * V_130 )
{
struct V_1 * V_4 = F_1 ( V_130 -> V_3 ) ;
struct V_10 * V_11 = V_4 -> V_11 ;
T_3 V_126 ;
unsigned long V_28 ;
F_38 ( & V_11 -> V_56 , V_28 ) ;
F_43 ( V_4 -> V_96 . V_95 , & V_4 -> V_97 ) ;
V_126 = F_52 ( V_130 ) ;
F_39 ( & V_11 -> V_56 , V_28 ) ;
return V_126 ;
}
static int F_53 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_131 * V_36 = V_3 -> V_132 ;
if ( V_36 != NULL )
V_4 -> V_123 = V_36 -> V_123 ;
while ( V_4 -> V_133 < V_134 ) {
struct V_5 * V_6 ;
V_6 = F_54 ( sizeof( * V_6 ) , V_135 ) ;
if ( ! V_6 )
break;
F_55 ( & V_6 -> V_6 , sizeof( struct V_129 ) ) ;
F_56 ( & V_6 -> V_6 , V_3 ) ;
V_6 -> V_6 . V_136 = F_51 ;
V_6 -> V_6 . V_28 = V_137 ;
V_6 -> V_138 = V_139 ;
F_57 ( & V_6 -> V_8 , & V_4 -> V_96 ) ;
V_4 -> V_133 ++ ;
}
if ( ! V_4 -> V_133 )
return - V_140 ;
return V_4 -> V_133 ;
}
static void F_58 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_10 * V_11 = V_4 -> V_11 ;
struct V_5 * V_6 , * V_141 ;
unsigned long V_28 ;
F_38 ( & V_11 -> V_56 , V_28 ) ;
F_25 ( V_4 ) ;
F_46 ( & V_4 -> V_7 , & V_4 -> V_96 ) ;
F_46 ( & V_4 -> V_97 , & V_4 -> V_96 ) ;
F_39 ( & V_11 -> V_56 , V_28 ) ;
F_59 (desc, _desc, &imxdmac->ld_free, node) {
F_60 ( V_6 ) ;
V_4 -> V_133 -- ;
}
F_61 ( & V_4 -> V_96 ) ;
if ( V_4 -> V_142 ) {
F_60 ( V_4 -> V_142 ) ;
V_4 -> V_142 = NULL ;
}
}
static struct V_129 * F_62 (
struct V_2 * V_3 , struct V_17 * V_143 ,
unsigned int V_144 , enum V_145 V_22 ,
unsigned long V_28 , void * V_146 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_17 * V_18 ;
int V_41 , V_147 = 0 ;
struct V_5 * V_6 ;
if ( F_4 ( & V_4 -> V_96 ) ||
F_3 ( V_4 ) )
return NULL ;
V_6 = F_5 ( & V_4 -> V_96 , struct V_5 , V_8 ) ;
F_63 (sgl, sg, sg_len, i) {
V_147 += F_14 ( V_18 ) ;
}
switch ( V_4 -> V_109 ) {
case V_118 :
if ( F_14 ( V_143 ) & 3 || V_143 -> V_24 & 3 )
return NULL ;
break;
case V_116 :
if ( F_14 ( V_143 ) & 1 || V_143 -> V_24 & 1 )
return NULL ;
break;
case V_114 :
break;
default:
return NULL ;
}
V_6 -> type = V_86 ;
V_6 -> V_18 = V_143 ;
V_6 -> V_89 = V_144 ;
V_6 -> V_20 = V_147 ;
V_6 -> V_22 = V_22 ;
if ( V_22 == V_23 ) {
V_6 -> V_84 = V_4 -> V_87 ;
} else {
V_6 -> V_85 = V_4 -> V_87 ;
}
V_6 -> V_6 . V_93 = NULL ;
V_6 -> V_6 . V_94 = NULL ;
return & V_6 -> V_6 ;
}
static struct V_129 * F_64 (
struct V_2 * V_3 , T_4 V_148 , T_5 V_149 ,
T_5 V_150 , enum V_145 V_22 ,
void * V_146 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_10 * V_11 = V_4 -> V_11 ;
struct V_5 * V_6 ;
int V_41 ;
unsigned int V_151 = V_149 / V_150 ;
F_18 ( V_11 -> V_26 , L_19 ,
V_27 , V_4 -> V_25 , V_149 , V_150 ) ;
if ( F_4 ( & V_4 -> V_96 ) ||
F_3 ( V_4 ) )
return NULL ;
V_6 = F_5 ( & V_4 -> V_96 , struct V_5 , V_8 ) ;
if ( V_4 -> V_142 )
F_60 ( V_4 -> V_142 ) ;
V_4 -> V_142 = F_65 ( V_151 + 1 ,
sizeof( struct V_17 ) , V_135 ) ;
if ( ! V_4 -> V_142 )
return NULL ;
F_66 ( V_4 -> V_142 , V_151 ) ;
for ( V_41 = 0 ; V_41 < V_151 ; V_41 ++ ) {
V_4 -> V_142 [ V_41 ] . V_152 = 0 ;
V_4 -> V_142 [ V_41 ] . V_13 = 0 ;
V_4 -> V_142 [ V_41 ] . V_24 = V_148 ;
F_14 ( & V_4 -> V_142 [ V_41 ] ) = V_150 ;
V_148 += V_150 ;
}
V_4 -> V_142 [ V_151 ] . V_13 = 0 ;
F_14 ( & V_4 -> V_142 [ V_151 ] ) = 0 ;
V_4 -> V_142 [ V_151 ] . V_152 =
( ( unsigned long ) V_4 -> V_142 | 0x01 ) & ~ 0x02 ;
V_6 -> type = V_9 ;
V_6 -> V_18 = V_4 -> V_142 ;
V_6 -> V_89 = V_151 ;
V_6 -> V_20 = V_21 ;
V_6 -> V_22 = V_22 ;
if ( V_22 == V_23 ) {
V_6 -> V_84 = V_4 -> V_87 ;
} else {
V_6 -> V_85 = V_4 -> V_87 ;
}
V_6 -> V_6 . V_93 = NULL ;
V_6 -> V_6 . V_94 = NULL ;
return & V_6 -> V_6 ;
}
static struct V_129 * F_67 (
struct V_2 * V_3 , T_4 V_85 ,
T_4 V_84 , T_5 V_20 , unsigned long V_28 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_10 * V_11 = V_4 -> V_11 ;
struct V_5 * V_6 ;
F_18 ( V_11 -> V_26 , L_20 ,
V_27 , V_4 -> V_25 , V_84 , V_85 , V_20 ) ;
if ( F_4 ( & V_4 -> V_96 ) ||
F_3 ( V_4 ) )
return NULL ;
V_6 = F_5 ( & V_4 -> V_96 , struct V_5 , V_8 ) ;
V_6 -> type = V_83 ;
V_6 -> V_84 = V_84 ;
V_6 -> V_85 = V_85 ;
V_6 -> V_20 = V_20 ;
V_6 -> V_22 = V_153 ;
V_6 -> V_76 = V_119 | V_121 ;
V_6 -> V_74 = V_119 | V_121 ;
V_6 -> V_6 . V_93 = NULL ;
V_6 -> V_6 . V_94 = NULL ;
return & V_6 -> V_6 ;
}
static struct V_129 * F_68 (
struct V_2 * V_3 , struct V_154 * V_155 ,
unsigned long V_28 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_10 * V_11 = V_4 -> V_11 ;
struct V_5 * V_6 ;
F_18 ( V_11 -> V_26 , L_21
L_22 , V_27 ,
V_4 -> V_25 , V_155 -> V_156 , V_155 -> V_157 ,
V_155 -> V_158 ? L_23 : L_24 , V_155 -> V_159 ? L_23 : L_24 ,
V_155 -> V_160 , V_155 -> V_161 ) ;
if ( F_4 ( & V_4 -> V_96 ) ||
F_3 ( V_4 ) )
return NULL ;
if ( V_155 -> V_161 != 1 || V_155 -> V_160 <= 0 || V_155 -> V_162 != V_153 )
return NULL ;
V_6 = F_5 ( & V_4 -> V_96 , struct V_5 , V_8 ) ;
V_6 -> type = V_60 ;
V_6 -> V_84 = V_155 -> V_156 ;
V_6 -> V_85 = V_155 -> V_157 ;
V_6 -> V_65 = V_155 -> V_143 [ 0 ] . V_163 ;
V_6 -> V_67 = V_155 -> V_160 ;
V_6 -> V_69 = V_155 -> V_143 [ 0 ] . V_164 + V_6 -> V_65 ;
V_6 -> V_20 = V_6 -> V_65 * V_6 -> V_67 ;
V_6 -> V_22 = V_153 ;
V_6 -> V_76 = V_119 ;
V_6 -> V_74 = V_119 ;
if ( V_155 -> V_158 )
V_6 -> V_74 |= V_165 ;
if ( V_155 -> V_159 )
V_6 -> V_76 |= V_165 ;
V_6 -> V_6 . V_93 = NULL ;
V_6 -> V_6 . V_94 = NULL ;
return & V_6 -> V_6 ;
}
static void F_69 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_10 * V_11 = V_4 -> V_11 ;
struct V_5 * V_6 ;
unsigned long V_28 ;
F_38 ( & V_11 -> V_56 , V_28 ) ;
if ( F_4 ( & V_4 -> V_7 ) &&
! F_4 ( & V_4 -> V_97 ) ) {
V_6 = F_5 ( & V_4 -> V_97 ,
struct V_5 , V_8 ) ;
if ( F_37 ( V_6 ) < 0 ) {
F_44 ( V_11 -> V_26 ,
L_25 ,
V_27 , V_4 -> V_25 ) ;
} else {
F_43 ( V_4 -> V_97 . V_95 ,
& V_4 -> V_7 ) ;
}
}
F_39 ( & V_11 -> V_56 , V_28 ) ;
}
static int T_6 F_70 ( struct V_166 * V_167 )
{
struct V_10 * V_11 ;
int V_168 , V_41 ;
V_11 = F_54 ( sizeof( * V_11 ) , V_135 ) ;
if ( ! V_11 )
return - V_140 ;
if ( F_71 () ) {
V_11 -> V_14 = F_72 ( V_169 ) ;
} else if ( F_22 () ) {
V_11 -> V_14 = F_73 ( V_170 ) ;
} else if ( F_11 () ) {
V_11 -> V_14 = F_74 ( V_171 ) ;
} else {
F_60 ( V_11 ) ;
return 0 ;
}
V_11 -> V_172 = F_75 ( & V_167 -> V_26 , L_26 ) ;
if ( F_76 ( V_11 -> V_172 ) ) {
V_168 = F_77 ( V_11 -> V_172 ) ;
goto V_173;
}
V_11 -> V_174 = F_75 ( & V_167 -> V_26 , L_27 ) ;
if ( F_76 ( V_11 -> V_174 ) ) {
V_168 = F_77 ( V_11 -> V_174 ) ;
goto V_173;
}
F_78 ( V_11 -> V_172 ) ;
F_78 ( V_11 -> V_174 ) ;
F_6 ( V_11 , V_175 , V_176 ) ;
if ( F_71 () ) {
V_168 = F_79 ( V_177 , F_36 , 0 , L_28 , V_11 ) ;
if ( V_168 ) {
F_44 ( V_11 -> V_26 , L_29 ) ;
goto V_178;
}
V_168 = F_79 ( V_179 , F_29 , 0 , L_28 , V_11 ) ;
if ( V_168 ) {
F_44 ( V_11 -> V_26 , L_30 ) ;
F_80 ( V_177 , NULL ) ;
goto V_178;
}
}
F_6 ( V_11 , V_180 , V_176 ) ;
F_6 ( V_11 , ( 1 << V_49 ) - 1 , V_29 ) ;
F_6 ( V_11 , ( 1 << V_49 ) - 1 , V_30 ) ;
F_61 ( & V_11 -> V_181 . V_182 ) ;
F_81 ( V_183 , V_11 -> V_181 . V_184 ) ;
F_81 ( V_185 , V_11 -> V_181 . V_184 ) ;
F_81 ( V_186 , V_11 -> V_181 . V_184 ) ;
F_81 ( V_187 , V_11 -> V_181 . V_184 ) ;
for ( V_41 = 0 ; V_41 < V_61 ; V_41 ++ )
V_11 -> V_62 [ V_41 ] . V_63 = 0 ;
F_82 ( & V_11 -> V_56 ) ;
for ( V_41 = 0 ; V_41 < V_49 ; V_41 ++ ) {
struct V_1 * V_4 = & V_11 -> V_25 [ V_41 ] ;
if ( F_22 () || F_11 () ) {
V_168 = F_79 ( V_188 + V_41 ,
F_36 , 0 , L_28 , V_11 ) ;
if ( V_168 ) {
F_44 ( V_11 -> V_26 , L_31
L_32 ,
V_188 + V_41 , V_41 ) ;
goto V_189;
}
F_83 ( & V_4 -> V_35 ) ;
V_4 -> V_35 . V_190 = & F_27 ;
V_4 -> V_35 . V_36 = ( unsigned long ) V_4 ;
}
V_4 -> V_11 = V_11 ;
F_61 ( & V_4 -> V_97 ) ;
F_61 ( & V_4 -> V_96 ) ;
F_61 ( & V_4 -> V_7 ) ;
F_84 ( & V_4 -> V_37 , F_41 ,
( unsigned long ) V_4 ) ;
V_4 -> V_3 . V_191 = & V_11 -> V_181 ;
F_85 ( & V_4 -> V_3 ) ;
V_4 -> V_25 = V_41 ;
F_57 ( & V_4 -> V_3 . V_192 ,
& V_11 -> V_181 . V_182 ) ;
}
V_11 -> V_26 = & V_167 -> V_26 ;
V_11 -> V_181 . V_26 = & V_167 -> V_26 ;
V_11 -> V_181 . V_193 = F_53 ;
V_11 -> V_181 . V_194 = F_58 ;
V_11 -> V_181 . V_195 = F_49 ;
V_11 -> V_181 . V_196 = F_62 ;
V_11 -> V_181 . V_197 = F_64 ;
V_11 -> V_181 . V_198 = F_67 ;
V_11 -> V_181 . V_199 = F_68 ;
V_11 -> V_181 . V_200 = F_45 ;
V_11 -> V_181 . V_201 = F_69 ;
F_86 ( V_167 , V_11 ) ;
V_11 -> V_181 . V_202 = 2 ;
V_11 -> V_181 . V_26 -> V_203 = & V_11 -> V_203 ;
F_87 ( V_11 -> V_181 . V_26 , 0xffffff ) ;
V_168 = F_88 ( & V_11 -> V_181 ) ;
if ( V_168 ) {
F_40 ( & V_167 -> V_26 , L_33 ) ;
goto V_189;
}
return 0 ;
V_189:
if ( F_22 () || F_11 () ) {
while ( -- V_41 >= 0 )
F_80 ( V_188 + V_41 , NULL ) ;
} else if cpu_is_mx1() {
F_80 ( V_177 , NULL ) ;
F_80 ( V_179 , NULL ) ;
}
V_178:
F_89 ( V_11 -> V_172 ) ;
F_89 ( V_11 -> V_174 ) ;
V_173:
F_60 ( V_11 ) ;
return V_168 ;
}
static int T_7 F_90 ( struct V_166 * V_167 )
{
struct V_10 * V_11 = F_91 ( V_167 ) ;
int V_41 ;
F_92 ( & V_11 -> V_181 ) ;
if ( F_22 () || F_11 () ) {
for ( V_41 = 0 ; V_41 < V_49 ; V_41 ++ )
F_80 ( V_188 + V_41 , NULL ) ;
} else if cpu_is_mx1() {
F_80 ( V_177 , NULL ) ;
F_80 ( V_179 , NULL ) ;
}
F_89 ( V_11 -> V_172 ) ;
F_89 ( V_11 -> V_174 ) ;
F_60 ( V_11 ) ;
return 0 ;
}
static int T_6 F_93 ( void )
{
return F_94 ( & V_204 , F_70 ) ;
}
