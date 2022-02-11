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
struct V_11 * * V_60 )
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
if ( * V_58 > 0 ) {
V_25 -> V_57 . V_70 = * * V_57 ;
( * V_57 ) ++ ;
( * V_58 ) -- ;
} else {
V_25 -> V_57 . V_70 = 0 ;
}
V_65 = ! ! ( F_10 ( V_25 -> V_35 . V_36 )
& ( V_71 |
V_72 ) ) ;
V_61 = F_44 ( F_10 ( V_25 -> V_73 . V_70 ) ,
V_74 ) ;
V_66 = V_25 -> V_75 . V_76 ;
if ( V_65 )
V_61 = 0 ;
F_45 ( V_53 , 0 ) ;
F_41 ( V_53 , F_23 ( V_61 , V_77 ) ) ;
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
V_64 = F_10 ( V_25 -> V_78 . V_70 ) &
V_79 ;
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
static void F_46 ( unsigned long V_80 )
{
struct V_1 * V_2 = (struct V_1 * ) V_80 ;
F_21 ( V_2 ) ;
}
int F_47 ( struct V_1 * V_2 )
{
T_1 V_20 ;
void * V_29 ;
struct V_81 * V_82 = & V_2 -> V_10 . V_44 ;
V_2 -> V_10 . V_3 = F_1 ( V_2 ) ;
if ( ! F_48 ( V_2 -> V_10 . V_3 ) ) {
F_37 ( L_6 ) ;
return - V_83 ;
}
V_2 -> V_10 . V_38 = V_2 -> V_10 . V_3 - 1 ;
V_2 -> V_10 . V_42 = F_3 ( V_2 ) ;
V_2 -> V_10 . V_17 =
F_49 ( V_2 -> V_10 . V_3 * sizeof( struct V_11 * ) ,
V_84 ) ;
if ( ! V_2 -> V_10 . V_17 )
goto V_85;
V_29 = F_50 ( V_2 -> V_18 -> V_19 ,
( V_2 -> V_10 . V_3 * sizeof( V_2 -> V_10 . V_37 ) ) ,
& V_20 , V_86 ) ;
if ( ! V_29 )
goto V_87;
V_2 -> V_10 . V_37 = V_29 ;
V_2 -> V_10 . V_52 = V_20 ;
V_29 = F_50 ( V_2 -> V_18 -> V_19 ,
sizeof( * V_2 -> V_10 . V_28 . V_29 ) ,
& V_20 , V_86 ) ;
if ( ! V_29 )
goto V_88;
V_2 -> V_10 . V_28 . V_29 = V_29 ;
V_2 -> V_10 . V_28 . V_20 = V_20 ;
V_2 -> V_10 . V_54 . V_55 = 0 ;
* V_2 -> V_10 . V_28 . V_29 = 0 ;
F_51 ( V_82 , F_28 , ( unsigned long ) V_2 ) ;
F_52 ( & V_2 -> V_10 . V_39 ) ;
V_2 -> V_10 . V_16 = 0 ;
if ( F_9 ( V_2 , V_2 -> V_10 . V_42 ) )
goto V_89;
F_53 ( & V_2 -> V_47 , F_46 ,
( unsigned long ) V_2 ) ;
F_54 ( & V_2 -> V_50 ) ;
F_54 ( & V_2 -> V_51 ) ;
F_53 ( & V_2 -> V_49 , V_90 ,
( unsigned long ) V_2 ) ;
F_55 ( V_91 , L_7 ,
V_2 -> V_10 . V_3 , V_2 -> V_10 . V_42 ) ;
return 0 ;
V_89:
F_4 ( V_2 ) ;
F_34 ( V_2 -> V_18 -> V_19 ,
sizeof( * V_2 -> V_10 . V_28 . V_29 ) ,
V_2 -> V_10 . V_28 . V_29 ,
V_2 -> V_10 . V_28 . V_20 ) ;
V_88:
F_34 ( V_2 -> V_18 -> V_19 ,
( V_2 -> V_10 . V_3 *
sizeof( V_2 -> V_10 . V_37 ) ) ,
V_2 -> V_10 . V_37 ,
V_2 -> V_10 . V_52 ) ;
V_87:
F_35 ( V_2 -> V_10 . V_17 ) ;
V_85:
return - V_32 ;
}
static int F_56 ( enum V_92 type )
{
switch ( type ) {
case V_93 :
case V_94 :
return 4 ;
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
return 8 ;
case V_100 :
return 0 ;
}
F_37 ( L_8 , type ) ;
return 0 ;
}
static int F_57 ( enum V_92 type )
{
switch ( type ) {
case V_100 :
case V_93 :
case V_94 :
case V_96 :
case V_98 :
return 0 ;
case V_95 :
case V_97 :
return 4 ;
case V_99 :
return 8 ;
}
F_37 ( L_8 , type ) ;
return 0 ;
}
static struct V_101 * F_58 ( struct V_11 * V_12 )
{
struct V_24 * V_102 ;
enum V_103 V_104 ;
V_102 = ( void * ) V_12 -> V_34 - sizeof( * V_102 ) ;
V_104 = F_44 ( F_10 ( V_102 -> V_73 . V_105 ) ,
V_106 ) ;
if ( V_104 == V_107 )
return ( void * ) V_12 -> V_34 ;
else
return ( void * ) V_12 -> V_34 - V_108 ;
}
static bool F_59 ( struct V_101 * V_109 )
{
if ( F_60 ( V_109 -> V_110 ) ) {
T_2 * V_111 = F_61 ( V_109 ) ;
if ( V_111 [ 0 ] & 0x80 )
return true ;
}
return false ;
}
static void F_62 ( struct V_112 * V_18 ,
enum V_113 V_114 ,
T_2 V_70 , T_3 V_105 , T_3 V_115 ,
struct V_116 * V_117 )
{
T_2 V_118 , V_119 , V_120 , V_121 , V_122 , V_123 , V_124 ;
T_2 V_125 = 0 ;
if ( ! ( V_70 & V_126 ) )
return;
V_125 = F_44 ( V_105 , V_127 ) ;
switch ( V_125 ) {
case V_128 :
V_118 = V_70 & V_129 ;
V_119 = F_44 ( V_70 , V_130 ) ;
V_120 = 0 ;
if ( V_119 < 0x08 || V_119 > 0x0F )
break;
switch ( V_114 ) {
case V_131 :
if ( V_118 )
V_119 &= ~ F_63 ( 3 ) ;
V_120 = V_132 [ V_119 ] ;
break;
case V_133 :
V_120 = V_132 [ V_119 ] ;
V_120 -= 4 ;
break;
default:
break;
}
V_117 -> V_120 = V_120 ;
break;
case V_134 :
case V_135 :
V_123 = V_105 & 0x1F ;
V_124 = V_123 >> 3 ;
V_121 = ( V_105 >> 7 ) & 1 ;
V_122 = ( V_115 >> 7 ) & 1 ;
V_117 -> V_120 = V_123 ;
V_117 -> V_136 |= V_137 ;
if ( V_122 )
V_117 -> V_136 |= V_138 ;
if ( V_121 )
V_117 -> V_136 |= V_139 ;
break;
case V_140 :
case V_141 :
V_123 = ( V_115 >> 4 ) & 0x0F ;
V_124 = ( ( V_105 >> 10 ) & 0x07 ) + 1 ;
V_121 = V_105 & 3 ;
V_122 = V_115 & 1 ;
V_117 -> V_120 = V_123 ;
V_117 -> V_142 = V_124 ;
if ( V_122 )
V_117 -> V_136 |= V_138 ;
switch ( V_121 ) {
case 0 :
break;
case 1 :
V_117 -> V_136 |= V_139 ;
break;
case 2 :
V_117 -> V_143 |= V_144 ;
}
V_117 -> V_136 |= V_145 ;
break;
default:
break;
}
}
static void F_64 ( struct V_1 * V_2 ,
struct V_116 * V_146 ,
struct V_11 * V_12 ,
enum V_92 V_147 ,
enum V_103 V_104 ,
bool V_148 )
{
struct V_101 * V_109 = (struct V_101 * ) V_12 -> V_34 ;
V_146 -> V_136 &= ~ ( V_149 |
V_150 |
V_151 ) ;
if ( V_147 == V_100 )
return;
if ( V_104 == V_107 && ! V_148 )
return;
V_146 -> V_136 |= V_149 |
V_150 |
V_151 ;
V_109 -> V_110 = F_65 ( F_66 ( V_109 -> V_110 ) &
~ V_152 ) ;
}
static bool F_67 ( struct V_112 * V_18 ,
struct V_116 * V_117 )
{
struct V_153 * V_154 ;
F_22 ( & V_18 -> V_155 ) ;
V_154 = V_18 -> V_156 ;
if ( ! V_154 )
V_154 = V_18 -> V_157 ;
F_27 ( & V_18 -> V_155 ) ;
if ( ! V_154 )
return false ;
V_117 -> V_114 = V_154 -> V_114 ;
V_117 -> V_158 = V_154 -> V_159 ;
return true ;
}
static void F_68 ( struct V_112 * V_18 ,
struct V_116 * V_146 ,
struct V_11 * V_12 )
{
struct V_116 * V_117 ;
V_117 = F_69 ( V_12 ) ;
* V_117 = * V_146 ;
F_55 ( V_160 ,
L_9 ,
V_12 ,
V_12 -> V_21 ,
V_117 -> V_136 == 0 ? L_10 : L_11 ,
V_117 -> V_136 & V_137 ? L_12 : L_11 ,
V_117 -> V_136 & V_145 ? L_13 : L_11 ,
V_117 -> V_136 & V_139 ? L_14 : L_11 ,
V_117 -> V_143 & V_144 ? L_15 : L_11 ,
V_117 -> V_136 & V_138 ? L_16 : L_11 ,
V_117 -> V_120 ,
V_117 -> V_142 ,
V_117 -> V_158 ,
V_117 -> V_114 , V_117 -> V_136 ,
! ! ( V_117 -> V_136 & V_161 ) ,
! ! ( V_117 -> V_136 & V_162 ) ) ;
F_40 ( V_67 , NULL , L_17 ,
V_12 -> V_34 , V_12 -> V_21 ) ;
F_70 ( V_18 -> V_163 , V_12 ) ;
}
static int F_71 ( struct V_101 * V_109 )
{
return F_72 ( F_73 ( V_109 -> V_110 ) , 4 ) ;
}
static void F_74 ( struct V_1 * V_2 ,
struct V_116 * V_146 ,
struct V_11 * V_164 )
{
struct V_24 * V_102 ;
struct V_11 * V_12 = V_164 ;
struct V_11 * V_165 ;
enum V_103 V_104 ;
enum V_92 V_147 ;
struct V_101 * V_109 ;
T_2 V_166 [ 64 ] , V_167 [ V_168 ] , * V_169 ;
unsigned int V_170 ;
V_102 = ( void * ) V_12 -> V_34 - sizeof( * V_102 ) ;
V_147 = F_44 ( F_10 ( V_102 -> V_171 . V_70 ) ,
V_172 ) ;
V_109 = (struct V_101 * ) V_102 -> V_173 ;
V_170 = F_73 ( V_109 -> V_110 ) ;
memcpy ( V_166 , V_109 , V_170 ) ;
V_109 = (struct V_101 * ) V_166 ;
V_165 = V_12 ;
while ( V_12 ) {
void * V_174 ;
int V_21 ;
V_102 = ( void * ) V_12 -> V_34 - sizeof( * V_102 ) ;
V_104 = F_44 ( F_10 ( V_102 -> V_73 . V_105 ) ,
V_106 ) ;
V_174 = ( void * ) V_102 -> V_173 ;
V_12 -> V_175 = F_75 ( V_12 ) ;
if ( V_12 == V_165 ) {
V_21 = F_72 ( F_73 ( V_109 -> V_110 ) , 4 ) ;
V_21 += F_72 ( F_56 ( V_147 ) ,
4 ) ;
V_174 += V_21 ;
}
switch ( V_104 ) {
case V_107 :
F_45 ( V_12 , V_12 -> V_21 - V_176 ) ;
break;
case V_177 :
V_109 = (struct V_101 * ) V_12 -> V_34 ;
V_170 = F_71 ( V_109 ) ;
memcpy ( V_167 , F_76 ( V_109 ) , V_168 ) ;
F_13 ( V_12 , V_170 ) ;
V_109 = (struct V_101 * ) V_166 ;
V_170 = F_73 ( V_109 -> V_110 ) ;
memcpy ( F_77 ( V_12 , V_170 ) , V_109 , V_170 ) ;
V_109 = (struct V_101 * ) V_12 -> V_34 ;
V_169 = F_61 ( V_109 ) ;
V_169 [ 0 ] &= ~ V_178 ;
memcpy ( F_76 ( V_109 ) , V_167 , V_168 ) ;
break;
case V_179 :
V_21 = 0 ;
V_21 += sizeof( struct V_180 ) ;
V_21 += sizeof( struct V_181 ) ;
F_13 ( V_12 , sizeof( struct V_182 ) ) ;
memcpy ( F_77 ( V_12 , V_21 ) , V_174 , V_21 ) ;
memcpy ( F_77 ( V_12 , V_170 ) , V_109 , V_170 ) ;
break;
case V_183 :
memcpy ( F_77 ( V_12 , V_170 ) , V_109 , V_170 ) ;
break;
}
V_164 = V_12 ;
F_64 ( V_2 , V_146 , V_164 , V_147 , V_104 ,
false ) ;
V_12 = V_12 -> V_56 ;
V_164 -> V_56 = NULL ;
if ( V_12 )
V_146 -> V_136 |= V_184 ;
else
V_146 -> V_136 &= ~ V_184 ;
F_68 ( V_2 -> V_18 , V_146 , V_164 ) ;
}
}
static void F_78 ( struct V_1 * V_2 ,
struct V_116 * V_146 ,
struct V_11 * V_12 )
{
struct V_24 * V_102 ;
struct V_101 * V_109 ;
enum V_103 V_104 ;
enum V_92 V_147 ;
int V_170 ;
void * V_185 ;
if ( V_12 -> V_56 ) {
F_37 ( L_18 ) ;
F_38 ( V_12 -> V_56 ) ;
V_12 -> V_56 = NULL ;
}
V_102 = ( void * ) V_12 -> V_34 - sizeof( * V_102 ) ;
V_104 = F_44 ( F_10 ( V_102 -> V_73 . V_105 ) ,
V_106 ) ;
V_147 = F_44 ( F_10 ( V_102 -> V_171 . V_70 ) ,
V_172 ) ;
V_109 = (struct V_101 * ) V_102 -> V_173 ;
V_170 = F_73 ( V_109 -> V_110 ) ;
V_12 -> V_175 = F_75 ( V_12 ) ;
switch ( V_104 ) {
case V_107 :
F_45 ( V_12 , V_12 -> V_21 - V_176 ) ;
break;
case V_177 :
V_109 = (struct V_101 * ) V_12 -> V_34 ;
V_170 = F_71 ( V_109 ) ;
F_13 ( V_12 , V_170 ) ;
V_109 = (struct V_101 * ) V_102 -> V_173 ;
V_170 = F_73 ( V_109 -> V_110 ) ;
memcpy ( F_77 ( V_12 , V_170 ) , V_109 , V_170 ) ;
break;
case V_179 :
V_185 = V_109 ;
V_185 += F_79 ( V_170 , 4 ) ;
V_185 += F_79 ( F_56 ( V_147 ) , 4 ) ;
F_13 ( V_12 , sizeof( struct V_182 ) ) ;
memcpy ( F_77 ( V_12 , sizeof( struct V_180 ) ) ,
V_185 , sizeof( struct V_180 ) ) ;
memcpy ( F_77 ( V_12 , V_170 ) , V_109 , V_170 ) ;
break;
case V_183 :
F_13 ( V_12 , sizeof( struct V_181 ) ) ;
memcpy ( F_77 ( V_12 , V_170 ) , V_109 , V_170 ) ;
break;
}
F_64 ( V_2 , V_146 , V_12 , V_147 , V_104 , false ) ;
F_68 ( V_2 -> V_18 , V_146 , V_12 ) ;
}
static int F_75 ( struct V_11 * V_12 )
{
struct V_24 * V_102 ;
T_3 V_36 , V_186 ;
bool V_187 , V_188 ;
bool V_189 , V_190 ;
bool V_191 , V_192 ;
V_102 = ( void * ) V_12 -> V_34 - sizeof( * V_102 ) ;
V_36 = F_10 ( V_102 -> V_35 . V_36 ) ;
V_186 = F_10 ( V_102 -> V_73 . V_105 ) ;
V_187 = ! ! ( V_186 & V_193 ) ;
V_188 = ! ! ( V_186 & V_194 ) ;
V_189 = ! ! ( V_186 & V_195 ) ;
V_190 = ! ! ( V_186 & V_196 ) ;
V_191 = ! ( V_36 & V_197 ) ;
V_192 = ! ( V_36 & V_198 ) ;
if ( ! V_187 && ! V_188 )
return V_199 ;
if ( ! V_189 && ! V_190 )
return V_199 ;
if ( ! V_191 )
return V_199 ;
if ( ! V_192 )
return V_199 ;
return V_200 ;
}
static int F_80 ( struct V_11 * V_201 )
{
struct V_11 * V_56 = V_201 -> V_56 ;
struct V_11 * V_202 = V_56 ;
int V_203 ;
int V_204 = 0 ;
V_201 -> V_56 = NULL ;
while ( V_56 ) {
V_204 += V_56 -> V_21 ;
V_56 = V_56 -> V_56 ;
}
V_203 = V_204 - F_7 ( V_201 ) ;
if ( ( V_203 > 0 ) &&
( F_81 ( V_201 , 0 , V_203 , V_205 ) < 0 ) ) {
V_201 -> V_56 = V_202 ;
return - 1 ;
}
V_56 = V_202 ;
while ( V_56 ) {
F_82 ( V_56 , F_41 ( V_201 , V_56 -> V_21 ) ,
V_56 -> V_21 ) ;
V_56 = V_56 -> V_56 ;
}
F_38 ( V_202 ) ;
return 0 ;
}
static bool F_83 ( struct V_1 * V_2 ,
struct V_11 * V_206 ,
enum V_207 V_117 ,
bool V_208 ,
T_3 V_35 )
{
if ( V_206 -> V_21 == 0 ) {
F_55 ( V_209 ,
L_19 ) ;
return false ;
}
if ( V_35 & V_210 ) {
F_55 ( V_209 ,
L_20 ) ;
return false ;
}
if ( ! V_208 ) {
F_37 ( L_21 ) ;
return false ;
}
if ( V_117 == V_211 ||
V_35 & V_212 ) {
F_55 ( V_209 , L_22 ) ;
return false ;
}
if ( V_117 != V_213 &&
V_117 != V_214 &&
V_117 != V_215 &&
! V_2 -> V_18 -> V_216 ) {
F_55 ( V_209 ,
L_23 ,
V_117 ) ;
return false ;
}
if ( F_84 ( V_217 , & V_2 -> V_18 -> V_218 ) ) {
F_55 ( V_209 ,
L_24 ) ;
return false ;
}
return true ;
}
static void F_85 ( struct V_1 * V_2 ,
struct V_219 * V_220 )
{
struct V_116 * V_146 = & V_2 -> V_146 ;
struct V_221 * V_222 ;
struct V_24 * V_102 ;
enum V_207 V_117 ;
struct V_101 * V_109 ;
int V_223 ;
T_3 V_35 ;
int V_58 ;
T_2 * V_57 ;
bool V_208 ;
int V_15 , V_224 ;
int V_26 ;
F_20 ( & V_2 -> V_10 . V_39 ) ;
V_58 = F_66 ( V_220 -> V_225 . V_226 ) ;
V_57 = ( T_2 * ) & V_220 -> V_57 ;
V_223 = F_44 ( F_10 ( V_220 -> V_109 . V_105 ) ,
V_227 ) ;
V_222 = F_86 ( V_220 ) ;
if ( V_220 -> V_228 . V_70 & V_126 ) {
memset ( V_146 , 0 , sizeof( * V_146 ) ) ;
V_146 -> signal = V_229 +
V_220 -> V_228 . V_230 ;
}
if ( V_220 -> V_228 . V_70 & V_231 ) {
V_146 -> V_232 = F_10 ( V_220 -> V_228 . V_233 ) & 0xffffffff ;
V_146 -> V_136 |= V_234 ;
}
V_208 = F_67 ( V_2 -> V_18 , V_146 ) ;
if ( V_208 ) {
F_62 ( V_2 -> V_18 , V_146 -> V_114 ,
V_220 -> V_228 . V_70 ,
F_10 ( V_220 -> V_228 . V_105 ) ,
F_10 ( V_220 -> V_228 . V_115 ) ,
V_146 ) ;
}
F_40 ( V_67 , NULL , L_25 ,
V_220 , sizeof( * V_220 ) +
( sizeof( struct V_221 ) *
V_223 ) ) ;
for ( V_15 = 0 ; V_15 < V_223 ; V_15 ++ ) {
V_117 = V_222 [ V_15 ] . V_235 ;
for ( V_224 = 0 ; V_224 < V_222 [ V_15 ] . V_236 ; V_224 ++ ) {
struct V_11 * V_201 , * V_237 ;
V_201 = NULL ;
V_237 = NULL ;
V_26 = F_39 ( V_2 ,
& V_57 ,
& V_58 ,
& V_201 ,
& V_237 ) ;
if ( V_26 < 0 ) {
F_37 ( L_26 ,
V_26 ) ;
F_38 ( V_201 ) ;
continue;
}
V_102 = F_87 ( ( void * ) V_201 -> V_34 ,
struct V_24 ,
V_68 ) ;
V_35 = F_10 ( V_102 -> V_35 . V_36 ) ;
if ( ! F_83 ( V_2 , V_201 ,
V_117 ,
V_208 ,
V_35 ) ) {
F_38 ( V_201 ) ;
continue;
}
if ( V_26 > 0 &&
F_80 ( V_201 ) < 0 ) {
F_38 ( V_201 ) ;
continue;
}
if ( V_35 & V_238 )
V_146 -> V_136 |= V_161 ;
else
V_146 -> V_136 &= ~ V_161 ;
if ( V_35 & V_239 )
V_146 -> V_136 |= V_162 ;
else
V_146 -> V_136 &= ~ V_162 ;
V_109 = F_58 ( V_201 ) ;
if ( F_59 ( V_109 ) )
F_74 ( V_2 , V_146 , V_201 ) ;
else
F_78 ( V_2 , V_146 , V_201 ) ;
}
}
F_26 ( & V_2 -> V_47 ) ;
}
static void F_88 ( struct V_1 * V_2 ,
struct V_240 * V_241 )
{
struct V_11 * V_201 , * V_237 ;
enum V_92 V_147 ;
struct V_24 * V_102 ;
enum V_103 V_104 ;
struct V_116 * V_146 = & V_2 -> V_146 ;
struct V_101 * V_109 ;
int V_26 ;
bool V_242 ;
bool V_243 ;
T_2 * V_57 ;
int V_58 , V_244 , V_245 ;
int V_246 ;
V_58 = F_66 ( V_241 -> V_226 ) ;
V_57 = ( T_2 * ) V_241 -> V_247 ;
V_201 = NULL ;
V_237 = NULL ;
F_22 ( & V_2 -> V_10 . V_39 ) ;
V_26 = F_39 ( V_2 , & V_57 , & V_58 ,
& V_201 , & V_237 ) ;
F_27 ( & V_2 -> V_10 . V_39 ) ;
F_55 ( V_67 , L_27 ) ;
if ( V_26 ) {
F_37 ( L_28 ,
V_26 ) ;
F_38 ( V_201 ) ;
return;
}
V_146 -> V_136 |= V_248 ;
V_109 = (struct V_101 * ) V_201 -> V_34 ;
V_102 = ( void * ) V_201 -> V_34 - sizeof( * V_102 ) ;
V_242 = ! ! ( F_10 ( V_102 -> V_35 . V_36 ) &
V_239 ) ;
V_243 = ! ! ( F_10 ( V_102 -> V_35 . V_36 ) &
V_210 ) ;
V_104 = F_44 ( F_10 ( V_102 -> V_73 . V_105 ) ,
V_106 ) ;
if ( V_104 != V_107 ) {
F_37 ( L_29 ) ;
F_8 ( V_201 ) ;
goto V_249;
}
V_147 = F_44 ( F_10 ( V_102 -> V_171 . V_70 ) ,
V_172 ) ;
F_64 ( V_2 , V_146 , V_201 , V_147 , V_104 ,
true ) ;
V_201 -> V_175 = F_75 ( V_201 ) ;
if ( V_242 )
F_37 ( L_30 ) ;
if ( V_243 ) {
F_37 ( L_31 ) ;
F_8 ( V_201 ) ;
goto V_249;
}
if ( V_147 != V_100 ) {
V_244 = F_73 ( V_109 -> V_110 ) ;
V_245 = F_56 ( V_147 ) ;
memmove ( ( void * ) V_201 -> V_34 + V_245 ,
( void * ) V_201 -> V_34 ,
V_244 ) ;
F_13 ( V_201 , V_245 ) ;
V_109 = (struct V_101 * ) V_201 -> V_34 ;
}
V_246 = 4 ;
V_246 += F_57 ( V_147 ) ;
if ( ! F_89 ( V_109 -> V_110 ) &&
V_147 == V_97 )
V_246 += 8 ;
if ( V_246 > V_201 -> V_21 ) {
F_37 ( L_32 ) ;
F_8 ( V_201 ) ;
goto V_249;
}
F_45 ( V_201 , V_201 -> V_21 - V_246 ) ;
F_40 ( V_67 , NULL , L_33 ,
V_201 -> V_34 , V_201 -> V_21 ) ;
F_68 ( V_2 -> V_18 , V_146 , V_201 ) ;
V_249:
if ( V_58 > 0 ) {
F_55 ( V_209 ,
L_34 ,
V_58 ) ;
}
}
static void F_90 ( struct V_112 * V_18 ,
struct V_11 * V_12 )
{
struct V_1 * V_2 = & V_18 -> V_2 ;
struct V_250 * V_251 = (struct V_250 * ) V_12 -> V_34 ;
struct V_252 V_253 = {} ;
int V_117 = F_44 ( V_251 -> V_254 . V_36 , V_255 ) ;
T_4 V_256 ;
int V_15 ;
F_20 ( & V_2 -> V_257 ) ;
switch ( V_117 ) {
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
F_37 ( L_35 , V_117 ) ;
V_253 . V_264 = true ;
break;
}
F_55 ( V_209 , L_36 ,
V_251 -> V_254 . V_265 ) ;
for ( V_15 = 0 ; V_15 < V_251 -> V_254 . V_265 ; V_15 ++ ) {
V_256 = V_251 -> V_254 . V_266 [ V_15 ] ;
V_253 . V_256 = F_66 ( V_256 ) ;
F_91 ( V_2 , & V_253 ) ;
}
}
void F_92 ( struct V_112 * V_18 , struct V_11 * V_12 )
{
struct V_1 * V_2 = & V_18 -> V_2 ;
struct V_250 * V_251 = (struct V_250 * ) V_12 -> V_34 ;
if ( ! F_12 ( ( unsigned long ) V_12 -> V_34 , 4 ) )
F_37 ( L_37 ) ;
F_55 ( V_209 , L_38 ,
V_251 -> V_109 . V_267 ) ;
switch ( V_251 -> V_109 . V_267 ) {
case V_268 : {
V_2 -> V_269 = V_251 -> V_270 . V_271 ;
V_2 -> V_272 = V_251 -> V_270 . V_273 ;
F_93 ( & V_2 -> V_274 ) ;
break;
}
case V_275 :
F_22 ( & V_2 -> V_10 . V_39 ) ;
F_94 ( & V_2 -> V_51 , V_12 ) ;
F_27 ( & V_2 -> V_10 . V_39 ) ;
F_26 ( & V_2 -> V_49 ) ;
return;
case V_276 : {
struct V_277 V_278 = {
. V_279 = V_251 -> V_280 . V_279 ,
. V_281 = F_66 ( V_251 -> V_280 . V_281 ) ,
} ;
memcpy ( V_278 . V_167 , V_251 -> V_280 . V_167 , sizeof( V_278 . V_167 ) ) ;
F_95 ( V_2 , & V_278 ) ;
break;
}
case V_282 : {
struct V_283 V_278 = {
. V_281 = F_66 ( V_251 -> V_284 . V_281 ) ,
} ;
F_96 ( V_2 , & V_278 ) ;
break;
}
case V_285 : {
struct V_252 V_253 = {} ;
int V_117 = F_10 ( V_251 -> V_286 . V_117 ) ;
V_253 . V_256 =
F_10 ( V_251 -> V_286 . V_287 ) ;
switch ( V_117 ) {
case V_288 :
break;
case V_289 :
V_253 . V_259 = true ;
break;
case V_290 :
V_253 . V_264 = true ;
break;
}
F_22 ( & V_2 -> V_257 ) ;
F_91 ( V_2 , & V_253 ) ;
F_27 ( & V_2 -> V_257 ) ;
break;
}
case V_291 :
F_22 ( & V_2 -> V_257 ) ;
F_94 ( & V_2 -> V_50 , V_12 ) ;
F_27 ( & V_2 -> V_257 ) ;
F_26 ( & V_2 -> V_49 ) ;
return;
case V_292 : {
struct V_112 * V_18 = V_2 -> V_18 ;
struct V_293 * V_278 = & V_251 -> V_294 ;
F_55 ( V_209 ,
L_39 ,
F_66 ( V_278 -> V_281 ) ,
! ! ( V_278 -> V_36 & V_295 ) ,
F_44 ( V_278 -> V_36 , V_296 ) ) ;
F_93 ( & V_18 -> V_297 ) ;
break;
}
case V_298 : {
F_40 ( V_67 , NULL , L_40 ,
V_12 -> V_34 , V_12 -> V_21 ) ;
F_88 ( V_2 , & V_251 -> V_299 ) ;
break;
}
case V_300 :
break;
case V_301 :
F_97 ( V_12 -> V_34 , V_12 -> V_21 ) ;
break;
case V_302 :
case V_303 :
case V_304 :
case V_305 :
default:
F_55 ( V_209 , L_41 ,
V_251 -> V_109 . V_267 ) ;
F_40 ( V_67 , NULL , L_40 ,
V_12 -> V_34 , V_12 -> V_21 ) ;
break;
} ;
F_8 ( V_12 ) ;
}
static void V_90 ( unsigned long V_80 )
{
struct V_1 * V_2 = (struct V_1 * ) V_80 ;
struct V_250 * V_251 ;
struct V_11 * V_12 ;
F_22 ( & V_2 -> V_257 ) ;
while ( ( V_12 = F_98 ( & V_2 -> V_50 ) ) ) {
F_90 ( V_2 -> V_18 , V_12 ) ;
F_8 ( V_12 ) ;
}
F_27 ( & V_2 -> V_257 ) ;
F_22 ( & V_2 -> V_10 . V_39 ) ;
while ( ( V_12 = F_98 ( & V_2 -> V_51 ) ) ) {
V_251 = (struct V_250 * ) V_12 -> V_34 ;
F_85 ( V_2 , & V_251 -> V_306 ) ;
F_8 ( V_12 ) ;
}
F_27 ( & V_2 -> V_10 . V_39 ) ;
}
