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
if ( V_2 -> V_4 -> V_44 < 2 )
return;
F_3 ( & V_6 . V_32 , & V_2 -> V_17 ) ;
F_4 ( V_2 -> V_4 , V_45 , sizeof( V_6 ) , & V_6 ) ;
}
void F_12 ( struct V_1 * V_2 , T_1 V_46 )
{
struct V_47 V_6 ;
F_7 ( L_1 , V_2 ) ;
V_2 -> V_7 = V_48 ;
V_6 . V_49 = F_2 ( V_2 -> V_49 ) ;
V_6 . V_46 = V_46 ;
F_4 ( V_2 -> V_4 , V_50 , sizeof( V_6 ) , & V_6 ) ;
}
void F_13 ( struct V_1 * V_2 , T_2 V_49 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_51 V_6 ;
F_7 ( L_1 , V_2 ) ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = 1 ;
V_2 -> V_30 ++ ;
V_6 . V_49 = F_2 ( V_49 ) ;
V_6 . V_40 = F_2 ( V_2 -> V_40 ) ;
F_4 ( V_4 , V_52 , sizeof( V_6 ) , & V_6 ) ;
}
void F_14 ( struct V_1 * V_2 , T_2 V_49 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_53 V_6 ;
F_7 ( L_1 , V_2 ) ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = 1 ;
V_2 -> V_30 ++ ;
V_6 . V_49 = F_2 ( V_49 ) ;
V_6 . V_40 = F_2 ( V_2 -> V_40 ) ;
V_6 . V_54 = F_15 ( 0x00001f40 ) ;
V_6 . V_55 = F_15 ( 0x00001f40 ) ;
V_6 . V_56 = F_2 ( 0xffff ) ;
V_6 . V_57 = F_2 ( V_4 -> V_57 ) ;
V_6 . V_58 = 0xff ;
F_4 ( V_4 , V_59 , sizeof( V_6 ) , & V_6 ) ;
}
void F_16 ( struct V_1 * V_2 , T_3 V_60 , T_3 V_61 ,
T_3 V_62 , T_3 V_63 )
{
struct V_64 V_6 ;
struct V_3 * V_4 = V_2 -> V_4 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_49 = F_2 ( V_2 -> V_49 ) ;
V_6 . V_20 = F_2 ( V_60 ) ;
V_6 . V_21 = F_2 ( V_61 ) ;
V_6 . V_65 = F_2 ( V_62 ) ;
V_6 . V_22 = F_2 ( V_63 ) ;
V_6 . V_23 = F_2 ( 0x0001 ) ;
V_6 . V_24 = F_2 ( 0x0001 ) ;
F_4 ( V_4 , V_66 , sizeof( V_6 ) , & V_6 ) ;
}
void F_17 ( struct V_1 * V_2 , T_4 V_67 , T_1 rand [ 8 ] ,
T_1 V_68 [ 16 ] )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_69 V_6 ;
F_7 ( L_1 , V_2 ) ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_49 = F_2 ( V_2 -> V_49 ) ;
memcpy ( V_6 . V_68 , V_68 , sizeof( V_6 . V_68 ) ) ;
V_6 . V_67 = V_67 ;
memcpy ( V_6 . rand , rand , sizeof( V_6 . rand ) ) ;
F_4 ( V_4 , V_70 , sizeof( V_6 ) , & V_6 ) ;
}
void F_18 ( struct V_1 * V_2 , T_5 V_68 [ 16 ] )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_71 V_6 ;
F_7 ( L_1 , V_2 ) ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_49 = F_2 ( V_2 -> V_49 ) ;
memcpy ( V_6 . V_68 , V_68 , sizeof( V_68 ) ) ;
F_4 ( V_4 , V_72 , sizeof( V_6 ) , & V_6 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_73 V_6 ;
F_7 ( L_1 , V_2 ) ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_49 = F_2 ( V_2 -> V_49 ) ;
F_4 ( V_4 , V_74 , sizeof( V_6 ) , & V_6 ) ;
}
void F_20 ( struct V_1 * V_2 , T_1 V_75 )
{
struct V_1 * V_76 = V_2 -> V_77 ;
F_7 ( L_1 , V_2 ) ;
if ( ! V_76 )
return;
if ( ! V_75 ) {
if ( F_21 ( V_2 -> V_4 ) )
F_14 ( V_76 , V_2 -> V_49 ) ;
else
F_13 ( V_76 , V_2 -> V_49 ) ;
} else {
F_22 ( V_76 , V_75 ) ;
F_23 ( V_76 ) ;
}
}
static void F_24 ( unsigned long V_78 )
{
struct V_1 * V_2 = ( void * ) V_78 ;
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_46 ;
F_7 ( L_2 , V_2 , V_2 -> V_7 ) ;
if ( F_25 ( & V_2 -> V_79 ) )
return;
F_26 ( V_4 ) ;
switch ( V_2 -> V_7 ) {
case V_8 :
case V_80 :
if ( V_2 -> V_9 ) {
if ( V_2 -> type == V_81 )
F_11 ( V_2 ) ;
else if ( V_2 -> type == V_82 )
F_5 ( V_2 ) ;
}
break;
case V_83 :
case V_84 :
V_46 = F_27 ( V_2 ) ;
F_12 ( V_2 , V_46 ) ;
break;
default:
V_2 -> V_7 = V_85 ;
break;
}
F_28 ( V_4 ) ;
}
static void F_29 ( unsigned long V_78 )
{
struct V_1 * V_2 = ( void * ) V_78 ;
F_7 ( L_3 , V_2 , V_2 -> V_86 ) ;
F_30 ( V_2 ) ;
}
static void F_31 ( unsigned long V_78 )
{
struct V_1 * V_2 = ( void * ) V_78 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_26 ( V_4 ) ;
F_4 ( V_4 , V_87 , sizeof( V_2 -> V_17 ) ,
& V_2 -> V_17 ) ;
F_28 ( V_4 ) ;
}
struct V_1 * F_32 ( struct V_3 * V_4 , int type , T_6 * V_17 )
{
struct V_1 * V_2 ;
F_7 ( L_4 , V_4 -> V_88 , F_33 ( V_17 ) ) ;
V_2 = F_34 ( sizeof( struct V_1 ) , V_89 ) ;
if ( ! V_2 )
return NULL ;
F_3 ( & V_2 -> V_17 , V_17 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> type = type ;
V_2 -> V_86 = V_90 ;
V_2 -> V_7 = V_91 ;
V_2 -> V_92 = V_93 ;
V_2 -> V_94 = V_4 -> V_94 ;
V_2 -> V_95 = 0xff ;
V_2 -> V_96 = 0xff ;
V_2 -> V_97 = 1 ;
V_2 -> V_98 = V_99 ;
switch ( type ) {
case V_81 :
V_2 -> V_40 = V_4 -> V_40 & V_100 ;
break;
case V_101 :
if ( F_21 ( V_4 ) )
V_2 -> V_40 = ( V_4 -> V_102 & V_103 ) |
( V_4 -> V_102 & V_104 ) ;
else
V_2 -> V_40 = V_4 -> V_40 & V_105 ;
break;
case V_106 :
V_2 -> V_40 = V_4 -> V_102 & ~ V_104 ;
break;
}
F_35 ( & V_2 -> V_107 ) ;
F_36 ( & V_2 -> V_108 , F_24 , ( unsigned long ) V_2 ) ;
F_36 ( & V_2 -> V_109 , F_29 , ( unsigned long ) V_2 ) ;
F_36 ( & V_2 -> V_110 , F_31 ,
( unsigned long ) V_2 ) ;
F_37 ( & V_2 -> V_79 , 0 ) ;
F_38 ( V_4 ) ;
F_39 ( & V_4 -> V_111 ) ;
F_40 ( V_4 , V_2 ) ;
if ( V_4 -> V_112 )
V_4 -> V_112 ( V_4 , V_113 ) ;
F_37 ( & V_2 -> V_114 , 0 ) ;
F_41 ( V_2 ) ;
F_42 ( & V_4 -> V_111 ) ;
return V_2 ;
}
int F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_7 ( L_5 , V_4 -> V_88 , V_2 , V_2 -> V_49 ) ;
F_43 ( & V_2 -> V_109 ) ;
F_43 ( & V_2 -> V_108 ) ;
F_43 ( & V_2 -> V_110 ) ;
if ( V_2 -> type == V_81 ) {
struct V_1 * V_76 = V_2 -> V_77 ;
if ( V_76 )
V_76 -> V_77 = NULL ;
V_4 -> V_115 += V_2 -> V_116 ;
} else if ( V_2 -> type == V_82 ) {
if ( V_4 -> V_117 )
V_4 -> V_118 += V_2 -> V_116 ;
else
V_4 -> V_115 += V_2 -> V_116 ;
} else {
struct V_1 * V_119 = V_2 -> V_77 ;
if ( V_119 ) {
V_119 -> V_77 = NULL ;
F_44 ( V_119 ) ;
}
}
F_39 ( & V_4 -> V_111 ) ;
F_45 ( V_4 , V_2 ) ;
if ( V_4 -> V_112 )
V_4 -> V_112 ( V_4 , V_120 ) ;
F_42 ( & V_4 -> V_111 ) ;
F_46 ( & V_2 -> V_107 ) ;
F_47 ( V_2 ) ;
F_48 ( V_4 ) ;
if ( V_2 -> V_49 == 0 )
F_49 ( V_2 ) ;
return 0 ;
}
struct V_3 * F_50 ( T_6 * V_17 , T_6 * V_121 )
{
int V_122 = F_51 ( V_121 , V_123 ) ;
struct V_3 * V_4 = NULL ;
struct V_124 * V_125 ;
F_7 ( L_6 , F_33 ( V_121 ) , F_33 ( V_17 ) ) ;
F_52 ( & V_126 ) ;
F_53 (p, &hci_dev_list) {
struct V_3 * V_127 = F_54 ( V_125 , struct V_3 , V_128 ) ;
if ( ! F_55 ( V_129 , & V_127 -> V_130 ) || F_55 ( V_131 , & V_127 -> V_130 ) )
continue;
if ( V_122 ) {
if ( ! F_51 ( & V_127 -> V_32 , V_121 ) ) {
V_4 = V_127 ; break;
}
} else {
if ( F_51 ( & V_127 -> V_32 , V_17 ) ) {
V_4 = V_127 ; break;
}
}
}
if ( V_4 )
V_4 = F_38 ( V_4 ) ;
F_56 ( & V_126 ) ;
return V_4 ;
}
struct V_1 * F_57 ( struct V_3 * V_4 , int type , T_6 * V_17 , T_1 V_12 , T_1 V_92 )
{
struct V_1 * V_119 ;
struct V_1 * V_76 ;
struct V_1 * V_132 ;
F_7 ( L_4 , V_4 -> V_88 , F_33 ( V_17 ) ) ;
if ( type == V_82 ) {
struct V_133 * V_134 ;
V_132 = F_58 ( V_4 , V_82 , V_17 ) ;
if ( V_132 )
return F_59 ( - V_135 ) ;
V_134 = F_60 ( V_4 , V_17 ) ;
if ( ! V_134 )
return F_59 ( - V_136 ) ;
V_132 = F_32 ( V_4 , V_82 , V_17 ) ;
if ( ! V_132 )
return F_59 ( - V_137 ) ;
V_132 -> V_19 = V_134 -> V_138 ;
F_1 ( V_132 ) ;
F_61 ( V_132 ) ;
return V_132 ;
}
V_119 = F_58 ( V_4 , V_81 , V_17 ) ;
if ( ! V_119 ) {
V_119 = F_32 ( V_4 , V_81 , V_17 ) ;
if ( ! V_119 )
return NULL ;
}
F_61 ( V_119 ) ;
if ( V_119 -> V_7 == V_91 || V_119 -> V_7 == V_85 ) {
V_119 -> V_12 = V_13 ;
V_119 -> V_139 = V_12 ;
V_119 -> V_92 = V_92 ;
F_6 ( V_119 ) ;
}
if ( type == V_81 )
return V_119 ;
V_76 = F_58 ( V_4 , type , V_17 ) ;
if ( ! V_76 ) {
V_76 = F_32 ( V_4 , type , V_17 ) ;
if ( ! V_76 ) {
F_44 ( V_119 ) ;
return NULL ;
}
}
V_119 -> V_77 = V_76 ;
V_76 -> V_77 = V_119 ;
F_61 ( V_76 ) ;
if ( V_119 -> V_7 == V_84 &&
( V_76 -> V_7 == V_91 || V_76 -> V_7 == V_85 ) ) {
V_119 -> V_97 = 1 ;
F_62 ( V_119 , V_140 ) ;
if ( F_55 ( V_141 , & V_119 -> V_142 ) ) {
F_63 ( V_143 , & V_119 -> V_142 ) ;
return V_76 ;
}
F_20 ( V_119 , 0x00 ) ;
}
return V_76 ;
}
int F_64 ( struct V_1 * V_2 )
{
F_7 ( L_7 , V_2 ) ;
if ( V_2 -> V_39 > 0 && V_2 -> V_4 -> V_39 > 0 &&
! ( V_2 -> V_10 & V_144 ) )
return 0 ;
return 1 ;
}
static int F_65 ( struct V_1 * V_2 , T_1 V_12 , T_1 V_92 )
{
F_7 ( L_7 , V_2 ) ;
if ( V_2 -> V_139 > V_12 )
V_12 = V_2 -> V_139 ;
if ( V_12 > V_2 -> V_12 )
V_2 -> V_139 = V_12 ;
else if ( V_2 -> V_10 & V_145 )
return 1 ;
V_92 |= ( V_2 -> V_92 & 0x01 ) ;
V_2 -> V_92 = V_92 ;
if ( ! F_66 ( V_146 , & V_2 -> V_142 ) ) {
struct V_147 V_6 ;
V_6 . V_49 = F_2 ( V_2 -> V_49 ) ;
F_4 ( V_2 -> V_4 , V_148 ,
sizeof( V_6 ) , & V_6 ) ;
if ( V_2 -> V_96 != 0xff )
F_63 ( V_149 , & V_2 -> V_142 ) ;
}
return 0 ;
}
static void F_67 ( struct V_1 * V_2 )
{
F_7 ( L_7 , V_2 ) ;
if ( ! F_66 ( V_150 , & V_2 -> V_142 ) ) {
struct V_151 V_6 ;
V_6 . V_49 = F_2 ( V_2 -> V_49 ) ;
V_6 . V_152 = 0x01 ;
F_4 ( V_2 -> V_4 , V_153 , sizeof( V_6 ) ,
& V_6 ) ;
}
}
int F_68 ( struct V_1 * V_2 , T_1 V_12 , T_1 V_92 )
{
F_7 ( L_7 , V_2 ) ;
if ( V_12 == V_154 )
return 1 ;
if ( V_12 == V_13 &&
( ! V_2 -> V_39 || ! V_2 -> V_4 -> V_39 ) )
return 1 ;
if ( ! ( V_2 -> V_10 & V_145 ) )
goto V_155;
if ( V_2 -> V_96 == V_156 )
goto V_152;
if ( V_2 -> V_96 == V_157 &&
( V_12 == V_158 ||
V_12 == V_13 ) )
goto V_152;
if ( V_2 -> V_96 == V_159 &&
( V_12 != V_160 ||
V_2 -> V_161 == 16 ) )
goto V_152;
V_155:
if ( F_55 ( V_150 , & V_2 -> V_142 ) )
return 0 ;
if ( ! F_65 ( V_2 , V_12 , V_92 ) )
return 0 ;
V_152:
if ( V_2 -> V_10 & V_144 )
return 1 ;
F_67 ( V_2 ) ;
return 0 ;
}
int F_69 ( struct V_1 * V_2 , T_1 V_12 )
{
F_7 ( L_7 , V_2 ) ;
if ( V_12 != V_160 )
return 1 ;
if ( V_2 -> V_12 == V_160 )
return 1 ;
return 0 ;
}
int F_70 ( struct V_1 * V_2 )
{
F_7 ( L_7 , V_2 ) ;
if ( ! F_66 ( V_146 , & V_2 -> V_142 ) ) {
struct V_162 V_6 ;
V_6 . V_49 = F_2 ( V_2 -> V_49 ) ;
F_4 ( V_2 -> V_4 , V_163 ,
sizeof( V_6 ) , & V_6 ) ;
}
return 0 ;
}
int F_71 ( struct V_1 * V_2 , T_1 V_164 )
{
F_7 ( L_7 , V_2 ) ;
if ( ! V_164 && V_2 -> V_10 & V_11 )
return 1 ;
if ( ! F_66 ( V_165 , & V_2 -> V_142 ) ) {
struct V_166 V_6 ;
F_3 ( & V_6 . V_32 , & V_2 -> V_17 ) ;
V_6 . V_164 = V_164 ;
F_4 ( V_2 -> V_4 , V_167 , sizeof( V_6 ) , & V_6 ) ;
}
return 0 ;
}
void F_62 ( struct V_1 * V_2 , T_1 V_168 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_7 ( L_3 , V_2 , V_2 -> V_86 ) ;
if ( F_55 ( V_131 , & V_4 -> V_130 ) )
return;
if ( V_2 -> V_86 != V_169 )
goto V_170;
if ( ! V_2 -> V_97 && ! V_168 )
goto V_170;
if ( ! F_66 ( V_141 , & V_2 -> V_142 ) ) {
struct V_171 V_6 ;
V_6 . V_49 = F_2 ( V_2 -> V_49 ) ;
F_4 ( V_4 , V_172 , sizeof( V_6 ) , & V_6 ) ;
}
V_170:
if ( V_4 -> V_173 > 0 )
F_72 ( & V_2 -> V_109 ,
V_174 + F_73 ( V_4 -> V_173 ) ) ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_7 ( L_3 , V_2 , V_2 -> V_86 ) ;
if ( F_55 ( V_131 , & V_4 -> V_130 ) )
return;
if ( ! F_74 ( V_4 ) || ! F_74 ( V_2 ) )
return;
if ( V_2 -> V_86 != V_90 || ! ( V_2 -> V_31 & V_175 ) )
return;
if ( F_75 ( V_4 ) && F_75 ( V_2 ) ) {
struct V_176 V_6 ;
V_6 . V_49 = F_2 ( V_2 -> V_49 ) ;
V_6 . V_56 = F_2 ( 0 ) ;
V_6 . V_177 = F_2 ( 0 ) ;
V_6 . V_178 = F_2 ( 0 ) ;
F_4 ( V_4 , V_179 , sizeof( V_6 ) , & V_6 ) ;
}
if ( ! F_66 ( V_141 , & V_2 -> V_142 ) ) {
struct V_180 V_6 ;
V_6 . V_49 = F_2 ( V_2 -> V_49 ) ;
V_6 . V_181 = F_2 ( V_4 -> V_182 ) ;
V_6 . V_183 = F_2 ( V_4 -> V_184 ) ;
V_6 . V_30 = F_2 ( 4 ) ;
V_6 . V_185 = F_2 ( 1 ) ;
F_4 ( V_4 , V_186 , sizeof( V_6 ) , & V_6 ) ;
}
}
void F_76 ( struct V_3 * V_4 )
{
struct V_187 * V_188 = & V_4 -> V_189 ;
struct V_124 * V_125 ;
F_7 ( L_8 , V_4 -> V_88 ) ;
V_125 = V_188 -> V_128 . V_190 ;
while ( V_125 != & V_188 -> V_128 ) {
struct V_1 * V_191 ;
V_191 = F_54 ( V_125 , struct V_1 , V_128 ) ;
V_125 = V_125 -> V_190 ;
V_191 -> V_7 = V_85 ;
F_77 ( V_191 , 0x16 ) ;
F_23 ( V_191 ) ;
}
}
void F_78 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
F_7 ( L_8 , V_4 -> V_88 ) ;
F_26 ( V_4 ) ;
V_2 = F_79 ( V_4 , V_81 , V_80 ) ;
if ( V_2 )
F_6 ( V_2 ) ;
F_28 ( V_4 ) ;
}
void F_80 ( struct V_1 * V_2 )
{
F_81 ( & V_2 -> V_114 ) ;
}
void F_47 ( struct V_1 * V_2 )
{
if ( F_82 ( & V_2 -> V_114 ) )
F_83 ( V_2 ) ;
}
int F_84 ( void T_7 * V_78 )
{
struct V_192 V_193 , * V_194 ;
struct V_195 * V_196 ;
struct V_3 * V_4 ;
struct V_124 * V_125 ;
int V_197 = 0 , V_198 , V_199 ;
if ( F_85 ( & V_193 , V_78 , sizeof( V_193 ) ) )
return - V_200 ;
if ( ! V_193 . V_201 || V_193 . V_201 > ( V_202 * 2 ) / sizeof( * V_196 ) )
return - V_203 ;
V_198 = sizeof( V_193 ) + V_193 . V_201 * sizeof( * V_196 ) ;
V_194 = F_86 ( V_198 , V_204 ) ;
if ( ! V_194 )
return - V_137 ;
V_4 = F_87 ( V_193 . V_205 ) ;
if ( ! V_4 ) {
F_49 ( V_194 ) ;
return - V_206 ;
}
V_196 = V_194 -> V_207 ;
F_88 ( V_4 ) ;
F_53 (p, &hdev->conn_hash.list) {
register struct V_1 * V_191 ;
V_191 = F_54 ( V_125 , struct V_1 , V_128 ) ;
F_3 ( & ( V_196 + V_197 ) -> V_32 , & V_191 -> V_17 ) ;
( V_196 + V_197 ) -> V_49 = V_191 -> V_49 ;
( V_196 + V_197 ) -> type = V_191 -> type ;
( V_196 + V_197 ) -> V_9 = V_191 -> V_9 ;
( V_196 + V_197 ) -> V_7 = V_191 -> V_7 ;
( V_196 + V_197 ) -> V_10 = V_191 -> V_10 ;
if ( ++ V_197 >= V_193 . V_201 )
break;
}
F_89 ( V_4 ) ;
V_194 -> V_205 = V_4 -> V_208 ;
V_194 -> V_201 = V_197 ;
V_198 = sizeof( V_193 ) + V_197 * sizeof( * V_196 ) ;
F_48 ( V_4 ) ;
V_199 = F_90 ( V_78 , V_194 , V_198 ) ;
F_49 ( V_194 ) ;
return V_199 ? - V_200 : 0 ;
}
int F_91 ( struct V_3 * V_4 , void T_7 * V_78 )
{
struct V_209 V_193 ;
struct V_195 V_196 ;
struct V_1 * V_2 ;
char T_7 * V_210 = V_78 + sizeof( V_193 ) ;
if ( F_85 ( & V_193 , V_78 , sizeof( V_193 ) ) )
return - V_200 ;
F_88 ( V_4 ) ;
V_2 = F_58 ( V_4 , V_193 . type , & V_193 . V_32 ) ;
if ( V_2 ) {
F_3 ( & V_196 . V_32 , & V_2 -> V_17 ) ;
V_196 . V_49 = V_2 -> V_49 ;
V_196 . type = V_2 -> type ;
V_196 . V_9 = V_2 -> V_9 ;
V_196 . V_7 = V_2 -> V_7 ;
V_196 . V_10 = V_2 -> V_10 ;
}
F_89 ( V_4 ) ;
if ( ! V_2 )
return - V_211 ;
return F_90 ( V_210 , & V_196 , sizeof( V_196 ) ) ? - V_200 : 0 ;
}
int F_92 ( struct V_3 * V_4 , void T_7 * V_78 )
{
struct V_212 V_193 ;
struct V_1 * V_2 ;
if ( F_85 ( & V_193 , V_78 , sizeof( V_193 ) ) )
return - V_200 ;
F_88 ( V_4 ) ;
V_2 = F_58 ( V_4 , V_81 , & V_193 . V_32 ) ;
if ( V_2 )
V_193 . type = V_2 -> V_92 ;
F_89 ( V_4 ) ;
if ( ! V_2 )
return - V_211 ;
return F_90 ( V_78 , & V_193 , sizeof( V_193 ) ) ? - V_200 : 0 ;
}
