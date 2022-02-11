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
unsigned int F_27 ( void )
{
unsigned int V_51 ;
V_51 = F_1 ( F_7 ( V_32 , V_52 ) ) ;
return V_51 & V_53 ;
}
static void F_28 ( int V_54 , int V_55 )
{
V_54 -= V_56 ;
F_3 ( F_7 ( V_32 , V_57 ) +
F_29 ( V_54 ) , V_55 ) ;
}
void F_30 ( unsigned int V_6 )
{
F_3 ( F_7 ( V_7 , V_58 ) , F_31 ( V_6 ) ) ;
}
int F_32 ( void )
{
if ( ! F_26 ( V_42 ) )
return V_59 + V_60 ;
return F_33 ( V_61 ,
F_34 ( V_42 ) ) ;
}
int F_35 ( void )
{
if ( ! F_26 ( V_44 ) ) {
if ( V_62 < 0 )
return - 1 ;
return V_59 + V_62 ;
}
return F_33 ( V_61 ,
F_34 ( V_44 ) ) ;
}
static unsigned int F_36 ( void )
{
unsigned int V_63 ;
unsigned long * V_64 ;
unsigned long V_65 , V_66 ;
F_37 ( V_67 , V_68 ) ;
F_37 ( V_69 , V_68 ) ;
V_64 = V_70 [ F_38 () ] . V_64 ;
V_65 = F_7 ( V_7 , V_71 ) ;
V_66 = F_7 ( V_7 , V_72 ) ;
for ( V_63 = 0 ; V_63 < F_39 ( V_73 ) ; V_63 ++ ) {
V_67 [ V_63 ] = F_1 ( V_65 ) ;
V_69 [ V_63 ] = F_1 ( V_66 ) ;
V_65 += 0x4 ;
V_66 += 0x4 ;
}
F_40 ( V_67 , V_67 , V_69 , V_73 ) ;
F_40 ( V_67 , V_67 , V_64 , V_73 ) ;
return F_41 ( V_67 , V_73 ) ;
}
static void F_42 ( struct V_74 * V_75 )
{
F_6 ( F_43 ( V_75 -> V_76 ) ) ;
}
static void F_44 ( struct V_74 * V_75 )
{
F_10 ( F_43 ( V_75 -> V_76 ) ) ;
}
static void F_45 ( struct V_74 * V_75 )
{
unsigned int V_54 = F_43 ( V_75 -> V_76 ) ;
F_3 ( F_7 ( V_7 , V_58 ) , F_46 ( V_54 ) ) ;
}
static int F_47 ( struct V_74 * V_75 , unsigned int type )
{
unsigned int V_54 = F_43 ( V_75 -> V_76 ) ;
unsigned long V_36 ;
bool V_77 ;
F_48 ( & V_78 , V_36 ) ;
switch ( type & V_79 ) {
case V_80 :
F_11 ( V_54 , V_81 ) ;
F_12 ( V_54 , V_82 ) ;
F_13 ( V_54 , V_83 ) ;
V_77 = true ;
break;
case V_84 :
F_11 ( V_54 , V_85 ) ;
F_12 ( V_54 , V_82 ) ;
F_13 ( V_54 , V_83 ) ;
V_77 = true ;
break;
case V_86 :
F_12 ( V_54 , V_82 ) ;
F_13 ( V_54 , V_87 ) ;
V_77 = true ;
break;
case V_88 :
F_11 ( V_54 , V_81 ) ;
F_12 ( V_54 , V_89 ) ;
F_13 ( V_54 , V_83 ) ;
V_77 = false ;
break;
case V_90 :
default:
F_11 ( V_54 , V_85 ) ;
F_12 ( V_54 , V_89 ) ;
F_13 ( V_54 , V_83 ) ;
V_77 = false ;
break;
}
if ( V_77 ) {
F_49 ( V_75 -> V_54 ,
& V_91 ,
V_92 , NULL ) ;
} else {
F_49 ( V_75 -> V_54 ,
& V_93 ,
V_94 , NULL ) ;
}
F_50 ( & V_78 , V_36 ) ;
return 0 ;
}
static int F_51 ( struct V_74 * V_75 , const struct V_95 * V_95 ,
bool V_96 )
{
unsigned int V_54 = F_43 ( V_75 -> V_76 ) ;
T_3 V_97 = V_98 ;
unsigned long V_36 ;
int V_63 ;
F_52 ( & V_97 , V_95 , V_99 ) ;
if ( F_53 ( V_97 ) )
return - V_100 ;
F_48 ( & V_78 , V_36 ) ;
F_16 ( V_54 , F_54 ( V_97 ) ) ;
for ( V_63 = 0 ; V_63 < V_101 ; V_63 ++ )
F_55 ( V_54 , V_70 [ V_63 ] . V_64 ) ;
F_56 ( V_54 , V_70 [ F_54 ( V_97 ) ] . V_64 ) ;
F_57 ( V_75 -> V_102 , V_95 ) ;
F_50 ( & V_78 , V_36 ) ;
return V_103 ;
}
static unsigned int F_58 ( void )
{
unsigned long V_67 , V_104 ;
V_67 = F_1 ( F_7 ( V_32 , V_52 ) ) ;
V_104 = F_1 ( F_7 ( V_32 , V_105 ) ) ;
F_40 ( & V_67 , & V_67 , & V_104 , V_106 ) ;
return F_41 ( & V_67 , V_106 ) ;
}
static void F_59 ( struct V_74 * V_75 )
{
int V_6 = F_60 ( V_75 -> V_76 ) ;
F_3 ( F_7 ( V_32 , V_107 ) , 1 << V_6 ) ;
}
static void F_61 ( struct V_74 * V_75 )
{
int V_6 = F_60 ( V_75 -> V_76 ) ;
F_3 ( F_7 ( V_32 , V_108 ) , 1 << V_6 ) ;
}
static void F_62 ( struct V_74 * V_75 )
{
int V_6 = F_60 ( V_75 -> V_76 ) ;
int V_63 ;
unsigned long V_36 ;
F_48 ( & V_78 , V_36 ) ;
for ( V_63 = 0 ; V_63 < V_109 ; V_63 ++ ) {
F_3 ( F_7 ( V_32 , V_37 ) , V_63 ) ;
F_3 ( F_7 ( V_38 , V_107 ) , 1 << V_6 ) ;
}
F_50 ( & V_78 , V_36 ) ;
}
static void F_63 ( struct V_74 * V_75 )
{
int V_6 = F_60 ( V_75 -> V_76 ) ;
int V_63 ;
unsigned long V_36 ;
F_48 ( & V_78 , V_36 ) ;
for ( V_63 = 0 ; V_63 < V_109 ; V_63 ++ ) {
F_3 ( F_7 ( V_32 , V_37 ) , V_63 ) ;
F_3 ( F_7 ( V_38 , V_108 ) , 1 << V_6 ) ;
}
F_50 ( & V_78 , V_36 ) ;
}
static void F_64 ( void )
{
unsigned int V_6 , V_110 ;
while ( ( V_6 = F_58 () ) != V_106 ) {
V_110 = F_65 ( V_61 ,
F_34 ( V_6 ) ) ;
F_66 ( V_110 ) ;
}
while ( ( V_6 = F_36 () ) != V_73 ) {
V_110 = F_65 ( V_61 ,
F_67 ( V_6 ) ) ;
F_66 ( V_110 ) ;
}
}
static void F_68 ( unsigned int V_54 , struct V_111 * V_112 )
{
F_64 () ;
}
unsigned int F_69 ( unsigned int V_35 )
{
return V_113 + V_35 ;
}
unsigned int F_70 ( unsigned int V_35 )
{
return V_114 + V_35 ;
}
static T_4 F_71 ( int V_54 , void * V_115 )
{
F_72 () ;
return V_116 ;
}
static T_4 F_73 ( int V_54 , void * V_115 )
{
F_74 () ;
return V_116 ;
}
static T_5 void F_75 ( unsigned int V_6 , int V_35 ,
struct V_117 * V_118 )
{
int V_110 = F_33 ( V_61 ,
F_67 ( V_6 ) ) ;
int V_63 ;
F_16 ( V_6 , V_35 ) ;
for ( V_63 = 0 ; V_63 < V_101 ; V_63 ++ )
F_55 ( V_6 , V_70 [ V_63 ] . V_64 ) ;
F_56 ( V_6 , V_70 [ V_35 ] . V_64 ) ;
F_76 ( V_110 , V_84 ) ;
F_77 ( V_110 , V_119 ) ;
F_78 ( V_110 , V_118 ) ;
}
static T_5 void F_79 ( void )
{
int V_63 ;
V_113 = V_73 - V_120 ;
V_114 = V_113 - V_120 ;
for ( V_63 = 0 ; V_63 < V_120 ; V_63 ++ ) {
F_75 ( V_114 + V_63 , V_63 , & V_121 ) ;
F_75 ( V_113 + V_63 , V_63 , & V_122 ) ;
}
}
static inline void F_79 ( void )
{
}
static void T_5 F_80 ( void )
{
unsigned int V_63 ;
V_123 = & F_28 ;
for ( V_63 = 0 ; V_63 < V_73 ; V_63 ++ ) {
F_11 ( V_63 , V_85 ) ;
F_12 ( V_63 , V_89 ) ;
F_6 ( V_63 ) ;
}
for ( V_63 = 0 ; V_63 < V_109 ; V_63 ++ ) {
unsigned int V_124 ;
F_3 ( F_7 ( V_32 , V_37 ) , V_63 ) ;
for ( V_124 = 0 ; V_124 < V_106 ; V_124 ++ ) {
if ( ! F_26 ( V_124 ) )
continue;
F_3 ( F_7 ( V_38 , V_107 ) , 1 << V_124 ) ;
}
}
}
static int F_81 ( struct V_125 * V_75 , unsigned int V_110 ,
T_6 V_126 )
{
int V_6 = F_60 ( V_126 ) ;
int V_127 = 0 ;
int V_63 ;
unsigned long V_36 ;
if ( ! F_26 ( V_6 ) )
return - V_128 ;
if ( V_6 != V_42 && V_6 != V_44 ) {
F_82 ( V_110 ,
& V_129 ,
V_130 ) ;
F_83 ( V_110 ) ;
} else {
F_82 ( V_110 ,
& V_131 ,
V_119 ) ;
}
F_48 ( & V_78 , V_36 ) ;
for ( V_63 = 0 ; V_63 < V_109 ; V_63 ++ ) {
T_2 V_3 = V_18 | V_132 ;
F_3 ( F_7 ( V_32 , V_37 ) , V_63 ) ;
switch ( V_6 ) {
case V_133 :
F_3 ( F_7 ( V_38 , V_134 ) , V_3 ) ;
break;
case V_135 :
F_3 ( F_7 ( V_38 , V_136 ) , V_3 ) ;
break;
case V_42 :
V_3 = V_18 | V_137 ;
F_3 ( F_7 ( V_38 , V_138 ) , V_3 ) ;
break;
case V_44 :
F_3 ( F_7 ( V_38 , V_139 ) , V_3 ) ;
break;
case V_48 :
F_3 ( F_7 ( V_38 , V_140 ) , V_3 ) ;
break;
case V_49 :
F_3 ( F_7 ( V_38 , V_141 ) , V_3 ) ;
break;
case V_46 :
F_3 ( F_7 ( V_38 , V_142 ) , V_3 ) ;
break;
default:
F_84 ( L_1 , V_6 ) ;
V_127 = - V_100 ;
break;
}
}
F_50 ( & V_78 , V_36 ) ;
return V_127 ;
}
static int F_85 ( struct V_125 * V_75 , unsigned int V_110 ,
T_6 V_126 )
{
int V_6 = F_43 ( V_126 ) ;
unsigned long V_36 ;
F_82 ( V_110 , & V_93 ,
V_94 ) ;
F_48 ( & V_78 , V_36 ) ;
F_14 ( V_6 , V_132 ) ;
F_16 ( V_6 , 0 ) ;
F_56 ( V_6 , V_70 [ 0 ] . V_64 ) ;
F_50 ( & V_78 , V_36 ) ;
return 0 ;
}
static int F_86 ( struct V_125 * V_75 , unsigned int V_110 ,
T_6 V_126 )
{
if ( F_60 ( V_126 ) < V_106 )
return F_81 ( V_75 , V_110 , V_126 ) ;
return F_85 ( V_75 , V_110 , V_126 ) ;
}
static int F_87 ( struct V_125 * V_75 , struct V_143 * V_144 ,
const T_2 * V_145 , unsigned int V_146 ,
T_6 * V_147 ,
unsigned int * V_148 )
{
if ( V_146 != 3 )
return - V_100 ;
if ( V_145 [ 0 ] == V_149 )
* V_147 = F_67 ( V_145 [ 1 ] ) ;
else if ( V_145 [ 0 ] == V_150 )
* V_147 = F_34 ( V_145 [ 1 ] ) ;
else
return - V_100 ;
* V_148 = V_145 [ 2 ] & V_79 ;
return 0 ;
}
static void T_5 F_88 ( unsigned long V_151 ,
unsigned long V_152 ,
unsigned int V_153 , unsigned int V_154 ,
struct V_143 * V_155 )
{
unsigned int V_156 ;
V_2 = F_89 ( V_151 , V_152 ) ;
V_156 = F_1 ( F_7 ( V_7 , V_28 ) ) ;
V_73 = ( V_156 & V_157 ) >>
V_158 ;
V_73 = ( ( V_73 + 1 ) * 8 ) ;
V_109 = ( V_156 & V_159 ) >>
V_160 ;
V_109 = V_109 + 1 ;
if ( V_40 ) {
V_132 = 0 ;
V_137 = V_132 ;
F_90 ( V_132 + V_56 ,
F_64 ) ;
} else {
V_132 = V_153 - V_161 ;
F_91 ( V_59 + V_153 ,
F_68 ) ;
if ( F_92 ( V_162 ) &&
F_26 ( V_42 ) ) {
V_137 = F_1 ( F_7 ( V_32 ,
V_138 ) ) &
V_163 ;
F_91 ( V_59 +
V_161 +
V_137 ,
F_68 ) ;
} else {
V_137 = V_132 ;
}
}
V_61 = F_93 ( V_155 , V_106 +
V_73 , V_154 ,
& V_164 , NULL ) ;
if ( ! V_61 )
F_94 ( L_2 ) ;
F_80 () ;
F_79 () ;
}
void T_5 F_95 ( unsigned long V_151 ,
unsigned long V_152 ,
unsigned int V_153 , unsigned int V_154 )
{
F_88 ( V_151 , V_152 , V_153 , V_154 , NULL ) ;
}
static int T_5 F_96 ( struct V_143 * V_155 ,
struct V_143 * V_165 )
{
struct V_166 V_167 ;
unsigned int V_153 , V_63 = 0 , V_168 = 0 ;
T_7 V_2 ;
T_8 V_169 ;
while ( ! F_97 ( V_155 , L_3 ,
V_63 ++ , & V_153 ) )
V_168 |= F_98 ( V_153 ) ;
for ( V_153 = 2 ; V_153 < 8 ; V_153 ++ ) {
if ( ! ( V_168 & F_98 ( V_153 ) ) )
break;
}
if ( V_153 == 8 ) {
F_84 ( L_4 ) ;
return - V_170 ;
}
if ( F_99 ( V_155 , 0 , & V_167 ) ) {
if ( F_100 () ) {
V_2 = F_101 () &
~ V_171 ;
V_169 = 0x20000 ;
} else {
F_84 ( L_5 ) ;
return - V_170 ;
}
} else {
V_2 = V_167 . V_172 ;
V_169 = F_102 ( & V_167 ) ;
}
if ( F_100 () )
F_103 ( V_2 | V_171 ) ;
V_173 = true ;
F_88 ( V_2 , V_169 , V_153 , 0 , V_155 ) ;
return 0 ;
}
