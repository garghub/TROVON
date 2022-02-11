char * T_1 F_1 ( unsigned long V_1 , unsigned long V_2 )
{
if ( ! V_1 || ! V_2 )
return NULL ;
return F_2 ( V_1 , V_2 ) ;
}
void T_1 F_3 ( char * V_3 , unsigned long V_2 )
{
if ( ! V_3 || ! V_2 )
return;
F_4 ( V_3 , V_2 ) ;
}
static int T_1 F_5 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = NULL ;
if ( ! F_6 ( V_8 ) )
return - V_9 ;
V_7 = (struct V_6 * ) V_5 ;
if ( ! V_7 ) {
F_7 (KERN_WARNING PREFIX L_1 ) ;
return - V_10 ;
}
if ( V_7 -> V_11 ) {
V_12 = ( V_13 ) V_7 -> V_11 ;
F_7 (KERN_DEBUG PREFIX L_2 ,
madt->address) ;
}
F_8 ( V_7 -> V_14 . V_15 ,
V_7 -> V_14 . V_16 ) ;
return 0 ;
}
static int F_9 ( int V_17 , T_2 V_18 , T_3 V_19 )
{
unsigned int V_20 = 0 ;
int V_21 ;
if ( V_17 >= V_22 ) {
F_7 (KERN_INFO PREFIX L_3 ) ;
return - V_9 ;
}
if ( ! V_19 ) {
++ V_23 ;
return - V_9 ;
}
if ( V_24 != - 1U )
V_20 = V_25 ;
V_21 = F_10 ( V_17 , V_20 ) ;
if ( V_21 >= 0 )
F_11 ( V_26 , V_21 ) = V_18 ;
return V_21 ;
}
static int T_1
F_12 ( struct V_27 * V_14 , const unsigned long V_28 )
{
struct V_29 * V_30 = NULL ;
int V_31 ;
T_3 V_19 ;
V_30 = (struct V_29 * ) V_14 ;
if ( F_13 ( V_30 , V_28 ) )
return - V_9 ;
F_14 ( V_14 ) ;
V_31 = V_30 -> V_32 ;
V_19 = V_30 -> V_33 & V_34 ;
#ifdef F_15
if ( ! V_35 -> V_36 ( V_31 ) && V_19 )
F_7 (KERN_WARNING PREFIX L_4 ) ;
else
F_9 ( V_31 , V_30 -> V_37 , V_19 ) ;
#else
F_7 (KERN_WARNING PREFIX L_4 ) ;
#endif
return 0 ;
}
static int T_1
F_16 ( struct V_27 * V_14 , const unsigned long V_28 )
{
struct V_38 * V_30 = NULL ;
V_30 = (struct V_38 * ) V_14 ;
if ( F_13 ( V_30 , V_28 ) )
return - V_9 ;
F_14 ( V_14 ) ;
if ( V_30 -> V_17 == 0xff )
return 0 ;
F_9 ( V_30 -> V_17 ,
V_30 -> V_39 ,
V_30 -> V_33 & V_34 ) ;
return 0 ;
}
static int T_1
F_17 ( struct V_27 * V_14 , const unsigned long V_28 )
{
struct V_40 * V_30 = NULL ;
V_30 = (struct V_40 * ) V_14 ;
if ( F_13 ( V_30 , V_28 ) )
return - V_9 ;
F_14 ( V_14 ) ;
F_9 ( ( V_30 -> V_17 << 8 ) | V_30 -> V_41 ,
V_30 -> V_39 ,
V_30 -> V_33 & V_34 ) ;
return 0 ;
}
static int T_1
F_18 ( struct V_27 * V_14 ,
const unsigned long V_28 )
{
struct V_42 * V_43 = NULL ;
V_43 = (struct V_42 * ) V_14 ;
if ( F_13 ( V_43 , V_28 ) )
return - V_9 ;
F_14 ( V_14 ) ;
V_12 = V_43 -> V_11 ;
return 0 ;
}
static int T_1
F_19 ( struct V_27 * V_14 ,
const unsigned long V_28 )
{
struct V_44 * V_45 = NULL ;
V_45 = (struct V_44 * ) V_14 ;
if ( F_13 ( V_45 , V_28 ) )
return - V_9 ;
F_14 ( V_14 ) ;
if ( V_45 -> V_46 != 1 )
F_7 (KERN_WARNING PREFIX L_5 ) ;
return 0 ;
}
static int T_1
F_20 ( struct V_27 * V_14 , const unsigned long V_28 )
{
struct V_47 * V_48 = NULL ;
V_48 = (struct V_47 * ) V_14 ;
if ( F_13 ( V_48 , V_28 ) )
return - V_9 ;
F_14 ( V_14 ) ;
if ( V_48 -> V_46 != 1 )
F_7 (KERN_WARNING PREFIX L_5 ) ;
return 0 ;
}
static void T_1 F_21 ( T_3 V_49 , T_3 V_50 , T_3 V_51 ,
T_2 V_52 )
{
int V_53 ;
int V_54 ;
struct V_55 V_56 ;
if ( V_49 >= V_57 ) {
F_22 ( L_6 , V_49 ) ;
return;
}
V_53 = F_23 ( V_52 ) ;
if ( V_53 < 0 )
return;
V_54 = F_24 ( V_53 , V_52 ) ;
if ( ( V_49 == 0 ) && ( V_51 == 3 ) )
V_51 = 1 ;
V_56 . type = V_58 ;
V_56 . V_59 = V_60 ;
V_56 . V_61 = ( V_51 << 2 ) | V_50 ;
V_56 . V_62 = V_63 ;
V_56 . V_64 = V_49 ;
V_56 . V_65 = F_25 ( V_53 ) ;
V_56 . V_66 = V_54 ;
F_26 ( & V_56 ) ;
if ( V_52 < F_27 () && V_67 [ V_52 ] == V_52 )
V_67 [ V_52 ] = V_68 ;
V_67 [ V_49 ] = V_52 ;
}
static int F_28 ( struct V_69 * V_70 , T_2 V_52 , int V_51 ,
int V_50 )
{
#ifdef F_29
struct V_55 V_56 ;
struct V_71 * V_72 ;
unsigned char V_73 ;
unsigned int V_74 ;
int V_53 ;
T_3 V_54 ;
if ( ! V_75 )
return 0 ;
if ( ! V_70 || ! F_30 ( V_70 ) )
return 0 ;
V_72 = F_31 ( V_70 ) ;
V_73 = V_72 -> V_76 -> V_73 ;
V_74 = V_72 -> V_74 ;
V_54 = V_72 -> V_54 ;
V_56 . type = V_58 ;
V_56 . V_59 = V_60 ;
V_56 . V_61 = ( V_51 == V_77 ? 4 : 0x0c ) |
( V_50 == V_78 ? 1 : 3 ) ;
V_56 . V_62 = V_73 ;
V_56 . V_64 = ( ( ( V_74 >> 3 ) & 0x1f ) << 2 ) | ( ( V_54 - 1 ) & 3 ) ;
V_53 = F_23 ( V_52 ) ;
V_56 . V_65 = F_25 ( V_53 ) ;
V_56 . V_66 = F_24 ( V_53 , V_52 ) ;
F_26 ( & V_56 ) ;
#endif
return 0 ;
}
static int T_1
F_32 ( struct V_27 * V_14 , const unsigned long V_28 )
{
struct V_79 * V_53 = NULL ;
struct V_80 V_81 = {
. type = V_82 ,
. V_83 = & V_84 ,
} ;
V_53 = (struct V_79 * ) V_14 ;
if ( F_13 ( V_53 , V_28 ) )
return - V_9 ;
F_14 ( V_14 ) ;
if ( V_53 -> V_85 < F_27 () )
V_81 . type = V_86 ;
F_33 ( V_53 -> V_17 , V_53 -> V_11 , V_53 -> V_85 ,
& V_81 ) ;
return 0 ;
}
static void T_1 F_34 ( T_3 V_49 , T_4 V_50 , T_4 V_51 , T_2 V_52 )
{
if ( V_51 == 0 )
V_51 = 3 ;
if ( V_50 == 0 )
V_50 = 3 ;
if ( V_87 & V_88 )
V_51 = ( V_87 & V_88 ) >> 2 ;
if ( V_87 & V_89 )
V_50 = V_87 & V_89 ;
F_21 ( V_49 , V_50 , V_51 , V_52 ) ;
F_35 ( V_49 , V_51 , V_50 ) ;
V_90 = V_52 ;
return;
}
static int T_1
F_36 ( struct V_27 * V_14 ,
const unsigned long V_28 )
{
struct V_91 * V_92 = NULL ;
V_92 = (struct V_91 * ) V_14 ;
if ( F_13 ( V_92 , V_28 ) )
return - V_9 ;
F_14 ( V_14 ) ;
if ( V_92 -> V_93 == V_94 . V_95 ) {
F_34 ( V_92 -> V_93 ,
V_92 -> V_96 & V_89 ,
( V_92 -> V_96 & V_88 ) >> 2 ,
V_92 -> V_97 ) ;
return 0 ;
}
if ( V_92 -> V_93 == 0 ) {
if ( V_98 ) {
F_7 ( V_99 L_7 ) ;
return 0 ;
}
if ( ( V_92 -> V_97 == 2 ) && V_100
&& ( V_92 -> V_96 & V_89 ) ) {
V_92 -> V_96 &= ~ V_89 ;
F_7 ( V_99 L_8 ) ;
}
}
F_21 ( V_92 -> V_93 ,
V_92 -> V_96 & V_89 ,
( V_92 -> V_96 & V_88 ) >> 2 ,
V_92 -> V_97 ) ;
return 0 ;
}
static int T_1
F_37 ( struct V_27 * V_14 , const unsigned long V_28 )
{
struct V_101 * V_102 = NULL ;
V_102 = (struct V_101 * ) V_14 ;
if ( F_13 ( V_102 , V_28 ) )
return - V_9 ;
F_14 ( V_14 ) ;
return 0 ;
}
void T_1 F_38 ( unsigned int V_103 , T_4 V_51 )
{
unsigned int V_104 = 1 << V_103 ;
unsigned int V_105 , V_106 ;
V_105 = F_39 ( 0x4d0 ) | ( F_39 ( 0x4d1 ) << 8 ) ;
V_106 = V_107 ? V_105 : 0 ;
switch ( V_51 ) {
case 1 :
V_106 &= ~ V_104 ;
break;
case 3 :
V_106 |= V_104 ;
break;
}
if ( V_105 == V_106 )
return;
F_7 ( V_99 L_9 , V_106 , V_105 ) ;
F_40 ( V_106 , 0x4d0 ) ;
F_40 ( V_106 >> 8 , 0x4d1 ) ;
}
int F_41 ( T_2 V_52 , unsigned int * V_108 )
{
int V_109 , V_103 , V_51 , V_50 ;
if ( V_110 == V_111 ) {
* V_108 = V_52 ;
return 0 ;
}
V_109 = F_42 ( V_52 , & V_51 , & V_50 ) ;
if ( V_109 == 0 ) {
V_51 = V_51 ? V_112 : V_77 ;
V_50 = V_50 ? V_113 : V_78 ;
V_103 = F_43 ( NULL , V_52 , V_51 , V_50 ) ;
if ( V_103 >= 0 ) {
* V_108 = V_103 ;
return 0 ;
}
}
return - 1 ;
}
int F_44 ( unsigned V_114 , T_2 * V_52 )
{
if ( V_114 < F_27 () &&
V_67 [ V_114 ] != V_68 ) {
* V_52 = V_67 [ V_114 ] ;
return 0 ;
}
return - 1 ;
}
static int F_45 ( struct V_69 * V_70 , T_2 V_52 ,
int V_51 , int V_50 )
{
#ifdef F_46
if ( V_51 == V_112 )
F_47 ( V_52 ) ;
#endif
return V_52 ;
}
static int F_48 ( struct V_69 * V_70 , T_2 V_52 ,
int V_51 , int V_50 )
{
int V_103 = V_52 ;
#ifdef F_49
int V_115 ;
struct V_116 V_117 ;
V_115 = V_70 ? F_50 ( V_70 ) : V_118 ;
V_51 = V_51 == V_77 ? 0 : 1 ;
V_50 = V_50 == V_78 ? 0 : 1 ;
F_51 ( & V_117 , V_115 , V_51 , V_50 ) ;
F_52 ( & V_119 ) ;
V_103 = F_53 ( V_52 , V_120 , & V_117 ) ;
if ( V_103 >= 0 && V_121 &&
V_94 . V_95 != V_52 )
F_28 ( V_70 , V_52 , V_51 , V_50 ) ;
F_54 ( & V_119 ) ;
#endif
return V_103 ;
}
static void F_55 ( T_2 V_52 )
{
#ifdef F_49
int V_103 ;
F_52 ( & V_119 ) ;
V_103 = F_53 ( V_52 , 0 , NULL ) ;
if ( V_103 > 0 )
F_56 ( V_103 ) ;
F_54 ( & V_119 ) ;
#endif
}
int F_43 ( struct V_69 * V_70 , T_2 V_52 , int V_51 , int V_50 )
{
return F_57 ( V_70 , V_52 , V_51 , V_50 ) ;
}
void F_58 ( T_2 V_52 )
{
if ( V_122 )
V_122 ( V_52 ) ;
}
static void T_1 F_59 ( void )
{
V_110 = V_123 ;
F_57 = F_48 ;
V_122 = F_55 ;
V_75 = 1 ;
}
static int F_60 ( T_5 V_124 , int V_21 , int V_125 )
{
#ifdef F_61
int V_126 ;
V_126 = F_62 ( V_124 ) ;
if ( V_126 != V_118 ) {
F_63 ( V_125 , V_126 ) ;
F_64 ( V_21 , V_126 ) ;
}
#endif
return 0 ;
}
int F_65 ( T_5 V_124 , T_6 V_125 , T_2 V_127 ,
int * V_128 )
{
int V_21 ;
V_21 = F_9 ( V_125 , V_127 , V_34 ) ;
if ( V_21 < 0 ) {
F_66 ( V_99 L_10 ) ;
return V_21 ;
}
F_67 ( V_124 ) ;
F_60 ( V_124 , V_21 , V_125 ) ;
* V_128 = V_21 ;
return 0 ;
}
int F_68 ( int V_21 )
{
#ifdef F_61
F_63 ( F_69 ( V_129 , V_21 ) , V_118 ) ;
#endif
F_69 ( V_129 , V_21 ) = - 1 ;
F_70 ( V_21 , false ) ;
V_130 -- ;
return ( 0 ) ;
}
int F_71 ( T_5 V_124 , V_13 V_131 , T_2 V_132 )
{
int V_133 = - V_134 ;
#ifdef F_72
int V_135 ;
V_13 V_136 ;
struct V_80 V_81 = {
. type = V_82 ,
. V_83 = & V_84 ,
} ;
V_135 = F_73 ( V_124 , V_132 , & V_136 ) ;
if ( V_135 < 0 ) {
unsigned long long V_37 ;
T_7 V_137 ;
V_137 = F_74 ( V_124 , V_138 ,
NULL , & V_37 ) ;
if ( F_75 ( V_137 ) ) {
F_76 ( V_124 , L_11 ) ;
return - V_9 ;
}
V_135 = ( int ) V_37 ;
}
F_52 ( & V_119 ) ;
V_133 = F_33 ( V_135 , V_131 , V_132 , & V_81 ) ;
F_54 ( & V_119 ) ;
#endif
return V_133 ;
}
int F_77 ( T_5 V_124 , T_2 V_132 )
{
int V_133 = - V_134 ;
#ifdef F_72
F_52 ( & V_119 ) ;
V_133 = F_78 ( V_132 ) ;
F_54 ( & V_119 ) ;
#endif
return V_133 ;
}
int F_79 ( T_5 V_124 , T_2 V_132 )
{
int V_133 = 0 ;
#ifdef F_72
F_52 ( & V_119 ) ;
V_133 = F_80 ( V_132 ) ;
F_54 ( & V_119 ) ;
#endif
return V_133 ;
}
static int T_1 F_81 ( struct V_4 * V_5 )
{
struct V_139 * V_140 = (struct V_139 * ) V_5 ;
V_141 = V_140 -> V_142 ;
return 0 ;
}
static int T_1 F_82 ( struct V_4 * V_5 )
{
struct V_143 * V_144 = (struct V_143 * ) V_5 ;
if ( V_144 -> V_11 . V_145 != V_146 ) {
F_7 (KERN_WARNING PREFIX L_12
L_13 ) ;
return - 1 ;
}
V_147 = V_144 -> V_11 . V_11 ;
V_148 = V_144 -> V_149 ;
if ( ! V_147 ) {
F_7 (KERN_WARNING PREFIX
L_14 ,
hpet_tbl->id, hpet_address) ;
return 0 ;
}
#ifdef F_83
if ( V_147 == 0xfed0000000000000UL ) {
if ( ! V_150 ) {
F_7 (KERN_WARNING PREFIX L_15
L_16
L_17
L_18 , hpet_tbl->id) ;
V_147 = 0 ;
return 0 ;
}
F_7 (KERN_WARNING PREFIX
L_19
L_20 , hpet_tbl->id) ;
V_147 >>= 32 ;
}
#endif
F_7 (KERN_INFO PREFIX L_21 ,
hpet_tbl->id, hpet_address) ;
#define F_84 9
V_151 = F_85 ( sizeof( * V_151 ) + F_84 ) ;
V_151 -> V_152 = ( void * ) & V_151 [ 1 ] ;
V_151 -> V_153 = V_154 ;
snprintf ( ( char * ) V_151 -> V_152 , F_84 , L_22 ,
V_144 -> V_149 ) ;
V_151 -> V_155 = V_147 ;
V_151 -> V_28 = V_147 + ( 1 * 1024 ) - 1 ;
return 0 ;
}
static T_1 int F_86 ( void )
{
if ( ! V_151 )
return 1 ;
return F_87 ( & V_156 , V_151 ) ;
}
static int T_1 F_88 ( struct V_4 * V_5 )
{
if ( ! ( V_94 . V_157 & V_158 ) ) {
F_89 ( L_23 ) ;
V_159 . V_160 . V_161 . V_162 = 0 ;
}
if ( V_94 . V_14 . V_163 >= V_164 &&
! ( V_94 . V_157 & V_165 ) &&
V_159 . V_160 . V_166 != V_167 ) {
F_89 ( L_24 ) ;
V_159 . V_160 . V_166 = V_168 ;
}
if ( V_94 . V_157 & V_169 ) {
F_89 ( L_25 ) ;
V_159 . V_160 . V_170 = 0 ;
}
#ifdef F_90
if ( V_94 . V_14 . V_163 >= V_164 ) {
if ( V_94 . V_171 . V_145 !=
V_172 )
return 0 ;
V_173 = V_94 . V_171 . V_11 ;
if ( ! V_173 )
V_173 = V_94 . V_174 ;
} else {
V_173 = V_94 . V_174 ;
}
if ( V_173 )
F_7 (KERN_INFO PREFIX L_26 ,
pmtmr_ioport) ;
#endif
return 0 ;
}
static int T_1 F_91 ( void )
{
int V_175 ;
if ( ! F_6 ( V_8 ) )
return - V_10 ;
V_175 = F_92 ( V_176 ,
F_18 , 0 ) ;
if ( V_175 < 0 ) {
F_7 (KERN_ERR PREFIX
L_27 ) ;
return V_175 ;
}
F_93 ( V_12 ) ;
return V_175 ;
}
static int T_1 F_94 ( void )
{
int V_175 ;
int V_177 = 0 ;
int V_133 ;
struct V_178 V_179 [ 2 ] ;
if ( ! F_6 ( V_8 ) )
return - V_10 ;
V_175 = F_92 ( V_180 ,
F_17 , V_22 ) ;
if ( ! V_175 ) {
memset ( V_179 , 0 , sizeof( V_179 ) ) ;
V_179 [ 0 ] . V_17 = V_181 ;
V_179 [ 0 ] . V_182 = F_16 ;
V_179 [ 1 ] . V_17 = V_183 ;
V_179 [ 1 ] . V_182 = F_12 ;
V_133 = F_95 ( V_184 ,
sizeof( struct V_6 ) ,
V_179 , F_96 ( V_179 ) , V_22 ) ;
if ( V_133 < 0 ) {
F_7 (KERN_ERR PREFIX
L_28 ) ;
return V_133 ;
}
V_175 = V_179 [ 0 ] . V_175 ;
V_177 = V_179 [ 1 ] . V_175 ;
}
if ( ! V_175 && ! V_177 ) {
F_7 (KERN_ERR PREFIX L_29 ) ;
return - V_10 ;
} else if ( V_175 < 0 || V_177 < 0 ) {
F_7 (KERN_ERR PREFIX L_30 ) ;
return V_175 ;
}
V_177 = F_92 ( V_185 ,
F_19 , 0 ) ;
V_175 = F_92 ( V_186 ,
F_20 , 0 ) ;
if ( V_175 < 0 || V_177 < 0 ) {
F_7 (KERN_ERR PREFIX L_31 ) ;
return V_175 ;
}
return 0 ;
}
static void T_1 F_97 ( void )
{
int V_187 ;
struct V_55 V_56 ;
#ifdef F_98
V_188 [ V_63 ] = V_189 ;
#endif
F_99 ( V_63 , V_190 ) ;
F_89 ( L_32 , V_63 ) ;
for ( V_187 = 0 ; V_187 < F_27 () ; V_187 ++ ) {
int V_53 , V_54 ;
unsigned int V_65 ;
int V_191 ;
T_2 V_52 ;
if ( F_44 ( V_187 , & V_52 ) )
continue;
V_53 = F_23 ( V_52 ) ;
if ( V_53 < 0 )
continue;
V_54 = F_24 ( V_53 , V_52 ) ;
V_65 = F_25 ( V_53 ) ;
for ( V_191 = 0 ; V_191 < V_192 ; V_191 ++ ) {
struct V_55 * V_103 = V_193 + V_191 ;
if ( V_103 -> V_62 == V_63 && V_103 -> V_64 == V_187 )
break;
if ( V_103 -> V_65 == V_65 && V_103 -> V_66 == V_54 )
break;
}
if ( V_191 != V_192 ) {
F_7 ( V_194 L_33 , V_187 ) ;
continue;
}
V_56 . type = V_58 ;
V_56 . V_61 = 0 ;
V_56 . V_62 = V_63 ;
V_56 . V_65 = V_65 ;
V_56 . V_59 = V_60 ;
V_56 . V_64 = V_187 ;
V_56 . V_66 = V_54 ;
F_26 ( & V_56 ) ;
}
}
static int T_1 F_100 ( void )
{
int V_175 ;
if ( V_195 || V_107 )
return - V_10 ;
if ( ! F_6 ( V_8 ) )
return - V_10 ;
if ( V_196 ) {
F_7 (KERN_INFO PREFIX L_34
L_35 ) ;
return - V_10 ;
}
V_175 = F_92 ( V_197 , F_32 ,
V_198 ) ;
if ( ! V_175 ) {
F_7 (KERN_ERR PREFIX L_36 ) ;
return - V_10 ;
} else if ( V_175 < 0 ) {
F_7 (KERN_ERR PREFIX L_37 ) ;
return V_175 ;
}
V_175 = F_92 ( V_199 ,
F_36 , V_200 ) ;
if ( V_175 < 0 ) {
F_7 (KERN_ERR PREFIX
L_38 ) ;
return V_175 ;
}
if ( ! V_90 )
F_34 ( V_94 . V_95 , 0 , 0 ,
V_94 . V_95 ) ;
F_97 () ;
V_175 = F_92 ( V_201 ,
F_37 , V_200 ) ;
if ( V_175 < 0 ) {
F_7 (KERN_ERR PREFIX L_39 ) ;
return V_175 ;
}
return 0 ;
}
static inline int F_100 ( void )
{
return - 1 ;
}
static void T_1 F_101 ( void )
{
#ifdef F_102
int error ;
if ( ! F_103 ( V_184 , F_5 ) ) {
error = F_91 () ;
if ( ! error ) {
V_202 = 1 ;
V_203 = 1 ;
}
if ( error == - V_9 ) {
F_7 (KERN_ERR PREFIX
L_40 ) ;
F_104 () ;
}
}
#endif
}
static void T_1 F_105 ( void )
{
#ifdef F_102
int error ;
if ( ! F_103 ( V_184 , F_5 ) ) {
error = F_94 () ;
if ( ! error ) {
V_202 = 1 ;
F_52 ( & V_119 ) ;
error = F_100 () ;
F_54 ( & V_119 ) ;
if ( ! error ) {
F_59 () ;
V_203 = 1 ;
}
}
if ( error == - V_9 ) {
F_7 (KERN_ERR PREFIX
L_40 ) ;
F_104 () ;
}
} else {
if ( V_203 ) {
F_7 (KERN_WARNING PREFIX
L_41 ) ;
V_203 = 0 ;
}
}
if ( V_202 && V_75 )
F_7 ( V_204 L_42
L_43 ) ;
else if ( V_202 )
F_7 ( V_204 L_44
L_45 ) ;
#endif
return;
}
static int T_1 F_106 ( const struct V_205 * V_206 )
{
if ( ! V_207 ) {
F_7 ( V_208 L_46 ,
V_206 -> V_209 ) ;
F_107 () ;
}
return 0 ;
}
static int T_1 F_108 ( const struct V_205 * V_206 )
{
if ( ! V_207 ) {
F_7 ( V_208 L_47 ,
V_206 -> V_209 ) ;
F_109 () ;
}
return 0 ;
}
static int T_1 F_110 ( const struct V_205 * V_206 )
{
if ( ! V_207 ) {
F_7 ( V_208 L_48 , V_206 -> V_209 ) ;
F_104 () ;
} else {
F_7 ( V_208
L_49 ) ;
}
return 0 ;
}
static int T_1 F_111 ( const struct V_205 * V_206 )
{
if ( ! V_98 ) {
F_112 ( L_50 ,
V_206 -> V_209 ) ;
V_98 = 1 ;
}
return 0 ;
}
static void T_1 F_113 ( void )
{
if ( V_210 ) {
V_211 . V_212 . V_213 = V_214 ;
V_211 . V_215 . V_216 = V_214 ;
V_217 = & V_218 ;
}
}
void T_1 F_114 ( void )
{
F_115 ( V_219 ) ;
if ( V_195 )
return;
if ( F_116 () ) {
F_104 () ;
return;
}
F_103 ( V_220 , F_81 ) ;
if ( F_117 () ) {
if ( V_207 ) {
F_7 (KERN_WARNING PREFIX L_51 ) ;
} else {
F_7 (KERN_WARNING PREFIX L_52 ) ;
F_104 () ;
return;
}
}
}
int T_1 F_118 ( void )
{
if ( V_195 )
return 1 ;
F_101 () ;
F_113 () ;
return 0 ;
}
int T_1 F_119 ( void )
{
F_115 ( V_221 ) ;
if ( V_195 )
return 1 ;
F_103 ( V_220 , F_81 ) ;
F_103 ( V_222 , F_88 ) ;
F_105 () ;
F_103 ( V_223 , F_82 ) ;
if ( F_120 ( V_224 ) )
F_103 ( V_225 , V_226 ) ;
if ( ! V_107 )
V_211 . V_227 . V_228 = V_229 ;
return 0 ;
}
static int T_1 F_121 ( char * V_230 )
{
if ( ! V_230 )
return - V_9 ;
if ( strcmp ( V_230 , L_53 ) == 0 ) {
F_104 () ;
}
else if ( strcmp ( V_230 , L_54 ) == 0 ) {
V_207 = 1 ;
V_195 = 0 ;
}
else if ( strcmp ( V_230 , L_55 ) == 0 ) {
V_231 = 1 ;
}
else if ( strcmp ( V_230 , L_56 ) == 0 ) {
V_232 = TRUE ;
}
else if ( strcmp ( V_230 , L_57 ) == 0 ) {
F_107 () ;
}
else if ( strcmp ( V_230 , L_58 ) == 0 ) {
V_233 = 1 ;
}
else if ( strcmp ( V_230 , L_59 ) == 0 ) {
V_234 = 1 ;
} else {
return - V_9 ;
}
return 0 ;
}
static int T_1 F_122 ( char * V_230 )
{
if ( V_230 && strcmp ( V_230 , L_60 ) == 0 )
F_109 () ;
return 0 ;
}
int T_1 F_123 ( void )
{
#if F_124 ( F_102 ) && ! F_124 ( F_29 )
if ( V_195 || V_107 ) {
F_7 ( V_235 L_61
L_62
L_63 ) ;
return 1 ;
}
#endif
return 0 ;
}
static int T_1 F_125 ( char * V_230 )
{
V_98 = 1 ;
return 0 ;
}
static int T_1 F_126 ( char * V_230 )
{
V_236 = 1 ;
return 0 ;
}
static int T_1 F_127 ( char * V_237 )
{
if ( ! V_237 )
return - V_9 ;
if ( ! strcmp ( V_237 , L_64 ) )
V_87 = V_238 |
( V_87 & ~ V_88 ) ;
else if ( ! strcmp ( V_237 , L_65 ) )
V_87 = V_239 |
( V_87 & ~ V_88 ) ;
else if ( ! strcmp ( V_237 , L_66 ) )
V_87 = V_240 |
( V_87 & ~ V_89 ) ;
else if ( ! strcmp ( V_237 , L_67 ) )
V_87 = V_241 |
( V_87 & ~ V_89 ) ;
else
return - V_9 ;
return 0 ;
}
int F_128 ( unsigned int * V_242 )
{
unsigned int V_105 , V_106 , V_243 ;
do {
V_105 = * V_242 ;
V_106 = ( ( ( V_105 & ~ 0x3 ) + 2 ) + ( ( V_105 >> 1 ) & 0x1 ) ) ;
V_243 = F_129 ( V_242 , V_105 , V_106 ) ;
} while ( F_130 ( V_243 != V_105 ) );
return ( V_106 < 3 ) ? - 1 : 0 ;
}
int F_131 ( unsigned int * V_242 )
{
unsigned int V_105 , V_106 , V_243 ;
do {
V_105 = * V_242 ;
V_106 = V_105 & ~ 0x3 ;
V_243 = F_129 ( V_242 , V_105 , V_106 ) ;
} while ( F_130 ( V_243 != V_105 ) );
return V_105 & 0x1 ;
}
void T_1 F_132 ( T_8 V_136 , T_9 V_2 )
{
F_133 ( V_136 , V_2 , V_244 ) ;
F_134 () ;
}
