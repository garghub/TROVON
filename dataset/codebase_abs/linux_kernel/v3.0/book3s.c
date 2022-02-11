void F_1 ( struct V_1 * V_2 )
{
}
void F_2 ( struct V_1 * V_2 )
{
}
void F_3 ( struct V_1 * V_2 , int V_3 )
{
#ifdef F_4
memcpy ( F_5 ( V_2 ) -> V_4 , F_6 ( V_2 ) -> V_5 , sizeof( F_5 ( V_2 ) -> V_4 ) ) ;
memcpy ( & F_7 () -> V_6 , F_6 ( V_2 ) -> V_6 ,
sizeof( F_7 () -> V_6 ) ) ;
F_5 ( V_2 ) -> V_7 = F_6 ( V_2 ) -> V_8 ;
#endif
#ifdef F_8
V_9 -> V_10 . V_11 = F_6 ( V_2 ) -> V_6 ;
#endif
}
void F_9 ( struct V_1 * V_2 )
{
#ifdef F_4
memcpy ( F_6 ( V_2 ) -> V_5 , F_5 ( V_2 ) -> V_4 , sizeof( F_5 ( V_2 ) -> V_4 ) ) ;
memcpy ( F_6 ( V_2 ) -> V_6 , & F_7 () -> V_6 ,
sizeof( F_7 () -> V_6 ) ) ;
F_6 ( V_2 ) -> V_8 = F_5 ( V_2 ) -> V_7 ;
#endif
F_10 ( V_2 , V_12 ) ;
F_10 ( V_2 , V_13 ) ;
F_10 ( V_2 , V_14 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
T_1 V_15 = V_2 -> V_16 . V_17 -> V_18 ;
V_15 &= V_19 | V_20 | V_21 | V_22 | V_23 | V_24 ;
V_15 |= V_25 | V_26 | V_27 | V_28 | V_29 | V_30 ;
V_15 |= ( V_2 -> V_16 . V_17 -> V_18 & V_2 -> V_16 . V_31 ) ;
#ifdef F_4
V_15 |= V_32 | V_33 ;
#endif
V_2 -> V_16 . V_34 = V_15 ;
}
void F_12 ( struct V_1 * V_2 , T_2 V_18 )
{
T_1 V_35 = V_2 -> V_16 . V_17 -> V_18 ;
#ifdef F_13
F_14 ( V_36 L_1 , V_18 ) ;
#endif
V_18 &= F_6 ( V_2 ) -> V_37 ;
V_2 -> V_16 . V_17 -> V_18 = V_18 ;
F_11 ( V_2 ) ;
if ( V_18 & V_38 ) {
if ( ! V_2 -> V_16 . V_39 ) {
F_15 ( V_2 ) ;
V_2 -> V_40 . V_41 ++ ;
V_18 &= ~ V_38 ;
V_2 -> V_16 . V_17 -> V_18 = V_18 ;
}
}
if ( ( V_2 -> V_16 . V_17 -> V_18 & ( V_29 | V_27 | V_28 ) ) !=
( V_35 & ( V_29 | V_27 | V_28 ) ) ) {
F_16 ( V_2 ) ;
F_17 ( V_2 , F_18 ( V_2 ) ) ;
if ( ! ( V_18 & V_29 ) && V_2 -> V_16 . V_42 ) {
struct V_43 * V_44 = & V_2 -> V_16 ;
if ( V_18 & V_28 )
F_17 ( V_2 , V_44 -> V_45 ) ;
else
F_17 ( V_2 , V_44 -> V_42 ) ;
}
}
if ( V_2 -> V_16 . V_17 -> V_18 & V_12 )
F_19 ( V_2 , V_46 , V_12 ) ;
}
void F_20 ( struct V_1 * V_2 , int V_47 , T_2 V_48 )
{
V_2 -> V_16 . V_17 -> V_49 = F_18 ( V_2 ) ;
V_2 -> V_16 . V_17 -> V_50 = V_2 -> V_16 . V_17 -> V_18 | V_48 ;
F_21 ( V_2 , F_6 ( V_2 ) -> V_51 + V_47 ) ;
V_2 -> V_16 . V_52 . V_53 ( V_2 ) ;
}
static int F_22 ( unsigned int V_47 )
{
unsigned int V_54 ;
switch ( V_47 ) {
case 0x100 : V_54 = V_55 ; break;
case 0x200 : V_54 = V_56 ; break;
case 0x300 : V_54 = V_57 ; break;
case 0x380 : V_54 = V_58 ; break;
case 0x400 : V_54 = V_59 ; break;
case 0x480 : V_54 = V_60 ; break;
case 0x500 : V_54 = V_61 ; break;
case 0x501 : V_54 = V_62 ; break;
case 0x600 : V_54 = V_63 ; break;
case 0x700 : V_54 = V_64 ; break;
case 0x800 : V_54 = V_65 ; break;
case 0x900 : V_54 = V_66 ; break;
case 0xc00 : V_54 = V_67 ; break;
case 0xd00 : V_54 = V_68 ; break;
case 0xf20 : V_54 = V_69 ; break;
case 0xf40 : V_54 = V_70 ; break;
default: V_54 = V_71 ; break;
}
return V_54 ;
}
static void F_23 ( struct V_1 * V_2 ,
unsigned int V_47 )
{
F_24 ( F_22 ( V_47 ) ,
& V_2 -> V_16 . V_39 ) ;
if ( ! V_2 -> V_16 . V_39 )
V_2 -> V_16 . V_17 -> V_72 = 0 ;
}
void F_25 ( struct V_1 * V_2 , unsigned int V_47 )
{
V_2 -> V_40 . V_73 ++ ;
F_26 ( F_22 ( V_47 ) ,
& V_2 -> V_16 . V_39 ) ;
#ifdef F_13
F_14 ( V_36 L_2 , V_47 ) ;
#endif
}
void F_27 ( struct V_1 * V_2 , T_1 V_48 )
{
F_6 ( V_2 ) -> V_74 = V_48 ;
F_25 ( V_2 , V_75 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
F_25 ( V_2 , V_76 ) ;
}
int F_29 ( struct V_1 * V_2 )
{
return F_30 ( V_66 , & V_2 -> V_16 . V_39 ) ;
}
void F_31 ( struct V_1 * V_2 )
{
F_23 ( V_2 , V_76 ) ;
}
void F_32 ( struct V_1 * V_2 ,
struct V_77 * V_78 )
{
unsigned int V_47 = V_79 ;
if ( V_78 -> V_78 == V_80 )
V_47 = V_81 ;
F_25 ( V_2 , V_47 ) ;
}
void F_33 ( struct V_1 * V_2 ,
struct V_77 * V_78 )
{
F_23 ( V_2 , V_79 ) ;
F_23 ( V_2 , V_81 ) ;
}
int F_34 ( struct V_1 * V_2 , unsigned int V_82 )
{
int V_83 = 1 ;
int V_47 = 0 ;
T_1 V_48 = 0ULL ;
T_1 V_84 = V_2 -> V_16 . V_17 -> V_85 ;
T_1 V_86 = F_35 ( V_2 , 1 ) ;
bool V_87 ;
if ( ! ( V_2 -> V_16 . V_17 -> V_18 & V_21 ) ) {
V_84 &= 0xffffffff ;
V_86 &= 0xffffffff ;
}
V_87 = ( V_84 == V_86 ) ;
V_87 = V_87 && ! ( V_2 -> V_16 . V_17 -> V_18 & V_29 ) ;
switch ( V_82 ) {
case V_66 :
V_83 = ( V_2 -> V_16 . V_17 -> V_18 & V_30 ) && ! V_87 ;
V_47 = V_76 ;
break;
case V_61 :
case V_62 :
V_83 = ( V_2 -> V_16 . V_17 -> V_18 & V_30 ) && ! V_87 ;
V_47 = V_79 ;
break;
case V_55 :
V_47 = V_88 ;
break;
case V_56 :
V_47 = V_89 ;
break;
case V_57 :
V_47 = V_90 ;
break;
case V_59 :
V_47 = V_91 ;
break;
case V_58 :
V_47 = V_92 ;
break;
case V_60 :
V_47 = V_93 ;
break;
case V_63 :
V_47 = V_94 ;
break;
case V_64 :
V_47 = V_75 ;
V_48 = F_6 ( V_2 ) -> V_74 ;
break;
case V_70 :
V_47 = V_95 ;
break;
case V_69 :
V_47 = V_96 ;
break;
case V_65 :
V_47 = V_46 ;
break;
case V_67 :
V_47 = V_97 ;
break;
case V_68 :
V_47 = V_98 ;
break;
case V_99 :
V_47 = V_100 ;
break;
default:
V_83 = 0 ;
F_14 ( V_101 L_3 , V_82 ) ;
break;
}
#if 0
printk(KERN_INFO "Deliver interrupt 0x%x? %x\n", vec, deliver);
#endif
if ( V_83 )
F_20 ( V_2 , V_47 , V_48 ) ;
return V_83 ;
}
static bool F_36 ( struct V_1 * V_2 , unsigned int V_82 )
{
switch ( V_82 ) {
case V_66 :
return false ;
case V_62 :
return false ;
}
return true ;
}
void F_37 ( struct V_1 * V_2 )
{
unsigned long * V_102 = & V_2 -> V_16 . V_39 ;
unsigned long V_103 = V_2 -> V_16 . V_39 ;
unsigned int V_82 ;
#ifdef F_13
if ( V_2 -> V_16 . V_39 )
F_14 ( V_104 L_4 , V_2 -> V_16 . V_39 ) ;
#endif
V_82 = F_38 ( * V_102 ) ;
while ( V_82 < V_71 ) {
if ( F_34 ( V_2 , V_82 ) &&
F_36 ( V_2 , V_82 ) ) {
F_24 ( V_82 , & V_2 -> V_16 . V_39 ) ;
break;
}
V_82 = F_39 ( V_102 ,
V_105 * sizeof( * V_102 ) ,
V_82 + 1 ) ;
}
if ( * V_102 )
V_2 -> V_16 . V_17 -> V_72 = 1 ;
else if ( V_103 )
V_2 -> V_16 . V_17 -> V_72 = 0 ;
}
void F_40 ( struct V_1 * V_2 , T_3 V_106 )
{
T_3 V_107 ;
V_2 -> V_16 . V_108 &= ~ V_109 ;
V_2 -> V_16 . V_106 = V_106 ;
#ifdef F_4
if ( ( V_106 >= 0x330000 ) && ( V_106 < 0x70330000 ) ) {
F_41 ( V_2 ) ;
F_6 ( V_2 ) -> V_51 = 0xfff00000 ;
F_6 ( V_2 ) -> V_37 = 0xffffffffffffffffULL ;
} else
#endif
{
F_42 ( V_2 ) ;
F_6 ( V_2 ) -> V_51 = 0 ;
F_6 ( V_2 ) -> V_37 = 0xffffffffULL ;
}
V_2 -> V_16 . V_108 &= ~ V_110 ;
if ( V_2 -> V_16 . V_52 . V_111 ( V_2 ) && ( F_43 () & V_33 ) &&
! strcmp ( V_112 -> V_113 , L_5 ) )
V_2 -> V_16 . V_108 |= V_110 ;
if ( ! strcmp ( V_112 -> V_113 , L_6 ) )
F_6 ( V_2 ) -> V_37 &= ~ ( V_19 | V_20 ) ;
#ifdef F_8
V_2 -> V_16 . V_108 |= V_110 ;
#endif
asm ( "mfpvr %0" : "=r"(host_pvr));
switch ( V_107 ) {
case 0x00080200 :
case 0x00088202 :
case 0x70000100 :
case 0x00080100 :
case 0x00083203 :
case 0x00083213 :
case 0x00083204 :
case 0x00083214 :
case 0x00087200 :
V_2 -> V_16 . V_108 |= V_114 ;
F_44 ( V_115 , F_45 ( V_115 ) | ( 1 << 29 ) ) ;
}
}
T_4 F_46 ( struct V_1 * V_2 , T_5 V_116 )
{
T_1 V_117 = V_2 -> V_16 . V_42 ;
if ( F_47 ( V_117 ) &&
F_47 ( ( ( V_116 << V_118 ) & V_119 ) ==
( ( V_117 & V_120 ) & V_119 ) ) ) {
T_1 V_121 = ( ( T_1 ) V_2 -> V_16 . V_17 ) & V_120 ;
T_4 V_122 ;
V_122 = ( T_4 ) F_48 ( ( void * ) V_121 ) >> V_118 ;
F_49 ( F_50 ( V_122 ) ) ;
return V_122 ;
}
return F_51 ( V_2 -> V_123 , V_116 ) ;
}
static void F_52 ( struct V_1 * V_2 , struct V_124 * V_125 )
{
struct V_126 * V_127 ;
T_2 V_128 ;
T_3 * V_126 ;
int V_129 ;
V_127 = F_53 ( V_2 -> V_123 , V_125 -> V_130 >> V_118 ) ;
if ( F_54 ( V_127 ) ) {
F_55 ( V_127 ) ;
return;
}
V_128 = V_125 -> V_130 & ~ V_120 ;
V_128 &= ~ 0xFFFULL ;
V_128 /= 4 ;
F_49 ( V_127 ) ;
V_126 = F_56 ( V_127 , V_131 ) ;
for ( V_129 = V_128 ; V_129 < V_128 + ( V_132 / 4 ) ; V_129 ++ )
if ( ( V_126 [ V_129 ] & 0xff0007ff ) == V_133 )
V_126 [ V_129 ] &= 0xfffffff7 ;
F_57 ( V_126 , V_131 ) ;
F_58 ( V_127 ) ;
}
static int F_59 ( struct V_1 * V_2 , T_1 V_134 , bool V_135 ,
struct V_124 * V_125 )
{
int V_136 = ( V_2 -> V_16 . V_17 -> V_18 & ( V_135 ? V_28 : V_27 ) ) ;
int V_137 ;
if ( V_136 ) {
V_137 = V_2 -> V_16 . V_52 . V_138 ( V_2 , V_134 , V_125 , V_135 ) ;
} else {
V_125 -> V_134 = V_134 ;
V_125 -> V_130 = V_134 & V_119 ;
V_125 -> V_139 = V_140 | V_134 >> 12 ;
V_125 -> V_141 = true ;
V_125 -> V_142 = true ;
V_125 -> V_143 = true ;
V_137 = 0 ;
}
return V_137 ;
}
static T_6 F_60 ( void )
{
return V_144 ;
}
static T_6 F_61 ( struct V_1 * V_2 , struct V_124 * V_125 ,
bool V_145 )
{
T_6 V_127 ;
if ( V_145 && ! V_125 -> V_141 )
goto V_146;
if ( ! V_145 && ! V_125 -> V_142 )
goto V_146;
V_127 = F_62 ( V_2 -> V_123 , V_125 -> V_130 >> V_118 ) ;
if ( F_63 ( V_127 ) )
goto V_146;
return V_127 | ( V_125 -> V_130 & ~ V_120 ) ;
V_146:
return F_60 () ;
}
int F_64 ( struct V_1 * V_2 , T_1 * V_134 , int V_147 , void * V_148 ,
bool V_135 )
{
struct V_124 V_125 ;
V_2 -> V_40 . V_149 ++ ;
if ( F_59 ( V_2 , * V_134 , V_135 , & V_125 ) )
return - V_150 ;
* V_134 = V_125 . V_130 ;
if ( ! V_125 . V_142 )
return - V_151 ;
if ( F_65 ( V_2 -> V_123 , V_125 . V_130 , V_148 , V_147 ) )
return V_152 ;
return V_153 ;
}
int F_66 ( struct V_1 * V_2 , T_1 * V_134 , int V_147 , void * V_148 ,
bool V_135 )
{
struct V_124 V_125 ;
T_6 V_154 = * V_134 ;
V_2 -> V_40 . V_155 ++ ;
if ( F_59 ( V_2 , * V_134 , V_135 , & V_125 ) )
goto V_156;
* V_134 = V_125 . V_130 ;
V_154 = F_61 ( V_2 , & V_125 , true ) ;
if ( F_63 ( V_154 ) )
goto V_157;
if ( F_67 ( V_148 , ( void V_158 * ) V_154 , V_147 ) ) {
F_14 ( V_36 L_7 , V_154 ) ;
goto V_157;
}
return V_153 ;
V_156:
return - V_150 ;
V_157:
return V_152 ;
}
static int F_68 ( struct V_1 * V_2 , T_5 V_116 )
{
T_1 V_117 = V_2 -> V_16 . V_42 ;
if ( F_47 ( V_117 ) &&
F_47 ( ( V_117 & V_119 ) >> V_118 == V_116 ) ) {
return 1 ;
}
return F_69 ( V_2 -> V_123 , V_116 ) ;
}
int F_70 ( struct V_159 * V_160 , struct V_1 * V_2 ,
T_1 V_134 , int V_47 )
{
bool V_135 = ( V_47 == V_90 ) ;
int V_137 = V_161 ;
int V_136 ;
int V_162 = 0 ;
struct V_124 V_125 ;
bool V_163 = false ;
bool V_164 = ( V_2 -> V_16 . V_17 -> V_18 & V_28 ) ? true : false ;
bool V_165 = ( V_2 -> V_16 . V_17 -> V_18 & V_27 ) ? true : false ;
T_2 V_166 ;
V_136 = V_135 ? V_164 : V_165 ;
if ( V_136 ) {
V_162 = V_2 -> V_16 . V_52 . V_138 ( V_2 , V_134 , & V_125 , V_135 ) ;
} else {
V_125 . V_143 = true ;
V_125 . V_141 = true ;
V_125 . V_142 = true ;
V_125 . V_130 = V_134 & V_119 ;
V_125 . V_134 = V_134 ;
V_125 . V_139 = V_134 >> 12 ;
}
switch ( V_2 -> V_16 . V_17 -> V_18 & ( V_28 | V_27 ) ) {
case 0 :
V_125 . V_139 |= ( ( T_2 ) V_140 << ( V_167 - 12 ) ) ;
break;
case V_28 :
case V_27 :
V_2 -> V_16 . V_52 . V_168 ( V_2 , V_134 >> V_167 , & V_166 ) ;
if ( ( V_2 -> V_16 . V_17 -> V_18 & ( V_28 | V_27 ) ) == V_28 )
V_125 . V_139 |= ( ( T_2 ) V_169 << ( V_167 - 12 ) ) ;
else
V_125 . V_139 |= ( ( T_2 ) V_170 << ( V_167 - 12 ) ) ;
V_125 . V_139 |= V_166 ;
if ( V_166 == - 1 )
V_162 = - V_171 ;
break;
}
if ( V_2 -> V_16 . V_52 . V_111 ( V_2 ) &&
( ! ( V_2 -> V_16 . V_108 & V_110 ) ) ) {
V_125 . V_143 = ! V_135 ;
}
if ( V_162 == - V_150 ) {
V_2 -> V_16 . V_17 -> V_172 = F_71 ( V_2 ) ;
V_2 -> V_16 . V_17 -> V_173 = F_5 ( V_2 ) -> V_174 ;
V_2 -> V_16 . V_17 -> V_18 |=
( F_5 ( V_2 ) -> V_175 & 0x00000000f8000000ULL ) ;
F_25 ( V_2 , V_47 ) ;
} else if ( V_162 == - V_151 ) {
V_2 -> V_16 . V_17 -> V_172 = F_71 ( V_2 ) ;
V_2 -> V_16 . V_17 -> V_173 =
F_5 ( V_2 ) -> V_174 & ~ V_176 ;
V_2 -> V_16 . V_17 -> V_173 |= V_177 ;
V_2 -> V_16 . V_17 -> V_18 |=
( F_5 ( V_2 ) -> V_175 & 0x00000000f8000000ULL ) ;
F_25 ( V_2 , V_47 ) ;
} else if ( V_162 == - V_171 ) {
V_2 -> V_16 . V_17 -> V_172 = F_71 ( V_2 ) ;
F_25 ( V_2 , V_47 + 0x80 ) ;
} else if ( ! V_163 &&
F_68 ( V_2 , V_125 . V_130 >> V_118 ) ) {
F_72 ( V_2 , & V_125 ) ;
if ( V_135 )
V_2 -> V_40 . V_178 ++ ;
else if ( V_2 -> V_16 . V_52 . V_111 ( V_2 ) &&
( ! ( V_2 -> V_16 . V_108 & V_110 ) ) )
F_52 ( V_2 , & V_125 ) ;
} else {
V_2 -> V_40 . V_179 ++ ;
V_2 -> V_16 . V_180 = V_125 . V_130 ;
V_137 = F_73 ( V_160 , V_2 ) ;
if ( V_137 == V_181 )
V_137 = V_182 ;
}
return V_137 ;
}
static inline int F_74 ( int V_129 )
{
#ifdef F_75
V_129 *= 2 ;
#endif
return V_129 ;
}
void F_10 ( struct V_1 * V_2 , T_1 V_18 )
{
struct V_183 * V_184 = & V_9 -> V_10 ;
T_2 * V_185 = V_2 -> V_16 . V_186 ;
#ifdef F_75
T_2 * V_187 = V_2 -> V_16 . V_188 ;
#endif
T_2 * V_189 = ( T_2 * ) V_184 -> V_186 ;
int V_129 ;
if ( ! ( V_2 -> V_16 . V_31 & V_18 ) )
return;
#ifdef F_76
F_14 ( V_36 L_8 , V_18 ) ;
#endif
switch ( V_18 ) {
case V_12 :
F_77 ( V_9 ) ;
for ( V_129 = 0 ; V_129 < F_78 ( V_2 -> V_16 . V_186 ) ; V_129 ++ )
V_185 [ V_129 ] = V_189 [ F_74 ( V_129 ) ] ;
V_2 -> V_16 . V_190 = V_184 -> V_190 . V_191 ;
break;
case V_13 :
#ifdef F_79
F_80 ( V_9 ) ;
memcpy ( V_2 -> V_16 . V_192 , V_184 -> V_192 , sizeof( V_2 -> V_16 . V_192 ) ) ;
V_2 -> V_16 . V_193 = V_184 -> V_193 ;
#endif
break;
case V_14 :
#ifdef F_75
F_81 ( V_9 ) ;
for ( V_129 = 0 ; V_129 < F_78 ( V_2 -> V_16 . V_188 ) ; V_129 ++ )
V_187 [ V_129 ] = V_189 [ F_74 ( V_129 ) + 1 ] ;
#endif
break;
default:
F_82 () ;
}
V_2 -> V_16 . V_31 &= ~ V_18 ;
V_9 -> V_10 . V_194 -> V_18 &= ~ V_18 ;
F_11 ( V_2 ) ;
}
static int F_83 ( struct V_1 * V_2 )
{
T_1 V_49 = F_18 ( V_2 ) ;
T_3 V_195 = F_84 ( V_2 ) ;
int V_196 ;
V_196 = F_66 ( V_2 , & V_49 , sizeof( T_3 ) , & V_195 , false ) ;
if ( V_196 == - V_150 ) {
T_1 V_18 = V_2 -> V_16 . V_17 -> V_18 ;
V_18 = F_85 ( V_18 , 33 , 33 , 1 ) ;
V_18 = F_85 ( V_18 , 34 , 36 , 0 ) ;
V_2 -> V_16 . V_17 -> V_18 = F_85 ( V_18 , 42 , 47 , 0 ) ;
F_25 ( V_2 , V_91 ) ;
return V_197 ;
}
return V_153 ;
}
static int F_86 ( struct V_1 * V_2 , unsigned int V_198 )
{
if ( ! ( V_2 -> V_16 . V_108 & V_199 ) )
return V_153 ;
if ( F_83 ( V_2 ) == V_153 )
return V_200 ;
return V_197 ;
}
static int F_19 ( struct V_1 * V_2 , unsigned int V_198 ,
T_1 V_18 )
{
struct V_183 * V_184 = & V_9 -> V_10 ;
T_2 * V_185 = V_2 -> V_16 . V_186 ;
#ifdef F_75
T_2 * V_187 = V_2 -> V_16 . V_188 ;
#endif
T_2 * V_189 = ( T_2 * ) V_184 -> V_186 ;
int V_129 ;
if ( V_2 -> V_16 . V_108 & V_199 )
return V_161 ;
if ( ! ( V_2 -> V_16 . V_17 -> V_18 & V_18 ) ) {
F_25 ( V_2 , V_198 ) ;
return V_161 ;
}
if ( V_2 -> V_16 . V_31 & V_18 ) {
return V_161 ;
}
#ifdef F_76
F_14 ( V_36 L_9 , V_18 ) ;
#endif
V_9 -> V_10 . V_194 -> V_18 |= V_18 ;
switch ( V_18 ) {
case V_12 :
for ( V_129 = 0 ; V_129 < F_78 ( V_2 -> V_16 . V_186 ) ; V_129 ++ )
V_189 [ F_74 ( V_129 ) ] = V_185 [ V_129 ] ;
V_184 -> V_190 . V_191 = V_2 -> V_16 . V_190 ;
V_184 -> V_201 = 0 ;
F_87 () ;
break;
case V_13 :
#ifdef F_79
memcpy ( V_184 -> V_192 , V_2 -> V_16 . V_192 , sizeof( V_2 -> V_16 . V_192 ) ) ;
V_184 -> V_193 = V_2 -> V_16 . V_193 ;
V_184 -> V_202 = - 1 ;
F_88 () ;
#endif
break;
case V_14 :
#ifdef F_75
for ( V_129 = 0 ; V_129 < F_78 ( V_2 -> V_16 . V_188 ) ; V_129 ++ )
V_189 [ F_74 ( V_129 ) + 1 ] = V_187 [ V_129 ] ;
F_89 () ;
#endif
break;
default:
F_82 () ;
}
V_2 -> V_16 . V_31 |= V_18 ;
F_11 ( V_2 ) ;
return V_161 ;
}
int F_90 ( struct V_159 * V_160 , struct V_1 * V_2 ,
unsigned int V_198 )
{
int V_137 = V_182 ;
V_2 -> V_40 . V_203 ++ ;
V_160 -> V_204 = V_205 ;
V_160 -> V_206 = 1 ;
F_91 ( V_198 , V_2 ) ;
F_92 ( V_2 ) ;
switch ( V_198 ) {
case V_91 :
V_2 -> V_40 . V_207 ++ ;
#ifdef F_8
if ( F_5 ( V_2 ) -> V_208 [ F_18 ( V_2 ) >> V_167 ]
== V_209 ) {
F_17 ( V_2 , F_18 ( V_2 ) ) ;
V_137 = V_161 ;
break;
}
#endif
if ( F_5 ( V_2 ) -> V_175 & 0x40000000 ) {
V_137 = F_70 ( V_160 , V_2 , F_18 ( V_2 ) , V_198 ) ;
V_2 -> V_40 . V_210 ++ ;
} else if ( V_2 -> V_16 . V_52 . V_111 ( V_2 ) &&
( ! ( V_2 -> V_16 . V_108 & V_110 ) ) ) {
F_93 ( V_2 , F_18 ( V_2 ) , ~ 0xFFFUL ) ;
V_137 = V_161 ;
} else {
V_2 -> V_16 . V_17 -> V_18 |=
F_5 ( V_2 ) -> V_175 & 0x58000000 ;
F_25 ( V_2 , V_198 ) ;
V_137 = V_161 ;
}
break;
case V_90 :
{
T_1 V_172 = F_71 ( V_2 ) ;
V_2 -> V_40 . V_211 ++ ;
#ifdef F_8
if ( ( F_5 ( V_2 ) -> V_208 [ V_172 >> V_167 ] ) == V_209 ) {
F_17 ( V_2 , V_172 ) ;
V_137 = V_161 ;
break;
}
#endif
if ( F_5 ( V_2 ) -> V_174 & V_176 ) {
V_137 = F_70 ( V_160 , V_2 , V_172 , V_198 ) ;
} else {
V_2 -> V_16 . V_17 -> V_172 = V_172 ;
V_2 -> V_16 . V_17 -> V_173 = F_5 ( V_2 ) -> V_174 ;
F_25 ( V_2 , V_198 ) ;
V_137 = V_161 ;
}
break;
}
case V_92 :
if ( F_17 ( V_2 , F_71 ( V_2 ) ) < 0 ) {
V_2 -> V_16 . V_17 -> V_172 = F_71 ( V_2 ) ;
F_25 ( V_2 ,
V_92 ) ;
}
V_137 = V_161 ;
break;
case V_93 :
if ( F_17 ( V_2 , F_18 ( V_2 ) ) < 0 ) {
F_25 ( V_2 ,
V_93 ) ;
}
V_137 = V_161 ;
break;
case V_76 :
V_2 -> V_40 . V_212 ++ ;
V_137 = V_161 ;
break;
case V_79 :
V_2 -> V_40 . V_213 ++ ;
V_137 = V_161 ;
break;
case V_100 :
V_137 = V_161 ;
break;
case V_75 :
{
enum V_214 V_215 ;
T_1 V_48 ;
V_216:
V_48 = F_5 ( V_2 ) -> V_175 & 0x1f0000ull ;
if ( V_2 -> V_16 . V_17 -> V_18 & V_29 ) {
#ifdef F_13
F_14 ( V_36 L_10 , F_18 ( V_2 ) , F_84 ( V_2 ) ) ;
#endif
if ( ( F_84 ( V_2 ) & 0xff0007ff ) !=
( V_133 & 0xfffffff7 ) ) {
F_27 ( V_2 , V_48 ) ;
V_137 = V_161 ;
break;
}
}
V_2 -> V_40 . V_217 ++ ;
V_215 = F_94 ( V_160 , V_2 ) ;
switch ( V_215 ) {
case V_153 :
V_137 = V_218 ;
break;
case V_197 :
V_137 = V_161 ;
break;
case V_200 :
F_14 ( V_219 L_11 ,
V_220 , F_18 ( V_2 ) , F_84 ( V_2 ) ) ;
F_27 ( V_2 , V_48 ) ;
V_137 = V_161 ;
break;
case V_152 :
V_160 -> V_204 = V_221 ;
V_137 = V_181 ;
break;
default:
F_82 () ;
}
break;
}
case V_97 :
if ( V_2 -> V_16 . V_222 &&
( ( ( T_3 ) F_35 ( V_2 , 3 ) ) == V_223 ) &&
( ( ( T_3 ) F_35 ( V_2 , 4 ) ) == V_224 ) ) {
T_2 * V_225 = V_160 -> V_226 . V_225 ;
int V_129 ;
V_160 -> V_204 = V_227 ;
for ( V_129 = 0 ; V_129 < 32 ; V_129 ++ )
V_225 [ V_129 ] = F_35 ( V_2 , V_129 ) ;
V_2 -> V_16 . V_228 = 1 ;
V_137 = V_181 ;
} else if ( ! ( V_2 -> V_16 . V_17 -> V_18 & V_29 ) &&
( ( ( T_3 ) F_35 ( V_2 , 0 ) ) == V_229 ) ) {
F_95 ( V_2 , 3 , F_96 ( V_2 ) ) ;
V_137 = V_161 ;
} else {
V_2 -> V_40 . V_230 ++ ;
F_25 ( V_2 , V_198 ) ;
V_137 = V_161 ;
}
break;
case V_46 :
case V_96 :
case V_95 :
{
int V_231 = 0 ;
switch ( V_198 ) {
case V_46 : V_231 = V_12 ; break;
case V_96 : V_231 = V_13 ; break;
case V_95 : V_231 = V_14 ; break;
}
switch ( F_86 ( V_2 , V_198 ) ) {
case V_153 :
V_137 = F_19 ( V_2 , V_198 , V_231 ) ;
break;
case V_200 :
goto V_216;
break;
default:
break;
}
break;
}
case V_94 :
if ( F_83 ( V_2 ) == V_153 ) {
V_2 -> V_16 . V_17 -> V_173 = F_97 ( V_2 ,
F_84 ( V_2 ) ) ;
V_2 -> V_16 . V_17 -> V_172 = F_98 ( V_2 ,
F_84 ( V_2 ) ) ;
F_25 ( V_2 , V_198 ) ;
}
V_137 = V_161 ;
break;
case V_89 :
case V_98 :
F_25 ( V_2 , V_198 ) ;
V_137 = V_161 ;
break;
default:
F_14 ( V_104 L_12 ,
V_198 , F_18 ( V_2 ) , F_5 ( V_2 ) -> V_175 ) ;
V_137 = V_182 ;
F_82 () ;
break;
}
if ( ! ( V_137 & V_182 ) ) {
if ( F_99 ( V_9 ) ) {
#ifdef F_13
F_14 ( V_104 L_13 ) ;
#endif
V_2 -> V_40 . V_232 ++ ;
V_160 -> V_204 = V_233 ;
V_137 = - V_234 ;
} else {
F_37 ( V_2 ) ;
}
}
F_100 ( V_137 , V_2 ) ;
return V_137 ;
}
int F_101 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_102 ( struct V_1 * V_2 , struct V_235 * V_194 )
{
int V_129 ;
V_194 -> V_236 = F_18 ( V_2 ) ;
V_194 -> V_237 = F_103 ( V_2 ) ;
V_194 -> V_238 = F_104 ( V_2 ) ;
V_194 -> V_239 = F_105 ( V_2 ) ;
V_194 -> V_240 = F_106 ( V_2 ) ;
V_194 -> V_18 = V_2 -> V_16 . V_17 -> V_18 ;
V_194 -> V_49 = V_2 -> V_16 . V_17 -> V_49 ;
V_194 -> V_50 = V_2 -> V_16 . V_17 -> V_50 ;
V_194 -> V_241 = V_2 -> V_16 . V_241 ;
V_194 -> V_242 = V_2 -> V_16 . V_17 -> V_242 ;
V_194 -> V_243 = V_2 -> V_16 . V_17 -> V_243 ;
V_194 -> V_244 = V_2 -> V_16 . V_17 -> V_244 ;
V_194 -> V_245 = V_2 -> V_16 . V_17 -> V_245 ;
V_194 -> V_246 = V_2 -> V_16 . V_246 ;
V_194 -> V_247 = V_2 -> V_16 . V_247 ;
V_194 -> V_248 = V_2 -> V_16 . V_248 ;
V_194 -> V_249 = V_2 -> V_16 . V_249 ;
for ( V_129 = 0 ; V_129 < F_78 ( V_194 -> V_250 ) ; V_129 ++ )
V_194 -> V_250 [ V_129 ] = F_35 ( V_2 , V_129 ) ;
return 0 ;
}
int F_107 ( struct V_1 * V_2 , struct V_235 * V_194 )
{
int V_129 ;
F_21 ( V_2 , V_194 -> V_236 ) ;
F_108 ( V_2 , V_194 -> V_237 ) ;
F_109 ( V_2 , V_194 -> V_238 ) ;
F_110 ( V_2 , V_194 -> V_239 ) ;
F_111 ( V_2 , V_194 -> V_240 ) ;
F_12 ( V_2 , V_194 -> V_18 ) ;
V_2 -> V_16 . V_17 -> V_49 = V_194 -> V_49 ;
V_2 -> V_16 . V_17 -> V_50 = V_194 -> V_50 ;
V_2 -> V_16 . V_17 -> V_242 = V_194 -> V_242 ;
V_2 -> V_16 . V_17 -> V_243 = V_194 -> V_243 ;
V_2 -> V_16 . V_17 -> V_244 = V_194 -> V_244 ;
V_2 -> V_16 . V_17 -> V_245 = V_194 -> V_245 ;
V_2 -> V_16 . V_246 = V_194 -> V_246 ;
V_2 -> V_16 . V_247 = V_194 -> V_247 ;
V_2 -> V_16 . V_248 = V_194 -> V_248 ;
V_2 -> V_16 . V_249 = V_194 -> V_249 ;
for ( V_129 = 0 ; V_129 < F_78 ( V_194 -> V_250 ) ; V_129 ++ )
F_95 ( V_2 , V_129 , V_194 -> V_250 [ V_129 ] ) ;
return 0 ;
}
int F_112 ( struct V_1 * V_2 ,
struct V_251 * V_252 )
{
struct V_253 * V_254 = F_6 ( V_2 ) ;
int V_129 ;
V_252 -> V_106 = V_2 -> V_16 . V_106 ;
V_252 -> V_255 . V_256 . V_257 = F_6 ( V_2 ) -> V_257 ;
if ( V_2 -> V_16 . V_108 & V_109 ) {
for ( V_129 = 0 ; V_129 < 64 ; V_129 ++ ) {
V_252 -> V_255 . V_256 . V_258 . V_4 [ V_129 ] . V_259 = V_254 -> V_4 [ V_129 ] . V_260 | V_129 ;
V_252 -> V_255 . V_256 . V_258 . V_4 [ V_129 ] . V_261 = V_254 -> V_4 [ V_129 ] . V_262 ;
}
} else {
for ( V_129 = 0 ; V_129 < 16 ; V_129 ++ )
V_252 -> V_255 . V_256 . V_263 . V_208 [ V_129 ] = V_2 -> V_16 . V_17 -> V_208 [ V_129 ] ;
for ( V_129 = 0 ; V_129 < 8 ; V_129 ++ ) {
V_252 -> V_255 . V_256 . V_263 . V_264 [ V_129 ] = V_254 -> V_264 [ V_129 ] . V_265 ;
V_252 -> V_255 . V_256 . V_263 . V_266 [ V_129 ] = V_254 -> V_266 [ V_129 ] . V_265 ;
}
}
return 0 ;
}
int F_113 ( struct V_1 * V_2 ,
struct V_251 * V_252 )
{
struct V_253 * V_254 = F_6 ( V_2 ) ;
int V_129 ;
F_40 ( V_2 , V_252 -> V_106 ) ;
V_254 -> V_257 = V_252 -> V_255 . V_256 . V_257 ;
if ( V_2 -> V_16 . V_108 & V_109 ) {
for ( V_129 = 0 ; V_129 < 64 ; V_129 ++ ) {
V_2 -> V_16 . V_52 . V_267 ( V_2 , V_252 -> V_255 . V_256 . V_258 . V_4 [ V_129 ] . V_261 ,
V_252 -> V_255 . V_256 . V_258 . V_4 [ V_129 ] . V_259 ) ;
}
} else {
for ( V_129 = 0 ; V_129 < 16 ; V_129 ++ ) {
V_2 -> V_16 . V_52 . V_268 ( V_2 , V_129 , V_252 -> V_255 . V_256 . V_263 . V_208 [ V_129 ] ) ;
}
for ( V_129 = 0 ; V_129 < 8 ; V_129 ++ ) {
F_114 ( V_2 , & ( V_254 -> V_264 [ V_129 ] ) , false ,
( T_3 ) V_252 -> V_255 . V_256 . V_263 . V_264 [ V_129 ] ) ;
F_114 ( V_2 , & ( V_254 -> V_264 [ V_129 ] ) , true ,
( T_3 ) ( V_252 -> V_255 . V_256 . V_263 . V_264 [ V_129 ] >> 32 ) ) ;
F_114 ( V_2 , & ( V_254 -> V_266 [ V_129 ] ) , false ,
( T_3 ) V_252 -> V_255 . V_256 . V_263 . V_266 [ V_129 ] ) ;
F_114 ( V_2 , & ( V_254 -> V_266 [ V_129 ] ) , true ,
( T_3 ) ( V_252 -> V_255 . V_256 . V_263 . V_266 [ V_129 ] >> 32 ) ) ;
}
}
F_93 ( V_2 , 0 , 0 ) ;
return 0 ;
}
int F_115 ( struct V_1 * V_2 , struct V_269 * V_270 )
{
return - V_271 ;
}
int F_116 ( struct V_1 * V_2 , struct V_269 * V_270 )
{
return - V_271 ;
}
int F_117 ( struct V_1 * V_2 ,
struct V_272 * V_273 )
{
return 0 ;
}
int F_118 ( struct V_123 * V_123 ,
struct V_274 * log )
{
struct V_275 * V_276 ;
struct V_1 * V_2 ;
T_1 V_277 , V_278 ;
int V_279 = 0 ;
int V_137 ;
unsigned long V_280 ;
F_119 ( & V_123 -> V_281 ) ;
V_137 = F_120 ( V_123 , log , & V_279 ) ;
if ( V_137 )
goto V_282;
if ( V_279 ) {
V_276 = & V_123 -> V_283 -> V_283 [ log -> V_284 ] ;
V_277 = V_276 -> V_285 << V_118 ;
V_278 = V_277 + ( V_276 -> V_286 << V_118 ) ;
F_121 (n, vcpu, kvm)
F_122 ( V_2 , V_277 , V_278 ) ;
V_280 = F_123 ( V_276 ) ;
memset ( V_276 -> V_287 , 0 , V_280 ) ;
}
V_137 = 0 ;
V_282:
F_124 ( & V_123 -> V_281 ) ;
return V_137 ;
}
int F_125 ( void )
{
return 0 ;
}
struct V_1 * F_126 ( struct V_123 * V_123 , unsigned int V_288 )
{
struct V_253 * V_289 ;
struct V_1 * V_2 ;
int V_146 = - V_290 ;
unsigned long V_291 ;
V_289 = F_127 ( sizeof( struct V_253 ) ) ;
if ( ! V_289 )
goto V_282;
V_289 -> V_6 = (struct V_292 * )
F_128 ( sizeof( * V_289 -> V_6 ) , V_293 ) ;
if ( ! V_289 -> V_6 )
goto V_294;
V_2 = & V_289 -> V_2 ;
V_146 = F_129 ( V_2 , V_123 , V_288 ) ;
if ( V_146 )
goto V_295;
V_291 = F_130 ( V_293 | V_296 ) ;
V_2 -> V_16 . V_17 = ( void * ) ( V_291 + V_297 - 4096 ) ;
if ( ! V_291 )
goto V_298;
V_2 -> V_16 . V_299 = V_300 ;
V_2 -> V_16 . V_301 = F_43 () ;
#ifdef F_4
V_2 -> V_16 . V_106 = 0x3C0301 ;
#else
V_2 -> V_16 . V_106 = 0x84202 ;
#endif
F_40 ( V_2 , V_2 -> V_16 . V_106 ) ;
V_289 -> V_302 = 64 ;
V_2 -> V_16 . V_303 = V_304 ;
V_2 -> V_16 . V_305 = V_306 ;
V_2 -> V_16 . V_307 = ( T_1 ) V_308 ;
#ifdef F_4
V_2 -> V_16 . V_309 = * ( T_1 * ) V_310 ;
#else
V_2 -> V_16 . V_309 = ( T_1 ) V_310 ;
#endif
V_2 -> V_16 . V_34 = V_311 ;
V_146 = F_131 ( V_2 ) ;
if ( V_146 < 0 )
goto V_298;
return V_2 ;
V_298:
F_132 ( V_2 ) ;
V_295:
F_133 ( V_289 -> V_6 ) ;
V_294:
F_134 ( V_289 ) ;
V_282:
return F_135 ( V_146 ) ;
}
void F_136 ( struct V_1 * V_2 )
{
struct V_253 * V_289 = F_6 ( V_2 ) ;
F_137 ( ( unsigned long ) V_2 -> V_16 . V_17 & V_120 ) ;
F_132 ( V_2 ) ;
F_133 ( V_289 -> V_6 ) ;
F_134 ( V_289 ) ;
}
int F_138 ( struct V_159 * V_159 , struct V_1 * V_2 )
{
int V_196 ;
double V_186 [ 32 ] [ V_312 ] ;
unsigned int V_190 ;
int V_201 ;
#ifdef F_79
T_7 V_192 [ 32 ] ;
T_7 V_193 ;
unsigned long V_313 ( V_202 ) ;
int V_314 ;
#endif
#ifdef F_75
int V_315 ;
#endif
T_1 V_231 ;
if ( F_99 ( V_9 ) ) {
V_159 -> V_204 = V_233 ;
return - V_234 ;
}
if ( V_9 -> V_10 . V_194 -> V_18 & V_12 )
F_77 ( V_9 ) ;
memcpy ( V_186 , V_9 -> V_10 . V_186 , sizeof( V_9 -> V_10 . V_186 ) ) ;
V_190 = V_9 -> V_10 . V_190 . V_191 ;
V_201 = V_9 -> V_10 . V_201 ;
#ifdef F_79
V_314 = V_9 -> V_10 . V_314 ;
if ( V_314 ) {
if ( V_9 -> V_10 . V_194 -> V_18 & V_13 )
F_80 ( V_9 ) ;
memcpy ( V_192 , V_9 -> V_10 . V_192 , sizeof( V_9 -> V_10 . V_192 ) ) ;
V_193 = V_9 -> V_10 . V_193 ;
V_202 = V_9 -> V_10 . V_202 ;
}
#endif
#ifdef F_75
V_315 = V_9 -> V_10 . V_315 ;
if ( V_315 && ( V_9 -> V_10 . V_194 -> V_18 & V_14 ) )
F_81 ( V_9 ) ;
#endif
V_231 = V_9 -> V_10 . V_194 -> V_18 ;
F_139 () ;
if ( V_2 -> V_16 . V_17 -> V_18 & V_12 )
F_19 ( V_2 , V_46 , V_12 ) ;
V_196 = F_140 ( V_159 , V_2 ) ;
F_141 () ;
V_9 -> V_10 . V_194 -> V_18 = V_231 ;
F_10 ( V_2 , V_12 ) ;
F_10 ( V_2 , V_13 ) ;
F_10 ( V_2 , V_14 ) ;
memcpy ( V_9 -> V_10 . V_186 , V_186 , sizeof( V_9 -> V_10 . V_186 ) ) ;
V_9 -> V_10 . V_190 . V_191 = V_190 ;
V_9 -> V_10 . V_201 = V_201 ;
#ifdef F_79
if ( V_314 && V_9 -> V_10 . V_314 ) {
memcpy ( V_9 -> V_10 . V_192 , V_192 , sizeof( V_9 -> V_10 . V_192 ) ) ;
V_9 -> V_10 . V_193 = V_193 ;
V_9 -> V_10 . V_202 = V_202 ;
}
V_9 -> V_10 . V_314 = V_314 ;
#endif
#ifdef F_75
V_9 -> V_10 . V_315 = V_315 ;
#endif
return V_196 ;
}
static int F_142 ( void )
{
int V_137 ;
V_137 = F_143 ( NULL , sizeof( struct V_253 ) , 0 ,
V_316 ) ;
if ( V_137 )
return V_137 ;
V_137 = F_144 () ;
return V_137 ;
}
static void F_145 ( void )
{
F_146 () ;
F_147 () ;
}
