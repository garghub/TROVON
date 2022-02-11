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
static int F_89 ( struct V_111 * V_8 , struct V_145 * V_146 ,
int V_147 )
{
struct V_148 * V_149 = (struct V_148 * ) V_146 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 ;
int V_10 = 0 ;
struct V_150 * V_4 ;
char V_151 [ 9 ] ;
if ( ! V_146 || V_146 -> V_152 != V_153 )
return - V_154 ;
F_58 ( V_9 ) ;
if ( V_9 -> V_13 != V_17 ) {
V_10 = - V_155 ;
goto V_156;
}
F_74 ( & V_11 . V_12 ) ;
V_7 = F_10 ( V_9 ) ;
if ( F_42 ( V_149 -> V_157 ) ) {
V_10 = - V_158 ;
goto V_159;
}
if ( V_7 -> V_37 )
goto V_159;
if ( V_100 )
if ( ! memcmp ( V_149 -> V_160 , V_161 , 8 ) )
goto V_162;
memcpy ( V_151 , V_149 -> V_160 , sizeof( V_151 ) ) ;
F_31 ( V_151 , 8 ) ;
F_21 () ;
F_90 (&init_net, dev) {
if ( ! memcmp ( V_4 -> V_163 , V_151 , 8 ) ) {
memcpy ( V_7 -> V_72 , V_149 -> V_157 , 8 ) ;
memcpy ( V_7 -> V_70 , V_149 -> V_160 , 8 ) ;
V_9 -> V_110 = V_4 -> V_164 ;
V_7 -> V_74 = V_4 ;
F_91 ( V_4 ) ;
V_9 -> V_13 = V_18 ;
V_7 -> V_35 = V_104 ;
if ( ! V_7 -> V_62 )
V_7 -> V_62 = V_165 ;
F_26 () ;
goto V_159;
}
}
F_26 () ;
V_162:
if ( V_100 ) {
memcpy ( V_7 -> V_72 , V_149 -> V_157 , 8 ) ;
memcpy ( V_7 -> V_70 , V_161 , 8 ) ;
V_9 -> V_13 = V_18 ;
V_7 -> V_35 = V_36 ;
if ( ! V_7 -> V_62 )
V_7 -> V_62 = V_166 ;
goto V_159;
}
V_10 = - V_75 ;
V_159:
F_76 ( & V_11 . V_12 ) ;
V_156:
F_62 ( V_9 ) ;
return V_10 ;
}
static int F_92 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
char V_167 [ 12 ] ;
int V_10 = 0 ;
if ( F_93 ( ! V_100 ) )
return - V_168 ;
memcpy ( V_7 -> V_70 , V_161 , 8 ) ;
F_74 ( & V_11 . V_12 ) ;
sprintf ( V_167 , L_6 , F_94 ( & V_11 . V_169 ) ) ;
while ( F_42 ( V_167 ) ) {
sprintf ( V_167 , L_6 ,
F_94 ( & V_11 . V_169 ) ) ;
}
F_76 ( & V_11 . V_12 ) ;
memcpy ( & V_7 -> V_72 , V_167 , 8 ) ;
if ( ! V_7 -> V_62 )
V_7 -> V_62 = V_166 ;
return V_10 ;
}
static int F_95 ( struct V_111 * V_8 , struct V_145 * V_146 )
{
struct V_148 * V_149 = (struct V_148 * ) V_146 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
unsigned char V_98 [ 16 ] ;
int V_10 ;
F_1 ( V_98 , V_149 -> V_157 ) ;
F_2 ( V_98 , V_7 -> V_72 ) ;
F_31 ( V_98 , sizeof( V_98 ) ) ;
V_7 -> V_37 = F_96 ( V_7 -> V_62 ,
V_30 , V_138 ) ;
if ( ! V_7 -> V_37 ) {
V_10 = - V_85 ;
goto V_156;
}
V_10 = V_100 -> V_170 ( V_7 -> V_37 , & V_171 ,
V_149 -> V_160 , NULL , V_98 ,
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
V_156:
return V_10 ;
}
static int F_97 ( struct V_111 * V_8 , struct V_145 * V_146 ,
int V_176 , int V_29 )
{
struct V_148 * V_149 = (struct V_148 * ) V_146 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
int V_10 ;
if ( V_146 -> V_152 != V_153 || V_176 < sizeof( struct V_148 ) )
return - V_154 ;
if ( V_9 -> V_13 != V_17 && V_9 -> V_13 != V_18 )
return - V_155 ;
if ( V_9 -> V_13 == V_17 &&
V_7 -> V_35 == V_104 )
return - V_155 ;
if ( V_9 -> V_80 != V_134 && V_9 -> V_80 != V_81 )
return - V_154 ;
if ( V_9 -> V_13 == V_17 ) {
V_10 = F_92 ( V_9 ) ;
if ( F_93 ( V_10 ) )
return V_10 ;
}
F_58 ( V_9 ) ;
memcpy ( V_7 -> V_66 , V_149 -> V_160 , 8 ) ;
memcpy ( V_7 -> V_68 , V_149 -> V_157 , 8 ) ;
if ( V_7 -> V_35 == V_104 )
V_10 = F_55 ( V_8 -> V_9 , V_60 ) ;
else
V_10 = F_95 ( V_8 , V_146 ) ;
if ( V_10 )
goto V_156;
if ( V_9 -> V_13 != V_16 )
V_10 = F_60 ( V_9 , F_16 ( V_9 , V_16 ,
V_14 ) ,
F_98 ( V_9 , V_29 & V_177 ) ) ;
if ( V_9 -> V_13 == V_14 || V_9 -> V_13 == V_20 )
V_10 = - V_175 ;
if ( V_10 && V_7 -> V_35 == V_36 )
F_11 ( V_9 , 0 ) ;
V_156:
F_62 ( V_9 ) ;
return V_10 ;
}
static int F_99 ( struct V_111 * V_8 , int V_178 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
int V_10 ;
F_58 ( V_9 ) ;
V_10 = - V_154 ;
if ( V_9 -> V_13 != V_18 )
goto V_156;
if ( V_8 -> type != V_134 && V_8 -> type != V_81 )
goto V_156;
V_9 -> V_179 = V_178 ;
V_9 -> V_180 = 0 ;
V_9 -> V_13 = V_19 ;
V_10 = 0 ;
V_156:
F_62 ( V_9 ) ;
return V_10 ;
}
static int F_100 ( struct V_111 * V_8 , struct V_111 * V_142 ,
int V_29 )
{
F_101 ( V_45 , V_181 ) ;
struct V_8 * V_9 = V_8 -> V_9 , * V_182 ;
long V_103 ;
int V_10 = 0 ;
F_102 ( V_9 , V_183 ) ;
if ( V_9 -> V_13 != V_19 ) {
V_10 = - V_155 ;
goto V_156;
}
V_103 = F_103 ( V_9 , V_29 & V_177 ) ;
F_104 ( F_105 ( V_9 ) , & V_45 ) ;
while ( ! ( V_182 = F_48 ( V_9 , V_142 ) ) ) {
F_106 ( V_184 ) ;
if ( ! V_103 ) {
V_10 = - V_173 ;
break;
}
F_62 ( V_9 ) ;
V_103 = F_107 ( V_103 ) ;
F_102 ( V_9 , V_183 ) ;
if ( V_9 -> V_13 != V_19 ) {
V_10 = - V_155 ;
break;
}
if ( F_108 ( V_181 ) ) {
V_10 = F_109 ( V_103 ) ;
break;
}
}
F_106 ( V_185 ) ;
F_110 ( F_105 ( V_9 ) , & V_45 ) ;
if ( V_10 )
goto V_156;
V_142 -> V_33 = V_186 ;
V_156:
F_62 ( V_9 ) ;
return V_10 ;
}
static int F_111 ( struct V_111 * V_8 , struct V_145 * V_146 ,
int * V_78 , int V_187 )
{
struct V_148 * V_188 = (struct V_148 * ) V_146 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
V_146 -> V_152 = V_153 ;
* V_78 = sizeof( struct V_148 ) ;
if ( V_187 ) {
memcpy ( V_188 -> V_160 , V_7 -> V_66 , 8 ) ;
memcpy ( V_188 -> V_157 , V_7 -> V_68 , 8 ) ;
} else {
memcpy ( V_188 -> V_160 , V_7 -> V_70 , 8 ) ;
memcpy ( V_188 -> V_157 , V_7 -> V_72 , 8 ) ;
}
memset ( & V_188 -> V_189 , 0 , sizeof( V_188 -> V_189 ) ) ;
memset ( & V_188 -> V_190 , 0 , sizeof( V_188 -> V_190 ) ) ;
memset ( & V_188 -> V_191 , 0 , sizeof( V_188 -> V_191 ) ) ;
return 0 ;
}
static int F_112 ( struct V_99 * V_37 , struct V_26 * V_27 ,
struct V_49 * V_50 )
{
T_2 V_192 [ 8 ] ;
memcpy ( V_192 , ( void * ) V_50 -> V_193 , V_50 -> V_78 ) ;
V_192 [ 7 ] = 0xff - ( T_2 ) V_50 -> V_78 ;
return V_100 -> V_194 ( V_37 , V_27 , V_30 , 0 ,
( void * ) V_192 , 8 ) ;
}
static int F_113 ( struct V_195 * V_196 , struct V_111 * V_8 ,
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
V_10 = F_114 ( V_9 ) ;
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
for ( V_200 = F_115 ( V_27 ) ; V_200 ;
V_200 = F_116 ( V_27 , V_200 ) ) {
if ( ! F_117 ( V_27 , V_200 ) ) {
V_10 = - V_154 ;
goto V_212;
}
if ( V_200 -> V_215 != V_216 )
continue;
if ( V_200 -> V_217 & V_201 ) {
V_10 = - V_154 ;
goto V_212;
}
V_201 |= V_200 -> V_217 ;
switch ( V_200 -> V_217 ) {
case V_218 :
if ( V_200 -> V_219 != F_118 ( V_220 ) ) {
V_10 = - V_154 ;
goto V_212;
}
memcpy ( & V_198 . V_214 ,
( void * ) F_119 ( V_200 ) , V_220 ) ;
break;
default:
V_10 = - V_154 ;
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
if ( F_120 ( F_121 ( V_50 , V_78 ) , V_27 -> V_221 , V_78 ) ) {
V_10 = - V_222 ;
goto V_223;
}
V_103 = F_98 ( V_9 , V_204 ) ;
V_10 = F_60 ( V_9 , F_17 ( V_9 ) , V_103 ) ;
if ( V_10 )
goto V_223;
if ( V_9 -> V_13 != V_16 ) {
V_10 = - V_109 ;
goto V_223;
}
V_198 . V_224 = V_7 -> V_121 ++ ;
F_122 ( V_50 ) -> V_224 = V_198 . V_224 ;
if ( V_7 -> V_35 == V_104 ) {
F_123 ( & V_7 -> V_39 ) ;
V_10 = F_27 ( & V_198 , V_9 , V_50 , 0 ) ;
if ( V_10 ) {
F_124 ( & V_7 -> V_39 ) ;
goto V_223;
}
goto V_225;
}
F_35 ( & V_7 -> V_21 , V_50 ) ;
if ( ( ( V_7 -> V_37 -> V_29 & V_30 ) & V_7 -> V_29 )
&& V_50 -> V_78 <= 7 ) {
V_10 = F_112 ( V_7 -> V_37 , & V_198 , V_50 ) ;
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
F_46 ( L_7
L_8 ,
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
static int F_125 ( struct V_8 * V_9 , struct V_49 * V_50 , int V_78 )
{
int V_226 , V_227 , V_228 = 0 ;
struct V_49 * V_53 ;
V_226 = V_78 ;
while ( V_226 ) {
if ( V_226 >= V_9 -> V_229 / 4 )
V_227 = V_9 -> V_229 / 4 ;
else
V_227 = V_226 ;
V_53 = F_126 ( V_227 , V_84 | V_128 ) ;
if ( ! V_53 )
return - V_85 ;
F_122 ( V_53 ) -> V_214 = F_122 ( V_50 ) -> V_214 ;
memcpy ( V_53 -> V_193 , V_50 -> V_193 + V_228 , V_227 ) ;
V_228 += V_227 ;
V_226 -= V_227 ;
F_127 ( V_53 ) ;
F_30 ( V_53 ) ;
V_53 -> V_78 = V_227 ;
F_35 ( & F_10 ( V_9 ) -> V_22 , V_53 ) ;
}
return 0 ;
}
static void F_128 ( struct V_8 * V_9 , struct V_49 * V_50 ,
struct V_99 * V_37 ,
struct V_26 * V_27 )
{
int V_230 ;
unsigned int V_78 ;
V_78 = F_15 ( V_27 ) ;
F_122 ( V_50 ) -> V_214 = V_27 -> V_214 ;
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
V_230 = F_125 ( V_9 , V_50 , V_78 ) ;
F_39 ( V_50 ) ;
V_50 = NULL ;
if ( V_230 ) {
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
F_122 ( V_50 ) -> V_234 = 0 ;
if ( F_130 ( V_9 , V_50 ) )
F_131 ( & F_10 ( V_9 ) -> V_22 , V_50 ) ;
}
static void F_132 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_49 * V_50 ;
struct V_235 * V_236 , * V_144 ;
F_87 (p, n, &iucv->message_q.list, list) {
V_50 = F_126 ( F_15 ( & V_236 -> V_27 ) , V_84 | V_128 ) ;
if ( ! V_50 )
break;
F_128 ( V_9 , V_50 , V_236 -> V_37 , & V_236 -> V_27 ) ;
F_133 ( & V_236 -> V_120 ) ;
F_134 ( V_236 ) ;
if ( ! F_59 ( & V_7 -> V_22 ) )
break;
}
}
static int F_135 ( struct V_195 * V_196 , struct V_111 * V_8 ,
struct V_197 * V_27 , T_1 V_78 , int V_29 )
{
int V_204 = V_29 & V_206 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
unsigned int V_228 , V_237 ;
struct V_49 * V_50 , * V_238 , * V_239 ;
int V_10 = 0 ;
T_4 V_234 ;
V_27 -> V_240 = 0 ;
if ( ( V_9 -> V_13 == V_14 ) &&
F_59 ( & V_7 -> V_22 ) &&
F_59 ( & V_9 -> V_87 ) &&
F_136 ( & V_7 -> V_119 . V_120 ) )
return 0 ;
if ( V_29 & ( V_207 ) )
return - V_208 ;
V_50 = F_137 ( V_9 , V_29 , V_204 , & V_10 ) ;
if ( ! V_50 ) {
if ( V_9 -> V_210 & V_241 )
return 0 ;
return V_10 ;
}
V_234 = F_122 ( V_50 ) -> V_234 ;
V_237 = V_50 -> V_78 - V_234 ;
V_228 = F_138 (unsigned int, rlen, len) ;
if ( ! V_237 )
V_9 -> V_210 = V_9 -> V_210 | V_241 ;
V_239 = V_50 ;
if ( F_139 ( V_239 , V_234 , V_27 -> V_221 , V_228 ) ) {
if ( ! ( V_29 & V_242 ) )
F_131 ( & V_9 -> V_87 , V_50 ) ;
return - V_222 ;
}
if ( V_9 -> V_80 == V_81 ) {
if ( V_228 < V_237 )
V_27 -> V_205 |= V_243 ;
V_27 -> V_205 |= V_209 ;
}
V_10 = F_140 ( V_27 , V_216 , V_218 ,
sizeof( F_122 ( V_50 ) -> V_214 ) ,
( void * ) & F_122 ( V_50 ) -> V_214 ) ;
if ( V_10 ) {
if ( ! ( V_29 & V_242 ) )
F_131 ( & V_9 -> V_87 , V_50 ) ;
return V_10 ;
}
if ( ! ( V_29 & V_242 ) ) {
if ( V_9 -> V_80 == V_134 ) {
if ( V_228 < V_237 ) {
F_122 ( V_50 ) -> V_234 = V_234 + V_228 ;
goto V_156;
}
}
F_39 ( V_50 ) ;
if ( V_7 -> V_35 == V_104 ) {
F_123 ( & V_7 -> V_64 ) ;
if ( F_19 ( & V_7 -> V_64 ) > V_7 -> V_62 ) {
F_41 ( 1 ) ;
F_49 ( V_9 ) ;
return - V_222 ;
}
}
F_141 ( & V_7 -> V_119 . V_12 ) ;
V_238 = F_129 ( & V_7 -> V_22 ) ;
while ( V_238 ) {
F_122 ( V_238 ) -> V_234 = 0 ;
if ( F_130 ( V_9 , V_238 ) ) {
F_131 ( & V_7 -> V_22 ,
V_238 ) ;
break;
} else {
V_238 = F_129 ( & V_7 -> V_22 ) ;
}
}
if ( F_59 ( & V_7 -> V_22 ) ) {
if ( ! F_136 ( & V_7 -> V_119 . V_120 ) )
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
F_142 ( & V_7 -> V_119 . V_12 ) ;
}
V_156:
if ( V_9 -> V_80 == V_81 && ( V_29 & V_243 ) )
V_228 = V_237 ;
return V_228 ;
}
static inline unsigned int F_143 ( struct V_8 * V_94 )
{
struct V_6 * V_143 , * V_144 ;
struct V_8 * V_9 ;
F_87 (isk, n, &iucv_sk(parent)->accept_q, accept_q) {
V_9 = (struct V_8 * ) V_143 ;
if ( V_9 -> V_13 == V_16 )
return V_244 | V_245 ;
}
return 0 ;
}
unsigned int F_144 ( struct V_246 * V_246 , struct V_111 * V_8 ,
T_5 * V_45 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
unsigned int V_247 = 0 ;
F_145 ( V_246 , F_105 ( V_9 ) , V_45 ) ;
if ( V_9 -> V_13 == V_19 )
return F_143 ( V_9 ) ;
if ( V_9 -> V_23 || ! F_59 ( & V_9 -> V_88 ) )
V_247 |= V_248 |
( F_45 ( V_9 , V_249 ) ? V_250 : 0 ) ;
if ( V_9 -> V_210 & V_241 )
V_247 |= V_251 ;
if ( V_9 -> V_210 == V_252 )
V_247 |= V_253 ;
if ( ! F_59 ( & V_9 -> V_87 ) ||
( V_9 -> V_210 & V_241 ) )
V_247 |= V_244 | V_245 ;
if ( V_9 -> V_13 == V_20 )
V_247 |= V_253 ;
if ( V_9 -> V_13 == V_14 )
V_247 |= V_244 ;
if ( F_146 ( V_9 ) && F_17 ( V_9 ) )
V_247 |= V_254 | V_255 | V_256 ;
else
F_147 ( V_257 , & V_9 -> V_96 -> V_29 ) ;
return V_247 ;
}
static int F_148 ( struct V_111 * V_8 , int V_258 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_26 V_198 ;
int V_10 = 0 ;
V_258 ++ ;
if ( ( V_258 & ~ V_252 ) || ! V_258 )
return - V_154 ;
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
if ( V_258 == V_211 || V_258 == V_252 ) {
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
F_55 ( V_9 , V_259 ) ;
}
V_9 -> V_210 |= V_258 ;
if ( V_258 == V_241 || V_258 == V_252 ) {
if ( V_7 -> V_35 == V_36 ) {
V_10 = V_100 -> V_260 ( V_7 -> V_37 , NULL ) ;
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
static int F_151 ( struct V_111 * V_8 , int V_261 , int V_262 ,
char T_6 * V_263 , unsigned int V_264 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
int V_265 ;
int V_230 ;
if ( V_261 != V_216 )
return - V_266 ;
if ( V_264 < sizeof( int ) )
return - V_154 ;
if ( F_152 ( V_265 , ( int T_6 * ) V_263 ) )
return - V_222 ;
V_230 = 0 ;
F_58 ( V_9 ) ;
switch ( V_262 ) {
case V_267 :
if ( V_265 )
V_7 -> V_29 |= V_30 ;
else
V_7 -> V_29 &= ~ V_30 ;
break;
case V_268 :
switch ( V_9 -> V_13 ) {
case V_17 :
case V_18 :
if ( V_265 < 1 || V_265 > ( V_269 ) ( ~ 0 ) )
V_230 = - V_154 ;
else
V_7 -> V_62 = V_265 ;
break;
default:
V_230 = - V_154 ;
break;
}
break;
default:
V_230 = - V_266 ;
break;
}
F_62 ( V_9 ) ;
return V_230 ;
}
static int F_153 ( struct V_111 * V_8 , int V_261 , int V_262 ,
char T_6 * V_263 , int T_6 * V_264 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
unsigned int V_265 ;
int V_78 ;
if ( V_261 != V_216 )
return - V_266 ;
if ( F_152 ( V_78 , V_264 ) )
return - V_222 ;
if ( V_78 < 0 )
return - V_154 ;
V_78 = F_138 (unsigned int, len, sizeof(int)) ;
switch ( V_262 ) {
case V_267 :
V_265 = ( V_7 -> V_29 & V_30 ) ? 1 : 0 ;
break;
case V_268 :
F_58 ( V_9 ) ;
V_265 = ( V_7 -> V_37 != NULL ) ? V_7 -> V_37 -> V_38
: V_7 -> V_62 ;
F_62 ( V_9 ) ;
break;
case V_270 :
if ( V_9 -> V_13 == V_17 )
return - V_155 ;
V_265 = ( V_7 -> V_74 ) ? V_7 -> V_74 -> V_79 -
sizeof( struct V_51 ) - V_56 :
0x7fffffff ;
break;
default:
return - V_266 ;
}
if ( F_154 ( V_78 , V_264 ) )
return - V_222 ;
if ( F_155 ( V_263 , & V_265 , V_78 ) )
return - V_222 ;
return 0 ;
}
static int F_156 ( struct V_99 * V_37 ,
T_2 V_271 [ 8 ] , T_2 V_272 [ 16 ] )
{
unsigned char V_98 [ 16 ] ;
unsigned char V_273 [ 16 ] ;
unsigned char V_72 [ 8 ] ;
struct V_8 * V_9 , * V_182 ;
struct V_6 * V_7 , * V_274 ;
int V_10 ;
memcpy ( V_72 , V_272 , 8 ) ;
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
return - V_154 ;
F_158 ( V_9 ) ;
F_2 ( V_98 , V_7 -> V_72 ) ;
F_1 ( V_98 , V_7 -> V_68 ) ;
F_31 ( V_98 , sizeof( V_98 ) ) ;
if ( V_9 -> V_13 != V_19 ) {
V_10 = V_100 -> V_101 ( V_37 , V_98 ) ;
F_54 ( V_37 ) ;
goto V_223;
}
if ( F_159 ( V_9 ) ) {
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
V_274 = F_10 ( V_182 ) ;
F_63 ( V_182 , V_9 ) ;
memcpy ( V_274 -> V_68 , V_272 + 8 , 8 ) ;
F_157 ( V_274 -> V_68 , 8 ) ;
memcpy ( V_274 -> V_66 , V_271 , 8 ) ;
memcpy ( V_274 -> V_72 , V_7 -> V_72 , 8 ) ;
memcpy ( V_274 -> V_70 , V_7 -> V_70 , 8 ) ;
V_274 -> V_37 = V_37 ;
F_1 ( V_273 , V_272 + 8 ) ;
memcpy ( V_273 + 8 , V_274 -> V_72 , 8 ) ;
F_31 ( V_273 + 8 , 8 ) ;
V_274 -> V_62 = V_7 -> V_62 ;
V_37 -> V_38 = V_7 -> V_62 ;
V_10 = V_100 -> V_275 ( V_37 , & V_171 , V_273 , V_182 ) ;
if ( V_10 ) {
F_11 ( V_182 , 1 ) ;
F_50 ( V_182 ) ;
goto V_223;
}
F_78 ( V_9 , V_182 ) ;
V_182 -> V_13 = V_16 ;
V_9 -> V_276 ( V_9 , 1 ) ;
V_10 = 0 ;
V_223:
F_160 ( V_9 ) ;
return 0 ;
}
static void F_161 ( struct V_99 * V_37 , T_2 V_272 [ 16 ] )
{
struct V_8 * V_9 = V_37 -> V_277 ;
V_9 -> V_13 = V_16 ;
V_9 -> V_25 ( V_9 ) ;
}
static void F_162 ( struct V_99 * V_37 , struct V_26 * V_27 )
{
struct V_8 * V_9 = V_37 -> V_277 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_49 * V_50 ;
struct V_235 * V_278 ;
int V_78 ;
if ( V_9 -> V_210 & V_241 ) {
V_100 -> V_279 ( V_37 , V_27 ) ;
return;
}
F_163 ( & V_7 -> V_119 . V_12 ) ;
if ( ! F_136 ( & V_7 -> V_119 . V_120 ) ||
! F_59 ( & V_7 -> V_22 ) )
goto V_280;
V_78 = F_19 ( & V_9 -> V_90 ) ;
V_78 += F_164 ( F_15 ( V_27 ) ) ;
if ( V_78 > V_9 -> V_229 )
goto V_280;
V_50 = F_126 ( F_15 ( V_27 ) , V_84 | V_128 ) ;
if ( ! V_50 )
goto V_280;
F_128 ( V_9 , V_50 , V_37 , V_27 ) ;
goto V_281;
V_280:
V_278 = F_165 ( sizeof( struct V_235 ) , V_84 | V_128 ) ;
if ( ! V_278 )
goto V_281;
V_278 -> V_37 = V_37 ;
V_278 -> V_27 = * V_27 ;
F_81 ( & V_278 -> V_120 , & V_7 -> V_119 . V_120 ) ;
V_281:
F_166 ( & V_7 -> V_119 . V_12 ) ;
}
static void F_167 ( struct V_99 * V_37 ,
struct V_26 * V_27 )
{
struct V_8 * V_9 = V_37 -> V_277 ;
struct V_49 * V_282 = NULL ;
struct V_283 * V_120 = & F_10 ( V_9 ) -> V_21 ;
struct V_49 * V_284 = V_120 -> V_285 ;
unsigned long V_29 ;
F_158 ( V_9 ) ;
if ( ! F_59 ( V_120 ) ) {
F_80 ( & V_120 -> V_12 , V_29 ) ;
while ( V_284 != (struct V_49 * ) V_120 ) {
if ( V_27 -> V_224 != F_122 ( V_284 ) -> V_224 ) {
V_282 = V_284 ;
break;
}
V_284 = V_284 -> V_285 ;
}
if ( V_282 )
F_168 ( V_282 , V_120 ) ;
F_82 ( & V_120 -> V_12 , V_29 ) ;
if ( V_282 ) {
F_39 ( V_282 ) ;
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
static void F_169 ( struct V_99 * V_37 , T_2 V_272 [ 16 ] )
{
struct V_8 * V_9 = V_37 -> V_277 ;
if ( V_9 -> V_13 == V_20 )
return;
F_158 ( V_9 ) ;
F_11 ( V_9 , 1 ) ;
V_9 -> V_13 = V_14 ;
V_9 -> V_25 ( V_9 ) ;
F_160 ( V_9 ) ;
}
static void F_170 ( struct V_99 * V_37 , T_2 V_272 [ 16 ] )
{
struct V_8 * V_9 = V_37 -> V_277 ;
F_158 ( V_9 ) ;
if ( V_9 -> V_13 != V_20 ) {
V_9 -> V_210 |= V_211 ;
V_9 -> V_25 ( V_9 ) ;
}
F_160 ( V_9 ) ;
}
static void F_171 ( struct V_49 * V_50 )
{
struct V_51 * V_286 =
(struct V_51 * ) V_50 -> V_193 ;
char V_287 [ 8 ] ;
char V_288 [ 8 ] ;
F_31 ( V_286 -> V_65 , sizeof( V_286 -> V_65 ) ) ;
F_31 ( V_286 -> V_67 , sizeof( V_286 -> V_67 ) ) ;
F_31 ( V_286 -> V_69 , sizeof( V_286 -> V_69 ) ) ;
F_31 ( V_286 -> V_71 , sizeof( V_286 -> V_71 ) ) ;
memcpy ( V_287 , V_286 -> V_69 , 8 ) ;
memcpy ( V_288 , V_286 -> V_71 , 8 ) ;
memcpy ( V_286 -> V_69 , V_286 -> V_65 , 8 ) ;
memcpy ( V_286 -> V_71 , V_286 -> V_67 , 8 ) ;
memcpy ( V_286 -> V_65 , V_287 , 8 ) ;
memcpy ( V_286 -> V_67 , V_288 , 8 ) ;
F_28 ( V_50 , V_56 ) ;
memset ( V_50 -> V_193 , 0 , V_56 ) ;
}
static int F_172 ( struct V_8 * V_9 , struct V_49 * V_50 )
{
struct V_8 * V_182 ;
struct V_6 * V_7 , * V_274 ;
struct V_51 * V_286 ;
int V_10 ;
V_7 = F_10 ( V_9 ) ;
V_286 = (struct V_51 * ) V_50 -> V_193 ;
if ( ! V_7 ) {
F_171 ( V_50 ) ;
V_286 -> V_29 = V_60 | V_105 ;
V_10 = F_36 ( V_50 ) ;
goto V_212;
}
V_182 = F_64 ( NULL , V_9 -> V_80 , V_84 ) ;
F_158 ( V_9 ) ;
if ( ( V_9 -> V_13 != V_19 ) ||
F_159 ( V_9 ) ||
! V_182 ) {
if ( V_182 )
F_173 ( V_182 ) ;
F_171 ( V_50 ) ;
V_286 -> V_29 = V_60 | V_105 ;
V_10 = F_36 ( V_50 ) ;
F_160 ( V_9 ) ;
goto V_212;
}
V_274 = F_10 ( V_182 ) ;
F_63 ( V_182 , V_9 ) ;
V_274 -> V_35 = V_104 ;
V_274 -> V_62 = V_7 -> V_62 ;
if ( ! V_286 -> V_61 )
V_274 -> V_40 = V_165 ;
else
V_274 -> V_40 = V_286 -> V_61 ;
memcpy ( V_274 -> V_68 , V_286 -> V_71 , 8 ) ;
memcpy ( V_274 -> V_66 , V_286 -> V_69 , 8 ) ;
memcpy ( V_274 -> V_72 , V_7 -> V_72 , 8 ) ;
memcpy ( V_274 -> V_70 , V_7 -> V_70 , 8 ) ;
V_182 -> V_110 = V_9 -> V_110 ;
V_274 -> V_74 = V_7 -> V_74 ;
F_91 ( V_274 -> V_74 ) ;
F_171 ( V_50 ) ;
V_286 -> V_29 = V_60 | V_289 ;
V_286 -> V_61 = V_274 -> V_62 ;
V_10 = F_36 ( V_50 ) ;
if ( ! V_10 ) {
F_78 ( V_9 , V_182 ) ;
V_182 -> V_13 = V_16 ;
V_9 -> V_276 ( V_9 , 1 ) ;
} else
F_50 ( V_182 ) ;
F_160 ( V_9 ) ;
V_212:
return V_290 ;
}
static int F_174 ( struct V_8 * V_9 , struct V_49 * V_50 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_51 * V_286 =
(struct V_51 * ) V_50 -> V_193 ;
if ( ! V_7 )
goto V_212;
if ( V_9 -> V_13 != V_18 )
goto V_212;
F_158 ( V_9 ) ;
V_7 -> V_40 = V_286 -> V_61 ;
V_9 -> V_13 = V_16 ;
V_9 -> V_25 ( V_9 ) ;
F_160 ( V_9 ) ;
V_212:
F_39 ( V_50 ) ;
return V_290 ;
}
static int F_175 ( struct V_8 * V_9 , struct V_49 * V_50 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
if ( ! V_7 )
goto V_212;
if ( V_9 -> V_13 != V_18 )
goto V_212;
F_158 ( V_9 ) ;
V_9 -> V_13 = V_14 ;
V_9 -> V_25 ( V_9 ) ;
F_160 ( V_9 ) ;
V_212:
F_39 ( V_50 ) ;
return V_290 ;
}
static int F_176 ( struct V_8 * V_9 , struct V_49 * V_50 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
if ( ! V_7 )
goto V_212;
F_158 ( V_9 ) ;
if ( V_9 -> V_13 == V_16 ) {
V_9 -> V_13 = V_14 ;
V_9 -> V_25 ( V_9 ) ;
}
F_160 ( V_9 ) ;
V_212:
F_39 ( V_50 ) ;
return V_290 ;
}
static int F_177 ( struct V_8 * V_9 , struct V_49 * V_50 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_51 * V_286 =
(struct V_51 * ) V_50 -> V_193 ;
if ( ! V_7 )
return V_290 ;
if ( V_9 -> V_13 != V_16 )
return V_290 ;
F_40 ( V_286 -> V_61 , & V_7 -> V_39 ) ;
F_20 ( V_9 ) ;
return V_290 ;
}
static int F_178 ( struct V_8 * V_9 , struct V_49 * V_50 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
if ( ! V_7 ) {
F_39 ( V_50 ) ;
return V_290 ;
}
if ( V_9 -> V_13 != V_16 ) {
F_39 ( V_50 ) ;
return V_290 ;
}
if ( V_9 -> V_210 & V_241 ) {
F_39 ( V_50 ) ;
return V_290 ;
}
if ( V_50 -> V_78 < sizeof( struct V_51 ) ) {
F_39 ( V_50 ) ;
return V_290 ;
}
F_179 ( V_50 , sizeof( struct V_51 ) ) ;
F_127 ( V_50 ) ;
F_30 ( V_50 ) ;
F_122 ( V_50 ) -> V_234 = 0 ;
F_163 ( & V_7 -> V_119 . V_12 ) ;
if ( F_59 ( & V_7 -> V_22 ) ) {
if ( F_130 ( V_9 , V_50 ) ) {
F_35 ( & V_7 -> V_22 , V_50 ) ;
}
} else
F_35 ( & F_10 ( V_9 ) -> V_22 , V_50 ) ;
F_166 ( & V_7 -> V_119 . V_12 ) ;
return V_290 ;
}
static int F_180 ( struct V_49 * V_50 , struct V_150 * V_4 ,
struct V_291 * V_292 , struct V_150 * V_293 )
{
struct V_8 * V_9 ;
struct V_6 * V_7 ;
struct V_51 * V_286 ;
char V_294 [ 8 ] ;
int V_10 = 0 ;
F_179 ( V_50 , V_56 ) ;
V_286 = (struct V_51 * ) V_50 -> V_193 ;
F_157 ( V_286 -> V_67 , sizeof( V_286 -> V_67 ) ) ;
F_157 ( V_286 -> V_65 , sizeof( V_286 -> V_65 ) ) ;
F_157 ( V_286 -> V_71 , sizeof( V_286 -> V_71 ) ) ;
F_157 ( V_286 -> V_69 , sizeof( V_286 -> V_69 ) ) ;
memset ( V_294 , 0 , sizeof( V_294 ) ) ;
V_7 = NULL ;
V_9 = NULL ;
F_8 ( & V_11 . V_12 ) ;
F_9 (sk, &iucv_sk_list.head) {
if ( V_286 -> V_29 == V_60 ) {
if ( ( ! memcmp ( & F_10 ( V_9 ) -> V_72 ,
V_286 -> V_67 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_70 ,
V_286 -> V_65 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_68 , V_294 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_66 ,
V_294 , 8 ) ) ) {
V_7 = F_10 ( V_9 ) ;
break;
}
} else {
if ( ( ! memcmp ( & F_10 ( V_9 ) -> V_72 ,
V_286 -> V_67 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_70 ,
V_286 -> V_65 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_68 ,
V_286 -> V_71 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_66 ,
V_286 -> V_69 , 8 ) ) ) {
V_7 = F_10 ( V_9 ) ;
break;
}
}
}
F_13 ( & V_11 . V_12 ) ;
if ( ! V_7 )
V_9 = NULL ;
switch ( V_286 -> V_29 ) {
case V_60 :
V_10 = F_172 ( V_9 , V_50 ) ;
break;
case ( V_60 | V_289 ) :
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
case ( V_259 ) :
case 0 :
F_122 ( V_50 ) -> V_214 = V_286 -> V_73 . V_214 ;
V_10 = F_178 ( V_9 , V_50 ) ;
break;
default:
;
}
return V_10 ;
}
static void V_123 ( struct V_49 * V_50 ,
enum V_295 V_144 )
{
struct V_8 * V_143 = V_50 -> V_9 ;
struct V_8 * V_9 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_283 * V_120 ;
struct V_49 * V_284 ;
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
goto V_281;
V_284 = V_120 -> V_285 ;
V_53 = V_284 -> V_285 ;
while ( V_284 != (struct V_49 * ) V_120 ) {
if ( F_183 ( V_284 ) == F_183 ( V_50 ) ) {
switch ( V_144 ) {
case V_296 :
F_168 ( V_284 , V_120 ) ;
F_39 ( V_284 ) ;
F_20 ( V_9 ) ;
break;
case V_297 :
F_123 ( & V_7 -> V_41 ) ;
break;
case V_298 :
F_168 ( V_284 , V_120 ) ;
F_124 ( & V_7 -> V_41 ) ;
if ( F_19 ( & V_7 -> V_41 ) <= 0 )
F_20 ( V_9 ) ;
F_39 ( V_284 ) ;
break;
case V_299 :
case V_300 :
case V_301 :
case V_302 :
case V_303 :
F_168 ( V_284 , V_120 ) ;
F_39 ( V_284 ) ;
if ( V_9 -> V_13 == V_16 ) {
V_9 -> V_13 = V_14 ;
V_9 -> V_25 ( V_9 ) ;
}
break;
}
break;
}
V_284 = V_53 ;
V_53 = V_53 -> V_285 ;
}
V_281:
F_82 ( & V_120 -> V_12 , V_29 ) ;
if ( V_9 -> V_13 == V_15 ) {
if ( F_59 ( & F_10 ( V_9 ) -> V_21 ) ) {
V_9 -> V_13 = V_20 ;
V_9 -> V_25 ( V_9 ) ;
}
}
}
static int F_184 ( struct V_304 * V_282 ,
unsigned long V_305 , void * V_306 )
{
struct V_150 * V_307 = F_185 ( V_306 ) ;
struct V_8 * V_9 ;
struct V_6 * V_7 ;
switch ( V_305 ) {
case V_308 :
case V_309 :
F_9 (sk, &iucv_sk_list.head) {
V_7 = F_10 ( V_9 ) ;
if ( ( V_7 -> V_74 == V_307 ) &&
( V_9 -> V_13 == V_16 ) ) {
if ( V_305 == V_309 )
F_55 ( V_9 , V_105 ) ;
V_9 -> V_13 = V_14 ;
V_9 -> V_25 ( V_9 ) ;
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
int V_10 ;
V_10 = V_100 -> V_313 ( & V_171 , 0 ) ;
if ( V_10 )
goto V_212;
V_314 . V_315 = V_100 -> V_315 ;
V_10 = F_187 ( & V_314 ) ;
if ( V_10 )
goto V_316;
V_317 = F_165 ( sizeof( struct V_3 ) , V_138 ) ;
if ( ! V_317 ) {
V_10 = - V_85 ;
goto V_318;
}
F_188 ( V_317 , L_9 ) ;
V_317 -> V_315 = V_100 -> V_315 ;
V_317 -> V_94 = V_100 -> V_319 ;
V_317 -> V_225 = ( void ( * ) ( struct V_3 * ) ) F_134 ;
V_317 -> V_320 = & V_314 ;
V_10 = F_189 ( V_317 ) ;
if ( V_10 )
goto V_318;
return 0 ;
V_318:
F_190 ( & V_314 ) ;
V_316:
V_100 -> V_321 ( & V_171 , 0 ) ;
V_212:
return V_10 ;
}
static int T_7 F_191 ( void )
{
int V_10 ;
if ( V_322 ) {
F_192 ( L_10 , V_161 , sizeof( V_161 ) , & V_10 ) ;
if ( F_93 ( V_10 ) ) {
F_41 ( V_10 ) ;
V_10 = - V_132 ;
goto V_212;
}
V_100 = F_193 ( F_194 ( V_323 ) , L_11 ) ;
if ( ! V_100 ) {
F_5 ( V_5 L_12 ) ;
memset ( & V_161 , 0 , sizeof( V_161 ) ) ;
}
} else {
memset ( & V_161 , 0 , sizeof( V_161 ) ) ;
V_100 = NULL ;
}
V_10 = F_195 ( & V_116 , 0 ) ;
if ( V_10 )
goto V_212;
V_10 = F_196 ( & V_324 ) ;
if ( V_10 )
goto V_325;
if ( V_100 ) {
V_10 = F_186 () ;
if ( V_10 )
goto V_326;
} else
F_197 ( & V_327 ) ;
F_198 ( & V_328 ) ;
return 0 ;
V_326:
F_199 ( V_115 ) ;
V_325:
F_200 ( & V_116 ) ;
V_212:
if ( V_100 )
F_201 ( V_323 ) ;
return V_10 ;
}
static void T_8 F_202 ( void )
{
if ( V_100 ) {
F_203 ( V_317 ) ;
F_190 ( & V_314 ) ;
V_100 -> V_321 ( & V_171 , 0 ) ;
F_201 ( V_323 ) ;
} else
F_204 ( & V_327 ) ;
F_205 ( & V_328 ) ;
F_199 ( V_115 ) ;
F_200 ( & V_116 ) ;
}
