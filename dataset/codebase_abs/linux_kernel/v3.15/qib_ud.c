static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 . V_8 , V_2 -> V_9 ) ;
struct V_10 * V_11 ;
struct V_1 * V_12 ;
struct V_13 * V_14 ;
unsigned long V_15 ;
struct V_16 V_17 ;
struct V_18 * V_19 ;
struct V_20 V_21 ;
T_1 V_22 ;
enum V_23 V_24 , V_25 ;
V_12 = F_3 ( V_6 , V_4 -> V_26 . V_26 . V_27 . V_28 ) ;
if ( ! V_12 ) {
V_6 -> V_29 ++ ;
return;
}
V_24 = V_2 -> V_7 . V_30 == V_31 ?
V_32 : V_2 -> V_7 . V_30 ;
V_25 = V_12 -> V_7 . V_30 == V_31 ?
V_32 : V_12 -> V_7 . V_30 ;
if ( V_25 != V_24 ||
! ( V_33 [ V_12 -> V_34 ] & V_35 ) ) {
V_6 -> V_29 ++ ;
goto V_36;
}
V_14 = & F_4 ( V_4 -> V_26 . V_26 . V_27 . V_37 ) -> V_38 ;
V_11 = F_5 ( V_6 ) ;
if ( V_12 -> V_7 . V_39 > 1 ) {
T_2 V_40 ;
T_2 V_41 ;
T_2 V_42 ;
V_40 = F_6 ( V_6 , V_2 -> V_43 ) ;
V_41 = F_6 ( V_6 , V_12 -> V_43 ) ;
if ( F_7 ( ! F_8 ( V_40 , V_41 ) ) ) {
V_42 = V_11 -> V_42 | ( V_14 -> V_44 &
( ( 1 << V_11 -> V_45 ) - 1 ) ) ;
F_9 ( V_6 , V_46 , V_40 ,
V_14 -> V_47 ,
V_2 -> V_7 . V_39 , V_12 -> V_7 . V_39 ,
F_10 ( V_42 ) ,
F_10 ( V_14 -> V_48 ) ) ;
goto V_36;
}
}
if ( V_12 -> V_7 . V_39 ) {
T_1 V_49 ;
V_49 = ( int ) V_4 -> V_26 . V_26 . V_27 . V_50 < 0 ?
V_2 -> V_49 : V_4 -> V_26 . V_26 . V_27 . V_50 ;
if ( F_7 ( V_49 != V_12 -> V_49 ) ) {
T_2 V_42 ;
V_42 = V_11 -> V_42 | ( V_14 -> V_44 &
( ( 1 << V_11 -> V_45 ) - 1 ) ) ;
F_9 ( V_6 , V_51 , V_49 ,
V_14 -> V_47 ,
V_2 -> V_7 . V_39 , V_12 -> V_7 . V_39 ,
F_10 ( V_42 ) ,
F_10 ( V_14 -> V_48 ) ) ;
goto V_36;
}
}
V_22 = V_4 -> V_22 ;
memset ( & V_21 , 0 , sizeof V_21 ) ;
V_21 . V_52 = V_22 + sizeof( struct V_53 ) ;
if ( V_4 -> V_26 . V_54 == V_55 ) {
V_21 . V_56 = V_57 ;
V_21 . V_58 . V_59 = V_4 -> V_26 . V_58 . V_59 ;
}
F_11 ( & V_12 -> V_60 , V_15 ) ;
if ( V_12 -> V_61 & V_62 )
V_12 -> V_61 &= ~ V_62 ;
else {
int V_63 ;
V_63 = F_12 ( V_12 , 0 ) ;
if ( V_63 < 0 ) {
F_13 ( V_12 , V_64 ) ;
goto V_65;
}
if ( ! V_63 ) {
if ( V_12 -> V_7 . V_39 == 0 )
V_6 -> V_66 ++ ;
goto V_65;
}
}
if ( F_7 ( V_21 . V_52 > V_12 -> V_67 ) ) {
V_12 -> V_61 |= V_62 ;
V_6 -> V_29 ++ ;
goto V_65;
}
if ( V_14 -> V_68 & V_69 ) {
F_14 ( & V_12 -> V_70 , & V_14 -> V_71 ,
sizeof( struct V_53 ) , 1 ) ;
V_21 . V_56 |= V_72 ;
} else
F_15 ( & V_12 -> V_70 , sizeof( struct V_53 ) , 1 ) ;
V_17 . V_73 = V_4 -> V_73 + 1 ;
V_17 . V_19 = * V_4 -> V_73 ;
V_17 . V_74 = V_4 -> V_26 . V_74 ;
V_19 = & V_17 . V_19 ;
while ( V_22 ) {
T_1 V_75 = V_19 -> V_22 ;
if ( V_75 > V_22 )
V_75 = V_22 ;
if ( V_75 > V_19 -> V_76 )
V_75 = V_19 -> V_76 ;
F_16 ( V_75 == 0 ) ;
F_14 ( & V_12 -> V_70 , V_19 -> V_77 , V_75 , 1 ) ;
V_19 -> V_77 += V_75 ;
V_19 -> V_22 -= V_75 ;
V_19 -> V_76 -= V_75 ;
if ( V_19 -> V_76 == 0 ) {
if ( -- V_17 . V_74 )
* V_19 = * V_17 . V_73 ++ ;
} else if ( V_19 -> V_22 == 0 && V_19 -> V_78 -> V_79 ) {
if ( ++ V_19 -> V_80 >= V_81 ) {
if ( ++ V_19 -> V_82 >= V_19 -> V_78 -> V_83 )
break;
V_19 -> V_80 = 0 ;
}
V_19 -> V_77 =
V_19 -> V_78 -> V_84 [ V_19 -> V_82 ] -> V_85 [ V_19 -> V_80 ] . V_77 ;
V_19 -> V_22 =
V_19 -> V_78 -> V_84 [ V_19 -> V_82 ] -> V_85 [ V_19 -> V_80 ] . V_22 ;
}
V_22 -= V_75 ;
}
F_17 ( & V_12 -> V_70 ) ;
if ( ! F_18 ( V_86 , & V_12 -> V_87 ) )
goto V_65;
V_21 . V_88 = V_12 -> V_89 ;
V_21 . V_90 = V_91 ;
V_21 . V_54 = V_92 ;
V_21 . V_12 = & V_12 -> V_7 ;
V_21 . V_93 = V_2 -> V_7 . V_39 ;
V_21 . V_94 = V_12 -> V_7 . V_30 == V_31 ?
V_4 -> V_26 . V_26 . V_27 . V_94 : 0 ;
V_21 . V_95 = V_11 -> V_42 | ( V_14 -> V_44 & ( ( 1 << V_11 -> V_45 ) - 1 ) ) ;
V_21 . V_47 = V_14 -> V_47 ;
V_21 . V_96 = V_14 -> V_48 & ( ( 1 << V_11 -> V_45 ) - 1 ) ;
V_21 . V_9 = V_12 -> V_9 ;
F_19 ( F_20 ( V_12 -> V_7 . V_97 ) , & V_21 ,
V_4 -> V_26 . V_98 & V_99 ) ;
V_6 -> V_100 ++ ;
V_65:
F_21 ( & V_12 -> V_60 , V_15 ) ;
V_36:
if ( F_22 ( & V_12 -> V_101 ) )
F_23 ( & V_12 -> V_102 ) ;
}
int F_24 ( struct V_1 * V_12 )
{
struct V_103 * V_104 ;
struct V_13 * V_14 ;
struct V_10 * V_11 ;
struct V_5 * V_6 ;
struct V_3 * V_105 ;
unsigned long V_15 ;
T_1 V_106 ;
T_1 V_107 ;
T_1 V_108 ;
T_2 V_109 ;
T_2 V_42 ;
int V_63 = 0 ;
int V_110 ;
F_11 ( & V_12 -> V_111 , V_15 ) ;
if ( ! ( V_33 [ V_12 -> V_34 ] & V_112 ) ) {
if ( ! ( V_33 [ V_12 -> V_34 ] & V_113 ) )
goto V_114;
if ( V_12 -> V_115 == V_12 -> V_116 )
goto V_114;
if ( F_25 ( & V_12 -> V_117 ) ) {
V_12 -> V_118 |= V_119 ;
goto V_114;
}
V_105 = F_26 ( V_12 , V_12 -> V_115 ) ;
F_27 ( V_12 , V_105 , V_120 ) ;
goto V_121;
}
if ( V_12 -> V_122 == V_12 -> V_116 )
goto V_114;
V_105 = F_26 ( V_12 , V_12 -> V_122 ) ;
V_110 = V_12 -> V_122 + 1 ;
if ( V_110 >= V_12 -> V_123 )
V_110 = 0 ;
V_6 = F_2 ( V_12 -> V_7 . V_8 , V_12 -> V_9 ) ;
V_11 = F_5 ( V_6 ) ;
V_14 = & F_4 ( V_105 -> V_26 . V_26 . V_27 . V_37 ) -> V_38 ;
if ( V_14 -> V_48 >= V_124 ) {
if ( V_14 -> V_48 != V_125 )
F_28 ( V_6 -> V_126 -> V_127 ) ;
else
F_28 ( V_6 -> V_126 -> V_128 ) ;
} else {
F_28 ( V_6 -> V_126 -> V_128 ) ;
V_42 = V_14 -> V_48 & ~ ( ( 1 << V_11 -> V_45 ) - 1 ) ;
if ( F_7 ( V_42 == V_11 -> V_42 ) ) {
if ( F_25 ( & V_12 -> V_117 ) ) {
V_12 -> V_118 |= V_119 ;
goto V_114;
}
V_12 -> V_122 = V_110 ;
F_21 ( & V_12 -> V_111 , V_15 ) ;
F_1 ( V_12 , V_105 ) ;
F_11 ( & V_12 -> V_111 , V_15 ) ;
F_27 ( V_12 , V_105 , V_91 ) ;
goto V_121;
}
}
V_12 -> V_122 = V_110 ;
V_107 = - V_105 -> V_22 & 3 ;
V_106 = ( V_105 -> V_22 + V_107 ) >> 2 ;
V_12 -> V_129 = 7 ;
V_12 -> V_130 = V_105 -> V_22 ;
V_12 -> V_131 = & V_12 -> V_132 ;
V_12 -> V_133 = V_14 -> V_134 ;
V_12 -> V_135 = V_105 ;
V_12 -> V_132 . V_19 = V_105 -> V_73 [ 0 ] ;
V_12 -> V_132 . V_73 = V_105 -> V_73 + 1 ;
V_12 -> V_132 . V_74 = V_105 -> V_26 . V_74 ;
V_12 -> V_132 . V_136 = V_105 -> V_22 ;
if ( V_14 -> V_68 & V_69 ) {
V_12 -> V_129 += F_29 ( V_6 , & V_12 -> V_137 -> V_138 . V_139 . V_71 ,
& V_14 -> V_71 ,
V_12 -> V_129 , V_106 ) ;
V_109 = V_140 ;
V_104 = & V_12 -> V_137 -> V_138 . V_139 . V_141 ;
} else {
V_109 = V_142 ;
V_104 = & V_12 -> V_137 -> V_138 . V_141 ;
}
if ( V_105 -> V_26 . V_54 == V_55 ) {
V_12 -> V_129 ++ ;
V_104 -> V_138 . V_27 . V_59 = V_105 -> V_26 . V_58 . V_59 ;
V_108 = V_143 << 24 ;
} else
V_108 = V_144 << 24 ;
V_109 |= V_14 -> V_47 << 4 ;
if ( V_12 -> V_7 . V_30 == V_145 )
V_109 |= 0xF000 ;
else
V_109 |= V_6 -> V_146 [ V_14 -> V_47 ] << 12 ;
V_12 -> V_137 -> V_147 [ 0 ] = F_10 ( V_109 ) ;
V_12 -> V_137 -> V_147 [ 1 ] = F_10 ( V_14 -> V_48 ) ;
V_12 -> V_137 -> V_147 [ 2 ] = F_10 ( V_12 -> V_129 + V_106 + V_148 ) ;
V_42 = V_11 -> V_42 ;
if ( V_42 ) {
V_42 |= V_14 -> V_44 & ( ( 1 << V_11 -> V_45 ) - 1 ) ;
V_12 -> V_137 -> V_147 [ 3 ] = F_10 ( V_42 ) ;
} else
V_12 -> V_137 -> V_147 [ 3 ] = V_149 ;
if ( V_105 -> V_26 . V_98 & V_99 )
V_108 |= V_150 ;
V_108 |= V_107 << 20 ;
V_108 |= V_12 -> V_7 . V_30 == V_145 ? V_151 :
F_6 ( V_6 , V_12 -> V_7 . V_30 == V_31 ?
V_105 -> V_26 . V_26 . V_27 . V_94 : V_12 -> V_43 ) ;
V_104 -> V_152 [ 0 ] = F_30 ( V_108 ) ;
V_104 -> V_152 [ 1 ] = V_14 -> V_48 >= V_124 &&
V_14 -> V_48 != V_125 ?
F_30 ( V_153 ) :
F_30 ( V_105 -> V_26 . V_26 . V_27 . V_28 ) ;
V_104 -> V_152 [ 2 ] = F_30 ( V_12 -> V_154 ++ & V_155 ) ;
V_104 -> V_138 . V_27 . V_156 [ 0 ] = F_30 ( ( int ) V_105 -> V_26 . V_26 . V_27 . V_50 < 0 ?
V_12 -> V_49 : V_105 -> V_26 . V_26 . V_27 . V_50 ) ;
V_104 -> V_138 . V_27 . V_156 [ 1 ] = F_30 ( V_12 -> V_7 . V_39 ) ;
V_121:
V_63 = 1 ;
goto V_157;
V_114:
V_12 -> V_118 &= ~ V_158 ;
V_157:
F_21 ( & V_12 -> V_111 , V_15 ) ;
return V_63 ;
}
static unsigned F_31 ( struct V_5 * V_6 , T_2 V_159 )
{
struct V_10 * V_11 = F_5 ( V_6 ) ;
struct V_160 * V_161 = V_11 -> V_161 ;
unsigned V_162 = V_11 -> V_163 ;
unsigned V_164 ;
V_159 &= 0x7fff ;
for ( V_164 = 0 ; V_164 < F_32 ( V_161 -> V_165 [ V_162 ] -> V_166 ) ; ++ V_164 )
if ( ( V_161 -> V_165 [ V_162 ] -> V_166 [ V_164 ] & 0x7fff ) == V_159 )
return V_164 ;
return 0 ;
}
void F_33 ( struct V_5 * V_6 , struct V_167 * V_168 ,
int V_169 , void * V_170 , T_1 V_171 , struct V_1 * V_12 )
{
struct V_103 * V_104 ;
int V_54 ;
T_1 V_172 ;
T_1 V_173 ;
struct V_20 V_21 ;
T_1 V_49 ;
T_1 V_93 ;
T_2 V_48 ;
if ( ! V_169 ) {
V_104 = & V_168 -> V_138 . V_141 ;
V_172 = 8 + 12 + 8 ;
} else {
V_104 = & V_168 -> V_138 . V_139 . V_141 ;
V_172 = 8 + 40 + 12 + 8 ;
}
V_49 = F_34 ( V_104 -> V_138 . V_27 . V_156 [ 0 ] ) ;
V_93 = F_34 ( V_104 -> V_138 . V_27 . V_156 [ 1 ] ) & V_174 ;
V_173 = ( F_34 ( V_104 -> V_152 [ 0 ] ) >> 20 ) & 3 ;
if ( F_7 ( V_171 < ( V_172 + V_173 + 4 ) ) )
goto V_36;
V_171 -= V_172 + V_173 + 4 ;
if ( V_12 -> V_7 . V_39 ) {
if ( F_7 ( V_168 -> V_147 [ 1 ] == V_149 ||
V_168 -> V_147 [ 3 ] == V_149 ) )
goto V_36;
if ( V_12 -> V_7 . V_39 > 1 ) {
T_2 V_40 , V_41 ;
V_40 = F_34 ( V_104 -> V_152 [ 0 ] ) ;
V_41 = F_6 ( V_6 , V_12 -> V_43 ) ;
if ( F_7 ( ! F_8 ( V_40 , V_41 ) ) ) {
F_9 ( V_6 , V_46 ,
V_40 ,
( F_35 ( V_168 -> V_147 [ 0 ] ) >> 4 ) &
0xF ,
V_93 , V_12 -> V_7 . V_39 ,
V_168 -> V_147 [ 3 ] , V_168 -> V_147 [ 1 ] ) ;
return;
}
}
if ( F_7 ( V_49 != V_12 -> V_49 ) ) {
F_9 ( V_6 , V_51 , V_49 ,
( F_35 ( V_168 -> V_147 [ 0 ] ) >> 4 ) & 0xF ,
V_93 , V_12 -> V_7 . V_39 ,
V_168 -> V_147 [ 3 ] , V_168 -> V_147 [ 1 ] ) ;
return;
}
if ( F_7 ( V_12 -> V_7 . V_39 == 1 &&
( V_171 != 256 ||
( F_35 ( V_168 -> V_147 [ 0 ] ) >> 12 ) == 15 ) ) )
goto V_36;
} else {
struct V_175 * V_176 ;
if ( V_171 != 256 || ( F_35 ( V_168 -> V_147 [ 0 ] ) >> 12 ) != 15 )
goto V_36;
V_176 = (struct V_175 * ) V_170 ;
if ( ( V_168 -> V_147 [ 1 ] == V_149 ||
V_168 -> V_147 [ 3 ] == V_149 ) &&
V_176 -> V_177 != V_178 )
goto V_36;
}
V_54 = F_34 ( V_104 -> V_152 [ 0 ] ) >> 24 ;
if ( V_12 -> V_7 . V_39 > 1 &&
V_54 == V_143 ) {
V_21 . V_58 . V_59 = V_104 -> V_138 . V_27 . V_59 ;
V_21 . V_56 = V_57 ;
V_171 -= sizeof( T_1 ) ;
} else if ( V_54 == V_144 ) {
V_21 . V_58 . V_59 = 0 ;
V_21 . V_56 = 0 ;
} else
goto V_36;
V_21 . V_52 = V_171 + sizeof( struct V_53 ) ;
if ( V_12 -> V_61 & V_62 )
V_12 -> V_61 &= ~ V_62 ;
else {
int V_63 ;
V_63 = F_12 ( V_12 , 0 ) ;
if ( V_63 < 0 ) {
F_13 ( V_12 , V_64 ) ;
return;
}
if ( ! V_63 ) {
if ( V_12 -> V_7 . V_39 == 0 )
V_6 -> V_66 ++ ;
return;
}
}
if ( F_7 ( V_21 . V_52 > V_12 -> V_67 ) ) {
V_12 -> V_61 |= V_62 ;
goto V_36;
}
if ( V_169 ) {
F_14 ( & V_12 -> V_70 , & V_168 -> V_138 . V_139 . V_71 ,
sizeof( struct V_53 ) , 1 ) ;
V_21 . V_56 |= V_72 ;
} else
F_15 ( & V_12 -> V_70 , sizeof( struct V_53 ) , 1 ) ;
F_14 ( & V_12 -> V_70 , V_170 , V_21 . V_52 - sizeof( struct V_53 ) , 1 ) ;
F_17 ( & V_12 -> V_70 ) ;
if ( ! F_18 ( V_86 , & V_12 -> V_87 ) )
return;
V_21 . V_88 = V_12 -> V_89 ;
V_21 . V_90 = V_91 ;
V_21 . V_54 = V_92 ;
V_21 . V_179 = 0 ;
V_21 . V_12 = & V_12 -> V_7 ;
V_21 . V_93 = V_93 ;
V_21 . V_94 = V_12 -> V_7 . V_30 == V_31 ?
F_31 ( V_6 , F_34 ( V_104 -> V_152 [ 0 ] ) ) : 0 ;
V_21 . V_95 = F_35 ( V_168 -> V_147 [ 3 ] ) ;
V_21 . V_47 = ( F_35 ( V_168 -> V_147 [ 0 ] ) >> 4 ) & 0xF ;
V_48 = F_35 ( V_168 -> V_147 [ 1 ] ) ;
V_21 . V_96 = V_48 >= V_124 ? 0 :
V_48 & ( ( 1 << F_5 ( V_6 ) -> V_45 ) - 1 ) ;
V_21 . V_9 = V_12 -> V_9 ;
F_19 ( F_20 ( V_12 -> V_7 . V_97 ) , & V_21 ,
( V_104 -> V_152 [ 0 ] &
F_30 ( V_150 ) ) != 0 ) ;
return;
V_36:
V_6 -> V_29 ++ ;
}
