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
int V_10 = 0 ;
#ifdef F_4
F_5 ( V_5 L_3 ) ;
#endif
F_8 ( & V_11 . V_12 ) ;
F_9 (sk, &iucv_sk_list.head) {
V_7 = F_10 ( V_9 ) ;
switch ( V_9 -> V_13 ) {
case V_14 :
case V_15 :
case V_16 :
F_11 ( V_9 , 0 ) ;
break;
case V_17 :
case V_18 :
case V_19 :
case V_20 :
default:
break;
}
F_12 ( & V_7 -> V_21 ) ;
F_12 ( & V_7 -> V_22 ) ;
}
F_13 ( & V_11 . V_12 ) ;
return V_10 ;
}
static int F_14 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
#ifdef F_4
F_5 ( V_5 L_4 ) ;
#endif
F_8 ( & V_11 . V_12 ) ;
F_9 (sk, &iucv_sk_list.head) {
switch ( V_9 -> V_13 ) {
case V_16 :
V_9 -> V_23 = V_24 ;
V_9 -> V_13 = V_14 ;
V_9 -> V_25 ( V_9 ) ;
break;
case V_14 :
case V_15 :
case V_19 :
case V_18 :
case V_17 :
default:
break;
}
}
F_13 ( & V_11 . V_12 ) ;
return 0 ;
}
static inline T_1 F_15 ( struct V_26 * V_27 )
{
T_1 V_28 ;
if ( V_27 -> V_29 & V_30 ) {
V_28 = 0xff - V_27 -> V_31 [ 7 ] ;
return ( V_28 < 8 ) ? V_28 : 8 ;
}
return V_27 -> V_32 ;
}
static int F_16 ( struct V_8 * V_9 , int V_33 , int V_34 )
{
return ( V_9 -> V_13 == V_33 || V_9 -> V_13 == V_34 ) ;
}
static inline int F_17 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
if ( V_9 -> V_13 != V_16 )
return 1 ;
if ( V_7 -> V_35 == V_36 )
return ( F_18 ( & V_7 -> V_21 ) < V_7 -> V_37 -> V_38 ) ;
else
return ( ( F_19 ( & V_7 -> V_39 ) < V_7 -> V_40 ) &&
( F_19 ( & V_7 -> V_41 ) <= 0 ) ) ;
}
static void F_20 ( struct V_8 * V_9 )
{
struct V_42 * V_43 ;
F_21 () ;
V_43 = F_22 ( V_9 -> V_44 ) ;
if ( F_23 ( V_43 ) )
F_24 ( & V_43 -> V_45 ) ;
F_25 ( V_9 , V_46 , V_47 ) ;
F_26 () ;
}
static int F_27 ( struct V_26 * V_48 , struct V_8 * V_8 ,
struct V_49 * V_50 , T_2 V_29 )
{
struct V_6 * V_7 = F_10 ( V_8 ) ;
struct V_51 * V_52 ;
struct V_49 * V_53 ;
int V_10 , V_54 = 0 ;
memset ( V_50 -> V_55 , 0 , V_56 ) ;
V_52 = (struct V_51 * ) F_28 ( V_50 ,
sizeof( struct V_51 ) ) ;
F_29 ( V_50 ) ;
F_30 ( V_50 ) ;
F_28 ( V_50 , V_56 ) ;
F_29 ( V_50 ) ;
memset ( V_52 , 0 , sizeof( struct V_51 ) ) ;
V_52 -> V_57 = V_58 ;
V_52 -> V_59 = 1 ;
V_52 -> V_29 = V_29 ;
if ( V_29 == V_60 )
V_52 -> V_61 = V_7 -> V_62 ;
else if ( ( V_29 == V_63 ) || ! V_29 ) {
V_54 = F_19 ( & V_7 -> V_64 ) ;
V_52 -> V_61 = V_54 ;
if ( V_54 )
V_52 -> V_29 = V_52 -> V_29 | V_63 ;
}
memcpy ( V_52 -> V_65 , V_7 -> V_66 , 8 ) ;
memcpy ( V_52 -> V_67 , V_7 -> V_68 , 8 ) ;
memcpy ( V_52 -> V_69 , V_7 -> V_70 , 8 ) ;
memcpy ( V_52 -> V_71 , V_7 -> V_72 , 8 ) ;
F_31 ( V_52 -> V_65 , sizeof( V_52 -> V_65 ) ) ;
F_31 ( V_52 -> V_67 , sizeof( V_52 -> V_67 ) ) ;
F_31 ( V_52 -> V_69 , sizeof( V_52 -> V_69 ) ) ;
F_31 ( V_52 -> V_71 , sizeof( V_52 -> V_71 ) ) ;
if ( V_48 )
memcpy ( & V_52 -> V_73 , V_48 , sizeof( struct V_26 ) ) ;
V_50 -> V_4 = V_7 -> V_74 ;
if ( ! V_50 -> V_4 )
return - V_75 ;
if ( ! ( V_50 -> V_4 -> V_29 & V_76 ) || ! F_32 ( V_50 -> V_4 ) )
return - V_77 ;
if ( V_50 -> V_78 > V_50 -> V_4 -> V_79 ) {
if ( V_8 -> V_80 == V_81 )
return - V_82 ;
else
F_33 ( V_50 , V_50 -> V_4 -> V_79 ) ;
}
V_50 -> V_83 = V_58 ;
V_53 = F_34 ( V_50 , V_84 ) ;
if ( ! V_53 )
return - V_85 ;
F_35 ( & V_7 -> V_21 , V_53 ) ;
V_10 = F_36 ( V_50 ) ;
if ( F_37 ( V_10 ) ) {
F_38 ( V_53 , & V_7 -> V_21 ) ;
F_39 ( V_53 ) ;
} else {
F_40 ( V_54 , & V_7 -> V_64 ) ;
F_41 ( F_19 ( & V_7 -> V_64 ) < 0 ) ;
}
return F_37 ( V_10 ) ;
}
static struct V_8 * F_42 ( char * V_86 )
{
struct V_8 * V_9 ;
F_9 (sk, &iucv_sk_list.head)
if ( ! memcmp ( & F_10 ( V_9 ) -> V_72 , V_86 , 8 ) )
return V_9 ;
return NULL ;
}
static void F_43 ( struct V_8 * V_9 )
{
F_12 ( & V_9 -> V_87 ) ;
F_12 ( & V_9 -> V_88 ) ;
F_44 ( V_9 ) ;
if ( ! F_45 ( V_9 , V_89 ) ) {
F_46 ( L_5 , V_9 ) ;
return;
}
F_41 ( F_19 ( & V_9 -> V_90 ) ) ;
F_41 ( F_19 ( & V_9 -> V_91 ) ) ;
F_41 ( V_9 -> V_92 ) ;
F_41 ( V_9 -> V_93 ) ;
}
static void F_47 ( struct V_8 * V_94 )
{
struct V_8 * V_9 ;
while ( ( V_9 = F_48 ( V_94 , NULL ) ) ) {
F_49 ( V_9 ) ;
F_50 ( V_9 ) ;
}
V_94 -> V_13 = V_20 ;
}
static void F_50 ( struct V_8 * V_9 )
{
if ( ! F_45 ( V_9 , V_95 ) || V_9 -> V_96 )
return;
F_51 ( & V_11 , V_9 ) ;
F_52 ( V_9 , V_89 ) ;
F_53 ( V_9 ) ;
}
static void F_11 ( struct V_8 * V_9 , int V_97 )
{
unsigned char V_98 [ 16 ] ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_99 * V_37 = V_7 -> V_37 ;
if ( V_7 -> V_37 ) {
V_7 -> V_37 = NULL ;
if ( V_97 ) {
F_2 ( V_98 , V_7 -> V_72 ) ;
F_1 ( V_98 , V_7 -> V_68 ) ;
F_31 ( V_98 , sizeof( V_98 ) ) ;
V_100 -> V_101 ( V_37 , V_98 ) ;
} else
V_100 -> V_101 ( V_37 , NULL ) ;
F_54 ( V_37 ) ;
}
}
static int F_55 ( struct V_8 * V_9 , T_2 V_29 )
{
int V_10 = 0 ;
int V_102 ;
struct V_49 * V_50 ;
V_102 = sizeof( struct V_51 ) + V_56 ;
V_50 = F_56 ( V_9 , V_102 , 1 , & V_10 ) ;
if ( V_50 ) {
F_57 ( V_50 , V_102 ) ;
V_10 = F_27 ( NULL , V_9 , V_50 , V_29 ) ;
}
return V_10 ;
}
static void F_49 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
unsigned long V_103 ;
int V_10 = 0 ;
F_58 ( V_9 ) ;
switch ( V_9 -> V_13 ) {
case V_19 :
F_47 ( V_9 ) ;
break;
case V_16 :
if ( V_7 -> V_35 == V_104 ) {
V_10 = F_55 ( V_9 , V_105 ) ;
V_9 -> V_13 = V_14 ;
V_9 -> V_25 ( V_9 ) ;
}
case V_14 :
V_9 -> V_13 = V_15 ;
V_9 -> V_25 ( V_9 ) ;
if ( ! V_10 && ! F_59 ( & V_7 -> V_21 ) ) {
if ( F_45 ( V_9 , V_106 ) && V_9 -> V_107 )
V_103 = V_9 -> V_107 ;
else
V_103 = V_108 ;
F_60 ( V_9 ,
F_16 ( V_9 , V_20 , 0 ) ,
V_103 ) ;
}
case V_15 :
V_9 -> V_13 = V_20 ;
V_9 -> V_25 ( V_9 ) ;
V_9 -> V_23 = V_109 ;
V_9 -> V_25 ( V_9 ) ;
F_12 ( & V_7 -> V_21 ) ;
F_12 ( & V_7 -> V_22 ) ;
default:
F_11 ( V_9 , 1 ) ;
}
if ( V_7 -> V_74 ) {
F_61 ( V_7 -> V_74 ) ;
V_7 -> V_74 = NULL ;
V_9 -> V_110 = 0 ;
}
F_52 ( V_9 , V_95 ) ;
F_62 ( V_9 ) ;
}
static void F_63 ( struct V_8 * V_9 , struct V_8 * V_94 )
{
if ( V_94 )
V_9 -> V_80 = V_94 -> V_80 ;
}
static struct V_8 * F_64 ( struct V_111 * V_8 , int V_112 , T_3 V_113 , int V_114 )
{
struct V_8 * V_9 ;
struct V_6 * V_7 ;
V_9 = F_65 ( & V_115 , V_116 , V_113 , & V_117 , V_114 ) ;
if ( ! V_9 )
return NULL ;
V_7 = F_10 ( V_9 ) ;
F_66 ( V_8 , V_9 ) ;
F_67 ( & V_7 -> V_118 ) ;
F_68 ( & V_7 -> V_119 ) ;
F_69 ( & V_7 -> V_21 ) ;
F_67 ( & V_7 -> V_120 . V_121 ) ;
F_68 ( & V_7 -> V_120 . V_12 ) ;
F_69 ( & V_7 -> V_22 ) ;
V_7 -> V_122 = 0 ;
F_70 ( & V_7 -> V_41 , 0 ) ;
V_7 -> V_29 = 0 ;
V_7 -> V_62 = 0 ;
F_70 ( & V_7 -> V_39 , 0 ) ;
F_70 ( & V_7 -> V_64 , 0 ) ;
V_7 -> V_37 = NULL ;
V_7 -> V_123 = V_124 ;
memset ( & V_7 -> V_70 , 0 , 32 ) ;
if ( V_100 )
V_7 -> V_35 = V_36 ;
else
V_7 -> V_35 = V_104 ;
V_9 -> V_125 = F_43 ;
V_9 -> V_126 = V_127 ;
V_9 -> V_128 = V_129 ;
F_71 ( V_9 , V_95 ) ;
V_9 -> V_130 = V_112 ;
V_9 -> V_13 = V_17 ;
F_72 ( & V_11 , V_9 ) ;
return V_9 ;
}
static int F_73 ( struct V_131 * V_131 , struct V_111 * V_8 , int V_83 ,
int V_114 )
{
struct V_8 * V_9 ;
if ( V_83 && V_83 != V_116 )
return - V_132 ;
V_8 -> V_33 = V_133 ;
switch ( V_8 -> type ) {
case V_134 :
V_8 -> V_135 = & V_136 ;
break;
case V_81 :
V_8 -> V_135 = & V_136 ;
break;
default:
return - V_137 ;
}
V_9 = F_64 ( V_8 , V_83 , V_138 , V_114 ) ;
if ( ! V_9 )
return - V_85 ;
F_63 ( V_9 , NULL ) ;
return 0 ;
}
void F_72 ( struct V_139 * V_140 , struct V_8 * V_9 )
{
F_74 ( & V_140 -> V_12 ) ;
F_75 ( V_9 , & V_140 -> V_55 ) ;
F_76 ( & V_140 -> V_12 ) ;
}
void F_51 ( struct V_139 * V_140 , struct V_8 * V_9 )
{
F_74 ( & V_140 -> V_12 ) ;
F_77 ( V_9 ) ;
F_76 ( & V_140 -> V_12 ) ;
}
void F_78 ( struct V_8 * V_94 , struct V_8 * V_9 )
{
unsigned long V_29 ;
struct V_6 * V_141 = F_10 ( V_94 ) ;
F_79 ( V_9 ) ;
F_80 ( & V_141 -> V_119 , V_29 ) ;
F_81 ( & F_10 ( V_9 ) -> V_118 , & V_141 -> V_118 ) ;
F_82 ( & V_141 -> V_119 , V_29 ) ;
F_10 ( V_9 ) -> V_94 = V_94 ;
F_83 ( V_94 ) ;
}
void F_84 ( struct V_8 * V_9 )
{
unsigned long V_29 ;
struct V_6 * V_141 = F_10 ( F_10 ( V_9 ) -> V_94 ) ;
F_80 ( & V_141 -> V_119 , V_29 ) ;
F_85 ( & F_10 ( V_9 ) -> V_118 ) ;
F_82 ( & V_141 -> V_119 , V_29 ) ;
F_86 ( F_10 ( V_9 ) -> V_94 ) ;
F_10 ( V_9 ) -> V_94 = NULL ;
F_53 ( V_9 ) ;
}
struct V_8 * F_48 ( struct V_8 * V_94 , struct V_111 * V_142 )
{
struct V_6 * V_143 , * V_144 ;
struct V_8 * V_9 ;
F_87 (isk, n, &iucv_sk(parent)->accept_q, accept_q) {
V_9 = (struct V_8 * ) V_143 ;
F_58 ( V_9 ) ;
if ( V_9 -> V_13 == V_20 ) {
F_84 ( V_9 ) ;
F_62 ( V_9 ) ;
continue;
}
if ( V_9 -> V_13 == V_16 ||
V_9 -> V_13 == V_14 ||
! V_142 ) {
F_84 ( V_9 ) ;
if ( V_142 )
F_88 ( V_9 , V_142 ) ;
F_62 ( V_9 ) ;
return V_9 ;
}
F_62 ( V_9 ) ;
}
return NULL ;
}
static void F_89 ( struct V_6 * V_7 )
{
char V_145 [ 12 ] ;
sprintf ( V_145 , L_6 , F_90 ( & V_11 . V_146 ) ) ;
while ( F_42 ( V_145 ) ) {
sprintf ( V_145 , L_6 ,
F_90 ( & V_11 . V_146 ) ) ;
}
memcpy ( V_7 -> V_72 , V_145 , 8 ) ;
}
static int F_91 ( struct V_111 * V_8 , struct V_147 * V_148 ,
int V_149 )
{
struct V_150 * V_151 = (struct V_150 * ) V_148 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 ;
int V_10 = 0 ;
struct V_152 * V_4 ;
char V_153 [ 9 ] ;
if ( ! V_148 || V_148 -> V_154 != V_155 )
return - V_156 ;
F_58 ( V_9 ) ;
if ( V_9 -> V_13 != V_17 ) {
V_10 = - V_157 ;
goto V_158;
}
F_74 ( & V_11 . V_12 ) ;
V_7 = F_10 ( V_9 ) ;
if ( F_42 ( V_151 -> V_159 ) ) {
V_10 = - V_160 ;
goto V_161;
}
if ( V_7 -> V_37 )
goto V_161;
if ( V_100 )
if ( ! memcmp ( V_151 -> V_162 , V_163 , 8 ) )
goto V_164;
memcpy ( V_153 , V_151 -> V_162 , sizeof( V_153 ) ) ;
F_31 ( V_153 , 8 ) ;
F_21 () ;
F_92 (&init_net, dev) {
if ( ! memcmp ( V_4 -> V_165 , V_153 , 8 ) ) {
memcpy ( V_7 -> V_70 , V_151 -> V_162 , 8 ) ;
if ( strncmp ( V_151 -> V_159 , L_7 , 8 ) == 0 )
F_89 ( V_7 ) ;
else
memcpy ( V_7 -> V_72 , V_151 -> V_159 , 8 ) ;
V_9 -> V_110 = V_4 -> V_166 ;
V_7 -> V_74 = V_4 ;
F_93 ( V_4 ) ;
V_9 -> V_13 = V_18 ;
V_7 -> V_35 = V_104 ;
if ( ! V_7 -> V_62 )
V_7 -> V_62 = V_167 ;
F_26 () ;
goto V_161;
}
}
F_26 () ;
V_164:
if ( V_100 ) {
memcpy ( V_7 -> V_72 , V_151 -> V_159 , 8 ) ;
memcpy ( V_7 -> V_70 , V_163 , 8 ) ;
V_9 -> V_13 = V_18 ;
V_7 -> V_35 = V_36 ;
if ( ! V_7 -> V_62 )
V_7 -> V_62 = V_168 ;
goto V_161;
}
V_10 = - V_75 ;
V_161:
F_76 ( & V_11 . V_12 ) ;
V_158:
F_62 ( V_9 ) ;
return V_10 ;
}
static int F_94 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
int V_10 = 0 ;
if ( F_95 ( ! V_100 ) )
return - V_169 ;
memcpy ( V_7 -> V_70 , V_163 , 8 ) ;
F_74 ( & V_11 . V_12 ) ;
F_89 ( V_7 ) ;
F_76 ( & V_11 . V_12 ) ;
if ( ! V_7 -> V_62 )
V_7 -> V_62 = V_168 ;
return V_10 ;
}
static int F_96 ( struct V_111 * V_8 , struct V_147 * V_148 )
{
struct V_150 * V_151 = (struct V_150 * ) V_148 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
unsigned char V_98 [ 16 ] ;
int V_10 ;
F_1 ( V_98 , V_151 -> V_159 ) ;
F_2 ( V_98 , V_7 -> V_72 ) ;
F_31 ( V_98 , sizeof( V_98 ) ) ;
V_7 -> V_37 = F_97 ( V_7 -> V_62 ,
V_30 , V_138 ) ;
if ( ! V_7 -> V_37 ) {
V_10 = - V_85 ;
goto V_158;
}
V_10 = V_100 -> V_170 ( V_7 -> V_37 , & V_171 ,
V_151 -> V_162 , NULL , V_98 ,
V_9 ) ;
if ( V_10 ) {
F_54 ( V_7 -> V_37 ) ;
V_7 -> V_37 = NULL ;
switch ( V_10 ) {
case 0x0b :
V_10 = - V_172 ;
break;
case 0x0d :
case 0x0e :
V_10 = - V_173 ;
break;
case 0x0f :
V_10 = - V_174 ;
break;
default:
V_10 = - V_175 ;
break;
}
}
V_158:
return V_10 ;
}
static int F_98 ( struct V_111 * V_8 , struct V_147 * V_148 ,
int V_176 , int V_29 )
{
struct V_150 * V_151 = (struct V_150 * ) V_148 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
int V_10 ;
if ( V_148 -> V_154 != V_155 || V_176 < sizeof( struct V_150 ) )
return - V_156 ;
if ( V_9 -> V_13 != V_17 && V_9 -> V_13 != V_18 )
return - V_157 ;
if ( V_9 -> V_13 == V_17 &&
V_7 -> V_35 == V_104 )
return - V_157 ;
if ( V_9 -> V_80 != V_134 && V_9 -> V_80 != V_81 )
return - V_156 ;
if ( V_9 -> V_13 == V_17 ) {
V_10 = F_94 ( V_9 ) ;
if ( F_95 ( V_10 ) )
return V_10 ;
}
F_58 ( V_9 ) ;
memcpy ( V_7 -> V_66 , V_151 -> V_162 , 8 ) ;
memcpy ( V_7 -> V_68 , V_151 -> V_159 , 8 ) ;
if ( V_7 -> V_35 == V_104 )
V_10 = F_55 ( V_8 -> V_9 , V_60 ) ;
else
V_10 = F_96 ( V_8 , V_148 ) ;
if ( V_10 )
goto V_158;
if ( V_9 -> V_13 != V_16 )
V_10 = F_60 ( V_9 , F_16 ( V_9 , V_16 ,
V_14 ) ,
F_99 ( V_9 , V_29 & V_177 ) ) ;
if ( V_9 -> V_13 == V_14 || V_9 -> V_13 == V_20 )
V_10 = - V_175 ;
if ( V_10 && V_7 -> V_35 == V_36 )
F_11 ( V_9 , 0 ) ;
V_158:
F_62 ( V_9 ) ;
return V_10 ;
}
static int F_100 ( struct V_111 * V_8 , int V_178 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
int V_10 ;
F_58 ( V_9 ) ;
V_10 = - V_156 ;
if ( V_9 -> V_13 != V_18 )
goto V_158;
if ( V_8 -> type != V_134 && V_8 -> type != V_81 )
goto V_158;
V_9 -> V_179 = V_178 ;
V_9 -> V_180 = 0 ;
V_9 -> V_13 = V_19 ;
V_10 = 0 ;
V_158:
F_62 ( V_9 ) ;
return V_10 ;
}
static int F_101 ( struct V_111 * V_8 , struct V_111 * V_142 ,
int V_29 )
{
F_102 ( V_45 , V_181 ) ;
struct V_8 * V_9 = V_8 -> V_9 , * V_182 ;
long V_103 ;
int V_10 = 0 ;
F_103 ( V_9 , V_183 ) ;
if ( V_9 -> V_13 != V_19 ) {
V_10 = - V_157 ;
goto V_158;
}
V_103 = F_104 ( V_9 , V_29 & V_177 ) ;
F_105 ( F_106 ( V_9 ) , & V_45 ) ;
while ( ! ( V_182 = F_48 ( V_9 , V_142 ) ) ) {
F_107 ( V_184 ) ;
if ( ! V_103 ) {
V_10 = - V_173 ;
break;
}
F_62 ( V_9 ) ;
V_103 = F_108 ( V_103 ) ;
F_103 ( V_9 , V_183 ) ;
if ( V_9 -> V_13 != V_19 ) {
V_10 = - V_157 ;
break;
}
if ( F_109 ( V_181 ) ) {
V_10 = F_110 ( V_103 ) ;
break;
}
}
F_107 ( V_185 ) ;
F_111 ( F_106 ( V_9 ) , & V_45 ) ;
if ( V_10 )
goto V_158;
V_142 -> V_33 = V_186 ;
V_158:
F_62 ( V_9 ) ;
return V_10 ;
}
static int F_112 ( struct V_111 * V_8 , struct V_147 * V_148 ,
int * V_78 , int V_187 )
{
struct V_150 * V_188 = (struct V_150 * ) V_148 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
V_148 -> V_154 = V_155 ;
* V_78 = sizeof( struct V_150 ) ;
if ( V_187 ) {
memcpy ( V_188 -> V_162 , V_7 -> V_66 , 8 ) ;
memcpy ( V_188 -> V_159 , V_7 -> V_68 , 8 ) ;
} else {
memcpy ( V_188 -> V_162 , V_7 -> V_70 , 8 ) ;
memcpy ( V_188 -> V_159 , V_7 -> V_72 , 8 ) ;
}
memset ( & V_188 -> V_189 , 0 , sizeof( V_188 -> V_189 ) ) ;
memset ( & V_188 -> V_190 , 0 , sizeof( V_188 -> V_190 ) ) ;
memset ( & V_188 -> V_191 , 0 , sizeof( V_188 -> V_191 ) ) ;
return 0 ;
}
static int F_113 ( struct V_99 * V_37 , struct V_26 * V_27 ,
struct V_49 * V_50 )
{
T_2 V_192 [ 8 ] ;
memcpy ( V_192 , ( void * ) V_50 -> V_193 , V_50 -> V_78 ) ;
V_192 [ 7 ] = 0xff - ( T_2 ) V_50 -> V_78 ;
return V_100 -> V_194 ( V_37 , V_27 , V_30 , 0 ,
( void * ) V_192 , 8 ) ;
}
static int F_114 ( struct V_111 * V_8 , struct V_195 * V_27 ,
T_1 V_78 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_49 * V_50 ;
struct V_26 V_196 ;
struct V_197 * V_198 ;
int V_199 ;
long V_103 ;
char V_200 [ 9 ] ;
char V_201 [ 9 ] ;
int V_10 ;
int V_202 = V_27 -> V_203 & V_204 ;
V_10 = F_115 ( V_9 ) ;
if ( V_10 )
return V_10 ;
if ( V_27 -> V_203 & V_205 )
return - V_206 ;
if ( V_9 -> V_80 == V_81 && ! ( V_27 -> V_203 & V_207 ) )
return - V_206 ;
F_58 ( V_9 ) ;
if ( V_9 -> V_208 & V_209 ) {
V_10 = - V_24 ;
goto V_210;
}
if ( V_9 -> V_13 != V_16 ) {
V_10 = - V_211 ;
goto V_210;
}
V_199 = 0 ;
V_196 . V_212 = 0 ;
F_116 (cmsg, msg) {
if ( ! F_117 ( V_27 , V_198 ) ) {
V_10 = - V_156 ;
goto V_210;
}
if ( V_198 -> V_213 != V_214 )
continue;
if ( V_198 -> V_215 & V_199 ) {
V_10 = - V_156 ;
goto V_210;
}
V_199 |= V_198 -> V_215 ;
switch ( V_198 -> V_215 ) {
case V_216 :
if ( V_198 -> V_217 != F_118 ( V_218 ) ) {
V_10 = - V_156 ;
goto V_210;
}
memcpy ( & V_196 . V_212 ,
( void * ) F_119 ( V_198 ) , V_218 ) ;
break;
default:
V_10 = - V_156 ;
goto V_210;
}
}
if ( V_7 -> V_35 == V_104 )
V_50 = F_56 ( V_9 ,
V_78 + sizeof( struct V_51 ) + V_56 ,
V_202 , & V_10 ) ;
else
V_50 = F_56 ( V_9 , V_78 , V_202 , & V_10 ) ;
if ( ! V_50 )
goto V_210;
if ( V_7 -> V_35 == V_104 )
F_57 ( V_50 , sizeof( struct V_51 ) + V_56 ) ;
if ( F_120 ( F_121 ( V_50 , V_78 ) , V_27 , V_78 ) ) {
V_10 = - V_219 ;
goto V_220;
}
V_103 = F_99 ( V_9 , V_202 ) ;
V_10 = F_60 ( V_9 , F_17 ( V_9 ) , V_103 ) ;
if ( V_10 )
goto V_220;
if ( V_9 -> V_13 != V_16 ) {
V_10 = - V_109 ;
goto V_220;
}
V_196 . V_221 = V_7 -> V_122 ++ ;
F_122 ( V_50 ) -> V_221 = V_196 . V_221 ;
if ( V_7 -> V_35 == V_104 ) {
F_123 ( & V_7 -> V_39 ) ;
V_10 = F_27 ( & V_196 , V_9 , V_50 , 0 ) ;
if ( V_10 ) {
F_124 ( & V_7 -> V_39 ) ;
goto V_220;
}
goto V_222;
}
F_35 ( & V_7 -> V_21 , V_50 ) ;
if ( ( ( V_7 -> V_37 -> V_29 & V_30 ) & V_7 -> V_29 )
&& V_50 -> V_78 <= 7 ) {
V_10 = F_113 ( V_7 -> V_37 , & V_196 , V_50 ) ;
if ( V_10 == 0 ) {
F_38 ( V_50 , & V_7 -> V_21 ) ;
F_39 ( V_50 ) ;
}
if ( V_10 == 0x15 ) {
V_100 -> V_101 ( V_7 -> V_37 , NULL ) ;
F_38 ( V_50 , & V_7 -> V_21 ) ;
V_10 = - V_24 ;
goto V_220;
}
} else
V_10 = V_100 -> V_194 ( V_7 -> V_37 , & V_196 , 0 , 0 ,
( void * ) V_50 -> V_193 , V_50 -> V_78 ) ;
if ( V_10 ) {
if ( V_10 == 3 ) {
V_200 [ 8 ] = 0 ;
memcpy ( V_200 , V_7 -> V_66 , 8 ) ;
V_201 [ 8 ] = 0 ;
memcpy ( V_201 , V_7 -> V_68 , 8 ) ;
F_46 ( L_8
L_9 ,
V_201 , V_200 ) ;
V_10 = - V_173 ;
} else
V_10 = - V_24 ;
F_38 ( V_50 , & V_7 -> V_21 ) ;
goto V_220;
}
V_222:
F_62 ( V_9 ) ;
return V_78 ;
V_220:
F_39 ( V_50 ) ;
V_210:
F_62 ( V_9 ) ;
return V_10 ;
}
static int F_125 ( struct V_8 * V_9 , struct V_49 * V_50 , int V_78 )
{
int V_223 , V_224 , V_225 = 0 ;
struct V_49 * V_53 ;
V_223 = V_78 ;
while ( V_223 ) {
if ( V_223 >= V_9 -> V_226 / 4 )
V_224 = V_9 -> V_226 / 4 ;
else
V_224 = V_223 ;
V_53 = F_126 ( V_224 , V_84 | V_129 ) ;
if ( ! V_53 )
return - V_85 ;
F_122 ( V_53 ) -> V_212 = F_122 ( V_50 ) -> V_212 ;
memcpy ( V_53 -> V_193 , V_50 -> V_193 + V_225 , V_224 ) ;
V_225 += V_224 ;
V_223 -= V_224 ;
F_127 ( V_53 ) ;
F_30 ( V_53 ) ;
V_53 -> V_78 = V_224 ;
F_35 ( & F_10 ( V_9 ) -> V_22 , V_53 ) ;
}
return 0 ;
}
static void F_128 ( struct V_8 * V_9 , struct V_49 * V_50 ,
struct V_99 * V_37 ,
struct V_26 * V_27 )
{
int V_227 ;
unsigned int V_78 ;
V_78 = F_15 ( V_27 ) ;
F_122 ( V_50 ) -> V_212 = V_27 -> V_212 ;
if ( ( V_27 -> V_29 & V_30 ) && V_78 > 7 ) {
if ( memcmp ( V_27 -> V_31 , V_228 , 8 ) == 0 ) {
V_50 -> V_193 = NULL ;
V_50 -> V_78 = 0 ;
}
} else {
V_227 = V_100 -> V_229 ( V_37 , V_27 ,
V_27 -> V_29 & V_30 ,
V_50 -> V_193 , V_78 , NULL ) ;
if ( V_227 ) {
F_39 ( V_50 ) ;
return;
}
if ( V_9 -> V_80 == V_134 &&
V_50 -> V_230 >= V_9 -> V_226 / 4 ) {
V_227 = F_125 ( V_9 , V_50 , V_78 ) ;
F_39 ( V_50 ) ;
V_50 = NULL ;
if ( V_227 ) {
V_100 -> V_101 ( V_37 , NULL ) ;
return;
}
V_50 = F_129 ( & F_10 ( V_9 ) -> V_22 ) ;
} else {
F_127 ( V_50 ) ;
F_30 ( V_50 ) ;
V_50 -> V_78 = V_78 ;
}
}
F_122 ( V_50 ) -> V_231 = 0 ;
if ( F_130 ( V_9 , V_50 ) )
F_131 ( & F_10 ( V_9 ) -> V_22 , V_50 ) ;
}
static void F_132 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_49 * V_50 ;
struct V_232 * V_233 , * V_144 ;
F_87 (p, n, &iucv->message_q.list, list) {
V_50 = F_126 ( F_15 ( & V_233 -> V_27 ) , V_84 | V_129 ) ;
if ( ! V_50 )
break;
F_128 ( V_9 , V_50 , V_233 -> V_37 , & V_233 -> V_27 ) ;
F_133 ( & V_233 -> V_121 ) ;
F_134 ( V_233 ) ;
if ( ! F_59 ( & V_7 -> V_22 ) )
break;
}
}
static int F_135 ( struct V_111 * V_8 , struct V_195 * V_27 ,
T_1 V_78 , int V_29 )
{
int V_202 = V_29 & V_204 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
unsigned int V_225 , V_234 ;
struct V_49 * V_50 , * V_235 , * V_236 ;
int V_10 = 0 ;
T_4 V_231 ;
if ( ( V_9 -> V_13 == V_14 ) &&
F_59 ( & V_7 -> V_22 ) &&
F_59 ( & V_9 -> V_87 ) &&
F_136 ( & V_7 -> V_120 . V_121 ) )
return 0 ;
if ( V_29 & ( V_205 ) )
return - V_206 ;
V_50 = F_137 ( V_9 , V_29 , V_202 , & V_10 ) ;
if ( ! V_50 ) {
if ( V_9 -> V_208 & V_237 )
return 0 ;
return V_10 ;
}
V_231 = F_122 ( V_50 ) -> V_231 ;
V_234 = V_50 -> V_78 - V_231 ;
V_225 = F_138 (unsigned int, rlen, len) ;
if ( ! V_234 )
V_9 -> V_208 = V_9 -> V_208 | V_237 ;
V_236 = V_50 ;
if ( F_139 ( V_236 , V_231 , V_27 , V_225 ) ) {
if ( ! ( V_29 & V_238 ) )
F_131 ( & V_9 -> V_87 , V_50 ) ;
return - V_219 ;
}
if ( V_9 -> V_80 == V_81 ) {
if ( V_225 < V_234 )
V_27 -> V_203 |= V_239 ;
V_27 -> V_203 |= V_207 ;
}
V_10 = F_140 ( V_27 , V_214 , V_216 ,
sizeof( F_122 ( V_50 ) -> V_212 ) ,
( void * ) & F_122 ( V_50 ) -> V_212 ) ;
if ( V_10 ) {
if ( ! ( V_29 & V_238 ) )
F_131 ( & V_9 -> V_87 , V_50 ) ;
return V_10 ;
}
if ( ! ( V_29 & V_238 ) ) {
if ( V_9 -> V_80 == V_134 ) {
if ( V_225 < V_234 ) {
F_122 ( V_50 ) -> V_231 = V_231 + V_225 ;
F_131 ( & V_9 -> V_87 , V_50 ) ;
goto V_158;
}
}
F_39 ( V_50 ) ;
if ( V_7 -> V_35 == V_104 ) {
F_123 ( & V_7 -> V_64 ) ;
if ( F_19 ( & V_7 -> V_64 ) > V_7 -> V_62 ) {
F_41 ( 1 ) ;
F_49 ( V_9 ) ;
return - V_219 ;
}
}
F_141 ( & V_7 -> V_120 . V_12 ) ;
V_235 = F_129 ( & V_7 -> V_22 ) ;
while ( V_235 ) {
F_122 ( V_235 ) -> V_231 = 0 ;
if ( F_130 ( V_9 , V_235 ) ) {
F_131 ( & V_7 -> V_22 ,
V_235 ) ;
break;
} else {
V_235 = F_129 ( & V_7 -> V_22 ) ;
}
}
if ( F_59 ( & V_7 -> V_22 ) ) {
if ( ! F_136 ( & V_7 -> V_120 . V_121 ) )
F_132 ( V_9 ) ;
if ( F_19 ( & V_7 -> V_64 ) >=
V_7 -> V_62 / 2 ) {
V_10 = F_55 ( V_9 , V_63 ) ;
if ( V_10 ) {
V_9 -> V_13 = V_14 ;
V_9 -> V_25 ( V_9 ) ;
}
}
}
F_142 ( & V_7 -> V_120 . V_12 ) ;
}
V_158:
if ( V_9 -> V_80 == V_81 && ( V_29 & V_239 ) )
V_225 = V_234 ;
return V_225 ;
}
static inline unsigned int F_143 ( struct V_8 * V_94 )
{
struct V_6 * V_143 , * V_144 ;
struct V_8 * V_9 ;
F_87 (isk, n, &iucv_sk(parent)->accept_q, accept_q) {
V_9 = (struct V_8 * ) V_143 ;
if ( V_9 -> V_13 == V_16 )
return V_240 | V_241 ;
}
return 0 ;
}
unsigned int F_144 ( struct V_242 * V_242 , struct V_111 * V_8 ,
T_5 * V_45 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
unsigned int V_243 = 0 ;
F_145 ( V_242 , F_106 ( V_9 ) , V_45 ) ;
if ( V_9 -> V_13 == V_19 )
return F_143 ( V_9 ) ;
if ( V_9 -> V_23 || ! F_59 ( & V_9 -> V_88 ) )
V_243 |= V_244 |
( F_45 ( V_9 , V_245 ) ? V_246 : 0 ) ;
if ( V_9 -> V_208 & V_237 )
V_243 |= V_247 ;
if ( V_9 -> V_208 == V_248 )
V_243 |= V_249 ;
if ( ! F_59 ( & V_9 -> V_87 ) ||
( V_9 -> V_208 & V_237 ) )
V_243 |= V_240 | V_241 ;
if ( V_9 -> V_13 == V_20 )
V_243 |= V_249 ;
if ( V_9 -> V_13 == V_14 )
V_243 |= V_240 ;
if ( F_146 ( V_9 ) && F_17 ( V_9 ) )
V_243 |= V_250 | V_251 | V_252 ;
else
F_147 ( V_253 , V_9 ) ;
return V_243 ;
}
static int F_148 ( struct V_111 * V_8 , int V_254 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_26 V_196 ;
int V_10 = 0 ;
V_254 ++ ;
if ( ( V_254 & ~ V_248 ) || ! V_254 )
return - V_156 ;
F_58 ( V_9 ) ;
switch ( V_9 -> V_13 ) {
case V_19 :
case V_14 :
case V_15 :
case V_20 :
V_10 = - V_211 ;
goto V_220;
default:
break;
}
if ( V_254 == V_209 || V_254 == V_248 ) {
if ( V_7 -> V_35 == V_36 ) {
V_196 . V_212 = 0 ;
V_196 . V_221 = 0 ;
V_10 = V_100 -> V_194 ( V_7 -> V_37 , & V_196 ,
V_30 , 0 , ( void * ) V_228 , 8 ) ;
if ( V_10 ) {
switch ( V_10 ) {
case 1 :
V_10 = - V_211 ;
break;
case 2 :
V_10 = - V_109 ;
break;
default:
V_10 = - V_211 ;
break;
}
}
} else
F_55 ( V_9 , V_255 ) ;
}
V_9 -> V_208 |= V_254 ;
if ( V_254 == V_237 || V_254 == V_248 ) {
if ( ( V_7 -> V_35 == V_36 ) &&
V_7 -> V_37 ) {
V_10 = V_100 -> V_256 ( V_7 -> V_37 , NULL ) ;
if ( V_10 )
V_10 = - V_211 ;
}
F_12 ( & V_9 -> V_87 ) ;
}
V_9 -> V_25 ( V_9 ) ;
V_220:
F_62 ( V_9 ) ;
return V_10 ;
}
static int F_149 ( struct V_111 * V_8 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
int V_10 = 0 ;
if ( ! V_9 )
return 0 ;
F_49 ( V_9 ) ;
F_150 ( V_9 ) ;
F_50 ( V_9 ) ;
return V_10 ;
}
static int F_151 ( struct V_111 * V_8 , int V_257 , int V_258 ,
char T_6 * V_259 , unsigned int V_260 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
int V_261 ;
int V_227 ;
if ( V_257 != V_214 )
return - V_262 ;
if ( V_260 < sizeof( int ) )
return - V_156 ;
if ( F_152 ( V_261 , ( int T_6 * ) V_259 ) )
return - V_219 ;
V_227 = 0 ;
F_58 ( V_9 ) ;
switch ( V_258 ) {
case V_263 :
if ( V_261 )
V_7 -> V_29 |= V_30 ;
else
V_7 -> V_29 &= ~ V_30 ;
break;
case V_264 :
switch ( V_9 -> V_13 ) {
case V_17 :
case V_18 :
if ( V_261 < 1 || V_261 > ( V_265 ) ( ~ 0 ) )
V_227 = - V_156 ;
else
V_7 -> V_62 = V_261 ;
break;
default:
V_227 = - V_156 ;
break;
}
break;
default:
V_227 = - V_262 ;
break;
}
F_62 ( V_9 ) ;
return V_227 ;
}
static int F_153 ( struct V_111 * V_8 , int V_257 , int V_258 ,
char T_6 * V_259 , int T_6 * V_260 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
unsigned int V_261 ;
int V_78 ;
if ( V_257 != V_214 )
return - V_262 ;
if ( F_152 ( V_78 , V_260 ) )
return - V_219 ;
if ( V_78 < 0 )
return - V_156 ;
V_78 = F_138 (unsigned int, len, sizeof(int)) ;
switch ( V_258 ) {
case V_263 :
V_261 = ( V_7 -> V_29 & V_30 ) ? 1 : 0 ;
break;
case V_264 :
F_58 ( V_9 ) ;
V_261 = ( V_7 -> V_37 != NULL ) ? V_7 -> V_37 -> V_38
: V_7 -> V_62 ;
F_62 ( V_9 ) ;
break;
case V_266 :
if ( V_9 -> V_13 == V_17 )
return - V_157 ;
V_261 = ( V_7 -> V_74 ) ? V_7 -> V_74 -> V_79 -
sizeof( struct V_51 ) - V_56 :
0x7fffffff ;
break;
default:
return - V_262 ;
}
if ( F_154 ( V_78 , V_260 ) )
return - V_219 ;
if ( F_155 ( V_259 , & V_261 , V_78 ) )
return - V_219 ;
return 0 ;
}
static int F_156 ( struct V_99 * V_37 ,
T_2 V_267 [ 8 ] , T_2 V_268 [ 16 ] )
{
unsigned char V_98 [ 16 ] ;
unsigned char V_269 [ 16 ] ;
unsigned char V_72 [ 8 ] ;
struct V_8 * V_9 , * V_182 ;
struct V_6 * V_7 , * V_270 ;
int V_10 ;
memcpy ( V_72 , V_268 , 8 ) ;
F_157 ( V_72 , 8 ) ;
F_8 ( & V_11 . V_12 ) ;
V_7 = NULL ;
V_9 = NULL ;
F_9 (sk, &iucv_sk_list.head)
if ( V_9 -> V_13 == V_19 &&
! memcmp ( & F_10 ( V_9 ) -> V_72 , V_72 , 8 ) ) {
V_7 = F_10 ( V_9 ) ;
break;
}
F_13 ( & V_11 . V_12 ) ;
if ( ! V_7 )
return - V_156 ;
F_158 ( V_9 ) ;
F_2 ( V_98 , V_7 -> V_72 ) ;
F_1 ( V_98 , V_7 -> V_68 ) ;
F_31 ( V_98 , sizeof( V_98 ) ) ;
if ( V_9 -> V_13 != V_19 ) {
V_10 = V_100 -> V_101 ( V_37 , V_98 ) ;
F_54 ( V_37 ) ;
goto V_220;
}
if ( F_159 ( V_9 ) ) {
V_10 = V_100 -> V_101 ( V_37 , V_98 ) ;
F_54 ( V_37 ) ;
goto V_220;
}
V_182 = F_64 ( NULL , V_9 -> V_80 , V_84 , 0 ) ;
if ( ! V_182 ) {
V_10 = V_100 -> V_101 ( V_37 , V_98 ) ;
F_54 ( V_37 ) ;
goto V_220;
}
V_270 = F_10 ( V_182 ) ;
F_63 ( V_182 , V_9 ) ;
memcpy ( V_270 -> V_68 , V_268 + 8 , 8 ) ;
F_157 ( V_270 -> V_68 , 8 ) ;
memcpy ( V_270 -> V_66 , V_267 , 8 ) ;
memcpy ( V_270 -> V_72 , V_7 -> V_72 , 8 ) ;
memcpy ( V_270 -> V_70 , V_7 -> V_70 , 8 ) ;
V_270 -> V_37 = V_37 ;
F_1 ( V_269 , V_268 + 8 ) ;
memcpy ( V_269 + 8 , V_270 -> V_72 , 8 ) ;
F_31 ( V_269 + 8 , 8 ) ;
V_270 -> V_62 = V_7 -> V_62 ;
V_37 -> V_38 = V_7 -> V_62 ;
V_10 = V_100 -> V_271 ( V_37 , & V_171 , V_269 , V_182 ) ;
if ( V_10 ) {
F_11 ( V_182 , 1 ) ;
F_50 ( V_182 ) ;
goto V_220;
}
F_78 ( V_9 , V_182 ) ;
V_182 -> V_13 = V_16 ;
V_9 -> V_272 ( V_9 ) ;
V_10 = 0 ;
V_220:
F_160 ( V_9 ) ;
return 0 ;
}
static void F_161 ( struct V_99 * V_37 , T_2 V_268 [ 16 ] )
{
struct V_8 * V_9 = V_37 -> V_273 ;
V_9 -> V_13 = V_16 ;
V_9 -> V_25 ( V_9 ) ;
}
static void F_162 ( struct V_99 * V_37 , struct V_26 * V_27 )
{
struct V_8 * V_9 = V_37 -> V_273 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_49 * V_50 ;
struct V_232 * V_274 ;
int V_78 ;
if ( V_9 -> V_208 & V_237 ) {
V_100 -> V_275 ( V_37 , V_27 ) ;
return;
}
F_163 ( & V_7 -> V_120 . V_12 ) ;
if ( ! F_136 ( & V_7 -> V_120 . V_121 ) ||
! F_59 ( & V_7 -> V_22 ) )
goto V_276;
V_78 = F_19 ( & V_9 -> V_90 ) ;
V_78 += F_164 ( F_15 ( V_27 ) ) ;
if ( V_78 > V_9 -> V_226 )
goto V_276;
V_50 = F_126 ( F_15 ( V_27 ) , V_84 | V_129 ) ;
if ( ! V_50 )
goto V_276;
F_128 ( V_9 , V_50 , V_37 , V_27 ) ;
goto V_277;
V_276:
V_274 = F_165 ( sizeof( struct V_232 ) , V_84 | V_129 ) ;
if ( ! V_274 )
goto V_277;
V_274 -> V_37 = V_37 ;
V_274 -> V_27 = * V_27 ;
F_81 ( & V_274 -> V_121 , & V_7 -> V_120 . V_121 ) ;
V_277:
F_166 ( & V_7 -> V_120 . V_12 ) ;
}
static void F_167 ( struct V_99 * V_37 ,
struct V_26 * V_27 )
{
struct V_8 * V_9 = V_37 -> V_273 ;
struct V_49 * V_278 = NULL ;
struct V_279 * V_121 = & F_10 ( V_9 ) -> V_21 ;
struct V_49 * V_280 = V_121 -> V_281 ;
unsigned long V_29 ;
F_158 ( V_9 ) ;
if ( ! F_59 ( V_121 ) ) {
F_80 ( & V_121 -> V_12 , V_29 ) ;
while ( V_280 != (struct V_49 * ) V_121 ) {
if ( V_27 -> V_221 == F_122 ( V_280 ) -> V_221 ) {
V_278 = V_280 ;
break;
}
V_280 = V_280 -> V_281 ;
}
if ( V_278 )
F_168 ( V_278 , V_121 ) ;
F_82 ( & V_121 -> V_12 , V_29 ) ;
if ( V_278 ) {
F_39 ( V_278 ) ;
F_20 ( V_9 ) ;
}
}
if ( V_9 -> V_13 == V_15 ) {
if ( F_59 ( & F_10 ( V_9 ) -> V_21 ) ) {
V_9 -> V_13 = V_20 ;
V_9 -> V_25 ( V_9 ) ;
}
}
F_160 ( V_9 ) ;
}
static void F_169 ( struct V_99 * V_37 , T_2 V_268 [ 16 ] )
{
struct V_8 * V_9 = V_37 -> V_273 ;
if ( V_9 -> V_13 == V_20 )
return;
F_158 ( V_9 ) ;
F_11 ( V_9 , 1 ) ;
V_9 -> V_13 = V_14 ;
V_9 -> V_25 ( V_9 ) ;
F_160 ( V_9 ) ;
}
static void F_170 ( struct V_99 * V_37 , T_2 V_268 [ 16 ] )
{
struct V_8 * V_9 = V_37 -> V_273 ;
F_158 ( V_9 ) ;
if ( V_9 -> V_13 != V_20 ) {
V_9 -> V_208 |= V_209 ;
V_9 -> V_25 ( V_9 ) ;
}
F_160 ( V_9 ) ;
}
static void F_171 ( struct V_49 * V_50 )
{
struct V_51 * V_282 =
(struct V_51 * ) V_50 -> V_193 ;
char V_283 [ 8 ] ;
char V_284 [ 8 ] ;
F_31 ( V_282 -> V_65 , sizeof( V_282 -> V_65 ) ) ;
F_31 ( V_282 -> V_67 , sizeof( V_282 -> V_67 ) ) ;
F_31 ( V_282 -> V_69 , sizeof( V_282 -> V_69 ) ) ;
F_31 ( V_282 -> V_71 , sizeof( V_282 -> V_71 ) ) ;
memcpy ( V_283 , V_282 -> V_69 , 8 ) ;
memcpy ( V_284 , V_282 -> V_71 , 8 ) ;
memcpy ( V_282 -> V_69 , V_282 -> V_65 , 8 ) ;
memcpy ( V_282 -> V_71 , V_282 -> V_67 , 8 ) ;
memcpy ( V_282 -> V_65 , V_283 , 8 ) ;
memcpy ( V_282 -> V_67 , V_284 , 8 ) ;
F_28 ( V_50 , V_56 ) ;
memset ( V_50 -> V_193 , 0 , V_56 ) ;
}
static int F_172 ( struct V_8 * V_9 , struct V_49 * V_50 )
{
struct V_8 * V_182 ;
struct V_6 * V_7 , * V_270 ;
struct V_51 * V_282 ;
int V_10 ;
V_7 = F_10 ( V_9 ) ;
V_282 = (struct V_51 * ) V_50 -> V_193 ;
if ( ! V_7 ) {
F_171 ( V_50 ) ;
V_282 -> V_29 = V_60 | V_105 ;
V_10 = F_36 ( V_50 ) ;
goto V_210;
}
V_182 = F_64 ( NULL , V_9 -> V_80 , V_84 , 0 ) ;
F_158 ( V_9 ) ;
if ( ( V_9 -> V_13 != V_19 ) ||
F_159 ( V_9 ) ||
! V_182 ) {
F_171 ( V_50 ) ;
V_282 -> V_29 = V_60 | V_105 ;
V_10 = F_36 ( V_50 ) ;
F_50 ( V_182 ) ;
F_160 ( V_9 ) ;
goto V_210;
}
V_270 = F_10 ( V_182 ) ;
F_63 ( V_182 , V_9 ) ;
V_270 -> V_35 = V_104 ;
V_270 -> V_62 = V_7 -> V_62 ;
if ( ! V_282 -> V_61 )
V_270 -> V_40 = V_167 ;
else
V_270 -> V_40 = V_282 -> V_61 ;
memcpy ( V_270 -> V_68 , V_282 -> V_71 , 8 ) ;
memcpy ( V_270 -> V_66 , V_282 -> V_69 , 8 ) ;
memcpy ( V_270 -> V_72 , V_7 -> V_72 , 8 ) ;
memcpy ( V_270 -> V_70 , V_7 -> V_70 , 8 ) ;
V_182 -> V_110 = V_9 -> V_110 ;
V_270 -> V_74 = V_7 -> V_74 ;
F_93 ( V_270 -> V_74 ) ;
F_171 ( V_50 ) ;
V_282 -> V_29 = V_60 | V_285 ;
V_282 -> V_61 = V_270 -> V_62 ;
V_10 = F_36 ( V_50 ) ;
if ( ! V_10 ) {
F_78 ( V_9 , V_182 ) ;
V_182 -> V_13 = V_16 ;
V_9 -> V_272 ( V_9 ) ;
} else
F_50 ( V_182 ) ;
F_160 ( V_9 ) ;
V_210:
return V_286 ;
}
static int F_173 ( struct V_8 * V_9 , struct V_49 * V_50 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_51 * V_282 =
(struct V_51 * ) V_50 -> V_193 ;
if ( ! V_7 )
goto V_210;
if ( V_9 -> V_13 != V_18 )
goto V_210;
F_158 ( V_9 ) ;
V_7 -> V_40 = V_282 -> V_61 ;
V_9 -> V_13 = V_16 ;
V_9 -> V_25 ( V_9 ) ;
F_160 ( V_9 ) ;
V_210:
F_39 ( V_50 ) ;
return V_286 ;
}
static int F_174 ( struct V_8 * V_9 , struct V_49 * V_50 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
if ( ! V_7 )
goto V_210;
if ( V_9 -> V_13 != V_18 )
goto V_210;
F_158 ( V_9 ) ;
V_9 -> V_13 = V_14 ;
V_9 -> V_25 ( V_9 ) ;
F_160 ( V_9 ) ;
V_210:
F_39 ( V_50 ) ;
return V_286 ;
}
static int F_175 ( struct V_8 * V_9 , struct V_49 * V_50 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
if ( ! V_7 )
goto V_210;
F_158 ( V_9 ) ;
if ( V_9 -> V_13 == V_16 ) {
V_9 -> V_13 = V_14 ;
V_9 -> V_25 ( V_9 ) ;
}
F_160 ( V_9 ) ;
V_210:
F_39 ( V_50 ) ;
return V_286 ;
}
static int F_176 ( struct V_8 * V_9 , struct V_49 * V_50 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_51 * V_282 =
(struct V_51 * ) V_50 -> V_193 ;
if ( ! V_7 )
return V_286 ;
if ( V_9 -> V_13 != V_16 )
return V_286 ;
F_40 ( V_282 -> V_61 , & V_7 -> V_39 ) ;
F_20 ( V_9 ) ;
return V_286 ;
}
static int F_177 ( struct V_8 * V_9 , struct V_49 * V_50 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
if ( ! V_7 ) {
F_39 ( V_50 ) ;
return V_286 ;
}
if ( V_9 -> V_13 != V_16 ) {
F_39 ( V_50 ) ;
return V_286 ;
}
if ( V_9 -> V_208 & V_237 ) {
F_39 ( V_50 ) ;
return V_286 ;
}
if ( V_50 -> V_78 < sizeof( struct V_51 ) ) {
F_39 ( V_50 ) ;
return V_286 ;
}
F_178 ( V_50 , sizeof( struct V_51 ) ) ;
F_127 ( V_50 ) ;
F_30 ( V_50 ) ;
F_122 ( V_50 ) -> V_231 = 0 ;
F_163 ( & V_7 -> V_120 . V_12 ) ;
if ( F_59 ( & V_7 -> V_22 ) ) {
if ( F_130 ( V_9 , V_50 ) ) {
F_35 ( & V_7 -> V_22 , V_50 ) ;
}
} else
F_35 ( & F_10 ( V_9 ) -> V_22 , V_50 ) ;
F_166 ( & V_7 -> V_120 . V_12 ) ;
return V_286 ;
}
static int F_179 ( struct V_49 * V_50 , struct V_152 * V_4 ,
struct V_287 * V_288 , struct V_152 * V_289 )
{
struct V_8 * V_9 ;
struct V_6 * V_7 ;
struct V_51 * V_282 ;
char V_290 [ 8 ] ;
int V_10 = 0 ;
F_178 ( V_50 , V_56 ) ;
V_282 = (struct V_51 * ) V_50 -> V_193 ;
F_157 ( V_282 -> V_67 , sizeof( V_282 -> V_67 ) ) ;
F_157 ( V_282 -> V_65 , sizeof( V_282 -> V_65 ) ) ;
F_157 ( V_282 -> V_71 , sizeof( V_282 -> V_71 ) ) ;
F_157 ( V_282 -> V_69 , sizeof( V_282 -> V_69 ) ) ;
memset ( V_290 , 0 , sizeof( V_290 ) ) ;
V_7 = NULL ;
V_9 = NULL ;
F_8 ( & V_11 . V_12 ) ;
F_9 (sk, &iucv_sk_list.head) {
if ( V_282 -> V_29 == V_60 ) {
if ( ( ! memcmp ( & F_10 ( V_9 ) -> V_72 ,
V_282 -> V_67 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_70 ,
V_282 -> V_65 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_68 , V_290 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_66 ,
V_290 , 8 ) ) ) {
V_7 = F_10 ( V_9 ) ;
break;
}
} else {
if ( ( ! memcmp ( & F_10 ( V_9 ) -> V_72 ,
V_282 -> V_67 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_70 ,
V_282 -> V_65 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_68 ,
V_282 -> V_71 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_66 ,
V_282 -> V_69 , 8 ) ) ) {
V_7 = F_10 ( V_9 ) ;
break;
}
}
}
F_13 ( & V_11 . V_12 ) ;
if ( ! V_7 )
V_9 = NULL ;
switch ( V_282 -> V_29 ) {
case V_60 :
V_10 = F_172 ( V_9 , V_50 ) ;
break;
case ( V_60 | V_285 ) :
V_10 = F_173 ( V_9 , V_50 ) ;
break;
case ( V_60 | V_105 ) :
V_10 = F_174 ( V_9 , V_50 ) ;
break;
case ( V_105 ) :
V_10 = F_175 ( V_9 , V_50 ) ;
break;
case ( V_63 ) :
V_10 = F_176 ( V_9 , V_50 ) ;
if ( V_50 -> V_78 == sizeof( struct V_51 ) ) {
F_39 ( V_50 ) ;
break;
}
case ( V_255 ) :
case 0 :
F_122 ( V_50 ) -> V_212 = V_282 -> V_73 . V_212 ;
V_10 = F_177 ( V_9 , V_50 ) ;
break;
default:
;
}
return V_10 ;
}
static void V_124 ( struct V_49 * V_50 ,
enum V_291 V_144 )
{
struct V_8 * V_143 = V_50 -> V_9 ;
struct V_8 * V_9 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_279 * V_121 ;
struct V_49 * V_280 ;
struct V_49 * V_53 ;
unsigned long V_29 ;
F_180 ( & V_11 . V_12 , V_29 ) ;
F_9 (sk, &iucv_sk_list.head)
if ( V_9 == V_143 ) {
V_7 = F_10 ( V_9 ) ;
break;
}
F_181 ( & V_11 . V_12 , V_29 ) ;
if ( ! V_7 || F_45 ( V_9 , V_95 ) )
return;
V_121 = & V_7 -> V_21 ;
F_80 ( & V_121 -> V_12 , V_29 ) ;
if ( F_59 ( V_121 ) )
goto V_277;
V_280 = V_121 -> V_281 ;
V_53 = V_280 -> V_281 ;
while ( V_280 != (struct V_49 * ) V_121 ) {
if ( F_182 ( V_280 ) == F_182 ( V_50 ) ) {
switch ( V_144 ) {
case V_292 :
F_168 ( V_280 , V_121 ) ;
F_39 ( V_280 ) ;
F_20 ( V_9 ) ;
break;
case V_293 :
F_123 ( & V_7 -> V_41 ) ;
break;
case V_294 :
F_168 ( V_280 , V_121 ) ;
F_124 ( & V_7 -> V_41 ) ;
if ( F_19 ( & V_7 -> V_41 ) <= 0 )
F_20 ( V_9 ) ;
F_39 ( V_280 ) ;
break;
case V_295 :
case V_296 :
case V_297 :
case V_298 :
case V_299 :
F_168 ( V_280 , V_121 ) ;
F_39 ( V_280 ) ;
if ( V_9 -> V_13 == V_16 ) {
V_9 -> V_13 = V_14 ;
V_9 -> V_25 ( V_9 ) ;
}
break;
}
break;
}
V_280 = V_53 ;
V_53 = V_53 -> V_281 ;
}
V_277:
F_82 ( & V_121 -> V_12 , V_29 ) ;
if ( V_9 -> V_13 == V_15 ) {
if ( F_59 ( & F_10 ( V_9 ) -> V_21 ) ) {
V_9 -> V_13 = V_20 ;
V_9 -> V_25 ( V_9 ) ;
}
}
}
static int F_183 ( struct V_300 * V_278 ,
unsigned long V_301 , void * V_302 )
{
struct V_152 * V_303 = F_184 ( V_302 ) ;
struct V_8 * V_9 ;
struct V_6 * V_7 ;
switch ( V_301 ) {
case V_304 :
case V_305 :
F_9 (sk, &iucv_sk_list.head) {
V_7 = F_10 ( V_9 ) ;
if ( ( V_7 -> V_74 == V_303 ) &&
( V_9 -> V_13 == V_16 ) ) {
if ( V_301 == V_305 )
F_55 ( V_9 , V_105 ) ;
V_9 -> V_13 = V_14 ;
V_9 -> V_25 ( V_9 ) ;
}
}
break;
case V_306 :
case V_307 :
default:
break;
}
return V_308 ;
}
static int F_185 ( void )
{
int V_10 ;
V_10 = V_100 -> V_309 ( & V_171 , 0 ) ;
if ( V_10 )
goto V_210;
V_310 . V_311 = V_100 -> V_311 ;
V_10 = F_186 ( & V_310 ) ;
if ( V_10 )
goto V_312;
V_313 = F_165 ( sizeof( struct V_3 ) , V_138 ) ;
if ( ! V_313 ) {
V_10 = - V_85 ;
goto V_314;
}
F_187 ( V_313 , L_10 ) ;
V_313 -> V_311 = V_100 -> V_311 ;
V_313 -> V_94 = V_100 -> V_315 ;
V_313 -> V_222 = ( void ( * ) ( struct V_3 * ) ) F_134 ;
V_313 -> V_316 = & V_310 ;
V_10 = F_188 ( V_313 ) ;
if ( V_10 )
goto V_314;
return 0 ;
V_314:
F_189 ( & V_310 ) ;
V_312:
V_100 -> V_317 ( & V_171 , 0 ) ;
V_210:
return V_10 ;
}
static int T_7 F_190 ( void )
{
int V_10 ;
if ( V_318 ) {
F_191 ( L_11 , V_163 , sizeof( V_163 ) , & V_10 ) ;
if ( F_95 ( V_10 ) ) {
F_41 ( V_10 ) ;
V_10 = - V_132 ;
goto V_210;
}
V_100 = F_192 ( F_193 ( V_319 ) , L_12 ) ;
if ( ! V_100 ) {
F_5 ( V_5 L_13 ) ;
memset ( & V_163 , 0 , sizeof( V_163 ) ) ;
}
} else {
memset ( & V_163 , 0 , sizeof( V_163 ) ) ;
V_100 = NULL ;
}
V_10 = F_194 ( & V_117 , 0 ) ;
if ( V_10 )
goto V_210;
V_10 = F_195 ( & V_320 ) ;
if ( V_10 )
goto V_321;
if ( V_100 ) {
V_10 = F_185 () ;
if ( V_10 )
goto V_322;
} else
F_196 ( & V_323 ) ;
F_197 ( & V_324 ) ;
return 0 ;
V_322:
F_198 ( V_116 ) ;
V_321:
F_199 ( & V_117 ) ;
V_210:
if ( V_100 )
F_200 ( V_319 ) ;
return V_10 ;
}
static void T_8 F_201 ( void )
{
if ( V_100 ) {
F_202 ( V_313 ) ;
F_189 ( & V_310 ) ;
V_100 -> V_317 ( & V_171 , 0 ) ;
F_200 ( V_319 ) ;
} else
F_203 ( & V_323 ) ;
F_204 ( & V_324 ) ;
F_198 ( V_116 ) ;
F_199 ( & V_117 ) ;
}
