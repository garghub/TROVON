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
int V_3 , V_11 , V_12 ;
unsigned long V_1 ;
unsigned long V_13 ;
unsigned long V_14 = V_7 ;
for ( V_3 = 0 ; V_3 < ( V_2 / V_15 ) ; V_3 ++ ) {
V_1 = V_6 + ( V_3 * V_15 ) ;
V_9 -> V_16 += V_15 ;
if ( V_14 > V_15 ) {
V_13 = V_15 ;
V_14 -= V_15 ;
} else {
V_13 = V_14 ;
V_14 = 0 ;
}
V_9 -> V_17 += V_13 ;
F_7 ( & V_18 . V_19 ) ;
V_18 . V_20 = true ;
V_11 = F_8 ( F_9 ( V_1 ) ) ;
V_10 = F_10 ( V_11 , F_9 ( ( V_1 ) ) ,
( V_15 << V_21 ) ) ;
if ( V_10 ) {
F_11 ( L_1 , V_10 ) ;
if ( V_10 == - V_22 ) {
V_23 = false ;
}
V_9 -> V_16 -= V_15 ;
V_9 -> V_17 -= V_13 ;
break;
}
V_12 = F_12 ( & V_18 . V_19 , 5 * V_24 ) ;
if ( V_12 == 0 ) {
F_11 ( L_2 ) ;
V_9 -> V_16 -= V_15 ;
V_9 -> V_17 -= V_13 ;
break;
}
}
return;
}
static void F_13 ( struct V_4 * V_5 )
{
struct V_25 * V_26 ;
struct V_8 * V_9 ;
unsigned long V_27 ;
unsigned long V_28 ;
if ( V_18 . V_20 ) {
V_18 . V_20 = false ;
F_14 ( & V_18 . V_19 ) ;
}
F_15 (cur, &dm_device.ha_region_list) {
V_9 = F_16 ( V_26 , struct V_8 , V_29 ) ;
V_27 = ( unsigned long )
F_2 ( V_9 -> V_30 ) ;
V_28 = ( unsigned long ) F_2 ( V_9 -> V_17 ) ;
if ( ( ( unsigned long ) V_5 >= V_27 ) &&
( ( unsigned long ) V_5 < V_28 ) ) {
F_3 ( V_5 ) ;
F_4 ( V_5 ) ;
F_5 ( V_5 ) ;
V_9 -> V_30 ++ ;
}
}
}
static bool F_17 ( unsigned long V_1 , unsigned long V_31 )
{
struct V_25 * V_26 ;
struct V_8 * V_9 ;
unsigned long V_32 , V_33 ;
if ( F_18 ( & V_18 . V_34 ) )
return false ;
F_15 (cur, &dm_device.ha_region_list) {
V_9 = F_16 ( V_26 , struct V_8 , V_29 ) ;
if ( ( V_1 >= V_9 -> V_35 ) )
continue;
if ( ( V_1 + V_31 ) > V_9 -> V_35 ) {
V_32 = ( V_1 + V_31 - V_9 -> V_35 ) ;
V_33 = ( V_32 / V_15 ) * V_15 ;
if ( V_32 % V_15 )
V_33 += V_15 ;
V_9 -> V_35 += V_33 ;
}
if ( V_9 -> V_17 != V_1 ) {
V_9 -> V_17 = V_1 ;
V_9 -> V_30 = V_1 ;
}
return true ;
}
return false ;
}
static unsigned long F_19 ( unsigned long V_36 ,
unsigned long V_37 )
{
unsigned long V_1 = V_36 ;
unsigned long V_31 = V_37 ;
unsigned long V_2 ;
struct V_25 * V_26 ;
struct V_8 * V_9 ;
unsigned long V_38 = 0 ;
unsigned long V_39 ;
if ( F_18 ( & V_18 . V_34 ) )
return 0 ;
F_15 (cur, &dm_device.ha_region_list) {
V_9 = F_16 ( V_26 , struct V_8 , V_29 ) ;
if ( ( V_1 >= V_9 -> V_35 ) )
continue;
V_39 = V_9 -> V_17 ;
if ( V_1 < V_9 -> V_16 ) {
V_38 = V_9 -> V_16 - V_1 ;
if ( V_38 > V_31 )
V_38 = V_31 ;
F_1 ( V_1 , V_38 ) ;
V_9 -> V_17 += V_38 ;
V_9 -> V_30 += V_38 ;
V_31 -= V_38 ;
}
if ( ( V_9 -> V_16 < V_9 -> V_35 ) && ( V_31 > 0 ) ) {
V_2 = ( V_9 -> V_35 - V_9 -> V_16 ) ;
if ( V_31 <= V_2 ) {
V_2 = ( ( V_31 / V_15 ) * V_15 ) ;
if ( V_31 % V_15 )
V_2 += V_15 ;
} else {
V_31 = V_2 ;
}
F_6 ( V_9 -> V_16 , V_2 , V_31 , V_9 ) ;
}
return V_9 -> V_17 - V_39 ;
}
return 0 ;
}
static unsigned long F_20 ( unsigned long V_36 ,
unsigned long V_31 ,
unsigned long V_40 ,
unsigned long V_41 )
{
struct V_8 * V_42 = NULL ;
if ( V_31 == 0 )
return 0 ;
if ( ! V_18 . V_43 )
if ( F_17 ( V_36 , V_31 ) )
goto V_44;
if ( V_41 != 0 ) {
V_42 = F_21 ( sizeof( struct V_8 ) , V_45 ) ;
if ( ! V_42 )
return 0 ;
F_22 ( & V_42 -> V_29 ) ;
F_23 ( & V_42 -> V_29 , & V_18 . V_34 ) ;
V_42 -> V_1 = V_40 ;
V_42 -> V_16 = V_40 ;
V_42 -> V_30 = V_36 ;
V_42 -> V_17 = V_36 ;
V_42 -> V_35 = V_40 + V_41 ;
}
V_44:
return F_19 ( V_36 , V_31 ) ;
}
static void F_24 ( struct V_46 * V_47 )
{
struct V_48 V_49 ;
#ifdef F_25
unsigned long V_36 , V_31 ;
unsigned long V_40 , V_50 ;
#endif
struct V_51 * V_52 = & V_18 ;
memset ( & V_49 , 0 , sizeof( struct V_48 ) ) ;
V_49 . V_53 . type = V_54 ;
V_49 . V_53 . V_2 = sizeof( struct V_48 ) ;
V_49 . V_53 . V_55 = F_26 ( & V_55 ) ;
#ifdef F_25
V_36 = V_52 -> V_56 . V_57 . V_58 . V_59 ;
V_31 = V_52 -> V_56 . V_57 . V_58 . V_60 ;
V_40 = V_52 -> V_56 . V_61 . V_58 . V_59 ;
V_50 = V_52 -> V_56 . V_61 . V_58 . V_60 ;
if ( ( V_40 == 0 ) && ( ! V_52 -> V_43 ) ) {
unsigned long V_62 ;
unsigned long V_63 ;
V_63 = V_36 ;
V_62 = ( V_31 / V_15 ) * V_15 ;
if ( V_31 % V_15 )
V_62 += V_15 ;
V_63 = ( V_36 / V_15 ) * V_15 ;
V_40 = V_63 ;
V_50 = V_62 ;
}
if ( V_23 )
V_49 . V_64 = F_20 ( V_36 , V_31 ,
V_40 , V_50 ) ;
#endif
if ( V_49 . V_64 > 0 )
V_49 . V_65 = 1 ;
else if ( ! V_23 )
V_49 . V_65 = 1 ;
else
V_49 . V_65 = 0 ;
if ( ! V_23 || ( V_49 . V_64 == 0 ) )
F_11 ( L_3 ) ;
V_52 -> V_66 = V_67 ;
F_27 ( V_52 -> V_68 -> V_69 , & V_49 ,
sizeof( struct V_48 ) ,
( unsigned long ) NULL ,
V_70 , 0 ) ;
}
static void F_28 ( struct V_51 * V_52 , struct V_71 * V_72 )
{
struct V_73 * V_74 ;
V_74 = (struct V_73 * ) V_72 -> V_75 ;
switch ( V_74 -> type ) {
case V_76 :
F_11 ( L_4 ) ;
F_11 ( L_5 , V_74 -> V_77 ) ;
break;
default:
F_11 ( L_6 , V_74 -> type ) ;
}
}
static unsigned long F_29 ( void )
{
unsigned long V_78 ;
#define F_30 ( T_1 ) ((mb) << (20 - PAGE_SHIFT))
if ( V_79 < F_30 ( 128 ) )
V_78 = F_30 ( 8 ) + ( V_79 >> 1 ) ;
else if ( V_79 < F_30 ( 512 ) )
V_78 = F_30 ( 40 ) + ( V_79 >> 2 ) ;
else if ( V_79 < F_30 ( 2048 ) )
V_78 = F_30 ( 104 ) + ( V_79 >> 3 ) ;
else
V_78 = F_30 ( 296 ) + ( V_79 >> 5 ) ;
#undef F_30
return V_78 ;
}
static void F_31 ( struct V_51 * V_52 )
{
struct V_80 V_81 ;
struct V_82 V_83 ;
if ( V_84 > 0 ) {
-- V_84 ;
return;
}
F_32 ( & V_83 ) ;
memset ( & V_81 , 0 , sizeof( struct V_80 ) ) ;
V_81 . V_53 . type = V_85 ;
V_81 . V_53 . V_2 = sizeof( struct V_80 ) ;
V_81 . V_53 . V_55 = F_26 ( & V_55 ) ;
V_81 . V_86 = V_83 . V_87 ;
V_81 . V_88 = F_33 () +
V_52 -> V_89 +
F_29 () ;
F_27 ( V_52 -> V_68 -> V_69 , & V_81 ,
sizeof( struct V_80 ) ,
( unsigned long ) NULL ,
V_70 , 0 ) ;
}
static void F_34 ( struct V_51 * V_52 ,
union V_90 * V_91 )
{
int V_92 = V_91 -> V_58 . V_60 ;
T_2 V_93 = V_91 -> V_58 . V_59 ;
struct V_4 * V_5 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_92 ; V_3 ++ ) {
V_5 = F_2 ( V_3 + V_93 ) ;
F_35 ( V_5 ) ;
V_52 -> V_89 -- ;
}
}
static int F_36 ( struct V_51 * V_52 , int V_92 ,
struct V_94 * V_95 , int V_96 ,
bool * V_97 )
{
int V_3 = 0 ;
struct V_4 * V_5 ;
if ( V_92 < V_96 )
return 0 ;
for ( V_3 = 0 ; ( V_3 * V_96 ) < V_92 ; V_3 ++ ) {
if ( V_95 -> V_53 . V_2 + sizeof( union V_90 ) >
V_98 )
return V_3 * V_96 ;
V_5 = F_37 ( V_99 | V_100 |
V_101 | V_102 ,
F_38 ( V_96 << V_21 ) ) ;
if ( ! V_5 ) {
* V_97 = true ;
return V_3 * V_96 ;
}
V_52 -> V_89 += V_96 ;
if ( V_96 != 1 )
F_39 ( V_5 , F_38 ( V_96 << V_21 ) ) ;
V_95 -> V_103 ++ ;
V_95 -> V_91 [ V_3 ] . V_58 . V_59 =
F_40 ( V_5 ) ;
V_95 -> V_91 [ V_3 ] . V_58 . V_60 = V_96 ;
V_95 -> V_53 . V_2 += sizeof( union V_90 ) ;
}
return V_92 ;
}
static void F_41 ( struct V_46 * V_47 )
{
int V_92 = V_18 . V_104 . V_92 ;
int V_105 = 0 ;
struct V_94 * V_95 ;
int V_96 ;
int V_10 ;
bool V_97 = false ;
bool V_106 = false ;
int V_3 ;
V_96 = 512 ;
while ( ! V_106 ) {
V_95 = (struct V_94 * ) V_107 ;
memset ( V_107 , 0 , V_98 ) ;
V_95 -> V_53 . type = V_108 ;
V_95 -> V_53 . V_55 = F_26 ( & V_55 ) ;
V_95 -> V_53 . V_2 = sizeof( struct V_94 ) ;
V_95 -> V_109 = 1 ;
V_92 -= V_105 ;
V_105 = F_36 ( & V_18 , V_92 ,
V_95 , V_96 ,
& V_97 ) ;
if ( ( V_97 ) && ( V_96 != 1 ) ) {
V_96 = 1 ;
continue;
}
if ( ( V_97 ) || ( V_105 == V_92 ) ) {
V_95 -> V_109 = 0 ;
V_106 = true ;
V_18 . V_66 = V_67 ;
}
do {
V_10 = F_27 ( V_18 . V_68 -> V_69 ,
V_95 ,
V_95 -> V_53 . V_2 ,
( unsigned long ) NULL ,
V_70 , 0 ) ;
if ( V_10 == - V_110 )
F_42 ( 20 ) ;
} while ( V_10 == - V_110 );
if ( V_10 ) {
F_11 ( L_7 ) ;
for ( V_3 = 0 ; V_3 < V_95 -> V_103 ; V_3 ++ )
F_34 ( & V_18 ,
& V_95 -> V_91 [ V_3 ] ) ;
V_106 = true ;
}
}
}
static void F_43 ( struct V_51 * V_52 ,
struct V_111 * V_112 )
{
union V_90 * V_91 = V_112 -> V_91 ;
int V_103 = V_112 -> V_103 ;
struct V_113 V_49 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_103 ; V_3 ++ )
F_34 ( V_52 , & V_91 [ V_3 ] ) ;
if ( V_112 -> V_109 == 1 )
return;
memset ( & V_49 , 0 , sizeof( struct V_113 ) ) ;
V_49 . V_53 . type = V_114 ;
V_49 . V_53 . V_55 = F_26 ( & V_55 ) ;
V_49 . V_53 . V_2 = sizeof( struct V_113 ) ;
F_27 ( V_18 . V_68 -> V_69 , & V_49 ,
sizeof( struct V_113 ) ,
( unsigned long ) NULL ,
V_70 , 0 ) ;
V_52 -> V_66 = V_67 ;
}
static int F_44 ( void * V_115 )
{
struct V_51 * V_52 = V_115 ;
int V_12 ;
while ( ! F_45 () ) {
V_12 = F_12 ( & V_18 . V_116 , 1 * V_24 ) ;
if ( V_12 == 0 )
F_31 ( V_52 ) ;
}
return 0 ;
}
static void F_46 ( struct V_51 * V_52 ,
struct V_117 * V_118 )
{
struct V_119 V_120 ;
int V_10 ;
if ( V_118 -> V_121 ) {
F_14 ( & V_52 -> V_122 ) ;
return;
}
if ( V_52 -> V_123 == 0 )
goto V_124;
V_52 -> V_123 = 0 ;
memset ( & V_120 , 0 , sizeof( struct V_119 ) ) ;
V_120 . V_53 . type = V_125 ;
V_120 . V_53 . V_2 = sizeof( struct V_119 ) ;
V_120 . V_53 . V_55 = F_26 ( & V_55 ) ;
V_120 . V_126 . V_126 = V_127 ;
V_120 . V_128 = 1 ;
V_10 = F_27 ( V_52 -> V_68 -> V_69 , & V_120 ,
sizeof( struct V_119 ) ,
( unsigned long ) NULL ,
V_70 , 0 ) ;
if ( V_10 )
goto V_124;
return;
V_124:
V_52 -> V_66 = V_129 ;
F_14 ( & V_52 -> V_122 ) ;
}
static void F_47 ( struct V_51 * V_52 ,
struct V_130 * F_47 )
{
if ( ! F_47 -> V_121 ) {
F_11 ( L_8 ) ;
V_52 -> V_66 = V_129 ;
}
F_14 ( & V_52 -> V_122 ) ;
}
static void F_48 ( void * V_131 )
{
struct V_132 * V_68 = V_131 ;
T_3 V_133 ;
T_4 V_134 ;
struct V_135 * V_136 ;
struct V_137 * V_138 ;
struct V_51 * V_52 = F_49 ( V_68 ) ;
struct V_139 * V_140 ;
struct V_141 * V_142 ;
union V_90 * V_143 ;
union V_90 * V_42 ;
memset ( V_144 , 0 , sizeof( V_144 ) ) ;
F_50 ( V_68 -> V_69 , V_144 ,
V_98 , & V_133 , & V_134 ) ;
if ( V_133 > 0 ) {
V_136 = (struct V_135 * ) V_144 ;
V_138 = & V_136 -> V_53 ;
switch ( V_138 -> type ) {
case V_145 :
F_46 ( V_52 ,
(struct V_117 * ) V_136 ) ;
break;
case V_146 :
F_47 ( V_52 ,
(struct V_130 * ) V_136 ) ;
break;
case V_147 :
if ( V_52 -> V_66 == V_148 )
F_51 ( L_9 ) ;
V_140 = (struct V_139 * ) V_144 ;
V_52 -> V_66 = V_148 ;
V_18 . V_104 . V_92 = V_140 -> V_92 ;
F_52 ( & V_18 . V_104 . V_149 ) ;
break;
case V_150 :
V_52 -> V_66 = V_151 ;
F_43 ( V_52 ,
(struct V_111 * ) V_144 ) ;
break;
case V_152 :
if ( V_52 -> V_66 == V_153 )
F_51 ( L_10 ) ;
V_52 -> V_66 = V_153 ;
V_142 = (struct V_141 * ) V_144 ;
if ( V_142 -> V_53 . V_2 == sizeof( struct V_141 ) ) {
V_143 = & V_142 -> V_154 ;
V_52 -> V_56 . V_57 = * V_143 ;
V_52 -> V_56 . V_61 . V_155 = 0 ;
} else {
V_52 -> V_43 = true ;
V_143 = & V_142 -> V_154 ;
V_42 = & V_143 [ 1 ] ;
V_52 -> V_56 . V_57 = * V_143 ;
V_52 -> V_56 . V_61 = * V_42 ;
}
F_52 ( & V_18 . V_56 . V_149 ) ;
break;
case V_156 :
F_28 ( V_52 , (struct V_71 * ) V_136 ) ;
break;
default:
F_53 ( L_11 , V_138 -> type ) ;
}
}
}
static int F_54 ( struct V_132 * V_68 ,
const struct V_157 * V_158 )
{
int V_10 , V_12 ;
struct V_119 V_120 ;
struct V_159 V_160 ;
V_23 = V_161 ;
V_107 = F_55 ( V_98 , V_45 ) ;
if ( ! V_107 )
return - V_162 ;
V_10 = F_56 ( V_68 -> V_69 , V_163 , V_163 , NULL , 0 ,
F_48 , V_68 ) ;
if ( V_10 )
goto V_164;
V_18 . V_68 = V_68 ;
V_18 . V_66 = V_165 ;
V_18 . V_123 = V_127 ;
F_7 ( & V_18 . V_122 ) ;
F_7 ( & V_18 . V_116 ) ;
F_22 ( & V_18 . V_34 ) ;
F_57 ( & V_18 . V_104 . V_149 , F_41 ) ;
F_57 ( & V_18 . V_56 . V_149 , F_24 ) ;
V_18 . V_43 = false ;
V_18 . V_166 =
F_58 ( F_44 , & V_18 , L_12 ) ;
if ( F_59 ( V_18 . V_166 ) ) {
V_10 = F_60 ( V_18 . V_166 ) ;
goto V_167;
}
#ifdef F_25
F_61 ( & F_13 ) ;
#endif
F_62 ( V_68 , & V_18 ) ;
memset ( & V_120 , 0 , sizeof( struct V_119 ) ) ;
V_120 . V_53 . type = V_125 ;
V_120 . V_53 . V_2 = sizeof( struct V_119 ) ;
V_120 . V_53 . V_55 = F_26 ( & V_55 ) ;
V_120 . V_126 . V_126 = V_168 ;
V_120 . V_128 = 0 ;
V_10 = F_27 ( V_68 -> V_69 , & V_120 ,
sizeof( struct V_119 ) ,
( unsigned long ) NULL ,
V_70 , 0 ) ;
if ( V_10 )
goto V_169;
V_12 = F_12 ( & V_18 . V_122 , 5 * V_24 ) ;
if ( V_12 == 0 ) {
V_10 = - V_170 ;
goto V_169;
}
if ( V_18 . V_66 == V_129 ) {
V_10 = - V_170 ;
goto V_169;
}
memset ( & V_160 , 0 , sizeof( struct V_159 ) ) ;
V_160 . V_53 . type = V_171 ;
V_160 . V_53 . V_2 = sizeof( struct V_159 ) ;
V_160 . V_53 . V_55 = F_26 ( & V_55 ) ;
V_160 . V_172 . V_173 . V_174 = 1 ;
V_160 . V_172 . V_173 . V_161 = 1 ;
V_160 . V_172 . V_173 . V_175 = 7 ;
V_160 . V_176 = 0 ;
V_160 . V_177 = - 1 ;
V_10 = F_27 ( V_68 -> V_69 , & V_160 ,
sizeof( struct V_159 ) ,
( unsigned long ) NULL ,
V_70 , 0 ) ;
if ( V_10 )
goto V_169;
V_12 = F_12 ( & V_18 . V_122 , 5 * V_24 ) ;
if ( V_12 == 0 ) {
V_10 = - V_170 ;
goto V_169;
}
if ( V_18 . V_66 == V_129 ) {
V_10 = - V_170 ;
goto V_169;
}
V_18 . V_66 = V_67 ;
return 0 ;
V_169:
#ifdef F_25
F_63 ( & F_13 ) ;
#endif
F_64 ( V_18 . V_166 ) ;
V_167:
F_65 ( V_68 -> V_69 ) ;
V_164:
F_66 ( V_107 ) ;
return V_10 ;
}
static int F_67 ( struct V_132 * V_68 )
{
struct V_51 * V_52 = F_49 ( V_68 ) ;
struct V_25 * V_26 , * V_178 ;
struct V_8 * V_9 ;
if ( V_52 -> V_89 != 0 )
F_51 ( L_13 , V_52 -> V_89 ) ;
F_68 ( & V_52 -> V_104 . V_149 ) ;
F_68 ( & V_52 -> V_56 . V_149 ) ;
F_65 ( V_68 -> V_69 ) ;
F_64 ( V_52 -> V_166 ) ;
F_66 ( V_107 ) ;
#ifdef F_25
F_63 ( & F_13 ) ;
#endif
F_69 (cur, tmp, &dm->ha_region_list) {
V_9 = F_16 ( V_26 , struct V_8 , V_29 ) ;
F_70 ( & V_9 -> V_29 ) ;
F_66 ( V_9 ) ;
}
return 0 ;
}
static int T_5 F_71 ( void )
{
return F_72 ( & V_179 ) ;
}
