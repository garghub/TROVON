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
V_6 . V_42 = F_2 ( V_2 -> V_42 ) ;
if ( F_11 ( V_4 ) && ! ( V_4 -> V_10 & V_11 ) )
V_6 . V_43 = 0x01 ;
else
V_6 . V_43 = 0x00 ;
F_4 ( V_4 , V_44 , sizeof( V_6 ) , & V_6 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_45 V_6 ;
F_7 ( L_2 , V_2 ) ;
if ( V_2 -> V_4 -> V_46 < V_47 )
return;
F_3 ( & V_6 . V_32 , & V_2 -> V_17 ) ;
F_4 ( V_2 -> V_4 , V_48 , sizeof( V_6 ) , & V_6 ) ;
}
void F_13 ( struct V_1 * V_2 , T_1 V_49 )
{
struct V_50 V_6 ;
F_7 ( L_2 , V_2 ) ;
V_2 -> V_7 = V_51 ;
V_6 . V_52 = F_2 ( V_2 -> V_52 ) ;
V_6 . V_49 = V_49 ;
F_4 ( V_2 -> V_4 , V_53 , sizeof( V_6 ) , & V_6 ) ;
}
void F_14 ( struct V_1 * V_2 , T_2 V_52 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_54 V_6 ;
F_7 ( L_2 , V_2 ) ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = true ;
V_2 -> V_30 ++ ;
V_6 . V_52 = F_2 ( V_52 ) ;
V_6 . V_42 = F_2 ( V_2 -> V_42 ) ;
F_4 ( V_4 , V_55 , sizeof( V_6 ) , & V_6 ) ;
}
void F_15 ( struct V_1 * V_2 , T_2 V_52 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_56 V_6 ;
F_7 ( L_2 , V_2 ) ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = true ;
V_2 -> V_30 ++ ;
V_6 . V_52 = F_2 ( V_52 ) ;
V_6 . V_42 = F_2 ( V_2 -> V_42 ) ;
V_6 . V_57 = F_16 ( 0x00001f40 ) ;
V_6 . V_58 = F_16 ( 0x00001f40 ) ;
V_6 . V_59 = F_2 ( 0xffff ) ;
V_6 . V_60 = F_2 ( V_4 -> V_60 ) ;
V_6 . V_61 = 0xff ;
F_4 ( V_4 , V_62 , sizeof( V_6 ) , & V_6 ) ;
}
void F_17 ( struct V_1 * V_2 , T_3 V_63 , T_3 V_64 ,
T_3 V_65 , T_3 V_66 )
{
struct V_67 V_6 ;
struct V_3 * V_4 = V_2 -> V_4 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_52 = F_2 ( V_2 -> V_52 ) ;
V_6 . V_20 = F_2 ( V_63 ) ;
V_6 . V_21 = F_2 ( V_64 ) ;
V_6 . V_68 = F_2 ( V_65 ) ;
V_6 . V_22 = F_2 ( V_66 ) ;
V_6 . V_23 = F_2 ( 0x0001 ) ;
V_6 . V_24 = F_2 ( 0x0001 ) ;
F_4 ( V_4 , V_69 , sizeof( V_6 ) , & V_6 ) ;
}
void F_18 ( struct V_1 * V_2 , T_4 V_70 , T_1 rand [ 8 ] ,
T_1 V_71 [ 16 ] )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_72 V_6 ;
F_7 ( L_2 , V_2 ) ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_52 = F_2 ( V_2 -> V_52 ) ;
memcpy ( V_6 . V_71 , V_71 , sizeof( V_6 . V_71 ) ) ;
V_6 . V_70 = V_70 ;
memcpy ( V_6 . rand , rand , sizeof( V_6 . rand ) ) ;
F_4 ( V_4 , V_73 , sizeof( V_6 ) , & V_6 ) ;
}
void F_19 ( struct V_1 * V_2 , T_1 V_74 )
{
struct V_1 * V_75 = V_2 -> V_76 ;
F_7 ( L_2 , V_2 ) ;
if ( ! V_75 )
return;
if ( ! V_74 ) {
if ( F_20 ( V_2 -> V_4 ) )
F_15 ( V_75 , V_2 -> V_52 ) ;
else
F_14 ( V_75 , V_2 -> V_52 ) ;
} else {
F_21 ( V_75 , V_74 ) ;
F_22 ( V_75 ) ;
}
}
static void F_23 ( struct V_77 * V_78 )
{
struct V_1 * V_2 = F_24 ( V_78 , struct V_1 ,
V_79 . V_78 ) ;
T_1 V_49 ;
F_7 ( L_3 , V_2 , F_25 ( V_2 -> V_7 ) ) ;
if ( F_26 ( & V_2 -> V_80 ) )
return;
switch ( V_2 -> V_7 ) {
case V_8 :
case V_81 :
if ( V_2 -> V_9 ) {
if ( V_2 -> type == V_82 )
F_12 ( V_2 ) ;
else if ( V_2 -> type == V_83 )
F_5 ( V_2 ) ;
}
break;
case V_84 :
case V_85 :
V_49 = F_27 ( V_2 ) ;
F_13 ( V_2 , V_49 ) ;
break;
default:
V_2 -> V_7 = V_86 ;
break;
}
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_7 ( L_4 , V_2 , V_2 -> V_87 ) ;
if ( F_29 ( V_88 , & V_4 -> V_41 ) )
return;
if ( ! F_30 ( V_4 ) || ! F_30 ( V_2 ) )
return;
if ( V_2 -> V_87 != V_89 || ! ( V_2 -> V_31 & V_90 ) )
return;
if ( F_31 ( V_4 ) && F_31 ( V_2 ) ) {
struct V_91 V_6 ;
V_6 . V_52 = F_2 ( V_2 -> V_52 ) ;
V_6 . V_59 = F_2 ( 0 ) ;
V_6 . V_92 = F_2 ( 0 ) ;
V_6 . V_93 = F_2 ( 0 ) ;
F_4 ( V_4 , V_94 , sizeof( V_6 ) , & V_6 ) ;
}
if ( ! F_32 ( V_95 , & V_2 -> V_41 ) ) {
struct V_96 V_6 ;
V_6 . V_52 = F_2 ( V_2 -> V_52 ) ;
V_6 . V_97 = F_2 ( V_4 -> V_98 ) ;
V_6 . V_99 = F_2 ( V_4 -> V_100 ) ;
V_6 . V_30 = F_2 ( 4 ) ;
V_6 . V_101 = F_2 ( 1 ) ;
F_4 ( V_4 , V_102 , sizeof( V_6 ) , & V_6 ) ;
}
}
static void F_33 ( unsigned long V_103 )
{
struct V_1 * V_2 = ( void * ) V_103 ;
F_7 ( L_4 , V_2 , V_2 -> V_87 ) ;
F_28 ( V_2 ) ;
}
static void F_34 ( unsigned long V_103 )
{
struct V_1 * V_2 = ( void * ) V_103 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_4 ( V_4 , V_104 , sizeof( V_2 -> V_17 ) ,
& V_2 -> V_17 ) ;
}
struct V_1 * F_35 ( struct V_3 * V_4 , int type , T_5 * V_17 )
{
struct V_1 * V_2 ;
F_7 ( L_5 , V_4 -> V_105 , F_36 ( V_17 ) ) ;
V_2 = F_37 ( sizeof( struct V_1 ) , V_106 ) ;
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
if ( F_20 ( V_4 ) )
V_2 -> V_42 = ( V_4 -> V_118 & V_119 ) |
( V_4 -> V_118 & V_120 ) ;
else
V_2 -> V_42 = V_4 -> V_42 & V_121 ;
break;
case V_122 :
V_2 -> V_42 = V_4 -> V_118 & ~ V_120 ;
break;
}
F_38 ( & V_2 -> V_123 ) ;
F_39 ( & V_2 -> V_124 ) ;
F_40 ( & V_2 -> V_79 , F_23 ) ;
F_41 ( & V_2 -> V_125 , F_33 , ( unsigned long ) V_2 ) ;
F_41 ( & V_2 -> V_126 , F_34 ,
( unsigned long ) V_2 ) ;
F_42 ( & V_2 -> V_80 , 0 ) ;
F_43 ( V_4 ) ;
F_44 ( V_4 , V_2 ) ;
if ( V_4 -> V_127 )
V_4 -> V_127 ( V_4 , V_128 ) ;
F_42 ( & V_2 -> V_129 , 0 ) ;
F_45 ( V_2 ) ;
return V_2 ;
}
int F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_7 ( L_6 , V_4 -> V_105 , V_2 , V_2 -> V_52 ) ;
F_46 ( & V_2 -> V_125 ) ;
F_47 ( & V_2 -> V_79 ) ;
F_46 ( & V_2 -> V_126 ) ;
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
F_48 ( V_134 ) ;
}
}
F_49 ( V_2 ) ;
F_50 ( V_4 , V_2 ) ;
if ( V_4 -> V_127 )
V_4 -> V_127 ( V_4 , V_135 ) ;
F_51 ( & V_2 -> V_123 ) ;
F_52 ( V_2 ) ;
F_53 ( V_4 ) ;
if ( V_2 -> V_52 == 0 )
F_54 ( V_2 ) ;
return 0 ;
}
struct V_3 * F_55 ( T_5 * V_17 , T_5 * V_136 )
{
int V_137 = F_56 ( V_136 , V_138 ) ;
struct V_3 * V_4 = NULL , * V_139 ;
F_7 ( L_7 , F_36 ( V_136 ) , F_36 ( V_17 ) ) ;
F_57 ( & V_140 ) ;
F_58 (d, &hci_dev_list, list) {
if ( ! F_29 ( V_141 , & V_139 -> V_41 ) || F_29 ( V_88 , & V_139 -> V_41 ) )
continue;
if ( V_137 ) {
if ( ! F_56 ( & V_139 -> V_32 , V_136 ) ) {
V_4 = V_139 ; break;
}
} else {
if ( F_56 ( & V_139 -> V_32 , V_17 ) ) {
V_4 = V_139 ; break;
}
}
}
if ( V_4 )
V_4 = F_43 ( V_4 ) ;
F_59 ( & V_140 ) ;
return V_4 ;
}
struct V_1 * F_60 ( struct V_3 * V_4 , int type , T_5 * V_17 ,
T_1 V_19 , T_1 V_12 , T_1 V_108 )
{
struct V_1 * V_134 ;
struct V_1 * V_75 ;
struct V_1 * V_142 ;
F_7 ( L_5 , V_4 -> V_105 , F_36 ( V_17 ) ) ;
if ( type == V_83 ) {
V_142 = F_61 ( V_4 , V_83 , V_17 ) ;
if ( ! V_142 ) {
V_142 = F_35 ( V_4 , V_83 , V_17 ) ;
if ( ! V_142 )
return F_62 ( - V_143 ) ;
V_142 -> V_19 = F_63 ( V_19 ) ;
F_1 ( V_142 ) ;
}
V_142 -> V_144 = V_12 ;
V_142 -> V_108 = V_108 ;
F_64 ( V_142 ) ;
return V_142 ;
}
V_134 = F_61 ( V_4 , V_82 , V_17 ) ;
if ( ! V_134 ) {
V_134 = F_35 ( V_4 , V_82 , V_17 ) ;
if ( ! V_134 )
return F_62 ( - V_143 ) ;
}
F_64 ( V_134 ) ;
if ( V_134 -> V_7 == V_107 || V_134 -> V_7 == V_86 ) {
V_134 -> V_12 = V_13 ;
V_134 -> V_144 = V_12 ;
V_134 -> V_108 = V_108 ;
F_6 ( V_134 ) ;
}
if ( type == V_82 )
return V_134 ;
V_75 = F_61 ( V_4 , type , V_17 ) ;
if ( ! V_75 ) {
V_75 = F_35 ( V_4 , type , V_17 ) ;
if ( ! V_75 ) {
F_48 ( V_134 ) ;
return F_62 ( - V_143 ) ;
}
}
V_134 -> V_76 = V_75 ;
V_75 -> V_76 = V_134 ;
F_64 ( V_75 ) ;
if ( V_134 -> V_7 == V_85 &&
( V_75 -> V_7 == V_107 || V_75 -> V_7 == V_86 ) ) {
F_10 ( V_113 , & V_134 -> V_41 ) ;
F_65 ( V_134 , V_145 ) ;
if ( F_29 ( V_95 , & V_134 -> V_41 ) ) {
F_10 ( V_146 , & V_134 -> V_41 ) ;
return V_75 ;
}
F_19 ( V_134 , 0x00 ) ;
}
return V_75 ;
}
int F_66 ( struct V_1 * V_2 )
{
F_7 ( L_8 , V_2 ) ;
if ( F_67 ( V_2 ) && ! ( V_2 -> V_10 & V_147 ) )
return 0 ;
return 1 ;
}
static int F_68 ( struct V_1 * V_2 , T_1 V_12 , T_1 V_108 )
{
F_7 ( L_8 , V_2 ) ;
if ( V_2 -> V_144 > V_12 )
V_12 = V_2 -> V_144 ;
if ( V_12 > V_2 -> V_12 )
V_2 -> V_144 = V_12 ;
else if ( V_2 -> V_10 & V_148 )
return 1 ;
V_108 |= ( V_2 -> V_108 & 0x01 ) ;
V_2 -> V_108 = V_108 ;
if ( ! F_32 ( V_149 , & V_2 -> V_41 ) ) {
struct V_150 V_6 ;
F_10 ( V_151 , & V_2 -> V_41 ) ;
V_6 . V_52 = F_2 ( V_2 -> V_52 ) ;
F_4 ( V_2 -> V_4 , V_152 ,
sizeof( V_6 ) , & V_6 ) ;
if ( V_2 -> V_112 != 0xff )
F_10 ( V_153 , & V_2 -> V_41 ) ;
}
return 0 ;
}
static void F_69 ( struct V_1 * V_2 )
{
F_7 ( L_8 , V_2 ) ;
if ( ! F_32 ( V_151 , & V_2 -> V_41 ) ) {
struct V_154 V_6 ;
V_6 . V_52 = F_2 ( V_2 -> V_52 ) ;
V_6 . V_155 = 0x01 ;
F_4 ( V_2 -> V_4 , V_156 , sizeof( V_6 ) ,
& V_6 ) ;
}
}
int F_70 ( struct V_1 * V_2 , T_1 V_12 , T_1 V_108 )
{
F_7 ( L_8 , V_2 ) ;
if ( V_12 == V_157 )
return 1 ;
if ( V_12 == V_13 && ! F_67 ( V_2 ) )
return 1 ;
if ( ! ( V_2 -> V_10 & V_148 ) )
goto V_158;
if ( V_2 -> V_112 == V_159 )
goto V_155;
if ( V_2 -> V_112 == V_160 &&
( V_12 == V_161 ||
V_12 == V_13 ) )
goto V_155;
if ( V_2 -> V_112 == V_162 &&
( V_12 != V_163 ||
V_2 -> V_164 == 16 ) )
goto V_155;
V_158:
if ( F_29 ( V_151 , & V_2 -> V_41 ) )
return 0 ;
if ( ! F_68 ( V_2 , V_12 , V_108 ) )
return 0 ;
V_155:
if ( V_2 -> V_10 & V_147 )
return 1 ;
F_69 ( V_2 ) ;
return 0 ;
}
int F_71 ( struct V_1 * V_2 , T_1 V_12 )
{
F_7 ( L_8 , V_2 ) ;
if ( V_12 != V_163 )
return 1 ;
if ( V_2 -> V_12 == V_163 )
return 1 ;
return 0 ;
}
int F_72 ( struct V_1 * V_2 )
{
F_7 ( L_8 , V_2 ) ;
if ( ! F_32 ( V_149 , & V_2 -> V_41 ) ) {
struct V_165 V_6 ;
V_6 . V_52 = F_2 ( V_2 -> V_52 ) ;
F_4 ( V_2 -> V_4 , V_166 ,
sizeof( V_6 ) , & V_6 ) ;
}
return 0 ;
}
int F_73 ( struct V_1 * V_2 , T_1 V_167 )
{
F_7 ( L_8 , V_2 ) ;
if ( ! V_167 && V_2 -> V_10 & V_11 )
return 1 ;
if ( ! F_32 ( V_168 , & V_2 -> V_41 ) ) {
struct V_169 V_6 ;
F_3 ( & V_6 . V_32 , & V_2 -> V_17 ) ;
V_6 . V_167 = V_167 ;
F_4 ( V_2 -> V_4 , V_170 , sizeof( V_6 ) , & V_6 ) ;
}
return 0 ;
}
void F_65 ( struct V_1 * V_2 , T_1 V_171 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_7 ( L_4 , V_2 , V_2 -> V_87 ) ;
if ( F_29 ( V_88 , & V_4 -> V_41 ) )
return;
if ( V_2 -> V_87 != V_172 )
goto V_173;
if ( ! F_29 ( V_113 , & V_2 -> V_41 ) && ! V_171 )
goto V_173;
if ( ! F_32 ( V_95 , & V_2 -> V_41 ) ) {
struct V_174 V_6 ;
V_6 . V_52 = F_2 ( V_2 -> V_52 ) ;
F_4 ( V_4 , V_175 , sizeof( V_6 ) , & V_6 ) ;
}
V_173:
if ( V_4 -> V_176 > 0 )
F_74 ( & V_2 -> V_125 ,
V_177 + F_75 ( V_4 -> V_176 ) ) ;
}
void F_76 ( struct V_3 * V_4 )
{
struct V_178 * V_179 = & V_4 -> V_180 ;
struct V_1 * V_181 , * V_182 ;
F_7 ( L_9 , V_4 -> V_105 ) ;
F_77 (c, n, &h->list, list) {
V_181 -> V_7 = V_86 ;
F_78 ( V_181 , V_183 ) ;
F_22 ( V_181 ) ;
}
}
void F_79 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
F_7 ( L_9 , V_4 -> V_105 ) ;
F_80 ( V_4 ) ;
V_2 = F_81 ( V_4 , V_82 , V_81 ) ;
if ( V_2 )
F_6 ( V_2 ) ;
F_82 ( V_4 ) ;
}
void F_83 ( struct V_1 * V_2 )
{
F_84 ( & V_2 -> V_129 ) ;
}
void F_52 ( struct V_1 * V_2 )
{
if ( F_85 ( & V_2 -> V_129 ) )
F_86 ( V_2 ) ;
}
int F_87 ( void T_6 * V_103 )
{
register struct V_1 * V_181 ;
struct V_184 V_185 , * V_186 ;
struct V_187 * V_188 ;
struct V_3 * V_4 ;
int V_182 = 0 , V_189 , V_190 ;
if ( F_88 ( & V_185 , V_103 , sizeof( V_185 ) ) )
return - V_191 ;
if ( ! V_185 . V_192 || V_185 . V_192 > ( V_193 * 2 ) / sizeof( * V_188 ) )
return - V_194 ;
V_189 = sizeof( V_185 ) + V_185 . V_192 * sizeof( * V_188 ) ;
V_186 = F_89 ( V_189 , V_106 ) ;
if ( ! V_186 )
return - V_143 ;
V_4 = F_90 ( V_185 . V_195 ) ;
if ( ! V_4 ) {
F_54 ( V_186 ) ;
return - V_196 ;
}
V_188 = V_186 -> V_197 ;
F_80 ( V_4 ) ;
F_58 (c, &hdev->conn_hash.list, list) {
F_3 ( & ( V_188 + V_182 ) -> V_32 , & V_181 -> V_17 ) ;
( V_188 + V_182 ) -> V_52 = V_181 -> V_52 ;
( V_188 + V_182 ) -> type = V_181 -> type ;
( V_188 + V_182 ) -> V_9 = V_181 -> V_9 ;
( V_188 + V_182 ) -> V_7 = V_181 -> V_7 ;
( V_188 + V_182 ) -> V_10 = V_181 -> V_10 ;
if ( ++ V_182 >= V_185 . V_192 )
break;
}
F_82 ( V_4 ) ;
V_186 -> V_195 = V_4 -> V_198 ;
V_186 -> V_192 = V_182 ;
V_189 = sizeof( V_185 ) + V_182 * sizeof( * V_188 ) ;
F_53 ( V_4 ) ;
V_190 = F_91 ( V_103 , V_186 , V_189 ) ;
F_54 ( V_186 ) ;
return V_190 ? - V_191 : 0 ;
}
int F_92 ( struct V_3 * V_4 , void T_6 * V_103 )
{
struct V_199 V_185 ;
struct V_187 V_188 ;
struct V_1 * V_2 ;
char T_6 * V_200 = V_103 + sizeof( V_185 ) ;
if ( F_88 ( & V_185 , V_103 , sizeof( V_185 ) ) )
return - V_191 ;
F_80 ( V_4 ) ;
V_2 = F_61 ( V_4 , V_185 . type , & V_185 . V_32 ) ;
if ( V_2 ) {
F_3 ( & V_188 . V_32 , & V_2 -> V_17 ) ;
V_188 . V_52 = V_2 -> V_52 ;
V_188 . type = V_2 -> type ;
V_188 . V_9 = V_2 -> V_9 ;
V_188 . V_7 = V_2 -> V_7 ;
V_188 . V_10 = V_2 -> V_10 ;
}
F_82 ( V_4 ) ;
if ( ! V_2 )
return - V_201 ;
return F_91 ( V_200 , & V_188 , sizeof( V_188 ) ) ? - V_191 : 0 ;
}
int F_93 ( struct V_3 * V_4 , void T_6 * V_103 )
{
struct V_202 V_185 ;
struct V_1 * V_2 ;
if ( F_88 ( & V_185 , V_103 , sizeof( V_185 ) ) )
return - V_191 ;
F_80 ( V_4 ) ;
V_2 = F_61 ( V_4 , V_82 , & V_185 . V_32 ) ;
if ( V_2 )
V_185 . type = V_2 -> V_108 ;
F_82 ( V_4 ) ;
if ( ! V_2 )
return - V_201 ;
return F_91 ( V_103 , & V_185 , sizeof( V_185 ) ) ? - V_191 : 0 ;
}
struct V_203 * F_94 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_203 * V_204 ;
F_7 ( L_10 , V_4 -> V_105 , V_2 ) ;
V_204 = F_37 ( sizeof( struct V_203 ) , V_106 ) ;
if ( ! V_204 )
return NULL ;
V_204 -> V_2 = V_2 ;
F_38 ( & V_204 -> V_123 ) ;
F_95 ( & V_204 -> V_205 , & V_2 -> V_124 ) ;
return V_204 ;
}
int F_96 ( struct V_203 * V_204 )
{
struct V_1 * V_2 = V_204 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_7 ( L_11 , V_4 -> V_105 , V_2 , V_204 ) ;
F_97 ( & V_204 -> V_205 ) ;
F_98 () ;
F_51 ( & V_204 -> V_123 ) ;
F_54 ( V_204 ) ;
return 0 ;
}
void F_49 ( struct V_1 * V_2 )
{
struct V_203 * V_204 , * V_182 ;
F_7 ( L_8 , V_2 ) ;
F_77 (chan, n, &conn->chan_list, list)
F_96 ( V_204 ) ;
}
