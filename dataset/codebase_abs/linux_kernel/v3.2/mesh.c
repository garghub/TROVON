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
if ( V_17 -> V_28 == V_27 -> V_28 &&
memcmp ( V_17 -> V_29 , V_27 -> V_29 , V_27 -> V_28 ) == 0 &&
( V_17 -> V_30 == V_27 -> V_31 -> V_32 ) &&
( V_17 -> V_33 == V_27 -> V_31 -> V_34 ) &&
( V_17 -> V_35 == V_27 -> V_31 -> V_36 ) &&
( V_17 -> V_37 == V_27 -> V_31 -> V_38 ) &&
( V_17 -> V_39 == V_27 -> V_31 -> V_40 ) )
return true ;
return false ;
}
bool F_12 ( struct V_26 * V_27 )
{
return ( V_27 -> V_31 -> V_41 &
V_42 ) != 0 ;
}
void F_13 ( struct V_12 * V_13 )
{
bool V_43 ;
V_43 = F_14 ( V_13 ) ;
if ( V_43 != V_13 -> V_3 . V_18 . V_44 )
F_8 ( ( unsigned long ) V_13 ) ;
}
int F_15 ( struct V_12 * V_13 )
{
int V_45 ;
V_13 -> V_3 . V_18 . V_46 = F_16 ( sizeof( struct V_47 ) , V_48 ) ;
if ( ! V_13 -> V_3 . V_18 . V_46 )
return - V_49 ;
V_13 -> V_3 . V_18 . V_46 -> V_50 = V_51 - 1 ;
for ( V_45 = 0 ; V_45 < V_51 ; V_45 ++ )
F_17 ( & V_13 -> V_3 . V_18 . V_46 -> V_52 [ V_45 ] . V_53 ) ;
return 0 ;
}
void F_18 ( struct V_12 * V_13 )
{
struct V_47 * V_46 = V_13 -> V_3 . V_18 . V_46 ;
struct V_10 * V_54 , * V_55 ;
int V_45 ;
if ( ! V_13 -> V_3 . V_18 . V_46 )
return;
for ( V_45 = 0 ; V_45 < V_51 ; V_45 ++ )
F_19 (p, n, &rmc->bucket[i].list, list) {
F_20 ( & V_54 -> V_53 ) ;
F_21 ( V_9 , V_54 ) ;
}
F_22 ( V_46 ) ;
V_13 -> V_3 . V_18 . V_46 = NULL ;
}
int F_23 ( T_1 * V_56 , struct V_57 * V_58 ,
struct V_12 * V_13 )
{
struct V_47 * V_46 = V_13 -> V_3 . V_18 . V_46 ;
T_2 V_59 = 0 ;
int V_60 = 0 ;
T_1 V_61 ;
struct V_10 * V_54 , * V_55 ;
memcpy ( & V_59 , & V_58 -> V_59 , sizeof( V_58 -> V_59 ) ) ;
V_61 = F_24 ( V_58 -> V_59 ) & V_46 -> V_50 ;
F_19 (p, n, &rmc->bucket[idx].list, list) {
++ V_60 ;
if ( F_25 ( V_62 , V_54 -> V_63 ) ||
( V_60 == V_64 ) ) {
F_20 ( & V_54 -> V_53 ) ;
F_21 ( V_9 , V_54 ) ;
-- V_60 ;
} else if ( ( V_59 == V_54 -> V_59 ) &&
( memcmp ( V_56 , V_54 -> V_56 , V_65 ) == 0 ) )
return - 1 ;
}
V_54 = F_26 ( V_9 , V_66 ) ;
if ( ! V_54 )
return 0 ;
V_54 -> V_59 = V_59 ;
V_54 -> V_63 = V_62 + V_67 ;
memcpy ( V_54 -> V_56 , V_56 , V_65 ) ;
F_27 ( & V_54 -> V_53 , & V_46 -> V_52 [ V_61 ] . V_53 ) ;
return 0 ;
}
int
F_28 ( struct V_68 * V_69 , struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 * V_70 , V_71 ;
T_1 V_72 = sizeof( struct V_73 ) ;
if ( F_29 ( V_69 ) < 2 + V_72 )
return - V_49 ;
V_70 = F_30 ( V_69 , 2 + V_72 ) ;
* V_70 ++ = V_74 ;
* V_70 ++ = V_72 ;
* V_70 ++ = V_17 -> V_30 ;
* V_70 ++ = V_17 -> V_33 ;
* V_70 ++ = V_17 -> V_35 ;
* V_70 ++ = V_17 -> V_37 ;
* V_70 ++ = V_17 -> V_39 ;
V_71 = F_31 ( & V_17 -> V_75 . V_76 ) ;
V_71 = ( V_71 > 15 ) ? 15 : V_71 ;
* V_70 ++ = V_71 << 1 ;
V_17 -> V_44 = F_14 ( V_13 ) ;
* V_70 = V_77 ;
* V_70 ++ |= V_17 -> V_44 ?
V_42 : 0x00 ;
* V_70 ++ = 0x00 ;
return 0 ;
}
int
F_32 ( struct V_68 * V_69 , struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 * V_70 ;
if ( F_29 ( V_69 ) < 2 + V_17 -> V_28 )
return - V_49 ;
V_70 = F_30 ( V_69 , 2 + V_17 -> V_28 ) ;
* V_70 ++ = V_78 ;
* V_70 ++ = V_17 -> V_28 ;
if ( V_17 -> V_28 )
memcpy ( V_70 , V_17 -> V_29 , V_17 -> V_28 ) ;
return 0 ;
}
int
F_33 ( struct V_68 * V_69 , struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 V_79 , V_80 ;
const T_1 * V_11 ;
if ( ! V_17 -> V_27 || ! V_17 -> V_81 )
return 0 ;
V_79 = F_34 ( V_17 -> V_27 , V_17 -> V_81 , 0 ) ;
if ( V_79 ) {
V_80 = V_17 -> V_81 - V_79 ;
V_11 = V_17 -> V_27 + V_79 ;
if ( F_29 ( V_69 ) < V_80 )
return - V_49 ;
memcpy ( F_30 ( V_69 , V_80 ) , V_11 , V_80 ) ;
}
return 0 ;
}
int
F_35 ( struct V_68 * V_69 , struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
T_1 V_80 = 0 ;
const T_1 * V_11 ;
if ( ! V_17 -> V_27 || ! V_17 -> V_81 )
return 0 ;
V_11 = V_17 -> V_27 ;
while ( V_11 < V_17 -> V_27 + V_17 -> V_81 ) {
if ( * V_11 == V_82 ) {
V_80 = V_11 [ 1 ] + 2 ;
break;
}
V_11 ++ ;
}
if ( V_80 ) {
if ( F_29 ( V_69 ) < V_80 )
return - V_49 ;
memcpy ( F_30 ( V_69 , V_80 ) , V_11 , V_80 ) ;
}
return 0 ;
}
int F_36 ( struct V_68 * V_69 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_83 * V_84 ;
T_1 * V_70 ;
if ( F_29 ( V_69 ) < 3 )
return - V_49 ;
V_84 = V_15 -> V_24 . V_85 -> V_86 [ V_15 -> V_24 . V_87 . V_88 -> V_89 ] ;
if ( V_84 -> V_89 == V_90 ) {
V_70 = F_30 ( V_69 , 2 + 1 ) ;
* V_70 ++ = V_91 ;
* V_70 ++ = 1 ;
* V_70 ++ = F_37 ( V_15 -> V_24 . V_87 . V_88 -> V_92 ) ;
}
return 0 ;
}
static void F_38 ( unsigned long V_11 )
{
struct V_12 * V_13 =
(struct V_12 * ) V_11 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_14 * V_15 = V_13 -> V_15 ;
if ( V_15 -> V_21 ) {
F_9 ( V_93 , & V_17 -> V_23 ) ;
return;
}
F_10 ( & V_15 -> V_24 , & V_13 -> V_25 ) ;
}
static void F_39 ( unsigned long V_11 )
{
struct V_12 * V_13 =
(struct V_12 * ) V_11 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_14 * V_15 = V_13 -> V_15 ;
F_9 ( V_94 , & V_17 -> V_20 ) ;
if ( V_15 -> V_21 ) {
F_9 ( V_95 , & V_17 -> V_23 ) ;
return;
}
F_10 ( & V_15 -> V_24 , & V_13 -> V_25 ) ;
}
void F_40 ( struct V_16 * V_17 )
{
if ( V_17 -> V_96 . V_97 )
F_9 ( V_94 , & V_17 -> V_20 ) ;
else {
F_41 ( V_94 , & V_17 -> V_20 ) ;
F_42 ( & V_17 -> V_98 ) ;
}
}
int F_43 ( struct V_99 * V_100 , T_3 * V_101 ,
const T_1 * V_102 , const T_1 * V_103 )
{
if ( F_44 ( V_102 ) ) {
* V_101 |= F_45 ( V_104 ) ;
memcpy ( V_100 -> V_105 , V_102 , V_65 ) ;
memcpy ( V_100 -> V_106 , V_103 , V_65 ) ;
memcpy ( V_100 -> V_107 , V_103 , V_65 ) ;
return 24 ;
} else {
* V_101 |= F_45 ( V_104 | V_108 ) ;
memset ( V_100 -> V_105 , 0 , V_65 ) ;
memcpy ( V_100 -> V_106 , V_103 , V_65 ) ;
memcpy ( V_100 -> V_107 , V_102 , V_65 ) ;
memcpy ( V_100 -> V_109 , V_103 , V_65 ) ;
return 30 ;
}
}
int F_46 ( struct V_57 * V_110 ,
struct V_12 * V_13 , char * V_111 ,
char * V_112 )
{
int V_113 = 0 ;
F_47 ( ! V_111 && V_112 ) ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
V_110 -> V_114 = V_13 -> V_3 . V_18 . V_96 . V_115 ;
F_48 ( F_49 ( V_13 -> V_3 . V_18 . V_116 ) , & V_110 -> V_59 ) ;
V_13 -> V_3 . V_18 . V_116 ++ ;
if ( V_111 && ! V_112 ) {
V_110 -> V_117 |= V_118 ;
V_113 += V_65 ;
memcpy ( V_110 -> V_119 , V_111 , V_65 ) ;
} else if ( V_111 && V_112 ) {
V_110 -> V_117 |= V_120 ;
V_113 += 2 * V_65 ;
memcpy ( V_110 -> V_119 , V_111 , V_65 ) ;
memcpy ( V_110 -> V_121 , V_112 , V_65 ) ;
}
return 6 + V_113 ;
}
static void F_50 ( struct V_12 * V_13 ,
struct V_16 * V_17 )
{
bool V_43 ;
#ifdef F_51
F_52 ( V_122 L_2 ,
V_13 -> V_123 ) ;
#endif
F_53 ( V_13 , V_124 ) ;
F_54 ( V_13 ) ;
V_43 = F_14 ( V_13 ) ;
if ( V_43 != V_13 -> V_3 . V_18 . V_44 )
F_55 ( V_13 , V_125 ) ;
F_56 ( & V_17 -> V_126 ,
F_57 ( V_62 + V_127 ) ) ;
}
static void F_58 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
F_59 ( V_13 ) ;
F_56 ( & V_17 -> V_98 ,
F_57 ( F_60 (
V_17 -> V_96 . V_128 ) ) ) ;
}
void F_61 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
if ( F_42 ( & V_17 -> V_126 ) )
F_9 ( V_22 , & V_17 -> V_23 ) ;
if ( F_42 ( & V_17 -> V_129 ) )
F_9 ( V_93 , & V_17 -> V_23 ) ;
if ( F_42 ( & V_17 -> V_98 ) )
F_9 ( V_95 , & V_17 -> V_23 ) ;
}
void F_62 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
if ( F_63 ( V_22 , & V_17 -> V_23 ) )
F_64 ( & V_17 -> V_126 ) ;
if ( F_63 ( V_93 , & V_17 -> V_23 ) )
F_64 ( & V_17 -> V_129 ) ;
if ( F_63 ( V_95 , & V_17 -> V_23 ) )
F_64 ( & V_17 -> V_98 ) ;
F_40 ( V_17 ) ;
}
void F_65 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
struct V_14 * V_15 = V_13 -> V_15 ;
V_15 -> V_130 ++ ;
F_66 ( & V_15 -> V_131 ) ;
F_67 ( V_15 ) ;
V_17 -> V_35 = 0 ;
V_17 -> V_37 = 0 ;
V_17 -> V_39 = 0 ;
F_9 ( V_19 , & V_17 -> V_20 ) ;
F_40 ( V_17 ) ;
F_10 ( & V_15 -> V_24 , & V_13 -> V_25 ) ;
V_13 -> V_132 . V_133 . V_134 = V_135 ;
F_55 ( V_13 , V_125 |
V_136 |
V_137 ) ;
}
void F_68 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
V_17 -> V_28 = 0 ;
F_55 ( V_13 , V_136 ) ;
F_69 ( V_15 , NULL ) ;
F_42 ( & V_13 -> V_3 . V_18 . V_126 ) ;
F_42 ( & V_13 -> V_3 . V_18 . V_98 ) ;
F_70 ( & V_13 -> V_25 ) ;
V_15 -> V_130 -- ;
F_71 ( & V_15 -> V_131 ) ;
F_67 ( V_15 ) ;
}
static void F_72 ( struct V_12 * V_13 ,
T_4 V_138 ,
struct V_1 * V_2 ,
T_5 V_80 ,
struct V_139 * V_140 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_26 V_141 ;
struct V_142 * V_88 ;
T_2 V_143 = 0 ;
T_5 V_144 ;
int V_145 ;
enum V_146 V_89 = V_140 -> V_89 ;
if ( V_138 == V_147 &&
F_73 ( V_2 -> V_148 , V_13 -> V_132 . V_149 ) )
return;
V_144 = ( T_1 * ) V_2 -> V_3 . V_150 . V_151 - ( T_1 * ) V_2 ;
if ( V_144 > V_80 )
return;
F_74 ( V_2 -> V_3 . V_150 . V_151 , V_80 - V_144 ,
& V_141 ) ;
if ( V_141 . V_152 && V_13 -> V_3 . V_18 . V_153 == V_154 )
return;
if ( V_141 . V_155 && V_141 . V_156 == 1 )
V_145 = F_75 ( V_141 . V_155 [ 0 ] , V_89 ) ;
else
V_145 = V_140 -> V_145 ;
V_88 = F_76 ( V_15 -> V_24 . V_85 , V_145 ) ;
if ( ! V_88 || V_88 -> V_117 & V_157 )
return;
if ( V_141 . V_29 && V_141 . V_31 &&
F_11 ( & V_141 , V_13 ) ) {
V_143 = F_77 ( V_15 , & V_141 , V_89 ) ;
F_78 ( V_2 -> V_56 , V_143 , V_13 , & V_141 ) ;
}
}
static void F_79 ( struct V_12 * V_13 ,
struct V_1 * V_2 ,
T_5 V_80 ,
struct V_139 * V_140 )
{
switch ( V_2 -> V_3 . V_4 . V_158 ) {
case V_159 :
switch ( V_2 -> V_3 . V_4 . V_3 . V_160 . V_6 ) {
case V_161 :
case V_162 :
case V_163 :
F_80 ( V_13 , V_2 , V_80 , V_140 ) ;
break;
}
break;
case V_164 :
if ( F_1 ( V_2 ) )
F_81 ( V_13 , V_2 , V_80 ) ;
break;
}
}
void F_82 ( struct V_12 * V_13 ,
struct V_68 * V_69 )
{
struct V_139 * V_140 ;
struct V_1 * V_2 ;
T_4 V_138 ;
V_140 = F_83 ( V_69 ) ;
V_2 = (struct V_1 * ) V_69 -> V_11 ;
V_138 = F_84 ( V_2 -> V_165 ) & V_166 ;
switch ( V_138 ) {
case V_147 :
case V_167 :
F_72 ( V_13 , V_138 , V_2 , V_69 -> V_80 ,
V_140 ) ;
break;
case V_168 :
F_79 ( V_13 , V_2 , V_69 -> V_80 , V_140 ) ;
break;
}
}
void F_85 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
if ( V_17 -> V_169 &&
F_25 ( V_62 ,
V_17 -> V_170 + F_86 ( V_17 -> V_96 . V_171 ) ) )
F_87 ( V_13 ) ;
if ( F_63 ( V_172 , & V_17 -> V_20 ) )
F_88 () ;
if ( F_63 ( V_173 , & V_17 -> V_20 ) )
F_89 () ;
if ( F_63 ( V_19 , & V_17 -> V_20 ) )
F_50 ( V_13 , V_17 ) ;
if ( F_63 ( V_94 , & V_17 -> V_20 ) )
F_58 ( V_13 ) ;
}
void F_90 ( struct V_14 * V_15 )
{
struct V_12 * V_13 ;
F_91 () ;
F_92 (sdata, &local->interfaces, list)
if ( F_93 ( & V_13 -> V_132 ) )
F_10 ( & V_15 -> V_24 , & V_13 -> V_25 ) ;
F_94 () ;
}
void F_95 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = & V_13 -> V_3 . V_18 ;
F_96 ( & V_17 -> V_126 ,
F_8 ,
( unsigned long ) V_13 ) ;
V_17 -> V_44 = true ;
V_17 -> V_174 = 0 ;
V_17 -> V_175 = 0 ;
V_17 -> V_176 = 0 ;
F_97 ( & V_17 -> V_177 , 0 ) ;
F_15 ( V_13 ) ;
V_17 -> V_170 = V_62 ;
if ( ! V_8 )
F_2 () ;
F_96 ( & V_17 -> V_129 ,
F_38 ,
( unsigned long ) V_13 ) ;
F_96 ( & V_17 -> V_98 ,
F_39 ,
( unsigned long ) V_13 ) ;
F_17 ( & V_17 -> V_178 . V_53 ) ;
F_98 ( & V_17 -> V_179 ) ;
}
