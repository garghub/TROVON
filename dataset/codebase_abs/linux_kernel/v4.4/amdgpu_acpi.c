static union V_1 * F_1 ( T_1 V_2 , int V_3 ,
struct V_4 * V_5 )
{
T_2 V_6 ;
union V_1 V_7 [ 2 ] ;
struct V_8 V_9 ;
struct V_4 V_10 = { V_11 , NULL } ;
V_9 . V_12 = 2 ;
V_9 . V_13 = & V_7 [ 0 ] ;
V_7 [ 0 ] . type = V_14 ;
V_7 [ 0 ] . integer . V_15 = V_3 ;
if ( V_5 ) {
V_7 [ 1 ] . type = V_16 ;
V_7 [ 1 ] . V_10 . V_17 = V_5 -> V_17 ;
V_7 [ 1 ] . V_10 . V_13 = V_5 -> V_13 ;
} else {
V_7 [ 1 ] . type = V_14 ;
V_7 [ 1 ] . integer . V_15 = 0 ;
}
V_6 = F_2 ( V_2 , L_1 , & V_9 , & V_10 ) ;
if ( F_3 ( V_6 ) && V_6 != V_18 ) {
F_4 ( L_2 ,
F_5 ( V_6 ) ) ;
F_6 ( V_10 . V_13 ) ;
return NULL ;
}
return V_10 . V_13 ;
}
static void F_7 ( struct V_19 * V_20 , T_3 V_21 )
{
V_20 -> V_22 = V_21 & V_23 ;
V_20 -> V_24 = V_21 & V_25 ;
V_20 -> V_26 = V_21 & V_27 ;
V_20 -> V_28 = V_21 & V_29 ;
V_20 -> V_30 = V_21 & V_31 ;
V_20 -> V_32 = V_21 & V_33 ;
V_20 -> V_34 = V_21 & V_35 ;
V_20 -> V_36 = V_21 & V_37 ;
V_20 -> V_38 = V_21 & V_39 ;
}
static void F_8 ( struct V_40 * V_41 , T_3 V_21 )
{
V_41 -> V_42 = V_21 & V_43 ;
V_41 -> V_44 = V_21 & V_45 ;
V_41 -> V_46 = V_21 & V_47 ;
V_41 -> V_48 = V_21 & V_49 ;
V_41 -> V_50 = V_21 & V_51 ;
V_41 -> V_52 = V_21 & V_53 ;
V_41 -> V_54 = V_21 & V_55 ;
V_41 -> V_56 = V_21 & V_57 ;
V_41 -> V_58 = V_21 & V_59 ;
V_41 -> V_60 = V_21 & V_61 ;
}
static int F_9 ( T_1 V_2 ,
struct V_62 * V_63 )
{
union V_1 * V_64 ;
struct V_65 V_66 ;
T_4 V_67 ;
int V_68 = 0 ;
V_64 = F_1 ( V_2 , V_69 , NULL ) ;
if ( ! V_64 )
return - V_70 ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
V_67 = * ( V_71 * ) V_64 -> V_10 . V_13 ;
if ( V_67 < 12 ) {
F_10 ( L_3 , V_67 ) ;
V_68 = - V_72 ;
goto V_73;
}
V_67 = F_11 ( sizeof( V_66 ) , V_67 ) ;
memcpy ( & V_66 , V_64 -> V_10 . V_13 , V_67 ) ;
F_4 ( L_4 , V_66 . V_74 ) ;
F_7 ( & V_63 -> V_75 , V_66 . V_76 ) ;
F_8 ( & V_63 -> V_77 , V_66 . V_78 ) ;
V_73:
F_6 ( V_64 ) ;
return V_68 ;
}
static int F_12 ( T_1 V_2 ,
struct V_79 * V_20 )
{
union V_1 * V_64 ;
struct V_80 V_5 ;
T_4 V_67 ;
int V_68 = 0 ;
V_64 = F_1 ( V_2 , V_81 , NULL ) ;
if ( ! V_64 ) {
V_68 = - V_70 ;
goto V_73;
}
V_67 = * ( V_71 * ) V_64 -> V_10 . V_13 ;
if ( V_67 < 10 ) {
V_68 = - V_72 ;
goto V_73;
}
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
V_67 = F_11 ( sizeof( V_5 ) , V_67 ) ;
memcpy ( & V_5 , V_64 -> V_10 . V_13 , V_67 ) ;
F_4 ( L_5 ,
V_5 . V_82 , V_5 . V_83 ) ;
V_5 . V_82 = V_5 . V_82 & V_5 . V_83 ;
if ( ( V_5 . V_82 & V_84 ) == V_85 ) {
V_20 -> V_86 = false ;
V_20 -> V_87 = 0 ;
} else if ( ( V_5 . V_82 & V_84 ) == V_88 ) {
V_20 -> V_86 = true ;
V_20 -> V_87 = 0x81 ;
} else {
if ( V_67 < 11 ) {
V_68 = - V_72 ;
goto V_73;
}
V_20 -> V_86 = true ;
V_20 -> V_87 = V_5 . V_87 ;
}
V_73:
F_4 ( L_6 ,
( V_20 -> V_86 ? L_7 : L_8 ) ,
V_20 -> V_87 ) ;
F_6 ( V_64 ) ;
return V_68 ;
}
static int F_13 ( T_1 V_2 ,
struct V_89 * V_90 )
{
union V_1 * V_64 ;
T_4 V_67 ;
int V_12 = 0 ;
V_64 = F_1 ( V_2 , V_91 , NULL ) ;
if ( ! V_64 )
return - V_70 ;
V_67 = * ( V_71 * ) V_64 -> V_10 . V_13 ;
if ( V_67 < 0xd ) {
V_12 = - V_72 ;
goto V_73;
}
memset ( V_90 , 0 , sizeof( * V_90 ) ) ;
V_67 = F_11 ( sizeof( * V_90 ) , V_67 ) ;
memcpy ( V_90 , V_64 -> V_10 . V_13 , V_67 ) ;
F_4 ( L_9 , V_90 -> V_92 ) ;
V_12 = F_14 ( V_90 -> V_92 ) ;
V_73:
F_6 ( V_64 ) ;
return V_12 ;
}
int F_15 ( struct V_93 * V_94 ,
struct V_95 * V_96 )
{
struct V_62 * V_63 = & V_94 -> V_63 ;
struct V_89 V_90 ;
T_1 V_2 ;
int V_12 ;
F_4 ( L_10 ,
V_96 -> V_97 , V_96 -> type ) ;
if ( strcmp ( V_96 -> V_97 , V_98 ) != 0 )
return V_99 ;
if ( ! V_63 -> V_100 . V_86 ||
V_96 -> type != V_63 -> V_100 . V_87 )
return V_99 ;
V_2 = F_16 ( & V_94 -> V_101 -> V_102 ) ;
V_12 = F_13 ( V_2 , & V_90 ) ;
if ( V_12 <= 0 )
return V_99 ;
F_4 ( L_11 , V_12 ) ;
if ( V_90 . V_92 & V_103 ) {
struct V_104 * V_105 = V_63 -> V_106 ;
if ( V_105 ) {
struct V_107 * V_108 = V_105 -> V_109 ;
F_4 ( L_12 ,
V_90 . V_110 ) ;
F_17 ( V_94 , V_105 , V_90 . V_110 ) ;
#if F_18 ( V_111 ) || F_18 ( V_112 )
F_19 ( V_108 -> V_113 ,
V_114 ) ;
#endif
}
}
return V_115 ;
}
static union V_1 * F_20 ( T_1 V_2 , int V_3 ,
struct V_4 * V_5 )
{
T_2 V_6 ;
union V_1 V_116 [ 2 ] ;
struct V_8 V_117 ;
struct V_4 V_10 = { V_11 , NULL } ;
V_117 . V_12 = 2 ;
V_117 . V_13 = & V_116 [ 0 ] ;
V_116 [ 0 ] . type = V_14 ;
V_116 [ 0 ] . integer . V_15 = V_3 ;
if ( V_5 ) {
V_116 [ 1 ] . type = V_16 ;
V_116 [ 1 ] . V_10 . V_17 = V_5 -> V_17 ;
V_116 [ 1 ] . V_10 . V_13 = V_5 -> V_13 ;
} else {
V_116 [ 1 ] . type = V_14 ;
V_116 [ 1 ] . integer . V_15 = 0 ;
}
V_6 = F_2 ( V_2 , L_13 , & V_117 , & V_10 ) ;
if ( F_3 ( V_6 ) && V_6 != V_18 ) {
F_4 ( L_14 ,
F_5 ( V_6 ) ) ;
F_6 ( V_10 . V_13 ) ;
return NULL ;
}
return V_10 . V_13 ;
}
static void F_21 ( struct V_118 * V_41 , T_3 V_21 )
{
V_41 -> V_119 = V_21 & V_120 ;
V_41 -> V_121 = V_21 & V_122 ;
V_41 -> V_123 = V_21 & V_124 ;
V_41 -> V_125 = V_21 & V_126 ;
}
static int F_22 ( T_1 V_2 ,
struct V_127 * V_128 )
{
union V_1 * V_64 ;
struct V_129 V_66 ;
T_4 V_67 ;
int V_68 = 0 ;
V_64 = F_20 ( V_2 , V_130 , NULL ) ;
if ( ! V_64 )
return - V_70 ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
V_67 = * ( V_71 * ) V_64 -> V_10 . V_13 ;
if ( V_67 < 8 ) {
F_10 ( L_15 , V_67 ) ;
V_68 = - V_72 ;
goto V_73;
}
V_67 = F_11 ( sizeof( V_66 ) , V_67 ) ;
memcpy ( & V_66 , V_64 -> V_10 . V_13 , V_67 ) ;
F_4 ( L_16 , V_66 . V_74 ) ;
F_21 ( & V_128 -> V_77 , V_66 . V_78 ) ;
V_73:
F_6 ( V_64 ) ;
return V_68 ;
}
bool F_23 ( struct V_93 * V_94 )
{
struct V_127 * V_128 = & V_94 -> V_128 ;
if ( V_128 -> V_77 . V_121 && V_128 -> V_77 . V_123 )
return true ;
return false ;
}
int F_24 ( struct V_93 * V_94 )
{
T_1 V_2 ;
union V_1 * V_64 ;
struct V_127 * V_128 = & V_94 -> V_128 ;
V_2 = F_16 ( & V_94 -> V_101 -> V_102 ) ;
if ( ! V_2 )
return - V_72 ;
if ( ! V_128 -> V_77 . V_123 )
return - V_72 ;
V_64 = F_20 ( V_2 , V_131 , NULL ) ;
if ( ! V_64 )
return - V_70 ;
F_6 ( V_64 ) ;
return 0 ;
}
int F_25 ( struct V_93 * V_94 ,
T_5 V_132 , bool V_133 )
{
T_1 V_2 ;
union V_1 * V_64 ;
struct V_127 * V_128 = & V_94 -> V_128 ;
struct V_134 V_135 ;
struct V_136 V_137 ;
struct V_4 V_5 ;
T_4 V_67 ;
T_3 V_138 = 3 ;
V_2 = F_16 ( & V_94 -> V_101 -> V_102 ) ;
if ( ! V_2 )
return - V_72 ;
if ( ! V_128 -> V_77 . V_121 )
return - V_72 ;
V_135 . V_67 = sizeof( struct V_134 ) ;
V_135 . V_139 = V_94 -> V_101 -> V_140 | ( V_94 -> V_101 -> V_141 -> V_142 << 8 ) ;
V_135 . V_143 = V_144 ;
V_135 . V_82 = V_145 ;
if ( V_133 )
V_135 . V_82 |= V_146 ;
V_135 . V_147 = V_148 ;
V_135 . V_132 = V_132 ;
V_5 . V_17 = sizeof( struct V_134 ) ;
V_5 . V_13 = & V_135 ;
while ( V_138 -- ) {
V_64 = F_20 ( V_2 , V_149 , & V_5 ) ;
if ( ! V_64 )
return - V_70 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_67 = * ( V_71 * ) V_64 -> V_10 . V_13 ;
if ( V_67 < 3 ) {
F_10 ( L_15 , V_67 ) ;
F_6 ( V_64 ) ;
return - V_72 ;
}
V_67 = F_11 ( sizeof( V_137 ) , V_67 ) ;
memcpy ( & V_137 , V_64 -> V_10 . V_13 , V_67 ) ;
F_6 ( V_64 ) ;
switch ( V_137 . V_150 ) {
case V_151 :
default:
return - V_72 ;
case V_152 :
return 0 ;
case V_153 :
F_26 ( 10 ) ;
break;
}
}
return 0 ;
}
static int F_27 ( struct V_154 * V_155 ,
unsigned long V_156 ,
void * V_157 )
{
struct V_93 * V_94 = F_28 ( V_155 , struct V_93 , V_158 ) ;
struct V_95 * V_159 = (struct V_95 * ) V_157 ;
if ( strcmp ( V_159 -> V_97 , V_160 ) == 0 ) {
if ( F_29 () > 0 )
F_4 ( L_17 ) ;
else
F_4 ( L_18 ) ;
F_30 ( V_94 ) ;
}
return F_15 ( V_94 , V_159 ) ;
}
int F_31 ( struct V_93 * V_94 )
{
T_1 V_2 ;
struct V_62 * V_63 = & V_94 -> V_63 ;
struct V_127 * V_128 = & V_94 -> V_128 ;
int V_161 ;
V_2 = F_16 ( & V_94 -> V_101 -> V_102 ) ;
if ( ! V_94 -> V_162 || ! V_2 )
return 0 ;
V_161 = F_22 ( V_2 , V_128 ) ;
if ( V_161 ) {
F_4 ( L_19 , V_161 ) ;
}
V_161 = F_9 ( V_2 , V_63 ) ;
if ( V_161 ) {
F_4 ( L_20 , V_161 ) ;
goto V_73;
}
if ( V_63 -> V_75 . V_36 ) {
struct V_163 * V_164 ;
F_32 (tmp, &adev->ddev->mode_config.encoder_list,
head) {
struct V_104 * V_105 = F_33 ( V_164 ) ;
if ( ( V_105 -> V_165 & ( V_166 ) ) &&
V_105 -> V_109 ) {
if ( V_94 -> V_167 ) {
struct V_107 * V_108 = V_105 -> V_109 ;
if ( V_108 -> V_113 ) {
V_63 -> V_106 = V_105 ;
break;
}
}
}
}
}
if ( V_63 -> V_77 . V_44 && ! V_63 -> V_77 . V_42 ) {
V_63 -> V_77 . V_42 = true ;
}
if ( V_63 -> V_77 . V_42 ) {
V_161 = F_12 ( V_2 ,
& V_63 -> V_100 ) ;
if ( V_161 ) {
F_4 ( L_21 ,
V_161 ) ;
V_63 -> V_100 . V_86 = false ;
}
}
V_73:
V_94 -> V_158 . V_168 = F_27 ;
F_34 ( & V_94 -> V_158 ) ;
return V_161 ;
}
void F_35 ( struct V_93 * V_94 )
{
F_36 ( & V_94 -> V_158 ) ;
}
