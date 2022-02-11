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
bool V_100 ;
bool V_109 = false ;
int V_3 ;
F_44 ( V_95 % V_110 != 0 ) ;
V_99 = 512 ;
while ( ! V_109 ) {
V_98 = (struct V_97 * ) V_111 ;
memset ( V_111 , 0 , V_101 ) ;
V_98 -> V_52 . type = V_112 ;
V_98 -> V_52 . V_2 = sizeof( struct V_97 ) ;
V_98 -> V_113 = 1 ;
V_95 -= V_108 ;
V_100 = false ;
V_108 = F_38 ( & V_17 , V_95 ,
V_98 , V_99 ,
& V_100 ) ;
if ( V_99 != 1 && V_108 == 0 ) {
V_99 = 1 ;
continue;
}
if ( ( V_99 == 1 && V_100 ) ||
( V_108 == V_95 ) ) {
V_98 -> V_113 = 0 ;
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
if ( V_10 == - V_114 )
F_45 ( 20 ) ;
F_13 ( & V_17 ) ;
} while ( V_10 == - V_114 );
if ( V_10 ) {
F_11 ( L_6 ) ;
for ( V_3 = 0 ; V_3 < V_98 -> V_106 ; V_3 ++ )
F_36 ( & V_17 ,
& V_98 -> V_94 [ V_3 ] ) ;
V_109 = true ;
}
}
}
static void F_46 ( struct V_50 * V_51 ,
struct V_115 * V_116 )
{
union V_93 * V_94 = V_116 -> V_94 ;
int V_106 = V_116 -> V_106 ;
struct V_117 V_48 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_106 ; V_3 ++ ) {
F_36 ( V_51 , & V_94 [ V_3 ] ) ;
F_13 ( & V_17 ) ;
}
if ( V_116 -> V_113 == 1 )
return;
memset ( & V_48 , 0 , sizeof( struct V_117 ) ) ;
V_48 . V_52 . type = V_118 ;
V_48 . V_52 . V_66 = F_27 ( & V_66 ) ;
V_48 . V_52 . V_2 = sizeof( struct V_117 ) ;
F_28 ( V_17 . V_67 -> V_68 , & V_48 ,
sizeof( struct V_117 ) ,
( unsigned long ) NULL ,
V_69 , 0 ) ;
V_51 -> V_64 = V_65 ;
}
static int F_47 ( void * V_119 )
{
struct V_50 * V_51 = V_119 ;
int V_120 ;
while ( ! F_48 () ) {
V_120 = F_49 (
& V_17 . V_121 , 1 * V_23 ) ;
if ( V_120 == 0 )
F_13 ( V_51 ) ;
}
return 0 ;
}
static void F_50 ( struct V_50 * V_51 ,
struct V_122 * V_123 )
{
struct V_124 V_125 ;
int V_10 ;
if ( V_123 -> V_126 ) {
F_15 ( & V_51 -> V_127 ) ;
return;
}
if ( V_51 -> V_128 == 0 )
goto V_129;
V_51 -> V_128 = 0 ;
memset ( & V_125 , 0 , sizeof( struct V_124 ) ) ;
V_125 . V_52 . type = V_130 ;
V_125 . V_52 . V_2 = sizeof( struct V_124 ) ;
V_125 . V_52 . V_66 = F_27 ( & V_66 ) ;
V_125 . V_131 . V_131 = V_132 ;
V_125 . V_133 = 1 ;
V_10 = F_28 ( V_51 -> V_67 -> V_68 , & V_125 ,
sizeof( struct V_124 ) ,
( unsigned long ) NULL ,
V_69 , 0 ) ;
if ( V_10 )
goto V_129;
return;
V_129:
V_51 -> V_64 = V_134 ;
F_15 ( & V_51 -> V_127 ) ;
}
static void F_51 ( struct V_50 * V_51 ,
struct V_135 * F_51 )
{
if ( ! F_51 -> V_126 ) {
F_11 ( L_7 ) ;
V_51 -> V_64 = V_134 ;
}
F_15 ( & V_51 -> V_127 ) ;
}
static void F_52 ( void * V_136 )
{
struct V_137 * V_67 = V_136 ;
T_3 V_138 ;
T_4 V_139 ;
struct V_140 * V_141 ;
struct V_142 * V_143 ;
struct V_50 * V_51 = F_53 ( V_67 ) ;
struct V_144 * V_145 ;
struct V_146 * V_147 ;
union V_93 * V_148 ;
union V_93 * V_41 ;
memset ( V_149 , 0 , sizeof( V_149 ) ) ;
F_54 ( V_67 -> V_68 , V_149 ,
V_101 , & V_138 , & V_139 ) ;
if ( V_138 > 0 ) {
V_141 = (struct V_140 * ) V_149 ;
V_143 = & V_141 -> V_52 ;
switch ( V_143 -> type ) {
case V_150 :
F_50 ( V_51 ,
(struct V_122 * ) V_141 ) ;
break;
case V_151 :
F_51 ( V_51 ,
(struct V_135 * ) V_141 ) ;
break;
case V_152 :
if ( V_51 -> V_64 == V_153 )
F_55 ( L_8 ) ;
V_145 = (struct V_144 * ) V_149 ;
V_51 -> V_64 = V_153 ;
V_17 . V_107 . V_95 = V_145 -> V_95 ;
F_56 ( & V_17 . V_107 . V_154 ) ;
break;
case V_155 :
V_51 -> V_64 = V_156 ;
F_46 ( V_51 ,
(struct V_115 * ) V_149 ) ;
break;
case V_157 :
if ( V_51 -> V_64 == V_158 )
F_55 ( L_9 ) ;
V_51 -> V_64 = V_158 ;
V_147 = (struct V_146 * ) V_149 ;
if ( V_147 -> V_52 . V_2 == sizeof( struct V_146 ) ) {
V_148 = & V_147 -> V_159 ;
V_51 -> V_54 . V_55 = * V_148 ;
V_51 -> V_54 . V_59 . V_160 = 0 ;
} else {
V_51 -> V_42 = true ;
V_148 = & V_147 -> V_159 ;
V_41 = & V_148 [ 1 ] ;
V_51 -> V_54 . V_55 = * V_148 ;
V_51 -> V_54 . V_59 = * V_41 ;
}
F_56 ( & V_17 . V_54 . V_154 ) ;
break;
case V_161 :
F_29 ( V_51 , (struct V_70 * ) V_141 ) ;
break;
default:
F_57 ( L_10 , V_143 -> type ) ;
}
}
}
static int F_58 ( struct V_137 * V_67 ,
const struct V_162 * V_163 )
{
int V_10 , V_120 ;
struct V_124 V_125 ;
struct V_164 V_165 ;
V_22 = V_166 ;
V_111 = F_59 ( V_101 , V_44 ) ;
if ( ! V_111 )
return - V_167 ;
V_10 = F_60 ( V_67 -> V_68 , V_168 , V_168 , NULL , 0 ,
F_52 , V_67 ) ;
if ( V_10 )
goto V_169;
V_17 . V_67 = V_67 ;
V_17 . V_64 = V_170 ;
V_17 . V_128 = V_132 ;
F_7 ( & V_17 . V_127 ) ;
F_7 ( & V_17 . V_121 ) ;
F_23 ( & V_17 . V_33 ) ;
F_61 ( & V_17 . V_107 . V_154 , F_43 ) ;
F_61 ( & V_17 . V_54 . V_154 , F_25 ) ;
V_17 . V_42 = false ;
V_17 . V_171 =
F_62 ( F_47 , & V_17 , L_11 ) ;
if ( F_63 ( V_17 . V_171 ) ) {
V_10 = F_64 ( V_17 . V_171 ) ;
goto V_172;
}
#ifdef F_26
F_65 ( & F_14 ) ;
#endif
F_66 ( V_67 , & V_17 ) ;
memset ( & V_125 , 0 , sizeof( struct V_124 ) ) ;
V_125 . V_52 . type = V_130 ;
V_125 . V_52 . V_2 = sizeof( struct V_124 ) ;
V_125 . V_52 . V_66 = F_27 ( & V_66 ) ;
V_125 . V_131 . V_131 = V_173 ;
V_125 . V_133 = 0 ;
V_10 = F_28 ( V_67 -> V_68 , & V_125 ,
sizeof( struct V_124 ) ,
( unsigned long ) NULL ,
V_69 , 0 ) ;
if ( V_10 )
goto V_174;
V_120 = F_12 ( & V_17 . V_127 , 5 * V_23 ) ;
if ( V_120 == 0 ) {
V_10 = - V_175 ;
goto V_174;
}
if ( V_17 . V_64 == V_134 ) {
V_10 = - V_175 ;
goto V_174;
}
memset ( & V_165 , 0 , sizeof( struct V_164 ) ) ;
V_165 . V_52 . type = V_176 ;
V_165 . V_52 . V_2 = sizeof( struct V_164 ) ;
V_165 . V_52 . V_66 = F_27 ( & V_66 ) ;
V_165 . V_177 . V_178 . V_179 = 1 ;
V_165 . V_177 . V_178 . V_166 = 1 ;
V_165 . V_177 . V_178 . V_180 = 7 ;
V_165 . V_181 = 0 ;
V_165 . V_182 = - 1 ;
V_10 = F_28 ( V_67 -> V_68 , & V_165 ,
sizeof( struct V_164 ) ,
( unsigned long ) NULL ,
V_69 , 0 ) ;
if ( V_10 )
goto V_174;
V_120 = F_12 ( & V_17 . V_127 , 5 * V_23 ) ;
if ( V_120 == 0 ) {
V_10 = - V_175 ;
goto V_174;
}
if ( V_17 . V_64 == V_134 ) {
V_10 = - V_175 ;
goto V_174;
}
V_17 . V_64 = V_65 ;
return 0 ;
V_174:
#ifdef F_26
F_67 ( & F_14 ) ;
#endif
F_68 ( V_17 . V_171 ) ;
V_172:
F_69 ( V_67 -> V_68 ) ;
V_169:
F_70 ( V_111 ) ;
return V_10 ;
}
static int F_71 ( struct V_137 * V_67 )
{
struct V_50 * V_51 = F_53 ( V_67 ) ;
struct V_24 * V_25 , * V_183 ;
struct V_8 * V_9 ;
if ( V_51 -> V_92 != 0 )
F_55 ( L_12 , V_51 -> V_92 ) ;
F_72 ( & V_51 -> V_107 . V_154 ) ;
F_72 ( & V_51 -> V_54 . V_154 ) ;
F_69 ( V_67 -> V_68 ) ;
F_68 ( V_51 -> V_171 ) ;
F_70 ( V_111 ) ;
#ifdef F_26
F_67 ( & F_14 ) ;
#endif
F_73 (cur, tmp, &dm->ha_region_list) {
V_9 = F_17 ( V_25 , struct V_8 , V_28 ) ;
F_74 ( & V_9 -> V_28 ) ;
F_70 ( V_9 ) ;
}
return 0 ;
}
static int T_5 F_75 ( void )
{
return F_76 ( & V_184 ) ;
}
