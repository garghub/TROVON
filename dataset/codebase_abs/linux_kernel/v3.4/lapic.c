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
static inline void F_9 ( int V_6 , void * V_7 )
{
F_10 ( F_5 ( V_6 ) , ( V_7 ) + F_6 ( V_6 ) ) ;
}
static inline void F_11 ( int V_6 , void * V_7 )
{
F_12 ( F_5 ( V_6 ) , ( V_7 ) + F_6 ( V_6 ) ) ;
}
static inline int F_13 ( struct V_1 * V_2 )
{
return ( V_2 ) -> V_8 -> V_9 . V_10 & V_11 ;
}
static inline int F_14 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_12 ) & V_13 ;
}
static inline int F_15 ( struct V_1 * V_2 )
{
return F_14 ( V_2 ) && F_13 ( V_2 ) ;
}
static inline int F_16 ( struct V_1 * V_2 )
{
return ( F_1 ( V_2 , V_14 ) >> 24 ) & 0xff ;
}
static inline int F_17 ( struct V_1 * V_2 , int V_15 )
{
return ! ( F_1 ( V_2 , V_15 ) & V_16 ) ;
}
static inline int F_18 ( struct V_1 * V_2 , int V_15 )
{
return F_1 ( V_2 , V_15 ) & V_17 ;
}
static inline int F_19 ( struct V_1 * V_2 )
{
return ( ( F_1 ( V_2 , V_18 ) &
V_2 -> V_19 . V_20 ) == V_21 ) ;
}
static inline int F_20 ( struct V_1 * V_2 )
{
return ( ( F_1 ( V_2 , V_18 ) &
V_2 -> V_19 . V_20 ) == V_22 ) ;
}
static inline int F_21 ( struct V_1 * V_2 )
{
return ( ( F_1 ( V_2 , V_18 ) &
V_2 -> V_19 . V_20 ) ==
V_23 ) ;
}
static inline int F_22 ( T_1 V_24 )
{
return ( V_24 & ( V_25 | V_16 ) ) == V_26 ;
}
void F_23 ( struct V_27 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
struct V_28 * V_29 ;
T_1 V_30 = V_31 ;
if ( ! F_24 ( V_8 -> V_32 ) )
return;
V_29 = F_25 ( V_2 -> V_8 , 0x1 , 0 ) ;
if ( V_29 && ( V_29 -> V_33 & ( 1 << ( V_34 & 31 ) ) ) )
V_30 |= V_35 ;
F_2 ( V_2 , V_36 , V_30 ) ;
}
static inline int F_26 ( struct V_1 * V_2 )
{
return V_2 -> V_8 -> V_9 . V_10 & V_37 ;
}
static int F_27 ( void * V_7 )
{
T_1 * V_38 = V_7 ;
int V_39 = V_40 >> 5 ;
while ( ( V_39 != 0 ) && ( V_38 [ ( -- V_39 ) << 2 ] == 0 ) )
continue;
if ( F_28 ( ! V_39 && ! V_38 [ 0 ] ) )
return - 1 ;
else
return F_29 ( V_38 [ V_39 << 2 ] ) - 1 + ( V_39 << 5 ) ;
}
static inline int F_30 ( int V_6 , struct V_1 * V_2 )
{
V_2 -> V_41 = true ;
return F_3 ( V_6 , V_2 -> V_4 + V_42 ) ;
}
static inline int F_31 ( struct V_1 * V_2 )
{
return F_27 ( V_2 -> V_4 + V_42 ) ;
}
static inline int F_32 ( struct V_1 * V_2 )
{
int V_43 ;
if ( ! V_2 -> V_41 )
return - 1 ;
V_43 = F_31 ( V_2 ) ;
ASSERT ( V_43 == - 1 || V_43 >= 16 ) ;
return V_43 ;
}
static inline void F_33 ( int V_6 , struct V_1 * V_2 )
{
V_2 -> V_41 = false ;
F_11 ( V_6 , V_2 -> V_4 + V_42 ) ;
if ( F_31 ( V_2 ) != - 1 )
V_2 -> V_41 = true ;
}
int F_34 ( struct V_27 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
int V_44 ;
if ( ! V_2 )
return 0 ;
V_44 = F_32 ( V_2 ) ;
return V_44 ;
}
int F_35 ( struct V_27 * V_8 , struct V_45 * V_46 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
return F_36 ( V_2 , V_46 -> V_47 , V_46 -> V_48 ,
V_46 -> V_49 , V_46 -> V_50 ) ;
}
static inline int F_37 ( struct V_1 * V_2 )
{
int V_43 ;
V_43 = F_27 ( V_2 -> V_4 + V_51 ) ;
ASSERT ( V_43 == - 1 || V_43 >= 16 ) ;
return V_43 ;
}
static void F_38 ( struct V_1 * V_2 )
{
T_1 V_52 , V_53 , V_54 , V_55 ;
int V_56 ;
V_55 = F_1 ( V_2 , V_57 ) ;
V_52 = F_1 ( V_2 , V_58 ) ;
V_56 = F_37 ( V_2 ) ;
V_53 = ( V_56 != - 1 ) ? V_56 : 0 ;
if ( ( V_52 & 0xf0 ) >= ( V_53 & 0xf0 ) )
V_54 = V_52 & 0xff ;
else
V_54 = V_53 & 0xf0 ;
F_39 ( L_1 ,
V_2 , V_54 , V_56 , V_53 ) ;
if ( V_55 != V_54 ) {
F_2 ( V_2 , V_57 , V_54 ) ;
if ( V_54 < V_55 )
F_40 ( V_59 , V_2 -> V_8 ) ;
}
}
static void F_41 ( struct V_1 * V_2 , T_1 V_52 )
{
F_2 ( V_2 , V_58 , V_52 ) ;
F_38 ( V_2 ) ;
}
int F_42 ( struct V_1 * V_2 , T_2 V_60 )
{
return V_60 == 0xff || F_16 ( V_2 ) == V_60 ;
}
int F_43 ( struct V_1 * V_2 , T_3 V_61 )
{
int V_43 = 0 ;
T_1 V_62 ;
if ( F_26 ( V_2 ) ) {
V_62 = F_1 ( V_2 , V_63 ) ;
return V_62 & V_61 ;
}
V_62 = F_44 ( F_1 ( V_2 , V_63 ) ) ;
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
F_39 ( L_2 ,
V_2 -> V_8 -> V_67 , F_1 ( V_2 , V_64 ) ) ;
break;
}
return V_43 ;
}
int F_45 ( struct V_27 * V_8 , struct V_1 * V_68 ,
int V_69 , int V_60 , int V_70 )
{
int V_43 = 0 ;
struct V_1 * V_71 = V_8 -> V_9 . V_2 ;
F_39 ( L_3
L_4 ,
V_71 , V_68 , V_60 , V_70 , V_69 ) ;
ASSERT ( V_71 ) ;
switch ( V_69 ) {
case V_72 :
if ( V_70 == 0 )
V_43 = F_42 ( V_71 , V_60 ) ;
else
V_43 = F_43 ( V_71 , V_60 ) ;
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
F_39 ( L_5 ,
V_69 ) ;
break;
}
return V_43 ;
}
static int F_36 ( struct V_1 * V_2 , int V_47 ,
int V_48 , int V_49 , int V_50 )
{
int V_43 = 0 ;
struct V_27 * V_8 = V_2 -> V_8 ;
switch ( V_47 ) {
case V_76 :
V_8 -> V_9 . V_77 ++ ;
case V_78 :
if ( F_46 ( ! F_15 ( V_2 ) ) )
break;
if ( V_50 ) {
F_39 ( L_6 , V_48 ) ;
F_9 ( V_48 , V_2 -> V_4 + V_79 ) ;
} else
F_11 ( V_48 , V_2 -> V_4 + V_79 ) ;
V_43 = ! F_30 ( V_48 , V_2 ) ;
F_47 ( V_8 -> V_67 , V_47 ,
V_50 , V_48 , ! V_43 ) ;
if ( ! V_43 ) {
if ( V_50 )
F_39 ( L_7
L_8 , V_48 ) ;
break;
}
F_40 ( V_59 , V_8 ) ;
F_48 ( V_8 ) ;
break;
case V_80 :
F_39 ( L_9 ) ;
break;
case V_81 :
F_39 ( L_10 ) ;
break;
case V_26 :
V_43 = 1 ;
F_49 ( V_8 ) ;
F_48 ( V_8 ) ;
break;
case V_82 :
if ( ! V_50 || V_49 ) {
V_43 = 1 ;
V_8 -> V_9 . V_83 = V_84 ;
F_40 ( V_59 , V_8 ) ;
F_48 ( V_8 ) ;
} else {
F_39 ( L_11 ,
V_8 -> V_67 ) ;
}
break;
case V_85 :
F_39 ( L_12 ,
V_8 -> V_67 , V_48 ) ;
if ( V_8 -> V_9 . V_83 == V_84 ) {
V_43 = 1 ;
V_8 -> V_9 . V_86 = V_48 ;
V_8 -> V_9 . V_83 = V_87 ;
F_40 ( V_59 , V_8 ) ;
F_48 ( V_8 ) ;
}
break;
case V_88 :
break;
default:
F_50 ( V_89 L_13 ,
V_47 ) ;
break;
}
return V_43 ;
}
int F_51 ( struct V_27 * V_90 , struct V_27 * V_91 )
{
return V_90 -> V_9 . V_77 - V_91 -> V_9 . V_77 ;
}
static void F_52 ( struct V_1 * V_2 )
{
int V_48 = F_37 ( V_2 ) ;
int V_92 ;
if ( V_48 == - 1 )
return;
F_11 ( V_48 , V_2 -> V_4 + V_51 ) ;
F_38 ( V_2 ) ;
if ( F_7 ( V_48 , V_2 -> V_4 + V_79 ) )
V_92 = V_93 ;
else
V_92 = V_94 ;
if ( ! ( F_1 ( V_2 , V_12 ) & V_95 ) )
F_53 ( V_2 -> V_8 -> V_32 , V_48 , V_92 ) ;
F_40 ( V_59 , V_2 -> V_8 ) ;
}
static void F_54 ( struct V_1 * V_2 )
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
if ( F_26 ( V_2 ) )
V_46 . V_105 = V_98 ;
else
V_46 . V_105 = F_55 ( V_98 ) ;
F_56 ( V_96 , V_46 . V_105 ) ;
F_39 ( L_14
L_15
L_16 ,
V_98 , V_96 , V_46 . V_103 , V_46 . V_105 ,
V_46 . V_50 , V_46 . V_49 , V_46 . V_70 , V_46 . V_47 ,
V_46 . V_48 ) ;
F_57 ( V_2 -> V_8 -> V_32 , V_2 , & V_46 ) ;
}
static T_1 F_58 ( struct V_1 * V_2 )
{
T_4 V_106 ;
T_5 V_107 ;
T_1 V_108 ;
ASSERT ( V_2 != NULL ) ;
if ( F_1 ( V_2 , V_109 ) == 0 )
return 0 ;
V_106 = F_59 ( & V_2 -> V_19 . V_110 ) ;
if ( F_60 ( V_106 ) < 0 )
V_106 = F_61 ( 0 , 0 ) ;
V_107 = F_62 ( F_60 ( V_106 ) , V_2 -> V_19 . V_111 ) ;
V_108 = F_63 ( V_107 ,
( V_112 * V_2 -> V_113 ) ) ;
return V_108 ;
}
static void F_64 ( struct V_1 * V_2 , bool V_114 )
{
struct V_27 * V_8 = V_2 -> V_8 ;
struct V_115 * V_116 = V_8 -> V_116 ;
F_40 ( V_117 , V_8 ) ;
V_116 -> V_118 . V_119 = F_65 ( V_8 ) ;
V_116 -> V_118 . V_120 = V_114 ;
}
static inline void F_66 ( struct V_1 * V_2 , bool V_114 )
{
if ( V_2 -> V_8 -> V_9 . V_121 )
F_64 ( V_2 , V_114 ) ;
}
static T_1 F_67 ( struct V_1 * V_2 , unsigned int V_122 )
{
T_1 V_5 = 0 ;
if ( V_122 >= V_123 )
return 0 ;
switch ( V_122 ) {
case V_14 :
if ( F_26 ( V_2 ) )
V_5 = F_16 ( V_2 ) ;
else
V_5 = F_16 ( V_2 ) << 24 ;
break;
case V_124 :
F_39 ( L_17 ) ;
break;
case V_125 :
if ( F_21 ( V_2 ) )
return 0 ;
V_5 = F_58 ( V_2 ) ;
break;
case V_58 :
F_66 ( V_2 , false ) ;
default:
F_38 ( V_2 ) ;
V_5 = F_1 ( V_2 , V_122 ) ;
break;
}
return V_5 ;
}
static inline struct V_1 * F_68 ( struct V_126 * V_127 )
{
return F_69 ( V_127 , struct V_1 , V_127 ) ;
}
static int F_70 ( struct V_1 * V_2 , T_1 V_122 , int V_128 ,
void * V_129 )
{
unsigned char V_130 = V_122 & 0xf ;
T_1 V_43 ;
static const T_6 V_131 = 0x43ff01ffffffe70cULL ;
if ( ( V_130 + V_128 ) > 4 ) {
F_39 ( L_18 ,
V_122 , V_128 ) ;
return 1 ;
}
if ( V_122 > 0x3f0 || ! ( V_131 & ( 1ULL << ( V_122 >> 4 ) ) ) ) {
F_39 ( L_19 ,
V_122 ) ;
return 1 ;
}
V_43 = F_67 ( V_2 , V_122 & ~ 0xf ) ;
F_71 ( V_122 , V_43 ) ;
switch ( V_128 ) {
case 1 :
case 2 :
case 4 :
memcpy ( V_129 , ( char * ) & V_43 + V_130 , V_128 ) ;
break;
default:
F_50 ( V_89 L_20
L_21 , V_128 ) ;
break;
}
return 0 ;
}
static int F_72 ( struct V_1 * V_2 , T_7 V_132 )
{
return F_13 ( V_2 ) &&
V_132 >= V_2 -> V_133 &&
V_132 < V_2 -> V_133 + V_123 ;
}
static int F_73 ( struct V_126 * V_134 ,
T_7 V_135 , int V_128 , void * V_129 )
{
struct V_1 * V_2 = F_68 ( V_134 ) ;
T_1 V_122 = V_135 - V_2 -> V_133 ;
if ( ! F_72 ( V_2 , V_135 ) )
return - V_136 ;
F_70 ( V_2 , V_122 , V_128 , V_129 ) ;
return 0 ;
}
static void F_74 ( struct V_1 * V_2 )
{
T_1 V_137 , V_138 , V_139 ;
V_139 = F_1 ( V_2 , V_140 ) ;
V_137 = V_139 & 0xf ;
V_138 = ( ( V_137 & 0x3 ) | ( ( V_137 & 0x8 ) >> 1 ) ) + 1 ;
V_2 -> V_113 = 0x1 << ( V_138 & 0x7 ) ;
F_39 ( L_22 ,
V_2 -> V_113 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
T_4 V_141 ;
F_76 ( & V_2 -> V_19 . V_142 , 0 ) ;
if ( F_20 ( V_2 ) || F_19 ( V_2 ) ) {
V_141 = V_2 -> V_19 . V_110 . V_143 -> V_144 () ;
V_2 -> V_19 . V_111 = ( T_6 ) F_1 ( V_2 , V_109 )
* V_112 * V_2 -> V_113 ;
if ( ! V_2 -> V_19 . V_111 )
return;
if ( F_20 ( V_2 ) ) {
T_5 V_145 = V_146 * 1000LL ;
if ( V_2 -> V_19 . V_111 < V_145 ) {
F_77 (
L_23
L_24 ,
V_2 -> V_8 -> V_67 ,
V_2 -> V_19 . V_111 , V_145 ) ;
V_2 -> V_19 . V_111 = V_145 ;
}
}
F_78 ( & V_2 -> V_19 . V_110 ,
F_79 ( V_141 , V_2 -> V_19 . V_111 ) ,
V_147 ) ;
F_39 ( L_25 V_148 L_26
V_149 L_27
L_28
L_29 V_149 L_30 , V_150 ,
V_112 , F_60 ( V_141 ) ,
F_1 ( V_2 , V_109 ) ,
V_2 -> V_19 . V_111 ,
F_60 ( F_79 ( V_141 ,
V_2 -> V_19 . V_111 ) ) ) ;
} else if ( F_21 ( V_2 ) ) {
T_6 V_151 , V_152 = V_2 -> V_19 . V_152 ;
T_6 V_107 = 0 ;
struct V_27 * V_8 = V_2 -> V_8 ;
unsigned long V_153 = V_8 -> V_9 . V_154 ;
unsigned long V_155 ;
if ( F_46 ( ! V_152 || ! V_153 ) )
return;
F_80 ( V_155 ) ;
V_141 = V_2 -> V_19 . V_110 . V_143 -> V_144 () ;
V_151 = V_156 -> V_157 ( V_8 ) ;
if ( F_28 ( V_152 > V_151 ) ) {
V_107 = ( V_152 - V_151 ) * 1000000ULL ;
F_81 ( V_107 , V_153 ) ;
}
F_78 ( & V_2 -> V_19 . V_110 ,
F_79 ( V_141 , V_107 ) , V_147 ) ;
F_82 ( V_155 ) ;
}
}
static void F_83 ( struct V_1 * V_2 , T_1 V_158 )
{
int V_159 = F_22 ( F_1 ( V_2 , V_160 ) ) ;
if ( F_22 ( V_158 ) ) {
if ( ! V_159 ) {
F_39 ( L_31
L_32 , V_2 -> V_8 -> V_67 ) ;
V_2 -> V_8 -> V_32 -> V_9 . V_161 ++ ;
}
} else if ( V_159 )
V_2 -> V_8 -> V_32 -> V_9 . V_161 -- ;
}
static int F_84 ( struct V_1 * V_2 , T_1 V_162 , T_1 V_5 )
{
int V_163 = 0 ;
F_85 ( V_162 , V_5 ) ;
switch ( V_162 ) {
case V_14 :
if ( ! F_26 ( V_2 ) )
F_2 ( V_2 , V_14 , V_5 ) ;
else
V_163 = 1 ;
break;
case V_58 :
F_66 ( V_2 , true ) ;
F_41 ( V_2 , V_5 & 0xff ) ;
break;
case V_164 :
F_52 ( V_2 ) ;
break;
case V_63 :
if ( ! F_26 ( V_2 ) )
F_2 ( V_2 , V_63 , V_5 & V_165 ) ;
else
V_163 = 1 ;
break;
case V_64 :
if ( ! F_26 ( V_2 ) )
F_2 ( V_2 , V_64 , V_5 | 0x0FFFFFFF ) ;
else
V_163 = 1 ;
break;
case V_12 : {
T_1 V_166 = 0x3ff ;
if ( F_1 ( V_2 , V_36 ) & V_35 )
V_166 |= V_95 ;
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
F_76 ( & V_2 -> V_19 . V_142 , 0 ) ;
}
break;
}
case V_97 :
F_2 ( V_2 , V_97 , V_5 & ~ ( 1 << 12 ) ) ;
F_54 ( V_2 ) ;
break;
case V_99 :
if ( ! F_26 ( V_2 ) )
V_5 &= 0xff000000 ;
F_2 ( V_2 , V_99 , V_5 ) ;
break;
case V_160 :
F_83 ( V_2 , V_5 ) ;
case V_169 :
case V_170 :
case V_171 :
case V_172 :
if ( ! F_14 ( V_2 ) )
V_5 |= V_16 ;
V_5 &= V_173 [ ( V_162 - V_18 ) >> 4 ] ;
F_2 ( V_2 , V_162 , V_5 ) ;
break;
case V_18 :
if ( ( F_1 ( V_2 , V_18 ) &
V_2 -> V_19 . V_20 ) !=
( V_5 & V_2 -> V_19 . V_20 ) )
F_86 ( & V_2 -> V_19 . V_110 ) ;
if ( ! F_14 ( V_2 ) )
V_5 |= V_16 ;
V_5 &= ( V_173 [ 0 ] | V_2 -> V_19 . V_20 ) ;
F_2 ( V_2 , V_18 , V_5 ) ;
break;
case V_109 :
if ( F_21 ( V_2 ) )
break;
F_86 ( & V_2 -> V_19 . V_110 ) ;
F_2 ( V_2 , V_109 , V_5 ) ;
F_75 ( V_2 ) ;
break;
case V_140 :
if ( V_5 & 4 )
F_39 ( L_33 , V_5 ) ;
F_2 ( V_2 , V_140 , V_5 ) ;
F_74 ( V_2 ) ;
break;
case V_174 :
if ( F_26 ( V_2 ) && V_5 != 0 ) {
F_39 ( L_34 , V_5 ) ;
V_163 = 1 ;
}
break;
case V_175 :
if ( F_26 ( V_2 ) ) {
F_84 ( V_2 , V_97 , 0x40000 | ( V_5 & 0xff ) ) ;
} else
V_163 = 1 ;
break;
default:
V_163 = 1 ;
break;
}
if ( V_163 )
F_39 ( L_35 , V_162 ) ;
return V_163 ;
}
static int F_87 ( struct V_126 * V_134 ,
T_7 V_135 , int V_128 , const void * V_129 )
{
struct V_1 * V_2 = F_68 ( V_134 ) ;
unsigned int V_122 = V_135 - V_2 -> V_133 ;
T_1 V_5 ;
if ( ! F_72 ( V_2 , V_135 ) )
return - V_136 ;
if ( V_128 != 4 || ( V_122 & 0xf ) ) {
F_39 ( L_36 , V_128 , ( long ) V_135 ) ;
return 0 ;
}
V_5 = * ( T_1 * ) V_129 ;
if ( V_122 != V_164 )
F_39 ( L_37
L_38 , V_150 , V_122 , V_128 , V_5 ) ;
F_84 ( V_2 , V_122 & 0xff0 , V_5 ) ;
return 0 ;
}
void F_88 ( struct V_27 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
if ( V_2 )
F_84 ( V_8 -> V_9 . V_2 , V_164 , 0 ) ;
}
void F_89 ( struct V_27 * V_8 )
{
if ( ! V_8 -> V_9 . V_2 )
return;
F_86 ( & V_8 -> V_9 . V_2 -> V_19 . V_110 ) ;
if ( V_8 -> V_9 . V_2 -> V_4 )
F_90 ( ( unsigned long ) V_8 -> V_9 . V_2 -> V_4 ) ;
F_91 ( V_8 -> V_9 . V_2 ) ;
}
T_6 F_92 ( struct V_27 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
if ( ! V_2 )
return 0 ;
if ( F_19 ( V_2 ) || F_20 ( V_2 ) )
return 0 ;
return V_2 -> V_19 . V_152 ;
}
void F_93 ( struct V_27 * V_8 , T_6 V_129 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
if ( ! V_2 )
return;
if ( F_19 ( V_2 ) || F_20 ( V_2 ) )
return;
F_86 ( & V_2 -> V_19 . V_110 ) ;
V_2 -> V_19 . V_152 = V_129 ;
F_75 ( V_2 ) ;
}
void F_94 ( struct V_27 * V_8 , unsigned long V_176 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
if ( ! V_2 )
return;
F_41 ( V_2 , ( ( V_176 & 0x0f ) << 4 )
| ( F_1 ( V_2 , V_58 ) & 4 ) ) ;
}
T_6 F_95 ( struct V_27 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
T_6 V_52 ;
if ( ! V_2 )
return 0 ;
V_52 = ( T_6 ) F_1 ( V_2 , V_58 ) ;
return ( V_52 & 0xf0 ) >> 4 ;
}
void F_96 ( struct V_27 * V_8 , T_6 V_177 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
if ( ! V_2 ) {
V_177 |= V_178 ;
V_8 -> V_9 . V_10 = V_177 ;
return;
}
if ( ! F_97 ( V_2 -> V_8 ) )
V_177 &= ~ V_178 ;
V_8 -> V_9 . V_10 = V_177 ;
if ( F_26 ( V_2 ) ) {
T_1 V_179 = F_16 ( V_2 ) ;
T_1 V_180 = ( ( V_179 & ~ 0xf ) << 16 ) | ( 1 << ( V_179 & 0xf ) ) ;
F_2 ( V_2 , V_63 , V_180 ) ;
}
V_2 -> V_133 = V_2 -> V_8 -> V_9 . V_10 &
V_181 ;
F_39 ( L_39 V_149 L_40
L_41 , V_2 -> V_8 -> V_9 . V_10 , V_2 -> V_133 ) ;
}
void F_98 ( struct V_27 * V_8 )
{
struct V_1 * V_2 ;
int V_167 ;
F_39 ( L_42 , V_150 ) ;
ASSERT ( V_8 ) ;
V_2 = V_8 -> V_9 . V_2 ;
ASSERT ( V_2 != NULL ) ;
F_86 ( & V_2 -> V_19 . V_110 ) ;
F_2 ( V_2 , V_14 , V_8 -> V_67 << 24 ) ;
F_23 ( V_2 -> V_8 ) ;
for ( V_167 = 0 ; V_167 < V_168 ; V_167 ++ )
F_2 ( V_2 , V_18 + 0x10 * V_167 , V_16 ) ;
F_2 ( V_2 , V_160 ,
F_99 ( 0 , V_182 ) ) ;
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
F_74 ( V_2 ) ;
F_76 ( & V_2 -> V_19 . V_142 , 0 ) ;
if ( F_97 ( V_8 ) )
V_8 -> V_9 . V_10 |= V_178 ;
F_38 ( V_2 ) ;
V_8 -> V_9 . V_77 = 0 ;
F_39 ( V_183 L_43
L_44 V_149 L_45 , V_150 ,
V_8 , F_16 ( V_2 ) ,
V_8 -> V_9 . V_10 , V_2 -> V_133 ) ;
}
bool F_100 ( struct V_27 * V_8 )
{
return V_8 -> V_9 . V_2 && F_13 ( V_8 -> V_9 . V_2 ) ;
}
int F_101 ( struct V_27 * V_8 )
{
return F_100 ( V_8 ) && F_14 ( V_8 -> V_9 . V_2 ) ;
}
static bool F_102 ( struct V_184 * V_185 )
{
struct V_1 * V_2 = F_69 ( V_185 , struct V_1 ,
V_19 ) ;
return F_20 ( V_2 ) ;
}
int F_103 ( struct V_27 * V_8 )
{
struct V_1 * V_186 = V_8 -> V_9 . V_2 ;
if ( V_186 && F_15 ( V_186 ) && F_17 ( V_186 , V_18 ) )
return F_104 ( & V_186 -> V_19 . V_142 ) ;
return 0 ;
}
int F_105 ( struct V_1 * V_2 , int V_15 )
{
T_1 V_162 = F_1 ( V_2 , V_15 ) ;
int V_48 , V_187 , V_50 ;
if ( F_13 ( V_2 ) && ! ( V_162 & V_16 ) ) {
V_48 = V_162 & V_17 ;
V_187 = V_162 & V_25 ;
V_50 = V_162 & V_188 ;
return F_36 ( V_2 , V_187 , V_48 , 1 , V_50 ) ;
}
return 0 ;
}
void F_106 ( struct V_27 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
if ( V_2 )
F_105 ( V_2 , V_160 ) ;
}
int F_107 ( struct V_27 * V_8 )
{
struct V_1 * V_2 ;
ASSERT ( V_8 != NULL ) ;
F_39 ( L_46 , V_8 -> V_67 ) ;
V_2 = F_108 ( sizeof( * V_2 ) , V_189 ) ;
if ( ! V_2 )
goto V_190;
V_8 -> V_9 . V_2 = V_2 ;
V_2 -> V_4 = ( void * ) F_109 ( V_189 ) ;
if ( ! V_2 -> V_4 ) {
F_50 ( V_89 L_47 ,
V_8 -> V_67 ) ;
goto V_191;
}
V_2 -> V_8 = V_8 ;
F_110 ( & V_2 -> V_19 . V_110 , V_192 ,
V_147 ) ;
V_2 -> V_19 . V_110 . V_193 = V_194 ;
V_2 -> V_19 . V_195 = & V_196 ;
V_2 -> V_19 . V_32 = V_8 -> V_32 ;
V_2 -> V_19 . V_8 = V_8 ;
V_2 -> V_133 = V_197 ;
V_8 -> V_9 . V_10 = V_197 ;
F_98 ( V_8 ) ;
F_111 ( & V_2 -> V_127 , & V_198 ) ;
return 0 ;
V_191:
F_91 ( V_2 ) ;
V_190:
return - V_199 ;
}
int F_112 ( struct V_27 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
int V_44 ;
if ( ! V_2 || ! F_15 ( V_2 ) )
return - 1 ;
F_38 ( V_2 ) ;
V_44 = F_32 ( V_2 ) ;
if ( ( V_44 == - 1 ) ||
( ( V_44 & 0xF0 ) <= F_1 ( V_2 , V_57 ) ) )
return - 1 ;
return V_44 ;
}
int F_113 ( struct V_27 * V_8 )
{
T_1 V_200 = F_1 ( V_8 -> V_9 . V_2 , V_160 ) ;
int V_201 = 0 ;
if ( ! F_13 ( V_8 -> V_9 . V_2 ) )
V_201 = 1 ;
if ( ( V_200 & V_16 ) == 0 &&
F_114 ( V_200 ) == V_182 )
V_201 = 1 ;
return V_201 ;
}
void F_115 ( struct V_27 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
if ( V_2 && F_104 ( & V_2 -> V_19 . V_142 ) > 0 ) {
if ( F_105 ( V_2 , V_18 ) )
F_116 ( & V_2 -> V_19 . V_142 ) ;
}
}
int F_117 ( struct V_27 * V_8 )
{
int V_48 = F_112 ( V_8 ) ;
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
if ( V_48 == - 1 )
return - 1 ;
F_9 ( V_48 , V_2 -> V_4 + V_51 ) ;
F_38 ( V_2 ) ;
F_33 ( V_48 , V_2 ) ;
return V_48 ;
}
void F_118 ( struct V_27 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
V_2 -> V_133 = V_8 -> V_9 . V_10 &
V_181 ;
F_23 ( V_8 ) ;
F_38 ( V_2 ) ;
F_86 ( & V_2 -> V_19 . V_110 ) ;
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
V_2 -> V_41 = true ;
F_40 ( V_59 , V_8 ) ;
}
void F_119 ( struct V_27 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
struct V_202 * V_110 ;
if ( ! V_2 )
return;
V_110 = & V_2 -> V_19 . V_110 ;
if ( F_86 ( V_110 ) )
F_120 ( V_110 , V_147 ) ;
}
void F_121 ( struct V_27 * V_8 )
{
T_1 V_129 ;
void * V_203 ;
if ( ! F_24 ( V_8 -> V_32 ) || ! V_8 -> V_9 . V_2 -> V_204 )
return;
V_203 = F_122 ( V_8 -> V_9 . V_2 -> V_205 ) ;
V_129 = * ( T_1 * ) ( V_203 + F_123 ( V_8 -> V_9 . V_2 -> V_204 ) ) ;
F_124 ( V_203 ) ;
F_41 ( V_8 -> V_9 . V_2 , V_129 & 0xff ) ;
}
void F_125 ( struct V_27 * V_8 )
{
T_1 V_129 , V_52 ;
int V_206 , V_207 ;
struct V_1 * V_2 ;
void * V_203 ;
if ( ! F_24 ( V_8 -> V_32 ) || ! V_8 -> V_9 . V_2 -> V_204 )
return;
V_2 = V_8 -> V_9 . V_2 ;
V_52 = F_1 ( V_2 , V_58 ) & 0xff ;
V_206 = F_32 ( V_2 ) ;
if ( V_206 < 0 )
V_206 = 0 ;
V_207 = F_37 ( V_2 ) ;
if ( V_207 < 0 )
V_207 = 0 ;
V_129 = ( V_52 & 0xff ) | ( ( V_207 & 0xf0 ) << 8 ) | ( V_206 << 24 ) ;
V_203 = F_122 ( V_8 -> V_9 . V_2 -> V_205 ) ;
* ( T_1 * ) ( V_203 + F_123 ( V_8 -> V_9 . V_2 -> V_204 ) ) = V_129 ;
F_124 ( V_203 ) ;
}
void F_126 ( struct V_27 * V_8 , T_7 V_204 )
{
if ( ! F_24 ( V_8 -> V_32 ) )
return;
V_8 -> V_9 . V_2 -> V_204 = V_204 ;
}
int F_127 ( struct V_27 * V_8 , T_1 V_208 , T_6 V_129 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
T_1 V_162 = ( V_208 - V_209 ) << 4 ;
if ( ! F_24 ( V_8 -> V_32 ) || ! F_26 ( V_2 ) )
return 1 ;
if ( V_208 == 0x830 )
F_84 ( V_2 , V_99 , ( T_1 ) ( V_129 >> 32 ) ) ;
return F_84 ( V_2 , V_162 , ( T_1 ) V_129 ) ;
}
int F_128 ( struct V_27 * V_8 , T_1 V_208 , T_6 * V_129 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
T_1 V_162 = ( V_208 - V_209 ) << 4 , V_210 , V_211 = 0 ;
if ( ! F_24 ( V_8 -> V_32 ) || ! F_26 ( V_2 ) )
return 1 ;
if ( F_70 ( V_2 , V_162 , 4 , & V_210 ) )
return 1 ;
if ( V_208 == 0x830 )
F_70 ( V_2 , V_99 , 4 , & V_211 ) ;
* V_129 = ( ( ( T_6 ) V_211 ) << 32 ) | V_210 ;
return 0 ;
}
int F_129 ( struct V_27 * V_8 , T_1 V_162 , T_6 V_129 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
if ( ! F_24 ( V_8 -> V_32 ) )
return 1 ;
if ( V_162 == V_97 )
F_84 ( V_2 , V_99 , ( T_1 ) ( V_129 >> 32 ) ) ;
return F_84 ( V_2 , V_162 , ( T_1 ) V_129 ) ;
}
int F_130 ( struct V_27 * V_8 , T_1 V_162 , T_6 * V_129 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
T_1 V_210 , V_211 = 0 ;
if ( ! F_24 ( V_8 -> V_32 ) )
return 1 ;
if ( F_70 ( V_2 , V_162 , 4 , & V_210 ) )
return 1 ;
if ( V_162 == V_97 )
F_70 ( V_2 , V_99 , 4 , & V_211 ) ;
* V_129 = ( ( ( T_6 ) V_211 ) << 32 ) | V_210 ;
return 0 ;
}
