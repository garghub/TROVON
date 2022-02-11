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
void F_6 ( struct V_1 * V_2 )
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
void F_14 ( struct V_1 * V_2 , T_1 V_49 )
{
struct V_50 V_6 ;
F_7 ( L_1 , V_2 ) ;
V_2 -> V_7 = V_51 ;
V_6 . V_52 = F_11 ( V_2 -> V_52 ) ;
V_6 . V_49 = V_49 ;
F_4 ( V_2 -> V_4 , V_53 , sizeof( V_6 ) , & V_6 ) ;
}
void F_15 ( struct V_1 * V_2 , T_2 V_52 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_54 V_6 ;
F_7 ( L_1 , V_2 ) ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = true ;
V_2 -> V_30 ++ ;
V_6 . V_52 = F_11 ( V_52 ) ;
V_6 . V_42 = F_11 ( V_2 -> V_42 ) ;
F_4 ( V_4 , V_55 , sizeof( V_6 ) , & V_6 ) ;
}
void F_16 ( struct V_1 * V_2 , T_2 V_52 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_56 V_6 ;
F_7 ( L_1 , V_2 ) ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = true ;
V_2 -> V_30 ++ ;
V_6 . V_52 = F_11 ( V_52 ) ;
V_6 . V_42 = F_11 ( V_2 -> V_42 ) ;
V_6 . V_57 = F_17 ( 0x00001f40 ) ;
V_6 . V_58 = F_17 ( 0x00001f40 ) ;
V_6 . V_59 = F_2 ( 0xffff ) ;
V_6 . V_60 = F_11 ( V_4 -> V_60 ) ;
V_6 . V_61 = 0xff ;
F_4 ( V_4 , V_62 , sizeof( V_6 ) , & V_6 ) ;
}
void F_18 ( struct V_1 * V_2 , T_3 V_63 , T_3 V_64 ,
T_3 V_65 , T_3 V_66 )
{
struct V_67 V_6 ;
struct V_3 * V_4 = V_2 -> V_4 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_52 = F_11 ( V_2 -> V_52 ) ;
V_6 . V_20 = F_11 ( V_63 ) ;
V_6 . V_21 = F_11 ( V_64 ) ;
V_6 . V_68 = F_11 ( V_65 ) ;
V_6 . V_22 = F_11 ( V_66 ) ;
V_6 . V_23 = F_2 ( 0x0001 ) ;
V_6 . V_24 = F_2 ( 0x0001 ) ;
F_4 ( V_4 , V_69 , sizeof( V_6 ) , & V_6 ) ;
}
void F_19 ( struct V_1 * V_2 , T_4 V_70 , T_1 rand [ 8 ] ,
T_1 V_71 [ 16 ] )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_72 V_6 ;
F_7 ( L_1 , V_2 ) ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_52 = F_11 ( V_2 -> V_52 ) ;
memcpy ( V_6 . V_71 , V_71 , sizeof( V_6 . V_71 ) ) ;
V_6 . V_70 = V_70 ;
memcpy ( V_6 . rand , rand , sizeof( V_6 . rand ) ) ;
F_4 ( V_4 , V_73 , sizeof( V_6 ) , & V_6 ) ;
}
void F_20 ( struct V_1 * V_2 , T_1 V_74 )
{
struct V_1 * V_75 = V_2 -> V_76 ;
if ( ! V_75 )
return;
F_7 ( L_1 , V_2 ) ;
if ( ! V_74 ) {
if ( F_21 ( V_2 -> V_4 ) )
F_16 ( V_75 , V_2 -> V_52 ) ;
else
F_15 ( V_75 , V_2 -> V_52 ) ;
} else {
F_22 ( V_75 , V_74 ) ;
F_23 ( V_75 ) ;
}
}
static void F_24 ( struct V_77 * V_78 )
{
struct V_1 * V_2 = F_25 ( V_78 , struct V_1 ,
V_79 . V_78 ) ;
T_1 V_49 ;
F_7 ( L_2 , V_2 , F_26 ( V_2 -> V_7 ) ) ;
if ( F_27 ( & V_2 -> V_80 ) )
return;
switch ( V_2 -> V_7 ) {
case V_8 :
case V_81 :
if ( V_2 -> V_9 ) {
if ( V_2 -> type == V_82 )
F_13 ( V_2 ) ;
else if ( V_2 -> type == V_83 )
F_5 ( V_2 ) ;
}
break;
case V_84 :
case V_85 :
V_49 = F_28 ( V_2 ) ;
F_14 ( V_2 , V_49 ) ;
break;
default:
V_2 -> V_7 = V_86 ;
break;
}
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_7 ( L_3 , V_2 , V_2 -> V_87 ) ;
if ( F_30 ( V_88 , & V_4 -> V_41 ) )
return;
if ( ! F_31 ( V_4 ) || ! F_31 ( V_2 ) )
return;
if ( V_2 -> V_87 != V_89 || ! ( V_2 -> V_31 & V_90 ) )
return;
if ( F_32 ( V_4 ) && F_32 ( V_2 ) ) {
struct V_91 V_6 ;
V_6 . V_52 = F_11 ( V_2 -> V_52 ) ;
V_6 . V_59 = F_2 ( 0 ) ;
V_6 . V_92 = F_2 ( 0 ) ;
V_6 . V_93 = F_2 ( 0 ) ;
F_4 ( V_4 , V_94 , sizeof( V_6 ) , & V_6 ) ;
}
if ( ! F_33 ( V_95 , & V_2 -> V_41 ) ) {
struct V_96 V_6 ;
V_6 . V_52 = F_11 ( V_2 -> V_52 ) ;
V_6 . V_97 = F_11 ( V_4 -> V_98 ) ;
V_6 . V_99 = F_11 ( V_4 -> V_100 ) ;
V_6 . V_30 = F_2 ( 4 ) ;
V_6 . V_101 = F_2 ( 1 ) ;
F_4 ( V_4 , V_102 , sizeof( V_6 ) , & V_6 ) ;
}
}
static void F_34 ( unsigned long V_103 )
{
struct V_1 * V_2 = ( void * ) V_103 ;
F_7 ( L_3 , V_2 , V_2 -> V_87 ) ;
F_29 ( V_2 ) ;
}
static void F_35 ( unsigned long V_103 )
{
struct V_1 * V_2 = ( void * ) V_103 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_4 ( V_4 , V_104 , sizeof( V_2 -> V_17 ) ,
& V_2 -> V_17 ) ;
}
struct V_1 * F_36 ( struct V_3 * V_4 , int type , T_5 * V_17 )
{
struct V_1 * V_2 ;
F_7 ( L_4 , V_4 -> V_105 , F_37 ( V_17 ) ) ;
V_2 = F_38 ( sizeof( struct V_1 ) , V_106 ) ;
if ( ! V_2 )
return NULL ;
F_3 ( & V_2 -> V_17 , V_17 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> type = type ;
V_2 -> V_87 = V_89 ;
V_2 -> V_7 = V_107 ;
V_2 -> V_108 = V_109 ;
V_2 -> V_110 = V_4 -> V_110 ;
V_2 -> V_111 = 0xff ;
V_2 -> V_112 = 0xff ;
F_10 ( V_113 , & V_2 -> V_41 ) ;
V_2 -> V_114 = V_115 ;
switch ( type ) {
case V_82 :
V_2 -> V_42 = V_4 -> V_42 & V_116 ;
break;
case V_117 :
if ( F_21 ( V_4 ) )
V_2 -> V_42 = ( V_4 -> V_118 & V_119 ) |
( V_4 -> V_118 & V_120 ) ;
else
V_2 -> V_42 = V_4 -> V_42 & V_121 ;
break;
case V_122 :
V_2 -> V_42 = V_4 -> V_118 & ~ V_120 ;
break;
}
F_39 ( & V_2 -> V_123 ) ;
F_40 ( & V_2 -> V_124 ) ;
F_41 ( & V_2 -> V_79 , F_24 ) ;
F_42 ( & V_2 -> V_125 , F_34 , ( unsigned long ) V_2 ) ;
F_42 ( & V_2 -> V_126 , F_35 ,
( unsigned long ) V_2 ) ;
F_43 ( & V_2 -> V_80 , 0 ) ;
F_44 ( V_4 ) ;
F_45 ( V_4 , V_2 ) ;
if ( V_4 -> V_127 )
V_4 -> V_127 ( V_4 , V_128 ) ;
F_43 ( & V_2 -> V_129 , 0 ) ;
F_46 ( V_2 ) ;
return V_2 ;
}
int F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_7 ( L_5 , V_4 -> V_105 , V_2 , V_2 -> V_52 ) ;
F_47 ( & V_2 -> V_125 ) ;
F_48 ( & V_2 -> V_79 ) ;
F_47 ( & V_2 -> V_126 ) ;
if ( V_2 -> type == V_82 ) {
struct V_1 * V_75 = V_2 -> V_76 ;
if ( V_75 )
V_75 -> V_76 = NULL ;
V_4 -> V_130 += V_2 -> V_131 ;
} else if ( V_2 -> type == V_83 ) {
if ( V_4 -> V_132 )
V_4 -> V_133 += V_2 -> V_131 ;
else
V_4 -> V_130 += V_2 -> V_131 ;
} else {
struct V_1 * V_134 = V_2 -> V_76 ;
if ( V_134 ) {
V_134 -> V_76 = NULL ;
F_49 ( V_134 ) ;
}
}
F_50 ( V_2 ) ;
if ( V_2 -> V_135 )
F_51 ( V_2 -> V_135 ) ;
F_52 ( V_4 , V_2 ) ;
if ( V_4 -> V_127 )
V_4 -> V_127 ( V_4 , V_136 ) ;
F_53 ( & V_2 -> V_123 ) ;
F_54 ( V_2 ) ;
F_55 ( V_4 ) ;
if ( V_2 -> V_52 == 0 )
F_56 ( V_2 ) ;
return 0 ;
}
struct V_3 * F_57 ( T_5 * V_17 , T_5 * V_137 )
{
int V_138 = F_58 ( V_137 , V_139 ) ;
struct V_3 * V_4 = NULL , * V_140 ;
F_7 ( L_6 , F_37 ( V_137 ) , F_37 ( V_17 ) ) ;
F_59 ( & V_141 ) ;
F_60 (d, &hci_dev_list, list) {
if ( ! F_30 ( V_142 , & V_140 -> V_41 ) ||
F_30 ( V_88 , & V_140 -> V_41 ) ||
V_140 -> V_143 != V_144 )
continue;
if ( V_138 ) {
if ( ! F_58 ( & V_140 -> V_32 , V_137 ) ) {
V_4 = V_140 ; break;
}
} else {
if ( F_58 ( & V_140 -> V_32 , V_17 ) ) {
V_4 = V_140 ; break;
}
}
}
if ( V_4 )
V_4 = F_44 ( V_4 ) ;
F_61 ( & V_141 ) ;
return V_4 ;
}
struct V_1 * F_62 ( struct V_3 * V_4 , int type , T_5 * V_17 ,
T_1 V_19 , T_1 V_12 , T_1 V_108 )
{
struct V_1 * V_134 ;
struct V_1 * V_75 ;
struct V_1 * V_145 ;
F_7 ( L_4 , V_4 -> V_105 , F_37 ( V_17 ) ) ;
if ( type == V_83 ) {
V_145 = F_63 ( V_4 , V_83 , V_17 ) ;
if ( ! V_145 ) {
V_145 = F_64 ( V_4 , V_83 ,
V_8 ) ;
if ( V_145 )
return F_65 ( - V_146 ) ;
V_145 = F_36 ( V_4 , V_83 , V_17 ) ;
if ( ! V_145 )
return F_65 ( - V_147 ) ;
V_145 -> V_19 = F_66 ( V_19 ) ;
F_1 ( V_145 ) ;
}
V_145 -> V_148 = V_12 ;
V_145 -> V_108 = V_108 ;
F_67 ( V_145 ) ;
return V_145 ;
}
V_134 = F_63 ( V_4 , V_82 , V_17 ) ;
if ( ! V_134 ) {
V_134 = F_36 ( V_4 , V_82 , V_17 ) ;
if ( ! V_134 )
return F_65 ( - V_147 ) ;
}
F_67 ( V_134 ) ;
if ( V_134 -> V_7 == V_107 || V_134 -> V_7 == V_86 ) {
V_134 -> V_12 = V_13 ;
V_134 -> V_148 = V_12 ;
V_134 -> V_108 = V_108 ;
F_6 ( V_134 ) ;
}
if ( type == V_82 )
return V_134 ;
V_75 = F_63 ( V_4 , type , V_17 ) ;
if ( ! V_75 ) {
V_75 = F_36 ( V_4 , type , V_17 ) ;
if ( ! V_75 ) {
F_49 ( V_134 ) ;
return F_65 ( - V_147 ) ;
}
}
V_134 -> V_76 = V_75 ;
V_75 -> V_76 = V_134 ;
F_67 ( V_75 ) ;
if ( V_134 -> V_7 == V_85 &&
( V_75 -> V_7 == V_107 || V_75 -> V_7 == V_86 ) ) {
F_10 ( V_113 , & V_134 -> V_41 ) ;
F_68 ( V_134 , V_149 ) ;
if ( F_30 ( V_95 , & V_134 -> V_41 ) ) {
F_10 ( V_150 , & V_134 -> V_41 ) ;
return V_75 ;
}
F_20 ( V_134 , 0x00 ) ;
}
return V_75 ;
}
int F_69 ( struct V_1 * V_2 )
{
F_7 ( L_1 , V_2 ) ;
if ( F_70 ( V_2 ) && ! ( V_2 -> V_10 & V_151 ) )
return 0 ;
return 1 ;
}
static int F_71 ( struct V_1 * V_2 , T_1 V_12 , T_1 V_108 )
{
F_7 ( L_1 , V_2 ) ;
if ( V_2 -> V_148 > V_12 )
V_12 = V_2 -> V_148 ;
if ( V_12 > V_2 -> V_12 )
V_2 -> V_148 = V_12 ;
else if ( V_2 -> V_10 & V_152 )
return 1 ;
V_108 |= ( V_2 -> V_108 & 0x01 ) ;
V_2 -> V_108 = V_108 ;
if ( ! F_33 ( V_153 , & V_2 -> V_41 ) ) {
struct V_154 V_6 ;
F_10 ( V_155 , & V_2 -> V_41 ) ;
V_6 . V_52 = F_11 ( V_2 -> V_52 ) ;
F_4 ( V_2 -> V_4 , V_156 ,
sizeof( V_6 ) , & V_6 ) ;
if ( V_2 -> V_112 != 0xff )
F_10 ( V_157 , & V_2 -> V_41 ) ;
}
return 0 ;
}
static void F_72 ( struct V_1 * V_2 )
{
F_7 ( L_1 , V_2 ) ;
if ( ! F_33 ( V_155 , & V_2 -> V_41 ) ) {
struct V_158 V_6 ;
V_6 . V_52 = F_11 ( V_2 -> V_52 ) ;
V_6 . V_159 = 0x01 ;
F_4 ( V_2 -> V_4 , V_160 , sizeof( V_6 ) ,
& V_6 ) ;
}
}
int F_73 ( struct V_1 * V_2 , T_1 V_12 , T_1 V_108 )
{
F_7 ( L_1 , V_2 ) ;
if ( V_2 -> type == V_83 )
return F_74 ( V_2 , V_12 ) ;
if ( V_12 == V_161 )
return 1 ;
if ( V_12 == V_13 && ! F_70 ( V_2 ) )
return 1 ;
if ( ! ( V_2 -> V_10 & V_152 ) )
goto V_162;
if ( V_2 -> V_112 == V_163 )
goto V_159;
if ( V_2 -> V_112 == V_164 &&
( V_12 == V_165 || V_12 == V_13 ) )
goto V_159;
if ( V_2 -> V_112 == V_166 &&
( V_12 != V_167 || V_2 -> V_168 == 16 ) )
goto V_159;
V_162:
if ( F_30 ( V_155 , & V_2 -> V_41 ) )
return 0 ;
if ( ! F_71 ( V_2 , V_12 , V_108 ) )
return 0 ;
V_159:
if ( V_2 -> V_10 & V_151 )
return 1 ;
F_72 ( V_2 ) ;
return 0 ;
}
int F_75 ( struct V_1 * V_2 , T_1 V_12 )
{
F_7 ( L_1 , V_2 ) ;
if ( V_12 != V_167 )
return 1 ;
if ( V_2 -> V_12 == V_167 )
return 1 ;
return 0 ;
}
int F_76 ( struct V_1 * V_2 )
{
F_7 ( L_1 , V_2 ) ;
if ( ! F_33 ( V_153 , & V_2 -> V_41 ) ) {
struct V_169 V_6 ;
V_6 . V_52 = F_11 ( V_2 -> V_52 ) ;
F_4 ( V_2 -> V_4 , V_170 ,
sizeof( V_6 ) , & V_6 ) ;
}
return 0 ;
}
int F_77 ( struct V_1 * V_2 , T_1 V_171 )
{
F_7 ( L_1 , V_2 ) ;
if ( ! V_171 && V_2 -> V_10 & V_11 )
return 1 ;
if ( ! F_33 ( V_172 , & V_2 -> V_41 ) ) {
struct V_173 V_6 ;
F_3 ( & V_6 . V_32 , & V_2 -> V_17 ) ;
V_6 . V_171 = V_171 ;
F_4 ( V_2 -> V_4 , V_174 , sizeof( V_6 ) , & V_6 ) ;
}
return 0 ;
}
void F_68 ( struct V_1 * V_2 , T_1 V_175 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_7 ( L_3 , V_2 , V_2 -> V_87 ) ;
if ( F_30 ( V_88 , & V_4 -> V_41 ) )
return;
if ( V_2 -> V_87 != V_176 )
goto V_177;
if ( ! F_30 ( V_113 , & V_2 -> V_41 ) && ! V_175 )
goto V_177;
if ( ! F_33 ( V_95 , & V_2 -> V_41 ) ) {
struct V_178 V_6 ;
V_6 . V_52 = F_11 ( V_2 -> V_52 ) ;
F_4 ( V_4 , V_179 , sizeof( V_6 ) , & V_6 ) ;
}
V_177:
if ( V_4 -> V_180 > 0 )
F_78 ( & V_2 -> V_125 ,
V_181 + F_79 ( V_4 -> V_180 ) ) ;
}
void F_80 ( struct V_3 * V_4 )
{
struct V_182 * V_183 = & V_4 -> V_184 ;
struct V_1 * V_185 , * V_186 ;
F_7 ( L_7 , V_4 -> V_105 ) ;
F_81 (c, n, &h->list, list) {
V_185 -> V_7 = V_86 ;
F_82 ( V_185 , V_187 ) ;
F_23 ( V_185 ) ;
}
}
void F_83 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
F_7 ( L_7 , V_4 -> V_105 ) ;
F_84 ( V_4 ) ;
V_2 = F_64 ( V_4 , V_82 , V_81 ) ;
if ( V_2 )
F_6 ( V_2 ) ;
F_85 ( V_4 ) ;
}
void F_86 ( struct V_1 * V_2 )
{
F_87 ( & V_2 -> V_129 ) ;
}
void F_54 ( struct V_1 * V_2 )
{
if ( F_88 ( & V_2 -> V_129 ) )
F_89 ( V_2 ) ;
}
int F_90 ( void T_6 * V_103 )
{
struct V_1 * V_185 ;
struct V_188 V_189 , * V_190 ;
struct V_191 * V_192 ;
struct V_3 * V_4 ;
int V_186 = 0 , V_193 , V_194 ;
if ( F_91 ( & V_189 , V_103 , sizeof( V_189 ) ) )
return - V_195 ;
if ( ! V_189 . V_196 || V_189 . V_196 > ( V_197 * 2 ) / sizeof( * V_192 ) )
return - V_198 ;
V_193 = sizeof( V_189 ) + V_189 . V_196 * sizeof( * V_192 ) ;
V_190 = F_92 ( V_193 , V_106 ) ;
if ( ! V_190 )
return - V_147 ;
V_4 = F_93 ( V_189 . V_199 ) ;
if ( ! V_4 ) {
F_56 ( V_190 ) ;
return - V_200 ;
}
V_192 = V_190 -> V_201 ;
F_84 ( V_4 ) ;
F_60 (c, &hdev->conn_hash.list, list) {
F_3 ( & ( V_192 + V_186 ) -> V_32 , & V_185 -> V_17 ) ;
( V_192 + V_186 ) -> V_52 = V_185 -> V_52 ;
( V_192 + V_186 ) -> type = V_185 -> type ;
( V_192 + V_186 ) -> V_9 = V_185 -> V_9 ;
( V_192 + V_186 ) -> V_7 = V_185 -> V_7 ;
( V_192 + V_186 ) -> V_10 = V_185 -> V_10 ;
if ( ++ V_186 >= V_189 . V_196 )
break;
}
F_85 ( V_4 ) ;
V_190 -> V_199 = V_4 -> V_202 ;
V_190 -> V_196 = V_186 ;
V_193 = sizeof( V_189 ) + V_186 * sizeof( * V_192 ) ;
F_55 ( V_4 ) ;
V_194 = F_94 ( V_103 , V_190 , V_193 ) ;
F_56 ( V_190 ) ;
return V_194 ? - V_195 : 0 ;
}
int F_95 ( struct V_3 * V_4 , void T_6 * V_103 )
{
struct V_203 V_189 ;
struct V_191 V_192 ;
struct V_1 * V_2 ;
char T_6 * V_204 = V_103 + sizeof( V_189 ) ;
if ( F_91 ( & V_189 , V_103 , sizeof( V_189 ) ) )
return - V_195 ;
F_84 ( V_4 ) ;
V_2 = F_63 ( V_4 , V_189 . type , & V_189 . V_32 ) ;
if ( V_2 ) {
F_3 ( & V_192 . V_32 , & V_2 -> V_17 ) ;
V_192 . V_52 = V_2 -> V_52 ;
V_192 . type = V_2 -> type ;
V_192 . V_9 = V_2 -> V_9 ;
V_192 . V_7 = V_2 -> V_7 ;
V_192 . V_10 = V_2 -> V_10 ;
}
F_85 ( V_4 ) ;
if ( ! V_2 )
return - V_205 ;
return F_94 ( V_204 , & V_192 , sizeof( V_192 ) ) ? - V_195 : 0 ;
}
int F_96 ( struct V_3 * V_4 , void T_6 * V_103 )
{
struct V_206 V_189 ;
struct V_1 * V_2 ;
if ( F_91 ( & V_189 , V_103 , sizeof( V_189 ) ) )
return - V_195 ;
F_84 ( V_4 ) ;
V_2 = F_63 ( V_4 , V_82 , & V_189 . V_32 ) ;
if ( V_2 )
V_189 . type = V_2 -> V_108 ;
F_85 ( V_4 ) ;
if ( ! V_2 )
return - V_205 ;
return F_94 ( V_103 , & V_189 , sizeof( V_189 ) ) ? - V_195 : 0 ;
}
struct V_207 * F_97 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_207 * V_208 ;
F_7 ( L_8 , V_4 -> V_105 , V_2 ) ;
V_208 = F_38 ( sizeof( struct V_207 ) , V_106 ) ;
if ( ! V_208 )
return NULL ;
V_208 -> V_2 = V_2 ;
F_39 ( & V_208 -> V_123 ) ;
F_98 ( & V_208 -> V_209 , & V_2 -> V_124 ) ;
return V_208 ;
}
int F_99 ( struct V_207 * V_208 )
{
struct V_1 * V_2 = V_208 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_7 ( L_9 , V_4 -> V_105 , V_2 , V_208 ) ;
F_100 ( & V_208 -> V_209 ) ;
F_101 () ;
F_53 ( & V_208 -> V_123 ) ;
F_56 ( V_208 ) ;
return 0 ;
}
void F_50 ( struct V_1 * V_2 )
{
struct V_207 * V_208 , * V_186 ;
F_7 ( L_1 , V_2 ) ;
F_81 (chan, n, &conn->chan_list, list)
F_99 ( V_208 ) ;
}
