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
if ( V_68 == NULL )
return;
F_43 ( & V_68 -> V_69 , V_1 ) ;
F_27 ( V_1 , & V_68 -> V_30 ,
& V_68 -> V_69 , sizeof( V_68 -> V_69 ) , NULL , 0 ) ;
F_35 ( & V_1 -> V_22 ) ;
F_51 ( & V_1 -> V_23 , F_49 , V_1 ) ;
F_38 ( & V_1 -> V_22 ) ;
}
void F_52 ( struct V_17 * V_3 )
{
F_44 ( V_3 , F_50 ) ;
}
static void F_53 ( struct V_1 * V_1 )
{
F_31 ( & V_1 -> V_25 ) ;
}
void F_54 ( struct V_17 * V_3 )
{
F_44 ( V_3 , F_53 ) ;
}
static int F_55 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_72 * V_73 = & V_71 -> V_74 ;
struct V_48 V_75 ;
unsigned long V_44 = 0 ;
V_1 -> V_76 = V_73 -> V_76 ;
V_73 -> V_76 = V_77 ;
V_73 -> V_50 = V_1 -> V_3 -> V_50 -> V_78 ;
F_56 ( & V_79 ) ;
if ( V_73 -> V_80 != 0 ) {
T_3 V_81 = V_73 -> V_82 ;
T_3 V_83 = V_1 -> V_3 -> V_84 * 4 ;
V_44 = F_41 ( F_12 ( V_73 -> V_80 ) ,
V_1 -> V_3 -> V_85 , F_40 ( V_81 , V_83 ) ) ;
}
V_73 -> V_82 = V_1 -> V_3 -> V_84 * 4 ;
F_57 ( & V_79 ) ;
if ( V_44 != 0 )
return - V_45 ;
F_46 ( & V_1 -> V_3 -> V_64 ) ;
V_1 -> V_52 = V_73 -> V_52 ;
if ( V_73 -> V_75 != 0 ) {
F_43 ( & V_75 , V_1 ) ;
V_44 = F_41 ( F_12 ( V_73 -> V_75 ) , & V_75 , 36 ) ;
}
if ( V_44 == 0 && F_34 ( & V_1 -> V_28 ) )
F_29 ( & V_1 -> V_28 , & V_1 -> V_3 -> V_86 ) ;
F_48 ( & V_1 -> V_3 -> V_64 ) ;
return V_44 ? - V_45 : 0 ;
}
static int F_58 ( struct V_1 * V_1 ,
struct V_9 * V_10 , T_6 V_87 )
{
bool V_88 = F_59 ( V_87 ) ;
unsigned long V_35 ;
int V_44 ;
if ( V_88 )
F_60 ( V_87 ) ;
F_28 ( & V_1 -> V_22 , V_35 ) ;
if ( V_1 -> V_39 )
V_44 = - V_89 ;
else
V_44 = F_61 ( & V_1 -> V_23 , V_10 , 0 , 0 ,
V_90 ) ;
if ( V_44 >= 0 ) {
V_10 -> V_91 = V_44 ;
F_1 ( V_1 ) ;
F_11 ( V_10 ) ;
}
F_30 ( & V_1 -> V_22 , V_35 ) ;
if ( V_88 )
F_62 () ;
return V_44 < 0 ? V_44 : 0 ;
}
static int F_63 ( struct V_1 * V_1 , T_7 V_91 ,
T_8 V_11 ,
struct V_9 * * V_92 )
{
struct V_9 * V_10 ;
F_35 ( & V_1 -> V_22 ) ;
if ( V_1 -> V_39 )
V_10 = NULL ;
else
V_10 = F_64 ( & V_1 -> V_23 , V_91 ) ;
if ( V_10 && V_10 -> V_11 == V_11 )
F_65 ( & V_1 -> V_23 , V_91 ) ;
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
static void F_66 ( struct V_1 * V_1 ,
struct V_9 * V_10 )
{
}
static void F_67 ( struct V_49 * V_50 , int V_94 ,
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
F_65 ( & V_1 -> V_23 , V_68 -> V_5 . V_10 . V_91 ) ;
if ( V_1 -> V_39 )
F_68 ( & V_1 -> V_26 ) ;
F_30 ( & V_1 -> V_22 , V_35 ) ;
V_99 -> type = V_102 ;
V_99 -> V_94 = V_94 ;
if ( V_99 -> V_96 <= sizeof( * V_99 ) - F_69 ( F_70 ( * V_99 ) , V_37 ) )
F_27 ( V_1 , & V_68 -> V_30 , V_99 , sizeof( * V_99 ) ,
V_99 -> V_37 , V_99 -> V_96 ) ;
else
F_27 ( V_1 , & V_68 -> V_30 , V_99 , sizeof( * V_99 ) + V_99 -> V_96 ,
NULL , 0 ) ;
F_7 ( V_1 ) ;
}
static int F_71 ( struct V_1 * V_1 ,
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
V_68 = F_72 ( sizeof( * V_68 ) + V_104 -> V_96 , V_20 ) ;
if ( V_68 == NULL )
return - V_21 ;
V_68 -> V_1 = V_1 ;
V_68 -> V_100 . V_96 = V_104 -> V_96 ;
V_68 -> V_100 . V_51 = V_104 -> V_51 ;
if ( V_104 -> V_37 &&
F_73 ( V_68 -> V_100 . V_37 ,
F_12 ( V_104 -> V_37 ) , V_104 -> V_96 ) ) {
V_44 = - V_45 ;
goto V_111;
}
V_68 -> V_5 . V_10 . V_11 = F_66 ;
V_44 = F_58 ( V_1 , & V_68 -> V_5 . V_10 , V_20 ) ;
if ( V_44 < 0 )
goto V_111;
F_74 ( V_1 -> V_3 -> V_50 , & V_68 -> V_5 . V_112 ,
V_104 -> V_107 , V_105 , V_104 -> V_54 ,
V_106 , V_104 -> V_47 , V_68 -> V_100 . V_37 ,
V_104 -> V_96 , F_67 , V_68 ) ;
return 0 ;
V_111:
F_6 ( V_68 ) ;
return V_44 ;
}
static int F_75 ( struct V_1 * V_1 , union V_70 * V_71 )
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
return F_71 ( V_1 , & V_71 -> V_113 , V_1 -> V_3 -> V_55 ,
V_1 -> V_3 -> V_124 ) ;
}
static inline bool F_76 ( struct V_125 * V_104 )
{
return V_104 == NULL ;
}
static void F_77 ( struct V_1 * V_1 ,
struct V_9 * V_10 )
{
struct V_126 * V_5 = F_4 ( V_10 ,
struct V_126 , V_10 ) ;
if ( F_76 ( V_5 -> V_104 ) )
F_6 ( V_5 -> V_37 ) ;
else
F_78 ( V_5 -> V_50 , V_5 -> V_104 , V_127 ) ;
F_79 ( V_5 -> V_50 ) ;
F_6 ( V_5 ) ;
}
static void F_80 ( struct V_49 * V_50 , struct V_125 * V_104 ,
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
F_81 ( V_50 ) ;
V_5 = F_72 ( sizeof( * V_5 ) , V_136 ) ;
V_68 = F_72 ( sizeof( * V_68 ) , V_136 ) ;
if ( V_5 == NULL || V_68 == NULL )
goto V_111;
V_5 -> V_50 = V_50 ;
V_5 -> V_104 = V_104 ;
V_5 -> V_37 = V_95 ;
V_5 -> V_96 = V_96 ;
if ( F_76 ( V_104 ) ) {
V_135 = F_82 ( V_95 , V_96 , V_136 ) ;
if ( V_135 == NULL )
goto V_111;
V_5 -> V_37 = V_135 ;
}
V_5 -> V_10 . V_11 = F_77 ;
V_44 = F_58 ( V_132 -> V_1 , & V_5 -> V_10 , V_136 ) ;
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
V_139 -> V_91 = V_5 -> V_10 . V_91 ;
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
V_139 -> V_91 = V_5 -> V_10 . V_91 ;
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
if ( ! F_76 ( V_104 ) )
F_78 ( V_50 , V_104 , V_127 ) ;
F_79 ( V_50 ) ;
}
static void F_83 ( struct V_1 * V_1 ,
struct V_9 * V_10 )
{
struct V_131 * V_5 =
F_4 ( V_10 , struct V_131 , V_10 ) ;
F_84 ( & V_5 -> V_132 ) ;
F_6 ( V_5 ) ;
}
static int F_85 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_147 * V_73 = & V_71 -> V_148 ;
struct V_131 * V_5 ;
struct V_149 V_150 ;
int V_44 ;
V_5 = F_72 ( sizeof( * V_5 ) , V_20 ) ;
if ( V_5 == NULL )
return - V_21 ;
V_150 . V_151 = V_73 -> V_47 ;
if ( V_1 -> V_76 < V_152 )
V_150 . V_153 = V_73 -> V_47 + V_73 -> V_96 ;
else
V_150 . V_153 = V_73 -> V_154 ;
V_5 -> V_132 . V_96 = V_73 -> V_96 ;
V_5 -> V_132 . V_155 = F_80 ;
V_5 -> V_132 . V_130 = V_5 ;
V_5 -> V_51 = V_73 -> V_51 ;
V_5 -> V_1 = V_1 ;
V_44 = F_86 ( & V_5 -> V_132 , & V_150 ) ;
if ( V_44 < 0 ) {
F_6 ( V_5 ) ;
return V_44 ;
}
V_73 -> V_47 = V_5 -> V_132 . V_47 ;
V_5 -> V_10 . V_11 = F_83 ;
V_44 = F_58 ( V_1 , & V_5 -> V_10 , V_20 ) ;
if ( V_44 < 0 ) {
F_83 ( V_1 , & V_5 -> V_10 ) ;
return V_44 ;
}
V_73 -> V_91 = V_5 -> V_10 . V_91 ;
return 0 ;
}
static int F_87 ( struct V_1 * V_1 , union V_70 * V_71 )
{
return F_63 ( V_1 , V_71 -> V_156 . V_91 ,
F_83 , NULL ) ;
}
static int F_88 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_157 * V_73 = & V_71 -> V_158 ;
struct V_9 * V_10 ;
struct V_126 * V_5 ;
int V_44 = 0 ;
if ( F_63 ( V_1 , V_73 -> V_91 ,
F_77 , & V_10 ) < 0 )
return - V_93 ;
V_5 = F_4 ( V_10 , struct V_126 ,
V_10 ) ;
if ( F_76 ( V_5 -> V_104 ) )
goto V_46;
if ( V_73 -> V_96 != F_89 ( V_5 -> V_104 ) ) {
V_44 = - V_93 ;
F_6 ( V_5 -> V_104 ) ;
goto V_46;
}
if ( F_73 ( V_5 -> V_37 , F_12 ( V_73 -> V_37 ) , V_73 -> V_96 ) ) {
V_44 = - V_45 ;
F_6 ( V_5 -> V_104 ) ;
goto V_46;
}
F_78 ( V_5 -> V_50 , V_5 -> V_104 , V_73 -> V_94 ) ;
V_46:
F_79 ( V_5 -> V_50 ) ;
F_6 ( V_5 ) ;
return V_44 ;
}
static int F_90 ( struct V_1 * V_1 , union V_70 * V_71 )
{
F_91 ( V_1 -> V_3 -> V_50 , true ,
V_71 -> V_159 . type == V_160 ) ;
return 0 ;
}
static void F_92 ( struct V_1 * V_1 ,
struct V_9 * V_10 )
{
struct V_161 * V_5 =
F_4 ( V_10 , struct V_161 , V_10 ) ;
F_93 ( & V_5 -> V_162 ) ;
F_6 ( V_5 ) ;
}
static int F_94 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_163 * V_73 = & V_71 -> V_164 ;
struct V_161 * V_5 ;
int V_44 ;
if ( ! V_1 -> V_3 -> V_165 )
return - V_166 ;
if ( V_73 -> V_96 > 256 )
return - V_93 ;
V_5 = F_72 ( sizeof( * V_5 ) + V_73 -> V_96 * 4 , V_20 ) ;
if ( V_5 == NULL )
return - V_21 ;
if ( F_73 ( V_5 -> V_37 , F_12 ( V_73 -> V_37 ) , V_73 -> V_96 * 4 ) ) {
V_44 = - V_45 ;
goto V_111;
}
V_5 -> V_162 . V_96 = V_73 -> V_96 ;
V_5 -> V_162 . V_167 = V_73 -> V_167 ;
V_5 -> V_162 . V_168 = V_73 -> V_168 ;
V_5 -> V_162 . V_37 = V_5 -> V_37 ;
V_44 = F_95 ( & V_5 -> V_162 ) ;
if ( V_44 < 0 )
goto V_111;
V_5 -> V_10 . V_11 = F_92 ;
V_44 = F_58 ( V_1 , & V_5 -> V_10 , V_20 ) ;
if ( V_44 < 0 ) {
F_93 ( & V_5 -> V_162 ) ;
goto V_111;
}
V_73 -> V_91 = V_5 -> V_10 . V_91 ;
return 0 ;
V_111:
F_6 ( V_5 ) ;
return V_44 ;
}
static int F_96 ( struct V_1 * V_1 , union V_70 * V_71 )
{
return F_63 ( V_1 , V_71 -> V_169 . V_91 ,
F_92 , NULL ) ;
}
static void F_97 ( struct V_170 * V_171 , T_7 V_172 ,
T_3 V_173 , void * V_174 , void * V_37 )
{
struct V_1 * V_1 = V_37 ;
struct V_175 * V_68 ;
V_68 = F_72 ( sizeof( * V_68 ) + V_173 , V_136 ) ;
if ( V_68 == NULL )
return;
V_68 -> V_176 . type = V_177 ;
V_68 -> V_176 . V_51 = V_1 -> V_178 ;
V_68 -> V_176 . V_172 = V_172 ;
V_68 -> V_176 . V_173 = V_173 ;
memcpy ( V_68 -> V_176 . V_174 , V_174 , V_173 ) ;
F_27 ( V_1 , & V_68 -> V_30 , & V_68 -> V_176 ,
sizeof( V_68 -> V_176 ) + V_173 , NULL , 0 ) ;
}
static void F_98 ( struct V_170 * V_171 ,
T_9 V_179 , void * V_37 )
{
struct V_1 * V_1 = V_37 ;
struct V_180 * V_68 ;
V_68 = F_72 ( sizeof( * V_68 ) , V_136 ) ;
if ( V_68 == NULL )
return;
V_68 -> V_176 . type = V_181 ;
V_68 -> V_176 . V_51 = V_1 -> V_178 ;
V_68 -> V_176 . V_179 = F_99 ( & V_1 -> V_40 ,
V_179 ) ;
F_27 ( V_1 , & V_68 -> V_30 , & V_68 -> V_176 ,
sizeof( V_68 -> V_176 ) , NULL , 0 ) ;
}
static enum V_182 F_100 ( struct V_170 * V_171 )
{
if ( V_171 -> type == V_183 )
return V_184 ;
else
return V_185 ;
}
static int F_101 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_186 * V_73 = & V_71 -> V_187 ;
struct V_170 * V_171 ;
T_10 V_188 ;
int V_44 ;
F_102 ( V_189 != V_183 ||
V_190 != V_191 ||
V_192 !=
V_193 ) ;
switch ( V_73 -> type ) {
case V_183 :
if ( V_73 -> V_106 > V_194 || V_73 -> V_195 > 63 )
return - V_93 ;
V_188 = F_97 ;
break;
case V_191 :
if ( V_73 -> V_196 < 4 || ( V_73 -> V_196 & 3 ) ||
V_73 -> V_195 > 63 )
return - V_93 ;
V_188 = F_97 ;
break;
case V_193 :
V_188 = ( T_10 ) F_98 ;
break;
default:
return - V_93 ;
}
V_171 = F_103 ( V_1 -> V_3 -> V_50 , V_73 -> type ,
V_73 -> V_195 , V_73 -> V_106 , V_73 -> V_196 , V_188 , V_1 ) ;
if ( F_104 ( V_171 ) )
return F_105 ( V_171 ) ;
if ( V_1 -> V_76 < V_197 )
V_171 -> V_198 = true ;
F_35 ( & V_1 -> V_22 ) ;
if ( V_1 -> V_199 != NULL ) {
F_38 ( & V_1 -> V_22 ) ;
F_106 ( V_171 ) ;
return - V_200 ;
}
if ( ! V_1 -> V_201 ) {
V_44 = F_107 ( & V_1 -> V_40 ,
V_1 -> V_3 -> V_50 ,
F_100 ( V_171 ) ) ;
if ( V_44 < 0 ) {
F_38 ( & V_1 -> V_22 ) ;
F_106 ( V_171 ) ;
return V_44 ;
}
V_1 -> V_201 = true ;
}
V_1 -> V_178 = V_73 -> V_51 ;
V_1 -> V_199 = V_171 ;
F_38 ( & V_1 -> V_22 ) ;
V_73 -> V_91 = 0 ;
return 0 ;
}
static int F_108 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_202 * V_73 = & V_71 -> V_203 ;
struct V_170 * V_204 = V_1 -> V_199 ;
if ( V_204 == NULL || V_73 -> V_91 != 0 )
return - V_93 ;
return F_109 ( V_204 , & V_73 -> V_205 ) ;
}
static int F_110 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_206 * V_73 = & V_71 -> V_207 ;
struct V_208 T_1 * V_66 , * V_153 , * V_209 ;
struct V_170 * V_204 = V_1 -> V_199 ;
unsigned long V_95 , V_210 , V_211 = 0 ;
T_7 V_212 ;
int V_41 ;
struct {
struct V_213 V_214 ;
T_11 V_174 [ 256 ] ;
} V_215 ;
if ( V_204 == NULL || V_73 -> V_91 != 0 )
return - V_93 ;
V_95 = ( unsigned long ) V_73 -> V_37 - V_1 -> V_216 ;
V_210 = V_1 -> V_40 . V_217 << V_218 ;
if ( V_73 -> V_37 == 0 || V_1 -> V_40 . V_219 == NULL ||
V_95 >= V_210 ) {
V_95 = 0 ;
V_210 = 0 ;
}
if ( V_204 -> type == V_193 && V_95 & 3 )
return - V_93 ;
V_66 = (struct V_208 T_1 * ) F_12 ( V_73 -> V_220 ) ;
if ( ! F_111 ( V_221 , V_66 , V_73 -> V_38 ) )
return - V_45 ;
V_153 = ( void T_1 * ) V_66 + V_73 -> V_38 ;
V_41 = 0 ;
while ( V_66 < V_153 ) {
if ( F_112 ( V_212 , & V_66 -> V_212 ) )
return - V_45 ;
V_215 . V_214 . V_222 = F_113 ( V_212 ) ;
V_215 . V_214 . V_176 = F_114 ( V_212 ) ;
V_215 . V_214 . V_223 = F_115 ( V_212 ) ;
V_215 . V_214 . V_224 = F_116 ( V_212 ) ;
V_215 . V_214 . V_225 = F_117 ( V_212 ) ;
V_215 . V_214 . V_173 = F_118 ( V_212 ) ;
switch ( V_204 -> type ) {
case V_183 :
if ( V_215 . V_214 . V_173 & 3 )
return - V_93 ;
V_211 = V_215 . V_214 . V_173 ;
break;
case V_191 :
if ( V_215 . V_214 . V_173 == 0 ||
V_215 . V_214 . V_173 % V_204 -> V_196 != 0 )
return - V_93 ;
break;
case V_193 :
if ( V_215 . V_214 . V_222 == 0 ||
V_215 . V_214 . V_222 & 3 )
return - V_93 ;
break;
}
V_209 = (struct V_208 T_1 * )
& V_66 -> V_174 [ V_211 / 4 ] ;
if ( V_209 > V_153 )
return - V_93 ;
if ( F_119
( V_215 . V_214 . V_174 , V_66 -> V_174 , V_211 ) )
return - V_45 ;
if ( V_215 . V_214 . V_223 && V_204 -> type == V_183 &&
V_215 . V_214 . V_173 + V_215 . V_214 . V_222 > 0 )
return - V_93 ;
if ( V_95 + V_215 . V_214 . V_222 > V_210 )
return - V_93 ;
if ( F_120 ( V_204 , & V_215 . V_214 ,
& V_1 -> V_40 , V_95 ) )
break;
V_66 = V_209 ;
V_95 += V_215 . V_214 . V_222 ;
V_41 ++ ;
}
F_121 ( V_204 ) ;
V_73 -> V_38 -= F_15 ( V_66 ) - V_73 -> V_220 ;
V_73 -> V_220 = F_15 ( V_66 ) ;
V_73 -> V_37 = V_1 -> V_216 + V_95 ;
return V_41 ;
}
static int F_122 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_226 * V_73 = & V_71 -> V_227 ;
F_102 (
V_228 != V_229 ||
V_230 != V_231 ||
V_232 != V_233 ||
V_234 != V_235 ||
V_236 != V_237 ) ;
if ( V_1 -> V_199 == NULL || V_73 -> V_91 != 0 )
return - V_93 ;
if ( V_1 -> V_199 -> type == V_191 &&
( V_73 -> V_238 == 0 || V_73 -> V_238 > 15 || V_73 -> V_239 > 15 ) )
return - V_93 ;
return F_123 ( V_1 -> V_199 ,
V_73 -> V_172 , V_73 -> V_239 , V_73 -> V_238 ) ;
}
static int F_124 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_240 * V_73 = & V_71 -> V_241 ;
if ( V_1 -> V_199 == NULL || V_73 -> V_91 != 0 )
return - V_93 ;
return F_125 ( V_1 -> V_199 ) ;
}
static int F_126 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_242 * V_73 = & V_71 -> V_243 ;
if ( V_1 -> V_199 == NULL || V_73 -> V_91 != 0 )
return - V_93 ;
return F_127 ( V_1 -> V_199 ) ;
}
static int F_128 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_244 * V_73 = & V_71 -> V_245 ;
struct V_49 * V_50 = V_1 -> V_3 -> V_50 ;
struct V_246 V_247 = { 0 , 0 } ;
T_7 V_248 ;
int V_44 = 0 ;
F_129 () ;
V_248 = V_50 -> V_249 -> V_250 ( V_50 , V_251 ) ;
switch ( V_73 -> V_252 ) {
case V_253 : F_130 ( & V_247 ) ; break;
case V_254 : F_131 ( & V_247 ) ; break;
case V_255 : F_132 ( & V_247 ) ; break;
default:
V_44 = - V_93 ;
}
F_133 () ;
V_73 -> V_256 = V_247 . V_256 ;
V_73 -> V_257 = V_247 . V_257 ;
V_73 -> V_258 = V_248 ;
return V_44 ;
}
static int F_134 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_259 * V_73 = & V_71 -> V_260 ;
struct V_244 V_261 ;
V_261 . V_252 = V_253 ;
F_128 ( V_1 , (union V_70 * ) & V_261 ) ;
V_73 -> V_262 = V_261 . V_256 * V_263 + V_261 . V_257 / V_264 ;
V_73 -> V_258 = V_261 . V_258 ;
return 0 ;
}
static void F_135 ( struct V_265 * V_8 )
{
struct V_266 * V_68 ;
struct V_4 * V_5 =
F_4 ( V_8 , struct V_4 , V_8 . V_8 ) ;
struct V_1 * V_1 = V_5 -> V_1 ;
int V_54 , V_195 , V_267 , V_268 ;
bool V_223 , free , V_269 ;
F_35 ( & V_1 -> V_22 ) ;
V_54 = V_1 -> V_3 -> V_54 ;
V_268 = V_5 -> V_268 ;
if ( V_268 == V_270 &&
F_136 ( F_137 () ,
V_1 -> V_3 -> V_50 -> V_271 + V_272 ) ) {
F_9 ( V_5 , F_138 ( V_272 , 3 ) ) ;
V_223 = true ;
} else {
V_223 = V_268 == V_273 &&
V_5 -> V_54 == V_54 ;
}
free = V_268 == V_274 ||
V_268 == V_275 ||
V_268 == V_276 ;
V_5 -> V_54 = V_54 ;
F_38 ( & V_1 -> V_22 ) ;
if ( V_223 )
goto V_46;
V_267 = V_5 -> V_267 ;
F_139 ( V_1 -> V_3 -> V_50 , V_54 ,
V_5 -> V_205 , & V_195 , & V_267 ,
V_268 == V_270 ||
V_268 == V_273 ||
V_268 == V_275 ) ;
if ( V_195 == - V_277 &&
( V_268 == V_270 || V_268 == V_273 ) )
goto V_46;
V_269 = V_195 >= 0 || V_267 > 0 ;
F_35 ( & V_1 -> V_22 ) ;
if ( V_5 -> V_268 == V_270 )
V_5 -> V_268 = V_273 ;
if ( V_5 -> V_268 == V_273 && ! V_269 &&
! V_1 -> V_39 &&
F_65 ( & V_1 -> V_23 , V_5 -> V_10 . V_91 ) ) {
F_7 ( V_1 ) ;
free = true ;
}
F_38 ( & V_1 -> V_22 ) ;
if ( V_268 == V_270 && V_195 >= 0 )
V_5 -> V_205 = 1ULL << V_195 ;
if ( V_268 == V_273 && V_269 )
goto V_46;
if ( V_268 == V_270 || V_268 == V_275 ) {
V_68 = V_5 -> V_278 ;
V_5 -> V_278 = NULL ;
} else {
V_68 = V_5 -> V_279 ;
V_5 -> V_279 = NULL ;
}
V_68 -> V_4 . V_91 = V_5 -> V_10 . V_91 ;
V_68 -> V_4 . V_195 = V_195 ;
V_68 -> V_4 . V_267 = V_267 ;
F_27 ( V_1 , & V_68 -> V_30 ,
& V_68 -> V_4 , sizeof( V_68 -> V_4 ) , NULL , 0 ) ;
if ( free ) {
F_140 ( & V_5 -> V_8 ) ;
F_6 ( V_5 -> V_278 ) ;
F_6 ( V_5 -> V_279 ) ;
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
V_5 -> V_268 = V_274 ;
F_9 ( V_5 , 0 ) ;
F_38 ( & V_1 -> V_22 ) ;
}
static int F_141 ( struct V_1 * V_1 ,
struct V_280 * V_104 , int V_268 )
{
struct V_266 * V_281 , * V_282 ;
struct V_4 * V_5 ;
int V_44 ;
if ( ( V_104 -> V_205 == 0 && V_104 -> V_267 == 0 ) ||
V_104 -> V_267 > V_283 )
return - V_93 ;
V_5 = F_72 ( sizeof( * V_5 ) , V_20 ) ;
V_281 = F_72 ( sizeof( * V_281 ) , V_20 ) ;
V_282 = F_72 ( sizeof( * V_282 ) , V_20 ) ;
if ( V_5 == NULL || V_281 == NULL || V_282 == NULL ) {
V_44 = - V_21 ;
goto V_284;
}
F_142 ( & V_5 -> V_8 , F_135 ) ;
V_5 -> V_1 = V_1 ;
V_5 -> V_268 = V_268 ;
V_5 -> V_54 = - 1 ;
V_5 -> V_205 = V_104 -> V_205 ;
V_5 -> V_267 = V_104 -> V_267 ;
V_5 -> V_278 = V_281 ;
V_5 -> V_279 = V_282 ;
V_281 -> V_4 . V_51 = V_104 -> V_51 ;
V_281 -> V_4 . type = V_285 ;
V_282 -> V_4 . V_51 = V_104 -> V_51 ;
V_282 -> V_4 . type = V_286 ;
if ( V_268 == V_270 ) {
V_5 -> V_10 . V_11 = V_12 ;
V_44 = F_58 ( V_1 , & V_5 -> V_10 , V_20 ) ;
if ( V_44 < 0 )
goto V_284;
} else {
V_5 -> V_10 . V_11 = NULL ;
V_5 -> V_10 . V_91 = - 1 ;
F_9 ( V_5 , 0 ) ;
}
V_104 -> V_91 = V_5 -> V_10 . V_91 ;
return 0 ;
V_284:
F_6 ( V_5 ) ;
F_6 ( V_281 ) ;
F_6 ( V_282 ) ;
return V_44 ;
}
static int F_143 ( struct V_1 * V_1 ,
union V_70 * V_71 )
{
return F_141 ( V_1 ,
& V_71 -> V_287 , V_270 ) ;
}
static int F_144 ( struct V_1 * V_1 ,
union V_70 * V_71 )
{
return F_63 ( V_1 ,
V_71 -> V_156 . V_91 , V_12 , NULL ) ;
}
static int F_145 ( struct V_1 * V_1 ,
union V_70 * V_71 )
{
return F_141 ( V_1 ,
& V_71 -> V_287 , V_275 ) ;
}
static int F_146 ( struct V_1 * V_1 ,
union V_70 * V_71 )
{
return F_141 ( V_1 ,
& V_71 -> V_287 , V_276 ) ;
}
static int F_147 ( struct V_1 * V_1 , union V_70 * V_71 )
{
return V_1 -> V_3 -> V_124 ;
}
static int F_148 ( struct V_1 * V_1 ,
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
if ( V_73 -> V_47 < V_288 + V_289 )
return - V_290 ;
return F_71 ( V_1 , V_73 , V_291 | 0x3f , V_292 ) ;
}
static int F_149 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_293 * V_73 = & V_71 -> V_294 ;
struct V_103 V_104 ;
int V_295 ;
if ( V_73 -> V_106 > V_1 -> V_3 -> V_50 -> V_296 ||
V_73 -> V_96 > 1024 << V_73 -> V_106 )
return - V_109 ;
if ( V_73 -> V_224 > 3 || V_73 -> V_195 > 63 || V_73 -> V_225 > 15 )
return - V_93 ;
V_295 = F_150 ( V_73 -> V_224 , V_73 -> V_195 , V_73 -> V_225 ) ;
V_104 . V_107 = V_108 ;
V_104 . V_96 = V_73 -> V_96 ;
V_104 . V_51 = V_73 -> V_51 ;
V_104 . V_37 = V_73 -> V_37 ;
V_104 . V_54 = V_73 -> V_54 ;
return F_71 ( V_1 , & V_104 , V_295 , V_73 -> V_106 ) ;
}
static void F_151 ( struct V_297 * V_214 ,
struct V_49 * V_50 , int V_298 )
{
struct V_299 * V_68 =
F_4 ( V_214 , struct V_299 , V_66 ) ;
switch ( V_298 ) {
case V_300 : V_68 -> V_301 . V_94 = V_101 ; break;
case V_302 : V_68 -> V_301 . V_94 = V_101 ; break;
case V_303 :
case V_304 :
case V_305 : V_68 -> V_301 . V_94 = V_306 ; break;
case V_307 : V_68 -> V_301 . V_94 = V_308 ; break;
case V_309 : V_68 -> V_301 . V_94 = V_310 ; break;
default: V_68 -> V_301 . V_94 = V_298 ; break;
}
V_68 -> V_301 . V_37 [ 0 ] = V_214 -> V_311 ;
F_27 ( V_68 -> V_1 , & V_68 -> V_30 , & V_68 -> V_301 ,
sizeof( V_68 -> V_301 ) + V_68 -> V_301 . V_96 , NULL , 0 ) ;
F_7 ( V_68 -> V_1 ) ;
}
static int F_152 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_312 * V_73 = & V_71 -> V_313 ;
struct V_49 * V_50 = V_1 -> V_3 -> V_50 ;
struct V_299 * V_68 ;
if ( ! V_1 -> V_3 -> V_165 )
return - V_166 ;
V_68 = F_20 ( sizeof( * V_68 ) + 4 , V_20 ) ;
if ( V_68 == NULL )
return - V_21 ;
F_1 ( V_1 ) ;
V_68 -> V_1 = V_1 ;
V_68 -> V_66 . V_106 = V_292 ;
V_68 -> V_66 . V_54 = V_73 -> V_54 ;
V_68 -> V_66 . V_174 [ 0 ] = V_314 << 4 ;
V_68 -> V_66 . V_174 [ 1 ] = V_73 -> V_37 [ 0 ] ;
V_68 -> V_66 . V_174 [ 2 ] = V_73 -> V_37 [ 1 ] ;
V_68 -> V_66 . V_173 = 12 ;
V_68 -> V_66 . F_45 = F_151 ;
V_68 -> V_301 . V_51 = V_73 -> V_51 ;
V_68 -> V_301 . type = V_315 ;
if ( F_153 ( V_73 -> V_37 ) )
V_68 -> V_301 . V_96 = 4 ;
V_50 -> V_249 -> V_113 ( V_50 , & V_68 -> V_66 ) ;
return 0 ;
}
static int F_154 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_316 * V_73 = & V_71 -> V_317 ;
struct V_49 * V_50 = V_1 -> V_3 -> V_50 ;
if ( ! V_1 -> V_3 -> V_165 )
return - V_166 ;
F_35 ( & V_50 -> V_22 ) ;
F_155 ( & V_1 -> V_27 , & V_50 -> V_318 ) ;
V_1 -> V_319 = V_73 -> V_51 ;
F_38 ( & V_50 -> V_22 ) ;
return 0 ;
}
void F_156 ( struct V_49 * V_50 , struct V_297 * V_66 )
{
struct V_1 * V_1 ;
struct V_320 * V_68 ;
unsigned long V_35 ;
F_28 ( & V_50 -> V_22 , V_35 ) ;
F_47 (client, &card->phy_receiver_list, phy_receiver_link) {
V_68 = F_72 ( sizeof( * V_68 ) + 8 , V_136 ) ;
if ( V_68 == NULL )
break;
V_68 -> V_301 . V_51 = V_1 -> V_319 ;
V_68 -> V_301 . type = V_321 ;
V_68 -> V_301 . V_94 = V_101 ;
V_68 -> V_301 . V_96 = 8 ;
V_68 -> V_301 . V_37 [ 0 ] = V_66 -> V_174 [ 1 ] ;
V_68 -> V_301 . V_37 [ 1 ] = V_66 -> V_174 [ 2 ] ;
F_27 ( V_1 , & V_68 -> V_30 ,
& V_68 -> V_301 , sizeof( V_68 -> V_301 ) + 8 , NULL , 0 ) ;
}
F_30 ( & V_50 -> V_22 , V_35 ) ;
}
static int F_157 ( struct V_1 * V_1 ,
unsigned int V_322 , void T_1 * V_71 )
{
union V_70 V_40 ;
int V_44 ;
if ( F_19 ( V_1 -> V_3 ) )
return - V_19 ;
if ( F_158 ( V_322 ) != '#' ||
F_159 ( V_322 ) >= F_39 ( V_323 ) ||
F_160 ( V_322 ) > sizeof( V_40 ) )
return - V_324 ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
if ( F_161 ( V_322 ) & V_325 )
if ( F_73 ( & V_40 , V_71 , F_160 ( V_322 ) ) )
return - V_45 ;
V_44 = V_323 [ F_159 ( V_322 ) ] ( V_1 , & V_40 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( F_161 ( V_322 ) & V_326 )
if ( F_41 ( V_71 , & V_40 , F_160 ( V_322 ) ) )
return - V_45 ;
return V_44 ;
}
static long F_162 ( struct V_16 * V_16 ,
unsigned int V_322 , unsigned long V_71 )
{
return F_157 ( V_16 -> V_29 , V_322 , ( void T_1 * ) V_71 ) ;
}
static long F_163 ( struct V_16 * V_16 ,
unsigned int V_322 , unsigned long V_71 )
{
return F_157 ( V_16 -> V_29 , V_322 , F_14 ( V_71 ) ) ;
}
static int F_164 ( struct V_16 * V_16 , struct V_327 * V_328 )
{
struct V_1 * V_1 = V_16 -> V_29 ;
unsigned long V_38 ;
int V_217 , V_44 ;
if ( F_19 ( V_1 -> V_3 ) )
return - V_19 ;
if ( V_1 -> V_40 . V_219 != NULL )
return - V_200 ;
if ( ! ( V_328 -> V_329 & V_330 ) )
return - V_93 ;
if ( V_328 -> V_216 & ~ V_331 )
return - V_93 ;
V_1 -> V_216 = V_328 -> V_216 ;
V_38 = V_328 -> V_332 - V_328 -> V_216 ;
V_217 = V_38 >> V_218 ;
if ( V_38 & ~ V_331 )
return - V_93 ;
V_44 = F_165 ( & V_1 -> V_40 , V_217 ) ;
if ( V_44 < 0 )
return V_44 ;
F_35 ( & V_1 -> V_22 ) ;
if ( V_1 -> V_199 ) {
V_44 = F_107 ( & V_1 -> V_40 ,
V_1 -> V_3 -> V_50 ,
F_100 ( V_1 -> V_199 ) ) ;
V_1 -> V_201 = ( V_44 == 0 ) ;
}
F_38 ( & V_1 -> V_22 ) ;
if ( V_44 < 0 )
goto V_284;
V_44 = F_166 ( & V_1 -> V_40 , V_328 ) ;
if ( V_44 < 0 )
goto V_284;
return 0 ;
V_284:
F_167 ( & V_1 -> V_40 , V_1 -> V_3 -> V_50 ) ;
return V_44 ;
}
static int F_168 ( int V_65 , void * V_66 , void * V_37 )
{
struct V_9 * V_10 = V_66 ;
return V_10 -> V_11 == F_66 ;
}
static int F_169 ( struct V_1 * V_1 )
{
int V_44 ;
F_35 ( & V_1 -> V_22 ) ;
V_44 = F_51 ( & V_1 -> V_23 ,
F_168 , NULL ) ;
F_38 ( & V_1 -> V_22 ) ;
return V_44 ;
}
static int F_170 ( int V_65 , void * V_66 , void * V_37 )
{
struct V_9 * V_10 = V_66 ;
struct V_1 * V_1 = V_37 ;
V_10 -> V_11 ( V_1 , V_10 ) ;
F_7 ( V_1 ) ;
return 0 ;
}
static int F_171 ( struct V_15 * V_15 , struct V_16 * V_16 )
{
struct V_1 * V_1 = V_16 -> V_29 ;
struct V_30 * V_30 , * V_333 ;
F_35 ( & V_1 -> V_3 -> V_50 -> V_22 ) ;
F_37 ( & V_1 -> V_27 ) ;
F_38 ( & V_1 -> V_3 -> V_50 -> V_22 ) ;
F_46 ( & V_1 -> V_3 -> V_64 ) ;
F_37 ( & V_1 -> V_28 ) ;
F_48 ( & V_1 -> V_3 -> V_64 ) ;
if ( V_1 -> V_199 )
F_106 ( V_1 -> V_199 ) ;
if ( V_1 -> V_40 . V_219 )
F_167 ( & V_1 -> V_40 , V_1 -> V_3 -> V_50 ) ;
F_35 ( & V_1 -> V_22 ) ;
V_1 -> V_39 = true ;
F_38 ( & V_1 -> V_22 ) ;
F_172 ( V_1 -> V_26 , ! F_169 ( V_1 ) ) ;
F_51 ( & V_1 -> V_23 , F_170 , V_1 ) ;
F_173 ( & V_1 -> V_23 ) ;
F_174 (event, next_event, &client->event_list, link)
F_6 ( V_30 ) ;
F_7 ( V_1 ) ;
return 0 ;
}
static unsigned int F_175 ( struct V_16 * V_16 , T_12 * V_334 )
{
struct V_1 * V_1 = V_16 -> V_29 ;
unsigned int V_335 = 0 ;
F_176 ( V_16 , & V_1 -> V_25 , V_334 ) ;
if ( F_19 ( V_1 -> V_3 ) )
V_335 |= V_336 | V_337 ;
if ( ! F_34 ( & V_1 -> V_24 ) )
V_335 |= V_338 | V_339 ;
return V_335 ;
}
