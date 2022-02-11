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
#if F_4 ( V_24 )
V_15 |= ( 1 << V_25 ) ;
#endif
break;
default:
V_10 = V_26 ;
break;
}
F_5 ( V_8 , 4 , V_15 ) ;
return V_10 ;
}
int F_6 ( struct V_27 * V_28 , struct V_1 * V_8 )
{
enum V_29 V_30 ;
int V_10 ;
V_30 = F_7 ( V_28 , V_8 ) ;
switch ( V_30 ) {
case V_31 :
V_10 = V_32 ;
break;
case V_33 :
V_28 -> V_34 = V_35 ;
V_10 = V_36 ;
break;
case V_37 :
F_8 ( V_38 L_1 , V_39 ,
F_9 ( V_8 ) ) ;
V_10 = V_40 ;
break;
default:
F_10 () ;
}
return V_10 ;
}
int F_11 ( void * V_41 )
{
return 0 ;
}
void F_12 ( void * V_41 )
{
}
int F_13 ( void )
{
return 0 ;
}
void F_14 ( void )
{
}
void F_15 ( void * V_42 )
{
* ( int * ) V_42 = F_16 () ;
}
int F_17 ( struct V_43 * V_43 )
{
return 0 ;
}
void F_18 ( struct V_43 * V_43 )
{
unsigned int V_44 ;
struct V_1 * V_8 ;
F_19 (i, vcpu, kvm)
F_20 ( V_8 ) ;
F_21 ( & V_43 -> V_45 ) ;
for ( V_44 = 0 ; V_44 < F_22 ( & V_43 -> V_46 ) ; V_44 ++ )
V_43 -> V_47 [ V_44 ] = NULL ;
F_23 ( & V_43 -> V_46 , 0 ) ;
F_24 ( & V_43 -> V_45 ) ;
}
void F_25 ( struct V_43 * V_43 )
{
}
int F_26 ( long V_48 )
{
int V_10 ;
switch ( V_48 ) {
#ifdef F_27
case V_49 :
#else
case V_50 :
#endif
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
V_10 = 1 ;
break;
case V_57 :
V_10 = V_58 ;
break;
default:
V_10 = 0 ;
break;
}
return V_10 ;
}
long F_28 ( struct V_59 * V_60 ,
unsigned int V_61 , unsigned long V_62 )
{
return - V_63 ;
}
int F_29 ( struct V_43 * V_43 ,
struct V_64 * V_65 ,
struct V_64 V_66 ,
struct V_67 * V_68 ,
int V_69 )
{
return 0 ;
}
void F_30 ( struct V_43 * V_43 ,
struct V_67 * V_68 ,
struct V_64 V_66 ,
int V_69 )
{
return;
}
void F_31 ( struct V_43 * V_43 )
{
}
struct V_1 * F_32 ( struct V_43 * V_43 , unsigned int V_70 )
{
struct V_1 * V_8 ;
V_8 = F_33 ( V_43 , V_70 ) ;
if ( ! F_34 ( V_8 ) )
F_35 ( V_8 , V_70 ) ;
return V_8 ;
}
void F_20 ( struct V_1 * V_8 )
{
F_36 ( & V_8 -> V_3 . V_71 ) ;
F_37 ( & V_8 -> V_3 . V_72 ) ;
F_38 ( V_8 ) ;
F_39 ( V_8 ) ;
}
void F_40 ( struct V_1 * V_8 )
{
F_20 ( V_8 ) ;
}
int F_41 ( struct V_1 * V_8 )
{
return F_42 ( V_8 ) ;
}
static void F_43 ( unsigned long V_73 )
{
struct V_1 * V_8 = (struct V_1 * ) V_73 ;
F_44 ( V_8 ) ;
if ( F_45 ( & V_8 -> V_74 ) ) {
F_46 ( & V_8 -> V_74 ) ;
V_8 -> V_75 . V_76 ++ ;
}
}
enum V_77 F_47 ( struct V_78 * V_79 )
{
struct V_1 * V_8 ;
V_8 = F_48 ( V_79 , struct V_1 , V_3 . V_71 ) ;
F_49 ( & V_8 -> V_3 . V_72 ) ;
return V_80 ;
}
int F_50 ( struct V_1 * V_8 )
{
F_51 ( & V_8 -> V_3 . V_71 , V_81 , V_82 ) ;
F_52 ( & V_8 -> V_3 . V_72 , F_43 , ( V_83 ) V_8 ) ;
V_8 -> V_3 . V_71 . V_84 = F_47 ;
#ifdef F_53
F_54 ( & V_8 -> V_3 . V_85 ) ;
#endif
return 0 ;
}
void F_55 ( struct V_1 * V_8 )
{
F_56 ( V_8 ) ;
}
void F_57 ( struct V_1 * V_8 , int V_86 )
{
#ifdef F_27
F_58 ( V_87 , V_8 -> V_3 . V_88 ) ;
#endif
F_59 ( V_8 , V_86 ) ;
}
void F_60 ( struct V_1 * V_8 )
{
F_61 ( V_8 ) ;
#ifdef F_27
V_8 -> V_3 . V_88 = F_62 ( V_87 ) ;
#endif
}
int F_63 ( struct V_1 * V_8 ,
struct V_89 * V_90 )
{
return - V_63 ;
}
static void F_64 ( struct V_1 * V_8 ,
struct V_27 * V_28 )
{
F_5 ( V_8 , V_8 -> V_3 . V_91 , V_28 -> V_92 . V_73 ) ;
}
static void F_65 ( struct V_1 * V_8 ,
struct V_27 * V_28 )
{
T_2 V_93 ( V_94 ) ;
if ( V_28 -> V_95 . V_96 > sizeof( V_94 ) ) {
F_8 ( V_97 L_2 , V_28 -> V_95 . V_96 ) ;
return;
}
if ( V_8 -> V_3 . V_98 ) {
switch ( V_28 -> V_95 . V_96 ) {
case 8 : V_94 = * ( T_2 * ) V_28 -> V_95 . V_73 ; break;
case 4 : V_94 = * ( V_99 * ) V_28 -> V_95 . V_73 ; break;
case 2 : V_94 = * ( V_100 * ) V_28 -> V_95 . V_73 ; break;
case 1 : V_94 = * ( V_101 * ) V_28 -> V_95 . V_73 ; break;
}
} else {
switch ( V_28 -> V_95 . V_96 ) {
case 4 : V_94 = F_66 ( ( V_99 * ) V_28 -> V_95 . V_73 ) ; break;
case 2 : V_94 = F_67 ( ( V_100 * ) V_28 -> V_95 . V_73 ) ; break;
case 1 : V_94 = * ( V_101 * ) V_28 -> V_95 . V_73 ; break;
}
}
if ( V_8 -> V_3 . V_102 ) {
switch ( V_28 -> V_95 . V_96 ) {
#ifdef F_68
case 4 :
V_94 = ( V_103 ) ( V_104 ) V_94 ;
break;
#endif
case 2 :
V_94 = ( V_103 ) ( V_105 ) V_94 ;
break;
case 1 :
V_94 = ( V_103 ) ( V_106 ) V_94 ;
break;
}
}
F_5 ( V_8 , V_8 -> V_3 . V_91 , V_94 ) ;
switch ( V_8 -> V_3 . V_91 & V_107 ) {
case V_108 :
F_5 ( V_8 , V_8 -> V_3 . V_91 , V_94 ) ;
break;
case V_109 :
V_8 -> V_3 . V_110 [ V_8 -> V_3 . V_91 & V_111 ] = V_94 ;
break;
#ifdef V_24
case V_112 :
V_8 -> V_3 . V_113 [ V_8 -> V_3 . V_91 & V_111 ] = V_94 ;
break;
case V_114 :
V_8 -> V_3 . V_110 [ V_8 -> V_3 . V_91 & V_111 ] = V_94 ;
V_8 -> V_3 . V_113 [ V_8 -> V_3 . V_91 & V_111 ] = V_94 ;
break;
#endif
default:
F_10 () ;
}
}
int F_69 ( struct V_27 * V_28 , struct V_1 * V_8 ,
unsigned int V_115 , unsigned int V_116 , int V_117 )
{
if ( V_116 > sizeof( V_28 -> V_95 . V_73 ) ) {
F_8 ( V_97 L_3 , V_39 ,
V_28 -> V_95 . V_96 ) ;
}
V_28 -> V_95 . V_118 = V_8 -> V_3 . V_119 ;
V_28 -> V_95 . V_96 = V_116 ;
V_28 -> V_95 . V_120 = 0 ;
V_8 -> V_3 . V_91 = V_115 ;
V_8 -> V_3 . V_98 = V_117 ;
V_8 -> V_121 = 1 ;
V_8 -> V_122 = 0 ;
V_8 -> V_3 . V_102 = 0 ;
return V_33 ;
}
int F_70 ( struct V_27 * V_28 , struct V_1 * V_8 ,
unsigned int V_115 , unsigned int V_116 , int V_117 )
{
int V_10 ;
V_10 = F_69 ( V_28 , V_8 , V_115 , V_116 , V_117 ) ;
V_8 -> V_3 . V_102 = 1 ;
return V_10 ;
}
int F_71 ( struct V_27 * V_28 , struct V_1 * V_8 ,
T_2 V_123 , unsigned int V_116 , int V_117 )
{
void * V_73 = V_28 -> V_95 . V_73 ;
if ( V_116 > sizeof( V_28 -> V_95 . V_73 ) ) {
F_8 ( V_97 L_3 , V_39 ,
V_28 -> V_95 . V_96 ) ;
}
V_28 -> V_95 . V_118 = V_8 -> V_3 . V_119 ;
V_28 -> V_95 . V_96 = V_116 ;
V_28 -> V_95 . V_120 = 1 ;
V_8 -> V_121 = 1 ;
V_8 -> V_122 = 1 ;
if ( V_117 ) {
switch ( V_116 ) {
case 8 : * ( T_2 * ) V_73 = V_123 ; break;
case 4 : * ( V_99 * ) V_73 = V_123 ; break;
case 2 : * ( V_100 * ) V_73 = V_123 ; break;
case 1 : * ( V_101 * ) V_73 = V_123 ; break;
}
} else {
switch ( V_116 ) {
case 4 : F_72 ( V_73 , V_123 ) ; break;
case 2 : F_73 ( V_73 , V_123 ) ; break;
case 1 : * ( V_101 * ) V_73 = V_123 ; break;
}
}
return V_33 ;
}
int F_74 ( struct V_1 * V_8 , struct V_27 * V_28 )
{
int V_10 ;
T_3 V_124 ;
if ( V_8 -> V_125 )
F_75 ( V_126 , & V_8 -> V_127 , & V_124 ) ;
if ( V_8 -> V_121 ) {
if ( ! V_8 -> V_122 )
F_65 ( V_8 , V_28 ) ;
V_8 -> V_121 = 0 ;
} else if ( V_8 -> V_3 . V_128 ) {
if ( ! V_8 -> V_3 . V_129 )
F_64 ( V_8 , V_28 ) ;
V_8 -> V_3 . V_128 = 0 ;
} else if ( V_8 -> V_3 . V_130 ) {
T_2 * V_131 = V_28 -> V_132 . V_131 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < 32 ; V_44 ++ )
F_5 ( V_8 , V_44 , V_131 [ V_44 ] ) ;
V_8 -> V_3 . V_130 = 0 ;
}
F_76 ( V_8 ) ;
F_77 () ;
F_78 () ;
V_10 = F_79 ( V_28 , V_8 ) ;
F_80 () ;
F_81 () ;
if ( V_8 -> V_125 )
F_75 ( V_126 , & V_124 , NULL ) ;
return V_10 ;
}
int F_82 ( struct V_1 * V_8 , struct V_133 * V_134 )
{
if ( V_134 -> V_134 == V_135 )
F_83 ( V_8 , V_134 ) ;
else
F_84 ( V_8 , V_134 ) ;
if ( F_45 ( & V_8 -> V_74 ) ) {
F_46 ( & V_8 -> V_74 ) ;
V_8 -> V_75 . V_76 ++ ;
}
return 0 ;
}
static int F_85 ( struct V_1 * V_8 ,
struct V_136 * V_137 )
{
int V_10 ;
if ( V_137 -> V_138 )
return - V_63 ;
switch ( V_137 -> V_137 ) {
case V_55 :
V_10 = 0 ;
V_8 -> V_3 . V_139 = true ;
break;
default:
V_10 = - V_63 ;
break;
}
return V_10 ;
}
int F_86 ( struct V_1 * V_8 ,
struct V_140 * V_141 )
{
return - V_63 ;
}
int F_87 ( struct V_1 * V_8 ,
struct V_140 * V_141 )
{
return - V_63 ;
}
long F_88 ( struct V_59 * V_60 ,
unsigned int V_61 , unsigned long V_62 )
{
struct V_1 * V_8 = V_60 -> V_142 ;
void T_4 * V_143 = ( void T_4 * ) V_62 ;
long V_10 ;
switch ( V_61 ) {
case V_144 : {
struct V_133 V_134 ;
V_10 = - V_145 ;
if ( F_89 ( & V_134 , V_143 , sizeof( V_134 ) ) )
goto V_146;
V_10 = F_82 ( V_8 , & V_134 ) ;
goto V_146;
}
case V_147 :
{
struct V_136 V_137 ;
V_10 = - V_145 ;
if ( F_89 ( & V_137 , V_143 , sizeof( V_137 ) ) )
goto V_146;
V_10 = F_85 ( V_8 , & V_137 ) ;
break;
}
default:
V_10 = - V_63 ;
}
V_146:
return V_10 ;
}
static int F_90 ( struct V_148 * V_149 )
{
V_99 V_150 = 0x3c000000 ;
V_99 V_151 = 0x60000000 ;
V_99 V_152 = 0x60000000 ;
V_99 V_153 = 0x44000002 ;
V_99 V_154 = 0xffff ;
V_149 -> V_155 [ 0 ] = V_150 | ( ( V_156 >> 16 ) & V_154 ) ;
V_149 -> V_155 [ 1 ] = V_151 | ( V_156 & V_154 ) ;
V_149 -> V_155 [ 2 ] = V_153 ;
V_149 -> V_155 [ 3 ] = V_152 ;
return 0 ;
}
long F_91 ( struct V_59 * V_60 ,
unsigned int V_61 , unsigned long V_62 )
{
void T_4 * V_143 = ( void T_4 * ) V_62 ;
long V_10 ;
switch ( V_61 ) {
case V_157 : {
struct V_148 V_149 ;
memset ( & V_149 , 0 , sizeof( V_149 ) ) ;
V_10 = F_90 ( & V_149 ) ;
if ( F_92 ( V_143 , & V_149 , sizeof( V_149 ) ) ) {
V_10 = - V_145 ;
goto V_146;
}
break;
}
default:
V_10 = - V_158 ;
}
V_146:
return V_10 ;
}
int F_93 ( void * V_159 )
{
return 0 ;
}
void F_94 ( void )
{
}
