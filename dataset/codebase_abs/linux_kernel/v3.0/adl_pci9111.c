static int T_1 F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
return F_2 ( V_2 , V_5 . V_6 ) ;
}
static void T_2 F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
}
static int T_3 F_5 ( void )
{
int V_7 ;
V_7 = F_6 ( & V_5 ) ;
if ( V_7 < 0 )
return V_7 ;
V_8 . V_9 = ( char * ) V_5 . V_6 ;
return F_7 ( & V_8 ) ;
}
static void T_4 F_8 ( void )
{
F_9 ( & V_8 ) ;
F_10 ( & V_5 ) ;
}
static void F_11 ( unsigned long V_10 ,
bool V_11 ,
bool V_12 ,
bool V_13 ,
bool V_14 ,
bool V_15 )
{
int V_16 = 0 ;
if ( V_11 )
V_16 |= V_17 ;
if ( V_12 )
V_16 |= V_18 ;
if ( V_13 )
V_16 |= V_19 ;
if ( V_14 )
V_16 |= V_20 ;
if ( V_15 )
V_16 |= V_21 ;
F_12 ( V_16 , V_10 + V_22 ) ;
}
static void F_13 ( struct V_23 * V_2 )
{
F_14 ( V_24 |
V_25 |
V_26 |
V_27 ) ;
F_14 ( V_28 |
V_25 |
V_29 |
V_27 ) ;
F_14 ( V_30 |
V_25 |
V_29 |
V_27 ) ;
F_15 ( 1 ) ;
F_16 ( V_31 -> V_32 ) ;
F_17 ( V_31 -> V_33 ) ;
}
static void F_18 ( struct V_23 * V_2 ,
enum V_34 V_35 )
{
int V_16 ;
V_16 = F_19 () & 0x09 ;
switch ( V_35 ) {
case V_36 :
V_16 |= V_37 | V_38 ;
break;
case V_39 :
V_16 |= V_37 | V_40 ;
break;
case V_41 :
V_16 |= V_42 ;
break;
}
F_20 ( V_16 ) ;
}
static void F_21 ( struct V_23 * V_2 , bool V_43 )
{
int V_16 ;
V_16 = F_19 () & 0x07 ;
if ( V_43 )
V_16 |= V_44 ;
F_20 ( V_16 ) ;
}
static void F_22 ( struct V_23 * V_2 , bool V_45 )
{
int V_16 ;
V_16 = F_19 () & 0x0e ;
if ( V_45 )
V_16 |= V_46 ;
F_20 ( V_16 ) ;
}
static void F_23 ( struct V_23 * V_2 ,
enum V_47 V_48 ,
enum V_49 V_50 )
{
int V_16 ;
V_16 = F_24 () & 0x04 ;
if ( V_48 == V_51 )
V_16 |= V_52 ;
if ( V_50 == V_53 )
V_16 |= V_54 ;
F_25 ( V_16 ) ;
}
static int F_26 ( struct V_23 * V_2 ,
struct V_55 * V_56 )
{
F_11 ( V_31 -> V_57 , true , true , true ,
true , false ) ;
F_18 ( V_2 , V_36 ) ;
F_22 ( V_2 , false ) ;
F_27 () ;
#ifdef F_28
F_29 ( V_58 L_1 ) ;
#endif
return 0 ;
}
static int
F_30 ( struct V_23 * V_2 ,
struct V_55 * V_56 , struct V_59 * V_60 )
{
int V_61 ;
int error = 0 ;
int V_62 , V_63 ;
int V_64 ;
struct V_65 * V_66 = (struct V_65 * ) V_2 -> V_67 ;
F_31 ( V_60 -> V_68 , V_69 ) ;
F_31 ( V_60 -> V_70 ,
V_71 | V_72 | V_73 ) ;
F_31 ( V_60 -> V_74 , V_71 | V_73 ) ;
F_31 ( V_60 -> V_75 , V_76 ) ;
F_31 ( V_60 -> V_77 , V_76 | V_78 ) ;
if ( error )
return 1 ;
if ( V_60 -> V_68 != V_69 )
error ++ ;
if ( ( V_60 -> V_70 != V_71 ) &&
( V_60 -> V_70 != V_72 ) &&
( V_60 -> V_70 != V_73 ) )
error ++ ;
if ( ( V_60 -> V_74 != V_71 ) && ( V_60 -> V_74 != V_73 ) )
error ++ ;
if ( ( V_60 -> V_74 == V_71 ) &&
! ( ( V_60 -> V_70 == V_71 ) ||
( V_60 -> V_70 == V_72 ) ) )
error ++ ;
if ( ( V_60 -> V_74 == V_73 ) &&
! ( ( V_60 -> V_70 == V_73 ) ||
( V_60 -> V_70 == V_72 ) ) )
error ++ ;
if ( V_60 -> V_75 != V_76 )
error ++ ;
if ( ( V_60 -> V_77 != V_76 ) && ( V_60 -> V_77 != V_78 ) )
error ++ ;
if ( error )
return 2 ;
if ( V_60 -> V_79 < 1 ) {
V_60 -> V_79 = 1 ;
error ++ ;
}
if ( V_60 -> V_79 > V_66 -> V_80 ) {
V_60 -> V_79 = V_66 -> V_80 ;
error ++ ;
}
if ( ( V_60 -> V_68 == V_69 ) && ( V_60 -> V_81 != 0 ) ) {
V_60 -> V_81 = 0 ;
error ++ ;
}
if ( ( V_60 -> V_74 == V_71 ) &&
( V_60 -> V_82 < V_66 -> V_83 ) ) {
V_60 -> V_82 = V_66 -> V_83 ;
error ++ ;
}
if ( ( V_60 -> V_74 == V_73 ) && ( V_60 -> V_82 != 0 ) ) {
V_60 -> V_82 = 0 ;
error ++ ;
}
if ( ( V_60 -> V_70 == V_71 ) &&
( V_60 -> V_84 < V_66 -> V_83 ) ) {
V_60 -> V_84 = V_66 -> V_83 ;
error ++ ;
}
if ( ( V_60 -> V_70 == V_72 )
&& ( V_60 -> V_84 != 0 ) ) {
V_60 -> V_84 = 0 ;
error ++ ;
}
if ( ( V_60 -> V_70 == V_73 ) && ( V_60 -> V_84 != 0 ) ) {
V_60 -> V_84 = 0 ;
error ++ ;
}
if ( ( V_60 -> V_75 == V_76 ) &&
( V_60 -> V_85 != V_60 -> V_79 ) ) {
V_60 -> V_85 = V_60 -> V_79 ;
error ++ ;
}
if ( ( V_60 -> V_77 == V_76 ) && ( V_60 -> V_86 < 1 ) ) {
V_60 -> V_86 = 1 ;
error ++ ;
}
if ( ( V_60 -> V_77 == V_78 ) && ( V_60 -> V_86 != 0 ) ) {
V_60 -> V_86 = 0 ;
error ++ ;
}
if ( error )
return 3 ;
if ( V_60 -> V_74 == V_71 ) {
V_61 = V_60 -> V_82 ;
F_32 ( V_87 ,
& ( V_31 -> V_33 ) ,
& ( V_31 -> V_32 ) ,
& ( V_60 -> V_82 ) ,
V_60 -> V_16 & V_88 ) ;
if ( V_61 != V_60 -> V_82 )
error ++ ;
}
if ( V_60 -> V_70 == V_71 ) {
unsigned int V_89 ;
unsigned int V_84 ;
unsigned int V_90 ;
V_89 = V_60 -> V_79 * V_60 -> V_82 ;
if ( V_60 -> V_84 != V_89 ) {
if ( V_89 < V_60 -> V_84 ) {
V_90 =
V_60 -> V_84 / V_89 ;
V_84 = V_90 * V_89 ;
if ( V_60 -> V_84 != V_84 ) {
V_60 -> V_84 = V_84 ;
error ++ ;
}
} else {
V_60 -> V_84 = V_89 ;
error ++ ;
}
}
}
if ( error )
return 4 ;
if ( V_60 -> V_91 ) {
V_62 = F_33 ( V_60 -> V_91 [ 0 ] ) ;
V_63 = F_34 ( V_60 -> V_91 [ 0 ] ) ;
if ( V_60 -> V_79 > 1 ) {
for ( V_64 = 0 ; V_64 < V_60 -> V_79 ; V_64 ++ ) {
if ( F_35 ( V_60 -> V_91 [ V_64 ] ) != V_64 ) {
F_36 ( V_2 ,
L_2
L_3 ) ;
error ++ ;
}
if ( F_33 ( V_60 -> V_91 [ V_64 ] ) != V_62 ) {
F_36 ( V_2 ,
L_4 ) ;
error ++ ;
}
if ( F_34 ( V_60 -> V_91 [ V_64 ] ) != V_63 ) {
F_36 ( V_2 ,
L_5 ) ;
error ++ ;
}
}
} else {
if ( ( F_35 ( V_60 -> V_91 [ 0 ] ) >
( V_66 -> V_80 - 1 ) )
|| ( F_35 ( V_60 -> V_91 [ 0 ] ) < 0 ) ) {
F_36 ( V_2 ,
L_6 ) ;
error ++ ;
}
}
}
if ( error )
return 5 ;
return 0 ;
}
static int F_37 ( struct V_23 * V_2 ,
struct V_55 * V_92 )
{
struct V_59 * V_93 = & V_92 -> V_94 -> V_60 ;
if ( ! V_2 -> V_95 ) {
F_36 ( V_2 ,
L_7 ) ;
return - 1 ;
}
if ( V_93 -> V_79 > 1 ) {
F_38 ( ( V_93 -> V_79 ) - 1 ) ;
F_22 ( V_2 , true ) ;
} else {
F_38 ( F_35 ( V_93 -> V_91 [ 0 ] ) ) ;
F_22 ( V_2 , false ) ;
}
F_39 ( F_33 ( V_93 -> V_91 [ 0 ] ) ) ;
switch ( V_93 -> V_77 ) {
case V_76 :
V_31 -> V_96 =
V_93 -> V_86 * V_93 -> V_79 ;
V_31 -> V_97 = 0 ;
break;
case V_78 :
V_31 -> V_96 = 0 ;
V_31 -> V_97 = 1 ;
break;
default:
F_36 ( V_2 , L_8 ) ;
return - 1 ;
}
V_31 -> V_98 = 0 ;
switch ( V_93 -> V_74 ) {
case V_71 :
F_32 ( V_87 ,
& ( V_31 -> V_33 ) ,
& ( V_31 -> V_32 ) ,
& ( V_93 -> V_82 ) ,
V_93 ->
V_16 & V_88 ) ;
#ifdef F_28
F_29 ( V_58 L_9 ,
V_31 -> V_33 ,
V_31 -> V_32 ) ;
#endif
F_18 ( V_2 , V_36 ) ;
F_13 ( V_2 ) ;
F_27 () ;
F_23 ( V_2 , V_51 ,
V_99 ) ;
F_18 ( V_2 , V_39 ) ;
F_11 ( V_31 -> V_57 , true , true ,
false , true , true ) ;
if ( V_93 -> V_70 == V_71 ) {
V_31 -> V_98 =
( V_93 -> V_84 /
( V_93 -> V_82 *
V_93 -> V_79 ) ) - 1 ;
}
break;
case V_73 :
F_18 ( V_2 , V_41 ) ;
F_27 () ;
F_23 ( V_2 , V_51 ,
V_99 ) ;
F_11 ( V_31 -> V_57 , true , true ,
false , true , true ) ;
break;
default:
F_36 ( V_2 , L_10 ) ;
return - 1 ;
}
V_31 -> V_96 *= ( 1 + V_31 -> V_98 ) ;
V_31 -> V_79 = V_93 -> V_79 ;
V_31 -> V_100 = 0 ;
V_31 -> V_101 =
V_31 -> V_79 * ( 1 + V_31 -> V_98 ) ;
#ifdef F_28
F_29 ( V_58 L_11 ) ;
F_29 ( V_58 L_12 ,
F_19 () ) ;
F_29 ( V_58 L_13 ,
F_24 () ) ;
F_29 ( V_58 L_14 ) ;
F_29 ( V_58 L_15 ,
V_31 -> V_96 ) ;
F_29 ( V_58 L_16 ,
V_31 -> V_98 ) ;
F_29 ( V_58 L_17 ,
V_31 -> V_79 ) ;
F_29 ( V_58 L_18 ,
V_31 -> V_101 ) ;
#endif
return 0 ;
}
static void F_40 ( struct V_23 * V_2 ,
struct V_55 * V_56 , void * V_102 ,
unsigned int V_103 ,
unsigned int V_104 )
{
unsigned int V_64 , V_105 = V_103 / sizeof( short ) ;
short * V_106 = V_102 ;
int V_107 =
( (struct V_65 * ) V_2 -> V_67 ) -> V_108 ;
for ( V_64 = 0 ; V_64 < V_105 ; V_64 ++ ) {
if ( V_107 == V_109 )
V_106 [ V_64 ] =
( V_106 [ V_64 ] & V_110 ) ^
V_111 ;
else
V_106 [ V_64 ] =
( ( V_106 [ V_64 ] >> 4 ) & V_112 ) ^
V_113 ;
}
}
static T_5 F_41 ( int V_95 , void * V_114 )
{
struct V_23 * V_2 = V_114 ;
struct V_55 * V_92 = V_2 -> V_115 ;
struct V_116 * V_94 ;
unsigned long V_117 ;
unsigned char V_118 ;
if ( ! V_2 -> V_119 ) {
return V_120 ;
}
V_94 = V_92 -> V_94 ;
F_42 ( & V_2 -> V_121 , V_117 ) ;
V_118 = F_43 ( V_31 -> V_57 +
V_22 ) ;
if ( ! ( ( ( V_118 & V_21 ) != 0 )
&& ( ( ( V_118 & ( V_17 | V_122 ) )
== ( V_17 | V_122 ) )
|| ( ( V_118 & ( V_19 | V_123 ) )
== ( V_19 | V_123 ) ) ) ) ) {
F_44 ( & V_2 -> V_121 , V_117 ) ;
return V_120 ;
}
if ( ( V_118 & ( V_17 | V_122 ) ) ==
( V_17 | V_122 ) ) {
if ( F_45 () ) {
F_44 ( & V_2 -> V_121 , V_117 ) ;
F_36 ( V_2 , V_58 L_19 ) ;
F_46 () ;
F_26 ( V_2 , V_92 ) ;
V_94 -> V_124 |= V_125 | V_126 ;
F_47 ( V_2 , V_92 ) ;
return V_127 ;
}
if ( F_48 () ) {
unsigned int V_105 ;
unsigned int V_128 = 0 ;
#ifdef F_49
F_29 ( V_58 L_20 ) ;
#endif
V_105 =
V_129 >
V_31 -> V_96
&& ! V_31 ->
V_97 ? V_31 -> V_96 :
V_129 ;
F_50 ( V_130 + V_131 ,
V_31 -> V_132 , V_105 ) ;
if ( V_31 -> V_98 < 1 ) {
V_128 =
F_51 ( V_92 ,
V_31 ->
V_132 ,
V_105 *
sizeof( short ) ) ;
} else {
int V_133 = 0 ;
int V_134 ;
while ( V_133 < V_105 ) {
if ( V_31 -> V_100 <
V_31 -> V_79 ) {
V_134 =
V_31 -> V_79 -
V_31 -> V_100 ;
if ( V_134 >
V_105 - V_133 )
V_134 =
V_105 -
V_133 ;
V_128 +=
F_51
( V_92 ,
V_31 -> V_132
+ V_133 ,
V_134 * sizeof( short ) ) ;
} else {
V_134 =
V_31 -> V_101
-
V_31 -> V_100 ;
if ( V_134 >
V_105 - V_133 )
V_134 =
V_105 -
V_133 ;
V_128 +=
sizeof( short ) * V_134 ;
}
V_133 += V_134 ;
V_31 -> V_100 += V_134 ;
if ( V_31 -> V_100 >=
V_31 -> V_101 )
V_31 -> V_100 = 0 ;
}
}
V_31 -> V_96 -=
V_128 / sizeof( short ) ;
}
}
if ( ( V_31 -> V_96 == 0 ) && ( ! V_31 -> V_97 ) ) {
V_94 -> V_124 |= V_126 ;
F_26 ( V_2 , V_92 ) ;
}
F_46 () ;
F_44 ( & V_2 -> V_121 , V_117 ) ;
F_47 ( V_2 , V_92 ) ;
return V_127 ;
}
static int F_52 ( struct V_23 * V_2 ,
struct V_55 * V_92 ,
struct V_135 * V_136 , unsigned int * V_102 )
{
int V_107 =
( (struct V_65 * ) V_2 -> V_67 ) -> V_108 ;
int V_137 , V_64 ;
#ifdef F_53
F_29 ( V_58 L_21 ,
F_35 ( ( & V_136 -> V_138 ) [ 0 ] ) ,
F_33 ( ( & V_136 -> V_138 ) [ 0 ] ) , V_136 -> V_139 ) ;
#endif
F_38 ( F_35 ( ( & V_136 -> V_138 ) [ 0 ] ) ) ;
if ( ( F_54 () ) != F_33 ( ( & V_136 -> V_138 ) [ 0 ] ) )
F_39 ( F_33 ( ( & V_136 -> V_138 ) [ 0 ] ) ) ;
F_27 () ;
for ( V_64 = 0 ; V_64 < V_136 -> V_139 ; V_64 ++ ) {
F_55 () ;
V_137 = V_140 ;
while ( V_137 -- ) {
if ( ! F_56 () )
goto V_141;
}
F_36 ( V_2 , L_22 ) ;
V_102 [ V_64 ] = 0 ;
F_27 () ;
return - V_142 ;
V_141:
if ( V_107 == V_109 )
V_102 [ V_64 ] = F_57 () ;
else
V_102 [ V_64 ] = F_58 () ;
}
#ifdef F_53
F_29 ( V_58 L_23 ,
F_59 () ,
F_54 () , F_19 () ) ;
#endif
return V_64 ;
}
static int
F_60 ( struct V_23 * V_2 ,
struct V_55 * V_56 , struct V_135 * V_136 ,
unsigned int * V_102 )
{
int V_64 ;
for ( V_64 = 0 ; V_64 < V_136 -> V_139 ; V_64 ++ ) {
F_61 ( V_102 [ V_64 ] ) ;
V_31 -> V_143 = V_102 [ V_64 ] ;
}
return V_64 ;
}
static int F_62 ( struct V_23 * V_2 ,
struct V_55 * V_56 ,
struct V_135 * V_136 , unsigned int * V_102 )
{
int V_64 ;
for ( V_64 = 0 ; V_64 < V_136 -> V_139 ; V_64 ++ )
V_102 [ V_64 ] = V_31 -> V_143 & V_144 ;
return V_64 ;
}
static int F_63 ( struct V_23 * V_2 ,
struct V_55 * V_92 ,
struct V_135 * V_136 , unsigned int * V_102 )
{
unsigned int V_145 ;
V_145 = F_64 () ;
V_102 [ 1 ] = V_145 ;
return 2 ;
}
static int F_65 ( struct V_23 * V_2 ,
struct V_55 * V_92 ,
struct V_135 * V_136 , unsigned int * V_102 )
{
unsigned int V_145 ;
V_102 [ 0 ] &= V_146 ;
V_145 = V_92 -> V_147 ;
V_145 &= ~ V_102 [ 0 ] ;
V_145 |= V_102 [ 0 ] & V_102 [ 1 ] ;
V_92 -> V_147 = V_145 ;
F_66 ( V_145 ) ;
V_102 [ 1 ] = V_145 ;
return 2 ;
}
static int F_67 ( struct V_23 * V_2 )
{
F_11 ( V_31 -> V_57 , true , true , true ,
true , false ) ;
F_18 ( V_2 , V_36 ) ;
F_21 ( V_2 , false ) ;
F_22 ( V_2 , false ) ;
V_31 -> V_33 = 0 ;
V_31 -> V_32 = 0 ;
F_13 ( V_2 ) ;
return 0 ;
}
static int F_68 ( struct V_23 * V_2 ,
struct V_148 * V_149 )
{
struct V_55 * V_92 ;
unsigned long V_10 , V_150 , V_57 , V_151 ;
struct V_1 * V_152 = NULL ;
int error , V_64 ;
const struct V_65 * V_66 ;
if ( F_69 ( V_2 , sizeof( struct V_153 ) ) < 0 )
return - V_154 ;
F_29 ( V_155 L_24 V_58 L_25 ,
V_2 -> V_156 ) ;
F_70 (pci_device) {
if ( V_152 -> V_157 == V_158 ) {
for ( V_64 = 0 ; V_64 < V_159 ; V_64 ++ ) {
if ( V_160 [ V_64 ] . V_161 ==
V_152 -> V_162 ) {
if ( ( V_149 -> V_163 [ 0 ] != 0 )
|| ( V_149 -> V_163 [ 1 ] != 0 ) ) {
if ( V_152 -> V_164 -> V_165 !=
V_149 -> V_163 [ 0 ]
||
F_71 ( V_152 -> V_166 )
!= V_149 -> V_163 [ 1 ] ) {
continue;
}
}
V_2 -> V_67 = V_160 + V_64 ;
V_66 =
(struct V_65 * )
V_2 -> V_67 ;
V_31 -> V_152 = V_152 ;
goto V_167;
}
}
}
}
F_29 ( V_155
L_26 ,
V_2 -> V_156 , V_149 -> V_163 [ 0 ] , V_149 -> V_163 [ 1 ] ) ;
return - V_168 ;
V_167:
F_29 ( V_155 L_27 ,
V_2 -> V_156 ,
V_160 [ V_64 ] . V_9 ,
V_152 -> V_164 -> V_165 ,
F_71 ( V_152 -> V_166 ) ,
F_72 ( V_152 -> V_166 ) , V_152 -> V_95 ) ;
V_57 = F_73 ( V_152 , 1 ) ;
V_151 = F_74 ( V_152 , 1 ) ;
F_29
( L_28 ,
V_2 -> V_156 , V_57 , V_151 ) ;
if ( F_75 ( V_152 , V_58 ) < 0 ) {
F_29
( L_29 ,
V_2 -> V_156 ) ;
return - V_168 ;
}
V_10 = F_73 ( V_152 , 2 ) ;
V_150 = F_74 ( V_152 , 2 ) ;
F_29 ( V_155 L_30 ,
V_2 -> V_156 , V_10 , V_150 ) ;
V_2 -> V_169 = V_10 ;
V_2 -> V_170 = V_66 -> V_9 ;
V_31 -> V_150 = V_150 ;
V_31 -> V_171 = 0 ;
V_31 -> V_57 = V_57 ;
V_31 -> V_151 = V_151 ;
F_67 ( V_2 ) ;
V_2 -> V_95 = 0 ;
if ( V_152 -> V_95 > 0 ) {
if ( F_76 ( V_152 -> V_95 , F_41 ,
V_172 , V_58 , V_2 ) != 0 ) {
F_29 ( V_155
L_31 ,
V_2 -> V_156 , V_152 -> V_95 ) ;
return - V_173 ;
}
}
V_2 -> V_95 = V_152 -> V_95 ;
error = F_77 ( V_2 , 4 ) ;
if ( error < 0 )
return error ;
V_92 = V_2 -> V_174 + 0 ;
V_2 -> V_115 = V_92 ;
V_92 -> type = V_175 ;
V_92 -> V_176 = V_177 | V_178 | V_179 ;
V_92 -> V_180 = V_66 -> V_80 ;
V_92 -> V_181 = V_66 -> V_182 ;
V_92 -> V_183 = V_66 -> V_80 ;
V_92 -> V_184 = V_66 -> V_185 ;
V_92 -> V_186 = F_26 ;
V_92 -> V_187 = F_52 ;
V_92 -> V_188 = F_30 ;
V_92 -> V_189 = F_37 ;
V_92 -> V_190 = F_40 ;
V_92 = V_2 -> V_174 + 1 ;
V_92 -> type = V_191 ;
V_92 -> V_176 = V_192 | V_178 ;
V_92 -> V_180 = V_66 -> V_193 ;
V_92 -> V_181 = V_66 -> V_194 ;
V_92 -> V_183 = V_66 -> V_193 ;
V_92 -> V_184 = V_66 -> V_195 ;
V_92 -> V_196 = F_60 ;
V_92 -> V_187 = F_62 ;
V_92 = V_2 -> V_174 + 2 ;
V_92 -> type = V_197 ;
V_92 -> V_176 = V_177 ;
V_92 -> V_180 = V_198 ;
V_92 -> V_181 = 1 ;
V_92 -> V_184 = & V_199 ;
V_92 -> V_200 = F_63 ;
V_92 = V_2 -> V_174 + 3 ;
V_92 -> type = V_201 ;
V_92 -> V_176 = V_177 | V_192 ;
V_92 -> V_180 = V_202 ;
V_92 -> V_181 = 1 ;
V_92 -> V_184 = & V_199 ;
V_92 -> V_200 = F_65 ;
V_31 -> V_171 = 1 ;
return 0 ;
}
static int F_78 ( struct V_23 * V_2 )
{
if ( V_2 -> V_203 != NULL ) {
if ( V_31 -> V_171 )
F_67 ( V_2 ) ;
}
if ( V_2 -> V_95 != 0 )
F_79 ( V_2 -> V_95 , V_2 ) ;
if ( V_31 != NULL && V_31 -> V_152 != NULL ) {
if ( V_2 -> V_169 )
F_80 ( V_31 -> V_152 ) ;
F_81 ( V_31 -> V_152 ) ;
}
return 0 ;
}
