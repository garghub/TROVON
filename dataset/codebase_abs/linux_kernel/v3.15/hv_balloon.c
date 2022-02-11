static void F_1 ( unsigned long V_1 , unsigned long V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 ; V_3 ++ ) {
struct V_4 * V_5 ;
V_5 = F_2 ( V_1 + V_3 ) ;
F_3 ( V_5 ) ;
F_4 ( V_5 ) ;
F_5 ( V_5 ) ;
}
}
static void F_6 ( unsigned long V_6 , unsigned long V_2 ,
unsigned long V_7 ,
struct V_8 * V_9 )
{
int V_10 = 0 ;
int V_3 , V_11 ;
unsigned long V_1 ;
unsigned long V_12 ;
unsigned long V_13 = V_7 ;
for ( V_3 = 0 ; V_3 < ( V_2 / V_14 ) ; V_3 ++ ) {
V_1 = V_6 + ( V_3 * V_14 ) ;
V_9 -> V_15 += V_14 ;
if ( V_13 > V_14 ) {
V_12 = V_14 ;
V_13 -= V_14 ;
} else {
V_12 = V_13 ;
V_13 = 0 ;
}
V_9 -> V_16 += V_12 ;
F_7 ( & V_17 . V_18 ) ;
V_17 . V_19 = true ;
V_11 = F_8 ( F_9 ( V_1 ) ) ;
V_10 = F_10 ( V_11 , F_9 ( ( V_1 ) ) ,
( V_14 << V_20 ) ) ;
if ( V_10 ) {
F_11 ( L_1 , V_10 ) ;
if ( V_10 == - V_21 ) {
V_22 = false ;
}
V_9 -> V_15 -= V_14 ;
V_9 -> V_16 -= V_12 ;
break;
}
F_12 ( & V_17 . V_18 , 5 * V_23 ) ;
}
return;
}
static void F_13 ( struct V_4 * V_5 )
{
struct V_24 * V_25 ;
struct V_8 * V_9 ;
unsigned long V_26 ;
unsigned long V_27 ;
if ( V_17 . V_19 ) {
V_17 . V_19 = false ;
F_14 ( & V_17 . V_18 ) ;
}
F_15 (cur, &dm_device.ha_region_list) {
V_9 = F_16 ( V_25 , struct V_8 , V_28 ) ;
V_26 = ( unsigned long )
F_2 ( V_9 -> V_29 ) ;
V_27 = ( unsigned long ) F_2 ( V_9 -> V_16 ) ;
if ( ( ( unsigned long ) V_5 >= V_26 ) &&
( ( unsigned long ) V_5 < V_27 ) ) {
F_3 ( V_5 ) ;
F_4 ( V_5 ) ;
F_5 ( V_5 ) ;
V_9 -> V_29 ++ ;
}
}
}
static bool F_17 ( unsigned long V_1 , unsigned long V_30 )
{
struct V_24 * V_25 ;
struct V_8 * V_9 ;
unsigned long V_31 , V_32 ;
if ( F_18 ( & V_17 . V_33 ) )
return false ;
F_15 (cur, &dm_device.ha_region_list) {
V_9 = F_16 ( V_25 , struct V_8 , V_28 ) ;
if ( ( V_1 >= V_9 -> V_34 ) )
continue;
if ( ( V_1 + V_30 ) > V_9 -> V_34 ) {
V_31 = ( V_1 + V_30 - V_9 -> V_34 ) ;
V_32 = ( V_31 / V_14 ) * V_14 ;
if ( V_31 % V_14 )
V_32 += V_14 ;
V_9 -> V_34 += V_32 ;
}
if ( V_9 -> V_16 != V_1 ) {
V_9 -> V_16 = V_1 ;
V_9 -> V_29 = V_1 ;
}
return true ;
}
return false ;
}
static unsigned long F_19 ( unsigned long V_35 ,
unsigned long V_36 )
{
unsigned long V_1 = V_35 ;
unsigned long V_30 = V_36 ;
unsigned long V_2 ;
struct V_24 * V_25 ;
struct V_8 * V_9 ;
unsigned long V_37 = 0 ;
unsigned long V_38 ;
if ( F_18 ( & V_17 . V_33 ) )
return 0 ;
F_15 (cur, &dm_device.ha_region_list) {
V_9 = F_16 ( V_25 , struct V_8 , V_28 ) ;
if ( ( V_1 >= V_9 -> V_34 ) )
continue;
V_38 = V_9 -> V_16 ;
if ( V_1 < V_9 -> V_15 ) {
V_37 = V_9 -> V_15 - V_1 ;
if ( V_37 > V_30 )
V_37 = V_30 ;
F_1 ( V_1 , V_37 ) ;
V_9 -> V_16 += V_37 ;
V_9 -> V_29 += V_37 ;
V_30 -= V_37 ;
}
if ( ( V_9 -> V_15 < V_9 -> V_34 ) && ( V_30 > 0 ) ) {
V_2 = ( V_9 -> V_34 - V_9 -> V_15 ) ;
if ( V_30 <= V_2 ) {
V_2 = ( ( V_30 / V_14 ) * V_14 ) ;
if ( V_30 % V_14 )
V_2 += V_14 ;
} else {
V_30 = V_2 ;
}
F_6 ( V_9 -> V_15 , V_2 , V_30 , V_9 ) ;
}
return V_9 -> V_16 - V_38 ;
}
return 0 ;
}
static unsigned long F_20 ( unsigned long V_35 ,
unsigned long V_30 ,
unsigned long V_39 ,
unsigned long V_40 )
{
struct V_8 * V_41 = NULL ;
if ( V_30 == 0 )
return 0 ;
if ( ! V_17 . V_42 )
if ( F_17 ( V_35 , V_30 ) )
goto V_43;
if ( V_40 != 0 ) {
V_41 = F_21 ( sizeof( struct V_8 ) , V_44 ) ;
if ( ! V_41 )
return 0 ;
F_22 ( & V_41 -> V_28 ) ;
F_23 ( & V_41 -> V_28 , & V_17 . V_33 ) ;
V_41 -> V_1 = V_39 ;
V_41 -> V_15 = V_39 ;
V_41 -> V_29 = V_35 ;
V_41 -> V_16 = V_35 ;
V_41 -> V_34 = V_39 + V_40 ;
}
V_43:
return F_19 ( V_35 , V_30 ) ;
}
static void F_24 ( struct V_45 * V_46 )
{
struct V_47 V_48 ;
#ifdef F_25
unsigned long V_35 , V_30 ;
unsigned long V_39 , V_49 ;
#endif
struct V_50 * V_51 = & V_17 ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
V_48 . V_52 . type = V_53 ;
V_48 . V_52 . V_2 = sizeof( struct V_47 ) ;
#ifdef F_25
V_35 = V_51 -> V_54 . V_55 . V_56 . V_57 ;
V_30 = V_51 -> V_54 . V_55 . V_56 . V_58 ;
V_39 = V_51 -> V_54 . V_59 . V_56 . V_57 ;
V_49 = V_51 -> V_54 . V_59 . V_56 . V_58 ;
if ( ( V_39 == 0 ) && ( ! V_51 -> V_42 ) ) {
unsigned long V_60 ;
unsigned long V_61 ;
V_61 = V_35 ;
V_60 = ( V_30 / V_14 ) * V_14 ;
if ( V_30 % V_14 )
V_60 += V_14 ;
V_61 = ( V_35 / V_14 ) * V_14 ;
V_39 = V_61 ;
V_49 = V_60 ;
}
if ( V_22 )
V_48 . V_62 = F_20 ( V_35 , V_30 ,
V_39 , V_49 ) ;
#endif
if ( V_48 . V_62 > 0 )
V_48 . V_63 = 1 ;
else if ( ! V_22 )
V_48 . V_63 = 1 ;
else
V_48 . V_63 = 0 ;
if ( ! V_22 || ( V_48 . V_62 == 0 ) )
F_11 ( L_2 ) ;
V_51 -> V_64 = V_65 ;
V_48 . V_52 . V_66 = F_26 ( & V_66 ) ;
F_27 ( V_51 -> V_67 -> V_68 , & V_48 ,
sizeof( struct V_47 ) ,
( unsigned long ) NULL ,
V_69 , 0 ) ;
}
static void F_28 ( struct V_50 * V_51 , struct V_70 * V_71 )
{
struct V_72 * V_73 ;
V_73 = (struct V_72 * ) V_71 -> V_74 ;
switch ( V_73 -> type ) {
case V_75 :
F_11 ( L_3 ) ;
F_11 ( L_4 , V_73 -> V_76 ) ;
break;
default:
F_11 ( L_5 , V_73 -> type ) ;
}
}
static unsigned long F_29 ( void )
{
unsigned long V_77 ;
#define F_30 ( T_1 ) ((mb) << (20 - PAGE_SHIFT))
if ( V_78 < F_30 ( 128 ) )
V_77 = F_30 ( 8 ) + ( V_78 >> 1 ) ;
else if ( V_78 < F_30 ( 512 ) )
V_77 = F_30 ( 40 ) + ( V_78 >> 2 ) ;
else if ( V_78 < F_30 ( 2048 ) )
V_77 = F_30 ( 104 ) + ( V_78 >> 3 ) ;
else
V_77 = F_30 ( 296 ) + ( V_78 >> 5 ) ;
#undef F_30
return V_77 ;
}
static void F_31 ( struct V_50 * V_51 )
{
struct V_79 V_80 ;
struct V_81 V_82 ;
if ( V_83 > 0 ) {
-- V_83 ;
return;
}
F_32 ( & V_82 ) ;
memset ( & V_80 , 0 , sizeof( struct V_79 ) ) ;
V_80 . V_52 . type = V_84 ;
V_80 . V_52 . V_2 = sizeof( struct V_79 ) ;
V_80 . V_52 . V_66 = F_26 ( & V_66 ) ;
V_80 . V_85 = V_82 . V_86 ;
V_80 . V_87 = F_33 () +
V_51 -> V_88 +
F_29 () ;
if ( V_80 . V_52 . V_66 != F_34 ( & V_66 ) )
return;
F_27 ( V_51 -> V_67 -> V_68 , & V_80 ,
sizeof( struct V_79 ) ,
( unsigned long ) NULL ,
V_69 , 0 ) ;
}
static void F_35 ( struct V_50 * V_51 ,
union V_89 * V_90 )
{
int V_91 = V_90 -> V_56 . V_58 ;
T_2 V_92 = V_90 -> V_56 . V_57 ;
struct V_4 * V_5 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_91 ; V_3 ++ ) {
V_5 = F_2 ( V_3 + V_92 ) ;
F_36 ( V_5 ) ;
V_51 -> V_88 -- ;
}
}
static int F_37 ( struct V_50 * V_51 , int V_91 ,
struct V_93 * V_94 , int V_95 ,
bool * V_96 )
{
int V_3 = 0 ;
struct V_4 * V_5 ;
if ( V_91 < V_95 )
return 0 ;
for ( V_3 = 0 ; ( V_3 * V_95 ) < V_91 ; V_3 ++ ) {
if ( V_94 -> V_52 . V_2 + sizeof( union V_89 ) >
V_97 )
return V_3 * V_95 ;
V_5 = F_38 ( V_98 | V_99 |
V_100 | V_101 ,
F_39 ( V_95 << V_20 ) ) ;
if ( ! V_5 ) {
* V_96 = true ;
return V_3 * V_95 ;
}
V_51 -> V_88 += V_95 ;
if ( V_95 != 1 )
F_40 ( V_5 , F_39 ( V_95 << V_20 ) ) ;
V_94 -> V_102 ++ ;
V_94 -> V_90 [ V_3 ] . V_56 . V_57 =
F_41 ( V_5 ) ;
V_94 -> V_90 [ V_3 ] . V_56 . V_58 = V_95 ;
V_94 -> V_52 . V_2 += sizeof( union V_89 ) ;
}
return V_91 ;
}
static void F_42 ( struct V_45 * V_46 )
{
int V_91 = V_17 . V_103 . V_91 ;
int V_104 = 0 ;
struct V_93 * V_94 ;
int V_95 ;
int V_10 ;
bool V_96 = false ;
bool V_105 = false ;
int V_3 ;
V_95 = 512 ;
while ( ! V_105 ) {
V_94 = (struct V_93 * ) V_106 ;
memset ( V_106 , 0 , V_97 ) ;
V_94 -> V_52 . type = V_107 ;
V_94 -> V_52 . V_2 = sizeof( struct V_93 ) ;
V_94 -> V_108 = 1 ;
V_91 -= V_104 ;
V_104 = F_37 ( & V_17 , V_91 ,
V_94 , V_95 ,
& V_96 ) ;
if ( ( V_96 ) && ( V_95 != 1 ) ) {
V_95 = 1 ;
continue;
}
if ( ( V_96 ) || ( V_104 == V_91 ) ) {
V_94 -> V_108 = 0 ;
V_105 = true ;
V_17 . V_64 = V_65 ;
}
do {
V_94 -> V_52 . V_66 = F_26 ( & V_66 ) ;
V_10 = F_27 ( V_17 . V_67 -> V_68 ,
V_94 ,
V_94 -> V_52 . V_2 ,
( unsigned long ) NULL ,
V_69 , 0 ) ;
if ( V_10 == - V_109 )
F_43 ( 20 ) ;
} while ( V_10 == - V_109 );
if ( V_10 ) {
F_11 ( L_6 ) ;
for ( V_3 = 0 ; V_3 < V_94 -> V_102 ; V_3 ++ )
F_35 ( & V_17 ,
& V_94 -> V_90 [ V_3 ] ) ;
V_105 = true ;
}
}
}
static void F_44 ( struct V_50 * V_51 ,
struct V_110 * V_111 )
{
union V_89 * V_90 = V_111 -> V_90 ;
int V_102 = V_111 -> V_102 ;
struct V_112 V_48 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_102 ; V_3 ++ )
F_35 ( V_51 , & V_90 [ V_3 ] ) ;
if ( V_111 -> V_108 == 1 )
return;
memset ( & V_48 , 0 , sizeof( struct V_112 ) ) ;
V_48 . V_52 . type = V_113 ;
V_48 . V_52 . V_66 = F_26 ( & V_66 ) ;
V_48 . V_52 . V_2 = sizeof( struct V_112 ) ;
F_27 ( V_17 . V_67 -> V_68 , & V_48 ,
sizeof( struct V_112 ) ,
( unsigned long ) NULL ,
V_69 , 0 ) ;
V_51 -> V_64 = V_65 ;
}
static int F_45 ( void * V_114 )
{
struct V_50 * V_51 = V_114 ;
int V_115 ;
while ( ! F_46 () ) {
V_115 = F_47 (
& V_17 . V_116 , 1 * V_23 ) ;
if ( V_115 == 0 )
F_31 ( V_51 ) ;
}
return 0 ;
}
static void F_48 ( struct V_50 * V_51 ,
struct V_117 * V_118 )
{
struct V_119 V_120 ;
int V_10 ;
if ( V_118 -> V_121 ) {
F_14 ( & V_51 -> V_122 ) ;
return;
}
if ( V_51 -> V_123 == 0 )
goto V_124;
V_51 -> V_123 = 0 ;
memset ( & V_120 , 0 , sizeof( struct V_119 ) ) ;
V_120 . V_52 . type = V_125 ;
V_120 . V_52 . V_2 = sizeof( struct V_119 ) ;
V_120 . V_52 . V_66 = F_26 ( & V_66 ) ;
V_120 . V_126 . V_126 = V_127 ;
V_120 . V_128 = 1 ;
V_10 = F_27 ( V_51 -> V_67 -> V_68 , & V_120 ,
sizeof( struct V_119 ) ,
( unsigned long ) NULL ,
V_69 , 0 ) ;
if ( V_10 )
goto V_124;
return;
V_124:
V_51 -> V_64 = V_129 ;
F_14 ( & V_51 -> V_122 ) ;
}
static void F_49 ( struct V_50 * V_51 ,
struct V_130 * F_49 )
{
if ( ! F_49 -> V_121 ) {
F_11 ( L_7 ) ;
V_51 -> V_64 = V_129 ;
}
F_14 ( & V_51 -> V_122 ) ;
}
static void F_50 ( void * V_131 )
{
struct V_132 * V_67 = V_131 ;
T_3 V_133 ;
T_4 V_134 ;
struct V_135 * V_136 ;
struct V_137 * V_138 ;
struct V_50 * V_51 = F_51 ( V_67 ) ;
struct V_139 * V_140 ;
struct V_141 * V_142 ;
union V_89 * V_143 ;
union V_89 * V_41 ;
memset ( V_144 , 0 , sizeof( V_144 ) ) ;
F_52 ( V_67 -> V_68 , V_144 ,
V_97 , & V_133 , & V_134 ) ;
if ( V_133 > 0 ) {
V_136 = (struct V_135 * ) V_144 ;
V_138 = & V_136 -> V_52 ;
switch ( V_138 -> type ) {
case V_145 :
F_48 ( V_51 ,
(struct V_117 * ) V_136 ) ;
break;
case V_146 :
F_49 ( V_51 ,
(struct V_130 * ) V_136 ) ;
break;
case V_147 :
if ( V_51 -> V_64 == V_148 )
F_53 ( L_8 ) ;
V_140 = (struct V_139 * ) V_144 ;
V_51 -> V_64 = V_148 ;
V_17 . V_103 . V_91 = V_140 -> V_91 ;
F_54 ( & V_17 . V_103 . V_149 ) ;
break;
case V_150 :
V_51 -> V_64 = V_151 ;
F_44 ( V_51 ,
(struct V_110 * ) V_144 ) ;
break;
case V_152 :
if ( V_51 -> V_64 == V_153 )
F_53 ( L_9 ) ;
V_51 -> V_64 = V_153 ;
V_142 = (struct V_141 * ) V_144 ;
if ( V_142 -> V_52 . V_2 == sizeof( struct V_141 ) ) {
V_143 = & V_142 -> V_154 ;
V_51 -> V_54 . V_55 = * V_143 ;
V_51 -> V_54 . V_59 . V_155 = 0 ;
} else {
V_51 -> V_42 = true ;
V_143 = & V_142 -> V_154 ;
V_41 = & V_143 [ 1 ] ;
V_51 -> V_54 . V_55 = * V_143 ;
V_51 -> V_54 . V_59 = * V_41 ;
}
F_54 ( & V_17 . V_54 . V_149 ) ;
break;
case V_156 :
F_28 ( V_51 , (struct V_70 * ) V_136 ) ;
break;
default:
F_55 ( L_10 , V_138 -> type ) ;
}
}
}
static int F_56 ( struct V_132 * V_67 ,
const struct V_157 * V_158 )
{
int V_10 , V_115 ;
struct V_119 V_120 ;
struct V_159 V_160 ;
V_22 = V_161 ;
V_106 = F_57 ( V_97 , V_44 ) ;
if ( ! V_106 )
return - V_162 ;
V_10 = F_58 ( V_67 -> V_68 , V_163 , V_163 , NULL , 0 ,
F_50 , V_67 ) ;
if ( V_10 )
goto V_164;
V_17 . V_67 = V_67 ;
V_17 . V_64 = V_165 ;
V_17 . V_123 = V_127 ;
F_7 ( & V_17 . V_122 ) ;
F_7 ( & V_17 . V_116 ) ;
F_22 ( & V_17 . V_33 ) ;
F_59 ( & V_17 . V_103 . V_149 , F_42 ) ;
F_59 ( & V_17 . V_54 . V_149 , F_24 ) ;
V_17 . V_42 = false ;
V_17 . V_166 =
F_60 ( F_45 , & V_17 , L_11 ) ;
if ( F_61 ( V_17 . V_166 ) ) {
V_10 = F_62 ( V_17 . V_166 ) ;
goto V_167;
}
#ifdef F_25
F_63 ( & F_13 ) ;
#endif
F_64 ( V_67 , & V_17 ) ;
memset ( & V_120 , 0 , sizeof( struct V_119 ) ) ;
V_120 . V_52 . type = V_125 ;
V_120 . V_52 . V_2 = sizeof( struct V_119 ) ;
V_120 . V_52 . V_66 = F_26 ( & V_66 ) ;
V_120 . V_126 . V_126 = V_168 ;
V_120 . V_128 = 0 ;
V_10 = F_27 ( V_67 -> V_68 , & V_120 ,
sizeof( struct V_119 ) ,
( unsigned long ) NULL ,
V_69 , 0 ) ;
if ( V_10 )
goto V_169;
V_115 = F_12 ( & V_17 . V_122 , 5 * V_23 ) ;
if ( V_115 == 0 ) {
V_10 = - V_170 ;
goto V_169;
}
if ( V_17 . V_64 == V_129 ) {
V_10 = - V_170 ;
goto V_169;
}
memset ( & V_160 , 0 , sizeof( struct V_159 ) ) ;
V_160 . V_52 . type = V_171 ;
V_160 . V_52 . V_2 = sizeof( struct V_159 ) ;
V_160 . V_52 . V_66 = F_26 ( & V_66 ) ;
V_160 . V_172 . V_173 . V_174 = 1 ;
V_160 . V_172 . V_173 . V_161 = 1 ;
V_160 . V_172 . V_173 . V_175 = 7 ;
V_160 . V_176 = 0 ;
V_160 . V_177 = - 1 ;
V_10 = F_27 ( V_67 -> V_68 , & V_160 ,
sizeof( struct V_159 ) ,
( unsigned long ) NULL ,
V_69 , 0 ) ;
if ( V_10 )
goto V_169;
V_115 = F_12 ( & V_17 . V_122 , 5 * V_23 ) ;
if ( V_115 == 0 ) {
V_10 = - V_170 ;
goto V_169;
}
if ( V_17 . V_64 == V_129 ) {
V_10 = - V_170 ;
goto V_169;
}
V_17 . V_64 = V_65 ;
return 0 ;
V_169:
#ifdef F_25
F_65 ( & F_13 ) ;
#endif
F_66 ( V_17 . V_166 ) ;
V_167:
F_67 ( V_67 -> V_68 ) ;
V_164:
F_68 ( V_106 ) ;
return V_10 ;
}
static int F_69 ( struct V_132 * V_67 )
{
struct V_50 * V_51 = F_51 ( V_67 ) ;
struct V_24 * V_25 , * V_178 ;
struct V_8 * V_9 ;
if ( V_51 -> V_88 != 0 )
F_53 ( L_12 , V_51 -> V_88 ) ;
F_70 ( & V_51 -> V_103 . V_149 ) ;
F_70 ( & V_51 -> V_54 . V_149 ) ;
F_67 ( V_67 -> V_68 ) ;
F_66 ( V_51 -> V_166 ) ;
F_68 ( V_106 ) ;
#ifdef F_25
F_65 ( & F_13 ) ;
#endif
F_71 (cur, tmp, &dm->ha_region_list) {
V_9 = F_16 ( V_25 , struct V_8 , V_28 ) ;
F_72 ( & V_9 -> V_28 ) ;
F_68 ( V_9 ) ;
}
return 0 ;
}
static int T_5 F_73 ( void )
{
return F_74 ( & V_179 ) ;
}
