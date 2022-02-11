static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static T_1 F_3 ( struct V_5 * V_5 , char T_2 * V_6 ,
T_3 V_7 , T_4 * V_8 )
{
struct V_1 * V_9 = V_5 -> V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
unsigned long V_15 ;
int V_16 ;
if ( ! V_7 )
return 0 ;
if ( ! F_4 ( V_17 , V_6 , V_7 ) )
return - V_18 ;
F_5 ( & V_9 -> V_19 , V_15 ) ;
#define F_6 (!list_empty(&hidg->completed_out_req))
while ( ! F_6 ) {
F_7 ( & V_9 -> V_19 , V_15 ) ;
if ( V_5 -> V_20 & V_21 )
return - V_22 ;
if ( F_8 ( V_9 -> V_23 , F_6 ) )
return - V_24 ;
F_5 ( & V_9 -> V_19 , V_15 ) ;
}
V_12 = F_9 ( & V_9 -> V_25 ,
struct V_11 , V_12 ) ;
V_14 = V_12 -> V_14 ;
V_7 = F_10 (unsigned int, count, req->actual - list->pos) ;
F_7 ( & V_9 -> V_19 , V_15 ) ;
V_7 -= F_11 ( V_6 , V_14 -> V_26 + V_12 -> V_27 , V_7 ) ;
V_12 -> V_27 += V_7 ;
if ( V_12 -> V_27 == V_14 -> V_28 ) {
F_5 ( & V_9 -> V_19 , V_15 ) ;
F_12 ( & V_12 -> V_12 ) ;
F_13 ( V_12 ) ;
F_7 ( & V_9 -> V_19 , V_15 ) ;
V_14 -> V_29 = V_9 -> V_30 ;
V_16 = F_14 ( V_9 -> V_31 , V_14 , V_32 ) ;
if ( V_16 < 0 )
return V_16 ;
}
return V_7 ;
}
static void F_15 ( struct V_33 * V_34 , struct V_13 * V_14 )
{
struct V_1 * V_9 = (struct V_1 * ) V_34 -> V_35 ;
if ( V_14 -> V_36 != 0 ) {
ERROR ( V_9 -> V_4 . V_37 -> V_38 ,
L_1 , V_14 -> V_36 ) ;
}
V_9 -> V_39 = 0 ;
F_16 ( & V_9 -> V_40 ) ;
}
static T_1 F_17 ( struct V_5 * V_5 , const char T_2 * V_6 ,
T_3 V_7 , T_4 * V_41 )
{
struct V_1 * V_9 = V_5 -> V_10 ;
T_1 V_36 = - V_42 ;
if ( ! F_4 ( V_43 , V_6 , V_7 ) )
return - V_18 ;
F_18 ( & V_9 -> V_44 ) ;
#define F_19 (!hidg->write_pending)
while ( ! F_19 ) {
F_20 ( & V_9 -> V_44 ) ;
if ( V_5 -> V_20 & V_21 )
return - V_22 ;
if ( F_21 (
V_9 -> V_40 , F_19 ) )
return - V_24 ;
F_18 ( & V_9 -> V_44 ) ;
}
V_7 = F_10 ( unsigned , V_7 , V_9 -> V_30 ) ;
V_36 = F_22 ( V_9 -> V_14 -> V_26 , V_6 , V_7 ) ;
if ( V_36 != 0 ) {
ERROR ( V_9 -> V_4 . V_37 -> V_38 ,
L_2 ) ;
F_20 ( & V_9 -> V_44 ) ;
return - V_45 ;
}
V_9 -> V_14 -> V_36 = 0 ;
V_9 -> V_14 -> V_46 = 0 ;
V_9 -> V_14 -> V_29 = V_7 ;
V_9 -> V_14 -> V_47 = F_15 ;
V_9 -> V_14 -> V_48 = V_9 ;
V_9 -> V_39 = 1 ;
V_36 = F_14 ( V_9 -> V_49 , V_9 -> V_14 , V_50 ) ;
if ( V_36 < 0 ) {
ERROR ( V_9 -> V_4 . V_37 -> V_38 ,
L_3 , V_36 ) ;
V_9 -> V_39 = 0 ;
F_16 ( & V_9 -> V_40 ) ;
} else {
V_36 = V_7 ;
}
F_20 ( & V_9 -> V_44 ) ;
return V_36 ;
}
static unsigned int F_23 ( struct V_5 * V_5 , T_5 * V_51 )
{
struct V_1 * V_9 = V_5 -> V_10 ;
unsigned int V_16 = 0 ;
F_24 ( V_5 , & V_9 -> V_23 , V_51 ) ;
F_24 ( V_5 , & V_9 -> V_40 , V_51 ) ;
if ( F_19 )
V_16 |= V_52 | V_53 ;
if ( F_6 )
V_16 |= V_54 | V_55 ;
return V_16 ;
}
static int F_25 ( struct V_56 * V_56 , struct V_5 * V_57 )
{
V_57 -> V_10 = NULL ;
return 0 ;
}
static int F_26 ( struct V_56 * V_56 , struct V_5 * V_57 )
{
struct V_1 * V_9 =
F_2 ( V_56 -> V_58 , struct V_1 , V_38 ) ;
V_57 -> V_10 = V_9 ;
return 0 ;
}
static inline struct V_13 * F_27 ( struct V_33 * V_34 ,
unsigned V_29 )
{
return F_28 ( V_34 , V_29 , V_29 ) ;
}
static void F_29 ( struct V_33 * V_34 , struct V_13 * V_14 )
{
struct V_1 * V_9 = (struct V_1 * ) V_14 -> V_48 ;
struct V_11 * V_59 ;
unsigned long V_15 ;
V_59 = F_30 ( sizeof( * V_59 ) , V_50 ) ;
if ( ! V_59 )
return;
V_59 -> V_14 = V_14 ;
F_5 ( & V_9 -> V_19 , V_15 ) ;
F_31 ( & V_59 -> V_12 , & V_9 -> V_25 ) ;
F_7 ( & V_9 -> V_19 , V_15 ) ;
F_16 ( & V_9 -> V_23 ) ;
}
static int F_32 ( struct V_2 * V_3 ,
const struct V_60 * V_61 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_62 * V_38 = V_3 -> V_37 -> V_38 ;
struct V_13 * V_14 = V_38 -> V_14 ;
int V_36 = 0 ;
T_6 V_63 , V_29 ;
V_63 = F_33 ( V_61 -> V_64 ) ;
V_29 = F_33 ( V_61 -> V_65 ) ;
F_34 ( V_38 ,
L_4 ,
V_66 , V_61 -> V_67 , V_61 -> V_68 , V_63 ) ;
switch ( ( V_61 -> V_67 << 8 ) | V_61 -> V_68 ) {
case ( ( V_69 | V_70 | V_71 ) << 8
| V_72 ) :
F_34 ( V_38 , L_5 ) ;
V_29 = F_10 ( unsigned , V_29 , V_9 -> V_30 ) ;
memset ( V_14 -> V_26 , 0x0 , V_29 ) ;
goto V_73;
break;
case ( ( V_69 | V_70 | V_71 ) << 8
| V_74 ) :
F_34 ( V_38 , L_6 ) ;
goto V_75;
break;
case ( ( V_76 | V_70 | V_71 ) << 8
| V_77 ) :
F_34 ( V_38 , L_7 , V_61 -> V_65 ) ;
goto V_75;
break;
case ( ( V_76 | V_70 | V_71 ) << 8
| V_78 ) :
F_34 ( V_38 , L_8 ) ;
goto V_75;
break;
case ( ( V_69 | V_79 | V_71 ) << 8
| V_80 ) :
switch ( V_63 >> 8 ) {
case V_81 :
F_34 ( V_38 , L_9 ) ;
V_29 = F_10 (unsigned short, length,
hidg_desc.bLength) ;
memcpy ( V_14 -> V_26 , & V_82 , V_29 ) ;
goto V_73;
break;
case V_83 :
F_34 ( V_38 , L_10 ) ;
V_29 = F_10 (unsigned short, length,
hidg->report_desc_length) ;
memcpy ( V_14 -> V_26 , V_9 -> V_84 , V_29 ) ;
goto V_73;
break;
default:
F_34 ( V_38 , L_11 ,
V_63 >> 8 ) ;
goto V_75;
break;
}
break;
default:
F_34 ( V_38 , L_12 ,
V_61 -> V_68 ) ;
goto V_75;
break;
}
V_75:
return - V_85 ;
V_73:
V_14 -> V_46 = 0 ;
V_14 -> V_29 = V_29 ;
V_36 = F_14 ( V_38 -> V_86 -> V_87 , V_14 , V_50 ) ;
if ( V_36 < 0 )
ERROR ( V_38 , L_13 , V_63 ) ;
return V_36 ;
}
static void F_35 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_11 * V_12 , * V_88 ;
F_36 ( V_9 -> V_49 ) ;
V_9 -> V_49 -> V_35 = NULL ;
F_36 ( V_9 -> V_31 ) ;
V_9 -> V_31 -> V_35 = NULL ;
F_37 (list, next, &hidg->completed_out_req, list) {
F_12 ( & V_12 -> V_12 ) ;
F_13 ( V_12 ) ;
}
}
static int F_38 ( struct V_2 * V_3 , unsigned V_89 , unsigned V_90 )
{
struct V_62 * V_38 = V_3 -> V_37 -> V_38 ;
struct V_1 * V_9 = F_1 ( V_3 ) ;
int V_91 , V_36 = 0 ;
F_34 ( V_38 , L_14 , V_89 , V_90 ) ;
if ( V_9 -> V_49 != NULL ) {
if ( V_9 -> V_49 -> V_35 != NULL )
F_36 ( V_9 -> V_49 ) ;
V_36 = F_39 ( V_3 -> V_37 -> V_38 -> V_86 , V_3 ,
V_9 -> V_49 ) ;
if ( V_36 ) {
ERROR ( V_38 , L_15 ) ;
goto V_92;
}
V_36 = F_40 ( V_9 -> V_49 ) ;
if ( V_36 < 0 ) {
ERROR ( V_38 , L_16 ) ;
goto V_92;
}
V_9 -> V_49 -> V_35 = V_9 ;
}
if ( V_9 -> V_31 != NULL ) {
if ( V_9 -> V_31 -> V_35 != NULL )
F_36 ( V_9 -> V_31 ) ;
V_36 = F_39 ( V_3 -> V_37 -> V_38 -> V_86 , V_3 ,
V_9 -> V_31 ) ;
if ( V_36 ) {
ERROR ( V_38 , L_15 ) ;
goto V_92;
}
V_36 = F_40 ( V_9 -> V_31 ) ;
if ( V_36 < 0 ) {
ERROR ( V_38 , L_16 ) ;
goto V_92;
}
V_9 -> V_31 -> V_35 = V_9 ;
for ( V_91 = 0 ; V_91 < V_9 -> V_93 && V_36 == 0 ; V_91 ++ ) {
struct V_13 * V_14 =
F_27 ( V_9 -> V_31 ,
V_9 -> V_30 ) ;
if ( V_14 ) {
V_14 -> V_47 = F_29 ;
V_14 -> V_48 = V_9 ;
V_36 = F_14 ( V_9 -> V_31 , V_14 ,
V_50 ) ;
if ( V_36 )
ERROR ( V_38 , L_17 ,
V_9 -> V_31 -> V_94 , V_36 ) ;
} else {
F_36 ( V_9 -> V_31 ) ;
V_9 -> V_31 -> V_35 = NULL ;
V_36 = - V_42 ;
goto V_92;
}
}
}
V_92:
return V_36 ;
}
static int F_41 ( struct V_95 * V_96 , struct V_2 * V_3 )
{
struct V_33 * V_34 ;
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_97 * V_98 ;
struct V_99 * V_99 ;
int V_36 ;
T_7 V_100 ;
V_98 = F_42 ( V_96 -> V_38 , V_101 ,
F_43 ( V_102 ) ) ;
if ( F_44 ( V_98 ) )
return F_45 ( V_98 ) ;
V_103 . V_104 = V_98 [ V_105 ] . V_106 ;
V_36 = F_46 ( V_96 , V_3 ) ;
if ( V_36 < 0 )
goto V_92;
V_103 . V_107 = V_36 ;
V_36 = - V_108 ;
V_34 = F_47 ( V_96 -> V_38 -> V_86 , & V_109 ) ;
if ( ! V_34 )
goto V_92;
V_34 -> V_35 = V_96 -> V_38 ;
V_9 -> V_49 = V_34 ;
V_34 = F_47 ( V_96 -> V_38 -> V_86 , & V_110 ) ;
if ( ! V_34 )
goto V_92;
V_34 -> V_35 = V_96 -> V_38 ;
V_9 -> V_31 = V_34 ;
V_36 = - V_42 ;
V_9 -> V_14 = F_48 ( V_9 -> V_49 , V_32 ) ;
if ( ! V_9 -> V_14 )
goto V_92;
V_9 -> V_14 -> V_26 = F_49 ( V_9 -> V_30 , V_32 ) ;
if ( ! V_9 -> V_14 -> V_26 )
goto V_92;
V_103 . V_111 = V_9 -> V_111 ;
V_103 . V_112 = V_9 -> V_112 ;
V_113 . V_114 = F_50 ( V_9 -> V_30 ) ;
V_109 . V_114 = F_50 ( V_9 -> V_30 ) ;
V_115 . V_114 = F_50 ( V_9 -> V_30 ) ;
V_110 . V_114 = F_50 ( V_9 -> V_30 ) ;
V_82 . V_116 [ 0 ] . V_117 = V_83 ;
V_82 . V_116 [ 0 ] . V_118 =
F_50 ( V_9 -> V_119 ) ;
V_113 . V_120 =
V_109 . V_120 ;
V_115 . V_120 =
V_110 . V_120 ;
V_36 = F_51 ( V_3 , V_121 ,
V_122 , NULL ) ;
if ( V_36 )
goto V_92;
F_52 ( & V_9 -> V_44 ) ;
F_53 ( & V_9 -> V_19 ) ;
F_54 ( & V_9 -> V_40 ) ;
F_54 ( & V_9 -> V_23 ) ;
F_55 ( & V_9 -> V_25 ) ;
F_56 ( & V_9 -> V_38 , & V_123 ) ;
V_100 = F_57 ( V_124 , V_9 -> V_125 ) ;
V_36 = F_58 ( & V_9 -> V_38 , V_100 , 1 ) ;
if ( V_36 )
goto V_126;
V_99 = F_59 ( V_127 , NULL , V_100 , NULL ,
L_18 , L_19 , V_9 -> V_125 ) ;
if ( F_44 ( V_99 ) ) {
V_36 = F_45 ( V_99 ) ;
goto V_128;
}
return 0 ;
V_128:
F_60 ( & V_9 -> V_38 ) ;
V_126:
F_61 ( V_3 ) ;
V_92:
ERROR ( V_3 -> V_37 -> V_38 , L_20 ) ;
if ( V_9 -> V_14 != NULL ) {
F_13 ( V_9 -> V_14 -> V_26 ) ;
if ( V_9 -> V_49 != NULL )
F_62 ( V_9 -> V_49 , V_9 -> V_14 ) ;
}
return V_36 ;
}
static inline int F_63 ( void )
{
int V_16 ;
V_16 = F_64 ( & V_129 , 0 , 0 , V_32 ) ;
return V_16 ;
}
static inline struct V_130 * F_65 ( struct V_131 * V_132 )
{
return F_2 ( F_66 ( V_132 ) , struct V_130 ,
V_133 . V_134 ) ;
}
static void F_67 ( struct V_131 * V_132 )
{
struct V_130 * V_135 = F_65 ( V_132 ) ;
F_68 ( & V_135 -> V_133 ) ;
}
static T_1 F_69 ( struct V_130 * V_135 , char * V_136 )
{
int V_137 ;
F_18 ( & V_135 -> V_44 ) ;
V_137 = V_135 -> V_119 ;
memcpy ( V_136 , V_135 -> V_84 , V_135 -> V_119 ) ;
F_20 ( & V_135 -> V_44 ) ;
return V_137 ;
}
static T_1 F_70 ( struct V_130 * V_135 ,
const char * V_136 , T_3 V_138 )
{
int V_16 = - V_139 ;
char * V_140 ;
F_18 ( & V_135 -> V_44 ) ;
if ( V_135 -> V_141 )
goto V_142;
if ( V_138 > V_143 ) {
V_16 = - V_144 ;
goto V_142;
}
V_140 = F_71 ( V_136 , V_138 , V_32 ) ;
if ( ! V_140 ) {
V_16 = - V_42 ;
goto V_142;
}
F_13 ( V_135 -> V_84 ) ;
V_135 -> V_84 = V_140 ;
V_135 -> V_119 = V_138 ;
V_135 -> V_145 = true ;
V_16 = V_138 ;
V_142:
F_20 ( & V_135 -> V_44 ) ;
return V_16 ;
}
static inline void F_72 ( int V_125 )
{
F_73 ( & V_129 , V_125 ) ;
}
static void F_74 ( struct V_146 * V_3 )
{
struct V_130 * V_135 ;
V_135 = F_2 ( V_3 , struct V_130 , V_133 ) ;
F_18 ( & V_147 ) ;
F_72 ( V_135 -> V_125 ) ;
if ( F_75 ( & V_129 . V_148 ) )
F_76 () ;
F_20 ( & V_147 ) ;
if ( V_135 -> V_145 )
F_13 ( V_135 -> V_84 ) ;
F_13 ( V_135 ) ;
}
static struct V_146 * F_77 ( void )
{
struct V_130 * V_135 ;
struct V_146 * V_16 ;
int V_36 = 0 ;
V_135 = F_30 ( sizeof( * V_135 ) , V_32 ) ;
if ( ! V_135 )
return F_78 ( - V_42 ) ;
F_52 ( & V_135 -> V_44 ) ;
V_135 -> V_133 . V_149 = F_74 ;
V_16 = & V_135 -> V_133 ;
F_18 ( & V_147 ) ;
if ( F_75 ( & V_129 . V_148 ) ) {
V_36 = F_79 ( NULL , V_150 ) ;
if ( V_36 ) {
V_16 = F_78 ( V_36 ) ;
F_13 ( V_135 ) ;
goto V_151;
}
}
V_135 -> V_125 = F_63 () ;
if ( V_135 -> V_125 < 0 ) {
V_16 = F_78 ( V_135 -> V_125 ) ;
F_13 ( V_135 ) ;
if ( F_75 ( & V_129 . V_148 ) )
F_76 () ;
goto V_151;
}
F_80 ( & V_135 -> V_133 . V_134 , L_21 , & V_152 ) ;
V_151:
F_20 ( & V_147 ) ;
return V_16 ;
}
static void F_81 ( struct V_2 * V_3 )
{
struct V_1 * V_9 ;
struct V_130 * V_135 ;
V_9 = F_1 ( V_3 ) ;
V_135 = F_2 ( V_3 -> V_153 , struct V_130 , V_133 ) ;
F_13 ( V_9 -> V_84 ) ;
F_13 ( V_9 ) ;
F_18 ( & V_135 -> V_44 ) ;
-- V_135 -> V_141 ;
F_20 ( & V_135 -> V_44 ) ;
}
static void F_82 ( struct V_95 * V_96 , struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_83 ( V_127 , F_57 ( V_124 , V_9 -> V_125 ) ) ;
F_60 ( & V_9 -> V_38 ) ;
F_36 ( V_9 -> V_49 ) ;
F_84 ( V_9 -> V_49 , V_9 -> V_14 ) ;
F_13 ( V_9 -> V_14 -> V_26 ) ;
F_62 ( V_9 -> V_49 , V_9 -> V_14 ) ;
F_61 ( V_3 ) ;
}
static struct V_2 * F_85 ( struct V_146 * V_153 )
{
struct V_1 * V_9 ;
struct V_130 * V_135 ;
V_9 = F_30 ( sizeof( * V_9 ) , V_32 ) ;
if ( ! V_9 )
return F_78 ( - V_42 ) ;
V_135 = F_2 ( V_153 , struct V_130 , V_133 ) ;
F_18 ( & V_135 -> V_44 ) ;
++ V_135 -> V_141 ;
V_9 -> V_125 = V_135 -> V_125 ;
V_9 -> V_111 = V_135 -> V_154 ;
V_9 -> V_112 = V_135 -> V_155 ;
V_9 -> V_30 = V_135 -> V_30 ;
V_9 -> V_119 = V_135 -> V_119 ;
if ( V_135 -> V_84 ) {
V_9 -> V_84 = F_71 ( V_135 -> V_84 ,
V_135 -> V_119 ,
V_32 ) ;
if ( ! V_9 -> V_84 ) {
F_13 ( V_9 ) ;
F_20 ( & V_135 -> V_44 ) ;
return F_78 ( - V_42 ) ;
}
}
F_20 ( & V_135 -> V_44 ) ;
V_9 -> V_4 . V_94 = L_22 ;
V_9 -> V_4 . V_156 = F_41 ;
V_9 -> V_4 . V_157 = F_82 ;
V_9 -> V_4 . V_158 = F_38 ;
V_9 -> V_4 . V_159 = F_35 ;
V_9 -> V_4 . V_160 = F_32 ;
V_9 -> V_4 . V_161 = F_81 ;
V_9 -> V_93 = 4 ;
return & V_9 -> V_4 ;
}
int F_79 ( struct V_162 * V_163 , int V_7 )
{
int V_36 ;
T_7 V_100 ;
V_127 = F_86 ( V_164 , L_19 ) ;
if ( F_44 ( V_127 ) ) {
V_36 = F_45 ( V_127 ) ;
V_127 = NULL ;
return V_36 ;
}
V_36 = F_87 ( & V_100 , 0 , V_7 , L_19 ) ;
if ( V_36 ) {
F_88 ( V_127 ) ;
V_127 = NULL ;
return V_36 ;
}
V_124 = F_89 ( V_100 ) ;
V_165 = V_7 ;
return 0 ;
}
void F_76 ( void )
{
if ( V_124 ) {
F_90 ( F_57 ( V_124 , 0 ) , V_165 ) ;
V_124 = V_165 = 0 ;
}
F_88 ( V_127 ) ;
V_127 = NULL ;
}
