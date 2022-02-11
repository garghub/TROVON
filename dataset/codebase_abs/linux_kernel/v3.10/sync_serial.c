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
int V_113 = F_16 ( F_33 ( V_112 ) -> V_114 ) ;
unsigned int V_150 = 0 ;
struct V_44 * V_45 ;
F_34 (static unsigned int prev_mask = 0 ) ;
V_45 = & V_1 [ V_113 ] ;
F_35 ( V_112 , & V_45 -> V_67 , V_149 ) ;
F_35 ( V_112 , & V_45 -> V_68 , V_149 ) ;
if ( V_45 -> V_51 < V_151 )
V_150 |= V_152 | V_153 ;
if ( F_13 ( V_45 ) >= V_45 -> V_59 )
V_150 |= V_154 | V_155 ;
F_34 (if (mask != prev_mask)
printk(KERN_DEBUG L_29,
mask,
mask & POLLOUT ? L_30 : L_31,
mask & POLLIN ? L_32 : L_31);
prev_mask = mask;
) ;
return V_150 ;
}
static int F_36 ( struct V_112 * V_112 ,
unsigned int V_156 , unsigned long V_157 )
{
int V_158 = 0 ;
unsigned long V_159 ;
int V_113 = F_16 ( F_33 ( V_112 ) -> V_114 ) ;
struct V_44 * V_45 ;
if ( V_113 < 0 || V_113 >= V_117 || ! V_1 [ V_113 ] . V_2 ) {
F_11 ( F_4 ( V_46 L_10 , V_113 ) ) ;
return - 1 ;
}
V_45 = & V_1 [ V_113 ] ;
F_37 ( V_159 ) ;
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
F_38 ( V_159 ) ;
switch ( V_156 ) {
case V_160 :
if ( F_39 ( V_157 ) == V_161 ) {
if ( V_113 )
F_7 ( V_27 ,
V_26 , V_32 ,
V_29 ) ;
else
F_7 ( V_27 ,
V_26 , V_28 ,
V_29 ) ;
F_40 ( V_27 ,
V_26 , V_34 ,
F_41 ( V_157 ) ) ;
F_40 ( V_27 ,
V_26 , V_36 ,
F_42 ( V_157 ) ) ;
F_40 ( V_27 ,
V_26 , V_38 ,
F_43 ( V_157 ) ) ;
} else {
F_40 ( V_45 -> V_69 , V_70 ,
V_71 , F_39 ( V_157 ) ) ;
if ( V_113 )
F_7 ( V_27 ,
V_26 , V_32 ,
V_162 ) ;
else
F_7 ( V_27 ,
V_26 , V_28 ,
V_162 ) ;
}
break;
case V_163 :
if ( V_157 > 5 )
return - V_164 ;
if ( V_157 == V_165 || V_157 == V_166 )
* V_147 = 1 << V_45 -> V_146 ;
else if ( ! V_45 -> V_22 )
* V_145 = 1 << V_45 -> V_146 ;
F_40 ( V_45 -> V_69 , V_70 , V_73 , V_157 ) ;
break;
case V_167 :
if ( V_157 & V_168 )
F_7 ( V_45 -> V_69 , V_70 ,
V_78 , V_41 ) ;
else if ( V_157 & V_169 )
F_7 ( V_45 -> V_69 , V_70 ,
V_78 , V_170 ) ;
if ( V_157 & V_171 )
F_7 ( V_45 -> V_69 , V_70 ,
V_79 , V_172 ) ;
else if ( V_157 & V_173 )
F_7 ( V_45 -> V_69 , V_70 ,
V_79 , V_80 ) ;
else if ( V_157 & V_174 )
F_7 ( V_45 -> V_69 , V_70 ,
V_79 , V_175 ) ;
if ( V_157 & V_176 )
F_7 ( V_45 -> V_69 , V_70 ,
V_81 , V_82 ) ;
else if ( V_157 & V_177 )
F_7 ( V_45 -> V_69 , V_70 ,
V_81 , V_106 ) ;
if ( V_157 & V_178 )
F_7 ( V_45 -> V_69 , V_70 ,
V_89 , V_90 ) ;
else if ( V_157 & V_179 )
F_7 ( V_45 -> V_69 , V_70 ,
V_89 , V_180 ) ;
else if ( V_157 & V_181 )
F_7 ( V_45 -> V_69 , V_70 ,
V_89 , V_182 ) ;
else if ( V_157 & V_183 )
F_7 ( V_45 -> V_69 , V_70 ,
V_89 , V_184 ) ;
else if ( V_157 & V_185 )
F_7 ( V_45 -> V_69 , V_70 ,
V_89 , V_186 ) ;
if ( V_157 & V_187 )
F_7 ( V_45 -> V_69 , V_70 ,
V_86 , V_87 ) ;
else if ( V_157 & V_188 )
F_7 ( V_45 -> V_69 , V_70 ,
V_86 , V_189 ) ;
if ( V_157 & V_190 )
F_7 ( V_45 -> V_69 , V_70 ,
V_94 , V_2 ) ;
else if ( V_157 & V_191 )
F_7 ( V_45 -> V_69 , V_70 ,
V_94 , V_192 ) ;
if ( V_157 & V_193 )
F_7 ( V_45 -> V_69 , V_70 ,
V_83 , V_41 ) ;
else if ( V_157 & V_194 )
F_7 ( V_45 -> V_69 , V_70 ,
V_83 , V_195 ) ;
break;
case V_196 :
if ( V_157 & V_197 )
F_7 ( V_45 -> V_69 , V_70 ,
V_95 , V_96 ) ;
else if ( V_157 & V_198 )
F_7 ( V_45 -> V_69 , V_70 ,
V_95 , V_199 ) ;
if ( V_157 & V_200 )
F_7 ( V_45 -> V_69 , V_70 ,
V_97 , V_41 ) ;
else if ( V_157 & V_201 )
F_7 ( V_45 -> V_69 , V_70 ,
V_97 , V_99 ) ;
if ( V_157 & V_202 )
F_7 ( V_45 -> V_69 , V_70 ,
V_98 , V_41 ) ;
else if ( V_157 & V_203 )
F_7 ( V_45 -> V_69 , V_70 ,
V_98 , V_99 ) ;
break;
case V_204 :
if ( V_157 & V_197 )
F_7 ( V_45 -> V_69 , V_70 ,
V_100 , V_41 ) ;
else if ( V_157 & V_198 )
F_7 ( V_45 -> V_69 , V_70 ,
V_100 , V_99 ) ;
if ( V_157 & V_200 )
F_7 ( V_45 -> V_69 , V_70 ,
V_101 , V_41 ) ;
else if ( V_157 & V_201 )
F_7 ( V_45 -> V_69 , V_70 ,
V_101 , V_99 ) ;
if ( V_157 & V_202 )
F_7 ( V_45 -> V_69 , V_70 ,
V_102 , V_41 ) ;
else if ( V_157 & V_203 )
F_7 ( V_45 -> V_69 , V_70 ,
V_102 , V_99 ) ;
break;
case V_205 :
F_7 ( V_45 -> V_69 , V_70 , V_94 ,
V_192 ) ;
F_7 ( V_45 -> V_69 , V_70 , V_86 ,
V_87 ) ;
F_7 ( V_45 -> V_69 , V_70 , V_89 ,
V_90 ) ;
F_7 ( V_45 -> V_69 , V_70 , V_81 , V_82 ) ;
F_7 ( V_45 -> V_69 , V_70 , V_79 ,
V_80 ) ;
F_7 ( V_45 -> V_69 , V_70 , V_78 ,
V_41 ) ;
if ( V_157 & V_206 ) {
F_7 ( V_45 -> V_69 , V_70 ,
V_97 , V_99 ) ;
F_7 ( V_45 -> V_69 , V_70 ,
V_95 , V_96 ) ;
F_40 ( V_45 -> V_69 , V_70 ,
V_73 , V_207 ) ;
} else {
F_7 ( V_45 -> V_69 , V_70 ,
V_101 , V_99 ) ;
F_7 ( V_45 -> V_69 , V_70 ,
V_100 , V_99 ) ;
F_40 ( V_45 -> V_69 , V_70 ,
V_73 , V_165 ) ;
}
break;
case V_208 :
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
V_158 = - 1 ;
}
F_37 ( V_159 ) ;
* V_45 -> V_107 = V_45 -> V_69 ;
F_44 () ; F_44 () ; F_44 () ; F_44 () ;
* V_26 = V_27 ;
F_44 () ; F_44 () ; F_44 () ; F_44 () ;
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
F_38 ( V_159 ) ;
return V_158 ;
}
static long F_45 ( struct V_112 * V_112 ,
unsigned int V_156 , unsigned long V_157 )
{
long V_209 ;
F_17 ( & V_116 ) ;
V_209 = F_36 ( V_112 , V_156 , V_157 ) ;
F_30 ( & V_116 ) ;
return V_209 ;
}
static T_3 F_46 ( struct V_112 * V_112 , const char * V_210 ,
T_4 V_211 , T_5 * V_212 )
{
int V_113 = F_16 ( F_33 ( V_112 ) -> V_114 ) ;
F_47 ( V_149 , V_213 ) ;
struct V_44 * V_45 ;
unsigned long V_159 ;
unsigned long V_214 , V_215 ;
unsigned long V_216 ;
unsigned long V_52 ;
unsigned long V_53 ;
if ( V_113 < 0 || V_113 >= V_117 || ! V_1 [ V_113 ] . V_2 ) {
F_11 ( F_4 ( V_46 L_10 , V_113 ) ) ;
return - V_118 ;
}
V_45 = & V_1 [ V_113 ] ;
F_48 ( F_4 ( V_46 L_33 ,
V_45 -> V_48 , V_211 , V_45 -> V_51 , V_151 ) ) ;
F_37 ( V_159 ) ;
if ( V_211 > V_151 - V_45 -> V_51 )
V_211 = V_151 - V_45 -> V_51 ;
V_52 = ( unsigned long ) V_45 -> V_52 ;
V_216 = V_52 + V_45 -> V_51 ;
F_38 ( V_159 ) ;
V_53 = ( unsigned long ) V_45 -> V_53 ;
if ( V_216 >= V_53 + V_151 )
V_216 -= V_151 ;
if ( V_216 >= V_52 )
V_214 = V_53 + V_151 - V_216 ;
else
V_214 = V_52 - V_216 ;
if ( V_214 > V_211 )
V_214 = V_211 ;
F_48 ( F_4 ( V_46 L_34 ,
V_52 , V_216 , V_214 ) ) ;
if ( F_49 ( ( void * ) V_216 , V_210 , V_214 ) )
return - V_217 ;
if ( V_214 != V_211 ) {
V_210 += V_214 ;
V_215 = V_211 - V_214 ;
F_48 ( F_4 ( V_46 L_35 ,
V_216 - V_53 , V_214 , V_215 ) ) ;
if ( F_49 ( ( void * ) V_53 , V_210 , V_215 ) )
return - V_217 ;
}
F_37 ( V_159 ) ;
V_45 -> V_51 += V_211 ;
F_38 ( V_159 ) ;
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
if ( V_112 -> V_218 & V_219 ) {
F_37 ( V_159 ) ;
if ( ! V_45 -> V_50 ) {
if ( ! V_45 -> V_22 ) {
F_50 ( V_45 ) ;
* V_145 = 1 <<
V_45 -> V_148 ;
} else
F_51 ( V_45 ,
( unsigned char * volatile ) V_45 -> V_52 , V_214 ) ;
}
F_38 ( V_159 ) ;
F_48 ( F_4 ( V_46 L_36 ,
V_45 -> V_48 , V_211 ) ) ;
return V_211 ;
}
F_52 ( & V_45 -> V_67 , & V_149 ) ;
F_53 ( V_220 ) ;
F_37 ( V_159 ) ;
if ( ! V_45 -> V_50 ) {
if ( ! V_45 -> V_22 ) {
F_50 ( V_45 ) ;
* V_145 = 1 << V_45 -> V_148 ;
} else
F_51 ( V_45 , V_45 -> V_52 , V_214 ) ;
}
F_38 ( V_159 ) ;
F_54 () ;
F_53 ( V_221 ) ;
F_55 ( & V_45 -> V_67 , & V_149 ) ;
if ( F_56 ( V_213 ) )
return - V_222 ;
F_48 ( F_4 ( V_46 L_37 , V_45 -> V_48 , V_211 ) ) ;
return V_211 ;
}
static T_3 F_57 ( struct V_112 * V_112 , char * V_210 ,
T_4 V_211 , T_5 * V_212 )
{
int V_113 = F_16 ( F_33 ( V_112 ) -> V_114 ) ;
int V_108 ;
struct V_44 * V_45 ;
unsigned char * V_109 ;
unsigned char * V_110 ;
unsigned long V_159 ;
if ( V_113 < 0 || V_113 >= V_117 || ! V_1 [ V_113 ] . V_2 ) {
F_11 ( F_4 ( V_46 L_10 , V_113 ) ) ;
return - V_118 ;
}
V_45 = & V_1 [ V_113 ] ;
F_58 ( F_4 ( V_46 L_38 ,
V_113 , V_211 , V_45 -> V_54 - V_45 -> V_55 ,
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
F_37 ( V_159 ) ;
V_109 = ( unsigned char * ) V_45 -> V_54 ;
V_110 = ( unsigned char * ) V_45 -> V_56 ;
F_38 ( V_159 ) ;
while ( V_109 == V_110 && ! V_45 -> V_223 ) {
if ( V_112 -> V_218 & V_219 )
return - V_224 ;
F_59 ( & V_45 -> V_68 ) ;
if ( F_56 ( V_213 ) )
return - V_222 ;
F_37 ( V_159 ) ;
V_109 = ( unsigned char * ) V_45 -> V_54 ;
V_110 = ( unsigned char * ) V_45 -> V_56 ;
F_38 ( V_159 ) ;
}
if ( V_45 -> V_223 )
V_108 = V_45 -> V_57 ;
else if ( V_110 > V_109 )
V_108 = V_110 - V_109 ;
else
V_108 = V_45 -> V_55 + V_45 -> V_57 - V_109 ;
V_211 = V_211 > V_108 ? V_108 : V_211 ;
if ( F_60 ( V_210 , V_109 , V_211 ) )
return - V_217 ;
F_37 ( V_159 ) ;
V_45 -> V_54 += V_211 ;
if ( V_45 -> V_54 >= V_45 -> V_55 + V_45 -> V_57 )
V_45 -> V_54 = V_45 -> V_55 ;
V_45 -> V_223 = 0 ;
F_38 ( V_159 ) ;
F_58 ( F_4 ( V_46 L_39 , V_211 ) ) ;
return V_211 ;
}
static void F_50 ( struct V_44 * V_45 )
{
switch ( F_28 ( V_70 , V_89 ,
V_45 -> V_69 ) ) {
case F_29 ( V_70 , V_89 , V_90 ) :
V_45 -> V_51 -- ;
* V_45 -> V_225 = * V_45 -> V_52 ++ ;
if ( V_45 -> V_52 >= V_45 -> V_53 + V_151 )
V_45 -> V_52 = V_45 -> V_53 ;
break;
case F_29 ( V_70 , V_89 , V_180 ) :
{
int V_226 = ( * V_45 -> V_52 ++ ) << 8 ;
V_226 |= * V_45 -> V_52 ++ ;
V_45 -> V_51 -= 2 ;
* V_45 -> V_225 = V_226 ;
if ( V_45 -> V_52 >= V_45 -> V_53 + V_151 )
V_45 -> V_52 = V_45 -> V_53 ;
break;
}
case F_29 ( V_70 , V_89 , V_182 ) :
V_45 -> V_51 -= 2 ;
* V_45 -> V_225 = * ( unsigned short * ) V_45 -> V_52 ;
V_45 -> V_52 += 2 ;
if ( V_45 -> V_52 >= V_45 -> V_53 + V_151 )
V_45 -> V_52 = V_45 -> V_53 ;
break;
case F_29 ( V_70 , V_89 , V_184 ) :
V_45 -> V_51 -= 3 ;
* V_45 -> V_225 = * ( unsigned int * ) V_45 -> V_52 ;
V_45 -> V_52 += 3 ;
if ( V_45 -> V_52 >= V_45 -> V_53 + V_151 )
V_45 -> V_52 = V_45 -> V_53 ;
break;
case F_29 ( V_70 , V_89 , V_186 ) :
V_45 -> V_51 -= 4 ;
* V_45 -> V_225 = * ( unsigned int * ) V_45 -> V_52 ;
V_45 -> V_52 += 4 ;
if ( V_45 -> V_52 >= V_45 -> V_53 + V_151 )
V_45 -> V_52 = V_45 -> V_53 ;
break;
}
}
static void F_51 ( struct V_44 * V_45 , const char * V_226 , int V_211 )
{
V_45 -> V_50 = 1 ;
V_45 -> V_227 . V_228 = 0 ;
V_45 -> V_227 . V_229 = 0 ;
V_45 -> V_227 . V_65 = V_66 | V_230 ;
V_45 -> V_227 . V_231 = V_211 ;
V_45 -> V_227 . V_210 = F_61 ( V_226 ) ;
V_45 -> V_227 . V_232 = 0 ;
* V_45 -> V_233 = F_61 ( & V_45 -> V_227 ) ;
* V_45 -> V_234 = F_9 ( V_235 , V_156 , V_109 ) ;
F_62 ( F_4 ( V_46 L_40 ,
( unsigned long ) V_226 , V_211 ) ) ;
}
static void F_25 ( struct V_44 * V_45 )
{
int V_236 ;
unsigned long V_210 ;
V_45 -> V_56 = V_45 -> V_55 ;
if ( V_45 -> V_56 > V_45 -> V_55 + V_45 -> V_57 ) {
F_27 ( L_41 ) ;
return;
}
V_210 = F_61 ( V_45 -> V_237 ) ;
for ( V_236 = 0 ; V_236 < V_64 ; V_236 ++ ) {
V_45 -> V_62 [ V_236 ] . V_231 = V_45 -> V_59 ;
V_45 -> V_62 [ V_236 ] . V_65 = V_238 ;
V_45 -> V_62 [ V_236 ] . V_229 = F_61 ( & V_45 -> V_62 [ V_236 + 1 ] ) ;
V_45 -> V_62 [ V_236 ] . V_210 = V_210 ;
V_45 -> V_62 [ V_236 ] . V_228 = 0 ;
V_45 -> V_62 [ V_236 ] . V_232 = 0 ;
V_45 -> V_62 [ V_236 ] . V_239 = 0 ;
V_210 += V_45 -> V_59 ;
F_63 ( & V_45 -> V_62 [ V_236 ] ) ;
}
V_45 -> V_62 [ V_236 - 1 ] . V_229 = F_61 ( & V_45 -> V_62 [ 0 ] ) ;
V_45 -> V_62 [ V_236 - 1 ] . V_65 |= V_66 ;
V_45 -> V_61 = & V_45 -> V_62 [ 0 ] ;
V_45 -> V_63 = & V_45 -> V_62 [ V_64 - 1 ] ;
* V_45 -> V_240 = F_61 ( V_45 -> V_61 ) ;
* V_45 -> V_241 = F_9 ( V_235 , V_156 , V_109 ) ;
}
static T_6 V_121 ( int V_242 , void * V_243 )
{
unsigned long V_244 = * V_245 ;
struct V_246 * V_247 ;
unsigned int V_248 ;
int V_249 = 0 ;
int V_236 ;
for ( V_236 = 0 ; V_236 < V_117 ; V_236 ++ ) {
struct V_44 * V_45 = & V_1 [ V_236 ] ;
if ( ! V_45 -> V_2 || ! V_45 -> V_22 )
continue;
if ( ! ( V_244 & ( 1 << V_45 -> V_250 ) ) )
continue;
V_249 = 1 ;
* V_45 -> V_251 =
F_9 (R_DMA_CH0_CLR_INTR, clr_eop, do) |
F_9 (R_DMA_CH0_CLR_INTR, clr_descr, do) ;
V_247 = & V_45 -> V_227 ;
if ( ! ( V_247 -> V_232 & V_252 ) )
V_248 = V_247 -> V_231 ;
else
V_248 = V_247 -> V_228 ;
V_45 -> V_51 -= V_248 ;
V_45 -> V_52 += V_248 ;
if ( V_45 -> V_52 >= V_45 -> V_53 + V_151 )
V_45 -> V_52 = V_45 -> V_53 ;
if ( V_45 -> V_51 ) {
int V_214 = V_45 -> V_53 + V_151 - V_45 -> V_52 ;
if ( V_214 > V_45 -> V_51 )
V_214 = V_45 -> V_51 ;
F_62 ( F_4 ( V_46
L_42 , V_248 , V_214 ) ) ;
F_51 ( V_45 , V_45 -> V_52 , V_214 ) ;
} else {
F_62 ( F_4 ( V_46
L_43 , V_248 ) ) ;
V_45 -> V_50 = 0 ;
}
F_64 ( & V_45 -> V_67 ) ;
}
return F_65 ( V_249 ) ;
}
static T_6 V_122 ( int V_242 , void * V_243 )
{
unsigned long V_244 = * V_245 ;
int V_236 ;
int V_249 = 0 ;
for ( V_236 = 0 ; V_236 < V_117 ; V_236 ++ ) {
struct V_44 * V_45 = & V_1 [ V_236 ] ;
if ( ! V_45 -> V_2 || ! V_45 -> V_22 )
continue;
if ( ! ( V_244 & ( 1 << V_45 -> V_253 ) ) )
continue;
V_249 = 1 ;
while ( * V_45 -> V_254 !=
F_61 ( V_45 -> V_61 ) ) {
if ( V_45 -> V_56 + V_45 -> V_59 > V_45 -> V_55 +
V_45 -> V_57 ) {
int V_255 = V_45 -> V_55 +
V_45 -> V_57 - V_45 -> V_56 ;
memcpy ( V_45 -> V_56 ,
F_66 ( V_45 -> V_61 -> V_210 ) ,
V_255 ) ;
memcpy ( V_45 -> V_55 ,
F_66 ( V_45 -> V_61 -> V_210 +
V_255 ) ,
V_45 -> V_59 - V_255 ) ;
V_45 -> V_56 = V_45 -> V_55 +
V_45 -> V_59 - V_255 ;
} else {
memcpy ( V_45 -> V_56 ,
F_66 ( V_45 -> V_61 -> V_210 ) ,
V_45 -> V_59 ) ;
V_45 -> V_56 += V_45 -> V_59 ;
if ( V_45 -> V_56 >= V_45 -> V_55
+ V_45 -> V_57 )
V_45 -> V_56 = V_45 -> V_55 ;
}
if ( V_45 -> V_56 == V_45 -> V_54 )
V_45 -> V_223 = 1 ;
F_63 ( V_45 -> V_61 ) ;
V_45 -> V_61 -> V_65 |= V_66 ;
V_45 -> V_63 -> V_65 &= ~ V_66 ;
V_45 -> V_63 = F_66 ( ( unsigned )
V_45 -> V_61 ) ;
V_45 -> V_61 = F_66 ( ( unsigned )
V_45 -> V_61 -> V_229 ) ;
F_64 ( & V_45 -> V_68 ) ;
* V_45 -> V_241 = F_9 ( V_256 ,
V_156 , V_257 ) ;
* V_45 -> V_258 = F_9 (R_DMA_CH0_CLR_INTR,
clr_descr, do) ;
}
}
return F_65 ( V_249 ) ;
}
static T_6 V_136 ( int V_242 , void * V_243 )
{
int V_236 ;
int V_249 = 0 ;
for ( V_236 = 0 ; V_236 < V_117 ; V_236 ++ ) {
struct V_44 * V_45 = & V_1 [ V_236 ] ;
if ( ! V_45 -> V_2 || V_45 -> V_22 )
continue;
if ( * V_259 & ( 1 << V_45 -> V_146 ) ) {
V_249 = 1 ;
switch ( V_45 -> V_69 &
F_67 ( V_70 , V_89 ) ) {
case F_9 ( V_70 , V_89 , V_90 ) :
* V_45 -> V_56 ++ =
* ( volatile char * ) V_45 -> V_260 ;
break;
case F_9 ( V_70 , V_89 , V_180 ) :
{
int V_226 = * ( unsigned short * ) V_45 -> V_260 ;
* V_45 -> V_56 = ( V_226 & 0x0ff0 ) >> 4 ;
* ( V_45 -> V_56 + 1 ) = V_226 & 0x0f ;
V_45 -> V_56 += 2 ;
break;
}
case F_9 ( V_70 , V_89 , V_182 ) :
* ( unsigned short * ) V_45 -> V_56 =
* ( volatile unsigned short * ) V_45 -> V_260 ;
V_45 -> V_56 += 2 ;
break;
case F_9 ( V_70 , V_89 , V_184 ) :
* ( unsigned int * ) V_45 -> V_56 = * V_45 -> V_260 ;
V_45 -> V_56 += 3 ;
break;
case F_9 ( V_70 , V_89 , V_186 ) :
* ( unsigned int * ) V_45 -> V_56 = * V_45 -> V_260 ;
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
F_64 ( & V_45 -> V_68 ) ;
}
}
if ( * V_259 & ( 1 << V_45 -> V_148 ) ) {
if ( V_45 -> V_51 > 0 ) {
F_50 ( V_45 ) ;
} else {
* V_147 = 1 <<
V_45 -> V_148 ;
F_64 ( & V_45 -> V_67 ) ;
}
}
}
return F_65 ( V_249 ) ;
}
