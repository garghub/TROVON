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
F_7 ( V_2 , V_4 ) ;
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
F_21 ( V_20 -> V_28 ,
L_1 ,
F_5 ( & V_20 -> V_43 [ V_24 ] ) ,
! ! F_15 ( V_20 , V_42 ) , V_26 ) ;
F_7 ( & V_6 -> V_2 , V_4 ) ;
}
static void F_22 ( struct V_19 * V_20 , T_1 * V_48 , T_1 V_36 )
{
struct V_49 * V_50 ;
V_50 = F_23 ( V_20 -> V_51 . V_50 [ V_36 ] ) ;
if ( ! V_50 || ! V_50 -> V_52 )
return;
V_50 -> V_52 = false ;
F_24 ( & V_20 -> V_28 -> V_27 , V_48 , V_36 , V_50 -> V_53 ) ;
}
static void F_25 ( struct V_19 * V_20 , struct V_3 * V_4 )
{
struct V_54 * V_55 = ( void * ) V_4 -> V_23 ;
struct V_5 * V_6 = V_20 -> V_6 ;
struct V_56 * V_28 = V_20 -> V_28 ;
if ( F_12 ( V_55 -> V_33 ) ) {
struct V_21 * V_22 = ( void * ) V_4 -> V_23 ;
T_1 * V_57 = F_13 ( V_22 ) ;
T_2 V_36 = V_57 [ 0 ] & 0xf ;
F_22 ( V_20 , V_22 -> V_58 , V_36 ) ;
}
if ( F_26 ( V_55 -> V_33 ) &&
V_55 -> V_59 . V_60 . V_61 == V_62 &&
V_55 -> V_59 . V_60 . V_59 . V_63 . V_60 == V_64 &&
V_28 -> V_27 . type == V_65 &&
F_27 ( V_28 ) ) {
switch ( V_55 -> V_59 . V_60 . V_59 . V_63 . V_66 ) {
case V_67 :
V_28 -> V_68 = V_69 ;
break;
case V_70 :
V_28 -> V_68 = V_71 ;
break;
case V_72 :
default:
V_28 -> V_68 = V_73 ;
break;
}
F_28 ( & V_6 -> V_2 , & V_28 -> V_74 ) ;
}
}
static void F_29 ( struct V_19 * V_20 , T_1 V_36 , T_2 V_75 )
{
struct V_49 * V_50 ;
V_50 = F_23 ( V_20 -> V_51 . V_50 [ V_36 ] ) ;
if ( ! V_50 )
return;
V_50 -> V_53 = V_75 ;
V_50 -> V_52 = true ;
}
static int F_30 ( struct V_7 * V_8 )
{
int V_76 = sizeof( struct V_77 ) ;
if ( V_8 -> V_78 . V_79 [ 0 ] . V_80 >= 0 &&
! ( V_8 -> V_78 . V_79 [ 0 ] . V_12 & V_81 ) )
V_76 += 2 ;
V_76 += 2 ;
V_76 += 1 ;
if ( V_8 -> V_78 . V_79 [ 0 ] . V_80 >= 0 &&
V_8 -> V_78 . V_79 [ 0 ] . V_12 & V_81 )
V_76 += 3 ;
return V_76 ;
}
static void F_31 ( struct V_82
* V_83 , struct V_3 * V_4 ,
int V_84 , int V_85 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
struct V_21 * V_22 = (struct V_21 * ) V_4 -> V_23 ;
struct V_77 * V_86 ;
unsigned char * V_87 ;
T_2 V_88 ;
V_86 = (struct V_77 * ) F_32 ( V_4 , V_85 ) ;
memset ( V_86 , 0 , V_85 ) ;
V_86 -> V_89 = F_11 ( V_85 ) ;
V_86 -> V_90 =
F_33 ( ( 1 << V_91 ) |
( 1 << V_92 ) ) ;
V_87 = ( unsigned char * ) ( V_86 + 1 ) ;
if ( V_8 -> V_78 . V_79 [ 0 ] . V_80 >= 0 &&
! ( V_8 -> V_78 . V_79 [ 0 ] . V_12 & V_81 ) ) {
V_86 -> V_90 |= F_33 ( 1 << V_93 ) ;
* V_87 = V_83 -> V_94 [ V_8 -> V_78 . V_79 [ 0 ] . V_80 ] . V_95 / 5 ;
V_87 += 2 ;
}
V_88 = 0 ;
if ( ! ( V_8 -> V_12 & V_96 ) &&
! F_34 ( V_22 -> V_58 ) )
V_88 |= V_97 ;
if ( ( V_8 -> V_78 . V_79 [ 0 ] . V_12 & V_98 ) ||
( V_8 -> V_78 . V_79 [ 0 ] . V_12 & V_99 ) )
V_88 |= V_100 ;
else if ( V_8 -> V_78 . V_79 [ 0 ] . V_12 & V_98 )
V_88 |= V_101 ;
F_35 ( V_88 , V_87 ) ;
V_87 += 2 ;
* V_87 = V_84 ;
V_87 ++ ;
if ( V_8 -> V_78 . V_79 [ 0 ] . V_80 >= 0 &&
V_8 -> V_78 . V_79 [ 0 ] . V_12 & V_81 ) {
V_86 -> V_90 |= F_33 ( 1 << V_102 ) ;
V_87 [ 0 ] = V_103 |
V_104 |
V_105 ;
if ( V_8 -> V_78 . V_79 [ 0 ] . V_12 & V_106 )
V_87 [ 1 ] |= V_107 ;
if ( V_8 -> V_78 . V_79 [ 0 ] . V_12 & V_108 )
V_87 [ 1 ] |= V_109 ;
if ( V_8 -> V_78 . V_79 [ 0 ] . V_12 & V_110 )
V_87 [ 1 ] |= V_111 ;
V_87 [ 2 ] = V_8 -> V_78 . V_79 [ 0 ] . V_80 ;
V_87 += 3 ;
}
}
static void F_36 ( struct V_5 * V_6 ,
struct V_3 * V_4 , bool V_112 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
struct V_21 * V_22 = ( void * ) V_4 -> V_23 ;
bool V_113 = V_8 -> V_12 & V_96 ;
if ( V_112 )
V_113 = false ;
if ( V_8 -> V_12 & ( V_114 |
V_115 ) ) {
struct V_56 * V_28 = NULL ;
struct V_56 * V_116 ;
T_3 V_117 = ( unsigned long ) V_4 ;
F_37 () ;
if ( V_4 -> V_118 ) {
F_38 (iter_sdata, &local->interfaces,
list) {
if ( ! V_116 -> V_118 )
continue;
if ( V_4 -> V_118 == V_116 -> V_118 ) {
V_28 = V_116 ;
break;
}
}
} else {
V_28 = F_23 ( V_6 -> V_119 ) ;
}
if ( ! V_28 ) {
V_4 -> V_118 = NULL ;
} else if ( V_8 -> V_12 & V_115 ) {
F_39 ( V_28 , V_22 -> V_33 ,
V_113 ) ;
} else if ( F_40 ( V_22 -> V_33 ) ||
F_41 ( V_22 -> V_33 ) ) {
F_42 ( V_28 -> V_118 , V_22 -> V_58 ,
V_117 , V_113 , V_120 ) ;
} else {
F_43 ( & V_28 -> V_121 , V_117 , V_4 -> V_23 ,
V_4 -> V_76 , V_113 , V_120 ) ;
}
F_44 () ;
}
if ( F_45 ( V_8 -> V_122 ) ) {
struct V_3 * V_123 ;
unsigned long V_12 ;
F_46 ( & V_6 -> V_124 , V_12 ) ;
V_123 = F_47 ( & V_6 -> V_125 ,
V_8 -> V_122 ) ;
if ( V_123 )
F_48 ( & V_6 -> V_125 ,
V_8 -> V_122 ) ;
F_49 ( & V_6 -> V_124 , V_12 ) ;
if ( V_123 ) {
if ( ! V_112 ) {
F_50 ( V_123 , V_113 ) ;
} else {
F_51 ( V_123 ) ;
}
}
}
}
void F_52 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_3 * V_126 ;
struct V_21 * V_22 = (struct V_21 * ) V_4 -> V_23 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
T_4 V_127 ;
struct V_82 * V_83 ;
struct V_56 * V_28 ;
struct V_128 * V_129 = NULL ;
struct V_19 * V_20 , * V_9 ;
int V_84 = - 1 , V_130 ;
int V_131 = - 1 ;
bool V_132 ;
bool V_113 ;
struct V_133 * V_134 ;
int V_85 ;
for ( V_130 = 0 ; V_130 < V_135 ; V_130 ++ ) {
if ( ( V_8 -> V_12 & V_136 ) &&
! ( V_8 -> V_12 & V_137 ) ) {
V_8 -> V_78 . V_79 [ V_130 ] . V_80 = - 1 ;
V_8 -> V_78 . V_79 [ V_130 ] . V_138 = 0 ;
break;
} else if ( V_8 -> V_78 . V_79 [ V_130 ] . V_80 < 0 ) {
break;
} else if ( V_130 >= V_2 -> V_139 ) {
V_8 -> V_78 . V_79 [ V_130 ] . V_80 = - 1 ;
V_8 -> V_78 . V_79 [ V_130 ] . V_138 = 0 ;
break;
}
V_84 += V_8 -> V_78 . V_79 [ V_130 ] . V_138 ;
}
V_131 = V_130 - 1 ;
if ( V_84 < 0 )
V_84 = 0 ;
F_37 () ;
V_83 = V_6 -> V_2 . V_140 -> V_141 [ V_8 -> V_142 ] ;
V_127 = V_22 -> V_33 ;
F_53 (local, hdr->addr1, sta, tmp) {
if ( ! F_54 ( V_22 -> V_143 , V_20 -> V_28 -> V_27 . V_48 ) )
continue;
if ( V_8 -> V_12 & V_144 )
F_55 ( V_20 , V_145 ) ;
V_113 = ! ! ( V_8 -> V_12 & V_96 ) ;
if ( ! V_113 && F_15 ( V_20 , V_42 ) ) {
F_10 ( V_6 , V_20 , V_4 ) ;
F_44 () ;
return;
}
if ( F_56 ( & V_20 -> V_28 -> V_27 ) &&
F_12 ( V_127 ) )
F_57 (
F_13 ( V_22 ) ,
V_20 , true , V_113 ) ;
if ( ( V_6 -> V_2 . V_12 & V_146 ) &&
( V_131 != - 1 ) )
V_20 -> V_147 = V_8 -> V_78 . V_79 [ V_131 ] ;
if ( ( V_8 -> V_12 & V_148 ) &&
( F_12 ( V_127 ) ) ) {
T_2 V_36 , V_75 ;
T_1 * V_57 ;
V_57 = F_13 ( V_22 ) ;
V_36 = V_57 [ 0 ] & 0xf ;
V_75 = ( ( F_58 ( V_22 -> V_149 ) + 0x10 )
& V_150 ) ;
F_24 ( & V_20 -> V_28 -> V_27 , V_22 -> V_58 ,
V_36 , V_75 ) ;
}
if ( ! V_113 && F_59 ( V_127 ) ) {
T_2 V_36 , V_25 ;
V_134 = (struct V_133 * ) V_4 -> V_23 ;
V_25 = F_58 ( V_134 -> V_25 ) ;
if ( ! ( V_25 & V_151 ) ) {
T_2 V_75 = F_58 ( V_134 -> V_152 ) ;
V_36 = ( V_25 &
V_153 ) >>
V_154 ;
F_29 ( V_20 , V_36 , V_75 ) ;
}
}
if ( V_8 -> V_12 & V_155 ) {
F_10 ( V_6 , V_20 , V_4 ) ;
F_44 () ;
return;
} else {
if ( ! V_113 )
V_20 -> V_156 ++ ;
V_20 -> V_157 += V_84 ;
}
F_60 ( V_6 , V_83 , V_20 , V_4 ) ;
if ( F_56 ( & V_20 -> V_28 -> V_27 ) )
F_61 ( V_6 , V_20 , V_4 ) ;
if ( ! ( V_8 -> V_12 & V_158 ) && V_113 )
F_25 ( V_20 , V_4 ) ;
if ( ( V_20 -> V_28 -> V_27 . type == V_65 ) &&
( V_6 -> V_2 . V_12 & V_159 ) )
F_62 ( V_20 -> V_28 , ( void * ) V_4 -> V_23 , V_113 ) ;
if ( V_6 -> V_2 . V_12 & V_159 ) {
if ( V_8 -> V_12 & V_96 ) {
if ( V_20 -> V_160 )
V_20 -> V_160 = 0 ;
} else if ( ++ V_20 -> V_160 >= V_161 ) {
F_63 ( V_20 -> V_28 -> V_118 ,
V_20 -> V_20 . V_48 ,
V_20 -> V_160 ,
V_120 ) ;
V_20 -> V_160 = 0 ;
}
}
if ( V_113 )
V_20 -> V_162 = V_8 -> V_78 . V_163 ;
}
F_44 () ;
F_64 ( V_6 , 0 ) ;
if ( V_8 -> V_12 & V_96 ) {
if ( F_65 ( V_22 -> V_149 ) ) {
V_6 -> V_164 ++ ;
if ( F_34 ( V_22 -> V_58 ) )
V_6 -> V_165 ++ ;
if ( V_84 > 0 )
V_6 -> V_166 ++ ;
if ( V_84 > 1 )
V_6 -> V_167 ++ ;
}
if ( ! F_34 ( V_22 -> V_58 ) ||
F_66 ( V_127 ) ||
F_67 ( V_127 ) )
V_6 -> V_168 ++ ;
} else {
if ( F_65 ( V_22 -> V_149 ) )
V_6 -> V_169 ++ ;
}
if ( F_40 ( V_127 ) && F_68 ( V_127 ) &&
( V_6 -> V_2 . V_12 & V_159 ) &&
! ( V_8 -> V_12 & V_158 ) &&
V_6 -> V_170 && ! ( V_6 -> V_171 ) ) {
if ( V_8 -> V_12 & V_96 ) {
V_6 -> V_170 -> V_59 . V_172 . V_12 |=
V_173 ;
} else
F_18 ( & V_6 -> V_174 , V_26 +
F_69 ( 10 ) ) ;
}
F_36 ( V_6 , V_4 , false ) ;
F_70 ( V_4 ) ;
V_132 = ! ! ( V_8 -> V_12 & V_158 ) ||
! ( F_66 ( V_127 ) ) ;
if ( ! V_6 -> V_175 && ( ! V_132 || ! V_6 -> V_176 ) ) {
F_71 ( V_4 ) ;
return;
}
V_85 = F_30 ( V_8 ) ;
if ( F_72 ( F_73 ( V_4 ) < V_85 ) ) {
F_74 ( L_2 ) ;
F_71 ( V_4 ) ;
return;
}
F_31 ( V_83 , V_4 , V_84 , V_85 ) ;
F_75 ( V_4 , 0 ) ;
V_4 -> V_177 = V_178 ;
V_4 -> V_10 = V_179 ;
V_4 -> V_180 = F_76 ( V_181 ) ;
memset ( V_4 -> V_182 , 0 , sizeof( V_4 -> V_182 ) ) ;
F_37 () ;
F_38 (sdata, &local->interfaces, list) {
if ( V_28 -> V_27 . type == V_183 ) {
if ( ! F_27 ( V_28 ) )
continue;
if ( ( V_28 -> V_59 . V_184 & V_185 ) &&
! V_132 )
continue;
if ( V_129 ) {
V_126 = F_77 ( V_4 , V_120 ) ;
if ( V_126 ) {
V_126 -> V_118 = V_129 ;
F_78 ( V_126 ) ;
}
}
V_129 = V_28 -> V_118 ;
}
}
if ( V_129 ) {
V_4 -> V_118 = V_129 ;
F_78 ( V_4 ) ;
V_4 = NULL ;
}
F_44 () ;
F_71 ( V_4 ) ;
}
void F_79 ( struct V_186 * V_187 , T_5 V_188 )
{
struct V_19 * V_20 = F_80 ( V_187 , struct V_19 , V_20 ) ;
F_63 ( V_20 -> V_28 -> V_118 , V_20 -> V_20 . V_48 ,
V_188 , V_120 ) ;
}
void F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_36 ( V_6 , V_4 , true ) ;
F_51 ( V_4 ) ;
}
void F_81 ( struct V_1 * V_2 ,
struct V_189 * V_190 )
{
struct V_3 * V_4 ;
while ( ( V_4 = F_82 ( V_190 ) ) )
F_7 ( V_2 , V_4 ) ;
}
