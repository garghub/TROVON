static void F_1 ( struct V_1 * V_2 , int V_3 )
{
unsigned long V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( & V_6 -> V_7 , V_4 ) ;
if ( V_3 || ( ! V_6 -> V_8 ) ) {
F_4 ( V_9 , V_6 -> V_10 ) ;
F_5 ( 2 ) ;
F_4 ( ( V_11 | V_12 | V_13
| V_9 ) , V_6 -> V_10 ) ;
F_5 ( 2 ) ;
V_6 -> V_8 = 1 ;
}
F_6 ( & V_6 -> V_7 , V_4 ) ;
}
static int F_7 ( struct V_1 * V_2 , int V_14 , int V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 * const V_16 = & V_6 -> V_17 -> V_18 ;
T_1 * const V_19 = & V_6 -> V_17 -> V_20 ;
T_1 V_21 = 20 ;
T_1 V_18 ;
while ( F_8 ( V_16 ) & V_22 ) {
F_9 ( 1 ) ;
if ( -- V_21 == 0 ) {
F_10 ( V_2 , L_1 ) ;
return - 1 ;
}
}
V_18 = F_11 ( V_15 ) |
F_12 ( V_14 ) | V_23 ;
F_4 ( V_18 , V_16 ) ;
V_21 = 20 ;
while ( F_8 ( V_16 ) & V_22 ) {
F_9 ( 1 ) ;
if ( -- V_21 == 0 ) {
F_10 ( V_2 , L_2 ) ;
return - 1 ;
}
}
return F_8 ( V_19 ) ;
}
static void F_13 ( struct V_1 * V_2 , int V_14 ,
int V_15 , T_2 V_24 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 * const V_16 = & V_6 -> V_17 -> V_18 ;
T_1 * const V_19 = & V_6 -> V_17 -> V_20 ;
T_1 V_21 = 20 ;
T_1 V_18 ;
while ( F_8 ( V_16 ) & V_22 ) {
F_9 ( 1 ) ;
if ( -- V_21 == 0 ) {
F_10 ( V_2 , L_3 ) ;
return;
}
}
V_18 = F_11 ( V_15 ) |
F_12 ( V_14 ) | V_25 ;
F_4 ( V_24 , V_19 ) ;
F_4 ( V_18 , V_16 ) ;
}
static int F_14 ( struct V_26 * V_27 , int V_14 , int V_28 )
{
struct V_1 * const V_2 = V_27 -> V_29 ;
F_1 ( V_2 , 0 ) ;
return F_7 ( V_2 , V_14 , V_28 ) ;
}
static int F_15 ( struct V_26 * V_27 , int V_14 , int V_28 ,
T_2 V_24 )
{
struct V_1 * const V_2 = V_27 -> V_29 ;
F_1 ( V_2 , 0 ) ;
F_13 ( V_2 , V_14 , V_28 , V_24 ) ;
return 0 ;
}
static int F_16 ( struct V_26 * V_27 )
{
struct V_1 * const V_2 = V_27 -> V_29 ;
F_1 ( V_2 , 0 ) ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_15 ;
F_18 ( V_6 , V_30 , V_2 , L_4 ) ;
V_15 = F_8 ( & V_6 -> V_17 -> V_31 ) ;
V_15 &= ~ ( V_32 | V_33 ) ;
F_4 ( V_15 , & V_6 -> V_17 -> V_31 ) ;
F_5 ( 10 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_15 ;
F_18 ( V_6 , V_34 , V_2 , L_5 ) ;
V_15 = F_8 ( & V_6 -> V_17 -> V_31 ) ;
V_15 |= ( V_32 | V_33 ) ;
F_4 ( V_15 , & V_6 -> V_17 -> V_31 ) ;
F_5 ( 10 ) ;
}
static void
F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_35 * V_36 = V_6 -> V_37 ;
unsigned long V_4 ;
T_1 V_15 ;
int V_38 = 0 ;
F_21 ( ! V_6 -> V_37 ) ;
F_3 ( & V_6 -> V_7 , V_4 ) ;
if ( V_36 -> V_39 && ( V_6 -> V_40 != V_36 -> V_41 ) ) {
switch ( V_36 -> V_41 ) {
case V_42 :
case V_43 :
break;
default:
F_22 ( V_2 , L_6 ,
V_36 -> V_41 ) ;
break;
}
V_6 -> V_40 = V_36 -> V_41 ;
V_38 = 1 ;
}
if ( V_36 -> V_39 && ( V_6 -> V_44 != V_36 -> V_45 ) ) {
F_17 ( V_2 ) ;
V_15 = F_8 ( & V_6 -> V_17 -> V_31 ) ;
if ( V_46 == V_36 -> V_45 ) {
V_15 |= V_47 ;
V_15 &= ~ V_48 ;
} else {
V_15 &= ~ V_47 ;
V_15 |= V_48 ;
}
F_4 ( V_15 , & V_6 -> V_17 -> V_31 ) ;
F_5 ( 1 ) ;
F_19 ( V_2 ) ;
V_6 -> V_44 = V_36 -> V_45 ;
V_38 = 1 ;
}
if ( V_36 -> V_39 != V_6 -> V_49 ) {
if ( ! V_36 -> V_39 ) {
V_6 -> V_40 = 0 ;
V_6 -> V_44 = - 1 ;
}
V_6 -> V_49 = V_36 -> V_39 ;
V_38 = 1 ;
}
F_6 ( & V_6 -> V_7 , V_4 ) ;
if ( V_38 ) {
if ( V_36 -> V_39 )
F_23 ( V_2 , L_7 ,
V_36 -> V_41 ,
V_46 == V_36 -> V_45 ? L_8 : L_9 ) ;
else
F_23 ( V_2 , L_10 ) ;
}
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_5 * const V_6 = F_2 ( V_2 ) ;
struct V_35 * V_36 = NULL ;
int V_14 ;
if ( V_6 -> V_50 ) {
F_21 ( V_6 -> V_51 < 0 || V_6 -> V_51 > 1 ) ;
if ( V_6 -> V_14 )
V_36 = V_6 -> V_26 -> V_52 [ V_6 -> V_14 ] ;
else
F_23 ( V_2 , L_11 ) ;
return 0 ;
}
for ( V_14 = 0 ; V_14 < V_53 ; V_14 ++ )
if ( V_6 -> V_26 -> V_52 [ V_14 ] ) {
V_36 = V_6 -> V_26 -> V_52 [ V_14 ] ;
if ( ! V_6 -> V_54 )
break;
}
if ( V_6 -> V_55 ) {
if ( ! V_36 && ( V_6 -> V_51 == 1 ) ) {
F_25 ( & V_2 -> V_2 , L_12
L_13 ) ;
for ( V_14 = 0 ; V_14 < V_53 ; V_14 ++ ) {
struct V_35 * const V_56 =
V_6 -> V_26 -> V_52 [ V_14 ] ;
if ( V_6 -> V_51 == 1 )
break;
if ( ! V_56 )
continue;
if ( V_56 -> V_57 )
continue;
V_36 = V_56 ;
break;
}
}
}
if ( ! V_36 ) {
F_10 ( V_2 , L_14 ) ;
return - 1 ;
}
F_21 ( V_36 -> V_57 ) ;
V_36 = F_26 ( V_2 , F_27 ( & V_36 -> V_2 ) , & F_20 ,
0 , V_58 ) ;
if ( F_28 ( V_36 ) ) {
F_10 ( V_2 , L_15 ) ;
return F_29 ( V_36 ) ;
}
V_36 -> V_59 &= ( V_60
| V_61
| V_62
| V_63
| V_64
| V_65
| V_66 ) ;
V_36 -> V_67 = V_36 -> V_59 ;
V_6 -> V_49 = 0 ;
V_6 -> V_40 = 0 ;
V_6 -> V_44 = - 1 ;
V_6 -> V_37 = V_36 ;
F_23 ( V_2 , L_16
L_17 ,
V_36 -> V_30 -> V_68 , F_27 ( & V_36 -> V_2 ) , V_36 -> V_69 ) ;
return 0 ;
}
static struct V_70 * F_30 ( struct V_5 * V_6 )
{
struct V_70 * V_71 ;
V_71 = V_6 -> V_72 ;
if ( V_71 )
V_6 -> V_72 = V_71 -> V_73 ;
return V_71 ;
}
void F_31 ( struct V_5 * V_6 , struct V_70 * V_71 )
{
struct V_70 * V_72 = V_6 -> V_72 ;
if ( V_72 )
V_72 -> V_73 = V_71 ;
V_6 -> V_72 = V_71 ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_5 * const V_6 = F_2 ( V_2 ) ;
int V_74 ;
F_17 ( V_2 ) ;
F_4 ( V_9 , V_6 -> V_10 ) ;
F_5 ( 2 ) ;
F_4 ( 0 , V_6 -> V_10 ) ;
F_5 ( 2 ) ;
V_6 -> V_75 = 0 ;
for ( V_74 = 0 ; V_74 < V_76 ; V_74 ++ ) {
V_6 -> V_77 [ V_74 ] -> V_78 &= ~ 0xf ;
}
for ( V_74 = 0 ; V_74 < V_79 ; V_74 ++ ) {
V_6 -> V_80 [ V_74 ] -> V_78 &= ~ 0xf ;
}
V_6 -> V_8 = 0 ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_5 * const V_6 = F_2 ( V_2 ) ;
unsigned long V_4 ;
F_18 ( V_6 , V_34 , V_2 , L_18 ,
( unsigned ) V_6 ) ;
F_3 ( & V_6 -> V_7 , V_4 ) ;
F_32 ( V_2 ) ;
F_6 ( & V_6 -> V_7 , V_4 ) ;
}
static void
F_34 ( struct V_5 * V_6 , T_1 V_81 , T_1 V_82 )
{
int V_74 ;
for ( V_74 = 0 ; V_74 < V_76 ; V_74 ++ ) {
V_6 -> V_77 [ V_74 ] =
(struct V_83 * )
( V_81 + sizeof( struct V_83 ) * V_74 ) ;
}
for ( V_74 = 0 ; V_74 < V_79 ; V_74 ++ ) {
V_6 -> V_80 [ V_74 ] =
(struct V_84 * )
( V_82 + sizeof( struct V_84 ) * V_74 ) ;
}
}
static int F_35 ( struct V_1 * V_2 , struct V_85 * V_86 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_37 )
return F_36 ( V_6 -> V_37 , V_86 ) ;
return - V_87 ;
}
static int F_37 ( struct V_1 * V_2 , struct V_85 * V_86 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_38 ( V_88 ) )
return - V_89 ;
if ( V_6 -> V_37 )
return F_39 ( V_6 -> V_37 , V_86 ) ;
return - V_87 ;
}
static void
F_40 ( struct V_1 * V_2 , struct V_90 * V_91 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
strcpy ( V_91 -> V_92 , V_93 ) ;
strcpy ( V_91 -> V_94 , V_95 ) ;
V_91 -> V_96 [ 0 ] = '\0' ;
sprintf ( V_91 -> V_97 , L_19 , V_93 , V_6 -> V_51 ) ;
V_91 -> V_98 = 0 ;
}
static void F_41 ( struct V_1 * V_2 , T_1 V_24 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_99 = V_24 ;
}
static T_1 F_42 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_99 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_4 ;
int V_74 ;
T_1 V_31 ;
F_18 ( V_6 , V_34 , V_2 , L_20 ) ;
F_1 ( V_2 , 1 ) ;
F_3 ( & V_6 -> V_7 , V_4 ) ;
F_4 ( 0 , & V_6 -> V_17 -> V_31 ) ;
V_6 -> V_100 = ( V_6 -> V_80 [ 0 ] -> V_78 & 0xC ) >> 2 ;
V_6 -> V_101 = V_6 -> V_100 ;
V_6 -> V_102 = ( V_6 -> V_77 [ 0 ] -> V_78 & 0xC ) >> 2 ;
F_4 ( V_2 -> V_103 [ 5 ] << 8 | V_2 -> V_103 [ 4 ] ,
& V_6 -> V_17 -> V_104 ) ;
F_4 ( V_2 -> V_103 [ 3 ] << 24 | V_2 -> V_103 [ 2 ] << 16 |
V_2 -> V_103 [ 1 ] << 8 | V_2 -> V_103 [ 0 ] ,
& V_6 -> V_17 -> V_105 ) ;
for ( V_74 = 0 ; V_74 < V_76 ; V_74 ++ )
V_6 -> V_77 [ V_74 ] -> V_78 |= V_106 ;
F_44 () ;
V_31 = V_32 | V_33 ;
#ifndef F_45
V_31 |= V_107 ;
#endif
if ( V_6 -> V_37 ) {
if ( V_6 -> V_37 -> V_39 && ( V_46 == V_6 -> V_37 -> V_45 ) )
V_31 |= V_47 ;
else
V_31 |= V_48 ;
} else {
V_31 |= V_47 ;
}
F_4 ( V_31 , & V_6 -> V_17 -> V_31 ) ;
F_4 ( 0x8100 , & V_6 -> V_17 -> V_108 ) ;
F_44 () ;
F_6 ( & V_6 -> V_7 , V_4 ) ;
return 0 ;
}
static inline void F_46 ( struct V_1 * V_2 , T_1 V_109 )
{
struct V_110 * V_111 = & V_2 -> V_112 ;
V_111 -> V_113 ++ ;
if ( V_109 & V_114 )
V_111 -> V_115 ++ ;
if ( V_109 & V_116 ) {
V_111 -> V_117 ++ ;
if ( V_109 & V_118 )
V_111 -> V_119 ++ ;
if ( V_109 & ( V_120 | V_121 | V_122 ) )
V_111 -> V_123 ++ ;
if ( V_109 & V_124 )
V_111 -> V_125 ++ ;
if ( V_109 & V_126 )
V_111 -> V_127 ++ ;
} else
V_111 -> V_128 += V_109 & V_129 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_130 * V_131 ;
struct V_83 * V_132 ;
T_1 V_78 , V_109 ;
struct V_70 * V_71 ;
T_1 V_133 ;
F_18 ( V_6 , V_134 , V_2 , L_21 , V_6 -> V_102 ) ;
V_132 = V_6 -> V_77 [ V_6 -> V_102 ] ;
V_78 = V_132 -> V_78 ;
while ( V_78 & V_135 ) {
V_109 = V_132 -> V_109 ;
V_71 = V_6 -> V_136 [ V_6 -> V_102 ] ;
F_46 ( V_2 , V_109 ) ;
if ( ! ( V_109 & V_116 ) ) {
V_133 = ( V_109 & V_129 ) ;
V_133 -= 4 ;
V_131 = F_48 ( V_133 + 2 ) ;
if ( V_131 == NULL ) {
F_10 ( V_2 , L_22 ) ;
V_2 -> V_112 . V_137 ++ ;
continue;
}
F_49 ( V_131 , 2 ) ;
F_50 ( V_131 ,
( unsigned char * ) V_71 -> V_138 , V_133 ) ;
F_51 ( V_131 , V_133 ) ;
V_131 -> V_139 = F_52 ( V_131 , V_2 ) ;
F_53 ( V_131 ) ;
} else {
if ( V_140 > 4 ) {
F_54 ( L_23 ) ;
if ( V_109 & V_118 )
F_55 ( L_24 ) ;
if ( V_109 & V_141 )
F_55 ( L_25 ) ;
if ( V_109 & V_121 )
F_55 ( L_26 ) ;
if ( V_109 & V_120 )
F_55 ( L_27 ) ;
if ( V_109 & V_126 )
F_55 ( L_28 ) ;
if ( V_109 & V_142 )
F_55 ( L_29 ) ;
if ( V_109 & V_124 )
F_55 ( L_30 ) ;
if ( V_109 & V_122 )
F_55 ( L_31 ) ;
if ( V_109 & V_143 )
F_55 ( L_32 ) ;
F_55 ( L_33 ) ;
}
}
V_132 -> V_78 = ( T_1 ) ( V_71 -> V_144 | V_106 ) ;
V_6 -> V_102 = ( V_6 -> V_102 + 1 ) & ( V_76 - 1 ) ;
F_44 () ;
V_132 = V_6 -> V_77 [ V_6 -> V_102 ] ;
V_78 = V_132 -> V_78 ;
}
return 0 ;
}
static void F_56 ( struct V_1 * V_2 , T_1 V_109 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_110 * V_111 = & V_2 -> V_112 ;
if ( V_109 & V_145 ) {
if ( ! V_6 -> V_37 || ( V_46 == V_6 -> V_37 -> V_45 ) ) {
if ( V_109 & ( V_146 | V_147 ) ) {
V_111 -> V_148 ++ ;
V_111 -> V_149 ++ ;
}
} else {
V_111 -> V_148 ++ ;
V_111 -> V_149 ++ ;
if ( V_109 & ( V_150 | V_151 ) )
V_111 -> V_152 ++ ;
}
}
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_84 * V_153 ;
V_153 = V_6 -> V_80 [ V_6 -> V_101 ] ;
while ( V_153 -> V_78 & V_154 ) {
F_56 ( V_2 , V_153 -> V_109 ) ;
V_153 -> V_78 &= ~ V_154 ;
V_153 -> V_155 = 0 ;
F_44 () ;
V_6 -> V_101 = ( V_6 -> V_101 + 1 ) & ( V_79 - 1 ) ;
V_153 = V_6 -> V_80 [ V_6 -> V_101 ] ;
if ( V_6 -> V_75 ) {
V_6 -> V_75 = 0 ;
F_58 ( V_2 ) ;
}
}
}
static T_3 F_59 ( int V_69 , void * V_156 )
{
struct V_1 * V_2 = V_156 ;
F_47 ( V_2 ) ;
F_57 ( V_2 ) ;
return F_60 ( 1 ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
int V_157 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_18 ( V_6 , V_30 , V_2 , L_34 , V_2 ) ;
V_157 = F_62 ( V_2 -> V_69 , F_59 , 0 ,
V_2 -> V_68 , V_2 ) ;
if ( V_157 ) {
F_10 ( V_2 , L_35 , V_2 -> V_69 ) ;
return V_157 ;
}
V_157 = F_43 ( V_2 ) ;
if ( V_157 ) {
F_10 ( V_2 , L_36 ) ;
F_63 ( V_2 -> V_69 , V_2 ) ;
return V_157 ;
}
if ( V_6 -> V_37 ) {
V_6 -> V_37 -> V_158 = V_159 ;
F_64 ( V_6 -> V_37 ) ;
}
F_65 ( V_2 ) ;
F_18 ( V_6 , V_30 , V_2 , L_37 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
struct V_5 * const V_6 = F_2 ( V_2 ) ;
F_18 ( V_6 , V_30 , V_2 , L_38 , V_2 ) ;
if ( V_6 -> V_37 )
F_67 ( V_6 -> V_37 ) ;
F_3 ( & V_6 -> V_7 , V_4 ) ;
F_32 ( V_2 ) ;
F_68 ( V_2 ) ;
F_63 ( V_2 -> V_69 , V_2 ) ;
F_6 ( & V_6 -> V_7 , V_4 ) ;
return 0 ;
}
static T_4 F_69 ( struct V_130 * V_131 , struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_110 * V_111 = & V_2 -> V_112 ;
struct V_84 * V_153 ;
T_1 V_78 ;
struct V_70 * V_71 ;
int V_74 ;
F_18 ( V_6 , V_160 , V_2 , L_39 ,
( unsigned ) V_6 , V_131 -> V_155 ,
V_131 -> V_161 , V_6 -> V_100 ) ;
V_153 = V_6 -> V_80 [ V_6 -> V_100 ] ;
V_78 = V_153 -> V_78 ;
if ( V_78 & V_162 ) {
F_68 ( V_2 ) ;
V_6 -> V_75 = 1 ;
return V_163 ;
} else if ( V_78 & V_154 ) {
F_56 ( V_2 , V_153 -> V_109 ) ;
V_153 -> V_155 = 0 ;
}
if ( V_6 -> V_75 ) {
V_6 -> V_75 = 0 ;
F_58 ( V_2 ) ;
}
V_71 = V_6 -> V_164 [ V_6 -> V_100 ] ;
F_70 ( V_131 , ( void * ) V_71 -> V_138 , V_131 -> V_155 ) ;
if ( V_131 -> V_155 < V_165 ) {
for ( V_74 = V_131 -> V_155 ; V_74 < V_165 ; V_74 ++ )
( ( char * ) V_71 -> V_138 ) [ V_74 ] = 0 ;
V_153 -> V_155 = V_165 ;
} else
V_153 -> V_155 = V_131 -> V_155 ;
V_111 -> V_166 ++ ;
V_111 -> V_167 += V_153 -> V_155 ;
V_153 -> V_78 = V_71 -> V_144 | V_162 ;
F_44 () ;
F_71 ( V_131 ) ;
V_6 -> V_100 = ( V_6 -> V_100 + 1 ) & ( V_79 - 1 ) ;
return V_168 ;
}
static void F_72 ( struct V_1 * V_2 )
{
F_10 ( V_2 , L_40 , V_2 ) ;
F_33 ( V_2 ) ;
F_43 ( V_2 ) ;
V_2 -> V_169 = V_170 ;
F_58 ( V_2 ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_15 ;
F_18 ( V_6 , V_30 , V_2 , L_41 , V_171 , V_2 -> V_4 ) ;
V_15 = F_8 ( & V_6 -> V_17 -> V_31 ) ;
if ( V_2 -> V_4 & V_172 ) {
V_15 |= V_173 ;
} else if ( ( V_2 -> V_4 & V_174 ) ||
F_74 ( V_2 ) > V_175 ) {
V_15 |= V_176 ;
V_15 &= ~ V_173 ;
F_23 ( V_2 , L_42 ) ;
} else {
struct V_177 * V_178 ;
T_1 V_179 [ 2 ] ;
V_179 [ 1 ] = V_179 [ 0 ] = 0 ;
F_75 (ha, dev)
F_76 ( F_77 ( V_180 , V_178 -> V_181 ) >> 26 ,
( long * ) V_179 ) ;
F_4 ( V_179 [ 1 ] , & V_6 -> V_17 -> V_182 ) ;
F_4 ( V_179 [ 0 ] , & V_6 -> V_17 -> V_183 ) ;
V_15 &= ~ V_173 ;
V_15 |= V_184 ;
}
F_4 ( V_15 , & V_6 -> V_17 -> V_31 ) ;
}
static int F_78 ( struct V_1 * V_2 , struct V_185 * V_186 , int V_86 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_79 ( V_2 ) )
return - V_87 ;
if ( ! V_6 -> V_37 )
return - V_87 ;
return F_80 ( V_6 -> V_37 , V_186 , V_86 ) ;
}
static int T_5 F_81 ( struct V_187 * V_188 )
{
static unsigned V_189 ;
struct V_5 * V_6 = NULL ;
struct V_190 * V_191 ;
struct V_1 * V_2 = NULL ;
struct V_70 * V_71 , * V_72 ;
int V_69 , V_74 , V_192 = 0 ;
struct V_193 * V_194 , * V_195 ;
V_194 = F_82 ( V_188 , V_196 , 0 ) ;
if ( ! V_194 ) {
F_83 ( & V_188 -> V_2 , L_43 ) ;
V_192 = - V_197 ;
goto V_198;
}
V_195 = F_82 ( V_188 , V_196 , 1 ) ;
if ( ! V_195 ) {
F_83 ( & V_188 -> V_2 , L_44 ) ;
V_192 = - V_197 ;
goto V_198;
}
V_69 = F_84 ( V_188 , 0 ) ;
if ( V_69 < 0 ) {
F_83 ( & V_188 -> V_2 , L_45 ) ;
V_192 = - V_197 ;
goto V_198;
}
if ( ! F_85 ( V_194 -> V_199 , F_86 ( V_194 ) ,
V_188 -> V_68 ) ) {
F_83 ( & V_188 -> V_2 , L_46 ) ;
V_192 = - V_200 ;
goto V_198;
}
if ( ! F_85 ( V_195 -> V_199 , F_86 ( V_195 ) ,
V_188 -> V_68 ) ) {
F_83 ( & V_188 -> V_2 , L_47 ) ;
V_192 = - V_200 ;
goto V_201;
}
V_2 = F_87 ( sizeof( struct V_5 ) ) ;
if ( ! V_2 ) {
F_83 ( & V_188 -> V_2 , L_48 ) ;
V_192 = - V_202 ;
goto V_203;
}
F_88 ( V_2 , & V_188 -> V_2 ) ;
F_89 ( V_188 , V_2 ) ;
V_6 = F_2 ( V_2 ) ;
F_90 ( & V_6 -> V_7 ) ;
V_6 -> V_99 = ( V_140 < 4 ?
V_204 : V_140 ) ;
V_6 -> V_138 = ( T_1 ) F_91 ( NULL , V_205 *
( V_206 + V_207 ) ,
& V_6 -> V_144 , 0 ) ;
if ( ! V_6 -> V_138 ) {
F_83 ( & V_188 -> V_2 , L_49 ) ;
V_192 = - V_202 ;
goto V_208;
}
V_6 -> V_17 = (struct V_209 * )
F_92 ( V_194 -> V_199 , F_86 ( V_194 ) ) ;
if ( ! V_6 -> V_17 ) {
F_83 ( & V_188 -> V_2 , L_50 ) ;
V_192 = - V_200 ;
goto V_210;
}
V_6 -> V_10 = ( T_1 * ) F_92 ( V_195 -> V_199 ,
F_86 ( V_195 ) ) ;
if ( ! V_6 -> V_10 ) {
F_83 ( & V_188 -> V_2 , L_51 ) ;
V_192 = - V_200 ;
goto V_211;
}
V_6 -> V_51 = V_188 -> V_212 ;
if ( V_188 -> V_212 == 0 )
F_34 ( V_6 , V_213 , V_214 ) ;
else if ( V_188 -> V_212 == 1 )
F_34 ( V_6 , V_215 , V_216 ) ;
F_93 ( V_2 -> V_103 ) ;
F_4 ( 0 , V_6 -> V_10 ) ;
V_6 -> V_8 = 0 ;
V_191 = V_188 -> V_2 . V_217 ;
if ( ! V_191 ) {
F_25 ( & V_188 -> V_2 , L_52
L_53 ) ;
V_6 -> V_55 = 1 ;
} else {
if ( F_94 ( V_191 -> V_17 ) )
memcpy ( V_2 -> V_103 , V_191 -> V_17 , 6 ) ;
V_6 -> V_50 = V_191 -> V_50 ;
V_6 -> V_54 = V_191 -> V_54 ;
V_6 -> V_55 = V_191 -> V_55 ;
V_6 -> V_14 = V_191 -> V_14 ;
V_6 -> V_218 = V_191 -> V_218 ;
V_6 -> V_219 = V_191 -> V_219 ;
}
if ( V_6 -> V_218 && V_6 -> V_218 > 0 ) {
F_83 ( & V_188 -> V_2 , L_54 ) ;
V_192 = - V_197 ;
goto V_220;
}
V_6 -> V_26 = F_95 () ;
if ( V_6 -> V_26 == NULL ) {
F_83 ( & V_188 -> V_2 , L_55 ) ;
V_192 = - V_202 ;
goto V_220;
}
V_6 -> V_26 -> V_29 = V_2 ;
V_6 -> V_26 -> V_221 = F_14 ;
V_6 -> V_26 -> V_222 = F_15 ;
V_6 -> V_26 -> V_223 = F_16 ;
V_6 -> V_26 -> V_68 = L_56 ;
snprintf ( V_6 -> V_26 -> V_212 , V_224 , L_57 , V_6 -> V_51 ) ;
V_6 -> V_26 -> V_69 = F_96 ( sizeof( int ) * V_53 , V_225 ) ;
if ( V_6 -> V_26 -> V_69 == NULL )
goto V_226;
for ( V_74 = 0 ; V_74 < V_53 ; ++ V_74 )
V_6 -> V_26 -> V_69 [ V_74 ] = V_227 ;
if ( V_6 -> V_50 )
if ( V_6 -> V_219 && V_6 -> V_218 == V_6 -> V_51 )
V_6 -> V_26 -> V_69 [ V_6 -> V_14 ] = V_6 -> V_219 ;
V_192 = F_97 ( V_6 -> V_26 ) ;
if ( V_192 ) {
F_83 ( & V_188 -> V_2 , L_58 ) ;
goto V_228;
}
if ( F_24 ( V_2 ) != 0 )
goto V_226;
V_72 = NULL ;
V_71 = V_6 -> V_229 ;
for ( V_74 = 0 ; V_74 < ( V_206 + V_207 ) ; V_74 ++ ) {
V_71 -> V_73 = V_72 ;
V_72 = V_71 ;
V_71 -> V_138 = ( T_1 * ) ( ( unsigned ) V_6 -> V_138 + V_205 * V_74 ) ;
V_71 -> V_144 = ( V_230 ) F_98 ( V_71 -> V_138 ) ;
V_71 ++ ;
}
V_6 -> V_72 = V_72 ;
for ( V_74 = 0 ; V_74 < V_76 ; V_74 ++ ) {
V_71 = F_30 ( V_6 ) ;
if ( ! V_71 )
goto V_226;
V_6 -> V_77 [ V_74 ] -> V_78 = ( unsigned ) V_71 -> V_144 ;
V_6 -> V_136 [ V_74 ] = V_71 ;
}
for ( V_74 = 0 ; V_74 < V_79 ; V_74 ++ ) {
V_71 = F_30 ( V_6 ) ;
if ( ! V_71 )
goto V_226;
V_6 -> V_80 [ V_74 ] -> V_78 = ( unsigned ) V_71 -> V_144 ;
V_6 -> V_80 [ V_74 ] -> V_155 = 0 ;
V_6 -> V_164 [ V_74 ] = V_71 ;
}
V_2 -> V_231 = V_194 -> V_199 ;
V_2 -> V_69 = V_69 ;
V_2 -> V_232 = & V_233 ;
F_99 ( V_2 , & V_234 ) ;
V_2 -> V_235 = V_236 ;
F_33 ( V_2 ) ;
V_192 = F_100 ( V_2 ) ;
if ( V_192 ) {
F_10 ( V_2 , L_59 ) ;
goto V_226;
}
F_23 ( V_2 , L_60 ,
( unsigned long ) V_194 -> V_199 , V_69 ) ;
if ( V_189 ++ == 0 )
F_101 ( L_61 ,
V_93 , V_95 , V_237 ) ;
return 0 ;
V_226:
if ( V_6 -> V_26 != NULL )
F_102 ( V_6 -> V_26 ) ;
F_33 ( V_2 ) ;
for ( V_74 = 0 ; V_74 < V_76 ; V_74 ++ ) {
if ( V_6 -> V_136 [ V_74 ] )
F_31 ( V_6 , V_6 -> V_136 [ V_74 ] ) ;
}
for ( V_74 = 0 ; V_74 < V_79 ; V_74 ++ ) {
if ( V_6 -> V_164 [ V_74 ] )
F_31 ( V_6 , V_6 -> V_164 [ V_74 ] ) ;
}
V_228:
F_103 ( V_6 -> V_26 ) ;
V_220:
F_104 ( V_6 -> V_10 ) ;
V_211:
F_104 ( V_6 -> V_17 ) ;
V_210:
F_105 ( NULL , V_205 * ( V_206 + V_207 ) ,
( void * ) V_6 -> V_138 , V_6 -> V_144 ) ;
V_208:
F_106 ( V_2 ) ;
V_203:
F_107 ( V_195 -> V_199 , F_86 ( V_195 ) ) ;
V_201:
F_107 ( V_194 -> V_199 , F_86 ( V_194 ) ) ;
V_198:
return V_192 ;
}
static int T_6 F_108 ( struct V_187 * V_188 )
{
struct V_1 * V_2 = F_109 ( V_188 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_74 ;
struct V_193 * V_194 , * V_195 ;
F_89 ( V_188 , NULL ) ;
F_110 ( V_2 ) ;
F_102 ( V_6 -> V_26 ) ;
F_103 ( V_6 -> V_26 ) ;
for ( V_74 = 0 ; V_74 < V_76 ; V_74 ++ )
if ( V_6 -> V_136 [ V_74 ] )
F_31 ( V_6 , V_6 -> V_136 [ V_74 ] ) ;
for ( V_74 = 0 ; V_74 < V_79 ; V_74 ++ )
if ( V_6 -> V_164 [ V_74 ] )
F_31 ( V_6 , V_6 -> V_164 [ V_74 ] ) ;
F_105 ( NULL , V_205 *
( V_206 + V_207 ) ,
( void * ) V_6 -> V_138 , V_6 -> V_144 ) ;
F_104 ( V_6 -> V_17 ) ;
F_104 ( V_6 -> V_10 ) ;
V_194 = F_82 ( V_188 , V_196 , 0 ) ;
F_107 ( V_194 -> V_199 , F_86 ( V_194 ) ) ;
V_195 = F_82 ( V_188 , V_196 , 1 ) ;
F_107 ( V_195 -> V_199 , F_86 ( V_195 ) ) ;
F_106 ( V_2 ) ;
return 0 ;
}
static int T_7 F_111 ( void )
{
return F_112 ( & V_238 ) ;
}
static void T_8 F_113 ( void )
{
F_114 ( & V_238 ) ;
}
