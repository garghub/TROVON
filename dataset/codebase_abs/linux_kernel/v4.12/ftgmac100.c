static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
F_2 ( V_3 , V_2 -> V_7 + V_8 ) ;
F_2 ( V_3 | V_9 ,
V_2 -> V_7 + V_8 ) ;
for ( V_6 = 0 ; V_6 < 50 ; V_6 ++ ) {
unsigned int V_3 ;
V_3 = F_3 ( V_2 -> V_7 + V_8 ) ;
if ( ! ( V_3 & V_9 ) )
return 0 ;
F_4 ( 1 ) ;
}
F_5 ( V_5 , L_1 ) ;
return - V_10 ;
}
static int F_6 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
switch ( V_2 -> V_11 ) {
case V_12 :
case 0 :
break;
case V_13 :
V_3 |= V_14 ;
break;
case V_15 :
V_3 |= V_16 ;
break;
default:
F_5 ( V_2 -> V_5 , L_2 ,
V_2 -> V_11 ) ;
break;
}
V_2 -> V_17 = 0 ;
V_2 -> V_18 = 0 ;
V_2 -> V_19 = 0 ;
if ( F_1 ( V_2 , V_3 ) )
return - V_10 ;
F_7 ( 10 , 1000 ) ;
return F_1 ( V_2 , V_3 ) ;
}
static void F_8 ( struct V_1 * V_2 , const T_2 * V_20 )
{
unsigned int V_21 = V_20 [ 0 ] << 8 | V_20 [ 1 ] ;
unsigned int V_22 = V_20 [ 2 ] << 24 | V_20 [ 3 ] << 16 | V_20 [ 4 ] << 8 | V_20 [ 5 ] ;
F_2 ( V_21 , V_2 -> V_7 + V_23 ) ;
F_2 ( V_22 , V_2 -> V_7 + V_24 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
T_2 V_20 [ V_25 ] ;
unsigned int V_26 ;
unsigned int V_27 ;
void * V_28 ;
V_28 = F_10 ( V_2 -> V_29 , V_20 , V_25 ) ;
if ( V_28 ) {
F_11 ( V_2 -> V_5 -> V_30 , V_20 ) ;
F_12 ( V_2 -> V_29 , L_3 ,
V_20 ) ;
return;
}
V_26 = F_3 ( V_2 -> V_7 + V_23 ) ;
V_27 = F_3 ( V_2 -> V_7 + V_24 ) ;
V_20 [ 0 ] = ( V_26 >> 8 ) & 0xff ;
V_20 [ 1 ] = V_26 & 0xff ;
V_20 [ 2 ] = ( V_27 >> 24 ) & 0xff ;
V_20 [ 3 ] = ( V_27 >> 16 ) & 0xff ;
V_20 [ 4 ] = ( V_27 >> 8 ) & 0xff ;
V_20 [ 5 ] = V_27 & 0xff ;
if ( F_13 ( V_20 ) ) {
F_11 ( V_2 -> V_5 -> V_30 , V_20 ) ;
F_12 ( V_2 -> V_29 , L_4 , V_20 ) ;
} else {
F_14 ( V_2 -> V_5 ) ;
F_12 ( V_2 -> V_29 , L_5 ,
V_2 -> V_5 -> V_30 ) ;
}
}
static int F_15 ( struct V_4 * V_29 , void * V_31 )
{
int V_32 ;
V_32 = F_16 ( V_29 , V_31 ) ;
if ( V_32 < 0 )
return V_32 ;
F_17 ( V_29 , V_31 ) ;
F_8 ( F_18 ( V_29 ) , V_29 -> V_30 ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
T_1 V_33 = F_20 ( 16 ) ;
if ( V_2 -> V_34 )
V_33 |= V_35 ;
if ( V_2 -> V_36 )
V_33 |= V_37 ;
F_2 ( V_33 , V_2 -> V_7 + V_38 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
T_1 V_39 , V_40 , V_41 ;
V_39 = F_3 ( V_2 -> V_7 + V_42 ) ;
F_2 ( V_39 , V_2 -> V_7 + V_42 ) ;
F_2 ( V_2 -> V_43 , V_2 -> V_7 + V_44 ) ;
F_2 ( V_2 -> V_45 , V_2 -> V_7 + V_46 ) ;
F_2 ( F_22 ( V_47 ) ,
V_2 -> V_7 + V_48 ) ;
F_2 ( F_23 ( 1 ) ,
V_2 -> V_7 + V_49 ) ;
F_8 ( V_2 , V_2 -> V_5 -> V_30 ) ;
F_2 ( V_2 -> V_50 , V_2 -> V_7 + V_51 ) ;
F_2 ( V_2 -> V_52 , V_2 -> V_7 + V_53 ) ;
F_2 ( F_24 ( 2 ) |
F_25 ( 2 ) |
F_26 ( 3 ) |
F_27 ( 3 ) |
V_54 |
F_28 ( 6 ) |
F_29 ( 2 ) ,
V_2 -> V_7 + V_55 ) ;
F_2 ( F_30 ( 1 ) |
F_31 ( 1 ) ,
V_2 -> V_7 + V_56 ) ;
V_39 = F_3 ( V_2 -> V_7 + V_57 ) ;
V_40 = V_39 & 0x00000007 ;
V_41 = ( V_39 >> 3 ) & 0x00000007 ;
V_39 = F_3 ( V_2 -> V_7 + V_58 ) ;
V_39 &= ~ 0x3f000000 ;
V_39 |= ( V_41 << 27 ) ;
V_39 |= ( V_40 << 24 ) ;
F_2 ( V_39 , V_2 -> V_7 + V_58 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
T_1 V_3 = F_3 ( V_2 -> V_7 + V_8 ) ;
V_3 &= ( V_14 | V_16 ) ;
V_3 |= V_59 |
V_60 |
V_61 |
V_62 |
V_63 |
V_64 |
V_65 |
V_66 ;
if ( V_2 -> V_67 == V_68 )
V_3 |= V_69 ;
if ( V_2 -> V_5 -> V_70 & V_71 )
V_3 |= V_72 ;
if ( V_2 -> V_5 -> V_70 & V_73 )
V_3 |= V_74 ;
else if ( F_33 ( V_2 -> V_5 ) )
V_3 |= V_75 ;
if ( V_2 -> V_5 -> V_76 & V_77 )
V_3 |= V_78 ;
F_2 ( V_3 , V_2 -> V_7 + V_8 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_2 ( 0 , V_2 -> V_7 + V_8 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_79 * V_80 ;
V_2 -> V_52 = 0 ;
V_2 -> V_50 = 0 ;
F_36 (ha, priv->netdev) {
T_1 V_81 = F_37 ( V_25 , V_80 -> V_28 ) ;
V_81 = ( ~ ( V_81 >> 2 ) ) & 0x3f ;
if ( V_81 >= 32 )
V_2 -> V_52 |= 1ul << ( V_81 - 32 ) ;
else
V_2 -> V_50 |= 1ul << ( V_81 ) ;
}
}
static void F_38 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_18 ( V_5 ) ;
F_35 ( V_2 ) ;
if ( ! F_39 ( V_5 ) )
return;
F_2 ( V_2 -> V_50 , V_2 -> V_7 + V_51 ) ;
F_2 ( V_2 -> V_52 , V_2 -> V_7 + V_53 ) ;
F_32 ( V_2 ) ;
}
static int F_40 ( struct V_1 * V_2 , unsigned int V_82 ,
struct V_83 * V_84 , T_3 V_85 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_86 * V_87 ;
T_4 V_88 ;
int V_89 ;
V_87 = F_41 ( V_5 , V_47 ) ;
if ( F_42 ( ! V_87 ) ) {
if ( F_43 () )
F_44 ( V_5 , L_6 ) ;
V_89 = - V_90 ;
V_88 = V_2 -> V_91 ;
} else {
V_88 = F_45 ( V_2 -> V_29 , V_87 -> V_92 , V_47 ,
V_93 ) ;
if ( F_42 ( F_46 ( V_2 -> V_29 , V_88 ) ) ) {
if ( F_43 () )
F_5 ( V_5 , L_7 ) ;
F_47 ( V_87 ) ;
V_88 = V_2 -> V_91 ;
V_87 = NULL ;
V_89 = - V_90 ;
}
}
V_2 -> V_94 [ V_82 ] = V_87 ;
V_84 -> V_95 = F_48 ( V_88 ) ;
F_49 () ;
if ( V_82 == ( V_2 -> V_96 - 1 ) )
V_84 -> V_97 = F_48 ( V_2 -> V_98 ) ;
else
V_84 -> V_97 = 0 ;
return 0 ;
}
static unsigned int F_50 ( struct V_1 * V_2 ,
unsigned int V_99 )
{
return ( V_99 + 1 ) & ( V_2 -> V_96 - 1 ) ;
}
static void F_51 ( struct V_1 * V_2 , T_1 V_100 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_100 & V_101 )
V_5 -> V_102 . V_103 ++ ;
if ( V_100 & V_104 )
V_5 -> V_102 . V_105 ++ ;
if ( V_100 & ( V_106 |
V_107 |
V_108 ) )
V_5 -> V_102 . V_109 ++ ;
}
static bool F_52 ( struct V_1 * V_2 , int * V_110 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_83 * V_84 ;
struct V_86 * V_87 ;
unsigned int V_99 , V_111 ;
T_1 V_100 , V_112 ;
T_4 V_88 ;
V_99 = V_2 -> V_17 ;
V_84 = & V_2 -> V_84 [ V_99 ] ;
V_100 = F_53 ( V_84 -> V_97 ) ;
if ( ! ( V_100 & V_113 ) )
return false ;
F_54 () ;
if ( F_42 ( ! ( V_100 & V_114 ) ||
! ( V_100 & V_115 ) ) )
goto V_116;
V_111 = V_100 & V_117 ;
V_112 = F_53 ( V_84 -> V_118 ) ;
if ( F_42 ( V_100 & V_119 ) ) {
if ( ( V_100 & V_107 ) &&
( V_112 & V_120 ) &&
( V_111 >= 60 ) )
V_100 &= ~ V_107 ;
if ( V_100 & V_119 ) {
F_51 ( V_2 , V_100 ) ;
goto V_116;
}
}
V_87 = V_2 -> V_94 [ V_99 ] ;
if ( ! F_42 ( V_87 ) ) {
F_40 ( V_2 , V_99 , V_84 , V_121 ) ;
goto V_116;
}
if ( F_42 ( V_100 & V_122 ) )
V_5 -> V_102 . V_123 ++ ;
if ( V_5 -> V_76 & V_124 ) {
T_1 V_125 = V_126 |
V_127 |
V_128 ;
if ( ( V_112 & V_125 ) ||
! ( V_112 & V_129 ) )
V_87 -> V_130 = V_131 ;
else
V_87 -> V_130 = V_132 ;
}
F_55 ( V_87 , V_111 ) ;
if ( ( V_5 -> V_76 & V_77 ) &&
( V_112 & V_120 ) )
F_56 ( V_87 , F_57 ( V_133 ) ,
V_112 & 0xffff ) ;
V_88 = F_53 ( V_84 -> V_95 ) ;
#if F_58 ( V_134 ) && ! F_58 ( V_135 )
F_59 ( V_2 -> V_29 , V_88 , V_111 , V_93 ) ;
#else
F_59 ( V_2 -> V_29 , V_88 , V_47 , V_93 ) ;
#endif
F_40 ( V_2 , V_99 , V_84 , V_121 ) ;
V_2 -> V_17 = F_50 ( V_2 , V_99 ) ;
V_87 -> V_136 = F_60 ( V_87 , V_5 ) ;
V_5 -> V_102 . V_137 ++ ;
V_5 -> V_102 . V_138 += V_111 ;
if ( V_87 -> V_130 == V_131 )
F_61 ( V_87 ) ;
else
F_62 ( & V_2 -> V_139 , V_87 ) ;
( * V_110 ) ++ ;
return true ;
V_116:
V_84 -> V_97 = F_48 ( V_100 & V_2 -> V_98 ) ;
V_2 -> V_17 = F_50 ( V_2 , V_99 ) ;
V_5 -> V_102 . V_140 ++ ;
return true ;
}
static T_1 F_63 ( struct V_1 * V_2 ,
unsigned int V_141 )
{
if ( V_141 == ( V_2 -> V_142 - 1 ) )
return V_2 -> V_143 ;
else
return 0 ;
}
static unsigned int F_64 ( struct V_1 * V_2 ,
unsigned int V_99 )
{
return ( V_99 + 1 ) & ( V_2 -> V_142 - 1 ) ;
}
static T_1 F_65 ( struct V_1 * V_2 )
{
return ( V_2 -> V_18 - V_2 -> V_19 - 1 ) &
( V_2 -> V_142 - 1 ) ;
}
static bool F_66 ( struct V_1 * V_2 )
{
return V_2 -> V_19 != V_2 -> V_18 ;
}
static void F_67 ( struct V_1 * V_2 ,
unsigned int V_99 ,
struct V_86 * V_87 ,
struct V_144 * V_145 ,
T_1 V_146 )
{
T_4 V_88 = F_53 ( V_145 -> V_147 ) ;
T_5 V_148 ;
if ( V_146 & V_149 ) {
V_148 = F_68 ( V_87 ) ;
F_59 ( V_2 -> V_29 , V_88 , V_148 , V_150 ) ;
} else {
V_148 = F_69 ( V_146 ) ;
F_70 ( V_2 -> V_29 , V_88 , V_148 , V_150 ) ;
}
if ( V_146 & V_151 )
F_71 ( V_87 ) ;
V_2 -> V_152 [ V_99 ] = NULL ;
}
static bool F_72 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_144 * V_145 ;
struct V_86 * V_87 ;
unsigned int V_99 ;
T_1 V_146 ;
V_99 = V_2 -> V_18 ;
V_145 = & V_2 -> V_145 [ V_99 ] ;
V_146 = F_53 ( V_145 -> V_153 ) ;
if ( V_146 & V_154 )
return false ;
V_87 = V_2 -> V_152 [ V_99 ] ;
V_5 -> V_102 . V_155 ++ ;
V_5 -> V_102 . V_156 += V_87 -> V_148 ;
F_67 ( V_2 , V_99 , V_87 , V_145 , V_146 ) ;
V_145 -> V_153 = F_48 ( V_146 & V_2 -> V_143 ) ;
V_2 -> V_18 = F_64 ( V_2 , V_99 ) ;
return true ;
}
static void F_73 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
while ( F_66 ( V_2 ) &&
F_72 ( V_2 ) )
;
F_74 () ;
if ( F_42 ( F_75 ( V_5 ) &&
F_65 ( V_2 ) >= V_157 ) ) {
struct V_158 * V_159 ;
V_159 = F_76 ( V_5 , 0 ) ;
F_77 ( V_159 , F_78 () ) ;
if ( F_75 ( V_5 ) &&
F_65 ( V_2 ) >= V_157 )
F_79 ( V_5 ) ;
F_80 ( V_159 ) ;
}
}
static bool F_81 ( struct V_86 * V_87 , T_1 * V_112 )
{
if ( V_87 -> V_136 == F_82 ( V_160 ) ) {
T_2 V_161 = F_83 ( V_87 ) -> V_136 ;
* V_112 |= V_162 ;
switch( V_161 ) {
case V_163 :
* V_112 |= V_164 ;
return true ;
case V_165 :
* V_112 |= V_166 ;
return true ;
case V_167 :
return true ;
}
}
return F_84 ( V_87 ) == 0 ;
}
static int F_85 ( struct V_86 * V_87 ,
struct V_4 * V_5 )
{
struct V_1 * V_2 = F_18 ( V_5 ) ;
struct V_144 * V_145 , * V_168 ;
unsigned int V_99 , V_169 , V_148 , V_6 , V_170 ;
T_1 V_171 , V_146 , V_112 ;
T_4 V_88 ;
if ( F_86 ( V_87 ) ) {
V_5 -> V_102 . V_172 ++ ;
return V_173 ;
}
if ( F_42 ( V_87 -> V_148 > V_174 ) ) {
if ( F_43 () )
F_87 ( V_5 , L_8 ) ;
goto V_116;
}
V_169 = F_88 ( V_87 ) -> V_175 ;
V_148 = F_68 ( V_87 ) ;
V_88 = F_45 ( V_2 -> V_29 , V_87 -> V_92 , V_148 , V_150 ) ;
if ( F_46 ( V_2 -> V_29 , V_88 ) ) {
if ( F_43 () )
F_5 ( V_5 , L_9 ) ;
goto V_116;
}
V_99 = V_2 -> V_19 ;
V_145 = V_168 = & V_2 -> V_145 [ V_99 ] ;
V_2 -> V_152 [ V_99 ] = V_87 ;
V_171 = F_63 ( V_2 , V_99 ) ;
V_171 |= V_154 ;
V_171 |= F_69 ( V_148 ) ;
V_171 |= V_149 ;
if ( V_169 == 0 )
V_171 |= V_151 ;
V_145 -> V_147 = F_48 ( V_88 ) ;
V_112 = 0 ;
if ( V_87 -> V_130 == V_176 &&
! F_81 ( V_87 , & V_112 ) )
goto V_116;
if ( F_89 ( V_87 ) ) {
V_112 |= V_177 ;
V_112 |= F_90 ( V_87 ) & 0xffff ;
}
V_145 -> V_178 = F_48 ( V_112 ) ;
V_99 = F_64 ( V_2 , V_99 ) ;
for ( V_6 = 0 ; V_6 < V_169 ; V_6 ++ ) {
T_6 * V_179 = & F_88 ( V_87 ) -> V_180 [ V_6 ] ;
V_148 = V_179 -> V_111 ;
V_88 = F_91 ( V_2 -> V_29 , V_179 , 0 , V_148 ,
V_150 ) ;
if ( F_46 ( V_2 -> V_29 , V_88 ) )
goto V_181;
V_2 -> V_152 [ V_99 ] = V_87 ;
V_145 = & V_2 -> V_145 [ V_99 ] ;
V_146 = F_63 ( V_2 , V_99 ) ;
V_146 |= V_154 ;
V_146 |= F_69 ( V_148 ) ;
if ( V_6 == ( V_169 - 1 ) )
V_146 |= V_151 ;
V_145 -> V_153 = F_48 ( V_146 ) ;
V_145 -> V_178 = 0 ;
V_145 -> V_147 = F_48 ( V_88 ) ;
V_99 = F_64 ( V_2 , V_99 ) ;
}
F_49 () ;
V_168 -> V_153 = F_48 ( V_171 ) ;
V_2 -> V_19 = V_99 ;
if ( F_42 ( F_65 ( V_2 ) < V_157 ) ) {
F_92 ( V_5 ) ;
F_74 () ;
if ( F_65 ( V_2 ) >= V_157 )
F_79 ( V_5 ) ;
}
F_2 ( 1 , V_2 -> V_7 + V_182 ) ;
return V_173 ;
V_181:
if ( F_43 () )
F_5 ( V_5 , L_10 ) ;
V_99 = V_2 -> V_19 ;
F_67 ( V_2 , V_99 , V_87 , V_168 , V_171 ) ;
V_168 -> V_153 = F_48 ( V_171 & V_2 -> V_143 ) ;
for ( V_170 = 0 ; V_170 < V_6 ; V_170 ++ ) {
V_99 = F_64 ( V_2 , V_99 ) ;
V_145 = & V_2 -> V_145 [ V_99 ] ;
V_146 = F_53 ( V_145 -> V_153 ) ;
F_67 ( V_2 , V_99 , V_87 , V_145 , V_146 ) ;
V_145 -> V_153 = F_48 ( V_146 & V_2 -> V_143 ) ;
}
V_116:
F_47 ( V_87 ) ;
V_5 -> V_102 . V_172 ++ ;
return V_173 ;
}
static void F_93 ( struct V_1 * V_2 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_96 ; V_6 ++ ) {
struct V_83 * V_84 = & V_2 -> V_84 [ V_6 ] ;
struct V_86 * V_87 = V_2 -> V_94 [ V_6 ] ;
T_4 V_88 = F_53 ( V_84 -> V_95 ) ;
if ( ! V_87 )
continue;
V_2 -> V_94 [ V_6 ] = NULL ;
F_59 ( V_2 -> V_29 , V_88 , V_47 , V_93 ) ;
F_47 ( V_87 ) ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_142 ; V_6 ++ ) {
struct V_144 * V_145 = & V_2 -> V_145 [ V_6 ] ;
struct V_86 * V_87 = V_2 -> V_152 [ V_6 ] ;
if ( ! V_87 )
continue;
F_67 ( V_2 , V_6 , V_87 , V_145 ,
F_53 ( V_145 -> V_153 ) ) ;
}
}
static void F_94 ( struct V_1 * V_2 )
{
F_95 ( V_2 -> V_94 ) ;
F_95 ( V_2 -> V_152 ) ;
if ( V_2 -> V_84 )
F_96 ( V_2 -> V_29 , V_183 *
sizeof( struct V_83 ) ,
V_2 -> V_84 , V_2 -> V_43 ) ;
V_2 -> V_84 = NULL ;
if ( V_2 -> V_145 )
F_96 ( V_2 -> V_29 , V_184 *
sizeof( struct V_144 ) ,
V_2 -> V_145 , V_2 -> V_45 ) ;
V_2 -> V_145 = NULL ;
if ( V_2 -> V_185 )
F_96 ( V_2 -> V_29 , V_47 ,
V_2 -> V_185 , V_2 -> V_91 ) ;
}
static int F_97 ( struct V_1 * V_2 )
{
V_2 -> V_94 = F_98 ( V_183 , sizeof( void * ) ,
V_186 ) ;
if ( ! V_2 -> V_94 )
return - V_90 ;
V_2 -> V_152 = F_98 ( V_184 , sizeof( void * ) ,
V_186 ) ;
if ( ! V_2 -> V_152 )
return - V_90 ;
V_2 -> V_84 = F_99 ( V_2 -> V_29 ,
V_183 *
sizeof( struct V_83 ) ,
& V_2 -> V_43 , V_186 ) ;
if ( ! V_2 -> V_84 )
return - V_90 ;
V_2 -> V_145 = F_99 ( V_2 -> V_29 ,
V_184 *
sizeof( struct V_144 ) ,
& V_2 -> V_45 , V_186 ) ;
if ( ! V_2 -> V_145 )
return - V_90 ;
V_2 -> V_185 = F_100 ( V_2 -> V_29 ,
V_47 ,
& V_2 -> V_91 ,
V_186 ) ;
if ( ! V_2 -> V_185 )
return - V_90 ;
return 0 ;
}
static void F_101 ( struct V_1 * V_2 )
{
struct V_83 * V_84 = NULL ;
struct V_144 * V_145 = NULL ;
int V_6 ;
V_2 -> V_96 = V_2 -> V_187 ;
V_2 -> V_142 = V_2 -> V_188 ;
if ( F_102 ( V_2 -> V_96 < V_189 ) )
return;
for ( V_6 = 0 ; V_6 < V_2 -> V_96 ; V_6 ++ ) {
V_84 = & V_2 -> V_84 [ V_6 ] ;
V_84 -> V_97 = 0 ;
V_84 -> V_95 = F_48 ( V_2 -> V_91 ) ;
}
V_84 -> V_97 |= F_48 ( V_2 -> V_98 ) ;
if ( F_102 ( V_2 -> V_142 < V_189 ) )
return;
for ( V_6 = 0 ; V_6 < V_2 -> V_142 ; V_6 ++ ) {
V_145 = & V_2 -> V_145 [ V_6 ] ;
V_145 -> V_153 = 0 ;
}
V_145 -> V_153 |= F_48 ( V_2 -> V_143 ) ;
}
static int F_103 ( struct V_1 * V_2 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_96 ; V_6 ++ ) {
struct V_83 * V_84 = & V_2 -> V_84 [ V_6 ] ;
if ( F_40 ( V_2 , V_6 , V_84 , V_186 ) )
return - V_90 ;
}
return 0 ;
}
static void F_104 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_18 ( V_5 ) ;
struct V_190 * V_191 = V_5 -> V_191 ;
bool V_36 , V_34 ;
int V_192 ;
if ( ! V_191 -> V_193 )
V_192 = 0 ;
else
V_192 = V_191 -> V_194 ;
if ( V_2 -> V_195 ) {
V_34 = V_36 = V_191 -> V_196 ;
if ( V_191 -> V_197 )
V_36 = ! V_34 ;
} else {
V_34 = V_2 -> V_34 ;
V_36 = V_2 -> V_36 ;
}
if ( V_191 -> V_194 == V_2 -> V_11 &&
V_191 -> V_198 == V_2 -> V_67 &&
V_34 == V_2 -> V_34 &&
V_36 == V_2 -> V_36 )
return;
if ( V_192 || V_2 -> V_11 )
F_105 ( V_191 ) ;
V_2 -> V_11 = V_192 ;
V_2 -> V_67 = V_191 -> V_198 ;
V_2 -> V_34 = V_34 ;
V_2 -> V_36 = V_36 ;
if ( ! V_192 )
return;
F_2 ( 0 , V_2 -> V_7 + V_199 ) ;
F_106 ( & V_2 -> V_200 ) ;
}
static int F_107 ( struct V_1 * V_2 , T_7 V_201 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_190 * V_191 ;
V_191 = F_108 ( V_2 -> V_202 ) ;
if ( ! V_191 ) {
F_109 ( V_5 , L_11 , V_5 -> V_203 ) ;
return - V_204 ;
}
V_191 = F_110 ( V_5 , F_111 ( V_191 ) ,
& F_104 , V_201 ) ;
if ( F_112 ( V_191 ) ) {
F_5 ( V_5 , L_12 , V_5 -> V_203 ) ;
return F_113 ( V_191 ) ;
}
V_191 -> V_205 |= V_206 | V_207 ;
V_191 -> V_208 = V_191 -> V_205 ;
F_114 ( V_191 ) ;
return 0 ;
}
static int F_115 ( struct V_202 * V_209 , int V_210 , int V_211 )
{
struct V_4 * V_5 = V_209 -> V_2 ;
struct V_1 * V_2 = F_18 ( V_5 ) ;
unsigned int V_212 ;
int V_6 ;
V_212 = F_3 ( V_2 -> V_7 + V_213 ) ;
V_212 &= V_214 ;
V_212 |= F_116 ( V_210 ) |
F_117 ( V_211 ) |
V_215 ;
F_2 ( V_212 , V_2 -> V_7 + V_213 ) ;
for ( V_6 = 0 ; V_6 < 10 ; V_6 ++ ) {
V_212 = F_3 ( V_2 -> V_7 + V_213 ) ;
if ( ( V_212 & V_215 ) == 0 ) {
int V_92 ;
V_92 = F_3 ( V_2 -> V_7 + V_216 ) ;
return F_118 ( V_92 ) ;
}
F_4 ( 100 ) ;
}
F_5 ( V_5 , L_13 ) ;
return - V_10 ;
}
static int F_119 ( struct V_202 * V_209 , int V_210 ,
int V_211 , T_8 V_217 )
{
struct V_4 * V_5 = V_209 -> V_2 ;
struct V_1 * V_2 = F_18 ( V_5 ) ;
unsigned int V_212 ;
int V_92 ;
int V_6 ;
V_212 = F_3 ( V_2 -> V_7 + V_213 ) ;
V_212 &= V_214 ;
V_212 |= F_116 ( V_210 ) |
F_117 ( V_211 ) |
V_218 ;
V_92 = F_120 ( V_217 ) ;
F_2 ( V_92 , V_2 -> V_7 + V_216 ) ;
F_2 ( V_212 , V_2 -> V_7 + V_213 ) ;
for ( V_6 = 0 ; V_6 < 10 ; V_6 ++ ) {
V_212 = F_3 ( V_2 -> V_7 + V_213 ) ;
if ( ( V_212 & V_218 ) == 0 )
return 0 ;
F_4 ( 100 ) ;
}
F_5 ( V_5 , L_14 ) ;
return - V_10 ;
}
static void F_121 ( struct V_4 * V_5 ,
struct V_219 * V_220 )
{
F_122 ( V_220 -> V_221 , V_222 , sizeof( V_220 -> V_221 ) ) ;
F_122 ( V_220 -> V_223 , V_224 , sizeof( V_220 -> V_223 ) ) ;
F_122 ( V_220 -> V_225 , F_123 ( & V_5 -> V_29 ) , sizeof( V_220 -> V_225 ) ) ;
}
static void F_124 ( struct V_4 * V_5 ,
struct V_226 * V_227 )
{
struct V_1 * V_2 = F_18 ( V_5 ) ;
memset ( V_227 , 0 , sizeof( * V_227 ) ) ;
V_227 -> V_228 = V_183 ;
V_227 -> V_229 = V_184 ;
V_227 -> V_230 = V_2 -> V_96 ;
V_227 -> V_231 = V_2 -> V_142 ;
}
static int F_125 ( struct V_4 * V_5 ,
struct V_226 * V_227 )
{
struct V_1 * V_2 = F_18 ( V_5 ) ;
if ( V_227 -> V_230 > V_183 ||
V_227 -> V_231 > V_184 ||
V_227 -> V_230 < V_189 ||
V_227 -> V_231 < V_232 ||
! F_126 ( V_227 -> V_230 ) ||
! F_126 ( V_227 -> V_231 ) )
return - V_233 ;
V_2 -> V_187 = V_227 -> V_230 ;
V_2 -> V_188 = V_227 -> V_231 ;
if ( F_39 ( V_5 ) )
F_106 ( & V_2 -> V_200 ) ;
return 0 ;
}
static void F_127 ( struct V_4 * V_5 ,
struct V_234 * V_196 )
{
struct V_1 * V_2 = F_18 ( V_5 ) ;
V_196 -> V_235 = V_2 -> V_195 ;
V_196 -> V_36 = V_2 -> V_36 ;
V_196 -> V_34 = V_2 -> V_34 ;
}
static int F_128 ( struct V_4 * V_5 ,
struct V_234 * V_196 )
{
struct V_1 * V_2 = F_18 ( V_5 ) ;
struct V_190 * V_191 = V_5 -> V_191 ;
V_2 -> V_195 = V_196 -> V_235 ;
V_2 -> V_36 = V_196 -> V_36 ;
V_2 -> V_34 = V_196 -> V_34 ;
if ( V_191 ) {
V_191 -> V_208 &= ~ V_236 ;
V_191 -> V_208 &= ~ V_237 ;
if ( V_196 -> V_34 ) {
V_191 -> V_208 |= V_236 ;
V_191 -> V_208 |= V_237 ;
}
if ( V_196 -> V_36 )
V_191 -> V_208 ^= V_237 ;
}
if ( F_39 ( V_5 ) ) {
if ( V_191 && V_2 -> V_195 )
F_129 ( V_191 ) ;
else
F_19 ( V_2 ) ;
}
return 0 ;
}
static T_9 F_130 ( int V_238 , void * V_239 )
{
struct V_4 * V_5 = V_239 ;
struct V_1 * V_2 = F_18 ( V_5 ) ;
unsigned int V_100 , V_240 = V_241 ;
V_100 = F_3 ( V_2 -> V_7 + V_42 ) ;
F_2 ( V_100 , V_2 -> V_7 + V_42 ) ;
if ( F_42 ( V_100 & V_241 ) ) {
if ( V_100 & V_242 )
V_5 -> V_102 . V_243 ++ ;
if ( V_100 & V_244 )
V_5 -> V_102 . V_245 ++ ;
if ( V_100 & V_246 )
V_5 -> V_102 . V_247 ++ ;
if ( V_100 & V_248 ) {
if ( F_43 () )
F_44 ( V_5 ,
L_15 ) ;
F_2 ( 0 , V_2 -> V_7 + V_199 ) ;
F_106 ( & V_2 -> V_200 ) ;
return V_249 ;
}
V_2 -> V_250 = true ;
V_240 &= ~ V_100 ;
}
F_2 ( V_240 , V_2 -> V_7 + V_199 ) ;
F_131 ( & V_2 -> V_139 ) ;
return V_249 ;
}
static bool F_132 ( struct V_1 * V_2 )
{
struct V_83 * V_84 = & V_2 -> V_84 [ V_2 -> V_17 ] ;
return ! ! ( V_84 -> V_97 & F_48 ( V_113 ) ) ;
}
static int F_133 ( struct V_251 * V_139 , int V_252 )
{
struct V_1 * V_2 = F_134 ( V_139 , struct V_1 , V_139 ) ;
int V_253 = 0 ;
bool V_254 ;
if ( F_66 ( V_2 ) )
F_73 ( V_2 ) ;
do {
V_254 = F_52 ( V_2 , & V_253 ) ;
} while ( V_254 && V_253 < V_252 );
if ( F_42 ( V_2 -> V_250 ) ) {
F_32 ( V_2 ) ;
F_2 ( V_241 ,
V_2 -> V_7 + V_199 ) ;
}
if ( F_66 ( V_2 ) )
V_253 = V_252 ;
if ( V_253 < V_252 ) {
F_2 ( V_255 ,
V_2 -> V_7 + V_42 ) ;
F_3 ( V_2 -> V_7 + V_42 ) ;
if ( F_132 ( V_2 ) ||
F_66 ( V_2 ) )
return V_252 ;
F_135 ( V_139 ) ;
F_2 ( V_256 ,
V_2 -> V_7 + V_199 ) ;
}
return V_253 ;
}
static int F_136 ( struct V_1 * V_2 , bool V_257 )
{
int V_89 = 0 ;
F_101 ( V_2 ) ;
V_89 = F_103 ( V_2 ) ;
if ( V_89 && ! V_257 )
return V_89 ;
F_21 ( V_2 ) ;
F_19 ( V_2 ) ;
F_32 ( V_2 ) ;
F_137 ( & V_2 -> V_139 ) ;
F_138 ( V_2 -> V_5 ) ;
F_2 ( V_256 , V_2 -> V_7 + V_199 ) ;
return V_89 ;
}
static void F_139 ( struct V_258 * V_259 )
{
struct V_1 * V_2 = F_134 ( V_259 , struct V_1 ,
V_200 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_89 ;
F_87 ( V_5 , L_16 ) ;
F_140 () ;
if ( V_5 -> V_191 )
F_141 ( & V_5 -> V_191 -> V_260 ) ;
if ( V_2 -> V_202 )
F_141 ( & V_2 -> V_202 -> V_261 ) ;
if ( ! F_39 ( V_5 ) )
goto V_262;
F_142 ( V_5 ) ;
F_143 ( & V_2 -> V_139 ) ;
F_144 ( V_5 ) ;
F_34 ( V_2 ) ;
V_89 = F_6 ( V_2 ) ;
if ( V_89 ) {
F_5 ( V_5 , L_17 ) ;
}
F_93 ( V_2 ) ;
F_136 ( V_2 , true ) ;
F_87 ( V_5 , L_18 ) ;
V_262:
if ( V_2 -> V_202 )
F_145 ( & V_2 -> V_202 -> V_261 ) ;
if ( V_5 -> V_191 )
F_145 ( & V_5 -> V_191 -> V_260 ) ;
F_146 () ;
}
static int F_147 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_18 ( V_5 ) ;
int V_89 ;
V_89 = F_97 ( V_2 ) ;
if ( V_89 ) {
F_5 ( V_5 , L_19 ) ;
return V_89 ;
}
if ( V_2 -> V_263 ) {
V_2 -> V_67 = V_68 ;
V_2 -> V_11 = V_13 ;
} else {
V_2 -> V_67 = 0 ;
V_2 -> V_11 = 0 ;
}
V_89 = F_6 ( V_2 ) ;
if ( V_89 )
goto V_264;
F_148 ( V_5 , & V_2 -> V_139 , F_133 , 64 ) ;
V_89 = F_149 ( V_5 -> V_238 , F_130 , 0 , V_5 -> V_203 , V_5 ) ;
if ( V_89 ) {
F_5 ( V_5 , L_20 , V_5 -> V_238 ) ;
goto V_265;
}
V_89 = F_136 ( V_2 , false ) ;
if ( V_89 ) {
F_5 ( V_5 , L_21 ) ;
goto V_266;
}
if ( V_5 -> V_191 ) {
F_150 ( V_5 -> V_191 ) ;
} else if ( V_2 -> V_263 ) {
F_151 ( V_5 ) ;
V_89 = F_152 ( V_2 -> V_267 ) ;
if ( V_89 )
goto V_268;
}
return 0 ;
V_268:
F_143 ( & V_2 -> V_139 ) ;
F_92 ( V_5 ) ;
V_266:
F_93 ( V_2 ) ;
F_153 ( V_5 -> V_238 , V_5 ) ;
V_265:
F_154 ( & V_2 -> V_139 ) ;
V_264:
F_2 ( 0 , V_2 -> V_7 + V_199 ) ;
F_94 ( V_2 ) ;
return V_89 ;
}
static int F_155 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_18 ( V_5 ) ;
F_2 ( 0 , V_2 -> V_7 + V_199 ) ;
F_92 ( V_5 ) ;
F_143 ( & V_2 -> V_139 ) ;
F_154 ( & V_2 -> V_139 ) ;
if ( V_5 -> V_191 )
F_156 ( V_5 -> V_191 ) ;
else if ( V_2 -> V_263 )
F_157 ( V_2 -> V_267 ) ;
F_34 ( V_2 ) ;
F_153 ( V_5 -> V_238 , V_5 ) ;
F_93 ( V_2 ) ;
F_94 ( V_2 ) ;
return 0 ;
}
static int F_158 ( struct V_4 * V_5 , struct V_269 * V_270 , int V_271 )
{
if ( ! V_5 -> V_191 )
return - V_272 ;
return F_159 ( V_5 -> V_191 , V_270 , V_271 ) ;
}
static void F_160 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_18 ( V_5 ) ;
F_2 ( 0 , V_2 -> V_7 + V_199 ) ;
F_106 ( & V_2 -> V_200 ) ;
}
static int F_161 ( struct V_4 * V_5 ,
T_10 V_76 )
{
struct V_1 * V_2 = F_18 ( V_5 ) ;
T_10 V_273 = V_5 -> V_76 ^ V_76 ;
if ( ! F_39 ( V_5 ) )
return 0 ;
if ( V_273 & V_77 ) {
T_1 V_3 ;
V_3 = F_3 ( V_2 -> V_7 + V_8 ) ;
if ( V_2 -> V_5 -> V_76 & V_77 )
V_3 |= V_78 ;
else
V_3 &= ~ V_78 ;
F_2 ( V_3 , V_2 -> V_7 + V_8 ) ;
}
return 0 ;
}
static void F_162 ( struct V_4 * V_5 )
{
unsigned long V_70 ;
F_163 ( V_70 ) ;
F_130 ( V_5 -> V_238 , V_5 ) ;
F_164 ( V_70 ) ;
}
static int F_165 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_18 ( V_5 ) ;
struct V_274 * V_275 = F_166 ( V_2 -> V_29 ) ;
int V_276 = V_277 ;
struct V_278 * V_279 = V_275 -> V_29 . V_280 ;
int V_6 , V_89 = 0 ;
T_1 V_39 ;
V_2 -> V_202 = F_167 () ;
if ( ! V_2 -> V_202 )
return - V_10 ;
if ( V_2 -> V_281 ) {
V_39 = F_3 ( V_2 -> V_7 + V_282 ) ;
V_39 &= ~ V_283 ;
F_2 ( V_39 , V_2 -> V_7 + V_282 ) ;
} ;
if ( V_279 ) {
V_276 = F_168 ( V_279 ) ;
if ( V_276 < 0 )
V_276 = V_277 ;
if ( V_2 -> V_281 &&
V_276 != V_284 &&
V_276 != V_277 &&
V_276 != V_285 &&
V_276 != V_286 &&
V_276 != V_287 ) {
F_44 ( V_5 ,
L_22 ,
F_169 ( V_276 ) ) ;
}
}
V_2 -> V_202 -> V_203 = L_23 ;
snprintf ( V_2 -> V_202 -> V_288 , V_289 , L_24 ,
V_275 -> V_203 , V_275 -> V_288 ) ;
V_2 -> V_202 -> V_2 = V_2 -> V_5 ;
V_2 -> V_202 -> V_290 = F_115 ;
V_2 -> V_202 -> V_291 = F_119 ;
for ( V_6 = 0 ; V_6 < V_292 ; V_6 ++ )
V_2 -> V_202 -> V_238 [ V_6 ] = V_293 ;
V_89 = F_170 ( V_2 -> V_202 ) ;
if ( V_89 ) {
F_171 ( V_2 -> V_29 , L_25 ) ;
goto V_294;
}
V_89 = F_107 ( V_2 , V_276 ) ;
if ( V_89 ) {
F_171 ( V_2 -> V_29 , L_26 ) ;
goto V_295;
}
return 0 ;
V_295:
F_172 ( V_2 -> V_202 ) ;
V_294:
F_173 ( V_2 -> V_202 ) ;
return V_89 ;
}
static void F_174 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_18 ( V_5 ) ;
if ( ! V_5 -> V_191 )
return;
F_175 ( V_5 -> V_191 ) ;
F_172 ( V_2 -> V_202 ) ;
F_173 ( V_2 -> V_202 ) ;
}
static void F_176 ( struct V_296 * V_297 )
{
if ( F_42 ( V_297 -> V_298 != V_299 ) )
return;
F_109 ( V_297 -> V_29 , L_27 ,
V_297 -> V_300 ? L_28 : L_29 ) ;
}
static int F_177 ( struct V_274 * V_275 )
{
struct V_301 * V_302 ;
int V_238 ;
struct V_4 * V_5 ;
struct V_1 * V_2 ;
struct V_278 * V_279 ;
int V_89 = 0 ;
if ( ! V_275 )
return - V_204 ;
V_302 = F_178 ( V_275 , V_303 , 0 ) ;
if ( ! V_302 )
return - V_272 ;
V_238 = F_179 ( V_275 , 0 ) ;
if ( V_238 < 0 )
return V_238 ;
V_5 = F_180 ( sizeof( * V_2 ) ) ;
if ( ! V_5 ) {
V_89 = - V_90 ;
goto V_304;
}
F_181 ( V_5 , & V_275 -> V_29 ) ;
V_5 -> V_305 = & V_306 ;
V_5 -> V_307 = & V_308 ;
V_5 -> V_309 = 5 * V_310 ;
F_182 ( V_275 , V_5 ) ;
V_2 = F_18 ( V_5 ) ;
V_2 -> V_5 = V_5 ;
V_2 -> V_29 = & V_275 -> V_29 ;
F_183 ( & V_2 -> V_200 , F_139 ) ;
V_2 -> V_302 = F_184 ( V_302 -> V_311 , F_185 ( V_302 ) ,
F_123 ( & V_275 -> V_29 ) ) ;
if ( ! V_2 -> V_302 ) {
F_171 ( & V_275 -> V_29 , L_30 ) ;
V_89 = - V_90 ;
goto V_312;
}
V_2 -> V_7 = F_186 ( V_302 -> V_311 , F_185 ( V_302 ) ) ;
if ( ! V_2 -> V_7 ) {
F_171 ( & V_275 -> V_29 , L_31 ) ;
V_89 = - V_10 ;
goto V_313;
}
V_5 -> V_238 = V_238 ;
V_2 -> V_36 = true ;
V_2 -> V_34 = true ;
V_2 -> V_195 = true ;
F_9 ( V_2 ) ;
V_279 = V_275 -> V_29 . V_280 ;
if ( V_279 && ( F_187 ( V_279 , L_32 ) ||
F_187 ( V_279 , L_33 ) ) ) {
V_2 -> V_98 = F_188 ( 30 ) ;
V_2 -> V_143 = F_188 ( 30 ) ;
V_2 -> V_281 = true ;
} else {
V_2 -> V_98 = F_188 ( 15 ) ;
V_2 -> V_143 = F_188 ( 15 ) ;
}
if ( V_279 && F_189 ( V_279 , L_34 , NULL ) ) {
if ( ! F_190 ( V_314 ) ) {
F_171 ( & V_275 -> V_29 , L_35 ) ;
goto V_315;
}
F_12 ( & V_275 -> V_29 , L_36 ) ;
V_2 -> V_263 = true ;
V_2 -> V_267 = F_191 ( V_5 , F_176 ) ;
if ( ! V_2 -> V_267 )
goto V_315;
} else {
V_2 -> V_263 = false ;
V_89 = F_165 ( V_5 ) ;
if ( V_89 )
goto V_316;
}
V_2 -> V_96 = V_2 -> V_187 = V_317 ;
V_2 -> V_142 = V_2 -> V_188 = V_318 ;
V_5 -> V_319 = V_124 | V_320 |
V_321 | V_322 | V_77 |
V_323 ;
if ( V_279 && ( F_187 ( V_279 , L_32 ) ) )
V_5 -> V_319 &= ~ V_320 ;
if ( V_279 && F_189 ( V_279 , L_37 , NULL ) )
V_5 -> V_319 &= ~ ( V_320 | V_124 ) ;
V_5 -> V_76 |= V_5 -> V_319 ;
V_89 = F_192 ( V_5 ) ;
if ( V_89 ) {
F_171 ( & V_275 -> V_29 , L_38 ) ;
goto V_324;
}
F_109 ( V_5 , L_39 , V_5 -> V_238 , V_2 -> V_7 ) ;
return 0 ;
V_315:
V_324:
F_174 ( V_5 ) ;
V_316:
F_193 ( V_2 -> V_7 ) ;
V_313:
F_194 ( V_2 -> V_302 ) ;
V_312:
F_154 ( & V_2 -> V_139 ) ;
F_195 ( V_5 ) ;
V_304:
return V_89 ;
}
static int F_196 ( struct V_274 * V_275 )
{
struct V_4 * V_5 ;
struct V_1 * V_2 ;
V_5 = F_197 ( V_275 ) ;
V_2 = F_18 ( V_5 ) ;
F_198 ( V_5 ) ;
F_199 ( & V_2 -> V_200 ) ;
F_174 ( V_5 ) ;
F_193 ( V_2 -> V_7 ) ;
F_194 ( V_2 -> V_302 ) ;
F_154 ( & V_2 -> V_139 ) ;
F_195 ( V_5 ) ;
return 0 ;
}
