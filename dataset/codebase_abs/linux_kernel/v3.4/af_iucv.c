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
F_34 ( V_52 ) -> V_86 |= V_87 ;
V_55 = F_35 ( V_52 , V_88 ) ;
if ( ! V_55 )
return - V_89 ;
F_36 ( & V_7 -> V_23 , V_55 ) ;
V_12 = F_37 ( V_52 ) ;
if ( F_38 ( V_12 ) ) {
F_39 ( V_55 , & V_7 -> V_23 ) ;
F_40 ( V_55 ) ;
} else {
F_41 ( V_56 , & V_7 -> V_66 ) ;
F_42 ( F_19 ( & V_7 -> V_66 ) < 0 ) ;
}
return F_38 ( V_12 ) ;
}
static struct V_8 * F_43 ( char * V_90 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
F_9 (sk, node, &iucv_sk_list.head)
if ( ! memcmp ( & F_10 ( V_9 ) -> V_74 , V_90 , 8 ) )
return V_9 ;
return NULL ;
}
static void F_44 ( struct V_8 * V_9 )
{
F_12 ( & V_9 -> V_91 ) ;
F_12 ( & V_9 -> V_92 ) ;
F_45 ( V_9 ) ;
if ( ! F_46 ( V_9 , V_93 ) ) {
F_47 ( L_5 , V_9 ) ;
return;
}
F_42 ( F_19 ( & V_9 -> V_94 ) ) ;
F_42 ( F_19 ( & V_9 -> V_95 ) ) ;
F_42 ( V_9 -> V_96 ) ;
F_42 ( V_9 -> V_97 ) ;
}
static void F_48 ( struct V_8 * V_98 )
{
struct V_8 * V_9 ;
while ( ( V_9 = F_49 ( V_98 , NULL ) ) ) {
F_50 ( V_9 ) ;
F_51 ( V_9 ) ;
}
V_98 -> V_15 = V_22 ;
}
static void F_51 ( struct V_8 * V_9 )
{
if ( ! F_46 ( V_9 , V_99 ) || V_9 -> V_100 )
return;
F_52 ( & V_13 , V_9 ) ;
F_53 ( V_9 , V_93 ) ;
F_54 ( V_9 ) ;
}
static void F_11 ( struct V_8 * V_9 , int V_101 )
{
unsigned char V_102 [ 16 ] ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_103 * V_39 = V_7 -> V_39 ;
if ( V_7 -> V_39 ) {
V_7 -> V_39 = NULL ;
if ( V_101 ) {
F_2 ( V_102 , V_7 -> V_74 ) ;
F_1 ( V_102 , V_7 -> V_70 ) ;
F_31 ( V_102 , sizeof( V_102 ) ) ;
V_104 -> V_105 ( V_39 , V_102 ) ;
} else
V_104 -> V_105 ( V_39 , NULL ) ;
F_55 ( V_39 ) ;
}
}
static int F_56 ( struct V_8 * V_9 , T_2 V_31 )
{
int V_12 = 0 ;
int V_106 ;
struct V_51 * V_52 ;
V_106 = sizeof( struct V_53 ) + V_58 ;
V_52 = F_57 ( V_9 , V_106 , 1 , & V_12 ) ;
if ( V_52 ) {
F_58 ( V_52 , V_106 ) ;
V_12 = F_27 ( NULL , V_9 , V_52 , V_31 ) ;
}
return V_12 ;
}
static void F_50 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
unsigned long V_107 ;
int V_12 = 0 ;
F_59 ( V_9 ) ;
switch ( V_9 -> V_15 ) {
case V_21 :
F_48 ( V_9 ) ;
break;
case V_18 :
if ( V_7 -> V_37 == V_108 ) {
V_12 = F_56 ( V_9 , V_109 ) ;
V_9 -> V_15 = V_16 ;
V_9 -> V_27 ( V_9 ) ;
}
case V_16 :
V_9 -> V_15 = V_17 ;
V_9 -> V_27 ( V_9 ) ;
if ( ! V_12 && ! F_60 ( & V_7 -> V_23 ) ) {
if ( F_46 ( V_9 , V_110 ) && V_9 -> V_111 )
V_107 = V_9 -> V_111 ;
else
V_107 = V_112 ;
F_61 ( V_9 ,
F_16 ( V_9 , V_22 , 0 ) ,
V_107 ) ;
}
case V_17 :
V_9 -> V_15 = V_22 ;
V_9 -> V_27 ( V_9 ) ;
V_9 -> V_25 = V_113 ;
V_9 -> V_27 ( V_9 ) ;
F_12 ( & V_7 -> V_23 ) ;
F_12 ( & V_7 -> V_24 ) ;
default:
F_11 ( V_9 , 1 ) ;
}
if ( V_7 -> V_76 ) {
F_62 ( V_7 -> V_76 ) ;
V_7 -> V_76 = NULL ;
V_9 -> V_114 = 0 ;
}
F_53 ( V_9 , V_99 ) ;
F_63 ( V_9 ) ;
}
static void F_64 ( struct V_8 * V_9 , struct V_8 * V_98 )
{
if ( V_98 )
V_9 -> V_82 = V_98 -> V_82 ;
}
static struct V_8 * F_65 ( struct V_115 * V_8 , int V_116 , T_3 V_117 )
{
struct V_8 * V_9 ;
struct V_6 * V_7 ;
V_9 = F_66 ( & V_118 , V_119 , V_117 , & V_120 ) ;
if ( ! V_9 )
return NULL ;
V_7 = F_10 ( V_9 ) ;
F_67 ( V_8 , V_9 ) ;
F_68 ( & V_7 -> V_121 ) ;
F_69 ( & V_7 -> V_122 ) ;
F_70 ( & V_7 -> V_23 ) ;
F_68 ( & V_7 -> V_123 . V_124 ) ;
F_69 ( & V_7 -> V_123 . V_14 ) ;
F_70 ( & V_7 -> V_24 ) ;
V_7 -> V_125 = 0 ;
F_71 ( & V_7 -> V_43 , 0 ) ;
V_7 -> V_31 = 0 ;
V_7 -> V_64 = 0 ;
F_71 ( & V_7 -> V_41 , 0 ) ;
F_71 ( & V_7 -> V_66 , 0 ) ;
V_7 -> V_39 = NULL ;
V_7 -> V_126 = V_127 ;
memset ( & V_7 -> V_72 , 0 , 32 ) ;
if ( V_104 )
V_7 -> V_37 = V_38 ;
else
V_7 -> V_37 = V_108 ;
V_9 -> V_128 = F_44 ;
V_9 -> V_129 = V_130 ;
V_9 -> V_131 = V_132 ;
F_72 ( V_9 , V_99 ) ;
V_9 -> V_133 = V_116 ;
V_9 -> V_15 = V_19 ;
F_73 ( & V_13 , V_9 ) ;
return V_9 ;
}
static int F_74 ( struct V_134 * V_134 , struct V_115 * V_8 , int V_85 ,
int V_135 )
{
struct V_8 * V_9 ;
if ( V_85 && V_85 != V_119 )
return - V_136 ;
V_8 -> V_35 = V_137 ;
switch ( V_8 -> type ) {
case V_138 :
V_8 -> V_139 = & V_140 ;
break;
case V_83 :
V_8 -> V_139 = & V_140 ;
break;
default:
return - V_141 ;
}
V_9 = F_65 ( V_8 , V_85 , V_142 ) ;
if ( ! V_9 )
return - V_89 ;
F_64 ( V_9 , NULL ) ;
return 0 ;
}
void F_73 ( struct V_143 * V_144 , struct V_8 * V_9 )
{
F_75 ( & V_144 -> V_14 ) ;
F_76 ( V_9 , & V_144 -> V_57 ) ;
F_77 ( & V_144 -> V_14 ) ;
}
void F_52 ( struct V_143 * V_144 , struct V_8 * V_9 )
{
F_75 ( & V_144 -> V_14 ) ;
F_78 ( V_9 ) ;
F_77 ( & V_144 -> V_14 ) ;
}
void F_79 ( struct V_8 * V_98 , struct V_8 * V_9 )
{
unsigned long V_31 ;
struct V_6 * V_145 = F_10 ( V_98 ) ;
F_80 ( V_9 ) ;
F_81 ( & V_145 -> V_122 , V_31 ) ;
F_82 ( & F_10 ( V_9 ) -> V_121 , & V_145 -> V_121 ) ;
F_83 ( & V_145 -> V_122 , V_31 ) ;
F_10 ( V_9 ) -> V_98 = V_98 ;
F_84 ( V_98 ) ;
}
void F_85 ( struct V_8 * V_9 )
{
unsigned long V_31 ;
struct V_6 * V_145 = F_10 ( F_10 ( V_9 ) -> V_98 ) ;
F_81 ( & V_145 -> V_122 , V_31 ) ;
F_86 ( & F_10 ( V_9 ) -> V_121 ) ;
F_83 ( & V_145 -> V_122 , V_31 ) ;
F_87 ( F_10 ( V_9 ) -> V_98 ) ;
F_10 ( V_9 ) -> V_98 = NULL ;
F_54 ( V_9 ) ;
}
struct V_8 * F_49 ( struct V_8 * V_98 , struct V_115 * V_146 )
{
struct V_6 * V_147 , * V_148 ;
struct V_8 * V_9 ;
F_88 (isk, n, &iucv_sk(parent)->accept_q, accept_q) {
V_9 = (struct V_8 * ) V_147 ;
F_59 ( V_9 ) ;
if ( V_9 -> V_15 == V_22 ) {
F_85 ( V_9 ) ;
F_63 ( V_9 ) ;
continue;
}
if ( V_9 -> V_15 == V_18 ||
V_9 -> V_15 == V_16 ||
! V_146 ) {
F_85 ( V_9 ) ;
if ( V_146 )
F_89 ( V_9 , V_146 ) ;
F_63 ( V_9 ) ;
return V_9 ;
}
F_63 ( V_9 ) ;
}
return NULL ;
}
static int F_90 ( struct V_115 * V_8 , struct V_149 * V_150 ,
int V_151 )
{
struct V_152 * V_153 = (struct V_152 * ) V_150 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 ;
int V_12 = 0 ;
struct V_154 * V_4 ;
char V_155 [ 9 ] ;
if ( ! V_150 || V_150 -> V_156 != V_157 )
return - V_158 ;
F_59 ( V_9 ) ;
if ( V_9 -> V_15 != V_19 ) {
V_12 = - V_159 ;
goto V_160;
}
F_75 ( & V_13 . V_14 ) ;
V_7 = F_10 ( V_9 ) ;
if ( F_43 ( V_153 -> V_161 ) ) {
V_12 = - V_162 ;
goto V_163;
}
if ( V_7 -> V_39 )
goto V_163;
if ( V_104 )
if ( ! memcmp ( V_153 -> V_164 , V_165 , 8 ) )
goto V_166;
memcpy ( V_155 , V_153 -> V_164 , sizeof( V_155 ) ) ;
F_31 ( V_155 , 8 ) ;
F_21 () ;
F_91 (&init_net, dev) {
if ( ! memcmp ( V_4 -> V_167 , V_155 , 8 ) ) {
memcpy ( V_7 -> V_74 , V_153 -> V_161 , 8 ) ;
memcpy ( V_7 -> V_72 , V_153 -> V_164 , 8 ) ;
V_9 -> V_114 = V_4 -> V_168 ;
V_7 -> V_76 = V_4 ;
F_92 ( V_4 ) ;
V_9 -> V_15 = V_20 ;
V_7 -> V_37 = V_108 ;
if ( ! V_7 -> V_64 )
V_7 -> V_64 = V_169 ;
F_26 () ;
goto V_163;
}
}
F_26 () ;
V_166:
if ( V_104 ) {
memcpy ( V_7 -> V_74 , V_153 -> V_161 , 8 ) ;
memcpy ( V_7 -> V_72 , V_165 , 8 ) ;
V_9 -> V_15 = V_20 ;
V_7 -> V_37 = V_38 ;
if ( ! V_7 -> V_64 )
V_7 -> V_64 = V_170 ;
goto V_163;
}
V_12 = - V_77 ;
V_163:
F_77 ( & V_13 . V_14 ) ;
V_160:
F_63 ( V_9 ) ;
return V_12 ;
}
static int F_93 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
char V_171 [ 12 ] ;
int V_12 = 0 ;
if ( F_94 ( ! V_104 ) )
return - V_172 ;
memcpy ( V_7 -> V_72 , V_165 , 8 ) ;
F_75 ( & V_13 . V_14 ) ;
sprintf ( V_171 , L_6 , F_95 ( & V_13 . V_173 ) ) ;
while ( F_43 ( V_171 ) ) {
sprintf ( V_171 , L_6 ,
F_95 ( & V_13 . V_173 ) ) ;
}
F_77 ( & V_13 . V_14 ) ;
memcpy ( & V_7 -> V_74 , V_171 , 8 ) ;
if ( ! V_7 -> V_64 )
V_7 -> V_64 = V_170 ;
return V_12 ;
}
static int F_96 ( struct V_115 * V_8 , struct V_149 * V_150 )
{
struct V_152 * V_153 = (struct V_152 * ) V_150 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
unsigned char V_102 [ 16 ] ;
int V_12 ;
F_1 ( V_102 , V_153 -> V_161 ) ;
F_2 ( V_102 , V_7 -> V_74 ) ;
F_31 ( V_102 , sizeof( V_102 ) ) ;
V_7 -> V_39 = F_97 ( V_7 -> V_64 ,
V_32 , V_142 ) ;
if ( ! V_7 -> V_39 ) {
V_12 = - V_89 ;
goto V_160;
}
V_12 = V_104 -> V_174 ( V_7 -> V_39 , & V_175 ,
V_153 -> V_164 , NULL , V_102 ,
V_9 ) ;
if ( V_12 ) {
F_55 ( V_7 -> V_39 ) ;
V_7 -> V_39 = NULL ;
switch ( V_12 ) {
case 0x0b :
V_12 = - V_176 ;
break;
case 0x0d :
case 0x0e :
V_12 = - V_177 ;
break;
case 0x0f :
V_12 = - V_178 ;
break;
default:
V_12 = - V_179 ;
break;
}
}
V_160:
return V_12 ;
}
static int F_98 ( struct V_115 * V_8 , struct V_149 * V_150 ,
int V_180 , int V_31 )
{
struct V_152 * V_153 = (struct V_152 * ) V_150 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
int V_12 ;
if ( V_150 -> V_156 != V_157 || V_180 < sizeof( struct V_152 ) )
return - V_158 ;
if ( V_9 -> V_15 != V_19 && V_9 -> V_15 != V_20 )
return - V_159 ;
if ( V_9 -> V_15 == V_19 &&
V_7 -> V_37 == V_108 )
return - V_159 ;
if ( V_9 -> V_82 != V_138 && V_9 -> V_82 != V_83 )
return - V_158 ;
if ( V_9 -> V_15 == V_19 ) {
V_12 = F_93 ( V_9 ) ;
if ( F_94 ( V_12 ) )
return V_12 ;
}
F_59 ( V_9 ) ;
memcpy ( V_7 -> V_68 , V_153 -> V_164 , 8 ) ;
memcpy ( V_7 -> V_70 , V_153 -> V_161 , 8 ) ;
if ( V_7 -> V_37 == V_108 )
V_12 = F_56 ( V_8 -> V_9 , V_62 ) ;
else
V_12 = F_96 ( V_8 , V_150 ) ;
if ( V_12 )
goto V_160;
if ( V_9 -> V_15 != V_18 )
V_12 = F_61 ( V_9 , F_16 ( V_9 , V_18 ,
V_16 ) ,
F_99 ( V_9 , V_31 & V_181 ) ) ;
if ( V_9 -> V_15 == V_16 || V_9 -> V_15 == V_22 )
V_12 = - V_179 ;
if ( V_12 && V_7 -> V_37 == V_38 )
F_11 ( V_9 , 0 ) ;
V_160:
F_63 ( V_9 ) ;
return V_12 ;
}
static int F_100 ( struct V_115 * V_8 , int V_182 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
int V_12 ;
F_59 ( V_9 ) ;
V_12 = - V_158 ;
if ( V_9 -> V_15 != V_20 )
goto V_160;
if ( V_8 -> type != V_138 && V_8 -> type != V_83 )
goto V_160;
V_9 -> V_183 = V_182 ;
V_9 -> V_184 = 0 ;
V_9 -> V_15 = V_21 ;
V_12 = 0 ;
V_160:
F_63 ( V_9 ) ;
return V_12 ;
}
static int F_101 ( struct V_115 * V_8 , struct V_115 * V_146 ,
int V_31 )
{
F_102 ( V_47 , V_185 ) ;
struct V_8 * V_9 = V_8 -> V_9 , * V_186 ;
long V_107 ;
int V_12 = 0 ;
F_103 ( V_9 , V_187 ) ;
if ( V_9 -> V_15 != V_21 ) {
V_12 = - V_159 ;
goto V_160;
}
V_107 = F_104 ( V_9 , V_31 & V_181 ) ;
F_105 ( F_106 ( V_9 ) , & V_47 ) ;
while ( ! ( V_186 = F_49 ( V_9 , V_146 ) ) ) {
F_107 ( V_188 ) ;
if ( ! V_107 ) {
V_12 = - V_177 ;
break;
}
F_63 ( V_9 ) ;
V_107 = F_108 ( V_107 ) ;
F_103 ( V_9 , V_187 ) ;
if ( V_9 -> V_15 != V_21 ) {
V_12 = - V_159 ;
break;
}
if ( F_109 ( V_185 ) ) {
V_12 = F_110 ( V_107 ) ;
break;
}
}
F_107 ( V_189 ) ;
F_111 ( F_106 ( V_9 ) , & V_47 ) ;
if ( V_12 )
goto V_160;
V_146 -> V_35 = V_190 ;
V_160:
F_63 ( V_9 ) ;
return V_12 ;
}
static int F_112 ( struct V_115 * V_8 , struct V_149 * V_150 ,
int * V_80 , int V_191 )
{
struct V_152 * V_192 = (struct V_152 * ) V_150 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
V_150 -> V_156 = V_157 ;
* V_80 = sizeof( struct V_152 ) ;
if ( V_191 ) {
memcpy ( V_192 -> V_164 , V_7 -> V_68 , 8 ) ;
memcpy ( V_192 -> V_161 , V_7 -> V_70 , 8 ) ;
} else {
memcpy ( V_192 -> V_164 , V_7 -> V_72 , 8 ) ;
memcpy ( V_192 -> V_161 , V_7 -> V_74 , 8 ) ;
}
memset ( & V_192 -> V_193 , 0 , sizeof( V_192 -> V_193 ) ) ;
memset ( & V_192 -> V_194 , 0 , sizeof( V_192 -> V_194 ) ) ;
memset ( & V_192 -> V_195 , 0 , sizeof( V_192 -> V_195 ) ) ;
return 0 ;
}
static int F_113 ( struct V_103 * V_39 , struct V_28 * V_29 ,
struct V_51 * V_52 )
{
T_2 V_196 [ 8 ] ;
memcpy ( V_196 , ( void * ) V_52 -> V_197 , V_52 -> V_80 ) ;
V_196 [ 7 ] = 0xff - ( T_2 ) V_52 -> V_80 ;
return V_104 -> V_198 ( V_39 , V_29 , V_32 , 0 ,
( void * ) V_196 , 8 ) ;
}
static int F_114 ( struct V_199 * V_200 , struct V_115 * V_8 ,
struct V_201 * V_29 , T_1 V_80 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_51 * V_52 ;
struct V_28 V_202 ;
struct V_203 * V_204 ;
int V_205 ;
long V_107 ;
char V_206 [ 9 ] ;
char V_207 [ 9 ] ;
int V_12 ;
int V_208 = V_29 -> V_209 & V_210 ;
V_12 = F_115 ( V_9 ) ;
if ( V_12 )
return V_12 ;
if ( V_29 -> V_209 & V_211 )
return - V_212 ;
if ( V_9 -> V_82 == V_83 && ! ( V_29 -> V_209 & V_213 ) )
return - V_212 ;
F_59 ( V_9 ) ;
if ( V_9 -> V_214 & V_215 ) {
V_12 = - V_26 ;
goto V_216;
}
if ( V_9 -> V_15 != V_18 ) {
V_12 = - V_217 ;
goto V_216;
}
V_205 = 0 ;
V_202 . V_218 = 0 ;
for ( V_204 = F_116 ( V_29 ) ; V_204 ;
V_204 = F_117 ( V_29 , V_204 ) ) {
if ( ! F_118 ( V_29 , V_204 ) ) {
V_12 = - V_158 ;
goto V_216;
}
if ( V_204 -> V_219 != V_220 )
continue;
if ( V_204 -> V_221 & V_205 ) {
V_12 = - V_158 ;
goto V_216;
}
V_205 |= V_204 -> V_221 ;
switch ( V_204 -> V_221 ) {
case V_222 :
if ( V_204 -> V_223 != F_119 ( V_224 ) ) {
V_12 = - V_158 ;
goto V_216;
}
memcpy ( & V_202 . V_218 ,
( void * ) F_120 ( V_204 ) , V_224 ) ;
break;
default:
V_12 = - V_158 ;
goto V_216;
break;
}
}
if ( V_7 -> V_37 == V_108 )
V_52 = F_57 ( V_9 ,
V_80 + sizeof( struct V_53 ) + V_58 ,
V_208 , & V_12 ) ;
else
V_52 = F_57 ( V_9 , V_80 , V_208 , & V_12 ) ;
if ( ! V_52 ) {
V_12 = - V_89 ;
goto V_216;
}
if ( V_7 -> V_37 == V_108 )
F_58 ( V_52 , sizeof( struct V_53 ) + V_58 ) ;
if ( F_121 ( F_122 ( V_52 , V_80 ) , V_29 -> V_225 , V_80 ) ) {
V_12 = - V_226 ;
goto V_227;
}
V_107 = F_99 ( V_9 , V_208 ) ;
V_12 = F_61 ( V_9 , F_17 ( V_9 ) , V_107 ) ;
if ( V_12 )
goto V_227;
if ( V_9 -> V_15 != V_18 ) {
V_12 = - V_113 ;
goto V_227;
}
V_202 . V_228 = V_7 -> V_125 ++ ;
memcpy ( F_123 ( V_52 ) , & V_202 . V_228 , V_229 ) ;
if ( V_7 -> V_37 == V_108 ) {
F_124 ( & V_7 -> V_41 ) ;
V_12 = F_27 ( & V_202 , V_9 , V_52 , 0 ) ;
if ( V_12 ) {
F_125 ( & V_7 -> V_41 ) ;
goto V_227;
}
goto V_230;
}
F_36 ( & V_7 -> V_23 , V_52 ) ;
if ( ( ( V_7 -> V_39 -> V_31 & V_32 ) & V_7 -> V_31 )
&& V_52 -> V_80 <= 7 ) {
V_12 = F_113 ( V_7 -> V_39 , & V_202 , V_52 ) ;
if ( V_12 == 0 ) {
F_39 ( V_52 , & V_7 -> V_23 ) ;
F_40 ( V_52 ) ;
}
if ( V_12 == 0x15 ) {
V_104 -> V_105 ( V_7 -> V_39 , NULL ) ;
F_39 ( V_52 , & V_7 -> V_23 ) ;
V_12 = - V_26 ;
goto V_227;
}
} else
V_12 = V_104 -> V_198 ( V_7 -> V_39 , & V_202 , 0 , 0 ,
( void * ) V_52 -> V_197 , V_52 -> V_80 ) ;
if ( V_12 ) {
if ( V_12 == 3 ) {
V_206 [ 8 ] = 0 ;
memcpy ( V_206 , V_7 -> V_68 , 8 ) ;
V_207 [ 8 ] = 0 ;
memcpy ( V_207 , V_7 -> V_70 , 8 ) ;
F_47 ( L_7
L_8 ,
V_207 , V_206 ) ;
V_12 = - V_177 ;
} else
V_12 = - V_26 ;
F_39 ( V_52 , & V_7 -> V_23 ) ;
goto V_227;
}
V_230:
F_63 ( V_9 ) ;
return V_80 ;
V_227:
F_40 ( V_52 ) ;
V_216:
F_63 ( V_9 ) ;
return V_12 ;
}
static int F_126 ( struct V_8 * V_9 , struct V_51 * V_52 , int V_80 )
{
int V_231 , V_232 , V_233 = 0 ;
struct V_51 * V_55 ;
V_231 = V_80 ;
while ( V_231 ) {
if ( V_231 >= V_9 -> V_234 / 4 )
V_232 = V_9 -> V_234 / 4 ;
else
V_232 = V_231 ;
V_55 = F_127 ( V_232 , V_88 | V_132 ) ;
if ( ! V_55 )
return - V_89 ;
memcpy ( F_128 ( V_55 ) , F_128 ( V_52 ) , V_235 ) ;
memcpy ( V_55 -> V_197 , V_52 -> V_197 + V_233 , V_232 ) ;
V_233 += V_232 ;
V_231 -= V_232 ;
F_129 ( V_55 ) ;
F_30 ( V_55 ) ;
V_55 -> V_80 = V_232 ;
F_36 ( & F_10 ( V_9 ) -> V_24 , V_55 ) ;
}
return 0 ;
}
static void F_130 ( struct V_8 * V_9 , struct V_51 * V_52 ,
struct V_103 * V_39 ,
struct V_28 * V_29 )
{
int V_236 ;
unsigned int V_80 ;
V_80 = F_15 ( V_29 ) ;
memcpy ( F_128 ( V_52 ) , & V_29 -> V_218 , V_235 ) ;
if ( ( V_29 -> V_31 & V_32 ) && V_80 > 7 ) {
if ( memcmp ( V_29 -> V_33 , V_237 , 8 ) == 0 ) {
V_52 -> V_197 = NULL ;
V_52 -> V_80 = 0 ;
}
} else {
V_236 = V_104 -> V_238 ( V_39 , V_29 ,
V_29 -> V_31 & V_32 ,
V_52 -> V_197 , V_80 , NULL ) ;
if ( V_236 ) {
F_40 ( V_52 ) ;
return;
}
if ( V_9 -> V_82 == V_138 &&
V_52 -> V_239 >= V_9 -> V_234 / 4 ) {
V_236 = F_126 ( V_9 , V_52 , V_80 ) ;
F_40 ( V_52 ) ;
V_52 = NULL ;
if ( V_236 ) {
V_104 -> V_105 ( V_39 , NULL ) ;
return;
}
V_52 = F_131 ( & F_10 ( V_9 ) -> V_24 ) ;
} else {
F_129 ( V_52 ) ;
F_30 ( V_52 ) ;
V_52 -> V_80 = V_80 ;
}
}
if ( F_132 ( V_9 , V_52 ) )
F_133 ( & F_10 ( V_9 ) -> V_24 , V_52 ) ;
}
static void F_134 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_51 * V_52 ;
struct V_240 * V_241 , * V_148 ;
F_88 (p, n, &iucv->message_q.list, list) {
V_52 = F_127 ( F_15 ( & V_241 -> V_29 ) , V_88 | V_132 ) ;
if ( ! V_52 )
break;
F_130 ( V_9 , V_52 , V_241 -> V_39 , & V_241 -> V_29 ) ;
F_135 ( & V_241 -> V_124 ) ;
F_136 ( V_241 ) ;
if ( ! F_60 ( & V_7 -> V_24 ) )
break;
}
}
static int F_137 ( struct V_199 * V_200 , struct V_115 * V_8 ,
struct V_201 * V_29 , T_1 V_80 , int V_31 )
{
int V_208 = V_31 & V_210 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
unsigned int V_233 , V_242 ;
struct V_51 * V_52 , * V_243 , * V_244 ;
int V_12 = 0 ;
if ( ( V_9 -> V_15 == V_16 ) &&
F_60 ( & V_7 -> V_24 ) &&
F_60 ( & V_9 -> V_91 ) &&
F_138 ( & V_7 -> V_123 . V_124 ) )
return 0 ;
if ( V_31 & ( V_211 ) )
return - V_212 ;
V_52 = F_139 ( V_9 , V_31 , V_208 , & V_12 ) ;
if ( ! V_52 ) {
if ( V_9 -> V_214 & V_245 )
return 0 ;
return V_12 ;
}
V_242 = V_52 -> V_80 ;
V_233 = F_140 (unsigned int, rlen, len) ;
if ( ! V_242 )
V_9 -> V_214 = V_9 -> V_214 | V_245 ;
V_244 = V_52 ;
if ( F_141 ( V_244 , 0 , V_29 -> V_225 , V_233 ) ) {
if ( ! ( V_31 & V_246 ) )
F_133 ( & V_9 -> V_91 , V_52 ) ;
return - V_226 ;
}
if ( V_9 -> V_82 == V_83 ) {
if ( V_233 < V_242 )
V_29 -> V_209 |= V_247 ;
V_29 -> V_209 |= V_213 ;
}
V_12 = F_142 ( V_29 , V_220 , V_222 ,
V_235 , F_128 ( V_52 ) ) ;
if ( V_12 ) {
if ( ! ( V_31 & V_246 ) )
F_133 ( & V_9 -> V_91 , V_52 ) ;
return V_12 ;
}
if ( ! ( V_31 & V_246 ) ) {
if ( V_9 -> V_82 == V_138 ) {
F_143 ( V_52 , V_233 ) ;
if ( V_52 -> V_80 ) {
F_133 ( & V_9 -> V_91 , V_52 ) ;
goto V_160;
}
}
F_40 ( V_52 ) ;
if ( V_7 -> V_37 == V_108 ) {
F_124 ( & V_7 -> V_66 ) ;
if ( F_19 ( & V_7 -> V_66 ) > V_7 -> V_64 ) {
F_42 ( 1 ) ;
F_50 ( V_9 ) ;
return - V_226 ;
}
}
F_144 ( & V_7 -> V_123 . V_14 ) ;
V_243 = F_131 ( & V_7 -> V_24 ) ;
while ( V_243 ) {
if ( F_132 ( V_9 , V_243 ) ) {
F_133 ( & V_7 -> V_24 ,
V_243 ) ;
break;
} else {
V_243 = F_131 ( & V_7 -> V_24 ) ;
}
}
if ( F_60 ( & V_7 -> V_24 ) ) {
if ( ! F_138 ( & V_7 -> V_123 . V_124 ) )
F_134 ( V_9 ) ;
if ( F_19 ( & V_7 -> V_66 ) >=
V_7 -> V_64 / 2 ) {
V_12 = F_56 ( V_9 , V_65 ) ;
if ( V_12 ) {
V_9 -> V_15 = V_16 ;
V_9 -> V_27 ( V_9 ) ;
}
}
}
F_145 ( & V_7 -> V_123 . V_14 ) ;
}
V_160:
if ( V_9 -> V_82 == V_83 && ( V_31 & V_247 ) )
V_233 = V_242 ;
return V_233 ;
}
static inline unsigned int F_146 ( struct V_8 * V_98 )
{
struct V_6 * V_147 , * V_148 ;
struct V_8 * V_9 ;
F_88 (isk, n, &iucv_sk(parent)->accept_q, accept_q) {
V_9 = (struct V_8 * ) V_147 ;
if ( V_9 -> V_15 == V_18 )
return V_248 | V_249 ;
}
return 0 ;
}
unsigned int F_147 ( struct V_250 * V_250 , struct V_115 * V_8 ,
T_4 * V_47 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
unsigned int V_251 = 0 ;
F_148 ( V_250 , F_106 ( V_9 ) , V_47 ) ;
if ( V_9 -> V_15 == V_21 )
return F_146 ( V_9 ) ;
if ( V_9 -> V_25 || ! F_60 ( & V_9 -> V_92 ) )
V_251 |= V_252 ;
if ( V_9 -> V_214 & V_245 )
V_251 |= V_253 ;
if ( V_9 -> V_214 == V_254 )
V_251 |= V_255 ;
if ( ! F_60 ( & V_9 -> V_91 ) ||
( V_9 -> V_214 & V_245 ) )
V_251 |= V_248 | V_249 ;
if ( V_9 -> V_15 == V_22 )
V_251 |= V_255 ;
if ( V_9 -> V_15 == V_16 )
V_251 |= V_248 ;
if ( F_149 ( V_9 ) && F_17 ( V_9 ) )
V_251 |= V_256 | V_257 | V_258 ;
else
F_150 ( V_259 , & V_9 -> V_100 -> V_31 ) ;
return V_251 ;
}
static int F_151 ( struct V_115 * V_8 , int V_260 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_28 V_202 ;
int V_12 = 0 ;
V_260 ++ ;
if ( ( V_260 & ~ V_254 ) || ! V_260 )
return - V_158 ;
F_59 ( V_9 ) ;
switch ( V_9 -> V_15 ) {
case V_21 :
case V_16 :
case V_17 :
case V_22 :
V_12 = - V_217 ;
goto V_227;
default:
break;
}
if ( V_260 == V_215 || V_260 == V_254 ) {
if ( V_7 -> V_37 == V_38 ) {
V_202 . V_218 = 0 ;
V_202 . V_228 = 0 ;
V_12 = V_104 -> V_198 ( V_7 -> V_39 , & V_202 ,
V_32 , 0 , ( void * ) V_237 , 8 ) ;
if ( V_12 ) {
switch ( V_12 ) {
case 1 :
V_12 = - V_217 ;
break;
case 2 :
V_12 = - V_113 ;
break;
default:
V_12 = - V_217 ;
break;
}
}
} else
F_56 ( V_9 , V_261 ) ;
}
V_9 -> V_214 |= V_260 ;
if ( V_260 == V_245 || V_260 == V_254 ) {
if ( V_7 -> V_37 == V_38 ) {
V_12 = V_104 -> V_262 ( V_7 -> V_39 , NULL ) ;
if ( V_12 )
V_12 = - V_217 ;
}
F_12 ( & V_9 -> V_91 ) ;
}
V_9 -> V_27 ( V_9 ) ;
V_227:
F_63 ( V_9 ) ;
return V_12 ;
}
static int F_152 ( struct V_115 * V_8 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
int V_12 = 0 ;
if ( ! V_9 )
return 0 ;
F_50 ( V_9 ) ;
F_153 ( V_9 ) ;
F_51 ( V_9 ) ;
return V_12 ;
}
static int F_154 ( struct V_115 * V_8 , int V_263 , int V_264 ,
char T_5 * V_265 , unsigned int V_266 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
int V_267 ;
int V_236 ;
if ( V_263 != V_220 )
return - V_268 ;
if ( V_266 < sizeof( int ) )
return - V_158 ;
if ( F_155 ( V_267 , ( int T_5 * ) V_265 ) )
return - V_226 ;
V_236 = 0 ;
F_59 ( V_9 ) ;
switch ( V_264 ) {
case V_269 :
if ( V_267 )
V_7 -> V_31 |= V_32 ;
else
V_7 -> V_31 &= ~ V_32 ;
break;
case V_270 :
switch ( V_9 -> V_15 ) {
case V_19 :
case V_20 :
if ( V_267 < 1 || V_267 > ( V_271 ) ( ~ 0 ) )
V_236 = - V_158 ;
else
V_7 -> V_64 = V_267 ;
break;
default:
V_236 = - V_158 ;
break;
}
break;
default:
V_236 = - V_268 ;
break;
}
F_63 ( V_9 ) ;
return V_236 ;
}
static int F_156 ( struct V_115 * V_8 , int V_263 , int V_264 ,
char T_5 * V_265 , int T_5 * V_266 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
unsigned int V_267 ;
int V_80 ;
if ( V_263 != V_220 )
return - V_268 ;
if ( F_155 ( V_80 , V_266 ) )
return - V_226 ;
if ( V_80 < 0 )
return - V_158 ;
V_80 = F_140 (unsigned int, len, sizeof(int)) ;
switch ( V_264 ) {
case V_269 :
V_267 = ( V_7 -> V_31 & V_32 ) ? 1 : 0 ;
break;
case V_270 :
F_59 ( V_9 ) ;
V_267 = ( V_7 -> V_39 != NULL ) ? V_7 -> V_39 -> V_40
: V_7 -> V_64 ;
F_63 ( V_9 ) ;
break;
case V_272 :
if ( V_9 -> V_15 == V_19 )
return - V_159 ;
V_267 = ( V_7 -> V_76 ) ? V_7 -> V_76 -> V_81 -
sizeof( struct V_53 ) - V_58 :
0x7fffffff ;
break;
default:
return - V_268 ;
}
if ( F_157 ( V_80 , V_266 ) )
return - V_226 ;
if ( F_158 ( V_265 , & V_267 , V_80 ) )
return - V_226 ;
return 0 ;
}
static int F_159 ( struct V_103 * V_39 ,
T_2 V_273 [ 8 ] , T_2 V_274 [ 16 ] )
{
unsigned char V_102 [ 16 ] ;
unsigned char V_275 [ 16 ] ;
unsigned char V_74 [ 8 ] ;
struct V_10 * V_11 ;
struct V_8 * V_9 , * V_186 ;
struct V_6 * V_7 , * V_276 ;
int V_12 ;
memcpy ( V_74 , V_274 , 8 ) ;
F_160 ( V_74 , 8 ) ;
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
return - V_158 ;
F_161 ( V_9 ) ;
F_2 ( V_102 , V_7 -> V_74 ) ;
F_1 ( V_102 , V_7 -> V_70 ) ;
F_31 ( V_102 , sizeof( V_102 ) ) ;
if ( V_9 -> V_15 != V_21 ) {
V_12 = V_104 -> V_105 ( V_39 , V_102 ) ;
F_55 ( V_39 ) ;
goto V_227;
}
if ( F_162 ( V_9 ) ) {
V_12 = V_104 -> V_105 ( V_39 , V_102 ) ;
F_55 ( V_39 ) ;
goto V_227;
}
V_186 = F_65 ( NULL , V_9 -> V_82 , V_88 ) ;
if ( ! V_186 ) {
V_12 = V_104 -> V_105 ( V_39 , V_102 ) ;
F_55 ( V_39 ) ;
goto V_227;
}
V_276 = F_10 ( V_186 ) ;
F_64 ( V_186 , V_9 ) ;
memcpy ( V_276 -> V_70 , V_274 + 8 , 8 ) ;
F_160 ( V_276 -> V_70 , 8 ) ;
memcpy ( V_276 -> V_68 , V_273 , 8 ) ;
memcpy ( V_276 -> V_74 , V_7 -> V_74 , 8 ) ;
memcpy ( V_276 -> V_72 , V_7 -> V_72 , 8 ) ;
V_276 -> V_39 = V_39 ;
F_1 ( V_275 , V_274 + 8 ) ;
memcpy ( V_275 + 8 , V_276 -> V_74 , 8 ) ;
F_31 ( V_275 + 8 , 8 ) ;
V_276 -> V_64 = V_7 -> V_64 ;
V_39 -> V_40 = V_7 -> V_64 ;
V_12 = V_104 -> V_277 ( V_39 , & V_175 , V_275 , V_186 ) ;
if ( V_12 ) {
F_11 ( V_186 , 1 ) ;
F_51 ( V_186 ) ;
goto V_227;
}
F_79 ( V_9 , V_186 ) ;
V_186 -> V_15 = V_18 ;
V_9 -> V_278 ( V_9 , 1 ) ;
V_12 = 0 ;
V_227:
F_163 ( V_9 ) ;
return 0 ;
}
static void F_164 ( struct V_103 * V_39 , T_2 V_274 [ 16 ] )
{
struct V_8 * V_9 = V_39 -> V_279 ;
V_9 -> V_15 = V_18 ;
V_9 -> V_27 ( V_9 ) ;
}
static void F_165 ( struct V_103 * V_39 , struct V_28 * V_29 )
{
struct V_8 * V_9 = V_39 -> V_279 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_51 * V_52 ;
struct V_240 * V_280 ;
int V_80 ;
if ( V_9 -> V_214 & V_245 ) {
V_104 -> V_281 ( V_39 , V_29 ) ;
return;
}
F_166 ( & V_7 -> V_123 . V_14 ) ;
if ( ! F_138 ( & V_7 -> V_123 . V_124 ) ||
! F_60 ( & V_7 -> V_24 ) )
goto V_282;
V_80 = F_19 ( & V_9 -> V_94 ) ;
V_80 += F_167 ( F_15 ( V_29 ) ) ;
if ( V_80 > V_9 -> V_234 )
goto V_282;
V_52 = F_127 ( F_15 ( V_29 ) , V_88 | V_132 ) ;
if ( ! V_52 )
goto V_282;
F_130 ( V_9 , V_52 , V_39 , V_29 ) ;
goto V_283;
V_282:
V_280 = F_168 ( sizeof( struct V_240 ) , V_88 | V_132 ) ;
if ( ! V_280 )
goto V_283;
V_280 -> V_39 = V_39 ;
V_280 -> V_29 = * V_29 ;
F_82 ( & V_280 -> V_124 , & V_7 -> V_123 . V_124 ) ;
V_283:
F_169 ( & V_7 -> V_123 . V_14 ) ;
}
static void F_170 ( struct V_103 * V_39 ,
struct V_28 * V_29 )
{
struct V_8 * V_9 = V_39 -> V_279 ;
struct V_51 * V_284 = NULL ;
struct V_285 * V_124 = & F_10 ( V_9 ) -> V_23 ;
struct V_51 * V_286 = V_124 -> V_287 ;
unsigned long V_31 ;
F_161 ( V_9 ) ;
if ( ! F_60 ( V_124 ) ) {
F_81 ( & V_124 -> V_14 , V_31 ) ;
while ( V_286 != (struct V_51 * ) V_124 ) {
if ( ! memcmp ( & V_29 -> V_228 , F_123 ( V_286 ) , V_229 ) ) {
V_284 = V_286 ;
break;
}
V_286 = V_286 -> V_287 ;
}
if ( V_284 )
F_171 ( V_284 , V_124 ) ;
F_83 ( & V_124 -> V_14 , V_31 ) ;
if ( V_284 ) {
F_40 ( V_284 ) ;
F_20 ( V_9 ) ;
}
}
if ( V_9 -> V_15 == V_17 ) {
if ( F_60 ( & F_10 ( V_9 ) -> V_23 ) ) {
V_9 -> V_15 = V_22 ;
V_9 -> V_27 ( V_9 ) ;
}
}
F_163 ( V_9 ) ;
}
static void F_172 ( struct V_103 * V_39 , T_2 V_274 [ 16 ] )
{
struct V_8 * V_9 = V_39 -> V_279 ;
if ( V_9 -> V_15 == V_22 )
return;
F_161 ( V_9 ) ;
F_11 ( V_9 , 1 ) ;
V_9 -> V_15 = V_16 ;
V_9 -> V_27 ( V_9 ) ;
F_163 ( V_9 ) ;
}
static void F_173 ( struct V_103 * V_39 , T_2 V_274 [ 16 ] )
{
struct V_8 * V_9 = V_39 -> V_279 ;
F_161 ( V_9 ) ;
if ( V_9 -> V_15 != V_22 ) {
V_9 -> V_214 |= V_215 ;
V_9 -> V_27 ( V_9 ) ;
}
F_163 ( V_9 ) ;
}
static void F_174 ( struct V_51 * V_52 )
{
struct V_53 * V_288 =
(struct V_53 * ) V_52 -> V_197 ;
char V_289 [ 8 ] ;
char V_290 [ 8 ] ;
F_31 ( V_288 -> V_67 , sizeof( V_288 -> V_67 ) ) ;
F_31 ( V_288 -> V_69 , sizeof( V_288 -> V_69 ) ) ;
F_31 ( V_288 -> V_71 , sizeof( V_288 -> V_71 ) ) ;
F_31 ( V_288 -> V_73 , sizeof( V_288 -> V_73 ) ) ;
memcpy ( V_289 , V_288 -> V_71 , 8 ) ;
memcpy ( V_290 , V_288 -> V_73 , 8 ) ;
memcpy ( V_288 -> V_71 , V_288 -> V_67 , 8 ) ;
memcpy ( V_288 -> V_73 , V_288 -> V_69 , 8 ) ;
memcpy ( V_288 -> V_67 , V_289 , 8 ) ;
memcpy ( V_288 -> V_69 , V_290 , 8 ) ;
F_28 ( V_52 , V_58 ) ;
memset ( V_52 -> V_197 , 0 , V_58 ) ;
}
static int F_175 ( struct V_8 * V_9 , struct V_51 * V_52 )
{
struct V_8 * V_186 ;
struct V_6 * V_7 , * V_276 ;
struct V_53 * V_288 ;
int V_12 ;
V_7 = F_10 ( V_9 ) ;
V_288 = (struct V_53 * ) V_52 -> V_197 ;
if ( ! V_7 ) {
F_174 ( V_52 ) ;
V_288 -> V_31 = V_62 | V_109 ;
V_12 = F_37 ( V_52 ) ;
goto V_216;
}
V_186 = F_65 ( NULL , V_9 -> V_82 , V_88 ) ;
F_161 ( V_9 ) ;
if ( ( V_9 -> V_15 != V_21 ) ||
F_162 ( V_9 ) ||
! V_186 ) {
if ( V_186 )
F_176 ( V_186 ) ;
F_174 ( V_52 ) ;
V_288 -> V_31 = V_62 | V_109 ;
V_12 = F_37 ( V_52 ) ;
F_163 ( V_9 ) ;
goto V_216;
}
V_276 = F_10 ( V_186 ) ;
F_64 ( V_186 , V_9 ) ;
V_276 -> V_37 = V_108 ;
V_276 -> V_64 = V_7 -> V_64 ;
if ( ! V_288 -> V_63 )
V_276 -> V_42 = V_169 ;
else
V_276 -> V_42 = V_288 -> V_63 ;
memcpy ( V_276 -> V_70 , V_288 -> V_73 , 8 ) ;
memcpy ( V_276 -> V_68 , V_288 -> V_71 , 8 ) ;
memcpy ( V_276 -> V_74 , V_7 -> V_74 , 8 ) ;
memcpy ( V_276 -> V_72 , V_7 -> V_72 , 8 ) ;
V_186 -> V_114 = V_9 -> V_114 ;
V_276 -> V_76 = V_7 -> V_76 ;
F_92 ( V_276 -> V_76 ) ;
F_174 ( V_52 ) ;
V_288 -> V_31 = V_62 | V_291 ;
V_288 -> V_63 = V_276 -> V_64 ;
V_12 = F_37 ( V_52 ) ;
if ( ! V_12 ) {
F_79 ( V_9 , V_186 ) ;
V_186 -> V_15 = V_18 ;
V_9 -> V_278 ( V_9 , 1 ) ;
} else
F_51 ( V_186 ) ;
F_163 ( V_9 ) ;
V_216:
return V_292 ;
}
static int F_177 ( struct V_8 * V_9 , struct V_51 * V_52 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_53 * V_288 =
(struct V_53 * ) V_52 -> V_197 ;
if ( ! V_7 )
goto V_216;
if ( V_9 -> V_15 != V_20 )
goto V_216;
F_161 ( V_9 ) ;
V_7 -> V_42 = V_288 -> V_63 ;
V_9 -> V_15 = V_18 ;
V_9 -> V_27 ( V_9 ) ;
F_163 ( V_9 ) ;
V_216:
F_40 ( V_52 ) ;
return V_292 ;
}
static int F_178 ( struct V_8 * V_9 , struct V_51 * V_52 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
if ( ! V_7 )
goto V_216;
if ( V_9 -> V_15 != V_20 )
goto V_216;
F_161 ( V_9 ) ;
V_9 -> V_15 = V_16 ;
V_9 -> V_27 ( V_9 ) ;
F_163 ( V_9 ) ;
V_216:
F_40 ( V_52 ) ;
return V_292 ;
}
static int F_179 ( struct V_8 * V_9 , struct V_51 * V_52 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
if ( ! V_7 )
goto V_216;
F_161 ( V_9 ) ;
if ( V_9 -> V_15 == V_18 ) {
V_9 -> V_15 = V_16 ;
V_9 -> V_27 ( V_9 ) ;
}
F_163 ( V_9 ) ;
V_216:
F_40 ( V_52 ) ;
return V_292 ;
}
static int F_180 ( struct V_8 * V_9 , struct V_51 * V_52 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_53 * V_288 =
(struct V_53 * ) V_52 -> V_197 ;
if ( ! V_7 )
return V_292 ;
if ( V_9 -> V_15 != V_18 )
return V_292 ;
F_41 ( V_288 -> V_63 , & V_7 -> V_41 ) ;
F_20 ( V_9 ) ;
return V_292 ;
}
static int F_181 ( struct V_8 * V_9 , struct V_51 * V_52 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
if ( ! V_7 ) {
F_40 ( V_52 ) ;
return V_292 ;
}
if ( V_9 -> V_15 != V_18 ) {
F_40 ( V_52 ) ;
return V_292 ;
}
if ( V_9 -> V_214 & V_245 ) {
F_40 ( V_52 ) ;
return V_292 ;
}
if ( V_52 -> V_80 < sizeof( struct V_53 ) ) {
F_40 ( V_52 ) ;
return V_292 ;
}
F_143 ( V_52 , sizeof( struct V_53 ) ) ;
F_129 ( V_52 ) ;
F_30 ( V_52 ) ;
F_166 ( & V_7 -> V_123 . V_14 ) ;
if ( F_60 ( & V_7 -> V_24 ) ) {
if ( F_132 ( V_9 , V_52 ) ) {
F_36 ( & V_7 -> V_24 , V_52 ) ;
}
} else
F_36 ( & F_10 ( V_9 ) -> V_24 , V_52 ) ;
F_169 ( & V_7 -> V_123 . V_14 ) ;
return V_292 ;
}
static int F_182 ( struct V_51 * V_52 , struct V_154 * V_4 ,
struct V_293 * V_294 , struct V_154 * V_295 )
{
struct V_10 * V_11 ;
struct V_8 * V_9 ;
struct V_6 * V_7 ;
struct V_53 * V_288 ;
char V_296 [ 8 ] ;
int V_12 = 0 ;
F_143 ( V_52 , V_58 ) ;
V_288 = (struct V_53 * ) V_52 -> V_197 ;
F_160 ( V_288 -> V_69 , sizeof( V_288 -> V_69 ) ) ;
F_160 ( V_288 -> V_67 , sizeof( V_288 -> V_67 ) ) ;
F_160 ( V_288 -> V_73 , sizeof( V_288 -> V_73 ) ) ;
F_160 ( V_288 -> V_71 , sizeof( V_288 -> V_71 ) ) ;
memset ( V_296 , 0 , sizeof( V_296 ) ) ;
V_7 = NULL ;
V_9 = NULL ;
F_8 ( & V_13 . V_14 ) ;
F_9 (sk, node, &iucv_sk_list.head) {
if ( V_288 -> V_31 == V_62 ) {
if ( ( ! memcmp ( & F_10 ( V_9 ) -> V_74 ,
V_288 -> V_69 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_72 ,
V_288 -> V_67 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_70 , V_296 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_68 ,
V_296 , 8 ) ) ) {
V_7 = F_10 ( V_9 ) ;
break;
}
} else {
if ( ( ! memcmp ( & F_10 ( V_9 ) -> V_74 ,
V_288 -> V_69 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_72 ,
V_288 -> V_67 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_70 ,
V_288 -> V_73 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_68 ,
V_288 -> V_71 , 8 ) ) ) {
V_7 = F_10 ( V_9 ) ;
break;
}
}
}
F_13 ( & V_13 . V_14 ) ;
if ( ! V_7 )
V_9 = NULL ;
switch ( V_288 -> V_31 ) {
case V_62 :
V_12 = F_175 ( V_9 , V_52 ) ;
break;
case ( V_62 | V_291 ) :
V_12 = F_177 ( V_9 , V_52 ) ;
break;
case ( V_62 | V_109 ) :
V_12 = F_178 ( V_9 , V_52 ) ;
break;
case ( V_109 ) :
V_12 = F_179 ( V_9 , V_52 ) ;
break;
case ( V_65 ) :
V_12 = F_180 ( V_9 , V_52 ) ;
if ( V_52 -> V_80 == sizeof( struct V_53 ) ) {
F_40 ( V_52 ) ;
break;
}
case ( V_261 ) :
case 0 :
memcpy ( F_128 ( V_52 ) , & V_288 -> V_75 . V_218 ,
V_235 ) ;
V_12 = F_181 ( V_9 , V_52 ) ;
break;
default:
;
}
return V_12 ;
}
static void V_127 ( struct V_51 * V_52 ,
enum V_297 V_148 )
{
struct V_8 * V_147 = V_52 -> V_9 ;
struct V_8 * V_9 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_285 * V_124 ;
struct V_51 * V_286 ;
struct V_51 * V_55 ;
unsigned long V_31 ;
struct V_10 * V_11 ;
F_183 ( & V_13 . V_14 , V_31 ) ;
F_9 (sk, node, &iucv_sk_list.head)
if ( V_9 == V_147 ) {
V_7 = F_10 ( V_9 ) ;
break;
}
F_184 ( & V_13 . V_14 , V_31 ) ;
if ( ! V_7 || F_46 ( V_9 , V_99 ) )
return;
V_124 = & V_7 -> V_23 ;
F_81 ( & V_124 -> V_14 , V_31 ) ;
if ( F_60 ( V_124 ) )
goto V_283;
V_286 = V_124 -> V_287 ;
V_55 = V_286 -> V_287 ;
while ( V_286 != (struct V_51 * ) V_124 ) {
if ( F_34 ( V_286 ) == F_34 ( V_52 ) ) {
switch ( V_148 ) {
case V_298 :
F_171 ( V_286 , V_124 ) ;
F_40 ( V_286 ) ;
F_20 ( V_9 ) ;
break;
case V_299 :
F_124 ( & V_7 -> V_43 ) ;
break;
case V_300 :
F_171 ( V_286 , V_124 ) ;
F_125 ( & V_7 -> V_43 ) ;
if ( F_19 ( & V_7 -> V_43 ) <= 0 )
F_20 ( V_9 ) ;
F_40 ( V_286 ) ;
break;
case V_301 :
case V_302 :
case V_303 :
case V_304 :
case V_305 :
F_171 ( V_286 , V_124 ) ;
F_40 ( V_286 ) ;
if ( V_9 -> V_15 == V_18 ) {
V_9 -> V_15 = V_16 ;
V_9 -> V_27 ( V_9 ) ;
}
break;
}
break;
}
V_286 = V_55 ;
V_55 = V_55 -> V_287 ;
}
V_283:
F_83 ( & V_124 -> V_14 , V_31 ) ;
if ( V_9 -> V_15 == V_17 ) {
if ( F_60 ( & F_10 ( V_9 ) -> V_23 ) ) {
V_9 -> V_15 = V_22 ;
V_9 -> V_27 ( V_9 ) ;
}
}
}
static int F_185 ( struct V_306 * V_284 ,
unsigned long V_307 , void * V_308 )
{
struct V_154 * V_309 = (struct V_154 * ) V_308 ;
struct V_10 * V_11 ;
struct V_8 * V_9 ;
struct V_6 * V_7 ;
switch ( V_307 ) {
case V_310 :
case V_311 :
F_9 (sk, node, &iucv_sk_list.head) {
V_7 = F_10 ( V_9 ) ;
if ( ( V_7 -> V_76 == V_309 ) &&
( V_9 -> V_15 == V_18 ) ) {
if ( V_307 == V_311 )
F_56 ( V_9 , V_109 ) ;
V_9 -> V_15 = V_16 ;
V_9 -> V_27 ( V_9 ) ;
}
}
break;
case V_312 :
case V_313 :
default:
break;
}
return V_314 ;
}
static int F_186 ( void )
{
int V_12 ;
V_12 = V_104 -> V_315 ( & V_175 , 0 ) ;
if ( V_12 )
goto V_216;
V_316 . V_317 = V_104 -> V_317 ;
V_12 = F_187 ( & V_316 ) ;
if ( V_12 )
goto V_318;
V_319 = F_168 ( sizeof( struct V_3 ) , V_142 ) ;
if ( ! V_319 ) {
V_12 = - V_89 ;
goto V_320;
}
F_188 ( V_319 , L_9 ) ;
V_319 -> V_317 = V_104 -> V_317 ;
V_319 -> V_98 = V_104 -> V_321 ;
V_319 -> V_230 = ( void ( * ) ( struct V_3 * ) ) F_136 ;
V_319 -> V_322 = & V_316 ;
V_12 = F_189 ( V_319 ) ;
if ( V_12 )
goto V_320;
return 0 ;
V_320:
F_190 ( & V_316 ) ;
V_318:
V_104 -> V_323 ( & V_175 , 0 ) ;
V_216:
return V_12 ;
}
static int T_6 F_191 ( void )
{
int V_12 ;
if ( V_324 ) {
F_192 ( L_10 , V_165 , sizeof( V_165 ) , & V_12 ) ;
if ( F_94 ( V_12 ) ) {
F_42 ( V_12 ) ;
V_12 = - V_136 ;
goto V_216;
}
V_104 = F_193 ( F_194 ( V_325 ) , L_11 ) ;
if ( ! V_104 ) {
F_5 ( V_5 L_12 ) ;
memset ( & V_165 , 0 , sizeof( V_165 ) ) ;
}
} else {
memset ( & V_165 , 0 , sizeof( V_165 ) ) ;
V_104 = NULL ;
}
V_12 = F_195 ( & V_120 , 0 ) ;
if ( V_12 )
goto V_216;
V_12 = F_196 ( & V_326 ) ;
if ( V_12 )
goto V_327;
if ( V_104 ) {
V_12 = F_186 () ;
if ( V_12 )
goto V_328;
} else
F_197 ( & V_329 ) ;
F_198 ( & V_330 ) ;
return 0 ;
V_328:
F_199 ( V_119 ) ;
V_327:
F_200 ( & V_120 ) ;
V_216:
if ( V_104 )
F_201 ( V_325 ) ;
return V_12 ;
}
static void T_7 F_202 ( void )
{
if ( V_104 ) {
F_203 ( V_319 ) ;
F_190 ( & V_316 ) ;
V_104 -> V_323 ( & V_175 , 0 ) ;
F_201 ( V_325 ) ;
} else
F_204 ( & V_329 ) ;
F_205 ( & V_330 ) ;
F_199 ( V_119 ) ;
F_200 ( & V_120 ) ;
}
