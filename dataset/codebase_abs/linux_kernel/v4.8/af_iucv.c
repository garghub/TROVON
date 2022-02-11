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
if ( V_94 ) {
V_9 -> V_80 = V_94 -> V_80 ;
F_64 ( V_94 , V_9 ) ;
}
}
static struct V_8 * F_65 ( struct V_111 * V_8 , int V_112 , T_3 V_113 , int V_114 )
{
struct V_8 * V_9 ;
struct V_6 * V_7 ;
V_9 = F_66 ( & V_115 , V_116 , V_113 , & V_117 , V_114 ) ;
if ( ! V_9 )
return NULL ;
V_7 = F_10 ( V_9 ) ;
F_67 ( V_8 , V_9 ) ;
F_68 ( & V_7 -> V_118 ) ;
F_69 ( & V_7 -> V_119 ) ;
F_70 ( & V_7 -> V_21 ) ;
F_68 ( & V_7 -> V_120 . V_121 ) ;
F_69 ( & V_7 -> V_120 . V_12 ) ;
F_70 ( & V_7 -> V_22 ) ;
V_7 -> V_122 = 0 ;
F_71 ( & V_7 -> V_41 , 0 ) ;
V_7 -> V_29 = 0 ;
V_7 -> V_62 = 0 ;
F_71 ( & V_7 -> V_39 , 0 ) ;
F_71 ( & V_7 -> V_64 , 0 ) ;
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
F_72 ( V_9 , V_95 ) ;
V_9 -> V_130 = V_112 ;
V_9 -> V_13 = V_17 ;
F_73 ( & V_11 , V_9 ) ;
return V_9 ;
}
static int F_74 ( struct V_131 * V_131 , struct V_111 * V_8 , int V_83 ,
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
V_9 = F_65 ( V_8 , V_83 , V_138 , V_114 ) ;
if ( ! V_9 )
return - V_85 ;
F_63 ( V_9 , NULL ) ;
return 0 ;
}
void F_73 ( struct V_139 * V_140 , struct V_8 * V_9 )
{
F_75 ( & V_140 -> V_12 ) ;
F_76 ( V_9 , & V_140 -> V_55 ) ;
F_77 ( & V_140 -> V_12 ) ;
}
void F_51 ( struct V_139 * V_140 , struct V_8 * V_9 )
{
F_75 ( & V_140 -> V_12 ) ;
F_78 ( V_9 ) ;
F_77 ( & V_140 -> V_12 ) ;
}
void F_79 ( struct V_8 * V_94 , struct V_8 * V_9 )
{
unsigned long V_29 ;
struct V_6 * V_141 = F_10 ( V_94 ) ;
F_80 ( V_9 ) ;
F_81 ( & V_141 -> V_119 , V_29 ) ;
F_82 ( & F_10 ( V_9 ) -> V_118 , & V_141 -> V_118 ) ;
F_83 ( & V_141 -> V_119 , V_29 ) ;
F_10 ( V_9 ) -> V_94 = V_94 ;
F_84 ( V_94 ) ;
}
void F_85 ( struct V_8 * V_9 )
{
unsigned long V_29 ;
struct V_6 * V_141 = F_10 ( F_10 ( V_9 ) -> V_94 ) ;
F_81 ( & V_141 -> V_119 , V_29 ) ;
F_86 ( & F_10 ( V_9 ) -> V_118 ) ;
F_83 ( & V_141 -> V_119 , V_29 ) ;
F_87 ( F_10 ( V_9 ) -> V_94 ) ;
F_10 ( V_9 ) -> V_94 = NULL ;
F_53 ( V_9 ) ;
}
struct V_8 * F_48 ( struct V_8 * V_94 , struct V_111 * V_142 )
{
struct V_6 * V_143 , * V_144 ;
struct V_8 * V_9 ;
F_88 (isk, n, &iucv_sk(parent)->accept_q, accept_q) {
V_9 = (struct V_8 * ) V_143 ;
F_58 ( V_9 ) ;
if ( V_9 -> V_13 == V_20 ) {
F_85 ( V_9 ) ;
F_62 ( V_9 ) ;
continue;
}
if ( V_9 -> V_13 == V_16 ||
V_9 -> V_13 == V_14 ||
! V_142 ) {
F_85 ( V_9 ) ;
if ( V_142 )
F_89 ( V_9 , V_142 ) ;
F_62 ( V_9 ) ;
return V_9 ;
}
F_62 ( V_9 ) ;
}
return NULL ;
}
static void F_90 ( struct V_6 * V_7 )
{
char V_145 [ 12 ] ;
sprintf ( V_145 , L_6 , F_91 ( & V_11 . V_146 ) ) ;
while ( F_42 ( V_145 ) ) {
sprintf ( V_145 , L_6 ,
F_91 ( & V_11 . V_146 ) ) ;
}
memcpy ( V_7 -> V_72 , V_145 , 8 ) ;
}
static int F_92 ( struct V_111 * V_8 , struct V_147 * V_148 ,
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
if ( V_149 < sizeof( struct V_150 ) )
return - V_156 ;
F_58 ( V_9 ) ;
if ( V_9 -> V_13 != V_17 ) {
V_10 = - V_157 ;
goto V_158;
}
F_75 ( & V_11 . V_12 ) ;
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
F_93 (&init_net, dev) {
if ( ! memcmp ( V_4 -> V_165 , V_153 , 8 ) ) {
memcpy ( V_7 -> V_70 , V_151 -> V_162 , 8 ) ;
if ( strncmp ( V_151 -> V_159 , L_7 , 8 ) == 0 )
F_90 ( V_7 ) ;
else
memcpy ( V_7 -> V_72 , V_151 -> V_159 , 8 ) ;
V_9 -> V_110 = V_4 -> V_166 ;
V_7 -> V_74 = V_4 ;
F_94 ( V_4 ) ;
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
F_77 ( & V_11 . V_12 ) ;
V_158:
F_62 ( V_9 ) ;
return V_10 ;
}
static int F_95 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
int V_10 = 0 ;
if ( F_96 ( ! V_100 ) )
return - V_169 ;
memcpy ( V_7 -> V_70 , V_163 , 8 ) ;
F_75 ( & V_11 . V_12 ) ;
F_90 ( V_7 ) ;
F_77 ( & V_11 . V_12 ) ;
if ( ! V_7 -> V_62 )
V_7 -> V_62 = V_168 ;
return V_10 ;
}
static int F_97 ( struct V_111 * V_8 , struct V_147 * V_148 )
{
struct V_150 * V_151 = (struct V_150 * ) V_148 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
unsigned char V_98 [ 16 ] ;
int V_10 ;
F_1 ( V_98 , V_151 -> V_159 ) ;
F_2 ( V_98 , V_7 -> V_72 ) ;
F_31 ( V_98 , sizeof( V_98 ) ) ;
V_7 -> V_37 = F_98 ( V_7 -> V_62 ,
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
static int F_99 ( struct V_111 * V_8 , struct V_147 * V_148 ,
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
V_10 = F_95 ( V_9 ) ;
if ( F_96 ( V_10 ) )
return V_10 ;
}
F_58 ( V_9 ) ;
memcpy ( V_7 -> V_66 , V_151 -> V_162 , 8 ) ;
memcpy ( V_7 -> V_68 , V_151 -> V_159 , 8 ) ;
if ( V_7 -> V_35 == V_104 )
V_10 = F_55 ( V_8 -> V_9 , V_60 ) ;
else
V_10 = F_97 ( V_8 , V_148 ) ;
if ( V_10 )
goto V_158;
if ( V_9 -> V_13 != V_16 )
V_10 = F_60 ( V_9 , F_16 ( V_9 , V_16 ,
V_14 ) ,
F_100 ( V_9 , V_29 & V_177 ) ) ;
if ( V_9 -> V_13 == V_14 || V_9 -> V_13 == V_20 )
V_10 = - V_175 ;
if ( V_10 && V_7 -> V_35 == V_36 )
F_11 ( V_9 , 0 ) ;
V_158:
F_62 ( V_9 ) ;
return V_10 ;
}
static int F_101 ( struct V_111 * V_8 , int V_178 )
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
static int F_102 ( struct V_111 * V_8 , struct V_111 * V_142 ,
int V_29 )
{
F_103 ( V_45 , V_181 ) ;
struct V_8 * V_9 = V_8 -> V_9 , * V_182 ;
long V_103 ;
int V_10 = 0 ;
F_104 ( V_9 , V_183 ) ;
if ( V_9 -> V_13 != V_19 ) {
V_10 = - V_157 ;
goto V_158;
}
V_103 = F_105 ( V_9 , V_29 & V_177 ) ;
F_106 ( F_107 ( V_9 ) , & V_45 ) ;
while ( ! ( V_182 = F_48 ( V_9 , V_142 ) ) ) {
F_108 ( V_184 ) ;
if ( ! V_103 ) {
V_10 = - V_173 ;
break;
}
F_62 ( V_9 ) ;
V_103 = F_109 ( V_103 ) ;
F_104 ( V_9 , V_183 ) ;
if ( V_9 -> V_13 != V_19 ) {
V_10 = - V_157 ;
break;
}
if ( F_110 ( V_181 ) ) {
V_10 = F_111 ( V_103 ) ;
break;
}
}
F_108 ( V_185 ) ;
F_112 ( F_107 ( V_9 ) , & V_45 ) ;
if ( V_10 )
goto V_158;
V_142 -> V_33 = V_186 ;
V_158:
F_62 ( V_9 ) ;
return V_10 ;
}
static int F_113 ( struct V_111 * V_8 , struct V_147 * V_148 ,
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
static int F_114 ( struct V_99 * V_37 , struct V_26 * V_27 ,
struct V_49 * V_50 )
{
T_2 V_192 [ 8 ] ;
memcpy ( V_192 , ( void * ) V_50 -> V_193 , V_50 -> V_78 ) ;
V_192 [ 7 ] = 0xff - ( T_2 ) V_50 -> V_78 ;
return V_100 -> V_194 ( V_37 , V_27 , V_30 , 0 ,
( void * ) V_192 , 8 ) ;
}
static int F_115 ( struct V_111 * V_8 , struct V_195 * V_27 ,
T_1 V_78 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
T_1 V_196 , V_197 ;
struct V_49 * V_50 ;
struct V_26 V_198 = { 0 } ;
struct V_199 * V_200 ;
int V_201 ;
long V_103 ;
char V_202 [ 9 ] ;
char V_203 [ 9 ] ;
int V_10 ;
int V_204 = V_27 -> V_205 & V_206 ;
V_10 = F_116 ( V_9 ) ;
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
F_117 (cmsg, msg) {
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
}
}
V_196 = ( V_7 -> V_35 == V_104 )
? sizeof( struct V_51 ) + V_56 : 0 ;
if ( V_196 + V_78 < V_221 ) {
V_197 = V_78 ;
} else {
if ( V_7 -> V_35 != V_104 )
V_196 += sizeof( struct V_222 ) *
( V_223 + 1 ) ;
V_197 = V_221 - V_196 ;
}
V_50 = F_121 ( V_9 , V_196 + V_197 , V_78 - V_197 ,
V_204 , & V_10 , 0 ) ;
if ( ! V_50 )
goto V_212;
if ( V_196 )
F_57 ( V_50 , V_196 ) ;
F_122 ( V_50 , V_197 ) ;
V_50 -> V_78 = V_78 ;
V_50 -> V_224 = V_78 - V_197 ;
V_10 = F_123 ( V_50 , 0 , & V_27 -> V_225 , V_78 ) ;
if ( V_10 )
goto V_226;
V_103 = F_100 ( V_9 , V_204 ) ;
V_10 = F_60 ( V_9 , F_17 ( V_9 ) , V_103 ) ;
if ( V_10 )
goto V_226;
if ( V_9 -> V_13 != V_16 ) {
V_10 = - V_109 ;
goto V_226;
}
V_198 . V_227 = V_7 -> V_122 ++ ;
F_124 ( V_50 ) -> V_227 = V_198 . V_227 ;
if ( V_7 -> V_35 == V_104 ) {
F_125 ( & V_7 -> V_39 ) ;
V_10 = F_27 ( & V_198 , V_9 , V_50 , 0 ) ;
if ( V_10 ) {
F_126 ( & V_7 -> V_39 ) ;
goto V_226;
}
} else {
F_35 ( & V_7 -> V_21 , V_50 ) ;
if ( ( ( V_7 -> V_37 -> V_29 & V_30 ) & V_7 -> V_29 ) &&
V_50 -> V_78 <= 7 ) {
V_10 = F_114 ( V_7 -> V_37 , & V_198 , V_50 ) ;
if ( V_10 == 0 ) {
F_38 ( V_50 , & V_7 -> V_21 ) ;
F_39 ( V_50 ) ;
}
if ( V_10 == 0x15 ) {
V_100 -> V_101 ( V_7 -> V_37 , NULL ) ;
F_38 ( V_50 , & V_7 -> V_21 ) ;
V_10 = - V_24 ;
goto V_226;
}
} else if ( F_127 ( V_50 ) ) {
struct V_222 * V_228 = (struct V_222 * ) V_50 -> V_55 ;
int V_229 ;
V_228 [ 0 ] . V_230 = ( V_231 ) ( V_232 ) V_50 -> V_193 ;
V_228 [ 0 ] . V_32 = ( V_231 ) F_128 ( V_50 ) ;
for ( V_229 = 0 ; V_229 < F_129 ( V_50 ) -> V_233 ; V_229 ++ ) {
T_4 * V_234 = & F_129 ( V_50 ) -> V_235 [ V_229 ] ;
V_228 [ V_229 + 1 ] . V_230 =
( V_231 ) ( V_232 ) F_130 ( V_234 ) ;
V_228 [ V_229 + 1 ] . V_32 = ( V_231 ) F_131 ( V_234 ) ;
}
V_10 = V_100 -> V_194 ( V_7 -> V_37 , & V_198 ,
V_236 , 0 ,
( void * ) V_228 , V_50 -> V_78 ) ;
} else {
V_10 = V_100 -> V_194 ( V_7 -> V_37 , & V_198 ,
0 , 0 , ( void * ) V_50 -> V_193 , V_50 -> V_78 ) ;
}
if ( V_10 ) {
if ( V_10 == 3 ) {
V_202 [ 8 ] = 0 ;
memcpy ( V_202 , V_7 -> V_66 , 8 ) ;
V_203 [ 8 ] = 0 ;
memcpy ( V_203 , V_7 -> V_68 , 8 ) ;
F_46 (
L_8 ,
V_203 , V_202 ) ;
V_10 = - V_173 ;
} else {
V_10 = - V_24 ;
}
F_38 ( V_50 , & V_7 -> V_21 ) ;
goto V_226;
}
}
F_62 ( V_9 ) ;
return V_78 ;
V_226:
F_39 ( V_50 ) ;
V_212:
F_62 ( V_9 ) ;
return V_10 ;
}
static struct V_49 * F_132 ( unsigned long V_78 )
{
T_1 V_196 , V_197 ;
struct V_49 * V_50 ;
int V_10 ;
if ( V_78 < V_221 ) {
V_196 = 0 ;
V_197 = V_78 ;
} else {
V_196 = sizeof( struct V_222 ) * ( V_223 + 1 ) ;
V_197 = V_221 - V_196 ;
}
V_50 = F_133 ( V_196 + V_197 , V_78 - V_197 ,
0 , & V_10 , V_84 | V_129 ) ;
F_134 ( ! V_50 ,
L_9 ,
V_78 , V_10 ) ;
if ( V_50 ) {
if ( V_196 )
F_57 ( V_50 , V_196 ) ;
F_122 ( V_50 , V_197 ) ;
V_50 -> V_78 = V_78 ;
V_50 -> V_224 = V_78 - V_197 ;
}
return V_50 ;
}
static void F_135 ( struct V_8 * V_9 , struct V_49 * V_50 ,
struct V_99 * V_37 ,
struct V_26 * V_27 )
{
int V_237 ;
unsigned int V_78 ;
V_78 = F_15 ( V_27 ) ;
F_124 ( V_50 ) -> V_214 = V_27 -> V_214 ;
if ( ( V_27 -> V_29 & V_30 ) && V_78 > 7 ) {
if ( memcmp ( V_27 -> V_31 , V_238 , 8 ) == 0 ) {
V_50 -> V_193 = NULL ;
V_50 -> V_78 = 0 ;
}
} else {
if ( F_127 ( V_50 ) ) {
struct V_222 * V_228 = (struct V_222 * ) V_50 -> V_55 ;
int V_229 ;
V_228 [ 0 ] . V_230 = ( V_231 ) ( V_232 ) V_50 -> V_193 ;
V_228 [ 0 ] . V_32 = ( V_231 ) F_128 ( V_50 ) ;
for ( V_229 = 0 ; V_229 < F_129 ( V_50 ) -> V_233 ; V_229 ++ ) {
T_4 * V_234 = & F_129 ( V_50 ) -> V_235 [ V_229 ] ;
V_228 [ V_229 + 1 ] . V_230 =
( V_231 ) ( V_232 ) F_130 ( V_234 ) ;
V_228 [ V_229 + 1 ] . V_32 = ( V_231 ) F_131 ( V_234 ) ;
}
V_237 = V_100 -> V_239 ( V_37 , V_27 ,
V_236 ,
( void * ) V_228 , V_78 , NULL ) ;
} else {
V_237 = V_100 -> V_239 ( V_37 , V_27 ,
V_27 -> V_29 & V_30 ,
V_50 -> V_193 , V_78 , NULL ) ;
}
if ( V_237 ) {
F_39 ( V_50 ) ;
return;
}
F_136 ( V_50 -> V_78 != V_78 ) ;
}
F_124 ( V_50 ) -> V_240 = 0 ;
if ( F_137 ( V_9 , V_50 ) )
F_138 ( & F_10 ( V_9 ) -> V_22 , V_50 ) ;
}
static void F_139 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_49 * V_50 ;
struct V_241 * V_242 , * V_144 ;
F_88 (p, n, &iucv->message_q.list, list) {
V_50 = F_132 ( F_15 ( & V_242 -> V_27 ) ) ;
if ( ! V_50 )
break;
F_135 ( V_9 , V_50 , V_242 -> V_37 , & V_242 -> V_27 ) ;
F_140 ( & V_242 -> V_121 ) ;
F_141 ( V_242 ) ;
if ( ! F_59 ( & V_7 -> V_22 ) )
break;
}
}
static int F_142 ( struct V_111 * V_8 , struct V_195 * V_27 ,
T_1 V_78 , int V_29 )
{
int V_204 = V_29 & V_206 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
unsigned int V_243 , V_244 ;
struct V_49 * V_50 , * V_245 , * V_246 ;
int V_10 = 0 ;
V_231 V_240 ;
if ( ( V_9 -> V_13 == V_14 ) &&
F_59 ( & V_7 -> V_22 ) &&
F_59 ( & V_9 -> V_87 ) &&
F_143 ( & V_7 -> V_120 . V_121 ) )
return 0 ;
if ( V_29 & ( V_207 ) )
return - V_208 ;
V_50 = F_144 ( V_9 , V_29 , V_204 , & V_10 ) ;
if ( ! V_50 ) {
if ( V_9 -> V_210 & V_247 )
return 0 ;
return V_10 ;
}
V_240 = F_124 ( V_50 ) -> V_240 ;
V_244 = V_50 -> V_78 - V_240 ;
V_243 = F_145 (unsigned int, rlen, len) ;
if ( ! V_244 )
V_9 -> V_210 = V_9 -> V_210 | V_247 ;
V_246 = V_50 ;
if ( F_146 ( V_246 , V_240 , V_27 , V_243 ) ) {
if ( ! ( V_29 & V_248 ) )
F_138 ( & V_9 -> V_87 , V_50 ) ;
return - V_249 ;
}
if ( V_9 -> V_80 == V_81 ) {
if ( V_243 < V_244 )
V_27 -> V_205 |= V_250 ;
V_27 -> V_205 |= V_209 ;
}
V_10 = F_147 ( V_27 , V_216 , V_218 ,
sizeof( F_124 ( V_50 ) -> V_214 ) ,
( void * ) & F_124 ( V_50 ) -> V_214 ) ;
if ( V_10 ) {
if ( ! ( V_29 & V_248 ) )
F_138 ( & V_9 -> V_87 , V_50 ) ;
return V_10 ;
}
if ( ! ( V_29 & V_248 ) ) {
if ( V_9 -> V_80 == V_134 ) {
if ( V_243 < V_244 ) {
F_124 ( V_50 ) -> V_240 = V_240 + V_243 ;
F_138 ( & V_9 -> V_87 , V_50 ) ;
goto V_158;
}
}
F_39 ( V_50 ) ;
if ( V_7 -> V_35 == V_104 ) {
F_125 ( & V_7 -> V_64 ) ;
if ( F_19 ( & V_7 -> V_64 ) > V_7 -> V_62 ) {
F_41 ( 1 ) ;
F_49 ( V_9 ) ;
return - V_249 ;
}
}
F_148 ( & V_7 -> V_120 . V_12 ) ;
V_245 = F_149 ( & V_7 -> V_22 ) ;
while ( V_245 ) {
F_124 ( V_245 ) -> V_240 = 0 ;
if ( F_137 ( V_9 , V_245 ) ) {
F_138 ( & V_7 -> V_22 ,
V_245 ) ;
break;
} else {
V_245 = F_149 ( & V_7 -> V_22 ) ;
}
}
if ( F_59 ( & V_7 -> V_22 ) ) {
if ( ! F_143 ( & V_7 -> V_120 . V_121 ) )
F_139 ( V_9 ) ;
if ( F_19 ( & V_7 -> V_64 ) >=
V_7 -> V_62 / 2 ) {
V_10 = F_55 ( V_9 , V_63 ) ;
if ( V_10 ) {
V_9 -> V_13 = V_14 ;
V_9 -> V_25 ( V_9 ) ;
}
}
}
F_150 ( & V_7 -> V_120 . V_12 ) ;
}
V_158:
if ( V_9 -> V_80 == V_81 && ( V_29 & V_250 ) )
V_243 = V_244 ;
return V_243 ;
}
static inline unsigned int F_151 ( struct V_8 * V_94 )
{
struct V_6 * V_143 , * V_144 ;
struct V_8 * V_9 ;
F_88 (isk, n, &iucv_sk(parent)->accept_q, accept_q) {
V_9 = (struct V_8 * ) V_143 ;
if ( V_9 -> V_13 == V_16 )
return V_251 | V_252 ;
}
return 0 ;
}
unsigned int F_152 ( struct V_253 * V_253 , struct V_111 * V_8 ,
T_5 * V_45 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
unsigned int V_254 = 0 ;
F_153 ( V_253 , F_107 ( V_9 ) , V_45 ) ;
if ( V_9 -> V_13 == V_19 )
return F_151 ( V_9 ) ;
if ( V_9 -> V_23 || ! F_59 ( & V_9 -> V_88 ) )
V_254 |= V_255 |
( F_45 ( V_9 , V_256 ) ? V_257 : 0 ) ;
if ( V_9 -> V_210 & V_247 )
V_254 |= V_258 ;
if ( V_9 -> V_210 == V_259 )
V_254 |= V_260 ;
if ( ! F_59 ( & V_9 -> V_87 ) ||
( V_9 -> V_210 & V_247 ) )
V_254 |= V_251 | V_252 ;
if ( V_9 -> V_13 == V_20 )
V_254 |= V_260 ;
if ( V_9 -> V_13 == V_14 )
V_254 |= V_251 ;
if ( F_154 ( V_9 ) && F_17 ( V_9 ) )
V_254 |= V_261 | V_262 | V_263 ;
else
F_155 ( V_264 , V_9 ) ;
return V_254 ;
}
static int F_156 ( struct V_111 * V_8 , int V_265 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_26 V_198 ;
int V_10 = 0 ;
V_265 ++ ;
if ( ( V_265 & ~ V_259 ) || ! V_265 )
return - V_156 ;
F_58 ( V_9 ) ;
switch ( V_9 -> V_13 ) {
case V_19 :
case V_14 :
case V_15 :
case V_20 :
V_10 = - V_213 ;
goto V_226;
default:
break;
}
if ( V_265 == V_211 || V_265 == V_259 ) {
if ( V_7 -> V_35 == V_36 ) {
V_198 . V_214 = 0 ;
V_198 . V_227 = 0 ;
V_10 = V_100 -> V_194 ( V_7 -> V_37 , & V_198 ,
V_30 , 0 , ( void * ) V_238 , 8 ) ;
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
F_55 ( V_9 , V_266 ) ;
}
V_9 -> V_210 |= V_265 ;
if ( V_265 == V_247 || V_265 == V_259 ) {
if ( ( V_7 -> V_35 == V_36 ) &&
V_7 -> V_37 ) {
V_10 = V_100 -> V_267 ( V_7 -> V_37 , NULL ) ;
if ( V_10 )
V_10 = - V_213 ;
}
F_12 ( & V_9 -> V_87 ) ;
}
V_9 -> V_25 ( V_9 ) ;
V_226:
F_62 ( V_9 ) ;
return V_10 ;
}
static int F_157 ( struct V_111 * V_8 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
int V_10 = 0 ;
if ( ! V_9 )
return 0 ;
F_49 ( V_9 ) ;
F_158 ( V_9 ) ;
F_50 ( V_9 ) ;
return V_10 ;
}
static int F_159 ( struct V_111 * V_8 , int V_268 , int V_269 ,
char T_6 * V_270 , unsigned int V_271 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
int V_272 ;
int V_237 ;
if ( V_268 != V_216 )
return - V_273 ;
if ( V_271 < sizeof( int ) )
return - V_156 ;
if ( F_160 ( V_272 , ( int T_6 * ) V_270 ) )
return - V_249 ;
V_237 = 0 ;
F_58 ( V_9 ) ;
switch ( V_269 ) {
case V_274 :
if ( V_272 )
V_7 -> V_29 |= V_30 ;
else
V_7 -> V_29 &= ~ V_30 ;
break;
case V_275 :
switch ( V_9 -> V_13 ) {
case V_17 :
case V_18 :
if ( V_272 < 1 || V_272 > ( V_276 ) ( ~ 0 ) )
V_237 = - V_156 ;
else
V_7 -> V_62 = V_272 ;
break;
default:
V_237 = - V_156 ;
break;
}
break;
default:
V_237 = - V_273 ;
break;
}
F_62 ( V_9 ) ;
return V_237 ;
}
static int F_161 ( struct V_111 * V_8 , int V_268 , int V_269 ,
char T_6 * V_270 , int T_6 * V_271 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
unsigned int V_272 ;
int V_78 ;
if ( V_268 != V_216 )
return - V_273 ;
if ( F_160 ( V_78 , V_271 ) )
return - V_249 ;
if ( V_78 < 0 )
return - V_156 ;
V_78 = F_145 (unsigned int, len, sizeof(int)) ;
switch ( V_269 ) {
case V_274 :
V_272 = ( V_7 -> V_29 & V_30 ) ? 1 : 0 ;
break;
case V_275 :
F_58 ( V_9 ) ;
V_272 = ( V_7 -> V_37 != NULL ) ? V_7 -> V_37 -> V_38
: V_7 -> V_62 ;
F_62 ( V_9 ) ;
break;
case V_277 :
if ( V_9 -> V_13 == V_17 )
return - V_157 ;
V_272 = ( V_7 -> V_74 ) ? V_7 -> V_74 -> V_79 -
sizeof( struct V_51 ) - V_56 :
0x7fffffff ;
break;
default:
return - V_273 ;
}
if ( F_162 ( V_78 , V_271 ) )
return - V_249 ;
if ( F_163 ( V_270 , & V_272 , V_78 ) )
return - V_249 ;
return 0 ;
}
static int F_164 ( struct V_99 * V_37 ,
T_2 V_278 [ 8 ] , T_2 V_279 [ 16 ] )
{
unsigned char V_98 [ 16 ] ;
unsigned char V_280 [ 16 ] ;
unsigned char V_72 [ 8 ] ;
struct V_8 * V_9 , * V_182 ;
struct V_6 * V_7 , * V_281 ;
int V_10 ;
memcpy ( V_72 , V_279 , 8 ) ;
F_165 ( V_72 , 8 ) ;
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
F_166 ( V_9 ) ;
F_2 ( V_98 , V_7 -> V_72 ) ;
F_1 ( V_98 , V_7 -> V_68 ) ;
F_31 ( V_98 , sizeof( V_98 ) ) ;
if ( V_9 -> V_13 != V_19 ) {
V_10 = V_100 -> V_101 ( V_37 , V_98 ) ;
F_54 ( V_37 ) ;
goto V_226;
}
if ( F_167 ( V_9 ) ) {
V_10 = V_100 -> V_101 ( V_37 , V_98 ) ;
F_54 ( V_37 ) ;
goto V_226;
}
V_182 = F_65 ( NULL , V_9 -> V_80 , V_84 , 0 ) ;
if ( ! V_182 ) {
V_10 = V_100 -> V_101 ( V_37 , V_98 ) ;
F_54 ( V_37 ) ;
goto V_226;
}
V_281 = F_10 ( V_182 ) ;
F_63 ( V_182 , V_9 ) ;
memcpy ( V_281 -> V_68 , V_279 + 8 , 8 ) ;
F_165 ( V_281 -> V_68 , 8 ) ;
memcpy ( V_281 -> V_66 , V_278 , 8 ) ;
memcpy ( V_281 -> V_72 , V_7 -> V_72 , 8 ) ;
memcpy ( V_281 -> V_70 , V_7 -> V_70 , 8 ) ;
V_281 -> V_37 = V_37 ;
F_1 ( V_280 , V_279 + 8 ) ;
memcpy ( V_280 + 8 , V_281 -> V_72 , 8 ) ;
F_31 ( V_280 + 8 , 8 ) ;
V_281 -> V_62 = V_7 -> V_62 ;
V_37 -> V_38 = V_7 -> V_62 ;
V_10 = V_100 -> V_282 ( V_37 , & V_171 , V_280 , V_182 ) ;
if ( V_10 ) {
F_11 ( V_182 , 1 ) ;
F_50 ( V_182 ) ;
goto V_226;
}
F_79 ( V_9 , V_182 ) ;
V_182 -> V_13 = V_16 ;
V_9 -> V_283 ( V_9 ) ;
V_10 = 0 ;
V_226:
F_168 ( V_9 ) ;
return 0 ;
}
static void F_169 ( struct V_99 * V_37 , T_2 V_279 [ 16 ] )
{
struct V_8 * V_9 = V_37 -> V_284 ;
V_9 -> V_13 = V_16 ;
V_9 -> V_25 ( V_9 ) ;
}
static void F_170 ( struct V_99 * V_37 , struct V_26 * V_27 )
{
struct V_8 * V_9 = V_37 -> V_284 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_49 * V_50 ;
struct V_241 * V_285 ;
int V_78 ;
if ( V_9 -> V_210 & V_247 ) {
V_100 -> V_286 ( V_37 , V_27 ) ;
return;
}
F_171 ( & V_7 -> V_120 . V_12 ) ;
if ( ! F_143 ( & V_7 -> V_120 . V_121 ) ||
! F_59 ( & V_7 -> V_22 ) )
goto V_287;
V_78 = F_19 ( & V_9 -> V_90 ) ;
V_78 += F_172 ( F_15 ( V_27 ) ) ;
if ( V_78 > V_9 -> V_288 )
goto V_287;
V_50 = F_132 ( F_15 ( V_27 ) ) ;
if ( ! V_50 )
goto V_287;
F_135 ( V_9 , V_50 , V_37 , V_27 ) ;
goto V_289;
V_287:
V_285 = F_173 ( sizeof( struct V_241 ) , V_84 | V_129 ) ;
if ( ! V_285 )
goto V_289;
V_285 -> V_37 = V_37 ;
V_285 -> V_27 = * V_27 ;
F_82 ( & V_285 -> V_121 , & V_7 -> V_120 . V_121 ) ;
V_289:
F_174 ( & V_7 -> V_120 . V_12 ) ;
}
static void F_175 ( struct V_99 * V_37 ,
struct V_26 * V_27 )
{
struct V_8 * V_9 = V_37 -> V_284 ;
struct V_49 * V_290 = NULL ;
struct V_291 * V_121 = & F_10 ( V_9 ) -> V_21 ;
struct V_49 * V_292 = V_121 -> V_293 ;
unsigned long V_29 ;
F_166 ( V_9 ) ;
if ( ! F_59 ( V_121 ) ) {
F_81 ( & V_121 -> V_12 , V_29 ) ;
while ( V_292 != (struct V_49 * ) V_121 ) {
if ( V_27 -> V_227 == F_124 ( V_292 ) -> V_227 ) {
V_290 = V_292 ;
break;
}
V_292 = V_292 -> V_293 ;
}
if ( V_290 )
F_176 ( V_290 , V_121 ) ;
F_83 ( & V_121 -> V_12 , V_29 ) ;
if ( V_290 ) {
F_39 ( V_290 ) ;
F_20 ( V_9 ) ;
}
}
if ( V_9 -> V_13 == V_15 ) {
if ( F_59 ( & F_10 ( V_9 ) -> V_21 ) ) {
V_9 -> V_13 = V_20 ;
V_9 -> V_25 ( V_9 ) ;
}
}
F_168 ( V_9 ) ;
}
static void F_177 ( struct V_99 * V_37 , T_2 V_279 [ 16 ] )
{
struct V_8 * V_9 = V_37 -> V_284 ;
if ( V_9 -> V_13 == V_20 )
return;
F_166 ( V_9 ) ;
F_11 ( V_9 , 1 ) ;
V_9 -> V_13 = V_14 ;
V_9 -> V_25 ( V_9 ) ;
F_168 ( V_9 ) ;
}
static void F_178 ( struct V_99 * V_37 , T_2 V_279 [ 16 ] )
{
struct V_8 * V_9 = V_37 -> V_284 ;
F_166 ( V_9 ) ;
if ( V_9 -> V_13 != V_20 ) {
V_9 -> V_210 |= V_211 ;
V_9 -> V_25 ( V_9 ) ;
}
F_168 ( V_9 ) ;
}
static void F_179 ( struct V_49 * V_50 )
{
struct V_51 * V_294 =
(struct V_51 * ) V_50 -> V_193 ;
char V_295 [ 8 ] ;
char V_296 [ 8 ] ;
F_31 ( V_294 -> V_65 , sizeof( V_294 -> V_65 ) ) ;
F_31 ( V_294 -> V_67 , sizeof( V_294 -> V_67 ) ) ;
F_31 ( V_294 -> V_69 , sizeof( V_294 -> V_69 ) ) ;
F_31 ( V_294 -> V_71 , sizeof( V_294 -> V_71 ) ) ;
memcpy ( V_295 , V_294 -> V_69 , 8 ) ;
memcpy ( V_296 , V_294 -> V_71 , 8 ) ;
memcpy ( V_294 -> V_69 , V_294 -> V_65 , 8 ) ;
memcpy ( V_294 -> V_71 , V_294 -> V_67 , 8 ) ;
memcpy ( V_294 -> V_65 , V_295 , 8 ) ;
memcpy ( V_294 -> V_67 , V_296 , 8 ) ;
F_28 ( V_50 , V_56 ) ;
memset ( V_50 -> V_193 , 0 , V_56 ) ;
}
static int F_180 ( struct V_8 * V_9 , struct V_49 * V_50 )
{
struct V_8 * V_182 ;
struct V_6 * V_7 , * V_281 ;
struct V_51 * V_294 ;
int V_10 ;
V_7 = F_10 ( V_9 ) ;
V_294 = (struct V_51 * ) V_50 -> V_193 ;
if ( ! V_7 ) {
F_179 ( V_50 ) ;
V_294 -> V_29 = V_60 | V_105 ;
V_10 = F_36 ( V_50 ) ;
goto V_212;
}
V_182 = F_65 ( NULL , V_9 -> V_80 , V_84 , 0 ) ;
F_166 ( V_9 ) ;
if ( ( V_9 -> V_13 != V_19 ) ||
F_167 ( V_9 ) ||
! V_182 ) {
F_179 ( V_50 ) ;
V_294 -> V_29 = V_60 | V_105 ;
V_10 = F_36 ( V_50 ) ;
F_50 ( V_182 ) ;
F_168 ( V_9 ) ;
goto V_212;
}
V_281 = F_10 ( V_182 ) ;
F_63 ( V_182 , V_9 ) ;
V_281 -> V_35 = V_104 ;
V_281 -> V_62 = V_7 -> V_62 ;
if ( ! V_294 -> V_61 )
V_281 -> V_40 = V_167 ;
else
V_281 -> V_40 = V_294 -> V_61 ;
memcpy ( V_281 -> V_68 , V_294 -> V_71 , 8 ) ;
memcpy ( V_281 -> V_66 , V_294 -> V_69 , 8 ) ;
memcpy ( V_281 -> V_72 , V_7 -> V_72 , 8 ) ;
memcpy ( V_281 -> V_70 , V_7 -> V_70 , 8 ) ;
V_182 -> V_110 = V_9 -> V_110 ;
V_281 -> V_74 = V_7 -> V_74 ;
F_94 ( V_281 -> V_74 ) ;
F_179 ( V_50 ) ;
V_294 -> V_29 = V_60 | V_297 ;
V_294 -> V_61 = V_281 -> V_62 ;
V_10 = F_36 ( V_50 ) ;
if ( ! V_10 ) {
F_79 ( V_9 , V_182 ) ;
V_182 -> V_13 = V_16 ;
V_9 -> V_283 ( V_9 ) ;
} else
F_50 ( V_182 ) ;
F_168 ( V_9 ) ;
V_212:
return V_298 ;
}
static int F_181 ( struct V_8 * V_9 , struct V_49 * V_50 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_51 * V_294 =
(struct V_51 * ) V_50 -> V_193 ;
if ( ! V_7 )
goto V_212;
if ( V_9 -> V_13 != V_18 )
goto V_212;
F_166 ( V_9 ) ;
V_7 -> V_40 = V_294 -> V_61 ;
V_9 -> V_13 = V_16 ;
V_9 -> V_25 ( V_9 ) ;
F_168 ( V_9 ) ;
V_212:
F_39 ( V_50 ) ;
return V_298 ;
}
static int F_182 ( struct V_8 * V_9 , struct V_49 * V_50 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
if ( ! V_7 )
goto V_212;
if ( V_9 -> V_13 != V_18 )
goto V_212;
F_166 ( V_9 ) ;
V_9 -> V_13 = V_14 ;
V_9 -> V_25 ( V_9 ) ;
F_168 ( V_9 ) ;
V_212:
F_39 ( V_50 ) ;
return V_298 ;
}
static int F_183 ( struct V_8 * V_9 , struct V_49 * V_50 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
if ( ! V_7 )
goto V_212;
F_166 ( V_9 ) ;
if ( V_9 -> V_13 == V_16 ) {
V_9 -> V_13 = V_14 ;
V_9 -> V_25 ( V_9 ) ;
}
F_168 ( V_9 ) ;
V_212:
F_39 ( V_50 ) ;
return V_298 ;
}
static int F_184 ( struct V_8 * V_9 , struct V_49 * V_50 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_51 * V_294 =
(struct V_51 * ) V_50 -> V_193 ;
if ( ! V_7 )
return V_298 ;
if ( V_9 -> V_13 != V_16 )
return V_298 ;
F_40 ( V_294 -> V_61 , & V_7 -> V_39 ) ;
F_20 ( V_9 ) ;
return V_298 ;
}
static int F_185 ( struct V_8 * V_9 , struct V_49 * V_50 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
if ( ! V_7 ) {
F_39 ( V_50 ) ;
return V_298 ;
}
if ( V_9 -> V_13 != V_16 ) {
F_39 ( V_50 ) ;
return V_298 ;
}
if ( V_9 -> V_210 & V_247 ) {
F_39 ( V_50 ) ;
return V_298 ;
}
F_186 ( V_50 , sizeof( struct V_51 ) ) ;
F_187 ( V_50 ) ;
F_30 ( V_50 ) ;
F_124 ( V_50 ) -> V_240 = 0 ;
F_171 ( & V_7 -> V_120 . V_12 ) ;
if ( F_59 ( & V_7 -> V_22 ) ) {
if ( F_137 ( V_9 , V_50 ) ) {
F_35 ( & V_7 -> V_22 , V_50 ) ;
}
} else
F_35 ( & F_10 ( V_9 ) -> V_22 , V_50 ) ;
F_174 ( & V_7 -> V_120 . V_12 ) ;
return V_298 ;
}
static int F_188 ( struct V_49 * V_50 , struct V_152 * V_4 ,
struct V_299 * V_300 , struct V_152 * V_301 )
{
struct V_8 * V_9 ;
struct V_6 * V_7 ;
struct V_51 * V_294 ;
char V_302 [ 8 ] ;
int V_10 = 0 ;
if ( V_50 -> V_78 < ( V_56 + sizeof( struct V_51 ) ) ) {
F_134 ( 1 , L_10 ,
( int ) V_50 -> V_78 ,
( int ) ( V_56 + sizeof( struct V_51 ) ) ) ;
F_39 ( V_50 ) ;
return V_298 ;
}
if ( F_128 ( V_50 ) < ( V_56 + sizeof( struct V_51 ) ) )
if ( F_189 ( V_50 ) ) {
F_134 ( 1 , L_11 ,
( int ) V_50 -> V_78 ) ;
F_39 ( V_50 ) ;
return V_298 ;
}
F_186 ( V_50 , V_56 ) ;
V_294 = (struct V_51 * ) V_50 -> V_193 ;
F_165 ( V_294 -> V_67 , sizeof( V_294 -> V_67 ) ) ;
F_165 ( V_294 -> V_65 , sizeof( V_294 -> V_65 ) ) ;
F_165 ( V_294 -> V_71 , sizeof( V_294 -> V_71 ) ) ;
F_165 ( V_294 -> V_69 , sizeof( V_294 -> V_69 ) ) ;
memset ( V_302 , 0 , sizeof( V_302 ) ) ;
V_7 = NULL ;
V_9 = NULL ;
F_8 ( & V_11 . V_12 ) ;
F_9 (sk, &iucv_sk_list.head) {
if ( V_294 -> V_29 == V_60 ) {
if ( ( ! memcmp ( & F_10 ( V_9 ) -> V_72 ,
V_294 -> V_67 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_70 ,
V_294 -> V_65 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_68 , V_302 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_66 ,
V_302 , 8 ) ) ) {
V_7 = F_10 ( V_9 ) ;
break;
}
} else {
if ( ( ! memcmp ( & F_10 ( V_9 ) -> V_72 ,
V_294 -> V_67 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_70 ,
V_294 -> V_65 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_68 ,
V_294 -> V_71 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_66 ,
V_294 -> V_69 , 8 ) ) ) {
V_7 = F_10 ( V_9 ) ;
break;
}
}
}
F_13 ( & V_11 . V_12 ) ;
if ( ! V_7 )
V_9 = NULL ;
switch ( V_294 -> V_29 ) {
case V_60 :
V_10 = F_180 ( V_9 , V_50 ) ;
break;
case ( V_60 | V_297 ) :
V_10 = F_181 ( V_9 , V_50 ) ;
break;
case ( V_60 | V_105 ) :
V_10 = F_182 ( V_9 , V_50 ) ;
break;
case ( V_105 ) :
V_10 = F_183 ( V_9 , V_50 ) ;
break;
case ( V_63 ) :
V_10 = F_184 ( V_9 , V_50 ) ;
if ( V_50 -> V_78 == sizeof( struct V_51 ) ) {
F_39 ( V_50 ) ;
break;
}
case ( V_266 ) :
case 0 :
F_124 ( V_50 ) -> V_214 = V_294 -> V_73 . V_214 ;
V_10 = F_185 ( V_9 , V_50 ) ;
break;
default:
;
}
return V_10 ;
}
static void V_124 ( struct V_49 * V_50 ,
enum V_303 V_144 )
{
struct V_8 * V_143 = V_50 -> V_9 ;
struct V_8 * V_9 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_291 * V_121 ;
struct V_49 * V_292 ;
struct V_49 * V_53 ;
unsigned long V_29 ;
F_190 ( & V_11 . V_12 , V_29 ) ;
F_9 (sk, &iucv_sk_list.head)
if ( V_9 == V_143 ) {
V_7 = F_10 ( V_9 ) ;
break;
}
F_191 ( & V_11 . V_12 , V_29 ) ;
if ( ! V_7 || F_45 ( V_9 , V_95 ) )
return;
V_121 = & V_7 -> V_21 ;
F_81 ( & V_121 -> V_12 , V_29 ) ;
if ( F_59 ( V_121 ) )
goto V_289;
V_292 = V_121 -> V_293 ;
V_53 = V_292 -> V_293 ;
while ( V_292 != (struct V_49 * ) V_121 ) {
if ( F_129 ( V_292 ) == F_129 ( V_50 ) ) {
switch ( V_144 ) {
case V_304 :
F_176 ( V_292 , V_121 ) ;
F_39 ( V_292 ) ;
F_20 ( V_9 ) ;
break;
case V_305 :
F_125 ( & V_7 -> V_41 ) ;
break;
case V_306 :
F_176 ( V_292 , V_121 ) ;
F_126 ( & V_7 -> V_41 ) ;
if ( F_19 ( & V_7 -> V_41 ) <= 0 )
F_20 ( V_9 ) ;
F_39 ( V_292 ) ;
break;
case V_307 :
case V_308 :
case V_309 :
case V_310 :
case V_311 :
F_176 ( V_292 , V_121 ) ;
F_39 ( V_292 ) ;
if ( V_9 -> V_13 == V_16 ) {
V_9 -> V_13 = V_14 ;
V_9 -> V_25 ( V_9 ) ;
}
break;
}
break;
}
V_292 = V_53 ;
V_53 = V_53 -> V_293 ;
}
V_289:
F_83 ( & V_121 -> V_12 , V_29 ) ;
if ( V_9 -> V_13 == V_15 ) {
if ( F_59 ( & F_10 ( V_9 ) -> V_21 ) ) {
V_9 -> V_13 = V_20 ;
V_9 -> V_25 ( V_9 ) ;
}
}
}
static int F_192 ( struct V_312 * V_290 ,
unsigned long V_313 , void * V_314 )
{
struct V_152 * V_315 = F_193 ( V_314 ) ;
struct V_8 * V_9 ;
struct V_6 * V_7 ;
switch ( V_313 ) {
case V_316 :
case V_317 :
F_9 (sk, &iucv_sk_list.head) {
V_7 = F_10 ( V_9 ) ;
if ( ( V_7 -> V_74 == V_315 ) &&
( V_9 -> V_13 == V_16 ) ) {
if ( V_313 == V_317 )
F_55 ( V_9 , V_105 ) ;
V_9 -> V_13 = V_14 ;
V_9 -> V_25 ( V_9 ) ;
}
}
break;
case V_318 :
case V_319 :
default:
break;
}
return V_320 ;
}
static int F_194 ( void )
{
int V_10 ;
V_10 = V_100 -> V_321 ( & V_171 , 0 ) ;
if ( V_10 )
goto V_212;
V_322 . V_323 = V_100 -> V_323 ;
V_10 = F_195 ( & V_322 ) ;
if ( V_10 )
goto V_324;
V_325 = F_173 ( sizeof( struct V_3 ) , V_138 ) ;
if ( ! V_325 ) {
V_10 = - V_85 ;
goto V_326;
}
F_196 ( V_325 , L_12 ) ;
V_325 -> V_323 = V_100 -> V_323 ;
V_325 -> V_94 = V_100 -> V_327 ;
V_325 -> V_328 = ( void ( * ) ( struct V_3 * ) ) F_141 ;
V_325 -> V_329 = & V_322 ;
V_10 = F_197 ( V_325 ) ;
if ( V_10 )
goto V_326;
return 0 ;
V_326:
F_198 ( & V_322 ) ;
V_324:
V_100 -> V_330 ( & V_171 , 0 ) ;
V_212:
return V_10 ;
}
static int T_7 F_199 ( void )
{
int V_10 ;
if ( V_331 ) {
F_200 ( L_13 , V_163 , sizeof( V_163 ) , & V_10 ) ;
if ( F_96 ( V_10 ) ) {
F_41 ( V_10 ) ;
V_10 = - V_132 ;
goto V_212;
}
V_100 = F_201 ( F_202 ( V_332 ) , L_14 ) ;
if ( ! V_100 ) {
F_5 ( V_5 L_15 ) ;
memset ( & V_163 , 0 , sizeof( V_163 ) ) ;
}
} else {
memset ( & V_163 , 0 , sizeof( V_163 ) ) ;
V_100 = NULL ;
}
V_10 = F_203 ( & V_117 , 0 ) ;
if ( V_10 )
goto V_212;
V_10 = F_204 ( & V_333 ) ;
if ( V_10 )
goto V_334;
if ( V_100 ) {
V_10 = F_194 () ;
if ( V_10 )
goto V_335;
} else
F_205 ( & V_336 ) ;
F_206 ( & V_337 ) ;
return 0 ;
V_335:
F_207 ( V_116 ) ;
V_334:
F_208 ( & V_117 ) ;
V_212:
if ( V_100 )
F_209 ( V_332 ) ;
return V_10 ;
}
static void T_8 F_210 ( void )
{
if ( V_100 ) {
F_211 ( V_325 ) ;
F_198 ( & V_322 ) ;
V_100 -> V_330 ( & V_171 , 0 ) ;
F_209 ( V_332 ) ;
} else
F_212 ( & V_336 ) ;
F_213 ( & V_337 ) ;
F_207 ( V_116 ) ;
F_208 ( & V_117 ) ;
}
