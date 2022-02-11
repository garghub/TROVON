int F_1 ( struct V_1 * V_2 )
{
return F_2 ( & V_3 , V_2 ) ;
}
int F_3 ( struct V_1 * V_2 )
{
return F_4 ( & V_3 , V_2 ) ;
}
static void F_5 ( struct V_4 * V_5 , int V_6 )
{
F_6 ( & V_3 , V_6 , V_5 ) ;
}
void F_7 ( struct V_4 * V_5 , T_1 V_7 , int V_8 )
{
F_8 ( L_1 , V_5 -> V_9 , V_7 , V_8 ) ;
if ( F_9 ( V_10 , & V_5 -> V_11 ) && V_5 -> V_12 != V_7 )
return;
if ( V_5 -> V_13 == V_14 ) {
V_5 -> V_15 = V_8 ;
V_5 -> V_13 = V_16 ;
F_10 ( & V_5 -> V_17 ) ;
}
}
static void F_11 ( struct V_4 * V_5 , int V_18 )
{
F_8 ( L_2 , V_5 -> V_9 , V_18 ) ;
if ( V_5 -> V_13 == V_14 ) {
V_5 -> V_15 = V_18 ;
V_5 -> V_13 = V_19 ;
F_10 ( & V_5 -> V_17 ) ;
}
}
static int F_12 ( struct V_4 * V_5 , void (* F_13)( struct V_4 * V_5 , unsigned long V_20 ) ,
unsigned long V_20 , T_2 V_21 )
{
F_14 ( V_22 , V_23 ) ;
int V_18 = 0 ;
F_8 ( L_3 , V_5 -> V_9 ) ;
V_5 -> V_13 = V_14 ;
F_15 ( & V_5 -> V_17 , & V_22 ) ;
F_16 ( V_24 ) ;
F_13 ( V_5 , V_20 ) ;
F_17 ( V_21 ) ;
F_18 ( & V_5 -> V_17 , & V_22 ) ;
if ( F_19 ( V_23 ) )
return - V_25 ;
switch ( V_5 -> V_13 ) {
case V_16 :
V_18 = - F_20 ( V_5 -> V_15 ) ;
break;
case V_19 :
V_18 = - V_5 -> V_15 ;
break;
default:
V_18 = - V_26 ;
break;
}
V_5 -> V_13 = V_5 -> V_15 = 0 ;
F_8 ( L_4 , V_5 -> V_9 , V_18 ) ;
return V_18 ;
}
static inline int F_21 ( struct V_4 * V_5 , void (* F_13)( struct V_4 * V_5 , unsigned long V_20 ) ,
unsigned long V_20 , T_2 V_21 )
{
int V_27 ;
if ( ! F_9 ( V_28 , & V_5 -> V_11 ) )
return - V_29 ;
F_22 ( V_5 ) ;
V_27 = F_12 ( V_5 , F_13 , V_20 , V_21 ) ;
F_23 ( V_5 ) ;
return V_27 ;
}
static void F_24 ( struct V_4 * V_5 , unsigned long V_20 )
{
F_8 ( L_5 , V_5 -> V_9 , V_20 ) ;
F_25 ( V_30 , & V_5 -> V_11 ) ;
F_26 ( V_5 , V_31 , 0 , NULL ) ;
}
static void F_27 ( struct V_4 * V_5 )
{
struct V_32 V_33 ;
T_3 V_34 ;
T_4 V_35 ;
V_5 -> V_36 = V_37 ;
if ( ! F_9 ( V_38 , & V_5 -> V_39 ) ) {
F_25 ( V_30 , & V_5 -> V_11 ) ;
F_26 ( V_5 , V_31 , 0 , NULL ) ;
}
F_26 ( V_5 , V_40 , 0 , NULL ) ;
F_26 ( V_5 , V_41 , 0 , NULL ) ;
F_26 ( V_5 , V_42 , 0 , NULL ) ;
F_26 ( V_5 , V_43 , 0 , NULL ) ;
F_26 ( V_5 , V_44 , 0 , NULL ) ;
F_26 ( V_5 , V_45 , 0 , NULL ) ;
F_26 ( V_5 , V_46 , 0 , NULL ) ;
V_35 = V_47 ;
F_26 ( V_5 , V_48 , 1 , & V_35 ) ;
V_34 = F_28 ( 0x7d00 ) ;
F_26 ( V_5 , V_49 , 2 , & V_34 ) ;
F_29 ( & V_33 . V_50 , V_51 ) ;
V_33 . V_52 = 1 ;
F_26 ( V_5 , V_53 , sizeof( V_33 ) , & V_33 ) ;
}
static void F_30 ( struct V_4 * V_5 )
{
V_5 -> V_36 = V_54 ;
F_26 ( V_5 , V_31 , 0 , NULL ) ;
F_26 ( V_5 , V_41 , 0 , NULL ) ;
}
static void F_31 ( struct V_4 * V_5 , unsigned long V_20 )
{
struct V_55 * V_56 ;
F_8 ( L_5 , V_5 -> V_9 , V_20 ) ;
while ( ( V_56 = F_32 ( & V_5 -> V_57 ) ) ) {
F_33 ( V_56 ) -> V_58 = V_59 ;
V_56 -> V_60 = ( void * ) V_5 ;
F_34 ( & V_5 -> V_61 , V_56 ) ;
F_35 ( V_5 -> V_62 , & V_5 -> V_63 ) ;
}
F_36 ( & V_5 -> V_57 ) ;
switch ( V_5 -> V_64 ) {
case V_65 :
F_27 ( V_5 ) ;
break;
case V_66 :
F_30 ( V_5 ) ;
break;
default:
F_37 ( L_6 , V_5 -> V_64 ) ;
break;
}
}
static void F_38 ( struct V_4 * V_5 , unsigned long V_20 )
{
F_8 ( L_7 , V_5 -> V_9 ) ;
F_26 ( V_5 , V_67 , 0 , NULL ) ;
}
static void F_39 ( struct V_4 * V_5 , unsigned long V_20 )
{
T_4 V_68 = V_20 ;
F_8 ( L_8 , V_5 -> V_9 , V_68 ) ;
F_26 ( V_5 , V_69 , 1 , & V_68 ) ;
}
static void F_40 ( struct V_4 * V_5 , unsigned long V_20 )
{
T_4 V_70 = V_20 ;
F_8 ( L_8 , V_5 -> V_9 , V_70 ) ;
F_26 ( V_5 , V_71 , 1 , & V_70 ) ;
}
static void F_41 ( struct V_4 * V_5 , unsigned long V_20 )
{
T_4 V_72 = V_20 ;
F_8 ( L_8 , V_5 -> V_9 , V_72 ) ;
F_26 ( V_5 , V_73 , 1 , & V_72 ) ;
}
static void F_42 ( struct V_4 * V_5 , unsigned long V_20 )
{
T_3 V_74 = F_28 ( V_20 ) ;
F_8 ( L_8 , V_5 -> V_9 , V_74 ) ;
F_26 ( V_5 , V_75 , 2 , & V_74 ) ;
}
struct V_4 * F_43 ( int V_76 )
{
struct V_4 * V_5 = NULL , * V_77 ;
F_8 ( L_9 , V_76 ) ;
if ( V_76 < 0 )
return NULL ;
F_44 ( & V_78 ) ;
F_45 (d, &hci_dev_list, list) {
if ( V_77 -> V_79 == V_76 ) {
V_5 = F_46 ( V_77 ) ;
break;
}
}
F_47 ( & V_78 ) ;
return V_5 ;
}
static void F_48 ( struct V_4 * V_5 )
{
struct V_80 * V_81 = & V_5 -> V_82 ;
struct V_83 * V_84 = V_81 -> V_85 , * V_86 ;
F_8 ( L_10 , V_81 ) ;
V_81 -> V_85 = NULL ;
while ( ( V_86 = V_84 ) ) {
V_84 = V_86 -> V_84 ;
F_49 ( V_86 ) ;
}
}
struct V_83 * F_50 ( struct V_4 * V_5 , T_5 * V_50 )
{
struct V_80 * V_81 = & V_5 -> V_82 ;
struct V_83 * V_86 ;
F_8 ( L_11 , V_81 , F_51 ( V_50 ) ) ;
for ( V_86 = V_81 -> V_85 ; V_86 ; V_86 = V_86 -> V_84 )
if ( ! F_52 ( & V_86 -> V_87 . V_50 , V_50 ) )
break;
return V_86 ;
}
void F_53 ( struct V_4 * V_5 , struct V_88 * V_87 )
{
struct V_80 * V_81 = & V_5 -> V_82 ;
struct V_83 * V_89 ;
F_8 ( L_11 , V_81 , F_51 ( & V_87 -> V_50 ) ) ;
V_89 = F_50 ( V_5 , & V_87 -> V_50 ) ;
if ( ! V_89 ) {
V_89 = F_54 ( sizeof( struct V_83 ) , V_90 ) ;
if ( ! V_89 )
return;
V_89 -> V_84 = V_81 -> V_85 ;
V_81 -> V_85 = V_89 ;
}
memcpy ( & V_89 -> V_87 , V_87 , sizeof( * V_87 ) ) ;
V_89 -> V_91 = V_92 ;
V_81 -> V_91 = V_92 ;
}
static int F_55 ( struct V_4 * V_5 , int V_93 , T_4 * V_94 )
{
struct V_80 * V_81 = & V_5 -> V_82 ;
struct V_95 * V_96 = (struct V_95 * ) V_94 ;
struct V_83 * V_86 ;
int V_97 = 0 ;
for ( V_86 = V_81 -> V_85 ; V_86 && V_97 < V_93 ; V_86 = V_86 -> V_84 , V_97 ++ ) {
struct V_88 * V_87 = & V_86 -> V_87 ;
F_29 ( & V_96 -> V_50 , & V_87 -> V_50 ) ;
V_96 -> V_98 = V_87 -> V_98 ;
V_96 -> V_99 = V_87 -> V_99 ;
V_96 -> V_100 = V_87 -> V_100 ;
memcpy ( V_96 -> V_101 , V_87 -> V_101 , 3 ) ;
V_96 -> V_102 = V_87 -> V_102 ;
V_96 ++ ;
}
F_8 ( L_12 , V_81 , V_97 ) ;
return V_97 ;
}
static void F_56 ( struct V_4 * V_5 , unsigned long V_20 )
{
struct V_103 * V_104 = (struct V_103 * ) V_20 ;
struct V_105 V_33 ;
F_8 ( L_7 , V_5 -> V_9 ) ;
if ( F_9 ( V_106 , & V_5 -> V_11 ) )
return;
memcpy ( & V_33 . V_107 , & V_104 -> V_107 , 3 ) ;
V_33 . V_108 = V_104 -> V_108 ;
V_33 . V_109 = V_104 -> V_109 ;
F_26 ( V_5 , V_110 , sizeof( V_33 ) , & V_33 ) ;
}
int F_57 ( void T_6 * V_111 )
{
T_4 T_6 * V_112 = V_111 ;
struct V_103 V_104 ;
struct V_4 * V_5 ;
int V_18 = 0 , V_113 = 0 , V_114 ;
long V_115 ;
T_4 * V_94 ;
if ( F_58 ( & V_104 , V_112 , sizeof( V_104 ) ) )
return - V_116 ;
V_5 = F_43 ( V_104 . V_117 ) ;
if ( ! V_5 )
return - V_118 ;
F_59 ( V_5 ) ;
if ( F_60 ( V_5 ) > V_119 ||
F_61 ( V_5 ) ||
V_104 . V_11 & V_120 ) {
F_48 ( V_5 ) ;
V_113 = 1 ;
}
F_62 ( V_5 ) ;
V_115 = V_104 . V_108 * F_63 ( 2000 ) ;
if ( V_113 ) {
V_18 = F_21 ( V_5 , F_56 , ( unsigned long ) & V_104 , V_115 ) ;
if ( V_18 < 0 )
goto V_121;
}
V_114 = ( V_104 . V_109 == 0 ) ? 255 : V_104 . V_109 ;
V_94 = F_64 ( sizeof( struct V_95 ) * V_114 , V_122 ) ;
if ( ! V_94 ) {
V_18 = - V_123 ;
goto V_121;
}
F_59 ( V_5 ) ;
V_104 . V_109 = F_55 ( V_5 , V_114 , V_94 ) ;
F_62 ( V_5 ) ;
F_8 ( L_13 , V_104 . V_109 ) ;
if ( ! F_65 ( V_112 , & V_104 , sizeof( V_104 ) ) ) {
V_112 += sizeof( V_104 ) ;
if ( F_65 ( V_112 , V_94 , sizeof( struct V_95 ) *
V_104 . V_109 ) )
V_18 = - V_116 ;
} else
V_18 = - V_116 ;
F_49 ( V_94 ) ;
V_121:
F_66 ( V_5 ) ;
return V_18 ;
}
int F_67 ( T_1 V_60 )
{
struct V_4 * V_5 ;
int V_27 = 0 ;
V_5 = F_43 ( V_60 ) ;
if ( ! V_5 )
return - V_118 ;
F_8 ( L_14 , V_5 -> V_9 , V_5 ) ;
F_22 ( V_5 ) ;
if ( V_5 -> V_124 && F_68 ( V_5 -> V_124 ) ) {
V_27 = - V_125 ;
goto V_121;
}
if ( F_9 ( V_28 , & V_5 -> V_11 ) ) {
V_27 = - V_126 ;
goto V_121;
}
if ( F_9 ( V_127 , & V_5 -> V_39 ) )
F_25 ( V_128 , & V_5 -> V_11 ) ;
if ( V_5 -> V_64 != V_65 && ! V_129 )
F_25 ( V_128 , & V_5 -> V_11 ) ;
if ( V_5 -> V_130 ( V_5 ) ) {
V_27 = - V_131 ;
goto V_121;
}
if ( ! F_9 ( V_128 , & V_5 -> V_11 ) ) {
F_69 ( & V_5 -> V_132 , 1 ) ;
F_25 ( V_10 , & V_5 -> V_11 ) ;
V_5 -> V_12 = 0 ;
V_27 = F_12 ( V_5 , F_31 , 0 ,
F_63 ( V_133 ) ) ;
if ( F_70 ( V_5 ) )
V_27 = F_12 ( V_5 , F_38 , 0 ,
F_63 ( V_133 ) ) ;
F_71 ( V_10 , & V_5 -> V_11 ) ;
}
if ( ! V_27 ) {
F_46 ( V_5 ) ;
F_25 ( V_28 , & V_5 -> V_11 ) ;
F_5 ( V_5 , V_134 ) ;
if ( ! F_9 ( V_135 , & V_5 -> V_11 ) ) {
F_59 ( V_5 ) ;
F_72 ( V_5 , 1 ) ;
F_62 ( V_5 ) ;
}
} else {
F_73 ( & V_5 -> V_136 ) ;
F_73 ( & V_5 -> V_63 ) ;
F_73 ( & V_5 -> V_137 ) ;
F_36 ( & V_5 -> V_61 ) ;
F_36 ( & V_5 -> V_138 ) ;
if ( V_5 -> V_139 )
V_5 -> V_139 ( V_5 ) ;
if ( V_5 -> V_140 ) {
F_74 ( V_5 -> V_140 ) ;
V_5 -> V_140 = NULL ;
}
V_5 -> V_141 ( V_5 ) ;
V_5 -> V_11 = 0 ;
}
V_121:
F_23 ( V_5 ) ;
F_66 ( V_5 ) ;
return V_27 ;
}
static int F_75 ( struct V_4 * V_5 )
{
F_8 ( L_14 , V_5 -> V_9 , V_5 ) ;
F_11 ( V_5 , V_118 ) ;
F_22 ( V_5 ) ;
if ( ! F_76 ( V_28 , & V_5 -> V_11 ) ) {
F_77 ( & V_5 -> V_142 ) ;
F_23 ( V_5 ) ;
return 0 ;
}
F_73 ( & V_5 -> V_136 ) ;
F_73 ( & V_5 -> V_137 ) ;
if ( V_5 -> V_143 > 0 ) {
F_78 ( & V_5 -> V_144 ) ;
V_5 -> V_143 = 0 ;
}
if ( F_76 ( V_145 , & V_5 -> V_11 ) )
F_78 ( & V_5 -> V_146 ) ;
if ( F_76 ( V_147 , & V_5 -> V_11 ) )
F_78 ( & V_5 -> V_148 ) ;
F_59 ( V_5 ) ;
F_48 ( V_5 ) ;
F_79 ( V_5 ) ;
F_62 ( V_5 ) ;
F_5 ( V_5 , V_149 ) ;
if ( V_5 -> V_139 )
V_5 -> V_139 ( V_5 ) ;
F_36 ( & V_5 -> V_61 ) ;
F_69 ( & V_5 -> V_132 , 1 ) ;
if ( ! F_9 ( V_128 , & V_5 -> V_11 ) &&
F_9 ( V_38 , & V_5 -> V_39 ) ) {
F_25 ( V_10 , & V_5 -> V_11 ) ;
F_12 ( V_5 , F_24 , 0 ,
F_63 ( 250 ) ) ;
F_71 ( V_10 , & V_5 -> V_11 ) ;
}
F_73 ( & V_5 -> V_63 ) ;
F_36 ( & V_5 -> V_138 ) ;
F_36 ( & V_5 -> V_61 ) ;
F_36 ( & V_5 -> V_150 ) ;
if ( V_5 -> V_140 ) {
F_77 ( & V_5 -> V_142 ) ;
F_74 ( V_5 -> V_140 ) ;
V_5 -> V_140 = NULL ;
}
V_5 -> V_141 ( V_5 ) ;
F_59 ( V_5 ) ;
F_72 ( V_5 , 0 ) ;
F_62 ( V_5 ) ;
V_5 -> V_11 = 0 ;
F_23 ( V_5 ) ;
F_66 ( V_5 ) ;
return 0 ;
}
int F_80 ( T_1 V_60 )
{
struct V_4 * V_5 ;
int V_18 ;
V_5 = F_43 ( V_60 ) ;
if ( ! V_5 )
return - V_118 ;
V_18 = F_75 ( V_5 ) ;
F_66 ( V_5 ) ;
return V_18 ;
}
int F_81 ( T_1 V_60 )
{
struct V_4 * V_5 ;
int V_27 = 0 ;
V_5 = F_43 ( V_60 ) ;
if ( ! V_5 )
return - V_118 ;
F_22 ( V_5 ) ;
if ( ! F_9 ( V_28 , & V_5 -> V_11 ) )
goto V_121;
F_36 ( & V_5 -> V_138 ) ;
F_36 ( & V_5 -> V_61 ) ;
F_59 ( V_5 ) ;
F_48 ( V_5 ) ;
F_79 ( V_5 ) ;
F_62 ( V_5 ) ;
if ( V_5 -> V_139 )
V_5 -> V_139 ( V_5 ) ;
F_69 ( & V_5 -> V_132 , 1 ) ;
V_5 -> V_151 = 0 ; V_5 -> V_152 = 0 ; V_5 -> V_153 = 0 ;
if ( ! F_9 ( V_128 , & V_5 -> V_11 ) )
V_27 = F_12 ( V_5 , F_24 , 0 ,
F_63 ( V_133 ) ) ;
V_121:
F_23 ( V_5 ) ;
F_66 ( V_5 ) ;
return V_27 ;
}
int F_82 ( T_1 V_60 )
{
struct V_4 * V_5 ;
int V_27 = 0 ;
V_5 = F_43 ( V_60 ) ;
if ( ! V_5 )
return - V_118 ;
memset ( & V_5 -> V_154 , 0 , sizeof( struct V_155 ) ) ;
F_66 ( V_5 ) ;
return V_27 ;
}
int F_83 ( unsigned int V_7 , void T_6 * V_111 )
{
struct V_4 * V_5 ;
struct V_156 V_157 ;
int V_18 = 0 ;
if ( F_58 ( & V_157 , V_111 , sizeof( V_157 ) ) )
return - V_116 ;
V_5 = F_43 ( V_157 . V_117 ) ;
if ( ! V_5 )
return - V_118 ;
switch ( V_7 ) {
case V_158 :
V_18 = F_21 ( V_5 , F_40 , V_157 . V_159 ,
F_63 ( V_133 ) ) ;
break;
case V_160 :
if ( ! F_84 ( V_5 ) ) {
V_18 = - V_161 ;
break;
}
if ( ! F_9 ( V_162 , & V_5 -> V_11 ) ) {
V_18 = F_21 ( V_5 , F_40 , V_157 . V_159 ,
F_63 ( V_133 ) ) ;
if ( V_18 )
break;
}
V_18 = F_21 ( V_5 , F_41 , V_157 . V_159 ,
F_63 ( V_133 ) ) ;
break;
case V_163 :
V_18 = F_21 ( V_5 , F_39 , V_157 . V_159 ,
F_63 ( V_133 ) ) ;
break;
case V_164 :
V_18 = F_21 ( V_5 , F_42 , V_157 . V_159 ,
F_63 ( V_133 ) ) ;
break;
case V_165 :
V_5 -> V_166 = ( ( T_1 ) V_157 . V_159 ) &
( V_167 | V_168 ) ;
break;
case V_169 :
V_5 -> V_58 = ( T_1 ) V_157 . V_159 ;
break;
case V_170 :
V_5 -> V_171 = * ( ( T_1 * ) & V_157 . V_159 + 1 ) ;
V_5 -> V_172 = * ( ( T_1 * ) & V_157 . V_159 + 0 ) ;
break;
case V_173 :
V_5 -> V_174 = * ( ( T_1 * ) & V_157 . V_159 + 1 ) ;
V_5 -> V_175 = * ( ( T_1 * ) & V_157 . V_159 + 0 ) ;
break;
default:
V_18 = - V_176 ;
break;
}
F_66 ( V_5 ) ;
return V_18 ;
}
int F_85 ( void T_6 * V_111 )
{
struct V_4 * V_5 ;
struct V_177 * V_178 ;
struct V_156 * V_157 ;
int V_179 = 0 , V_180 , V_18 ;
T_1 V_181 ;
if ( F_86 ( V_181 , ( T_1 T_6 * ) V_111 ) )
return - V_116 ;
if ( ! V_181 || V_181 > ( V_182 * 2 ) / sizeof( * V_157 ) )
return - V_176 ;
V_180 = sizeof( * V_178 ) + V_181 * sizeof( * V_157 ) ;
V_178 = F_54 ( V_180 , V_122 ) ;
if ( ! V_178 )
return - V_123 ;
V_157 = V_178 -> V_183 ;
F_44 ( & V_78 ) ;
F_45 (hdev, &hci_dev_list, list) {
if ( F_76 ( V_145 , & V_5 -> V_11 ) )
F_78 ( & V_5 -> V_146 ) ;
if ( ! F_9 ( V_184 , & V_5 -> V_11 ) )
F_25 ( V_185 , & V_5 -> V_11 ) ;
( V_157 + V_179 ) -> V_117 = V_5 -> V_79 ;
( V_157 + V_179 ) -> V_159 = V_5 -> V_11 ;
if ( ++ V_179 >= V_181 )
break;
}
F_47 ( & V_78 ) ;
V_178 -> V_181 = V_179 ;
V_180 = sizeof( * V_178 ) + V_179 * sizeof( * V_157 ) ;
V_18 = F_65 ( V_111 , V_178 , V_180 ) ;
F_49 ( V_178 ) ;
return V_18 ? - V_116 : 0 ;
}
int F_87 ( void T_6 * V_111 )
{
struct V_4 * V_5 ;
struct V_186 V_187 ;
int V_18 = 0 ;
if ( F_58 ( & V_187 , V_111 , sizeof( V_187 ) ) )
return - V_116 ;
V_5 = F_43 ( V_187 . V_117 ) ;
if ( ! V_5 )
return - V_118 ;
if ( F_76 ( V_145 , & V_5 -> V_11 ) )
F_88 ( & V_5 -> V_146 ) ;
if ( ! F_9 ( V_184 , & V_5 -> V_11 ) )
F_25 ( V_185 , & V_5 -> V_11 ) ;
strcpy ( V_187 . V_9 , V_5 -> V_9 ) ;
V_187 . V_50 = V_5 -> V_50 ;
V_187 . type = ( V_5 -> V_188 & 0x0f ) | ( V_5 -> V_64 << 4 ) ;
V_187 . V_11 = V_5 -> V_11 ;
V_187 . V_58 = V_5 -> V_58 ;
V_187 . V_171 = V_5 -> V_171 ;
V_187 . V_172 = V_5 -> V_172 ;
V_187 . V_174 = V_5 -> V_174 ;
V_187 . V_175 = V_5 -> V_175 ;
V_187 . V_189 = V_5 -> V_189 ;
V_187 . V_166 = V_5 -> V_166 ;
memcpy ( & V_187 . V_154 , & V_5 -> V_154 , sizeof( V_187 . V_154 ) ) ;
memcpy ( & V_187 . V_190 , & V_5 -> V_190 , sizeof( V_187 . V_190 ) ) ;
if ( F_65 ( V_111 , & V_187 , sizeof( V_187 ) ) )
V_18 = - V_116 ;
F_66 ( V_5 ) ;
return V_18 ;
}
static int F_89 ( void * V_87 , bool V_191 )
{
struct V_4 * V_5 = V_87 ;
F_8 ( L_15 , V_5 , V_5 -> V_9 , V_191 ) ;
if ( ! V_191 )
return 0 ;
F_75 ( V_5 ) ;
return 0 ;
}
struct V_4 * F_90 ( void )
{
struct V_4 * V_5 ;
V_5 = F_54 ( sizeof( struct V_4 ) , V_122 ) ;
if ( ! V_5 )
return NULL ;
F_91 ( V_5 ) ;
F_92 ( & V_5 -> V_57 ) ;
return V_5 ;
}
void F_93 ( struct V_4 * V_5 )
{
F_36 ( & V_5 -> V_57 ) ;
F_94 ( & V_5 -> V_60 ) ;
}
static void F_95 ( struct V_192 * V_193 )
{
struct V_4 * V_5 = F_96 ( V_193 , struct V_4 , V_194 ) ;
F_8 ( L_7 , V_5 -> V_9 ) ;
if ( F_67 ( V_5 -> V_79 ) < 0 )
return;
if ( F_9 ( V_145 , & V_5 -> V_11 ) )
F_97 ( & V_5 -> V_146 ,
F_63 ( V_195 ) ) ;
if ( F_76 ( V_135 , & V_5 -> V_11 ) )
F_98 ( V_5 ) ;
}
static void F_99 ( struct V_192 * V_193 )
{
struct V_4 * V_5 = F_96 ( V_193 , struct V_4 ,
V_146 . V_193 ) ;
F_8 ( L_7 , V_5 -> V_9 ) ;
F_71 ( V_145 , & V_5 -> V_11 ) ;
F_80 ( V_5 -> V_79 ) ;
}
static void F_100 ( struct V_192 * V_193 )
{
struct V_4 * V_5 ;
T_7 V_68 = V_196 ;
V_5 = F_96 ( V_193 , struct V_4 , V_144 . V_193 ) ;
F_8 ( L_7 , V_5 -> V_9 ) ;
F_59 ( V_5 ) ;
F_26 ( V_5 , V_69 , sizeof( V_68 ) , & V_68 ) ;
V_5 -> V_143 = 0 ;
F_62 ( V_5 ) ;
}
int F_101 ( struct V_4 * V_5 )
{
struct V_197 * V_198 , * V_179 ;
F_102 (p, n, &hdev->uuids) {
struct V_199 * V_200 ;
V_200 = F_103 ( V_198 , struct V_199 , V_85 ) ;
F_104 ( V_198 ) ;
F_49 ( V_200 ) ;
}
return 0 ;
}
int F_105 ( struct V_4 * V_5 )
{
struct V_197 * V_198 , * V_179 ;
F_102 (p, n, &hdev->link_keys) {
struct V_201 * V_202 ;
V_202 = F_103 ( V_198 , struct V_201 , V_85 ) ;
F_104 ( V_198 ) ;
F_49 ( V_202 ) ;
}
return 0 ;
}
struct V_201 * F_106 ( struct V_4 * V_5 , T_5 * V_50 )
{
struct V_201 * V_203 ;
F_45 (k, &hdev->link_keys, list)
if ( F_52 ( V_50 , & V_203 -> V_50 ) == 0 )
return V_203 ;
return NULL ;
}
static int F_107 ( struct V_4 * V_5 , struct V_204 * V_205 ,
T_7 V_206 , T_7 V_207 )
{
if ( V_206 < 0x03 )
return 1 ;
if ( V_206 == V_208 )
return 0 ;
if ( V_206 == V_209 && V_207 == 0xff )
return 0 ;
if ( ! V_205 )
return 1 ;
if ( V_205 -> V_210 > 0x01 && V_205 -> V_211 > 0x01 )
return 1 ;
if ( V_205 -> V_210 == 0x02 || V_205 -> V_210 == 0x03 )
return 1 ;
if ( V_205 -> V_211 == 0x02 || V_205 -> V_211 == 0x03 )
return 1 ;
return 0 ;
}
struct V_201 * F_108 ( struct V_4 * V_5 , T_3 V_212 , T_7 rand [ 8 ] )
{
struct V_201 * V_203 ;
F_45 (k, &hdev->link_keys, list) {
struct V_213 * V_79 ;
if ( V_203 -> type != V_214 )
continue;
if ( V_203 -> V_215 != sizeof( * V_79 ) )
continue;
V_79 = ( void * ) & V_203 -> V_87 ;
if ( V_79 -> V_212 == V_212 &&
( memcmp ( rand , V_79 -> rand , sizeof( V_79 -> rand ) ) == 0 ) )
return V_203 ;
}
return NULL ;
}
struct V_201 * F_109 ( struct V_4 * V_5 ,
T_5 * V_50 , T_7 type )
{
struct V_201 * V_203 ;
F_45 (k, &hdev->link_keys, list)
if ( V_203 -> type == type && F_52 ( V_50 , & V_203 -> V_50 ) == 0 )
return V_203 ;
return NULL ;
}
int F_110 ( struct V_4 * V_5 , struct V_204 * V_205 , int V_216 ,
T_5 * V_50 , T_7 * V_217 , T_7 type , T_7 V_218 )
{
struct V_201 * V_202 , * V_219 ;
T_7 V_207 , V_220 ;
V_219 = F_106 ( V_5 , V_50 ) ;
if ( V_219 ) {
V_207 = V_219 -> type ;
V_202 = V_219 ;
} else {
V_207 = V_205 ? V_205 -> V_206 : 0xff ;
V_202 = F_54 ( sizeof( * V_202 ) , V_90 ) ;
if ( ! V_202 )
return - V_123 ;
F_111 ( & V_202 -> V_85 , & V_5 -> V_221 ) ;
}
F_8 ( L_16 , V_5 -> V_9 , F_51 ( V_50 ) , type ) ;
if ( type == V_209 &&
( ! V_205 || V_205 -> V_211 == 0xff ) &&
V_207 == 0xff ) {
type = V_222 ;
if ( V_205 )
V_205 -> V_206 = type ;
}
F_29 ( & V_202 -> V_50 , V_50 ) ;
memcpy ( V_202 -> V_217 , V_217 , 16 ) ;
V_202 -> V_218 = V_218 ;
if ( type == V_209 )
V_202 -> type = V_207 ;
else
V_202 -> type = type ;
if ( ! V_216 )
return 0 ;
V_220 = F_107 ( V_5 , V_205 , type , V_207 ) ;
F_112 ( V_5 , V_202 , V_220 ) ;
if ( ! V_220 ) {
F_104 ( & V_202 -> V_85 ) ;
F_49 ( V_202 ) ;
}
return 0 ;
}
int F_113 ( struct V_4 * V_5 , int V_216 , T_5 * V_50 ,
T_7 V_223 , T_3 V_212 , T_7 rand [ 8 ] , T_7 V_224 [ 16 ] )
{
struct V_201 * V_202 , * V_219 ;
struct V_213 * V_79 ;
T_7 V_207 ;
F_8 ( L_17 , V_5 -> V_9 , F_51 ( V_50 ) ) ;
V_219 = F_109 ( V_5 , V_50 , V_214 ) ;
if ( V_219 ) {
V_202 = V_219 ;
V_207 = V_219 -> type ;
} else {
V_202 = F_54 ( sizeof( * V_202 ) + sizeof( * V_79 ) , V_90 ) ;
if ( ! V_202 )
return - V_123 ;
F_111 ( & V_202 -> V_85 , & V_5 -> V_221 ) ;
V_207 = 0xff ;
}
V_202 -> V_215 = sizeof( * V_79 ) ;
F_29 ( & V_202 -> V_50 , V_50 ) ;
memcpy ( V_202 -> V_217 , V_224 , sizeof( V_202 -> V_217 ) ) ;
V_202 -> type = V_214 ;
V_202 -> V_218 = V_223 ;
V_79 = ( void * ) & V_202 -> V_87 ;
V_79 -> V_212 = V_212 ;
memcpy ( V_79 -> rand , rand , sizeof( V_79 -> rand ) ) ;
if ( V_216 )
F_112 ( V_5 , V_202 , V_207 ) ;
return 0 ;
}
int F_114 ( struct V_4 * V_5 , T_5 * V_50 )
{
struct V_201 * V_202 ;
V_202 = F_106 ( V_5 , V_50 ) ;
if ( ! V_202 )
return - V_225 ;
F_8 ( L_18 , V_5 -> V_9 , F_51 ( V_50 ) ) ;
F_104 ( & V_202 -> V_85 ) ;
F_49 ( V_202 ) ;
return 0 ;
}
static void F_115 ( unsigned long V_111 )
{
struct V_4 * V_5 = ( void * ) V_111 ;
F_37 ( L_19 , V_5 -> V_9 ) ;
F_69 ( & V_5 -> V_132 , 1 ) ;
F_35 ( V_5 -> V_62 , & V_5 -> V_63 ) ;
}
struct V_226 * F_116 ( struct V_4 * V_5 ,
T_5 * V_50 )
{
struct V_226 * V_87 ;
F_45 (data, &hdev->remote_oob_data, list)
if ( F_52 ( V_50 , & V_87 -> V_50 ) == 0 )
return V_87 ;
return NULL ;
}
int F_117 ( struct V_4 * V_5 , T_5 * V_50 )
{
struct V_226 * V_87 ;
V_87 = F_116 ( V_5 , V_50 ) ;
if ( ! V_87 )
return - V_225 ;
F_8 ( L_18 , V_5 -> V_9 , F_51 ( V_50 ) ) ;
F_104 ( & V_87 -> V_85 ) ;
F_49 ( V_87 ) ;
return 0 ;
}
int F_118 ( struct V_4 * V_5 )
{
struct V_226 * V_87 , * V_179 ;
F_119 (data, n, &hdev->remote_oob_data, list) {
F_104 ( & V_87 -> V_85 ) ;
F_49 ( V_87 ) ;
}
return 0 ;
}
int F_120 ( struct V_4 * V_5 , T_5 * V_50 , T_7 * V_227 ,
T_7 * V_228 )
{
struct V_226 * V_87 ;
V_87 = F_116 ( V_5 , V_50 ) ;
if ( ! V_87 ) {
V_87 = F_64 ( sizeof( * V_87 ) , V_90 ) ;
if ( ! V_87 )
return - V_123 ;
F_29 ( & V_87 -> V_50 , V_50 ) ;
F_111 ( & V_87 -> V_85 , & V_5 -> V_229 ) ;
}
memcpy ( V_87 -> V_227 , V_227 , sizeof( V_87 -> V_227 ) ) ;
memcpy ( V_87 -> V_228 , V_228 , sizeof( V_87 -> V_228 ) ) ;
F_8 ( L_20 , V_5 -> V_9 , F_51 ( V_50 ) ) ;
return 0 ;
}
struct V_230 * F_121 ( struct V_4 * V_5 ,
T_5 * V_50 )
{
struct V_230 * V_231 ;
F_45 (b, &hdev->blacklist, list)
if ( F_52 ( V_50 , & V_231 -> V_50 ) == 0 )
return V_231 ;
return NULL ;
}
int F_122 ( struct V_4 * V_5 )
{
struct V_197 * V_198 , * V_179 ;
F_102 (p, n, &hdev->blacklist) {
struct V_230 * V_231 ;
V_231 = F_103 ( V_198 , struct V_230 , V_85 ) ;
F_104 ( V_198 ) ;
F_49 ( V_231 ) ;
}
return 0 ;
}
int F_123 ( struct V_4 * V_5 , T_5 * V_50 )
{
struct V_230 * V_232 ;
if ( F_52 ( V_50 , V_51 ) == 0 )
return - V_233 ;
if ( F_121 ( V_5 , V_50 ) )
return - V_234 ;
V_232 = F_54 ( sizeof( struct V_230 ) , V_122 ) ;
if ( ! V_232 )
return - V_123 ;
F_29 ( & V_232 -> V_50 , V_50 ) ;
F_111 ( & V_232 -> V_85 , & V_5 -> V_235 ) ;
return F_124 ( V_5 , V_50 ) ;
}
int F_125 ( struct V_4 * V_5 , T_5 * V_50 )
{
struct V_230 * V_232 ;
if ( F_52 ( V_50 , V_51 ) == 0 )
return F_122 ( V_5 ) ;
V_232 = F_121 ( V_5 , V_50 ) ;
if ( ! V_232 )
return - V_225 ;
F_104 ( & V_232 -> V_85 ) ;
F_49 ( V_232 ) ;
return F_126 ( V_5 , V_50 ) ;
}
static void F_127 ( struct V_192 * V_193 )
{
struct V_4 * V_5 = F_96 ( V_193 , struct V_4 ,
V_236 . V_193 ) ;
F_59 ( V_5 ) ;
F_128 ( V_5 ) ;
F_62 ( V_5 ) ;
}
int F_128 ( struct V_4 * V_5 )
{
struct V_237 * V_232 , * V_238 ;
F_119 (entry, tmp, &hdev->adv_entries, list) {
F_104 ( & V_232 -> V_85 ) ;
F_49 ( V_232 ) ;
}
F_8 ( L_21 , V_5 -> V_9 ) ;
return 0 ;
}
struct V_237 * F_129 ( struct V_4 * V_5 , T_5 * V_50 )
{
struct V_237 * V_232 ;
F_45 (entry, &hdev->adv_entries, list)
if ( F_52 ( V_50 , & V_232 -> V_50 ) == 0 )
return V_232 ;
return NULL ;
}
static inline int F_130 ( T_7 V_239 )
{
if ( V_239 == V_240 || V_239 == V_241 )
return 1 ;
return 0 ;
}
int F_131 ( struct V_4 * V_5 ,
struct V_242 * V_243 )
{
struct V_237 * V_232 ;
if ( ! F_130 ( V_243 -> V_239 ) )
return - V_176 ;
if ( F_129 ( V_5 , & V_243 -> V_50 ) )
return 0 ;
V_232 = F_54 ( sizeof( * V_232 ) , V_90 ) ;
if ( ! V_232 )
return - V_123 ;
F_29 ( & V_232 -> V_50 , & V_243 -> V_50 ) ;
V_232 -> V_244 = V_243 -> V_244 ;
F_111 ( & V_232 -> V_85 , & V_5 -> V_245 ) ;
F_8 ( L_22 , V_5 -> V_9 ,
F_51 ( & V_232 -> V_50 ) , V_232 -> V_244 ) ;
return 0 ;
}
int F_132 ( struct V_4 * V_5 )
{
struct V_197 * V_246 = & V_247 , * V_198 ;
int V_248 , V_79 , error ;
F_8 ( L_23 , V_5 , V_5 -> V_9 ,
V_5 -> V_188 , V_5 -> V_249 ) ;
if ( ! V_5 -> V_130 || ! V_5 -> V_141 || ! V_5 -> V_250 )
return - V_176 ;
V_79 = ( V_5 -> V_64 == V_65 ) ? 0 : 1 ;
F_133 ( & V_78 ) ;
F_134 (p, &hci_dev_list) {
if ( F_103 ( V_198 , struct V_4 , V_85 ) -> V_79 != V_79 )
break;
V_246 = V_198 ; V_79 ++ ;
}
sprintf ( V_5 -> V_9 , L_24 , V_79 ) ;
V_5 -> V_79 = V_79 ;
F_135 ( & V_5 -> V_85 , V_246 ) ;
F_69 ( & V_5 -> V_251 , 1 ) ;
F_136 ( & V_5 -> V_252 ) ;
V_5 -> V_11 = 0 ;
V_5 -> V_253 = 0 ;
V_5 -> V_58 = ( V_254 | V_255 | V_256 ) ;
V_5 -> V_257 = ( V_258 ) ;
V_5 -> V_166 = ( V_168 ) ;
V_5 -> V_259 = 0x03 ;
V_5 -> V_260 = 0 ;
V_5 -> V_261 = 800 ;
V_5 -> V_262 = 80 ;
F_137 ( & V_5 -> V_137 , V_263 ) ;
F_137 ( & V_5 -> V_63 , V_264 ) ;
F_137 ( & V_5 -> V_136 , V_265 ) ;
F_92 ( & V_5 -> V_138 ) ;
F_92 ( & V_5 -> V_61 ) ;
F_92 ( & V_5 -> V_150 ) ;
F_138 ( & V_5 -> V_142 , F_115 , ( unsigned long ) V_5 ) ;
for ( V_248 = 0 ; V_248 < V_266 ; V_248 ++ )
V_5 -> V_267 [ V_248 ] = NULL ;
F_139 ( & V_5 -> V_17 ) ;
F_136 ( & V_5 -> V_268 ) ;
F_140 ( V_5 ) ;
F_141 ( V_5 ) ;
F_142 ( & V_5 -> V_269 ) ;
F_142 ( & V_5 -> V_235 ) ;
F_142 ( & V_5 -> V_270 ) ;
F_142 ( & V_5 -> V_221 ) ;
F_142 ( & V_5 -> V_229 ) ;
F_142 ( & V_5 -> V_245 ) ;
F_143 ( & V_5 -> V_236 , F_127 ) ;
F_137 ( & V_5 -> V_194 , F_95 ) ;
F_143 ( & V_5 -> V_146 , F_99 ) ;
F_143 ( & V_5 -> V_144 , F_100 ) ;
memset ( & V_5 -> V_154 , 0 , sizeof( struct V_155 ) ) ;
F_69 ( & V_5 -> V_271 , 0 ) ;
F_144 ( & V_78 ) ;
V_5 -> V_62 = F_145 ( V_5 -> V_9 , V_272 | V_273 |
V_274 , 1 ) ;
if ( ! V_5 -> V_62 ) {
error = - V_123 ;
goto V_18;
}
error = F_146 ( V_5 ) ;
if ( error < 0 )
goto V_275;
V_5 -> V_124 = F_147 ( V_5 -> V_9 , & V_5 -> V_60 ,
V_276 , & V_277 , V_5 ) ;
if ( V_5 -> V_124 ) {
if ( F_148 ( V_5 -> V_124 ) < 0 ) {
F_149 ( V_5 -> V_124 ) ;
V_5 -> V_124 = NULL ;
}
}
F_25 ( V_145 , & V_5 -> V_11 ) ;
F_25 ( V_135 , & V_5 -> V_11 ) ;
F_150 ( & V_5 -> V_194 ) ;
F_5 ( V_5 , V_278 ) ;
return V_79 ;
V_275:
F_151 ( V_5 -> V_62 ) ;
V_18:
F_133 ( & V_78 ) ;
F_104 ( & V_5 -> V_85 ) ;
F_144 ( & V_78 ) ;
return error ;
}
void F_152 ( struct V_4 * V_5 )
{
int V_248 ;
F_8 ( L_25 , V_5 , V_5 -> V_9 , V_5 -> V_188 ) ;
F_133 ( & V_78 ) ;
F_104 ( & V_5 -> V_85 ) ;
F_144 ( & V_78 ) ;
F_75 ( V_5 ) ;
for ( V_248 = 0 ; V_248 < V_266 ; V_248 ++ )
F_74 ( V_5 -> V_267 [ V_248 ] ) ;
if ( ! F_9 ( V_10 , & V_5 -> V_11 ) &&
! F_9 ( V_135 , & V_5 -> V_11 ) ) {
F_59 ( V_5 ) ;
F_153 ( V_5 ) ;
F_62 ( V_5 ) ;
}
F_154 ( ! F_155 ( & V_5 -> V_269 ) ) ;
F_5 ( V_5 , V_279 ) ;
if ( V_5 -> V_124 ) {
F_156 ( V_5 -> V_124 ) ;
F_149 ( V_5 -> V_124 ) ;
}
F_157 ( V_5 ) ;
F_88 ( & V_5 -> V_236 ) ;
F_151 ( V_5 -> V_62 ) ;
F_59 ( V_5 ) ;
F_122 ( V_5 ) ;
F_101 ( V_5 ) ;
F_105 ( V_5 ) ;
F_118 ( V_5 ) ;
F_128 ( V_5 ) ;
F_62 ( V_5 ) ;
F_158 ( V_5 ) ;
}
int F_159 ( struct V_4 * V_5 )
{
F_5 ( V_5 , V_280 ) ;
return 0 ;
}
int F_160 ( struct V_4 * V_5 )
{
F_5 ( V_5 , V_281 ) ;
return 0 ;
}
int F_161 ( struct V_55 * V_56 )
{
struct V_4 * V_5 = (struct V_4 * ) V_56 -> V_60 ;
if ( ! V_5 || ( ! F_9 ( V_28 , & V_5 -> V_11 )
&& ! F_9 ( V_10 , & V_5 -> V_11 ) ) ) {
F_74 ( V_56 ) ;
return - V_282 ;
}
F_33 ( V_56 ) -> V_283 = 1 ;
F_162 ( V_56 ) ;
F_34 ( & V_5 -> V_138 , V_56 ) ;
F_35 ( V_5 -> V_62 , & V_5 -> V_137 ) ;
return 0 ;
}
static int F_163 ( struct V_4 * V_5 , int type , void * V_87 ,
int V_284 , T_4 V_76 )
{
int V_285 = 0 ;
int V_286 = 0 ;
int V_287 = V_284 ;
struct V_55 * V_56 ;
struct V_288 * V_289 ;
if ( ( type < V_290 || type > V_291 ) ||
V_76 >= V_266 )
return - V_292 ;
V_56 = V_5 -> V_267 [ V_76 ] ;
if ( ! V_56 ) {
switch ( type ) {
case V_290 :
V_285 = V_293 ;
V_286 = V_294 ;
break;
case V_291 :
V_285 = V_295 ;
V_286 = V_296 ;
break;
case V_297 :
V_285 = V_298 ;
V_286 = V_299 ;
break;
}
V_56 = F_164 ( V_285 , V_90 ) ;
if ( ! V_56 )
return - V_123 ;
V_289 = ( void * ) V_56 -> V_300 ;
V_289 -> V_301 = V_286 ;
V_289 -> V_58 = type ;
V_56 -> V_60 = ( void * ) V_5 ;
V_5 -> V_267 [ V_76 ] = V_56 ;
}
while ( V_284 ) {
V_289 = ( void * ) V_56 -> V_300 ;
V_285 = F_165 ( V_289 -> V_301 , ( T_1 ) V_284 ) ;
memcpy ( F_166 ( V_56 , V_285 ) , V_87 , V_285 ) ;
V_284 -= V_285 ;
V_87 += V_285 ;
V_289 -> V_301 -= V_285 ;
V_287 = V_284 ;
switch ( type ) {
case V_291 :
if ( V_56 -> V_285 == V_296 ) {
struct V_302 * V_303 = V_302 ( V_56 ) ;
V_289 -> V_301 = V_303 -> V_304 ;
if ( F_167 ( V_56 ) < V_289 -> V_301 ) {
F_74 ( V_56 ) ;
V_5 -> V_267 [ V_76 ] = NULL ;
return - V_123 ;
}
}
break;
case V_290 :
if ( V_56 -> V_285 == V_294 ) {
struct V_305 * V_303 = V_305 ( V_56 ) ;
V_289 -> V_301 = F_168 ( V_303 -> V_215 ) ;
if ( F_167 ( V_56 ) < V_289 -> V_301 ) {
F_74 ( V_56 ) ;
V_5 -> V_267 [ V_76 ] = NULL ;
return - V_123 ;
}
}
break;
case V_297 :
if ( V_56 -> V_285 == V_299 ) {
struct V_306 * V_303 = V_306 ( V_56 ) ;
V_289 -> V_301 = V_303 -> V_215 ;
if ( F_167 ( V_56 ) < V_289 -> V_301 ) {
F_74 ( V_56 ) ;
V_5 -> V_267 [ V_76 ] = NULL ;
return - V_123 ;
}
}
break;
}
if ( V_289 -> V_301 == 0 ) {
F_33 ( V_56 ) -> V_58 = type ;
F_161 ( V_56 ) ;
V_5 -> V_267 [ V_76 ] = NULL ;
return V_287 ;
}
}
return V_287 ;
}
int F_169 ( struct V_4 * V_5 , int type , void * V_87 , int V_284 )
{
int V_307 = 0 ;
if ( type < V_290 || type > V_291 )
return - V_292 ;
while ( V_284 ) {
V_307 = F_163 ( V_5 , type , V_87 , V_284 , type - 1 ) ;
if ( V_307 < 0 )
return V_307 ;
V_87 += ( V_284 - V_307 ) ;
V_284 = V_307 ;
}
return V_307 ;
}
int F_170 ( struct V_4 * V_5 , void * V_87 , int V_284 )
{
int type ;
int V_307 = 0 ;
while ( V_284 ) {
struct V_55 * V_56 = V_5 -> V_267 [ V_308 ] ;
if ( ! V_56 ) {
struct { char type ; } * V_309 ;
V_309 = V_87 ;
type = V_309 -> type ;
V_87 ++ ;
V_284 -- ;
} else
type = F_33 ( V_56 ) -> V_58 ;
V_307 = F_163 ( V_5 , type , V_87 , V_284 ,
V_308 ) ;
if ( V_307 < 0 )
return V_307 ;
V_87 += ( V_284 - V_307 ) ;
V_284 = V_307 ;
}
return V_307 ;
}
int F_171 ( struct V_310 * V_300 )
{
F_8 ( L_26 , V_300 , V_300 -> V_9 ) ;
F_133 ( & V_311 ) ;
F_111 ( & V_300 -> V_85 , & V_312 ) ;
F_144 ( & V_311 ) ;
return 0 ;
}
int F_172 ( struct V_310 * V_300 )
{
F_8 ( L_26 , V_300 , V_300 -> V_9 ) ;
F_133 ( & V_311 ) ;
F_104 ( & V_300 -> V_85 ) ;
F_144 ( & V_311 ) ;
return 0 ;
}
static int F_173 ( struct V_55 * V_56 )
{
struct V_4 * V_5 = (struct V_4 * ) V_56 -> V_60 ;
if ( ! V_5 ) {
F_74 ( V_56 ) ;
return - V_118 ;
}
F_8 ( L_27 , V_5 -> V_9 , F_33 ( V_56 ) -> V_58 , V_56 -> V_285 ) ;
if ( F_174 ( & V_5 -> V_271 ) ) {
F_162 ( V_56 ) ;
F_175 ( V_5 , V_56 , NULL ) ;
}
F_176 ( V_56 ) ;
return V_5 -> V_313 ( V_56 ) ;
}
int F_26 ( struct V_4 * V_5 , T_1 V_314 , T_2 V_304 , void * V_34 )
{
int V_285 = V_315 + V_304 ;
struct V_316 * V_317 ;
struct V_55 * V_56 ;
F_8 ( L_28 , V_5 -> V_9 , V_314 , V_304 ) ;
V_56 = F_164 ( V_285 , V_90 ) ;
if ( ! V_56 ) {
F_37 ( L_29 , V_5 -> V_9 ) ;
return - V_123 ;
}
V_317 = (struct V_316 * ) F_166 ( V_56 , V_315 ) ;
V_317 -> V_314 = F_28 ( V_314 ) ;
V_317 -> V_304 = V_304 ;
if ( V_304 )
memcpy ( F_166 ( V_56 , V_304 ) , V_34 , V_304 ) ;
F_8 ( L_30 , V_56 -> V_285 ) ;
F_33 ( V_56 ) -> V_58 = V_59 ;
V_56 -> V_60 = ( void * ) V_5 ;
if ( F_9 ( V_10 , & V_5 -> V_11 ) )
V_5 -> V_12 = V_314 ;
F_34 ( & V_5 -> V_61 , V_56 ) ;
F_35 ( V_5 -> V_62 , & V_5 -> V_63 ) ;
return 0 ;
}
void * F_177 ( struct V_4 * V_5 , T_1 V_314 )
{
struct V_316 * V_317 ;
if ( ! V_5 -> V_140 )
return NULL ;
V_317 = ( void * ) V_5 -> V_140 -> V_87 ;
if ( V_317 -> V_314 != F_28 ( V_314 ) )
return NULL ;
F_8 ( L_31 , V_5 -> V_9 , V_314 ) ;
return V_5 -> V_140 -> V_87 + V_315 ;
}
static void F_178 ( struct V_55 * V_56 , T_1 V_318 , T_1 V_11 )
{
struct V_305 * V_317 ;
int V_285 = V_56 -> V_285 ;
F_179 ( V_56 , V_294 ) ;
F_180 ( V_56 ) ;
V_317 = (struct V_305 * ) F_181 ( V_56 ) ;
V_317 -> V_318 = F_28 ( F_182 ( V_318 , V_11 ) ) ;
V_317 -> V_215 = F_28 ( V_285 ) ;
}
static void F_183 ( struct V_204 * V_205 , struct V_319 * V_320 ,
struct V_55 * V_56 , T_1 V_11 )
{
struct V_4 * V_5 = V_205 -> V_5 ;
struct V_55 * V_85 ;
V_85 = F_184 ( V_56 ) -> V_321 ;
if ( ! V_85 ) {
F_8 ( L_32 , V_5 -> V_9 , V_56 , V_56 -> V_285 ) ;
F_34 ( V_320 , V_56 ) ;
} else {
F_8 ( L_33 , V_5 -> V_9 , V_56 , V_56 -> V_285 ) ;
F_184 ( V_56 ) -> V_321 = NULL ;
F_185 ( & V_320 -> V_252 ) ;
F_186 ( V_320 , V_56 ) ;
V_11 &= ~ V_322 ;
V_11 |= V_323 ;
do {
V_56 = V_85 ; V_85 = V_85 -> V_84 ;
V_56 -> V_60 = ( void * ) V_5 ;
F_33 ( V_56 ) -> V_58 = V_290 ;
F_178 ( V_56 , V_205 -> V_318 , V_11 ) ;
F_8 ( L_33 , V_5 -> V_9 , V_56 , V_56 -> V_285 ) ;
F_186 ( V_320 , V_56 ) ;
} while ( V_85 );
F_187 ( & V_320 -> V_252 ) ;
}
}
void F_188 ( struct V_324 * V_325 , struct V_55 * V_56 , T_1 V_11 )
{
struct V_204 * V_205 = V_325 -> V_205 ;
struct V_4 * V_5 = V_205 -> V_5 ;
F_8 ( L_34 , V_5 -> V_9 , V_325 , V_11 ) ;
V_56 -> V_60 = ( void * ) V_5 ;
F_33 ( V_56 ) -> V_58 = V_290 ;
F_178 ( V_56 , V_205 -> V_318 , V_11 ) ;
F_183 ( V_205 , & V_325 -> V_326 , V_56 , V_11 ) ;
F_35 ( V_5 -> V_62 , & V_5 -> V_136 ) ;
}
void F_189 ( struct V_204 * V_205 , struct V_55 * V_56 )
{
struct V_4 * V_5 = V_205 -> V_5 ;
struct V_306 V_317 ;
F_8 ( L_35 , V_5 -> V_9 , V_56 -> V_285 ) ;
V_317 . V_318 = F_28 ( V_205 -> V_318 ) ;
V_317 . V_215 = V_56 -> V_285 ;
F_179 ( V_56 , V_299 ) ;
F_180 ( V_56 ) ;
memcpy ( F_181 ( V_56 ) , & V_317 , V_299 ) ;
V_56 -> V_60 = ( void * ) V_5 ;
F_33 ( V_56 ) -> V_58 = V_297 ;
F_34 ( & V_205 -> V_326 , V_56 ) ;
F_35 ( V_5 -> V_62 , & V_5 -> V_136 ) ;
}
static inline struct V_204 * F_190 ( struct V_4 * V_5 , T_4 type , int * V_327 )
{
struct V_328 * V_303 = & V_5 -> V_329 ;
struct V_204 * V_205 = NULL , * V_330 ;
int V_93 = 0 , F_165 = ~ 0 ;
F_191 () ;
F_192 (c, &h->list, list) {
if ( V_330 -> type != type || F_193 ( & V_330 -> V_326 ) )
continue;
if ( V_330 -> V_331 != V_332 && V_330 -> V_331 != V_333 )
continue;
V_93 ++ ;
if ( V_330 -> V_334 < F_165 ) {
F_165 = V_330 -> V_334 ;
V_205 = V_330 ;
}
if ( F_194 ( V_5 , type ) == V_93 )
break;
}
F_195 () ;
if ( V_205 ) {
int V_335 , V_336 ;
switch ( V_205 -> type ) {
case V_337 :
V_335 = V_5 -> V_151 ;
break;
case V_338 :
case V_339 :
V_335 = V_5 -> V_152 ;
break;
case V_340 :
V_335 = V_5 -> V_341 ? V_5 -> V_153 : V_5 -> V_151 ;
break;
default:
V_335 = 0 ;
F_37 ( L_36 ) ;
}
V_336 = V_335 / V_93 ;
* V_327 = V_336 ? V_336 : 1 ;
} else
* V_327 = 0 ;
F_8 ( L_37 , V_205 , * V_327 ) ;
return V_205 ;
}
static inline void F_196 ( struct V_4 * V_5 , T_4 type )
{
struct V_328 * V_303 = & V_5 -> V_329 ;
struct V_204 * V_330 ;
F_37 ( L_38 , V_5 -> V_9 ) ;
F_191 () ;
F_192 (c, &h->list, list) {
if ( V_330 -> type == type && V_330 -> V_334 ) {
F_37 ( L_39 ,
V_5 -> V_9 , F_51 ( & V_330 -> V_342 ) ) ;
F_197 ( V_330 , 0x13 ) ;
}
}
F_195 () ;
}
static inline struct V_324 * F_198 ( struct V_4 * V_5 , T_4 type ,
int * V_327 )
{
struct V_328 * V_303 = & V_5 -> V_329 ;
struct V_324 * V_325 = NULL ;
int V_93 = 0 , F_165 = ~ 0 , V_343 = 0 ;
struct V_204 * V_205 ;
int V_335 , V_336 , V_344 = 0 ;
F_8 ( L_7 , V_5 -> V_9 ) ;
F_191 () ;
F_192 (conn, &h->list, list) {
struct V_324 * V_238 ;
if ( V_205 -> type != type )
continue;
if ( V_205 -> V_331 != V_332 && V_205 -> V_331 != V_333 )
continue;
V_344 ++ ;
F_192 (tmp, &conn->chan_list, list) {
struct V_55 * V_56 ;
if ( F_193 ( & V_238 -> V_326 ) )
continue;
V_56 = F_199 ( & V_238 -> V_326 ) ;
if ( V_56 -> V_345 < V_343 )
continue;
if ( V_56 -> V_345 > V_343 ) {
V_93 = 0 ;
F_165 = ~ 0 ;
V_343 = V_56 -> V_345 ;
}
V_93 ++ ;
if ( V_205 -> V_334 < F_165 ) {
F_165 = V_205 -> V_334 ;
V_325 = V_238 ;
}
}
if ( F_194 ( V_5 , type ) == V_344 )
break;
}
F_195 () ;
if ( ! V_325 )
return NULL ;
switch ( V_325 -> V_205 -> type ) {
case V_337 :
V_335 = V_5 -> V_151 ;
break;
case V_338 :
case V_339 :
V_335 = V_5 -> V_152 ;
break;
case V_340 :
V_335 = V_5 -> V_341 ? V_5 -> V_153 : V_5 -> V_151 ;
break;
default:
V_335 = 0 ;
F_37 ( L_36 ) ;
}
V_336 = V_335 / V_93 ;
* V_327 = V_336 ? V_336 : 1 ;
F_8 ( L_40 , V_325 , * V_327 ) ;
return V_325 ;
}
static void F_200 ( struct V_4 * V_5 , T_4 type )
{
struct V_328 * V_303 = & V_5 -> V_329 ;
struct V_204 * V_205 ;
int V_93 = 0 ;
F_8 ( L_7 , V_5 -> V_9 ) ;
F_191 () ;
F_192 (conn, &h->list, list) {
struct V_324 * V_325 ;
if ( V_205 -> type != type )
continue;
if ( V_205 -> V_331 != V_332 && V_205 -> V_331 != V_333 )
continue;
V_93 ++ ;
F_192 (chan, &conn->chan_list, list) {
struct V_55 * V_56 ;
if ( V_325 -> V_334 ) {
V_325 -> V_334 = 0 ;
continue;
}
if ( F_193 ( & V_325 -> V_326 ) )
continue;
V_56 = F_199 ( & V_325 -> V_326 ) ;
if ( V_56 -> V_345 >= V_346 - 1 )
continue;
V_56 -> V_345 = V_346 - 1 ;
F_8 ( L_41 , V_325 , V_56 ,
V_56 -> V_345 ) ;
}
if ( F_194 ( V_5 , type ) == V_93 )
break;
}
F_195 () ;
}
static inline void F_201 ( struct V_4 * V_5 )
{
struct V_324 * V_325 ;
struct V_55 * V_56 ;
int V_327 ;
unsigned int V_335 ;
F_8 ( L_7 , V_5 -> V_9 ) ;
if ( ! F_194 ( V_5 , V_337 ) )
return;
if ( ! F_9 ( V_128 , & V_5 -> V_11 ) ) {
if ( ! V_5 -> V_151 && F_202 ( V_92 , V_5 -> V_347 + V_348 * 45 ) )
F_196 ( V_5 , V_337 ) ;
}
V_335 = V_5 -> V_151 ;
while ( V_5 -> V_151 &&
( V_325 = F_198 ( V_5 , V_337 , & V_327 ) ) ) {
T_8 V_345 = ( F_199 ( & V_325 -> V_326 ) ) -> V_345 ;
while ( V_327 -- && ( V_56 = F_199 ( & V_325 -> V_326 ) ) ) {
F_8 ( L_42 , V_325 , V_56 ,
V_56 -> V_285 , V_56 -> V_345 ) ;
if ( V_56 -> V_345 < V_345 )
break;
V_56 = F_32 ( & V_325 -> V_326 ) ;
F_203 ( V_325 -> V_205 ,
F_33 ( V_56 ) -> V_349 ) ;
F_173 ( V_56 ) ;
V_5 -> V_347 = V_92 ;
V_5 -> V_151 -- ;
V_325 -> V_334 ++ ;
V_325 -> V_205 -> V_334 ++ ;
}
}
if ( V_335 != V_5 -> V_151 )
F_200 ( V_5 , V_337 ) ;
}
static inline void F_204 ( struct V_4 * V_5 )
{
struct V_204 * V_205 ;
struct V_55 * V_56 ;
int V_327 ;
F_8 ( L_7 , V_5 -> V_9 ) ;
if ( ! F_194 ( V_5 , V_338 ) )
return;
while ( V_5 -> V_152 && ( V_205 = F_190 ( V_5 , V_338 , & V_327 ) ) ) {
while ( V_327 -- && ( V_56 = F_32 ( & V_205 -> V_326 ) ) ) {
F_8 ( L_43 , V_56 , V_56 -> V_285 ) ;
F_173 ( V_56 ) ;
V_205 -> V_334 ++ ;
if ( V_205 -> V_334 == ~ 0 )
V_205 -> V_334 = 0 ;
}
}
}
static inline void F_205 ( struct V_4 * V_5 )
{
struct V_204 * V_205 ;
struct V_55 * V_56 ;
int V_327 ;
F_8 ( L_7 , V_5 -> V_9 ) ;
if ( ! F_194 ( V_5 , V_339 ) )
return;
while ( V_5 -> V_152 && ( V_205 = F_190 ( V_5 , V_339 , & V_327 ) ) ) {
while ( V_327 -- && ( V_56 = F_32 ( & V_205 -> V_326 ) ) ) {
F_8 ( L_43 , V_56 , V_56 -> V_285 ) ;
F_173 ( V_56 ) ;
V_205 -> V_334 ++ ;
if ( V_205 -> V_334 == ~ 0 )
V_205 -> V_334 = 0 ;
}
}
}
static inline void F_206 ( struct V_4 * V_5 )
{
struct V_324 * V_325 ;
struct V_55 * V_56 ;
int V_327 , V_335 , V_238 ;
F_8 ( L_7 , V_5 -> V_9 ) ;
if ( ! F_194 ( V_5 , V_340 ) )
return;
if ( ! F_9 ( V_128 , & V_5 -> V_11 ) ) {
if ( ! V_5 -> V_153 && V_5 -> V_350 &&
F_202 ( V_92 , V_5 -> V_351 + V_348 * 45 ) )
F_196 ( V_5 , V_340 ) ;
}
V_335 = V_5 -> V_350 ? V_5 -> V_153 : V_5 -> V_151 ;
V_238 = V_335 ;
while ( V_335 && ( V_325 = F_198 ( V_5 , V_340 , & V_327 ) ) ) {
T_8 V_345 = ( F_199 ( & V_325 -> V_326 ) ) -> V_345 ;
while ( V_327 -- && ( V_56 = F_199 ( & V_325 -> V_326 ) ) ) {
F_8 ( L_42 , V_325 , V_56 ,
V_56 -> V_285 , V_56 -> V_345 ) ;
if ( V_56 -> V_345 < V_345 )
break;
V_56 = F_32 ( & V_325 -> V_326 ) ;
F_173 ( V_56 ) ;
V_5 -> V_351 = V_92 ;
V_335 -- ;
V_325 -> V_334 ++ ;
V_325 -> V_205 -> V_334 ++ ;
}
}
if ( V_5 -> V_350 )
V_5 -> V_153 = V_335 ;
else
V_5 -> V_151 = V_335 ;
if ( V_335 != V_238 )
F_200 ( V_5 , V_340 ) ;
}
static void V_265 ( struct V_192 * V_193 )
{
struct V_4 * V_5 = F_96 ( V_193 , struct V_4 , V_136 ) ;
struct V_55 * V_56 ;
F_8 ( L_44 , V_5 -> V_9 , V_5 -> V_151 ,
V_5 -> V_152 , V_5 -> V_153 ) ;
F_201 ( V_5 ) ;
F_204 ( V_5 ) ;
F_205 ( V_5 ) ;
F_206 ( V_5 ) ;
while ( ( V_56 = F_32 ( & V_5 -> V_150 ) ) )
F_173 ( V_56 ) ;
}
static inline void F_207 ( struct V_4 * V_5 , struct V_55 * V_56 )
{
struct V_305 * V_317 = ( void * ) V_56 -> V_87 ;
struct V_204 * V_205 ;
T_1 V_318 , V_11 ;
F_208 ( V_56 , V_294 ) ;
V_318 = F_168 ( V_317 -> V_318 ) ;
V_11 = F_209 ( V_318 ) ;
V_318 = F_210 ( V_318 ) ;
F_8 ( L_45 , V_5 -> V_9 , V_56 -> V_285 , V_318 , V_11 ) ;
V_5 -> V_154 . V_352 ++ ;
F_59 ( V_5 ) ;
V_205 = F_211 ( V_5 , V_318 ) ;
F_62 ( V_5 ) ;
if ( V_205 ) {
F_203 ( V_205 , V_353 ) ;
F_212 ( V_205 , V_56 , V_11 ) ;
return;
} else {
F_37 ( L_46 ,
V_5 -> V_9 , V_318 ) ;
}
F_74 ( V_56 ) ;
}
static inline void F_213 ( struct V_4 * V_5 , struct V_55 * V_56 )
{
struct V_306 * V_317 = ( void * ) V_56 -> V_87 ;
struct V_204 * V_205 ;
T_1 V_318 ;
F_208 ( V_56 , V_299 ) ;
V_318 = F_168 ( V_317 -> V_318 ) ;
F_8 ( L_47 , V_5 -> V_9 , V_56 -> V_285 , V_318 ) ;
V_5 -> V_154 . V_354 ++ ;
F_59 ( V_5 ) ;
V_205 = F_211 ( V_5 , V_318 ) ;
F_62 ( V_5 ) ;
if ( V_205 ) {
F_214 ( V_205 , V_56 ) ;
return;
} else {
F_37 ( L_48 ,
V_5 -> V_9 , V_318 ) ;
}
F_74 ( V_56 ) ;
}
static void V_263 ( struct V_192 * V_193 )
{
struct V_4 * V_5 = F_96 ( V_193 , struct V_4 , V_137 ) ;
struct V_55 * V_56 ;
F_8 ( L_7 , V_5 -> V_9 ) ;
while ( ( V_56 = F_32 ( & V_5 -> V_138 ) ) ) {
if ( F_174 ( & V_5 -> V_271 ) ) {
F_175 ( V_5 , V_56 , NULL ) ;
}
if ( F_9 ( V_128 , & V_5 -> V_11 ) ) {
F_74 ( V_56 ) ;
continue;
}
if ( F_9 ( V_10 , & V_5 -> V_11 ) ) {
switch ( F_33 ( V_56 ) -> V_58 ) {
case V_290 :
case V_297 :
F_74 ( V_56 ) ;
continue;
}
}
switch ( F_33 ( V_56 ) -> V_58 ) {
case V_291 :
F_8 ( L_49 , V_5 -> V_9 ) ;
F_215 ( V_5 , V_56 ) ;
break;
case V_290 :
F_8 ( L_50 , V_5 -> V_9 ) ;
F_207 ( V_5 , V_56 ) ;
break;
case V_297 :
F_8 ( L_51 , V_5 -> V_9 ) ;
F_213 ( V_5 , V_56 ) ;
break;
default:
F_74 ( V_56 ) ;
break;
}
}
}
static void V_264 ( struct V_192 * V_193 )
{
struct V_4 * V_5 = F_96 ( V_193 , struct V_4 , V_63 ) ;
struct V_55 * V_56 ;
F_8 ( L_52 , V_5 -> V_9 , F_174 ( & V_5 -> V_132 ) ) ;
if ( F_174 ( & V_5 -> V_132 ) ) {
V_56 = F_32 ( & V_5 -> V_61 ) ;
if ( ! V_56 )
return;
F_74 ( V_5 -> V_140 ) ;
V_5 -> V_140 = F_216 ( V_56 , V_90 ) ;
if ( V_5 -> V_140 ) {
F_217 ( & V_5 -> V_132 ) ;
F_173 ( V_56 ) ;
if ( F_9 ( V_30 , & V_5 -> V_11 ) )
F_218 ( & V_5 -> V_142 ) ;
else
F_219 ( & V_5 -> V_142 ,
V_92 + F_63 ( V_355 ) ) ;
} else {
F_220 ( & V_5 -> V_61 , V_56 ) ;
F_35 ( V_5 -> V_62 , & V_5 -> V_63 ) ;
}
}
}
int F_221 ( struct V_4 * V_5 , T_7 V_108 )
{
T_7 V_107 [ 3 ] = { 0x33 , 0x8b , 0x9e } ;
struct V_105 V_33 ;
F_8 ( L_7 , V_5 -> V_9 ) ;
if ( F_9 ( V_106 , & V_5 -> V_11 ) )
return - V_356 ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
memcpy ( & V_33 . V_107 , V_107 , sizeof( V_33 . V_107 ) ) ;
V_33 . V_108 = V_108 ;
return F_26 ( V_5 , V_110 , sizeof( V_33 ) , & V_33 ) ;
}
int F_222 ( struct V_4 * V_5 )
{
F_8 ( L_7 , V_5 -> V_9 ) ;
if ( ! F_9 ( V_106 , & V_5 -> V_11 ) )
return - V_357 ;
return F_26 ( V_5 , V_358 , 0 , NULL ) ;
}
