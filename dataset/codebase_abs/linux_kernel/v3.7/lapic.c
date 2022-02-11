static inline void F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
* ( ( T_1 * ) ( V_2 -> V_5 + V_3 ) ) = V_4 ;
}
static inline int F_2 ( int V_6 , void * V_7 )
{
return F_3 ( F_4 ( V_6 ) , ( V_7 ) + F_5 ( V_6 ) ) ;
}
static inline int F_6 ( int V_6 , void * V_7 )
{
return F_7 ( F_4 ( V_6 ) , ( V_7 ) + F_5 ( V_6 ) ) ;
}
static inline int F_8 ( int V_6 , void * V_7 )
{
return F_9 ( F_4 ( V_6 ) , ( V_7 ) + F_5 ( V_6 ) ) ;
}
static inline void F_10 ( int V_6 , void * V_7 )
{
F_11 ( F_4 ( V_6 ) , ( V_7 ) + F_5 ( V_6 ) ) ;
}
static inline void F_12 ( int V_6 , void * V_7 )
{
F_13 ( F_4 ( V_6 ) , ( V_7 ) + F_5 ( V_6 ) ) ;
}
static inline int F_14 ( int V_6 , void * V_7 )
{
return F_15 ( F_4 ( V_6 ) , ( V_7 ) + F_5 ( V_6 ) ) ;
}
static inline int F_16 ( int V_6 , void * V_7 )
{
return F_17 ( F_4 ( V_6 ) , ( V_7 ) + F_5 ( V_6 ) ) ;
}
static inline void F_18 ( struct V_1 * V_2 , T_1 V_4 )
{
if ( ( F_19 ( V_2 , V_8 ) ^ V_4 ) & V_9 ) {
if ( V_4 & V_9 )
F_20 ( & V_10 ) ;
else
F_21 ( & V_10 . V_11 ) ;
}
F_1 ( V_2 , V_8 , V_4 ) ;
}
static inline int F_22 ( struct V_1 * V_2 )
{
return F_23 ( V_2 ) && F_24 ( V_2 ) ;
}
static inline int F_25 ( struct V_1 * V_2 )
{
return V_2 -> V_12 -> V_13 . V_14 & V_15 ;
}
static inline int F_26 ( struct V_1 * V_2 )
{
return ( F_19 ( V_2 , V_16 ) >> 24 ) & 0xff ;
}
static inline T_2 F_27 ( struct V_17 * V_18 , T_1 V_19 )
{
T_2 V_20 ;
V_19 >>= 32 - V_18 -> V_21 ;
V_20 = ( V_19 >> V_18 -> V_22 ) & V_18 -> V_23 ;
F_28 ( V_20 >= F_29 ( V_18 -> V_24 ) ) ;
return V_20 ;
}
static inline T_2 F_30 ( struct V_17 * V_18 , T_1 V_19 )
{
V_19 >>= ( 32 - V_18 -> V_21 ) ;
return V_19 & V_18 -> V_25 ;
}
static void F_31 ( struct V_26 * V_26 )
{
struct V_17 * V_27 , * V_28 = NULL ;
struct V_29 * V_12 ;
int V_30 ;
V_27 = F_32 ( sizeof( struct V_17 ) , V_31 ) ;
F_33 ( & V_26 -> V_13 . V_32 ) ;
if ( ! V_27 )
goto V_33;
V_27 -> V_21 = 8 ;
V_27 -> V_22 = 8 ;
V_27 -> V_23 = 0 ;
V_27 -> V_25 = 0xff ;
F_34 (i, vcpu, kvm) {
struct V_1 * V_2 = V_12 -> V_13 . V_2 ;
T_2 V_20 , V_34 ;
T_1 V_19 ;
if ( ! F_35 ( V_12 ) )
continue;
if ( F_25 ( V_2 ) ) {
V_27 -> V_21 = 32 ;
V_27 -> V_22 = 16 ;
V_27 -> V_23 = V_27 -> V_25 = 0xffff ;
} else if ( F_23 ( V_2 ) &&
! V_27 -> V_23 &&
F_19 ( V_2 , V_35 ) == V_36 ) {
V_27 -> V_22 = 4 ;
V_27 -> V_23 = 0xf ;
V_27 -> V_25 = 0xf ;
}
V_27 -> V_37 [ F_26 ( V_2 ) ] = V_2 ;
V_19 = F_19 ( V_2 , V_38 ) ;
V_20 = F_27 ( V_27 , V_19 ) ;
V_34 = F_30 ( V_27 , V_19 ) ;
if ( V_34 )
V_27 -> V_24 [ V_20 ] [ F_36 ( V_34 ) - 1 ] = V_2 ;
}
V_33:
V_28 = F_37 ( V_26 -> V_13 . V_39 ,
F_38 ( & V_26 -> V_13 . V_32 ) ) ;
F_39 ( V_26 -> V_13 . V_39 , V_27 ) ;
F_40 ( & V_26 -> V_13 . V_32 ) ;
if ( V_28 )
F_41 ( V_28 , V_40 ) ;
}
static inline void F_42 ( struct V_1 * V_2 , T_3 V_41 )
{
F_1 ( V_2 , V_16 , V_41 << 24 ) ;
F_31 ( V_2 -> V_12 -> V_26 ) ;
}
static inline void F_43 ( struct V_1 * V_2 , T_1 V_41 )
{
F_1 ( V_2 , V_38 , V_41 ) ;
F_31 ( V_2 -> V_12 -> V_26 ) ;
}
static inline int F_44 ( struct V_1 * V_2 , int V_42 )
{
return ! ( F_19 ( V_2 , V_42 ) & V_43 ) ;
}
static inline int F_45 ( struct V_1 * V_2 , int V_42 )
{
return F_19 ( V_2 , V_42 ) & V_44 ;
}
static inline int F_46 ( struct V_1 * V_2 )
{
return ( ( F_19 ( V_2 , V_45 ) &
V_2 -> V_46 . V_47 ) == V_48 ) ;
}
static inline int F_47 ( struct V_1 * V_2 )
{
return ( ( F_19 ( V_2 , V_45 ) &
V_2 -> V_46 . V_47 ) == V_49 ) ;
}
static inline int F_48 ( struct V_1 * V_2 )
{
return ( ( F_19 ( V_2 , V_45 ) &
V_2 -> V_46 . V_47 ) ==
V_50 ) ;
}
static inline int F_49 ( T_1 V_51 )
{
return ( V_51 & ( V_52 | V_43 ) ) == V_53 ;
}
void F_50 ( struct V_29 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_13 . V_2 ;
struct V_54 * V_55 ;
T_1 V_56 = V_57 ;
if ( ! F_51 ( V_12 ) )
return;
V_55 = F_52 ( V_2 -> V_12 , 0x1 , 0 ) ;
if ( V_55 && ( V_55 -> V_58 & ( 1 << ( V_59 & 31 ) ) ) )
V_56 |= V_60 ;
F_1 ( V_2 , V_61 , V_56 ) ;
}
static int F_53 ( void * V_7 )
{
int V_6 ;
T_1 * V_62 ;
for ( V_6 = V_63 - V_64 ;
V_6 >= 0 ; V_6 -= V_64 ) {
V_62 = V_7 + F_5 ( V_6 ) ;
if ( * V_62 )
return F_54 ( * V_62 ) - 1 + V_6 ;
}
return - 1 ;
}
static T_3 F_55 ( void * V_7 )
{
int V_6 ;
T_1 * V_62 ;
T_3 V_65 = 0 ;
for ( V_6 = 0 ; V_6 < V_63 ; V_6 += V_64 ) {
V_62 = V_7 + F_5 ( V_6 ) ;
V_65 += F_56 ( * V_62 ) ;
}
return V_65 ;
}
static inline int F_57 ( int V_6 , struct V_1 * V_2 )
{
V_2 -> V_66 = true ;
return F_2 ( V_6 , V_2 -> V_5 + V_67 ) ;
}
static inline int F_58 ( struct V_1 * V_2 )
{
return F_53 ( V_2 -> V_5 + V_67 ) ;
}
static inline int F_59 ( struct V_1 * V_2 )
{
int V_68 ;
if ( ! V_2 -> V_66 )
return - 1 ;
V_68 = F_58 ( V_2 ) ;
ASSERT ( V_68 == - 1 || V_68 >= 16 ) ;
return V_68 ;
}
static inline void F_60 ( int V_6 , struct V_1 * V_2 )
{
V_2 -> V_66 = false ;
F_12 ( V_6 , V_2 -> V_5 + V_67 ) ;
if ( F_58 ( V_2 ) != - 1 )
V_2 -> V_66 = true ;
}
static inline void F_61 ( int V_6 , struct V_1 * V_2 )
{
if ( ! F_14 ( V_6 , V_2 -> V_5 + V_69 ) )
++ V_2 -> V_70 ;
F_28 ( V_2 -> V_70 > V_63 ) ;
V_2 -> V_71 = V_6 ;
}
static inline void F_62 ( int V_6 , struct V_1 * V_2 )
{
if ( F_16 ( V_6 , V_2 -> V_5 + V_69 ) )
-- V_2 -> V_70 ;
F_28 ( V_2 -> V_70 < 0 ) ;
V_2 -> V_71 = - 1 ;
}
int F_63 ( struct V_29 * V_12 )
{
int V_72 ;
if ( ! F_51 ( V_12 ) )
return 0 ;
V_72 = F_59 ( V_12 -> V_13 . V_2 ) ;
return V_72 ;
}
int F_64 ( struct V_29 * V_12 , struct V_73 * V_74 )
{
struct V_1 * V_2 = V_12 -> V_13 . V_2 ;
return F_65 ( V_2 , V_74 -> V_75 , V_74 -> V_76 ,
V_74 -> V_77 , V_74 -> V_78 ) ;
}
static int F_66 ( struct V_29 * V_12 , T_3 V_4 )
{
return F_67 ( V_12 -> V_26 , & V_12 -> V_13 . V_79 . V_80 , & V_4 ,
sizeof( V_4 ) ) ;
}
static int F_68 ( struct V_29 * V_12 , T_3 * V_4 )
{
return F_69 ( V_12 -> V_26 , & V_12 -> V_13 . V_79 . V_80 , V_4 ,
sizeof( * V_4 ) ) ;
}
static inline bool F_70 ( struct V_29 * V_12 )
{
return V_12 -> V_13 . V_79 . V_81 & V_82 ;
}
static bool F_71 ( struct V_29 * V_12 )
{
T_3 V_4 ;
if ( F_68 ( V_12 , & V_4 ) < 0 )
F_72 ( L_1 ,
( unsigned long long ) V_83 -> V_13 . V_79 . V_81 ) ;
return V_4 & 0x1 ;
}
static void F_73 ( struct V_29 * V_12 )
{
if ( F_66 ( V_12 , V_84 ) < 0 ) {
F_72 ( L_2 ,
( unsigned long long ) V_83 -> V_13 . V_79 . V_81 ) ;
return;
}
F_74 ( V_85 , & V_12 -> V_13 . V_86 ) ;
}
static void F_75 ( struct V_29 * V_12 )
{
if ( F_66 ( V_12 , V_87 ) < 0 ) {
F_72 ( L_3 ,
( unsigned long long ) V_83 -> V_13 . V_79 . V_81 ) ;
return;
}
F_76 ( V_85 , & V_12 -> V_13 . V_86 ) ;
}
static inline int F_77 ( struct V_1 * V_2 )
{
int V_68 ;
if ( ! V_2 -> V_70 )
return - 1 ;
if ( F_78 ( V_2 -> V_71 != - 1 ) )
return V_2 -> V_71 ;
V_68 = F_53 ( V_2 -> V_5 + V_69 ) ;
ASSERT ( V_68 == - 1 || V_68 >= 16 ) ;
return V_68 ;
}
static void F_79 ( struct V_1 * V_2 )
{
T_1 V_88 , V_89 , V_90 , V_91 ;
int V_92 ;
V_91 = F_19 ( V_2 , V_93 ) ;
V_88 = F_19 ( V_2 , V_94 ) ;
V_92 = F_77 ( V_2 ) ;
V_89 = ( V_92 != - 1 ) ? V_92 : 0 ;
if ( ( V_88 & 0xf0 ) >= ( V_89 & 0xf0 ) )
V_90 = V_88 & 0xff ;
else
V_90 = V_89 & 0xf0 ;
F_72 ( L_4 ,
V_2 , V_90 , V_92 , V_89 ) ;
if ( V_91 != V_90 ) {
F_1 ( V_2 , V_93 , V_90 ) ;
if ( V_90 < V_91 )
F_80 ( V_95 , V_2 -> V_12 ) ;
}
}
static void F_81 ( struct V_1 * V_2 , T_1 V_88 )
{
F_1 ( V_2 , V_94 , V_88 ) ;
F_79 ( V_2 ) ;
}
int F_82 ( struct V_1 * V_2 , T_2 V_96 )
{
return V_96 == 0xff || F_26 ( V_2 ) == V_96 ;
}
int F_83 ( struct V_1 * V_2 , T_3 V_97 )
{
int V_68 = 0 ;
T_1 V_98 ;
if ( F_25 ( V_2 ) ) {
V_98 = F_19 ( V_2 , V_38 ) ;
return V_98 & V_97 ;
}
V_98 = F_84 ( F_19 ( V_2 , V_38 ) ) ;
switch ( F_19 ( V_2 , V_35 ) ) {
case V_99 :
if ( V_98 & V_97 )
V_68 = 1 ;
break;
case V_36 :
if ( ( ( V_98 >> 4 ) == ( V_97 >> 0x4 ) )
&& ( V_98 & V_97 & 0xf ) )
V_68 = 1 ;
break;
default:
F_72 ( L_5 ,
V_2 -> V_12 -> V_100 , F_19 ( V_2 , V_35 ) ) ;
break;
}
return V_68 ;
}
int F_85 ( struct V_29 * V_12 , struct V_1 * V_101 ,
int V_102 , int V_96 , int V_103 )
{
int V_68 = 0 ;
struct V_1 * V_104 = V_12 -> V_13 . V_2 ;
F_72 ( L_6
L_7 ,
V_104 , V_101 , V_96 , V_103 , V_102 ) ;
ASSERT ( V_104 ) ;
switch ( V_102 ) {
case V_105 :
if ( V_103 == 0 )
V_68 = F_82 ( V_104 , V_96 ) ;
else
V_68 = F_83 ( V_104 , V_96 ) ;
break;
case V_106 :
V_68 = ( V_104 == V_101 ) ;
break;
case V_107 :
V_68 = 1 ;
break;
case V_108 :
V_68 = ( V_104 != V_101 ) ;
break;
default:
F_72 ( L_8 ,
V_102 ) ;
break;
}
return V_68 ;
}
bool F_86 ( struct V_26 * V_26 , struct V_1 * V_109 ,
struct V_73 * V_74 , int * V_110 )
{
struct V_17 * V_18 ;
unsigned long V_7 = 1 ;
struct V_1 * * V_111 ;
int V_30 ;
bool V_112 = false ;
* V_110 = - 1 ;
if ( V_74 -> V_113 == V_106 ) {
* V_110 = F_64 ( V_109 -> V_12 , V_74 ) ;
return true ;
}
if ( V_74 -> V_113 )
return false ;
F_87 () ;
V_18 = F_88 ( V_26 -> V_13 . V_39 ) ;
if ( ! V_18 )
goto V_33;
if ( V_74 -> V_103 == 0 ) {
if ( V_74 -> V_75 == V_114 ||
V_74 -> V_115 == 0xff )
goto V_33;
V_111 = & V_18 -> V_37 [ V_74 -> V_115 & 0xff ] ;
} else {
T_1 V_97 = V_74 -> V_115 << ( 32 - V_18 -> V_21 ) ;
V_111 = V_18 -> V_24 [ F_27 ( V_18 , V_97 ) ] ;
V_7 = F_30 ( V_18 , V_97 ) ;
if ( V_74 -> V_75 == V_114 ) {
int V_116 = - 1 ;
F_89 (i, &bitmap, 16 ) {
if ( ! V_111 [ V_30 ] )
continue;
if ( V_116 < 0 )
V_116 = V_30 ;
else if ( F_90 ( V_111 [ V_30 ] -> V_12 , V_111 [ V_116 ] -> V_12 ) < 0 )
V_116 = V_30 ;
}
V_7 = ( V_116 >= 0 ) ? 1 << V_116 : 0 ;
}
}
F_89 (i, &bitmap, 16 ) {
if ( ! V_111 [ V_30 ] )
continue;
if ( * V_110 < 0 )
* V_110 = 0 ;
* V_110 += F_64 ( V_111 [ V_30 ] -> V_12 , V_74 ) ;
}
V_112 = true ;
V_33:
F_91 () ;
return V_112 ;
}
static int F_65 ( struct V_1 * V_2 , int V_75 ,
int V_76 , int V_77 , int V_78 )
{
int V_68 = 0 ;
struct V_29 * V_12 = V_2 -> V_12 ;
switch ( V_75 ) {
case V_114 :
V_12 -> V_13 . V_117 ++ ;
case V_118 :
if ( F_92 ( ! F_22 ( V_2 ) ) )
break;
if ( V_78 ) {
F_72 ( L_9 , V_76 ) ;
F_10 ( V_76 , V_2 -> V_5 + V_119 ) ;
} else
F_12 ( V_76 , V_2 -> V_5 + V_119 ) ;
V_68 = ! F_57 ( V_76 , V_2 ) ;
F_93 ( V_12 -> V_100 , V_75 ,
V_78 , V_76 , ! V_68 ) ;
if ( ! V_68 ) {
if ( V_78 )
F_72 ( L_10
L_11 , V_76 ) ;
break;
}
F_80 ( V_95 , V_12 ) ;
F_94 ( V_12 ) ;
break;
case V_120 :
F_72 ( L_12 ) ;
break;
case V_121 :
F_72 ( L_13 ) ;
break;
case V_53 :
V_68 = 1 ;
F_95 ( V_12 ) ;
F_94 ( V_12 ) ;
break;
case V_122 :
if ( ! V_78 || V_77 ) {
V_68 = 1 ;
V_12 -> V_13 . V_123 = V_124 ;
F_80 ( V_95 , V_12 ) ;
F_94 ( V_12 ) ;
} else {
F_72 ( L_14 ,
V_12 -> V_100 ) ;
}
break;
case V_125 :
F_72 ( L_15 ,
V_12 -> V_100 , V_76 ) ;
if ( V_12 -> V_13 . V_123 == V_124 ) {
V_68 = 1 ;
V_12 -> V_13 . V_126 = V_76 ;
V_12 -> V_13 . V_123 = V_127 ;
F_80 ( V_95 , V_12 ) ;
F_94 ( V_12 ) ;
}
break;
case V_128 :
break;
default:
F_96 ( V_129 L_16 ,
V_75 ) ;
break;
}
return V_68 ;
}
int F_90 ( struct V_29 * V_130 , struct V_29 * V_131 )
{
return V_130 -> V_13 . V_117 - V_131 -> V_13 . V_117 ;
}
static int F_97 ( struct V_1 * V_2 )
{
int V_76 = F_77 ( V_2 ) ;
F_98 ( V_2 , V_76 ) ;
if ( V_76 == - 1 )
return V_76 ;
F_62 ( V_76 , V_2 ) ;
F_79 ( V_2 ) ;
if ( ! ( F_19 ( V_2 , V_8 ) & V_132 ) &&
F_99 ( V_2 -> V_12 -> V_26 , V_76 ) ) {
int V_133 ;
if ( F_8 ( V_76 , V_2 -> V_5 + V_119 ) )
V_133 = V_134 ;
else
V_133 = V_135 ;
F_100 ( V_2 -> V_12 -> V_26 , V_76 , V_133 ) ;
}
F_80 ( V_95 , V_2 -> V_12 ) ;
return V_76 ;
}
static void F_101 ( struct V_1 * V_2 )
{
T_1 V_136 = F_19 ( V_2 , V_137 ) ;
T_1 V_138 = F_19 ( V_2 , V_139 ) ;
struct V_73 V_74 ;
V_74 . V_76 = V_136 & V_44 ;
V_74 . V_75 = V_136 & V_52 ;
V_74 . V_103 = V_136 & V_140 ;
V_74 . V_77 = V_136 & V_141 ;
V_74 . V_78 = V_136 & V_142 ;
V_74 . V_113 = V_136 & V_143 ;
if ( F_25 ( V_2 ) )
V_74 . V_115 = V_138 ;
else
V_74 . V_115 = F_102 ( V_138 ) ;
F_103 ( V_136 , V_74 . V_115 ) ;
F_72 ( L_17
L_18
L_19 ,
V_138 , V_136 , V_74 . V_113 , V_74 . V_115 ,
V_74 . V_78 , V_74 . V_77 , V_74 . V_103 , V_74 . V_75 ,
V_74 . V_76 ) ;
F_104 ( V_2 -> V_12 -> V_26 , V_2 , & V_74 ) ;
}
static T_1 F_105 ( struct V_1 * V_2 )
{
T_4 V_144 ;
T_5 V_145 ;
T_1 V_146 ;
ASSERT ( V_2 != NULL ) ;
if ( F_19 ( V_2 , V_147 ) == 0 )
return 0 ;
V_144 = F_106 ( & V_2 -> V_46 . V_148 ) ;
if ( F_107 ( V_144 ) < 0 )
V_144 = F_108 ( 0 , 0 ) ;
V_145 = F_109 ( F_107 ( V_144 ) , V_2 -> V_46 . V_149 ) ;
V_146 = F_110 ( V_145 ,
( V_150 * V_2 -> V_151 ) ) ;
return V_146 ;
}
static void F_111 ( struct V_1 * V_2 , bool V_152 )
{
struct V_29 * V_12 = V_2 -> V_12 ;
struct V_153 * V_154 = V_12 -> V_154 ;
F_80 ( V_155 , V_12 ) ;
V_154 -> V_156 . V_157 = F_112 ( V_12 ) ;
V_154 -> V_156 . V_158 = V_152 ;
}
static inline void F_113 ( struct V_1 * V_2 , bool V_152 )
{
if ( V_2 -> V_12 -> V_13 . V_159 )
F_111 ( V_2 , V_152 ) ;
}
static T_1 F_114 ( struct V_1 * V_2 , unsigned int V_160 )
{
T_1 V_4 = 0 ;
if ( V_160 >= V_161 )
return 0 ;
switch ( V_160 ) {
case V_16 :
if ( F_25 ( V_2 ) )
V_4 = F_26 ( V_2 ) ;
else
V_4 = F_26 ( V_2 ) << 24 ;
break;
case V_162 :
F_72 ( L_20 ) ;
break;
case V_163 :
if ( F_48 ( V_2 ) )
return 0 ;
V_4 = F_105 ( V_2 ) ;
break;
case V_93 :
F_79 ( V_2 ) ;
V_4 = F_19 ( V_2 , V_160 ) ;
break;
case V_94 :
F_113 ( V_2 , false ) ;
default:
V_4 = F_19 ( V_2 , V_160 ) ;
break;
}
return V_4 ;
}
static inline struct V_1 * F_115 ( struct V_164 * V_165 )
{
return F_116 ( V_165 , struct V_1 , V_165 ) ;
}
static int F_117 ( struct V_1 * V_2 , T_1 V_160 , int V_166 ,
void * V_80 )
{
unsigned char V_167 = V_160 & 0xf ;
T_1 V_68 ;
static const T_6 V_168 = 0x43ff01ffffffe70cULL ;
if ( ( V_167 + V_166 ) > 4 ) {
F_72 ( L_21 ,
V_160 , V_166 ) ;
return 1 ;
}
if ( V_160 > 0x3f0 || ! ( V_168 & ( 1ULL << ( V_160 >> 4 ) ) ) ) {
F_72 ( L_22 ,
V_160 ) ;
return 1 ;
}
V_68 = F_114 ( V_2 , V_160 & ~ 0xf ) ;
F_118 ( V_160 , V_68 ) ;
switch ( V_166 ) {
case 1 :
case 2 :
case 4 :
memcpy ( V_80 , ( char * ) & V_68 + V_167 , V_166 ) ;
break;
default:
F_96 ( V_129 L_23
L_24 , V_166 ) ;
break;
}
return 0 ;
}
static int F_119 ( struct V_1 * V_2 , T_7 V_169 )
{
return F_24 ( V_2 ) &&
V_169 >= V_2 -> V_170 &&
V_169 < V_2 -> V_170 + V_161 ;
}
static int F_120 ( struct V_164 * V_171 ,
T_7 V_172 , int V_166 , void * V_80 )
{
struct V_1 * V_2 = F_115 ( V_171 ) ;
T_1 V_160 = V_172 - V_2 -> V_170 ;
if ( ! F_119 ( V_2 , V_172 ) )
return - V_173 ;
F_117 ( V_2 , V_160 , V_166 , V_80 ) ;
return 0 ;
}
static void F_121 ( struct V_1 * V_2 )
{
T_1 V_174 , V_175 , V_176 ;
V_176 = F_19 ( V_2 , V_177 ) ;
V_174 = V_176 & 0xf ;
V_175 = ( ( V_174 & 0x3 ) | ( ( V_174 & 0x8 ) >> 1 ) ) + 1 ;
V_2 -> V_151 = 0x1 << ( V_175 & 0x7 ) ;
F_72 ( L_25 ,
V_2 -> V_151 ) ;
}
static void F_122 ( struct V_1 * V_2 )
{
T_4 V_178 ;
F_123 ( & V_2 -> V_46 . V_179 , 0 ) ;
if ( F_47 ( V_2 ) || F_46 ( V_2 ) ) {
V_178 = V_2 -> V_46 . V_148 . V_180 -> V_181 () ;
V_2 -> V_46 . V_149 = ( T_6 ) F_19 ( V_2 , V_147 )
* V_150 * V_2 -> V_151 ;
if ( ! V_2 -> V_46 . V_149 )
return;
if ( F_47 ( V_2 ) ) {
T_5 V_182 = V_183 * 1000LL ;
if ( V_2 -> V_46 . V_149 < V_182 ) {
F_124 (
L_26
L_27 ,
V_2 -> V_12 -> V_100 ,
V_2 -> V_46 . V_149 , V_182 ) ;
V_2 -> V_46 . V_149 = V_182 ;
}
}
F_125 ( & V_2 -> V_46 . V_148 ,
F_126 ( V_178 , V_2 -> V_46 . V_149 ) ,
V_184 ) ;
F_72 ( L_28 V_185 L_29
V_186 L_30
L_31
L_32 V_186 L_33 , V_187 ,
V_150 , F_107 ( V_178 ) ,
F_19 ( V_2 , V_147 ) ,
V_2 -> V_46 . V_149 ,
F_107 ( F_126 ( V_178 ,
V_2 -> V_46 . V_149 ) ) ) ;
} else if ( F_48 ( V_2 ) ) {
T_6 V_188 , V_189 = V_2 -> V_46 . V_189 ;
T_6 V_145 = 0 ;
struct V_29 * V_12 = V_2 -> V_12 ;
unsigned long V_190 = V_12 -> V_13 . V_191 ;
unsigned long V_192 ;
if ( F_92 ( ! V_189 || ! V_190 ) )
return;
F_127 ( V_192 ) ;
V_178 = V_2 -> V_46 . V_148 . V_180 -> V_181 () ;
V_188 = V_193 -> V_194 ( V_12 ) ;
if ( F_78 ( V_189 > V_188 ) ) {
V_145 = ( V_189 - V_188 ) * 1000000ULL ;
F_128 ( V_145 , V_190 ) ;
}
F_125 ( & V_2 -> V_46 . V_148 ,
F_126 ( V_178 , V_145 ) , V_184 ) ;
F_129 ( V_192 ) ;
}
}
static void F_130 ( struct V_1 * V_2 , T_1 V_195 )
{
int V_196 = F_49 ( F_19 ( V_2 , V_197 ) ) ;
if ( F_49 ( V_195 ) ) {
if ( ! V_196 ) {
F_72 ( L_34
L_35 , V_2 -> V_12 -> V_100 ) ;
V_2 -> V_12 -> V_26 -> V_13 . V_198 ++ ;
}
} else if ( V_196 )
V_2 -> V_12 -> V_26 -> V_13 . V_198 -- ;
}
static int F_131 ( struct V_1 * V_2 , T_1 V_62 , T_1 V_4 )
{
int V_112 = 0 ;
F_132 ( V_62 , V_4 ) ;
switch ( V_62 ) {
case V_16 :
if ( ! F_25 ( V_2 ) )
F_42 ( V_2 , V_4 >> 24 ) ;
else
V_112 = 1 ;
break;
case V_94 :
F_113 ( V_2 , true ) ;
F_81 ( V_2 , V_4 & 0xff ) ;
break;
case V_199 :
F_97 ( V_2 ) ;
break;
case V_38 :
if ( ! F_25 ( V_2 ) )
F_43 ( V_2 , V_4 & V_200 ) ;
else
V_112 = 1 ;
break;
case V_35 :
if ( ! F_25 ( V_2 ) ) {
F_1 ( V_2 , V_35 , V_4 | 0x0FFFFFFF ) ;
F_31 ( V_2 -> V_12 -> V_26 ) ;
} else
V_112 = 1 ;
break;
case V_8 : {
T_1 V_201 = 0x3ff ;
if ( F_19 ( V_2 , V_61 ) & V_60 )
V_201 |= V_132 ;
F_18 ( V_2 , V_4 & V_201 ) ;
if ( ! ( V_4 & V_9 ) ) {
int V_30 ;
T_1 V_51 ;
for ( V_30 = 0 ; V_30 < V_202 ; V_30 ++ ) {
V_51 = F_19 ( V_2 ,
V_45 + 0x10 * V_30 ) ;
F_1 ( V_2 , V_45 + 0x10 * V_30 ,
V_51 | V_43 ) ;
}
F_123 ( & V_2 -> V_46 . V_179 , 0 ) ;
}
break;
}
case V_137 :
F_1 ( V_2 , V_137 , V_4 & ~ ( 1 << 12 ) ) ;
F_101 ( V_2 ) ;
break;
case V_139 :
if ( ! F_25 ( V_2 ) )
V_4 &= 0xff000000 ;
F_1 ( V_2 , V_139 , V_4 ) ;
break;
case V_197 :
F_130 ( V_2 , V_4 ) ;
case V_203 :
case V_204 :
case V_205 :
case V_206 :
if ( ! F_23 ( V_2 ) )
V_4 |= V_43 ;
V_4 &= V_207 [ ( V_62 - V_45 ) >> 4 ] ;
F_1 ( V_2 , V_62 , V_4 ) ;
break;
case V_45 :
if ( ( F_19 ( V_2 , V_45 ) &
V_2 -> V_46 . V_47 ) !=
( V_4 & V_2 -> V_46 . V_47 ) )
F_133 ( & V_2 -> V_46 . V_148 ) ;
if ( ! F_23 ( V_2 ) )
V_4 |= V_43 ;
V_4 &= ( V_207 [ 0 ] | V_2 -> V_46 . V_47 ) ;
F_1 ( V_2 , V_45 , V_4 ) ;
break;
case V_147 :
if ( F_48 ( V_2 ) )
break;
F_133 ( & V_2 -> V_46 . V_148 ) ;
F_1 ( V_2 , V_147 , V_4 ) ;
F_122 ( V_2 ) ;
break;
case V_177 :
if ( V_4 & 4 )
F_72 ( L_36 , V_4 ) ;
F_1 ( V_2 , V_177 , V_4 ) ;
F_121 ( V_2 ) ;
break;
case V_208 :
if ( F_25 ( V_2 ) && V_4 != 0 ) {
F_72 ( L_37 , V_4 ) ;
V_112 = 1 ;
}
break;
case V_209 :
if ( F_25 ( V_2 ) ) {
F_131 ( V_2 , V_137 , 0x40000 | ( V_4 & 0xff ) ) ;
} else
V_112 = 1 ;
break;
default:
V_112 = 1 ;
break;
}
if ( V_112 )
F_72 ( L_38 , V_62 ) ;
return V_112 ;
}
static int F_134 ( struct V_164 * V_171 ,
T_7 V_172 , int V_166 , const void * V_80 )
{
struct V_1 * V_2 = F_115 ( V_171 ) ;
unsigned int V_160 = V_172 - V_2 -> V_170 ;
T_1 V_4 ;
if ( ! F_119 ( V_2 , V_172 ) )
return - V_173 ;
if ( V_166 != 4 || ( V_160 & 0xf ) ) {
F_72 ( L_39 , V_166 , ( long ) V_172 ) ;
return 0 ;
}
V_4 = * ( T_1 * ) V_80 ;
if ( V_160 != V_199 )
F_72 ( L_40
L_41 , V_187 , V_160 , V_166 , V_4 ) ;
F_131 ( V_2 , V_160 & 0xff0 , V_4 ) ;
return 0 ;
}
void F_135 ( struct V_29 * V_12 )
{
if ( F_51 ( V_12 ) )
F_131 ( V_12 -> V_13 . V_2 , V_199 , 0 ) ;
}
void F_136 ( struct V_29 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_13 . V_2 ;
if ( ! V_12 -> V_13 . V_2 )
return;
F_133 ( & V_2 -> V_46 . V_148 ) ;
if ( ! ( V_12 -> V_13 . V_14 & V_210 ) )
F_20 ( & V_211 ) ;
if ( ! ( F_19 ( V_2 , V_8 ) & V_9 ) )
F_20 ( & V_10 ) ;
if ( V_2 -> V_5 )
F_137 ( ( unsigned long ) V_2 -> V_5 ) ;
F_138 ( V_2 ) ;
}
T_6 F_139 ( struct V_29 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_13 . V_2 ;
if ( ! F_51 ( V_12 ) || F_46 ( V_2 ) ||
F_47 ( V_2 ) )
return 0 ;
return V_2 -> V_46 . V_189 ;
}
void F_140 ( struct V_29 * V_12 , T_6 V_80 )
{
struct V_1 * V_2 = V_12 -> V_13 . V_2 ;
if ( ! F_51 ( V_12 ) || F_46 ( V_2 ) ||
F_47 ( V_2 ) )
return;
F_133 ( & V_2 -> V_46 . V_148 ) ;
V_2 -> V_46 . V_189 = V_80 ;
F_122 ( V_2 ) ;
}
void F_141 ( struct V_29 * V_12 , unsigned long V_212 )
{
struct V_1 * V_2 = V_12 -> V_13 . V_2 ;
if ( ! F_51 ( V_12 ) )
return;
F_81 ( V_2 , ( ( V_212 & 0x0f ) << 4 )
| ( F_19 ( V_2 , V_94 ) & 4 ) ) ;
}
T_6 F_142 ( struct V_29 * V_12 )
{
T_6 V_88 ;
if ( ! F_51 ( V_12 ) )
return 0 ;
V_88 = ( T_6 ) F_19 ( V_12 -> V_13 . V_2 , V_94 ) ;
return ( V_88 & 0xf0 ) >> 4 ;
}
void F_143 ( struct V_29 * V_12 , T_6 V_213 )
{
struct V_1 * V_2 = V_12 -> V_13 . V_2 ;
if ( ! V_2 ) {
V_213 |= V_214 ;
V_12 -> V_13 . V_14 = V_213 ;
return;
}
if ( ( V_12 -> V_13 . V_14 ^ V_213 ) & V_210 ) {
if ( V_213 & V_210 )
F_20 ( & V_211 ) ;
else
F_21 ( & V_211 . V_11 ) ;
F_31 ( V_12 -> V_26 ) ;
}
if ( ! F_144 ( V_2 -> V_12 ) )
V_213 &= ~ V_214 ;
V_12 -> V_13 . V_14 = V_213 ;
if ( F_25 ( V_2 ) ) {
T_1 V_41 = F_26 ( V_2 ) ;
T_1 V_19 = ( ( V_41 >> 4 ) << 16 ) | ( 1 << ( V_41 & 0xf ) ) ;
F_43 ( V_2 , V_19 ) ;
}
V_2 -> V_170 = V_2 -> V_12 -> V_13 . V_14 &
V_215 ;
F_72 ( L_42 V_186 L_43
L_44 , V_2 -> V_12 -> V_13 . V_14 , V_2 -> V_170 ) ;
}
void F_145 ( struct V_29 * V_12 )
{
struct V_1 * V_2 ;
int V_30 ;
F_72 ( L_45 , V_187 ) ;
ASSERT ( V_12 ) ;
V_2 = V_12 -> V_13 . V_2 ;
ASSERT ( V_2 != NULL ) ;
F_133 ( & V_2 -> V_46 . V_148 ) ;
F_42 ( V_2 , V_12 -> V_100 ) ;
F_50 ( V_2 -> V_12 ) ;
for ( V_30 = 0 ; V_30 < V_202 ; V_30 ++ )
F_1 ( V_2 , V_45 + 0x10 * V_30 , V_43 ) ;
F_1 ( V_2 , V_197 ,
F_146 ( 0 , V_216 ) ) ;
F_1 ( V_2 , V_35 , 0xffffffffU ) ;
F_18 ( V_2 , 0xff ) ;
F_1 ( V_2 , V_94 , 0 ) ;
F_43 ( V_2 , 0 ) ;
F_1 ( V_2 , V_208 , 0 ) ;
F_1 ( V_2 , V_137 , 0 ) ;
F_1 ( V_2 , V_139 , 0 ) ;
F_1 ( V_2 , V_177 , 0 ) ;
F_1 ( V_2 , V_147 , 0 ) ;
for ( V_30 = 0 ; V_30 < 8 ; V_30 ++ ) {
F_1 ( V_2 , V_67 + 0x10 * V_30 , 0 ) ;
F_1 ( V_2 , V_69 + 0x10 * V_30 , 0 ) ;
F_1 ( V_2 , V_119 + 0x10 * V_30 , 0 ) ;
}
V_2 -> V_66 = false ;
V_2 -> V_70 = 0 ;
V_2 -> V_71 = - 1 ;
F_121 ( V_2 ) ;
F_123 ( & V_2 -> V_46 . V_179 , 0 ) ;
if ( F_144 ( V_12 ) )
F_143 ( V_12 ,
V_12 -> V_13 . V_14 | V_214 ) ;
V_12 -> V_13 . V_79 . V_81 = 0 ;
F_79 ( V_2 ) ;
V_12 -> V_13 . V_117 = 0 ;
V_12 -> V_13 . V_86 = 0 ;
F_72 ( V_217 L_46
L_47 V_186 L_48 , V_187 ,
V_12 , F_26 ( V_2 ) ,
V_12 -> V_13 . V_14 , V_2 -> V_170 ) ;
}
static bool F_147 ( struct V_1 * V_2 )
{
return F_47 ( V_2 ) ;
}
int F_148 ( struct V_29 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_13 . V_2 ;
if ( F_51 ( V_12 ) && F_22 ( V_2 ) &&
F_44 ( V_2 , V_45 ) )
return F_149 ( & V_2 -> V_46 . V_179 ) ;
return 0 ;
}
int F_150 ( struct V_1 * V_2 , int V_42 )
{
T_1 V_62 = F_19 ( V_2 , V_42 ) ;
int V_76 , V_218 , V_78 ;
if ( F_24 ( V_2 ) && ! ( V_62 & V_43 ) ) {
V_76 = V_62 & V_44 ;
V_218 = V_62 & V_52 ;
V_78 = V_62 & V_219 ;
return F_65 ( V_2 , V_218 , V_76 , 1 , V_78 ) ;
}
return 0 ;
}
void F_151 ( struct V_29 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_13 . V_2 ;
if ( V_2 )
F_150 ( V_2 , V_197 ) ;
}
static enum V_220 F_152 ( struct V_221 * V_80 )
{
struct V_222 * V_223 = F_116 ( V_80 , struct V_222 , V_148 ) ;
struct V_1 * V_2 = F_116 ( V_223 , struct V_1 , V_46 ) ;
struct V_29 * V_12 = V_2 -> V_12 ;
T_8 * V_224 = & V_12 -> V_225 ;
if ( ! F_149 ( & V_223 -> V_179 ) ) {
F_153 ( & V_223 -> V_179 ) ;
F_80 ( V_226 , V_12 ) ;
}
if ( F_154 ( V_224 ) )
F_155 ( V_224 ) ;
if ( F_147 ( V_2 ) ) {
F_156 ( & V_223 -> V_148 , V_223 -> V_149 ) ;
return V_227 ;
} else
return V_228 ;
}
int F_157 ( struct V_29 * V_12 )
{
struct V_1 * V_2 ;
ASSERT ( V_12 != NULL ) ;
F_72 ( L_49 , V_12 -> V_100 ) ;
V_2 = F_32 ( sizeof( * V_2 ) , V_31 ) ;
if ( ! V_2 )
goto V_229;
V_12 -> V_13 . V_2 = V_2 ;
V_2 -> V_5 = ( void * ) F_158 ( V_31 ) ;
if ( ! V_2 -> V_5 ) {
F_96 ( V_129 L_50 ,
V_12 -> V_100 ) ;
goto V_230;
}
V_2 -> V_12 = V_12 ;
F_159 ( & V_2 -> V_46 . V_148 , V_231 ,
V_184 ) ;
V_2 -> V_46 . V_148 . V_232 = F_152 ;
V_12 -> V_13 . V_14 = V_210 ;
F_143 ( V_12 ,
V_233 | V_210 ) ;
F_21 ( & V_10 . V_11 ) ;
F_145 ( V_12 ) ;
F_160 ( & V_2 -> V_165 , & V_234 ) ;
return 0 ;
V_230:
F_138 ( V_2 ) ;
V_229:
return - V_235 ;
}
int F_161 ( struct V_29 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_13 . V_2 ;
int V_72 ;
if ( ! F_51 ( V_12 ) || ! F_22 ( V_2 ) )
return - 1 ;
F_79 ( V_2 ) ;
V_72 = F_59 ( V_2 ) ;
if ( ( V_72 == - 1 ) ||
( ( V_72 & 0xF0 ) <= F_19 ( V_2 , V_93 ) ) )
return - 1 ;
return V_72 ;
}
int F_162 ( struct V_29 * V_12 )
{
T_1 V_236 = F_19 ( V_12 -> V_13 . V_2 , V_197 ) ;
int V_110 = 0 ;
if ( ! F_24 ( V_12 -> V_13 . V_2 ) )
V_110 = 1 ;
if ( ( V_236 & V_43 ) == 0 &&
F_163 ( V_236 ) == V_216 )
V_110 = 1 ;
return V_110 ;
}
void F_164 ( struct V_29 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_13 . V_2 ;
if ( ! F_51 ( V_12 ) )
return;
if ( F_149 ( & V_2 -> V_46 . V_179 ) > 0 ) {
if ( F_150 ( V_2 , V_45 ) )
F_165 ( & V_2 -> V_46 . V_179 ) ;
}
}
int F_166 ( struct V_29 * V_12 )
{
int V_76 = F_161 ( V_12 ) ;
struct V_1 * V_2 = V_12 -> V_13 . V_2 ;
if ( V_76 == - 1 )
return - 1 ;
F_61 ( V_76 , V_2 ) ;
F_79 ( V_2 ) ;
F_60 ( V_76 , V_2 ) ;
return V_76 ;
}
void F_167 ( struct V_29 * V_12 ,
struct V_237 * V_238 )
{
struct V_1 * V_2 = V_12 -> V_13 . V_2 ;
F_143 ( V_12 , V_12 -> V_13 . V_14 ) ;
F_18 ( V_2 , * ( ( T_1 * ) ( V_238 -> V_5 + V_8 ) ) ) ;
memcpy ( V_12 -> V_13 . V_2 -> V_5 , V_238 -> V_5 , sizeof *V_238 ) ;
F_42 ( V_2 , F_26 ( V_2 ) ) ;
F_50 ( V_12 ) ;
F_79 ( V_2 ) ;
F_133 ( & V_2 -> V_46 . V_148 ) ;
F_121 ( V_2 ) ;
F_122 ( V_2 ) ;
V_2 -> V_66 = true ;
V_2 -> V_70 = F_55 ( V_2 -> V_5 + V_69 ) ;
V_2 -> V_71 = - 1 ;
F_80 ( V_95 , V_12 ) ;
}
void F_168 ( struct V_29 * V_12 )
{
struct V_221 * V_148 ;
if ( ! F_51 ( V_12 ) )
return;
V_148 = & V_12 -> V_13 . V_2 -> V_46 . V_148 ;
if ( F_133 ( V_148 ) )
F_169 ( V_148 , V_184 ) ;
}
static void F_170 ( struct V_29 * V_12 ,
struct V_1 * V_2 )
{
bool V_179 ;
int V_76 ;
F_28 ( ! F_70 ( V_12 ) ) ;
V_179 = F_71 ( V_12 ) ;
F_75 ( V_12 ) ;
if ( V_179 )
return;
V_76 = F_97 ( V_2 ) ;
F_171 ( V_2 , V_76 ) ;
}
void F_172 ( struct V_29 * V_12 )
{
T_1 V_80 ;
void * V_239 ;
if ( F_9 ( V_85 , & V_12 -> V_13 . V_86 ) )
F_170 ( V_12 , V_12 -> V_13 . V_2 ) ;
if ( ! F_9 ( V_240 , & V_12 -> V_13 . V_86 ) )
return;
V_239 = F_173 ( V_12 -> V_13 . V_2 -> V_241 ) ;
V_80 = * ( T_1 * ) ( V_239 + F_174 ( V_12 -> V_13 . V_2 -> V_242 ) ) ;
F_175 ( V_239 ) ;
F_81 ( V_12 -> V_13 . V_2 , V_80 & 0xff ) ;
}
static void F_176 ( struct V_29 * V_12 ,
struct V_1 * V_2 )
{
if ( ! F_70 ( V_12 ) ||
V_2 -> V_66 ||
V_2 -> V_71 == - 1 ||
F_99 ( V_12 -> V_26 , V_2 -> V_71 ) ) {
return;
}
F_73 ( V_2 -> V_12 ) ;
}
void F_177 ( struct V_29 * V_12 )
{
T_1 V_80 , V_88 ;
int V_243 , V_244 ;
struct V_1 * V_2 = V_12 -> V_13 . V_2 ;
void * V_239 ;
F_176 ( V_12 , V_2 ) ;
if ( ! F_9 ( V_240 , & V_12 -> V_13 . V_86 ) )
return;
V_88 = F_19 ( V_2 , V_94 ) & 0xff ;
V_243 = F_59 ( V_2 ) ;
if ( V_243 < 0 )
V_243 = 0 ;
V_244 = F_77 ( V_2 ) ;
if ( V_244 < 0 )
V_244 = 0 ;
V_80 = ( V_88 & 0xff ) | ( ( V_244 & 0xf0 ) << 8 ) | ( V_243 << 24 ) ;
V_239 = F_173 ( V_12 -> V_13 . V_2 -> V_241 ) ;
* ( T_1 * ) ( V_239 + F_174 ( V_12 -> V_13 . V_2 -> V_242 ) ) = V_80 ;
F_175 ( V_239 ) ;
}
void F_178 ( struct V_29 * V_12 , T_7 V_242 )
{
V_12 -> V_13 . V_2 -> V_242 = V_242 ;
if ( V_242 )
F_74 ( V_240 , & V_12 -> V_13 . V_86 ) ;
else
F_76 ( V_240 , & V_12 -> V_13 . V_86 ) ;
}
int F_179 ( struct V_29 * V_12 , T_1 V_245 , T_6 V_80 )
{
struct V_1 * V_2 = V_12 -> V_13 . V_2 ;
T_1 V_62 = ( V_245 - V_246 ) << 4 ;
if ( ! F_180 ( V_12 -> V_26 ) || ! F_25 ( V_2 ) )
return 1 ;
if ( V_245 == 0x830 )
F_131 ( V_2 , V_139 , ( T_1 ) ( V_80 >> 32 ) ) ;
return F_131 ( V_2 , V_62 , ( T_1 ) V_80 ) ;
}
int F_181 ( struct V_29 * V_12 , T_1 V_245 , T_6 * V_80 )
{
struct V_1 * V_2 = V_12 -> V_13 . V_2 ;
T_1 V_62 = ( V_245 - V_246 ) << 4 , V_247 , V_248 = 0 ;
if ( ! F_180 ( V_12 -> V_26 ) || ! F_25 ( V_2 ) )
return 1 ;
if ( F_117 ( V_2 , V_62 , 4 , & V_247 ) )
return 1 ;
if ( V_245 == 0x830 )
F_117 ( V_2 , V_139 , 4 , & V_248 ) ;
* V_80 = ( ( ( T_6 ) V_248 ) << 32 ) | V_247 ;
return 0 ;
}
int F_182 ( struct V_29 * V_12 , T_1 V_62 , T_6 V_80 )
{
struct V_1 * V_2 = V_12 -> V_13 . V_2 ;
if ( ! F_51 ( V_12 ) )
return 1 ;
if ( V_62 == V_137 )
F_131 ( V_2 , V_139 , ( T_1 ) ( V_80 >> 32 ) ) ;
return F_131 ( V_2 , V_62 , ( T_1 ) V_80 ) ;
}
int F_183 ( struct V_29 * V_12 , T_1 V_62 , T_6 * V_80 )
{
struct V_1 * V_2 = V_12 -> V_13 . V_2 ;
T_1 V_247 , V_248 = 0 ;
if ( ! F_51 ( V_12 ) )
return 1 ;
if ( F_117 ( V_2 , V_62 , 4 , & V_247 ) )
return 1 ;
if ( V_62 == V_137 )
F_117 ( V_2 , V_139 , 4 , & V_248 ) ;
* V_80 = ( ( ( T_6 ) V_248 ) << 32 ) | V_247 ;
return 0 ;
}
int F_184 ( struct V_29 * V_12 , T_6 V_80 )
{
T_6 V_169 = V_80 & ~ V_82 ;
if ( ! F_185 ( V_169 , 4 ) )
return 1 ;
V_12 -> V_13 . V_79 . V_81 = V_80 ;
if ( ! F_70 ( V_12 ) )
return 0 ;
return F_186 ( V_12 -> V_26 , & V_12 -> V_13 . V_79 . V_80 ,
V_169 ) ;
}
void F_187 ( void )
{
F_188 ( & V_211 , V_249 ) ;
F_188 ( & V_10 , V_249 ) ;
}
