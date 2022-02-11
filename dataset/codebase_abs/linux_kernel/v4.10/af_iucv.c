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
T_2 V_103 = 0 ;
V_102 = sizeof( struct V_51 ) + V_56 ;
if ( V_9 -> V_104 & V_105 ) {
V_103 = V_9 -> V_104 ;
V_9 -> V_104 &= V_106 ;
}
V_50 = F_56 ( V_9 , V_102 , 1 , & V_10 ) ;
if ( V_50 ) {
F_57 ( V_50 , V_102 ) ;
V_10 = F_27 ( NULL , V_9 , V_50 , V_29 ) ;
}
if ( V_103 )
V_9 -> V_104 = V_103 ;
return V_10 ;
}
static void F_49 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
unsigned long V_107 ;
int V_10 = 0 ;
F_58 ( V_9 ) ;
switch ( V_9 -> V_13 ) {
case V_19 :
F_47 ( V_9 ) ;
break;
case V_16 :
if ( V_7 -> V_35 == V_108 ) {
V_10 = F_55 ( V_9 , V_109 ) ;
V_9 -> V_13 = V_14 ;
V_9 -> V_25 ( V_9 ) ;
}
case V_14 :
V_9 -> V_13 = V_15 ;
V_9 -> V_25 ( V_9 ) ;
if ( ! V_10 && ! F_59 ( & V_7 -> V_21 ) ) {
if ( F_45 ( V_9 , V_110 ) && V_9 -> V_111 )
V_107 = V_9 -> V_111 ;
else
V_107 = V_112 ;
F_60 ( V_9 ,
F_16 ( V_9 , V_20 , 0 ) ,
V_107 ) ;
}
case V_15 :
V_9 -> V_13 = V_20 ;
V_9 -> V_25 ( V_9 ) ;
V_9 -> V_23 = V_113 ;
V_9 -> V_25 ( V_9 ) ;
F_12 ( & V_7 -> V_21 ) ;
F_12 ( & V_7 -> V_22 ) ;
default:
F_11 ( V_9 , 1 ) ;
}
if ( V_7 -> V_74 ) {
F_61 ( V_7 -> V_74 ) ;
V_7 -> V_74 = NULL ;
V_9 -> V_114 = 0 ;
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
static struct V_8 * F_65 ( struct V_115 * V_8 , int V_116 , T_3 V_117 , int V_118 )
{
struct V_8 * V_9 ;
struct V_6 * V_7 ;
V_9 = F_66 ( & V_119 , V_120 , V_117 , & V_121 , V_118 ) ;
if ( ! V_9 )
return NULL ;
V_7 = F_10 ( V_9 ) ;
F_67 ( V_8 , V_9 ) ;
F_68 ( & V_7 -> V_122 ) ;
F_69 ( & V_7 -> V_123 ) ;
F_70 ( & V_7 -> V_21 ) ;
F_68 ( & V_7 -> V_124 . V_125 ) ;
F_69 ( & V_7 -> V_124 . V_12 ) ;
F_70 ( & V_7 -> V_22 ) ;
V_7 -> V_126 = 0 ;
F_71 ( & V_7 -> V_41 , 0 ) ;
V_7 -> V_29 = 0 ;
V_7 -> V_62 = 0 ;
F_71 ( & V_7 -> V_39 , 0 ) ;
F_71 ( & V_7 -> V_64 , 0 ) ;
V_7 -> V_37 = NULL ;
V_7 -> V_127 = V_128 ;
memset ( & V_7 -> V_70 , 0 , 32 ) ;
if ( V_100 )
V_7 -> V_35 = V_36 ;
else
V_7 -> V_35 = V_108 ;
V_9 -> V_129 = F_43 ;
V_9 -> V_130 = V_131 ;
V_9 -> V_132 = V_133 ;
F_72 ( V_9 , V_95 ) ;
V_9 -> V_134 = V_116 ;
V_9 -> V_13 = V_17 ;
F_73 ( & V_11 , V_9 ) ;
return V_9 ;
}
static int F_74 ( struct V_135 * V_135 , struct V_115 * V_8 , int V_83 ,
int V_118 )
{
struct V_8 * V_9 ;
if ( V_83 && V_83 != V_120 )
return - V_136 ;
V_8 -> V_33 = V_137 ;
switch ( V_8 -> type ) {
case V_138 :
V_8 -> V_139 = & V_140 ;
break;
case V_81 :
V_8 -> V_139 = & V_140 ;
break;
default:
return - V_141 ;
}
V_9 = F_65 ( V_8 , V_83 , V_142 , V_118 ) ;
if ( ! V_9 )
return - V_85 ;
F_63 ( V_9 , NULL ) ;
return 0 ;
}
void F_73 ( struct V_143 * V_144 , struct V_8 * V_9 )
{
F_75 ( & V_144 -> V_12 ) ;
F_76 ( V_9 , & V_144 -> V_55 ) ;
F_77 ( & V_144 -> V_12 ) ;
}
void F_51 ( struct V_143 * V_144 , struct V_8 * V_9 )
{
F_75 ( & V_144 -> V_12 ) ;
F_78 ( V_9 ) ;
F_77 ( & V_144 -> V_12 ) ;
}
void F_79 ( struct V_8 * V_94 , struct V_8 * V_9 )
{
unsigned long V_29 ;
struct V_6 * V_145 = F_10 ( V_94 ) ;
F_80 ( V_9 ) ;
F_81 ( & V_145 -> V_123 , V_29 ) ;
F_82 ( & F_10 ( V_9 ) -> V_122 , & V_145 -> V_122 ) ;
F_83 ( & V_145 -> V_123 , V_29 ) ;
F_10 ( V_9 ) -> V_94 = V_94 ;
F_84 ( V_94 ) ;
}
void F_85 ( struct V_8 * V_9 )
{
unsigned long V_29 ;
struct V_6 * V_145 = F_10 ( F_10 ( V_9 ) -> V_94 ) ;
F_81 ( & V_145 -> V_123 , V_29 ) ;
F_86 ( & F_10 ( V_9 ) -> V_122 ) ;
F_83 ( & V_145 -> V_123 , V_29 ) ;
F_87 ( F_10 ( V_9 ) -> V_94 ) ;
F_10 ( V_9 ) -> V_94 = NULL ;
F_53 ( V_9 ) ;
}
struct V_8 * F_48 ( struct V_8 * V_94 , struct V_115 * V_146 )
{
struct V_6 * V_147 , * V_148 ;
struct V_8 * V_9 ;
F_88 (isk, n, &iucv_sk(parent)->accept_q, accept_q) {
V_9 = (struct V_8 * ) V_147 ;
F_58 ( V_9 ) ;
if ( V_9 -> V_13 == V_20 ) {
F_85 ( V_9 ) ;
F_62 ( V_9 ) ;
continue;
}
if ( V_9 -> V_13 == V_16 ||
V_9 -> V_13 == V_14 ||
! V_146 ) {
F_85 ( V_9 ) ;
if ( V_146 )
F_89 ( V_9 , V_146 ) ;
F_62 ( V_9 ) ;
return V_9 ;
}
F_62 ( V_9 ) ;
}
return NULL ;
}
static void F_90 ( struct V_6 * V_7 )
{
char V_149 [ 12 ] ;
sprintf ( V_149 , L_6 , F_91 ( & V_11 . V_150 ) ) ;
while ( F_42 ( V_149 ) ) {
sprintf ( V_149 , L_6 ,
F_91 ( & V_11 . V_150 ) ) ;
}
memcpy ( V_7 -> V_72 , V_149 , 8 ) ;
}
static int F_92 ( struct V_115 * V_8 , struct V_151 * V_152 ,
int V_153 )
{
struct V_154 * V_155 = (struct V_154 * ) V_152 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 ;
int V_10 = 0 ;
struct V_156 * V_4 ;
char V_157 [ 9 ] ;
if ( ! V_152 || V_152 -> V_158 != V_159 )
return - V_160 ;
if ( V_153 < sizeof( struct V_154 ) )
return - V_160 ;
F_58 ( V_9 ) ;
if ( V_9 -> V_13 != V_17 ) {
V_10 = - V_161 ;
goto V_162;
}
F_75 ( & V_11 . V_12 ) ;
V_7 = F_10 ( V_9 ) ;
if ( F_42 ( V_155 -> V_163 ) ) {
V_10 = - V_164 ;
goto V_165;
}
if ( V_7 -> V_37 )
goto V_165;
if ( V_100 )
if ( ! memcmp ( V_155 -> V_166 , V_167 , 8 ) )
goto V_168;
memcpy ( V_157 , V_155 -> V_166 , sizeof( V_157 ) ) ;
F_31 ( V_157 , 8 ) ;
F_21 () ;
F_93 (&init_net, dev) {
if ( ! memcmp ( V_4 -> V_169 , V_157 , 8 ) ) {
memcpy ( V_7 -> V_70 , V_155 -> V_166 , 8 ) ;
if ( strncmp ( V_155 -> V_163 , L_7 , 8 ) == 0 )
F_90 ( V_7 ) ;
else
memcpy ( V_7 -> V_72 , V_155 -> V_163 , 8 ) ;
V_9 -> V_114 = V_4 -> V_170 ;
V_7 -> V_74 = V_4 ;
F_94 ( V_4 ) ;
V_9 -> V_13 = V_18 ;
V_7 -> V_35 = V_108 ;
if ( ! V_7 -> V_62 )
V_7 -> V_62 = V_171 ;
F_26 () ;
goto V_165;
}
}
F_26 () ;
V_168:
if ( V_100 ) {
memcpy ( V_7 -> V_72 , V_155 -> V_163 , 8 ) ;
memcpy ( V_7 -> V_70 , V_167 , 8 ) ;
V_9 -> V_13 = V_18 ;
V_7 -> V_35 = V_36 ;
if ( ! V_7 -> V_62 )
V_7 -> V_62 = V_172 ;
goto V_165;
}
V_10 = - V_75 ;
V_165:
F_77 ( & V_11 . V_12 ) ;
V_162:
F_62 ( V_9 ) ;
return V_10 ;
}
static int F_95 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
int V_10 = 0 ;
if ( F_96 ( ! V_100 ) )
return - V_173 ;
memcpy ( V_7 -> V_70 , V_167 , 8 ) ;
F_75 ( & V_11 . V_12 ) ;
F_90 ( V_7 ) ;
F_77 ( & V_11 . V_12 ) ;
if ( ! V_7 -> V_62 )
V_7 -> V_62 = V_172 ;
return V_10 ;
}
static int F_97 ( struct V_115 * V_8 , struct V_151 * V_152 )
{
struct V_154 * V_155 = (struct V_154 * ) V_152 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
unsigned char V_98 [ 16 ] ;
int V_10 ;
F_1 ( V_98 , V_155 -> V_163 ) ;
F_2 ( V_98 , V_7 -> V_72 ) ;
F_31 ( V_98 , sizeof( V_98 ) ) ;
V_7 -> V_37 = F_98 ( V_7 -> V_62 ,
V_30 , V_142 ) ;
if ( ! V_7 -> V_37 ) {
V_10 = - V_85 ;
goto V_162;
}
V_10 = V_100 -> V_174 ( V_7 -> V_37 , & V_175 ,
V_155 -> V_166 , NULL , V_98 ,
V_9 ) ;
if ( V_10 ) {
F_54 ( V_7 -> V_37 ) ;
V_7 -> V_37 = NULL ;
switch ( V_10 ) {
case 0x0b :
V_10 = - V_176 ;
break;
case 0x0d :
case 0x0e :
V_10 = - V_177 ;
break;
case 0x0f :
V_10 = - V_178 ;
break;
default:
V_10 = - V_179 ;
break;
}
}
V_162:
return V_10 ;
}
static int F_99 ( struct V_115 * V_8 , struct V_151 * V_152 ,
int V_180 , int V_29 )
{
struct V_154 * V_155 = (struct V_154 * ) V_152 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
int V_10 ;
if ( V_152 -> V_158 != V_159 || V_180 < sizeof( struct V_154 ) )
return - V_160 ;
if ( V_9 -> V_13 != V_17 && V_9 -> V_13 != V_18 )
return - V_161 ;
if ( V_9 -> V_13 == V_17 &&
V_7 -> V_35 == V_108 )
return - V_161 ;
if ( V_9 -> V_80 != V_138 && V_9 -> V_80 != V_81 )
return - V_160 ;
if ( V_9 -> V_13 == V_17 ) {
V_10 = F_95 ( V_9 ) ;
if ( F_96 ( V_10 ) )
return V_10 ;
}
F_58 ( V_9 ) ;
memcpy ( V_7 -> V_66 , V_155 -> V_166 , 8 ) ;
memcpy ( V_7 -> V_68 , V_155 -> V_163 , 8 ) ;
if ( V_7 -> V_35 == V_108 )
V_10 = F_55 ( V_8 -> V_9 , V_60 ) ;
else
V_10 = F_97 ( V_8 , V_152 ) ;
if ( V_10 )
goto V_162;
if ( V_9 -> V_13 != V_16 )
V_10 = F_60 ( V_9 , F_16 ( V_9 , V_16 ,
V_14 ) ,
F_100 ( V_9 , V_29 & V_181 ) ) ;
if ( V_9 -> V_13 == V_14 || V_9 -> V_13 == V_20 )
V_10 = - V_179 ;
if ( V_10 && V_7 -> V_35 == V_36 )
F_11 ( V_9 , 0 ) ;
V_162:
F_62 ( V_9 ) ;
return V_10 ;
}
static int F_101 ( struct V_115 * V_8 , int V_182 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
int V_10 ;
F_58 ( V_9 ) ;
V_10 = - V_160 ;
if ( V_9 -> V_13 != V_18 )
goto V_162;
if ( V_8 -> type != V_138 && V_8 -> type != V_81 )
goto V_162;
V_9 -> V_183 = V_182 ;
V_9 -> V_184 = 0 ;
V_9 -> V_13 = V_19 ;
V_10 = 0 ;
V_162:
F_62 ( V_9 ) ;
return V_10 ;
}
static int F_102 ( struct V_115 * V_8 , struct V_115 * V_146 ,
int V_29 )
{
F_103 ( V_45 , V_185 ) ;
struct V_8 * V_9 = V_8 -> V_9 , * V_186 ;
long V_107 ;
int V_10 = 0 ;
F_104 ( V_9 , V_187 ) ;
if ( V_9 -> V_13 != V_19 ) {
V_10 = - V_161 ;
goto V_162;
}
V_107 = F_105 ( V_9 , V_29 & V_181 ) ;
F_106 ( F_107 ( V_9 ) , & V_45 ) ;
while ( ! ( V_186 = F_48 ( V_9 , V_146 ) ) ) {
F_108 ( V_188 ) ;
if ( ! V_107 ) {
V_10 = - V_177 ;
break;
}
F_62 ( V_9 ) ;
V_107 = F_109 ( V_107 ) ;
F_104 ( V_9 , V_187 ) ;
if ( V_9 -> V_13 != V_19 ) {
V_10 = - V_161 ;
break;
}
if ( F_110 ( V_185 ) ) {
V_10 = F_111 ( V_107 ) ;
break;
}
}
F_108 ( V_189 ) ;
F_112 ( F_107 ( V_9 ) , & V_45 ) ;
if ( V_10 )
goto V_162;
V_146 -> V_33 = V_190 ;
V_162:
F_62 ( V_9 ) ;
return V_10 ;
}
static int F_113 ( struct V_115 * V_8 , struct V_151 * V_152 ,
int * V_78 , int V_191 )
{
struct V_154 * V_192 = (struct V_154 * ) V_152 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
V_152 -> V_158 = V_159 ;
* V_78 = sizeof( struct V_154 ) ;
if ( V_191 ) {
memcpy ( V_192 -> V_166 , V_7 -> V_66 , 8 ) ;
memcpy ( V_192 -> V_163 , V_7 -> V_68 , 8 ) ;
} else {
memcpy ( V_192 -> V_166 , V_7 -> V_70 , 8 ) ;
memcpy ( V_192 -> V_163 , V_7 -> V_72 , 8 ) ;
}
memset ( & V_192 -> V_193 , 0 , sizeof( V_192 -> V_193 ) ) ;
memset ( & V_192 -> V_194 , 0 , sizeof( V_192 -> V_194 ) ) ;
memset ( & V_192 -> V_195 , 0 , sizeof( V_192 -> V_195 ) ) ;
return 0 ;
}
static int F_114 ( struct V_99 * V_37 , struct V_26 * V_27 ,
struct V_49 * V_50 )
{
T_2 V_196 [ 8 ] ;
memcpy ( V_196 , ( void * ) V_50 -> V_197 , V_50 -> V_78 ) ;
V_196 [ 7 ] = 0xff - ( T_2 ) V_50 -> V_78 ;
return V_100 -> V_198 ( V_37 , V_27 , V_30 , 0 ,
( void * ) V_196 , 8 ) ;
}
static int F_115 ( struct V_115 * V_8 , struct V_199 * V_27 ,
T_1 V_78 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
T_1 V_200 = 0 ;
T_1 V_201 ;
struct V_49 * V_50 ;
struct V_26 V_202 = { 0 } ;
struct V_203 * V_204 ;
int V_205 ;
long V_107 ;
char V_206 [ 9 ] ;
char V_207 [ 9 ] ;
int V_10 ;
int V_208 = V_27 -> V_209 & V_210 ;
V_10 = F_116 ( V_9 ) ;
if ( V_10 )
return V_10 ;
if ( V_27 -> V_209 & V_211 )
return - V_212 ;
if ( V_9 -> V_80 == V_81 && ! ( V_27 -> V_209 & V_213 ) )
return - V_212 ;
F_58 ( V_9 ) ;
if ( V_9 -> V_104 & V_105 ) {
V_10 = - V_24 ;
goto V_214;
}
if ( V_9 -> V_13 != V_16 ) {
V_10 = - V_215 ;
goto V_214;
}
V_205 = 0 ;
V_202 . V_216 = 0 ;
F_117 (cmsg, msg) {
if ( ! F_118 ( V_27 , V_204 ) ) {
V_10 = - V_160 ;
goto V_214;
}
if ( V_204 -> V_217 != V_218 )
continue;
if ( V_204 -> V_219 & V_205 ) {
V_10 = - V_160 ;
goto V_214;
}
V_205 |= V_204 -> V_219 ;
switch ( V_204 -> V_219 ) {
case V_220 :
if ( V_204 -> V_221 != F_119 ( V_222 ) ) {
V_10 = - V_160 ;
goto V_214;
}
memcpy ( & V_202 . V_216 ,
( void * ) F_120 ( V_204 ) , V_222 ) ;
break;
default:
V_10 = - V_160 ;
goto V_214;
}
}
if ( V_7 -> V_35 == V_108 ) {
V_200 = sizeof( struct V_51 ) + V_56 ;
V_201 = V_78 ;
} else {
if ( V_78 < V_223 ) {
V_201 = V_78 ;
} else {
V_200 = sizeof( struct V_224 ) *
( V_225 + 1 ) ;
V_201 = V_223 - V_200 ;
}
}
V_50 = F_121 ( V_9 , V_200 + V_201 , V_78 - V_201 ,
V_208 , & V_10 , 0 ) ;
if ( ! V_50 )
goto V_214;
if ( V_200 )
F_57 ( V_50 , V_200 ) ;
F_122 ( V_50 , V_201 ) ;
V_50 -> V_78 = V_78 ;
V_50 -> V_226 = V_78 - V_201 ;
V_10 = F_123 ( V_50 , 0 , & V_27 -> V_227 , V_78 ) ;
if ( V_10 )
goto V_228;
V_107 = F_100 ( V_9 , V_208 ) ;
V_10 = F_60 ( V_9 , F_17 ( V_9 ) , V_107 ) ;
if ( V_10 )
goto V_228;
if ( V_9 -> V_13 != V_16 ) {
V_10 = - V_113 ;
goto V_228;
}
V_202 . V_229 = V_7 -> V_126 ++ ;
F_124 ( V_50 ) -> V_229 = V_202 . V_229 ;
if ( V_7 -> V_35 == V_108 ) {
F_125 ( & V_7 -> V_39 ) ;
V_10 = F_27 ( & V_202 , V_9 , V_50 , 0 ) ;
if ( V_10 ) {
F_126 ( & V_7 -> V_39 ) ;
goto V_228;
}
} else {
F_35 ( & V_7 -> V_21 , V_50 ) ;
if ( ( ( V_7 -> V_37 -> V_29 & V_30 ) & V_7 -> V_29 ) &&
V_50 -> V_78 <= 7 ) {
V_10 = F_114 ( V_7 -> V_37 , & V_202 , V_50 ) ;
if ( V_10 == 0 ) {
F_38 ( V_50 , & V_7 -> V_21 ) ;
F_39 ( V_50 ) ;
}
if ( V_10 == 0x15 ) {
V_100 -> V_101 ( V_7 -> V_37 , NULL ) ;
F_38 ( V_50 , & V_7 -> V_21 ) ;
V_10 = - V_24 ;
goto V_228;
}
} else if ( F_127 ( V_50 ) ) {
struct V_224 * V_230 = (struct V_224 * ) V_50 -> V_55 ;
int V_231 ;
V_230 [ 0 ] . V_232 = ( V_233 ) ( V_234 ) V_50 -> V_197 ;
V_230 [ 0 ] . V_32 = ( V_233 ) F_128 ( V_50 ) ;
for ( V_231 = 0 ; V_231 < F_129 ( V_50 ) -> V_235 ; V_231 ++ ) {
T_4 * V_236 = & F_129 ( V_50 ) -> V_237 [ V_231 ] ;
V_230 [ V_231 + 1 ] . V_232 =
( V_233 ) ( V_234 ) F_130 ( V_236 ) ;
V_230 [ V_231 + 1 ] . V_32 = ( V_233 ) F_131 ( V_236 ) ;
}
V_10 = V_100 -> V_198 ( V_7 -> V_37 , & V_202 ,
V_238 , 0 ,
( void * ) V_230 , V_50 -> V_78 ) ;
} else {
V_10 = V_100 -> V_198 ( V_7 -> V_37 , & V_202 ,
0 , 0 , ( void * ) V_50 -> V_197 , V_50 -> V_78 ) ;
}
if ( V_10 ) {
if ( V_10 == 3 ) {
V_206 [ 8 ] = 0 ;
memcpy ( V_206 , V_7 -> V_66 , 8 ) ;
V_207 [ 8 ] = 0 ;
memcpy ( V_207 , V_7 -> V_68 , 8 ) ;
F_46 (
L_8 ,
V_207 , V_206 ) ;
V_10 = - V_177 ;
} else {
V_10 = - V_24 ;
}
F_38 ( V_50 , & V_7 -> V_21 ) ;
goto V_228;
}
}
F_62 ( V_9 ) ;
return V_78 ;
V_228:
F_39 ( V_50 ) ;
V_214:
F_62 ( V_9 ) ;
return V_10 ;
}
static struct V_49 * F_132 ( unsigned long V_78 )
{
T_1 V_200 , V_201 ;
struct V_49 * V_50 ;
int V_10 ;
if ( V_78 < V_223 ) {
V_200 = 0 ;
V_201 = V_78 ;
} else {
V_200 = sizeof( struct V_224 ) * ( V_225 + 1 ) ;
V_201 = V_223 - V_200 ;
}
V_50 = F_133 ( V_200 + V_201 , V_78 - V_201 ,
0 , & V_10 , V_84 | V_133 ) ;
F_134 ( ! V_50 ,
L_9 ,
V_78 , V_10 ) ;
if ( V_50 ) {
if ( V_200 )
F_57 ( V_50 , V_200 ) ;
F_122 ( V_50 , V_201 ) ;
V_50 -> V_78 = V_78 ;
V_50 -> V_226 = V_78 - V_201 ;
}
return V_50 ;
}
static void F_135 ( struct V_8 * V_9 , struct V_49 * V_50 ,
struct V_99 * V_37 ,
struct V_26 * V_27 )
{
int V_239 ;
unsigned int V_78 ;
V_78 = F_15 ( V_27 ) ;
F_124 ( V_50 ) -> V_216 = V_27 -> V_216 ;
if ( ( V_27 -> V_29 & V_30 ) && V_78 > 7 ) {
if ( memcmp ( V_27 -> V_31 , V_240 , 8 ) == 0 ) {
V_50 -> V_197 = NULL ;
V_50 -> V_78 = 0 ;
}
} else {
if ( F_127 ( V_50 ) ) {
struct V_224 * V_230 = (struct V_224 * ) V_50 -> V_55 ;
int V_231 ;
V_230 [ 0 ] . V_232 = ( V_233 ) ( V_234 ) V_50 -> V_197 ;
V_230 [ 0 ] . V_32 = ( V_233 ) F_128 ( V_50 ) ;
for ( V_231 = 0 ; V_231 < F_129 ( V_50 ) -> V_235 ; V_231 ++ ) {
T_4 * V_236 = & F_129 ( V_50 ) -> V_237 [ V_231 ] ;
V_230 [ V_231 + 1 ] . V_232 =
( V_233 ) ( V_234 ) F_130 ( V_236 ) ;
V_230 [ V_231 + 1 ] . V_32 = ( V_233 ) F_131 ( V_236 ) ;
}
V_239 = V_100 -> V_241 ( V_37 , V_27 ,
V_238 ,
( void * ) V_230 , V_78 , NULL ) ;
} else {
V_239 = V_100 -> V_241 ( V_37 , V_27 ,
V_27 -> V_29 & V_30 ,
V_50 -> V_197 , V_78 , NULL ) ;
}
if ( V_239 ) {
F_39 ( V_50 ) ;
return;
}
F_136 ( V_50 -> V_78 != V_78 ) ;
}
F_124 ( V_50 ) -> V_242 = 0 ;
if ( F_137 ( V_9 , V_50 ) ) {
F_125 ( & V_9 -> V_243 ) ;
F_39 ( V_50 ) ;
return;
}
if ( F_138 ( V_9 , V_50 ) )
F_35 ( & F_10 ( V_9 ) -> V_22 , V_50 ) ;
}
static void F_139 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_49 * V_50 ;
struct V_244 * V_245 , * V_148 ;
F_88 (p, n, &iucv->message_q.list, list) {
V_50 = F_132 ( F_15 ( & V_245 -> V_27 ) ) ;
if ( ! V_50 )
break;
F_135 ( V_9 , V_50 , V_245 -> V_37 , & V_245 -> V_27 ) ;
F_140 ( & V_245 -> V_125 ) ;
F_141 ( V_245 ) ;
if ( ! F_59 ( & V_7 -> V_22 ) )
break;
}
}
static int F_142 ( struct V_115 * V_8 , struct V_199 * V_27 ,
T_1 V_78 , int V_29 )
{
int V_208 = V_29 & V_210 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
unsigned int V_246 , V_247 ;
struct V_49 * V_50 , * V_248 , * V_249 ;
int V_10 = 0 ;
V_233 V_242 ;
if ( ( V_9 -> V_13 == V_14 ) &&
F_59 ( & V_7 -> V_22 ) &&
F_59 ( & V_9 -> V_87 ) &&
F_143 ( & V_7 -> V_124 . V_125 ) )
return 0 ;
if ( V_29 & ( V_211 ) )
return - V_212 ;
V_50 = F_144 ( V_9 , V_29 , V_208 , & V_10 ) ;
if ( ! V_50 ) {
if ( V_9 -> V_104 & V_106 )
return 0 ;
return V_10 ;
}
V_242 = F_124 ( V_50 ) -> V_242 ;
V_247 = V_50 -> V_78 - V_242 ;
V_246 = F_145 (unsigned int, rlen, len) ;
if ( ! V_247 )
V_9 -> V_104 = V_9 -> V_104 | V_106 ;
V_249 = V_50 ;
if ( F_146 ( V_249 , V_242 , V_27 , V_246 ) ) {
if ( ! ( V_29 & V_250 ) )
F_147 ( & V_9 -> V_87 , V_50 ) ;
return - V_251 ;
}
if ( V_9 -> V_80 == V_81 ) {
if ( V_246 < V_247 )
V_27 -> V_209 |= V_252 ;
V_27 -> V_209 |= V_213 ;
}
V_10 = F_148 ( V_27 , V_218 , V_220 ,
sizeof( F_124 ( V_50 ) -> V_216 ) ,
( void * ) & F_124 ( V_50 ) -> V_216 ) ;
if ( V_10 ) {
if ( ! ( V_29 & V_250 ) )
F_147 ( & V_9 -> V_87 , V_50 ) ;
return V_10 ;
}
if ( ! ( V_29 & V_250 ) ) {
if ( V_9 -> V_80 == V_138 ) {
if ( V_246 < V_247 ) {
F_124 ( V_50 ) -> V_242 = V_242 + V_246 ;
F_147 ( & V_9 -> V_87 , V_50 ) ;
goto V_162;
}
}
F_39 ( V_50 ) ;
if ( V_7 -> V_35 == V_108 ) {
F_125 ( & V_7 -> V_64 ) ;
if ( F_19 ( & V_7 -> V_64 ) > V_7 -> V_62 ) {
F_41 ( 1 ) ;
F_49 ( V_9 ) ;
return - V_251 ;
}
}
F_149 ( & V_7 -> V_124 . V_12 ) ;
V_248 = F_150 ( & V_7 -> V_22 ) ;
while ( V_248 ) {
F_124 ( V_248 ) -> V_242 = 0 ;
if ( F_138 ( V_9 , V_248 ) ) {
F_147 ( & V_7 -> V_22 ,
V_248 ) ;
break;
}
V_248 = F_150 ( & V_7 -> V_22 ) ;
}
if ( F_59 ( & V_7 -> V_22 ) ) {
if ( ! F_143 ( & V_7 -> V_124 . V_125 ) )
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
F_151 ( & V_7 -> V_124 . V_12 ) ;
}
V_162:
if ( V_9 -> V_80 == V_81 && ( V_29 & V_252 ) )
V_246 = V_247 ;
return V_246 ;
}
static inline unsigned int F_152 ( struct V_8 * V_94 )
{
struct V_6 * V_147 , * V_148 ;
struct V_8 * V_9 ;
F_88 (isk, n, &iucv_sk(parent)->accept_q, accept_q) {
V_9 = (struct V_8 * ) V_147 ;
if ( V_9 -> V_13 == V_16 )
return V_253 | V_254 ;
}
return 0 ;
}
unsigned int F_153 ( struct V_255 * V_255 , struct V_115 * V_8 ,
T_5 * V_45 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
unsigned int V_256 = 0 ;
F_154 ( V_255 , F_107 ( V_9 ) , V_45 ) ;
if ( V_9 -> V_13 == V_19 )
return F_152 ( V_9 ) ;
if ( V_9 -> V_23 || ! F_59 ( & V_9 -> V_88 ) )
V_256 |= V_257 |
( F_45 ( V_9 , V_258 ) ? V_259 : 0 ) ;
if ( V_9 -> V_104 & V_106 )
V_256 |= V_260 ;
if ( V_9 -> V_104 == V_261 )
V_256 |= V_262 ;
if ( ! F_59 ( & V_9 -> V_87 ) ||
( V_9 -> V_104 & V_106 ) )
V_256 |= V_253 | V_254 ;
if ( V_9 -> V_13 == V_20 )
V_256 |= V_262 ;
if ( V_9 -> V_13 == V_14 )
V_256 |= V_253 ;
if ( F_155 ( V_9 ) && F_17 ( V_9 ) )
V_256 |= V_263 | V_264 | V_265 ;
else
F_156 ( V_266 , V_9 ) ;
return V_256 ;
}
static int F_157 ( struct V_115 * V_8 , int V_267 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_26 V_202 ;
int V_10 = 0 ;
V_267 ++ ;
if ( ( V_267 & ~ V_261 ) || ! V_267 )
return - V_160 ;
F_58 ( V_9 ) ;
switch ( V_9 -> V_13 ) {
case V_19 :
case V_14 :
case V_15 :
case V_20 :
V_10 = - V_215 ;
goto V_228;
default:
break;
}
if ( V_267 == V_105 || V_267 == V_261 ) {
if ( V_7 -> V_35 == V_36 ) {
V_202 . V_216 = 0 ;
V_202 . V_229 = 0 ;
V_10 = V_100 -> V_198 ( V_7 -> V_37 , & V_202 ,
V_30 , 0 , ( void * ) V_240 , 8 ) ;
if ( V_10 ) {
switch ( V_10 ) {
case 1 :
V_10 = - V_215 ;
break;
case 2 :
V_10 = - V_113 ;
break;
default:
V_10 = - V_215 ;
break;
}
}
} else
F_55 ( V_9 , V_268 ) ;
}
V_9 -> V_104 |= V_267 ;
if ( V_267 == V_106 || V_267 == V_261 ) {
if ( ( V_7 -> V_35 == V_36 ) &&
V_7 -> V_37 ) {
V_10 = V_100 -> V_269 ( V_7 -> V_37 , NULL ) ;
if ( V_10 )
V_10 = - V_215 ;
}
F_12 ( & V_9 -> V_87 ) ;
}
V_9 -> V_25 ( V_9 ) ;
V_228:
F_62 ( V_9 ) ;
return V_10 ;
}
static int F_158 ( struct V_115 * V_8 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
int V_10 = 0 ;
if ( ! V_9 )
return 0 ;
F_49 ( V_9 ) ;
F_159 ( V_9 ) ;
F_50 ( V_9 ) ;
return V_10 ;
}
static int F_160 ( struct V_115 * V_8 , int V_270 , int V_271 ,
char T_6 * V_272 , unsigned int V_273 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
int V_274 ;
int V_239 ;
if ( V_270 != V_218 )
return - V_275 ;
if ( V_273 < sizeof( int ) )
return - V_160 ;
if ( F_161 ( V_274 , ( int T_6 * ) V_272 ) )
return - V_251 ;
V_239 = 0 ;
F_58 ( V_9 ) ;
switch ( V_271 ) {
case V_276 :
if ( V_274 )
V_7 -> V_29 |= V_30 ;
else
V_7 -> V_29 &= ~ V_30 ;
break;
case V_277 :
switch ( V_9 -> V_13 ) {
case V_17 :
case V_18 :
if ( V_274 < 1 || V_274 > ( V_278 ) ( ~ 0 ) )
V_239 = - V_160 ;
else
V_7 -> V_62 = V_274 ;
break;
default:
V_239 = - V_160 ;
break;
}
break;
default:
V_239 = - V_275 ;
break;
}
F_62 ( V_9 ) ;
return V_239 ;
}
static int F_162 ( struct V_115 * V_8 , int V_270 , int V_271 ,
char T_6 * V_272 , int T_6 * V_273 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
unsigned int V_274 ;
int V_78 ;
if ( V_270 != V_218 )
return - V_275 ;
if ( F_161 ( V_78 , V_273 ) )
return - V_251 ;
if ( V_78 < 0 )
return - V_160 ;
V_78 = F_145 (unsigned int, len, sizeof(int)) ;
switch ( V_271 ) {
case V_276 :
V_274 = ( V_7 -> V_29 & V_30 ) ? 1 : 0 ;
break;
case V_277 :
F_58 ( V_9 ) ;
V_274 = ( V_7 -> V_37 != NULL ) ? V_7 -> V_37 -> V_38
: V_7 -> V_62 ;
F_62 ( V_9 ) ;
break;
case V_279 :
if ( V_9 -> V_13 == V_17 )
return - V_161 ;
V_274 = ( V_7 -> V_74 ) ? V_7 -> V_74 -> V_79 -
sizeof( struct V_51 ) - V_56 :
0x7fffffff ;
break;
default:
return - V_275 ;
}
if ( F_163 ( V_78 , V_273 ) )
return - V_251 ;
if ( F_164 ( V_272 , & V_274 , V_78 ) )
return - V_251 ;
return 0 ;
}
static int F_165 ( struct V_99 * V_37 ,
T_2 V_280 [ 8 ] , T_2 V_281 [ 16 ] )
{
unsigned char V_98 [ 16 ] ;
unsigned char V_282 [ 16 ] ;
unsigned char V_72 [ 8 ] ;
struct V_8 * V_9 , * V_186 ;
struct V_6 * V_7 , * V_283 ;
int V_10 ;
memcpy ( V_72 , V_281 , 8 ) ;
F_166 ( V_72 , 8 ) ;
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
return - V_160 ;
F_167 ( V_9 ) ;
F_2 ( V_98 , V_7 -> V_72 ) ;
F_1 ( V_98 , V_7 -> V_68 ) ;
F_31 ( V_98 , sizeof( V_98 ) ) ;
if ( V_9 -> V_13 != V_19 ) {
V_10 = V_100 -> V_101 ( V_37 , V_98 ) ;
F_54 ( V_37 ) ;
goto V_228;
}
if ( F_168 ( V_9 ) ) {
V_10 = V_100 -> V_101 ( V_37 , V_98 ) ;
F_54 ( V_37 ) ;
goto V_228;
}
V_186 = F_65 ( NULL , V_9 -> V_80 , V_84 , 0 ) ;
if ( ! V_186 ) {
V_10 = V_100 -> V_101 ( V_37 , V_98 ) ;
F_54 ( V_37 ) ;
goto V_228;
}
V_283 = F_10 ( V_186 ) ;
F_63 ( V_186 , V_9 ) ;
memcpy ( V_283 -> V_68 , V_281 + 8 , 8 ) ;
F_166 ( V_283 -> V_68 , 8 ) ;
memcpy ( V_283 -> V_66 , V_280 , 8 ) ;
memcpy ( V_283 -> V_72 , V_7 -> V_72 , 8 ) ;
memcpy ( V_283 -> V_70 , V_7 -> V_70 , 8 ) ;
V_283 -> V_37 = V_37 ;
F_1 ( V_282 , V_281 + 8 ) ;
memcpy ( V_282 + 8 , V_283 -> V_72 , 8 ) ;
F_31 ( V_282 + 8 , 8 ) ;
V_283 -> V_62 = V_7 -> V_62 ;
V_37 -> V_38 = V_7 -> V_62 ;
V_10 = V_100 -> V_284 ( V_37 , & V_175 , V_282 , V_186 ) ;
if ( V_10 ) {
F_11 ( V_186 , 1 ) ;
F_50 ( V_186 ) ;
goto V_228;
}
F_79 ( V_9 , V_186 ) ;
V_186 -> V_13 = V_16 ;
V_9 -> V_285 ( V_9 ) ;
V_10 = 0 ;
V_228:
F_169 ( V_9 ) ;
return 0 ;
}
static void F_170 ( struct V_99 * V_37 , T_2 V_281 [ 16 ] )
{
struct V_8 * V_9 = V_37 -> V_286 ;
V_9 -> V_13 = V_16 ;
V_9 -> V_25 ( V_9 ) ;
}
static void F_171 ( struct V_99 * V_37 , struct V_26 * V_27 )
{
struct V_8 * V_9 = V_37 -> V_286 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_49 * V_50 ;
struct V_244 * V_287 ;
int V_78 ;
if ( V_9 -> V_104 & V_106 ) {
V_100 -> V_288 ( V_37 , V_27 ) ;
return;
}
F_172 ( & V_7 -> V_124 . V_12 ) ;
if ( ! F_143 ( & V_7 -> V_124 . V_125 ) ||
! F_59 ( & V_7 -> V_22 ) )
goto V_289;
V_78 = F_19 ( & V_9 -> V_90 ) ;
V_78 += F_173 ( F_15 ( V_27 ) ) ;
if ( V_78 > V_9 -> V_290 )
goto V_289;
V_50 = F_132 ( F_15 ( V_27 ) ) ;
if ( ! V_50 )
goto V_289;
F_135 ( V_9 , V_50 , V_37 , V_27 ) ;
goto V_291;
V_289:
V_287 = F_174 ( sizeof( struct V_244 ) , V_84 | V_133 ) ;
if ( ! V_287 )
goto V_291;
V_287 -> V_37 = V_37 ;
V_287 -> V_27 = * V_27 ;
F_82 ( & V_287 -> V_125 , & V_7 -> V_124 . V_125 ) ;
V_291:
F_175 ( & V_7 -> V_124 . V_12 ) ;
}
static void F_176 ( struct V_99 * V_37 ,
struct V_26 * V_27 )
{
struct V_8 * V_9 = V_37 -> V_286 ;
struct V_49 * V_292 = NULL ;
struct V_293 * V_125 = & F_10 ( V_9 ) -> V_21 ;
struct V_49 * V_294 = V_125 -> V_295 ;
unsigned long V_29 ;
F_167 ( V_9 ) ;
if ( ! F_59 ( V_125 ) ) {
F_81 ( & V_125 -> V_12 , V_29 ) ;
while ( V_294 != (struct V_49 * ) V_125 ) {
if ( V_27 -> V_229 == F_124 ( V_294 ) -> V_229 ) {
V_292 = V_294 ;
break;
}
V_294 = V_294 -> V_295 ;
}
if ( V_292 )
F_177 ( V_292 , V_125 ) ;
F_83 ( & V_125 -> V_12 , V_29 ) ;
if ( V_292 ) {
F_39 ( V_292 ) ;
F_20 ( V_9 ) ;
}
}
if ( V_9 -> V_13 == V_15 ) {
if ( F_59 ( & F_10 ( V_9 ) -> V_21 ) ) {
V_9 -> V_13 = V_20 ;
V_9 -> V_25 ( V_9 ) ;
}
}
F_169 ( V_9 ) ;
}
static void F_178 ( struct V_99 * V_37 , T_2 V_281 [ 16 ] )
{
struct V_8 * V_9 = V_37 -> V_286 ;
if ( V_9 -> V_13 == V_20 )
return;
F_167 ( V_9 ) ;
F_11 ( V_9 , 1 ) ;
V_9 -> V_13 = V_14 ;
V_9 -> V_25 ( V_9 ) ;
F_169 ( V_9 ) ;
}
static void F_179 ( struct V_99 * V_37 , T_2 V_281 [ 16 ] )
{
struct V_8 * V_9 = V_37 -> V_286 ;
F_167 ( V_9 ) ;
if ( V_9 -> V_13 != V_20 ) {
V_9 -> V_104 |= V_105 ;
V_9 -> V_25 ( V_9 ) ;
}
F_169 ( V_9 ) ;
}
static void F_180 ( struct V_49 * V_50 )
{
struct V_51 * V_296 =
(struct V_51 * ) V_50 -> V_197 ;
char V_297 [ 8 ] ;
char V_298 [ 8 ] ;
F_31 ( V_296 -> V_65 , sizeof( V_296 -> V_65 ) ) ;
F_31 ( V_296 -> V_67 , sizeof( V_296 -> V_67 ) ) ;
F_31 ( V_296 -> V_69 , sizeof( V_296 -> V_69 ) ) ;
F_31 ( V_296 -> V_71 , sizeof( V_296 -> V_71 ) ) ;
memcpy ( V_297 , V_296 -> V_69 , 8 ) ;
memcpy ( V_298 , V_296 -> V_71 , 8 ) ;
memcpy ( V_296 -> V_69 , V_296 -> V_65 , 8 ) ;
memcpy ( V_296 -> V_71 , V_296 -> V_67 , 8 ) ;
memcpy ( V_296 -> V_65 , V_297 , 8 ) ;
memcpy ( V_296 -> V_67 , V_298 , 8 ) ;
F_28 ( V_50 , V_56 ) ;
memset ( V_50 -> V_197 , 0 , V_56 ) ;
}
static int F_181 ( struct V_8 * V_9 , struct V_49 * V_50 )
{
struct V_8 * V_186 ;
struct V_6 * V_7 , * V_283 ;
struct V_51 * V_296 ;
int V_10 ;
V_7 = F_10 ( V_9 ) ;
V_296 = (struct V_51 * ) V_50 -> V_197 ;
if ( ! V_7 ) {
F_180 ( V_50 ) ;
V_296 -> V_29 = V_60 | V_109 ;
V_10 = F_36 ( V_50 ) ;
goto V_214;
}
V_186 = F_65 ( NULL , V_9 -> V_80 , V_84 , 0 ) ;
F_167 ( V_9 ) ;
if ( ( V_9 -> V_13 != V_19 ) ||
F_168 ( V_9 ) ||
! V_186 ) {
F_180 ( V_50 ) ;
V_296 -> V_29 = V_60 | V_109 ;
V_10 = F_36 ( V_50 ) ;
F_50 ( V_186 ) ;
F_169 ( V_9 ) ;
goto V_214;
}
V_283 = F_10 ( V_186 ) ;
F_63 ( V_186 , V_9 ) ;
V_283 -> V_35 = V_108 ;
V_283 -> V_62 = V_7 -> V_62 ;
if ( ! V_296 -> V_61 )
V_283 -> V_40 = V_171 ;
else
V_283 -> V_40 = V_296 -> V_61 ;
memcpy ( V_283 -> V_68 , V_296 -> V_71 , 8 ) ;
memcpy ( V_283 -> V_66 , V_296 -> V_69 , 8 ) ;
memcpy ( V_283 -> V_72 , V_7 -> V_72 , 8 ) ;
memcpy ( V_283 -> V_70 , V_7 -> V_70 , 8 ) ;
V_186 -> V_114 = V_9 -> V_114 ;
V_283 -> V_74 = V_7 -> V_74 ;
F_94 ( V_283 -> V_74 ) ;
F_180 ( V_50 ) ;
V_296 -> V_29 = V_60 | V_299 ;
V_296 -> V_61 = V_283 -> V_62 ;
V_10 = F_36 ( V_50 ) ;
if ( ! V_10 ) {
F_79 ( V_9 , V_186 ) ;
V_186 -> V_13 = V_16 ;
V_9 -> V_285 ( V_9 ) ;
} else
F_50 ( V_186 ) ;
F_169 ( V_9 ) ;
V_214:
return V_300 ;
}
static int F_182 ( struct V_8 * V_9 , struct V_49 * V_50 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_51 * V_296 =
(struct V_51 * ) V_50 -> V_197 ;
if ( ! V_7 )
goto V_214;
if ( V_9 -> V_13 != V_18 )
goto V_214;
F_167 ( V_9 ) ;
V_7 -> V_40 = V_296 -> V_61 ;
V_9 -> V_13 = V_16 ;
V_9 -> V_25 ( V_9 ) ;
F_169 ( V_9 ) ;
V_214:
F_39 ( V_50 ) ;
return V_300 ;
}
static int F_183 ( struct V_8 * V_9 , struct V_49 * V_50 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
if ( ! V_7 )
goto V_214;
if ( V_9 -> V_13 != V_18 )
goto V_214;
F_167 ( V_9 ) ;
V_9 -> V_13 = V_14 ;
V_9 -> V_25 ( V_9 ) ;
F_169 ( V_9 ) ;
V_214:
F_39 ( V_50 ) ;
return V_300 ;
}
static int F_184 ( struct V_8 * V_9 , struct V_49 * V_50 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
if ( ! V_7 )
goto V_214;
F_167 ( V_9 ) ;
if ( V_9 -> V_13 == V_16 ) {
V_9 -> V_13 = V_14 ;
V_9 -> V_25 ( V_9 ) ;
}
F_169 ( V_9 ) ;
V_214:
F_39 ( V_50 ) ;
return V_300 ;
}
static int F_185 ( struct V_8 * V_9 , struct V_49 * V_50 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_51 * V_296 =
(struct V_51 * ) V_50 -> V_197 ;
if ( ! V_7 )
return V_300 ;
if ( V_9 -> V_13 != V_16 )
return V_300 ;
F_40 ( V_296 -> V_61 , & V_7 -> V_39 ) ;
F_20 ( V_9 ) ;
return V_300 ;
}
static int F_186 ( struct V_8 * V_9 , struct V_49 * V_50 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
if ( ! V_7 ) {
F_39 ( V_50 ) ;
return V_300 ;
}
if ( V_9 -> V_13 != V_16 ) {
F_39 ( V_50 ) ;
return V_300 ;
}
if ( V_9 -> V_104 & V_106 ) {
F_39 ( V_50 ) ;
return V_300 ;
}
F_187 ( V_50 , sizeof( struct V_51 ) ) ;
F_188 ( V_50 ) ;
F_30 ( V_50 ) ;
F_124 ( V_50 ) -> V_242 = 0 ;
if ( F_137 ( V_9 , V_50 ) ) {
F_125 ( & V_9 -> V_243 ) ;
F_39 ( V_50 ) ;
return V_300 ;
}
F_172 ( & V_7 -> V_124 . V_12 ) ;
if ( F_59 ( & V_7 -> V_22 ) ) {
if ( F_138 ( V_9 , V_50 ) )
F_35 ( & V_7 -> V_22 , V_50 ) ;
} else
F_35 ( & F_10 ( V_9 ) -> V_22 , V_50 ) ;
F_175 ( & V_7 -> V_124 . V_12 ) ;
return V_300 ;
}
static int F_189 ( struct V_49 * V_50 , struct V_156 * V_4 ,
struct V_301 * V_302 , struct V_156 * V_303 )
{
struct V_8 * V_9 ;
struct V_6 * V_7 ;
struct V_51 * V_296 ;
char V_304 [ 8 ] ;
int V_10 = 0 ;
if ( V_50 -> V_78 < ( V_56 + sizeof( struct V_51 ) ) ) {
F_134 ( 1 , L_10 ,
( int ) V_50 -> V_78 ,
( int ) ( V_56 + sizeof( struct V_51 ) ) ) ;
F_39 ( V_50 ) ;
return V_300 ;
}
if ( F_128 ( V_50 ) < ( V_56 + sizeof( struct V_51 ) ) )
if ( F_190 ( V_50 ) ) {
F_134 ( 1 , L_11 ,
( int ) V_50 -> V_78 ) ;
F_39 ( V_50 ) ;
return V_300 ;
}
F_187 ( V_50 , V_56 ) ;
V_296 = (struct V_51 * ) V_50 -> V_197 ;
F_166 ( V_296 -> V_67 , sizeof( V_296 -> V_67 ) ) ;
F_166 ( V_296 -> V_65 , sizeof( V_296 -> V_65 ) ) ;
F_166 ( V_296 -> V_71 , sizeof( V_296 -> V_71 ) ) ;
F_166 ( V_296 -> V_69 , sizeof( V_296 -> V_69 ) ) ;
memset ( V_304 , 0 , sizeof( V_304 ) ) ;
V_7 = NULL ;
V_9 = NULL ;
F_8 ( & V_11 . V_12 ) ;
F_9 (sk, &iucv_sk_list.head) {
if ( V_296 -> V_29 == V_60 ) {
if ( ( ! memcmp ( & F_10 ( V_9 ) -> V_72 ,
V_296 -> V_67 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_70 ,
V_296 -> V_65 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_68 , V_304 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_66 ,
V_304 , 8 ) ) ) {
V_7 = F_10 ( V_9 ) ;
break;
}
} else {
if ( ( ! memcmp ( & F_10 ( V_9 ) -> V_72 ,
V_296 -> V_67 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_70 ,
V_296 -> V_65 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_68 ,
V_296 -> V_71 , 8 ) ) &&
( ! memcmp ( & F_10 ( V_9 ) -> V_66 ,
V_296 -> V_69 , 8 ) ) ) {
V_7 = F_10 ( V_9 ) ;
break;
}
}
}
F_13 ( & V_11 . V_12 ) ;
if ( ! V_7 )
V_9 = NULL ;
switch ( V_296 -> V_29 ) {
case V_60 :
V_10 = F_181 ( V_9 , V_50 ) ;
break;
case ( V_60 | V_299 ) :
V_10 = F_182 ( V_9 , V_50 ) ;
break;
case ( V_60 | V_109 ) :
V_10 = F_183 ( V_9 , V_50 ) ;
break;
case ( V_109 ) :
V_10 = F_184 ( V_9 , V_50 ) ;
break;
case ( V_63 ) :
V_10 = F_185 ( V_9 , V_50 ) ;
if ( V_50 -> V_78 == sizeof( struct V_51 ) ) {
F_39 ( V_50 ) ;
break;
}
case ( V_268 ) :
case 0 :
F_124 ( V_50 ) -> V_216 = V_296 -> V_73 . V_216 ;
V_10 = F_186 ( V_9 , V_50 ) ;
break;
default:
;
}
return V_10 ;
}
static void V_128 ( struct V_49 * V_50 ,
enum V_305 V_148 )
{
struct V_8 * V_147 = V_50 -> V_9 ;
struct V_8 * V_9 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_293 * V_125 ;
struct V_49 * V_294 ;
struct V_49 * V_53 ;
unsigned long V_29 ;
F_191 ( & V_11 . V_12 , V_29 ) ;
F_9 (sk, &iucv_sk_list.head)
if ( V_9 == V_147 ) {
V_7 = F_10 ( V_9 ) ;
break;
}
F_192 ( & V_11 . V_12 , V_29 ) ;
if ( ! V_7 || F_45 ( V_9 , V_95 ) )
return;
V_125 = & V_7 -> V_21 ;
F_81 ( & V_125 -> V_12 , V_29 ) ;
if ( F_59 ( V_125 ) )
goto V_291;
V_294 = V_125 -> V_295 ;
V_53 = V_294 -> V_295 ;
while ( V_294 != (struct V_49 * ) V_125 ) {
if ( F_129 ( V_294 ) == F_129 ( V_50 ) ) {
switch ( V_148 ) {
case V_306 :
F_177 ( V_294 , V_125 ) ;
F_39 ( V_294 ) ;
F_20 ( V_9 ) ;
break;
case V_307 :
F_125 ( & V_7 -> V_41 ) ;
break;
case V_308 :
F_177 ( V_294 , V_125 ) ;
F_126 ( & V_7 -> V_41 ) ;
if ( F_19 ( & V_7 -> V_41 ) <= 0 )
F_20 ( V_9 ) ;
F_39 ( V_294 ) ;
break;
case V_309 :
case V_310 :
case V_311 :
case V_312 :
case V_313 :
F_177 ( V_294 , V_125 ) ;
F_39 ( V_294 ) ;
if ( V_9 -> V_13 == V_16 ) {
V_9 -> V_13 = V_14 ;
V_9 -> V_25 ( V_9 ) ;
}
break;
}
break;
}
V_294 = V_53 ;
V_53 = V_53 -> V_295 ;
}
V_291:
F_83 ( & V_125 -> V_12 , V_29 ) ;
if ( V_9 -> V_13 == V_15 ) {
if ( F_59 ( & F_10 ( V_9 ) -> V_21 ) ) {
V_9 -> V_13 = V_20 ;
V_9 -> V_25 ( V_9 ) ;
}
}
}
static int F_193 ( struct V_314 * V_292 ,
unsigned long V_315 , void * V_316 )
{
struct V_156 * V_317 = F_194 ( V_316 ) ;
struct V_8 * V_9 ;
struct V_6 * V_7 ;
switch ( V_315 ) {
case V_318 :
case V_319 :
F_9 (sk, &iucv_sk_list.head) {
V_7 = F_10 ( V_9 ) ;
if ( ( V_7 -> V_74 == V_317 ) &&
( V_9 -> V_13 == V_16 ) ) {
if ( V_315 == V_319 )
F_55 ( V_9 , V_109 ) ;
V_9 -> V_13 = V_14 ;
V_9 -> V_25 ( V_9 ) ;
}
}
break;
case V_320 :
case V_321 :
default:
break;
}
return V_322 ;
}
static int F_195 ( void )
{
int V_10 ;
V_10 = V_100 -> V_323 ( & V_175 , 0 ) ;
if ( V_10 )
goto V_214;
V_324 . V_325 = V_100 -> V_325 ;
V_10 = F_196 ( & V_324 ) ;
if ( V_10 )
goto V_326;
V_327 = F_174 ( sizeof( struct V_3 ) , V_142 ) ;
if ( ! V_327 ) {
V_10 = - V_85 ;
goto V_328;
}
F_197 ( V_327 , L_12 ) ;
V_327 -> V_325 = V_100 -> V_325 ;
V_327 -> V_94 = V_100 -> V_329 ;
V_327 -> V_330 = ( void ( * ) ( struct V_3 * ) ) F_141 ;
V_327 -> V_331 = & V_324 ;
V_10 = F_198 ( V_327 ) ;
if ( V_10 )
goto V_328;
return 0 ;
V_328:
F_199 ( & V_324 ) ;
V_326:
V_100 -> V_332 ( & V_175 , 0 ) ;
V_214:
return V_10 ;
}
static int T_7 F_200 ( void )
{
int V_10 ;
if ( V_333 ) {
F_201 ( L_13 , V_167 , sizeof( V_167 ) , & V_10 ) ;
if ( F_96 ( V_10 ) ) {
F_41 ( V_10 ) ;
V_10 = - V_136 ;
goto V_214;
}
V_100 = F_202 ( F_203 ( V_334 ) , L_14 ) ;
if ( ! V_100 ) {
F_5 ( V_5 L_15 ) ;
memset ( & V_167 , 0 , sizeof( V_167 ) ) ;
}
} else {
memset ( & V_167 , 0 , sizeof( V_167 ) ) ;
V_100 = NULL ;
}
V_10 = F_204 ( & V_121 , 0 ) ;
if ( V_10 )
goto V_214;
V_10 = F_205 ( & V_335 ) ;
if ( V_10 )
goto V_336;
if ( V_100 ) {
V_10 = F_195 () ;
if ( V_10 )
goto V_337;
} else
F_206 ( & V_338 ) ;
F_207 ( & V_339 ) ;
return 0 ;
V_337:
F_208 ( V_120 ) ;
V_336:
F_209 ( & V_121 ) ;
V_214:
if ( V_100 )
F_210 ( V_334 ) ;
return V_10 ;
}
static void T_8 F_211 ( void )
{
if ( V_100 ) {
F_212 ( V_327 ) ;
F_199 ( & V_324 ) ;
V_100 -> V_332 ( & V_175 , 0 ) ;
F_210 ( V_334 ) ;
} else
F_213 ( & V_338 ) ;
F_214 ( & V_339 ) ;
F_208 ( V_120 ) ;
F_209 ( & V_121 ) ;
}
