static void F_1 ( T_1 * V_1 )
{
T_2 * V_2 = V_1 -> V_2 ;
V_2 [ V_3 ] = V_2 [ V_4 ] = V_1 -> V_5 ;
V_2 [ V_6 ] = V_2 [ V_7 ] = V_1 -> V_8 ;
V_2 [ V_9 ] = V_2 [ V_10 ] = V_1 -> V_11 ;
}
static void F_2 ( T_1 * V_1 )
{
T_2 * V_2 = V_1 -> V_2 ;
if ( ! V_1 -> V_5 || ! V_1 -> V_8 || ! V_1 -> V_11 ) {
V_1 -> V_5 = V_1 -> V_12 = V_2 [ V_4 ] ;
V_1 -> V_8 = V_1 -> V_13 = V_2 [ V_7 ] ;
V_1 -> V_11 = V_1 -> V_14 = V_2 [ V_10 ] ;
}
if ( F_3 ( V_2 ) ) {
V_1 -> V_5 = V_2 [ V_3 ] ;
V_1 -> V_8 = V_2 [ V_6 ] ;
V_1 -> V_11 = V_2 [ V_9 ] ;
}
if ( V_1 -> V_8 > 16 && V_2 [ V_7 ] && V_2 [ V_7 ] <= 16 ) {
V_1 -> V_5 = V_2 [ V_4 ] ;
V_1 -> V_8 = V_2 [ V_7 ] ;
V_1 -> V_11 = V_2 [ V_10 ] ;
}
}
static void F_4 ( T_1 * V_1 )
{
T_2 * V_2 = V_1 -> V_2 ;
T_3 V_15 = V_2 [ V_16 ] & 0xff ;
if ( V_15 ) {
if ( ( V_15 / 2 ) > 1 )
V_2 [ V_17 ] = V_15 | 0x100 ;
else
V_2 [ V_17 ] &= ~ 0x1ff ;
V_1 -> V_18 = V_2 [ V_17 ] & 0xff ;
if ( V_1 -> V_18 )
V_1 -> V_19 |= V_20 ;
}
}
static void F_5 ( T_1 * V_1 )
{
T_2 * V_2 = V_1 -> V_2 ;
char * V_21 = ( char * ) & V_2 [ V_22 ] ;
int V_23 = F_6 ( V_2 ) ;
if ( V_23 == 0 && ( V_2 [ V_24 ] & ( 1 << 7 ) ) )
V_1 -> V_25 |= V_26 ;
V_1 -> V_27 = V_28 ;
if ( ! F_7 ( V_1 -> V_2 ) )
V_1 -> V_25 |= V_29 ;
F_8 ( V_30 L_1 , V_1 -> V_31 , V_21 ,
V_23 ? L_2 : L_3 ) ;
}
static void F_9 ( T_1 * V_1 )
{
T_2 * V_2 = V_1 -> V_2 ;
char * V_21 = ( char * ) & V_2 [ V_22 ] ;
T_3 type = ( V_2 [ V_24 ] >> 8 ) & 0x1f ;
F_8 ( V_30 L_4 , V_1 -> V_31 , V_21 ) ;
switch ( type ) {
case V_32 :
if ( ! strstr ( V_21 , L_5 ) ) {
if ( ! strstr ( V_21 , L_6 ) &&
! strstr ( V_21 , L_7 ) &&
! strstr ( V_21 , L_8 ) )
F_8 ( V_33 L_9 ) ;
if ( V_1 -> V_27 != V_34 ) {
F_8 ( V_33 L_10 ) ;
V_1 -> V_25 |= V_26 ;
break;
}
}
type = V_34 ;
case V_34 :
V_1 -> V_25 |= V_26 ;
#ifdef F_10
if ( ! strstr ( V_21 , L_5 ) && strstr ( V_21 , L_8 ) ) {
F_8 ( V_33 L_10 ) ;
type = V_32 ;
break;
}
#endif
F_8 ( V_33 L_11 ) ;
break;
case V_35 :
F_8 ( V_33 L_12 ) ;
break;
case V_36 :
F_8 ( V_33 L_13 ) ;
V_1 -> V_25 |= V_26 ;
break;
default:
F_8 ( V_33 L_14 , type ) ;
break;
}
F_8 ( V_33 L_15 ) ;
V_1 -> V_27 = type ;
V_1 -> V_37 = 0 ;
if ( F_11 ( V_2 ) )
V_1 -> V_38 |= V_39 ;
V_1 -> V_25 |= V_40 ;
V_1 -> V_25 |= V_29 ;
}
static void F_12 ( T_1 * V_1 , T_3 V_41 , T_2 * V_2 )
{
T_4 * V_42 = V_1 -> V_42 ;
char * V_21 = ( char * ) & V_2 [ V_22 ] ;
unsigned long V_43 ;
int V_44 = 1 ;
F_13 ( V_43 ) ;
V_42 -> V_45 -> V_46 ( V_1 , NULL , V_2 , V_47 ) ;
F_14 ( V_43 ) ;
V_1 -> V_25 |= V_48 ;
#ifdef F_15
F_8 ( V_30 L_16 , V_1 -> V_31 ) ;
F_16 ( ( T_3 * ) V_2 ) ;
#endif
F_17 ( V_2 ) ;
if ( V_41 == V_49 ) {
if ( ( V_21 [ 0 ] == 'N' && V_21 [ 1 ] == 'E' ) ||
( V_21 [ 0 ] == 'F' && V_21 [ 1 ] == 'X' ) ||
( V_21 [ 0 ] == 'P' && V_21 [ 1 ] == 'i' ) )
V_44 ^= 1 ;
}
F_18 ( V_21 , V_50 , V_44 ) ;
F_18 ( ( char * ) & V_2 [ V_51 ] , V_52 , V_44 ) ;
F_18 ( ( char * ) & V_2 [ V_53 ] , V_54 , V_44 ) ;
V_21 [ V_50 - 1 ] = '\0' ;
if ( strstr ( V_21 , L_17 ) )
V_1 -> V_25 &= ~ V_55 ;
else
V_1 -> V_25 |= V_55 ;
}
int F_19 ( T_1 * V_1 , T_3 V_41 , T_2 * V_2 , int V_56 )
{
T_4 * V_42 = V_1 -> V_42 ;
struct V_57 * V_58 = & V_42 -> V_58 ;
const struct V_59 * V_45 = V_42 -> V_45 ;
int V_60 = 0 , V_61 ;
unsigned long V_62 ;
T_3 V_63 = 0 , V_64 = 0 ;
if ( V_58 -> V_65 )
V_45 -> V_66 ( V_42 , V_67 | V_68 ) ;
if ( V_56 )
F_20 ( 50 ) ;
else
F_21 ( 50 ) ;
if ( V_58 -> V_65 &&
( V_42 -> V_69 & V_70 ) == 0 ) {
V_64 = V_45 -> V_71 ( V_42 ) ;
V_63 = V_45 -> V_72 ( V_42 ) ;
if ( ( V_64 ^ V_63 ) & ~ V_73 )
F_8 ( V_30 L_18
L_19 ,
V_1 -> V_31 , V_63 , V_64 ) ;
else
V_60 = 1 ;
}
if ( V_41 == V_49 ) {
struct V_74 V_75 ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_45 -> V_76 ( V_1 , & V_75 , V_77 ) ;
}
V_45 -> V_78 ( V_42 , V_41 ) ;
V_62 = ( ( V_41 == V_79 ) ? V_80 : V_81 ) / 2 ;
if ( V_56 ) {
V_61 = F_22 ( V_1 , V_82 , V_83 , V_62 , & V_63 ) ;
if ( V_61 )
return 1 ;
} else {
V_61 = F_23 ( V_1 , V_62 , V_60 ) ;
if ( V_61 )
return 1 ;
F_21 ( 50 ) ;
V_63 = V_45 -> V_72 ( V_42 ) ;
}
if ( F_24 ( V_63 , V_82 , V_83 ) ) {
F_12 ( V_1 , V_41 , V_2 ) ;
V_61 = 0 ;
( void ) V_45 -> V_72 ( V_42 ) ;
} else {
V_61 = 2 ;
}
return V_61 ;
}
int F_23 ( T_1 * V_1 , unsigned long V_62 , int V_84 )
{
T_4 * V_42 = V_1 -> V_42 ;
T_3 V_85 ;
V_62 += V_86 ;
do {
F_21 ( 50 ) ;
V_85 = V_84 ? V_42 -> V_45 -> V_71 ( V_42 )
: V_42 -> V_45 -> V_72 ( V_42 ) ;
if ( ( V_85 & V_87 ) == 0 )
return 0 ;
} while ( F_25 ( V_86 , V_62 ) );
F_8 ( V_88 L_20 , V_1 -> V_31 , V_89 ) ;
return 1 ;
}
static T_3 F_26 ( T_1 * V_1 )
{
struct V_74 V_75 ;
V_1 -> V_42 -> V_45 -> V_90 ( V_1 , & V_75 , V_91 ) ;
return V_75 . V_92 ;
}
static int F_27 ( T_1 * V_1 , T_3 V_41 )
{
T_4 * V_42 = V_1 -> V_42 ;
const struct V_59 * V_45 = V_42 -> V_45 ;
T_2 * V_2 = V_1 -> V_2 ;
int V_61 ;
T_3 V_93 = ! ! ( V_1 -> V_25 & V_55 ) , V_85 ;
if ( V_93 && V_1 -> V_27 != V_28 && V_41 == V_79 )
return 4 ;
#ifdef F_15
F_8 ( V_30 L_21 ,
V_1 -> V_31 , V_93 , V_1 -> V_27 ,
( V_41 == V_79 ) ? L_3 : L_22 ) ;
#endif
F_21 ( 50 ) ;
V_45 -> V_94 ( V_1 ) ;
F_21 ( 50 ) ;
if ( F_26 ( V_1 ) != V_1 -> V_95 && V_93 == 0 ) {
if ( V_1 -> V_96 & 1 ) {
V_45 -> V_94 ( V_42 -> V_97 [ 0 ] ) ;
F_21 ( 50 ) ;
}
return 3 ;
}
V_85 = V_45 -> V_72 ( V_42 ) ;
if ( F_24 ( V_85 , V_98 , V_87 ) ||
V_93 || V_41 == V_49 ) {
V_61 = F_19 ( V_1 , V_41 , V_2 , 0 ) ;
if ( V_61 )
V_61 = F_19 ( V_1 , V_41 , V_2 , 0 ) ;
V_85 = V_45 -> V_72 ( V_42 ) ;
if ( V_85 == ( V_87 | V_98 ) )
return 4 ;
if ( V_61 == 1 && V_41 == V_49 ) {
F_8 ( V_88 L_23
L_24 , V_1 -> V_31 , V_85 ) ;
F_21 ( 50 ) ;
V_45 -> V_94 ( V_1 ) ;
F_21 ( 50 ) ;
V_45 -> V_78 ( V_42 , V_99 ) ;
( void ) F_23 ( V_1 , V_80 , 0 ) ;
V_61 = F_19 ( V_1 , V_41 , V_2 , 0 ) ;
}
V_85 = V_45 -> V_72 ( V_42 ) ;
if ( V_61 == 1 )
F_8 ( V_88 L_25 ,
V_1 -> V_31 , V_85 ) ;
} else {
V_61 = 3 ;
}
if ( V_1 -> V_96 & 1 ) {
V_45 -> V_94 ( V_42 -> V_97 [ 0 ] ) ;
F_21 ( 50 ) ;
( void ) V_45 -> V_72 ( V_42 ) ;
}
return V_61 ;
}
static T_3 F_28 ( T_1 * V_1 )
{
char * V_21 ;
int V_61 ;
T_3 V_41 ;
V_1 -> V_25 &= ~ V_48 ;
V_21 = ( char * ) & V_1 -> V_2 [ V_22 ] ;
strcpy ( V_21 , L_26 ) ;
if ( ( V_1 -> V_25 & V_100 ) == 0 ) {
V_41 = V_79 ;
V_61 = F_27 ( V_1 , V_41 ) ;
if ( V_61 >= 2 ) {
V_41 = V_49 ;
V_61 = F_27 ( V_1 , V_41 ) ;
}
if ( ( V_1 -> V_25 & V_55 ) == 0 )
return 0 ;
if ( ( V_1 -> V_25 & V_48 ) == 0 ) {
if ( V_1 -> V_27 == V_28 ) {
F_8 ( V_30 L_27 ,
V_1 -> V_31 , V_1 -> V_5 ,
V_1 -> V_8 , V_1 -> V_11 ) ;
} else if ( V_1 -> V_27 == V_34 ) {
F_8 ( V_30 L_28 , V_1 -> V_31 ) ;
} else {
F_8 ( V_101 L_29 , V_1 -> V_31 ) ;
V_1 -> V_25 &= ~ V_55 ;
}
} else {
if ( V_41 == V_49 )
F_9 ( V_1 ) ;
else
F_5 ( V_1 ) ;
}
}
if ( ( V_1 -> V_25 & V_55 ) == 0 )
return 0 ;
if ( ( V_1 -> V_25 & V_48 ) == 0 ) {
F_1 ( V_1 ) ;
return 1 ;
}
if ( V_1 -> V_27 == V_28 ) {
F_2 ( V_1 ) ;
F_4 ( V_1 ) ;
}
return 1 ;
}
static void F_29 ( struct V_92 * V_102 )
{
T_4 * V_42 = F_30 ( V_102 , T_4 , V_103 ) ;
F_31 ( & V_42 -> V_104 ) ;
}
static int F_32 ( T_4 * V_42 )
{
int V_105 ;
F_33 ( & V_42 -> V_103 , L_30 , V_42 -> V_31 ) ;
F_34 ( & V_42 -> V_103 , V_42 ) ;
if ( V_42 -> V_103 . V_106 == NULL )
V_42 -> V_103 . V_106 = V_42 -> V_102 ;
V_42 -> V_103 . V_107 = F_29 ;
V_105 = F_35 ( & V_42 -> V_103 ) ;
if ( V_105 < 0 ) {
F_8 ( V_101 L_31 ,
V_89 , V_105 ) ;
goto V_108;
}
V_42 -> V_109 = F_36 ( V_110 , & V_42 -> V_103 ,
F_37 ( 0 , 0 ) , V_42 , L_30 , V_42 -> V_31 ) ;
if ( F_38 ( V_42 -> V_109 ) ) {
V_105 = F_39 ( V_42 -> V_109 ) ;
F_40 ( & V_42 -> V_103 ) ;
}
V_108:
return V_105 ;
}
static int F_41 ( T_4 * V_42 )
{
const struct V_59 * V_45 = V_42 -> V_45 ;
T_1 * V_1 ;
int V_111 , V_61 ;
F_8 ( V_112 L_32 , V_42 -> V_31 ) ;
F_20 ( 2 ) ;
V_61 = F_42 ( V_42 , 35000 ) ;
if ( V_61 )
return V_61 ;
F_43 (i, drive, hwif) {
if ( ( V_1 -> V_25 & V_100 ) == 0 ||
( V_1 -> V_25 & V_55 ) ) {
V_45 -> V_94 ( V_1 ) ;
V_45 -> V_66 ( V_42 , V_68 ) ;
F_20 ( 2 ) ;
V_61 = F_42 ( V_42 , 35000 ) ;
if ( V_61 )
goto V_108;
} else
F_8 ( V_112 L_33 ,
V_1 -> V_31 ) ;
}
V_108:
if ( V_111 )
V_45 -> V_94 ( V_42 -> V_97 [ 0 ] ) ;
return V_61 ;
}
void F_44 ( T_1 * V_113 )
{
T_1 * V_114 = V_113 -> V_42 -> V_97 [ 0 ] ;
if ( ( V_113 -> V_96 & 1 ) == 0 || ( V_114 -> V_25 & V_55 ) == 0 )
return;
if ( strcmp ( ( char * ) & V_114 -> V_2 [ V_22 ] ,
( char * ) & V_113 -> V_2 [ V_22 ] ) )
return;
if ( strncmp ( ( char * ) & V_114 -> V_2 [ V_53 ] ,
( char * ) & V_113 -> V_2 [ V_53 ] , V_54 ) )
return;
if ( * ( char * ) & V_114 -> V_2 [ V_53 ] == 0 )
return;
F_8 ( V_101 L_34 ) ;
V_113 -> V_25 &= ~ V_55 ;
}
static int F_45 ( T_4 * V_42 )
{
T_1 * V_1 ;
unsigned int V_115 ;
int V_111 , V_61 = - V_116 ;
F_46 ( V_42 -> V_93 ) ;
if ( ( V_42 -> V_97 [ 0 ] -> V_25 & V_100 ) &&
( V_42 -> V_97 [ 1 ] -> V_25 & V_100 ) )
return - V_117 ;
V_115 = V_42 -> V_118 ;
if ( V_115 )
F_47 ( V_42 -> V_118 ) ;
if ( F_41 ( V_42 ) == - V_119 )
F_8 ( V_112 L_35 , V_42 -> V_31 ) ;
F_43 (i, drive, hwif) {
( void ) F_28 ( V_1 ) ;
if ( V_1 -> V_25 & V_55 )
V_61 = 0 ;
}
if ( V_115 )
F_48 ( V_115 ) ;
return V_61 ;
}
static void F_49 ( T_4 * V_42 )
{
const struct V_120 * V_121 = V_42 -> V_121 ;
T_1 * V_1 ;
int V_111 ;
F_50 (i, drive, hwif) {
F_51 ( V_1 ) ;
if ( V_121 && V_121 -> V_122 )
V_121 -> V_122 ( V_1 ) ;
}
F_50 (i, drive, hwif) {
F_52 ( V_1 ) ;
V_1 -> V_25 |= V_123 ;
if ( V_42 -> V_124 )
F_53 ( V_1 ) ;
}
}
static int F_54 ( struct V_125 * V_126 , struct V_127 * V_128 , T_5 V_129 )
{
struct V_130 * V_131 = F_55 ( V_128 ) ;
V_131 -> V_132 . V_133 = V_131 -> V_133 ;
return 0 ;
}
static int F_56 ( T_1 * V_1 )
{
struct V_125 * V_126 ;
T_4 * V_42 = V_1 -> V_42 ;
int V_134 = 256 ;
int V_135 = V_136 ;
V_126 = F_57 ( V_137 , F_58 ( V_42 ) ) ;
if ( ! V_126 )
return 1 ;
V_126 -> V_138 = V_139 ;
V_126 -> V_140 = F_54 ;
V_126 -> V_141 = sizeof( struct V_130 ) ;
if ( F_59 ( V_126 ) < 0 ) {
F_60 ( V_126 ) ;
return 1 ;
}
V_126 -> V_142 = V_1 ;
F_61 ( V_126 , 0xffff ) ;
if ( V_42 -> V_143 < V_134 )
V_134 = V_42 -> V_143 ;
F_62 ( V_126 , V_134 ) ;
#ifdef F_63
if ( ! V_144 )
V_135 >>= 1 ;
#endif
F_64 ( V_126 , V_135 ) ;
V_1 -> V_145 = V_126 ;
F_65 ( V_1 , 1 ) ;
return 0 ;
}
static int F_66 ( T_4 * V_42 )
{
T_1 * V_1 ;
int V_111 , V_146 = 0 ;
F_67 ( & V_147 ) ;
F_50 (i, drive, hwif) {
if ( F_56 ( V_1 ) ) {
F_8 ( V_88 L_36 ,
V_1 -> V_31 ) ;
V_1 -> V_25 &= ~ V_55 ;
continue;
}
V_146 ++ ;
}
F_68 ( & V_147 ) ;
return V_146 ;
}
static void F_69 ( struct V_148 * V_149 )
{
T_4 * V_42 ;
int V_111 ;
F_70 (i, hwif, host) {
if ( V_42 == NULL )
continue;
V_42 -> V_45 -> V_72 ( V_42 ) ;
if ( V_42 -> V_58 . V_65 )
V_42 -> V_45 -> V_66 ( V_42 , V_68 ) ;
}
}
static int F_71 ( T_4 * V_42 )
{
struct V_57 * V_58 = & V_42 -> V_58 ;
struct V_148 * V_149 = V_42 -> V_149 ;
T_6 V_150 = V_149 -> V_150 ;
int V_151 = V_149 -> V_152 ;
if ( V_150 == NULL )
V_150 = V_153 ;
if ( ! V_149 -> V_154 )
if ( F_72 ( V_42 -> V_118 , V_150 , V_151 , V_42 -> V_31 , V_42 ) )
goto V_155;
#if ! F_73 ( V_156 )
F_8 ( V_30 L_37 , V_42 -> V_31 ,
V_58 -> V_157 , V_58 -> V_158 ,
V_58 -> V_65 , V_42 -> V_118 ) ;
#else
F_8 ( V_30 L_38 , V_42 -> V_31 ,
V_58 -> V_157 , V_42 -> V_118 ) ;
#endif
if ( V_42 -> V_149 -> V_69 & V_159 )
F_8 ( V_33 L_39 ) ;
F_8 ( V_33 L_40 ) ;
return 0 ;
V_155:
return 1 ;
}
static int F_74 ( T_7 V_102 , void * V_160 )
{
return 0 ;
}
static struct V_161 * F_75 ( T_7 V_102 , int * V_162 , void * V_160 )
{
T_4 * V_42 = V_160 ;
int V_163 = * V_162 >> V_164 ;
T_1 * V_1 = V_42 -> V_97 [ V_163 ] ;
if ( ( V_1 -> V_25 & V_55 ) == 0 )
return NULL ;
if ( V_1 -> V_27 == V_28 )
F_76 ( L_41 ) ;
if ( V_1 -> V_27 == V_34 || V_1 -> V_27 == V_36 )
F_76 ( L_42 ) ;
if ( V_1 -> V_27 == V_35 )
F_76 ( L_43 ) ;
if ( V_1 -> V_27 == V_32 )
F_76 ( L_44 ) ;
return NULL ;
}
static struct V_161 * F_77 ( T_7 V_102 , int * V_162 , void * V_160 )
{
struct V_165 * V_166 = V_160 ;
* V_162 &= ( 1 << V_164 ) - 1 ;
return & F_78 ( V_166 ) -> V_167 ;
}
static int F_79 ( T_7 V_102 , void * V_160 )
{
struct V_165 * V_166 = V_160 ;
if ( ! F_80 ( V_166 ) )
return - 1 ;
return 0 ;
}
void F_81 ( struct V_165 * V_168 )
{
F_82 ( F_37 ( V_168 -> V_169 , V_168 -> V_170 ) ,
V_168 -> V_171 , NULL , F_77 , F_79 , V_168 ) ;
}
void F_83 ( struct V_165 * V_168 )
{
F_84 ( F_37 ( V_168 -> V_169 , V_168 -> V_170 ) ,
V_168 -> V_171 ) ;
}
void F_85 ( struct V_165 * V_168 , T_1 * V_1 )
{
T_4 * V_42 = V_1 -> V_42 ;
unsigned int V_163 = V_1 -> V_96 & 1 ;
V_168 -> V_169 = V_42 -> V_169 ;
V_168 -> V_170 = V_163 << V_164 ;
sprintf ( V_168 -> V_172 , L_45 , 'a' + V_42 -> V_173 * V_174 + V_163 ) ;
V_168 -> V_145 = V_1 -> V_145 ;
}
static void F_86 ( struct V_92 * V_102 )
{
T_1 * V_1 = F_30 ( V_102 , T_1 , V_103 ) ;
F_87 ( V_1 ) ;
F_60 ( V_1 -> V_145 ) ;
V_1 -> V_145 = NULL ;
V_1 -> V_25 &= ~ V_55 ;
F_31 ( & V_1 -> V_104 ) ;
}
static int F_88 ( T_4 * V_42 )
{
if ( ! V_42 -> V_118 ) {
F_8 ( V_88 L_46 , V_42 -> V_31 ) ;
return 0 ;
}
if ( F_89 ( V_42 -> V_169 , V_42 -> V_31 ) )
return 0 ;
if ( ! V_42 -> V_175 )
V_42 -> V_175 = V_136 ;
V_42 -> V_176 = F_90 ( sizeof( struct V_177 ) * V_42 -> V_175 ,
V_137 ) ;
if ( ! V_42 -> V_176 ) {
F_8 ( V_88 L_47 , V_42 -> V_31 ) ;
goto V_108;
}
F_91 ( V_42 -> V_176 , V_42 -> V_175 ) ;
if ( F_71 ( V_42 ) ) {
F_8 ( V_88 L_48 ,
V_42 -> V_31 , V_42 -> V_118 ) ;
goto V_108;
}
F_82 ( F_37 ( V_42 -> V_169 , 0 ) , V_174 << V_164 ,
V_178 , F_75 , F_74 , V_42 ) ;
return 1 ;
V_108:
F_92 ( V_42 -> V_169 , V_42 -> V_31 ) ;
return 0 ;
}
static void F_93 ( T_4 * V_42 )
{
T_1 * V_1 ;
unsigned int V_111 ;
F_50 (i, drive, hwif) {
struct V_92 * V_102 = & V_1 -> V_103 ;
int V_105 ;
F_33 ( V_102 , L_49 , V_42 -> V_173 , V_111 ) ;
F_34 ( V_102 , V_1 ) ;
V_102 -> V_106 = & V_42 -> V_103 ;
V_102 -> V_179 = & V_180 ;
V_102 -> V_107 = F_86 ;
V_105 = F_35 ( V_102 ) ;
if ( V_105 < 0 )
F_8 ( V_101 L_50
L_51 , V_89 , V_105 ) ;
}
}
static void F_94 ( T_4 * V_42 )
{
const struct V_120 * V_121 = V_42 -> V_121 ;
T_1 * V_1 ;
int V_111 ;
F_43 (i, drive, hwif) {
V_1 -> V_96 = V_111 + V_42 -> V_181 * 2 ;
if ( V_42 -> V_69 & V_182 )
V_1 -> V_183 = 1 ;
if ( V_42 -> V_69 & V_184 )
V_1 -> V_25 |= V_185 ;
if ( V_42 -> V_69 & V_186 )
V_1 -> V_25 |= V_187 ;
if ( V_42 -> V_69 & V_188 )
V_1 -> V_25 |= V_189 ;
V_1 -> V_190 = V_191 ;
if ( V_121 && V_121 -> V_192 )
V_121 -> V_192 ( V_1 ) ;
}
}
static void F_95 ( T_4 * V_42 , unsigned int V_193 ,
const struct V_194 * V_195 )
{
V_42 -> V_181 = V_193 ;
V_42 -> V_196 = V_195 -> V_196 ? V_195 -> V_196 : V_197 ;
if ( V_195 -> V_198 )
V_195 -> V_198 ( V_42 ) ;
V_42 -> V_69 |= V_195 -> V_69 ;
V_42 -> V_199 = V_195 -> V_199 ;
if ( V_195 -> V_45 )
V_42 -> V_45 = V_195 -> V_45 ;
if ( ( V_42 -> V_69 & V_200 ) == 0 || V_42 -> V_181 == 0 )
V_42 -> V_121 = V_195 -> V_121 ;
V_42 -> V_201 = V_195 -> V_201 ;
V_42 -> V_202 = V_195 -> V_202 ;
V_42 -> V_203 = V_195 -> V_204 ;
if ( ( V_195 -> V_69 & V_205 ) == 0 ) {
int V_61 ;
V_42 -> V_124 = V_195 -> V_124 ;
if ( V_195 -> V_206 )
V_61 = V_195 -> V_206 ( V_42 , V_195 ) ;
else
V_61 = F_96 ( V_42 , V_195 ) ;
if ( V_61 < 0 ) {
F_8 ( V_30 L_52 , V_42 -> V_31 ) ;
V_42 -> V_124 = NULL ;
V_42 -> V_207 = 0 ;
V_42 -> V_201 = 0 ;
V_42 -> V_202 = 0 ;
V_42 -> V_203 = 0 ;
}
}
if ( ( V_195 -> V_69 & V_159 ) ||
( ( V_195 -> V_69 & V_208 ) && V_42 -> V_207 ) )
V_42 -> V_149 -> V_69 |= V_159 ;
if ( V_195 -> V_134 )
V_42 -> V_143 = V_195 -> V_134 ;
else {
if ( ( V_42 -> V_69 & V_209 ) ||
( V_42 -> V_69 & V_210 ) )
V_42 -> V_143 = 256 ;
else
V_42 -> V_143 = 65536 ;
}
if ( V_195 -> V_211 )
V_195 -> V_211 ( V_42 ) ;
}
static void F_97 ( T_4 * V_42 )
{
const struct V_120 * V_121 = V_42 -> V_121 ;
if ( V_121 && V_121 -> V_212 && ( V_42 -> V_203 & 0x78 ) ) {
if ( V_42 -> V_213 != V_214 )
V_42 -> V_213 = V_121 -> V_212 ( V_42 ) ;
}
}
static void F_98 ( T_4 * V_42 )
{
T_1 * V_1 ;
int V_111 ;
F_43 (i, drive, hwif) {
T_3 V_146 = ( V_42 -> V_173 * V_174 ) + V_111 ;
T_2 * V_215 = V_1 -> V_2 ;
struct V_127 * V_216 = V_1 -> V_217 ;
memset ( V_1 , 0 , sizeof( * V_1 ) ) ;
memset ( V_215 , 0 , V_47 ) ;
V_1 -> V_2 = V_215 ;
V_1 -> V_217 = V_216 ;
V_1 -> V_27 = V_28 ;
V_1 -> V_95 = ( V_111 << 4 ) | V_218 ;
V_1 -> V_42 = V_42 ;
V_1 -> V_37 = V_98 ;
V_1 -> V_219 = V_220 ;
V_1 -> V_19 = V_221 |
V_222 ;
V_1 -> V_31 [ 0 ] = 'h' ;
V_1 -> V_31 [ 1 ] = 'd' ;
V_1 -> V_31 [ 2 ] = 'a' + V_146 ;
V_1 -> V_223 = V_224 ;
F_99 ( & V_1 -> V_225 ) ;
F_100 ( & V_1 -> V_104 ) ;
}
}
static void F_101 ( T_4 * V_42 , unsigned int V_173 )
{
V_42 -> V_173 = V_173 ;
V_42 -> V_169 = V_226 [ V_173 ] ;
V_42 -> V_31 [ 0 ] = 'i' ;
V_42 -> V_31 [ 1 ] = 'd' ;
V_42 -> V_31 [ 2 ] = 'e' ;
V_42 -> V_31 [ 3 ] = '0' + V_173 ;
F_102 ( & V_42 -> V_227 ) ;
F_103 ( & V_42 -> V_228 , & V_229 , ( unsigned long ) V_42 ) ;
F_100 ( & V_42 -> V_104 ) ;
V_42 -> V_45 = & V_230 ;
F_98 ( V_42 ) ;
}
static void F_104 ( T_4 * V_42 , struct V_231 * V_232 )
{
memcpy ( & V_42 -> V_58 , & V_232 -> V_58 , sizeof( V_42 -> V_58 ) ) ;
V_42 -> V_118 = V_232 -> V_118 ;
V_42 -> V_102 = V_232 -> V_102 ;
V_42 -> V_103 . V_106 = V_232 -> V_106 ? V_232 -> V_106 : V_232 -> V_102 ;
V_42 -> V_233 = V_232 -> V_234 ;
}
static int F_105 ( const struct V_194 * V_195 )
{
int V_235 = - V_236 ;
T_3 V_237 = ( V_195 && ( V_195 -> V_69 & V_238 ) ) ? 0 : 1 ;
T_3 V_111 = ( V_195 && ( V_195 -> V_69 & V_239 ) ) ? 1 : 0 ;
F_67 ( & V_147 ) ;
if ( V_237 ) {
if ( ( V_240 | V_111 ) != ( 1 << V_241 ) - 1 )
V_235 = F_106 ( V_240 | V_111 ) ;
} else {
if ( ( V_240 | 3 ) != ( 1 << V_241 ) - 1 )
V_235 = F_106 ( V_240 | 3 ) ;
else if ( ( V_240 & 3 ) != 3 )
V_235 = F_106 ( V_240 ) ;
}
if ( V_235 >= 0 )
V_240 |= ( 1 << V_235 ) ;
F_68 ( & V_147 ) ;
return V_235 ;
}
static void F_107 ( int V_235 )
{
F_67 ( & V_147 ) ;
V_240 &= ~ ( 1 << V_235 ) ;
F_68 ( & V_147 ) ;
}
static void F_108 ( T_4 * V_42 )
{
T_1 * V_1 ;
int V_111 ;
F_43 (i, drive, hwif) {
F_109 ( V_1 -> V_217 ) ;
F_109 ( V_1 -> V_2 ) ;
F_109 ( V_1 ) ;
}
}
static int F_110 ( T_4 * V_42 , int V_242 )
{
T_1 * V_1 ;
int V_111 ;
for ( V_111 = 0 ; V_111 < V_174 ; V_111 ++ ) {
V_1 = F_111 ( sizeof( * V_1 ) , V_137 , V_242 ) ;
if ( V_1 == NULL )
goto V_243;
V_1 -> V_2 = F_111 ( V_47 , V_137 , V_242 ) ;
if ( V_1 -> V_2 == NULL )
goto V_244;
V_1 -> V_217 = F_90 ( sizeof( struct V_127 ) +
sizeof( struct V_130 ) , V_137 ) ;
if ( ! V_1 -> V_217 )
goto V_245;
V_42 -> V_97 [ V_111 ] = V_1 ;
}
return 0 ;
V_245:
F_109 ( V_1 -> V_2 ) ;
V_244:
F_109 ( V_1 ) ;
V_243:
F_108 ( V_42 ) ;
return - V_246 ;
}
struct V_148 * F_112 ( const struct V_194 * V_195 ,
struct V_231 * * V_247 , unsigned int V_248 )
{
struct V_148 * V_149 ;
struct V_92 * V_102 = V_247 [ 0 ] ? V_247 [ 0 ] -> V_102 : NULL ;
int V_242 = V_102 ? F_113 ( V_102 ) : - 1 ;
int V_111 ;
V_149 = F_111 ( sizeof( * V_149 ) , V_137 , V_242 ) ;
if ( V_149 == NULL )
return NULL ;
for ( V_111 = 0 ; V_111 < V_248 ; V_111 ++ ) {
T_4 * V_42 ;
int V_235 ;
if ( V_247 [ V_111 ] == NULL )
continue;
V_42 = F_111 ( sizeof( * V_42 ) , V_137 , V_242 ) ;
if ( V_42 == NULL )
continue;
if ( F_110 ( V_42 , V_242 ) < 0 ) {
F_109 ( V_42 ) ;
continue;
}
V_235 = F_105 ( V_195 ) ;
if ( V_235 < 0 ) {
F_8 ( V_88 L_53 ,
V_195 ? V_195 -> V_31 : L_54 ) ;
F_108 ( V_42 ) ;
F_109 ( V_42 ) ;
continue;
}
F_101 ( V_42 , V_235 ) ;
V_42 -> V_149 = V_149 ;
V_149 -> V_249 [ V_111 ] = V_42 ;
V_149 -> V_248 ++ ;
}
if ( V_149 -> V_248 == 0 ) {
F_109 ( V_149 ) ;
return NULL ;
}
V_149 -> V_102 [ 0 ] = V_102 ;
if ( V_195 ) {
V_149 -> V_250 = V_195 -> V_250 ;
V_149 -> V_154 = V_195 -> V_154 ;
V_149 -> V_251 = V_195 -> V_251 ;
V_149 -> V_69 = V_195 -> V_69 ;
V_149 -> V_152 = V_195 -> V_152 ;
}
return V_149 ;
}
static void F_114 ( T_4 * V_42 )
{
F_108 ( V_42 ) ;
F_107 ( V_42 -> V_173 ) ;
F_109 ( V_42 ) ;
}
static void F_115 ( T_4 * V_42 )
{
struct V_148 * V_149 = V_42 -> V_149 ;
int V_111 ;
F_8 ( V_30 L_55 , V_42 -> V_31 ) ;
for ( V_111 = 0 ; V_111 < V_252 ; V_111 ++ ) {
if ( V_149 -> V_249 [ V_111 ] == V_42 ) {
V_149 -> V_249 [ V_111 ] = NULL ;
V_149 -> V_248 -- ;
}
}
F_114 ( V_42 ) ;
}
int F_116 ( struct V_148 * V_149 , const struct V_194 * V_195 ,
struct V_231 * * V_247 )
{
T_4 * V_42 , * V_253 = NULL ;
int V_111 , V_146 = 0 ;
F_70 (i, hwif, host) {
if ( V_42 == NULL ) {
V_253 = NULL ;
continue;
}
F_104 ( V_42 , V_247 [ V_111 ] ) ;
F_117 ( V_42 ) ;
if ( ( V_111 & 1 ) && V_253 ) {
V_42 -> V_253 = V_253 ;
V_253 -> V_253 = V_42 ;
}
V_253 = ( V_111 & 1 ) ? NULL : V_42 ;
F_95 ( V_42 , V_111 & 1 , V_195 ) ;
F_97 ( V_42 ) ;
V_42 -> V_254 |= V_255 ;
F_94 ( V_42 ) ;
}
F_70 (i, hwif, host) {
if ( V_42 == NULL )
continue;
if ( F_45 ( V_42 ) == 0 )
V_42 -> V_93 = 1 ;
V_42 -> V_254 &= ~ V_255 ;
if ( ( V_42 -> V_69 & V_256 ) == 0 ||
V_42 -> V_253 == NULL || V_42 -> V_253 -> V_93 == 0 ) {
if ( F_32 ( V_42 ) ) {
F_115 ( V_42 ) ;
continue;
}
}
if ( V_42 -> V_93 )
F_49 ( V_42 ) ;
}
F_69 ( V_149 ) ;
F_70 (i, hwif, host) {
if ( V_42 == NULL )
continue;
if ( F_88 ( V_42 ) == 0 ) {
F_8 ( V_30 L_56
L_57 , V_42 -> V_31 ) ;
F_40 ( & V_42 -> V_103 ) ;
F_115 ( V_42 ) ;
continue;
}
if ( V_42 -> V_93 )
if ( F_66 ( V_42 ) == 0 ) {
V_42 -> V_93 = 0 ;
continue;
}
V_146 ++ ;
F_118 ( V_42 ) ;
if ( V_42 -> V_93 )
F_119 ( V_42 ) ;
}
F_70 (i, hwif, host) {
if ( V_42 == NULL )
continue;
F_120 ( V_42 ) ;
F_121 ( V_42 ) ;
if ( V_42 -> V_93 ) {
F_122 ( V_42 ) ;
F_93 ( V_42 ) ;
}
}
return V_146 ? 0 : - 1 ;
}
int F_123 ( const struct V_194 * V_195 , struct V_231 * * V_247 ,
unsigned int V_248 , struct V_148 * * V_257 )
{
struct V_148 * V_149 ;
int V_61 ;
V_149 = F_112 ( V_195 , V_247 , V_248 ) ;
if ( V_149 == NULL )
return - V_246 ;
V_61 = F_116 ( V_149 , V_195 , V_247 ) ;
if ( V_61 ) {
F_124 ( V_149 ) ;
return V_61 ;
}
if ( V_257 )
* V_257 = V_149 ;
return 0 ;
}
static void F_125 ( T_4 * V_42 )
{
T_1 * V_1 ;
int V_111 ;
F_50 (i, drive, hwif) {
F_40 ( & V_1 -> V_103 ) ;
F_126 ( & V_1 -> V_104 ) ;
}
}
void F_127 ( T_4 * V_42 )
{
F_67 ( & V_147 ) ;
F_125 ( V_42 ) ;
V_42 -> V_93 = 0 ;
F_98 ( V_42 ) ;
F_68 ( & V_147 ) ;
}
static void F_128 ( T_4 * V_42 )
{
F_46 ( F_129 () ) ;
F_46 ( F_130 () ) ;
F_67 ( & V_147 ) ;
if ( V_42 -> V_93 ) {
F_125 ( V_42 ) ;
V_42 -> V_93 = 0 ;
}
F_131 ( V_42 ) ;
if ( ! V_42 -> V_149 -> V_154 )
F_132 ( V_42 -> V_118 , V_42 ) ;
F_40 ( V_42 -> V_109 ) ;
F_40 ( & V_42 -> V_103 ) ;
F_126 ( & V_42 -> V_104 ) ;
F_84 ( F_37 ( V_42 -> V_169 , 0 ) , V_174 << V_164 ) ;
F_109 ( V_42 -> V_176 ) ;
F_92 ( V_42 -> V_169 , V_42 -> V_31 ) ;
F_133 ( V_42 ) ;
F_68 ( & V_147 ) ;
}
void F_124 ( struct V_148 * V_149 )
{
T_4 * V_42 ;
int V_111 ;
F_70 (i, hwif, host) {
if ( V_42 )
F_114 ( V_42 ) ;
}
F_109 ( V_149 ) ;
}
void F_134 ( struct V_148 * V_149 )
{
T_4 * V_42 ;
int V_111 ;
F_70 (i, hwif, host) {
if ( V_42 )
F_128 ( V_42 ) ;
}
F_124 ( V_149 ) ;
}
void F_135 ( T_4 * V_42 )
{
int V_61 ;
F_117 ( V_42 ) ;
F_97 ( V_42 ) ;
V_42 -> V_254 |= V_255 ;
F_94 ( V_42 ) ;
V_61 = F_45 ( V_42 ) ;
V_42 -> V_254 &= ~ V_255 ;
if ( V_61 < 0 )
return;
V_42 -> V_93 = 1 ;
F_49 ( V_42 ) ;
F_66 ( V_42 ) ;
F_119 ( V_42 ) ;
F_93 ( V_42 ) ;
F_122 ( V_42 ) ;
}
