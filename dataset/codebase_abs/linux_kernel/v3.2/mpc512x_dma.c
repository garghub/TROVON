static inline struct V_1 * F_1 ( struct V_2 * V_3 )
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
struct V_10 * V_11 = NULL ;
struct V_10 * V_12 = NULL ;
struct V_10 * V_13 ;
int V_14 = V_6 -> V_4 . V_8 ;
F_5 ( & V_6 -> V_15 , & V_6 -> V_16 ) ;
F_6 (mdesc, &mchan->active, node) {
if ( ! V_11 )
V_11 = V_13 ;
if ( ! V_12 ) {
V_12 = V_13 ;
continue;
}
V_12 -> V_17 -> V_18 = V_13 -> V_19 ;
V_12 -> V_17 -> V_20 = 1 ;
V_13 -> V_17 -> V_21 = 1 ;
V_12 = V_13 ;
}
V_12 -> V_17 -> V_22 = 1 ;
F_7 ( & V_9 -> V_17 [ V_14 ] , V_11 -> V_17 , sizeof( struct V_23 ) ) ;
if ( V_11 != V_12 )
V_9 -> V_17 [ V_14 ] . V_20 = 1 ;
F_8 ( & V_9 -> V_24 -> V_25 , V_14 ) ;
}
static void F_9 ( struct V_5 * V_9 , T_1 V_26 , T_1 V_27 , int V_28 )
{
struct V_1 * V_6 ;
struct V_10 * V_13 ;
T_1 V_29 = V_26 | V_27 ;
int V_30 ;
while ( ( V_30 = F_10 ( V_29 ) - 1 ) >= 0 ) {
V_29 &= ~ ( 1 << V_30 ) ;
V_6 = & V_9 -> V_7 [ V_30 + V_28 ] ;
F_11 ( & V_6 -> V_31 ) ;
F_8 ( & V_9 -> V_24 -> V_32 , V_30 + V_28 ) ;
F_8 ( & V_9 -> V_24 -> V_33 , V_30 + V_28 ) ;
if ( V_27 & ( 1 << V_30 ) )
F_6 (mdesc, &mchan->active, node)
V_13 -> error = - V_34 ;
F_5 ( & V_6 -> V_16 , & V_6 -> V_35 ) ;
if ( ! F_12 ( & V_6 -> V_15 ) )
F_4 ( V_6 ) ;
F_13 ( & V_6 -> V_31 ) ;
}
}
static T_2 F_14 ( int V_36 , void * V_37 )
{
struct V_5 * V_9 = V_37 ;
T_3 V_27 ;
V_27 = F_15 ( & V_9 -> V_24 -> V_38 ) ;
F_11 ( & V_9 -> V_39 ) ;
if ( ( V_27 & V_40 ) && V_9 -> V_41 == 0 )
V_9 -> V_41 = V_27 ;
F_13 ( & V_9 -> V_39 ) ;
if ( V_9 -> V_42 . V_43 > 32 ) {
F_9 ( V_9 , F_15 ( & V_9 -> V_24 -> V_44 ) ,
F_15 ( & V_9 -> V_24 -> V_45 ) , 32 ) ;
}
F_9 ( V_9 , F_15 ( & V_9 -> V_24 -> V_46 ) ,
F_15 ( & V_9 -> V_24 -> V_47 ) , 0 ) ;
F_16 ( & V_9 -> V_48 ) ;
return V_49 ;
}
static void F_17 ( struct V_5 * V_9 )
{
T_4 V_50 = 0 ;
struct V_1 * V_6 ;
struct V_10 * V_13 ;
struct V_51 * V_52 ;
unsigned long V_53 ;
F_18 ( V_54 ) ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_9 -> V_42 . V_43 ; V_55 ++ ) {
V_6 = & V_9 -> V_7 [ V_55 ] ;
F_19 ( & V_6 -> V_31 , V_53 ) ;
if ( ! F_12 ( & V_6 -> V_35 ) )
F_5 ( & V_6 -> V_35 , & V_54 ) ;
F_20 ( & V_6 -> V_31 , V_53 ) ;
if ( F_12 ( & V_54 ) )
continue;
F_6 (mdesc, &list, node) {
V_52 = & V_13 -> V_52 ;
if ( V_52 -> V_56 )
V_52 -> V_56 ( V_52 -> V_57 ) ;
V_50 = V_52 -> V_58 ;
F_21 ( V_52 ) ;
}
F_19 ( & V_6 -> V_31 , V_53 ) ;
F_5 ( & V_54 , & V_6 -> free ) ;
V_6 -> V_59 = V_50 ;
F_20 ( & V_6 -> V_31 , V_53 ) ;
}
}
static void F_22 ( unsigned long V_37 )
{
struct V_5 * V_9 = ( void * ) V_37 ;
unsigned long V_53 ;
T_3 V_27 ;
F_19 ( & V_9 -> V_39 , V_53 ) ;
V_27 = V_9 -> V_41 ;
V_9 -> V_41 = 0 ;
F_20 ( & V_9 -> V_39 , V_53 ) ;
if ( V_27 ) {
F_23 ( V_9 -> V_42 . V_60 ,
L_1 ,
F_24 ( V_27 ) ) ;
if ( V_27 & V_61 )
F_23 ( V_9 -> V_42 . V_60 , L_2 ) ;
if ( V_27 & V_62 )
F_23 ( V_9 -> V_42 . V_60 , L_3 ) ;
if ( V_27 & V_63 )
F_23 ( V_9 -> V_42 . V_60 , L_4 ) ;
if ( V_27 & V_64 )
F_23 ( V_9 -> V_42 . V_60 , L_5
L_6 ) ;
if ( V_27 & V_65 )
F_23 ( V_9 -> V_42 . V_60 , L_7
L_8 ) ;
if ( V_27 & V_66 )
F_23 ( V_9 -> V_42 . V_60 , L_9
L_6 ) ;
if ( V_27 & V_67 )
F_23 ( V_9 -> V_42 . V_60 , L_10
L_6 ) ;
if ( V_27 & V_68 )
F_23 ( V_9 -> V_42 . V_60 , L_11
L_6 ) ;
if ( V_27 & V_69 )
F_23 ( V_9 -> V_42 . V_60 , L_12 ) ;
if ( V_27 & V_70 )
F_23 ( V_9 -> V_42 . V_60 , L_13 ) ;
}
F_17 ( V_9 ) ;
}
static T_4 F_25 ( struct V_51 * V_71 )
{
struct V_1 * V_6 = F_1 ( V_71 -> V_4 ) ;
struct V_10 * V_13 ;
unsigned long V_53 ;
T_4 V_58 ;
V_13 = F_2 ( V_71 , struct V_10 , V_52 ) ;
F_19 ( & V_6 -> V_31 , V_53 ) ;
F_26 ( & V_13 -> V_72 , & V_6 -> V_15 ) ;
if ( F_12 ( & V_6 -> V_16 ) )
F_4 ( V_6 ) ;
V_58 = V_6 -> V_4 . V_58 + 1 ;
if ( V_58 <= 0 )
V_58 = 1 ;
V_6 -> V_4 . V_58 = V_58 ;
V_13 -> V_52 . V_58 = V_58 ;
F_20 ( & V_6 -> V_31 , V_53 ) ;
return V_58 ;
}
static int F_27 ( struct V_2 * V_4 )
{
struct V_5 * V_9 = F_3 ( V_4 ) ;
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_10 * V_13 ;
struct V_23 * V_17 ;
T_5 V_19 ;
unsigned long V_53 ;
F_18 ( V_73 ) ;
int V_55 ;
V_17 = F_28 ( V_9 -> V_42 . V_60 ,
V_74 * sizeof( struct V_23 ) ,
& V_19 , V_75 ) ;
if ( ! V_17 )
return - V_76 ;
for ( V_55 = 0 ; V_55 < V_74 ; V_55 ++ ) {
V_13 = F_29 ( sizeof( struct V_10 ) , V_75 ) ;
if ( ! V_13 ) {
F_30 ( V_9 -> V_42 . V_60 , L_14
L_15 , V_55 ) ;
break;
}
F_31 ( & V_13 -> V_52 , V_4 ) ;
V_13 -> V_52 . V_53 = V_77 ;
V_13 -> V_52 . V_78 = F_25 ;
V_13 -> V_17 = & V_17 [ V_55 ] ;
V_13 -> V_19 = V_19 + ( V_55 * sizeof( struct V_23 ) ) ;
F_32 ( & V_13 -> V_72 , & V_73 ) ;
}
if ( V_55 == 0 ) {
F_33 ( V_9 -> V_42 . V_60 ,
V_74 * sizeof( struct V_23 ) ,
V_17 , V_19 ) ;
return - V_76 ;
}
F_19 ( & V_6 -> V_31 , V_53 ) ;
V_6 -> V_17 = V_17 ;
V_6 -> V_19 = V_19 ;
F_5 ( & V_73 , & V_6 -> free ) ;
F_20 ( & V_6 -> V_31 , V_53 ) ;
F_8 ( & V_9 -> V_24 -> V_79 , V_4 -> V_8 ) ;
return 0 ;
}
static void F_34 ( struct V_2 * V_4 )
{
struct V_5 * V_9 = F_3 ( V_4 ) ;
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_10 * V_13 , * V_80 ;
struct V_23 * V_17 ;
T_5 V_19 ;
unsigned long V_53 ;
F_18 ( V_73 ) ;
F_19 ( & V_6 -> V_31 , V_53 ) ;
F_35 ( ! F_12 ( & V_6 -> V_81 ) ) ;
F_35 ( ! F_12 ( & V_6 -> V_15 ) ) ;
F_35 ( ! F_12 ( & V_6 -> V_16 ) ) ;
F_35 ( ! F_12 ( & V_6 -> V_35 ) ) ;
F_5 ( & V_6 -> free , & V_73 ) ;
V_17 = V_6 -> V_17 ;
V_19 = V_6 -> V_19 ;
F_20 ( & V_6 -> V_31 , V_53 ) ;
F_33 ( V_9 -> V_42 . V_60 ,
V_74 * sizeof( struct V_23 ) ,
V_17 , V_19 ) ;
F_36 (mdesc, tmp, &descs, node)
F_37 ( V_13 ) ;
F_8 ( & V_9 -> V_24 -> V_82 , V_4 -> V_8 ) ;
}
static void F_38 ( struct V_2 * V_4 )
{
}
static enum V_83
F_39 ( struct V_2 * V_4 , T_4 V_58 ,
struct V_84 * V_85 )
{
struct V_1 * V_6 = F_1 ( V_4 ) ;
unsigned long V_53 ;
T_4 V_86 ;
T_4 V_87 ;
F_19 ( & V_6 -> V_31 , V_53 ) ;
V_86 = V_6 -> V_4 . V_58 ;
V_87 = V_6 -> V_59 ;
F_20 ( & V_6 -> V_31 , V_53 ) ;
F_40 ( V_85 , V_87 , V_86 , 0 ) ;
return F_41 ( V_58 , V_87 , V_86 ) ;
}
static struct V_51 *
F_42 ( struct V_2 * V_4 , T_5 V_88 , T_5 V_89 ,
T_6 V_90 , unsigned long V_53 )
{
struct V_5 * V_9 = F_3 ( V_4 ) ;
struct V_1 * V_6 = F_1 ( V_4 ) ;
struct V_10 * V_13 = NULL ;
struct V_23 * V_17 ;
unsigned long V_91 ;
F_19 ( & V_6 -> V_31 , V_91 ) ;
if ( ! F_12 ( & V_6 -> free ) ) {
V_13 = F_43 ( & V_6 -> free , struct V_10 ,
V_72 ) ;
F_44 ( & V_13 -> V_72 ) ;
}
F_20 ( & V_6 -> V_31 , V_91 ) ;
if ( ! V_13 ) {
F_17 ( V_9 ) ;
return NULL ;
}
V_13 -> error = 0 ;
V_17 = V_13 -> V_17 ;
memset ( V_17 , 0 , sizeof( struct V_23 ) ) ;
if ( F_45 ( V_89 | V_88 | V_90 , 32 ) ) {
V_17 -> V_92 = V_93 ;
V_17 -> V_94 = V_93 ;
V_17 -> V_95 = 32 ;
V_17 -> V_96 = 32 ;
} else if ( ! V_9 -> V_97 && F_45 ( V_89 | V_88 | V_90 , 16 ) ) {
V_17 -> V_92 = V_98 ;
V_17 -> V_94 = V_98 ;
V_17 -> V_95 = 16 ;
V_17 -> V_96 = 16 ;
} else if ( F_45 ( V_89 | V_88 | V_90 , 4 ) ) {
V_17 -> V_92 = V_99 ;
V_17 -> V_94 = V_99 ;
V_17 -> V_95 = 4 ;
V_17 -> V_96 = 4 ;
} else if ( F_45 ( V_89 | V_88 | V_90 , 2 ) ) {
V_17 -> V_92 = V_100 ;
V_17 -> V_94 = V_100 ;
V_17 -> V_95 = 2 ;
V_17 -> V_96 = 2 ;
} else {
V_17 -> V_92 = V_101 ;
V_17 -> V_94 = V_101 ;
V_17 -> V_95 = 1 ;
V_17 -> V_96 = 1 ;
}
V_17 -> V_102 = V_89 ;
V_17 -> V_103 = V_88 ;
V_17 -> V_104 = V_90 ;
V_17 -> V_105 = 1 ;
V_17 -> V_106 = 1 ;
F_19 ( & V_6 -> V_31 , V_91 ) ;
F_32 ( & V_13 -> V_72 , & V_6 -> V_81 ) ;
F_20 ( & V_6 -> V_31 , V_91 ) ;
return & V_13 -> V_52 ;
}
static int T_7 F_46 ( struct V_107 * V_108 )
{
struct V_109 * V_110 = V_108 -> V_60 . V_111 ;
struct V_112 * V_60 = & V_108 -> V_60 ;
struct V_113 * V_42 ;
struct V_5 * V_9 ;
struct V_1 * V_6 ;
struct V_114 V_115 ;
T_8 V_116 , V_117 ;
int V_118 , V_55 ;
V_9 = F_47 ( V_60 , sizeof( struct V_5 ) , V_75 ) ;
if ( ! V_9 ) {
F_23 ( V_60 , L_16 ) ;
return - V_76 ;
}
V_9 -> V_36 = F_48 ( V_110 , 0 ) ;
if ( V_9 -> V_36 == V_119 ) {
F_23 ( V_60 , L_17 ) ;
return - V_120 ;
}
if ( F_49 ( V_110 , L_18 ) ) {
V_9 -> V_97 = 1 ;
V_9 -> V_121 = F_48 ( V_110 , 1 ) ;
if ( V_9 -> V_121 == V_119 ) {
F_23 ( V_60 , L_17 ) ;
return - V_120 ;
}
}
V_118 = F_50 ( V_110 , 0 , & V_115 ) ;
if ( V_118 ) {
F_23 ( V_60 , L_19 ) ;
return V_118 ;
}
V_116 = V_115 . V_21 ;
V_117 = F_51 ( & V_115 ) ;
if ( ! F_52 ( V_60 , V_116 , V_117 , V_122 ) ) {
F_23 ( V_60 , L_20 ) ;
return - V_123 ;
}
V_9 -> V_24 = F_53 ( V_60 , V_116 , V_117 ) ;
if ( ! V_9 -> V_24 ) {
F_23 ( V_60 , L_21 ) ;
return - V_76 ;
}
V_9 -> V_17 = (struct V_23 * ) ( ( V_124 * ) ( V_9 -> V_24 )
+ V_125 ) ;
V_118 = F_54 ( V_60 , V_9 -> V_36 , & F_14 , 0 , V_122 ,
V_9 ) ;
if ( V_118 ) {
F_23 ( V_60 , L_22 ) ;
return - V_120 ;
}
if ( V_9 -> V_97 ) {
V_118 = F_54 ( V_60 , V_9 -> V_121 , & F_14 , 0 ,
V_122 , V_9 ) ;
if ( V_118 ) {
F_23 ( V_60 , L_23 ) ;
return - V_120 ;
}
}
F_55 ( & V_9 -> V_39 ) ;
V_42 = & V_9 -> V_42 ;
V_42 -> V_60 = V_60 ;
if ( ! V_9 -> V_97 )
V_42 -> V_43 = V_126 ;
else
V_42 -> V_43 = 16 ;
V_42 -> V_127 = F_27 ;
V_42 -> V_128 = F_34 ;
V_42 -> V_129 = F_38 ;
V_42 -> V_130 = F_39 ;
V_42 -> V_131 = F_42 ;
F_56 ( & V_42 -> V_7 ) ;
F_57 ( V_132 , V_42 -> V_133 ) ;
for ( V_55 = 0 ; V_55 < V_42 -> V_43 ; V_55 ++ ) {
V_6 = & V_9 -> V_7 [ V_55 ] ;
V_6 -> V_4 . V_112 = V_42 ;
V_6 -> V_4 . V_58 = 1 ;
V_6 -> V_59 = V_6 -> V_4 . V_58 ;
F_56 ( & V_6 -> free ) ;
F_56 ( & V_6 -> V_81 ) ;
F_56 ( & V_6 -> V_15 ) ;
F_56 ( & V_6 -> V_16 ) ;
F_56 ( & V_6 -> V_35 ) ;
F_55 ( & V_6 -> V_31 ) ;
F_32 ( & V_6 -> V_4 . V_109 , & V_42 -> V_7 ) ;
}
F_58 ( & V_9 -> V_48 , F_22 , ( unsigned long ) V_9 ) ;
if ( ! V_9 -> V_97 ) {
F_59 ( & V_9 -> V_24 -> V_134 , V_135 |
V_136 | V_137 ) ;
F_59 ( & V_9 -> V_24 -> V_138 , 0 ) ;
F_59 ( & V_9 -> V_24 -> V_139 , 0 ) ;
F_59 ( & V_9 -> V_24 -> V_140 , 0 ) ;
F_59 ( & V_9 -> V_24 -> V_141 , 0 ) ;
F_59 ( & V_9 -> V_24 -> V_44 , 0xFFFFFFFF ) ;
F_59 ( & V_9 -> V_24 -> V_46 , 0xFFFFFFFF ) ;
F_59 ( & V_9 -> V_24 -> V_45 , 0xFFFFFFFF ) ;
F_59 ( & V_9 -> V_24 -> V_47 , 0xFFFFFFFF ) ;
F_59 ( & V_9 -> V_24 -> V_142 , 0 ) ;
F_59 ( & V_9 -> V_24 -> V_143 , 0 ) ;
} else {
F_59 ( & V_9 -> V_24 -> V_134 , V_137 ) ;
F_59 ( & V_9 -> V_24 -> V_144 , V_145 ) ;
F_59 ( & V_9 -> V_24 -> V_141 , 0 ) ;
F_59 ( & V_9 -> V_24 -> V_46 , 0xFFFF ) ;
F_59 ( & V_9 -> V_24 -> V_47 , 0xFFFF ) ;
}
F_60 ( V_60 , V_9 ) ;
V_118 = F_61 ( V_42 ) ;
if ( V_118 ) {
F_62 ( V_60 , V_9 -> V_36 , V_9 ) ;
F_63 ( V_9 -> V_36 ) ;
}
return V_118 ;
}
static int T_9 F_64 ( struct V_107 * V_108 )
{
struct V_112 * V_60 = & V_108 -> V_60 ;
struct V_5 * V_9 = F_65 ( V_60 ) ;
F_66 ( & V_9 -> V_42 ) ;
F_62 ( V_60 , V_9 -> V_36 , V_9 ) ;
F_63 ( V_9 -> V_36 ) ;
return 0 ;
}
static int T_10 F_67 ( void )
{
return F_68 ( & V_146 ) ;
}
static void T_11 F_69 ( void )
{
F_70 ( & V_146 ) ;
}
