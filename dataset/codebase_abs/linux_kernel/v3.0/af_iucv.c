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
V_12 = F_12 ( V_7 -> V_22 , NULL ) ;
F_13 ( V_7 -> V_22 ) ;
V_7 -> V_22 = NULL ;
}
break;
case V_23 :
case V_24 :
case V_25 :
case V_26 :
default:
break;
}
}
F_14 ( & V_13 . V_14 ) ;
return V_12 ;
}
static int F_15 ( struct V_3 * V_4 )
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
V_9 -> V_27 = V_28 ;
V_9 -> V_17 = V_19 ;
V_9 -> V_29 ( V_9 ) ;
break;
case V_19 :
case V_18 :
case V_20 :
case V_25 :
case V_24 :
case V_23 :
default:
break;
}
}
F_14 ( & V_13 . V_14 ) ;
return 0 ;
}
static inline T_1 F_16 ( struct V_30 * V_31 )
{
T_1 V_32 ;
if ( V_31 -> V_33 & V_34 ) {
V_32 = 0xff - V_31 -> V_35 [ 7 ] ;
return ( V_32 < 8 ) ? V_32 : 8 ;
}
return V_31 -> V_36 ;
}
static int F_17 ( struct V_8 * V_9 , int V_37 , int V_38 )
{
return ( V_9 -> V_17 == V_37 || V_9 -> V_17 == V_38 ) ;
}
static inline int F_18 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
if ( V_9 -> V_17 != V_21 )
return 1 ;
return ( F_19 ( & V_7 -> V_15 ) < V_7 -> V_22 -> V_39 ) ;
}
static void F_20 ( struct V_8 * V_9 )
{
struct V_40 * V_41 ;
F_21 () ;
V_41 = F_22 ( V_9 -> V_42 ) ;
if ( F_23 ( V_41 ) )
F_24 ( & V_41 -> V_43 ) ;
F_25 ( V_9 , V_44 , V_45 ) ;
F_26 () ;
}
static void F_27 ( unsigned long V_46 )
{
struct V_8 * V_9 = (struct V_8 * ) V_46 ;
F_28 ( V_9 ) ;
V_9 -> V_27 = V_47 ;
V_9 -> V_29 ( V_9 ) ;
F_29 ( V_9 ) ;
F_30 ( V_9 ) ;
F_31 ( V_9 ) ;
}
static void F_32 ( struct V_8 * V_9 )
{
F_33 ( V_9 , & V_9 -> V_48 ) ;
}
static struct V_8 * F_34 ( char * V_49 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
F_9 (sk, node, &iucv_sk_list.head)
if ( ! memcmp ( & F_10 ( V_9 ) -> V_50 , V_49 , 8 ) )
return V_9 ;
return NULL ;
}
static void F_35 ( struct V_8 * V_9 )
{
F_11 ( & V_9 -> V_51 ) ;
F_11 ( & V_9 -> V_52 ) ;
}
static void F_36 ( struct V_8 * V_53 )
{
struct V_8 * V_9 ;
while ( ( V_9 = F_37 ( V_53 , NULL ) ) ) {
F_38 ( V_9 ) ;
F_30 ( V_9 ) ;
}
V_53 -> V_17 = V_26 ;
}
static void F_30 ( struct V_8 * V_9 )
{
if ( ! F_39 ( V_9 , V_54 ) || V_9 -> V_55 )
return;
F_40 ( & V_13 , V_9 ) ;
F_41 ( V_9 , V_56 ) ;
F_31 ( V_9 ) ;
}
static void F_38 ( struct V_8 * V_9 )
{
unsigned char V_57 [ 16 ] ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
unsigned long V_58 ;
F_32 ( V_9 ) ;
F_42 ( V_9 ) ;
switch ( V_9 -> V_17 ) {
case V_25 :
F_36 ( V_9 ) ;
break;
case V_21 :
case V_19 :
V_9 -> V_17 = V_20 ;
V_9 -> V_29 ( V_9 ) ;
if ( ! F_43 ( & V_7 -> V_15 ) ) {
if ( F_39 ( V_9 , V_59 ) && V_9 -> V_60 )
V_58 = V_9 -> V_60 ;
else
V_58 = V_61 ;
F_44 ( V_9 ,
F_17 ( V_9 , V_26 , 0 ) ,
V_58 ) ;
}
case V_20 :
V_9 -> V_17 = V_26 ;
V_9 -> V_29 ( V_9 ) ;
if ( V_7 -> V_22 ) {
F_2 ( V_57 , V_7 -> V_50 ) ;
F_1 ( V_57 , V_7 -> V_62 ) ;
F_45 ( V_57 , sizeof( V_57 ) ) ;
F_12 ( V_7 -> V_22 , V_57 ) ;
F_13 ( V_7 -> V_22 ) ;
V_7 -> V_22 = NULL ;
}
V_9 -> V_27 = V_63 ;
V_9 -> V_29 ( V_9 ) ;
F_11 ( & V_7 -> V_15 ) ;
F_11 ( & V_7 -> V_16 ) ;
break;
default:
break;
}
F_41 ( V_9 , V_54 ) ;
F_46 ( V_9 ) ;
}
static void F_47 ( struct V_8 * V_9 , struct V_8 * V_53 )
{
if ( V_53 )
V_9 -> V_64 = V_53 -> V_64 ;
}
static struct V_8 * F_48 ( struct V_65 * V_8 , int V_66 , T_2 V_67 )
{
struct V_8 * V_9 ;
V_9 = F_49 ( & V_68 , V_69 , V_67 , & V_70 ) ;
if ( ! V_9 )
return NULL ;
F_50 ( V_8 , V_9 ) ;
F_51 ( & F_10 ( V_9 ) -> V_71 ) ;
F_52 ( & F_10 ( V_9 ) -> V_72 ) ;
F_53 ( & F_10 ( V_9 ) -> V_15 ) ;
F_51 ( & F_10 ( V_9 ) -> V_73 . V_74 ) ;
F_52 ( & F_10 ( V_9 ) -> V_73 . V_14 ) ;
F_53 ( & F_10 ( V_9 ) -> V_16 ) ;
F_10 ( V_9 ) -> V_75 = 0 ;
F_10 ( V_9 ) -> V_33 = 0 ;
F_10 ( V_9 ) -> V_76 = V_77 ;
F_10 ( V_9 ) -> V_22 = NULL ;
memset ( & F_10 ( V_9 ) -> V_78 , 0 , 32 ) ;
V_9 -> V_79 = F_35 ;
V_9 -> V_80 = V_81 ;
V_9 -> V_82 = V_83 ;
F_54 ( V_9 , V_54 ) ;
V_9 -> V_84 = V_66 ;
V_9 -> V_17 = V_23 ;
F_55 ( & V_9 -> V_48 , F_27 , ( unsigned long ) V_9 ) ;
F_56 ( & V_13 , V_9 ) ;
return V_9 ;
}
static int F_57 ( struct V_85 * V_85 , struct V_65 * V_8 , int V_86 ,
int V_87 )
{
struct V_8 * V_9 ;
if ( V_86 && V_86 != V_69 )
return - V_88 ;
V_8 -> V_37 = V_89 ;
switch ( V_8 -> type ) {
case V_90 :
V_8 -> V_91 = & V_92 ;
break;
case V_93 :
V_8 -> V_91 = & V_92 ;
break;
default:
return - V_94 ;
}
V_9 = F_48 ( V_8 , V_86 , V_95 ) ;
if ( ! V_9 )
return - V_96 ;
F_47 ( V_9 , NULL ) ;
return 0 ;
}
void F_56 ( struct V_97 * V_98 , struct V_8 * V_9 )
{
F_58 ( & V_98 -> V_14 ) ;
F_59 ( V_9 , & V_98 -> V_99 ) ;
F_60 ( & V_98 -> V_14 ) ;
}
void F_40 ( struct V_97 * V_98 , struct V_8 * V_9 )
{
F_58 ( & V_98 -> V_14 ) ;
F_61 ( V_9 ) ;
F_60 ( & V_98 -> V_14 ) ;
}
void F_62 ( struct V_8 * V_53 , struct V_8 * V_9 )
{
unsigned long V_33 ;
struct V_6 * V_100 = F_10 ( V_53 ) ;
F_63 ( V_9 ) ;
F_64 ( & V_100 -> V_72 , V_33 ) ;
F_65 ( & F_10 ( V_9 ) -> V_71 , & V_100 -> V_71 ) ;
F_66 ( & V_100 -> V_72 , V_33 ) ;
F_10 ( V_9 ) -> V_53 = V_53 ;
F_67 ( V_53 ) ;
}
void F_68 ( struct V_8 * V_9 )
{
unsigned long V_33 ;
struct V_6 * V_100 = F_10 ( F_10 ( V_9 ) -> V_53 ) ;
F_64 ( & V_100 -> V_72 , V_33 ) ;
F_69 ( & F_10 ( V_9 ) -> V_71 ) ;
F_66 ( & V_100 -> V_72 , V_33 ) ;
F_70 ( F_10 ( V_9 ) -> V_53 ) ;
F_10 ( V_9 ) -> V_53 = NULL ;
F_31 ( V_9 ) ;
}
struct V_8 * F_37 ( struct V_8 * V_53 , struct V_65 * V_101 )
{
struct V_6 * V_102 , * V_103 ;
struct V_8 * V_9 ;
F_71 (isk, n, &iucv_sk(parent)->accept_q, accept_q) {
V_9 = (struct V_8 * ) V_102 ;
F_42 ( V_9 ) ;
if ( V_9 -> V_17 == V_26 ) {
F_68 ( V_9 ) ;
F_46 ( V_9 ) ;
continue;
}
if ( V_9 -> V_17 == V_21 ||
V_9 -> V_17 == V_18 ||
V_9 -> V_17 == V_19 ||
! V_101 ) {
F_68 ( V_9 ) ;
if ( V_101 )
F_72 ( V_9 , V_101 ) ;
if ( V_9 -> V_17 == V_18 )
V_9 -> V_17 = V_19 ;
F_46 ( V_9 ) ;
return V_9 ;
}
F_46 ( V_9 ) ;
}
return NULL ;
}
static int F_73 ( struct V_65 * V_8 , struct V_104 * V_105 ,
int V_106 )
{
struct V_107 * V_108 = (struct V_107 * ) V_105 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 ;
int V_12 ;
if ( ! V_105 || V_105 -> V_109 != V_110 )
return - V_111 ;
F_42 ( V_9 ) ;
if ( V_9 -> V_17 != V_23 ) {
V_12 = - V_112 ;
goto V_113;
}
F_58 ( & V_13 . V_14 ) ;
V_7 = F_10 ( V_9 ) ;
if ( F_34 ( V_108 -> V_114 ) ) {
V_12 = - V_115 ;
goto V_116;
}
if ( V_7 -> V_22 ) {
V_12 = 0 ;
goto V_116;
}
memcpy ( V_7 -> V_50 , V_108 -> V_114 , 8 ) ;
memcpy ( V_7 -> V_78 , V_117 , 8 ) ;
V_9 -> V_17 = V_24 ;
V_12 = 0 ;
V_116:
F_60 ( & V_13 . V_14 ) ;
V_113:
F_46 ( V_9 ) ;
return V_12 ;
}
static int F_74 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
char V_118 [ 80 ] ;
char V_119 [ 12 ] ;
int V_12 = 0 ;
F_75 ( L_5 , V_118 , sizeof( V_118 ) , & V_12 ) ;
if ( F_76 ( V_12 ) )
return - V_120 ;
memcpy ( V_7 -> V_78 , V_118 , 8 ) ;
F_58 ( & V_13 . V_14 ) ;
sprintf ( V_119 , L_6 , F_77 ( & V_13 . V_121 ) ) ;
while ( F_34 ( V_119 ) ) {
sprintf ( V_119 , L_6 ,
F_77 ( & V_13 . V_121 ) ) ;
}
F_60 ( & V_13 . V_14 ) ;
memcpy ( & V_7 -> V_50 , V_119 , 8 ) ;
return V_12 ;
}
static int F_78 ( struct V_65 * V_8 , struct V_104 * V_105 ,
int V_122 , int V_33 )
{
struct V_107 * V_108 = (struct V_107 * ) V_105 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 ;
unsigned char V_57 [ 16 ] ;
int V_12 ;
if ( V_105 -> V_109 != V_110 || V_122 < sizeof( struct V_107 ) )
return - V_111 ;
if ( V_9 -> V_17 != V_23 && V_9 -> V_17 != V_24 )
return - V_112 ;
if ( V_9 -> V_64 != V_90 && V_9 -> V_64 != V_93 )
return - V_111 ;
if ( V_9 -> V_17 == V_23 ) {
V_12 = F_74 ( V_9 ) ;
if ( F_76 ( V_12 ) )
return V_12 ;
}
F_42 ( V_9 ) ;
memcpy ( F_10 ( V_9 ) -> V_123 , V_108 -> V_124 , 8 ) ;
memcpy ( F_10 ( V_9 ) -> V_62 , V_108 -> V_114 , 8 ) ;
F_1 ( V_57 , V_108 -> V_114 ) ;
F_2 ( V_57 , F_10 ( V_9 ) -> V_50 ) ;
F_45 ( V_57 , sizeof( V_57 ) ) ;
V_7 = F_10 ( V_9 ) ;
V_7 -> V_22 = F_79 ( V_7 -> V_76 ,
V_34 , V_95 ) ;
if ( ! V_7 -> V_22 ) {
V_12 = - V_96 ;
goto V_113;
}
V_12 = F_80 ( V_7 -> V_22 , & V_125 ,
V_108 -> V_124 , NULL , V_57 , V_9 ) ;
if ( V_12 ) {
F_13 ( V_7 -> V_22 ) ;
V_7 -> V_22 = NULL ;
switch ( V_12 ) {
case 0x0b :
V_12 = - V_126 ;
break;
case 0x0d :
case 0x0e :
V_12 = - V_127 ;
break;
case 0x0f :
V_12 = - V_128 ;
break;
default:
V_12 = - V_129 ;
break;
}
goto V_113;
}
if ( V_9 -> V_17 != V_21 ) {
V_12 = F_44 ( V_9 , F_17 ( V_9 , V_21 ,
V_19 ) ,
F_81 ( V_9 , V_33 & V_130 ) ) ;
}
if ( V_9 -> V_17 == V_19 ) {
V_12 = - V_129 ;
}
if ( V_12 ) {
F_12 ( V_7 -> V_22 , NULL ) ;
F_13 ( V_7 -> V_22 ) ;
V_7 -> V_22 = NULL ;
}
V_113:
F_46 ( V_9 ) ;
return V_12 ;
}
static int F_82 ( struct V_65 * V_8 , int V_131 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
int V_12 ;
F_42 ( V_9 ) ;
V_12 = - V_111 ;
if ( V_9 -> V_17 != V_24 )
goto V_113;
if ( V_8 -> type != V_90 && V_8 -> type != V_93 )
goto V_113;
V_9 -> V_132 = V_131 ;
V_9 -> V_133 = 0 ;
V_9 -> V_17 = V_25 ;
V_12 = 0 ;
V_113:
F_46 ( V_9 ) ;
return V_12 ;
}
static int F_83 ( struct V_65 * V_8 , struct V_65 * V_101 ,
int V_33 )
{
F_84 ( V_43 , V_134 ) ;
struct V_8 * V_9 = V_8 -> V_9 , * V_135 ;
long V_58 ;
int V_12 = 0 ;
F_85 ( V_9 , V_136 ) ;
if ( V_9 -> V_17 != V_25 ) {
V_12 = - V_112 ;
goto V_113;
}
V_58 = F_86 ( V_9 , V_33 & V_130 ) ;
F_87 ( F_88 ( V_9 ) , & V_43 ) ;
while ( ! ( V_135 = F_37 ( V_9 , V_101 ) ) ) {
F_89 ( V_137 ) ;
if ( ! V_58 ) {
V_12 = - V_127 ;
break;
}
F_46 ( V_9 ) ;
V_58 = F_90 ( V_58 ) ;
F_85 ( V_9 , V_136 ) ;
if ( V_9 -> V_17 != V_25 ) {
V_12 = - V_112 ;
break;
}
if ( F_91 ( V_134 ) ) {
V_12 = F_92 ( V_58 ) ;
break;
}
}
F_89 ( V_138 ) ;
F_93 ( F_88 ( V_9 ) , & V_43 ) ;
if ( V_12 )
goto V_113;
V_101 -> V_37 = V_139 ;
V_113:
F_46 ( V_9 ) ;
return V_12 ;
}
static int F_94 ( struct V_65 * V_8 , struct V_104 * V_105 ,
int * V_140 , int V_141 )
{
struct V_107 * V_142 = (struct V_107 * ) V_105 ;
struct V_8 * V_9 = V_8 -> V_9 ;
V_105 -> V_109 = V_110 ;
* V_140 = sizeof( struct V_107 ) ;
if ( V_141 ) {
memcpy ( V_142 -> V_124 , F_10 ( V_9 ) -> V_123 , 8 ) ;
memcpy ( V_142 -> V_114 , & F_10 ( V_9 ) -> V_62 , 8 ) ;
} else {
memcpy ( V_142 -> V_124 , F_10 ( V_9 ) -> V_78 , 8 ) ;
memcpy ( V_142 -> V_114 , F_10 ( V_9 ) -> V_50 , 8 ) ;
}
memset ( & V_142 -> V_143 , 0 , sizeof( V_142 -> V_143 ) ) ;
memset ( & V_142 -> V_144 , 0 , sizeof( V_142 -> V_144 ) ) ;
memset ( V_142 -> V_145 , 0 , sizeof( V_142 -> V_145 ) ) ;
return 0 ;
}
static int F_95 ( struct V_146 * V_22 , struct V_30 * V_31 ,
struct V_147 * V_148 )
{
T_3 V_149 [ 8 ] ;
memcpy ( V_149 , ( void * ) V_148 -> V_150 , V_148 -> V_140 ) ;
V_149 [ 7 ] = 0xff - ( T_3 ) V_148 -> V_140 ;
return F_96 ( V_22 , V_31 , V_34 , 0 ,
( void * ) V_149 , 8 ) ;
}
static int F_97 ( struct V_151 * V_152 , struct V_65 * V_8 ,
struct V_153 * V_31 , T_1 V_140 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_147 * V_148 ;
struct V_30 V_154 ;
struct V_155 * V_156 ;
int V_157 ;
long V_58 ;
char V_158 [ 9 ] ;
char V_159 [ 9 ] ;
int V_12 ;
int V_160 = V_31 -> V_161 & V_162 ;
V_12 = F_98 ( V_9 ) ;
if ( V_12 )
return V_12 ;
if ( V_31 -> V_161 & V_163 )
return - V_164 ;
if ( V_9 -> V_64 == V_93 && ! ( V_31 -> V_161 & V_165 ) )
return - V_164 ;
F_42 ( V_9 ) ;
if ( V_9 -> V_166 & V_167 ) {
V_12 = - V_28 ;
goto V_168;
}
if ( V_9 -> V_17 != V_21 ) {
V_12 = - V_169 ;
goto V_168;
}
V_157 = 0 ;
V_154 . V_170 = 0 ;
for ( V_156 = F_99 ( V_31 ) ; V_156 ;
V_156 = F_100 ( V_31 , V_156 ) ) {
if ( ! F_101 ( V_31 , V_156 ) ) {
V_12 = - V_111 ;
goto V_168;
}
if ( V_156 -> V_171 != V_172 )
continue;
if ( V_156 -> V_173 & V_157 ) {
V_12 = - V_111 ;
goto V_168;
}
V_157 |= V_156 -> V_173 ;
switch ( V_156 -> V_173 ) {
case V_174 :
if ( V_156 -> V_175 != F_102 ( V_176 ) ) {
V_12 = - V_111 ;
goto V_168;
}
memcpy ( & V_154 . V_170 ,
( void * ) F_103 ( V_156 ) , V_176 ) ;
break;
default:
V_12 = - V_111 ;
goto V_168;
break;
}
}
V_148 = F_104 ( V_9 , V_140 , V_160 , & V_12 ) ;
if ( ! V_148 )
goto V_168;
if ( F_105 ( F_106 ( V_148 , V_140 ) , V_31 -> V_177 , V_140 ) ) {
V_12 = - V_178 ;
goto V_179;
}
V_58 = F_81 ( V_9 , V_160 ) ;
V_12 = F_44 ( V_9 , F_18 ( V_9 ) , V_58 ) ;
if ( V_12 )
goto V_179;
if ( V_9 -> V_17 != V_21 ) {
V_12 = - V_63 ;
goto V_179;
}
V_154 . V_180 = V_7 -> V_75 ++ ;
memcpy ( F_107 ( V_148 ) , & V_154 . V_180 , V_181 ) ;
F_108 ( & V_7 -> V_15 , V_148 ) ;
if ( ( ( V_7 -> V_22 -> V_33 & V_34 ) & V_7 -> V_33 )
&& V_148 -> V_140 <= 7 ) {
V_12 = F_95 ( V_7 -> V_22 , & V_154 , V_148 ) ;
if ( V_12 == 0 ) {
F_109 ( V_148 , & V_7 -> V_15 ) ;
F_110 ( V_148 ) ;
}
if ( V_12 == 0x15 ) {
F_12 ( V_7 -> V_22 , NULL ) ;
F_109 ( V_148 , & V_7 -> V_15 ) ;
V_12 = - V_28 ;
goto V_179;
}
} else
V_12 = F_96 ( V_7 -> V_22 , & V_154 , 0 , 0 ,
( void * ) V_148 -> V_150 , V_148 -> V_140 ) ;
if ( V_12 ) {
if ( V_12 == 3 ) {
V_158 [ 8 ] = 0 ;
memcpy ( V_158 , V_7 -> V_123 , 8 ) ;
V_159 [ 8 ] = 0 ;
memcpy ( V_159 , V_7 -> V_62 , 8 ) ;
F_111 ( L_7
L_8 ,
V_159 , V_158 ) ;
V_12 = - V_127 ;
} else
V_12 = - V_28 ;
F_109 ( V_148 , & V_7 -> V_15 ) ;
goto V_179;
}
F_46 ( V_9 ) ;
return V_140 ;
V_179:
F_110 ( V_148 ) ;
V_168:
F_46 ( V_9 ) ;
return V_12 ;
}
static int F_112 ( struct V_8 * V_9 , struct V_147 * V_148 , int V_140 )
{
int V_182 , V_183 , V_184 = 0 ;
struct V_147 * V_185 ;
V_182 = V_140 ;
while ( V_182 ) {
if ( V_182 >= V_9 -> V_186 / 4 )
V_183 = V_9 -> V_186 / 4 ;
else
V_183 = V_182 ;
V_185 = F_113 ( V_183 , V_187 | V_83 ) ;
if ( ! V_185 )
return - V_96 ;
memcpy ( F_114 ( V_185 ) , F_114 ( V_148 ) , V_188 ) ;
memcpy ( V_185 -> V_150 , V_148 -> V_150 + V_184 , V_183 ) ;
V_184 += V_183 ;
V_182 -= V_183 ;
F_115 ( V_185 ) ;
F_116 ( V_185 ) ;
V_185 -> V_140 = V_183 ;
F_108 ( & F_10 ( V_9 ) -> V_16 , V_185 ) ;
}
return 0 ;
}
static void F_117 ( struct V_8 * V_9 , struct V_147 * V_148 ,
struct V_146 * V_22 ,
struct V_30 * V_31 )
{
int V_189 ;
unsigned int V_140 ;
V_140 = F_16 ( V_31 ) ;
memcpy ( F_114 ( V_148 ) , & V_31 -> V_170 , V_188 ) ;
if ( ( V_31 -> V_33 & V_34 ) && V_140 > 7 ) {
if ( memcmp ( V_31 -> V_35 , V_190 , 8 ) == 0 ) {
V_148 -> V_150 = NULL ;
V_148 -> V_140 = 0 ;
}
} else {
V_189 = F_118 ( V_22 , V_31 , V_31 -> V_33 & V_34 ,
V_148 -> V_150 , V_140 , NULL ) ;
if ( V_189 ) {
F_110 ( V_148 ) ;
return;
}
if ( V_9 -> V_64 == V_90 &&
V_148 -> V_191 >= V_9 -> V_186 / 4 ) {
V_189 = F_112 ( V_9 , V_148 , V_140 ) ;
F_110 ( V_148 ) ;
V_148 = NULL ;
if ( V_189 ) {
F_12 ( V_22 , NULL ) ;
return;
}
V_148 = F_119 ( & F_10 ( V_9 ) -> V_16 ) ;
} else {
F_115 ( V_148 ) ;
F_116 ( V_148 ) ;
V_148 -> V_140 = V_140 ;
}
}
if ( F_120 ( V_9 , V_148 ) )
F_121 ( & F_10 ( V_9 ) -> V_16 , V_148 ) ;
}
static void F_122 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_147 * V_148 ;
struct V_192 * V_193 , * V_103 ;
F_71 (p, n, &iucv->message_q.list, list) {
V_148 = F_113 ( F_16 ( & V_193 -> V_31 ) , V_187 | V_83 ) ;
if ( ! V_148 )
break;
F_117 ( V_9 , V_148 , V_193 -> V_22 , & V_193 -> V_31 ) ;
F_123 ( & V_193 -> V_74 ) ;
F_124 ( V_193 ) ;
if ( ! F_43 ( & V_7 -> V_16 ) )
break;
}
}
static int F_125 ( struct V_151 * V_152 , struct V_65 * V_8 ,
struct V_153 * V_31 , T_1 V_140 , int V_33 )
{
int V_160 = V_33 & V_162 ;
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
unsigned int V_184 , V_194 ;
struct V_147 * V_148 , * V_195 , * V_196 ;
int V_12 = 0 ;
if ( ( V_9 -> V_17 == V_19 || V_9 -> V_17 == V_18 ) &&
F_43 ( & V_7 -> V_16 ) &&
F_43 ( & V_9 -> V_51 ) &&
F_126 ( & V_7 -> V_73 . V_74 ) )
return 0 ;
if ( V_33 & ( V_163 ) )
return - V_164 ;
V_148 = F_127 ( V_9 , V_33 , V_160 , & V_12 ) ;
if ( ! V_148 ) {
if ( V_9 -> V_166 & V_197 )
return 0 ;
return V_12 ;
}
V_194 = V_148 -> V_140 ;
V_184 = F_128 (unsigned int, rlen, len) ;
V_196 = V_148 ;
if ( F_129 ( V_31 -> V_177 , V_196 -> V_150 , V_184 ) ) {
if ( ! ( V_33 & V_198 ) )
F_121 ( & V_9 -> V_51 , V_148 ) ;
return - V_178 ;
}
if ( V_9 -> V_64 == V_93 ) {
if ( V_184 < V_194 )
V_31 -> V_161 |= V_199 ;
V_31 -> V_161 |= V_165 ;
}
V_12 = F_130 ( V_31 , V_172 , V_174 ,
V_188 , F_114 ( V_148 ) ) ;
if ( V_12 ) {
if ( ! ( V_33 & V_198 ) )
F_121 ( & V_9 -> V_51 , V_148 ) ;
return V_12 ;
}
if ( ! ( V_33 & V_198 ) ) {
if ( V_9 -> V_64 == V_90 ) {
F_131 ( V_148 , V_184 ) ;
if ( V_148 -> V_140 ) {
F_121 ( & V_9 -> V_51 , V_148 ) ;
goto V_113;
}
}
F_110 ( V_148 ) ;
F_132 ( & V_7 -> V_73 . V_14 ) ;
V_195 = F_119 ( & V_7 -> V_16 ) ;
while ( V_195 ) {
if ( F_120 ( V_9 , V_195 ) ) {
F_121 ( & V_7 -> V_16 ,
V_195 ) ;
break;
} else {
V_195 = F_119 ( & V_7 -> V_16 ) ;
}
}
if ( F_43 ( & V_7 -> V_16 ) ) {
if ( ! F_126 ( & V_7 -> V_73 . V_74 ) )
F_122 ( V_9 ) ;
}
F_133 ( & V_7 -> V_73 . V_14 ) ;
}
V_113:
if ( V_9 -> V_64 == V_93 && ( V_33 & V_199 ) )
V_184 = V_194 ;
return V_184 ;
}
static inline unsigned int F_134 ( struct V_8 * V_53 )
{
struct V_6 * V_102 , * V_103 ;
struct V_8 * V_9 ;
F_71 (isk, n, &iucv_sk(parent)->accept_q, accept_q) {
V_9 = (struct V_8 * ) V_102 ;
if ( V_9 -> V_17 == V_21 )
return V_200 | V_201 ;
}
return 0 ;
}
unsigned int F_135 ( struct V_202 * V_202 , struct V_65 * V_8 ,
T_4 * V_43 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
unsigned int V_203 = 0 ;
F_136 ( V_202 , F_88 ( V_9 ) , V_43 ) ;
if ( V_9 -> V_17 == V_25 )
return F_134 ( V_9 ) ;
if ( V_9 -> V_27 || ! F_43 ( & V_9 -> V_204 ) )
V_203 |= V_205 ;
if ( V_9 -> V_166 & V_197 )
V_203 |= V_206 ;
if ( V_9 -> V_166 == V_207 )
V_203 |= V_208 ;
if ( ! F_43 ( & V_9 -> V_51 ) ||
( V_9 -> V_166 & V_197 ) )
V_203 |= V_200 | V_201 ;
if ( V_9 -> V_17 == V_26 )
V_203 |= V_208 ;
if ( V_9 -> V_17 == V_19 || V_9 -> V_17 == V_18 )
V_203 |= V_200 ;
if ( F_137 ( V_9 ) )
V_203 |= V_209 | V_210 | V_211 ;
else
F_138 ( V_212 , & V_9 -> V_55 -> V_33 ) ;
return V_203 ;
}
static int F_139 ( struct V_65 * V_8 , int V_213 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_30 V_154 ;
int V_12 = 0 ;
V_213 ++ ;
if ( ( V_213 & ~ V_207 ) || ! V_213 )
return - V_111 ;
F_42 ( V_9 ) ;
switch ( V_9 -> V_17 ) {
case V_19 :
case V_20 :
case V_18 :
case V_26 :
V_12 = - V_169 ;
goto V_179;
default:
V_9 -> V_166 |= V_213 ;
break;
}
if ( V_213 == V_167 || V_213 == V_207 ) {
V_154 . V_170 = 0 ;
V_154 . V_180 = 0 ;
V_12 = F_96 ( V_7 -> V_22 , & V_154 , V_34 , 0 ,
( void * ) V_190 , 8 ) ;
if ( V_12 ) {
switch ( V_12 ) {
case 1 :
V_12 = - V_169 ;
break;
case 2 :
V_12 = - V_63 ;
break;
default:
V_12 = - V_169 ;
break;
}
}
}
if ( V_213 == V_197 || V_213 == V_207 ) {
V_12 = F_140 ( F_10 ( V_9 ) -> V_22 , NULL ) ;
if ( V_12 )
V_12 = - V_169 ;
F_11 ( & V_9 -> V_51 ) ;
}
V_9 -> V_29 ( V_9 ) ;
V_179:
F_46 ( V_9 ) ;
return V_12 ;
}
static int F_141 ( struct V_65 * V_8 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
int V_12 = 0 ;
if ( ! V_9 )
return 0 ;
F_38 ( V_9 ) ;
if ( F_10 ( V_9 ) -> V_22 ) {
F_12 ( F_10 ( V_9 ) -> V_22 , NULL ) ;
F_13 ( F_10 ( V_9 ) -> V_22 ) ;
F_10 ( V_9 ) -> V_22 = NULL ;
}
F_142 ( V_9 ) ;
F_30 ( V_9 ) ;
return V_12 ;
}
static int F_143 ( struct V_65 * V_8 , int V_214 , int V_215 ,
char T_5 * V_216 , unsigned int V_217 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
int V_218 ;
int V_189 ;
if ( V_214 != V_172 )
return - V_219 ;
if ( V_217 < sizeof( int ) )
return - V_111 ;
if ( F_144 ( V_218 , ( int T_5 * ) V_216 ) )
return - V_178 ;
V_189 = 0 ;
F_42 ( V_9 ) ;
switch ( V_215 ) {
case V_220 :
if ( V_218 )
V_7 -> V_33 |= V_34 ;
else
V_7 -> V_33 &= ~ V_34 ;
break;
case V_221 :
switch ( V_9 -> V_17 ) {
case V_23 :
case V_24 :
if ( V_218 < 1 || V_218 > ( V_222 ) ( ~ 0 ) )
V_189 = - V_111 ;
else
V_7 -> V_76 = V_218 ;
break;
default:
V_189 = - V_111 ;
break;
}
break;
default:
V_189 = - V_219 ;
break;
}
F_46 ( V_9 ) ;
return V_189 ;
}
static int F_145 ( struct V_65 * V_8 , int V_214 , int V_215 ,
char T_5 * V_216 , int T_5 * V_217 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
int V_218 , V_140 ;
if ( V_214 != V_172 )
return - V_219 ;
if ( F_144 ( V_140 , V_217 ) )
return - V_178 ;
if ( V_140 < 0 )
return - V_111 ;
V_140 = F_128 (unsigned int, len, sizeof(int)) ;
switch ( V_215 ) {
case V_220 :
V_218 = ( V_7 -> V_33 & V_34 ) ? 1 : 0 ;
break;
case V_221 :
F_42 ( V_9 ) ;
V_218 = ( V_7 -> V_22 != NULL ) ? V_7 -> V_22 -> V_39
: V_7 -> V_76 ;
F_46 ( V_9 ) ;
break;
default:
return - V_219 ;
}
if ( F_146 ( V_140 , V_217 ) )
return - V_178 ;
if ( F_147 ( V_216 , & V_218 , V_140 ) )
return - V_178 ;
return 0 ;
}
static int F_148 ( struct V_146 * V_22 ,
T_3 V_223 [ 8 ] , T_3 V_224 [ 16 ] )
{
unsigned char V_57 [ 16 ] ;
unsigned char V_225 [ 16 ] ;
unsigned char V_50 [ 8 ] ;
struct V_10 * V_11 ;
struct V_8 * V_9 , * V_135 ;
struct V_6 * V_7 , * V_226 ;
int V_12 ;
memcpy ( V_50 , V_224 , 8 ) ;
F_149 ( V_50 , 8 ) ;
F_8 ( & V_13 . V_14 ) ;
V_7 = NULL ;
V_9 = NULL ;
F_9 (sk, node, &iucv_sk_list.head)
if ( V_9 -> V_17 == V_25 &&
! memcmp ( & F_10 ( V_9 ) -> V_50 , V_50 , 8 ) ) {
V_7 = F_10 ( V_9 ) ;
break;
}
F_14 ( & V_13 . V_14 ) ;
if ( ! V_7 )
return - V_111 ;
F_28 ( V_9 ) ;
F_2 ( V_57 , V_7 -> V_50 ) ;
F_1 ( V_57 , V_7 -> V_62 ) ;
F_45 ( V_57 , sizeof( V_57 ) ) ;
if ( V_9 -> V_17 != V_25 ) {
V_12 = F_12 ( V_22 , V_57 ) ;
F_13 ( V_22 ) ;
goto V_179;
}
if ( F_150 ( V_9 ) ) {
V_12 = F_12 ( V_22 , V_57 ) ;
F_13 ( V_22 ) ;
goto V_179;
}
V_135 = F_48 ( NULL , V_9 -> V_64 , V_187 ) ;
if ( ! V_135 ) {
V_12 = F_12 ( V_22 , V_57 ) ;
F_13 ( V_22 ) ;
goto V_179;
}
V_226 = F_10 ( V_135 ) ;
F_47 ( V_135 , V_9 ) ;
memcpy ( V_226 -> V_62 , V_224 + 8 , 8 ) ;
F_149 ( V_226 -> V_62 , 8 ) ;
memcpy ( V_226 -> V_123 , V_223 , 8 ) ;
memcpy ( V_226 -> V_50 , V_7 -> V_50 , 8 ) ;
memcpy ( V_226 -> V_78 , V_7 -> V_78 , 8 ) ;
V_226 -> V_22 = V_22 ;
F_1 ( V_225 , V_224 + 8 ) ;
memcpy ( V_225 + 8 , V_226 -> V_50 , 8 ) ;
F_45 ( V_225 + 8 , 8 ) ;
V_226 -> V_76 = V_7 -> V_76 ;
V_22 -> V_39 = V_7 -> V_76 ;
V_12 = F_151 ( V_22 , & V_125 , V_225 , V_135 ) ;
if ( V_12 ) {
V_12 = F_12 ( V_22 , V_57 ) ;
F_13 ( V_22 ) ;
F_30 ( V_135 ) ;
goto V_179;
}
F_62 ( V_9 , V_135 ) ;
V_135 -> V_17 = V_21 ;
V_9 -> V_227 ( V_9 , 1 ) ;
V_12 = 0 ;
V_179:
F_29 ( V_9 ) ;
return 0 ;
}
static void F_152 ( struct V_146 * V_22 , T_3 V_224 [ 16 ] )
{
struct V_8 * V_9 = V_22 -> V_228 ;
V_9 -> V_17 = V_21 ;
V_9 -> V_29 ( V_9 ) ;
}
static void F_153 ( struct V_146 * V_22 , struct V_30 * V_31 )
{
struct V_8 * V_9 = V_22 -> V_228 ;
struct V_6 * V_7 = F_10 ( V_9 ) ;
struct V_147 * V_148 ;
struct V_192 * V_229 ;
int V_140 ;
if ( V_9 -> V_166 & V_197 ) {
F_154 ( V_22 , V_31 ) ;
return;
}
F_155 ( & V_7 -> V_73 . V_14 ) ;
if ( ! F_126 ( & V_7 -> V_73 . V_74 ) ||
! F_43 ( & V_7 -> V_16 ) )
goto V_230;
V_140 = F_156 ( & V_9 -> V_231 ) ;
V_140 += F_16 ( V_31 ) + sizeof( struct V_147 ) ;
if ( V_140 > V_9 -> V_186 )
goto V_230;
V_148 = F_113 ( F_16 ( V_31 ) , V_187 | V_83 ) ;
if ( ! V_148 )
goto V_230;
F_117 ( V_9 , V_148 , V_22 , V_31 ) ;
goto V_232;
V_230:
V_229 = F_157 ( sizeof( struct V_192 ) , V_187 | V_83 ) ;
if ( ! V_229 )
goto V_232;
V_229 -> V_22 = V_22 ;
V_229 -> V_31 = * V_31 ;
F_65 ( & V_229 -> V_74 , & V_7 -> V_73 . V_74 ) ;
V_232:
F_158 ( & V_7 -> V_73 . V_14 ) ;
}
static void F_159 ( struct V_146 * V_22 ,
struct V_30 * V_31 )
{
struct V_8 * V_9 = V_22 -> V_228 ;
struct V_147 * V_233 = NULL ;
struct V_234 * V_74 = & F_10 ( V_9 ) -> V_15 ;
struct V_147 * V_235 = V_74 -> V_236 ;
unsigned long V_33 ;
if ( ! F_43 ( V_74 ) ) {
F_64 ( & V_74 -> V_14 , V_33 ) ;
while ( V_235 != (struct V_147 * ) V_74 ) {
if ( ! memcmp ( & V_31 -> V_180 , F_107 ( V_235 ) , V_181 ) ) {
V_233 = V_235 ;
break;
}
V_235 = V_235 -> V_236 ;
}
if ( V_233 )
F_160 ( V_233 , V_74 ) ;
F_66 ( & V_74 -> V_14 , V_33 ) ;
if ( V_233 ) {
F_110 ( V_233 ) ;
F_20 ( V_9 ) ;
}
}
F_161 ( ! V_233 ) ;
if ( V_9 -> V_17 == V_20 ) {
if ( F_43 ( & F_10 ( V_9 ) -> V_15 ) ) {
V_9 -> V_17 = V_26 ;
V_9 -> V_29 ( V_9 ) ;
}
}
}
static void F_162 ( struct V_146 * V_22 , T_3 V_224 [ 16 ] )
{
struct V_8 * V_9 = V_22 -> V_228 ;
if ( ! F_126 ( & F_10 ( V_9 ) -> V_71 ) )
V_9 -> V_17 = V_18 ;
else
V_9 -> V_17 = V_19 ;
V_9 -> V_29 ( V_9 ) ;
}
static void F_163 ( struct V_146 * V_22 , T_3 V_224 [ 16 ] )
{
struct V_8 * V_9 = V_22 -> V_228 ;
F_28 ( V_9 ) ;
if ( V_9 -> V_17 != V_26 ) {
V_9 -> V_166 |= V_167 ;
V_9 -> V_29 ( V_9 ) ;
}
F_29 ( V_9 ) ;
}
static int T_6 F_164 ( void )
{
int V_12 ;
if ( ! V_237 ) {
F_111 ( L_9
L_10 ) ;
V_12 = - V_88 ;
goto V_168;
}
F_75 ( L_5 , V_117 , sizeof( V_117 ) , & V_12 ) ;
if ( F_76 ( V_12 ) ) {
F_165 ( V_12 ) ;
V_12 = - V_88 ;
goto V_168;
}
V_12 = F_166 ( & V_125 , 0 ) ;
if ( V_12 )
goto V_168;
V_12 = F_167 ( & V_70 , 0 ) ;
if ( V_12 )
goto V_238;
V_12 = F_168 ( & V_239 ) ;
if ( V_12 )
goto V_240;
V_12 = F_169 ( & V_241 ) ;
if ( V_12 )
goto V_242;
V_243 = F_157 ( sizeof( struct V_3 ) , V_95 ) ;
if ( ! V_243 ) {
V_12 = - V_96 ;
goto V_244;
}
F_170 ( V_243 , L_11 ) ;
V_243 -> V_245 = & V_246 ;
V_243 -> V_53 = V_247 ;
V_243 -> V_248 = ( void ( * ) ( struct V_3 * ) ) F_124 ;
V_243 -> V_249 = & V_241 ;
V_12 = F_171 ( V_243 ) ;
if ( V_12 )
goto V_244;
return 0 ;
V_244:
F_172 ( & V_241 ) ;
V_242:
F_173 ( V_69 ) ;
V_240:
F_174 ( & V_70 ) ;
V_238:
F_175 ( & V_125 , 0 ) ;
V_168:
return V_12 ;
}
static void T_7 F_176 ( void )
{
F_177 ( V_243 ) ;
F_172 ( & V_241 ) ;
F_173 ( V_69 ) ;
F_174 ( & V_70 ) ;
F_175 ( & V_125 , 0 ) ;
}
