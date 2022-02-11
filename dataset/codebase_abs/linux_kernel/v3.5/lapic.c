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
static inline int F_15 ( struct V_1 * V_2 )
{
return ( V_2 ) -> V_8 -> V_9 . V_10 & V_11 ;
}
static inline int F_16 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_12 ) & V_13 ;
}
static inline int F_17 ( struct V_1 * V_2 )
{
return F_16 ( V_2 ) && F_15 ( V_2 ) ;
}
static inline int F_18 ( struct V_1 * V_2 )
{
return ( F_1 ( V_2 , V_14 ) >> 24 ) & 0xff ;
}
static inline int F_19 ( struct V_1 * V_2 , int V_15 )
{
return ! ( F_1 ( V_2 , V_15 ) & V_16 ) ;
}
static inline int F_20 ( struct V_1 * V_2 , int V_15 )
{
return F_1 ( V_2 , V_15 ) & V_17 ;
}
static inline int F_21 ( struct V_1 * V_2 )
{
return ( ( F_1 ( V_2 , V_18 ) &
V_2 -> V_19 . V_20 ) == V_21 ) ;
}
static inline int F_22 ( struct V_1 * V_2 )
{
return ( ( F_1 ( V_2 , V_18 ) &
V_2 -> V_19 . V_20 ) == V_22 ) ;
}
static inline int F_23 ( struct V_1 * V_2 )
{
return ( ( F_1 ( V_2 , V_18 ) &
V_2 -> V_19 . V_20 ) ==
V_23 ) ;
}
static inline int F_24 ( T_1 V_24 )
{
return ( V_24 & ( V_25 | V_16 ) ) == V_26 ;
}
void F_25 ( struct V_27 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
struct V_28 * V_29 ;
T_1 V_30 = V_31 ;
if ( ! F_26 ( V_8 -> V_32 ) )
return;
V_29 = F_27 ( V_2 -> V_8 , 0x1 , 0 ) ;
if ( V_29 && ( V_29 -> V_33 & ( 1 << ( V_34 & 31 ) ) ) )
V_30 |= V_35 ;
F_2 ( V_2 , V_36 , V_30 ) ;
}
static inline int F_28 ( struct V_1 * V_2 )
{
return V_2 -> V_8 -> V_9 . V_10 & V_37 ;
}
static int F_29 ( void * V_7 )
{
T_1 * V_38 = V_7 ;
int V_39 = V_40 >> 5 ;
while ( ( V_39 != 0 ) && ( V_38 [ ( -- V_39 ) << 2 ] == 0 ) )
continue;
if ( F_30 ( ! V_39 && ! V_38 [ 0 ] ) )
return - 1 ;
else
return F_31 ( V_38 [ V_39 << 2 ] ) - 1 + ( V_39 << 5 ) ;
}
static inline int F_32 ( int V_6 , struct V_1 * V_2 )
{
V_2 -> V_41 = true ;
return F_3 ( V_6 , V_2 -> V_4 + V_42 ) ;
}
static inline int F_33 ( struct V_1 * V_2 )
{
return F_29 ( V_2 -> V_4 + V_42 ) ;
}
static inline int F_34 ( struct V_1 * V_2 )
{
int V_43 ;
if ( ! V_2 -> V_41 )
return - 1 ;
V_43 = F_33 ( V_2 ) ;
ASSERT ( V_43 == - 1 || V_43 >= 16 ) ;
return V_43 ;
}
static inline void F_35 ( int V_6 , struct V_1 * V_2 )
{
V_2 -> V_41 = false ;
F_13 ( V_6 , V_2 -> V_4 + V_42 ) ;
if ( F_33 ( V_2 ) != - 1 )
V_2 -> V_41 = true ;
}
int F_36 ( struct V_27 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
int V_44 ;
if ( ! V_2 )
return 0 ;
V_44 = F_34 ( V_2 ) ;
return V_44 ;
}
int F_37 ( struct V_27 * V_8 , struct V_45 * V_46 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
return F_38 ( V_2 , V_46 -> V_47 , V_46 -> V_48 ,
V_46 -> V_49 , V_46 -> V_50 ) ;
}
static inline int F_39 ( struct V_1 * V_2 )
{
int V_43 ;
V_43 = F_29 ( V_2 -> V_4 + V_51 ) ;
ASSERT ( V_43 == - 1 || V_43 >= 16 ) ;
return V_43 ;
}
static void F_40 ( struct V_1 * V_2 )
{
T_1 V_52 , V_53 , V_54 , V_55 ;
int V_56 ;
V_55 = F_1 ( V_2 , V_57 ) ;
V_52 = F_1 ( V_2 , V_58 ) ;
V_56 = F_39 ( V_2 ) ;
V_53 = ( V_56 != - 1 ) ? V_56 : 0 ;
if ( ( V_52 & 0xf0 ) >= ( V_53 & 0xf0 ) )
V_54 = V_52 & 0xff ;
else
V_54 = V_53 & 0xf0 ;
F_41 ( L_1 ,
V_2 , V_54 , V_56 , V_53 ) ;
if ( V_55 != V_54 ) {
F_2 ( V_2 , V_57 , V_54 ) ;
if ( V_54 < V_55 )
F_42 ( V_59 , V_2 -> V_8 ) ;
}
}
static void F_43 ( struct V_1 * V_2 , T_1 V_52 )
{
F_2 ( V_2 , V_58 , V_52 ) ;
F_40 ( V_2 ) ;
}
int F_44 ( struct V_1 * V_2 , T_2 V_60 )
{
return V_60 == 0xff || F_18 ( V_2 ) == V_60 ;
}
int F_45 ( struct V_1 * V_2 , T_3 V_61 )
{
int V_43 = 0 ;
T_1 V_62 ;
if ( F_28 ( V_2 ) ) {
V_62 = F_1 ( V_2 , V_63 ) ;
return V_62 & V_61 ;
}
V_62 = F_46 ( F_1 ( V_2 , V_63 ) ) ;
switch ( F_1 ( V_2 , V_64 ) ) {
case V_65 :
if ( V_62 & V_61 )
V_43 = 1 ;
break;
case V_66 :
if ( ( ( V_62 >> 4 ) == ( V_61 >> 0x4 ) )
&& ( V_62 & V_61 & 0xf ) )
V_43 = 1 ;
break;
default:
F_41 ( L_2 ,
V_2 -> V_8 -> V_67 , F_1 ( V_2 , V_64 ) ) ;
break;
}
return V_43 ;
}
int F_47 ( struct V_27 * V_8 , struct V_1 * V_68 ,
int V_69 , int V_60 , int V_70 )
{
int V_43 = 0 ;
struct V_1 * V_71 = V_8 -> V_9 . V_2 ;
F_41 ( L_3
L_4 ,
V_71 , V_68 , V_60 , V_70 , V_69 ) ;
ASSERT ( V_71 ) ;
switch ( V_69 ) {
case V_72 :
if ( V_70 == 0 )
V_43 = F_44 ( V_71 , V_60 ) ;
else
V_43 = F_45 ( V_71 , V_60 ) ;
break;
case V_73 :
V_43 = ( V_71 == V_68 ) ;
break;
case V_74 :
V_43 = 1 ;
break;
case V_75 :
V_43 = ( V_71 != V_68 ) ;
break;
default:
F_41 ( L_5 ,
V_69 ) ;
break;
}
return V_43 ;
}
static int F_38 ( struct V_1 * V_2 , int V_47 ,
int V_48 , int V_49 , int V_50 )
{
int V_43 = 0 ;
struct V_27 * V_8 = V_2 -> V_8 ;
switch ( V_47 ) {
case V_76 :
V_8 -> V_9 . V_77 ++ ;
case V_78 :
if ( F_48 ( ! F_17 ( V_2 ) ) )
break;
if ( V_50 ) {
F_41 ( L_6 , V_48 ) ;
F_11 ( V_48 , V_2 -> V_4 + V_79 ) ;
} else
F_13 ( V_48 , V_2 -> V_4 + V_79 ) ;
V_43 = ! F_32 ( V_48 , V_2 ) ;
F_49 ( V_8 -> V_67 , V_47 ,
V_50 , V_48 , ! V_43 ) ;
if ( ! V_43 ) {
if ( V_50 )
F_41 ( L_7
L_8 , V_48 ) ;
break;
}
F_42 ( V_59 , V_8 ) ;
F_50 ( V_8 ) ;
break;
case V_80 :
F_41 ( L_9 ) ;
break;
case V_81 :
F_41 ( L_10 ) ;
break;
case V_26 :
V_43 = 1 ;
F_51 ( V_8 ) ;
F_50 ( V_8 ) ;
break;
case V_82 :
if ( ! V_50 || V_49 ) {
V_43 = 1 ;
V_8 -> V_9 . V_83 = V_84 ;
F_42 ( V_59 , V_8 ) ;
F_50 ( V_8 ) ;
} else {
F_41 ( L_11 ,
V_8 -> V_67 ) ;
}
break;
case V_85 :
F_41 ( L_12 ,
V_8 -> V_67 , V_48 ) ;
if ( V_8 -> V_9 . V_83 == V_84 ) {
V_43 = 1 ;
V_8 -> V_9 . V_86 = V_48 ;
V_8 -> V_9 . V_83 = V_87 ;
F_42 ( V_59 , V_8 ) ;
F_50 ( V_8 ) ;
}
break;
case V_88 :
break;
default:
F_52 ( V_89 L_13 ,
V_47 ) ;
break;
}
return V_43 ;
}
int F_53 ( struct V_27 * V_90 , struct V_27 * V_91 )
{
return V_90 -> V_9 . V_77 - V_91 -> V_9 . V_77 ;
}
static void F_54 ( struct V_1 * V_2 )
{
int V_48 = F_39 ( V_2 ) ;
if ( V_48 == - 1 )
return;
F_13 ( V_48 , V_2 -> V_4 + V_51 ) ;
F_40 ( V_2 ) ;
if ( ! ( F_1 ( V_2 , V_12 ) & V_92 ) &&
F_55 ( V_2 -> V_8 -> V_32 , V_48 ) ) {
int V_93 ;
if ( F_9 ( V_48 , V_2 -> V_4 + V_79 ) )
V_93 = V_94 ;
else
V_93 = V_95 ;
F_56 ( V_2 -> V_8 -> V_32 , V_48 , V_93 ) ;
}
F_42 ( V_59 , V_2 -> V_8 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
T_1 V_96 = F_1 ( V_2 , V_97 ) ;
T_1 V_98 = F_1 ( V_2 , V_99 ) ;
struct V_45 V_46 ;
V_46 . V_48 = V_96 & V_17 ;
V_46 . V_47 = V_96 & V_25 ;
V_46 . V_70 = V_96 & V_100 ;
V_46 . V_49 = V_96 & V_101 ;
V_46 . V_50 = V_96 & V_102 ;
V_46 . V_103 = V_96 & V_104 ;
if ( F_28 ( V_2 ) )
V_46 . V_105 = V_98 ;
else
V_46 . V_105 = F_58 ( V_98 ) ;
F_59 ( V_96 , V_46 . V_105 ) ;
F_41 ( L_14
L_15
L_16 ,
V_98 , V_96 , V_46 . V_103 , V_46 . V_105 ,
V_46 . V_50 , V_46 . V_49 , V_46 . V_70 , V_46 . V_47 ,
V_46 . V_48 ) ;
F_60 ( V_2 -> V_8 -> V_32 , V_2 , & V_46 ) ;
}
static T_1 F_61 ( struct V_1 * V_2 )
{
T_4 V_106 ;
T_5 V_107 ;
T_1 V_108 ;
ASSERT ( V_2 != NULL ) ;
if ( F_1 ( V_2 , V_109 ) == 0 )
return 0 ;
V_106 = F_62 ( & V_2 -> V_19 . V_110 ) ;
if ( F_63 ( V_106 ) < 0 )
V_106 = F_64 ( 0 , 0 ) ;
V_107 = F_65 ( F_63 ( V_106 ) , V_2 -> V_19 . V_111 ) ;
V_108 = F_66 ( V_107 ,
( V_112 * V_2 -> V_113 ) ) ;
return V_108 ;
}
static void F_67 ( struct V_1 * V_2 , bool V_114 )
{
struct V_27 * V_8 = V_2 -> V_8 ;
struct V_115 * V_116 = V_8 -> V_116 ;
F_42 ( V_117 , V_8 ) ;
V_116 -> V_118 . V_119 = F_68 ( V_8 ) ;
V_116 -> V_118 . V_120 = V_114 ;
}
static inline void F_69 ( struct V_1 * V_2 , bool V_114 )
{
if ( V_2 -> V_8 -> V_9 . V_121 )
F_67 ( V_2 , V_114 ) ;
}
static T_1 F_70 ( struct V_1 * V_2 , unsigned int V_122 )
{
T_1 V_5 = 0 ;
if ( V_122 >= V_123 )
return 0 ;
switch ( V_122 ) {
case V_14 :
if ( F_28 ( V_2 ) )
V_5 = F_18 ( V_2 ) ;
else
V_5 = F_18 ( V_2 ) << 24 ;
break;
case V_124 :
F_41 ( L_17 ) ;
break;
case V_125 :
if ( F_23 ( V_2 ) )
return 0 ;
V_5 = F_61 ( V_2 ) ;
break;
case V_58 :
F_69 ( V_2 , false ) ;
default:
F_40 ( V_2 ) ;
V_5 = F_1 ( V_2 , V_122 ) ;
break;
}
return V_5 ;
}
static inline struct V_1 * F_71 ( struct V_126 * V_127 )
{
return F_72 ( V_127 , struct V_1 , V_127 ) ;
}
static int F_73 ( struct V_1 * V_2 , T_1 V_122 , int V_128 ,
void * V_129 )
{
unsigned char V_130 = V_122 & 0xf ;
T_1 V_43 ;
static const T_6 V_131 = 0x43ff01ffffffe70cULL ;
if ( ( V_130 + V_128 ) > 4 ) {
F_41 ( L_18 ,
V_122 , V_128 ) ;
return 1 ;
}
if ( V_122 > 0x3f0 || ! ( V_131 & ( 1ULL << ( V_122 >> 4 ) ) ) ) {
F_41 ( L_19 ,
V_122 ) ;
return 1 ;
}
V_43 = F_70 ( V_2 , V_122 & ~ 0xf ) ;
F_74 ( V_122 , V_43 ) ;
switch ( V_128 ) {
case 1 :
case 2 :
case 4 :
memcpy ( V_129 , ( char * ) & V_43 + V_130 , V_128 ) ;
break;
default:
F_52 ( V_89 L_20
L_21 , V_128 ) ;
break;
}
return 0 ;
}
static int F_75 ( struct V_1 * V_2 , T_7 V_132 )
{
return F_15 ( V_2 ) &&
V_132 >= V_2 -> V_133 &&
V_132 < V_2 -> V_133 + V_123 ;
}
static int F_76 ( struct V_126 * V_134 ,
T_7 V_135 , int V_128 , void * V_129 )
{
struct V_1 * V_2 = F_71 ( V_134 ) ;
T_1 V_122 = V_135 - V_2 -> V_133 ;
if ( ! F_75 ( V_2 , V_135 ) )
return - V_136 ;
F_73 ( V_2 , V_122 , V_128 , V_129 ) ;
return 0 ;
}
static void F_77 ( struct V_1 * V_2 )
{
T_1 V_137 , V_138 , V_139 ;
V_139 = F_1 ( V_2 , V_140 ) ;
V_137 = V_139 & 0xf ;
V_138 = ( ( V_137 & 0x3 ) | ( ( V_137 & 0x8 ) >> 1 ) ) + 1 ;
V_2 -> V_113 = 0x1 << ( V_138 & 0x7 ) ;
F_41 ( L_22 ,
V_2 -> V_113 ) ;
}
static void F_78 ( struct V_1 * V_2 )
{
T_4 V_141 ;
F_79 ( & V_2 -> V_19 . V_142 , 0 ) ;
if ( F_22 ( V_2 ) || F_21 ( V_2 ) ) {
V_141 = V_2 -> V_19 . V_110 . V_143 -> V_144 () ;
V_2 -> V_19 . V_111 = ( T_6 ) F_1 ( V_2 , V_109 )
* V_112 * V_2 -> V_113 ;
if ( ! V_2 -> V_19 . V_111 )
return;
if ( F_22 ( V_2 ) ) {
T_5 V_145 = V_146 * 1000LL ;
if ( V_2 -> V_19 . V_111 < V_145 ) {
F_80 (
L_23
L_24 ,
V_2 -> V_8 -> V_67 ,
V_2 -> V_19 . V_111 , V_145 ) ;
V_2 -> V_19 . V_111 = V_145 ;
}
}
F_81 ( & V_2 -> V_19 . V_110 ,
F_82 ( V_141 , V_2 -> V_19 . V_111 ) ,
V_147 ) ;
F_41 ( L_25 V_148 L_26
V_149 L_27
L_28
L_29 V_149 L_30 , V_150 ,
V_112 , F_63 ( V_141 ) ,
F_1 ( V_2 , V_109 ) ,
V_2 -> V_19 . V_111 ,
F_63 ( F_82 ( V_141 ,
V_2 -> V_19 . V_111 ) ) ) ;
} else if ( F_23 ( V_2 ) ) {
T_6 V_151 , V_152 = V_2 -> V_19 . V_152 ;
T_6 V_107 = 0 ;
struct V_27 * V_8 = V_2 -> V_8 ;
unsigned long V_153 = V_8 -> V_9 . V_154 ;
unsigned long V_155 ;
if ( F_48 ( ! V_152 || ! V_153 ) )
return;
F_83 ( V_155 ) ;
V_141 = V_2 -> V_19 . V_110 . V_143 -> V_144 () ;
V_151 = V_156 -> V_157 ( V_8 ) ;
if ( F_30 ( V_152 > V_151 ) ) {
V_107 = ( V_152 - V_151 ) * 1000000ULL ;
F_84 ( V_107 , V_153 ) ;
}
F_81 ( & V_2 -> V_19 . V_110 ,
F_82 ( V_141 , V_107 ) , V_147 ) ;
F_85 ( V_155 ) ;
}
}
static void F_86 ( struct V_1 * V_2 , T_1 V_158 )
{
int V_159 = F_24 ( F_1 ( V_2 , V_160 ) ) ;
if ( F_24 ( V_158 ) ) {
if ( ! V_159 ) {
F_41 ( L_31
L_32 , V_2 -> V_8 -> V_67 ) ;
V_2 -> V_8 -> V_32 -> V_9 . V_161 ++ ;
}
} else if ( V_159 )
V_2 -> V_8 -> V_32 -> V_9 . V_161 -- ;
}
static int F_87 ( struct V_1 * V_2 , T_1 V_162 , T_1 V_5 )
{
int V_163 = 0 ;
F_88 ( V_162 , V_5 ) ;
switch ( V_162 ) {
case V_14 :
if ( ! F_28 ( V_2 ) )
F_2 ( V_2 , V_14 , V_5 ) ;
else
V_163 = 1 ;
break;
case V_58 :
F_69 ( V_2 , true ) ;
F_43 ( V_2 , V_5 & 0xff ) ;
break;
case V_164 :
F_54 ( V_2 ) ;
break;
case V_63 :
if ( ! F_28 ( V_2 ) )
F_2 ( V_2 , V_63 , V_5 & V_165 ) ;
else
V_163 = 1 ;
break;
case V_64 :
if ( ! F_28 ( V_2 ) )
F_2 ( V_2 , V_64 , V_5 | 0x0FFFFFFF ) ;
else
V_163 = 1 ;
break;
case V_12 : {
T_1 V_166 = 0x3ff ;
if ( F_1 ( V_2 , V_36 ) & V_35 )
V_166 |= V_92 ;
F_2 ( V_2 , V_12 , V_5 & V_166 ) ;
if ( ! ( V_5 & V_13 ) ) {
int V_167 ;
T_1 V_24 ;
for ( V_167 = 0 ; V_167 < V_168 ; V_167 ++ ) {
V_24 = F_1 ( V_2 ,
V_18 + 0x10 * V_167 ) ;
F_2 ( V_2 , V_18 + 0x10 * V_167 ,
V_24 | V_16 ) ;
}
F_79 ( & V_2 -> V_19 . V_142 , 0 ) ;
}
break;
}
case V_97 :
F_2 ( V_2 , V_97 , V_5 & ~ ( 1 << 12 ) ) ;
F_57 ( V_2 ) ;
break;
case V_99 :
if ( ! F_28 ( V_2 ) )
V_5 &= 0xff000000 ;
F_2 ( V_2 , V_99 , V_5 ) ;
break;
case V_160 :
F_86 ( V_2 , V_5 ) ;
case V_169 :
case V_170 :
case V_171 :
case V_172 :
if ( ! F_16 ( V_2 ) )
V_5 |= V_16 ;
V_5 &= V_173 [ ( V_162 - V_18 ) >> 4 ] ;
F_2 ( V_2 , V_162 , V_5 ) ;
break;
case V_18 :
if ( ( F_1 ( V_2 , V_18 ) &
V_2 -> V_19 . V_20 ) !=
( V_5 & V_2 -> V_19 . V_20 ) )
F_89 ( & V_2 -> V_19 . V_110 ) ;
if ( ! F_16 ( V_2 ) )
V_5 |= V_16 ;
V_5 &= ( V_173 [ 0 ] | V_2 -> V_19 . V_20 ) ;
F_2 ( V_2 , V_18 , V_5 ) ;
break;
case V_109 :
if ( F_23 ( V_2 ) )
break;
F_89 ( & V_2 -> V_19 . V_110 ) ;
F_2 ( V_2 , V_109 , V_5 ) ;
F_78 ( V_2 ) ;
break;
case V_140 :
if ( V_5 & 4 )
F_41 ( L_33 , V_5 ) ;
F_2 ( V_2 , V_140 , V_5 ) ;
F_77 ( V_2 ) ;
break;
case V_174 :
if ( F_28 ( V_2 ) && V_5 != 0 ) {
F_41 ( L_34 , V_5 ) ;
V_163 = 1 ;
}
break;
case V_175 :
if ( F_28 ( V_2 ) ) {
F_87 ( V_2 , V_97 , 0x40000 | ( V_5 & 0xff ) ) ;
} else
V_163 = 1 ;
break;
default:
V_163 = 1 ;
break;
}
if ( V_163 )
F_41 ( L_35 , V_162 ) ;
return V_163 ;
}
static int F_90 ( struct V_126 * V_134 ,
T_7 V_135 , int V_128 , const void * V_129 )
{
struct V_1 * V_2 = F_71 ( V_134 ) ;
unsigned int V_122 = V_135 - V_2 -> V_133 ;
T_1 V_5 ;
if ( ! F_75 ( V_2 , V_135 ) )
return - V_136 ;
if ( V_128 != 4 || ( V_122 & 0xf ) ) {
F_41 ( L_36 , V_128 , ( long ) V_135 ) ;
return 0 ;
}
V_5 = * ( T_1 * ) V_129 ;
if ( V_122 != V_164 )
F_41 ( L_37
L_38 , V_150 , V_122 , V_128 , V_5 ) ;
F_87 ( V_2 , V_122 & 0xff0 , V_5 ) ;
return 0 ;
}
void F_91 ( struct V_27 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
if ( V_2 )
F_87 ( V_8 -> V_9 . V_2 , V_164 , 0 ) ;
}
void F_92 ( struct V_27 * V_8 )
{
if ( ! V_8 -> V_9 . V_2 )
return;
F_89 ( & V_8 -> V_9 . V_2 -> V_19 . V_110 ) ;
if ( V_8 -> V_9 . V_2 -> V_4 )
F_93 ( ( unsigned long ) V_8 -> V_9 . V_2 -> V_4 ) ;
F_94 ( V_8 -> V_9 . V_2 ) ;
}
T_6 F_95 ( struct V_27 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
if ( ! V_2 )
return 0 ;
if ( F_21 ( V_2 ) || F_22 ( V_2 ) )
return 0 ;
return V_2 -> V_19 . V_152 ;
}
void F_96 ( struct V_27 * V_8 , T_6 V_129 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
if ( ! V_2 )
return;
if ( F_21 ( V_2 ) || F_22 ( V_2 ) )
return;
F_89 ( & V_2 -> V_19 . V_110 ) ;
V_2 -> V_19 . V_152 = V_129 ;
F_78 ( V_2 ) ;
}
void F_97 ( struct V_27 * V_8 , unsigned long V_176 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
if ( ! V_2 )
return;
F_43 ( V_2 , ( ( V_176 & 0x0f ) << 4 )
| ( F_1 ( V_2 , V_58 ) & 4 ) ) ;
}
T_6 F_98 ( struct V_27 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
T_6 V_52 ;
if ( ! V_2 )
return 0 ;
V_52 = ( T_6 ) F_1 ( V_2 , V_58 ) ;
return ( V_52 & 0xf0 ) >> 4 ;
}
void F_99 ( struct V_27 * V_8 , T_6 V_177 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
if ( ! V_2 ) {
V_177 |= V_178 ;
V_8 -> V_9 . V_10 = V_177 ;
return;
}
if ( ! F_100 ( V_2 -> V_8 ) )
V_177 &= ~ V_178 ;
V_8 -> V_9 . V_10 = V_177 ;
if ( F_28 ( V_2 ) ) {
T_1 V_179 = F_18 ( V_2 ) ;
T_1 V_180 = ( ( V_179 & ~ 0xf ) << 16 ) | ( 1 << ( V_179 & 0xf ) ) ;
F_2 ( V_2 , V_63 , V_180 ) ;
}
V_2 -> V_133 = V_2 -> V_8 -> V_9 . V_10 &
V_181 ;
F_41 ( L_39 V_149 L_40
L_41 , V_2 -> V_8 -> V_9 . V_10 , V_2 -> V_133 ) ;
}
void F_101 ( struct V_27 * V_8 )
{
struct V_1 * V_2 ;
int V_167 ;
F_41 ( L_42 , V_150 ) ;
ASSERT ( V_8 ) ;
V_2 = V_8 -> V_9 . V_2 ;
ASSERT ( V_2 != NULL ) ;
F_89 ( & V_2 -> V_19 . V_110 ) ;
F_2 ( V_2 , V_14 , V_8 -> V_67 << 24 ) ;
F_25 ( V_2 -> V_8 ) ;
for ( V_167 = 0 ; V_167 < V_168 ; V_167 ++ )
F_2 ( V_2 , V_18 + 0x10 * V_167 , V_16 ) ;
F_2 ( V_2 , V_160 ,
F_102 ( 0 , V_182 ) ) ;
F_2 ( V_2 , V_64 , 0xffffffffU ) ;
F_2 ( V_2 , V_12 , 0xff ) ;
F_2 ( V_2 , V_58 , 0 ) ;
F_2 ( V_2 , V_63 , 0 ) ;
F_2 ( V_2 , V_174 , 0 ) ;
F_2 ( V_2 , V_97 , 0 ) ;
F_2 ( V_2 , V_99 , 0 ) ;
F_2 ( V_2 , V_140 , 0 ) ;
F_2 ( V_2 , V_109 , 0 ) ;
for ( V_167 = 0 ; V_167 < 8 ; V_167 ++ ) {
F_2 ( V_2 , V_42 + 0x10 * V_167 , 0 ) ;
F_2 ( V_2 , V_51 + 0x10 * V_167 , 0 ) ;
F_2 ( V_2 , V_79 + 0x10 * V_167 , 0 ) ;
}
V_2 -> V_41 = false ;
F_77 ( V_2 ) ;
F_79 ( & V_2 -> V_19 . V_142 , 0 ) ;
if ( F_100 ( V_8 ) )
V_8 -> V_9 . V_10 |= V_178 ;
F_40 ( V_2 ) ;
V_8 -> V_9 . V_77 = 0 ;
V_8 -> V_9 . V_183 = 0 ;
F_41 ( V_184 L_43
L_44 V_149 L_45 , V_150 ,
V_8 , F_18 ( V_2 ) ,
V_8 -> V_9 . V_10 , V_2 -> V_133 ) ;
}
bool F_103 ( struct V_27 * V_8 )
{
return V_8 -> V_9 . V_2 && F_15 ( V_8 -> V_9 . V_2 ) ;
}
int F_104 ( struct V_27 * V_8 )
{
return F_103 ( V_8 ) && F_16 ( V_8 -> V_9 . V_2 ) ;
}
static bool F_105 ( struct V_185 * V_186 )
{
struct V_1 * V_2 = F_72 ( V_186 , struct V_1 ,
V_19 ) ;
return F_22 ( V_2 ) ;
}
int F_106 ( struct V_27 * V_8 )
{
struct V_1 * V_187 = V_8 -> V_9 . V_2 ;
if ( V_187 && F_17 ( V_187 ) && F_19 ( V_187 , V_18 ) )
return F_107 ( & V_187 -> V_19 . V_142 ) ;
return 0 ;
}
int F_108 ( struct V_1 * V_2 , int V_15 )
{
T_1 V_162 = F_1 ( V_2 , V_15 ) ;
int V_48 , V_188 , V_50 ;
if ( F_15 ( V_2 ) && ! ( V_162 & V_16 ) ) {
V_48 = V_162 & V_17 ;
V_188 = V_162 & V_25 ;
V_50 = V_162 & V_189 ;
return F_38 ( V_2 , V_188 , V_48 , 1 , V_50 ) ;
}
return 0 ;
}
void F_109 ( struct V_27 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
if ( V_2 )
F_108 ( V_2 , V_160 ) ;
}
int F_110 ( struct V_27 * V_8 )
{
struct V_1 * V_2 ;
ASSERT ( V_8 != NULL ) ;
F_41 ( L_46 , V_8 -> V_67 ) ;
V_2 = F_111 ( sizeof( * V_2 ) , V_190 ) ;
if ( ! V_2 )
goto V_191;
V_8 -> V_9 . V_2 = V_2 ;
V_2 -> V_4 = ( void * ) F_112 ( V_190 ) ;
if ( ! V_2 -> V_4 ) {
F_52 ( V_89 L_47 ,
V_8 -> V_67 ) ;
goto V_192;
}
V_2 -> V_8 = V_8 ;
F_113 ( & V_2 -> V_19 . V_110 , V_193 ,
V_147 ) ;
V_2 -> V_19 . V_110 . V_194 = V_195 ;
V_2 -> V_19 . V_196 = & V_197 ;
V_2 -> V_19 . V_32 = V_8 -> V_32 ;
V_2 -> V_19 . V_8 = V_8 ;
V_2 -> V_133 = V_198 ;
V_8 -> V_9 . V_10 = V_198 ;
F_101 ( V_8 ) ;
F_114 ( & V_2 -> V_127 , & V_199 ) ;
return 0 ;
V_192:
F_94 ( V_2 ) ;
V_191:
return - V_200 ;
}
int F_115 ( struct V_27 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
int V_44 ;
if ( ! V_2 || ! F_17 ( V_2 ) )
return - 1 ;
F_40 ( V_2 ) ;
V_44 = F_34 ( V_2 ) ;
if ( ( V_44 == - 1 ) ||
( ( V_44 & 0xF0 ) <= F_1 ( V_2 , V_57 ) ) )
return - 1 ;
return V_44 ;
}
int F_116 ( struct V_27 * V_8 )
{
T_1 V_201 = F_1 ( V_8 -> V_9 . V_2 , V_160 ) ;
int V_202 = 0 ;
if ( ! F_15 ( V_8 -> V_9 . V_2 ) )
V_202 = 1 ;
if ( ( V_201 & V_16 ) == 0 &&
F_117 ( V_201 ) == V_182 )
V_202 = 1 ;
return V_202 ;
}
void F_118 ( struct V_27 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
if ( V_2 && F_107 ( & V_2 -> V_19 . V_142 ) > 0 ) {
if ( F_108 ( V_2 , V_18 ) )
F_119 ( & V_2 -> V_19 . V_142 ) ;
}
}
int F_120 ( struct V_27 * V_8 )
{
int V_48 = F_115 ( V_8 ) ;
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
if ( V_48 == - 1 )
return - 1 ;
F_11 ( V_48 , V_2 -> V_4 + V_51 ) ;
F_40 ( V_2 ) ;
F_35 ( V_48 , V_2 ) ;
return V_48 ;
}
void F_121 ( struct V_27 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
V_2 -> V_133 = V_8 -> V_9 . V_10 &
V_181 ;
F_25 ( V_8 ) ;
F_40 ( V_2 ) ;
F_89 ( & V_2 -> V_19 . V_110 ) ;
F_77 ( V_2 ) ;
F_78 ( V_2 ) ;
V_2 -> V_41 = true ;
F_42 ( V_59 , V_8 ) ;
}
void F_122 ( struct V_27 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
struct V_203 * V_110 ;
if ( ! V_2 )
return;
V_110 = & V_2 -> V_19 . V_110 ;
if ( F_89 ( V_110 ) )
F_123 ( V_110 , V_147 ) ;
}
void F_124 ( struct V_27 * V_8 )
{
T_1 V_129 ;
void * V_204 ;
if ( ! F_10 ( V_205 , & V_8 -> V_9 . V_183 ) )
return;
V_204 = F_125 ( V_8 -> V_9 . V_2 -> V_206 ) ;
V_129 = * ( T_1 * ) ( V_204 + F_126 ( V_8 -> V_9 . V_2 -> V_207 ) ) ;
F_127 ( V_204 ) ;
F_43 ( V_8 -> V_9 . V_2 , V_129 & 0xff ) ;
}
void F_128 ( struct V_27 * V_8 )
{
T_1 V_129 , V_52 ;
int V_208 , V_209 ;
struct V_1 * V_2 ;
void * V_204 ;
if ( ! F_10 ( V_205 , & V_8 -> V_9 . V_183 ) )
return;
V_2 = V_8 -> V_9 . V_2 ;
V_52 = F_1 ( V_2 , V_58 ) & 0xff ;
V_208 = F_34 ( V_2 ) ;
if ( V_208 < 0 )
V_208 = 0 ;
V_209 = F_39 ( V_2 ) ;
if ( V_209 < 0 )
V_209 = 0 ;
V_129 = ( V_52 & 0xff ) | ( ( V_209 & 0xf0 ) << 8 ) | ( V_208 << 24 ) ;
V_204 = F_125 ( V_8 -> V_9 . V_2 -> V_206 ) ;
* ( T_1 * ) ( V_204 + F_126 ( V_8 -> V_9 . V_2 -> V_207 ) ) = V_129 ;
F_127 ( V_204 ) ;
}
void F_129 ( struct V_27 * V_8 , T_7 V_207 )
{
V_8 -> V_9 . V_2 -> V_207 = V_207 ;
if ( V_207 )
F_130 ( V_205 , & V_8 -> V_9 . V_183 ) ;
else
F_131 ( V_205 , & V_8 -> V_9 . V_183 ) ;
}
int F_132 ( struct V_27 * V_8 , T_1 V_210 , T_6 V_129 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
T_1 V_162 = ( V_210 - V_211 ) << 4 ;
if ( ! F_26 ( V_8 -> V_32 ) || ! F_28 ( V_2 ) )
return 1 ;
if ( V_210 == 0x830 )
F_87 ( V_2 , V_99 , ( T_1 ) ( V_129 >> 32 ) ) ;
return F_87 ( V_2 , V_162 , ( T_1 ) V_129 ) ;
}
int F_133 ( struct V_27 * V_8 , T_1 V_210 , T_6 * V_129 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
T_1 V_162 = ( V_210 - V_211 ) << 4 , V_212 , V_213 = 0 ;
if ( ! F_26 ( V_8 -> V_32 ) || ! F_28 ( V_2 ) )
return 1 ;
if ( F_73 ( V_2 , V_162 , 4 , & V_212 ) )
return 1 ;
if ( V_210 == 0x830 )
F_73 ( V_2 , V_99 , 4 , & V_213 ) ;
* V_129 = ( ( ( T_6 ) V_213 ) << 32 ) | V_212 ;
return 0 ;
}
int F_134 ( struct V_27 * V_8 , T_1 V_162 , T_6 V_129 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
if ( ! F_26 ( V_8 -> V_32 ) )
return 1 ;
if ( V_162 == V_97 )
F_87 ( V_2 , V_99 , ( T_1 ) ( V_129 >> 32 ) ) ;
return F_87 ( V_2 , V_162 , ( T_1 ) V_129 ) ;
}
int F_135 ( struct V_27 * V_8 , T_1 V_162 , T_6 * V_129 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
T_1 V_212 , V_213 = 0 ;
if ( ! F_26 ( V_8 -> V_32 ) )
return 1 ;
if ( F_73 ( V_2 , V_162 , 4 , & V_212 ) )
return 1 ;
if ( V_162 == V_97 )
F_73 ( V_2 , V_99 , 4 , & V_213 ) ;
* V_129 = ( ( ( T_6 ) V_213 ) << 32 ) | V_212 ;
return 0 ;
}
