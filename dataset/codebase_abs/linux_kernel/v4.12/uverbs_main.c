int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
V_5 = V_2 -> V_6 -> V_7 ( V_2 ) ;
if ( ! V_5 )
F_2 ( & V_4 -> V_8 ) ;
return V_5 ;
}
static void F_3 ( struct V_9 * V_10 )
{
struct V_11 * V_12 =
F_4 ( V_10 , struct V_11 , V_10 ) ;
F_5 ( & V_12 -> V_13 ) ;
F_6 ( V_12 ) ;
}
static void F_7 ( struct V_14 * V_15 )
{
struct V_16 * V_17 =
F_4 ( V_15 , struct V_16 , V_15 ) ;
F_6 ( V_17 ) ;
}
void F_8 ( struct V_18 * V_17 ,
struct V_19 * V_20 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 , * V_25 ;
if ( V_20 ) {
F_9 ( & V_20 -> V_26 . V_27 ) ;
F_10 (evt, tmp, &uobj->comp_list, obj_list) {
F_11 ( & V_24 -> V_28 ) ;
F_6 ( V_24 ) ;
}
F_12 ( & V_20 -> V_26 . V_27 ) ;
F_13 ( & V_20 -> V_29 . V_22 ) ;
}
F_9 ( & V_17 -> V_30 -> V_26 . V_27 ) ;
F_10 (evt, tmp, &uobj->async_list, obj_list) {
F_11 ( & V_24 -> V_28 ) ;
F_6 ( V_24 ) ;
}
F_12 ( & V_17 -> V_30 -> V_26 . V_27 ) ;
}
void F_14 ( struct V_18 * V_17 ,
struct V_31 * V_22 )
{
struct V_23 * V_24 , * V_25 ;
F_9 ( & V_17 -> V_30 -> V_26 . V_27 ) ;
F_10 (evt, tmp, &uobj->event_list, obj_list) {
F_11 ( & V_24 -> V_28 ) ;
F_6 ( V_24 ) ;
}
F_12 ( & V_17 -> V_30 -> V_26 . V_27 ) ;
}
void F_15 ( struct V_32 * V_33 ,
struct V_34 * V_22 )
{
struct V_35 * V_36 , * V_25 ;
F_10 (mcast, tmp, &uobj->mcast_list, list) {
F_16 ( V_33 , & V_36 -> V_37 , V_36 -> V_38 ) ;
F_11 ( & V_36 -> V_28 ) ;
F_6 ( V_36 ) ;
}
}
static int F_17 ( struct V_18 * V_17 ,
struct V_39 * V_40 ,
bool V_41 )
{
V_40 -> V_42 = 1 ;
F_18 ( V_40 , V_41 ) ;
F_19 ( V_40 -> V_43 ) ;
F_20 ( & V_40 -> V_44 , V_40 -> V_6 ,
V_45 ) ;
return V_40 -> V_6 -> V_46 ( V_40 ) ;
}
static void F_21 ( struct V_11 * V_12 )
{
F_22 ( & V_12 -> V_47 ) ;
}
void F_23 ( struct V_14 * V_15 )
{
struct V_18 * V_17 =
F_4 ( V_15 , struct V_18 , V_15 ) ;
struct V_48 * V_49 ;
int V_50 ;
V_50 = F_24 ( & V_17 -> V_6 -> V_13 ) ;
V_49 = F_25 ( V_17 -> V_6 -> V_49 ,
& V_17 -> V_6 -> V_13 ) ;
if ( V_49 && ! V_49 -> V_51 )
F_26 ( V_49 -> V_52 ) ;
F_27 ( & V_17 -> V_6 -> V_13 , V_50 ) ;
if ( F_28 ( & V_17 -> V_6 -> V_53 ) )
F_21 ( V_17 -> V_6 ) ;
F_6 ( V_17 ) ;
}
static T_1 F_29 ( struct V_54 * V_26 ,
struct V_18 * V_55 ,
struct V_17 * V_56 , char T_2 * V_57 ,
T_3 V_58 , T_4 * V_59 ,
T_3 V_60 )
{
struct V_23 * V_61 ;
int V_5 = 0 ;
F_9 ( & V_26 -> V_27 ) ;
while ( F_30 ( & V_26 -> V_62 ) ) {
F_12 ( & V_26 -> V_27 ) ;
if ( V_56 -> V_63 & V_64 )
return - V_65 ;
if ( F_31 ( V_26 -> V_66 ,
( ! F_30 ( & V_26 -> V_62 ) ||
! V_55 -> V_6 -> V_49 ) ) )
return - V_67 ;
if ( F_30 ( & V_26 -> V_62 ) &&
! V_55 -> V_6 -> V_49 )
return - V_68 ;
F_9 ( & V_26 -> V_27 ) ;
}
V_61 = F_32 ( V_26 -> V_62 . V_69 , struct V_23 , V_28 ) ;
if ( V_60 > V_58 ) {
V_5 = - V_70 ;
V_61 = NULL ;
} else {
F_11 ( V_26 -> V_62 . V_69 ) ;
if ( V_61 -> V_71 ) {
++ ( * V_61 -> V_71 ) ;
F_11 ( & V_61 -> V_72 ) ;
}
}
F_12 ( & V_26 -> V_27 ) ;
if ( V_61 ) {
if ( F_33 ( V_57 , V_61 , V_60 ) )
V_5 = - V_73 ;
else
V_5 = V_60 ;
}
F_6 ( V_61 ) ;
return V_5 ;
}
static T_1 F_34 ( struct V_17 * V_56 , char T_2 * V_57 ,
T_3 V_58 , T_4 * V_59 )
{
struct V_16 * V_17 = V_56 -> V_74 ;
return F_29 ( & V_17 -> V_26 , V_17 -> V_55 , V_56 ,
V_57 , V_58 , V_59 ,
sizeof( struct V_75 ) ) ;
}
static T_1 F_35 ( struct V_17 * V_56 , char T_2 * V_57 ,
T_3 V_58 , T_4 * V_59 )
{
struct V_19 * V_76 =
V_56 -> V_74 ;
return F_29 ( & V_76 -> V_26 ,
V_76 -> V_29 . V_77 , V_56 ,
V_57 , V_58 , V_59 ,
sizeof( struct V_78 ) ) ;
}
static unsigned int F_36 ( struct V_54 * V_26 ,
struct V_17 * V_56 ,
struct V_79 * V_80 )
{
unsigned int V_81 = 0 ;
V_66 ( V_56 , & V_26 -> V_66 , V_80 ) ;
F_9 ( & V_26 -> V_27 ) ;
if ( ! F_30 ( & V_26 -> V_62 ) )
V_81 = V_82 | V_83 ;
F_12 ( & V_26 -> V_27 ) ;
return V_81 ;
}
static unsigned int F_37 ( struct V_17 * V_56 ,
struct V_79 * V_80 )
{
return F_36 ( V_56 -> V_74 , V_56 , V_80 ) ;
}
static unsigned int F_38 ( struct V_17 * V_56 ,
struct V_79 * V_80 )
{
struct V_19 * V_76 =
V_56 -> V_74 ;
return F_36 ( & V_76 -> V_26 , V_56 , V_80 ) ;
}
static int F_39 ( int V_84 , struct V_17 * V_56 , int V_85 )
{
struct V_54 * V_26 = V_56 -> V_74 ;
return F_40 ( V_84 , V_56 , V_85 , & V_26 -> V_86 ) ;
}
static int F_41 ( int V_84 , struct V_17 * V_56 , int V_85 )
{
struct V_19 * V_76 =
V_56 -> V_74 ;
return F_40 ( V_84 , V_56 , V_85 , & V_76 -> V_26 . V_86 ) ;
}
static int F_42 ( struct V_87 * V_87 , struct V_17 * V_56 )
{
struct V_16 * V_17 = V_56 -> V_74 ;
struct V_18 * V_55 = V_17 -> V_55 ;
struct V_23 * V_88 , * V_25 ;
int V_89 = 0 ;
F_43 ( & V_55 -> V_6 -> V_90 ) ;
F_9 ( & V_17 -> V_26 . V_27 ) ;
V_89 = V_17 -> V_26 . V_91 ;
V_17 -> V_26 . V_91 = 1 ;
F_10 (entry, tmp, &file->ev_queue.event_list, list) {
if ( V_88 -> V_71 )
F_11 ( & V_88 -> V_72 ) ;
F_6 ( V_88 ) ;
}
F_12 ( & V_17 -> V_26 . V_27 ) ;
if ( ! V_89 ) {
F_11 ( & V_17 -> V_28 ) ;
F_44 ( & V_55 -> V_92 ) ;
}
F_45 ( & V_55 -> V_6 -> V_90 ) ;
F_46 ( & V_55 -> V_15 , F_23 ) ;
F_46 ( & V_17 -> V_15 , F_7 ) ;
return 0 ;
}
static int F_47 ( struct V_87 * V_87 , struct V_17 * V_56 )
{
struct V_19 * V_17 = V_56 -> V_74 ;
struct V_23 * V_88 , * V_25 ;
F_9 ( & V_17 -> V_26 . V_27 ) ;
F_10 (entry, tmp, &file->ev_queue.event_list, list) {
if ( V_88 -> V_71 )
F_11 ( & V_88 -> V_72 ) ;
F_6 ( V_88 ) ;
}
F_12 ( & V_17 -> V_26 . V_27 ) ;
F_48 ( V_56 ) ;
return 0 ;
}
void F_49 ( struct V_93 * V_94 , void * V_95 )
{
struct V_54 * V_26 = V_95 ;
struct V_21 * V_22 ;
struct V_23 * V_88 ;
unsigned long V_96 ;
if ( ! V_26 )
return;
F_50 ( & V_26 -> V_27 , V_96 ) ;
if ( V_26 -> V_91 ) {
F_51 ( & V_26 -> V_27 , V_96 ) ;
return;
}
V_88 = F_52 ( sizeof *V_88 , V_97 ) ;
if ( ! V_88 ) {
F_51 ( & V_26 -> V_27 , V_96 ) ;
return;
}
V_22 = F_4 ( V_94 -> V_98 , struct V_21 , V_98 ) ;
V_88 -> V_99 . V_47 . V_100 = V_94 -> V_98 -> V_101 ;
V_88 -> V_71 = & V_22 -> V_102 ;
F_53 ( & V_88 -> V_28 , & V_26 -> V_62 ) ;
F_53 ( & V_88 -> V_72 , & V_22 -> V_103 ) ;
F_51 ( & V_26 -> V_27 , V_96 ) ;
F_54 ( & V_26 -> V_66 ) ;
F_55 ( & V_26 -> V_86 , V_104 , V_105 ) ;
}
static void F_56 ( struct V_18 * V_17 ,
T_5 V_106 , T_5 V_61 ,
struct V_107 * V_72 ,
T_6 * V_71 )
{
struct V_23 * V_88 ;
unsigned long V_96 ;
F_50 ( & V_17 -> V_30 -> V_26 . V_27 , V_96 ) ;
if ( V_17 -> V_30 -> V_26 . V_91 ) {
F_51 ( & V_17 -> V_30 -> V_26 . V_27 , V_96 ) ;
return;
}
V_88 = F_52 ( sizeof *V_88 , V_97 ) ;
if ( ! V_88 ) {
F_51 ( & V_17 -> V_30 -> V_26 . V_27 , V_96 ) ;
return;
}
V_88 -> V_99 . V_108 . V_106 = V_106 ;
V_88 -> V_99 . V_108 . V_109 = V_61 ;
V_88 -> V_99 . V_108 . V_110 = 0 ;
V_88 -> V_71 = V_71 ;
F_53 ( & V_88 -> V_28 , & V_17 -> V_30 -> V_26 . V_62 ) ;
if ( V_72 )
F_53 ( & V_88 -> V_72 , V_72 ) ;
F_51 ( & V_17 -> V_30 -> V_26 . V_27 , V_96 ) ;
F_54 ( & V_17 -> V_30 -> V_26 . V_66 ) ;
F_55 ( & V_17 -> V_30 -> V_26 . V_86 , V_104 , V_105 ) ;
}
void F_57 ( struct V_111 * V_61 , void * V_112 )
{
struct V_21 * V_22 = F_4 ( V_61 -> V_106 . V_94 -> V_98 ,
struct V_21 , V_98 ) ;
F_56 ( V_22 -> V_55 , V_22 -> V_98 . V_101 ,
V_61 -> V_61 , & V_22 -> V_113 ,
& V_22 -> V_114 ) ;
}
void F_58 ( struct V_111 * V_61 , void * V_112 )
{
struct V_31 * V_22 ;
if ( ! V_61 -> V_106 . V_33 -> V_98 )
return;
V_22 = F_4 ( V_61 -> V_106 . V_33 -> V_98 ,
struct V_31 , V_98 ) ;
F_56 ( V_112 , V_22 -> V_98 . V_101 ,
V_61 -> V_61 , & V_22 -> V_62 ,
& V_22 -> V_115 ) ;
}
void F_59 ( struct V_111 * V_61 , void * V_112 )
{
struct V_31 * V_22 = F_4 ( V_61 -> V_106 . V_116 -> V_98 ,
struct V_31 , V_98 ) ;
F_56 ( V_112 , V_22 -> V_98 . V_101 ,
V_61 -> V_61 , & V_22 -> V_62 ,
& V_22 -> V_115 ) ;
}
void F_60 ( struct V_111 * V_61 , void * V_112 )
{
struct V_31 * V_22 ;
V_22 = F_4 ( V_61 -> V_106 . V_117 -> V_98 ,
struct V_31 , V_98 ) ;
F_56 ( V_112 , V_22 -> V_98 . V_101 ,
V_61 -> V_61 , & V_22 -> V_62 ,
& V_22 -> V_115 ) ;
}
void F_61 ( struct V_118 * V_119 ,
struct V_111 * V_61 )
{
struct V_18 * V_17 =
F_4 ( V_119 , struct V_18 , V_92 ) ;
F_56 ( V_17 , V_61 -> V_106 . V_120 , V_61 -> V_61 ,
NULL , NULL ) ;
}
void F_62 ( struct V_18 * V_17 )
{
F_46 ( & V_17 -> V_30 -> V_15 , F_7 ) ;
V_17 -> V_30 = NULL ;
}
void F_63 ( struct V_54 * V_26 )
{
F_64 ( & V_26 -> V_27 ) ;
F_65 ( & V_26 -> V_62 ) ;
F_66 ( & V_26 -> V_66 ) ;
V_26 -> V_91 = 0 ;
V_26 -> V_86 = NULL ;
}
struct V_17 * F_67 ( struct V_18 * V_55 ,
struct V_48 * V_49 )
{
struct V_16 * V_20 ;
struct V_17 * V_56 ;
int V_5 ;
V_20 = F_68 ( sizeof( * V_20 ) , V_121 ) ;
if ( ! V_20 )
return F_69 ( - V_122 ) ;
F_63 ( & V_20 -> V_26 ) ;
V_20 -> V_55 = V_55 ;
F_70 ( & V_20 -> V_55 -> V_15 ) ;
F_71 ( & V_20 -> V_15 ) ;
V_56 = F_72 ( L_1 , & V_123 ,
V_20 , V_124 ) ;
if ( F_73 ( V_56 ) )
goto V_125;
F_43 ( & V_55 -> V_6 -> V_90 ) ;
F_53 ( & V_20 -> V_28 ,
& V_55 -> V_6 -> V_126 ) ;
F_45 ( & V_55 -> V_6 -> V_90 ) ;
F_74 ( V_55 -> V_30 ) ;
V_55 -> V_30 = V_20 ;
F_70 ( & V_55 -> V_30 -> V_15 ) ;
F_75 ( & V_55 -> V_92 ,
V_49 ,
F_61 ) ;
V_5 = F_76 ( & V_55 -> V_92 ) ;
if ( V_5 )
goto V_127;
return V_56 ;
V_127:
F_77 ( V_56 ) ;
F_46 ( & V_55 -> V_30 -> V_15 ,
F_7 ) ;
V_55 -> V_30 = NULL ;
return F_69 ( V_5 ) ;
V_125:
F_46 ( & V_20 -> V_55 -> V_15 , F_23 ) ;
F_46 ( & V_20 -> V_15 , F_7 ) ;
return V_56 ;
}
static int F_78 ( struct V_48 * V_49 , T_7 V_128 )
{
T_8 V_129 ;
if ( V_128 <= V_130 )
V_129 = V_49 -> V_131 ;
else
V_129 = V_49 -> V_132 ;
if ( V_129 & ( ( T_8 ) 1 << V_128 ) )
return 0 ;
return - 1 ;
}
static T_1 F_79 ( struct V_17 * V_56 , const char T_2 * V_57 ,
T_3 V_58 , T_4 * V_59 )
{
struct V_18 * V_17 = V_56 -> V_74 ;
struct V_48 * V_49 ;
struct V_133 V_134 ;
T_7 V_128 ;
T_7 V_96 ;
int V_50 ;
T_1 V_5 ;
if ( ! F_80 ( V_56 ) ) {
F_81 ( L_2 ,
F_82 ( V_135 ) , V_135 -> V_136 ) ;
return - V_137 ;
}
if ( V_58 < sizeof V_134 )
return - V_70 ;
if ( F_83 ( & V_134 , V_57 , sizeof V_134 ) )
return - V_73 ;
V_50 = F_24 ( & V_17 -> V_6 -> V_13 ) ;
V_49 = F_25 ( V_17 -> V_6 -> V_49 ,
& V_17 -> V_6 -> V_13 ) ;
if ( ! V_49 ) {
V_5 = - V_68 ;
goto V_138;
}
if ( V_134 . V_128 & ~ ( T_7 ) ( V_139 |
V_140 ) ) {
V_5 = - V_70 ;
goto V_138;
}
V_128 = V_134 . V_128 & V_140 ;
if ( F_78 ( V_49 , V_128 ) ) {
V_5 = - V_141 ;
goto V_138;
}
if ( ! V_17 -> V_142 &&
V_128 != V_143 ) {
V_5 = - V_70 ;
goto V_138;
}
V_96 = ( V_134 . V_128 &
V_139 ) >> V_144 ;
if ( ! V_96 ) {
if ( V_128 >= F_84 ( V_145 ) ||
! V_145 [ V_128 ] ) {
V_5 = - V_70 ;
goto V_138;
}
if ( V_134 . V_146 * 4 != V_58 ) {
V_5 = - V_70 ;
goto V_138;
}
V_5 = V_145 [ V_128 ] ( V_17 , V_49 ,
V_57 + sizeof( V_134 ) ,
V_134 . V_146 * 4 ,
V_134 . V_147 * 4 ) ;
} else if ( V_96 == V_148 ) {
struct V_149 V_150 ;
struct V_151 V_152 ;
struct V_151 V_153 ;
T_3 V_154 = V_58 ;
if ( V_128 >= F_84 ( V_155 ) ||
! V_155 [ V_128 ] ) {
V_5 = - V_156 ;
goto V_138;
}
if ( ! V_17 -> V_142 ) {
V_5 = - V_70 ;
goto V_138;
}
if ( V_58 < ( sizeof( V_134 ) + sizeof( V_150 ) ) ) {
V_5 = - V_70 ;
goto V_138;
}
if ( F_83 ( & V_150 , V_57 + sizeof( V_134 ) , sizeof( V_150 ) ) ) {
V_5 = - V_73 ;
goto V_138;
}
V_58 -= sizeof( V_134 ) + sizeof( V_150 ) ;
V_57 += sizeof( V_134 ) + sizeof( V_150 ) ;
if ( ( V_134 . V_146 + V_150 . V_157 ) * 8 != V_58 ) {
V_5 = - V_70 ;
goto V_138;
}
if ( V_150 . V_158 ) {
V_5 = - V_70 ;
goto V_138;
}
if ( V_150 . V_159 ) {
if ( ! V_134 . V_147 && ! V_150 . V_160 ) {
V_5 = - V_70 ;
goto V_138;
}
if ( ! F_85 ( V_161 ,
( void T_2 * ) ( unsigned long ) V_150 . V_159 ,
( V_134 . V_147 + V_150 . V_160 ) * 8 ) ) {
V_5 = - V_73 ;
goto V_138;
}
} else {
if ( V_134 . V_147 || V_150 . V_160 ) {
V_5 = - V_70 ;
goto V_138;
}
}
F_86 ( & V_152 , V_57 , ( unsigned long ) V_150 . V_159 ,
V_134 . V_146 * 8 , V_134 . V_147 * 8 ) ;
F_86 ( & V_153 ,
V_57 + V_152 . V_162 ,
( unsigned long ) V_150 . V_159 + V_152 . V_163 ,
V_150 . V_157 * 8 ,
V_150 . V_160 * 8 ) ;
V_5 = V_155 [ V_128 ] ( V_17 ,
V_49 ,
& V_152 ,
& V_153 ) ;
if ( ! V_5 )
V_5 = V_154 ;
} else {
V_5 = - V_156 ;
}
V_138:
F_27 ( & V_17 -> V_6 -> V_13 , V_50 ) ;
return V_5 ;
}
static int F_87 ( struct V_17 * V_56 , struct V_164 * V_165 )
{
struct V_18 * V_17 = V_56 -> V_74 ;
struct V_48 * V_49 ;
int V_5 = 0 ;
int V_50 ;
V_50 = F_24 ( & V_17 -> V_6 -> V_13 ) ;
V_49 = F_25 ( V_17 -> V_6 -> V_49 ,
& V_17 -> V_6 -> V_13 ) ;
if ( ! V_49 ) {
V_5 = - V_68 ;
goto V_138;
}
if ( ! V_17 -> V_142 )
V_5 = - V_166 ;
else
V_5 = V_49 -> V_167 ( V_17 -> V_142 , V_165 ) ;
V_138:
F_27 ( & V_17 -> V_6 -> V_13 , V_50 ) ;
return V_5 ;
}
static int F_88 ( struct V_87 * V_87 , struct V_17 * V_56 )
{
struct V_11 * V_12 ;
struct V_18 * V_17 ;
struct V_48 * V_49 ;
int V_5 ;
int V_168 ;
int V_50 ;
V_12 = F_4 ( V_87 -> V_169 , struct V_11 , V_170 ) ;
if ( ! F_89 ( & V_12 -> V_53 ) )
return - V_171 ;
V_50 = F_24 ( & V_12 -> V_13 ) ;
F_43 ( & V_12 -> V_90 ) ;
V_49 = F_25 ( V_12 -> V_49 ,
& V_12 -> V_13 ) ;
if ( ! V_49 ) {
V_5 = - V_68 ;
goto V_172;
}
V_168 = ! ( V_49 -> V_51 ) ;
if ( V_168 ) {
if ( ! F_90 ( V_49 -> V_52 ) ) {
V_5 = - V_166 ;
goto V_172;
}
}
V_17 = F_68 ( sizeof( * V_17 ) , V_121 ) ;
if ( ! V_17 ) {
V_5 = - V_122 ;
if ( V_168 )
goto V_173;
goto V_172;
}
V_17 -> V_6 = V_12 ;
F_64 ( & V_17 -> V_174 ) ;
F_91 ( & V_17 -> V_175 ) ;
V_17 -> V_142 = NULL ;
V_17 -> V_30 = NULL ;
F_71 ( & V_17 -> V_15 ) ;
F_92 ( & V_17 -> V_176 ) ;
F_92 ( & V_17 -> V_177 ) ;
V_56 -> V_74 = V_17 ;
F_93 ( & V_12 -> V_10 ) ;
F_53 ( & V_17 -> V_28 , & V_12 -> V_178 ) ;
F_45 ( & V_12 -> V_90 ) ;
F_27 ( & V_12 -> V_13 , V_50 ) ;
return F_94 ( V_87 , V_56 ) ;
V_173:
F_26 ( V_49 -> V_52 ) ;
V_172:
F_45 ( & V_12 -> V_90 ) ;
F_27 ( & V_12 -> V_13 , V_50 ) ;
if ( F_28 ( & V_12 -> V_53 ) )
F_21 ( V_12 ) ;
return V_5 ;
}
static int F_95 ( struct V_87 * V_87 , struct V_17 * V_56 )
{
struct V_18 * V_17 = V_56 -> V_74 ;
struct V_11 * V_12 = V_17 -> V_6 ;
F_43 ( & V_17 -> V_177 ) ;
if ( V_17 -> V_142 ) {
F_17 ( V_17 , V_17 -> V_142 , false ) ;
V_17 -> V_142 = NULL ;
}
F_45 ( & V_17 -> V_177 ) ;
F_96 ( & V_17 -> V_175 ) ;
F_43 ( & V_17 -> V_6 -> V_90 ) ;
if ( ! V_17 -> V_91 ) {
F_11 ( & V_17 -> V_28 ) ;
V_17 -> V_91 = 1 ;
}
F_45 ( & V_17 -> V_6 -> V_90 ) ;
if ( V_17 -> V_30 )
F_46 ( & V_17 -> V_30 -> V_15 ,
F_7 ) ;
F_46 ( & V_17 -> V_15 , F_23 ) ;
F_97 ( & V_12 -> V_10 ) ;
return 0 ;
}
static T_1 F_98 ( struct V_6 * V_6 , struct V_179 * V_180 ,
char * V_57 )
{
int V_5 = - V_166 ;
int V_50 ;
struct V_11 * V_12 = F_99 ( V_6 ) ;
struct V_48 * V_49 ;
if ( ! V_12 )
return - V_166 ;
V_50 = F_24 ( & V_12 -> V_13 ) ;
V_49 = F_25 ( V_12 -> V_49 , & V_12 -> V_13 ) ;
if ( V_49 )
V_5 = sprintf ( V_57 , L_3 , V_49 -> V_181 ) ;
F_27 ( & V_12 -> V_13 , V_50 ) ;
return V_5 ;
}
static T_1 F_100 ( struct V_6 * V_6 ,
struct V_179 * V_180 , char * V_57 )
{
struct V_11 * V_12 = F_99 ( V_6 ) ;
int V_5 = - V_166 ;
int V_50 ;
struct V_48 * V_49 ;
if ( ! V_12 )
return - V_166 ;
V_50 = F_24 ( & V_12 -> V_13 ) ;
V_49 = F_25 ( V_12 -> V_49 , & V_12 -> V_13 ) ;
if ( V_49 )
V_5 = sprintf ( V_57 , L_4 , V_49 -> V_182 ) ;
F_27 ( & V_12 -> V_13 , V_50 ) ;
return V_5 ;
}
static int F_101 ( void )
{
int V_5 ;
if ( ! V_183 ) {
V_5 = F_102 ( & V_183 , 0 , V_184 ,
L_5 ) ;
if ( V_5 ) {
F_103 ( L_6 ) ;
return V_5 ;
}
}
V_5 = F_104 ( V_185 , V_184 ) ;
if ( V_5 >= V_184 )
return - 1 ;
return V_5 ;
}
static void F_105 ( struct V_48 * V_6 )
{
int V_186 ;
T_9 V_187 ;
struct V_11 * V_188 ;
int V_5 ;
if ( ! V_6 -> V_189 )
return;
V_188 = F_68 ( sizeof *V_188 , V_121 ) ;
if ( ! V_188 )
return;
V_5 = F_106 ( & V_188 -> V_13 ) ;
if ( V_5 ) {
F_6 ( V_188 ) ;
return;
}
F_107 ( & V_188 -> V_53 , 1 ) ;
F_108 ( & V_188 -> V_47 ) ;
V_188 -> V_190 = V_191 ;
F_92 ( & V_188 -> V_192 ) ;
F_109 ( & V_188 -> V_10 , & V_193 ) ;
F_92 ( & V_188 -> V_90 ) ;
F_65 ( & V_188 -> V_178 ) ;
F_65 ( & V_188 -> V_126 ) ;
F_110 ( & V_194 ) ;
V_186 = F_104 ( V_195 , V_184 ) ;
if ( V_186 >= V_184 ) {
F_111 ( & V_194 ) ;
V_186 = F_101 () ;
if ( V_186 < 0 )
goto V_172;
F_110 ( & V_194 ) ;
V_188 -> V_186 = V_186 + V_184 ;
V_187 = V_186 + V_183 ;
F_112 ( V_186 , V_185 ) ;
} else {
V_188 -> V_186 = V_186 ;
V_187 = V_186 + V_196 ;
F_112 ( V_186 , V_195 ) ;
}
F_111 ( & V_194 ) ;
F_113 ( V_188 -> V_49 , V_6 ) ;
V_188 -> V_197 = V_6 -> V_197 ;
F_114 ( & V_188 -> V_170 , NULL ) ;
V_188 -> V_170 . V_52 = V_198 ;
V_188 -> V_170 . V_199 = V_6 -> V_167 ? & V_200 : & V_201 ;
F_115 ( & V_188 -> V_170 , & V_188 -> V_10 ) ;
F_116 ( & V_188 -> V_170 . V_10 , L_7 , V_188 -> V_186 ) ;
if ( F_117 ( & V_188 -> V_170 , V_187 , 1 ) )
goto V_202;
V_188 -> V_12 = F_118 ( V_203 , V_6 -> V_12 . V_204 ,
V_188 -> V_170 . V_12 , V_188 ,
L_7 , V_188 -> V_186 ) ;
if ( F_73 ( V_188 -> V_12 ) )
goto V_202;
if ( F_119 ( V_188 -> V_12 , & V_205 ) )
goto V_206;
if ( F_119 ( V_188 -> V_12 , & V_207 ) )
goto V_206;
F_120 ( V_6 , & V_208 , V_188 ) ;
return;
V_206:
F_121 ( V_203 , V_188 -> V_170 . V_12 ) ;
V_202:
F_122 ( & V_188 -> V_170 ) ;
if ( V_188 -> V_186 < V_184 )
F_123 ( V_186 , V_195 ) ;
else
F_123 ( V_186 , V_185 ) ;
V_172:
if ( F_28 ( & V_188 -> V_53 ) )
F_21 ( V_188 ) ;
F_124 ( & V_188 -> V_47 ) ;
F_97 ( & V_188 -> V_10 ) ;
return;
}
static void F_125 ( struct V_11 * V_188 ,
struct V_48 * V_49 )
{
struct V_18 * V_17 ;
struct V_16 * V_209 ;
struct V_111 V_61 ;
F_126 ( & V_188 -> V_13 ) ;
V_61 . V_61 = V_210 ;
V_61 . V_106 . V_120 = 0 ;
V_61 . V_6 = V_49 ;
F_43 ( & V_188 -> V_90 ) ;
while ( ! F_30 ( & V_188 -> V_178 ) ) {
struct V_39 * V_142 ;
V_17 = F_127 ( & V_188 -> V_178 ,
struct V_18 , V_28 ) ;
V_17 -> V_91 = 1 ;
F_11 ( & V_17 -> V_28 ) ;
F_70 ( & V_17 -> V_15 ) ;
F_45 ( & V_188 -> V_90 ) ;
F_61 ( & V_17 -> V_92 , & V_61 ) ;
F_43 ( & V_17 -> V_177 ) ;
V_142 = V_17 -> V_142 ;
V_17 -> V_142 = NULL ;
F_45 ( & V_17 -> V_177 ) ;
if ( V_142 ) {
V_49 -> V_51 ( V_142 ) ;
F_43 ( & V_17 -> V_177 ) ;
F_17 ( V_17 , V_142 , true ) ;
F_45 ( & V_17 -> V_177 ) ;
}
F_43 ( & V_188 -> V_90 ) ;
F_46 ( & V_17 -> V_15 , F_23 ) ;
}
while ( ! F_30 ( & V_188 -> V_126 ) ) {
V_209 = F_127 ( & V_188 ->
V_126 ,
struct V_16 ,
V_28 ) ;
F_9 ( & V_209 -> V_26 . V_27 ) ;
V_209 -> V_26 . V_91 = 1 ;
F_12 ( & V_209 -> V_26 . V_27 ) ;
F_11 ( & V_209 -> V_28 ) ;
F_44 (
& V_209 -> V_55 -> V_92 ) ;
V_209 -> V_55 -> V_92 . V_6 =
NULL ;
F_54 ( & V_209 -> V_26 . V_66 ) ;
F_55 ( & V_209 -> V_26 . V_86 , V_104 , V_105 ) ;
}
F_45 ( & V_188 -> V_90 ) ;
}
static void F_128 ( struct V_48 * V_6 , void * V_211 )
{
struct V_11 * V_188 = V_211 ;
int V_212 = 1 ;
if ( ! V_188 )
return;
F_129 ( V_188 -> V_12 , NULL ) ;
F_121 ( V_203 , V_188 -> V_170 . V_12 ) ;
F_122 ( & V_188 -> V_170 ) ;
if ( V_188 -> V_186 < V_184 )
F_123 ( V_188 -> V_186 , V_195 ) ;
else
F_123 ( V_188 -> V_186 - V_184 , V_185 ) ;
if ( V_6 -> V_51 ) {
F_113 ( V_188 -> V_49 , NULL ) ;
F_125 ( V_188 , V_6 ) ;
V_212 = 0 ;
}
if ( F_28 ( & V_188 -> V_53 ) )
F_21 ( V_188 ) ;
if ( V_212 )
F_124 ( & V_188 -> V_47 ) ;
F_97 ( & V_188 -> V_10 ) ;
}
static char * F_130 ( struct V_6 * V_12 , T_10 * V_213 )
{
if ( V_213 )
* V_213 = 0666 ;
return F_131 ( V_121 , L_8 , F_132 ( V_12 ) ) ;
}
static int T_11 F_133 ( void )
{
int V_5 ;
V_5 = F_134 ( V_196 , V_184 ,
L_5 ) ;
if ( V_5 ) {
F_103 ( L_9 ) ;
goto V_138;
}
V_203 = F_135 ( V_198 , L_5 ) ;
if ( F_73 ( V_203 ) ) {
V_5 = F_136 ( V_203 ) ;
F_103 ( L_10 ) ;
goto V_214;
}
V_203 -> V_215 = F_130 ;
V_5 = F_137 ( V_203 , & V_216 . V_180 ) ;
if ( V_5 ) {
F_103 ( L_11 ) ;
goto V_217;
}
V_5 = F_138 ( & V_208 ) ;
if ( V_5 ) {
F_103 ( L_12 ) ;
goto V_217;
}
return 0 ;
V_217:
F_139 ( V_203 ) ;
V_214:
F_140 ( V_196 , V_184 ) ;
V_138:
return V_5 ;
}
static void T_12 F_141 ( void )
{
F_142 ( & V_208 ) ;
F_139 ( V_203 ) ;
F_140 ( V_196 , V_184 ) ;
if ( V_183 )
F_140 ( V_183 , V_184 ) ;
}
