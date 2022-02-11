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
( V_13 -> V_48 . V_49 . V_51 == V_52 ||
V_13 -> V_48 . V_49 . V_51 == V_53 ) &&
( V_30 == V_52 ||
V_30 == V_53 ) &&
V_13 -> V_48 . V_49 . V_51 != V_30 )
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
T_1 F_15 ( struct V_12 * V_13 )
{
bool V_56 ;
T_1 V_57 = 0 ;
V_56 = F_16 ( V_13 ) ;
if ( V_56 != V_13 -> V_3 . V_18 . V_58 ) {
V_13 -> V_3 . V_18 . V_58 = V_56 ;
V_57 = V_59 ;
}
return V_57 ;
}
int F_17 ( struct V_12 * V_13 )
{
int V_60 ;
V_13 -> V_3 . V_18 . V_61 = F_18 ( sizeof( struct V_62 ) , V_63 ) ;
if ( ! V_13 -> V_3 . V_18 . V_61 )
return - V_64 ;
V_13 -> V_3 . V_18 . V_61 -> V_65 = V_66 - 1 ;
for ( V_60 = 0 ; V_60 < V_66 ; V_60 ++ )
F_19 ( & V_13 -> V_3 . V_18 . V_61 -> V_67 [ V_60 ] . V_68 ) ;
return 0 ;
}
void F_20 ( struct V_12 * V_13 )
{
struct V_62 * V_61 = V_13 -> V_3 . V_18 . V_61 ;
struct V_10 * V_69 , * V_70 ;
int V_60 ;
if ( ! V_13 -> V_3 . V_18 . V_61 )
return;
for ( V_60 = 0 ; V_60 < V_66 ; V_60 ++ )
F_21 (p, n, &rmc->bucket[i].list, list) {
F_22 ( & V_69 -> V_68 ) ;
F_23 ( V_9 , V_69 ) ;
}
F_24 ( V_61 ) ;
V_13 -> V_3 . V_18 . V_61 = NULL ;
}
int F_25 ( T_2 * V_71 , struct V_72 * V_73 ,
struct V_12 * V_13 )
{
struct V_62 * V_61 = V_13 -> V_3 . V_18 . V_61 ;
T_1 V_74 = 0 ;
int V_75 = 0 ;
T_2 V_76 ;
struct V_10 * V_69 , * V_70 ;
memcpy ( & V_74 , & V_73 -> V_74 , sizeof( V_73 -> V_74 ) ) ;
V_76 = F_26 ( V_73 -> V_74 ) & V_61 -> V_65 ;
F_21 (p, n, &rmc->bucket[idx].list, list) {
++ V_75 ;
if ( F_27 ( V_77 , V_69 -> V_78 ) ||
( V_75 == V_79 ) ) {
F_22 ( & V_69 -> V_68 ) ;
F_23 ( V_9 , V_69 ) ;
-- V_75 ;
} else if ( ( V_74 == V_69 -> V_74 ) &&
( F_28 ( V_71 , V_69 -> V_71 ) ) )
return - 1 ;
}
V_69 = F_29 ( V_9 , V_80 ) ;
if ( ! V_69 )
return 0 ;
V_69 -> V_74 = V_74 ;
V_69 -> V_78 = V_77 + V_81 ;
memcpy ( V_69 -> V_71 , V_71 , V_82 ) ;
F_30 ( & V_69 -> V_68 , & V_61 -> V_67 [ V_76 ] . V_68 ) ;
return 0 ;
}
int
F_31 ( struct V_83 * V_84 , struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 * V_85 , V_86 ;
T_2 V_87 = sizeof( struct V_88 ) ;
if ( F_32 ( V_84 ) < 2 + V_87 )
return - V_64 ;
V_85 = F_33 ( V_84 , 2 + V_87 ) ;
* V_85 ++ = V_89 ;
* V_85 ++ = V_87 ;
* V_85 ++ = V_17 -> V_34 ;
* V_85 ++ = V_17 -> V_37 ;
* V_85 ++ = V_17 -> V_39 ;
* V_85 ++ = V_17 -> V_41 ;
* V_85 ++ = V_17 -> V_43 ;
V_86 = F_34 ( & V_17 -> V_90 . V_91 ) ;
V_86 = ( V_86 > 15 ) ? 15 : V_86 ;
* V_85 ++ = V_86 << 1 ;
* V_85 = V_92 ;
* V_85 |= V_17 -> V_58 ?
V_55 : 0x00 ;
* V_85 ++ |= V_17 -> V_93 ?
V_94 : 0x00 ;
* V_85 ++ = 0x00 ;
return 0 ;
}
int
F_35 ( struct V_83 * V_84 , struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 * V_85 ;
if ( F_32 ( V_84 ) < 2 + V_17 -> V_32 )
return - V_64 ;
V_85 = F_33 ( V_84 , 2 + V_17 -> V_32 ) ;
* V_85 ++ = V_95 ;
* V_85 ++ = V_17 -> V_32 ;
if ( V_17 -> V_32 )
memcpy ( V_85 , V_17 -> V_33 , V_17 -> V_32 ) ;
return 0 ;
}
int
F_36 ( struct V_83 * V_84 , struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 V_96 , V_97 ;
const T_2 * V_11 ;
if ( ! V_17 -> V_27 || ! V_17 -> V_98 )
return 0 ;
V_96 = F_37 ( V_17 -> V_27 , V_17 -> V_98 , 0 ) ;
if ( V_96 ) {
V_97 = V_17 -> V_98 - V_96 ;
V_11 = V_17 -> V_27 + V_96 ;
if ( F_32 ( V_84 ) < V_97 )
return - V_64 ;
memcpy ( F_33 ( V_84 , V_97 ) , V_11 , V_97 ) ;
}
return 0 ;
}
int
F_38 ( struct V_83 * V_84 , struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 V_97 = 0 ;
const T_2 * V_11 ;
if ( ! V_17 -> V_27 || ! V_17 -> V_98 )
return 0 ;
V_11 = V_17 -> V_27 ;
while ( V_11 < V_17 -> V_27 + V_17 -> V_98 ) {
if ( * V_11 == V_99 ) {
V_97 = V_11 [ 1 ] + 2 ;
break;
}
V_11 ++ ;
}
if ( V_97 ) {
if ( F_32 ( V_84 ) < V_97 )
return - V_64 ;
memcpy ( F_33 ( V_84 , V_97 ) , V_11 , V_97 ) ;
}
return 0 ;
}
int F_39 ( struct V_83 * V_84 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_100 * V_101 ;
struct V_102 * V_103 = V_15 -> V_46 ;
T_2 * V_85 ;
if ( F_32 ( V_84 ) < 3 )
return - V_64 ;
V_101 = V_15 -> V_24 . V_104 -> V_105 [ V_103 -> V_47 ] ;
if ( V_101 -> V_47 == V_106 ) {
V_85 = F_33 ( V_84 , 2 + 1 ) ;
* V_85 ++ = V_107 ;
* V_85 ++ = 1 ;
* V_85 ++ = F_40 ( V_103 -> V_108 ) ;
}
return 0 ;
}
int F_41 ( struct V_83 * V_84 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_100 * V_101 ;
T_2 * V_85 ;
V_101 = V_15 -> V_24 . V_104 -> V_105 [ V_15 -> V_46 -> V_47 ] ;
if ( ! V_101 -> V_109 . V_110 ||
V_13 -> V_48 . V_49 . V_51 == V_31 )
return 0 ;
if ( F_32 ( V_84 ) < 2 + sizeof( struct V_111 ) )
return - V_64 ;
V_85 = F_33 ( V_84 , 2 + sizeof( struct V_111 ) ) ;
F_42 ( V_85 , & V_101 -> V_109 , V_101 -> V_109 . V_112 ) ;
return 0 ;
}
int F_43 ( struct V_83 * V_84 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_102 * V_113 = V_15 -> V_46 ;
enum V_29 V_51 =
V_13 -> V_48 . V_49 . V_51 ;
struct V_100 * V_101 =
V_15 -> V_24 . V_104 -> V_105 [ V_113 -> V_47 ] ;
struct V_114 * V_109 = & V_101 -> V_109 ;
T_2 * V_85 ;
if ( ! V_109 -> V_110 || V_51 == V_31 )
return 0 ;
if ( F_32 ( V_84 ) < 2 + sizeof( struct V_115 ) )
return - V_64 ;
V_85 = F_33 ( V_84 , 2 + sizeof( struct V_115 ) ) ;
F_44 ( V_85 , V_109 , V_113 , V_51 ,
V_13 -> V_48 . V_49 . V_116 ) ;
return 0 ;
}
static void F_45 ( unsigned long V_11 )
{
struct V_12 * V_13 =
(struct V_12 * ) V_11 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_14 * V_15 = V_13 -> V_15 ;
if ( V_15 -> V_21 ) {
F_9 ( V_117 , & V_17 -> V_23 ) ;
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
F_9 ( V_118 , & V_17 -> V_20 ) ;
if ( V_15 -> V_21 ) {
F_9 ( V_119 , & V_17 -> V_23 ) ;
return;
}
F_10 ( & V_15 -> V_24 , & V_13 -> V_25 ) ;
}
void F_47 ( struct V_16 * V_17 )
{
if ( V_17 -> V_120 . V_121 > V_122 )
F_9 ( V_118 , & V_17 -> V_20 ) ;
else {
F_48 ( V_118 , & V_17 -> V_20 ) ;
F_49 ( & V_17 -> V_123 ) ;
}
}
int F_50 ( struct V_124 * V_125 , T_3 * V_126 ,
const T_2 * V_127 , const T_2 * V_128 )
{
if ( F_51 ( V_127 ) ) {
* V_126 |= F_52 ( V_129 ) ;
memcpy ( V_125 -> V_130 , V_127 , V_82 ) ;
memcpy ( V_125 -> V_131 , V_128 , V_82 ) ;
memcpy ( V_125 -> V_132 , V_128 , V_82 ) ;
return 24 ;
} else {
* V_126 |= F_52 ( V_129 | V_133 ) ;
memset ( V_125 -> V_130 , 0 , V_82 ) ;
memcpy ( V_125 -> V_131 , V_128 , V_82 ) ;
memcpy ( V_125 -> V_132 , V_127 , V_82 ) ;
memcpy ( V_125 -> V_134 , V_128 , V_82 ) ;
return 30 ;
}
}
int F_53 ( struct V_72 * V_135 ,
struct V_12 * V_13 , char * V_136 ,
char * V_137 )
{
int V_138 = 0 ;
F_54 ( ! V_136 && V_137 ) ;
memset ( V_135 , 0 , sizeof( * V_135 ) ) ;
V_135 -> V_139 = V_13 -> V_3 . V_18 . V_120 . V_140 ;
F_55 ( F_56 ( V_13 -> V_3 . V_18 . V_141 ) , & V_135 -> V_74 ) ;
V_13 -> V_3 . V_18 . V_141 ++ ;
if ( V_136 && ! V_137 ) {
V_135 -> V_142 |= V_143 ;
V_138 += V_82 ;
memcpy ( V_135 -> V_144 , V_136 , V_82 ) ;
} else if ( V_136 && V_137 ) {
V_135 -> V_142 |= V_145 ;
V_138 += 2 * V_82 ;
memcpy ( V_135 -> V_144 , V_136 , V_82 ) ;
memcpy ( V_135 -> V_146 , V_137 , V_82 ) ;
}
return 6 + V_138 ;
}
static void F_57 ( struct V_12 * V_13 ,
struct V_16 * V_17 )
{
T_1 V_57 ;
F_58 ( V_13 , V_147 ) ;
F_59 ( V_13 ) ;
V_57 = F_15 ( V_13 ) ;
F_60 ( V_13 , V_57 ) ;
F_61 ( & V_17 -> V_148 ,
F_62 ( V_77 + V_149 ) ) ;
}
static void F_63 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 V_150 ;
F_64 ( V_13 ) ;
if ( V_17 -> V_120 . V_121 == V_151 )
V_150 = V_17 -> V_120 . V_152 ;
else
V_150 = V_17 -> V_120 . V_153 ;
F_61 ( & V_17 -> V_123 ,
F_62 ( F_65 ( V_150 ) ) ) ;
}
void F_66 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
if ( F_49 ( & V_17 -> V_148 ) )
F_9 ( V_22 , & V_17 -> V_23 ) ;
if ( F_49 ( & V_17 -> V_154 ) )
F_9 ( V_117 , & V_17 -> V_23 ) ;
if ( F_49 ( & V_17 -> V_123 ) )
F_9 ( V_119 , & V_17 -> V_23 ) ;
}
void F_67 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
if ( F_68 ( V_22 , & V_17 -> V_23 ) )
F_69 ( & V_17 -> V_148 ) ;
if ( F_68 ( V_117 , & V_17 -> V_23 ) )
F_69 ( & V_17 -> V_154 ) ;
if ( F_68 ( V_119 , & V_17 -> V_23 ) )
F_69 ( & V_17 -> V_123 ) ;
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
V_17 -> V_93 = false ;
V_17 -> V_158 = 0 ;
F_9 ( V_19 , & V_17 -> V_20 ) ;
F_47 ( V_17 ) ;
F_10 ( & V_15 -> V_24 , & V_13 -> V_25 ) ;
V_13 -> V_48 . V_49 . V_116 =
V_17 -> V_120 . V_159 ;
V_13 -> V_48 . V_49 . V_160 = V_161 ;
V_13 -> V_48 . V_49 . V_28 =
F_74 ( V_13 -> V_15 ,
V_13 -> V_15 -> V_46 -> V_47 ) ;
F_60 ( V_13 , V_59 |
V_162 |
V_163 |
V_164 |
V_165 ) ;
F_75 ( V_13 -> V_166 ) ;
}
void F_76 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
F_77 ( V_13 -> V_166 ) ;
V_17 -> V_32 = 0 ;
F_60 ( V_13 , V_162 ) ;
F_78 ( V_13 -> V_15 , V_13 ) ;
F_79 ( V_13 ) ;
F_49 ( & V_13 -> V_3 . V_18 . V_148 ) ;
F_49 ( & V_13 -> V_3 . V_18 . V_123 ) ;
F_49 ( & V_13 -> V_3 . V_18 . V_154 ) ;
F_80 ( & V_13 -> V_25 ) ;
V_15 -> V_155 -- ;
F_81 ( & V_15 -> V_156 ) ;
F_72 ( V_15 ) ;
V_13 -> V_3 . V_18 . V_23 = 0 ;
}
static void F_82 ( struct V_12 * V_13 ,
T_4 V_167 ,
struct V_1 * V_2 ,
T_5 V_97 ,
struct V_168 * V_169 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_26 V_170 ;
struct V_102 * V_113 ;
T_5 V_171 ;
int V_172 ;
enum V_173 V_47 = V_169 -> V_47 ;
if ( V_167 == V_174 &&
! F_28 ( V_2 -> V_175 , V_13 -> V_48 . V_176 ) )
return;
V_171 = ( T_2 * ) V_2 -> V_3 . V_177 . V_178 - ( T_2 * ) V_2 ;
if ( V_171 > V_97 )
return;
F_83 ( V_2 -> V_3 . V_177 . V_178 , V_97 - V_171 ,
& V_170 ) ;
if ( V_170 . V_179 && V_13 -> V_3 . V_18 . V_180 == V_181 )
return;
if ( V_170 . V_182 && V_170 . V_183 == 1 )
V_172 = F_84 ( V_170 . V_182 [ 0 ] , V_47 ) ;
else
V_172 = V_169 -> V_172 ;
V_113 = F_85 ( V_15 -> V_24 . V_104 , V_172 ) ;
if ( ! V_113 || V_113 -> V_142 & V_184 )
return;
if ( V_170 . V_33 && V_170 . V_35 &&
F_11 ( V_13 , & V_170 ) )
F_86 ( V_13 , V_2 -> V_71 , & V_170 ) ;
if ( V_17 -> V_157 )
V_17 -> V_157 -> V_185 ( V_13 ,
V_167 , V_2 , & V_170 , V_169 ) ;
}
static void F_87 ( struct V_12 * V_13 ,
struct V_1 * V_2 ,
T_5 V_97 ,
struct V_168 * V_169 )
{
switch ( V_2 -> V_3 . V_4 . V_186 ) {
case V_187 :
switch ( V_2 -> V_3 . V_4 . V_3 . V_188 . V_6 ) {
case V_189 :
case V_190 :
case V_191 :
F_88 ( V_13 , V_2 , V_97 , V_169 ) ;
break;
}
break;
case V_192 :
if ( F_1 ( V_2 ) )
F_89 ( V_13 , V_2 , V_97 ) ;
break;
}
}
void F_90 ( struct V_12 * V_13 ,
struct V_83 * V_84 )
{
struct V_168 * V_169 ;
struct V_1 * V_2 ;
T_4 V_167 ;
V_169 = F_91 ( V_84 ) ;
V_2 = (struct V_1 * ) V_84 -> V_11 ;
V_167 = F_92 ( V_2 -> V_193 ) & V_194 ;
switch ( V_167 ) {
case V_174 :
case V_195 :
F_82 ( V_13 , V_167 , V_2 , V_84 -> V_97 ,
V_169 ) ;
break;
case V_196 :
F_87 ( V_13 , V_2 , V_84 -> V_97 , V_169 ) ;
break;
}
}
void F_93 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
if ( V_17 -> V_197 &&
F_27 ( V_77 ,
V_17 -> V_198 + F_94 ( V_17 -> V_120 . V_199 ) ) )
F_95 ( V_13 ) ;
if ( F_68 ( V_200 , & V_17 -> V_20 ) )
F_96 () ;
if ( F_68 ( V_201 , & V_17 -> V_20 ) )
F_97 () ;
if ( F_68 ( V_19 , & V_17 -> V_20 ) )
F_57 ( V_13 , V_17 ) ;
if ( F_68 ( V_118 , & V_17 -> V_20 ) )
F_63 ( V_13 ) ;
if ( F_68 ( V_202 , & V_17 -> V_20 ) )
F_98 ( V_13 ) ;
}
void F_99 ( struct V_14 * V_15 )
{
struct V_12 * V_13 ;
F_100 () ;
F_101 (sdata, &local->interfaces, list)
if ( F_102 ( & V_13 -> V_48 ) )
F_10 ( & V_15 -> V_24 , & V_13 -> V_25 ) ;
F_103 () ;
}
void F_104 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
F_105 ( & V_17 -> V_148 ,
F_8 ,
( unsigned long ) V_13 ) ;
V_17 -> V_58 = true ;
V_17 -> V_203 = 0 ;
V_17 -> V_204 = 0 ;
V_17 -> V_205 = 0 ;
F_106 ( & V_17 -> V_206 , 0 ) ;
F_17 ( V_13 ) ;
V_17 -> V_198 = V_77 ;
V_17 -> V_207 = V_77 ;
if ( ! V_8 )
F_2 () ;
F_105 ( & V_17 -> V_154 ,
F_45 ,
( unsigned long ) V_13 ) ;
F_105 ( & V_17 -> V_123 ,
F_46 ,
( unsigned long ) V_13 ) ;
F_19 ( & V_17 -> V_208 . V_68 ) ;
F_107 ( & V_17 -> V_209 ) ;
F_107 ( & V_17 -> V_210 ) ;
}
