static inline void F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
* ( ( T_1 * ) ( V_2 -> V_5 + V_3 ) ) = V_4 ;
}
static inline int F_2 ( int V_6 , void * V_7 )
{
return F_3 ( F_4 ( V_6 ) , ( V_7 ) + F_5 ( V_6 ) ) ;
}
bool F_6 ( struct V_8 * V_9 , int V_10 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
return F_2 ( V_10 , V_2 -> V_5 + V_12 ) ||
F_2 ( V_10 , V_2 -> V_5 + V_13 ) ;
}
static inline void F_7 ( int V_6 , void * V_7 )
{
F_8 ( F_4 ( V_6 ) , ( V_7 ) + F_5 ( V_6 ) ) ;
}
static inline void F_9 ( int V_6 , void * V_7 )
{
F_10 ( F_4 ( V_6 ) , ( V_7 ) + F_5 ( V_6 ) ) ;
}
static inline int F_11 ( int V_6 , void * V_7 )
{
return F_12 ( F_4 ( V_6 ) , ( V_7 ) + F_5 ( V_6 ) ) ;
}
static inline int F_13 ( int V_6 , void * V_7 )
{
return F_14 ( F_4 ( V_6 ) , ( V_7 ) + F_5 ( V_6 ) ) ;
}
static inline void F_15 ( struct V_1 * V_2 , T_1 V_4 )
{
if ( ( F_16 ( V_2 , V_14 ) ^ V_4 ) & V_15 ) {
if ( V_4 & V_15 )
F_17 ( & V_16 ) ;
else
F_18 ( & V_16 . V_17 ) ;
}
F_1 ( V_2 , V_14 , V_4 ) ;
}
static inline int F_19 ( struct V_1 * V_2 )
{
return F_20 ( V_2 ) && F_21 ( V_2 ) ;
}
static inline int F_22 ( struct V_1 * V_2 )
{
return ( F_16 ( V_2 , V_18 ) >> 24 ) & 0xff ;
}
static void F_23 ( struct V_19 * V_19 )
{
struct V_20 * V_21 , * V_22 = NULL ;
struct V_8 * V_9 ;
int V_23 ;
V_21 = F_24 ( sizeof( struct V_20 ) , V_24 ) ;
F_25 ( & V_19 -> V_11 . V_25 ) ;
if ( ! V_21 )
goto V_26;
V_21 -> V_27 = 8 ;
V_21 -> V_28 = 8 ;
V_21 -> V_29 = 0 ;
V_21 -> V_30 = 0xff ;
F_26 (i, vcpu, kvm) {
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_2 V_31 , V_32 ;
T_1 V_33 ;
if ( ! F_27 ( V_9 ) )
continue;
if ( F_28 ( V_2 ) ) {
V_21 -> V_27 = 32 ;
V_21 -> V_28 = 16 ;
V_21 -> V_29 = V_21 -> V_30 = 0xffff ;
} else if ( F_20 ( V_2 ) &&
! V_21 -> V_29 &&
F_16 ( V_2 , V_34 ) == V_35 ) {
V_21 -> V_28 = 4 ;
V_21 -> V_29 = 0xf ;
V_21 -> V_30 = 0xf ;
}
V_21 -> V_36 [ F_22 ( V_2 ) ] = V_2 ;
V_33 = F_16 ( V_2 , V_37 ) ;
V_31 = F_29 ( V_21 , V_33 ) ;
V_32 = F_30 ( V_21 , V_33 ) ;
if ( V_32 )
V_21 -> V_38 [ V_31 ] [ F_31 ( V_32 ) - 1 ] = V_2 ;
}
V_26:
V_22 = F_32 ( V_19 -> V_11 . V_39 ,
F_33 ( & V_19 -> V_11 . V_25 ) ) ;
F_34 ( V_19 -> V_11 . V_39 , V_21 ) ;
F_35 ( & V_19 -> V_11 . V_25 ) ;
if ( V_22 )
F_36 ( V_22 , V_40 ) ;
F_37 ( V_19 ) ;
}
static inline void F_38 ( struct V_1 * V_2 , T_3 V_41 )
{
F_1 ( V_2 , V_18 , V_41 << 24 ) ;
F_23 ( V_2 -> V_9 -> V_19 ) ;
}
static inline void F_39 ( struct V_1 * V_2 , T_1 V_41 )
{
F_1 ( V_2 , V_37 , V_41 ) ;
F_23 ( V_2 -> V_9 -> V_19 ) ;
}
static inline int F_40 ( struct V_1 * V_2 , int V_42 )
{
return ! ( F_16 ( V_2 , V_42 ) & V_43 ) ;
}
static inline int F_41 ( struct V_1 * V_2 , int V_42 )
{
return F_16 ( V_2 , V_42 ) & V_44 ;
}
static inline int F_42 ( struct V_1 * V_2 )
{
return ( ( F_16 ( V_2 , V_45 ) &
V_2 -> V_46 . V_47 ) == V_48 ) ;
}
static inline int F_43 ( struct V_1 * V_2 )
{
return ( ( F_16 ( V_2 , V_45 ) &
V_2 -> V_46 . V_47 ) == V_49 ) ;
}
static inline int F_44 ( struct V_1 * V_2 )
{
return ( ( F_16 ( V_2 , V_45 ) &
V_2 -> V_46 . V_47 ) ==
V_50 ) ;
}
static inline int F_45 ( T_1 V_51 )
{
return ( V_51 & ( V_52 | V_43 ) ) == V_53 ;
}
void F_46 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
struct V_54 * V_55 ;
T_1 V_56 = V_57 ;
if ( ! F_47 ( V_9 ) )
return;
V_55 = F_48 ( V_2 -> V_9 , 0x1 , 0 ) ;
if ( V_55 && ( V_55 -> V_58 & ( 1 << ( V_59 & 31 ) ) ) )
V_56 |= V_60 ;
F_1 ( V_2 , V_61 , V_56 ) ;
}
static int F_49 ( void * V_7 )
{
int V_6 ;
T_1 * V_62 ;
for ( V_6 = V_63 - V_64 ;
V_6 >= 0 ; V_6 -= V_64 ) {
V_62 = V_7 + F_5 ( V_6 ) ;
if ( * V_62 )
return F_50 ( * V_62 ) - 1 + V_6 ;
}
return - 1 ;
}
static T_3 F_51 ( void * V_7 )
{
int V_6 ;
T_1 * V_62 ;
T_3 V_65 = 0 ;
for ( V_6 = 0 ; V_6 < V_63 ; V_6 += V_64 ) {
V_62 = V_7 + F_5 ( V_6 ) ;
V_65 += F_52 ( * V_62 ) ;
}
return V_65 ;
}
void F_53 ( struct V_8 * V_9 , T_1 * V_66 )
{
T_1 V_23 , V_67 ;
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
for ( V_23 = 0 ; V_23 <= 7 ; V_23 ++ ) {
V_67 = F_54 ( & V_66 [ V_23 ] , 0 ) ;
if ( V_67 )
* ( ( T_1 * ) ( V_2 -> V_5 + V_13 + V_23 * 0x10 ) ) |= V_67 ;
}
}
static inline void F_55 ( int V_6 , struct V_1 * V_2 )
{
V_2 -> V_68 = true ;
F_7 ( V_6 , V_2 -> V_5 + V_13 ) ;
}
static inline int F_56 ( struct V_1 * V_2 )
{
return F_49 ( V_2 -> V_5 + V_13 ) ;
}
static inline int F_57 ( struct V_1 * V_2 )
{
int V_69 ;
if ( ! V_2 -> V_68 )
return - 1 ;
V_70 -> V_71 ( V_2 -> V_9 ) ;
V_69 = F_56 ( V_2 ) ;
ASSERT ( V_69 == - 1 || V_69 >= 16 ) ;
return V_69 ;
}
static inline void F_58 ( int V_6 , struct V_1 * V_2 )
{
V_2 -> V_68 = false ;
F_9 ( V_6 , V_2 -> V_5 + V_13 ) ;
if ( F_56 ( V_2 ) != - 1 )
V_2 -> V_68 = true ;
}
static inline void F_59 ( int V_6 , struct V_1 * V_2 )
{
if ( ! F_11 ( V_6 , V_2 -> V_5 + V_12 ) )
++ V_2 -> V_72 ;
F_60 ( V_2 -> V_72 > V_63 ) ;
V_2 -> V_73 = V_6 ;
}
static inline void F_61 ( int V_6 , struct V_1 * V_2 )
{
if ( F_13 ( V_6 , V_2 -> V_5 + V_12 ) )
-- V_2 -> V_72 ;
F_60 ( V_2 -> V_72 < 0 ) ;
V_2 -> V_73 = - 1 ;
}
int F_62 ( struct V_8 * V_9 )
{
int V_74 ;
if ( ! F_47 ( V_9 ) )
return 0 ;
V_74 = F_57 ( V_9 -> V_11 . V_2 ) ;
return V_74 ;
}
int F_63 ( struct V_8 * V_9 , struct V_75 * V_76 ,
unsigned long * V_77 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
return F_64 ( V_2 , V_76 -> V_78 , V_76 -> V_10 ,
V_76 -> V_79 , V_76 -> V_80 , V_77 ) ;
}
static int F_65 ( struct V_8 * V_9 , T_3 V_4 )
{
return F_66 ( V_9 -> V_19 , & V_9 -> V_11 . V_81 . V_82 , & V_4 ,
sizeof( V_4 ) ) ;
}
static int F_67 ( struct V_8 * V_9 , T_3 * V_4 )
{
return F_68 ( V_9 -> V_19 , & V_9 -> V_11 . V_81 . V_82 , V_4 ,
sizeof( * V_4 ) ) ;
}
static inline bool F_69 ( struct V_8 * V_9 )
{
return V_9 -> V_11 . V_81 . V_83 & V_84 ;
}
static bool F_70 ( struct V_8 * V_9 )
{
T_3 V_4 ;
if ( F_67 ( V_9 , & V_4 ) < 0 )
F_71 ( L_1 ,
( unsigned long long ) V_85 -> V_11 . V_81 . V_83 ) ;
return V_4 & 0x1 ;
}
static void F_72 ( struct V_8 * V_9 )
{
if ( F_65 ( V_9 , V_86 ) < 0 ) {
F_71 ( L_2 ,
( unsigned long long ) V_85 -> V_11 . V_81 . V_83 ) ;
return;
}
F_73 ( V_87 , & V_9 -> V_11 . V_88 ) ;
}
static void F_74 ( struct V_8 * V_9 )
{
if ( F_65 ( V_9 , V_89 ) < 0 ) {
F_71 ( L_3 ,
( unsigned long long ) V_85 -> V_11 . V_81 . V_83 ) ;
return;
}
F_75 ( V_87 , & V_9 -> V_11 . V_88 ) ;
}
static inline int F_76 ( struct V_1 * V_2 )
{
int V_69 ;
if ( ! V_2 -> V_72 )
return - 1 ;
if ( F_77 ( V_2 -> V_73 != - 1 ) )
return V_2 -> V_73 ;
V_69 = F_49 ( V_2 -> V_5 + V_12 ) ;
ASSERT ( V_69 == - 1 || V_69 >= 16 ) ;
return V_69 ;
}
void F_78 ( struct V_8 * V_9 , T_1 * V_90 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < 8 ; V_23 ++ )
F_1 ( V_2 , V_91 + 0x10 * V_23 , V_90 [ V_23 ] ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
T_1 V_92 , V_93 , V_94 , V_95 ;
int V_96 ;
V_95 = F_16 ( V_2 , V_97 ) ;
V_92 = F_16 ( V_2 , V_98 ) ;
V_96 = F_76 ( V_2 ) ;
V_93 = ( V_96 != - 1 ) ? V_96 : 0 ;
if ( ( V_92 & 0xf0 ) >= ( V_93 & 0xf0 ) )
V_94 = V_92 & 0xff ;
else
V_94 = V_93 & 0xf0 ;
F_71 ( L_4 ,
V_2 , V_94 , V_96 , V_93 ) ;
if ( V_95 != V_94 ) {
F_1 ( V_2 , V_97 , V_94 ) ;
if ( V_94 < V_95 )
F_80 ( V_99 , V_2 -> V_9 ) ;
}
}
static void F_81 ( struct V_1 * V_2 , T_1 V_92 )
{
F_1 ( V_2 , V_98 , V_92 ) ;
F_79 ( V_2 ) ;
}
int F_82 ( struct V_1 * V_2 , T_2 V_100 )
{
return V_100 == 0xff || F_22 ( V_2 ) == V_100 ;
}
int F_83 ( struct V_1 * V_2 , T_3 V_101 )
{
int V_69 = 0 ;
T_1 V_102 ;
if ( F_28 ( V_2 ) ) {
V_102 = F_16 ( V_2 , V_37 ) ;
return V_102 & V_101 ;
}
V_102 = F_84 ( F_16 ( V_2 , V_37 ) ) ;
switch ( F_16 ( V_2 , V_34 ) ) {
case V_103 :
if ( V_102 & V_101 )
V_69 = 1 ;
break;
case V_35 :
if ( ( ( V_102 >> 4 ) == ( V_101 >> 0x4 ) )
&& ( V_102 & V_101 & 0xf ) )
V_69 = 1 ;
break;
default:
F_71 ( L_5 ,
V_2 -> V_9 -> V_104 , F_16 ( V_2 , V_34 ) ) ;
break;
}
return V_69 ;
}
int F_85 ( struct V_8 * V_9 , struct V_1 * V_105 ,
int V_106 , int V_100 , int V_107 )
{
int V_69 = 0 ;
struct V_1 * V_108 = V_9 -> V_11 . V_2 ;
F_71 ( L_6
L_7 ,
V_108 , V_105 , V_100 , V_107 , V_106 ) ;
ASSERT ( V_108 ) ;
switch ( V_106 ) {
case V_109 :
if ( V_107 == 0 )
V_69 = F_82 ( V_108 , V_100 ) ;
else
V_69 = F_83 ( V_108 , V_100 ) ;
break;
case V_110 :
V_69 = ( V_108 == V_105 ) ;
break;
case V_111 :
V_69 = 1 ;
break;
case V_112 :
V_69 = ( V_108 != V_105 ) ;
break;
default:
F_71 ( L_8 ,
V_106 ) ;
break;
}
return V_69 ;
}
bool F_86 ( struct V_19 * V_19 , struct V_1 * V_113 ,
struct V_75 * V_76 , int * V_114 , unsigned long * V_77 )
{
struct V_20 * V_115 ;
unsigned long V_7 = 1 ;
struct V_1 * * V_116 ;
int V_23 ;
bool V_117 = false ;
* V_114 = - 1 ;
if ( V_76 -> V_118 == V_110 ) {
* V_114 = F_63 ( V_113 -> V_9 , V_76 , V_77 ) ;
return true ;
}
if ( V_76 -> V_118 )
return false ;
F_87 () ;
V_115 = F_88 ( V_19 -> V_11 . V_39 ) ;
if ( ! V_115 )
goto V_26;
if ( V_76 -> V_107 == 0 ) {
if ( V_76 -> V_78 == V_119 ||
V_76 -> V_120 == 0xff )
goto V_26;
V_116 = & V_115 -> V_36 [ V_76 -> V_120 & 0xff ] ;
} else {
T_1 V_101 = V_76 -> V_120 << ( 32 - V_115 -> V_27 ) ;
V_116 = V_115 -> V_38 [ F_29 ( V_115 , V_101 ) ] ;
V_7 = F_30 ( V_115 , V_101 ) ;
if ( V_76 -> V_78 == V_119 ) {
int V_121 = - 1 ;
F_89 (i, &bitmap, 16 ) {
if ( ! V_116 [ V_23 ] )
continue;
if ( V_121 < 0 )
V_121 = V_23 ;
else if ( F_90 ( V_116 [ V_23 ] -> V_9 , V_116 [ V_121 ] -> V_9 ) < 0 )
V_121 = V_23 ;
}
V_7 = ( V_121 >= 0 ) ? 1 << V_121 : 0 ;
}
}
F_89 (i, &bitmap, 16 ) {
if ( ! V_116 [ V_23 ] )
continue;
if ( * V_114 < 0 )
* V_114 = 0 ;
* V_114 += F_63 ( V_116 [ V_23 ] -> V_9 , V_76 , V_77 ) ;
}
V_117 = true ;
V_26:
F_91 () ;
return V_117 ;
}
static int F_64 ( struct V_1 * V_2 , int V_78 ,
int V_10 , int V_79 , int V_80 ,
unsigned long * V_77 )
{
int V_69 = 0 ;
struct V_8 * V_9 = V_2 -> V_9 ;
switch ( V_78 ) {
case V_119 :
V_9 -> V_11 . V_122 ++ ;
case V_123 :
if ( F_92 ( ! F_19 ( V_2 ) ) )
break;
V_69 = 1 ;
if ( V_77 )
F_73 ( V_9 -> V_104 , V_77 ) ;
if ( V_70 -> V_124 )
V_70 -> V_124 ( V_9 , V_10 ) ;
else {
F_55 ( V_10 , V_2 ) ;
F_80 ( V_99 , V_9 ) ;
F_93 ( V_9 ) ;
}
F_94 ( V_9 -> V_104 , V_78 ,
V_80 , V_10 , false ) ;
break;
case V_125 :
V_69 = 1 ;
V_9 -> V_11 . V_126 . V_127 = 1 ;
F_80 ( V_99 , V_9 ) ;
F_93 ( V_9 ) ;
break;
case V_128 :
F_71 ( L_9 ) ;
break;
case V_53 :
V_69 = 1 ;
F_95 ( V_9 ) ;
F_93 ( V_9 ) ;
break;
case V_129 :
if ( ! V_80 || V_79 ) {
V_69 = 1 ;
V_2 -> V_130 = ( 1UL << V_131 ) ;
F_96 () ;
F_80 ( V_99 , V_9 ) ;
F_93 ( V_9 ) ;
} else {
F_71 ( L_10 ,
V_9 -> V_104 ) ;
}
break;
case V_132 :
F_71 ( L_11 ,
V_9 -> V_104 , V_10 ) ;
V_69 = 1 ;
V_2 -> V_133 = V_10 ;
F_96 () ;
F_8 ( V_134 , & V_2 -> V_130 ) ;
F_80 ( V_99 , V_9 ) ;
F_93 ( V_9 ) ;
break;
case V_135 :
break;
default:
F_97 ( V_136 L_12 ,
V_78 ) ;
break;
}
return V_69 ;
}
int F_90 ( struct V_8 * V_137 , struct V_8 * V_138 )
{
return V_137 -> V_11 . V_122 - V_138 -> V_11 . V_122 ;
}
static void F_98 ( struct V_1 * V_2 , int V_10 )
{
if ( ! ( F_16 ( V_2 , V_14 ) & V_139 ) &&
F_99 ( V_2 -> V_9 -> V_19 , V_10 ) ) {
int V_140 ;
if ( F_2 ( V_10 , V_2 -> V_5 + V_91 ) )
V_140 = V_141 ;
else
V_140 = V_142 ;
F_100 ( V_2 -> V_9 , V_10 , V_140 ) ;
}
}
static int F_101 ( struct V_1 * V_2 )
{
int V_10 = F_76 ( V_2 ) ;
F_102 ( V_2 , V_10 ) ;
if ( V_10 == - 1 )
return V_10 ;
F_61 ( V_10 , V_2 ) ;
F_79 ( V_2 ) ;
F_98 ( V_2 , V_10 ) ;
F_80 ( V_99 , V_2 -> V_9 ) ;
return V_10 ;
}
void F_103 ( struct V_8 * V_9 , int V_10 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
F_102 ( V_2 , V_10 ) ;
F_98 ( V_2 , V_10 ) ;
F_80 ( V_99 , V_2 -> V_9 ) ;
}
static void F_104 ( struct V_1 * V_2 )
{
T_1 V_143 = F_16 ( V_2 , V_144 ) ;
T_1 V_145 = F_16 ( V_2 , V_146 ) ;
struct V_75 V_76 ;
V_76 . V_10 = V_143 & V_44 ;
V_76 . V_78 = V_143 & V_52 ;
V_76 . V_107 = V_143 & V_147 ;
V_76 . V_79 = V_143 & V_148 ;
V_76 . V_80 = V_143 & V_149 ;
V_76 . V_118 = V_143 & V_150 ;
if ( F_28 ( V_2 ) )
V_76 . V_120 = V_145 ;
else
V_76 . V_120 = F_105 ( V_145 ) ;
F_106 ( V_143 , V_76 . V_120 ) ;
F_71 ( L_13
L_14
L_15 ,
V_145 , V_143 , V_76 . V_118 , V_76 . V_120 ,
V_76 . V_80 , V_76 . V_79 , V_76 . V_107 , V_76 . V_78 ,
V_76 . V_10 ) ;
F_107 ( V_2 -> V_9 -> V_19 , V_2 , & V_76 , NULL ) ;
}
static T_1 F_108 ( struct V_1 * V_2 )
{
T_4 V_151 ;
T_5 V_152 ;
T_1 V_153 ;
ASSERT ( V_2 != NULL ) ;
if ( F_16 ( V_2 , V_154 ) == 0 )
return 0 ;
V_151 = F_109 ( & V_2 -> V_46 . V_155 ) ;
if ( F_110 ( V_151 ) < 0 )
V_151 = F_111 ( 0 , 0 ) ;
V_152 = F_112 ( F_110 ( V_151 ) , V_2 -> V_46 . V_156 ) ;
V_153 = F_113 ( V_152 ,
( V_157 * V_2 -> V_158 ) ) ;
return V_153 ;
}
static void F_114 ( struct V_1 * V_2 , bool V_159 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_160 * V_161 = V_9 -> V_161 ;
F_80 ( V_162 , V_9 ) ;
V_161 -> V_163 . V_164 = F_115 ( V_9 ) ;
V_161 -> V_163 . V_165 = V_159 ;
}
static inline void F_116 ( struct V_1 * V_2 , bool V_159 )
{
if ( V_2 -> V_9 -> V_11 . V_166 )
F_114 ( V_2 , V_159 ) ;
}
static T_1 F_117 ( struct V_1 * V_2 , unsigned int V_167 )
{
T_1 V_4 = 0 ;
if ( V_167 >= V_168 )
return 0 ;
switch ( V_167 ) {
case V_18 :
if ( F_28 ( V_2 ) )
V_4 = F_22 ( V_2 ) ;
else
V_4 = F_22 ( V_2 ) << 24 ;
break;
case V_169 :
F_71 ( L_16 ) ;
break;
case V_170 :
if ( F_44 ( V_2 ) )
return 0 ;
V_4 = F_108 ( V_2 ) ;
break;
case V_97 :
F_79 ( V_2 ) ;
V_4 = F_16 ( V_2 , V_167 ) ;
break;
case V_98 :
F_116 ( V_2 , false ) ;
default:
V_4 = F_16 ( V_2 , V_167 ) ;
break;
}
return V_4 ;
}
static inline struct V_1 * F_118 ( struct V_171 * V_172 )
{
return F_119 ( V_172 , struct V_1 , V_172 ) ;
}
static int F_120 ( struct V_1 * V_2 , T_1 V_167 , int V_173 ,
void * V_82 )
{
unsigned char V_174 = V_167 & 0xf ;
T_1 V_69 ;
static const T_6 V_175 = 0x43ff01ffffffe70cULL ;
if ( ( V_174 + V_173 ) > 4 ) {
F_71 ( L_17 ,
V_167 , V_173 ) ;
return 1 ;
}
if ( V_167 > 0x3f0 || ! ( V_175 & ( 1ULL << ( V_167 >> 4 ) ) ) ) {
F_71 ( L_18 ,
V_167 ) ;
return 1 ;
}
V_69 = F_117 ( V_2 , V_167 & ~ 0xf ) ;
F_121 ( V_167 , V_69 ) ;
switch ( V_173 ) {
case 1 :
case 2 :
case 4 :
memcpy ( V_82 , ( char * ) & V_69 + V_174 , V_173 ) ;
break;
default:
F_97 ( V_136 L_19
L_20 , V_173 ) ;
break;
}
return 0 ;
}
static int F_122 ( struct V_1 * V_2 , T_7 V_176 )
{
return F_21 ( V_2 ) &&
V_176 >= V_2 -> V_177 &&
V_176 < V_2 -> V_177 + V_168 ;
}
static int F_123 ( struct V_171 * V_178 ,
T_7 V_179 , int V_173 , void * V_82 )
{
struct V_1 * V_2 = F_118 ( V_178 ) ;
T_1 V_167 = V_179 - V_2 -> V_177 ;
if ( ! F_122 ( V_2 , V_179 ) )
return - V_180 ;
F_120 ( V_2 , V_167 , V_173 , V_82 ) ;
return 0 ;
}
static void F_124 ( struct V_1 * V_2 )
{
T_1 V_181 , V_182 , V_183 ;
V_183 = F_16 ( V_2 , V_184 ) ;
V_181 = V_183 & 0xf ;
V_182 = ( ( V_181 & 0x3 ) | ( ( V_181 & 0x8 ) >> 1 ) ) + 1 ;
V_2 -> V_158 = 0x1 << ( V_182 & 0x7 ) ;
F_71 ( L_21 ,
V_2 -> V_158 ) ;
}
static void F_125 ( struct V_1 * V_2 )
{
T_4 V_185 ;
F_126 ( & V_2 -> V_46 . V_186 , 0 ) ;
if ( F_43 ( V_2 ) || F_42 ( V_2 ) ) {
V_185 = V_2 -> V_46 . V_155 . V_187 -> V_188 () ;
V_2 -> V_46 . V_156 = ( T_6 ) F_16 ( V_2 , V_154 )
* V_157 * V_2 -> V_158 ;
if ( ! V_2 -> V_46 . V_156 )
return;
if ( F_43 ( V_2 ) ) {
T_5 V_189 = V_190 * 1000LL ;
if ( V_2 -> V_46 . V_156 < V_189 ) {
F_127 (
L_22
L_23 ,
V_2 -> V_9 -> V_104 ,
V_2 -> V_46 . V_156 , V_189 ) ;
V_2 -> V_46 . V_156 = V_189 ;
}
}
F_128 ( & V_2 -> V_46 . V_155 ,
F_129 ( V_185 , V_2 -> V_46 . V_156 ) ,
V_191 ) ;
F_71 ( L_24 V_192 L_25
V_193 L_26
L_27
L_28 V_193 L_29 , V_194 ,
V_157 , F_110 ( V_185 ) ,
F_16 ( V_2 , V_154 ) ,
V_2 -> V_46 . V_156 ,
F_110 ( F_129 ( V_185 ,
V_2 -> V_46 . V_156 ) ) ) ;
} else if ( F_44 ( V_2 ) ) {
T_6 V_195 , V_196 = V_2 -> V_46 . V_196 ;
T_6 V_152 = 0 ;
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned long V_197 = V_9 -> V_11 . V_198 ;
unsigned long V_199 ;
if ( F_92 ( ! V_196 || ! V_197 ) )
return;
F_130 ( V_199 ) ;
V_185 = V_2 -> V_46 . V_155 . V_187 -> V_188 () ;
V_195 = V_70 -> V_200 ( V_9 , F_131 () ) ;
if ( F_77 ( V_196 > V_195 ) ) {
V_152 = ( V_196 - V_195 ) * 1000000ULL ;
F_132 ( V_152 , V_197 ) ;
}
F_128 ( & V_2 -> V_46 . V_155 ,
F_129 ( V_185 , V_152 ) , V_191 ) ;
F_133 ( V_199 ) ;
}
}
static void F_134 ( struct V_1 * V_2 , T_1 V_201 )
{
int V_202 = F_45 ( F_16 ( V_2 , V_203 ) ) ;
if ( F_45 ( V_201 ) ) {
if ( ! V_202 ) {
F_71 ( L_30
L_31 , V_2 -> V_9 -> V_104 ) ;
V_2 -> V_9 -> V_19 -> V_11 . V_204 ++ ;
}
} else if ( V_202 )
V_2 -> V_9 -> V_19 -> V_11 . V_204 -- ;
}
static int F_135 ( struct V_1 * V_2 , T_1 V_62 , T_1 V_4 )
{
int V_117 = 0 ;
F_136 ( V_62 , V_4 ) ;
switch ( V_62 ) {
case V_18 :
if ( ! F_28 ( V_2 ) )
F_38 ( V_2 , V_4 >> 24 ) ;
else
V_117 = 1 ;
break;
case V_98 :
F_116 ( V_2 , true ) ;
F_81 ( V_2 , V_4 & 0xff ) ;
break;
case V_205 :
F_101 ( V_2 ) ;
break;
case V_37 :
if ( ! F_28 ( V_2 ) )
F_39 ( V_2 , V_4 & V_206 ) ;
else
V_117 = 1 ;
break;
case V_34 :
if ( ! F_28 ( V_2 ) ) {
F_1 ( V_2 , V_34 , V_4 | 0x0FFFFFFF ) ;
F_23 ( V_2 -> V_9 -> V_19 ) ;
} else
V_117 = 1 ;
break;
case V_14 : {
T_1 V_207 = 0x3ff ;
if ( F_16 ( V_2 , V_61 ) & V_60 )
V_207 |= V_139 ;
F_15 ( V_2 , V_4 & V_207 ) ;
if ( ! ( V_4 & V_15 ) ) {
int V_23 ;
T_1 V_51 ;
for ( V_23 = 0 ; V_23 < V_208 ; V_23 ++ ) {
V_51 = F_16 ( V_2 ,
V_45 + 0x10 * V_23 ) ;
F_1 ( V_2 , V_45 + 0x10 * V_23 ,
V_51 | V_43 ) ;
}
F_126 ( & V_2 -> V_46 . V_186 , 0 ) ;
}
break;
}
case V_144 :
F_1 ( V_2 , V_144 , V_4 & ~ ( 1 << 12 ) ) ;
F_104 ( V_2 ) ;
break;
case V_146 :
if ( ! F_28 ( V_2 ) )
V_4 &= 0xff000000 ;
F_1 ( V_2 , V_146 , V_4 ) ;
break;
case V_203 :
F_134 ( V_2 , V_4 ) ;
case V_209 :
case V_210 :
case V_211 :
case V_212 :
if ( ! F_20 ( V_2 ) )
V_4 |= V_43 ;
V_4 &= V_213 [ ( V_62 - V_45 ) >> 4 ] ;
F_1 ( V_2 , V_62 , V_4 ) ;
break;
case V_45 :
if ( ( F_16 ( V_2 , V_45 ) &
V_2 -> V_46 . V_47 ) !=
( V_4 & V_2 -> V_46 . V_47 ) )
F_137 ( & V_2 -> V_46 . V_155 ) ;
if ( ! F_20 ( V_2 ) )
V_4 |= V_43 ;
V_4 &= ( V_213 [ 0 ] | V_2 -> V_46 . V_47 ) ;
F_1 ( V_2 , V_45 , V_4 ) ;
break;
case V_154 :
if ( F_44 ( V_2 ) )
break;
F_137 ( & V_2 -> V_46 . V_155 ) ;
F_1 ( V_2 , V_154 , V_4 ) ;
F_125 ( V_2 ) ;
break;
case V_184 :
if ( V_4 & 4 )
F_71 ( L_32 , V_4 ) ;
F_1 ( V_2 , V_184 , V_4 ) ;
F_124 ( V_2 ) ;
break;
case V_214 :
if ( F_28 ( V_2 ) && V_4 != 0 ) {
F_71 ( L_33 , V_4 ) ;
V_117 = 1 ;
}
break;
case V_215 :
if ( F_28 ( V_2 ) ) {
F_135 ( V_2 , V_144 , 0x40000 | ( V_4 & 0xff ) ) ;
} else
V_117 = 1 ;
break;
default:
V_117 = 1 ;
break;
}
if ( V_117 )
F_71 ( L_34 , V_62 ) ;
return V_117 ;
}
static int F_138 ( struct V_171 * V_178 ,
T_7 V_179 , int V_173 , const void * V_82 )
{
struct V_1 * V_2 = F_118 ( V_178 ) ;
unsigned int V_167 = V_179 - V_2 -> V_177 ;
T_1 V_4 ;
if ( ! F_122 ( V_2 , V_179 ) )
return - V_180 ;
if ( V_173 != 4 || ( V_167 & 0xf ) ) {
F_71 ( L_35 , V_173 , ( long ) V_179 ) ;
return 0 ;
}
V_4 = * ( T_1 * ) V_82 ;
if ( V_167 != V_205 )
F_71 ( L_36
L_37 , V_194 , V_167 , V_173 , V_4 ) ;
F_135 ( V_2 , V_167 & 0xff0 , V_4 ) ;
return 0 ;
}
void F_139 ( struct V_8 * V_9 )
{
if ( F_47 ( V_9 ) )
F_135 ( V_9 -> V_11 . V_2 , V_205 , 0 ) ;
}
void F_140 ( struct V_8 * V_9 , T_1 V_167 )
{
T_1 V_4 = 0 ;
V_167 &= 0xff0 ;
F_120 ( V_9 -> V_11 . V_2 , V_167 , 4 , & V_4 ) ;
F_135 ( V_9 -> V_11 . V_2 , V_167 , V_4 ) ;
}
void F_141 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! V_9 -> V_11 . V_2 )
return;
F_137 ( & V_2 -> V_46 . V_155 ) ;
if ( ! ( V_9 -> V_11 . V_216 & V_217 ) )
F_17 ( & V_218 ) ;
if ( ! ( F_16 ( V_2 , V_14 ) & V_15 ) )
F_17 ( & V_16 ) ;
if ( V_2 -> V_5 )
F_142 ( ( unsigned long ) V_2 -> V_5 ) ;
F_143 ( V_2 ) ;
}
T_6 F_144 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_47 ( V_9 ) || F_42 ( V_2 ) ||
F_43 ( V_2 ) )
return 0 ;
return V_2 -> V_46 . V_196 ;
}
void F_145 ( struct V_8 * V_9 , T_6 V_82 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_47 ( V_9 ) || F_42 ( V_2 ) ||
F_43 ( V_2 ) )
return;
F_137 ( & V_2 -> V_46 . V_155 ) ;
V_2 -> V_46 . V_196 = V_82 ;
F_125 ( V_2 ) ;
}
void F_146 ( struct V_8 * V_9 , unsigned long V_219 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_47 ( V_9 ) )
return;
F_81 ( V_2 , ( ( V_219 & 0x0f ) << 4 )
| ( F_16 ( V_2 , V_98 ) & 4 ) ) ;
}
T_6 F_147 ( struct V_8 * V_9 )
{
T_6 V_92 ;
if ( ! F_47 ( V_9 ) )
return 0 ;
V_92 = ( T_6 ) F_16 ( V_9 -> V_11 . V_2 , V_98 ) ;
return ( V_92 & 0xf0 ) >> 4 ;
}
void F_148 ( struct V_8 * V_9 , T_6 V_220 )
{
T_6 V_221 = V_9 -> V_11 . V_216 ;
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! V_2 ) {
V_220 |= V_222 ;
V_9 -> V_11 . V_216 = V_220 ;
return;
}
if ( ( V_9 -> V_11 . V_216 ^ V_220 ) & V_217 ) {
if ( V_220 & V_217 )
F_17 ( & V_218 ) ;
else
F_18 ( & V_218 . V_17 ) ;
F_23 ( V_9 -> V_19 ) ;
}
if ( ! F_149 ( V_2 -> V_9 ) )
V_220 &= ~ V_222 ;
V_9 -> V_11 . V_216 = V_220 ;
if ( ( V_221 ^ V_220 ) & V_223 ) {
if ( V_220 & V_223 ) {
T_1 V_41 = F_22 ( V_2 ) ;
T_1 V_33 = ( ( V_41 >> 4 ) << 16 ) | ( 1 << ( V_41 & 0xf ) ) ;
F_39 ( V_2 , V_33 ) ;
V_70 -> V_224 ( V_9 , true ) ;
} else
V_70 -> V_224 ( V_9 , false ) ;
}
V_2 -> V_177 = V_2 -> V_9 -> V_11 . V_216 &
V_225 ;
F_71 ( L_38 V_193 L_39
L_40 , V_2 -> V_9 -> V_11 . V_216 , V_2 -> V_177 ) ;
}
void F_150 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
int V_23 ;
F_71 ( L_41 , V_194 ) ;
ASSERT ( V_9 ) ;
V_2 = V_9 -> V_11 . V_2 ;
ASSERT ( V_2 != NULL ) ;
F_137 ( & V_2 -> V_46 . V_155 ) ;
F_38 ( V_2 , V_9 -> V_104 ) ;
F_46 ( V_2 -> V_9 ) ;
for ( V_23 = 0 ; V_23 < V_208 ; V_23 ++ )
F_1 ( V_2 , V_45 + 0x10 * V_23 , V_43 ) ;
F_1 ( V_2 , V_203 ,
F_151 ( 0 , V_226 ) ) ;
F_1 ( V_2 , V_34 , 0xffffffffU ) ;
F_15 ( V_2 , 0xff ) ;
F_1 ( V_2 , V_98 , 0 ) ;
F_39 ( V_2 , 0 ) ;
F_1 ( V_2 , V_214 , 0 ) ;
F_1 ( V_2 , V_144 , 0 ) ;
F_1 ( V_2 , V_146 , 0 ) ;
F_1 ( V_2 , V_184 , 0 ) ;
F_1 ( V_2 , V_154 , 0 ) ;
for ( V_23 = 0 ; V_23 < 8 ; V_23 ++ ) {
F_1 ( V_2 , V_13 + 0x10 * V_23 , 0 ) ;
F_1 ( V_2 , V_12 + 0x10 * V_23 , 0 ) ;
F_1 ( V_2 , V_91 + 0x10 * V_23 , 0 ) ;
}
V_2 -> V_68 = F_152 ( V_9 -> V_19 ) ;
V_2 -> V_72 = F_152 ( V_9 -> V_19 ) ;
V_2 -> V_73 = - 1 ;
F_124 ( V_2 ) ;
F_126 ( & V_2 -> V_46 . V_186 , 0 ) ;
if ( F_149 ( V_9 ) )
F_148 ( V_9 ,
V_9 -> V_11 . V_216 | V_222 ) ;
V_9 -> V_11 . V_81 . V_83 = 0 ;
F_79 ( V_2 ) ;
V_9 -> V_11 . V_122 = 0 ;
V_9 -> V_11 . V_88 = 0 ;
F_71 ( V_227 L_42
L_43 V_193 L_44 , V_194 ,
V_9 , F_22 ( V_2 ) ,
V_9 -> V_11 . V_216 , V_2 -> V_177 ) ;
}
static bool F_153 ( struct V_1 * V_2 )
{
return F_43 ( V_2 ) ;
}
int F_154 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( F_47 ( V_9 ) && F_19 ( V_2 ) &&
F_40 ( V_2 , V_45 ) )
return F_155 ( & V_2 -> V_46 . V_186 ) ;
return 0 ;
}
int F_156 ( struct V_1 * V_2 , int V_42 )
{
T_1 V_62 = F_16 ( V_2 , V_42 ) ;
int V_10 , V_228 , V_80 ;
if ( F_21 ( V_2 ) && ! ( V_62 & V_43 ) ) {
V_10 = V_62 & V_44 ;
V_228 = V_62 & V_52 ;
V_80 = V_62 & V_229 ;
return F_64 ( V_2 , V_228 , V_10 , 1 , V_80 ,
NULL ) ;
}
return 0 ;
}
void F_157 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( V_2 )
F_156 ( V_2 , V_203 ) ;
}
static enum V_230 F_158 ( struct V_231 * V_82 )
{
struct V_232 * V_233 = F_119 ( V_82 , struct V_232 , V_155 ) ;
struct V_1 * V_2 = F_119 ( V_233 , struct V_1 , V_46 ) ;
struct V_8 * V_9 = V_2 -> V_9 ;
T_8 * V_234 = & V_9 -> V_235 ;
if ( ! F_155 ( & V_233 -> V_186 ) ) {
F_159 ( & V_233 -> V_186 ) ;
F_80 ( V_236 , V_9 ) ;
}
if ( F_160 ( V_234 ) )
F_161 ( V_234 ) ;
if ( F_153 ( V_2 ) ) {
F_162 ( & V_233 -> V_155 , V_233 -> V_156 ) ;
return V_237 ;
} else
return V_238 ;
}
int F_163 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
ASSERT ( V_9 != NULL ) ;
F_71 ( L_45 , V_9 -> V_104 ) ;
V_2 = F_24 ( sizeof( * V_2 ) , V_24 ) ;
if ( ! V_2 )
goto V_239;
V_9 -> V_11 . V_2 = V_2 ;
V_2 -> V_5 = ( void * ) F_164 ( V_24 ) ;
if ( ! V_2 -> V_5 ) {
F_97 ( V_136 L_46 ,
V_9 -> V_104 ) ;
goto V_240;
}
V_2 -> V_9 = V_9 ;
F_165 ( & V_2 -> V_46 . V_155 , V_241 ,
V_191 ) ;
V_2 -> V_46 . V_155 . V_242 = F_158 ;
V_9 -> V_11 . V_216 = V_217 ;
F_148 ( V_9 ,
V_243 | V_217 ) ;
F_18 ( & V_16 . V_17 ) ;
F_150 ( V_9 ) ;
F_166 ( & V_2 -> V_172 , & V_244 ) ;
return 0 ;
V_240:
F_143 ( V_2 ) ;
V_239:
return - V_245 ;
}
int F_167 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
int V_74 ;
if ( ! F_47 ( V_9 ) || ! F_19 ( V_2 ) )
return - 1 ;
F_79 ( V_2 ) ;
V_74 = F_57 ( V_2 ) ;
if ( ( V_74 == - 1 ) ||
( ( V_74 & 0xF0 ) <= F_16 ( V_2 , V_97 ) ) )
return - 1 ;
return V_74 ;
}
int F_168 ( struct V_8 * V_9 )
{
T_1 V_246 = F_16 ( V_9 -> V_11 . V_2 , V_203 ) ;
int V_114 = 0 ;
if ( ! F_21 ( V_9 -> V_11 . V_2 ) )
V_114 = 1 ;
if ( ( V_246 & V_43 ) == 0 &&
F_169 ( V_246 ) == V_226 )
V_114 = 1 ;
return V_114 ;
}
void F_170 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_47 ( V_9 ) )
return;
if ( F_155 ( & V_2 -> V_46 . V_186 ) > 0 ) {
F_156 ( V_2 , V_45 ) ;
F_126 ( & V_2 -> V_46 . V_186 , 0 ) ;
}
}
int F_171 ( struct V_8 * V_9 )
{
int V_10 = F_167 ( V_9 ) ;
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( V_10 == - 1 )
return - 1 ;
F_59 ( V_10 , V_2 ) ;
F_79 ( V_2 ) ;
F_58 ( V_10 , V_2 ) ;
return V_10 ;
}
void F_172 ( struct V_8 * V_9 ,
struct V_247 * V_248 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
F_148 ( V_9 , V_9 -> V_11 . V_216 ) ;
F_15 ( V_2 , * ( ( T_1 * ) ( V_248 -> V_5 + V_14 ) ) ) ;
memcpy ( V_9 -> V_11 . V_2 -> V_5 , V_248 -> V_5 , sizeof *V_248 ) ;
F_38 ( V_2 , F_22 ( V_2 ) ) ;
F_46 ( V_9 ) ;
F_79 ( V_2 ) ;
F_137 ( & V_2 -> V_46 . V_155 ) ;
F_124 ( V_2 ) ;
F_125 ( V_2 ) ;
V_2 -> V_68 = true ;
V_2 -> V_72 = F_152 ( V_9 -> V_19 ) ?
1 : F_51 ( V_2 -> V_5 + V_12 ) ;
V_2 -> V_73 = - 1 ;
V_70 -> V_249 ( V_9 -> V_19 , F_76 ( V_2 ) ) ;
F_80 ( V_99 , V_9 ) ;
F_173 ( V_9 ) ;
}
void F_174 ( struct V_8 * V_9 )
{
struct V_231 * V_155 ;
if ( ! F_47 ( V_9 ) )
return;
V_155 = & V_9 -> V_11 . V_2 -> V_46 . V_155 ;
if ( F_137 ( V_155 ) )
F_175 ( V_155 , V_191 ) ;
}
static void F_176 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
bool V_186 ;
int V_10 ;
F_60 ( ! F_69 ( V_9 ) ) ;
V_186 = F_70 ( V_9 ) ;
F_74 ( V_9 ) ;
if ( V_186 )
return;
V_10 = F_101 ( V_2 ) ;
F_177 ( V_2 , V_10 ) ;
}
void F_178 ( struct V_8 * V_9 )
{
T_1 V_82 ;
void * V_250 ;
if ( F_3 ( V_87 , & V_9 -> V_11 . V_88 ) )
F_176 ( V_9 , V_9 -> V_11 . V_2 ) ;
if ( ! F_3 ( V_251 , & V_9 -> V_11 . V_88 ) )
return;
V_250 = F_179 ( V_9 -> V_11 . V_2 -> V_252 ) ;
V_82 = * ( T_1 * ) ( V_250 + F_180 ( V_9 -> V_11 . V_2 -> V_253 ) ) ;
F_181 ( V_250 ) ;
F_81 ( V_9 -> V_11 . V_2 , V_82 & 0xff ) ;
}
static void F_182 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
if ( ! F_69 ( V_9 ) ||
V_2 -> V_68 ||
V_2 -> V_73 == - 1 ||
F_99 ( V_9 -> V_19 , V_2 -> V_73 ) ) {
return;
}
F_72 ( V_2 -> V_9 ) ;
}
void F_183 ( struct V_8 * V_9 )
{
T_1 V_82 , V_92 ;
int V_254 , V_255 ;
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
void * V_250 ;
F_182 ( V_9 , V_2 ) ;
if ( ! F_3 ( V_251 , & V_9 -> V_11 . V_88 ) )
return;
V_92 = F_16 ( V_2 , V_98 ) & 0xff ;
V_254 = F_57 ( V_2 ) ;
if ( V_254 < 0 )
V_254 = 0 ;
V_255 = F_76 ( V_2 ) ;
if ( V_255 < 0 )
V_255 = 0 ;
V_82 = ( V_92 & 0xff ) | ( ( V_255 & 0xf0 ) << 8 ) | ( V_254 << 24 ) ;
V_250 = F_179 ( V_9 -> V_11 . V_2 -> V_252 ) ;
* ( T_1 * ) ( V_250 + F_180 ( V_9 -> V_11 . V_2 -> V_253 ) ) = V_82 ;
F_181 ( V_250 ) ;
}
void F_184 ( struct V_8 * V_9 , T_7 V_253 )
{
V_9 -> V_11 . V_2 -> V_253 = V_253 ;
if ( V_253 )
F_73 ( V_251 , & V_9 -> V_11 . V_88 ) ;
else
F_75 ( V_251 , & V_9 -> V_11 . V_88 ) ;
}
int F_185 ( struct V_8 * V_9 , T_1 V_256 , T_6 V_82 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_1 V_62 = ( V_256 - V_257 ) << 4 ;
if ( ! F_186 ( V_9 -> V_19 ) || ! F_28 ( V_2 ) )
return 1 ;
if ( V_256 == 0x830 )
F_135 ( V_2 , V_146 , ( T_1 ) ( V_82 >> 32 ) ) ;
return F_135 ( V_2 , V_62 , ( T_1 ) V_82 ) ;
}
int F_187 ( struct V_8 * V_9 , T_1 V_256 , T_6 * V_82 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_1 V_62 = ( V_256 - V_257 ) << 4 , V_258 , V_259 = 0 ;
if ( ! F_186 ( V_9 -> V_19 ) || ! F_28 ( V_2 ) )
return 1 ;
if ( F_120 ( V_2 , V_62 , 4 , & V_258 ) )
return 1 ;
if ( V_256 == 0x830 )
F_120 ( V_2 , V_146 , 4 , & V_259 ) ;
* V_82 = ( ( ( T_6 ) V_259 ) << 32 ) | V_258 ;
return 0 ;
}
int F_188 ( struct V_8 * V_9 , T_1 V_62 , T_6 V_82 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_47 ( V_9 ) )
return 1 ;
if ( V_62 == V_144 )
F_135 ( V_2 , V_146 , ( T_1 ) ( V_82 >> 32 ) ) ;
return F_135 ( V_2 , V_62 , ( T_1 ) V_82 ) ;
}
int F_189 ( struct V_8 * V_9 , T_1 V_62 , T_6 * V_82 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_1 V_258 , V_259 = 0 ;
if ( ! F_47 ( V_9 ) )
return 1 ;
if ( F_120 ( V_2 , V_62 , 4 , & V_258 ) )
return 1 ;
if ( V_62 == V_144 )
F_120 ( V_2 , V_146 , 4 , & V_259 ) ;
* V_82 = ( ( ( T_6 ) V_259 ) << 32 ) | V_258 ;
return 0 ;
}
int F_190 ( struct V_8 * V_9 , T_6 V_82 )
{
T_6 V_176 = V_82 & ~ V_84 ;
if ( ! F_191 ( V_176 , 4 ) )
return 1 ;
V_9 -> V_11 . V_81 . V_83 = V_82 ;
if ( ! F_69 ( V_9 ) )
return 0 ;
return F_192 ( V_9 -> V_19 , & V_9 -> V_11 . V_81 . V_82 ,
V_176 , sizeof( T_3 ) ) ;
}
void F_193 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
unsigned int V_133 ;
unsigned long V_260 ;
if ( ! F_47 ( V_9 ) || ! V_2 -> V_130 )
return;
V_260 = F_54 ( & V_2 -> V_130 , 0 ) ;
if ( F_3 ( V_131 , & V_260 ) ) {
F_150 ( V_9 ) ;
F_194 ( V_9 ) ;
if ( F_149 ( V_2 -> V_9 ) )
V_9 -> V_11 . V_261 = V_262 ;
else
V_9 -> V_11 . V_261 = V_263 ;
}
if ( F_3 ( V_134 , & V_260 ) &&
V_9 -> V_11 . V_261 == V_263 ) {
F_195 () ;
V_133 = V_2 -> V_133 ;
F_196 ( L_47 ,
V_9 -> V_104 , V_133 ) ;
F_197 ( V_9 , V_133 ) ;
V_9 -> V_11 . V_261 = V_262 ;
}
}
void F_198 ( void )
{
F_199 ( & V_218 , V_264 ) ;
F_199 ( & V_16 , V_264 ) ;
}
