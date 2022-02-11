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
static struct V_8 * F_64 ( struct V_111 * V_8 , int V_112 , T_3 V_113 )
{
struct V_8 * V_9 ;
struct V_6 * V_7 ;
V_9 = F_65 ( & V_114 , V_115 , V_113 , & V_116 ) ;
if ( ! V_9 )
return NULL ;
V_7 = F_10 ( V_9 ) ;
F_66 ( V_8 , V_9 ) ;
F_67 ( & V_7 -> V_117 ) ;
F_68 ( & V_7 -> V_118 ) ;
F_69 ( & V_7 -> V_21 ) ;
F_67 ( & V_7 -> V_119 . V_120 ) ;
F_68 ( & V_7 -> V_119 . V_12 ) ;
F_69 ( & V_7 -> V_22 ) ;
V_7 -> V_121 = 0 ;
F_70 ( & V_7 -> V_41 , 0 ) ;
V_7 -> V_29 = 0 ;
V_7 -> V_62 = 0 ;
F_70 ( & V_7 -> V_39 , 0 ) ;
F_70 ( & V_7 -> V_64 , 0 ) ;
V_7 -> V_37 = NULL ;
V_7 -> V_122 = V_123 ;
memset ( & V_7 -> V_70 , 0 , 32 ) ;
if ( V_100 )
V_7 -> V_35 = V_36 ;
else
V_7 -> V_35 = V_104 ;
V_9 -> V_124 = F_43 ;
V_9 -> V_125 = V_126 ;
V_9 -> V_127 = V_128 ;
F_71 ( V_9 , V_95 ) ;
V_9 -> V_129 = V_112 ;
V_9 -> V_13 = V_17 ;
F_72 ( & V_11 , V_9 ) ;
return V_9 ;
}
static int F_73 ( struct V_130 * V_130 , struct V_111 * V_8 , int V_83 ,
int V_131 )
{
struct V_8 * V_9 ;
if ( V_83 && V_83 != V_115 )
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
V_9 = F_64 ( V_8 , V_83 , V_138 ) ;
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
F_80 ( & V_141 -> V_118 , V_29 ) ;
F_81 ( & F_10 ( V_9 ) -> V_117 , & V_141 -> V_117 ) ;
F_82 ( & V_141 -> V_118 , V_29 ) ;
F_10 ( V_9 ) -> V_94 = V_94 ;
F_83 ( V_94 ) ;
}
void F_84 ( struct V_8 * V_9 )
{
unsigned long V_29 ;
struct V_6 * V_141 = F_10 ( F_10 ( V_9 ) -> V_94 ) ;
F_80 ( & V_141 -> V_118 , V_29 ) ;
F_85 ( & F_10 ( V_9 ) -> V_117 ) ;
F_82 ( & V_141 -> V_118 , V_29 ) ;
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
static int F_114 ( struct V_195 * V_196 , struct V_111 * V_8 ,
struct V_197 * V_27 , T_1 V_78 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_49 * V_50 ;
struct V_26 V_198 ;
struct V_199 * V_200 ;
int V_201 ;
long V_103 ;
char V_202 [ 9 ] ;
char V_203 [ 9 ] ;
int V_10 ;
int V_204 = V_27 -> V_205 & V_206 ;
V_10 = F_115 ( V_9 ) ;
if ( V_10 )
return V_10 ;
if ( V_27 -> V_205 & V_207 )
return - V_208 ;
if ( V_9 -> V_80 == V_81 && ! ( V_27 -> V_205 & V_209 ) )
return - V_208 ;
F_58 ( V_9 ) ;
if ( V_9 -> V_210 & V_211 ) {
V_10 = - V_24 ;
goto V_212;
}
if ( V_9 -> V_13 != V_16 ) {
V_10 = - V_213 ;
goto V_212;
}
V_201 = 0 ;
V_198 . V_214 = 0 ;
for ( V_200 = F_116 ( V_27 ) ; V_200 ;
V_200 = F_117 ( V_27 , V_200 ) ) {
if ( ! F_118 ( V_27 , V_200 ) ) {
V_10 = - V_156 ;
goto V_212;
}
if ( V_200 -> V_215 != V_216 )
continue;
if ( V_200 -> V_217 & V_201 ) {
V_10 = - V_156 ;
goto V_212;
}
V_201 |= V_200 -> V_217 ;
switch ( V_200 -> V_217 ) {
case V_218 :
if ( V_200 -> V_219 != F_119 ( V_220 ) ) {
V_10 = - V_156 ;
goto V_212;
}
memcpy ( & V_198 . V_214 ,
( void * ) F_120 ( V_200 ) , V_220 ) ;
break;
default:
V_10 = - V_156 ;
goto V_212;
break;
}
}
if ( V_7 -> V_35 == V_104 )
V_50 = F_56 ( V_9 ,
V_78 + sizeof( struct V_51 ) + V_56 ,
V_204 , & V_10 ) ;
else
V_50 = F_56 ( V_9 , V_78 , V_204 , & V_10 ) ;
if ( ! V_50 ) {
V_10 = - V_85 ;
goto V_212;
}
if ( V_7 -> V_35 == V_104 )
F_57 ( V_50 , sizeof( struct V_51 ) + V_56 ) ;
if ( F_121 ( F_122 ( V_50 , V_78 ) , V_27 -> V_221 , V_78 ) ) {
V_10 = - V_222 ;
goto V_223;
}
V_103 = F_99 ( V_9 , V_204 ) ;
V_10 = F_60 ( V_9 , F_17 ( V_9 ) , V_103 ) ;
if ( V_10 )
goto V_223;
if ( V_9 -> V_13 != V_16 ) {
V_10 = - V_109 ;
goto V_223;
}
V_198 . V_224 = V_7 -> V_121 ++ ;
F_123 ( V_50 ) -> V_224 = V_198 . V_224 ;
if ( V_7 -> V_35 == V_104 ) {
F_124 ( & V_7 -> V_39 ) ;
V_10 = F_27 ( & V_198 , V_9 , V_50 , 0 ) ;
if ( V_10 ) {
F_125 ( & V_7 -> V_39 ) ;
goto V_223;
}
goto V_225;
}
F_35 ( & V_7 -> V_21 , V_50 ) ;
if ( ( ( V_7 -> V_37 -> V_29 & V_30 ) & V_7 -> V_29 )
&& V_50 -> V_78 <= 7 ) {
V_10 = F_113 ( V_7 -> V_37 , & V_198 , V_50 ) ;
if ( V_10 == 0 ) {
F_38 ( V_50 , & V_7 -> V_21 ) ;
F_39 ( V_50 ) ;
}
if ( V_10 == 0x15 ) {
V_100 -> V_101 ( V_7 -> V_37 , NULL ) ;
F_38 ( V_50 , & V_7 -> V_21 ) ;
V_10 = - V_24 ;
goto V_223;
}
} else
V_10 = V_100 -> V_194 ( V_7 -> V_37 , & V_198 , 0 , 0 ,
( void * ) V_50 -> V_193 , V_50 -> V_78 ) ;
if ( V_10 ) {
if ( V_10 == 3 ) {
V_202 [ 8 ] = 0 ;
memcpy ( V_202 , V_7 -> V_66 , 8 ) ;
V_203 [ 8 ] = 0 ;
memcpy ( V_203 , V_7 -> V_68 , 8 ) ;
F_46 ( L_8
L_9 ,
V_203 , V_202 ) ;
V_10 = - V_173 ;
} else
V_10 = - V_24 ;
F_38 ( V_50 , & V_7 -> V_21 ) ;
goto V_223;
}
V_225:
F_62 ( V_9 ) ;
return V_78 ;
V_223:
F_39 ( V_50 ) ;
V_212:
F_62 ( V_9 ) ;
return V_10 ;
}
static int F_126 ( struct V_8 * V_9 , struct V_49 * V_50 , int V_78 )
{
int V_226 , V_227 , V_228 = 0 ;
struct V_49 * V_53 ;
V_226 = V_78 ;
while ( V_226 ) {
if ( V_226 >= V_9 -> V_229 / 4 )
V_227 = V_9 -> V_229 / 4 ;
else
V_227 = V_226 ;
V_53 = F_127 ( V_227 , V_84 | V_128 ) ;
if ( ! V_53 )
return - V_85 ;
F_123 ( V_53 ) -> V_214 = F_123 ( V_50 ) -> V_214 ;
memcpy ( V_53 -> V_193 , V_50 -> V_193 + V_228 , V_227 ) ;
V_228 += V_227 ;
V_226 -= V_227 ;
F_128 ( V_53 ) ;
F_30 ( V_53 ) ;
V_53 -> V_78 = V_227 ;
F_35 ( & F_10 ( V_9 ) -> V_22 , V_53 ) ;
}
return 0 ;
}
static void F_129 ( struct V_8 * V_9 , struct V_49 * V_50 ,
struct V_99 * V_37 ,
struct V_26 * V_27 )
{
int V_230 ;
unsigned int V_78 ;
V_78 = F_15 ( V_27 ) ;
F_123 ( V_50 ) -> V_214 = V_27 -> V_214 ;
if ( ( V_27 -> V_29 & V_30 ) && V_78 > 7 ) {
if ( memcmp ( V_27 -> V_31 , V_231 , 8 ) == 0 ) {
V_50 -> V_193 = NULL ;
V_50 -> V_78 = 0 ;
}
} else {
V_230 = V_100 -> V_232 ( V_37 , V_27 ,
V_27 -> V_29 & V_30 ,
V_50 -> V_193 , V_78 , NULL ) ;
if ( V_230 ) {
F_39 ( V_50 ) ;
return;
}
if ( V_9 -> V_80 == V_134 &&
V_50 -> V_233 >= V_9 -> V_229 / 4 ) {
V_230 = F_126 ( V_9 , V_50 , V_78 ) ;
F_39 ( V_50 ) ;
V_50 = NULL ;
if ( V_230 ) {
V_100 -> V_101 ( V_37 , NULL ) ;
return;
}
V_50 = F_130 ( & F_10 ( V_9 ) -> V_22 ) ;
} else {
F_128 ( V_50 ) ;
F_30 ( V_50 ) ;
V_50 -> V_78 = V_78 ;
}
}
F_123 ( V_50 ) -> V_234 = 0 ;
if ( F_131 ( V_9 , V_50 ) )
F_132 ( & F_10 ( V_9 ) -> V_22 , V_50 ) ;
}
static void F_133 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_49 * V_50 ;
struct V_235 * V_236 , * V_144 ;
F_87 (p, n, &iucv->message_q.list, list) {
V_50 = F_127 ( F_15 ( & V_236 -> V_27 ) , V_84 | V_128 ) ;
if ( ! V_50 )
break;
F_129 ( V_9 , V_50 , V_236 -> V_37 , & V_236 -> V_27 ) ;
F_134 ( & V_236 -> V_120 ) ;
F_135 ( V_236 ) ;
if ( ! F_59 ( & V_7 -> V_22 ) )
break;
}
}
static int F_136 ( struct V_195 * V_196 , struct V_111 * V_8 ,
struct V_197 * V_27 , T_1 V_78 , int V_29 )
{
int V_204 = V_29 & V_206 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
unsigned int V_228 , V_237 ;
struct V_49 * V_50 , * V_238 , * V_239 ;
int V_10 = 0 ;
T_4 V_234 ;
if ( ( V_9 -> V_13 == V_14 ) &&
F_59 ( & V_7 -> V_22 ) &&
F_59 ( & V_9 -> V_87 ) &&
F_137 ( & V_7 -> V_119 . V_120 ) )
return 0 ;
if ( V_29 & ( V_207 ) )
return - V_208 ;
V_50 = F_138 ( V_9 , V_29 , V_204 , & V_10 ) ;
if ( ! V_50 ) {
if ( V_9 -> V_210 & V_240 )
return 0 ;
return V_10 ;
}
V_234 = F_123 ( V_50 ) -> V_234 ;
V_237 = V_50 -> V_78 - V_234 ;
V_228 = F_139 (unsigned int, rlen, len) ;
if ( ! V_237 )
V_9 -> V_210 = V_9 -> V_210 | V_240 ;
V_239 = V_50 ;
if ( F_140 ( V_239 , V_234 , V_27 -> V_221 , V_228 ) ) {
if ( ! ( V_29 & V_241 ) )
F_132 ( & V_9 -> V_87 , V_50 ) ;
return - V_222 ;
}
if ( V_9 -> V_80 == V_81 ) {
if ( V_228 < V_237 )
V_27 -> V_205 |= V_242 ;
V_27 -> V_205 |= V_209 ;
}
V_10 = F_141 ( V_27 , V_216 , V_218 ,
sizeof( F_123 ( V_50 ) -> V_214 ) ,
( void * ) & F_123 ( V_50 ) -> V_214 ) ;
if ( V_10 ) {
if ( ! ( V_29 & V_241 ) )
F_132 ( & V_9 -> V_87 , V_50 ) ;
return V_10 ;
}
if ( ! ( V_29 & V_241 ) ) {
if ( V_9 -> V_80 == V_134 ) {
if ( V_228 < V_237 ) {
F_123 ( V_50 ) -> V_234 = V_234 + V_228 ;
F_132 ( & V_9 -> V_87 , V_50 ) ;
goto V_158;
}
}
F_39 ( V_50 ) ;
if ( V_7 -> V_35 == V_104 ) {
F_124 ( & V_7 -> V_64 ) ;
if ( F_19 ( & V_7 -> V_64 ) > V_7 -> V_62 ) {
F_41 ( 1 ) ;
F_49 ( V_9 ) ;
return - V_222 ;
}
}
F_142 ( & V_7 -> V_119 . V_12 ) ;
V_238 = F_130 ( & V_7 -> V_22 ) ;
while ( V_238 ) {
F_123 ( V_238 ) -> V_234 = 0 ;
if ( F_131 ( V_9 , V_238 ) ) {
F_132 ( & V_7 -> V_22 ,
V_238 ) ;
break;
} else {
V_238 = F_130 ( & V_7 -> V_22 ) ;
}
}
if ( F_59 ( & V_7 -> V_22 ) ) {
if ( ! F_137 ( & V_7 -> V_119 . V_120 ) )
F_133 ( V_9 ) ;
if ( F_19 ( & V_7 -> V_64 ) >=
V_7 -> V_62 / 2 ) {
V_10 = F_55 ( V_9 , V_63 ) ;
if ( V_10 ) {
V_9 -> V_13 = V_14 ;
V_9 -> V_25 ( V_9 ) ;
}
}
}
F_143 ( & V_7 -> V_119 . V_12 ) ;
}
V_158:
if ( V_9 -> V_80 == V_81 && ( V_29 & V_242 ) )
V_228 = V_237 ;
return V_228 ;
}
static inline unsigned int F_144 ( struct V_8 * V_94 )
{
struct V_6 * V_143 , * V_144 ;
struct V_8 * V_9 ;
F_87 (isk, n, &iucv_sk(parent)->accept_q, accept_q) {
V_9 = (struct V_8 * ) V_143 ;
if ( V_9 -> V_13 == V_16 )
return V_243 | V_244 ;
}
return 0 ;
}
unsigned int F_145 ( struct V_245 * V_245 , struct V_111 * V_8 ,
T_5 * V_45 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
unsigned int V_246 = 0 ;
F_146 ( V_245 , F_106 ( V_9 ) , V_45 ) ;
if ( V_9 -> V_13 == V_19 )
return F_144 ( V_9 ) ;
if ( V_9 -> V_23 || ! F_59 ( & V_9 -> V_88 ) )
V_246 |= V_247 |
( F_45 ( V_9 , V_248 ) ? V_249 : 0 ) ;
if ( V_9 -> V_210 & V_240 )
V_246 |= V_250 ;
if ( V_9 -> V_210 == V_251 )
V_246 |= V_252 ;
if ( ! F_59 ( & V_9 -> V_87 ) ||
( V_9 -> V_210 & V_240 ) )
V_246 |= V_243 | V_244 ;
if ( V_9 -> V_13 == V_20 )
V_246 |= V_252 ;
if ( V_9 -> V_13 == V_14 )
V_246 |= V_243 ;
if ( F_147 ( V_9 ) && F_17 ( V_9 ) )
V_246 |= V_253 | V_254 | V_255 ;
else
F_148 ( V_256 , & V_9 -> V_96 -> V_29 ) ;
return V_246 ;
}
static int F_149 ( struct V_111 * V_8 , int V_257 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_26 V_198 ;
int V_10 = 0 ;
V_257 ++ ;
if ( ( V_257 & ~ V_251 ) || ! V_257 )
return - V_156 ;
F_58 ( V_9 ) ;
switch ( V_9 -> V_13 ) {
case V_19 :
case V_14 :
case V_15 :
case V_20 :
V_10 = - V_213 ;
goto V_223;
default:
break;
}
if ( V_257 == V_211 || V_257 == V_251 ) {
if ( V_7 -> V_35 == V_36 ) {
V_198 . V_214 = 0 ;
V_198 . V_224 = 0 ;
V_10 = V_100 -> V_194 ( V_7 -> V_37 , & V_198 ,
V_30 , 0 , ( void * ) V_231 , 8 ) ;
if ( V_10 ) {
switch ( V_10 ) {
case 1 :
V_10 = - V_213 ;
break;
case 2 :
V_10 = - V_109 ;
break;
default:
V_10 = - V_213 ;
break;
}
}
} else
F_55 ( V_9 , V_258 ) ;
}
V_9 -> V_210 |= V_257 ;
if ( V_257 == V_240 || V_257 == V_251 ) {
if ( V_7 -> V_35 == V_36 ) {
V_10 = V_100 -> V_259 ( V_7 -> V_37 , NULL ) ;
if ( V_10 )
V_10 = - V_213 ;
}
F_12 ( & V_9 -> V_87 ) ;
}
V_9 -> V_25 ( V_9 ) ;
V_223:
F_62 ( V_9 ) ;
return V_10 ;
}
static int F_150 ( struct V_111 * V_8 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
int V_10 = 0 ;
if ( ! V_9 )
return 0 ;
F_49 ( V_9 ) ;
F_151 ( V_9 ) ;
F_50 ( V_9 ) ;
return V_10 ;
}
static int F_152 ( struct V_111 * V_8 , int V_260 , int V_261 ,
char T_6 * V_262 , unsigned int V_263 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
int V_264 ;
int V_230 ;
if ( V_260 != V_216 )
return - V_265 ;
if ( V_263 < sizeof( int ) )
return - V_156 ;
if ( F_153 ( V_264 , ( int T_6 * ) V_262 ) )
return - V_222 ;
V_230 = 0 ;
F_58 ( V_9 ) ;
switch ( V_261 ) {
case V_266 :
if ( V_264 )
V_7 -> V_29 |= V_30 ;
else
V_7 -> V_29 &= ~ V_30 ;
break;
case V_267 :
switch ( V_9 -> V_13 ) {
case V_17 :
case V_18 :
if ( V_264 < 1 || V_264 > ( V_268 ) ( ~ 0 ) )
V_230 = - V_156 ;
else
V_7 -> V_62 = V_264 ;
break;
default:
V_230 = - V_156 ;
break;
}
break;
default:
V_230 = - V_265 ;
break;
}
F_62 ( V_9 ) ;
return V_230 ;
}
static int F_154 ( struct V_111 * V_8 , int V_260 , int V_261 ,
char T_6 * V_262 , int T_6 * V_263 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
unsigned int V_264 ;
int V_78 ;
if ( V_260 != V_216 )
return - V_265 ;
if ( F_153 ( V_78 , V_263 ) )
return - V_222 ;
if ( V_78 < 0 )
return - V_156 ;
V_78 = F_139 (unsigned int, len, sizeof(int)) ;
switch ( V_261 ) {
case V_266 :
V_264 = ( V_7 -> V_29 & V_30 ) ? 1 : 0 ;
break;
case V_267 :
F_58 ( V_9 ) ;
V_264 = ( V_7 -> V_37 != NULL ) ? V_7 -> V_37 -> V_38
: V_7 -> V_62 ;
F_62 ( V_9 ) ;
break;
case V_269 :
if ( V_9 -> V_13 == V_17 )
return - V_157 ;
V_264 = ( V_7 -> V_74 ) ? V_7 -> V_74 -> V_79 -
sizeof( struct V_51 ) - V_56 :
0x7fffffff ;
break;
default:
return - V_265 ;
}
if ( F_155 ( V_78 , V_263 ) )
return - V_222 ;
if ( F_156 ( V_262 , & V_264 , V_78 ) )
return - V_222 ;
return 0 ;
}
static int F_157 ( struct V_99 * V_37 ,
T_2 V_270 [ 8 ] , T_2 V_271 [ 16 ] )
{
unsigned char V_98 [ 16 ] ;
unsigned char V_272 [ 16 ] ;
unsigned char V_72 [ 8 ] ;
struct V_8 * V_9 , * V_182 ;
struct V_6 * V_7 , * V_273 ;
int V_10 ;
memcpy ( V_72 , V_271 , 8 ) ;
F_158 ( V_72 , 8 ) ;
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
F_159 ( V_9 ) ;
F_2 ( V_98 , V_7 -> V_72 ) ;
F_1 ( V_98 , V_7 -> V_68 ) ;
F_31 ( V_98 , sizeof( V_98 ) ) ;
if ( V_9 -> V_13 != V_19 ) {
V_10 = V_100 -> V_101 ( V_37 , V_98 ) ;
F_54 ( V_37 ) ;
goto V_223;
}
if ( F_160 ( V_9 ) ) {
V_10 = V_100 -> V_101 ( V_37 , V_98 ) ;
F_54 ( V_37 ) ;
goto V_223;
}
V_182 = F_64 ( NULL , V_9 -> V_80 , V_84 ) ;
if ( ! V_182 ) {
V_10 = V_100 -> V_101 ( V_37 , V_98 ) ;
F_54 ( V_37 ) ;
goto V_223;
}
V_273 = F_10 ( V_182 ) ;
F_63 ( V_182 , V_9 ) ;
memcpy ( V_273 -> V_68 , V_271 + 8 , 8 ) ;
F_158 ( V_273 -> V_68 , 8 ) ;
memcpy ( V_273 -> V_66 , V_270 , 8 ) ;
memcpy ( V_273 -> V_72 , V_7 -> V_72 , 8 ) ;
memcpy ( V_273 -> V_70 , V_7 -> V_70 , 8 ) ;
V_273 -> V_37 = V_37 ;
F_1 ( V_272 , V_271 + 8 ) ;
memcpy ( V_272 + 8 , V_273 -> V_72 , 8 ) ;
F_31 ( V_272 + 8 , 8 ) ;
V_273 -> V_62 = V_7 -> V_62 ;
V_37 -> V_38 = V_7 -> V_62 ;
V_10 = V_100 -> V_274 ( V_37 , & V_171 , V_272 , V_182 ) ;
if ( V_10 ) {
F_11 ( V_182 , 1 ) ;
F_50 ( V_182 ) ;
goto V_223;
}
F_78 ( V_9 , V_182 ) ;
V_182 -> V_13 = V_16 ;
V_9 -> V_275 ( V_9 ) ;
V_10 = 0 ;
V_223:
F_161 ( V_9 ) ;
return 0 ;
}
static void F_162 ( struct V_99 * V_37 , T_2 V_271 [ 16 ] )
{
struct V_8 * V_9 = V_37 -> V_276 ;
V_9 -> V_13 = V_16 ;
V_9 -> V_25 ( V_9 ) ;
}
static void F_163 ( struct V_99 * V_37 , struct V_26 * V_27 )
{
struct V_8 * V_9 = V_37 -> V_276 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_49 * V_50 ;
struct V_235 * V_277 ;
int V_78 ;
if ( V_9 -> V_210 & V_240 ) {
V_100 -> V_278 ( V_37 , V_27 ) ;
return;
}
F_164 ( & V_7 -> V_119 . V_12 ) ;
if ( ! F_137 ( & V_7 -> V_119 . V_120 ) ||
! F_59 ( & V_7 -> V_22 ) )
goto V_279;
V_78 = F_19 ( & V_9 -> V_90 ) ;
V_78 += F_165 ( F_15 ( V_27 ) ) ;
if ( V_78 > V_9 -> V_229 )
goto V_279;
V_50 = F_127 ( F_15 ( V_27 ) , V_84 | V_128 ) ;
if ( ! V_50 )
goto V_279;
F_129 ( V_9 , V_50 , V_37 , V_27 ) ;
goto V_280;
V_279:
V_277 = F_166 ( sizeof( struct V_235 ) , V_84 | V_128 ) ;
if ( ! V_277 )
goto V_280;
V_277 -> V_37 = V_37 ;
V_277 -> V_27 = * V_27 ;
F_81 ( & V_277 -> V_120 , & V_7 -> V_119 . V_120 ) ;
V_280:
F_167 ( & V_7 -> V_119 . V_12 ) ;
}
static void F_168 ( struct V_99 * V_37 ,
struct V_26 * V_27 )
{
struct V_8 * V_9 = V_37 -> V_276 ;
struct V_49 * V_281 = NULL ;
struct V_282 * V_120 = & F_10 ( V_9 ) -> V_21 ;
struct V_49 * V_283 = V_120 -> V_284 ;
unsigned long V_29 ;
F_159 ( V_9 ) ;
if ( ! F_59 ( V_120 ) ) {
F_80 ( & V_120 -> V_12 , V_29 ) ;
while ( V_283 != (struct V_49 * ) V_120 ) {
if ( V_27 -> V_224 == F_123 ( V_283 ) -> V_224 ) {
V_281 = V_283 ;
break;
}
V_283 = V_283 -> V_284 ;
}
if ( V_281 )
F_169 ( V_281 , V_120 ) ;
F_82 ( & V_120 -> V_12 , V_29 ) ;
if ( V_281 ) {
F_39 ( V_281 ) ;
F_20 ( V_9 ) ;
}
}
if ( V_9 -> V_13 == V_15 ) {
if ( F_59 ( & F_10 ( V_9 ) -> V_21 ) ) {
V_9 -> V_13 = V_20 ;
V_9 -> V_25 ( V_9 ) ;
}
}
F_161 ( V_9 ) ;
}
static void F_170 ( struct V_99 * V_37 , T_2 V_271 [ 16 ] )
{
struct V_8 * V_9 = V_37 -> V_276 ;
if ( V_9 -> V_13 == V_20 )
return;
F_159 ( V_9 ) ;
F_11 ( V_9 , 1 ) ;
V_9 -> V_13 = V_14 ;
V_9 -> V_25 ( V_9 ) ;
F_161 ( V_9 ) ;
}
static void F_171 ( struct V_99 * V_37 , T_2 V_271 [ 16 ] )
{
struct V_8 * V_9 = V_37 -> V_276 ;
F_159 ( V_9 ) ;
if ( V_9 -> V_13 != V_20 ) {
V_9 -> V_210 |= V_211 ;
V_9 -> V_25 ( V_9 ) ;
}
F_161 ( V_9 ) ;
}
static void F_172 ( struct V_49 * V_50 )
{
struct V_51 * V_285 =
(struct V_51 * ) V_50 -> V_193 ;
char V_286 [ 8 ] ;
char V_287 [ 8 ] ;
F_31 ( V_285 -> V_65 , sizeof( V_285 -> V_65 ) ) ;
F_31 ( V_285 -> V_67 , sizeof( V_285 -> V_67 ) ) ;
F_31 ( V_285 -> V_69 , sizeof( V_285 -> V_69 ) ) ;
F_31 ( V_285 -> V_71 , sizeof( V_285 -> V_71 ) ) ;
memcpy ( V_286 , V_285 -> V_69 , 8 ) ;
memcpy ( V_287 , V_285 -> V_71 , 8 ) ;
memcpy ( V_285 -> V_69 , V_285 -> V_65 , 8 ) ;
memcpy ( V_285 -> V_71 , V_285 -> V_67 , 8 ) ;
memcpy ( V_285 -> V_65 , V_286 , 8 ) ;
memcpy ( V_285 -> V_67 , V_287 , 8 ) ;
F_28 ( V_50 , V_56 ) ;
memset ( V_50 -> V_193 , 0 , V_56 ) ;
}
static int F_173 ( struct V_8 * V_9 , struct V_49 * V_50 )
{
struct V_8 * V_182 ;
struct V_6 * V_7 , * V_273 ;
struct V_51 * V_285 ;
int V_10 ;
V_7 = F_10 ( V_9 ) ;
V_285 = (struct V_51 * ) V_50 -> V_193 ;
if ( ! V_7 ) {
F_172 ( V_50 ) ;
V_285 -> V_29 = V_60 | V_105 ;
V_10 = F_36 ( V_50 ) ;
goto V_212;
}
V_182 = F_64 ( NULL , V_9 -> V_80 , V_84 ) ;
F_159 ( V_9 ) ;
if ( ( V_9 -> V_13 != V_19 ) ||
F_160 ( V_9 ) ||
! V_182 ) {
F_172 ( V_50 ) ;
V_285 -> V_29 = V_60 | V_105 ;
V_10 = F_36 ( V_50 ) ;
F_50 ( V_182 ) ;
F_161 ( V_9 ) ;
goto V_212;
}
V_273 = F_10 ( V_182 ) ;
F_63 ( V_182 , V_9 ) ;
V_273 -> V_35 = V_104 ;
V_273 -> V_62 = V_7 -> V_62 ;
if ( ! V_285 -> V_61 )
V_273 -> V_40 = V_167 ;
else
V_273 -> V_40 = V_285 -> V_61 ;
memcpy ( V_273 -> V_68 , V_285 -> V_71 , 8 ) ;
memcpy ( V_273 -> V_66 , V_285 -> V_69 , 8 ) ;
memcpy ( V_273 -> V_72 , V_7 -> V_72 , 8 ) ;
memcpy ( V_273 -> V_70 , V_7 -> V_70 , 8 ) ;
V_182 -> V_110 = V_9 -> V_110 ;
V_273 -> V_74 = V_7 -> V_74 ;
F_93 ( V_273 -> V_74 ) ;
F_172 ( V_50 ) ;
V_285 -> V_29 = V_60 | V_288 ;
V_285 -> V_61 = V_273 -> V_62 ;
V_10 = F_36 ( V_50 ) ;
if ( ! V_10 ) {
F_78 ( V_9 , V_182 ) ;
V_182 -> V_13 = V_16 ;
V_9 -> V_275 ( V_9 ) ;
} else
F_50 ( V_182 ) ;
F_161 ( V_9 ) ;
V_212:
return V_289 ;
}
static int F_174 ( struct V_8 * V_9 , struct V_49 * V_50 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_51 * V_285 =
(struct V_51 * ) V_50 -> V_193 ;
if ( ! V_7 )
goto V_212;
if ( V_9 -> V_13 != V_18 )
goto V_212;
F_159 ( V_9 ) ;
V_7 -> V_40 = V_285 -> V_61 ;
V_9 -> V_13 = V_16 ;
V_9 -> V_25 ( V_9 ) ;
F_161 ( V_9 ) ;
V_212:
F_39 ( V_50 ) ;
return V_289 ;
}
static int F_175 ( struct V_8 * V_9 , struct V_49 * V_50 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
if ( ! V_7 )
goto V_212;
if ( V_9 -> V_13 != V_18 )
goto V_212;
F_159 ( V_9 ) ;
V_9 -> V_13 = V_14 ;
V_9 -> V_25 ( V_9 ) ;
F_161 ( V_9 ) ;
V_212:
F_39 ( V_50 ) ;
return V_289 ;
}
static int F_176 ( struct V_8 * V_9 , struct V_49 * V_50 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
if ( ! V_7 )
goto V_212;
F_159 ( V_9 ) ;
if ( V_9 -> V_13 == V_16 ) {
V_9 -> V_13 = V_14 ;
V_9 -> V_25 ( V_9 ) ;
}
F_161 ( V_9 ) ;
V_212:
F_39 ( V_50 ) ;
return V_289 ;
}
static int F_177 ( struct V_8 * V_9 , struct V_49 * V_50 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_51 * V_285 =
(struct V_51 * ) V_50 -> V_193 ;
if ( ! V_7 )
return V_289 ;
if ( V_9 -> V_13 != V_16 )
return V_289 ;
F_40 ( V_285 -> V_61 , & V_7 -> V_39 ) ;
F_20 ( V_9 ) ;
return V_289 ;
}
static int F_178 ( struct V_8 * V_9 , struct V_49 * V_50 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
if ( ! V_7 ) {
F_39 ( V_50 ) ;
return V_289 ;
}
if ( V_9 -> V_13 != V_16 ) {
F_39 ( V_50 ) ;
return V_289 ;
}
if ( V_9 -> V_210 & V_240 ) {
F_39 ( V_50 ) ;
return V_289 ;
}
if ( V_50 -> V_78 < sizeof( struct V_51 ) ) {
F_39 ( V_50 ) ;
return V_289 ;
}
F_179 ( V_50 , sizeof( struct V_51 ) ) ;
F_128 ( V_50 ) ;
F_30 ( V_50 ) ;
F_123 ( V_50 ) -> V_234 = 0 ;
F_164 ( & V_7 -> V_119 . V_12 ) ;
if ( F_59 ( & V_7 -> V_22 ) ) {
if ( F_131 ( V_9 , V_50 ) ) {
F_35 ( & V_7 -> V_22 , V_50 ) ;
}
} else
F_35 ( & F_10 ( V_9 ) -> V_22 , V_50 ) ;
F_167 ( & V_7 -> V_119 . V_12 ) ;
return V_289 ;
}
static int F_180 ( struct V_49 * V_50 , struct V_152 * V_4 ,
struct V_290 * V_291 , struct V_152 * V_292 )
{
struct V_8 * V_9 ;
struct V_6 * V_7 ;
struct V_51 * V_285 ;
char V_293 [ 8 ] ;
int V_10 = 0 ;
F_179 ( V_50 , V_56 ) ;
V_285 = (struct V_51 * ) V_50 -> V_193 ;
F_158 ( V_285 -> V_67 , sizeof( V_285 -> V_67 ) ) ;
F_158 ( V_285 -> V_65 , sizeof( V_285 -> V_65 ) ) ;
F_158 ( V_285 -> V_71 , sizeof( V_285 -> V_71 ) ) ;
F_158 ( V_285 -> V_69 , sizeof( V_285 -> V_69 ) ) ;
memset ( V_293 , 0 , sizeof( V_293 ) ) ;
V_7 = NULL ;
V_9 = NULL ;
F_8 ( & V_11 . V_12 ) ;
F_9 (sk, &iucv_sk_list.head) {
if ( V_285 -> V_29 == V_60 ) {
if ( ( ! memcmp ( & F_10 ( V_9 ) -> V_72 ,
V_285 -> V_67 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_70 ,
V_285 -> V_65 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_68 , V_293 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_66 ,
V_293 , 8 ) ) ) {
V_7 = F_10 ( V_9 ) ;
break;
}
} else {
if ( ( ! memcmp ( & F_10 ( V_9 ) -> V_72 ,
V_285 -> V_67 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_70 ,
V_285 -> V_65 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_68 ,
V_285 -> V_71 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_66 ,
V_285 -> V_69 , 8 ) ) ) {
V_7 = F_10 ( V_9 ) ;
break;
}
}
}
F_13 ( & V_11 . V_12 ) ;
if ( ! V_7 )
V_9 = NULL ;
switch ( V_285 -> V_29 ) {
case V_60 :
V_10 = F_173 ( V_9 , V_50 ) ;
break;
case ( V_60 | V_288 ) :
V_10 = F_174 ( V_9 , V_50 ) ;
break;
case ( V_60 | V_105 ) :
V_10 = F_175 ( V_9 , V_50 ) ;
break;
case ( V_105 ) :
V_10 = F_176 ( V_9 , V_50 ) ;
break;
case ( V_63 ) :
V_10 = F_177 ( V_9 , V_50 ) ;
if ( V_50 -> V_78 == sizeof( struct V_51 ) ) {
F_39 ( V_50 ) ;
break;
}
case ( V_258 ) :
case 0 :
F_123 ( V_50 ) -> V_214 = V_285 -> V_73 . V_214 ;
V_10 = F_178 ( V_9 , V_50 ) ;
break;
default:
;
}
return V_10 ;
}
static void V_123 ( struct V_49 * V_50 ,
enum V_294 V_144 )
{
struct V_8 * V_143 = V_50 -> V_9 ;
struct V_8 * V_9 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_282 * V_120 ;
struct V_49 * V_283 ;
struct V_49 * V_53 ;
unsigned long V_29 ;
F_181 ( & V_11 . V_12 , V_29 ) ;
F_9 (sk, &iucv_sk_list.head)
if ( V_9 == V_143 ) {
V_7 = F_10 ( V_9 ) ;
break;
}
F_182 ( & V_11 . V_12 , V_29 ) ;
if ( ! V_7 || F_45 ( V_9 , V_95 ) )
return;
V_120 = & V_7 -> V_21 ;
F_80 ( & V_120 -> V_12 , V_29 ) ;
if ( F_59 ( V_120 ) )
goto V_280;
V_283 = V_120 -> V_284 ;
V_53 = V_283 -> V_284 ;
while ( V_283 != (struct V_49 * ) V_120 ) {
if ( F_183 ( V_283 ) == F_183 ( V_50 ) ) {
switch ( V_144 ) {
case V_295 :
F_169 ( V_283 , V_120 ) ;
F_39 ( V_283 ) ;
F_20 ( V_9 ) ;
break;
case V_296 :
F_124 ( & V_7 -> V_41 ) ;
break;
case V_297 :
F_169 ( V_283 , V_120 ) ;
F_125 ( & V_7 -> V_41 ) ;
if ( F_19 ( & V_7 -> V_41 ) <= 0 )
F_20 ( V_9 ) ;
F_39 ( V_283 ) ;
break;
case V_298 :
case V_299 :
case V_300 :
case V_301 :
case V_302 :
F_169 ( V_283 , V_120 ) ;
F_39 ( V_283 ) ;
if ( V_9 -> V_13 == V_16 ) {
V_9 -> V_13 = V_14 ;
V_9 -> V_25 ( V_9 ) ;
}
break;
}
break;
}
V_283 = V_53 ;
V_53 = V_53 -> V_284 ;
}
V_280:
F_82 ( & V_120 -> V_12 , V_29 ) ;
if ( V_9 -> V_13 == V_15 ) {
if ( F_59 ( & F_10 ( V_9 ) -> V_21 ) ) {
V_9 -> V_13 = V_20 ;
V_9 -> V_25 ( V_9 ) ;
}
}
}
static int F_184 ( struct V_303 * V_281 ,
unsigned long V_304 , void * V_305 )
{
struct V_152 * V_306 = F_185 ( V_305 ) ;
struct V_8 * V_9 ;
struct V_6 * V_7 ;
switch ( V_304 ) {
case V_307 :
case V_308 :
F_9 (sk, &iucv_sk_list.head) {
V_7 = F_10 ( V_9 ) ;
if ( ( V_7 -> V_74 == V_306 ) &&
( V_9 -> V_13 == V_16 ) ) {
if ( V_304 == V_308 )
F_55 ( V_9 , V_105 ) ;
V_9 -> V_13 = V_14 ;
V_9 -> V_25 ( V_9 ) ;
}
}
break;
case V_309 :
case V_310 :
default:
break;
}
return V_311 ;
}
static int F_186 ( void )
{
int V_10 ;
V_10 = V_100 -> V_312 ( & V_171 , 0 ) ;
if ( V_10 )
goto V_212;
V_313 . V_314 = V_100 -> V_314 ;
V_10 = F_187 ( & V_313 ) ;
if ( V_10 )
goto V_315;
V_316 = F_166 ( sizeof( struct V_3 ) , V_138 ) ;
if ( ! V_316 ) {
V_10 = - V_85 ;
goto V_317;
}
F_188 ( V_316 , L_10 ) ;
V_316 -> V_314 = V_100 -> V_314 ;
V_316 -> V_94 = V_100 -> V_318 ;
V_316 -> V_225 = ( void ( * ) ( struct V_3 * ) ) F_135 ;
V_316 -> V_319 = & V_313 ;
V_10 = F_189 ( V_316 ) ;
if ( V_10 )
goto V_317;
return 0 ;
V_317:
F_190 ( & V_313 ) ;
V_315:
V_100 -> V_320 ( & V_171 , 0 ) ;
V_212:
return V_10 ;
}
static int T_7 F_191 ( void )
{
int V_10 ;
if ( V_321 ) {
F_192 ( L_11 , V_163 , sizeof( V_163 ) , & V_10 ) ;
if ( F_95 ( V_10 ) ) {
F_41 ( V_10 ) ;
V_10 = - V_132 ;
goto V_212;
}
V_100 = F_193 ( F_194 ( V_322 ) , L_12 ) ;
if ( ! V_100 ) {
F_5 ( V_5 L_13 ) ;
memset ( & V_163 , 0 , sizeof( V_163 ) ) ;
}
} else {
memset ( & V_163 , 0 , sizeof( V_163 ) ) ;
V_100 = NULL ;
}
V_10 = F_195 ( & V_116 , 0 ) ;
if ( V_10 )
goto V_212;
V_10 = F_196 ( & V_323 ) ;
if ( V_10 )
goto V_324;
if ( V_100 ) {
V_10 = F_186 () ;
if ( V_10 )
goto V_325;
} else
F_197 ( & V_326 ) ;
F_198 ( & V_327 ) ;
return 0 ;
V_325:
F_199 ( V_115 ) ;
V_324:
F_200 ( & V_116 ) ;
V_212:
if ( V_100 )
F_201 ( V_322 ) ;
return V_10 ;
}
static void T_8 F_202 ( void )
{
if ( V_100 ) {
F_203 ( V_316 ) ;
F_190 ( & V_313 ) ;
V_100 -> V_320 ( & V_171 , 0 ) ;
F_201 ( V_322 ) ;
} else
F_204 ( & V_326 ) ;
F_205 ( & V_327 ) ;
F_199 ( V_115 ) ;
F_200 ( & V_116 ) ;
}
