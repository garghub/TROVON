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
static inline int F_15 ( struct V_1 * V_2 )
{
return F_16 ( V_2 ) && F_17 ( V_2 ) ;
}
static inline int F_18 ( struct V_1 * V_2 )
{
return ( F_19 ( V_2 , V_14 ) >> 24 ) & 0xff ;
}
static void F_20 ( struct V_15 * V_15 )
{
struct V_16 * V_17 , * V_18 = NULL ;
struct V_8 * V_9 ;
int V_19 ;
V_17 = F_21 ( sizeof( struct V_16 ) , V_20 ) ;
F_22 ( & V_15 -> V_11 . V_21 ) ;
if ( ! V_17 )
goto V_22;
V_17 -> V_23 = 8 ;
V_17 -> V_24 = 8 ;
V_17 -> V_25 = 0 ;
V_17 -> V_26 = 0xff ;
F_23 (i, vcpu, kvm) {
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_2 V_27 , V_28 ;
T_1 V_29 ;
if ( ! F_24 ( V_9 ) )
continue;
if ( F_25 ( V_2 ) ) {
V_17 -> V_23 = 32 ;
V_17 -> V_24 = 16 ;
V_17 -> V_25 = ( 1 << V_30 ) - 1 ;
V_17 -> V_26 = 0xffff ;
} else if ( F_16 ( V_2 ) &&
! V_17 -> V_25 &&
F_19 ( V_2 , V_31 ) == V_32 ) {
V_17 -> V_24 = 4 ;
V_17 -> V_25 = 0xf ;
V_17 -> V_26 = 0xf ;
}
V_17 -> V_33 [ F_18 ( V_2 ) ] = V_2 ;
V_29 = F_19 ( V_2 , V_34 ) ;
V_27 = F_26 ( V_17 , V_29 ) ;
V_28 = F_27 ( V_17 , V_29 ) ;
if ( V_28 )
V_17 -> V_35 [ V_27 ] [ F_28 ( V_28 ) - 1 ] = V_2 ;
}
V_22:
V_18 = F_29 ( V_15 -> V_11 . V_36 ,
F_30 ( & V_15 -> V_11 . V_21 ) ) ;
F_31 ( V_15 -> V_11 . V_36 , V_17 ) ;
F_32 ( & V_15 -> V_11 . V_21 ) ;
if ( V_18 )
F_33 ( V_18 , V_37 ) ;
F_34 ( V_15 ) ;
}
static inline void F_35 ( struct V_1 * V_2 , T_1 V_4 )
{
T_1 V_38 = F_19 ( V_2 , V_39 ) ;
F_1 ( V_2 , V_39 , V_4 ) ;
if ( ( V_38 ^ V_4 ) & V_40 ) {
if ( V_4 & V_40 ) {
F_36 ( & V_41 ) ;
F_20 ( V_2 -> V_9 -> V_15 ) ;
} else
F_37 ( & V_41 . V_42 ) ;
}
}
static inline void F_38 ( struct V_1 * V_2 , T_3 V_43 )
{
F_1 ( V_2 , V_14 , V_43 << 24 ) ;
F_20 ( V_2 -> V_9 -> V_15 ) ;
}
static inline void F_39 ( struct V_1 * V_2 , T_1 V_43 )
{
F_1 ( V_2 , V_34 , V_43 ) ;
F_20 ( V_2 -> V_9 -> V_15 ) ;
}
static inline int F_40 ( struct V_1 * V_2 , int V_44 )
{
return ! ( F_19 ( V_2 , V_44 ) & V_45 ) ;
}
static inline int F_41 ( struct V_1 * V_2 , int V_44 )
{
return F_19 ( V_2 , V_44 ) & V_46 ;
}
static inline int F_42 ( struct V_1 * V_2 )
{
return ( ( F_19 ( V_2 , V_47 ) &
V_2 -> V_48 . V_49 ) == V_50 ) ;
}
static inline int F_43 ( struct V_1 * V_2 )
{
return ( ( F_19 ( V_2 , V_47 ) &
V_2 -> V_48 . V_49 ) == V_51 ) ;
}
static inline int F_44 ( struct V_1 * V_2 )
{
return ( ( F_19 ( V_2 , V_47 ) &
V_2 -> V_48 . V_49 ) ==
V_52 ) ;
}
static inline int F_45 ( T_1 V_53 )
{
return ( V_53 & ( V_54 | V_45 ) ) == V_55 ;
}
void F_46 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
struct V_56 * V_57 ;
T_1 V_58 = V_59 ;
if ( ! F_47 ( V_9 ) )
return;
V_57 = F_48 ( V_2 -> V_9 , 0x1 , 0 ) ;
if ( V_57 && ( V_57 -> V_60 & ( 1 << ( V_61 & 31 ) ) ) )
V_58 |= V_62 ;
F_1 ( V_2 , V_63 , V_58 ) ;
}
static int F_49 ( void * V_7 )
{
int V_6 ;
T_1 * V_64 ;
for ( V_6 = V_65 - V_66 ;
V_6 >= 0 ; V_6 -= V_66 ) {
V_64 = V_7 + F_5 ( V_6 ) ;
if ( * V_64 )
return F_50 ( * V_64 ) - 1 + V_6 ;
}
return - 1 ;
}
static T_3 F_51 ( void * V_7 )
{
int V_6 ;
T_1 * V_64 ;
T_3 V_67 = 0 ;
for ( V_6 = 0 ; V_6 < V_65 ; V_6 += V_66 ) {
V_64 = V_7 + F_5 ( V_6 ) ;
V_67 += F_52 ( * V_64 ) ;
}
return V_67 ;
}
void F_53 ( struct V_8 * V_9 , T_1 * V_68 )
{
T_1 V_19 , V_69 ;
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
for ( V_19 = 0 ; V_19 <= 7 ; V_19 ++ ) {
V_69 = F_54 ( & V_68 [ V_19 ] , 0 ) ;
if ( V_69 )
* ( ( T_1 * ) ( V_2 -> V_5 + V_13 + V_19 * 0x10 ) ) |= V_69 ;
}
}
static inline void F_55 ( int V_6 , struct V_1 * V_2 )
{
V_2 -> V_70 = true ;
F_7 ( V_6 , V_2 -> V_5 + V_13 ) ;
}
static inline int F_56 ( struct V_1 * V_2 )
{
return F_49 ( V_2 -> V_5 + V_13 ) ;
}
static inline int F_57 ( struct V_1 * V_2 )
{
int V_71 ;
if ( ! V_2 -> V_70 )
return - 1 ;
V_72 -> V_73 ( V_2 -> V_9 ) ;
V_71 = F_56 ( V_2 ) ;
ASSERT ( V_71 == - 1 || V_71 >= 16 ) ;
return V_71 ;
}
static inline void F_58 ( int V_6 , struct V_1 * V_2 )
{
struct V_8 * V_9 ;
V_9 = V_2 -> V_9 ;
F_9 ( V_6 , V_2 -> V_5 + V_13 ) ;
if ( F_59 ( F_60 ( V_9 -> V_15 ) ) )
F_61 ( V_74 , V_9 ) ;
else {
V_6 = F_56 ( V_2 ) ;
V_2 -> V_70 = ( V_6 != - 1 ) ;
}
}
static inline void F_62 ( int V_6 , struct V_1 * V_2 )
{
struct V_8 * V_9 ;
if ( F_11 ( V_6 , V_2 -> V_5 + V_12 ) )
return;
V_9 = V_2 -> V_9 ;
if ( F_59 ( F_60 ( V_9 -> V_15 ) ) )
V_72 -> V_75 ( V_9 -> V_15 , V_6 ) ;
else {
++ V_2 -> V_76 ;
F_63 ( V_2 -> V_76 > V_65 ) ;
V_2 -> V_77 = V_6 ;
}
}
static inline int F_64 ( struct V_1 * V_2 )
{
int V_71 ;
if ( ! V_2 -> V_76 )
return - 1 ;
if ( F_65 ( V_2 -> V_77 != - 1 ) )
return V_2 -> V_77 ;
V_71 = F_49 ( V_2 -> V_5 + V_12 ) ;
ASSERT ( V_71 == - 1 || V_71 >= 16 ) ;
return V_71 ;
}
static inline void F_66 ( int V_6 , struct V_1 * V_2 )
{
struct V_8 * V_9 ;
if ( ! F_13 ( V_6 , V_2 -> V_5 + V_12 ) )
return;
V_9 = V_2 -> V_9 ;
if ( F_59 ( F_60 ( V_9 -> V_15 ) ) )
V_72 -> V_75 ( V_9 -> V_15 ,
F_64 ( V_2 ) ) ;
else {
-- V_2 -> V_76 ;
F_63 ( V_2 -> V_76 < 0 ) ;
V_2 -> V_77 = - 1 ;
}
}
int F_67 ( struct V_8 * V_9 )
{
int V_78 ;
if ( ! F_47 ( V_9 ) )
return 0 ;
V_78 = F_57 ( V_9 -> V_11 . V_2 ) ;
return V_78 ;
}
int F_68 ( struct V_8 * V_9 , struct V_79 * V_80 ,
unsigned long * V_81 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
return F_69 ( V_2 , V_80 -> V_82 , V_80 -> V_10 ,
V_80 -> V_83 , V_80 -> V_84 , V_81 ) ;
}
static int F_70 ( struct V_8 * V_9 , T_3 V_4 )
{
return F_71 ( V_9 -> V_15 , & V_9 -> V_11 . V_85 . V_86 , & V_4 ,
sizeof( V_4 ) ) ;
}
static int F_72 ( struct V_8 * V_9 , T_3 * V_4 )
{
return F_73 ( V_9 -> V_15 , & V_9 -> V_11 . V_85 . V_86 , V_4 ,
sizeof( * V_4 ) ) ;
}
static inline bool F_74 ( struct V_8 * V_9 )
{
return V_9 -> V_11 . V_85 . V_87 & V_88 ;
}
static bool F_75 ( struct V_8 * V_9 )
{
T_3 V_4 ;
if ( F_72 ( V_9 , & V_4 ) < 0 )
F_76 ( L_1 ,
( unsigned long long ) V_9 -> V_11 . V_85 . V_87 ) ;
return V_4 & 0x1 ;
}
static void F_77 ( struct V_8 * V_9 )
{
if ( F_70 ( V_9 , V_89 ) < 0 ) {
F_76 ( L_2 ,
( unsigned long long ) V_9 -> V_11 . V_85 . V_87 ) ;
return;
}
F_78 ( V_90 , & V_9 -> V_11 . V_91 ) ;
}
static void F_79 ( struct V_8 * V_9 )
{
if ( F_70 ( V_9 , V_92 ) < 0 ) {
F_76 ( L_3 ,
( unsigned long long ) V_9 -> V_11 . V_85 . V_87 ) ;
return;
}
F_80 ( V_90 , & V_9 -> V_11 . V_91 ) ;
}
void F_81 ( struct V_8 * V_9 , T_1 * V_93 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < 8 ; V_19 ++ )
F_1 ( V_2 , V_94 + 0x10 * V_19 , V_93 [ V_19 ] ) ;
}
static void F_82 ( struct V_1 * V_2 )
{
T_1 V_95 , V_96 , V_97 , V_98 ;
int V_99 ;
V_98 = F_19 ( V_2 , V_100 ) ;
V_95 = F_19 ( V_2 , V_101 ) ;
V_99 = F_64 ( V_2 ) ;
V_96 = ( V_99 != - 1 ) ? V_99 : 0 ;
if ( ( V_95 & 0xf0 ) >= ( V_96 & 0xf0 ) )
V_97 = V_95 & 0xff ;
else
V_97 = V_96 & 0xf0 ;
F_76 ( L_4 ,
V_2 , V_97 , V_99 , V_96 ) ;
if ( V_98 != V_97 ) {
F_1 ( V_2 , V_100 , V_97 ) ;
if ( V_97 < V_98 )
F_61 ( V_74 , V_2 -> V_9 ) ;
}
}
static void F_83 ( struct V_1 * V_2 , T_1 V_95 )
{
F_1 ( V_2 , V_101 , V_95 ) ;
F_82 ( V_2 ) ;
}
int F_84 ( struct V_1 * V_2 , T_2 V_102 )
{
return V_102 == 0xff || F_18 ( V_2 ) == V_102 ;
}
int F_85 ( struct V_1 * V_2 , T_3 V_103 )
{
int V_71 = 0 ;
T_1 V_104 ;
if ( F_25 ( V_2 ) ) {
V_104 = F_19 ( V_2 , V_34 ) ;
return V_104 & V_103 ;
}
V_104 = F_86 ( F_19 ( V_2 , V_34 ) ) ;
switch ( F_19 ( V_2 , V_31 ) ) {
case V_105 :
if ( V_104 & V_103 )
V_71 = 1 ;
break;
case V_32 :
if ( ( ( V_104 >> 4 ) == ( V_103 >> 0x4 ) )
&& ( V_104 & V_103 & 0xf ) )
V_71 = 1 ;
break;
default:
F_76 ( L_5 ,
V_2 -> V_9 -> V_106 , F_19 ( V_2 , V_31 ) ) ;
break;
}
return V_71 ;
}
int F_87 ( struct V_8 * V_9 , struct V_1 * V_107 ,
int V_108 , int V_102 , int V_109 )
{
int V_71 = 0 ;
struct V_1 * V_110 = V_9 -> V_11 . V_2 ;
F_76 ( L_6
L_7 ,
V_110 , V_107 , V_102 , V_109 , V_108 ) ;
ASSERT ( V_110 ) ;
switch ( V_108 ) {
case V_111 :
if ( V_109 == 0 )
V_71 = F_84 ( V_110 , V_102 ) ;
else
V_71 = F_85 ( V_110 , V_102 ) ;
break;
case V_112 :
V_71 = ( V_110 == V_107 ) ;
break;
case V_113 :
V_71 = 1 ;
break;
case V_114 :
V_71 = ( V_110 != V_107 ) ;
break;
default:
F_76 ( L_8 ,
V_108 ) ;
break;
}
return V_71 ;
}
bool F_88 ( struct V_15 * V_15 , struct V_1 * V_115 ,
struct V_79 * V_80 , int * V_116 , unsigned long * V_81 )
{
struct V_16 * V_117 ;
unsigned long V_7 = 1 ;
struct V_1 * * V_118 ;
int V_19 ;
bool V_119 = false ;
* V_116 = - 1 ;
if ( V_80 -> V_120 == V_112 ) {
* V_116 = F_68 ( V_115 -> V_9 , V_80 , V_81 ) ;
return true ;
}
if ( V_80 -> V_120 )
return false ;
F_89 () ;
V_117 = F_90 ( V_15 -> V_11 . V_36 ) ;
if ( ! V_117 )
goto V_22;
if ( V_80 -> V_109 == 0 ) {
if ( V_80 -> V_82 == V_121 ||
V_80 -> V_122 == 0xff )
goto V_22;
V_118 = & V_117 -> V_33 [ V_80 -> V_122 & 0xff ] ;
} else {
T_1 V_103 = V_80 -> V_122 << ( 32 - V_117 -> V_23 ) ;
V_118 = V_117 -> V_35 [ F_26 ( V_117 , V_103 ) ] ;
V_7 = F_27 ( V_117 , V_103 ) ;
if ( V_80 -> V_82 == V_121 ) {
int V_123 = - 1 ;
F_91 (i, &bitmap, 16 ) {
if ( ! V_118 [ V_19 ] )
continue;
if ( V_123 < 0 )
V_123 = V_19 ;
else if ( F_92 ( V_118 [ V_19 ] -> V_9 , V_118 [ V_123 ] -> V_9 ) < 0 )
V_123 = V_19 ;
}
V_7 = ( V_123 >= 0 ) ? 1 << V_123 : 0 ;
}
}
F_91 (i, &bitmap, 16 ) {
if ( ! V_118 [ V_19 ] )
continue;
if ( * V_116 < 0 )
* V_116 = 0 ;
* V_116 += F_68 ( V_118 [ V_19 ] -> V_9 , V_80 , V_81 ) ;
}
V_119 = true ;
V_22:
F_93 () ;
return V_119 ;
}
static int F_69 ( struct V_1 * V_2 , int V_82 ,
int V_10 , int V_83 , int V_84 ,
unsigned long * V_81 )
{
int V_71 = 0 ;
struct V_8 * V_9 = V_2 -> V_9 ;
F_94 ( V_9 -> V_106 , V_82 ,
V_84 , V_10 ) ;
switch ( V_82 ) {
case V_121 :
V_9 -> V_11 . V_124 ++ ;
case V_125 :
if ( F_59 ( ! F_15 ( V_2 ) ) )
break;
V_71 = 1 ;
if ( V_81 )
F_78 ( V_9 -> V_106 , V_81 ) ;
if ( V_72 -> V_126 )
V_72 -> V_126 ( V_9 , V_10 ) ;
else {
F_55 ( V_10 , V_2 ) ;
F_61 ( V_74 , V_9 ) ;
F_95 ( V_9 ) ;
}
break;
case V_127 :
V_71 = 1 ;
V_9 -> V_11 . V_128 . V_129 = 1 ;
F_61 ( V_74 , V_9 ) ;
F_95 ( V_9 ) ;
break;
case V_130 :
F_76 ( L_9 ) ;
break;
case V_55 :
V_71 = 1 ;
F_96 ( V_9 ) ;
F_95 ( V_9 ) ;
break;
case V_131 :
if ( ! V_84 || V_83 ) {
V_71 = 1 ;
V_2 -> V_132 = ( 1UL << V_133 ) ;
F_97 () ;
F_61 ( V_74 , V_9 ) ;
F_95 ( V_9 ) ;
} else {
F_76 ( L_10 ,
V_9 -> V_106 ) ;
}
break;
case V_134 :
F_76 ( L_11 ,
V_9 -> V_106 , V_10 ) ;
V_71 = 1 ;
V_2 -> V_135 = V_10 ;
F_97 () ;
F_8 ( V_136 , & V_2 -> V_132 ) ;
F_61 ( V_74 , V_9 ) ;
F_95 ( V_9 ) ;
break;
case V_137 :
break;
default:
F_98 ( V_138 L_12 ,
V_82 ) ;
break;
}
return V_71 ;
}
int F_92 ( struct V_8 * V_139 , struct V_8 * V_140 )
{
return V_139 -> V_11 . V_124 - V_140 -> V_11 . V_124 ;
}
static void F_99 ( struct V_1 * V_2 , int V_10 )
{
if ( ! ( F_19 ( V_2 , V_39 ) & V_141 ) &&
F_100 ( V_2 -> V_9 -> V_15 , V_10 ) ) {
int V_142 ;
if ( F_2 ( V_10 , V_2 -> V_5 + V_94 ) )
V_142 = V_143 ;
else
V_142 = V_144 ;
F_101 ( V_2 -> V_9 , V_10 , V_142 ) ;
}
}
static int F_102 ( struct V_1 * V_2 )
{
int V_10 = F_64 ( V_2 ) ;
F_103 ( V_2 , V_10 ) ;
if ( V_10 == - 1 )
return V_10 ;
F_66 ( V_10 , V_2 ) ;
F_82 ( V_2 ) ;
F_99 ( V_2 , V_10 ) ;
F_61 ( V_74 , V_2 -> V_9 ) ;
return V_10 ;
}
void F_104 ( struct V_8 * V_9 , int V_10 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
F_103 ( V_2 , V_10 ) ;
F_99 ( V_2 , V_10 ) ;
F_61 ( V_74 , V_2 -> V_9 ) ;
}
static void F_105 ( struct V_1 * V_2 )
{
T_1 V_145 = F_19 ( V_2 , V_146 ) ;
T_1 V_147 = F_19 ( V_2 , V_148 ) ;
struct V_79 V_80 ;
V_80 . V_10 = V_145 & V_46 ;
V_80 . V_82 = V_145 & V_54 ;
V_80 . V_109 = V_145 & V_149 ;
V_80 . V_83 = V_145 & V_150 ;
V_80 . V_84 = V_145 & V_151 ;
V_80 . V_120 = V_145 & V_152 ;
if ( F_25 ( V_2 ) )
V_80 . V_122 = V_147 ;
else
V_80 . V_122 = F_106 ( V_147 ) ;
F_107 ( V_145 , V_80 . V_122 ) ;
F_76 ( L_13
L_14
L_15 ,
V_147 , V_145 , V_80 . V_120 , V_80 . V_122 ,
V_80 . V_84 , V_80 . V_83 , V_80 . V_109 , V_80 . V_82 ,
V_80 . V_10 ) ;
F_108 ( V_2 -> V_9 -> V_15 , V_2 , & V_80 , NULL ) ;
}
static T_1 F_109 ( struct V_1 * V_2 )
{
T_4 V_153 ;
T_5 V_154 ;
T_1 V_155 ;
ASSERT ( V_2 != NULL ) ;
if ( F_19 ( V_2 , V_156 ) == 0 ||
V_2 -> V_48 . V_157 == 0 )
return 0 ;
V_153 = F_110 ( & V_2 -> V_48 . V_158 ) ;
if ( F_111 ( V_153 ) < 0 )
V_153 = F_112 ( 0 , 0 ) ;
V_154 = F_113 ( F_111 ( V_153 ) , V_2 -> V_48 . V_157 ) ;
V_155 = F_114 ( V_154 ,
( V_159 * V_2 -> V_160 ) ) ;
return V_155 ;
}
static void F_115 ( struct V_1 * V_2 , bool V_161 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_162 * V_163 = V_9 -> V_163 ;
F_61 ( V_164 , V_9 ) ;
V_163 -> V_165 . V_166 = F_116 ( V_9 ) ;
V_163 -> V_165 . V_167 = V_161 ;
}
static inline void F_117 ( struct V_1 * V_2 , bool V_161 )
{
if ( V_2 -> V_9 -> V_11 . V_168 )
F_115 ( V_2 , V_161 ) ;
}
static T_1 F_118 ( struct V_1 * V_2 , unsigned int V_169 )
{
T_1 V_4 = 0 ;
if ( V_169 >= V_170 )
return 0 ;
switch ( V_169 ) {
case V_14 :
if ( F_25 ( V_2 ) )
V_4 = F_18 ( V_2 ) ;
else
V_4 = F_18 ( V_2 ) << 24 ;
break;
case V_171 :
F_76 ( L_16 ) ;
break;
case V_172 :
if ( F_44 ( V_2 ) )
return 0 ;
V_4 = F_109 ( V_2 ) ;
break;
case V_100 :
F_82 ( V_2 ) ;
V_4 = F_19 ( V_2 , V_169 ) ;
break;
case V_101 :
F_117 ( V_2 , false ) ;
default:
V_4 = F_19 ( V_2 , V_169 ) ;
break;
}
return V_4 ;
}
static inline struct V_1 * F_119 ( struct V_173 * V_174 )
{
return F_120 ( V_174 , struct V_1 , V_174 ) ;
}
static int F_121 ( struct V_1 * V_2 , T_1 V_169 , int V_175 ,
void * V_86 )
{
unsigned char V_176 = V_169 & 0xf ;
T_1 V_71 ;
static const T_6 V_177 = 0x43ff01ffffffe70cULL ;
if ( ( V_176 + V_175 ) > 4 ) {
F_76 ( L_17 ,
V_169 , V_175 ) ;
return 1 ;
}
if ( V_169 > 0x3f0 || ! ( V_177 & ( 1ULL << ( V_169 >> 4 ) ) ) ) {
F_76 ( L_18 ,
V_169 ) ;
return 1 ;
}
V_71 = F_118 ( V_2 , V_169 & ~ 0xf ) ;
F_122 ( V_169 , V_71 ) ;
switch ( V_175 ) {
case 1 :
case 2 :
case 4 :
memcpy ( V_86 , ( char * ) & V_71 + V_176 , V_175 ) ;
break;
default:
F_98 ( V_138 L_19
L_20 , V_175 ) ;
break;
}
return 0 ;
}
static int F_123 ( struct V_1 * V_2 , T_7 V_178 )
{
return F_17 ( V_2 ) &&
V_178 >= V_2 -> V_179 &&
V_178 < V_2 -> V_179 + V_170 ;
}
static int F_124 ( struct V_173 * V_180 ,
T_7 V_181 , int V_175 , void * V_86 )
{
struct V_1 * V_2 = F_119 ( V_180 ) ;
T_1 V_169 = V_181 - V_2 -> V_179 ;
if ( ! F_123 ( V_2 , V_181 ) )
return - V_182 ;
F_121 ( V_2 , V_169 , V_175 , V_86 ) ;
return 0 ;
}
static void F_125 ( struct V_1 * V_2 )
{
T_1 V_183 , V_184 , V_185 ;
V_185 = F_19 ( V_2 , V_186 ) ;
V_183 = V_185 & 0xf ;
V_184 = ( ( V_183 & 0x3 ) | ( ( V_183 & 0x8 ) >> 1 ) ) + 1 ;
V_2 -> V_160 = 0x1 << ( V_184 & 0x7 ) ;
F_76 ( L_21 ,
V_2 -> V_160 ) ;
}
static void F_126 ( struct V_1 * V_2 )
{
T_4 V_187 ;
F_127 ( & V_2 -> V_48 . V_188 , 0 ) ;
if ( F_43 ( V_2 ) || F_42 ( V_2 ) ) {
V_187 = V_2 -> V_48 . V_158 . V_189 -> V_190 () ;
V_2 -> V_48 . V_157 = ( T_6 ) F_19 ( V_2 , V_156 )
* V_159 * V_2 -> V_160 ;
if ( ! V_2 -> V_48 . V_157 )
return;
if ( F_43 ( V_2 ) ) {
T_5 V_191 = V_192 * 1000LL ;
if ( V_2 -> V_48 . V_157 < V_191 ) {
F_128 (
L_22
L_23 ,
V_2 -> V_9 -> V_106 ,
V_2 -> V_48 . V_157 , V_191 ) ;
V_2 -> V_48 . V_157 = V_191 ;
}
}
F_129 ( & V_2 -> V_48 . V_158 ,
F_130 ( V_187 , V_2 -> V_48 . V_157 ) ,
V_193 ) ;
F_76 ( L_24 V_194 L_25
V_195 L_26
L_27
L_28 V_195 L_29 , V_196 ,
V_159 , F_111 ( V_187 ) ,
F_19 ( V_2 , V_156 ) ,
V_2 -> V_48 . V_157 ,
F_111 ( F_130 ( V_187 ,
V_2 -> V_48 . V_157 ) ) ) ;
} else if ( F_44 ( V_2 ) ) {
T_6 V_197 , V_198 = V_2 -> V_48 . V_198 ;
T_6 V_154 = 0 ;
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned long V_199 = V_9 -> V_11 . V_200 ;
unsigned long V_201 ;
if ( F_59 ( ! V_198 || ! V_199 ) )
return;
F_131 ( V_201 ) ;
V_187 = V_2 -> V_48 . V_158 . V_189 -> V_190 () ;
V_197 = V_72 -> V_202 ( V_9 , F_132 () ) ;
if ( F_65 ( V_198 > V_197 ) ) {
V_154 = ( V_198 - V_197 ) * 1000000ULL ;
F_133 ( V_154 , V_199 ) ;
}
F_129 ( & V_2 -> V_48 . V_158 ,
F_130 ( V_187 , V_154 ) , V_193 ) ;
F_134 ( V_201 ) ;
}
}
static void F_135 ( struct V_1 * V_2 , T_1 V_203 )
{
int V_204 = F_45 ( F_19 ( V_2 , V_205 ) ) ;
if ( F_45 ( V_203 ) ) {
if ( ! V_204 ) {
F_76 ( L_30
L_31 , V_2 -> V_9 -> V_106 ) ;
V_2 -> V_9 -> V_15 -> V_11 . V_206 ++ ;
}
} else if ( V_204 )
V_2 -> V_9 -> V_15 -> V_11 . V_206 -- ;
}
static int F_136 ( struct V_1 * V_2 , T_1 V_64 , T_1 V_4 )
{
int V_119 = 0 ;
F_137 ( V_64 , V_4 ) ;
switch ( V_64 ) {
case V_14 :
if ( ! F_25 ( V_2 ) )
F_38 ( V_2 , V_4 >> 24 ) ;
else
V_119 = 1 ;
break;
case V_101 :
F_117 ( V_2 , true ) ;
F_83 ( V_2 , V_4 & 0xff ) ;
break;
case V_207 :
F_102 ( V_2 ) ;
break;
case V_34 :
if ( ! F_25 ( V_2 ) )
F_39 ( V_2 , V_4 & V_208 ) ;
else
V_119 = 1 ;
break;
case V_31 :
if ( ! F_25 ( V_2 ) ) {
F_1 ( V_2 , V_31 , V_4 | 0x0FFFFFFF ) ;
F_20 ( V_2 -> V_9 -> V_15 ) ;
} else
V_119 = 1 ;
break;
case V_39 : {
T_1 V_209 = 0x3ff ;
if ( F_19 ( V_2 , V_63 ) & V_62 )
V_209 |= V_141 ;
F_35 ( V_2 , V_4 & V_209 ) ;
if ( ! ( V_4 & V_40 ) ) {
int V_19 ;
T_1 V_53 ;
for ( V_19 = 0 ; V_19 < V_210 ; V_19 ++ ) {
V_53 = F_19 ( V_2 ,
V_47 + 0x10 * V_19 ) ;
F_1 ( V_2 , V_47 + 0x10 * V_19 ,
V_53 | V_45 ) ;
}
F_127 ( & V_2 -> V_48 . V_188 , 0 ) ;
}
break;
}
case V_146 :
F_1 ( V_2 , V_146 , V_4 & ~ ( 1 << 12 ) ) ;
F_105 ( V_2 ) ;
break;
case V_148 :
if ( ! F_25 ( V_2 ) )
V_4 &= 0xff000000 ;
F_1 ( V_2 , V_148 , V_4 ) ;
break;
case V_205 :
F_135 ( V_2 , V_4 ) ;
case V_211 :
case V_212 :
case V_213 :
case V_214 :
if ( ! F_16 ( V_2 ) )
V_4 |= V_45 ;
V_4 &= V_215 [ ( V_64 - V_47 ) >> 4 ] ;
F_1 ( V_2 , V_64 , V_4 ) ;
break;
case V_47 :
if ( ( F_19 ( V_2 , V_47 ) &
V_2 -> V_48 . V_49 ) !=
( V_4 & V_2 -> V_48 . V_49 ) )
F_138 ( & V_2 -> V_48 . V_158 ) ;
if ( ! F_16 ( V_2 ) )
V_4 |= V_45 ;
V_4 &= ( V_215 [ 0 ] | V_2 -> V_48 . V_49 ) ;
F_1 ( V_2 , V_47 , V_4 ) ;
break;
case V_156 :
if ( F_44 ( V_2 ) )
break;
F_138 ( & V_2 -> V_48 . V_158 ) ;
F_1 ( V_2 , V_156 , V_4 ) ;
F_126 ( V_2 ) ;
break;
case V_186 :
if ( V_4 & 4 )
F_76 ( L_32 , V_4 ) ;
F_1 ( V_2 , V_186 , V_4 ) ;
F_125 ( V_2 ) ;
break;
case V_216 :
if ( F_25 ( V_2 ) && V_4 != 0 ) {
F_76 ( L_33 , V_4 ) ;
V_119 = 1 ;
}
break;
case V_217 :
if ( F_25 ( V_2 ) ) {
F_136 ( V_2 , V_146 , 0x40000 | ( V_4 & 0xff ) ) ;
} else
V_119 = 1 ;
break;
default:
V_119 = 1 ;
break;
}
if ( V_119 )
F_76 ( L_34 , V_64 ) ;
return V_119 ;
}
static int F_139 ( struct V_173 * V_180 ,
T_7 V_181 , int V_175 , const void * V_86 )
{
struct V_1 * V_2 = F_119 ( V_180 ) ;
unsigned int V_169 = V_181 - V_2 -> V_179 ;
T_1 V_4 ;
if ( ! F_123 ( V_2 , V_181 ) )
return - V_182 ;
if ( V_175 != 4 || ( V_169 & 0xf ) ) {
F_76 ( L_35 , V_175 , ( long ) V_181 ) ;
return 0 ;
}
V_4 = * ( T_1 * ) V_86 ;
if ( V_169 != V_207 )
F_76 ( L_36
L_37 , V_196 , V_169 , V_175 , V_4 ) ;
F_136 ( V_2 , V_169 & 0xff0 , V_4 ) ;
return 0 ;
}
void F_140 ( struct V_8 * V_9 )
{
if ( F_47 ( V_9 ) )
F_136 ( V_9 -> V_11 . V_2 , V_207 , 0 ) ;
}
void F_141 ( struct V_8 * V_9 , T_1 V_169 )
{
T_1 V_4 = 0 ;
V_169 &= 0xff0 ;
F_121 ( V_9 -> V_11 . V_2 , V_169 , 4 , & V_4 ) ;
F_136 ( V_9 -> V_11 . V_2 , V_169 , V_4 ) ;
}
void F_142 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! V_9 -> V_11 . V_2 )
return;
F_138 ( & V_2 -> V_48 . V_158 ) ;
if ( ! ( V_9 -> V_11 . V_218 & V_219 ) )
F_36 ( & V_220 ) ;
if ( ! ( F_19 ( V_2 , V_39 ) & V_40 ) )
F_36 ( & V_41 ) ;
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
return V_2 -> V_48 . V_198 ;
}
void F_146 ( struct V_8 * V_9 , T_6 V_86 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_47 ( V_9 ) || F_42 ( V_2 ) ||
F_43 ( V_2 ) )
return;
F_138 ( & V_2 -> V_48 . V_158 ) ;
if ( F_147 ( V_9 ) )
F_148 ( V_9 ) ;
V_2 -> V_48 . V_198 = V_86 ;
F_126 ( V_2 ) ;
}
void F_149 ( struct V_8 * V_9 , unsigned long V_221 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_47 ( V_9 ) )
return;
F_83 ( V_2 , ( ( V_221 & 0x0f ) << 4 )
| ( F_19 ( V_2 , V_101 ) & 4 ) ) ;
}
T_6 F_150 ( struct V_8 * V_9 )
{
T_6 V_95 ;
if ( ! F_47 ( V_9 ) )
return 0 ;
V_95 = ( T_6 ) F_19 ( V_9 -> V_11 . V_2 , V_101 ) ;
return ( V_95 & 0xf0 ) >> 4 ;
}
void F_151 ( struct V_8 * V_9 , T_6 V_222 )
{
T_6 V_223 = V_9 -> V_11 . V_218 ;
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! V_2 ) {
V_222 |= V_224 ;
V_9 -> V_11 . V_218 = V_222 ;
return;
}
if ( ! F_152 ( V_2 -> V_9 ) )
V_222 &= ~ V_224 ;
V_9 -> V_11 . V_218 = V_222 ;
if ( ( V_223 ^ V_222 ) & V_219 ) {
if ( V_222 & V_219 )
F_36 ( & V_220 ) ;
else
F_37 ( & V_220 . V_42 ) ;
F_20 ( V_9 -> V_15 ) ;
}
if ( ( V_223 ^ V_222 ) & V_225 ) {
if ( V_222 & V_225 ) {
T_1 V_43 = F_18 ( V_2 ) ;
T_1 V_29 = ( ( V_43 >> 4 ) << 16 ) | ( 1 << ( V_43 & 0xf ) ) ;
F_39 ( V_2 , V_29 ) ;
V_72 -> V_226 ( V_9 , true ) ;
} else
V_72 -> V_226 ( V_9 , false ) ;
}
V_2 -> V_179 = V_2 -> V_9 -> V_11 . V_218 &
V_227 ;
F_76 ( L_38 V_195 L_39
L_40 , V_2 -> V_9 -> V_11 . V_218 , V_2 -> V_179 ) ;
}
void F_153 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
int V_19 ;
F_76 ( L_41 , V_196 ) ;
ASSERT ( V_9 ) ;
V_2 = V_9 -> V_11 . V_2 ;
ASSERT ( V_2 != NULL ) ;
F_138 ( & V_2 -> V_48 . V_158 ) ;
F_38 ( V_2 , V_9 -> V_106 ) ;
F_46 ( V_2 -> V_9 ) ;
for ( V_19 = 0 ; V_19 < V_210 ; V_19 ++ )
F_1 ( V_2 , V_47 + 0x10 * V_19 , V_45 ) ;
F_1 ( V_2 , V_205 ,
F_154 ( 0 , V_228 ) ) ;
F_1 ( V_2 , V_31 , 0xffffffffU ) ;
F_35 ( V_2 , 0xff ) ;
F_1 ( V_2 , V_101 , 0 ) ;
F_39 ( V_2 , 0 ) ;
F_1 ( V_2 , V_216 , 0 ) ;
F_1 ( V_2 , V_146 , 0 ) ;
F_1 ( V_2 , V_148 , 0 ) ;
F_1 ( V_2 , V_186 , 0 ) ;
F_1 ( V_2 , V_156 , 0 ) ;
for ( V_19 = 0 ; V_19 < 8 ; V_19 ++ ) {
F_1 ( V_2 , V_13 + 0x10 * V_19 , 0 ) ;
F_1 ( V_2 , V_12 + 0x10 * V_19 , 0 ) ;
F_1 ( V_2 , V_94 + 0x10 * V_19 , 0 ) ;
}
V_2 -> V_70 = F_60 ( V_9 -> V_15 ) ;
V_2 -> V_76 = F_60 ( V_9 -> V_15 ) ;
V_2 -> V_77 = - 1 ;
F_125 ( V_2 ) ;
F_127 ( & V_2 -> V_48 . V_188 , 0 ) ;
if ( F_152 ( V_9 ) )
F_151 ( V_9 ,
V_9 -> V_11 . V_218 | V_224 ) ;
V_9 -> V_11 . V_85 . V_87 = 0 ;
F_82 ( V_2 ) ;
V_9 -> V_11 . V_124 = 0 ;
V_9 -> V_11 . V_91 = 0 ;
F_76 ( L_42
L_43 V_195 L_44 , V_196 ,
V_9 , F_18 ( V_2 ) ,
V_9 -> V_11 . V_218 , V_2 -> V_179 ) ;
}
static bool F_155 ( struct V_1 * V_2 )
{
return F_43 ( V_2 ) ;
}
int F_147 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( F_47 ( V_9 ) && F_15 ( V_2 ) &&
F_40 ( V_2 , V_47 ) )
return F_156 ( & V_2 -> V_48 . V_188 ) ;
return 0 ;
}
int F_157 ( struct V_1 * V_2 , int V_44 )
{
T_1 V_64 = F_19 ( V_2 , V_44 ) ;
int V_10 , V_229 , V_84 ;
if ( F_17 ( V_2 ) && ! ( V_64 & V_45 ) ) {
V_10 = V_64 & V_46 ;
V_229 = V_64 & V_54 ;
V_84 = V_64 & V_230 ;
return F_69 ( V_2 , V_229 , V_10 , 1 , V_84 ,
NULL ) ;
}
return 0 ;
}
void F_158 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( V_2 )
F_157 ( V_2 , V_205 ) ;
}
static enum V_231 F_159 ( struct V_232 * V_86 )
{
struct V_233 * V_234 = F_120 ( V_86 , struct V_233 , V_158 ) ;
struct V_1 * V_2 = F_120 ( V_234 , struct V_1 , V_48 ) ;
struct V_8 * V_9 = V_2 -> V_9 ;
T_8 * V_235 = & V_9 -> V_236 ;
if ( ! F_156 ( & V_234 -> V_188 ) ) {
F_160 ( & V_234 -> V_188 ) ;
F_61 ( V_237 , V_9 ) ;
}
if ( F_161 ( V_235 ) )
F_162 ( V_235 ) ;
if ( F_155 ( V_2 ) ) {
F_163 ( & V_234 -> V_158 , V_234 -> V_157 ) ;
return V_238 ;
} else
return V_239 ;
}
int F_164 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
ASSERT ( V_9 != NULL ) ;
F_76 ( L_45 , V_9 -> V_106 ) ;
V_2 = F_21 ( sizeof( * V_2 ) , V_20 ) ;
if ( ! V_2 )
goto V_240;
V_9 -> V_11 . V_2 = V_2 ;
V_2 -> V_5 = ( void * ) F_165 ( V_20 ) ;
if ( ! V_2 -> V_5 ) {
F_98 ( V_138 L_46 ,
V_9 -> V_106 ) ;
goto V_241;
}
V_2 -> V_9 = V_9 ;
F_166 ( & V_2 -> V_48 . V_158 , V_242 ,
V_193 ) ;
V_2 -> V_48 . V_158 . V_243 = F_159 ;
V_9 -> V_11 . V_218 = V_219 ;
F_151 ( V_9 ,
V_244 | V_219 ) ;
F_37 ( & V_41 . V_42 ) ;
F_153 ( V_9 ) ;
F_167 ( & V_2 -> V_174 , & V_245 ) ;
return 0 ;
V_241:
F_144 ( V_2 ) ;
V_240:
return - V_246 ;
}
int F_168 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
int V_78 ;
if ( ! F_47 ( V_9 ) || ! F_15 ( V_2 ) )
return - 1 ;
F_82 ( V_2 ) ;
V_78 = F_57 ( V_2 ) ;
if ( ( V_78 == - 1 ) ||
( ( V_78 & 0xF0 ) <= F_19 ( V_2 , V_100 ) ) )
return - 1 ;
return V_78 ;
}
int F_169 ( struct V_8 * V_9 )
{
T_1 V_247 = F_19 ( V_9 -> V_11 . V_2 , V_205 ) ;
int V_116 = 0 ;
if ( ! F_17 ( V_9 -> V_11 . V_2 ) )
V_116 = 1 ;
if ( ( V_247 & V_45 ) == 0 &&
F_170 ( V_247 ) == V_228 )
V_116 = 1 ;
return V_116 ;
}
void F_148 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_47 ( V_9 ) )
return;
if ( F_156 ( & V_2 -> V_48 . V_188 ) > 0 ) {
F_157 ( V_2 , V_47 ) ;
if ( F_44 ( V_2 ) )
V_2 -> V_48 . V_198 = 0 ;
F_127 ( & V_2 -> V_48 . V_188 , 0 ) ;
}
}
int F_171 ( struct V_8 * V_9 )
{
int V_10 = F_168 ( V_9 ) ;
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( V_10 == - 1 )
return - 1 ;
F_62 ( V_10 , V_2 ) ;
F_82 ( V_2 ) ;
F_58 ( V_10 , V_2 ) ;
return V_10 ;
}
void F_172 ( struct V_8 * V_9 ,
struct V_248 * V_249 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
F_151 ( V_9 , V_9 -> V_11 . V_218 ) ;
F_35 ( V_2 , * ( ( T_1 * ) ( V_249 -> V_5 + V_39 ) ) ) ;
memcpy ( V_9 -> V_11 . V_2 -> V_5 , V_249 -> V_5 , sizeof *V_249 ) ;
F_38 ( V_2 , F_18 ( V_2 ) ) ;
F_46 ( V_9 ) ;
F_82 ( V_2 ) ;
F_138 ( & V_2 -> V_48 . V_158 ) ;
F_125 ( V_2 ) ;
F_126 ( V_2 ) ;
V_2 -> V_70 = true ;
V_2 -> V_76 = F_60 ( V_9 -> V_15 ) ?
1 : F_51 ( V_2 -> V_5 + V_12 ) ;
V_2 -> V_77 = - 1 ;
V_72 -> V_75 ( V_9 -> V_15 , F_64 ( V_2 ) ) ;
F_61 ( V_74 , V_9 ) ;
F_173 ( V_9 ) ;
}
void F_174 ( struct V_8 * V_9 )
{
struct V_232 * V_158 ;
if ( ! F_47 ( V_9 ) )
return;
V_158 = & V_9 -> V_11 . V_2 -> V_48 . V_158 ;
if ( F_138 ( V_158 ) )
F_175 ( V_158 , V_193 ) ;
}
static void F_176 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
bool V_188 ;
int V_10 ;
F_63 ( ! F_74 ( V_9 ) ) ;
V_188 = F_75 ( V_9 ) ;
F_79 ( V_9 ) ;
if ( V_188 )
return;
V_10 = F_102 ( V_2 ) ;
F_177 ( V_2 , V_10 ) ;
}
void F_178 ( struct V_8 * V_9 )
{
T_1 V_86 ;
if ( F_3 ( V_90 , & V_9 -> V_11 . V_91 ) )
F_176 ( V_9 , V_9 -> V_11 . V_2 ) ;
if ( ! F_3 ( V_250 , & V_9 -> V_11 . V_91 ) )
return;
F_73 ( V_9 -> V_15 , & V_9 -> V_11 . V_2 -> V_251 , & V_86 ,
sizeof( T_1 ) ) ;
F_83 ( V_9 -> V_11 . V_2 , V_86 & 0xff ) ;
}
static void F_179 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
if ( ! F_74 ( V_9 ) ||
V_2 -> V_70 ||
V_2 -> V_77 == - 1 ||
F_100 ( V_9 -> V_15 , V_2 -> V_77 ) ) {
return;
}
F_77 ( V_2 -> V_9 ) ;
}
void F_180 ( struct V_8 * V_9 )
{
T_1 V_86 , V_95 ;
int V_252 , V_253 ;
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
F_179 ( V_9 , V_2 ) ;
if ( ! F_3 ( V_250 , & V_9 -> V_11 . V_91 ) )
return;
V_95 = F_19 ( V_2 , V_101 ) & 0xff ;
V_252 = F_57 ( V_2 ) ;
if ( V_252 < 0 )
V_252 = 0 ;
V_253 = F_64 ( V_2 ) ;
if ( V_253 < 0 )
V_253 = 0 ;
V_86 = ( V_95 & 0xff ) | ( ( V_253 & 0xf0 ) << 8 ) | ( V_252 << 24 ) ;
F_71 ( V_9 -> V_15 , & V_9 -> V_11 . V_2 -> V_251 , & V_86 ,
sizeof( T_1 ) ) ;
}
int F_181 ( struct V_8 * V_9 , T_7 V_254 )
{
if ( V_254 ) {
if ( F_182 ( V_9 -> V_15 ,
& V_9 -> V_11 . V_2 -> V_251 ,
V_254 , sizeof( T_1 ) ) )
return - V_255 ;
F_78 ( V_250 , & V_9 -> V_11 . V_91 ) ;
} else {
F_80 ( V_250 , & V_9 -> V_11 . V_91 ) ;
}
V_9 -> V_11 . V_2 -> V_254 = V_254 ;
return 0 ;
}
int F_183 ( struct V_8 * V_9 , T_1 V_256 , T_6 V_86 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_1 V_64 = ( V_256 - V_257 ) << 4 ;
if ( ! F_184 ( V_9 -> V_15 ) || ! F_25 ( V_2 ) )
return 1 ;
if ( V_256 == 0x830 )
F_136 ( V_2 , V_148 , ( T_1 ) ( V_86 >> 32 ) ) ;
return F_136 ( V_2 , V_64 , ( T_1 ) V_86 ) ;
}
int F_185 ( struct V_8 * V_9 , T_1 V_256 , T_6 * V_86 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_1 V_64 = ( V_256 - V_257 ) << 4 , V_258 , V_259 = 0 ;
if ( ! F_184 ( V_9 -> V_15 ) || ! F_25 ( V_2 ) )
return 1 ;
if ( F_121 ( V_2 , V_64 , 4 , & V_258 ) )
return 1 ;
if ( V_256 == 0x830 )
F_121 ( V_2 , V_148 , 4 , & V_259 ) ;
* V_86 = ( ( ( T_6 ) V_259 ) << 32 ) | V_258 ;
return 0 ;
}
int F_186 ( struct V_8 * V_9 , T_1 V_64 , T_6 V_86 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_47 ( V_9 ) )
return 1 ;
if ( V_64 == V_146 )
F_136 ( V_2 , V_148 , ( T_1 ) ( V_86 >> 32 ) ) ;
return F_136 ( V_2 , V_64 , ( T_1 ) V_86 ) ;
}
int F_187 ( struct V_8 * V_9 , T_1 V_64 , T_6 * V_86 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_1 V_258 , V_259 = 0 ;
if ( ! F_47 ( V_9 ) )
return 1 ;
if ( F_121 ( V_2 , V_64 , 4 , & V_258 ) )
return 1 ;
if ( V_64 == V_146 )
F_121 ( V_2 , V_148 , 4 , & V_259 ) ;
* V_86 = ( ( ( T_6 ) V_259 ) << 32 ) | V_258 ;
return 0 ;
}
int F_188 ( struct V_8 * V_9 , T_6 V_86 )
{
T_6 V_178 = V_86 & ~ V_88 ;
if ( ! F_189 ( V_178 , 4 ) )
return 1 ;
V_9 -> V_11 . V_85 . V_87 = V_86 ;
if ( ! F_74 ( V_9 ) )
return 0 ;
return F_182 ( V_9 -> V_15 , & V_9 -> V_11 . V_85 . V_86 ,
V_178 , sizeof( T_3 ) ) ;
}
void F_190 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
unsigned int V_135 ;
unsigned long V_260 ;
if ( ! F_47 ( V_9 ) || ! V_2 -> V_132 )
return;
V_260 = F_54 ( & V_2 -> V_132 , 0 ) ;
if ( F_3 ( V_133 , & V_260 ) ) {
F_153 ( V_9 ) ;
F_191 ( V_9 ) ;
if ( F_152 ( V_2 -> V_9 ) )
V_9 -> V_11 . V_261 = V_262 ;
else
V_9 -> V_11 . V_261 = V_263 ;
}
if ( F_3 ( V_136 , & V_260 ) &&
V_9 -> V_11 . V_261 == V_263 ) {
F_192 () ;
V_135 = V_2 -> V_135 ;
F_76 ( L_47 ,
V_9 -> V_106 , V_135 ) ;
F_193 ( V_9 , V_135 ) ;
V_9 -> V_11 . V_261 = V_262 ;
}
}
void F_194 ( void )
{
F_195 ( & V_220 , V_264 ) ;
F_195 ( & V_41 , V_264 ) ;
}
