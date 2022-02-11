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
F_29 ( & V_17 -> V_6 -> V_10 ) ;
F_6 ( V_17 ) ;
}
static T_1 F_30 ( struct V_54 * V_26 ,
struct V_18 * V_55 ,
struct V_17 * V_56 , char T_2 * V_57 ,
T_3 V_58 , T_4 * V_59 ,
T_3 V_60 )
{
struct V_23 * V_61 ;
int V_5 = 0 ;
F_9 ( & V_26 -> V_27 ) ;
while ( F_31 ( & V_26 -> V_62 ) ) {
F_12 ( & V_26 -> V_27 ) ;
if ( V_56 -> V_63 & V_64 )
return - V_65 ;
if ( F_32 ( V_26 -> V_66 ,
( ! F_31 ( & V_26 -> V_62 ) ||
! V_55 -> V_6 -> V_49 ) ) )
return - V_67 ;
if ( F_31 ( & V_26 -> V_62 ) &&
! V_55 -> V_6 -> V_49 )
return - V_68 ;
F_9 ( & V_26 -> V_27 ) ;
}
V_61 = F_33 ( V_26 -> V_62 . V_69 , struct V_23 , V_28 ) ;
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
if ( F_34 ( V_57 , V_61 , V_60 ) )
V_5 = - V_73 ;
else
V_5 = V_60 ;
}
F_6 ( V_61 ) ;
return V_5 ;
}
static T_1 F_35 ( struct V_17 * V_56 , char T_2 * V_57 ,
T_3 V_58 , T_4 * V_59 )
{
struct V_16 * V_17 = V_56 -> V_74 ;
return F_30 ( & V_17 -> V_26 , V_17 -> V_55 , V_56 ,
V_57 , V_58 , V_59 ,
sizeof( struct V_75 ) ) ;
}
static T_1 F_36 ( struct V_17 * V_56 , char T_2 * V_57 ,
T_3 V_58 , T_4 * V_59 )
{
struct V_19 * V_76 =
V_56 -> V_74 ;
return F_30 ( & V_76 -> V_26 ,
V_76 -> V_29 . V_77 , V_56 ,
V_57 , V_58 , V_59 ,
sizeof( struct V_78 ) ) ;
}
static unsigned int F_37 ( struct V_54 * V_26 ,
struct V_17 * V_56 ,
struct V_79 * V_80 )
{
unsigned int V_81 = 0 ;
V_66 ( V_56 , & V_26 -> V_66 , V_80 ) ;
F_9 ( & V_26 -> V_27 ) ;
if ( ! F_31 ( & V_26 -> V_62 ) )
V_81 = V_82 | V_83 ;
F_12 ( & V_26 -> V_27 ) ;
return V_81 ;
}
static unsigned int F_38 ( struct V_17 * V_56 ,
struct V_79 * V_80 )
{
return F_37 ( V_56 -> V_74 , V_56 , V_80 ) ;
}
static unsigned int F_39 ( struct V_17 * V_56 ,
struct V_79 * V_80 )
{
struct V_19 * V_76 =
V_56 -> V_74 ;
return F_37 ( & V_76 -> V_26 , V_56 , V_80 ) ;
}
static int F_40 ( int V_84 , struct V_17 * V_56 , int V_85 )
{
struct V_54 * V_26 = V_56 -> V_74 ;
return F_41 ( V_84 , V_56 , V_85 , & V_26 -> V_86 ) ;
}
static int F_42 ( int V_84 , struct V_17 * V_56 , int V_85 )
{
struct V_19 * V_76 =
V_56 -> V_74 ;
return F_41 ( V_84 , V_56 , V_85 , & V_76 -> V_26 . V_86 ) ;
}
static int F_43 ( struct V_87 * V_87 , struct V_17 * V_56 )
{
struct V_16 * V_17 = V_56 -> V_74 ;
struct V_18 * V_55 = V_17 -> V_55 ;
struct V_23 * V_88 , * V_25 ;
int V_89 = 0 ;
F_44 ( & V_55 -> V_6 -> V_90 ) ;
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
F_45 ( & V_55 -> V_92 ) ;
}
F_46 ( & V_55 -> V_6 -> V_90 ) ;
F_47 ( & V_55 -> V_15 , F_23 ) ;
F_47 ( & V_17 -> V_15 , F_7 ) ;
return 0 ;
}
static int F_48 ( struct V_87 * V_87 , struct V_17 * V_56 )
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
F_49 ( V_56 ) ;
return 0 ;
}
void F_50 ( struct V_93 * V_94 , void * V_95 )
{
struct V_54 * V_26 = V_95 ;
struct V_21 * V_22 ;
struct V_23 * V_88 ;
unsigned long V_96 ;
if ( ! V_26 )
return;
F_51 ( & V_26 -> V_27 , V_96 ) ;
if ( V_26 -> V_91 ) {
F_52 ( & V_26 -> V_27 , V_96 ) ;
return;
}
V_88 = F_53 ( sizeof *V_88 , V_97 ) ;
if ( ! V_88 ) {
F_52 ( & V_26 -> V_27 , V_96 ) ;
return;
}
V_22 = F_4 ( V_94 -> V_98 , struct V_21 , V_98 ) ;
V_88 -> V_99 . V_47 . V_100 = V_94 -> V_98 -> V_101 ;
V_88 -> V_71 = & V_22 -> V_102 ;
F_54 ( & V_88 -> V_28 , & V_26 -> V_62 ) ;
F_54 ( & V_88 -> V_72 , & V_22 -> V_103 ) ;
F_52 ( & V_26 -> V_27 , V_96 ) ;
F_55 ( & V_26 -> V_66 ) ;
F_56 ( & V_26 -> V_86 , V_104 , V_105 ) ;
}
static void F_57 ( struct V_18 * V_17 ,
T_5 V_106 , T_5 V_61 ,
struct V_107 * V_72 ,
T_6 * V_71 )
{
struct V_23 * V_88 ;
unsigned long V_96 ;
F_51 ( & V_17 -> V_30 -> V_26 . V_27 , V_96 ) ;
if ( V_17 -> V_30 -> V_26 . V_91 ) {
F_52 ( & V_17 -> V_30 -> V_26 . V_27 , V_96 ) ;
return;
}
V_88 = F_53 ( sizeof *V_88 , V_97 ) ;
if ( ! V_88 ) {
F_52 ( & V_17 -> V_30 -> V_26 . V_27 , V_96 ) ;
return;
}
V_88 -> V_99 . V_108 . V_106 = V_106 ;
V_88 -> V_99 . V_108 . V_109 = V_61 ;
V_88 -> V_99 . V_108 . V_110 = 0 ;
V_88 -> V_71 = V_71 ;
F_54 ( & V_88 -> V_28 , & V_17 -> V_30 -> V_26 . V_62 ) ;
if ( V_72 )
F_54 ( & V_88 -> V_72 , V_72 ) ;
F_52 ( & V_17 -> V_30 -> V_26 . V_27 , V_96 ) ;
F_55 ( & V_17 -> V_30 -> V_26 . V_66 ) ;
F_56 ( & V_17 -> V_30 -> V_26 . V_86 , V_104 , V_105 ) ;
}
void F_58 ( struct V_111 * V_61 , void * V_112 )
{
struct V_21 * V_22 = F_4 ( V_61 -> V_106 . V_94 -> V_98 ,
struct V_21 , V_98 ) ;
F_57 ( V_22 -> V_55 , V_22 -> V_98 . V_101 ,
V_61 -> V_61 , & V_22 -> V_113 ,
& V_22 -> V_114 ) ;
}
void F_59 ( struct V_111 * V_61 , void * V_112 )
{
struct V_31 * V_22 ;
if ( ! V_61 -> V_106 . V_33 -> V_98 )
return;
V_22 = F_4 ( V_61 -> V_106 . V_33 -> V_98 ,
struct V_31 , V_98 ) ;
F_57 ( V_112 , V_22 -> V_98 . V_101 ,
V_61 -> V_61 , & V_22 -> V_62 ,
& V_22 -> V_115 ) ;
}
void F_60 ( struct V_111 * V_61 , void * V_112 )
{
struct V_31 * V_22 = F_4 ( V_61 -> V_106 . V_116 -> V_98 ,
struct V_31 , V_98 ) ;
F_57 ( V_112 , V_22 -> V_98 . V_101 ,
V_61 -> V_61 , & V_22 -> V_62 ,
& V_22 -> V_115 ) ;
}
void F_61 ( struct V_111 * V_61 , void * V_112 )
{
struct V_31 * V_22 ;
V_22 = F_4 ( V_61 -> V_106 . V_117 -> V_98 ,
struct V_31 , V_98 ) ;
F_57 ( V_112 , V_22 -> V_98 . V_101 ,
V_61 -> V_61 , & V_22 -> V_62 ,
& V_22 -> V_115 ) ;
}
void F_62 ( struct V_118 * V_119 ,
struct V_111 * V_61 )
{
struct V_18 * V_17 =
F_4 ( V_119 , struct V_18 , V_92 ) ;
F_57 ( V_17 , V_61 -> V_106 . V_120 , V_61 -> V_61 ,
NULL , NULL ) ;
}
void F_63 ( struct V_18 * V_17 )
{
F_47 ( & V_17 -> V_30 -> V_15 , F_7 ) ;
V_17 -> V_30 = NULL ;
}
void F_64 ( struct V_54 * V_26 )
{
F_65 ( & V_26 -> V_27 ) ;
F_66 ( & V_26 -> V_62 ) ;
F_67 ( & V_26 -> V_66 ) ;
V_26 -> V_91 = 0 ;
V_26 -> V_86 = NULL ;
}
struct V_17 * F_68 ( struct V_18 * V_55 ,
struct V_48 * V_49 )
{
struct V_16 * V_20 ;
struct V_17 * V_56 ;
V_20 = F_69 ( sizeof( * V_20 ) , V_121 ) ;
if ( ! V_20 )
return F_70 ( - V_122 ) ;
F_64 ( & V_20 -> V_26 ) ;
V_20 -> V_55 = V_55 ;
F_71 ( & V_20 -> V_55 -> V_15 ) ;
F_72 ( & V_20 -> V_15 ) ;
V_56 = F_73 ( L_1 , & V_123 ,
V_20 , V_124 ) ;
if ( F_74 ( V_56 ) )
goto V_125;
F_44 ( & V_55 -> V_6 -> V_90 ) ;
F_54 ( & V_20 -> V_28 ,
& V_55 -> V_6 -> V_126 ) ;
F_46 ( & V_55 -> V_6 -> V_90 ) ;
F_75 ( V_55 -> V_30 ) ;
V_55 -> V_30 = V_20 ;
F_71 ( & V_55 -> V_30 -> V_15 ) ;
F_76 ( & V_55 -> V_92 ,
V_49 ,
F_62 ) ;
F_77 ( & V_55 -> V_92 ) ;
return V_56 ;
V_125:
F_47 ( & V_20 -> V_55 -> V_15 , F_23 ) ;
F_47 ( & V_20 -> V_15 , F_7 ) ;
return V_56 ;
}
static int F_78 ( struct V_48 * V_49 , T_7 V_127 )
{
T_8 V_128 ;
if ( V_127 <= V_129 )
V_128 = V_49 -> V_130 ;
else
V_128 = V_49 -> V_131 ;
if ( V_128 & ( ( T_8 ) 1 << V_127 ) )
return 0 ;
return - 1 ;
}
static T_1 F_79 ( struct V_17 * V_56 , const char T_2 * V_57 ,
T_3 V_58 , T_4 * V_59 )
{
struct V_18 * V_17 = V_56 -> V_74 ;
struct V_48 * V_49 ;
struct V_132 V_133 ;
T_7 V_127 ;
T_7 V_96 ;
int V_50 ;
T_1 V_5 ;
if ( ! F_80 ( V_56 ) ) {
F_81 ( L_2 ,
F_82 ( V_134 ) , V_134 -> V_135 ) ;
return - V_136 ;
}
if ( V_58 < sizeof V_133 )
return - V_70 ;
if ( F_83 ( & V_133 , V_57 , sizeof V_133 ) )
return - V_73 ;
V_50 = F_24 ( & V_17 -> V_6 -> V_13 ) ;
V_49 = F_25 ( V_17 -> V_6 -> V_49 ,
& V_17 -> V_6 -> V_13 ) ;
if ( ! V_49 ) {
V_5 = - V_68 ;
goto V_137;
}
if ( V_133 . V_127 & ~ ( T_7 ) ( V_138 |
V_139 ) ) {
V_5 = - V_70 ;
goto V_137;
}
V_127 = V_133 . V_127 & V_139 ;
if ( F_78 ( V_49 , V_127 ) ) {
V_5 = - V_140 ;
goto V_137;
}
if ( ! V_17 -> V_141 &&
V_127 != V_142 ) {
V_5 = - V_70 ;
goto V_137;
}
V_96 = ( V_133 . V_127 &
V_138 ) >> V_143 ;
if ( ! V_96 ) {
if ( V_127 >= F_84 ( V_144 ) ||
! V_144 [ V_127 ] ) {
V_5 = - V_70 ;
goto V_137;
}
if ( V_133 . V_145 * 4 != V_58 ) {
V_5 = - V_70 ;
goto V_137;
}
V_5 = V_144 [ V_127 ] ( V_17 , V_49 ,
V_57 + sizeof( V_133 ) ,
V_133 . V_145 * 4 ,
V_133 . V_146 * 4 ) ;
} else if ( V_96 == V_147 ) {
struct V_148 V_149 ;
struct V_150 V_151 ;
struct V_150 V_152 ;
T_3 V_153 = V_58 ;
if ( V_127 >= F_84 ( V_154 ) ||
! V_154 [ V_127 ] ) {
V_5 = - V_155 ;
goto V_137;
}
if ( ! V_17 -> V_141 ) {
V_5 = - V_70 ;
goto V_137;
}
if ( V_58 < ( sizeof( V_133 ) + sizeof( V_149 ) ) ) {
V_5 = - V_70 ;
goto V_137;
}
if ( F_83 ( & V_149 , V_57 + sizeof( V_133 ) , sizeof( V_149 ) ) ) {
V_5 = - V_73 ;
goto V_137;
}
V_58 -= sizeof( V_133 ) + sizeof( V_149 ) ;
V_57 += sizeof( V_133 ) + sizeof( V_149 ) ;
if ( ( V_133 . V_145 + V_149 . V_156 ) * 8 != V_58 ) {
V_5 = - V_70 ;
goto V_137;
}
if ( V_149 . V_157 ) {
V_5 = - V_70 ;
goto V_137;
}
if ( V_149 . V_158 ) {
if ( ! V_133 . V_146 && ! V_149 . V_159 ) {
V_5 = - V_70 ;
goto V_137;
}
if ( ! F_85 ( V_160 ,
( void T_2 * ) ( unsigned long ) V_149 . V_158 ,
( V_133 . V_146 + V_149 . V_159 ) * 8 ) ) {
V_5 = - V_73 ;
goto V_137;
}
} else {
if ( V_133 . V_146 || V_149 . V_159 ) {
V_5 = - V_70 ;
goto V_137;
}
}
F_86 ( & V_151 , V_57 , ( unsigned long ) V_149 . V_158 ,
V_133 . V_145 * 8 , V_133 . V_146 * 8 ) ;
F_86 ( & V_152 ,
V_57 + V_151 . V_161 ,
( unsigned long ) V_149 . V_158 + V_151 . V_162 ,
V_149 . V_156 * 8 ,
V_149 . V_159 * 8 ) ;
V_5 = V_154 [ V_127 ] ( V_17 ,
V_49 ,
& V_151 ,
& V_152 ) ;
if ( ! V_5 )
V_5 = V_153 ;
} else {
V_5 = - V_155 ;
}
V_137:
F_27 ( & V_17 -> V_6 -> V_13 , V_50 ) ;
return V_5 ;
}
static int F_87 ( struct V_17 * V_56 , struct V_163 * V_164 )
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
goto V_137;
}
if ( ! V_17 -> V_141 )
V_5 = - V_165 ;
else
V_5 = V_49 -> V_166 ( V_17 -> V_141 , V_164 ) ;
V_137:
F_27 ( & V_17 -> V_6 -> V_13 , V_50 ) ;
return V_5 ;
}
static int F_88 ( struct V_87 * V_87 , struct V_17 * V_56 )
{
struct V_11 * V_12 ;
struct V_18 * V_17 ;
struct V_48 * V_49 ;
int V_5 ;
int V_167 ;
int V_50 ;
V_12 = F_4 ( V_87 -> V_168 , struct V_11 , V_169 ) ;
if ( ! F_89 ( & V_12 -> V_53 ) )
return - V_170 ;
V_50 = F_24 ( & V_12 -> V_13 ) ;
F_44 ( & V_12 -> V_90 ) ;
V_49 = F_25 ( V_12 -> V_49 ,
& V_12 -> V_13 ) ;
if ( ! V_49 ) {
V_5 = - V_68 ;
goto V_171;
}
V_167 = ! ( V_49 -> V_51 ) ;
if ( V_167 ) {
if ( ! F_90 ( V_49 -> V_52 ) ) {
V_5 = - V_165 ;
goto V_171;
}
}
V_17 = F_69 ( sizeof( * V_17 ) , V_121 ) ;
if ( ! V_17 ) {
V_5 = - V_122 ;
if ( V_167 )
goto V_172;
goto V_171;
}
V_17 -> V_6 = V_12 ;
F_65 ( & V_17 -> V_173 ) ;
F_91 ( & V_17 -> V_174 ) ;
V_17 -> V_141 = NULL ;
V_17 -> V_30 = NULL ;
F_72 ( & V_17 -> V_15 ) ;
F_92 ( & V_17 -> V_175 ) ;
F_92 ( & V_17 -> V_176 ) ;
V_56 -> V_74 = V_17 ;
F_93 ( & V_12 -> V_10 ) ;
F_54 ( & V_17 -> V_28 , & V_12 -> V_177 ) ;
F_46 ( & V_12 -> V_90 ) ;
F_27 ( & V_12 -> V_13 , V_50 ) ;
return F_94 ( V_87 , V_56 ) ;
V_172:
F_26 ( V_49 -> V_52 ) ;
V_171:
F_46 ( & V_12 -> V_90 ) ;
F_27 ( & V_12 -> V_13 , V_50 ) ;
if ( F_28 ( & V_12 -> V_53 ) )
F_21 ( V_12 ) ;
return V_5 ;
}
static int F_95 ( struct V_87 * V_87 , struct V_17 * V_56 )
{
struct V_18 * V_17 = V_56 -> V_74 ;
F_44 ( & V_17 -> V_176 ) ;
if ( V_17 -> V_141 ) {
F_17 ( V_17 , V_17 -> V_141 , false ) ;
V_17 -> V_141 = NULL ;
}
F_46 ( & V_17 -> V_176 ) ;
F_96 ( & V_17 -> V_174 ) ;
F_44 ( & V_17 -> V_6 -> V_90 ) ;
if ( ! V_17 -> V_91 ) {
F_11 ( & V_17 -> V_28 ) ;
V_17 -> V_91 = 1 ;
}
F_46 ( & V_17 -> V_6 -> V_90 ) ;
if ( V_17 -> V_30 )
F_47 ( & V_17 -> V_30 -> V_15 ,
F_7 ) ;
F_47 ( & V_17 -> V_15 , F_23 ) ;
return 0 ;
}
static T_1 F_97 ( struct V_6 * V_6 , struct V_178 * V_179 ,
char * V_57 )
{
int V_5 = - V_165 ;
int V_50 ;
struct V_11 * V_12 = F_98 ( V_6 ) ;
struct V_48 * V_49 ;
if ( ! V_12 )
return - V_165 ;
V_50 = F_24 ( & V_12 -> V_13 ) ;
V_49 = F_25 ( V_12 -> V_49 , & V_12 -> V_13 ) ;
if ( V_49 )
V_5 = sprintf ( V_57 , L_3 , V_49 -> V_180 ) ;
F_27 ( & V_12 -> V_13 , V_50 ) ;
return V_5 ;
}
static T_1 F_99 ( struct V_6 * V_6 ,
struct V_178 * V_179 , char * V_57 )
{
struct V_11 * V_12 = F_98 ( V_6 ) ;
int V_5 = - V_165 ;
int V_50 ;
struct V_48 * V_49 ;
if ( ! V_12 )
return - V_165 ;
V_50 = F_24 ( & V_12 -> V_13 ) ;
V_49 = F_25 ( V_12 -> V_49 , & V_12 -> V_13 ) ;
if ( V_49 )
V_5 = sprintf ( V_57 , L_4 , V_49 -> V_181 ) ;
F_27 ( & V_12 -> V_13 , V_50 ) ;
return V_5 ;
}
static int F_100 ( void )
{
int V_5 ;
if ( ! V_182 ) {
V_5 = F_101 ( & V_182 , 0 , V_183 ,
L_5 ) ;
if ( V_5 ) {
F_102 ( L_6 ) ;
return V_5 ;
}
}
V_5 = F_103 ( V_184 , V_183 ) ;
if ( V_5 >= V_183 )
return - 1 ;
return V_5 ;
}
static void F_104 ( struct V_48 * V_6 )
{
int V_185 ;
T_9 V_186 ;
struct V_11 * V_187 ;
int V_5 ;
if ( ! V_6 -> V_188 )
return;
V_187 = F_69 ( sizeof *V_187 , V_121 ) ;
if ( ! V_187 )
return;
V_5 = F_105 ( & V_187 -> V_13 ) ;
if ( V_5 ) {
F_6 ( V_187 ) ;
return;
}
F_106 ( & V_187 -> V_53 , 1 ) ;
F_107 ( & V_187 -> V_47 ) ;
V_187 -> V_189 = V_190 ;
F_92 ( & V_187 -> V_191 ) ;
F_108 ( & V_187 -> V_10 , & V_192 ) ;
F_92 ( & V_187 -> V_90 ) ;
F_66 ( & V_187 -> V_177 ) ;
F_66 ( & V_187 -> V_126 ) ;
F_109 ( & V_193 ) ;
V_185 = F_103 ( V_194 , V_183 ) ;
if ( V_185 >= V_183 ) {
F_110 ( & V_193 ) ;
V_185 = F_100 () ;
if ( V_185 < 0 )
goto V_171;
F_109 ( & V_193 ) ;
V_187 -> V_185 = V_185 + V_183 ;
V_186 = V_185 + V_182 ;
F_111 ( V_185 , V_184 ) ;
} else {
V_187 -> V_185 = V_185 ;
V_186 = V_185 + V_195 ;
F_111 ( V_185 , V_194 ) ;
}
F_110 ( & V_193 ) ;
F_112 ( V_187 -> V_49 , V_6 ) ;
V_187 -> V_196 = V_6 -> V_196 ;
F_113 ( & V_187 -> V_169 , NULL ) ;
V_187 -> V_169 . V_52 = V_197 ;
V_187 -> V_169 . V_198 = V_6 -> V_166 ? & V_199 : & V_200 ;
F_114 ( & V_187 -> V_169 , & V_187 -> V_10 ) ;
F_115 ( & V_187 -> V_169 . V_10 , L_7 , V_187 -> V_185 ) ;
if ( F_116 ( & V_187 -> V_169 , V_186 , 1 ) )
goto V_201;
V_187 -> V_12 = F_117 ( V_202 , V_6 -> V_12 . V_203 ,
V_187 -> V_169 . V_12 , V_187 ,
L_7 , V_187 -> V_185 ) ;
if ( F_74 ( V_187 -> V_12 ) )
goto V_201;
if ( F_118 ( V_187 -> V_12 , & V_204 ) )
goto V_205;
if ( F_118 ( V_187 -> V_12 , & V_206 ) )
goto V_205;
if ( ! V_6 -> V_207 ) {
const struct V_208 * V_209 [] = {
F_119 () } ;
V_187 -> V_207 = F_120 ( 1 ,
V_209 ) ;
if ( F_74 ( V_187 -> V_207 ) )
goto V_205;
V_6 -> V_207 = V_187 -> V_207 ;
}
F_121 ( V_6 , & V_210 , V_187 ) ;
return;
V_205:
F_122 ( V_202 , V_187 -> V_169 . V_12 ) ;
V_201:
F_123 ( & V_187 -> V_169 ) ;
if ( V_187 -> V_185 < V_183 )
F_124 ( V_185 , V_194 ) ;
else
F_124 ( V_185 , V_184 ) ;
V_171:
if ( F_28 ( & V_187 -> V_53 ) )
F_21 ( V_187 ) ;
F_125 ( & V_187 -> V_47 ) ;
F_29 ( & V_187 -> V_10 ) ;
return;
}
static void F_126 ( struct V_11 * V_187 ,
struct V_48 * V_49 )
{
struct V_18 * V_17 ;
struct V_16 * V_211 ;
struct V_111 V_61 ;
F_127 ( & V_187 -> V_13 ) ;
V_61 . V_61 = V_212 ;
V_61 . V_106 . V_120 = 0 ;
V_61 . V_6 = V_49 ;
F_44 ( & V_187 -> V_90 ) ;
while ( ! F_31 ( & V_187 -> V_177 ) ) {
struct V_39 * V_141 ;
V_17 = F_128 ( & V_187 -> V_177 ,
struct V_18 , V_28 ) ;
V_17 -> V_91 = 1 ;
F_11 ( & V_17 -> V_28 ) ;
F_71 ( & V_17 -> V_15 ) ;
F_46 ( & V_187 -> V_90 ) ;
F_44 ( & V_17 -> V_176 ) ;
V_141 = V_17 -> V_141 ;
V_17 -> V_141 = NULL ;
F_46 ( & V_17 -> V_176 ) ;
if ( V_141 ) {
F_62 ( & V_17 -> V_92 , & V_61 ) ;
V_49 -> V_51 ( V_141 ) ;
F_44 ( & V_17 -> V_176 ) ;
F_17 ( V_17 , V_141 , true ) ;
F_46 ( & V_17 -> V_176 ) ;
}
F_44 ( & V_187 -> V_90 ) ;
F_47 ( & V_17 -> V_15 , F_23 ) ;
}
while ( ! F_31 ( & V_187 -> V_126 ) ) {
V_211 = F_128 ( & V_187 ->
V_126 ,
struct V_16 ,
V_28 ) ;
F_9 ( & V_211 -> V_26 . V_27 ) ;
V_211 -> V_26 . V_91 = 1 ;
F_12 ( & V_211 -> V_26 . V_27 ) ;
F_11 ( & V_211 -> V_28 ) ;
F_45 (
& V_211 -> V_55 -> V_92 ) ;
V_211 -> V_55 -> V_92 . V_6 =
NULL ;
F_55 ( & V_211 -> V_26 . V_66 ) ;
F_56 ( & V_211 -> V_26 . V_86 , V_104 , V_105 ) ;
}
F_46 ( & V_187 -> V_90 ) ;
}
static void F_129 ( struct V_48 * V_6 , void * V_213 )
{
struct V_11 * V_187 = V_213 ;
int V_214 = 1 ;
if ( ! V_187 )
return;
F_130 ( V_187 -> V_12 , NULL ) ;
F_122 ( V_202 , V_187 -> V_169 . V_12 ) ;
F_123 ( & V_187 -> V_169 ) ;
if ( V_187 -> V_185 < V_183 )
F_124 ( V_187 -> V_185 , V_194 ) ;
else
F_124 ( V_187 -> V_185 - V_183 , V_184 ) ;
if ( V_6 -> V_51 ) {
F_112 ( V_187 -> V_49 , NULL ) ;
F_126 ( V_187 , V_6 ) ;
V_214 = 0 ;
}
if ( F_28 ( & V_187 -> V_53 ) )
F_21 ( V_187 ) ;
if ( V_214 )
F_125 ( & V_187 -> V_47 ) ;
if ( V_187 -> V_207 ) {
F_131 ( V_187 -> V_207 ) ;
V_6 -> V_207 = NULL ;
}
F_29 ( & V_187 -> V_10 ) ;
}
static char * F_132 ( struct V_6 * V_12 , T_10 * V_215 )
{
if ( V_215 )
* V_215 = 0666 ;
return F_133 ( V_121 , L_8 , F_134 ( V_12 ) ) ;
}
static int T_11 F_135 ( void )
{
int V_5 ;
V_5 = F_136 ( V_195 , V_183 ,
L_5 ) ;
if ( V_5 ) {
F_102 ( L_9 ) ;
goto V_137;
}
V_202 = F_137 ( V_197 , L_5 ) ;
if ( F_74 ( V_202 ) ) {
V_5 = F_138 ( V_202 ) ;
F_102 ( L_10 ) ;
goto V_216;
}
V_202 -> V_217 = F_132 ;
V_5 = F_139 ( V_202 , & V_218 . V_179 ) ;
if ( V_5 ) {
F_102 ( L_11 ) ;
goto V_219;
}
V_5 = F_140 ( & V_210 ) ;
if ( V_5 ) {
F_102 ( L_12 ) ;
goto V_219;
}
return 0 ;
V_219:
F_141 ( V_202 ) ;
V_216:
F_142 ( V_195 , V_183 ) ;
V_137:
return V_5 ;
}
static void T_12 F_143 ( void )
{
F_144 ( & V_210 ) ;
F_141 ( V_202 ) ;
F_142 ( V_195 , V_183 ) ;
if ( V_182 )
F_142 ( V_182 , V_183 ) ;
}
