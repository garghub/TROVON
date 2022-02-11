static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 V_6 ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = true ;
V_2 -> V_10 |= V_11 ;
V_2 -> V_12 = V_13 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_14 = F_2 ( 0x0060 ) ;
V_6 . V_15 = F_2 ( 0x0030 ) ;
F_3 ( & V_6 . V_16 , & V_2 -> V_17 ) ;
V_6 . V_18 = V_2 -> V_19 ;
V_6 . V_20 = F_2 ( 0x0028 ) ;
V_6 . V_21 = F_2 ( 0x0038 ) ;
V_6 . V_22 = F_2 ( 0x002a ) ;
V_6 . V_23 = F_2 ( 0x0000 ) ;
V_6 . V_24 = F_2 ( 0x0000 ) ;
F_4 ( V_4 , V_25 , sizeof( V_6 ) , & V_6 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_4 , V_26 , 0 , NULL ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_27 * V_28 ;
struct V_29 V_6 ;
F_7 ( L_1 , V_2 ) ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = true ;
V_2 -> V_10 = V_11 ;
V_2 -> V_30 ++ ;
V_2 -> V_31 = V_4 -> V_31 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
F_3 ( & V_6 . V_32 , & V_2 -> V_17 ) ;
V_6 . V_33 = 0x02 ;
V_28 = F_8 ( V_4 , & V_2 -> V_17 ) ;
if ( V_28 ) {
if ( F_9 ( V_28 ) <= V_34 ) {
V_6 . V_33 = V_28 -> V_35 . V_33 ;
V_6 . V_36 = V_28 -> V_35 . V_36 ;
V_6 . V_37 = V_28 -> V_35 . V_37 |
F_2 ( 0x8000 ) ;
}
memcpy ( V_2 -> V_38 , V_28 -> V_35 . V_38 , 3 ) ;
if ( V_28 -> V_35 . V_39 > 0 )
F_10 ( V_40 , & V_2 -> V_41 ) ;
}
V_6 . V_42 = F_11 ( V_2 -> V_42 ) ;
if ( F_12 ( V_4 ) && ! ( V_4 -> V_10 & V_11 ) )
V_6 . V_43 = 0x01 ;
else
V_6 . V_43 = 0x00 ;
F_4 ( V_4 , V_44 , sizeof( V_6 ) , & V_6 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_45 V_6 ;
F_7 ( L_1 , V_2 ) ;
if ( V_2 -> V_4 -> V_46 < V_47 )
return;
F_3 ( & V_6 . V_32 , & V_2 -> V_17 ) ;
F_4 ( V_2 -> V_4 , V_48 , sizeof( V_6 ) , & V_6 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_49 V_6 ;
V_6 . V_50 = V_51 ;
F_3 ( & V_6 . V_32 , & V_2 -> V_17 ) ;
F_4 ( V_2 -> V_4 , V_52 , sizeof( V_6 ) , & V_6 ) ;
}
void F_15 ( struct V_1 * V_2 , T_1 V_50 )
{
struct V_53 V_6 ;
F_7 ( L_1 , V_2 ) ;
V_2 -> V_7 = V_54 ;
V_6 . V_55 = F_11 ( V_2 -> V_55 ) ;
V_6 . V_50 = V_50 ;
F_4 ( V_2 -> V_4 , V_56 , sizeof( V_6 ) , & V_6 ) ;
}
static void F_16 ( struct V_1 * V_2 , T_1 V_50 )
{
struct V_57 V_6 ;
F_7 ( L_1 , V_2 ) ;
V_2 -> V_7 = V_54 ;
V_6 . V_58 = F_17 ( V_2 -> V_55 ) ;
V_6 . V_50 = V_50 ;
F_4 ( V_2 -> V_4 , V_59 ,
sizeof( V_6 ) , & V_6 ) ;
}
static void F_18 ( struct V_1 * V_2 , T_2 V_55 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_60 V_6 ;
F_7 ( L_1 , V_2 ) ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = true ;
V_2 -> V_30 ++ ;
V_6 . V_55 = F_11 ( V_55 ) ;
V_6 . V_42 = F_11 ( V_2 -> V_42 ) ;
F_4 ( V_4 , V_61 , sizeof( V_6 ) , & V_6 ) ;
}
bool F_19 ( struct V_1 * V_2 , T_2 V_55 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_62 V_6 ;
const struct V_63 * V_64 ;
F_7 ( L_1 , V_2 ) ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = true ;
V_2 -> V_30 ++ ;
V_6 . V_55 = F_11 ( V_55 ) ;
V_6 . V_65 = F_20 ( 0x00001f40 ) ;
V_6 . V_66 = F_20 ( 0x00001f40 ) ;
V_6 . V_67 = F_11 ( V_2 -> V_68 ) ;
switch ( V_2 -> V_68 & V_69 ) {
case V_70 :
if ( V_2 -> V_30 > F_21 ( V_71 ) )
return false ;
V_6 . V_72 = 0x02 ;
V_64 = & V_71 [ V_2 -> V_30 - 1 ] ;
break;
case V_73 :
if ( V_2 -> V_30 > F_21 ( V_74 ) )
return false ;
V_6 . V_72 = 0x01 ;
V_64 = & V_74 [ V_2 -> V_30 - 1 ] ;
break;
default:
return false ;
}
V_6 . V_42 = F_22 ( V_64 -> V_42 ) ;
V_6 . V_75 = F_22 ( V_64 -> V_75 ) ;
if ( F_4 ( V_4 , V_76 , sizeof( V_6 ) , & V_6 ) < 0 )
return false ;
return true ;
}
void F_23 ( struct V_1 * V_2 , T_3 V_77 , T_3 V_78 ,
T_3 V_79 , T_3 V_80 )
{
struct V_81 V_6 ;
struct V_3 * V_4 = V_2 -> V_4 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_55 = F_11 ( V_2 -> V_55 ) ;
V_6 . V_20 = F_11 ( V_77 ) ;
V_6 . V_21 = F_11 ( V_78 ) ;
V_6 . V_82 = F_11 ( V_79 ) ;
V_6 . V_22 = F_11 ( V_80 ) ;
V_6 . V_23 = F_2 ( 0x0001 ) ;
V_6 . V_24 = F_2 ( 0x0001 ) ;
F_4 ( V_4 , V_83 , sizeof( V_6 ) , & V_6 ) ;
}
void F_24 ( struct V_1 * V_2 , T_4 V_84 , T_1 rand [ 8 ] ,
T_1 V_85 [ 16 ] )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_86 V_6 ;
F_7 ( L_1 , V_2 ) ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_55 = F_11 ( V_2 -> V_55 ) ;
memcpy ( V_6 . V_85 , V_85 , sizeof( V_6 . V_85 ) ) ;
V_6 . V_84 = V_84 ;
memcpy ( V_6 . rand , rand , sizeof( V_6 . rand ) ) ;
F_4 ( V_4 , V_87 , sizeof( V_6 ) , & V_6 ) ;
}
void F_25 ( struct V_1 * V_2 , T_1 V_88 )
{
struct V_1 * V_89 = V_2 -> V_90 ;
if ( ! V_89 )
return;
F_7 ( L_1 , V_2 ) ;
if ( ! V_88 ) {
if ( F_26 ( V_2 -> V_4 ) )
F_19 ( V_89 , V_2 -> V_55 ) ;
else
F_18 ( V_89 , V_2 -> V_55 ) ;
} else {
F_27 ( V_89 , V_88 ) ;
F_28 ( V_89 ) ;
}
}
static void F_29 ( struct V_1 * V_2 )
{
T_1 V_50 = F_30 ( V_2 ) ;
switch ( V_2 -> type ) {
case V_91 :
F_16 ( V_2 , V_50 ) ;
break;
default:
F_15 ( V_2 , V_50 ) ;
break;
}
}
static void F_31 ( struct V_92 * V_93 )
{
struct V_1 * V_2 = F_32 ( V_93 , struct V_1 ,
V_94 . V_93 ) ;
F_7 ( L_2 , V_2 , F_33 ( V_2 -> V_7 ) ) ;
if ( F_34 ( & V_2 -> V_95 ) )
return;
switch ( V_2 -> V_7 ) {
case V_8 :
case V_96 :
if ( V_2 -> V_9 ) {
if ( V_2 -> type == V_97 )
F_13 ( V_2 ) ;
else if ( V_2 -> type == V_98 )
F_5 ( V_2 ) ;
} else if ( V_2 -> type == V_99 || V_2 -> type == V_100 ) {
F_14 ( V_2 ) ;
}
break;
case V_101 :
case V_102 :
F_29 ( V_2 ) ;
break;
default:
V_2 -> V_7 = V_103 ;
break;
}
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_7 ( L_3 , V_2 , V_2 -> V_104 ) ;
if ( F_36 ( V_105 , & V_4 -> V_41 ) )
return;
if ( ! F_37 ( V_4 ) || ! F_37 ( V_2 ) )
return;
if ( V_2 -> V_104 != V_106 || ! ( V_2 -> V_31 & V_107 ) )
return;
if ( F_38 ( V_4 ) && F_38 ( V_2 ) ) {
struct V_108 V_6 ;
V_6 . V_55 = F_11 ( V_2 -> V_55 ) ;
V_6 . V_75 = F_2 ( 0 ) ;
V_6 . V_109 = F_2 ( 0 ) ;
V_6 . V_110 = F_2 ( 0 ) ;
F_4 ( V_4 , V_111 , sizeof( V_6 ) , & V_6 ) ;
}
if ( ! F_39 ( V_112 , & V_2 -> V_41 ) ) {
struct V_113 V_6 ;
V_6 . V_55 = F_11 ( V_2 -> V_55 ) ;
V_6 . V_114 = F_11 ( V_4 -> V_115 ) ;
V_6 . V_116 = F_11 ( V_4 -> V_117 ) ;
V_6 . V_30 = F_2 ( 4 ) ;
V_6 . V_118 = F_2 ( 1 ) ;
F_4 ( V_4 , V_119 , sizeof( V_6 ) , & V_6 ) ;
}
}
static void F_40 ( unsigned long V_120 )
{
struct V_1 * V_2 = ( void * ) V_120 ;
F_7 ( L_3 , V_2 , V_2 -> V_104 ) ;
F_35 ( V_2 ) ;
}
static void F_41 ( unsigned long V_120 )
{
struct V_1 * V_2 = ( void * ) V_120 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_4 ( V_4 , V_121 , sizeof( V_2 -> V_17 ) ,
& V_2 -> V_17 ) ;
}
struct V_1 * F_42 ( struct V_3 * V_4 , int type , T_5 * V_17 )
{
struct V_1 * V_2 ;
F_7 ( L_4 , V_4 -> V_122 , V_17 ) ;
V_2 = F_43 ( sizeof( struct V_1 ) , V_123 ) ;
if ( ! V_2 )
return NULL ;
F_3 ( & V_2 -> V_17 , V_17 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> type = type ;
V_2 -> V_104 = V_106 ;
V_2 -> V_7 = V_124 ;
V_2 -> V_125 = V_126 ;
V_2 -> V_127 = V_4 -> V_127 ;
V_2 -> V_128 = 0xff ;
V_2 -> V_129 = 0xff ;
F_10 ( V_130 , & V_2 -> V_41 ) ;
V_2 -> V_131 = V_132 ;
switch ( type ) {
case V_97 :
V_2 -> V_42 = V_4 -> V_42 & V_133 ;
break;
case V_99 :
if ( F_26 ( V_4 ) )
V_2 -> V_42 = ( V_4 -> V_134 & V_135 ) |
( V_4 -> V_134 & V_136 ) ;
else
V_2 -> V_42 = V_4 -> V_42 & V_137 ;
break;
case V_100 :
V_2 -> V_42 = V_4 -> V_134 & ~ V_136 ;
break;
}
F_44 ( & V_2 -> V_138 ) ;
F_45 ( & V_2 -> V_139 ) ;
F_46 ( & V_2 -> V_94 , F_31 ) ;
F_47 ( & V_2 -> V_140 , F_40 , ( unsigned long ) V_2 ) ;
F_47 ( & V_2 -> V_141 , F_41 ,
( unsigned long ) V_2 ) ;
F_48 ( & V_2 -> V_95 , 0 ) ;
F_49 ( V_4 ) ;
F_50 ( V_4 , V_2 ) ;
if ( V_4 -> V_142 )
V_4 -> V_142 ( V_4 , V_143 ) ;
F_51 ( V_2 ) ;
return V_2 ;
}
int F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_7 ( L_5 , V_4 -> V_122 , V_2 , V_2 -> V_55 ) ;
F_52 ( & V_2 -> V_140 ) ;
F_53 ( & V_2 -> V_94 ) ;
F_52 ( & V_2 -> V_141 ) ;
if ( V_2 -> type == V_97 ) {
struct V_1 * V_89 = V_2 -> V_90 ;
if ( V_89 )
V_89 -> V_90 = NULL ;
V_4 -> V_144 += V_2 -> V_145 ;
} else if ( V_2 -> type == V_98 ) {
if ( V_4 -> V_146 )
V_4 -> V_147 += V_2 -> V_145 ;
else
V_4 -> V_144 += V_2 -> V_145 ;
} else {
struct V_1 * V_148 = V_2 -> V_90 ;
if ( V_148 ) {
V_148 -> V_90 = NULL ;
F_54 ( V_148 ) ;
}
}
F_55 ( V_2 ) ;
if ( V_2 -> V_149 )
F_56 ( V_2 -> V_149 ) ;
F_57 ( V_4 , V_2 ) ;
if ( V_4 -> V_142 )
V_4 -> V_142 ( V_4 , V_150 ) ;
F_58 ( & V_2 -> V_138 ) ;
F_59 ( V_2 ) ;
F_60 ( V_4 ) ;
F_61 ( V_2 ) ;
return 0 ;
}
struct V_3 * F_62 ( T_5 * V_17 , T_5 * V_151 )
{
int V_152 = F_63 ( V_151 , V_153 ) ;
struct V_3 * V_4 = NULL , * V_154 ;
F_7 ( L_6 , V_151 , V_17 ) ;
F_64 ( & V_155 ) ;
F_65 (d, &hci_dev_list, list) {
if ( ! F_36 ( V_156 , & V_154 -> V_41 ) ||
F_36 ( V_105 , & V_154 -> V_41 ) ||
V_154 -> V_157 != V_158 )
continue;
if ( V_152 ) {
if ( ! F_63 ( & V_154 -> V_32 , V_151 ) ) {
V_4 = V_154 ; break;
}
} else {
if ( F_63 ( & V_154 -> V_32 , V_17 ) ) {
V_4 = V_154 ; break;
}
}
}
if ( V_4 )
V_4 = F_49 ( V_4 ) ;
F_66 ( & V_155 ) ;
return V_4 ;
}
static struct V_1 * F_67 ( struct V_3 * V_4 , T_5 * V_17 ,
T_6 V_19 , T_6 V_12 , T_6 V_125 )
{
struct V_1 * V_159 ;
if ( F_36 ( V_160 , & V_4 -> V_41 ) )
return F_68 ( - V_161 ) ;
V_159 = F_69 ( V_4 , V_98 , V_17 ) ;
if ( ! V_159 ) {
V_159 = F_70 ( V_4 , V_98 , V_8 ) ;
if ( V_159 )
return F_68 ( - V_162 ) ;
V_159 = F_42 ( V_4 , V_98 , V_17 ) ;
if ( ! V_159 )
return F_68 ( - V_163 ) ;
V_159 -> V_19 = F_71 ( V_19 ) ;
F_1 ( V_159 ) ;
}
V_159 -> V_164 = V_12 ;
V_159 -> V_125 = V_125 ;
F_72 ( V_159 ) ;
return V_159 ;
}
static struct V_1 * F_73 ( struct V_3 * V_4 , T_5 * V_17 ,
T_6 V_12 , T_6 V_125 )
{
struct V_1 * V_148 ;
V_148 = F_69 ( V_4 , V_97 , V_17 ) ;
if ( ! V_148 ) {
V_148 = F_42 ( V_4 , V_97 , V_17 ) ;
if ( ! V_148 )
return F_68 ( - V_163 ) ;
}
F_72 ( V_148 ) ;
if ( V_148 -> V_7 == V_124 || V_148 -> V_7 == V_103 ) {
V_148 -> V_12 = V_13 ;
V_148 -> V_164 = V_12 ;
V_148 -> V_125 = V_125 ;
F_6 ( V_148 ) ;
}
return V_148 ;
}
struct V_1 * F_74 ( struct V_3 * V_4 , int type , T_5 * V_17 ,
T_2 V_68 )
{
struct V_1 * V_148 ;
struct V_1 * V_89 ;
V_148 = F_73 ( V_4 , V_17 , V_13 , V_165 ) ;
if ( F_75 ( V_148 ) )
return V_148 ;
V_89 = F_69 ( V_4 , type , V_17 ) ;
if ( ! V_89 ) {
V_89 = F_42 ( V_4 , type , V_17 ) ;
if ( ! V_89 ) {
F_54 ( V_148 ) ;
return F_68 ( - V_163 ) ;
}
}
V_148 -> V_90 = V_89 ;
V_89 -> V_90 = V_148 ;
F_72 ( V_89 ) ;
V_89 -> V_68 = V_68 ;
if ( V_148 -> V_7 == V_102 &&
( V_89 -> V_7 == V_124 || V_89 -> V_7 == V_103 ) ) {
F_10 ( V_130 , & V_148 -> V_41 ) ;
F_76 ( V_148 , V_166 ) ;
if ( F_36 ( V_112 , & V_148 -> V_41 ) ) {
F_10 ( V_167 , & V_148 -> V_41 ) ;
return V_89 ;
}
F_25 ( V_148 , 0x00 ) ;
}
return V_89 ;
}
struct V_1 * F_77 ( struct V_3 * V_4 , int type , T_5 * V_17 ,
T_1 V_19 , T_1 V_12 , T_1 V_125 )
{
F_7 ( L_7 , V_4 -> V_122 , V_17 , type ) ;
switch ( type ) {
case V_98 :
return F_67 ( V_4 , V_17 , V_19 , V_12 , V_125 ) ;
case V_97 :
return F_73 ( V_4 , V_17 , V_12 , V_125 ) ;
}
return F_68 ( - V_168 ) ;
}
int F_78 ( struct V_1 * V_2 )
{
F_7 ( L_1 , V_2 ) ;
if ( F_79 ( V_2 ) && ! ( V_2 -> V_10 & V_169 ) )
return 0 ;
return 1 ;
}
static int F_80 ( struct V_1 * V_2 , T_1 V_12 , T_1 V_125 )
{
F_7 ( L_1 , V_2 ) ;
if ( V_2 -> V_164 > V_12 )
V_12 = V_2 -> V_164 ;
if ( V_12 > V_2 -> V_12 )
V_2 -> V_164 = V_12 ;
else if ( V_2 -> V_10 & V_170 )
return 1 ;
V_125 |= ( V_2 -> V_125 & 0x01 ) ;
V_2 -> V_125 = V_125 ;
if ( ! F_39 ( V_171 , & V_2 -> V_41 ) ) {
struct V_172 V_6 ;
F_10 ( V_173 , & V_2 -> V_41 ) ;
V_6 . V_55 = F_11 ( V_2 -> V_55 ) ;
F_4 ( V_2 -> V_4 , V_174 ,
sizeof( V_6 ) , & V_6 ) ;
if ( V_2 -> V_129 != 0xff )
F_10 ( V_175 , & V_2 -> V_41 ) ;
}
return 0 ;
}
static void F_81 ( struct V_1 * V_2 )
{
F_7 ( L_1 , V_2 ) ;
if ( ! F_39 ( V_173 , & V_2 -> V_41 ) ) {
struct V_176 V_6 ;
V_6 . V_55 = F_11 ( V_2 -> V_55 ) ;
V_6 . V_177 = 0x01 ;
F_4 ( V_2 -> V_4 , V_178 , sizeof( V_6 ) ,
& V_6 ) ;
}
}
int F_82 ( struct V_1 * V_2 , T_1 V_12 , T_1 V_125 )
{
F_7 ( L_1 , V_2 ) ;
if ( V_2 -> type == V_98 )
return F_83 ( V_2 , V_12 ) ;
if ( V_12 == V_179 )
return 1 ;
if ( V_12 == V_13 && ! F_79 ( V_2 ) )
return 1 ;
if ( ! ( V_2 -> V_10 & V_170 ) )
goto V_180;
if ( V_2 -> V_129 == V_181 )
goto V_177;
if ( V_2 -> V_129 == V_182 &&
( V_12 == V_183 || V_12 == V_13 ) )
goto V_177;
if ( V_2 -> V_129 == V_184 &&
( V_12 != V_185 || V_2 -> V_186 == 16 ) )
goto V_177;
V_180:
if ( F_36 ( V_173 , & V_2 -> V_41 ) )
return 0 ;
if ( ! F_80 ( V_2 , V_12 , V_125 ) )
return 0 ;
V_177:
if ( V_2 -> V_10 & V_169 )
return 1 ;
F_81 ( V_2 ) ;
return 0 ;
}
int F_84 ( struct V_1 * V_2 , T_1 V_12 )
{
F_7 ( L_1 , V_2 ) ;
if ( V_12 != V_185 )
return 1 ;
if ( V_2 -> V_12 == V_185 )
return 1 ;
return 0 ;
}
int F_85 ( struct V_1 * V_2 )
{
F_7 ( L_1 , V_2 ) ;
if ( ! F_39 ( V_171 , & V_2 -> V_41 ) ) {
struct V_187 V_6 ;
V_6 . V_55 = F_11 ( V_2 -> V_55 ) ;
F_4 ( V_2 -> V_4 , V_188 ,
sizeof( V_6 ) , & V_6 ) ;
}
return 0 ;
}
int F_86 ( struct V_1 * V_2 , T_1 V_189 )
{
F_7 ( L_1 , V_2 ) ;
if ( ! V_189 && V_2 -> V_10 & V_11 )
return 1 ;
if ( ! F_39 ( V_190 , & V_2 -> V_41 ) ) {
struct V_191 V_6 ;
F_3 ( & V_6 . V_32 , & V_2 -> V_17 ) ;
V_6 . V_189 = V_189 ;
F_4 ( V_2 -> V_4 , V_192 , sizeof( V_6 ) , & V_6 ) ;
}
return 0 ;
}
void F_76 ( struct V_1 * V_2 , T_1 V_193 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_7 ( L_3 , V_2 , V_2 -> V_104 ) ;
if ( F_36 ( V_105 , & V_4 -> V_41 ) )
return;
if ( V_2 -> V_104 != V_194 )
goto V_195;
if ( ! F_36 ( V_130 , & V_2 -> V_41 ) && ! V_193 )
goto V_195;
if ( ! F_39 ( V_112 , & V_2 -> V_41 ) ) {
struct V_196 V_6 ;
V_6 . V_55 = F_11 ( V_2 -> V_55 ) ;
F_4 ( V_4 , V_197 , sizeof( V_6 ) , & V_6 ) ;
}
V_195:
if ( V_4 -> V_198 > 0 )
F_87 ( & V_2 -> V_140 ,
V_199 + F_88 ( V_4 -> V_198 ) ) ;
}
void F_89 ( struct V_3 * V_4 )
{
struct V_200 * V_201 = & V_4 -> V_202 ;
struct V_1 * V_203 , * V_204 ;
F_7 ( L_8 , V_4 -> V_122 ) ;
F_90 (c, n, &h->list, list) {
V_203 -> V_7 = V_103 ;
F_91 ( V_203 , V_205 ) ;
F_28 ( V_203 ) ;
}
}
void F_92 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
F_7 ( L_8 , V_4 -> V_122 ) ;
F_93 ( V_4 ) ;
V_2 = F_70 ( V_4 , V_97 , V_96 ) ;
if ( V_2 )
F_6 ( V_2 ) ;
F_94 ( V_4 ) ;
}
int F_95 ( void T_7 * V_120 )
{
struct V_1 * V_203 ;
struct V_206 V_207 , * V_208 ;
struct V_209 * V_210 ;
struct V_3 * V_4 ;
int V_204 = 0 , V_211 , V_212 ;
if ( F_96 ( & V_207 , V_120 , sizeof( V_207 ) ) )
return - V_213 ;
if ( ! V_207 . V_214 || V_207 . V_214 > ( V_215 * 2 ) / sizeof( * V_210 ) )
return - V_168 ;
V_211 = sizeof( V_207 ) + V_207 . V_214 * sizeof( * V_210 ) ;
V_208 = F_97 ( V_211 , V_123 ) ;
if ( ! V_208 )
return - V_163 ;
V_4 = F_98 ( V_207 . V_216 ) ;
if ( ! V_4 ) {
F_99 ( V_208 ) ;
return - V_217 ;
}
V_210 = V_208 -> V_218 ;
F_93 ( V_4 ) ;
F_65 (c, &hdev->conn_hash.list, list) {
F_3 ( & ( V_210 + V_204 ) -> V_32 , & V_203 -> V_17 ) ;
( V_210 + V_204 ) -> V_55 = V_203 -> V_55 ;
( V_210 + V_204 ) -> type = V_203 -> type ;
( V_210 + V_204 ) -> V_9 = V_203 -> V_9 ;
( V_210 + V_204 ) -> V_7 = V_203 -> V_7 ;
( V_210 + V_204 ) -> V_10 = V_203 -> V_10 ;
if ( ++ V_204 >= V_207 . V_214 )
break;
}
F_94 ( V_4 ) ;
V_208 -> V_216 = V_4 -> V_219 ;
V_208 -> V_214 = V_204 ;
V_211 = sizeof( V_207 ) + V_204 * sizeof( * V_210 ) ;
F_60 ( V_4 ) ;
V_212 = F_100 ( V_120 , V_208 , V_211 ) ;
F_99 ( V_208 ) ;
return V_212 ? - V_213 : 0 ;
}
int F_101 ( struct V_3 * V_4 , void T_7 * V_120 )
{
struct V_220 V_207 ;
struct V_209 V_210 ;
struct V_1 * V_2 ;
char T_7 * V_221 = V_120 + sizeof( V_207 ) ;
if ( F_96 ( & V_207 , V_120 , sizeof( V_207 ) ) )
return - V_213 ;
F_93 ( V_4 ) ;
V_2 = F_69 ( V_4 , V_207 . type , & V_207 . V_32 ) ;
if ( V_2 ) {
F_3 ( & V_210 . V_32 , & V_2 -> V_17 ) ;
V_210 . V_55 = V_2 -> V_55 ;
V_210 . type = V_2 -> type ;
V_210 . V_9 = V_2 -> V_9 ;
V_210 . V_7 = V_2 -> V_7 ;
V_210 . V_10 = V_2 -> V_10 ;
}
F_94 ( V_4 ) ;
if ( ! V_2 )
return - V_222 ;
return F_100 ( V_221 , & V_210 , sizeof( V_210 ) ) ? - V_213 : 0 ;
}
int F_102 ( struct V_3 * V_4 , void T_7 * V_120 )
{
struct V_223 V_207 ;
struct V_1 * V_2 ;
if ( F_96 ( & V_207 , V_120 , sizeof( V_207 ) ) )
return - V_213 ;
F_93 ( V_4 ) ;
V_2 = F_69 ( V_4 , V_97 , & V_207 . V_32 ) ;
if ( V_2 )
V_207 . type = V_2 -> V_125 ;
F_94 ( V_4 ) ;
if ( ! V_2 )
return - V_222 ;
return F_100 ( V_120 , & V_207 , sizeof( V_207 ) ) ? - V_213 : 0 ;
}
struct V_224 * F_103 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_224 * V_225 ;
F_7 ( L_9 , V_4 -> V_122 , V_2 ) ;
V_225 = F_43 ( sizeof( struct V_224 ) , V_123 ) ;
if ( ! V_225 )
return NULL ;
V_225 -> V_2 = V_2 ;
F_44 ( & V_225 -> V_138 ) ;
V_225 -> V_7 = V_102 ;
F_104 ( & V_225 -> V_226 , & V_2 -> V_139 ) ;
return V_225 ;
}
void F_105 ( struct V_224 * V_225 )
{
struct V_1 * V_2 = V_225 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_7 ( L_10 , V_4 -> V_122 , V_2 , V_225 ) ;
F_106 ( & V_225 -> V_226 ) ;
F_107 () ;
F_54 ( V_2 ) ;
F_58 ( & V_225 -> V_138 ) ;
F_99 ( V_225 ) ;
}
void F_55 ( struct V_1 * V_2 )
{
struct V_224 * V_225 , * V_204 ;
F_7 ( L_1 , V_2 ) ;
F_90 (chan, n, &conn->chan_list, list)
F_105 ( V_225 ) ;
}
static struct V_224 * F_108 ( struct V_1 * V_227 ,
T_2 V_55 )
{
struct V_224 * V_228 ;
F_65 (hchan, &hcon->chan_list, list) {
if ( V_228 -> V_55 == V_55 )
return V_228 ;
}
return NULL ;
}
struct V_224 * F_109 ( struct V_3 * V_4 , T_2 V_55 )
{
struct V_200 * V_201 = & V_4 -> V_202 ;
struct V_1 * V_227 ;
struct V_224 * V_228 = NULL ;
F_110 () ;
F_111 (hcon, &h->list, list) {
V_228 = F_108 ( V_227 , V_55 ) ;
if ( V_228 )
break;
}
F_112 () ;
return V_228 ;
}
