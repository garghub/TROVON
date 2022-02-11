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
F_51 ( V_1 -> V_3 -> V_50 , L_1 ) ;
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
V_44 = F_41 ( F_12 ( V_73 -> V_75 ) , & V_75 , 36 ) ;
}
if ( V_44 == 0 && F_34 ( & V_1 -> V_28 ) )
F_29 ( & V_1 -> V_28 , & V_1 -> V_3 -> V_86 ) ;
F_48 ( & V_1 -> V_3 -> V_64 ) ;
return V_44 ? - V_45 : 0 ;
}
static int F_59 ( struct V_1 * V_1 ,
struct V_9 * V_10 , T_6 V_87 )
{
bool V_88 = V_87 & V_89 ;
unsigned long V_35 ;
int V_44 ;
if ( V_88 )
F_60 ( V_87 ) ;
F_28 ( & V_1 -> V_22 , V_35 ) ;
if ( V_1 -> V_39 )
V_44 = - V_90 ;
else
V_44 = F_61 ( & V_1 -> V_23 , V_10 , 0 , 0 ,
V_91 ) ;
if ( V_44 >= 0 ) {
V_10 -> V_92 = V_44 ;
F_1 ( V_1 ) ;
F_11 ( V_10 ) ;
}
F_30 ( & V_1 -> V_22 , V_35 ) ;
if ( V_88 )
F_62 () ;
return V_44 < 0 ? V_44 : 0 ;
}
static int F_63 ( struct V_1 * V_1 , T_7 V_92 ,
T_8 V_11 ,
struct V_9 * * V_93 )
{
struct V_9 * V_10 ;
F_35 ( & V_1 -> V_22 ) ;
if ( V_1 -> V_39 )
V_10 = NULL ;
else
V_10 = F_64 ( & V_1 -> V_23 , V_92 ) ;
if ( V_10 && V_10 -> V_11 == V_11 )
F_65 ( & V_1 -> V_23 , V_92 ) ;
F_38 ( & V_1 -> V_22 ) ;
if ( ! ( V_10 && V_10 -> V_11 == V_11 ) )
return - V_94 ;
if ( V_93 )
* V_93 = V_10 ;
else
V_10 -> V_11 ( V_1 , V_10 ) ;
F_7 ( V_1 ) ;
return 0 ;
}
static void F_66 ( struct V_1 * V_1 ,
struct V_9 * V_10 )
{
}
static void F_67 ( struct V_49 * V_50 , int V_95 ,
void * V_96 , T_3 V_97 , void * V_37 )
{
struct V_98 * V_68 = V_37 ;
struct V_99 * V_100 = & V_68 -> V_101 ;
struct V_1 * V_1 = V_68 -> V_1 ;
unsigned long V_35 ;
if ( V_97 < V_100 -> V_97 )
V_100 -> V_97 = V_97 ;
if ( V_95 == V_102 )
memcpy ( V_100 -> V_37 , V_96 , V_100 -> V_97 ) ;
F_28 ( & V_1 -> V_22 , V_35 ) ;
F_65 ( & V_1 -> V_23 , V_68 -> V_5 . V_10 . V_92 ) ;
if ( V_1 -> V_39 )
F_68 ( & V_1 -> V_26 ) ;
F_30 ( & V_1 -> V_22 , V_35 ) ;
V_100 -> type = V_103 ;
V_100 -> V_95 = V_95 ;
if ( V_100 -> V_97 <= sizeof( * V_100 ) - F_69 ( F_70 ( * V_100 ) , V_37 ) )
F_27 ( V_1 , & V_68 -> V_30 , V_100 , sizeof( * V_100 ) ,
V_100 -> V_37 , V_100 -> V_97 ) ;
else
F_27 ( V_1 , & V_68 -> V_30 , V_100 , sizeof( * V_100 ) + V_100 -> V_97 ,
NULL , 0 ) ;
F_7 ( V_1 ) ;
}
static int F_71 ( struct V_1 * V_1 ,
struct V_104 * V_105 ,
int V_106 , int V_107 )
{
struct V_98 * V_68 ;
int V_44 ;
if ( V_105 -> V_108 != V_109 &&
( V_105 -> V_97 > 4096 || V_105 -> V_97 > 512 << V_107 ) )
return - V_110 ;
if ( V_105 -> V_108 == V_111 &&
V_105 -> V_97 < 4 )
return - V_94 ;
V_68 = F_72 ( sizeof( * V_68 ) + V_105 -> V_97 , V_20 ) ;
if ( V_68 == NULL )
return - V_21 ;
V_68 -> V_1 = V_1 ;
V_68 -> V_101 . V_97 = V_105 -> V_97 ;
V_68 -> V_101 . V_51 = V_105 -> V_51 ;
if ( V_105 -> V_37 &&
F_73 ( V_68 -> V_101 . V_37 ,
F_12 ( V_105 -> V_37 ) , V_105 -> V_97 ) ) {
V_44 = - V_45 ;
goto V_112;
}
V_68 -> V_5 . V_10 . V_11 = F_66 ;
V_44 = F_59 ( V_1 , & V_68 -> V_5 . V_10 , V_20 ) ;
if ( V_44 < 0 )
goto V_112;
F_74 ( V_1 -> V_3 -> V_50 , & V_68 -> V_5 . V_113 ,
V_105 -> V_108 , V_106 , V_105 -> V_54 ,
V_107 , V_105 -> V_47 , V_68 -> V_101 . V_37 ,
V_105 -> V_97 , F_67 , V_68 ) ;
return 0 ;
V_112:
F_6 ( V_68 ) ;
return V_44 ;
}
static int F_75 ( struct V_1 * V_1 , union V_70 * V_71 )
{
switch ( V_71 -> V_114 . V_108 ) {
case V_111 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
break;
default:
return - V_94 ;
}
return F_71 ( V_1 , & V_71 -> V_114 , V_1 -> V_3 -> V_55 ,
V_1 -> V_3 -> V_125 ) ;
}
static inline bool F_76 ( struct V_126 * V_105 )
{
return V_105 == NULL ;
}
static void F_77 ( struct V_1 * V_1 ,
struct V_9 * V_10 )
{
struct V_127 * V_5 = F_4 ( V_10 ,
struct V_127 , V_10 ) ;
if ( F_76 ( V_5 -> V_105 ) )
F_6 ( V_5 -> V_37 ) ;
else
F_78 ( V_5 -> V_50 , V_5 -> V_105 , V_128 ) ;
F_79 ( V_5 -> V_50 ) ;
F_6 ( V_5 ) ;
}
static void F_80 ( struct V_49 * V_50 , struct V_126 * V_105 ,
int V_108 , int V_129 , int V_130 ,
int V_54 , unsigned long long V_47 ,
void * V_96 , T_3 V_97 , void * V_131 )
{
struct V_132 * V_133 = V_131 ;
struct V_127 * V_5 ;
struct V_134 * V_68 ;
T_3 V_135 ;
void * V_136 = NULL ;
int V_44 ;
F_81 ( V_50 ) ;
V_5 = F_72 ( sizeof( * V_5 ) , V_137 ) ;
V_68 = F_72 ( sizeof( * V_68 ) , V_137 ) ;
if ( V_5 == NULL || V_68 == NULL ) {
F_51 ( V_50 , L_1 ) ;
goto V_112;
}
V_5 -> V_50 = V_50 ;
V_5 -> V_105 = V_105 ;
V_5 -> V_37 = V_96 ;
V_5 -> V_97 = V_97 ;
if ( F_76 ( V_105 ) ) {
V_136 = F_82 ( V_96 , V_97 , V_137 ) ;
if ( V_136 == NULL )
goto V_112;
V_5 -> V_37 = V_136 ;
}
V_5 -> V_10 . V_11 = F_77 ;
V_44 = F_59 ( V_133 -> V_1 , & V_5 -> V_10 , V_137 ) ;
if ( V_44 < 0 )
goto V_112;
if ( V_133 -> V_1 -> V_76 < V_138 ) {
struct V_139 * V_140 = & V_68 -> V_140 . V_105 ;
if ( V_108 & 0x10 )
V_108 = V_141 ;
V_140 -> type = V_142 ;
V_140 -> V_108 = V_108 ;
V_140 -> V_47 = V_47 ;
V_140 -> V_97 = V_97 ;
V_140 -> V_92 = V_5 -> V_10 . V_92 ;
V_140 -> V_51 = V_133 -> V_51 ;
V_135 = sizeof( * V_140 ) ;
} else {
struct V_143 * V_140 = & V_68 -> V_140 . V_144 ;
V_140 -> type = V_145 ;
V_140 -> V_108 = V_108 ;
V_140 -> V_47 = V_47 ;
V_140 -> V_146 = V_130 ;
V_140 -> V_147 = V_129 ;
V_140 -> V_50 = V_50 -> V_78 ;
V_140 -> V_54 = V_54 ;
V_140 -> V_97 = V_97 ;
V_140 -> V_92 = V_5 -> V_10 . V_92 ;
V_140 -> V_51 = V_133 -> V_51 ;
V_135 = sizeof( * V_140 ) ;
}
F_27 ( V_133 -> V_1 , & V_68 -> V_30 ,
& V_68 -> V_140 , V_135 , V_5 -> V_37 , V_97 ) ;
return;
V_112:
F_6 ( V_5 ) ;
F_6 ( V_68 ) ;
F_6 ( V_136 ) ;
if ( ! F_76 ( V_105 ) )
F_78 ( V_50 , V_105 , V_128 ) ;
F_79 ( V_50 ) ;
}
static void F_83 ( struct V_1 * V_1 ,
struct V_9 * V_10 )
{
struct V_132 * V_5 =
F_4 ( V_10 , struct V_132 , V_10 ) ;
F_84 ( & V_5 -> V_133 ) ;
F_6 ( V_5 ) ;
}
static int F_85 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_148 * V_73 = & V_71 -> V_149 ;
struct V_132 * V_5 ;
struct V_150 V_151 ;
int V_44 ;
V_5 = F_72 ( sizeof( * V_5 ) , V_20 ) ;
if ( V_5 == NULL )
return - V_21 ;
V_151 . V_152 = V_73 -> V_47 ;
if ( V_1 -> V_76 < V_153 )
V_151 . V_154 = V_73 -> V_47 + V_73 -> V_97 ;
else
V_151 . V_154 = V_73 -> V_155 ;
V_5 -> V_133 . V_97 = V_73 -> V_97 ;
V_5 -> V_133 . V_156 = F_80 ;
V_5 -> V_133 . V_131 = V_5 ;
V_5 -> V_51 = V_73 -> V_51 ;
V_5 -> V_1 = V_1 ;
V_44 = F_86 ( & V_5 -> V_133 , & V_151 ) ;
if ( V_44 < 0 ) {
F_6 ( V_5 ) ;
return V_44 ;
}
V_73 -> V_47 = V_5 -> V_133 . V_47 ;
V_5 -> V_10 . V_11 = F_83 ;
V_44 = F_59 ( V_1 , & V_5 -> V_10 , V_20 ) ;
if ( V_44 < 0 ) {
F_83 ( V_1 , & V_5 -> V_10 ) ;
return V_44 ;
}
V_73 -> V_92 = V_5 -> V_10 . V_92 ;
return 0 ;
}
static int F_87 ( struct V_1 * V_1 , union V_70 * V_71 )
{
return F_63 ( V_1 , V_71 -> V_157 . V_92 ,
F_83 , NULL ) ;
}
static int F_88 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_158 * V_73 = & V_71 -> V_159 ;
struct V_9 * V_10 ;
struct V_127 * V_5 ;
int V_44 = 0 ;
if ( F_63 ( V_1 , V_73 -> V_92 ,
F_77 , & V_10 ) < 0 )
return - V_94 ;
V_5 = F_4 ( V_10 , struct V_127 ,
V_10 ) ;
if ( F_76 ( V_5 -> V_105 ) )
goto V_46;
if ( V_73 -> V_97 != F_89 ( V_5 -> V_105 ) ) {
V_44 = - V_94 ;
F_6 ( V_5 -> V_105 ) ;
goto V_46;
}
if ( F_73 ( V_5 -> V_37 , F_12 ( V_73 -> V_37 ) , V_73 -> V_97 ) ) {
V_44 = - V_45 ;
F_6 ( V_5 -> V_105 ) ;
goto V_46;
}
F_78 ( V_5 -> V_50 , V_5 -> V_105 , V_73 -> V_95 ) ;
V_46:
F_79 ( V_5 -> V_50 ) ;
F_6 ( V_5 ) ;
return V_44 ;
}
static int F_90 ( struct V_1 * V_1 , union V_70 * V_71 )
{
F_91 ( V_1 -> V_3 -> V_50 , true ,
V_71 -> V_160 . type == V_161 ) ;
return 0 ;
}
static void F_92 ( struct V_1 * V_1 ,
struct V_9 * V_10 )
{
struct V_162 * V_5 =
F_4 ( V_10 , struct V_162 , V_10 ) ;
F_93 ( & V_5 -> V_163 ) ;
F_6 ( V_5 ) ;
}
static int F_94 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_164 * V_73 = & V_71 -> V_165 ;
struct V_162 * V_5 ;
int V_44 ;
if ( ! V_1 -> V_3 -> V_166 )
return - V_167 ;
if ( V_73 -> V_97 > 256 )
return - V_94 ;
V_5 = F_72 ( sizeof( * V_5 ) + V_73 -> V_97 * 4 , V_20 ) ;
if ( V_5 == NULL )
return - V_21 ;
if ( F_73 ( V_5 -> V_37 , F_12 ( V_73 -> V_37 ) , V_73 -> V_97 * 4 ) ) {
V_44 = - V_45 ;
goto V_112;
}
V_5 -> V_163 . V_97 = V_73 -> V_97 ;
V_5 -> V_163 . V_168 = V_73 -> V_168 ;
V_5 -> V_163 . V_169 = V_73 -> V_169 ;
V_5 -> V_163 . V_37 = V_5 -> V_37 ;
V_44 = F_95 ( & V_5 -> V_163 ) ;
if ( V_44 < 0 )
goto V_112;
V_5 -> V_10 . V_11 = F_92 ;
V_44 = F_59 ( V_1 , & V_5 -> V_10 , V_20 ) ;
if ( V_44 < 0 ) {
F_93 ( & V_5 -> V_163 ) ;
goto V_112;
}
V_73 -> V_92 = V_5 -> V_10 . V_92 ;
return 0 ;
V_112:
F_6 ( V_5 ) ;
return V_44 ;
}
static int F_96 ( struct V_1 * V_1 , union V_70 * V_71 )
{
return F_63 ( V_1 , V_71 -> V_170 . V_92 ,
F_92 , NULL ) ;
}
static void F_97 ( struct V_171 * V_172 , T_7 V_173 ,
T_3 V_174 , void * V_175 , void * V_37 )
{
struct V_1 * V_1 = V_37 ;
struct V_176 * V_68 ;
V_68 = F_72 ( sizeof( * V_68 ) + V_174 , V_137 ) ;
if ( V_68 == NULL ) {
F_51 ( V_172 -> V_50 , L_1 ) ;
return;
}
V_68 -> V_177 . type = V_178 ;
V_68 -> V_177 . V_51 = V_1 -> V_179 ;
V_68 -> V_177 . V_173 = V_173 ;
V_68 -> V_177 . V_174 = V_174 ;
memcpy ( V_68 -> V_177 . V_175 , V_175 , V_174 ) ;
F_27 ( V_1 , & V_68 -> V_30 , & V_68 -> V_177 ,
sizeof( V_68 -> V_177 ) + V_174 , NULL , 0 ) ;
}
static void F_98 ( struct V_171 * V_172 ,
T_9 V_180 , void * V_37 )
{
struct V_1 * V_1 = V_37 ;
struct V_181 * V_68 ;
V_68 = F_72 ( sizeof( * V_68 ) , V_137 ) ;
if ( V_68 == NULL ) {
F_51 ( V_172 -> V_50 , L_1 ) ;
return;
}
V_68 -> V_177 . type = V_182 ;
V_68 -> V_177 . V_51 = V_1 -> V_179 ;
V_68 -> V_177 . V_180 = F_99 ( & V_1 -> V_40 ,
V_180 ) ;
F_27 ( V_1 , & V_68 -> V_30 , & V_68 -> V_177 ,
sizeof( V_68 -> V_177 ) , NULL , 0 ) ;
}
static enum V_183 F_100 ( struct V_171 * V_172 )
{
if ( V_172 -> type == V_184 )
return V_185 ;
else
return V_186 ;
}
static int F_101 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_187 * V_73 = & V_71 -> V_188 ;
struct V_171 * V_172 ;
T_10 V_189 ;
int V_44 ;
F_102 ( V_190 != V_184 ||
V_191 != V_192 ||
V_193 !=
V_194 ) ;
switch ( V_73 -> type ) {
case V_184 :
if ( V_73 -> V_107 > V_195 || V_73 -> V_196 > 63 )
return - V_94 ;
V_189 = F_97 ;
break;
case V_192 :
if ( V_73 -> V_197 < 4 || ( V_73 -> V_197 & 3 ) ||
V_73 -> V_196 > 63 )
return - V_94 ;
V_189 = F_97 ;
break;
case V_194 :
V_189 = ( T_10 ) F_98 ;
break;
default:
return - V_94 ;
}
V_172 = F_103 ( V_1 -> V_3 -> V_50 , V_73 -> type ,
V_73 -> V_196 , V_73 -> V_107 , V_73 -> V_197 , V_189 , V_1 ) ;
if ( F_104 ( V_172 ) )
return F_105 ( V_172 ) ;
F_35 ( & V_1 -> V_22 ) ;
if ( V_1 -> V_198 != NULL ) {
F_38 ( & V_1 -> V_22 ) ;
F_106 ( V_172 ) ;
return - V_199 ;
}
if ( ! V_1 -> V_200 ) {
V_44 = F_107 ( & V_1 -> V_40 ,
V_1 -> V_3 -> V_50 ,
F_100 ( V_172 ) ) ;
if ( V_44 < 0 ) {
F_38 ( & V_1 -> V_22 ) ;
F_106 ( V_172 ) ;
return V_44 ;
}
V_1 -> V_200 = true ;
}
V_1 -> V_179 = V_73 -> V_51 ;
V_1 -> V_198 = V_172 ;
F_38 ( & V_1 -> V_22 ) ;
V_73 -> V_92 = 0 ;
return 0 ;
}
static int F_108 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_201 * V_73 = & V_71 -> V_202 ;
struct V_171 * V_203 = V_1 -> V_198 ;
if ( V_203 == NULL || V_73 -> V_92 != 0 )
return - V_94 ;
return F_109 ( V_203 , & V_73 -> V_204 ) ;
}
static int F_110 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_205 * V_73 = & V_71 -> V_206 ;
struct V_207 T_1 * V_66 , * V_154 , * V_208 ;
struct V_171 * V_203 = V_1 -> V_198 ;
unsigned long V_96 , V_209 , V_210 = 0 ;
T_7 V_211 ;
int V_41 ;
struct {
struct V_212 V_213 ;
T_11 V_175 [ 256 ] ;
} V_214 ;
if ( V_203 == NULL || V_73 -> V_92 != 0 )
return - V_94 ;
V_96 = ( unsigned long ) V_73 -> V_37 - V_1 -> V_215 ;
V_209 = V_1 -> V_40 . V_216 << V_217 ;
if ( V_73 -> V_37 == 0 || V_1 -> V_40 . V_218 == NULL ||
V_96 >= V_209 ) {
V_96 = 0 ;
V_209 = 0 ;
}
if ( V_203 -> type == V_194 && V_96 & 3 )
return - V_94 ;
V_66 = (struct V_207 T_1 * ) F_12 ( V_73 -> V_219 ) ;
if ( ! F_111 ( V_220 , V_66 , V_73 -> V_38 ) )
return - V_45 ;
V_154 = ( void T_1 * ) V_66 + V_73 -> V_38 ;
V_41 = 0 ;
while ( V_66 < V_154 ) {
if ( F_112 ( V_211 , & V_66 -> V_211 ) )
return - V_45 ;
V_214 . V_213 . V_221 = F_113 ( V_211 ) ;
V_214 . V_213 . V_177 = F_114 ( V_211 ) ;
V_214 . V_213 . V_222 = F_115 ( V_211 ) ;
V_214 . V_213 . V_223 = F_116 ( V_211 ) ;
V_214 . V_213 . V_224 = F_117 ( V_211 ) ;
V_214 . V_213 . V_174 = F_118 ( V_211 ) ;
switch ( V_203 -> type ) {
case V_184 :
if ( V_214 . V_213 . V_174 & 3 )
return - V_94 ;
V_210 = V_214 . V_213 . V_174 ;
break;
case V_192 :
if ( V_214 . V_213 . V_174 == 0 ||
V_214 . V_213 . V_174 % V_203 -> V_197 != 0 )
return - V_94 ;
break;
case V_194 :
if ( V_214 . V_213 . V_221 == 0 ||
V_214 . V_213 . V_221 & 3 )
return - V_94 ;
break;
}
V_208 = (struct V_207 T_1 * )
& V_66 -> V_175 [ V_210 / 4 ] ;
if ( V_208 > V_154 )
return - V_94 ;
if ( F_119
( V_214 . V_213 . V_175 , V_66 -> V_175 , V_210 ) )
return - V_45 ;
if ( V_214 . V_213 . V_222 && V_203 -> type == V_184 &&
V_214 . V_213 . V_174 + V_214 . V_213 . V_221 > 0 )
return - V_94 ;
if ( V_96 + V_214 . V_213 . V_221 > V_209 )
return - V_94 ;
if ( F_120 ( V_203 , & V_214 . V_213 ,
& V_1 -> V_40 , V_96 ) )
break;
V_66 = V_208 ;
V_96 += V_214 . V_213 . V_221 ;
V_41 ++ ;
}
F_121 ( V_203 ) ;
V_73 -> V_38 -= F_15 ( V_66 ) - V_73 -> V_219 ;
V_73 -> V_219 = F_15 ( V_66 ) ;
V_73 -> V_37 = V_1 -> V_215 + V_96 ;
return V_41 ;
}
static int F_122 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_225 * V_73 = & V_71 -> V_226 ;
F_102 (
V_227 != V_228 ||
V_229 != V_230 ||
V_231 != V_232 ||
V_233 != V_234 ||
V_235 != V_236 ) ;
if ( V_1 -> V_198 == NULL || V_73 -> V_92 != 0 )
return - V_94 ;
if ( V_1 -> V_198 -> type == V_192 &&
( V_73 -> V_237 == 0 || V_73 -> V_237 > 15 || V_73 -> V_238 > 15 ) )
return - V_94 ;
return F_123 ( V_1 -> V_198 ,
V_73 -> V_173 , V_73 -> V_238 , V_73 -> V_237 ) ;
}
static int F_124 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_239 * V_73 = & V_71 -> V_240 ;
if ( V_1 -> V_198 == NULL || V_73 -> V_92 != 0 )
return - V_94 ;
return F_125 ( V_1 -> V_198 ) ;
}
static int F_126 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_241 * V_73 = & V_71 -> V_242 ;
if ( V_1 -> V_198 == NULL || V_73 -> V_92 != 0 )
return - V_94 ;
return F_127 ( V_1 -> V_198 ) ;
}
static int F_128 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_243 * V_73 = & V_71 -> V_244 ;
struct V_49 * V_50 = V_1 -> V_3 -> V_50 ;
struct V_245 V_246 = { 0 , 0 } ;
T_7 V_247 ;
int V_44 = 0 ;
F_129 () ;
V_247 = V_50 -> V_248 -> V_249 ( V_50 , V_250 ) ;
switch ( V_73 -> V_251 ) {
case V_252 : F_130 ( & V_246 ) ; break;
case V_253 : F_131 ( & V_246 ) ; break;
case V_254 : F_132 ( & V_246 ) ; break;
default:
V_44 = - V_94 ;
}
F_133 () ;
V_73 -> V_255 = V_246 . V_255 ;
V_73 -> V_256 = V_246 . V_256 ;
V_73 -> V_257 = V_247 ;
return V_44 ;
}
static int F_134 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_258 * V_73 = & V_71 -> V_259 ;
struct V_243 V_260 ;
V_260 . V_251 = V_252 ;
F_128 ( V_1 , (union V_70 * ) & V_260 ) ;
V_73 -> V_261 = V_260 . V_255 * V_262 + V_260 . V_256 / V_263 ;
V_73 -> V_257 = V_260 . V_257 ;
return 0 ;
}
static void F_135 ( struct V_264 * V_8 )
{
struct V_265 * V_68 ;
struct V_4 * V_5 =
F_4 ( V_8 , struct V_4 , V_8 . V_8 ) ;
struct V_1 * V_1 = V_5 -> V_1 ;
int V_54 , V_196 , V_266 , V_267 ;
bool V_222 , free , V_268 ;
F_35 ( & V_1 -> V_22 ) ;
V_54 = V_1 -> V_3 -> V_54 ;
V_267 = V_5 -> V_267 ;
if ( V_267 == V_269 &&
F_136 ( F_137 () ,
V_1 -> V_3 -> V_50 -> V_270 + V_271 ) ) {
F_9 ( V_5 , F_138 ( V_271 , 3 ) ) ;
V_222 = true ;
} else {
V_222 = V_267 == V_272 &&
V_5 -> V_54 == V_54 ;
}
free = V_267 == V_273 ||
V_267 == V_274 ||
V_267 == V_275 ;
V_5 -> V_54 = V_54 ;
F_38 ( & V_1 -> V_22 ) ;
if ( V_222 )
goto V_46;
V_266 = V_5 -> V_266 ;
F_139 ( V_1 -> V_3 -> V_50 , V_54 ,
V_5 -> V_204 , & V_196 , & V_266 ,
V_267 == V_269 ||
V_267 == V_272 ||
V_267 == V_274 ) ;
if ( V_196 == - V_276 &&
( V_267 == V_269 || V_267 == V_272 ) )
goto V_46;
V_268 = V_196 >= 0 || V_266 > 0 ;
F_35 ( & V_1 -> V_22 ) ;
if ( V_5 -> V_267 == V_269 )
V_5 -> V_267 = V_272 ;
if ( V_5 -> V_267 == V_272 && ! V_268 &&
! V_1 -> V_39 &&
F_64 ( & V_1 -> V_23 , V_5 -> V_10 . V_92 ) ) {
F_65 ( & V_1 -> V_23 , V_5 -> V_10 . V_92 ) ;
F_7 ( V_1 ) ;
free = true ;
}
F_38 ( & V_1 -> V_22 ) ;
if ( V_267 == V_269 && V_196 >= 0 )
V_5 -> V_204 = 1ULL << V_196 ;
if ( V_267 == V_272 && V_268 )
goto V_46;
if ( V_267 == V_269 || V_267 == V_274 ) {
V_68 = V_5 -> V_277 ;
V_5 -> V_277 = NULL ;
} else {
V_68 = V_5 -> V_278 ;
V_5 -> V_278 = NULL ;
}
V_68 -> V_4 . V_92 = V_5 -> V_10 . V_92 ;
V_68 -> V_4 . V_196 = V_196 ;
V_68 -> V_4 . V_266 = V_266 ;
F_27 ( V_1 , & V_68 -> V_30 ,
& V_68 -> V_4 , sizeof( V_68 -> V_4 ) , NULL , 0 ) ;
if ( free ) {
F_140 ( & V_5 -> V_8 ) ;
F_6 ( V_5 -> V_277 ) ;
F_6 ( V_5 -> V_278 ) ;
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
V_5 -> V_267 = V_273 ;
F_9 ( V_5 , 0 ) ;
F_38 ( & V_1 -> V_22 ) ;
}
static int F_141 ( struct V_1 * V_1 ,
struct V_279 * V_105 , int V_267 )
{
struct V_265 * V_280 , * V_281 ;
struct V_4 * V_5 ;
int V_44 ;
if ( ( V_105 -> V_204 == 0 && V_105 -> V_266 == 0 ) ||
V_105 -> V_266 > V_282 ||
V_105 -> V_266 < 0 )
return - V_94 ;
V_5 = F_72 ( sizeof( * V_5 ) , V_20 ) ;
V_280 = F_72 ( sizeof( * V_280 ) , V_20 ) ;
V_281 = F_72 ( sizeof( * V_281 ) , V_20 ) ;
if ( V_5 == NULL || V_280 == NULL || V_281 == NULL ) {
V_44 = - V_21 ;
goto V_283;
}
F_142 ( & V_5 -> V_8 , F_135 ) ;
V_5 -> V_1 = V_1 ;
V_5 -> V_267 = V_267 ;
V_5 -> V_54 = - 1 ;
V_5 -> V_204 = V_105 -> V_204 ;
V_5 -> V_266 = V_105 -> V_266 ;
V_5 -> V_277 = V_280 ;
V_5 -> V_278 = V_281 ;
V_280 -> V_4 . V_51 = V_105 -> V_51 ;
V_280 -> V_4 . type = V_284 ;
V_281 -> V_4 . V_51 = V_105 -> V_51 ;
V_281 -> V_4 . type = V_285 ;
if ( V_267 == V_269 ) {
V_5 -> V_10 . V_11 = V_12 ;
V_44 = F_59 ( V_1 , & V_5 -> V_10 , V_20 ) ;
if ( V_44 < 0 )
goto V_283;
} else {
V_5 -> V_10 . V_11 = NULL ;
V_5 -> V_10 . V_92 = - 1 ;
F_9 ( V_5 , 0 ) ;
}
V_105 -> V_92 = V_5 -> V_10 . V_92 ;
return 0 ;
V_283:
F_6 ( V_5 ) ;
F_6 ( V_280 ) ;
F_6 ( V_281 ) ;
return V_44 ;
}
static int F_143 ( struct V_1 * V_1 ,
union V_70 * V_71 )
{
return F_141 ( V_1 ,
& V_71 -> V_286 , V_269 ) ;
}
static int F_144 ( struct V_1 * V_1 ,
union V_70 * V_71 )
{
return F_63 ( V_1 ,
V_71 -> V_157 . V_92 , V_12 , NULL ) ;
}
static int F_145 ( struct V_1 * V_1 ,
union V_70 * V_71 )
{
return F_141 ( V_1 ,
& V_71 -> V_286 , V_274 ) ;
}
static int F_146 ( struct V_1 * V_1 ,
union V_70 * V_71 )
{
return F_141 ( V_1 ,
& V_71 -> V_286 , V_275 ) ;
}
static int F_147 ( struct V_1 * V_1 , union V_70 * V_71 )
{
return V_1 -> V_3 -> V_125 ;
}
static int F_148 ( struct V_1 * V_1 ,
union V_70 * V_71 )
{
struct V_104 * V_73 = & V_71 -> V_114 ;
switch ( V_73 -> V_108 ) {
case V_111 :
case V_115 :
break;
default:
return - V_94 ;
}
if ( V_73 -> V_47 < V_287 + V_288 )
return - V_289 ;
return F_71 ( V_1 , V_73 , V_290 | 0x3f , V_291 ) ;
}
static int F_149 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_292 * V_73 = & V_71 -> V_293 ;
struct V_104 V_105 ;
int V_294 ;
if ( V_73 -> V_107 > V_1 -> V_3 -> V_50 -> V_295 ||
V_73 -> V_97 > 1024 << V_73 -> V_107 )
return - V_110 ;
if ( V_73 -> V_223 > 3 || V_73 -> V_196 > 63 || V_73 -> V_224 > 15 )
return - V_94 ;
V_294 = F_150 ( V_73 -> V_223 , V_73 -> V_196 , V_73 -> V_224 ) ;
V_105 . V_108 = V_109 ;
V_105 . V_97 = V_73 -> V_97 ;
V_105 . V_51 = V_73 -> V_51 ;
V_105 . V_37 = V_73 -> V_37 ;
V_105 . V_54 = V_73 -> V_54 ;
return F_71 ( V_1 , & V_105 , V_294 , V_73 -> V_107 ) ;
}
static void F_151 ( struct V_296 * V_213 ,
struct V_49 * V_50 , int V_297 )
{
struct V_298 * V_68 =
F_4 ( V_213 , struct V_298 , V_66 ) ;
switch ( V_297 ) {
case V_299 : V_68 -> V_300 . V_95 = V_102 ; break;
case V_301 : V_68 -> V_300 . V_95 = V_102 ; break;
case V_302 :
case V_303 :
case V_304 : V_68 -> V_300 . V_95 = V_305 ; break;
case V_306 : V_68 -> V_300 . V_95 = V_307 ; break;
case V_308 : V_68 -> V_300 . V_95 = V_309 ; break;
default: V_68 -> V_300 . V_95 = V_297 ; break;
}
V_68 -> V_300 . V_37 [ 0 ] = V_213 -> V_310 ;
F_27 ( V_68 -> V_1 , & V_68 -> V_30 , & V_68 -> V_300 ,
sizeof( V_68 -> V_300 ) + V_68 -> V_300 . V_97 , NULL , 0 ) ;
F_7 ( V_68 -> V_1 ) ;
}
static int F_152 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_311 * V_73 = & V_71 -> V_312 ;
struct V_49 * V_50 = V_1 -> V_3 -> V_50 ;
struct V_298 * V_68 ;
if ( ! V_1 -> V_3 -> V_166 )
return - V_167 ;
V_68 = F_20 ( sizeof( * V_68 ) + 4 , V_20 ) ;
if ( V_68 == NULL )
return - V_21 ;
F_1 ( V_1 ) ;
V_68 -> V_1 = V_1 ;
V_68 -> V_66 . V_107 = V_291 ;
V_68 -> V_66 . V_54 = V_73 -> V_54 ;
V_68 -> V_66 . V_175 [ 0 ] = V_313 << 4 ;
V_68 -> V_66 . V_175 [ 1 ] = V_73 -> V_37 [ 0 ] ;
V_68 -> V_66 . V_175 [ 2 ] = V_73 -> V_37 [ 1 ] ;
V_68 -> V_66 . V_174 = 12 ;
V_68 -> V_66 . F_45 = F_151 ;
V_68 -> V_300 . V_51 = V_73 -> V_51 ;
V_68 -> V_300 . type = V_314 ;
if ( F_153 ( V_73 -> V_37 ) )
V_68 -> V_300 . V_97 = 4 ;
V_50 -> V_248 -> V_114 ( V_50 , & V_68 -> V_66 ) ;
return 0 ;
}
static int F_154 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_315 * V_73 = & V_71 -> V_316 ;
struct V_49 * V_50 = V_1 -> V_3 -> V_50 ;
if ( ! V_1 -> V_3 -> V_166 )
return - V_167 ;
F_35 ( & V_50 -> V_22 ) ;
F_155 ( & V_1 -> V_27 , & V_50 -> V_317 ) ;
V_1 -> V_318 = V_73 -> V_51 ;
F_38 ( & V_50 -> V_22 ) ;
return 0 ;
}
void F_156 ( struct V_49 * V_50 , struct V_296 * V_66 )
{
struct V_1 * V_1 ;
struct V_319 * V_68 ;
unsigned long V_35 ;
F_28 ( & V_50 -> V_22 , V_35 ) ;
F_47 (client, &card->phy_receiver_list, phy_receiver_link) {
V_68 = F_72 ( sizeof( * V_68 ) + 8 , V_137 ) ;
if ( V_68 == NULL ) {
F_51 ( V_50 , L_1 ) ;
break;
}
V_68 -> V_300 . V_51 = V_1 -> V_318 ;
V_68 -> V_300 . type = V_320 ;
V_68 -> V_300 . V_95 = V_102 ;
V_68 -> V_300 . V_97 = 8 ;
V_68 -> V_300 . V_37 [ 0 ] = V_66 -> V_175 [ 1 ] ;
V_68 -> V_300 . V_37 [ 1 ] = V_66 -> V_175 [ 2 ] ;
F_27 ( V_1 , & V_68 -> V_30 ,
& V_68 -> V_300 , sizeof( V_68 -> V_300 ) + 8 , NULL , 0 ) ;
}
F_30 ( & V_50 -> V_22 , V_35 ) ;
}
static int F_157 ( struct V_1 * V_1 ,
unsigned int V_321 , void T_1 * V_71 )
{
union V_70 V_40 ;
int V_44 ;
if ( F_19 ( V_1 -> V_3 ) )
return - V_19 ;
if ( F_158 ( V_321 ) != '#' ||
F_159 ( V_321 ) >= F_39 ( V_322 ) ||
F_160 ( V_321 ) > sizeof( V_40 ) )
return - V_323 ;
if ( F_161 ( V_321 ) == V_324 )
memset ( & V_40 , 0 , F_160 ( V_321 ) ) ;
if ( F_161 ( V_321 ) & V_325 )
if ( F_73 ( & V_40 , V_71 , F_160 ( V_321 ) ) )
return - V_45 ;
V_44 = V_322 [ F_159 ( V_321 ) ] ( V_1 , & V_40 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( F_161 ( V_321 ) & V_324 )
if ( F_41 ( V_71 , & V_40 , F_160 ( V_321 ) ) )
return - V_45 ;
return V_44 ;
}
static long F_162 ( struct V_16 * V_16 ,
unsigned int V_321 , unsigned long V_71 )
{
return F_157 ( V_16 -> V_29 , V_321 , ( void T_1 * ) V_71 ) ;
}
static long F_163 ( struct V_16 * V_16 ,
unsigned int V_321 , unsigned long V_71 )
{
return F_157 ( V_16 -> V_29 , V_321 , F_14 ( V_71 ) ) ;
}
static int F_164 ( struct V_16 * V_16 , struct V_326 * V_327 )
{
struct V_1 * V_1 = V_16 -> V_29 ;
unsigned long V_38 ;
int V_216 , V_44 ;
if ( F_19 ( V_1 -> V_3 ) )
return - V_19 ;
if ( V_1 -> V_40 . V_218 != NULL )
return - V_199 ;
if ( ! ( V_327 -> V_328 & V_329 ) )
return - V_94 ;
if ( V_327 -> V_215 & ~ V_330 )
return - V_94 ;
V_1 -> V_215 = V_327 -> V_215 ;
V_38 = V_327 -> V_331 - V_327 -> V_215 ;
V_216 = V_38 >> V_217 ;
if ( V_38 & ~ V_330 )
return - V_94 ;
V_44 = F_165 ( & V_1 -> V_40 , V_216 ) ;
if ( V_44 < 0 )
return V_44 ;
F_35 ( & V_1 -> V_22 ) ;
if ( V_1 -> V_198 ) {
V_44 = F_107 ( & V_1 -> V_40 ,
V_1 -> V_3 -> V_50 ,
F_100 ( V_1 -> V_198 ) ) ;
V_1 -> V_200 = ( V_44 == 0 ) ;
}
F_38 ( & V_1 -> V_22 ) ;
if ( V_44 < 0 )
goto V_283;
V_44 = F_166 ( & V_1 -> V_40 , V_327 ) ;
if ( V_44 < 0 )
goto V_283;
return 0 ;
V_283:
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
V_44 = F_52 ( & V_1 -> V_23 ,
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
struct V_30 * V_30 , * V_332 ;
F_35 ( & V_1 -> V_3 -> V_50 -> V_22 ) ;
F_37 ( & V_1 -> V_27 ) ;
F_38 ( & V_1 -> V_3 -> V_50 -> V_22 ) ;
F_46 ( & V_1 -> V_3 -> V_64 ) ;
F_37 ( & V_1 -> V_28 ) ;
F_48 ( & V_1 -> V_3 -> V_64 ) ;
if ( V_1 -> V_198 )
F_106 ( V_1 -> V_198 ) ;
if ( V_1 -> V_40 . V_218 )
F_167 ( & V_1 -> V_40 , V_1 -> V_3 -> V_50 ) ;
F_35 ( & V_1 -> V_22 ) ;
V_1 -> V_39 = true ;
F_38 ( & V_1 -> V_22 ) ;
F_172 ( V_1 -> V_26 , ! F_169 ( V_1 ) ) ;
F_52 ( & V_1 -> V_23 , F_170 , V_1 ) ;
F_173 ( & V_1 -> V_23 ) ;
F_174 (event, next_event, &client->event_list, link)
F_6 ( V_30 ) ;
F_7 ( V_1 ) ;
return 0 ;
}
static unsigned int F_175 ( struct V_16 * V_16 , T_12 * V_333 )
{
struct V_1 * V_1 = V_16 -> V_29 ;
unsigned int V_334 = 0 ;
F_176 ( V_16 , & V_1 -> V_25 , V_333 ) ;
if ( F_19 ( V_1 -> V_3 ) )
V_334 |= V_335 | V_336 ;
if ( ! F_34 ( & V_1 -> V_24 ) )
V_334 |= V_337 | V_338 ;
return V_334 ;
}
