static void F_1 ( struct V_1 * V_2 , unsigned short V_3 )
{
unsigned short V_4 ;
F_2 ( V_3 != V_2 -> V_3 ) ;
V_2 -> V_5 = V_3 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ )
V_2 -> V_6 [ V_4 ] = V_3 - 1 - V_4 ;
}
static unsigned short F_3 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
F_2 ( V_2 -> V_5 <= 0 ) ;
return V_2 -> V_6 [ -- V_2 -> V_5 ] ;
}
static void F_4 ( struct V_7 * V_8 , struct V_1 * V_2 ,
unsigned short V_9 )
{
F_2 ( V_2 -> V_5 >= V_2 -> V_3 ) ;
V_2 -> V_6 [ V_2 -> V_5 ++ ] = V_9 ;
}
static bool F_5 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 == 0 )
return 1 ;
else
return 0 ;
}
static void F_6 ( struct V_10 * V_11 , void * * V_12 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_13 ; V_4 ++ )
if ( ( F_7 ( V_11 , V_4 ) & V_14 ) &&
V_12 [ V_4 ] )
F_8 ( V_11 , V_12 [ V_4 ] ) ;
}
static int F_9 ( struct V_10 * V_11 , void * * V_12 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_13 ; V_4 ++ ) {
if ( F_7 ( V_11 , V_4 ) & V_14 ) {
V_12 [ V_4 ] = F_10 ( V_11 , V_4 , 0 ) ;
if ( ! V_12 [ V_4 ] ) {
F_11 ( & V_11 -> V_11 , L_1 ,
V_4 ) ;
F_6 ( V_11 , V_12 ) ;
return - V_15 ;
}
} else
V_12 [ V_4 ] = NULL ;
F_12 ( & V_11 -> V_11 , L_2 , V_4 , V_12 [ V_4 ] ) ;
}
return 0 ;
}
static struct V_16 * F_13 ( struct V_7 * V_8 ,
enum V_17 type , unsigned int V_3 )
{
struct V_16 * V_18 = F_14 ( sizeof( * V_18 ) , V_19 ) ;
if ( ! V_18 ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_3 ) ;
return NULL ;
}
switch ( type ) {
case V_21 :
V_18 -> V_22 = F_14 ( V_3 , V_19 ) ;
if ( ! V_18 -> V_22 ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_4 , V_3 ) ;
F_15 ( V_18 ) ;
return NULL ;
}
break;
case V_23 :
V_3 = F_16 ( V_3 , 8 ) ;
V_18 -> V_22 = F_17 ( V_8 -> V_20 , V_3 ,
& V_18 -> V_24 ) ;
if ( ! V_18 -> V_22 ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_5
L_6 , V_3 ) ;
F_15 ( V_18 ) ;
return NULL ;
}
memset ( V_18 -> V_22 , 0 , V_3 ) ;
break;
default:
F_11 ( & V_8 -> V_20 -> V_11 , L_7 , type ) ;
F_15 ( V_18 ) ;
return NULL ;
}
V_18 -> type = type ;
V_18 -> V_3 = V_3 ;
F_18 ( & V_18 -> V_25 ) ;
F_19 ( & V_18 -> V_25 , & V_8 -> V_26 ) ;
return V_18 ;
}
static void F_20 ( struct V_7 * V_8 )
{
struct V_16 * V_18 , * V_27 ;
F_21 (res, tmp, &mhba->res_list, entry) {
switch ( V_18 -> type ) {
case V_23 :
F_22 ( V_8 -> V_20 , V_18 -> V_3 ,
V_18 -> V_22 , V_18 -> V_24 ) ;
break;
case V_21 :
F_15 ( V_18 -> V_22 ) ;
break;
default:
F_11 ( & V_8 -> V_20 -> V_11 ,
L_8 , V_18 -> type ) ;
break;
}
F_23 ( & V_18 -> V_25 ) ;
F_15 ( V_18 ) ;
}
V_8 -> V_28 &= ~ V_29 ;
}
static int F_24 ( struct V_7 * V_8 , struct V_30 * V_31 ,
void * V_32 , unsigned char * V_33 )
{
struct V_34 * V_35 ;
struct V_36 * V_37 = (struct V_36 * ) V_32 ;
unsigned int V_4 ;
unsigned int V_38 = F_25 ( V_31 ) ;
T_1 V_39 ;
if ( V_38 ) {
V_35 = F_26 ( V_31 ) ;
* V_33 = F_27 ( V_8 -> V_20 , V_35 , V_38 ,
( int ) V_31 -> V_40 ) ;
if ( * V_33 > V_8 -> V_41 ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_9
L_10 ,
* V_33 , V_8 -> V_41 ) ;
return - 1 ;
}
for ( V_4 = 0 ; V_4 < * V_33 ; V_4 ++ ) {
V_39 = F_28 ( & V_35 [ V_4 ] ) ;
V_37 -> V_42 = F_29 ( F_30 ( V_39 ) ) ;
V_37 -> V_43 = F_29 ( F_31 ( V_39 ) ) ;
V_37 -> V_44 = 0 ;
V_37 -> V_3 = F_29 ( F_32 ( & V_35 [ V_4 ] ) ) ;
if ( ( V_4 + 1 ) == * V_33 )
V_37 -> V_44 |= V_45 ;
V_37 ++ ;
}
} else {
V_31 -> V_46 . V_47 = F_33 ( V_31 ) ?
F_34 ( V_8 -> V_20 , F_26 ( V_31 ) ,
F_33 ( V_31 ) ,
( int ) V_31 -> V_40 )
: 0 ;
V_39 = V_31 -> V_46 . V_47 ;
V_37 -> V_42 = F_29 ( F_30 ( V_39 ) ) ;
V_37 -> V_43 = F_29 ( F_31 ( V_39 ) ) ;
V_37 -> V_44 = V_45 ;
V_37 -> V_3 = F_29 ( F_33 ( V_31 ) ) ;
* V_33 = 1 ;
}
return 0 ;
}
static int F_35 ( struct V_7 * V_8 , struct V_48 * V_49 ,
unsigned int V_3 )
{
struct V_36 * V_37 ;
void * V_22 ;
T_1 V_50 ;
if ( V_3 == 0 )
return 0 ;
V_22 = F_17 ( V_8 -> V_20 , V_3 , & V_50 ) ;
if ( ! V_22 )
return - 1 ;
memset ( V_22 , 0 , V_3 ) ;
V_37 = (struct V_36 * ) & V_49 -> V_51 -> V_52 [ 0 ] ;
V_49 -> V_51 -> V_53 = 1 ;
V_49 -> V_54 = V_22 ;
V_37 -> V_42 = F_29 ( F_30 ( V_50 ) ) ;
V_37 -> V_43 = F_29 ( F_31 ( V_50 ) ) ;
V_37 -> V_44 = V_45 ;
V_37 -> V_3 = F_29 ( V_3 ) ;
return 0 ;
}
static struct V_48 * F_36 ( struct V_7 * V_8 ,
unsigned int V_55 )
{
struct V_48 * V_49 ;
V_49 = F_14 ( sizeof( * V_49 ) , V_19 ) ;
if ( ! V_49 ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_11 ) ;
return NULL ;
}
F_18 ( & V_49 -> V_56 ) ;
V_49 -> V_51 = F_14 ( V_8 -> V_57 , V_19 ) ;
if ( ! V_49 -> V_51 ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_12
L_13 , V_8 -> V_57 ) ;
F_15 ( V_49 ) ;
return NULL ;
}
if ( V_55 ) {
if ( F_35 ( V_8 , V_49 , V_55 ) ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_14
L_15 ) ;
F_15 ( V_49 -> V_51 ) ;
F_15 ( V_49 ) ;
return NULL ;
}
} else
V_49 -> V_51 -> V_53 = 0 ;
return V_49 ;
}
static void F_37 ( struct V_7 * V_8 ,
struct V_48 * V_49 )
{
struct V_36 * V_37 ;
unsigned int V_3 ;
T_1 V_50 ;
if ( V_49 && V_49 -> V_51 ) {
if ( V_49 -> V_51 -> V_53 ) {
V_37 = (struct V_36 * ) & V_49 -> V_51 -> V_52 [ 0 ] ;
V_3 = V_37 -> V_3 ;
V_50 = ( T_1 ) V_37 -> V_42 |
( T_1 ) ( ( V_37 -> V_43 << 16 ) << 16 ) ;
F_22 ( V_8 -> V_20 , V_3 , V_49 -> V_54 ,
V_50 ) ;
}
F_15 ( V_49 -> V_51 ) ;
F_15 ( V_49 ) ;
}
}
static struct V_48 * F_38 ( struct V_7 * V_8 )
{
struct V_48 * V_49 = NULL ;
if ( F_39 ( ! F_40 ( & V_8 -> V_58 ) ) ) {
V_49 = F_41 ( ( & V_8 -> V_58 ) -> V_59 ,
struct V_48 , V_56 ) ;
F_42 ( & V_49 -> V_56 ) ;
} else
F_43 ( & V_8 -> V_20 -> V_11 , L_16 ) ;
return V_49 ;
}
static inline void F_44 ( struct V_7 * V_8 ,
struct V_48 * V_49 )
{
V_49 -> V_31 = NULL ;
F_19 ( & V_49 -> V_56 , & V_8 -> V_58 ) ;
}
static void F_45 ( struct V_7 * V_8 )
{
struct V_48 * V_49 ;
while ( ! F_40 ( & V_8 -> V_58 ) ) {
V_49 = F_46 ( & V_8 -> V_58 , struct V_48 ,
V_56 ) ;
F_23 ( & V_49 -> V_56 ) ;
F_15 ( V_49 -> V_51 ) ;
F_15 ( V_49 ) ;
}
}
static int F_47 ( struct V_7 * V_8 )
{
int V_4 ;
struct V_48 * V_49 ;
for ( V_4 = 0 ; V_4 < V_8 -> V_60 ; V_4 ++ ) {
V_49 = F_14 ( sizeof( * V_49 ) , V_19 ) ;
if ( ! V_49 )
goto V_61;
F_18 ( & V_49 -> V_56 ) ;
F_19 ( & V_49 -> V_56 , & V_8 -> V_58 ) ;
V_49 -> V_51 = F_14 ( V_8 -> V_57 , V_19 ) ;
if ( ! V_49 -> V_51 )
goto V_61;
}
return 0 ;
V_61:
F_11 ( & V_8 -> V_20 -> V_11 ,
L_17 , V_4 ) ;
while ( ! F_40 ( & V_8 -> V_58 ) ) {
V_49 = F_46 ( & V_8 -> V_58 , struct V_48 ,
V_56 ) ;
F_23 ( & V_49 -> V_56 ) ;
F_15 ( V_49 -> V_51 ) ;
F_15 ( V_49 ) ;
}
return - V_15 ;
}
static int F_48 ( struct V_7 * V_8 , void * * V_62 )
{
unsigned int V_63 , V_64 ;
if ( F_49 ( & V_8 -> V_65 ) >= V_8 -> V_60 ) {
F_43 ( & V_8 -> V_20 -> V_11 , L_18 ) ;
return - 1 ;
}
V_63 = F_50 ( V_8 -> V_66 + V_67 ) ;
if ( F_51 ( ( ( V_63 & V_68 ) ==
( V_8 -> V_69 & V_68 ) ) &&
( ( V_63 & V_70 ) !=
( V_8 -> V_69 & V_70 ) ) ) ) {
F_43 ( & V_8 -> V_20 -> V_11 , L_19 ) ;
return - 1 ;
}
V_64 = V_8 -> V_69 & V_68 ;
V_64 ++ ;
if ( V_64 >= V_8 -> V_71 ) {
V_64 -= V_8 -> V_71 ;
V_8 -> V_69 ^= V_70 ;
}
V_8 -> V_69 &= ~ V_68 ;
V_8 -> V_69 |= ( V_64 & V_68 ) ;
* V_62 = V_8 -> V_72 + V_64 * V_8 -> V_57 ;
F_52 ( & V_8 -> V_65 ) ;
return 0 ;
}
static void F_53 ( struct V_7 * V_8 )
{
F_54 ( 0xfff , V_8 -> V_73 ) ;
F_54 ( V_8 -> V_69 , V_8 -> V_66 + V_74 ) ;
}
static char F_55 ( struct V_7 * V_8 ,
unsigned int V_75 , struct V_76 * V_77 )
{
unsigned short V_9 , V_78 ;
F_56 ( 1 ) ;
V_77 = V_8 -> V_79 + V_75 * V_8 -> V_80 ;
V_78 = V_77 -> V_78 ;
V_9 = V_77 -> V_9 ;
if ( V_9 > V_8 -> V_81 . V_3 ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_20 ) ;
return - 1 ;
}
if ( V_8 -> V_82 [ V_9 ] == NULL ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_21 , V_9 ) ;
return - 1 ;
} else if ( V_8 -> V_82 [ V_9 ] -> V_78 != V_78 &&
V_8 -> V_83 ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_22
L_23 , V_78 ,
V_8 -> V_82 [ V_9 ] -> V_78 ) ;
return - 1 ;
}
return 0 ;
}
static void F_57 ( struct V_7 * V_8 )
{
unsigned int V_84 , V_85 ;
unsigned int V_75 , V_86 , V_4 ;
struct V_87 * V_88 ;
struct V_76 * V_77 ;
do {
V_84 = F_50 ( V_8 -> V_66 + V_89 ) ;
V_85 = F_50 ( V_8 -> V_90 ) ;
} while ( ( V_84 & V_68 ) != V_85 );
V_75 = V_8 -> V_91 & V_68 ;
V_86 = V_84 & V_68 ;
if ( ( V_84 & V_70 ) !=
( V_8 -> V_91 & V_70 ) ) {
V_86 += V_8 -> V_71 ;
}
for ( V_4 = ( V_86 - V_75 ) ; V_4 != 0 ; V_4 -- ) {
V_75 ++ ;
if ( V_75 >= V_8 -> V_71 ) {
V_75 -= V_8 -> V_71 ;
V_8 -> V_91 ^= V_70 ;
}
V_77 = V_8 -> V_79 + V_75 * V_8 -> V_80 ;
if ( F_51 ( V_77 -> V_9 > V_8 -> V_81 . V_3 ||
V_8 -> V_82 [ V_77 -> V_9 ] == NULL ||
V_77 -> V_78 !=
V_8 -> V_82 [ V_77 -> V_9 ] -> V_78 ) )
if ( F_55 ( V_8 , V_75 , V_77 ) )
continue;
if ( ! F_40 ( & V_8 -> V_92 ) ) {
V_88 = (struct V_87 * )
F_46 ( & V_8 -> V_92 ,
struct V_87 , V_93 ) ;
F_42 ( & V_88 -> V_93 ) ;
} else {
V_88 = NULL ;
if ( V_75 == 0 ) {
V_75 = V_8 -> V_71 - 1 ;
V_8 -> V_91 ^= V_70 ;
} else
V_75 -= 1 ;
break;
}
memcpy ( V_88 -> V_94 , V_77 , V_8 -> V_80 ) ;
V_77 -> V_9 = 0xff ;
F_19 ( & V_88 -> V_93 , & V_8 -> V_95 ) ;
}
V_8 -> V_91 &= ~ V_68 ;
V_8 -> V_91 |= ( V_75 & V_68 ) ;
F_54 ( V_8 -> V_91 , V_8 -> V_66 + V_96 ) ;
}
static void F_58 ( void * V_97 )
{
F_54 ( 0 , V_97 + V_98 ) ;
if ( F_50 ( V_97 + V_99 ) != V_100 )
return;
F_54 ( V_101 , V_97 + V_102 ) ;
}
static int F_59 ( struct V_7 * V_8 )
{
V_8 -> V_103 = V_104 ;
F_58 ( V_8 -> V_66 ) ;
if ( F_60 ( V_8 ) )
return V_105 ;
else
return V_106 ;
}
static int F_61 ( struct V_30 * V_31 )
{
struct V_7 * V_8 ;
V_8 = (struct V_7 * ) V_31 -> V_107 -> V_108 -> V_109 ;
F_62 ( V_110 , V_31 , L_24 ,
V_31 -> V_111 , V_31 -> V_112 [ 0 ] , V_31 -> V_113 ) ;
return F_59 ( V_8 ) ;
}
static int F_63 ( struct V_7 * V_8 ,
struct V_48 * V_49 )
{
unsigned long V_44 ;
V_49 -> V_114 = V_115 ;
if ( F_49 ( & V_49 -> V_116 ) ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_25 ,
F_49 ( & V_49 -> V_116 ) ) ;
F_2 ( 1 ) ;
return - 1 ;
}
F_52 ( & V_49 -> V_116 ) ;
F_64 ( V_8 -> V_117 -> V_118 , V_44 ) ;
V_8 -> V_119 -> V_120 ( V_8 , V_49 ) ;
F_65 ( V_8 -> V_117 -> V_118 , V_44 ) ;
F_66 ( V_8 -> V_121 ,
( V_49 -> V_114 != V_115 ) ,
V_122 * V_123 ) ;
if ( F_49 ( & V_49 -> V_116 ) ) {
F_64 ( V_8 -> V_117 -> V_118 , V_44 ) ;
F_67 ( & V_49 -> V_116 ) ;
if ( V_8 -> V_82 [ V_49 -> V_51 -> V_9 ] ) {
V_8 -> V_82 [ V_49 -> V_51 -> V_9 ] = 0 ;
F_43 ( & V_8 -> V_20 -> V_11 , L_26 ,
V_49 -> V_51 -> V_9 ) ;
F_4 ( V_8 , & V_8 -> V_81 , V_49 -> V_51 -> V_9 ) ;
}
if ( ! F_40 ( & V_49 -> V_56 ) ) {
F_43 ( & V_8 -> V_20 -> V_11 ,
L_27 ) ;
F_42 ( & V_49 -> V_56 ) ;
} else
F_67 ( & V_8 -> V_65 ) ;
F_65 ( V_8 -> V_117 -> V_118 , V_44 ) ;
}
return 0 ;
}
static void F_68 ( struct V_7 * V_8 )
{
F_45 ( V_8 ) ;
F_20 ( V_8 ) ;
F_6 ( V_8 -> V_20 , V_8 -> V_124 ) ;
F_15 ( V_8 -> V_125 ) ;
F_69 ( V_8 -> V_20 ) ;
}
static unsigned char F_70 ( struct V_7 * V_8 )
{
struct V_48 * V_49 ;
struct V_126 * V_51 ;
unsigned char V_127 , V_128 = 0 ;
unsigned char V_129 = sizeof( unsigned char ) * 8 ;
for ( V_127 = 0 ; V_127 < V_8 -> V_130 ; V_127 ++ ) {
if ( ! ( V_8 -> V_131 [ V_127 / V_129 ] &
( 1 << ( V_127 % V_129 ) ) ) )
continue;
V_132: V_49 = F_36 ( V_8 , 0 ) ;
if ( ! V_49 ) {
if ( V_128 ++ >= 5 ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_28
L_29
L_30 , V_127 ) ;
V_128 = 0 ;
continue;
} else
goto V_132;
}
V_49 -> V_31 = NULL ;
V_49 -> V_114 = V_115 ;
F_71 ( & V_49 -> V_116 , 0 ) ;
V_51 = V_49 -> V_51 ;
V_51 -> V_133 = V_134 ;
V_51 -> V_127 = V_127 ;
V_51 -> V_135 = V_136 ;
V_51 -> V_137 = 0 ;
V_51 -> V_138 = V_139 ;
memset ( V_51 -> V_140 , 0 , V_139 ) ;
V_51 -> V_140 [ 0 ] = V_141 ;
V_51 -> V_140 [ 2 ] = V_142 ;
F_63 ( V_8 , V_49 ) ;
if ( V_49 -> V_114 != V_143 ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_31 ,
V_127 , V_49 -> V_114 ) ;
}
F_37 ( V_8 , V_49 ) ;
}
return 0 ;
}
static unsigned char
F_72 ( struct V_144 * V_145 ,
unsigned short V_146 )
{
unsigned char * V_147 ;
unsigned char V_148 = 0 , V_4 ;
V_147 = ( unsigned char * ) V_145 -> V_149 ;
for ( V_4 = 0 ; V_4 < V_146 ; V_4 ++ ) {
V_148 ^= * V_147 ;
V_147 ++ ;
}
return V_148 ;
}
void F_73 ( struct V_7 * V_8 ,
struct V_144 * V_150 )
{
struct V_151 * V_152 ;
struct V_153 * V_154 ;
struct V_155 * V_156 ;
struct V_157 time ;
unsigned int V_158 ;
switch ( V_150 -> V_159 ) {
case V_160 :
V_152 = (struct V_151 * ) V_150 ;
V_150 -> V_161 = sizeof( * V_152 ) - 4 ;
memset ( V_150 -> V_149 , 0 , V_150 -> V_161 ) ;
V_152 -> V_162 = 3 ;
V_152 -> V_163 . V_164 = V_165 ;
V_152 -> V_163 . V_166 = V_167 ;
V_152 -> V_163 . V_168 = V_169 ;
V_152 -> V_163 . V_170 = V_171 ;
V_152 -> V_172 = 0 ;
V_152 -> V_173 = 0 ;
V_152 -> V_174 = 0 ;
V_152 -> V_175 = 0 ;
F_74 ( & time ) ;
V_158 = ( unsigned int ) ( time . V_176 -
( V_177 . V_178 * 60 ) ) ;
V_152 -> V_179 = V_158 ;
V_150 -> V_180 = F_72 ( V_150 ,
V_150 -> V_161 ) ;
break;
case V_181 :
V_156 = (struct V_155 * ) V_150 ;
V_150 -> V_161 = sizeof( * V_156 ) - 4 ;
memset ( V_150 -> V_149 , 0 , V_150 -> V_161 ) ;
V_150 -> V_180 = F_72 ( V_150 ,
V_150 -> V_161 ) ;
break;
case V_182 :
V_154 = (struct V_153 * ) V_150 ;
V_150 -> V_161 = sizeof( * V_154 ) - 4 ;
memset ( V_150 -> V_149 , 0 , V_150 -> V_161 ) ;
V_154 -> V_183 = F_30 ( V_8 -> V_184 ) ;
V_154 -> V_185 = F_31 ( V_8 -> V_184 ) ;
V_154 -> V_186 = F_30 ( V_8 -> V_187 ) ;
V_154 -> V_188 = F_31 ( V_8 -> V_187 ) ;
V_154 -> V_189 = V_8 -> V_190 ;
V_154 -> V_191 = V_8 -> V_192 ;
V_154 -> V_193 = V_8 -> V_71 ;
V_154 -> V_194 = V_8 -> V_71 ;
V_150 -> V_180 = F_72 ( V_150 ,
V_150 -> V_161 ) ;
break;
default:
F_11 ( & V_8 -> V_20 -> V_11 , L_32 ,
V_150 -> V_159 ) ;
break;
}
}
static int F_75 ( struct V_7 * V_8 )
{
struct V_87 * V_195 ;
struct V_16 * V_196 ;
unsigned int V_197 , V_198 , V_4 ;
void * V_199 , * V_200 ;
T_1 V_201 ;
if ( V_8 -> V_28 & V_29 )
return 0 ;
V_197 = V_8 -> V_57 * V_8 -> V_60 ;
V_197 += 128 + V_8 -> V_80 * V_8 -> V_60 ;
V_197 += 8 + sizeof( V_202 ) + 16 ;
V_196 = F_13 ( V_8 ,
V_23 , V_197 ) ;
if ( ! V_196 ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_33 ) ;
goto V_203;
}
V_201 = V_196 -> V_24 ;
V_200 = V_196 -> V_22 ;
V_198 = F_16 ( V_201 , 128 ) - V_201 ;
V_201 += V_198 ;
V_200 += V_198 ;
V_8 -> V_72 = V_200 ;
V_8 -> V_184 = V_201 ;
V_200 += V_8 -> V_57 * V_8 -> V_60 ;
V_201 += V_8 -> V_57 * V_8 -> V_60 ;
V_198 = F_16 ( V_201 , 8 ) - V_201 ;
V_201 += V_198 ;
V_200 += V_198 ;
V_8 -> V_73 = V_200 ;
V_8 -> V_204 = V_201 ;
V_201 += sizeof( V_202 ) ;
V_200 += sizeof( V_202 ) ;
V_198 = F_16 ( V_201 , 8 ) - V_201 ;
V_201 += V_198 ;
V_200 += V_198 ;
V_8 -> V_90 = V_200 ;
V_8 -> V_205 = V_201 ;
V_201 += 8 ;
V_200 += 8 ;
V_198 = F_16 ( V_201 , 128 ) - V_201 ;
V_201 += V_198 ;
V_200 += V_198 ;
V_8 -> V_79 = V_200 ;
V_8 -> V_187 = V_201 ;
V_197 = V_8 -> V_60 * ( V_8 -> V_80 + sizeof( * V_195 ) ) ;
V_197 = F_16 ( V_197 , 8 ) ;
V_196 = F_13 ( V_8 ,
V_21 , V_197 ) ;
if ( ! V_196 ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_34 ) ;
goto V_203;
}
V_199 = V_196 -> V_22 ;
for ( V_4 = V_8 -> V_60 ; V_4 != 0 ; V_4 -- ) {
V_195 = (struct V_87 * ) V_199 ;
F_19 ( & V_195 -> V_93 , & V_8 -> V_92 ) ;
V_199 += V_8 -> V_80 + sizeof( * V_195 ) ;
}
V_197 = sizeof( unsigned short ) * V_8 -> V_60 +
sizeof( struct V_48 * ) * V_8 -> V_60 ;
V_197 += F_16 ( V_8 -> V_130 , sizeof( unsigned char ) * 8 ) /
(sizeof( unsigned char ) * 8 ) ;
V_196 = F_13 ( V_8 ,
V_21 , V_197 ) ;
if ( ! V_196 ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_35 ) ;
goto V_203;
}
V_199 = V_196 -> V_22 ;
V_8 -> V_81 . V_6 = V_199 ;
V_8 -> V_81 . V_3 = V_8 -> V_60 ;
F_1 ( & V_8 -> V_81 , V_8 -> V_60 ) ;
V_199 += sizeof( unsigned short ) * V_8 -> V_60 ;
V_8 -> V_82 = V_199 ;
V_199 += sizeof( struct V_48 * ) * V_8 -> V_60 ;
V_8 -> V_131 = V_199 ;
V_8 -> V_28 |= V_29 ;
return 0 ;
V_203:
F_20 ( V_8 ) ;
return - 1 ;
}
static int F_76 ( struct V_7 * V_8 ,
struct V_144 * V_150 )
{
struct V_206 * V_207 ;
unsigned char V_208 ;
V_208 = F_72 ( V_150 ,
V_150 -> V_161 ) ;
if ( V_208 != V_150 -> V_180 ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_36 ) ;
return - 1 ;
}
switch ( V_150 -> V_159 ) {
case V_209 :
V_207 = (struct V_206 * ) V_150 ;
V_8 -> V_60 = V_207 -> V_210 ;
V_8 -> V_71 = V_207 -> V_211 ;
V_8 -> V_212 = V_207 -> V_212 ;
V_8 -> V_130 = V_207 -> V_213 ;
V_8 -> V_214 = V_207 -> V_215 ;
V_8 -> V_190 = V_207 -> V_216 ;
V_8 -> V_57 = ( 1 << V_207 -> V_216 ) << 2 ;
V_8 -> V_192 = V_207 -> V_217 ;
V_8 -> V_80 = ( 1 << V_207 -> V_217 ) << 2 ;
F_12 ( & V_8 -> V_20 -> V_11 , L_37 ,
V_207 -> V_218 . V_170 ) ;
break;
default:
F_11 ( & V_8 -> V_20 -> V_11 , L_38 ) ;
return - 1 ;
}
return 0 ;
}
static int F_77 ( struct V_7 * V_8 )
{
unsigned int V_219 , V_27 , V_220 ;
struct V_144 * V_150 ;
void * V_97 = V_8 -> V_66 ;
if ( V_8 -> V_103 == V_221 )
V_219 = V_222 ;
else {
V_27 = F_50 ( V_97 + V_223 ) ;
V_219 = F_78 ( V_27 ) ;
F_12 ( & V_8 -> V_20 -> V_11 , L_39 , V_219 ) ;
if ( F_79 ( V_27 ) != V_224 ) {
V_8 -> V_103 = V_221 ;
return - 1 ;
}
}
V_220 = 0 ;
switch ( V_219 ) {
case V_222 :
V_8 -> V_103 = V_225 ;
F_80 ( V_220 , V_224 ) ;
F_81 ( V_220 , V_226 ) ;
F_54 ( V_227 , V_97 + V_228 ) ;
F_54 ( V_220 , V_97 + V_229 ) ;
F_54 ( V_230 , V_97 + V_102 ) ;
break;
case V_226 :
F_54 ( F_30 ( V_8 -> V_231 ) ,
V_97 + V_228 ) ;
F_54 ( F_31 ( V_8 -> V_231 ) ,
V_97 + V_99 ) ;
F_80 ( V_220 , V_224 ) ;
F_81 ( V_220 , V_232 ) ;
F_54 ( V_220 , V_97 + V_229 ) ;
F_54 ( V_230 , V_97 + V_102 ) ;
break;
case V_232 :
case V_233 :
case V_234 :
V_150 = (struct V_144 * ) V_8 -> V_125 ;
if ( V_150 -> V_159 == V_209 ) {
V_8 -> V_235 =
( (struct V_206 * ) V_150 ) -> V_236 ;
if ( V_8 -> V_235 == 0 )
V_8 -> V_235 = V_237 - 1 ;
}
if ( V_219 == V_233 ) {
if ( F_76 ( V_8 , V_150 ) ) {
F_81 ( V_220 , V_238 ) ;
return - 1 ;
}
if ( F_75 ( V_8 ) ) {
F_81 ( V_220 , V_238 ) ;
return - 1 ;
}
} else if ( V_219 == V_232 ) {
V_150 -> V_159 = 0 ;
V_8 -> V_235 = V_237 - 1 ;
}
if ( ( V_150 -> V_159 + 1 ) <= V_8 -> V_235 ) {
V_150 -> V_159 ++ ;
if ( V_150 -> V_159 != V_209 ) {
F_73 ( V_8 , V_150 ) ;
F_81 ( V_220 , V_234 ) ;
} else
F_81 ( V_220 , V_233 ) ;
} else
F_81 ( V_220 , V_239 ) ;
F_80 ( V_220 , V_224 ) ;
F_54 ( V_220 , V_97 + V_229 ) ;
F_54 ( V_230 , V_97 + V_102 ) ;
break;
case V_239 :
V_27 = F_50 ( V_97 + V_98 ) ;
V_27 |= V_240 | V_241 ;
F_54 ( V_27 , V_97 + V_98 ) ;
F_54 ( V_8 -> V_71 , V_8 -> V_73 ) ;
F_54 ( F_30 ( V_8 -> V_204 ) ,
V_97 + V_242 ) ;
F_54 ( F_31 ( V_8 -> V_204 ) ,
V_97 + V_243 ) ;
F_54 ( ( V_8 -> V_71 - 1 ) | V_70 ,
V_8 -> V_90 ) ;
F_54 ( F_30 ( V_8 -> V_205 ) , V_97 + 0x5B0 ) ;
F_54 ( F_31 ( V_8 -> V_205 ) , V_97 + 0x5B4 ) ;
V_8 -> V_69 = ( V_8 -> V_71 - 1 ) | V_70 ;
V_8 -> V_91 = ( V_8 -> V_71 - 1 ) | V_70 ;
V_8 -> V_103 = V_244 ;
break;
default:
F_11 ( & V_8 -> V_20 -> V_11 , L_40 ,
V_219 ) ;
return - 1 ;
}
return 0 ;
}
static unsigned char F_82 ( struct V_7 * V_8 )
{
unsigned int V_245 ;
unsigned long V_246 ;
V_246 = V_247 ;
F_77 ( V_8 ) ;
do {
V_245 = V_8 -> V_119 -> V_248 ( V_8 -> V_66 ) ;
if ( V_8 -> V_103 == V_244 )
return 0 ;
if ( F_83 ( V_247 , V_246 + V_249 * V_123 ) ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_41 ,
V_8 -> V_103 ) ;
F_11 ( & V_8 -> V_20 -> V_11 ,
L_42 ,
V_8 -> V_250 , V_245 ) ;
return - 1 ;
}
F_84 () ;
F_85 ( 1000 , 2000 ) ;
} while ( ! ( V_245 & V_251 ) );
return 0 ;
}
static unsigned char F_86 ( struct V_7 * V_8 )
{
void * V_97 = V_8 -> V_66 ;
unsigned int V_27 ;
unsigned long V_246 ;
V_246 = V_247 ;
V_27 = F_50 ( V_97 + V_99 ) ;
while ( ( V_27 != V_252 ) && ( V_27 != V_100 ) ) {
if ( V_27 != V_252 )
F_54 ( V_253 ,
V_97 + V_102 ) ;
if ( F_83 ( V_247 , V_246 + V_249 * V_123 ) ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_43 , V_27 ) ;
return - 1 ;
}
F_85 ( 1000 , 2000 ) ;
F_84 () ;
V_27 = F_50 ( V_97 + V_99 ) ;
}
V_8 -> V_103 = V_221 ;
F_12 ( & V_8 -> V_20 -> V_11 , L_44 ) ;
do {
if ( F_82 ( V_8 ) ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_45 ,
V_8 -> V_103 ) ;
return - 1 ;
}
} while ( V_8 -> V_103 != V_244 );
F_12 ( & V_8 -> V_20 -> V_11 , L_46 ) ;
return 0 ;
}
static unsigned char F_60 ( struct V_7 * V_8 )
{
void * V_97 = V_8 -> V_66 ;
unsigned int V_27 ;
V_27 = F_50 ( V_97 + V_254 ) ;
F_54 ( V_27 , V_97 + V_254 ) ;
F_54 ( 0x3FFFFFFF , V_97 + V_255 ) ;
V_27 = F_50 ( V_97 + V_98 ) | V_256 ;
F_54 ( V_27 , V_97 + V_98 ) ;
if ( F_86 ( V_8 ) )
return - 1 ;
return 0 ;
}
static void F_87 ( struct V_7 * V_8 , struct V_48 * V_49 ,
struct V_76 * V_257 )
{
struct V_30 * V_31 = V_49 -> V_31 ;
V_49 -> V_31 -> V_46 . V_147 = NULL ;
V_31 -> V_258 = V_257 -> V_259 ;
switch ( V_257 -> V_259 ) {
case V_143 :
V_31 -> V_258 |= V_260 << 16 ;
break;
case V_261 :
V_31 -> V_258 |= V_262 << 16 ;
break;
case V_263 :
V_31 -> V_258 |= ( V_260 << 16 ) ;
if ( V_257 -> V_264 & V_265 ) {
memcpy ( V_49 -> V_31 -> V_266 , V_257 -> V_52 ,
sizeof( struct V_267 ) ) ;
V_31 -> V_258 |= ( V_268 << 24 ) ;
}
break;
default:
V_31 -> V_258 |= ( V_269 << 24 ) | ( V_270 << 16 ) ;
break;
}
if ( F_33 ( V_31 ) ) {
if ( F_25 ( V_31 ) ) {
F_88 ( V_8 -> V_20 ,
F_26 ( V_31 ) ,
F_25 ( V_31 ) ,
( int ) V_31 -> V_40 ) ;
} else {
F_89 ( V_8 -> V_20 ,
V_31 -> V_46 . V_47 ,
F_33 ( V_31 ) ,
( int ) V_31 -> V_40 ) ;
V_31 -> V_46 . V_47 = 0 ;
}
}
V_49 -> V_31 -> V_271 ( V_31 ) ;
F_44 ( V_8 , V_49 ) ;
}
static void F_90 ( struct V_7 * V_8 ,
struct V_48 * V_49 ,
struct V_76 * V_257 )
{
if ( F_49 ( & V_49 -> V_116 ) ) {
V_49 -> V_114 = V_257 -> V_259 ;
if ( ( V_257 -> V_259 == V_263 ) &&
( V_257 -> V_264 & V_265 ) &&
V_49 -> V_54 ) {
memcpy ( V_49 -> V_54 , V_257 -> V_52 ,
sizeof( struct V_267 ) ) ;
}
F_67 ( & V_49 -> V_116 ) ;
F_91 ( & V_8 -> V_121 ) ;
}
}
static void F_92 ( struct V_7 * V_8 ,
struct V_272 * V_147 )
{
unsigned int V_4 ;
F_43 ( & V_8 -> V_20 -> V_11 ,
L_47 ,
V_147 -> V_273 , V_147 -> V_274 , V_147 -> V_275 , V_147 -> V_127 ) ;
if ( V_147 -> V_276 ) {
F_93 ( V_277 L_48 ,
V_147 -> V_276 ) ;
for ( V_4 = 0 ; V_4 < V_147 -> V_276 ; V_4 ++ )
F_93 ( V_277 L_49 , V_147 -> V_278 [ V_4 ] ) ;
F_93 ( V_277 L_50 ) ;
}
if ( V_147 -> V_279 ) {
F_93 ( V_277 L_51 ,
V_147 -> V_279 ) ;
for ( V_4 = 0 ; V_4 < V_147 -> V_279 ; V_4 ++ )
F_93 ( V_277 L_49 , V_147 -> V_280 [ V_4 ] ) ;
F_93 ( V_277 L_50 ) ;
}
}
static void F_94 ( struct V_7 * V_8 , T_2 V_281 , void * V_282 )
{
if ( V_281 == V_283 ) {
int V_4 , V_284 ;
struct V_272 * V_285 = NULL ;
struct V_286 * V_287 = V_282 ;
V_284 = V_287 -> V_284 ;
if ( V_284 > V_288 ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_52
L_53 ,
V_284 , V_288 ) ;
return;
}
for ( V_4 = 0 ; V_4 < V_284 ; V_4 ++ ) {
V_285 = & V_287 -> V_289 [ V_4 ] ;
F_92 ( V_8 , V_285 ) ;
}
}
}
static int F_95 ( struct V_7 * V_8 , unsigned char V_281 )
{
struct V_48 * V_49 ;
struct V_126 * V_51 ;
V_49 = F_36 ( V_8 , 512 ) ;
if ( ! V_49 )
return - 1 ;
V_49 -> V_31 = NULL ;
V_49 -> V_114 = V_115 ;
F_71 ( & V_49 -> V_116 , 0 ) ;
V_51 = V_49 -> V_51 ;
V_51 -> V_127 = 0 ;
V_51 -> V_135 = V_290 ;
V_51 -> V_133 = V_134 ;
V_51 -> V_138 = V_139 ;
V_51 -> V_137 = sizeof( struct V_286 ) ;
memset ( V_51 -> V_140 , 0 , V_139 ) ;
V_51 -> V_140 [ 0 ] = V_291 ;
V_51 -> V_140 [ 1 ] = V_281 ;
F_63 ( V_8 , V_49 ) ;
if ( V_49 -> V_114 != V_143 )
F_11 ( & V_8 -> V_20 -> V_11 , L_54 ,
V_49 -> V_114 ) ;
else
F_94 ( V_8 , V_49 -> V_51 -> V_140 [ 1 ] , V_49 -> V_54 ) ;
F_37 ( V_8 , V_49 ) ;
return 0 ;
}
static void F_96 ( struct V_292 * V_293 )
{
struct V_294 * V_295 =
F_97 ( V_293 , struct V_294 , V_296 ) ;
F_95 ( V_295 -> V_8 , V_295 -> V_297 ) ;
F_15 ( V_295 ) ;
}
static void F_98 ( struct V_7 * V_8 , T_2 V_281 )
{
struct V_294 * V_295 ;
V_295 = F_14 ( sizeof( * V_295 ) , V_298 ) ;
if ( V_295 ) {
F_99 ( & V_295 -> V_296 , F_96 ) ;
V_295 -> V_8 = V_8 ;
V_295 -> V_297 = V_281 ;
V_295 -> V_285 = NULL ;
F_100 ( & V_295 -> V_296 ) ;
}
}
static void F_101 ( struct V_7 * V_8 )
{
struct V_76 * V_257 ;
struct V_48 * V_49 ;
struct V_87 * V_299 ;
while ( ! F_40 ( & V_8 -> V_95 ) ) {
V_299 = F_46 ( & V_8 -> V_95 ,
struct V_87 , V_93 ) ;
F_42 ( & V_299 -> V_93 ) ;
F_19 ( & V_299 -> V_93 , & V_8 -> V_92 ) ;
V_257 = (struct V_76 * ) & V_299 -> V_94 [ 0 ] ;
V_49 = V_8 -> V_82 [ V_257 -> V_9 ] ;
F_67 ( & V_8 -> V_65 ) ;
V_8 -> V_82 [ V_257 -> V_9 ] = 0 ;
F_4 ( V_8 , & V_8 -> V_81 , V_257 -> V_9 ) ;
if ( V_49 -> V_31 )
F_87 ( V_8 , V_49 , V_257 ) ;
else
F_90 ( V_8 , V_49 , V_257 ) ;
}
V_8 -> V_119 -> V_120 ( V_8 , NULL ) ;
}
static T_3 F_102 ( int V_300 , void * V_301 )
{
struct V_7 * V_8 = (struct V_7 * ) V_301 ;
unsigned long V_44 ;
F_64 ( V_8 -> V_117 -> V_118 , V_44 ) ;
if ( F_51 ( V_8 -> V_119 -> V_302 ( V_8 ) || ! V_8 -> V_250 ) ) {
F_65 ( V_8 -> V_117 -> V_118 , V_44 ) ;
return V_303 ;
}
if ( V_8 -> V_250 & V_256 ) {
if ( V_8 -> V_245 & V_251 ) {
F_43 ( & V_8 -> V_20 -> V_11 , L_55 ) ;
F_77 ( V_8 ) ;
}
if ( V_8 -> V_245 & V_304 )
F_98 ( V_8 , V_283 ) ;
}
if ( V_8 -> V_250 & V_240 )
F_57 ( V_8 ) ;
V_8 -> V_250 = 0 ;
V_8 -> V_245 = 0 ;
if ( V_8 -> V_103 == V_244 )
F_101 ( V_8 ) ;
F_65 ( V_8 -> V_117 -> V_118 , V_44 ) ;
return V_305 ;
}
static enum V_306 F_103 ( struct V_7 * V_8 ,
struct V_48 * V_49 )
{
void * V_62 ;
struct V_126 * V_307 ;
unsigned int V_308 ;
V_307 = V_49 -> V_51 ;
if ( F_51 ( V_8 -> V_103 != V_244 ) ) {
F_12 ( & V_8 -> V_20 -> V_11 , L_56 ) ;
return V_309 ;
}
if ( F_5 ( & V_8 -> V_81 ) ) {
F_12 ( & V_8 -> V_20 -> V_11 , L_57 ) ;
return V_309 ;
}
if ( F_48 ( V_8 , & V_62 ) )
return V_309 ;
V_49 -> V_51 -> V_9 = F_3 ( V_8 , & V_8 -> V_81 ) ;
V_49 -> V_51 -> V_78 = V_8 -> V_310 ++ ;
V_49 -> V_78 = V_49 -> V_51 -> V_78 ;
V_8 -> V_82 [ V_49 -> V_51 -> V_9 ] = V_49 ;
V_308 = sizeof( * V_307 ) - 4 +
V_307 -> V_53 * sizeof( struct V_36 ) ;
memcpy ( V_62 , V_307 , V_308 ) ;
return V_311 ;
}
static void F_104 ( struct V_7 * V_8 , struct V_48 * V_49 )
{
unsigned short V_312 = 0 ;
enum V_306 V_258 ;
if ( V_49 )
F_19 ( & V_49 -> V_56 , & V_8 -> V_313 ) ;
while ( ! F_40 ( & V_8 -> V_313 ) ) {
V_49 = F_46 ( & V_8 -> V_313 ,
struct V_48 , V_56 ) ;
F_42 ( & V_49 -> V_56 ) ;
V_258 = F_103 ( V_8 , V_49 ) ;
switch ( V_258 ) {
case V_311 :
V_312 ++ ;
break;
case V_309 :
F_105 ( & V_49 -> V_56 , & V_8 -> V_313 ) ;
if ( V_312 > 0 )
F_53 ( V_8 ) ;
return;
}
}
if ( V_312 > 0 )
F_53 ( V_8 ) ;
}
static void F_106 ( void * V_97 )
{
unsigned int V_314 ;
F_54 ( 0x3FFFFFFF , V_97 + V_255 ) ;
V_314 = F_50 ( V_97 + V_98 ) ;
V_314 |= V_256 | V_240 | V_241 ;
F_54 ( V_314 , V_97 + V_98 ) ;
}
static void F_107 ( void * V_97 )
{
unsigned int V_314 ;
F_54 ( 0 , V_97 + V_255 ) ;
V_314 = F_50 ( V_97 + V_98 ) ;
V_314 &= ~ ( V_256 | V_240 | V_241 ) ;
F_54 ( V_314 , V_97 + V_98 ) ;
}
static int F_108 ( void * V_315 )
{
struct V_7 * V_8 = (struct V_7 * ) V_315 ;
unsigned int V_316 , V_245 = 0 , V_27 = 0 ;
void * V_97 = V_8 -> V_66 ;
V_316 = F_50 ( V_97 + V_317 ) ;
if ( ! ( V_316 & V_318 ) || V_316 == 0xFFFFFFFF )
return 1 ;
if ( F_51 ( V_316 & V_241 ) ) {
V_27 = F_50 ( V_97 + V_319 ) ;
if ( V_27 & ( V_320 | V_321 ) )
F_54 ( V_27 & ( V_320 | V_321 ) ,
V_97 + V_319 ) ;
V_316 ^= V_241 ;
}
if ( V_316 & V_240 ) {
V_27 = F_50 ( V_97 + V_319 ) ;
if ( V_27 & V_322 )
F_54 ( V_27 & V_322 , V_97 + V_319 ) ;
}
if ( V_316 & V_256 ) {
V_245 = F_50 ( V_97 + V_254 ) ;
if ( V_245 )
F_54 ( V_245 , V_97 + V_254 ) ;
}
V_8 -> V_250 = V_316 ;
V_8 -> V_245 = V_245 ;
return 0 ;
}
static unsigned int F_109 ( void * V_97 )
{
unsigned int V_316 ;
V_316 = F_50 ( V_97 + V_254 ) ;
if ( V_316 )
F_54 ( V_316 , V_97 + V_254 ) ;
return V_316 ;
}
static int F_110 ( struct V_323 * V_324 )
{
struct V_7 * V_8 ;
unsigned char V_129 = sizeof( unsigned char ) * 8 ;
V_8 = (struct V_7 * ) V_324 -> V_108 -> V_109 ;
if ( V_324 -> V_325 >= V_8 -> V_130 )
return - V_326 ;
V_8 -> V_131 [ V_324 -> V_325 / V_129 ] |= ( 1 << ( V_324 -> V_325 % V_129 ) ) ;
return 0 ;
}
static unsigned char F_111 ( struct V_7 * V_8 ,
struct V_30 * V_31 , struct V_48 * V_49 )
{
struct V_126 * V_327 ;
V_49 -> V_31 = V_31 ;
V_49 -> V_114 = V_115 ;
V_327 = V_49 -> V_51 ;
V_327 -> V_127 = ( ( unsigned short ) V_31 -> V_107 -> V_325 ) |
( ( ( unsigned short ) V_31 -> V_107 -> V_328 ) << 8 ) ;
V_327 -> V_135 = 0 ;
switch ( V_31 -> V_40 ) {
case V_329 :
V_327 -> V_135 |= V_136 ;
break;
case V_330 :
V_327 -> V_135 |= V_290 ;
break;
case V_331 :
V_327 -> V_135 |= V_332 ;
break;
case V_333 :
default:
F_43 ( & V_8 -> V_20 -> V_11 , L_58
L_59 , V_31 -> V_40 , V_31 -> V_112 [ 0 ] ) ;
goto error;
}
V_327 -> V_138 = V_31 -> V_334 ;
memcpy ( V_327 -> V_140 , V_31 -> V_112 , V_327 -> V_138 ) ;
V_327 -> V_133 = V_134 ;
if ( F_33 ( V_31 ) ) {
if ( F_24 ( V_8 , V_31 , & V_327 -> V_52 [ 0 ] ,
& V_327 -> V_53 ) )
goto error;
V_327 -> V_137 = F_33 ( V_31 ) ;
} else {
V_327 -> V_53 = 0 ;
V_327 -> V_137 = 0 ;
}
return 0 ;
error:
V_31 -> V_258 = ( V_260 << 16 ) | ( V_268 << 24 ) |
V_263 ;
F_112 ( 0 , V_31 -> V_266 , V_335 , 0x24 ,
0 ) ;
return - 1 ;
}
static int F_113 ( struct V_336 * V_117 ,
struct V_30 * V_31 )
{
struct V_48 * V_49 ;
struct V_7 * V_8 ;
unsigned long V_337 ;
F_64 ( V_117 -> V_118 , V_337 ) ;
F_114 ( V_117 , V_31 ) ;
V_8 = (struct V_7 * ) V_117 -> V_109 ;
V_31 -> V_258 = 0 ;
V_49 = F_38 ( V_8 ) ;
if ( F_51 ( ! V_49 ) ) {
F_65 ( V_117 -> V_118 , V_337 ) ;
return V_338 ;
}
if ( F_51 ( F_111 ( V_8 , V_31 , V_49 ) ) )
goto V_339;
V_49 -> V_31 = V_31 ;
V_31 -> V_46 . V_147 = ( char * ) V_49 ;
V_8 -> V_119 -> V_120 ( V_8 , V_49 ) ;
F_65 ( V_117 -> V_118 , V_337 ) ;
return 0 ;
V_339:
F_44 ( V_8 , V_49 ) ;
V_31 -> V_271 ( V_31 ) ;
F_65 ( V_117 -> V_118 , V_337 ) ;
return 0 ;
}
static enum V_340 F_115 ( struct V_30 * V_31 )
{
struct V_48 * V_49 = (struct V_48 * ) V_31 -> V_46 . V_147 ;
struct V_336 * V_108 = V_31 -> V_107 -> V_108 ;
struct V_7 * V_8 = F_116 ( V_108 ) ;
unsigned long V_44 ;
F_64 ( V_8 -> V_117 -> V_118 , V_44 ) ;
if ( V_8 -> V_82 [ V_49 -> V_51 -> V_9 ] ) {
V_8 -> V_82 [ V_49 -> V_51 -> V_9 ] = 0 ;
F_4 ( V_8 , & V_8 -> V_81 , V_49 -> V_51 -> V_9 ) ;
}
if ( ! F_40 ( & V_49 -> V_56 ) )
F_42 ( & V_49 -> V_56 ) ;
else
F_67 ( & V_8 -> V_65 ) ;
V_31 -> V_258 = ( V_269 << 24 ) | ( V_270 << 16 ) ;
V_31 -> V_46 . V_147 = NULL ;
if ( F_33 ( V_31 ) ) {
if ( F_25 ( V_31 ) ) {
F_88 ( V_8 -> V_20 ,
F_26 ( V_31 ) ,
F_25 ( V_31 ) ,
( int ) V_31 -> V_40 ) ;
} else {
F_89 ( V_8 -> V_20 ,
V_31 -> V_46 . V_47 ,
F_33 ( V_31 ) ,
( int ) V_31 -> V_40 ) ;
V_31 -> V_46 . V_47 = 0 ;
}
}
F_44 ( V_8 , V_49 ) ;
F_65 ( V_8 -> V_117 -> V_118 , V_44 ) ;
return V_341 ;
}
static int
F_117 ( struct V_323 * V_324 , struct V_342 * V_343 ,
T_4 V_344 , int V_345 [] )
{
int V_346 , V_347 ;
T_4 V_348 ;
unsigned long V_27 ;
V_346 = 64 ;
V_347 = 32 ;
V_27 = V_346 * V_347 ;
V_348 = V_344 ;
F_118 ( V_348 , V_27 ) ;
if ( V_344 >= 0x200000 ) {
V_346 = 255 ;
V_347 = 63 ;
V_27 = V_346 * V_347 ;
V_348 = V_344 ;
F_118 ( V_348 , V_27 ) ;
}
V_345 [ 0 ] = V_346 ;
V_345 [ 1 ] = V_347 ;
V_345 [ 2 ] = V_348 ;
return 0 ;
}
static int F_119 ( struct V_7 * V_8 )
{
int V_148 = 0 ;
if ( F_120 ( V_8 -> V_20 , V_349 ) ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_60 ) ;
return - V_350 ;
}
V_148 = F_9 ( V_8 -> V_20 , V_8 -> V_124 ) ;
if ( V_148 )
goto V_351;
V_8 -> V_66 = V_8 -> V_124 [ 0 ] ;
switch ( V_8 -> V_20 -> V_107 ) {
case V_352 :
V_8 -> V_119 = & V_353 ;
V_8 -> V_310 = 0 ;
V_8 -> V_41 = V_354 ;
V_8 -> V_83 = 1 ;
break;
default:
F_11 ( & V_8 -> V_20 -> V_11 , L_61 ,
V_8 -> V_20 -> V_107 ) ;
V_8 -> V_119 = NULL ;
V_148 = - V_326 ;
goto V_355;
}
F_12 ( & V_8 -> V_20 -> V_11 , L_62 ,
V_8 -> V_20 -> V_107 ) ;
V_8 -> V_125 = F_14 ( V_356 , V_19 ) ;
if ( ! V_8 -> V_125 ) {
F_11 ( & V_8 -> V_20 -> V_11 ,
L_63 ) ;
V_148 = - V_15 ;
goto V_355;
}
V_8 -> V_231 = F_121 ( V_8 -> V_125 ) ;
if ( F_60 ( V_8 ) ) {
V_148 = - V_326 ;
goto V_357;
}
V_148 = F_47 ( V_8 ) ;
if ( V_148 )
goto V_357;
return 0 ;
V_357:
F_20 ( V_8 ) ;
F_15 ( V_8 -> V_125 ) ;
V_355:
F_6 ( V_8 -> V_20 , V_8 -> V_124 ) ;
V_351:
F_69 ( V_8 -> V_20 ) ;
return V_148 ;
}
static int F_122 ( struct V_7 * V_8 )
{
struct V_336 * V_108 = V_8 -> V_117 ;
int V_148 ;
unsigned int V_358 = ( V_8 -> V_57 + 4 -
sizeof( struct V_126 ) ) / sizeof( struct V_36 ) ;
V_108 -> V_300 = V_8 -> V_20 -> V_300 ;
V_108 -> V_359 = V_8 -> V_359 ;
V_108 -> V_360 = ( V_8 -> V_60 - 1 ) ? ( V_8 -> V_60 - 1 ) : 1 ;
V_108 -> V_361 = V_8 -> V_41 > V_358 ? V_358 : V_8 -> V_41 ;
V_108 -> V_362 = V_8 -> V_212 / 512 ;
V_108 -> V_363 = ( V_8 -> V_60 - 1 ) ? ( V_8 -> V_60 - 1 ) : 1 ;
V_108 -> V_364 = V_8 -> V_130 ;
V_108 -> V_365 = V_139 ;
V_108 -> V_366 = & V_367 ;
V_148 = F_123 ( V_108 , & V_8 -> V_20 -> V_11 ) ;
if ( V_148 ) {
F_11 ( & V_8 -> V_20 -> V_11 , L_64 ) ;
return V_148 ;
}
V_8 -> V_28 |= V_368 ;
F_124 ( V_108 ) ;
return 0 ;
}
static int T_5 F_125 ( struct V_10 * V_20 ,
const struct V_369 * V_325 )
{
struct V_336 * V_108 ;
struct V_7 * V_8 ;
int V_148 ;
F_12 ( & V_20 -> V_11 , L_65 ,
V_20 -> V_370 , V_20 -> V_107 , V_20 -> V_371 ,
V_20 -> V_372 ) ;
V_148 = F_126 ( V_20 ) ;
if ( V_148 )
return V_148 ;
F_127 ( V_20 ) ;
if ( V_373 ) {
V_148 = F_128 ( V_20 , F_129 ( 64 ) ) ;
if ( V_148 ) {
V_148 = F_128 ( V_20 , F_129 ( 32 ) ) ;
if ( V_148 )
goto V_374;
}
} else {
V_148 = F_128 ( V_20 , F_129 ( 32 ) ) ;
if ( V_148 )
goto V_374;
}
V_108 = F_130 ( & V_375 , sizeof( * V_8 ) ) ;
if ( ! V_108 ) {
F_11 ( & V_20 -> V_11 , L_66 ) ;
V_148 = - V_15 ;
goto V_376;
}
V_8 = F_116 ( V_108 ) ;
F_18 ( & V_8 -> V_58 ) ;
F_18 ( & V_8 -> V_92 ) ;
F_18 ( & V_8 -> V_95 ) ;
F_18 ( & V_8 -> V_26 ) ;
F_18 ( & V_8 -> V_313 ) ;
F_71 ( & V_8 -> V_65 , 0 ) ;
F_131 ( & V_8 -> V_121 ) ;
V_8 -> V_20 = V_20 ;
V_8 -> V_117 = V_108 ;
V_8 -> V_359 = V_20 -> V_377 -> V_378 << 8 | V_20 -> V_379 ;
V_148 = F_119 ( V_8 ) ;
if ( V_148 )
goto V_380;
V_148 = F_132 ( V_8 -> V_20 -> V_300 , F_102 , V_381 ,
L_67 , V_8 ) ;
if ( V_148 ) {
F_11 ( & V_20 -> V_11 , L_68 ) ;
goto V_382;
}
V_8 -> V_119 -> V_383 ( V_8 -> V_66 ) ;
F_133 ( V_20 , V_8 ) ;
V_148 = F_122 ( V_8 ) ;
if ( V_148 )
goto V_384;
F_12 ( & V_20 -> V_11 , L_69 ) ;
return 0 ;
V_384:
F_133 ( V_20 , NULL ) ;
V_8 -> V_119 -> V_385 ( V_8 -> V_66 ) ;
F_134 ( V_8 -> V_20 -> V_300 , V_8 ) ;
V_382:
F_68 ( V_8 ) ;
V_380:
F_135 ( V_108 ) ;
V_376:
V_374:
F_136 ( V_20 ) ;
return V_148 ;
}
static void F_137 ( struct V_10 * V_20 )
{
struct V_336 * V_108 ;
struct V_7 * V_8 ;
V_8 = F_138 ( V_20 ) ;
V_108 = V_8 -> V_117 ;
F_139 ( V_8 -> V_117 ) ;
F_70 ( V_8 ) ;
V_8 -> V_119 -> V_385 ( V_8 -> V_66 ) ;
F_134 ( V_8 -> V_20 -> V_300 , V_8 ) ;
F_68 ( V_8 ) ;
F_135 ( V_108 ) ;
F_133 ( V_20 , NULL ) ;
F_136 ( V_20 ) ;
F_12 ( & V_20 -> V_11 , L_70 ) ;
}
static void F_140 ( struct V_10 * V_20 )
{
struct V_7 * V_8 = F_138 ( V_20 ) ;
F_70 ( V_8 ) ;
}
static int F_141 ( struct V_10 * V_20 , T_6 V_386 )
{
struct V_7 * V_8 = NULL ;
V_8 = F_138 ( V_20 ) ;
F_70 ( V_8 ) ;
F_133 ( V_20 , V_8 ) ;
V_8 -> V_119 -> V_385 ( V_8 -> V_66 ) ;
F_134 ( V_8 -> V_20 -> V_300 , V_8 ) ;
F_6 ( V_20 , V_8 -> V_124 ) ;
F_69 ( V_20 ) ;
F_142 ( V_20 ) ;
F_136 ( V_20 ) ;
F_143 ( V_20 , F_144 ( V_20 , V_386 ) ) ;
return 0 ;
}
static int F_145 ( struct V_10 * V_20 )
{
int V_148 ;
struct V_7 * V_8 = NULL ;
V_8 = F_138 ( V_20 ) ;
F_143 ( V_20 , V_387 ) ;
F_146 ( V_20 , V_387 , 0 ) ;
F_147 ( V_20 ) ;
V_148 = F_126 ( V_20 ) ;
if ( V_148 ) {
F_11 ( & V_20 -> V_11 , L_71 ) ;
return V_148 ;
}
F_127 ( V_20 ) ;
if ( V_373 ) {
V_148 = F_128 ( V_20 , F_129 ( 64 ) ) ;
if ( V_148 ) {
V_148 = F_128 ( V_20 , F_129 ( 32 ) ) ;
if ( V_148 )
goto V_388;
}
} else {
V_148 = F_128 ( V_20 , F_129 ( 32 ) ) ;
if ( V_148 )
goto V_388;
}
V_148 = F_120 ( V_8 -> V_20 , V_349 ) ;
if ( V_148 )
goto V_388;
V_148 = F_9 ( V_8 -> V_20 , V_8 -> V_124 ) ;
if ( V_148 )
goto V_389;
V_8 -> V_66 = V_8 -> V_124 [ 0 ] ;
F_58 ( V_8 -> V_66 ) ;
if ( F_60 ( V_8 ) ) {
V_148 = - V_326 ;
goto V_390;
}
V_148 = F_132 ( V_8 -> V_20 -> V_300 , F_102 , V_381 ,
L_67 , V_8 ) ;
if ( V_148 ) {
F_11 ( & V_20 -> V_11 , L_68 ) ;
goto V_390;
}
V_8 -> V_119 -> V_383 ( V_8 -> V_66 ) ;
return 0 ;
V_390:
F_6 ( V_20 , V_8 -> V_124 ) ;
V_389:
F_69 ( V_20 ) ;
V_388:
F_136 ( V_20 ) ;
return V_148 ;
}
static int T_7 F_148 ( void )
{
return F_149 ( & V_391 ) ;
}
static void T_8 F_150 ( void )
{
F_151 ( & V_391 ) ;
}
