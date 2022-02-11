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
if ( V_17 -> V_119 . V_120 )
F_9 ( V_117 , & V_17 -> V_20 ) ;
else {
F_48 ( V_117 , & V_17 -> V_20 ) ;
F_49 ( & V_17 -> V_121 ) ;
}
}
int F_50 ( struct V_122 * V_123 , T_3 * V_124 ,
const T_2 * V_125 , const T_2 * V_126 )
{
if ( F_51 ( V_125 ) ) {
* V_124 |= F_52 ( V_127 ) ;
memcpy ( V_123 -> V_128 , V_125 , V_80 ) ;
memcpy ( V_123 -> V_129 , V_126 , V_80 ) ;
memcpy ( V_123 -> V_130 , V_126 , V_80 ) ;
return 24 ;
} else {
* V_124 |= F_52 ( V_127 | V_131 ) ;
memset ( V_123 -> V_128 , 0 , V_80 ) ;
memcpy ( V_123 -> V_129 , V_126 , V_80 ) ;
memcpy ( V_123 -> V_130 , V_125 , V_80 ) ;
memcpy ( V_123 -> V_132 , V_126 , V_80 ) ;
return 30 ;
}
}
int F_53 ( struct V_70 * V_133 ,
struct V_12 * V_13 , char * V_134 ,
char * V_135 )
{
int V_136 = 0 ;
F_54 ( ! V_134 && V_135 ) ;
memset ( V_133 , 0 , sizeof( * V_133 ) ) ;
V_133 -> V_137 = V_13 -> V_3 . V_18 . V_119 . V_138 ;
F_55 ( F_56 ( V_13 -> V_3 . V_18 . V_139 ) , & V_133 -> V_72 ) ;
V_13 -> V_3 . V_18 . V_139 ++ ;
if ( V_134 && ! V_135 ) {
V_133 -> V_140 |= V_141 ;
V_136 += V_80 ;
memcpy ( V_133 -> V_142 , V_134 , V_80 ) ;
} else if ( V_134 && V_135 ) {
V_133 -> V_140 |= V_143 ;
V_136 += 2 * V_80 ;
memcpy ( V_133 -> V_142 , V_134 , V_80 ) ;
memcpy ( V_133 -> V_144 , V_135 , V_80 ) ;
}
return 6 + V_136 ;
}
static void F_57 ( struct V_12 * V_13 ,
struct V_16 * V_17 )
{
bool V_56 ;
#ifdef F_58
F_59 ( V_145 L_2 ,
V_13 -> V_146 ) ;
#endif
F_60 ( V_13 , V_147 ) ;
F_61 ( V_13 ) ;
V_56 = F_16 ( V_13 ) ;
if ( V_56 != V_13 -> V_3 . V_18 . V_57 )
F_62 ( V_13 , V_148 ) ;
F_63 ( & V_17 -> V_149 ,
F_64 ( V_75 + V_150 ) ) ;
}
static void F_65 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
F_66 ( V_13 ) ;
F_63 ( & V_17 -> V_121 ,
F_64 ( F_67 (
V_17 -> V_119 . V_151 ) ) ) ;
}
void F_68 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
if ( F_49 ( & V_17 -> V_149 ) )
F_9 ( V_22 , & V_17 -> V_23 ) ;
if ( F_49 ( & V_17 -> V_152 ) )
F_9 ( V_116 , & V_17 -> V_23 ) ;
if ( F_49 ( & V_17 -> V_121 ) )
F_9 ( V_118 , & V_17 -> V_23 ) ;
}
void F_69 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
if ( F_70 ( V_22 , & V_17 -> V_23 ) )
F_71 ( & V_17 -> V_149 ) ;
if ( F_70 ( V_116 , & V_17 -> V_23 ) )
F_71 ( & V_17 -> V_152 ) ;
if ( F_70 ( V_118 , & V_17 -> V_23 ) )
F_71 ( & V_17 -> V_121 ) ;
F_47 ( V_17 ) ;
}
void F_72 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_14 * V_15 = V_13 -> V_15 ;
V_15 -> V_153 ++ ;
F_73 ( & V_15 -> V_154 ) ;
F_74 ( V_15 ) ;
V_17 -> V_39 = 0 ;
V_17 -> V_43 = 0 ;
V_17 -> V_155 = F_75 ( V_17 -> V_41 ) ;
V_17 -> V_91 = false ;
V_17 -> V_156 = 0 ;
F_9 ( V_19 , & V_17 -> V_20 ) ;
F_47 ( V_17 ) ;
F_10 ( & V_15 -> V_24 , & V_13 -> V_25 ) ;
V_13 -> V_48 . V_49 . V_115 =
V_17 -> V_119 . V_157 ;
V_13 -> V_48 . V_49 . V_158 = V_159 ;
V_13 -> V_48 . V_49 . V_28 =
F_76 ( V_13 -> V_15 ,
V_13 -> V_15 -> V_24 . V_102 . V_103 -> V_47 ) ;
F_62 ( V_13 , V_148 |
V_160 |
V_161 |
V_162 |
V_163 ) ;
}
void F_77 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
V_17 -> V_32 = 0 ;
F_62 ( V_13 , V_160 ) ;
F_78 ( V_15 , NULL ) ;
F_49 ( & V_13 -> V_3 . V_18 . V_149 ) ;
F_49 ( & V_13 -> V_3 . V_18 . V_121 ) ;
F_79 ( & V_13 -> V_25 ) ;
V_15 -> V_153 -- ;
F_80 ( & V_15 -> V_154 ) ;
F_74 ( V_15 ) ;
}
static void F_81 ( struct V_12 * V_13 ,
T_4 V_164 ,
struct V_1 * V_2 ,
T_5 V_95 ,
struct V_165 * V_166 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_26 V_167 ;
struct V_111 * V_103 ;
T_5 V_168 ;
int V_169 ;
enum V_170 V_47 = V_166 -> V_47 ;
if ( V_164 == V_171 &&
! F_28 ( V_2 -> V_172 , V_13 -> V_48 . V_173 ) )
return;
V_168 = ( T_2 * ) V_2 -> V_3 . V_174 . V_175 - ( T_2 * ) V_2 ;
if ( V_168 > V_95 )
return;
F_82 ( V_2 -> V_3 . V_174 . V_175 , V_95 - V_168 ,
& V_167 ) ;
if ( V_167 . V_176 && V_13 -> V_3 . V_18 . V_177 == V_178 )
return;
if ( V_167 . V_179 && V_167 . V_180 == 1 )
V_169 = F_83 ( V_167 . V_179 [ 0 ] , V_47 ) ;
else
V_169 = V_166 -> V_169 ;
V_103 = F_84 ( V_15 -> V_24 . V_100 , V_169 ) ;
if ( ! V_103 || V_103 -> V_140 & V_181 )
return;
if ( V_167 . V_33 && V_167 . V_35 &&
F_11 ( V_13 , & V_167 ) )
F_85 ( V_13 , V_2 -> V_69 , & V_167 ) ;
if ( V_17 -> V_155 )
V_17 -> V_155 -> V_182 ( V_13 ,
V_164 , V_2 , & V_167 , V_166 ) ;
}
static void F_86 ( struct V_12 * V_13 ,
struct V_1 * V_2 ,
T_5 V_95 ,
struct V_165 * V_166 )
{
switch ( V_2 -> V_3 . V_4 . V_183 ) {
case V_184 :
switch ( V_2 -> V_3 . V_4 . V_3 . V_185 . V_6 ) {
case V_186 :
case V_187 :
case V_188 :
F_87 ( V_13 , V_2 , V_95 , V_166 ) ;
break;
}
break;
case V_189 :
if ( F_1 ( V_2 ) )
F_88 ( V_13 , V_2 , V_95 ) ;
break;
}
}
void F_89 ( struct V_12 * V_13 ,
struct V_81 * V_82 )
{
struct V_165 * V_166 ;
struct V_1 * V_2 ;
T_4 V_164 ;
V_166 = F_90 ( V_82 ) ;
V_2 = (struct V_1 * ) V_82 -> V_11 ;
V_164 = F_91 ( V_2 -> V_190 ) & V_191 ;
switch ( V_164 ) {
case V_171 :
case V_192 :
F_81 ( V_13 , V_164 , V_2 , V_82 -> V_95 ,
V_166 ) ;
break;
case V_193 :
F_86 ( V_13 , V_2 , V_82 -> V_95 , V_166 ) ;
break;
}
}
void F_92 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
if ( V_17 -> V_194 &&
F_27 ( V_75 ,
V_17 -> V_195 + F_93 ( V_17 -> V_119 . V_196 ) ) )
F_94 ( V_13 ) ;
if ( F_70 ( V_197 , & V_17 -> V_20 ) )
F_95 () ;
if ( F_70 ( V_198 , & V_17 -> V_20 ) )
F_96 () ;
if ( F_70 ( V_19 , & V_17 -> V_20 ) )
F_57 ( V_13 , V_17 ) ;
if ( F_70 ( V_117 , & V_17 -> V_20 ) )
F_65 ( V_13 ) ;
if ( F_70 ( V_199 , & V_17 -> V_20 ) )
F_97 ( V_13 ) ;
}
void F_98 ( struct V_14 * V_15 )
{
struct V_12 * V_13 ;
F_99 () ;
F_100 (sdata, &local->interfaces, list)
if ( F_101 ( & V_13 -> V_48 ) )
F_10 ( & V_15 -> V_24 , & V_13 -> V_25 ) ;
F_102 () ;
}
void F_103 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
F_104 ( & V_17 -> V_149 ,
F_8 ,
( unsigned long ) V_13 ) ;
V_17 -> V_57 = true ;
V_17 -> V_200 = 0 ;
V_17 -> V_201 = 0 ;
V_17 -> V_202 = 0 ;
F_105 ( & V_17 -> V_203 , 0 ) ;
F_17 ( V_13 ) ;
V_17 -> V_195 = V_75 ;
V_17 -> V_204 = V_75 ;
if ( ! V_8 )
F_2 () ;
F_104 ( & V_17 -> V_152 ,
F_45 ,
( unsigned long ) V_13 ) ;
F_104 ( & V_17 -> V_121 ,
F_46 ,
( unsigned long ) V_13 ) ;
F_19 ( & V_17 -> V_205 . V_66 ) ;
F_106 ( & V_17 -> V_206 ) ;
F_106 ( & V_17 -> V_207 ) ;
}
