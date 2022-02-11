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
static bool F_26 ( int V_6 )
{
T_2 V_39 ;
if ( V_40 )
return true ;
V_39 = F_1 ( F_7 ( V_32 , V_41 ) ) ;
switch ( V_6 ) {
case V_42 :
return V_39 & V_43 ;
case V_44 :
return V_39 & V_45 ;
case V_46 :
return V_39 & V_47 ;
case V_48 :
case V_49 :
return V_39 & V_50 ;
default:
return true ;
}
}
static void F_27 ( int V_51 , int V_52 )
{
V_51 -= V_53 ;
F_3 ( F_7 ( V_32 , V_54 ) +
F_28 ( V_51 ) , V_52 ) ;
}
void F_29 ( unsigned int V_6 )
{
F_3 ( F_7 ( V_7 , V_55 ) , F_30 ( V_6 ) ) ;
}
int F_31 ( void )
{
if ( ! F_26 ( V_42 ) )
return V_56 + V_57 ;
return F_32 ( V_58 ,
F_33 ( V_42 ) ) ;
}
int F_34 ( void )
{
if ( ! F_26 ( V_44 ) ) {
if ( V_59 < 0 )
return - 1 ;
return V_56 + V_59 ;
}
return F_32 ( V_58 ,
F_33 ( V_44 ) ) ;
}
static void F_35 ( void )
{
unsigned int V_60 , V_6 , V_61 ;
unsigned long * V_62 ;
unsigned long V_63 , V_64 ;
F_36 ( V_65 , V_66 ) ;
F_36 ( V_67 , V_66 ) ;
V_62 = V_68 [ F_37 () ] . V_62 ;
V_63 = F_7 ( V_7 , V_69 ) ;
V_64 = F_7 ( V_7 , V_70 ) ;
for ( V_60 = 0 ; V_60 < F_38 ( V_71 ) ; V_60 ++ ) {
V_65 [ V_60 ] = F_1 ( V_63 ) ;
V_67 [ V_60 ] = F_1 ( V_64 ) ;
V_63 += 0x4 ;
V_64 += 0x4 ;
}
F_39 ( V_65 , V_65 , V_67 , V_71 ) ;
F_39 ( V_65 , V_65 , V_62 , V_71 ) ;
V_6 = F_40 ( V_65 , V_71 ) ;
while ( V_6 != V_71 ) {
V_61 = F_41 ( V_58 ,
F_42 ( V_6 ) ) ;
F_43 ( V_61 ) ;
F_44 ( V_65 , V_6 , 1 ) ;
V_6 = F_40 ( V_65 , V_71 ) ;
}
}
static void F_45 ( struct V_72 * V_73 )
{
F_6 ( F_46 ( V_73 -> V_74 ) ) ;
}
static void F_47 ( struct V_72 * V_73 )
{
F_10 ( F_46 ( V_73 -> V_74 ) ) ;
}
static void F_48 ( struct V_72 * V_73 )
{
unsigned int V_51 = F_46 ( V_73 -> V_74 ) ;
F_3 ( F_7 ( V_7 , V_55 ) , F_49 ( V_51 ) ) ;
}
static int F_50 ( struct V_72 * V_73 , unsigned int type )
{
unsigned int V_51 = F_46 ( V_73 -> V_74 ) ;
unsigned long V_36 ;
bool V_75 ;
F_51 ( & V_76 , V_36 ) ;
switch ( type & V_77 ) {
case V_78 :
F_11 ( V_51 , V_79 ) ;
F_12 ( V_51 , V_80 ) ;
F_13 ( V_51 , V_81 ) ;
V_75 = true ;
break;
case V_82 :
F_11 ( V_51 , V_83 ) ;
F_12 ( V_51 , V_80 ) ;
F_13 ( V_51 , V_81 ) ;
V_75 = true ;
break;
case V_84 :
F_12 ( V_51 , V_80 ) ;
F_13 ( V_51 , V_85 ) ;
V_75 = true ;
break;
case V_86 :
F_11 ( V_51 , V_79 ) ;
F_12 ( V_51 , V_87 ) ;
F_13 ( V_51 , V_81 ) ;
V_75 = false ;
break;
case V_88 :
default:
F_11 ( V_51 , V_83 ) ;
F_12 ( V_51 , V_87 ) ;
F_13 ( V_51 , V_81 ) ;
V_75 = false ;
break;
}
if ( V_75 ) {
F_52 ( V_73 -> V_51 ,
& V_89 ,
V_90 , NULL ) ;
} else {
F_52 ( V_73 -> V_51 ,
& V_91 ,
V_92 , NULL ) ;
}
F_53 ( & V_76 , V_36 ) ;
return 0 ;
}
static int F_54 ( struct V_72 * V_73 , const struct V_93 * V_93 ,
bool V_94 )
{
unsigned int V_51 = F_46 ( V_73 -> V_74 ) ;
T_3 V_95 = V_96 ;
unsigned long V_36 ;
int V_60 ;
F_55 ( & V_95 , V_93 , V_97 ) ;
if ( F_56 ( V_95 ) )
return - V_98 ;
F_51 ( & V_76 , V_36 ) ;
F_16 ( V_51 , F_57 ( V_95 ) ) ;
for ( V_60 = 0 ; V_60 < V_99 ; V_60 ++ )
F_58 ( V_51 , V_68 [ V_60 ] . V_62 ) ;
F_59 ( V_51 , V_68 [ F_57 ( V_95 ) ] . V_62 ) ;
F_60 ( V_73 -> V_100 , V_93 ) ;
F_53 ( & V_76 , V_36 ) ;
return V_101 ;
}
static void F_61 ( void )
{
unsigned long V_65 , V_102 ;
unsigned int V_6 , V_61 ;
V_65 = F_1 ( F_7 ( V_32 , V_103 ) ) ;
V_102 = F_1 ( F_7 ( V_32 , V_104 ) ) ;
F_39 ( & V_65 , & V_65 , & V_102 , V_105 ) ;
V_6 = F_40 ( & V_65 , V_105 ) ;
while ( V_6 != V_105 ) {
V_61 = F_41 ( V_58 ,
F_33 ( V_6 ) ) ;
F_43 ( V_61 ) ;
F_44 ( & V_65 , V_6 , 1 ) ;
V_6 = F_40 ( & V_65 , V_105 ) ;
}
}
static void F_62 ( struct V_72 * V_73 )
{
int V_6 = F_63 ( V_73 -> V_74 ) ;
F_3 ( F_7 ( V_32 , V_106 ) , 1 << V_6 ) ;
}
static void F_64 ( struct V_72 * V_73 )
{
int V_6 = F_63 ( V_73 -> V_74 ) ;
F_3 ( F_7 ( V_32 , V_107 ) , 1 << V_6 ) ;
}
static void F_65 ( struct V_72 * V_73 )
{
int V_6 = F_63 ( V_73 -> V_74 ) ;
int V_60 ;
unsigned long V_36 ;
F_51 ( & V_76 , V_36 ) ;
for ( V_60 = 0 ; V_60 < V_108 ; V_60 ++ ) {
F_3 ( F_7 ( V_32 , V_37 ) , V_60 ) ;
F_3 ( F_7 ( V_38 , V_106 ) , 1 << V_6 ) ;
}
F_53 ( & V_76 , V_36 ) ;
}
static void F_66 ( struct V_72 * V_73 )
{
int V_6 = F_63 ( V_73 -> V_74 ) ;
int V_60 ;
unsigned long V_36 ;
F_51 ( & V_76 , V_36 ) ;
for ( V_60 = 0 ; V_60 < V_108 ; V_60 ++ ) {
F_3 ( F_7 ( V_32 , V_37 ) , V_60 ) ;
F_3 ( F_7 ( V_38 , V_107 ) , 1 << V_6 ) ;
}
F_53 ( & V_76 , V_36 ) ;
}
static void F_67 ( void )
{
F_61 () ;
F_35 () ;
}
static void F_68 ( unsigned int V_51 , struct V_109 * V_110 )
{
F_67 () ;
}
unsigned int F_69 ( unsigned int V_35 )
{
return V_111 + V_35 ;
}
unsigned int F_70 ( unsigned int V_35 )
{
return V_112 + V_35 ;
}
static T_4 F_71 ( int V_51 , void * V_113 )
{
F_72 () ;
return V_114 ;
}
static T_4 F_73 ( int V_51 , void * V_113 )
{
F_74 () ;
return V_114 ;
}
static T_5 void F_75 ( unsigned int V_6 , int V_35 ,
struct V_115 * V_116 )
{
int V_61 = F_32 ( V_58 ,
F_42 ( V_6 ) ) ;
int V_60 ;
F_16 ( V_6 , V_35 ) ;
for ( V_60 = 0 ; V_60 < V_99 ; V_60 ++ )
F_58 ( V_6 , V_68 [ V_60 ] . V_62 ) ;
F_59 ( V_6 , V_68 [ V_35 ] . V_62 ) ;
F_76 ( V_61 , V_82 ) ;
F_77 ( V_61 , V_117 ) ;
F_78 ( V_61 , V_116 ) ;
}
static T_5 void F_79 ( void )
{
int V_60 ;
V_111 = V_71 - V_118 ;
V_112 = V_111 - V_118 ;
for ( V_60 = 0 ; V_60 < V_118 ; V_60 ++ ) {
F_75 ( V_112 + V_60 , V_60 , & V_119 ) ;
F_75 ( V_111 + V_60 , V_60 , & V_120 ) ;
}
}
static inline void F_79 ( void )
{
}
static void T_5 F_80 ( void )
{
unsigned int V_60 ;
V_121 = & F_27 ;
for ( V_60 = 0 ; V_60 < V_71 ; V_60 ++ ) {
F_11 ( V_60 , V_83 ) ;
F_12 ( V_60 , V_87 ) ;
F_6 ( V_60 ) ;
}
for ( V_60 = 0 ; V_60 < V_108 ; V_60 ++ ) {
unsigned int V_122 ;
F_3 ( F_7 ( V_32 , V_37 ) , V_60 ) ;
for ( V_122 = 0 ; V_122 < V_105 ; V_122 ++ ) {
if ( ! F_26 ( V_122 ) )
continue;
F_3 ( F_7 ( V_38 , V_106 ) , 1 << V_122 ) ;
}
}
}
static int F_81 ( struct V_123 * V_73 , unsigned int V_61 ,
T_6 V_124 )
{
int V_6 = F_63 ( V_124 ) ;
int V_125 = 0 ;
int V_60 ;
unsigned long V_36 ;
if ( ! F_26 ( V_6 ) )
return - V_126 ;
if ( V_6 != V_42 && V_6 != V_44 ) {
F_82 ( V_61 ,
& V_127 ,
V_128 ) ;
F_83 ( V_61 ) ;
} else {
F_82 ( V_61 ,
& V_129 ,
V_117 ) ;
}
F_51 ( & V_76 , V_36 ) ;
for ( V_60 = 0 ; V_60 < V_108 ; V_60 ++ ) {
T_2 V_3 = V_18 | V_130 ;
F_3 ( F_7 ( V_32 , V_37 ) , V_60 ) ;
switch ( V_6 ) {
case V_131 :
F_3 ( F_7 ( V_38 , V_132 ) , V_3 ) ;
break;
case V_133 :
F_3 ( F_7 ( V_38 , V_134 ) , V_3 ) ;
break;
case V_42 :
V_3 = V_18 | V_135 ;
F_3 ( F_7 ( V_38 , V_136 ) , V_3 ) ;
break;
case V_44 :
F_3 ( F_7 ( V_38 , V_137 ) , V_3 ) ;
break;
case V_48 :
F_3 ( F_7 ( V_38 , V_138 ) , V_3 ) ;
break;
case V_49 :
F_3 ( F_7 ( V_38 , V_139 ) , V_3 ) ;
break;
case V_46 :
F_3 ( F_7 ( V_38 , V_140 ) , V_3 ) ;
break;
default:
F_84 ( L_1 , V_6 ) ;
V_125 = - V_98 ;
break;
}
}
F_53 ( & V_76 , V_36 ) ;
return V_125 ;
}
static int F_85 ( struct V_123 * V_73 , unsigned int V_61 ,
T_6 V_124 )
{
int V_6 = F_46 ( V_124 ) ;
unsigned long V_36 ;
F_82 ( V_61 , & V_91 ,
V_92 ) ;
F_51 ( & V_76 , V_36 ) ;
F_14 ( V_6 , V_130 ) ;
F_16 ( V_6 , 0 ) ;
F_59 ( V_6 , V_68 [ 0 ] . V_62 ) ;
F_53 ( & V_76 , V_36 ) ;
return 0 ;
}
static int F_86 ( struct V_123 * V_73 , unsigned int V_61 ,
T_6 V_124 )
{
if ( F_63 ( V_124 ) < V_105 )
return F_81 ( V_73 , V_61 , V_124 ) ;
return F_85 ( V_73 , V_61 , V_124 ) ;
}
static int F_87 ( struct V_123 * V_73 , struct V_141 * V_142 ,
const T_2 * V_143 , unsigned int V_144 ,
T_6 * V_145 ,
unsigned int * V_146 )
{
if ( V_144 != 3 )
return - V_98 ;
if ( V_143 [ 0 ] == V_147 )
* V_145 = F_42 ( V_143 [ 1 ] ) ;
else if ( V_143 [ 0 ] == V_148 )
* V_145 = F_33 ( V_143 [ 1 ] ) ;
else
return - V_98 ;
* V_146 = V_143 [ 2 ] & V_77 ;
return 0 ;
}
static void T_5 F_88 ( unsigned long V_149 ,
unsigned long V_150 ,
unsigned int V_151 , unsigned int V_152 ,
struct V_141 * V_153 )
{
unsigned int V_154 ;
V_2 = F_89 ( V_149 , V_150 ) ;
V_154 = F_1 ( F_7 ( V_7 , V_28 ) ) ;
V_71 = ( V_154 & V_155 ) >>
V_156 ;
V_71 = ( ( V_71 + 1 ) * 8 ) ;
V_108 = ( V_154 & V_157 ) >>
V_158 ;
V_108 = V_108 + 1 ;
if ( V_40 ) {
V_130 = 0 ;
V_135 = V_130 ;
F_90 ( V_130 + V_53 ,
F_67 ) ;
} else {
V_130 = V_151 - V_159 ;
F_91 ( V_56 + V_151 ,
F_68 ) ;
if ( F_92 ( V_160 ) &&
F_26 ( V_42 ) ) {
V_135 = F_1 ( F_7 ( V_32 ,
V_136 ) ) &
V_161 ;
F_91 ( V_56 +
V_159 +
V_135 ,
F_68 ) ;
} else {
V_135 = V_130 ;
}
}
V_58 = F_93 ( V_153 , V_105 +
V_71 , V_152 ,
& V_162 , NULL ) ;
if ( ! V_58 )
F_94 ( L_2 ) ;
F_80 () ;
F_79 () ;
}
void T_5 F_95 ( unsigned long V_149 ,
unsigned long V_150 ,
unsigned int V_151 , unsigned int V_152 )
{
F_88 ( V_149 , V_150 , V_151 , V_152 , NULL ) ;
}
static int T_5 F_96 ( struct V_141 * V_153 ,
struct V_141 * V_163 )
{
struct V_164 V_165 ;
unsigned int V_151 , V_60 = 0 , V_166 = 0 ;
T_7 V_2 ;
T_8 V_167 ;
while ( ! F_97 ( V_153 , L_3 ,
V_60 ++ , & V_151 ) )
V_166 |= F_98 ( V_151 ) ;
for ( V_151 = 2 ; V_151 < 8 ; V_151 ++ ) {
if ( ! ( V_166 & F_98 ( V_151 ) ) )
break;
}
if ( V_151 == 8 ) {
F_84 ( L_4 ) ;
return - V_168 ;
}
if ( F_99 ( V_153 , 0 , & V_165 ) ) {
if ( F_100 () ) {
V_2 = F_101 () &
~ V_169 ;
V_167 = 0x20000 ;
} else {
F_84 ( L_5 ) ;
return - V_168 ;
}
} else {
V_2 = V_165 . V_170 ;
V_167 = F_102 ( & V_165 ) ;
}
if ( F_100 () )
F_103 ( V_2 | V_169 ) ;
V_171 = true ;
F_88 ( V_2 , V_167 , V_151 , 0 , V_153 ) ;
return 0 ;
}
