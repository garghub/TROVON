void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
int V_9 ;
V_4 -> V_10 = V_11 ;
F_4 ( V_8 -> V_12 & V_13 ?
& V_6 -> V_14 : & V_6 -> V_15 , V_4 ) ;
V_9 = F_5 ( & V_6 -> V_14 ) +
F_5 ( & V_6 -> V_15 ) ;
while ( V_9 > V_16 &&
( V_4 = F_6 ( & V_6 -> V_15 ) ) ) {
F_7 ( V_4 ) ;
V_9 -- ;
F_8 ( V_6 -> V_17 ) ;
}
F_9 ( & V_6 -> V_18 ) ;
}
static void F_10 ( struct V_5 * V_6 ,
struct V_19 * V_20 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
struct V_21 * V_22 = ( void * ) V_4 -> V_23 ;
int V_24 ;
memset ( & V_8 -> V_25 , 0 , sizeof( V_8 -> V_25 ) ) ;
V_8 -> V_25 . V_26 = V_26 ;
V_8 -> V_25 . V_27 = & V_20 -> V_28 -> V_27 ;
V_8 -> V_12 |= V_29 |
V_30 ;
V_8 -> V_12 &= ~ V_31 ;
V_20 -> V_32 ++ ;
if ( V_22 -> V_33 & F_11 ( V_34 ) )
V_22 -> V_33 &= ~ F_11 ( V_34 ) ;
if ( F_12 ( V_22 -> V_33 ) ) {
T_1 * V_35 = F_13 ( V_22 ) ;
int V_36 = * V_35 & V_37 ;
if ( * V_35 & V_38 )
* V_35 &= ~ V_38 ;
V_24 = V_39 [ V_36 & 7 ] ;
} else {
V_24 = V_40 ;
}
F_14 ( V_20 , V_41 ) ;
if ( F_15 ( V_20 , V_42 ) &&
F_5 ( & V_20 -> V_43 [ V_24 ] ) < V_44 ) {
F_4 ( & V_20 -> V_43 [ V_24 ] , V_4 ) ;
F_16 ( V_20 ) ;
if ( ! F_17 ( & V_6 -> V_45 ) )
F_18 ( & V_6 -> V_45 ,
F_19 ( V_26 +
V_46 ) ) ;
return;
}
if ( ! F_15 ( V_20 , V_42 ) &&
! ( V_8 -> V_12 & V_47 ) ) {
V_8 -> V_12 |= V_47 ;
F_20 ( V_6 , V_4 ) ;
return;
}
#ifdef F_21
if ( F_22 () )
F_23 ( V_6 -> V_2 . V_48 ,
L_1 ,
F_5 ( & V_20 -> V_43 [ V_24 ] ) ,
! ! F_15 ( V_20 , V_42 ) , V_26 ) ;
#endif
F_24 ( V_4 ) ;
}
static void F_25 ( struct V_19 * V_20 , T_1 * V_49 , T_1 V_36 )
{
struct V_50 * V_51 ;
V_51 = F_26 ( V_20 -> V_52 . V_51 [ V_36 ] ) ;
if ( ! V_51 || ! V_51 -> V_53 )
return;
V_51 -> V_53 = false ;
F_27 ( & V_20 -> V_28 -> V_27 , V_49 , V_36 , V_51 -> V_54 ) ;
}
static void F_28 ( struct V_19 * V_20 , struct V_3 * V_4 )
{
struct V_55 * V_56 = ( void * ) V_4 -> V_23 ;
struct V_5 * V_6 = V_20 -> V_6 ;
struct V_57 * V_28 = V_20 -> V_28 ;
if ( F_12 ( V_56 -> V_33 ) ) {
struct V_21 * V_22 = ( void * ) V_4 -> V_23 ;
T_1 * V_58 = F_13 ( V_22 ) ;
T_2 V_36 = V_58 [ 0 ] & 0xf ;
F_25 ( V_20 , V_22 -> V_59 , V_36 ) ;
}
if ( F_29 ( V_56 -> V_33 ) &&
V_28 -> V_27 . type == V_60 &&
V_56 -> V_61 . V_62 . V_63 == V_64 &&
V_56 -> V_61 . V_62 . V_61 . V_65 . V_62 == V_66 ) {
switch ( V_56 -> V_61 . V_62 . V_61 . V_65 . V_67 ) {
case V_68 :
V_20 -> V_28 -> V_61 . V_69 . V_70 = V_71 ;
break;
case V_72 :
V_20 -> V_28 -> V_61 . V_69 . V_70 = V_73 ;
break;
case V_74 :
default:
V_20 -> V_28 -> V_61 . V_69 . V_70 = V_75 ;
break;
}
F_30 ( & V_6 -> V_2 , & V_6 -> V_76 ) ;
}
}
static void F_31 ( struct V_19 * V_20 , T_1 V_36 , T_2 V_77 )
{
struct V_50 * V_51 ;
V_51 = F_26 ( V_20 -> V_52 . V_51 [ V_36 ] ) ;
if ( ! V_51 )
return;
V_51 -> V_54 = V_77 ;
V_51 -> V_53 = true ;
}
static int F_32 ( struct V_7 * V_8 )
{
int V_78 = sizeof( struct V_79 ) ;
if ( V_8 -> V_80 . V_81 [ 0 ] . V_82 >= 0 &&
! ( V_8 -> V_80 . V_81 [ 0 ] . V_12 & V_83 ) )
V_78 += 2 ;
V_78 += 2 ;
V_78 += 1 ;
if ( V_8 -> V_80 . V_81 [ 0 ] . V_82 >= 0 &&
V_8 -> V_80 . V_81 [ 0 ] . V_12 & V_83 )
V_78 += 3 ;
return V_78 ;
}
static void F_33 ( struct V_84
* V_85 , struct V_3 * V_4 ,
int V_86 , int V_87 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
struct V_21 * V_22 = (struct V_21 * ) V_4 -> V_23 ;
struct V_79 * V_88 ;
unsigned char * V_89 ;
T_2 V_90 ;
V_88 = (struct V_79 * ) F_34 ( V_4 , V_87 ) ;
memset ( V_88 , 0 , V_87 ) ;
V_88 -> V_91 = F_11 ( V_87 ) ;
V_88 -> V_92 =
F_35 ( ( 1 << V_93 ) |
( 1 << V_94 ) ) ;
V_89 = ( unsigned char * ) ( V_88 + 1 ) ;
if ( V_8 -> V_80 . V_81 [ 0 ] . V_82 >= 0 &&
! ( V_8 -> V_80 . V_81 [ 0 ] . V_12 & V_83 ) ) {
V_88 -> V_92 |= F_35 ( 1 << V_95 ) ;
* V_89 = V_85 -> V_96 [ V_8 -> V_80 . V_81 [ 0 ] . V_82 ] . V_97 / 5 ;
V_89 += 2 ;
}
V_90 = 0 ;
if ( ! ( V_8 -> V_12 & V_98 ) &&
! F_36 ( V_22 -> V_59 ) )
V_90 |= V_99 ;
if ( ( V_8 -> V_80 . V_81 [ 0 ] . V_12 & V_100 ) ||
( V_8 -> V_80 . V_81 [ 0 ] . V_12 & V_101 ) )
V_90 |= V_102 ;
else if ( V_8 -> V_80 . V_81 [ 0 ] . V_12 & V_100 )
V_90 |= V_103 ;
F_37 ( V_90 , V_89 ) ;
V_89 += 2 ;
* V_89 = V_86 ;
V_89 ++ ;
if ( V_8 -> V_80 . V_81 [ 0 ] . V_82 >= 0 &&
V_8 -> V_80 . V_81 [ 0 ] . V_12 & V_83 ) {
V_88 -> V_92 |= F_35 ( 1 << V_104 ) ;
V_89 [ 0 ] = V_105 |
V_106 |
V_107 ;
if ( V_8 -> V_80 . V_81 [ 0 ] . V_12 & V_108 )
V_89 [ 1 ] |= V_109 ;
if ( V_8 -> V_80 . V_81 [ 0 ] . V_12 & V_110 )
V_89 [ 1 ] |= V_111 ;
if ( V_8 -> V_80 . V_81 [ 0 ] . V_12 & V_112 )
V_89 [ 1 ] |= V_113 ;
V_89 [ 2 ] = V_8 -> V_80 . V_81 [ 0 ] . V_82 ;
V_89 += 3 ;
}
}
void F_38 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_3 * V_114 ;
struct V_21 * V_22 = (struct V_21 * ) V_4 -> V_23 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
T_3 V_115 ;
struct V_84 * V_85 ;
struct V_57 * V_28 ;
struct V_116 * V_117 = NULL ;
struct V_19 * V_20 , * V_9 ;
int V_86 = - 1 , V_118 ;
int V_119 = - 1 ;
bool V_120 ;
bool V_121 ;
struct V_122 * V_123 ;
T_2 V_36 ;
int V_87 ;
for ( V_118 = 0 ; V_118 < V_124 ; V_118 ++ ) {
if ( V_8 -> V_80 . V_81 [ V_118 ] . V_82 < 0 ) {
break;
} else if ( V_118 >= V_2 -> V_125 ) {
V_8 -> V_80 . V_81 [ V_118 ] . V_82 = - 1 ;
V_8 -> V_80 . V_81 [ V_118 ] . V_126 = 0 ;
break;
}
V_86 += V_8 -> V_80 . V_81 [ V_118 ] . V_126 ;
}
V_119 = V_118 - 1 ;
if ( V_86 < 0 )
V_86 = 0 ;
F_39 () ;
V_85 = V_6 -> V_2 . V_48 -> V_127 [ V_8 -> V_128 ] ;
V_115 = V_22 -> V_33 ;
F_40 (local, hdr->addr1, sta, tmp) {
if ( memcmp ( V_22 -> V_129 , V_20 -> V_28 -> V_27 . V_49 , V_130 ) )
continue;
if ( V_8 -> V_12 & V_131 )
F_41 ( V_20 , V_132 ) ;
V_121 = ! ! ( V_8 -> V_12 & V_98 ) ;
if ( ! V_121 && F_15 ( V_20 , V_42 ) ) {
F_10 ( V_6 , V_20 , V_4 ) ;
F_42 () ;
return;
}
if ( ( V_6 -> V_2 . V_12 & V_133 ) &&
( V_119 != - 1 ) )
V_20 -> V_134 = V_8 -> V_80 . V_81 [ V_119 ] ;
if ( ( V_8 -> V_12 & V_135 ) &&
( F_12 ( V_115 ) ) ) {
T_2 V_36 , V_77 ;
T_1 * V_58 ;
V_58 = F_13 ( V_22 ) ;
V_36 = V_58 [ 0 ] & 0xf ;
V_77 = ( ( F_43 ( V_22 -> V_136 ) + 0x10 )
& V_137 ) ;
F_27 ( & V_20 -> V_28 -> V_27 , V_22 -> V_59 ,
V_36 , V_77 ) ;
}
if ( ! V_121 && F_44 ( V_115 ) ) {
T_2 V_25 ;
V_123 = (struct V_122 * ) V_4 -> V_23 ;
V_25 = F_43 ( V_123 -> V_25 ) ;
if ( ! ( V_25 & V_138 ) ) {
T_2 V_77 = F_43 ( V_123 -> V_139 ) ;
V_36 = ( V_25 &
V_140 ) >>
V_141 ;
F_31 ( V_20 , V_36 , V_77 ) ;
}
}
if ( V_8 -> V_12 & V_142 ) {
F_10 ( V_6 , V_20 , V_4 ) ;
F_42 () ;
return;
} else {
if ( ! V_121 )
V_20 -> V_143 ++ ;
V_20 -> V_144 += V_86 ;
}
F_45 ( V_6 , V_85 , V_20 , V_4 ) ;
if ( F_46 ( & V_20 -> V_28 -> V_27 ) )
F_47 ( V_6 , V_20 , V_4 ) ;
if ( ! ( V_8 -> V_12 & V_145 ) && V_121 )
F_28 ( V_20 , V_4 ) ;
if ( ( V_20 -> V_28 -> V_27 . type == V_60 ) &&
( V_6 -> V_2 . V_12 & V_146 ) )
F_48 ( V_20 -> V_28 , ( void * ) V_4 -> V_23 , V_121 ) ;
if ( V_6 -> V_2 . V_12 & V_146 ) {
if ( V_8 -> V_12 & V_98 ) {
if ( V_20 -> V_147 )
V_20 -> V_147 = 0 ;
} else if ( ++ V_20 -> V_147 >= V_148 ) {
F_49 ( V_20 -> V_28 -> V_149 ,
V_20 -> V_20 . V_49 ,
V_20 -> V_147 ,
V_150 ) ;
V_20 -> V_147 = 0 ;
}
}
}
F_42 () ;
F_50 ( V_6 , 0 ) ;
if ( V_8 -> V_12 & V_98 ) {
if ( F_51 ( V_22 -> V_136 ) ) {
V_6 -> V_151 ++ ;
if ( F_36 ( V_22 -> V_59 ) )
V_6 -> V_152 ++ ;
if ( V_86 > 0 )
V_6 -> V_153 ++ ;
if ( V_86 > 1 )
V_6 -> V_154 ++ ;
}
if ( ! F_36 ( V_22 -> V_59 ) ||
F_52 ( V_115 ) ||
F_53 ( V_115 ) )
V_6 -> V_155 ++ ;
} else {
if ( F_51 ( V_22 -> V_136 ) )
V_6 -> V_156 ++ ;
}
if ( F_54 ( V_115 ) && F_55 ( V_115 ) &&
( V_6 -> V_2 . V_12 & V_146 ) &&
! ( V_8 -> V_12 & V_145 ) &&
V_6 -> V_157 && ! ( V_6 -> V_158 ) ) {
if ( V_8 -> V_12 & V_98 ) {
V_6 -> V_157 -> V_61 . V_69 . V_12 |=
V_159 ;
} else
F_18 ( & V_6 -> V_160 , V_26 +
F_56 ( 10 ) ) ;
}
if ( V_8 -> V_12 & V_161 ) {
T_4 V_162 = ( unsigned long ) V_4 ;
if ( F_54 ( V_22 -> V_33 ) ||
F_57 ( V_22 -> V_33 ) ) {
bool V_121 = V_8 -> V_12 & V_98 ;
F_58 ( V_4 -> V_149 , V_22 -> V_59 ,
V_162 , V_121 , V_150 ) ;
} else {
struct V_163 * V_164 ;
F_39 () ;
F_59 (wk, &local->work_list, list) {
if ( V_164 -> type != V_165 )
continue;
if ( V_164 -> V_166 . V_167 != V_4 )
continue;
V_164 -> V_166 . V_80 = true ;
break;
}
F_42 () ;
if ( V_6 -> V_168 == V_4 ) {
V_162 = V_6 -> V_169 ^ 2 ;
V_6 -> V_168 = NULL ;
}
F_60 (
V_4 -> V_149 , V_162 , V_4 -> V_23 , V_4 -> V_78 ,
! ! ( V_8 -> V_12 & V_98 ) ,
V_150 ) ;
}
}
if ( F_61 ( V_8 -> V_170 ) ) {
struct V_3 * V_171 ;
unsigned long V_12 ;
F_62 ( & V_6 -> V_172 , V_12 ) ;
V_171 = F_63 ( & V_6 -> V_173 ,
V_8 -> V_170 ) ;
if ( V_171 )
F_64 ( & V_6 -> V_173 ,
V_8 -> V_170 ) ;
F_65 ( & V_6 -> V_172 , V_12 ) ;
if ( V_171 )
F_66 ( V_171 ,
V_8 -> V_12 & V_98 ) ;
}
F_67 ( V_4 ) ;
V_120 = ! ! ( V_8 -> V_12 & V_145 ) ||
! ( F_52 ( V_115 ) ) ;
if ( ! V_6 -> V_174 && ( ! V_120 || ! V_6 -> V_175 ) ) {
F_24 ( V_4 ) ;
return;
}
V_87 = F_32 ( V_8 ) ;
if ( F_68 ( F_69 ( V_4 ) < V_87 ) ) {
F_70 ( V_176 L_2 ) ;
F_24 ( V_4 ) ;
return;
}
F_33 ( V_85 , V_4 , V_86 , V_87 ) ;
F_71 ( V_4 , 0 ) ;
V_4 -> V_177 = V_178 ;
V_4 -> V_10 = V_179 ;
V_4 -> V_180 = F_72 ( V_181 ) ;
memset ( V_4 -> V_182 , 0 , sizeof( V_4 -> V_182 ) ) ;
F_39 () ;
F_59 (sdata, &local->interfaces, list) {
if ( V_28 -> V_27 . type == V_183 ) {
if ( ! F_73 ( V_28 ) )
continue;
if ( ( V_28 -> V_61 . V_184 & V_185 ) &&
! V_120 )
continue;
if ( V_117 ) {
V_114 = F_74 ( V_4 , V_150 ) ;
if ( V_114 ) {
V_114 -> V_149 = V_117 ;
F_75 ( V_114 ) ;
}
}
V_117 = V_28 -> V_149 ;
}
}
if ( V_117 ) {
V_4 -> V_149 = V_117 ;
F_75 ( V_4 ) ;
V_4 = NULL ;
}
F_42 () ;
F_24 ( V_4 ) ;
}
void F_76 ( struct V_186 * V_187 , T_5 V_188 )
{
struct V_19 * V_20 = F_77 ( V_187 , struct V_19 , V_20 ) ;
F_49 ( V_20 -> V_28 -> V_149 , V_20 -> V_20 . V_49 ,
V_188 , V_150 ) ;
}
void F_78 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
if ( F_61 ( V_8 -> V_170 ) ) {
struct V_3 * V_171 ;
unsigned long V_12 ;
F_62 ( & V_6 -> V_172 , V_12 ) ;
V_171 = F_63 ( & V_6 -> V_173 ,
V_8 -> V_170 ) ;
if ( V_171 )
F_64 ( & V_6 -> V_173 ,
V_8 -> V_170 ) ;
F_65 ( & V_6 -> V_172 , V_12 ) ;
if ( V_171 )
F_79 ( V_171 ) ;
}
F_79 ( V_4 ) ;
}
