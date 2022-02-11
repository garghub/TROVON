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
V_27 = F_10 ( * ( V_2 -> V_10 . V_28 . V_29 ) ) ;
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
* ( V_2 -> V_10 . V_28 . V_29 ) = F_15 ( V_27 ) ;
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
int V_27 ;
struct V_11 * V_53 ;
F_20 ( & V_2 -> V_10 . V_39 ) ;
if ( V_2 -> V_10 . V_16 == 0 ) {
F_37 ( L_1 ) ;
return NULL ;
}
V_27 = V_2 -> V_10 . V_54 . V_55 ;
V_53 = V_2 -> V_10 . V_17 [ V_27 ] ;
V_2 -> V_10 . V_17 [ V_27 ] = NULL ;
V_27 ++ ;
V_27 &= V_2 -> V_10 . V_38 ;
V_2 -> V_10 . V_54 . V_55 = V_27 ;
V_2 -> V_10 . V_16 -- ;
return V_53 ;
}
static void F_38 ( struct V_11 * V_12 )
{
struct V_11 * V_56 ;
while ( V_12 ) {
V_56 = V_12 -> V_56 ;
F_8 ( V_12 ) ;
V_12 = V_56 ;
}
}
static int F_39 ( struct V_1 * V_2 ,
T_2 * * V_57 , int * V_58 ,
struct V_11 * * V_59 ,
struct V_11 * * V_60 ,
T_3 * V_35 )
{
int V_61 , V_62 = 0 ;
struct V_11 * V_53 ;
struct V_24 * V_25 ;
F_20 ( & V_2 -> V_10 . V_39 ) ;
if ( V_2 -> V_63 ) {
F_37 ( L_2 ) ;
return - 1 ;
}
V_53 = * V_59 = F_36 ( V_2 ) ;
while ( V_53 ) {
int V_64 , V_65 , V_66 ;
F_6 ( V_2 -> V_18 -> V_19 ,
F_5 ( V_53 ) -> V_20 ,
V_53 -> V_21 + F_7 ( V_53 ) ,
V_22 ) ;
F_40 ( V_67 , NULL , L_3 ,
V_53 -> V_34 , V_53 -> V_21 + F_7 ( V_53 ) ) ;
V_25 = (struct V_24 * ) V_53 -> V_34 ;
F_41 ( V_53 , F_42 ( struct V_24 , V_68 ) ) ;
F_13 ( V_53 , F_42 ( struct V_24 , V_68 ) ) ;
if ( ! ( F_10 ( V_25 -> V_35 . V_36 )
& V_69 ) ) {
F_38 ( * V_59 ) ;
* V_59 = NULL ;
V_53 = NULL ;
F_43 ( L_4 ) ;
V_2 -> V_63 = true ;
break;
}
* V_35 |= F_10 ( V_25 -> V_35 . V_36 ) &
( V_70 |
V_71 |
V_72 |
V_73 ) ;
if ( * V_58 > 0 ) {
V_25 -> V_57 . V_74 = * * V_57 ;
( * V_57 ) ++ ;
( * V_58 ) -- ;
} else {
V_25 -> V_57 . V_74 = 0 ;
}
V_65 = ! ! ( F_10 ( V_25 -> V_35 . V_36 )
& ( V_75 |
V_76 ) ) ;
V_61 = F_44 ( F_10 ( V_25 -> V_77 . V_74 ) ,
V_78 ) ;
V_66 = V_25 -> V_79 . V_80 ;
if ( V_65 )
V_61 = 0 ;
F_45 ( V_53 , 0 ) ;
F_41 ( V_53 , F_23 ( V_61 , V_81 ) ) ;
V_61 -= V_53 -> V_21 ;
while ( V_66 -- ) {
struct V_11 * V_56 = F_36 ( V_2 ) ;
F_6 ( V_2 -> V_18 -> V_19 ,
F_5 ( V_56 ) -> V_20 ,
V_56 -> V_21 + F_7 ( V_56 ) ,
V_22 ) ;
F_40 ( V_67 , NULL ,
L_5 , V_56 -> V_34 ,
V_56 -> V_21 + F_7 ( V_56 ) ) ;
F_45 ( V_56 , 0 ) ;
F_41 ( V_56 , F_23 ( V_61 , V_30 ) ) ;
V_61 -= V_56 -> V_21 ;
V_53 -> V_56 = V_56 ;
V_53 = V_56 ;
V_62 = 1 ;
}
V_64 = F_10 ( V_25 -> V_82 . V_74 ) &
V_83 ;
if ( V_64 ) {
V_53 -> V_56 = NULL ;
break;
} else {
struct V_11 * V_56 = F_36 ( V_2 ) ;
V_53 -> V_56 = V_56 ;
V_53 = V_56 ;
}
}
* V_60 = V_53 ;
if ( * V_59 == NULL )
V_62 = - 1 ;
return V_62 ;
}
static void F_46 ( unsigned long V_84 )
{
struct V_1 * V_2 = (struct V_1 * ) V_84 ;
F_21 ( V_2 ) ;
}
int F_47 ( struct V_1 * V_2 )
{
T_1 V_20 ;
void * V_29 ;
struct V_85 * V_86 = & V_2 -> V_10 . V_44 ;
V_2 -> V_10 . V_3 = F_1 ( V_2 ) ;
if ( ! F_48 ( V_2 -> V_10 . V_3 ) ) {
F_37 ( L_6 ) ;
return - V_87 ;
}
V_2 -> V_10 . V_38 = V_2 -> V_10 . V_3 - 1 ;
V_2 -> V_10 . V_42 = F_3 ( V_2 ) ;
V_2 -> V_10 . V_17 =
F_49 ( V_2 -> V_10 . V_3 * sizeof( struct V_11 * ) ,
V_88 ) ;
if ( ! V_2 -> V_10 . V_17 )
goto V_89;
V_29 = F_50 ( V_2 -> V_18 -> V_19 ,
( V_2 -> V_10 . V_3 * sizeof( V_2 -> V_10 . V_37 ) ) ,
& V_20 , V_90 ) ;
if ( ! V_29 )
goto V_91;
V_2 -> V_10 . V_37 = V_29 ;
V_2 -> V_10 . V_52 = V_20 ;
V_29 = F_50 ( V_2 -> V_18 -> V_19 ,
sizeof( * V_2 -> V_10 . V_28 . V_29 ) ,
& V_20 , V_90 ) ;
if ( ! V_29 )
goto V_92;
V_2 -> V_10 . V_28 . V_29 = V_29 ;
V_2 -> V_10 . V_28 . V_20 = V_20 ;
V_2 -> V_10 . V_54 . V_55 = 0 ;
* V_2 -> V_10 . V_28 . V_29 = 0 ;
F_51 ( V_86 , F_28 , ( unsigned long ) V_2 ) ;
F_52 ( & V_2 -> V_10 . V_39 ) ;
V_2 -> V_10 . V_16 = 0 ;
if ( F_9 ( V_2 , V_2 -> V_10 . V_42 ) )
goto V_93;
F_53 ( & V_2 -> V_47 , F_46 ,
( unsigned long ) V_2 ) ;
F_54 ( & V_2 -> V_50 ) ;
F_54 ( & V_2 -> V_51 ) ;
F_53 ( & V_2 -> V_49 , V_94 ,
( unsigned long ) V_2 ) ;
F_55 ( V_95 , L_7 ,
V_2 -> V_10 . V_3 , V_2 -> V_10 . V_42 ) ;
return 0 ;
V_93:
F_4 ( V_2 ) ;
F_34 ( V_2 -> V_18 -> V_19 ,
sizeof( * V_2 -> V_10 . V_28 . V_29 ) ,
V_2 -> V_10 . V_28 . V_29 ,
V_2 -> V_10 . V_28 . V_20 ) ;
V_92:
F_34 ( V_2 -> V_18 -> V_19 ,
( V_2 -> V_10 . V_3 *
sizeof( V_2 -> V_10 . V_37 ) ) ,
V_2 -> V_10 . V_37 ,
V_2 -> V_10 . V_52 ) ;
V_91:
F_35 ( V_2 -> V_10 . V_17 ) ;
V_89:
return - V_32 ;
}
static int F_56 ( enum V_96 type )
{
switch ( type ) {
case V_97 :
case V_98 :
return 4 ;
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
return 8 ;
case V_104 :
return 0 ;
}
F_37 ( L_8 , type ) ;
return 0 ;
}
static int F_57 ( enum V_96 type )
{
switch ( type ) {
case V_104 :
case V_97 :
case V_98 :
case V_100 :
case V_102 :
return 0 ;
case V_99 :
case V_101 :
return 4 ;
case V_103 :
return 8 ;
}
F_37 ( L_8 , type ) ;
return 0 ;
}
static struct V_105 * F_58 ( struct V_11 * V_12 )
{
struct V_24 * V_106 ;
enum V_107 V_108 ;
V_106 = ( void * ) V_12 -> V_34 - sizeof( * V_106 ) ;
V_108 = F_44 ( F_10 ( V_106 -> V_77 . V_109 ) ,
V_110 ) ;
if ( V_108 == V_111 )
return ( void * ) V_12 -> V_34 ;
else
return ( void * ) V_12 -> V_34 - V_112 ;
}
static bool F_59 ( struct V_105 * V_113 )
{
if ( F_60 ( V_113 -> V_114 ) ) {
T_2 * V_115 = F_61 ( V_113 ) ;
if ( V_115 [ 0 ] & 0x80 )
return true ;
}
return false ;
}
static void F_62 ( struct V_116 * V_18 ,
enum V_117 V_118 ,
T_2 V_74 , T_3 V_109 , T_3 V_119 ,
struct V_120 * V_121 )
{
T_2 V_122 , V_123 , V_124 , V_125 , V_126 , V_127 , V_128 ;
T_2 V_129 = 0 ;
if ( ! ( V_74 & V_130 ) )
return;
V_129 = F_44 ( V_109 , V_131 ) ;
switch ( V_129 ) {
case V_132 :
V_122 = V_74 & V_133 ;
V_123 = F_44 ( V_74 , V_134 ) ;
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
V_127 = V_109 & 0x1F ;
V_128 = V_127 >> 3 ;
V_125 = ( V_109 >> 7 ) & 1 ;
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
V_128 = ( ( V_109 >> 10 ) & 0x07 ) + 1 ;
V_125 = V_109 & 3 ;
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
enum V_96 V_151 ,
enum V_107 V_108 ,
bool V_152 )
{
struct V_105 * V_113 = (struct V_105 * ) V_12 -> V_34 ;
V_150 -> V_140 &= ~ ( V_153 |
V_154 |
V_155 ) ;
if ( V_151 == V_104 )
return;
if ( V_108 == V_111 && ! V_152 )
return;
V_150 -> V_140 |= V_153 |
V_154 |
V_155 ;
V_113 -> V_114 = F_65 ( F_66 ( V_113 -> V_114 ) &
~ V_156 ) ;
}
static bool F_67 ( struct V_116 * V_18 ,
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
static void F_68 ( struct V_116 * V_18 ,
struct V_120 * V_150 ,
struct V_11 * V_12 )
{
struct V_120 * V_121 ;
V_121 = F_69 ( V_12 ) ;
* V_121 = * V_150 ;
F_55 ( V_164 ,
L_9 ,
V_12 ,
V_12 -> V_21 ,
V_121 -> V_140 == 0 ? L_10 : L_11 ,
V_121 -> V_140 & V_141 ? L_12 : L_11 ,
V_121 -> V_140 & V_149 ? L_13 : L_11 ,
V_121 -> V_140 & V_143 ? L_14 : L_11 ,
V_121 -> V_147 & V_148 ? L_15 : L_11 ,
V_121 -> V_140 & V_142 ? L_16 : L_11 ,
V_121 -> V_124 ,
V_121 -> V_146 ,
V_121 -> V_162 ,
V_121 -> V_118 , V_121 -> V_140 ,
! ! ( V_121 -> V_140 & V_165 ) ,
! ! ( V_121 -> V_140 & V_166 ) ) ;
F_40 ( V_67 , NULL , L_17 ,
V_12 -> V_34 , V_12 -> V_21 ) ;
F_70 ( V_18 -> V_167 , V_12 ) ;
}
static int F_71 ( struct V_105 * V_113 )
{
return F_72 ( F_73 ( V_113 -> V_114 ) , 4 ) ;
}
static void F_74 ( struct V_1 * V_2 ,
struct V_120 * V_150 ,
struct V_11 * V_168 )
{
struct V_24 * V_106 ;
struct V_11 * V_12 = V_168 ;
struct V_11 * V_169 ;
enum V_107 V_108 ;
enum V_96 V_151 ;
struct V_105 * V_113 ;
T_2 V_170 [ 64 ] , V_171 [ V_172 ] , * V_173 ;
unsigned int V_174 ;
V_106 = ( void * ) V_12 -> V_34 - sizeof( * V_106 ) ;
V_151 = F_44 ( F_10 ( V_106 -> V_175 . V_74 ) ,
V_176 ) ;
V_113 = (struct V_105 * ) V_106 -> V_177 ;
V_174 = F_73 ( V_113 -> V_114 ) ;
memcpy ( V_170 , V_113 , V_174 ) ;
V_113 = (struct V_105 * ) V_170 ;
V_169 = V_12 ;
while ( V_12 ) {
void * V_178 ;
int V_21 ;
V_106 = ( void * ) V_12 -> V_34 - sizeof( * V_106 ) ;
V_108 = F_44 ( F_10 ( V_106 -> V_77 . V_109 ) ,
V_110 ) ;
V_178 = ( void * ) V_106 -> V_177 ;
V_12 -> V_179 = F_75 ( V_12 ) ;
if ( V_12 == V_169 ) {
V_21 = F_72 ( F_73 ( V_113 -> V_114 ) , 4 ) ;
V_21 += F_72 ( F_56 ( V_151 ) ,
4 ) ;
V_178 += V_21 ;
}
switch ( V_108 ) {
case V_111 :
F_45 ( V_12 , V_12 -> V_21 - V_180 ) ;
break;
case V_181 :
V_113 = (struct V_105 * ) V_12 -> V_34 ;
V_174 = F_71 ( V_113 ) ;
memcpy ( V_171 , F_76 ( V_113 ) , V_172 ) ;
F_13 ( V_12 , V_174 ) ;
V_113 = (struct V_105 * ) V_170 ;
V_174 = F_73 ( V_113 -> V_114 ) ;
memcpy ( F_77 ( V_12 , V_174 ) , V_113 , V_174 ) ;
V_113 = (struct V_105 * ) V_12 -> V_34 ;
V_173 = F_61 ( V_113 ) ;
V_173 [ 0 ] &= ~ V_182 ;
memcpy ( F_76 ( V_113 ) , V_171 , V_172 ) ;
break;
case V_183 :
V_21 = 0 ;
V_21 += sizeof( struct V_184 ) ;
V_21 += sizeof( struct V_185 ) ;
F_13 ( V_12 , sizeof( struct V_186 ) ) ;
memcpy ( F_77 ( V_12 , V_21 ) , V_178 , V_21 ) ;
memcpy ( F_77 ( V_12 , V_174 ) , V_113 , V_174 ) ;
break;
case V_187 :
memcpy ( F_77 ( V_12 , V_174 ) , V_113 , V_174 ) ;
break;
}
V_168 = V_12 ;
F_64 ( V_2 , V_150 , V_168 , V_151 , V_108 ,
false ) ;
V_12 = V_12 -> V_56 ;
V_168 -> V_56 = NULL ;
if ( V_12 )
V_150 -> V_140 |= V_188 ;
else
V_150 -> V_140 &= ~ V_188 ;
F_68 ( V_2 -> V_18 , V_150 , V_168 ) ;
}
}
static void F_78 ( struct V_1 * V_2 ,
struct V_120 * V_150 ,
struct V_11 * V_12 )
{
struct V_24 * V_106 ;
struct V_105 * V_113 ;
enum V_107 V_108 ;
enum V_96 V_151 ;
int V_174 ;
void * V_189 ;
if ( V_12 -> V_56 ) {
F_37 ( L_18 ) ;
F_38 ( V_12 -> V_56 ) ;
V_12 -> V_56 = NULL ;
}
V_106 = ( void * ) V_12 -> V_34 - sizeof( * V_106 ) ;
V_108 = F_44 ( F_10 ( V_106 -> V_77 . V_109 ) ,
V_110 ) ;
V_151 = F_44 ( F_10 ( V_106 -> V_175 . V_74 ) ,
V_176 ) ;
V_113 = (struct V_105 * ) V_106 -> V_177 ;
V_174 = F_73 ( V_113 -> V_114 ) ;
V_12 -> V_179 = F_75 ( V_12 ) ;
switch ( V_108 ) {
case V_111 :
F_45 ( V_12 , V_12 -> V_21 - V_180 ) ;
break;
case V_181 :
V_113 = (struct V_105 * ) V_12 -> V_34 ;
V_174 = F_71 ( V_113 ) ;
F_13 ( V_12 , V_174 ) ;
V_113 = (struct V_105 * ) V_106 -> V_177 ;
V_174 = F_73 ( V_113 -> V_114 ) ;
memcpy ( F_77 ( V_12 , V_174 ) , V_113 , V_174 ) ;
break;
case V_183 :
V_189 = V_113 ;
V_189 += F_79 ( V_174 , 4 ) ;
V_189 += F_79 ( F_56 ( V_151 ) , 4 ) ;
F_13 ( V_12 , sizeof( struct V_186 ) ) ;
memcpy ( F_77 ( V_12 , sizeof( struct V_184 ) ) ,
V_189 , sizeof( struct V_184 ) ) ;
memcpy ( F_77 ( V_12 , V_174 ) , V_113 , V_174 ) ;
break;
case V_187 :
F_13 ( V_12 , sizeof( struct V_185 ) ) ;
memcpy ( F_77 ( V_12 , V_174 ) , V_113 , V_174 ) ;
break;
}
F_64 ( V_2 , V_150 , V_12 , V_151 , V_108 , false ) ;
F_68 ( V_2 -> V_18 , V_150 , V_12 ) ;
}
static int F_75 ( struct V_11 * V_12 )
{
struct V_24 * V_106 ;
T_3 V_36 , V_190 ;
bool V_191 , V_192 ;
bool V_193 , V_194 ;
bool V_195 , V_196 ;
V_106 = ( void * ) V_12 -> V_34 - sizeof( * V_106 ) ;
V_36 = F_10 ( V_106 -> V_35 . V_36 ) ;
V_190 = F_10 ( V_106 -> V_77 . V_109 ) ;
V_191 = ! ! ( V_190 & V_197 ) ;
V_192 = ! ! ( V_190 & V_198 ) ;
V_193 = ! ! ( V_190 & V_199 ) ;
V_194 = ! ! ( V_190 & V_200 ) ;
V_195 = ! ( V_36 & V_201 ) ;
V_196 = ! ( V_36 & V_202 ) ;
if ( ! V_191 && ! V_192 )
return V_203 ;
if ( ! V_193 && ! V_194 )
return V_203 ;
if ( ! V_195 )
return V_203 ;
if ( ! V_196 )
return V_203 ;
return V_204 ;
}
static int F_80 ( struct V_11 * V_205 )
{
struct V_11 * V_56 = V_205 -> V_56 ;
struct V_11 * V_206 = V_56 ;
int V_207 ;
int V_208 = 0 ;
V_205 -> V_56 = NULL ;
while ( V_56 ) {
V_208 += V_56 -> V_21 ;
V_56 = V_56 -> V_56 ;
}
V_207 = V_208 - F_7 ( V_205 ) ;
if ( ( V_207 > 0 ) &&
( F_81 ( V_205 , 0 , V_207 , V_209 ) < 0 ) ) {
V_205 -> V_56 = V_206 ;
return - 1 ;
}
V_56 = V_206 ;
while ( V_56 ) {
F_82 ( V_56 , F_41 ( V_205 , V_56 -> V_21 ) ,
V_56 -> V_21 ) ;
V_56 = V_56 -> V_56 ;
}
F_38 ( V_206 ) ;
return 0 ;
}
static bool F_83 ( struct V_1 * V_2 ,
struct V_11 * V_210 ,
enum V_211 V_121 ,
bool V_212 ,
T_3 V_35 )
{
if ( V_210 -> V_21 == 0 ) {
F_55 ( V_213 ,
L_19 ) ;
return false ;
}
if ( V_35 & V_71 ) {
F_55 ( V_213 ,
L_20 ) ;
return false ;
}
if ( ! V_212 ) {
F_37 ( L_21 ) ;
return false ;
}
if ( V_121 == V_214 ||
V_35 & V_73 ) {
F_55 ( V_213 , L_22 ) ;
return false ;
}
if ( V_121 != V_215 &&
V_121 != V_216 &&
V_121 != V_217 &&
! V_2 -> V_18 -> V_218 ) {
F_55 ( V_213 ,
L_23 ,
V_121 ) ;
return false ;
}
if ( F_84 ( V_219 , & V_2 -> V_18 -> V_220 ) ) {
F_55 ( V_213 ,
L_24 ) ;
return false ;
}
return true ;
}
static void F_85 ( struct V_1 * V_2 ,
struct V_221 * V_222 )
{
struct V_120 * V_150 = & V_2 -> V_150 ;
struct V_223 * V_224 ;
struct V_24 * V_106 ;
enum V_211 V_121 ;
struct V_105 * V_113 ;
int V_225 ;
T_3 V_35 ;
int V_58 ;
T_2 * V_57 ;
bool V_212 ;
int V_15 , V_226 ;
int V_26 ;
F_20 ( & V_2 -> V_10 . V_39 ) ;
V_58 = F_66 ( V_222 -> V_227 . V_228 ) ;
V_57 = ( T_2 * ) & V_222 -> V_57 ;
V_225 = F_44 ( F_10 ( V_222 -> V_113 . V_109 ) ,
V_229 ) ;
V_224 = F_86 ( V_222 ) ;
if ( V_222 -> V_230 . V_74 & V_130 ) {
memset ( V_150 , 0 , sizeof( * V_150 ) ) ;
V_150 -> signal = V_231 +
V_222 -> V_230 . V_232 ;
}
if ( V_222 -> V_230 . V_74 & V_233 ) {
V_150 -> V_234 = F_10 ( V_222 -> V_230 . V_235 ) & 0xffffffff ;
V_150 -> V_140 |= V_236 ;
}
V_212 = F_67 ( V_2 -> V_18 , V_150 ) ;
if ( V_212 ) {
F_62 ( V_2 -> V_18 , V_150 -> V_118 ,
V_222 -> V_230 . V_74 ,
F_10 ( V_222 -> V_230 . V_109 ) ,
F_10 ( V_222 -> V_230 . V_119 ) ,
V_150 ) ;
}
F_40 ( V_67 , NULL , L_25 ,
V_222 , sizeof( * V_222 ) +
( sizeof( struct V_223 ) *
V_225 ) ) ;
for ( V_15 = 0 ; V_15 < V_225 ; V_15 ++ ) {
V_121 = V_224 [ V_15 ] . V_237 ;
for ( V_226 = 0 ; V_226 < V_224 [ V_15 ] . V_238 ; V_226 ++ ) {
struct V_11 * V_205 , * V_239 ;
V_35 = 0 ;
V_205 = NULL ;
V_239 = NULL ;
V_26 = F_39 ( V_2 ,
& V_57 ,
& V_58 ,
& V_205 ,
& V_239 ,
& V_35 ) ;
if ( V_26 < 0 ) {
F_37 ( L_26 ,
V_26 ) ;
F_38 ( V_205 ) ;
continue;
}
V_106 = F_87 ( ( void * ) V_205 -> V_34 ,
struct V_24 ,
V_68 ) ;
if ( ! F_83 ( V_2 , V_205 ,
V_121 ,
V_212 ,
V_35 ) ) {
F_38 ( V_205 ) ;
continue;
}
if ( V_26 > 0 &&
F_80 ( V_205 ) < 0 ) {
F_38 ( V_205 ) ;
continue;
}
if ( V_35 & V_72 )
V_150 -> V_140 |= V_165 ;
else
V_150 -> V_140 &= ~ V_165 ;
if ( V_35 & V_70 )
V_150 -> V_140 |= V_166 ;
else
V_150 -> V_140 &= ~ V_166 ;
V_113 = F_58 ( V_205 ) ;
if ( F_59 ( V_113 ) )
F_74 ( V_2 , V_150 , V_205 ) ;
else
F_78 ( V_2 , V_150 , V_205 ) ;
}
}
F_26 ( & V_2 -> V_47 ) ;
}
static void F_88 ( struct V_1 * V_2 ,
struct V_240 * V_241 )
{
struct V_11 * V_205 , * V_239 ;
enum V_96 V_151 ;
struct V_24 * V_106 ;
enum V_107 V_108 ;
struct V_120 * V_150 = & V_2 -> V_150 ;
struct V_105 * V_113 ;
int V_26 ;
bool V_242 ;
bool V_243 ;
T_2 * V_57 ;
int V_58 , V_244 , V_245 ;
int V_246 ;
T_3 V_35 = 0 ;
V_58 = F_66 ( V_241 -> V_228 ) ;
V_57 = ( T_2 * ) V_241 -> V_247 ;
V_205 = NULL ;
V_239 = NULL ;
F_22 ( & V_2 -> V_10 . V_39 ) ;
V_26 = F_39 ( V_2 , & V_57 , & V_58 ,
& V_205 , & V_239 ,
& V_35 ) ;
F_27 ( & V_2 -> V_10 . V_39 ) ;
F_55 ( V_67 , L_27 ) ;
if ( V_26 ) {
F_37 ( L_28 ,
V_26 ) ;
F_38 ( V_205 ) ;
return;
}
V_150 -> V_140 |= V_248 ;
V_113 = (struct V_105 * ) V_205 -> V_34 ;
V_106 = ( void * ) V_205 -> V_34 - sizeof( * V_106 ) ;
V_242 = ! ! ( V_35 & V_70 ) ;
V_243 = ! ! ( V_35 & V_71 ) ;
V_108 = F_44 ( F_10 ( V_106 -> V_77 . V_109 ) ,
V_110 ) ;
if ( V_108 != V_111 ) {
F_37 ( L_29 ) ;
F_8 ( V_205 ) ;
goto V_249;
}
V_151 = F_44 ( F_10 ( V_106 -> V_175 . V_74 ) ,
V_176 ) ;
F_64 ( V_2 , V_150 , V_205 , V_151 , V_108 ,
true ) ;
V_205 -> V_179 = F_75 ( V_205 ) ;
if ( V_242 )
F_37 ( L_30 ) ;
if ( V_243 ) {
F_37 ( L_31 ) ;
F_8 ( V_205 ) ;
goto V_249;
}
if ( V_151 != V_104 ) {
V_244 = F_73 ( V_113 -> V_114 ) ;
V_245 = F_56 ( V_151 ) ;
memmove ( ( void * ) V_205 -> V_34 + V_245 ,
( void * ) V_205 -> V_34 ,
V_244 ) ;
F_13 ( V_205 , V_245 ) ;
V_113 = (struct V_105 * ) V_205 -> V_34 ;
}
V_246 = 4 ;
V_246 += F_57 ( V_151 ) ;
if ( ! F_89 ( V_113 -> V_114 ) &&
V_151 == V_101 )
V_246 += 8 ;
if ( V_246 > V_205 -> V_21 ) {
F_37 ( L_32 ) ;
F_8 ( V_205 ) ;
goto V_249;
}
F_45 ( V_205 , V_205 -> V_21 - V_246 ) ;
F_40 ( V_67 , NULL , L_33 ,
V_205 -> V_34 , V_205 -> V_21 ) ;
F_68 ( V_2 -> V_18 , V_150 , V_205 ) ;
V_249:
if ( V_58 > 0 ) {
F_55 ( V_213 ,
L_34 ,
V_58 ) ;
}
}
static void F_90 ( struct V_116 * V_18 ,
struct V_11 * V_12 )
{
struct V_1 * V_2 = & V_18 -> V_2 ;
struct V_250 * V_251 = (struct V_250 * ) V_12 -> V_34 ;
struct V_252 V_253 = {} ;
int V_121 = F_44 ( V_251 -> V_254 . V_36 , V_255 ) ;
T_4 V_256 ;
int V_15 ;
F_20 ( & V_2 -> V_257 ) ;
switch ( V_121 ) {
case V_258 :
V_253 . V_259 = true ;
break;
case V_260 :
break;
case V_261 :
case V_262 :
case V_263 :
V_253 . V_264 = true ;
break;
default:
F_37 ( L_35 , V_121 ) ;
V_253 . V_264 = true ;
break;
}
F_55 ( V_213 , L_36 ,
V_251 -> V_254 . V_265 ) ;
for ( V_15 = 0 ; V_15 < V_251 -> V_254 . V_265 ; V_15 ++ ) {
V_256 = V_251 -> V_254 . V_266 [ V_15 ] ;
V_253 . V_256 = F_66 ( V_256 ) ;
F_91 ( V_2 , & V_253 ) ;
}
}
static void F_92 ( struct V_116 * V_18 , struct V_250 * V_251 )
{
struct V_267 * V_268 = & V_251 -> V_269 ;
struct V_270 * V_271 ;
struct V_272 * V_273 ;
T_5 V_74 , V_274 , V_275 ;
V_74 = F_66 ( V_268 -> V_74 ) ;
V_274 = F_44 ( V_74 , V_276 ) ;
V_275 = F_44 ( V_74 , V_277 ) ;
F_55 ( V_213 ,
L_37 ,
V_274 , V_275 , V_268 -> V_278 ) ;
F_22 ( & V_18 -> V_159 ) ;
V_271 = F_93 ( V_18 , V_275 ) ;
if ( ! V_271 ) {
F_37 ( L_38 ,
V_275 ) ;
F_27 ( & V_18 -> V_159 ) ;
return;
}
V_273 = F_94 ( V_18 , V_271 -> V_279 ) ;
if ( ! V_273 ) {
F_37 ( L_39 ,
V_271 -> V_279 ) ;
F_27 ( & V_18 -> V_159 ) ;
return;
}
F_55 ( V_213 ,
L_40 ,
V_271 -> V_171 , V_274 , V_268 -> V_278 ) ;
F_95 ( V_273 -> V_280 , V_271 -> V_171 , V_274 ) ;
F_27 ( & V_18 -> V_159 ) ;
}
static void F_96 ( struct V_116 * V_18 , struct V_250 * V_251 )
{
struct V_281 * V_268 = & V_251 -> V_282 ;
struct V_270 * V_271 ;
struct V_272 * V_273 ;
T_5 V_74 , V_274 , V_275 ;
V_74 = F_66 ( V_268 -> V_74 ) ;
V_274 = F_44 ( V_74 , V_276 ) ;
V_275 = F_44 ( V_74 , V_277 ) ;
F_55 ( V_213 ,
L_41 ,
V_274 , V_275 ) ;
F_22 ( & V_18 -> V_159 ) ;
V_271 = F_93 ( V_18 , V_275 ) ;
if ( ! V_271 ) {
F_37 ( L_38 ,
V_275 ) ;
F_27 ( & V_18 -> V_159 ) ;
return;
}
V_273 = F_94 ( V_18 , V_271 -> V_279 ) ;
if ( ! V_273 ) {
F_37 ( L_39 ,
V_271 -> V_279 ) ;
F_27 ( & V_18 -> V_159 ) ;
return;
}
F_55 ( V_213 ,
L_42 ,
V_271 -> V_171 , V_274 ) ;
F_97 ( V_273 -> V_280 , V_271 -> V_171 , V_274 ) ;
F_27 ( & V_18 -> V_159 ) ;
}
void F_98 ( struct V_116 * V_18 , struct V_11 * V_12 )
{
struct V_1 * V_2 = & V_18 -> V_2 ;
struct V_250 * V_251 = (struct V_250 * ) V_12 -> V_34 ;
if ( ! F_12 ( ( unsigned long ) V_12 -> V_34 , 4 ) )
F_37 ( L_43 ) ;
F_55 ( V_213 , L_44 ,
V_251 -> V_113 . V_283 ) ;
switch ( V_251 -> V_113 . V_283 ) {
case V_284 : {
V_2 -> V_285 = V_251 -> V_286 . V_287 ;
V_2 -> V_288 = V_251 -> V_286 . V_289 ;
F_99 ( & V_2 -> V_290 ) ;
break;
}
case V_291 :
F_22 ( & V_2 -> V_10 . V_39 ) ;
F_100 ( & V_2 -> V_51 , V_12 ) ;
F_27 ( & V_2 -> V_10 . V_39 ) ;
F_26 ( & V_2 -> V_49 ) ;
return;
case V_292 : {
struct V_293 V_268 = {
. V_279 = V_251 -> V_294 . V_279 ,
. V_275 = F_66 ( V_251 -> V_294 . V_275 ) ,
} ;
memcpy ( V_268 . V_171 , V_251 -> V_294 . V_171 , sizeof( V_268 . V_171 ) ) ;
F_101 ( V_2 , & V_268 ) ;
break;
}
case V_295 : {
struct V_296 V_268 = {
. V_275 = F_66 ( V_251 -> V_297 . V_275 ) ,
} ;
F_102 ( V_2 , & V_268 ) ;
break;
}
case V_298 : {
struct V_252 V_253 = {} ;
int V_121 = F_10 ( V_251 -> V_299 . V_121 ) ;
V_253 . V_256 =
F_10 ( V_251 -> V_299 . V_300 ) ;
switch ( V_121 ) {
case V_301 :
break;
case V_302 :
V_253 . V_259 = true ;
break;
case V_303 :
V_253 . V_264 = true ;
break;
}
F_22 ( & V_2 -> V_257 ) ;
F_91 ( V_2 , & V_253 ) ;
F_27 ( & V_2 -> V_257 ) ;
break;
}
case V_304 :
F_22 ( & V_2 -> V_257 ) ;
F_100 ( & V_2 -> V_50 , V_12 ) ;
F_27 ( & V_2 -> V_257 ) ;
F_26 ( & V_2 -> V_49 ) ;
return;
case V_305 : {
struct V_116 * V_18 = V_2 -> V_18 ;
struct V_306 * V_268 = & V_251 -> V_307 ;
F_55 ( V_213 ,
L_45 ,
F_66 ( V_268 -> V_275 ) ,
! ! ( V_268 -> V_36 & V_308 ) ,
F_44 ( V_268 -> V_36 , V_309 ) ) ;
F_99 ( & V_18 -> V_310 ) ;
break;
}
case V_311 : {
F_40 ( V_67 , NULL , L_46 ,
V_12 -> V_34 , V_12 -> V_21 ) ;
F_88 ( V_2 , & V_251 -> V_312 ) ;
break;
}
case V_313 :
break;
case V_314 :
F_103 ( V_12 -> V_34 , V_12 -> V_21 ) ;
break;
case V_315 :
F_37 ( L_47 ) ;
break;
case V_316 :
F_92 ( V_18 , V_251 ) ;
break;
case V_317 :
F_96 ( V_18 , V_251 ) ;
break;
case V_318 : {
break;
}
default:
F_55 ( V_213 , L_48 ,
V_251 -> V_113 . V_283 ) ;
F_40 ( V_67 , NULL , L_46 ,
V_12 -> V_34 , V_12 -> V_21 ) ;
break;
} ;
F_8 ( V_12 ) ;
}
static void V_94 ( unsigned long V_84 )
{
struct V_1 * V_2 = (struct V_1 * ) V_84 ;
struct V_250 * V_251 ;
struct V_11 * V_12 ;
F_22 ( & V_2 -> V_257 ) ;
while ( ( V_12 = F_104 ( & V_2 -> V_50 ) ) ) {
F_90 ( V_2 -> V_18 , V_12 ) ;
F_8 ( V_12 ) ;
}
F_27 ( & V_2 -> V_257 ) ;
F_22 ( & V_2 -> V_10 . V_39 ) ;
while ( ( V_12 = F_104 ( & V_2 -> V_51 ) ) ) {
V_251 = (struct V_250 * ) V_12 -> V_34 ;
F_85 ( V_2 , & V_251 -> V_319 ) ;
F_8 ( V_12 ) ;
}
F_27 ( & V_2 -> V_10 . V_39 ) ;
}
