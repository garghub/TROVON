static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 V_6 ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = 1 ;
V_2 -> V_10 |= V_11 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_12 = F_2 ( 0x0004 ) ;
V_6 . V_13 = F_2 ( 0x0004 ) ;
F_3 ( & V_6 . V_14 , & V_2 -> V_15 ) ;
V_6 . V_16 = F_2 ( 0x0008 ) ;
V_6 . V_17 = F_2 ( 0x0100 ) ;
V_6 . V_18 = F_2 ( 0x0064 ) ;
V_6 . V_19 = F_2 ( 0x0001 ) ;
V_6 . V_20 = F_2 ( 0x0001 ) ;
F_4 ( V_4 , V_21 , sizeof( V_6 ) , & V_6 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_4 , V_22 , 0 , NULL ) ;
}
void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 ;
struct V_25 V_6 ;
F_7 ( L_1 , V_2 ) ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = 1 ;
V_2 -> V_10 = V_11 ;
V_2 -> V_26 ++ ;
V_2 -> V_27 = V_4 -> V_27 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
F_3 ( & V_6 . V_28 , & V_2 -> V_15 ) ;
V_6 . V_29 = 0x02 ;
V_24 = F_8 ( V_4 , & V_2 -> V_15 ) ;
if ( V_24 ) {
if ( F_9 ( V_24 ) <= V_30 ) {
V_6 . V_29 = V_24 -> V_31 . V_29 ;
V_6 . V_32 = V_24 -> V_31 . V_32 ;
V_6 . V_33 = V_24 -> V_31 . V_33 |
F_2 ( 0x8000 ) ;
}
memcpy ( V_2 -> V_34 , V_24 -> V_31 . V_34 , 3 ) ;
V_2 -> V_35 = V_24 -> V_31 . V_35 ;
}
V_6 . V_36 = F_2 ( V_2 -> V_36 ) ;
if ( F_10 ( V_4 ) && ! ( V_4 -> V_10 & V_11 ) )
V_6 . V_37 = 0x01 ;
else
V_6 . V_37 = 0x00 ;
F_4 ( V_4 , V_38 , sizeof( V_6 ) , & V_6 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_39 V_6 ;
F_7 ( L_1 , V_2 ) ;
if ( V_2 -> V_4 -> V_40 < 2 )
return;
F_3 ( & V_6 . V_28 , & V_2 -> V_15 ) ;
F_4 ( V_2 -> V_4 , V_41 , sizeof( V_6 ) , & V_6 ) ;
}
void F_12 ( struct V_1 * V_2 , T_1 V_42 )
{
struct V_43 V_6 ;
F_7 ( L_1 , V_2 ) ;
V_2 -> V_7 = V_44 ;
V_6 . V_45 = F_2 ( V_2 -> V_45 ) ;
V_6 . V_42 = V_42 ;
F_4 ( V_2 -> V_4 , V_46 , sizeof( V_6 ) , & V_6 ) ;
}
void F_13 ( struct V_1 * V_2 , T_2 V_45 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_47 V_6 ;
F_7 ( L_1 , V_2 ) ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = 1 ;
V_2 -> V_26 ++ ;
V_6 . V_45 = F_2 ( V_45 ) ;
V_6 . V_36 = F_2 ( V_2 -> V_36 ) ;
F_4 ( V_4 , V_48 , sizeof( V_6 ) , & V_6 ) ;
}
void F_14 ( struct V_1 * V_2 , T_2 V_45 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_49 V_6 ;
F_7 ( L_1 , V_2 ) ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = 1 ;
V_2 -> V_26 ++ ;
V_6 . V_45 = F_2 ( V_45 ) ;
V_6 . V_36 = F_2 ( V_2 -> V_36 ) ;
V_6 . V_50 = F_15 ( 0x00001f40 ) ;
V_6 . V_51 = F_15 ( 0x00001f40 ) ;
V_6 . V_52 = F_2 ( 0xffff ) ;
V_6 . V_53 = F_2 ( V_4 -> V_53 ) ;
V_6 . V_54 = 0xff ;
F_4 ( V_4 , V_55 , sizeof( V_6 ) , & V_6 ) ;
}
void F_16 ( struct V_1 * V_2 , T_3 V_56 , T_3 V_57 ,
T_3 V_58 , T_3 V_59 )
{
struct V_60 V_6 ;
struct V_3 * V_4 = V_2 -> V_4 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_45 = F_2 ( V_2 -> V_45 ) ;
V_6 . V_16 = F_2 ( V_56 ) ;
V_6 . V_17 = F_2 ( V_57 ) ;
V_6 . V_61 = F_2 ( V_58 ) ;
V_6 . V_18 = F_2 ( V_59 ) ;
V_6 . V_19 = F_2 ( 0x0001 ) ;
V_6 . V_20 = F_2 ( 0x0001 ) ;
F_4 ( V_4 , V_62 , sizeof( V_6 ) , & V_6 ) ;
}
void F_17 ( struct V_1 * V_2 , T_1 V_63 )
{
struct V_1 * V_64 = V_2 -> V_65 ;
F_7 ( L_1 , V_2 ) ;
if ( ! V_64 )
return;
if ( ! V_63 ) {
if ( F_18 ( V_2 -> V_4 ) )
F_14 ( V_64 , V_2 -> V_45 ) ;
else
F_13 ( V_64 , V_2 -> V_45 ) ;
} else {
F_19 ( V_64 , V_63 ) ;
F_20 ( V_64 ) ;
}
}
static void F_21 ( unsigned long V_66 )
{
struct V_1 * V_2 = ( void * ) V_66 ;
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_42 ;
F_7 ( L_2 , V_2 , V_2 -> V_7 ) ;
if ( F_22 ( & V_2 -> V_67 ) )
return;
F_23 ( V_4 ) ;
switch ( V_2 -> V_7 ) {
case V_8 :
case V_68 :
if ( V_2 -> V_9 ) {
if ( V_2 -> type == V_69 )
F_11 ( V_2 ) ;
else if ( V_2 -> type == V_70 )
F_5 ( V_2 ) ;
}
break;
case V_71 :
case V_72 :
V_42 = F_24 ( V_2 ) ;
F_12 ( V_2 , V_42 ) ;
break;
default:
V_2 -> V_7 = V_73 ;
break;
}
F_25 ( V_4 ) ;
}
static void F_26 ( unsigned long V_66 )
{
struct V_1 * V_2 = ( void * ) V_66 ;
F_7 ( L_3 , V_2 , V_2 -> V_74 ) ;
F_27 ( V_2 ) ;
}
static void F_28 ( unsigned long V_66 )
{
struct V_1 * V_2 = ( void * ) V_66 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_23 ( V_4 ) ;
F_4 ( V_4 , V_75 , sizeof( V_2 -> V_15 ) ,
& V_2 -> V_15 ) ;
F_25 ( V_4 ) ;
}
struct V_1 * F_29 ( struct V_3 * V_4 , int type , T_4 * V_15 )
{
struct V_1 * V_2 ;
F_7 ( L_4 , V_4 -> V_76 , F_30 ( V_15 ) ) ;
V_2 = F_31 ( sizeof( struct V_1 ) , V_77 ) ;
if ( ! V_2 )
return NULL ;
F_3 ( & V_2 -> V_15 , V_15 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> type = type ;
V_2 -> V_74 = V_78 ;
V_2 -> V_7 = V_79 ;
V_2 -> V_80 = V_81 ;
V_2 -> V_82 = V_4 -> V_82 ;
V_2 -> V_83 = 0xff ;
V_2 -> V_84 = 0xff ;
V_2 -> V_85 = 1 ;
V_2 -> V_86 = V_87 ;
switch ( type ) {
case V_69 :
V_2 -> V_36 = V_4 -> V_36 & V_88 ;
break;
case V_89 :
if ( F_18 ( V_4 ) )
V_2 -> V_36 = ( V_4 -> V_90 & V_91 ) |
( V_4 -> V_90 & V_92 ) ;
else
V_2 -> V_36 = V_4 -> V_36 & V_93 ;
break;
case V_94 :
V_2 -> V_36 = V_4 -> V_90 & ~ V_92 ;
break;
}
F_32 ( & V_2 -> V_95 ) ;
F_33 ( & V_2 -> V_96 , F_21 , ( unsigned long ) V_2 ) ;
F_33 ( & V_2 -> V_97 , F_26 , ( unsigned long ) V_2 ) ;
F_33 ( & V_2 -> V_98 , F_28 ,
( unsigned long ) V_2 ) ;
F_34 ( & V_2 -> V_67 , 0 ) ;
F_35 ( V_4 ) ;
F_36 ( & V_4 -> V_99 ) ;
F_37 ( V_4 , V_2 ) ;
if ( V_4 -> V_100 )
V_4 -> V_100 ( V_4 , V_101 ) ;
F_34 ( & V_2 -> V_102 , 0 ) ;
F_38 ( V_2 ) ;
F_39 ( & V_4 -> V_99 ) ;
return V_2 ;
}
int F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_7 ( L_5 , V_4 -> V_76 , V_2 , V_2 -> V_45 ) ;
F_40 ( & V_2 -> V_97 ) ;
F_40 ( & V_2 -> V_96 ) ;
F_40 ( & V_2 -> V_98 ) ;
if ( V_2 -> type == V_69 ) {
struct V_1 * V_64 = V_2 -> V_65 ;
if ( V_64 )
V_64 -> V_65 = NULL ;
V_4 -> V_103 += V_2 -> V_104 ;
} else if ( V_2 -> type == V_70 ) {
if ( V_4 -> V_105 )
V_4 -> V_106 += V_2 -> V_104 ;
else
V_4 -> V_103 += V_2 -> V_104 ;
} else {
struct V_1 * V_107 = V_2 -> V_65 ;
if ( V_107 ) {
V_107 -> V_65 = NULL ;
F_41 ( V_107 ) ;
}
}
F_36 ( & V_4 -> V_99 ) ;
F_42 ( V_4 , V_2 ) ;
if ( V_4 -> V_100 )
V_4 -> V_100 ( V_4 , V_108 ) ;
F_39 ( & V_4 -> V_99 ) ;
F_43 ( & V_2 -> V_95 ) ;
F_44 ( V_2 ) ;
F_45 ( V_4 ) ;
if ( V_2 -> V_45 == 0 )
F_46 ( V_2 ) ;
return 0 ;
}
struct V_3 * F_47 ( T_4 * V_15 , T_4 * V_109 )
{
int V_110 = F_48 ( V_109 , V_111 ) ;
struct V_3 * V_4 = NULL ;
struct V_112 * V_113 ;
F_7 ( L_6 , F_30 ( V_109 ) , F_30 ( V_15 ) ) ;
F_49 ( & V_114 ) ;
F_50 (p, &hci_dev_list) {
struct V_3 * V_115 = F_51 ( V_113 , struct V_3 , V_116 ) ;
if ( ! F_52 ( V_117 , & V_115 -> V_118 ) || F_52 ( V_119 , & V_115 -> V_118 ) )
continue;
if ( V_110 ) {
if ( ! F_48 ( & V_115 -> V_28 , V_109 ) ) {
V_4 = V_115 ; break;
}
} else {
if ( F_48 ( & V_115 -> V_28 , V_15 ) ) {
V_4 = V_115 ; break;
}
}
}
if ( V_4 )
V_4 = F_35 ( V_4 ) ;
F_53 ( & V_114 ) ;
return V_4 ;
}
struct V_1 * F_54 ( struct V_3 * V_4 , int type , T_4 * V_15 , T_1 V_120 , T_1 V_80 )
{
struct V_1 * V_107 ;
struct V_1 * V_64 ;
struct V_1 * V_121 ;
F_7 ( L_4 , V_4 -> V_76 , F_30 ( V_15 ) ) ;
if ( type == V_70 ) {
V_121 = F_55 ( V_4 , V_70 , V_15 ) ;
if ( V_121 )
return F_56 ( - V_122 ) ;
V_121 = F_29 ( V_4 , V_70 , V_15 ) ;
if ( ! V_121 )
return F_56 ( - V_123 ) ;
if ( V_121 -> V_7 == V_79 )
F_1 ( V_121 ) ;
F_57 ( V_121 ) ;
return V_121 ;
}
V_107 = F_55 ( V_4 , V_69 , V_15 ) ;
if ( ! V_107 ) {
V_107 = F_29 ( V_4 , V_69 , V_15 ) ;
if ( ! V_107 )
return NULL ;
}
F_57 ( V_107 ) ;
if ( V_107 -> V_7 == V_79 || V_107 -> V_7 == V_73 ) {
V_107 -> V_120 = V_124 ;
V_107 -> V_125 = V_120 ;
V_107 -> V_80 = V_80 ;
F_6 ( V_107 ) ;
}
if ( type == V_69 )
return V_107 ;
V_64 = F_55 ( V_4 , type , V_15 ) ;
if ( ! V_64 ) {
V_64 = F_29 ( V_4 , type , V_15 ) ;
if ( ! V_64 ) {
F_41 ( V_107 ) ;
return NULL ;
}
}
V_107 -> V_65 = V_64 ;
V_64 -> V_65 = V_107 ;
F_57 ( V_64 ) ;
if ( V_107 -> V_7 == V_72 &&
( V_64 -> V_7 == V_79 || V_64 -> V_7 == V_73 ) ) {
V_107 -> V_85 = 1 ;
F_58 ( V_107 ) ;
if ( F_52 ( V_126 , & V_107 -> V_127 ) ) {
F_59 ( V_128 , & V_107 -> V_127 ) ;
return V_64 ;
}
F_17 ( V_107 , 0x00 ) ;
}
return V_64 ;
}
int F_60 ( struct V_1 * V_2 )
{
F_7 ( L_7 , V_2 ) ;
if ( V_2 -> V_35 > 0 && V_2 -> V_4 -> V_35 > 0 &&
! ( V_2 -> V_10 & V_129 ) )
return 0 ;
return 1 ;
}
static int F_61 ( struct V_1 * V_2 , T_1 V_120 , T_1 V_80 )
{
F_7 ( L_7 , V_2 ) ;
if ( V_2 -> V_125 > V_120 )
V_120 = V_2 -> V_125 ;
if ( V_120 > V_2 -> V_120 )
V_2 -> V_125 = V_120 ;
else if ( V_2 -> V_10 & V_130 )
return 1 ;
V_80 |= ( V_2 -> V_80 & 0x01 ) ;
V_2 -> V_80 = V_80 ;
if ( ! F_62 ( V_131 , & V_2 -> V_127 ) ) {
struct V_132 V_6 ;
V_6 . V_45 = F_2 ( V_2 -> V_45 ) ;
F_4 ( V_2 -> V_4 , V_133 ,
sizeof( V_6 ) , & V_6 ) ;
}
return 0 ;
}
static void F_63 ( struct V_1 * V_2 )
{
F_7 ( L_7 , V_2 ) ;
if ( ! F_62 ( V_134 , & V_2 -> V_127 ) ) {
struct V_135 V_6 ;
V_6 . V_45 = F_2 ( V_2 -> V_45 ) ;
V_6 . V_136 = 0x01 ;
F_4 ( V_2 -> V_4 , V_137 , sizeof( V_6 ) ,
& V_6 ) ;
}
}
int F_64 ( struct V_1 * V_2 , T_1 V_120 , T_1 V_80 )
{
F_7 ( L_7 , V_2 ) ;
if ( V_120 == V_138 )
return 1 ;
if ( V_120 == V_124 &&
( ! V_2 -> V_35 || ! V_2 -> V_4 -> V_35 ) )
return 1 ;
if ( ! ( V_2 -> V_10 & V_130 ) )
goto V_139;
if ( V_2 -> V_84 == V_140 )
goto V_136;
if ( V_2 -> V_84 == V_141 &&
( V_120 == V_142 ||
V_120 == V_124 ) )
goto V_136;
if ( V_2 -> V_84 == V_143 &&
( V_120 != V_144 ||
V_2 -> V_145 == 16 ) )
goto V_136;
V_139:
if ( F_52 ( V_134 , & V_2 -> V_127 ) )
return 0 ;
if ( ! F_61 ( V_2 , V_120 , V_80 ) )
return 0 ;
V_136:
if ( V_2 -> V_10 & V_129 )
return 1 ;
F_63 ( V_2 ) ;
return 0 ;
}
int F_65 ( struct V_1 * V_2 , T_1 V_120 )
{
F_7 ( L_7 , V_2 ) ;
if ( V_120 != V_144 )
return 1 ;
if ( V_2 -> V_84 == V_140 ||
( V_2 -> V_84 == V_143 &&
V_2 -> V_145 == 16 ) )
return 1 ;
return 0 ;
}
int F_66 ( struct V_1 * V_2 )
{
F_7 ( L_7 , V_2 ) ;
if ( ! F_62 ( V_131 , & V_2 -> V_127 ) ) {
struct V_146 V_6 ;
V_6 . V_45 = F_2 ( V_2 -> V_45 ) ;
F_4 ( V_2 -> V_4 , V_147 ,
sizeof( V_6 ) , & V_6 ) ;
}
return 0 ;
}
int F_67 ( struct V_1 * V_2 , T_1 V_148 )
{
F_7 ( L_7 , V_2 ) ;
if ( ! V_148 && V_2 -> V_10 & V_11 )
return 1 ;
if ( ! F_62 ( V_149 , & V_2 -> V_127 ) ) {
struct V_150 V_6 ;
F_3 ( & V_6 . V_28 , & V_2 -> V_15 ) ;
V_6 . V_148 = V_148 ;
F_4 ( V_2 -> V_4 , V_151 , sizeof( V_6 ) , & V_6 ) ;
}
return 0 ;
}
void F_58 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_7 ( L_3 , V_2 , V_2 -> V_74 ) ;
if ( F_52 ( V_119 , & V_4 -> V_118 ) )
return;
if ( V_2 -> V_74 != V_152 || ! V_2 -> V_85 )
goto V_153;
if ( ! F_62 ( V_126 , & V_2 -> V_127 ) ) {
struct V_154 V_6 ;
V_6 . V_45 = F_2 ( V_2 -> V_45 ) ;
F_4 ( V_4 , V_155 , sizeof( V_6 ) , & V_6 ) ;
}
V_153:
if ( V_4 -> V_156 > 0 )
F_68 ( & V_2 -> V_97 ,
V_157 + F_69 ( V_4 -> V_156 ) ) ;
}
void F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_7 ( L_3 , V_2 , V_2 -> V_74 ) ;
if ( F_52 ( V_119 , & V_4 -> V_118 ) )
return;
if ( ! F_70 ( V_4 ) || ! F_70 ( V_2 ) )
return;
if ( V_2 -> V_74 != V_78 || ! ( V_2 -> V_27 & V_158 ) )
return;
if ( F_71 ( V_4 ) && F_71 ( V_2 ) ) {
struct V_159 V_6 ;
V_6 . V_45 = F_2 ( V_2 -> V_45 ) ;
V_6 . V_52 = F_2 ( 0 ) ;
V_6 . V_160 = F_2 ( 0 ) ;
V_6 . V_161 = F_2 ( 0 ) ;
F_4 ( V_4 , V_162 , sizeof( V_6 ) , & V_6 ) ;
}
if ( ! F_62 ( V_126 , & V_2 -> V_127 ) ) {
struct V_163 V_6 ;
V_6 . V_45 = F_2 ( V_2 -> V_45 ) ;
V_6 . V_164 = F_2 ( V_4 -> V_165 ) ;
V_6 . V_166 = F_2 ( V_4 -> V_167 ) ;
V_6 . V_26 = F_2 ( 4 ) ;
V_6 . V_168 = F_2 ( 1 ) ;
F_4 ( V_4 , V_169 , sizeof( V_6 ) , & V_6 ) ;
}
}
void F_72 ( struct V_3 * V_4 )
{
struct V_170 * V_171 = & V_4 -> V_172 ;
struct V_112 * V_113 ;
F_7 ( L_8 , V_4 -> V_76 ) ;
V_113 = V_171 -> V_116 . V_173 ;
while ( V_113 != & V_171 -> V_116 ) {
struct V_1 * V_174 ;
V_174 = F_51 ( V_113 , struct V_1 , V_116 ) ;
V_113 = V_113 -> V_173 ;
V_174 -> V_7 = V_73 ;
F_73 ( V_174 , 0x16 ) ;
F_20 ( V_174 ) ;
}
}
void F_74 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
F_7 ( L_8 , V_4 -> V_76 ) ;
F_23 ( V_4 ) ;
V_2 = F_75 ( V_4 , V_69 , V_68 ) ;
if ( V_2 )
F_6 ( V_2 ) ;
F_25 ( V_4 ) ;
}
void F_76 ( struct V_1 * V_2 )
{
F_77 ( & V_2 -> V_102 ) ;
}
void F_44 ( struct V_1 * V_2 )
{
if ( F_78 ( & V_2 -> V_102 ) )
F_79 ( V_2 ) ;
}
int F_80 ( void T_5 * V_66 )
{
struct V_175 V_176 , * V_177 ;
struct V_178 * V_179 ;
struct V_3 * V_4 ;
struct V_112 * V_113 ;
int V_180 = 0 , V_181 , V_182 ;
if ( F_81 ( & V_176 , V_66 , sizeof( V_176 ) ) )
return - V_183 ;
if ( ! V_176 . V_184 || V_176 . V_184 > ( V_185 * 2 ) / sizeof( * V_179 ) )
return - V_186 ;
V_181 = sizeof( V_176 ) + V_176 . V_184 * sizeof( * V_179 ) ;
V_177 = F_82 ( V_181 , V_187 ) ;
if ( ! V_177 )
return - V_123 ;
V_4 = F_83 ( V_176 . V_188 ) ;
if ( ! V_4 ) {
F_46 ( V_177 ) ;
return - V_189 ;
}
V_179 = V_177 -> V_190 ;
F_84 ( V_4 ) ;
F_50 (p, &hdev->conn_hash.list) {
register struct V_1 * V_174 ;
V_174 = F_51 ( V_113 , struct V_1 , V_116 ) ;
F_3 ( & ( V_179 + V_180 ) -> V_28 , & V_174 -> V_15 ) ;
( V_179 + V_180 ) -> V_45 = V_174 -> V_45 ;
( V_179 + V_180 ) -> type = V_174 -> type ;
( V_179 + V_180 ) -> V_9 = V_174 -> V_9 ;
( V_179 + V_180 ) -> V_7 = V_174 -> V_7 ;
( V_179 + V_180 ) -> V_10 = V_174 -> V_10 ;
if ( ++ V_180 >= V_176 . V_184 )
break;
}
F_85 ( V_4 ) ;
V_177 -> V_188 = V_4 -> V_191 ;
V_177 -> V_184 = V_180 ;
V_181 = sizeof( V_176 ) + V_180 * sizeof( * V_179 ) ;
F_45 ( V_4 ) ;
V_182 = F_86 ( V_66 , V_177 , V_181 ) ;
F_46 ( V_177 ) ;
return V_182 ? - V_183 : 0 ;
}
int F_87 ( struct V_3 * V_4 , void T_5 * V_66 )
{
struct V_192 V_176 ;
struct V_178 V_179 ;
struct V_1 * V_2 ;
char T_5 * V_193 = V_66 + sizeof( V_176 ) ;
if ( F_81 ( & V_176 , V_66 , sizeof( V_176 ) ) )
return - V_183 ;
F_84 ( V_4 ) ;
V_2 = F_55 ( V_4 , V_176 . type , & V_176 . V_28 ) ;
if ( V_2 ) {
F_3 ( & V_179 . V_28 , & V_2 -> V_15 ) ;
V_179 . V_45 = V_2 -> V_45 ;
V_179 . type = V_2 -> type ;
V_179 . V_9 = V_2 -> V_9 ;
V_179 . V_7 = V_2 -> V_7 ;
V_179 . V_10 = V_2 -> V_10 ;
}
F_85 ( V_4 ) ;
if ( ! V_2 )
return - V_194 ;
return F_86 ( V_193 , & V_179 , sizeof( V_179 ) ) ? - V_183 : 0 ;
}
int F_88 ( struct V_3 * V_4 , void T_5 * V_66 )
{
struct V_195 V_176 ;
struct V_1 * V_2 ;
if ( F_81 ( & V_176 , V_66 , sizeof( V_176 ) ) )
return - V_183 ;
F_84 ( V_4 ) ;
V_2 = F_55 ( V_4 , V_69 , & V_176 . V_28 ) ;
if ( V_2 )
V_176 . type = V_2 -> V_80 ;
F_85 ( V_4 ) ;
if ( ! V_2 )
return - V_194 ;
return F_86 ( V_66 , & V_176 , sizeof( V_176 ) ) ? - V_183 : 0 ;
}
