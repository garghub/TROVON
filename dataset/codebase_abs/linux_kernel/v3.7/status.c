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
V_28 -> V_27 . type == V_59 &&
V_55 -> V_60 . V_61 . V_62 == V_63 &&
V_55 -> V_60 . V_61 . V_60 . V_64 . V_61 == V_65 ) {
switch ( V_55 -> V_60 . V_61 . V_60 . V_64 . V_66 ) {
case V_67 :
V_20 -> V_28 -> V_60 . V_68 . V_69 = V_70 ;
break;
case V_71 :
V_20 -> V_28 -> V_60 . V_68 . V_69 = V_72 ;
break;
case V_73 :
default:
V_20 -> V_28 -> V_60 . V_68 . V_69 = V_74 ;
break;
}
F_27 ( & V_6 -> V_2 , & V_6 -> V_75 ) ;
}
}
static void F_28 ( struct V_19 * V_20 , T_1 V_36 , T_2 V_76 )
{
struct V_49 * V_50 ;
V_50 = F_23 ( V_20 -> V_51 . V_50 [ V_36 ] ) ;
if ( ! V_50 )
return;
V_50 -> V_53 = V_76 ;
V_50 -> V_52 = true ;
}
static int F_29 ( struct V_7 * V_8 )
{
int V_77 = sizeof( struct V_78 ) ;
if ( V_8 -> V_79 . V_80 [ 0 ] . V_81 >= 0 &&
! ( V_8 -> V_79 . V_80 [ 0 ] . V_12 & V_82 ) )
V_77 += 2 ;
V_77 += 2 ;
V_77 += 1 ;
if ( V_8 -> V_79 . V_80 [ 0 ] . V_81 >= 0 &&
V_8 -> V_79 . V_80 [ 0 ] . V_12 & V_82 )
V_77 += 3 ;
return V_77 ;
}
static void F_30 ( struct V_83
* V_84 , struct V_3 * V_4 ,
int V_85 , int V_86 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
struct V_21 * V_22 = (struct V_21 * ) V_4 -> V_23 ;
struct V_78 * V_87 ;
unsigned char * V_88 ;
T_2 V_89 ;
V_87 = (struct V_78 * ) F_31 ( V_4 , V_86 ) ;
memset ( V_87 , 0 , V_86 ) ;
V_87 -> V_90 = F_11 ( V_86 ) ;
V_87 -> V_91 =
F_32 ( ( 1 << V_92 ) |
( 1 << V_93 ) ) ;
V_88 = ( unsigned char * ) ( V_87 + 1 ) ;
if ( V_8 -> V_79 . V_80 [ 0 ] . V_81 >= 0 &&
! ( V_8 -> V_79 . V_80 [ 0 ] . V_12 & V_82 ) ) {
V_87 -> V_91 |= F_32 ( 1 << V_94 ) ;
* V_88 = V_84 -> V_95 [ V_8 -> V_79 . V_80 [ 0 ] . V_81 ] . V_96 / 5 ;
V_88 += 2 ;
}
V_89 = 0 ;
if ( ! ( V_8 -> V_12 & V_97 ) &&
! F_33 ( V_22 -> V_58 ) )
V_89 |= V_98 ;
if ( ( V_8 -> V_79 . V_80 [ 0 ] . V_12 & V_99 ) ||
( V_8 -> V_79 . V_80 [ 0 ] . V_12 & V_100 ) )
V_89 |= V_101 ;
else if ( V_8 -> V_79 . V_80 [ 0 ] . V_12 & V_99 )
V_89 |= V_102 ;
F_34 ( V_89 , V_88 ) ;
V_88 += 2 ;
* V_88 = V_85 ;
V_88 ++ ;
if ( V_8 -> V_79 . V_80 [ 0 ] . V_81 >= 0 &&
V_8 -> V_79 . V_80 [ 0 ] . V_12 & V_82 ) {
V_87 -> V_91 |= F_32 ( 1 << V_103 ) ;
V_88 [ 0 ] = V_104 |
V_105 |
V_106 ;
if ( V_8 -> V_79 . V_80 [ 0 ] . V_12 & V_107 )
V_88 [ 1 ] |= V_108 ;
if ( V_8 -> V_79 . V_80 [ 0 ] . V_12 & V_109 )
V_88 [ 1 ] |= V_110 ;
if ( V_8 -> V_79 . V_80 [ 0 ] . V_12 & V_111 )
V_88 [ 1 ] |= V_112 ;
V_88 [ 2 ] = V_8 -> V_79 . V_80 [ 0 ] . V_81 ;
V_88 += 3 ;
}
}
void F_35 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_3 * V_113 ;
struct V_21 * V_22 = (struct V_21 * ) V_4 -> V_23 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
T_3 V_114 ;
struct V_83 * V_84 ;
struct V_56 * V_28 ;
struct V_115 * V_116 = NULL ;
struct V_19 * V_20 , * V_9 ;
int V_85 = - 1 , V_117 ;
int V_118 = - 1 ;
bool V_119 ;
bool V_120 ;
struct V_121 * V_122 ;
int V_86 ;
for ( V_117 = 0 ; V_117 < V_123 ; V_117 ++ ) {
if ( ( V_8 -> V_12 & V_124 ) &&
! ( V_8 -> V_12 & V_125 ) ) {
V_8 -> V_79 . V_80 [ V_117 ] . V_81 = - 1 ;
V_8 -> V_79 . V_80 [ V_117 ] . V_126 = 0 ;
break;
} else if ( V_8 -> V_79 . V_80 [ V_117 ] . V_81 < 0 ) {
break;
} else if ( V_117 >= V_2 -> V_127 ) {
V_8 -> V_79 . V_80 [ V_117 ] . V_81 = - 1 ;
V_8 -> V_79 . V_80 [ V_117 ] . V_126 = 0 ;
break;
}
V_85 += V_8 -> V_79 . V_80 [ V_117 ] . V_126 ;
}
V_118 = V_117 - 1 ;
if ( V_85 < 0 )
V_85 = 0 ;
F_36 () ;
V_84 = V_6 -> V_2 . V_128 -> V_129 [ V_8 -> V_130 ] ;
V_114 = V_22 -> V_33 ;
F_37 (local, hdr->addr1, sta, tmp) {
if ( ! F_38 ( V_22 -> V_131 , V_20 -> V_28 -> V_27 . V_48 ) )
continue;
if ( V_8 -> V_12 & V_132 )
F_39 ( V_20 , V_133 ) ;
V_120 = ! ! ( V_8 -> V_12 & V_97 ) ;
if ( ! V_120 && F_15 ( V_20 , V_42 ) ) {
F_10 ( V_6 , V_20 , V_4 ) ;
F_40 () ;
return;
}
if ( ( V_6 -> V_2 . V_12 & V_134 ) &&
( V_118 != - 1 ) )
V_20 -> V_135 = V_8 -> V_79 . V_80 [ V_118 ] ;
if ( ( V_8 -> V_12 & V_136 ) &&
( F_12 ( V_114 ) ) ) {
T_2 V_36 , V_76 ;
T_1 * V_57 ;
V_57 = F_13 ( V_22 ) ;
V_36 = V_57 [ 0 ] & 0xf ;
V_76 = ( ( F_41 ( V_22 -> V_137 ) + 0x10 )
& V_138 ) ;
F_24 ( & V_20 -> V_28 -> V_27 , V_22 -> V_58 ,
V_36 , V_76 ) ;
}
if ( ! V_120 && F_42 ( V_114 ) ) {
T_2 V_36 , V_25 ;
V_122 = (struct V_121 * ) V_4 -> V_23 ;
V_25 = F_41 ( V_122 -> V_25 ) ;
if ( ! ( V_25 & V_139 ) ) {
T_2 V_76 = F_41 ( V_122 -> V_140 ) ;
V_36 = ( V_25 &
V_141 ) >>
V_142 ;
F_28 ( V_20 , V_36 , V_76 ) ;
}
}
if ( V_8 -> V_12 & V_143 ) {
F_10 ( V_6 , V_20 , V_4 ) ;
F_40 () ;
return;
} else {
if ( ! V_120 )
V_20 -> V_144 ++ ;
V_20 -> V_145 += V_85 ;
}
F_43 ( V_6 , V_84 , V_20 , V_4 ) ;
if ( F_44 ( & V_20 -> V_28 -> V_27 ) )
F_45 ( V_6 , V_20 , V_4 ) ;
if ( ! ( V_8 -> V_12 & V_146 ) && V_120 )
F_25 ( V_20 , V_4 ) ;
if ( ( V_20 -> V_28 -> V_27 . type == V_59 ) &&
( V_6 -> V_2 . V_12 & V_147 ) )
F_46 ( V_20 -> V_28 , ( void * ) V_4 -> V_23 , V_120 ) ;
if ( V_6 -> V_2 . V_12 & V_147 ) {
if ( V_8 -> V_12 & V_97 ) {
if ( V_20 -> V_148 )
V_20 -> V_148 = 0 ;
} else if ( ++ V_20 -> V_148 >= V_149 ) {
F_47 ( V_20 -> V_28 -> V_150 ,
V_20 -> V_20 . V_48 ,
V_20 -> V_148 ,
V_151 ) ;
V_20 -> V_148 = 0 ;
}
}
}
F_40 () ;
F_48 ( V_6 , 0 ) ;
if ( V_8 -> V_12 & V_97 ) {
if ( F_49 ( V_22 -> V_137 ) ) {
V_6 -> V_152 ++ ;
if ( F_33 ( V_22 -> V_58 ) )
V_6 -> V_153 ++ ;
if ( V_85 > 0 )
V_6 -> V_154 ++ ;
if ( V_85 > 1 )
V_6 -> V_155 ++ ;
}
if ( ! F_33 ( V_22 -> V_58 ) ||
F_50 ( V_114 ) ||
F_51 ( V_114 ) )
V_6 -> V_156 ++ ;
} else {
if ( F_49 ( V_22 -> V_137 ) )
V_6 -> V_157 ++ ;
}
if ( F_52 ( V_114 ) && F_53 ( V_114 ) &&
( V_6 -> V_2 . V_12 & V_147 ) &&
! ( V_8 -> V_12 & V_146 ) &&
V_6 -> V_158 && ! ( V_6 -> V_159 ) ) {
if ( V_8 -> V_12 & V_97 ) {
V_6 -> V_158 -> V_60 . V_68 . V_12 |=
V_160 ;
} else
F_18 ( & V_6 -> V_161 , V_26 +
F_54 ( 10 ) ) ;
}
if ( V_8 -> V_12 & V_162 ) {
T_4 V_163 = ( unsigned long ) V_4 ;
bool V_164 = false ;
V_120 = V_8 -> V_12 & V_97 ;
F_36 () ;
F_55 (sdata, &local->interfaces, list) {
if ( ! V_28 -> V_150 )
continue;
if ( V_4 -> V_150 != V_28 -> V_150 )
continue;
V_164 = true ;
break;
}
if ( ! V_4 -> V_150 ) {
V_28 = F_23 ( V_6 -> V_165 ) ;
if ( V_28 )
V_164 = true ;
}
if ( ! V_164 )
V_4 -> V_150 = NULL ;
else if ( F_52 ( V_22 -> V_33 ) ||
F_56 ( V_22 -> V_33 ) ) {
F_57 ( V_28 -> V_150 , V_22 -> V_58 ,
V_163 , V_120 , V_151 ) ;
} else {
F_58 ( & V_28 -> V_166 , V_163 , V_4 -> V_23 ,
V_4 -> V_77 , V_120 , V_151 ) ;
}
F_40 () ;
}
if ( F_59 ( V_8 -> V_167 ) ) {
struct V_3 * V_168 ;
unsigned long V_12 ;
F_60 ( & V_6 -> V_169 , V_12 ) ;
V_168 = F_61 ( & V_6 -> V_170 ,
V_8 -> V_167 ) ;
if ( V_168 )
F_62 ( & V_6 -> V_170 ,
V_8 -> V_167 ) ;
F_63 ( & V_6 -> V_169 , V_12 ) ;
if ( V_168 )
F_64 ( V_168 ,
V_8 -> V_12 & V_97 ) ;
}
F_65 ( V_4 ) ;
V_119 = ! ! ( V_8 -> V_12 & V_146 ) ||
! ( F_50 ( V_114 ) ) ;
if ( ! V_6 -> V_171 && ( ! V_119 || ! V_6 -> V_172 ) ) {
F_66 ( V_4 ) ;
return;
}
V_86 = F_29 ( V_8 ) ;
if ( F_67 ( F_68 ( V_4 ) < V_86 ) ) {
F_69 ( L_2 ) ;
F_66 ( V_4 ) ;
return;
}
F_30 ( V_84 , V_4 , V_85 , V_86 ) ;
F_70 ( V_4 , 0 ) ;
V_4 -> V_173 = V_174 ;
V_4 -> V_10 = V_175 ;
V_4 -> V_176 = F_71 ( V_177 ) ;
memset ( V_4 -> V_178 , 0 , sizeof( V_4 -> V_178 ) ) ;
F_36 () ;
F_55 (sdata, &local->interfaces, list) {
if ( V_28 -> V_27 . type == V_179 ) {
if ( ! F_72 ( V_28 ) )
continue;
if ( ( V_28 -> V_60 . V_180 & V_181 ) &&
! V_119 )
continue;
if ( V_116 ) {
V_113 = F_73 ( V_4 , V_151 ) ;
if ( V_113 ) {
V_113 -> V_150 = V_116 ;
F_74 ( V_113 ) ;
}
}
V_116 = V_28 -> V_150 ;
}
}
if ( V_116 ) {
V_4 -> V_150 = V_116 ;
F_74 ( V_4 ) ;
V_4 = NULL ;
}
F_40 () ;
F_66 ( V_4 ) ;
}
void F_75 ( struct V_182 * V_183 , T_5 V_184 )
{
struct V_19 * V_20 = F_76 ( V_183 , struct V_19 , V_20 ) ;
F_47 ( V_20 -> V_28 -> V_150 , V_20 -> V_20 . V_48 ,
V_184 , V_151 ) ;
}
void F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
if ( F_59 ( V_8 -> V_167 ) ) {
struct V_3 * V_168 ;
unsigned long V_12 ;
F_60 ( & V_6 -> V_169 , V_12 ) ;
V_168 = F_61 ( & V_6 -> V_170 ,
V_8 -> V_167 ) ;
if ( V_168 )
F_62 ( & V_6 -> V_170 ,
V_8 -> V_167 ) ;
F_63 ( & V_6 -> V_169 , V_12 ) ;
if ( V_168 )
F_77 ( V_168 ) ;
}
F_77 ( V_4 ) ;
}
void F_78 ( struct V_1 * V_2 ,
struct V_185 * V_186 )
{
struct V_3 * V_4 ;
while ( ( V_4 = F_79 ( V_186 ) ) )
F_7 ( V_2 , V_4 ) ;
}
