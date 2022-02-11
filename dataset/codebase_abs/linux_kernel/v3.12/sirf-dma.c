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
static int F_27 ( struct V_1 * V_6 ,
struct V_57 * V_58 )
{
unsigned long V_47 ;
if ( ( V_58 -> V_59 != V_60 ) ||
( V_58 -> V_61 != V_60 ) )
return - V_62 ;
F_20 ( & V_6 -> V_40 , V_47 ) ;
V_6 -> V_19 = ( V_58 -> V_63 == 4 ? 1 : 0 ) ;
F_21 ( & V_6 -> V_40 , V_47 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_6 )
{
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
static int F_29 ( struct V_1 * V_6 )
{
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
static int F_30 ( struct V_1 * V_6 )
{
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
static int F_31 ( struct V_2 * V_4 , enum V_68 V_69 ,
unsigned long V_70 )
{
struct V_57 * V_58 ;
struct V_1 * V_6 = F_1 ( V_4 ) ;
switch ( V_69 ) {
case V_71 :
return F_29 ( V_6 ) ;
case V_72 :
return F_30 ( V_6 ) ;
case V_73 :
return F_28 ( V_6 ) ;
case V_74 :
V_58 = (struct V_57 * ) V_70 ;
return F_27 ( V_6 , V_58 ) ;
default:
break;
}
return - V_75 ;
}
static int F_32 ( struct V_2 * V_4 )
{
struct V_5 * V_9 = F_3 ( V_4 ) ;
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_11 * V_12 ;
unsigned long V_47 ;
F_19 ( V_76 ) ;
int V_49 ;
F_33 ( V_9 -> V_50 . V_77 ) ;
for ( V_49 = 0 ; V_49 < V_78 ; V_49 ++ ) {
V_12 = F_34 ( sizeof( * V_12 ) , V_79 ) ;
if ( ! V_12 ) {
F_35 ( V_9 -> V_50 . V_77 , L_1
L_2 , V_49 ) ;
break;
}
F_36 ( & V_12 -> V_46 , V_4 ) ;
V_12 -> V_46 . V_47 = V_80 ;
V_12 -> V_46 . V_81 = F_25 ;
F_37 ( & V_12 -> V_14 , & V_76 ) ;
}
if ( V_49 == 0 )
return - V_82 ;
F_20 ( & V_6 -> V_40 , V_47 ) ;
F_14 ( & V_76 , & V_6 -> free ) ;
F_21 ( & V_6 -> V_40 , V_47 ) ;
return V_49 ;
}
static void F_38 ( struct V_2 * V_4 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_5 * V_9 = F_3 ( V_4 ) ;
struct V_11 * V_12 , * V_83 ;
unsigned long V_47 ;
F_19 ( V_76 ) ;
F_20 ( & V_6 -> V_40 , V_47 ) ;
F_39 ( ! F_15 ( & V_6 -> V_84 ) ) ;
F_39 ( ! F_15 ( & V_6 -> V_13 ) ) ;
F_39 ( ! F_15 ( & V_6 -> V_15 ) ) ;
F_39 ( ! F_15 ( & V_6 -> V_41 ) ) ;
F_14 ( & V_6 -> free , & V_76 ) ;
F_21 ( & V_6 -> V_40 , V_47 ) ;
F_40 (sdesc, tmp, &descs, node)
F_41 ( V_12 ) ;
F_42 ( V_9 -> V_50 . V_77 ) ;
}
static void F_43 ( struct V_2 * V_4 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
unsigned long V_47 ;
F_20 ( & V_6 -> V_40 , V_47 ) ;
if ( F_15 ( & V_6 -> V_15 ) && ! F_15 ( & V_6 -> V_13 ) )
F_4 ( V_6 ) ;
F_21 ( & V_6 -> V_40 , V_47 ) ;
}
static enum V_85
F_44 ( struct V_2 * V_4 , T_3 V_54 ,
struct V_86 * V_87 )
{
struct V_5 * V_9 = F_3 ( V_4 ) ;
struct V_1 * V_6 = F_1 ( V_4 ) ;
unsigned long V_47 ;
enum V_85 V_88 ;
struct V_11 * V_12 ;
int V_10 = V_6 -> V_4 . V_8 ;
unsigned long V_89 ;
unsigned long V_90 ;
unsigned long V_91 ;
F_20 ( & V_6 -> V_40 , V_47 ) ;
V_12 = F_5 ( & V_6 -> V_15 , struct V_11 ,
V_14 ) ;
V_90 = ( V_12 -> V_24 + 1 ) * ( V_12 -> V_26 + 1 ) *
( V_12 -> V_16 * V_92 ) ;
V_88 = F_45 ( V_4 , V_54 , V_87 ) ;
V_89 = F_8 ( V_9 -> V_17 + V_10 * 0x10 + V_30 )
<< 2 ;
V_91 = V_90 - ( V_89 - V_12 -> V_29 ) ;
F_46 ( V_87 , V_91 ) ;
F_21 ( & V_6 -> V_40 , V_47 ) ;
return V_88 ;
}
static struct V_45 * F_47 (
struct V_2 * V_4 , struct V_93 * V_94 ,
unsigned long V_47 )
{
struct V_5 * V_9 = F_3 ( V_4 ) ;
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_11 * V_12 = NULL ;
unsigned long V_95 ;
int V_88 ;
if ( ( V_94 -> V_21 != V_96 ) && ( V_94 -> V_21 != V_97 ) ) {
V_88 = - V_62 ;
goto V_98;
}
F_20 ( & V_6 -> V_40 , V_95 ) ;
if ( ! F_15 ( & V_6 -> free ) ) {
V_12 = F_5 ( & V_6 -> free , struct V_11 ,
V_14 ) ;
F_48 ( & V_12 -> V_14 ) ;
}
F_21 ( & V_6 -> V_40 , V_95 ) ;
if ( ! V_12 ) {
F_18 ( V_9 ) ;
V_88 = 0 ;
goto V_99;
}
F_20 ( & V_6 -> V_40 , V_95 ) ;
if ( ( V_94 -> V_100 == 1 ) && ( V_94 -> V_101 > 0 ) ) {
V_12 -> V_31 = 0 ;
V_12 -> V_24 = V_94 -> V_102 [ 0 ] . V_103 / V_92 ;
V_12 -> V_16 = ( V_94 -> V_102 [ 0 ] . V_103 + V_94 -> V_102 [ 0 ] . V_104 ) /
V_92 ;
V_12 -> V_26 = V_94 -> V_101 - 1 ;
if ( V_94 -> V_21 == V_96 ) {
V_12 -> V_29 = V_94 -> V_105 ;
V_12 -> V_21 = 1 ;
} else {
V_12 -> V_29 = V_94 -> V_106 ;
V_12 -> V_21 = 0 ;
}
F_37 ( & V_12 -> V_14 , & V_6 -> V_84 ) ;
} else {
F_49 ( L_3 ) ;
V_88 = - V_62 ;
goto V_107;
}
F_21 ( & V_6 -> V_40 , V_95 ) ;
return & V_12 -> V_46 ;
V_107:
F_21 ( & V_6 -> V_40 , V_95 ) ;
V_99:
V_98:
return F_50 ( V_88 ) ;
}
static struct V_45 *
F_51 ( struct V_2 * V_4 , T_4 V_29 ,
T_5 V_108 , T_5 V_109 ,
enum V_110 V_111 , unsigned long V_47 , void * V_112 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_11 * V_12 = NULL ;
unsigned long V_95 ;
if ( V_108 != 2 * V_109 )
return F_50 ( - V_62 ) ;
F_20 ( & V_6 -> V_40 , V_95 ) ;
if ( ! F_15 ( & V_6 -> free ) ) {
V_12 = F_5 ( & V_6 -> free , struct V_11 ,
V_14 ) ;
F_48 ( & V_12 -> V_14 ) ;
}
F_21 ( & V_6 -> V_40 , V_95 ) ;
if ( ! V_12 )
return NULL ;
F_20 ( & V_6 -> V_40 , V_95 ) ;
V_12 -> V_29 = V_29 ;
V_12 -> V_31 = 1 ;
V_12 -> V_24 = 0 ;
V_12 -> V_26 = V_108 / V_92 - 1 ;
V_12 -> V_16 = 1 ;
F_37 ( & V_12 -> V_14 , & V_6 -> V_84 ) ;
F_21 ( & V_6 -> V_40 , V_95 ) ;
return & V_12 -> V_46 ;
}
bool F_52 ( struct V_2 * V_4 , void * V_8 )
{
unsigned int V_113 = ( unsigned int ) V_8 ;
if ( V_113 == V_4 -> V_8 +
V_4 -> V_114 -> V_115 * V_116 )
return true ;
return false ;
}
static int F_53 ( struct V_117 * V_118 )
{
struct V_119 * V_120 = V_118 -> V_77 . V_121 ;
struct V_114 * V_77 = & V_118 -> V_77 ;
struct V_122 * V_50 ;
struct V_5 * V_9 ;
struct V_1 * V_6 ;
struct V_123 V_124 ;
T_6 V_125 , V_126 ;
T_2 V_127 ;
int V_88 , V_49 ;
V_9 = F_54 ( V_77 , sizeof( * V_9 ) , V_79 ) ;
if ( ! V_9 ) {
F_55 ( V_77 , L_4 ) ;
return - V_82 ;
}
if ( F_56 ( V_120 , L_5 ) )
V_9 -> V_64 = true ;
if ( F_57 ( V_120 , L_6 , & V_127 ) ) {
F_55 ( V_77 , L_7 ) ;
return - V_128 ;
}
V_9 -> V_35 = F_58 ( V_120 , 0 ) ;
if ( V_9 -> V_35 == V_129 ) {
F_55 ( V_77 , L_8 ) ;
return - V_62 ;
}
V_9 -> V_130 = F_59 ( V_77 , NULL ) ;
if ( F_60 ( V_9 -> V_130 ) ) {
F_55 ( V_77 , L_9 ) ;
return F_61 ( V_9 -> V_130 ) ;
}
V_88 = F_62 ( V_120 , 0 , & V_124 ) ;
if ( V_88 ) {
F_55 ( V_77 , L_10 ) ;
goto V_131;
}
V_125 = V_124 . V_132 ;
V_126 = F_63 ( & V_124 ) ;
V_9 -> V_17 = F_64 ( V_77 , V_125 , V_126 ) ;
if ( ! V_9 -> V_17 ) {
F_55 ( V_77 , L_11 ) ;
V_88 = - V_82 ;
goto V_131;
}
V_88 = F_65 ( V_9 -> V_35 , & F_10 , 0 , V_133 , V_9 ) ;
if ( V_88 ) {
F_55 ( V_77 , L_12 ) ;
V_88 = - V_62 ;
goto V_131;
}
V_50 = & V_9 -> V_50 ;
V_50 -> V_77 = V_77 ;
V_50 -> V_51 = V_116 ;
V_50 -> V_134 = F_32 ;
V_50 -> V_135 = F_38 ;
V_50 -> V_136 = F_43 ;
V_50 -> V_137 = F_31 ;
V_50 -> V_138 = F_44 ;
V_50 -> V_139 = F_47 ;
V_50 -> V_140 = F_51 ;
F_66 ( & V_50 -> V_7 ) ;
F_67 ( V_141 , V_50 -> V_142 ) ;
F_67 ( V_143 , V_50 -> V_142 ) ;
F_67 ( V_144 , V_50 -> V_142 ) ;
F_67 ( V_145 , V_50 -> V_142 ) ;
for ( V_49 = 0 ; V_49 < V_50 -> V_51 ; V_49 ++ ) {
V_6 = & V_9 -> V_7 [ V_49 ] ;
V_6 -> V_4 . V_114 = V_50 ;
F_68 ( & V_6 -> V_4 ) ;
F_66 ( & V_6 -> free ) ;
F_66 ( & V_6 -> V_84 ) ;
F_66 ( & V_6 -> V_13 ) ;
F_66 ( & V_6 -> V_15 ) ;
F_66 ( & V_6 -> V_41 ) ;
F_69 ( & V_6 -> V_40 ) ;
F_37 ( & V_6 -> V_4 . V_119 , & V_50 -> V_7 ) ;
}
F_70 ( & V_9 -> V_42 , F_24 , ( unsigned long ) V_9 ) ;
F_71 ( V_77 , V_9 ) ;
V_88 = F_72 ( V_50 ) ;
if ( V_88 )
goto V_146;
F_73 ( & V_118 -> V_77 ) ;
F_74 ( V_77 , L_13 ) ;
return 0 ;
V_146:
V_146 ( V_9 -> V_35 , V_9 ) ;
V_131:
F_75 ( V_9 -> V_35 ) ;
return V_88 ;
}
static int F_76 ( struct V_117 * V_118 )
{
struct V_114 * V_77 = & V_118 -> V_77 ;
struct V_5 * V_9 = F_77 ( V_77 ) ;
F_78 ( & V_9 -> V_50 ) ;
V_146 ( V_9 -> V_35 , V_9 ) ;
F_75 ( V_9 -> V_35 ) ;
F_79 ( & V_118 -> V_77 ) ;
if ( ! F_80 ( & V_118 -> V_77 ) )
F_81 ( & V_118 -> V_77 ) ;
return 0 ;
}
static int F_81 ( struct V_114 * V_77 )
{
struct V_5 * V_9 = F_77 ( V_77 ) ;
F_82 ( V_9 -> V_130 ) ;
return 0 ;
}
static int F_83 ( struct V_114 * V_77 )
{
struct V_5 * V_9 = F_77 ( V_77 ) ;
int V_88 ;
V_88 = F_84 ( V_9 -> V_130 ) ;
if ( V_88 < 0 ) {
F_55 ( V_77 , L_14 , V_88 ) ;
return V_88 ;
}
return 0 ;
}
static int F_85 ( struct V_114 * V_77 )
{
struct V_5 * V_9 = F_77 ( V_77 ) ;
struct V_147 * V_148 = & V_9 -> V_149 ;
struct V_11 * V_12 ;
struct V_1 * V_6 ;
int V_38 ;
int V_88 ;
if ( F_80 ( V_77 ) ) {
V_88 = F_83 ( V_77 ) ;
if ( V_88 < 0 )
return V_88 ;
}
for ( V_38 = 0 ; V_38 < V_116 ; V_38 ++ ) {
V_6 = & V_9 -> V_7 [ V_38 ] ;
if ( F_15 ( & V_6 -> V_15 ) )
continue;
V_12 = F_5 ( & V_6 -> V_15 ,
struct V_11 ,
V_14 ) ;
V_148 -> V_150 [ V_38 ] = F_8 ( V_9 -> V_17 +
V_38 * 0x10 + V_23 ) ;
}
V_148 -> V_151 = F_8 ( V_9 -> V_17 + V_28 ) ;
F_81 ( V_77 ) ;
return 0 ;
}
static int F_86 ( struct V_114 * V_77 )
{
struct V_5 * V_9 = F_77 ( V_77 ) ;
struct V_147 * V_148 = & V_9 -> V_149 ;
struct V_11 * V_12 ;
struct V_1 * V_6 ;
int V_38 ;
int V_88 ;
V_88 = F_83 ( V_77 ) ;
if ( V_88 < 0 )
return V_88 ;
F_7 ( V_148 -> V_151 , V_9 -> V_17 + V_28 ) ;
for ( V_38 = 0 ; V_38 < V_116 ; V_38 ++ ) {
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
F_7 ( V_148 -> V_150 [ V_38 ] ,
V_9 -> V_17 + V_38 * 0x10 + V_23 ) ;
F_7 ( V_12 -> V_29 >> 2 ,
V_9 -> V_17 + V_38 * 0x10 + V_30 ) ;
}
if ( F_80 ( V_77 ) )
F_81 ( V_77 ) ;
return 0 ;
}
static T_7 int F_87 ( void )
{
return F_88 ( & V_152 ) ;
}
static void T_8 F_89 ( void )
{
F_90 ( & V_152 ) ;
}
