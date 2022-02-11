int F_1 ( struct V_1 * V_2 )
{
return ! ( V_2 -> V_3 . V_4 -> V_5 & V_6 ) ||
! ! ( V_2 -> V_3 . V_7 ) ;
}
int F_2 ( struct V_1 * V_8 )
{
int V_9 = F_3 ( V_8 , 11 ) ;
int V_10 ;
unsigned long T_1 V_11 = F_3 ( V_8 , 3 ) ;
unsigned long T_1 V_12 = F_3 ( V_8 , 4 ) ;
unsigned long T_1 V_13 = F_3 ( V_8 , 5 ) ;
unsigned long T_1 V_14 = F_3 ( V_8 , 6 ) ;
unsigned long V_15 = 0 ;
if ( ! ( V_8 -> V_3 . V_4 -> V_5 & V_16 ) ) {
V_11 &= 0xffffffff ;
V_12 &= 0xffffffff ;
V_13 &= 0xffffffff ;
V_14 &= 0xffffffff ;
}
switch ( V_9 ) {
case V_17 | V_18 :
{
V_8 -> V_3 . V_19 = V_11 ;
V_8 -> V_3 . V_20 = V_12 ;
V_15 = V_21 ;
V_10 = V_22 ;
break;
}
case V_17 | V_23 :
V_10 = V_22 ;
#if F_4 ( V_24 ) || F_4 ( V_25 )
V_15 |= ( 1 << V_26 ) ;
#endif
break;
default:
V_10 = V_27 ;
break;
}
F_5 ( V_8 , 4 , V_15 ) ;
return V_10 ;
}
int F_6 ( struct V_1 * V_8 )
{
int V_10 = false ;
if ( ! V_8 -> V_3 . V_28 )
goto V_29;
if ( ( V_8 -> V_3 . V_30 != V_31 ) && V_8 -> V_3 . V_32 )
goto V_29;
#ifdef F_7
if ( ! V_8 -> V_3 . V_32 )
goto V_29;
#endif
V_10 = true ;
V_29:
V_8 -> V_3 . V_33 = V_10 ;
return V_10 ? 0 : - V_34 ;
}
int F_8 ( struct V_35 * V_36 , struct V_1 * V_8 )
{
enum V_37 V_38 ;
int V_10 ;
V_38 = F_9 ( V_36 , V_8 ) ;
switch ( V_38 ) {
case V_39 :
V_10 = V_40 ;
break;
case V_41 :
V_36 -> V_42 = V_43 ;
V_10 = V_44 ;
break;
case V_45 :
F_10 ( V_46 L_1 , V_47 ,
F_11 ( V_8 ) ) ;
V_10 = V_48 ;
break;
default:
F_12 () ;
}
return V_10 ;
}
int F_13 ( void * V_49 )
{
return 0 ;
}
void F_14 ( void * V_49 )
{
}
int F_15 ( void )
{
return 0 ;
}
void F_16 ( void )
{
}
void F_17 ( void * V_50 )
{
* ( int * ) V_50 = F_18 () ;
}
int F_19 ( struct V_51 * V_51 )
{
return F_20 ( V_51 ) ;
}
void F_21 ( struct V_51 * V_51 )
{
unsigned int V_52 ;
struct V_1 * V_8 ;
F_22 (i, vcpu, kvm)
F_23 ( V_8 ) ;
F_24 ( & V_51 -> V_53 ) ;
for ( V_52 = 0 ; V_52 < F_25 ( & V_51 -> V_54 ) ; V_52 ++ )
V_51 -> V_55 [ V_52 ] = NULL ;
F_26 ( & V_51 -> V_54 , 0 ) ;
F_27 ( V_51 ) ;
F_28 ( & V_51 -> V_53 ) ;
}
void F_29 ( struct V_51 * V_51 )
{
}
int F_30 ( long V_56 )
{
int V_10 ;
switch ( V_56 ) {
#ifdef F_31
case V_57 :
#else
case V_58 :
case V_59 :
#endif
case V_60 :
case V_61 :
case V_62 :
V_10 = 1 ;
break;
#ifndef F_7
case V_63 :
case V_64 :
case V_65 :
V_10 = 1 ;
break;
case V_66 :
V_10 = V_67 ;
break;
#endif
#ifdef F_7
case V_68 :
V_10 = 1 ;
break;
case V_69 :
V_10 = V_70 ;
break;
case V_71 :
V_10 = 1 ;
if ( F_32 ( V_72 ) )
V_10 = 2 ;
break;
#endif
default:
V_10 = 0 ;
break;
}
return V_10 ;
}
long F_33 ( struct V_73 * V_74 ,
unsigned int V_75 , unsigned long V_76 )
{
return - V_34 ;
}
int F_34 ( struct V_51 * V_51 ,
struct V_77 * V_78 ,
struct V_77 V_79 ,
struct V_80 * V_81 ,
int V_82 )
{
return F_35 ( V_51 , V_81 ) ;
}
void F_36 ( struct V_51 * V_51 ,
struct V_80 * V_81 ,
struct V_77 V_79 ,
int V_82 )
{
F_37 ( V_51 , V_81 ) ;
}
void F_38 ( struct V_51 * V_51 )
{
}
struct V_1 * F_39 ( struct V_51 * V_51 , unsigned int V_83 )
{
struct V_1 * V_8 ;
V_8 = F_40 ( V_51 , V_83 ) ;
V_8 -> V_3 . V_84 = & V_8 -> V_85 ;
if ( ! F_41 ( V_8 ) )
F_42 ( V_8 , V_83 ) ;
return V_8 ;
}
void F_23 ( struct V_1 * V_8 )
{
F_43 ( & V_8 -> V_3 . V_86 ) ;
F_44 ( & V_8 -> V_3 . V_87 ) ;
F_45 ( V_8 ) ;
F_46 ( V_8 ) ;
}
void F_47 ( struct V_1 * V_8 )
{
F_23 ( V_8 ) ;
}
int F_48 ( struct V_1 * V_8 )
{
return F_49 ( V_8 ) ;
}
static void F_50 ( unsigned long V_88 )
{
struct V_1 * V_8 = (struct V_1 * ) V_88 ;
F_51 ( V_8 ) ;
if ( F_52 ( V_8 -> V_3 . V_84 ) ) {
F_53 ( V_8 -> V_3 . V_84 ) ;
V_8 -> V_89 . V_90 ++ ;
}
}
enum V_91 F_54 ( struct V_92 * V_93 )
{
struct V_1 * V_8 ;
V_8 = F_55 ( V_93 , struct V_1 , V_3 . V_86 ) ;
F_56 ( & V_8 -> V_3 . V_87 ) ;
return V_94 ;
}
int F_57 ( struct V_1 * V_8 )
{
F_58 ( & V_8 -> V_3 . V_86 , V_95 , V_96 ) ;
F_59 ( & V_8 -> V_3 . V_87 , F_50 , ( V_97 ) V_8 ) ;
V_8 -> V_3 . V_86 . V_98 = F_54 ;
V_8 -> V_3 . V_99 = ~ ( V_100 ) 0 ;
#ifdef F_60
F_61 ( & V_8 -> V_3 . V_101 ) ;
#endif
return 0 ;
}
void F_62 ( struct V_1 * V_8 )
{
F_63 ( V_8 ) ;
}
void F_64 ( struct V_1 * V_8 , int V_102 )
{
#ifdef F_31
F_65 ( V_103 , V_8 -> V_3 . V_104 ) ;
#endif
F_66 ( V_8 , V_102 ) ;
V_8 -> V_102 = F_67 () ;
}
void F_68 ( struct V_1 * V_8 )
{
F_69 ( V_8 ) ;
#ifdef F_31
V_8 -> V_3 . V_104 = F_70 ( V_103 ) ;
#endif
V_8 -> V_102 = - 1 ;
}
int F_71 ( struct V_1 * V_8 ,
struct V_105 * V_106 )
{
return - V_34 ;
}
static void F_72 ( struct V_1 * V_8 ,
struct V_35 * V_36 )
{
F_5 ( V_8 , V_8 -> V_3 . V_107 , V_36 -> V_108 . V_88 ) ;
}
static void F_73 ( struct V_1 * V_8 ,
struct V_35 * V_36 )
{
V_100 V_109 ( V_110 ) ;
if ( V_36 -> V_111 . V_112 > sizeof( V_110 ) ) {
F_10 ( V_113 L_2 , V_36 -> V_111 . V_112 ) ;
return;
}
if ( V_8 -> V_3 . V_114 ) {
switch ( V_36 -> V_111 . V_112 ) {
case 8 : V_110 = * ( V_100 * ) V_36 -> V_111 . V_88 ; break;
case 4 : V_110 = * ( V_115 * ) V_36 -> V_111 . V_88 ; break;
case 2 : V_110 = * ( V_116 * ) V_36 -> V_111 . V_88 ; break;
case 1 : V_110 = * ( V_117 * ) V_36 -> V_111 . V_88 ; break;
}
} else {
switch ( V_36 -> V_111 . V_112 ) {
case 4 : V_110 = F_74 ( ( V_115 * ) V_36 -> V_111 . V_88 ) ; break;
case 2 : V_110 = F_75 ( ( V_116 * ) V_36 -> V_111 . V_88 ) ; break;
case 1 : V_110 = * ( V_117 * ) V_36 -> V_111 . V_88 ; break;
}
}
if ( V_8 -> V_3 . V_118 ) {
switch ( V_36 -> V_111 . V_112 ) {
#ifdef F_76
case 4 :
V_110 = ( V_119 ) ( V_120 ) V_110 ;
break;
#endif
case 2 :
V_110 = ( V_119 ) ( V_121 ) V_110 ;
break;
case 1 :
V_110 = ( V_119 ) ( V_122 ) V_110 ;
break;
}
}
F_5 ( V_8 , V_8 -> V_3 . V_107 , V_110 ) ;
switch ( V_8 -> V_3 . V_107 & V_123 ) {
case V_124 :
F_5 ( V_8 , V_8 -> V_3 . V_107 , V_110 ) ;
break;
case V_125 :
V_8 -> V_3 . V_126 [ V_8 -> V_3 . V_107 & V_127 ] = V_110 ;
break;
#ifdef V_24
case V_128 :
V_8 -> V_3 . V_129 [ V_8 -> V_3 . V_107 & V_127 ] = V_110 ;
break;
case V_130 :
V_8 -> V_3 . V_126 [ V_8 -> V_3 . V_107 & V_127 ] = V_110 ;
V_8 -> V_3 . V_129 [ V_8 -> V_3 . V_107 & V_127 ] = V_110 ;
break;
#endif
default:
F_12 () ;
}
}
int F_77 ( struct V_35 * V_36 , struct V_1 * V_8 ,
unsigned int V_131 , unsigned int V_132 , int V_133 )
{
if ( V_132 > sizeof( V_36 -> V_111 . V_88 ) ) {
F_10 ( V_113 L_3 , V_47 ,
V_36 -> V_111 . V_112 ) ;
}
V_36 -> V_111 . V_134 = V_8 -> V_3 . V_135 ;
V_36 -> V_111 . V_112 = V_132 ;
V_36 -> V_111 . V_136 = 0 ;
V_8 -> V_3 . V_107 = V_131 ;
V_8 -> V_3 . V_114 = V_133 ;
V_8 -> V_137 = 1 ;
V_8 -> V_138 = 0 ;
V_8 -> V_3 . V_118 = 0 ;
return V_41 ;
}
int F_78 ( struct V_35 * V_36 , struct V_1 * V_8 ,
unsigned int V_131 , unsigned int V_132 , int V_133 )
{
int V_10 ;
V_10 = F_77 ( V_36 , V_8 , V_131 , V_132 , V_133 ) ;
V_8 -> V_3 . V_118 = 1 ;
return V_10 ;
}
int F_79 ( struct V_35 * V_36 , struct V_1 * V_8 ,
V_100 V_139 , unsigned int V_132 , int V_133 )
{
void * V_88 = V_36 -> V_111 . V_88 ;
if ( V_132 > sizeof( V_36 -> V_111 . V_88 ) ) {
F_10 ( V_113 L_3 , V_47 ,
V_36 -> V_111 . V_112 ) ;
}
V_36 -> V_111 . V_134 = V_8 -> V_3 . V_135 ;
V_36 -> V_111 . V_112 = V_132 ;
V_36 -> V_111 . V_136 = 1 ;
V_8 -> V_137 = 1 ;
V_8 -> V_138 = 1 ;
if ( V_133 ) {
switch ( V_132 ) {
case 8 : * ( V_100 * ) V_88 = V_139 ; break;
case 4 : * ( V_115 * ) V_88 = V_139 ; break;
case 2 : * ( V_116 * ) V_88 = V_139 ; break;
case 1 : * ( V_117 * ) V_88 = V_139 ; break;
}
} else {
switch ( V_132 ) {
case 4 : F_80 ( V_88 , V_139 ) ; break;
case 2 : F_81 ( V_88 , V_139 ) ; break;
case 1 : * ( V_117 * ) V_88 = V_139 ; break;
}
}
return V_41 ;
}
int F_82 ( struct V_1 * V_8 , struct V_35 * V_36 )
{
int V_10 ;
T_2 V_140 ;
if ( V_8 -> V_141 )
F_83 ( V_142 , & V_8 -> V_143 , & V_140 ) ;
if ( V_8 -> V_137 ) {
if ( ! V_8 -> V_138 )
F_73 ( V_8 , V_36 ) ;
V_8 -> V_137 = 0 ;
} else if ( V_8 -> V_3 . V_144 ) {
if ( ! V_8 -> V_3 . V_145 )
F_72 ( V_8 , V_36 ) ;
V_8 -> V_3 . V_144 = 0 ;
} else if ( V_8 -> V_3 . V_146 ) {
V_100 * V_147 = V_36 -> V_148 . V_147 ;
int V_52 ;
for ( V_52 = 0 ; V_52 < 32 ; V_52 ++ )
F_5 ( V_8 , V_52 , V_147 [ V_52 ] ) ;
V_8 -> V_3 . V_146 = 0 ;
} else if ( V_8 -> V_3 . V_149 ) {
int V_52 ;
F_5 ( V_8 , 3 , V_36 -> V_150 . V_151 ) ;
for ( V_52 = 0 ; V_52 < 9 ; ++ V_52 )
F_5 ( V_8 , 4 + V_52 , V_36 -> V_150 . args [ V_52 ] ) ;
V_8 -> V_3 . V_149 = 0 ;
}
F_84 ( V_8 ) ;
V_10 = F_85 ( V_36 , V_8 ) ;
if ( V_8 -> V_141 )
F_83 ( V_142 , & V_140 , NULL ) ;
return V_10 ;
}
int F_86 ( struct V_1 * V_8 , struct V_152 * V_153 )
{
if ( V_153 -> V_153 == V_154 ) {
F_87 ( V_8 , V_153 ) ;
return 0 ;
}
F_88 ( V_8 , V_153 ) ;
if ( F_52 ( V_8 -> V_3 . V_84 ) ) {
F_53 ( V_8 -> V_3 . V_84 ) ;
V_8 -> V_89 . V_90 ++ ;
} else if ( V_8 -> V_102 != - 1 ) {
F_89 ( V_8 -> V_102 ) ;
}
return 0 ;
}
static int F_90 ( struct V_1 * V_8 ,
struct V_155 * V_156 )
{
int V_10 ;
if ( V_156 -> V_157 )
return - V_34 ;
switch ( V_156 -> V_156 ) {
case V_64 :
V_10 = 0 ;
V_8 -> V_3 . V_158 = true ;
break;
case V_59 :
V_10 = 0 ;
V_8 -> V_3 . V_32 = true ;
break;
default:
V_10 = - V_34 ;
break;
}
if ( ! V_10 )
V_10 = F_6 ( V_8 ) ;
return V_10 ;
}
int F_91 ( struct V_1 * V_8 ,
struct V_159 * V_160 )
{
return - V_34 ;
}
int F_92 ( struct V_1 * V_8 ,
struct V_159 * V_160 )
{
return - V_34 ;
}
long F_93 ( struct V_73 * V_74 ,
unsigned int V_75 , unsigned long V_76 )
{
struct V_1 * V_8 = V_74 -> V_161 ;
void T_3 * V_162 = ( void T_3 * ) V_76 ;
long V_10 ;
switch ( V_75 ) {
case V_163 : {
struct V_152 V_153 ;
V_10 = - V_164 ;
if ( F_94 ( & V_153 , V_162 , sizeof( V_153 ) ) )
goto V_29;
V_10 = F_86 ( V_8 , & V_153 ) ;
goto V_29;
}
case V_165 :
{
struct V_155 V_156 ;
V_10 = - V_164 ;
if ( F_94 ( & V_156 , V_162 , sizeof( V_156 ) ) )
goto V_29;
V_10 = F_90 ( V_8 , & V_156 ) ;
break;
}
default:
V_10 = - V_34 ;
}
V_29:
return V_10 ;
}
static int F_95 ( struct V_166 * V_167 )
{
V_115 V_168 = 0x3c000000 ;
V_115 V_169 = 0x60000000 ;
V_115 V_170 = 0x60000000 ;
V_115 V_171 = 0x44000002 ;
V_115 V_172 = 0xffff ;
V_167 -> V_173 [ 0 ] = V_168 | ( ( V_174 >> 16 ) & V_172 ) ;
V_167 -> V_173 [ 1 ] = V_169 | ( V_174 & V_172 ) ;
V_167 -> V_173 [ 2 ] = V_171 ;
V_167 -> V_173 [ 3 ] = V_170 ;
return 0 ;
}
long F_96 ( struct V_73 * V_74 ,
unsigned int V_75 , unsigned long V_76 )
{
void T_3 * V_162 = ( void T_3 * ) V_76 ;
long V_10 ;
switch ( V_75 ) {
case V_175 : {
struct V_166 V_167 ;
memset ( & V_167 , 0 , sizeof( V_167 ) ) ;
V_10 = F_95 ( & V_167 ) ;
if ( F_97 ( V_162 , & V_167 , sizeof( V_167 ) ) ) {
V_10 = - V_164 ;
goto V_29;
}
break;
}
#ifdef F_7
case V_176 : {
struct V_177 V_178 ;
struct V_51 * V_51 = V_74 -> V_161 ;
V_10 = - V_164 ;
if ( F_94 ( & V_178 , V_162 , sizeof( V_178 ) ) )
goto V_29;
V_10 = F_98 ( V_51 , & V_178 ) ;
goto V_29;
}
case V_179 : {
struct V_51 * V_51 = V_74 -> V_161 ;
struct V_180 V_181 ;
V_10 = F_99 ( V_51 , & V_181 ) ;
if ( V_10 >= 0 && F_97 ( V_162 , & V_181 , sizeof( V_181 ) ) )
V_10 = - V_164 ;
break;
}
#endif
default:
V_10 = - V_182 ;
}
V_29:
return V_10 ;
}
int F_100 ( void * V_183 )
{
return 0 ;
}
void F_101 ( void )
{
}
