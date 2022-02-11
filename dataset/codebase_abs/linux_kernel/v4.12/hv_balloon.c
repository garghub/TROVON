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
F_12 ( L_1 , V_33 , V_31 ) ;
for ( V_34 = 0 ; V_34 < V_33 ; V_34 ++ )
F_5 ( V_22 , F_6 ( V_31 + V_34 ) ) ;
}
static void F_13 ( unsigned long V_35 , unsigned long V_33 ,
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
F_14 ( & V_9 . V_15 ) ;
V_9 . V_14 = ! V_43 ;
V_38 = F_15 ( F_16 ( V_31 ) ) ;
V_37 = F_17 ( V_38 , F_16 ( ( V_31 ) ) ,
( V_41 << V_44 ) ) ;
if ( V_37 ) {
F_18 ( L_2 , V_37 ) ;
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
F_19 ( & V_9 . V_15 ,
5 * V_47 ) ;
F_20 ( & V_9 ) ;
}
}
static void F_21 ( struct V_23 * V_24 )
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
static int F_22 ( unsigned long V_31 , unsigned long V_48 )
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
V_28 = F_23 ( sizeof( struct V_27 ) , V_51 ) ;
if ( ! V_28 ) {
V_37 = - V_52 ;
break;
}
F_24 ( & V_28 -> V_53 ) ;
V_28 -> V_31 = V_22 -> V_30 ;
V_28 -> V_32 = V_31 ;
F_25 ( & V_28 -> V_53 , & V_22 -> V_54 ) ;
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
static unsigned long F_26 ( unsigned long V_55 ,
unsigned long V_56 )
{
unsigned long V_31 = V_55 ;
unsigned long V_48 = V_56 ;
unsigned long V_33 ;
struct V_21 * V_22 ;
unsigned long V_57 = 0 ;
unsigned long V_58 ;
unsigned long V_59 = 0 , V_7 ;
F_12 ( L_3 , V_56 ,
V_55 ) ;
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
! F_27 ( F_6 ( V_31 - 1 ) ) )
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
F_13 ( V_22 -> V_42 , V_33 , V_48 , V_22 ) ;
F_2 ( & V_9 . V_10 , V_7 ) ;
}
V_59 = V_22 -> V_30 - V_58 ;
break;
}
F_3 ( & V_9 . V_10 , V_7 ) ;
return V_59 ;
}
static unsigned long F_28 ( unsigned long V_55 ,
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
V_63 = F_22 ( V_55 , V_48 ) ;
if ( V_63 < 0 )
return 0 ;
if ( V_63 )
goto V_65;
}
if ( V_61 != 0 ) {
V_62 = F_23 ( sizeof( struct V_21 ) , V_66 ) ;
if ( ! V_62 )
return 0 ;
F_24 ( & V_62 -> V_53 ) ;
F_24 ( & V_62 -> V_54 ) ;
V_62 -> V_31 = V_60 ;
V_62 -> V_42 = V_60 ;
V_62 -> V_29 = V_55 ;
V_62 -> V_30 = V_55 ;
V_62 -> V_32 = V_60 + V_61 ;
F_2 ( & V_9 . V_10 , V_7 ) ;
F_25 ( & V_62 -> V_53 , & V_9 . V_67 ) ;
F_3 ( & V_9 . V_10 , V_7 ) ;
}
V_65:
return F_26 ( V_55 , V_48 ) ;
}
static void F_29 ( struct V_68 * V_69 )
{
struct V_70 V_71 ;
#ifdef F_30
unsigned long V_55 , V_48 ;
unsigned long V_60 , V_72 ;
#endif
struct V_73 * V_74 = & V_9 ;
memset ( & V_71 , 0 , sizeof( struct V_70 ) ) ;
V_71 . V_75 . type = V_76 ;
V_71 . V_75 . V_33 = sizeof( struct V_70 ) ;
#ifdef F_30
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
V_71 . V_85 = F_28 ( V_55 , V_48 ,
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
F_31 ( L_4 ) ;
V_74 -> V_88 = V_89 ;
V_71 . V_75 . V_90 = F_32 ( & V_90 ) ;
F_33 ( V_74 -> V_91 -> V_92 , & V_71 ,
sizeof( struct V_70 ) ,
( unsigned long ) NULL ,
V_93 , 0 ) ;
}
static void F_34 ( struct V_73 * V_74 , struct V_94 * V_95 )
{
struct V_96 * V_97 ;
V_97 = (struct V_96 * ) V_95 -> V_98 ;
switch ( V_97 -> type ) {
case V_99 :
if ( V_97 -> V_100 == sizeof( V_101 ) ) {
V_101 * V_102 = ( V_101 * ) & V_97 [ 1 ] ;
F_31 ( L_5 ,
* V_102 ) ;
}
break;
default:
F_31 ( L_6 , V_97 -> type ) ;
}
}
static unsigned long F_35 ( void )
{
unsigned long V_103 ;
#define F_36 ( T_1 ) ((mb) << (20 - PAGE_SHIFT))
if ( V_104 < F_36 ( 128 ) )
V_103 = F_36 ( 8 ) + ( V_104 >> 1 ) ;
else if ( V_104 < F_36 ( 512 ) )
V_103 = F_36 ( 40 ) + ( V_104 >> 2 ) ;
else if ( V_104 < F_36 ( 2048 ) )
V_103 = F_36 ( 104 ) + ( V_104 >> 3 ) ;
else if ( V_104 < F_36 ( 8192 ) )
V_103 = F_36 ( 232 ) + ( V_104 >> 4 ) ;
else
V_103 = F_36 ( 488 ) + ( V_104 >> 5 ) ;
#undef F_36
return V_103 ;
}
static void F_20 ( struct V_73 * V_74 )
{
struct V_105 V_106 ;
unsigned long V_107 = V_108 ;
unsigned long V_109 = V_110 ;
if ( V_111 > 0 ) {
-- V_111 ;
return;
}
if ( ! F_37 ( V_107 , ( V_110 + V_47 ) ) )
return;
memset ( & V_106 , 0 , sizeof( struct V_105 ) ) ;
V_106 . V_75 . type = V_112 ;
V_106 . V_75 . V_33 = sizeof( struct V_105 ) ;
V_106 . V_75 . V_90 = F_32 ( & V_90 ) ;
V_106 . V_113 = F_38 () ;
V_106 . V_114 = F_39 () +
V_74 -> V_115 +
( V_74 -> V_86 > V_74 -> V_11 ?
V_74 -> V_86 - V_74 -> V_11 : 0 ) +
F_35 () ;
if ( V_106 . V_75 . V_90 != F_40 ( & V_90 ) )
return;
if ( V_109 != V_110 )
return;
V_110 = V_108 ;
F_33 ( V_74 -> V_91 -> V_92 , & V_106 ,
sizeof( struct V_105 ) ,
( unsigned long ) NULL ,
V_93 , 0 ) ;
}
static void F_41 ( struct V_73 * V_74 ,
union V_116 * V_117 )
{
int V_118 = V_117 -> V_79 . V_81 ;
V_101 V_119 = V_117 -> V_79 . V_80 ;
struct V_23 * V_24 ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_118 ; V_34 ++ ) {
V_24 = F_6 ( V_34 + V_119 ) ;
F_42 ( V_24 ) ;
V_74 -> V_115 -- ;
}
}
static unsigned int F_43 ( struct V_73 * V_74 ,
unsigned int V_118 ,
struct V_120 * V_121 ,
int V_122 )
{
unsigned int V_34 = 0 ;
struct V_23 * V_24 ;
if ( V_118 < V_122 )
return 0 ;
for ( V_34 = 0 ; ( V_34 * V_122 ) < V_118 ; V_34 ++ ) {
if ( V_121 -> V_75 . V_33 + sizeof( union V_116 ) >
V_123 )
return V_34 * V_122 ;
V_24 = F_44 ( V_124 | V_125 |
V_126 | V_127 ,
F_45 ( V_122 << V_44 ) ) ;
if ( ! V_24 )
return V_34 * V_122 ;
V_74 -> V_115 += V_122 ;
if ( V_122 != 1 )
F_46 ( V_24 , F_45 ( V_122 << V_44 ) ) ;
V_121 -> V_128 ++ ;
V_121 -> V_117 [ V_34 ] . V_79 . V_80 =
F_47 ( V_24 ) ;
V_121 -> V_117 [ V_34 ] . V_79 . V_81 = V_122 ;
V_121 -> V_75 . V_33 += sizeof( union V_116 ) ;
}
return V_118 ;
}
static void F_48 ( struct V_68 * V_69 )
{
unsigned int V_118 = V_9 . V_129 . V_118 ;
unsigned int V_130 = 0 ;
struct V_120 * V_121 ;
int V_122 ;
int V_37 ;
bool V_131 = false ;
int V_34 ;
long V_132 ;
unsigned long floor ;
F_49 ( V_118 % V_133 != 0 ) ;
V_122 = 512 ;
V_132 = F_38 () ;
floor = F_35 () ;
if ( V_132 < V_118 || V_132 - V_118 < floor ) {
F_18 ( L_7 ,
V_132 < V_118 ? L_8 :
L_9 ) ;
V_118 = V_132 > floor ? ( V_132 - floor ) : 0 ;
V_118 -= V_118 % V_133 ;
}
while ( ! V_131 ) {
V_121 = (struct V_120 * ) V_134 ;
memset ( V_134 , 0 , V_123 ) ;
V_121 -> V_75 . type = V_135 ;
V_121 -> V_75 . V_33 = sizeof( struct V_120 ) ;
V_121 -> V_136 = 1 ;
V_118 -= V_130 ;
V_130 = F_43 ( & V_9 , V_118 ,
V_121 , V_122 ) ;
if ( V_122 != 1 && V_130 == 0 ) {
V_122 = 1 ;
continue;
}
if ( V_130 == 0 || V_130 == V_118 ) {
F_12 ( L_10 ,
V_118 , V_9 . V_129 . V_118 ) ;
V_121 -> V_136 = 0 ;
V_131 = true ;
V_9 . V_88 = V_89 ;
}
do {
V_121 -> V_75 . V_90 = F_32 ( & V_90 ) ;
V_37 = F_33 ( V_9 . V_91 -> V_92 ,
V_121 ,
V_121 -> V_75 . V_33 ,
( unsigned long ) NULL ,
V_93 , 0 ) ;
if ( V_37 == - V_137 )
F_50 ( 20 ) ;
F_20 ( & V_9 ) ;
} while ( V_37 == - V_137 );
if ( V_37 ) {
F_31 ( L_11 ) ;
for ( V_34 = 0 ; V_34 < V_121 -> V_128 ; V_34 ++ )
F_41 ( & V_9 ,
& V_121 -> V_117 [ V_34 ] ) ;
V_131 = true ;
}
}
}
static void F_51 ( struct V_73 * V_74 ,
struct V_138 * V_139 )
{
union V_116 * V_117 = V_139 -> V_117 ;
int V_128 = V_139 -> V_128 ;
struct V_140 V_71 ;
int V_34 ;
unsigned int V_141 = V_74 -> V_115 ;
for ( V_34 = 0 ; V_34 < V_128 ; V_34 ++ ) {
F_41 ( V_74 , & V_117 [ V_34 ] ) ;
F_4 ( & V_9 . V_142 ) ;
}
F_12 ( L_12 ,
V_141 - V_74 -> V_115 ) ;
if ( V_139 -> V_136 == 1 )
return;
memset ( & V_71 , 0 , sizeof( struct V_140 ) ) ;
V_71 . V_75 . type = V_143 ;
V_71 . V_75 . V_90 = F_32 ( & V_90 ) ;
V_71 . V_75 . V_33 = sizeof( struct V_140 ) ;
F_33 ( V_9 . V_91 -> V_92 , & V_71 ,
sizeof( struct V_140 ) ,
( unsigned long ) NULL ,
V_93 , 0 ) ;
V_74 -> V_88 = V_89 ;
}
static int F_52 ( void * V_144 )
{
struct V_73 * V_74 = V_144 ;
while ( ! F_53 () ) {
F_54 (
& V_9 . V_142 , 1 * V_47 ) ;
F_55 ( & V_9 . V_142 ) ;
F_20 ( V_74 ) ;
}
return 0 ;
}
static void F_56 ( struct V_73 * V_74 ,
struct V_145 * V_146 )
{
struct V_147 V_148 ;
int V_37 ;
if ( V_146 -> V_149 ) {
F_4 ( & V_74 -> V_150 ) ;
return;
}
if ( V_74 -> V_151 == 0 )
goto V_152;
memset ( & V_148 , 0 , sizeof( struct V_147 ) ) ;
V_148 . V_75 . type = V_153 ;
V_148 . V_75 . V_33 = sizeof( struct V_147 ) ;
V_148 . V_75 . V_90 = F_32 ( & V_90 ) ;
V_148 . V_154 . V_154 = V_74 -> V_151 ;
V_74 -> V_154 = V_148 . V_154 . V_154 ;
switch ( V_148 . V_154 . V_154 ) {
case V_155 :
V_74 -> V_151 = V_156 ;
V_148 . V_157 = 0 ;
break;
default:
V_74 -> V_151 = 0 ;
V_148 . V_157 = 1 ;
}
V_37 = F_33 ( V_74 -> V_91 -> V_92 , & V_148 ,
sizeof( struct V_147 ) ,
( unsigned long ) NULL ,
V_93 , 0 ) ;
if ( V_37 )
goto V_152;
return;
V_152:
V_74 -> V_88 = V_158 ;
F_4 ( & V_74 -> V_150 ) ;
}
static void F_57 ( struct V_73 * V_74 ,
struct V_159 * F_57 )
{
if ( ! F_57 -> V_149 ) {
F_31 ( L_13 ) ;
V_74 -> V_88 = V_158 ;
}
F_4 ( & V_74 -> V_150 ) ;
}
static void F_58 ( void * V_160 )
{
struct V_161 * V_91 = V_160 ;
T_2 V_162 ;
T_3 V_163 ;
struct V_164 * V_165 ;
struct V_166 * V_167 ;
struct V_73 * V_74 = F_59 ( V_91 ) ;
struct V_168 * V_169 ;
struct V_170 * V_171 ;
union V_116 * V_172 ;
union V_116 * V_62 ;
memset ( V_173 , 0 , sizeof( V_173 ) ) ;
F_60 ( V_91 -> V_92 , V_173 ,
V_123 , & V_162 , & V_163 ) ;
if ( V_162 > 0 ) {
V_165 = (struct V_164 * ) V_173 ;
V_167 = & V_165 -> V_75 ;
switch ( V_167 -> type ) {
case V_174 :
F_56 ( V_74 ,
(struct V_145 * ) V_165 ) ;
break;
case V_175 :
F_57 ( V_74 ,
(struct V_159 * ) V_165 ) ;
break;
case V_176 :
if ( V_74 -> V_88 == V_177 )
F_18 ( L_14 ) ;
V_169 = (struct V_168 * ) V_173 ;
V_74 -> V_88 = V_177 ;
V_9 . V_129 . V_118 = V_169 -> V_118 ;
F_61 ( & V_9 . V_129 . V_178 ) ;
break;
case V_179 :
V_74 -> V_88 = V_180 ;
F_51 ( V_74 ,
(struct V_138 * ) V_173 ) ;
break;
case V_181 :
if ( V_74 -> V_88 == V_182 )
F_18 ( L_15 ) ;
V_74 -> V_88 = V_182 ;
V_171 = (struct V_170 * ) V_173 ;
if ( V_171 -> V_75 . V_33 == sizeof( struct V_170 ) ) {
V_74 -> V_64 = false ;
V_172 = & V_171 -> V_183 ;
V_74 -> V_77 . V_78 = * V_172 ;
V_74 -> V_77 . V_82 . V_184 = 0 ;
} else {
V_74 -> V_64 = true ;
V_172 = & V_171 -> V_183 ;
V_62 = & V_172 [ 1 ] ;
V_74 -> V_77 . V_78 = * V_172 ;
V_74 -> V_77 . V_82 = * V_62 ;
}
F_61 ( & V_9 . V_77 . V_178 ) ;
break;
case V_185 :
F_34 ( V_74 , (struct V_94 * ) V_165 ) ;
break;
default:
F_62 ( L_16 , V_167 -> type ) ;
}
}
}
static int F_63 ( struct V_161 * V_91 ,
const struct V_186 * V_187 )
{
int V_37 ;
unsigned long V_188 ;
struct V_147 V_148 ;
struct V_189 V_190 ;
#ifdef F_30
V_46 = V_191 ;
#else
V_46 = false ;
#endif
V_134 = F_64 ( V_123 , V_66 ) ;
if ( ! V_134 )
return - V_52 ;
V_37 = F_65 ( V_91 -> V_92 , V_192 , V_192 , NULL , 0 ,
F_58 , V_91 ) ;
if ( V_37 )
goto V_193;
V_9 . V_91 = V_91 ;
V_9 . V_88 = V_194 ;
V_9 . V_151 = V_155 ;
F_14 ( & V_9 . V_150 ) ;
F_14 ( & V_9 . V_142 ) ;
F_24 ( & V_9 . V_67 ) ;
F_66 ( & V_9 . V_10 ) ;
F_67 ( & V_9 . V_129 . V_178 , F_48 ) ;
F_67 ( & V_9 . V_77 . V_178 , F_29 ) ;
V_9 . V_64 = false ;
V_9 . V_195 =
F_68 ( F_52 , & V_9 , L_17 ) ;
if ( F_69 ( V_9 . V_195 ) ) {
V_37 = F_70 ( V_9 . V_195 ) ;
goto V_196;
}
#ifdef F_30
F_71 ( & F_21 ) ;
F_72 ( & V_197 ) ;
#endif
F_73 ( V_91 , & V_9 ) ;
memset ( & V_148 , 0 , sizeof( struct V_147 ) ) ;
V_148 . V_75 . type = V_153 ;
V_148 . V_75 . V_33 = sizeof( struct V_147 ) ;
V_148 . V_75 . V_90 = F_32 ( & V_90 ) ;
V_148 . V_154 . V_154 = V_198 ;
V_148 . V_157 = 0 ;
V_9 . V_154 = V_148 . V_154 . V_154 ;
V_37 = F_33 ( V_91 -> V_92 , & V_148 ,
sizeof( struct V_147 ) ,
( unsigned long ) NULL ,
V_93 , 0 ) ;
if ( V_37 )
goto V_199;
V_188 = F_19 ( & V_9 . V_150 , 5 * V_47 ) ;
if ( V_188 == 0 ) {
V_37 = - V_200 ;
goto V_199;
}
if ( V_9 . V_88 == V_158 ) {
V_37 = - V_200 ;
goto V_199;
}
F_31 ( L_18 ,
F_74 ( V_9 . V_154 ) ,
F_75 ( V_9 . V_154 ) ) ;
memset ( & V_190 , 0 , sizeof( struct V_189 ) ) ;
V_190 . V_75 . type = V_201 ;
V_190 . V_75 . V_33 = sizeof( struct V_189 ) ;
V_190 . V_75 . V_90 = F_32 ( & V_90 ) ;
V_190 . V_202 . V_203 . V_204 = 1 ;
V_190 . V_202 . V_203 . V_191 = 1 ;
V_190 . V_202 . V_203 . V_205 = 7 ;
V_190 . V_206 = 0 ;
V_190 . V_207 = - 1 ;
V_37 = F_33 ( V_91 -> V_92 , & V_190 ,
sizeof( struct V_189 ) ,
( unsigned long ) NULL ,
V_93 , 0 ) ;
if ( V_37 )
goto V_199;
V_188 = F_19 ( & V_9 . V_150 , 5 * V_47 ) ;
if ( V_188 == 0 ) {
V_37 = - V_200 ;
goto V_199;
}
if ( V_9 . V_88 == V_158 ) {
V_37 = - V_200 ;
goto V_199;
}
V_9 . V_88 = V_89 ;
return 0 ;
V_199:
#ifdef F_30
F_76 ( & F_21 ) ;
#endif
F_77 ( V_9 . V_195 ) ;
V_196:
F_78 ( V_91 -> V_92 ) ;
V_193:
F_79 ( V_134 ) ;
return V_37 ;
}
static int F_80 ( struct V_161 * V_91 )
{
struct V_73 * V_74 = F_59 ( V_91 ) ;
struct V_21 * V_22 , * V_208 ;
struct V_27 * V_28 , * V_209 ;
unsigned long V_7 ;
if ( V_74 -> V_115 != 0 )
F_18 ( L_19 , V_74 -> V_115 ) ;
F_81 ( & V_74 -> V_129 . V_178 ) ;
F_81 ( & V_74 -> V_77 . V_178 ) ;
F_78 ( V_91 -> V_92 ) ;
F_77 ( V_74 -> V_195 ) ;
F_79 ( V_134 ) ;
#ifdef F_30
F_76 ( & F_21 ) ;
F_82 ( & V_197 ) ;
#endif
F_2 ( & V_9 . V_10 , V_7 ) ;
F_83 (has, tmp, &dm->ha_region_list, list) {
F_83 (gap, tmp_gap, &has->gap_list, list) {
F_84 ( & V_28 -> V_53 ) ;
F_79 ( V_28 ) ;
}
F_84 ( & V_22 -> V_53 ) ;
F_79 ( V_22 ) ;
}
F_3 ( & V_9 . V_10 , V_7 ) ;
return 0 ;
}
static int T_4 F_85 ( void )
{
return F_86 ( & V_210 ) ;
}
