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
static void F_44 ( bool V_66 )
{
unsigned int V_67 , V_7 , V_68 , V_69 = V_3 ? 8 : 4 ;
unsigned long * V_70 ;
unsigned long V_71 , V_72 ;
F_45 ( V_73 , V_74 ) ;
F_45 ( V_75 , V_74 ) ;
V_70 = V_76 [ F_46 () ] . V_70 ;
V_71 = F_13 ( V_8 , V_77 ) ;
V_72 = F_13 ( V_8 , V_78 ) ;
for ( V_67 = 0 ; V_67 < F_47 ( V_79 ) ; V_67 ++ ) {
V_73 [ V_67 ] = F_5 ( V_71 ) ;
V_75 [ V_67 ] = F_5 ( V_72 ) ;
V_71 += V_69 ;
V_72 += V_69 ;
if ( ! F_48 ( V_80 ) || V_3 )
continue;
V_73 [ V_67 ] |= ( T_2 ) F_5 ( V_71 ) << 32 ;
V_75 [ V_67 ] |= ( T_2 ) F_5 ( V_72 ) << 32 ;
V_71 += V_69 ;
V_72 += V_69 ;
}
F_49 ( V_73 , V_73 , V_75 , V_79 ) ;
F_49 ( V_73 , V_73 , V_70 , V_79 ) ;
V_7 = F_50 ( V_73 , V_79 ) ;
while ( V_7 != V_79 ) {
V_68 = F_51 ( V_63 ,
F_52 ( V_7 ) ) ;
if ( V_66 )
F_53 ( V_68 ) ;
else
F_54 ( V_68 ) ;
F_55 ( V_73 , V_7 , 1 ) ;
V_7 = F_50 ( V_73 , V_79 ) ;
}
}
static void F_56 ( struct V_81 * V_82 )
{
F_12 ( F_57 ( V_82 -> V_83 ) ) ;
}
static void F_58 ( struct V_81 * V_82 )
{
F_16 ( F_57 ( V_82 -> V_83 ) ) ;
}
static void F_59 ( struct V_81 * V_82 )
{
unsigned int V_56 = F_57 ( V_82 -> V_83 ) ;
F_10 ( F_13 ( V_8 , V_60 ) , F_60 ( V_56 ) ) ;
}
static int F_61 ( struct V_81 * V_82 , unsigned int type )
{
unsigned int V_56 = F_57 ( V_82 -> V_83 ) ;
unsigned long V_39 ;
bool V_84 ;
F_62 ( & V_85 , V_39 ) ;
switch ( type & V_86 ) {
case V_87 :
F_17 ( V_56 , V_88 ) ;
F_18 ( V_56 , V_89 ) ;
F_19 ( V_56 , V_90 ) ;
V_84 = true ;
break;
case V_91 :
F_17 ( V_56 , V_92 ) ;
F_18 ( V_56 , V_89 ) ;
F_19 ( V_56 , V_90 ) ;
V_84 = true ;
break;
case V_93 :
F_18 ( V_56 , V_89 ) ;
F_19 ( V_56 , V_94 ) ;
V_84 = true ;
break;
case V_95 :
F_17 ( V_56 , V_88 ) ;
F_18 ( V_56 , V_96 ) ;
F_19 ( V_56 , V_90 ) ;
V_84 = false ;
break;
case V_97 :
default:
F_17 ( V_56 , V_92 ) ;
F_18 ( V_56 , V_96 ) ;
F_19 ( V_56 , V_90 ) ;
V_84 = false ;
break;
}
if ( V_84 )
F_63 ( V_82 , & V_98 ,
V_99 , NULL ) ;
else
F_63 ( V_82 , & V_100 ,
V_101 , NULL ) ;
F_64 ( & V_85 , V_39 ) ;
return 0 ;
}
static int F_65 ( struct V_81 * V_82 , const struct V_102 * V_102 ,
bool V_103 )
{
unsigned int V_56 = F_57 ( V_82 -> V_83 ) ;
T_4 V_104 = V_105 ;
unsigned long V_39 ;
int V_67 ;
F_66 ( & V_104 , V_102 , V_106 ) ;
if ( F_67 ( & V_104 ) )
return - V_107 ;
F_62 ( & V_85 , V_39 ) ;
F_22 ( V_56 , F_68 ( F_69 ( & V_104 ) ) ) ;
for ( V_67 = 0 ; V_67 < V_108 ; V_67 ++ )
F_70 ( V_56 , V_76 [ V_67 ] . V_70 ) ;
F_71 ( V_56 , V_76 [ F_69 ( & V_104 ) ] . V_70 ) ;
F_72 ( F_73 ( V_82 ) , V_102 ) ;
F_64 ( & V_85 , V_39 ) ;
return V_109 ;
}
static void F_74 ( bool V_66 )
{
unsigned long V_73 , V_110 ;
unsigned int V_7 , V_68 ;
V_73 = F_1 ( F_13 ( V_34 , V_111 ) ) ;
V_110 = F_1 ( F_13 ( V_34 , V_112 ) ) ;
F_49 ( & V_73 , & V_73 , & V_110 , V_113 ) ;
V_7 = F_50 ( & V_73 , V_113 ) ;
while ( V_7 != V_113 ) {
V_68 = F_51 ( V_63 ,
F_41 ( V_7 ) ) ;
if ( V_66 )
F_53 ( V_68 ) ;
else
F_54 ( V_68 ) ;
F_55 ( & V_73 , V_7 , 1 ) ;
V_7 = F_50 ( & V_73 , V_113 ) ;
}
}
static void F_75 ( struct V_81 * V_82 )
{
int V_7 = F_76 ( V_82 -> V_83 ) ;
F_6 ( F_13 ( V_34 , V_114 ) , 1 << V_7 ) ;
}
static void F_77 ( struct V_81 * V_82 )
{
int V_7 = F_76 ( V_82 -> V_83 ) ;
F_6 ( F_13 ( V_34 , V_115 ) , 1 << V_7 ) ;
}
static void F_78 ( struct V_81 * V_82 )
{
int V_7 = F_76 ( V_82 -> V_83 ) ;
int V_67 ;
unsigned long V_39 ;
F_62 ( & V_85 , V_39 ) ;
for ( V_67 = 0 ; V_67 < V_116 ; V_67 ++ ) {
F_10 ( F_13 ( V_34 , V_40 ) , V_67 ) ;
F_6 ( F_13 ( V_41 , V_114 ) , 1 << V_7 ) ;
}
F_64 ( & V_85 , V_39 ) ;
}
static void F_79 ( struct V_81 * V_82 )
{
int V_7 = F_76 ( V_82 -> V_83 ) ;
int V_67 ;
unsigned long V_39 ;
F_62 ( & V_85 , V_39 ) ;
for ( V_67 = 0 ; V_67 < V_116 ; V_67 ++ ) {
F_10 ( F_13 ( V_34 , V_40 ) , V_67 ) ;
F_6 ( F_13 ( V_41 , V_115 ) , 1 << V_7 ) ;
}
F_64 ( & V_85 , V_39 ) ;
}
static void F_80 ( void )
{
F_74 ( false ) ;
F_44 ( false ) ;
}
static void F_81 ( struct V_117 * V_118 )
{
F_74 ( true ) ;
F_44 ( true ) ;
}
unsigned int F_82 ( unsigned int V_38 )
{
return V_119 + V_38 ;
}
unsigned int F_83 ( unsigned int V_38 )
{
return V_120 + V_38 ;
}
static T_5 F_84 ( int V_56 , void * V_121 )
{
F_85 () ;
return V_122 ;
}
static T_5 F_86 ( int V_56 , void * V_121 )
{
F_87 () ;
return V_122 ;
}
static T_6 void F_88 ( unsigned int V_7 , int V_38 ,
struct V_123 * V_124 )
{
int V_68 = F_40 ( V_63 ,
F_52 ( V_7 ) ) ;
int V_67 ;
F_22 ( V_7 , F_68 ( V_38 ) ) ;
for ( V_67 = 0 ; V_67 < V_108 ; V_67 ++ )
F_70 ( V_7 , V_76 [ V_67 ] . V_70 ) ;
F_71 ( V_7 , V_76 [ V_38 ] . V_70 ) ;
F_89 ( V_68 , V_91 ) ;
F_90 ( V_68 , V_125 ) ;
F_91 ( V_68 , V_124 ) ;
}
static T_6 void F_92 ( void )
{
int V_67 ;
V_119 = V_79 - V_126 ;
V_120 = V_119 - V_126 ;
for ( V_67 = 0 ; V_67 < V_126 ; V_67 ++ ) {
F_88 ( V_120 + V_67 , V_67 , & V_127 ) ;
F_88 ( V_119 + V_67 , V_67 , & V_128 ) ;
}
}
static inline void F_92 ( void )
{
}
static void T_6 F_93 ( void )
{
unsigned int V_67 ;
V_129 = & F_35 ;
for ( V_67 = 0 ; V_67 < V_79 ; V_67 ++ ) {
F_17 ( V_67 , V_92 ) ;
F_18 ( V_67 , V_96 ) ;
F_12 ( V_67 ) ;
}
for ( V_67 = 0 ; V_67 < V_116 ; V_67 ++ ) {
unsigned int V_130 ;
F_10 ( F_13 ( V_34 , V_40 ) , V_67 ) ;
for ( V_130 = 0 ; V_130 < V_113 ; V_130 ++ ) {
if ( ! F_34 ( V_130 ) )
continue;
F_6 ( F_13 ( V_41 , V_114 ) , 1 << V_130 ) ;
}
}
}
static int F_94 ( struct V_131 * V_82 , unsigned int V_68 ,
T_7 V_132 )
{
int V_7 = F_76 ( V_132 ) ;
int V_133 = 0 ;
int V_67 ;
unsigned long V_39 ;
if ( ! F_34 ( V_7 ) )
return - V_134 ;
switch ( V_7 ) {
case V_47 :
case V_49 :
case V_51 :
F_95 ( V_68 ,
& V_135 ,
V_125 ) ;
break;
default:
F_95 ( V_68 ,
& V_136 ,
V_137 ) ;
F_96 ( V_68 ) ;
break;
}
F_62 ( & V_85 , V_39 ) ;
for ( V_67 = 0 ; V_67 < V_116 ; V_67 ++ ) {
T_1 V_4 = V_19 | V_138 ;
F_10 ( F_13 ( V_34 , V_40 ) , V_67 ) ;
switch ( V_7 ) {
case V_139 :
F_6 ( F_13 ( V_41 , V_140 ) , V_4 ) ;
break;
case V_141 :
F_6 ( F_13 ( V_41 , V_142 ) ,
V_4 ) ;
break;
case V_47 :
V_4 = V_19 | V_143 ;
F_6 ( F_13 ( V_41 , V_144 ) ,
V_4 ) ;
break;
case V_49 :
F_6 ( F_13 ( V_41 , V_145 ) ,
V_4 ) ;
break;
case V_53 :
F_6 ( F_13 ( V_41 , V_146 ) ,
V_4 ) ;
break;
case V_54 :
F_6 ( F_13 ( V_41 , V_147 ) ,
V_4 ) ;
break;
case V_51 :
F_6 ( F_13 ( V_41 , V_148 ) , V_4 ) ;
break;
default:
F_97 ( L_1 , V_7 ) ;
V_133 = - V_107 ;
break;
}
}
F_64 ( & V_85 , V_39 ) ;
return V_133 ;
}
static int F_98 ( struct V_131 * V_82 , unsigned int V_68 ,
T_7 V_132 )
{
int V_7 = F_57 ( V_132 ) ;
unsigned long V_39 ;
F_95 ( V_68 , & V_100 ,
V_101 ) ;
F_62 ( & V_85 , V_39 ) ;
F_20 ( V_7 , V_138 ) ;
F_22 ( V_7 , 0 ) ;
F_71 ( V_7 , V_76 [ 0 ] . V_70 ) ;
F_64 ( & V_85 , V_39 ) ;
return 0 ;
}
static int F_99 ( struct V_131 * V_82 , unsigned int V_68 ,
T_7 V_132 )
{
if ( F_76 ( V_132 ) < V_113 )
return F_94 ( V_82 , V_68 , V_132 ) ;
return F_98 ( V_82 , V_68 , V_132 ) ;
}
static int F_100 ( struct V_131 * V_82 , struct V_149 * V_150 ,
const T_1 * V_151 , unsigned int V_152 ,
T_7 * V_153 ,
unsigned int * V_154 )
{
if ( V_152 != 3 )
return - V_107 ;
if ( V_151 [ 0 ] == V_155 )
* V_153 = F_52 ( V_151 [ 1 ] ) ;
else if ( V_151 [ 0 ] == V_156 )
* V_153 = F_41 ( V_151 [ 1 ] ) ;
else
return - V_107 ;
* V_154 = V_151 [ 2 ] & V_86 ;
return 0 ;
}
static void T_6 F_101 ( unsigned long V_157 ,
unsigned long V_158 ,
unsigned int V_159 , unsigned int V_160 ,
struct V_149 * V_161 )
{
unsigned int V_42 ;
V_2 = F_102 ( V_157 , V_158 ) ;
V_42 = F_5 ( F_13 ( V_8 , V_30 ) ) ;
V_79 = ( V_42 & V_162 ) >>
V_163 ;
V_79 = ( ( V_79 + 1 ) * 8 ) ;
V_116 = ( V_42 & V_164 ) >>
V_165 ;
V_116 = V_116 + 1 ;
if ( V_45 ) {
V_138 = 0 ;
V_143 = V_138 ;
F_103 ( V_138 + V_58 ,
F_80 ) ;
} else {
V_138 = V_159 - V_166 ;
F_104 ( V_61 + V_159 ,
F_81 ) ;
if ( F_105 ( V_167 ) &&
F_34 ( V_47 ) ) {
V_143 = F_1 ( F_13 ( V_34 ,
V_144 ) ) &
V_168 ;
F_104 ( V_61 +
V_166 +
V_143 ,
F_81 ) ;
} else {
V_143 = V_138 ;
}
}
V_63 = F_106 ( V_161 , V_113 +
V_79 , V_160 ,
& V_169 , NULL ) ;
if ( ! V_63 )
F_107 ( L_2 ) ;
F_93 () ;
F_92 () ;
}
void T_6 F_108 ( unsigned long V_157 ,
unsigned long V_158 ,
unsigned int V_159 , unsigned int V_160 )
{
F_101 ( V_157 , V_158 , V_159 , V_160 , NULL ) ;
}
static int T_6 F_109 ( struct V_149 * V_161 ,
struct V_149 * V_170 )
{
struct V_171 V_172 ;
unsigned int V_159 , V_67 = 0 , V_173 = 0 ;
T_8 V_2 ;
T_9 V_174 ;
while ( ! F_110 ( V_161 , L_3 ,
V_67 ++ , & V_159 ) )
V_173 |= F_111 ( V_159 ) ;
for ( V_159 = 2 ; V_159 < 8 ; V_159 ++ ) {
if ( ! ( V_173 & F_111 ( V_159 ) ) )
break;
}
if ( V_159 == 8 ) {
F_97 ( L_4 ) ;
return - V_175 ;
}
if ( F_112 ( V_161 , 0 , & V_172 ) ) {
if ( F_113 () ) {
V_2 = F_114 () &
~ V_176 ;
V_174 = 0x20000 ;
} else {
F_97 ( L_5 ) ;
return - V_175 ;
}
} else {
V_2 = V_172 . V_177 ;
V_174 = F_115 ( & V_172 ) ;
}
if ( F_113 () )
F_116 ( V_2 | V_176 ) ;
V_178 = true ;
F_101 ( V_2 , V_174 , V_159 , 0 , V_161 ) ;
return 0 ;
}
