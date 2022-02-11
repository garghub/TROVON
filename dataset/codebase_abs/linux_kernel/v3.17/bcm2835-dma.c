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
unsigned long V_35 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
enum V_71 V_72 ;
struct V_10 * V_3 ;
T_4 V_73 ;
unsigned int V_74 , V_75 ;
unsigned int V_76 ;
if ( ! F_33 ( V_70 ) ) {
F_34 ( V_9 -> V_17 -> V_18 , L_4 , V_77 ) ;
return NULL ;
}
if ( V_70 == V_51 ) {
V_73 = V_7 -> V_78 . V_79 ;
V_72 = V_7 -> V_78 . V_80 ;
V_75 = V_81 ;
} else {
V_73 = V_7 -> V_78 . V_82 ;
V_72 = V_7 -> V_78 . V_83 ;
V_75 = V_84 ;
}
switch ( V_72 ) {
case V_85 :
V_74 = V_86 ;
break;
default:
return NULL ;
}
V_3 = F_35 ( sizeof( * V_3 ) , V_87 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_50 = V_70 ;
V_3 -> V_44 = V_67 / V_68 ;
V_3 -> V_19 = V_3 -> V_44 * sizeof( struct V_45 ) ;
V_3 -> V_20 = F_36 ( V_9 -> V_17 -> V_18 ,
V_3 -> V_19 , & V_3 -> V_21 ,
V_87 ) ;
if ( ! V_3 -> V_20 ) {
F_7 ( V_3 ) ;
return NULL ;
}
for ( V_76 = 0 ; V_76 < V_3 -> V_44 ; V_76 ++ ) {
struct V_45 * V_46 =
& V_3 -> V_20 [ V_76 ] ;
if ( V_3 -> V_50 == V_51 ) {
V_46 -> V_88 = V_89 ;
V_46 -> V_53 = V_73 ;
V_46 -> V_52 = V_66 + V_76 * V_68 ;
} else {
V_46 -> V_88 = V_90 ;
V_46 -> V_53 = V_66 + V_76 * V_68 ;
V_46 -> V_52 = V_73 ;
}
V_46 -> V_88 |= V_91 ;
if ( V_75 != 0 )
V_46 -> V_88 |= V_75 ;
if ( V_7 -> V_92 != 0 )
V_46 -> V_88 |=
F_37 ( V_7 -> V_92 ) ;
V_46 -> V_48 = V_68 ;
V_3 -> V_41 += V_46 -> V_48 ;
V_46 -> V_93 = V_3 -> V_21 +
sizeof( struct V_45 )
* ( ( V_76 + 1 ) % V_3 -> V_44 ) ;
}
return F_38 ( & V_7 -> V_8 , & V_3 -> V_13 , V_35 ) ;
}
static int F_39 ( struct V_5 * V_7 ,
struct V_94 * V_78 )
{
if ( ( V_78 -> V_70 == V_51 &&
V_78 -> V_80 != V_85 ) ||
( V_78 -> V_70 == V_62 &&
V_78 -> V_83 != V_85 ) ||
! F_33 ( V_78 -> V_70 ) ) {
return - V_95 ;
}
V_7 -> V_78 = * V_78 ;
return 0 ;
}
static int F_40 ( struct V_5 * V_7 )
{
struct V_1 * V_3 = F_1 ( V_7 -> V_8 . V_9 . V_17 ) ;
unsigned long V_35 ;
int V_24 = 10000 ;
F_41 ( V_96 ) ;
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
F_45 ( & V_7 -> V_8 , & V_96 ) ;
F_18 ( & V_7 -> V_8 . V_36 , V_35 ) ;
F_46 ( & V_7 -> V_8 , & V_96 ) ;
return 0 ;
}
static int F_47 ( struct V_6 * V_9 , enum V_97 V_98 ,
unsigned long V_99 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
switch ( V_98 ) {
case V_100 :
return F_39 ( V_7 ,
(struct V_94 * ) V_99 ) ;
case V_101 :
return F_40 ( V_7 ) ;
default:
return - V_102 ;
}
}
static int F_48 ( struct V_1 * V_3 , int V_103 , int V_33 )
{
struct V_5 * V_7 ;
V_7 = F_49 ( V_3 -> V_4 . V_18 , sizeof( * V_7 ) , V_104 ) ;
if ( ! V_7 )
return - V_105 ;
V_7 -> V_8 . V_106 = F_5 ;
F_50 ( & V_7 -> V_8 , & V_3 -> V_4 ) ;
F_51 ( & V_7 -> V_31 ) ;
V_3 -> V_4 . V_107 ++ ;
V_7 -> V_22 = F_52 ( V_3 -> V_108 , V_103 ) ;
V_7 -> V_39 = V_103 ;
V_7 -> V_40 = V_33 ;
return 0 ;
}
static void F_53 ( struct V_1 * V_109 )
{
struct V_5 * V_7 , * V_93 ;
F_54 (c, next, &od->ddev.channels,
vc.chan.device_node) {
F_14 ( & V_7 -> V_8 . V_9 . V_110 ) ;
F_55 ( & V_7 -> V_8 . V_111 ) ;
}
}
static struct V_6 * F_56 ( struct V_112 * V_113 ,
struct V_114 * V_115 )
{
struct V_1 * V_3 = V_115 -> V_116 ;
struct V_6 * V_9 ;
V_9 = F_57 ( & V_3 -> V_4 ) ;
if ( ! V_9 )
return NULL ;
F_3 ( V_9 ) -> V_92 = V_113 -> args [ 0 ] ;
return V_9 ;
}
static int F_58 ( struct V_6 * V_117 ,
struct V_118 * V_119 )
{
V_119 -> V_120 = F_59 ( V_85 ) ;
V_119 -> V_121 = F_59 ( V_85 ) ;
V_119 -> V_122 = F_59 ( V_51 ) | F_59 ( V_62 ) ;
V_119 -> V_123 = false ;
V_119 -> V_124 = true ;
return 0 ;
}
static int F_60 ( struct V_125 * V_126 )
{
struct V_1 * V_109 ;
struct V_127 * V_128 ;
void T_1 * V_108 ;
int V_129 ;
int V_43 ;
int V_33 ;
T_6 V_130 ;
if ( ! V_126 -> V_18 . V_131 )
V_126 -> V_18 . V_131 = & V_126 -> V_18 . V_132 ;
V_129 = F_61 ( & V_126 -> V_18 , F_62 ( 32 ) ) ;
if ( V_129 )
return V_129 ;
V_109 = F_49 ( & V_126 -> V_18 , sizeof( * V_109 ) , V_104 ) ;
if ( ! V_109 )
return - V_105 ;
V_126 -> V_18 . V_133 = & V_109 -> V_133 ;
F_63 ( & V_126 -> V_18 , 0x3FFFFFFF ) ;
V_128 = F_64 ( V_126 , V_134 , 0 ) ;
V_108 = F_65 ( & V_126 -> V_18 , V_128 ) ;
if ( F_66 ( V_108 ) )
return F_67 ( V_108 ) ;
V_109 -> V_108 = V_108 ;
F_68 ( V_135 , V_109 -> V_4 . V_136 ) ;
F_68 ( V_137 , V_109 -> V_4 . V_136 ) ;
F_68 ( V_138 , V_109 -> V_4 . V_136 ) ;
V_109 -> V_4 . V_139 = F_19 ;
V_109 -> V_4 . V_140 = F_22 ;
V_109 -> V_4 . V_141 = F_27 ;
V_109 -> V_4 . V_142 = F_30 ;
V_109 -> V_4 . V_143 = F_58 ;
V_109 -> V_4 . V_144 = F_32 ;
V_109 -> V_4 . V_145 = F_47 ;
V_109 -> V_4 . V_18 = & V_126 -> V_18 ;
F_51 ( & V_109 -> V_4 . V_146 ) ;
F_69 ( & V_109 -> V_36 ) ;
F_70 ( V_126 , V_109 ) ;
if ( F_71 ( V_126 -> V_18 . V_147 ,
L_6 ,
& V_130 ) ) {
F_34 ( & V_126 -> V_18 , L_7 ) ;
V_129 = - V_95 ;
goto V_148;
}
V_130 &= ~ ( V_149 | V_150 ) ;
for ( V_43 = 0 ; V_43 < V_126 -> V_151 ; V_43 ++ ) {
V_33 = F_72 ( V_126 , V_43 ) ;
if ( V_33 < 0 )
break;
if ( V_130 & ( 1 << V_43 ) ) {
V_129 = F_48 ( V_109 , V_43 , V_33 ) ;
if ( V_129 )
goto V_148;
}
}
F_20 ( & V_126 -> V_18 , L_8 , V_43 ) ;
V_129 = F_73 ( V_126 -> V_18 . V_147 ,
F_56 , V_109 ) ;
if ( V_129 ) {
F_34 ( & V_126 -> V_18 , L_9 ) ;
goto V_148;
}
V_129 = F_74 ( & V_109 -> V_4 ) ;
if ( V_129 ) {
F_34 ( & V_126 -> V_18 ,
L_10 , V_129 ) ;
goto V_148;
}
F_20 ( & V_126 -> V_18 , L_11 ) ;
return 0 ;
V_148:
F_53 ( V_109 ) ;
return V_129 ;
}
static int F_75 ( struct V_125 * V_126 )
{
struct V_1 * V_109 = F_76 ( V_126 ) ;
F_77 ( & V_109 -> V_4 ) ;
F_53 ( V_109 ) ;
return 0 ;
}
