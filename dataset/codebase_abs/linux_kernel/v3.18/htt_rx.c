static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 =
V_2 -> V_4 +
1000 /
( 8 * V_5 ) * V_6 ;
if ( V_3 < V_7 )
V_3 = V_7 ;
if ( V_3 > V_8 )
V_3 = V_8 ;
V_3 = F_2 ( V_3 ) ;
return V_3 ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 =
V_2 -> V_4 *
1000 /
( 8 * V_5 ) * V_9 ;
if ( V_3 >= V_2 -> V_10 . V_3 )
V_3 = V_2 -> V_10 . V_3 - 1 ;
return V_3 ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_13 * V_14 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_10 . V_16 ; V_15 ++ ) {
V_12 = V_2 -> V_10 . V_17 [ V_15 ] ;
V_14 = F_5 ( V_12 ) ;
F_6 ( V_2 -> V_18 -> V_19 , V_14 -> V_20 ,
V_12 -> V_21 + F_7 ( V_12 ) ,
V_22 ) ;
F_8 ( V_12 ) ;
}
V_2 -> V_10 . V_16 = 0 ;
}
static int F_9 ( struct V_1 * V_2 , int V_23 )
{
struct V_24 * V_25 ;
struct V_11 * V_12 ;
T_1 V_20 ;
int V_26 = 0 , V_27 ;
V_27 = F_10 ( * V_2 -> V_10 . V_28 . V_29 ) ;
while ( V_23 > 0 ) {
V_12 = F_11 ( V_30 + V_31 ) ;
if ( ! V_12 ) {
V_26 = - V_32 ;
goto V_33;
}
if ( ! F_12 ( ( unsigned long ) V_12 -> V_34 , V_31 ) )
F_13 ( V_12 ,
F_14 ( V_12 -> V_34 , V_31 ) -
V_12 -> V_34 ) ;
V_25 = (struct V_24 * ) V_12 -> V_34 ;
V_25 -> V_35 . V_36 = F_15 ( 0 ) ;
V_20 = F_16 ( V_2 -> V_18 -> V_19 , V_12 -> V_34 ,
V_12 -> V_21 + F_7 ( V_12 ) ,
V_22 ) ;
if ( F_17 ( F_18 ( V_2 -> V_18 -> V_19 , V_20 ) ) ) {
F_8 ( V_12 ) ;
V_26 = - V_32 ;
goto V_33;
}
F_5 ( V_12 ) -> V_20 = V_20 ;
V_2 -> V_10 . V_17 [ V_27 ] = V_12 ;
V_2 -> V_10 . V_37 [ V_27 ] = F_15 ( V_20 ) ;
V_2 -> V_10 . V_16 ++ ;
V_23 -- ;
V_27 ++ ;
V_27 &= V_2 -> V_10 . V_38 ;
}
V_33:
* V_2 -> V_10 . V_28 . V_29 = F_15 ( V_27 ) ;
return V_26 ;
}
static int F_19 ( struct V_1 * V_2 , int V_23 )
{
F_20 ( & V_2 -> V_10 . V_39 ) ;
return F_9 ( V_2 , V_23 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
int V_26 , V_40 , V_41 ;
F_22 ( & V_2 -> V_10 . V_39 ) ;
V_40 = V_2 -> V_10 . V_42 - V_2 -> V_10 . V_16 ;
V_41 = F_23 ( V_43 , V_40 ) ;
V_40 -= V_41 ;
V_26 = F_19 ( V_2 , V_41 ) ;
if ( V_26 == - V_32 ) {
F_24 ( & V_2 -> V_10 . V_44 , V_45 +
F_25 ( V_46 ) ) ;
} else if ( V_40 > 0 ) {
F_26 ( & V_2 -> V_47 ) ;
}
F_27 ( & V_2 -> V_10 . V_39 ) ;
}
static void F_28 ( unsigned long V_48 )
{
struct V_1 * V_2 = (struct V_1 * ) V_48 ;
F_21 ( V_2 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_10 . V_3 ; V_15 ++ ) {
V_12 = V_2 -> V_10 . V_17 [ V_15 ] ;
if ( ! V_12 )
continue;
F_6 ( V_2 -> V_18 -> V_19 , F_5 ( V_12 ) -> V_20 ,
V_12 -> V_21 + F_7 ( V_12 ) ,
V_22 ) ;
F_8 ( V_12 ) ;
V_2 -> V_10 . V_17 [ V_15 ] = NULL ;
}
}
void F_30 ( struct V_1 * V_2 )
{
F_31 ( & V_2 -> V_10 . V_44 ) ;
F_32 ( & V_2 -> V_47 ) ;
F_32 ( & V_2 -> V_49 ) ;
F_33 ( & V_2 -> V_50 ) ;
F_33 ( & V_2 -> V_51 ) ;
F_29 ( V_2 ) ;
F_34 ( V_2 -> V_18 -> V_19 ,
( V_2 -> V_10 . V_3 *
sizeof( V_2 -> V_10 . V_37 ) ) ,
V_2 -> V_10 . V_37 ,
V_2 -> V_10 . V_52 ) ;
F_34 ( V_2 -> V_18 -> V_19 ,
sizeof( * V_2 -> V_10 . V_28 . V_29 ) ,
V_2 -> V_10 . V_28 . V_29 ,
V_2 -> V_10 . V_28 . V_20 ) ;
F_35 ( V_2 -> V_10 . V_17 ) ;
}
static inline struct V_11 * F_36 ( struct V_1 * V_2 )
{
struct V_53 * V_18 = V_2 -> V_18 ;
int V_27 ;
struct V_11 * V_54 ;
F_20 ( & V_2 -> V_10 . V_39 ) ;
if ( V_2 -> V_10 . V_16 == 0 ) {
F_37 ( V_18 , L_1 ) ;
return NULL ;
}
V_27 = V_2 -> V_10 . V_55 . V_56 ;
V_54 = V_2 -> V_10 . V_17 [ V_27 ] ;
V_2 -> V_10 . V_17 [ V_27 ] = NULL ;
V_27 ++ ;
V_27 &= V_2 -> V_10 . V_38 ;
V_2 -> V_10 . V_55 . V_56 = V_27 ;
V_2 -> V_10 . V_16 -- ;
return V_54 ;
}
static void F_38 ( struct V_11 * V_12 )
{
struct V_11 * V_57 ;
while ( V_12 ) {
V_57 = V_12 -> V_57 ;
F_8 ( V_12 ) ;
V_12 = V_57 ;
}
}
static int F_39 ( struct V_1 * V_2 ,
T_2 * * V_58 , int * V_59 ,
struct V_11 * * V_60 ,
struct V_11 * * V_61 ,
T_3 * V_35 )
{
struct V_53 * V_18 = V_2 -> V_18 ;
int V_62 , V_63 = 0 ;
struct V_11 * V_54 , * V_57 ;
struct V_24 * V_25 ;
F_20 ( & V_2 -> V_10 . V_39 ) ;
if ( V_2 -> V_64 ) {
F_37 ( V_18 , L_2 ) ;
return - 1 ;
}
V_54 = * V_60 = F_36 ( V_2 ) ;
while ( V_54 ) {
int V_65 , V_66 , V_67 ;
F_6 ( V_2 -> V_18 -> V_19 ,
F_5 ( V_54 ) -> V_20 ,
V_54 -> V_21 + F_7 ( V_54 ) ,
V_22 ) ;
F_40 ( V_18 , V_68 , NULL , L_3 ,
V_54 -> V_34 , V_54 -> V_21 + F_7 ( V_54 ) ) ;
V_25 = (struct V_24 * ) V_54 -> V_34 ;
F_41 ( V_54 , F_42 ( struct V_24 , V_69 ) ) ;
F_13 ( V_54 , F_42 ( struct V_24 , V_69 ) ) ;
if ( ! ( F_10 ( V_25 -> V_35 . V_36 )
& V_70 ) ) {
F_38 ( * V_60 ) ;
* V_60 = NULL ;
V_54 = NULL ;
F_43 ( V_18 , L_4 ) ;
V_2 -> V_64 = true ;
break;
}
* V_35 |= F_10 ( V_25 -> V_35 . V_36 ) &
( V_71 |
V_72 |
V_73 |
V_74 ) ;
if ( * V_59 > 0 ) {
V_25 -> V_58 . V_75 = * * V_58 ;
( * V_58 ) ++ ;
( * V_59 ) -- ;
} else {
V_25 -> V_58 . V_75 = 0 ;
}
V_66 = ! ! ( F_10 ( V_25 -> V_35 . V_36 )
& ( V_76 |
V_77 ) ) ;
V_62 = F_44 ( F_10 ( V_25 -> V_78 . V_75 ) ,
V_79 ) ;
V_67 = V_25 -> V_80 . V_81 ;
if ( V_66 )
V_62 = 0 ;
F_45 ( V_54 , 0 ) ;
F_41 ( V_54 , F_23 ( V_62 , V_82 ) ) ;
V_62 -= V_54 -> V_21 ;
while ( V_67 -- ) {
struct V_11 * V_57 = F_36 ( V_2 ) ;
F_6 ( V_2 -> V_18 -> V_19 ,
F_5 ( V_57 ) -> V_20 ,
V_57 -> V_21 + F_7 ( V_57 ) ,
V_22 ) ;
F_40 ( V_18 , V_68 , NULL ,
L_5 , V_57 -> V_34 ,
V_57 -> V_21 + F_7 ( V_57 ) ) ;
F_45 ( V_57 , 0 ) ;
F_41 ( V_57 , F_23 ( V_62 , V_30 ) ) ;
V_62 -= V_57 -> V_21 ;
V_54 -> V_57 = V_57 ;
V_54 = V_57 ;
V_63 = 1 ;
}
V_65 = F_10 ( V_25 -> V_83 . V_75 ) &
V_84 ;
if ( V_65 ) {
V_54 -> V_57 = NULL ;
break;
}
V_57 = F_36 ( V_2 ) ;
V_54 -> V_57 = V_57 ;
V_54 = V_57 ;
}
* V_61 = V_54 ;
if ( * V_60 == NULL )
V_63 = - 1 ;
return V_63 ;
}
static void F_46 ( unsigned long V_85 )
{
struct V_1 * V_2 = (struct V_1 * ) V_85 ;
F_21 ( V_2 ) ;
}
int F_47 ( struct V_1 * V_2 )
{
struct V_53 * V_18 = V_2 -> V_18 ;
T_1 V_20 ;
void * V_29 ;
T_4 V_3 ;
struct V_86 * V_87 = & V_2 -> V_10 . V_44 ;
V_2 -> V_10 . V_3 = F_1 ( V_2 ) ;
if ( ! F_48 ( V_2 -> V_10 . V_3 ) ) {
F_37 ( V_18 , L_6 ) ;
return - V_88 ;
}
V_2 -> V_10 . V_38 = V_2 -> V_10 . V_3 - 1 ;
V_2 -> V_10 . V_42 = F_3 ( V_2 ) ;
V_2 -> V_10 . V_17 =
F_49 ( V_2 -> V_10 . V_3 * sizeof( struct V_11 * ) ,
V_89 ) ;
if ( ! V_2 -> V_10 . V_17 )
goto V_90;
V_3 = V_2 -> V_10 . V_3 * sizeof( V_2 -> V_10 . V_37 ) ;
V_29 = F_50 ( V_2 -> V_18 -> V_19 , V_3 , & V_20 , V_91 ) ;
if ( ! V_29 )
goto V_92;
V_2 -> V_10 . V_37 = V_29 ;
V_2 -> V_10 . V_52 = V_20 ;
V_29 = F_50 ( V_2 -> V_18 -> V_19 ,
sizeof( * V_2 -> V_10 . V_28 . V_29 ) ,
& V_20 , V_91 ) ;
if ( ! V_29 )
goto V_93;
V_2 -> V_10 . V_28 . V_29 = V_29 ;
V_2 -> V_10 . V_28 . V_20 = V_20 ;
V_2 -> V_10 . V_55 . V_56 = 0 ;
* V_2 -> V_10 . V_28 . V_29 = 0 ;
F_51 ( V_87 , F_28 , ( unsigned long ) V_2 ) ;
F_52 ( & V_2 -> V_10 . V_39 ) ;
V_2 -> V_10 . V_16 = 0 ;
if ( F_9 ( V_2 , V_2 -> V_10 . V_42 ) )
goto V_94;
F_53 ( & V_2 -> V_47 , F_46 ,
( unsigned long ) V_2 ) ;
F_54 ( & V_2 -> V_50 ) ;
F_54 ( & V_2 -> V_51 ) ;
F_53 ( & V_2 -> V_49 , V_95 ,
( unsigned long ) V_2 ) ;
F_55 ( V_18 , V_96 , L_7 ,
V_2 -> V_10 . V_3 , V_2 -> V_10 . V_42 ) ;
return 0 ;
V_94:
F_4 ( V_2 ) ;
F_34 ( V_2 -> V_18 -> V_19 ,
sizeof( * V_2 -> V_10 . V_28 . V_29 ) ,
V_2 -> V_10 . V_28 . V_29 ,
V_2 -> V_10 . V_28 . V_20 ) ;
V_93:
F_34 ( V_2 -> V_18 -> V_19 ,
( V_2 -> V_10 . V_3 *
sizeof( V_2 -> V_10 . V_37 ) ) ,
V_2 -> V_10 . V_37 ,
V_2 -> V_10 . V_52 ) ;
V_92:
F_35 ( V_2 -> V_10 . V_17 ) ;
V_90:
return - V_32 ;
}
static int F_56 ( struct V_53 * V_18 ,
enum V_97 type )
{
switch ( type ) {
case V_98 :
case V_99 :
return 4 ;
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
return 8 ;
case V_105 :
return 0 ;
}
F_37 ( V_18 , L_8 , type ) ;
return 0 ;
}
static int F_57 ( struct V_53 * V_18 ,
enum V_97 type )
{
switch ( type ) {
case V_105 :
case V_98 :
case V_99 :
case V_101 :
case V_103 :
return 0 ;
case V_100 :
case V_102 :
return 4 ;
case V_104 :
return 8 ;
}
F_37 ( V_18 , L_8 , type ) ;
return 0 ;
}
static struct V_106 * F_58 ( struct V_11 * V_12 )
{
struct V_24 * V_107 ;
enum V_108 V_109 ;
V_107 = ( void * ) V_12 -> V_34 - sizeof( * V_107 ) ;
V_109 = F_44 ( F_10 ( V_107 -> V_78 . V_110 ) ,
V_111 ) ;
if ( V_109 == V_112 )
return ( void * ) V_12 -> V_34 ;
return ( void * ) V_12 -> V_34 - V_113 ;
}
static bool F_59 ( struct V_106 * V_114 )
{
T_2 * V_115 ;
if ( F_60 ( V_114 -> V_116 ) ) {
V_115 = F_61 ( V_114 ) ;
if ( V_115 [ 0 ] & 0x80 )
return true ;
}
return false ;
}
static void F_62 ( struct V_53 * V_18 ,
enum V_117 V_118 ,
T_2 V_75 , T_3 V_110 , T_3 V_119 ,
struct V_120 * V_121 )
{
T_2 V_122 , V_123 , V_124 , V_125 , V_126 , V_127 , V_128 ;
T_2 V_129 = 0 ;
if ( ! ( V_75 & V_130 ) )
return;
V_129 = F_44 ( V_110 , V_131 ) ;
switch ( V_129 ) {
case V_132 :
V_122 = V_75 & V_133 ;
V_123 = F_44 ( V_75 , V_134 ) ;
V_124 = 0 ;
if ( V_123 < 0x08 || V_123 > 0x0F )
break;
switch ( V_118 ) {
case V_135 :
if ( V_122 )
V_123 &= ~ F_63 ( 3 ) ;
V_124 = V_136 [ V_123 ] ;
break;
case V_137 :
V_124 = V_136 [ V_123 ] ;
V_124 -= 4 ;
break;
default:
break;
}
V_121 -> V_124 = V_124 ;
break;
case V_138 :
case V_139 :
V_127 = V_110 & 0x1F ;
V_128 = V_127 >> 3 ;
V_125 = ( V_110 >> 7 ) & 1 ;
V_126 = ( V_119 >> 7 ) & 1 ;
V_121 -> V_124 = V_127 ;
V_121 -> V_140 |= V_141 ;
if ( V_126 )
V_121 -> V_140 |= V_142 ;
if ( V_125 )
V_121 -> V_140 |= V_143 ;
break;
case V_144 :
case V_145 :
V_127 = ( V_119 >> 4 ) & 0x0F ;
V_128 = ( ( V_110 >> 10 ) & 0x07 ) + 1 ;
V_125 = V_110 & 3 ;
V_126 = V_119 & 1 ;
V_121 -> V_124 = V_127 ;
V_121 -> V_146 = V_128 ;
if ( V_126 )
V_121 -> V_140 |= V_142 ;
switch ( V_125 ) {
case 0 :
break;
case 1 :
V_121 -> V_140 |= V_143 ;
break;
case 2 :
V_121 -> V_147 |= V_148 ;
}
V_121 -> V_140 |= V_149 ;
break;
default:
break;
}
}
static void F_64 ( struct V_1 * V_2 ,
struct V_120 * V_150 ,
struct V_11 * V_12 ,
enum V_97 V_151 ,
enum V_108 V_109 ,
bool V_152 )
{
struct V_106 * V_114 = (struct V_106 * ) V_12 -> V_34 ;
V_150 -> V_140 &= ~ ( V_153 |
V_154 |
V_155 ) ;
if ( V_151 == V_105 )
return;
if ( V_109 == V_112 && ! V_152 )
return;
V_150 -> V_140 |= V_153 |
V_154 |
V_155 ;
V_114 -> V_116 = F_65 ( F_66 ( V_114 -> V_116 ) &
~ V_156 ) ;
}
static bool F_67 ( struct V_53 * V_18 ,
struct V_120 * V_121 )
{
struct V_157 * V_158 ;
F_22 ( & V_18 -> V_159 ) ;
V_158 = V_18 -> V_160 ;
if ( ! V_158 )
V_158 = V_18 -> V_161 ;
F_27 ( & V_18 -> V_159 ) ;
if ( ! V_158 )
return false ;
V_121 -> V_118 = V_158 -> V_118 ;
V_121 -> V_162 = V_158 -> V_163 ;
return true ;
}
static char * F_68 ( struct V_106 * V_114 , char * V_164 , T_4 V_3 )
{
T_2 * V_115 ;
int V_165 ;
if ( ! F_60 ( V_114 -> V_116 ) )
return L_9 ;
V_115 = F_61 ( V_114 ) ;
V_165 = * V_115 & V_166 ;
if ( V_165 < 8 )
snprintf ( V_164 , V_3 , L_10 , V_165 , V_167 [ V_165 ] ) ;
else
snprintf ( V_164 , V_3 , L_11 , V_165 ) ;
return V_164 ;
}
static void F_69 ( struct V_53 * V_18 ,
struct V_120 * V_150 ,
struct V_11 * V_12 )
{
struct V_120 * V_121 ;
struct V_106 * V_114 = (struct V_106 * ) V_12 -> V_34 ;
char V_165 [ 32 ] ;
V_121 = F_70 ( V_12 ) ;
* V_121 = * V_150 ;
F_55 ( V_18 , V_168 ,
L_12 ,
V_12 ,
V_12 -> V_21 ,
F_71 ( V_114 ) ,
F_68 ( V_114 , V_165 , sizeof( V_165 ) ) ,
F_72 ( F_73 ( V_114 ) ) ?
L_13 : L_14 ,
( F_66 ( V_114 -> V_169 ) & V_170 ) >> 4 ,
V_121 -> V_140 == 0 ? L_15 : L_9 ,
V_121 -> V_140 & V_141 ? L_16 : L_9 ,
V_121 -> V_140 & V_149 ? L_17 : L_9 ,
V_121 -> V_140 & V_143 ? L_18 : L_9 ,
V_121 -> V_147 & V_148 ? L_19 : L_9 ,
V_121 -> V_140 & V_142 ? L_20 : L_9 ,
V_121 -> V_124 ,
V_121 -> V_146 ,
V_121 -> V_162 ,
V_121 -> V_118 , V_121 -> V_140 ,
! ! ( V_121 -> V_140 & V_171 ) ,
! ! ( V_121 -> V_140 & V_172 ) ,
! ! ( V_121 -> V_140 & V_173 ) ) ;
F_40 ( V_18 , V_68 , NULL , L_21 ,
V_12 -> V_34 , V_12 -> V_21 ) ;
F_74 ( V_18 -> V_174 , V_12 ) ;
}
static int F_75 ( struct V_106 * V_114 )
{
return F_76 ( F_77 ( V_114 -> V_116 ) , 4 ) ;
}
static void F_78 ( struct V_1 * V_2 ,
struct V_120 * V_150 ,
struct V_11 * V_175 )
{
struct V_53 * V_18 = V_2 -> V_18 ;
struct V_24 * V_107 ;
struct V_11 * V_12 = V_175 ;
struct V_11 * V_176 ;
enum V_108 V_109 ;
enum V_97 V_151 ;
struct V_106 * V_114 ;
T_2 V_177 [ 64 ] , V_178 [ V_179 ] , V_180 [ V_179 ] , * V_181 ;
unsigned int V_182 ;
V_107 = ( void * ) V_12 -> V_34 - sizeof( * V_107 ) ;
V_151 = F_44 ( F_10 ( V_107 -> V_183 . V_75 ) ,
V_184 ) ;
V_114 = (struct V_106 * ) V_107 -> V_185 ;
V_182 = F_77 ( V_114 -> V_116 ) ;
memcpy ( V_177 , V_114 , V_182 ) ;
V_114 = (struct V_106 * ) V_177 ;
V_176 = V_12 ;
while ( V_12 ) {
void * V_186 ;
int V_21 ;
V_107 = ( void * ) V_12 -> V_34 - sizeof( * V_107 ) ;
V_109 = F_44 ( F_10 ( V_107 -> V_78 . V_110 ) ,
V_111 ) ;
V_186 = ( void * ) V_107 -> V_185 ;
V_12 -> V_187 = F_79 ( V_12 ) ;
if ( V_12 == V_176 ) {
V_21 = F_76 ( F_77 ( V_114 -> V_116 ) , 4 ) ;
V_21 += F_76 ( F_56 ( V_18 ,
V_151 ) , 4 ) ;
V_186 += V_21 ;
}
switch ( V_109 ) {
case V_112 :
F_45 ( V_12 , V_12 -> V_21 - V_188 ) ;
break;
case V_189 :
V_114 = (struct V_106 * ) V_12 -> V_34 ;
V_182 = F_75 ( V_114 ) ;
F_80 ( V_178 , F_73 ( V_114 ) ) ;
F_80 ( V_180 , F_71 ( V_114 ) ) ;
F_13 ( V_12 , V_182 ) ;
V_114 = (struct V_106 * ) V_177 ;
V_182 = F_77 ( V_114 -> V_116 ) ;
memcpy ( F_81 ( V_12 , V_182 ) , V_114 , V_182 ) ;
V_114 = (struct V_106 * ) V_12 -> V_34 ;
V_181 = F_61 ( V_114 ) ;
V_181 [ 0 ] &= ~ V_190 ;
F_80 ( F_73 ( V_114 ) , V_178 ) ;
F_80 ( F_71 ( V_114 ) , V_180 ) ;
break;
case V_191 :
V_21 = 0 ;
V_21 += sizeof( struct V_192 ) ;
V_21 += sizeof( struct V_193 ) ;
F_13 ( V_12 , sizeof( struct V_194 ) ) ;
memcpy ( F_81 ( V_12 , V_21 ) , V_186 , V_21 ) ;
memcpy ( F_81 ( V_12 , V_182 ) , V_114 , V_182 ) ;
break;
case V_195 :
memcpy ( F_81 ( V_12 , V_182 ) , V_114 , V_182 ) ;
break;
}
V_175 = V_12 ;
F_64 ( V_2 , V_150 , V_175 , V_151 , V_109 ,
false ) ;
V_12 = V_12 -> V_57 ;
V_175 -> V_57 = NULL ;
if ( V_12 )
V_150 -> V_140 |= V_173 ;
else
V_150 -> V_140 &= ~ V_173 ;
F_69 ( V_2 -> V_18 , V_150 , V_175 ) ;
}
}
static void F_82 ( struct V_1 * V_2 ,
struct V_120 * V_150 ,
struct V_11 * V_12 )
{
struct V_53 * V_18 = V_2 -> V_18 ;
struct V_24 * V_107 ;
struct V_106 * V_114 ;
enum V_108 V_109 ;
enum V_97 V_151 ;
int V_182 ;
void * V_196 ;
if ( V_12 -> V_57 ) {
F_37 ( V_18 , L_22 ) ;
F_38 ( V_12 -> V_57 ) ;
V_12 -> V_57 = NULL ;
}
V_107 = ( void * ) V_12 -> V_34 - sizeof( * V_107 ) ;
V_109 = F_44 ( F_10 ( V_107 -> V_78 . V_110 ) ,
V_111 ) ;
V_151 = F_44 ( F_10 ( V_107 -> V_183 . V_75 ) ,
V_184 ) ;
V_114 = (struct V_106 * ) V_107 -> V_185 ;
V_182 = F_77 ( V_114 -> V_116 ) ;
V_12 -> V_187 = F_79 ( V_12 ) ;
switch ( V_109 ) {
case V_112 :
F_45 ( V_12 , V_12 -> V_21 - V_188 ) ;
break;
case V_189 :
V_114 = (struct V_106 * ) V_12 -> V_34 ;
V_182 = F_75 ( V_114 ) ;
F_13 ( V_12 , V_182 ) ;
V_114 = (struct V_106 * ) V_107 -> V_185 ;
V_182 = F_77 ( V_114 -> V_116 ) ;
memcpy ( F_81 ( V_12 , V_182 ) , V_114 , V_182 ) ;
break;
case V_191 :
V_196 = V_114 ;
V_196 += F_83 ( V_182 , 4 ) ;
V_196 += F_83 ( F_56 ( V_18 ,
V_151 ) , 4 ) ;
F_13 ( V_12 , sizeof( struct V_194 ) ) ;
memcpy ( F_81 ( V_12 , sizeof( struct V_192 ) ) ,
V_196 , sizeof( struct V_192 ) ) ;
memcpy ( F_81 ( V_12 , V_182 ) , V_114 , V_182 ) ;
break;
case V_195 :
F_13 ( V_12 , sizeof( struct V_193 ) ) ;
memcpy ( F_81 ( V_12 , V_182 ) , V_114 , V_182 ) ;
break;
}
F_64 ( V_2 , V_150 , V_12 , V_151 , V_109 , false ) ;
F_69 ( V_2 -> V_18 , V_150 , V_12 ) ;
}
static int F_79 ( struct V_11 * V_12 )
{
struct V_24 * V_107 ;
T_3 V_36 , V_197 ;
bool V_198 , V_199 ;
bool V_200 , V_201 ;
bool V_202 , V_203 ;
V_107 = ( void * ) V_12 -> V_34 - sizeof( * V_107 ) ;
V_36 = F_10 ( V_107 -> V_35 . V_36 ) ;
V_197 = F_10 ( V_107 -> V_78 . V_110 ) ;
V_198 = ! ! ( V_197 & V_204 ) ;
V_199 = ! ! ( V_197 & V_205 ) ;
V_200 = ! ! ( V_197 & V_206 ) ;
V_201 = ! ! ( V_197 & V_207 ) ;
V_202 = ! ( V_36 & V_208 ) ;
V_203 = ! ( V_36 & V_209 ) ;
if ( ! V_198 && ! V_199 )
return V_210 ;
if ( ! V_200 && ! V_201 )
return V_210 ;
if ( ! V_202 )
return V_210 ;
if ( ! V_203 )
return V_210 ;
return V_211 ;
}
static int F_84 ( struct V_11 * V_212 )
{
struct V_11 * V_57 = V_212 -> V_57 ;
struct V_11 * V_213 = V_57 ;
int V_214 ;
int V_215 = 0 ;
V_212 -> V_57 = NULL ;
while ( V_57 ) {
V_215 += V_57 -> V_21 ;
V_57 = V_57 -> V_57 ;
}
V_214 = V_215 - F_7 ( V_212 ) ;
if ( ( V_214 > 0 ) &&
( F_85 ( V_212 , 0 , V_214 , V_216 ) < 0 ) ) {
V_212 -> V_57 = V_213 ;
return - 1 ;
}
V_57 = V_213 ;
while ( V_57 ) {
F_86 ( V_57 , F_41 ( V_212 , V_57 -> V_21 ) ,
V_57 -> V_21 ) ;
V_57 = V_57 -> V_57 ;
}
F_38 ( V_213 ) ;
return 0 ;
}
static bool F_87 ( struct V_1 * V_2 ,
struct V_11 * V_217 ,
enum V_218 V_121 ,
bool V_219 ,
T_3 V_35 )
{
struct V_53 * V_18 = V_2 -> V_18 ;
if ( V_217 -> V_21 == 0 ) {
F_55 ( V_18 , V_220 ,
L_23 ) ;
return false ;
}
if ( V_35 & V_72 ) {
F_55 ( V_18 , V_220 ,
L_24 ) ;
return false ;
}
if ( ! V_219 ) {
F_37 ( V_18 , L_25 ) ;
return false ;
}
if ( V_121 == V_221 ||
V_35 & V_74 ) {
F_55 ( V_18 , V_220 , L_26 ) ;
return false ;
}
if ( V_121 != V_222 &&
V_121 != V_223 &&
V_121 != V_224 &&
! V_2 -> V_18 -> V_225 ) {
F_55 ( V_18 , V_220 ,
L_27 ,
V_121 ) ;
return false ;
}
if ( F_88 ( V_226 , & V_2 -> V_18 -> V_227 ) ) {
F_55 ( V_18 , V_220 ,
L_28 ) ;
return false ;
}
return true ;
}
static void F_89 ( struct V_1 * V_2 ,
struct V_228 * V_229 )
{
struct V_53 * V_18 = V_2 -> V_18 ;
struct V_120 * V_150 = & V_2 -> V_150 ;
struct V_230 * V_231 ;
struct V_24 * V_107 ;
enum V_218 V_121 ;
struct V_106 * V_114 ;
int V_232 ;
T_3 V_35 ;
int V_59 ;
T_2 * V_58 ;
bool V_219 ;
int V_15 , V_233 ;
int V_26 ;
F_20 ( & V_2 -> V_10 . V_39 ) ;
V_59 = F_66 ( V_229 -> V_234 . V_235 ) ;
V_58 = ( T_2 * ) & V_229 -> V_58 ;
V_232 = F_44 ( F_10 ( V_229 -> V_114 . V_110 ) ,
V_236 ) ;
V_231 = F_90 ( V_229 ) ;
if ( V_229 -> V_237 . V_75 & V_130 ) {
memset ( V_150 , 0 , sizeof( * V_150 ) ) ;
V_150 -> signal = V_238 +
V_229 -> V_237 . V_239 ;
}
if ( V_229 -> V_237 . V_75 & V_240 ) {
V_150 -> V_241 = F_10 ( V_229 -> V_237 . V_242 ) & 0xffffffff ;
V_150 -> V_140 |= V_243 ;
}
V_219 = F_67 ( V_2 -> V_18 , V_150 ) ;
if ( V_219 ) {
F_62 ( V_2 -> V_18 , V_150 -> V_118 ,
V_229 -> V_237 . V_75 ,
F_10 ( V_229 -> V_237 . V_110 ) ,
F_10 ( V_229 -> V_237 . V_119 ) ,
V_150 ) ;
}
F_40 ( V_18 , V_68 , NULL , L_29 ,
V_229 , sizeof( * V_229 ) +
( sizeof( struct V_230 ) *
V_232 ) ) ;
for ( V_15 = 0 ; V_15 < V_232 ; V_15 ++ ) {
V_121 = V_231 [ V_15 ] . V_244 ;
for ( V_233 = 0 ; V_233 < V_231 [ V_15 ] . V_245 ; V_233 ++ ) {
struct V_11 * V_212 , * V_246 ;
V_35 = 0 ;
V_212 = NULL ;
V_246 = NULL ;
V_26 = F_39 ( V_2 ,
& V_58 ,
& V_59 ,
& V_212 ,
& V_246 ,
& V_35 ) ;
if ( V_26 < 0 ) {
F_37 ( V_18 , L_30 ,
V_26 ) ;
F_38 ( V_212 ) ;
continue;
}
V_107 = F_91 ( ( void * ) V_212 -> V_34 ,
struct V_24 ,
V_69 ) ;
if ( ! F_87 ( V_2 , V_212 ,
V_121 ,
V_219 ,
V_35 ) ) {
F_38 ( V_212 ) ;
continue;
}
if ( V_26 > 0 &&
F_84 ( V_212 ) < 0 ) {
F_38 ( V_212 ) ;
continue;
}
if ( V_35 & V_73 )
V_150 -> V_140 |= V_171 ;
else
V_150 -> V_140 &= ~ V_171 ;
if ( V_35 & V_71 )
V_150 -> V_140 |= V_172 ;
else
V_150 -> V_140 &= ~ V_172 ;
V_114 = F_58 ( V_212 ) ;
if ( F_59 ( V_114 ) )
F_78 ( V_2 , V_150 , V_212 ) ;
else
F_82 ( V_2 , V_150 , V_212 ) ;
}
}
F_26 ( & V_2 -> V_47 ) ;
}
static void F_92 ( struct V_1 * V_2 ,
struct V_247 * V_248 )
{
struct V_53 * V_18 = V_2 -> V_18 ;
struct V_11 * V_212 , * V_246 ;
enum V_97 V_151 ;
struct V_24 * V_107 ;
enum V_108 V_109 ;
struct V_120 * V_150 = & V_2 -> V_150 ;
struct V_106 * V_114 ;
int V_26 ;
bool V_249 ;
bool V_250 ;
T_2 * V_58 ;
int V_59 , V_251 , V_252 ;
int V_253 ;
T_3 V_35 = 0 ;
V_59 = F_66 ( V_248 -> V_235 ) ;
V_58 = ( T_2 * ) V_248 -> V_254 ;
V_212 = NULL ;
V_246 = NULL ;
F_22 ( & V_2 -> V_10 . V_39 ) ;
V_26 = F_39 ( V_2 , & V_58 , & V_59 ,
& V_212 , & V_246 ,
& V_35 ) ;
F_27 ( & V_2 -> V_10 . V_39 ) ;
F_55 ( V_18 , V_68 , L_31 ) ;
if ( V_26 ) {
F_37 ( V_18 , L_32 ,
V_26 ) ;
F_38 ( V_212 ) ;
return;
}
V_150 -> V_140 |= V_255 ;
V_114 = (struct V_106 * ) V_212 -> V_34 ;
V_107 = ( void * ) V_212 -> V_34 - sizeof( * V_107 ) ;
V_249 = ! ! ( V_35 & V_71 ) ;
V_250 = ! ! ( V_35 & V_72 ) ;
V_109 = F_44 ( F_10 ( V_107 -> V_78 . V_110 ) ,
V_111 ) ;
if ( V_109 != V_112 ) {
F_37 ( V_18 , L_33 ) ;
F_8 ( V_212 ) ;
goto V_256;
}
V_151 = F_44 ( F_10 ( V_107 -> V_183 . V_75 ) ,
V_184 ) ;
F_64 ( V_2 , V_150 , V_212 , V_151 , V_109 ,
true ) ;
V_212 -> V_187 = F_79 ( V_212 ) ;
if ( V_249 )
F_37 ( V_18 , L_34 ) ;
if ( V_250 ) {
F_37 ( V_18 , L_35 ) ;
F_8 ( V_212 ) ;
goto V_256;
}
if ( V_151 != V_105 ) {
V_251 = F_77 ( V_114 -> V_116 ) ;
V_252 = F_56 ( V_18 , V_151 ) ;
memmove ( ( void * ) V_212 -> V_34 + V_252 ,
( void * ) V_212 -> V_34 ,
V_251 ) ;
F_13 ( V_212 , V_252 ) ;
V_114 = (struct V_106 * ) V_212 -> V_34 ;
}
V_253 = 4 ;
V_253 += F_57 ( V_18 , V_151 ) ;
if ( ! F_93 ( V_114 -> V_116 ) &&
V_151 == V_102 )
V_253 += 8 ;
if ( V_253 > V_212 -> V_21 ) {
F_37 ( V_18 , L_36 ) ;
F_8 ( V_212 ) ;
goto V_256;
}
F_45 ( V_212 , V_212 -> V_21 - V_253 ) ;
F_40 ( V_18 , V_68 , NULL , L_37 ,
V_212 -> V_34 , V_212 -> V_21 ) ;
F_69 ( V_2 -> V_18 , V_150 , V_212 ) ;
V_256:
if ( V_59 > 0 ) {
F_55 ( V_18 , V_220 ,
L_38 ,
V_59 ) ;
}
}
static void F_94 ( struct V_53 * V_18 ,
struct V_11 * V_12 )
{
struct V_1 * V_2 = & V_18 -> V_2 ;
struct V_257 * V_258 = (struct V_257 * ) V_12 -> V_34 ;
struct V_259 V_260 = {} ;
int V_121 = F_44 ( V_258 -> V_261 . V_36 , V_262 ) ;
T_5 V_263 ;
int V_15 ;
F_20 ( & V_2 -> V_264 ) ;
switch ( V_121 ) {
case V_265 :
V_260 . V_266 = true ;
break;
case V_267 :
break;
case V_268 :
case V_269 :
case V_270 :
V_260 . V_271 = true ;
break;
default:
F_37 ( V_18 , L_39 , V_121 ) ;
V_260 . V_271 = true ;
break;
}
F_55 ( V_18 , V_220 , L_40 ,
V_258 -> V_261 . V_272 ) ;
for ( V_15 = 0 ; V_15 < V_258 -> V_261 . V_272 ; V_15 ++ ) {
V_263 = V_258 -> V_261 . V_273 [ V_15 ] ;
V_260 . V_263 = F_66 ( V_263 ) ;
F_95 ( V_2 , & V_260 ) ;
}
}
static void F_96 ( struct V_53 * V_18 , struct V_257 * V_258 )
{
struct V_274 * V_275 = & V_258 -> V_276 ;
struct V_277 * V_278 ;
struct V_279 * V_280 ;
T_6 V_75 , V_165 , V_281 ;
V_75 = F_66 ( V_275 -> V_75 ) ;
V_165 = F_44 ( V_75 , V_282 ) ;
V_281 = F_44 ( V_75 , V_283 ) ;
F_55 ( V_18 , V_220 ,
L_41 ,
V_165 , V_281 , V_275 -> V_284 ) ;
F_22 ( & V_18 -> V_159 ) ;
V_278 = F_97 ( V_18 , V_281 ) ;
if ( ! V_278 ) {
F_37 ( V_18 , L_42 ,
V_281 ) ;
F_27 ( & V_18 -> V_159 ) ;
return;
}
V_280 = F_98 ( V_18 , V_278 -> V_285 ) ;
if ( ! V_280 ) {
F_37 ( V_18 , L_43 ,
V_278 -> V_285 ) ;
F_27 ( & V_18 -> V_159 ) ;
return;
}
F_55 ( V_18 , V_220 ,
L_44 ,
V_278 -> V_286 , V_165 , V_275 -> V_284 ) ;
F_99 ( V_280 -> V_287 , V_278 -> V_286 , V_165 ) ;
F_27 ( & V_18 -> V_159 ) ;
}
static void F_100 ( struct V_53 * V_18 , struct V_257 * V_258 )
{
struct V_288 * V_275 = & V_258 -> V_289 ;
struct V_277 * V_278 ;
struct V_279 * V_280 ;
T_6 V_75 , V_165 , V_281 ;
V_75 = F_66 ( V_275 -> V_75 ) ;
V_165 = F_44 ( V_75 , V_282 ) ;
V_281 = F_44 ( V_75 , V_283 ) ;
F_55 ( V_18 , V_220 ,
L_45 ,
V_165 , V_281 ) ;
F_22 ( & V_18 -> V_159 ) ;
V_278 = F_97 ( V_18 , V_281 ) ;
if ( ! V_278 ) {
F_37 ( V_18 , L_42 ,
V_281 ) ;
F_27 ( & V_18 -> V_159 ) ;
return;
}
V_280 = F_98 ( V_18 , V_278 -> V_285 ) ;
if ( ! V_280 ) {
F_37 ( V_18 , L_43 ,
V_278 -> V_285 ) ;
F_27 ( & V_18 -> V_159 ) ;
return;
}
F_55 ( V_18 , V_220 ,
L_46 ,
V_278 -> V_286 , V_165 ) ;
F_101 ( V_280 -> V_287 , V_278 -> V_286 , V_165 ) ;
F_27 ( & V_18 -> V_159 ) ;
}
void F_102 ( struct V_53 * V_18 , struct V_11 * V_12 )
{
struct V_1 * V_2 = & V_18 -> V_2 ;
struct V_257 * V_258 = (struct V_257 * ) V_12 -> V_34 ;
if ( ! F_12 ( ( unsigned long ) V_12 -> V_34 , 4 ) )
F_37 ( V_18 , L_47 ) ;
F_55 ( V_18 , V_220 , L_48 ,
V_258 -> V_114 . V_290 ) ;
switch ( V_258 -> V_114 . V_290 ) {
case V_291 : {
V_2 -> V_292 = V_258 -> V_293 . V_294 ;
V_2 -> V_295 = V_258 -> V_293 . V_296 ;
F_103 ( & V_2 -> V_297 ) ;
break;
}
case V_298 :
F_22 ( & V_2 -> V_10 . V_39 ) ;
F_104 ( & V_2 -> V_51 , V_12 ) ;
F_27 ( & V_2 -> V_10 . V_39 ) ;
F_26 ( & V_2 -> V_49 ) ;
return;
case V_299 : {
struct V_300 V_275 = {
. V_285 = V_258 -> V_301 . V_285 ,
. V_281 = F_66 ( V_258 -> V_301 . V_281 ) ,
} ;
memcpy ( V_275 . V_286 , V_258 -> V_301 . V_286 , sizeof( V_275 . V_286 ) ) ;
F_105 ( V_2 , & V_275 ) ;
break;
}
case V_302 : {
struct V_303 V_275 = {
. V_281 = F_66 ( V_258 -> V_304 . V_281 ) ,
} ;
F_106 ( V_2 , & V_275 ) ;
break;
}
case V_305 : {
struct V_259 V_260 = {} ;
int V_121 = F_10 ( V_258 -> V_306 . V_121 ) ;
V_260 . V_263 =
F_10 ( V_258 -> V_306 . V_307 ) ;
switch ( V_121 ) {
case V_308 :
break;
case V_309 :
V_260 . V_266 = true ;
break;
case V_310 :
V_260 . V_271 = true ;
break;
}
F_22 ( & V_2 -> V_264 ) ;
F_95 ( V_2 , & V_260 ) ;
F_27 ( & V_2 -> V_264 ) ;
break;
}
case V_311 :
F_22 ( & V_2 -> V_264 ) ;
F_104 ( & V_2 -> V_50 , V_12 ) ;
F_27 ( & V_2 -> V_264 ) ;
F_26 ( & V_2 -> V_49 ) ;
return;
case V_312 : {
struct V_53 * V_18 = V_2 -> V_18 ;
struct V_313 * V_275 = & V_258 -> V_314 ;
F_55 ( V_18 , V_220 ,
L_49 ,
F_66 ( V_275 -> V_281 ) ,
! ! ( V_275 -> V_36 & V_315 ) ,
F_44 ( V_275 -> V_36 , V_316 ) ) ;
F_103 ( & V_18 -> V_317 ) ;
break;
}
case V_318 : {
F_40 ( V_18 , V_68 , NULL , L_50 ,
V_12 -> V_34 , V_12 -> V_21 ) ;
F_92 ( V_2 , & V_258 -> V_319 ) ;
break;
}
case V_320 :
break;
case V_321 :
F_107 ( V_18 , V_12 -> V_34 , V_12 -> V_21 ) ;
break;
case V_322 :
F_37 ( V_18 , L_51 ) ;
break;
case V_323 :
F_96 ( V_18 , V_258 ) ;
break;
case V_324 :
F_100 ( V_18 , V_258 ) ;
break;
case V_325 : {
break;
}
default:
F_55 ( V_18 , V_220 , L_52 ,
V_258 -> V_114 . V_290 ) ;
F_40 ( V_18 , V_68 , NULL , L_50 ,
V_12 -> V_34 , V_12 -> V_21 ) ;
break;
} ;
F_8 ( V_12 ) ;
}
static void V_95 ( unsigned long V_85 )
{
struct V_1 * V_2 = (struct V_1 * ) V_85 ;
struct V_257 * V_258 ;
struct V_11 * V_12 ;
F_22 ( & V_2 -> V_264 ) ;
while ( ( V_12 = F_108 ( & V_2 -> V_50 ) ) ) {
F_94 ( V_2 -> V_18 , V_12 ) ;
F_8 ( V_12 ) ;
}
F_27 ( & V_2 -> V_264 ) ;
F_22 ( & V_2 -> V_10 . V_39 ) ;
while ( ( V_12 = F_108 ( & V_2 -> V_51 ) ) ) {
V_258 = (struct V_257 * ) V_12 -> V_34 ;
F_89 ( V_2 , & V_258 -> V_326 ) ;
F_8 ( V_12 ) ;
}
F_27 ( & V_2 -> V_10 . V_39 ) ;
}
