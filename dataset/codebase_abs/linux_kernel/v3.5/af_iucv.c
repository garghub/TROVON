static inline void F_1 ( unsigned char * V_1 , char * V_2 )
{
memcpy ( V_1 , V_2 , 8 ) ;
}
static inline void F_2 ( unsigned char * V_1 , char * V_2 )
{
memcpy ( & V_1 [ 8 ] , V_2 , 8 ) ;
}
static int F_3 ( struct V_3 * V_4 )
{
#ifdef F_4
F_5 ( V_5 L_1 ) ;
#endif
return 0 ;
}
static void F_6 ( struct V_3 * V_4 )
{
#ifdef F_4
F_5 ( V_5 L_2 ) ;
#endif
}
static int F_7 ( struct V_3 * V_4 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
int V_12 = 0 ;
#ifdef F_4
F_5 ( V_5 L_3 ) ;
#endif
F_8 ( & V_13 . V_14 ) ;
F_9 (sk, node, &iucv_sk_list.head) {
V_7 = F_10 ( V_9 ) ;
switch ( V_9 -> V_15 ) {
case V_16 :
case V_17 :
case V_18 :
F_11 ( V_9 , 0 ) ;
break;
case V_19 :
case V_20 :
case V_21 :
case V_22 :
default:
break;
}
F_12 ( & V_7 -> V_23 ) ;
F_12 ( & V_7 -> V_24 ) ;
}
F_13 ( & V_13 . V_14 ) ;
return V_12 ;
}
static int F_14 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
#ifdef F_4
F_5 ( V_5 L_4 ) ;
#endif
F_8 ( & V_13 . V_14 ) ;
F_9 (sk, node, &iucv_sk_list.head) {
switch ( V_9 -> V_15 ) {
case V_18 :
V_9 -> V_25 = V_26 ;
V_9 -> V_15 = V_16 ;
V_9 -> V_27 ( V_9 ) ;
break;
case V_16 :
case V_17 :
case V_21 :
case V_20 :
case V_19 :
default:
break;
}
}
F_13 ( & V_13 . V_14 ) ;
return 0 ;
}
static inline T_1 F_15 ( struct V_28 * V_29 )
{
T_1 V_30 ;
if ( V_29 -> V_31 & V_32 ) {
V_30 = 0xff - V_29 -> V_33 [ 7 ] ;
return ( V_30 < 8 ) ? V_30 : 8 ;
}
return V_29 -> V_34 ;
}
static int F_16 ( struct V_8 * V_9 , int V_35 , int V_36 )
{
return ( V_9 -> V_15 == V_35 || V_9 -> V_15 == V_36 ) ;
}
static inline int F_17 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
if ( V_9 -> V_15 != V_18 )
return 1 ;
if ( V_7 -> V_37 == V_38 )
return ( F_18 ( & V_7 -> V_23 ) < V_7 -> V_39 -> V_40 ) ;
else
return ( ( F_19 ( & V_7 -> V_41 ) < V_7 -> V_42 ) &&
( F_19 ( & V_7 -> V_43 ) <= 0 ) ) ;
}
static void F_20 ( struct V_8 * V_9 )
{
struct V_44 * V_45 ;
F_21 () ;
V_45 = F_22 ( V_9 -> V_46 ) ;
if ( F_23 ( V_45 ) )
F_24 ( & V_45 -> V_47 ) ;
F_25 ( V_9 , V_48 , V_49 ) ;
F_26 () ;
}
static int F_27 ( struct V_28 * V_50 , struct V_8 * V_8 ,
struct V_51 * V_52 , T_2 V_31 )
{
struct V_6 * V_7 = F_10 ( V_8 ) ;
struct V_53 * V_54 ;
struct V_51 * V_55 ;
int V_12 , V_56 = 0 ;
memset ( V_52 -> V_57 , 0 , V_58 ) ;
V_54 = (struct V_53 * ) F_28 ( V_52 ,
sizeof( struct V_53 ) ) ;
F_29 ( V_52 ) ;
F_30 ( V_52 ) ;
F_28 ( V_52 , V_58 ) ;
F_29 ( V_52 ) ;
memset ( V_54 , 0 , sizeof( struct V_53 ) ) ;
V_54 -> V_59 = V_60 ;
V_54 -> V_61 = 1 ;
V_54 -> V_31 = V_31 ;
if ( V_31 == V_62 )
V_54 -> V_63 = V_7 -> V_64 ;
else if ( ( V_31 == V_65 ) || ! V_31 ) {
V_56 = F_19 ( & V_7 -> V_66 ) ;
V_54 -> V_63 = V_56 ;
if ( V_56 )
V_54 -> V_31 = V_54 -> V_31 | V_65 ;
}
memcpy ( V_54 -> V_67 , V_7 -> V_68 , 8 ) ;
memcpy ( V_54 -> V_69 , V_7 -> V_70 , 8 ) ;
memcpy ( V_54 -> V_71 , V_7 -> V_72 , 8 ) ;
memcpy ( V_54 -> V_73 , V_7 -> V_74 , 8 ) ;
F_31 ( V_54 -> V_67 , sizeof( V_54 -> V_67 ) ) ;
F_31 ( V_54 -> V_69 , sizeof( V_54 -> V_69 ) ) ;
F_31 ( V_54 -> V_71 , sizeof( V_54 -> V_71 ) ) ;
F_31 ( V_54 -> V_73 , sizeof( V_54 -> V_73 ) ) ;
if ( V_50 )
memcpy ( & V_54 -> V_75 , V_50 , sizeof( struct V_28 ) ) ;
V_52 -> V_4 = V_7 -> V_76 ;
if ( ! V_52 -> V_4 )
return - V_77 ;
if ( ! ( V_52 -> V_4 -> V_31 & V_78 ) || ! F_32 ( V_52 -> V_4 ) )
return - V_79 ;
if ( V_52 -> V_80 > V_52 -> V_4 -> V_81 ) {
if ( V_8 -> V_82 == V_83 )
return - V_84 ;
else
F_33 ( V_52 , V_52 -> V_4 -> V_81 ) ;
}
V_52 -> V_85 = V_60 ;
V_55 = F_34 ( V_52 , V_86 ) ;
if ( ! V_55 )
return - V_87 ;
F_35 ( & V_7 -> V_23 , V_55 ) ;
V_12 = F_36 ( V_52 ) ;
if ( F_37 ( V_12 ) ) {
F_38 ( V_55 , & V_7 -> V_23 ) ;
F_39 ( V_55 ) ;
} else {
F_40 ( V_56 , & V_7 -> V_66 ) ;
F_41 ( F_19 ( & V_7 -> V_66 ) < 0 ) ;
}
return F_37 ( V_12 ) ;
}
static struct V_8 * F_42 ( char * V_88 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
F_9 (sk, node, &iucv_sk_list.head)
if ( ! memcmp ( & F_10 ( V_9 ) -> V_74 , V_88 , 8 ) )
return V_9 ;
return NULL ;
}
static void F_43 ( struct V_8 * V_9 )
{
F_12 ( & V_9 -> V_89 ) ;
F_12 ( & V_9 -> V_90 ) ;
F_44 ( V_9 ) ;
if ( ! F_45 ( V_9 , V_91 ) ) {
F_46 ( L_5 , V_9 ) ;
return;
}
F_41 ( F_19 ( & V_9 -> V_92 ) ) ;
F_41 ( F_19 ( & V_9 -> V_93 ) ) ;
F_41 ( V_9 -> V_94 ) ;
F_41 ( V_9 -> V_95 ) ;
}
static void F_47 ( struct V_8 * V_96 )
{
struct V_8 * V_9 ;
while ( ( V_9 = F_48 ( V_96 , NULL ) ) ) {
F_49 ( V_9 ) ;
F_50 ( V_9 ) ;
}
V_96 -> V_15 = V_22 ;
}
static void F_50 ( struct V_8 * V_9 )
{
if ( ! F_45 ( V_9 , V_97 ) || V_9 -> V_98 )
return;
F_51 ( & V_13 , V_9 ) ;
F_52 ( V_9 , V_91 ) ;
F_53 ( V_9 ) ;
}
static void F_11 ( struct V_8 * V_9 , int V_99 )
{
unsigned char V_100 [ 16 ] ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_101 * V_39 = V_7 -> V_39 ;
if ( V_7 -> V_39 ) {
V_7 -> V_39 = NULL ;
if ( V_99 ) {
F_2 ( V_100 , V_7 -> V_74 ) ;
F_1 ( V_100 , V_7 -> V_70 ) ;
F_31 ( V_100 , sizeof( V_100 ) ) ;
V_102 -> V_103 ( V_39 , V_100 ) ;
} else
V_102 -> V_103 ( V_39 , NULL ) ;
F_54 ( V_39 ) ;
}
}
static int F_55 ( struct V_8 * V_9 , T_2 V_31 )
{
int V_12 = 0 ;
int V_104 ;
struct V_51 * V_52 ;
V_104 = sizeof( struct V_53 ) + V_58 ;
V_52 = F_56 ( V_9 , V_104 , 1 , & V_12 ) ;
if ( V_52 ) {
F_57 ( V_52 , V_104 ) ;
V_12 = F_27 ( NULL , V_9 , V_52 , V_31 ) ;
}
return V_12 ;
}
static void F_49 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
unsigned long V_105 ;
int V_12 = 0 ;
F_58 ( V_9 ) ;
switch ( V_9 -> V_15 ) {
case V_21 :
F_47 ( V_9 ) ;
break;
case V_18 :
if ( V_7 -> V_37 == V_106 ) {
V_12 = F_55 ( V_9 , V_107 ) ;
V_9 -> V_15 = V_16 ;
V_9 -> V_27 ( V_9 ) ;
}
case V_16 :
V_9 -> V_15 = V_17 ;
V_9 -> V_27 ( V_9 ) ;
if ( ! V_12 && ! F_59 ( & V_7 -> V_23 ) ) {
if ( F_45 ( V_9 , V_108 ) && V_9 -> V_109 )
V_105 = V_9 -> V_109 ;
else
V_105 = V_110 ;
F_60 ( V_9 ,
F_16 ( V_9 , V_22 , 0 ) ,
V_105 ) ;
}
case V_17 :
V_9 -> V_15 = V_22 ;
V_9 -> V_27 ( V_9 ) ;
V_9 -> V_25 = V_111 ;
V_9 -> V_27 ( V_9 ) ;
F_12 ( & V_7 -> V_23 ) ;
F_12 ( & V_7 -> V_24 ) ;
default:
F_11 ( V_9 , 1 ) ;
}
if ( V_7 -> V_76 ) {
F_61 ( V_7 -> V_76 ) ;
V_7 -> V_76 = NULL ;
V_9 -> V_112 = 0 ;
}
F_52 ( V_9 , V_97 ) ;
F_62 ( V_9 ) ;
}
static void F_63 ( struct V_8 * V_9 , struct V_8 * V_96 )
{
if ( V_96 )
V_9 -> V_82 = V_96 -> V_82 ;
}
static struct V_8 * F_64 ( struct V_113 * V_8 , int V_114 , T_3 V_115 )
{
struct V_8 * V_9 ;
struct V_6 * V_7 ;
V_9 = F_65 ( & V_116 , V_117 , V_115 , & V_118 ) ;
if ( ! V_9 )
return NULL ;
V_7 = F_10 ( V_9 ) ;
F_66 ( V_8 , V_9 ) ;
F_67 ( & V_7 -> V_119 ) ;
F_68 ( & V_7 -> V_120 ) ;
F_69 ( & V_7 -> V_23 ) ;
F_67 ( & V_7 -> V_121 . V_122 ) ;
F_68 ( & V_7 -> V_121 . V_14 ) ;
F_69 ( & V_7 -> V_24 ) ;
V_7 -> V_123 = 0 ;
F_70 ( & V_7 -> V_43 , 0 ) ;
V_7 -> V_31 = 0 ;
V_7 -> V_64 = 0 ;
F_70 ( & V_7 -> V_41 , 0 ) ;
F_70 ( & V_7 -> V_66 , 0 ) ;
V_7 -> V_39 = NULL ;
V_7 -> V_124 = V_125 ;
memset ( & V_7 -> V_72 , 0 , 32 ) ;
if ( V_102 )
V_7 -> V_37 = V_38 ;
else
V_7 -> V_37 = V_106 ;
V_9 -> V_126 = F_43 ;
V_9 -> V_127 = V_128 ;
V_9 -> V_129 = V_130 ;
F_71 ( V_9 , V_97 ) ;
V_9 -> V_131 = V_114 ;
V_9 -> V_15 = V_19 ;
F_72 ( & V_13 , V_9 ) ;
return V_9 ;
}
static int F_73 ( struct V_132 * V_132 , struct V_113 * V_8 , int V_85 ,
int V_133 )
{
struct V_8 * V_9 ;
if ( V_85 && V_85 != V_117 )
return - V_134 ;
V_8 -> V_35 = V_135 ;
switch ( V_8 -> type ) {
case V_136 :
V_8 -> V_137 = & V_138 ;
break;
case V_83 :
V_8 -> V_137 = & V_138 ;
break;
default:
return - V_139 ;
}
V_9 = F_64 ( V_8 , V_85 , V_140 ) ;
if ( ! V_9 )
return - V_87 ;
F_63 ( V_9 , NULL ) ;
return 0 ;
}
void F_72 ( struct V_141 * V_142 , struct V_8 * V_9 )
{
F_74 ( & V_142 -> V_14 ) ;
F_75 ( V_9 , & V_142 -> V_57 ) ;
F_76 ( & V_142 -> V_14 ) ;
}
void F_51 ( struct V_141 * V_142 , struct V_8 * V_9 )
{
F_74 ( & V_142 -> V_14 ) ;
F_77 ( V_9 ) ;
F_76 ( & V_142 -> V_14 ) ;
}
void F_78 ( struct V_8 * V_96 , struct V_8 * V_9 )
{
unsigned long V_31 ;
struct V_6 * V_143 = F_10 ( V_96 ) ;
F_79 ( V_9 ) ;
F_80 ( & V_143 -> V_120 , V_31 ) ;
F_81 ( & F_10 ( V_9 ) -> V_119 , & V_143 -> V_119 ) ;
F_82 ( & V_143 -> V_120 , V_31 ) ;
F_10 ( V_9 ) -> V_96 = V_96 ;
F_83 ( V_96 ) ;
}
void F_84 ( struct V_8 * V_9 )
{
unsigned long V_31 ;
struct V_6 * V_143 = F_10 ( F_10 ( V_9 ) -> V_96 ) ;
F_80 ( & V_143 -> V_120 , V_31 ) ;
F_85 ( & F_10 ( V_9 ) -> V_119 ) ;
F_82 ( & V_143 -> V_120 , V_31 ) ;
F_86 ( F_10 ( V_9 ) -> V_96 ) ;
F_10 ( V_9 ) -> V_96 = NULL ;
F_53 ( V_9 ) ;
}
struct V_8 * F_48 ( struct V_8 * V_96 , struct V_113 * V_144 )
{
struct V_6 * V_145 , * V_146 ;
struct V_8 * V_9 ;
F_87 (isk, n, &iucv_sk(parent)->accept_q, accept_q) {
V_9 = (struct V_8 * ) V_145 ;
F_58 ( V_9 ) ;
if ( V_9 -> V_15 == V_22 ) {
F_84 ( V_9 ) ;
F_62 ( V_9 ) ;
continue;
}
if ( V_9 -> V_15 == V_18 ||
V_9 -> V_15 == V_16 ||
! V_144 ) {
F_84 ( V_9 ) ;
if ( V_144 )
F_88 ( V_9 , V_144 ) ;
F_62 ( V_9 ) ;
return V_9 ;
}
F_62 ( V_9 ) ;
}
return NULL ;
}
static int F_89 ( struct V_113 * V_8 , struct V_147 * V_148 ,
int V_149 )
{
struct V_150 * V_151 = (struct V_150 * ) V_148 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 ;
int V_12 = 0 ;
struct V_152 * V_4 ;
char V_153 [ 9 ] ;
if ( ! V_148 || V_148 -> V_154 != V_155 )
return - V_156 ;
F_58 ( V_9 ) ;
if ( V_9 -> V_15 != V_19 ) {
V_12 = - V_157 ;
goto V_158;
}
F_74 ( & V_13 . V_14 ) ;
V_7 = F_10 ( V_9 ) ;
if ( F_42 ( V_151 -> V_159 ) ) {
V_12 = - V_160 ;
goto V_161;
}
if ( V_7 -> V_39 )
goto V_161;
if ( V_102 )
if ( ! memcmp ( V_151 -> V_162 , V_163 , 8 ) )
goto V_164;
memcpy ( V_153 , V_151 -> V_162 , sizeof( V_153 ) ) ;
F_31 ( V_153 , 8 ) ;
F_21 () ;
F_90 (&init_net, dev) {
if ( ! memcmp ( V_4 -> V_165 , V_153 , 8 ) ) {
memcpy ( V_7 -> V_74 , V_151 -> V_159 , 8 ) ;
memcpy ( V_7 -> V_72 , V_151 -> V_162 , 8 ) ;
V_9 -> V_112 = V_4 -> V_166 ;
V_7 -> V_76 = V_4 ;
F_91 ( V_4 ) ;
V_9 -> V_15 = V_20 ;
V_7 -> V_37 = V_106 ;
if ( ! V_7 -> V_64 )
V_7 -> V_64 = V_167 ;
F_26 () ;
goto V_161;
}
}
F_26 () ;
V_164:
if ( V_102 ) {
memcpy ( V_7 -> V_74 , V_151 -> V_159 , 8 ) ;
memcpy ( V_7 -> V_72 , V_163 , 8 ) ;
V_9 -> V_15 = V_20 ;
V_7 -> V_37 = V_38 ;
if ( ! V_7 -> V_64 )
V_7 -> V_64 = V_168 ;
goto V_161;
}
V_12 = - V_77 ;
V_161:
F_76 ( & V_13 . V_14 ) ;
V_158:
F_62 ( V_9 ) ;
return V_12 ;
}
static int F_92 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
char V_169 [ 12 ] ;
int V_12 = 0 ;
if ( F_93 ( ! V_102 ) )
return - V_170 ;
memcpy ( V_7 -> V_72 , V_163 , 8 ) ;
F_74 ( & V_13 . V_14 ) ;
sprintf ( V_169 , L_6 , F_94 ( & V_13 . V_171 ) ) ;
while ( F_42 ( V_169 ) ) {
sprintf ( V_169 , L_6 ,
F_94 ( & V_13 . V_171 ) ) ;
}
F_76 ( & V_13 . V_14 ) ;
memcpy ( & V_7 -> V_74 , V_169 , 8 ) ;
if ( ! V_7 -> V_64 )
V_7 -> V_64 = V_168 ;
return V_12 ;
}
static int F_95 ( struct V_113 * V_8 , struct V_147 * V_148 )
{
struct V_150 * V_151 = (struct V_150 * ) V_148 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
unsigned char V_100 [ 16 ] ;
int V_12 ;
F_1 ( V_100 , V_151 -> V_159 ) ;
F_2 ( V_100 , V_7 -> V_74 ) ;
F_31 ( V_100 , sizeof( V_100 ) ) ;
V_7 -> V_39 = F_96 ( V_7 -> V_64 ,
V_32 , V_140 ) ;
if ( ! V_7 -> V_39 ) {
V_12 = - V_87 ;
goto V_158;
}
V_12 = V_102 -> V_172 ( V_7 -> V_39 , & V_173 ,
V_151 -> V_162 , NULL , V_100 ,
V_9 ) ;
if ( V_12 ) {
F_54 ( V_7 -> V_39 ) ;
V_7 -> V_39 = NULL ;
switch ( V_12 ) {
case 0x0b :
V_12 = - V_174 ;
break;
case 0x0d :
case 0x0e :
V_12 = - V_175 ;
break;
case 0x0f :
V_12 = - V_176 ;
break;
default:
V_12 = - V_177 ;
break;
}
}
V_158:
return V_12 ;
}
static int F_97 ( struct V_113 * V_8 , struct V_147 * V_148 ,
int V_178 , int V_31 )
{
struct V_150 * V_151 = (struct V_150 * ) V_148 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
int V_12 ;
if ( V_148 -> V_154 != V_155 || V_178 < sizeof( struct V_150 ) )
return - V_156 ;
if ( V_9 -> V_15 != V_19 && V_9 -> V_15 != V_20 )
return - V_157 ;
if ( V_9 -> V_15 == V_19 &&
V_7 -> V_37 == V_106 )
return - V_157 ;
if ( V_9 -> V_82 != V_136 && V_9 -> V_82 != V_83 )
return - V_156 ;
if ( V_9 -> V_15 == V_19 ) {
V_12 = F_92 ( V_9 ) ;
if ( F_93 ( V_12 ) )
return V_12 ;
}
F_58 ( V_9 ) ;
memcpy ( V_7 -> V_68 , V_151 -> V_162 , 8 ) ;
memcpy ( V_7 -> V_70 , V_151 -> V_159 , 8 ) ;
if ( V_7 -> V_37 == V_106 )
V_12 = F_55 ( V_8 -> V_9 , V_62 ) ;
else
V_12 = F_95 ( V_8 , V_148 ) ;
if ( V_12 )
goto V_158;
if ( V_9 -> V_15 != V_18 )
V_12 = F_60 ( V_9 , F_16 ( V_9 , V_18 ,
V_16 ) ,
F_98 ( V_9 , V_31 & V_179 ) ) ;
if ( V_9 -> V_15 == V_16 || V_9 -> V_15 == V_22 )
V_12 = - V_177 ;
if ( V_12 && V_7 -> V_37 == V_38 )
F_11 ( V_9 , 0 ) ;
V_158:
F_62 ( V_9 ) ;
return V_12 ;
}
static int F_99 ( struct V_113 * V_8 , int V_180 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
int V_12 ;
F_58 ( V_9 ) ;
V_12 = - V_156 ;
if ( V_9 -> V_15 != V_20 )
goto V_158;
if ( V_8 -> type != V_136 && V_8 -> type != V_83 )
goto V_158;
V_9 -> V_181 = V_180 ;
V_9 -> V_182 = 0 ;
V_9 -> V_15 = V_21 ;
V_12 = 0 ;
V_158:
F_62 ( V_9 ) ;
return V_12 ;
}
static int F_100 ( struct V_113 * V_8 , struct V_113 * V_144 ,
int V_31 )
{
F_101 ( V_47 , V_183 ) ;
struct V_8 * V_9 = V_8 -> V_9 , * V_184 ;
long V_105 ;
int V_12 = 0 ;
F_102 ( V_9 , V_185 ) ;
if ( V_9 -> V_15 != V_21 ) {
V_12 = - V_157 ;
goto V_158;
}
V_105 = F_103 ( V_9 , V_31 & V_179 ) ;
F_104 ( F_105 ( V_9 ) , & V_47 ) ;
while ( ! ( V_184 = F_48 ( V_9 , V_144 ) ) ) {
F_106 ( V_186 ) ;
if ( ! V_105 ) {
V_12 = - V_175 ;
break;
}
F_62 ( V_9 ) ;
V_105 = F_107 ( V_105 ) ;
F_102 ( V_9 , V_185 ) ;
if ( V_9 -> V_15 != V_21 ) {
V_12 = - V_157 ;
break;
}
if ( F_108 ( V_183 ) ) {
V_12 = F_109 ( V_105 ) ;
break;
}
}
F_106 ( V_187 ) ;
F_110 ( F_105 ( V_9 ) , & V_47 ) ;
if ( V_12 )
goto V_158;
V_144 -> V_35 = V_188 ;
V_158:
F_62 ( V_9 ) ;
return V_12 ;
}
static int F_111 ( struct V_113 * V_8 , struct V_147 * V_148 ,
int * V_80 , int V_189 )
{
struct V_150 * V_190 = (struct V_150 * ) V_148 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
V_148 -> V_154 = V_155 ;
* V_80 = sizeof( struct V_150 ) ;
if ( V_189 ) {
memcpy ( V_190 -> V_162 , V_7 -> V_68 , 8 ) ;
memcpy ( V_190 -> V_159 , V_7 -> V_70 , 8 ) ;
} else {
memcpy ( V_190 -> V_162 , V_7 -> V_72 , 8 ) ;
memcpy ( V_190 -> V_159 , V_7 -> V_74 , 8 ) ;
}
memset ( & V_190 -> V_191 , 0 , sizeof( V_190 -> V_191 ) ) ;
memset ( & V_190 -> V_192 , 0 , sizeof( V_190 -> V_192 ) ) ;
memset ( & V_190 -> V_193 , 0 , sizeof( V_190 -> V_193 ) ) ;
return 0 ;
}
static int F_112 ( struct V_101 * V_39 , struct V_28 * V_29 ,
struct V_51 * V_52 )
{
T_2 V_194 [ 8 ] ;
memcpy ( V_194 , ( void * ) V_52 -> V_195 , V_52 -> V_80 ) ;
V_194 [ 7 ] = 0xff - ( T_2 ) V_52 -> V_80 ;
return V_102 -> V_196 ( V_39 , V_29 , V_32 , 0 ,
( void * ) V_194 , 8 ) ;
}
static int F_113 ( struct V_197 * V_198 , struct V_113 * V_8 ,
struct V_199 * V_29 , T_1 V_80 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_51 * V_52 ;
struct V_28 V_200 ;
struct V_201 * V_202 ;
int V_203 ;
long V_105 ;
char V_204 [ 9 ] ;
char V_205 [ 9 ] ;
int V_12 ;
int V_206 = V_29 -> V_207 & V_208 ;
V_12 = F_114 ( V_9 ) ;
if ( V_12 )
return V_12 ;
if ( V_29 -> V_207 & V_209 )
return - V_210 ;
if ( V_9 -> V_82 == V_83 && ! ( V_29 -> V_207 & V_211 ) )
return - V_210 ;
F_58 ( V_9 ) ;
if ( V_9 -> V_212 & V_213 ) {
V_12 = - V_26 ;
goto V_214;
}
if ( V_9 -> V_15 != V_18 ) {
V_12 = - V_215 ;
goto V_214;
}
V_203 = 0 ;
V_200 . V_216 = 0 ;
for ( V_202 = F_115 ( V_29 ) ; V_202 ;
V_202 = F_116 ( V_29 , V_202 ) ) {
if ( ! F_117 ( V_29 , V_202 ) ) {
V_12 = - V_156 ;
goto V_214;
}
if ( V_202 -> V_217 != V_218 )
continue;
if ( V_202 -> V_219 & V_203 ) {
V_12 = - V_156 ;
goto V_214;
}
V_203 |= V_202 -> V_219 ;
switch ( V_202 -> V_219 ) {
case V_220 :
if ( V_202 -> V_221 != F_118 ( V_222 ) ) {
V_12 = - V_156 ;
goto V_214;
}
memcpy ( & V_200 . V_216 ,
( void * ) F_119 ( V_202 ) , V_222 ) ;
break;
default:
V_12 = - V_156 ;
goto V_214;
break;
}
}
if ( V_7 -> V_37 == V_106 )
V_52 = F_56 ( V_9 ,
V_80 + sizeof( struct V_53 ) + V_58 ,
V_206 , & V_12 ) ;
else
V_52 = F_56 ( V_9 , V_80 , V_206 , & V_12 ) ;
if ( ! V_52 ) {
V_12 = - V_87 ;
goto V_214;
}
if ( V_7 -> V_37 == V_106 )
F_57 ( V_52 , sizeof( struct V_53 ) + V_58 ) ;
if ( F_120 ( F_121 ( V_52 , V_80 ) , V_29 -> V_223 , V_80 ) ) {
V_12 = - V_224 ;
goto V_225;
}
V_105 = F_98 ( V_9 , V_206 ) ;
V_12 = F_60 ( V_9 , F_17 ( V_9 ) , V_105 ) ;
if ( V_12 )
goto V_225;
if ( V_9 -> V_15 != V_18 ) {
V_12 = - V_111 ;
goto V_225;
}
V_200 . V_226 = V_7 -> V_123 ++ ;
memcpy ( F_122 ( V_52 ) , & V_200 . V_226 , V_227 ) ;
if ( V_7 -> V_37 == V_106 ) {
F_123 ( & V_7 -> V_41 ) ;
V_12 = F_27 ( & V_200 , V_9 , V_52 , 0 ) ;
if ( V_12 ) {
F_124 ( & V_7 -> V_41 ) ;
goto V_225;
}
goto V_228;
}
F_35 ( & V_7 -> V_23 , V_52 ) ;
if ( ( ( V_7 -> V_39 -> V_31 & V_32 ) & V_7 -> V_31 )
&& V_52 -> V_80 <= 7 ) {
V_12 = F_112 ( V_7 -> V_39 , & V_200 , V_52 ) ;
if ( V_12 == 0 ) {
F_38 ( V_52 , & V_7 -> V_23 ) ;
F_39 ( V_52 ) ;
}
if ( V_12 == 0x15 ) {
V_102 -> V_103 ( V_7 -> V_39 , NULL ) ;
F_38 ( V_52 , & V_7 -> V_23 ) ;
V_12 = - V_26 ;
goto V_225;
}
} else
V_12 = V_102 -> V_196 ( V_7 -> V_39 , & V_200 , 0 , 0 ,
( void * ) V_52 -> V_195 , V_52 -> V_80 ) ;
if ( V_12 ) {
if ( V_12 == 3 ) {
V_204 [ 8 ] = 0 ;
memcpy ( V_204 , V_7 -> V_68 , 8 ) ;
V_205 [ 8 ] = 0 ;
memcpy ( V_205 , V_7 -> V_70 , 8 ) ;
F_46 ( L_7
L_8 ,
V_205 , V_204 ) ;
V_12 = - V_175 ;
} else
V_12 = - V_26 ;
F_38 ( V_52 , & V_7 -> V_23 ) ;
goto V_225;
}
V_228:
F_62 ( V_9 ) ;
return V_80 ;
V_225:
F_39 ( V_52 ) ;
V_214:
F_62 ( V_9 ) ;
return V_12 ;
}
static int F_125 ( struct V_8 * V_9 , struct V_51 * V_52 , int V_80 )
{
int V_229 , V_230 , V_231 = 0 ;
struct V_51 * V_55 ;
V_229 = V_80 ;
while ( V_229 ) {
if ( V_229 >= V_9 -> V_232 / 4 )
V_230 = V_9 -> V_232 / 4 ;
else
V_230 = V_229 ;
V_55 = F_126 ( V_230 , V_86 | V_130 ) ;
if ( ! V_55 )
return - V_87 ;
memcpy ( F_127 ( V_55 ) , F_127 ( V_52 ) , V_233 ) ;
memcpy ( V_55 -> V_195 , V_52 -> V_195 + V_231 , V_230 ) ;
V_231 += V_230 ;
V_229 -= V_230 ;
F_128 ( V_55 ) ;
F_30 ( V_55 ) ;
V_55 -> V_80 = V_230 ;
F_35 ( & F_10 ( V_9 ) -> V_24 , V_55 ) ;
}
return 0 ;
}
static void F_129 ( struct V_8 * V_9 , struct V_51 * V_52 ,
struct V_101 * V_39 ,
struct V_28 * V_29 )
{
int V_234 ;
unsigned int V_80 ;
V_80 = F_15 ( V_29 ) ;
memcpy ( F_127 ( V_52 ) , & V_29 -> V_216 , V_233 ) ;
if ( ( V_29 -> V_31 & V_32 ) && V_80 > 7 ) {
if ( memcmp ( V_29 -> V_33 , V_235 , 8 ) == 0 ) {
V_52 -> V_195 = NULL ;
V_52 -> V_80 = 0 ;
}
} else {
V_234 = V_102 -> V_236 ( V_39 , V_29 ,
V_29 -> V_31 & V_32 ,
V_52 -> V_195 , V_80 , NULL ) ;
if ( V_234 ) {
F_39 ( V_52 ) ;
return;
}
if ( V_9 -> V_82 == V_136 &&
V_52 -> V_237 >= V_9 -> V_232 / 4 ) {
V_234 = F_125 ( V_9 , V_52 , V_80 ) ;
F_39 ( V_52 ) ;
V_52 = NULL ;
if ( V_234 ) {
V_102 -> V_103 ( V_39 , NULL ) ;
return;
}
V_52 = F_130 ( & F_10 ( V_9 ) -> V_24 ) ;
} else {
F_128 ( V_52 ) ;
F_30 ( V_52 ) ;
V_52 -> V_80 = V_80 ;
}
}
if ( F_131 ( V_9 , V_52 ) )
F_132 ( & F_10 ( V_9 ) -> V_24 , V_52 ) ;
}
static void F_133 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_51 * V_52 ;
struct V_238 * V_239 , * V_146 ;
F_87 (p, n, &iucv->message_q.list, list) {
V_52 = F_126 ( F_15 ( & V_239 -> V_29 ) , V_86 | V_130 ) ;
if ( ! V_52 )
break;
F_129 ( V_9 , V_52 , V_239 -> V_39 , & V_239 -> V_29 ) ;
F_134 ( & V_239 -> V_122 ) ;
F_135 ( V_239 ) ;
if ( ! F_59 ( & V_7 -> V_24 ) )
break;
}
}
static int F_136 ( struct V_197 * V_198 , struct V_113 * V_8 ,
struct V_199 * V_29 , T_1 V_80 , int V_31 )
{
int V_206 = V_31 & V_208 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
unsigned int V_231 , V_240 ;
struct V_51 * V_52 , * V_241 , * V_242 ;
int V_12 = 0 ;
if ( ( V_9 -> V_15 == V_16 ) &&
F_59 ( & V_7 -> V_24 ) &&
F_59 ( & V_9 -> V_89 ) &&
F_137 ( & V_7 -> V_121 . V_122 ) )
return 0 ;
if ( V_31 & ( V_209 ) )
return - V_210 ;
V_52 = F_138 ( V_9 , V_31 , V_206 , & V_12 ) ;
if ( ! V_52 ) {
if ( V_9 -> V_212 & V_243 )
return 0 ;
return V_12 ;
}
V_240 = V_52 -> V_80 ;
V_231 = F_139 (unsigned int, rlen, len) ;
if ( ! V_240 )
V_9 -> V_212 = V_9 -> V_212 | V_243 ;
V_242 = V_52 ;
if ( F_140 ( V_242 , 0 , V_29 -> V_223 , V_231 ) ) {
if ( ! ( V_31 & V_244 ) )
F_132 ( & V_9 -> V_89 , V_52 ) ;
return - V_224 ;
}
if ( V_9 -> V_82 == V_83 ) {
if ( V_231 < V_240 )
V_29 -> V_207 |= V_245 ;
V_29 -> V_207 |= V_211 ;
}
V_12 = F_141 ( V_29 , V_218 , V_220 ,
V_233 , F_127 ( V_52 ) ) ;
if ( V_12 ) {
if ( ! ( V_31 & V_244 ) )
F_132 ( & V_9 -> V_89 , V_52 ) ;
return V_12 ;
}
if ( ! ( V_31 & V_244 ) ) {
if ( V_9 -> V_82 == V_136 ) {
F_142 ( V_52 , V_231 ) ;
if ( V_52 -> V_80 ) {
F_132 ( & V_9 -> V_89 , V_52 ) ;
goto V_158;
}
}
F_39 ( V_52 ) ;
if ( V_7 -> V_37 == V_106 ) {
F_123 ( & V_7 -> V_66 ) ;
if ( F_19 ( & V_7 -> V_66 ) > V_7 -> V_64 ) {
F_41 ( 1 ) ;
F_49 ( V_9 ) ;
return - V_224 ;
}
}
F_143 ( & V_7 -> V_121 . V_14 ) ;
V_241 = F_130 ( & V_7 -> V_24 ) ;
while ( V_241 ) {
if ( F_131 ( V_9 , V_241 ) ) {
F_132 ( & V_7 -> V_24 ,
V_241 ) ;
break;
} else {
V_241 = F_130 ( & V_7 -> V_24 ) ;
}
}
if ( F_59 ( & V_7 -> V_24 ) ) {
if ( ! F_137 ( & V_7 -> V_121 . V_122 ) )
F_133 ( V_9 ) ;
if ( F_19 ( & V_7 -> V_66 ) >=
V_7 -> V_64 / 2 ) {
V_12 = F_55 ( V_9 , V_65 ) ;
if ( V_12 ) {
V_9 -> V_15 = V_16 ;
V_9 -> V_27 ( V_9 ) ;
}
}
}
F_144 ( & V_7 -> V_121 . V_14 ) ;
}
V_158:
if ( V_9 -> V_82 == V_83 && ( V_31 & V_245 ) )
V_231 = V_240 ;
return V_231 ;
}
static inline unsigned int F_145 ( struct V_8 * V_96 )
{
struct V_6 * V_145 , * V_146 ;
struct V_8 * V_9 ;
F_87 (isk, n, &iucv_sk(parent)->accept_q, accept_q) {
V_9 = (struct V_8 * ) V_145 ;
if ( V_9 -> V_15 == V_18 )
return V_246 | V_247 ;
}
return 0 ;
}
unsigned int F_146 ( struct V_248 * V_248 , struct V_113 * V_8 ,
T_4 * V_47 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
unsigned int V_249 = 0 ;
F_147 ( V_248 , F_105 ( V_9 ) , V_47 ) ;
if ( V_9 -> V_15 == V_21 )
return F_145 ( V_9 ) ;
if ( V_9 -> V_25 || ! F_59 ( & V_9 -> V_90 ) )
V_249 |= V_250 ;
if ( V_9 -> V_212 & V_243 )
V_249 |= V_251 ;
if ( V_9 -> V_212 == V_252 )
V_249 |= V_253 ;
if ( ! F_59 ( & V_9 -> V_89 ) ||
( V_9 -> V_212 & V_243 ) )
V_249 |= V_246 | V_247 ;
if ( V_9 -> V_15 == V_22 )
V_249 |= V_253 ;
if ( V_9 -> V_15 == V_16 )
V_249 |= V_246 ;
if ( F_148 ( V_9 ) && F_17 ( V_9 ) )
V_249 |= V_254 | V_255 | V_256 ;
else
F_149 ( V_257 , & V_9 -> V_98 -> V_31 ) ;
return V_249 ;
}
static int F_150 ( struct V_113 * V_8 , int V_258 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_28 V_200 ;
int V_12 = 0 ;
V_258 ++ ;
if ( ( V_258 & ~ V_252 ) || ! V_258 )
return - V_156 ;
F_58 ( V_9 ) ;
switch ( V_9 -> V_15 ) {
case V_21 :
case V_16 :
case V_17 :
case V_22 :
V_12 = - V_215 ;
goto V_225;
default:
break;
}
if ( V_258 == V_213 || V_258 == V_252 ) {
if ( V_7 -> V_37 == V_38 ) {
V_200 . V_216 = 0 ;
V_200 . V_226 = 0 ;
V_12 = V_102 -> V_196 ( V_7 -> V_39 , & V_200 ,
V_32 , 0 , ( void * ) V_235 , 8 ) ;
if ( V_12 ) {
switch ( V_12 ) {
case 1 :
V_12 = - V_215 ;
break;
case 2 :
V_12 = - V_111 ;
break;
default:
V_12 = - V_215 ;
break;
}
}
} else
F_55 ( V_9 , V_259 ) ;
}
V_9 -> V_212 |= V_258 ;
if ( V_258 == V_243 || V_258 == V_252 ) {
if ( V_7 -> V_37 == V_38 ) {
V_12 = V_102 -> V_260 ( V_7 -> V_39 , NULL ) ;
if ( V_12 )
V_12 = - V_215 ;
}
F_12 ( & V_9 -> V_89 ) ;
}
V_9 -> V_27 ( V_9 ) ;
V_225:
F_62 ( V_9 ) ;
return V_12 ;
}
static int F_151 ( struct V_113 * V_8 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
int V_12 = 0 ;
if ( ! V_9 )
return 0 ;
F_49 ( V_9 ) ;
F_152 ( V_9 ) ;
F_50 ( V_9 ) ;
return V_12 ;
}
static int F_153 ( struct V_113 * V_8 , int V_261 , int V_262 ,
char T_5 * V_263 , unsigned int V_264 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
int V_265 ;
int V_234 ;
if ( V_261 != V_218 )
return - V_266 ;
if ( V_264 < sizeof( int ) )
return - V_156 ;
if ( F_154 ( V_265 , ( int T_5 * ) V_263 ) )
return - V_224 ;
V_234 = 0 ;
F_58 ( V_9 ) ;
switch ( V_262 ) {
case V_267 :
if ( V_265 )
V_7 -> V_31 |= V_32 ;
else
V_7 -> V_31 &= ~ V_32 ;
break;
case V_268 :
switch ( V_9 -> V_15 ) {
case V_19 :
case V_20 :
if ( V_265 < 1 || V_265 > ( V_269 ) ( ~ 0 ) )
V_234 = - V_156 ;
else
V_7 -> V_64 = V_265 ;
break;
default:
V_234 = - V_156 ;
break;
}
break;
default:
V_234 = - V_266 ;
break;
}
F_62 ( V_9 ) ;
return V_234 ;
}
static int F_155 ( struct V_113 * V_8 , int V_261 , int V_262 ,
char T_5 * V_263 , int T_5 * V_264 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
unsigned int V_265 ;
int V_80 ;
if ( V_261 != V_218 )
return - V_266 ;
if ( F_154 ( V_80 , V_264 ) )
return - V_224 ;
if ( V_80 < 0 )
return - V_156 ;
V_80 = F_139 (unsigned int, len, sizeof(int)) ;
switch ( V_262 ) {
case V_267 :
V_265 = ( V_7 -> V_31 & V_32 ) ? 1 : 0 ;
break;
case V_268 :
F_58 ( V_9 ) ;
V_265 = ( V_7 -> V_39 != NULL ) ? V_7 -> V_39 -> V_40
: V_7 -> V_64 ;
F_62 ( V_9 ) ;
break;
case V_270 :
if ( V_9 -> V_15 == V_19 )
return - V_157 ;
V_265 = ( V_7 -> V_76 ) ? V_7 -> V_76 -> V_81 -
sizeof( struct V_53 ) - V_58 :
0x7fffffff ;
break;
default:
return - V_266 ;
}
if ( F_156 ( V_80 , V_264 ) )
return - V_224 ;
if ( F_157 ( V_263 , & V_265 , V_80 ) )
return - V_224 ;
return 0 ;
}
static int F_158 ( struct V_101 * V_39 ,
T_2 V_271 [ 8 ] , T_2 V_272 [ 16 ] )
{
unsigned char V_100 [ 16 ] ;
unsigned char V_273 [ 16 ] ;
unsigned char V_74 [ 8 ] ;
struct V_10 * V_11 ;
struct V_8 * V_9 , * V_184 ;
struct V_6 * V_7 , * V_274 ;
int V_12 ;
memcpy ( V_74 , V_272 , 8 ) ;
F_159 ( V_74 , 8 ) ;
F_8 ( & V_13 . V_14 ) ;
V_7 = NULL ;
V_9 = NULL ;
F_9 (sk, node, &iucv_sk_list.head)
if ( V_9 -> V_15 == V_21 &&
! memcmp ( & F_10 ( V_9 ) -> V_74 , V_74 , 8 ) ) {
V_7 = F_10 ( V_9 ) ;
break;
}
F_13 ( & V_13 . V_14 ) ;
if ( ! V_7 )
return - V_156 ;
F_160 ( V_9 ) ;
F_2 ( V_100 , V_7 -> V_74 ) ;
F_1 ( V_100 , V_7 -> V_70 ) ;
F_31 ( V_100 , sizeof( V_100 ) ) ;
if ( V_9 -> V_15 != V_21 ) {
V_12 = V_102 -> V_103 ( V_39 , V_100 ) ;
F_54 ( V_39 ) ;
goto V_225;
}
if ( F_161 ( V_9 ) ) {
V_12 = V_102 -> V_103 ( V_39 , V_100 ) ;
F_54 ( V_39 ) ;
goto V_225;
}
V_184 = F_64 ( NULL , V_9 -> V_82 , V_86 ) ;
if ( ! V_184 ) {
V_12 = V_102 -> V_103 ( V_39 , V_100 ) ;
F_54 ( V_39 ) ;
goto V_225;
}
V_274 = F_10 ( V_184 ) ;
F_63 ( V_184 , V_9 ) ;
memcpy ( V_274 -> V_70 , V_272 + 8 , 8 ) ;
F_159 ( V_274 -> V_70 , 8 ) ;
memcpy ( V_274 -> V_68 , V_271 , 8 ) ;
memcpy ( V_274 -> V_74 , V_7 -> V_74 , 8 ) ;
memcpy ( V_274 -> V_72 , V_7 -> V_72 , 8 ) ;
V_274 -> V_39 = V_39 ;
F_1 ( V_273 , V_272 + 8 ) ;
memcpy ( V_273 + 8 , V_274 -> V_74 , 8 ) ;
F_31 ( V_273 + 8 , 8 ) ;
V_274 -> V_64 = V_7 -> V_64 ;
V_39 -> V_40 = V_7 -> V_64 ;
V_12 = V_102 -> V_275 ( V_39 , & V_173 , V_273 , V_184 ) ;
if ( V_12 ) {
F_11 ( V_184 , 1 ) ;
F_50 ( V_184 ) ;
goto V_225;
}
F_78 ( V_9 , V_184 ) ;
V_184 -> V_15 = V_18 ;
V_9 -> V_276 ( V_9 , 1 ) ;
V_12 = 0 ;
V_225:
F_162 ( V_9 ) ;
return 0 ;
}
static void F_163 ( struct V_101 * V_39 , T_2 V_272 [ 16 ] )
{
struct V_8 * V_9 = V_39 -> V_277 ;
V_9 -> V_15 = V_18 ;
V_9 -> V_27 ( V_9 ) ;
}
static void F_164 ( struct V_101 * V_39 , struct V_28 * V_29 )
{
struct V_8 * V_9 = V_39 -> V_277 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_51 * V_52 ;
struct V_238 * V_278 ;
int V_80 ;
if ( V_9 -> V_212 & V_243 ) {
V_102 -> V_279 ( V_39 , V_29 ) ;
return;
}
F_165 ( & V_7 -> V_121 . V_14 ) ;
if ( ! F_137 ( & V_7 -> V_121 . V_122 ) ||
! F_59 ( & V_7 -> V_24 ) )
goto V_280;
V_80 = F_19 ( & V_9 -> V_92 ) ;
V_80 += F_166 ( F_15 ( V_29 ) ) ;
if ( V_80 > V_9 -> V_232 )
goto V_280;
V_52 = F_126 ( F_15 ( V_29 ) , V_86 | V_130 ) ;
if ( ! V_52 )
goto V_280;
F_129 ( V_9 , V_52 , V_39 , V_29 ) ;
goto V_281;
V_280:
V_278 = F_167 ( sizeof( struct V_238 ) , V_86 | V_130 ) ;
if ( ! V_278 )
goto V_281;
V_278 -> V_39 = V_39 ;
V_278 -> V_29 = * V_29 ;
F_81 ( & V_278 -> V_122 , & V_7 -> V_121 . V_122 ) ;
V_281:
F_168 ( & V_7 -> V_121 . V_14 ) ;
}
static void F_169 ( struct V_101 * V_39 ,
struct V_28 * V_29 )
{
struct V_8 * V_9 = V_39 -> V_277 ;
struct V_51 * V_282 = NULL ;
struct V_283 * V_122 = & F_10 ( V_9 ) -> V_23 ;
struct V_51 * V_284 = V_122 -> V_285 ;
unsigned long V_31 ;
F_160 ( V_9 ) ;
if ( ! F_59 ( V_122 ) ) {
F_80 ( & V_122 -> V_14 , V_31 ) ;
while ( V_284 != (struct V_51 * ) V_122 ) {
if ( ! memcmp ( & V_29 -> V_226 , F_122 ( V_284 ) , V_227 ) ) {
V_282 = V_284 ;
break;
}
V_284 = V_284 -> V_285 ;
}
if ( V_282 )
F_170 ( V_282 , V_122 ) ;
F_82 ( & V_122 -> V_14 , V_31 ) ;
if ( V_282 ) {
F_39 ( V_282 ) ;
F_20 ( V_9 ) ;
}
}
if ( V_9 -> V_15 == V_17 ) {
if ( F_59 ( & F_10 ( V_9 ) -> V_23 ) ) {
V_9 -> V_15 = V_22 ;
V_9 -> V_27 ( V_9 ) ;
}
}
F_162 ( V_9 ) ;
}
static void F_171 ( struct V_101 * V_39 , T_2 V_272 [ 16 ] )
{
struct V_8 * V_9 = V_39 -> V_277 ;
if ( V_9 -> V_15 == V_22 )
return;
F_160 ( V_9 ) ;
F_11 ( V_9 , 1 ) ;
V_9 -> V_15 = V_16 ;
V_9 -> V_27 ( V_9 ) ;
F_162 ( V_9 ) ;
}
static void F_172 ( struct V_101 * V_39 , T_2 V_272 [ 16 ] )
{
struct V_8 * V_9 = V_39 -> V_277 ;
F_160 ( V_9 ) ;
if ( V_9 -> V_15 != V_22 ) {
V_9 -> V_212 |= V_213 ;
V_9 -> V_27 ( V_9 ) ;
}
F_162 ( V_9 ) ;
}
static void F_173 ( struct V_51 * V_52 )
{
struct V_53 * V_286 =
(struct V_53 * ) V_52 -> V_195 ;
char V_287 [ 8 ] ;
char V_288 [ 8 ] ;
F_31 ( V_286 -> V_67 , sizeof( V_286 -> V_67 ) ) ;
F_31 ( V_286 -> V_69 , sizeof( V_286 -> V_69 ) ) ;
F_31 ( V_286 -> V_71 , sizeof( V_286 -> V_71 ) ) ;
F_31 ( V_286 -> V_73 , sizeof( V_286 -> V_73 ) ) ;
memcpy ( V_287 , V_286 -> V_71 , 8 ) ;
memcpy ( V_288 , V_286 -> V_73 , 8 ) ;
memcpy ( V_286 -> V_71 , V_286 -> V_67 , 8 ) ;
memcpy ( V_286 -> V_73 , V_286 -> V_69 , 8 ) ;
memcpy ( V_286 -> V_67 , V_287 , 8 ) ;
memcpy ( V_286 -> V_69 , V_288 , 8 ) ;
F_28 ( V_52 , V_58 ) ;
memset ( V_52 -> V_195 , 0 , V_58 ) ;
}
static int F_174 ( struct V_8 * V_9 , struct V_51 * V_52 )
{
struct V_8 * V_184 ;
struct V_6 * V_7 , * V_274 ;
struct V_53 * V_286 ;
int V_12 ;
V_7 = F_10 ( V_9 ) ;
V_286 = (struct V_53 * ) V_52 -> V_195 ;
if ( ! V_7 ) {
F_173 ( V_52 ) ;
V_286 -> V_31 = V_62 | V_107 ;
V_12 = F_36 ( V_52 ) ;
goto V_214;
}
V_184 = F_64 ( NULL , V_9 -> V_82 , V_86 ) ;
F_160 ( V_9 ) ;
if ( ( V_9 -> V_15 != V_21 ) ||
F_161 ( V_9 ) ||
! V_184 ) {
if ( V_184 )
F_175 ( V_184 ) ;
F_173 ( V_52 ) ;
V_286 -> V_31 = V_62 | V_107 ;
V_12 = F_36 ( V_52 ) ;
F_162 ( V_9 ) ;
goto V_214;
}
V_274 = F_10 ( V_184 ) ;
F_63 ( V_184 , V_9 ) ;
V_274 -> V_37 = V_106 ;
V_274 -> V_64 = V_7 -> V_64 ;
if ( ! V_286 -> V_63 )
V_274 -> V_42 = V_167 ;
else
V_274 -> V_42 = V_286 -> V_63 ;
memcpy ( V_274 -> V_70 , V_286 -> V_73 , 8 ) ;
memcpy ( V_274 -> V_68 , V_286 -> V_71 , 8 ) ;
memcpy ( V_274 -> V_74 , V_7 -> V_74 , 8 ) ;
memcpy ( V_274 -> V_72 , V_7 -> V_72 , 8 ) ;
V_184 -> V_112 = V_9 -> V_112 ;
V_274 -> V_76 = V_7 -> V_76 ;
F_91 ( V_274 -> V_76 ) ;
F_173 ( V_52 ) ;
V_286 -> V_31 = V_62 | V_289 ;
V_286 -> V_63 = V_274 -> V_64 ;
V_12 = F_36 ( V_52 ) ;
if ( ! V_12 ) {
F_78 ( V_9 , V_184 ) ;
V_184 -> V_15 = V_18 ;
V_9 -> V_276 ( V_9 , 1 ) ;
} else
F_50 ( V_184 ) ;
F_162 ( V_9 ) ;
V_214:
return V_290 ;
}
static int F_176 ( struct V_8 * V_9 , struct V_51 * V_52 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_53 * V_286 =
(struct V_53 * ) V_52 -> V_195 ;
if ( ! V_7 )
goto V_214;
if ( V_9 -> V_15 != V_20 )
goto V_214;
F_160 ( V_9 ) ;
V_7 -> V_42 = V_286 -> V_63 ;
V_9 -> V_15 = V_18 ;
V_9 -> V_27 ( V_9 ) ;
F_162 ( V_9 ) ;
V_214:
F_39 ( V_52 ) ;
return V_290 ;
}
static int F_177 ( struct V_8 * V_9 , struct V_51 * V_52 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
if ( ! V_7 )
goto V_214;
if ( V_9 -> V_15 != V_20 )
goto V_214;
F_160 ( V_9 ) ;
V_9 -> V_15 = V_16 ;
V_9 -> V_27 ( V_9 ) ;
F_162 ( V_9 ) ;
V_214:
F_39 ( V_52 ) ;
return V_290 ;
}
static int F_178 ( struct V_8 * V_9 , struct V_51 * V_52 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
if ( ! V_7 )
goto V_214;
F_160 ( V_9 ) ;
if ( V_9 -> V_15 == V_18 ) {
V_9 -> V_15 = V_16 ;
V_9 -> V_27 ( V_9 ) ;
}
F_162 ( V_9 ) ;
V_214:
F_39 ( V_52 ) ;
return V_290 ;
}
static int F_179 ( struct V_8 * V_9 , struct V_51 * V_52 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_53 * V_286 =
(struct V_53 * ) V_52 -> V_195 ;
if ( ! V_7 )
return V_290 ;
if ( V_9 -> V_15 != V_18 )
return V_290 ;
F_40 ( V_286 -> V_63 , & V_7 -> V_41 ) ;
F_20 ( V_9 ) ;
return V_290 ;
}
static int F_180 ( struct V_8 * V_9 , struct V_51 * V_52 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
if ( ! V_7 ) {
F_39 ( V_52 ) ;
return V_290 ;
}
if ( V_9 -> V_15 != V_18 ) {
F_39 ( V_52 ) ;
return V_290 ;
}
if ( V_9 -> V_212 & V_243 ) {
F_39 ( V_52 ) ;
return V_290 ;
}
if ( V_52 -> V_80 < sizeof( struct V_53 ) ) {
F_39 ( V_52 ) ;
return V_290 ;
}
F_142 ( V_52 , sizeof( struct V_53 ) ) ;
F_128 ( V_52 ) ;
F_30 ( V_52 ) ;
F_165 ( & V_7 -> V_121 . V_14 ) ;
if ( F_59 ( & V_7 -> V_24 ) ) {
if ( F_131 ( V_9 , V_52 ) ) {
F_35 ( & V_7 -> V_24 , V_52 ) ;
}
} else
F_35 ( & F_10 ( V_9 ) -> V_24 , V_52 ) ;
F_168 ( & V_7 -> V_121 . V_14 ) ;
return V_290 ;
}
static int F_181 ( struct V_51 * V_52 , struct V_152 * V_4 ,
struct V_291 * V_292 , struct V_152 * V_293 )
{
struct V_10 * V_11 ;
struct V_8 * V_9 ;
struct V_6 * V_7 ;
struct V_53 * V_286 ;
char V_294 [ 8 ] ;
int V_12 = 0 ;
F_142 ( V_52 , V_58 ) ;
V_286 = (struct V_53 * ) V_52 -> V_195 ;
F_159 ( V_286 -> V_69 , sizeof( V_286 -> V_69 ) ) ;
F_159 ( V_286 -> V_67 , sizeof( V_286 -> V_67 ) ) ;
F_159 ( V_286 -> V_73 , sizeof( V_286 -> V_73 ) ) ;
F_159 ( V_286 -> V_71 , sizeof( V_286 -> V_71 ) ) ;
memset ( V_294 , 0 , sizeof( V_294 ) ) ;
V_7 = NULL ;
V_9 = NULL ;
F_8 ( & V_13 . V_14 ) ;
F_9 (sk, node, &iucv_sk_list.head) {
if ( V_286 -> V_31 == V_62 ) {
if ( ( ! memcmp ( & F_10 ( V_9 ) -> V_74 ,
V_286 -> V_69 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_72 ,
V_286 -> V_67 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_70 , V_294 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_68 ,
V_294 , 8 ) ) ) {
V_7 = F_10 ( V_9 ) ;
break;
}
} else {
if ( ( ! memcmp ( & F_10 ( V_9 ) -> V_74 ,
V_286 -> V_69 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_72 ,
V_286 -> V_67 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_70 ,
V_286 -> V_73 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_68 ,
V_286 -> V_71 , 8 ) ) ) {
V_7 = F_10 ( V_9 ) ;
break;
}
}
}
F_13 ( & V_13 . V_14 ) ;
if ( ! V_7 )
V_9 = NULL ;
switch ( V_286 -> V_31 ) {
case V_62 :
V_12 = F_174 ( V_9 , V_52 ) ;
break;
case ( V_62 | V_289 ) :
V_12 = F_176 ( V_9 , V_52 ) ;
break;
case ( V_62 | V_107 ) :
V_12 = F_177 ( V_9 , V_52 ) ;
break;
case ( V_107 ) :
V_12 = F_178 ( V_9 , V_52 ) ;
break;
case ( V_65 ) :
V_12 = F_179 ( V_9 , V_52 ) ;
if ( V_52 -> V_80 == sizeof( struct V_53 ) ) {
F_39 ( V_52 ) ;
break;
}
case ( V_259 ) :
case 0 :
memcpy ( F_127 ( V_52 ) , & V_286 -> V_75 . V_216 ,
V_233 ) ;
V_12 = F_180 ( V_9 , V_52 ) ;
break;
default:
;
}
return V_12 ;
}
static void V_125 ( struct V_51 * V_52 ,
enum V_295 V_146 )
{
struct V_8 * V_145 = V_52 -> V_9 ;
struct V_8 * V_9 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_283 * V_122 ;
struct V_51 * V_284 ;
struct V_51 * V_55 ;
unsigned long V_31 ;
struct V_10 * V_11 ;
F_182 ( & V_13 . V_14 , V_31 ) ;
F_9 (sk, node, &iucv_sk_list.head)
if ( V_9 == V_145 ) {
V_7 = F_10 ( V_9 ) ;
break;
}
F_183 ( & V_13 . V_14 , V_31 ) ;
if ( ! V_7 || F_45 ( V_9 , V_97 ) )
return;
V_122 = & V_7 -> V_23 ;
F_80 ( & V_122 -> V_14 , V_31 ) ;
if ( F_59 ( V_122 ) )
goto V_281;
V_284 = V_122 -> V_285 ;
V_55 = V_284 -> V_285 ;
while ( V_284 != (struct V_51 * ) V_122 ) {
if ( F_184 ( V_284 ) == F_184 ( V_52 ) ) {
switch ( V_146 ) {
case V_296 :
F_170 ( V_284 , V_122 ) ;
F_39 ( V_284 ) ;
F_20 ( V_9 ) ;
break;
case V_297 :
F_123 ( & V_7 -> V_43 ) ;
break;
case V_298 :
F_170 ( V_284 , V_122 ) ;
F_124 ( & V_7 -> V_43 ) ;
if ( F_19 ( & V_7 -> V_43 ) <= 0 )
F_20 ( V_9 ) ;
F_39 ( V_284 ) ;
break;
case V_299 :
case V_300 :
case V_301 :
case V_302 :
case V_303 :
F_170 ( V_284 , V_122 ) ;
F_39 ( V_284 ) ;
if ( V_9 -> V_15 == V_18 ) {
V_9 -> V_15 = V_16 ;
V_9 -> V_27 ( V_9 ) ;
}
break;
}
break;
}
V_284 = V_55 ;
V_55 = V_55 -> V_285 ;
}
V_281:
F_82 ( & V_122 -> V_14 , V_31 ) ;
if ( V_9 -> V_15 == V_17 ) {
if ( F_59 ( & F_10 ( V_9 ) -> V_23 ) ) {
V_9 -> V_15 = V_22 ;
V_9 -> V_27 ( V_9 ) ;
}
}
}
static int F_185 ( struct V_304 * V_282 ,
unsigned long V_305 , void * V_306 )
{
struct V_152 * V_307 = (struct V_152 * ) V_306 ;
struct V_10 * V_11 ;
struct V_8 * V_9 ;
struct V_6 * V_7 ;
switch ( V_305 ) {
case V_308 :
case V_309 :
F_9 (sk, node, &iucv_sk_list.head) {
V_7 = F_10 ( V_9 ) ;
if ( ( V_7 -> V_76 == V_307 ) &&
( V_9 -> V_15 == V_18 ) ) {
if ( V_305 == V_309 )
F_55 ( V_9 , V_107 ) ;
V_9 -> V_15 = V_16 ;
V_9 -> V_27 ( V_9 ) ;
}
}
break;
case V_310 :
case V_311 :
default:
break;
}
return V_312 ;
}
static int F_186 ( void )
{
int V_12 ;
V_12 = V_102 -> V_313 ( & V_173 , 0 ) ;
if ( V_12 )
goto V_214;
V_314 . V_315 = V_102 -> V_315 ;
V_12 = F_187 ( & V_314 ) ;
if ( V_12 )
goto V_316;
V_317 = F_167 ( sizeof( struct V_3 ) , V_140 ) ;
if ( ! V_317 ) {
V_12 = - V_87 ;
goto V_318;
}
F_188 ( V_317 , L_9 ) ;
V_317 -> V_315 = V_102 -> V_315 ;
V_317 -> V_96 = V_102 -> V_319 ;
V_317 -> V_228 = ( void ( * ) ( struct V_3 * ) ) F_135 ;
V_317 -> V_320 = & V_314 ;
V_12 = F_189 ( V_317 ) ;
if ( V_12 )
goto V_318;
return 0 ;
V_318:
F_190 ( & V_314 ) ;
V_316:
V_102 -> V_321 ( & V_173 , 0 ) ;
V_214:
return V_12 ;
}
static int T_6 F_191 ( void )
{
int V_12 ;
if ( V_322 ) {
F_192 ( L_10 , V_163 , sizeof( V_163 ) , & V_12 ) ;
if ( F_93 ( V_12 ) ) {
F_41 ( V_12 ) ;
V_12 = - V_134 ;
goto V_214;
}
V_102 = F_193 ( F_194 ( V_323 ) , L_11 ) ;
if ( ! V_102 ) {
F_5 ( V_5 L_12 ) ;
memset ( & V_163 , 0 , sizeof( V_163 ) ) ;
}
} else {
memset ( & V_163 , 0 , sizeof( V_163 ) ) ;
V_102 = NULL ;
}
V_12 = F_195 ( & V_118 , 0 ) ;
if ( V_12 )
goto V_214;
V_12 = F_196 ( & V_324 ) ;
if ( V_12 )
goto V_325;
if ( V_102 ) {
V_12 = F_186 () ;
if ( V_12 )
goto V_326;
} else
F_197 ( & V_327 ) ;
F_198 ( & V_328 ) ;
return 0 ;
V_326:
F_199 ( V_117 ) ;
V_325:
F_200 ( & V_118 ) ;
V_214:
if ( V_102 )
F_201 ( V_323 ) ;
return V_12 ;
}
static void T_7 F_202 ( void )
{
if ( V_102 ) {
F_203 ( V_317 ) ;
F_190 ( & V_314 ) ;
V_102 -> V_321 ( & V_173 , 0 ) ;
F_201 ( V_323 ) ;
} else
F_204 ( & V_327 ) ;
F_205 ( & V_328 ) ;
F_199 ( V_117 ) ;
F_200 ( & V_118 ) ;
}
