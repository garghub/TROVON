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
V_21 -> V_29 = ( 1 << V_34 ) - 1 ;
V_21 -> V_30 = 0xffff ;
} else if ( F_20 ( V_2 ) &&
! V_21 -> V_29 &&
F_16 ( V_2 , V_35 ) == V_36 ) {
V_21 -> V_28 = 4 ;
V_21 -> V_29 = 0xf ;
V_21 -> V_30 = 0xf ;
}
V_21 -> V_37 [ F_22 ( V_2 ) ] = V_2 ;
V_33 = F_16 ( V_2 , V_38 ) ;
V_31 = F_29 ( V_21 , V_33 ) ;
V_32 = F_30 ( V_21 , V_33 ) ;
if ( V_32 )
V_21 -> V_39 [ V_31 ] [ F_31 ( V_32 ) - 1 ] = V_2 ;
}
V_26:
V_22 = F_32 ( V_19 -> V_11 . V_40 ,
F_33 ( & V_19 -> V_11 . V_25 ) ) ;
F_34 ( V_19 -> V_11 . V_40 , V_21 ) ;
F_35 ( & V_19 -> V_11 . V_25 ) ;
if ( V_22 )
F_36 ( V_22 , V_41 ) ;
F_37 ( V_19 ) ;
}
static inline void F_38 ( struct V_1 * V_2 , T_3 V_42 )
{
F_1 ( V_2 , V_18 , V_42 << 24 ) ;
F_23 ( V_2 -> V_9 -> V_19 ) ;
}
static inline void F_39 ( struct V_1 * V_2 , T_1 V_42 )
{
F_1 ( V_2 , V_38 , V_42 ) ;
F_23 ( V_2 -> V_9 -> V_19 ) ;
}
static inline int F_40 ( struct V_1 * V_2 , int V_43 )
{
return ! ( F_16 ( V_2 , V_43 ) & V_44 ) ;
}
static inline int F_41 ( struct V_1 * V_2 , int V_43 )
{
return F_16 ( V_2 , V_43 ) & V_45 ;
}
static inline int F_42 ( struct V_1 * V_2 )
{
return ( ( F_16 ( V_2 , V_46 ) &
V_2 -> V_47 . V_48 ) == V_49 ) ;
}
static inline int F_43 ( struct V_1 * V_2 )
{
return ( ( F_16 ( V_2 , V_46 ) &
V_2 -> V_47 . V_48 ) == V_50 ) ;
}
static inline int F_44 ( struct V_1 * V_2 )
{
return ( ( F_16 ( V_2 , V_46 ) &
V_2 -> V_47 . V_48 ) ==
V_51 ) ;
}
static inline int F_45 ( T_1 V_52 )
{
return ( V_52 & ( V_53 | V_44 ) ) == V_54 ;
}
void F_46 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
struct V_55 * V_56 ;
T_1 V_57 = V_58 ;
if ( ! F_47 ( V_9 ) )
return;
V_56 = F_48 ( V_2 -> V_9 , 0x1 , 0 ) ;
if ( V_56 && ( V_56 -> V_59 & ( 1 << ( V_60 & 31 ) ) ) )
V_57 |= V_61 ;
F_1 ( V_2 , V_62 , V_57 ) ;
}
static int F_49 ( void * V_7 )
{
int V_6 ;
T_1 * V_63 ;
for ( V_6 = V_64 - V_65 ;
V_6 >= 0 ; V_6 -= V_65 ) {
V_63 = V_7 + F_5 ( V_6 ) ;
if ( * V_63 )
return F_50 ( * V_63 ) - 1 + V_6 ;
}
return - 1 ;
}
static T_3 F_51 ( void * V_7 )
{
int V_6 ;
T_1 * V_63 ;
T_3 V_66 = 0 ;
for ( V_6 = 0 ; V_6 < V_64 ; V_6 += V_65 ) {
V_63 = V_7 + F_5 ( V_6 ) ;
V_66 += F_52 ( * V_63 ) ;
}
return V_66 ;
}
void F_53 ( struct V_8 * V_9 , T_1 * V_67 )
{
T_1 V_23 , V_68 ;
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
for ( V_23 = 0 ; V_23 <= 7 ; V_23 ++ ) {
V_68 = F_54 ( & V_67 [ V_23 ] , 0 ) ;
if ( V_68 )
* ( ( T_1 * ) ( V_2 -> V_5 + V_13 + V_23 * 0x10 ) ) |= V_68 ;
}
}
static inline void F_55 ( int V_6 , struct V_1 * V_2 )
{
V_2 -> V_69 = true ;
F_7 ( V_6 , V_2 -> V_5 + V_13 ) ;
}
static inline int F_56 ( struct V_1 * V_2 )
{
return F_49 ( V_2 -> V_5 + V_13 ) ;
}
static inline int F_57 ( struct V_1 * V_2 )
{
int V_70 ;
if ( ! V_2 -> V_69 )
return - 1 ;
V_71 -> V_72 ( V_2 -> V_9 ) ;
V_70 = F_56 ( V_2 ) ;
ASSERT ( V_70 == - 1 || V_70 >= 16 ) ;
return V_70 ;
}
static inline void F_58 ( int V_6 , struct V_1 * V_2 )
{
V_2 -> V_69 = false ;
F_9 ( V_6 , V_2 -> V_5 + V_13 ) ;
if ( F_56 ( V_2 ) != - 1 )
V_2 -> V_69 = true ;
}
static inline void F_59 ( int V_6 , struct V_1 * V_2 )
{
if ( ! F_11 ( V_6 , V_2 -> V_5 + V_12 ) )
++ V_2 -> V_73 ;
F_60 ( V_2 -> V_73 > V_64 ) ;
V_2 -> V_74 = V_6 ;
}
static inline int F_61 ( struct V_1 * V_2 )
{
int V_70 ;
if ( ! V_2 -> V_73 )
return - 1 ;
if ( F_62 ( V_2 -> V_74 != - 1 ) )
return V_2 -> V_74 ;
V_70 = F_49 ( V_2 -> V_5 + V_12 ) ;
ASSERT ( V_70 == - 1 || V_70 >= 16 ) ;
return V_70 ;
}
static inline void F_63 ( int V_6 , struct V_1 * V_2 )
{
struct V_8 * V_9 ;
if ( ! F_13 ( V_6 , V_2 -> V_5 + V_12 ) )
return;
V_9 = V_2 -> V_9 ;
if ( F_64 ( F_65 ( V_9 -> V_19 ) ) )
V_71 -> V_75 ( V_9 -> V_19 ,
F_61 ( V_2 ) ) ;
else {
-- V_2 -> V_73 ;
F_60 ( V_2 -> V_73 < 0 ) ;
V_2 -> V_74 = - 1 ;
}
}
int F_66 ( struct V_8 * V_9 )
{
int V_76 ;
if ( ! F_47 ( V_9 ) )
return 0 ;
V_76 = F_57 ( V_9 -> V_11 . V_2 ) ;
return V_76 ;
}
int F_67 ( struct V_8 * V_9 , struct V_77 * V_78 ,
unsigned long * V_79 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
return F_68 ( V_2 , V_78 -> V_80 , V_78 -> V_10 ,
V_78 -> V_81 , V_78 -> V_82 , V_79 ) ;
}
static int F_69 ( struct V_8 * V_9 , T_3 V_4 )
{
return F_70 ( V_9 -> V_19 , & V_9 -> V_11 . V_83 . V_84 , & V_4 ,
sizeof( V_4 ) ) ;
}
static int F_71 ( struct V_8 * V_9 , T_3 * V_4 )
{
return F_72 ( V_9 -> V_19 , & V_9 -> V_11 . V_83 . V_84 , V_4 ,
sizeof( * V_4 ) ) ;
}
static inline bool F_73 ( struct V_8 * V_9 )
{
return V_9 -> V_11 . V_83 . V_85 & V_86 ;
}
static bool F_74 ( struct V_8 * V_9 )
{
T_3 V_4 ;
if ( F_71 ( V_9 , & V_4 ) < 0 )
F_75 ( L_1 ,
( unsigned long long ) V_9 -> V_11 . V_83 . V_85 ) ;
return V_4 & 0x1 ;
}
static void F_76 ( struct V_8 * V_9 )
{
if ( F_69 ( V_9 , V_87 ) < 0 ) {
F_75 ( L_2 ,
( unsigned long long ) V_9 -> V_11 . V_83 . V_85 ) ;
return;
}
F_77 ( V_88 , & V_9 -> V_11 . V_89 ) ;
}
static void F_78 ( struct V_8 * V_9 )
{
if ( F_69 ( V_9 , V_90 ) < 0 ) {
F_75 ( L_3 ,
( unsigned long long ) V_9 -> V_11 . V_83 . V_85 ) ;
return;
}
F_79 ( V_88 , & V_9 -> V_11 . V_89 ) ;
}
void F_80 ( struct V_8 * V_9 , T_1 * V_91 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < 8 ; V_23 ++ )
F_1 ( V_2 , V_92 + 0x10 * V_23 , V_91 [ V_23 ] ) ;
}
static void F_81 ( struct V_1 * V_2 )
{
T_1 V_93 , V_94 , V_95 , V_96 ;
int V_97 ;
V_96 = F_16 ( V_2 , V_98 ) ;
V_93 = F_16 ( V_2 , V_99 ) ;
V_97 = F_61 ( V_2 ) ;
V_94 = ( V_97 != - 1 ) ? V_97 : 0 ;
if ( ( V_93 & 0xf0 ) >= ( V_94 & 0xf0 ) )
V_95 = V_93 & 0xff ;
else
V_95 = V_94 & 0xf0 ;
F_75 ( L_4 ,
V_2 , V_95 , V_97 , V_94 ) ;
if ( V_96 != V_95 ) {
F_1 ( V_2 , V_98 , V_95 ) ;
if ( V_95 < V_96 )
F_82 ( V_100 , V_2 -> V_9 ) ;
}
}
static void F_83 ( struct V_1 * V_2 , T_1 V_93 )
{
F_1 ( V_2 , V_99 , V_93 ) ;
F_81 ( V_2 ) ;
}
int F_84 ( struct V_1 * V_2 , T_2 V_101 )
{
return V_101 == 0xff || F_22 ( V_2 ) == V_101 ;
}
int F_85 ( struct V_1 * V_2 , T_3 V_102 )
{
int V_70 = 0 ;
T_1 V_103 ;
if ( F_28 ( V_2 ) ) {
V_103 = F_16 ( V_2 , V_38 ) ;
return V_103 & V_102 ;
}
V_103 = F_86 ( F_16 ( V_2 , V_38 ) ) ;
switch ( F_16 ( V_2 , V_35 ) ) {
case V_104 :
if ( V_103 & V_102 )
V_70 = 1 ;
break;
case V_36 :
if ( ( ( V_103 >> 4 ) == ( V_102 >> 0x4 ) )
&& ( V_103 & V_102 & 0xf ) )
V_70 = 1 ;
break;
default:
F_75 ( L_5 ,
V_2 -> V_9 -> V_105 , F_16 ( V_2 , V_35 ) ) ;
break;
}
return V_70 ;
}
int F_87 ( struct V_8 * V_9 , struct V_1 * V_106 ,
int V_107 , int V_101 , int V_108 )
{
int V_70 = 0 ;
struct V_1 * V_109 = V_9 -> V_11 . V_2 ;
F_75 ( L_6
L_7 ,
V_109 , V_106 , V_101 , V_108 , V_107 ) ;
ASSERT ( V_109 ) ;
switch ( V_107 ) {
case V_110 :
if ( V_108 == 0 )
V_70 = F_84 ( V_109 , V_101 ) ;
else
V_70 = F_85 ( V_109 , V_101 ) ;
break;
case V_111 :
V_70 = ( V_109 == V_106 ) ;
break;
case V_112 :
V_70 = 1 ;
break;
case V_113 :
V_70 = ( V_109 != V_106 ) ;
break;
default:
F_75 ( L_8 ,
V_107 ) ;
break;
}
return V_70 ;
}
bool F_88 ( struct V_19 * V_19 , struct V_1 * V_114 ,
struct V_77 * V_78 , int * V_115 , unsigned long * V_79 )
{
struct V_20 * V_116 ;
unsigned long V_7 = 1 ;
struct V_1 * * V_117 ;
int V_23 ;
bool V_118 = false ;
* V_115 = - 1 ;
if ( V_78 -> V_119 == V_111 ) {
* V_115 = F_67 ( V_114 -> V_9 , V_78 , V_79 ) ;
return true ;
}
if ( V_78 -> V_119 )
return false ;
F_89 () ;
V_116 = F_90 ( V_19 -> V_11 . V_40 ) ;
if ( ! V_116 )
goto V_26;
if ( V_78 -> V_108 == 0 ) {
if ( V_78 -> V_80 == V_120 ||
V_78 -> V_121 == 0xff )
goto V_26;
V_117 = & V_116 -> V_37 [ V_78 -> V_121 & 0xff ] ;
} else {
T_1 V_102 = V_78 -> V_121 << ( 32 - V_116 -> V_27 ) ;
V_117 = V_116 -> V_39 [ F_29 ( V_116 , V_102 ) ] ;
V_7 = F_30 ( V_116 , V_102 ) ;
if ( V_78 -> V_80 == V_120 ) {
int V_122 = - 1 ;
F_91 (i, &bitmap, 16 ) {
if ( ! V_117 [ V_23 ] )
continue;
if ( V_122 < 0 )
V_122 = V_23 ;
else if ( F_92 ( V_117 [ V_23 ] -> V_9 , V_117 [ V_122 ] -> V_9 ) < 0 )
V_122 = V_23 ;
}
V_7 = ( V_122 >= 0 ) ? 1 << V_122 : 0 ;
}
}
F_91 (i, &bitmap, 16 ) {
if ( ! V_117 [ V_23 ] )
continue;
if ( * V_115 < 0 )
* V_115 = 0 ;
* V_115 += F_67 ( V_117 [ V_23 ] -> V_9 , V_78 , V_79 ) ;
}
V_118 = true ;
V_26:
F_93 () ;
return V_118 ;
}
static int F_68 ( struct V_1 * V_2 , int V_80 ,
int V_10 , int V_81 , int V_82 ,
unsigned long * V_79 )
{
int V_70 = 0 ;
struct V_8 * V_9 = V_2 -> V_9 ;
switch ( V_80 ) {
case V_120 :
V_9 -> V_11 . V_123 ++ ;
case V_124 :
if ( F_64 ( ! F_19 ( V_2 ) ) )
break;
V_70 = 1 ;
if ( V_79 )
F_77 ( V_9 -> V_105 , V_79 ) ;
if ( V_71 -> V_125 )
V_71 -> V_125 ( V_9 , V_10 ) ;
else {
F_55 ( V_10 , V_2 ) ;
F_82 ( V_100 , V_9 ) ;
F_94 ( V_9 ) ;
}
F_95 ( V_9 -> V_105 , V_80 ,
V_82 , V_10 , false ) ;
break;
case V_126 :
V_70 = 1 ;
V_9 -> V_11 . V_127 . V_128 = 1 ;
F_82 ( V_100 , V_9 ) ;
F_94 ( V_9 ) ;
break;
case V_129 :
F_75 ( L_9 ) ;
break;
case V_54 :
V_70 = 1 ;
F_96 ( V_9 ) ;
F_94 ( V_9 ) ;
break;
case V_130 :
if ( ! V_82 || V_81 ) {
V_70 = 1 ;
V_2 -> V_131 = ( 1UL << V_132 ) ;
F_97 () ;
F_82 ( V_100 , V_9 ) ;
F_94 ( V_9 ) ;
} else {
F_75 ( L_10 ,
V_9 -> V_105 ) ;
}
break;
case V_133 :
F_75 ( L_11 ,
V_9 -> V_105 , V_10 ) ;
V_70 = 1 ;
V_2 -> V_134 = V_10 ;
F_97 () ;
F_8 ( V_135 , & V_2 -> V_131 ) ;
F_82 ( V_100 , V_9 ) ;
F_94 ( V_9 ) ;
break;
case V_136 :
break;
default:
F_98 ( V_137 L_12 ,
V_80 ) ;
break;
}
return V_70 ;
}
int F_92 ( struct V_8 * V_138 , struct V_8 * V_139 )
{
return V_138 -> V_11 . V_123 - V_139 -> V_11 . V_123 ;
}
static void F_99 ( struct V_1 * V_2 , int V_10 )
{
if ( ! ( F_16 ( V_2 , V_14 ) & V_140 ) &&
F_100 ( V_2 -> V_9 -> V_19 , V_10 ) ) {
int V_141 ;
if ( F_2 ( V_10 , V_2 -> V_5 + V_92 ) )
V_141 = V_142 ;
else
V_141 = V_143 ;
F_101 ( V_2 -> V_9 , V_10 , V_141 ) ;
}
}
static int F_102 ( struct V_1 * V_2 )
{
int V_10 = F_61 ( V_2 ) ;
F_103 ( V_2 , V_10 ) ;
if ( V_10 == - 1 )
return V_10 ;
F_63 ( V_10 , V_2 ) ;
F_81 ( V_2 ) ;
F_99 ( V_2 , V_10 ) ;
F_82 ( V_100 , V_2 -> V_9 ) ;
return V_10 ;
}
void F_104 ( struct V_8 * V_9 , int V_10 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
F_103 ( V_2 , V_10 ) ;
F_99 ( V_2 , V_10 ) ;
F_82 ( V_100 , V_2 -> V_9 ) ;
}
static void F_105 ( struct V_1 * V_2 )
{
T_1 V_144 = F_16 ( V_2 , V_145 ) ;
T_1 V_146 = F_16 ( V_2 , V_147 ) ;
struct V_77 V_78 ;
V_78 . V_10 = V_144 & V_45 ;
V_78 . V_80 = V_144 & V_53 ;
V_78 . V_108 = V_144 & V_148 ;
V_78 . V_81 = V_144 & V_149 ;
V_78 . V_82 = V_144 & V_150 ;
V_78 . V_119 = V_144 & V_151 ;
if ( F_28 ( V_2 ) )
V_78 . V_121 = V_146 ;
else
V_78 . V_121 = F_106 ( V_146 ) ;
F_107 ( V_144 , V_78 . V_121 ) ;
F_75 ( L_13
L_14
L_15 ,
V_146 , V_144 , V_78 . V_119 , V_78 . V_121 ,
V_78 . V_82 , V_78 . V_81 , V_78 . V_108 , V_78 . V_80 ,
V_78 . V_10 ) ;
F_108 ( V_2 -> V_9 -> V_19 , V_2 , & V_78 , NULL ) ;
}
static T_1 F_109 ( struct V_1 * V_2 )
{
T_4 V_152 ;
T_5 V_153 ;
T_1 V_154 ;
ASSERT ( V_2 != NULL ) ;
if ( F_16 ( V_2 , V_155 ) == 0 ||
V_2 -> V_47 . V_156 == 0 )
return 0 ;
V_152 = F_110 ( & V_2 -> V_47 . V_157 ) ;
if ( F_111 ( V_152 ) < 0 )
V_152 = F_112 ( 0 , 0 ) ;
V_153 = F_113 ( F_111 ( V_152 ) , V_2 -> V_47 . V_156 ) ;
V_154 = F_114 ( V_153 ,
( V_158 * V_2 -> V_159 ) ) ;
return V_154 ;
}
static void F_115 ( struct V_1 * V_2 , bool V_160 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_161 * V_162 = V_9 -> V_162 ;
F_82 ( V_163 , V_9 ) ;
V_162 -> V_164 . V_165 = F_116 ( V_9 ) ;
V_162 -> V_164 . V_166 = V_160 ;
}
static inline void F_117 ( struct V_1 * V_2 , bool V_160 )
{
if ( V_2 -> V_9 -> V_11 . V_167 )
F_115 ( V_2 , V_160 ) ;
}
static T_1 F_118 ( struct V_1 * V_2 , unsigned int V_168 )
{
T_1 V_4 = 0 ;
if ( V_168 >= V_169 )
return 0 ;
switch ( V_168 ) {
case V_18 :
if ( F_28 ( V_2 ) )
V_4 = F_22 ( V_2 ) ;
else
V_4 = F_22 ( V_2 ) << 24 ;
break;
case V_170 :
F_75 ( L_16 ) ;
break;
case V_171 :
if ( F_44 ( V_2 ) )
return 0 ;
V_4 = F_109 ( V_2 ) ;
break;
case V_98 :
F_81 ( V_2 ) ;
V_4 = F_16 ( V_2 , V_168 ) ;
break;
case V_99 :
F_117 ( V_2 , false ) ;
default:
V_4 = F_16 ( V_2 , V_168 ) ;
break;
}
return V_4 ;
}
static inline struct V_1 * F_119 ( struct V_172 * V_173 )
{
return F_120 ( V_173 , struct V_1 , V_173 ) ;
}
static int F_121 ( struct V_1 * V_2 , T_1 V_168 , int V_174 ,
void * V_84 )
{
unsigned char V_175 = V_168 & 0xf ;
T_1 V_70 ;
static const T_6 V_176 = 0x43ff01ffffffe70cULL ;
if ( ( V_175 + V_174 ) > 4 ) {
F_75 ( L_17 ,
V_168 , V_174 ) ;
return 1 ;
}
if ( V_168 > 0x3f0 || ! ( V_176 & ( 1ULL << ( V_168 >> 4 ) ) ) ) {
F_75 ( L_18 ,
V_168 ) ;
return 1 ;
}
V_70 = F_118 ( V_2 , V_168 & ~ 0xf ) ;
F_122 ( V_168 , V_70 ) ;
switch ( V_174 ) {
case 1 :
case 2 :
case 4 :
memcpy ( V_84 , ( char * ) & V_70 + V_175 , V_174 ) ;
break;
default:
F_98 ( V_137 L_19
L_20 , V_174 ) ;
break;
}
return 0 ;
}
static int F_123 ( struct V_1 * V_2 , T_7 V_177 )
{
return F_21 ( V_2 ) &&
V_177 >= V_2 -> V_178 &&
V_177 < V_2 -> V_178 + V_169 ;
}
static int F_124 ( struct V_172 * V_179 ,
T_7 V_180 , int V_174 , void * V_84 )
{
struct V_1 * V_2 = F_119 ( V_179 ) ;
T_1 V_168 = V_180 - V_2 -> V_178 ;
if ( ! F_123 ( V_2 , V_180 ) )
return - V_181 ;
F_121 ( V_2 , V_168 , V_174 , V_84 ) ;
return 0 ;
}
static void F_125 ( struct V_1 * V_2 )
{
T_1 V_182 , V_183 , V_184 ;
V_184 = F_16 ( V_2 , V_185 ) ;
V_182 = V_184 & 0xf ;
V_183 = ( ( V_182 & 0x3 ) | ( ( V_182 & 0x8 ) >> 1 ) ) + 1 ;
V_2 -> V_159 = 0x1 << ( V_183 & 0x7 ) ;
F_75 ( L_21 ,
V_2 -> V_159 ) ;
}
static void F_126 ( struct V_1 * V_2 )
{
T_4 V_186 ;
F_127 ( & V_2 -> V_47 . V_187 , 0 ) ;
if ( F_43 ( V_2 ) || F_42 ( V_2 ) ) {
V_186 = V_2 -> V_47 . V_157 . V_188 -> V_189 () ;
V_2 -> V_47 . V_156 = ( T_6 ) F_16 ( V_2 , V_155 )
* V_158 * V_2 -> V_159 ;
if ( ! V_2 -> V_47 . V_156 )
return;
if ( F_43 ( V_2 ) ) {
T_5 V_190 = V_191 * 1000LL ;
if ( V_2 -> V_47 . V_156 < V_190 ) {
F_128 (
L_22
L_23 ,
V_2 -> V_9 -> V_105 ,
V_2 -> V_47 . V_156 , V_190 ) ;
V_2 -> V_47 . V_156 = V_190 ;
}
}
F_129 ( & V_2 -> V_47 . V_157 ,
F_130 ( V_186 , V_2 -> V_47 . V_156 ) ,
V_192 ) ;
F_75 ( L_24 V_193 L_25
V_194 L_26
L_27
L_28 V_194 L_29 , V_195 ,
V_158 , F_111 ( V_186 ) ,
F_16 ( V_2 , V_155 ) ,
V_2 -> V_47 . V_156 ,
F_111 ( F_130 ( V_186 ,
V_2 -> V_47 . V_156 ) ) ) ;
} else if ( F_44 ( V_2 ) ) {
T_6 V_196 , V_197 = V_2 -> V_47 . V_197 ;
T_6 V_153 = 0 ;
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned long V_198 = V_9 -> V_11 . V_199 ;
unsigned long V_200 ;
if ( F_64 ( ! V_197 || ! V_198 ) )
return;
F_131 ( V_200 ) ;
V_186 = V_2 -> V_47 . V_157 . V_188 -> V_189 () ;
V_196 = V_71 -> V_201 ( V_9 , F_132 () ) ;
if ( F_62 ( V_197 > V_196 ) ) {
V_153 = ( V_197 - V_196 ) * 1000000ULL ;
F_133 ( V_153 , V_198 ) ;
}
F_129 ( & V_2 -> V_47 . V_157 ,
F_130 ( V_186 , V_153 ) , V_192 ) ;
F_134 ( V_200 ) ;
}
}
static void F_135 ( struct V_1 * V_2 , T_1 V_202 )
{
int V_203 = F_45 ( F_16 ( V_2 , V_204 ) ) ;
if ( F_45 ( V_202 ) ) {
if ( ! V_203 ) {
F_75 ( L_30
L_31 , V_2 -> V_9 -> V_105 ) ;
V_2 -> V_9 -> V_19 -> V_11 . V_205 ++ ;
}
} else if ( V_203 )
V_2 -> V_9 -> V_19 -> V_11 . V_205 -- ;
}
static int F_136 ( struct V_1 * V_2 , T_1 V_63 , T_1 V_4 )
{
int V_118 = 0 ;
F_137 ( V_63 , V_4 ) ;
switch ( V_63 ) {
case V_18 :
if ( ! F_28 ( V_2 ) )
F_38 ( V_2 , V_4 >> 24 ) ;
else
V_118 = 1 ;
break;
case V_99 :
F_117 ( V_2 , true ) ;
F_83 ( V_2 , V_4 & 0xff ) ;
break;
case V_206 :
F_102 ( V_2 ) ;
break;
case V_38 :
if ( ! F_28 ( V_2 ) )
F_39 ( V_2 , V_4 & V_207 ) ;
else
V_118 = 1 ;
break;
case V_35 :
if ( ! F_28 ( V_2 ) ) {
F_1 ( V_2 , V_35 , V_4 | 0x0FFFFFFF ) ;
F_23 ( V_2 -> V_9 -> V_19 ) ;
} else
V_118 = 1 ;
break;
case V_14 : {
T_1 V_208 = 0x3ff ;
if ( F_16 ( V_2 , V_62 ) & V_61 )
V_208 |= V_140 ;
F_15 ( V_2 , V_4 & V_208 ) ;
if ( ! ( V_4 & V_15 ) ) {
int V_23 ;
T_1 V_52 ;
for ( V_23 = 0 ; V_23 < V_209 ; V_23 ++ ) {
V_52 = F_16 ( V_2 ,
V_46 + 0x10 * V_23 ) ;
F_1 ( V_2 , V_46 + 0x10 * V_23 ,
V_52 | V_44 ) ;
}
F_127 ( & V_2 -> V_47 . V_187 , 0 ) ;
}
break;
}
case V_145 :
F_1 ( V_2 , V_145 , V_4 & ~ ( 1 << 12 ) ) ;
F_105 ( V_2 ) ;
break;
case V_147 :
if ( ! F_28 ( V_2 ) )
V_4 &= 0xff000000 ;
F_1 ( V_2 , V_147 , V_4 ) ;
break;
case V_204 :
F_135 ( V_2 , V_4 ) ;
case V_210 :
case V_211 :
case V_212 :
case V_213 :
if ( ! F_20 ( V_2 ) )
V_4 |= V_44 ;
V_4 &= V_214 [ ( V_63 - V_46 ) >> 4 ] ;
F_1 ( V_2 , V_63 , V_4 ) ;
break;
case V_46 :
if ( ( F_16 ( V_2 , V_46 ) &
V_2 -> V_47 . V_48 ) !=
( V_4 & V_2 -> V_47 . V_48 ) )
F_138 ( & V_2 -> V_47 . V_157 ) ;
if ( ! F_20 ( V_2 ) )
V_4 |= V_44 ;
V_4 &= ( V_214 [ 0 ] | V_2 -> V_47 . V_48 ) ;
F_1 ( V_2 , V_46 , V_4 ) ;
break;
case V_155 :
if ( F_44 ( V_2 ) )
break;
F_138 ( & V_2 -> V_47 . V_157 ) ;
F_1 ( V_2 , V_155 , V_4 ) ;
F_126 ( V_2 ) ;
break;
case V_185 :
if ( V_4 & 4 )
F_75 ( L_32 , V_4 ) ;
F_1 ( V_2 , V_185 , V_4 ) ;
F_125 ( V_2 ) ;
break;
case V_215 :
if ( F_28 ( V_2 ) && V_4 != 0 ) {
F_75 ( L_33 , V_4 ) ;
V_118 = 1 ;
}
break;
case V_216 :
if ( F_28 ( V_2 ) ) {
F_136 ( V_2 , V_145 , 0x40000 | ( V_4 & 0xff ) ) ;
} else
V_118 = 1 ;
break;
default:
V_118 = 1 ;
break;
}
if ( V_118 )
F_75 ( L_34 , V_63 ) ;
return V_118 ;
}
static int F_139 ( struct V_172 * V_179 ,
T_7 V_180 , int V_174 , const void * V_84 )
{
struct V_1 * V_2 = F_119 ( V_179 ) ;
unsigned int V_168 = V_180 - V_2 -> V_178 ;
T_1 V_4 ;
if ( ! F_123 ( V_2 , V_180 ) )
return - V_181 ;
if ( V_174 != 4 || ( V_168 & 0xf ) ) {
F_75 ( L_35 , V_174 , ( long ) V_180 ) ;
return 0 ;
}
V_4 = * ( T_1 * ) V_84 ;
if ( V_168 != V_206 )
F_75 ( L_36
L_37 , V_195 , V_168 , V_174 , V_4 ) ;
F_136 ( V_2 , V_168 & 0xff0 , V_4 ) ;
return 0 ;
}
void F_140 ( struct V_8 * V_9 )
{
if ( F_47 ( V_9 ) )
F_136 ( V_9 -> V_11 . V_2 , V_206 , 0 ) ;
}
void F_141 ( struct V_8 * V_9 , T_1 V_168 )
{
T_1 V_4 = 0 ;
V_168 &= 0xff0 ;
F_121 ( V_9 -> V_11 . V_2 , V_168 , 4 , & V_4 ) ;
F_136 ( V_9 -> V_11 . V_2 , V_168 , V_4 ) ;
}
void F_142 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! V_9 -> V_11 . V_2 )
return;
F_138 ( & V_2 -> V_47 . V_157 ) ;
if ( ! ( V_9 -> V_11 . V_217 & V_218 ) )
F_17 ( & V_219 ) ;
if ( ! ( F_16 ( V_2 , V_14 ) & V_15 ) )
F_17 ( & V_16 ) ;
if ( V_2 -> V_5 )
F_143 ( ( unsigned long ) V_2 -> V_5 ) ;
F_144 ( V_2 ) ;
}
T_6 F_145 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_47 ( V_9 ) || F_42 ( V_2 ) ||
F_43 ( V_2 ) )
return 0 ;
return V_2 -> V_47 . V_197 ;
}
void F_146 ( struct V_8 * V_9 , T_6 V_84 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_47 ( V_9 ) || F_42 ( V_2 ) ||
F_43 ( V_2 ) )
return;
F_138 ( & V_2 -> V_47 . V_157 ) ;
V_2 -> V_47 . V_197 = V_84 ;
F_126 ( V_2 ) ;
}
void F_147 ( struct V_8 * V_9 , unsigned long V_220 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_47 ( V_9 ) )
return;
F_83 ( V_2 , ( ( V_220 & 0x0f ) << 4 )
| ( F_16 ( V_2 , V_99 ) & 4 ) ) ;
}
T_6 F_148 ( struct V_8 * V_9 )
{
T_6 V_93 ;
if ( ! F_47 ( V_9 ) )
return 0 ;
V_93 = ( T_6 ) F_16 ( V_9 -> V_11 . V_2 , V_99 ) ;
return ( V_93 & 0xf0 ) >> 4 ;
}
void F_149 ( struct V_8 * V_9 , T_6 V_221 )
{
T_6 V_222 = V_9 -> V_11 . V_217 ;
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! V_2 ) {
V_221 |= V_223 ;
V_9 -> V_11 . V_217 = V_221 ;
return;
}
if ( ! F_150 ( V_2 -> V_9 ) )
V_221 &= ~ V_223 ;
V_9 -> V_11 . V_217 = V_221 ;
if ( ( V_222 ^ V_221 ) & V_218 ) {
if ( V_221 & V_218 )
F_17 ( & V_219 ) ;
else
F_18 ( & V_219 . V_17 ) ;
F_23 ( V_9 -> V_19 ) ;
}
if ( ( V_222 ^ V_221 ) & V_224 ) {
if ( V_221 & V_224 ) {
T_1 V_42 = F_22 ( V_2 ) ;
T_1 V_33 = ( ( V_42 >> 4 ) << 16 ) | ( 1 << ( V_42 & 0xf ) ) ;
F_39 ( V_2 , V_33 ) ;
V_71 -> V_225 ( V_9 , true ) ;
} else
V_71 -> V_225 ( V_9 , false ) ;
}
V_2 -> V_178 = V_2 -> V_9 -> V_11 . V_217 &
V_226 ;
F_75 ( L_38 V_194 L_39
L_40 , V_2 -> V_9 -> V_11 . V_217 , V_2 -> V_178 ) ;
}
void F_151 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
int V_23 ;
F_75 ( L_41 , V_195 ) ;
ASSERT ( V_9 ) ;
V_2 = V_9 -> V_11 . V_2 ;
ASSERT ( V_2 != NULL ) ;
F_138 ( & V_2 -> V_47 . V_157 ) ;
F_38 ( V_2 , V_9 -> V_105 ) ;
F_46 ( V_2 -> V_9 ) ;
for ( V_23 = 0 ; V_23 < V_209 ; V_23 ++ )
F_1 ( V_2 , V_46 + 0x10 * V_23 , V_44 ) ;
F_1 ( V_2 , V_204 ,
F_152 ( 0 , V_227 ) ) ;
F_1 ( V_2 , V_35 , 0xffffffffU ) ;
F_15 ( V_2 , 0xff ) ;
F_1 ( V_2 , V_99 , 0 ) ;
F_39 ( V_2 , 0 ) ;
F_1 ( V_2 , V_215 , 0 ) ;
F_1 ( V_2 , V_145 , 0 ) ;
F_1 ( V_2 , V_147 , 0 ) ;
F_1 ( V_2 , V_185 , 0 ) ;
F_1 ( V_2 , V_155 , 0 ) ;
for ( V_23 = 0 ; V_23 < 8 ; V_23 ++ ) {
F_1 ( V_2 , V_13 + 0x10 * V_23 , 0 ) ;
F_1 ( V_2 , V_12 + 0x10 * V_23 , 0 ) ;
F_1 ( V_2 , V_92 + 0x10 * V_23 , 0 ) ;
}
V_2 -> V_69 = F_65 ( V_9 -> V_19 ) ;
V_2 -> V_73 = F_65 ( V_9 -> V_19 ) ;
V_2 -> V_74 = - 1 ;
F_125 ( V_2 ) ;
F_127 ( & V_2 -> V_47 . V_187 , 0 ) ;
if ( F_150 ( V_9 ) )
F_149 ( V_9 ,
V_9 -> V_11 . V_217 | V_223 ) ;
V_9 -> V_11 . V_83 . V_85 = 0 ;
F_81 ( V_2 ) ;
V_9 -> V_11 . V_123 = 0 ;
V_9 -> V_11 . V_89 = 0 ;
F_75 ( V_228 L_42
L_43 V_194 L_44 , V_195 ,
V_9 , F_22 ( V_2 ) ,
V_9 -> V_11 . V_217 , V_2 -> V_178 ) ;
}
static bool F_153 ( struct V_1 * V_2 )
{
return F_43 ( V_2 ) ;
}
int F_154 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( F_47 ( V_9 ) && F_19 ( V_2 ) &&
F_40 ( V_2 , V_46 ) )
return F_155 ( & V_2 -> V_47 . V_187 ) ;
return 0 ;
}
int F_156 ( struct V_1 * V_2 , int V_43 )
{
T_1 V_63 = F_16 ( V_2 , V_43 ) ;
int V_10 , V_229 , V_82 ;
if ( F_21 ( V_2 ) && ! ( V_63 & V_44 ) ) {
V_10 = V_63 & V_45 ;
V_229 = V_63 & V_53 ;
V_82 = V_63 & V_230 ;
return F_68 ( V_2 , V_229 , V_10 , 1 , V_82 ,
NULL ) ;
}
return 0 ;
}
void F_157 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( V_2 )
F_156 ( V_2 , V_204 ) ;
}
static enum V_231 F_158 ( struct V_232 * V_84 )
{
struct V_233 * V_234 = F_120 ( V_84 , struct V_233 , V_157 ) ;
struct V_1 * V_2 = F_120 ( V_234 , struct V_1 , V_47 ) ;
struct V_8 * V_9 = V_2 -> V_9 ;
T_8 * V_235 = & V_9 -> V_236 ;
if ( ! F_155 ( & V_234 -> V_187 ) ) {
F_159 ( & V_234 -> V_187 ) ;
F_82 ( V_237 , V_9 ) ;
}
if ( F_160 ( V_235 ) )
F_161 ( V_235 ) ;
if ( F_153 ( V_2 ) ) {
F_162 ( & V_234 -> V_157 , V_234 -> V_156 ) ;
return V_238 ;
} else
return V_239 ;
}
int F_163 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
ASSERT ( V_9 != NULL ) ;
F_75 ( L_45 , V_9 -> V_105 ) ;
V_2 = F_24 ( sizeof( * V_2 ) , V_24 ) ;
if ( ! V_2 )
goto V_240;
V_9 -> V_11 . V_2 = V_2 ;
V_2 -> V_5 = ( void * ) F_164 ( V_24 ) ;
if ( ! V_2 -> V_5 ) {
F_98 ( V_137 L_46 ,
V_9 -> V_105 ) ;
goto V_241;
}
V_2 -> V_9 = V_9 ;
F_165 ( & V_2 -> V_47 . V_157 , V_242 ,
V_192 ) ;
V_2 -> V_47 . V_157 . V_243 = F_158 ;
V_9 -> V_11 . V_217 = V_218 ;
F_149 ( V_9 ,
V_244 | V_218 ) ;
F_18 ( & V_16 . V_17 ) ;
F_151 ( V_9 ) ;
F_166 ( & V_2 -> V_173 , & V_245 ) ;
return 0 ;
V_241:
F_144 ( V_2 ) ;
V_240:
return - V_246 ;
}
int F_167 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
int V_76 ;
if ( ! F_47 ( V_9 ) || ! F_19 ( V_2 ) )
return - 1 ;
F_81 ( V_2 ) ;
V_76 = F_57 ( V_2 ) ;
if ( ( V_76 == - 1 ) ||
( ( V_76 & 0xF0 ) <= F_16 ( V_2 , V_98 ) ) )
return - 1 ;
return V_76 ;
}
int F_168 ( struct V_8 * V_9 )
{
T_1 V_247 = F_16 ( V_9 -> V_11 . V_2 , V_204 ) ;
int V_115 = 0 ;
if ( ! F_21 ( V_9 -> V_11 . V_2 ) )
V_115 = 1 ;
if ( ( V_247 & V_44 ) == 0 &&
F_169 ( V_247 ) == V_227 )
V_115 = 1 ;
return V_115 ;
}
void F_170 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_47 ( V_9 ) )
return;
if ( F_155 ( & V_2 -> V_47 . V_187 ) > 0 ) {
F_156 ( V_2 , V_46 ) ;
F_127 ( & V_2 -> V_47 . V_187 , 0 ) ;
}
}
int F_171 ( struct V_8 * V_9 )
{
int V_10 = F_167 ( V_9 ) ;
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( V_10 == - 1 )
return - 1 ;
F_59 ( V_10 , V_2 ) ;
F_81 ( V_2 ) ;
F_58 ( V_10 , V_2 ) ;
return V_10 ;
}
void F_172 ( struct V_8 * V_9 ,
struct V_248 * V_249 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
F_149 ( V_9 , V_9 -> V_11 . V_217 ) ;
F_15 ( V_2 , * ( ( T_1 * ) ( V_249 -> V_5 + V_14 ) ) ) ;
memcpy ( V_9 -> V_11 . V_2 -> V_5 , V_249 -> V_5 , sizeof *V_249 ) ;
F_38 ( V_2 , F_22 ( V_2 ) ) ;
F_46 ( V_9 ) ;
F_81 ( V_2 ) ;
F_138 ( & V_2 -> V_47 . V_157 ) ;
F_125 ( V_2 ) ;
F_126 ( V_2 ) ;
V_2 -> V_69 = true ;
V_2 -> V_73 = F_65 ( V_9 -> V_19 ) ?
1 : F_51 ( V_2 -> V_5 + V_12 ) ;
V_2 -> V_74 = - 1 ;
V_71 -> V_75 ( V_9 -> V_19 , F_61 ( V_2 ) ) ;
F_82 ( V_100 , V_9 ) ;
F_173 ( V_9 ) ;
}
void F_174 ( struct V_8 * V_9 )
{
struct V_232 * V_157 ;
if ( ! F_47 ( V_9 ) )
return;
V_157 = & V_9 -> V_11 . V_2 -> V_47 . V_157 ;
if ( F_138 ( V_157 ) )
F_175 ( V_157 , V_192 ) ;
}
static void F_176 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
bool V_187 ;
int V_10 ;
F_60 ( ! F_73 ( V_9 ) ) ;
V_187 = F_74 ( V_9 ) ;
F_78 ( V_9 ) ;
if ( V_187 )
return;
V_10 = F_102 ( V_2 ) ;
F_177 ( V_2 , V_10 ) ;
}
void F_178 ( struct V_8 * V_9 )
{
T_1 V_84 ;
if ( F_3 ( V_88 , & V_9 -> V_11 . V_89 ) )
F_176 ( V_9 , V_9 -> V_11 . V_2 ) ;
if ( ! F_3 ( V_250 , & V_9 -> V_11 . V_89 ) )
return;
F_72 ( V_9 -> V_19 , & V_9 -> V_11 . V_2 -> V_251 , & V_84 ,
sizeof( T_1 ) ) ;
F_83 ( V_9 -> V_11 . V_2 , V_84 & 0xff ) ;
}
static void F_179 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
if ( ! F_73 ( V_9 ) ||
V_2 -> V_69 ||
V_2 -> V_74 == - 1 ||
F_100 ( V_9 -> V_19 , V_2 -> V_74 ) ) {
return;
}
F_76 ( V_2 -> V_9 ) ;
}
void F_180 ( struct V_8 * V_9 )
{
T_1 V_84 , V_93 ;
int V_252 , V_253 ;
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
F_179 ( V_9 , V_2 ) ;
if ( ! F_3 ( V_250 , & V_9 -> V_11 . V_89 ) )
return;
V_93 = F_16 ( V_2 , V_99 ) & 0xff ;
V_252 = F_57 ( V_2 ) ;
if ( V_252 < 0 )
V_252 = 0 ;
V_253 = F_61 ( V_2 ) ;
if ( V_253 < 0 )
V_253 = 0 ;
V_84 = ( V_93 & 0xff ) | ( ( V_253 & 0xf0 ) << 8 ) | ( V_252 << 24 ) ;
F_70 ( V_9 -> V_19 , & V_9 -> V_11 . V_2 -> V_251 , & V_84 ,
sizeof( T_1 ) ) ;
}
int F_181 ( struct V_8 * V_9 , T_7 V_254 )
{
if ( V_254 ) {
if ( F_182 ( V_9 -> V_19 ,
& V_9 -> V_11 . V_2 -> V_251 ,
V_254 , sizeof( T_1 ) ) )
return - V_255 ;
F_77 ( V_250 , & V_9 -> V_11 . V_89 ) ;
} else {
F_79 ( V_250 , & V_9 -> V_11 . V_89 ) ;
}
V_9 -> V_11 . V_2 -> V_254 = V_254 ;
return 0 ;
}
int F_183 ( struct V_8 * V_9 , T_1 V_256 , T_6 V_84 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_1 V_63 = ( V_256 - V_257 ) << 4 ;
if ( ! F_184 ( V_9 -> V_19 ) || ! F_28 ( V_2 ) )
return 1 ;
if ( V_256 == 0x830 )
F_136 ( V_2 , V_147 , ( T_1 ) ( V_84 >> 32 ) ) ;
return F_136 ( V_2 , V_63 , ( T_1 ) V_84 ) ;
}
int F_185 ( struct V_8 * V_9 , T_1 V_256 , T_6 * V_84 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_1 V_63 = ( V_256 - V_257 ) << 4 , V_258 , V_259 = 0 ;
if ( ! F_184 ( V_9 -> V_19 ) || ! F_28 ( V_2 ) )
return 1 ;
if ( F_121 ( V_2 , V_63 , 4 , & V_258 ) )
return 1 ;
if ( V_256 == 0x830 )
F_121 ( V_2 , V_147 , 4 , & V_259 ) ;
* V_84 = ( ( ( T_6 ) V_259 ) << 32 ) | V_258 ;
return 0 ;
}
int F_186 ( struct V_8 * V_9 , T_1 V_63 , T_6 V_84 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_47 ( V_9 ) )
return 1 ;
if ( V_63 == V_145 )
F_136 ( V_2 , V_147 , ( T_1 ) ( V_84 >> 32 ) ) ;
return F_136 ( V_2 , V_63 , ( T_1 ) V_84 ) ;
}
int F_187 ( struct V_8 * V_9 , T_1 V_63 , T_6 * V_84 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_1 V_258 , V_259 = 0 ;
if ( ! F_47 ( V_9 ) )
return 1 ;
if ( F_121 ( V_2 , V_63 , 4 , & V_258 ) )
return 1 ;
if ( V_63 == V_145 )
F_121 ( V_2 , V_147 , 4 , & V_259 ) ;
* V_84 = ( ( ( T_6 ) V_259 ) << 32 ) | V_258 ;
return 0 ;
}
int F_188 ( struct V_8 * V_9 , T_6 V_84 )
{
T_6 V_177 = V_84 & ~ V_86 ;
if ( ! F_189 ( V_177 , 4 ) )
return 1 ;
V_9 -> V_11 . V_83 . V_85 = V_84 ;
if ( ! F_73 ( V_9 ) )
return 0 ;
return F_182 ( V_9 -> V_19 , & V_9 -> V_11 . V_83 . V_84 ,
V_177 , sizeof( T_3 ) ) ;
}
void F_190 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
unsigned int V_134 ;
unsigned long V_260 ;
if ( ! F_47 ( V_9 ) || ! V_2 -> V_131 )
return;
V_260 = F_54 ( & V_2 -> V_131 , 0 ) ;
if ( F_3 ( V_132 , & V_260 ) ) {
F_151 ( V_9 ) ;
F_191 ( V_9 ) ;
if ( F_150 ( V_2 -> V_9 ) )
V_9 -> V_11 . V_261 = V_262 ;
else
V_9 -> V_11 . V_261 = V_263 ;
}
if ( F_3 ( V_135 , & V_260 ) &&
V_9 -> V_11 . V_261 == V_263 ) {
F_192 () ;
V_134 = V_2 -> V_134 ;
F_193 ( L_47 ,
V_9 -> V_105 , V_134 ) ;
F_194 ( V_9 , V_134 ) ;
V_9 -> V_11 . V_261 = V_262 ;
}
}
void F_195 ( void )
{
F_196 ( & V_219 , V_264 ) ;
F_196 ( & V_16 , V_264 ) ;
}
