static inline int F_1 ( int V_1 )
{
if ( V_1 >= V_2 && V_1 < V_3 )
return V_4 [ V_1 ] ;
return - V_5 ;
}
static void F_2 ( struct V_6 * V_7 , T_1 V_8 )
{
unsigned long V_9 ;
struct V_10 * V_11 , * V_12 = NULL ;
F_3 ( & V_7 -> V_13 , V_9 ) ;
if ( F_4 ( & V_7 -> V_14 ) ) {
F_5 ( & V_7 -> V_13 , V_9 ) ;
return;
}
if ( V_15 -> V_16 ) {
V_12 = F_6 ( & V_7 -> V_14 , struct V_10 ,
V_17 ) ;
F_7 ( & V_12 -> V_17 ) ;
} else {
F_8 (t, &ch->rx_pending, node)
if ( F_9 ( V_11 -> V_8 ) == F_9 ( V_8 ) ) {
F_7 ( & V_11 -> V_17 ) ;
V_12 = V_11 ;
break;
}
}
if ( V_12 && ! F_10 ( & V_12 -> V_18 ) ) {
unsigned int V_19 ;
if ( V_15 -> V_16 ) {
struct V_20 * V_21 = V_7 -> V_22 ;
V_19 = V_12 -> V_23 ;
V_12 -> V_24 = F_11 ( V_21 -> V_24 ) ;
F_12 ( V_12 -> V_25 , V_21 -> V_26 , V_19 ) ;
} else {
struct V_27 * V_21 = V_7 -> V_22 ;
V_19 = F_13 ( V_12 -> V_23 , F_14 ( V_8 ) ) ;
V_12 -> V_24 = F_11 ( V_21 -> V_24 ) ;
F_12 ( V_12 -> V_25 , V_21 -> V_26 , V_19 ) ;
}
if ( V_12 -> V_23 > V_19 )
memset ( V_12 -> V_25 + V_19 , 0 , V_12 -> V_23 - V_19 ) ;
F_15 ( & V_12 -> V_18 ) ;
}
F_5 ( & V_7 -> V_13 , V_9 ) ;
}
static void F_16 ( struct V_28 * V_29 , void * V_30 )
{
struct V_6 * V_7 = F_17 ( V_29 , struct V_6 , V_31 ) ;
struct V_27 * V_21 = V_7 -> V_22 ;
T_1 V_8 = 0 ;
if ( ! V_15 -> V_16 )
V_8 = F_11 ( V_21 -> V_32 ) ;
F_2 ( V_7 , V_8 ) ;
}
static void F_18 ( struct V_28 * V_29 , void * V_30 )
{
unsigned long V_9 ;
struct V_10 * V_11 = V_30 ;
struct V_6 * V_7 = F_17 ( V_29 , struct V_6 , V_31 ) ;
struct V_27 * V_21 = (struct V_27 * ) V_7 -> V_33 ;
if ( V_11 -> V_34 ) {
if ( V_15 -> V_16 )
F_19 ( V_7 -> V_33 , V_11 -> V_34 , V_11 -> V_35 ) ;
else
F_19 ( V_21 -> V_26 , V_11 -> V_34 , V_11 -> V_35 ) ;
}
if ( V_11 -> V_25 ) {
if ( ! ( ++ V_7 -> V_36 ) )
++ V_7 -> V_36 ;
F_20 ( V_11 -> V_8 , V_7 -> V_36 ) ;
F_3 ( & V_7 -> V_13 , V_9 ) ;
F_21 ( & V_11 -> V_17 , & V_7 -> V_14 ) ;
F_5 ( & V_7 -> V_13 , V_9 ) ;
}
if ( ! V_15 -> V_16 )
V_21 -> V_32 = F_22 ( V_11 -> V_8 ) ;
}
static struct V_10 * F_23 ( struct V_6 * V_7 )
{
struct V_10 * V_11 ;
F_24 ( & V_7 -> V_37 ) ;
if ( F_4 ( & V_7 -> V_38 ) ) {
F_25 ( & V_7 -> V_37 ) ;
return NULL ;
}
V_11 = F_6 ( & V_7 -> V_38 , struct V_10 , V_17 ) ;
F_7 ( & V_11 -> V_17 ) ;
F_25 ( & V_7 -> V_37 ) ;
return V_11 ;
}
static void F_26 ( struct V_10 * V_11 , struct V_6 * V_7 )
{
F_24 ( & V_7 -> V_37 ) ;
F_21 ( & V_11 -> V_17 , & V_7 -> V_38 ) ;
F_25 ( & V_7 -> V_37 ) ;
}
static int F_27 ( T_2 V_39 , void * V_34 , unsigned int V_35 ,
void * V_25 , unsigned int V_23 )
{
int V_40 ;
T_2 V_41 ;
T_2 V_8 ;
struct V_10 * V_30 ;
struct V_6 * V_6 ;
if ( V_15 -> V_42 [ V_39 ] < 0 )
return - V_43 ;
V_8 = V_15 -> V_42 [ V_39 ] ;
if ( V_15 -> V_16 )
V_41 = F_28 ( V_8 , V_15 -> V_44 ) ? 1 : 0 ;
else
V_41 = F_29 ( & V_15 -> V_45 ) %
V_15 -> V_46 ;
V_6 = V_15 -> V_47 + V_41 ;
V_30 = F_23 ( V_6 ) ;
if ( ! V_30 )
return - V_48 ;
if ( V_15 -> V_16 ) {
V_30 -> V_8 = F_30 ( V_8 , V_35 ) ;
V_30 -> V_49 = V_30 -> V_8 ;
} else {
V_30 -> V_49 = F_31 ( V_50 ) ;
V_30 -> V_8 = F_32 ( V_8 , V_35 ) ;
}
V_30 -> V_34 = V_34 ;
V_30 -> V_35 = V_35 ;
V_30 -> V_25 = V_25 ;
V_30 -> V_23 = V_23 ;
F_33 ( & V_30 -> V_18 ) ;
V_40 = F_34 ( V_6 -> V_41 , V_30 ) ;
if ( V_40 < 0 || ! V_25 )
goto V_51;
if ( ! F_35 ( & V_30 -> V_18 , V_52 ) )
V_40 = - V_53 ;
else
V_40 = V_30 -> V_24 ;
V_51:
if ( V_40 < 0 && V_25 )
F_2 ( V_6 , V_30 -> V_8 ) ;
F_26 ( V_30 , V_6 ) ;
return V_40 > 0 ? F_1 ( V_40 ) : V_40 ;
}
static T_1 F_36 ( void )
{
return V_15 -> V_54 ;
}
static int
F_37 ( T_3 V_55 , unsigned long * F_13 , unsigned long * V_56 )
{
int V_40 ;
struct V_57 V_58 ;
T_4 V_59 = F_38 ( V_55 ) ;
V_40 = F_27 ( V_60 , & V_59 ,
sizeof( V_59 ) , & V_58 , sizeof( V_58 ) ) ;
if ( ! V_40 ) {
* F_13 = F_11 ( V_58 . V_61 ) ;
* V_56 = F_11 ( V_58 . V_62 ) ;
}
return V_40 ;
}
static unsigned long F_39 ( T_3 V_55 )
{
int V_40 ;
struct V_63 V_58 ;
T_4 V_59 = F_38 ( V_55 ) ;
V_40 = F_27 ( V_64 , & V_59 ,
sizeof( V_59 ) , & V_58 , sizeof( V_58 ) ) ;
return V_40 ? V_40 : F_11 ( V_58 . V_65 ) ;
}
static int F_40 ( T_3 V_55 , unsigned long V_65 )
{
int V_66 ;
struct V_67 V_58 = {
. V_68 = F_38 ( V_55 ) ,
. V_65 = F_22 (rate)
} ;
return F_27 ( V_69 , & V_58 , sizeof( V_58 ) ,
& V_66 , sizeof( V_66 ) ) ;
}
static int F_41 ( T_3 V_55 , unsigned long V_65 )
{
int V_66 ;
struct V_70 V_58 = {
. V_68 = F_38 ( V_55 ) ,
. V_65 = F_22 (rate)
} ;
return F_27 ( V_69 , & V_58 , sizeof( V_58 ) ,
& V_66 , sizeof( V_66 ) ) ;
}
static int F_42 ( T_2 V_71 )
{
int V_40 ;
T_2 V_72 ;
V_40 = F_27 ( V_73 , & V_71 , sizeof( V_71 ) ,
& V_72 , sizeof( V_72 ) ) ;
return V_40 ? V_40 : V_72 ;
}
static int F_43 ( T_2 V_71 , T_2 V_74 )
{
int V_66 ;
struct V_75 V_76 = { V_71 , V_74 } ;
return F_27 ( V_77 , & V_76 , sizeof( V_76 ) ,
& V_66 , sizeof( V_66 ) ) ;
}
static int F_44 ( const void * V_78 , const void * V_79 )
{
const struct V_80 * V_81 = V_78 , * V_82 = V_79 ;
return V_81 -> V_83 - V_82 -> V_83 ;
}
static struct V_84 * F_45 ( T_2 V_71 )
{
struct V_84 * V_85 ;
struct V_80 * V_86 ;
struct V_87 V_88 ;
int V_40 , V_89 ;
if ( V_71 >= V_90 )
return F_46 ( - V_91 ) ;
if ( V_15 -> V_76 [ V_71 ] )
return V_15 -> V_76 [ V_71 ] ;
V_40 = F_27 ( V_92 , & V_71 , sizeof( V_71 ) ,
& V_88 , sizeof( V_88 ) ) ;
if ( V_40 )
return F_46 ( V_40 ) ;
V_85 = F_47 ( sizeof( * V_85 ) , V_93 ) ;
if ( ! V_85 )
return F_46 ( - V_48 ) ;
V_85 -> V_94 = F_48 ( V_88 . V_95 ) ;
V_85 -> V_96 = F_49 ( V_88 . V_95 ) * 1000 ;
V_85 -> V_97 = F_50 ( V_85 -> V_94 , sizeof( * V_86 ) , V_93 ) ;
if ( ! V_85 -> V_97 ) {
F_51 ( V_85 ) ;
return F_46 ( - V_48 ) ;
}
for ( V_89 = 0 , V_86 = V_85 -> V_97 ; V_89 < V_85 -> V_94 ; V_89 ++ , V_86 ++ ) {
V_86 -> V_83 = F_11 ( V_88 . V_97 [ V_89 ] . V_83 ) ;
V_86 -> V_98 = F_11 ( V_88 . V_97 [ V_89 ] . V_98 ) ;
}
F_52 ( V_85 -> V_97 , V_85 -> V_94 , sizeof( * V_86 ) , F_44 , NULL ) ;
V_15 -> V_76 [ V_71 ] = V_85 ;
return V_85 ;
}
static int F_53 ( struct V_99 * V_100 )
{
struct V_101 V_102 ;
if ( F_54 ( V_100 -> V_103 , L_1 , L_2 ,
0 , & V_102 ) )
return - V_91 ;
return V_102 . args [ 0 ] ;
}
static struct V_84 * V_84 ( struct V_99 * V_100 )
{
int V_71 = F_53 ( V_100 ) ;
if ( V_71 < 0 )
return F_46 ( V_71 ) ;
return F_45 ( V_71 ) ;
}
static int F_55 ( struct V_99 * V_100 )
{
struct V_84 * V_85 = V_84 ( V_100 ) ;
if ( F_56 ( V_85 ) )
return F_57 ( V_85 ) ;
if ( ! V_85 -> V_96 )
return 0 ;
return V_85 -> V_96 ;
}
static int F_58 ( struct V_99 * V_100 )
{
int V_39 , V_40 ;
struct V_80 * V_86 ;
struct V_84 * V_85 = V_84 ( V_100 ) ;
if ( F_56 ( V_85 ) )
return F_57 ( V_85 ) ;
if ( ! V_85 -> V_97 )
return - V_5 ;
for ( V_86 = V_85 -> V_97 , V_39 = 0 ; V_39 < V_85 -> V_94 ; V_39 ++ , V_86 ++ ) {
V_40 = F_59 ( V_100 , V_86 -> V_83 , V_86 -> V_98 * 1000 ) ;
if ( V_40 ) {
F_60 ( V_100 , L_3 ,
V_86 -> V_83 , V_86 -> V_98 ) ;
while ( V_39 -- > 0 )
F_61 ( V_100 , ( -- V_86 ) -> V_83 ) ;
return V_40 ;
}
}
return 0 ;
}
static int F_62 ( T_3 * V_104 )
{
struct V_105 V_106 ;
int V_40 ;
V_40 = F_27 ( V_107 , NULL , 0 , & V_106 ,
sizeof( V_106 ) ) ;
if ( ! V_40 )
* V_104 = F_63 ( V_106 . V_104 ) ;
return V_40 ;
}
static int F_64 ( T_3 V_108 , struct V_109 * V_85 )
{
T_4 V_68 = F_38 ( V_108 ) ;
struct V_110 V_111 ;
int V_40 ;
V_40 = F_27 ( V_112 , & V_68 , sizeof( V_68 ) ,
& V_111 , sizeof( V_111 ) ) ;
if ( ! V_40 ) {
memcpy ( V_85 , & V_111 , sizeof( * V_85 ) ) ;
V_85 -> V_108 = F_63 ( V_111 . V_108 ) ;
}
return V_40 ;
}
static int F_65 ( T_3 V_113 , T_5 * V_114 )
{
T_4 V_68 = F_38 ( V_113 ) ;
struct V_115 V_88 ;
int V_40 ;
V_40 = F_27 ( V_116 , & V_68 , sizeof( V_68 ) ,
& V_88 , sizeof( V_88 ) ) ;
if ( V_40 )
return V_40 ;
if ( V_15 -> V_16 )
* V_114 = F_11 ( V_88 . V_117 ) ;
else
* V_114 = ( T_5 ) F_11 ( V_88 . V_118 ) << 32 |
F_11 ( V_88 . V_117 ) ;
return 0 ;
}
static int F_66 ( T_3 V_119 )
{
int V_40 ;
T_2 V_120 ;
T_4 V_68 = F_38 ( V_119 ) ;
V_40 = F_27 ( V_121 , & V_68 ,
sizeof( V_68 ) , & V_120 , sizeof( V_120 ) ) ;
return V_40 ? V_40 : V_120 ;
}
static int F_67 ( T_3 V_119 , T_2 V_120 )
{
int V_66 ;
struct V_122 V_123 = {
. V_119 = F_38 ( V_119 ) ,
. V_120 = V_120 ,
} ;
return F_27 ( V_124 , & V_123 ,
sizeof( V_123 ) , & V_66 , sizeof( V_66 ) ) ;
}
struct V_125 * F_68 ( void )
{
return V_15 ? V_15 -> V_125 : NULL ;
}
static int F_69 ( struct V_126 * V_85 )
{
int V_40 ;
struct V_127 V_128 ;
V_40 = F_27 ( V_129 , NULL , 0 ,
& V_128 , sizeof( V_128 ) ) ;
if ( ! V_40 ) {
V_85 -> V_54 = F_11 ( V_128 . V_54 ) ;
V_85 -> V_130 = F_11 ( V_128 . V_131 ) ;
}
if ( V_15 -> V_16 && V_40 == - V_43 )
return 0 ;
return V_40 ;
}
static T_6 F_70 ( struct V_99 * V_100 ,
struct V_132 * V_133 , char * V_88 )
{
struct V_126 * V_15 = F_71 ( V_100 ) ;
return sprintf ( V_88 , L_4 ,
F_72 ( V_15 -> V_54 ) ,
F_73 ( V_15 -> V_54 ) ) ;
}
static T_6 F_74 ( struct V_99 * V_100 ,
struct V_132 * V_133 , char * V_88 )
{
struct V_126 * V_15 = F_71 ( V_100 ) ;
return sprintf ( V_88 , L_5 ,
F_75 ( V_15 -> V_130 ) ,
F_76 ( V_15 -> V_130 ) ,
F_77 ( V_15 -> V_130 ) ) ;
}
static void
F_78 ( struct V_99 * V_100 , struct V_6 * V_134 , int V_94 )
{
int V_89 ;
for ( V_89 = 0 ; V_89 < V_94 && V_134 -> V_41 ; V_89 ++ , V_134 ++ ) {
F_79 ( V_134 -> V_41 ) ;
F_80 ( V_100 , V_134 -> V_135 ) ;
F_81 ( V_100 , V_134 -> V_22 ) ;
}
}
static int F_82 ( struct V_136 * V_137 )
{
int V_89 ;
struct V_99 * V_100 = & V_137 -> V_100 ;
struct V_126 * V_85 = F_83 ( V_137 ) ;
V_15 = NULL ;
F_84 ( V_100 ) ;
F_85 ( & V_100 -> V_138 , V_139 ) ;
F_78 ( V_100 , V_85 -> V_47 , V_85 -> V_46 ) ;
F_86 ( V_137 , NULL ) ;
for ( V_89 = 0 ; V_89 < V_90 && V_85 -> V_76 [ V_89 ] ; V_89 ++ ) {
F_51 ( V_85 -> V_76 [ V_89 ] -> V_97 ) ;
F_51 ( V_85 -> V_76 [ V_89 ] ) ;
}
F_80 ( V_100 , V_85 -> V_47 ) ;
F_80 ( V_100 , V_85 ) ;
return 0 ;
}
static int F_87 ( struct V_99 * V_100 , struct V_6 * V_7 )
{
int V_89 ;
struct V_10 * V_135 ;
V_135 = F_88 ( V_100 , V_140 * sizeof( * V_135 ) , V_93 ) ;
if ( ! V_135 )
return - V_48 ;
V_7 -> V_135 = V_135 ;
for ( V_89 = 0 ; V_89 < V_140 ; V_89 ++ , V_135 ++ ) {
F_89 ( & V_135 -> V_18 ) ;
F_21 ( & V_135 -> V_17 , & V_7 -> V_38 ) ;
}
return 0 ;
}
static int F_90 ( struct V_136 * V_137 )
{
int V_94 , V_39 , V_40 ;
struct V_141 V_142 ;
struct V_6 * V_6 ;
struct V_99 * V_100 = & V_137 -> V_100 ;
struct V_143 * V_144 = V_100 -> V_103 ;
V_15 = F_88 ( V_100 , sizeof( * V_15 ) , V_93 ) ;
if ( ! V_15 )
return - V_48 ;
if ( F_91 ( V_145 , & V_137 -> V_100 ) )
V_15 -> V_16 = true ;
V_94 = F_92 ( V_144 , L_6 , L_7 ) ;
if ( V_94 < 0 ) {
F_93 ( V_100 , L_8 , V_144 ) ;
return - V_146 ;
}
V_6 = F_94 ( V_100 , V_94 , sizeof( * V_6 ) , V_93 ) ;
if ( ! V_6 )
return - V_48 ;
for ( V_39 = 0 ; V_39 < V_94 ; V_39 ++ ) {
T_7 V_147 ;
struct V_6 * V_134 = V_6 + V_39 ;
struct V_28 * V_31 = & V_134 -> V_31 ;
struct V_143 * V_148 = F_95 ( V_144 , L_9 , V_39 ) ;
V_40 = F_96 ( V_148 , 0 , & V_142 ) ;
F_97 ( V_148 ) ;
if ( V_40 ) {
F_93 ( V_100 , L_10 ) ;
goto V_149;
}
V_147 = F_98 ( & V_142 ) ;
V_134 -> V_22 = F_99 ( V_100 , V_142 . V_150 , V_147 ) ;
if ( ! V_134 -> V_22 ) {
F_93 ( V_100 , L_11 ) ;
V_40 = - V_151 ;
goto V_149;
}
V_134 -> V_33 = V_134 -> V_22 + ( V_147 >> 1 ) ;
V_31 -> V_100 = V_100 ;
V_31 -> V_152 = F_16 ;
V_31 -> V_153 = F_18 ;
V_31 -> V_154 = true ;
V_31 -> V_155 = 20 ;
V_31 -> V_156 = false ;
F_100 ( & V_134 -> V_14 ) ;
F_100 ( & V_134 -> V_38 ) ;
F_101 ( & V_134 -> V_13 ) ;
F_102 ( & V_134 -> V_37 ) ;
V_40 = F_87 ( V_100 , V_134 ) ;
if ( ! V_40 ) {
V_134 -> V_41 = F_103 ( V_31 , V_39 ) ;
if ( ! F_56 ( V_134 -> V_41 ) )
continue;
V_40 = F_57 ( V_134 -> V_41 ) ;
if ( V_40 != - V_157 )
F_93 ( V_100 , L_12 ,
V_39 , V_40 ) ;
}
V_149:
F_78 ( V_100 , V_6 , V_39 ) ;
V_15 = NULL ;
return V_40 ;
}
V_15 -> V_47 = V_6 ;
V_15 -> V_46 = V_94 ;
V_15 -> V_42 = V_158 ;
F_86 ( V_137 , V_15 ) ;
if ( V_15 -> V_16 ) {
V_125 . V_159 = F_41 ;
V_15 -> V_42 = V_160 ;
for ( V_39 = 0 ; V_39 < F_104 ( V_161 ) ; V_39 ++ )
F_105 ( V_161 [ V_39 ] ,
V_15 -> V_44 ) ;
}
V_40 = F_69 ( V_15 ) ;
if ( V_40 ) {
F_93 ( V_100 , L_13 ) ;
F_82 ( V_137 ) ;
return V_40 ;
}
F_106 ( V_100 , L_14 ,
F_72 ( V_15 -> V_54 ) ,
F_73 ( V_15 -> V_54 ) ,
F_75 ( V_15 -> V_130 ) ,
F_76 ( V_15 -> V_130 ) ,
F_77 ( V_15 -> V_130 ) ) ;
V_15 -> V_125 = & V_125 ;
V_40 = F_107 ( & V_100 -> V_138 , V_139 ) ;
if ( V_40 )
F_93 ( V_100 , L_15 ) ;
return F_108 ( V_100 -> V_103 , NULL , NULL , V_100 ) ;
}
