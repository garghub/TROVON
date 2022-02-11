bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_3 ( V_2 ) ) ;
struct V_7 * V_8 = V_7 ( V_3 ( V_2 ) ) ;
bool V_9 = true ;
if ( V_8 -> V_10 == V_11 )
V_4 -> V_12 -> V_13 ( V_2 ) ;
if ( F_3 ( V_8 ) )
F_4 ( V_14 , V_15 , ( L_1 ) ) ;
V_4 -> V_16 -> V_17 -> V_18 ( V_2 ) ;
F_5 ( V_6 , V_19 ) ;
V_4 -> V_16 -> V_17 -> V_20 ( V_2 ) ;
F_6 ( ( unsigned long ) V_2 ) ;
return V_9 ;
}
bool F_7 ( struct V_1 * V_2 )
{
bool V_21 = true ;
struct V_3 * V_4 = V_3 ( V_2 ) ;
F_8 ( V_2 ) ;
V_4 -> V_16 -> V_17 -> V_22 ( V_2 ) ;
V_4 -> V_16 -> V_17 -> V_23 ( V_2 ) ;
return V_21 ;
}
bool F_9 ( struct V_1 * V_2 ,
enum V_24 V_25 ,
T_1 V_26 , bool V_27 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_3 ( V_2 ) ) ;
enum V_24 V_28 ;
bool V_29 = false ;
T_2 V_30 = 0 ;
if ( V_27 )
goto V_31;
while ( true ) {
F_10 ( & V_4 -> V_32 . V_33 ) ;
if ( V_6 -> V_34 ) {
F_11 ( & V_4 -> V_32 . V_33 ) ;
F_4 ( V_14 , V_15 ,
( L_2
L_3 ,
V_25 ) ) ;
while ( V_6 -> V_34 ) {
V_30 ++ ;
F_12 ( 1 ) ;
if ( V_30 > 100 )
return false ;
}
} else {
V_6 -> V_34 = true ;
F_11 ( & V_4 -> V_32 . V_33 ) ;
break;
}
}
V_31:
V_28 = V_6 -> V_35 ;
switch ( V_25 ) {
case V_36 :
V_6 -> V_37 &= ( ~ V_26 ) ;
if ( ( V_26 == V_38 ) &&
( V_6 -> V_39 == true ) ) {
V_6 -> V_39 = false ;
}
if ( ! V_6 -> V_37 ) {
V_6 -> V_37 = 0 ;
V_29 = true ;
}
break;
case V_40 :
if ( ( V_26 == V_38 ) &&
( V_6 -> V_39 == false ) ) {
V_6 -> V_39 = true ;
}
V_6 -> V_37 |= V_26 ;
V_29 = true ;
break;
case V_41 :
V_6 -> V_37 |= V_26 ;
V_29 = true ;
break;
default:
F_4 ( V_14 , V_42 , ( L_4 ) ) ;
break;
}
if ( V_29 )
V_4 -> V_16 -> V_17 -> V_43 ( V_2 , V_25 ) ;
if ( ! V_27 ) {
F_10 ( & V_4 -> V_32 . V_33 ) ;
V_6 -> V_34 = false ;
F_11 ( & V_4 -> V_32 . V_33 ) ;
}
return V_29 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_7 * V_8 = V_7 ( V_3 ( V_2 ) ) ;
struct V_5 * V_6 = F_2 ( V_3 ( V_2 ) ) ;
V_6 -> V_44 = true ;
if ( V_6 -> V_45 == V_36 && V_8 -> V_10 == V_11 ) {
if ( ( V_6 -> V_46 & V_47 ) &&
F_14 ( V_6 , V_48 ) &&
V_8 -> V_10 == V_11 ) {
V_4 -> V_12 -> V_49 ( V_2 ) ;
F_5 ( V_6 , V_48 ) ;
}
}
if ( V_4 -> V_16 -> V_17 -> V_50 () ) {
V_4 -> V_51 . V_52 -> V_53 ( V_4 ,
V_6 -> V_45 ) ;
}
F_9 ( V_2 , V_6 -> V_45 ,
V_54 , false ) ;
if ( V_6 -> V_45 == V_40 &&
V_8 -> V_10 == V_11 ) {
if ( V_6 -> V_46 & V_47 &&
! F_14 ( V_6 , V_48 ) ) {
V_4 -> V_12 -> V_55 ( V_2 ) ;
F_15 ( V_6 , V_48 ) ;
}
}
V_6 -> V_44 = false ;
}
void F_16 ( void * V_56 )
{
struct V_57 * V_58 =
F_17 ( V_56 , struct V_57 , V_59 ) ;
struct V_1 * V_2 = V_58 -> V_2 ;
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_7 * V_8 = V_7 ( V_3 ( V_2 ) ) ;
struct V_60 * V_61 = V_60 ( V_3 ( V_2 ) ) ;
struct V_5 * V_6 = F_2 ( V_3 ( V_2 ) ) ;
enum V_24 V_28 ;
if ( V_61 -> V_62 != V_63 ) {
F_4 ( V_14 , V_15 , ( L_5 ) ) ;
return;
}
if ( V_61 -> V_64 )
return;
if ( V_61 -> V_65 > V_66 )
return;
if ( F_3 ( V_8 ) )
return;
if ( V_4 -> V_67 . V_68 )
return;
if( V_4 -> V_16 -> V_17 -> V_69 )
V_4 -> V_16 -> V_17 -> V_69 ( V_2 ) ;
if ( V_6 -> V_70 ) {
V_28 = V_6 -> V_35 ;
if ( V_28 == V_36 &&
! V_6 -> V_44 &&
( V_61 -> V_65 == V_66 ) &&
! V_61 -> V_71 ) {
F_4 ( V_72 , V_73 ,
( L_6 ) ) ;
V_6 -> V_45 = V_40 ;
V_6 -> V_74 = true ;
F_13 ( V_2 ) ;
}
}
}
void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
F_19 ( V_4 -> V_75 . V_76 ,
& V_4 -> V_75 . V_59 , F_20 ( 100 ) ) ;
}
void F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_3 ( V_2 ) ) ;
enum V_24 V_28 ;
F_22 ( & V_4 -> V_75 . V_59 ) ;
F_10 ( & V_4 -> V_32 . V_77 ) ;
if ( V_6 -> V_70 ) {
V_28 = V_6 -> V_35 ;
if ( V_28 != V_36 &&
! V_6 -> V_44 &&
V_6 -> V_37 <= V_54 ) {
V_6 -> V_45 = V_36 ;
V_6 -> V_74 = false ;
F_13 ( V_2 ) ;
}
}
F_11 ( & V_4 -> V_32 . V_77 ) ;
}
static bool F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_60 * V_61 = V_60 ( V_3 ( V_2 ) ) ;
struct V_5 * V_6 = F_2 ( V_3 ( V_2 ) ) ;
T_1 V_78 ;
V_78 = F_24 ( V_79 -
V_6 -> V_80 ) ;
if ( V_78 < 2000 ) {
F_4 ( V_81 , V_73 ,
( L_7
L_8 ) ) ;
return false ;
}
if ( V_61 -> V_65 != V_82 )
return false ;
if ( V_61 -> V_62 == V_83 )
return false ;
return true ;
}
void F_25 ( struct V_1 * V_2 , T_3 V_84 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_60 * V_61 = V_60 ( V_3 ( V_2 ) ) ;
struct V_5 * V_6 = F_2 ( V_3 ( V_2 ) ) ;
bool V_85 ;
if ( V_61 -> V_62 == V_83 )
return;
if ( V_61 -> V_65 != V_82 )
return;
if ( V_6 -> V_86 == V_84 )
return;
V_6 -> V_86 = V_84 ;
if ( ( V_6 -> V_87 ) && V_6 -> V_88 ) {
if ( V_6 -> V_86 == V_89 ) {
F_4 ( V_72 , V_90 ,
( L_9 ,
V_91 ) ) ;
V_85 = false ;
V_6 -> V_92 = V_91 ;
V_6 -> V_93 = 0 ;
V_4 -> V_16 -> V_17 -> V_94 ( V_2 , V_95 ,
( T_3 * ) ( & V_85 ) ) ;
if ( V_6 -> V_96 . V_97 )
F_26 ( V_2 , V_98 ) ;
} else {
if ( F_23 ( V_2 ) ) {
F_4 ( V_72 , V_90 ,
( L_10 ,
V_6 -> V_99 ) ) ;
V_85 = true ;
V_6 -> V_92 = V_6 -> V_99 ;
V_6 -> V_93 = 2 ;
V_4 -> V_16 -> V_17 -> V_94 ( V_2 ,
V_95 ,
( T_3 * ) ( & V_85 ) ) ;
} else {
V_6 -> V_86 = V_89 ;
}
}
}
}
void F_27 ( struct V_1 * V_2 )
{
struct V_60 * V_61 = V_60 ( V_3 ( V_2 ) ) ;
struct V_5 * V_6 = F_2 ( V_3 ( V_2 ) ) ;
struct V_3 * V_4 = V_3 ( V_2 ) ;
unsigned long V_100 ;
if ( ! V_6 -> V_87 )
return;
if ( V_4 -> V_67 . V_68 )
return;
if ( V_4 -> V_101 . V_102 )
return;
if ( V_61 -> V_103 < 5 )
return;
if ( V_61 -> V_62 == V_83 )
return;
if ( V_61 -> V_65 != V_82 )
return;
F_28 ( & V_4 -> V_32 . V_104 , V_100 ) ;
if ( V_61 -> V_103 >= 2 ) {
if ( V_6 -> V_86 == V_89 ) {
F_4 ( V_81 , V_73 ,
( L_11 ) ) ;
F_25 ( V_2 , V_105 ) ;
}
}
F_29 ( & V_4 -> V_32 . V_104 , V_100 ) ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_3 ( V_2 ) ) ;
struct V_7 * V_8 = V_7 ( V_3 ( V_2 ) ) ;
unsigned long V_100 ;
F_28 ( & V_4 -> V_32 . V_104 , V_100 ) ;
if ( V_6 -> V_87 ) {
if ( V_6 -> V_86 != V_89 ) {
V_4 -> V_16 -> V_17 -> V_20 ( V_2 ) ;
if ( V_6 -> V_46 & V_106 &&
F_14 ( V_6 , V_48 ) &&
V_8 -> V_10 == V_11 ) {
V_4 -> V_12 -> V_49 ( V_2 ) ;
F_5 ( V_6 , V_48 ) ;
}
F_4 ( V_81 , V_73 ,
( L_12 ) ) ;
F_25 ( V_2 , V_89 ) ;
}
}
F_29 ( & V_4 -> V_32 . V_104 , V_100 ) ;
}
void F_31 ( struct V_1 * V_2 , void * V_56 , unsigned int V_107 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_60 * V_61 = V_60 ( V_3 ( V_2 ) ) ;
struct V_108 * V_109 = ( void * ) V_56 ;
struct V_110 * V_111 ;
T_3 * V_112 ;
T_3 V_113 ;
bool V_114 ;
bool V_115 ;
if ( V_61 -> V_62 != V_63 )
return;
if ( ! V_4 -> V_116 . V_117 )
return;
if ( V_4 -> V_118 . V_65 != V_82 )
return;
if ( ! V_4 -> V_116 . V_119 )
return;
if ( V_4 -> V_116 . V_87 )
return;
if ( F_32 ( ! ( V_2 -> V_120 . V_121 & V_122 ) ) )
return;
if ( ! F_33 ( V_109 -> V_123 ) )
return;
if ( V_107 <= 40 + V_124 )
return;
if ( F_34 ( V_109 -> V_125 , V_4 -> V_118 . V_126 ) )
return;
V_4 -> V_116 . V_127 = V_79 ;
V_112 = F_35 ( V_56 , V_107 - V_124 , V_128 ) ;
if ( ! V_112 )
return;
if ( V_112 [ 1 ] < sizeof( * V_111 ) )
return;
V_113 = V_112 [ 1 ] ;
V_111 = (struct V_110 * ) & V_112 [ 2 ] ;
if ( ! F_36 ( ! V_2 -> V_120 . V_129 ) )
V_4 -> V_116 . V_130 = V_111 -> V_131 ;
V_114 = F_37 ( V_111 , V_113 ,
V_4 -> V_118 . V_132 ) ;
V_115 = V_111 -> V_133 & 0x01 ;
V_4 -> V_116 . V_134 = V_115 ;
if ( ! V_115 ) {
F_19 ( V_4 -> V_75 . V_76 ,
& V_4 -> V_75 . V_135 , F_20 ( 5 ) ) ;
} else {
F_4 ( V_81 , V_90 ,
( L_13 ,
V_114 , V_115 ) ) ;
}
}
void F_38 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_5 * V_6 = F_2 ( V_3 ( V_2 ) ) ;
struct V_60 * V_61 = V_60 ( V_3 ( V_2 ) ) ;
unsigned long V_100 ;
if ( ! V_4 -> V_116 . V_117 )
return;
if ( V_61 -> V_65 != V_82 )
return;
if ( V_6 -> V_46 & V_106 &&
F_14 ( V_6 , V_48 ) ) {
V_4 -> V_12 -> V_49 ( V_2 ) ;
F_5 ( V_6 , V_48 ) ;
}
F_28 ( & V_4 -> V_32 . V_104 , V_100 ) ;
F_9 ( V_2 , V_36 , V_136 , false ) ;
F_29 ( & V_4 -> V_32 . V_104 , V_100 ) ;
}
void F_39 ( void * V_56 )
{
struct V_57 * V_58 =
F_17 ( V_56 , struct V_57 , V_137 ) ;
struct V_1 * V_2 = V_58 -> V_2 ;
F_38 ( V_2 ) ;
}
void F_40 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_60 * V_61 = V_60 ( V_3 ( V_2 ) ) ;
struct V_5 * V_6 = F_2 ( V_3 ( V_2 ) ) ;
unsigned long V_100 ;
T_3 V_138 ;
if ( ! V_4 -> V_116 . V_119 )
return;
if ( ( V_4 -> V_67 . V_68 ) ||
( V_61 -> V_62 == V_83 ) )
return;
if ( ( V_61 -> V_65 != V_82 ) || ( V_61 -> V_103 < 5 ) )
return;
if ( V_4 -> V_101 . V_102 )
return;
F_10 ( & V_4 -> V_32 . V_33 ) ;
if ( V_4 -> V_116 . V_34 ) {
F_11 ( & V_4 -> V_32 . V_33 ) ;
return;
}
F_11 ( & V_4 -> V_32 . V_33 ) ;
F_28 ( & V_4 -> V_32 . V_104 , V_100 ) ;
F_9 ( V_2 , V_41 , V_136 , false ) ;
F_29 ( & V_4 -> V_32 . V_104 , V_100 ) ;
if ( V_6 -> V_46 & V_47 &&
! F_14 ( V_6 , V_48 ) ) {
V_4 -> V_12 -> V_55 ( V_2 ) ;
F_15 ( V_6 , V_48 ) ;
}
if ( V_4 -> V_116 . V_130 == 0 ) {
if ( V_2 -> V_120 . V_129 == 1 )
V_138 = V_2 -> V_120 . V_129 * 2 ;
else
V_138 = V_2 -> V_120 . V_129 ;
} else {
V_138 = V_4 -> V_116 . V_130 ;
}
if ( V_138 > V_139 )
V_138 = V_139 ;
F_4 ( V_81 , V_90 ,
( L_14 ,
V_4 -> V_116 . V_130 , V_138 ) ) ;
F_19 ( V_4 -> V_75 . V_76 , & V_4 -> V_75 . V_137 ,
F_20 ( V_138 * V_61 -> V_140 -> V_141 . V_142 - 40 ) ) ;
}
void F_41 ( void * V_56 )
{
struct V_57 * V_58 =
F_17 ( V_56 , struct V_57 , V_135 ) ;
struct V_1 * V_2 = V_58 -> V_2 ;
struct V_3 * V_4 = V_3 ( V_2 ) ;
bool V_143 = false ;
V_143 = ( V_2 -> V_120 . V_121 & V_122 ) ;
if ( V_4 -> V_116 . V_144 ) {
F_40 ( V_2 ) ;
if ( V_4 -> V_116 . V_145 && ! V_143 ) {
V_4 -> V_116 . V_146 =
F_24 ( V_79 -
V_4 -> V_116 . V_147 ) ;
}
if ( V_143 )
V_4 -> V_116 . V_148 = V_79 ;
V_4 -> V_116 . V_147 = V_79 ;
V_4 -> V_116 . V_145 = V_143 ;
}
}
static void F_42 ( struct V_1 * V_2 , void * V_56 ,
unsigned int V_107 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_149 * V_150 = ( void * ) V_56 ;
struct V_151 * V_152 = & ( V_4 -> V_116 . V_96 ) ;
T_3 * V_153 , * V_154 , * V_155 ;
T_2 V_156 ;
static T_3 V_157 [ 4 ] = { 0x50 , 0x6f , 0x9a , 0x09 } ;
T_3 V_158 , V_159 , V_160 , V_161 = 0 ;
bool V_162 = false , V_163 = false ;
V_153 = ( T_3 * ) V_150 -> V_164 . V_165 . V_166 ;
V_154 = V_56 + V_107 ;
V_155 = NULL ;
while ( V_153 + 1 < V_154 ) {
if ( V_153 + 2 + V_153 [ 1 ] > V_154 )
return;
if ( V_153 [ 0 ] == 221 && V_153 [ 1 ] > 4 ) {
if ( memcmp ( & V_153 [ 2 ] , V_157 , 4 ) == 0 ) {
V_155 = V_153 + 2 + 4 ;
break;
}
}
V_153 += 2 + V_153 [ 1 ] ;
}
if ( V_155 == NULL )
return;
V_162 = true ;
while ( V_155 + 1 < V_154 ) {
V_156 = F_43 ( & V_155 [ 1 ] ) ;
if ( V_155 + 3 + V_155 [ 1 ] > V_154 )
return;
if ( V_155 [ 0 ] == 12 ) {
V_163 = true ;
if ( ( V_156 - 2 ) % 13 != 0 ) {
F_4 ( V_167 , V_73 ,
( L_15
L_16 , V_156 ) ) ;
return;
} else {
V_158 = ( V_156 - 2 ) / 13 ;
}
V_161 = V_155 [ 3 ] ;
if ( V_4 -> V_116 . V_96 . V_168 == V_169
|| V_161 != V_152 -> V_161 ) {
F_4 ( V_170 , V_73 ,
( L_17 ) ) ;
V_152 -> V_161 = V_161 ;
V_152 -> V_97 = ( V_155 [ 4 ] >> 7 ) ;
V_152 -> V_171 = V_155 [ 4 ] & 0x7F ;
V_152 -> V_158 = V_158 ;
V_159 = 5 ;
for ( V_160 = 0 ; V_160 < V_158 ; V_160 ++ ) {
V_152 -> V_172 [ V_160 ] =
F_44 ( V_155 + V_159 ) ;
V_159 += 1 ;
V_152 -> V_173 [ V_160 ] =
F_45 ( V_155 + V_159 ) ;
V_159 += 4 ;
V_152 -> V_174 [ V_160 ] =
F_45 ( V_155 + V_159 ) ;
V_159 += 4 ;
V_152 -> V_175 [ V_160 ] =
F_45 ( V_155 + V_159 ) ;
V_159 += 4 ;
}
if ( V_152 -> V_97 == 1 ) {
V_152 -> V_168 = V_176 ;
if ( V_4 -> V_116 . V_177 ) {
F_26 ( V_2 ,
V_98 ) ;
}
} else if ( V_152 -> V_158 > 0 ) {
V_152 -> V_168 = V_178 ;
F_26 ( V_2 , V_98 ) ;
} else if ( V_152 -> V_168 > V_169 ) {
F_26 ( V_2 , V_179 ) ;
}
}
break;
}
V_155 += 3 + V_156 ;
}
if ( V_162 == true ) {
if ( ( V_152 -> V_168 > V_169 ) &&
( V_163 == false ) )
F_26 ( V_2 , V_179 ) ;
}
}
static void F_46 ( struct V_1 * V_2 , void * V_56 ,
unsigned int V_107 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_149 * V_150 = ( void * ) V_56 ;
struct V_151 * V_152 = & ( V_4 -> V_116 . V_96 ) ;
bool V_162 = false , V_163 = false ;
T_3 V_158 , V_159 , V_160 , V_161 = 0 ;
T_3 * V_153 , * V_154 , * V_155 ;
T_2 V_156 ;
static T_3 V_157 [ 4 ] = { 0x50 , 0x6f , 0x9a , 0x09 } ;
V_153 = ( T_3 * ) & V_150 -> V_164 . V_180 . V_181 ;
V_154 = V_56 + V_107 ;
V_155 = NULL ;
if ( V_153 [ 0 ] == 0x7f ) {
if ( memcmp ( & V_153 [ 1 ] , V_157 , 4 ) == 0 ) {
V_155 = V_153 + 3 + 4 ;
}
}
if ( V_155 == NULL )
return;
V_162 = true ;
F_4 ( V_170 , V_73 , ( L_18 ) ) ;
while ( V_155 + 1 < V_154 ) {
V_156 = F_43 ( & V_155 [ 1 ] ) ;
if ( V_155 + 3 + V_155 [ 1 ] > V_154 )
return;
if ( V_155 [ 0 ] == 12 ) {
F_4 ( V_170 , V_73 , ( L_19 ) ) ;
F_47 ( V_4 , V_170 , V_73 , ( L_20 ) ,
V_155 , V_156 ) ;
V_163 = true ;
if ( ( V_156 - 2 ) % 13 != 0 ) {
F_4 ( V_170 , V_73 ,
( L_15
L_16 , V_156 ) ) ;
return;
} else {
V_158 = ( V_156 - 2 ) / 13 ;
}
V_161 = V_155 [ 3 ] ;
if ( V_4 -> V_116 . V_96 . V_168 == V_169
|| V_161 != V_152 -> V_161 ) {
V_152 -> V_161 = V_161 ;
V_152 -> V_97 = ( V_155 [ 4 ] >> 7 ) ;
V_152 -> V_171 = V_155 [ 4 ] & 0x7F ;
V_152 -> V_158 = V_158 ;
V_159 = 5 ;
for ( V_160 = 0 ; V_160 < V_158 ; V_160 ++ ) {
V_152 -> V_172 [ V_160 ] =
F_44 ( V_155 + V_159 ) ;
V_159 += 1 ;
V_152 -> V_173 [ V_160 ] =
F_45 ( V_155 + V_159 ) ;
V_159 += 4 ;
V_152 -> V_174 [ V_160 ] =
F_45 ( V_155 + V_159 ) ;
V_159 += 4 ;
V_152 -> V_175 [ V_160 ] =
F_45 ( V_155 + V_159 ) ;
V_159 += 4 ;
}
if ( V_152 -> V_97 == 1 ) {
V_152 -> V_168 = V_176 ;
if ( V_4 -> V_116 . V_177 ) {
F_26 ( V_2 ,
V_98 ) ;
}
} else if ( V_152 -> V_158 > 0 ) {
V_152 -> V_168 = V_178 ;
F_26 ( V_2 , V_98 ) ;
} else if ( V_152 -> V_168 > V_169 ) {
F_26 ( V_2 , V_179 ) ;
}
}
break;
}
V_155 += 3 + V_156 ;
}
}
void F_26 ( struct V_1 * V_2 , T_3 V_182 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_5 * V_183 = F_2 ( V_3 ( V_2 ) ) ;
struct V_151 * V_152 = & ( V_4 -> V_116 . V_96 ) ;
F_4 ( V_170 , V_73 , ( L_21 , V_182 ) ) ;
switch ( V_182 ) {
case V_179 :
V_152 -> V_182 = V_182 ;
V_4 -> V_16 -> V_17 -> V_94 ( V_2 ,
V_184 ,
( T_3 * ) ( & V_182 ) ) ;
V_152 -> V_161 = 0 ;
V_152 -> V_171 = 0 ;
V_152 -> V_97 = 0 ;
V_152 -> V_158 = 0 ;
V_152 -> V_168 = V_169 ;
if ( V_183 -> V_177 == true ) {
if ( V_183 -> V_93 == 0 ) {
V_183 -> V_93 = 2 ;
V_4 -> V_16 -> V_17 -> V_94 ( V_2 ,
V_185 ,
( T_3 * ) ( & V_183 -> V_92 ) ) ;
}
}
break;
case V_98 :
if ( V_152 -> V_168 > V_169 ) {
V_152 -> V_182 = V_182 ;
if ( V_152 -> V_171 > 0 ) {
if ( V_183 -> V_93 != 0 ) {
V_183 -> V_93 = 0 ;
V_4 -> V_16 -> V_17 -> V_94 (
V_2 , V_185 ,
( T_3 * ) ( & V_183 -> V_92 ) ) ;
}
}
V_4 -> V_16 -> V_17 -> V_94 ( V_2 ,
V_184 ,
( T_3 * ) ( & V_182 ) ) ;
}
break;
case V_186 :
case V_187 :
case V_188 :
if ( V_152 -> V_168 > V_169 ) {
V_152 -> V_182 = V_182 ;
V_4 -> V_16 -> V_17 -> V_94 ( V_2 ,
V_184 ,
( T_3 * ) ( & V_182 ) ) ;
}
break;
default:
break;
}
F_4 ( V_170 , V_73 , ( L_22 ,
V_152 -> V_171 , V_152 -> V_97 ) ) ;
F_4 ( V_170 , V_73 , ( L_23
L_24 ,
V_152 -> V_172 [ 0 ] ,
V_152 -> V_173 [ 0 ] ,
V_152 -> V_161 ,
V_152 -> V_174 [ 0 ] ,
V_152 -> V_175 [ 0 ] ,
V_152 -> V_158 ) ) ;
F_4 ( V_170 , V_73 , ( L_25 ) ) ;
}
void F_48 ( struct V_1 * V_2 , void * V_56 , unsigned int V_107 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_60 * V_61 = V_60 ( V_3 ( V_2 ) ) ;
struct V_108 * V_109 = ( void * ) V_56 ;
if ( ! V_61 -> V_189 )
return;
if ( V_61 -> V_65 != V_82 )
return;
if ( V_107 <= 40 + V_124 )
return;
if ( F_34 ( V_109 -> V_125 , V_4 -> V_118 . V_126 ) )
return;
if ( ! ( F_33 ( V_109 -> V_123 ) ||
F_49 ( V_109 -> V_123 ) ||
F_50 ( V_109 -> V_123 ) ) )
return;
if ( F_50 ( V_109 -> V_123 ) ) {
F_46 ( V_2 , V_56 , V_107 - V_124 ) ;
} else {
F_42 ( V_2 , V_56 , V_107 - V_124 ) ;
}
}
