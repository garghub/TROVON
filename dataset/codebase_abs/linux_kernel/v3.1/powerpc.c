int F_1 ( struct V_1 * V_2 )
{
#ifndef F_2
return ! ( V_2 -> V_3 . V_4 -> V_5 & V_6 ) ||
! ! ( V_2 -> V_3 . V_7 ) ;
#else
return ! ( V_2 -> V_3 . V_8 ) || ! ! ( V_2 -> V_3 . V_7 ) ;
#endif
}
int F_3 ( struct V_1 * V_9 )
{
int V_10 = F_4 ( V_9 , 11 ) ;
int V_11 ;
unsigned long T_1 V_12 = F_4 ( V_9 , 3 ) ;
unsigned long T_1 V_13 = F_4 ( V_9 , 4 ) ;
unsigned long T_1 V_14 = F_4 ( V_9 , 5 ) ;
unsigned long T_1 V_15 = F_4 ( V_9 , 6 ) ;
unsigned long V_16 = 0 ;
if ( ! ( V_9 -> V_3 . V_4 -> V_5 & V_17 ) ) {
V_12 &= 0xffffffff ;
V_13 &= 0xffffffff ;
V_14 &= 0xffffffff ;
V_15 &= 0xffffffff ;
}
switch ( V_10 ) {
case V_18 | V_19 :
{
V_9 -> V_3 . V_20 = V_12 ;
V_9 -> V_3 . V_21 = V_13 ;
V_16 = V_22 ;
V_11 = V_23 ;
break;
}
case V_18 | V_24 :
V_11 = V_23 ;
#if F_5 ( V_25 ) || F_5 ( V_26 )
V_16 |= ( 1 << V_27 ) ;
#endif
break;
default:
V_11 = V_28 ;
break;
}
F_6 ( V_9 , 4 , V_16 ) ;
return V_11 ;
}
int F_7 ( struct V_29 * V_30 , struct V_1 * V_9 )
{
enum V_31 V_32 ;
int V_11 ;
V_32 = F_8 ( V_30 , V_9 ) ;
switch ( V_32 ) {
case V_33 :
V_11 = V_34 ;
break;
case V_35 :
V_30 -> V_36 = V_37 ;
V_11 = V_38 ;
break;
case V_39 :
F_9 ( V_40 L_1 , V_41 ,
F_10 ( V_9 ) ) ;
V_11 = V_42 ;
break;
default:
F_11 () ;
}
return V_11 ;
}
int F_12 ( void * V_43 )
{
return 0 ;
}
void F_13 ( void * V_43 )
{
}
int F_14 ( void )
{
return 0 ;
}
void F_15 ( void )
{
}
void F_16 ( void * V_44 )
{
* ( int * ) V_44 = F_17 () ;
}
int F_18 ( struct V_45 * V_45 )
{
return F_19 ( V_45 ) ;
}
void F_20 ( struct V_45 * V_45 )
{
unsigned int V_46 ;
struct V_1 * V_9 ;
F_21 (i, vcpu, kvm)
F_22 ( V_9 ) ;
F_23 ( & V_45 -> V_47 ) ;
for ( V_46 = 0 ; V_46 < F_24 ( & V_45 -> V_48 ) ; V_46 ++ )
V_45 -> V_49 [ V_46 ] = NULL ;
F_25 ( & V_45 -> V_48 , 0 ) ;
F_26 ( V_45 ) ;
F_27 ( & V_45 -> V_47 ) ;
}
void F_28 ( struct V_45 * V_45 )
{
}
int F_29 ( long V_50 )
{
int V_11 ;
switch ( V_50 ) {
#ifdef F_30
case V_51 :
#else
case V_52 :
#endif
case V_53 :
case V_54 :
case V_55 :
V_11 = 1 ;
break;
#ifndef F_2
case V_56 :
case V_57 :
case V_58 :
V_11 = 1 ;
break;
case V_59 :
V_11 = V_60 ;
break;
#endif
#ifdef F_2
case V_61 :
V_11 = 1 ;
break;
case V_62 :
V_11 = V_63 ;
break;
case V_64 :
V_11 = 1 ;
if ( F_31 ( V_65 ) )
V_11 = 2 ;
break;
#endif
default:
V_11 = 0 ;
break;
}
return V_11 ;
}
long F_32 ( struct V_66 * V_67 ,
unsigned int V_68 , unsigned long V_69 )
{
return - V_70 ;
}
int F_33 ( struct V_45 * V_45 ,
struct V_71 * V_72 ,
struct V_71 V_73 ,
struct V_74 * V_75 ,
int V_76 )
{
return F_34 ( V_45 , V_75 ) ;
}
void F_35 ( struct V_45 * V_45 ,
struct V_74 * V_75 ,
struct V_71 V_73 ,
int V_76 )
{
F_36 ( V_45 , V_75 ) ;
}
void F_37 ( struct V_45 * V_45 )
{
}
struct V_1 * F_38 ( struct V_45 * V_45 , unsigned int V_77 )
{
struct V_1 * V_9 ;
V_9 = F_39 ( V_45 , V_77 ) ;
if ( ! F_40 ( V_9 ) )
F_41 ( V_9 , V_77 ) ;
return V_9 ;
}
void F_22 ( struct V_1 * V_9 )
{
F_42 ( & V_9 -> V_3 . V_78 ) ;
F_43 ( & V_9 -> V_3 . V_79 ) ;
F_44 ( V_9 ) ;
F_45 ( V_9 ) ;
}
void F_46 ( struct V_1 * V_9 )
{
F_22 ( V_9 ) ;
}
int F_47 ( struct V_1 * V_9 )
{
return F_48 ( V_9 ) ;
}
static void F_49 ( unsigned long V_80 )
{
struct V_1 * V_9 = (struct V_1 * ) V_80 ;
F_50 ( V_9 ) ;
if ( F_51 ( & V_9 -> V_81 ) ) {
F_52 ( & V_9 -> V_81 ) ;
V_9 -> V_82 . V_83 ++ ;
}
}
enum V_84 F_53 ( struct V_85 * V_86 )
{
struct V_1 * V_9 ;
V_9 = F_54 ( V_86 , struct V_1 , V_3 . V_78 ) ;
F_55 ( & V_9 -> V_3 . V_79 ) ;
return V_87 ;
}
int F_56 ( struct V_1 * V_9 )
{
F_57 ( & V_9 -> V_3 . V_78 , V_88 , V_89 ) ;
F_58 ( & V_9 -> V_3 . V_79 , F_49 , ( V_90 ) V_9 ) ;
V_9 -> V_3 . V_78 . V_91 = F_53 ;
V_9 -> V_3 . V_92 = ~ ( V_93 ) 0 ;
#ifdef F_59
F_60 ( & V_9 -> V_3 . V_94 ) ;
#endif
return 0 ;
}
void F_61 ( struct V_1 * V_9 )
{
F_62 ( V_9 ) ;
}
void F_63 ( struct V_1 * V_9 , int V_95 )
{
#ifdef F_30
F_64 ( V_96 , V_9 -> V_3 . V_97 ) ;
#endif
F_65 ( V_9 , V_95 ) ;
V_9 -> V_95 = F_66 () ;
}
void F_67 ( struct V_1 * V_9 )
{
F_68 ( V_9 ) ;
#ifdef F_30
V_9 -> V_3 . V_97 = F_69 ( V_96 ) ;
#endif
V_9 -> V_95 = - 1 ;
}
int F_70 ( struct V_1 * V_9 ,
struct V_98 * V_99 )
{
return - V_70 ;
}
static void F_71 ( struct V_1 * V_9 ,
struct V_29 * V_30 )
{
F_6 ( V_9 , V_9 -> V_3 . V_100 , V_30 -> V_101 . V_80 ) ;
}
static void F_72 ( struct V_1 * V_9 ,
struct V_29 * V_30 )
{
V_93 V_102 ( V_103 ) ;
if ( V_30 -> V_104 . V_105 > sizeof( V_103 ) ) {
F_9 ( V_106 L_2 , V_30 -> V_104 . V_105 ) ;
return;
}
if ( V_9 -> V_3 . V_107 ) {
switch ( V_30 -> V_104 . V_105 ) {
case 8 : V_103 = * ( V_93 * ) V_30 -> V_104 . V_80 ; break;
case 4 : V_103 = * ( V_108 * ) V_30 -> V_104 . V_80 ; break;
case 2 : V_103 = * ( V_109 * ) V_30 -> V_104 . V_80 ; break;
case 1 : V_103 = * ( V_110 * ) V_30 -> V_104 . V_80 ; break;
}
} else {
switch ( V_30 -> V_104 . V_105 ) {
case 4 : V_103 = F_73 ( ( V_108 * ) V_30 -> V_104 . V_80 ) ; break;
case 2 : V_103 = F_74 ( ( V_109 * ) V_30 -> V_104 . V_80 ) ; break;
case 1 : V_103 = * ( V_110 * ) V_30 -> V_104 . V_80 ; break;
}
}
if ( V_9 -> V_3 . V_111 ) {
switch ( V_30 -> V_104 . V_105 ) {
#ifdef F_75
case 4 :
V_103 = ( V_112 ) ( V_113 ) V_103 ;
break;
#endif
case 2 :
V_103 = ( V_112 ) ( V_114 ) V_103 ;
break;
case 1 :
V_103 = ( V_112 ) ( V_115 ) V_103 ;
break;
}
}
F_6 ( V_9 , V_9 -> V_3 . V_100 , V_103 ) ;
switch ( V_9 -> V_3 . V_100 & V_116 ) {
case V_117 :
F_6 ( V_9 , V_9 -> V_3 . V_100 , V_103 ) ;
break;
case V_118 :
V_9 -> V_3 . V_119 [ V_9 -> V_3 . V_100 & V_120 ] = V_103 ;
break;
#ifdef V_25
case V_121 :
V_9 -> V_3 . V_122 [ V_9 -> V_3 . V_100 & V_120 ] = V_103 ;
break;
case V_123 :
V_9 -> V_3 . V_119 [ V_9 -> V_3 . V_100 & V_120 ] = V_103 ;
V_9 -> V_3 . V_122 [ V_9 -> V_3 . V_100 & V_120 ] = V_103 ;
break;
#endif
default:
F_11 () ;
}
}
int F_76 ( struct V_29 * V_30 , struct V_1 * V_9 ,
unsigned int V_124 , unsigned int V_125 , int V_126 )
{
if ( V_125 > sizeof( V_30 -> V_104 . V_80 ) ) {
F_9 ( V_106 L_3 , V_41 ,
V_30 -> V_104 . V_105 ) ;
}
V_30 -> V_104 . V_127 = V_9 -> V_3 . V_128 ;
V_30 -> V_104 . V_105 = V_125 ;
V_30 -> V_104 . V_129 = 0 ;
V_9 -> V_3 . V_100 = V_124 ;
V_9 -> V_3 . V_107 = V_126 ;
V_9 -> V_130 = 1 ;
V_9 -> V_131 = 0 ;
V_9 -> V_3 . V_111 = 0 ;
return V_35 ;
}
int F_77 ( struct V_29 * V_30 , struct V_1 * V_9 ,
unsigned int V_124 , unsigned int V_125 , int V_126 )
{
int V_11 ;
V_11 = F_76 ( V_30 , V_9 , V_124 , V_125 , V_126 ) ;
V_9 -> V_3 . V_111 = 1 ;
return V_11 ;
}
int F_78 ( struct V_29 * V_30 , struct V_1 * V_9 ,
V_93 V_132 , unsigned int V_125 , int V_126 )
{
void * V_80 = V_30 -> V_104 . V_80 ;
if ( V_125 > sizeof( V_30 -> V_104 . V_80 ) ) {
F_9 ( V_106 L_3 , V_41 ,
V_30 -> V_104 . V_105 ) ;
}
V_30 -> V_104 . V_127 = V_9 -> V_3 . V_128 ;
V_30 -> V_104 . V_105 = V_125 ;
V_30 -> V_104 . V_129 = 1 ;
V_9 -> V_130 = 1 ;
V_9 -> V_131 = 1 ;
if ( V_126 ) {
switch ( V_125 ) {
case 8 : * ( V_93 * ) V_80 = V_132 ; break;
case 4 : * ( V_108 * ) V_80 = V_132 ; break;
case 2 : * ( V_109 * ) V_80 = V_132 ; break;
case 1 : * ( V_110 * ) V_80 = V_132 ; break;
}
} else {
switch ( V_125 ) {
case 4 : F_79 ( V_80 , V_132 ) ; break;
case 2 : F_80 ( V_80 , V_132 ) ; break;
case 1 : * ( V_110 * ) V_80 = V_132 ; break;
}
}
return V_35 ;
}
int F_81 ( struct V_1 * V_9 , struct V_29 * V_30 )
{
int V_11 ;
T_2 V_133 ;
if ( V_9 -> V_134 )
F_82 ( V_135 , & V_9 -> V_136 , & V_133 ) ;
if ( V_9 -> V_130 ) {
if ( ! V_9 -> V_131 )
F_72 ( V_9 , V_30 ) ;
V_9 -> V_130 = 0 ;
} else if ( V_9 -> V_3 . V_137 ) {
if ( ! V_9 -> V_3 . V_138 )
F_71 ( V_9 , V_30 ) ;
V_9 -> V_3 . V_137 = 0 ;
} else if ( V_9 -> V_3 . V_139 ) {
V_93 * V_140 = V_30 -> V_141 . V_140 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < 32 ; V_46 ++ )
F_6 ( V_9 , V_46 , V_140 [ V_46 ] ) ;
V_9 -> V_3 . V_139 = 0 ;
} else if ( V_9 -> V_3 . V_142 ) {
int V_46 ;
F_6 ( V_9 , 3 , V_30 -> V_143 . V_144 ) ;
for ( V_46 = 0 ; V_46 < 9 ; ++ V_46 )
F_6 ( V_9 , 4 + V_46 , V_30 -> V_143 . args [ V_46 ] ) ;
V_9 -> V_3 . V_142 = 0 ;
}
F_83 ( V_9 ) ;
V_11 = F_84 ( V_30 , V_9 ) ;
if ( V_9 -> V_134 )
F_82 ( V_135 , & V_133 , NULL ) ;
return V_11 ;
}
int F_85 ( struct V_1 * V_9 , struct V_145 * V_146 )
{
if ( V_146 -> V_146 == V_147 )
F_86 ( V_9 , V_146 ) ;
else
F_87 ( V_9 , V_146 ) ;
if ( F_51 ( & V_9 -> V_81 ) ) {
F_52 ( & V_9 -> V_81 ) ;
V_9 -> V_82 . V_83 ++ ;
} else if ( V_9 -> V_95 != - 1 ) {
F_88 ( V_9 -> V_95 ) ;
}
return 0 ;
}
static int F_89 ( struct V_1 * V_9 ,
struct V_148 * V_149 )
{
int V_11 ;
if ( V_149 -> V_150 )
return - V_70 ;
switch ( V_149 -> V_149 ) {
case V_57 :
V_11 = 0 ;
V_9 -> V_3 . V_151 = true ;
break;
default:
V_11 = - V_70 ;
break;
}
return V_11 ;
}
int F_90 ( struct V_1 * V_9 ,
struct V_152 * V_153 )
{
return - V_70 ;
}
int F_91 ( struct V_1 * V_9 ,
struct V_152 * V_153 )
{
return - V_70 ;
}
long F_92 ( struct V_66 * V_67 ,
unsigned int V_68 , unsigned long V_69 )
{
struct V_1 * V_9 = V_67 -> V_154 ;
void T_3 * V_155 = ( void T_3 * ) V_69 ;
long V_11 ;
switch ( V_68 ) {
case V_156 : {
struct V_145 V_146 ;
V_11 = - V_157 ;
if ( F_93 ( & V_146 , V_155 , sizeof( V_146 ) ) )
goto V_158;
V_11 = F_85 ( V_9 , & V_146 ) ;
goto V_158;
}
case V_159 :
{
struct V_148 V_149 ;
V_11 = - V_157 ;
if ( F_93 ( & V_149 , V_155 , sizeof( V_149 ) ) )
goto V_158;
V_11 = F_89 ( V_9 , & V_149 ) ;
break;
}
default:
V_11 = - V_70 ;
}
V_158:
return V_11 ;
}
static int F_94 ( struct V_160 * V_161 )
{
V_108 V_162 = 0x3c000000 ;
V_108 V_163 = 0x60000000 ;
V_108 V_164 = 0x60000000 ;
V_108 V_165 = 0x44000002 ;
V_108 V_166 = 0xffff ;
V_161 -> V_167 [ 0 ] = V_162 | ( ( V_168 >> 16 ) & V_166 ) ;
V_161 -> V_167 [ 1 ] = V_163 | ( V_168 & V_166 ) ;
V_161 -> V_167 [ 2 ] = V_165 ;
V_161 -> V_167 [ 3 ] = V_164 ;
return 0 ;
}
long F_95 ( struct V_66 * V_67 ,
unsigned int V_68 , unsigned long V_69 )
{
void T_3 * V_155 = ( void T_3 * ) V_69 ;
long V_11 ;
switch ( V_68 ) {
case V_169 : {
struct V_160 V_161 ;
memset ( & V_161 , 0 , sizeof( V_161 ) ) ;
V_11 = F_94 ( & V_161 ) ;
if ( F_96 ( V_155 , & V_161 , sizeof( V_161 ) ) ) {
V_11 = - V_157 ;
goto V_158;
}
break;
}
#ifdef F_2
case V_170 : {
struct V_171 V_172 ;
struct V_45 * V_45 = V_67 -> V_154 ;
V_11 = - V_157 ;
if ( F_93 ( & V_172 , V_155 , sizeof( V_172 ) ) )
goto V_158;
V_11 = F_97 ( V_45 , & V_172 ) ;
goto V_158;
}
case V_173 : {
struct V_45 * V_45 = V_67 -> V_154 ;
struct V_174 V_175 ;
V_11 = F_98 ( V_45 , & V_175 ) ;
if ( V_11 >= 0 && F_96 ( V_155 , & V_175 , sizeof( V_175 ) ) )
V_11 = - V_157 ;
break;
}
#endif
default:
V_11 = - V_176 ;
}
V_158:
return V_11 ;
}
int F_99 ( void * V_177 )
{
return 0 ;
}
void F_100 ( void )
{
}
