static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 * F_3 ( struct V_6 * V_7 )
{
return F_2 ( V_7 , struct V_5 , V_8 . V_9 ) ;
}
static inline struct V_10 * F_4 (
struct V_11 * V_12 )
{
return F_2 ( V_12 , struct V_10 , V_13 . V_14 ) ;
}
static void F_5 ( struct V_15 * V_13 )
{
struct V_10 * V_16 = F_2 ( V_13 , struct V_10 , V_13 ) ;
F_6 ( V_16 -> V_13 . V_14 . V_9 -> V_17 -> V_18 ,
V_16 -> V_19 ,
V_16 -> V_20 ,
V_16 -> V_21 ) ;
F_7 ( V_16 ) ;
}
static int F_8 ( void T_1 * V_22 )
{
unsigned long V_23 ;
long int V_24 = 10000 ;
V_23 = F_9 ( V_22 + V_25 ) ;
if ( ! ( V_23 & V_26 ) )
return 0 ;
F_10 ( 0 , V_22 + V_25 ) ;
while ( ( V_23 & V_27 ) && -- V_24 ) {
F_11 () ;
V_23 = F_9 ( V_22 + V_25 ) ;
}
if ( ! V_24 )
return - V_28 ;
if ( ! ( V_23 & V_26 ) )
return 0 ;
F_10 ( 0 , V_22 + V_29 ) ;
F_10 ( V_30 | V_26 ,
V_22 + V_25 ) ;
return 0 ;
}
static void F_12 ( struct V_5 * V_7 )
{
struct V_15 * V_13 = F_13 ( & V_7 -> V_8 ) ;
struct V_10 * V_3 ;
if ( ! V_13 ) {
V_7 -> V_16 = NULL ;
return;
}
F_14 ( & V_13 -> V_31 ) ;
V_7 -> V_16 = V_3 = F_4 ( & V_13 -> V_14 ) ;
F_10 ( V_3 -> V_21 , V_7 -> V_22 + V_32 ) ;
F_10 ( V_26 , V_7 -> V_22 + V_25 ) ;
}
static T_2 F_15 ( int V_33 , void * V_34 )
{
struct V_5 * V_7 = V_34 ;
struct V_10 * V_3 ;
unsigned long V_35 ;
F_16 ( & V_7 -> V_8 . V_36 , V_35 ) ;
F_10 ( V_37 , V_7 -> V_22 + V_25 ) ;
V_3 = V_7 -> V_16 ;
if ( V_3 ) {
F_17 ( & V_3 -> V_13 ) ;
}
F_10 ( V_26 , V_7 -> V_22 + V_25 ) ;
F_18 ( & V_7 -> V_8 . V_36 , V_35 ) ;
return V_38 ;
}
static int F_19 ( struct V_6 * V_9 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
F_20 ( V_7 -> V_8 . V_9 . V_17 -> V_18 ,
L_1 , V_7 -> V_39 ) ;
return F_21 ( V_7 -> V_40 ,
F_15 , 0 , L_2 , V_7 ) ;
}
static void F_22 ( struct V_6 * V_9 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
F_23 ( & V_7 -> V_8 ) ;
F_24 ( V_7 -> V_40 , V_7 ) ;
F_20 ( V_7 -> V_8 . V_9 . V_17 -> V_18 , L_3 , V_7 -> V_39 ) ;
}
static T_3 F_25 ( struct V_10 * V_3 )
{
return V_3 -> V_41 ;
}
static T_3 F_26 ( struct V_10 * V_3 , T_4 V_42 )
{
unsigned int V_43 ;
T_3 V_41 ;
for ( V_41 = V_43 = 0 ; V_43 < V_3 -> V_44 ; V_43 ++ ) {
struct V_45 * V_46 =
& V_3 -> V_20 [ V_43 ] ;
T_3 V_47 = V_46 -> V_48 ;
T_4 V_49 ;
if ( V_3 -> V_50 == V_51 )
V_49 = V_46 -> V_52 ;
else
V_49 = V_46 -> V_53 ;
if ( V_41 )
V_41 += V_47 ;
else if ( V_42 >= V_49 && V_42 < V_49 + V_47 )
V_41 += V_49 + V_47 - V_42 ;
}
return V_41 ;
}
static enum V_54 F_27 ( struct V_6 * V_9 ,
T_5 V_55 , struct V_56 * V_57 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
struct V_15 * V_13 ;
enum V_54 V_58 ;
unsigned long V_35 ;
V_58 = F_28 ( V_9 , V_55 , V_57 ) ;
if ( V_58 == V_59 || ! V_57 )
return V_58 ;
F_16 ( & V_7 -> V_8 . V_36 , V_35 ) ;
V_13 = F_29 ( & V_7 -> V_8 , V_55 ) ;
if ( V_13 ) {
V_57 -> V_60 =
F_25 ( F_4 ( & V_13 -> V_14 ) ) ;
} else if ( V_7 -> V_16 && V_7 -> V_16 -> V_13 . V_14 . V_55 == V_55 ) {
struct V_10 * V_3 = V_7 -> V_16 ;
T_4 V_61 ;
if ( V_3 -> V_50 == V_62 )
V_61 = F_9 ( V_7 -> V_22 + V_63 ) ;
else if ( V_3 -> V_50 == V_51 )
V_61 = F_9 ( V_7 -> V_22 + V_64 ) ;
else
V_61 = 0 ;
V_57 -> V_60 = F_26 ( V_3 , V_61 ) ;
} else {
V_57 -> V_60 = 0 ;
}
F_18 ( & V_7 -> V_8 . V_36 , V_35 ) ;
return V_58 ;
}
static void F_30 ( struct V_6 * V_9 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
unsigned long V_35 ;
V_7 -> V_65 = true ;
F_16 ( & V_7 -> V_8 . V_36 , V_35 ) ;
if ( F_31 ( & V_7 -> V_8 ) && ! V_7 -> V_16 )
F_12 ( V_7 ) ;
F_18 ( & V_7 -> V_8 . V_36 , V_35 ) ;
}
static struct V_11 * F_32 (
struct V_6 * V_9 , T_4 V_66 , T_3 V_67 ,
T_3 V_68 , enum V_69 V_70 ,
unsigned long V_35 , void * V_71 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
enum V_72 V_73 ;
struct V_10 * V_3 ;
T_4 V_74 ;
unsigned int V_75 , V_76 ;
unsigned int V_77 ;
if ( ! F_33 ( V_70 ) ) {
F_34 ( V_9 -> V_17 -> V_18 , L_4 , V_78 ) ;
return NULL ;
}
if ( V_70 == V_51 ) {
V_74 = V_7 -> V_79 . V_80 ;
V_73 = V_7 -> V_79 . V_81 ;
V_76 = V_82 ;
} else {
V_74 = V_7 -> V_79 . V_83 ;
V_73 = V_7 -> V_79 . V_84 ;
V_76 = V_85 ;
}
switch ( V_73 ) {
case V_86 :
V_75 = V_87 ;
break;
default:
return NULL ;
}
V_3 = F_35 ( sizeof( * V_3 ) , V_88 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_50 = V_70 ;
V_3 -> V_44 = V_67 / V_68 ;
V_3 -> V_19 = V_3 -> V_44 * sizeof( struct V_45 ) ;
V_3 -> V_20 = F_36 ( V_9 -> V_17 -> V_18 ,
V_3 -> V_19 , & V_3 -> V_21 ,
V_88 ) ;
if ( ! V_3 -> V_20 ) {
F_7 ( V_3 ) ;
return NULL ;
}
for ( V_77 = 0 ; V_77 < V_3 -> V_44 ; V_77 ++ ) {
struct V_45 * V_46 =
& V_3 -> V_20 [ V_77 ] ;
if ( V_3 -> V_50 == V_51 ) {
V_46 -> V_89 = V_90 ;
V_46 -> V_53 = V_74 ;
V_46 -> V_52 = V_66 + V_77 * V_68 ;
} else {
V_46 -> V_89 = V_91 ;
V_46 -> V_53 = V_66 + V_77 * V_68 ;
V_46 -> V_52 = V_74 ;
}
V_46 -> V_89 |= V_92 ;
if ( V_76 != 0 )
V_46 -> V_89 |= V_76 ;
if ( V_7 -> V_93 != 0 )
V_46 -> V_89 |=
F_37 ( V_7 -> V_93 ) ;
V_46 -> V_48 = V_68 ;
V_3 -> V_41 += V_46 -> V_48 ;
V_46 -> V_94 = V_3 -> V_21 +
sizeof( struct V_45 )
* ( ( V_77 + 1 ) % V_3 -> V_44 ) ;
}
return F_38 ( & V_7 -> V_8 , & V_3 -> V_13 , V_35 ) ;
}
static int F_39 ( struct V_5 * V_7 ,
struct V_95 * V_79 )
{
if ( ( V_79 -> V_70 == V_51 &&
V_79 -> V_81 != V_86 ) ||
( V_79 -> V_70 == V_62 &&
V_79 -> V_84 != V_86 ) ||
! F_33 ( V_79 -> V_70 ) ) {
return - V_96 ;
}
V_7 -> V_79 = * V_79 ;
return 0 ;
}
static int F_40 ( struct V_5 * V_7 )
{
struct V_1 * V_3 = F_1 ( V_7 -> V_8 . V_9 . V_17 ) ;
unsigned long V_35 ;
int V_24 = 10000 ;
F_41 ( V_97 ) ;
F_16 ( & V_7 -> V_8 . V_36 , V_35 ) ;
F_42 ( & V_3 -> V_36 ) ;
F_43 ( & V_7 -> V_31 ) ;
F_44 ( & V_3 -> V_36 ) ;
if ( V_7 -> V_16 ) {
V_7 -> V_16 = NULL ;
F_8 ( V_7 -> V_22 ) ;
while ( -- V_24 ) {
if ( ! ( F_9 ( V_7 -> V_22 + V_25 ) &
V_26 ) )
break;
F_11 () ;
}
if ( ! V_24 )
F_34 ( V_3 -> V_4 . V_18 , L_5 ) ;
}
F_45 ( & V_7 -> V_8 , & V_97 ) ;
F_18 ( & V_7 -> V_8 . V_36 , V_35 ) ;
F_46 ( & V_7 -> V_8 , & V_97 ) ;
return 0 ;
}
static int F_47 ( struct V_6 * V_9 , enum V_98 V_99 ,
unsigned long V_100 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
switch ( V_99 ) {
case V_101 :
return F_39 ( V_7 ,
(struct V_95 * ) V_100 ) ;
case V_102 :
return F_40 ( V_7 ) ;
default:
return - V_103 ;
}
}
static int F_48 ( struct V_1 * V_3 , int V_104 , int V_33 )
{
struct V_5 * V_7 ;
V_7 = F_49 ( V_3 -> V_4 . V_18 , sizeof( * V_7 ) , V_105 ) ;
if ( ! V_7 )
return - V_106 ;
V_7 -> V_8 . V_107 = F_5 ;
F_50 ( & V_7 -> V_8 , & V_3 -> V_4 ) ;
F_51 ( & V_7 -> V_31 ) ;
V_3 -> V_4 . V_108 ++ ;
V_7 -> V_22 = F_52 ( V_3 -> V_109 , V_104 ) ;
V_7 -> V_39 = V_104 ;
V_7 -> V_40 = V_33 ;
return 0 ;
}
static void F_53 ( struct V_1 * V_110 )
{
struct V_5 * V_7 , * V_94 ;
F_54 (c, next, &od->ddev.channels,
vc.chan.device_node) {
F_14 ( & V_7 -> V_8 . V_9 . V_111 ) ;
F_55 ( & V_7 -> V_8 . V_112 ) ;
}
}
static struct V_6 * F_56 ( struct V_113 * V_114 ,
struct V_115 * V_116 )
{
struct V_1 * V_3 = V_116 -> V_117 ;
struct V_6 * V_9 ;
V_9 = F_57 ( & V_3 -> V_4 ) ;
if ( ! V_9 )
return NULL ;
F_3 ( V_9 ) -> V_93 = V_114 -> args [ 0 ] ;
return V_9 ;
}
static int F_58 ( struct V_6 * V_118 ,
struct V_119 * V_120 )
{
V_120 -> V_121 = F_59 ( V_86 ) ;
V_120 -> V_122 = F_59 ( V_86 ) ;
V_120 -> V_123 = F_59 ( V_51 ) | F_59 ( V_62 ) ;
V_120 -> V_124 = false ;
V_120 -> V_125 = true ;
return 0 ;
}
static int F_60 ( struct V_126 * V_127 )
{
struct V_1 * V_110 ;
struct V_128 * V_129 ;
void T_1 * V_109 ;
int V_130 ;
int V_43 ;
int V_33 ;
T_6 V_131 ;
if ( ! V_127 -> V_18 . V_132 )
V_127 -> V_18 . V_132 = & V_127 -> V_18 . V_133 ;
V_130 = F_61 ( & V_127 -> V_18 , F_62 ( 32 ) ) ;
if ( V_130 )
return V_130 ;
V_110 = F_49 ( & V_127 -> V_18 , sizeof( * V_110 ) , V_105 ) ;
if ( ! V_110 )
return - V_106 ;
V_127 -> V_18 . V_134 = & V_110 -> V_134 ;
F_63 ( & V_127 -> V_18 , 0x3FFFFFFF ) ;
V_129 = F_64 ( V_127 , V_135 , 0 ) ;
V_109 = F_65 ( & V_127 -> V_18 , V_129 ) ;
if ( F_66 ( V_109 ) )
return F_67 ( V_109 ) ;
V_110 -> V_109 = V_109 ;
F_68 ( V_136 , V_110 -> V_4 . V_137 ) ;
F_68 ( V_138 , V_110 -> V_4 . V_137 ) ;
F_68 ( V_139 , V_110 -> V_4 . V_137 ) ;
V_110 -> V_4 . V_140 = F_19 ;
V_110 -> V_4 . V_141 = F_22 ;
V_110 -> V_4 . V_142 = F_27 ;
V_110 -> V_4 . V_143 = F_30 ;
V_110 -> V_4 . V_144 = F_58 ;
V_110 -> V_4 . V_145 = F_32 ;
V_110 -> V_4 . V_146 = F_47 ;
V_110 -> V_4 . V_18 = & V_127 -> V_18 ;
F_51 ( & V_110 -> V_4 . V_147 ) ;
F_69 ( & V_110 -> V_36 ) ;
F_70 ( V_127 , V_110 ) ;
if ( F_71 ( V_127 -> V_18 . V_148 ,
L_6 ,
& V_131 ) ) {
F_34 ( & V_127 -> V_18 , L_7 ) ;
V_130 = - V_96 ;
goto V_149;
}
V_131 &= ~ ( V_150 | V_151 ) ;
for ( V_43 = 0 ; V_43 < V_127 -> V_152 ; V_43 ++ ) {
V_33 = F_72 ( V_127 , V_43 ) ;
if ( V_33 < 0 )
break;
if ( V_131 & ( 1 << V_43 ) ) {
V_130 = F_48 ( V_110 , V_43 , V_33 ) ;
if ( V_130 )
goto V_149;
}
}
F_20 ( & V_127 -> V_18 , L_8 , V_43 ) ;
V_130 = F_73 ( V_127 -> V_18 . V_148 ,
F_56 , V_110 ) ;
if ( V_130 ) {
F_34 ( & V_127 -> V_18 , L_9 ) ;
goto V_149;
}
V_130 = F_74 ( & V_110 -> V_4 ) ;
if ( V_130 ) {
F_34 ( & V_127 -> V_18 ,
L_10 , V_130 ) ;
goto V_149;
}
F_20 ( & V_127 -> V_18 , L_11 ) ;
return 0 ;
V_149:
F_53 ( V_110 ) ;
return V_130 ;
}
static int F_75 ( struct V_126 * V_127 )
{
struct V_1 * V_110 = F_76 ( V_127 ) ;
F_77 ( & V_110 -> V_4 ) ;
F_53 ( V_110 ) ;
return 0 ;
}
