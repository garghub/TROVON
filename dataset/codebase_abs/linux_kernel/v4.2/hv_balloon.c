static int F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_4 ;
switch ( V_3 ) {
case V_7 :
F_2 ( & V_8 . V_9 ) ;
break;
case V_10 :
V_8 . V_11 += V_6 -> V_12 ;
case V_13 :
if ( V_3 == V_10 ||
F_3 ( & V_8 . V_9 ) )
F_4 ( & V_8 . V_9 ) ;
if ( V_8 . V_14 ) {
V_8 . V_14 = false ;
F_5 ( & V_8 . V_15 ) ;
}
break;
case V_16 :
F_2 ( & V_8 . V_9 ) ;
V_8 . V_11 -= V_6 -> V_12 ;
F_4 ( & V_8 . V_9 ) ;
break;
case V_17 :
case V_18 :
break;
}
return V_19 ;
}
static void F_6 ( unsigned long V_20 , unsigned long V_21 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_21 ; V_22 ++ ) {
struct V_23 * V_24 ;
V_24 = F_7 ( V_20 + V_22 ) ;
F_8 ( V_24 ) ;
F_9 ( V_24 ) ;
F_10 ( V_24 ) ;
}
}
static void F_11 ( unsigned long V_25 , unsigned long V_21 ,
unsigned long V_26 ,
struct V_27 * V_28 )
{
int V_29 = 0 ;
int V_22 , V_30 ;
unsigned long V_20 ;
unsigned long V_31 ;
unsigned long V_32 = V_26 ;
for ( V_22 = 0 ; V_22 < ( V_21 / V_33 ) ; V_22 ++ ) {
V_20 = V_25 + ( V_22 * V_33 ) ;
V_28 -> V_34 += V_33 ;
if ( V_32 > V_33 ) {
V_31 = V_33 ;
V_32 -= V_33 ;
} else {
V_31 = V_32 ;
V_32 = 0 ;
}
V_28 -> V_35 += V_31 ;
F_12 ( & V_8 . V_15 ) ;
V_8 . V_14 = true ;
F_4 ( & V_8 . V_9 ) ;
V_30 = F_13 ( F_14 ( V_20 ) ) ;
V_29 = F_15 ( V_30 , F_14 ( ( V_20 ) ) ,
( V_33 << V_36 ) ) ;
if ( V_29 ) {
F_16 ( L_1 , V_29 ) ;
if ( V_29 == - V_37 ) {
V_38 = false ;
}
V_28 -> V_34 -= V_33 ;
V_28 -> V_35 -= V_31 ;
F_2 ( & V_8 . V_9 ) ;
break;
}
F_17 ( & V_8 . V_15 , 5 * V_39 ) ;
F_2 ( & V_8 . V_9 ) ;
F_18 ( & V_8 ) ;
}
return;
}
static void F_19 ( struct V_23 * V_24 )
{
struct V_40 * V_41 ;
struct V_27 * V_28 ;
unsigned long V_42 ;
unsigned long V_43 ;
F_20 (cur, &dm_device.ha_region_list) {
V_28 = F_21 ( V_41 , struct V_27 , V_44 ) ;
V_42 = ( unsigned long ) F_7 ( V_28 -> V_20 ) ;
V_43 = ( unsigned long ) F_7 ( V_28 -> V_35 ) ;
if ( ( ( unsigned long ) V_24 >= V_42 ) &&
( ( unsigned long ) V_24 < V_43 ) ) {
F_8 ( V_24 ) ;
F_9 ( V_24 ) ;
F_10 ( V_24 ) ;
}
}
}
static bool F_22 ( unsigned long V_20 , unsigned long V_45 )
{
struct V_40 * V_41 ;
struct V_27 * V_28 ;
unsigned long V_46 , V_47 ;
if ( F_23 ( & V_8 . V_48 ) )
return false ;
F_20 (cur, &dm_device.ha_region_list) {
V_28 = F_21 ( V_41 , struct V_27 , V_44 ) ;
if ( ( V_20 >= V_28 -> V_49 ) )
continue;
if ( ( V_20 + V_45 ) > V_28 -> V_49 ) {
V_46 = ( V_20 + V_45 - V_28 -> V_49 ) ;
V_47 = ( V_46 / V_33 ) * V_33 ;
if ( V_46 % V_33 )
V_47 += V_33 ;
V_28 -> V_49 += V_47 ;
}
if ( V_28 -> V_35 != V_20 )
V_28 -> V_35 = V_20 ;
return true ;
}
return false ;
}
static unsigned long F_24 ( unsigned long V_50 ,
unsigned long V_51 )
{
unsigned long V_20 = V_50 ;
unsigned long V_45 = V_51 ;
unsigned long V_21 ;
struct V_40 * V_41 ;
struct V_27 * V_28 ;
unsigned long V_52 = 0 ;
unsigned long V_53 ;
if ( F_23 ( & V_8 . V_48 ) )
return 0 ;
F_20 (cur, &dm_device.ha_region_list) {
V_28 = F_21 ( V_41 , struct V_27 , V_44 ) ;
if ( ( V_20 >= V_28 -> V_49 ) )
continue;
V_53 = V_28 -> V_35 ;
if ( V_20 < V_28 -> V_34 ) {
V_52 = V_28 -> V_34 - V_20 ;
if ( V_52 > V_45 )
V_52 = V_45 ;
if ( V_20 > V_28 -> V_20 &&
! F_25 ( F_7 ( V_20 - 1 ) ) )
F_6 ( V_20 , V_52 ) ;
V_28 -> V_35 += V_52 ;
V_45 -= V_52 ;
}
if ( ( V_28 -> V_34 < V_28 -> V_49 ) && ( V_45 > 0 ) ) {
V_21 = ( V_28 -> V_49 - V_28 -> V_34 ) ;
if ( V_45 <= V_21 ) {
V_21 = ( ( V_45 / V_33 ) * V_33 ) ;
if ( V_45 % V_33 )
V_21 += V_33 ;
} else {
V_45 = V_21 ;
}
F_11 ( V_28 -> V_34 , V_21 , V_45 , V_28 ) ;
}
return V_28 -> V_35 - V_53 ;
}
return 0 ;
}
static unsigned long F_26 ( unsigned long V_50 ,
unsigned long V_45 ,
unsigned long V_54 ,
unsigned long V_55 )
{
struct V_27 * V_56 = NULL ;
if ( V_45 == 0 )
return 0 ;
if ( ! V_8 . V_57 )
if ( F_22 ( V_50 , V_45 ) )
goto V_58;
if ( V_55 != 0 ) {
V_56 = F_27 ( sizeof( struct V_27 ) , V_59 ) ;
if ( ! V_56 )
return 0 ;
F_28 ( & V_56 -> V_44 ) ;
F_29 ( & V_56 -> V_44 , & V_8 . V_48 ) ;
V_56 -> V_20 = V_54 ;
V_56 -> V_34 = V_54 ;
V_56 -> V_35 = V_50 ;
V_56 -> V_49 = V_54 + V_55 ;
}
V_58:
return F_24 ( V_50 , V_45 ) ;
}
static void F_30 ( struct V_60 * V_61 )
{
struct V_62 V_63 ;
#ifdef F_31
unsigned long V_50 , V_45 ;
unsigned long V_54 , V_64 ;
#endif
struct V_65 * V_66 = & V_8 ;
memset ( & V_63 , 0 , sizeof( struct V_62 ) ) ;
V_63 . V_67 . type = V_68 ;
V_63 . V_67 . V_21 = sizeof( struct V_62 ) ;
#ifdef F_31
F_2 ( & V_8 . V_9 ) ;
V_50 = V_66 -> V_69 . V_70 . V_71 . V_72 ;
V_45 = V_66 -> V_69 . V_70 . V_71 . V_73 ;
V_54 = V_66 -> V_69 . V_74 . V_71 . V_72 ;
V_64 = V_66 -> V_69 . V_74 . V_71 . V_73 ;
if ( ( V_54 == 0 ) && ( ! V_66 -> V_57 ) ) {
unsigned long V_75 ;
unsigned long V_76 ;
V_76 = V_50 ;
V_75 = ( V_45 / V_33 ) * V_33 ;
if ( V_45 % V_33 )
V_75 += V_33 ;
V_76 = ( V_50 / V_33 ) * V_33 ;
V_54 = V_76 ;
V_64 = V_75 ;
}
if ( V_38 )
V_63 . V_77 = F_26 ( V_50 , V_45 ,
V_54 , V_64 ) ;
V_66 -> V_78 += V_63 . V_77 ;
F_4 ( & V_8 . V_9 ) ;
#endif
if ( V_63 . V_77 > 0 )
V_63 . V_79 = 1 ;
else if ( ! V_38 )
V_63 . V_79 = 1 ;
else
V_63 . V_79 = 0 ;
if ( ! V_38 || ( V_63 . V_77 == 0 ) )
F_16 ( L_2 ) ;
V_66 -> V_80 = V_81 ;
V_63 . V_67 . V_82 = F_32 ( & V_82 ) ;
F_33 ( V_66 -> V_83 -> V_84 , & V_63 ,
sizeof( struct V_62 ) ,
( unsigned long ) NULL ,
V_85 , 0 ) ;
}
static void F_34 ( struct V_65 * V_66 , struct V_86 * V_87 )
{
struct V_88 * V_89 ;
V_89 = (struct V_88 * ) V_87 -> V_90 ;
switch ( V_89 -> type ) {
case V_91 :
F_16 ( L_3 ) ;
F_16 ( L_4 , V_89 -> V_92 ) ;
break;
default:
F_16 ( L_5 , V_89 -> type ) ;
}
}
static unsigned long F_35 ( void )
{
unsigned long V_93 ;
#define F_36 ( T_1 ) ((mb) << (20 - PAGE_SHIFT))
if ( V_94 < F_36 ( 128 ) )
V_93 = F_36 ( 8 ) + ( V_94 >> 1 ) ;
else if ( V_94 < F_36 ( 512 ) )
V_93 = F_36 ( 40 ) + ( V_94 >> 2 ) ;
else if ( V_94 < F_36 ( 2048 ) )
V_93 = F_36 ( 104 ) + ( V_94 >> 3 ) ;
else if ( V_94 < F_36 ( 8192 ) )
V_93 = F_36 ( 232 ) + ( V_94 >> 4 ) ;
else
V_93 = F_36 ( 488 ) + ( V_94 >> 5 ) ;
#undef F_36
return V_93 ;
}
static void F_18 ( struct V_65 * V_66 )
{
struct V_95 V_96 ;
struct V_97 V_3 ;
unsigned long V_98 = V_99 ;
unsigned long V_100 = V_101 ;
if ( V_102 > 0 ) {
-- V_102 ;
return;
}
if ( ! F_37 ( V_98 , ( V_101 + V_39 ) ) )
return;
F_38 ( & V_3 ) ;
memset ( & V_96 , 0 , sizeof( struct V_95 ) ) ;
V_96 . V_67 . type = V_103 ;
V_96 . V_67 . V_21 = sizeof( struct V_95 ) ;
V_96 . V_67 . V_82 = F_32 ( & V_82 ) ;
V_96 . V_104 = V_3 . V_105 ;
V_96 . V_106 = F_39 () +
V_66 -> V_107 +
( V_66 -> V_78 > V_66 -> V_11 ?
V_66 -> V_78 - V_66 -> V_11 : 0 ) +
F_35 () ;
if ( V_96 . V_67 . V_82 != F_40 ( & V_82 ) )
return;
if ( V_100 != V_101 )
return;
V_101 = V_99 ;
F_33 ( V_66 -> V_83 -> V_84 , & V_96 ,
sizeof( struct V_95 ) ,
( unsigned long ) NULL ,
V_85 , 0 ) ;
}
static void F_41 ( struct V_65 * V_66 ,
union V_108 * V_109 )
{
int V_110 = V_109 -> V_71 . V_73 ;
T_2 V_111 = V_109 -> V_71 . V_72 ;
struct V_23 * V_24 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_110 ; V_22 ++ ) {
V_24 = F_7 ( V_22 + V_111 ) ;
F_42 ( V_24 ) ;
V_66 -> V_107 -- ;
}
}
static unsigned int F_43 ( struct V_65 * V_66 ,
unsigned int V_110 ,
struct V_112 * V_113 ,
int V_114 )
{
unsigned int V_22 = 0 ;
struct V_23 * V_24 ;
if ( V_110 < V_114 )
return 0 ;
for ( V_22 = 0 ; ( V_22 * V_114 ) < V_110 ; V_22 ++ ) {
if ( V_113 -> V_67 . V_21 + sizeof( union V_108 ) >
V_115 )
return V_22 * V_114 ;
V_24 = F_44 ( V_116 | V_117 |
V_118 | V_119 ,
F_45 ( V_114 << V_36 ) ) ;
if ( ! V_24 )
return V_22 * V_114 ;
V_66 -> V_107 += V_114 ;
if ( V_114 != 1 )
F_46 ( V_24 , F_45 ( V_114 << V_36 ) ) ;
V_113 -> V_120 ++ ;
V_113 -> V_109 [ V_22 ] . V_71 . V_72 =
F_47 ( V_24 ) ;
V_113 -> V_109 [ V_22 ] . V_71 . V_73 = V_114 ;
V_113 -> V_67 . V_21 += sizeof( union V_108 ) ;
}
return V_110 ;
}
static void F_48 ( struct V_60 * V_61 )
{
unsigned int V_110 = V_8 . V_121 . V_110 ;
unsigned int V_122 = 0 ;
struct V_112 * V_113 ;
int V_114 ;
int V_29 ;
bool V_123 = false ;
int V_22 ;
struct V_97 V_3 ;
unsigned long floor ;
F_49 ( V_110 % V_124 != 0 ) ;
V_114 = 512 ;
F_38 ( & V_3 ) ;
floor = F_35 () ;
if ( V_3 . V_105 < V_110 || V_3 . V_105 - V_110 < floor ) {
V_110 = V_3 . V_105 > floor ? ( V_3 . V_105 - floor ) : 0 ;
V_110 -= V_110 % V_124 ;
}
while ( ! V_123 ) {
V_113 = (struct V_112 * ) V_125 ;
memset ( V_125 , 0 , V_115 ) ;
V_113 -> V_67 . type = V_126 ;
V_113 -> V_67 . V_21 = sizeof( struct V_112 ) ;
V_113 -> V_127 = 1 ;
V_110 -= V_122 ;
V_122 = F_43 ( & V_8 , V_110 ,
V_113 , V_114 ) ;
if ( V_114 != 1 && V_122 == 0 ) {
V_114 = 1 ;
continue;
}
if ( V_122 == 0 || V_122 == V_110 ) {
V_113 -> V_127 = 0 ;
V_123 = true ;
V_8 . V_80 = V_81 ;
}
do {
V_113 -> V_67 . V_82 = F_32 ( & V_82 ) ;
V_29 = F_33 ( V_8 . V_83 -> V_84 ,
V_113 ,
V_113 -> V_67 . V_21 ,
( unsigned long ) NULL ,
V_85 , 0 ) ;
if ( V_29 == - V_128 )
F_50 ( 20 ) ;
F_18 ( & V_8 ) ;
} while ( V_29 == - V_128 );
if ( V_29 ) {
F_16 ( L_6 ) ;
for ( V_22 = 0 ; V_22 < V_113 -> V_120 ; V_22 ++ )
F_41 ( & V_8 ,
& V_113 -> V_109 [ V_22 ] ) ;
V_123 = true ;
}
}
}
static void F_51 ( struct V_65 * V_66 ,
struct V_129 * V_130 )
{
union V_108 * V_109 = V_130 -> V_109 ;
int V_120 = V_130 -> V_120 ;
struct V_131 V_63 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_120 ; V_22 ++ ) {
F_41 ( V_66 , & V_109 [ V_22 ] ) ;
F_5 ( & V_8 . V_132 ) ;
}
if ( V_130 -> V_127 == 1 )
return;
memset ( & V_63 , 0 , sizeof( struct V_131 ) ) ;
V_63 . V_67 . type = V_133 ;
V_63 . V_67 . V_82 = F_32 ( & V_82 ) ;
V_63 . V_67 . V_21 = sizeof( struct V_131 ) ;
F_33 ( V_8 . V_83 -> V_84 , & V_63 ,
sizeof( struct V_131 ) ,
( unsigned long ) NULL ,
V_85 , 0 ) ;
V_66 -> V_80 = V_81 ;
}
static int F_52 ( void * V_134 )
{
struct V_65 * V_66 = V_134 ;
while ( ! F_53 () ) {
F_54 (
& V_8 . V_132 , 1 * V_39 ) ;
F_55 ( & V_8 . V_132 ) ;
F_18 ( V_66 ) ;
}
return 0 ;
}
static void F_56 ( struct V_65 * V_66 ,
struct V_135 * V_136 )
{
struct V_137 V_138 ;
int V_29 ;
if ( V_136 -> V_139 ) {
F_5 ( & V_66 -> V_140 ) ;
return;
}
if ( V_66 -> V_141 == 0 )
goto V_142;
V_66 -> V_141 = 0 ;
memset ( & V_138 , 0 , sizeof( struct V_137 ) ) ;
V_138 . V_67 . type = V_143 ;
V_138 . V_67 . V_21 = sizeof( struct V_137 ) ;
V_138 . V_67 . V_82 = F_32 ( & V_82 ) ;
V_138 . V_144 . V_144 = V_145 ;
V_138 . V_146 = 1 ;
V_29 = F_33 ( V_66 -> V_83 -> V_84 , & V_138 ,
sizeof( struct V_137 ) ,
( unsigned long ) NULL ,
V_85 , 0 ) ;
if ( V_29 )
goto V_142;
return;
V_142:
V_66 -> V_80 = V_147 ;
F_5 ( & V_66 -> V_140 ) ;
}
static void F_57 ( struct V_65 * V_66 ,
struct V_148 * F_57 )
{
if ( ! F_57 -> V_139 ) {
F_16 ( L_7 ) ;
V_66 -> V_80 = V_147 ;
}
F_5 ( & V_66 -> V_140 ) ;
}
static void F_58 ( void * V_149 )
{
struct V_150 * V_83 = V_149 ;
T_3 V_151 ;
T_4 V_152 ;
struct V_153 * V_154 ;
struct V_155 * V_156 ;
struct V_65 * V_66 = F_59 ( V_83 ) ;
struct V_157 * V_158 ;
struct V_159 * V_160 ;
union V_108 * V_161 ;
union V_108 * V_56 ;
memset ( V_162 , 0 , sizeof( V_162 ) ) ;
F_60 ( V_83 -> V_84 , V_162 ,
V_115 , & V_151 , & V_152 ) ;
if ( V_151 > 0 ) {
V_154 = (struct V_153 * ) V_162 ;
V_156 = & V_154 -> V_67 ;
switch ( V_156 -> type ) {
case V_163 :
F_56 ( V_66 ,
(struct V_135 * ) V_154 ) ;
break;
case V_164 :
F_57 ( V_66 ,
(struct V_148 * ) V_154 ) ;
break;
case V_165 :
if ( V_66 -> V_80 == V_166 )
F_61 ( L_8 ) ;
V_158 = (struct V_157 * ) V_162 ;
V_66 -> V_80 = V_166 ;
V_8 . V_121 . V_110 = V_158 -> V_110 ;
F_62 ( & V_8 . V_121 . V_167 ) ;
break;
case V_168 :
V_66 -> V_80 = V_169 ;
F_51 ( V_66 ,
(struct V_129 * ) V_162 ) ;
break;
case V_170 :
if ( V_66 -> V_80 == V_171 )
F_61 ( L_9 ) ;
V_66 -> V_80 = V_171 ;
V_160 = (struct V_159 * ) V_162 ;
if ( V_160 -> V_67 . V_21 == sizeof( struct V_159 ) ) {
V_161 = & V_160 -> V_172 ;
V_66 -> V_69 . V_70 = * V_161 ;
V_66 -> V_69 . V_74 . V_173 = 0 ;
} else {
V_66 -> V_57 = true ;
V_161 = & V_160 -> V_172 ;
V_56 = & V_161 [ 1 ] ;
V_66 -> V_69 . V_70 = * V_161 ;
V_66 -> V_69 . V_74 = * V_56 ;
}
F_62 ( & V_8 . V_69 . V_167 ) ;
break;
case V_174 :
F_34 ( V_66 , (struct V_86 * ) V_154 ) ;
break;
default:
F_63 ( L_10 , V_156 -> type ) ;
}
}
}
static int F_64 ( struct V_150 * V_83 ,
const struct V_175 * V_176 )
{
int V_29 ;
unsigned long V_177 ;
struct V_137 V_138 ;
struct V_178 V_179 ;
V_38 = V_180 ;
V_125 = F_65 ( V_115 , V_59 ) ;
if ( ! V_125 )
return - V_181 ;
V_29 = F_66 ( V_83 -> V_84 , V_182 , V_182 , NULL , 0 ,
F_58 , V_83 ) ;
if ( V_29 )
goto V_183;
V_8 . V_83 = V_83 ;
V_8 . V_80 = V_184 ;
V_8 . V_141 = V_145 ;
F_12 ( & V_8 . V_140 ) ;
F_12 ( & V_8 . V_132 ) ;
F_28 ( & V_8 . V_48 ) ;
F_67 ( & V_8 . V_9 ) ;
F_68 ( & V_8 . V_121 . V_167 , F_48 ) ;
F_68 ( & V_8 . V_69 . V_167 , F_30 ) ;
V_8 . V_57 = false ;
V_8 . V_185 =
F_69 ( F_52 , & V_8 , L_11 ) ;
if ( F_70 ( V_8 . V_185 ) ) {
V_29 = F_71 ( V_8 . V_185 ) ;
goto V_186;
}
#ifdef F_31
F_72 ( & F_19 ) ;
F_73 ( & V_187 ) ;
#endif
F_74 ( V_83 , & V_8 ) ;
memset ( & V_138 , 0 , sizeof( struct V_137 ) ) ;
V_138 . V_67 . type = V_143 ;
V_138 . V_67 . V_21 = sizeof( struct V_137 ) ;
V_138 . V_67 . V_82 = F_32 ( & V_82 ) ;
V_138 . V_144 . V_144 = V_188 ;
V_138 . V_146 = 0 ;
V_29 = F_33 ( V_83 -> V_84 , & V_138 ,
sizeof( struct V_137 ) ,
( unsigned long ) NULL ,
V_85 , 0 ) ;
if ( V_29 )
goto V_189;
V_177 = F_17 ( & V_8 . V_140 , 5 * V_39 ) ;
if ( V_177 == 0 ) {
V_29 = - V_190 ;
goto V_189;
}
if ( V_8 . V_80 == V_147 ) {
V_29 = - V_190 ;
goto V_189;
}
memset ( & V_179 , 0 , sizeof( struct V_178 ) ) ;
V_179 . V_67 . type = V_191 ;
V_179 . V_67 . V_21 = sizeof( struct V_178 ) ;
V_179 . V_67 . V_82 = F_32 ( & V_82 ) ;
V_179 . V_192 . V_193 . V_194 = 1 ;
V_179 . V_192 . V_193 . V_180 = 1 ;
V_179 . V_192 . V_193 . V_195 = 7 ;
V_179 . V_196 = 0 ;
V_179 . V_197 = - 1 ;
V_29 = F_33 ( V_83 -> V_84 , & V_179 ,
sizeof( struct V_178 ) ,
( unsigned long ) NULL ,
V_85 , 0 ) ;
if ( V_29 )
goto V_189;
V_177 = F_17 ( & V_8 . V_140 , 5 * V_39 ) ;
if ( V_177 == 0 ) {
V_29 = - V_190 ;
goto V_189;
}
if ( V_8 . V_80 == V_147 ) {
V_29 = - V_190 ;
goto V_189;
}
V_8 . V_80 = V_81 ;
return 0 ;
V_189:
#ifdef F_31
F_75 ( & F_19 ) ;
#endif
F_76 ( V_8 . V_185 ) ;
V_186:
F_77 ( V_83 -> V_84 ) ;
V_183:
F_78 ( V_125 ) ;
return V_29 ;
}
static int F_79 ( struct V_150 * V_83 )
{
struct V_65 * V_66 = F_59 ( V_83 ) ;
struct V_40 * V_41 , * V_198 ;
struct V_27 * V_28 ;
if ( V_66 -> V_107 != 0 )
F_61 ( L_12 , V_66 -> V_107 ) ;
F_80 ( & V_66 -> V_121 . V_167 ) ;
F_80 ( & V_66 -> V_69 . V_167 ) ;
F_77 ( V_83 -> V_84 ) ;
F_76 ( V_66 -> V_185 ) ;
F_78 ( V_125 ) ;
#ifdef F_31
F_75 ( & F_19 ) ;
F_81 ( & V_187 ) ;
#endif
F_82 (cur, tmp, &dm->ha_region_list) {
V_28 = F_21 ( V_41 , struct V_27 , V_44 ) ;
F_83 ( & V_28 -> V_44 ) ;
F_78 ( V_28 ) ;
}
return 0 ;
}
static int T_5 F_84 ( void )
{
return F_85 ( & V_199 ) ;
}
