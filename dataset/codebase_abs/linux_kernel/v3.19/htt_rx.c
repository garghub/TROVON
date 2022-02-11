static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_8 . V_9 ; V_7 ++ ) {
V_4 = V_2 -> V_8 . V_10 [ V_7 ] ;
V_6 = F_2 ( V_4 ) ;
F_3 ( V_2 -> V_11 -> V_12 , V_6 -> V_13 ,
V_4 -> V_14 + F_4 ( V_4 ) ,
V_15 ) ;
F_5 ( V_4 ) ;
}
V_2 -> V_8 . V_9 = 0 ;
}
static int F_6 ( struct V_1 * V_2 , int V_16 )
{
struct V_17 * V_18 ;
struct V_3 * V_4 ;
T_1 V_13 ;
int V_19 = 0 , V_20 ;
V_20 = F_7 ( * V_2 -> V_8 . V_21 . V_22 ) ;
while ( V_16 > 0 ) {
V_4 = F_8 ( V_23 + V_24 ) ;
if ( ! V_4 ) {
V_19 = - V_25 ;
goto V_26;
}
if ( ! F_9 ( ( unsigned long ) V_4 -> V_27 , V_24 ) )
F_10 ( V_4 ,
F_11 ( V_4 -> V_27 , V_24 ) -
V_4 -> V_27 ) ;
V_18 = (struct V_17 * ) V_4 -> V_27 ;
V_18 -> V_28 . V_29 = F_12 ( 0 ) ;
V_13 = F_13 ( V_2 -> V_11 -> V_12 , V_4 -> V_27 ,
V_4 -> V_14 + F_4 ( V_4 ) ,
V_15 ) ;
if ( F_14 ( F_15 ( V_2 -> V_11 -> V_12 , V_13 ) ) ) {
F_5 ( V_4 ) ;
V_19 = - V_25 ;
goto V_26;
}
F_2 ( V_4 ) -> V_13 = V_13 ;
V_2 -> V_8 . V_10 [ V_20 ] = V_4 ;
V_2 -> V_8 . V_30 [ V_20 ] = F_12 ( V_13 ) ;
V_2 -> V_8 . V_9 ++ ;
V_16 -- ;
V_20 ++ ;
V_20 &= V_2 -> V_8 . V_31 ;
}
V_26:
* V_2 -> V_8 . V_21 . V_22 = F_12 ( V_20 ) ;
return V_19 ;
}
static int F_16 ( struct V_1 * V_2 , int V_16 )
{
F_17 ( & V_2 -> V_8 . V_32 ) ;
return F_6 ( V_2 , V_16 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
int V_19 , V_33 , V_34 ;
F_19 ( & V_2 -> V_8 . V_32 ) ;
V_33 = V_2 -> V_8 . V_35 - V_2 -> V_8 . V_9 ;
V_34 = F_20 ( V_36 , V_33 ) ;
V_33 -= V_34 ;
V_19 = F_16 ( V_2 , V_34 ) ;
if ( V_19 == - V_25 ) {
F_21 ( & V_2 -> V_8 . V_37 , V_38 +
F_22 ( V_39 ) ) ;
} else if ( V_33 > 0 ) {
F_23 ( & V_2 -> V_40 ) ;
}
F_24 ( & V_2 -> V_8 . V_32 ) ;
}
static void F_25 ( unsigned long V_41 )
{
struct V_1 * V_2 = (struct V_1 * ) V_41 ;
F_18 ( V_2 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_8 . V_42 ; V_7 ++ ) {
V_4 = V_2 -> V_8 . V_10 [ V_7 ] ;
if ( ! V_4 )
continue;
F_3 ( V_2 -> V_11 -> V_12 , F_2 ( V_4 ) -> V_13 ,
V_4 -> V_14 + F_4 ( V_4 ) ,
V_15 ) ;
F_5 ( V_4 ) ;
V_2 -> V_8 . V_10 [ V_7 ] = NULL ;
}
}
void F_27 ( struct V_1 * V_2 )
{
F_28 ( & V_2 -> V_8 . V_37 ) ;
F_29 ( & V_2 -> V_40 ) ;
F_29 ( & V_2 -> V_43 ) ;
F_30 ( & V_2 -> V_44 ) ;
F_30 ( & V_2 -> V_45 ) ;
F_26 ( V_2 ) ;
F_31 ( V_2 -> V_11 -> V_12 ,
( V_2 -> V_8 . V_42 *
sizeof( V_2 -> V_8 . V_30 ) ) ,
V_2 -> V_8 . V_30 ,
V_2 -> V_8 . V_46 ) ;
F_31 ( V_2 -> V_11 -> V_12 ,
sizeof( * V_2 -> V_8 . V_21 . V_22 ) ,
V_2 -> V_8 . V_21 . V_22 ,
V_2 -> V_8 . V_21 . V_13 ) ;
F_32 ( V_2 -> V_8 . V_10 ) ;
}
static inline struct V_3 * F_33 ( struct V_1 * V_2 )
{
struct V_47 * V_11 = V_2 -> V_11 ;
int V_20 ;
struct V_3 * V_48 ;
F_17 ( & V_2 -> V_8 . V_32 ) ;
if ( V_2 -> V_8 . V_9 == 0 ) {
F_34 ( V_11 , L_1 ) ;
return NULL ;
}
V_20 = V_2 -> V_8 . V_49 . V_50 ;
V_48 = V_2 -> V_8 . V_10 [ V_20 ] ;
V_2 -> V_8 . V_10 [ V_20 ] = NULL ;
V_20 ++ ;
V_20 &= V_2 -> V_8 . V_31 ;
V_2 -> V_8 . V_49 . V_50 = V_20 ;
V_2 -> V_8 . V_9 -- ;
F_3 ( V_2 -> V_11 -> V_12 ,
F_2 ( V_48 ) -> V_13 ,
V_48 -> V_14 + F_4 ( V_48 ) ,
V_15 ) ;
F_35 ( V_11 , V_51 , NULL , L_2 ,
V_48 -> V_27 , V_48 -> V_14 + F_4 ( V_48 ) ) ;
return V_48 ;
}
static int F_36 ( struct V_1 * V_2 ,
T_2 * * V_52 , int * V_53 ,
struct V_54 * V_55 )
{
struct V_47 * V_11 = V_2 -> V_11 ;
int V_56 , V_57 = 0 ;
struct V_3 * V_48 ;
struct V_17 * V_18 ;
F_17 ( & V_2 -> V_8 . V_32 ) ;
for (; ; ) {
int V_58 , V_59 , V_60 ;
V_48 = F_33 ( V_2 ) ;
if ( ! V_48 ) {
F_37 ( V_55 ) ;
return - V_61 ;
}
F_38 ( V_55 , V_48 ) ;
V_18 = (struct V_17 * ) V_48 -> V_27 ;
F_39 ( V_48 , F_40 ( struct V_17 , V_62 ) ) ;
F_10 ( V_48 , F_40 ( struct V_17 , V_62 ) ) ;
if ( ! ( F_7 ( V_18 -> V_28 . V_29 )
& V_63 ) ) {
F_37 ( V_55 ) ;
return - V_64 ;
}
if ( * V_53 > 0 ) {
V_18 -> V_52 . V_65 = * * V_52 ;
( * V_52 ) ++ ;
( * V_53 ) -- ;
} else {
V_18 -> V_52 . V_65 = 0 ;
}
V_59 = ! ! ( F_7 ( V_18 -> V_28 . V_29 )
& ( V_66 |
V_67 ) ) ;
V_56 = F_41 ( F_7 ( V_18 -> V_68 . V_65 ) ,
V_69 ) ;
V_60 = V_18 -> V_70 . V_71 ;
if ( V_59 )
V_56 = 0 ;
F_42 ( V_48 , 0 ) ;
F_39 ( V_48 , F_20 ( V_56 , V_72 ) ) ;
V_56 -= V_48 -> V_14 ;
while ( V_60 -- ) {
V_48 = F_33 ( V_2 ) ;
if ( ! V_48 ) {
F_37 ( V_55 ) ;
return - V_61 ;
}
F_38 ( V_55 , V_48 ) ;
F_42 ( V_48 , 0 ) ;
F_39 ( V_48 , F_20 ( V_56 , V_23 ) ) ;
V_56 -= V_48 -> V_14 ;
V_57 = 1 ;
}
V_58 = F_7 ( V_18 -> V_73 . V_65 ) &
V_74 ;
F_43 ( V_11 , & V_18 -> V_28 ,
sizeof( * V_18 ) - sizeof( V_75 ) ) ;
if ( V_58 )
break;
}
if ( F_44 ( V_55 ) )
V_57 = - 1 ;
return V_57 ;
}
static void F_45 ( unsigned long V_76 )
{
struct V_1 * V_2 = (struct V_1 * ) V_76 ;
F_18 ( V_2 ) ;
}
int F_46 ( struct V_1 * V_2 )
{
struct V_47 * V_11 = V_2 -> V_11 ;
T_1 V_13 ;
void * V_22 ;
T_3 V_42 ;
struct V_77 * V_78 = & V_2 -> V_8 . V_37 ;
V_2 -> V_79 = false ;
V_2 -> V_8 . V_42 = V_80 ;
V_2 -> V_8 . V_31 = V_2 -> V_8 . V_42 - 1 ;
V_2 -> V_8 . V_35 = V_81 ;
if ( ! F_47 ( V_2 -> V_8 . V_42 ) ) {
F_34 ( V_11 , L_3 ) ;
return - V_82 ;
}
V_2 -> V_8 . V_10 =
F_48 ( V_2 -> V_8 . V_42 * sizeof( struct V_3 * ) ,
V_83 ) ;
if ( ! V_2 -> V_8 . V_10 )
goto V_84;
V_42 = V_2 -> V_8 . V_42 * sizeof( V_2 -> V_8 . V_30 ) ;
V_22 = F_49 ( V_2 -> V_11 -> V_12 , V_42 , & V_13 , V_85 ) ;
if ( ! V_22 )
goto V_86;
V_2 -> V_8 . V_30 = V_22 ;
V_2 -> V_8 . V_46 = V_13 ;
V_22 = F_49 ( V_2 -> V_11 -> V_12 ,
sizeof( * V_2 -> V_8 . V_21 . V_22 ) ,
& V_13 , V_85 ) ;
if ( ! V_22 )
goto V_87;
V_2 -> V_8 . V_21 . V_22 = V_22 ;
V_2 -> V_8 . V_21 . V_13 = V_13 ;
V_2 -> V_8 . V_49 . V_50 = 0 ;
* V_2 -> V_8 . V_21 . V_22 = 0 ;
F_50 ( V_78 , F_25 , ( unsigned long ) V_2 ) ;
F_51 ( & V_2 -> V_8 . V_32 ) ;
V_2 -> V_8 . V_9 = 0 ;
if ( F_6 ( V_2 , V_2 -> V_8 . V_35 ) )
goto V_88;
F_52 ( & V_2 -> V_40 , F_45 ,
( unsigned long ) V_2 ) ;
F_53 ( & V_2 -> V_44 ) ;
F_53 ( & V_2 -> V_45 ) ;
F_52 ( & V_2 -> V_43 , V_89 ,
( unsigned long ) V_2 ) ;
F_54 ( V_11 , V_90 , L_4 ,
V_2 -> V_8 . V_42 , V_2 -> V_8 . V_35 ) ;
return 0 ;
V_88:
F_1 ( V_2 ) ;
F_31 ( V_2 -> V_11 -> V_12 ,
sizeof( * V_2 -> V_8 . V_21 . V_22 ) ,
V_2 -> V_8 . V_21 . V_22 ,
V_2 -> V_8 . V_21 . V_13 ) ;
V_87:
F_31 ( V_2 -> V_11 -> V_12 ,
( V_2 -> V_8 . V_42 *
sizeof( V_2 -> V_8 . V_30 ) ) ,
V_2 -> V_8 . V_30 ,
V_2 -> V_8 . V_46 ) ;
V_86:
F_32 ( V_2 -> V_8 . V_10 ) ;
V_84:
return - V_25 ;
}
static int F_55 ( struct V_47 * V_11 ,
enum V_91 type )
{
switch ( type ) {
case V_92 :
return 0 ;
case V_93 :
case V_94 :
return V_95 ;
case V_96 :
case V_97 :
return V_98 ;
case V_99 :
return V_100 ;
case V_101 :
case V_102 :
break;
}
F_34 ( V_11 , L_5 , type ) ;
return 0 ;
}
static int F_56 ( struct V_47 * V_11 ,
enum V_91 type )
{
switch ( type ) {
case V_92 :
return 0 ;
case V_93 :
case V_94 :
return V_103 ;
case V_96 :
case V_97 :
return V_104 ;
case V_99 :
return V_105 ;
case V_101 :
case V_102 :
break;
}
F_34 ( V_11 , L_5 , type ) ;
return 0 ;
}
static void F_57 ( struct V_47 * V_11 ,
struct V_106 * V_107 ,
struct V_17 * V_108 )
{
enum V_109 V_110 ;
T_2 V_111 , V_112 , V_113 , V_114 , V_115 , V_116 , V_117 ;
T_2 V_118 = 0 ;
V_75 V_119 , V_120 , V_121 ;
if ( ! V_107 -> V_122 )
return;
V_110 = V_107 -> V_110 ;
V_119 = F_7 ( V_108 -> V_123 . V_119 ) ;
V_120 = F_7 ( V_108 -> V_123 . V_120 ) ;
V_121 = F_7 ( V_108 -> V_123 . V_121 ) ;
V_118 = F_41 ( V_119 , V_124 ) ;
switch ( V_118 ) {
case V_125 :
V_111 = V_119 & V_126 ;
V_112 = F_41 ( V_119 , V_127 ) ;
V_113 = 0 ;
if ( V_112 < 0x08 || V_112 > 0x0F )
break;
switch ( V_110 ) {
case V_128 :
if ( V_111 )
V_112 &= ~ F_58 ( 3 ) ;
V_113 = V_129 [ V_112 ] ;
break;
case V_130 :
V_113 = V_129 [ V_112 ] ;
V_113 -= 4 ;
break;
default:
break;
}
V_107 -> V_113 = V_113 ;
break;
case V_131 :
case V_132 :
V_116 = V_120 & 0x1F ;
V_117 = V_116 >> 3 ;
V_114 = ( V_120 >> 7 ) & 1 ;
V_115 = ( V_121 >> 7 ) & 1 ;
V_107 -> V_113 = V_116 ;
V_107 -> V_133 |= V_134 ;
if ( V_115 )
V_107 -> V_133 |= V_135 ;
if ( V_114 )
V_107 -> V_133 |= V_136 ;
break;
case V_137 :
case V_138 :
V_116 = ( V_121 >> 4 ) & 0x0F ;
V_117 = ( ( V_120 >> 10 ) & 0x07 ) + 1 ;
V_114 = V_120 & 3 ;
V_115 = V_121 & 1 ;
V_107 -> V_113 = V_116 ;
V_107 -> V_139 = V_117 ;
if ( V_115 )
V_107 -> V_133 |= V_135 ;
switch ( V_114 ) {
case 0 :
break;
case 1 :
V_107 -> V_133 |= V_136 ;
break;
case 2 :
V_107 -> V_140 |= V_141 ;
}
V_107 -> V_133 |= V_142 ;
break;
default:
break;
}
}
static bool F_59 ( struct V_47 * V_11 ,
struct V_106 * V_107 )
{
struct V_143 * V_144 ;
F_19 ( & V_11 -> V_145 ) ;
V_144 = V_11 -> V_146 ;
if ( ! V_144 )
V_144 = V_11 -> V_147 ;
F_24 ( & V_11 -> V_145 ) ;
if ( ! V_144 )
return false ;
V_107 -> V_110 = V_144 -> V_110 ;
V_107 -> V_122 = V_144 -> V_148 ;
return true ;
}
static void F_60 ( struct V_47 * V_11 ,
struct V_106 * V_107 ,
struct V_17 * V_108 )
{
V_107 -> signal = V_149 +
V_108 -> V_123 . V_150 ;
V_107 -> V_133 &= ~ V_151 ;
}
static void F_61 ( struct V_47 * V_11 ,
struct V_106 * V_107 ,
struct V_17 * V_108 )
{
V_107 -> V_152 = F_7 ( V_108 -> V_153 . V_154 ) ;
V_107 -> V_133 |= V_155 ;
}
static void F_62 ( struct V_47 * V_11 ,
struct V_54 * V_55 ,
struct V_106 * V_107 )
{
struct V_3 * V_156 ;
struct V_17 * V_108 ;
bool V_157 ;
bool V_158 ;
if ( F_44 ( V_55 ) )
return;
V_156 = F_63 ( V_55 ) ;
V_108 = ( void * ) V_156 -> V_27 - sizeof( * V_108 ) ;
V_157 = ! ! ( V_108 -> V_28 . V_29 &
F_12 ( V_159 ) ) ;
V_158 = ! ! ( V_108 -> V_28 . V_29 &
F_12 ( V_160 ) ) ;
if ( V_157 ) {
V_107 -> V_122 = 0 ;
V_107 -> V_113 = 0 ;
V_107 -> V_139 = 0 ;
V_107 -> V_140 &= ~ V_141 ;
V_107 -> V_133 &= ~ ( V_134 |
V_142 |
V_135 |
V_136 |
V_155 ) ;
V_107 -> V_133 |= V_151 ;
F_60 ( V_11 , V_107 , V_108 ) ;
F_59 ( V_11 , V_107 ) ;
F_57 ( V_11 , V_107 , V_108 ) ;
}
if ( V_158 )
F_61 ( V_11 , V_107 , V_108 ) ;
}
static char * F_64 ( struct V_161 * V_162 , char * V_163 , T_3 V_42 )
{
T_2 * V_164 ;
int V_165 ;
if ( ! F_65 ( V_162 -> V_166 ) )
return L_6 ;
V_164 = F_66 ( V_162 ) ;
V_165 = * V_164 & V_167 ;
if ( V_165 < 8 )
snprintf ( V_163 , V_42 , L_7 , V_165 , V_168 [ V_165 ] ) ;
else
snprintf ( V_163 , V_42 , L_8 , V_165 ) ;
return V_163 ;
}
static void F_67 ( struct V_47 * V_11 ,
struct V_106 * V_169 ,
struct V_3 * V_4 )
{
struct V_106 * V_107 ;
struct V_161 * V_162 = (struct V_161 * ) V_4 -> V_27 ;
char V_165 [ 32 ] ;
V_107 = F_68 ( V_4 ) ;
* V_107 = * V_169 ;
F_54 ( V_11 , V_170 ,
L_9 ,
V_4 ,
V_4 -> V_14 ,
F_69 ( V_162 ) ,
F_64 ( V_162 , V_165 , sizeof( V_165 ) ) ,
F_70 ( F_71 ( V_162 ) ) ?
L_10 : L_11 ,
( F_72 ( V_162 -> V_171 ) & V_172 ) >> 4 ,
V_107 -> V_133 == 0 ? L_12 : L_6 ,
V_107 -> V_133 & V_134 ? L_13 : L_6 ,
V_107 -> V_133 & V_142 ? L_14 : L_6 ,
V_107 -> V_133 & V_136 ? L_15 : L_6 ,
V_107 -> V_140 & V_141 ? L_16 : L_6 ,
V_107 -> V_133 & V_135 ? L_17 : L_6 ,
V_107 -> V_113 ,
V_107 -> V_139 ,
V_107 -> V_122 ,
V_107 -> V_110 , V_107 -> V_133 ,
! ! ( V_107 -> V_133 & V_173 ) ,
! ! ( V_107 -> V_133 & V_174 ) ,
! ! ( V_107 -> V_133 & V_175 ) ) ;
F_35 ( V_11 , V_51 , NULL , L_18 ,
V_4 -> V_27 , V_4 -> V_14 ) ;
F_73 ( V_11 , V_4 -> V_27 , V_4 -> V_14 ) ;
F_74 ( V_11 , V_4 -> V_27 , V_4 -> V_14 ) ;
F_75 ( V_11 -> V_176 , V_4 ) ;
}
static int F_76 ( struct V_161 * V_162 )
{
return F_77 ( F_78 ( V_162 -> V_166 ) , 4 ) ;
}
static void F_79 ( struct V_47 * V_11 ,
struct V_3 * V_48 ,
struct V_106 * V_107 ,
enum V_91 V_177 ,
bool V_178 )
{
struct V_161 * V_162 ;
struct V_17 * V_108 ;
T_3 V_179 ;
T_3 V_180 ;
bool V_181 ;
bool V_182 ;
V_108 = ( void * ) V_48 -> V_27 - sizeof( * V_108 ) ;
V_181 = ! ! ( V_108 -> V_73 . V_65 &
F_12 ( V_183 ) ) ;
V_182 = ! ! ( V_108 -> V_73 . V_65 &
F_12 ( V_74 ) ) ;
if ( F_14 ( F_80 ( ! V_181 ) ) )
return;
if ( F_14 ( F_80 ( ! ( V_181 && V_182 ) ) ) )
return;
F_42 ( V_48 , V_48 -> V_14 - V_184 ) ;
if ( ! V_178 )
return;
V_162 = ( void * ) V_48 -> V_27 ;
F_42 ( V_48 , V_48 -> V_14 - F_56 ( V_11 , V_177 ) ) ;
if ( ! F_81 ( V_162 -> V_166 ) &&
V_177 == V_97 )
F_42 ( V_48 , V_48 -> V_14 - 8 ) ;
V_179 = F_78 ( V_162 -> V_166 ) ;
V_180 = F_55 ( V_11 , V_177 ) ;
memmove ( ( void * ) V_48 -> V_27 + V_180 ,
( void * ) V_48 -> V_27 , V_179 ) ;
F_10 ( V_48 , V_180 ) ;
}
static void F_82 ( struct V_47 * V_11 ,
struct V_3 * V_48 ,
struct V_106 * V_107 ,
const T_2 V_185 [ 64 ] )
{
struct V_161 * V_162 ;
T_3 V_179 ;
T_2 V_186 [ V_187 ] ;
T_2 V_188 [ V_187 ] ;
V_162 = (struct V_161 * ) V_48 -> V_27 ;
V_179 = F_76 ( V_162 ) ;
F_83 ( V_186 , F_71 ( V_162 ) ) ;
F_83 ( V_188 , F_69 ( V_162 ) ) ;
F_10 ( V_48 , V_179 ) ;
V_162 = (struct V_161 * ) V_185 ;
V_179 = F_78 ( V_162 -> V_166 ) ;
memcpy ( F_84 ( V_48 , V_179 ) , V_162 , V_179 ) ;
V_162 = (struct V_161 * ) V_48 -> V_27 ;
F_83 ( F_71 ( V_162 ) , V_186 ) ;
F_83 ( F_69 ( V_162 ) , V_188 ) ;
}
static void * F_85 ( struct V_47 * V_11 ,
struct V_3 * V_48 ,
enum V_91 V_177 )
{
struct V_161 * V_162 ;
struct V_17 * V_108 ;
T_3 V_179 , V_180 ;
void * V_189 ;
bool V_181 , V_182 , V_190 ;
V_108 = ( void * ) V_48 -> V_27 - sizeof( * V_108 ) ;
V_162 = ( void * ) V_108 -> V_191 ;
V_181 = ! ! ( V_108 -> V_73 . V_65 &
F_12 ( V_183 ) ) ;
V_182 = ! ! ( V_108 -> V_73 . V_65 &
F_12 ( V_74 ) ) ;
V_190 = ! ( V_181 && V_182 ) ;
V_189 = V_162 ;
if ( V_181 ) {
V_179 = F_78 ( V_162 -> V_166 ) ;
V_180 = F_55 ( V_11 , V_177 ) ;
V_189 += F_77 ( V_179 , 4 ) +
F_77 ( V_180 , 4 ) ;
}
if ( V_190 )
V_189 += sizeof( struct V_192 ) ;
return V_189 ;
}
static void F_86 ( struct V_47 * V_11 ,
struct V_3 * V_48 ,
struct V_106 * V_107 ,
const T_2 V_185 [ 64 ] ,
enum V_91 V_177 )
{
struct V_161 * V_162 ;
struct V_193 * V_194 ;
T_3 V_179 ;
void * V_189 ;
T_2 V_186 [ V_187 ] ;
T_2 V_188 [ V_187 ] ;
V_189 = F_85 ( V_11 , V_48 , V_177 ) ;
if ( F_80 ( ! V_189 ) )
return;
V_194 = (struct V_193 * ) V_48 -> V_27 ;
F_83 ( V_186 , V_194 -> V_195 ) ;
F_83 ( V_188 , V_194 -> V_196 ) ;
F_10 ( V_48 , sizeof( struct V_193 ) ) ;
memcpy ( F_84 ( V_48 , sizeof( struct V_197 ) ) , V_189 ,
sizeof( struct V_197 ) ) ;
V_162 = (struct V_161 * ) V_185 ;
V_179 = F_78 ( V_162 -> V_166 ) ;
memcpy ( F_84 ( V_48 , V_179 ) , V_162 , V_179 ) ;
V_162 = (struct V_161 * ) V_48 -> V_27 ;
F_83 ( F_71 ( V_162 ) , V_186 ) ;
F_83 ( F_69 ( V_162 ) , V_188 ) ;
}
static void F_87 ( struct V_47 * V_11 ,
struct V_3 * V_48 ,
struct V_106 * V_107 ,
const T_2 V_185 [ 64 ] )
{
struct V_161 * V_162 ;
T_3 V_179 ;
F_10 ( V_48 , sizeof( struct V_192 ) ) ;
V_162 = (struct V_161 * ) V_185 ;
V_179 = F_78 ( V_162 -> V_166 ) ;
memcpy ( F_84 ( V_48 , V_179 ) , V_162 , V_179 ) ;
}
static void F_88 ( struct V_47 * V_11 ,
struct V_3 * V_48 ,
struct V_106 * V_107 ,
T_2 V_185 [ 64 ] ,
enum V_91 V_177 ,
bool V_178 )
{
struct V_17 * V_108 ;
enum V_198 V_199 ;
struct V_161 * V_162 ;
V_108 = ( void * ) V_48 -> V_27 - sizeof( * V_108 ) ;
V_162 = ( void * ) V_108 -> V_191 ;
V_199 = F_41 ( F_7 ( V_108 -> V_68 . V_119 ) ,
V_200 ) ;
switch ( V_199 ) {
case V_201 :
F_79 ( V_11 , V_48 , V_107 , V_177 ,
V_178 ) ;
break;
case V_202 :
F_82 ( V_11 , V_48 , V_107 , V_185 ) ;
break;
case V_203 :
F_86 ( V_11 , V_48 , V_107 , V_185 , V_177 ) ;
break;
case V_204 :
F_87 ( V_11 , V_48 , V_107 , V_185 ) ;
break;
}
}
static int F_89 ( struct V_3 * V_4 )
{
struct V_17 * V_108 ;
V_75 V_29 , V_205 ;
bool V_206 , V_207 ;
bool V_208 , V_209 ;
bool V_210 , V_211 ;
V_108 = ( void * ) V_4 -> V_27 - sizeof( * V_108 ) ;
V_29 = F_7 ( V_108 -> V_28 . V_29 ) ;
V_205 = F_7 ( V_108 -> V_68 . V_119 ) ;
V_206 = ! ! ( V_205 & V_212 ) ;
V_207 = ! ! ( V_205 & V_213 ) ;
V_208 = ! ! ( V_205 & V_214 ) ;
V_209 = ! ! ( V_205 & V_215 ) ;
V_210 = ! ( V_29 & V_216 ) ;
V_211 = ! ( V_29 & V_217 ) ;
if ( ! V_206 && ! V_207 )
return V_218 ;
if ( ! V_208 && ! V_209 )
return V_218 ;
if ( ! V_210 )
return V_218 ;
if ( ! V_211 )
return V_218 ;
return V_219 ;
}
static void F_90 ( struct V_3 * V_48 )
{
V_48 -> V_220 = F_89 ( V_48 ) ;
}
static void F_91 ( struct V_47 * V_11 ,
struct V_54 * V_55 ,
struct V_106 * V_107 )
{
struct V_3 * V_156 ;
struct V_3 * V_221 ;
struct V_3 * V_48 ;
struct V_17 * V_108 ;
struct V_161 * V_162 ;
enum V_91 V_177 ;
T_2 V_185 [ 64 ] ;
T_2 * V_222 ;
T_3 V_179 ;
bool V_223 ;
bool V_224 ;
bool V_225 ;
bool V_226 ;
bool V_178 ;
V_75 V_28 ;
if ( F_44 ( V_55 ) )
return;
V_156 = F_63 ( V_55 ) ;
V_108 = ( void * ) V_156 -> V_27 - sizeof( * V_108 ) ;
V_177 = F_41 ( F_7 ( V_108 -> V_227 . V_65 ) ,
V_228 ) ;
V_162 = ( void * ) V_108 -> V_191 ;
V_179 = F_78 ( V_162 -> V_166 ) ;
memcpy ( V_185 , V_162 , V_179 ) ;
V_162 = ( void * ) V_185 ;
V_222 = F_66 ( V_162 ) ;
V_222 [ 0 ] &= ~ V_229 ;
V_221 = F_92 ( V_55 ) ;
V_108 = ( void * ) V_221 -> V_27 - sizeof( * V_108 ) ;
V_28 = F_7 ( V_108 -> V_28 . V_29 ) ;
V_223 = ! ! ( V_28 & V_230 ) ;
V_224 = ! ! ( V_28 & V_231 ) ;
V_225 = ! ! ( V_28 & V_232 ) ;
V_226 = ! ! ( V_28 & V_233 ) ;
V_178 = ( V_177 != V_92 &&
! V_223 &&
! V_224 &&
! V_226 ) ;
V_107 -> V_133 &= ~ ( V_173 |
V_174 |
V_234 |
V_235 |
V_236 ) ;
if ( V_223 )
V_107 -> V_133 |= V_173 ;
if ( V_225 )
V_107 -> V_133 |= V_174 ;
if ( V_178 )
V_107 -> V_133 |= V_234 |
V_235 |
V_236 ;
F_93 (amsdu, msdu) {
F_90 ( V_48 ) ;
F_88 ( V_11 , V_48 , V_107 , V_185 , V_177 ,
V_178 ) ;
if ( ! V_178 )
continue;
V_162 = ( void * ) V_48 -> V_27 ;
V_162 -> V_166 &= ~ F_94 ( V_237 ) ;
}
}
static void F_95 ( struct V_47 * V_11 ,
struct V_54 * V_55 ,
struct V_106 * V_107 )
{
struct V_3 * V_48 ;
while ( ( V_48 = F_96 ( V_55 ) ) ) {
if ( F_44 ( V_55 ) )
V_107 -> V_133 &= ~ V_175 ;
else
V_107 -> V_133 |= V_175 ;
F_67 ( V_11 , V_107 , V_48 ) ;
}
}
static int F_97 ( struct V_54 * V_55 )
{
struct V_3 * V_4 , * V_156 ;
int V_238 ;
int V_239 = 0 ;
V_156 = F_96 ( V_55 ) ;
F_93 (amsdu, skb)
V_239 += V_4 -> V_14 ;
V_238 = V_239 - F_4 ( V_156 ) ;
if ( ( V_238 > 0 ) &&
( F_98 ( V_156 , 0 , V_238 , V_240 ) < 0 ) ) {
F_99 ( V_55 , V_156 ) ;
return - 1 ;
}
while ( ( V_4 = F_96 ( V_55 ) ) ) {
F_100 ( V_4 , F_39 ( V_156 , V_4 -> V_14 ) ,
V_4 -> V_14 ) ;
F_5 ( V_4 ) ;
}
F_99 ( V_55 , V_156 ) ;
return 0 ;
}
static void F_101 ( struct V_47 * V_11 ,
struct V_54 * V_55 ,
bool V_241 )
{
struct V_3 * V_156 ;
struct V_17 * V_108 ;
enum V_198 V_199 ;
V_156 = F_63 ( V_55 ) ;
V_108 = ( void * ) V_156 -> V_27 - sizeof( * V_108 ) ;
V_199 = F_41 ( F_7 ( V_108 -> V_68 . V_119 ) ,
V_200 ) ;
if ( ! V_241 )
return;
if ( V_199 != V_201 ||
F_102 ( V_55 ) != 1 + V_108 -> V_70 . V_71 ) {
F_37 ( V_55 ) ;
return;
}
F_97 ( V_55 ) ;
}
static bool F_103 ( struct V_47 * V_11 ,
struct V_54 * V_55 ,
struct V_106 * V_169 )
{
struct V_3 * V_48 ;
struct V_17 * V_108 ;
bool V_242 ;
bool V_223 ;
V_48 = F_63 ( V_55 ) ;
V_108 = ( void * ) V_48 -> V_27 - sizeof( * V_108 ) ;
if ( ! V_169 -> V_122 ) {
F_34 ( V_11 , L_19 ) ;
return false ;
}
V_242 = ! ! ( V_108 -> V_28 . V_29 &
F_12 ( V_243 ) ) ;
V_223 = ! ! ( V_108 -> V_28 . V_29 &
F_12 ( V_230 ) ) ;
if ( V_242 && ! V_223 ) {
F_54 ( V_11 , V_244 , L_20 ) ;
return false ;
}
if ( F_104 ( V_245 , & V_11 -> V_246 ) ) {
F_54 ( V_11 , V_244 , L_21 ) ;
return false ;
}
return true ;
}
static void F_105 ( struct V_47 * V_11 ,
struct V_54 * V_55 ,
struct V_106 * V_169 )
{
if ( F_44 ( V_55 ) )
return;
if ( F_103 ( V_11 , V_55 , V_169 ) )
return;
F_37 ( V_55 ) ;
}
static void F_106 ( struct V_1 * V_2 ,
struct V_247 * V_248 )
{
struct V_47 * V_11 = V_2 -> V_11 ;
struct V_106 * V_169 = & V_2 -> V_169 ;
struct V_249 * V_250 ;
struct V_54 V_55 ;
int V_251 ;
int V_53 ;
T_2 * V_52 ;
int V_7 , V_19 , V_252 = 0 ;
F_17 ( & V_2 -> V_8 . V_32 ) ;
if ( V_2 -> V_79 )
return;
V_53 = F_72 ( V_248 -> V_253 . V_254 ) ;
V_52 = ( T_2 * ) & V_248 -> V_52 ;
V_251 = F_41 ( F_7 ( V_248 -> V_162 . V_119 ) ,
V_255 ) ;
V_250 = F_107 ( V_248 ) ;
F_35 ( V_11 , V_51 , NULL , L_22 ,
V_248 , sizeof( * V_248 ) +
( sizeof( struct V_249 ) *
V_251 ) ) ;
for ( V_7 = 0 ; V_7 < V_251 ; V_7 ++ )
V_252 += V_250 [ V_7 ] . V_252 ;
while ( V_252 -- ) {
F_108 ( & V_55 ) ;
V_19 = F_36 ( V_2 , & V_52 ,
& V_53 , & V_55 ) ;
if ( V_19 < 0 ) {
F_34 ( V_11 , L_23 , V_19 ) ;
F_37 ( & V_55 ) ;
V_2 -> V_79 = true ;
break;
}
F_62 ( V_11 , & V_55 , V_169 ) ;
F_101 ( V_11 , & V_55 , V_19 > 0 ) ;
F_105 ( V_11 , & V_55 , V_169 ) ;
F_91 ( V_11 , & V_55 , V_169 ) ;
F_95 ( V_11 , & V_55 , V_169 ) ;
}
F_23 ( & V_2 -> V_40 ) ;
}
static void F_109 ( struct V_1 * V_2 ,
struct V_256 * V_257 )
{
struct V_47 * V_11 = V_2 -> V_11 ;
struct V_106 * V_169 = & V_2 -> V_169 ;
struct V_54 V_55 ;
int V_19 ;
T_2 * V_52 ;
int V_53 ;
V_53 = F_72 ( V_257 -> V_254 ) ;
V_52 = ( T_2 * ) V_257 -> V_258 ;
F_108 ( & V_55 ) ;
F_19 ( & V_2 -> V_8 . V_32 ) ;
V_19 = F_36 ( V_2 , & V_52 , & V_53 ,
& V_55 ) ;
F_24 ( & V_2 -> V_8 . V_32 ) ;
F_23 ( & V_2 -> V_40 ) ;
F_54 ( V_11 , V_51 , L_24 ) ;
if ( V_19 ) {
F_34 ( V_11 , L_25 ,
V_19 ) ;
F_37 ( & V_55 ) ;
return;
}
if ( F_102 ( & V_55 ) != 1 ) {
F_34 ( V_11 , L_26 ) ;
F_37 ( & V_55 ) ;
return;
}
F_62 ( V_11 , & V_55 , V_169 ) ;
F_105 ( V_11 , & V_55 , V_169 ) ;
F_91 ( V_11 , & V_55 , V_169 ) ;
F_95 ( V_11 , & V_55 , V_169 ) ;
if ( V_53 > 0 ) {
F_54 ( V_11 , V_244 ,
L_27 ,
V_53 ) ;
}
}
static void F_110 ( struct V_47 * V_11 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_11 -> V_2 ;
struct V_259 * V_260 = (struct V_259 * ) V_4 -> V_27 ;
struct V_261 V_262 = {} ;
int V_107 = F_41 ( V_260 -> V_263 . V_29 , V_264 ) ;
T_4 V_265 ;
int V_7 ;
F_17 ( & V_2 -> V_266 ) ;
switch ( V_107 ) {
case V_267 :
V_262 . V_268 = true ;
break;
case V_269 :
break;
case V_270 :
case V_271 :
case V_272 :
V_262 . V_273 = true ;
break;
default:
F_34 ( V_11 , L_28 , V_107 ) ;
V_262 . V_273 = true ;
break;
}
F_54 ( V_11 , V_244 , L_29 ,
V_260 -> V_263 . V_274 ) ;
for ( V_7 = 0 ; V_7 < V_260 -> V_263 . V_274 ; V_7 ++ ) {
V_265 = V_260 -> V_263 . V_275 [ V_7 ] ;
V_262 . V_265 = F_72 ( V_265 ) ;
F_111 ( V_2 , & V_262 ) ;
}
}
static void F_112 ( struct V_47 * V_11 , struct V_259 * V_260 )
{
struct V_276 * V_277 = & V_260 -> V_278 ;
struct V_279 * V_280 ;
struct V_281 * V_282 ;
T_5 V_65 , V_165 , V_283 ;
V_65 = F_72 ( V_277 -> V_65 ) ;
V_165 = F_41 ( V_65 , V_284 ) ;
V_283 = F_41 ( V_65 , V_285 ) ;
F_54 ( V_11 , V_244 ,
L_30 ,
V_165 , V_283 , V_277 -> V_286 ) ;
F_19 ( & V_11 -> V_145 ) ;
V_280 = F_113 ( V_11 , V_283 ) ;
if ( ! V_280 ) {
F_34 ( V_11 , L_31 ,
V_283 ) ;
F_24 ( & V_11 -> V_145 ) ;
return;
}
V_282 = F_114 ( V_11 , V_280 -> V_287 ) ;
if ( ! V_282 ) {
F_34 ( V_11 , L_32 ,
V_280 -> V_287 ) ;
F_24 ( & V_11 -> V_145 ) ;
return;
}
F_54 ( V_11 , V_244 ,
L_33 ,
V_280 -> V_288 , V_165 , V_277 -> V_286 ) ;
F_115 ( V_282 -> V_289 , V_280 -> V_288 , V_165 ) ;
F_24 ( & V_11 -> V_145 ) ;
}
static void F_116 ( struct V_47 * V_11 , struct V_259 * V_260 )
{
struct V_290 * V_277 = & V_260 -> V_291 ;
struct V_279 * V_280 ;
struct V_281 * V_282 ;
T_5 V_65 , V_165 , V_283 ;
V_65 = F_72 ( V_277 -> V_65 ) ;
V_165 = F_41 ( V_65 , V_284 ) ;
V_283 = F_41 ( V_65 , V_285 ) ;
F_54 ( V_11 , V_244 ,
L_34 ,
V_165 , V_283 ) ;
F_19 ( & V_11 -> V_145 ) ;
V_280 = F_113 ( V_11 , V_283 ) ;
if ( ! V_280 ) {
F_34 ( V_11 , L_31 ,
V_283 ) ;
F_24 ( & V_11 -> V_145 ) ;
return;
}
V_282 = F_114 ( V_11 , V_280 -> V_287 ) ;
if ( ! V_282 ) {
F_34 ( V_11 , L_32 ,
V_280 -> V_287 ) ;
F_24 ( & V_11 -> V_145 ) ;
return;
}
F_54 ( V_11 , V_244 ,
L_35 ,
V_280 -> V_288 , V_165 ) ;
F_117 ( V_282 -> V_289 , V_280 -> V_288 , V_165 ) ;
F_24 ( & V_11 -> V_145 ) ;
}
void F_118 ( struct V_47 * V_11 , struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_11 -> V_2 ;
struct V_259 * V_260 = (struct V_259 * ) V_4 -> V_27 ;
if ( ! F_9 ( ( unsigned long ) V_4 -> V_27 , 4 ) )
F_34 ( V_11 , L_36 ) ;
F_54 ( V_11 , V_244 , L_37 ,
V_260 -> V_162 . V_292 ) ;
switch ( V_260 -> V_162 . V_292 ) {
case V_293 : {
V_2 -> V_294 = V_260 -> V_295 . V_296 ;
V_2 -> V_297 = V_260 -> V_295 . V_298 ;
F_119 ( & V_2 -> V_299 ) ;
break;
}
case V_300 :
F_19 ( & V_2 -> V_8 . V_32 ) ;
F_38 ( & V_2 -> V_45 , V_4 ) ;
F_24 ( & V_2 -> V_8 . V_32 ) ;
F_23 ( & V_2 -> V_43 ) ;
return;
case V_301 : {
struct V_302 V_277 = {
. V_287 = V_260 -> V_303 . V_287 ,
. V_283 = F_72 ( V_260 -> V_303 . V_283 ) ,
} ;
memcpy ( V_277 . V_288 , V_260 -> V_303 . V_288 , sizeof( V_277 . V_288 ) ) ;
F_120 ( V_2 , & V_277 ) ;
break;
}
case V_304 : {
struct V_305 V_277 = {
. V_283 = F_72 ( V_260 -> V_306 . V_283 ) ,
} ;
F_121 ( V_2 , & V_277 ) ;
break;
}
case V_307 : {
struct V_261 V_262 = {} ;
int V_107 = F_7 ( V_260 -> V_308 . V_107 ) ;
V_262 . V_265 =
F_7 ( V_260 -> V_308 . V_309 ) ;
switch ( V_107 ) {
case V_310 :
break;
case V_311 :
V_262 . V_268 = true ;
break;
case V_312 :
V_262 . V_273 = true ;
break;
}
F_19 ( & V_2 -> V_266 ) ;
F_111 ( V_2 , & V_262 ) ;
F_24 ( & V_2 -> V_266 ) ;
break;
}
case V_313 :
F_19 ( & V_2 -> V_266 ) ;
F_38 ( & V_2 -> V_44 , V_4 ) ;
F_24 ( & V_2 -> V_266 ) ;
F_23 ( & V_2 -> V_43 ) ;
return;
case V_314 : {
struct V_47 * V_11 = V_2 -> V_11 ;
struct V_315 * V_277 = & V_260 -> V_316 ;
F_54 ( V_11 , V_244 ,
L_38 ,
F_72 ( V_277 -> V_283 ) ,
! ! ( V_277 -> V_29 & V_317 ) ,
F_41 ( V_277 -> V_29 , V_318 ) ) ;
F_119 ( & V_11 -> V_319 ) ;
break;
}
case V_320 : {
F_35 ( V_11 , V_51 , NULL , L_39 ,
V_4 -> V_27 , V_4 -> V_14 ) ;
F_109 ( V_2 , & V_260 -> V_321 ) ;
break;
}
case V_322 :
break;
case V_323 :
F_122 ( V_11 , V_4 -> V_27 , V_4 -> V_14 ) ;
break;
case V_324 :
F_34 ( V_11 , L_40 ) ;
break;
case V_325 :
F_112 ( V_11 , V_260 ) ;
break;
case V_326 :
F_116 ( V_11 , V_260 ) ;
break;
case V_327 : {
struct V_328 * V_162 =
(struct V_328 * ) V_260 -> V_329 . V_330 ;
F_123 ( V_11 , V_260 -> V_329 . V_330 ,
sizeof( * V_162 ) +
F_72 ( V_162 -> V_42 ) ) ;
break;
}
case V_331 : {
break;
}
default:
F_34 ( V_11 , L_41 ,
V_260 -> V_162 . V_292 ) ;
F_35 ( V_11 , V_51 , NULL , L_39 ,
V_4 -> V_27 , V_4 -> V_14 ) ;
break;
} ;
F_5 ( V_4 ) ;
}
static void V_89 ( unsigned long V_76 )
{
struct V_1 * V_2 = (struct V_1 * ) V_76 ;
struct V_259 * V_260 ;
struct V_3 * V_4 ;
F_19 ( & V_2 -> V_266 ) ;
while ( ( V_4 = F_96 ( & V_2 -> V_44 ) ) ) {
F_110 ( V_2 -> V_11 , V_4 ) ;
F_5 ( V_4 ) ;
}
F_24 ( & V_2 -> V_266 ) ;
F_19 ( & V_2 -> V_8 . V_32 ) ;
while ( ( V_4 = F_96 ( & V_2 -> V_45 ) ) ) {
V_260 = (struct V_259 * ) V_4 -> V_27 ;
F_106 ( V_2 , & V_260 -> V_332 ) ;
F_5 ( V_4 ) ;
}
F_24 ( & V_2 -> V_8 . V_32 ) ;
}
