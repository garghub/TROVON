static inline void F_1 ( struct V_1 * V_1 )
{
F_2 ( & V_1 -> V_2 ) ;
}
static void F_3 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_4 ( V_2 , struct V_1 , V_2 ) ;
F_5 ( V_1 -> V_3 ) ;
F_6 ( V_1 ) ;
}
static void F_7 ( struct V_1 * V_1 )
{
F_8 ( & V_1 -> V_2 , F_3 ) ;
}
static void F_9 ( struct V_4 * V_5 , unsigned long V_6 )
{
F_1 ( V_5 -> V_1 ) ;
if ( ! F_10 ( V_7 , & V_5 -> V_8 , V_6 ) )
F_7 ( V_5 -> V_1 ) ;
}
static void F_11 ( struct V_9 * V_10 )
{
if ( V_10 -> V_11 == V_12 )
F_9 ( F_4 ( V_10 ,
struct V_4 , V_10 ) , 0 ) ;
}
static void T_1 * F_12 ( T_2 V_13 )
{
if ( F_13 () )
return F_14 ( V_13 ) ;
else
return ( void T_1 * ) ( unsigned long ) V_13 ;
}
static T_2 F_15 ( void T_1 * V_14 )
{
if ( F_13 () )
return F_16 ( V_14 ) ;
else
return ( T_2 ) ( unsigned long ) V_14 ;
}
static inline void T_1 * F_12 ( T_2 V_13 )
{
return ( void T_1 * ) ( unsigned long ) V_13 ;
}
static inline T_2 F_15 ( void T_1 * V_14 )
{
return ( T_2 ) ( unsigned long ) V_14 ;
}
static int F_17 ( struct V_15 * V_15 , struct V_16 * V_16 )
{
struct V_17 * V_3 ;
struct V_1 * V_1 ;
V_3 = F_18 ( V_15 -> V_18 ) ;
if ( V_3 == NULL )
return - V_19 ;
if ( F_19 ( V_3 ) ) {
F_5 ( V_3 ) ;
return - V_19 ;
}
V_1 = F_20 ( sizeof( * V_1 ) , V_20 ) ;
if ( V_1 == NULL ) {
F_5 ( V_3 ) ;
return - V_21 ;
}
V_1 -> V_3 = V_3 ;
F_21 ( & V_1 -> V_22 ) ;
F_22 ( & V_1 -> V_23 ) ;
F_23 ( & V_1 -> V_24 ) ;
F_24 ( & V_1 -> V_25 ) ;
F_24 ( & V_1 -> V_26 ) ;
F_23 ( & V_1 -> V_27 ) ;
F_23 ( & V_1 -> V_28 ) ;
F_25 ( & V_1 -> V_2 ) ;
V_16 -> V_29 = V_1 ;
return F_26 ( V_15 , V_16 ) ;
}
static void F_27 ( struct V_1 * V_1 , struct V_30 * V_30 ,
void * V_31 , T_3 V_32 , void * V_33 , T_3 V_34 )
{
unsigned long V_35 ;
V_30 -> V_36 [ 0 ] . V_37 = V_31 ;
V_30 -> V_36 [ 0 ] . V_38 = V_32 ;
V_30 -> V_36 [ 1 ] . V_37 = V_33 ;
V_30 -> V_36 [ 1 ] . V_38 = V_34 ;
F_28 ( & V_1 -> V_22 , V_35 ) ;
if ( V_1 -> V_39 )
F_6 ( V_30 ) ;
else
F_29 ( & V_30 -> V_28 , & V_1 -> V_24 ) ;
F_30 ( & V_1 -> V_22 , V_35 ) ;
F_31 ( & V_1 -> V_25 ) ;
}
static int F_32 ( struct V_1 * V_1 ,
char T_1 * V_40 , T_3 V_41 )
{
struct V_30 * V_30 ;
T_3 V_38 , V_42 ;
int V_43 , V_44 ;
V_44 = F_33 ( V_1 -> V_25 ,
! F_34 ( & V_1 -> V_24 ) ||
F_19 ( V_1 -> V_3 ) ) ;
if ( V_44 < 0 )
return V_44 ;
if ( F_34 ( & V_1 -> V_24 ) &&
F_19 ( V_1 -> V_3 ) )
return - V_19 ;
F_35 ( & V_1 -> V_22 ) ;
V_30 = F_36 ( & V_1 -> V_24 , struct V_30 , V_28 ) ;
F_37 ( & V_30 -> V_28 ) ;
F_38 ( & V_1 -> V_22 ) ;
V_42 = 0 ;
for ( V_43 = 0 ; V_43 < F_39 ( V_30 -> V_36 ) && V_42 < V_41 ; V_43 ++ ) {
V_38 = F_40 ( V_30 -> V_36 [ V_43 ] . V_38 , V_41 - V_42 ) ;
if ( F_41 ( V_40 + V_42 , V_30 -> V_36 [ V_43 ] . V_37 , V_38 ) ) {
V_44 = - V_45 ;
goto V_46;
}
V_42 += V_38 ;
}
V_44 = V_42 ;
V_46:
F_6 ( V_30 ) ;
return V_44 ;
}
static T_4 F_42 ( struct V_16 * V_16 , char T_1 * V_40 ,
T_3 V_41 , T_5 * V_47 )
{
struct V_1 * V_1 = V_16 -> V_29 ;
return F_32 ( V_1 , V_40 , V_41 ) ;
}
static void F_43 ( struct V_48 * V_30 ,
struct V_1 * V_1 )
{
struct V_49 * V_50 = V_1 -> V_3 -> V_50 ;
F_35 ( & V_50 -> V_22 ) ;
V_30 -> V_51 = V_1 -> V_52 ;
V_30 -> type = V_53 ;
V_30 -> V_54 = V_1 -> V_3 -> V_54 ;
V_30 -> V_55 = V_1 -> V_3 -> V_55 ;
V_30 -> V_56 = V_50 -> V_57 -> V_55 ;
V_30 -> V_58 = V_50 -> V_58 ;
V_30 -> V_59 = V_50 -> V_60 -> V_55 ;
V_30 -> V_61 = V_50 -> V_62 -> V_55 ;
F_38 ( & V_50 -> V_22 ) ;
}
static void F_44 ( struct V_17 * V_3 ,
void (* F_45)( struct V_1 * V_1 ) )
{
struct V_1 * V_63 ;
F_46 ( & V_3 -> V_64 ) ;
F_47 (c, &device->client_list, link)
F_45 ( V_63 ) ;
F_48 ( & V_3 -> V_64 ) ;
}
static int F_49 ( int V_65 , void * V_66 , void * V_37 )
{
F_11 ( V_66 ) ;
return 0 ;
}
static void F_50 ( struct V_1 * V_1 )
{
struct V_67 * V_68 ;
V_68 = F_20 ( sizeof( * V_68 ) , V_20 ) ;
if ( V_68 == NULL ) {
F_51 ( L_1 ) ;
return;
}
F_43 ( & V_68 -> V_69 , V_1 ) ;
F_27 ( V_1 , & V_68 -> V_30 ,
& V_68 -> V_69 , sizeof( V_68 -> V_69 ) , NULL , 0 ) ;
F_35 ( & V_1 -> V_22 ) ;
F_52 ( & V_1 -> V_23 , F_49 , V_1 ) ;
F_38 ( & V_1 -> V_22 ) ;
}
void F_53 ( struct V_17 * V_3 )
{
F_44 ( V_3 , F_50 ) ;
}
static void F_54 ( struct V_1 * V_1 )
{
F_31 ( & V_1 -> V_25 ) ;
}
void F_55 ( struct V_17 * V_3 )
{
F_44 ( V_3 , F_54 ) ;
}
static int F_56 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_72 * V_73 = & V_71 -> V_74 ;
struct V_48 V_75 ;
unsigned long V_44 = 0 ;
V_1 -> V_76 = V_73 -> V_76 ;
V_73 -> V_76 = V_77 ;
V_73 -> V_50 = V_1 -> V_3 -> V_50 -> V_78 ;
F_57 ( & V_79 ) ;
if ( V_73 -> V_80 != 0 ) {
T_3 V_81 = V_73 -> V_82 ;
T_3 V_83 = V_1 -> V_3 -> V_84 * 4 ;
V_44 = F_41 ( F_12 ( V_73 -> V_80 ) ,
V_1 -> V_3 -> V_85 , F_40 ( V_81 , V_83 ) ) ;
}
V_73 -> V_82 = V_1 -> V_3 -> V_84 * 4 ;
F_58 ( & V_79 ) ;
if ( V_44 != 0 )
return - V_45 ;
F_46 ( & V_1 -> V_3 -> V_64 ) ;
V_1 -> V_52 = V_73 -> V_52 ;
if ( V_73 -> V_75 != 0 ) {
F_43 ( & V_75 , V_1 ) ;
V_44 = F_41 ( F_12 ( V_73 -> V_75 ) ,
& V_75 , sizeof( V_75 ) ) ;
}
if ( V_44 == 0 && F_34 ( & V_1 -> V_28 ) )
F_29 ( & V_1 -> V_28 , & V_1 -> V_3 -> V_86 ) ;
F_48 ( & V_1 -> V_3 -> V_64 ) ;
return V_44 ? - V_45 : 0 ;
}
static int F_59 ( struct V_1 * V_1 ,
struct V_9 * V_10 , T_6 V_87 )
{
unsigned long V_35 ;
int V_44 ;
V_88:
if ( F_60 ( & V_1 -> V_23 , V_87 ) == 0 )
return - V_21 ;
F_28 ( & V_1 -> V_22 , V_35 ) ;
if ( V_1 -> V_39 )
V_44 = - V_89 ;
else
V_44 = F_61 ( & V_1 -> V_23 , V_10 ,
& V_10 -> V_90 ) ;
if ( V_44 >= 0 ) {
F_1 ( V_1 ) ;
F_11 ( V_10 ) ;
}
F_30 ( & V_1 -> V_22 , V_35 ) ;
if ( V_44 == - V_91 )
goto V_88;
return V_44 < 0 ? V_44 : 0 ;
}
static int F_62 ( struct V_1 * V_1 , T_7 V_90 ,
T_8 V_11 ,
struct V_9 * * V_92 )
{
struct V_9 * V_10 ;
F_35 ( & V_1 -> V_22 ) ;
if ( V_1 -> V_39 )
V_10 = NULL ;
else
V_10 = F_63 ( & V_1 -> V_23 , V_90 ) ;
if ( V_10 && V_10 -> V_11 == V_11 )
F_64 ( & V_1 -> V_23 , V_90 ) ;
F_38 ( & V_1 -> V_22 ) ;
if ( ! ( V_10 && V_10 -> V_11 == V_11 ) )
return - V_93 ;
if ( V_92 )
* V_92 = V_10 ;
else
V_10 -> V_11 ( V_1 , V_10 ) ;
F_7 ( V_1 ) ;
return 0 ;
}
static void F_65 ( struct V_1 * V_1 ,
struct V_9 * V_10 )
{
}
static void F_66 ( struct V_49 * V_50 , int V_94 ,
void * V_95 , T_3 V_96 , void * V_37 )
{
struct V_97 * V_68 = V_37 ;
struct V_98 * V_99 = & V_68 -> V_100 ;
struct V_1 * V_1 = V_68 -> V_1 ;
unsigned long V_35 ;
if ( V_96 < V_99 -> V_96 )
V_99 -> V_96 = V_96 ;
if ( V_94 == V_101 )
memcpy ( V_99 -> V_37 , V_95 , V_99 -> V_96 ) ;
F_28 ( & V_1 -> V_22 , V_35 ) ;
F_64 ( & V_1 -> V_23 , V_68 -> V_5 . V_10 . V_90 ) ;
if ( V_1 -> V_39 )
F_67 ( & V_1 -> V_26 ) ;
F_30 ( & V_1 -> V_22 , V_35 ) ;
V_99 -> type = V_102 ;
V_99 -> V_94 = V_94 ;
if ( V_99 -> V_96 <= sizeof( * V_99 ) - F_68 ( F_69 ( * V_99 ) , V_37 ) )
F_27 ( V_1 , & V_68 -> V_30 , V_99 , sizeof( * V_99 ) ,
V_99 -> V_37 , V_99 -> V_96 ) ;
else
F_27 ( V_1 , & V_68 -> V_30 , V_99 , sizeof( * V_99 ) + V_99 -> V_96 ,
NULL , 0 ) ;
F_7 ( V_1 ) ;
}
static int F_70 ( struct V_1 * V_1 ,
struct V_103 * V_104 ,
int V_105 , int V_106 )
{
struct V_97 * V_68 ;
int V_44 ;
if ( V_104 -> V_107 != V_108 &&
( V_104 -> V_96 > 4096 || V_104 -> V_96 > 512 << V_106 ) )
return - V_109 ;
if ( V_104 -> V_107 == V_110 &&
V_104 -> V_96 < 4 )
return - V_93 ;
V_68 = F_71 ( sizeof( * V_68 ) + V_104 -> V_96 , V_20 ) ;
if ( V_68 == NULL )
return - V_21 ;
V_68 -> V_1 = V_1 ;
V_68 -> V_100 . V_96 = V_104 -> V_96 ;
V_68 -> V_100 . V_51 = V_104 -> V_51 ;
if ( V_104 -> V_37 &&
F_72 ( V_68 -> V_100 . V_37 ,
F_12 ( V_104 -> V_37 ) , V_104 -> V_96 ) ) {
V_44 = - V_45 ;
goto V_111;
}
V_68 -> V_5 . V_10 . V_11 = F_65 ;
V_44 = F_59 ( V_1 , & V_68 -> V_5 . V_10 , V_20 ) ;
if ( V_44 < 0 )
goto V_111;
F_73 ( V_1 -> V_3 -> V_50 , & V_68 -> V_5 . V_112 ,
V_104 -> V_107 , V_105 , V_104 -> V_54 ,
V_106 , V_104 -> V_47 , V_68 -> V_100 . V_37 ,
V_104 -> V_96 , F_66 , V_68 ) ;
return 0 ;
V_111:
F_6 ( V_68 ) ;
return V_44 ;
}
static int F_74 ( struct V_1 * V_1 , union V_70 * V_71 )
{
switch ( V_71 -> V_113 . V_107 ) {
case V_110 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
break;
default:
return - V_93 ;
}
return F_70 ( V_1 , & V_71 -> V_113 , V_1 -> V_3 -> V_55 ,
V_1 -> V_3 -> V_124 ) ;
}
static inline bool F_75 ( struct V_125 * V_104 )
{
return V_104 == NULL ;
}
static void F_76 ( struct V_1 * V_1 ,
struct V_9 * V_10 )
{
struct V_126 * V_5 = F_4 ( V_10 ,
struct V_126 , V_10 ) ;
if ( F_75 ( V_5 -> V_104 ) )
F_6 ( V_5 -> V_37 ) ;
else
F_77 ( V_5 -> V_50 , V_5 -> V_104 , V_127 ) ;
F_78 ( V_5 -> V_50 ) ;
F_6 ( V_5 ) ;
}
static void F_79 ( struct V_49 * V_50 , struct V_125 * V_104 ,
int V_107 , int V_128 , int V_129 ,
int V_54 , unsigned long long V_47 ,
void * V_95 , T_3 V_96 , void * V_130 )
{
struct V_131 * V_132 = V_130 ;
struct V_126 * V_5 ;
struct V_133 * V_68 ;
T_3 V_134 ;
void * V_135 = NULL ;
int V_44 ;
F_80 ( V_50 ) ;
V_5 = F_71 ( sizeof( * V_5 ) , V_136 ) ;
V_68 = F_71 ( sizeof( * V_68 ) , V_136 ) ;
if ( V_5 == NULL || V_68 == NULL ) {
F_51 ( L_1 ) ;
goto V_111;
}
V_5 -> V_50 = V_50 ;
V_5 -> V_104 = V_104 ;
V_5 -> V_37 = V_95 ;
V_5 -> V_96 = V_96 ;
if ( F_75 ( V_104 ) ) {
V_135 = F_81 ( V_95 , V_96 , V_136 ) ;
if ( V_135 == NULL )
goto V_111;
V_5 -> V_37 = V_135 ;
}
V_5 -> V_10 . V_11 = F_76 ;
V_44 = F_59 ( V_132 -> V_1 , & V_5 -> V_10 , V_136 ) ;
if ( V_44 < 0 )
goto V_111;
if ( V_132 -> V_1 -> V_76 < V_137 ) {
struct V_138 * V_139 = & V_68 -> V_139 . V_104 ;
if ( V_107 & 0x10 )
V_107 = V_140 ;
V_139 -> type = V_141 ;
V_139 -> V_107 = V_107 ;
V_139 -> V_47 = V_47 ;
V_139 -> V_96 = V_96 ;
V_139 -> V_90 = V_5 -> V_10 . V_90 ;
V_139 -> V_51 = V_132 -> V_51 ;
V_134 = sizeof( * V_139 ) ;
} else {
struct V_142 * V_139 = & V_68 -> V_139 . V_143 ;
V_139 -> type = V_144 ;
V_139 -> V_107 = V_107 ;
V_139 -> V_47 = V_47 ;
V_139 -> V_145 = V_129 ;
V_139 -> V_146 = V_128 ;
V_139 -> V_50 = V_50 -> V_78 ;
V_139 -> V_54 = V_54 ;
V_139 -> V_96 = V_96 ;
V_139 -> V_90 = V_5 -> V_10 . V_90 ;
V_139 -> V_51 = V_132 -> V_51 ;
V_134 = sizeof( * V_139 ) ;
}
F_27 ( V_132 -> V_1 , & V_68 -> V_30 ,
& V_68 -> V_139 , V_134 , V_5 -> V_37 , V_96 ) ;
return;
V_111:
F_6 ( V_5 ) ;
F_6 ( V_68 ) ;
F_6 ( V_135 ) ;
if ( ! F_75 ( V_104 ) )
F_77 ( V_50 , V_104 , V_127 ) ;
F_78 ( V_50 ) ;
}
static void F_82 ( struct V_1 * V_1 ,
struct V_9 * V_10 )
{
struct V_131 * V_5 =
F_4 ( V_10 , struct V_131 , V_10 ) ;
F_83 ( & V_5 -> V_132 ) ;
F_6 ( V_5 ) ;
}
static int F_84 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_147 * V_73 = & V_71 -> V_148 ;
struct V_131 * V_5 ;
struct V_149 V_150 ;
int V_44 ;
V_5 = F_71 ( sizeof( * V_5 ) , V_20 ) ;
if ( V_5 == NULL )
return - V_21 ;
V_150 . V_151 = V_73 -> V_47 ;
if ( V_1 -> V_76 < V_152 )
V_150 . V_153 = V_73 -> V_47 + V_73 -> V_96 ;
else
V_150 . V_153 = V_73 -> V_154 ;
V_5 -> V_132 . V_96 = V_73 -> V_96 ;
V_5 -> V_132 . V_155 = F_79 ;
V_5 -> V_132 . V_130 = V_5 ;
V_5 -> V_51 = V_73 -> V_51 ;
V_5 -> V_1 = V_1 ;
V_44 = F_85 ( & V_5 -> V_132 , & V_150 ) ;
if ( V_44 < 0 ) {
F_6 ( V_5 ) ;
return V_44 ;
}
V_73 -> V_47 = V_5 -> V_132 . V_47 ;
V_5 -> V_10 . V_11 = F_82 ;
V_44 = F_59 ( V_1 , & V_5 -> V_10 , V_20 ) ;
if ( V_44 < 0 ) {
F_82 ( V_1 , & V_5 -> V_10 ) ;
return V_44 ;
}
V_73 -> V_90 = V_5 -> V_10 . V_90 ;
return 0 ;
}
static int F_86 ( struct V_1 * V_1 , union V_70 * V_71 )
{
return F_62 ( V_1 , V_71 -> V_156 . V_90 ,
F_82 , NULL ) ;
}
static int F_87 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_157 * V_73 = & V_71 -> V_158 ;
struct V_9 * V_10 ;
struct V_126 * V_5 ;
int V_44 = 0 ;
if ( F_62 ( V_1 , V_73 -> V_90 ,
F_76 , & V_10 ) < 0 )
return - V_93 ;
V_5 = F_4 ( V_10 , struct V_126 ,
V_10 ) ;
if ( F_75 ( V_5 -> V_104 ) )
goto V_46;
if ( V_73 -> V_96 != F_88 ( V_5 -> V_104 ) ) {
V_44 = - V_93 ;
F_6 ( V_5 -> V_104 ) ;
goto V_46;
}
if ( F_72 ( V_5 -> V_37 , F_12 ( V_73 -> V_37 ) , V_73 -> V_96 ) ) {
V_44 = - V_45 ;
F_6 ( V_5 -> V_104 ) ;
goto V_46;
}
F_77 ( V_5 -> V_50 , V_5 -> V_104 , V_73 -> V_94 ) ;
V_46:
F_78 ( V_5 -> V_50 ) ;
F_6 ( V_5 ) ;
return V_44 ;
}
static int F_89 ( struct V_1 * V_1 , union V_70 * V_71 )
{
F_90 ( V_1 -> V_3 -> V_50 , true ,
V_71 -> V_159 . type == V_160 ) ;
return 0 ;
}
static void F_91 ( struct V_1 * V_1 ,
struct V_9 * V_10 )
{
struct V_161 * V_5 =
F_4 ( V_10 , struct V_161 , V_10 ) ;
F_92 ( & V_5 -> V_162 ) ;
F_6 ( V_5 ) ;
}
static int F_93 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_163 * V_73 = & V_71 -> V_164 ;
struct V_161 * V_5 ;
int V_44 ;
if ( ! V_1 -> V_3 -> V_165 )
return - V_166 ;
if ( V_73 -> V_96 > 256 )
return - V_93 ;
V_5 = F_71 ( sizeof( * V_5 ) + V_73 -> V_96 * 4 , V_20 ) ;
if ( V_5 == NULL )
return - V_21 ;
if ( F_72 ( V_5 -> V_37 , F_12 ( V_73 -> V_37 ) , V_73 -> V_96 * 4 ) ) {
V_44 = - V_45 ;
goto V_111;
}
V_5 -> V_162 . V_96 = V_73 -> V_96 ;
V_5 -> V_162 . V_167 = V_73 -> V_167 ;
V_5 -> V_162 . V_168 = V_73 -> V_168 ;
V_5 -> V_162 . V_37 = V_5 -> V_37 ;
V_44 = F_94 ( & V_5 -> V_162 ) ;
if ( V_44 < 0 )
goto V_111;
V_5 -> V_10 . V_11 = F_91 ;
V_44 = F_59 ( V_1 , & V_5 -> V_10 , V_20 ) ;
if ( V_44 < 0 ) {
F_92 ( & V_5 -> V_162 ) ;
goto V_111;
}
V_73 -> V_90 = V_5 -> V_10 . V_90 ;
return 0 ;
V_111:
F_6 ( V_5 ) ;
return V_44 ;
}
static int F_95 ( struct V_1 * V_1 , union V_70 * V_71 )
{
return F_62 ( V_1 , V_71 -> V_169 . V_90 ,
F_91 , NULL ) ;
}
static void F_96 ( struct V_170 * V_171 , T_7 V_172 ,
T_3 V_173 , void * V_174 , void * V_37 )
{
struct V_1 * V_1 = V_37 ;
struct V_175 * V_68 ;
V_68 = F_71 ( sizeof( * V_68 ) + V_173 , V_136 ) ;
if ( V_68 == NULL ) {
F_51 ( L_1 ) ;
return;
}
V_68 -> V_176 . type = V_177 ;
V_68 -> V_176 . V_51 = V_1 -> V_178 ;
V_68 -> V_176 . V_172 = V_172 ;
V_68 -> V_176 . V_173 = V_173 ;
memcpy ( V_68 -> V_176 . V_174 , V_174 , V_173 ) ;
F_27 ( V_1 , & V_68 -> V_30 , & V_68 -> V_176 ,
sizeof( V_68 -> V_176 ) + V_173 , NULL , 0 ) ;
}
static void F_97 ( struct V_170 * V_171 ,
T_9 V_179 , void * V_37 )
{
struct V_1 * V_1 = V_37 ;
struct V_180 * V_68 ;
V_68 = F_71 ( sizeof( * V_68 ) , V_136 ) ;
if ( V_68 == NULL ) {
F_51 ( L_1 ) ;
return;
}
V_68 -> V_176 . type = V_181 ;
V_68 -> V_176 . V_51 = V_1 -> V_178 ;
V_68 -> V_176 . V_179 = F_98 ( & V_1 -> V_40 ,
V_179 ) ;
F_27 ( V_1 , & V_68 -> V_30 , & V_68 -> V_176 ,
sizeof( V_68 -> V_176 ) , NULL , 0 ) ;
}
static int F_99 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_182 * V_73 = & V_71 -> V_183 ;
struct V_170 * V_171 ;
T_10 V_184 ;
F_100 ( V_185 != V_186 ||
V_187 != V_188 ||
V_189 !=
V_190 ) ;
switch ( V_73 -> type ) {
case V_186 :
if ( V_73 -> V_106 > V_191 || V_73 -> V_192 > 63 )
return - V_93 ;
V_184 = F_96 ;
break;
case V_188 :
if ( V_73 -> V_193 < 4 || ( V_73 -> V_193 & 3 ) ||
V_73 -> V_192 > 63 )
return - V_93 ;
V_184 = F_96 ;
break;
case V_190 :
V_184 = ( T_10 ) F_97 ;
break;
default:
return - V_93 ;
}
V_171 = F_101 ( V_1 -> V_3 -> V_50 , V_73 -> type ,
V_73 -> V_192 , V_73 -> V_106 , V_73 -> V_193 , V_184 , V_1 ) ;
if ( F_102 ( V_171 ) )
return F_103 ( V_171 ) ;
F_35 ( & V_1 -> V_22 ) ;
if ( V_1 -> V_194 != NULL ) {
F_38 ( & V_1 -> V_22 ) ;
F_104 ( V_171 ) ;
return - V_195 ;
}
V_1 -> V_178 = V_73 -> V_51 ;
V_1 -> V_194 = V_171 ;
F_38 ( & V_1 -> V_22 ) ;
V_73 -> V_90 = 0 ;
return 0 ;
}
static int F_105 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_196 * V_73 = & V_71 -> V_197 ;
struct V_170 * V_198 = V_1 -> V_194 ;
if ( V_198 == NULL || V_73 -> V_90 != 0 )
return - V_93 ;
return F_106 ( V_198 , & V_73 -> V_199 ) ;
}
static int F_107 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_200 * V_73 = & V_71 -> V_201 ;
struct V_202 T_1 * V_66 , * V_153 , * V_203 ;
struct V_170 * V_198 = V_1 -> V_194 ;
unsigned long V_95 , V_204 , V_205 = 0 ;
T_7 V_206 ;
int V_41 ;
struct {
struct V_207 V_208 ;
T_11 V_174 [ 256 ] ;
} V_209 ;
if ( V_198 == NULL || V_73 -> V_90 != 0 )
return - V_93 ;
V_95 = ( unsigned long ) V_73 -> V_37 - V_1 -> V_210 ;
V_204 = V_1 -> V_40 . V_211 << V_212 ;
if ( V_73 -> V_37 == 0 || V_1 -> V_40 . V_213 == NULL ||
V_95 >= V_204 ) {
V_95 = 0 ;
V_204 = 0 ;
}
if ( V_198 -> type == V_190 && V_95 & 3 )
return - V_93 ;
V_66 = (struct V_202 T_1 * ) F_12 ( V_73 -> V_214 ) ;
if ( ! F_108 ( V_215 , V_66 , V_73 -> V_38 ) )
return - V_45 ;
V_153 = ( void T_1 * ) V_66 + V_73 -> V_38 ;
V_41 = 0 ;
while ( V_66 < V_153 ) {
if ( F_109 ( V_206 , & V_66 -> V_206 ) )
return - V_45 ;
V_209 . V_208 . V_216 = F_110 ( V_206 ) ;
V_209 . V_208 . V_176 = F_111 ( V_206 ) ;
V_209 . V_208 . V_217 = F_112 ( V_206 ) ;
V_209 . V_208 . V_218 = F_113 ( V_206 ) ;
V_209 . V_208 . V_219 = F_114 ( V_206 ) ;
V_209 . V_208 . V_173 = F_115 ( V_206 ) ;
switch ( V_198 -> type ) {
case V_186 :
if ( V_209 . V_208 . V_173 & 3 )
return - V_93 ;
V_205 = V_209 . V_208 . V_173 ;
break;
case V_188 :
if ( V_209 . V_208 . V_173 == 0 ||
V_209 . V_208 . V_173 % V_198 -> V_193 != 0 )
return - V_93 ;
break;
case V_190 :
if ( V_209 . V_208 . V_216 == 0 ||
V_209 . V_208 . V_216 & 3 )
return - V_93 ;
break;
}
V_203 = (struct V_202 T_1 * )
& V_66 -> V_174 [ V_205 / 4 ] ;
if ( V_203 > V_153 )
return - V_93 ;
if ( F_116
( V_209 . V_208 . V_174 , V_66 -> V_174 , V_205 ) )
return - V_45 ;
if ( V_209 . V_208 . V_217 && V_198 -> type == V_186 &&
V_209 . V_208 . V_173 + V_209 . V_208 . V_216 > 0 )
return - V_93 ;
if ( V_95 + V_209 . V_208 . V_216 > V_204 )
return - V_93 ;
if ( F_117 ( V_198 , & V_209 . V_208 ,
& V_1 -> V_40 , V_95 ) )
break;
V_66 = V_203 ;
V_95 += V_209 . V_208 . V_216 ;
V_41 ++ ;
}
F_118 ( V_198 ) ;
V_73 -> V_38 -= F_15 ( V_66 ) - V_73 -> V_214 ;
V_73 -> V_214 = F_15 ( V_66 ) ;
V_73 -> V_37 = V_1 -> V_210 + V_95 ;
return V_41 ;
}
static int F_119 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_220 * V_73 = & V_71 -> V_221 ;
F_100 (
V_222 != V_223 ||
V_224 != V_225 ||
V_226 != V_227 ||
V_228 != V_229 ||
V_230 != V_231 ) ;
if ( V_1 -> V_194 == NULL || V_73 -> V_90 != 0 )
return - V_93 ;
if ( V_1 -> V_194 -> type == V_188 &&
( V_73 -> V_232 == 0 || V_73 -> V_232 > 15 || V_73 -> V_233 > 15 ) )
return - V_93 ;
return F_120 ( V_1 -> V_194 ,
V_73 -> V_172 , V_73 -> V_233 , V_73 -> V_232 ) ;
}
static int F_121 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_234 * V_73 = & V_71 -> V_235 ;
if ( V_1 -> V_194 == NULL || V_73 -> V_90 != 0 )
return - V_93 ;
return F_122 ( V_1 -> V_194 ) ;
}
static int F_123 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_236 * V_73 = & V_71 -> V_237 ;
struct V_49 * V_50 = V_1 -> V_3 -> V_50 ;
struct V_238 V_239 = { 0 , 0 } ;
T_7 V_240 ;
int V_44 = 0 ;
F_124 () ;
V_240 = V_50 -> V_241 -> V_242 ( V_50 , V_243 ) ;
switch ( V_73 -> V_244 ) {
case V_245 : F_125 ( & V_239 ) ; break;
case V_246 : F_126 ( & V_239 ) ; break;
case V_247 : F_127 ( & V_239 ) ; break;
default:
V_44 = - V_93 ;
}
F_128 () ;
V_73 -> V_248 = V_239 . V_248 ;
V_73 -> V_249 = V_239 . V_249 ;
V_73 -> V_250 = V_240 ;
return V_44 ;
}
static int F_129 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_251 * V_73 = & V_71 -> V_252 ;
struct V_236 V_253 ;
V_253 . V_244 = V_245 ;
F_123 ( V_1 , (union V_70 * ) & V_253 ) ;
V_73 -> V_254 = V_253 . V_248 * V_255 + V_253 . V_249 / V_256 ;
V_73 -> V_250 = V_253 . V_250 ;
return 0 ;
}
static void F_130 ( struct V_257 * V_8 )
{
struct V_258 * V_68 ;
struct V_4 * V_5 =
F_4 ( V_8 , struct V_4 , V_8 . V_8 ) ;
struct V_1 * V_1 = V_5 -> V_1 ;
int V_54 , V_192 , V_259 , V_260 ;
bool V_217 , free , V_261 ;
F_35 ( & V_1 -> V_22 ) ;
V_54 = V_1 -> V_3 -> V_54 ;
V_260 = V_5 -> V_260 ;
if ( V_260 == V_262 &&
F_131 ( F_132 () ,
V_1 -> V_3 -> V_50 -> V_263 + V_264 ) ) {
F_9 ( V_5 , F_133 ( V_264 , 3 ) ) ;
V_217 = true ;
} else {
V_217 = V_260 == V_265 &&
V_5 -> V_54 == V_54 ;
}
free = V_260 == V_266 ||
V_260 == V_267 ||
V_260 == V_268 ;
V_5 -> V_54 = V_54 ;
F_38 ( & V_1 -> V_22 ) ;
if ( V_217 )
goto V_46;
V_259 = V_5 -> V_259 ;
F_134 ( V_1 -> V_3 -> V_50 , V_54 ,
V_5 -> V_199 , & V_192 , & V_259 ,
V_260 == V_262 ||
V_260 == V_265 ||
V_260 == V_267 ) ;
if ( V_192 == - V_91 &&
( V_260 == V_262 || V_260 == V_265 ) )
goto V_46;
V_261 = V_192 >= 0 || V_259 > 0 ;
F_35 ( & V_1 -> V_22 ) ;
if ( V_5 -> V_260 == V_262 )
V_5 -> V_260 = V_265 ;
if ( V_5 -> V_260 == V_265 && ! V_261 &&
! V_1 -> V_39 &&
F_63 ( & V_1 -> V_23 , V_5 -> V_10 . V_90 ) ) {
F_64 ( & V_1 -> V_23 , V_5 -> V_10 . V_90 ) ;
F_7 ( V_1 ) ;
free = true ;
}
F_38 ( & V_1 -> V_22 ) ;
if ( V_260 == V_262 && V_192 >= 0 )
V_5 -> V_199 = 1ULL << V_192 ;
if ( V_260 == V_265 && V_261 )
goto V_46;
if ( V_260 == V_262 || V_260 == V_267 ) {
V_68 = V_5 -> V_269 ;
V_5 -> V_269 = NULL ;
} else {
V_68 = V_5 -> V_270 ;
V_5 -> V_270 = NULL ;
}
V_68 -> V_4 . V_90 = V_5 -> V_10 . V_90 ;
V_68 -> V_4 . V_192 = V_192 ;
V_68 -> V_4 . V_259 = V_259 ;
F_27 ( V_1 , & V_68 -> V_30 ,
& V_68 -> V_4 , sizeof( V_68 -> V_4 ) , NULL , 0 ) ;
if ( free ) {
F_135 ( & V_5 -> V_8 ) ;
F_6 ( V_5 -> V_269 ) ;
F_6 ( V_5 -> V_270 ) ;
F_6 ( V_5 ) ;
}
V_46:
F_7 ( V_1 ) ;
}
static void V_12 ( struct V_1 * V_1 ,
struct V_9 * V_10 )
{
struct V_4 * V_5 =
F_4 ( V_10 , struct V_4 , V_10 ) ;
F_35 ( & V_1 -> V_22 ) ;
V_5 -> V_260 = V_266 ;
F_9 ( V_5 , 0 ) ;
F_38 ( & V_1 -> V_22 ) ;
}
static int F_136 ( struct V_1 * V_1 ,
struct V_271 * V_104 , int V_260 )
{
struct V_258 * V_272 , * V_273 ;
struct V_4 * V_5 ;
int V_44 ;
if ( ( V_104 -> V_199 == 0 && V_104 -> V_259 == 0 ) ||
V_104 -> V_259 > V_274 ||
V_104 -> V_259 < 0 )
return - V_93 ;
V_5 = F_71 ( sizeof( * V_5 ) , V_20 ) ;
V_272 = F_71 ( sizeof( * V_272 ) , V_20 ) ;
V_273 = F_71 ( sizeof( * V_273 ) , V_20 ) ;
if ( V_5 == NULL || V_272 == NULL || V_273 == NULL ) {
V_44 = - V_21 ;
goto V_275;
}
F_137 ( & V_5 -> V_8 , F_130 ) ;
V_5 -> V_1 = V_1 ;
V_5 -> V_260 = V_260 ;
V_5 -> V_54 = - 1 ;
V_5 -> V_199 = V_104 -> V_199 ;
V_5 -> V_259 = V_104 -> V_259 ;
V_5 -> V_269 = V_272 ;
V_5 -> V_270 = V_273 ;
V_272 -> V_4 . V_51 = V_104 -> V_51 ;
V_272 -> V_4 . type = V_276 ;
V_273 -> V_4 . V_51 = V_104 -> V_51 ;
V_273 -> V_4 . type = V_277 ;
if ( V_260 == V_262 ) {
V_5 -> V_10 . V_11 = V_12 ;
V_44 = F_59 ( V_1 , & V_5 -> V_10 , V_20 ) ;
if ( V_44 < 0 )
goto V_275;
} else {
V_5 -> V_10 . V_11 = NULL ;
V_5 -> V_10 . V_90 = - 1 ;
F_9 ( V_5 , 0 ) ;
}
V_104 -> V_90 = V_5 -> V_10 . V_90 ;
return 0 ;
V_275:
F_6 ( V_5 ) ;
F_6 ( V_272 ) ;
F_6 ( V_273 ) ;
return V_44 ;
}
static int F_138 ( struct V_1 * V_1 ,
union V_70 * V_71 )
{
return F_136 ( V_1 ,
& V_71 -> V_278 , V_262 ) ;
}
static int F_139 ( struct V_1 * V_1 ,
union V_70 * V_71 )
{
return F_62 ( V_1 ,
V_71 -> V_156 . V_90 , V_12 , NULL ) ;
}
static int F_140 ( struct V_1 * V_1 ,
union V_70 * V_71 )
{
return F_136 ( V_1 ,
& V_71 -> V_278 , V_267 ) ;
}
static int F_141 ( struct V_1 * V_1 ,
union V_70 * V_71 )
{
return F_136 ( V_1 ,
& V_71 -> V_278 , V_268 ) ;
}
static int F_142 ( struct V_1 * V_1 , union V_70 * V_71 )
{
return V_1 -> V_3 -> V_124 ;
}
static int F_143 ( struct V_1 * V_1 ,
union V_70 * V_71 )
{
struct V_103 * V_73 = & V_71 -> V_113 ;
switch ( V_73 -> V_107 ) {
case V_110 :
case V_114 :
break;
default:
return - V_93 ;
}
if ( V_73 -> V_47 < V_279 + V_280 )
return - V_281 ;
return F_70 ( V_1 , V_73 , V_282 | 0x3f , V_283 ) ;
}
static int F_144 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_284 * V_73 = & V_71 -> V_285 ;
struct V_103 V_104 ;
int V_286 ;
if ( V_73 -> V_106 > V_1 -> V_3 -> V_50 -> V_287 ||
V_73 -> V_96 > 1024 << V_73 -> V_106 )
return - V_109 ;
if ( V_73 -> V_218 > 3 || V_73 -> V_192 > 63 || V_73 -> V_219 > 15 )
return - V_93 ;
V_286 = F_145 ( V_73 -> V_218 , V_73 -> V_192 , V_73 -> V_219 ) ;
V_104 . V_107 = V_108 ;
V_104 . V_96 = V_73 -> V_96 ;
V_104 . V_51 = V_73 -> V_51 ;
V_104 . V_37 = V_73 -> V_37 ;
V_104 . V_54 = V_73 -> V_54 ;
return F_70 ( V_1 , & V_104 , V_286 , V_73 -> V_106 ) ;
}
static void F_146 ( struct V_288 * V_208 ,
struct V_49 * V_50 , int V_289 )
{
struct V_290 * V_68 =
F_4 ( V_208 , struct V_290 , V_66 ) ;
switch ( V_289 ) {
case V_291 : V_68 -> V_292 . V_94 = V_101 ; break;
case V_293 : V_68 -> V_292 . V_94 = V_101 ; break;
case V_294 :
case V_295 :
case V_296 : V_68 -> V_292 . V_94 = V_297 ; break;
case V_298 : V_68 -> V_292 . V_94 = V_299 ; break;
case V_300 : V_68 -> V_292 . V_94 = V_301 ; break;
default: V_68 -> V_292 . V_94 = V_289 ; break;
}
V_68 -> V_292 . V_37 [ 0 ] = V_208 -> V_302 ;
F_27 ( V_68 -> V_1 , & V_68 -> V_30 , & V_68 -> V_292 ,
sizeof( V_68 -> V_292 ) + V_68 -> V_292 . V_96 , NULL , 0 ) ;
F_7 ( V_68 -> V_1 ) ;
}
static int F_147 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_303 * V_73 = & V_71 -> V_304 ;
struct V_49 * V_50 = V_1 -> V_3 -> V_50 ;
struct V_290 * V_68 ;
if ( ! V_1 -> V_3 -> V_165 )
return - V_166 ;
V_68 = F_20 ( sizeof( * V_68 ) + 4 , V_20 ) ;
if ( V_68 == NULL )
return - V_21 ;
F_1 ( V_1 ) ;
V_68 -> V_1 = V_1 ;
V_68 -> V_66 . V_106 = V_283 ;
V_68 -> V_66 . V_54 = V_73 -> V_54 ;
V_68 -> V_66 . V_174 [ 0 ] = V_305 << 4 ;
V_68 -> V_66 . V_174 [ 1 ] = V_73 -> V_37 [ 0 ] ;
V_68 -> V_66 . V_174 [ 2 ] = V_73 -> V_37 [ 1 ] ;
V_68 -> V_66 . V_173 = 12 ;
V_68 -> V_66 . F_45 = F_146 ;
V_68 -> V_292 . V_51 = V_73 -> V_51 ;
V_68 -> V_292 . type = V_306 ;
if ( F_148 ( V_73 -> V_37 ) )
V_68 -> V_292 . V_96 = 4 ;
V_50 -> V_241 -> V_113 ( V_50 , & V_68 -> V_66 ) ;
return 0 ;
}
static int F_149 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_307 * V_73 = & V_71 -> V_308 ;
struct V_49 * V_50 = V_1 -> V_3 -> V_50 ;
if ( ! V_1 -> V_3 -> V_165 )
return - V_166 ;
F_35 ( & V_50 -> V_22 ) ;
F_150 ( & V_1 -> V_27 , & V_50 -> V_309 ) ;
V_1 -> V_310 = V_73 -> V_51 ;
F_38 ( & V_50 -> V_22 ) ;
return 0 ;
}
void F_151 ( struct V_49 * V_50 , struct V_288 * V_66 )
{
struct V_1 * V_1 ;
struct V_311 * V_68 ;
unsigned long V_35 ;
F_28 ( & V_50 -> V_22 , V_35 ) ;
F_47 (client, &card->phy_receiver_list, phy_receiver_link) {
V_68 = F_71 ( sizeof( * V_68 ) + 8 , V_136 ) ;
if ( V_68 == NULL ) {
F_51 ( L_1 ) ;
break;
}
V_68 -> V_292 . V_51 = V_1 -> V_310 ;
V_68 -> V_292 . type = V_312 ;
V_68 -> V_292 . V_94 = V_101 ;
V_68 -> V_292 . V_96 = 8 ;
V_68 -> V_292 . V_37 [ 0 ] = V_66 -> V_174 [ 1 ] ;
V_68 -> V_292 . V_37 [ 1 ] = V_66 -> V_174 [ 2 ] ;
F_27 ( V_1 , & V_68 -> V_30 ,
& V_68 -> V_292 , sizeof( V_68 -> V_292 ) + 8 , NULL , 0 ) ;
}
F_30 ( & V_50 -> V_22 , V_35 ) ;
}
static int F_152 ( struct V_1 * V_1 ,
unsigned int V_313 , void T_1 * V_71 )
{
union V_70 V_40 ;
int V_44 ;
if ( F_19 ( V_1 -> V_3 ) )
return - V_19 ;
if ( F_153 ( V_313 ) != '#' ||
F_154 ( V_313 ) >= F_39 ( V_314 ) ||
F_155 ( V_313 ) > sizeof( V_40 ) )
return - V_315 ;
if ( F_156 ( V_313 ) == V_316 )
memset ( & V_40 , 0 , F_155 ( V_313 ) ) ;
if ( F_156 ( V_313 ) & V_317 )
if ( F_72 ( & V_40 , V_71 , F_155 ( V_313 ) ) )
return - V_45 ;
V_44 = V_314 [ F_154 ( V_313 ) ] ( V_1 , & V_40 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( F_156 ( V_313 ) & V_316 )
if ( F_41 ( V_71 , & V_40 , F_155 ( V_313 ) ) )
return - V_45 ;
return V_44 ;
}
static long F_157 ( struct V_16 * V_16 ,
unsigned int V_313 , unsigned long V_71 )
{
return F_152 ( V_16 -> V_29 , V_313 , ( void T_1 * ) V_71 ) ;
}
static long F_158 ( struct V_16 * V_16 ,
unsigned int V_313 , unsigned long V_71 )
{
return F_152 ( V_16 -> V_29 , V_313 , F_14 ( V_71 ) ) ;
}
static int F_159 ( struct V_16 * V_16 , struct V_318 * V_319 )
{
struct V_1 * V_1 = V_16 -> V_29 ;
enum V_320 V_321 ;
unsigned long V_38 ;
int V_211 , V_44 ;
if ( F_19 ( V_1 -> V_3 ) )
return - V_19 ;
if ( V_1 -> V_40 . V_213 != NULL )
return - V_195 ;
if ( ! ( V_319 -> V_322 & V_323 ) )
return - V_93 ;
if ( V_319 -> V_210 & ~ V_324 )
return - V_93 ;
V_1 -> V_210 = V_319 -> V_210 ;
V_38 = V_319 -> V_325 - V_319 -> V_210 ;
V_211 = V_38 >> V_212 ;
if ( V_38 & ~ V_324 )
return - V_93 ;
if ( V_319 -> V_322 & V_326 )
V_321 = V_327 ;
else
V_321 = V_328 ;
V_44 = F_160 ( & V_1 -> V_40 , V_1 -> V_3 -> V_50 ,
V_211 , V_321 ) ;
if ( V_44 < 0 )
return V_44 ;
V_44 = F_161 ( & V_1 -> V_40 , V_319 ) ;
if ( V_44 < 0 )
F_162 ( & V_1 -> V_40 , V_1 -> V_3 -> V_50 ) ;
return V_44 ;
}
static int F_163 ( int V_65 , void * V_66 , void * V_37 )
{
struct V_9 * V_10 = V_66 ;
return V_10 -> V_11 == F_65 ;
}
static int F_164 ( struct V_1 * V_1 )
{
int V_44 ;
F_35 ( & V_1 -> V_22 ) ;
V_44 = F_52 ( & V_1 -> V_23 ,
F_163 , NULL ) ;
F_38 ( & V_1 -> V_22 ) ;
return V_44 ;
}
static int F_165 ( int V_65 , void * V_66 , void * V_37 )
{
struct V_9 * V_10 = V_66 ;
struct V_1 * V_1 = V_37 ;
V_10 -> V_11 ( V_1 , V_10 ) ;
F_7 ( V_1 ) ;
return 0 ;
}
static int F_166 ( struct V_15 * V_15 , struct V_16 * V_16 )
{
struct V_1 * V_1 = V_16 -> V_29 ;
struct V_30 * V_30 , * V_329 ;
F_35 ( & V_1 -> V_3 -> V_50 -> V_22 ) ;
F_37 ( & V_1 -> V_27 ) ;
F_38 ( & V_1 -> V_3 -> V_50 -> V_22 ) ;
F_46 ( & V_1 -> V_3 -> V_64 ) ;
F_37 ( & V_1 -> V_28 ) ;
F_48 ( & V_1 -> V_3 -> V_64 ) ;
if ( V_1 -> V_194 )
F_104 ( V_1 -> V_194 ) ;
if ( V_1 -> V_40 . V_213 )
F_162 ( & V_1 -> V_40 , V_1 -> V_3 -> V_50 ) ;
F_35 ( & V_1 -> V_22 ) ;
V_1 -> V_39 = true ;
F_38 ( & V_1 -> V_22 ) ;
F_167 ( V_1 -> V_26 , ! F_164 ( V_1 ) ) ;
F_52 ( & V_1 -> V_23 , F_165 , V_1 ) ;
F_168 ( & V_1 -> V_23 ) ;
F_169 ( & V_1 -> V_23 ) ;
F_170 (event, next_event, &client->event_list, link)
F_6 ( V_30 ) ;
F_7 ( V_1 ) ;
return 0 ;
}
static unsigned int F_171 ( struct V_16 * V_16 , T_12 * V_330 )
{
struct V_1 * V_1 = V_16 -> V_29 ;
unsigned int V_331 = 0 ;
F_172 ( V_16 , & V_1 -> V_25 , V_330 ) ;
if ( F_19 ( V_1 -> V_3 ) )
V_331 |= V_332 | V_333 ;
if ( ! F_34 ( & V_1 -> V_24 ) )
V_331 |= V_334 | V_335 ;
return V_331 ;
}
