bool F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 . V_4 . V_3 . V_5 . V_6 ==
V_7 ) ;
}
bool F_1 ( struct V_1 * V_2 )
{ return false ; }
void F_2 ( void )
{
F_3 () ;
V_8 = 1 ;
V_9 = F_4 ( L_1 , sizeof( struct V_10 ) ,
0 , 0 , NULL ) ;
}
void F_5 ( void )
{
F_6 () ;
F_7 ( V_9 ) ;
}
static void F_8 ( unsigned long V_11 )
{
struct V_12 * V_13 = ( void * ) V_11 ;
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
F_9 ( V_19 , & V_17 -> V_20 ) ;
if ( V_15 -> V_21 ) {
F_9 ( V_22 , & V_17 -> V_23 ) ;
return;
}
F_10 ( & V_15 -> V_24 , & V_13 -> V_25 ) ;
}
bool F_11 ( struct V_12 * V_13 ,
struct V_26 * V_27 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_14 * V_15 = V_13 -> V_15 ;
T_1 V_28 = 0 ;
enum V_29 V_30 = V_31 ;
if ( ! ( V_17 -> V_32 == V_27 -> V_32 &&
memcmp ( V_17 -> V_33 , V_27 -> V_33 , V_27 -> V_32 ) == 0 &&
( V_17 -> V_34 == V_27 -> V_35 -> V_36 ) &&
( V_17 -> V_37 == V_27 -> V_35 -> V_38 ) &&
( V_17 -> V_39 == V_27 -> V_35 -> V_40 ) &&
( V_17 -> V_41 == V_27 -> V_35 -> V_42 ) &&
( V_17 -> V_43 == V_27 -> V_35 -> V_44 ) ) )
goto V_45;
F_12 ( V_15 , V_27 , V_15 -> V_46 -> V_47 ,
& V_28 ) ;
if ( V_13 -> V_48 . V_49 . V_28 != V_28 )
goto V_45;
if ( V_27 -> V_50 )
V_30 =
F_13 ( V_27 -> V_50 ) ;
if ( V_27 -> V_50 &&
( V_15 -> V_51 == V_52 ||
V_15 -> V_51 == V_53 ) &&
( V_30 == V_52 ||
V_30 == V_53 ) &&
V_15 -> V_51 != V_30 )
goto V_45;
return true ;
V_45:
return false ;
}
bool F_14 ( struct V_26 * V_27 )
{
return ( V_27 -> V_35 -> V_54 &
V_55 ) != 0 ;
}
void F_15 ( struct V_12 * V_13 )
{
bool V_56 ;
V_56 = F_16 ( V_13 ) ;
if ( V_56 != V_13 -> V_3 . V_18 . V_57 )
F_8 ( ( unsigned long ) V_13 ) ;
}
int F_17 ( struct V_12 * V_13 )
{
int V_58 ;
V_13 -> V_3 . V_18 . V_59 = F_18 ( sizeof( struct V_60 ) , V_61 ) ;
if ( ! V_13 -> V_3 . V_18 . V_59 )
return - V_62 ;
V_13 -> V_3 . V_18 . V_59 -> V_63 = V_64 - 1 ;
for ( V_58 = 0 ; V_58 < V_64 ; V_58 ++ )
F_19 ( & V_13 -> V_3 . V_18 . V_59 -> V_65 [ V_58 ] . V_66 ) ;
return 0 ;
}
void F_20 ( struct V_12 * V_13 )
{
struct V_60 * V_59 = V_13 -> V_3 . V_18 . V_59 ;
struct V_10 * V_67 , * V_68 ;
int V_58 ;
if ( ! V_13 -> V_3 . V_18 . V_59 )
return;
for ( V_58 = 0 ; V_58 < V_64 ; V_58 ++ )
F_21 (p, n, &rmc->bucket[i].list, list) {
F_22 ( & V_67 -> V_66 ) ;
F_23 ( V_9 , V_67 ) ;
}
F_24 ( V_59 ) ;
V_13 -> V_3 . V_18 . V_59 = NULL ;
}
int F_25 ( T_2 * V_69 , struct V_70 * V_71 ,
struct V_12 * V_13 )
{
struct V_60 * V_59 = V_13 -> V_3 . V_18 . V_59 ;
T_1 V_72 = 0 ;
int V_73 = 0 ;
T_2 V_74 ;
struct V_10 * V_67 , * V_68 ;
memcpy ( & V_72 , & V_71 -> V_72 , sizeof( V_71 -> V_72 ) ) ;
V_74 = F_26 ( V_71 -> V_72 ) & V_59 -> V_63 ;
F_21 (p, n, &rmc->bucket[idx].list, list) {
++ V_73 ;
if ( F_27 ( V_75 , V_67 -> V_76 ) ||
( V_73 == V_77 ) ) {
F_22 ( & V_67 -> V_66 ) ;
F_23 ( V_9 , V_67 ) ;
-- V_73 ;
} else if ( ( V_72 == V_67 -> V_72 ) &&
( F_28 ( V_69 , V_67 -> V_69 ) ) )
return - 1 ;
}
V_67 = F_29 ( V_9 , V_78 ) ;
if ( ! V_67 )
return 0 ;
V_67 -> V_72 = V_72 ;
V_67 -> V_76 = V_75 + V_79 ;
memcpy ( V_67 -> V_69 , V_69 , V_80 ) ;
F_30 ( & V_67 -> V_66 , & V_59 -> V_65 [ V_74 ] . V_66 ) ;
return 0 ;
}
int
F_31 ( struct V_81 * V_82 , struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 * V_83 , V_84 ;
T_2 V_85 = sizeof( struct V_86 ) ;
if ( F_32 ( V_82 ) < 2 + V_85 )
return - V_62 ;
V_83 = F_33 ( V_82 , 2 + V_85 ) ;
* V_83 ++ = V_87 ;
* V_83 ++ = V_85 ;
* V_83 ++ = V_17 -> V_34 ;
* V_83 ++ = V_17 -> V_37 ;
* V_83 ++ = V_17 -> V_39 ;
* V_83 ++ = V_17 -> V_41 ;
* V_83 ++ = V_17 -> V_43 ;
V_84 = F_34 ( & V_17 -> V_88 . V_89 ) ;
V_84 = ( V_84 > 15 ) ? 15 : V_84 ;
* V_83 ++ = V_84 << 1 ;
V_17 -> V_57 = F_16 ( V_13 ) ;
* V_83 = V_90 ;
* V_83 |= V_17 -> V_57 ?
V_55 : 0x00 ;
* V_83 ++ |= V_17 -> V_91 ?
V_92 : 0x00 ;
* V_83 ++ = 0x00 ;
return 0 ;
}
int
F_35 ( struct V_81 * V_82 , struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 * V_83 ;
if ( F_32 ( V_82 ) < 2 + V_17 -> V_32 )
return - V_62 ;
V_83 = F_33 ( V_82 , 2 + V_17 -> V_32 ) ;
* V_83 ++ = V_93 ;
* V_83 ++ = V_17 -> V_32 ;
if ( V_17 -> V_32 )
memcpy ( V_83 , V_17 -> V_33 , V_17 -> V_32 ) ;
return 0 ;
}
int
F_36 ( struct V_81 * V_82 , struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 V_94 , V_95 ;
const T_2 * V_11 ;
if ( ! V_17 -> V_27 || ! V_17 -> V_96 )
return 0 ;
V_94 = F_37 ( V_17 -> V_27 , V_17 -> V_96 , 0 ) ;
if ( V_94 ) {
V_95 = V_17 -> V_96 - V_94 ;
V_11 = V_17 -> V_27 + V_94 ;
if ( F_32 ( V_82 ) < V_95 )
return - V_62 ;
memcpy ( F_33 ( V_82 , V_95 ) , V_11 , V_95 ) ;
}
return 0 ;
}
int
F_38 ( struct V_81 * V_82 , struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 V_95 = 0 ;
const T_2 * V_11 ;
if ( ! V_17 -> V_27 || ! V_17 -> V_96 )
return 0 ;
V_11 = V_17 -> V_27 ;
while ( V_11 < V_17 -> V_27 + V_17 -> V_96 ) {
if ( * V_11 == V_97 ) {
V_95 = V_11 [ 1 ] + 2 ;
break;
}
V_11 ++ ;
}
if ( V_95 ) {
if ( F_32 ( V_82 ) < V_95 )
return - V_62 ;
memcpy ( F_33 ( V_82 , V_95 ) , V_11 , V_95 ) ;
}
return 0 ;
}
int F_39 ( struct V_81 * V_82 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_98 * V_99 ;
T_2 * V_83 ;
if ( F_32 ( V_82 ) < 3 )
return - V_62 ;
V_99 = V_15 -> V_24 . V_100 -> V_101 [ V_15 -> V_24 . V_102 . V_103 -> V_47 ] ;
if ( V_99 -> V_47 == V_104 ) {
V_83 = F_33 ( V_82 , 2 + 1 ) ;
* V_83 ++ = V_105 ;
* V_83 ++ = 1 ;
* V_83 ++ = F_40 ( V_15 -> V_24 . V_102 . V_103 -> V_106 ) ;
}
return 0 ;
}
int F_41 ( struct V_81 * V_82 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_98 * V_99 ;
T_2 * V_83 ;
V_99 = V_15 -> V_24 . V_100 -> V_101 [ V_15 -> V_46 -> V_47 ] ;
if ( ! V_99 -> V_107 . V_108 ||
V_15 -> V_51 == V_31 )
return 0 ;
if ( F_32 ( V_82 ) < 2 + sizeof( struct V_109 ) )
return - V_62 ;
V_83 = F_33 ( V_82 , 2 + sizeof( struct V_109 ) ) ;
F_42 ( V_83 , & V_99 -> V_107 , V_99 -> V_107 . V_110 ) ;
return 0 ;
}
int F_43 ( struct V_81 * V_82 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_111 * V_103 = V_15 -> V_46 ;
enum V_29 V_112 = V_15 -> V_51 ;
struct V_98 * V_99 =
V_15 -> V_24 . V_100 -> V_101 [ V_103 -> V_47 ] ;
struct V_113 * V_107 = & V_99 -> V_107 ;
T_2 * V_83 ;
if ( ! V_107 -> V_108 || V_112 == V_31 )
return 0 ;
if ( F_32 ( V_82 ) < 2 + sizeof( struct V_114 ) )
return - V_62 ;
V_83 = F_33 ( V_82 , 2 + sizeof( struct V_114 ) ) ;
F_44 ( V_83 , V_107 , V_103 , V_112 ,
V_13 -> V_48 . V_49 . V_115 ) ;
return 0 ;
}
static void F_45 ( unsigned long V_11 )
{
struct V_12 * V_13 =
(struct V_12 * ) V_11 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_14 * V_15 = V_13 -> V_15 ;
if ( V_15 -> V_21 ) {
F_9 ( V_116 , & V_17 -> V_23 ) ;
return;
}
F_10 ( & V_15 -> V_24 , & V_13 -> V_25 ) ;
}
static void F_46 ( unsigned long V_11 )
{
struct V_12 * V_13 =
(struct V_12 * ) V_11 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_14 * V_15 = V_13 -> V_15 ;
F_9 ( V_117 , & V_17 -> V_20 ) ;
if ( V_15 -> V_21 ) {
F_9 ( V_118 , & V_17 -> V_23 ) ;
return;
}
F_10 ( & V_15 -> V_24 , & V_13 -> V_25 ) ;
}
void F_47 ( struct V_16 * V_17 )
{
if ( V_17 -> V_119 . V_120 > V_121 )
F_9 ( V_117 , & V_17 -> V_20 ) ;
else {
F_48 ( V_117 , & V_17 -> V_20 ) ;
F_49 ( & V_17 -> V_122 ) ;
}
}
int F_50 ( struct V_123 * V_124 , T_3 * V_125 ,
const T_2 * V_126 , const T_2 * V_127 )
{
if ( F_51 ( V_126 ) ) {
* V_125 |= F_52 ( V_128 ) ;
memcpy ( V_124 -> V_129 , V_126 , V_80 ) ;
memcpy ( V_124 -> V_130 , V_127 , V_80 ) ;
memcpy ( V_124 -> V_131 , V_127 , V_80 ) ;
return 24 ;
} else {
* V_125 |= F_52 ( V_128 | V_132 ) ;
memset ( V_124 -> V_129 , 0 , V_80 ) ;
memcpy ( V_124 -> V_130 , V_127 , V_80 ) ;
memcpy ( V_124 -> V_131 , V_126 , V_80 ) ;
memcpy ( V_124 -> V_133 , V_127 , V_80 ) ;
return 30 ;
}
}
int F_53 ( struct V_70 * V_134 ,
struct V_12 * V_13 , char * V_135 ,
char * V_136 )
{
int V_137 = 0 ;
F_54 ( ! V_135 && V_136 ) ;
memset ( V_134 , 0 , sizeof( * V_134 ) ) ;
V_134 -> V_138 = V_13 -> V_3 . V_18 . V_119 . V_139 ;
F_55 ( F_56 ( V_13 -> V_3 . V_18 . V_140 ) , & V_134 -> V_72 ) ;
V_13 -> V_3 . V_18 . V_140 ++ ;
if ( V_135 && ! V_136 ) {
V_134 -> V_141 |= V_142 ;
V_137 += V_80 ;
memcpy ( V_134 -> V_143 , V_135 , V_80 ) ;
} else if ( V_135 && V_136 ) {
V_134 -> V_141 |= V_144 ;
V_137 += 2 * V_80 ;
memcpy ( V_134 -> V_143 , V_135 , V_80 ) ;
memcpy ( V_134 -> V_145 , V_136 , V_80 ) ;
}
return 6 + V_137 ;
}
static void F_57 ( struct V_12 * V_13 ,
struct V_16 * V_17 )
{
bool V_56 ;
F_58 ( V_13 , V_146 ) ;
F_59 ( V_13 ) ;
V_56 = F_16 ( V_13 ) ;
if ( V_56 != V_13 -> V_3 . V_18 . V_57 )
F_60 ( V_13 , V_147 ) ;
F_61 ( & V_17 -> V_148 ,
F_62 ( V_75 + V_149 ) ) ;
}
static void F_63 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 V_150 ;
F_64 ( V_13 ) ;
if ( V_17 -> V_119 . V_120 == V_151 )
V_150 = V_17 -> V_119 . V_152 ;
else
V_150 = V_17 -> V_119 . V_153 ;
F_61 ( & V_17 -> V_122 ,
F_62 ( F_65 ( V_150 ) ) ) ;
}
void F_66 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
if ( F_49 ( & V_17 -> V_148 ) )
F_9 ( V_22 , & V_17 -> V_23 ) ;
if ( F_49 ( & V_17 -> V_154 ) )
F_9 ( V_116 , & V_17 -> V_23 ) ;
if ( F_49 ( & V_17 -> V_122 ) )
F_9 ( V_118 , & V_17 -> V_23 ) ;
}
void F_67 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
if ( F_68 ( V_22 , & V_17 -> V_23 ) )
F_69 ( & V_17 -> V_148 ) ;
if ( F_68 ( V_116 , & V_17 -> V_23 ) )
F_69 ( & V_17 -> V_154 ) ;
if ( F_68 ( V_118 , & V_17 -> V_23 ) )
F_69 ( & V_17 -> V_122 ) ;
F_47 ( V_17 ) ;
}
void F_70 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_14 * V_15 = V_13 -> V_15 ;
V_15 -> V_155 ++ ;
F_71 ( & V_15 -> V_156 ) ;
F_72 ( V_15 ) ;
V_17 -> V_39 = 0 ;
V_17 -> V_43 = 0 ;
V_17 -> V_157 = F_73 ( V_17 -> V_41 ) ;
V_17 -> V_91 = false ;
V_17 -> V_158 = 0 ;
F_9 ( V_19 , & V_17 -> V_20 ) ;
F_47 ( V_17 ) ;
F_10 ( & V_15 -> V_24 , & V_13 -> V_25 ) ;
V_13 -> V_48 . V_49 . V_115 =
V_17 -> V_119 . V_159 ;
V_13 -> V_48 . V_49 . V_160 = V_161 ;
V_13 -> V_48 . V_49 . V_28 =
F_74 ( V_13 -> V_15 ,
V_13 -> V_15 -> V_24 . V_102 . V_103 -> V_47 ) ;
F_60 ( V_13 , V_147 |
V_162 |
V_163 |
V_164 |
V_165 ) ;
}
void F_75 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
V_17 -> V_32 = 0 ;
F_60 ( V_13 , V_162 ) ;
F_76 ( V_15 , NULL ) ;
F_49 ( & V_13 -> V_3 . V_18 . V_148 ) ;
F_49 ( & V_13 -> V_3 . V_18 . V_122 ) ;
F_49 ( & V_13 -> V_3 . V_18 . V_154 ) ;
F_77 ( & V_13 -> V_25 ) ;
V_15 -> V_155 -- ;
F_78 ( & V_15 -> V_156 ) ;
F_72 ( V_15 ) ;
V_13 -> V_3 . V_18 . V_23 = 0 ;
}
static void F_79 ( struct V_12 * V_13 ,
T_4 V_166 ,
struct V_1 * V_2 ,
T_5 V_95 ,
struct V_167 * V_168 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_26 V_169 ;
struct V_111 * V_103 ;
T_5 V_170 ;
int V_171 ;
enum V_172 V_47 = V_168 -> V_47 ;
if ( V_166 == V_173 &&
! F_28 ( V_2 -> V_174 , V_13 -> V_48 . V_175 ) )
return;
V_170 = ( T_2 * ) V_2 -> V_3 . V_176 . V_177 - ( T_2 * ) V_2 ;
if ( V_170 > V_95 )
return;
F_80 ( V_2 -> V_3 . V_176 . V_177 , V_95 - V_170 ,
& V_169 ) ;
if ( V_169 . V_178 && V_13 -> V_3 . V_18 . V_179 == V_180 )
return;
if ( V_169 . V_181 && V_169 . V_182 == 1 )
V_171 = F_81 ( V_169 . V_181 [ 0 ] , V_47 ) ;
else
V_171 = V_168 -> V_171 ;
V_103 = F_82 ( V_15 -> V_24 . V_100 , V_171 ) ;
if ( ! V_103 || V_103 -> V_141 & V_183 )
return;
if ( V_169 . V_33 && V_169 . V_35 &&
F_11 ( V_13 , & V_169 ) )
F_83 ( V_13 , V_2 -> V_69 , & V_169 ) ;
if ( V_17 -> V_157 )
V_17 -> V_157 -> V_184 ( V_13 ,
V_166 , V_2 , & V_169 , V_168 ) ;
}
static void F_84 ( struct V_12 * V_13 ,
struct V_1 * V_2 ,
T_5 V_95 ,
struct V_167 * V_168 )
{
switch ( V_2 -> V_3 . V_4 . V_185 ) {
case V_186 :
switch ( V_2 -> V_3 . V_4 . V_3 . V_187 . V_6 ) {
case V_188 :
case V_189 :
case V_190 :
F_85 ( V_13 , V_2 , V_95 , V_168 ) ;
break;
}
break;
case V_191 :
if ( F_1 ( V_2 ) )
F_86 ( V_13 , V_2 , V_95 ) ;
break;
}
}
void F_87 ( struct V_12 * V_13 ,
struct V_81 * V_82 )
{
struct V_167 * V_168 ;
struct V_1 * V_2 ;
T_4 V_166 ;
V_168 = F_88 ( V_82 ) ;
V_2 = (struct V_1 * ) V_82 -> V_11 ;
V_166 = F_89 ( V_2 -> V_192 ) & V_193 ;
switch ( V_166 ) {
case V_173 :
case V_194 :
F_79 ( V_13 , V_166 , V_2 , V_82 -> V_95 ,
V_168 ) ;
break;
case V_195 :
F_84 ( V_13 , V_2 , V_82 -> V_95 , V_168 ) ;
break;
}
}
void F_90 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
if ( V_17 -> V_196 &&
F_27 ( V_75 ,
V_17 -> V_197 + F_91 ( V_17 -> V_119 . V_198 ) ) )
F_92 ( V_13 ) ;
if ( F_68 ( V_199 , & V_17 -> V_20 ) )
F_93 () ;
if ( F_68 ( V_200 , & V_17 -> V_20 ) )
F_94 () ;
if ( F_68 ( V_19 , & V_17 -> V_20 ) )
F_57 ( V_13 , V_17 ) ;
if ( F_68 ( V_117 , & V_17 -> V_20 ) )
F_63 ( V_13 ) ;
if ( F_68 ( V_201 , & V_17 -> V_20 ) )
F_95 ( V_13 ) ;
}
void F_96 ( struct V_14 * V_15 )
{
struct V_12 * V_13 ;
F_97 () ;
F_98 (sdata, &local->interfaces, list)
if ( F_99 ( & V_13 -> V_48 ) )
F_10 ( & V_15 -> V_24 , & V_13 -> V_25 ) ;
F_100 () ;
}
void F_101 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
F_102 ( & V_17 -> V_148 ,
F_8 ,
( unsigned long ) V_13 ) ;
V_17 -> V_57 = true ;
V_17 -> V_202 = 0 ;
V_17 -> V_203 = 0 ;
V_17 -> V_204 = 0 ;
F_103 ( & V_17 -> V_205 , 0 ) ;
F_17 ( V_13 ) ;
V_17 -> V_197 = V_75 ;
V_17 -> V_206 = V_75 ;
if ( ! V_8 )
F_2 () ;
F_102 ( & V_17 -> V_154 ,
F_45 ,
( unsigned long ) V_13 ) ;
F_102 ( & V_17 -> V_122 ,
F_46 ,
( unsigned long ) V_13 ) ;
F_19 ( & V_17 -> V_207 . V_66 ) ;
F_104 ( & V_17 -> V_208 ) ;
F_104 ( & V_17 -> V_209 ) ;
}
