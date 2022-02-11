static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 V_6 ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = 1 ;
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
void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_27 * V_28 ;
struct V_29 V_6 ;
F_7 ( L_1 , V_2 ) ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = 1 ;
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
V_2 -> V_39 = V_28 -> V_35 . V_39 ;
}
V_6 . V_40 = F_2 ( V_2 -> V_40 ) ;
if ( F_10 ( V_4 ) && ! ( V_4 -> V_10 & V_11 ) )
V_6 . V_41 = 0x01 ;
else
V_6 . V_41 = 0x00 ;
F_4 ( V_4 , V_42 , sizeof( V_6 ) , & V_6 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_43 V_6 ;
F_7 ( L_1 , V_2 ) ;
if ( V_2 -> V_4 -> V_44 < V_45 )
return;
F_3 ( & V_6 . V_32 , & V_2 -> V_17 ) ;
F_4 ( V_2 -> V_4 , V_46 , sizeof( V_6 ) , & V_6 ) ;
}
void F_12 ( struct V_1 * V_2 , T_1 V_47 )
{
struct V_48 V_6 ;
F_7 ( L_1 , V_2 ) ;
V_2 -> V_7 = V_49 ;
V_6 . V_50 = F_2 ( V_2 -> V_50 ) ;
V_6 . V_47 = V_47 ;
F_4 ( V_2 -> V_4 , V_51 , sizeof( V_6 ) , & V_6 ) ;
}
void F_13 ( struct V_1 * V_2 , T_2 V_50 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_52 V_6 ;
F_7 ( L_1 , V_2 ) ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = 1 ;
V_2 -> V_30 ++ ;
V_6 . V_50 = F_2 ( V_50 ) ;
V_6 . V_40 = F_2 ( V_2 -> V_40 ) ;
F_4 ( V_4 , V_53 , sizeof( V_6 ) , & V_6 ) ;
}
void F_14 ( struct V_1 * V_2 , T_2 V_50 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_54 V_6 ;
F_7 ( L_1 , V_2 ) ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = 1 ;
V_2 -> V_30 ++ ;
V_6 . V_50 = F_2 ( V_50 ) ;
V_6 . V_40 = F_2 ( V_2 -> V_40 ) ;
V_6 . V_55 = F_15 ( 0x00001f40 ) ;
V_6 . V_56 = F_15 ( 0x00001f40 ) ;
V_6 . V_57 = F_2 ( 0xffff ) ;
V_6 . V_58 = F_2 ( V_4 -> V_58 ) ;
V_6 . V_59 = 0xff ;
F_4 ( V_4 , V_60 , sizeof( V_6 ) , & V_6 ) ;
}
void F_16 ( struct V_1 * V_2 , T_3 V_61 , T_3 V_62 ,
T_3 V_63 , T_3 V_64 )
{
struct V_65 V_6 ;
struct V_3 * V_4 = V_2 -> V_4 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_50 = F_2 ( V_2 -> V_50 ) ;
V_6 . V_20 = F_2 ( V_61 ) ;
V_6 . V_21 = F_2 ( V_62 ) ;
V_6 . V_66 = F_2 ( V_63 ) ;
V_6 . V_22 = F_2 ( V_64 ) ;
V_6 . V_23 = F_2 ( 0x0001 ) ;
V_6 . V_24 = F_2 ( 0x0001 ) ;
F_4 ( V_4 , V_67 , sizeof( V_6 ) , & V_6 ) ;
}
void F_17 ( struct V_1 * V_2 , T_4 V_68 , T_1 rand [ 8 ] ,
T_1 V_69 [ 16 ] )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_70 V_6 ;
F_7 ( L_1 , V_2 ) ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_50 = F_2 ( V_2 -> V_50 ) ;
memcpy ( V_6 . V_69 , V_69 , sizeof( V_6 . V_69 ) ) ;
V_6 . V_68 = V_68 ;
memcpy ( V_6 . rand , rand , sizeof( V_6 . rand ) ) ;
F_4 ( V_4 , V_71 , sizeof( V_6 ) , & V_6 ) ;
}
void F_18 ( struct V_1 * V_2 , T_5 V_69 [ 16 ] )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_72 V_6 ;
F_7 ( L_1 , V_2 ) ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_50 = F_2 ( V_2 -> V_50 ) ;
memcpy ( V_6 . V_69 , V_69 , sizeof( V_69 ) ) ;
F_4 ( V_4 , V_73 , sizeof( V_6 ) , & V_6 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_74 V_6 ;
F_7 ( L_1 , V_2 ) ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_50 = F_2 ( V_2 -> V_50 ) ;
F_4 ( V_4 , V_75 , sizeof( V_6 ) , & V_6 ) ;
}
void F_20 ( struct V_1 * V_2 , T_1 V_76 )
{
struct V_1 * V_77 = V_2 -> V_78 ;
F_7 ( L_1 , V_2 ) ;
if ( ! V_77 )
return;
if ( ! V_76 ) {
if ( F_21 ( V_2 -> V_4 ) )
F_14 ( V_77 , V_2 -> V_50 ) ;
else
F_13 ( V_77 , V_2 -> V_50 ) ;
} else {
F_22 ( V_77 , V_76 ) ;
F_23 ( V_77 ) ;
}
}
static void F_24 ( struct V_79 * V_80 )
{
struct V_1 * V_2 = F_25 ( V_80 , struct V_1 ,
V_81 . V_80 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_47 ;
F_7 ( L_2 , V_2 , V_2 -> V_7 ) ;
if ( F_26 ( & V_2 -> V_82 ) )
return;
F_27 ( V_4 ) ;
switch ( V_2 -> V_7 ) {
case V_8 :
case V_83 :
if ( V_2 -> V_9 ) {
if ( V_2 -> type == V_84 )
F_11 ( V_2 ) ;
else if ( V_2 -> type == V_85 )
F_5 ( V_2 ) ;
}
break;
case V_86 :
case V_87 :
V_47 = F_28 ( V_2 ) ;
F_12 ( V_2 , V_47 ) ;
break;
default:
V_2 -> V_7 = V_88 ;
break;
}
F_29 ( V_4 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_7 ( L_3 , V_2 , V_2 -> V_89 ) ;
if ( F_31 ( V_90 , & V_4 -> V_91 ) )
return;
if ( ! F_32 ( V_4 ) || ! F_32 ( V_2 ) )
return;
if ( V_2 -> V_89 != V_92 || ! ( V_2 -> V_31 & V_93 ) )
return;
if ( F_33 ( V_4 ) && F_33 ( V_2 ) ) {
struct V_94 V_6 ;
V_6 . V_50 = F_2 ( V_2 -> V_50 ) ;
V_6 . V_57 = F_2 ( 0 ) ;
V_6 . V_95 = F_2 ( 0 ) ;
V_6 . V_96 = F_2 ( 0 ) ;
F_4 ( V_4 , V_97 , sizeof( V_6 ) , & V_6 ) ;
}
if ( ! F_34 ( V_98 , & V_2 -> V_99 ) ) {
struct V_100 V_6 ;
V_6 . V_50 = F_2 ( V_2 -> V_50 ) ;
V_6 . V_101 = F_2 ( V_4 -> V_102 ) ;
V_6 . V_103 = F_2 ( V_4 -> V_104 ) ;
V_6 . V_30 = F_2 ( 4 ) ;
V_6 . V_105 = F_2 ( 1 ) ;
F_4 ( V_4 , V_106 , sizeof( V_6 ) , & V_6 ) ;
}
}
static void F_35 ( unsigned long V_107 )
{
struct V_1 * V_2 = ( void * ) V_107 ;
F_7 ( L_3 , V_2 , V_2 -> V_89 ) ;
F_30 ( V_2 ) ;
}
static void F_36 ( unsigned long V_107 )
{
struct V_1 * V_2 = ( void * ) V_107 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_4 ( V_4 , V_108 , sizeof( V_2 -> V_17 ) ,
& V_2 -> V_17 ) ;
}
struct V_1 * F_37 ( struct V_3 * V_4 , int type , T_6 * V_17 )
{
struct V_1 * V_2 ;
F_7 ( L_4 , V_4 -> V_109 , F_38 ( V_17 ) ) ;
V_2 = F_39 ( sizeof( struct V_1 ) , V_110 ) ;
if ( ! V_2 )
return NULL ;
F_3 ( & V_2 -> V_17 , V_17 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> type = type ;
V_2 -> V_89 = V_92 ;
V_2 -> V_7 = V_111 ;
V_2 -> V_112 = V_113 ;
V_2 -> V_114 = V_4 -> V_114 ;
V_2 -> V_115 = 0xff ;
V_2 -> V_116 = 0xff ;
V_2 -> V_117 = 1 ;
V_2 -> V_118 = V_119 ;
switch ( type ) {
case V_84 :
V_2 -> V_40 = V_4 -> V_40 & V_120 ;
break;
case V_121 :
if ( F_21 ( V_4 ) )
V_2 -> V_40 = ( V_4 -> V_122 & V_123 ) |
( V_4 -> V_122 & V_124 ) ;
else
V_2 -> V_40 = V_4 -> V_40 & V_125 ;
break;
case V_126 :
V_2 -> V_40 = V_4 -> V_122 & ~ V_124 ;
break;
}
F_40 ( & V_2 -> V_127 ) ;
F_41 ( & V_2 -> V_128 ) ; ;
F_42 ( & V_2 -> V_81 , F_24 ) ;
F_43 ( & V_2 -> V_129 , F_35 , ( unsigned long ) V_2 ) ;
F_43 ( & V_2 -> V_130 , F_36 ,
( unsigned long ) V_2 ) ;
F_44 ( & V_2 -> V_82 , 0 ) ;
F_45 ( V_4 ) ;
F_46 ( V_4 , V_2 ) ;
if ( V_4 -> V_131 )
V_4 -> V_131 ( V_4 , V_132 ) ;
F_44 ( & V_2 -> V_133 , 0 ) ;
F_47 ( V_2 ) ;
return V_2 ;
}
int F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_7 ( L_5 , V_4 -> V_109 , V_2 , V_2 -> V_50 ) ;
F_48 ( & V_2 -> V_129 ) ;
F_49 ( & V_2 -> V_81 ) ;
F_48 ( & V_2 -> V_130 ) ;
if ( V_2 -> type == V_84 ) {
struct V_1 * V_77 = V_2 -> V_78 ;
if ( V_77 )
V_77 -> V_78 = NULL ;
V_4 -> V_134 += V_2 -> V_135 ;
} else if ( V_2 -> type == V_85 ) {
if ( V_4 -> V_136 )
V_4 -> V_137 += V_2 -> V_135 ;
else
V_4 -> V_134 += V_2 -> V_135 ;
} else {
struct V_1 * V_138 = V_2 -> V_78 ;
if ( V_138 ) {
V_138 -> V_78 = NULL ;
F_50 ( V_138 ) ;
}
}
F_51 ( V_2 ) ;
F_52 ( V_4 , V_2 ) ;
if ( V_4 -> V_131 )
V_4 -> V_131 ( V_4 , V_139 ) ;
F_53 ( & V_2 -> V_127 ) ;
F_54 ( V_2 ) ;
F_55 ( V_4 ) ;
if ( V_2 -> V_50 == 0 )
F_56 ( V_2 ) ;
return 0 ;
}
struct V_3 * F_57 ( T_6 * V_17 , T_6 * V_140 )
{
int V_141 = F_58 ( V_140 , V_142 ) ;
struct V_3 * V_4 = NULL , * V_143 ;
F_7 ( L_6 , F_38 ( V_140 ) , F_38 ( V_17 ) ) ;
F_59 ( & V_144 ) ;
F_60 (d, &hci_dev_list, list) {
if ( ! F_31 ( V_145 , & V_143 -> V_91 ) || F_31 ( V_90 , & V_143 -> V_91 ) )
continue;
if ( V_141 ) {
if ( ! F_58 ( & V_143 -> V_32 , V_140 ) ) {
V_4 = V_143 ; break;
}
} else {
if ( F_58 ( & V_143 -> V_32 , V_17 ) ) {
V_4 = V_143 ; break;
}
}
}
if ( V_4 )
V_4 = F_45 ( V_4 ) ;
F_61 ( & V_144 ) ;
return V_4 ;
}
struct V_1 * F_62 ( struct V_3 * V_4 , int type , T_6 * V_17 , T_1 V_12 , T_1 V_112 )
{
struct V_1 * V_138 ;
struct V_1 * V_77 ;
struct V_1 * V_146 ;
F_7 ( L_4 , V_4 -> V_109 , F_38 ( V_17 ) ) ;
if ( type == V_85 ) {
struct V_147 * V_148 ;
V_146 = F_63 ( V_4 , V_85 , V_17 ) ;
if ( V_146 )
return F_64 ( - V_149 ) ;
V_148 = F_65 ( V_4 , V_17 ) ;
if ( ! V_148 )
return F_64 ( - V_150 ) ;
V_146 = F_37 ( V_4 , V_85 , V_17 ) ;
if ( ! V_146 )
return F_64 ( - V_151 ) ;
V_146 -> V_19 = V_148 -> V_152 ;
F_1 ( V_146 ) ;
F_66 ( V_146 ) ;
return V_146 ;
}
V_138 = F_63 ( V_4 , V_84 , V_17 ) ;
if ( ! V_138 ) {
V_138 = F_37 ( V_4 , V_84 , V_17 ) ;
if ( ! V_138 )
return NULL ;
}
F_66 ( V_138 ) ;
if ( V_138 -> V_7 == V_111 || V_138 -> V_7 == V_88 ) {
V_138 -> V_12 = V_13 ;
V_138 -> V_153 = V_12 ;
V_138 -> V_112 = V_112 ;
F_6 ( V_138 ) ;
}
if ( type == V_84 )
return V_138 ;
V_77 = F_63 ( V_4 , type , V_17 ) ;
if ( ! V_77 ) {
V_77 = F_37 ( V_4 , type , V_17 ) ;
if ( ! V_77 ) {
F_50 ( V_138 ) ;
return NULL ;
}
}
V_138 -> V_78 = V_77 ;
V_77 -> V_78 = V_138 ;
F_66 ( V_77 ) ;
if ( V_138 -> V_7 == V_87 &&
( V_77 -> V_7 == V_111 || V_77 -> V_7 == V_88 ) ) {
V_138 -> V_117 = 1 ;
F_67 ( V_138 , V_154 ) ;
if ( F_31 ( V_98 , & V_138 -> V_99 ) ) {
F_68 ( V_155 , & V_138 -> V_99 ) ;
return V_77 ;
}
F_20 ( V_138 , 0x00 ) ;
}
return V_77 ;
}
int F_69 ( struct V_1 * V_2 )
{
F_7 ( L_7 , V_2 ) ;
if ( V_2 -> V_39 > 0 && V_2 -> V_4 -> V_39 > 0 &&
! ( V_2 -> V_10 & V_156 ) )
return 0 ;
return 1 ;
}
static int F_70 ( struct V_1 * V_2 , T_1 V_12 , T_1 V_112 )
{
F_7 ( L_7 , V_2 ) ;
if ( V_2 -> V_153 > V_12 )
V_12 = V_2 -> V_153 ;
if ( V_12 > V_2 -> V_12 )
V_2 -> V_153 = V_12 ;
else if ( V_2 -> V_10 & V_157 )
return 1 ;
V_112 |= ( V_2 -> V_112 & 0x01 ) ;
V_2 -> V_112 = V_112 ;
if ( ! F_34 ( V_158 , & V_2 -> V_99 ) ) {
struct V_159 V_6 ;
F_68 ( V_160 , & V_2 -> V_99 ) ;
V_6 . V_50 = F_2 ( V_2 -> V_50 ) ;
F_4 ( V_2 -> V_4 , V_161 ,
sizeof( V_6 ) , & V_6 ) ;
if ( V_2 -> V_116 != 0xff )
F_68 ( V_162 , & V_2 -> V_99 ) ;
}
return 0 ;
}
static void F_71 ( struct V_1 * V_2 )
{
F_7 ( L_7 , V_2 ) ;
if ( ! F_34 ( V_160 , & V_2 -> V_99 ) ) {
struct V_163 V_6 ;
V_6 . V_50 = F_2 ( V_2 -> V_50 ) ;
V_6 . V_164 = 0x01 ;
F_4 ( V_2 -> V_4 , V_165 , sizeof( V_6 ) ,
& V_6 ) ;
}
}
int F_72 ( struct V_1 * V_2 , T_1 V_12 , T_1 V_112 )
{
F_7 ( L_7 , V_2 ) ;
if ( V_12 == V_166 )
return 1 ;
if ( V_12 == V_13 &&
( ! V_2 -> V_39 || ! V_2 -> V_4 -> V_39 ) )
return 1 ;
if ( ! ( V_2 -> V_10 & V_157 ) )
goto V_167;
if ( V_2 -> V_116 == V_168 )
goto V_164;
if ( V_2 -> V_116 == V_169 &&
( V_12 == V_170 ||
V_12 == V_13 ) )
goto V_164;
if ( V_2 -> V_116 == V_171 &&
( V_12 != V_172 ||
V_2 -> V_173 == 16 ) )
goto V_164;
V_167:
if ( F_31 ( V_160 , & V_2 -> V_99 ) )
return 0 ;
if ( ! F_70 ( V_2 , V_12 , V_112 ) )
return 0 ;
V_164:
if ( V_2 -> V_10 & V_156 )
return 1 ;
F_71 ( V_2 ) ;
return 0 ;
}
int F_73 ( struct V_1 * V_2 , T_1 V_12 )
{
F_7 ( L_7 , V_2 ) ;
if ( V_12 != V_172 )
return 1 ;
if ( V_2 -> V_12 == V_172 )
return 1 ;
return 0 ;
}
int F_74 ( struct V_1 * V_2 )
{
F_7 ( L_7 , V_2 ) ;
if ( ! F_34 ( V_158 , & V_2 -> V_99 ) ) {
struct V_174 V_6 ;
V_6 . V_50 = F_2 ( V_2 -> V_50 ) ;
F_4 ( V_2 -> V_4 , V_175 ,
sizeof( V_6 ) , & V_6 ) ;
}
return 0 ;
}
int F_75 ( struct V_1 * V_2 , T_1 V_176 )
{
F_7 ( L_7 , V_2 ) ;
if ( ! V_176 && V_2 -> V_10 & V_11 )
return 1 ;
if ( ! F_34 ( V_177 , & V_2 -> V_99 ) ) {
struct V_178 V_6 ;
F_3 ( & V_6 . V_32 , & V_2 -> V_17 ) ;
V_6 . V_176 = V_176 ;
F_4 ( V_2 -> V_4 , V_179 , sizeof( V_6 ) , & V_6 ) ;
}
return 0 ;
}
void F_67 ( struct V_1 * V_2 , T_1 V_180 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_7 ( L_3 , V_2 , V_2 -> V_89 ) ;
if ( F_31 ( V_90 , & V_4 -> V_91 ) )
return;
if ( V_2 -> V_89 != V_181 )
goto V_182;
if ( ! V_2 -> V_117 && ! V_180 )
goto V_182;
if ( ! F_34 ( V_98 , & V_2 -> V_99 ) ) {
struct V_183 V_6 ;
V_6 . V_50 = F_2 ( V_2 -> V_50 ) ;
F_4 ( V_4 , V_184 , sizeof( V_6 ) , & V_6 ) ;
}
V_182:
if ( V_4 -> V_185 > 0 )
F_76 ( & V_2 -> V_129 ,
V_186 + F_77 ( V_4 -> V_185 ) ) ;
}
void F_78 ( struct V_3 * V_4 )
{
struct V_187 * V_188 = & V_4 -> V_189 ;
struct V_1 * V_190 ;
F_7 ( L_8 , V_4 -> V_109 ) ;
F_79 (c, &h->list, list) {
V_190 -> V_7 = V_88 ;
F_80 ( V_190 , V_191 ) ;
F_23 ( V_190 ) ;
}
}
void F_81 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
F_7 ( L_8 , V_4 -> V_109 ) ;
F_27 ( V_4 ) ;
V_2 = F_82 ( V_4 , V_84 , V_83 ) ;
if ( V_2 )
F_6 ( V_2 ) ;
F_29 ( V_4 ) ;
}
void F_83 ( struct V_1 * V_2 )
{
F_84 ( & V_2 -> V_133 ) ;
}
void F_54 ( struct V_1 * V_2 )
{
if ( F_85 ( & V_2 -> V_133 ) )
F_86 ( V_2 ) ;
}
int F_87 ( void T_7 * V_107 )
{
register struct V_1 * V_190 ;
struct V_192 V_193 , * V_194 ;
struct V_195 * V_196 ;
struct V_3 * V_4 ;
int V_197 = 0 , V_198 , V_199 ;
if ( F_88 ( & V_193 , V_107 , sizeof( V_193 ) ) )
return - V_200 ;
if ( ! V_193 . V_201 || V_193 . V_201 > ( V_202 * 2 ) / sizeof( * V_196 ) )
return - V_203 ;
V_198 = sizeof( V_193 ) + V_193 . V_201 * sizeof( * V_196 ) ;
V_194 = F_89 ( V_198 , V_204 ) ;
if ( ! V_194 )
return - V_151 ;
V_4 = F_90 ( V_193 . V_205 ) ;
if ( ! V_4 ) {
F_56 ( V_194 ) ;
return - V_206 ;
}
V_196 = V_194 -> V_207 ;
F_27 ( V_4 ) ;
F_60 (c, &hdev->conn_hash.list, list) {
F_3 ( & ( V_196 + V_197 ) -> V_32 , & V_190 -> V_17 ) ;
( V_196 + V_197 ) -> V_50 = V_190 -> V_50 ;
( V_196 + V_197 ) -> type = V_190 -> type ;
( V_196 + V_197 ) -> V_9 = V_190 -> V_9 ;
( V_196 + V_197 ) -> V_7 = V_190 -> V_7 ;
( V_196 + V_197 ) -> V_10 = V_190 -> V_10 ;
if ( ++ V_197 >= V_193 . V_201 )
break;
}
F_29 ( V_4 ) ;
V_194 -> V_205 = V_4 -> V_208 ;
V_194 -> V_201 = V_197 ;
V_198 = sizeof( V_193 ) + V_197 * sizeof( * V_196 ) ;
F_55 ( V_4 ) ;
V_199 = F_91 ( V_107 , V_194 , V_198 ) ;
F_56 ( V_194 ) ;
return V_199 ? - V_200 : 0 ;
}
int F_92 ( struct V_3 * V_4 , void T_7 * V_107 )
{
struct V_209 V_193 ;
struct V_195 V_196 ;
struct V_1 * V_2 ;
char T_7 * V_210 = V_107 + sizeof( V_193 ) ;
if ( F_88 ( & V_193 , V_107 , sizeof( V_193 ) ) )
return - V_200 ;
F_27 ( V_4 ) ;
V_2 = F_63 ( V_4 , V_193 . type , & V_193 . V_32 ) ;
if ( V_2 ) {
F_3 ( & V_196 . V_32 , & V_2 -> V_17 ) ;
V_196 . V_50 = V_2 -> V_50 ;
V_196 . type = V_2 -> type ;
V_196 . V_9 = V_2 -> V_9 ;
V_196 . V_7 = V_2 -> V_7 ;
V_196 . V_10 = V_2 -> V_10 ;
}
F_29 ( V_4 ) ;
if ( ! V_2 )
return - V_211 ;
return F_91 ( V_210 , & V_196 , sizeof( V_196 ) ) ? - V_200 : 0 ;
}
int F_93 ( struct V_3 * V_4 , void T_7 * V_107 )
{
struct V_212 V_193 ;
struct V_1 * V_2 ;
if ( F_88 ( & V_193 , V_107 , sizeof( V_193 ) ) )
return - V_200 ;
F_27 ( V_4 ) ;
V_2 = F_63 ( V_4 , V_84 , & V_193 . V_32 ) ;
if ( V_2 )
V_193 . type = V_2 -> V_112 ;
F_29 ( V_4 ) ;
if ( ! V_2 )
return - V_211 ;
return F_91 ( V_107 , & V_193 , sizeof( V_193 ) ) ? - V_200 : 0 ;
}
struct V_213 * F_94 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_213 * V_214 ;
F_7 ( L_9 , V_4 -> V_109 , V_2 ) ;
V_214 = F_39 ( sizeof( struct V_213 ) , V_110 ) ;
if ( ! V_214 )
return NULL ;
V_214 -> V_2 = V_2 ;
F_40 ( & V_214 -> V_127 ) ;
F_95 ( & V_214 -> V_215 , & V_2 -> V_128 ) ;
return V_214 ;
}
int F_96 ( struct V_213 * V_214 )
{
struct V_1 * V_2 = V_214 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_7 ( L_10 , V_4 -> V_109 , V_2 , V_214 ) ;
F_97 ( & V_214 -> V_215 ) ;
F_98 () ;
F_53 ( & V_214 -> V_127 ) ;
F_56 ( V_214 ) ;
return 0 ;
}
void F_51 ( struct V_1 * V_2 )
{
struct V_213 * V_214 ;
F_7 ( L_7 , V_2 ) ;
F_79 (chan, &conn->chan_list, list)
F_96 ( V_214 ) ;
}
