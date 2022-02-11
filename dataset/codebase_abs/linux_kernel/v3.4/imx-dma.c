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
V_19 = F_13 ( V_16 -> V_20 , V_18 -> V_21 ) ;
if ( V_16 -> V_20 != V_22 )
V_16 -> V_20 -= V_19 ;
if ( V_16 -> V_23 == V_24 )
F_6 ( V_11 , V_18 -> V_25 ,
F_14 ( V_4 -> V_26 ) ) ;
else
F_6 ( V_11 , V_18 -> V_25 ,
F_15 ( V_4 -> V_26 ) ) ;
F_6 ( V_11 , V_19 , F_16 ( V_4 -> V_26 ) ) ;
F_17 ( V_11 -> V_27 , L_1
L_2 , V_28 , V_4 -> V_26 ,
F_8 ( V_11 , F_14 ( V_4 -> V_26 ) ) ,
F_8 ( V_11 , F_15 ( V_4 -> V_26 ) ) ,
F_8 ( V_11 , F_16 ( V_4 -> V_26 ) ) ) ;
return V_19 ;
}
static void F_18 ( struct V_5 * V_16 )
{
struct V_1 * V_4 = F_1 ( V_16 -> V_6 . V_3 ) ;
struct V_10 * V_11 = V_4 -> V_11 ;
int V_26 = V_4 -> V_26 ;
unsigned long V_29 ;
F_17 ( V_11 -> V_27 , L_3 , V_28 , V_26 ) ;
F_19 ( V_29 ) ;
F_6 ( V_11 , 1 << V_26 , V_30 ) ;
F_6 ( V_11 , F_8 ( V_11 , V_31 ) &
~ ( 1 << V_26 ) , V_31 ) ;
F_6 ( V_11 , F_8 ( V_11 , F_20 ( V_26 ) ) |
V_32 | V_33 , F_20 ( V_26 ) ) ;
if ( ( F_21 () || F_11 () ) &&
V_16 -> V_18 && F_10 ( V_4 ) ) {
V_16 -> V_18 = F_22 ( V_16 -> V_18 ) ;
if ( V_16 -> V_18 ) {
T_1 V_34 ;
F_12 ( V_16 ) ;
V_34 = F_8 ( V_11 , F_20 ( V_26 ) ) ;
F_6 ( V_11 , V_34 | V_35 | V_33 ,
F_20 ( V_26 ) ) ;
}
}
F_23 ( V_29 ) ;
}
static void F_24 ( struct V_1 * V_4 )
{
struct V_10 * V_11 = V_4 -> V_11 ;
int V_26 = V_4 -> V_26 ;
unsigned long V_29 ;
F_17 ( V_11 -> V_27 , L_3 , V_28 , V_26 ) ;
if ( F_10 ( V_4 ) )
F_25 ( & V_4 -> V_36 ) ;
F_19 ( V_29 ) ;
F_6 ( V_11 , F_8 ( V_11 , V_31 ) |
( 1 << V_26 ) , V_31 ) ;
F_6 ( V_11 , F_8 ( V_11 , F_20 ( V_26 ) ) &
~ V_32 , F_20 ( V_26 ) ) ;
F_6 ( V_11 , 1 << V_26 , V_30 ) ;
F_23 ( V_29 ) ;
}
static void F_26 ( unsigned long V_37 )
{
struct V_1 * V_4 = (struct V_1 * ) V_37 ;
struct V_10 * V_11 = V_4 -> V_11 ;
int V_26 = V_4 -> V_26 ;
F_6 ( V_11 , 0 , F_20 ( V_26 ) ) ;
F_27 ( & V_4 -> V_38 ) ;
F_17 ( V_11 -> V_27 , L_4 ,
V_4 -> V_26 ) ;
}
static T_2 F_28 ( int V_39 , void * V_40 )
{
struct V_10 * V_11 = V_40 ;
unsigned int V_41 ;
int V_42 , V_43 ;
int V_44 ;
V_43 = F_8 ( V_11 , V_30 ) ;
V_41 = F_8 ( V_11 , V_45 ) |
F_8 ( V_11 , V_46 ) |
F_8 ( V_11 , V_47 ) |
F_8 ( V_11 , V_48 ) ;
if ( ! V_41 )
return V_49 ;
F_6 ( V_11 , V_43 & V_41 , V_30 ) ;
for ( V_42 = 0 ; V_42 < V_50 ; V_42 ++ ) {
if ( ! ( V_41 & ( 1 << V_42 ) ) )
continue;
V_44 = 0 ;
if ( F_8 ( V_11 , V_45 ) & ( 1 << V_42 ) ) {
F_6 ( V_11 , 1 << V_42 , V_45 ) ;
V_44 |= V_51 ;
}
if ( F_8 ( V_11 , V_46 ) & ( 1 << V_42 ) ) {
F_6 ( V_11 , 1 << V_42 , V_46 ) ;
V_44 |= V_52 ;
}
if ( F_8 ( V_11 , V_47 ) & ( 1 << V_42 ) ) {
F_6 ( V_11 , 1 << V_42 , V_47 ) ;
V_44 |= V_53 ;
}
if ( F_8 ( V_11 , V_48 ) & ( 1 << V_42 ) ) {
F_6 ( V_11 , 1 << V_42 , V_48 ) ;
V_44 |= V_54 ;
}
F_27 ( & V_11 -> V_26 [ V_42 ] . V_38 ) ;
F_29 ( V_55
L_5 , V_42 ,
V_44 & V_51 ? L_6 : L_7 ,
V_44 & V_52 ? L_8 : L_7 ,
V_44 & V_53 ? L_9 : L_7 ,
V_44 & V_54 ? L_10 : L_7 ) ;
}
return V_49 ;
}
static void F_30 ( struct V_1 * V_4 )
{
struct V_10 * V_11 = V_4 -> V_11 ;
int V_56 = V_4 -> V_26 ;
struct V_5 * V_6 ;
F_31 ( & V_11 -> V_57 ) ;
if ( F_4 ( & V_4 -> V_7 ) ) {
F_32 ( & V_11 -> V_57 ) ;
goto V_58;
}
V_6 = F_5 ( & V_4 -> V_7 ,
struct V_5 ,
V_8 ) ;
F_32 ( & V_11 -> V_57 ) ;
if ( V_6 -> V_18 ) {
T_1 V_34 ;
V_6 -> V_18 = F_22 ( V_6 -> V_18 ) ;
if ( V_6 -> V_18 ) {
F_12 ( V_6 ) ;
V_34 = F_8 ( V_11 , F_20 ( V_56 ) ) ;
if ( F_10 ( V_4 ) ) {
F_33 ( & V_4 -> V_36 ,
V_59 + F_34 ( 500 ) ) ;
V_34 |= V_32 | V_35 | V_33 ;
F_6 ( V_11 , V_34 , F_20 ( V_56 ) ) ;
} else {
F_6 ( V_11 , V_34 & ~ V_32 ,
F_20 ( V_56 ) ) ;
V_34 |= V_32 ;
}
F_6 ( V_11 , V_34 , F_20 ( V_56 ) ) ;
if ( F_3 ( V_4 ) )
F_27 ( & V_4 -> V_38 ) ;
return;
}
if ( F_10 ( V_4 ) ) {
F_25 ( & V_4 -> V_36 ) ;
return;
}
}
V_58:
F_6 ( V_11 , 0 , F_20 ( V_56 ) ) ;
F_27 ( & V_4 -> V_38 ) ;
}
static T_2 F_35 ( int V_39 , void * V_40 )
{
struct V_10 * V_11 = V_40 ;
int V_42 , V_43 ;
if ( F_21 () || F_11 () )
F_28 ( V_39 , V_40 ) ;
V_43 = F_8 ( V_11 , V_30 ) ;
F_17 ( V_11 -> V_27 , L_11 , V_28 , V_43 ) ;
F_6 ( V_11 , V_43 , V_30 ) ;
for ( V_42 = 0 ; V_42 < V_50 ; V_42 ++ ) {
if ( V_43 & ( 1 << V_42 ) )
F_30 ( & V_11 -> V_26 [ V_42 ] ) ;
}
return V_49 ;
}
static int F_36 ( struct V_5 * V_16 )
{
struct V_1 * V_4 = F_1 ( V_16 -> V_6 . V_3 ) ;
struct V_10 * V_11 = V_4 -> V_11 ;
unsigned long V_29 ;
int V_60 = - 1 ;
int V_42 ;
switch ( V_16 -> type ) {
case V_61 :
F_37 ( & V_11 -> V_57 , V_29 ) ;
for ( V_42 = 0 ; V_42 < V_62 ; V_42 ++ ) {
if ( ( V_11 -> V_63 [ V_42 ] . V_64 > 0 ) &&
( ( V_11 -> V_63 [ V_42 ] . V_65 != V_16 -> V_66 ) ||
( V_11 -> V_63 [ V_42 ] . V_67 != V_16 -> V_68 ) ||
( V_11 -> V_63 [ V_42 ] . V_69 != V_16 -> V_70 ) ) )
continue;
V_60 = V_42 ;
break;
}
if ( V_60 < 0 )
return - V_71 ;
V_11 -> V_63 [ V_60 ] . V_65 = V_16 -> V_66 ;
V_11 -> V_63 [ V_60 ] . V_67 = V_16 -> V_68 ;
V_11 -> V_63 [ V_60 ] . V_69 = V_16 -> V_70 ;
V_11 -> V_63 [ V_60 ] . V_64 ++ ;
V_4 -> V_72 = V_60 ;
V_4 -> V_73 = true ;
F_38 ( & V_11 -> V_57 , V_29 ) ;
if ( V_60 == V_74 ) {
V_16 -> V_75 &= ~ V_76 ;
V_16 -> V_77 &= ~ V_76 ;
F_6 ( V_11 , V_16 -> V_66 , V_78 ) ;
F_6 ( V_11 , V_16 -> V_68 , V_79 ) ;
F_6 ( V_11 , V_16 -> V_70 , V_80 ) ;
} else {
V_16 -> V_75 |= V_76 ;
V_16 -> V_77 |= V_76 ;
F_6 ( V_11 , V_16 -> V_66 , V_81 ) ;
F_6 ( V_11 , V_16 -> V_68 , V_82 ) ;
F_6 ( V_11 , V_16 -> V_70 , V_83 ) ;
}
case V_84 :
F_6 ( V_11 , V_16 -> V_85 , F_15 ( V_4 -> V_26 ) ) ;
F_6 ( V_11 , V_16 -> V_86 , F_14 ( V_4 -> V_26 ) ) ;
F_6 ( V_11 , V_16 -> V_75 | ( V_16 -> V_77 << 2 ) ,
F_20 ( V_4 -> V_26 ) ) ;
F_6 ( V_11 , V_16 -> V_20 , F_16 ( V_4 -> V_26 ) ) ;
F_17 ( V_11 -> V_27 , L_12
L_13 , V_28 , V_4 -> V_26 ,
V_16 -> V_86 , V_16 -> V_85 , V_16 -> V_20 ) ;
break;
case V_9 :
case V_87 :
if ( V_16 -> V_23 == V_24 ) {
F_6 ( V_11 , V_4 -> V_88 ,
F_15 ( V_4 -> V_26 ) ) ;
F_6 ( V_11 , V_4 -> V_89 ,
F_20 ( V_4 -> V_26 ) ) ;
F_17 ( V_11 -> V_27 , L_14
L_15 ,
V_28 , V_4 -> V_26 , V_16 -> V_18 , V_16 -> V_90 ,
V_16 -> V_20 , V_4 -> V_88 ) ;
} else if ( V_16 -> V_23 == V_91 ) {
F_6 ( V_11 , V_4 -> V_88 ,
F_14 ( V_4 -> V_26 ) ) ;
F_6 ( V_11 , V_4 -> V_92 ,
F_20 ( V_4 -> V_26 ) ) ;
F_17 ( V_11 -> V_27 , L_14
L_16 ,
V_28 , V_4 -> V_26 , V_16 -> V_18 , V_16 -> V_90 ,
V_16 -> V_20 , V_4 -> V_88 ) ;
} else {
F_39 ( V_11 -> V_27 , L_17 ,
V_28 , V_4 -> V_26 ) ;
return - V_93 ;
}
F_12 ( V_16 ) ;
break;
default:
return - V_93 ;
}
F_18 ( V_16 ) ;
return 0 ;
}
static void F_40 ( unsigned long V_37 )
{
struct V_1 * V_4 = ( void * ) V_37 ;
struct V_10 * V_11 = V_4 -> V_11 ;
struct V_5 * V_6 ;
F_31 ( & V_11 -> V_57 ) ;
if ( F_4 ( & V_4 -> V_7 ) ) {
goto V_58;
}
V_6 = F_5 ( & V_4 -> V_7 , struct V_5 , V_8 ) ;
if ( V_6 -> V_6 . V_94 )
V_6 -> V_6 . V_94 ( V_6 -> V_6 . V_95 ) ;
if ( F_3 ( V_4 ) )
goto V_58;
else
F_41 ( & V_6 -> V_6 ) ;
if ( V_4 -> V_73 ) {
V_11 -> V_63 [ V_4 -> V_72 ] . V_64 -- ;
V_4 -> V_73 = false ;
}
F_42 ( V_4 -> V_7 . V_96 , & V_4 -> V_97 ) ;
if ( ! F_4 ( & V_4 -> V_98 ) ) {
V_6 = F_5 ( & V_4 -> V_98 , struct V_5 ,
V_8 ) ;
F_42 ( V_4 -> V_98 . V_96 , & V_4 -> V_7 ) ;
if ( F_36 ( V_6 ) < 0 )
F_43 ( V_11 -> V_27 , L_18 ,
V_28 , V_4 -> V_26 ) ;
}
V_58:
F_32 ( & V_11 -> V_57 ) ;
}
static int F_44 ( struct V_2 * V_3 , enum V_99 V_100 ,
unsigned long V_101 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_102 * V_103 = ( void * ) V_101 ;
struct V_10 * V_11 = V_4 -> V_11 ;
unsigned long V_29 ;
unsigned int V_104 = 0 ;
switch ( V_100 ) {
case V_105 :
F_24 ( V_4 ) ;
F_37 ( & V_11 -> V_57 , V_29 ) ;
F_45 ( & V_4 -> V_7 , & V_4 -> V_97 ) ;
F_45 ( & V_4 -> V_98 , & V_4 -> V_97 ) ;
F_38 ( & V_11 -> V_57 , V_29 ) ;
return 0 ;
case V_106 :
if ( V_103 -> V_23 == V_24 ) {
V_4 -> V_88 = V_103 -> V_107 ;
V_4 -> V_108 = V_103 -> V_109 ;
V_4 -> V_110 = V_103 -> V_111 ;
} else {
V_4 -> V_88 = V_103 -> V_112 ;
V_4 -> V_108 = V_103 -> V_113 ;
V_4 -> V_110 = V_103 -> V_114 ;
}
switch ( V_4 -> V_110 ) {
case V_115 :
V_104 = V_116 ;
break;
case V_117 :
V_104 = V_118 ;
break;
default:
case V_119 :
V_104 = V_120 ;
break;
}
V_4 -> V_15 = 1 ;
if ( ! F_10 ( V_4 ) )
return - V_93 ;
V_4 -> V_89 = ( V_104 | V_121 ) |
( ( V_120 | V_122 ) << 2 ) |
V_123 ;
V_4 -> V_92 =
( V_120 | V_122 ) |
( ( V_104 | V_121 ) << 2 ) | V_123 ;
F_6 ( V_11 , V_4 -> V_124 ,
F_46 ( V_4 -> V_26 ) ) ;
F_6 ( V_11 , V_4 -> V_108 *
V_4 -> V_110 , F_47 ( V_4 -> V_26 ) ) ;
return 0 ;
default:
return - V_125 ;
}
return - V_93 ;
}
static enum V_126 F_48 ( struct V_2 * V_3 ,
T_3 V_127 ,
struct V_128 * V_129 )
{
return F_49 ( V_3 , V_127 , V_129 ) ;
}
static T_3 F_50 ( struct V_130 * V_131 )
{
struct V_1 * V_4 = F_1 ( V_131 -> V_3 ) ;
struct V_10 * V_11 = V_4 -> V_11 ;
T_3 V_127 ;
unsigned long V_29 ;
F_37 ( & V_11 -> V_57 , V_29 ) ;
F_42 ( V_4 -> V_97 . V_96 , & V_4 -> V_98 ) ;
V_127 = F_51 ( V_131 ) ;
F_38 ( & V_11 -> V_57 , V_29 ) ;
return V_127 ;
}
static int F_52 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_132 * V_37 = V_3 -> V_133 ;
if ( V_37 != NULL )
V_4 -> V_124 = V_37 -> V_124 ;
while ( V_4 -> V_134 < V_135 ) {
struct V_5 * V_6 ;
V_6 = F_53 ( sizeof( * V_6 ) , V_136 ) ;
if ( ! V_6 )
break;
F_54 ( & V_6 -> V_6 , sizeof( struct V_130 ) ) ;
F_55 ( & V_6 -> V_6 , V_3 ) ;
V_6 -> V_6 . V_137 = F_50 ;
V_6 -> V_6 . V_29 = V_138 ;
V_6 -> V_139 = V_140 ;
F_56 ( & V_6 -> V_8 , & V_4 -> V_97 ) ;
V_4 -> V_134 ++ ;
}
if ( ! V_4 -> V_134 )
return - V_141 ;
return V_4 -> V_134 ;
}
static void F_57 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_10 * V_11 = V_4 -> V_11 ;
struct V_5 * V_6 , * V_142 ;
unsigned long V_29 ;
F_37 ( & V_11 -> V_57 , V_29 ) ;
F_24 ( V_4 ) ;
F_45 ( & V_4 -> V_7 , & V_4 -> V_97 ) ;
F_45 ( & V_4 -> V_98 , & V_4 -> V_97 ) ;
F_38 ( & V_11 -> V_57 , V_29 ) ;
F_58 (desc, _desc, &imxdmac->ld_free, node) {
F_59 ( V_6 ) ;
V_4 -> V_134 -- ;
}
F_60 ( & V_4 -> V_97 ) ;
if ( V_4 -> V_143 ) {
F_59 ( V_4 -> V_143 ) ;
V_4 -> V_143 = NULL ;
}
}
static struct V_130 * F_61 (
struct V_2 * V_3 , struct V_17 * V_144 ,
unsigned int V_145 , enum V_146 V_23 ,
unsigned long V_29 , void * V_147 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_17 * V_18 ;
int V_42 , V_148 = 0 ;
struct V_5 * V_6 ;
if ( F_4 ( & V_4 -> V_97 ) ||
F_3 ( V_4 ) )
return NULL ;
V_6 = F_5 ( & V_4 -> V_97 , struct V_5 , V_8 ) ;
F_62 (sgl, sg, sg_len, i) {
V_148 += V_18 -> V_21 ;
}
switch ( V_4 -> V_110 ) {
case V_119 :
if ( V_144 -> V_21 & 3 || V_144 -> V_25 & 3 )
return NULL ;
break;
case V_117 :
if ( V_144 -> V_21 & 1 || V_144 -> V_25 & 1 )
return NULL ;
break;
case V_115 :
break;
default:
return NULL ;
}
V_6 -> type = V_87 ;
V_6 -> V_18 = V_144 ;
V_6 -> V_90 = V_145 ;
V_6 -> V_20 = V_148 ;
V_6 -> V_23 = V_23 ;
if ( V_23 == V_24 ) {
V_6 -> V_85 = V_4 -> V_88 ;
} else {
V_6 -> V_86 = V_4 -> V_88 ;
}
V_6 -> V_6 . V_94 = NULL ;
V_6 -> V_6 . V_95 = NULL ;
return & V_6 -> V_6 ;
}
static struct V_130 * F_63 (
struct V_2 * V_3 , T_4 V_149 , T_5 V_150 ,
T_5 V_151 , enum V_146 V_23 ,
void * V_147 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_10 * V_11 = V_4 -> V_11 ;
struct V_5 * V_6 ;
int V_42 ;
unsigned int V_152 = V_150 / V_151 ;
F_17 ( V_11 -> V_27 , L_19 ,
V_28 , V_4 -> V_26 , V_150 , V_151 ) ;
if ( F_4 ( & V_4 -> V_97 ) ||
F_3 ( V_4 ) )
return NULL ;
V_6 = F_5 ( & V_4 -> V_97 , struct V_5 , V_8 ) ;
if ( V_4 -> V_143 )
F_59 ( V_4 -> V_143 ) ;
V_4 -> V_143 = F_64 ( V_152 + 1 ,
sizeof( struct V_17 ) , V_136 ) ;
if ( ! V_4 -> V_143 )
return NULL ;
F_65 ( V_4 -> V_143 , V_152 ) ;
for ( V_42 = 0 ; V_42 < V_152 ; V_42 ++ ) {
V_4 -> V_143 [ V_42 ] . V_153 = 0 ;
V_4 -> V_143 [ V_42 ] . V_13 = 0 ;
V_4 -> V_143 [ V_42 ] . V_25 = V_149 ;
V_4 -> V_143 [ V_42 ] . V_21 = V_151 ;
V_149 += V_151 ;
}
V_4 -> V_143 [ V_152 ] . V_13 = 0 ;
V_4 -> V_143 [ V_152 ] . V_21 = 0 ;
V_4 -> V_143 [ V_152 ] . V_153 =
( ( unsigned long ) V_4 -> V_143 | 0x01 ) & ~ 0x02 ;
V_6 -> type = V_9 ;
V_6 -> V_18 = V_4 -> V_143 ;
V_6 -> V_90 = V_152 ;
V_6 -> V_20 = V_22 ;
V_6 -> V_23 = V_23 ;
if ( V_23 == V_24 ) {
V_6 -> V_85 = V_4 -> V_88 ;
} else {
V_6 -> V_86 = V_4 -> V_88 ;
}
V_6 -> V_6 . V_94 = NULL ;
V_6 -> V_6 . V_95 = NULL ;
return & V_6 -> V_6 ;
}
static struct V_130 * F_66 (
struct V_2 * V_3 , T_4 V_86 ,
T_4 V_85 , T_5 V_20 , unsigned long V_29 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_10 * V_11 = V_4 -> V_11 ;
struct V_5 * V_6 ;
F_17 ( V_11 -> V_27 , L_20 ,
V_28 , V_4 -> V_26 , V_85 , V_86 , V_20 ) ;
if ( F_4 ( & V_4 -> V_97 ) ||
F_3 ( V_4 ) )
return NULL ;
V_6 = F_5 ( & V_4 -> V_97 , struct V_5 , V_8 ) ;
V_6 -> type = V_84 ;
V_6 -> V_85 = V_85 ;
V_6 -> V_86 = V_86 ;
V_6 -> V_20 = V_20 ;
V_6 -> V_23 = V_154 ;
V_6 -> V_77 = V_120 | V_122 ;
V_6 -> V_75 = V_120 | V_122 ;
V_6 -> V_6 . V_94 = NULL ;
V_6 -> V_6 . V_95 = NULL ;
return & V_6 -> V_6 ;
}
static struct V_130 * F_67 (
struct V_2 * V_3 , struct V_155 * V_156 ,
unsigned long V_29 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_10 * V_11 = V_4 -> V_11 ;
struct V_5 * V_6 ;
F_17 ( V_11 -> V_27 , L_21
L_22 , V_28 ,
V_4 -> V_26 , V_156 -> V_157 , V_156 -> V_158 ,
V_156 -> V_159 ? L_23 : L_24 , V_156 -> V_160 ? L_23 : L_24 ,
V_156 -> V_161 , V_156 -> V_162 ) ;
if ( F_4 ( & V_4 -> V_97 ) ||
F_3 ( V_4 ) )
return NULL ;
if ( V_156 -> V_162 != 1 || V_156 -> V_161 <= 0 || V_156 -> V_163 != V_154 )
return NULL ;
V_6 = F_5 ( & V_4 -> V_97 , struct V_5 , V_8 ) ;
V_6 -> type = V_61 ;
V_6 -> V_85 = V_156 -> V_157 ;
V_6 -> V_86 = V_156 -> V_158 ;
V_6 -> V_66 = V_156 -> V_144 [ 0 ] . V_164 ;
V_6 -> V_68 = V_156 -> V_161 ;
V_6 -> V_70 = V_156 -> V_144 [ 0 ] . V_165 + V_6 -> V_66 ;
V_6 -> V_20 = V_6 -> V_66 * V_6 -> V_68 ;
V_6 -> V_23 = V_154 ;
V_6 -> V_77 = V_120 ;
V_6 -> V_75 = V_120 ;
if ( V_156 -> V_159 )
V_6 -> V_75 |= V_166 ;
if ( V_156 -> V_160 )
V_6 -> V_77 |= V_166 ;
V_6 -> V_6 . V_94 = NULL ;
V_6 -> V_6 . V_95 = NULL ;
return & V_6 -> V_6 ;
}
static void F_68 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_10 * V_11 = V_4 -> V_11 ;
struct V_5 * V_6 ;
unsigned long V_29 ;
F_37 ( & V_11 -> V_57 , V_29 ) ;
if ( F_4 ( & V_4 -> V_7 ) &&
! F_4 ( & V_4 -> V_98 ) ) {
V_6 = F_5 ( & V_4 -> V_98 ,
struct V_5 , V_8 ) ;
if ( F_36 ( V_6 ) < 0 ) {
F_43 ( V_11 -> V_27 ,
L_25 ,
V_28 , V_4 -> V_26 ) ;
} else {
F_42 ( V_4 -> V_98 . V_96 ,
& V_4 -> V_7 ) ;
}
}
F_38 ( & V_11 -> V_57 , V_29 ) ;
}
static int T_6 F_69 ( struct V_167 * V_168 )
{
struct V_10 * V_11 ;
int V_169 , V_42 ;
V_11 = F_53 ( sizeof( * V_11 ) , V_136 ) ;
if ( ! V_11 )
return - V_141 ;
if ( F_70 () ) {
V_11 -> V_14 = F_71 ( V_170 ) ;
} else if ( F_21 () ) {
V_11 -> V_14 = F_72 ( V_171 ) ;
} else if ( F_11 () ) {
V_11 -> V_14 = F_73 ( V_172 ) ;
} else {
F_59 ( V_11 ) ;
return 0 ;
}
V_11 -> V_173 = F_74 ( NULL , L_26 ) ;
if ( F_75 ( V_11 -> V_173 ) )
return F_76 ( V_11 -> V_173 ) ;
F_77 ( V_11 -> V_173 ) ;
F_6 ( V_11 , V_174 , V_175 ) ;
if ( F_70 () ) {
V_169 = F_78 ( V_176 , F_35 , 0 , L_27 , V_11 ) ;
if ( V_169 ) {
F_43 ( V_11 -> V_27 , L_28 ) ;
F_59 ( V_11 ) ;
return V_169 ;
}
V_169 = F_78 ( V_177 , F_28 , 0 , L_27 , V_11 ) ;
if ( V_169 ) {
F_43 ( V_11 -> V_27 , L_29 ) ;
F_79 ( V_176 , NULL ) ;
F_59 ( V_11 ) ;
return V_169 ;
}
}
F_6 ( V_11 , V_178 , V_175 ) ;
F_6 ( V_11 , ( 1 << V_50 ) - 1 , V_30 ) ;
F_6 ( V_11 , ( 1 << V_50 ) - 1 , V_31 ) ;
F_60 ( & V_11 -> V_179 . V_180 ) ;
F_80 ( V_181 , V_11 -> V_179 . V_182 ) ;
F_80 ( V_183 , V_11 -> V_179 . V_182 ) ;
F_80 ( V_184 , V_11 -> V_179 . V_182 ) ;
F_80 ( V_185 , V_11 -> V_179 . V_182 ) ;
for ( V_42 = 0 ; V_42 < V_62 ; V_42 ++ )
V_11 -> V_63 [ V_42 ] . V_64 = 0 ;
F_81 ( & V_11 -> V_57 ) ;
for ( V_42 = 0 ; V_42 < V_50 ; V_42 ++ ) {
struct V_1 * V_4 = & V_11 -> V_26 [ V_42 ] ;
if ( F_21 () || F_11 () ) {
V_169 = F_78 ( V_186 + V_42 ,
F_35 , 0 , L_27 , V_11 ) ;
if ( V_169 ) {
F_43 ( V_11 -> V_27 , L_30
L_31 ,
V_186 + V_42 , V_42 ) ;
goto V_187;
}
F_82 ( & V_4 -> V_36 ) ;
V_4 -> V_36 . V_188 = & F_26 ;
V_4 -> V_36 . V_37 = ( unsigned long ) V_4 ;
}
V_4 -> V_11 = V_11 ;
F_60 ( & V_4 -> V_98 ) ;
F_60 ( & V_4 -> V_97 ) ;
F_60 ( & V_4 -> V_7 ) ;
F_83 ( & V_4 -> V_38 , F_40 ,
( unsigned long ) V_4 ) ;
V_4 -> V_3 . V_189 = & V_11 -> V_179 ;
F_84 ( & V_4 -> V_3 ) ;
V_4 -> V_26 = V_42 ;
F_56 ( & V_4 -> V_3 . V_190 ,
& V_11 -> V_179 . V_180 ) ;
}
V_11 -> V_27 = & V_168 -> V_27 ;
V_11 -> V_179 . V_27 = & V_168 -> V_27 ;
V_11 -> V_179 . V_191 = F_52 ;
V_11 -> V_179 . V_192 = F_57 ;
V_11 -> V_179 . V_193 = F_48 ;
V_11 -> V_179 . V_194 = F_61 ;
V_11 -> V_179 . V_195 = F_63 ;
V_11 -> V_179 . V_196 = F_66 ;
V_11 -> V_179 . V_197 = F_67 ;
V_11 -> V_179 . V_198 = F_44 ;
V_11 -> V_179 . V_199 = F_68 ;
F_85 ( V_168 , V_11 ) ;
V_11 -> V_179 . V_200 = 2 ;
V_11 -> V_179 . V_27 -> V_201 = & V_11 -> V_201 ;
F_86 ( V_11 -> V_179 . V_27 , 0xffffff ) ;
V_169 = F_87 ( & V_11 -> V_179 ) ;
if ( V_169 ) {
F_39 ( & V_168 -> V_27 , L_32 ) ;
goto V_187;
}
return 0 ;
V_187:
if ( F_21 () || F_11 () ) {
while ( -- V_42 >= 0 )
F_79 ( V_186 + V_42 , NULL ) ;
} else if cpu_is_mx1() {
F_79 ( V_176 , NULL ) ;
F_79 ( V_177 , NULL ) ;
}
F_59 ( V_11 ) ;
return V_169 ;
}
static int T_7 F_88 ( struct V_167 * V_168 )
{
struct V_10 * V_11 = F_89 ( V_168 ) ;
int V_42 ;
F_90 ( & V_11 -> V_179 ) ;
if ( F_21 () || F_11 () ) {
for ( V_42 = 0 ; V_42 < V_50 ; V_42 ++ )
F_79 ( V_186 + V_42 , NULL ) ;
} else if cpu_is_mx1() {
F_79 ( V_176 , NULL ) ;
F_79 ( V_177 , NULL ) ;
}
F_59 ( V_11 ) ;
return 0 ;
}
static int T_6 F_91 ( void )
{
return F_92 ( & V_202 , F_69 ) ;
}
