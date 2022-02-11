static inline void F_1 ( unsigned char * V_1 , char * V_2 )
{
memcpy ( V_1 , V_2 , 8 ) ;
}
static inline void F_2 ( unsigned char * V_1 , char * V_2 )
{
memcpy ( & V_1 [ 8 ] , V_2 , 8 ) ;
}
static void F_3 ( struct V_3 * V_4 )
{
struct V_5 * V_6 ;
while ( ( V_6 = F_4 ( V_4 ) ) != NULL ) {
if ( V_6 -> V_7 )
F_5 ( V_6 -> V_7 ) ;
F_6 ( V_6 ) ;
}
}
static int F_7 ( struct V_8 * V_7 )
{
#ifdef F_8
F_9 ( V_9 L_1 ) ;
#endif
return 0 ;
}
static void F_10 ( struct V_8 * V_7 )
{
#ifdef F_8
F_9 ( V_9 L_2 ) ;
#endif
}
static int F_11 ( struct V_8 * V_7 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_16 = 0 ;
#ifdef F_8
F_9 ( V_9 L_3 ) ;
#endif
F_12 ( & V_17 . V_18 ) ;
F_13 (sk, node, &iucv_sk_list.head) {
V_11 = F_14 ( V_13 ) ;
F_3 ( & V_11 -> V_19 ) ;
F_15 ( & V_11 -> V_20 ) ;
switch ( V_13 -> V_21 ) {
case V_22 :
case V_23 :
case V_24 :
if ( V_11 -> V_25 ) {
V_16 = V_26 -> V_27 ( V_11 -> V_25 , NULL ) ;
F_16 ( V_11 -> V_25 ) ;
V_11 -> V_25 = NULL ;
}
break;
case V_28 :
case V_29 :
case V_30 :
case V_31 :
default:
break;
}
}
F_17 ( & V_17 . V_18 ) ;
return V_16 ;
}
static int F_18 ( struct V_8 * V_7 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
#ifdef F_8
F_9 ( V_9 L_4 ) ;
#endif
F_12 ( & V_17 . V_18 ) ;
F_13 (sk, node, &iucv_sk_list.head) {
switch ( V_13 -> V_21 ) {
case V_24 :
V_13 -> V_32 = V_33 ;
V_13 -> V_21 = V_22 ;
V_13 -> V_34 ( V_13 ) ;
break;
case V_22 :
case V_23 :
case V_30 :
case V_29 :
case V_28 :
default:
break;
}
}
F_17 ( & V_17 . V_18 ) ;
return 0 ;
}
static inline T_1 F_19 ( struct V_35 * V_36 )
{
T_1 V_37 ;
if ( V_36 -> V_38 & V_39 ) {
V_37 = 0xff - V_36 -> V_40 [ 7 ] ;
return ( V_37 < 8 ) ? V_37 : 8 ;
}
return V_36 -> V_41 ;
}
static int F_20 ( struct V_12 * V_13 , int V_42 , int V_43 )
{
return ( V_13 -> V_21 == V_42 || V_13 -> V_21 == V_43 ) ;
}
static inline int F_21 ( struct V_12 * V_13 )
{
struct V_10 * V_11 = F_14 ( V_13 ) ;
if ( V_13 -> V_21 != V_24 )
return 1 ;
if ( V_11 -> V_44 == V_45 )
return ( F_22 ( & V_11 -> V_19 ) < V_11 -> V_25 -> V_46 ) ;
else
return ( ( F_23 ( & V_11 -> V_47 ) < V_11 -> V_48 ) &&
( F_23 ( & V_11 -> V_49 ) <= 0 ) ) ;
}
static void F_24 ( struct V_12 * V_13 )
{
struct V_50 * V_51 ;
F_25 () ;
V_51 = F_26 ( V_13 -> V_52 ) ;
if ( F_27 ( V_51 ) )
F_28 ( & V_51 -> V_53 ) ;
F_29 ( V_13 , V_54 , V_55 ) ;
F_30 () ;
}
static int F_31 ( struct V_35 * V_56 , struct V_12 * V_12 ,
struct V_5 * V_6 , T_2 V_38 )
{
struct V_57 * V_57 = F_32 ( V_12 ) ;
struct V_10 * V_11 = F_14 ( V_12 ) ;
struct V_58 * V_59 ;
struct V_5 * V_60 ;
int V_16 , V_61 = 0 ;
memset ( V_6 -> V_62 , 0 , V_63 ) ;
V_59 = (struct V_58 * ) F_33 ( V_6 ,
sizeof( struct V_58 ) ) ;
F_34 ( V_6 ) ;
F_35 ( V_6 ) ;
F_33 ( V_6 , V_63 ) ;
F_34 ( V_6 ) ;
memset ( V_59 , 0 , sizeof( struct V_58 ) ) ;
V_59 -> V_64 = V_65 ;
V_59 -> V_66 = 1 ;
V_59 -> V_38 = V_38 ;
if ( V_38 == V_67 )
V_59 -> V_68 = V_11 -> V_69 ;
else if ( ( V_38 == V_70 ) || ! V_38 ) {
V_61 = F_23 ( & V_11 -> V_71 ) ;
V_59 -> V_68 = V_61 ;
if ( V_61 )
V_59 -> V_38 = V_59 -> V_38 | V_70 ;
}
memcpy ( V_59 -> V_72 , V_11 -> V_73 , 8 ) ;
memcpy ( V_59 -> V_74 , V_11 -> V_75 , 8 ) ;
memcpy ( V_59 -> V_76 , V_11 -> V_77 , 8 ) ;
memcpy ( V_59 -> V_78 , V_11 -> V_79 , 8 ) ;
F_36 ( V_59 -> V_72 , sizeof( V_59 -> V_72 ) ) ;
F_36 ( V_59 -> V_74 , sizeof( V_59 -> V_74 ) ) ;
F_36 ( V_59 -> V_76 , sizeof( V_59 -> V_76 ) ) ;
F_36 ( V_59 -> V_78 , sizeof( V_59 -> V_78 ) ) ;
if ( V_56 )
memcpy ( & V_59 -> V_80 , V_56 , sizeof( struct V_35 ) ) ;
V_6 -> V_7 = F_37 ( V_57 , V_12 -> V_81 ) ;
if ( ! V_6 -> V_7 )
return - V_82 ;
if ( ! ( V_6 -> V_7 -> V_38 & V_83 ) )
return - V_84 ;
if ( V_6 -> V_85 > V_6 -> V_7 -> V_86 ) {
if ( V_12 -> V_87 == V_88 )
return - V_89 ;
else
F_38 ( V_6 , V_6 -> V_7 -> V_86 ) ;
}
V_6 -> V_90 = V_65 ;
F_39 ( V_6 ) -> V_91 |= V_92 ;
V_60 = F_40 ( V_6 , V_93 ) ;
if ( ! V_60 )
return - V_94 ;
F_41 ( & V_11 -> V_19 , V_60 ) ;
V_16 = F_42 ( V_6 ) ;
if ( V_16 ) {
F_43 ( V_60 , & V_11 -> V_19 ) ;
F_5 ( V_60 -> V_7 ) ;
F_6 ( V_60 ) ;
} else {
F_44 ( V_61 , & V_11 -> V_71 ) ;
F_45 ( F_23 ( & V_11 -> V_71 ) < 0 ) ;
}
return V_16 ;
}
static struct V_12 * F_46 ( char * V_95 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
F_13 (sk, node, &iucv_sk_list.head)
if ( ! memcmp ( & F_14 ( V_13 ) -> V_79 , V_95 , 8 ) )
return V_13 ;
return NULL ;
}
static void F_47 ( struct V_12 * V_13 )
{
F_15 ( & V_13 -> V_96 ) ;
F_15 ( & V_13 -> V_97 ) ;
}
static void F_48 ( struct V_12 * V_98 )
{
struct V_12 * V_13 ;
while ( ( V_13 = F_49 ( V_98 , NULL ) ) ) {
F_50 ( V_13 ) ;
F_51 ( V_13 ) ;
}
V_98 -> V_21 = V_31 ;
}
static void F_51 ( struct V_12 * V_13 )
{
if ( ! F_52 ( V_13 , V_99 ) || V_13 -> V_100 )
return;
F_53 ( & V_17 , V_13 ) ;
F_54 ( V_13 , V_101 ) ;
F_55 ( V_13 ) ;
}
static void F_50 ( struct V_12 * V_13 )
{
unsigned char V_102 [ 16 ] ;
struct V_10 * V_11 = F_14 ( V_13 ) ;
unsigned long V_103 ;
int V_16 , V_104 ;
struct V_5 * V_6 ;
F_56 ( V_13 ) ;
switch ( V_13 -> V_21 ) {
case V_30 :
F_48 ( V_13 ) ;
break;
case V_24 :
if ( V_11 -> V_44 == V_105 ) {
V_104 = sizeof( struct V_58 ) + V_63 ;
V_6 = F_57 ( V_13 , V_104 , 1 , & V_16 ) ;
if ( V_6 ) {
F_58 ( V_6 , V_104 ) ;
V_16 = F_31 ( NULL , V_13 , V_6 ,
V_106 ) ;
}
V_13 -> V_21 = V_22 ;
V_13 -> V_34 ( V_13 ) ;
}
case V_22 :
V_13 -> V_21 = V_23 ;
V_13 -> V_34 ( V_13 ) ;
if ( ! F_59 ( & V_11 -> V_19 ) ) {
if ( F_52 ( V_13 , V_107 ) && V_13 -> V_108 )
V_103 = V_13 -> V_108 ;
else
V_103 = V_109 ;
F_60 ( V_13 ,
F_20 ( V_13 , V_31 , 0 ) ,
V_103 ) ;
}
case V_23 :
V_13 -> V_21 = V_31 ;
V_13 -> V_34 ( V_13 ) ;
if ( V_11 -> V_25 ) {
F_2 ( V_102 , V_11 -> V_79 ) ;
F_1 ( V_102 , V_11 -> V_75 ) ;
F_36 ( V_102 , sizeof( V_102 ) ) ;
V_26 -> V_27 ( V_11 -> V_25 , V_102 ) ;
F_16 ( V_11 -> V_25 ) ;
V_11 -> V_25 = NULL ;
}
V_13 -> V_32 = V_110 ;
V_13 -> V_34 ( V_13 ) ;
F_3 ( & V_11 -> V_19 ) ;
F_15 ( & V_11 -> V_20 ) ;
break;
default:
break;
}
F_54 ( V_13 , V_99 ) ;
F_61 ( V_13 ) ;
}
static void F_62 ( struct V_12 * V_13 , struct V_12 * V_98 )
{
if ( V_98 )
V_13 -> V_87 = V_98 -> V_87 ;
}
static struct V_12 * F_63 ( struct V_111 * V_12 , int V_112 , T_3 V_113 )
{
struct V_12 * V_13 ;
struct V_10 * V_11 ;
V_13 = F_64 ( & V_114 , V_115 , V_113 , & V_116 ) ;
if ( ! V_13 )
return NULL ;
V_11 = F_14 ( V_13 ) ;
F_65 ( V_12 , V_13 ) ;
F_66 ( & V_11 -> V_117 ) ;
F_67 ( & V_11 -> V_118 ) ;
F_68 ( & V_11 -> V_19 ) ;
F_66 ( & V_11 -> V_119 . V_4 ) ;
F_67 ( & V_11 -> V_119 . V_18 ) ;
F_68 ( & V_11 -> V_20 ) ;
V_11 -> V_120 = 0 ;
F_69 ( & V_11 -> V_49 , 0 ) ;
V_11 -> V_38 = 0 ;
V_11 -> V_69 = 0 ;
F_69 ( & V_11 -> V_47 , 0 ) ;
F_69 ( & V_11 -> V_71 , 0 ) ;
V_11 -> V_25 = NULL ;
V_11 -> V_121 = V_122 ;
memset ( & V_11 -> V_77 , 0 , 32 ) ;
if ( V_26 )
V_11 -> V_44 = V_45 ;
else
V_11 -> V_44 = V_105 ;
V_13 -> V_123 = F_47 ;
V_13 -> V_124 = V_125 ;
V_13 -> V_126 = V_127 ;
F_70 ( V_13 , V_99 ) ;
V_13 -> V_128 = V_112 ;
V_13 -> V_21 = V_28 ;
F_71 ( & V_17 , V_13 ) ;
return V_13 ;
}
static int F_72 ( struct V_57 * V_57 , struct V_111 * V_12 , int V_90 ,
int V_129 )
{
struct V_12 * V_13 ;
if ( V_90 && V_90 != V_115 )
return - V_130 ;
V_12 -> V_42 = V_131 ;
switch ( V_12 -> type ) {
case V_132 :
V_12 -> V_133 = & V_134 ;
break;
case V_88 :
V_12 -> V_133 = & V_134 ;
break;
default:
return - V_135 ;
}
V_13 = F_63 ( V_12 , V_90 , V_136 ) ;
if ( ! V_13 )
return - V_94 ;
F_62 ( V_13 , NULL ) ;
return 0 ;
}
void F_71 ( struct V_137 * V_138 , struct V_12 * V_13 )
{
F_73 ( & V_138 -> V_18 ) ;
F_74 ( V_13 , & V_138 -> V_62 ) ;
F_75 ( & V_138 -> V_18 ) ;
}
void F_53 ( struct V_137 * V_138 , struct V_12 * V_13 )
{
F_73 ( & V_138 -> V_18 ) ;
F_76 ( V_13 ) ;
F_75 ( & V_138 -> V_18 ) ;
}
void F_77 ( struct V_12 * V_98 , struct V_12 * V_13 )
{
unsigned long V_38 ;
struct V_10 * V_139 = F_14 ( V_98 ) ;
F_78 ( V_13 ) ;
F_79 ( & V_139 -> V_118 , V_38 ) ;
F_80 ( & F_14 ( V_13 ) -> V_117 , & V_139 -> V_117 ) ;
F_81 ( & V_139 -> V_118 , V_38 ) ;
F_14 ( V_13 ) -> V_98 = V_98 ;
F_82 ( V_98 ) ;
}
void F_83 ( struct V_12 * V_13 )
{
unsigned long V_38 ;
struct V_10 * V_139 = F_14 ( F_14 ( V_13 ) -> V_98 ) ;
F_79 ( & V_139 -> V_118 , V_38 ) ;
F_84 ( & F_14 ( V_13 ) -> V_117 ) ;
F_81 ( & V_139 -> V_118 , V_38 ) ;
F_85 ( F_14 ( V_13 ) -> V_98 ) ;
F_14 ( V_13 ) -> V_98 = NULL ;
F_55 ( V_13 ) ;
}
struct V_12 * F_49 ( struct V_12 * V_98 , struct V_111 * V_140 )
{
struct V_10 * V_141 , * V_142 ;
struct V_12 * V_13 ;
F_86 (isk, n, &iucv_sk(parent)->accept_q, accept_q) {
V_13 = (struct V_12 * ) V_141 ;
F_56 ( V_13 ) ;
if ( V_13 -> V_21 == V_31 ) {
F_83 ( V_13 ) ;
F_61 ( V_13 ) ;
continue;
}
if ( V_13 -> V_21 == V_24 ||
V_13 -> V_21 == V_22 ||
! V_140 ) {
F_83 ( V_13 ) ;
if ( V_140 )
F_87 ( V_13 , V_140 ) ;
F_61 ( V_13 ) ;
return V_13 ;
}
F_61 ( V_13 ) ;
}
return NULL ;
}
static int F_88 ( struct V_111 * V_12 , struct V_143 * V_144 ,
int V_145 )
{
struct V_146 * V_147 = (struct V_146 * ) V_144 ;
struct V_12 * V_13 = V_12 -> V_13 ;
struct V_10 * V_11 ;
int V_16 = 0 ;
struct V_148 * V_7 ;
char V_149 [ 9 ] ;
if ( ! V_144 || V_144 -> V_150 != V_151 )
return - V_152 ;
F_56 ( V_13 ) ;
if ( V_13 -> V_21 != V_28 ) {
V_16 = - V_153 ;
goto V_154;
}
F_73 ( & V_17 . V_18 ) ;
V_11 = F_14 ( V_13 ) ;
if ( F_46 ( V_147 -> V_155 ) ) {
V_16 = - V_156 ;
goto V_157;
}
if ( V_11 -> V_25 )
goto V_157;
if ( V_26 )
if ( ! memcmp ( V_147 -> V_158 , V_159 , 8 ) )
goto V_160;
memcpy ( V_149 , V_147 -> V_158 , sizeof( V_149 ) ) ;
F_36 ( V_149 , 8 ) ;
F_25 () ;
F_89 (&init_net, dev) {
if ( ! memcmp ( V_7 -> V_161 , V_149 , 8 ) ) {
memcpy ( V_11 -> V_79 , V_147 -> V_155 , 8 ) ;
memcpy ( V_11 -> V_77 , V_147 -> V_158 , 8 ) ;
V_13 -> V_81 = V_7 -> V_162 ;
V_13 -> V_21 = V_29 ;
V_11 -> V_44 = V_105 ;
if ( ! V_11 -> V_69 )
V_11 -> V_69 = V_163 ;
F_30 () ;
goto V_157;
}
}
F_30 () ;
V_160:
if ( V_26 ) {
memcpy ( V_11 -> V_79 , V_147 -> V_155 , 8 ) ;
memcpy ( V_11 -> V_77 , V_159 , 8 ) ;
V_13 -> V_21 = V_29 ;
V_11 -> V_44 = V_45 ;
if ( ! V_11 -> V_69 )
V_11 -> V_69 = V_164 ;
goto V_157;
}
V_16 = - V_82 ;
V_157:
F_75 ( & V_17 . V_18 ) ;
V_154:
F_61 ( V_13 ) ;
return V_16 ;
}
static int F_90 ( struct V_12 * V_13 )
{
struct V_10 * V_11 = F_14 ( V_13 ) ;
char V_165 [ 12 ] ;
int V_16 = 0 ;
if ( F_91 ( ! V_26 ) )
return - V_166 ;
memcpy ( V_11 -> V_77 , V_159 , 8 ) ;
F_73 ( & V_17 . V_18 ) ;
sprintf ( V_165 , L_5 , F_92 ( & V_17 . V_167 ) ) ;
while ( F_46 ( V_165 ) ) {
sprintf ( V_165 , L_5 ,
F_92 ( & V_17 . V_167 ) ) ;
}
F_75 ( & V_17 . V_18 ) ;
memcpy ( & V_11 -> V_79 , V_165 , 8 ) ;
if ( ! V_11 -> V_69 )
V_11 -> V_69 = V_164 ;
return V_16 ;
}
static int F_93 ( struct V_111 * V_12 )
{
struct V_12 * V_13 = V_12 -> V_13 ;
struct V_5 * V_6 ;
int V_104 = sizeof( struct V_58 ) + V_63 ;
int V_16 = 0 ;
V_6 = F_57 ( V_13 , V_104 , 1 , & V_16 ) ;
if ( ! V_6 ) {
V_16 = - V_94 ;
goto V_154;
}
V_6 -> V_7 = NULL ;
F_58 ( V_6 , V_104 ) ;
V_16 = F_31 ( NULL , V_13 , V_6 , V_67 ) ;
V_154:
return V_16 ;
}
static int F_94 ( struct V_111 * V_12 , struct V_143 * V_144 )
{
struct V_146 * V_147 = (struct V_146 * ) V_144 ;
struct V_12 * V_13 = V_12 -> V_13 ;
struct V_10 * V_11 = F_14 ( V_13 ) ;
unsigned char V_102 [ 16 ] ;
int V_16 ;
F_1 ( V_102 , V_147 -> V_155 ) ;
F_2 ( V_102 , V_11 -> V_79 ) ;
F_36 ( V_102 , sizeof( V_102 ) ) ;
V_11 -> V_25 = F_95 ( V_11 -> V_69 ,
V_39 , V_136 ) ;
if ( ! V_11 -> V_25 ) {
V_16 = - V_94 ;
goto V_154;
}
V_16 = V_26 -> V_168 ( V_11 -> V_25 , & V_169 ,
V_147 -> V_158 , NULL , V_102 ,
V_13 ) ;
if ( V_16 ) {
F_16 ( V_11 -> V_25 ) ;
V_11 -> V_25 = NULL ;
switch ( V_16 ) {
case 0x0b :
V_16 = - V_170 ;
break;
case 0x0d :
case 0x0e :
V_16 = - V_171 ;
break;
case 0x0f :
V_16 = - V_172 ;
break;
default:
V_16 = - V_173 ;
break;
}
}
V_154:
return V_16 ;
}
static int F_96 ( struct V_111 * V_12 , struct V_143 * V_144 ,
int V_174 , int V_38 )
{
struct V_146 * V_147 = (struct V_146 * ) V_144 ;
struct V_12 * V_13 = V_12 -> V_13 ;
struct V_10 * V_11 = F_14 ( V_13 ) ;
int V_16 ;
if ( V_144 -> V_150 != V_151 || V_174 < sizeof( struct V_146 ) )
return - V_152 ;
if ( V_13 -> V_21 != V_28 && V_13 -> V_21 != V_29 )
return - V_153 ;
if ( V_13 -> V_21 == V_28 &&
V_11 -> V_44 == V_105 )
return - V_153 ;
if ( V_13 -> V_87 != V_132 && V_13 -> V_87 != V_88 )
return - V_152 ;
if ( V_13 -> V_21 == V_28 ) {
V_16 = F_90 ( V_13 ) ;
if ( F_91 ( V_16 ) )
return V_16 ;
}
F_56 ( V_13 ) ;
memcpy ( V_11 -> V_73 , V_147 -> V_158 , 8 ) ;
memcpy ( V_11 -> V_75 , V_147 -> V_155 , 8 ) ;
if ( V_11 -> V_44 == V_105 )
V_16 = F_93 ( V_12 ) ;
else
V_16 = F_94 ( V_12 , V_144 ) ;
if ( V_16 )
goto V_154;
if ( V_13 -> V_21 != V_24 )
V_16 = F_60 ( V_13 , F_20 ( V_13 , V_24 ,
V_22 ) ,
F_97 ( V_13 , V_38 & V_175 ) ) ;
if ( V_13 -> V_21 == V_22 || V_13 -> V_21 == V_31 )
V_16 = - V_173 ;
if ( V_16 && V_11 -> V_44 == V_45 ) {
V_26 -> V_27 ( V_11 -> V_25 , NULL ) ;
F_16 ( V_11 -> V_25 ) ;
V_11 -> V_25 = NULL ;
}
V_154:
F_61 ( V_13 ) ;
return V_16 ;
}
static int F_98 ( struct V_111 * V_12 , int V_176 )
{
struct V_12 * V_13 = V_12 -> V_13 ;
int V_16 ;
F_56 ( V_13 ) ;
V_16 = - V_152 ;
if ( V_13 -> V_21 != V_29 )
goto V_154;
if ( V_12 -> type != V_132 && V_12 -> type != V_88 )
goto V_154;
V_13 -> V_177 = V_176 ;
V_13 -> V_178 = 0 ;
V_13 -> V_21 = V_30 ;
V_16 = 0 ;
V_154:
F_61 ( V_13 ) ;
return V_16 ;
}
static int F_99 ( struct V_111 * V_12 , struct V_111 * V_140 ,
int V_38 )
{
F_100 ( V_53 , V_179 ) ;
struct V_12 * V_13 = V_12 -> V_13 , * V_180 ;
long V_103 ;
int V_16 = 0 ;
F_101 ( V_13 , V_181 ) ;
if ( V_13 -> V_21 != V_30 ) {
V_16 = - V_153 ;
goto V_154;
}
V_103 = F_102 ( V_13 , V_38 & V_175 ) ;
F_103 ( F_104 ( V_13 ) , & V_53 ) ;
while ( ! ( V_180 = F_49 ( V_13 , V_140 ) ) ) {
F_105 ( V_182 ) ;
if ( ! V_103 ) {
V_16 = - V_171 ;
break;
}
F_61 ( V_13 ) ;
V_103 = F_106 ( V_103 ) ;
F_101 ( V_13 , V_181 ) ;
if ( V_13 -> V_21 != V_30 ) {
V_16 = - V_153 ;
break;
}
if ( F_107 ( V_179 ) ) {
V_16 = F_108 ( V_103 ) ;
break;
}
}
F_105 ( V_183 ) ;
F_109 ( F_104 ( V_13 ) , & V_53 ) ;
if ( V_16 )
goto V_154;
V_140 -> V_42 = V_184 ;
V_154:
F_61 ( V_13 ) ;
return V_16 ;
}
static int F_110 ( struct V_111 * V_12 , struct V_143 * V_144 ,
int * V_85 , int V_185 )
{
struct V_146 * V_186 = (struct V_146 * ) V_144 ;
struct V_12 * V_13 = V_12 -> V_13 ;
struct V_10 * V_11 = F_14 ( V_13 ) ;
V_144 -> V_150 = V_151 ;
* V_85 = sizeof( struct V_146 ) ;
if ( V_185 ) {
memcpy ( V_186 -> V_158 , V_11 -> V_73 , 8 ) ;
memcpy ( V_186 -> V_155 , V_11 -> V_75 , 8 ) ;
} else {
memcpy ( V_186 -> V_158 , V_11 -> V_77 , 8 ) ;
memcpy ( V_186 -> V_155 , V_11 -> V_79 , 8 ) ;
}
memset ( & V_186 -> V_187 , 0 , sizeof( V_186 -> V_187 ) ) ;
memset ( & V_186 -> V_188 , 0 , sizeof( V_186 -> V_188 ) ) ;
memset ( & V_186 -> V_189 , 0 , sizeof( V_186 -> V_189 ) ) ;
return 0 ;
}
static int F_111 ( struct V_190 * V_25 , struct V_35 * V_36 ,
struct V_5 * V_6 )
{
T_2 V_191 [ 8 ] ;
memcpy ( V_191 , ( void * ) V_6 -> V_192 , V_6 -> V_85 ) ;
V_191 [ 7 ] = 0xff - ( T_2 ) V_6 -> V_85 ;
return V_26 -> V_193 ( V_25 , V_36 , V_39 , 0 ,
( void * ) V_191 , 8 ) ;
}
static int F_112 ( struct V_194 * V_195 , struct V_111 * V_12 ,
struct V_196 * V_36 , T_1 V_85 )
{
struct V_12 * V_13 = V_12 -> V_13 ;
struct V_10 * V_11 = F_14 ( V_13 ) ;
struct V_5 * V_6 ;
struct V_35 V_197 ;
struct V_198 * V_199 ;
int V_200 ;
long V_103 ;
char V_201 [ 9 ] ;
char V_202 [ 9 ] ;
int V_16 ;
int V_203 = V_36 -> V_204 & V_205 ;
V_16 = F_113 ( V_13 ) ;
if ( V_16 )
return V_16 ;
if ( V_36 -> V_204 & V_206 )
return - V_207 ;
if ( V_13 -> V_87 == V_88 && ! ( V_36 -> V_204 & V_208 ) )
return - V_207 ;
F_56 ( V_13 ) ;
if ( V_13 -> V_209 & V_210 ) {
V_16 = - V_33 ;
goto V_211;
}
if ( V_13 -> V_21 != V_24 ) {
V_16 = - V_212 ;
goto V_211;
}
V_200 = 0 ;
V_197 . V_213 = 0 ;
for ( V_199 = F_114 ( V_36 ) ; V_199 ;
V_199 = F_115 ( V_36 , V_199 ) ) {
if ( ! F_116 ( V_36 , V_199 ) ) {
V_16 = - V_152 ;
goto V_211;
}
if ( V_199 -> V_214 != V_215 )
continue;
if ( V_199 -> V_216 & V_200 ) {
V_16 = - V_152 ;
goto V_211;
}
V_200 |= V_199 -> V_216 ;
switch ( V_199 -> V_216 ) {
case V_217 :
if ( V_199 -> V_218 != F_117 ( V_219 ) ) {
V_16 = - V_152 ;
goto V_211;
}
memcpy ( & V_197 . V_213 ,
( void * ) F_118 ( V_199 ) , V_219 ) ;
break;
default:
V_16 = - V_152 ;
goto V_211;
break;
}
}
if ( V_11 -> V_44 == V_105 )
V_6 = F_57 ( V_13 ,
V_85 + sizeof( struct V_58 ) + V_63 ,
V_203 , & V_16 ) ;
else
V_6 = F_57 ( V_13 , V_85 , V_203 , & V_16 ) ;
if ( ! V_6 )
goto V_211;
if ( V_11 -> V_44 == V_105 )
F_58 ( V_6 , sizeof( struct V_58 ) + V_63 ) ;
if ( F_119 ( F_120 ( V_6 , V_85 ) , V_36 -> V_220 , V_85 ) ) {
V_16 = - V_221 ;
goto V_222;
}
V_103 = F_97 ( V_13 , V_203 ) ;
V_16 = F_60 ( V_13 , F_21 ( V_13 ) , V_103 ) ;
if ( V_16 )
goto V_222;
if ( V_13 -> V_21 != V_24 ) {
V_16 = - V_110 ;
goto V_222;
}
V_197 . V_223 = V_11 -> V_120 ++ ;
memcpy ( F_121 ( V_6 ) , & V_197 . V_223 , V_224 ) ;
if ( V_11 -> V_44 == V_105 ) {
F_122 ( & V_11 -> V_47 ) ;
V_16 = F_31 ( & V_197 , V_13 , V_6 , 0 ) ;
if ( V_16 ) {
F_123 ( & V_11 -> V_47 ) ;
goto V_222;
}
goto V_225;
}
F_41 ( & V_11 -> V_19 , V_6 ) ;
if ( ( ( V_11 -> V_25 -> V_38 & V_39 ) & V_11 -> V_38 )
&& V_6 -> V_85 <= 7 ) {
V_16 = F_111 ( V_11 -> V_25 , & V_197 , V_6 ) ;
if ( V_16 == 0 ) {
F_43 ( V_6 , & V_11 -> V_19 ) ;
F_6 ( V_6 ) ;
}
if ( V_16 == 0x15 ) {
V_26 -> V_27 ( V_11 -> V_25 , NULL ) ;
F_43 ( V_6 , & V_11 -> V_19 ) ;
V_16 = - V_33 ;
goto V_222;
}
} else
V_16 = V_26 -> V_193 ( V_11 -> V_25 , & V_197 , 0 , 0 ,
( void * ) V_6 -> V_192 , V_6 -> V_85 ) ;
if ( V_16 ) {
if ( V_16 == 3 ) {
V_201 [ 8 ] = 0 ;
memcpy ( V_201 , V_11 -> V_73 , 8 ) ;
V_202 [ 8 ] = 0 ;
memcpy ( V_202 , V_11 -> V_75 , 8 ) ;
F_124 ( L_6
L_7 ,
V_202 , V_201 ) ;
V_16 = - V_171 ;
} else
V_16 = - V_33 ;
F_43 ( V_6 , & V_11 -> V_19 ) ;
goto V_222;
}
V_225:
F_61 ( V_13 ) ;
return V_85 ;
V_222:
if ( V_6 -> V_7 )
F_5 ( V_6 -> V_7 ) ;
F_6 ( V_6 ) ;
V_211:
F_61 ( V_13 ) ;
return V_16 ;
}
static int F_125 ( struct V_12 * V_13 , struct V_5 * V_6 , int V_85 )
{
int V_226 , V_227 , V_228 = 0 ;
struct V_5 * V_60 ;
V_226 = V_85 ;
while ( V_226 ) {
if ( V_226 >= V_13 -> V_229 / 4 )
V_227 = V_13 -> V_229 / 4 ;
else
V_227 = V_226 ;
V_60 = F_126 ( V_227 , V_93 | V_127 ) ;
if ( ! V_60 )
return - V_94 ;
memcpy ( F_127 ( V_60 ) , F_127 ( V_6 ) , V_230 ) ;
memcpy ( V_60 -> V_192 , V_6 -> V_192 + V_228 , V_227 ) ;
V_228 += V_227 ;
V_226 -= V_227 ;
F_128 ( V_60 ) ;
F_35 ( V_60 ) ;
V_60 -> V_85 = V_227 ;
F_41 ( & F_14 ( V_13 ) -> V_20 , V_60 ) ;
}
return 0 ;
}
static void F_129 ( struct V_12 * V_13 , struct V_5 * V_6 ,
struct V_190 * V_25 ,
struct V_35 * V_36 )
{
int V_231 ;
unsigned int V_85 ;
V_85 = F_19 ( V_36 ) ;
memcpy ( F_127 ( V_6 ) , & V_36 -> V_213 , V_230 ) ;
if ( ( V_36 -> V_38 & V_39 ) && V_85 > 7 ) {
if ( memcmp ( V_36 -> V_40 , V_232 , 8 ) == 0 ) {
V_6 -> V_192 = NULL ;
V_6 -> V_85 = 0 ;
}
} else {
V_231 = V_26 -> V_233 ( V_25 , V_36 ,
V_36 -> V_38 & V_39 ,
V_6 -> V_192 , V_85 , NULL ) ;
if ( V_231 ) {
F_6 ( V_6 ) ;
return;
}
if ( V_13 -> V_87 == V_132 &&
V_6 -> V_234 >= V_13 -> V_229 / 4 ) {
V_231 = F_125 ( V_13 , V_6 , V_85 ) ;
F_6 ( V_6 ) ;
V_6 = NULL ;
if ( V_231 ) {
V_26 -> V_27 ( V_25 , NULL ) ;
return;
}
V_6 = F_4 ( & F_14 ( V_13 ) -> V_20 ) ;
} else {
F_128 ( V_6 ) ;
F_35 ( V_6 ) ;
V_6 -> V_85 = V_85 ;
}
}
if ( F_130 ( V_13 , V_6 ) )
F_131 ( & F_14 ( V_13 ) -> V_20 , V_6 ) ;
}
static void F_132 ( struct V_12 * V_13 )
{
struct V_10 * V_11 = F_14 ( V_13 ) ;
struct V_5 * V_6 ;
struct V_235 * V_236 , * V_142 ;
F_86 (p, n, &iucv->message_q.list, list) {
V_6 = F_126 ( F_19 ( & V_236 -> V_36 ) , V_93 | V_127 ) ;
if ( ! V_6 )
break;
F_129 ( V_13 , V_6 , V_236 -> V_25 , & V_236 -> V_36 ) ;
F_133 ( & V_236 -> V_4 ) ;
F_134 ( V_236 ) ;
if ( ! F_59 ( & V_11 -> V_20 ) )
break;
}
}
static int F_135 ( struct V_194 * V_195 , struct V_111 * V_12 ,
struct V_196 * V_36 , T_1 V_85 , int V_38 )
{
int V_203 = V_38 & V_205 ;
struct V_12 * V_13 = V_12 -> V_13 ;
struct V_10 * V_11 = F_14 ( V_13 ) ;
unsigned int V_228 , V_237 ;
struct V_5 * V_6 , * V_238 , * V_239 , * V_240 ;
int V_104 ;
int V_16 = 0 ;
if ( ( V_13 -> V_21 == V_22 ) &&
F_59 ( & V_11 -> V_20 ) &&
F_59 ( & V_13 -> V_96 ) &&
F_136 ( & V_11 -> V_119 . V_4 ) )
return 0 ;
if ( V_38 & ( V_206 ) )
return - V_207 ;
V_6 = F_137 ( V_13 , V_38 , V_203 , & V_16 ) ;
if ( ! V_6 ) {
if ( V_13 -> V_209 & V_241 )
return 0 ;
return V_16 ;
}
V_237 = V_6 -> V_85 ;
V_228 = F_138 (unsigned int, rlen, len) ;
V_239 = V_6 ;
if ( F_139 ( V_239 , 0 , V_36 -> V_220 , V_228 ) ) {
if ( ! ( V_38 & V_242 ) )
F_131 ( & V_13 -> V_96 , V_6 ) ;
return - V_221 ;
}
if ( V_13 -> V_87 == V_88 ) {
if ( V_228 < V_237 )
V_36 -> V_204 |= V_243 ;
V_36 -> V_204 |= V_208 ;
}
V_16 = F_140 ( V_36 , V_215 , V_217 ,
V_230 , F_127 ( V_6 ) ) ;
if ( V_16 ) {
if ( ! ( V_38 & V_242 ) )
F_131 ( & V_13 -> V_96 , V_6 ) ;
return V_16 ;
}
if ( ! ( V_38 & V_242 ) ) {
if ( V_13 -> V_87 == V_132 ) {
F_141 ( V_6 , V_228 ) ;
if ( V_6 -> V_85 ) {
F_131 ( & V_13 -> V_96 , V_6 ) ;
goto V_154;
}
}
F_6 ( V_6 ) ;
F_122 ( & V_11 -> V_71 ) ;
F_142 ( & V_11 -> V_119 . V_18 ) ;
V_238 = F_4 ( & V_11 -> V_20 ) ;
while ( V_238 ) {
if ( F_130 ( V_13 , V_238 ) ) {
F_131 ( & V_11 -> V_20 ,
V_238 ) ;
break;
} else {
V_238 = F_4 ( & V_11 -> V_20 ) ;
}
}
if ( F_59 ( & V_11 -> V_20 ) ) {
if ( ! F_136 ( & V_11 -> V_119 . V_4 ) )
F_132 ( V_13 ) ;
if ( F_23 ( & V_11 -> V_71 ) >=
V_11 -> V_69 / 2 ) {
V_104 = sizeof( struct V_58 ) +
V_63 ;
V_240 = F_57 ( V_13 , V_104 , 1 , & V_16 ) ;
if ( V_240 ) {
F_58 ( V_240 , V_104 ) ;
V_16 = F_31 ( NULL , V_13 , V_240 ,
V_70 ) ;
}
if ( V_16 ) {
V_13 -> V_21 = V_22 ;
V_13 -> V_34 ( V_13 ) ;
}
}
}
F_143 ( & V_11 -> V_119 . V_18 ) ;
}
V_154:
if ( V_13 -> V_87 == V_88 && ( V_38 & V_243 ) )
V_228 = V_237 ;
return V_228 ;
}
static inline unsigned int F_144 ( struct V_12 * V_98 )
{
struct V_10 * V_141 , * V_142 ;
struct V_12 * V_13 ;
F_86 (isk, n, &iucv_sk(parent)->accept_q, accept_q) {
V_13 = (struct V_12 * ) V_141 ;
if ( V_13 -> V_21 == V_24 )
return V_244 | V_245 ;
}
return 0 ;
}
unsigned int F_145 ( struct V_246 * V_246 , struct V_111 * V_12 ,
T_4 * V_53 )
{
struct V_12 * V_13 = V_12 -> V_13 ;
unsigned int V_247 = 0 ;
F_146 ( V_246 , F_104 ( V_13 ) , V_53 ) ;
if ( V_13 -> V_21 == V_30 )
return F_144 ( V_13 ) ;
if ( V_13 -> V_32 || ! F_59 ( & V_13 -> V_248 ) )
V_247 |= V_249 ;
if ( V_13 -> V_209 & V_241 )
V_247 |= V_250 ;
if ( V_13 -> V_209 == V_251 )
V_247 |= V_252 ;
if ( ! F_59 ( & V_13 -> V_96 ) ||
( V_13 -> V_209 & V_241 ) )
V_247 |= V_244 | V_245 ;
if ( V_13 -> V_21 == V_31 )
V_247 |= V_252 ;
if ( V_13 -> V_21 == V_22 )
V_247 |= V_244 ;
if ( F_147 ( V_13 ) )
V_247 |= V_253 | V_254 | V_255 ;
else
F_148 ( V_256 , & V_13 -> V_100 -> V_38 ) ;
return V_247 ;
}
static int F_149 ( struct V_111 * V_12 , int V_257 )
{
struct V_12 * V_13 = V_12 -> V_13 ;
struct V_10 * V_11 = F_14 ( V_13 ) ;
struct V_35 V_197 ;
int V_16 = 0 ;
V_257 ++ ;
if ( ( V_257 & ~ V_251 ) || ! V_257 )
return - V_152 ;
F_56 ( V_13 ) ;
switch ( V_13 -> V_21 ) {
case V_22 :
case V_23 :
case V_31 :
V_16 = - V_212 ;
goto V_222;
default:
V_13 -> V_209 |= V_257 ;
break;
}
if ( V_257 == V_210 || V_257 == V_251 ) {
V_197 . V_213 = 0 ;
V_197 . V_223 = 0 ;
V_16 = V_26 -> V_193 ( V_11 -> V_25 , & V_197 , V_39 ,
0 , ( void * ) V_232 , 8 ) ;
if ( V_16 ) {
switch ( V_16 ) {
case 1 :
V_16 = - V_212 ;
break;
case 2 :
V_16 = - V_110 ;
break;
default:
V_16 = - V_212 ;
break;
}
}
}
if ( V_257 == V_241 || V_257 == V_251 ) {
V_16 = V_26 -> V_258 ( V_11 -> V_25 , NULL ) ;
if ( V_16 )
V_16 = - V_212 ;
F_15 ( & V_13 -> V_96 ) ;
}
V_13 -> V_34 ( V_13 ) ;
V_222:
F_61 ( V_13 ) ;
return V_16 ;
}
static int F_150 ( struct V_111 * V_12 )
{
struct V_12 * V_13 = V_12 -> V_13 ;
int V_16 = 0 ;
if ( ! V_13 )
return 0 ;
F_50 ( V_13 ) ;
if ( F_14 ( V_13 ) -> V_25 ) {
V_26 -> V_27 ( F_14 ( V_13 ) -> V_25 , NULL ) ;
F_16 ( F_14 ( V_13 ) -> V_25 ) ;
F_14 ( V_13 ) -> V_25 = NULL ;
}
F_151 ( V_13 ) ;
F_51 ( V_13 ) ;
return V_16 ;
}
static int F_152 ( struct V_111 * V_12 , int V_259 , int V_260 ,
char T_5 * V_261 , unsigned int V_262 )
{
struct V_12 * V_13 = V_12 -> V_13 ;
struct V_10 * V_11 = F_14 ( V_13 ) ;
int V_263 ;
int V_231 ;
if ( V_259 != V_215 )
return - V_264 ;
if ( V_262 < sizeof( int ) )
return - V_152 ;
if ( F_153 ( V_263 , ( int T_5 * ) V_261 ) )
return - V_221 ;
V_231 = 0 ;
F_56 ( V_13 ) ;
switch ( V_260 ) {
case V_265 :
if ( V_263 )
V_11 -> V_38 |= V_39 ;
else
V_11 -> V_38 &= ~ V_39 ;
break;
case V_266 :
switch ( V_13 -> V_21 ) {
case V_28 :
case V_29 :
if ( V_263 < 1 || V_263 > ( V_267 ) ( ~ 0 ) )
V_231 = - V_152 ;
else
V_11 -> V_69 = V_263 ;
break;
default:
V_231 = - V_152 ;
break;
}
break;
default:
V_231 = - V_264 ;
break;
}
F_61 ( V_13 ) ;
return V_231 ;
}
static int F_154 ( struct V_111 * V_12 , int V_259 , int V_260 ,
char T_5 * V_261 , int T_5 * V_262 )
{
struct V_12 * V_13 = V_12 -> V_13 ;
struct V_10 * V_11 = F_14 ( V_13 ) ;
int V_263 , V_85 ;
if ( V_259 != V_215 )
return - V_264 ;
if ( F_153 ( V_85 , V_262 ) )
return - V_221 ;
if ( V_85 < 0 )
return - V_152 ;
V_85 = F_138 (unsigned int, len, sizeof(int)) ;
switch ( V_260 ) {
case V_265 :
V_263 = ( V_11 -> V_38 & V_39 ) ? 1 : 0 ;
break;
case V_266 :
F_56 ( V_13 ) ;
V_263 = ( V_11 -> V_25 != NULL ) ? V_11 -> V_25 -> V_46
: V_11 -> V_69 ;
F_61 ( V_13 ) ;
break;
default:
return - V_264 ;
}
if ( F_155 ( V_85 , V_262 ) )
return - V_221 ;
if ( F_156 ( V_261 , & V_263 , V_85 ) )
return - V_221 ;
return 0 ;
}
static int F_157 ( struct V_190 * V_25 ,
T_2 V_268 [ 8 ] , T_2 V_269 [ 16 ] )
{
unsigned char V_102 [ 16 ] ;
unsigned char V_270 [ 16 ] ;
unsigned char V_79 [ 8 ] ;
struct V_14 * V_15 ;
struct V_12 * V_13 , * V_180 ;
struct V_10 * V_11 , * V_271 ;
int V_16 ;
memcpy ( V_79 , V_269 , 8 ) ;
F_158 ( V_79 , 8 ) ;
F_12 ( & V_17 . V_18 ) ;
V_11 = NULL ;
V_13 = NULL ;
F_13 (sk, node, &iucv_sk_list.head)
if ( V_13 -> V_21 == V_30 &&
! memcmp ( & F_14 ( V_13 ) -> V_79 , V_79 , 8 ) ) {
V_11 = F_14 ( V_13 ) ;
break;
}
F_17 ( & V_17 . V_18 ) ;
if ( ! V_11 )
return - V_152 ;
F_159 ( V_13 ) ;
F_2 ( V_102 , V_11 -> V_79 ) ;
F_1 ( V_102 , V_11 -> V_75 ) ;
F_36 ( V_102 , sizeof( V_102 ) ) ;
if ( V_13 -> V_21 != V_30 ) {
V_16 = V_26 -> V_27 ( V_25 , V_102 ) ;
F_16 ( V_25 ) ;
goto V_222;
}
if ( F_160 ( V_13 ) ) {
V_16 = V_26 -> V_27 ( V_25 , V_102 ) ;
F_16 ( V_25 ) ;
goto V_222;
}
V_180 = F_63 ( NULL , V_13 -> V_87 , V_93 ) ;
if ( ! V_180 ) {
V_16 = V_26 -> V_27 ( V_25 , V_102 ) ;
F_16 ( V_25 ) ;
goto V_222;
}
V_271 = F_14 ( V_180 ) ;
F_62 ( V_180 , V_13 ) ;
memcpy ( V_271 -> V_75 , V_269 + 8 , 8 ) ;
F_158 ( V_271 -> V_75 , 8 ) ;
memcpy ( V_271 -> V_73 , V_268 , 8 ) ;
memcpy ( V_271 -> V_79 , V_11 -> V_79 , 8 ) ;
memcpy ( V_271 -> V_77 , V_11 -> V_77 , 8 ) ;
V_271 -> V_25 = V_25 ;
F_1 ( V_270 , V_269 + 8 ) ;
memcpy ( V_270 + 8 , V_271 -> V_79 , 8 ) ;
F_36 ( V_270 + 8 , 8 ) ;
V_271 -> V_69 = V_11 -> V_69 ;
V_25 -> V_46 = V_11 -> V_69 ;
V_16 = V_26 -> V_272 ( V_25 , & V_169 , V_270 , V_180 ) ;
if ( V_16 ) {
V_16 = V_26 -> V_27 ( V_25 , V_102 ) ;
F_16 ( V_25 ) ;
F_51 ( V_180 ) ;
goto V_222;
}
F_77 ( V_13 , V_180 ) ;
V_180 -> V_21 = V_24 ;
V_13 -> V_273 ( V_13 , 1 ) ;
V_16 = 0 ;
V_222:
F_161 ( V_13 ) ;
return 0 ;
}
static void F_162 ( struct V_190 * V_25 , T_2 V_269 [ 16 ] )
{
struct V_12 * V_13 = V_25 -> V_274 ;
V_13 -> V_21 = V_24 ;
V_13 -> V_34 ( V_13 ) ;
}
static void F_163 ( struct V_190 * V_25 , struct V_35 * V_36 )
{
struct V_12 * V_13 = V_25 -> V_274 ;
struct V_10 * V_11 = F_14 ( V_13 ) ;
struct V_5 * V_6 ;
struct V_235 * V_275 ;
int V_85 ;
if ( V_13 -> V_209 & V_241 ) {
V_26 -> V_276 ( V_25 , V_36 ) ;
return;
}
F_164 ( & V_11 -> V_119 . V_18 ) ;
if ( ! F_136 ( & V_11 -> V_119 . V_4 ) ||
! F_59 ( & V_11 -> V_20 ) )
goto V_277;
V_85 = F_23 ( & V_13 -> V_278 ) ;
V_85 += F_165 ( F_19 ( V_36 ) ) ;
if ( V_85 > V_13 -> V_229 )
goto V_277;
V_6 = F_126 ( F_19 ( V_36 ) , V_93 | V_127 ) ;
if ( ! V_6 )
goto V_277;
F_129 ( V_13 , V_6 , V_25 , V_36 ) ;
goto V_279;
V_277:
V_275 = F_166 ( sizeof( struct V_235 ) , V_93 | V_127 ) ;
if ( ! V_275 )
goto V_279;
V_275 -> V_25 = V_25 ;
V_275 -> V_36 = * V_36 ;
F_80 ( & V_275 -> V_4 , & V_11 -> V_119 . V_4 ) ;
V_279:
F_167 ( & V_11 -> V_119 . V_18 ) ;
}
static void F_168 ( struct V_190 * V_25 ,
struct V_35 * V_36 )
{
struct V_12 * V_13 = V_25 -> V_274 ;
struct V_5 * V_280 = NULL ;
struct V_3 * V_4 = & F_14 ( V_13 ) -> V_19 ;
struct V_5 * V_281 = V_4 -> V_282 ;
unsigned long V_38 ;
if ( ! F_59 ( V_4 ) ) {
F_79 ( & V_4 -> V_18 , V_38 ) ;
while ( V_281 != (struct V_5 * ) V_4 ) {
if ( ! memcmp ( & V_36 -> V_223 , F_121 ( V_281 ) , V_224 ) ) {
V_280 = V_281 ;
break;
}
V_281 = V_281 -> V_282 ;
}
if ( V_280 )
F_169 ( V_280 , V_4 ) ;
F_81 ( & V_4 -> V_18 , V_38 ) ;
if ( V_280 ) {
F_6 ( V_280 ) ;
F_24 ( V_13 ) ;
}
}
F_170 ( ! V_280 ) ;
if ( V_13 -> V_21 == V_23 ) {
if ( F_59 ( & F_14 ( V_13 ) -> V_19 ) ) {
V_13 -> V_21 = V_31 ;
V_13 -> V_34 ( V_13 ) ;
}
}
}
static void F_171 ( struct V_190 * V_25 , T_2 V_269 [ 16 ] )
{
struct V_12 * V_13 = V_25 -> V_274 ;
V_13 -> V_21 = V_22 ;
V_13 -> V_34 ( V_13 ) ;
}
static void F_172 ( struct V_190 * V_25 , T_2 V_269 [ 16 ] )
{
struct V_12 * V_13 = V_25 -> V_274 ;
F_159 ( V_13 ) ;
if ( V_13 -> V_21 != V_31 ) {
V_13 -> V_209 |= V_210 ;
V_13 -> V_34 ( V_13 ) ;
}
F_161 ( V_13 ) ;
}
static void F_173 ( struct V_5 * V_6 )
{
struct V_58 * V_283 =
(struct V_58 * ) V_6 -> V_192 ;
char V_284 [ 8 ] ;
char V_285 [ 8 ] ;
F_36 ( V_283 -> V_72 , sizeof( V_283 -> V_72 ) ) ;
F_36 ( V_283 -> V_74 , sizeof( V_283 -> V_74 ) ) ;
F_36 ( V_283 -> V_76 , sizeof( V_283 -> V_76 ) ) ;
F_36 ( V_283 -> V_78 , sizeof( V_283 -> V_78 ) ) ;
memcpy ( V_284 , V_283 -> V_76 , 8 ) ;
memcpy ( V_285 , V_283 -> V_78 , 8 ) ;
memcpy ( V_283 -> V_76 , V_283 -> V_72 , 8 ) ;
memcpy ( V_283 -> V_78 , V_283 -> V_74 , 8 ) ;
memcpy ( V_283 -> V_72 , V_284 , 8 ) ;
memcpy ( V_283 -> V_74 , V_285 , 8 ) ;
F_33 ( V_6 , V_63 ) ;
memset ( V_6 -> V_192 , 0 , V_63 ) ;
}
static int F_174 ( struct V_12 * V_13 , struct V_5 * V_6 )
{
struct V_12 * V_180 ;
struct V_10 * V_11 , * V_271 ;
struct V_58 * V_283 ;
int V_16 ;
V_11 = F_14 ( V_13 ) ;
V_283 = (struct V_58 * ) V_6 -> V_192 ;
if ( ! V_11 ) {
F_173 ( V_6 ) ;
V_283 -> V_38 = V_67 | V_106 ;
V_16 = F_42 ( V_6 ) ;
goto V_211;
}
V_180 = F_63 ( NULL , V_13 -> V_87 , V_93 ) ;
F_159 ( V_13 ) ;
if ( ( V_13 -> V_21 != V_30 ) ||
F_160 ( V_13 ) ||
! V_180 ) {
if ( V_180 )
F_175 ( V_180 ) ;
F_173 ( V_6 ) ;
V_283 -> V_38 = V_67 | V_106 ;
V_16 = F_42 ( V_6 ) ;
F_161 ( V_13 ) ;
goto V_211;
}
V_271 = F_14 ( V_180 ) ;
F_62 ( V_180 , V_13 ) ;
V_271 -> V_44 = V_105 ;
V_271 -> V_69 = V_11 -> V_69 ;
if ( ! V_283 -> V_68 )
V_271 -> V_48 = V_163 ;
else
V_271 -> V_48 = V_283 -> V_68 ;
memcpy ( V_271 -> V_75 , V_283 -> V_78 , 8 ) ;
memcpy ( V_271 -> V_73 , V_283 -> V_76 , 8 ) ;
memcpy ( V_271 -> V_79 , V_11 -> V_79 , 8 ) ;
memcpy ( V_271 -> V_77 , V_11 -> V_77 , 8 ) ;
V_180 -> V_81 = V_13 -> V_81 ;
F_173 ( V_6 ) ;
V_283 -> V_38 = V_67 | V_286 ;
V_283 -> V_68 = V_271 -> V_69 ;
V_16 = F_42 ( V_6 ) ;
if ( ! V_16 ) {
F_77 ( V_13 , V_180 ) ;
V_180 -> V_21 = V_24 ;
V_13 -> V_273 ( V_13 , 1 ) ;
} else
F_51 ( V_180 ) ;
F_161 ( V_13 ) ;
V_211:
return V_287 ;
}
static int F_176 ( struct V_12 * V_13 , struct V_5 * V_6 )
{
struct V_10 * V_11 = F_14 ( V_13 ) ;
struct V_58 * V_283 =
(struct V_58 * ) V_6 -> V_192 ;
if ( ! V_11 )
goto V_211;
if ( V_13 -> V_21 != V_29 )
goto V_211;
F_159 ( V_13 ) ;
V_11 -> V_48 = V_283 -> V_68 ;
V_13 -> V_21 = V_24 ;
V_13 -> V_34 ( V_13 ) ;
F_161 ( V_13 ) ;
V_211:
F_6 ( V_6 ) ;
return V_287 ;
}
static int F_177 ( struct V_12 * V_13 , struct V_5 * V_6 )
{
struct V_10 * V_11 = F_14 ( V_13 ) ;
if ( ! V_11 )
goto V_211;
if ( V_13 -> V_21 != V_29 )
goto V_211;
F_159 ( V_13 ) ;
V_13 -> V_21 = V_22 ;
V_13 -> V_34 ( V_13 ) ;
F_161 ( V_13 ) ;
V_211:
F_6 ( V_6 ) ;
return V_287 ;
}
static int F_178 ( struct V_12 * V_13 , struct V_5 * V_6 )
{
struct V_10 * V_11 = F_14 ( V_13 ) ;
if ( V_11 ) {
F_159 ( V_13 ) ;
V_13 -> V_21 = V_22 ;
V_13 -> V_34 ( V_13 ) ;
F_161 ( V_13 ) ;
}
F_6 ( V_6 ) ;
return V_287 ;
}
static int F_179 ( struct V_12 * V_13 , struct V_5 * V_6 )
{
struct V_10 * V_11 = F_14 ( V_13 ) ;
struct V_58 * V_283 =
(struct V_58 * ) V_6 -> V_192 ;
if ( ! V_11 )
return V_287 ;
if ( V_13 -> V_21 != V_24 )
return V_287 ;
F_44 ( V_283 -> V_68 , & V_11 -> V_47 ) ;
F_24 ( V_13 ) ;
return V_287 ;
}
static int F_180 ( struct V_12 * V_13 , struct V_5 * V_6 )
{
struct V_10 * V_11 = F_14 ( V_13 ) ;
if ( ! V_11 ) {
F_6 ( V_6 ) ;
return V_287 ;
}
if ( V_13 -> V_21 != V_24 ) {
F_6 ( V_6 ) ;
return V_287 ;
}
if ( V_6 -> V_85 <= sizeof( struct V_58 ) ) {
F_6 ( V_6 ) ;
return V_287 ;
}
F_141 ( V_6 , sizeof( struct V_58 ) ) ;
F_128 ( V_6 ) ;
F_35 ( V_6 ) ;
F_164 ( & V_11 -> V_119 . V_18 ) ;
if ( F_59 ( & V_11 -> V_20 ) ) {
if ( F_130 ( V_13 , V_6 ) ) {
F_41 ( & V_11 -> V_20 , V_6 ) ;
}
} else
F_41 ( & F_14 ( V_13 ) -> V_20 , V_6 ) ;
F_167 ( & V_11 -> V_119 . V_18 ) ;
return V_287 ;
}
static int F_181 ( struct V_5 * V_6 , struct V_148 * V_7 ,
struct V_288 * V_289 , struct V_148 * V_290 )
{
struct V_14 * V_15 ;
struct V_12 * V_13 ;
struct V_10 * V_11 ;
struct V_58 * V_283 ;
char V_291 [ 8 ] ;
int V_16 = 0 ;
F_141 ( V_6 , V_63 ) ;
V_283 = (struct V_58 * ) V_6 -> V_192 ;
F_158 ( V_283 -> V_74 , sizeof( V_283 -> V_74 ) ) ;
F_158 ( V_283 -> V_72 , sizeof( V_283 -> V_72 ) ) ;
F_158 ( V_283 -> V_78 , sizeof( V_283 -> V_78 ) ) ;
F_158 ( V_283 -> V_76 , sizeof( V_283 -> V_76 ) ) ;
memset ( V_291 , 0 , sizeof( V_291 ) ) ;
V_11 = NULL ;
V_13 = NULL ;
F_12 ( & V_17 . V_18 ) ;
F_13 (sk, node, &iucv_sk_list.head) {
if ( V_283 -> V_38 == V_67 ) {
if ( ( ! memcmp ( & F_14 ( V_13 ) -> V_79 ,
V_283 -> V_74 , 8 ) ) &&
( ! memcmp ( & F_14 ( V_13 ) -> V_77 ,
V_283 -> V_72 , 8 ) ) &&
( ! memcmp ( & F_14 ( V_13 ) -> V_75 , V_291 , 8 ) ) &&
( ! memcmp ( & F_14 ( V_13 ) -> V_73 ,
V_291 , 8 ) ) ) {
V_11 = F_14 ( V_13 ) ;
break;
}
} else {
if ( ( ! memcmp ( & F_14 ( V_13 ) -> V_79 ,
V_283 -> V_74 , 8 ) ) &&
( ! memcmp ( & F_14 ( V_13 ) -> V_77 ,
V_283 -> V_72 , 8 ) ) &&
( ! memcmp ( & F_14 ( V_13 ) -> V_75 ,
V_283 -> V_78 , 8 ) ) &&
( ! memcmp ( & F_14 ( V_13 ) -> V_73 ,
V_283 -> V_76 , 8 ) ) ) {
V_11 = F_14 ( V_13 ) ;
break;
}
}
}
F_17 ( & V_17 . V_18 ) ;
if ( ! V_11 )
V_13 = NULL ;
switch ( V_283 -> V_38 ) {
case V_67 :
V_16 = F_174 ( V_13 , V_6 ) ;
break;
case ( V_67 | V_286 ) :
V_16 = F_176 ( V_13 , V_6 ) ;
break;
case ( V_67 | V_106 ) :
V_16 = F_177 ( V_13 , V_6 ) ;
break;
case ( V_106 ) :
V_16 = F_178 ( V_13 , V_6 ) ;
break;
case ( V_70 ) :
V_16 = F_179 ( V_13 , V_6 ) ;
if ( V_6 -> V_85 > sizeof( struct V_58 ) )
V_16 = F_180 ( V_13 , V_6 ) ;
else
F_134 ( V_6 ) ;
break;
case 0 :
memcpy ( F_127 ( V_6 ) , & V_283 -> V_80 . V_213 ,
V_230 ) ;
V_16 = F_180 ( V_13 , V_6 ) ;
break;
default:
;
}
return V_16 ;
}
static void V_122 ( struct V_5 * V_6 ,
enum V_292 V_142 )
{
struct V_12 * V_141 = V_6 -> V_13 ;
struct V_12 * V_13 = NULL ;
struct V_10 * V_11 = NULL ;
struct V_3 * V_4 ;
struct V_5 * V_281 ;
struct V_5 * V_280 = NULL ;
unsigned long V_38 ;
struct V_14 * V_15 ;
F_12 ( & V_17 . V_18 ) ;
F_13 (sk, node, &iucv_sk_list.head)
if ( V_13 == V_141 ) {
V_11 = F_14 ( V_13 ) ;
break;
}
F_17 ( & V_17 . V_18 ) ;
if ( ! V_11 )
return;
F_159 ( V_13 ) ;
V_4 = & V_11 -> V_19 ;
V_281 = V_4 -> V_282 ;
if ( F_59 ( V_4 ) )
goto V_279;
F_79 ( & V_4 -> V_18 , V_38 ) ;
while ( V_281 != (struct V_5 * ) V_4 ) {
if ( F_39 ( V_281 ) == F_39 ( V_6 ) ) {
V_280 = V_281 ;
switch ( V_142 ) {
case V_293 :
F_169 ( V_280 , V_4 ) ;
F_24 ( V_13 ) ;
F_5 ( V_280 -> V_7 ) ;
F_6 ( V_280 ) ;
break;
case V_294 :
F_122 ( & V_11 -> V_49 ) ;
break;
case V_295 :
F_169 ( V_280 , V_4 ) ;
F_123 ( & V_11 -> V_49 ) ;
if ( F_23 ( & V_11 -> V_49 ) <= 0 )
F_24 ( V_13 ) ;
F_5 ( V_280 -> V_7 ) ;
F_6 ( V_280 ) ;
break;
case V_296 :
case V_297 :
case V_298 :
case V_299 :
case V_300 :
F_169 ( V_280 , V_4 ) ;
F_5 ( V_280 -> V_7 ) ;
F_6 ( V_280 ) ;
V_13 -> V_21 = V_22 ;
V_13 -> V_34 ( V_13 ) ;
break;
}
break;
}
V_281 = V_281 -> V_282 ;
}
F_81 ( & V_4 -> V_18 , V_38 ) ;
if ( V_13 -> V_21 == V_23 ) {
if ( F_59 ( & F_14 ( V_13 ) -> V_19 ) ) {
V_13 -> V_21 = V_31 ;
V_13 -> V_34 ( V_13 ) ;
}
}
V_279:
F_161 ( V_13 ) ;
}
static int F_182 ( void )
{
int V_16 ;
V_16 = V_26 -> V_301 ( & V_169 , 0 ) ;
if ( V_16 )
goto V_211;
V_302 . V_303 = V_26 -> V_303 ;
V_16 = F_183 ( & V_302 ) ;
if ( V_16 )
goto V_304;
V_305 = F_166 ( sizeof( struct V_8 ) , V_136 ) ;
if ( ! V_305 ) {
V_16 = - V_94 ;
goto V_306;
}
F_184 ( V_305 , L_8 ) ;
V_305 -> V_303 = V_26 -> V_303 ;
V_305 -> V_98 = V_26 -> V_307 ;
V_305 -> V_225 = ( void ( * ) ( struct V_8 * ) ) F_134 ;
V_305 -> V_308 = & V_302 ;
V_16 = F_185 ( V_305 ) ;
if ( V_16 )
goto V_306;
return 0 ;
V_306:
F_186 ( & V_302 ) ;
V_304:
V_26 -> V_309 ( & V_169 , 0 ) ;
V_211:
return V_16 ;
}
static int T_6 F_187 ( void )
{
int V_16 ;
if ( V_310 ) {
F_188 ( L_9 , V_159 , sizeof( V_159 ) , & V_16 ) ;
if ( F_91 ( V_16 ) ) {
F_45 ( V_16 ) ;
V_16 = - V_130 ;
goto V_211;
}
V_26 = F_189 ( F_190 ( V_311 ) , L_10 ) ;
if ( ! V_26 ) {
F_9 ( V_9 L_11 ) ;
memset ( & V_159 , 0 , sizeof( V_159 ) ) ;
}
} else {
memset ( & V_159 , 0 , sizeof( V_159 ) ) ;
V_26 = NULL ;
}
V_16 = F_191 ( & V_116 , 0 ) ;
if ( V_16 )
goto V_211;
V_16 = F_192 ( & V_312 ) ;
if ( V_16 )
goto V_313;
if ( V_26 ) {
V_16 = F_182 () ;
if ( V_16 )
goto V_314;
}
F_193 ( & V_315 ) ;
return 0 ;
V_314:
F_194 ( V_115 ) ;
V_313:
F_195 ( & V_116 ) ;
V_211:
if ( V_26 )
F_196 ( V_311 ) ;
return V_16 ;
}
static void T_7 F_197 ( void )
{
if ( V_26 ) {
F_198 ( V_305 ) ;
F_186 ( & V_302 ) ;
V_26 -> V_309 ( & V_169 , 0 ) ;
F_196 ( V_311 ) ;
}
F_199 ( & V_315 ) ;
F_194 ( V_115 ) ;
F_195 ( & V_116 ) ;
}
