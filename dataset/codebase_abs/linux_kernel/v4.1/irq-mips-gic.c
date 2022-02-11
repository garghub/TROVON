static inline unsigned int F_1 ( unsigned int V_1 )
{
return F_2 ( V_2 + V_1 ) ;
}
static inline void F_3 ( unsigned int V_1 , unsigned int V_3 )
{
F_4 ( V_3 , V_2 + V_1 ) ;
}
static inline void F_5 ( unsigned int V_1 , unsigned int V_4 ,
unsigned int V_3 )
{
unsigned int V_5 ;
V_5 = F_1 ( V_1 ) ;
V_5 &= ~ V_4 ;
V_5 |= V_3 ;
F_3 ( V_1 , V_5 ) ;
}
static inline void F_6 ( unsigned int V_6 )
{
F_3 ( F_7 ( V_7 , V_8 ) + F_8 ( V_6 ) ,
1 << F_9 ( V_6 ) ) ;
}
static inline void F_10 ( unsigned int V_6 )
{
F_3 ( F_7 ( V_7 , V_9 ) + F_8 ( V_6 ) ,
1 << F_9 ( V_6 ) ) ;
}
static inline void F_11 ( unsigned int V_6 , unsigned int V_10 )
{
F_5 ( F_7 ( V_7 , V_11 ) +
F_8 ( V_6 ) , 1 << F_9 ( V_6 ) ,
V_10 << F_9 ( V_6 ) ) ;
}
static inline void F_12 ( unsigned int V_6 , unsigned int V_12 )
{
F_5 ( F_7 ( V_7 , V_13 ) +
F_8 ( V_6 ) , 1 << F_9 ( V_6 ) ,
V_12 << F_9 ( V_6 ) ) ;
}
static inline void F_13 ( unsigned int V_6 , unsigned int V_14 )
{
F_5 ( F_7 ( V_7 , V_15 ) + F_8 ( V_6 ) ,
1 << F_9 ( V_6 ) ,
V_14 << F_9 ( V_6 ) ) ;
}
static inline void F_14 ( unsigned int V_6 , unsigned int V_16 )
{
F_3 ( F_7 ( V_7 , V_17 ) +
F_15 ( V_6 ) , V_18 | V_16 ) ;
}
static inline void F_16 ( unsigned int V_6 , unsigned int V_19 )
{
F_3 ( F_7 ( V_7 , V_20 ) +
F_17 ( V_6 , V_19 ) ,
F_18 ( V_19 ) ) ;
}
T_1 F_19 ( void )
{
unsigned int V_21 , V_22 , V_23 ;
do {
V_21 = F_1 ( F_7 ( V_7 , V_24 ) ) ;
V_23 = F_1 ( F_7 ( V_7 , V_25 ) ) ;
V_22 = F_1 ( F_7 ( V_7 , V_24 ) ) ;
} while ( V_22 != V_21 );
return ( ( ( T_1 ) V_21 ) << 32 ) + V_23 ;
}
unsigned int F_20 ( void )
{
unsigned int V_26 , V_27 ;
V_27 = F_1 ( F_7 ( V_7 , V_28 ) ) ;
V_26 = 32 + 4 * ( ( V_27 & V_29 ) >>
V_30 ) ;
return V_26 ;
}
void F_21 ( T_1 V_31 )
{
F_3 ( F_7 ( V_32 , V_33 ) ,
( int ) ( V_31 >> 32 ) ) ;
F_3 ( F_7 ( V_32 , V_34 ) ,
( int ) ( V_31 & 0xffffffff ) ) ;
}
void F_22 ( T_1 V_31 , int V_35 )
{
unsigned long V_36 ;
F_23 ( V_36 ) ;
F_3 ( F_7 ( V_32 , V_37 ) , V_35 ) ;
F_3 ( F_7 ( V_38 , V_33 ) ,
( int ) ( V_31 >> 32 ) ) ;
F_3 ( F_7 ( V_38 , V_34 ) ,
( int ) ( V_31 & 0xffffffff ) ) ;
F_24 ( V_36 ) ;
}
T_1 F_25 ( void )
{
unsigned int V_21 , V_23 ;
V_21 = F_1 ( F_7 ( V_32 , V_33 ) ) ;
V_23 = F_1 ( F_7 ( V_32 , V_34 ) ) ;
return ( ( ( T_1 ) V_21 ) << 32 ) + V_23 ;
}
void F_26 ( void )
{
T_2 V_39 ;
V_39 = F_1 ( F_7 ( V_7 , V_28 ) ) ;
V_39 &= ~ ( 1 << V_40 ) ;
F_3 ( F_7 ( V_7 , V_28 ) , V_39 ) ;
}
void F_27 ( void )
{
T_2 V_39 ;
V_39 = F_1 ( F_7 ( V_7 , V_28 ) ) ;
V_39 |= 1 << V_40 ;
F_3 ( F_7 ( V_7 , V_28 ) , V_39 ) ;
}
static bool F_28 ( int V_6 )
{
T_2 V_41 ;
if ( V_42 )
return true ;
V_41 = F_1 ( F_7 ( V_32 , V_43 ) ) ;
switch ( V_6 ) {
case V_44 :
return V_41 & V_45 ;
case V_46 :
return V_41 & V_47 ;
case V_48 :
return V_41 & V_49 ;
case V_50 :
case V_51 :
return V_41 & V_52 ;
default:
return true ;
}
}
static void F_29 ( int V_53 , int V_54 )
{
V_53 -= V_55 ;
F_3 ( F_7 ( V_32 , V_56 ) +
F_30 ( V_53 ) , V_54 ) ;
}
void F_31 ( unsigned int V_6 )
{
F_3 ( F_7 ( V_7 , V_57 ) , F_32 ( V_6 ) ) ;
}
int F_33 ( void )
{
if ( ! F_28 ( V_44 ) )
return V_58 + V_59 ;
return F_34 ( V_60 ,
F_35 ( V_44 ) ) ;
}
int F_36 ( void )
{
if ( ! F_28 ( V_46 ) ) {
if ( V_61 < 0 )
return - 1 ;
return V_58 + V_61 ;
}
return F_34 ( V_60 ,
F_35 ( V_46 ) ) ;
}
int F_37 ( void )
{
if ( ! F_28 ( V_48 ) ) {
if ( V_62 < 0 )
return - 1 ;
return V_58 + V_62 ;
}
switch ( F_38 () ) {
case V_63 :
case V_64 :
return - 1 ;
}
return F_34 ( V_60 ,
F_35 ( V_48 ) ) ;
}
static void F_39 ( bool V_65 )
{
unsigned int V_66 , V_6 , V_67 ;
unsigned long * V_68 ;
unsigned long V_69 , V_70 ;
F_40 ( V_71 , V_72 ) ;
F_40 ( V_73 , V_72 ) ;
V_68 = V_74 [ F_41 () ] . V_68 ;
V_69 = F_7 ( V_7 , V_75 ) ;
V_70 = F_7 ( V_7 , V_76 ) ;
for ( V_66 = 0 ; V_66 < F_42 ( V_77 ) ; V_66 ++ ) {
V_71 [ V_66 ] = F_1 ( V_69 ) ;
V_73 [ V_66 ] = F_1 ( V_70 ) ;
V_69 += 0x4 ;
V_70 += 0x4 ;
}
F_43 ( V_71 , V_71 , V_73 , V_77 ) ;
F_43 ( V_71 , V_71 , V_68 , V_77 ) ;
V_6 = F_44 ( V_71 , V_77 ) ;
while ( V_6 != V_77 ) {
V_67 = F_45 ( V_60 ,
F_46 ( V_6 ) ) ;
if ( V_65 )
F_47 ( V_67 ) ;
else
F_48 ( V_67 ) ;
F_49 ( V_71 , V_6 , 1 ) ;
V_6 = F_44 ( V_71 , V_77 ) ;
}
}
static void F_50 ( struct V_78 * V_79 )
{
F_6 ( F_51 ( V_79 -> V_80 ) ) ;
}
static void F_52 ( struct V_78 * V_79 )
{
F_10 ( F_51 ( V_79 -> V_80 ) ) ;
}
static void F_53 ( struct V_78 * V_79 )
{
unsigned int V_53 = F_51 ( V_79 -> V_80 ) ;
F_3 ( F_7 ( V_7 , V_57 ) , F_54 ( V_53 ) ) ;
}
static int F_55 ( struct V_78 * V_79 , unsigned int type )
{
unsigned int V_53 = F_51 ( V_79 -> V_80 ) ;
unsigned long V_36 ;
bool V_81 ;
F_56 ( & V_82 , V_36 ) ;
switch ( type & V_83 ) {
case V_84 :
F_11 ( V_53 , V_85 ) ;
F_12 ( V_53 , V_86 ) ;
F_13 ( V_53 , V_87 ) ;
V_81 = true ;
break;
case V_88 :
F_11 ( V_53 , V_89 ) ;
F_12 ( V_53 , V_86 ) ;
F_13 ( V_53 , V_87 ) ;
V_81 = true ;
break;
case V_90 :
F_12 ( V_53 , V_86 ) ;
F_13 ( V_53 , V_91 ) ;
V_81 = true ;
break;
case V_92 :
F_11 ( V_53 , V_85 ) ;
F_12 ( V_53 , V_93 ) ;
F_13 ( V_53 , V_87 ) ;
V_81 = false ;
break;
case V_94 :
default:
F_11 ( V_53 , V_89 ) ;
F_12 ( V_53 , V_93 ) ;
F_13 ( V_53 , V_87 ) ;
V_81 = false ;
break;
}
if ( V_81 ) {
F_57 ( V_79 -> V_53 ,
& V_95 ,
V_96 , NULL ) ;
} else {
F_57 ( V_79 -> V_53 ,
& V_97 ,
V_98 , NULL ) ;
}
F_58 ( & V_82 , V_36 ) ;
return 0 ;
}
static int F_59 ( struct V_78 * V_79 , const struct V_99 * V_99 ,
bool V_100 )
{
unsigned int V_53 = F_51 ( V_79 -> V_80 ) ;
T_3 V_101 = V_102 ;
unsigned long V_36 ;
int V_66 ;
F_60 ( & V_101 , V_99 , V_103 ) ;
if ( F_61 ( & V_101 ) )
return - V_104 ;
F_56 ( & V_82 , V_36 ) ;
F_16 ( V_53 , F_62 ( & V_101 ) ) ;
for ( V_66 = 0 ; V_66 < V_105 ; V_66 ++ )
F_63 ( V_53 , V_74 [ V_66 ] . V_68 ) ;
F_64 ( V_53 , V_74 [ F_62 ( & V_101 ) ] . V_68 ) ;
F_65 ( V_79 -> V_106 , V_99 ) ;
F_58 ( & V_82 , V_36 ) ;
return V_107 ;
}
static void F_66 ( bool V_65 )
{
unsigned long V_71 , V_108 ;
unsigned int V_6 , V_67 ;
V_71 = F_1 ( F_7 ( V_32 , V_109 ) ) ;
V_108 = F_1 ( F_7 ( V_32 , V_110 ) ) ;
F_43 ( & V_71 , & V_71 , & V_108 , V_111 ) ;
V_6 = F_44 ( & V_71 , V_111 ) ;
while ( V_6 != V_111 ) {
V_67 = F_45 ( V_60 ,
F_35 ( V_6 ) ) ;
if ( V_65 )
F_47 ( V_67 ) ;
else
F_48 ( V_67 ) ;
F_49 ( & V_71 , V_6 , 1 ) ;
V_6 = F_44 ( & V_71 , V_111 ) ;
}
}
static void F_67 ( struct V_78 * V_79 )
{
int V_6 = F_68 ( V_79 -> V_80 ) ;
F_3 ( F_7 ( V_32 , V_112 ) , 1 << V_6 ) ;
}
static void F_69 ( struct V_78 * V_79 )
{
int V_6 = F_68 ( V_79 -> V_80 ) ;
F_3 ( F_7 ( V_32 , V_113 ) , 1 << V_6 ) ;
}
static void F_70 ( struct V_78 * V_79 )
{
int V_6 = F_68 ( V_79 -> V_80 ) ;
int V_66 ;
unsigned long V_36 ;
F_56 ( & V_82 , V_36 ) ;
for ( V_66 = 0 ; V_66 < V_114 ; V_66 ++ ) {
F_3 ( F_7 ( V_32 , V_37 ) , V_66 ) ;
F_3 ( F_7 ( V_38 , V_112 ) , 1 << V_6 ) ;
}
F_58 ( & V_82 , V_36 ) ;
}
static void F_71 ( struct V_78 * V_79 )
{
int V_6 = F_68 ( V_79 -> V_80 ) ;
int V_66 ;
unsigned long V_36 ;
F_56 ( & V_82 , V_36 ) ;
for ( V_66 = 0 ; V_66 < V_114 ; V_66 ++ ) {
F_3 ( F_7 ( V_32 , V_37 ) , V_66 ) ;
F_3 ( F_7 ( V_38 , V_113 ) , 1 << V_6 ) ;
}
F_58 ( & V_82 , V_36 ) ;
}
static void F_72 ( void )
{
F_66 ( false ) ;
F_39 ( false ) ;
}
static void F_73 ( unsigned int V_53 , struct V_115 * V_116 )
{
F_66 ( true ) ;
F_39 ( true ) ;
}
unsigned int F_74 ( unsigned int V_35 )
{
return V_117 + V_35 ;
}
unsigned int F_75 ( unsigned int V_35 )
{
return V_118 + V_35 ;
}
static T_4 F_76 ( int V_53 , void * V_119 )
{
F_77 () ;
return V_120 ;
}
static T_4 F_78 ( int V_53 , void * V_119 )
{
F_79 () ;
return V_120 ;
}
static T_5 void F_80 ( unsigned int V_6 , int V_35 ,
struct V_121 * V_122 )
{
int V_67 = F_34 ( V_60 ,
F_46 ( V_6 ) ) ;
int V_66 ;
F_16 ( V_6 , V_35 ) ;
for ( V_66 = 0 ; V_66 < V_105 ; V_66 ++ )
F_63 ( V_6 , V_74 [ V_66 ] . V_68 ) ;
F_64 ( V_6 , V_74 [ V_35 ] . V_68 ) ;
F_81 ( V_67 , V_88 ) ;
F_82 ( V_67 , V_123 ) ;
F_83 ( V_67 , V_122 ) ;
}
static T_5 void F_84 ( void )
{
int V_66 ;
V_117 = V_77 - V_124 ;
V_118 = V_117 - V_124 ;
for ( V_66 = 0 ; V_66 < V_124 ; V_66 ++ ) {
F_80 ( V_118 + V_66 , V_66 , & V_125 ) ;
F_80 ( V_117 + V_66 , V_66 , & V_126 ) ;
}
}
static inline void F_84 ( void )
{
}
static void T_5 F_85 ( void )
{
unsigned int V_66 ;
V_127 = & F_29 ;
for ( V_66 = 0 ; V_66 < V_77 ; V_66 ++ ) {
F_11 ( V_66 , V_89 ) ;
F_12 ( V_66 , V_93 ) ;
F_6 ( V_66 ) ;
}
for ( V_66 = 0 ; V_66 < V_114 ; V_66 ++ ) {
unsigned int V_128 ;
F_3 ( F_7 ( V_32 , V_37 ) , V_66 ) ;
for ( V_128 = 0 ; V_128 < V_111 ; V_128 ++ ) {
if ( ! F_28 ( V_128 ) )
continue;
F_3 ( F_7 ( V_38 , V_112 ) , 1 << V_128 ) ;
}
}
}
static int F_86 ( struct V_129 * V_79 , unsigned int V_67 ,
T_6 V_130 )
{
int V_6 = F_68 ( V_130 ) ;
int V_131 = 0 ;
int V_66 ;
unsigned long V_36 ;
if ( ! F_28 ( V_6 ) )
return - V_132 ;
switch ( V_6 ) {
case V_44 :
case V_46 :
case V_48 :
F_87 ( V_67 ,
& V_133 ,
V_123 ) ;
break;
default:
F_87 ( V_67 ,
& V_134 ,
V_135 ) ;
F_88 ( V_67 ) ;
break;
}
F_56 ( & V_82 , V_36 ) ;
for ( V_66 = 0 ; V_66 < V_114 ; V_66 ++ ) {
T_2 V_3 = V_18 | V_136 ;
F_3 ( F_7 ( V_32 , V_37 ) , V_66 ) ;
switch ( V_6 ) {
case V_137 :
F_3 ( F_7 ( V_38 , V_138 ) , V_3 ) ;
break;
case V_139 :
F_3 ( F_7 ( V_38 , V_140 ) , V_3 ) ;
break;
case V_44 :
V_3 = V_18 | V_141 ;
F_3 ( F_7 ( V_38 , V_142 ) , V_3 ) ;
break;
case V_46 :
F_3 ( F_7 ( V_38 , V_143 ) , V_3 ) ;
break;
case V_50 :
F_3 ( F_7 ( V_38 , V_144 ) , V_3 ) ;
break;
case V_51 :
F_3 ( F_7 ( V_38 , V_145 ) , V_3 ) ;
break;
case V_48 :
F_3 ( F_7 ( V_38 , V_146 ) , V_3 ) ;
break;
default:
F_89 ( L_1 , V_6 ) ;
V_131 = - V_104 ;
break;
}
}
F_58 ( & V_82 , V_36 ) ;
return V_131 ;
}
static int F_90 ( struct V_129 * V_79 , unsigned int V_67 ,
T_6 V_130 )
{
int V_6 = F_51 ( V_130 ) ;
unsigned long V_36 ;
F_87 ( V_67 , & V_97 ,
V_98 ) ;
F_56 ( & V_82 , V_36 ) ;
F_14 ( V_6 , V_136 ) ;
F_16 ( V_6 , 0 ) ;
F_64 ( V_6 , V_74 [ 0 ] . V_68 ) ;
F_58 ( & V_82 , V_36 ) ;
return 0 ;
}
static int F_91 ( struct V_129 * V_79 , unsigned int V_67 ,
T_6 V_130 )
{
if ( F_68 ( V_130 ) < V_111 )
return F_86 ( V_79 , V_67 , V_130 ) ;
return F_90 ( V_79 , V_67 , V_130 ) ;
}
static int F_92 ( struct V_129 * V_79 , struct V_147 * V_148 ,
const T_2 * V_149 , unsigned int V_150 ,
T_6 * V_151 ,
unsigned int * V_152 )
{
if ( V_150 != 3 )
return - V_104 ;
if ( V_149 [ 0 ] == V_153 )
* V_151 = F_46 ( V_149 [ 1 ] ) ;
else if ( V_149 [ 0 ] == V_154 )
* V_151 = F_35 ( V_149 [ 1 ] ) ;
else
return - V_104 ;
* V_152 = V_149 [ 2 ] & V_83 ;
return 0 ;
}
static void T_5 F_93 ( unsigned long V_155 ,
unsigned long V_156 ,
unsigned int V_157 , unsigned int V_158 ,
struct V_147 * V_159 )
{
unsigned int V_39 ;
V_2 = F_94 ( V_155 , V_156 ) ;
V_39 = F_1 ( F_7 ( V_7 , V_28 ) ) ;
V_77 = ( V_39 & V_160 ) >>
V_161 ;
V_77 = ( ( V_77 + 1 ) * 8 ) ;
V_114 = ( V_39 & V_162 ) >>
V_163 ;
V_114 = V_114 + 1 ;
if ( V_42 ) {
V_136 = 0 ;
V_141 = V_136 ;
F_95 ( V_136 + V_55 ,
F_72 ) ;
} else {
V_136 = V_157 - V_164 ;
F_96 ( V_58 + V_157 ,
F_73 ) ;
if ( F_97 ( V_165 ) &&
F_28 ( V_44 ) ) {
V_141 = F_1 ( F_7 ( V_32 ,
V_142 ) ) &
V_166 ;
F_96 ( V_58 +
V_164 +
V_141 ,
F_73 ) ;
} else {
V_141 = V_136 ;
}
}
V_60 = F_98 ( V_159 , V_111 +
V_77 , V_158 ,
& V_167 , NULL ) ;
if ( ! V_60 )
F_99 ( L_2 ) ;
F_85 () ;
F_84 () ;
}
void T_5 F_100 ( unsigned long V_155 ,
unsigned long V_156 ,
unsigned int V_157 , unsigned int V_158 )
{
F_93 ( V_155 , V_156 , V_157 , V_158 , NULL ) ;
}
static int T_5 F_101 ( struct V_147 * V_159 ,
struct V_147 * V_168 )
{
struct V_169 V_170 ;
unsigned int V_157 , V_66 = 0 , V_171 = 0 ;
T_7 V_2 ;
T_8 V_172 ;
while ( ! F_102 ( V_159 , L_3 ,
V_66 ++ , & V_157 ) )
V_171 |= F_103 ( V_157 ) ;
for ( V_157 = 2 ; V_157 < 8 ; V_157 ++ ) {
if ( ! ( V_171 & F_103 ( V_157 ) ) )
break;
}
if ( V_157 == 8 ) {
F_89 ( L_4 ) ;
return - V_173 ;
}
if ( F_104 ( V_159 , 0 , & V_170 ) ) {
if ( F_105 () ) {
V_2 = F_106 () &
~ V_174 ;
V_172 = 0x20000 ;
} else {
F_89 ( L_5 ) ;
return - V_173 ;
}
} else {
V_2 = V_170 . V_175 ;
V_172 = F_107 ( & V_170 ) ;
}
if ( F_105 () )
F_108 ( V_2 | V_174 ) ;
V_176 = true ;
F_93 ( V_2 , V_172 , V_157 , 0 , V_159 ) ;
return 0 ;
}
