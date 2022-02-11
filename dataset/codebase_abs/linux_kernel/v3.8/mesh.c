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
struct V_29 V_30 ;
if ( ! ( V_17 -> V_31 == V_27 -> V_31 &&
memcmp ( V_17 -> V_32 , V_27 -> V_32 , V_27 -> V_31 ) == 0 &&
( V_17 -> V_33 == V_27 -> V_34 -> V_35 ) &&
( V_17 -> V_36 == V_27 -> V_34 -> V_37 ) &&
( V_17 -> V_38 == V_27 -> V_34 -> V_39 ) &&
( V_17 -> V_40 == V_27 -> V_34 -> V_41 ) &&
( V_17 -> V_42 == V_27 -> V_34 -> V_43 ) ) )
goto V_44;
F_12 ( V_15 , V_27 , F_13 ( V_13 ) ,
& V_28 ) ;
if ( V_13 -> V_45 . V_46 . V_28 != V_28 )
goto V_44;
F_14 ( V_13 -> V_45 . V_46 . V_47 . V_48 ,
V_27 -> V_49 , & V_30 ) ;
if ( ! F_15 ( & V_13 -> V_45 . V_46 . V_47 ,
& V_30 ) )
goto V_44;
return true ;
V_44:
return false ;
}
bool F_16 ( struct V_26 * V_27 )
{
return ( V_27 -> V_34 -> V_50 &
V_51 ) != 0 ;
}
T_1 F_17 ( struct V_12 * V_13 )
{
bool V_52 ;
T_1 V_53 = 0 ;
V_52 = F_18 ( V_13 ) ;
if ( V_52 != V_13 -> V_3 . V_18 . V_54 ) {
V_13 -> V_3 . V_18 . V_54 = V_52 ;
V_53 = V_55 ;
}
return V_53 ;
}
int F_19 ( struct V_12 * V_13 )
{
int V_56 ;
V_13 -> V_3 . V_18 . V_57 = F_20 ( sizeof( struct V_58 ) , V_59 ) ;
if ( ! V_13 -> V_3 . V_18 . V_57 )
return - V_60 ;
V_13 -> V_3 . V_18 . V_57 -> V_61 = V_62 - 1 ;
for ( V_56 = 0 ; V_56 < V_62 ; V_56 ++ )
F_21 ( & V_13 -> V_3 . V_18 . V_57 -> V_63 [ V_56 ] ) ;
return 0 ;
}
void F_22 ( struct V_12 * V_13 )
{
struct V_58 * V_57 = V_13 -> V_3 . V_18 . V_57 ;
struct V_10 * V_64 , * V_65 ;
int V_56 ;
if ( ! V_13 -> V_3 . V_18 . V_57 )
return;
for ( V_56 = 0 ; V_56 < V_62 ; V_56 ++ )
F_23 (p, n, &rmc->bucket[i], list) {
F_24 ( & V_64 -> V_66 ) ;
F_25 ( V_9 , V_64 ) ;
}
F_26 ( V_57 ) ;
V_13 -> V_3 . V_18 . V_57 = NULL ;
}
int F_27 ( T_2 * V_67 , struct V_68 * V_69 ,
struct V_12 * V_13 )
{
struct V_58 * V_57 = V_13 -> V_3 . V_18 . V_57 ;
T_1 V_70 = 0 ;
int V_71 = 0 ;
T_2 V_72 ;
struct V_10 * V_64 , * V_65 ;
memcpy ( & V_70 , & V_69 -> V_70 , sizeof( V_69 -> V_70 ) ) ;
V_72 = F_28 ( V_69 -> V_70 ) & V_57 -> V_61 ;
F_23 (p, n, &rmc->bucket[idx], list) {
++ V_71 ;
if ( F_29 ( V_73 , V_64 -> V_74 ) ||
( V_71 == V_75 ) ) {
F_24 ( & V_64 -> V_66 ) ;
F_25 ( V_9 , V_64 ) ;
-- V_71 ;
} else if ( ( V_70 == V_64 -> V_70 ) &&
( F_30 ( V_67 , V_64 -> V_67 ) ) )
return - 1 ;
}
V_64 = F_31 ( V_9 , V_76 ) ;
if ( ! V_64 )
return 0 ;
V_64 -> V_70 = V_70 ;
V_64 -> V_74 = V_73 + V_77 ;
memcpy ( V_64 -> V_67 , V_67 , V_78 ) ;
F_32 ( & V_64 -> V_66 , & V_57 -> V_63 [ V_72 ] ) ;
return 0 ;
}
int
F_33 ( struct V_79 * V_80 , struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 * V_81 , V_82 ;
T_2 V_83 = sizeof( struct V_84 ) ;
if ( F_34 ( V_80 ) < 2 + V_83 )
return - V_60 ;
V_81 = F_35 ( V_80 , 2 + V_83 ) ;
* V_81 ++ = V_85 ;
* V_81 ++ = V_83 ;
* V_81 ++ = V_17 -> V_33 ;
* V_81 ++ = V_17 -> V_36 ;
* V_81 ++ = V_17 -> V_38 ;
* V_81 ++ = V_17 -> V_40 ;
* V_81 ++ = V_17 -> V_42 ;
V_82 = F_36 ( & V_17 -> V_86 ) ;
V_82 = ( V_82 > 15 ) ? 15 : V_82 ;
* V_81 ++ = V_82 << 1 ;
* V_81 = V_87 ;
* V_81 |= V_17 -> V_54 ?
V_51 : 0x00 ;
* V_81 ++ |= V_17 -> V_88 ?
V_89 : 0x00 ;
* V_81 ++ = 0x00 ;
return 0 ;
}
int
F_37 ( struct V_79 * V_80 , struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 * V_81 ;
if ( F_34 ( V_80 ) < 2 + V_17 -> V_31 )
return - V_60 ;
V_81 = F_35 ( V_80 , 2 + V_17 -> V_31 ) ;
* V_81 ++ = V_90 ;
* V_81 ++ = V_17 -> V_31 ;
if ( V_17 -> V_31 )
memcpy ( V_81 , V_17 -> V_32 , V_17 -> V_31 ) ;
return 0 ;
}
int
F_38 ( struct V_79 * V_80 , struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 V_91 , V_92 ;
const T_2 * V_11 ;
if ( ! V_17 -> V_27 || ! V_17 -> V_93 )
return 0 ;
V_91 = F_39 ( V_17 -> V_27 , V_17 -> V_93 , 0 ) ;
if ( V_91 ) {
V_92 = V_17 -> V_93 - V_91 ;
V_11 = V_17 -> V_27 + V_91 ;
if ( F_34 ( V_80 ) < V_92 )
return - V_60 ;
memcpy ( F_35 ( V_80 , V_92 ) , V_11 , V_92 ) ;
}
return 0 ;
}
int
F_40 ( struct V_79 * V_80 , struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_2 V_92 = 0 ;
const T_2 * V_11 ;
if ( ! V_17 -> V_27 || ! V_17 -> V_93 )
return 0 ;
V_11 = V_17 -> V_27 ;
while ( V_11 < V_17 -> V_27 + V_17 -> V_93 ) {
if ( * V_11 == V_94 ) {
V_92 = V_11 [ 1 ] + 2 ;
break;
}
V_11 ++ ;
}
if ( V_92 ) {
if ( F_34 ( V_80 ) < V_92 )
return - V_60 ;
memcpy ( F_35 ( V_80 , V_92 ) , V_11 , V_92 ) ;
}
return 0 ;
}
int F_41 ( struct V_79 * V_80 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_95 * V_96 ;
struct V_97 * V_98 ;
struct V_99 * V_48 ;
T_2 * V_81 ;
if ( F_34 ( V_80 ) < 3 )
return - V_60 ;
F_42 () ;
V_98 = F_43 ( V_13 -> V_45 . V_98 ) ;
if ( F_44 ( ! V_98 ) ) {
F_45 () ;
return - V_100 ;
}
V_48 = V_98 -> V_101 . V_48 ;
F_45 () ;
V_96 = V_15 -> V_24 . V_102 -> V_103 [ V_48 -> V_104 ] ;
if ( V_96 -> V_104 == V_105 ) {
V_81 = F_35 ( V_80 , 2 + 1 ) ;
* V_81 ++ = V_106 ;
* V_81 ++ = 1 ;
* V_81 ++ = F_46 ( V_48 -> V_107 ) ;
}
return 0 ;
}
int F_47 ( struct V_79 * V_80 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
enum V_108 V_104 = F_13 ( V_13 ) ;
struct V_95 * V_96 ;
T_2 * V_81 ;
V_96 = V_15 -> V_24 . V_102 -> V_103 [ V_104 ] ;
if ( ! V_96 -> V_109 . V_110 ||
V_13 -> V_45 . V_46 . V_47 . V_111 == V_112 )
return 0 ;
if ( F_34 ( V_80 ) < 2 + sizeof( struct V_113 ) )
return - V_60 ;
V_81 = F_35 ( V_80 , 2 + sizeof( struct V_113 ) ) ;
F_48 ( V_81 , & V_96 -> V_109 , V_96 -> V_109 . V_114 ) ;
return 0 ;
}
int F_49 ( struct V_79 * V_80 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_97 * V_98 ;
struct V_99 * V_115 ;
enum V_116 V_117 =
F_50 ( & V_13 -> V_45 . V_46 . V_47 ) ;
struct V_95 * V_96 ;
struct V_118 * V_109 ;
T_2 * V_81 ;
F_42 () ;
V_98 = F_43 ( V_13 -> V_45 . V_98 ) ;
if ( F_44 ( ! V_98 ) ) {
F_45 () ;
return - V_100 ;
}
V_115 = V_98 -> V_101 . V_48 ;
F_45 () ;
V_96 = V_15 -> V_24 . V_102 -> V_103 [ V_115 -> V_104 ] ;
V_109 = & V_96 -> V_109 ;
if ( ! V_109 -> V_110 || V_117 == V_119 )
return 0 ;
if ( F_34 ( V_80 ) < 2 + sizeof( struct V_120 ) )
return - V_60 ;
V_81 = F_35 ( V_80 , 2 + sizeof( struct V_120 ) ) ;
F_51 ( V_81 , V_109 , & V_13 -> V_45 . V_46 . V_47 ,
V_13 -> V_45 . V_46 . V_121 ) ;
return 0 ;
}
static void F_52 ( unsigned long V_11 )
{
struct V_12 * V_13 =
(struct V_12 * ) V_11 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_14 * V_15 = V_13 -> V_15 ;
if ( V_15 -> V_21 ) {
F_9 ( V_122 , & V_17 -> V_23 ) ;
return;
}
F_10 ( & V_15 -> V_24 , & V_13 -> V_25 ) ;
}
static void F_53 ( unsigned long V_11 )
{
struct V_12 * V_13 =
(struct V_12 * ) V_11 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_14 * V_15 = V_13 -> V_15 ;
F_9 ( V_123 , & V_17 -> V_20 ) ;
if ( V_15 -> V_21 ) {
F_9 ( V_124 , & V_17 -> V_23 ) ;
return;
}
F_10 ( & V_15 -> V_24 , & V_13 -> V_25 ) ;
}
void F_54 ( struct V_16 * V_17 )
{
if ( V_17 -> V_125 . V_126 > V_127 )
F_9 ( V_123 , & V_17 -> V_20 ) ;
else {
F_55 ( V_123 , & V_17 -> V_20 ) ;
F_56 ( & V_17 -> V_128 ) ;
}
}
int F_57 ( struct V_129 * V_130 , T_3 * V_131 ,
const T_2 * V_132 , const T_2 * V_133 )
{
if ( F_58 ( V_132 ) ) {
* V_131 |= F_59 ( V_134 ) ;
memcpy ( V_130 -> V_135 , V_132 , V_78 ) ;
memcpy ( V_130 -> V_136 , V_133 , V_78 ) ;
memcpy ( V_130 -> V_137 , V_133 , V_78 ) ;
return 24 ;
} else {
* V_131 |= F_59 ( V_134 | V_138 ) ;
memset ( V_130 -> V_135 , 0 , V_78 ) ;
memcpy ( V_130 -> V_136 , V_133 , V_78 ) ;
memcpy ( V_130 -> V_137 , V_132 , V_78 ) ;
memcpy ( V_130 -> V_139 , V_133 , V_78 ) ;
return 30 ;
}
}
int F_60 ( struct V_68 * V_140 ,
struct V_12 * V_13 , char * V_141 ,
char * V_142 )
{
int V_143 = 0 ;
F_61 ( ! V_141 && V_142 ) ;
memset ( V_140 , 0 , sizeof( * V_140 ) ) ;
V_140 -> V_144 = V_13 -> V_3 . V_18 . V_125 . V_145 ;
F_62 ( F_63 ( V_13 -> V_3 . V_18 . V_146 ) , & V_140 -> V_70 ) ;
V_13 -> V_3 . V_18 . V_146 ++ ;
if ( V_141 && ! V_142 ) {
V_140 -> V_147 |= V_148 ;
V_143 += V_78 ;
memcpy ( V_140 -> V_149 , V_141 , V_78 ) ;
} else if ( V_141 && V_142 ) {
V_140 -> V_147 |= V_150 ;
V_143 += 2 * V_78 ;
memcpy ( V_140 -> V_149 , V_141 , V_78 ) ;
memcpy ( V_140 -> V_151 , V_142 , V_78 ) ;
}
return 6 + V_143 ;
}
static void F_64 ( struct V_12 * V_13 ,
struct V_16 * V_17 )
{
T_1 V_53 ;
F_65 ( V_13 , V_152 ) ;
F_66 ( V_13 ) ;
V_53 = F_17 ( V_13 ) ;
F_67 ( V_13 , V_53 ) ;
F_68 ( & V_17 -> V_153 ,
F_69 ( V_73 + V_154 ) ) ;
}
static void F_70 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 V_155 ;
F_71 ( V_13 ) ;
if ( V_17 -> V_125 . V_126 == V_156 )
V_155 = V_17 -> V_125 . V_157 ;
else
V_155 = V_17 -> V_125 . V_158 ;
F_68 ( & V_17 -> V_128 ,
F_69 ( F_72 ( V_155 ) ) ) ;
}
void F_73 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
if ( F_56 ( & V_17 -> V_153 ) )
F_9 ( V_22 , & V_17 -> V_23 ) ;
if ( F_56 ( & V_17 -> V_159 ) )
F_9 ( V_122 , & V_17 -> V_23 ) ;
if ( F_56 ( & V_17 -> V_128 ) )
F_9 ( V_124 , & V_17 -> V_23 ) ;
}
void F_74 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
if ( F_75 ( V_22 , & V_17 -> V_23 ) )
F_76 ( & V_17 -> V_153 ) ;
if ( F_75 ( V_122 , & V_17 -> V_23 ) )
F_76 ( & V_17 -> V_159 ) ;
if ( F_75 ( V_124 , & V_17 -> V_23 ) )
F_76 ( & V_17 -> V_128 ) ;
F_54 ( V_17 ) ;
}
void F_77 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_14 * V_15 = V_13 -> V_15 ;
V_15 -> V_160 ++ ;
F_78 ( & V_15 -> V_161 ) ;
F_79 ( V_15 ) ;
V_17 -> V_38 = 0 ;
V_17 -> V_42 = 0 ;
V_17 -> V_162 = F_80 ( V_17 -> V_40 ) ;
V_17 -> V_88 = false ;
V_17 -> V_163 = 0 ;
F_9 ( V_19 , & V_17 -> V_20 ) ;
F_54 ( V_17 ) ;
F_10 ( & V_15 -> V_24 , & V_13 -> V_25 ) ;
V_13 -> V_45 . V_46 . V_121 =
V_17 -> V_125 . V_164 ;
V_13 -> V_45 . V_46 . V_165 = V_166 ;
V_13 -> V_45 . V_46 . V_28 =
F_81 ( V_13 -> V_15 ,
F_13 ( V_13 ) ) ;
F_67 ( V_13 , V_55 |
V_167 |
V_168 |
V_169 |
V_170 ) ;
F_82 ( V_13 -> V_171 ) ;
}
void F_83 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
F_84 ( V_13 -> V_171 ) ;
V_17 -> V_31 = 0 ;
F_67 ( V_13 , V_167 ) ;
F_85 ( V_13 -> V_15 , V_13 ) ;
F_86 ( V_13 ) ;
F_56 ( & V_13 -> V_3 . V_18 . V_153 ) ;
F_56 ( & V_13 -> V_3 . V_18 . V_128 ) ;
F_56 ( & V_13 -> V_3 . V_18 . V_159 ) ;
F_87 ( & V_13 -> V_25 ) ;
V_15 -> V_160 -- ;
F_88 ( & V_15 -> V_161 ) ;
F_79 ( V_15 ) ;
V_13 -> V_3 . V_18 . V_23 = 0 ;
}
static void F_89 ( struct V_12 * V_13 ,
T_4 V_172 ,
struct V_1 * V_2 ,
T_5 V_92 ,
struct V_173 * V_174 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_26 V_175 ;
struct V_99 * V_115 ;
T_5 V_176 ;
int V_177 ;
enum V_108 V_104 = V_174 -> V_104 ;
if ( V_172 == V_178 &&
! F_30 ( V_2 -> V_179 , V_13 -> V_45 . V_180 ) )
return;
V_176 = ( T_2 * ) V_2 -> V_3 . V_181 . V_182 - ( T_2 * ) V_2 ;
if ( V_176 > V_92 )
return;
F_90 ( V_2 -> V_3 . V_181 . V_182 , V_92 - V_176 ,
& V_175 ) ;
if ( ( ! V_175 . V_32 || ! V_175 . V_34 ) ||
( V_175 . V_183 && V_13 -> V_3 . V_18 . V_184 == V_185 ) ||
( ! V_175 . V_183 && V_13 -> V_3 . V_18 . V_184 != V_185 ) )
return;
if ( V_175 . V_186 && V_175 . V_187 == 1 )
V_177 = F_91 ( V_175 . V_186 [ 0 ] , V_104 ) ;
else
V_177 = V_174 -> V_177 ;
V_115 = F_92 ( V_15 -> V_24 . V_102 , V_177 ) ;
if ( ! V_115 || V_115 -> V_147 & V_188 )
return;
if ( F_11 ( V_13 , & V_175 ) )
F_93 ( V_13 , V_2 -> V_67 , & V_175 ) ;
if ( V_17 -> V_162 )
V_17 -> V_162 -> V_189 ( V_13 ,
V_172 , V_2 , & V_175 , V_174 ) ;
}
static void F_94 ( struct V_12 * V_13 ,
struct V_1 * V_2 ,
T_5 V_92 ,
struct V_173 * V_174 )
{
switch ( V_2 -> V_3 . V_4 . V_190 ) {
case V_191 :
switch ( V_2 -> V_3 . V_4 . V_3 . V_192 . V_6 ) {
case V_193 :
case V_194 :
case V_195 :
F_95 ( V_13 , V_2 , V_92 , V_174 ) ;
break;
}
break;
case V_196 :
if ( F_1 ( V_2 ) )
F_96 ( V_13 , V_2 , V_92 ) ;
break;
}
}
void F_97 ( struct V_12 * V_13 ,
struct V_79 * V_80 )
{
struct V_173 * V_174 ;
struct V_1 * V_2 ;
T_4 V_172 ;
V_174 = F_98 ( V_80 ) ;
V_2 = (struct V_1 * ) V_80 -> V_11 ;
V_172 = F_99 ( V_2 -> V_197 ) & V_198 ;
switch ( V_172 ) {
case V_178 :
case V_199 :
F_89 ( V_13 , V_172 , V_2 , V_80 -> V_92 ,
V_174 ) ;
break;
case V_200 :
F_94 ( V_13 , V_2 , V_80 -> V_92 , V_174 ) ;
break;
}
}
void F_100 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
if ( V_17 -> V_201 &&
F_29 ( V_73 ,
V_17 -> V_202 + F_101 ( V_17 -> V_125 . V_203 ) ) )
F_102 ( V_13 ) ;
if ( F_75 ( V_204 , & V_17 -> V_20 ) )
F_103 () ;
if ( F_75 ( V_205 , & V_17 -> V_20 ) )
F_104 () ;
if ( F_75 ( V_19 , & V_17 -> V_20 ) )
F_64 ( V_13 , V_17 ) ;
if ( F_75 ( V_123 , & V_17 -> V_20 ) )
F_70 ( V_13 ) ;
if ( F_75 ( V_206 , & V_17 -> V_20 ) )
F_105 ( V_13 ) ;
}
void F_106 ( struct V_14 * V_15 )
{
struct V_12 * V_13 ;
F_42 () ;
F_107 (sdata, &local->interfaces, list)
if ( F_108 ( & V_13 -> V_45 ) )
F_10 ( & V_15 -> V_24 , & V_13 -> V_25 ) ;
F_45 () ;
}
void F_109 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
F_110 ( & V_17 -> V_153 ,
F_8 ,
( unsigned long ) V_13 ) ;
V_17 -> V_54 = true ;
V_17 -> V_207 = 0 ;
V_17 -> V_208 = 0 ;
V_17 -> V_209 = 0 ;
F_111 ( & V_17 -> V_210 , 0 ) ;
F_19 ( V_13 ) ;
V_17 -> V_202 = V_73 ;
V_17 -> V_211 = V_73 ;
if ( ! V_8 )
F_2 () ;
F_110 ( & V_17 -> V_159 ,
F_52 ,
( unsigned long ) V_13 ) ;
F_110 ( & V_17 -> V_128 ,
F_53 ,
( unsigned long ) V_13 ) ;
F_21 ( & V_17 -> V_212 . V_66 ) ;
F_112 ( & V_17 -> V_213 ) ;
F_112 ( & V_17 -> V_214 ) ;
}
