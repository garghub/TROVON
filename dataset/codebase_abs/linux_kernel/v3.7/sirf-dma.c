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
F_7 ( F_8 ( V_9 -> V_17 + V_28 ) &
~ ( 1 << V_10 ) , V_9 -> V_17 + V_28 ) ;
F_7 ( 1 << V_10 , V_9 -> V_17 + V_64 ) ;
F_7 ( F_8 ( V_9 -> V_17 + V_32 )
& ~ ( ( 1 << V_10 ) | 1 << ( V_10 + 16 ) ) ,
V_9 -> V_17 + V_32 ) ;
F_20 ( & V_6 -> V_40 , V_47 ) ;
F_14 ( & V_6 -> V_15 , & V_6 -> free ) ;
F_14 ( & V_6 -> V_13 , & V_6 -> free ) ;
F_21 ( & V_6 -> V_40 , V_47 ) ;
return 0 ;
}
static int F_29 ( struct V_2 * V_4 , enum V_65 V_66 ,
unsigned long V_67 )
{
struct V_57 * V_58 ;
struct V_1 * V_6 = F_1 ( V_4 ) ;
switch ( V_66 ) {
case V_68 :
return F_28 ( V_6 ) ;
case V_69 :
V_58 = (struct V_57 * ) V_67 ;
return F_27 ( V_6 , V_58 ) ;
default:
break;
}
return - V_70 ;
}
static int F_30 ( struct V_2 * V_4 )
{
struct V_5 * V_9 = F_3 ( V_4 ) ;
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_11 * V_12 ;
unsigned long V_47 ;
F_19 ( V_71 ) ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_72 ; V_49 ++ ) {
V_12 = F_31 ( sizeof( * V_12 ) , V_73 ) ;
if ( ! V_12 ) {
F_32 ( V_9 -> V_50 . V_74 , L_1
L_2 , V_49 ) ;
break;
}
F_33 ( & V_12 -> V_46 , V_4 ) ;
V_12 -> V_46 . V_47 = V_75 ;
V_12 -> V_46 . V_76 = F_25 ;
F_34 ( & V_12 -> V_14 , & V_71 ) ;
}
if ( V_49 == 0 )
return - V_77 ;
F_20 ( & V_6 -> V_40 , V_47 ) ;
F_14 ( & V_71 , & V_6 -> free ) ;
F_21 ( & V_6 -> V_40 , V_47 ) ;
return V_49 ;
}
static void F_35 ( struct V_2 * V_4 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_11 * V_12 , * V_78 ;
unsigned long V_47 ;
F_19 ( V_71 ) ;
F_20 ( & V_6 -> V_40 , V_47 ) ;
F_36 ( ! F_15 ( & V_6 -> V_79 ) ) ;
F_36 ( ! F_15 ( & V_6 -> V_13 ) ) ;
F_36 ( ! F_15 ( & V_6 -> V_15 ) ) ;
F_36 ( ! F_15 ( & V_6 -> V_41 ) ) ;
F_14 ( & V_6 -> free , & V_71 ) ;
F_21 ( & V_6 -> V_40 , V_47 ) ;
F_37 (sdesc, tmp, &descs, node)
F_38 ( V_12 ) ;
}
static void F_39 ( struct V_2 * V_4 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
unsigned long V_47 ;
F_20 ( & V_6 -> V_40 , V_47 ) ;
if ( F_15 ( & V_6 -> V_15 ) && ! F_15 ( & V_6 -> V_13 ) )
F_4 ( V_6 ) ;
F_21 ( & V_6 -> V_40 , V_47 ) ;
}
static enum V_80
F_40 ( struct V_2 * V_4 , T_3 V_54 ,
struct V_81 * V_82 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
unsigned long V_47 ;
enum V_80 V_83 ;
F_20 ( & V_6 -> V_40 , V_47 ) ;
V_83 = F_41 ( V_4 , V_54 , V_82 ) ;
F_21 ( & V_6 -> V_40 , V_47 ) ;
return V_83 ;
}
static struct V_45 * F_42 (
struct V_2 * V_4 , struct V_84 * V_85 ,
unsigned long V_47 )
{
struct V_5 * V_9 = F_3 ( V_4 ) ;
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_11 * V_12 = NULL ;
unsigned long V_86 ;
int V_83 ;
if ( ( V_85 -> V_21 != V_87 ) && ( V_85 -> V_21 != V_88 ) ) {
V_83 = - V_62 ;
goto V_89;
}
F_20 ( & V_6 -> V_40 , V_86 ) ;
if ( ! F_15 ( & V_6 -> free ) ) {
V_12 = F_5 ( & V_6 -> free , struct V_11 ,
V_14 ) ;
F_43 ( & V_12 -> V_14 ) ;
}
F_21 ( & V_6 -> V_40 , V_86 ) ;
if ( ! V_12 ) {
F_18 ( V_9 ) ;
V_83 = 0 ;
goto V_90;
}
F_20 ( & V_6 -> V_40 , V_86 ) ;
if ( ( V_85 -> V_91 == 1 ) && ( V_85 -> V_92 > 0 ) ) {
V_12 -> V_31 = 0 ;
V_12 -> V_24 = V_85 -> V_93 [ 0 ] . V_94 / V_95 ;
V_12 -> V_16 = ( V_85 -> V_93 [ 0 ] . V_94 + V_85 -> V_93 [ 0 ] . V_96 ) /
V_95 ;
V_12 -> V_26 = V_85 -> V_92 - 1 ;
if ( V_85 -> V_21 == V_87 ) {
V_12 -> V_29 = V_85 -> V_97 ;
V_12 -> V_21 = 1 ;
} else {
V_12 -> V_29 = V_85 -> V_98 ;
V_12 -> V_21 = 0 ;
}
F_34 ( & V_12 -> V_14 , & V_6 -> V_79 ) ;
} else {
F_44 ( L_3 ) ;
V_83 = - V_62 ;
goto V_99;
}
F_21 ( & V_6 -> V_40 , V_86 ) ;
return & V_12 -> V_46 ;
V_99:
F_21 ( & V_6 -> V_40 , V_86 ) ;
V_90:
V_89:
return F_45 ( V_83 ) ;
}
static struct V_45 *
F_46 ( struct V_2 * V_4 , T_4 V_29 ,
T_5 V_100 , T_5 V_101 ,
enum V_102 V_103 , unsigned long V_47 , void * V_104 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_11 * V_12 = NULL ;
unsigned long V_86 ;
if ( V_100 != 2 * V_101 )
return F_45 ( - V_62 ) ;
F_20 ( & V_6 -> V_40 , V_86 ) ;
if ( ! F_15 ( & V_6 -> free ) ) {
V_12 = F_5 ( & V_6 -> free , struct V_11 ,
V_14 ) ;
F_43 ( & V_12 -> V_14 ) ;
}
F_21 ( & V_6 -> V_40 , V_86 ) ;
if ( ! V_12 )
return 0 ;
F_20 ( & V_6 -> V_40 , V_86 ) ;
V_12 -> V_29 = V_29 ;
V_12 -> V_31 = 1 ;
V_12 -> V_24 = 0 ;
V_12 -> V_26 = V_100 / V_95 - 1 ;
V_12 -> V_16 = 1 ;
F_34 ( & V_12 -> V_14 , & V_6 -> V_79 ) ;
F_21 ( & V_6 -> V_40 , V_86 ) ;
return & V_12 -> V_46 ;
}
bool F_47 ( struct V_2 * V_4 , void * V_8 )
{
unsigned int V_105 = ( unsigned int ) V_8 ;
if ( V_105 == V_4 -> V_8 +
V_4 -> V_106 -> V_107 * V_108 )
return true ;
return false ;
}
static int T_6 F_48 ( struct V_109 * V_110 )
{
struct V_111 * V_112 = V_110 -> V_74 . V_113 ;
struct V_106 * V_74 = & V_110 -> V_74 ;
struct V_114 * V_50 ;
struct V_5 * V_9 ;
struct V_1 * V_6 ;
struct V_115 V_116 ;
T_7 V_117 , V_118 ;
T_2 V_119 ;
int V_83 , V_49 ;
V_9 = F_49 ( V_74 , sizeof( * V_9 ) , V_73 ) ;
if ( ! V_9 ) {
F_50 ( V_74 , L_4 ) ;
return - V_77 ;
}
if ( F_51 ( V_112 , L_5 , & V_119 ) ) {
F_50 ( V_74 , L_6 ) ;
return - V_120 ;
}
V_9 -> V_35 = F_52 ( V_112 , 0 ) ;
if ( V_9 -> V_35 == V_121 ) {
F_50 ( V_74 , L_7 ) ;
return - V_62 ;
}
V_83 = F_53 ( V_112 , 0 , & V_116 ) ;
if ( V_83 ) {
F_50 ( V_74 , L_8 ) ;
goto V_122;
}
V_117 = V_116 . V_123 ;
V_118 = F_54 ( & V_116 ) ;
V_9 -> V_17 = F_55 ( V_74 , V_117 , V_118 ) ;
if ( ! V_9 -> V_17 ) {
F_50 ( V_74 , L_9 ) ;
V_83 = - V_77 ;
goto V_122;
}
V_83 = F_56 ( V_9 -> V_35 , & F_10 , 0 , V_124 , V_9 ) ;
if ( V_83 ) {
F_50 ( V_74 , L_10 ) ;
V_83 = - V_62 ;
goto V_122;
}
V_50 = & V_9 -> V_50 ;
V_50 -> V_74 = V_74 ;
V_50 -> V_51 = V_108 ;
V_50 -> V_125 = F_30 ;
V_50 -> V_126 = F_35 ;
V_50 -> V_127 = F_39 ;
V_50 -> V_128 = F_29 ;
V_50 -> V_129 = F_40 ;
V_50 -> V_130 = F_42 ;
V_50 -> V_131 = F_46 ;
F_57 ( & V_50 -> V_7 ) ;
F_58 ( V_132 , V_50 -> V_133 ) ;
F_58 ( V_134 , V_50 -> V_133 ) ;
F_58 ( V_135 , V_50 -> V_133 ) ;
F_58 ( V_136 , V_50 -> V_133 ) ;
for ( V_49 = 0 ; V_49 < V_50 -> V_51 ; V_49 ++ ) {
V_6 = & V_9 -> V_7 [ V_49 ] ;
V_6 -> V_4 . V_106 = V_50 ;
F_59 ( & V_6 -> V_4 ) ;
F_57 ( & V_6 -> free ) ;
F_57 ( & V_6 -> V_79 ) ;
F_57 ( & V_6 -> V_13 ) ;
F_57 ( & V_6 -> V_15 ) ;
F_57 ( & V_6 -> V_41 ) ;
F_60 ( & V_6 -> V_40 ) ;
F_34 ( & V_6 -> V_4 . V_111 , & V_50 -> V_7 ) ;
}
F_61 ( & V_9 -> V_42 , F_24 , ( unsigned long ) V_9 ) ;
F_62 ( V_74 , V_9 ) ;
V_83 = F_63 ( V_50 ) ;
if ( V_83 )
goto V_137;
F_64 ( V_74 , L_11 ) ;
return 0 ;
V_137:
V_137 ( V_9 -> V_35 , V_9 ) ;
V_122:
F_65 ( V_9 -> V_35 ) ;
return V_83 ;
}
static int T_8 F_66 ( struct V_109 * V_110 )
{
struct V_106 * V_74 = & V_110 -> V_74 ;
struct V_5 * V_9 = F_67 ( V_74 ) ;
F_68 ( & V_9 -> V_50 ) ;
V_137 ( V_9 -> V_35 , V_9 ) ;
F_65 ( V_9 -> V_35 ) ;
return 0 ;
}
