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
F_13 ( & V_17 ) ;
}
return;
}
static void F_14 ( struct V_4 * V_5 )
{
struct V_24 * V_25 ;
struct V_8 * V_9 ;
unsigned long V_26 ;
unsigned long V_27 ;
if ( V_17 . V_19 ) {
V_17 . V_19 = false ;
F_15 ( & V_17 . V_18 ) ;
}
F_16 (cur, &dm_device.ha_region_list) {
V_9 = F_17 ( V_25 , struct V_8 , V_28 ) ;
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
static bool F_18 ( unsigned long V_1 , unsigned long V_30 )
{
struct V_24 * V_25 ;
struct V_8 * V_9 ;
unsigned long V_31 , V_32 ;
if ( F_19 ( & V_17 . V_33 ) )
return false ;
F_16 (cur, &dm_device.ha_region_list) {
V_9 = F_17 ( V_25 , struct V_8 , V_28 ) ;
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
static unsigned long F_20 ( unsigned long V_35 ,
unsigned long V_36 )
{
unsigned long V_1 = V_35 ;
unsigned long V_30 = V_36 ;
unsigned long V_2 ;
struct V_24 * V_25 ;
struct V_8 * V_9 ;
unsigned long V_37 = 0 ;
unsigned long V_38 ;
if ( F_19 ( & V_17 . V_33 ) )
return 0 ;
F_16 (cur, &dm_device.ha_region_list) {
V_9 = F_17 ( V_25 , struct V_8 , V_28 ) ;
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
static unsigned long F_21 ( unsigned long V_35 ,
unsigned long V_30 ,
unsigned long V_39 ,
unsigned long V_40 )
{
struct V_8 * V_41 = NULL ;
if ( V_30 == 0 )
return 0 ;
if ( ! V_17 . V_42 )
if ( F_18 ( V_35 , V_30 ) )
goto V_43;
if ( V_40 != 0 ) {
V_41 = F_22 ( sizeof( struct V_8 ) , V_44 ) ;
if ( ! V_41 )
return 0 ;
F_23 ( & V_41 -> V_28 ) ;
F_24 ( & V_41 -> V_28 , & V_17 . V_33 ) ;
V_41 -> V_1 = V_39 ;
V_41 -> V_15 = V_39 ;
V_41 -> V_29 = V_35 ;
V_41 -> V_16 = V_35 ;
V_41 -> V_34 = V_39 + V_40 ;
}
V_43:
return F_20 ( V_35 , V_30 ) ;
}
static void F_25 ( struct V_45 * V_46 )
{
struct V_47 V_48 ;
#ifdef F_26
unsigned long V_35 , V_30 ;
unsigned long V_39 , V_49 ;
#endif
struct V_50 * V_51 = & V_17 ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
V_48 . V_52 . type = V_53 ;
V_48 . V_52 . V_2 = sizeof( struct V_47 ) ;
#ifdef F_26
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
V_48 . V_62 = F_21 ( V_35 , V_30 ,
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
V_48 . V_52 . V_66 = F_27 ( & V_66 ) ;
F_28 ( V_51 -> V_67 -> V_68 , & V_48 ,
sizeof( struct V_47 ) ,
( unsigned long ) NULL ,
V_69 , 0 ) ;
}
static void F_29 ( struct V_50 * V_51 , struct V_70 * V_71 )
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
static unsigned long F_30 ( void )
{
unsigned long V_77 ;
#define F_31 ( T_1 ) ((mb) << (20 - PAGE_SHIFT))
if ( V_78 < F_31 ( 128 ) )
V_77 = F_31 ( 8 ) + ( V_78 >> 1 ) ;
else if ( V_78 < F_31 ( 512 ) )
V_77 = F_31 ( 40 ) + ( V_78 >> 2 ) ;
else if ( V_78 < F_31 ( 2048 ) )
V_77 = F_31 ( 104 ) + ( V_78 >> 3 ) ;
else
V_77 = F_31 ( 296 ) + ( V_78 >> 5 ) ;
#undef F_31
return V_77 ;
}
static void F_13 ( struct V_50 * V_51 )
{
struct V_79 V_80 ;
struct V_81 V_82 ;
unsigned long V_83 = V_84 ;
unsigned long V_85 = V_86 ;
if ( V_87 > 0 ) {
-- V_87 ;
return;
}
if ( ! F_32 ( V_83 , ( V_86 + V_23 ) ) )
return;
F_33 ( & V_82 ) ;
memset ( & V_80 , 0 , sizeof( struct V_79 ) ) ;
V_80 . V_52 . type = V_88 ;
V_80 . V_52 . V_2 = sizeof( struct V_79 ) ;
V_80 . V_52 . V_66 = F_27 ( & V_66 ) ;
V_80 . V_89 = V_82 . V_90 ;
V_80 . V_91 = F_34 () +
V_51 -> V_92 +
F_30 () ;
if ( V_80 . V_52 . V_66 != F_35 ( & V_66 ) )
return;
if ( V_85 != V_86 )
return;
V_86 = V_84 ;
F_28 ( V_51 -> V_67 -> V_68 , & V_80 ,
sizeof( struct V_79 ) ,
( unsigned long ) NULL ,
V_69 , 0 ) ;
}
static void F_36 ( struct V_50 * V_51 ,
union V_93 * V_94 )
{
int V_95 = V_94 -> V_56 . V_58 ;
T_2 V_96 = V_94 -> V_56 . V_57 ;
struct V_4 * V_5 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_95 ; V_3 ++ ) {
V_5 = F_2 ( V_3 + V_96 ) ;
F_37 ( V_5 ) ;
V_51 -> V_92 -- ;
}
}
static int F_38 ( struct V_50 * V_51 , int V_95 ,
struct V_97 * V_98 , int V_99 ,
bool * V_100 )
{
int V_3 = 0 ;
struct V_4 * V_5 ;
if ( V_95 < V_99 )
return 0 ;
for ( V_3 = 0 ; ( V_3 * V_99 ) < V_95 ; V_3 ++ ) {
if ( V_98 -> V_52 . V_2 + sizeof( union V_93 ) >
V_101 )
return V_3 * V_99 ;
V_5 = F_39 ( V_102 | V_103 |
V_104 | V_105 ,
F_40 ( V_99 << V_20 ) ) ;
if ( ! V_5 ) {
* V_100 = true ;
return V_3 * V_99 ;
}
V_51 -> V_92 += V_99 ;
if ( V_99 != 1 )
F_41 ( V_5 , F_40 ( V_99 << V_20 ) ) ;
V_98 -> V_106 ++ ;
V_98 -> V_94 [ V_3 ] . V_56 . V_57 =
F_42 ( V_5 ) ;
V_98 -> V_94 [ V_3 ] . V_56 . V_58 = V_99 ;
V_98 -> V_52 . V_2 += sizeof( union V_93 ) ;
}
return V_95 ;
}
static void F_43 ( struct V_45 * V_46 )
{
int V_95 = V_17 . V_107 . V_95 ;
int V_108 = 0 ;
struct V_97 * V_98 ;
int V_99 ;
int V_10 ;
bool V_100 = false ;
bool V_109 = false ;
int V_3 ;
V_99 = 512 ;
while ( ! V_109 ) {
V_98 = (struct V_97 * ) V_110 ;
memset ( V_110 , 0 , V_101 ) ;
V_98 -> V_52 . type = V_111 ;
V_98 -> V_52 . V_2 = sizeof( struct V_97 ) ;
V_98 -> V_112 = 1 ;
V_95 -= V_108 ;
V_108 = F_38 ( & V_17 , V_95 ,
V_98 , V_99 ,
& V_100 ) ;
if ( ( V_100 ) && ( V_99 != 1 ) ) {
V_99 = 1 ;
continue;
}
if ( ( V_100 ) || ( V_108 == V_95 ) ) {
V_98 -> V_112 = 0 ;
V_109 = true ;
V_17 . V_64 = V_65 ;
}
do {
V_98 -> V_52 . V_66 = F_27 ( & V_66 ) ;
V_10 = F_28 ( V_17 . V_67 -> V_68 ,
V_98 ,
V_98 -> V_52 . V_2 ,
( unsigned long ) NULL ,
V_69 , 0 ) ;
if ( V_10 == - V_113 )
F_44 ( 20 ) ;
F_13 ( & V_17 ) ;
} while ( V_10 == - V_113 );
if ( V_10 ) {
F_11 ( L_6 ) ;
for ( V_3 = 0 ; V_3 < V_98 -> V_106 ; V_3 ++ )
F_36 ( & V_17 ,
& V_98 -> V_94 [ V_3 ] ) ;
V_109 = true ;
}
}
}
static void F_45 ( struct V_50 * V_51 ,
struct V_114 * V_115 )
{
union V_93 * V_94 = V_115 -> V_94 ;
int V_106 = V_115 -> V_106 ;
struct V_116 V_48 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_106 ; V_3 ++ ) {
F_36 ( V_51 , & V_94 [ V_3 ] ) ;
F_13 ( & V_17 ) ;
}
if ( V_115 -> V_112 == 1 )
return;
memset ( & V_48 , 0 , sizeof( struct V_116 ) ) ;
V_48 . V_52 . type = V_117 ;
V_48 . V_52 . V_66 = F_27 ( & V_66 ) ;
V_48 . V_52 . V_2 = sizeof( struct V_116 ) ;
F_28 ( V_17 . V_67 -> V_68 , & V_48 ,
sizeof( struct V_116 ) ,
( unsigned long ) NULL ,
V_69 , 0 ) ;
V_51 -> V_64 = V_65 ;
}
static int F_46 ( void * V_118 )
{
struct V_50 * V_51 = V_118 ;
int V_119 ;
while ( ! F_47 () ) {
V_119 = F_48 (
& V_17 . V_120 , 1 * V_23 ) ;
if ( V_119 == 0 )
F_13 ( V_51 ) ;
}
return 0 ;
}
static void F_49 ( struct V_50 * V_51 ,
struct V_121 * V_122 )
{
struct V_123 V_124 ;
int V_10 ;
if ( V_122 -> V_125 ) {
F_15 ( & V_51 -> V_126 ) ;
return;
}
if ( V_51 -> V_127 == 0 )
goto V_128;
V_51 -> V_127 = 0 ;
memset ( & V_124 , 0 , sizeof( struct V_123 ) ) ;
V_124 . V_52 . type = V_129 ;
V_124 . V_52 . V_2 = sizeof( struct V_123 ) ;
V_124 . V_52 . V_66 = F_27 ( & V_66 ) ;
V_124 . V_130 . V_130 = V_131 ;
V_124 . V_132 = 1 ;
V_10 = F_28 ( V_51 -> V_67 -> V_68 , & V_124 ,
sizeof( struct V_123 ) ,
( unsigned long ) NULL ,
V_69 , 0 ) ;
if ( V_10 )
goto V_128;
return;
V_128:
V_51 -> V_64 = V_133 ;
F_15 ( & V_51 -> V_126 ) ;
}
static void F_50 ( struct V_50 * V_51 ,
struct V_134 * F_50 )
{
if ( ! F_50 -> V_125 ) {
F_11 ( L_7 ) ;
V_51 -> V_64 = V_133 ;
}
F_15 ( & V_51 -> V_126 ) ;
}
static void F_51 ( void * V_135 )
{
struct V_136 * V_67 = V_135 ;
T_3 V_137 ;
T_4 V_138 ;
struct V_139 * V_140 ;
struct V_141 * V_142 ;
struct V_50 * V_51 = F_52 ( V_67 ) ;
struct V_143 * V_144 ;
struct V_145 * V_146 ;
union V_93 * V_147 ;
union V_93 * V_41 ;
memset ( V_148 , 0 , sizeof( V_148 ) ) ;
F_53 ( V_67 -> V_68 , V_148 ,
V_101 , & V_137 , & V_138 ) ;
if ( V_137 > 0 ) {
V_140 = (struct V_139 * ) V_148 ;
V_142 = & V_140 -> V_52 ;
switch ( V_142 -> type ) {
case V_149 :
F_49 ( V_51 ,
(struct V_121 * ) V_140 ) ;
break;
case V_150 :
F_50 ( V_51 ,
(struct V_134 * ) V_140 ) ;
break;
case V_151 :
if ( V_51 -> V_64 == V_152 )
F_54 ( L_8 ) ;
V_144 = (struct V_143 * ) V_148 ;
V_51 -> V_64 = V_152 ;
V_17 . V_107 . V_95 = V_144 -> V_95 ;
F_55 ( & V_17 . V_107 . V_153 ) ;
break;
case V_154 :
V_51 -> V_64 = V_155 ;
F_45 ( V_51 ,
(struct V_114 * ) V_148 ) ;
break;
case V_156 :
if ( V_51 -> V_64 == V_157 )
F_54 ( L_9 ) ;
V_51 -> V_64 = V_157 ;
V_146 = (struct V_145 * ) V_148 ;
if ( V_146 -> V_52 . V_2 == sizeof( struct V_145 ) ) {
V_147 = & V_146 -> V_158 ;
V_51 -> V_54 . V_55 = * V_147 ;
V_51 -> V_54 . V_59 . V_159 = 0 ;
} else {
V_51 -> V_42 = true ;
V_147 = & V_146 -> V_158 ;
V_41 = & V_147 [ 1 ] ;
V_51 -> V_54 . V_55 = * V_147 ;
V_51 -> V_54 . V_59 = * V_41 ;
}
F_55 ( & V_17 . V_54 . V_153 ) ;
break;
case V_160 :
F_29 ( V_51 , (struct V_70 * ) V_140 ) ;
break;
default:
F_56 ( L_10 , V_142 -> type ) ;
}
}
}
static int F_57 ( struct V_136 * V_67 ,
const struct V_161 * V_162 )
{
int V_10 , V_119 ;
struct V_123 V_124 ;
struct V_163 V_164 ;
V_22 = V_165 ;
V_110 = F_58 ( V_101 , V_44 ) ;
if ( ! V_110 )
return - V_166 ;
V_10 = F_59 ( V_67 -> V_68 , V_167 , V_167 , NULL , 0 ,
F_51 , V_67 ) ;
if ( V_10 )
goto V_168;
V_17 . V_67 = V_67 ;
V_17 . V_64 = V_169 ;
V_17 . V_127 = V_131 ;
F_7 ( & V_17 . V_126 ) ;
F_7 ( & V_17 . V_120 ) ;
F_23 ( & V_17 . V_33 ) ;
F_60 ( & V_17 . V_107 . V_153 , F_43 ) ;
F_60 ( & V_17 . V_54 . V_153 , F_25 ) ;
V_17 . V_42 = false ;
V_17 . V_170 =
F_61 ( F_46 , & V_17 , L_11 ) ;
if ( F_62 ( V_17 . V_170 ) ) {
V_10 = F_63 ( V_17 . V_170 ) ;
goto V_171;
}
#ifdef F_26
F_64 ( & F_14 ) ;
#endif
F_65 ( V_67 , & V_17 ) ;
memset ( & V_124 , 0 , sizeof( struct V_123 ) ) ;
V_124 . V_52 . type = V_129 ;
V_124 . V_52 . V_2 = sizeof( struct V_123 ) ;
V_124 . V_52 . V_66 = F_27 ( & V_66 ) ;
V_124 . V_130 . V_130 = V_172 ;
V_124 . V_132 = 0 ;
V_10 = F_28 ( V_67 -> V_68 , & V_124 ,
sizeof( struct V_123 ) ,
( unsigned long ) NULL ,
V_69 , 0 ) ;
if ( V_10 )
goto V_173;
V_119 = F_12 ( & V_17 . V_126 , 5 * V_23 ) ;
if ( V_119 == 0 ) {
V_10 = - V_174 ;
goto V_173;
}
if ( V_17 . V_64 == V_133 ) {
V_10 = - V_174 ;
goto V_173;
}
memset ( & V_164 , 0 , sizeof( struct V_163 ) ) ;
V_164 . V_52 . type = V_175 ;
V_164 . V_52 . V_2 = sizeof( struct V_163 ) ;
V_164 . V_52 . V_66 = F_27 ( & V_66 ) ;
V_164 . V_176 . V_177 . V_178 = 1 ;
V_164 . V_176 . V_177 . V_165 = 1 ;
V_164 . V_176 . V_177 . V_179 = 7 ;
V_164 . V_180 = 0 ;
V_164 . V_181 = - 1 ;
V_10 = F_28 ( V_67 -> V_68 , & V_164 ,
sizeof( struct V_163 ) ,
( unsigned long ) NULL ,
V_69 , 0 ) ;
if ( V_10 )
goto V_173;
V_119 = F_12 ( & V_17 . V_126 , 5 * V_23 ) ;
if ( V_119 == 0 ) {
V_10 = - V_174 ;
goto V_173;
}
if ( V_17 . V_64 == V_133 ) {
V_10 = - V_174 ;
goto V_173;
}
V_17 . V_64 = V_65 ;
return 0 ;
V_173:
#ifdef F_26
F_66 ( & F_14 ) ;
#endif
F_67 ( V_17 . V_170 ) ;
V_171:
F_68 ( V_67 -> V_68 ) ;
V_168:
F_69 ( V_110 ) ;
return V_10 ;
}
static int F_70 ( struct V_136 * V_67 )
{
struct V_50 * V_51 = F_52 ( V_67 ) ;
struct V_24 * V_25 , * V_182 ;
struct V_8 * V_9 ;
if ( V_51 -> V_92 != 0 )
F_54 ( L_12 , V_51 -> V_92 ) ;
F_71 ( & V_51 -> V_107 . V_153 ) ;
F_71 ( & V_51 -> V_54 . V_153 ) ;
F_68 ( V_67 -> V_68 ) ;
F_67 ( V_51 -> V_170 ) ;
F_69 ( V_110 ) ;
#ifdef F_26
F_66 ( & F_14 ) ;
#endif
F_72 (cur, tmp, &dm->ha_region_list) {
V_9 = F_17 ( V_25 , struct V_8 , V_28 ) ;
F_73 ( & V_9 -> V_28 ) ;
F_69 ( V_9 ) ;
}
return 0 ;
}
static int T_5 F_74 ( void )
{
return F_75 ( & V_183 ) ;
}
