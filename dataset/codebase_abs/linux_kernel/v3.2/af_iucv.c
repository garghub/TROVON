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
F_11 ( & V_7 -> V_15 ) ;
F_11 ( & V_7 -> V_16 ) ;
switch ( V_9 -> V_17 ) {
case V_18 :
case V_19 :
case V_20 :
case V_21 :
if ( V_7 -> V_22 ) {
V_12 = V_23 -> V_24 ( V_7 -> V_22 , NULL ) ;
F_12 ( V_7 -> V_22 ) ;
V_7 -> V_22 = NULL ;
}
break;
case V_25 :
case V_26 :
case V_27 :
case V_28 :
default:
break;
}
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
switch ( V_9 -> V_17 ) {
case V_21 :
V_9 -> V_29 = V_30 ;
V_9 -> V_17 = V_19 ;
V_9 -> V_31 ( V_9 ) ;
break;
case V_19 :
case V_18 :
case V_20 :
case V_27 :
case V_26 :
case V_25 :
default:
break;
}
}
F_13 ( & V_13 . V_14 ) ;
return 0 ;
}
static inline T_1 F_15 ( struct V_32 * V_33 )
{
T_1 V_34 ;
if ( V_33 -> V_35 & V_36 ) {
V_34 = 0xff - V_33 -> V_37 [ 7 ] ;
return ( V_34 < 8 ) ? V_34 : 8 ;
}
return V_33 -> V_38 ;
}
static int F_16 ( struct V_8 * V_9 , int V_39 , int V_40 )
{
return ( V_9 -> V_17 == V_39 || V_9 -> V_17 == V_40 ) ;
}
static inline int F_17 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
if ( V_9 -> V_17 != V_21 )
return 1 ;
if ( V_7 -> V_41 == V_42 )
return ( F_18 ( & V_7 -> V_15 ) < V_7 -> V_22 -> V_43 ) ;
else
return ( ( F_19 ( & V_7 -> V_44 ) < V_7 -> V_45 ) &&
( F_19 ( & V_7 -> V_46 ) <= 0 ) ) ;
}
static void F_20 ( struct V_8 * V_9 )
{
struct V_47 * V_48 ;
F_21 () ;
V_48 = F_22 ( V_9 -> V_49 ) ;
if ( F_23 ( V_48 ) )
F_24 ( & V_48 -> V_50 ) ;
F_25 ( V_9 , V_51 , V_52 ) ;
F_26 () ;
}
static int F_27 ( struct V_32 * V_53 , struct V_8 * V_8 ,
struct V_54 * V_55 , T_2 V_35 )
{
struct V_56 * V_56 = F_28 ( V_8 ) ;
struct V_6 * V_7 = F_10 ( V_8 ) ;
struct V_57 * V_58 ;
struct V_54 * V_59 ;
int V_12 , V_60 = 0 ;
memset ( V_55 -> V_61 , 0 , V_62 ) ;
V_58 = (struct V_57 * ) F_29 ( V_55 ,
sizeof( struct V_57 ) ) ;
F_30 ( V_55 ) ;
F_31 ( V_55 ) ;
F_29 ( V_55 , V_62 ) ;
F_30 ( V_55 ) ;
memset ( V_58 , 0 , sizeof( struct V_57 ) ) ;
V_58 -> V_63 = V_64 ;
V_58 -> V_65 = 1 ;
V_58 -> V_35 = V_35 ;
if ( V_35 == V_66 )
V_58 -> V_67 = V_7 -> V_68 ;
else if ( ( V_35 == V_69 ) || ! V_35 ) {
V_60 = F_19 ( & V_7 -> V_70 ) ;
V_58 -> V_67 = V_60 ;
if ( V_60 )
V_58 -> V_35 = V_58 -> V_35 | V_69 ;
}
memcpy ( V_58 -> V_71 , V_7 -> V_72 , 8 ) ;
memcpy ( V_58 -> V_73 , V_7 -> V_74 , 8 ) ;
memcpy ( V_58 -> V_75 , V_7 -> V_76 , 8 ) ;
memcpy ( V_58 -> V_77 , V_7 -> V_78 , 8 ) ;
F_32 ( V_58 -> V_71 , sizeof( V_58 -> V_71 ) ) ;
F_32 ( V_58 -> V_73 , sizeof( V_58 -> V_73 ) ) ;
F_32 ( V_58 -> V_75 , sizeof( V_58 -> V_75 ) ) ;
F_32 ( V_58 -> V_77 , sizeof( V_58 -> V_77 ) ) ;
if ( V_53 )
memcpy ( & V_58 -> V_79 , V_53 , sizeof( struct V_32 ) ) ;
F_21 () ;
V_55 -> V_4 = F_33 ( V_56 , V_8 -> V_80 ) ;
F_26 () ;
if ( ! V_55 -> V_4 )
return - V_81 ;
if ( ! ( V_55 -> V_4 -> V_35 & V_82 ) )
return - V_83 ;
if ( V_55 -> V_84 > V_55 -> V_4 -> V_85 ) {
if ( V_8 -> V_86 == V_87 )
return - V_88 ;
else
F_34 ( V_55 , V_55 -> V_4 -> V_85 ) ;
}
V_55 -> V_89 = V_64 ;
F_35 ( V_55 ) -> V_90 |= V_91 ;
V_59 = F_36 ( V_55 , V_92 ) ;
if ( ! V_59 )
return - V_93 ;
F_37 ( & V_7 -> V_15 , V_59 ) ;
V_12 = F_38 ( V_55 ) ;
if ( V_12 ) {
F_39 ( V_59 , & V_7 -> V_15 ) ;
F_40 ( V_59 ) ;
} else {
F_41 ( V_60 , & V_7 -> V_70 ) ;
F_42 ( F_19 ( & V_7 -> V_70 ) < 0 ) ;
}
return V_12 ;
}
static void F_43 ( unsigned long V_94 )
{
struct V_8 * V_9 = (struct V_8 * ) V_94 ;
F_44 ( V_9 ) ;
V_9 -> V_29 = V_95 ;
V_9 -> V_31 ( V_9 ) ;
F_45 ( V_9 ) ;
F_46 ( V_9 ) ;
F_47 ( V_9 ) ;
}
static void F_48 ( struct V_8 * V_9 )
{
F_49 ( V_9 , & V_9 -> V_96 ) ;
}
static struct V_8 * F_50 ( char * V_97 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
F_9 (sk, node, &iucv_sk_list.head)
if ( ! memcmp ( & F_10 ( V_9 ) -> V_78 , V_97 , 8 ) )
return V_9 ;
return NULL ;
}
static void F_51 ( struct V_8 * V_9 )
{
F_11 ( & V_9 -> V_98 ) ;
F_11 ( & V_9 -> V_99 ) ;
}
static void F_52 ( struct V_8 * V_100 )
{
struct V_8 * V_9 ;
while ( ( V_9 = F_53 ( V_100 , NULL ) ) ) {
F_54 ( V_9 ) ;
F_46 ( V_9 ) ;
}
V_100 -> V_17 = V_28 ;
}
static void F_46 ( struct V_8 * V_9 )
{
if ( ! F_55 ( V_9 , V_101 ) || V_9 -> V_102 )
return;
F_56 ( & V_13 , V_9 ) ;
F_57 ( V_9 , V_103 ) ;
F_47 ( V_9 ) ;
}
static void F_54 ( struct V_8 * V_9 )
{
unsigned char V_104 [ 16 ] ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
unsigned long V_105 ;
int V_12 , V_106 ;
struct V_54 * V_55 ;
F_48 ( V_9 ) ;
F_58 ( V_9 ) ;
switch ( V_9 -> V_17 ) {
case V_27 :
F_52 ( V_9 ) ;
break;
case V_21 :
if ( V_7 -> V_41 == V_107 ) {
V_106 = sizeof( struct V_57 ) + V_62 ;
V_55 = F_59 ( V_9 , V_106 , 1 , & V_12 ) ;
if ( V_55 ) {
F_60 ( V_55 ,
sizeof( struct V_57 ) +
V_62 ) ;
V_12 = F_27 ( NULL , V_9 , V_55 ,
V_108 ) ;
}
V_9 -> V_17 = V_19 ;
V_9 -> V_31 ( V_9 ) ;
}
case V_19 :
V_9 -> V_17 = V_20 ;
V_9 -> V_31 ( V_9 ) ;
if ( ! F_61 ( & V_7 -> V_15 ) ) {
if ( F_55 ( V_9 , V_109 ) && V_9 -> V_110 )
V_105 = V_9 -> V_110 ;
else
V_105 = V_111 ;
F_62 ( V_9 ,
F_16 ( V_9 , V_28 , 0 ) ,
V_105 ) ;
}
case V_20 :
V_9 -> V_17 = V_28 ;
V_9 -> V_31 ( V_9 ) ;
if ( V_7 -> V_22 ) {
F_2 ( V_104 , V_7 -> V_78 ) ;
F_1 ( V_104 , V_7 -> V_74 ) ;
F_32 ( V_104 , sizeof( V_104 ) ) ;
V_23 -> V_24 ( V_7 -> V_22 , V_104 ) ;
F_12 ( V_7 -> V_22 ) ;
V_7 -> V_22 = NULL ;
}
V_9 -> V_29 = V_112 ;
V_9 -> V_31 ( V_9 ) ;
F_11 ( & V_7 -> V_15 ) ;
F_11 ( & V_7 -> V_16 ) ;
break;
default:
break;
}
F_57 ( V_9 , V_101 ) ;
F_63 ( V_9 ) ;
}
static void F_64 ( struct V_8 * V_9 , struct V_8 * V_100 )
{
if ( V_100 )
V_9 -> V_86 = V_100 -> V_86 ;
}
static struct V_8 * F_65 ( struct V_113 * V_8 , int V_114 , T_3 V_115 )
{
struct V_8 * V_9 ;
struct V_6 * V_7 ;
V_9 = F_66 ( & V_116 , V_117 , V_115 , & V_118 ) ;
if ( ! V_9 )
return NULL ;
V_7 = F_10 ( V_9 ) ;
F_67 ( V_8 , V_9 ) ;
F_68 ( & V_7 -> V_119 ) ;
F_69 ( & V_7 -> V_120 ) ;
F_70 ( & V_7 -> V_15 ) ;
F_68 ( & V_7 -> V_121 . V_122 ) ;
F_69 ( & V_7 -> V_121 . V_14 ) ;
F_70 ( & V_7 -> V_16 ) ;
V_7 -> V_123 = 0 ;
F_71 ( & V_7 -> V_46 , 0 ) ;
V_7 -> V_35 = 0 ;
V_7 -> V_68 = 0 ;
F_71 ( & V_7 -> V_44 , 0 ) ;
F_71 ( & V_7 -> V_70 , 0 ) ;
V_7 -> V_22 = NULL ;
V_7 -> V_124 = V_125 ;
memset ( & V_7 -> V_76 , 0 , 32 ) ;
if ( V_23 )
V_7 -> V_41 = V_42 ;
else
V_7 -> V_41 = V_107 ;
V_9 -> V_126 = F_51 ;
V_9 -> V_127 = V_128 ;
V_9 -> V_129 = V_130 ;
F_72 ( V_9 , V_101 ) ;
V_9 -> V_131 = V_114 ;
V_9 -> V_17 = V_25 ;
F_73 ( & V_9 -> V_96 , F_43 , ( unsigned long ) V_9 ) ;
F_74 ( & V_13 , V_9 ) ;
return V_9 ;
}
static int F_75 ( struct V_56 * V_56 , struct V_113 * V_8 , int V_89 ,
int V_132 )
{
struct V_8 * V_9 ;
if ( V_89 && V_89 != V_117 )
return - V_133 ;
V_8 -> V_39 = V_134 ;
switch ( V_8 -> type ) {
case V_135 :
V_8 -> V_136 = & V_137 ;
break;
case V_87 :
V_8 -> V_136 = & V_137 ;
break;
default:
return - V_138 ;
}
V_9 = F_65 ( V_8 , V_89 , V_139 ) ;
if ( ! V_9 )
return - V_93 ;
F_64 ( V_9 , NULL ) ;
return 0 ;
}
void F_74 ( struct V_140 * V_141 , struct V_8 * V_9 )
{
F_76 ( & V_141 -> V_14 ) ;
F_77 ( V_9 , & V_141 -> V_61 ) ;
F_78 ( & V_141 -> V_14 ) ;
}
void F_56 ( struct V_140 * V_141 , struct V_8 * V_9 )
{
F_76 ( & V_141 -> V_14 ) ;
F_79 ( V_9 ) ;
F_78 ( & V_141 -> V_14 ) ;
}
void F_80 ( struct V_8 * V_100 , struct V_8 * V_9 )
{
unsigned long V_35 ;
struct V_6 * V_142 = F_10 ( V_100 ) ;
F_81 ( V_9 ) ;
F_82 ( & V_142 -> V_120 , V_35 ) ;
F_83 ( & F_10 ( V_9 ) -> V_119 , & V_142 -> V_119 ) ;
F_84 ( & V_142 -> V_120 , V_35 ) ;
F_10 ( V_9 ) -> V_100 = V_100 ;
F_85 ( V_100 ) ;
}
void F_86 ( struct V_8 * V_9 )
{
unsigned long V_35 ;
struct V_6 * V_142 = F_10 ( F_10 ( V_9 ) -> V_100 ) ;
F_82 ( & V_142 -> V_120 , V_35 ) ;
F_87 ( & F_10 ( V_9 ) -> V_119 ) ;
F_84 ( & V_142 -> V_120 , V_35 ) ;
F_88 ( F_10 ( V_9 ) -> V_100 ) ;
F_10 ( V_9 ) -> V_100 = NULL ;
F_47 ( V_9 ) ;
}
struct V_8 * F_53 ( struct V_8 * V_100 , struct V_113 * V_143 )
{
struct V_6 * V_144 , * V_145 ;
struct V_8 * V_9 ;
F_89 (isk, n, &iucv_sk(parent)->accept_q, accept_q) {
V_9 = (struct V_8 * ) V_144 ;
F_58 ( V_9 ) ;
if ( V_9 -> V_17 == V_28 ) {
F_86 ( V_9 ) ;
F_63 ( V_9 ) ;
continue;
}
if ( V_9 -> V_17 == V_21 ||
V_9 -> V_17 == V_18 ||
V_9 -> V_17 == V_19 ||
! V_143 ) {
F_86 ( V_9 ) ;
if ( V_143 )
F_90 ( V_9 , V_143 ) ;
if ( V_9 -> V_17 == V_18 )
V_9 -> V_17 = V_19 ;
F_63 ( V_9 ) ;
return V_9 ;
}
F_63 ( V_9 ) ;
}
return NULL ;
}
static int F_91 ( struct V_113 * V_8 , struct V_146 * V_147 ,
int V_148 )
{
struct V_149 * V_150 = (struct V_149 * ) V_147 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 ;
int V_12 = 0 ;
struct V_151 * V_4 ;
char V_152 [ 9 ] ;
if ( ! V_147 || V_147 -> V_153 != V_154 )
return - V_155 ;
F_58 ( V_9 ) ;
if ( V_9 -> V_17 != V_25 ) {
V_12 = - V_156 ;
goto V_157;
}
F_76 ( & V_13 . V_14 ) ;
V_7 = F_10 ( V_9 ) ;
if ( F_50 ( V_150 -> V_158 ) ) {
V_12 = - V_159 ;
goto V_160;
}
if ( V_7 -> V_22 )
goto V_160;
if ( V_23 )
if ( ! memcmp ( V_150 -> V_161 , V_162 , 8 ) )
goto V_163;
memcpy ( V_152 , V_150 -> V_161 , sizeof( V_152 ) ) ;
F_32 ( V_152 , 8 ) ;
F_21 () ;
F_92 (&init_net, dev) {
if ( ! memcmp ( V_4 -> V_164 , V_152 , 8 ) ) {
memcpy ( V_7 -> V_78 , V_150 -> V_158 , 8 ) ;
memcpy ( V_7 -> V_76 , V_150 -> V_161 , 8 ) ;
V_8 -> V_9 -> V_80 = V_4 -> V_165 ;
V_9 -> V_17 = V_26 ;
V_7 -> V_41 = V_107 ;
if ( ! V_7 -> V_68 )
V_7 -> V_68 = V_166 ;
F_26 () ;
goto V_160;
}
}
F_26 () ;
V_163:
if ( V_23 ) {
memcpy ( V_7 -> V_78 , V_150 -> V_158 , 8 ) ;
memcpy ( V_7 -> V_76 , V_162 , 8 ) ;
V_9 -> V_17 = V_26 ;
V_7 -> V_41 = V_42 ;
if ( ! V_7 -> V_68 )
V_7 -> V_68 = V_167 ;
goto V_160;
}
V_12 = - V_81 ;
V_160:
F_78 ( & V_13 . V_14 ) ;
V_157:
F_63 ( V_9 ) ;
return V_12 ;
}
static int F_93 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
char V_168 [ 80 ] ;
char V_169 [ 12 ] ;
int V_12 = 0 ;
F_94 ( L_5 , V_168 , sizeof( V_168 ) , & V_12 ) ;
if ( F_95 ( V_12 ) )
return - V_170 ;
memcpy ( V_7 -> V_76 , V_168 , 8 ) ;
F_76 ( & V_13 . V_14 ) ;
sprintf ( V_169 , L_6 , F_96 ( & V_13 . V_171 ) ) ;
while ( F_50 ( V_169 ) ) {
sprintf ( V_169 , L_6 ,
F_96 ( & V_13 . V_171 ) ) ;
}
F_78 ( & V_13 . V_14 ) ;
memcpy ( & V_7 -> V_78 , V_169 , 8 ) ;
if ( ! V_7 -> V_68 )
V_7 -> V_68 = V_167 ;
return V_12 ;
}
static int F_97 ( struct V_113 * V_8 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_54 * V_55 ;
int V_106 = sizeof( struct V_57 ) + V_62 ;
int V_12 = 0 ;
V_55 = F_59 ( V_9 , V_106 , 1 , & V_12 ) ;
if ( ! V_55 ) {
V_12 = - V_93 ;
goto V_157;
}
V_55 -> V_4 = NULL ;
F_60 ( V_55 , V_106 ) ;
V_12 = F_27 ( NULL , V_9 , V_55 , V_66 ) ;
V_157:
return V_12 ;
}
static int F_98 ( struct V_113 * V_8 , struct V_146 * V_147 )
{
struct V_149 * V_150 = (struct V_149 * ) V_147 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
unsigned char V_104 [ 16 ] ;
int V_12 ;
F_1 ( V_104 , V_150 -> V_158 ) ;
F_2 ( V_104 , V_7 -> V_78 ) ;
F_32 ( V_104 , sizeof( V_104 ) ) ;
V_7 -> V_22 = F_99 ( V_7 -> V_68 ,
V_36 , V_139 ) ;
if ( ! V_7 -> V_22 ) {
V_12 = - V_93 ;
goto V_157;
}
V_12 = V_23 -> V_172 ( V_7 -> V_22 , & V_173 ,
V_150 -> V_161 , NULL , V_104 ,
V_9 ) ;
if ( V_12 ) {
F_12 ( V_7 -> V_22 ) ;
V_7 -> V_22 = NULL ;
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
V_157:
return V_12 ;
}
static int F_100 ( struct V_113 * V_8 , struct V_146 * V_147 ,
int V_178 , int V_35 )
{
struct V_149 * V_150 = (struct V_149 * ) V_147 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
int V_12 ;
if ( V_147 -> V_153 != V_154 || V_178 < sizeof( struct V_149 ) )
return - V_155 ;
if ( V_9 -> V_17 != V_25 && V_9 -> V_17 != V_26 )
return - V_156 ;
if ( V_9 -> V_17 == V_25 &&
V_7 -> V_41 == V_107 )
return - V_156 ;
if ( V_9 -> V_86 != V_135 && V_9 -> V_86 != V_87 )
return - V_155 ;
if ( V_9 -> V_17 == V_25 ) {
V_12 = F_93 ( V_9 ) ;
if ( F_95 ( V_12 ) )
return V_12 ;
}
F_58 ( V_9 ) ;
memcpy ( V_7 -> V_72 , V_150 -> V_161 , 8 ) ;
memcpy ( V_7 -> V_74 , V_150 -> V_158 , 8 ) ;
if ( V_7 -> V_41 == V_107 )
V_12 = F_97 ( V_8 ) ;
else
V_12 = F_98 ( V_8 , V_147 ) ;
if ( V_12 )
goto V_157;
if ( V_9 -> V_17 != V_21 )
V_12 = F_62 ( V_9 , F_16 ( V_9 , V_21 ,
V_19 ) ,
F_101 ( V_9 , V_35 & V_179 ) ) ;
if ( V_9 -> V_17 == V_19 || V_9 -> V_17 == V_28 )
V_12 = - V_177 ;
if ( V_12 && V_7 -> V_41 == V_42 ) {
V_23 -> V_24 ( V_7 -> V_22 , NULL ) ;
F_12 ( V_7 -> V_22 ) ;
V_7 -> V_22 = NULL ;
}
V_157:
F_63 ( V_9 ) ;
return V_12 ;
}
static int F_102 ( struct V_113 * V_8 , int V_180 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
int V_12 ;
F_58 ( V_9 ) ;
V_12 = - V_155 ;
if ( V_9 -> V_17 != V_26 )
goto V_157;
if ( V_8 -> type != V_135 && V_8 -> type != V_87 )
goto V_157;
V_9 -> V_181 = V_180 ;
V_9 -> V_182 = 0 ;
V_9 -> V_17 = V_27 ;
V_12 = 0 ;
V_157:
F_63 ( V_9 ) ;
return V_12 ;
}
static int F_103 ( struct V_113 * V_8 , struct V_113 * V_143 ,
int V_35 )
{
F_104 ( V_50 , V_183 ) ;
struct V_8 * V_9 = V_8 -> V_9 , * V_184 ;
long V_105 ;
int V_12 = 0 ;
F_105 ( V_9 , V_185 ) ;
if ( V_9 -> V_17 != V_27 ) {
V_12 = - V_156 ;
goto V_157;
}
V_105 = F_106 ( V_9 , V_35 & V_179 ) ;
F_107 ( F_108 ( V_9 ) , & V_50 ) ;
while ( ! ( V_184 = F_53 ( V_9 , V_143 ) ) ) {
F_109 ( V_186 ) ;
if ( ! V_105 ) {
V_12 = - V_175 ;
break;
}
F_63 ( V_9 ) ;
V_105 = F_110 ( V_105 ) ;
F_105 ( V_9 , V_185 ) ;
if ( V_9 -> V_17 != V_27 ) {
V_12 = - V_156 ;
break;
}
if ( F_111 ( V_183 ) ) {
V_12 = F_112 ( V_105 ) ;
break;
}
}
F_109 ( V_187 ) ;
F_113 ( F_108 ( V_9 ) , & V_50 ) ;
if ( V_12 )
goto V_157;
V_143 -> V_39 = V_188 ;
V_157:
F_63 ( V_9 ) ;
return V_12 ;
}
static int F_114 ( struct V_113 * V_8 , struct V_146 * V_147 ,
int * V_84 , int V_189 )
{
struct V_149 * V_190 = (struct V_149 * ) V_147 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
V_147 -> V_153 = V_154 ;
* V_84 = sizeof( struct V_149 ) ;
if ( V_189 ) {
memcpy ( V_190 -> V_161 , V_7 -> V_72 , 8 ) ;
memcpy ( V_190 -> V_158 , V_7 -> V_74 , 8 ) ;
} else {
memcpy ( V_190 -> V_161 , V_7 -> V_76 , 8 ) ;
memcpy ( V_190 -> V_158 , V_7 -> V_78 , 8 ) ;
}
memset ( & V_190 -> V_191 , 0 , sizeof( V_190 -> V_191 ) ) ;
memset ( & V_190 -> V_192 , 0 , sizeof( V_190 -> V_192 ) ) ;
memset ( & V_190 -> V_193 , 0 , sizeof( V_190 -> V_193 ) ) ;
return 0 ;
}
static int F_115 ( struct V_194 * V_22 , struct V_32 * V_33 ,
struct V_54 * V_55 )
{
T_2 V_195 [ 8 ] ;
memcpy ( V_195 , ( void * ) V_55 -> V_196 , V_55 -> V_84 ) ;
V_195 [ 7 ] = 0xff - ( T_2 ) V_55 -> V_84 ;
return V_23 -> V_197 ( V_22 , V_33 , V_36 , 0 ,
( void * ) V_195 , 8 ) ;
}
static int F_116 ( struct V_198 * V_199 , struct V_113 * V_8 ,
struct V_200 * V_33 , T_1 V_84 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_54 * V_55 ;
struct V_32 V_201 ;
struct V_202 * V_203 ;
int V_204 ;
long V_105 ;
char V_205 [ 9 ] ;
char V_206 [ 9 ] ;
int V_12 ;
int V_207 = V_33 -> V_208 & V_209 ;
V_12 = F_117 ( V_9 ) ;
if ( V_12 )
return V_12 ;
if ( V_33 -> V_208 & V_210 )
return - V_211 ;
if ( V_9 -> V_86 == V_87 && ! ( V_33 -> V_208 & V_212 ) )
return - V_211 ;
F_58 ( V_9 ) ;
if ( V_9 -> V_213 & V_214 ) {
V_12 = - V_30 ;
goto V_215;
}
if ( V_9 -> V_17 != V_21 ) {
V_12 = - V_216 ;
goto V_215;
}
V_204 = 0 ;
V_201 . V_217 = 0 ;
for ( V_203 = F_118 ( V_33 ) ; V_203 ;
V_203 = F_119 ( V_33 , V_203 ) ) {
if ( ! F_120 ( V_33 , V_203 ) ) {
V_12 = - V_155 ;
goto V_215;
}
if ( V_203 -> V_218 != V_219 )
continue;
if ( V_203 -> V_220 & V_204 ) {
V_12 = - V_155 ;
goto V_215;
}
V_204 |= V_203 -> V_220 ;
switch ( V_203 -> V_220 ) {
case V_221 :
if ( V_203 -> V_222 != F_121 ( V_223 ) ) {
V_12 = - V_155 ;
goto V_215;
}
memcpy ( & V_201 . V_217 ,
( void * ) F_122 ( V_203 ) , V_223 ) ;
break;
default:
V_12 = - V_155 ;
goto V_215;
break;
}
}
if ( V_7 -> V_41 == V_107 )
V_55 = F_59 ( V_9 ,
V_84 + sizeof( struct V_57 ) + V_62 ,
V_207 , & V_12 ) ;
else
V_55 = F_59 ( V_9 , V_84 , V_207 , & V_12 ) ;
if ( ! V_55 )
goto V_215;
if ( V_7 -> V_41 == V_107 )
F_60 ( V_55 , sizeof( struct V_57 ) + V_62 ) ;
if ( F_123 ( F_124 ( V_55 , V_84 ) , V_33 -> V_224 , V_84 ) ) {
V_12 = - V_225 ;
goto V_226;
}
V_105 = F_101 ( V_9 , V_207 ) ;
V_12 = F_62 ( V_9 , F_17 ( V_9 ) , V_105 ) ;
if ( V_12 )
goto V_226;
if ( V_9 -> V_17 != V_21 ) {
V_12 = - V_112 ;
goto V_226;
}
V_201 . V_227 = V_7 -> V_123 ++ ;
memcpy ( F_125 ( V_55 ) , & V_201 . V_227 , V_228 ) ;
if ( V_7 -> V_41 == V_107 ) {
F_126 ( & V_7 -> V_44 ) ;
V_12 = F_27 ( & V_201 , V_9 , V_55 , 0 ) ;
if ( V_12 ) {
F_127 ( & V_7 -> V_44 ) ;
goto V_226;
}
goto V_229;
}
F_37 ( & V_7 -> V_15 , V_55 ) ;
if ( ( ( V_7 -> V_22 -> V_35 & V_36 ) & V_7 -> V_35 )
&& V_55 -> V_84 <= 7 ) {
V_12 = F_115 ( V_7 -> V_22 , & V_201 , V_55 ) ;
if ( V_12 == 0 ) {
F_39 ( V_55 , & V_7 -> V_15 ) ;
F_40 ( V_55 ) ;
}
if ( V_12 == 0x15 ) {
V_23 -> V_24 ( V_7 -> V_22 , NULL ) ;
F_39 ( V_55 , & V_7 -> V_15 ) ;
V_12 = - V_30 ;
goto V_226;
}
} else
V_12 = V_23 -> V_197 ( V_7 -> V_22 , & V_201 , 0 , 0 ,
( void * ) V_55 -> V_196 , V_55 -> V_84 ) ;
if ( V_12 ) {
if ( V_12 == 3 ) {
V_205 [ 8 ] = 0 ;
memcpy ( V_205 , V_7 -> V_72 , 8 ) ;
V_206 [ 8 ] = 0 ;
memcpy ( V_206 , V_7 -> V_74 , 8 ) ;
F_128 ( L_7
L_8 ,
V_206 , V_205 ) ;
V_12 = - V_175 ;
} else
V_12 = - V_30 ;
F_39 ( V_55 , & V_7 -> V_15 ) ;
goto V_226;
}
V_229:
F_63 ( V_9 ) ;
return V_84 ;
V_226:
F_40 ( V_55 ) ;
V_215:
F_63 ( V_9 ) ;
return V_12 ;
}
static int F_129 ( struct V_8 * V_9 , struct V_54 * V_55 , int V_84 )
{
int V_230 , V_231 , V_232 = 0 ;
struct V_54 * V_59 ;
V_230 = V_84 ;
while ( V_230 ) {
if ( V_230 >= V_9 -> V_233 / 4 )
V_231 = V_9 -> V_233 / 4 ;
else
V_231 = V_230 ;
V_59 = F_130 ( V_231 , V_92 | V_130 ) ;
if ( ! V_59 )
return - V_93 ;
memcpy ( F_131 ( V_59 ) , F_131 ( V_55 ) , V_234 ) ;
memcpy ( V_59 -> V_196 , V_55 -> V_196 + V_232 , V_231 ) ;
V_232 += V_231 ;
V_230 -= V_231 ;
F_132 ( V_59 ) ;
F_31 ( V_59 ) ;
V_59 -> V_84 = V_231 ;
F_37 ( & F_10 ( V_9 ) -> V_16 , V_59 ) ;
}
return 0 ;
}
static void F_133 ( struct V_8 * V_9 , struct V_54 * V_55 ,
struct V_194 * V_22 ,
struct V_32 * V_33 )
{
int V_235 ;
unsigned int V_84 ;
V_84 = F_15 ( V_33 ) ;
memcpy ( F_131 ( V_55 ) , & V_33 -> V_217 , V_234 ) ;
if ( ( V_33 -> V_35 & V_36 ) && V_84 > 7 ) {
if ( memcmp ( V_33 -> V_37 , V_236 , 8 ) == 0 ) {
V_55 -> V_196 = NULL ;
V_55 -> V_84 = 0 ;
}
} else {
V_235 = V_23 -> V_237 ( V_22 , V_33 ,
V_33 -> V_35 & V_36 ,
V_55 -> V_196 , V_84 , NULL ) ;
if ( V_235 ) {
F_40 ( V_55 ) ;
return;
}
if ( V_9 -> V_86 == V_135 &&
V_55 -> V_238 >= V_9 -> V_233 / 4 ) {
V_235 = F_129 ( V_9 , V_55 , V_84 ) ;
F_40 ( V_55 ) ;
V_55 = NULL ;
if ( V_235 ) {
V_23 -> V_24 ( V_22 , NULL ) ;
return;
}
V_55 = F_134 ( & F_10 ( V_9 ) -> V_16 ) ;
} else {
F_132 ( V_55 ) ;
F_31 ( V_55 ) ;
V_55 -> V_84 = V_84 ;
}
}
if ( F_135 ( V_9 , V_55 ) )
F_136 ( & F_10 ( V_9 ) -> V_16 , V_55 ) ;
}
static void F_137 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_54 * V_55 ;
struct V_239 * V_240 , * V_145 ;
F_89 (p, n, &iucv->message_q.list, list) {
V_55 = F_130 ( F_15 ( & V_240 -> V_33 ) , V_92 | V_130 ) ;
if ( ! V_55 )
break;
F_133 ( V_9 , V_55 , V_240 -> V_22 , & V_240 -> V_33 ) ;
F_138 ( & V_240 -> V_122 ) ;
F_139 ( V_240 ) ;
if ( ! F_61 ( & V_7 -> V_16 ) )
break;
}
}
static int F_140 ( struct V_198 * V_199 , struct V_113 * V_8 ,
struct V_200 * V_33 , T_1 V_84 , int V_35 )
{
int V_207 = V_35 & V_209 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
unsigned int V_232 , V_241 ;
struct V_54 * V_55 , * V_242 , * V_243 , * V_244 ;
int V_106 ;
int V_12 = 0 ;
if ( ( V_9 -> V_17 == V_19 || V_9 -> V_17 == V_18 ) &&
F_61 ( & V_7 -> V_16 ) &&
F_61 ( & V_9 -> V_98 ) &&
F_141 ( & V_7 -> V_121 . V_122 ) )
return 0 ;
if ( V_35 & ( V_210 ) )
return - V_211 ;
V_55 = F_142 ( V_9 , V_35 , V_207 , & V_12 ) ;
if ( ! V_55 ) {
if ( V_9 -> V_213 & V_245 )
return 0 ;
return V_12 ;
}
V_241 = V_55 -> V_84 ;
V_232 = F_143 (unsigned int, rlen, len) ;
V_243 = V_55 ;
if ( F_144 ( V_243 , 0 , V_33 -> V_224 , V_232 ) ) {
if ( ! ( V_35 & V_246 ) )
F_136 ( & V_9 -> V_98 , V_55 ) ;
return - V_225 ;
}
if ( V_9 -> V_86 == V_87 ) {
if ( V_232 < V_241 )
V_33 -> V_208 |= V_247 ;
V_33 -> V_208 |= V_212 ;
}
V_12 = F_145 ( V_33 , V_219 , V_221 ,
V_234 , F_131 ( V_55 ) ) ;
if ( V_12 ) {
if ( ! ( V_35 & V_246 ) )
F_136 ( & V_9 -> V_98 , V_55 ) ;
return V_12 ;
}
if ( ! ( V_35 & V_246 ) ) {
if ( V_9 -> V_86 == V_135 ) {
F_146 ( V_55 , V_232 ) ;
if ( V_55 -> V_84 ) {
F_136 ( & V_9 -> V_98 , V_55 ) ;
goto V_157;
}
}
F_40 ( V_55 ) ;
F_126 ( & V_7 -> V_70 ) ;
F_147 ( & V_7 -> V_121 . V_14 ) ;
V_242 = F_134 ( & V_7 -> V_16 ) ;
while ( V_242 ) {
if ( F_135 ( V_9 , V_242 ) ) {
F_136 ( & V_7 -> V_16 ,
V_242 ) ;
break;
} else {
V_242 = F_134 ( & V_7 -> V_16 ) ;
}
}
if ( F_61 ( & V_7 -> V_16 ) ) {
if ( ! F_141 ( & V_7 -> V_121 . V_122 ) )
F_137 ( V_9 ) ;
if ( F_19 ( & V_7 -> V_70 ) >=
V_7 -> V_68 / 2 ) {
V_106 = sizeof( struct V_57 ) +
V_62 ;
V_244 = F_59 ( V_9 , V_106 , 1 , & V_12 ) ;
if ( V_244 ) {
F_60 ( V_244 ,
sizeof( struct V_57 )
+ V_62 ) ;
V_12 = F_27 ( NULL , V_9 , V_244 ,
V_69 ) ;
}
if ( V_12 ) {
V_9 -> V_17 = V_19 ;
V_9 -> V_31 ( V_9 ) ;
}
}
}
F_148 ( & V_7 -> V_121 . V_14 ) ;
}
V_157:
if ( V_9 -> V_86 == V_87 && ( V_35 & V_247 ) )
V_232 = V_241 ;
return V_232 ;
}
static inline unsigned int F_149 ( struct V_8 * V_100 )
{
struct V_6 * V_144 , * V_145 ;
struct V_8 * V_9 ;
F_89 (isk, n, &iucv_sk(parent)->accept_q, accept_q) {
V_9 = (struct V_8 * ) V_144 ;
if ( V_9 -> V_17 == V_21 )
return V_248 | V_249 ;
}
return 0 ;
}
unsigned int F_150 ( struct V_250 * V_250 , struct V_113 * V_8 ,
T_4 * V_50 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
unsigned int V_251 = 0 ;
F_151 ( V_250 , F_108 ( V_9 ) , V_50 ) ;
if ( V_9 -> V_17 == V_27 )
return F_149 ( V_9 ) ;
if ( V_9 -> V_29 || ! F_61 ( & V_9 -> V_252 ) )
V_251 |= V_253 ;
if ( V_9 -> V_213 & V_245 )
V_251 |= V_254 ;
if ( V_9 -> V_213 == V_255 )
V_251 |= V_256 ;
if ( ! F_61 ( & V_9 -> V_98 ) ||
( V_9 -> V_213 & V_245 ) )
V_251 |= V_248 | V_249 ;
if ( V_9 -> V_17 == V_28 )
V_251 |= V_256 ;
if ( V_9 -> V_17 == V_19 || V_9 -> V_17 == V_18 )
V_251 |= V_248 ;
if ( F_152 ( V_9 ) )
V_251 |= V_257 | V_258 | V_259 ;
else
F_153 ( V_260 , & V_9 -> V_102 -> V_35 ) ;
return V_251 ;
}
static int F_154 ( struct V_113 * V_8 , int V_261 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_32 V_201 ;
int V_12 = 0 ;
V_261 ++ ;
if ( ( V_261 & ~ V_255 ) || ! V_261 )
return - V_155 ;
F_58 ( V_9 ) ;
switch ( V_9 -> V_17 ) {
case V_19 :
case V_20 :
case V_18 :
case V_28 :
V_12 = - V_216 ;
goto V_226;
default:
V_9 -> V_213 |= V_261 ;
break;
}
if ( V_261 == V_214 || V_261 == V_255 ) {
V_201 . V_217 = 0 ;
V_201 . V_227 = 0 ;
V_12 = V_23 -> V_197 ( V_7 -> V_22 , & V_201 , V_36 ,
0 , ( void * ) V_236 , 8 ) ;
if ( V_12 ) {
switch ( V_12 ) {
case 1 :
V_12 = - V_216 ;
break;
case 2 :
V_12 = - V_112 ;
break;
default:
V_12 = - V_216 ;
break;
}
}
}
if ( V_261 == V_245 || V_261 == V_255 ) {
V_12 = V_23 -> V_262 ( V_7 -> V_22 , NULL ) ;
if ( V_12 )
V_12 = - V_216 ;
F_11 ( & V_9 -> V_98 ) ;
}
V_9 -> V_31 ( V_9 ) ;
V_226:
F_63 ( V_9 ) ;
return V_12 ;
}
static int F_155 ( struct V_113 * V_8 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
int V_12 = 0 ;
if ( ! V_9 )
return 0 ;
F_54 ( V_9 ) ;
if ( F_10 ( V_9 ) -> V_22 ) {
V_23 -> V_24 ( F_10 ( V_9 ) -> V_22 , NULL ) ;
F_12 ( F_10 ( V_9 ) -> V_22 ) ;
F_10 ( V_9 ) -> V_22 = NULL ;
}
F_156 ( V_9 ) ;
F_46 ( V_9 ) ;
return V_12 ;
}
static int F_157 ( struct V_113 * V_8 , int V_263 , int V_264 ,
char T_5 * V_265 , unsigned int V_266 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
int V_267 ;
int V_235 ;
if ( V_263 != V_219 )
return - V_268 ;
if ( V_266 < sizeof( int ) )
return - V_155 ;
if ( F_158 ( V_267 , ( int T_5 * ) V_265 ) )
return - V_225 ;
V_235 = 0 ;
F_58 ( V_9 ) ;
switch ( V_264 ) {
case V_269 :
if ( V_267 )
V_7 -> V_35 |= V_36 ;
else
V_7 -> V_35 &= ~ V_36 ;
break;
case V_270 :
switch ( V_9 -> V_17 ) {
case V_25 :
case V_26 :
if ( V_267 < 1 || V_267 > ( V_271 ) ( ~ 0 ) )
V_235 = - V_155 ;
else
V_7 -> V_68 = V_267 ;
break;
default:
V_235 = - V_155 ;
break;
}
break;
default:
V_235 = - V_268 ;
break;
}
F_63 ( V_9 ) ;
return V_235 ;
}
static int F_159 ( struct V_113 * V_8 , int V_263 , int V_264 ,
char T_5 * V_265 , int T_5 * V_266 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
int V_267 , V_84 ;
if ( V_263 != V_219 )
return - V_268 ;
if ( F_158 ( V_84 , V_266 ) )
return - V_225 ;
if ( V_84 < 0 )
return - V_155 ;
V_84 = F_143 (unsigned int, len, sizeof(int)) ;
switch ( V_264 ) {
case V_269 :
V_267 = ( V_7 -> V_35 & V_36 ) ? 1 : 0 ;
break;
case V_270 :
F_58 ( V_9 ) ;
V_267 = ( V_7 -> V_22 != NULL ) ? V_7 -> V_22 -> V_43
: V_7 -> V_68 ;
F_63 ( V_9 ) ;
break;
default:
return - V_268 ;
}
if ( F_160 ( V_84 , V_266 ) )
return - V_225 ;
if ( F_161 ( V_265 , & V_267 , V_84 ) )
return - V_225 ;
return 0 ;
}
static int F_162 ( struct V_194 * V_22 ,
T_2 V_272 [ 8 ] , T_2 V_273 [ 16 ] )
{
unsigned char V_104 [ 16 ] ;
unsigned char V_274 [ 16 ] ;
unsigned char V_78 [ 8 ] ;
struct V_10 * V_11 ;
struct V_8 * V_9 , * V_184 ;
struct V_6 * V_7 , * V_275 ;
int V_12 ;
memcpy ( V_78 , V_273 , 8 ) ;
F_163 ( V_78 , 8 ) ;
F_8 ( & V_13 . V_14 ) ;
V_7 = NULL ;
V_9 = NULL ;
F_9 (sk, node, &iucv_sk_list.head)
if ( V_9 -> V_17 == V_27 &&
! memcmp ( & F_10 ( V_9 ) -> V_78 , V_78 , 8 ) ) {
V_7 = F_10 ( V_9 ) ;
break;
}
F_13 ( & V_13 . V_14 ) ;
if ( ! V_7 )
return - V_155 ;
F_44 ( V_9 ) ;
F_2 ( V_104 , V_7 -> V_78 ) ;
F_1 ( V_104 , V_7 -> V_74 ) ;
F_32 ( V_104 , sizeof( V_104 ) ) ;
if ( V_9 -> V_17 != V_27 ) {
V_12 = V_23 -> V_24 ( V_22 , V_104 ) ;
F_12 ( V_22 ) ;
goto V_226;
}
if ( F_164 ( V_9 ) ) {
V_12 = V_23 -> V_24 ( V_22 , V_104 ) ;
F_12 ( V_22 ) ;
goto V_226;
}
V_184 = F_65 ( NULL , V_9 -> V_86 , V_92 ) ;
if ( ! V_184 ) {
V_12 = V_23 -> V_24 ( V_22 , V_104 ) ;
F_12 ( V_22 ) ;
goto V_226;
}
V_275 = F_10 ( V_184 ) ;
F_64 ( V_184 , V_9 ) ;
memcpy ( V_275 -> V_74 , V_273 + 8 , 8 ) ;
F_163 ( V_275 -> V_74 , 8 ) ;
memcpy ( V_275 -> V_72 , V_272 , 8 ) ;
memcpy ( V_275 -> V_78 , V_7 -> V_78 , 8 ) ;
memcpy ( V_275 -> V_76 , V_7 -> V_76 , 8 ) ;
V_275 -> V_22 = V_22 ;
F_1 ( V_274 , V_273 + 8 ) ;
memcpy ( V_274 + 8 , V_275 -> V_78 , 8 ) ;
F_32 ( V_274 + 8 , 8 ) ;
V_275 -> V_68 = V_7 -> V_68 ;
V_22 -> V_43 = V_7 -> V_68 ;
V_12 = V_23 -> V_276 ( V_22 , & V_173 , V_274 , V_184 ) ;
if ( V_12 ) {
V_12 = V_23 -> V_24 ( V_22 , V_104 ) ;
F_12 ( V_22 ) ;
F_46 ( V_184 ) ;
goto V_226;
}
F_80 ( V_9 , V_184 ) ;
V_184 -> V_17 = V_21 ;
V_9 -> V_277 ( V_9 , 1 ) ;
V_12 = 0 ;
V_226:
F_45 ( V_9 ) ;
return 0 ;
}
static void F_165 ( struct V_194 * V_22 , T_2 V_273 [ 16 ] )
{
struct V_8 * V_9 = V_22 -> V_278 ;
V_9 -> V_17 = V_21 ;
V_9 -> V_31 ( V_9 ) ;
}
static void F_166 ( struct V_194 * V_22 , struct V_32 * V_33 )
{
struct V_8 * V_9 = V_22 -> V_278 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_54 * V_55 ;
struct V_239 * V_279 ;
int V_84 ;
if ( V_9 -> V_213 & V_245 ) {
V_23 -> V_280 ( V_22 , V_33 ) ;
return;
}
F_167 ( & V_7 -> V_121 . V_14 ) ;
if ( ! F_141 ( & V_7 -> V_121 . V_122 ) ||
! F_61 ( & V_7 -> V_16 ) )
goto V_281;
V_84 = F_19 ( & V_9 -> V_282 ) ;
V_84 += F_168 ( F_15 ( V_33 ) ) ;
if ( V_84 > V_9 -> V_233 )
goto V_281;
V_55 = F_130 ( F_15 ( V_33 ) , V_92 | V_130 ) ;
if ( ! V_55 )
goto V_281;
F_133 ( V_9 , V_55 , V_22 , V_33 ) ;
goto V_283;
V_281:
V_279 = F_169 ( sizeof( struct V_239 ) , V_92 | V_130 ) ;
if ( ! V_279 )
goto V_283;
V_279 -> V_22 = V_22 ;
V_279 -> V_33 = * V_33 ;
F_83 ( & V_279 -> V_122 , & V_7 -> V_121 . V_122 ) ;
V_283:
F_170 ( & V_7 -> V_121 . V_14 ) ;
}
static void F_171 ( struct V_194 * V_22 ,
struct V_32 * V_33 )
{
struct V_8 * V_9 = V_22 -> V_278 ;
struct V_54 * V_284 = NULL ;
struct V_285 * V_122 = & F_10 ( V_9 ) -> V_15 ;
struct V_54 * V_286 = V_122 -> V_287 ;
unsigned long V_35 ;
if ( ! F_61 ( V_122 ) ) {
F_82 ( & V_122 -> V_14 , V_35 ) ;
while ( V_286 != (struct V_54 * ) V_122 ) {
if ( ! memcmp ( & V_33 -> V_227 , F_125 ( V_286 ) , V_228 ) ) {
V_284 = V_286 ;
break;
}
V_286 = V_286 -> V_287 ;
}
if ( V_284 )
F_172 ( V_284 , V_122 ) ;
F_84 ( & V_122 -> V_14 , V_35 ) ;
if ( V_284 ) {
F_40 ( V_284 ) ;
F_20 ( V_9 ) ;
}
}
F_173 ( ! V_284 ) ;
if ( V_9 -> V_17 == V_20 ) {
if ( F_61 ( & F_10 ( V_9 ) -> V_15 ) ) {
V_9 -> V_17 = V_28 ;
V_9 -> V_31 ( V_9 ) ;
}
}
}
static void F_174 ( struct V_194 * V_22 , T_2 V_273 [ 16 ] )
{
struct V_8 * V_9 = V_22 -> V_278 ;
if ( ! F_141 ( & F_10 ( V_9 ) -> V_119 ) )
V_9 -> V_17 = V_18 ;
else
V_9 -> V_17 = V_19 ;
V_9 -> V_31 ( V_9 ) ;
}
static void F_175 ( struct V_194 * V_22 , T_2 V_273 [ 16 ] )
{
struct V_8 * V_9 = V_22 -> V_278 ;
F_44 ( V_9 ) ;
if ( V_9 -> V_17 != V_28 ) {
V_9 -> V_213 |= V_214 ;
V_9 -> V_31 ( V_9 ) ;
}
F_45 ( V_9 ) ;
}
static void F_176 ( struct V_54 * V_55 )
{
struct V_57 * V_288 =
(struct V_57 * ) V_55 -> V_196 ;
char V_289 [ 8 ] ;
char V_290 [ 8 ] ;
F_32 ( V_288 -> V_71 , sizeof( V_288 -> V_71 ) ) ;
F_32 ( V_288 -> V_73 , sizeof( V_288 -> V_73 ) ) ;
F_32 ( V_288 -> V_75 , sizeof( V_288 -> V_75 ) ) ;
F_32 ( V_288 -> V_77 , sizeof( V_288 -> V_77 ) ) ;
memcpy ( V_289 , V_288 -> V_75 , 8 ) ;
memcpy ( V_290 , V_288 -> V_77 , 8 ) ;
memcpy ( V_288 -> V_75 , V_288 -> V_71 , 8 ) ;
memcpy ( V_288 -> V_77 , V_288 -> V_73 , 8 ) ;
memcpy ( V_288 -> V_71 , V_289 , 8 ) ;
memcpy ( V_288 -> V_73 , V_290 , 8 ) ;
F_29 ( V_55 , V_62 ) ;
memset ( V_55 -> V_196 , 0 , V_62 ) ;
}
static int F_177 ( struct V_8 * V_9 , struct V_54 * V_55 )
{
struct V_8 * V_184 ;
struct V_6 * V_7 , * V_275 ;
struct V_57 * V_288 ;
int V_12 ;
V_7 = F_10 ( V_9 ) ;
V_288 = (struct V_57 * ) V_55 -> V_196 ;
if ( ! V_7 ) {
F_176 ( V_55 ) ;
V_288 -> V_35 = V_66 | V_108 ;
V_12 = F_38 ( V_55 ) ;
goto V_215;
}
V_184 = F_65 ( NULL , V_9 -> V_86 , V_92 ) ;
F_44 ( V_9 ) ;
if ( ( V_9 -> V_17 != V_27 ) ||
F_164 ( V_9 ) ||
! V_184 ) {
if ( V_184 )
F_178 ( V_184 ) ;
F_176 ( V_55 ) ;
V_288 -> V_35 = V_66 | V_108 ;
V_12 = F_38 ( V_55 ) ;
F_45 ( V_9 ) ;
goto V_215;
}
V_275 = F_10 ( V_184 ) ;
F_64 ( V_184 , V_9 ) ;
V_275 -> V_41 = V_107 ;
V_275 -> V_68 = V_7 -> V_68 ;
if ( ! V_288 -> V_67 )
V_275 -> V_45 = V_166 ;
else
V_275 -> V_45 = V_288 -> V_67 ;
memcpy ( V_275 -> V_74 , V_288 -> V_77 , 8 ) ;
memcpy ( V_275 -> V_72 , V_288 -> V_75 , 8 ) ;
memcpy ( V_275 -> V_78 , V_7 -> V_78 , 8 ) ;
memcpy ( V_275 -> V_76 , V_7 -> V_76 , 8 ) ;
V_184 -> V_80 = V_9 -> V_80 ;
F_176 ( V_55 ) ;
V_288 -> V_35 = V_66 | V_291 ;
V_288 -> V_67 = V_275 -> V_68 ;
V_12 = F_38 ( V_55 ) ;
if ( ! V_12 ) {
F_80 ( V_9 , V_184 ) ;
V_184 -> V_17 = V_21 ;
V_9 -> V_277 ( V_9 , 1 ) ;
} else
F_46 ( V_184 ) ;
F_45 ( V_9 ) ;
V_215:
return V_292 ;
}
static int F_179 ( struct V_8 * V_9 , struct V_54 * V_55 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_57 * V_288 =
(struct V_57 * ) V_55 -> V_196 ;
if ( ! V_7 )
goto V_215;
if ( V_9 -> V_17 != V_26 )
goto V_215;
F_44 ( V_9 ) ;
V_7 -> V_45 = V_288 -> V_67 ;
V_9 -> V_17 = V_21 ;
V_9 -> V_31 ( V_9 ) ;
F_45 ( V_9 ) ;
V_215:
F_40 ( V_55 ) ;
return V_292 ;
}
static int F_180 ( struct V_8 * V_9 , struct V_54 * V_55 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
if ( ! V_7 )
goto V_215;
if ( V_9 -> V_17 != V_26 )
goto V_215;
F_44 ( V_9 ) ;
V_9 -> V_17 = V_19 ;
V_9 -> V_31 ( V_9 ) ;
F_45 ( V_9 ) ;
V_215:
F_40 ( V_55 ) ;
return V_292 ;
}
static int F_181 ( struct V_8 * V_9 , struct V_54 * V_55 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
if ( V_7 ) {
F_44 ( V_9 ) ;
if ( ! F_141 ( & V_7 -> V_119 ) )
V_9 -> V_17 = V_18 ;
else
V_9 -> V_17 = V_19 ;
V_9 -> V_31 ( V_9 ) ;
F_45 ( V_9 ) ;
}
F_40 ( V_55 ) ;
return V_292 ;
}
static int F_182 ( struct V_8 * V_9 , struct V_54 * V_55 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_57 * V_288 =
(struct V_57 * ) V_55 -> V_196 ;
if ( ! V_7 )
return V_292 ;
if ( V_9 -> V_17 != V_21 )
return V_292 ;
F_41 ( V_288 -> V_67 , & V_7 -> V_44 ) ;
F_20 ( V_9 ) ;
return V_292 ;
}
static int F_183 ( struct V_8 * V_9 , struct V_54 * V_55 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
if ( ! V_7 ) {
F_40 ( V_55 ) ;
return V_292 ;
}
if ( V_9 -> V_17 != V_21 ) {
F_40 ( V_55 ) ;
return V_292 ;
}
if ( V_55 -> V_84 <= sizeof( struct V_57 ) ) {
F_40 ( V_55 ) ;
return V_292 ;
}
F_146 ( V_55 , sizeof( struct V_57 ) ) ;
F_132 ( V_55 ) ;
F_31 ( V_55 ) ;
F_167 ( & V_7 -> V_121 . V_14 ) ;
if ( F_61 ( & V_7 -> V_16 ) ) {
if ( F_135 ( V_9 , V_55 ) ) {
F_37 ( & V_7 -> V_16 , V_55 ) ;
}
} else
F_37 ( & F_10 ( V_9 ) -> V_16 , V_55 ) ;
F_170 ( & V_7 -> V_121 . V_14 ) ;
return V_292 ;
}
static int F_184 ( struct V_54 * V_55 , struct V_151 * V_4 ,
struct V_293 * V_294 , struct V_151 * V_295 )
{
struct V_10 * V_11 ;
struct V_8 * V_9 ;
struct V_6 * V_7 ;
struct V_57 * V_288 ;
char V_296 [ 8 ] ;
int V_12 = 0 ;
F_146 ( V_55 , V_62 ) ;
V_288 = (struct V_57 * ) V_55 -> V_196 ;
F_163 ( V_288 -> V_73 , sizeof( V_288 -> V_73 ) ) ;
F_163 ( V_288 -> V_71 , sizeof( V_288 -> V_71 ) ) ;
F_163 ( V_288 -> V_77 , sizeof( V_288 -> V_77 ) ) ;
F_163 ( V_288 -> V_75 , sizeof( V_288 -> V_75 ) ) ;
memset ( V_296 , 0 , sizeof( V_296 ) ) ;
V_7 = NULL ;
V_9 = NULL ;
F_8 ( & V_13 . V_14 ) ;
F_9 (sk, node, &iucv_sk_list.head) {
if ( V_288 -> V_35 == V_66 ) {
if ( ( ! memcmp ( & F_10 ( V_9 ) -> V_78 ,
V_288 -> V_73 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_76 ,
V_288 -> V_71 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_74 , V_296 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_72 ,
V_296 , 8 ) ) ) {
V_7 = F_10 ( V_9 ) ;
break;
}
} else {
if ( ( ! memcmp ( & F_10 ( V_9 ) -> V_78 ,
V_288 -> V_73 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_76 ,
V_288 -> V_71 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_74 ,
V_288 -> V_77 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_72 ,
V_288 -> V_75 , 8 ) ) ) {
V_7 = F_10 ( V_9 ) ;
break;
}
}
}
F_13 ( & V_13 . V_14 ) ;
if ( ! V_7 )
V_9 = NULL ;
switch ( V_288 -> V_35 ) {
case V_66 :
V_12 = F_177 ( V_9 , V_55 ) ;
break;
case ( V_66 | V_291 ) :
V_12 = F_179 ( V_9 , V_55 ) ;
break;
case ( V_66 | V_108 ) :
V_12 = F_180 ( V_9 , V_55 ) ;
break;
case ( V_108 ) :
V_12 = F_181 ( V_9 , V_55 ) ;
break;
case ( V_69 ) :
V_12 = F_182 ( V_9 , V_55 ) ;
if ( V_55 -> V_84 > sizeof( struct V_57 ) )
V_12 = F_183 ( V_9 , V_55 ) ;
else
F_139 ( V_55 ) ;
break;
case 0 :
V_12 = F_183 ( V_9 , V_55 ) ;
break;
default:
;
}
return V_12 ;
}
static void V_125 ( struct V_54 * V_55 ,
enum V_297 V_145 )
{
struct V_8 * V_144 = V_55 -> V_9 ;
struct V_8 * V_9 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_285 * V_122 ;
struct V_54 * V_286 ;
struct V_54 * V_284 = NULL ;
unsigned long V_35 ;
struct V_10 * V_11 ;
F_8 ( & V_13 . V_14 ) ;
F_9 (sk, node, &iucv_sk_list.head)
if ( V_9 == V_144 ) {
V_7 = F_10 ( V_9 ) ;
break;
}
F_13 ( & V_13 . V_14 ) ;
if ( ! V_7 )
return;
F_44 ( V_9 ) ;
V_122 = & V_7 -> V_15 ;
V_286 = V_122 -> V_287 ;
if ( F_61 ( V_122 ) )
goto V_283;
F_82 ( & V_122 -> V_14 , V_35 ) ;
while ( V_286 != (struct V_54 * ) V_122 ) {
if ( F_35 ( V_286 ) == F_35 ( V_55 ) ) {
V_284 = V_286 ;
switch ( V_145 ) {
case V_298 :
F_172 ( V_284 , V_122 ) ;
F_20 ( V_9 ) ;
F_40 ( V_284 ) ;
break;
case V_299 :
F_126 ( & V_7 -> V_46 ) ;
break;
case V_300 :
F_172 ( V_284 , V_122 ) ;
F_127 ( & V_7 -> V_46 ) ;
if ( F_19 ( & V_7 -> V_46 ) <= 0 )
F_20 ( V_9 ) ;
F_40 ( V_284 ) ;
break;
case V_301 :
case V_302 :
case V_303 :
case V_304 :
case V_305 :
F_172 ( V_284 , V_122 ) ;
F_40 ( V_284 ) ;
if ( ! F_141 ( & V_7 -> V_119 ) )
V_9 -> V_17 = V_18 ;
else
V_9 -> V_17 = V_19 ;
V_9 -> V_31 ( V_9 ) ;
break;
}
break;
}
V_286 = V_286 -> V_287 ;
}
F_84 ( & V_122 -> V_14 , V_35 ) ;
V_283:
F_45 ( V_9 ) ;
}
static int F_185 ( void )
{
int V_12 ;
V_12 = V_23 -> V_306 ( & V_173 , 0 ) ;
if ( V_12 )
goto V_215;
V_307 . V_308 = V_23 -> V_308 ;
V_12 = F_186 ( & V_307 ) ;
if ( V_12 )
goto V_309;
V_310 = F_169 ( sizeof( struct V_3 ) , V_139 ) ;
if ( ! V_310 ) {
V_12 = - V_93 ;
goto V_311;
}
F_187 ( V_310 , L_9 ) ;
V_310 -> V_308 = V_23 -> V_308 ;
V_310 -> V_100 = V_23 -> V_312 ;
V_310 -> V_229 = ( void ( * ) ( struct V_3 * ) ) F_139 ;
V_310 -> V_313 = & V_307 ;
V_12 = F_188 ( V_310 ) ;
if ( V_12 )
goto V_311;
return 0 ;
V_311:
F_189 ( & V_307 ) ;
V_309:
V_23 -> V_314 ( & V_173 , 0 ) ;
V_215:
return V_12 ;
}
static int T_6 F_190 ( void )
{
int V_12 ;
if ( V_315 ) {
F_94 ( L_5 , V_162 , sizeof( V_162 ) , & V_12 ) ;
if ( F_95 ( V_12 ) ) {
F_42 ( V_12 ) ;
V_12 = - V_133 ;
goto V_215;
}
V_23 = F_191 ( F_192 ( V_316 ) , L_10 ) ;
if ( ! V_23 ) {
F_5 ( V_5 L_11 ) ;
memset ( & V_162 , 0 , sizeof( V_162 ) ) ;
}
} else {
memset ( & V_162 , 0 , sizeof( V_162 ) ) ;
V_23 = NULL ;
}
V_12 = F_193 ( & V_118 , 0 ) ;
if ( V_12 )
goto V_215;
V_12 = F_194 ( & V_317 ) ;
if ( V_12 )
goto V_318;
if ( V_23 ) {
V_12 = F_185 () ;
if ( V_12 )
goto V_319;
}
F_195 ( & V_320 ) ;
return 0 ;
V_319:
F_196 ( V_117 ) ;
V_318:
F_197 ( & V_118 ) ;
V_215:
if ( V_23 )
F_198 ( V_316 ) ;
return V_12 ;
}
static void T_7 F_199 ( void )
{
if ( V_23 ) {
F_200 ( V_310 ) ;
F_189 ( & V_307 ) ;
V_23 -> V_314 ( & V_173 , 0 ) ;
F_198 ( V_316 ) ;
}
F_201 ( & V_320 ) ;
F_196 ( V_117 ) ;
F_197 ( & V_118 ) ;
}
