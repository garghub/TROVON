static inline T_1 F_1 ( unsigned int V_1 )
{
return F_2 ( V_2 + V_1 ) ;
}
static inline T_2 F_3 ( unsigned int V_1 )
{
return F_4 ( V_2 + V_1 ) ;
}
static inline unsigned long F_5 ( unsigned int V_1 )
{
if ( ! V_3 )
return F_1 ( V_1 ) ;
else
return F_3 ( V_1 ) ;
}
static inline void F_6 ( unsigned int V_1 , T_1 V_4 )
{
return F_7 ( V_4 , V_2 + V_1 ) ;
}
static inline void F_8 ( unsigned int V_1 , T_2 V_4 )
{
return F_9 ( V_4 , V_2 + V_1 ) ;
}
static inline void F_10 ( unsigned int V_1 , unsigned long V_4 )
{
if ( ! V_3 )
return F_6 ( V_1 , ( T_1 ) V_4 ) ;
else
return F_8 ( V_1 , ( T_2 ) V_4 ) ;
}
static inline void F_11 ( unsigned int V_1 , unsigned long V_5 ,
unsigned long V_4 )
{
unsigned long V_6 ;
V_6 = F_5 ( V_1 ) ;
V_6 &= ~ V_5 ;
V_6 |= V_4 ;
F_10 ( V_1 , V_6 ) ;
}
static inline void F_12 ( unsigned int V_7 )
{
F_10 ( F_13 ( V_8 , V_9 ) + F_14 ( V_7 ) ,
1ul << F_15 ( V_7 ) ) ;
}
static inline void F_16 ( unsigned int V_7 )
{
F_10 ( F_13 ( V_8 , V_10 ) + F_14 ( V_7 ) ,
1ul << F_15 ( V_7 ) ) ;
}
static inline void F_17 ( unsigned int V_7 , unsigned int V_11 )
{
F_11 ( F_13 ( V_8 , V_12 ) +
F_14 ( V_7 ) , 1ul << F_15 ( V_7 ) ,
( unsigned long ) V_11 << F_15 ( V_7 ) ) ;
}
static inline void F_18 ( unsigned int V_7 , unsigned int V_13 )
{
F_11 ( F_13 ( V_8 , V_14 ) +
F_14 ( V_7 ) , 1ul << F_15 ( V_7 ) ,
( unsigned long ) V_13 << F_15 ( V_7 ) ) ;
}
static inline void F_19 ( unsigned int V_7 , unsigned int V_15 )
{
F_11 ( F_13 ( V_8 , V_16 ) + F_14 ( V_7 ) ,
1ul << F_15 ( V_7 ) ,
( unsigned long ) V_15 << F_15 ( V_7 ) ) ;
}
static inline void F_20 ( unsigned int V_7 , unsigned int V_17 )
{
F_6 ( F_13 ( V_8 , V_18 ) +
F_21 ( V_7 ) , V_19 | V_17 ) ;
}
static inline void F_22 ( unsigned int V_7 , unsigned int V_20 )
{
F_10 ( F_13 ( V_8 , V_21 ) +
F_23 ( V_7 , V_20 ) ,
F_24 ( V_20 ) ) ;
}
T_3 F_25 ( void )
{
unsigned int V_22 , V_23 , V_24 ;
if ( V_3 )
return ( T_3 ) F_5 ( F_13 ( V_8 , V_25 ) ) ;
do {
V_22 = F_1 ( F_13 ( V_8 , V_26 ) ) ;
V_24 = F_1 ( F_13 ( V_8 , V_27 ) ) ;
V_23 = F_1 ( F_13 ( V_8 , V_26 ) ) ;
} while ( V_23 != V_22 );
return ( ( ( T_3 ) V_22 ) << 32 ) + V_24 ;
}
unsigned int F_26 ( void )
{
unsigned int V_28 , V_29 ;
V_29 = F_5 ( F_13 ( V_8 , V_30 ) ) ;
V_28 = 32 + 4 * ( ( V_29 & V_31 ) >>
V_32 ) ;
return V_28 ;
}
void F_27 ( T_3 V_33 )
{
if ( V_3 ) {
F_10 ( F_13 ( V_34 , V_35 ) , V_33 ) ;
} else {
F_6 ( F_13 ( V_34 , V_36 ) ,
( int ) ( V_33 >> 32 ) ) ;
F_6 ( F_13 ( V_34 , V_37 ) ,
( int ) ( V_33 & 0xffffffff ) ) ;
}
}
void F_28 ( T_3 V_33 , int V_38 )
{
unsigned long V_39 ;
F_29 ( V_39 ) ;
F_10 ( F_13 ( V_34 , V_40 ) , V_38 ) ;
if ( V_3 ) {
F_10 ( F_13 ( V_41 , V_35 ) , V_33 ) ;
} else {
F_6 ( F_13 ( V_41 , V_36 ) ,
( int ) ( V_33 >> 32 ) ) ;
F_6 ( F_13 ( V_41 , V_37 ) ,
( int ) ( V_33 & 0xffffffff ) ) ;
}
F_30 ( V_39 ) ;
}
T_3 F_31 ( void )
{
unsigned int V_22 , V_24 ;
if ( V_3 )
return ( T_3 ) F_5 ( F_13 ( V_34 , V_35 ) ) ;
V_22 = F_1 ( F_13 ( V_34 , V_36 ) ) ;
V_24 = F_1 ( F_13 ( V_34 , V_37 ) ) ;
return ( ( ( T_3 ) V_22 ) << 32 ) + V_24 ;
}
void F_32 ( void )
{
T_1 V_42 ;
V_42 = F_5 ( F_13 ( V_8 , V_30 ) ) ;
V_42 &= ~ ( 1 << V_43 ) ;
F_10 ( F_13 ( V_8 , V_30 ) , V_42 ) ;
}
void F_33 ( void )
{
T_1 V_42 ;
V_42 = F_5 ( F_13 ( V_8 , V_30 ) ) ;
V_42 |= 1 << V_43 ;
F_10 ( F_13 ( V_8 , V_30 ) , V_42 ) ;
}
static bool F_34 ( int V_7 )
{
T_1 V_44 ;
if ( V_45 )
return true ;
V_44 = F_1 ( F_13 ( V_34 , V_46 ) ) ;
switch ( V_7 ) {
case V_47 :
return V_44 & V_48 ;
case V_49 :
return V_44 & V_50 ;
case V_51 :
return V_44 & V_52 ;
case V_53 :
case V_54 :
return V_44 & V_55 ;
default:
return true ;
}
}
static void F_35 ( int V_56 , int V_57 )
{
V_56 -= V_58 ;
F_10 ( F_13 ( V_34 , V_59 ) +
F_36 ( V_56 ) , V_57 ) ;
}
static void F_37 ( struct V_60 * V_61 , unsigned int V_38 )
{
T_4 V_62 = F_38 ( F_39 ( V_61 ) ) ;
F_10 ( F_13 ( V_8 , V_63 ) , F_40 ( V_62 ) ) ;
}
int F_41 ( void )
{
if ( ! F_34 ( V_47 ) )
return V_64 + V_65 ;
return F_42 ( V_66 ,
F_43 ( V_47 ) ) ;
}
int F_44 ( void )
{
if ( ! F_34 ( V_49 ) ) {
if ( V_67 < 0 )
return - 1 ;
return V_64 + V_67 ;
}
return F_42 ( V_66 ,
F_43 ( V_49 ) ) ;
}
int F_45 ( void )
{
if ( ! F_34 ( V_51 ) ) {
if ( V_68 < 0 )
return - 1 ;
return V_64 + V_68 ;
}
return F_42 ( V_66 ,
F_43 ( V_51 ) ) ;
}
int F_46 ( struct V_69 * V_70 )
{
if ( ! V_71 )
return - 1 ;
V_70 -> V_72 = V_73 + V_74 ;
V_70 -> V_75 = V_70 -> V_72 + ( V_76 - 1 ) ;
return 0 ;
}
static void F_47 ( bool V_77 )
{
unsigned int V_78 , V_7 , V_79 , V_80 = V_3 ? 8 : 4 ;
unsigned long * V_81 ;
unsigned long V_82 , V_83 ;
F_48 ( V_84 , V_85 ) ;
F_48 ( V_86 , V_85 ) ;
V_81 = V_87 [ F_49 () ] . V_81 ;
V_82 = F_13 ( V_8 , V_88 ) ;
V_83 = F_13 ( V_8 , V_89 ) ;
for ( V_78 = 0 ; V_78 < F_50 ( V_90 ) ; V_78 ++ ) {
V_84 [ V_78 ] = F_5 ( V_82 ) ;
V_86 [ V_78 ] = F_5 ( V_83 ) ;
V_82 += V_80 ;
V_83 += V_80 ;
if ( ! F_51 ( V_91 ) || V_3 )
continue;
V_84 [ V_78 ] |= ( T_2 ) F_5 ( V_82 ) << 32 ;
V_86 [ V_78 ] |= ( T_2 ) F_5 ( V_83 ) << 32 ;
V_82 += V_80 ;
V_83 += V_80 ;
}
F_52 ( V_84 , V_84 , V_86 , V_90 ) ;
F_52 ( V_84 , V_84 , V_81 , V_90 ) ;
V_7 = F_53 ( V_84 , V_90 ) ;
while ( V_7 != V_90 ) {
V_79 = F_54 ( V_66 ,
F_55 ( V_7 ) ) ;
if ( V_77 )
F_56 ( V_79 ) ;
else
F_57 ( V_79 ) ;
F_58 ( V_84 , V_7 , 1 ) ;
V_7 = F_53 ( V_84 , V_90 ) ;
}
}
static void F_59 ( struct V_60 * V_61 )
{
F_12 ( F_38 ( V_61 -> V_62 ) ) ;
}
static void F_60 ( struct V_60 * V_61 )
{
F_16 ( F_38 ( V_61 -> V_62 ) ) ;
}
static void F_61 ( struct V_60 * V_61 )
{
unsigned int V_56 = F_38 ( V_61 -> V_62 ) ;
F_10 ( F_13 ( V_8 , V_63 ) , F_62 ( V_56 ) ) ;
}
static int F_63 ( struct V_60 * V_61 , unsigned int type )
{
unsigned int V_56 = F_38 ( V_61 -> V_62 ) ;
unsigned long V_39 ;
bool V_92 ;
F_64 ( & V_93 , V_39 ) ;
switch ( type & V_94 ) {
case V_95 :
F_17 ( V_56 , V_96 ) ;
F_18 ( V_56 , V_97 ) ;
F_19 ( V_56 , V_98 ) ;
V_92 = true ;
break;
case V_99 :
F_17 ( V_56 , V_100 ) ;
F_18 ( V_56 , V_97 ) ;
F_19 ( V_56 , V_98 ) ;
V_92 = true ;
break;
case V_101 :
F_18 ( V_56 , V_97 ) ;
F_19 ( V_56 , V_102 ) ;
V_92 = true ;
break;
case V_103 :
F_17 ( V_56 , V_96 ) ;
F_18 ( V_56 , V_104 ) ;
F_19 ( V_56 , V_98 ) ;
V_92 = false ;
break;
case V_105 :
default:
F_17 ( V_56 , V_100 ) ;
F_18 ( V_56 , V_104 ) ;
F_19 ( V_56 , V_98 ) ;
V_92 = false ;
break;
}
if ( V_92 )
F_65 ( V_61 , & V_106 ,
V_107 , NULL ) ;
else
F_65 ( V_61 , & V_108 ,
V_109 , NULL ) ;
F_66 ( & V_93 , V_39 ) ;
return 0 ;
}
static int F_67 ( struct V_60 * V_61 , const struct V_110 * V_110 ,
bool V_111 )
{
unsigned int V_56 = F_38 ( V_61 -> V_62 ) ;
T_5 V_112 = V_113 ;
unsigned long V_39 ;
int V_78 ;
F_68 ( & V_112 , V_110 , V_114 ) ;
if ( F_69 ( & V_112 ) )
return - V_115 ;
F_64 ( & V_93 , V_39 ) ;
F_22 ( V_56 , F_70 ( F_71 ( & V_112 ) ) ) ;
for ( V_78 = 0 ; V_78 < F_72 ( V_116 , V_117 ) ; V_78 ++ )
F_73 ( V_56 , V_87 [ V_78 ] . V_81 ) ;
F_74 ( V_56 , V_87 [ F_71 ( & V_112 ) ] . V_81 ) ;
F_75 ( F_76 ( V_61 ) , V_110 ) ;
F_66 ( & V_93 , V_39 ) ;
return V_118 ;
}
static void F_77 ( bool V_77 )
{
unsigned long V_84 , V_119 ;
unsigned int V_7 , V_79 ;
V_84 = F_1 ( F_13 ( V_34 , V_120 ) ) ;
V_119 = F_1 ( F_13 ( V_34 , V_121 ) ) ;
F_52 ( & V_84 , & V_84 , & V_119 , V_122 ) ;
V_7 = F_53 ( & V_84 , V_122 ) ;
while ( V_7 != V_122 ) {
V_79 = F_54 ( V_66 ,
F_43 ( V_7 ) ) ;
if ( V_77 )
F_56 ( V_79 ) ;
else
F_57 ( V_79 ) ;
F_58 ( & V_84 , V_7 , 1 ) ;
V_7 = F_53 ( & V_84 , V_122 ) ;
}
}
static void F_78 ( struct V_60 * V_61 )
{
int V_7 = F_79 ( V_61 -> V_62 ) ;
F_6 ( F_13 ( V_34 , V_123 ) , 1 << V_7 ) ;
}
static void F_80 ( struct V_60 * V_61 )
{
int V_7 = F_79 ( V_61 -> V_62 ) ;
F_6 ( F_13 ( V_34 , V_124 ) , 1 << V_7 ) ;
}
static void F_81 ( struct V_60 * V_61 )
{
int V_7 = F_79 ( V_61 -> V_62 ) ;
int V_78 ;
unsigned long V_39 ;
F_64 ( & V_93 , V_39 ) ;
for ( V_78 = 0 ; V_78 < V_116 ; V_78 ++ ) {
F_10 ( F_13 ( V_34 , V_40 ) , V_78 ) ;
F_6 ( F_13 ( V_41 , V_123 ) , 1 << V_7 ) ;
}
F_66 ( & V_93 , V_39 ) ;
}
static void F_82 ( struct V_60 * V_61 )
{
int V_7 = F_79 ( V_61 -> V_62 ) ;
int V_78 ;
unsigned long V_39 ;
F_64 ( & V_93 , V_39 ) ;
for ( V_78 = 0 ; V_78 < V_116 ; V_78 ++ ) {
F_10 ( F_13 ( V_34 , V_40 ) , V_78 ) ;
F_6 ( F_13 ( V_41 , V_124 ) , 1 << V_7 ) ;
}
F_66 ( & V_93 , V_39 ) ;
}
static void F_83 ( void )
{
F_77 ( false ) ;
F_47 ( false ) ;
}
static void F_84 ( struct V_125 * V_126 )
{
F_77 ( true ) ;
F_47 ( true ) ;
}
static void T_6 F_85 ( void )
{
unsigned int V_78 ;
V_127 = & F_35 ;
for ( V_78 = 0 ; V_78 < V_90 ; V_78 ++ ) {
F_17 ( V_78 , V_100 ) ;
F_18 ( V_78 , V_104 ) ;
F_12 ( V_78 ) ;
}
for ( V_78 = 0 ; V_78 < V_116 ; V_78 ++ ) {
unsigned int V_128 ;
F_10 ( F_13 ( V_34 , V_40 ) , V_78 ) ;
for ( V_128 = 0 ; V_128 < V_122 ; V_128 ++ ) {
if ( ! F_34 ( V_128 ) )
continue;
F_6 ( F_13 ( V_41 , V_123 ) , 1 << V_128 ) ;
}
}
}
static int F_86 ( struct V_129 * V_61 , unsigned int V_79 ,
T_4 V_130 )
{
int V_7 = F_79 ( V_130 ) ;
int V_131 = 0 ;
int V_78 ;
unsigned long V_39 ;
if ( ! F_34 ( V_7 ) )
return - V_132 ;
switch ( V_7 ) {
case V_47 :
case V_49 :
case V_51 :
F_87 ( V_79 ,
& V_133 ,
V_134 ) ;
break;
default:
F_87 ( V_79 ,
& V_135 ,
V_136 ) ;
F_88 ( V_79 ) ;
break;
}
F_64 ( & V_93 , V_39 ) ;
for ( V_78 = 0 ; V_78 < V_116 ; V_78 ++ ) {
T_1 V_4 = V_19 | V_137 ;
F_10 ( F_13 ( V_34 , V_40 ) , V_78 ) ;
switch ( V_7 ) {
case V_138 :
F_6 ( F_13 ( V_41 , V_139 ) , V_4 ) ;
break;
case V_140 :
F_6 ( F_13 ( V_41 , V_141 ) ,
V_4 ) ;
break;
case V_47 :
V_4 = V_19 | V_142 ;
F_6 ( F_13 ( V_41 , V_143 ) ,
V_4 ) ;
break;
case V_49 :
F_6 ( F_13 ( V_41 , V_144 ) ,
V_4 ) ;
break;
case V_53 :
F_6 ( F_13 ( V_41 , V_145 ) ,
V_4 ) ;
break;
case V_54 :
F_6 ( F_13 ( V_41 , V_146 ) ,
V_4 ) ;
break;
case V_51 :
F_6 ( F_13 ( V_41 , V_147 ) , V_4 ) ;
break;
default:
F_89 ( L_1 , V_7 ) ;
V_131 = - V_115 ;
break;
}
}
F_66 ( & V_93 , V_39 ) ;
return V_131 ;
}
static int F_90 ( struct V_129 * V_61 , unsigned int V_79 ,
T_4 V_130 , unsigned int V_20 )
{
int V_7 = F_38 ( V_130 ) ;
unsigned long V_39 ;
int V_78 ;
F_87 ( V_79 , & V_108 ,
V_109 ) ;
F_64 ( & V_93 , V_39 ) ;
F_20 ( V_7 , V_137 ) ;
F_22 ( V_7 , V_20 ) ;
for ( V_78 = 0 ; V_78 < F_72 ( V_116 , V_117 ) ; V_78 ++ )
F_73 ( V_7 , V_87 [ V_78 ] . V_81 ) ;
F_74 ( V_7 , V_87 [ V_20 ] . V_81 ) ;
F_66 ( & V_93 , V_39 ) ;
return 0 ;
}
static int F_91 ( struct V_129 * V_61 , unsigned int V_79 ,
T_4 V_130 )
{
if ( F_79 ( V_130 ) < V_122 )
return F_86 ( V_61 , V_79 , V_130 ) ;
return F_90 ( V_61 , V_79 , V_130 , 0 ) ;
}
static int F_92 ( struct V_129 * V_61 , unsigned int V_79 ,
unsigned int V_148 , void * V_149 )
{
struct V_150 * V_151 = V_149 ;
T_4 V_62 , V_152 ;
int V_38 , V_131 , V_78 ;
if ( V_151 -> type == V_153 ) {
if ( F_93 ( V_151 -> V_62 , V_154 ) )
return - V_155 ;
} else {
V_152 = F_53 ( V_154 , V_90 ) ;
if ( V_152 == V_90 ) {
return - V_156 ;
}
for ( V_78 = V_152 ; V_78 < V_148 ; V_78 ++ ) {
if ( ! F_93 ( V_78 , V_154 ) )
return - V_155 ;
}
F_58 ( V_154 , V_152 , V_148 ) ;
V_78 = 0 ;
F_94 (cpu, spec->ipimask) {
V_62 = F_55 ( V_152 + V_78 ) ;
V_131 = F_95 ( V_61 , V_79 + V_78 , V_62 ,
& V_106 ,
NULL ) ;
if ( V_131 )
goto error;
V_131 = F_90 ( V_61 , V_79 + V_78 , V_62 , V_38 ) ;
if ( V_131 )
goto error;
V_78 ++ ;
}
V_151 -> V_62 = V_152 ;
}
return 0 ;
error:
F_96 ( V_154 , V_152 , V_148 ) ;
return V_131 ;
}
void F_97 ( struct V_129 * V_61 , unsigned int V_79 ,
unsigned int V_148 )
{
T_4 V_152 ;
struct V_60 * V_157 ;
V_157 = F_98 ( V_79 ) ;
if ( ! V_157 )
return;
V_152 = F_38 ( F_39 ( V_157 ) ) ;
F_96 ( V_154 , V_152 , V_148 ) ;
}
int F_99 ( struct V_129 * V_61 , struct V_158 * V_159 ,
enum V_160 V_161 )
{
return 0 ;
}
static int F_100 ( struct V_129 * V_61 , struct V_158 * V_162 ,
const T_1 * V_163 , unsigned int V_164 ,
T_4 * V_165 ,
unsigned int * V_166 )
{
if ( V_164 != 3 )
return - V_115 ;
if ( V_163 [ 0 ] == V_167 )
* V_165 = F_55 ( V_163 [ 1 ] ) ;
else if ( V_163 [ 0 ] == V_168 )
* V_165 = F_43 ( V_163 [ 1 ] ) ;
else
return - V_115 ;
* V_166 = V_163 [ 2 ] & V_94 ;
return 0 ;
}
static int F_101 ( struct V_129 * V_61 , unsigned int V_79 ,
unsigned int V_148 , void * V_149 )
{
struct V_169 * V_170 = V_149 ;
struct V_150 V_151 = {
. type = V_153 ,
. V_62 = V_170 -> V_171 [ 1 ] ,
} ;
int V_78 , V_131 ;
bool V_172 = V_170 -> V_171 [ 0 ] == V_167 ;
if ( V_172 ) {
V_131 = F_102 ( V_61 , V_79 , V_148 , & V_151 ) ;
if ( V_131 )
return V_131 ;
}
for ( V_78 = 0 ; V_78 < V_148 ; V_78 ++ ) {
T_4 V_62 ;
if ( V_172 )
V_62 = F_55 ( V_151 . V_62 + V_78 ) ;
else
V_62 = F_43 ( V_151 . V_62 + V_78 ) ;
V_131 = F_95 ( V_61 , V_79 + V_78 ,
V_62 ,
& V_108 ,
NULL ) ;
if ( V_131 )
return V_131 ;
}
return 0 ;
}
void F_103 ( struct V_129 * V_61 , unsigned int V_79 ,
unsigned int V_148 )
{
return;
}
static int F_104 ( struct V_129 * V_61 , struct V_158 * V_162 ,
const T_1 * V_163 , unsigned int V_164 ,
T_4 * V_165 ,
unsigned int * V_166 )
{
* V_165 = 0 ;
* V_166 = V_99 ;
return 0 ;
}
static int F_105 ( struct V_129 * V_61 , unsigned int V_79 ,
unsigned int V_148 , void * V_149 )
{
struct V_110 * V_173 = V_149 ;
struct V_150 V_151 = {
. type = V_174 ,
. V_173 = V_173
} ;
int V_131 , V_78 ;
V_131 = F_102 ( V_61 , V_79 , V_148 , & V_151 ) ;
if ( V_131 )
return V_131 ;
for ( V_78 = 0 ; V_78 < V_148 ; V_78 ++ ) {
V_131 = F_95 ( V_61 , V_79 + V_78 ,
F_55 ( V_151 . V_62 + V_78 ) ,
& V_106 ,
NULL ) ;
if ( V_131 )
goto error;
V_131 = F_106 ( V_79 + V_78 , V_99 ) ;
if ( V_131 )
goto error;
}
return 0 ;
error:
F_107 ( V_61 , V_79 , V_148 ) ;
return V_131 ;
}
void F_108 ( struct V_129 * V_61 , unsigned int V_79 ,
unsigned int V_148 )
{
F_107 ( V_61 , V_79 , V_148 ) ;
}
int F_109 ( struct V_129 * V_61 , struct V_158 * V_159 ,
enum V_160 V_161 )
{
bool V_175 ;
switch ( V_161 ) {
case V_176 :
V_175 = V_61 -> V_161 == V_161 ;
return F_110 ( V_61 -> V_177 ) == V_159 && V_175 ;
break;
default:
return 0 ;
}
}
static void T_6 F_111 ( unsigned long V_178 ,
unsigned long V_179 ,
unsigned int V_180 , unsigned int V_181 ,
struct V_158 * V_159 )
{
unsigned int V_42 ;
unsigned int V_182 [ 2 ] ;
V_73 = V_178 ;
V_2 = F_112 ( V_178 , V_179 ) ;
V_42 = F_5 ( F_13 ( V_8 , V_30 ) ) ;
V_90 = ( V_42 & V_183 ) >>
V_184 ;
V_90 = ( ( V_90 + 1 ) * 8 ) ;
V_116 = ( V_42 & V_185 ) >>
V_186 ;
V_116 = V_116 + 1 ;
if ( V_45 ) {
V_137 = 0 ;
V_142 = V_137 ;
F_113 ( V_137 + V_58 ,
F_83 ) ;
} else {
V_137 = V_180 - V_187 ;
F_114 ( V_64 + V_180 ,
F_84 ) ;
if ( F_115 ( V_188 ) &&
F_34 ( V_47 ) ) {
V_142 = F_1 ( F_13 ( V_34 ,
V_143 ) ) &
V_189 ;
F_114 ( V_64 +
V_187 +
V_142 ,
F_84 ) ;
} else {
V_142 = V_137 ;
}
}
V_66 = F_116 ( V_159 , V_122 +
V_90 , V_181 ,
& V_190 , NULL ) ;
if ( ! V_66 )
F_117 ( L_2 ) ;
V_191 = F_118 ( V_66 , 0 ,
V_122 + V_90 ,
V_159 , & V_192 , NULL ) ;
if ( ! V_191 )
F_117 ( L_3 ) ;
V_193 = F_118 ( V_66 ,
V_194 ,
V_122 + V_90 ,
V_159 , & V_195 , NULL ) ;
if ( ! V_193 )
F_117 ( L_4 ) ;
V_193 -> V_161 = V_176 ;
if ( V_159 &&
! F_119 ( V_159 , L_5 , V_182 , 2 ) ) {
F_96 ( V_154 , V_182 [ 0 ] , V_182 [ 1 ] ) ;
} else {
F_96 ( V_154 ,
V_90 - 2 * V_116 ,
2 * V_116 ) ;
}
F_85 () ;
}
void T_6 F_120 ( unsigned long V_178 ,
unsigned long V_179 ,
unsigned int V_180 , unsigned int V_181 )
{
F_111 ( V_178 , V_179 , V_180 , V_181 , NULL ) ;
}
static int T_6 F_121 ( struct V_158 * V_159 ,
struct V_158 * V_196 )
{
struct V_69 V_197 ;
unsigned int V_180 , V_78 = 0 , V_198 = 0 ;
T_7 V_2 ;
T_8 V_199 ;
while ( ! F_122 ( V_159 , L_6 ,
V_78 ++ , & V_180 ) )
V_198 |= F_123 ( V_180 ) ;
for ( V_180 = 2 ; V_180 < 8 ; V_180 ++ ) {
if ( ! ( V_198 & F_123 ( V_180 ) ) )
break;
}
if ( V_180 == 8 ) {
F_89 ( L_7 ) ;
return - V_200 ;
}
if ( F_124 ( V_159 , 0 , & V_197 ) ) {
if ( F_125 () ) {
V_2 = F_126 () &
~ V_201 ;
V_199 = 0x20000 ;
} else {
F_89 ( L_8 ) ;
return - V_200 ;
}
} else {
V_2 = V_197 . V_72 ;
V_199 = F_127 ( & V_197 ) ;
}
if ( F_125 () )
F_128 ( V_2 | V_201 ) ;
V_71 = true ;
F_111 ( V_2 , V_199 , V_180 , 0 , V_159 ) ;
return 0 ;
}
