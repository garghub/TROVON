static int T_1 F_1 ( void )
{
V_1 [ 0 ] . V_2 = 0 ;
V_1 [ 1 ] . V_2 = 0 ;
#if F_2 ( V_3 )
if ( F_3 ( V_4 , L_1 ) ) {
F_4 ( V_5 L_2
L_3 , 0 ) ;
return - V_6 ;
}
#endif
#if F_2 ( V_7 )
if ( F_3 ( V_8 , L_4 ) ) {
#if F_2 ( V_3 )
F_5 ( V_4 ) ;
#endif
F_4 ( V_5 L_2
L_3 , 1 ) ;
return - V_6 ;
}
#endif
if ( F_6 ( V_9 , L_5 ,
& V_10 ) < 0 ) {
#if F_2 ( V_7 )
F_5 ( V_8 ) ;
#endif
#if F_2 ( V_3 )
F_5 ( V_4 ) ;
#endif
F_4 ( L_6 ) ;
return - V_6 ;
}
F_7 ( V_11 , V_12 , V_13 , V_14 ) ;
F_7 ( V_11 , V_12 , V_15 , V_14 ) ;
* V_12 = V_11 ;
#if F_2 ( V_3 )
V_1 [ 0 ] . V_2 = 1 ;
F_7 ( V_16 , V_17 , V_18 , V_19 ) ;
F_7 ( V_11 , V_12 , V_13 , V_20 ) ;
#if F_2 ( V_21 )
V_1 [ 0 ] . V_22 = 1 ;
#else
V_1 [ 0 ] . V_22 = 0 ;
#endif
F_8 ( 0 ) ;
#endif
#if F_2 ( V_7 )
V_1 [ 1 ] . V_2 = 1 ;
F_7 ( V_16 , V_17 , V_23 , V_24 ) ;
F_7 ( V_11 , V_12 , V_15 , V_20 ) ;
#if F_2 ( V_25 )
V_1 [ 1 ] . V_22 = 1 ;
#else
V_1 [ 1 ] . V_22 = 0 ;
#endif
F_8 ( 1 ) ;
#endif
* V_17 = V_16 ;
* V_26 = V_27 = (
F_9 ( V_26 , V_28 , V_29 ) |
F_9 ( V_26 , V_30 , V_31 ) |
F_9 ( V_26 , V_32 , V_29 ) |
F_9 ( V_26 , V_33 , V_31 ) |
F_9 ( V_26 , V_34 , V_35 ) |
F_10 ( V_26 , V_36 ,
V_37 ) |
F_10 ( V_26 , V_38 , V_39 ) |
F_9 ( V_26 , V_40 , V_41 ) ) ;
* V_12 = V_11 ;
F_4 ( V_42 L_7 ) ;
return 0 ;
}
static void T_1 F_8 ( int V_43 )
{
struct V_44 * V_45 = & V_1 [ V_43 ] ;
F_11 ( F_4 ( V_46 L_8 , V_43 ) ) ;
V_45 -> V_47 = 0 ;
V_45 -> V_48 = V_43 ;
V_45 -> V_49 = 0 ;
V_45 -> V_50 = 0 ;
V_45 -> V_51 = 0 ;
V_45 -> V_52 = V_45 -> V_53 ;
V_45 -> V_54 = V_45 -> V_55 ;
V_45 -> V_56 = V_45 -> V_55 ;
V_45 -> V_57 = V_58 ;
V_45 -> V_59 = V_60 ;
V_45 -> V_61 = & V_45 -> V_62 [ 0 ] ;
V_45 -> V_63 = & V_45 -> V_62 [ V_64 - 1 ] ;
V_45 -> V_63 -> V_65 = V_66 ;
F_12 ( & V_45 -> V_67 ) ;
F_12 ( & V_45 -> V_68 ) ;
V_45 -> V_69 =
F_9 ( V_70 , V_71 , V_72 ) |
F_9 ( V_70 , V_73 , V_74 ) |
F_9 ( V_70 , error , V_75 ) |
F_9 ( V_70 , V_76 , V_77 ) |
F_9 ( V_70 , V_78 , V_41 ) |
F_9 ( V_70 , V_79 , V_80 ) |
F_9 ( V_70 , V_81 , V_82 ) |
F_9 ( V_70 , V_83 , V_41 ) |
F_9 ( V_70 , V_84 , V_85 ) |
F_9 ( V_70 , V_86 , V_87 ) |
F_9 ( V_70 , V_88 , V_77 ) |
F_9 ( V_70 , V_89 , V_90 ) |
F_9 ( V_70 , V_91 , V_92 ) |
F_9 ( V_70 , V_93 , V_92 ) |
F_9 ( V_70 , V_94 , V_2 ) |
F_9 ( V_70 , V_95 , V_96 ) |
F_9 ( V_70 , V_97 , V_41 ) |
F_9 ( V_70 , V_98 , V_99 ) |
F_9 ( V_70 , V_100 , V_41 ) |
F_9 ( V_70 , V_101 , V_41 ) |
F_9 ( V_70 , V_102 , V_41 ) |
F_9 ( V_70 , V_103 , V_104 ) ;
if ( V_45 -> V_22 )
V_45 -> V_69 |= F_9 ( V_70 ,
V_105 , V_82 ) ;
else
V_45 -> V_69 |= F_9 ( V_70 ,
V_105 , V_106 ) ;
* V_45 -> V_107 = V_45 -> V_69 ;
}
static inline int F_13 ( struct V_44 * V_45 )
{
int V_108 ;
unsigned char * V_109 ;
unsigned char * V_110 ;
V_109 = ( unsigned char * ) V_45 -> V_54 ;
V_110 = ( unsigned char * ) V_45 -> V_56 ;
if ( V_110 >= V_109 )
V_108 = V_110 - V_109 ;
else
V_108 = V_45 -> V_57 - ( V_109 - V_110 ) ;
return V_108 ;
}
static inline int F_14 ( struct V_44 * V_45 )
{
int V_108 ;
unsigned char * V_109 ;
unsigned char * V_110 ;
V_109 = ( unsigned char * ) V_45 -> V_54 ;
V_110 = ( unsigned char * ) V_45 -> V_56 ;
if ( V_110 >= V_109 )
V_108 = V_110 - V_109 ;
else
V_108 = V_45 -> V_55 + V_45 -> V_57 - V_109 ;
return V_108 ;
}
static int F_15 ( struct V_111 * V_111 , struct V_112 * V_112 )
{
int V_113 = F_16 ( V_111 -> V_114 ) ;
struct V_44 * V_45 ;
int V_73 ;
int V_115 = - V_6 ;
F_17 ( & V_116 ) ;
F_11 ( F_4 ( V_46 L_9 , V_113 ) ) ;
if ( V_113 < 0 || V_113 >= V_117 || ! V_1 [ V_113 ] . V_2 ) {
F_11 ( F_4 ( V_46 L_10 , V_113 ) ) ;
V_115 = - V_118 ;
goto V_119;
}
V_45 = & V_1 [ V_113 ] ;
if ( V_45 -> V_49 == 2 ) {
F_11 ( F_4 ( V_46 L_11 ) ) ;
goto V_119;
}
if ( V_45 -> V_120 ) {
if ( V_45 -> V_22 ) {
if ( V_45 == & V_1 [ 0 ] ) {
#ifdef F_18
if ( F_19 ( 24 , V_121 , 0 ,
L_12 ,
& V_1 [ 0 ] ) ) {
F_4 ( V_5 L_13
L_14 ) ;
goto V_119;
} else if ( F_19 ( 25 , V_122 , 0 ,
L_15 ,
& V_1 [ 0 ] ) ) {
F_20 ( 24 , & V_45 [ 0 ] ) ;
F_4 ( V_5 L_13
L_14 ) ;
goto V_119;
} else if ( F_21 ( 8 ,
L_12 ,
V_123 ,
V_124 ) ) {
F_20 ( 24 , & V_45 [ 0 ] ) ;
F_20 ( 25 , & V_45 [ 0 ] ) ;
F_4 ( V_5 L_13
L_16
L_17 ) ;
goto V_119;
} else if ( F_21 ( 9 ,
L_18 ,
V_123 ,
V_124 ) ) {
F_22 ( 8 , NULL ) ;
F_20 ( 24 , & V_45 [ 0 ] ) ;
F_20 ( 25 , & V_45 [ 0 ] ) ;
F_4 ( V_5 L_13
L_16
L_19 ) ;
goto V_119;
}
#endif
F_23 ( 8 ) ; F_24 ( 8 ) ;
F_23 ( 9 ) ; F_24 ( 9 ) ;
* V_125 =
F_9 (R_DMA_CH8_CLR_INTR, clr_eop,
do) |
F_9 (R_DMA_CH8_CLR_INTR, clr_descr,
do) ;
* V_126 =
F_9 (R_DMA_CH9_CLR_INTR, clr_eop,
do) |
F_9 (R_DMA_CH9_CLR_INTR, clr_descr,
do) ;
* V_127 =
F_9 ( V_127 , V_128 ,
V_129 ) |
F_9 ( V_127 , V_130 ,
V_129 ) ;
} else if ( V_45 == & V_1 [ 1 ] ) {
#ifdef F_18
if ( F_19 ( 20 , V_121 , 0 ,
L_20 ,
& V_1 [ 1 ] ) ) {
F_4 ( V_5 L_13
L_21 ) ;
goto V_119;
} else if ( F_19 ( 21 , V_122 , 0 ,
L_22 ,
& V_1 [ 1 ] ) ) {
F_20 ( 20 , & V_1 [ 1 ] ) ;
F_4 ( V_5 L_13
L_21 ) ;
goto V_119;
} else if ( F_21 ( 4 ,
L_20 ,
V_123 ,
V_131 ) ) {
F_20 ( 21 , & V_1 [ 1 ] ) ;
F_20 ( 20 , & V_1 [ 1 ] ) ;
F_4 ( V_5 L_13
L_23
L_17 ) ;
goto V_119;
} else if ( F_21 ( 5 ,
L_24 ,
V_123 ,
V_131 ) ) {
F_22 ( 4 , NULL ) ;
F_20 ( 21 , & V_1 [ 1 ] ) ;
F_20 ( 20 , & V_1 [ 1 ] ) ;
F_4 ( V_5 L_13
L_23
L_19 ) ;
goto V_119;
}
#endif
F_23 ( 4 ) ; F_24 ( 4 ) ;
F_23 ( 5 ) ; F_24 ( 5 ) ;
* V_132 =
F_9 (R_DMA_CH4_CLR_INTR, clr_eop,
do) |
F_9 (R_DMA_CH4_CLR_INTR, clr_descr,
do) ;
* V_133 =
F_9 (R_DMA_CH5_CLR_INTR, clr_eop,
do) |
F_9 (R_DMA_CH5_CLR_INTR, clr_descr,
do) ;
* V_127 =
F_9 ( V_127 , V_134 ,
V_129 ) |
F_9 ( V_127 , V_135 ,
V_129 ) ;
}
F_25 ( V_45 ) ;
V_45 -> V_120 = 0 ;
} else {
#ifdef F_26
if ( V_45 == & V_1 [ 0 ] ) {
if ( F_19 ( 8 ,
V_136 ,
V_137 | V_138 ,
L_25 ,
& V_1 [ 0 ] ) ) {
F_4 ( V_5 L_13
L_26 ) ;
goto V_119;
}
} else if ( V_45 == & V_1 [ 1 ] ) {
if ( F_19 ( 8 ,
V_136 ,
V_137 | V_138 ,
L_25 ,
& V_1 [ 1 ] ) ) {
F_4 ( V_5 L_13
L_26 ) ;
goto V_119;
}
}
V_45 -> V_120 = 0 ;
#else
F_27 ( L_27 ) ;
#endif
}
}
V_45 -> V_49 ++ ;
V_73 = F_28 ( V_70 , V_73 , V_45 -> V_69 ) ;
if ( V_73 == F_29 ( V_70 , V_73 , V_139 ) ||
V_73 == F_29 ( V_70 , V_73 , V_140 ) ||
V_73 == F_29 ( V_70 , V_73 , V_141 ) ||
V_73 == F_29 ( V_70 , V_73 , V_142 ) ) {
F_7 ( V_45 -> V_69 , V_70 , V_84 ,
V_143 ) ;
F_7 ( V_45 -> V_69 , V_70 , V_88 ,
V_144 ) ;
F_7 ( V_45 -> V_69 , V_70 , V_76 ,
V_144 ) ;
V_45 -> V_47 = 1 ;
* V_45 -> V_107 = V_45 -> V_69 ;
if ( ! V_45 -> V_22 )
* V_145 = 1 << V_45 -> V_146 ;
F_11 ( F_4 ( V_46 L_28 , V_113 ) ) ;
}
V_115 = 0 ;
V_119:
F_30 ( & V_116 ) ;
return V_115 ;
}
static int F_31 ( struct V_111 * V_111 , struct V_112 * V_112 )
{
int V_113 = F_16 ( V_111 -> V_114 ) ;
struct V_44 * V_45 ;
if ( V_113 < 0 || V_113 >= V_117 || ! V_1 [ V_113 ] . V_2 ) {
F_11 ( F_4 ( V_46 L_10 , V_113 ) ) ;
return - V_118 ;
}
V_45 = & V_1 [ V_113 ] ;
if ( V_45 -> V_49 )
V_45 -> V_49 -- ;
if ( ! V_45 -> V_49 )
* V_147 = ( ( 1 << V_45 -> V_146 ) |
( 1 << V_45 -> V_148 ) ) ;
return 0 ;
}
static unsigned int F_32 ( struct V_112 * V_112 , T_2 * V_149 )
{
int V_113 = F_16 ( V_112 -> V_150 -> V_151 -> V_114 ) ;
unsigned int V_152 = 0 ;
struct V_44 * V_45 ;
F_33 (static unsigned int prev_mask = 0 ) ;
V_45 = & V_1 [ V_113 ] ;
F_34 ( V_112 , & V_45 -> V_67 , V_149 ) ;
F_34 ( V_112 , & V_45 -> V_68 , V_149 ) ;
if ( V_45 -> V_51 < V_153 )
V_152 |= V_154 | V_155 ;
if ( F_13 ( V_45 ) >= V_45 -> V_59 )
V_152 |= V_156 | V_157 ;
F_33 (if (mask != prev_mask)
printk(KERN_DEBUG L_29,
mask,
mask & POLLOUT ? L_30 : L_31,
mask & POLLIN ? L_32 : L_31);
prev_mask = mask;
) ;
return V_152 ;
}
static int F_35 ( struct V_112 * V_112 ,
unsigned int V_158 , unsigned long V_159 )
{
int V_160 = 0 ;
unsigned long V_161 ;
int V_113 = F_16 ( V_112 -> V_150 -> V_151 -> V_114 ) ;
struct V_44 * V_45 ;
if ( V_113 < 0 || V_113 >= V_117 || ! V_1 [ V_113 ] . V_2 ) {
F_11 ( F_4 ( V_46 L_10 , V_113 ) ) ;
return - 1 ;
}
V_45 = & V_1 [ V_113 ] ;
F_36 ( V_161 ) ;
if ( V_113 ) {
if ( V_45 -> V_22 ) {
F_23 ( 4 ) ; F_24 ( 4 ) ;
V_45 -> V_50 = 0 ;
V_45 -> V_51 = 0 ;
V_45 -> V_52 = V_45 -> V_53 ;
* V_132 =
F_9 (R_DMA_CH4_CLR_INTR, clr_eop, do) |
F_9 (R_DMA_CH4_CLR_INTR, clr_descr, do) ;
}
F_7 ( V_11 , V_12 , V_15 , V_14 ) ;
} else {
if ( V_45 -> V_22 ) {
F_23 ( 8 ) ; F_24 ( 8 ) ;
V_45 -> V_50 = 0 ;
V_45 -> V_51 = 0 ;
V_45 -> V_52 = V_45 -> V_53 ;
* V_125 =
F_9 (R_DMA_CH8_CLR_INTR, clr_eop, do) |
F_9 (R_DMA_CH8_CLR_INTR, clr_descr, do) ;
}
F_7 ( V_11 , V_12 , V_13 , V_14 ) ;
}
* V_12 = V_11 ;
F_37 ( V_161 ) ;
switch ( V_158 ) {
case V_162 :
if ( F_38 ( V_159 ) == V_163 ) {
if ( V_113 )
F_7 ( V_27 ,
V_26 , V_32 ,
V_29 ) ;
else
F_7 ( V_27 ,
V_26 , V_28 ,
V_29 ) ;
F_39 ( V_27 ,
V_26 , V_34 ,
F_40 ( V_159 ) ) ;
F_39 ( V_27 ,
V_26 , V_36 ,
F_41 ( V_159 ) ) ;
F_39 ( V_27 ,
V_26 , V_38 ,
F_42 ( V_159 ) ) ;
} else {
F_39 ( V_45 -> V_69 , V_70 ,
V_71 , F_38 ( V_159 ) ) ;
if ( V_113 )
F_7 ( V_27 ,
V_26 , V_32 ,
V_164 ) ;
else
F_7 ( V_27 ,
V_26 , V_28 ,
V_164 ) ;
}
break;
case V_165 :
if ( V_159 > 5 )
return - V_166 ;
if ( V_159 == V_167 || V_159 == V_168 )
* V_147 = 1 << V_45 -> V_146 ;
else if ( ! V_45 -> V_22 )
* V_145 = 1 << V_45 -> V_146 ;
F_39 ( V_45 -> V_69 , V_70 , V_73 , V_159 ) ;
break;
case V_169 :
if ( V_159 & V_170 )
F_7 ( V_45 -> V_69 , V_70 ,
V_78 , V_41 ) ;
else if ( V_159 & V_171 )
F_7 ( V_45 -> V_69 , V_70 ,
V_78 , V_172 ) ;
if ( V_159 & V_173 )
F_7 ( V_45 -> V_69 , V_70 ,
V_79 , V_174 ) ;
else if ( V_159 & V_175 )
F_7 ( V_45 -> V_69 , V_70 ,
V_79 , V_80 ) ;
else if ( V_159 & V_176 )
F_7 ( V_45 -> V_69 , V_70 ,
V_79 , V_177 ) ;
if ( V_159 & V_178 )
F_7 ( V_45 -> V_69 , V_70 ,
V_81 , V_82 ) ;
else if ( V_159 & V_179 )
F_7 ( V_45 -> V_69 , V_70 ,
V_81 , V_106 ) ;
if ( V_159 & V_180 )
F_7 ( V_45 -> V_69 , V_70 ,
V_89 , V_90 ) ;
else if ( V_159 & V_181 )
F_7 ( V_45 -> V_69 , V_70 ,
V_89 , V_182 ) ;
else if ( V_159 & V_183 )
F_7 ( V_45 -> V_69 , V_70 ,
V_89 , V_184 ) ;
else if ( V_159 & V_185 )
F_7 ( V_45 -> V_69 , V_70 ,
V_89 , V_186 ) ;
else if ( V_159 & V_187 )
F_7 ( V_45 -> V_69 , V_70 ,
V_89 , V_188 ) ;
if ( V_159 & V_189 )
F_7 ( V_45 -> V_69 , V_70 ,
V_86 , V_87 ) ;
else if ( V_159 & V_190 )
F_7 ( V_45 -> V_69 , V_70 ,
V_86 , V_191 ) ;
if ( V_159 & V_192 )
F_7 ( V_45 -> V_69 , V_70 ,
V_94 , V_2 ) ;
else if ( V_159 & V_193 )
F_7 ( V_45 -> V_69 , V_70 ,
V_94 , V_194 ) ;
if ( V_159 & V_195 )
F_7 ( V_45 -> V_69 , V_70 ,
V_83 , V_41 ) ;
else if ( V_159 & V_196 )
F_7 ( V_45 -> V_69 , V_70 ,
V_83 , V_197 ) ;
break;
case V_198 :
if ( V_159 & V_199 )
F_7 ( V_45 -> V_69 , V_70 ,
V_95 , V_96 ) ;
else if ( V_159 & V_200 )
F_7 ( V_45 -> V_69 , V_70 ,
V_95 , V_201 ) ;
if ( V_159 & V_202 )
F_7 ( V_45 -> V_69 , V_70 ,
V_97 , V_41 ) ;
else if ( V_159 & V_203 )
F_7 ( V_45 -> V_69 , V_70 ,
V_97 , V_99 ) ;
if ( V_159 & V_204 )
F_7 ( V_45 -> V_69 , V_70 ,
V_98 , V_41 ) ;
else if ( V_159 & V_205 )
F_7 ( V_45 -> V_69 , V_70 ,
V_98 , V_99 ) ;
break;
case V_206 :
if ( V_159 & V_199 )
F_7 ( V_45 -> V_69 , V_70 ,
V_100 , V_41 ) ;
else if ( V_159 & V_200 )
F_7 ( V_45 -> V_69 , V_70 ,
V_100 , V_99 ) ;
if ( V_159 & V_202 )
F_7 ( V_45 -> V_69 , V_70 ,
V_101 , V_41 ) ;
else if ( V_159 & V_203 )
F_7 ( V_45 -> V_69 , V_70 ,
V_101 , V_99 ) ;
if ( V_159 & V_204 )
F_7 ( V_45 -> V_69 , V_70 ,
V_102 , V_41 ) ;
else if ( V_159 & V_205 )
F_7 ( V_45 -> V_69 , V_70 ,
V_102 , V_99 ) ;
break;
case V_207 :
F_7 ( V_45 -> V_69 , V_70 , V_94 ,
V_194 ) ;
F_7 ( V_45 -> V_69 , V_70 , V_86 ,
V_87 ) ;
F_7 ( V_45 -> V_69 , V_70 , V_89 ,
V_90 ) ;
F_7 ( V_45 -> V_69 , V_70 , V_81 , V_82 ) ;
F_7 ( V_45 -> V_69 , V_70 , V_79 ,
V_80 ) ;
F_7 ( V_45 -> V_69 , V_70 , V_78 ,
V_41 ) ;
if ( V_159 & V_208 ) {
F_7 ( V_45 -> V_69 , V_70 ,
V_97 , V_99 ) ;
F_7 ( V_45 -> V_69 , V_70 ,
V_95 , V_96 ) ;
F_39 ( V_45 -> V_69 , V_70 ,
V_73 , V_209 ) ;
} else {
F_7 ( V_45 -> V_69 , V_70 ,
V_101 , V_99 ) ;
F_7 ( V_45 -> V_69 , V_70 ,
V_100 , V_99 ) ;
F_39 ( V_45 -> V_69 , V_70 ,
V_73 , V_167 ) ;
}
break;
case V_210 :
#if 0
if (arg > port->in_buffer_size/NUM_IN_DESCR)
return -EINVAL;
port->inbufchunk = arg;
port->in_buffer_size =
(port->in_buffer_size/port->inbufchunk) *
port->inbufchunk;
DEBUG(printk(KERN_DEBUG "inbufchunk %i in_buffer_size: %i\n",
port->inbufchunk, port->in_buffer_size));
if (port->use_dma) {
if (port->port_nbr == 0) {
RESET_DMA(9);
WAIT_DMA(9);
} else {
RESET_DMA(5);
WAIT_DMA(5);
}
start_dma_in(port);
}
#endif
break;
default:
V_160 = - 1 ;
}
F_36 ( V_161 ) ;
* V_45 -> V_107 = V_45 -> V_69 ;
F_43 () ; F_43 () ; F_43 () ; F_43 () ;
* V_26 = V_27 ;
F_43 () ; F_43 () ; F_43 () ; F_43 () ;
if ( V_113 )
F_7 ( V_11 , V_12 , V_15 , V_20 ) ;
else
F_7 ( V_11 , V_12 , V_13 , V_20 ) ;
* V_12 = V_11 ;
if ( V_45 -> V_22 ) {
if ( V_45 -> V_48 == 0 ) {
F_23 ( 9 ) ;
F_24 ( 9 ) ;
} else {
F_23 ( 5 ) ;
F_24 ( 5 ) ;
}
F_25 ( V_45 ) ;
}
F_37 ( V_161 ) ;
return V_160 ;
}
static long F_44 ( struct V_112 * V_112 ,
unsigned int V_158 , unsigned long V_159 )
{
long V_211 ;
F_17 ( & V_116 ) ;
V_211 = F_35 ( V_112 , V_158 , V_159 ) ;
F_30 ( & V_116 ) ;
return V_211 ;
}
static T_3 F_45 ( struct V_112 * V_112 , const char * V_212 ,
T_4 V_213 , T_5 * V_214 )
{
int V_113 = F_16 ( V_112 -> V_150 -> V_151 -> V_114 ) ;
F_46 ( V_149 , V_215 ) ;
struct V_44 * V_45 ;
unsigned long V_161 ;
unsigned long V_216 , V_217 ;
unsigned long V_218 ;
unsigned long V_52 ;
unsigned long V_53 ;
if ( V_113 < 0 || V_113 >= V_117 || ! V_1 [ V_113 ] . V_2 ) {
F_11 ( F_4 ( V_46 L_10 , V_113 ) ) ;
return - V_118 ;
}
V_45 = & V_1 [ V_113 ] ;
F_47 ( F_4 ( V_46 L_33 ,
V_45 -> V_48 , V_213 , V_45 -> V_51 , V_153 ) ) ;
F_36 ( V_161 ) ;
if ( V_213 > V_153 - V_45 -> V_51 )
V_213 = V_153 - V_45 -> V_51 ;
V_52 = ( unsigned long ) V_45 -> V_52 ;
V_218 = V_52 + V_45 -> V_51 ;
F_37 ( V_161 ) ;
V_53 = ( unsigned long ) V_45 -> V_53 ;
if ( V_218 >= V_53 + V_153 )
V_218 -= V_153 ;
if ( V_218 >= V_52 )
V_216 = V_53 + V_153 - V_218 ;
else
V_216 = V_52 - V_218 ;
if ( V_216 > V_213 )
V_216 = V_213 ;
F_47 ( F_4 ( V_46 L_34 ,
V_52 , V_218 , V_216 ) ) ;
if ( F_48 ( ( void * ) V_218 , V_212 , V_216 ) )
return - V_219 ;
if ( V_216 != V_213 ) {
V_212 += V_216 ;
V_217 = V_213 - V_216 ;
F_47 ( F_4 ( V_46 L_35 ,
V_218 - V_53 , V_216 , V_217 ) ) ;
if ( F_48 ( ( void * ) V_53 , V_212 , V_217 ) )
return - V_219 ;
}
F_36 ( V_161 ) ;
V_45 -> V_51 += V_213 ;
F_37 ( V_161 ) ;
if ( ! V_45 -> V_47 ) {
F_7 ( V_45 -> V_69 , V_70 , V_84 ,
V_143 ) ;
F_7 ( V_45 -> V_69 , V_70 , V_88 ,
V_144 ) ;
F_7 ( V_45 -> V_69 , V_70 , V_76 ,
V_144 ) ;
V_45 -> V_47 = 1 ;
}
* V_45 -> V_107 = V_45 -> V_69 ;
if ( V_112 -> V_220 & V_221 ) {
F_36 ( V_161 ) ;
if ( ! V_45 -> V_50 ) {
if ( ! V_45 -> V_22 ) {
F_49 ( V_45 ) ;
* V_145 = 1 <<
V_45 -> V_148 ;
} else
F_50 ( V_45 ,
( unsigned char * volatile ) V_45 -> V_52 , V_216 ) ;
}
F_37 ( V_161 ) ;
F_47 ( F_4 ( V_46 L_36 ,
V_45 -> V_48 , V_213 ) ) ;
return V_213 ;
}
F_51 ( & V_45 -> V_67 , & V_149 ) ;
F_52 ( V_222 ) ;
F_36 ( V_161 ) ;
if ( ! V_45 -> V_50 ) {
if ( ! V_45 -> V_22 ) {
F_49 ( V_45 ) ;
* V_145 = 1 << V_45 -> V_148 ;
} else
F_50 ( V_45 , V_45 -> V_52 , V_216 ) ;
}
F_37 ( V_161 ) ;
F_53 () ;
F_52 ( V_223 ) ;
F_54 ( & V_45 -> V_67 , & V_149 ) ;
if ( F_55 ( V_215 ) )
return - V_224 ;
F_47 ( F_4 ( V_46 L_37 , V_45 -> V_48 , V_213 ) ) ;
return V_213 ;
}
static T_3 F_56 ( struct V_112 * V_112 , char * V_212 ,
T_4 V_213 , T_5 * V_214 )
{
int V_113 = F_16 ( V_112 -> V_150 -> V_151 -> V_114 ) ;
int V_108 ;
struct V_44 * V_45 ;
unsigned char * V_109 ;
unsigned char * V_110 ;
unsigned long V_161 ;
if ( V_113 < 0 || V_113 >= V_117 || ! V_1 [ V_113 ] . V_2 ) {
F_11 ( F_4 ( V_46 L_10 , V_113 ) ) ;
return - V_118 ;
}
V_45 = & V_1 [ V_113 ] ;
F_57 ( F_4 ( V_46 L_38 ,
V_113 , V_213 , V_45 -> V_54 - V_45 -> V_55 ,
V_45 -> V_56 - V_45 -> V_55 , V_45 -> V_57 ) ) ;
if ( ! V_45 -> V_47 ) {
F_7 ( V_45 -> V_69 , V_70 , V_84 ,
V_143 ) ;
F_7 ( V_45 -> V_69 , V_70 , V_88 ,
V_144 ) ;
F_7 ( V_45 -> V_69 , V_70 , V_76 ,
V_144 ) ;
V_45 -> V_47 = 1 ;
}
* V_45 -> V_107 = V_45 -> V_69 ;
F_36 ( V_161 ) ;
V_109 = ( unsigned char * ) V_45 -> V_54 ;
V_110 = ( unsigned char * ) V_45 -> V_56 ;
F_37 ( V_161 ) ;
while ( V_109 == V_110 && ! V_45 -> V_225 ) {
if ( V_112 -> V_220 & V_221 )
return - V_226 ;
F_58 ( & V_45 -> V_68 ) ;
if ( F_55 ( V_215 ) )
return - V_224 ;
F_36 ( V_161 ) ;
V_109 = ( unsigned char * ) V_45 -> V_54 ;
V_110 = ( unsigned char * ) V_45 -> V_56 ;
F_37 ( V_161 ) ;
}
if ( V_45 -> V_225 )
V_108 = V_45 -> V_57 ;
else if ( V_110 > V_109 )
V_108 = V_110 - V_109 ;
else
V_108 = V_45 -> V_55 + V_45 -> V_57 - V_109 ;
V_213 = V_213 > V_108 ? V_108 : V_213 ;
if ( F_59 ( V_212 , V_109 , V_213 ) )
return - V_219 ;
F_36 ( V_161 ) ;
V_45 -> V_54 += V_213 ;
if ( V_45 -> V_54 >= V_45 -> V_55 + V_45 -> V_57 )
V_45 -> V_54 = V_45 -> V_55 ;
V_45 -> V_225 = 0 ;
F_37 ( V_161 ) ;
F_57 ( F_4 ( V_46 L_39 , V_213 ) ) ;
return V_213 ;
}
static void F_49 ( struct V_44 * V_45 )
{
switch ( F_28 ( V_70 , V_89 ,
V_45 -> V_69 ) ) {
case F_29 ( V_70 , V_89 , V_90 ) :
V_45 -> V_51 -- ;
* V_45 -> V_227 = * V_45 -> V_52 ++ ;
if ( V_45 -> V_52 >= V_45 -> V_53 + V_153 )
V_45 -> V_52 = V_45 -> V_53 ;
break;
case F_29 ( V_70 , V_89 , V_182 ) :
{
int V_228 = ( * V_45 -> V_52 ++ ) << 8 ;
V_228 |= * V_45 -> V_52 ++ ;
V_45 -> V_51 -= 2 ;
* V_45 -> V_227 = V_228 ;
if ( V_45 -> V_52 >= V_45 -> V_53 + V_153 )
V_45 -> V_52 = V_45 -> V_53 ;
break;
}
case F_29 ( V_70 , V_89 , V_184 ) :
V_45 -> V_51 -= 2 ;
* V_45 -> V_227 = * ( unsigned short * ) V_45 -> V_52 ;
V_45 -> V_52 += 2 ;
if ( V_45 -> V_52 >= V_45 -> V_53 + V_153 )
V_45 -> V_52 = V_45 -> V_53 ;
break;
case F_29 ( V_70 , V_89 , V_186 ) :
V_45 -> V_51 -= 3 ;
* V_45 -> V_227 = * ( unsigned int * ) V_45 -> V_52 ;
V_45 -> V_52 += 3 ;
if ( V_45 -> V_52 >= V_45 -> V_53 + V_153 )
V_45 -> V_52 = V_45 -> V_53 ;
break;
case F_29 ( V_70 , V_89 , V_188 ) :
V_45 -> V_51 -= 4 ;
* V_45 -> V_227 = * ( unsigned int * ) V_45 -> V_52 ;
V_45 -> V_52 += 4 ;
if ( V_45 -> V_52 >= V_45 -> V_53 + V_153 )
V_45 -> V_52 = V_45 -> V_53 ;
break;
}
}
static void F_50 ( struct V_44 * V_45 , const char * V_228 , int V_213 )
{
V_45 -> V_50 = 1 ;
V_45 -> V_229 . V_230 = 0 ;
V_45 -> V_229 . V_231 = 0 ;
V_45 -> V_229 . V_65 = V_66 | V_232 ;
V_45 -> V_229 . V_233 = V_213 ;
V_45 -> V_229 . V_212 = F_60 ( V_228 ) ;
V_45 -> V_229 . V_234 = 0 ;
* V_45 -> V_235 = F_60 ( & V_45 -> V_229 ) ;
* V_45 -> V_236 = F_9 ( V_237 , V_158 , V_109 ) ;
F_61 ( F_4 ( V_46 L_40 ,
( unsigned long ) V_228 , V_213 ) ) ;
}
static void F_25 ( struct V_44 * V_45 )
{
int V_238 ;
unsigned long V_212 ;
V_45 -> V_56 = V_45 -> V_55 ;
if ( V_45 -> V_56 > V_45 -> V_55 + V_45 -> V_57 ) {
F_27 ( L_41 ) ;
return;
}
V_212 = F_60 ( V_45 -> V_239 ) ;
for ( V_238 = 0 ; V_238 < V_64 ; V_238 ++ ) {
V_45 -> V_62 [ V_238 ] . V_233 = V_45 -> V_59 ;
V_45 -> V_62 [ V_238 ] . V_65 = V_240 ;
V_45 -> V_62 [ V_238 ] . V_231 = F_60 ( & V_45 -> V_62 [ V_238 + 1 ] ) ;
V_45 -> V_62 [ V_238 ] . V_212 = V_212 ;
V_45 -> V_62 [ V_238 ] . V_230 = 0 ;
V_45 -> V_62 [ V_238 ] . V_234 = 0 ;
V_45 -> V_62 [ V_238 ] . V_241 = 0 ;
V_212 += V_45 -> V_59 ;
F_62 ( & V_45 -> V_62 [ V_238 ] ) ;
}
V_45 -> V_62 [ V_238 - 1 ] . V_231 = F_60 ( & V_45 -> V_62 [ 0 ] ) ;
V_45 -> V_62 [ V_238 - 1 ] . V_65 |= V_66 ;
V_45 -> V_61 = & V_45 -> V_62 [ 0 ] ;
V_45 -> V_63 = & V_45 -> V_62 [ V_64 - 1 ] ;
* V_45 -> V_242 = F_60 ( V_45 -> V_61 ) ;
* V_45 -> V_243 = F_9 ( V_237 , V_158 , V_109 ) ;
}
static T_6 V_121 ( int V_244 , void * V_245 )
{
unsigned long V_246 = * V_247 ;
struct V_248 * V_249 ;
unsigned int V_250 ;
int V_251 = 0 ;
int V_238 ;
for ( V_238 = 0 ; V_238 < V_117 ; V_238 ++ ) {
struct V_44 * V_45 = & V_1 [ V_238 ] ;
if ( ! V_45 -> V_2 || ! V_45 -> V_22 )
continue;
if ( ! ( V_246 & ( 1 << V_45 -> V_252 ) ) )
continue;
V_251 = 1 ;
* V_45 -> V_253 =
F_9 (R_DMA_CH0_CLR_INTR, clr_eop, do) |
F_9 (R_DMA_CH0_CLR_INTR, clr_descr, do) ;
V_249 = & V_45 -> V_229 ;
if ( ! ( V_249 -> V_234 & V_254 ) )
V_250 = V_249 -> V_233 ;
else
V_250 = V_249 -> V_230 ;
V_45 -> V_51 -= V_250 ;
V_45 -> V_52 += V_250 ;
if ( V_45 -> V_52 >= V_45 -> V_53 + V_153 )
V_45 -> V_52 = V_45 -> V_53 ;
if ( V_45 -> V_51 ) {
int V_216 = V_45 -> V_53 + V_153 - V_45 -> V_52 ;
if ( V_216 > V_45 -> V_51 )
V_216 = V_45 -> V_51 ;
F_61 ( F_4 ( V_46
L_42 , V_250 , V_216 ) ) ;
F_50 ( V_45 , V_45 -> V_52 , V_216 ) ;
} else {
F_61 ( F_4 ( V_46
L_43 , V_250 ) ) ;
V_45 -> V_50 = 0 ;
}
F_63 ( & V_45 -> V_67 ) ;
}
return F_64 ( V_251 ) ;
}
static T_6 V_122 ( int V_244 , void * V_245 )
{
unsigned long V_246 = * V_247 ;
int V_238 ;
int V_251 = 0 ;
for ( V_238 = 0 ; V_238 < V_117 ; V_238 ++ ) {
struct V_44 * V_45 = & V_1 [ V_238 ] ;
if ( ! V_45 -> V_2 || ! V_45 -> V_22 )
continue;
if ( ! ( V_246 & ( 1 << V_45 -> V_255 ) ) )
continue;
V_251 = 1 ;
while ( * V_45 -> V_256 !=
F_60 ( V_45 -> V_61 ) ) {
if ( V_45 -> V_56 + V_45 -> V_59 > V_45 -> V_55 +
V_45 -> V_57 ) {
int V_257 = V_45 -> V_55 +
V_45 -> V_57 - V_45 -> V_56 ;
memcpy ( V_45 -> V_56 ,
F_65 ( V_45 -> V_61 -> V_212 ) ,
V_257 ) ;
memcpy ( V_45 -> V_55 ,
F_65 ( V_45 -> V_61 -> V_212 +
V_257 ) ,
V_45 -> V_59 - V_257 ) ;
V_45 -> V_56 = V_45 -> V_55 +
V_45 -> V_59 - V_257 ;
} else {
memcpy ( V_45 -> V_56 ,
F_65 ( V_45 -> V_61 -> V_212 ) ,
V_45 -> V_59 ) ;
V_45 -> V_56 += V_45 -> V_59 ;
if ( V_45 -> V_56 >= V_45 -> V_55
+ V_45 -> V_57 )
V_45 -> V_56 = V_45 -> V_55 ;
}
if ( V_45 -> V_56 == V_45 -> V_54 )
V_45 -> V_225 = 1 ;
F_62 ( V_45 -> V_61 ) ;
V_45 -> V_61 -> V_65 |= V_66 ;
V_45 -> V_63 -> V_65 &= ~ V_66 ;
V_45 -> V_63 = F_65 ( ( unsigned )
V_45 -> V_61 ) ;
V_45 -> V_61 = F_65 ( ( unsigned )
V_45 -> V_61 -> V_231 ) ;
F_63 ( & V_45 -> V_68 ) ;
* V_45 -> V_243 = F_9 ( V_258 ,
V_158 , V_259 ) ;
* V_45 -> V_260 = F_9 (R_DMA_CH0_CLR_INTR,
clr_descr, do) ;
}
}
return F_64 ( V_251 ) ;
}
static T_6 V_136 ( int V_244 , void * V_245 )
{
int V_238 ;
int V_251 = 0 ;
for ( V_238 = 0 ; V_238 < V_117 ; V_238 ++ ) {
struct V_44 * V_45 = & V_1 [ V_238 ] ;
if ( ! V_45 -> V_2 || V_45 -> V_22 )
continue;
if ( * V_261 & ( 1 << V_45 -> V_146 ) ) {
V_251 = 1 ;
switch ( V_45 -> V_69 &
F_66 ( V_70 , V_89 ) ) {
case F_9 ( V_70 , V_89 , V_90 ) :
* V_45 -> V_56 ++ =
* ( volatile char * ) V_45 -> V_262 ;
break;
case F_9 ( V_70 , V_89 , V_182 ) :
{
int V_228 = * ( unsigned short * ) V_45 -> V_262 ;
* V_45 -> V_56 = ( V_228 & 0x0ff0 ) >> 4 ;
* ( V_45 -> V_56 + 1 ) = V_228 & 0x0f ;
V_45 -> V_56 += 2 ;
break;
}
case F_9 ( V_70 , V_89 , V_184 ) :
* ( unsigned short * ) V_45 -> V_56 =
* ( volatile unsigned short * ) V_45 -> V_262 ;
V_45 -> V_56 += 2 ;
break;
case F_9 ( V_70 , V_89 , V_186 ) :
* ( unsigned int * ) V_45 -> V_56 = * V_45 -> V_262 ;
V_45 -> V_56 += 3 ;
break;
case F_9 ( V_70 , V_89 , V_188 ) :
* ( unsigned int * ) V_45 -> V_56 = * V_45 -> V_262 ;
V_45 -> V_56 += 4 ;
break;
}
if ( V_45 -> V_56 >= V_45 -> V_55 + V_45 -> V_57 )
V_45 -> V_56 = V_45 -> V_55 ;
if ( V_45 -> V_56 == V_45 -> V_54 ) {
V_45 -> V_54 ++ ;
if ( V_45 -> V_54 >= V_45 -> V_55 +
V_45 -> V_57 )
V_45 -> V_54 = V_45 -> V_55 ;
}
if ( F_13 ( V_45 ) >= V_45 -> V_59 ) {
F_63 ( & V_45 -> V_68 ) ;
}
}
if ( * V_261 & ( 1 << V_45 -> V_148 ) ) {
if ( V_45 -> V_51 > 0 ) {
F_49 ( V_45 ) ;
} else {
* V_147 = 1 <<
V_45 -> V_148 ;
F_63 ( & V_45 -> V_67 ) ;
}
}
}
return F_64 ( V_251 ) ;
}
