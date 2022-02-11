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
F_6 (t, &ch->rx_pending, node)
if ( F_7 ( V_11 -> V_8 ) == F_7 ( V_8 ) ) {
F_8 ( & V_11 -> V_15 ) ;
V_12 = V_11 ;
break;
}
if ( V_12 && ! F_9 ( & V_12 -> V_16 ) ) {
struct V_17 * V_18 = V_7 -> V_19 ;
unsigned int V_20 = F_10 ( V_12 -> V_21 , F_11 ( V_8 ) ) ;
V_12 -> V_22 = F_12 ( V_18 -> V_22 ) ;
F_13 ( V_12 -> V_23 , V_18 -> V_24 , V_20 ) ;
if ( V_12 -> V_21 > V_20 )
memset ( V_12 -> V_23 + V_20 , 0 , V_12 -> V_21 - V_20 ) ;
F_14 ( & V_12 -> V_16 ) ;
}
F_5 ( & V_7 -> V_13 , V_9 ) ;
}
static void F_15 ( struct V_25 * V_26 , void * V_27 )
{
struct V_6 * V_7 = F_16 ( V_26 , struct V_6 , V_28 ) ;
struct V_17 * V_18 = V_7 -> V_19 ;
T_1 V_8 = F_12 ( V_18 -> V_29 ) ;
F_2 ( V_7 , V_8 ) ;
}
static void F_17 ( struct V_25 * V_26 , void * V_27 )
{
unsigned long V_9 ;
struct V_10 * V_11 = V_27 ;
struct V_6 * V_7 = F_16 ( V_26 , struct V_6 , V_28 ) ;
struct V_17 * V_18 = (struct V_17 * ) V_7 -> V_30 ;
if ( V_11 -> V_31 )
F_18 ( V_18 -> V_24 , V_11 -> V_31 , V_11 -> V_32 ) ;
if ( V_11 -> V_23 ) {
if ( ! ( ++ V_7 -> V_33 ) )
++ V_7 -> V_33 ;
F_19 ( V_11 -> V_8 , V_7 -> V_33 ) ;
F_3 ( & V_7 -> V_13 , V_9 ) ;
F_20 ( & V_11 -> V_15 , & V_7 -> V_14 ) ;
F_5 ( & V_7 -> V_13 , V_9 ) ;
}
V_18 -> V_29 = F_21 ( V_11 -> V_8 ) ;
}
static struct V_10 * F_22 ( struct V_6 * V_7 )
{
struct V_10 * V_11 ;
F_23 ( & V_7 -> V_34 ) ;
if ( F_4 ( & V_7 -> V_35 ) ) {
F_24 ( & V_7 -> V_34 ) ;
return NULL ;
}
V_11 = F_25 ( & V_7 -> V_35 , struct V_10 , V_15 ) ;
F_8 ( & V_11 -> V_15 ) ;
F_24 ( & V_7 -> V_34 ) ;
return V_11 ;
}
static void F_26 ( struct V_10 * V_11 , struct V_6 * V_7 )
{
F_23 ( & V_7 -> V_34 ) ;
F_20 ( & V_11 -> V_15 , & V_7 -> V_35 ) ;
F_24 ( & V_7 -> V_34 ) ;
}
static int F_27 ( T_2 V_8 , void * V_31 , unsigned int V_32 ,
void * V_23 , unsigned int V_21 )
{
int V_36 ;
T_2 V_37 ;
struct V_10 * V_27 ;
struct V_6 * V_6 ;
V_37 = F_28 ( & V_38 -> V_39 ) % V_38 -> V_40 ;
V_6 = V_38 -> V_41 + V_37 ;
V_27 = F_22 ( V_6 ) ;
if ( ! V_27 )
return - V_42 ;
V_27 -> V_43 = F_29 ( V_44 ) ;
V_27 -> V_8 = F_30 ( V_8 , V_32 ) ;
V_27 -> V_31 = V_31 ;
V_27 -> V_32 = V_32 ;
V_27 -> V_23 = V_23 ;
V_27 -> V_21 = V_21 ;
F_31 ( & V_27 -> V_16 ) ;
V_36 = F_32 ( V_6 -> V_37 , V_27 ) ;
if ( V_36 < 0 || ! V_23 )
goto V_45;
if ( ! F_33 ( & V_27 -> V_16 , V_46 ) )
V_36 = - V_47 ;
else
V_36 = V_27 -> V_22 ;
V_45:
if ( V_36 < 0 && V_23 )
F_2 ( V_6 , V_27 -> V_8 ) ;
F_26 ( V_27 , V_6 ) ;
return V_36 > 0 ? F_1 ( V_36 ) : V_36 ;
}
static T_1 F_34 ( void )
{
return V_38 -> V_48 ;
}
static int
F_35 ( T_3 V_49 , unsigned long * F_10 , unsigned long * V_50 )
{
int V_36 ;
struct V_51 V_52 ;
T_4 V_53 = F_36 ( V_49 ) ;
V_36 = F_27 ( V_54 , & V_53 ,
sizeof( V_53 ) , & V_52 , sizeof( V_52 ) ) ;
if ( ! V_36 ) {
* F_10 = F_12 ( V_52 . V_55 ) ;
* V_50 = F_12 ( V_52 . V_56 ) ;
}
return V_36 ;
}
static unsigned long F_37 ( T_3 V_49 )
{
int V_36 ;
struct V_57 V_52 ;
T_4 V_53 = F_36 ( V_49 ) ;
V_36 = F_27 ( V_58 , & V_53 ,
sizeof( V_53 ) , & V_52 , sizeof( V_52 ) ) ;
return V_36 ? V_36 : F_12 ( V_52 . V_59 ) ;
}
static int F_38 ( T_3 V_49 , unsigned long V_59 )
{
int V_60 ;
struct V_61 V_52 = {
. V_62 = F_36 ( V_49 ) ,
. V_59 = F_21 (rate)
} ;
return F_27 ( V_63 , & V_52 , sizeof( V_52 ) ,
& V_60 , sizeof( V_60 ) ) ;
}
static int F_39 ( T_2 V_64 )
{
int V_36 ;
T_2 V_65 ;
V_36 = F_27 ( V_66 , & V_64 , sizeof( V_64 ) ,
& V_65 , sizeof( V_65 ) ) ;
return V_36 ? V_36 : V_65 ;
}
static int F_40 ( T_2 V_64 , T_2 V_67 )
{
int V_60 ;
struct V_68 V_69 = { V_64 , V_67 } ;
return F_27 ( V_70 , & V_69 , sizeof( V_69 ) ,
& V_60 , sizeof( V_60 ) ) ;
}
static int F_41 ( const void * V_71 , const void * V_72 )
{
const struct V_73 * V_74 = V_71 , * V_75 = V_72 ;
return V_74 -> V_76 - V_75 -> V_76 ;
}
static struct V_77 * F_42 ( T_2 V_64 )
{
struct V_77 * V_78 ;
struct V_73 * V_79 ;
struct V_80 V_81 ;
int V_36 , V_82 ;
if ( V_64 >= V_83 )
return F_43 ( - V_84 ) ;
if ( V_38 -> V_69 [ V_64 ] )
return V_38 -> V_69 [ V_64 ] ;
V_36 = F_27 ( V_85 , & V_64 , sizeof( V_64 ) ,
& V_81 , sizeof( V_81 ) ) ;
if ( V_36 )
return F_43 ( V_36 ) ;
V_78 = F_44 ( sizeof( * V_78 ) , V_86 ) ;
if ( ! V_78 )
return F_43 ( - V_42 ) ;
V_78 -> V_87 = F_45 ( V_81 . V_88 ) ;
V_78 -> V_89 = F_46 ( V_81 . V_88 ) * 1000 ;
V_78 -> V_90 = F_47 ( V_78 -> V_87 , sizeof( * V_79 ) , V_86 ) ;
if ( ! V_78 -> V_90 ) {
F_48 ( V_78 ) ;
return F_43 ( - V_42 ) ;
}
for ( V_82 = 0 , V_79 = V_78 -> V_90 ; V_82 < V_78 -> V_87 ; V_82 ++ , V_79 ++ ) {
V_79 -> V_76 = F_12 ( V_81 . V_90 [ V_82 ] . V_76 ) ;
V_79 -> V_91 = F_12 ( V_81 . V_90 [ V_82 ] . V_91 ) ;
}
F_49 ( V_78 -> V_90 , V_78 -> V_87 , sizeof( * V_79 ) , F_41 , NULL ) ;
V_38 -> V_69 [ V_64 ] = V_78 ;
return V_78 ;
}
static int F_50 ( T_3 * V_92 )
{
struct V_93 V_94 ;
int V_36 ;
V_36 = F_27 ( V_95 , NULL , 0 , & V_94 ,
sizeof( V_94 ) ) ;
if ( ! V_36 )
* V_92 = F_51 ( V_94 . V_92 ) ;
return V_36 ;
}
static int F_52 ( T_3 V_96 , struct V_97 * V_78 )
{
T_4 V_62 = F_36 ( V_96 ) ;
struct V_98 V_99 ;
int V_36 ;
V_36 = F_27 ( V_100 , & V_62 , sizeof( V_62 ) ,
& V_99 , sizeof( V_99 ) ) ;
if ( ! V_36 ) {
memcpy ( V_78 , & V_99 , sizeof( * V_78 ) ) ;
V_78 -> V_96 = F_51 ( V_99 . V_96 ) ;
}
return V_36 ;
}
static int F_53 ( T_3 V_101 , T_5 * V_102 )
{
T_4 V_62 = F_36 ( V_101 ) ;
struct V_103 V_81 ;
int V_36 ;
V_36 = F_27 ( V_104 , & V_62 , sizeof( V_62 ) ,
& V_81 , sizeof( V_81 ) ) ;
if ( ! V_36 )
* V_102 = ( T_5 ) F_12 ( V_81 . V_105 ) << 32 |
F_12 ( V_81 . V_106 ) ;
return V_36 ;
}
static int F_54 ( T_3 V_107 )
{
int V_36 ;
T_2 V_108 ;
T_4 V_62 = F_36 ( V_107 ) ;
V_36 = F_27 ( V_109 , & V_62 ,
sizeof( V_62 ) , & V_108 , sizeof( V_108 ) ) ;
return V_36 ? V_36 : V_108 ;
}
static int F_55 ( T_3 V_107 , T_2 V_108 )
{
int V_60 ;
struct V_110 V_111 = {
. V_107 = F_36 ( V_107 ) ,
. V_108 = V_108 ,
} ;
return F_27 ( V_112 , & V_111 ,
sizeof( V_111 ) , & V_60 , sizeof( V_60 ) ) ;
}
struct V_113 * F_56 ( void )
{
return V_38 ? V_38 -> V_113 : NULL ;
}
static int F_57 ( struct V_114 * V_78 )
{
int V_36 ;
struct V_115 V_116 ;
V_36 = F_27 ( V_117 , NULL , 0 ,
& V_116 , sizeof( V_116 ) ) ;
if ( ! V_36 ) {
V_78 -> V_48 = F_12 ( V_116 . V_48 ) ;
V_78 -> V_118 = F_12 ( V_116 . V_119 ) ;
}
return V_36 ;
}
static T_6 F_58 ( struct V_120 * V_121 ,
struct V_122 * V_123 , char * V_81 )
{
struct V_114 * V_38 = F_59 ( V_121 ) ;
return sprintf ( V_81 , L_1 ,
F_60 ( V_38 -> V_48 ) ,
F_61 ( V_38 -> V_48 ) ) ;
}
static T_6 F_62 ( struct V_120 * V_121 ,
struct V_122 * V_123 , char * V_81 )
{
struct V_114 * V_38 = F_59 ( V_121 ) ;
return sprintf ( V_81 , L_2 ,
F_63 ( V_38 -> V_118 ) ,
F_64 ( V_38 -> V_118 ) ,
F_65 ( V_38 -> V_118 ) ) ;
}
static void
F_66 ( struct V_120 * V_121 , struct V_6 * V_124 , int V_87 )
{
int V_82 ;
for ( V_82 = 0 ; V_82 < V_87 && V_124 -> V_37 ; V_82 ++ , V_124 ++ ) {
F_67 ( V_124 -> V_37 ) ;
F_68 ( V_121 , V_124 -> V_125 ) ;
F_69 ( V_121 , V_124 -> V_19 ) ;
}
}
static int F_70 ( struct V_126 * V_127 )
{
int V_82 ;
struct V_120 * V_121 = & V_127 -> V_121 ;
struct V_114 * V_78 = F_71 ( V_127 ) ;
V_38 = NULL ;
F_72 ( V_121 ) ;
F_73 ( & V_121 -> V_128 , V_129 ) ;
F_66 ( V_121 , V_78 -> V_41 , V_78 -> V_40 ) ;
F_74 ( V_127 , NULL ) ;
for ( V_82 = 0 ; V_82 < V_83 && V_78 -> V_69 [ V_82 ] ; V_82 ++ ) {
F_48 ( V_78 -> V_69 [ V_82 ] -> V_90 ) ;
F_48 ( V_78 -> V_69 [ V_82 ] ) ;
}
F_68 ( V_121 , V_78 -> V_41 ) ;
F_68 ( V_121 , V_78 ) ;
return 0 ;
}
static int F_75 ( struct V_120 * V_121 , struct V_6 * V_7 )
{
int V_82 ;
struct V_10 * V_125 ;
V_125 = F_76 ( V_121 , V_130 * sizeof( * V_125 ) , V_86 ) ;
if ( ! V_125 )
return - V_42 ;
V_7 -> V_125 = V_125 ;
for ( V_82 = 0 ; V_82 < V_130 ; V_82 ++ , V_125 ++ )
F_20 ( & V_125 -> V_15 , & V_7 -> V_35 ) ;
return 0 ;
}
static int F_77 ( struct V_126 * V_127 )
{
int V_87 , V_131 , V_36 ;
struct V_132 V_133 ;
struct V_6 * V_6 ;
struct V_120 * V_121 = & V_127 -> V_121 ;
struct V_134 * V_135 = V_121 -> V_136 ;
V_38 = F_76 ( V_121 , sizeof( * V_38 ) , V_86 ) ;
if ( ! V_38 )
return - V_42 ;
V_87 = F_78 ( V_135 , L_3 , L_4 ) ;
if ( V_87 < 0 ) {
F_79 ( V_121 , L_5 , V_135 -> V_137 ) ;
return - V_138 ;
}
V_6 = F_80 ( V_121 , V_87 , sizeof( * V_6 ) , V_86 ) ;
if ( ! V_6 )
return - V_42 ;
for ( V_131 = 0 ; V_131 < V_87 ; V_131 ++ ) {
T_7 V_139 ;
struct V_6 * V_124 = V_6 + V_131 ;
struct V_25 * V_28 = & V_124 -> V_28 ;
struct V_134 * V_140 = F_81 ( V_135 , L_6 , V_131 ) ;
V_36 = F_82 ( V_140 , 0 , & V_133 ) ;
F_83 ( V_140 ) ;
if ( V_36 ) {
F_79 ( V_121 , L_7 ) ;
goto V_141;
}
V_139 = F_84 ( & V_133 ) ;
V_124 -> V_19 = F_85 ( V_121 , V_133 . V_142 , V_139 ) ;
if ( ! V_124 -> V_19 ) {
F_79 ( V_121 , L_8 ) ;
V_36 = - V_143 ;
goto V_141;
}
V_124 -> V_30 = V_124 -> V_19 + ( V_139 >> 1 ) ;
V_28 -> V_121 = V_121 ;
V_28 -> V_144 = F_15 ;
V_28 -> V_145 = F_17 ;
V_28 -> V_146 = true ;
V_28 -> V_147 = 20 ;
V_28 -> V_148 = false ;
F_86 ( & V_124 -> V_14 ) ;
F_86 ( & V_124 -> V_35 ) ;
F_87 ( & V_124 -> V_13 ) ;
F_88 ( & V_124 -> V_34 ) ;
V_36 = F_75 ( V_121 , V_124 ) ;
if ( ! V_36 ) {
V_124 -> V_37 = F_89 ( V_28 , V_131 ) ;
if ( ! F_90 ( V_124 -> V_37 ) )
continue;
V_36 = F_91 ( V_124 -> V_37 ) ;
if ( V_36 != - V_149 )
F_79 ( V_121 , L_9 ,
V_131 , V_36 ) ;
}
V_141:
F_66 ( V_121 , V_6 , V_131 ) ;
V_38 = NULL ;
return V_36 ;
}
V_38 -> V_41 = V_6 ;
V_38 -> V_40 = V_87 ;
F_74 ( V_127 , V_38 ) ;
V_36 = F_57 ( V_38 ) ;
if ( V_36 ) {
F_79 ( V_121 , L_10 ) ;
F_70 ( V_127 ) ;
return V_36 ;
}
F_92 ( V_121 , L_11 ,
F_60 ( V_38 -> V_48 ) ,
F_61 ( V_38 -> V_48 ) ,
F_63 ( V_38 -> V_118 ) ,
F_64 ( V_38 -> V_118 ) ,
F_65 ( V_38 -> V_118 ) ) ;
V_38 -> V_113 = & V_113 ;
V_36 = F_93 ( & V_121 -> V_128 , V_129 ) ;
if ( V_36 )
F_79 ( V_121 , L_12 ) ;
return F_94 ( V_121 -> V_136 , NULL , NULL , V_121 ) ;
}
