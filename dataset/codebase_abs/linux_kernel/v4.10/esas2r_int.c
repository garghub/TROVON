void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_1 V_4 ;
F_2 ( V_2 ) ;
V_3 = F_3 ( V_2 , V_5 ) ;
if ( V_3 & V_6 ) {
F_4 ( V_2 , V_7 ,
V_8 ) ;
F_5 ( V_2 , V_7 ) ;
F_6 ( V_2 ) ;
}
if ( V_3 & V_9 ) {
V_4 = F_3 ( V_2 , V_10 ) ;
if ( V_4 != 0 )
F_7 ( V_2 , V_4 ) ;
}
F_8 ( V_2 ) ;
if ( F_9 ( & V_2 -> V_11 ) == 0 )
F_10 ( V_2 ) ;
}
T_2 F_11 ( int V_12 , void * V_13 )
{
struct V_1 * V_2 = (struct V_1 * ) V_13 ;
if ( ! F_12 ( V_2 ) )
return V_14 ;
F_13 ( V_15 , & V_2 -> V_16 ) ;
F_14 ( V_2 ) ;
return V_17 ;
}
void F_15 ( struct V_1 * V_2 )
{
T_1 V_4 ;
if ( F_16 ( V_2 -> V_18 & V_6 ) ) {
F_4 ( V_2 , V_7 ,
V_8 ) ;
F_5 ( V_2 , V_7 ) ;
F_6 ( V_2 ) ;
}
if ( F_17 ( V_2 -> V_18 & V_9 ) ) {
V_4 = F_3 ( V_2 , V_10 ) ;
if ( V_4 != 0 )
F_7 ( V_2 , V_4 ) ;
}
V_2 -> V_19 = V_20 ;
F_8 ( V_2 ) ;
if ( F_16 ( F_9 ( & V_2 -> V_11 ) == 0 ) )
F_10 ( V_2 ) ;
}
T_2 F_18 ( int V_12 , void * V_13 )
{
struct V_1 * V_2 = (struct V_1 * ) V_13 ;
T_1 V_3 ;
T_1 V_4 ;
V_3 = F_3 ( V_2 , V_5 ) ;
if ( F_16 ( V_3 & V_6 ) ) {
F_4 ( V_2 , V_7 ,
V_8 ) ;
F_5 ( V_2 , V_7 ) ;
F_6 ( V_2 ) ;
}
if ( F_17 ( V_3 & V_9 ) ) {
V_4 = F_3 ( V_2 , V_10 ) ;
if ( V_4 != 0 )
F_7 ( V_2 , V_4 ) ;
}
F_2 ( V_2 ) ;
F_8 ( V_2 ) ;
if ( F_16 ( F_9 ( & V_2 -> V_11 ) == 0 ) )
F_10 ( V_2 ) ;
F_19 ( V_2 ) ;
return 1 ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 )
{
if ( F_17 ( V_22 -> V_25 != V_26 ) ) {
memcpy ( & V_22 -> V_27 , & V_24 -> V_27 , sizeof( V_24 -> V_27 ) ) ;
if ( V_22 -> V_25 == V_28 ) {
if ( V_22 -> V_29 > V_30 )
V_22 -> V_25 = V_31 ;
} else if ( V_22 -> V_25 == V_32 ) {
T_3 V_33 = V_22 -> V_27 . V_34 . V_35 ;
F_21 ( L_1 , V_33 ) ;
if ( V_33 == V_36 || V_33 ==
V_37 || V_33 ==
V_38 || V_33 ==
V_39 ) {
V_22 -> V_25 = V_26 ;
V_22 -> V_27 . V_34 . V_35 =
V_36 ;
}
}
}
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_23 * V_24 ;
T_1 V_40 ;
T_1 V_41 ;
struct V_21 * V_22 ;
T_1 V_42 ;
unsigned long V_43 ;
F_22 ( V_44 ) ;
F_23 () ;
F_24 ( & V_2 -> V_45 , V_43 ) ;
V_40 = F_25 ( * V_2 -> V_46 ) & V_47 ;
V_41 = V_2 -> V_48 ;
F_21 ( L_2 , V_40 , V_41 ) ;
if ( F_17 ( V_41 == V_40 ) ) {
F_26 ( & V_2 -> V_45 , V_43 ) ;
F_27 () ;
return;
}
if ( F_17 ( V_40 >= V_2 -> V_49 ) ) {
F_26 ( & V_2 -> V_45 , V_43 ) ;
F_28 () ;
F_29 ( V_2 ) ;
F_27 () ;
return;
}
do {
V_41 ++ ;
if ( V_41 >= V_2 -> V_49 )
V_41 = 0 ;
V_24 = (struct V_23 * ) V_2 -> V_50 . V_51
+ V_41 ;
V_42 = V_24 -> V_42 ;
if ( F_17 ( F_30 ( V_42 ) == 0
|| F_30 ( V_42 ) > V_52 +
V_53 + 1 ) ) {
F_28 () ;
continue;
}
V_22 = V_2 -> V_54 [ F_30 ( V_42 ) ] ;
if ( F_17 ( V_22 == NULL || V_22 -> V_55 -> V_56 . V_42 != V_42 ) ) {
F_28 () ;
continue;
}
F_31 ( & V_22 -> V_57 ) ;
V_22 -> V_25 = V_24 -> V_25 ;
F_21 ( L_3 , V_42 ) ;
F_21 ( L_4 , V_22 ) ;
F_21 ( L_5 , V_22 -> V_25 ) ;
if ( F_16 ( V_22 -> V_55 -> V_56 . V_58 == V_59 ) ) {
F_20 ( V_2 , V_22 , V_24 ) ;
} else {
memcpy ( & V_22 -> V_27 , & V_24 -> V_27 ,
sizeof( V_24 -> V_27 ) ) ;
}
F_32 ( & V_22 -> V_44 , & V_44 ) ;
} while ( V_41 != V_40 );
V_2 -> V_48 = V_41 ;
F_26 ( & V_2 -> V_45 , V_43 ) ;
F_33 ( V_2 , & V_44 ) ;
F_27 () ;
}
void F_10 ( struct V_1 * V_2 )
{
int V_60 = 2 ;
struct V_21 * V_22 ;
unsigned long V_43 ;
if ( F_34 ( V_61 , & V_2 -> V_43 ) ||
F_34 ( V_62 , & V_2 -> V_43 ) )
V_60 = 0 ;
else if ( F_34 ( V_63 , & V_2 -> V_43 ) )
V_60 = 1 ;
F_35 ( & V_2 -> V_11 ) ;
if ( F_36 ( V_2 ) ) {
F_14 ( V_2 ) ;
V_60 = 0 ;
}
if ( V_60 && ! F_37 ( & V_2 -> V_64 ) ) {
F_22 ( V_44 ) ;
struct V_65 * V_66 , * V_67 ;
F_24 ( & V_2 -> V_45 , V_43 ) ;
F_38 (element, next, &a->defer_list) {
V_22 = F_39 ( V_66 , struct V_21 ,
V_57 ) ;
if ( V_22 -> V_25 != V_68 ) {
F_31 ( V_66 ) ;
F_32 ( & V_22 -> V_44 , & V_44 ) ;
}
else if ( V_22 -> V_69 == V_70 ) {
F_31 ( V_66 ) ;
F_40 ( V_2 , V_22 ) ;
} else if ( V_60 == 2 ) {
F_31 ( V_66 ) ;
F_41 ( V_2 , V_22 ) ;
if ( F_34 ( V_62 , & V_2 -> V_43 ) )
break;
}
}
F_26 ( & V_2 -> V_45 , V_43 ) ;
F_33 ( V_2 , & V_44 ) ;
}
F_42 ( & V_2 -> V_11 ) ;
}
void F_43 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = & V_2 -> V_71 ;
unsigned long V_43 ;
struct V_72 * V_73 ;
F_22 ( V_44 ) ;
struct V_65 * V_66 ;
F_23 () ;
F_24 ( & V_2 -> V_45 , V_43 ) ;
if ( V_22 -> V_74 ) {
V_73 = (struct V_72 * ) V_22 -> V_74 ;
V_73 -> V_75 = 0 ;
F_44 ( V_76 , & V_2 -> V_43 ) ;
}
V_22 -> V_74 = NULL ;
V_22 -> V_77 = NULL ;
V_22 -> V_78 = V_79 ;
* V_2 -> V_46 =
V_2 -> V_80 =
V_2 -> V_48 = V_2 -> V_49 - 1 ;
F_13 ( V_81 , & V_2 -> V_43 ) ;
F_45 (element, &a->defer_list) {
V_22 = F_39 ( V_66 , struct V_21 , V_57 ) ;
if ( V_22 -> V_25 == V_82 )
if ( F_46 ( V_2 , V_22 , V_28 ) )
F_32 ( & V_22 -> V_44 , & V_44 ) ;
}
F_26 ( & V_2 -> V_45 , V_43 ) ;
F_33 ( V_2 , & V_44 ) ;
F_47 ( V_2 ) ;
F_27 () ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_21 * V_22 ;
struct V_65 * V_66 ;
unsigned long V_43 ;
F_22 ( V_44 ) ;
F_23 () ;
F_48 ( L_6 ) ;
F_24 ( & V_2 -> V_45 , V_43 ) ;
F_45 (element, &a->defer_list) {
V_22 = F_39 ( V_66 , struct V_21 , V_57 ) ;
if ( F_46 ( V_2 , V_22 , V_28 ) )
F_32 ( & V_22 -> V_44 , & V_44 ) ;
}
F_26 ( & V_2 -> V_45 , V_43 ) ;
F_33 ( V_2 , & V_44 ) ;
if ( F_9 ( & V_2 -> V_11 ) == 0 )
F_10 ( V_2 ) ;
F_44 ( V_83 , & V_2 -> V_43 ) ;
F_27 () ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_44 ( V_84 , & V_2 -> V_43 ) ;
F_44 ( V_85 , & V_2 -> V_43 ) ;
F_44 ( V_86 , & V_2 -> V_43 ) ;
F_44 ( V_87 , & V_2 -> V_43 ) ;
if ( ! F_50 ( V_2 ) || ( V_2 -> V_88 >=
V_89 ) ) {
F_48 ( L_7 ) ;
F_13 ( V_90 , & V_2 -> V_43 ) ;
F_13 ( V_91 , & V_2 -> V_43 ) ;
F_44 ( V_61 , & V_2 -> V_43 ) ;
F_44 ( V_63 , & V_2 -> V_43 ) ;
F_2 ( V_2 ) ;
V_2 -> V_19 = 0 ;
F_43 ( V_2 ) ;
F_51 ( V_92 ,
L_8 ) ;
} else {
bool V_93 = F_52 ( V_94 , & V_2 -> V_43 ) ;
if ( ! V_93 )
F_2 ( V_2 ) ;
if ( ( F_34 ( V_95 , & V_2 -> V_43 ) ) &&
! F_34 ( V_96 , & V_2 -> V_43 ) && ! V_93 ) {
} else {
F_48 ( L_9 ) ;
F_53 ( V_2 ) ;
}
V_2 -> V_88 += V_97 ;
V_2 -> V_98 = F_54 ( V_99 ) ;
if ( ! F_34 ( V_95 , & V_2 -> V_43 ) ) {
F_43 ( V_2 ) ;
if ( ! V_93 ) {
V_2 -> V_100 =
F_55 ( V_2 ) ;
F_56 ( V_2 , false ) ;
}
}
V_2 -> V_19 = 0 ;
}
}
static void F_57 ( struct V_1 * V_2 )
{
while ( F_34 ( V_101 , & V_2 -> V_43 ) ) {
if ( ! F_34 ( V_90 , & V_2 -> V_43 ) &&
! F_34 ( V_95 , & V_2 -> V_43 ) )
F_2 ( V_2 ) ;
F_58 ( V_2 ) ;
F_59 ( V_2 , 0 ) ;
if ( F_34 ( V_84 , & V_2 -> V_43 ) )
break;
if ( F_34 ( V_95 , & V_2 -> V_43 ) ) {
if ( F_34 ( V_96 , & V_2 -> V_43 ) ) {
F_51 ( V_92 ,
L_10 ) ;
} else {
F_44 ( V_95 , & V_2 -> V_43 ) ;
F_60 ( V_2 , true ) ;
}
} else {
if ( F_34 ( V_96 , & V_2 -> V_43 ) ) {
} else {
F_60 ( V_2 , false ) ;
}
F_51 ( V_92 ,
L_11 ) ;
}
F_44 ( V_94 , & V_2 -> V_43 ) ;
F_8 ( V_2 ) ;
F_44 ( V_101 , & V_2 -> V_43 ) ;
}
}
void F_19 ( struct V_1 * V_2 )
{
if ( F_34 ( V_84 , & V_2 -> V_43 ) ||
F_34 ( V_101 , & V_2 -> V_43 ) ) {
if ( F_34 ( V_84 , & V_2 -> V_43 ) )
F_49 ( V_2 ) ;
F_57 ( V_2 ) ;
}
if ( F_34 ( V_85 , & V_2 -> V_43 ) ) {
F_48 ( L_12 ) ;
F_44 ( V_85 , & V_2 -> V_43 ) ;
if ( F_34 ( V_62 , & V_2 -> V_43 ) )
F_13 ( V_86 , & V_2 -> V_43 ) ;
else
F_4 ( V_2 , V_102 ,
V_103 ) ;
}
if ( F_34 ( V_86 , & V_2 -> V_43 ) ) {
F_47 ( V_2 ) ;
F_61 ( V_104 ,
& ( V_2 -> V_105 -> V_106 ) ,
L_13 ) ;
F_62 ( V_2 -> V_105 , 0 ) ;
F_44 ( V_86 , & V_2 -> V_43 ) ;
F_44 ( V_87 , & V_2 -> V_43 ) ;
F_51 ( V_104 , L_14 ) ;
}
if ( F_34 ( V_107 , & V_2 -> V_43 ) ) {
F_44 ( V_107 , & V_2 -> V_43 ) ;
F_63 ( V_2 ) ;
}
if ( F_9 ( & V_2 -> V_11 ) == 0 )
F_10 ( V_2 ) ;
}
static void F_7 ( struct V_1 * V_2 , T_1 V_4 )
{
if ( ! ( V_4 & V_108 ) ) {
F_23 () ;
F_21 ( L_15 , V_4 ) ;
}
F_4 ( V_2 , V_10 , V_4 ) ;
if ( V_4 & V_103 )
F_13 ( V_86 , & V_2 -> V_43 ) ;
if ( V_4 & V_108 )
F_44 ( V_109 , & V_2 -> V_43 ) ;
if ( V_4 & V_110 ) {
F_48 ( L_16 ) ;
F_51 ( V_92 , L_17 ) ;
}
if ( V_4 & V_111 ) {
F_13 ( V_112 , & V_2 -> V_16 ) ;
F_29 ( V_2 ) ;
}
if ( ! ( V_4 & V_108 ) )
F_27 () ;
}
void F_64 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_102 , V_108 |
V_113 ) ;
}
static void F_65 ( struct V_1 * V_2 , union V_114 * V_115 ,
T_4 V_116 , T_1 V_117 )
{
struct V_118 * V_119 = V_2 -> V_120 + V_116 ;
T_1 V_121 = V_117 ;
unsigned long V_43 ;
if ( V_121 > sizeof( V_119 -> V_122 ) )
V_121 = sizeof( V_119 -> V_122 ) ;
F_21 ( L_18 , V_115 -> V_123 . V_124 ) ;
F_21 ( L_19 , V_115 -> V_123 . V_125 ) ;
F_24 ( & V_2 -> V_126 , V_43 ) ;
V_119 -> V_127 = V_128 ;
if ( V_115 -> V_123 . V_124 & V_129 ) {
V_119 -> V_127 = V_130 ;
} else {
switch ( V_115 -> V_123 . V_125 ) {
case V_131 :
case V_132 :
case V_133 :
case V_134 :
V_119 -> V_127 = V_130 ;
break;
case V_135 :
case V_136 :
V_119 -> V_127 = V_137 ;
break;
}
}
if ( V_119 -> V_127 != V_128 ) {
memcpy ( & V_119 -> V_122 , & V_115 -> V_123 , V_121 ) ;
F_66 ( V_2 , V_138 ) ;
}
F_26 ( & V_2 -> V_126 , V_43 ) ;
}
void F_67 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
union V_114 * V_115 =
(union V_114 * ) V_22 -> V_139 -> V_140 . V_141 ;
T_1 V_117 = F_25 ( V_22 -> V_27 . V_142 . V_117 ) ;
union V_114 * V_143 =
(union V_114 * ) ( V_22 -> V_139 -> V_140 . V_141
+ V_117 ) ;
F_23 () ;
F_21 ( L_20 , V_117 ) ;
if ( V_117 > sizeof( struct V_144 )
|| ( V_117 & 3 ) != 0
|| V_117 == 0 ) {
F_51 ( V_104 ,
L_21 ,
V_22 , V_117 ) ;
F_48 ( L_22 , V_117 ) ;
F_28 () ;
V_143 = V_115 ;
}
while ( V_115 < V_143 ) {
T_4 V_116 ;
F_21 ( L_23 , V_115 ) ;
F_21 ( L_24 , & ( V_115 -> V_145 ) ) ;
V_117 = V_115 -> V_145 . V_146 ;
if ( V_117 > ( T_1 ) ( ( T_3 * ) V_143 - ( T_3 * ) V_115 )
|| ( V_117 & 3 ) != 0
|| V_117 == 0 ) {
F_51 ( V_92 ,
L_25 ,
V_115 , V_117 ) ;
F_48 ( L_26 , V_117 ) ;
F_28 () ;
break;
}
F_68 ( V_115 ) ;
F_69 ( V_2 , V_147 , V_115 ,
sizeof( union V_114 ) ) ;
switch ( V_115 -> V_145 . V_148 ) {
case V_149 :
if ( V_115 -> V_150 . V_151 & ( V_152
| V_153
| V_154
| V_155 ) ) {
F_51 ( V_156 ,
L_27 ,
V_115 -> V_150 . V_157 ,
V_115 -> V_150 . V_158 ,
V_115 -> V_150 . V_159 ) ;
}
break;
case V_160 :
F_51 ( V_156 ,
L_28 ,
V_115 -> V_123 . V_124 ,
V_115 -> V_123 . V_161 . V_162 . V_163 ,
V_115 -> V_123 . V_161 . V_162 . V_164 ,
V_115 -> V_123 . V_125 ) ;
V_116 = V_115 -> V_123 . V_161 . V_162 . V_163 ;
if ( V_116 < V_165 )
F_65 ( V_2 , V_115 , V_116 , V_117 ) ;
break;
case V_166 :
F_51 ( V_156 , L_29 ) ;
break;
default:
break;
}
V_115 = (union V_114 * ) ( ( T_3 * ) V_115 + V_117 ) ;
}
F_70 ( V_2 , V_22 ) ;
F_27 () ;
}
void F_60 ( struct V_1 * V_2 , bool V_167 )
{
struct V_168 V_115 ;
if ( V_167 )
V_115 . V_148 = V_169 ;
else
V_115 . V_148 = V_170 ;
V_115 . V_171 = V_172 ;
V_115 . V_173 = 0 ;
V_115 . V_146 = ( T_3 ) sizeof( struct V_168 ) ;
if ( V_167 )
F_48 ( L_30 ) ;
else
F_48 ( L_31 ) ;
F_69 ( V_2 , V_147 , & V_115 ,
sizeof( union V_114 ) ) ;
}
void V_79 ( struct V_1 * V_2 , struct V_21 * V_22 )
{}
static void F_71 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
T_3 V_174 , V_175 ;
V_174 = V_175 = V_22 -> V_27 . V_34 . V_176 ;
if ( V_174 > V_22 -> V_176 )
V_174 = V_22 -> V_176 ;
if ( V_174 ) {
if ( V_22 -> V_177 )
memcpy ( V_22 -> V_177 , V_22 -> V_178 , V_174 ) ;
else
V_22 -> V_177 = ( T_3 * ) V_22 -> V_178 ;
if ( V_175 > 0x0c ) {
T_3 * V_179 = ( T_3 * ) V_22 -> V_178 ;
F_23 () ;
if ( V_179 [ 0x0c ] == 0x3f && V_179 [ 0x0d ] == 0x0E ) {
F_21 ( L_32 ,
V_22 -> V_180 ) ;
F_72 ( V_2 , V_22 -> V_180 ,
V_181 ) ;
}
F_21 ( L_33 , V_179 [ 0x0c ] ) ;
F_21 ( L_34 , V_179 [ 0x0d ] ) ;
F_27 () ;
}
}
V_22 -> V_176 = V_174 ;
}
void F_73 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
if ( V_22 -> V_55 -> V_56 . V_58 == V_182
&& V_22 -> V_55 -> V_183 . V_184 == V_185 )
F_44 ( V_62 , & V_2 -> V_43 ) ;
if ( V_22 -> V_77 ) {
(* V_22 -> V_77 )( V_2 , V_22 ) ;
if ( V_22 -> V_25 == V_68 ) {
F_74 ( V_2 , V_22 ) ;
return;
}
}
if ( F_16 ( V_22 -> V_55 -> V_56 . V_58 == V_59 )
&& F_17 ( V_22 -> V_25 != V_26 ) ) {
F_71 ( V_2 , V_22 ) ;
F_75 ( V_2 , V_22 ) ;
}
(* V_22 -> V_78 )( V_2 , V_22 ) ;
}
