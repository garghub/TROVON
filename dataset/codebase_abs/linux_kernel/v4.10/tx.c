static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
int V_6 ;
bool V_7 = ( V_4 -> V_8 == V_9 ) ;
if ( V_7 )
V_6 = F_2 ( V_2 , V_5 ,
V_4 -> V_10 . V_11 ) ;
else
V_6 = F_2 ( V_2 , V_5 , V_4 -> V_12 . V_13 ) ;
if ( V_6 < 0 )
return V_6 ;
F_3 ( V_14 , L_1 , ( int ) V_5 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
int V_5 ;
V_5 = F_5 ( V_2 -> V_17 , V_2 -> V_18 ) ;
if ( V_5 >= V_2 -> V_18 )
return - V_19 ;
F_6 ( V_5 , V_2 -> V_17 ) ;
V_2 -> V_20 [ V_5 ] = V_16 ;
V_2 -> V_21 ++ ;
return V_5 ;
}
void F_7 ( struct V_1 * V_2 , int V_5 )
{
if ( F_8 ( V_5 , V_2 -> V_17 ) ) {
if ( F_9 ( V_2 -> V_21 == V_2 -> V_18 ) )
F_10 ( V_22 , & V_2 -> V_23 ) ;
V_2 -> V_20 [ V_5 ] = NULL ;
V_2 -> V_21 -- ;
}
}
static void F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_15 * V_16 )
{
struct V_24 * V_25 ;
V_25 = (struct V_24 * ) ( V_16 -> V_26 +
sizeof( struct V_27 ) ) ;
if ( ! F_12 ( V_25 -> V_28 ) )
return;
F_13 ( V_2 , V_4 , V_25 -> V_29 ) ;
F_14 ( V_2 , V_4 , NULL , true ) ;
V_4 -> V_30 = V_31 ;
F_15 ( & V_4 -> V_32 ) ;
F_16 ( V_2 -> V_33 ,
& V_4 -> V_32 ,
F_17 ( V_34 ) ) ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_13 )
{
bool V_35 ;
T_1 V_36 ;
if ( F_19 ( ! F_20 ( V_13 , V_4 -> V_37 ) ) )
return;
V_35 = F_20 ( V_13 , & V_2 -> V_38 ) ;
V_36 = V_2 -> V_39 [ V_13 ] . V_40 ;
if ( V_2 -> V_41 > ( V_2 -> V_42 * 2 + 1 ) && V_35 &&
V_36 >= V_43 )
F_21 ( V_2 , V_4 , V_13 , true ) ;
}
bool F_22 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
return V_2 -> V_44 == V_16 ;
}
static T_1 F_23 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_15 * V_16 , struct V_45 * V_12 )
{
if ( V_12 ) {
struct V_46 * V_47 ;
V_47 = (struct V_46 * ) V_12 -> V_48 ;
return V_47 -> V_13 ;
} else {
struct V_24 * V_25 ;
if ( ! F_20 ( V_49 , & V_4 -> V_23 ) )
return V_2 -> V_50 ;
V_25 = (struct V_24 * ) V_16 -> V_26 ;
if ( F_24 ( F_25 ( V_25 ) ) )
return V_4 -> V_10 . V_11 ;
else
return V_4 -> V_10 . V_51 ;
}
}
T_1 F_26 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_15 * V_16 , struct V_45 * V_12 )
{
struct V_52 * V_53 ;
if ( V_4 -> V_8 == V_9 )
return F_23 ( V_2 , V_4 , V_16 , V_12 ) ;
V_53 = F_27 ( V_16 ) ;
if ( V_53 -> V_23 & V_54 ) {
F_3 ( V_55 , L_2 ) ;
return V_4 -> V_56 ;
}
return V_4 -> V_12 . V_13 ;
}
unsigned int F_28 ( struct V_1 * V_2 ,
unsigned int V_57 )
{
if ( ( V_2 -> V_58 & V_59 ) ||
! ( V_2 -> V_58 & V_60 ) )
return F_29 ( V_57 , V_61 ) ;
else
return F_29 ( V_57 , V_62 ) ;
}
static int F_30 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_15 * V_16 , T_2 V_63 , T_2 V_64 ,
T_1 V_13 , bool V_65 )
{
struct V_27 * V_66 ;
T_2 V_67 = V_16 -> V_68 + sizeof( struct V_27 ) + V_63 ;
T_2 V_69 ;
int V_5 , V_6 = - V_19 , V_70 ;
T_2 V_71 ;
if ( V_64 + V_67 > V_2 -> V_72 )
return - V_73 ;
V_71 = F_31 ( V_2 , V_65 ) ;
V_5 = F_4 ( V_2 , V_16 ) ;
if ( V_5 < 0 )
return V_5 ;
V_69 = F_32 ( V_2 , V_67 , V_71 ) ;
if ( V_69 <= V_2 -> V_74 ) {
V_66 = (struct V_27 * ) F_33 (
V_16 , V_67 - V_16 -> V_68 ) ;
F_34 ( V_2 , V_66 , V_69 ,
V_71 ) ;
V_66 -> V_5 = V_5 ;
V_2 -> V_74 -= V_69 ;
V_2 -> V_75 += V_69 ;
if ( V_2 -> V_75 == V_69 ||
F_35 ( V_76 , & V_2 -> V_23 ) )
F_36 ( V_2 ) ;
V_70 = F_37 ( F_38 ( V_16 ) ) ;
V_2 -> V_77 [ V_70 ] ++ ;
if ( F_20 ( V_13 , V_2 -> V_37 ) )
V_2 -> V_39 [ V_13 ] . V_40 ++ ;
V_6 = 0 ;
F_3 ( V_55 ,
L_3 ,
V_67 , V_69 , V_5 ) ;
} else {
F_7 ( V_2 , V_5 ) ;
}
return V_6 ;
}
static void F_39 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_15 * V_16 , T_2 V_63 ,
struct V_52 * V_53 , T_1 V_13 )
{
struct V_78 V_79 ;
struct V_27 * V_66 ;
int V_70 , V_80 ;
T_3 V_81 ;
T_4 V_82 = 0 ;
T_5 V_28 ;
struct V_24 * V_25 ;
T_1 * V_83 ;
bool V_84 ;
V_66 = (struct V_27 * ) V_16 -> V_26 ;
V_83 = ( T_1 * ) ( V_66 + 1 ) ;
V_25 = (struct V_24 * ) ( V_83 + V_63 ) ;
V_28 = V_25 -> V_28 ;
if ( V_63 ) {
int V_85 = F_40 ( V_28 ) ;
memmove ( V_83 , V_25 , V_85 ) ;
F_41 ( V_16 , F_42 ( V_16 ) + V_63 ) ;
}
F_43 ( & V_79 ) ;
V_81 = ( F_44 ( & V_79 ) >> 10 ) ;
V_66 -> V_86 = F_45 ( V_81 - V_2 -> V_87 ) ;
V_84 = F_22 ( V_2 , V_16 ) ;
if ( V_84 || ! V_4 || V_4 -> V_8 != V_9 )
V_66 -> V_88 = F_46 ( V_89 ) ;
else
V_66 -> V_88 = F_46 ( V_90 ) ;
V_70 = F_37 ( F_38 ( V_16 ) ) ;
V_66 -> V_91 = V_16 -> V_92 ;
if ( V_84 ) {
V_82 = ( V_93 <<
V_94 ) &
V_95 ;
V_82 |= V_96 ;
} else if ( V_4 ) {
T_1 V_97 = V_2 -> V_98 [ V_13 ] ;
if ( ( V_2 -> V_58 & V_99 ) &&
( V_4 -> V_8 == V_9 ) )
V_97 = 0 ;
V_82 = V_97 << V_94 ;
}
V_66 -> V_13 = V_13 ;
if ( V_84 || ! V_4 )
V_80 = 0 ;
else if ( V_4 -> V_8 != V_9 ) {
if ( V_16 -> V_100 == F_47 ( V_101 ) )
V_80 = V_4 -> V_12 . V_102 ;
else if ( V_53 -> V_23 & V_103 )
V_80 = V_4 -> V_12 . V_104 ;
else if ( F_48 ( V_28 ) )
V_80 = V_4 -> V_12 . V_105 ;
else
V_80 = V_4 -> V_12 . V_102 ;
} else {
if ( V_13 == V_4 -> V_10 . V_51 )
V_80 = V_4 -> V_10 . V_106 ;
else if ( V_13 == V_4 -> V_10 . V_11 ||
V_16 -> V_100 == F_47 ( V_101 ) ||
! F_48 ( V_28 ) )
V_80 = V_4 -> V_10 . V_107 ;
else
V_80 = V_4 -> V_10 . V_108 [ V_70 ] ;
}
V_82 |= V_80 << V_109 ;
if ( F_12 ( V_28 ) &&
F_49 ( V_28 ) )
V_82 |= V_110 ;
if ( V_53 -> V_53 . V_23 & V_111 )
V_82 |= V_112 ;
V_66 -> V_82 = F_46 ( V_82 ) ;
F_50 ( V_2 , V_66 , V_16 ) ;
F_51 ( V_2 , V_66 , V_16 ) ;
}
static int F_52 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_15 * V_16 , T_2 V_64 , T_1 V_13 )
{
struct V_52 * V_113 ;
T_2 V_63 = 0 ;
int V_6 = 0 ;
T_2 V_67 ;
bool V_84 ;
bool V_65 = false ;
if ( ! V_16 ) {
F_53 ( L_4 ) ;
return - V_114 ;
}
if ( V_13 == V_115 ) {
F_53 ( L_5 , V_16 ) ;
return - V_114 ;
}
V_113 = F_27 ( V_16 ) ;
V_84 = F_22 ( V_2 , V_16 ) ;
if ( ( V_2 -> V_58 & V_116 ) &&
V_113 -> V_53 . V_117 &&
V_113 -> V_53 . V_117 -> V_118 == V_119 )
V_63 = V_120 ;
if ( V_113 -> V_53 . V_117 ) {
bool V_121 ;
T_1 V_122 = V_113 -> V_53 . V_117 -> V_123 ;
T_2 V_118 = V_113 -> V_53 . V_117 -> V_118 ;
V_121 = ( V_118 == V_124 ) ||
( V_118 == V_125 ) ;
if ( F_19 ( V_121 && V_4 && V_4 -> V_126 != V_122 ) ) {
V_6 = F_1 ( V_2 , V_4 , V_122 ) ;
if ( V_6 < 0 )
return V_6 ;
V_4 -> V_126 = V_122 ;
}
V_65 = ( V_118 == V_127 ) ;
}
V_6 = F_30 ( V_2 , V_4 , V_16 , V_63 , V_64 , V_13 ,
V_65 ) ;
if ( V_6 < 0 )
return V_6 ;
F_39 ( V_2 , V_4 , V_16 , V_63 , V_113 , V_13 ) ;
if ( ! V_84 && V_4 && V_4 -> V_8 == V_9 ) {
F_11 ( V_2 , V_4 , V_16 ) ;
F_18 ( V_2 , V_4 , V_13 ) ;
}
V_67 = F_28 ( V_2 , V_16 -> V_68 ) ;
memcpy ( V_2 -> V_128 + V_64 , V_16 -> V_26 , V_16 -> V_68 ) ;
memset ( V_2 -> V_128 + V_64 + V_16 -> V_68 , 0 , V_67 - V_16 -> V_68 ) ;
if ( V_84 )
F_54 ( V_16 , sizeof( struct V_27 ) ) ;
return V_67 ;
}
T_2 F_55 ( struct V_1 * V_2 , T_2 V_129 ,
enum V_130 V_131 )
{
struct V_132 * V_133 ;
T_2 V_134 = 0 ;
int V_135 ;
V_133 = V_2 -> V_33 -> V_136 -> V_137 [ V_131 ] ;
for ( V_135 = 0 ; V_135 < V_133 -> V_138 ; V_135 ++ ) {
if ( V_129 & 0x1 )
V_134 |= V_133 -> V_139 [ V_135 ] . V_140 ;
V_129 >>= 1 ;
}
V_129 >>= V_141 - V_133 -> V_138 ;
for ( V_135 = 0 ; V_135 < 16 ; V_135 ++ ) {
if ( V_129 & 0x1 )
V_134 |= ( V_142 << V_135 ) ;
V_129 >>= 1 ;
}
return V_134 ;
}
void F_56 ( struct V_1 * V_2 )
{
int V_143 ;
struct V_3 * V_4 ;
F_57 (wl, wlvif) {
for ( V_143 = 0 ; V_143 < V_144 ; V_143 ++ ) {
if ( F_58 ( V_2 , V_4 , V_143 ,
V_145 ) &&
V_4 -> V_146 [ V_143 ] <=
V_147 )
F_59 ( V_2 , V_4 , V_143 ,
V_145 ) ;
}
}
}
static int F_60 ( struct V_1 * V_2 )
{
int V_143 , V_148 = - 1 , V_70 ;
T_2 V_149 = 0xffffffff ;
for ( V_143 = 0 ; V_143 < V_144 ; V_143 ++ ) {
V_70 = F_37 ( V_143 ) ;
if ( V_2 -> V_146 [ V_70 ] &&
V_2 -> V_77 [ V_70 ] < V_149 ) {
V_148 = V_70 ;
V_149 = V_2 -> V_77 [ V_148 ] ;
}
}
return V_148 ;
}
static struct V_15 * F_61 ( struct V_1 * V_2 ,
struct V_150 * V_151 , T_1 V_148 )
{
struct V_15 * V_16 ;
unsigned long V_23 ;
V_16 = F_62 ( & V_151 -> V_152 [ V_148 ] ) ;
if ( V_16 ) {
F_63 ( & V_2 -> V_153 , V_23 ) ;
F_64 ( V_2 -> V_146 [ V_148 ] <= 0 ) ;
V_2 -> V_146 [ V_148 ] -- ;
if ( V_151 -> V_4 ) {
F_64 ( V_151 -> V_4 -> V_146 [ V_148 ] <= 0 ) ;
V_151 -> V_4 -> V_146 [ V_148 ] -- ;
}
F_65 ( & V_2 -> V_153 , V_23 ) ;
}
return V_16 ;
}
static struct V_15 * F_66 ( struct V_1 * V_2 ,
T_1 V_13 , T_1 V_70 ,
T_1 * V_154 )
{
struct V_150 * V_151 = & V_2 -> V_39 [ V_13 ] ;
if ( ! F_67 ( V_2 , V_13 , V_151 ) ) {
if ( * V_154 == V_115 &&
! F_68 ( & V_151 -> V_152 [ V_70 ] ) &&
F_69 ( V_2 , V_13 , V_151 ) )
* V_154 = V_13 ;
return NULL ;
}
return F_61 ( V_2 , V_151 , V_70 ) ;
}
static struct V_15 * F_70 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_70 , T_1 * V_13 ,
T_1 * V_154 )
{
struct V_15 * V_16 = NULL ;
int V_143 , V_155 , V_156 ;
V_156 = ( V_4 -> V_157 + 1 ) % V_2 -> V_158 ;
for ( V_143 = 0 ; V_143 < V_2 -> V_158 ; V_143 ++ ) {
V_155 = ( V_156 + V_143 ) % V_2 -> V_158 ;
if ( ! F_20 ( V_155 , V_4 -> V_37 ) )
continue;
V_16 = F_66 ( V_2 , V_155 , V_70 ,
V_154 ) ;
if ( ! V_16 )
continue;
V_4 -> V_157 = V_155 ;
break;
}
if ( ! V_16 )
V_4 -> V_157 = 0 ;
* V_13 = V_4 -> V_157 ;
return V_16 ;
}
static struct V_15 * F_71 ( struct V_1 * V_2 , T_1 * V_13 )
{
unsigned long V_23 ;
struct V_3 * V_4 = V_2 -> V_159 ;
struct V_15 * V_16 = NULL ;
int V_70 ;
T_1 V_154 = V_115 ;
V_70 = F_60 ( V_2 ) ;
if ( V_70 < 0 )
goto V_160;
if ( V_4 ) {
F_72 (wl, wlvif) {
if ( ! V_4 -> V_146 [ V_70 ] )
continue;
V_16 = F_70 ( V_2 , V_4 , V_70 , V_13 ,
& V_154 ) ;
if ( ! V_16 )
continue;
V_2 -> V_159 = V_4 ;
break;
}
}
if ( ! V_16 ) {
V_16 = F_66 ( V_2 , V_2 -> V_50 ,
V_70 , & V_154 ) ;
if ( V_16 ) {
* V_13 = V_2 -> V_50 ;
V_2 -> V_159 = NULL ;
}
}
if ( ! V_16 ) {
F_57 (wl, wlvif) {
if ( ! V_4 -> V_146 [ V_70 ] )
goto V_161;
V_16 = F_70 ( V_2 , V_4 , V_70 , V_13 ,
& V_154 ) ;
if ( V_16 ) {
V_2 -> V_159 = V_4 ;
break;
}
V_161:
if ( V_4 == V_2 -> V_159 )
break;
}
}
if ( ! V_16 && V_154 != V_115 ) {
struct V_150 * V_151 = & V_2 -> V_39 [ V_154 ] ;
V_16 = F_61 ( V_2 , V_151 , V_70 ) ;
F_19 ( ! V_16 ) ;
* V_13 = V_154 ;
V_2 -> V_159 = V_151 -> V_4 ;
if ( V_151 -> V_4 )
V_151 -> V_4 -> V_157 = V_154 ;
}
V_160:
if ( ! V_16 &&
F_35 ( V_162 , & V_2 -> V_23 ) ) {
int V_148 ;
V_16 = V_2 -> V_44 ;
* V_13 = V_2 -> V_50 ;
V_148 = F_37 ( F_38 ( V_16 ) ) ;
F_63 ( & V_2 -> V_153 , V_23 ) ;
F_64 ( V_2 -> V_146 [ V_148 ] <= 0 ) ;
V_2 -> V_146 [ V_148 ] -- ;
F_65 ( & V_2 -> V_153 , V_23 ) ;
}
return V_16 ;
}
static void F_73 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_15 * V_16 , T_1 V_13 )
{
unsigned long V_23 ;
int V_148 = F_37 ( F_38 ( V_16 ) ) ;
if ( F_22 ( V_2 , V_16 ) ) {
F_74 ( V_162 , & V_2 -> V_23 ) ;
} else {
F_75 ( & V_2 -> V_39 [ V_13 ] . V_152 [ V_148 ] , V_16 ) ;
V_4 -> V_157 = ( V_13 + V_2 -> V_158 - 1 ) %
V_2 -> V_158 ;
}
F_63 ( & V_2 -> V_153 , V_23 ) ;
V_2 -> V_146 [ V_148 ] ++ ;
if ( V_4 )
V_4 -> V_146 [ V_148 ] ++ ;
F_65 ( & V_2 -> V_153 , V_23 ) ;
}
static bool F_76 ( struct V_15 * V_16 )
{
struct V_24 * V_25 = (struct V_24 * ) ( V_16 -> V_26 ) ;
return F_77 ( V_25 -> V_28 ) ;
}
void F_78 ( struct V_1 * V_2 , unsigned long * V_163 )
{
struct V_3 * V_4 ;
T_2 V_164 ;
T_1 V_13 ;
if ( ! V_2 -> V_165 . V_166 . V_167 )
return;
if ( ! V_2 -> V_165 . V_166 . V_168 &&
! F_20 ( V_169 , & V_2 -> V_23 ) )
return;
V_164 = V_2 -> V_165 . V_166 . V_170 ;
F_79 (wl, wlvif) {
bool V_171 = false ;
F_80 (hlid, active_hlids, wl->num_links) {
if ( F_20 ( V_13 , V_4 -> V_37 ) ) {
V_171 = true ;
break;
}
}
if ( ! V_171 )
continue;
if ( ! F_20 ( V_172 , & V_4 -> V_23 ) )
F_81 ( V_2 -> V_33 ,
& V_4 -> V_173 ) ;
F_82 ( & V_4 -> V_174 ,
V_31 + F_17 ( V_164 ) ) ;
}
}
int F_83 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_15 * V_16 ;
struct V_27 * V_66 ;
T_2 V_64 = 0 , V_175 = 0 ;
bool V_176 = false ;
unsigned long V_163 [ F_84 ( V_177 ) ] = { 0 } ;
int V_6 = 0 ;
int V_178 = 0 ;
T_1 V_13 ;
if ( F_9 ( V_2 -> V_179 != V_180 ) )
return 0 ;
while ( ( V_16 = F_71 ( V_2 , & V_13 ) ) ) {
struct V_52 * V_113 = F_27 ( V_16 ) ;
bool V_181 = false ;
V_4 = NULL ;
if ( ! F_22 ( V_2 , V_16 ) )
V_4 = F_85 ( V_113 -> V_53 . V_182 ) ;
else
V_13 = V_2 -> V_50 ;
V_181 = V_4 && F_76 ( V_16 ) ;
V_6 = F_52 ( V_2 , V_4 , V_16 , V_64 ,
V_13 ) ;
if ( V_6 == - V_73 ) {
F_73 ( V_2 , V_4 , V_16 , V_13 ) ;
V_64 = F_86 ( V_2 , V_64 ,
V_175 ) ;
V_178 = F_87 ( V_2 , V_183 ,
V_2 -> V_128 , V_64 , true ) ;
if ( V_178 < 0 )
goto V_160;
V_176 = true ;
V_64 = 0 ;
continue;
} else if ( V_6 == - V_19 ) {
F_73 ( V_2 , V_4 , V_16 , V_13 ) ;
F_74 ( V_22 , & V_2 -> V_23 ) ;
goto V_184;
} else if ( V_6 < 0 ) {
if ( F_22 ( V_2 , V_16 ) )
F_73 ( V_2 , V_4 , V_16 , V_13 ) ;
else
F_88 ( V_2 -> V_33 , V_16 ) ;
goto V_184;
}
V_175 = V_6 ;
V_64 += V_175 ;
V_2 -> V_185 ++ ;
if ( V_181 ) {
V_66 = (struct V_27 * ) V_16 -> V_26 ;
F_6 ( V_66 -> V_13 , V_163 ) ;
}
}
V_184:
if ( V_64 ) {
V_64 = F_86 ( V_2 , V_64 , V_175 ) ;
V_178 = F_87 ( V_2 , V_183 , V_2 -> V_128 ,
V_64 , true ) ;
if ( V_178 < 0 )
goto V_160;
V_176 = true ;
}
if ( V_176 ) {
if ( V_2 -> V_58 & V_186 ) {
V_178 = F_89 ( V_2 , V_187 ,
V_2 -> V_185 ) ;
if ( V_178 < 0 )
goto V_160;
}
F_56 ( V_2 ) ;
}
F_78 ( V_2 , V_163 ) ;
V_160:
return V_178 ;
}
void F_90 ( struct V_188 * V_189 )
{
struct V_1 * V_2 = F_91 ( V_189 , struct V_1 , V_190 ) ;
int V_6 ;
F_92 ( & V_2 -> V_191 ) ;
V_6 = F_93 ( V_2 ) ;
if ( V_6 < 0 )
goto V_160;
V_6 = F_83 ( V_2 ) ;
if ( V_6 < 0 ) {
F_94 ( V_2 ) ;
goto V_160;
}
F_95 ( V_2 ) ;
V_160:
F_96 ( & V_2 -> V_191 ) ;
}
static T_1 F_97 ( T_1 V_192 )
{
T_1 V_23 = 0 ;
if ( V_192 <= 8 )
V_23 |= V_193 ;
if ( V_192 == 0 )
V_23 |= V_194 ;
return V_23 ;
}
static void F_98 ( struct V_1 * V_2 ,
struct V_195 * V_196 )
{
struct V_52 * V_113 ;
struct V_197 * V_182 ;
struct V_3 * V_4 ;
struct V_15 * V_16 ;
int V_5 = V_196 -> V_5 ;
int V_198 = - 1 ;
T_1 V_199 = 0 ;
T_1 V_200 = 0 ;
if ( F_9 ( V_5 >= V_2 -> V_18 || V_2 -> V_20 [ V_5 ] == NULL ) ) {
F_99 ( L_6 , V_5 ) ;
return;
}
V_16 = V_2 -> V_20 [ V_5 ] ;
V_113 = F_27 ( V_16 ) ;
if ( F_22 ( V_2 , V_16 ) ) {
F_7 ( V_2 , V_5 ) ;
return;
}
V_182 = V_113 -> V_53 . V_182 ;
V_4 = F_85 ( V_182 ) ;
if ( V_196 -> V_201 == V_202 ) {
if ( ! ( V_113 -> V_23 & V_203 ) )
V_113 -> V_23 |= V_204 ;
V_198 = F_100 ( V_2 , V_196 -> V_192 ,
V_4 -> V_133 ) ;
V_199 = F_97 ( V_196 -> V_192 ) ;
V_200 = V_196 -> V_205 ;
} else if ( V_196 -> V_201 == V_206 ) {
V_2 -> V_207 . V_208 ++ ;
V_200 = V_196 -> V_205 ;
}
V_113 -> V_201 . V_209 [ 0 ] . V_122 = V_198 ;
V_113 -> V_201 . V_209 [ 0 ] . V_210 = V_200 ;
V_113 -> V_201 . V_209 [ 0 ] . V_23 = V_199 ;
V_113 -> V_201 . V_211 = - 1 ;
V_2 -> V_207 . V_212 += V_196 -> V_205 ;
F_54 ( V_16 , sizeof( struct V_27 ) ) ;
if ( ( V_2 -> V_58 & V_116 ) &&
V_113 -> V_53 . V_117 &&
V_113 -> V_53 . V_117 -> V_118 == V_119 ) {
int V_85 = F_101 ( V_16 ) ;
memmove ( V_16 -> V_26 + V_120 , V_16 -> V_26 ,
V_85 ) ;
F_54 ( V_16 , V_120 ) ;
}
F_3 ( V_55 , L_7
L_8 ,
V_196 -> V_5 , V_16 , V_196 -> V_205 ,
V_196 -> V_192 , V_196 -> V_201 ) ;
F_102 ( & V_2 -> V_213 , V_16 ) ;
F_103 ( V_2 -> V_214 , & V_2 -> V_215 ) ;
F_7 ( V_2 , V_196 -> V_5 ) ;
}
int F_104 ( struct V_1 * V_2 )
{
struct V_216 * V_217 = V_2 -> V_218 ;
T_2 V_210 , V_219 ;
T_2 V_143 ;
int V_6 ;
V_6 = F_105 ( V_2 , F_106 ( V_217 -> V_220 ) ,
V_2 -> V_221 , sizeof( * V_2 -> V_221 ) , false ) ;
if ( V_6 < 0 )
goto V_160;
V_219 = F_106 ( V_2 -> V_221 -> V_222 ) ;
V_6 = F_89 ( V_2 , F_106 ( V_217 -> V_220 ) +
F_107 ( struct V_223 ,
V_224 ) , V_219 ) ;
if ( V_6 < 0 )
goto V_160;
V_210 = V_219 - V_2 -> V_225 ;
F_3 ( V_55 , L_9 , V_210 ) ;
if ( F_9 ( V_210 > V_226 ) )
F_99 ( L_10 , V_210 ) ;
for ( V_143 = 0 ; V_143 < V_210 ; V_143 ++ ) {
struct V_195 * V_196 ;
T_1 V_227 = V_2 -> V_225 & V_228 ;
V_196 = & ( V_2 -> V_221 -> V_229 [ V_227 ] ) ;
F_98 ( V_2 , V_196 ) ;
V_2 -> V_225 ++ ;
}
V_160:
return V_6 ;
}
void F_108 ( struct V_1 * V_2 , T_1 V_13 )
{
struct V_15 * V_16 ;
int V_143 ;
unsigned long V_23 ;
struct V_52 * V_113 ;
int V_230 [ V_144 ] ;
struct V_150 * V_151 = & V_2 -> V_39 [ V_13 ] ;
for ( V_143 = 0 ; V_143 < V_144 ; V_143 ++ ) {
V_230 [ V_143 ] = 0 ;
while ( ( V_16 = F_62 ( & V_151 -> V_152 [ V_143 ] ) ) ) {
F_3 ( V_55 , L_11 , V_16 ) ;
if ( ! F_22 ( V_2 , V_16 ) ) {
V_113 = F_27 ( V_16 ) ;
V_113 -> V_201 . V_209 [ 0 ] . V_122 = - 1 ;
V_113 -> V_201 . V_209 [ 0 ] . V_210 = 0 ;
F_109 ( V_2 -> V_33 , V_16 ) ;
}
V_230 [ V_143 ] ++ ;
}
}
F_63 ( & V_2 -> V_153 , V_23 ) ;
for ( V_143 = 0 ; V_143 < V_144 ; V_143 ++ ) {
V_2 -> V_146 [ V_143 ] -= V_230 [ V_143 ] ;
if ( V_151 -> V_4 )
V_151 -> V_4 -> V_146 [ V_143 ] -= V_230 [ V_143 ] ;
}
F_65 ( & V_2 -> V_153 , V_23 ) ;
F_56 ( V_2 ) ;
}
void F_110 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_143 ;
F_80 (i, wlvif->links_map, wl->num_links) {
if ( V_4 -> V_8 == V_9 &&
V_143 != V_4 -> V_10 . V_11 && V_143 != V_4 -> V_10 . V_51 ) {
F_111 ( V_2 , V_4 , V_143 ) ;
} else {
T_1 V_13 = V_143 ;
F_112 ( V_2 , V_4 , & V_13 ) ;
}
}
V_4 -> V_157 = 0 ;
for ( V_143 = 0 ; V_143 < V_144 ; V_143 ++ )
V_4 -> V_146 [ V_143 ] = 0 ;
}
void F_113 ( struct V_1 * V_2 )
{
int V_143 ;
struct V_15 * V_16 ;
struct V_52 * V_113 ;
if ( F_114 ( V_2 ) != 0 ) {
for ( V_143 = 0 ; V_143 < V_2 -> V_158 ; V_143 ++ )
F_108 ( V_2 , V_143 ) ;
for ( V_143 = 0 ; V_143 < V_144 ; V_143 ++ )
V_2 -> V_146 [ V_143 ] = 0 ;
}
F_56 ( V_2 ) ;
for ( V_143 = 0 ; V_143 < V_2 -> V_18 ; V_143 ++ ) {
if ( V_2 -> V_20 [ V_143 ] == NULL )
continue;
V_16 = V_2 -> V_20 [ V_143 ] ;
F_7 ( V_2 , V_143 ) ;
F_3 ( V_55 , L_12 , V_16 ) ;
if ( ! F_22 ( V_2 , V_16 ) ) {
V_113 = F_27 ( V_16 ) ;
F_54 ( V_16 , sizeof( struct V_27 ) ) ;
if ( ( V_2 -> V_58 & V_116 ) &&
V_113 -> V_53 . V_117 &&
V_113 -> V_53 . V_117 -> V_118 ==
V_119 ) {
int V_85 = F_101 ( V_16 ) ;
memmove ( V_16 -> V_26 + V_120 ,
V_16 -> V_26 , V_85 ) ;
F_54 ( V_16 , V_120 ) ;
}
V_113 -> V_201 . V_209 [ 0 ] . V_122 = - 1 ;
V_113 -> V_201 . V_209 [ 0 ] . V_210 = 0 ;
F_109 ( V_2 -> V_33 , V_16 ) ;
}
}
}
void F_115 ( struct V_1 * V_2 )
{
unsigned long V_164 , V_86 ;
int V_143 ;
V_86 = V_31 ;
V_164 = V_86 + F_116 ( V_231 ) ;
F_92 ( & V_2 -> V_232 ) ;
F_92 ( & V_2 -> V_191 ) ;
if ( V_2 -> V_21 == 0 && F_114 ( V_2 ) == 0 ) {
F_96 ( & V_2 -> V_191 ) ;
goto V_160;
}
F_117 ( V_2 , V_233 ) ;
while ( ! F_118 ( V_31 , V_164 ) ) {
F_3 ( V_234 , L_13 ,
V_2 -> V_21 ,
F_114 ( V_2 ) ) ;
F_96 ( & V_2 -> V_191 ) ;
if ( F_114 ( V_2 ) )
F_90 ( & V_2 -> V_190 ) ;
F_119 ( 20 ) ;
F_92 ( & V_2 -> V_191 ) ;
if ( ( V_2 -> V_21 == 0 ) &&
( F_114 ( V_2 ) == 0 ) ) {
F_3 ( V_234 , L_14 ,
F_120 ( V_31 - V_86 ) ) ;
goto V_235;
}
}
F_99 ( L_15
L_16 ,
V_231 / 1000 ) ;
for ( V_143 = 0 ; V_143 < V_2 -> V_158 ; V_143 ++ )
F_108 ( V_2 , V_143 ) ;
V_235:
F_121 ( V_2 , V_233 ) ;
F_96 ( & V_2 -> V_191 ) ;
V_160:
F_96 ( & V_2 -> V_232 ) ;
}
T_2 F_122 ( struct V_1 * V_2 , T_2 V_129 )
{
if ( F_19 ( ! V_129 ) )
return 0 ;
return F_123 ( F_124 ( V_129 ) ) ;
}
void F_125 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_236 , enum V_237 V_238 )
{
int V_239 = F_126 ( V_4 , V_236 ) ;
bool V_240 = ! ! V_2 -> V_241 [ V_239 ] ;
F_64 ( F_127 ( V_238 , & V_2 -> V_241 [ V_239 ] ) ) ;
if ( V_240 )
return;
F_128 ( V_2 -> V_33 , V_239 ) ;
}
void F_129 ( struct V_1 * V_2 , struct V_3 * V_4 , T_1 V_236 ,
enum V_237 V_238 )
{
unsigned long V_23 ;
F_63 ( & V_2 -> V_153 , V_23 ) ;
F_125 ( V_2 , V_4 , V_236 , V_238 ) ;
F_65 ( & V_2 -> V_153 , V_23 ) ;
}
void F_59 ( struct V_1 * V_2 , struct V_3 * V_4 , T_1 V_236 ,
enum V_237 V_238 )
{
unsigned long V_23 ;
int V_239 = F_126 ( V_4 , V_236 ) ;
F_63 ( & V_2 -> V_153 , V_23 ) ;
F_64 ( ! F_35 ( V_238 , & V_2 -> V_241 [ V_239 ] ) ) ;
if ( V_2 -> V_241 [ V_239 ] )
goto V_160;
F_130 ( V_2 -> V_33 , V_239 ) ;
V_160:
F_65 ( & V_2 -> V_153 , V_23 ) ;
}
void F_117 ( struct V_1 * V_2 ,
enum V_237 V_238 )
{
int V_143 ;
unsigned long V_23 ;
F_63 ( & V_2 -> V_153 , V_23 ) ;
for ( V_143 = 0 ; V_143 < V_242 * V_144 ; V_143 ++ )
F_64 ( F_127 ( V_238 ,
& V_2 -> V_241 [ V_143 ] ) ) ;
F_131 ( V_2 -> V_33 ) ;
F_65 ( & V_2 -> V_153 , V_23 ) ;
}
void F_121 ( struct V_1 * V_2 ,
enum V_237 V_238 )
{
int V_143 ;
unsigned long V_23 ;
F_63 ( & V_2 -> V_153 , V_23 ) ;
for ( V_143 = 0 ; V_143 < V_242 * V_144 ; V_143 ++ )
F_64 ( ! F_35 ( V_238 ,
& V_2 -> V_241 [ V_143 ] ) ) ;
F_132 ( V_2 -> V_33 ) ;
F_65 ( & V_2 -> V_153 , V_23 ) ;
}
bool F_58 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_236 ,
enum V_237 V_238 )
{
unsigned long V_23 ;
bool V_240 ;
F_63 ( & V_2 -> V_153 , V_23 ) ;
V_240 = F_133 ( V_2 , V_4 , V_236 ,
V_238 ) ;
F_65 ( & V_2 -> V_153 , V_23 ) ;
return V_240 ;
}
bool F_133 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_236 ,
enum V_237 V_238 )
{
int V_239 = F_126 ( V_4 , V_236 ) ;
F_134 ( & V_2 -> V_153 ) ;
return F_20 ( V_238 , & V_2 -> V_241 [ V_239 ] ) ;
}
bool F_135 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_236 )
{
int V_239 = F_126 ( V_4 , V_236 ) ;
F_134 ( & V_2 -> V_153 ) ;
return ! ! V_2 -> V_241 [ V_239 ] ;
}
