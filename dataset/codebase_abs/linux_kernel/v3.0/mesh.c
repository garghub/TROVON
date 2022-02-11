void F_1 ( void )
{
F_2 () ;
V_1 = 1 ;
V_2 = F_3 ( L_1 , sizeof( struct V_3 ) ,
0 , 0 , NULL ) ;
}
void F_4 ( void )
{
F_5 () ;
F_6 ( V_2 ) ;
}
static void F_7 ( unsigned long V_4 )
{
struct V_5 * V_6 = ( void * ) V_4 ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = & V_6 -> V_11 . V_12 ;
F_8 ( V_13 , & V_10 -> V_14 ) ;
if ( V_8 -> V_15 ) {
F_8 ( V_16 , & V_10 -> V_17 ) ;
return;
}
F_9 ( & V_8 -> V_18 , & V_6 -> V_19 ) ;
}
bool F_10 ( struct V_20 * V_21 , struct V_5 * V_6 )
{
struct V_9 * V_10 = & V_6 -> V_11 . V_12 ;
if ( V_10 -> V_22 == V_21 -> V_22 &&
memcmp ( V_10 -> V_23 , V_21 -> V_23 , V_21 -> V_22 ) == 0 &&
( V_10 -> V_24 == V_21 -> V_25 -> V_26 ) &&
( V_10 -> V_27 == V_21 -> V_25 -> V_28 ) &&
( V_10 -> V_29 == V_21 -> V_25 -> V_30 ) &&
( V_10 -> V_31 == V_21 -> V_25 -> V_32 ) &&
( V_10 -> V_33 == V_21 -> V_25 -> V_34 ) )
return true ;
return false ;
}
bool F_11 ( struct V_20 * V_21 )
{
return ( V_21 -> V_25 -> V_35 &
V_36 ) != 0 ;
}
void F_12 ( struct V_5 * V_6 )
{
bool V_37 ;
V_37 = F_13 ( V_6 ) ;
if ( V_37 != V_6 -> V_11 . V_12 . V_38 )
F_7 ( ( unsigned long ) V_6 ) ;
}
int F_14 ( struct V_5 * V_6 )
{
int V_39 ;
V_6 -> V_11 . V_12 . V_40 = F_15 ( sizeof( struct V_41 ) , V_42 ) ;
if ( ! V_6 -> V_11 . V_12 . V_40 )
return - V_43 ;
V_6 -> V_11 . V_12 . V_40 -> V_44 = V_45 - 1 ;
for ( V_39 = 0 ; V_39 < V_45 ; V_39 ++ )
F_16 ( & V_6 -> V_11 . V_12 . V_40 -> V_46 [ V_39 ] . V_47 ) ;
return 0 ;
}
void F_17 ( struct V_5 * V_6 )
{
struct V_41 * V_40 = V_6 -> V_11 . V_12 . V_40 ;
struct V_3 * V_48 , * V_49 ;
int V_39 ;
if ( ! V_6 -> V_11 . V_12 . V_40 )
return;
for ( V_39 = 0 ; V_39 < V_45 ; V_39 ++ )
F_18 (p, n, &rmc->bucket[i].list, list) {
F_19 ( & V_48 -> V_47 ) ;
F_20 ( V_2 , V_48 ) ;
}
F_21 ( V_40 ) ;
V_6 -> V_11 . V_12 . V_40 = NULL ;
}
int F_22 ( T_1 * V_50 , struct V_51 * V_52 ,
struct V_5 * V_6 )
{
struct V_41 * V_40 = V_6 -> V_11 . V_12 . V_40 ;
T_2 V_53 = 0 ;
int V_54 = 0 ;
T_1 V_55 ;
struct V_3 * V_48 , * V_49 ;
memcpy ( & V_53 , & V_52 -> V_53 , sizeof( V_52 -> V_53 ) ) ;
V_55 = F_23 ( V_52 -> V_53 ) & V_40 -> V_44 ;
F_18 (p, n, &rmc->bucket[idx].list, list) {
++ V_54 ;
if ( F_24 ( V_56 , V_48 -> V_57 ) ||
( V_54 == V_58 ) ) {
F_19 ( & V_48 -> V_47 ) ;
F_20 ( V_2 , V_48 ) ;
-- V_54 ;
} else if ( ( V_53 == V_48 -> V_53 ) &&
( memcmp ( V_50 , V_48 -> V_50 , V_59 ) == 0 ) )
return - 1 ;
}
V_48 = F_25 ( V_2 , V_60 ) ;
if ( ! V_48 ) {
F_26 ( V_61 L_2 ) ;
return 0 ;
}
V_48 -> V_53 = V_53 ;
V_48 -> V_57 = V_56 + V_62 ;
memcpy ( V_48 -> V_50 , V_50 , V_59 ) ;
F_27 ( & V_48 -> V_47 , & V_40 -> V_46 [ V_55 ] . V_47 ) ;
return 0 ;
}
void F_28 ( struct V_63 * V_64 , struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_65 * V_66 ;
T_1 * V_67 ;
int V_68 , V_39 , V_69 ;
T_1 V_70 ;
V_66 = V_8 -> V_18 . V_71 -> V_72 [ V_8 -> V_18 . V_73 . V_74 -> V_75 ] ;
V_68 = V_66 -> V_76 ;
if ( V_68 > 8 )
V_68 = 8 ;
V_67 = F_29 ( V_64 , V_68 + 2 ) ;
* V_67 ++ = V_77 ;
* V_67 ++ = V_68 ;
for ( V_39 = 0 ; V_39 < V_68 ; V_39 ++ ) {
V_69 = V_66 -> V_78 [ V_39 ] . V_79 ;
* V_67 ++ = ( T_1 ) ( V_69 / 5 ) ;
}
if ( V_66 -> V_76 > V_68 ) {
V_67 = F_29 ( V_64 , V_66 -> V_76 - V_68 + 2 ) ;
* V_67 ++ = V_80 ;
* V_67 ++ = V_66 -> V_76 - V_68 ;
for ( V_39 = V_68 ; V_39 < V_66 -> V_76 ; V_39 ++ ) {
V_69 = V_66 -> V_78 [ V_39 ] . V_79 ;
* V_67 ++ = ( T_1 ) ( V_69 / 5 ) ;
}
}
if ( V_66 -> V_75 == V_81 ) {
V_67 = F_29 ( V_64 , 2 + 1 ) ;
* V_67 ++ = V_82 ;
* V_67 ++ = 1 ;
* V_67 ++ = F_30 ( V_8 -> V_18 . V_73 . V_74 -> V_83 ) ;
}
V_67 = F_29 ( V_64 , 2 + V_6 -> V_11 . V_12 . V_22 ) ;
* V_67 ++ = V_84 ;
* V_67 ++ = V_6 -> V_11 . V_12 . V_22 ;
if ( V_6 -> V_11 . V_12 . V_22 )
memcpy ( V_67 , V_6 -> V_11 . V_12 . V_23 , V_6 -> V_11 . V_12 . V_22 ) ;
V_67 = F_29 ( V_64 , 2 + sizeof( struct V_85 ) ) ;
* V_67 ++ = V_86 ;
* V_67 ++ = sizeof( struct V_85 ) ;
* V_67 ++ = V_6 -> V_11 . V_12 . V_24 ;
* V_67 ++ = V_6 -> V_11 . V_12 . V_27 ;
* V_67 ++ = V_6 -> V_11 . V_12 . V_29 ;
* V_67 ++ = V_6 -> V_11 . V_12 . V_31 ;
* V_67 ++ = V_6 -> V_11 . V_12 . V_33 ;
V_70 = F_31 ( & V_6 -> V_11 . V_12 . V_87 . V_88 ) ;
V_70 = ( V_70 > 15 ) ? 15 : V_70 ;
* V_67 ++ = V_70 << 1 ;
V_6 -> V_11 . V_12 . V_38 = F_13 ( V_6 ) ;
* V_67 = V_89 ;
* V_67 ++ |= V_6 -> V_11 . V_12 . V_38 ?
V_36 : 0x00 ;
* V_67 ++ = 0x00 ;
if ( V_6 -> V_11 . V_12 . V_21 ) {
int V_68 = V_6 -> V_11 . V_12 . V_90 ;
const T_1 * V_4 = V_6 -> V_11 . V_12 . V_21 ;
if ( F_32 ( V_64 ) > V_68 )
memcpy ( F_29 ( V_64 , V_68 ) , V_4 , V_68 ) ;
}
}
static void F_33 ( unsigned long V_4 )
{
struct V_5 * V_6 =
(struct V_5 * ) V_4 ;
struct V_9 * V_10 = & V_6 -> V_11 . V_12 ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_8 -> V_15 ) {
F_8 ( V_91 , & V_10 -> V_17 ) ;
return;
}
F_9 ( & V_8 -> V_18 , & V_6 -> V_19 ) ;
}
static void F_34 ( unsigned long V_4 )
{
struct V_5 * V_6 =
(struct V_5 * ) V_4 ;
struct V_9 * V_10 = & V_6 -> V_11 . V_12 ;
struct V_7 * V_8 = V_6 -> V_8 ;
F_8 ( V_92 , & V_10 -> V_14 ) ;
if ( V_8 -> V_15 ) {
F_8 ( V_93 , & V_10 -> V_17 ) ;
return;
}
F_9 ( & V_8 -> V_18 , & V_6 -> V_19 ) ;
}
void F_35 ( struct V_9 * V_10 )
{
if ( V_10 -> V_94 . V_95 )
F_8 ( V_92 , & V_10 -> V_14 ) ;
else {
F_36 ( V_92 , & V_10 -> V_14 ) ;
F_37 ( & V_10 -> V_96 ) ;
}
}
int F_38 ( struct V_97 * V_98 , T_3 * V_99 ,
const T_1 * V_100 , const T_1 * V_101 )
{
if ( F_39 ( V_100 ) ) {
* V_99 |= F_40 ( V_102 ) ;
memcpy ( V_98 -> V_103 , V_100 , V_59 ) ;
memcpy ( V_98 -> V_104 , V_101 , V_59 ) ;
memcpy ( V_98 -> V_105 , V_101 , V_59 ) ;
return 24 ;
} else {
* V_99 |= F_40 ( V_102 |
V_106 ) ;
memset ( V_98 -> V_103 , 0 , V_59 ) ;
memcpy ( V_98 -> V_104 , V_101 , V_59 ) ;
memcpy ( V_98 -> V_105 , V_100 , V_59 ) ;
memcpy ( V_98 -> V_107 , V_101 , V_59 ) ;
return 30 ;
}
}
int F_41 ( struct V_51 * V_108 ,
struct V_5 * V_6 , char * V_109 ,
char * V_110 )
{
int V_111 = 0 ;
F_42 ( ! V_109 && V_110 ) ;
memset ( V_108 , 0 , sizeof( * V_108 ) ) ;
V_108 -> V_112 = V_6 -> V_11 . V_12 . V_94 . V_113 ;
F_43 ( F_44 ( V_6 -> V_11 . V_12 . V_114 ) , & V_108 -> V_53 ) ;
V_6 -> V_11 . V_12 . V_114 ++ ;
if ( V_109 && ! V_110 ) {
V_108 -> V_115 |= V_116 ;
V_111 += V_59 ;
memcpy ( V_108 -> V_117 , V_109 , V_59 ) ;
} else if ( V_109 && V_110 ) {
V_108 -> V_115 |= V_118 ;
V_111 += 2 * V_59 ;
memcpy ( V_108 -> V_117 , V_109 , V_59 ) ;
memcpy ( V_108 -> V_119 , V_110 , V_59 ) ;
}
return 6 + V_111 ;
}
static void F_45 ( struct V_5 * V_6 ,
struct V_9 * V_10 )
{
bool V_37 ;
#ifdef F_46
F_26 ( V_61 L_3 ,
V_6 -> V_120 ) ;
#endif
F_47 ( V_6 , V_121 ) ;
F_48 ( V_6 ) ;
V_37 = F_13 ( V_6 ) ;
if ( V_37 != V_6 -> V_11 . V_12 . V_38 )
F_49 ( V_6 , V_122 ) ;
F_50 ( & V_10 -> V_123 ,
F_51 ( V_56 + V_124 ) ) ;
}
static void F_52 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = & V_6 -> V_11 . V_12 ;
F_53 ( V_6 ) ;
F_50 ( & V_10 -> V_96 ,
F_51 ( V_56 + V_125 ) ) ;
}
void F_54 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = & V_6 -> V_11 . V_12 ;
if ( F_37 ( & V_10 -> V_123 ) )
F_8 ( V_16 , & V_10 -> V_17 ) ;
if ( F_37 ( & V_10 -> V_126 ) )
F_8 ( V_91 , & V_10 -> V_17 ) ;
if ( F_37 ( & V_10 -> V_96 ) )
F_8 ( V_93 , & V_10 -> V_17 ) ;
}
void F_55 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = & V_6 -> V_11 . V_12 ;
if ( F_56 ( V_16 , & V_10 -> V_17 ) )
F_57 ( & V_10 -> V_123 ) ;
if ( F_56 ( V_91 , & V_10 -> V_17 ) )
F_57 ( & V_10 -> V_126 ) ;
if ( F_56 ( V_93 , & V_10 -> V_17 ) )
F_57 ( & V_10 -> V_96 ) ;
F_35 ( V_10 ) ;
}
void F_58 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = & V_6 -> V_11 . V_12 ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_127 ++ ;
F_59 ( & V_8 -> V_128 ) ;
F_60 ( V_8 ) ;
V_10 -> V_29 = 0 ;
V_10 -> V_31 = 0 ;
V_10 -> V_33 = 0 ;
F_8 ( V_13 , & V_10 -> V_14 ) ;
F_35 ( V_10 ) ;
F_9 ( & V_8 -> V_18 , & V_6 -> V_19 ) ;
V_6 -> V_129 . V_130 . V_131 = V_132 ;
F_49 ( V_6 , V_122 |
V_133 |
V_134 ) ;
}
void F_61 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = & V_6 -> V_11 . V_12 ;
V_10 -> V_22 = 0 ;
F_49 ( V_6 , V_133 ) ;
F_62 ( V_8 , NULL ) ;
F_37 ( & V_6 -> V_11 . V_12 . V_123 ) ;
F_37 ( & V_6 -> V_11 . V_12 . V_96 ) ;
F_63 ( & V_6 -> V_19 ) ;
V_8 -> V_127 -- ;
F_64 ( & V_8 -> V_128 ) ;
F_60 ( V_8 ) ;
}
static void F_65 ( struct V_5 * V_6 ,
T_4 V_135 ,
struct V_136 * V_137 ,
T_5 V_68 ,
struct V_138 * V_139 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_20 V_140 ;
struct V_141 * V_74 ;
T_2 V_142 = 0 ;
T_5 V_143 ;
int V_144 ;
enum V_145 V_75 = V_139 -> V_75 ;
if ( V_135 == V_146 &&
F_66 ( V_137 -> V_147 , V_6 -> V_129 . V_148 ) )
return;
V_143 = ( T_1 * ) V_137 -> V_11 . V_149 . V_150 - ( T_1 * ) V_137 ;
if ( V_143 > V_68 )
return;
F_67 ( V_137 -> V_11 . V_149 . V_150 , V_68 - V_143 ,
& V_140 ) ;
if ( V_140 . V_151 && V_6 -> V_11 . V_12 . V_152 == V_153 )
return;
if ( V_140 . V_154 && V_140 . V_155 == 1 )
V_144 = F_68 ( V_140 . V_154 [ 0 ] , V_75 ) ;
else
V_144 = V_139 -> V_144 ;
V_74 = F_69 ( V_8 -> V_18 . V_71 , V_144 ) ;
if ( ! V_74 || V_74 -> V_115 & V_156 )
return;
if ( V_140 . V_23 && V_140 . V_25 &&
F_10 ( & V_140 , V_6 ) ) {
V_142 = F_70 ( V_8 , & V_140 , V_75 ) ;
F_71 ( V_137 -> V_50 , V_142 , V_6 , & V_140 ) ;
}
}
static void F_72 ( struct V_5 * V_6 ,
struct V_136 * V_137 ,
T_5 V_68 ,
struct V_138 * V_139 )
{
switch ( V_137 -> V_11 . V_157 . V_158 ) {
case V_159 :
F_73 ( V_6 , V_137 , V_68 , V_139 ) ;
break;
case V_160 :
F_74 ( V_6 , V_137 , V_68 ) ;
break;
}
}
void F_75 ( struct V_5 * V_6 ,
struct V_63 * V_64 )
{
struct V_138 * V_139 ;
struct V_136 * V_137 ;
T_4 V_135 ;
V_139 = F_76 ( V_64 ) ;
V_137 = (struct V_136 * ) V_64 -> V_4 ;
V_135 = F_77 ( V_137 -> V_161 ) & V_162 ;
switch ( V_135 ) {
case V_146 :
case V_163 :
F_65 ( V_6 , V_135 , V_137 , V_64 -> V_68 ,
V_139 ) ;
break;
case V_164 :
F_72 ( V_6 , V_137 , V_64 -> V_68 , V_139 ) ;
break;
}
}
void F_78 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = & V_6 -> V_11 . V_12 ;
if ( V_10 -> V_165 &&
F_24 ( V_56 ,
V_10 -> V_166 + F_79 ( V_10 -> V_94 . V_167 ) ) )
F_80 ( V_6 ) ;
if ( F_56 ( V_168 , & V_10 -> V_14 ) )
F_81 () ;
if ( F_56 ( V_169 , & V_10 -> V_14 ) )
F_82 () ;
if ( F_56 ( V_13 , & V_10 -> V_14 ) )
F_45 ( V_6 , V_10 ) ;
if ( F_56 ( V_92 , & V_10 -> V_14 ) )
F_52 ( V_6 ) ;
}
void F_83 ( struct V_7 * V_8 )
{
struct V_5 * V_6 ;
F_84 () ;
F_85 (sdata, &local->interfaces, list)
if ( F_86 ( & V_6 -> V_129 ) )
F_9 ( & V_8 -> V_18 , & V_6 -> V_19 ) ;
F_87 () ;
}
void F_88 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = & V_6 -> V_11 . V_12 ;
F_89 ( & V_10 -> V_123 ,
F_7 ,
( unsigned long ) V_6 ) ;
V_10 -> V_38 = true ;
V_10 -> V_170 = 0 ;
V_10 -> V_171 = 0 ;
F_90 ( & V_10 -> V_172 , 0 ) ;
F_14 ( V_6 ) ;
V_10 -> V_166 = V_56 ;
if ( ! V_1 )
F_1 () ;
F_89 ( & V_10 -> V_126 ,
F_33 ,
( unsigned long ) V_6 ) ;
F_89 ( & V_10 -> V_96 ,
F_34 ,
( unsigned long ) V_6 ) ;
F_16 ( & V_10 -> V_173 . V_47 ) ;
F_91 ( & V_10 -> V_174 ) ;
}
