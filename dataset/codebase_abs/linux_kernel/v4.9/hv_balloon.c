static int F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_4 ;
unsigned long V_7 ;
switch ( V_3 ) {
case V_8 :
F_2 ( & V_9 . V_10 , V_7 ) ;
V_9 . V_11 += V_6 -> V_12 ;
F_3 ( & V_9 . V_10 , V_7 ) ;
case V_13 :
if ( V_9 . V_14 ) {
V_9 . V_14 = false ;
F_4 ( & V_9 . V_15 ) ;
}
break;
case V_16 :
F_2 ( & V_9 . V_10 , V_7 ) ;
V_9 . V_11 -= V_6 -> V_12 ;
F_3 ( & V_9 . V_10 , V_7 ) ;
break;
case V_17 :
case V_18 :
case V_19 :
break;
}
return V_20 ;
}
static void F_5 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
unsigned long V_25 ;
unsigned long V_26 ;
struct V_27 * V_28 ;
V_25 = ( unsigned long ) F_6 ( V_22 -> V_29 ) ;
V_26 = ( unsigned long ) F_6 ( V_22 -> V_30 ) ;
if ( ( ( unsigned long ) V_24 < V_25 ) ||
( ( unsigned long ) V_24 >= V_26 ) )
return;
F_7 (gap, &has->gap_list, list) {
V_25 = ( unsigned long )
F_6 ( V_28 -> V_31 ) ;
V_26 = ( unsigned long )
F_6 ( V_28 -> V_32 ) ;
if ( ( ( unsigned long ) V_24 >= V_25 ) &&
( ( unsigned long ) V_24 < V_26 ) ) {
return;
}
}
F_8 ( V_24 ) ;
F_9 ( V_24 ) ;
F_10 ( V_24 ) ;
}
static void F_11 ( struct V_21 * V_22 ,
unsigned long V_31 , unsigned long V_33 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < V_33 ; V_34 ++ )
F_5 ( V_22 , F_6 ( V_31 + V_34 ) ) ;
}
static void F_12 ( unsigned long V_35 , unsigned long V_33 ,
unsigned long V_36 ,
struct V_21 * V_22 )
{
int V_37 = 0 ;
int V_34 , V_38 ;
unsigned long V_31 ;
unsigned long V_39 ;
unsigned long V_40 = V_36 ;
unsigned long V_7 ;
for ( V_34 = 0 ; V_34 < ( V_33 / V_41 ) ; V_34 ++ ) {
V_31 = V_35 + ( V_34 * V_41 ) ;
F_2 ( & V_9 . V_10 , V_7 ) ;
V_22 -> V_42 += V_41 ;
if ( V_40 > V_41 ) {
V_39 = V_41 ;
V_40 -= V_41 ;
} else {
V_39 = V_40 ;
V_40 = 0 ;
}
V_22 -> V_30 += V_39 ;
F_3 ( & V_9 . V_10 , V_7 ) ;
F_13 ( & V_9 . V_15 ) ;
V_9 . V_14 = ! V_43 ;
V_38 = F_14 ( F_15 ( V_31 ) ) ;
V_37 = F_16 ( V_38 , F_15 ( ( V_31 ) ) ,
( V_41 << V_44 ) ) ;
if ( V_37 ) {
F_17 ( L_1 , V_37 ) ;
if ( V_37 == - V_45 ) {
V_46 = false ;
}
F_2 ( & V_9 . V_10 , V_7 ) ;
V_22 -> V_42 -= V_41 ;
V_22 -> V_30 -= V_39 ;
F_3 ( & V_9 . V_10 , V_7 ) ;
break;
}
if ( V_9 . V_14 )
F_18 ( & V_9 . V_15 ,
5 * V_47 ) ;
F_19 ( & V_9 ) ;
}
return;
}
static void F_20 ( struct V_23 * V_24 )
{
struct V_21 * V_22 ;
unsigned long V_25 ;
unsigned long V_26 ;
unsigned long V_7 ;
F_2 ( & V_9 . V_10 , V_7 ) ;
F_7 (has, &dm_device.ha_region_list, list) {
V_25 = ( unsigned long )
F_6 ( V_22 -> V_31 ) ;
V_26 = ( unsigned long ) F_6 ( V_22 -> V_32 ) ;
if ( ( ( unsigned long ) V_24 < V_25 ) ||
( ( unsigned long ) V_24 >= V_26 ) )
continue;
F_5 ( V_22 , V_24 ) ;
break;
}
F_3 ( & V_9 . V_10 , V_7 ) ;
}
static int F_21 ( unsigned long V_31 , unsigned long V_48 )
{
struct V_21 * V_22 ;
struct V_27 * V_28 ;
unsigned long V_49 , V_50 ;
int V_37 = 0 ;
unsigned long V_7 ;
F_2 ( & V_9 . V_10 , V_7 ) ;
F_7 (has, &dm_device.ha_region_list, list) {
if ( V_31 < V_22 -> V_31 || V_31 >= V_22 -> V_32 )
continue;
if ( V_22 -> V_30 != V_31 ) {
V_28 = F_22 ( sizeof( struct V_27 ) , V_51 ) ;
if ( ! V_28 ) {
V_37 = - V_52 ;
break;
}
F_23 ( & V_28 -> V_53 ) ;
V_28 -> V_31 = V_22 -> V_30 ;
V_28 -> V_32 = V_31 ;
F_24 ( & V_28 -> V_53 , & V_22 -> V_54 ) ;
V_22 -> V_30 = V_31 ;
}
if ( ( V_31 + V_48 ) > V_22 -> V_32 ) {
V_49 = ( V_31 + V_48 - V_22 -> V_32 ) ;
V_50 = ( V_49 / V_41 ) * V_41 ;
if ( V_49 % V_41 )
V_50 += V_41 ;
V_22 -> V_32 += V_50 ;
}
V_37 = 1 ;
break;
}
F_3 ( & V_9 . V_10 , V_7 ) ;
return V_37 ;
}
static unsigned long F_25 ( unsigned long V_55 ,
unsigned long V_56 )
{
unsigned long V_31 = V_55 ;
unsigned long V_48 = V_56 ;
unsigned long V_33 ;
struct V_21 * V_22 ;
unsigned long V_57 = 0 ;
unsigned long V_58 ;
unsigned long V_59 = 0 , V_7 ;
F_2 ( & V_9 . V_10 , V_7 ) ;
F_7 (has, &dm_device.ha_region_list, list) {
if ( V_31 < V_22 -> V_31 || V_31 >= V_22 -> V_32 )
continue;
V_58 = V_22 -> V_30 ;
if ( V_31 < V_22 -> V_42 ) {
V_57 = V_22 -> V_42 - V_31 ;
if ( V_57 > V_48 )
V_57 = V_48 ;
V_22 -> V_30 += V_57 ;
V_48 -= V_57 ;
if ( V_31 > V_22 -> V_31 &&
! F_26 ( F_6 ( V_31 - 1 ) ) )
F_11 ( V_22 , V_31 , V_57 ) ;
}
if ( ( V_22 -> V_42 < V_22 -> V_32 ) && ( V_48 > 0 ) ) {
V_33 = ( V_22 -> V_32 - V_22 -> V_42 ) ;
if ( V_48 <= V_33 ) {
V_33 = ( ( V_48 / V_41 ) * V_41 ) ;
if ( V_48 % V_41 )
V_33 += V_41 ;
} else {
V_48 = V_33 ;
}
F_3 ( & V_9 . V_10 , V_7 ) ;
F_12 ( V_22 -> V_42 , V_33 , V_48 , V_22 ) ;
F_2 ( & V_9 . V_10 , V_7 ) ;
}
V_59 = V_22 -> V_30 - V_58 ;
break;
}
F_3 ( & V_9 . V_10 , V_7 ) ;
return V_59 ;
}
static unsigned long F_27 ( unsigned long V_55 ,
unsigned long V_48 ,
unsigned long V_60 ,
unsigned long V_61 )
{
struct V_21 * V_62 = NULL ;
int V_63 ;
unsigned long V_7 ;
if ( V_48 == 0 )
return 0 ;
if ( ! V_9 . V_64 ) {
V_63 = F_21 ( V_55 , V_48 ) ;
if ( V_63 < 0 )
return 0 ;
if ( V_63 )
goto V_65;
}
if ( V_61 != 0 ) {
V_62 = F_22 ( sizeof( struct V_21 ) , V_66 ) ;
if ( ! V_62 )
return 0 ;
F_23 ( & V_62 -> V_53 ) ;
F_23 ( & V_62 -> V_54 ) ;
V_62 -> V_31 = V_60 ;
V_62 -> V_42 = V_60 ;
V_62 -> V_29 = V_55 ;
V_62 -> V_30 = V_55 ;
V_62 -> V_32 = V_60 + V_61 ;
F_2 ( & V_9 . V_10 , V_7 ) ;
F_24 ( & V_62 -> V_53 , & V_9 . V_67 ) ;
F_3 ( & V_9 . V_10 , V_7 ) ;
}
V_65:
return F_25 ( V_55 , V_48 ) ;
}
static void F_28 ( struct V_68 * V_69 )
{
struct V_70 V_71 ;
#ifdef F_29
unsigned long V_55 , V_48 ;
unsigned long V_60 , V_72 ;
#endif
struct V_73 * V_74 = & V_9 ;
memset ( & V_71 , 0 , sizeof( struct V_70 ) ) ;
V_71 . V_75 . type = V_76 ;
V_71 . V_75 . V_33 = sizeof( struct V_70 ) ;
#ifdef F_29
V_55 = V_74 -> V_77 . V_78 . V_79 . V_80 ;
V_48 = V_74 -> V_77 . V_78 . V_79 . V_81 ;
V_60 = V_74 -> V_77 . V_82 . V_79 . V_80 ;
V_72 = V_74 -> V_77 . V_82 . V_79 . V_81 ;
if ( ( V_60 == 0 ) && ( ! V_74 -> V_64 ) ) {
unsigned long V_83 ;
unsigned long V_84 ;
V_84 = V_55 ;
V_83 = ( V_48 / V_41 ) * V_41 ;
if ( V_48 % V_41 )
V_83 += V_41 ;
V_84 = ( V_55 / V_41 ) * V_41 ;
V_60 = V_84 ;
V_72 = V_83 ;
}
if ( V_46 )
V_71 . V_85 = F_27 ( V_55 , V_48 ,
V_60 , V_72 ) ;
V_74 -> V_86 += V_71 . V_85 ;
#endif
if ( V_71 . V_85 > 0 )
V_71 . V_87 = 1 ;
else if ( ! V_46 )
V_71 . V_87 = 1 ;
else
V_71 . V_87 = 0 ;
if ( ! V_46 || ( V_71 . V_85 == 0 ) )
F_17 ( L_2 ) ;
V_74 -> V_88 = V_89 ;
V_71 . V_75 . V_90 = F_30 ( & V_90 ) ;
F_31 ( V_74 -> V_91 -> V_92 , & V_71 ,
sizeof( struct V_70 ) ,
( unsigned long ) NULL ,
V_93 , 0 ) ;
}
static void F_32 ( struct V_73 * V_74 , struct V_94 * V_95 )
{
struct V_96 * V_97 ;
V_97 = (struct V_96 * ) V_95 -> V_98 ;
switch ( V_97 -> type ) {
case V_99 :
F_17 ( L_3 ) ;
F_17 ( L_4 , V_97 -> V_100 ) ;
break;
default:
F_17 ( L_5 , V_97 -> type ) ;
}
}
static unsigned long F_33 ( void )
{
unsigned long V_101 ;
#define F_34 ( T_1 ) ((mb) << (20 - PAGE_SHIFT))
if ( V_102 < F_34 ( 128 ) )
V_101 = F_34 ( 8 ) + ( V_102 >> 1 ) ;
else if ( V_102 < F_34 ( 512 ) )
V_101 = F_34 ( 40 ) + ( V_102 >> 2 ) ;
else if ( V_102 < F_34 ( 2048 ) )
V_101 = F_34 ( 104 ) + ( V_102 >> 3 ) ;
else if ( V_102 < F_34 ( 8192 ) )
V_101 = F_34 ( 232 ) + ( V_102 >> 4 ) ;
else
V_101 = F_34 ( 488 ) + ( V_102 >> 5 ) ;
#undef F_34
return V_101 ;
}
static void F_19 ( struct V_73 * V_74 )
{
struct V_103 V_104 ;
unsigned long V_105 = V_106 ;
unsigned long V_107 = V_108 ;
if ( V_109 > 0 ) {
-- V_109 ;
return;
}
if ( ! F_35 ( V_105 , ( V_108 + V_47 ) ) )
return;
memset ( & V_104 , 0 , sizeof( struct V_103 ) ) ;
V_104 . V_75 . type = V_110 ;
V_104 . V_75 . V_33 = sizeof( struct V_103 ) ;
V_104 . V_75 . V_90 = F_30 ( & V_90 ) ;
V_104 . V_111 = F_36 () ;
V_104 . V_112 = F_37 () +
V_74 -> V_113 +
( V_74 -> V_86 > V_74 -> V_11 ?
V_74 -> V_86 - V_74 -> V_11 : 0 ) +
F_33 () ;
if ( V_104 . V_75 . V_90 != F_38 ( & V_90 ) )
return;
if ( V_107 != V_108 )
return;
V_108 = V_106 ;
F_31 ( V_74 -> V_91 -> V_92 , & V_104 ,
sizeof( struct V_103 ) ,
( unsigned long ) NULL ,
V_93 , 0 ) ;
}
static void F_39 ( struct V_73 * V_74 ,
union V_114 * V_115 )
{
int V_116 = V_115 -> V_79 . V_81 ;
T_2 V_117 = V_115 -> V_79 . V_80 ;
struct V_23 * V_24 ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_116 ; V_34 ++ ) {
V_24 = F_6 ( V_34 + V_117 ) ;
F_40 ( V_24 ) ;
V_74 -> V_113 -- ;
}
}
static unsigned int F_41 ( struct V_73 * V_74 ,
unsigned int V_116 ,
struct V_118 * V_119 ,
int V_120 )
{
unsigned int V_34 = 0 ;
struct V_23 * V_24 ;
if ( V_116 < V_120 )
return 0 ;
for ( V_34 = 0 ; ( V_34 * V_120 ) < V_116 ; V_34 ++ ) {
if ( V_119 -> V_75 . V_33 + sizeof( union V_114 ) >
V_121 )
return V_34 * V_120 ;
V_24 = F_42 ( V_122 | V_123 |
V_124 | V_125 ,
F_43 ( V_120 << V_44 ) ) ;
if ( ! V_24 )
return V_34 * V_120 ;
V_74 -> V_113 += V_120 ;
if ( V_120 != 1 )
F_44 ( V_24 , F_43 ( V_120 << V_44 ) ) ;
V_119 -> V_126 ++ ;
V_119 -> V_115 [ V_34 ] . V_79 . V_80 =
F_45 ( V_24 ) ;
V_119 -> V_115 [ V_34 ] . V_79 . V_81 = V_120 ;
V_119 -> V_75 . V_33 += sizeof( union V_114 ) ;
}
return V_116 ;
}
static void F_46 ( struct V_68 * V_69 )
{
unsigned int V_116 = V_9 . V_127 . V_116 ;
unsigned int V_128 = 0 ;
struct V_118 * V_119 ;
int V_120 ;
int V_37 ;
bool V_129 = false ;
int V_34 ;
long V_130 ;
unsigned long floor ;
F_47 ( V_116 % V_131 != 0 ) ;
V_120 = 512 ;
V_130 = F_36 () ;
floor = F_33 () ;
if ( V_130 < V_116 || V_130 - V_116 < floor ) {
V_116 = V_130 > floor ? ( V_130 - floor ) : 0 ;
V_116 -= V_116 % V_131 ;
}
while ( ! V_129 ) {
V_119 = (struct V_118 * ) V_132 ;
memset ( V_132 , 0 , V_121 ) ;
V_119 -> V_75 . type = V_133 ;
V_119 -> V_75 . V_33 = sizeof( struct V_118 ) ;
V_119 -> V_134 = 1 ;
V_116 -= V_128 ;
V_128 = F_41 ( & V_9 , V_116 ,
V_119 , V_120 ) ;
if ( V_120 != 1 && V_128 == 0 ) {
V_120 = 1 ;
continue;
}
if ( V_128 == 0 || V_128 == V_116 ) {
V_119 -> V_134 = 0 ;
V_129 = true ;
V_9 . V_88 = V_89 ;
}
do {
V_119 -> V_75 . V_90 = F_30 ( & V_90 ) ;
V_37 = F_31 ( V_9 . V_91 -> V_92 ,
V_119 ,
V_119 -> V_75 . V_33 ,
( unsigned long ) NULL ,
V_93 , 0 ) ;
if ( V_37 == - V_135 )
F_48 ( 20 ) ;
F_19 ( & V_9 ) ;
} while ( V_37 == - V_135 );
if ( V_37 ) {
F_17 ( L_6 ) ;
for ( V_34 = 0 ; V_34 < V_119 -> V_126 ; V_34 ++ )
F_39 ( & V_9 ,
& V_119 -> V_115 [ V_34 ] ) ;
V_129 = true ;
}
}
}
static void F_49 ( struct V_73 * V_74 ,
struct V_136 * V_137 )
{
union V_114 * V_115 = V_137 -> V_115 ;
int V_126 = V_137 -> V_126 ;
struct V_138 V_71 ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_126 ; V_34 ++ ) {
F_39 ( V_74 , & V_115 [ V_34 ] ) ;
F_4 ( & V_9 . V_139 ) ;
}
if ( V_137 -> V_134 == 1 )
return;
memset ( & V_71 , 0 , sizeof( struct V_138 ) ) ;
V_71 . V_75 . type = V_140 ;
V_71 . V_75 . V_90 = F_30 ( & V_90 ) ;
V_71 . V_75 . V_33 = sizeof( struct V_138 ) ;
F_31 ( V_9 . V_91 -> V_92 , & V_71 ,
sizeof( struct V_138 ) ,
( unsigned long ) NULL ,
V_93 , 0 ) ;
V_74 -> V_88 = V_89 ;
}
static int F_50 ( void * V_141 )
{
struct V_73 * V_74 = V_141 ;
while ( ! F_51 () ) {
F_52 (
& V_9 . V_139 , 1 * V_47 ) ;
F_53 ( & V_9 . V_139 ) ;
F_19 ( V_74 ) ;
}
return 0 ;
}
static void F_54 ( struct V_73 * V_74 ,
struct V_142 * V_143 )
{
struct V_144 V_145 ;
int V_37 ;
if ( V_143 -> V_146 ) {
F_4 ( & V_74 -> V_147 ) ;
return;
}
if ( V_74 -> V_148 == 0 )
goto V_149;
memset ( & V_145 , 0 , sizeof( struct V_144 ) ) ;
V_145 . V_75 . type = V_150 ;
V_145 . V_75 . V_33 = sizeof( struct V_144 ) ;
V_145 . V_75 . V_90 = F_30 ( & V_90 ) ;
V_145 . V_151 . V_151 = V_74 -> V_148 ;
switch ( V_145 . V_151 . V_151 ) {
case V_152 :
V_74 -> V_148 = V_153 ;
V_145 . V_154 = 0 ;
break;
default:
V_74 -> V_148 = 0 ;
V_145 . V_154 = 1 ;
}
V_37 = F_31 ( V_74 -> V_91 -> V_92 , & V_145 ,
sizeof( struct V_144 ) ,
( unsigned long ) NULL ,
V_93 , 0 ) ;
if ( V_37 )
goto V_149;
return;
V_149:
V_74 -> V_88 = V_155 ;
F_4 ( & V_74 -> V_147 ) ;
}
static void F_55 ( struct V_73 * V_74 ,
struct V_156 * F_55 )
{
if ( ! F_55 -> V_146 ) {
F_17 ( L_7 ) ;
V_74 -> V_88 = V_155 ;
}
F_4 ( & V_74 -> V_147 ) ;
}
static void F_56 ( void * V_157 )
{
struct V_158 * V_91 = V_157 ;
T_3 V_159 ;
T_4 V_160 ;
struct V_161 * V_162 ;
struct V_163 * V_164 ;
struct V_73 * V_74 = F_57 ( V_91 ) ;
struct V_165 * V_166 ;
struct V_167 * V_168 ;
union V_114 * V_169 ;
union V_114 * V_62 ;
memset ( V_170 , 0 , sizeof( V_170 ) ) ;
F_58 ( V_91 -> V_92 , V_170 ,
V_121 , & V_159 , & V_160 ) ;
if ( V_159 > 0 ) {
V_162 = (struct V_161 * ) V_170 ;
V_164 = & V_162 -> V_75 ;
switch ( V_164 -> type ) {
case V_171 :
F_54 ( V_74 ,
(struct V_142 * ) V_162 ) ;
break;
case V_172 :
F_55 ( V_74 ,
(struct V_156 * ) V_162 ) ;
break;
case V_173 :
if ( V_74 -> V_88 == V_174 )
F_59 ( L_8 ) ;
V_166 = (struct V_165 * ) V_170 ;
V_74 -> V_88 = V_174 ;
V_9 . V_127 . V_116 = V_166 -> V_116 ;
F_60 ( & V_9 . V_127 . V_175 ) ;
break;
case V_176 :
V_74 -> V_88 = V_177 ;
F_49 ( V_74 ,
(struct V_136 * ) V_170 ) ;
break;
case V_178 :
if ( V_74 -> V_88 == V_179 )
F_59 ( L_9 ) ;
V_74 -> V_88 = V_179 ;
V_168 = (struct V_167 * ) V_170 ;
if ( V_168 -> V_75 . V_33 == sizeof( struct V_167 ) ) {
V_74 -> V_64 = false ;
V_169 = & V_168 -> V_180 ;
V_74 -> V_77 . V_78 = * V_169 ;
V_74 -> V_77 . V_82 . V_181 = 0 ;
} else {
V_74 -> V_64 = true ;
V_169 = & V_168 -> V_180 ;
V_62 = & V_169 [ 1 ] ;
V_74 -> V_77 . V_78 = * V_169 ;
V_74 -> V_77 . V_82 = * V_62 ;
}
F_60 ( & V_9 . V_77 . V_175 ) ;
break;
case V_182 :
F_32 ( V_74 , (struct V_94 * ) V_162 ) ;
break;
default:
F_61 ( L_10 , V_164 -> type ) ;
}
}
}
static int F_62 ( struct V_158 * V_91 ,
const struct V_183 * V_184 )
{
int V_37 ;
unsigned long V_185 ;
struct V_144 V_145 ;
struct V_186 V_187 ;
V_46 = V_188 ;
V_132 = F_63 ( V_121 , V_66 ) ;
if ( ! V_132 )
return - V_52 ;
V_37 = F_64 ( V_91 -> V_92 , V_189 , V_189 , NULL , 0 ,
F_56 , V_91 ) ;
if ( V_37 )
goto V_190;
V_9 . V_91 = V_91 ;
V_9 . V_88 = V_191 ;
V_9 . V_148 = V_152 ;
F_13 ( & V_9 . V_147 ) ;
F_13 ( & V_9 . V_139 ) ;
F_23 ( & V_9 . V_67 ) ;
F_65 ( & V_9 . V_10 ) ;
F_66 ( & V_9 . V_127 . V_175 , F_46 ) ;
F_66 ( & V_9 . V_77 . V_175 , F_28 ) ;
V_9 . V_64 = false ;
V_9 . V_192 =
F_67 ( F_50 , & V_9 , L_11 ) ;
if ( F_68 ( V_9 . V_192 ) ) {
V_37 = F_69 ( V_9 . V_192 ) ;
goto V_193;
}
#ifdef F_29
F_70 ( & F_20 ) ;
F_71 ( & V_194 ) ;
#endif
F_72 ( V_91 , & V_9 ) ;
memset ( & V_145 , 0 , sizeof( struct V_144 ) ) ;
V_145 . V_75 . type = V_150 ;
V_145 . V_75 . V_33 = sizeof( struct V_144 ) ;
V_145 . V_75 . V_90 = F_30 ( & V_90 ) ;
V_145 . V_151 . V_151 = V_195 ;
V_145 . V_154 = 0 ;
V_37 = F_31 ( V_91 -> V_92 , & V_145 ,
sizeof( struct V_144 ) ,
( unsigned long ) NULL ,
V_93 , 0 ) ;
if ( V_37 )
goto V_196;
V_185 = F_18 ( & V_9 . V_147 , 5 * V_47 ) ;
if ( V_185 == 0 ) {
V_37 = - V_197 ;
goto V_196;
}
if ( V_9 . V_88 == V_155 ) {
V_37 = - V_197 ;
goto V_196;
}
memset ( & V_187 , 0 , sizeof( struct V_186 ) ) ;
V_187 . V_75 . type = V_198 ;
V_187 . V_75 . V_33 = sizeof( struct V_186 ) ;
V_187 . V_75 . V_90 = F_30 ( & V_90 ) ;
V_187 . V_199 . V_200 . V_201 = 1 ;
V_187 . V_199 . V_200 . V_188 = 1 ;
V_187 . V_199 . V_200 . V_202 = 7 ;
V_187 . V_203 = 0 ;
V_187 . V_204 = - 1 ;
V_37 = F_31 ( V_91 -> V_92 , & V_187 ,
sizeof( struct V_186 ) ,
( unsigned long ) NULL ,
V_93 , 0 ) ;
if ( V_37 )
goto V_196;
V_185 = F_18 ( & V_9 . V_147 , 5 * V_47 ) ;
if ( V_185 == 0 ) {
V_37 = - V_197 ;
goto V_196;
}
if ( V_9 . V_88 == V_155 ) {
V_37 = - V_197 ;
goto V_196;
}
V_9 . V_88 = V_89 ;
return 0 ;
V_196:
#ifdef F_29
F_73 ( & F_20 ) ;
#endif
F_74 ( V_9 . V_192 ) ;
V_193:
F_75 ( V_91 -> V_92 ) ;
V_190:
F_76 ( V_132 ) ;
return V_37 ;
}
static int F_77 ( struct V_158 * V_91 )
{
struct V_73 * V_74 = F_57 ( V_91 ) ;
struct V_21 * V_22 , * V_205 ;
struct V_27 * V_28 , * V_206 ;
unsigned long V_7 ;
if ( V_74 -> V_113 != 0 )
F_59 ( L_12 , V_74 -> V_113 ) ;
F_78 ( & V_74 -> V_127 . V_175 ) ;
F_78 ( & V_74 -> V_77 . V_175 ) ;
F_75 ( V_91 -> V_92 ) ;
F_74 ( V_74 -> V_192 ) ;
F_76 ( V_132 ) ;
#ifdef F_29
F_73 ( & F_20 ) ;
F_79 ( & V_194 ) ;
#endif
F_2 ( & V_9 . V_10 , V_7 ) ;
F_80 (has, tmp, &dm->ha_region_list, list) {
F_80 (gap, tmp_gap, &has->gap_list, list) {
F_81 ( & V_28 -> V_53 ) ;
F_76 ( V_28 ) ;
}
F_81 ( & V_22 -> V_53 ) ;
F_76 ( V_22 ) ;
}
F_3 ( & V_9 . V_10 , V_7 ) ;
return 0 ;
}
static int T_5 F_82 ( void )
{
return F_83 ( & V_207 ) ;
}
