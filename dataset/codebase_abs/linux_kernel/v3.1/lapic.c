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
return F_1 ( V_2 , V_18 ) & V_19 ;
}
static inline int F_20 ( T_1 V_20 )
{
return ( V_20 & ( V_21 | V_16 ) ) == V_22 ;
}
void F_21 ( struct V_23 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
struct V_24 * V_25 ;
T_1 V_26 = V_27 ;
if ( ! F_22 ( V_8 -> V_28 ) )
return;
V_25 = F_23 ( V_2 -> V_8 , 0x1 , 0 ) ;
if ( V_25 && ( V_25 -> V_29 & ( 1 << ( V_30 & 31 ) ) ) )
V_26 |= V_31 ;
F_2 ( V_2 , V_32 , V_26 ) ;
}
static inline int F_24 ( struct V_1 * V_2 )
{
return V_2 -> V_8 -> V_9 . V_10 & V_33 ;
}
static int F_25 ( void * V_7 )
{
T_1 * V_34 = V_7 ;
int V_35 = V_36 >> 5 ;
while ( ( V_35 != 0 ) && ( V_34 [ ( -- V_35 ) << 2 ] == 0 ) )
continue;
if ( F_26 ( ! V_35 && ! V_34 [ 0 ] ) )
return - 1 ;
else
return F_27 ( V_34 [ V_35 << 2 ] ) - 1 + ( V_35 << 5 ) ;
}
static inline int F_28 ( int V_6 , struct V_1 * V_2 )
{
V_2 -> V_37 = true ;
return F_3 ( V_6 , V_2 -> V_4 + V_38 ) ;
}
static inline int F_29 ( struct V_1 * V_2 )
{
return F_25 ( V_2 -> V_4 + V_38 ) ;
}
static inline int F_30 ( struct V_1 * V_2 )
{
int V_39 ;
if ( ! V_2 -> V_37 )
return - 1 ;
V_39 = F_29 ( V_2 ) ;
ASSERT ( V_39 == - 1 || V_39 >= 16 ) ;
return V_39 ;
}
static inline void F_31 ( int V_6 , struct V_1 * V_2 )
{
V_2 -> V_37 = false ;
F_11 ( V_6 , V_2 -> V_4 + V_38 ) ;
if ( F_29 ( V_2 ) != - 1 )
V_2 -> V_37 = true ;
}
int F_32 ( struct V_23 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
int V_40 ;
if ( ! V_2 )
return 0 ;
V_40 = F_30 ( V_2 ) ;
return V_40 ;
}
int F_33 ( struct V_23 * V_8 , struct V_41 * V_42 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
return F_34 ( V_2 , V_42 -> V_43 , V_42 -> V_44 ,
V_42 -> V_45 , V_42 -> V_46 ) ;
}
static inline int F_35 ( struct V_1 * V_2 )
{
int V_39 ;
V_39 = F_25 ( V_2 -> V_4 + V_47 ) ;
ASSERT ( V_39 == - 1 || V_39 >= 16 ) ;
return V_39 ;
}
static void F_36 ( struct V_1 * V_2 )
{
T_1 V_48 , V_49 , V_50 , V_51 ;
int V_52 ;
V_51 = F_1 ( V_2 , V_53 ) ;
V_48 = F_1 ( V_2 , V_54 ) ;
V_52 = F_35 ( V_2 ) ;
V_49 = ( V_52 != - 1 ) ? V_52 : 0 ;
if ( ( V_48 & 0xf0 ) >= ( V_49 & 0xf0 ) )
V_50 = V_48 & 0xff ;
else
V_50 = V_49 & 0xf0 ;
F_37 ( L_1 ,
V_2 , V_50 , V_52 , V_49 ) ;
if ( V_51 != V_50 ) {
F_2 ( V_2 , V_53 , V_50 ) ;
if ( V_50 < V_51 )
F_38 ( V_55 , V_2 -> V_8 ) ;
}
}
static void F_39 ( struct V_1 * V_2 , T_1 V_48 )
{
F_2 ( V_2 , V_54 , V_48 ) ;
F_36 ( V_2 ) ;
}
int F_40 ( struct V_1 * V_2 , T_2 V_56 )
{
return V_56 == 0xff || F_16 ( V_2 ) == V_56 ;
}
int F_41 ( struct V_1 * V_2 , T_3 V_57 )
{
int V_39 = 0 ;
T_1 V_58 ;
if ( F_24 ( V_2 ) ) {
V_58 = F_1 ( V_2 , V_59 ) ;
return V_58 & V_57 ;
}
V_58 = F_42 ( F_1 ( V_2 , V_59 ) ) ;
switch ( F_1 ( V_2 , V_60 ) ) {
case V_61 :
if ( V_58 & V_57 )
V_39 = 1 ;
break;
case V_62 :
if ( ( ( V_58 >> 4 ) == ( V_57 >> 0x4 ) )
&& ( V_58 & V_57 & 0xf ) )
V_39 = 1 ;
break;
default:
F_43 ( V_63 L_2 ,
V_2 -> V_8 -> V_64 , F_1 ( V_2 , V_60 ) ) ;
break;
}
return V_39 ;
}
int F_44 ( struct V_23 * V_8 , struct V_1 * V_65 ,
int V_66 , int V_56 , int V_67 )
{
int V_39 = 0 ;
struct V_1 * V_68 = V_8 -> V_9 . V_2 ;
F_37 ( L_3
L_4 ,
V_68 , V_65 , V_56 , V_67 , V_66 ) ;
ASSERT ( V_68 ) ;
switch ( V_66 ) {
case V_69 :
if ( V_67 == 0 )
V_39 = F_40 ( V_68 , V_56 ) ;
else
V_39 = F_41 ( V_68 , V_56 ) ;
break;
case V_70 :
V_39 = ( V_68 == V_65 ) ;
break;
case V_71 :
V_39 = 1 ;
break;
case V_72 :
V_39 = ( V_68 != V_65 ) ;
break;
default:
F_43 ( V_63 L_5 ,
V_66 ) ;
break;
}
return V_39 ;
}
static int F_34 ( struct V_1 * V_2 , int V_43 ,
int V_44 , int V_45 , int V_46 )
{
int V_39 = 0 ;
struct V_23 * V_8 = V_2 -> V_8 ;
switch ( V_43 ) {
case V_73 :
V_8 -> V_9 . V_74 ++ ;
case V_75 :
if ( F_45 ( ! F_15 ( V_2 ) ) )
break;
if ( V_46 ) {
F_37 ( L_6 , V_44 ) ;
F_9 ( V_44 , V_2 -> V_4 + V_76 ) ;
} else
F_11 ( V_44 , V_2 -> V_4 + V_76 ) ;
V_39 = ! F_28 ( V_44 , V_2 ) ;
F_46 ( V_8 -> V_64 , V_43 ,
V_46 , V_44 , ! V_39 ) ;
if ( ! V_39 ) {
if ( V_46 )
F_37 ( L_7
L_8 , V_44 ) ;
break;
}
F_38 ( V_55 , V_8 ) ;
F_47 ( V_8 ) ;
break;
case V_77 :
F_43 ( V_78 L_9 ) ;
break;
case V_79 :
F_43 ( V_78 L_10 ) ;
break;
case V_22 :
V_39 = 1 ;
F_48 ( V_8 ) ;
F_47 ( V_8 ) ;
break;
case V_80 :
if ( V_45 ) {
V_39 = 1 ;
V_8 -> V_9 . V_81 = V_82 ;
F_38 ( V_55 , V_8 ) ;
F_47 ( V_8 ) ;
} else {
F_37 ( L_11 ,
V_8 -> V_64 ) ;
}
break;
case V_83 :
F_37 ( L_12 ,
V_8 -> V_64 , V_44 ) ;
if ( V_8 -> V_9 . V_81 == V_82 ) {
V_39 = 1 ;
V_8 -> V_9 . V_84 = V_44 ;
V_8 -> V_9 . V_81 = V_85 ;
F_38 ( V_55 , V_8 ) ;
F_47 ( V_8 ) ;
}
break;
case V_86 :
break;
default:
F_43 ( V_87 L_13 ,
V_43 ) ;
break;
}
return V_39 ;
}
int F_49 ( struct V_23 * V_88 , struct V_23 * V_89 )
{
return V_88 -> V_9 . V_74 - V_89 -> V_9 . V_74 ;
}
static void F_50 ( struct V_1 * V_2 )
{
int V_44 = F_35 ( V_2 ) ;
int V_90 ;
if ( V_44 == - 1 )
return;
F_11 ( V_44 , V_2 -> V_4 + V_47 ) ;
F_36 ( V_2 ) ;
if ( F_7 ( V_44 , V_2 -> V_4 + V_76 ) )
V_90 = V_91 ;
else
V_90 = V_92 ;
if ( ! ( F_1 ( V_2 , V_12 ) & V_93 ) )
F_51 ( V_2 -> V_8 -> V_28 , V_44 , V_90 ) ;
F_38 ( V_55 , V_2 -> V_8 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
T_1 V_94 = F_1 ( V_2 , V_95 ) ;
T_1 V_96 = F_1 ( V_2 , V_97 ) ;
struct V_41 V_42 ;
V_42 . V_44 = V_94 & V_17 ;
V_42 . V_43 = V_94 & V_21 ;
V_42 . V_67 = V_94 & V_98 ;
V_42 . V_45 = V_94 & V_99 ;
V_42 . V_46 = V_94 & V_100 ;
V_42 . V_101 = V_94 & V_102 ;
if ( F_24 ( V_2 ) )
V_42 . V_103 = V_96 ;
else
V_42 . V_103 = F_53 ( V_96 ) ;
F_54 ( V_94 , V_42 . V_103 ) ;
F_37 ( L_14
L_15
L_16 ,
V_96 , V_94 , V_42 . V_101 , V_42 . V_103 ,
V_42 . V_46 , V_42 . V_45 , V_42 . V_67 , V_42 . V_43 ,
V_42 . V_44 ) ;
F_55 ( V_2 -> V_8 -> V_28 , V_2 , & V_42 ) ;
}
static T_1 F_56 ( struct V_1 * V_2 )
{
T_4 V_104 ;
T_5 V_105 ;
T_1 V_106 ;
ASSERT ( V_2 != NULL ) ;
if ( F_1 ( V_2 , V_107 ) == 0 )
return 0 ;
V_104 = F_57 ( & V_2 -> V_108 . V_109 ) ;
if ( F_58 ( V_104 ) < 0 )
V_104 = F_59 ( 0 , 0 ) ;
V_105 = F_60 ( F_58 ( V_104 ) , V_2 -> V_108 . V_110 ) ;
V_106 = F_61 ( V_105 ,
( V_111 * V_2 -> V_112 ) ) ;
return V_106 ;
}
static void F_62 ( struct V_1 * V_2 , bool V_113 )
{
struct V_23 * V_8 = V_2 -> V_8 ;
struct V_114 * V_115 = V_8 -> V_115 ;
F_38 ( V_116 , V_8 ) ;
V_115 -> V_117 . V_118 = F_63 ( V_8 ) ;
V_115 -> V_117 . V_119 = V_113 ;
}
static inline void F_64 ( struct V_1 * V_2 , bool V_113 )
{
if ( V_2 -> V_8 -> V_9 . V_120 )
F_62 ( V_2 , V_113 ) ;
}
static T_1 F_65 ( struct V_1 * V_2 , unsigned int V_121 )
{
T_1 V_5 = 0 ;
if ( V_121 >= V_122 )
return 0 ;
switch ( V_121 ) {
case V_14 :
if ( F_24 ( V_2 ) )
V_5 = F_16 ( V_2 ) ;
else
V_5 = F_16 ( V_2 ) << 24 ;
break;
case V_123 :
F_43 ( V_63 L_17
L_18 ) ;
break;
case V_124 :
V_5 = F_56 ( V_2 ) ;
break;
case V_54 :
F_64 ( V_2 , false ) ;
default:
F_36 ( V_2 ) ;
V_5 = F_1 ( V_2 , V_121 ) ;
break;
}
return V_5 ;
}
static inline struct V_1 * F_66 ( struct V_125 * V_126 )
{
return F_67 ( V_126 , struct V_1 , V_126 ) ;
}
static int F_68 ( struct V_1 * V_2 , T_1 V_121 , int V_127 ,
void * V_128 )
{
unsigned char V_129 = V_121 & 0xf ;
T_1 V_39 ;
static const T_6 V_130 = 0x43ff01ffffffe70cULL ;
if ( ( V_129 + V_127 ) > 4 ) {
F_37 ( L_19 ,
V_121 , V_127 ) ;
return 1 ;
}
if ( V_121 > 0x3f0 || ! ( V_130 & ( 1ULL << ( V_121 >> 4 ) ) ) ) {
F_37 ( L_20 ,
V_121 ) ;
return 1 ;
}
V_39 = F_65 ( V_2 , V_121 & ~ 0xf ) ;
F_69 ( V_121 , V_39 ) ;
switch ( V_127 ) {
case 1 :
case 2 :
case 4 :
memcpy ( V_128 , ( char * ) & V_39 + V_129 , V_127 ) ;
break;
default:
F_43 ( V_87 L_21
L_22 , V_127 ) ;
break;
}
return 0 ;
}
static int F_70 ( struct V_1 * V_2 , T_7 V_131 )
{
return F_13 ( V_2 ) &&
V_131 >= V_2 -> V_132 &&
V_131 < V_2 -> V_132 + V_122 ;
}
static int F_71 ( struct V_125 * V_133 ,
T_7 V_134 , int V_127 , void * V_128 )
{
struct V_1 * V_2 = F_66 ( V_133 ) ;
T_1 V_121 = V_134 - V_2 -> V_132 ;
if ( ! F_70 ( V_2 , V_134 ) )
return - V_135 ;
F_68 ( V_2 , V_121 , V_127 , V_128 ) ;
return 0 ;
}
static void F_72 ( struct V_1 * V_2 )
{
T_1 V_136 , V_137 , V_138 ;
V_138 = F_1 ( V_2 , V_139 ) ;
V_136 = V_138 & 0xf ;
V_137 = ( ( V_136 & 0x3 ) | ( ( V_136 & 0x8 ) >> 1 ) ) + 1 ;
V_2 -> V_112 = 0x1 << ( V_137 & 0x7 ) ;
F_37 ( L_23 ,
V_2 -> V_112 ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
T_4 V_140 = V_2 -> V_108 . V_109 . V_141 -> V_142 () ;
V_2 -> V_108 . V_110 = ( T_6 ) F_1 ( V_2 , V_107 ) *
V_111 * V_2 -> V_112 ;
F_74 ( & V_2 -> V_108 . V_143 , 0 ) ;
if ( ! V_2 -> V_108 . V_110 )
return;
if ( F_19 ( V_2 ) ) {
if ( V_2 -> V_108 . V_110 < V_144 / 2 )
V_2 -> V_108 . V_110 = V_144 / 2 ;
}
F_75 ( & V_2 -> V_108 . V_109 ,
F_76 ( V_140 , V_2 -> V_108 . V_110 ) ,
V_145 ) ;
F_37 ( L_24 V_146 L_25
V_147 L_26
L_27
L_28 V_147 L_29 , V_148 ,
V_111 , F_58 ( V_140 ) ,
F_1 ( V_2 , V_107 ) ,
V_2 -> V_108 . V_110 ,
F_58 ( F_76 ( V_140 ,
V_2 -> V_108 . V_110 ) ) ) ;
}
static void F_77 ( struct V_1 * V_2 , T_1 V_149 )
{
int V_150 = F_20 ( F_1 ( V_2 , V_151 ) ) ;
if ( F_20 ( V_149 ) ) {
if ( ! V_150 ) {
F_37 ( L_30
L_31 , V_2 -> V_8 -> V_64 ) ;
V_2 -> V_8 -> V_28 -> V_9 . V_152 ++ ;
}
} else if ( V_150 )
V_2 -> V_8 -> V_28 -> V_9 . V_152 -- ;
}
static int F_78 ( struct V_1 * V_2 , T_1 V_153 , T_1 V_5 )
{
int V_154 = 0 ;
F_79 ( V_153 , V_5 ) ;
switch ( V_153 ) {
case V_14 :
if ( ! F_24 ( V_2 ) )
F_2 ( V_2 , V_14 , V_5 ) ;
else
V_154 = 1 ;
break;
case V_54 :
F_64 ( V_2 , true ) ;
F_39 ( V_2 , V_5 & 0xff ) ;
break;
case V_155 :
F_50 ( V_2 ) ;
break;
case V_59 :
if ( ! F_24 ( V_2 ) )
F_2 ( V_2 , V_59 , V_5 & V_156 ) ;
else
V_154 = 1 ;
break;
case V_60 :
if ( ! F_24 ( V_2 ) )
F_2 ( V_2 , V_60 , V_5 | 0x0FFFFFFF ) ;
else
V_154 = 1 ;
break;
case V_12 : {
T_1 V_157 = 0x3ff ;
if ( F_1 ( V_2 , V_32 ) & V_31 )
V_157 |= V_93 ;
F_2 ( V_2 , V_12 , V_5 & V_157 ) ;
if ( ! ( V_5 & V_13 ) ) {
int V_158 ;
T_1 V_20 ;
for ( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
V_20 = F_1 ( V_2 ,
V_18 + 0x10 * V_158 ) ;
F_2 ( V_2 , V_18 + 0x10 * V_158 ,
V_20 | V_16 ) ;
}
F_74 ( & V_2 -> V_108 . V_143 , 0 ) ;
}
break;
}
case V_95 :
F_2 ( V_2 , V_95 , V_5 & ~ ( 1 << 12 ) ) ;
F_52 ( V_2 ) ;
break;
case V_97 :
if ( ! F_24 ( V_2 ) )
V_5 &= 0xff000000 ;
F_2 ( V_2 , V_97 , V_5 ) ;
break;
case V_151 :
F_77 ( V_2 , V_5 ) ;
case V_18 :
case V_160 :
case V_161 :
case V_162 :
case V_163 :
if ( ! F_14 ( V_2 ) )
V_5 |= V_16 ;
V_5 &= V_164 [ ( V_153 - V_18 ) >> 4 ] ;
F_2 ( V_2 , V_153 , V_5 ) ;
break;
case V_107 :
F_80 ( & V_2 -> V_108 . V_109 ) ;
F_2 ( V_2 , V_107 , V_5 ) ;
F_73 ( V_2 ) ;
break;
case V_139 :
if ( V_5 & 4 )
F_43 ( V_87 L_32 , V_5 ) ;
F_2 ( V_2 , V_139 , V_5 ) ;
F_72 ( V_2 ) ;
break;
case V_165 :
if ( F_24 ( V_2 ) && V_5 != 0 ) {
F_43 ( V_87 L_33 , V_5 ) ;
V_154 = 1 ;
}
break;
case V_166 :
if ( F_24 ( V_2 ) ) {
F_78 ( V_2 , V_95 , 0x40000 | ( V_5 & 0xff ) ) ;
} else
V_154 = 1 ;
break;
default:
V_154 = 1 ;
break;
}
if ( V_154 )
F_37 ( L_34 , V_153 ) ;
return V_154 ;
}
static int F_81 ( struct V_125 * V_133 ,
T_7 V_134 , int V_127 , const void * V_128 )
{
struct V_1 * V_2 = F_66 ( V_133 ) ;
unsigned int V_121 = V_134 - V_2 -> V_132 ;
T_1 V_5 ;
if ( ! F_70 ( V_2 , V_134 ) )
return - V_135 ;
if ( V_127 != 4 || ( V_121 & 0xf ) ) {
F_37 ( L_35 , V_127 , ( long ) V_134 ) ;
return 0 ;
}
V_5 = * ( T_1 * ) V_128 ;
if ( V_121 != V_155 )
F_37 ( L_36
L_37 , V_148 , V_121 , V_127 , V_5 ) ;
F_78 ( V_2 , V_121 & 0xff0 , V_5 ) ;
return 0 ;
}
void F_82 ( struct V_23 * V_8 )
{
if ( ! V_8 -> V_9 . V_2 )
return;
F_80 ( & V_8 -> V_9 . V_2 -> V_108 . V_109 ) ;
if ( V_8 -> V_9 . V_2 -> V_4 )
F_83 ( ( unsigned long ) V_8 -> V_9 . V_2 -> V_4 ) ;
F_84 ( V_8 -> V_9 . V_2 ) ;
}
void F_85 ( struct V_23 * V_8 , unsigned long V_167 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
if ( ! V_2 )
return;
F_39 ( V_2 , ( ( V_167 & 0x0f ) << 4 )
| ( F_1 ( V_2 , V_54 ) & 4 ) ) ;
}
T_6 F_86 ( struct V_23 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
T_6 V_48 ;
if ( ! V_2 )
return 0 ;
V_48 = ( T_6 ) F_1 ( V_2 , V_54 ) ;
return ( V_48 & 0xf0 ) >> 4 ;
}
void F_87 ( struct V_23 * V_8 , T_6 V_168 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
if ( ! V_2 ) {
V_168 |= V_169 ;
V_8 -> V_9 . V_10 = V_168 ;
return;
}
if ( ! F_88 ( V_2 -> V_8 ) )
V_168 &= ~ V_169 ;
V_8 -> V_9 . V_10 = V_168 ;
if ( F_24 ( V_2 ) ) {
T_1 V_170 = F_16 ( V_2 ) ;
T_1 V_171 = ( ( V_170 & ~ 0xf ) << 16 ) | ( 1 << ( V_170 & 0xf ) ) ;
F_2 ( V_2 , V_59 , V_171 ) ;
}
V_2 -> V_132 = V_2 -> V_8 -> V_9 . V_10 &
V_172 ;
F_37 ( L_38 V_147 L_39
L_40 , V_2 -> V_8 -> V_9 . V_10 , V_2 -> V_132 ) ;
}
void F_89 ( struct V_23 * V_8 )
{
struct V_1 * V_2 ;
int V_158 ;
F_37 ( L_41 , V_148 ) ;
ASSERT ( V_8 ) ;
V_2 = V_8 -> V_9 . V_2 ;
ASSERT ( V_2 != NULL ) ;
F_80 ( & V_2 -> V_108 . V_109 ) ;
F_2 ( V_2 , V_14 , V_8 -> V_64 << 24 ) ;
F_21 ( V_2 -> V_8 ) ;
for ( V_158 = 0 ; V_158 < V_159 ; V_158 ++ )
F_2 ( V_2 , V_18 + 0x10 * V_158 , V_16 ) ;
F_2 ( V_2 , V_151 ,
F_90 ( 0 , V_173 ) ) ;
F_2 ( V_2 , V_60 , 0xffffffffU ) ;
F_2 ( V_2 , V_12 , 0xff ) ;
F_2 ( V_2 , V_54 , 0 ) ;
F_2 ( V_2 , V_59 , 0 ) ;
F_2 ( V_2 , V_165 , 0 ) ;
F_2 ( V_2 , V_95 , 0 ) ;
F_2 ( V_2 , V_97 , 0 ) ;
F_2 ( V_2 , V_139 , 0 ) ;
F_2 ( V_2 , V_107 , 0 ) ;
for ( V_158 = 0 ; V_158 < 8 ; V_158 ++ ) {
F_2 ( V_2 , V_38 + 0x10 * V_158 , 0 ) ;
F_2 ( V_2 , V_47 + 0x10 * V_158 , 0 ) ;
F_2 ( V_2 , V_76 + 0x10 * V_158 , 0 ) ;
}
V_2 -> V_37 = false ;
F_72 ( V_2 ) ;
F_74 ( & V_2 -> V_108 . V_143 , 0 ) ;
if ( F_88 ( V_8 ) )
V_8 -> V_9 . V_10 |= V_169 ;
F_36 ( V_2 ) ;
V_8 -> V_9 . V_74 = 0 ;
F_37 ( V_174 L_42
L_43 V_147 L_44 , V_148 ,
V_8 , F_16 ( V_2 ) ,
V_8 -> V_9 . V_10 , V_2 -> V_132 ) ;
}
bool F_91 ( struct V_23 * V_8 )
{
return V_8 -> V_9 . V_2 && F_13 ( V_8 -> V_9 . V_2 ) ;
}
int F_92 ( struct V_23 * V_8 )
{
return F_91 ( V_8 ) && F_14 ( V_8 -> V_9 . V_2 ) ;
}
static bool F_93 ( struct V_175 * V_176 )
{
struct V_1 * V_2 = F_67 ( V_176 , struct V_1 ,
V_108 ) ;
return F_19 ( V_2 ) ;
}
int F_94 ( struct V_23 * V_8 )
{
struct V_1 * V_177 = V_8 -> V_9 . V_2 ;
if ( V_177 && F_15 ( V_177 ) && F_17 ( V_177 , V_18 ) )
return F_95 ( & V_177 -> V_108 . V_143 ) ;
return 0 ;
}
static int F_96 ( struct V_1 * V_2 , int V_15 )
{
T_1 V_153 = F_1 ( V_2 , V_15 ) ;
int V_44 , V_178 , V_46 ;
if ( F_13 ( V_2 ) && ! ( V_153 & V_16 ) ) {
V_44 = V_153 & V_17 ;
V_178 = V_153 & V_21 ;
V_46 = V_153 & V_179 ;
return F_34 ( V_2 , V_178 , V_44 , 1 , V_46 ) ;
}
return 0 ;
}
void F_97 ( struct V_23 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
if ( V_2 )
F_96 ( V_2 , V_151 ) ;
}
int F_98 ( struct V_23 * V_8 )
{
struct V_1 * V_2 ;
ASSERT ( V_8 != NULL ) ;
F_37 ( L_45 , V_8 -> V_64 ) ;
V_2 = F_99 ( sizeof( * V_2 ) , V_180 ) ;
if ( ! V_2 )
goto V_181;
V_8 -> V_9 . V_2 = V_2 ;
V_2 -> V_4 = ( void * ) F_100 ( V_180 ) ;
if ( ! V_2 -> V_4 ) {
F_43 ( V_87 L_46 ,
V_8 -> V_64 ) ;
goto V_182;
}
V_2 -> V_8 = V_8 ;
F_101 ( & V_2 -> V_108 . V_109 , V_183 ,
V_145 ) ;
V_2 -> V_108 . V_109 . V_184 = V_185 ;
V_2 -> V_108 . V_186 = & V_187 ;
V_2 -> V_108 . V_28 = V_8 -> V_28 ;
V_2 -> V_108 . V_8 = V_8 ;
V_2 -> V_132 = V_188 ;
V_8 -> V_9 . V_10 = V_188 ;
F_89 ( V_8 ) ;
F_102 ( & V_2 -> V_126 , & V_189 ) ;
return 0 ;
V_182:
F_84 ( V_2 ) ;
V_181:
return - V_190 ;
}
int F_103 ( struct V_23 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
int V_40 ;
if ( ! V_2 || ! F_15 ( V_2 ) )
return - 1 ;
F_36 ( V_2 ) ;
V_40 = F_30 ( V_2 ) ;
if ( ( V_40 == - 1 ) ||
( ( V_40 & 0xF0 ) <= F_1 ( V_2 , V_53 ) ) )
return - 1 ;
return V_40 ;
}
int F_104 ( struct V_23 * V_8 )
{
T_1 V_191 = F_1 ( V_8 -> V_9 . V_2 , V_151 ) ;
int V_192 = 0 ;
if ( ! F_13 ( V_8 -> V_9 . V_2 ) )
V_192 = 1 ;
if ( ( V_191 & V_16 ) == 0 &&
F_105 ( V_191 ) == V_173 )
V_192 = 1 ;
return V_192 ;
}
void F_106 ( struct V_23 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
if ( V_2 && F_95 ( & V_2 -> V_108 . V_143 ) > 0 ) {
if ( F_96 ( V_2 , V_18 ) )
F_107 ( & V_2 -> V_108 . V_143 ) ;
}
}
int F_108 ( struct V_23 * V_8 )
{
int V_44 = F_103 ( V_8 ) ;
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
if ( V_44 == - 1 )
return - 1 ;
F_9 ( V_44 , V_2 -> V_4 + V_47 ) ;
F_36 ( V_2 ) ;
F_31 ( V_44 , V_2 ) ;
return V_44 ;
}
void F_109 ( struct V_23 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
V_2 -> V_132 = V_8 -> V_9 . V_10 &
V_172 ;
F_21 ( V_8 ) ;
F_36 ( V_2 ) ;
F_80 ( & V_2 -> V_108 . V_109 ) ;
F_72 ( V_2 ) ;
F_73 ( V_2 ) ;
V_2 -> V_37 = true ;
F_38 ( V_55 , V_8 ) ;
}
void F_110 ( struct V_23 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
struct V_193 * V_109 ;
if ( ! V_2 )
return;
V_109 = & V_2 -> V_108 . V_109 ;
if ( F_80 ( V_109 ) )
F_111 ( V_109 , V_145 ) ;
}
void F_112 ( struct V_23 * V_8 )
{
T_1 V_128 ;
void * V_194 ;
if ( ! F_22 ( V_8 -> V_28 ) || ! V_8 -> V_9 . V_2 -> V_195 )
return;
V_194 = F_113 ( V_8 -> V_9 . V_2 -> V_196 , V_197 ) ;
V_128 = * ( T_1 * ) ( V_194 + F_114 ( V_8 -> V_9 . V_2 -> V_195 ) ) ;
F_115 ( V_194 , V_197 ) ;
F_39 ( V_8 -> V_9 . V_2 , V_128 & 0xff ) ;
}
void F_116 ( struct V_23 * V_8 )
{
T_1 V_128 , V_48 ;
int V_198 , V_199 ;
struct V_1 * V_2 ;
void * V_194 ;
if ( ! F_22 ( V_8 -> V_28 ) || ! V_8 -> V_9 . V_2 -> V_195 )
return;
V_2 = V_8 -> V_9 . V_2 ;
V_48 = F_1 ( V_2 , V_54 ) & 0xff ;
V_198 = F_30 ( V_2 ) ;
if ( V_198 < 0 )
V_198 = 0 ;
V_199 = F_35 ( V_2 ) ;
if ( V_199 < 0 )
V_199 = 0 ;
V_128 = ( V_48 & 0xff ) | ( ( V_199 & 0xf0 ) << 8 ) | ( V_198 << 24 ) ;
V_194 = F_113 ( V_8 -> V_9 . V_2 -> V_196 , V_197 ) ;
* ( T_1 * ) ( V_194 + F_114 ( V_8 -> V_9 . V_2 -> V_195 ) ) = V_128 ;
F_115 ( V_194 , V_197 ) ;
}
void F_117 ( struct V_23 * V_8 , T_7 V_195 )
{
if ( ! F_22 ( V_8 -> V_28 ) )
return;
V_8 -> V_9 . V_2 -> V_195 = V_195 ;
}
int F_118 ( struct V_23 * V_8 , T_1 V_200 , T_6 V_128 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
T_1 V_153 = ( V_200 - V_201 ) << 4 ;
if ( ! F_22 ( V_8 -> V_28 ) || ! F_24 ( V_2 ) )
return 1 ;
if ( V_200 == 0x830 )
F_78 ( V_2 , V_97 , ( T_1 ) ( V_128 >> 32 ) ) ;
return F_78 ( V_2 , V_153 , ( T_1 ) V_128 ) ;
}
int F_119 ( struct V_23 * V_8 , T_1 V_200 , T_6 * V_128 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
T_1 V_153 = ( V_200 - V_201 ) << 4 , V_202 , V_203 = 0 ;
if ( ! F_22 ( V_8 -> V_28 ) || ! F_24 ( V_2 ) )
return 1 ;
if ( F_68 ( V_2 , V_153 , 4 , & V_202 ) )
return 1 ;
if ( V_200 == 0x830 )
F_68 ( V_2 , V_97 , 4 , & V_203 ) ;
* V_128 = ( ( ( T_6 ) V_203 ) << 32 ) | V_202 ;
return 0 ;
}
int F_120 ( struct V_23 * V_8 , T_1 V_153 , T_6 V_128 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
if ( ! F_22 ( V_8 -> V_28 ) )
return 1 ;
if ( V_153 == V_95 )
F_78 ( V_2 , V_97 , ( T_1 ) ( V_128 >> 32 ) ) ;
return F_78 ( V_2 , V_153 , ( T_1 ) V_128 ) ;
}
int F_121 ( struct V_23 * V_8 , T_1 V_153 , T_6 * V_128 )
{
struct V_1 * V_2 = V_8 -> V_9 . V_2 ;
T_1 V_202 , V_203 = 0 ;
if ( ! F_22 ( V_8 -> V_28 ) )
return 1 ;
if ( F_68 ( V_2 , V_153 , 4 , & V_202 ) )
return 1 ;
if ( V_153 == V_95 )
F_68 ( V_2 , V_97 , 4 , & V_203 ) ;
* V_128 = ( ( ( T_6 ) V_203 ) << 32 ) | V_202 ;
return 0 ;
}
