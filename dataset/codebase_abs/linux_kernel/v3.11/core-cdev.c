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
bool V_88 = V_87 & V_89 ;
unsigned long V_35 ;
int V_44 ;
if ( V_88 )
F_59 ( V_87 ) ;
F_28 ( & V_1 -> V_22 , V_35 ) ;
if ( V_1 -> V_39 )
V_44 = - V_90 ;
else
V_44 = F_60 ( & V_1 -> V_23 , V_10 , 0 , 0 ,
V_91 ) ;
if ( V_44 >= 0 ) {
V_10 -> V_92 = V_44 ;
F_1 ( V_1 ) ;
F_11 ( V_10 ) ;
}
F_30 ( & V_1 -> V_22 , V_35 ) ;
if ( V_88 )
F_61 () ;
return V_44 < 0 ? V_44 : 0 ;
}
static int F_62 ( struct V_1 * V_1 , T_7 V_92 ,
T_8 V_11 ,
struct V_9 * * V_93 )
{
struct V_9 * V_10 ;
F_35 ( & V_1 -> V_22 ) ;
if ( V_1 -> V_39 )
V_10 = NULL ;
else
V_10 = F_63 ( & V_1 -> V_23 , V_92 ) ;
if ( V_10 && V_10 -> V_11 == V_11 )
F_64 ( & V_1 -> V_23 , V_92 ) ;
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
static void F_65 ( struct V_1 * V_1 ,
struct V_9 * V_10 )
{
}
static void F_66 ( struct V_49 * V_50 , int V_95 ,
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
F_64 ( & V_1 -> V_23 , V_68 -> V_5 . V_10 . V_92 ) ;
if ( V_1 -> V_39 )
F_67 ( & V_1 -> V_26 ) ;
F_30 ( & V_1 -> V_22 , V_35 ) ;
V_100 -> type = V_103 ;
V_100 -> V_95 = V_95 ;
if ( V_100 -> V_97 <= sizeof( * V_100 ) - F_68 ( F_69 ( * V_100 ) , V_37 ) )
F_27 ( V_1 , & V_68 -> V_30 , V_100 , sizeof( * V_100 ) ,
V_100 -> V_37 , V_100 -> V_97 ) ;
else
F_27 ( V_1 , & V_68 -> V_30 , V_100 , sizeof( * V_100 ) + V_100 -> V_97 ,
NULL , 0 ) ;
F_7 ( V_1 ) ;
}
static int F_70 ( struct V_1 * V_1 ,
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
V_68 = F_71 ( sizeof( * V_68 ) + V_105 -> V_97 , V_20 ) ;
if ( V_68 == NULL )
return - V_21 ;
V_68 -> V_1 = V_1 ;
V_68 -> V_101 . V_97 = V_105 -> V_97 ;
V_68 -> V_101 . V_51 = V_105 -> V_51 ;
if ( V_105 -> V_37 &&
F_72 ( V_68 -> V_101 . V_37 ,
F_12 ( V_105 -> V_37 ) , V_105 -> V_97 ) ) {
V_44 = - V_45 ;
goto V_112;
}
V_68 -> V_5 . V_10 . V_11 = F_65 ;
V_44 = F_58 ( V_1 , & V_68 -> V_5 . V_10 , V_20 ) ;
if ( V_44 < 0 )
goto V_112;
F_73 ( V_1 -> V_3 -> V_50 , & V_68 -> V_5 . V_113 ,
V_105 -> V_108 , V_106 , V_105 -> V_54 ,
V_107 , V_105 -> V_47 , V_68 -> V_101 . V_37 ,
V_105 -> V_97 , F_66 , V_68 ) ;
return 0 ;
V_112:
F_6 ( V_68 ) ;
return V_44 ;
}
static int F_74 ( struct V_1 * V_1 , union V_70 * V_71 )
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
return F_70 ( V_1 , & V_71 -> V_114 , V_1 -> V_3 -> V_55 ,
V_1 -> V_3 -> V_125 ) ;
}
static inline bool F_75 ( struct V_126 * V_105 )
{
return V_105 == NULL ;
}
static void F_76 ( struct V_1 * V_1 ,
struct V_9 * V_10 )
{
struct V_127 * V_5 = F_4 ( V_10 ,
struct V_127 , V_10 ) ;
if ( F_75 ( V_5 -> V_105 ) )
F_6 ( V_5 -> V_37 ) ;
else
F_77 ( V_5 -> V_50 , V_5 -> V_105 , V_128 ) ;
F_78 ( V_5 -> V_50 ) ;
F_6 ( V_5 ) ;
}
static void F_79 ( struct V_49 * V_50 , struct V_126 * V_105 ,
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
F_80 ( V_50 ) ;
V_5 = F_71 ( sizeof( * V_5 ) , V_137 ) ;
V_68 = F_71 ( sizeof( * V_68 ) , V_137 ) ;
if ( V_5 == NULL || V_68 == NULL )
goto V_112;
V_5 -> V_50 = V_50 ;
V_5 -> V_105 = V_105 ;
V_5 -> V_37 = V_96 ;
V_5 -> V_97 = V_97 ;
if ( F_75 ( V_105 ) ) {
V_136 = F_81 ( V_96 , V_97 , V_137 ) ;
if ( V_136 == NULL )
goto V_112;
V_5 -> V_37 = V_136 ;
}
V_5 -> V_10 . V_11 = F_76 ;
V_44 = F_58 ( V_133 -> V_1 , & V_5 -> V_10 , V_137 ) ;
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
if ( ! F_75 ( V_105 ) )
F_77 ( V_50 , V_105 , V_128 ) ;
F_78 ( V_50 ) ;
}
static void F_82 ( struct V_1 * V_1 ,
struct V_9 * V_10 )
{
struct V_132 * V_5 =
F_4 ( V_10 , struct V_132 , V_10 ) ;
F_83 ( & V_5 -> V_133 ) ;
F_6 ( V_5 ) ;
}
static int F_84 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_148 * V_73 = & V_71 -> V_149 ;
struct V_132 * V_5 ;
struct V_150 V_151 ;
int V_44 ;
V_5 = F_71 ( sizeof( * V_5 ) , V_20 ) ;
if ( V_5 == NULL )
return - V_21 ;
V_151 . V_152 = V_73 -> V_47 ;
if ( V_1 -> V_76 < V_153 )
V_151 . V_154 = V_73 -> V_47 + V_73 -> V_97 ;
else
V_151 . V_154 = V_73 -> V_155 ;
V_5 -> V_133 . V_97 = V_73 -> V_97 ;
V_5 -> V_133 . V_156 = F_79 ;
V_5 -> V_133 . V_131 = V_5 ;
V_5 -> V_51 = V_73 -> V_51 ;
V_5 -> V_1 = V_1 ;
V_44 = F_85 ( & V_5 -> V_133 , & V_151 ) ;
if ( V_44 < 0 ) {
F_6 ( V_5 ) ;
return V_44 ;
}
V_73 -> V_47 = V_5 -> V_133 . V_47 ;
V_5 -> V_10 . V_11 = F_82 ;
V_44 = F_58 ( V_1 , & V_5 -> V_10 , V_20 ) ;
if ( V_44 < 0 ) {
F_82 ( V_1 , & V_5 -> V_10 ) ;
return V_44 ;
}
V_73 -> V_92 = V_5 -> V_10 . V_92 ;
return 0 ;
}
static int F_86 ( struct V_1 * V_1 , union V_70 * V_71 )
{
return F_62 ( V_1 , V_71 -> V_157 . V_92 ,
F_82 , NULL ) ;
}
static int F_87 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_158 * V_73 = & V_71 -> V_159 ;
struct V_9 * V_10 ;
struct V_127 * V_5 ;
int V_44 = 0 ;
if ( F_62 ( V_1 , V_73 -> V_92 ,
F_76 , & V_10 ) < 0 )
return - V_94 ;
V_5 = F_4 ( V_10 , struct V_127 ,
V_10 ) ;
if ( F_75 ( V_5 -> V_105 ) )
goto V_46;
if ( V_73 -> V_97 != F_88 ( V_5 -> V_105 ) ) {
V_44 = - V_94 ;
F_6 ( V_5 -> V_105 ) ;
goto V_46;
}
if ( F_72 ( V_5 -> V_37 , F_12 ( V_73 -> V_37 ) , V_73 -> V_97 ) ) {
V_44 = - V_45 ;
F_6 ( V_5 -> V_105 ) ;
goto V_46;
}
F_77 ( V_5 -> V_50 , V_5 -> V_105 , V_73 -> V_95 ) ;
V_46:
F_78 ( V_5 -> V_50 ) ;
F_6 ( V_5 ) ;
return V_44 ;
}
static int F_89 ( struct V_1 * V_1 , union V_70 * V_71 )
{
F_90 ( V_1 -> V_3 -> V_50 , true ,
V_71 -> V_160 . type == V_161 ) ;
return 0 ;
}
static void F_91 ( struct V_1 * V_1 ,
struct V_9 * V_10 )
{
struct V_162 * V_5 =
F_4 ( V_10 , struct V_162 , V_10 ) ;
F_92 ( & V_5 -> V_163 ) ;
F_6 ( V_5 ) ;
}
static int F_93 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_164 * V_73 = & V_71 -> V_165 ;
struct V_162 * V_5 ;
int V_44 ;
if ( ! V_1 -> V_3 -> V_166 )
return - V_167 ;
if ( V_73 -> V_97 > 256 )
return - V_94 ;
V_5 = F_71 ( sizeof( * V_5 ) + V_73 -> V_97 * 4 , V_20 ) ;
if ( V_5 == NULL )
return - V_21 ;
if ( F_72 ( V_5 -> V_37 , F_12 ( V_73 -> V_37 ) , V_73 -> V_97 * 4 ) ) {
V_44 = - V_45 ;
goto V_112;
}
V_5 -> V_163 . V_97 = V_73 -> V_97 ;
V_5 -> V_163 . V_168 = V_73 -> V_168 ;
V_5 -> V_163 . V_169 = V_73 -> V_169 ;
V_5 -> V_163 . V_37 = V_5 -> V_37 ;
V_44 = F_94 ( & V_5 -> V_163 ) ;
if ( V_44 < 0 )
goto V_112;
V_5 -> V_10 . V_11 = F_91 ;
V_44 = F_58 ( V_1 , & V_5 -> V_10 , V_20 ) ;
if ( V_44 < 0 ) {
F_92 ( & V_5 -> V_163 ) ;
goto V_112;
}
V_73 -> V_92 = V_5 -> V_10 . V_92 ;
return 0 ;
V_112:
F_6 ( V_5 ) ;
return V_44 ;
}
static int F_95 ( struct V_1 * V_1 , union V_70 * V_71 )
{
return F_62 ( V_1 , V_71 -> V_170 . V_92 ,
F_91 , NULL ) ;
}
static void F_96 ( struct V_171 * V_172 , T_7 V_173 ,
T_3 V_174 , void * V_175 , void * V_37 )
{
struct V_1 * V_1 = V_37 ;
struct V_176 * V_68 ;
V_68 = F_71 ( sizeof( * V_68 ) + V_174 , V_137 ) ;
if ( V_68 == NULL )
return;
V_68 -> V_177 . type = V_178 ;
V_68 -> V_177 . V_51 = V_1 -> V_179 ;
V_68 -> V_177 . V_173 = V_173 ;
V_68 -> V_177 . V_174 = V_174 ;
memcpy ( V_68 -> V_177 . V_175 , V_175 , V_174 ) ;
F_27 ( V_1 , & V_68 -> V_30 , & V_68 -> V_177 ,
sizeof( V_68 -> V_177 ) + V_174 , NULL , 0 ) ;
}
static void F_97 ( struct V_171 * V_172 ,
T_9 V_180 , void * V_37 )
{
struct V_1 * V_1 = V_37 ;
struct V_181 * V_68 ;
V_68 = F_71 ( sizeof( * V_68 ) , V_137 ) ;
if ( V_68 == NULL )
return;
V_68 -> V_177 . type = V_182 ;
V_68 -> V_177 . V_51 = V_1 -> V_179 ;
V_68 -> V_177 . V_180 = F_98 ( & V_1 -> V_40 ,
V_180 ) ;
F_27 ( V_1 , & V_68 -> V_30 , & V_68 -> V_177 ,
sizeof( V_68 -> V_177 ) , NULL , 0 ) ;
}
static enum V_183 F_99 ( struct V_171 * V_172 )
{
if ( V_172 -> type == V_184 )
return V_185 ;
else
return V_186 ;
}
static int F_100 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_187 * V_73 = & V_71 -> V_188 ;
struct V_171 * V_172 ;
T_10 V_189 ;
int V_44 ;
F_101 ( V_190 != V_184 ||
V_191 != V_192 ||
V_193 !=
V_194 ) ;
switch ( V_73 -> type ) {
case V_184 :
if ( V_73 -> V_107 > V_195 || V_73 -> V_196 > 63 )
return - V_94 ;
V_189 = F_96 ;
break;
case V_192 :
if ( V_73 -> V_197 < 4 || ( V_73 -> V_197 & 3 ) ||
V_73 -> V_196 > 63 )
return - V_94 ;
V_189 = F_96 ;
break;
case V_194 :
V_189 = ( T_10 ) F_97 ;
break;
default:
return - V_94 ;
}
V_172 = F_102 ( V_1 -> V_3 -> V_50 , V_73 -> type ,
V_73 -> V_196 , V_73 -> V_107 , V_73 -> V_197 , V_189 , V_1 ) ;
if ( F_103 ( V_172 ) )
return F_104 ( V_172 ) ;
if ( V_1 -> V_76 < V_198 )
V_172 -> V_199 = true ;
F_35 ( & V_1 -> V_22 ) ;
if ( V_1 -> V_200 != NULL ) {
F_38 ( & V_1 -> V_22 ) ;
F_105 ( V_172 ) ;
return - V_201 ;
}
if ( ! V_1 -> V_202 ) {
V_44 = F_106 ( & V_1 -> V_40 ,
V_1 -> V_3 -> V_50 ,
F_99 ( V_172 ) ) ;
if ( V_44 < 0 ) {
F_38 ( & V_1 -> V_22 ) ;
F_105 ( V_172 ) ;
return V_44 ;
}
V_1 -> V_202 = true ;
}
V_1 -> V_179 = V_73 -> V_51 ;
V_1 -> V_200 = V_172 ;
F_38 ( & V_1 -> V_22 ) ;
V_73 -> V_92 = 0 ;
return 0 ;
}
static int F_107 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_203 * V_73 = & V_71 -> V_204 ;
struct V_171 * V_205 = V_1 -> V_200 ;
if ( V_205 == NULL || V_73 -> V_92 != 0 )
return - V_94 ;
return F_108 ( V_205 , & V_73 -> V_206 ) ;
}
static int F_109 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_207 * V_73 = & V_71 -> V_208 ;
struct V_209 T_1 * V_66 , * V_154 , * V_210 ;
struct V_171 * V_205 = V_1 -> V_200 ;
unsigned long V_96 , V_211 , V_212 = 0 ;
T_7 V_213 ;
int V_41 ;
struct {
struct V_214 V_215 ;
T_11 V_175 [ 256 ] ;
} V_216 ;
if ( V_205 == NULL || V_73 -> V_92 != 0 )
return - V_94 ;
V_96 = ( unsigned long ) V_73 -> V_37 - V_1 -> V_217 ;
V_211 = V_1 -> V_40 . V_218 << V_219 ;
if ( V_73 -> V_37 == 0 || V_1 -> V_40 . V_220 == NULL ||
V_96 >= V_211 ) {
V_96 = 0 ;
V_211 = 0 ;
}
if ( V_205 -> type == V_194 && V_96 & 3 )
return - V_94 ;
V_66 = (struct V_209 T_1 * ) F_12 ( V_73 -> V_221 ) ;
if ( ! F_110 ( V_222 , V_66 , V_73 -> V_38 ) )
return - V_45 ;
V_154 = ( void T_1 * ) V_66 + V_73 -> V_38 ;
V_41 = 0 ;
while ( V_66 < V_154 ) {
if ( F_111 ( V_213 , & V_66 -> V_213 ) )
return - V_45 ;
V_216 . V_215 . V_223 = F_112 ( V_213 ) ;
V_216 . V_215 . V_177 = F_113 ( V_213 ) ;
V_216 . V_215 . V_224 = F_114 ( V_213 ) ;
V_216 . V_215 . V_225 = F_115 ( V_213 ) ;
V_216 . V_215 . V_226 = F_116 ( V_213 ) ;
V_216 . V_215 . V_174 = F_117 ( V_213 ) ;
switch ( V_205 -> type ) {
case V_184 :
if ( V_216 . V_215 . V_174 & 3 )
return - V_94 ;
V_212 = V_216 . V_215 . V_174 ;
break;
case V_192 :
if ( V_216 . V_215 . V_174 == 0 ||
V_216 . V_215 . V_174 % V_205 -> V_197 != 0 )
return - V_94 ;
break;
case V_194 :
if ( V_216 . V_215 . V_223 == 0 ||
V_216 . V_215 . V_223 & 3 )
return - V_94 ;
break;
}
V_210 = (struct V_209 T_1 * )
& V_66 -> V_175 [ V_212 / 4 ] ;
if ( V_210 > V_154 )
return - V_94 ;
if ( F_118
( V_216 . V_215 . V_175 , V_66 -> V_175 , V_212 ) )
return - V_45 ;
if ( V_216 . V_215 . V_224 && V_205 -> type == V_184 &&
V_216 . V_215 . V_174 + V_216 . V_215 . V_223 > 0 )
return - V_94 ;
if ( V_96 + V_216 . V_215 . V_223 > V_211 )
return - V_94 ;
if ( F_119 ( V_205 , & V_216 . V_215 ,
& V_1 -> V_40 , V_96 ) )
break;
V_66 = V_210 ;
V_96 += V_216 . V_215 . V_223 ;
V_41 ++ ;
}
F_120 ( V_205 ) ;
V_73 -> V_38 -= F_15 ( V_66 ) - V_73 -> V_221 ;
V_73 -> V_221 = F_15 ( V_66 ) ;
V_73 -> V_37 = V_1 -> V_217 + V_96 ;
return V_41 ;
}
static int F_121 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_227 * V_73 = & V_71 -> V_228 ;
F_101 (
V_229 != V_230 ||
V_231 != V_232 ||
V_233 != V_234 ||
V_235 != V_236 ||
V_237 != V_238 ) ;
if ( V_1 -> V_200 == NULL || V_73 -> V_92 != 0 )
return - V_94 ;
if ( V_1 -> V_200 -> type == V_192 &&
( V_73 -> V_239 == 0 || V_73 -> V_239 > 15 || V_73 -> V_240 > 15 ) )
return - V_94 ;
return F_122 ( V_1 -> V_200 ,
V_73 -> V_173 , V_73 -> V_240 , V_73 -> V_239 ) ;
}
static int F_123 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_241 * V_73 = & V_71 -> V_242 ;
if ( V_1 -> V_200 == NULL || V_73 -> V_92 != 0 )
return - V_94 ;
return F_124 ( V_1 -> V_200 ) ;
}
static int F_125 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_243 * V_73 = & V_71 -> V_244 ;
if ( V_1 -> V_200 == NULL || V_73 -> V_92 != 0 )
return - V_94 ;
return F_126 ( V_1 -> V_200 ) ;
}
static int F_127 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_245 * V_73 = & V_71 -> V_246 ;
struct V_49 * V_50 = V_1 -> V_3 -> V_50 ;
struct V_247 V_248 = { 0 , 0 } ;
T_7 V_249 ;
int V_44 = 0 ;
F_128 () ;
V_249 = V_50 -> V_250 -> V_251 ( V_50 , V_252 ) ;
switch ( V_73 -> V_253 ) {
case V_254 : F_129 ( & V_248 ) ; break;
case V_255 : F_130 ( & V_248 ) ; break;
case V_256 : F_131 ( & V_248 ) ; break;
default:
V_44 = - V_94 ;
}
F_132 () ;
V_73 -> V_257 = V_248 . V_257 ;
V_73 -> V_258 = V_248 . V_258 ;
V_73 -> V_259 = V_249 ;
return V_44 ;
}
static int F_133 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_260 * V_73 = & V_71 -> V_261 ;
struct V_245 V_262 ;
V_262 . V_253 = V_254 ;
F_127 ( V_1 , (union V_70 * ) & V_262 ) ;
V_73 -> V_263 = V_262 . V_257 * V_264 + V_262 . V_258 / V_265 ;
V_73 -> V_259 = V_262 . V_259 ;
return 0 ;
}
static void F_134 ( struct V_266 * V_8 )
{
struct V_267 * V_68 ;
struct V_4 * V_5 =
F_4 ( V_8 , struct V_4 , V_8 . V_8 ) ;
struct V_1 * V_1 = V_5 -> V_1 ;
int V_54 , V_196 , V_268 , V_269 ;
bool V_224 , free , V_270 ;
F_35 ( & V_1 -> V_22 ) ;
V_54 = V_1 -> V_3 -> V_54 ;
V_269 = V_5 -> V_269 ;
if ( V_269 == V_271 &&
F_135 ( F_136 () ,
V_1 -> V_3 -> V_50 -> V_272 + V_273 ) ) {
F_9 ( V_5 , F_137 ( V_273 , 3 ) ) ;
V_224 = true ;
} else {
V_224 = V_269 == V_274 &&
V_5 -> V_54 == V_54 ;
}
free = V_269 == V_275 ||
V_269 == V_276 ||
V_269 == V_277 ;
V_5 -> V_54 = V_54 ;
F_38 ( & V_1 -> V_22 ) ;
if ( V_224 )
goto V_46;
V_268 = V_5 -> V_268 ;
F_138 ( V_1 -> V_3 -> V_50 , V_54 ,
V_5 -> V_206 , & V_196 , & V_268 ,
V_269 == V_271 ||
V_269 == V_274 ||
V_269 == V_276 ) ;
if ( V_196 == - V_278 &&
( V_269 == V_271 || V_269 == V_274 ) )
goto V_46;
V_270 = V_196 >= 0 || V_268 > 0 ;
F_35 ( & V_1 -> V_22 ) ;
if ( V_5 -> V_269 == V_271 )
V_5 -> V_269 = V_274 ;
if ( V_5 -> V_269 == V_274 && ! V_270 &&
! V_1 -> V_39 &&
F_63 ( & V_1 -> V_23 , V_5 -> V_10 . V_92 ) ) {
F_64 ( & V_1 -> V_23 , V_5 -> V_10 . V_92 ) ;
F_7 ( V_1 ) ;
free = true ;
}
F_38 ( & V_1 -> V_22 ) ;
if ( V_269 == V_271 && V_196 >= 0 )
V_5 -> V_206 = 1ULL << V_196 ;
if ( V_269 == V_274 && V_270 )
goto V_46;
if ( V_269 == V_271 || V_269 == V_276 ) {
V_68 = V_5 -> V_279 ;
V_5 -> V_279 = NULL ;
} else {
V_68 = V_5 -> V_280 ;
V_5 -> V_280 = NULL ;
}
V_68 -> V_4 . V_92 = V_5 -> V_10 . V_92 ;
V_68 -> V_4 . V_196 = V_196 ;
V_68 -> V_4 . V_268 = V_268 ;
F_27 ( V_1 , & V_68 -> V_30 ,
& V_68 -> V_4 , sizeof( V_68 -> V_4 ) , NULL , 0 ) ;
if ( free ) {
F_139 ( & V_5 -> V_8 ) ;
F_6 ( V_5 -> V_279 ) ;
F_6 ( V_5 -> V_280 ) ;
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
V_5 -> V_269 = V_275 ;
F_9 ( V_5 , 0 ) ;
F_38 ( & V_1 -> V_22 ) ;
}
static int F_140 ( struct V_1 * V_1 ,
struct V_281 * V_105 , int V_269 )
{
struct V_267 * V_282 , * V_283 ;
struct V_4 * V_5 ;
int V_44 ;
if ( ( V_105 -> V_206 == 0 && V_105 -> V_268 == 0 ) ||
V_105 -> V_268 > V_284 )
return - V_94 ;
V_5 = F_71 ( sizeof( * V_5 ) , V_20 ) ;
V_282 = F_71 ( sizeof( * V_282 ) , V_20 ) ;
V_283 = F_71 ( sizeof( * V_283 ) , V_20 ) ;
if ( V_5 == NULL || V_282 == NULL || V_283 == NULL ) {
V_44 = - V_21 ;
goto V_285;
}
F_141 ( & V_5 -> V_8 , F_134 ) ;
V_5 -> V_1 = V_1 ;
V_5 -> V_269 = V_269 ;
V_5 -> V_54 = - 1 ;
V_5 -> V_206 = V_105 -> V_206 ;
V_5 -> V_268 = V_105 -> V_268 ;
V_5 -> V_279 = V_282 ;
V_5 -> V_280 = V_283 ;
V_282 -> V_4 . V_51 = V_105 -> V_51 ;
V_282 -> V_4 . type = V_286 ;
V_283 -> V_4 . V_51 = V_105 -> V_51 ;
V_283 -> V_4 . type = V_287 ;
if ( V_269 == V_271 ) {
V_5 -> V_10 . V_11 = V_12 ;
V_44 = F_58 ( V_1 , & V_5 -> V_10 , V_20 ) ;
if ( V_44 < 0 )
goto V_285;
} else {
V_5 -> V_10 . V_11 = NULL ;
V_5 -> V_10 . V_92 = - 1 ;
F_9 ( V_5 , 0 ) ;
}
V_105 -> V_92 = V_5 -> V_10 . V_92 ;
return 0 ;
V_285:
F_6 ( V_5 ) ;
F_6 ( V_282 ) ;
F_6 ( V_283 ) ;
return V_44 ;
}
static int F_142 ( struct V_1 * V_1 ,
union V_70 * V_71 )
{
return F_140 ( V_1 ,
& V_71 -> V_288 , V_271 ) ;
}
static int F_143 ( struct V_1 * V_1 ,
union V_70 * V_71 )
{
return F_62 ( V_1 ,
V_71 -> V_157 . V_92 , V_12 , NULL ) ;
}
static int F_144 ( struct V_1 * V_1 ,
union V_70 * V_71 )
{
return F_140 ( V_1 ,
& V_71 -> V_288 , V_276 ) ;
}
static int F_145 ( struct V_1 * V_1 ,
union V_70 * V_71 )
{
return F_140 ( V_1 ,
& V_71 -> V_288 , V_277 ) ;
}
static int F_146 ( struct V_1 * V_1 , union V_70 * V_71 )
{
return V_1 -> V_3 -> V_125 ;
}
static int F_147 ( struct V_1 * V_1 ,
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
if ( V_73 -> V_47 < V_289 + V_290 )
return - V_291 ;
return F_70 ( V_1 , V_73 , V_292 | 0x3f , V_293 ) ;
}
static int F_148 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_294 * V_73 = & V_71 -> V_295 ;
struct V_104 V_105 ;
int V_296 ;
if ( V_73 -> V_107 > V_1 -> V_3 -> V_50 -> V_297 ||
V_73 -> V_97 > 1024 << V_73 -> V_107 )
return - V_110 ;
if ( V_73 -> V_225 > 3 || V_73 -> V_196 > 63 || V_73 -> V_226 > 15 )
return - V_94 ;
V_296 = F_149 ( V_73 -> V_225 , V_73 -> V_196 , V_73 -> V_226 ) ;
V_105 . V_108 = V_109 ;
V_105 . V_97 = V_73 -> V_97 ;
V_105 . V_51 = V_73 -> V_51 ;
V_105 . V_37 = V_73 -> V_37 ;
V_105 . V_54 = V_73 -> V_54 ;
return F_70 ( V_1 , & V_105 , V_296 , V_73 -> V_107 ) ;
}
static void F_150 ( struct V_298 * V_215 ,
struct V_49 * V_50 , int V_299 )
{
struct V_300 * V_68 =
F_4 ( V_215 , struct V_300 , V_66 ) ;
switch ( V_299 ) {
case V_301 : V_68 -> V_302 . V_95 = V_102 ; break;
case V_303 : V_68 -> V_302 . V_95 = V_102 ; break;
case V_304 :
case V_305 :
case V_306 : V_68 -> V_302 . V_95 = V_307 ; break;
case V_308 : V_68 -> V_302 . V_95 = V_309 ; break;
case V_310 : V_68 -> V_302 . V_95 = V_311 ; break;
default: V_68 -> V_302 . V_95 = V_299 ; break;
}
V_68 -> V_302 . V_37 [ 0 ] = V_215 -> V_312 ;
F_27 ( V_68 -> V_1 , & V_68 -> V_30 , & V_68 -> V_302 ,
sizeof( V_68 -> V_302 ) + V_68 -> V_302 . V_97 , NULL , 0 ) ;
F_7 ( V_68 -> V_1 ) ;
}
static int F_151 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_313 * V_73 = & V_71 -> V_314 ;
struct V_49 * V_50 = V_1 -> V_3 -> V_50 ;
struct V_300 * V_68 ;
if ( ! V_1 -> V_3 -> V_166 )
return - V_167 ;
V_68 = F_20 ( sizeof( * V_68 ) + 4 , V_20 ) ;
if ( V_68 == NULL )
return - V_21 ;
F_1 ( V_1 ) ;
V_68 -> V_1 = V_1 ;
V_68 -> V_66 . V_107 = V_293 ;
V_68 -> V_66 . V_54 = V_73 -> V_54 ;
V_68 -> V_66 . V_175 [ 0 ] = V_315 << 4 ;
V_68 -> V_66 . V_175 [ 1 ] = V_73 -> V_37 [ 0 ] ;
V_68 -> V_66 . V_175 [ 2 ] = V_73 -> V_37 [ 1 ] ;
V_68 -> V_66 . V_174 = 12 ;
V_68 -> V_66 . F_45 = F_150 ;
V_68 -> V_302 . V_51 = V_73 -> V_51 ;
V_68 -> V_302 . type = V_316 ;
if ( F_152 ( V_73 -> V_37 ) )
V_68 -> V_302 . V_97 = 4 ;
V_50 -> V_250 -> V_114 ( V_50 , & V_68 -> V_66 ) ;
return 0 ;
}
static int F_153 ( struct V_1 * V_1 , union V_70 * V_71 )
{
struct V_317 * V_73 = & V_71 -> V_318 ;
struct V_49 * V_50 = V_1 -> V_3 -> V_50 ;
if ( ! V_1 -> V_3 -> V_166 )
return - V_167 ;
F_35 ( & V_50 -> V_22 ) ;
F_154 ( & V_1 -> V_27 , & V_50 -> V_319 ) ;
V_1 -> V_320 = V_73 -> V_51 ;
F_38 ( & V_50 -> V_22 ) ;
return 0 ;
}
void F_155 ( struct V_49 * V_50 , struct V_298 * V_66 )
{
struct V_1 * V_1 ;
struct V_321 * V_68 ;
unsigned long V_35 ;
F_28 ( & V_50 -> V_22 , V_35 ) ;
F_47 (client, &card->phy_receiver_list, phy_receiver_link) {
V_68 = F_71 ( sizeof( * V_68 ) + 8 , V_137 ) ;
if ( V_68 == NULL )
break;
V_68 -> V_302 . V_51 = V_1 -> V_320 ;
V_68 -> V_302 . type = V_322 ;
V_68 -> V_302 . V_95 = V_102 ;
V_68 -> V_302 . V_97 = 8 ;
V_68 -> V_302 . V_37 [ 0 ] = V_66 -> V_175 [ 1 ] ;
V_68 -> V_302 . V_37 [ 1 ] = V_66 -> V_175 [ 2 ] ;
F_27 ( V_1 , & V_68 -> V_30 ,
& V_68 -> V_302 , sizeof( V_68 -> V_302 ) + 8 , NULL , 0 ) ;
}
F_30 ( & V_50 -> V_22 , V_35 ) ;
}
static int F_156 ( struct V_1 * V_1 ,
unsigned int V_323 , void T_1 * V_71 )
{
union V_70 V_40 ;
int V_44 ;
if ( F_19 ( V_1 -> V_3 ) )
return - V_19 ;
if ( F_157 ( V_323 ) != '#' ||
F_158 ( V_323 ) >= F_39 ( V_324 ) ||
F_159 ( V_323 ) > sizeof( V_40 ) )
return - V_325 ;
if ( F_160 ( V_323 ) == V_326 )
memset ( & V_40 , 0 , F_159 ( V_323 ) ) ;
if ( F_160 ( V_323 ) & V_327 )
if ( F_72 ( & V_40 , V_71 , F_159 ( V_323 ) ) )
return - V_45 ;
V_44 = V_324 [ F_158 ( V_323 ) ] ( V_1 , & V_40 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( F_160 ( V_323 ) & V_326 )
if ( F_41 ( V_71 , & V_40 , F_159 ( V_323 ) ) )
return - V_45 ;
return V_44 ;
}
static long F_161 ( struct V_16 * V_16 ,
unsigned int V_323 , unsigned long V_71 )
{
return F_156 ( V_16 -> V_29 , V_323 , ( void T_1 * ) V_71 ) ;
}
static long F_162 ( struct V_16 * V_16 ,
unsigned int V_323 , unsigned long V_71 )
{
return F_156 ( V_16 -> V_29 , V_323 , F_14 ( V_71 ) ) ;
}
static int F_163 ( struct V_16 * V_16 , struct V_328 * V_329 )
{
struct V_1 * V_1 = V_16 -> V_29 ;
unsigned long V_38 ;
int V_218 , V_44 ;
if ( F_19 ( V_1 -> V_3 ) )
return - V_19 ;
if ( V_1 -> V_40 . V_220 != NULL )
return - V_201 ;
if ( ! ( V_329 -> V_330 & V_331 ) )
return - V_94 ;
if ( V_329 -> V_217 & ~ V_332 )
return - V_94 ;
V_1 -> V_217 = V_329 -> V_217 ;
V_38 = V_329 -> V_333 - V_329 -> V_217 ;
V_218 = V_38 >> V_219 ;
if ( V_38 & ~ V_332 )
return - V_94 ;
V_44 = F_164 ( & V_1 -> V_40 , V_218 ) ;
if ( V_44 < 0 )
return V_44 ;
F_35 ( & V_1 -> V_22 ) ;
if ( V_1 -> V_200 ) {
V_44 = F_106 ( & V_1 -> V_40 ,
V_1 -> V_3 -> V_50 ,
F_99 ( V_1 -> V_200 ) ) ;
V_1 -> V_202 = ( V_44 == 0 ) ;
}
F_38 ( & V_1 -> V_22 ) ;
if ( V_44 < 0 )
goto V_285;
V_44 = F_165 ( & V_1 -> V_40 , V_329 ) ;
if ( V_44 < 0 )
goto V_285;
return 0 ;
V_285:
F_166 ( & V_1 -> V_40 , V_1 -> V_3 -> V_50 ) ;
return V_44 ;
}
static int F_167 ( int V_65 , void * V_66 , void * V_37 )
{
struct V_9 * V_10 = V_66 ;
return V_10 -> V_11 == F_65 ;
}
static int F_168 ( struct V_1 * V_1 )
{
int V_44 ;
F_35 ( & V_1 -> V_22 ) ;
V_44 = F_51 ( & V_1 -> V_23 ,
F_167 , NULL ) ;
F_38 ( & V_1 -> V_22 ) ;
return V_44 ;
}
static int F_169 ( int V_65 , void * V_66 , void * V_37 )
{
struct V_9 * V_10 = V_66 ;
struct V_1 * V_1 = V_37 ;
V_10 -> V_11 ( V_1 , V_10 ) ;
F_7 ( V_1 ) ;
return 0 ;
}
static int F_170 ( struct V_15 * V_15 , struct V_16 * V_16 )
{
struct V_1 * V_1 = V_16 -> V_29 ;
struct V_30 * V_30 , * V_334 ;
F_35 ( & V_1 -> V_3 -> V_50 -> V_22 ) ;
F_37 ( & V_1 -> V_27 ) ;
F_38 ( & V_1 -> V_3 -> V_50 -> V_22 ) ;
F_46 ( & V_1 -> V_3 -> V_64 ) ;
F_37 ( & V_1 -> V_28 ) ;
F_48 ( & V_1 -> V_3 -> V_64 ) ;
if ( V_1 -> V_200 )
F_105 ( V_1 -> V_200 ) ;
if ( V_1 -> V_40 . V_220 )
F_166 ( & V_1 -> V_40 , V_1 -> V_3 -> V_50 ) ;
F_35 ( & V_1 -> V_22 ) ;
V_1 -> V_39 = true ;
F_38 ( & V_1 -> V_22 ) ;
F_171 ( V_1 -> V_26 , ! F_168 ( V_1 ) ) ;
F_51 ( & V_1 -> V_23 , F_169 , V_1 ) ;
F_172 ( & V_1 -> V_23 ) ;
F_173 (event, next_event, &client->event_list, link)
F_6 ( V_30 ) ;
F_7 ( V_1 ) ;
return 0 ;
}
static unsigned int F_174 ( struct V_16 * V_16 , T_12 * V_335 )
{
struct V_1 * V_1 = V_16 -> V_29 ;
unsigned int V_336 = 0 ;
F_175 ( V_16 , & V_1 -> V_25 , V_335 ) ;
if ( F_19 ( V_1 -> V_3 ) )
V_336 |= V_337 | V_338 ;
if ( ! F_34 ( & V_1 -> V_24 ) )
V_336 |= V_339 | V_340 ;
return V_336 ;
}
