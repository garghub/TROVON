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
V_137 ,
L_25 ,
& V_1 [ 0 ] ) ) {
F_4 ( V_5 L_13
L_26 ) ;
goto V_119;
}
} else if ( V_45 == & V_1 [ 1 ] ) {
if ( F_19 ( 8 ,
V_136 ,
V_137 ,
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
if ( V_73 == F_29 ( V_70 , V_73 , V_138 ) ||
V_73 == F_29 ( V_70 , V_73 , V_139 ) ||
V_73 == F_29 ( V_70 , V_73 , V_140 ) ||
V_73 == F_29 ( V_70 , V_73 , V_141 ) ) {
F_7 ( V_45 -> V_69 , V_70 , V_84 ,
V_142 ) ;
F_7 ( V_45 -> V_69 , V_70 , V_88 ,
V_143 ) ;
F_7 ( V_45 -> V_69 , V_70 , V_76 ,
V_143 ) ;
V_45 -> V_47 = 1 ;
* V_45 -> V_107 = V_45 -> V_69 ;
if ( ! V_45 -> V_22 )
* V_144 = 1 << V_45 -> V_145 ;
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
* V_146 = ( ( 1 << V_45 -> V_145 ) |
( 1 << V_45 -> V_147 ) ) ;
return 0 ;
}
static unsigned int F_32 ( struct V_112 * V_112 , T_2 * V_148 )
{
int V_113 = F_16 ( F_33 ( V_112 ) -> V_114 ) ;
unsigned int V_149 = 0 ;
struct V_44 * V_45 ;
F_34 (static unsigned int prev_mask = 0 ) ;
V_45 = & V_1 [ V_113 ] ;
F_35 ( V_112 , & V_45 -> V_67 , V_148 ) ;
F_35 ( V_112 , & V_45 -> V_68 , V_148 ) ;
if ( V_45 -> V_51 < V_150 )
V_149 |= V_151 | V_152 ;
if ( F_13 ( V_45 ) >= V_45 -> V_59 )
V_149 |= V_153 | V_154 ;
F_34 (if (mask != prev_mask)
printk(KERN_DEBUG L_29,
mask,
mask & POLLOUT ? L_30 : L_31,
mask & POLLIN ? L_32 : L_31);
prev_mask = mask;
) ;
return V_149 ;
}
static int F_36 ( struct V_112 * V_112 ,
unsigned int V_155 , unsigned long V_156 )
{
int V_157 = 0 ;
unsigned long V_158 ;
int V_113 = F_16 ( F_33 ( V_112 ) -> V_114 ) ;
struct V_44 * V_45 ;
if ( V_113 < 0 || V_113 >= V_117 || ! V_1 [ V_113 ] . V_2 ) {
F_11 ( F_4 ( V_46 L_10 , V_113 ) ) ;
return - 1 ;
}
V_45 = & V_1 [ V_113 ] ;
F_37 ( V_158 ) ;
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
F_38 ( V_158 ) ;
switch ( V_155 ) {
case V_159 :
if ( F_39 ( V_156 ) == V_160 ) {
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
F_41 ( V_156 ) ) ;
F_40 ( V_27 ,
V_26 , V_36 ,
F_42 ( V_156 ) ) ;
F_40 ( V_27 ,
V_26 , V_38 ,
F_43 ( V_156 ) ) ;
} else {
F_40 ( V_45 -> V_69 , V_70 ,
V_71 , F_39 ( V_156 ) ) ;
if ( V_113 )
F_7 ( V_27 ,
V_26 , V_32 ,
V_161 ) ;
else
F_7 ( V_27 ,
V_26 , V_28 ,
V_161 ) ;
}
break;
case V_162 :
if ( V_156 > 5 )
return - V_163 ;
if ( V_156 == V_164 || V_156 == V_165 )
* V_146 = 1 << V_45 -> V_145 ;
else if ( ! V_45 -> V_22 )
* V_144 = 1 << V_45 -> V_145 ;
F_40 ( V_45 -> V_69 , V_70 , V_73 , V_156 ) ;
break;
case V_166 :
if ( V_156 & V_167 )
F_7 ( V_45 -> V_69 , V_70 ,
V_78 , V_41 ) ;
else if ( V_156 & V_168 )
F_7 ( V_45 -> V_69 , V_70 ,
V_78 , V_169 ) ;
if ( V_156 & V_170 )
F_7 ( V_45 -> V_69 , V_70 ,
V_79 , V_171 ) ;
else if ( V_156 & V_172 )
F_7 ( V_45 -> V_69 , V_70 ,
V_79 , V_80 ) ;
else if ( V_156 & V_173 )
F_7 ( V_45 -> V_69 , V_70 ,
V_79 , V_174 ) ;
if ( V_156 & V_175 )
F_7 ( V_45 -> V_69 , V_70 ,
V_81 , V_82 ) ;
else if ( V_156 & V_176 )
F_7 ( V_45 -> V_69 , V_70 ,
V_81 , V_106 ) ;
if ( V_156 & V_177 )
F_7 ( V_45 -> V_69 , V_70 ,
V_89 , V_90 ) ;
else if ( V_156 & V_178 )
F_7 ( V_45 -> V_69 , V_70 ,
V_89 , V_179 ) ;
else if ( V_156 & V_180 )
F_7 ( V_45 -> V_69 , V_70 ,
V_89 , V_181 ) ;
else if ( V_156 & V_182 )
F_7 ( V_45 -> V_69 , V_70 ,
V_89 , V_183 ) ;
else if ( V_156 & V_184 )
F_7 ( V_45 -> V_69 , V_70 ,
V_89 , V_185 ) ;
if ( V_156 & V_186 )
F_7 ( V_45 -> V_69 , V_70 ,
V_86 , V_87 ) ;
else if ( V_156 & V_187 )
F_7 ( V_45 -> V_69 , V_70 ,
V_86 , V_188 ) ;
if ( V_156 & V_189 )
F_7 ( V_45 -> V_69 , V_70 ,
V_94 , V_2 ) ;
else if ( V_156 & V_190 )
F_7 ( V_45 -> V_69 , V_70 ,
V_94 , V_191 ) ;
if ( V_156 & V_192 )
F_7 ( V_45 -> V_69 , V_70 ,
V_83 , V_41 ) ;
else if ( V_156 & V_193 )
F_7 ( V_45 -> V_69 , V_70 ,
V_83 , V_194 ) ;
break;
case V_195 :
if ( V_156 & V_196 )
F_7 ( V_45 -> V_69 , V_70 ,
V_95 , V_96 ) ;
else if ( V_156 & V_197 )
F_7 ( V_45 -> V_69 , V_70 ,
V_95 , V_198 ) ;
if ( V_156 & V_199 )
F_7 ( V_45 -> V_69 , V_70 ,
V_97 , V_41 ) ;
else if ( V_156 & V_200 )
F_7 ( V_45 -> V_69 , V_70 ,
V_97 , V_99 ) ;
if ( V_156 & V_201 )
F_7 ( V_45 -> V_69 , V_70 ,
V_98 , V_41 ) ;
else if ( V_156 & V_202 )
F_7 ( V_45 -> V_69 , V_70 ,
V_98 , V_99 ) ;
break;
case V_203 :
if ( V_156 & V_196 )
F_7 ( V_45 -> V_69 , V_70 ,
V_100 , V_41 ) ;
else if ( V_156 & V_197 )
F_7 ( V_45 -> V_69 , V_70 ,
V_100 , V_99 ) ;
if ( V_156 & V_199 )
F_7 ( V_45 -> V_69 , V_70 ,
V_101 , V_41 ) ;
else if ( V_156 & V_200 )
F_7 ( V_45 -> V_69 , V_70 ,
V_101 , V_99 ) ;
if ( V_156 & V_201 )
F_7 ( V_45 -> V_69 , V_70 ,
V_102 , V_41 ) ;
else if ( V_156 & V_202 )
F_7 ( V_45 -> V_69 , V_70 ,
V_102 , V_99 ) ;
break;
case V_204 :
F_7 ( V_45 -> V_69 , V_70 , V_94 ,
V_191 ) ;
F_7 ( V_45 -> V_69 , V_70 , V_86 ,
V_87 ) ;
F_7 ( V_45 -> V_69 , V_70 , V_89 ,
V_90 ) ;
F_7 ( V_45 -> V_69 , V_70 , V_81 , V_82 ) ;
F_7 ( V_45 -> V_69 , V_70 , V_79 ,
V_80 ) ;
F_7 ( V_45 -> V_69 , V_70 , V_78 ,
V_41 ) ;
if ( V_156 & V_205 ) {
F_7 ( V_45 -> V_69 , V_70 ,
V_97 , V_99 ) ;
F_7 ( V_45 -> V_69 , V_70 ,
V_95 , V_96 ) ;
F_40 ( V_45 -> V_69 , V_70 ,
V_73 , V_206 ) ;
} else {
F_7 ( V_45 -> V_69 , V_70 ,
V_101 , V_99 ) ;
F_7 ( V_45 -> V_69 , V_70 ,
V_100 , V_99 ) ;
F_40 ( V_45 -> V_69 , V_70 ,
V_73 , V_164 ) ;
}
break;
case V_207 :
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
V_157 = - 1 ;
}
F_37 ( V_158 ) ;
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
F_38 ( V_158 ) ;
return V_157 ;
}
static long F_45 ( struct V_112 * V_112 ,
unsigned int V_155 , unsigned long V_156 )
{
long V_208 ;
F_17 ( & V_116 ) ;
V_208 = F_36 ( V_112 , V_155 , V_156 ) ;
F_30 ( & V_116 ) ;
return V_208 ;
}
static T_3 F_46 ( struct V_112 * V_112 , const char * V_209 ,
T_4 V_210 , T_5 * V_211 )
{
int V_113 = F_16 ( F_33 ( V_112 ) -> V_114 ) ;
F_47 ( V_148 , V_212 ) ;
struct V_44 * V_45 ;
unsigned long V_158 ;
unsigned long V_213 , V_214 ;
unsigned long V_215 ;
unsigned long V_52 ;
unsigned long V_53 ;
if ( V_113 < 0 || V_113 >= V_117 || ! V_1 [ V_113 ] . V_2 ) {
F_11 ( F_4 ( V_46 L_10 , V_113 ) ) ;
return - V_118 ;
}
V_45 = & V_1 [ V_113 ] ;
F_48 ( F_4 ( V_46 L_33 ,
V_45 -> V_48 , V_210 , V_45 -> V_51 , V_150 ) ) ;
F_37 ( V_158 ) ;
if ( V_210 > V_150 - V_45 -> V_51 )
V_210 = V_150 - V_45 -> V_51 ;
V_52 = ( unsigned long ) V_45 -> V_52 ;
V_215 = V_52 + V_45 -> V_51 ;
F_38 ( V_158 ) ;
V_53 = ( unsigned long ) V_45 -> V_53 ;
if ( V_215 >= V_53 + V_150 )
V_215 -= V_150 ;
if ( V_215 >= V_52 )
V_213 = V_53 + V_150 - V_215 ;
else
V_213 = V_52 - V_215 ;
if ( V_213 > V_210 )
V_213 = V_210 ;
F_48 ( F_4 ( V_46 L_34 ,
V_52 , V_215 , V_213 ) ) ;
if ( F_49 ( ( void * ) V_215 , V_209 , V_213 ) )
return - V_216 ;
if ( V_213 != V_210 ) {
V_209 += V_213 ;
V_214 = V_210 - V_213 ;
F_48 ( F_4 ( V_46 L_35 ,
V_215 - V_53 , V_213 , V_214 ) ) ;
if ( F_49 ( ( void * ) V_53 , V_209 , V_214 ) )
return - V_216 ;
}
F_37 ( V_158 ) ;
V_45 -> V_51 += V_210 ;
F_38 ( V_158 ) ;
if ( ! V_45 -> V_47 ) {
F_7 ( V_45 -> V_69 , V_70 , V_84 ,
V_142 ) ;
F_7 ( V_45 -> V_69 , V_70 , V_88 ,
V_143 ) ;
F_7 ( V_45 -> V_69 , V_70 , V_76 ,
V_143 ) ;
V_45 -> V_47 = 1 ;
}
* V_45 -> V_107 = V_45 -> V_69 ;
if ( V_112 -> V_217 & V_218 ) {
F_37 ( V_158 ) ;
if ( ! V_45 -> V_50 ) {
if ( ! V_45 -> V_22 ) {
F_50 ( V_45 ) ;
* V_144 = 1 <<
V_45 -> V_147 ;
} else
F_51 ( V_45 ,
( unsigned char * volatile ) V_45 -> V_52 , V_213 ) ;
}
F_38 ( V_158 ) ;
F_48 ( F_4 ( V_46 L_36 ,
V_45 -> V_48 , V_210 ) ) ;
return V_210 ;
}
F_52 ( & V_45 -> V_67 , & V_148 ) ;
F_53 ( V_219 ) ;
F_37 ( V_158 ) ;
if ( ! V_45 -> V_50 ) {
if ( ! V_45 -> V_22 ) {
F_50 ( V_45 ) ;
* V_144 = 1 << V_45 -> V_147 ;
} else
F_51 ( V_45 , V_45 -> V_52 , V_213 ) ;
}
F_38 ( V_158 ) ;
F_54 () ;
F_53 ( V_220 ) ;
F_55 ( & V_45 -> V_67 , & V_148 ) ;
if ( F_56 ( V_212 ) )
return - V_221 ;
F_48 ( F_4 ( V_46 L_37 , V_45 -> V_48 , V_210 ) ) ;
return V_210 ;
}
static T_3 F_57 ( struct V_112 * V_112 , char * V_209 ,
T_4 V_210 , T_5 * V_211 )
{
int V_113 = F_16 ( F_33 ( V_112 ) -> V_114 ) ;
int V_108 ;
struct V_44 * V_45 ;
unsigned char * V_109 ;
unsigned char * V_110 ;
unsigned long V_158 ;
if ( V_113 < 0 || V_113 >= V_117 || ! V_1 [ V_113 ] . V_2 ) {
F_11 ( F_4 ( V_46 L_10 , V_113 ) ) ;
return - V_118 ;
}
V_45 = & V_1 [ V_113 ] ;
F_58 ( F_4 ( V_46 L_38 ,
V_113 , V_210 , V_45 -> V_54 - V_45 -> V_55 ,
V_45 -> V_56 - V_45 -> V_55 , V_45 -> V_57 ) ) ;
if ( ! V_45 -> V_47 ) {
F_7 ( V_45 -> V_69 , V_70 , V_84 ,
V_142 ) ;
F_7 ( V_45 -> V_69 , V_70 , V_88 ,
V_143 ) ;
F_7 ( V_45 -> V_69 , V_70 , V_76 ,
V_143 ) ;
V_45 -> V_47 = 1 ;
}
* V_45 -> V_107 = V_45 -> V_69 ;
F_37 ( V_158 ) ;
V_109 = ( unsigned char * ) V_45 -> V_54 ;
V_110 = ( unsigned char * ) V_45 -> V_56 ;
F_38 ( V_158 ) ;
while ( V_109 == V_110 && ! V_45 -> V_222 ) {
if ( V_112 -> V_217 & V_218 )
return - V_223 ;
F_59 ( V_45 -> V_68 ,
! ( V_109 == V_110 && ! V_45 -> V_222 ) ) ;
if ( F_56 ( V_212 ) )
return - V_221 ;
F_37 ( V_158 ) ;
V_109 = ( unsigned char * ) V_45 -> V_54 ;
V_110 = ( unsigned char * ) V_45 -> V_56 ;
F_38 ( V_158 ) ;
}
if ( V_45 -> V_222 )
V_108 = V_45 -> V_57 ;
else if ( V_110 > V_109 )
V_108 = V_110 - V_109 ;
else
V_108 = V_45 -> V_55 + V_45 -> V_57 - V_109 ;
V_210 = V_210 > V_108 ? V_108 : V_210 ;
if ( F_60 ( V_209 , V_109 , V_210 ) )
return - V_216 ;
F_37 ( V_158 ) ;
V_45 -> V_54 += V_210 ;
if ( V_45 -> V_54 >= V_45 -> V_55 + V_45 -> V_57 )
V_45 -> V_54 = V_45 -> V_55 ;
V_45 -> V_222 = 0 ;
F_38 ( V_158 ) ;
F_58 ( F_4 ( V_46 L_39 , V_210 ) ) ;
return V_210 ;
}
static void F_50 ( struct V_44 * V_45 )
{
switch ( F_28 ( V_70 , V_89 ,
V_45 -> V_69 ) ) {
case F_29 ( V_70 , V_89 , V_90 ) :
V_45 -> V_51 -- ;
* V_45 -> V_224 = * V_45 -> V_52 ++ ;
if ( V_45 -> V_52 >= V_45 -> V_53 + V_150 )
V_45 -> V_52 = V_45 -> V_53 ;
break;
case F_29 ( V_70 , V_89 , V_179 ) :
{
int V_225 = ( * V_45 -> V_52 ++ ) << 8 ;
V_225 |= * V_45 -> V_52 ++ ;
V_45 -> V_51 -= 2 ;
* V_45 -> V_224 = V_225 ;
if ( V_45 -> V_52 >= V_45 -> V_53 + V_150 )
V_45 -> V_52 = V_45 -> V_53 ;
break;
}
case F_29 ( V_70 , V_89 , V_181 ) :
V_45 -> V_51 -= 2 ;
* V_45 -> V_224 = * ( unsigned short * ) V_45 -> V_52 ;
V_45 -> V_52 += 2 ;
if ( V_45 -> V_52 >= V_45 -> V_53 + V_150 )
V_45 -> V_52 = V_45 -> V_53 ;
break;
case F_29 ( V_70 , V_89 , V_183 ) :
V_45 -> V_51 -= 3 ;
* V_45 -> V_224 = * ( unsigned int * ) V_45 -> V_52 ;
V_45 -> V_52 += 3 ;
if ( V_45 -> V_52 >= V_45 -> V_53 + V_150 )
V_45 -> V_52 = V_45 -> V_53 ;
break;
case F_29 ( V_70 , V_89 , V_185 ) :
V_45 -> V_51 -= 4 ;
* V_45 -> V_224 = * ( unsigned int * ) V_45 -> V_52 ;
V_45 -> V_52 += 4 ;
if ( V_45 -> V_52 >= V_45 -> V_53 + V_150 )
V_45 -> V_52 = V_45 -> V_53 ;
break;
}
}
static void F_51 ( struct V_44 * V_45 , const char * V_225 , int V_210 )
{
V_45 -> V_50 = 1 ;
V_45 -> V_226 . V_227 = 0 ;
V_45 -> V_226 . V_228 = 0 ;
V_45 -> V_226 . V_65 = V_66 | V_229 ;
V_45 -> V_226 . V_230 = V_210 ;
V_45 -> V_226 . V_209 = F_61 ( V_225 ) ;
V_45 -> V_226 . V_231 = 0 ;
* V_45 -> V_232 = F_61 ( & V_45 -> V_226 ) ;
* V_45 -> V_233 = F_9 ( V_234 , V_155 , V_109 ) ;
F_62 ( F_4 ( V_46 L_40 ,
( unsigned long ) V_225 , V_210 ) ) ;
}
static void F_25 ( struct V_44 * V_45 )
{
int V_235 ;
unsigned long V_209 ;
V_45 -> V_56 = V_45 -> V_55 ;
if ( V_45 -> V_56 > V_45 -> V_55 + V_45 -> V_57 ) {
F_27 ( L_41 ) ;
return;
}
V_209 = F_61 ( V_45 -> V_236 ) ;
for ( V_235 = 0 ; V_235 < V_64 ; V_235 ++ ) {
V_45 -> V_62 [ V_235 ] . V_230 = V_45 -> V_59 ;
V_45 -> V_62 [ V_235 ] . V_65 = V_237 ;
V_45 -> V_62 [ V_235 ] . V_228 = F_61 ( & V_45 -> V_62 [ V_235 + 1 ] ) ;
V_45 -> V_62 [ V_235 ] . V_209 = V_209 ;
V_45 -> V_62 [ V_235 ] . V_227 = 0 ;
V_45 -> V_62 [ V_235 ] . V_231 = 0 ;
V_45 -> V_62 [ V_235 ] . V_238 = 0 ;
V_209 += V_45 -> V_59 ;
F_63 ( & V_45 -> V_62 [ V_235 ] ) ;
}
V_45 -> V_62 [ V_235 - 1 ] . V_228 = F_61 ( & V_45 -> V_62 [ 0 ] ) ;
V_45 -> V_62 [ V_235 - 1 ] . V_65 |= V_66 ;
V_45 -> V_61 = & V_45 -> V_62 [ 0 ] ;
V_45 -> V_63 = & V_45 -> V_62 [ V_64 - 1 ] ;
* V_45 -> V_239 = F_61 ( V_45 -> V_61 ) ;
* V_45 -> V_240 = F_9 ( V_234 , V_155 , V_109 ) ;
}
static T_6 V_121 ( int V_241 , void * V_242 )
{
unsigned long V_243 = * V_244 ;
struct V_245 * V_246 ;
unsigned int V_247 ;
int V_248 = 0 ;
int V_235 ;
for ( V_235 = 0 ; V_235 < V_117 ; V_235 ++ ) {
struct V_44 * V_45 = & V_1 [ V_235 ] ;
if ( ! V_45 -> V_2 || ! V_45 -> V_22 )
continue;
if ( ! ( V_243 & ( 1 << V_45 -> V_249 ) ) )
continue;
V_248 = 1 ;
* V_45 -> V_250 =
F_9 (R_DMA_CH0_CLR_INTR, clr_eop, do) |
F_9 (R_DMA_CH0_CLR_INTR, clr_descr, do) ;
V_246 = & V_45 -> V_226 ;
if ( ! ( V_246 -> V_231 & V_251 ) )
V_247 = V_246 -> V_230 ;
else
V_247 = V_246 -> V_227 ;
V_45 -> V_51 -= V_247 ;
V_45 -> V_52 += V_247 ;
if ( V_45 -> V_52 >= V_45 -> V_53 + V_150 )
V_45 -> V_52 = V_45 -> V_53 ;
if ( V_45 -> V_51 ) {
int V_213 = V_45 -> V_53 + V_150 - V_45 -> V_52 ;
if ( V_213 > V_45 -> V_51 )
V_213 = V_45 -> V_51 ;
F_62 ( F_4 ( V_46
L_42 , V_247 , V_213 ) ) ;
F_51 ( V_45 , V_45 -> V_52 , V_213 ) ;
} else {
F_62 ( F_4 ( V_46
L_43 , V_247 ) ) ;
V_45 -> V_50 = 0 ;
}
F_64 ( & V_45 -> V_67 ) ;
}
return F_65 ( V_248 ) ;
}
static T_6 V_122 ( int V_241 , void * V_242 )
{
unsigned long V_243 = * V_244 ;
int V_235 ;
int V_248 = 0 ;
for ( V_235 = 0 ; V_235 < V_117 ; V_235 ++ ) {
struct V_44 * V_45 = & V_1 [ V_235 ] ;
if ( ! V_45 -> V_2 || ! V_45 -> V_22 )
continue;
if ( ! ( V_243 & ( 1 << V_45 -> V_252 ) ) )
continue;
V_248 = 1 ;
while ( * V_45 -> V_253 !=
F_61 ( V_45 -> V_61 ) ) {
if ( V_45 -> V_56 + V_45 -> V_59 > V_45 -> V_55 +
V_45 -> V_57 ) {
int V_254 = V_45 -> V_55 +
V_45 -> V_57 - V_45 -> V_56 ;
memcpy ( V_45 -> V_56 ,
F_66 ( V_45 -> V_61 -> V_209 ) ,
V_254 ) ;
memcpy ( V_45 -> V_55 ,
F_66 ( V_45 -> V_61 -> V_209 +
V_254 ) ,
V_45 -> V_59 - V_254 ) ;
V_45 -> V_56 = V_45 -> V_55 +
V_45 -> V_59 - V_254 ;
} else {
memcpy ( V_45 -> V_56 ,
F_66 ( V_45 -> V_61 -> V_209 ) ,
V_45 -> V_59 ) ;
V_45 -> V_56 += V_45 -> V_59 ;
if ( V_45 -> V_56 >= V_45 -> V_55
+ V_45 -> V_57 )
V_45 -> V_56 = V_45 -> V_55 ;
}
if ( V_45 -> V_56 == V_45 -> V_54 )
V_45 -> V_222 = 1 ;
F_63 ( V_45 -> V_61 ) ;
V_45 -> V_61 -> V_65 |= V_66 ;
V_45 -> V_63 -> V_65 &= ~ V_66 ;
V_45 -> V_63 = F_66 ( ( unsigned )
V_45 -> V_61 ) ;
V_45 -> V_61 = F_66 ( ( unsigned )
V_45 -> V_61 -> V_228 ) ;
F_64 ( & V_45 -> V_68 ) ;
* V_45 -> V_240 = F_9 ( V_255 ,
V_155 , V_256 ) ;
* V_45 -> V_257 = F_9 (R_DMA_CH0_CLR_INTR,
clr_descr, do) ;
}
}
return F_65 ( V_248 ) ;
}
static T_6 V_136 ( int V_241 , void * V_242 )
{
int V_235 ;
int V_248 = 0 ;
for ( V_235 = 0 ; V_235 < V_117 ; V_235 ++ ) {
struct V_44 * V_45 = & V_1 [ V_235 ] ;
if ( ! V_45 -> V_2 || V_45 -> V_22 )
continue;
if ( * V_258 & ( 1 << V_45 -> V_145 ) ) {
V_248 = 1 ;
switch ( V_45 -> V_69 &
F_67 ( V_70 , V_89 ) ) {
case F_9 ( V_70 , V_89 , V_90 ) :
* V_45 -> V_56 ++ =
* ( volatile char * ) V_45 -> V_259 ;
break;
case F_9 ( V_70 , V_89 , V_179 ) :
{
int V_225 = * ( unsigned short * ) V_45 -> V_259 ;
* V_45 -> V_56 = ( V_225 & 0x0ff0 ) >> 4 ;
* ( V_45 -> V_56 + 1 ) = V_225 & 0x0f ;
V_45 -> V_56 += 2 ;
break;
}
case F_9 ( V_70 , V_89 , V_181 ) :
* ( unsigned short * ) V_45 -> V_56 =
* ( volatile unsigned short * ) V_45 -> V_259 ;
V_45 -> V_56 += 2 ;
break;
case F_9 ( V_70 , V_89 , V_183 ) :
* ( unsigned int * ) V_45 -> V_56 = * V_45 -> V_259 ;
V_45 -> V_56 += 3 ;
break;
case F_9 ( V_70 , V_89 , V_185 ) :
* ( unsigned int * ) V_45 -> V_56 = * V_45 -> V_259 ;
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
if ( * V_258 & ( 1 << V_45 -> V_147 ) ) {
if ( V_45 -> V_51 > 0 ) {
F_50 ( V_45 ) ;
} else {
* V_146 = 1 <<
V_45 -> V_147 ;
F_64 ( & V_45 -> V_67 ) ;
}
}
}
return F_65 ( V_248 ) ;
}
