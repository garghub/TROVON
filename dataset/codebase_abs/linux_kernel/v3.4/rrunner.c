static int T_1 F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
static int V_7 ;
T_2 V_8 ;
struct V_9 * V_10 ;
void * V_11 ;
T_3 V_12 ;
int V_13 = - V_14 ;
V_6 = F_2 ( sizeof( struct V_9 ) ) ;
if ( ! V_6 )
goto V_15;
V_13 = F_3 ( V_2 ) ;
if ( V_13 ) {
V_13 = - V_16 ;
goto V_17;
}
V_10 = F_4 ( V_6 ) ;
F_5 ( V_6 , & V_2 -> V_6 ) ;
if ( F_6 ( V_2 , L_1 ) ) {
V_13 = - V_18 ;
goto V_19;
}
F_7 ( V_2 , V_6 ) ;
V_10 -> V_1 = V_2 ;
F_8 ( & V_10 -> V_20 ) ;
V_6 -> V_21 = V_2 -> V_21 ;
V_6 -> V_22 = & V_23 ;
V_6 -> V_24 = F_9 ( V_2 , 0 ) ;
if ( ! V_7 ) {
V_7 = 1 ;
F_10 ( V_25 ) ;
}
F_11 ( V_2 , V_26 , & V_8 ) ;
if ( V_8 <= 0x58 ) {
V_8 = 0x58 ;
F_12 ( V_2 , V_26 , V_8 ) ;
}
F_13 ( V_2 ) ;
F_10 ( V_27 L_2
L_3 , V_6 -> V_28 ,
V_6 -> V_24 , V_6 -> V_21 , V_8 ) ;
V_10 -> V_29 = F_14 ( V_6 -> V_24 , 0x1000 ) ;
if ( ! V_10 -> V_29 ) {
F_10 ( V_30 L_4
L_5 , V_6 -> V_28 ) ;
V_13 = - V_18 ;
goto V_19;
}
V_11 = F_15 ( V_2 , V_31 , & V_12 ) ;
V_10 -> V_32 = V_11 ;
V_10 -> V_33 = V_12 ;
if ( ! V_11 ) {
V_13 = - V_14 ;
goto V_19;
}
V_11 = F_15 ( V_2 , V_34 , & V_12 ) ;
V_10 -> V_35 = V_11 ;
V_10 -> V_36 = V_12 ;
if ( ! V_11 ) {
V_13 = - V_14 ;
goto V_19;
}
V_11 = F_15 ( V_2 , V_37 , & V_12 ) ;
V_10 -> V_38 = V_11 ;
V_10 -> V_39 = V_12 ;
if ( ! V_11 ) {
V_13 = - V_14 ;
goto V_19;
}
#ifdef F_16
F_17 ( F_18 ( & V_10 -> V_29 -> V_40 ) | V_41 ,
& V_10 -> V_29 -> V_40 ) ;
#endif
F_19 ( V_6 ) ;
V_6 -> V_24 = 0 ;
V_13 = F_20 ( V_6 ) ;
if ( V_13 )
goto V_19;
return 0 ;
V_19:
if ( V_10 -> V_35 )
F_21 ( V_2 , V_34 , V_10 -> V_35 ,
V_10 -> V_36 ) ;
if ( V_10 -> V_32 )
F_21 ( V_2 , V_31 , V_10 -> V_32 ,
V_10 -> V_33 ) ;
if ( V_10 -> V_29 )
F_22 ( V_10 -> V_29 ) ;
if ( V_2 ) {
F_23 ( V_2 ) ;
F_7 ( V_2 , NULL ) ;
}
V_17:
F_24 ( V_6 ) ;
V_15:
return V_13 ;
}
static void T_4 F_25 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_26 ( V_2 ) ;
if ( V_6 ) {
struct V_9 * V_42 = F_4 ( V_6 ) ;
if ( ! ( F_18 ( & V_42 -> V_29 -> V_40 ) & V_43 ) ) {
F_10 ( V_30 L_6 ,
V_6 -> V_28 ) ;
F_17 ( V_44 , & V_42 -> V_29 -> V_40 ) ;
}
F_21 ( V_2 , V_37 , V_42 -> V_38 ,
V_42 -> V_39 ) ;
F_21 ( V_2 , V_34 , V_42 -> V_35 ,
V_42 -> V_36 ) ;
F_21 ( V_2 , V_31 , V_42 -> V_32 ,
V_42 -> V_33 ) ;
F_27 ( V_6 ) ;
F_22 ( V_42 -> V_29 ) ;
F_24 ( V_6 ) ;
F_23 ( V_2 ) ;
F_28 ( V_2 ) ;
F_7 ( V_2 , NULL ) ;
}
}
static void F_29 ( struct V_9 * V_10 , struct V_45 * V_45 )
{
struct V_46 T_5 * V_29 ;
T_6 V_47 ;
V_29 = V_10 -> V_29 ;
if ( F_18 ( & V_29 -> V_40 ) & V_43 ) {
F_10 ( L_7
L_8 , V_45 -> V_48 , F_18 ( & V_29 -> V_40 ) ) ;
if ( F_18 ( & V_29 -> V_49 ) & V_50 )
F_10 ( L_9 ,
F_18 ( & V_29 -> V_51 ) , F_18 ( & V_29 -> V_52 ) ) ;
}
V_47 = V_10 -> V_53 -> V_54 . V_55 ;
F_17 ( * ( T_6 * ) ( V_45 ) , & V_29 -> V_56 [ V_47 ] ) ;
F_30 () ;
V_47 = ( V_47 - 1 ) % V_57 ;
V_10 -> V_53 -> V_54 . V_55 = V_47 ;
F_30 () ;
if ( F_18 ( & V_29 -> V_49 ) & V_50 )
F_10 ( L_10 , F_18 ( & V_29 -> V_51 ) ) ;
}
static int F_31 ( struct V_5 * V_6 )
{
struct V_9 * V_10 ;
struct V_46 T_5 * V_29 ;
T_6 V_58 ;
int V_59 ;
V_10 = F_4 ( V_6 ) ;
V_29 = V_10 -> V_29 ;
F_32 ( V_6 ) ;
F_17 ( 0x01000000 , & V_29 -> V_60 ) ;
F_17 ( 0xff800000 , & V_29 -> V_61 ) ;
F_17 ( 0 , & V_29 -> V_62 ) ;
F_17 ( V_63 , & V_29 -> V_64 ) ;
F_17 ( 0x01 , & V_29 -> V_65 ) ;
F_17 ( 0 , & V_29 -> V_66 ) ;
F_17 ( 0 , & V_29 -> V_67 ) ;
F_17 ( V_68 , & V_29 -> V_69 ) ;
F_17 ( V_68 , & V_29 -> V_70 ) ;
F_17 ( 0 , & V_29 -> V_71 ) ;
F_17 ( 0 , & V_29 -> V_72 ) ;
F_17 ( 0 , & V_29 -> V_73 ) ;
F_17 ( 0 , & V_29 -> V_74 ) ;
F_17 ( 0 , & V_29 -> V_75 ) ;
F_17 ( 0 , & V_29 -> V_76 ) ;
F_17 ( 0 , & V_29 -> V_77 ) ;
F_17 ( 0 , & V_29 -> V_78 ) ;
F_17 ( 0 , & V_29 -> V_79 ) ;
F_17 ( 0 , & V_29 -> V_80 ) ;
F_17 ( 0 , & V_29 -> V_81 ) ;
#if ( V_82 == 64 ) && V_83 V_84
F_17 ( V_85 | V_86 | V_87 , & V_29 -> V_49 ) ;
#elif ( V_82 == 64 )
F_17 ( V_85 | V_86 | V_88 , & V_29 -> V_49 ) ;
#else
F_17 ( V_85 | V_89 | V_88 , & V_29 -> V_49 ) ;
#endif
#if 0
writel(0xdf000, &regs->RxBase);
writel(0xdf000, &regs->RxPrd);
writel(0xdf000, &regs->RxCon);
writel(0xce000, &regs->TxBase);
writel(0xce000, &regs->TxPrd);
writel(0xce000, &regs->TxCon);
writel(0, &regs->RxIndPro);
writel(0, &regs->RxIndCon);
writel(0, &regs->RxIndRef);
writel(0, &regs->TxIndPro);
writel(0, &regs->TxIndCon);
writel(0, &regs->TxIndRef);
writel(0xcc000, &regs->pad10[0]);
writel(0, &regs->DrCmndPro);
writel(0, &regs->DrCmndCon);
writel(0, &regs->DwCmndPro);
writel(0, &regs->DwCmndCon);
writel(0, &regs->DwCmndRef);
writel(0, &regs->DrDataPro);
writel(0, &regs->DrDataCon);
writel(0, &regs->DrDataRef);
writel(0, &regs->DwDataPro);
writel(0, &regs->DwDataCon);
writel(0, &regs->DwDataRef);
#endif
F_17 ( 0xffffffff , & V_29 -> V_90 ) ;
F_17 ( 0 , & V_29 -> V_91 ) ;
F_17 ( 0 , & V_29 -> V_92 ) ;
F_17 ( 0 , & V_29 -> V_93 ) ;
F_17 ( 0 , & V_29 -> V_94 ) ;
F_17 ( 0 , & V_29 -> V_95 ) ;
V_10 -> V_53 -> V_96 . V_55 = 0 ;
for ( V_59 = 0 ; V_59 < V_57 ; V_59 ++ )
F_17 ( 0 , & V_29 -> V_56 [ V_59 ] ) ;
F_17 ( V_97 | V_98 , & V_29 -> V_81 ) ;
F_30 () ;
V_58 = F_33 ( V_10 ,
F_34 ( struct V_99 , V_100 . V_101 ) ) ;
#if ( V_102 > 1 )
F_10 ( L_11 ,
V_6 -> V_28 , V_58 ) ;
#endif
F_17 ( V_58 + 0x800 , & V_29 -> V_103 ) ;
F_30 () ;
F_35 ( 5 ) ;
F_17 ( V_58 , & V_29 -> V_103 ) ;
F_30 () ;
return 0 ;
}
static unsigned int F_36 ( struct V_9 * V_10 ,
unsigned long V_104 ,
unsigned char * V_105 ,
unsigned long V_106 )
{
struct V_46 T_5 * V_29 = V_10 -> V_29 ;
T_6 V_107 , V_108 , V_109 , V_59 ;
V_108 = F_18 ( & V_29 -> V_110 ) ;
F_17 ( 0 , & V_29 -> V_110 ) ;
V_107 = F_18 ( & V_29 -> V_64 ) ;
F_17 ( 0 , & V_29 -> V_64 ) ;
V_109 = F_18 ( & V_29 -> V_40 ) ;
F_17 ( V_109 | V_44 , & V_29 -> V_40 ) ;
F_37 () ;
for ( V_59 = 0 ; V_59 < V_106 ; V_59 ++ ) {
F_17 ( ( V_111 + ( ( V_104 + V_59 ) << 3 ) ) , & V_29 -> V_112 ) ;
F_37 () ;
V_105 [ V_59 ] = ( F_18 ( & V_29 -> V_113 ) >> 24 ) & 0xff ;
F_37 () ;
}
F_17 ( V_109 , & V_29 -> V_40 ) ;
F_17 ( V_107 , & V_29 -> V_64 ) ;
F_17 ( V_108 , & V_29 -> V_110 ) ;
F_37 () ;
return V_59 ;
}
static T_6 F_33 ( struct V_9 * V_10 ,
T_7 V_104 )
{
T_8 V_114 ;
if ( ( F_36 ( V_10 , V_104 ,
( unsigned char * ) & V_114 , 4 ) == 4 ) )
return F_38 ( V_114 ) ;
return 0 ;
}
static unsigned int F_39 ( struct V_9 * V_10 ,
unsigned long V_104 ,
unsigned char * V_105 ,
unsigned long V_106 )
{
struct V_46 T_5 * V_29 = V_10 -> V_29 ;
T_6 V_107 , V_108 , V_115 , V_59 , V_116 , V_117 , error = 0 ;
V_108 = F_18 ( & V_29 -> V_110 ) ;
F_17 ( 0 , & V_29 -> V_110 ) ;
V_107 = F_18 ( & V_29 -> V_64 ) ;
F_17 ( V_118 , & V_29 -> V_64 ) ;
F_37 () ;
for ( V_59 = 0 ; V_59 < V_106 ; V_59 ++ ) {
F_17 ( ( V_111 + ( ( V_104 + V_59 ) << 3 ) ) , & V_29 -> V_112 ) ;
F_37 () ;
V_115 = V_105 [ V_59 ] << 24 ;
if ( ( F_18 ( & V_29 -> V_113 ) & 0xff000000 ) != V_115 ) {
F_17 ( V_115 , & V_29 -> V_113 ) ;
V_117 = 0 ;
V_116 = 0 ;
F_37 () ;
while( ! V_117 ) {
F_35 ( 20 ) ;
if ( ( F_18 ( & V_29 -> V_113 ) & 0xff000000 ) ==
V_115 )
V_117 = 1 ;
F_37 () ;
if ( V_116 ++ > 5000 ) {
F_10 ( L_12
L_13 , V_115 ,
F_18 ( & V_29 -> V_113 ) ) ;
V_117 = 1 ;
error = 1 ;
}
}
}
}
F_17 ( V_107 , & V_29 -> V_64 ) ;
F_17 ( V_108 , & V_29 -> V_110 ) ;
F_37 () ;
return error ;
}
static int T_1 F_19 ( struct V_5 * V_6 )
{
struct V_9 * V_10 ;
struct V_46 T_5 * V_29 ;
T_6 V_119 , V_120 ;
V_10 = F_4 ( V_6 ) ;
V_29 = V_10 -> V_29 ;
V_120 = F_18 ( & V_29 -> V_121 ) ;
V_10 -> V_122 = V_120 ;
if ( V_120 > 0x00020024 )
F_10 ( L_14 , ( V_120 >> 16 ) ,
( ( V_120 >> 8 ) & 0xff ) , ( V_120 & 0xff ) ) ;
else if ( V_120 >= 0x00020000 ) {
F_10 ( L_15
L_16 , ( V_120 >> 16 ) ,
( ( V_120 >> 8 ) & 0xff ) , ( V_120 & 0xff ) ) ;
} else{
F_10 ( L_17
L_18 ,
( V_120 >> 16 ) , ( ( V_120 >> 8 ) & 0xff ) , ( V_120 & 0xff ) ) ;
}
#if ( V_102 > 2 )
F_10 ( L_19 , F_18 ( & V_29 -> V_123 ) ) ;
#endif
* ( V_124 * ) ( V_6 -> V_125 ) =
F_40 ( F_33 ( V_10 , F_34 ( struct V_99 , V_126 . V_127 ) ) ) ;
* ( T_8 * ) ( V_6 -> V_125 + 2 ) =
F_41 ( F_33 ( V_10 , F_34 ( struct V_99 , V_126 . V_127 [ 4 ] ) ) ) ;
F_10 ( L_20 , V_6 -> V_125 ) ;
V_119 = F_33 ( V_10 , 8 ) ;
F_10 ( L_21 , V_119 ) ;
return 0 ;
}
static int F_42 ( struct V_5 * V_6 )
{
struct V_9 * V_10 ;
struct V_46 T_5 * V_29 ;
unsigned long V_128 , V_129 ;
struct V_45 V_45 ;
T_6 V_130 ;
int V_131 = 0 ;
short V_59 ;
V_10 = F_4 ( V_6 ) ;
V_29 = V_10 -> V_29 ;
F_43 ( & V_10 -> V_20 , V_129 ) ;
V_130 = F_18 ( & V_29 -> V_40 ) ;
F_17 ( V_130 | V_44 | V_132 , & V_29 -> V_40 ) ;
F_30 () ;
if ( V_130 & V_133 ) {
F_10 ( L_22 ,
V_6 -> V_28 ) ;
F_44 ( & V_10 -> V_20 , V_129 ) ;
V_131 = - V_134 ;
goto error;
}
F_45 ( V_29 , V_10 -> V_135 ) ;
F_46 ( V_29 , V_10 -> V_136 ) ;
V_10 -> V_53 -> V_96 . V_137 = sizeof( struct V_138 ) ;
V_10 -> V_53 -> V_96 . V_139 = V_140 ;
V_10 -> V_53 -> V_96 . V_141 = 0 ;
V_10 -> V_53 -> V_96 . V_55 = 0 ;
F_47 ( & V_10 -> V_53 -> V_96 . V_142 , V_10 -> V_39 ) ;
V_10 -> V_53 -> V_54 . V_137 = sizeof( struct V_45 ) ;
V_10 -> V_53 -> V_54 . V_139 = V_57 ;
V_10 -> V_53 -> V_54 . V_141 = 0 ;
V_10 -> V_53 -> V_54 . V_55 = 15 ;
for ( V_59 = 0 ; V_59 < V_57 ; V_59 ++ ) {
F_17 ( 0 , & V_29 -> V_56 [ V_59 ] ) ;
}
for ( V_59 = 0 ; V_59 < V_143 ; V_59 ++ ) {
V_10 -> V_32 [ V_59 ] . V_144 = 0 ;
F_47 ( & V_10 -> V_32 [ V_59 ] . V_145 , 0 ) ;
V_10 -> V_146 [ V_59 ] = NULL ;
}
V_10 -> V_53 -> V_147 . V_137 = sizeof( struct V_148 ) ;
V_10 -> V_53 -> V_147 . V_139 = V_143 ;
V_10 -> V_53 -> V_147 . V_141 = 0 ;
V_10 -> V_53 -> V_147 . V_55 = 0 ;
F_47 ( & V_10 -> V_53 -> V_147 . V_142 , V_10 -> V_33 ) ;
V_10 -> V_149 = 0 ;
V_10 -> V_150 = 0 ;
V_10 -> V_151 = V_10 -> V_152 = 0 ;
F_31 ( V_6 ) ;
F_17 ( 0x5000 , & V_29 -> V_153 ) ;
F_17 ( 0x100 , & V_29 -> V_154 ) ;
F_17 ( 0x500000 , & V_29 -> V_155 ) ;
F_17 ( 0x60 , & V_29 -> V_156 ) ;
F_17 ( 0x500000 , & V_29 -> V_157 ) ;
F_17 ( 0x200000 , & V_29 -> V_158 ) ;
F_17 ( 0x80 , & V_29 -> V_159 ) ;
F_17 ( 0x80 , & V_29 -> V_160 ) ;
V_10 -> V_161 = 0 ;
F_30 () ;
V_130 &= ~ ( V_44 | V_162 | V_133 ) ;
F_17 ( V_130 , & V_29 -> V_40 ) ;
F_30 () ;
F_44 ( & V_10 -> V_20 , V_129 ) ;
for ( V_59 = 0 ; V_59 < V_163 ; V_59 ++ ) {
struct V_164 * V_165 ;
T_3 V_145 ;
V_10 -> V_35 [ V_59 ] . V_141 = 0 ;
V_165 = F_48 ( V_6 -> V_166 + V_167 , V_168 ) ;
if ( ! V_165 ) {
F_10 ( V_169 L_23
L_24 , V_6 -> V_28 ) ;
V_131 = - V_14 ;
goto error;
}
V_10 -> V_170 [ V_59 ] = V_165 ;
V_145 = F_49 ( V_10 -> V_1 , V_165 -> V_115 ,
V_6 -> V_166 + V_167 , V_171 ) ;
if ( ( ( ( unsigned long ) V_165 -> V_115 ) & 0xfff ) > ~ 65320 )
F_10 ( L_25 ) ;
F_47 ( & V_10 -> V_35 [ V_59 ] . V_145 , V_145 ) ;
V_10 -> V_35 [ V_59 ] . V_144 = V_6 -> V_166 + V_167 ;
}
V_10 -> V_172 [ 4 ] . V_137 = sizeof( struct V_173 ) ;
V_10 -> V_172 [ 4 ] . V_139 = V_163 ;
V_10 -> V_172 [ 4 ] . V_141 = 8 ;
V_10 -> V_172 [ 4 ] . V_55 = 0 ;
F_30 () ;
F_47 ( & V_10 -> V_172 [ 4 ] . V_142 , V_10 -> V_36 ) ;
F_35 ( 1000 ) ;
V_45 . V_48 = V_174 ;
V_45 . V_175 = 0 ;
V_45 . V_176 = 0 ;
F_29 ( V_10 , & V_45 ) ;
V_128 = V_177 + 5 * V_178 ;
while ( F_50 ( V_177 , V_128 ) && ! V_10 -> V_161 )
F_51 () ;
F_52 ( V_6 ) ;
return V_131 ;
error:
for ( V_59 = 0 ; V_59 < V_163 ; V_59 ++ ) {
struct V_164 * V_165 = V_10 -> V_170 [ V_59 ] ;
if ( V_165 ) {
F_53 ( V_10 -> V_1 ,
V_10 -> V_35 [ V_59 ] . V_145 . V_179 ,
V_6 -> V_166 + V_167 ,
V_171 ) ;
V_10 -> V_35 [ V_59 ] . V_144 = 0 ;
F_47 ( & V_10 -> V_35 [ V_59 ] . V_145 , 0 ) ;
F_54 ( V_165 ) ;
V_10 -> V_170 [ V_59 ] = NULL ;
}
}
return V_131 ;
}
static T_6 F_55 ( struct V_5 * V_6 , T_6 V_180 , T_6 V_181 )
{
struct V_9 * V_10 ;
struct V_46 T_5 * V_29 ;
T_6 V_182 ;
V_10 = F_4 ( V_6 ) ;
V_29 = V_10 -> V_29 ;
while ( V_180 != V_181 ) {
switch ( V_10 -> V_38 [ V_181 ] . V_48 ) {
case V_183 :
V_182 = F_18 ( & V_29 -> V_121 ) ;
F_10 ( V_27 L_26
L_27 , V_6 -> V_28 ,
( V_182 >> 16 ) , ( ( V_182 >> 8 ) & 0xff ) , ( V_182 & 0xff ) ) ;
V_10 -> V_161 = 1 ;
F_17 ( V_163 - 1 , & V_29 -> V_93 ) ;
F_30 () ;
break;
case V_184 :
F_10 ( V_27 L_28 , V_6 -> V_28 ) ;
break;
case V_185 :
F_10 ( V_27 L_29 , V_6 -> V_28 ) ;
break;
case V_186 :
F_10 ( V_169 L_30 ,
V_6 -> V_28 ) ;
goto V_187;
case V_188 :
F_10 ( V_27 L_31
L_32 , V_6 -> V_28 ) ;
break;
case V_189 :
F_10 ( V_30 L_33 ,
V_6 -> V_28 ) ;
F_17 ( F_18 ( & V_29 -> V_40 ) | V_44 | V_132 ,
& V_29 -> V_40 ) ;
F_30 () ;
break;
case V_190 :
F_10 ( V_30 L_34 ,
V_6 -> V_28 ) ;
F_17 ( F_18 ( & V_29 -> V_40 ) | V_44 | V_132 ,
& V_29 -> V_40 ) ;
F_30 () ;
break;
case V_191 :
F_10 ( V_169 L_35 ,
V_6 -> V_28 ) ;
V_6 -> V_192 . V_193 ++ ;
break;
case V_194 :
F_10 ( V_169 L_36 ,
V_6 -> V_28 ) ;
break;
case V_195 :
F_10 ( V_169 L_37 ,
V_6 -> V_28 ) ;
V_6 -> V_192 . V_193 ++ ;
break;
case V_196 :
F_10 ( V_30 L_38 ,
V_6 -> V_28 ) ;
F_17 ( F_18 ( & V_29 -> V_40 ) | V_44 | V_132 ,
& V_29 -> V_40 ) ;
F_30 () ;
break;
case V_197 :
F_10 ( V_169 L_39 ,
V_6 -> V_28 ) ;
break;
case V_198 :
F_10 ( V_169 L_40 ,
V_6 -> V_28 ) ;
V_6 -> V_192 . V_193 ++ ;
F_17 ( F_18 ( & V_29 -> V_40 ) | V_44 | V_132 ,
& V_29 -> V_40 ) ;
F_30 () ;
break;
case V_199 :
F_10 ( V_30 L_41 ,
V_6 -> V_28 ) ;
F_17 ( F_18 ( & V_29 -> V_40 ) | V_44 | V_132 ,
& V_29 -> V_40 ) ;
F_30 () ;
break;
case V_200 :
F_10 ( V_30 L_42 ,
V_6 -> V_28 ) ;
F_17 ( F_18 ( & V_29 -> V_40 ) | V_44 | V_132 ,
& V_29 -> V_40 ) ;
F_30 () ;
break;
case V_201 :
F_10 ( V_30 L_43 ,
V_6 -> V_28 ) ;
F_17 ( F_18 ( & V_29 -> V_40 ) | V_44 | V_132 ,
& V_29 -> V_40 ) ;
F_30 () ;
break;
case V_202 :
F_10 ( V_27 L_44 , V_6 -> V_28 ) ;
break;
case V_203 :
F_10 ( V_169 L_45 ,
V_6 -> V_28 ) ;
goto V_187;
case V_204 :
F_10 ( V_169 L_46 ,
V_6 -> V_28 ) ;
goto V_187;
case V_205 :
F_10 ( V_169 L_47
L_48 , V_6 -> V_28 ) ;
goto V_187;
case V_206 :
F_10 ( V_169 L_49 ,
V_6 -> V_28 ) ;
goto V_187;
case V_207 :
F_10 ( V_169 L_50
L_48 , V_6 -> V_28 ) ;
goto V_187;
case V_208 :
F_10 ( V_169 L_51
L_52 , V_6 -> V_28 ) ;
goto V_187;
case V_209 :
F_10 ( V_169 L_53 ,
V_6 -> V_28 ) ;
goto V_187;
case V_210 :
F_10 ( V_169 L_54 ,
V_6 -> V_28 ) ;
goto V_187;
case V_211 :
F_10 ( V_169 L_55 ,
V_6 -> V_28 ) ;
goto V_187;
case V_212 :
F_10 ( V_169 L_56
L_57 , V_6 -> V_28 ) ;
goto V_187;
case V_213 :
F_10 ( V_30 L_58
L_59 , V_6 -> V_28 ) ;
F_17 ( F_18 ( & V_29 -> V_40 ) | V_44 | V_132 ,
& V_29 -> V_40 ) ;
F_30 () ;
break;
case V_214 :
F_10 ( V_30 L_60
L_59 , V_6 -> V_28 ) ;
F_17 ( F_18 ( & V_29 -> V_40 ) | V_44 | V_132 ,
& V_29 -> V_40 ) ;
F_30 () ;
break;
case V_215 :
F_10 ( V_30 L_61 ,
V_6 -> V_28 ) ;
F_17 ( F_18 ( & V_29 -> V_40 ) | V_44 | V_132 ,
& V_29 -> V_40 ) ;
F_30 () ;
break;
V_187:
{
T_9 V_176 = V_10 -> V_38 [ V_181 ] . V_176 ;
V_176 = ( V_176 + ( V_163 - 1 ) ) %
V_163 ;
V_10 -> V_35 [ V_176 ] . V_141 |=
( V_216 | V_217 ) ;
}
break;
default:
F_10 ( V_169 L_62 ,
V_6 -> V_28 , V_10 -> V_38 [ V_181 ] . V_48 ) ;
}
V_181 = ( V_181 + 1 ) % V_140 ;
}
V_10 -> V_53 -> V_96 . V_55 = V_181 ;
F_30 () ;
return V_181 ;
}
static void F_56 ( struct V_5 * V_6 , T_6 V_218 , T_6 V_176 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_46 T_5 * V_29 = V_10 -> V_29 ;
do {
struct V_173 * V_219 ;
T_6 V_220 ;
V_219 = & ( V_10 -> V_35 [ V_176 ] ) ;
V_220 = V_219 -> V_144 ;
#if ( V_102 > 2 )
F_10 ( L_63 , V_176 , V_218 ) ;
F_10 ( L_64 , V_220 , V_219 -> V_141 ) ;
#endif
if ( ( V_10 -> V_35 [ V_176 ] . V_141 & V_216 ) == V_216 ) {
V_6 -> V_192 . V_221 ++ ;
goto V_222;
}
if ( V_220 > 0 ) {
struct V_164 * V_165 , * V_223 ;
V_223 = V_10 -> V_170 [ V_176 ] ;
if ( V_220 < V_224 ) {
V_165 = F_48 ( V_220 , V_168 ) ;
if ( V_165 == NULL ) {
F_10 ( V_169 L_65 , V_6 -> V_28 , V_220 ) ;
V_6 -> V_192 . V_221 ++ ;
goto V_222;
} else {
F_57 ( V_10 -> V_1 ,
V_219 -> V_145 . V_179 ,
V_220 ,
V_171 ) ;
memcpy ( F_58 ( V_165 , V_220 ) ,
V_223 -> V_115 , V_220 ) ;
F_59 ( V_10 -> V_1 ,
V_219 -> V_145 . V_179 ,
V_220 ,
V_171 ) ;
}
} else{
struct V_164 * V_225 ;
V_225 = F_48 ( V_6 -> V_166 + V_167 ,
V_168 ) ;
if ( V_225 ) {
T_3 V_145 ;
F_53 ( V_10 -> V_1 ,
V_219 -> V_145 . V_179 , V_6 -> V_166 +
V_167 , V_171 ) ;
V_165 = V_223 ;
F_58 ( V_165 , V_220 ) ;
V_10 -> V_170 [ V_176 ] = V_225 ;
V_145 = F_49 ( V_10 -> V_1 ,
V_225 -> V_115 ,
V_6 -> V_166 + V_167 ,
V_171 ) ;
F_47 ( & V_219 -> V_145 , V_145 ) ;
} else {
F_10 ( L_66
L_57 , V_6 -> V_28 ) ;
V_6 -> V_192 . V_221 ++ ;
goto V_222;
}
}
V_165 -> V_226 = F_60 ( V_165 , V_6 ) ;
F_61 ( V_165 ) ;
V_6 -> V_192 . V_227 ++ ;
V_6 -> V_192 . V_228 += V_220 ;
}
V_222:
V_219 -> V_141 = 0 ;
V_219 -> V_144 = V_6 -> V_166 + V_167 ;
if ( ( V_176 & 7 ) == 7 )
F_17 ( V_176 , & V_29 -> V_93 ) ;
V_176 = ( V_176 + 1 ) % V_163 ;
} while( V_176 != V_218 );
V_10 -> V_150 = V_176 ;
F_30 () ;
}
static T_10 F_62 ( int V_21 , void * V_229 )
{
struct V_9 * V_10 ;
struct V_46 T_5 * V_29 ;
struct V_5 * V_6 = (struct V_5 * ) V_229 ;
T_6 V_180 , V_230 , V_181 , V_231 , V_218 , V_232 ;
V_10 = F_4 ( V_6 ) ;
V_29 = V_10 -> V_29 ;
if ( ! ( F_18 ( & V_29 -> V_40 ) & V_233 ) )
return V_234 ;
F_63 ( & V_10 -> V_20 ) ;
V_180 = F_18 ( & V_29 -> V_95 ) ;
V_231 = ( V_180 >> 8 ) & 0xff ;
V_218 = ( V_180 >> 16 ) & 0xff ;
V_180 &= 0xff ;
#if ( V_102 > 2 )
F_10 ( L_67 , V_6 -> V_28 ,
V_180 , V_10 -> V_53 -> V_96 . V_55 ) ;
#endif
V_181 = V_10 -> V_53 -> V_96 . V_55 ;
if ( V_180 != V_181 )
V_181 = F_55 ( V_6 , V_180 , V_181 ) ;
V_230 = V_10 -> V_150 ;
if ( V_230 != V_218 )
F_56 ( V_6 , V_218 , V_230 ) ;
V_232 = V_10 -> V_152 ;
if ( V_231 != V_232 ) {
do {
if( V_10 -> V_146 [ V_232 ] ) {
struct V_148 * V_219 ;
struct V_164 * V_165 ;
V_219 = & ( V_10 -> V_32 [ V_232 ] ) ;
V_165 = V_10 -> V_146 [ V_232 ] ;
V_6 -> V_192 . V_235 ++ ;
V_6 -> V_192 . V_236 += V_165 -> V_237 ;
F_53 ( V_10 -> V_1 ,
V_219 -> V_145 . V_179 , V_165 -> V_237 ,
V_238 ) ;
F_64 ( V_165 ) ;
V_10 -> V_146 [ V_232 ] = NULL ;
V_219 -> V_144 = 0 ;
F_47 ( & V_10 -> V_32 [ V_232 ] . V_145 , 0 ) ;
V_219 -> V_141 = 0 ;
}
V_232 = ( V_232 + 1 ) % V_143 ;
} while ( V_231 != V_232 );
F_30 () ;
V_10 -> V_152 = V_232 ;
if ( V_10 -> V_149 && F_65 ( V_6 ) &&
( ( ( V_10 -> V_53 -> V_147 . V_55 + 1 ) % V_143 )
!= V_10 -> V_152 ) ) {
V_10 -> V_149 = 0 ;
F_66 ( V_6 ) ;
}
}
V_181 |= ( ( V_231 << 8 ) | ( V_218 << 16 ) ) ;
F_17 ( V_181 , & V_29 -> V_94 ) ;
F_30 () ;
F_67 ( & V_10 -> V_20 ) ;
return V_239 ;
}
static inline void F_68 ( struct V_9 * V_10 ,
struct V_5 * V_6 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_143 ; V_59 ++ ) {
struct V_164 * V_165 = V_10 -> V_146 [ V_59 ] ;
if ( V_165 ) {
struct V_148 * V_219 = & ( V_10 -> V_32 [ V_59 ] ) ;
F_53 ( V_10 -> V_1 , V_219 -> V_145 . V_179 ,
V_165 -> V_237 , V_238 ) ;
V_219 -> V_144 = 0 ;
F_47 ( & V_219 -> V_145 , 0 ) ;
F_54 ( V_165 ) ;
V_10 -> V_146 [ V_59 ] = NULL ;
}
}
}
static inline void F_69 ( struct V_9 * V_10 ,
struct V_5 * V_6 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_163 ; V_59 ++ ) {
struct V_164 * V_165 = V_10 -> V_170 [ V_59 ] ;
if ( V_165 ) {
struct V_173 * V_219 = & ( V_10 -> V_35 [ V_59 ] ) ;
F_53 ( V_10 -> V_1 , V_219 -> V_145 . V_179 ,
V_6 -> V_166 + V_167 , V_171 ) ;
V_219 -> V_144 = 0 ;
F_47 ( & V_219 -> V_145 , 0 ) ;
F_54 ( V_165 ) ;
V_10 -> V_170 [ V_59 ] = NULL ;
}
}
}
static void F_70 ( unsigned long V_115 )
{
struct V_5 * V_6 = (struct V_5 * ) V_115 ;
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_46 T_5 * V_29 = V_10 -> V_29 ;
unsigned long V_129 ;
if ( F_18 ( & V_29 -> V_40 ) & V_43 ) {
F_10 ( L_68 , V_6 -> V_28 ) ;
memset ( V_10 -> V_172 , 0 , 256 * sizeof( struct V_240 ) ) ;
memset ( V_10 -> V_53 , 0 , sizeof( struct V_241 ) ) ;
F_30 () ;
F_68 ( V_10 , V_6 ) ;
F_69 ( V_10 , V_6 ) ;
if ( F_42 ( V_6 ) ) {
F_43 ( & V_10 -> V_20 , V_129 ) ;
F_17 ( F_18 ( & V_29 -> V_40 ) | V_44 | V_132 ,
& V_29 -> V_40 ) ;
F_44 ( & V_10 -> V_20 , V_129 ) ;
}
}
V_10 -> V_242 . V_243 = F_71 ( 5 * V_178 ) ;
F_72 ( & V_10 -> V_242 ) ;
}
static int F_73 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_1 * V_2 = V_10 -> V_1 ;
struct V_46 T_5 * V_29 ;
int V_131 = 0 ;
unsigned long V_129 ;
T_3 V_244 ;
V_29 = V_10 -> V_29 ;
if ( V_10 -> V_122 < 0x00020000 ) {
F_10 ( V_169 L_69
L_70 , V_6 -> V_28 ) ;
V_131 = - V_245 ;
goto error;
}
V_10 -> V_172 = F_15 ( V_2 ,
256 * sizeof( struct V_240 ) ,
& V_244 ) ;
if ( ! V_10 -> V_172 ) {
V_131 = - V_14 ;
goto error;
}
V_10 -> V_135 = V_244 ;
memset ( V_10 -> V_172 , 0 , 256 * sizeof( struct V_240 ) ) ;
V_10 -> V_53 = F_15 ( V_2 , sizeof( struct V_241 ) ,
& V_244 ) ;
if ( ! V_10 -> V_53 ) {
V_131 = - V_14 ;
goto error;
}
V_10 -> V_136 = V_244 ;
memset ( V_10 -> V_53 , 0 , sizeof( struct V_241 ) ) ;
F_30 () ;
F_43 ( & V_10 -> V_20 , V_129 ) ;
F_17 ( F_18 ( & V_29 -> V_40 ) | V_44 | V_132 , & V_29 -> V_40 ) ;
F_18 ( & V_29 -> V_40 ) ;
F_44 ( & V_10 -> V_20 , V_129 ) ;
if ( F_74 ( V_6 -> V_21 , F_62 , V_246 , V_6 -> V_28 , V_6 ) ) {
F_10 ( V_169 L_71 ,
V_6 -> V_28 , V_6 -> V_21 ) ;
V_131 = - V_247 ;
goto error;
}
if ( ( V_131 = F_42 ( V_6 ) ) )
goto error;
F_75 ( & V_10 -> V_242 ) ;
V_10 -> V_242 . V_243 = F_71 ( 5 * V_178 ) ;
V_10 -> V_242 . V_115 = ( unsigned long ) V_6 ;
V_10 -> V_242 . V_248 = F_70 ;
F_72 ( & V_10 -> V_242 ) ;
F_52 ( V_6 ) ;
return V_131 ;
error:
F_43 ( & V_10 -> V_20 , V_129 ) ;
F_17 ( F_18 ( & V_29 -> V_40 ) | V_44 | V_132 , & V_29 -> V_40 ) ;
F_44 ( & V_10 -> V_20 , V_129 ) ;
if ( V_10 -> V_53 ) {
F_21 ( V_2 , sizeof( struct V_241 ) , V_10 -> V_53 ,
V_10 -> V_136 ) ;
V_10 -> V_53 = NULL ;
}
if ( V_10 -> V_172 ) {
F_21 ( V_2 , sizeof( struct V_240 ) ,
V_10 -> V_172 , V_10 -> V_135 ) ;
V_10 -> V_172 = NULL ;
}
F_76 ( V_6 ) ;
return V_131 ;
}
static void F_77 ( struct V_5 * V_6 )
{
struct V_9 * V_10 ;
struct V_46 T_5 * V_29 ;
T_6 V_176 , V_249 ;
short V_59 ;
int V_237 ;
V_10 = F_4 ( V_6 ) ;
V_29 = V_10 -> V_29 ;
F_10 ( L_72 , V_6 -> V_28 ) ;
F_10 ( L_73 ,
F_18 ( & V_29 -> V_250 ) , F_18 ( & V_29 -> V_251 ) ,
F_18 ( & V_29 -> V_95 ) , F_18 ( & V_29 -> V_92 ) ,
V_10 -> V_53 -> V_147 . V_55 ) ;
F_10 ( L_74 , F_18 ( & V_29 -> V_51 ) ) ;
V_176 = ( ( ( F_18 ( & V_29 -> V_95 ) >> 8 ) & 0xff ) - 1 ) % V_143 ;
V_249 = V_10 -> V_152 ;
F_10 ( L_75 ,
V_176 , V_249 ) ;
if ( V_10 -> V_146 [ V_176 ] ) {
V_237 = F_78 ( int , 0x80 , V_10 -> V_146 [ V_176 ] -> V_237 ) ;
F_10 ( L_76 , V_176 , V_237 , V_10 -> V_32 [ V_176 ] . V_144 ) ;
for ( V_59 = 0 ; V_59 < V_237 ; V_59 ++ ) {
if ( ! ( V_59 & 7 ) )
F_10 ( L_77 ) ;
F_10 ( L_78 , ( unsigned char ) V_10 -> V_146 [ V_176 ] -> V_115 [ V_59 ] ) ;
}
F_10 ( L_77 ) ;
}
if ( V_10 -> V_146 [ V_249 ] ) {
V_237 = F_78 ( int , 0x80 , V_10 -> V_146 [ V_249 ] -> V_237 ) ;
F_10 ( L_79 , V_249 , V_237 , V_10 -> V_146 [ V_249 ] -> V_237 ) ;
F_10 ( L_80 ,
V_10 -> V_32 [ V_249 ] . V_141 ,
V_10 -> V_32 [ V_249 ] . V_144 ,
( unsigned long long ) V_10 -> V_32 [ V_249 ] . V_145 . V_179 ,
( unsigned long ) V_10 -> V_146 [ V_249 ] -> V_115 ,
( unsigned int ) V_10 -> V_146 [ V_249 ] -> V_252 ) ;
for ( V_59 = 0 ; V_59 < V_237 ; V_59 ++ ) {
if ( ! ( V_59 & 7 ) )
F_10 ( L_77 ) ;
F_10 ( L_78 , ( unsigned char ) V_10 -> V_32 [ V_249 ] . V_144 ) ;
}
F_10 ( L_77 ) ;
}
F_10 ( L_81 ) ;
for ( V_59 = 0 ; V_59 < V_143 ; V_59 ++ )
F_10 ( L_82 ,
V_10 -> V_32 [ V_59 ] . V_141 ,
V_10 -> V_32 [ V_59 ] . V_144 ,
( unsigned long long ) V_10 -> V_32 [ V_59 ] . V_145 . V_179 ) ;
}
static int F_79 ( struct V_5 * V_6 )
{
struct V_9 * V_10 ;
struct V_46 T_5 * V_29 ;
unsigned long V_129 ;
T_6 V_182 ;
short V_59 ;
F_76 ( V_6 ) ;
V_10 = F_4 ( V_6 ) ;
V_29 = V_10 -> V_29 ;
F_43 ( & V_10 -> V_20 , V_129 ) ;
V_182 = F_18 ( & V_29 -> V_40 ) ;
if ( V_182 & V_43 ) {
F_10 ( L_83 , V_6 -> V_28 ) ;
F_77 ( V_6 ) ;
} else{
V_182 |= V_44 | V_132 ;
F_17 ( V_182 , & V_29 -> V_40 ) ;
F_18 ( & V_29 -> V_40 ) ;
}
V_10 -> V_161 = 0 ;
F_80 ( & V_10 -> V_242 ) ;
F_17 ( 0 , & V_29 -> V_92 ) ;
F_17 ( 0 , & V_29 -> V_93 ) ;
F_17 ( 0 , & V_29 -> V_94 ) ;
F_17 ( 0 , & V_29 -> V_95 ) ;
for ( V_59 = 0 ; V_59 < V_57 ; V_59 ++ )
F_17 ( 0 , & V_29 -> V_56 [ V_59 ] ) ;
V_10 -> V_53 -> V_147 . V_139 = 0 ;
V_10 -> V_53 -> V_54 . V_55 = 0 ;
V_10 -> V_53 -> V_96 . V_55 = 0 ;
V_10 -> V_172 [ 4 ] . V_139 = 0 ;
F_68 ( V_10 , V_6 ) ;
F_69 ( V_10 , V_6 ) ;
F_21 ( V_10 -> V_1 , 256 * sizeof( struct V_240 ) ,
V_10 -> V_172 , V_10 -> V_135 ) ;
V_10 -> V_172 = NULL ;
F_21 ( V_10 -> V_1 , sizeof( struct V_241 ) ,
V_10 -> V_53 , V_10 -> V_136 ) ;
V_10 -> V_53 = NULL ;
F_81 ( V_6 -> V_21 , V_6 ) ;
F_44 ( & V_10 -> V_20 , V_129 ) ;
return 0 ;
}
static T_11 F_82 ( struct V_164 * V_165 ,
struct V_5 * V_6 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
struct V_46 T_5 * V_29 = V_10 -> V_29 ;
struct V_253 * V_254 = (struct V_253 * ) V_165 -> V_255 ;
struct V_240 * V_256 ;
unsigned long V_129 ;
T_6 V_176 , V_237 = V_165 -> V_237 ;
T_6 * V_257 ;
struct V_164 * V_258 ;
if ( F_18 ( & V_29 -> V_49 ) & V_50 )
F_10 ( L_9 ,
F_18 ( & V_29 -> V_51 ) , F_18 ( & V_29 -> V_52 ) ) ;
if ( F_83 ( V_165 ) < 8 ) {
F_10 ( L_84 ) ;
if ( ! ( V_258 = F_84 ( V_237 + 8 ) ) ) {
F_54 ( V_165 ) ;
F_66 ( V_6 ) ;
return V_259 ;
}
F_85 ( V_258 , 8 ) ;
F_58 ( V_258 , V_237 ) ;
F_86 ( V_165 , V_258 -> V_115 , V_237 ) ;
F_54 ( V_165 ) ;
V_165 = V_258 ;
}
V_257 = ( T_6 * ) F_87 ( V_165 , 8 ) ;
V_257 [ 0 ] = 0 ;
V_257 [ 1 ] = V_254 -> V_257 ;
F_43 ( & V_10 -> V_20 , V_129 ) ;
V_256 = & V_10 -> V_53 -> V_147 ;
V_176 = V_256 -> V_55 ;
V_10 -> V_146 [ V_176 ] = V_165 ;
F_47 ( & V_10 -> V_32 [ V_176 ] . V_145 , F_49 (
V_10 -> V_1 , V_165 -> V_115 , V_237 + 8 , V_238 ) ) ;
V_10 -> V_32 [ V_176 ] . V_144 = V_237 + 8 ;
V_10 -> V_32 [ V_176 ] . V_141 = V_260 | V_217 ;
V_256 -> V_55 = ( V_176 + 1 ) % V_143 ;
F_30 () ;
F_17 ( V_256 -> V_55 , & V_29 -> V_92 ) ;
if ( V_256 -> V_55 == V_10 -> V_152 ) {
V_10 -> V_149 = 1 ;
F_76 ( V_6 ) ;
}
F_44 ( & V_10 -> V_20 , V_129 ) ;
return V_259 ;
}
static int F_32 ( struct V_5 * V_6 )
{
struct V_9 * V_10 ;
struct V_46 T_5 * V_29 ;
T_7 V_261 , V_262 ;
int V_59 , V_116 ;
T_6 V_263 , V_264 , V_237 , V_182 ;
T_6 V_265 , V_266 , V_267 , V_268 , V_108 , V_119 ;
V_10 = F_4 ( V_6 ) ;
V_29 = V_10 -> V_29 ;
if ( V_6 -> V_129 & V_269 )
return - V_245 ;
if ( ! ( F_18 ( & V_29 -> V_40 ) & V_43 ) ) {
F_10 ( L_85 ,
V_6 -> V_28 ) ;
return - V_245 ;
}
V_263 = F_18 ( & V_29 -> V_64 ) ;
F_17 ( 0 , & V_29 -> V_64 ) ;
F_17 ( 0 , & V_29 -> V_95 ) ;
F_17 ( 0 , & V_29 -> V_250 ) ;
F_17 ( 0 , & V_29 -> V_251 ) ;
V_108 = F_18 ( & V_29 -> V_110 ) ;
F_17 ( 0 , & V_29 -> V_110 ) ;
V_119 = F_33 ( V_10 , 8 ) ;
for ( V_59 = 200 ; V_59 < V_119 / 4 ; V_59 ++ ) {
F_17 ( V_59 * 4 , & V_29 -> V_112 ) ;
F_37 () ;
F_17 ( 0 , & V_29 -> V_113 ) ;
F_37 () ;
}
F_17 ( V_108 , & V_29 -> V_110 ) ;
F_37 () ;
V_261 = F_33 ( V_10 ,
F_34 ( struct V_99 , V_100 . V_270 ) ) ;
V_261 = ( ( V_261 & 0x1fffff ) >> 3 ) ;
V_265 = F_33 ( V_10 , 0x83 * 4 ) ;
V_265 = ( V_265 << 2 ) ;
V_266 = F_33 ( V_10 , 0x84 * 4 ) ;
V_266 = ( ( V_266 & 0x1fffff ) >> 3 ) ;
if ( ( V_261 < V_266 ) || ( V_261 > ( V_266 + V_265 ) ) ) {
F_10 ( L_86 , V_6 -> V_28 ) ;
goto V_19;
}
V_268 = F_33 ( V_10 ,
F_34 ( struct V_99 , V_126 . V_271 ) ) ;
if ( V_268 != 1 ) {
F_10 ( L_87 ,
V_6 -> V_28 , V_268 ) ;
goto V_19;
}
V_267 = F_33 ( V_10 , V_261 ) ;
V_261 += 4 ;
#if ( V_102 > 1 )
F_10 ( L_88 , V_6 -> V_28 , V_267 ) ;
#endif
for ( V_59 = 0 ; V_59 < V_267 ; V_59 ++ ) {
V_264 = F_33 ( V_10 , V_261 ) ;
V_261 += 4 ;
V_237 = F_33 ( V_10 , V_261 ) ;
V_261 += 4 ;
V_262 = F_33 ( V_10 , V_261 ) ;
V_262 = ( ( V_262 & 0x1fffff ) >> 3 ) ;
V_261 += 4 ;
#if ( V_102 > 1 )
F_10 ( L_89 ,
V_6 -> V_28 , V_59 , V_264 , V_237 , V_262 ) ;
#endif
for ( V_116 = 0 ; V_116 < V_237 ; V_116 ++ ) {
V_182 = F_33 ( V_10 , V_262 ) ;
F_17 ( V_264 , & V_29 -> V_112 ) ;
F_37 () ;
F_17 ( V_182 , & V_29 -> V_113 ) ;
F_37 () ;
V_262 += 4 ;
V_264 += 4 ;
}
}
V_19:
F_17 ( V_263 , & V_29 -> V_64 ) ;
F_37 () ;
return 0 ;
}
static int F_88 ( struct V_5 * V_6 , struct V_272 * V_273 , int V_45 )
{
struct V_9 * V_10 ;
unsigned char * V_274 , * V_275 ;
unsigned long V_129 ;
unsigned int V_59 ;
int error = - V_276 ;
V_10 = F_4 ( V_6 ) ;
switch( V_45 ) {
case V_277 :
if ( ! F_89 ( V_278 ) ) {
return - V_279 ;
}
V_274 = F_90 ( V_280 * sizeof( T_6 ) , V_281 ) ;
if ( ! V_274 )
return - V_14 ;
if ( V_10 -> V_161 ) {
F_10 ( L_90 , V_6 -> V_28 ) ;
error = - V_279 ;
goto V_282;
}
F_43 ( & V_10 -> V_20 , V_129 ) ;
V_59 = F_36 ( V_10 , 0 , V_274 , V_283 ) ;
F_44 ( & V_10 -> V_20 , V_129 ) ;
if ( V_59 != V_283 ) {
F_10 ( V_30 L_91 ,
V_6 -> V_28 ) ;
error = - V_134 ;
goto V_282;
}
error = F_91 ( V_273 -> V_284 , V_274 , V_283 ) ;
if ( error )
error = - V_134 ;
V_282:
F_92 ( V_274 ) ;
return error ;
case V_285 :
if ( ! F_89 ( V_278 ) ) {
return - V_279 ;
}
V_274 = F_90 ( V_280 * sizeof( T_6 ) , V_281 ) ;
V_275 = F_90 ( V_280 * sizeof( T_6 ) , V_281 ) ;
if ( ! V_274 || ! V_275 ) {
error = - V_14 ;
goto V_286;
}
error = F_93 ( V_274 , V_273 -> V_284 , V_283 ) ;
if ( error ) {
error = - V_134 ;
goto V_286;
}
if ( V_10 -> V_161 ) {
F_10 ( L_90 , V_6 -> V_28 ) ;
error = - V_279 ;
goto V_286;
}
F_10 ( L_92 , V_6 -> V_28 ) ;
F_43 ( & V_10 -> V_20 , V_129 ) ;
error = F_39 ( V_10 , 0 , V_274 , V_283 ) ;
if ( error )
F_10 ( V_30 L_93 ,
V_6 -> V_28 ) ;
V_59 = F_36 ( V_10 , 0 , V_275 , V_283 ) ;
F_44 ( & V_10 -> V_20 , V_129 ) ;
if ( V_59 != V_283 )
F_10 ( V_30 L_94
L_95 , V_6 -> V_28 ) ;
error = memcmp ( V_274 , V_275 , V_283 ) ;
if ( error ) {
F_10 ( V_30 L_96 ,
V_6 -> V_28 ) ;
error = - V_134 ;
}
V_286:
F_92 ( V_275 ) ;
F_92 ( V_274 ) ;
return error ;
case V_287 :
return F_94 ( 0x52523032 , ( int V_288 * ) V_273 -> V_284 ) ;
default:
return error ;
}
}
static int T_12 F_95 ( void )
{
return F_96 ( & V_289 ) ;
}
static void T_13 F_97 ( void )
{
F_98 ( & V_289 ) ;
}
