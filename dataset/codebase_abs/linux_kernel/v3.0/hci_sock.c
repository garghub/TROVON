static inline int F_1 ( int V_1 , void * V_2 )
{
return * ( ( V_3 * ) V_2 + ( V_1 >> 5 ) ) & ( ( V_3 ) 1 << ( V_1 & 31 ) ) ;
}
void F_2 ( struct V_4 * V_5 , struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_8 * V_10 ;
struct V_11 * V_12 ;
F_3 ( L_1 , V_5 , V_7 -> V_13 ) ;
F_4 ( & V_14 . V_15 ) ;
F_5 (sk, node, &hci_sk_list.head) {
struct V_16 * V_17 ;
struct V_6 * V_18 ;
if ( V_10 == V_9 )
continue;
if ( V_10 -> V_19 != V_20 || F_6 ( V_10 ) -> V_5 != V_5 )
continue;
if ( V_7 -> V_10 == V_10 )
continue;
if ( F_7 ( V_7 ) -> V_21 != F_6 ( V_10 ) -> V_21 )
continue;
if ( F_7 ( V_7 ) -> V_21 == V_22 )
goto V_23;
V_17 = & F_6 ( V_10 ) -> V_24 ;
if ( ! F_8 ( ( F_7 ( V_7 ) -> V_25 == V_26 ) ?
0 : ( F_7 ( V_7 ) -> V_25 & V_27 ) , & V_17 -> V_28 ) )
continue;
if ( F_7 ( V_7 ) -> V_25 == V_29 ) {
register int V_30 = ( * ( V_31 * ) V_7 -> V_32 & V_33 ) ;
if ( ! F_1 ( V_30 , & V_17 -> V_34 ) )
continue;
if ( V_17 -> V_35 &&
( ( V_30 == V_36 &&
V_17 -> V_35 !=
F_9 ( ( V_37 * ) ( V_7 -> V_32 + 3 ) ) ) ||
( V_30 == V_38 &&
V_17 -> V_35 !=
F_9 ( ( V_37 * ) ( V_7 -> V_32 + 4 ) ) ) ) )
continue;
}
V_23:
V_18 = F_10 ( V_7 , V_39 ) ;
if ( ! V_18 )
continue;
if ( F_7 ( V_7 ) -> V_21 == V_40 )
memcpy ( F_11 ( V_18 , 1 ) , & F_7 ( V_18 ) -> V_25 , 1 ) ;
if ( F_12 ( V_10 , V_18 ) )
F_13 ( V_18 ) ;
}
F_14 ( & V_14 . V_15 ) ;
}
static int F_15 ( struct V_41 * V_8 )
{
struct V_8 * V_10 = V_8 -> V_10 ;
struct V_4 * V_5 ;
F_3 ( L_2 , V_8 , V_10 ) ;
if ( ! V_10 )
return 0 ;
V_5 = F_6 ( V_10 ) -> V_5 ;
F_16 ( & V_14 , V_10 ) ;
if ( V_5 ) {
F_17 ( & V_5 -> V_42 ) ;
F_18 ( V_5 ) ;
}
F_19 ( V_10 ) ;
F_20 ( & V_10 -> V_43 ) ;
F_20 ( & V_10 -> V_44 ) ;
F_21 ( V_10 ) ;
return 0 ;
}
struct V_45 * F_22 ( struct V_4 * V_5 , T_1 * V_46 )
{
struct V_47 * V_48 ;
F_23 (p, &hdev->blacklist) {
struct V_45 * V_49 ;
V_49 = F_24 ( V_48 , struct V_45 , V_50 ) ;
if ( F_25 ( V_46 , & V_49 -> V_46 ) == 0 )
return V_49 ;
}
return NULL ;
}
static int F_26 ( struct V_4 * V_5 , void T_2 * V_51 )
{
T_1 V_46 ;
struct V_45 * V_52 ;
if ( F_27 ( & V_46 , V_51 , sizeof( V_46 ) ) )
return - V_53 ;
if ( F_25 ( & V_46 , V_54 ) == 0 )
return - V_55 ;
if ( F_22 ( V_5 , & V_46 ) )
return - V_56 ;
V_52 = F_28 ( sizeof( struct V_45 ) , V_57 ) ;
if ( ! V_52 )
return - V_58 ;
F_29 ( & V_52 -> V_46 , & V_46 ) ;
F_30 ( & V_52 -> V_50 , & V_5 -> V_59 ) ;
return 0 ;
}
int F_31 ( struct V_4 * V_5 )
{
struct V_47 * V_48 , * V_60 ;
F_32 (p, n, &hdev->blacklist) {
struct V_45 * V_49 ;
V_49 = F_24 ( V_48 , struct V_45 , V_50 ) ;
F_33 ( V_48 ) ;
F_34 ( V_49 ) ;
}
return 0 ;
}
static int F_35 ( struct V_4 * V_5 , void T_2 * V_51 )
{
T_1 V_46 ;
struct V_45 * V_52 ;
if ( F_27 ( & V_46 , V_51 , sizeof( V_46 ) ) )
return - V_53 ;
if ( F_25 ( & V_46 , V_54 ) == 0 )
return F_31 ( V_5 ) ;
V_52 = F_22 ( V_5 , & V_46 ) ;
if ( ! V_52 )
return - V_61 ;
F_33 ( & V_52 -> V_50 ) ;
F_34 ( V_52 ) ;
return 0 ;
}
static inline int F_36 ( struct V_8 * V_10 , unsigned int V_62 , unsigned long V_51 )
{
struct V_4 * V_5 = F_6 ( V_10 ) -> V_5 ;
if ( ! V_5 )
return - V_63 ;
switch ( V_62 ) {
case V_64 :
if ( ! F_37 ( V_65 ) )
return - V_66 ;
if ( F_8 ( V_67 , & V_5 -> V_68 ) )
return - V_69 ;
if ( V_51 )
F_38 ( V_70 , & V_5 -> V_71 ) ;
else
F_39 ( V_70 , & V_5 -> V_71 ) ;
return 0 ;
case V_72 :
return F_40 ( V_5 , ( void T_2 * ) V_51 ) ;
case V_73 :
return F_41 ( V_5 , ( void T_2 * ) V_51 ) ;
case V_74 :
if ( ! F_37 ( V_65 ) )
return - V_66 ;
return F_26 ( V_5 , ( void T_2 * ) V_51 ) ;
case V_75 :
if ( ! F_37 ( V_65 ) )
return - V_66 ;
return F_35 ( V_5 , ( void T_2 * ) V_51 ) ;
default:
if ( V_5 -> V_76 )
return V_5 -> V_76 ( V_5 , V_62 , V_51 ) ;
return - V_77 ;
}
}
static int F_42 ( struct V_41 * V_8 , unsigned int V_62 , unsigned long V_51 )
{
struct V_8 * V_10 = V_8 -> V_10 ;
void T_2 * V_78 = ( void T_2 * ) V_51 ;
int V_79 ;
F_3 ( L_3 , V_62 , V_51 ) ;
switch ( V_62 ) {
case V_80 :
return F_43 ( V_78 ) ;
case V_81 :
return F_44 ( V_78 ) ;
case V_82 :
return F_45 ( V_78 ) ;
case V_83 :
if ( ! F_37 ( V_65 ) )
return - V_66 ;
return F_46 ( V_51 ) ;
case V_84 :
if ( ! F_37 ( V_65 ) )
return - V_66 ;
return F_47 ( V_51 ) ;
case V_85 :
if ( ! F_37 ( V_65 ) )
return - V_66 ;
return F_48 ( V_51 ) ;
case V_86 :
if ( ! F_37 ( V_65 ) )
return - V_66 ;
return F_49 ( V_51 ) ;
case V_87 :
case V_88 :
case V_89 :
case V_90 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
if ( ! F_37 ( V_65 ) )
return - V_66 ;
return F_50 ( V_62 , V_78 ) ;
case V_95 :
return F_51 ( V_78 ) ;
default:
F_52 ( V_10 ) ;
V_79 = F_36 ( V_10 , V_62 , V_51 ) ;
F_53 ( V_10 ) ;
return V_79 ;
}
}
static int F_54 ( struct V_41 * V_8 , struct V_96 * V_2 , int V_97 )
{
struct V_98 V_99 ;
struct V_8 * V_10 = V_8 -> V_10 ;
struct V_4 * V_5 = NULL ;
int V_13 , V_79 = 0 ;
F_3 ( L_2 , V_8 , V_10 ) ;
if ( ! V_2 )
return - V_77 ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
V_13 = F_55 (unsigned int, sizeof(haddr), addr_len) ;
memcpy ( & V_99 , V_2 , V_13 ) ;
if ( V_99 . V_100 != V_101 )
return - V_77 ;
if ( V_99 . V_102 > V_22 )
return - V_77 ;
if ( V_99 . V_102 == V_22 && ! V_103 )
return - V_77 ;
F_52 ( V_10 ) ;
if ( V_10 -> V_19 == V_20 || F_6 ( V_10 ) -> V_5 ) {
V_79 = - V_104 ;
goto V_105;
}
if ( V_99 . V_4 != V_106 ) {
V_5 = F_56 ( V_99 . V_4 ) ;
if ( ! V_5 ) {
V_79 = - V_107 ;
goto V_105;
}
F_57 ( & V_5 -> V_42 ) ;
}
F_6 ( V_10 ) -> V_21 = V_99 . V_102 ;
F_6 ( V_10 ) -> V_5 = V_5 ;
V_10 -> V_19 = V_20 ;
V_105:
F_53 ( V_10 ) ;
return V_79 ;
}
static int F_58 ( struct V_41 * V_8 , struct V_96 * V_2 , int * V_97 , int V_108 )
{
struct V_98 * V_99 = (struct V_98 * ) V_2 ;
struct V_8 * V_10 = V_8 -> V_10 ;
struct V_4 * V_5 = F_6 ( V_10 ) -> V_5 ;
F_3 ( L_2 , V_8 , V_10 ) ;
if ( ! V_5 )
return - V_63 ;
F_52 ( V_10 ) ;
* V_97 = sizeof( * V_99 ) ;
V_99 -> V_100 = V_101 ;
V_99 -> V_4 = V_5 -> V_109 ;
F_53 ( V_10 ) ;
return 0 ;
}
static inline void F_59 ( struct V_8 * V_10 , struct V_110 * V_111 , struct V_6 * V_7 )
{
V_3 V_112 = F_6 ( V_10 ) -> V_113 ;
if ( V_112 & V_114 ) {
int V_115 = F_7 ( V_7 ) -> V_115 ;
F_60 ( V_111 , V_116 , V_114 , sizeof( V_115 ) , & V_115 ) ;
}
if ( V_112 & V_117 ) {
#ifdef F_61
struct V_118 V_119 ;
#endif
struct V_120 V_121 ;
void * V_32 ;
int V_13 ;
F_62 ( V_7 , & V_121 ) ;
V_32 = & V_121 ;
V_13 = sizeof( V_121 ) ;
#ifdef F_61
if ( V_111 -> V_122 & V_123 ) {
V_119 . V_124 = V_121 . V_124 ;
V_119 . V_125 = V_121 . V_125 ;
V_32 = & V_119 ;
V_13 = sizeof( V_119 ) ;
}
#endif
F_60 ( V_111 , V_116 , V_117 , V_13 , V_32 ) ;
}
}
static int F_63 ( struct V_126 * V_127 , struct V_41 * V_8 ,
struct V_110 * V_111 , T_3 V_13 , int V_71 )
{
int V_128 = V_71 & V_129 ;
struct V_8 * V_10 = V_8 -> V_10 ;
struct V_6 * V_7 ;
int V_130 , V_79 ;
F_3 ( L_4 , V_8 , V_10 ) ;
if ( V_71 & ( V_131 ) )
return - V_132 ;
if ( V_10 -> V_19 == V_133 )
return 0 ;
V_7 = F_64 ( V_10 , V_71 , V_128 , & V_79 ) ;
if ( ! V_7 )
return V_79 ;
V_111 -> V_134 = 0 ;
V_130 = V_7 -> V_13 ;
if ( V_13 < V_130 ) {
V_111 -> V_122 |= V_135 ;
V_130 = V_13 ;
}
F_65 ( V_7 ) ;
V_79 = F_66 ( V_7 , 0 , V_111 -> V_136 , V_130 ) ;
F_59 ( V_10 , V_111 , V_7 ) ;
F_67 ( V_10 , V_7 ) ;
return V_79 ? : V_130 ;
}
static int F_68 ( struct V_126 * V_127 , struct V_41 * V_8 ,
struct V_110 * V_111 , T_3 V_13 )
{
struct V_8 * V_10 = V_8 -> V_10 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_79 ;
F_3 ( L_2 , V_8 , V_10 ) ;
if ( V_111 -> V_122 & V_131 )
return - V_132 ;
if ( V_111 -> V_122 & ~ ( V_129 | V_137 | V_138 ) )
return - V_77 ;
if ( V_13 < 4 || V_13 > V_139 )
return - V_77 ;
F_52 ( V_10 ) ;
switch ( F_6 ( V_10 ) -> V_21 ) {
case V_40 :
break;
case V_22 :
V_79 = F_69 ( V_10 , V_111 , V_13 ) ;
goto V_105;
default:
V_79 = - V_77 ;
goto V_105;
}
V_5 = F_6 ( V_10 ) -> V_5 ;
if ( ! V_5 ) {
V_79 = - V_63 ;
goto V_105;
}
if ( ! F_8 ( V_140 , & V_5 -> V_71 ) ) {
V_79 = - V_141 ;
goto V_105;
}
V_7 = F_70 ( V_10 , V_13 , V_111 -> V_122 & V_129 , & V_79 ) ;
if ( ! V_7 )
goto V_105;
if ( F_71 ( F_72 ( V_7 , V_13 ) , V_111 -> V_136 , V_13 ) ) {
V_79 = - V_53 ;
goto V_142;
}
F_7 ( V_7 ) -> V_25 = * ( ( unsigned char * ) V_7 -> V_32 ) ;
F_73 ( V_7 , 1 ) ;
V_7 -> V_143 = ( void * ) V_5 ;
if ( F_7 ( V_7 ) -> V_25 == V_144 ) {
T_4 V_35 = F_74 ( V_7 -> V_32 ) ;
T_4 V_145 = F_75 ( V_35 ) ;
T_4 V_146 = F_76 ( V_35 ) ;
if ( ( ( V_145 > V_147 ) ||
! F_1 ( V_146 & V_148 , & V_149 . V_150 [ V_145 ] ) ) &&
! F_37 ( V_151 ) ) {
V_79 = - V_69 ;
goto V_142;
}
if ( F_8 ( V_70 , & V_5 -> V_71 ) || ( V_145 == 0x3f ) ) {
F_77 ( & V_5 -> V_152 , V_7 ) ;
F_78 ( & V_5 -> V_153 ) ;
} else {
F_77 ( & V_5 -> V_154 , V_7 ) ;
F_78 ( & V_5 -> V_155 ) ;
}
} else {
if ( ! F_37 ( V_151 ) ) {
V_79 = - V_69 ;
goto V_142;
}
F_77 ( & V_5 -> V_152 , V_7 ) ;
F_78 ( & V_5 -> V_153 ) ;
}
V_79 = V_13 ;
V_105:
F_53 ( V_10 ) ;
return V_79 ;
V_142:
F_13 ( V_7 ) ;
goto V_105;
}
static int F_79 ( struct V_41 * V_8 , int V_156 , int V_157 , char T_2 * V_158 , unsigned int V_13 )
{
struct V_159 V_160 = { . V_35 = 0 } ;
struct V_8 * V_10 = V_8 -> V_10 ;
int V_79 = 0 , V_161 = 0 ;
F_3 ( L_5 , V_10 , V_157 ) ;
F_52 ( V_10 ) ;
switch ( V_157 ) {
case V_162 :
if ( F_80 ( V_161 , ( int T_2 * ) V_158 ) ) {
V_79 = - V_53 ;
break;
}
if ( V_161 )
F_6 ( V_10 ) -> V_113 |= V_114 ;
else
F_6 ( V_10 ) -> V_113 &= ~ V_114 ;
break;
case V_163 :
if ( F_80 ( V_161 , ( int T_2 * ) V_158 ) ) {
V_79 = - V_53 ;
break;
}
if ( V_161 )
F_6 ( V_10 ) -> V_113 |= V_117 ;
else
F_6 ( V_10 ) -> V_113 &= ~ V_117 ;
break;
case V_164 :
{
struct V_16 * V_165 = & F_6 ( V_10 ) -> V_24 ;
V_160 . V_28 = V_165 -> V_28 ;
V_160 . V_35 = V_165 -> V_35 ;
V_160 . V_34 [ 0 ] = * ( ( V_166 * ) V_165 -> V_34 + 0 ) ;
V_160 . V_34 [ 1 ] = * ( ( V_166 * ) V_165 -> V_34 + 1 ) ;
}
V_13 = F_55 (unsigned int, len, sizeof(uf)) ;
if ( F_27 ( & V_160 , V_158 , V_13 ) ) {
V_79 = - V_53 ;
break;
}
if ( ! F_37 ( V_151 ) ) {
V_160 . V_28 &= V_149 . V_28 ;
V_160 . V_34 [ 0 ] &= * ( ( V_166 * ) V_149 . V_34 + 0 ) ;
V_160 . V_34 [ 1 ] &= * ( ( V_166 * ) V_149 . V_34 + 1 ) ;
}
{
struct V_16 * V_165 = & F_6 ( V_10 ) -> V_24 ;
V_165 -> V_28 = V_160 . V_28 ;
V_165 -> V_35 = V_160 . V_35 ;
* ( ( V_166 * ) V_165 -> V_34 + 0 ) = V_160 . V_34 [ 0 ] ;
* ( ( V_166 * ) V_165 -> V_34 + 1 ) = V_160 . V_34 [ 1 ] ;
}
break;
default:
V_79 = - V_167 ;
break;
}
F_53 ( V_10 ) ;
return V_79 ;
}
static int F_81 ( struct V_41 * V_8 , int V_156 , int V_157 , char T_2 * V_158 , int T_2 * V_168 )
{
struct V_159 V_160 ;
struct V_8 * V_10 = V_8 -> V_10 ;
int V_13 , V_161 ;
if ( F_80 ( V_13 , V_168 ) )
return - V_53 ;
switch ( V_157 ) {
case V_162 :
if ( F_6 ( V_10 ) -> V_113 & V_114 )
V_161 = 1 ;
else
V_161 = 0 ;
if ( F_82 ( V_161 , V_158 ) )
return - V_53 ;
break;
case V_163 :
if ( F_6 ( V_10 ) -> V_113 & V_117 )
V_161 = 1 ;
else
V_161 = 0 ;
if ( F_82 ( V_161 , V_158 ) )
return - V_53 ;
break;
case V_164 :
{
struct V_16 * V_165 = & F_6 ( V_10 ) -> V_24 ;
V_160 . V_28 = V_165 -> V_28 ;
V_160 . V_35 = V_165 -> V_35 ;
V_160 . V_34 [ 0 ] = * ( ( V_166 * ) V_165 -> V_34 + 0 ) ;
V_160 . V_34 [ 1 ] = * ( ( V_166 * ) V_165 -> V_34 + 1 ) ;
}
V_13 = F_55 (unsigned int, len, sizeof(uf)) ;
if ( F_83 ( V_158 , & V_160 , V_13 ) )
return - V_53 ;
break;
default:
return - V_167 ;
break;
}
return 0 ;
}
static int F_84 ( struct V_169 * V_169 , struct V_41 * V_8 , int V_170 ,
int V_171 )
{
struct V_8 * V_10 ;
F_3 ( L_6 , V_8 ) ;
if ( V_8 -> type != V_172 )
return - V_173 ;
V_8 -> V_174 = & V_175 ;
V_10 = F_85 ( V_169 , V_176 , V_39 , & V_177 ) ;
if ( ! V_10 )
return - V_58 ;
F_86 ( V_8 , V_10 ) ;
F_87 ( V_10 , V_178 ) ;
V_10 -> V_179 = V_170 ;
V_8 -> V_180 = V_181 ;
V_10 -> V_19 = V_182 ;
F_88 ( & V_14 , V_10 ) ;
return 0 ;
}
static int F_89 ( struct V_183 * V_184 , unsigned long V_185 , void * V_186 )
{
struct V_4 * V_5 = (struct V_4 * ) V_186 ;
struct V_187 V_188 ;
F_3 ( L_7 , V_5 -> V_189 , V_185 ) ;
V_188 . V_185 = V_185 ;
V_188 . V_190 = V_5 -> V_109 ;
F_90 ( NULL , V_191 , sizeof( V_188 ) , & V_188 ) ;
if ( V_185 == V_192 ) {
struct V_8 * V_10 ;
struct V_11 * V_12 ;
F_4 ( & V_14 . V_15 ) ;
F_5 (sk, node, &hci_sk_list.head) {
F_91 () ;
F_92 ( V_10 ) ;
if ( F_6 ( V_10 ) -> V_5 == V_5 ) {
F_6 ( V_10 ) -> V_5 = NULL ;
V_10 -> V_193 = V_194 ;
V_10 -> V_19 = V_182 ;
V_10 -> V_195 ( V_10 ) ;
F_18 ( V_5 ) ;
}
F_93 ( V_10 ) ;
F_94 () ;
}
F_14 ( & V_14 . V_15 ) ;
}
return V_196 ;
}
int T_5 F_95 ( void )
{
int V_79 ;
V_79 = F_96 ( & V_177 , 0 ) ;
if ( V_79 < 0 )
return V_79 ;
V_79 = F_97 ( V_197 , & V_198 ) ;
if ( V_79 < 0 )
goto error;
F_98 ( & V_199 ) ;
F_99 ( L_8 ) ;
return 0 ;
error:
F_100 ( L_9 ) ;
F_101 ( & V_177 ) ;
return V_79 ;
}
void F_102 ( void )
{
if ( F_103 ( V_197 ) < 0 )
F_100 ( L_10 ) ;
F_104 ( & V_199 ) ;
F_101 ( & V_177 ) ;
}
