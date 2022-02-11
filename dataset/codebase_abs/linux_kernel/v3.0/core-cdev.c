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
static inline void T_1 * F_12 ( T_2 V_13 )
{
return ( void T_1 * ) ( unsigned long ) V_13 ;
}
static inline T_2 F_13 ( void T_1 * V_14 )
{
return ( T_2 ) ( unsigned long ) V_14 ;
}
static int F_14 ( struct V_15 * V_15 , struct V_16 * V_16 )
{
struct V_17 * V_3 ;
struct V_1 * V_1 ;
V_3 = F_15 ( V_15 -> V_18 ) ;
if ( V_3 == NULL )
return - V_19 ;
if ( F_16 ( V_3 ) ) {
F_5 ( V_3 ) ;
return - V_19 ;
}
V_1 = F_17 ( sizeof( * V_1 ) , V_20 ) ;
if ( V_1 == NULL ) {
F_5 ( V_3 ) ;
return - V_21 ;
}
V_1 -> V_3 = V_3 ;
F_18 ( & V_1 -> V_22 ) ;
F_19 ( & V_1 -> V_23 ) ;
F_20 ( & V_1 -> V_24 ) ;
F_21 ( & V_1 -> V_25 ) ;
F_21 ( & V_1 -> V_26 ) ;
F_20 ( & V_1 -> V_27 ) ;
F_22 ( & V_1 -> V_2 ) ;
V_16 -> V_28 = V_1 ;
F_23 ( & V_3 -> V_29 ) ;
F_24 ( & V_1 -> V_30 , & V_3 -> V_31 ) ;
F_25 ( & V_3 -> V_29 ) ;
return F_26 ( V_15 , V_16 ) ;
}
static void F_27 ( struct V_1 * V_1 , struct V_32 * V_32 ,
void * V_33 , T_3 V_34 , void * V_35 , T_3 V_36 )
{
unsigned long V_37 ;
V_32 -> V_38 [ 0 ] . V_39 = V_33 ;
V_32 -> V_38 [ 0 ] . V_40 = V_34 ;
V_32 -> V_38 [ 1 ] . V_39 = V_35 ;
V_32 -> V_38 [ 1 ] . V_40 = V_36 ;
F_28 ( & V_1 -> V_22 , V_37 ) ;
if ( V_1 -> V_41 )
F_6 ( V_32 ) ;
else
F_24 ( & V_32 -> V_30 , & V_1 -> V_24 ) ;
F_29 ( & V_1 -> V_22 , V_37 ) ;
F_30 ( & V_1 -> V_25 ) ;
}
static int F_31 ( struct V_1 * V_1 ,
char T_1 * V_42 , T_3 V_43 )
{
struct V_32 * V_32 ;
T_3 V_40 , V_44 ;
int V_45 , V_46 ;
V_46 = F_32 ( V_1 -> V_25 ,
! F_33 ( & V_1 -> V_24 ) ||
F_16 ( V_1 -> V_3 ) ) ;
if ( V_46 < 0 )
return V_46 ;
if ( F_33 ( & V_1 -> V_24 ) &&
F_16 ( V_1 -> V_3 ) )
return - V_19 ;
F_34 ( & V_1 -> V_22 ) ;
V_32 = F_35 ( & V_1 -> V_24 , struct V_32 , V_30 ) ;
F_36 ( & V_32 -> V_30 ) ;
F_37 ( & V_1 -> V_22 ) ;
V_44 = 0 ;
for ( V_45 = 0 ; V_45 < F_38 ( V_32 -> V_38 ) && V_44 < V_43 ; V_45 ++ ) {
V_40 = F_39 ( V_32 -> V_38 [ V_45 ] . V_40 , V_43 - V_44 ) ;
if ( F_40 ( V_42 + V_44 , V_32 -> V_38 [ V_45 ] . V_39 , V_40 ) ) {
V_46 = - V_47 ;
goto V_48;
}
V_44 += V_40 ;
}
V_46 = V_44 ;
V_48:
F_6 ( V_32 ) ;
return V_46 ;
}
static T_4 F_41 ( struct V_16 * V_16 , char T_1 * V_42 ,
T_3 V_43 , T_5 * V_49 )
{
struct V_1 * V_1 = V_16 -> V_28 ;
return F_31 ( V_1 , V_42 , V_43 ) ;
}
static void F_42 ( struct V_50 * V_32 ,
struct V_1 * V_1 )
{
struct V_51 * V_52 = V_1 -> V_3 -> V_52 ;
F_34 ( & V_52 -> V_22 ) ;
V_32 -> V_53 = V_1 -> V_54 ;
V_32 -> type = V_55 ;
V_32 -> V_56 = V_1 -> V_3 -> V_56 ;
V_32 -> V_57 = V_1 -> V_3 -> V_57 ;
V_32 -> V_58 = V_52 -> V_59 -> V_57 ;
V_32 -> V_60 = V_52 -> V_60 ;
V_32 -> V_61 = V_52 -> V_62 -> V_57 ;
V_32 -> V_63 = V_52 -> V_64 -> V_57 ;
F_37 ( & V_52 -> V_22 ) ;
}
static void F_43 ( struct V_17 * V_3 ,
void (* F_44)( struct V_1 * V_1 ) )
{
struct V_1 * V_65 ;
F_23 ( & V_3 -> V_29 ) ;
F_45 (c, &device->client_list, link)
F_44 ( V_65 ) ;
F_25 ( & V_3 -> V_29 ) ;
}
static int F_46 ( int V_66 , void * V_67 , void * V_39 )
{
F_11 ( V_67 ) ;
return 0 ;
}
static void F_47 ( struct V_1 * V_1 )
{
struct V_68 * V_69 ;
V_69 = F_17 ( sizeof( * V_69 ) , V_20 ) ;
if ( V_69 == NULL ) {
F_48 ( L_1 ) ;
return;
}
F_42 ( & V_69 -> V_70 , V_1 ) ;
F_27 ( V_1 , & V_69 -> V_32 ,
& V_69 -> V_70 , sizeof( V_69 -> V_70 ) , NULL , 0 ) ;
F_34 ( & V_1 -> V_22 ) ;
F_49 ( & V_1 -> V_23 , F_46 , V_1 ) ;
F_37 ( & V_1 -> V_22 ) ;
}
void F_50 ( struct V_17 * V_3 )
{
F_43 ( V_3 , F_47 ) ;
}
static void F_51 ( struct V_1 * V_1 )
{
F_30 ( & V_1 -> V_25 ) ;
}
void F_52 ( struct V_17 * V_3 )
{
F_43 ( V_3 , F_51 ) ;
}
static int F_53 ( struct V_1 * V_1 , union V_71 * V_72 )
{
struct V_73 * V_74 = & V_72 -> V_75 ;
struct V_50 V_76 ;
unsigned long V_46 = 0 ;
V_1 -> V_77 = V_74 -> V_77 ;
V_74 -> V_77 = V_78 ;
V_74 -> V_52 = V_1 -> V_3 -> V_52 -> V_79 ;
F_54 ( & V_80 ) ;
if ( V_74 -> V_81 != 0 ) {
T_3 V_82 = V_74 -> V_83 ;
T_3 V_84 = V_1 -> V_3 -> V_85 * 4 ;
V_46 = F_40 ( F_12 ( V_74 -> V_81 ) ,
V_1 -> V_3 -> V_86 , F_39 ( V_82 , V_84 ) ) ;
}
V_74 -> V_83 = V_1 -> V_3 -> V_85 * 4 ;
F_55 ( & V_80 ) ;
if ( V_46 != 0 )
return - V_47 ;
V_1 -> V_54 = V_74 -> V_54 ;
if ( V_74 -> V_76 != 0 ) {
F_42 ( & V_76 , V_1 ) ;
if ( F_40 ( F_12 ( V_74 -> V_76 ) ,
& V_76 , sizeof( V_76 ) ) )
return - V_47 ;
}
return 0 ;
}
static int F_56 ( struct V_1 * V_1 ,
struct V_9 * V_10 , T_6 V_87 )
{
unsigned long V_37 ;
int V_46 ;
V_88:
if ( F_57 ( & V_1 -> V_23 , V_87 ) == 0 )
return - V_21 ;
F_28 ( & V_1 -> V_22 , V_37 ) ;
if ( V_1 -> V_41 )
V_46 = - V_89 ;
else
V_46 = F_58 ( & V_1 -> V_23 , V_10 ,
& V_10 -> V_90 ) ;
if ( V_46 >= 0 ) {
F_1 ( V_1 ) ;
F_11 ( V_10 ) ;
}
F_29 ( & V_1 -> V_22 , V_37 ) ;
if ( V_46 == - V_91 )
goto V_88;
return V_46 < 0 ? V_46 : 0 ;
}
static int F_59 ( struct V_1 * V_1 , T_7 V_90 ,
T_8 V_11 ,
struct V_9 * * V_92 )
{
struct V_9 * V_10 ;
F_34 ( & V_1 -> V_22 ) ;
if ( V_1 -> V_41 )
V_10 = NULL ;
else
V_10 = F_60 ( & V_1 -> V_23 , V_90 ) ;
if ( V_10 && V_10 -> V_11 == V_11 )
F_61 ( & V_1 -> V_23 , V_90 ) ;
F_37 ( & V_1 -> V_22 ) ;
if ( ! ( V_10 && V_10 -> V_11 == V_11 ) )
return - V_93 ;
if ( V_92 )
* V_92 = V_10 ;
else
V_10 -> V_11 ( V_1 , V_10 ) ;
F_7 ( V_1 ) ;
return 0 ;
}
static void F_62 ( struct V_1 * V_1 ,
struct V_9 * V_10 )
{
}
static void F_63 ( struct V_51 * V_52 , int V_94 ,
void * V_95 , T_3 V_96 , void * V_39 )
{
struct V_97 * V_69 = V_39 ;
struct V_98 * V_99 = & V_69 -> V_100 ;
struct V_1 * V_1 = V_69 -> V_1 ;
unsigned long V_37 ;
if ( V_96 < V_99 -> V_96 )
V_99 -> V_96 = V_96 ;
if ( V_94 == V_101 )
memcpy ( V_99 -> V_39 , V_95 , V_99 -> V_96 ) ;
F_28 ( & V_1 -> V_22 , V_37 ) ;
F_61 ( & V_1 -> V_23 , V_69 -> V_5 . V_10 . V_90 ) ;
if ( V_1 -> V_41 )
F_64 ( & V_1 -> V_26 ) ;
F_29 ( & V_1 -> V_22 , V_37 ) ;
V_99 -> type = V_102 ;
V_99 -> V_94 = V_94 ;
if ( V_99 -> V_96 <= sizeof( * V_99 ) - F_65 ( F_66 ( * V_99 ) , V_39 ) )
F_27 ( V_1 , & V_69 -> V_32 , V_99 , sizeof( * V_99 ) ,
V_99 -> V_39 , V_99 -> V_96 ) ;
else
F_27 ( V_1 , & V_69 -> V_32 , V_99 , sizeof( * V_99 ) + V_99 -> V_96 ,
NULL , 0 ) ;
F_7 ( V_1 ) ;
}
static int F_67 ( struct V_1 * V_1 ,
struct V_103 * V_104 ,
int V_105 , int V_106 )
{
struct V_97 * V_69 ;
int V_46 ;
if ( V_104 -> V_107 != V_108 &&
( V_104 -> V_96 > 4096 || V_104 -> V_96 > 512 << V_106 ) )
return - V_109 ;
if ( V_104 -> V_107 == V_110 &&
V_104 -> V_96 < 4 )
return - V_93 ;
V_69 = F_68 ( sizeof( * V_69 ) + V_104 -> V_96 , V_20 ) ;
if ( V_69 == NULL )
return - V_21 ;
V_69 -> V_1 = V_1 ;
V_69 -> V_100 . V_96 = V_104 -> V_96 ;
V_69 -> V_100 . V_53 = V_104 -> V_53 ;
if ( V_104 -> V_39 &&
F_69 ( V_69 -> V_100 . V_39 ,
F_12 ( V_104 -> V_39 ) , V_104 -> V_96 ) ) {
V_46 = - V_47 ;
goto V_111;
}
V_69 -> V_5 . V_10 . V_11 = F_62 ;
V_46 = F_56 ( V_1 , & V_69 -> V_5 . V_10 , V_20 ) ;
if ( V_46 < 0 )
goto V_111;
F_70 ( V_1 -> V_3 -> V_52 , & V_69 -> V_5 . V_112 ,
V_104 -> V_107 , V_105 , V_104 -> V_56 ,
V_106 , V_104 -> V_49 , V_69 -> V_100 . V_39 ,
V_104 -> V_96 , F_63 , V_69 ) ;
return 0 ;
V_111:
F_6 ( V_69 ) ;
return V_46 ;
}
static int F_71 ( struct V_1 * V_1 , union V_71 * V_72 )
{
switch ( V_72 -> V_113 . V_107 ) {
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
return F_67 ( V_1 , & V_72 -> V_113 , V_1 -> V_3 -> V_57 ,
V_1 -> V_3 -> V_124 ) ;
}
static inline bool F_72 ( struct V_125 * V_104 )
{
return V_104 == NULL ;
}
static void F_73 ( struct V_1 * V_1 ,
struct V_9 * V_10 )
{
struct V_126 * V_5 = F_4 ( V_10 ,
struct V_126 , V_10 ) ;
if ( F_72 ( V_5 -> V_104 ) )
F_6 ( V_5 -> V_39 ) ;
else
F_74 ( V_5 -> V_52 , V_5 -> V_104 , V_127 ) ;
F_75 ( V_5 -> V_52 ) ;
F_6 ( V_5 ) ;
}
static void F_76 ( struct V_51 * V_52 , struct V_125 * V_104 ,
int V_107 , int V_128 , int V_129 ,
int V_56 , unsigned long long V_49 ,
void * V_95 , T_3 V_96 , void * V_130 )
{
struct V_131 * V_132 = V_130 ;
struct V_126 * V_5 ;
struct V_133 * V_69 ;
T_3 V_134 ;
void * V_135 = NULL ;
int V_46 ;
F_77 ( V_52 ) ;
V_5 = F_68 ( sizeof( * V_5 ) , V_136 ) ;
V_69 = F_68 ( sizeof( * V_69 ) , V_136 ) ;
if ( V_5 == NULL || V_69 == NULL ) {
F_48 ( L_1 ) ;
goto V_111;
}
V_5 -> V_52 = V_52 ;
V_5 -> V_104 = V_104 ;
V_5 -> V_39 = V_95 ;
V_5 -> V_96 = V_96 ;
if ( F_72 ( V_104 ) ) {
V_135 = F_78 ( V_95 , V_96 , V_136 ) ;
if ( V_135 == NULL )
goto V_111;
V_5 -> V_39 = V_135 ;
}
V_5 -> V_10 . V_11 = F_73 ;
V_46 = F_56 ( V_132 -> V_1 , & V_5 -> V_10 , V_136 ) ;
if ( V_46 < 0 )
goto V_111;
if ( V_132 -> V_1 -> V_77 < V_137 ) {
struct V_138 * V_139 = & V_69 -> V_139 . V_104 ;
if ( V_107 & 0x10 )
V_107 = V_140 ;
V_139 -> type = V_141 ;
V_139 -> V_107 = V_107 ;
V_139 -> V_49 = V_49 ;
V_139 -> V_96 = V_96 ;
V_139 -> V_90 = V_5 -> V_10 . V_90 ;
V_139 -> V_53 = V_132 -> V_53 ;
V_134 = sizeof( * V_139 ) ;
} else {
struct V_142 * V_139 = & V_69 -> V_139 . V_143 ;
V_139 -> type = V_144 ;
V_139 -> V_107 = V_107 ;
V_139 -> V_49 = V_49 ;
V_139 -> V_145 = V_129 ;
V_139 -> V_146 = V_128 ;
V_139 -> V_52 = V_52 -> V_79 ;
V_139 -> V_56 = V_56 ;
V_139 -> V_96 = V_96 ;
V_139 -> V_90 = V_5 -> V_10 . V_90 ;
V_139 -> V_53 = V_132 -> V_53 ;
V_134 = sizeof( * V_139 ) ;
}
F_27 ( V_132 -> V_1 , & V_69 -> V_32 ,
& V_69 -> V_139 , V_134 , V_5 -> V_39 , V_96 ) ;
return;
V_111:
F_6 ( V_5 ) ;
F_6 ( V_69 ) ;
F_6 ( V_135 ) ;
if ( ! F_72 ( V_104 ) )
F_74 ( V_52 , V_104 , V_127 ) ;
F_75 ( V_52 ) ;
}
static void F_79 ( struct V_1 * V_1 ,
struct V_9 * V_10 )
{
struct V_131 * V_5 =
F_4 ( V_10 , struct V_131 , V_10 ) ;
F_80 ( & V_5 -> V_132 ) ;
F_6 ( V_5 ) ;
}
static int F_81 ( struct V_1 * V_1 , union V_71 * V_72 )
{
struct V_147 * V_74 = & V_72 -> V_148 ;
struct V_131 * V_5 ;
struct V_149 V_150 ;
int V_46 ;
V_5 = F_68 ( sizeof( * V_5 ) , V_20 ) ;
if ( V_5 == NULL )
return - V_21 ;
V_150 . V_151 = V_74 -> V_49 ;
if ( V_1 -> V_77 < V_152 )
V_150 . V_153 = V_74 -> V_49 + V_74 -> V_96 ;
else
V_150 . V_153 = V_74 -> V_154 ;
V_5 -> V_132 . V_96 = V_74 -> V_96 ;
V_5 -> V_132 . V_155 = F_76 ;
V_5 -> V_132 . V_130 = V_5 ;
V_5 -> V_53 = V_74 -> V_53 ;
V_5 -> V_1 = V_1 ;
V_46 = F_82 ( & V_5 -> V_132 , & V_150 ) ;
if ( V_46 < 0 ) {
F_6 ( V_5 ) ;
return V_46 ;
}
V_74 -> V_49 = V_5 -> V_132 . V_49 ;
V_5 -> V_10 . V_11 = F_79 ;
V_46 = F_56 ( V_1 , & V_5 -> V_10 , V_20 ) ;
if ( V_46 < 0 ) {
F_79 ( V_1 , & V_5 -> V_10 ) ;
return V_46 ;
}
V_74 -> V_90 = V_5 -> V_10 . V_90 ;
return 0 ;
}
static int F_83 ( struct V_1 * V_1 , union V_71 * V_72 )
{
return F_59 ( V_1 , V_72 -> V_156 . V_90 ,
F_79 , NULL ) ;
}
static int F_84 ( struct V_1 * V_1 , union V_71 * V_72 )
{
struct V_157 * V_74 = & V_72 -> V_158 ;
struct V_9 * V_10 ;
struct V_126 * V_5 ;
int V_46 = 0 ;
if ( F_59 ( V_1 , V_74 -> V_90 ,
F_73 , & V_10 ) < 0 )
return - V_93 ;
V_5 = F_4 ( V_10 , struct V_126 ,
V_10 ) ;
if ( F_72 ( V_5 -> V_104 ) )
goto V_48;
if ( V_74 -> V_96 != F_85 ( V_5 -> V_104 ) ) {
V_46 = - V_93 ;
F_6 ( V_5 -> V_104 ) ;
goto V_48;
}
if ( F_69 ( V_5 -> V_39 , F_12 ( V_74 -> V_39 ) , V_74 -> V_96 ) ) {
V_46 = - V_47 ;
F_6 ( V_5 -> V_104 ) ;
goto V_48;
}
F_74 ( V_5 -> V_52 , V_5 -> V_104 , V_74 -> V_94 ) ;
V_48:
F_75 ( V_5 -> V_52 ) ;
F_6 ( V_5 ) ;
return V_46 ;
}
static int F_86 ( struct V_1 * V_1 , union V_71 * V_72 )
{
F_87 ( V_1 -> V_3 -> V_52 , true ,
V_72 -> V_159 . type == V_160 ) ;
return 0 ;
}
static void F_88 ( struct V_1 * V_1 ,
struct V_9 * V_10 )
{
struct V_161 * V_5 =
F_4 ( V_10 , struct V_161 , V_10 ) ;
F_89 ( & V_5 -> V_162 ) ;
F_6 ( V_5 ) ;
}
static int F_90 ( struct V_1 * V_1 , union V_71 * V_72 )
{
struct V_163 * V_74 = & V_72 -> V_164 ;
struct V_161 * V_5 ;
int V_46 ;
if ( ! V_1 -> V_3 -> V_165 )
return - V_166 ;
if ( V_74 -> V_96 > 256 )
return - V_93 ;
V_5 = F_68 ( sizeof( * V_5 ) + V_74 -> V_96 * 4 , V_20 ) ;
if ( V_5 == NULL )
return - V_21 ;
if ( F_69 ( V_5 -> V_39 , F_12 ( V_74 -> V_39 ) , V_74 -> V_96 * 4 ) ) {
V_46 = - V_47 ;
goto V_111;
}
V_5 -> V_162 . V_96 = V_74 -> V_96 ;
V_5 -> V_162 . V_167 = V_74 -> V_167 ;
V_5 -> V_162 . V_168 = V_74 -> V_168 ;
V_5 -> V_162 . V_39 = V_5 -> V_39 ;
V_46 = F_91 ( & V_5 -> V_162 ) ;
if ( V_46 < 0 )
goto V_111;
V_5 -> V_10 . V_11 = F_88 ;
V_46 = F_56 ( V_1 , & V_5 -> V_10 , V_20 ) ;
if ( V_46 < 0 ) {
F_89 ( & V_5 -> V_162 ) ;
goto V_111;
}
V_74 -> V_90 = V_5 -> V_10 . V_90 ;
return 0 ;
V_111:
F_6 ( V_5 ) ;
return V_46 ;
}
static int F_92 ( struct V_1 * V_1 , union V_71 * V_72 )
{
return F_59 ( V_1 , V_72 -> V_169 . V_90 ,
F_88 , NULL ) ;
}
static void F_93 ( struct V_170 * V_171 , T_7 V_172 ,
T_3 V_173 , void * V_174 , void * V_39 )
{
struct V_1 * V_1 = V_39 ;
struct V_175 * V_69 ;
V_69 = F_68 ( sizeof( * V_69 ) + V_173 , V_136 ) ;
if ( V_69 == NULL ) {
F_48 ( L_1 ) ;
return;
}
V_69 -> V_176 . type = V_177 ;
V_69 -> V_176 . V_53 = V_1 -> V_178 ;
V_69 -> V_176 . V_172 = V_172 ;
V_69 -> V_176 . V_173 = V_173 ;
memcpy ( V_69 -> V_176 . V_174 , V_174 , V_173 ) ;
F_27 ( V_1 , & V_69 -> V_32 , & V_69 -> V_176 ,
sizeof( V_69 -> V_176 ) + V_173 , NULL , 0 ) ;
}
static void F_94 ( struct V_170 * V_171 ,
T_9 V_179 , void * V_39 )
{
struct V_1 * V_1 = V_39 ;
struct V_180 * V_69 ;
V_69 = F_68 ( sizeof( * V_69 ) , V_136 ) ;
if ( V_69 == NULL ) {
F_48 ( L_1 ) ;
return;
}
V_69 -> V_176 . type = V_181 ;
V_69 -> V_176 . V_53 = V_1 -> V_178 ;
V_69 -> V_176 . V_179 = F_95 ( & V_1 -> V_42 ,
V_179 ) ;
F_27 ( V_1 , & V_69 -> V_32 , & V_69 -> V_176 ,
sizeof( V_69 -> V_176 ) , NULL , 0 ) ;
}
static int F_96 ( struct V_1 * V_1 , union V_71 * V_72 )
{
struct V_182 * V_74 = & V_72 -> V_183 ;
struct V_170 * V_171 ;
T_10 V_184 ;
F_97 ( V_185 != V_186 ||
V_187 != V_188 ||
V_189 !=
V_190 ) ;
switch ( V_74 -> type ) {
case V_186 :
if ( V_74 -> V_106 > V_191 || V_74 -> V_192 > 63 )
return - V_93 ;
V_184 = F_93 ;
break;
case V_188 :
if ( V_74 -> V_193 < 4 || ( V_74 -> V_193 & 3 ) ||
V_74 -> V_192 > 63 )
return - V_93 ;
V_184 = F_93 ;
break;
case V_190 :
V_184 = ( T_10 ) F_94 ;
break;
default:
return - V_93 ;
}
V_171 = F_98 ( V_1 -> V_3 -> V_52 , V_74 -> type ,
V_74 -> V_192 , V_74 -> V_106 , V_74 -> V_193 , V_184 , V_1 ) ;
if ( F_99 ( V_171 ) )
return F_100 ( V_171 ) ;
F_34 ( & V_1 -> V_22 ) ;
if ( V_1 -> V_194 != NULL ) {
F_37 ( & V_1 -> V_22 ) ;
F_101 ( V_171 ) ;
return - V_195 ;
}
V_1 -> V_178 = V_74 -> V_53 ;
V_1 -> V_194 = V_171 ;
F_37 ( & V_1 -> V_22 ) ;
V_74 -> V_90 = 0 ;
return 0 ;
}
static int F_102 ( struct V_1 * V_1 , union V_71 * V_72 )
{
struct V_196 * V_74 = & V_72 -> V_197 ;
struct V_170 * V_198 = V_1 -> V_194 ;
if ( V_198 == NULL || V_74 -> V_90 != 0 )
return - V_93 ;
return F_103 ( V_198 , & V_74 -> V_199 ) ;
}
static int F_104 ( struct V_1 * V_1 , union V_71 * V_72 )
{
struct V_200 * V_74 = & V_72 -> V_201 ;
struct V_202 T_1 * V_67 , * V_153 , * V_203 ;
struct V_170 * V_198 = V_1 -> V_194 ;
unsigned long V_95 , V_204 , V_205 = 0 ;
T_7 V_206 ;
int V_43 ;
struct {
struct V_207 V_208 ;
T_11 V_174 [ 256 ] ;
} V_209 ;
if ( V_198 == NULL || V_74 -> V_90 != 0 )
return - V_93 ;
V_95 = ( unsigned long ) V_74 -> V_39 - V_1 -> V_210 ;
V_204 = V_1 -> V_42 . V_211 << V_212 ;
if ( V_74 -> V_39 == 0 || V_1 -> V_42 . V_213 == NULL ||
V_95 >= V_204 ) {
V_95 = 0 ;
V_204 = 0 ;
}
if ( V_198 -> type == V_190 && V_95 & 3 )
return - V_93 ;
V_67 = (struct V_202 T_1 * ) F_12 ( V_74 -> V_214 ) ;
if ( ! F_105 ( V_215 , V_67 , V_74 -> V_40 ) )
return - V_47 ;
V_153 = ( void T_1 * ) V_67 + V_74 -> V_40 ;
V_43 = 0 ;
while ( V_67 < V_153 ) {
if ( F_106 ( V_206 , & V_67 -> V_206 ) )
return - V_47 ;
V_209 . V_208 . V_216 = F_107 ( V_206 ) ;
V_209 . V_208 . V_176 = F_108 ( V_206 ) ;
V_209 . V_208 . V_217 = F_109 ( V_206 ) ;
V_209 . V_208 . V_218 = F_110 ( V_206 ) ;
V_209 . V_208 . V_219 = F_111 ( V_206 ) ;
V_209 . V_208 . V_173 = F_112 ( V_206 ) ;
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
& V_67 -> V_174 [ V_205 / 4 ] ;
if ( V_203 > V_153 )
return - V_93 ;
if ( F_113
( V_209 . V_208 . V_174 , V_67 -> V_174 , V_205 ) )
return - V_47 ;
if ( V_209 . V_208 . V_217 && V_198 -> type == V_186 &&
V_209 . V_208 . V_173 + V_209 . V_208 . V_216 > 0 )
return - V_93 ;
if ( V_95 + V_209 . V_208 . V_216 > V_204 )
return - V_93 ;
if ( F_114 ( V_198 , & V_209 . V_208 ,
& V_1 -> V_42 , V_95 ) )
break;
V_67 = V_203 ;
V_95 += V_209 . V_208 . V_216 ;
V_43 ++ ;
}
F_115 ( V_198 ) ;
V_74 -> V_40 -= F_13 ( V_67 ) - V_74 -> V_214 ;
V_74 -> V_214 = F_13 ( V_67 ) ;
V_74 -> V_39 = V_1 -> V_210 + V_95 ;
return V_43 ;
}
static int F_116 ( struct V_1 * V_1 , union V_71 * V_72 )
{
struct V_220 * V_74 = & V_72 -> V_221 ;
F_97 (
V_222 != V_223 ||
V_224 != V_225 ||
V_226 != V_227 ||
V_228 != V_229 ||
V_230 != V_231 ) ;
if ( V_1 -> V_194 == NULL || V_74 -> V_90 != 0 )
return - V_93 ;
if ( V_1 -> V_194 -> type == V_188 &&
( V_74 -> V_232 == 0 || V_74 -> V_232 > 15 || V_74 -> V_233 > 15 ) )
return - V_93 ;
return F_117 ( V_1 -> V_194 ,
V_74 -> V_172 , V_74 -> V_233 , V_74 -> V_232 ) ;
}
static int F_118 ( struct V_1 * V_1 , union V_71 * V_72 )
{
struct V_234 * V_74 = & V_72 -> V_235 ;
if ( V_1 -> V_194 == NULL || V_74 -> V_90 != 0 )
return - V_93 ;
return F_119 ( V_1 -> V_194 ) ;
}
static int F_120 ( struct V_1 * V_1 , union V_71 * V_72 )
{
struct V_236 * V_74 = & V_72 -> V_237 ;
struct V_51 * V_52 = V_1 -> V_3 -> V_52 ;
struct V_238 V_239 = { 0 , 0 } ;
T_7 V_240 ;
int V_46 = 0 ;
F_121 () ;
V_240 = V_52 -> V_241 -> V_242 ( V_52 , V_243 ) ;
switch ( V_74 -> V_244 ) {
case V_245 : F_122 ( & V_239 ) ; break;
case V_246 : F_123 ( & V_239 ) ; break;
case V_247 : F_124 ( & V_239 ) ; break;
default:
V_46 = - V_93 ;
}
F_125 () ;
V_74 -> V_248 = V_239 . V_248 ;
V_74 -> V_249 = V_239 . V_249 ;
V_74 -> V_250 = V_240 ;
return V_46 ;
}
static int F_126 ( struct V_1 * V_1 , union V_71 * V_72 )
{
struct V_251 * V_74 = & V_72 -> V_252 ;
struct V_236 V_253 ;
V_253 . V_244 = V_245 ;
F_120 ( V_1 , (union V_71 * ) & V_253 ) ;
V_74 -> V_254 = V_253 . V_248 * V_255 + V_253 . V_249 / V_256 ;
V_74 -> V_250 = V_253 . V_250 ;
return 0 ;
}
static void F_127 ( struct V_257 * V_8 )
{
struct V_258 * V_69 ;
struct V_4 * V_5 =
F_4 ( V_8 , struct V_4 , V_8 . V_8 ) ;
struct V_1 * V_1 = V_5 -> V_1 ;
int V_56 , V_192 , V_259 , V_260 ;
bool V_217 , free , V_261 ;
F_34 ( & V_1 -> V_22 ) ;
V_56 = V_1 -> V_3 -> V_56 ;
V_260 = V_5 -> V_260 ;
if ( V_260 == V_262 &&
F_128 ( F_129 () ,
V_1 -> V_3 -> V_52 -> V_263 + V_264 ) ) {
F_9 ( V_5 , F_130 ( V_264 , 3 ) ) ;
V_217 = true ;
} else {
V_217 = V_260 == V_265 &&
V_5 -> V_56 == V_56 ;
}
free = V_260 == V_266 ||
V_260 == V_267 ||
V_260 == V_268 ;
V_5 -> V_56 = V_56 ;
F_37 ( & V_1 -> V_22 ) ;
if ( V_217 )
goto V_48;
V_259 = V_5 -> V_259 ;
F_131 ( V_1 -> V_3 -> V_52 , V_56 ,
V_5 -> V_199 , & V_192 , & V_259 ,
V_260 == V_262 ||
V_260 == V_265 ||
V_260 == V_267 ) ;
if ( V_192 == - V_91 &&
( V_260 == V_262 || V_260 == V_265 ) )
goto V_48;
V_261 = V_192 >= 0 || V_259 > 0 ;
F_34 ( & V_1 -> V_22 ) ;
if ( V_5 -> V_260 == V_262 )
V_5 -> V_260 = V_265 ;
if ( V_5 -> V_260 == V_265 && ! V_261 &&
! V_1 -> V_41 &&
F_60 ( & V_1 -> V_23 , V_5 -> V_10 . V_90 ) ) {
F_61 ( & V_1 -> V_23 , V_5 -> V_10 . V_90 ) ;
F_7 ( V_1 ) ;
free = true ;
}
F_37 ( & V_1 -> V_22 ) ;
if ( V_260 == V_262 && V_192 >= 0 )
V_5 -> V_199 = 1ULL << V_192 ;
if ( V_260 == V_265 && V_261 )
goto V_48;
if ( V_260 == V_262 || V_260 == V_267 ) {
V_69 = V_5 -> V_269 ;
V_5 -> V_269 = NULL ;
} else {
V_69 = V_5 -> V_270 ;
V_5 -> V_270 = NULL ;
}
V_69 -> V_4 . V_90 = V_5 -> V_10 . V_90 ;
V_69 -> V_4 . V_192 = V_192 ;
V_69 -> V_4 . V_259 = V_259 ;
F_27 ( V_1 , & V_69 -> V_32 ,
& V_69 -> V_4 , sizeof( V_69 -> V_4 ) , NULL , 0 ) ;
if ( free ) {
F_132 ( & V_5 -> V_8 ) ;
F_6 ( V_5 -> V_269 ) ;
F_6 ( V_5 -> V_270 ) ;
F_6 ( V_5 ) ;
}
V_48:
F_7 ( V_1 ) ;
}
static void V_12 ( struct V_1 * V_1 ,
struct V_9 * V_10 )
{
struct V_4 * V_5 =
F_4 ( V_10 , struct V_4 , V_10 ) ;
F_34 ( & V_1 -> V_22 ) ;
V_5 -> V_260 = V_266 ;
F_9 ( V_5 , 0 ) ;
F_37 ( & V_1 -> V_22 ) ;
}
static int F_133 ( struct V_1 * V_1 ,
struct V_271 * V_104 , int V_260 )
{
struct V_258 * V_272 , * V_273 ;
struct V_4 * V_5 ;
int V_46 ;
if ( ( V_104 -> V_199 == 0 && V_104 -> V_259 == 0 ) ||
V_104 -> V_259 > V_274 ||
V_104 -> V_259 < 0 )
return - V_93 ;
V_5 = F_68 ( sizeof( * V_5 ) , V_20 ) ;
V_272 = F_68 ( sizeof( * V_272 ) , V_20 ) ;
V_273 = F_68 ( sizeof( * V_273 ) , V_20 ) ;
if ( V_5 == NULL || V_272 == NULL || V_273 == NULL ) {
V_46 = - V_21 ;
goto V_275;
}
F_134 ( & V_5 -> V_8 , F_127 ) ;
V_5 -> V_1 = V_1 ;
V_5 -> V_260 = V_260 ;
V_5 -> V_56 = - 1 ;
V_5 -> V_199 = V_104 -> V_199 ;
V_5 -> V_259 = V_104 -> V_259 ;
V_5 -> V_269 = V_272 ;
V_5 -> V_270 = V_273 ;
V_272 -> V_4 . V_53 = V_104 -> V_53 ;
V_272 -> V_4 . type = V_276 ;
V_273 -> V_4 . V_53 = V_104 -> V_53 ;
V_273 -> V_4 . type = V_277 ;
if ( V_260 == V_262 ) {
V_5 -> V_10 . V_11 = V_12 ;
V_46 = F_56 ( V_1 , & V_5 -> V_10 , V_20 ) ;
if ( V_46 < 0 )
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
return V_46 ;
}
static int F_135 ( struct V_1 * V_1 ,
union V_71 * V_72 )
{
return F_133 ( V_1 ,
& V_72 -> V_278 , V_262 ) ;
}
static int F_136 ( struct V_1 * V_1 ,
union V_71 * V_72 )
{
return F_59 ( V_1 ,
V_72 -> V_156 . V_90 , V_12 , NULL ) ;
}
static int F_137 ( struct V_1 * V_1 ,
union V_71 * V_72 )
{
return F_133 ( V_1 ,
& V_72 -> V_278 , V_267 ) ;
}
static int F_138 ( struct V_1 * V_1 ,
union V_71 * V_72 )
{
return F_133 ( V_1 ,
& V_72 -> V_278 , V_268 ) ;
}
static int F_139 ( struct V_1 * V_1 , union V_71 * V_72 )
{
return V_1 -> V_3 -> V_124 ;
}
static int F_140 ( struct V_1 * V_1 ,
union V_71 * V_72 )
{
struct V_103 * V_74 = & V_72 -> V_113 ;
switch ( V_74 -> V_107 ) {
case V_110 :
case V_114 :
break;
default:
return - V_93 ;
}
if ( V_74 -> V_49 < V_279 + V_280 )
return - V_281 ;
return F_67 ( V_1 , V_74 , V_282 | 0x3f , V_283 ) ;
}
static int F_141 ( struct V_1 * V_1 , union V_71 * V_72 )
{
struct V_284 * V_74 = & V_72 -> V_285 ;
struct V_103 V_104 ;
int V_286 ;
if ( V_74 -> V_106 > V_1 -> V_3 -> V_52 -> V_287 ||
V_74 -> V_96 > 1024 << V_74 -> V_106 )
return - V_109 ;
if ( V_74 -> V_218 > 3 || V_74 -> V_192 > 63 || V_74 -> V_219 > 15 )
return - V_93 ;
V_286 = F_142 ( V_74 -> V_218 , V_74 -> V_192 , V_74 -> V_219 ) ;
V_104 . V_107 = V_108 ;
V_104 . V_96 = V_74 -> V_96 ;
V_104 . V_53 = V_74 -> V_53 ;
V_104 . V_39 = V_74 -> V_39 ;
V_104 . V_56 = V_74 -> V_56 ;
return F_67 ( V_1 , & V_104 , V_286 , V_74 -> V_106 ) ;
}
static void F_143 ( struct V_288 * V_208 ,
struct V_51 * V_52 , int V_289 )
{
struct V_290 * V_69 =
F_4 ( V_208 , struct V_290 , V_67 ) ;
switch ( V_289 ) {
case V_291 : V_69 -> V_292 . V_94 = V_101 ; break;
case V_293 : V_69 -> V_292 . V_94 = V_101 ; break;
case V_294 :
case V_295 :
case V_296 : V_69 -> V_292 . V_94 = V_297 ; break;
case V_298 : V_69 -> V_292 . V_94 = V_299 ; break;
case V_300 : V_69 -> V_292 . V_94 = V_301 ; break;
default: V_69 -> V_292 . V_94 = V_289 ; break;
}
V_69 -> V_292 . V_39 [ 0 ] = V_208 -> V_302 ;
F_27 ( V_69 -> V_1 , & V_69 -> V_32 , & V_69 -> V_292 ,
sizeof( V_69 -> V_292 ) + V_69 -> V_292 . V_96 , NULL , 0 ) ;
F_7 ( V_69 -> V_1 ) ;
}
static int F_144 ( struct V_1 * V_1 , union V_71 * V_72 )
{
struct V_303 * V_74 = & V_72 -> V_304 ;
struct V_51 * V_52 = V_1 -> V_3 -> V_52 ;
struct V_290 * V_69 ;
if ( ! V_1 -> V_3 -> V_165 )
return - V_166 ;
V_69 = F_17 ( sizeof( * V_69 ) + 4 , V_20 ) ;
if ( V_69 == NULL )
return - V_21 ;
F_1 ( V_1 ) ;
V_69 -> V_1 = V_1 ;
V_69 -> V_67 . V_106 = V_283 ;
V_69 -> V_67 . V_56 = V_74 -> V_56 ;
V_69 -> V_67 . V_174 [ 0 ] = V_305 << 4 ;
V_69 -> V_67 . V_174 [ 1 ] = V_74 -> V_39 [ 0 ] ;
V_69 -> V_67 . V_174 [ 2 ] = V_74 -> V_39 [ 1 ] ;
V_69 -> V_67 . V_173 = 12 ;
V_69 -> V_67 . F_44 = F_143 ;
V_69 -> V_292 . V_53 = V_74 -> V_53 ;
V_69 -> V_292 . type = V_306 ;
if ( F_145 ( V_74 -> V_39 ) )
V_69 -> V_292 . V_96 = 4 ;
V_52 -> V_241 -> V_113 ( V_52 , & V_69 -> V_67 ) ;
return 0 ;
}
static int F_146 ( struct V_1 * V_1 , union V_71 * V_72 )
{
struct V_307 * V_74 = & V_72 -> V_308 ;
struct V_51 * V_52 = V_1 -> V_3 -> V_52 ;
if ( ! V_1 -> V_3 -> V_165 )
return - V_166 ;
F_34 ( & V_52 -> V_22 ) ;
F_147 ( & V_1 -> V_27 , & V_52 -> V_309 ) ;
V_1 -> V_310 = V_74 -> V_53 ;
F_37 ( & V_52 -> V_22 ) ;
return 0 ;
}
void F_148 ( struct V_51 * V_52 , struct V_288 * V_67 )
{
struct V_1 * V_1 ;
struct V_311 * V_69 ;
unsigned long V_37 ;
F_28 ( & V_52 -> V_22 , V_37 ) ;
F_45 (client, &card->phy_receiver_list, phy_receiver_link) {
V_69 = F_68 ( sizeof( * V_69 ) + 8 , V_136 ) ;
if ( V_69 == NULL ) {
F_48 ( L_1 ) ;
break;
}
V_69 -> V_292 . V_53 = V_1 -> V_310 ;
V_69 -> V_292 . type = V_312 ;
V_69 -> V_292 . V_94 = V_101 ;
V_69 -> V_292 . V_96 = 8 ;
V_69 -> V_292 . V_39 [ 0 ] = V_67 -> V_174 [ 1 ] ;
V_69 -> V_292 . V_39 [ 1 ] = V_67 -> V_174 [ 2 ] ;
F_27 ( V_1 , & V_69 -> V_32 ,
& V_69 -> V_292 , sizeof( V_69 -> V_292 ) + 8 , NULL , 0 ) ;
}
F_29 ( & V_52 -> V_22 , V_37 ) ;
}
static int F_149 ( struct V_1 * V_1 ,
unsigned int V_313 , void T_1 * V_72 )
{
union V_71 V_42 ;
int V_46 ;
if ( F_16 ( V_1 -> V_3 ) )
return - V_19 ;
if ( F_150 ( V_313 ) != '#' ||
F_151 ( V_313 ) >= F_38 ( V_314 ) ||
F_152 ( V_313 ) > sizeof( V_42 ) )
return - V_93 ;
if ( F_153 ( V_313 ) == V_315 )
memset ( & V_42 , 0 , F_152 ( V_313 ) ) ;
if ( F_153 ( V_313 ) & V_316 )
if ( F_69 ( & V_42 , V_72 , F_152 ( V_313 ) ) )
return - V_47 ;
V_46 = V_314 [ F_151 ( V_313 ) ] ( V_1 , & V_42 ) ;
if ( V_46 < 0 )
return V_46 ;
if ( F_153 ( V_313 ) & V_315 )
if ( F_40 ( V_72 , & V_42 , F_152 ( V_313 ) ) )
return - V_47 ;
return V_46 ;
}
static long F_154 ( struct V_16 * V_16 ,
unsigned int V_313 , unsigned long V_72 )
{
return F_149 ( V_16 -> V_28 , V_313 , ( void T_1 * ) V_72 ) ;
}
static long F_155 ( struct V_16 * V_16 ,
unsigned int V_313 , unsigned long V_72 )
{
return F_149 ( V_16 -> V_28 , V_313 , F_156 ( V_72 ) ) ;
}
static int F_157 ( struct V_16 * V_16 , struct V_317 * V_318 )
{
struct V_1 * V_1 = V_16 -> V_28 ;
enum V_319 V_320 ;
unsigned long V_40 ;
int V_211 , V_46 ;
if ( F_16 ( V_1 -> V_3 ) )
return - V_19 ;
if ( V_1 -> V_42 . V_213 != NULL )
return - V_195 ;
if ( ! ( V_318 -> V_321 & V_322 ) )
return - V_93 ;
if ( V_318 -> V_210 & ~ V_323 )
return - V_93 ;
V_1 -> V_210 = V_318 -> V_210 ;
V_40 = V_318 -> V_324 - V_318 -> V_210 ;
V_211 = V_40 >> V_212 ;
if ( V_40 & ~ V_323 )
return - V_93 ;
if ( V_318 -> V_321 & V_325 )
V_320 = V_326 ;
else
V_320 = V_327 ;
V_46 = F_158 ( & V_1 -> V_42 , V_1 -> V_3 -> V_52 ,
V_211 , V_320 ) ;
if ( V_46 < 0 )
return V_46 ;
V_46 = F_159 ( & V_1 -> V_42 , V_318 ) ;
if ( V_46 < 0 )
F_160 ( & V_1 -> V_42 , V_1 -> V_3 -> V_52 ) ;
return V_46 ;
}
static int F_161 ( int V_66 , void * V_67 , void * V_39 )
{
struct V_9 * V_10 = V_67 ;
return V_10 -> V_11 == F_62 ;
}
static int F_162 ( struct V_1 * V_1 )
{
int V_46 ;
F_34 ( & V_1 -> V_22 ) ;
V_46 = F_49 ( & V_1 -> V_23 ,
F_161 , NULL ) ;
F_37 ( & V_1 -> V_22 ) ;
return V_46 ;
}
static int F_163 ( int V_66 , void * V_67 , void * V_39 )
{
struct V_9 * V_10 = V_67 ;
struct V_1 * V_1 = V_39 ;
V_10 -> V_11 ( V_1 , V_10 ) ;
F_7 ( V_1 ) ;
return 0 ;
}
static int F_164 ( struct V_15 * V_15 , struct V_16 * V_16 )
{
struct V_1 * V_1 = V_16 -> V_28 ;
struct V_32 * V_32 , * V_328 ;
F_34 ( & V_1 -> V_3 -> V_52 -> V_22 ) ;
F_36 ( & V_1 -> V_27 ) ;
F_37 ( & V_1 -> V_3 -> V_52 -> V_22 ) ;
F_23 ( & V_1 -> V_3 -> V_29 ) ;
F_36 ( & V_1 -> V_30 ) ;
F_25 ( & V_1 -> V_3 -> V_29 ) ;
if ( V_1 -> V_194 )
F_101 ( V_1 -> V_194 ) ;
if ( V_1 -> V_42 . V_213 )
F_160 ( & V_1 -> V_42 , V_1 -> V_3 -> V_52 ) ;
F_34 ( & V_1 -> V_22 ) ;
V_1 -> V_41 = true ;
F_37 ( & V_1 -> V_22 ) ;
F_165 ( V_1 -> V_26 , ! F_162 ( V_1 ) ) ;
F_49 ( & V_1 -> V_23 , F_163 , V_1 ) ;
F_166 ( & V_1 -> V_23 ) ;
F_167 ( & V_1 -> V_23 ) ;
F_168 (event, next_event, &client->event_list, link)
F_6 ( V_32 ) ;
F_7 ( V_1 ) ;
return 0 ;
}
static unsigned int F_169 ( struct V_16 * V_16 , T_12 * V_329 )
{
struct V_1 * V_1 = V_16 -> V_28 ;
unsigned int V_330 = 0 ;
F_170 ( V_16 , & V_1 -> V_25 , V_329 ) ;
if ( F_16 ( V_1 -> V_3 ) )
V_330 |= V_331 | V_332 ;
if ( ! F_33 ( & V_1 -> V_24 ) )
V_330 |= V_333 | V_334 ;
return V_330 ;
}
