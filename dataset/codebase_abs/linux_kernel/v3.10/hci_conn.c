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
void F_19 ( struct V_1 * V_2 , T_2 V_55 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_62 V_6 ;
F_7 ( L_1 , V_2 ) ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = true ;
V_2 -> V_30 ++ ;
V_6 . V_55 = F_11 ( V_55 ) ;
V_6 . V_42 = F_11 ( V_2 -> V_42 ) ;
V_6 . V_63 = F_20 ( 0x00001f40 ) ;
V_6 . V_64 = F_20 ( 0x00001f40 ) ;
V_6 . V_65 = F_2 ( 0xffff ) ;
V_6 . V_66 = F_11 ( V_4 -> V_66 ) ;
V_6 . V_67 = 0xff ;
F_4 ( V_4 , V_68 , sizeof( V_6 ) , & V_6 ) ;
}
void F_21 ( struct V_1 * V_2 , T_3 V_69 , T_3 V_70 ,
T_3 V_71 , T_3 V_72 )
{
struct V_73 V_6 ;
struct V_3 * V_4 = V_2 -> V_4 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_55 = F_11 ( V_2 -> V_55 ) ;
V_6 . V_20 = F_11 ( V_69 ) ;
V_6 . V_21 = F_11 ( V_70 ) ;
V_6 . V_74 = F_11 ( V_71 ) ;
V_6 . V_22 = F_11 ( V_72 ) ;
V_6 . V_23 = F_2 ( 0x0001 ) ;
V_6 . V_24 = F_2 ( 0x0001 ) ;
F_4 ( V_4 , V_75 , sizeof( V_6 ) , & V_6 ) ;
}
void F_22 ( struct V_1 * V_2 , T_4 V_76 , T_1 rand [ 8 ] ,
T_1 V_77 [ 16 ] )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_78 V_6 ;
F_7 ( L_1 , V_2 ) ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_55 = F_11 ( V_2 -> V_55 ) ;
memcpy ( V_6 . V_77 , V_77 , sizeof( V_6 . V_77 ) ) ;
V_6 . V_76 = V_76 ;
memcpy ( V_6 . rand , rand , sizeof( V_6 . rand ) ) ;
F_4 ( V_4 , V_79 , sizeof( V_6 ) , & V_6 ) ;
}
void F_23 ( struct V_1 * V_2 , T_1 V_80 )
{
struct V_1 * V_81 = V_2 -> V_82 ;
if ( ! V_81 )
return;
F_7 ( L_1 , V_2 ) ;
if ( ! V_80 ) {
if ( F_24 ( V_2 -> V_4 ) )
F_19 ( V_81 , V_2 -> V_55 ) ;
else
F_18 ( V_81 , V_2 -> V_55 ) ;
} else {
F_25 ( V_81 , V_80 ) ;
F_26 ( V_81 ) ;
}
}
static void F_27 ( struct V_1 * V_2 )
{
T_1 V_50 = F_28 ( V_2 ) ;
switch ( V_2 -> type ) {
case V_83 :
F_16 ( V_2 , V_50 ) ;
break;
default:
F_15 ( V_2 , V_50 ) ;
break;
}
}
static void F_29 ( struct V_84 * V_85 )
{
struct V_1 * V_2 = F_30 ( V_85 , struct V_1 ,
V_86 . V_85 ) ;
F_7 ( L_2 , V_2 , F_31 ( V_2 -> V_7 ) ) ;
if ( F_32 ( & V_2 -> V_87 ) )
return;
switch ( V_2 -> V_7 ) {
case V_8 :
case V_88 :
if ( V_2 -> V_9 ) {
if ( V_2 -> type == V_89 )
F_13 ( V_2 ) ;
else if ( V_2 -> type == V_90 )
F_5 ( V_2 ) ;
} else if ( V_2 -> type == V_91 || V_2 -> type == V_92 ) {
F_14 ( V_2 ) ;
}
break;
case V_93 :
case V_94 :
F_27 ( V_2 ) ;
break;
default:
V_2 -> V_7 = V_95 ;
break;
}
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_7 ( L_3 , V_2 , V_2 -> V_96 ) ;
if ( F_34 ( V_97 , & V_4 -> V_41 ) )
return;
if ( ! F_35 ( V_4 ) || ! F_35 ( V_2 ) )
return;
if ( V_2 -> V_96 != V_98 || ! ( V_2 -> V_31 & V_99 ) )
return;
if ( F_36 ( V_4 ) && F_36 ( V_2 ) ) {
struct V_100 V_6 ;
V_6 . V_55 = F_11 ( V_2 -> V_55 ) ;
V_6 . V_65 = F_2 ( 0 ) ;
V_6 . V_101 = F_2 ( 0 ) ;
V_6 . V_102 = F_2 ( 0 ) ;
F_4 ( V_4 , V_103 , sizeof( V_6 ) , & V_6 ) ;
}
if ( ! F_37 ( V_104 , & V_2 -> V_41 ) ) {
struct V_105 V_6 ;
V_6 . V_55 = F_11 ( V_2 -> V_55 ) ;
V_6 . V_106 = F_11 ( V_4 -> V_107 ) ;
V_6 . V_108 = F_11 ( V_4 -> V_109 ) ;
V_6 . V_30 = F_2 ( 4 ) ;
V_6 . V_110 = F_2 ( 1 ) ;
F_4 ( V_4 , V_111 , sizeof( V_6 ) , & V_6 ) ;
}
}
static void F_38 ( unsigned long V_112 )
{
struct V_1 * V_2 = ( void * ) V_112 ;
F_7 ( L_3 , V_2 , V_2 -> V_96 ) ;
F_33 ( V_2 ) ;
}
static void F_39 ( unsigned long V_112 )
{
struct V_1 * V_2 = ( void * ) V_112 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_4 ( V_4 , V_113 , sizeof( V_2 -> V_17 ) ,
& V_2 -> V_17 ) ;
}
struct V_1 * F_40 ( struct V_3 * V_4 , int type , T_5 * V_17 )
{
struct V_1 * V_2 ;
F_7 ( L_4 , V_4 -> V_114 , V_17 ) ;
V_2 = F_41 ( sizeof( struct V_1 ) , V_115 ) ;
if ( ! V_2 )
return NULL ;
F_3 ( & V_2 -> V_17 , V_17 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> type = type ;
V_2 -> V_96 = V_98 ;
V_2 -> V_7 = V_116 ;
V_2 -> V_117 = V_118 ;
V_2 -> V_119 = V_4 -> V_119 ;
V_2 -> V_120 = 0xff ;
V_2 -> V_121 = 0xff ;
F_10 ( V_122 , & V_2 -> V_41 ) ;
V_2 -> V_123 = V_124 ;
switch ( type ) {
case V_89 :
V_2 -> V_42 = V_4 -> V_42 & V_125 ;
break;
case V_91 :
if ( F_24 ( V_4 ) )
V_2 -> V_42 = ( V_4 -> V_126 & V_127 ) |
( V_4 -> V_126 & V_128 ) ;
else
V_2 -> V_42 = V_4 -> V_42 & V_129 ;
break;
case V_92 :
V_2 -> V_42 = V_4 -> V_126 & ~ V_128 ;
break;
}
F_42 ( & V_2 -> V_130 ) ;
F_43 ( & V_2 -> V_131 ) ;
F_44 ( & V_2 -> V_86 , F_29 ) ;
F_45 ( & V_2 -> V_132 , F_38 , ( unsigned long ) V_2 ) ;
F_45 ( & V_2 -> V_133 , F_39 ,
( unsigned long ) V_2 ) ;
F_46 ( & V_2 -> V_87 , 0 ) ;
F_47 ( V_4 ) ;
F_48 ( V_4 , V_2 ) ;
if ( V_4 -> V_134 )
V_4 -> V_134 ( V_4 , V_135 ) ;
F_49 ( V_2 ) ;
return V_2 ;
}
int F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_7 ( L_5 , V_4 -> V_114 , V_2 , V_2 -> V_55 ) ;
F_50 ( & V_2 -> V_132 ) ;
F_51 ( & V_2 -> V_86 ) ;
F_50 ( & V_2 -> V_133 ) ;
if ( V_2 -> type == V_89 ) {
struct V_1 * V_81 = V_2 -> V_82 ;
if ( V_81 )
V_81 -> V_82 = NULL ;
V_4 -> V_136 += V_2 -> V_137 ;
} else if ( V_2 -> type == V_90 ) {
if ( V_4 -> V_138 )
V_4 -> V_139 += V_2 -> V_137 ;
else
V_4 -> V_136 += V_2 -> V_137 ;
} else {
struct V_1 * V_140 = V_2 -> V_82 ;
if ( V_140 ) {
V_140 -> V_82 = NULL ;
F_52 ( V_140 ) ;
}
}
F_53 ( V_2 ) ;
if ( V_2 -> V_141 )
F_54 ( V_2 -> V_141 ) ;
F_55 ( V_4 , V_2 ) ;
if ( V_4 -> V_134 )
V_4 -> V_134 ( V_4 , V_142 ) ;
F_56 ( & V_2 -> V_130 ) ;
F_57 ( V_2 ) ;
F_58 ( V_4 ) ;
F_59 ( V_2 ) ;
return 0 ;
}
struct V_3 * F_60 ( T_5 * V_17 , T_5 * V_143 )
{
int V_144 = F_61 ( V_143 , V_145 ) ;
struct V_3 * V_4 = NULL , * V_146 ;
F_7 ( L_6 , V_143 , V_17 ) ;
F_62 ( & V_147 ) ;
F_63 (d, &hci_dev_list, list) {
if ( ! F_34 ( V_148 , & V_146 -> V_41 ) ||
F_34 ( V_97 , & V_146 -> V_41 ) ||
V_146 -> V_149 != V_150 )
continue;
if ( V_144 ) {
if ( ! F_61 ( & V_146 -> V_32 , V_143 ) ) {
V_4 = V_146 ; break;
}
} else {
if ( F_61 ( & V_146 -> V_32 , V_17 ) ) {
V_4 = V_146 ; break;
}
}
}
if ( V_4 )
V_4 = F_47 ( V_4 ) ;
F_64 ( & V_147 ) ;
return V_4 ;
}
static struct V_1 * F_65 ( struct V_3 * V_4 , T_5 * V_17 ,
T_6 V_19 , T_6 V_12 , T_6 V_117 )
{
struct V_1 * V_151 ;
if ( F_34 ( V_152 , & V_4 -> V_41 ) )
return F_66 ( - V_153 ) ;
V_151 = F_67 ( V_4 , V_90 , V_17 ) ;
if ( ! V_151 ) {
V_151 = F_68 ( V_4 , V_90 , V_8 ) ;
if ( V_151 )
return F_66 ( - V_154 ) ;
V_151 = F_40 ( V_4 , V_90 , V_17 ) ;
if ( ! V_151 )
return F_66 ( - V_155 ) ;
V_151 -> V_19 = F_69 ( V_19 ) ;
F_1 ( V_151 ) ;
}
V_151 -> V_156 = V_12 ;
V_151 -> V_117 = V_117 ;
F_70 ( V_151 ) ;
return V_151 ;
}
static struct V_1 * F_71 ( struct V_3 * V_4 , T_5 * V_17 ,
T_6 V_12 , T_6 V_117 )
{
struct V_1 * V_140 ;
V_140 = F_67 ( V_4 , V_89 , V_17 ) ;
if ( ! V_140 ) {
V_140 = F_40 ( V_4 , V_89 , V_17 ) ;
if ( ! V_140 )
return F_66 ( - V_155 ) ;
}
F_70 ( V_140 ) ;
if ( V_140 -> V_7 == V_116 || V_140 -> V_7 == V_95 ) {
V_140 -> V_12 = V_13 ;
V_140 -> V_156 = V_12 ;
V_140 -> V_117 = V_117 ;
F_6 ( V_140 ) ;
}
return V_140 ;
}
static struct V_1 * F_72 ( struct V_3 * V_4 , int type ,
T_5 * V_17 , T_6 V_12 , T_6 V_117 )
{
struct V_1 * V_140 ;
struct V_1 * V_81 ;
V_140 = F_71 ( V_4 , V_17 , V_12 , V_117 ) ;
if ( F_73 ( V_140 ) )
return V_140 ;
V_81 = F_67 ( V_4 , type , V_17 ) ;
if ( ! V_81 ) {
V_81 = F_40 ( V_4 , type , V_17 ) ;
if ( ! V_81 ) {
F_52 ( V_140 ) ;
return F_66 ( - V_155 ) ;
}
}
V_140 -> V_82 = V_81 ;
V_81 -> V_82 = V_140 ;
F_70 ( V_81 ) ;
if ( V_140 -> V_7 == V_94 &&
( V_81 -> V_7 == V_116 || V_81 -> V_7 == V_95 ) ) {
F_10 ( V_122 , & V_140 -> V_41 ) ;
F_74 ( V_140 , V_157 ) ;
if ( F_34 ( V_104 , & V_140 -> V_41 ) ) {
F_10 ( V_158 , & V_140 -> V_41 ) ;
return V_81 ;
}
F_23 ( V_140 , 0x00 ) ;
}
return V_81 ;
}
struct V_1 * F_75 ( struct V_3 * V_4 , int type , T_5 * V_17 ,
T_1 V_19 , T_1 V_12 , T_1 V_117 )
{
F_7 ( L_7 , V_4 -> V_114 , V_17 , type ) ;
switch ( type ) {
case V_90 :
return F_65 ( V_4 , V_17 , V_19 , V_12 , V_117 ) ;
case V_89 :
return F_71 ( V_4 , V_17 , V_12 , V_117 ) ;
case V_91 :
case V_92 :
return F_72 ( V_4 , type , V_17 , V_12 , V_117 ) ;
}
return F_66 ( - V_159 ) ;
}
int F_76 ( struct V_1 * V_2 )
{
F_7 ( L_1 , V_2 ) ;
if ( F_77 ( V_2 ) && ! ( V_2 -> V_10 & V_160 ) )
return 0 ;
return 1 ;
}
static int F_78 ( struct V_1 * V_2 , T_1 V_12 , T_1 V_117 )
{
F_7 ( L_1 , V_2 ) ;
if ( V_2 -> V_156 > V_12 )
V_12 = V_2 -> V_156 ;
if ( V_12 > V_2 -> V_12 )
V_2 -> V_156 = V_12 ;
else if ( V_2 -> V_10 & V_161 )
return 1 ;
V_117 |= ( V_2 -> V_117 & 0x01 ) ;
V_2 -> V_117 = V_117 ;
if ( ! F_37 ( V_162 , & V_2 -> V_41 ) ) {
struct V_163 V_6 ;
F_10 ( V_164 , & V_2 -> V_41 ) ;
V_6 . V_55 = F_11 ( V_2 -> V_55 ) ;
F_4 ( V_2 -> V_4 , V_165 ,
sizeof( V_6 ) , & V_6 ) ;
if ( V_2 -> V_121 != 0xff )
F_10 ( V_166 , & V_2 -> V_41 ) ;
}
return 0 ;
}
static void F_79 ( struct V_1 * V_2 )
{
F_7 ( L_1 , V_2 ) ;
if ( ! F_37 ( V_164 , & V_2 -> V_41 ) ) {
struct V_167 V_6 ;
V_6 . V_55 = F_11 ( V_2 -> V_55 ) ;
V_6 . V_168 = 0x01 ;
F_4 ( V_2 -> V_4 , V_169 , sizeof( V_6 ) ,
& V_6 ) ;
}
}
int F_80 ( struct V_1 * V_2 , T_1 V_12 , T_1 V_117 )
{
F_7 ( L_1 , V_2 ) ;
if ( V_2 -> type == V_90 )
return F_81 ( V_2 , V_12 ) ;
if ( V_12 == V_170 )
return 1 ;
if ( V_12 == V_13 && ! F_77 ( V_2 ) )
return 1 ;
if ( ! ( V_2 -> V_10 & V_161 ) )
goto V_171;
if ( V_2 -> V_121 == V_172 )
goto V_168;
if ( V_2 -> V_121 == V_173 &&
( V_12 == V_174 || V_12 == V_13 ) )
goto V_168;
if ( V_2 -> V_121 == V_175 &&
( V_12 != V_176 || V_2 -> V_177 == 16 ) )
goto V_168;
V_171:
if ( F_34 ( V_164 , & V_2 -> V_41 ) )
return 0 ;
if ( ! F_78 ( V_2 , V_12 , V_117 ) )
return 0 ;
V_168:
if ( V_2 -> V_10 & V_160 )
return 1 ;
F_79 ( V_2 ) ;
return 0 ;
}
int F_82 ( struct V_1 * V_2 , T_1 V_12 )
{
F_7 ( L_1 , V_2 ) ;
if ( V_12 != V_176 )
return 1 ;
if ( V_2 -> V_12 == V_176 )
return 1 ;
return 0 ;
}
int F_83 ( struct V_1 * V_2 )
{
F_7 ( L_1 , V_2 ) ;
if ( ! F_37 ( V_162 , & V_2 -> V_41 ) ) {
struct V_178 V_6 ;
V_6 . V_55 = F_11 ( V_2 -> V_55 ) ;
F_4 ( V_2 -> V_4 , V_179 ,
sizeof( V_6 ) , & V_6 ) ;
}
return 0 ;
}
int F_84 ( struct V_1 * V_2 , T_1 V_180 )
{
F_7 ( L_1 , V_2 ) ;
if ( ! V_180 && V_2 -> V_10 & V_11 )
return 1 ;
if ( ! F_37 ( V_181 , & V_2 -> V_41 ) ) {
struct V_182 V_6 ;
F_3 ( & V_6 . V_32 , & V_2 -> V_17 ) ;
V_6 . V_180 = V_180 ;
F_4 ( V_2 -> V_4 , V_183 , sizeof( V_6 ) , & V_6 ) ;
}
return 0 ;
}
void F_74 ( struct V_1 * V_2 , T_1 V_184 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_7 ( L_3 , V_2 , V_2 -> V_96 ) ;
if ( F_34 ( V_97 , & V_4 -> V_41 ) )
return;
if ( V_2 -> V_96 != V_185 )
goto V_186;
if ( ! F_34 ( V_122 , & V_2 -> V_41 ) && ! V_184 )
goto V_186;
if ( ! F_37 ( V_104 , & V_2 -> V_41 ) ) {
struct V_187 V_6 ;
V_6 . V_55 = F_11 ( V_2 -> V_55 ) ;
F_4 ( V_4 , V_188 , sizeof( V_6 ) , & V_6 ) ;
}
V_186:
if ( V_4 -> V_189 > 0 )
F_85 ( & V_2 -> V_132 ,
V_190 + F_86 ( V_4 -> V_189 ) ) ;
}
void F_87 ( struct V_3 * V_4 )
{
struct V_191 * V_192 = & V_4 -> V_193 ;
struct V_1 * V_194 , * V_195 ;
F_7 ( L_8 , V_4 -> V_114 ) ;
F_88 (c, n, &h->list, list) {
V_194 -> V_7 = V_95 ;
F_89 ( V_194 , V_196 ) ;
F_26 ( V_194 ) ;
}
}
void F_90 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
F_7 ( L_8 , V_4 -> V_114 ) ;
F_91 ( V_4 ) ;
V_2 = F_68 ( V_4 , V_89 , V_88 ) ;
if ( V_2 )
F_6 ( V_2 ) ;
F_92 ( V_4 ) ;
}
int F_93 ( void T_7 * V_112 )
{
struct V_1 * V_194 ;
struct V_197 V_198 , * V_199 ;
struct V_200 * V_201 ;
struct V_3 * V_4 ;
int V_195 = 0 , V_202 , V_203 ;
if ( F_94 ( & V_198 , V_112 , sizeof( V_198 ) ) )
return - V_204 ;
if ( ! V_198 . V_205 || V_198 . V_205 > ( V_206 * 2 ) / sizeof( * V_201 ) )
return - V_159 ;
V_202 = sizeof( V_198 ) + V_198 . V_205 * sizeof( * V_201 ) ;
V_199 = F_95 ( V_202 , V_115 ) ;
if ( ! V_199 )
return - V_155 ;
V_4 = F_96 ( V_198 . V_207 ) ;
if ( ! V_4 ) {
F_97 ( V_199 ) ;
return - V_208 ;
}
V_201 = V_199 -> V_209 ;
F_91 ( V_4 ) ;
F_63 (c, &hdev->conn_hash.list, list) {
F_3 ( & ( V_201 + V_195 ) -> V_32 , & V_194 -> V_17 ) ;
( V_201 + V_195 ) -> V_55 = V_194 -> V_55 ;
( V_201 + V_195 ) -> type = V_194 -> type ;
( V_201 + V_195 ) -> V_9 = V_194 -> V_9 ;
( V_201 + V_195 ) -> V_7 = V_194 -> V_7 ;
( V_201 + V_195 ) -> V_10 = V_194 -> V_10 ;
if ( ++ V_195 >= V_198 . V_205 )
break;
}
F_92 ( V_4 ) ;
V_199 -> V_207 = V_4 -> V_210 ;
V_199 -> V_205 = V_195 ;
V_202 = sizeof( V_198 ) + V_195 * sizeof( * V_201 ) ;
F_58 ( V_4 ) ;
V_203 = F_98 ( V_112 , V_199 , V_202 ) ;
F_97 ( V_199 ) ;
return V_203 ? - V_204 : 0 ;
}
int F_99 ( struct V_3 * V_4 , void T_7 * V_112 )
{
struct V_211 V_198 ;
struct V_200 V_201 ;
struct V_1 * V_2 ;
char T_7 * V_212 = V_112 + sizeof( V_198 ) ;
if ( F_94 ( & V_198 , V_112 , sizeof( V_198 ) ) )
return - V_204 ;
F_91 ( V_4 ) ;
V_2 = F_67 ( V_4 , V_198 . type , & V_198 . V_32 ) ;
if ( V_2 ) {
F_3 ( & V_201 . V_32 , & V_2 -> V_17 ) ;
V_201 . V_55 = V_2 -> V_55 ;
V_201 . type = V_2 -> type ;
V_201 . V_9 = V_2 -> V_9 ;
V_201 . V_7 = V_2 -> V_7 ;
V_201 . V_10 = V_2 -> V_10 ;
}
F_92 ( V_4 ) ;
if ( ! V_2 )
return - V_213 ;
return F_98 ( V_212 , & V_201 , sizeof( V_201 ) ) ? - V_204 : 0 ;
}
int F_100 ( struct V_3 * V_4 , void T_7 * V_112 )
{
struct V_214 V_198 ;
struct V_1 * V_2 ;
if ( F_94 ( & V_198 , V_112 , sizeof( V_198 ) ) )
return - V_204 ;
F_91 ( V_4 ) ;
V_2 = F_67 ( V_4 , V_89 , & V_198 . V_32 ) ;
if ( V_2 )
V_198 . type = V_2 -> V_117 ;
F_92 ( V_4 ) ;
if ( ! V_2 )
return - V_213 ;
return F_98 ( V_112 , & V_198 , sizeof( V_198 ) ) ? - V_204 : 0 ;
}
struct V_215 * F_101 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_215 * V_216 ;
F_7 ( L_9 , V_4 -> V_114 , V_2 ) ;
V_216 = F_41 ( sizeof( struct V_215 ) , V_115 ) ;
if ( ! V_216 )
return NULL ;
V_216 -> V_2 = V_2 ;
F_42 ( & V_216 -> V_130 ) ;
V_216 -> V_7 = V_94 ;
F_102 ( & V_216 -> V_217 , & V_2 -> V_131 ) ;
return V_216 ;
}
void F_103 ( struct V_215 * V_216 )
{
struct V_1 * V_2 = V_216 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_7 ( L_10 , V_4 -> V_114 , V_2 , V_216 ) ;
F_104 ( & V_216 -> V_217 ) ;
F_105 () ;
F_52 ( V_2 ) ;
F_56 ( & V_216 -> V_130 ) ;
F_97 ( V_216 ) ;
}
void F_53 ( struct V_1 * V_2 )
{
struct V_215 * V_216 , * V_195 ;
F_7 ( L_1 , V_2 ) ;
F_88 (chan, n, &conn->chan_list, list)
F_103 ( V_216 ) ;
}
static struct V_215 * F_106 ( struct V_1 * V_218 ,
T_2 V_55 )
{
struct V_215 * V_219 ;
F_63 (hchan, &hcon->chan_list, list) {
if ( V_219 -> V_55 == V_55 )
return V_219 ;
}
return NULL ;
}
struct V_215 * F_107 ( struct V_3 * V_4 , T_2 V_55 )
{
struct V_191 * V_192 = & V_4 -> V_193 ;
struct V_1 * V_218 ;
struct V_215 * V_219 = NULL ;
F_108 () ;
F_109 (hcon, &h->list, list) {
V_219 = F_106 ( V_218 , V_55 ) ;
if ( V_219 )
break;
}
F_110 () ;
return V_219 ;
}
