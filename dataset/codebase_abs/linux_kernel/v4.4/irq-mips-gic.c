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
void F_37 ( unsigned int V_7 )
{
F_10 ( F_13 ( V_8 , V_60 ) , F_38 ( V_7 ) ) ;
}
int F_39 ( void )
{
if ( ! F_34 ( V_47 ) )
return V_61 + V_62 ;
return F_40 ( V_63 ,
F_41 ( V_47 ) ) ;
}
int F_42 ( void )
{
if ( ! F_34 ( V_49 ) ) {
if ( V_64 < 0 )
return - 1 ;
return V_61 + V_64 ;
}
return F_40 ( V_63 ,
F_41 ( V_49 ) ) ;
}
int F_43 ( void )
{
if ( ! F_34 ( V_51 ) ) {
if ( V_65 < 0 )
return - 1 ;
return V_61 + V_65 ;
}
return F_40 ( V_63 ,
F_41 ( V_51 ) ) ;
}
int F_44 ( struct V_66 * V_67 )
{
if ( ! V_68 )
return - 1 ;
V_67 -> V_69 = V_70 + V_71 ;
V_67 -> V_72 = V_67 -> V_69 + ( V_73 - 1 ) ;
return 0 ;
}
static void F_45 ( bool V_74 )
{
unsigned int V_75 , V_7 , V_76 , V_77 = V_3 ? 8 : 4 ;
unsigned long * V_78 ;
unsigned long V_79 , V_80 ;
F_46 ( V_81 , V_82 ) ;
F_46 ( V_83 , V_82 ) ;
V_78 = V_84 [ F_47 () ] . V_78 ;
V_79 = F_13 ( V_8 , V_85 ) ;
V_80 = F_13 ( V_8 , V_86 ) ;
for ( V_75 = 0 ; V_75 < F_48 ( V_87 ) ; V_75 ++ ) {
V_81 [ V_75 ] = F_5 ( V_79 ) ;
V_83 [ V_75 ] = F_5 ( V_80 ) ;
V_79 += V_77 ;
V_80 += V_77 ;
if ( ! F_49 ( V_88 ) || V_3 )
continue;
V_81 [ V_75 ] |= ( T_2 ) F_5 ( V_79 ) << 32 ;
V_83 [ V_75 ] |= ( T_2 ) F_5 ( V_80 ) << 32 ;
V_79 += V_77 ;
V_80 += V_77 ;
}
F_50 ( V_81 , V_81 , V_83 , V_87 ) ;
F_50 ( V_81 , V_81 , V_78 , V_87 ) ;
V_7 = F_51 ( V_81 , V_87 ) ;
while ( V_7 != V_87 ) {
V_76 = F_52 ( V_63 ,
F_53 ( V_7 ) ) ;
if ( V_74 )
F_54 ( V_76 ) ;
else
F_55 ( V_76 ) ;
F_56 ( V_81 , V_7 , 1 ) ;
V_7 = F_51 ( V_81 , V_87 ) ;
}
}
static void F_57 ( struct V_89 * V_90 )
{
F_12 ( F_58 ( V_90 -> V_91 ) ) ;
}
static void F_59 ( struct V_89 * V_90 )
{
F_16 ( F_58 ( V_90 -> V_91 ) ) ;
}
static void F_60 ( struct V_89 * V_90 )
{
unsigned int V_56 = F_58 ( V_90 -> V_91 ) ;
F_10 ( F_13 ( V_8 , V_60 ) , F_61 ( V_56 ) ) ;
}
static int F_62 ( struct V_89 * V_90 , unsigned int type )
{
unsigned int V_56 = F_58 ( V_90 -> V_91 ) ;
unsigned long V_39 ;
bool V_92 ;
F_63 ( & V_93 , V_39 ) ;
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
F_64 ( V_90 , & V_106 ,
V_107 , NULL ) ;
else
F_64 ( V_90 , & V_108 ,
V_109 , NULL ) ;
F_65 ( & V_93 , V_39 ) ;
return 0 ;
}
static int F_66 ( struct V_89 * V_90 , const struct V_110 * V_110 ,
bool V_111 )
{
unsigned int V_56 = F_58 ( V_90 -> V_91 ) ;
T_4 V_112 = V_113 ;
unsigned long V_39 ;
int V_75 ;
F_67 ( & V_112 , V_110 , V_114 ) ;
if ( F_68 ( & V_112 ) )
return - V_115 ;
F_63 ( & V_93 , V_39 ) ;
F_22 ( V_56 , F_69 ( F_70 ( & V_112 ) ) ) ;
for ( V_75 = 0 ; V_75 < V_116 ; V_75 ++ )
F_71 ( V_56 , V_84 [ V_75 ] . V_78 ) ;
F_72 ( V_56 , V_84 [ F_70 ( & V_112 ) ] . V_78 ) ;
F_73 ( F_74 ( V_90 ) , V_110 ) ;
F_65 ( & V_93 , V_39 ) ;
return V_117 ;
}
static void F_75 ( bool V_74 )
{
unsigned long V_81 , V_118 ;
unsigned int V_7 , V_76 ;
V_81 = F_1 ( F_13 ( V_34 , V_119 ) ) ;
V_118 = F_1 ( F_13 ( V_34 , V_120 ) ) ;
F_50 ( & V_81 , & V_81 , & V_118 , V_121 ) ;
V_7 = F_51 ( & V_81 , V_121 ) ;
while ( V_7 != V_121 ) {
V_76 = F_52 ( V_63 ,
F_41 ( V_7 ) ) ;
if ( V_74 )
F_54 ( V_76 ) ;
else
F_55 ( V_76 ) ;
F_56 ( & V_81 , V_7 , 1 ) ;
V_7 = F_51 ( & V_81 , V_121 ) ;
}
}
static void F_76 ( struct V_89 * V_90 )
{
int V_7 = F_77 ( V_90 -> V_91 ) ;
F_6 ( F_13 ( V_34 , V_122 ) , 1 << V_7 ) ;
}
static void F_78 ( struct V_89 * V_90 )
{
int V_7 = F_77 ( V_90 -> V_91 ) ;
F_6 ( F_13 ( V_34 , V_123 ) , 1 << V_7 ) ;
}
static void F_79 ( struct V_89 * V_90 )
{
int V_7 = F_77 ( V_90 -> V_91 ) ;
int V_75 ;
unsigned long V_39 ;
F_63 ( & V_93 , V_39 ) ;
for ( V_75 = 0 ; V_75 < V_124 ; V_75 ++ ) {
F_10 ( F_13 ( V_34 , V_40 ) , V_75 ) ;
F_6 ( F_13 ( V_41 , V_122 ) , 1 << V_7 ) ;
}
F_65 ( & V_93 , V_39 ) ;
}
static void F_80 ( struct V_89 * V_90 )
{
int V_7 = F_77 ( V_90 -> V_91 ) ;
int V_75 ;
unsigned long V_39 ;
F_63 ( & V_93 , V_39 ) ;
for ( V_75 = 0 ; V_75 < V_124 ; V_75 ++ ) {
F_10 ( F_13 ( V_34 , V_40 ) , V_75 ) ;
F_6 ( F_13 ( V_41 , V_123 ) , 1 << V_7 ) ;
}
F_65 ( & V_93 , V_39 ) ;
}
static void F_81 ( void )
{
F_75 ( false ) ;
F_45 ( false ) ;
}
static void F_82 ( struct V_125 * V_126 )
{
F_75 ( true ) ;
F_45 ( true ) ;
}
unsigned int F_83 ( unsigned int V_38 )
{
return V_127 + V_38 ;
}
unsigned int F_84 ( unsigned int V_38 )
{
return V_128 + V_38 ;
}
static T_5 F_85 ( int V_56 , void * V_129 )
{
F_86 () ;
return V_130 ;
}
static T_5 F_87 ( int V_56 , void * V_129 )
{
F_88 () ;
return V_130 ;
}
static T_6 void F_89 ( unsigned int V_7 , int V_38 ,
struct V_131 * V_132 )
{
int V_76 = F_40 ( V_63 ,
F_53 ( V_7 ) ) ;
int V_75 ;
F_22 ( V_7 , F_69 ( V_38 ) ) ;
for ( V_75 = 0 ; V_75 < V_116 ; V_75 ++ )
F_71 ( V_7 , V_84 [ V_75 ] . V_78 ) ;
F_72 ( V_7 , V_84 [ V_38 ] . V_78 ) ;
F_90 ( V_76 , V_99 ) ;
F_91 ( V_76 , V_133 ) ;
F_92 ( V_76 , V_132 ) ;
}
static T_6 void F_93 ( void )
{
int V_75 ;
V_127 = V_87 - V_134 ;
V_128 = V_127 - V_134 ;
for ( V_75 = 0 ; V_75 < V_134 ; V_75 ++ ) {
F_89 ( V_128 + V_75 , V_75 , & V_135 ) ;
F_89 ( V_127 + V_75 , V_75 , & V_136 ) ;
}
}
static inline void F_93 ( void )
{
}
static void T_6 F_94 ( void )
{
unsigned int V_75 ;
V_137 = & F_35 ;
for ( V_75 = 0 ; V_75 < V_87 ; V_75 ++ ) {
F_17 ( V_75 , V_100 ) ;
F_18 ( V_75 , V_104 ) ;
F_12 ( V_75 ) ;
}
for ( V_75 = 0 ; V_75 < V_124 ; V_75 ++ ) {
unsigned int V_138 ;
F_10 ( F_13 ( V_34 , V_40 ) , V_75 ) ;
for ( V_138 = 0 ; V_138 < V_121 ; V_138 ++ ) {
if ( ! F_34 ( V_138 ) )
continue;
F_6 ( F_13 ( V_41 , V_122 ) , 1 << V_138 ) ;
}
}
}
static int F_95 ( struct V_139 * V_90 , unsigned int V_76 ,
T_7 V_140 )
{
int V_7 = F_77 ( V_140 ) ;
int V_141 = 0 ;
int V_75 ;
unsigned long V_39 ;
if ( ! F_34 ( V_7 ) )
return - V_142 ;
switch ( V_7 ) {
case V_47 :
case V_49 :
case V_51 :
F_96 ( V_76 ,
& V_143 ,
V_133 ) ;
break;
default:
F_96 ( V_76 ,
& V_144 ,
V_145 ) ;
F_97 ( V_76 ) ;
break;
}
F_63 ( & V_93 , V_39 ) ;
for ( V_75 = 0 ; V_75 < V_124 ; V_75 ++ ) {
T_1 V_4 = V_19 | V_146 ;
F_10 ( F_13 ( V_34 , V_40 ) , V_75 ) ;
switch ( V_7 ) {
case V_147 :
F_6 ( F_13 ( V_41 , V_148 ) , V_4 ) ;
break;
case V_149 :
F_6 ( F_13 ( V_41 , V_150 ) ,
V_4 ) ;
break;
case V_47 :
V_4 = V_19 | V_151 ;
F_6 ( F_13 ( V_41 , V_152 ) ,
V_4 ) ;
break;
case V_49 :
F_6 ( F_13 ( V_41 , V_153 ) ,
V_4 ) ;
break;
case V_53 :
F_6 ( F_13 ( V_41 , V_154 ) ,
V_4 ) ;
break;
case V_54 :
F_6 ( F_13 ( V_41 , V_155 ) ,
V_4 ) ;
break;
case V_51 :
F_6 ( F_13 ( V_41 , V_156 ) , V_4 ) ;
break;
default:
F_98 ( L_1 , V_7 ) ;
V_141 = - V_115 ;
break;
}
}
F_65 ( & V_93 , V_39 ) ;
return V_141 ;
}
static int F_99 ( struct V_139 * V_90 , unsigned int V_76 ,
T_7 V_140 )
{
int V_7 = F_58 ( V_140 ) ;
unsigned long V_39 ;
F_96 ( V_76 , & V_108 ,
V_109 ) ;
F_63 ( & V_93 , V_39 ) ;
F_20 ( V_7 , V_146 ) ;
F_22 ( V_7 , 0 ) ;
F_72 ( V_7 , V_84 [ 0 ] . V_78 ) ;
F_65 ( & V_93 , V_39 ) ;
return 0 ;
}
static int F_100 ( struct V_139 * V_90 , unsigned int V_76 ,
T_7 V_140 )
{
if ( F_77 ( V_140 ) < V_121 )
return F_95 ( V_90 , V_76 , V_140 ) ;
return F_99 ( V_90 , V_76 , V_140 ) ;
}
static int F_101 ( struct V_139 * V_90 , struct V_157 * V_158 ,
const T_1 * V_159 , unsigned int V_160 ,
T_7 * V_161 ,
unsigned int * V_162 )
{
if ( V_160 != 3 )
return - V_115 ;
if ( V_159 [ 0 ] == V_163 )
* V_161 = F_53 ( V_159 [ 1 ] ) ;
else if ( V_159 [ 0 ] == V_164 )
* V_161 = F_41 ( V_159 [ 1 ] ) ;
else
return - V_115 ;
* V_162 = V_159 [ 2 ] & V_94 ;
return 0 ;
}
static void T_6 F_102 ( unsigned long V_165 ,
unsigned long V_166 ,
unsigned int V_167 , unsigned int V_168 ,
struct V_157 * V_169 )
{
unsigned int V_42 ;
V_70 = V_165 ;
V_2 = F_103 ( V_165 , V_166 ) ;
V_42 = F_5 ( F_13 ( V_8 , V_30 ) ) ;
V_87 = ( V_42 & V_170 ) >>
V_171 ;
V_87 = ( ( V_87 + 1 ) * 8 ) ;
V_124 = ( V_42 & V_172 ) >>
V_173 ;
V_124 = V_124 + 1 ;
if ( V_45 ) {
V_146 = 0 ;
V_151 = V_146 ;
F_104 ( V_146 + V_58 ,
F_81 ) ;
} else {
V_146 = V_167 - V_174 ;
F_105 ( V_61 + V_167 ,
F_82 ) ;
if ( F_106 ( V_175 ) &&
F_34 ( V_47 ) ) {
V_151 = F_1 ( F_13 ( V_34 ,
V_152 ) ) &
V_176 ;
F_105 ( V_61 +
V_174 +
V_151 ,
F_82 ) ;
} else {
V_151 = V_146 ;
}
}
V_63 = F_107 ( V_169 , V_121 +
V_87 , V_168 ,
& V_177 , NULL ) ;
if ( ! V_63 )
F_108 ( L_2 ) ;
F_94 () ;
F_93 () ;
}
void T_6 F_109 ( unsigned long V_165 ,
unsigned long V_166 ,
unsigned int V_167 , unsigned int V_168 )
{
F_102 ( V_165 , V_166 , V_167 , V_168 , NULL ) ;
}
static int T_6 F_110 ( struct V_157 * V_169 ,
struct V_157 * V_178 )
{
struct V_66 V_179 ;
unsigned int V_167 , V_75 = 0 , V_180 = 0 ;
T_8 V_2 ;
T_9 V_181 ;
while ( ! F_111 ( V_169 , L_3 ,
V_75 ++ , & V_167 ) )
V_180 |= F_112 ( V_167 ) ;
for ( V_167 = 2 ; V_167 < 8 ; V_167 ++ ) {
if ( ! ( V_180 & F_112 ( V_167 ) ) )
break;
}
if ( V_167 == 8 ) {
F_98 ( L_4 ) ;
return - V_182 ;
}
if ( F_113 ( V_169 , 0 , & V_179 ) ) {
if ( F_114 () ) {
V_2 = F_115 () &
~ V_183 ;
V_181 = 0x20000 ;
} else {
F_98 ( L_5 ) ;
return - V_182 ;
}
} else {
V_2 = V_179 . V_69 ;
V_181 = F_116 ( & V_179 ) ;
}
if ( F_114 () )
F_117 ( V_2 | V_183 ) ;
V_68 = true ;
F_102 ( V_2 , V_181 , V_167 , 0 , V_169 ) ;
return 0 ;
}
