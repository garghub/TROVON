static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 . V_8 , V_2 -> V_9 ) ;
struct V_10 * V_11 = F_3 ( V_6 ) ;
struct V_12 * V_13 = V_11 -> V_13 ;
struct V_14 * V_15 = & V_13 -> V_16 . V_15 ;
struct V_1 * V_17 ;
struct V_18 * V_19 ;
unsigned long V_20 ;
struct V_21 V_22 ;
struct V_23 * V_24 ;
struct V_25 V_26 ;
T_1 V_27 ;
enum V_28 V_29 , V_30 ;
F_4 () ;
V_17 = F_5 ( V_15 , & V_6 -> V_31 , V_4 -> V_32 . V_33 ) ;
if ( ! V_17 ) {
V_6 -> V_31 . V_34 ++ ;
F_6 () ;
return;
}
V_29 = V_2 -> V_7 . V_35 == V_36 ?
V_37 : V_2 -> V_7 . V_35 ;
V_30 = V_17 -> V_7 . V_35 == V_36 ?
V_37 : V_17 -> V_7 . V_35 ;
if ( V_30 != V_29 ||
! ( V_38 [ V_17 -> V_39 ] & V_40 ) ) {
V_6 -> V_31 . V_34 ++ ;
goto V_41;
}
V_19 = & F_7 ( V_4 -> V_32 . V_42 ) -> V_43 ;
V_11 = F_3 ( V_6 ) ;
if ( V_17 -> V_7 . V_44 > 1 ) {
T_2 V_45 ;
T_2 V_46 ;
T_2 V_47 ;
V_45 = F_8 ( V_6 , V_2 -> V_48 ) ;
V_46 = F_8 ( V_6 , V_17 -> V_48 ) ;
if ( F_9 ( ! F_10 ( V_45 , V_46 ) ) ) {
V_47 = V_11 -> V_47 | ( V_19 -> V_49 &
( ( 1 << V_11 -> V_50 ) - 1 ) ) ;
F_11 ( V_6 , V_51 , V_45 ,
V_19 -> V_52 ,
V_2 -> V_7 . V_44 , V_17 -> V_7 . V_44 ,
F_12 ( V_47 ) ,
F_12 ( V_19 -> V_53 ) ) ;
goto V_41;
}
}
if ( V_17 -> V_7 . V_44 ) {
T_1 V_54 ;
V_54 = ( int ) V_4 -> V_32 . V_55 < 0 ?
V_2 -> V_54 : V_4 -> V_32 . V_55 ;
if ( F_9 ( V_54 != V_17 -> V_54 ) ) {
T_2 V_47 ;
V_47 = V_11 -> V_47 | ( V_19 -> V_49 &
( ( 1 << V_11 -> V_50 ) - 1 ) ) ;
F_11 ( V_6 , V_56 , V_54 ,
V_19 -> V_52 ,
V_2 -> V_7 . V_44 , V_17 -> V_7 . V_44 ,
F_12 ( V_47 ) ,
F_12 ( V_19 -> V_53 ) ) ;
goto V_41;
}
}
V_27 = V_4 -> V_27 ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
V_26 . V_57 = V_27 + sizeof( struct V_58 ) ;
if ( V_4 -> V_59 . V_60 == V_61 ) {
V_26 . V_62 = V_63 ;
V_26 . V_64 . V_65 = V_4 -> V_59 . V_64 . V_65 ;
}
F_13 ( & V_17 -> V_66 , V_20 ) ;
if ( V_17 -> V_67 & V_68 )
V_17 -> V_67 &= ~ V_68 ;
else {
int V_69 ;
V_69 = F_14 ( V_17 , 0 ) ;
if ( V_69 < 0 ) {
F_15 ( V_17 , V_70 ) ;
goto V_71;
}
if ( ! V_69 ) {
if ( V_17 -> V_7 . V_44 == 0 )
V_6 -> V_31 . V_72 ++ ;
goto V_71;
}
}
if ( F_9 ( V_26 . V_57 > V_17 -> V_73 ) ) {
V_17 -> V_67 |= V_68 ;
V_6 -> V_31 . V_34 ++ ;
goto V_71;
}
if ( V_19 -> V_74 & V_75 ) {
struct V_58 V_76 ;
struct V_77 V_78 = V_19 -> V_76 ;
F_16 ( V_6 , & V_76 , & V_78 , 0 , 0 ) ;
F_17 ( & V_17 -> V_79 , & V_76 ,
sizeof( V_76 ) , 1 ) ;
V_26 . V_62 |= V_80 ;
} else
F_18 ( & V_17 -> V_79 , sizeof( struct V_58 ) , true ) ;
V_22 . V_81 = V_4 -> V_81 + 1 ;
V_22 . V_24 = * V_4 -> V_81 ;
V_22 . V_82 = V_4 -> V_59 . V_82 ;
V_24 = & V_22 . V_24 ;
while ( V_27 ) {
T_1 V_83 = V_24 -> V_27 ;
if ( V_83 > V_27 )
V_83 = V_27 ;
if ( V_83 > V_24 -> V_84 )
V_83 = V_24 -> V_84 ;
F_19 ( V_83 == 0 ) ;
F_17 ( & V_17 -> V_79 , V_24 -> V_85 , V_83 , 1 ) ;
V_24 -> V_85 += V_83 ;
V_24 -> V_27 -= V_83 ;
V_24 -> V_84 -= V_83 ;
if ( V_24 -> V_84 == 0 ) {
if ( -- V_22 . V_82 )
* V_24 = * V_22 . V_81 ++ ;
} else if ( V_24 -> V_27 == 0 && V_24 -> V_86 -> V_87 ) {
if ( ++ V_24 -> V_88 >= V_89 ) {
if ( ++ V_24 -> V_90 >= V_24 -> V_86 -> V_91 )
break;
V_24 -> V_88 = 0 ;
}
V_24 -> V_85 =
V_24 -> V_86 -> V_92 [ V_24 -> V_90 ] -> V_93 [ V_24 -> V_88 ] . V_85 ;
V_24 -> V_27 =
V_24 -> V_86 -> V_92 [ V_24 -> V_90 ] -> V_93 [ V_24 -> V_88 ] . V_27 ;
}
V_27 -= V_83 ;
}
F_20 ( & V_17 -> V_79 ) ;
if ( ! F_21 ( V_94 , & V_17 -> V_95 ) )
goto V_71;
V_26 . V_96 = V_17 -> V_97 ;
V_26 . V_98 = V_99 ;
V_26 . V_60 = V_100 ;
V_26 . V_17 = & V_17 -> V_7 ;
V_26 . V_101 = V_2 -> V_7 . V_44 ;
V_26 . V_102 = V_17 -> V_7 . V_35 == V_36 ?
V_4 -> V_32 . V_102 : 0 ;
V_26 . V_103 = V_11 -> V_47 | ( V_19 -> V_49 & ( ( 1 << V_11 -> V_50 ) - 1 ) ) ;
V_26 . V_52 = V_19 -> V_52 ;
V_26 . V_104 = V_19 -> V_53 & ( ( 1 << V_11 -> V_50 ) - 1 ) ;
V_26 . V_9 = V_17 -> V_9 ;
F_22 ( F_23 ( V_17 -> V_7 . V_105 ) , & V_26 ,
V_4 -> V_59 . V_106 & V_107 ) ;
V_6 -> V_31 . V_108 ++ ;
V_71:
F_24 ( & V_17 -> V_66 , V_20 ) ;
V_41:
F_6 () ;
}
int F_25 ( struct V_1 * V_17 , unsigned long * V_20 )
{
struct V_109 * V_110 = V_17 -> V_110 ;
struct V_111 * V_112 ;
struct V_18 * V_19 ;
struct V_10 * V_11 ;
struct V_5 * V_6 ;
struct V_3 * V_113 ;
T_1 V_114 ;
T_1 V_115 ;
T_1 V_116 ;
T_2 V_117 ;
T_2 V_47 ;
int V_69 = 0 ;
int V_118 ;
if ( ! ( V_38 [ V_17 -> V_39 ] & V_119 ) ) {
if ( ! ( V_38 [ V_17 -> V_39 ] & V_120 ) )
goto V_121;
F_26 () ;
if ( V_17 -> V_122 == F_27 ( V_17 -> V_123 ) )
goto V_121;
if ( F_28 ( & V_110 -> V_124 ) ) {
V_17 -> V_125 |= V_126 ;
goto V_121;
}
V_113 = F_29 ( V_17 , V_17 -> V_122 ) ;
F_30 ( V_17 , V_113 , V_127 ) ;
goto V_128;
}
F_26 () ;
if ( V_17 -> V_129 == F_27 ( V_17 -> V_123 ) )
goto V_121;
V_113 = F_29 ( V_17 , V_17 -> V_129 ) ;
V_118 = V_17 -> V_129 + 1 ;
if ( V_118 >= V_17 -> V_130 )
V_118 = 0 ;
V_6 = F_2 ( V_17 -> V_7 . V_8 , V_17 -> V_9 ) ;
V_11 = F_3 ( V_6 ) ;
V_19 = & F_7 ( V_113 -> V_32 . V_42 ) -> V_43 ;
if ( V_19 -> V_53 >= F_31 ( V_131 ) ) {
if ( V_19 -> V_53 != F_31 ( V_132 ) )
F_32 ( V_6 -> V_133 -> V_134 ) ;
else
F_32 ( V_6 -> V_133 -> V_135 ) ;
} else {
F_32 ( V_6 -> V_133 -> V_135 ) ;
V_47 = V_19 -> V_53 & ~ ( ( 1 << V_11 -> V_50 ) - 1 ) ;
if ( F_9 ( V_47 == V_11 -> V_47 ) ) {
unsigned long V_136 = * V_20 ;
if ( F_28 ( & V_110 -> V_124 ) ) {
V_17 -> V_125 |= V_126 ;
goto V_121;
}
V_17 -> V_129 = V_118 ;
F_24 ( & V_17 -> V_137 , V_136 ) ;
F_1 ( V_17 , V_113 ) ;
F_13 ( & V_17 -> V_137 , V_136 ) ;
* V_20 = V_136 ;
F_30 ( V_17 , V_113 , V_99 ) ;
goto V_128;
}
}
V_17 -> V_129 = V_118 ;
V_115 = - V_113 -> V_27 & 3 ;
V_114 = ( V_113 -> V_27 + V_115 ) >> 2 ;
V_17 -> V_138 = 7 ;
V_17 -> V_139 = V_113 -> V_27 ;
V_17 -> V_140 = & V_17 -> V_141 ;
V_17 -> V_142 = V_19 -> V_143 ;
V_17 -> V_144 = V_113 ;
V_17 -> V_141 . V_24 = V_113 -> V_81 [ 0 ] ;
V_17 -> V_141 . V_81 = V_113 -> V_81 + 1 ;
V_17 -> V_141 . V_82 = V_113 -> V_59 . V_82 ;
V_17 -> V_141 . V_145 = V_113 -> V_27 ;
if ( V_19 -> V_74 & V_75 ) {
V_17 -> V_138 += F_16 ( V_6 , & V_110 -> V_146 -> V_147 . V_148 . V_76 ,
& V_19 -> V_76 ,
V_17 -> V_138 , V_114 ) ;
V_117 = V_149 ;
V_112 = & V_110 -> V_146 -> V_147 . V_148 . V_150 ;
} else {
V_117 = V_151 ;
V_112 = & V_110 -> V_146 -> V_147 . V_150 ;
}
if ( V_113 -> V_59 . V_60 == V_61 ) {
V_17 -> V_138 ++ ;
V_112 -> V_147 . V_152 . V_65 = V_113 -> V_59 . V_64 . V_65 ;
V_116 = V_153 << 24 ;
} else
V_116 = V_154 << 24 ;
V_117 |= V_19 -> V_52 << 4 ;
if ( V_17 -> V_7 . V_35 == V_155 )
V_117 |= 0xF000 ;
else
V_117 |= V_6 -> V_156 [ V_19 -> V_52 ] << 12 ;
V_110 -> V_146 -> V_157 [ 0 ] = F_12 ( V_117 ) ;
V_110 -> V_146 -> V_157 [ 1 ] = F_12 ( V_19 -> V_53 ) ;
V_110 -> V_146 -> V_157 [ 2 ] =
F_12 ( V_17 -> V_138 + V_114 + V_158 ) ;
V_47 = V_11 -> V_47 ;
if ( V_47 ) {
V_47 |= V_19 -> V_49 & ( ( 1 << V_11 -> V_50 ) - 1 ) ;
V_110 -> V_146 -> V_157 [ 3 ] = F_12 ( V_47 ) ;
} else
V_110 -> V_146 -> V_157 [ 3 ] = V_132 ;
if ( V_113 -> V_59 . V_106 & V_107 )
V_116 |= V_159 ;
V_116 |= V_115 << 20 ;
V_116 |= V_17 -> V_7 . V_35 == V_155 ? V_160 :
F_8 ( V_6 , V_17 -> V_7 . V_35 == V_36 ?
V_113 -> V_32 . V_102 : V_17 -> V_48 ) ;
V_112 -> V_161 [ 0 ] = F_33 ( V_116 ) ;
V_112 -> V_161 [ 1 ] = V_19 -> V_53 >= F_31 ( V_131 ) &&
V_19 -> V_53 != F_31 ( V_132 ) ?
F_33 ( V_162 ) :
F_33 ( V_113 -> V_32 . V_33 ) ;
V_112 -> V_161 [ 2 ] = F_33 ( V_113 -> V_163 & V_164 ) ;
V_112 -> V_147 . V_152 . V_165 [ 0 ] = F_33 ( ( int ) V_113 -> V_32 . V_55 < 0 ?
V_17 -> V_54 : V_113 -> V_32 . V_55 ) ;
V_112 -> V_147 . V_152 . V_165 [ 1 ] = F_33 ( V_17 -> V_7 . V_44 ) ;
V_128:
return 1 ;
V_121:
V_17 -> V_125 &= ~ V_166 ;
return V_69 ;
}
static unsigned F_34 ( struct V_5 * V_6 , T_2 V_167 )
{
struct V_10 * V_11 = F_3 ( V_6 ) ;
struct V_12 * V_13 = V_11 -> V_13 ;
unsigned V_168 = V_11 -> V_169 ;
unsigned V_170 ;
V_167 &= 0x7fff ;
for ( V_170 = 0 ; V_170 < F_35 ( V_13 -> V_171 [ V_168 ] -> V_172 ) ; ++ V_170 )
if ( ( V_13 -> V_171 [ V_168 ] -> V_172 [ V_170 ] & 0x7fff ) == V_167 )
return V_170 ;
return 0 ;
}
void F_36 ( struct V_5 * V_6 , struct V_173 * V_174 ,
int V_175 , void * V_176 , T_1 V_177 , struct V_1 * V_17 )
{
struct V_111 * V_112 ;
int V_60 ;
T_1 V_178 ;
T_1 V_179 ;
struct V_25 V_26 ;
T_1 V_54 ;
T_1 V_101 ;
T_2 V_53 ;
if ( ! V_175 ) {
V_112 = & V_174 -> V_147 . V_150 ;
V_178 = 8 + 12 + 8 ;
} else {
V_112 = & V_174 -> V_147 . V_148 . V_150 ;
V_178 = 8 + 40 + 12 + 8 ;
}
V_54 = F_37 ( V_112 -> V_147 . V_152 . V_165 [ 0 ] ) ;
V_101 = F_37 ( V_112 -> V_147 . V_152 . V_165 [ 1 ] ) & V_180 ;
V_179 = ( F_37 ( V_112 -> V_161 [ 0 ] ) >> 20 ) & 3 ;
if ( F_9 ( V_177 < ( V_178 + V_179 + 4 ) ) )
goto V_41;
V_177 -= V_178 + V_179 + 4 ;
if ( V_17 -> V_7 . V_44 ) {
if ( F_9 ( V_174 -> V_157 [ 1 ] == V_132 ||
V_174 -> V_157 [ 3 ] == V_132 ) )
goto V_41;
if ( V_17 -> V_7 . V_44 > 1 ) {
T_2 V_45 , V_46 ;
V_45 = F_37 ( V_112 -> V_161 [ 0 ] ) ;
V_46 = F_8 ( V_6 , V_17 -> V_48 ) ;
if ( F_9 ( ! F_10 ( V_45 , V_46 ) ) ) {
F_11 ( V_6 , V_51 ,
V_45 ,
( F_31 ( V_174 -> V_157 [ 0 ] ) >> 4 ) &
0xF ,
V_101 , V_17 -> V_7 . V_44 ,
V_174 -> V_157 [ 3 ] , V_174 -> V_157 [ 1 ] ) ;
return;
}
}
if ( F_9 ( V_54 != V_17 -> V_54 ) ) {
F_11 ( V_6 , V_56 , V_54 ,
( F_31 ( V_174 -> V_157 [ 0 ] ) >> 4 ) & 0xF ,
V_101 , V_17 -> V_7 . V_44 ,
V_174 -> V_157 [ 3 ] , V_174 -> V_157 [ 1 ] ) ;
return;
}
if ( F_9 ( V_17 -> V_7 . V_44 == 1 &&
( V_177 != 256 ||
( F_31 ( V_174 -> V_157 [ 0 ] ) >> 12 ) == 15 ) ) )
goto V_41;
} else {
struct V_181 * V_182 ;
if ( V_177 != 256 || ( F_31 ( V_174 -> V_157 [ 0 ] ) >> 12 ) != 15 )
goto V_41;
V_182 = (struct V_181 * ) V_176 ;
if ( ( V_174 -> V_157 [ 1 ] == V_132 ||
V_174 -> V_157 [ 3 ] == V_132 ) &&
V_182 -> V_183 != V_184 )
goto V_41;
}
V_60 = F_37 ( V_112 -> V_161 [ 0 ] ) >> 24 ;
if ( V_17 -> V_7 . V_44 > 1 &&
V_60 == V_153 ) {
V_26 . V_64 . V_65 = V_112 -> V_147 . V_152 . V_65 ;
V_26 . V_62 = V_63 ;
V_177 -= sizeof( T_1 ) ;
} else if ( V_60 == V_154 ) {
V_26 . V_64 . V_65 = 0 ;
V_26 . V_62 = 0 ;
} else
goto V_41;
V_26 . V_57 = V_177 + sizeof( struct V_58 ) ;
if ( V_17 -> V_67 & V_68 )
V_17 -> V_67 &= ~ V_68 ;
else {
int V_69 ;
V_69 = F_14 ( V_17 , 0 ) ;
if ( V_69 < 0 ) {
F_15 ( V_17 , V_70 ) ;
return;
}
if ( ! V_69 ) {
if ( V_17 -> V_7 . V_44 == 0 )
V_6 -> V_31 . V_72 ++ ;
return;
}
}
if ( F_9 ( V_26 . V_57 > V_17 -> V_73 ) ) {
V_17 -> V_67 |= V_68 ;
goto V_41;
}
if ( V_175 ) {
F_17 ( & V_17 -> V_79 , & V_174 -> V_147 . V_148 . V_76 ,
sizeof( struct V_58 ) , 1 ) ;
V_26 . V_62 |= V_80 ;
} else
F_18 ( & V_17 -> V_79 , sizeof( struct V_58 ) , true ) ;
F_17 ( & V_17 -> V_79 , V_176 , V_26 . V_57 - sizeof( struct V_58 ) , 1 ) ;
F_20 ( & V_17 -> V_79 ) ;
if ( ! F_21 ( V_94 , & V_17 -> V_95 ) )
return;
V_26 . V_96 = V_17 -> V_97 ;
V_26 . V_98 = V_99 ;
V_26 . V_60 = V_100 ;
V_26 . V_185 = 0 ;
V_26 . V_17 = & V_17 -> V_7 ;
V_26 . V_101 = V_101 ;
V_26 . V_102 = V_17 -> V_7 . V_35 == V_36 ?
F_34 ( V_6 , F_37 ( V_112 -> V_161 [ 0 ] ) ) : 0 ;
V_26 . V_103 = F_31 ( V_174 -> V_157 [ 3 ] ) ;
V_26 . V_52 = ( F_31 ( V_174 -> V_157 [ 0 ] ) >> 4 ) & 0xF ;
V_53 = F_31 ( V_174 -> V_157 [ 1 ] ) ;
V_26 . V_104 = V_53 >= F_31 ( V_131 ) ? 0 :
V_53 & ( ( 1 << F_3 ( V_6 ) -> V_50 ) - 1 ) ;
V_26 . V_9 = V_17 -> V_9 ;
F_22 ( F_23 ( V_17 -> V_7 . V_105 ) , & V_26 ,
( V_112 -> V_161 [ 0 ] &
F_33 ( V_159 ) ) != 0 ) ;
return;
V_41:
V_6 -> V_31 . V_34 ++ ;
}
