static inline
struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 * F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
return F_2 ( V_6 , struct V_5 , V_7 [ V_3 -> V_8 ] ) ;
}
static void F_4 ( struct V_1 * V_6 )
{
struct V_5 * V_9 = F_3 ( & V_6 -> V_4 ) ;
int V_10 = V_6 -> V_4 . V_8 ;
struct V_11 * V_12 = NULL ;
V_12 = F_5 ( & V_6 -> V_13 , struct V_11 ,
V_14 ) ;
F_6 ( & V_12 -> V_14 , & V_6 -> V_15 ) ;
F_7 ( V_12 -> V_16 , V_9 -> V_17 + V_18 +
V_10 * 4 ) ;
F_7 ( V_10 | ( V_6 -> V_19 << V_20 ) |
( V_12 -> V_21 << V_22 ) ,
V_9 -> V_17 + V_10 * 0x10 + V_23 ) ;
F_7 ( V_12 -> V_24 , V_9 -> V_17 + V_10 * 0x10 +
V_25 ) ;
F_7 ( V_12 -> V_26 , V_9 -> V_17 + V_10 * 0x10 +
V_27 ) ;
F_7 ( F_8 ( V_9 -> V_17 + V_28 ) |
( 1 << V_10 ) , V_9 -> V_17 + V_28 ) ;
F_9 ( V_12 -> V_29 >> 2 , V_9 -> V_17 + V_10 * 0x10 + V_30 ) ;
if ( V_12 -> V_31 ) {
F_9 ( ( 1 << V_10 ) | 1 << ( V_10 + 16 ) |
F_8 ( V_9 -> V_17 + V_32 ) ,
V_9 -> V_17 + V_32 ) ;
V_6 -> V_33 = V_6 -> V_34 = 0 ;
}
}
static T_1 F_10 ( int V_35 , void * V_36 )
{
struct V_5 * V_9 = V_36 ;
struct V_1 * V_6 ;
struct V_11 * V_12 = NULL ;
T_2 V_37 ;
int V_38 ;
V_37 = F_11 ( V_9 -> V_17 + V_39 ) ;
while ( ( V_38 = F_12 ( V_37 ) - 1 ) >= 0 ) {
V_37 &= ~ ( 1 << V_38 ) ;
F_7 ( 1 << V_38 , V_9 -> V_17 + V_39 ) ;
V_6 = & V_9 -> V_7 [ V_38 ] ;
F_13 ( & V_6 -> V_40 ) ;
V_12 = F_5 ( & V_6 -> V_15 , struct V_11 ,
V_14 ) ;
if ( ! V_12 -> V_31 ) {
F_14 ( & V_6 -> V_15 , & V_6 -> V_41 ) ;
if ( ! F_15 ( & V_6 -> V_13 ) )
F_4 ( V_6 ) ;
} else
V_6 -> V_33 ++ ;
F_16 ( & V_6 -> V_40 ) ;
}
F_17 ( & V_9 -> V_42 ) ;
return V_43 ;
}
static void F_18 ( struct V_5 * V_9 )
{
T_3 V_44 = 0 ;
struct V_1 * V_6 ;
struct V_11 * V_12 ;
struct V_45 * V_46 ;
unsigned long V_47 ;
unsigned long V_33 ;
F_19 ( V_48 ) ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_9 -> V_50 . V_51 ; V_49 ++ ) {
V_6 = & V_9 -> V_7 [ V_49 ] ;
F_20 ( & V_6 -> V_40 , V_47 ) ;
if ( ! F_15 ( & V_6 -> V_41 ) ) {
F_14 ( & V_6 -> V_41 , & V_48 ) ;
F_21 ( & V_6 -> V_40 , V_47 ) ;
F_22 (sdesc, &list, node) {
V_46 = & V_12 -> V_46 ;
if ( V_46 -> V_52 )
V_46 -> V_52 ( V_46 -> V_53 ) ;
V_44 = V_46 -> V_54 ;
F_23 ( V_46 ) ;
}
F_20 ( & V_6 -> V_40 , V_47 ) ;
F_14 ( & V_48 , & V_6 -> free ) ;
V_6 -> V_4 . V_55 = V_44 ;
F_21 ( & V_6 -> V_40 , V_47 ) ;
} else {
V_12 = F_5 ( & V_6 -> V_15 , struct V_11 ,
V_14 ) ;
if ( ! V_12 || ( V_12 && ! V_12 -> V_31 ) ) {
F_21 ( & V_6 -> V_40 , V_47 ) ;
continue;
}
V_33 = V_6 -> V_33 ;
F_21 ( & V_6 -> V_40 , V_47 ) ;
V_46 = & V_12 -> V_46 ;
while ( V_33 != V_6 -> V_34 ) {
if ( V_46 -> V_52 )
V_46 -> V_52 ( V_46 -> V_53 ) ;
V_6 -> V_34 ++ ;
}
}
}
}
static void F_24 ( unsigned long V_36 )
{
struct V_5 * V_9 = ( void * ) V_36 ;
F_18 ( V_9 ) ;
}
static T_3 F_25 ( struct V_45 * V_56 )
{
struct V_1 * V_6 = F_1 ( V_56 -> V_4 ) ;
struct V_11 * V_12 ;
unsigned long V_47 ;
T_3 V_54 ;
V_12 = F_2 ( V_56 , struct V_11 , V_46 ) ;
F_20 ( & V_6 -> V_40 , V_47 ) ;
F_6 ( & V_12 -> V_14 , & V_6 -> V_13 ) ;
V_54 = F_26 ( V_56 ) ;
F_21 ( & V_6 -> V_40 , V_47 ) ;
return V_54 ;
}
static int F_27 ( struct V_2 * V_4 ,
struct V_57 * V_58 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
unsigned long V_47 ;
if ( ( V_58 -> V_59 != V_60 ) ||
( V_58 -> V_61 != V_60 ) )
return - V_62 ;
F_20 ( & V_6 -> V_40 , V_47 ) ;
V_6 -> V_19 = ( V_58 -> V_63 == 4 ? 1 : 0 ) ;
F_21 ( & V_6 -> V_40 , V_47 ) ;
return 0 ;
}
static int F_28 ( struct V_2 * V_4 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_5 * V_9 = F_3 ( & V_6 -> V_4 ) ;
int V_10 = V_6 -> V_4 . V_8 ;
unsigned long V_47 ;
F_20 ( & V_6 -> V_40 , V_47 ) ;
if ( ! V_9 -> V_64 ) {
F_7 ( F_8 ( V_9 -> V_17 + V_28 ) &
~ ( 1 << V_10 ) , V_9 -> V_17 + V_28 ) ;
F_7 ( F_8 ( V_9 -> V_17 + V_32 )
& ~ ( ( 1 << V_10 ) | 1 << ( V_10 + 16 ) ) ,
V_9 -> V_17 + V_32 ) ;
} else {
F_7 ( 1 << V_10 , V_9 -> V_17 + V_65 ) ;
F_7 ( ( 1 << V_10 ) | 1 << ( V_10 + 16 ) ,
V_9 -> V_17 + V_66 ) ;
}
F_7 ( 1 << V_10 , V_9 -> V_17 + V_67 ) ;
F_14 ( & V_6 -> V_15 , & V_6 -> free ) ;
F_14 ( & V_6 -> V_13 , & V_6 -> free ) ;
F_21 ( & V_6 -> V_40 , V_47 ) ;
return 0 ;
}
static int F_29 ( struct V_2 * V_4 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_5 * V_9 = F_3 ( & V_6 -> V_4 ) ;
int V_10 = V_6 -> V_4 . V_8 ;
unsigned long V_47 ;
F_20 ( & V_6 -> V_40 , V_47 ) ;
if ( ! V_9 -> V_64 )
F_7 ( F_8 ( V_9 -> V_17 + V_32 )
& ~ ( ( 1 << V_10 ) | 1 << ( V_10 + 16 ) ) ,
V_9 -> V_17 + V_32 ) ;
else
F_7 ( ( 1 << V_10 ) | 1 << ( V_10 + 16 ) ,
V_9 -> V_17 + V_66 ) ;
F_21 ( & V_6 -> V_40 , V_47 ) ;
return 0 ;
}
static int F_30 ( struct V_2 * V_4 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_5 * V_9 = F_3 ( & V_6 -> V_4 ) ;
int V_10 = V_6 -> V_4 . V_8 ;
unsigned long V_47 ;
F_20 ( & V_6 -> V_40 , V_47 ) ;
if ( ! V_9 -> V_64 )
F_7 ( F_8 ( V_9 -> V_17 + V_32 )
| ( ( 1 << V_10 ) | 1 << ( V_10 + 16 ) ) ,
V_9 -> V_17 + V_32 ) ;
else
F_7 ( ( 1 << V_10 ) | 1 << ( V_10 + 16 ) ,
V_9 -> V_17 + V_32 ) ;
F_21 ( & V_6 -> V_40 , V_47 ) ;
return 0 ;
}
static int F_31 ( struct V_2 * V_4 )
{
struct V_5 * V_9 = F_3 ( V_4 ) ;
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_11 * V_12 ;
unsigned long V_47 ;
F_19 ( V_68 ) ;
int V_49 ;
F_32 ( V_9 -> V_50 . V_69 ) ;
for ( V_49 = 0 ; V_49 < V_70 ; V_49 ++ ) {
V_12 = F_33 ( sizeof( * V_12 ) , V_71 ) ;
if ( ! V_12 ) {
F_34 ( V_9 -> V_50 . V_69 , L_1
L_2 , V_49 ) ;
break;
}
F_35 ( & V_12 -> V_46 , V_4 ) ;
V_12 -> V_46 . V_47 = V_72 ;
V_12 -> V_46 . V_73 = F_25 ;
F_36 ( & V_12 -> V_14 , & V_68 ) ;
}
if ( V_49 == 0 )
return - V_74 ;
F_20 ( & V_6 -> V_40 , V_47 ) ;
F_14 ( & V_68 , & V_6 -> free ) ;
F_21 ( & V_6 -> V_40 , V_47 ) ;
return V_49 ;
}
static void F_37 ( struct V_2 * V_4 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_5 * V_9 = F_3 ( V_4 ) ;
struct V_11 * V_12 , * V_75 ;
unsigned long V_47 ;
F_19 ( V_68 ) ;
F_20 ( & V_6 -> V_40 , V_47 ) ;
F_38 ( ! F_15 ( & V_6 -> V_76 ) ) ;
F_38 ( ! F_15 ( & V_6 -> V_13 ) ) ;
F_38 ( ! F_15 ( & V_6 -> V_15 ) ) ;
F_38 ( ! F_15 ( & V_6 -> V_41 ) ) ;
F_14 ( & V_6 -> free , & V_68 ) ;
F_21 ( & V_6 -> V_40 , V_47 ) ;
F_39 (sdesc, tmp, &descs, node)
F_40 ( V_12 ) ;
F_41 ( V_9 -> V_50 . V_69 ) ;
}
static void F_42 ( struct V_2 * V_4 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
unsigned long V_47 ;
F_20 ( & V_6 -> V_40 , V_47 ) ;
if ( F_15 ( & V_6 -> V_15 ) && ! F_15 ( & V_6 -> V_13 ) )
F_4 ( V_6 ) ;
F_21 ( & V_6 -> V_40 , V_47 ) ;
}
static enum V_77
F_43 ( struct V_2 * V_4 , T_3 V_54 ,
struct V_78 * V_79 )
{
struct V_5 * V_9 = F_3 ( V_4 ) ;
struct V_1 * V_6 = F_1 ( V_4 ) ;
unsigned long V_47 ;
enum V_77 V_80 ;
struct V_11 * V_12 ;
int V_10 = V_6 -> V_4 . V_8 ;
unsigned long V_81 ;
unsigned long V_82 ;
unsigned long V_83 ;
F_20 ( & V_6 -> V_40 , V_47 ) ;
V_12 = F_5 ( & V_6 -> V_15 , struct V_11 ,
V_14 ) ;
V_82 = ( V_12 -> V_24 + 1 ) * ( V_12 -> V_26 + 1 ) *
( V_12 -> V_16 * V_84 ) ;
V_80 = F_44 ( V_4 , V_54 , V_79 ) ;
V_81 = F_8 ( V_9 -> V_17 + V_10 * 0x10 + V_30 )
<< 2 ;
V_83 = V_82 - ( V_81 - V_12 -> V_29 ) ;
F_45 ( V_79 , V_83 ) ;
F_21 ( & V_6 -> V_40 , V_47 ) ;
return V_80 ;
}
static struct V_45 * F_46 (
struct V_2 * V_4 , struct V_85 * V_86 ,
unsigned long V_47 )
{
struct V_5 * V_9 = F_3 ( V_4 ) ;
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_11 * V_12 = NULL ;
unsigned long V_87 ;
int V_80 ;
if ( ( V_86 -> V_21 != V_88 ) && ( V_86 -> V_21 != V_89 ) ) {
V_80 = - V_62 ;
goto V_90;
}
F_20 ( & V_6 -> V_40 , V_87 ) ;
if ( ! F_15 ( & V_6 -> free ) ) {
V_12 = F_5 ( & V_6 -> free , struct V_11 ,
V_14 ) ;
F_47 ( & V_12 -> V_14 ) ;
}
F_21 ( & V_6 -> V_40 , V_87 ) ;
if ( ! V_12 ) {
F_18 ( V_9 ) ;
V_80 = 0 ;
goto V_91;
}
F_20 ( & V_6 -> V_40 , V_87 ) ;
if ( ( V_86 -> V_92 == 1 ) && ( V_86 -> V_93 > 0 ) ) {
V_12 -> V_31 = 0 ;
V_12 -> V_24 = V_86 -> V_94 [ 0 ] . V_95 / V_84 ;
V_12 -> V_16 = ( V_86 -> V_94 [ 0 ] . V_95 + V_86 -> V_94 [ 0 ] . V_96 ) /
V_84 ;
V_12 -> V_26 = V_86 -> V_93 - 1 ;
if ( V_86 -> V_21 == V_88 ) {
V_12 -> V_29 = V_86 -> V_97 ;
V_12 -> V_21 = 1 ;
} else {
V_12 -> V_29 = V_86 -> V_98 ;
V_12 -> V_21 = 0 ;
}
F_36 ( & V_12 -> V_14 , & V_6 -> V_76 ) ;
} else {
F_48 ( L_3 ) ;
V_80 = - V_62 ;
goto V_99;
}
F_21 ( & V_6 -> V_40 , V_87 ) ;
return & V_12 -> V_46 ;
V_99:
F_21 ( & V_6 -> V_40 , V_87 ) ;
V_91:
V_90:
return F_49 ( V_80 ) ;
}
static struct V_45 *
F_50 ( struct V_2 * V_4 , T_4 V_29 ,
T_5 V_100 , T_5 V_101 ,
enum V_102 V_103 , unsigned long V_47 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_11 * V_12 = NULL ;
unsigned long V_87 ;
if ( V_100 != 2 * V_101 )
return F_49 ( - V_62 ) ;
F_20 ( & V_6 -> V_40 , V_87 ) ;
if ( ! F_15 ( & V_6 -> free ) ) {
V_12 = F_5 ( & V_6 -> free , struct V_11 ,
V_14 ) ;
F_47 ( & V_12 -> V_14 ) ;
}
F_21 ( & V_6 -> V_40 , V_87 ) ;
if ( ! V_12 )
return NULL ;
F_20 ( & V_6 -> V_40 , V_87 ) ;
V_12 -> V_29 = V_29 ;
V_12 -> V_31 = 1 ;
V_12 -> V_24 = 0 ;
V_12 -> V_26 = V_100 / V_84 - 1 ;
V_12 -> V_16 = 1 ;
F_36 ( & V_12 -> V_14 , & V_6 -> V_76 ) ;
F_21 ( & V_6 -> V_40 , V_87 ) ;
return & V_12 -> V_46 ;
}
bool F_51 ( struct V_2 * V_4 , void * V_8 )
{
unsigned int V_104 = ( unsigned int ) V_8 ;
if ( V_104 == V_4 -> V_8 +
V_4 -> V_105 -> V_106 * V_107 )
return true ;
return false ;
}
static struct V_2 * F_52 ( struct V_108 * V_109 ,
struct V_110 * V_111 )
{
struct V_5 * V_9 = V_111 -> V_112 ;
unsigned int V_113 = V_109 -> args [ 0 ] ;
if ( V_113 >= V_107 )
return NULL ;
return F_53 ( & V_9 -> V_7 [ V_113 ] . V_4 ) ;
}
static int F_54 ( struct V_114 * V_115 )
{
struct V_116 * V_117 = V_115 -> V_69 . V_118 ;
struct V_105 * V_69 = & V_115 -> V_69 ;
struct V_119 * V_50 ;
struct V_5 * V_9 ;
struct V_1 * V_6 ;
struct V_120 V_121 ;
T_6 V_122 , V_123 ;
T_2 V_124 ;
int V_80 , V_49 ;
V_9 = F_55 ( V_69 , sizeof( * V_9 ) , V_71 ) ;
if ( ! V_9 ) {
F_56 ( V_69 , L_4 ) ;
return - V_74 ;
}
if ( F_57 ( V_117 , L_5 ) )
V_9 -> V_64 = true ;
if ( F_58 ( V_117 , L_6 , & V_124 ) ) {
F_56 ( V_69 , L_7 ) ;
return - V_125 ;
}
V_9 -> V_35 = F_59 ( V_117 , 0 ) ;
if ( V_9 -> V_35 == V_126 ) {
F_56 ( V_69 , L_8 ) ;
return - V_62 ;
}
V_9 -> V_127 = F_60 ( V_69 , NULL ) ;
if ( F_61 ( V_9 -> V_127 ) ) {
F_56 ( V_69 , L_9 ) ;
return F_62 ( V_9 -> V_127 ) ;
}
V_80 = F_63 ( V_117 , 0 , & V_121 ) ;
if ( V_80 ) {
F_56 ( V_69 , L_10 ) ;
goto V_128;
}
V_122 = V_121 . V_129 ;
V_123 = F_64 ( & V_121 ) ;
V_9 -> V_17 = F_65 ( V_69 , V_122 , V_123 ) ;
if ( ! V_9 -> V_17 ) {
F_56 ( V_69 , L_11 ) ;
V_80 = - V_74 ;
goto V_128;
}
V_80 = F_66 ( V_9 -> V_35 , & F_10 , 0 , V_130 , V_9 ) ;
if ( V_80 ) {
F_56 ( V_69 , L_12 ) ;
V_80 = - V_62 ;
goto V_128;
}
V_50 = & V_9 -> V_50 ;
V_50 -> V_69 = V_69 ;
V_50 -> V_131 = F_31 ;
V_50 -> V_132 = F_37 ;
V_50 -> V_133 = F_42 ;
V_50 -> V_134 = F_27 ;
V_50 -> V_135 = F_29 ;
V_50 -> V_136 = F_30 ;
V_50 -> V_137 = F_28 ;
V_50 -> V_138 = F_43 ;
V_50 -> V_139 = F_46 ;
V_50 -> V_140 = F_50 ;
V_50 -> V_141 = V_142 ;
V_50 -> V_143 = V_142 ;
V_50 -> V_144 = F_67 ( V_89 ) | F_67 ( V_88 ) ;
F_68 ( & V_50 -> V_7 ) ;
F_69 ( V_145 , V_50 -> V_146 ) ;
F_69 ( V_147 , V_50 -> V_146 ) ;
F_69 ( V_148 , V_50 -> V_146 ) ;
F_69 ( V_149 , V_50 -> V_146 ) ;
for ( V_49 = 0 ; V_49 < V_107 ; V_49 ++ ) {
V_6 = & V_9 -> V_7 [ V_49 ] ;
V_6 -> V_4 . V_105 = V_50 ;
F_70 ( & V_6 -> V_4 ) ;
F_68 ( & V_6 -> free ) ;
F_68 ( & V_6 -> V_76 ) ;
F_68 ( & V_6 -> V_13 ) ;
F_68 ( & V_6 -> V_15 ) ;
F_68 ( & V_6 -> V_41 ) ;
F_71 ( & V_6 -> V_40 ) ;
F_36 ( & V_6 -> V_4 . V_116 , & V_50 -> V_7 ) ;
}
F_72 ( & V_9 -> V_42 , F_24 , ( unsigned long ) V_9 ) ;
F_73 ( V_69 , V_9 ) ;
V_80 = F_74 ( V_50 ) ;
if ( V_80 )
goto V_150;
V_80 = F_75 ( V_117 , F_52 , V_9 ) ;
if ( V_80 ) {
F_56 ( V_69 , L_13 ) ;
goto V_151;
}
F_76 ( & V_115 -> V_69 ) ;
F_77 ( V_69 , L_14 ) ;
return 0 ;
V_151:
F_78 ( V_50 ) ;
V_150:
V_150 ( V_9 -> V_35 , V_9 ) ;
V_128:
F_79 ( V_9 -> V_35 ) ;
return V_80 ;
}
static int F_80 ( struct V_114 * V_115 )
{
struct V_105 * V_69 = & V_115 -> V_69 ;
struct V_5 * V_9 = F_81 ( V_69 ) ;
F_82 ( V_115 -> V_69 . V_118 ) ;
F_78 ( & V_9 -> V_50 ) ;
V_150 ( V_9 -> V_35 , V_9 ) ;
F_79 ( V_9 -> V_35 ) ;
F_83 ( & V_115 -> V_69 ) ;
if ( ! F_84 ( & V_115 -> V_69 ) )
F_85 ( & V_115 -> V_69 ) ;
return 0 ;
}
static int F_85 ( struct V_105 * V_69 )
{
struct V_5 * V_9 = F_81 ( V_69 ) ;
F_86 ( V_9 -> V_127 ) ;
return 0 ;
}
static int F_87 ( struct V_105 * V_69 )
{
struct V_5 * V_9 = F_81 ( V_69 ) ;
int V_80 ;
V_80 = F_88 ( V_9 -> V_127 ) ;
if ( V_80 < 0 ) {
F_56 ( V_69 , L_15 , V_80 ) ;
return V_80 ;
}
return 0 ;
}
static int F_89 ( struct V_105 * V_69 )
{
struct V_5 * V_9 = F_81 ( V_69 ) ;
struct V_152 * V_153 = & V_9 -> V_154 ;
struct V_11 * V_12 ;
struct V_1 * V_6 ;
int V_38 ;
int V_80 ;
if ( F_84 ( V_69 ) ) {
V_80 = F_87 ( V_69 ) ;
if ( V_80 < 0 )
return V_80 ;
}
for ( V_38 = 0 ; V_38 < V_107 ; V_38 ++ ) {
V_6 = & V_9 -> V_7 [ V_38 ] ;
if ( F_15 ( & V_6 -> V_15 ) )
continue;
V_12 = F_5 ( & V_6 -> V_15 ,
struct V_11 ,
V_14 ) ;
V_153 -> V_155 [ V_38 ] = F_8 ( V_9 -> V_17 +
V_38 * 0x10 + V_23 ) ;
}
V_153 -> V_156 = F_8 ( V_9 -> V_17 + V_28 ) ;
F_85 ( V_69 ) ;
return 0 ;
}
static int F_90 ( struct V_105 * V_69 )
{
struct V_5 * V_9 = F_81 ( V_69 ) ;
struct V_152 * V_153 = & V_9 -> V_154 ;
struct V_11 * V_12 ;
struct V_1 * V_6 ;
int V_38 ;
int V_80 ;
V_80 = F_87 ( V_69 ) ;
if ( V_80 < 0 )
return V_80 ;
F_7 ( V_153 -> V_156 , V_9 -> V_17 + V_28 ) ;
for ( V_38 = 0 ; V_38 < V_107 ; V_38 ++ ) {
V_6 = & V_9 -> V_7 [ V_38 ] ;
if ( F_15 ( & V_6 -> V_15 ) )
continue;
V_12 = F_5 ( & V_6 -> V_15 ,
struct V_11 ,
V_14 ) ;
F_7 ( V_12 -> V_16 ,
V_9 -> V_17 + V_18 + V_38 * 4 ) ;
F_7 ( V_12 -> V_24 ,
V_9 -> V_17 + V_38 * 0x10 + V_25 ) ;
F_7 ( V_12 -> V_26 ,
V_9 -> V_17 + V_38 * 0x10 + V_27 ) ;
F_7 ( V_153 -> V_155 [ V_38 ] ,
V_9 -> V_17 + V_38 * 0x10 + V_23 ) ;
F_7 ( V_12 -> V_29 >> 2 ,
V_9 -> V_17 + V_38 * 0x10 + V_30 ) ;
}
if ( F_84 ( V_69 ) )
F_85 ( V_69 ) ;
return 0 ;
}
static T_7 int F_91 ( void )
{
return F_92 ( & V_157 ) ;
}
static void T_8 F_93 ( void )
{
F_94 ( & V_157 ) ;
}
