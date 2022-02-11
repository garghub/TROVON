static inline T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
return * ( ( T_1 * ) ( V_2 -> V_4 + V_3 ) ) ;
}
static inline void F_2 ( struct V_1 * V_2 , int V_3 , T_1 V_5 )
{
* ( ( T_1 * ) ( V_2 -> V_4 + V_3 ) ) = V_5 ;
}
static inline int F_3 ( int V_6 , void * V_7 )
{
return F_4 ( F_5 ( V_6 ) , ( V_7 ) + F_6 ( V_6 ) ) ;
}
static inline int F_7 ( int V_6 , void * V_7 )
{
return F_8 ( F_5 ( V_6 ) , ( V_7 ) + F_6 ( V_6 ) ) ;
}
static inline int F_9 ( int V_6 , void * V_7 )
{
return F_10 ( F_5 ( V_6 ) , ( V_7 ) + F_6 ( V_6 ) ) ;
}
static inline void F_11 ( int V_6 , void * V_7 )
{
F_12 ( F_5 ( V_6 ) , ( V_7 ) + F_6 ( V_6 ) ) ;
}
static inline void F_13 ( int V_6 , void * V_7 )
{
F_14 ( F_5 ( V_6 ) , ( V_7 ) + F_6 ( V_6 ) ) ;
}
static inline int F_15 ( int V_6 , void * V_7 )
{
return F_16 ( F_5 ( V_6 ) , ( V_7 ) + F_6 ( V_6 ) ) ;
}
static inline int F_17 ( int V_6 , void * V_7 )
{
return F_18 ( F_5 ( V_6 ) , ( V_7 ) + F_6 ( V_6 ) ) ;
}
static inline int F_19 ( struct V_1 * V_2 )
{
return ( V_2 ) -> V_8 -> V_9 . V_10 & V_11 ;
}
static inline int F_20 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_12 ) & V_13 ;
}
static inline int F_21 ( struct V_1 * V_2 )
{
return F_20 ( V_2 ) && F_19 ( V_2 ) ;
}
static inline int F_22 ( struct V_1 * V_2 )
{
return ( F_1 ( V_2 , V_14 ) >> 24 ) & 0xff ;
}
static inline int F_23 ( struct V_1 * V_2 , int V_15 )
{
return ! ( F_1 ( V_2 , V_15 ) & V_16 ) ;
}
static inline int F_24 ( struct V_1 * V_2 , int V_15 )
{
return F_1 ( V_2 , V_15 ) & V_17 ;
}
static inline int F_25 ( struct V_1 * V_2 )
{
return ( ( F_1 ( V_2 , V_18 ) &
V_2 -> V_19 . V_20 ) == V_21 ) ;
}
static inline int F_26 ( struct V_1 * V_2 )
{
return ( ( F_1 ( V_2 , V_18 ) &
V_2 -> V_19 . V_20 ) == V_22 ) ;
}
static inline int F_27 ( struct V_1 * V_2 )
{
return ( ( F_1 ( V_2 , V_18 ) &
V_2 -> V_19 . V_20 ) ==
V_23 ) ;
}
static inline int F_28 ( T_1 V_24 )
{
return ( V_24 & ( V_25 | V_16 ) ) == V_26 ;
}
void F_29 ( struct V_27 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
struct V_28 * V_29 ;
T_1 V_30 = V_31 ;
if ( ! F_30 ( V_8 -> V_32 ) )
return;
V_29 = F_31 ( V_2 -> V_8 , 0x1 , 0 ) ;
if ( V_29 && ( V_29 -> V_33 & ( 1 << ( V_34 & 31 ) ) ) )
V_30 |= V_35 ;
F_2 ( V_2 , V_36 , V_30 ) ;
}
static inline int F_32 ( struct V_1 * V_2 )
{
return V_2 -> V_8 -> V_9 . V_10 & V_37 ;
}
static int F_33 ( void * V_7 )
{
T_1 * V_38 = V_7 ;
int V_39 = V_40 >> 5 ;
while ( ( V_39 != 0 ) && ( V_38 [ ( -- V_39 ) << 2 ] == 0 ) )
continue;
if ( F_34 ( ! V_39 && ! V_38 [ 0 ] ) )
return - 1 ;
else
return F_35 ( V_38 [ V_39 << 2 ] ) - 1 + ( V_39 << 5 ) ;
}
static T_2 F_36 ( void * V_7 )
{
T_1 * V_38 = V_7 ;
int V_39 ;
T_2 V_41 = 0 ;
for ( V_39 = 0 ; V_39 < V_40 > > 5 ; ++ V_39 )
V_41 += F_37 ( V_38 [ V_39 << 2 ] ) ;
return V_41 ;
}
static inline int F_38 ( int V_6 , struct V_1 * V_2 )
{
V_2 -> V_42 = true ;
return F_3 ( V_6 , V_2 -> V_4 + V_43 ) ;
}
static inline int F_39 ( struct V_1 * V_2 )
{
return F_33 ( V_2 -> V_4 + V_43 ) ;
}
static inline int F_40 ( struct V_1 * V_2 )
{
int V_44 ;
if ( ! V_2 -> V_42 )
return - 1 ;
V_44 = F_39 ( V_2 ) ;
ASSERT ( V_44 == - 1 || V_44 >= 16 ) ;
return V_44 ;
}
static inline void F_41 ( int V_6 , struct V_1 * V_2 )
{
V_2 -> V_42 = false ;
F_13 ( V_6 , V_2 -> V_4 + V_43 ) ;
if ( F_39 ( V_2 ) != - 1 )
V_2 -> V_42 = true ;
}
static inline void F_42 ( int V_6 , struct V_1 * V_2 )
{
if ( ! F_15 ( V_6 , V_2 -> V_4 + V_45 ) )
++ V_2 -> V_46 ;
F_43 ( V_2 -> V_46 > V_40 ) ;
V_2 -> V_47 = V_6 ;
}
static inline void F_44 ( int V_6 , struct V_1 * V_2 )
{
if ( F_17 ( V_6 , V_2 -> V_4 + V_45 ) )
-- V_2 -> V_46 ;
F_43 ( V_2 -> V_46 < 0 ) ;
V_2 -> V_47 = - 1 ;
}
int F_45 ( struct V_27 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
int V_48 ;
if ( ! V_2 )
return 0 ;
V_48 = F_40 ( V_2 ) ;
return V_48 ;
}
int F_46 ( struct V_27 * V_8 , struct V_49 * V_50 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
return F_47 ( V_2 , V_50 -> V_51 , V_50 -> V_52 ,
V_50 -> V_53 , V_50 -> V_54 ) ;
}
static int F_48 ( struct V_27 * V_8 , T_2 V_5 )
{
return F_49 ( V_8 -> V_32 , & V_8 -> V_9 . V_55 . V_56 , & V_5 ,
sizeof( V_5 ) ) ;
}
static int F_50 ( struct V_27 * V_8 , T_2 * V_5 )
{
return F_51 ( V_8 -> V_32 , & V_8 -> V_9 . V_55 . V_56 , V_5 ,
sizeof( * V_5 ) ) ;
}
static inline bool F_52 ( struct V_27 * V_8 )
{
return V_8 -> V_9 . V_55 . V_57 & V_58 ;
}
static bool F_53 ( struct V_27 * V_8 )
{
T_2 V_5 ;
if ( F_50 ( V_8 , & V_5 ) < 0 )
F_54 ( L_1 ,
( unsigned long long ) V_59 -> V_9 . V_55 . V_57 ) ;
return V_5 & 0x1 ;
}
static void F_55 ( struct V_27 * V_8 )
{
if ( F_48 ( V_8 , V_60 ) < 0 ) {
F_54 ( L_2 ,
( unsigned long long ) V_59 -> V_9 . V_55 . V_57 ) ;
return;
}
F_56 ( V_61 , & V_8 -> V_9 . V_62 ) ;
}
static void F_57 ( struct V_27 * V_8 )
{
if ( F_48 ( V_8 , V_63 ) < 0 ) {
F_54 ( L_3 ,
( unsigned long long ) V_59 -> V_9 . V_55 . V_57 ) ;
return;
}
F_58 ( V_61 , & V_8 -> V_9 . V_62 ) ;
}
static inline int F_59 ( struct V_1 * V_2 )
{
int V_44 ;
if ( ! V_2 -> V_46 )
return - 1 ;
if ( F_34 ( V_2 -> V_47 != - 1 ) )
return V_2 -> V_47 ;
V_44 = F_33 ( V_2 -> V_4 + V_45 ) ;
ASSERT ( V_44 == - 1 || V_44 >= 16 ) ;
return V_44 ;
}
static void F_60 ( struct V_1 * V_2 )
{
T_1 V_64 , V_65 , V_66 , V_67 ;
int V_68 ;
V_67 = F_1 ( V_2 , V_69 ) ;
V_64 = F_1 ( V_2 , V_70 ) ;
V_68 = F_59 ( V_2 ) ;
V_65 = ( V_68 != - 1 ) ? V_68 : 0 ;
if ( ( V_64 & 0xf0 ) >= ( V_65 & 0xf0 ) )
V_66 = V_64 & 0xff ;
else
V_66 = V_65 & 0xf0 ;
F_54 ( L_4 ,
V_2 , V_66 , V_68 , V_65 ) ;
if ( V_67 != V_66 ) {
F_2 ( V_2 , V_69 , V_66 ) ;
if ( V_66 < V_67 )
F_61 ( V_71 , V_2 -> V_8 ) ;
}
}
static void F_62 ( struct V_1 * V_2 , T_1 V_64 )
{
F_2 ( V_2 , V_70 , V_64 ) ;
F_60 ( V_2 ) ;
}
int F_63 ( struct V_1 * V_2 , T_3 V_72 )
{
return V_72 == 0xff || F_22 ( V_2 ) == V_72 ;
}
int F_64 ( struct V_1 * V_2 , T_2 V_73 )
{
int V_44 = 0 ;
T_1 V_74 ;
if ( F_32 ( V_2 ) ) {
V_74 = F_1 ( V_2 , V_75 ) ;
return V_74 & V_73 ;
}
V_74 = F_65 ( F_1 ( V_2 , V_75 ) ) ;
switch ( F_1 ( V_2 , V_76 ) ) {
case V_77 :
if ( V_74 & V_73 )
V_44 = 1 ;
break;
case V_78 :
if ( ( ( V_74 >> 4 ) == ( V_73 >> 0x4 ) )
&& ( V_74 & V_73 & 0xf ) )
V_44 = 1 ;
break;
default:
F_54 ( L_5 ,
V_2 -> V_8 -> V_79 , F_1 ( V_2 , V_76 ) ) ;
break;
}
return V_44 ;
}
int F_66 ( struct V_27 * V_8 , struct V_1 * V_80 ,
int V_81 , int V_72 , int V_82 )
{
int V_44 = 0 ;
struct V_1 * V_83 = V_8 -> V_9 . V_2 ;
F_54 ( L_6
L_7 ,
V_83 , V_80 , V_72 , V_82 , V_81 ) ;
ASSERT ( V_83 ) ;
switch ( V_81 ) {
case V_84 :
if ( V_82 == 0 )
V_44 = F_63 ( V_83 , V_72 ) ;
else
V_44 = F_64 ( V_83 , V_72 ) ;
break;
case V_85 :
V_44 = ( V_83 == V_80 ) ;
break;
case V_86 :
V_44 = 1 ;
break;
case V_87 :
V_44 = ( V_83 != V_80 ) ;
break;
default:
F_54 ( L_8 ,
V_81 ) ;
break;
}
return V_44 ;
}
static int F_47 ( struct V_1 * V_2 , int V_51 ,
int V_52 , int V_53 , int V_54 )
{
int V_44 = 0 ;
struct V_27 * V_8 = V_2 -> V_8 ;
switch ( V_51 ) {
case V_88 :
V_8 -> V_9 . V_89 ++ ;
case V_90 :
if ( F_67 ( ! F_21 ( V_2 ) ) )
break;
if ( V_54 ) {
F_54 ( L_9 , V_52 ) ;
F_11 ( V_52 , V_2 -> V_4 + V_91 ) ;
} else
F_13 ( V_52 , V_2 -> V_4 + V_91 ) ;
V_44 = ! F_38 ( V_52 , V_2 ) ;
F_68 ( V_8 -> V_79 , V_51 ,
V_54 , V_52 , ! V_44 ) ;
if ( ! V_44 ) {
if ( V_54 )
F_54 ( L_10
L_11 , V_52 ) ;
break;
}
F_61 ( V_71 , V_8 ) ;
F_69 ( V_8 ) ;
break;
case V_92 :
F_54 ( L_12 ) ;
break;
case V_93 :
F_54 ( L_13 ) ;
break;
case V_26 :
V_44 = 1 ;
F_70 ( V_8 ) ;
F_69 ( V_8 ) ;
break;
case V_94 :
if ( ! V_54 || V_53 ) {
V_44 = 1 ;
V_8 -> V_9 . V_95 = V_96 ;
F_61 ( V_71 , V_8 ) ;
F_69 ( V_8 ) ;
} else {
F_54 ( L_14 ,
V_8 -> V_79 ) ;
}
break;
case V_97 :
F_54 ( L_15 ,
V_8 -> V_79 , V_52 ) ;
if ( V_8 -> V_9 . V_95 == V_96 ) {
V_44 = 1 ;
V_8 -> V_9 . V_98 = V_52 ;
V_8 -> V_9 . V_95 = V_99 ;
F_61 ( V_71 , V_8 ) ;
F_69 ( V_8 ) ;
}
break;
case V_100 :
break;
default:
F_71 ( V_101 L_16 ,
V_51 ) ;
break;
}
return V_44 ;
}
int F_72 ( struct V_27 * V_102 , struct V_27 * V_103 )
{
return V_102 -> V_9 . V_89 - V_103 -> V_9 . V_89 ;
}
static int F_73 ( struct V_1 * V_2 )
{
int V_52 = F_59 ( V_2 ) ;
F_74 ( V_2 , V_52 ) ;
if ( V_52 == - 1 )
return V_52 ;
F_44 ( V_52 , V_2 ) ;
F_60 ( V_2 ) ;
if ( ! ( F_1 ( V_2 , V_12 ) & V_104 ) &&
F_75 ( V_2 -> V_8 -> V_32 , V_52 ) ) {
int V_105 ;
if ( F_9 ( V_52 , V_2 -> V_4 + V_91 ) )
V_105 = V_106 ;
else
V_105 = V_107 ;
F_76 ( V_2 -> V_8 -> V_32 , V_52 , V_105 ) ;
}
F_61 ( V_71 , V_2 -> V_8 ) ;
return V_52 ;
}
static void F_77 ( struct V_1 * V_2 )
{
T_1 V_108 = F_1 ( V_2 , V_109 ) ;
T_1 V_110 = F_1 ( V_2 , V_111 ) ;
struct V_49 V_50 ;
V_50 . V_52 = V_108 & V_17 ;
V_50 . V_51 = V_108 & V_25 ;
V_50 . V_82 = V_108 & V_112 ;
V_50 . V_53 = V_108 & V_113 ;
V_50 . V_54 = V_108 & V_114 ;
V_50 . V_115 = V_108 & V_116 ;
if ( F_32 ( V_2 ) )
V_50 . V_117 = V_110 ;
else
V_50 . V_117 = F_78 ( V_110 ) ;
F_79 ( V_108 , V_50 . V_117 ) ;
F_54 ( L_17
L_18
L_19 ,
V_110 , V_108 , V_50 . V_115 , V_50 . V_117 ,
V_50 . V_54 , V_50 . V_53 , V_50 . V_82 , V_50 . V_51 ,
V_50 . V_52 ) ;
F_80 ( V_2 -> V_8 -> V_32 , V_2 , & V_50 ) ;
}
static T_1 F_81 ( struct V_1 * V_2 )
{
T_4 V_118 ;
T_5 V_119 ;
T_1 V_120 ;
ASSERT ( V_2 != NULL ) ;
if ( F_1 ( V_2 , V_121 ) == 0 )
return 0 ;
V_118 = F_82 ( & V_2 -> V_19 . V_122 ) ;
if ( F_83 ( V_118 ) < 0 )
V_118 = F_84 ( 0 , 0 ) ;
V_119 = F_85 ( F_83 ( V_118 ) , V_2 -> V_19 . V_123 ) ;
V_120 = F_86 ( V_119 ,
( V_124 * V_2 -> V_125 ) ) ;
return V_120 ;
}
static void F_87 ( struct V_1 * V_2 , bool V_126 )
{
struct V_27 * V_8 = V_2 -> V_8 ;
struct V_127 * V_128 = V_8 -> V_128 ;
F_61 ( V_129 , V_8 ) ;
V_128 -> V_130 . V_131 = F_88 ( V_8 ) ;
V_128 -> V_130 . V_132 = V_126 ;
}
static inline void F_89 ( struct V_1 * V_2 , bool V_126 )
{
if ( V_2 -> V_8 -> V_9 . V_133 )
F_87 ( V_2 , V_126 ) ;
}
static T_1 F_90 ( struct V_1 * V_2 , unsigned int V_134 )
{
T_1 V_5 = 0 ;
if ( V_134 >= V_135 )
return 0 ;
switch ( V_134 ) {
case V_14 :
if ( F_32 ( V_2 ) )
V_5 = F_22 ( V_2 ) ;
else
V_5 = F_22 ( V_2 ) << 24 ;
break;
case V_136 :
F_54 ( L_20 ) ;
break;
case V_137 :
if ( F_27 ( V_2 ) )
return 0 ;
V_5 = F_81 ( V_2 ) ;
break;
case V_70 :
F_89 ( V_2 , false ) ;
default:
F_60 ( V_2 ) ;
V_5 = F_1 ( V_2 , V_134 ) ;
break;
}
return V_5 ;
}
static inline struct V_1 * F_91 ( struct V_138 * V_139 )
{
return F_92 ( V_139 , struct V_1 , V_139 ) ;
}
static int F_93 ( struct V_1 * V_2 , T_1 V_134 , int V_140 ,
void * V_56 )
{
unsigned char V_141 = V_134 & 0xf ;
T_1 V_44 ;
static const T_6 V_142 = 0x43ff01ffffffe70cULL ;
if ( ( V_141 + V_140 ) > 4 ) {
F_54 ( L_21 ,
V_134 , V_140 ) ;
return 1 ;
}
if ( V_134 > 0x3f0 || ! ( V_142 & ( 1ULL << ( V_134 >> 4 ) ) ) ) {
F_54 ( L_22 ,
V_134 ) ;
return 1 ;
}
V_44 = F_90 ( V_2 , V_134 & ~ 0xf ) ;
F_94 ( V_134 , V_44 ) ;
switch ( V_140 ) {
case 1 :
case 2 :
case 4 :
memcpy ( V_56 , ( char * ) & V_44 + V_141 , V_140 ) ;
break;
default:
F_71 ( V_101 L_23
L_24 , V_140 ) ;
break;
}
return 0 ;
}
static int F_95 ( struct V_1 * V_2 , T_7 V_143 )
{
return F_19 ( V_2 ) &&
V_143 >= V_2 -> V_144 &&
V_143 < V_2 -> V_144 + V_135 ;
}
static int F_96 ( struct V_138 * V_145 ,
T_7 V_146 , int V_140 , void * V_56 )
{
struct V_1 * V_2 = F_91 ( V_145 ) ;
T_1 V_134 = V_146 - V_2 -> V_144 ;
if ( ! F_95 ( V_2 , V_146 ) )
return - V_147 ;
F_93 ( V_2 , V_134 , V_140 , V_56 ) ;
return 0 ;
}
static void F_97 ( struct V_1 * V_2 )
{
T_1 V_148 , V_149 , V_150 ;
V_150 = F_1 ( V_2 , V_151 ) ;
V_148 = V_150 & 0xf ;
V_149 = ( ( V_148 & 0x3 ) | ( ( V_148 & 0x8 ) >> 1 ) ) + 1 ;
V_2 -> V_125 = 0x1 << ( V_149 & 0x7 ) ;
F_54 ( L_25 ,
V_2 -> V_125 ) ;
}
static void F_98 ( struct V_1 * V_2 )
{
T_4 V_152 ;
F_99 ( & V_2 -> V_19 . V_153 , 0 ) ;
if ( F_26 ( V_2 ) || F_25 ( V_2 ) ) {
V_152 = V_2 -> V_19 . V_122 . V_154 -> V_155 () ;
V_2 -> V_19 . V_123 = ( T_6 ) F_1 ( V_2 , V_121 )
* V_124 * V_2 -> V_125 ;
if ( ! V_2 -> V_19 . V_123 )
return;
if ( F_26 ( V_2 ) ) {
T_5 V_156 = V_157 * 1000LL ;
if ( V_2 -> V_19 . V_123 < V_156 ) {
F_100 (
L_26
L_27 ,
V_2 -> V_8 -> V_79 ,
V_2 -> V_19 . V_123 , V_156 ) ;
V_2 -> V_19 . V_123 = V_156 ;
}
}
F_101 ( & V_2 -> V_19 . V_122 ,
F_102 ( V_152 , V_2 -> V_19 . V_123 ) ,
V_158 ) ;
F_54 ( L_28 V_159 L_29
V_160 L_30
L_31
L_32 V_160 L_33 , V_161 ,
V_124 , F_83 ( V_152 ) ,
F_1 ( V_2 , V_121 ) ,
V_2 -> V_19 . V_123 ,
F_83 ( F_102 ( V_152 ,
V_2 -> V_19 . V_123 ) ) ) ;
} else if ( F_27 ( V_2 ) ) {
T_6 V_162 , V_163 = V_2 -> V_19 . V_163 ;
T_6 V_119 = 0 ;
struct V_27 * V_8 = V_2 -> V_8 ;
unsigned long V_164 = V_8 -> V_9 . V_165 ;
unsigned long V_166 ;
if ( F_67 ( ! V_163 || ! V_164 ) )
return;
F_103 ( V_166 ) ;
V_152 = V_2 -> V_19 . V_122 . V_154 -> V_155 () ;
V_162 = V_167 -> V_168 ( V_8 ) ;
if ( F_34 ( V_163 > V_162 ) ) {
V_119 = ( V_163 - V_162 ) * 1000000ULL ;
F_104 ( V_119 , V_164 ) ;
}
F_101 ( & V_2 -> V_19 . V_122 ,
F_102 ( V_152 , V_119 ) , V_158 ) ;
F_105 ( V_166 ) ;
}
}
static void F_106 ( struct V_1 * V_2 , T_1 V_169 )
{
int V_170 = F_28 ( F_1 ( V_2 , V_171 ) ) ;
if ( F_28 ( V_169 ) ) {
if ( ! V_170 ) {
F_54 ( L_34
L_35 , V_2 -> V_8 -> V_79 ) ;
V_2 -> V_8 -> V_32 -> V_9 . V_172 ++ ;
}
} else if ( V_170 )
V_2 -> V_8 -> V_32 -> V_9 . V_172 -- ;
}
static int F_107 ( struct V_1 * V_2 , T_1 V_173 , T_1 V_5 )
{
int V_174 = 0 ;
F_108 ( V_173 , V_5 ) ;
switch ( V_173 ) {
case V_14 :
if ( ! F_32 ( V_2 ) )
F_2 ( V_2 , V_14 , V_5 ) ;
else
V_174 = 1 ;
break;
case V_70 :
F_89 ( V_2 , true ) ;
F_62 ( V_2 , V_5 & 0xff ) ;
break;
case V_175 :
F_73 ( V_2 ) ;
break;
case V_75 :
if ( ! F_32 ( V_2 ) )
F_2 ( V_2 , V_75 , V_5 & V_176 ) ;
else
V_174 = 1 ;
break;
case V_76 :
if ( ! F_32 ( V_2 ) )
F_2 ( V_2 , V_76 , V_5 | 0x0FFFFFFF ) ;
else
V_174 = 1 ;
break;
case V_12 : {
T_1 V_177 = 0x3ff ;
if ( F_1 ( V_2 , V_36 ) & V_35 )
V_177 |= V_104 ;
F_2 ( V_2 , V_12 , V_5 & V_177 ) ;
if ( ! ( V_5 & V_13 ) ) {
int V_178 ;
T_1 V_24 ;
for ( V_178 = 0 ; V_178 < V_179 ; V_178 ++ ) {
V_24 = F_1 ( V_2 ,
V_18 + 0x10 * V_178 ) ;
F_2 ( V_2 , V_18 + 0x10 * V_178 ,
V_24 | V_16 ) ;
}
F_99 ( & V_2 -> V_19 . V_153 , 0 ) ;
}
break;
}
case V_109 :
F_2 ( V_2 , V_109 , V_5 & ~ ( 1 << 12 ) ) ;
F_77 ( V_2 ) ;
break;
case V_111 :
if ( ! F_32 ( V_2 ) )
V_5 &= 0xff000000 ;
F_2 ( V_2 , V_111 , V_5 ) ;
break;
case V_171 :
F_106 ( V_2 , V_5 ) ;
case V_180 :
case V_181 :
case V_182 :
case V_183 :
if ( ! F_20 ( V_2 ) )
V_5 |= V_16 ;
V_5 &= V_184 [ ( V_173 - V_18 ) >> 4 ] ;
F_2 ( V_2 , V_173 , V_5 ) ;
break;
case V_18 :
if ( ( F_1 ( V_2 , V_18 ) &
V_2 -> V_19 . V_20 ) !=
( V_5 & V_2 -> V_19 . V_20 ) )
F_109 ( & V_2 -> V_19 . V_122 ) ;
if ( ! F_20 ( V_2 ) )
V_5 |= V_16 ;
V_5 &= ( V_184 [ 0 ] | V_2 -> V_19 . V_20 ) ;
F_2 ( V_2 , V_18 , V_5 ) ;
break;
case V_121 :
if ( F_27 ( V_2 ) )
break;
F_109 ( & V_2 -> V_19 . V_122 ) ;
F_2 ( V_2 , V_121 , V_5 ) ;
F_98 ( V_2 ) ;
break;
case V_151 :
if ( V_5 & 4 )
F_54 ( L_36 , V_5 ) ;
F_2 ( V_2 , V_151 , V_5 ) ;
F_97 ( V_2 ) ;
break;
case V_185 :
if ( F_32 ( V_2 ) && V_5 != 0 ) {
F_54 ( L_37 , V_5 ) ;
V_174 = 1 ;
}
break;
case V_186 :
if ( F_32 ( V_2 ) ) {
F_107 ( V_2 , V_109 , 0x40000 | ( V_5 & 0xff ) ) ;
} else
V_174 = 1 ;
break;
default:
V_174 = 1 ;
break;
}
if ( V_174 )
F_54 ( L_38 , V_173 ) ;
return V_174 ;
}
static int F_110 ( struct V_138 * V_145 ,
T_7 V_146 , int V_140 , const void * V_56 )
{
struct V_1 * V_2 = F_91 ( V_145 ) ;
unsigned int V_134 = V_146 - V_2 -> V_144 ;
T_1 V_5 ;
if ( ! F_95 ( V_2 , V_146 ) )
return - V_147 ;
if ( V_140 != 4 || ( V_134 & 0xf ) ) {
F_54 ( L_39 , V_140 , ( long ) V_146 ) ;
return 0 ;
}
V_5 = * ( T_1 * ) V_56 ;
if ( V_134 != V_175 )
F_54 ( L_40
L_41 , V_161 , V_134 , V_140 , V_5 ) ;
F_107 ( V_2 , V_134 & 0xff0 , V_5 ) ;
return 0 ;
}
void F_111 ( struct V_27 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
if ( V_2 )
F_107 ( V_8 -> V_9 . V_2 , V_175 , 0 ) ;
}
void F_112 ( struct V_27 * V_8 )
{
if ( ! V_8 -> V_9 . V_2 )
return;
F_109 ( & V_8 -> V_9 . V_2 -> V_19 . V_122 ) ;
if ( V_8 -> V_9 . V_2 -> V_4 )
F_113 ( ( unsigned long ) V_8 -> V_9 . V_2 -> V_4 ) ;
F_114 ( V_8 -> V_9 . V_2 ) ;
}
T_6 F_115 ( struct V_27 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
if ( ! V_2 )
return 0 ;
if ( F_25 ( V_2 ) || F_26 ( V_2 ) )
return 0 ;
return V_2 -> V_19 . V_163 ;
}
void F_116 ( struct V_27 * V_8 , T_6 V_56 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
if ( ! V_2 )
return;
if ( F_25 ( V_2 ) || F_26 ( V_2 ) )
return;
F_109 ( & V_2 -> V_19 . V_122 ) ;
V_2 -> V_19 . V_163 = V_56 ;
F_98 ( V_2 ) ;
}
void F_117 ( struct V_27 * V_8 , unsigned long V_187 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
if ( ! V_2 )
return;
F_62 ( V_2 , ( ( V_187 & 0x0f ) << 4 )
| ( F_1 ( V_2 , V_70 ) & 4 ) ) ;
}
T_6 F_118 ( struct V_27 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
T_6 V_64 ;
if ( ! V_2 )
return 0 ;
V_64 = ( T_6 ) F_1 ( V_2 , V_70 ) ;
return ( V_64 & 0xf0 ) >> 4 ;
}
void F_119 ( struct V_27 * V_8 , T_6 V_188 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
if ( ! V_2 ) {
V_188 |= V_189 ;
V_8 -> V_9 . V_10 = V_188 ;
return;
}
if ( ! F_120 ( V_2 -> V_8 ) )
V_188 &= ~ V_189 ;
V_8 -> V_9 . V_10 = V_188 ;
if ( F_32 ( V_2 ) ) {
T_1 V_190 = F_22 ( V_2 ) ;
T_1 V_191 = ( ( V_190 & ~ 0xf ) << 16 ) | ( 1 << ( V_190 & 0xf ) ) ;
F_2 ( V_2 , V_75 , V_191 ) ;
}
V_2 -> V_144 = V_2 -> V_8 -> V_9 . V_10 &
V_192 ;
F_54 ( L_42 V_160 L_43
L_44 , V_2 -> V_8 -> V_9 . V_10 , V_2 -> V_144 ) ;
}
void F_121 ( struct V_27 * V_8 )
{
struct V_1 * V_2 ;
int V_178 ;
F_54 ( L_45 , V_161 ) ;
ASSERT ( V_8 ) ;
V_2 = V_8 -> V_9 . V_2 ;
ASSERT ( V_2 != NULL ) ;
F_109 ( & V_2 -> V_19 . V_122 ) ;
F_2 ( V_2 , V_14 , V_8 -> V_79 << 24 ) ;
F_29 ( V_2 -> V_8 ) ;
for ( V_178 = 0 ; V_178 < V_179 ; V_178 ++ )
F_2 ( V_2 , V_18 + 0x10 * V_178 , V_16 ) ;
F_2 ( V_2 , V_171 ,
F_122 ( 0 , V_193 ) ) ;
F_2 ( V_2 , V_76 , 0xffffffffU ) ;
F_2 ( V_2 , V_12 , 0xff ) ;
F_2 ( V_2 , V_70 , 0 ) ;
F_2 ( V_2 , V_75 , 0 ) ;
F_2 ( V_2 , V_185 , 0 ) ;
F_2 ( V_2 , V_109 , 0 ) ;
F_2 ( V_2 , V_111 , 0 ) ;
F_2 ( V_2 , V_151 , 0 ) ;
F_2 ( V_2 , V_121 , 0 ) ;
for ( V_178 = 0 ; V_178 < 8 ; V_178 ++ ) {
F_2 ( V_2 , V_43 + 0x10 * V_178 , 0 ) ;
F_2 ( V_2 , V_45 + 0x10 * V_178 , 0 ) ;
F_2 ( V_2 , V_91 + 0x10 * V_178 , 0 ) ;
}
V_2 -> V_42 = false ;
V_2 -> V_46 = 0 ;
V_2 -> V_47 = - 1 ;
F_97 ( V_2 ) ;
F_99 ( & V_2 -> V_19 . V_153 , 0 ) ;
if ( F_120 ( V_8 ) )
V_8 -> V_9 . V_10 |= V_189 ;
V_8 -> V_9 . V_55 . V_57 = 0 ;
F_60 ( V_2 ) ;
V_8 -> V_9 . V_89 = 0 ;
V_8 -> V_9 . V_62 = 0 ;
F_54 ( V_194 L_46
L_47 V_160 L_48 , V_161 ,
V_8 , F_22 ( V_2 ) ,
V_8 -> V_9 . V_10 , V_2 -> V_144 ) ;
}
bool F_123 ( struct V_27 * V_8 )
{
return V_8 -> V_9 . V_2 && F_19 ( V_8 -> V_9 . V_2 ) ;
}
int F_124 ( struct V_27 * V_8 )
{
return F_123 ( V_8 ) && F_20 ( V_8 -> V_9 . V_2 ) ;
}
static bool F_125 ( struct V_195 * V_196 )
{
struct V_1 * V_2 = F_92 ( V_196 , struct V_1 ,
V_19 ) ;
return F_26 ( V_2 ) ;
}
int F_126 ( struct V_27 * V_8 )
{
struct V_1 * V_197 = V_8 -> V_9 . V_2 ;
if ( V_197 && F_21 ( V_197 ) && F_23 ( V_197 , V_18 ) )
return F_127 ( & V_197 -> V_19 . V_153 ) ;
return 0 ;
}
int F_128 ( struct V_1 * V_2 , int V_15 )
{
T_1 V_173 = F_1 ( V_2 , V_15 ) ;
int V_52 , V_198 , V_54 ;
if ( F_19 ( V_2 ) && ! ( V_173 & V_16 ) ) {
V_52 = V_173 & V_17 ;
V_198 = V_173 & V_25 ;
V_54 = V_173 & V_199 ;
return F_47 ( V_2 , V_198 , V_52 , 1 , V_54 ) ;
}
return 0 ;
}
void F_129 ( struct V_27 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
if ( V_2 )
F_128 ( V_2 , V_171 ) ;
}
int F_130 ( struct V_27 * V_8 )
{
struct V_1 * V_2 ;
ASSERT ( V_8 != NULL ) ;
F_54 ( L_49 , V_8 -> V_79 ) ;
V_2 = F_131 ( sizeof( * V_2 ) , V_200 ) ;
if ( ! V_2 )
goto V_201;
V_8 -> V_9 . V_2 = V_2 ;
V_2 -> V_4 = ( void * ) F_132 ( V_200 ) ;
if ( ! V_2 -> V_4 ) {
F_71 ( V_101 L_50 ,
V_8 -> V_79 ) ;
goto V_202;
}
V_2 -> V_8 = V_8 ;
F_133 ( & V_2 -> V_19 . V_122 , V_203 ,
V_158 ) ;
V_2 -> V_19 . V_122 . V_204 = V_205 ;
V_2 -> V_19 . V_206 = & V_207 ;
V_2 -> V_19 . V_32 = V_8 -> V_32 ;
V_2 -> V_19 . V_8 = V_8 ;
V_2 -> V_144 = V_208 ;
V_8 -> V_9 . V_10 = V_208 ;
F_121 ( V_8 ) ;
F_134 ( & V_2 -> V_139 , & V_209 ) ;
return 0 ;
V_202:
F_114 ( V_2 ) ;
V_201:
return - V_210 ;
}
int F_135 ( struct V_27 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
int V_48 ;
if ( ! V_2 || ! F_21 ( V_2 ) )
return - 1 ;
F_60 ( V_2 ) ;
V_48 = F_40 ( V_2 ) ;
if ( ( V_48 == - 1 ) ||
( ( V_48 & 0xF0 ) <= F_1 ( V_2 , V_69 ) ) )
return - 1 ;
return V_48 ;
}
int F_136 ( struct V_27 * V_8 )
{
T_1 V_211 = F_1 ( V_8 -> V_9 . V_2 , V_171 ) ;
int V_212 = 0 ;
if ( ! F_19 ( V_8 -> V_9 . V_2 ) )
V_212 = 1 ;
if ( ( V_211 & V_16 ) == 0 &&
F_137 ( V_211 ) == V_193 )
V_212 = 1 ;
return V_212 ;
}
void F_138 ( struct V_27 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
if ( V_2 && F_127 ( & V_2 -> V_19 . V_153 ) > 0 ) {
if ( F_128 ( V_2 , V_18 ) )
F_139 ( & V_2 -> V_19 . V_153 ) ;
}
}
int F_140 ( struct V_27 * V_8 )
{
int V_52 = F_135 ( V_8 ) ;
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
if ( V_52 == - 1 )
return - 1 ;
F_42 ( V_52 , V_2 ) ;
F_60 ( V_2 ) ;
F_41 ( V_52 , V_2 ) ;
return V_52 ;
}
void F_141 ( struct V_27 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
V_2 -> V_144 = V_8 -> V_9 . V_10 &
V_192 ;
F_29 ( V_8 ) ;
F_60 ( V_2 ) ;
F_109 ( & V_2 -> V_19 . V_122 ) ;
F_97 ( V_2 ) ;
F_98 ( V_2 ) ;
V_2 -> V_42 = true ;
V_2 -> V_46 = F_36 ( V_2 -> V_4 + V_45 ) ;
V_2 -> V_47 = - 1 ;
F_61 ( V_71 , V_8 ) ;
}
void F_142 ( struct V_27 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
struct V_213 * V_122 ;
if ( ! V_2 )
return;
V_122 = & V_2 -> V_19 . V_122 ;
if ( F_109 ( V_122 ) )
F_143 ( V_122 , V_158 ) ;
}
static void F_144 ( struct V_27 * V_8 ,
struct V_1 * V_2 )
{
bool V_153 ;
int V_52 ;
F_43 ( ! F_52 ( V_8 ) ) ;
V_153 = F_53 ( V_8 ) ;
F_57 ( V_8 ) ;
if ( V_153 )
return;
V_52 = F_73 ( V_2 ) ;
F_145 ( V_2 , V_52 ) ;
}
void F_146 ( struct V_27 * V_8 )
{
T_1 V_56 ;
void * V_214 ;
if ( F_10 ( V_61 , & V_8 -> V_9 . V_62 ) )
F_144 ( V_8 , V_8 -> V_9 . V_2 ) ;
if ( ! F_10 ( V_215 , & V_8 -> V_9 . V_62 ) )
return;
V_214 = F_147 ( V_8 -> V_9 . V_2 -> V_216 ) ;
V_56 = * ( T_1 * ) ( V_214 + F_148 ( V_8 -> V_9 . V_2 -> V_217 ) ) ;
F_149 ( V_214 ) ;
F_62 ( V_8 -> V_9 . V_2 , V_56 & 0xff ) ;
}
static void F_150 ( struct V_27 * V_8 ,
struct V_1 * V_2 )
{
if ( ! F_52 ( V_8 ) ||
V_2 -> V_42 ||
V_2 -> V_47 == - 1 ||
F_75 ( V_8 -> V_32 , V_2 -> V_47 ) ) {
return;
}
F_55 ( V_2 -> V_8 ) ;
}
void F_151 ( struct V_27 * V_8 )
{
T_1 V_56 , V_64 ;
int V_218 , V_219 ;
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
void * V_214 ;
F_150 ( V_8 , V_2 ) ;
if ( ! F_10 ( V_215 , & V_8 -> V_9 . V_62 ) )
return;
V_64 = F_1 ( V_2 , V_70 ) & 0xff ;
V_218 = F_40 ( V_2 ) ;
if ( V_218 < 0 )
V_218 = 0 ;
V_219 = F_59 ( V_2 ) ;
if ( V_219 < 0 )
V_219 = 0 ;
V_56 = ( V_64 & 0xff ) | ( ( V_219 & 0xf0 ) << 8 ) | ( V_218 << 24 ) ;
V_214 = F_147 ( V_8 -> V_9 . V_2 -> V_216 ) ;
* ( T_1 * ) ( V_214 + F_148 ( V_8 -> V_9 . V_2 -> V_217 ) ) = V_56 ;
F_149 ( V_214 ) ;
}
void F_152 ( struct V_27 * V_8 , T_7 V_217 )
{
V_8 -> V_9 . V_2 -> V_217 = V_217 ;
if ( V_217 )
F_56 ( V_215 , & V_8 -> V_9 . V_62 ) ;
else
F_58 ( V_215 , & V_8 -> V_9 . V_62 ) ;
}
int F_153 ( struct V_27 * V_8 , T_1 V_220 , T_6 V_56 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
T_1 V_173 = ( V_220 - V_221 ) << 4 ;
if ( ! F_30 ( V_8 -> V_32 ) || ! F_32 ( V_2 ) )
return 1 ;
if ( V_220 == 0x830 )
F_107 ( V_2 , V_111 , ( T_1 ) ( V_56 >> 32 ) ) ;
return F_107 ( V_2 , V_173 , ( T_1 ) V_56 ) ;
}
int F_154 ( struct V_27 * V_8 , T_1 V_220 , T_6 * V_56 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
T_1 V_173 = ( V_220 - V_221 ) << 4 , V_222 , V_223 = 0 ;
if ( ! F_30 ( V_8 -> V_32 ) || ! F_32 ( V_2 ) )
return 1 ;
if ( F_93 ( V_2 , V_173 , 4 , & V_222 ) )
return 1 ;
if ( V_220 == 0x830 )
F_93 ( V_2 , V_111 , 4 , & V_223 ) ;
* V_56 = ( ( ( T_6 ) V_223 ) << 32 ) | V_222 ;
return 0 ;
}
int F_155 ( struct V_27 * V_8 , T_1 V_173 , T_6 V_56 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
if ( ! F_30 ( V_8 -> V_32 ) )
return 1 ;
if ( V_173 == V_109 )
F_107 ( V_2 , V_111 , ( T_1 ) ( V_56 >> 32 ) ) ;
return F_107 ( V_2 , V_173 , ( T_1 ) V_56 ) ;
}
int F_156 ( struct V_27 * V_8 , T_1 V_173 , T_6 * V_56 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
T_1 V_222 , V_223 = 0 ;
if ( ! F_30 ( V_8 -> V_32 ) )
return 1 ;
if ( F_93 ( V_2 , V_173 , 4 , & V_222 ) )
return 1 ;
if ( V_173 == V_109 )
F_93 ( V_2 , V_111 , 4 , & V_223 ) ;
* V_56 = ( ( ( T_6 ) V_223 ) << 32 ) | V_222 ;
return 0 ;
}
int F_157 ( struct V_27 * V_8 , T_6 V_56 )
{
T_6 V_143 = V_56 & ~ V_58 ;
if ( ! F_158 ( V_143 , 4 ) )
return 1 ;
V_8 -> V_9 . V_55 . V_57 = V_56 ;
if ( ! F_52 ( V_8 ) )
return 0 ;
return F_159 ( V_8 -> V_32 , & V_8 -> V_9 . V_55 . V_56 ,
V_143 ) ;
}
