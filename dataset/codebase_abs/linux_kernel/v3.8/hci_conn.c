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
void F_14 ( struct V_1 * V_2 , T_1 V_49 )
{
struct V_50 V_6 ;
F_7 ( L_1 , V_2 ) ;
V_2 -> V_7 = V_51 ;
V_6 . V_52 = F_11 ( V_2 -> V_52 ) ;
V_6 . V_49 = V_49 ;
F_4 ( V_2 -> V_4 , V_53 , sizeof( V_6 ) , & V_6 ) ;
}
static void F_15 ( struct V_1 * V_2 , T_1 V_49 )
{
struct V_54 V_6 ;
F_7 ( L_1 , V_2 ) ;
V_2 -> V_7 = V_51 ;
V_6 . V_55 = F_16 ( V_2 -> V_52 ) ;
V_6 . V_49 = V_49 ;
F_4 ( V_2 -> V_4 , V_56 ,
sizeof( V_6 ) , & V_6 ) ;
}
static void F_17 ( struct V_1 * V_2 , T_2 V_52 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_57 V_6 ;
F_7 ( L_1 , V_2 ) ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = true ;
V_2 -> V_30 ++ ;
V_6 . V_52 = F_11 ( V_52 ) ;
V_6 . V_42 = F_11 ( V_2 -> V_42 ) ;
F_4 ( V_4 , V_58 , sizeof( V_6 ) , & V_6 ) ;
}
void F_18 ( struct V_1 * V_2 , T_2 V_52 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_59 V_6 ;
F_7 ( L_1 , V_2 ) ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = true ;
V_2 -> V_30 ++ ;
V_6 . V_52 = F_11 ( V_52 ) ;
V_6 . V_42 = F_11 ( V_2 -> V_42 ) ;
V_6 . V_60 = F_19 ( 0x00001f40 ) ;
V_6 . V_61 = F_19 ( 0x00001f40 ) ;
V_6 . V_62 = F_2 ( 0xffff ) ;
V_6 . V_63 = F_11 ( V_4 -> V_63 ) ;
V_6 . V_64 = 0xff ;
F_4 ( V_4 , V_65 , sizeof( V_6 ) , & V_6 ) ;
}
void F_20 ( struct V_1 * V_2 , T_3 V_66 , T_3 V_67 ,
T_3 V_68 , T_3 V_69 )
{
struct V_70 V_6 ;
struct V_3 * V_4 = V_2 -> V_4 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_52 = F_11 ( V_2 -> V_52 ) ;
V_6 . V_20 = F_11 ( V_66 ) ;
V_6 . V_21 = F_11 ( V_67 ) ;
V_6 . V_71 = F_11 ( V_68 ) ;
V_6 . V_22 = F_11 ( V_69 ) ;
V_6 . V_23 = F_2 ( 0x0001 ) ;
V_6 . V_24 = F_2 ( 0x0001 ) ;
F_4 ( V_4 , V_72 , sizeof( V_6 ) , & V_6 ) ;
}
void F_21 ( struct V_1 * V_2 , T_4 V_73 , T_1 rand [ 8 ] ,
T_1 V_74 [ 16 ] )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_75 V_6 ;
F_7 ( L_1 , V_2 ) ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_52 = F_11 ( V_2 -> V_52 ) ;
memcpy ( V_6 . V_74 , V_74 , sizeof( V_6 . V_74 ) ) ;
V_6 . V_73 = V_73 ;
memcpy ( V_6 . rand , rand , sizeof( V_6 . rand ) ) ;
F_4 ( V_4 , V_76 , sizeof( V_6 ) , & V_6 ) ;
}
void F_22 ( struct V_1 * V_2 , T_1 V_77 )
{
struct V_1 * V_78 = V_2 -> V_79 ;
if ( ! V_78 )
return;
F_7 ( L_1 , V_2 ) ;
if ( ! V_77 ) {
if ( F_23 ( V_2 -> V_4 ) )
F_18 ( V_78 , V_2 -> V_52 ) ;
else
F_17 ( V_78 , V_2 -> V_52 ) ;
} else {
F_24 ( V_78 , V_77 ) ;
F_25 ( V_78 ) ;
}
}
static void F_26 ( struct V_1 * V_2 )
{
T_1 V_49 = F_27 ( V_2 ) ;
switch ( V_2 -> type ) {
case V_80 :
F_15 ( V_2 , V_49 ) ;
break;
default:
F_14 ( V_2 , V_49 ) ;
break;
}
}
static void F_28 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = F_29 ( V_82 , struct V_1 ,
V_83 . V_82 ) ;
F_7 ( L_2 , V_2 , F_30 ( V_2 -> V_7 ) ) ;
if ( F_31 ( & V_2 -> V_84 ) )
return;
switch ( V_2 -> V_7 ) {
case V_8 :
case V_85 :
if ( V_2 -> V_9 ) {
if ( V_2 -> type == V_86 )
F_13 ( V_2 ) ;
else if ( V_2 -> type == V_87 )
F_5 ( V_2 ) ;
}
break;
case V_88 :
case V_89 :
F_26 ( V_2 ) ;
break;
default:
V_2 -> V_7 = V_90 ;
break;
}
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_7 ( L_3 , V_2 , V_2 -> V_91 ) ;
if ( F_33 ( V_92 , & V_4 -> V_41 ) )
return;
if ( ! F_34 ( V_4 ) || ! F_34 ( V_2 ) )
return;
if ( V_2 -> V_91 != V_93 || ! ( V_2 -> V_31 & V_94 ) )
return;
if ( F_35 ( V_4 ) && F_35 ( V_2 ) ) {
struct V_95 V_6 ;
V_6 . V_52 = F_11 ( V_2 -> V_52 ) ;
V_6 . V_62 = F_2 ( 0 ) ;
V_6 . V_96 = F_2 ( 0 ) ;
V_6 . V_97 = F_2 ( 0 ) ;
F_4 ( V_4 , V_98 , sizeof( V_6 ) , & V_6 ) ;
}
if ( ! F_36 ( V_99 , & V_2 -> V_41 ) ) {
struct V_100 V_6 ;
V_6 . V_52 = F_11 ( V_2 -> V_52 ) ;
V_6 . V_101 = F_11 ( V_4 -> V_102 ) ;
V_6 . V_103 = F_11 ( V_4 -> V_104 ) ;
V_6 . V_30 = F_2 ( 4 ) ;
V_6 . V_105 = F_2 ( 1 ) ;
F_4 ( V_4 , V_106 , sizeof( V_6 ) , & V_6 ) ;
}
}
static void F_37 ( unsigned long V_107 )
{
struct V_1 * V_2 = ( void * ) V_107 ;
F_7 ( L_3 , V_2 , V_2 -> V_91 ) ;
F_32 ( V_2 ) ;
}
static void F_38 ( unsigned long V_107 )
{
struct V_1 * V_2 = ( void * ) V_107 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_4 ( V_4 , V_108 , sizeof( V_2 -> V_17 ) ,
& V_2 -> V_17 ) ;
}
struct V_1 * F_39 ( struct V_3 * V_4 , int type , T_5 * V_17 )
{
struct V_1 * V_2 ;
F_7 ( L_4 , V_4 -> V_109 , V_17 ) ;
V_2 = F_40 ( sizeof( struct V_1 ) , V_110 ) ;
if ( ! V_2 )
return NULL ;
F_3 ( & V_2 -> V_17 , V_17 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> type = type ;
V_2 -> V_91 = V_93 ;
V_2 -> V_7 = V_111 ;
V_2 -> V_112 = V_113 ;
V_2 -> V_114 = V_4 -> V_114 ;
V_2 -> V_115 = 0xff ;
V_2 -> V_116 = 0xff ;
F_10 ( V_117 , & V_2 -> V_41 ) ;
V_2 -> V_118 = V_119 ;
switch ( type ) {
case V_86 :
V_2 -> V_42 = V_4 -> V_42 & V_120 ;
break;
case V_121 :
if ( F_23 ( V_4 ) )
V_2 -> V_42 = ( V_4 -> V_122 & V_123 ) |
( V_4 -> V_122 & V_124 ) ;
else
V_2 -> V_42 = V_4 -> V_42 & V_125 ;
break;
case V_126 :
V_2 -> V_42 = V_4 -> V_122 & ~ V_124 ;
break;
}
F_41 ( & V_2 -> V_127 ) ;
F_42 ( & V_2 -> V_128 ) ;
F_43 ( & V_2 -> V_83 , F_28 ) ;
F_44 ( & V_2 -> V_129 , F_37 , ( unsigned long ) V_2 ) ;
F_44 ( & V_2 -> V_130 , F_38 ,
( unsigned long ) V_2 ) ;
F_45 ( & V_2 -> V_84 , 0 ) ;
F_46 ( V_4 ) ;
F_47 ( V_4 , V_2 ) ;
if ( V_4 -> V_131 )
V_4 -> V_131 ( V_4 , V_132 ) ;
F_45 ( & V_2 -> V_133 , 0 ) ;
F_48 ( V_2 ) ;
return V_2 ;
}
int F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_7 ( L_5 , V_4 -> V_109 , V_2 , V_2 -> V_52 ) ;
F_49 ( & V_2 -> V_129 ) ;
F_50 ( & V_2 -> V_83 ) ;
F_49 ( & V_2 -> V_130 ) ;
if ( V_2 -> type == V_86 ) {
struct V_1 * V_78 = V_2 -> V_79 ;
if ( V_78 )
V_78 -> V_79 = NULL ;
V_4 -> V_134 += V_2 -> V_135 ;
} else if ( V_2 -> type == V_87 ) {
if ( V_4 -> V_136 )
V_4 -> V_137 += V_2 -> V_135 ;
else
V_4 -> V_134 += V_2 -> V_135 ;
} else {
struct V_1 * V_138 = V_2 -> V_79 ;
if ( V_138 ) {
V_138 -> V_79 = NULL ;
F_51 ( V_138 ) ;
}
}
F_52 ( V_2 ) ;
if ( V_2 -> V_139 )
F_53 ( V_2 -> V_139 ) ;
F_54 ( V_4 , V_2 ) ;
if ( V_4 -> V_131 )
V_4 -> V_131 ( V_4 , V_140 ) ;
F_55 ( & V_2 -> V_127 ) ;
F_56 ( V_2 ) ;
F_57 ( V_4 ) ;
if ( V_2 -> V_52 == 0 )
F_58 ( V_2 ) ;
return 0 ;
}
struct V_3 * F_59 ( T_5 * V_17 , T_5 * V_141 )
{
int V_142 = F_60 ( V_141 , V_143 ) ;
struct V_3 * V_4 = NULL , * V_144 ;
F_7 ( L_6 , V_141 , V_17 ) ;
F_61 ( & V_145 ) ;
F_62 (d, &hci_dev_list, list) {
if ( ! F_33 ( V_146 , & V_144 -> V_41 ) ||
F_33 ( V_92 , & V_144 -> V_41 ) ||
V_144 -> V_147 != V_148 )
continue;
if ( V_142 ) {
if ( ! F_60 ( & V_144 -> V_32 , V_141 ) ) {
V_4 = V_144 ; break;
}
} else {
if ( F_60 ( & V_144 -> V_32 , V_17 ) ) {
V_4 = V_144 ; break;
}
}
}
if ( V_4 )
V_4 = F_46 ( V_4 ) ;
F_63 ( & V_145 ) ;
return V_4 ;
}
static struct V_1 * F_64 ( struct V_3 * V_4 , T_5 * V_17 ,
T_6 V_19 , T_6 V_12 , T_6 V_112 )
{
struct V_1 * V_149 ;
if ( F_33 ( V_150 , & V_4 -> V_41 ) )
return F_65 ( - V_151 ) ;
V_149 = F_66 ( V_4 , V_87 , V_17 ) ;
if ( ! V_149 ) {
V_149 = F_67 ( V_4 , V_87 , V_8 ) ;
if ( V_149 )
return F_65 ( - V_152 ) ;
V_149 = F_39 ( V_4 , V_87 , V_17 ) ;
if ( ! V_149 )
return F_65 ( - V_153 ) ;
V_149 -> V_19 = F_68 ( V_19 ) ;
F_1 ( V_149 ) ;
}
V_149 -> V_154 = V_12 ;
V_149 -> V_112 = V_112 ;
F_69 ( V_149 ) ;
return V_149 ;
}
static struct V_1 * F_70 ( struct V_3 * V_4 , T_5 * V_17 ,
T_6 V_12 , T_6 V_112 )
{
struct V_1 * V_138 ;
V_138 = F_66 ( V_4 , V_86 , V_17 ) ;
if ( ! V_138 ) {
V_138 = F_39 ( V_4 , V_86 , V_17 ) ;
if ( ! V_138 )
return F_65 ( - V_153 ) ;
}
F_69 ( V_138 ) ;
if ( V_138 -> V_7 == V_111 || V_138 -> V_7 == V_90 ) {
V_138 -> V_12 = V_13 ;
V_138 -> V_154 = V_12 ;
V_138 -> V_112 = V_112 ;
F_6 ( V_138 ) ;
}
return V_138 ;
}
static struct V_1 * F_71 ( struct V_3 * V_4 , int type ,
T_5 * V_17 , T_6 V_12 , T_6 V_112 )
{
struct V_1 * V_138 ;
struct V_1 * V_78 ;
V_138 = F_70 ( V_4 , V_17 , V_12 , V_112 ) ;
if ( F_72 ( V_138 ) )
return V_138 ;
V_78 = F_66 ( V_4 , type , V_17 ) ;
if ( ! V_78 ) {
V_78 = F_39 ( V_4 , type , V_17 ) ;
if ( ! V_78 ) {
F_51 ( V_138 ) ;
return F_65 ( - V_153 ) ;
}
}
V_138 -> V_79 = V_78 ;
V_78 -> V_79 = V_138 ;
F_69 ( V_78 ) ;
if ( V_138 -> V_7 == V_89 &&
( V_78 -> V_7 == V_111 || V_78 -> V_7 == V_90 ) ) {
F_10 ( V_117 , & V_138 -> V_41 ) ;
F_73 ( V_138 , V_155 ) ;
if ( F_33 ( V_99 , & V_138 -> V_41 ) ) {
F_10 ( V_156 , & V_138 -> V_41 ) ;
return V_78 ;
}
F_22 ( V_138 , 0x00 ) ;
}
return V_78 ;
}
struct V_1 * F_74 ( struct V_3 * V_4 , int type , T_5 * V_17 ,
T_1 V_19 , T_1 V_12 , T_1 V_112 )
{
F_7 ( L_7 , V_4 -> V_109 , V_17 , type ) ;
switch ( type ) {
case V_87 :
return F_64 ( V_4 , V_17 , V_19 , V_12 , V_112 ) ;
case V_86 :
return F_70 ( V_4 , V_17 , V_12 , V_112 ) ;
case V_121 :
case V_126 :
return F_71 ( V_4 , type , V_17 , V_12 , V_112 ) ;
}
return F_65 ( - V_157 ) ;
}
int F_75 ( struct V_1 * V_2 )
{
F_7 ( L_1 , V_2 ) ;
if ( F_76 ( V_2 ) && ! ( V_2 -> V_10 & V_158 ) )
return 0 ;
return 1 ;
}
static int F_77 ( struct V_1 * V_2 , T_1 V_12 , T_1 V_112 )
{
F_7 ( L_1 , V_2 ) ;
if ( V_2 -> V_154 > V_12 )
V_12 = V_2 -> V_154 ;
if ( V_12 > V_2 -> V_12 )
V_2 -> V_154 = V_12 ;
else if ( V_2 -> V_10 & V_159 )
return 1 ;
V_112 |= ( V_2 -> V_112 & 0x01 ) ;
V_2 -> V_112 = V_112 ;
if ( ! F_36 ( V_160 , & V_2 -> V_41 ) ) {
struct V_161 V_6 ;
F_10 ( V_162 , & V_2 -> V_41 ) ;
V_6 . V_52 = F_11 ( V_2 -> V_52 ) ;
F_4 ( V_2 -> V_4 , V_163 ,
sizeof( V_6 ) , & V_6 ) ;
if ( V_2 -> V_116 != 0xff )
F_10 ( V_164 , & V_2 -> V_41 ) ;
}
return 0 ;
}
static void F_78 ( struct V_1 * V_2 )
{
F_7 ( L_1 , V_2 ) ;
if ( ! F_36 ( V_162 , & V_2 -> V_41 ) ) {
struct V_165 V_6 ;
V_6 . V_52 = F_11 ( V_2 -> V_52 ) ;
V_6 . V_166 = 0x01 ;
F_4 ( V_2 -> V_4 , V_167 , sizeof( V_6 ) ,
& V_6 ) ;
}
}
int F_79 ( struct V_1 * V_2 , T_1 V_12 , T_1 V_112 )
{
F_7 ( L_1 , V_2 ) ;
if ( V_2 -> type == V_87 )
return F_80 ( V_2 , V_12 ) ;
if ( V_12 == V_168 )
return 1 ;
if ( V_12 == V_13 && ! F_76 ( V_2 ) )
return 1 ;
if ( ! ( V_2 -> V_10 & V_159 ) )
goto V_169;
if ( V_2 -> V_116 == V_170 )
goto V_166;
if ( V_2 -> V_116 == V_171 &&
( V_12 == V_172 || V_12 == V_13 ) )
goto V_166;
if ( V_2 -> V_116 == V_173 &&
( V_12 != V_174 || V_2 -> V_175 == 16 ) )
goto V_166;
V_169:
if ( F_33 ( V_162 , & V_2 -> V_41 ) )
return 0 ;
if ( ! F_77 ( V_2 , V_12 , V_112 ) )
return 0 ;
V_166:
if ( V_2 -> V_10 & V_158 )
return 1 ;
F_78 ( V_2 ) ;
return 0 ;
}
int F_81 ( struct V_1 * V_2 , T_1 V_12 )
{
F_7 ( L_1 , V_2 ) ;
if ( V_12 != V_174 )
return 1 ;
if ( V_2 -> V_12 == V_174 )
return 1 ;
return 0 ;
}
int F_82 ( struct V_1 * V_2 )
{
F_7 ( L_1 , V_2 ) ;
if ( ! F_36 ( V_160 , & V_2 -> V_41 ) ) {
struct V_176 V_6 ;
V_6 . V_52 = F_11 ( V_2 -> V_52 ) ;
F_4 ( V_2 -> V_4 , V_177 ,
sizeof( V_6 ) , & V_6 ) ;
}
return 0 ;
}
int F_83 ( struct V_1 * V_2 , T_1 V_178 )
{
F_7 ( L_1 , V_2 ) ;
if ( ! V_178 && V_2 -> V_10 & V_11 )
return 1 ;
if ( ! F_36 ( V_179 , & V_2 -> V_41 ) ) {
struct V_180 V_6 ;
F_3 ( & V_6 . V_32 , & V_2 -> V_17 ) ;
V_6 . V_178 = V_178 ;
F_4 ( V_2 -> V_4 , V_181 , sizeof( V_6 ) , & V_6 ) ;
}
return 0 ;
}
void F_73 ( struct V_1 * V_2 , T_1 V_182 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_7 ( L_3 , V_2 , V_2 -> V_91 ) ;
if ( F_33 ( V_92 , & V_4 -> V_41 ) )
return;
if ( V_2 -> V_91 != V_183 )
goto V_184;
if ( ! F_33 ( V_117 , & V_2 -> V_41 ) && ! V_182 )
goto V_184;
if ( ! F_36 ( V_99 , & V_2 -> V_41 ) ) {
struct V_185 V_6 ;
V_6 . V_52 = F_11 ( V_2 -> V_52 ) ;
F_4 ( V_4 , V_186 , sizeof( V_6 ) , & V_6 ) ;
}
V_184:
if ( V_4 -> V_187 > 0 )
F_84 ( & V_2 -> V_129 ,
V_188 + F_85 ( V_4 -> V_187 ) ) ;
}
void F_86 ( struct V_3 * V_4 )
{
struct V_189 * V_190 = & V_4 -> V_191 ;
struct V_1 * V_192 , * V_193 ;
F_7 ( L_8 , V_4 -> V_109 ) ;
F_87 (c, n, &h->list, list) {
V_192 -> V_7 = V_90 ;
F_88 ( V_192 , V_194 ) ;
F_25 ( V_192 ) ;
}
}
void F_89 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
F_7 ( L_8 , V_4 -> V_109 ) ;
F_90 ( V_4 ) ;
V_2 = F_67 ( V_4 , V_86 , V_85 ) ;
if ( V_2 )
F_6 ( V_2 ) ;
F_91 ( V_4 ) ;
}
void F_92 ( struct V_1 * V_2 )
{
F_93 ( & V_2 -> V_133 ) ;
}
void F_56 ( struct V_1 * V_2 )
{
if ( F_94 ( & V_2 -> V_133 ) )
F_95 ( V_2 ) ;
}
int F_96 ( void T_7 * V_107 )
{
struct V_1 * V_192 ;
struct V_195 V_196 , * V_197 ;
struct V_198 * V_199 ;
struct V_3 * V_4 ;
int V_193 = 0 , V_200 , V_201 ;
if ( F_97 ( & V_196 , V_107 , sizeof( V_196 ) ) )
return - V_202 ;
if ( ! V_196 . V_203 || V_196 . V_203 > ( V_204 * 2 ) / sizeof( * V_199 ) )
return - V_157 ;
V_200 = sizeof( V_196 ) + V_196 . V_203 * sizeof( * V_199 ) ;
V_197 = F_98 ( V_200 , V_110 ) ;
if ( ! V_197 )
return - V_153 ;
V_4 = F_99 ( V_196 . V_205 ) ;
if ( ! V_4 ) {
F_58 ( V_197 ) ;
return - V_206 ;
}
V_199 = V_197 -> V_207 ;
F_90 ( V_4 ) ;
F_62 (c, &hdev->conn_hash.list, list) {
F_3 ( & ( V_199 + V_193 ) -> V_32 , & V_192 -> V_17 ) ;
( V_199 + V_193 ) -> V_52 = V_192 -> V_52 ;
( V_199 + V_193 ) -> type = V_192 -> type ;
( V_199 + V_193 ) -> V_9 = V_192 -> V_9 ;
( V_199 + V_193 ) -> V_7 = V_192 -> V_7 ;
( V_199 + V_193 ) -> V_10 = V_192 -> V_10 ;
if ( ++ V_193 >= V_196 . V_203 )
break;
}
F_91 ( V_4 ) ;
V_197 -> V_205 = V_4 -> V_208 ;
V_197 -> V_203 = V_193 ;
V_200 = sizeof( V_196 ) + V_193 * sizeof( * V_199 ) ;
F_57 ( V_4 ) ;
V_201 = F_100 ( V_107 , V_197 , V_200 ) ;
F_58 ( V_197 ) ;
return V_201 ? - V_202 : 0 ;
}
int F_101 ( struct V_3 * V_4 , void T_7 * V_107 )
{
struct V_209 V_196 ;
struct V_198 V_199 ;
struct V_1 * V_2 ;
char T_7 * V_210 = V_107 + sizeof( V_196 ) ;
if ( F_97 ( & V_196 , V_107 , sizeof( V_196 ) ) )
return - V_202 ;
F_90 ( V_4 ) ;
V_2 = F_66 ( V_4 , V_196 . type , & V_196 . V_32 ) ;
if ( V_2 ) {
F_3 ( & V_199 . V_32 , & V_2 -> V_17 ) ;
V_199 . V_52 = V_2 -> V_52 ;
V_199 . type = V_2 -> type ;
V_199 . V_9 = V_2 -> V_9 ;
V_199 . V_7 = V_2 -> V_7 ;
V_199 . V_10 = V_2 -> V_10 ;
}
F_91 ( V_4 ) ;
if ( ! V_2 )
return - V_211 ;
return F_100 ( V_210 , & V_199 , sizeof( V_199 ) ) ? - V_202 : 0 ;
}
int F_102 ( struct V_3 * V_4 , void T_7 * V_107 )
{
struct V_212 V_196 ;
struct V_1 * V_2 ;
if ( F_97 ( & V_196 , V_107 , sizeof( V_196 ) ) )
return - V_202 ;
F_90 ( V_4 ) ;
V_2 = F_66 ( V_4 , V_86 , & V_196 . V_32 ) ;
if ( V_2 )
V_196 . type = V_2 -> V_112 ;
F_91 ( V_4 ) ;
if ( ! V_2 )
return - V_211 ;
return F_100 ( V_107 , & V_196 , sizeof( V_196 ) ) ? - V_202 : 0 ;
}
struct V_213 * F_103 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_213 * V_214 ;
F_7 ( L_9 , V_4 -> V_109 , V_2 ) ;
V_214 = F_40 ( sizeof( struct V_213 ) , V_110 ) ;
if ( ! V_214 )
return NULL ;
V_214 -> V_2 = V_2 ;
F_41 ( & V_214 -> V_127 ) ;
V_214 -> V_7 = V_89 ;
F_104 ( & V_214 -> V_215 , & V_2 -> V_128 ) ;
return V_214 ;
}
void F_105 ( struct V_213 * V_214 )
{
struct V_1 * V_2 = V_214 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_7 ( L_10 , V_4 -> V_109 , V_2 , V_214 ) ;
F_106 ( & V_214 -> V_215 ) ;
F_107 () ;
F_51 ( V_2 ) ;
F_55 ( & V_214 -> V_127 ) ;
F_58 ( V_214 ) ;
}
void F_52 ( struct V_1 * V_2 )
{
struct V_213 * V_214 , * V_193 ;
F_7 ( L_1 , V_2 ) ;
F_87 (chan, n, &conn->chan_list, list)
F_105 ( V_214 ) ;
}
static struct V_213 * F_108 ( struct V_1 * V_216 ,
T_2 V_52 )
{
struct V_213 * V_217 ;
F_62 (hchan, &hcon->chan_list, list) {
if ( V_217 -> V_52 == V_52 )
return V_217 ;
}
return NULL ;
}
struct V_213 * F_109 ( struct V_3 * V_4 , T_2 V_52 )
{
struct V_189 * V_190 = & V_4 -> V_191 ;
struct V_1 * V_216 ;
struct V_213 * V_217 = NULL ;
F_110 () ;
F_111 (hcon, &h->list, list) {
V_217 = F_108 ( V_216 , V_52 ) ;
if ( V_217 )
break;
}
F_112 () ;
return V_217 ;
}
