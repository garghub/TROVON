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
return F_34 ( V_60 ,
F_35 ( V_48 ) ) ;
}
static void F_38 ( bool V_63 )
{
unsigned int V_64 , V_6 , V_65 ;
unsigned long * V_66 ;
unsigned long V_67 , V_68 ;
F_39 ( V_69 , V_70 ) ;
F_39 ( V_71 , V_70 ) ;
V_66 = V_72 [ F_40 () ] . V_66 ;
V_67 = F_7 ( V_7 , V_73 ) ;
V_68 = F_7 ( V_7 , V_74 ) ;
for ( V_64 = 0 ; V_64 < F_41 ( V_75 ) ; V_64 ++ ) {
V_69 [ V_64 ] = F_1 ( V_67 ) ;
V_71 [ V_64 ] = F_1 ( V_68 ) ;
V_67 += 0x4 ;
V_68 += 0x4 ;
}
F_42 ( V_69 , V_69 , V_71 , V_75 ) ;
F_42 ( V_69 , V_69 , V_66 , V_75 ) ;
V_6 = F_43 ( V_69 , V_75 ) ;
while ( V_6 != V_75 ) {
V_65 = F_44 ( V_60 ,
F_45 ( V_6 ) ) ;
if ( V_63 )
F_46 ( V_65 ) ;
else
F_47 ( V_65 ) ;
F_48 ( V_69 , V_6 , 1 ) ;
V_6 = F_43 ( V_69 , V_75 ) ;
}
}
static void F_49 ( struct V_76 * V_77 )
{
F_6 ( F_50 ( V_77 -> V_78 ) ) ;
}
static void F_51 ( struct V_76 * V_77 )
{
F_10 ( F_50 ( V_77 -> V_78 ) ) ;
}
static void F_52 ( struct V_76 * V_77 )
{
unsigned int V_53 = F_50 ( V_77 -> V_78 ) ;
F_3 ( F_7 ( V_7 , V_57 ) , F_53 ( V_53 ) ) ;
}
static int F_54 ( struct V_76 * V_77 , unsigned int type )
{
unsigned int V_53 = F_50 ( V_77 -> V_78 ) ;
unsigned long V_36 ;
bool V_79 ;
F_55 ( & V_80 , V_36 ) ;
switch ( type & V_81 ) {
case V_82 :
F_11 ( V_53 , V_83 ) ;
F_12 ( V_53 , V_84 ) ;
F_13 ( V_53 , V_85 ) ;
V_79 = true ;
break;
case V_86 :
F_11 ( V_53 , V_87 ) ;
F_12 ( V_53 , V_84 ) ;
F_13 ( V_53 , V_85 ) ;
V_79 = true ;
break;
case V_88 :
F_12 ( V_53 , V_84 ) ;
F_13 ( V_53 , V_89 ) ;
V_79 = true ;
break;
case V_90 :
F_11 ( V_53 , V_83 ) ;
F_12 ( V_53 , V_91 ) ;
F_13 ( V_53 , V_85 ) ;
V_79 = false ;
break;
case V_92 :
default:
F_11 ( V_53 , V_87 ) ;
F_12 ( V_53 , V_91 ) ;
F_13 ( V_53 , V_85 ) ;
V_79 = false ;
break;
}
if ( V_79 ) {
F_56 ( V_77 -> V_53 ,
& V_93 ,
V_94 , NULL ) ;
} else {
F_56 ( V_77 -> V_53 ,
& V_95 ,
V_96 , NULL ) ;
}
F_57 ( & V_80 , V_36 ) ;
return 0 ;
}
static int F_58 ( struct V_76 * V_77 , const struct V_97 * V_97 ,
bool V_98 )
{
unsigned int V_53 = F_50 ( V_77 -> V_78 ) ;
T_3 V_99 = V_100 ;
unsigned long V_36 ;
int V_64 ;
F_59 ( & V_99 , V_97 , V_101 ) ;
if ( F_60 ( & V_99 ) )
return - V_102 ;
F_55 ( & V_80 , V_36 ) ;
F_16 ( V_53 , F_61 ( & V_99 ) ) ;
for ( V_64 = 0 ; V_64 < V_103 ; V_64 ++ )
F_62 ( V_53 , V_72 [ V_64 ] . V_66 ) ;
F_63 ( V_53 , V_72 [ F_61 ( & V_99 ) ] . V_66 ) ;
F_64 ( V_77 -> V_104 , V_97 ) ;
F_57 ( & V_80 , V_36 ) ;
return V_105 ;
}
static void F_65 ( bool V_63 )
{
unsigned long V_69 , V_106 ;
unsigned int V_6 , V_65 ;
V_69 = F_1 ( F_7 ( V_32 , V_107 ) ) ;
V_106 = F_1 ( F_7 ( V_32 , V_108 ) ) ;
F_42 ( & V_69 , & V_69 , & V_106 , V_109 ) ;
V_6 = F_43 ( & V_69 , V_109 ) ;
while ( V_6 != V_109 ) {
V_65 = F_44 ( V_60 ,
F_35 ( V_6 ) ) ;
if ( V_63 )
F_46 ( V_65 ) ;
else
F_47 ( V_65 ) ;
F_48 ( & V_69 , V_6 , 1 ) ;
V_6 = F_43 ( & V_69 , V_109 ) ;
}
}
static void F_66 ( struct V_76 * V_77 )
{
int V_6 = F_67 ( V_77 -> V_78 ) ;
F_3 ( F_7 ( V_32 , V_110 ) , 1 << V_6 ) ;
}
static void F_68 ( struct V_76 * V_77 )
{
int V_6 = F_67 ( V_77 -> V_78 ) ;
F_3 ( F_7 ( V_32 , V_111 ) , 1 << V_6 ) ;
}
static void F_69 ( struct V_76 * V_77 )
{
int V_6 = F_67 ( V_77 -> V_78 ) ;
int V_64 ;
unsigned long V_36 ;
F_55 ( & V_80 , V_36 ) ;
for ( V_64 = 0 ; V_64 < V_112 ; V_64 ++ ) {
F_3 ( F_7 ( V_32 , V_37 ) , V_64 ) ;
F_3 ( F_7 ( V_38 , V_110 ) , 1 << V_6 ) ;
}
F_57 ( & V_80 , V_36 ) ;
}
static void F_70 ( struct V_76 * V_77 )
{
int V_6 = F_67 ( V_77 -> V_78 ) ;
int V_64 ;
unsigned long V_36 ;
F_55 ( & V_80 , V_36 ) ;
for ( V_64 = 0 ; V_64 < V_112 ; V_64 ++ ) {
F_3 ( F_7 ( V_32 , V_37 ) , V_64 ) ;
F_3 ( F_7 ( V_38 , V_111 ) , 1 << V_6 ) ;
}
F_57 ( & V_80 , V_36 ) ;
}
static void F_71 ( void )
{
F_65 ( false ) ;
F_38 ( false ) ;
}
static void F_72 ( unsigned int V_53 , struct V_113 * V_114 )
{
F_65 ( true ) ;
F_38 ( true ) ;
}
unsigned int F_73 ( unsigned int V_35 )
{
return V_115 + V_35 ;
}
unsigned int F_74 ( unsigned int V_35 )
{
return V_116 + V_35 ;
}
static T_4 F_75 ( int V_53 , void * V_117 )
{
F_76 () ;
return V_118 ;
}
static T_4 F_77 ( int V_53 , void * V_117 )
{
F_78 () ;
return V_118 ;
}
static T_5 void F_79 ( unsigned int V_6 , int V_35 ,
struct V_119 * V_120 )
{
int V_65 = F_34 ( V_60 ,
F_45 ( V_6 ) ) ;
int V_64 ;
F_16 ( V_6 , V_35 ) ;
for ( V_64 = 0 ; V_64 < V_103 ; V_64 ++ )
F_62 ( V_6 , V_72 [ V_64 ] . V_66 ) ;
F_63 ( V_6 , V_72 [ V_35 ] . V_66 ) ;
F_80 ( V_65 , V_86 ) ;
F_81 ( V_65 , V_121 ) ;
F_82 ( V_65 , V_120 ) ;
}
static T_5 void F_83 ( void )
{
int V_64 ;
V_115 = V_75 - V_122 ;
V_116 = V_115 - V_122 ;
for ( V_64 = 0 ; V_64 < V_122 ; V_64 ++ ) {
F_79 ( V_116 + V_64 , V_64 , & V_123 ) ;
F_79 ( V_115 + V_64 , V_64 , & V_124 ) ;
}
}
static inline void F_83 ( void )
{
}
static void T_5 F_84 ( void )
{
unsigned int V_64 ;
V_125 = & F_29 ;
for ( V_64 = 0 ; V_64 < V_75 ; V_64 ++ ) {
F_11 ( V_64 , V_87 ) ;
F_12 ( V_64 , V_91 ) ;
F_6 ( V_64 ) ;
}
for ( V_64 = 0 ; V_64 < V_112 ; V_64 ++ ) {
unsigned int V_126 ;
F_3 ( F_7 ( V_32 , V_37 ) , V_64 ) ;
for ( V_126 = 0 ; V_126 < V_109 ; V_126 ++ ) {
if ( ! F_28 ( V_126 ) )
continue;
F_3 ( F_7 ( V_38 , V_110 ) , 1 << V_126 ) ;
}
}
}
static int F_85 ( struct V_127 * V_77 , unsigned int V_65 ,
T_6 V_128 )
{
int V_6 = F_67 ( V_128 ) ;
int V_129 = 0 ;
int V_64 ;
unsigned long V_36 ;
if ( ! F_28 ( V_6 ) )
return - V_130 ;
switch ( V_6 ) {
case V_44 :
case V_46 :
case V_48 :
F_86 ( V_65 ,
& V_131 ,
V_121 ) ;
break;
default:
F_86 ( V_65 ,
& V_132 ,
V_133 ) ;
F_87 ( V_65 ) ;
break;
}
F_55 ( & V_80 , V_36 ) ;
for ( V_64 = 0 ; V_64 < V_112 ; V_64 ++ ) {
T_2 V_3 = V_18 | V_134 ;
F_3 ( F_7 ( V_32 , V_37 ) , V_64 ) ;
switch ( V_6 ) {
case V_135 :
F_3 ( F_7 ( V_38 , V_136 ) , V_3 ) ;
break;
case V_137 :
F_3 ( F_7 ( V_38 , V_138 ) , V_3 ) ;
break;
case V_44 :
V_3 = V_18 | V_139 ;
F_3 ( F_7 ( V_38 , V_140 ) , V_3 ) ;
break;
case V_46 :
F_3 ( F_7 ( V_38 , V_141 ) , V_3 ) ;
break;
case V_50 :
F_3 ( F_7 ( V_38 , V_142 ) , V_3 ) ;
break;
case V_51 :
F_3 ( F_7 ( V_38 , V_143 ) , V_3 ) ;
break;
case V_48 :
F_3 ( F_7 ( V_38 , V_144 ) , V_3 ) ;
break;
default:
F_88 ( L_1 , V_6 ) ;
V_129 = - V_102 ;
break;
}
}
F_57 ( & V_80 , V_36 ) ;
return V_129 ;
}
static int F_89 ( struct V_127 * V_77 , unsigned int V_65 ,
T_6 V_128 )
{
int V_6 = F_50 ( V_128 ) ;
unsigned long V_36 ;
F_86 ( V_65 , & V_95 ,
V_96 ) ;
F_55 ( & V_80 , V_36 ) ;
F_14 ( V_6 , V_134 ) ;
F_16 ( V_6 , 0 ) ;
F_63 ( V_6 , V_72 [ 0 ] . V_66 ) ;
F_57 ( & V_80 , V_36 ) ;
return 0 ;
}
static int F_90 ( struct V_127 * V_77 , unsigned int V_65 ,
T_6 V_128 )
{
if ( F_67 ( V_128 ) < V_109 )
return F_85 ( V_77 , V_65 , V_128 ) ;
return F_89 ( V_77 , V_65 , V_128 ) ;
}
static int F_91 ( struct V_127 * V_77 , struct V_145 * V_146 ,
const T_2 * V_147 , unsigned int V_148 ,
T_6 * V_149 ,
unsigned int * V_150 )
{
if ( V_148 != 3 )
return - V_102 ;
if ( V_147 [ 0 ] == V_151 )
* V_149 = F_45 ( V_147 [ 1 ] ) ;
else if ( V_147 [ 0 ] == V_152 )
* V_149 = F_35 ( V_147 [ 1 ] ) ;
else
return - V_102 ;
* V_150 = V_147 [ 2 ] & V_81 ;
return 0 ;
}
static void T_5 F_92 ( unsigned long V_153 ,
unsigned long V_154 ,
unsigned int V_155 , unsigned int V_156 ,
struct V_145 * V_157 )
{
unsigned int V_39 ;
V_2 = F_93 ( V_153 , V_154 ) ;
V_39 = F_1 ( F_7 ( V_7 , V_28 ) ) ;
V_75 = ( V_39 & V_158 ) >>
V_159 ;
V_75 = ( ( V_75 + 1 ) * 8 ) ;
V_112 = ( V_39 & V_160 ) >>
V_161 ;
V_112 = V_112 + 1 ;
if ( V_42 ) {
V_134 = 0 ;
V_139 = V_134 ;
F_94 ( V_134 + V_55 ,
F_71 ) ;
} else {
V_134 = V_155 - V_162 ;
F_95 ( V_58 + V_155 ,
F_72 ) ;
if ( F_96 ( V_163 ) &&
F_28 ( V_44 ) ) {
V_139 = F_1 ( F_7 ( V_32 ,
V_140 ) ) &
V_164 ;
F_95 ( V_58 +
V_162 +
V_139 ,
F_72 ) ;
} else {
V_139 = V_134 ;
}
}
V_60 = F_97 ( V_157 , V_109 +
V_75 , V_156 ,
& V_165 , NULL ) ;
if ( ! V_60 )
F_98 ( L_2 ) ;
F_84 () ;
F_83 () ;
}
void T_5 F_99 ( unsigned long V_153 ,
unsigned long V_154 ,
unsigned int V_155 , unsigned int V_156 )
{
F_92 ( V_153 , V_154 , V_155 , V_156 , NULL ) ;
}
static int T_5 F_100 ( struct V_145 * V_157 ,
struct V_145 * V_166 )
{
struct V_167 V_168 ;
unsigned int V_155 , V_64 = 0 , V_169 = 0 ;
T_7 V_2 ;
T_8 V_170 ;
while ( ! F_101 ( V_157 , L_3 ,
V_64 ++ , & V_155 ) )
V_169 |= F_102 ( V_155 ) ;
for ( V_155 = 2 ; V_155 < 8 ; V_155 ++ ) {
if ( ! ( V_169 & F_102 ( V_155 ) ) )
break;
}
if ( V_155 == 8 ) {
F_88 ( L_4 ) ;
return - V_171 ;
}
if ( F_103 ( V_157 , 0 , & V_168 ) ) {
if ( F_104 () ) {
V_2 = F_105 () &
~ V_172 ;
V_170 = 0x20000 ;
} else {
F_88 ( L_5 ) ;
return - V_171 ;
}
} else {
V_2 = V_168 . V_173 ;
V_170 = F_106 ( & V_168 ) ;
}
if ( F_104 () )
F_107 ( V_2 | V_172 ) ;
V_174 = true ;
F_92 ( V_2 , V_170 , V_155 , 0 , V_157 ) ;
return 0 ;
}
