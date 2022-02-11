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
static int F_22 ( struct V_4 * V_5 , void T_1 * V_45 )
{
T_2 V_46 ;
int V_47 ;
if ( F_23 ( & V_46 , V_45 , sizeof( V_46 ) ) )
return - V_48 ;
F_24 ( V_5 ) ;
V_47 = F_25 ( V_5 , & V_46 ) ;
F_26 ( V_5 ) ;
return V_47 ;
}
static int F_27 ( struct V_4 * V_5 , void T_1 * V_45 )
{
T_2 V_46 ;
int V_47 ;
if ( F_23 ( & V_46 , V_45 , sizeof( V_46 ) ) )
return - V_48 ;
F_24 ( V_5 ) ;
V_47 = F_28 ( V_5 , & V_46 ) ;
F_26 ( V_5 ) ;
return V_47 ;
}
static inline int F_29 ( struct V_8 * V_10 , unsigned int V_49 , unsigned long V_45 )
{
struct V_4 * V_5 = F_6 ( V_10 ) -> V_5 ;
if ( ! V_5 )
return - V_50 ;
switch ( V_49 ) {
case V_51 :
if ( ! F_30 ( V_52 ) )
return - V_53 ;
if ( F_8 ( V_54 , & V_5 -> V_55 ) )
return - V_56 ;
if ( V_45 )
F_31 ( V_57 , & V_5 -> V_58 ) ;
else
F_32 ( V_57 , & V_5 -> V_58 ) ;
return 0 ;
case V_59 :
return F_33 ( V_5 , ( void T_1 * ) V_45 ) ;
case V_60 :
return F_34 ( V_5 , ( void T_1 * ) V_45 ) ;
case V_61 :
if ( ! F_30 ( V_52 ) )
return - V_53 ;
return F_22 ( V_5 , ( void T_1 * ) V_45 ) ;
case V_62 :
if ( ! F_30 ( V_52 ) )
return - V_53 ;
return F_27 ( V_5 , ( void T_1 * ) V_45 ) ;
default:
if ( V_5 -> V_63 )
return V_5 -> V_63 ( V_5 , V_49 , V_45 ) ;
return - V_64 ;
}
}
static int F_35 ( struct V_41 * V_8 , unsigned int V_49 , unsigned long V_45 )
{
struct V_8 * V_10 = V_8 -> V_10 ;
void T_1 * V_65 = ( void T_1 * ) V_45 ;
int V_47 ;
F_3 ( L_3 , V_49 , V_45 ) ;
switch ( V_49 ) {
case V_66 :
return F_36 ( V_65 ) ;
case V_67 :
return F_37 ( V_65 ) ;
case V_68 :
return F_38 ( V_65 ) ;
case V_69 :
if ( ! F_30 ( V_52 ) )
return - V_53 ;
return F_39 ( V_45 ) ;
case V_70 :
if ( ! F_30 ( V_52 ) )
return - V_53 ;
return F_40 ( V_45 ) ;
case V_71 :
if ( ! F_30 ( V_52 ) )
return - V_53 ;
return F_41 ( V_45 ) ;
case V_72 :
if ( ! F_30 ( V_52 ) )
return - V_53 ;
return F_42 ( V_45 ) ;
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
if ( ! F_30 ( V_52 ) )
return - V_53 ;
return F_43 ( V_49 , V_65 ) ;
case V_81 :
return F_44 ( V_65 ) ;
default:
F_45 ( V_10 ) ;
V_47 = F_29 ( V_10 , V_49 , V_45 ) ;
F_46 ( V_10 ) ;
return V_47 ;
}
}
static int F_47 ( struct V_41 * V_8 , struct V_82 * V_2 , int V_83 )
{
struct V_84 V_85 ;
struct V_8 * V_10 = V_8 -> V_10 ;
struct V_4 * V_5 = NULL ;
int V_13 , V_47 = 0 ;
F_3 ( L_2 , V_8 , V_10 ) ;
if ( ! V_2 )
return - V_64 ;
memset ( & V_85 , 0 , sizeof( V_85 ) ) ;
V_13 = F_48 (unsigned int, sizeof(haddr), addr_len) ;
memcpy ( & V_85 , V_2 , V_13 ) ;
if ( V_85 . V_86 != V_87 )
return - V_64 ;
if ( V_85 . V_88 > V_22 )
return - V_64 ;
if ( V_85 . V_88 == V_22 && ! V_89 )
return - V_64 ;
F_45 ( V_10 ) ;
if ( V_10 -> V_19 == V_20 || F_6 ( V_10 ) -> V_5 ) {
V_47 = - V_90 ;
goto V_91;
}
if ( V_85 . V_4 != V_92 ) {
V_5 = F_49 ( V_85 . V_4 ) ;
if ( ! V_5 ) {
V_47 = - V_93 ;
goto V_91;
}
F_50 ( & V_5 -> V_42 ) ;
}
F_6 ( V_10 ) -> V_21 = V_85 . V_88 ;
F_6 ( V_10 ) -> V_5 = V_5 ;
V_10 -> V_19 = V_20 ;
V_91:
F_46 ( V_10 ) ;
return V_47 ;
}
static int F_51 ( struct V_41 * V_8 , struct V_82 * V_2 , int * V_83 , int V_94 )
{
struct V_84 * V_85 = (struct V_84 * ) V_2 ;
struct V_8 * V_10 = V_8 -> V_10 ;
struct V_4 * V_5 = F_6 ( V_10 ) -> V_5 ;
F_3 ( L_2 , V_8 , V_10 ) ;
if ( ! V_5 )
return - V_50 ;
F_45 ( V_10 ) ;
* V_83 = sizeof( * V_85 ) ;
V_85 -> V_86 = V_87 ;
V_85 -> V_4 = V_5 -> V_95 ;
F_46 ( V_10 ) ;
return 0 ;
}
static inline void F_52 ( struct V_8 * V_10 , struct V_96 * V_97 , struct V_6 * V_7 )
{
V_3 V_98 = F_6 ( V_10 ) -> V_99 ;
if ( V_98 & V_100 ) {
int V_101 = F_7 ( V_7 ) -> V_101 ;
F_53 ( V_97 , V_102 , V_100 , sizeof( V_101 ) , & V_101 ) ;
}
if ( V_98 & V_103 ) {
#ifdef F_54
struct V_104 V_105 ;
#endif
struct V_106 V_107 ;
void * V_32 ;
int V_13 ;
F_55 ( V_7 , & V_107 ) ;
V_32 = & V_107 ;
V_13 = sizeof( V_107 ) ;
#ifdef F_54
if ( V_97 -> V_108 & V_109 ) {
V_105 . V_110 = V_107 . V_110 ;
V_105 . V_111 = V_107 . V_111 ;
V_32 = & V_105 ;
V_13 = sizeof( V_105 ) ;
}
#endif
F_53 ( V_97 , V_102 , V_103 , V_13 , V_32 ) ;
}
}
static int F_56 ( struct V_112 * V_113 , struct V_41 * V_8 ,
struct V_96 * V_97 , T_3 V_13 , int V_58 )
{
int V_114 = V_58 & V_115 ;
struct V_8 * V_10 = V_8 -> V_10 ;
struct V_6 * V_7 ;
int V_116 , V_47 ;
F_3 ( L_4 , V_8 , V_10 ) ;
if ( V_58 & ( V_117 ) )
return - V_118 ;
if ( V_10 -> V_19 == V_119 )
return 0 ;
V_7 = F_57 ( V_10 , V_58 , V_114 , & V_47 ) ;
if ( ! V_7 )
return V_47 ;
V_97 -> V_120 = 0 ;
V_116 = V_7 -> V_13 ;
if ( V_13 < V_116 ) {
V_97 -> V_108 |= V_121 ;
V_116 = V_13 ;
}
F_58 ( V_7 ) ;
V_47 = F_59 ( V_7 , 0 , V_97 -> V_122 , V_116 ) ;
F_52 ( V_10 , V_97 , V_7 ) ;
F_60 ( V_10 , V_7 ) ;
return V_47 ? : V_116 ;
}
static int F_61 ( struct V_112 * V_113 , struct V_41 * V_8 ,
struct V_96 * V_97 , T_3 V_13 )
{
struct V_8 * V_10 = V_8 -> V_10 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_47 ;
F_3 ( L_2 , V_8 , V_10 ) ;
if ( V_97 -> V_108 & V_117 )
return - V_118 ;
if ( V_97 -> V_108 & ~ ( V_115 | V_123 | V_124 ) )
return - V_64 ;
if ( V_13 < 4 || V_13 > V_125 )
return - V_64 ;
F_45 ( V_10 ) ;
switch ( F_6 ( V_10 ) -> V_21 ) {
case V_40 :
break;
case V_22 :
V_47 = F_62 ( V_10 , V_97 , V_13 ) ;
goto V_91;
default:
V_47 = - V_64 ;
goto V_91;
}
V_5 = F_6 ( V_10 ) -> V_5 ;
if ( ! V_5 ) {
V_47 = - V_50 ;
goto V_91;
}
if ( ! F_8 ( V_126 , & V_5 -> V_58 ) ) {
V_47 = - V_127 ;
goto V_91;
}
V_7 = F_63 ( V_10 , V_13 , V_97 -> V_108 & V_115 , & V_47 ) ;
if ( ! V_7 )
goto V_91;
if ( F_64 ( F_65 ( V_7 , V_13 ) , V_97 -> V_122 , V_13 ) ) {
V_47 = - V_48 ;
goto V_128;
}
F_7 ( V_7 ) -> V_25 = * ( ( unsigned char * ) V_7 -> V_32 ) ;
F_66 ( V_7 , 1 ) ;
V_7 -> V_129 = ( void * ) V_5 ;
if ( F_7 ( V_7 ) -> V_25 == V_130 ) {
T_4 V_35 = F_67 ( V_7 -> V_32 ) ;
T_4 V_131 = F_68 ( V_35 ) ;
T_4 V_132 = F_69 ( V_35 ) ;
if ( ( ( V_131 > V_133 ) ||
! F_1 ( V_132 & V_134 , & V_135 . V_136 [ V_131 ] ) ) &&
! F_30 ( V_137 ) ) {
V_47 = - V_56 ;
goto V_128;
}
if ( F_8 ( V_57 , & V_5 -> V_58 ) || ( V_131 == 0x3f ) ) {
F_70 ( & V_5 -> V_138 , V_7 ) ;
F_71 ( & V_5 -> V_139 ) ;
} else {
F_70 ( & V_5 -> V_140 , V_7 ) ;
F_71 ( & V_5 -> V_141 ) ;
}
} else {
if ( ! F_30 ( V_137 ) ) {
V_47 = - V_56 ;
goto V_128;
}
F_70 ( & V_5 -> V_138 , V_7 ) ;
F_71 ( & V_5 -> V_139 ) ;
}
V_47 = V_13 ;
V_91:
F_46 ( V_10 ) ;
return V_47 ;
V_128:
F_13 ( V_7 ) ;
goto V_91;
}
static int F_72 ( struct V_41 * V_8 , int V_142 , int V_143 , char T_1 * V_144 , unsigned int V_13 )
{
struct V_145 V_146 = { . V_35 = 0 } ;
struct V_8 * V_10 = V_8 -> V_10 ;
int V_47 = 0 , V_147 = 0 ;
F_3 ( L_5 , V_10 , V_143 ) ;
F_45 ( V_10 ) ;
switch ( V_143 ) {
case V_148 :
if ( F_73 ( V_147 , ( int T_1 * ) V_144 ) ) {
V_47 = - V_48 ;
break;
}
if ( V_147 )
F_6 ( V_10 ) -> V_99 |= V_100 ;
else
F_6 ( V_10 ) -> V_99 &= ~ V_100 ;
break;
case V_149 :
if ( F_73 ( V_147 , ( int T_1 * ) V_144 ) ) {
V_47 = - V_48 ;
break;
}
if ( V_147 )
F_6 ( V_10 ) -> V_99 |= V_103 ;
else
F_6 ( V_10 ) -> V_99 &= ~ V_103 ;
break;
case V_150 :
{
struct V_16 * V_151 = & F_6 ( V_10 ) -> V_24 ;
V_146 . V_28 = V_151 -> V_28 ;
V_146 . V_35 = V_151 -> V_35 ;
V_146 . V_34 [ 0 ] = * ( ( V_152 * ) V_151 -> V_34 + 0 ) ;
V_146 . V_34 [ 1 ] = * ( ( V_152 * ) V_151 -> V_34 + 1 ) ;
}
V_13 = F_48 (unsigned int, len, sizeof(uf)) ;
if ( F_23 ( & V_146 , V_144 , V_13 ) ) {
V_47 = - V_48 ;
break;
}
if ( ! F_30 ( V_137 ) ) {
V_146 . V_28 &= V_135 . V_28 ;
V_146 . V_34 [ 0 ] &= * ( ( V_152 * ) V_135 . V_34 + 0 ) ;
V_146 . V_34 [ 1 ] &= * ( ( V_152 * ) V_135 . V_34 + 1 ) ;
}
{
struct V_16 * V_151 = & F_6 ( V_10 ) -> V_24 ;
V_151 -> V_28 = V_146 . V_28 ;
V_151 -> V_35 = V_146 . V_35 ;
* ( ( V_152 * ) V_151 -> V_34 + 0 ) = V_146 . V_34 [ 0 ] ;
* ( ( V_152 * ) V_151 -> V_34 + 1 ) = V_146 . V_34 [ 1 ] ;
}
break;
default:
V_47 = - V_153 ;
break;
}
F_46 ( V_10 ) ;
return V_47 ;
}
static int F_74 ( struct V_41 * V_8 , int V_142 , int V_143 , char T_1 * V_144 , int T_1 * V_154 )
{
struct V_145 V_146 ;
struct V_8 * V_10 = V_8 -> V_10 ;
int V_13 , V_147 ;
if ( F_73 ( V_13 , V_154 ) )
return - V_48 ;
switch ( V_143 ) {
case V_148 :
if ( F_6 ( V_10 ) -> V_99 & V_100 )
V_147 = 1 ;
else
V_147 = 0 ;
if ( F_75 ( V_147 , V_144 ) )
return - V_48 ;
break;
case V_149 :
if ( F_6 ( V_10 ) -> V_99 & V_103 )
V_147 = 1 ;
else
V_147 = 0 ;
if ( F_75 ( V_147 , V_144 ) )
return - V_48 ;
break;
case V_150 :
{
struct V_16 * V_151 = & F_6 ( V_10 ) -> V_24 ;
V_146 . V_28 = V_151 -> V_28 ;
V_146 . V_35 = V_151 -> V_35 ;
V_146 . V_34 [ 0 ] = * ( ( V_152 * ) V_151 -> V_34 + 0 ) ;
V_146 . V_34 [ 1 ] = * ( ( V_152 * ) V_151 -> V_34 + 1 ) ;
}
V_13 = F_48 (unsigned int, len, sizeof(uf)) ;
if ( F_76 ( V_144 , & V_146 , V_13 ) )
return - V_48 ;
break;
default:
return - V_153 ;
break;
}
return 0 ;
}
static int F_77 ( struct V_155 * V_155 , struct V_41 * V_8 , int V_156 ,
int V_157 )
{
struct V_8 * V_10 ;
F_3 ( L_6 , V_8 ) ;
if ( V_8 -> type != V_158 )
return - V_159 ;
V_8 -> V_160 = & V_161 ;
V_10 = F_78 ( V_155 , V_162 , V_39 , & V_163 ) ;
if ( ! V_10 )
return - V_164 ;
F_79 ( V_8 , V_10 ) ;
F_80 ( V_10 , V_165 ) ;
V_10 -> V_166 = V_156 ;
V_8 -> V_167 = V_168 ;
V_10 -> V_19 = V_169 ;
F_81 ( & V_14 , V_10 ) ;
return 0 ;
}
static int F_82 ( struct V_170 * V_171 , unsigned long V_172 , void * V_173 )
{
struct V_4 * V_5 = (struct V_4 * ) V_173 ;
struct V_174 V_175 ;
F_3 ( L_7 , V_5 -> V_176 , V_172 ) ;
V_175 . V_172 = V_172 ;
V_175 . V_177 = V_5 -> V_95 ;
F_83 ( NULL , V_178 , sizeof( V_175 ) , & V_175 ) ;
if ( V_172 == V_179 ) {
struct V_8 * V_10 ;
struct V_11 * V_12 ;
F_4 ( & V_14 . V_15 ) ;
F_5 (sk, node, &hci_sk_list.head) {
F_84 () ;
F_85 ( V_10 ) ;
if ( F_6 ( V_10 ) -> V_5 == V_5 ) {
F_6 ( V_10 ) -> V_5 = NULL ;
V_10 -> V_180 = V_181 ;
V_10 -> V_19 = V_169 ;
V_10 -> V_182 ( V_10 ) ;
F_18 ( V_5 ) ;
}
F_86 ( V_10 ) ;
F_87 () ;
}
F_14 ( & V_14 . V_15 ) ;
}
return V_183 ;
}
int T_5 F_88 ( void )
{
int V_47 ;
V_47 = F_89 ( & V_163 , 0 ) ;
if ( V_47 < 0 )
return V_47 ;
V_47 = F_90 ( V_184 , & V_185 ) ;
if ( V_47 < 0 )
goto error;
F_91 ( & V_186 ) ;
F_92 ( L_8 ) ;
return 0 ;
error:
F_93 ( L_9 ) ;
F_94 ( & V_163 ) ;
return V_47 ;
}
void F_95 ( void )
{
if ( F_96 ( V_184 ) < 0 )
F_93 ( L_10 ) ;
F_97 ( & V_186 ) ;
F_94 ( & V_163 ) ;
}
