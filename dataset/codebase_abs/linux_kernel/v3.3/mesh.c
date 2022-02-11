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
bool F_11 ( struct V_26 * V_27 , struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_14 * V_15 = V_13 -> V_15 ;
if ( ! ( V_17 -> V_28 == V_27 -> V_28 &&
memcmp ( V_17 -> V_29 , V_27 -> V_29 , V_27 -> V_28 ) == 0 &&
( V_17 -> V_30 == V_27 -> V_31 -> V_32 ) &&
( V_17 -> V_33 == V_27 -> V_31 -> V_34 ) &&
( V_17 -> V_35 == V_27 -> V_31 -> V_36 ) &&
( V_17 -> V_37 == V_27 -> V_31 -> V_38 ) &&
( V_17 -> V_39 == V_27 -> V_31 -> V_40 ) ) )
goto V_41;
if ( V_27 -> V_42 &&
( V_15 -> V_43 !=
F_12 ( V_27 -> V_42 ) ) )
goto V_41;
return true ;
V_41:
return false ;
}
bool F_13 ( struct V_26 * V_27 )
{
return ( V_27 -> V_31 -> V_44 &
V_45 ) != 0 ;
}
void F_14 ( struct V_12 * V_13 )
{
bool V_46 ;
V_46 = F_15 ( V_13 ) ;
if ( V_46 != V_13 -> V_3 . V_18 . V_47 )
F_8 ( ( unsigned long ) V_13 ) ;
}
int F_16 ( struct V_12 * V_13 )
{
int V_48 ;
V_13 -> V_3 . V_18 . V_49 = F_17 ( sizeof( struct V_50 ) , V_51 ) ;
if ( ! V_13 -> V_3 . V_18 . V_49 )
return - V_52 ;
V_13 -> V_3 . V_18 . V_49 -> V_53 = V_54 - 1 ;
for ( V_48 = 0 ; V_48 < V_54 ; V_48 ++ )
F_18 ( & V_13 -> V_3 . V_18 . V_49 -> V_55 [ V_48 ] . V_56 ) ;
return 0 ;
}
void F_19 ( struct V_12 * V_13 )
{
struct V_50 * V_49 = V_13 -> V_3 . V_18 . V_49 ;
struct V_10 * V_57 , * V_58 ;
int V_48 ;
if ( ! V_13 -> V_3 . V_18 . V_49 )
return;
for ( V_48 = 0 ; V_48 < V_54 ; V_48 ++ )
F_20 (p, n, &rmc->bucket[i].list, list) {
F_21 ( & V_57 -> V_56 ) ;
F_22 ( V_9 , V_57 ) ;
}
F_23 ( V_49 ) ;
V_13 -> V_3 . V_18 . V_49 = NULL ;
}
int F_24 ( T_1 * V_59 , struct V_60 * V_61 ,
struct V_12 * V_13 )
{
struct V_50 * V_49 = V_13 -> V_3 . V_18 . V_49 ;
T_2 V_62 = 0 ;
int V_63 = 0 ;
T_1 V_64 ;
struct V_10 * V_57 , * V_58 ;
memcpy ( & V_62 , & V_61 -> V_62 , sizeof( V_61 -> V_62 ) ) ;
V_64 = F_25 ( V_61 -> V_62 ) & V_49 -> V_53 ;
F_20 (p, n, &rmc->bucket[idx].list, list) {
++ V_63 ;
if ( F_26 ( V_65 , V_57 -> V_66 ) ||
( V_63 == V_67 ) ) {
F_21 ( & V_57 -> V_56 ) ;
F_22 ( V_9 , V_57 ) ;
-- V_63 ;
} else if ( ( V_62 == V_57 -> V_62 ) &&
( memcmp ( V_59 , V_57 -> V_59 , V_68 ) == 0 ) )
return - 1 ;
}
V_57 = F_27 ( V_9 , V_69 ) ;
if ( ! V_57 )
return 0 ;
V_57 -> V_62 = V_62 ;
V_57 -> V_66 = V_65 + V_70 ;
memcpy ( V_57 -> V_59 , V_59 , V_68 ) ;
F_28 ( & V_57 -> V_56 , & V_49 -> V_55 [ V_64 ] . V_56 ) ;
return 0 ;
}
int
F_29 ( struct V_71 * V_72 , struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 * V_73 , V_74 ;
T_1 V_75 = sizeof( struct V_76 ) ;
if ( F_30 ( V_72 ) < 2 + V_75 )
return - V_52 ;
V_73 = F_31 ( V_72 , 2 + V_75 ) ;
* V_73 ++ = V_77 ;
* V_73 ++ = V_75 ;
* V_73 ++ = V_17 -> V_30 ;
* V_73 ++ = V_17 -> V_33 ;
* V_73 ++ = V_17 -> V_35 ;
* V_73 ++ = V_17 -> V_37 ;
* V_73 ++ = V_17 -> V_39 ;
V_74 = F_32 ( & V_17 -> V_78 . V_79 ) ;
V_74 = ( V_74 > 15 ) ? 15 : V_74 ;
* V_73 ++ = V_74 << 1 ;
V_17 -> V_47 = F_15 ( V_13 ) ;
* V_73 = V_80 ;
* V_73 ++ |= V_17 -> V_47 ?
V_45 : 0x00 ;
* V_73 ++ = 0x00 ;
return 0 ;
}
int
F_33 ( struct V_71 * V_72 , struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 * V_73 ;
if ( F_30 ( V_72 ) < 2 + V_17 -> V_28 )
return - V_52 ;
V_73 = F_31 ( V_72 , 2 + V_17 -> V_28 ) ;
* V_73 ++ = V_81 ;
* V_73 ++ = V_17 -> V_28 ;
if ( V_17 -> V_28 )
memcpy ( V_73 , V_17 -> V_29 , V_17 -> V_28 ) ;
return 0 ;
}
int
F_34 ( struct V_71 * V_72 , struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 V_82 , V_83 ;
const T_1 * V_11 ;
if ( ! V_17 -> V_27 || ! V_17 -> V_84 )
return 0 ;
V_82 = F_35 ( V_17 -> V_27 , V_17 -> V_84 , 0 ) ;
if ( V_82 ) {
V_83 = V_17 -> V_84 - V_82 ;
V_11 = V_17 -> V_27 + V_82 ;
if ( F_30 ( V_72 ) < V_83 )
return - V_52 ;
memcpy ( F_31 ( V_72 , V_83 ) , V_11 , V_83 ) ;
}
return 0 ;
}
int
F_36 ( struct V_71 * V_72 , struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 V_83 = 0 ;
const T_1 * V_11 ;
if ( ! V_17 -> V_27 || ! V_17 -> V_84 )
return 0 ;
V_11 = V_17 -> V_27 ;
while ( V_11 < V_17 -> V_27 + V_17 -> V_84 ) {
if ( * V_11 == V_85 ) {
V_83 = V_11 [ 1 ] + 2 ;
break;
}
V_11 ++ ;
}
if ( V_83 ) {
if ( F_30 ( V_72 ) < V_83 )
return - V_52 ;
memcpy ( F_31 ( V_72 , V_83 ) , V_11 , V_83 ) ;
}
return 0 ;
}
int F_37 ( struct V_71 * V_72 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_86 * V_87 ;
T_1 * V_73 ;
if ( F_30 ( V_72 ) < 3 )
return - V_52 ;
V_87 = V_15 -> V_24 . V_88 -> V_89 [ V_15 -> V_24 . V_90 . V_91 -> V_92 ] ;
if ( V_87 -> V_92 == V_93 ) {
V_73 = F_31 ( V_72 , 2 + 1 ) ;
* V_73 ++ = V_94 ;
* V_73 ++ = 1 ;
* V_73 ++ = F_38 ( V_15 -> V_24 . V_90 . V_91 -> V_95 ) ;
}
return 0 ;
}
int F_39 ( struct V_71 * V_72 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_86 * V_87 ;
T_1 * V_73 ;
V_87 = V_15 -> V_24 . V_88 -> V_89 [ V_15 -> V_96 -> V_92 ] ;
if ( ! V_87 -> V_97 . V_98 ||
V_15 -> V_43 == V_99 )
return 0 ;
if ( F_30 ( V_72 ) < 2 + sizeof( struct V_100 ) )
return - V_52 ;
V_73 = F_31 ( V_72 , 2 + sizeof( struct V_100 ) ) ;
F_40 ( V_73 , & V_87 -> V_97 , V_87 -> V_97 . V_101 ) ;
return 0 ;
}
int F_41 ( struct V_71 * V_72 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_102 * V_91 = V_15 -> V_96 ;
enum V_103 V_104 = V_15 -> V_43 ;
struct V_86 * V_87 =
V_15 -> V_24 . V_88 -> V_89 [ V_91 -> V_92 ] ;
struct V_105 * V_97 = & V_87 -> V_97 ;
T_1 * V_73 ;
if ( ! V_97 -> V_98 || V_104 == V_99 )
return 0 ;
if ( F_30 ( V_72 ) < 2 + sizeof( struct V_106 ) )
return - V_52 ;
V_73 = F_31 ( V_72 , 2 + sizeof( struct V_106 ) ) ;
F_42 ( V_73 , V_97 , V_91 , V_104 ) ;
return 0 ;
}
static void F_43 ( unsigned long V_11 )
{
struct V_12 * V_13 =
(struct V_12 * ) V_11 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_14 * V_15 = V_13 -> V_15 ;
if ( V_15 -> V_21 ) {
F_9 ( V_107 , & V_17 -> V_23 ) ;
return;
}
F_10 ( & V_15 -> V_24 , & V_13 -> V_25 ) ;
}
static void F_44 ( unsigned long V_11 )
{
struct V_12 * V_13 =
(struct V_12 * ) V_11 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_14 * V_15 = V_13 -> V_15 ;
F_9 ( V_108 , & V_17 -> V_20 ) ;
if ( V_15 -> V_21 ) {
F_9 ( V_109 , & V_17 -> V_23 ) ;
return;
}
F_10 ( & V_15 -> V_24 , & V_13 -> V_25 ) ;
}
void F_45 ( struct V_16 * V_17 )
{
if ( V_17 -> V_110 . V_111 )
F_9 ( V_108 , & V_17 -> V_20 ) ;
else {
F_46 ( V_108 , & V_17 -> V_20 ) ;
F_47 ( & V_17 -> V_112 ) ;
}
}
int F_48 ( struct V_113 * V_114 , T_3 * V_115 ,
const T_1 * V_116 , const T_1 * V_117 )
{
if ( F_49 ( V_116 ) ) {
* V_115 |= F_50 ( V_118 ) ;
memcpy ( V_114 -> V_119 , V_116 , V_68 ) ;
memcpy ( V_114 -> V_120 , V_117 , V_68 ) ;
memcpy ( V_114 -> V_121 , V_117 , V_68 ) ;
return 24 ;
} else {
* V_115 |= F_50 ( V_118 | V_122 ) ;
memset ( V_114 -> V_119 , 0 , V_68 ) ;
memcpy ( V_114 -> V_120 , V_117 , V_68 ) ;
memcpy ( V_114 -> V_121 , V_116 , V_68 ) ;
memcpy ( V_114 -> V_123 , V_117 , V_68 ) ;
return 30 ;
}
}
int F_51 ( struct V_60 * V_124 ,
struct V_12 * V_13 , char * V_125 ,
char * V_126 )
{
int V_127 = 0 ;
F_52 ( ! V_125 && V_126 ) ;
memset ( V_124 , 0 , sizeof( * V_124 ) ) ;
V_124 -> V_128 = V_13 -> V_3 . V_18 . V_110 . V_129 ;
F_53 ( F_54 ( V_13 -> V_3 . V_18 . V_130 ) , & V_124 -> V_62 ) ;
V_13 -> V_3 . V_18 . V_130 ++ ;
if ( V_125 && ! V_126 ) {
V_124 -> V_131 |= V_132 ;
V_127 += V_68 ;
memcpy ( V_124 -> V_133 , V_125 , V_68 ) ;
} else if ( V_125 && V_126 ) {
V_124 -> V_131 |= V_134 ;
V_127 += 2 * V_68 ;
memcpy ( V_124 -> V_133 , V_125 , V_68 ) ;
memcpy ( V_124 -> V_135 , V_126 , V_68 ) ;
}
return 6 + V_127 ;
}
static void F_55 ( struct V_12 * V_13 ,
struct V_16 * V_17 )
{
bool V_46 ;
#ifdef F_56
F_57 ( V_136 L_2 ,
V_13 -> V_137 ) ;
#endif
F_58 ( V_13 , V_138 ) ;
F_59 ( V_13 ) ;
V_46 = F_15 ( V_13 ) ;
if ( V_46 != V_13 -> V_3 . V_18 . V_47 )
F_60 ( V_13 , V_139 ) ;
F_61 ( & V_17 -> V_140 ,
F_62 ( V_65 + V_141 ) ) ;
}
static void F_63 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
F_64 ( V_13 ) ;
F_61 ( & V_17 -> V_112 ,
F_62 ( F_65 (
V_17 -> V_110 . V_142 ) ) ) ;
}
void F_66 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
if ( F_47 ( & V_17 -> V_140 ) )
F_9 ( V_22 , & V_17 -> V_23 ) ;
if ( F_47 ( & V_17 -> V_143 ) )
F_9 ( V_107 , & V_17 -> V_23 ) ;
if ( F_47 ( & V_17 -> V_112 ) )
F_9 ( V_109 , & V_17 -> V_23 ) ;
}
void F_67 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
if ( F_68 ( V_22 , & V_17 -> V_23 ) )
F_69 ( & V_17 -> V_140 ) ;
if ( F_68 ( V_107 , & V_17 -> V_23 ) )
F_69 ( & V_17 -> V_143 ) ;
if ( F_68 ( V_109 , & V_17 -> V_23 ) )
F_69 ( & V_17 -> V_112 ) ;
F_45 ( V_17 ) ;
}
void F_70 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_14 * V_15 = V_13 -> V_15 ;
V_15 -> V_144 ++ ;
F_71 ( & V_15 -> V_145 ) ;
F_72 ( V_15 ) ;
V_17 -> V_35 = 0 ;
V_17 -> V_37 = 0 ;
V_17 -> V_39 = 0 ;
F_9 ( V_19 , & V_17 -> V_20 ) ;
F_45 ( V_17 ) ;
F_10 ( & V_15 -> V_24 , & V_13 -> V_25 ) ;
V_13 -> V_146 . V_147 . V_148 = V_149 ;
F_60 ( V_13 , V_139 |
V_150 |
V_151 ) ;
}
void F_73 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
V_17 -> V_28 = 0 ;
F_60 ( V_13 , V_150 ) ;
F_74 ( V_15 , NULL ) ;
F_47 ( & V_13 -> V_3 . V_18 . V_140 ) ;
F_47 ( & V_13 -> V_3 . V_18 . V_112 ) ;
F_75 ( & V_13 -> V_25 ) ;
V_15 -> V_144 -- ;
F_76 ( & V_15 -> V_145 ) ;
F_72 ( V_15 ) ;
}
static void F_77 ( struct V_12 * V_13 ,
T_4 V_152 ,
struct V_1 * V_2 ,
T_5 V_83 ,
struct V_153 * V_154 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_26 V_155 ;
struct V_102 * V_91 ;
T_2 V_156 = 0 ;
T_5 V_157 ;
int V_158 ;
enum V_159 V_92 = V_154 -> V_92 ;
if ( V_152 == V_160 &&
F_78 ( V_2 -> V_161 , V_13 -> V_146 . V_162 ) )
return;
V_157 = ( T_1 * ) V_2 -> V_3 . V_163 . V_164 - ( T_1 * ) V_2 ;
if ( V_157 > V_83 )
return;
F_79 ( V_2 -> V_3 . V_163 . V_164 , V_83 - V_157 ,
& V_155 ) ;
if ( V_155 . V_165 && V_13 -> V_3 . V_18 . V_166 == V_167 )
return;
if ( V_155 . V_168 && V_155 . V_169 == 1 )
V_158 = F_80 ( V_155 . V_168 [ 0 ] , V_92 ) ;
else
V_158 = V_154 -> V_158 ;
V_91 = F_81 ( V_15 -> V_24 . V_88 , V_158 ) ;
if ( ! V_91 || V_91 -> V_131 & V_170 )
return;
if ( V_155 . V_29 && V_155 . V_31 &&
F_11 ( & V_155 , V_13 ) ) {
V_156 = F_82 ( V_15 , & V_155 , V_92 ) ;
F_83 ( V_2 -> V_59 , V_156 , V_13 , & V_155 ) ;
}
}
static void F_84 ( struct V_12 * V_13 ,
struct V_1 * V_2 ,
T_5 V_83 ,
struct V_153 * V_154 )
{
switch ( V_2 -> V_3 . V_4 . V_171 ) {
case V_172 :
switch ( V_2 -> V_3 . V_4 . V_3 . V_173 . V_6 ) {
case V_174 :
case V_175 :
case V_176 :
F_85 ( V_13 , V_2 , V_83 , V_154 ) ;
break;
}
break;
case V_177 :
if ( F_1 ( V_2 ) )
F_86 ( V_13 , V_2 , V_83 ) ;
break;
}
}
void F_87 ( struct V_12 * V_13 ,
struct V_71 * V_72 )
{
struct V_153 * V_154 ;
struct V_1 * V_2 ;
T_4 V_152 ;
V_154 = F_88 ( V_72 ) ;
V_2 = (struct V_1 * ) V_72 -> V_11 ;
V_152 = F_89 ( V_2 -> V_178 ) & V_179 ;
switch ( V_152 ) {
case V_160 :
case V_180 :
F_77 ( V_13 , V_152 , V_2 , V_72 -> V_83 ,
V_154 ) ;
break;
case V_181 :
F_84 ( V_13 , V_2 , V_72 -> V_83 , V_154 ) ;
break;
}
}
void F_90 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
if ( V_17 -> V_182 &&
F_26 ( V_65 ,
V_17 -> V_183 + F_91 ( V_17 -> V_110 . V_184 ) ) )
F_92 ( V_13 ) ;
if ( F_68 ( V_185 , & V_17 -> V_20 ) )
F_93 () ;
if ( F_68 ( V_186 , & V_17 -> V_20 ) )
F_94 () ;
if ( F_68 ( V_19 , & V_17 -> V_20 ) )
F_55 ( V_13 , V_17 ) ;
if ( F_68 ( V_108 , & V_17 -> V_20 ) )
F_63 ( V_13 ) ;
}
void F_95 ( struct V_14 * V_15 )
{
struct V_12 * V_13 ;
F_96 () ;
F_97 (sdata, &local->interfaces, list)
if ( F_98 ( & V_13 -> V_146 ) )
F_10 ( & V_15 -> V_24 , & V_13 -> V_25 ) ;
F_99 () ;
}
void F_100 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
F_101 ( & V_17 -> V_140 ,
F_8 ,
( unsigned long ) V_13 ) ;
V_17 -> V_47 = true ;
V_17 -> V_187 = 0 ;
V_17 -> V_188 = 0 ;
V_17 -> V_189 = 0 ;
F_102 ( & V_17 -> V_190 , 0 ) ;
F_16 ( V_13 ) ;
V_17 -> V_183 = V_65 ;
V_17 -> V_191 = V_65 ;
if ( ! V_8 )
F_2 () ;
F_101 ( & V_17 -> V_143 ,
F_43 ,
( unsigned long ) V_13 ) ;
F_101 ( & V_17 -> V_112 ,
F_44 ,
( unsigned long ) V_13 ) ;
F_18 ( & V_17 -> V_192 . V_56 ) ;
F_103 ( & V_17 -> V_193 ) ;
}
