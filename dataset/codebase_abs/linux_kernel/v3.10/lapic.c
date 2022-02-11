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
bool F_10 ( struct V_8 * V_9 , int V_10 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
return F_8 ( V_10 , V_2 -> V_5 + V_12 ) ||
F_8 ( V_10 , V_2 -> V_5 + V_13 ) ;
}
static inline void F_11 ( int V_6 , void * V_7 )
{
F_12 ( F_4 ( V_6 ) , ( V_7 ) + F_5 ( V_6 ) ) ;
}
static inline void F_13 ( int V_6 , void * V_7 )
{
F_14 ( F_4 ( V_6 ) , ( V_7 ) + F_5 ( V_6 ) ) ;
}
static inline int F_15 ( int V_6 , void * V_7 )
{
return F_16 ( F_4 ( V_6 ) , ( V_7 ) + F_5 ( V_6 ) ) ;
}
static inline int F_17 ( int V_6 , void * V_7 )
{
return F_18 ( F_4 ( V_6 ) , ( V_7 ) + F_5 ( V_6 ) ) ;
}
static inline void F_19 ( struct V_1 * V_2 , T_1 V_4 )
{
if ( ( F_20 ( V_2 , V_14 ) ^ V_4 ) & V_15 ) {
if ( V_4 & V_15 )
F_21 ( & V_16 ) ;
else
F_22 ( & V_16 . V_17 ) ;
}
F_1 ( V_2 , V_14 , V_4 ) ;
}
static inline int F_23 ( struct V_1 * V_2 )
{
return F_24 ( V_2 ) && F_25 ( V_2 ) ;
}
static inline int F_26 ( struct V_1 * V_2 )
{
return ( F_20 ( V_2 , V_18 ) >> 24 ) & 0xff ;
}
static void F_27 ( struct V_19 * V_19 )
{
struct V_20 * V_21 , * V_22 = NULL ;
struct V_8 * V_9 ;
int V_23 ;
V_21 = F_28 ( sizeof( struct V_20 ) , V_24 ) ;
F_29 ( & V_19 -> V_11 . V_25 ) ;
if ( ! V_21 )
goto V_26;
V_21 -> V_27 = 8 ;
V_21 -> V_28 = 8 ;
V_21 -> V_29 = 0 ;
V_21 -> V_30 = 0xff ;
F_30 (i, vcpu, kvm) {
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_2 V_31 , V_32 ;
T_1 V_33 ;
if ( ! F_31 ( V_9 ) )
continue;
if ( F_32 ( V_2 ) ) {
V_21 -> V_27 = 32 ;
V_21 -> V_28 = 16 ;
V_21 -> V_29 = V_21 -> V_30 = 0xffff ;
} else if ( F_24 ( V_2 ) &&
! V_21 -> V_29 &&
F_20 ( V_2 , V_34 ) == V_35 ) {
V_21 -> V_28 = 4 ;
V_21 -> V_29 = 0xf ;
V_21 -> V_30 = 0xf ;
}
V_21 -> V_36 [ F_26 ( V_2 ) ] = V_2 ;
V_33 = F_20 ( V_2 , V_37 ) ;
V_31 = F_33 ( V_21 , V_33 ) ;
V_32 = F_34 ( V_21 , V_33 ) ;
if ( V_32 )
V_21 -> V_38 [ V_31 ] [ F_35 ( V_32 ) - 1 ] = V_2 ;
}
V_26:
V_22 = F_36 ( V_19 -> V_11 . V_39 ,
F_37 ( & V_19 -> V_11 . V_25 ) ) ;
F_38 ( V_19 -> V_11 . V_39 , V_21 ) ;
F_39 ( & V_19 -> V_11 . V_25 ) ;
if ( V_22 )
F_40 ( V_22 , V_40 ) ;
F_41 ( V_19 ) ;
}
static inline void F_42 ( struct V_1 * V_2 , T_3 V_41 )
{
F_1 ( V_2 , V_18 , V_41 << 24 ) ;
F_27 ( V_2 -> V_9 -> V_19 ) ;
}
static inline void F_43 ( struct V_1 * V_2 , T_1 V_41 )
{
F_1 ( V_2 , V_37 , V_41 ) ;
F_27 ( V_2 -> V_9 -> V_19 ) ;
}
static inline int F_44 ( struct V_1 * V_2 , int V_42 )
{
return ! ( F_20 ( V_2 , V_42 ) & V_43 ) ;
}
static inline int F_45 ( struct V_1 * V_2 , int V_42 )
{
return F_20 ( V_2 , V_42 ) & V_44 ;
}
static inline int F_46 ( struct V_1 * V_2 )
{
return ( ( F_20 ( V_2 , V_45 ) &
V_2 -> V_46 . V_47 ) == V_48 ) ;
}
static inline int F_47 ( struct V_1 * V_2 )
{
return ( ( F_20 ( V_2 , V_45 ) &
V_2 -> V_46 . V_47 ) == V_49 ) ;
}
static inline int F_48 ( struct V_1 * V_2 )
{
return ( ( F_20 ( V_2 , V_45 ) &
V_2 -> V_46 . V_47 ) ==
V_50 ) ;
}
static inline int F_49 ( T_1 V_51 )
{
return ( V_51 & ( V_52 | V_43 ) ) == V_53 ;
}
void F_50 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
struct V_54 * V_55 ;
T_1 V_56 = V_57 ;
if ( ! F_51 ( V_9 ) )
return;
V_55 = F_52 ( V_2 -> V_9 , 0x1 , 0 ) ;
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
void F_57 ( struct V_8 * V_9 , T_1 * V_66 )
{
T_1 V_23 , V_67 ;
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
for ( V_23 = 0 ; V_23 <= 7 ; V_23 ++ ) {
V_67 = F_58 ( & V_66 [ V_23 ] , 0 ) ;
if ( V_67 )
* ( ( T_1 * ) ( V_2 -> V_5 + V_13 + V_23 * 0x10 ) ) |= V_67 ;
}
}
static inline int F_59 ( int V_6 , struct V_1 * V_2 )
{
V_2 -> V_68 = true ;
return F_2 ( V_6 , V_2 -> V_5 + V_13 ) ;
}
static inline int F_60 ( struct V_1 * V_2 )
{
return F_53 ( V_2 -> V_5 + V_13 ) ;
}
static inline int F_61 ( struct V_1 * V_2 )
{
int V_69 ;
if ( ! V_2 -> V_68 )
return - 1 ;
V_70 -> V_71 ( V_2 -> V_9 ) ;
V_69 = F_60 ( V_2 ) ;
ASSERT ( V_69 == - 1 || V_69 >= 16 ) ;
return V_69 ;
}
static inline void F_62 ( int V_6 , struct V_1 * V_2 )
{
V_2 -> V_68 = false ;
F_13 ( V_6 , V_2 -> V_5 + V_13 ) ;
if ( F_60 ( V_2 ) != - 1 )
V_2 -> V_68 = true ;
}
static inline void F_63 ( int V_6 , struct V_1 * V_2 )
{
if ( ! F_15 ( V_6 , V_2 -> V_5 + V_12 ) )
++ V_2 -> V_72 ;
F_64 ( V_2 -> V_72 > V_63 ) ;
V_2 -> V_73 = V_6 ;
}
static inline void F_65 ( int V_6 , struct V_1 * V_2 )
{
if ( F_17 ( V_6 , V_2 -> V_5 + V_12 ) )
-- V_2 -> V_72 ;
F_64 ( V_2 -> V_72 < 0 ) ;
V_2 -> V_73 = - 1 ;
}
int F_66 ( struct V_8 * V_9 )
{
int V_74 ;
if ( ! F_51 ( V_9 ) )
return 0 ;
V_74 = F_61 ( V_9 -> V_11 . V_2 ) ;
return V_74 ;
}
int F_67 ( struct V_8 * V_9 , struct V_75 * V_76 ,
unsigned long * V_77 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
return F_68 ( V_2 , V_76 -> V_78 , V_76 -> V_10 ,
V_76 -> V_79 , V_76 -> V_80 , V_77 ) ;
}
static int F_69 ( struct V_8 * V_9 , T_3 V_4 )
{
return F_70 ( V_9 -> V_19 , & V_9 -> V_11 . V_81 . V_82 , & V_4 ,
sizeof( V_4 ) ) ;
}
static int F_71 ( struct V_8 * V_9 , T_3 * V_4 )
{
return F_72 ( V_9 -> V_19 , & V_9 -> V_11 . V_81 . V_82 , V_4 ,
sizeof( * V_4 ) ) ;
}
static inline bool F_73 ( struct V_8 * V_9 )
{
return V_9 -> V_11 . V_81 . V_83 & V_84 ;
}
static bool F_74 ( struct V_8 * V_9 )
{
T_3 V_4 ;
if ( F_71 ( V_9 , & V_4 ) < 0 )
F_75 ( L_1 ,
( unsigned long long ) V_85 -> V_11 . V_81 . V_83 ) ;
return V_4 & 0x1 ;
}
static void F_76 ( struct V_8 * V_9 )
{
if ( F_69 ( V_9 , V_86 ) < 0 ) {
F_75 ( L_2 ,
( unsigned long long ) V_85 -> V_11 . V_81 . V_83 ) ;
return;
}
F_77 ( V_87 , & V_9 -> V_11 . V_88 ) ;
}
static void F_78 ( struct V_8 * V_9 )
{
if ( F_69 ( V_9 , V_89 ) < 0 ) {
F_75 ( L_3 ,
( unsigned long long ) V_85 -> V_11 . V_81 . V_83 ) ;
return;
}
F_79 ( V_87 , & V_9 -> V_11 . V_88 ) ;
}
static inline int F_80 ( struct V_1 * V_2 )
{
int V_69 ;
if ( ! V_2 -> V_72 )
return - 1 ;
if ( F_81 ( V_2 -> V_73 != - 1 ) )
return V_2 -> V_73 ;
V_69 = F_53 ( V_2 -> V_5 + V_12 ) ;
ASSERT ( V_69 == - 1 || V_69 >= 16 ) ;
return V_69 ;
}
void F_82 ( struct V_8 * V_9 , T_1 * V_90 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < 8 ; V_23 ++ )
F_1 ( V_2 , V_91 + 0x10 * V_23 , V_90 [ V_23 ] ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
T_1 V_92 , V_93 , V_94 , V_95 ;
int V_96 ;
V_95 = F_20 ( V_2 , V_97 ) ;
V_92 = F_20 ( V_2 , V_98 ) ;
V_96 = F_80 ( V_2 ) ;
V_93 = ( V_96 != - 1 ) ? V_96 : 0 ;
if ( ( V_92 & 0xf0 ) >= ( V_93 & 0xf0 ) )
V_94 = V_92 & 0xff ;
else
V_94 = V_93 & 0xf0 ;
F_75 ( L_4 ,
V_2 , V_94 , V_96 , V_93 ) ;
if ( V_95 != V_94 ) {
F_1 ( V_2 , V_97 , V_94 ) ;
if ( V_94 < V_95 )
F_84 ( V_99 , V_2 -> V_9 ) ;
}
}
static void F_85 ( struct V_1 * V_2 , T_1 V_92 )
{
F_1 ( V_2 , V_98 , V_92 ) ;
F_83 ( V_2 ) ;
}
int F_86 ( struct V_1 * V_2 , T_2 V_100 )
{
return V_100 == 0xff || F_26 ( V_2 ) == V_100 ;
}
int F_87 ( struct V_1 * V_2 , T_3 V_101 )
{
int V_69 = 0 ;
T_1 V_102 ;
if ( F_32 ( V_2 ) ) {
V_102 = F_20 ( V_2 , V_37 ) ;
return V_102 & V_101 ;
}
V_102 = F_88 ( F_20 ( V_2 , V_37 ) ) ;
switch ( F_20 ( V_2 , V_34 ) ) {
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
F_75 ( L_5 ,
V_2 -> V_9 -> V_104 , F_20 ( V_2 , V_34 ) ) ;
break;
}
return V_69 ;
}
int F_89 ( struct V_8 * V_9 , struct V_1 * V_105 ,
int V_106 , int V_100 , int V_107 )
{
int V_69 = 0 ;
struct V_1 * V_108 = V_9 -> V_11 . V_2 ;
F_75 ( L_6
L_7 ,
V_108 , V_105 , V_100 , V_107 , V_106 ) ;
ASSERT ( V_108 ) ;
switch ( V_106 ) {
case V_109 :
if ( V_107 == 0 )
V_69 = F_86 ( V_108 , V_100 ) ;
else
V_69 = F_87 ( V_108 , V_100 ) ;
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
F_75 ( L_8 ,
V_106 ) ;
break;
}
return V_69 ;
}
bool F_90 ( struct V_19 * V_19 , struct V_1 * V_113 ,
struct V_75 * V_76 , int * V_114 , unsigned long * V_77 )
{
struct V_20 * V_115 ;
unsigned long V_7 = 1 ;
struct V_1 * * V_116 ;
int V_23 ;
bool V_117 = false ;
* V_114 = - 1 ;
if ( V_76 -> V_118 == V_110 ) {
* V_114 = F_67 ( V_113 -> V_9 , V_76 , V_77 ) ;
return true ;
}
if ( V_76 -> V_118 )
return false ;
F_91 () ;
V_115 = F_92 ( V_19 -> V_11 . V_39 ) ;
if ( ! V_115 )
goto V_26;
if ( V_76 -> V_107 == 0 ) {
if ( V_76 -> V_78 == V_119 ||
V_76 -> V_120 == 0xff )
goto V_26;
V_116 = & V_115 -> V_36 [ V_76 -> V_120 & 0xff ] ;
} else {
T_1 V_101 = V_76 -> V_120 << ( 32 - V_115 -> V_27 ) ;
V_116 = V_115 -> V_38 [ F_33 ( V_115 , V_101 ) ] ;
V_7 = F_34 ( V_115 , V_101 ) ;
if ( V_76 -> V_78 == V_119 ) {
int V_121 = - 1 ;
F_93 (i, &bitmap, 16 ) {
if ( ! V_116 [ V_23 ] )
continue;
if ( V_121 < 0 )
V_121 = V_23 ;
else if ( F_94 ( V_116 [ V_23 ] -> V_9 , V_116 [ V_121 ] -> V_9 ) < 0 )
V_121 = V_23 ;
}
V_7 = ( V_121 >= 0 ) ? 1 << V_121 : 0 ;
}
}
F_93 (i, &bitmap, 16 ) {
if ( ! V_116 [ V_23 ] )
continue;
if ( * V_114 < 0 )
* V_114 = 0 ;
* V_114 += F_67 ( V_116 [ V_23 ] -> V_9 , V_76 , V_77 ) ;
}
V_117 = true ;
V_26:
F_95 () ;
return V_117 ;
}
static int F_68 ( struct V_1 * V_2 , int V_78 ,
int V_10 , int V_79 , int V_80 ,
unsigned long * V_77 )
{
int V_69 = 0 ;
struct V_8 * V_9 = V_2 -> V_9 ;
switch ( V_78 ) {
case V_119 :
V_9 -> V_11 . V_122 ++ ;
case V_123 :
if ( F_96 ( ! F_23 ( V_2 ) ) )
break;
if ( V_77 )
F_77 ( V_9 -> V_104 , V_77 ) ;
if ( V_70 -> V_124 ) {
V_69 = 1 ;
V_70 -> V_124 ( V_9 , V_10 ) ;
} else {
V_69 = ! F_59 ( V_10 , V_2 ) ;
if ( ! V_69 ) {
if ( V_80 )
F_75 ( L_9
L_10 , V_10 ) ;
goto V_26;
}
F_84 ( V_99 , V_9 ) ;
F_97 ( V_9 ) ;
}
V_26:
F_98 ( V_9 -> V_104 , V_78 ,
V_80 , V_10 , ! V_69 ) ;
break;
case V_125 :
F_75 ( L_11 ) ;
break;
case V_126 :
F_75 ( L_12 ) ;
break;
case V_53 :
V_69 = 1 ;
F_99 ( V_9 ) ;
F_97 ( V_9 ) ;
break;
case V_127 :
if ( ! V_80 || V_79 ) {
V_69 = 1 ;
V_2 -> V_128 = ( 1UL << V_129 ) ;
F_100 () ;
F_84 ( V_99 , V_9 ) ;
F_97 ( V_9 ) ;
} else {
F_75 ( L_13 ,
V_9 -> V_104 ) ;
}
break;
case V_130 :
F_75 ( L_14 ,
V_9 -> V_104 , V_10 ) ;
V_69 = 1 ;
V_2 -> V_131 = V_10 ;
F_100 () ;
F_12 ( V_132 , & V_2 -> V_128 ) ;
F_84 ( V_99 , V_9 ) ;
F_97 ( V_9 ) ;
break;
case V_133 :
break;
default:
F_101 ( V_134 L_15 ,
V_78 ) ;
break;
}
return V_69 ;
}
int F_94 ( struct V_8 * V_135 , struct V_8 * V_136 )
{
return V_135 -> V_11 . V_122 - V_136 -> V_11 . V_122 ;
}
static void F_102 ( struct V_1 * V_2 , int V_10 )
{
if ( ! ( F_20 ( V_2 , V_14 ) & V_137 ) &&
F_103 ( V_2 -> V_9 -> V_19 , V_10 ) ) {
int V_138 ;
if ( F_8 ( V_10 , V_2 -> V_5 + V_91 ) )
V_138 = V_139 ;
else
V_138 = V_140 ;
F_104 ( V_2 -> V_9 , V_10 , V_138 ) ;
}
}
static int F_105 ( struct V_1 * V_2 )
{
int V_10 = F_80 ( V_2 ) ;
F_106 ( V_2 , V_10 ) ;
if ( V_10 == - 1 )
return V_10 ;
F_65 ( V_10 , V_2 ) ;
F_83 ( V_2 ) ;
F_102 ( V_2 , V_10 ) ;
F_84 ( V_99 , V_2 -> V_9 ) ;
return V_10 ;
}
void F_107 ( struct V_8 * V_9 , int V_10 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
F_106 ( V_2 , V_10 ) ;
F_102 ( V_2 , V_10 ) ;
F_84 ( V_99 , V_2 -> V_9 ) ;
}
static void F_108 ( struct V_1 * V_2 )
{
T_1 V_141 = F_20 ( V_2 , V_142 ) ;
T_1 V_143 = F_20 ( V_2 , V_144 ) ;
struct V_75 V_76 ;
V_76 . V_10 = V_141 & V_44 ;
V_76 . V_78 = V_141 & V_52 ;
V_76 . V_107 = V_141 & V_145 ;
V_76 . V_79 = V_141 & V_146 ;
V_76 . V_80 = V_141 & V_147 ;
V_76 . V_118 = V_141 & V_148 ;
if ( F_32 ( V_2 ) )
V_76 . V_120 = V_143 ;
else
V_76 . V_120 = F_109 ( V_143 ) ;
F_110 ( V_141 , V_76 . V_120 ) ;
F_75 ( L_16
L_17
L_18 ,
V_143 , V_141 , V_76 . V_118 , V_76 . V_120 ,
V_76 . V_80 , V_76 . V_79 , V_76 . V_107 , V_76 . V_78 ,
V_76 . V_10 ) ;
F_111 ( V_2 -> V_9 -> V_19 , V_2 , & V_76 , NULL ) ;
}
static T_1 F_112 ( struct V_1 * V_2 )
{
T_4 V_149 ;
T_5 V_150 ;
T_1 V_151 ;
ASSERT ( V_2 != NULL ) ;
if ( F_20 ( V_2 , V_152 ) == 0 )
return 0 ;
V_149 = F_113 ( & V_2 -> V_46 . V_153 ) ;
if ( F_114 ( V_149 ) < 0 )
V_149 = F_115 ( 0 , 0 ) ;
V_150 = F_116 ( F_114 ( V_149 ) , V_2 -> V_46 . V_154 ) ;
V_151 = F_117 ( V_150 ,
( V_155 * V_2 -> V_156 ) ) ;
return V_151 ;
}
static void F_118 ( struct V_1 * V_2 , bool V_157 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_158 * V_159 = V_9 -> V_159 ;
F_84 ( V_160 , V_9 ) ;
V_159 -> V_161 . V_162 = F_119 ( V_9 ) ;
V_159 -> V_161 . V_163 = V_157 ;
}
static inline void F_120 ( struct V_1 * V_2 , bool V_157 )
{
if ( V_2 -> V_9 -> V_11 . V_164 )
F_118 ( V_2 , V_157 ) ;
}
static T_1 F_121 ( struct V_1 * V_2 , unsigned int V_165 )
{
T_1 V_4 = 0 ;
if ( V_165 >= V_166 )
return 0 ;
switch ( V_165 ) {
case V_18 :
if ( F_32 ( V_2 ) )
V_4 = F_26 ( V_2 ) ;
else
V_4 = F_26 ( V_2 ) << 24 ;
break;
case V_167 :
F_75 ( L_19 ) ;
break;
case V_168 :
if ( F_48 ( V_2 ) )
return 0 ;
V_4 = F_112 ( V_2 ) ;
break;
case V_97 :
F_83 ( V_2 ) ;
V_4 = F_20 ( V_2 , V_165 ) ;
break;
case V_98 :
F_120 ( V_2 , false ) ;
default:
V_4 = F_20 ( V_2 , V_165 ) ;
break;
}
return V_4 ;
}
static inline struct V_1 * F_122 ( struct V_169 * V_170 )
{
return F_123 ( V_170 , struct V_1 , V_170 ) ;
}
static int F_124 ( struct V_1 * V_2 , T_1 V_165 , int V_171 ,
void * V_82 )
{
unsigned char V_172 = V_165 & 0xf ;
T_1 V_69 ;
static const T_6 V_173 = 0x43ff01ffffffe70cULL ;
if ( ( V_172 + V_171 ) > 4 ) {
F_75 ( L_20 ,
V_165 , V_171 ) ;
return 1 ;
}
if ( V_165 > 0x3f0 || ! ( V_173 & ( 1ULL << ( V_165 >> 4 ) ) ) ) {
F_75 ( L_21 ,
V_165 ) ;
return 1 ;
}
V_69 = F_121 ( V_2 , V_165 & ~ 0xf ) ;
F_125 ( V_165 , V_69 ) ;
switch ( V_171 ) {
case 1 :
case 2 :
case 4 :
memcpy ( V_82 , ( char * ) & V_69 + V_172 , V_171 ) ;
break;
default:
F_101 ( V_134 L_22
L_23 , V_171 ) ;
break;
}
return 0 ;
}
static int F_126 ( struct V_1 * V_2 , T_7 V_174 )
{
return F_25 ( V_2 ) &&
V_174 >= V_2 -> V_175 &&
V_174 < V_2 -> V_175 + V_166 ;
}
static int F_127 ( struct V_169 * V_176 ,
T_7 V_177 , int V_171 , void * V_82 )
{
struct V_1 * V_2 = F_122 ( V_176 ) ;
T_1 V_165 = V_177 - V_2 -> V_175 ;
if ( ! F_126 ( V_2 , V_177 ) )
return - V_178 ;
F_124 ( V_2 , V_165 , V_171 , V_82 ) ;
return 0 ;
}
static void F_128 ( struct V_1 * V_2 )
{
T_1 V_179 , V_180 , V_181 ;
V_181 = F_20 ( V_2 , V_182 ) ;
V_179 = V_181 & 0xf ;
V_180 = ( ( V_179 & 0x3 ) | ( ( V_179 & 0x8 ) >> 1 ) ) + 1 ;
V_2 -> V_156 = 0x1 << ( V_180 & 0x7 ) ;
F_75 ( L_24 ,
V_2 -> V_156 ) ;
}
static void F_129 ( struct V_1 * V_2 )
{
T_4 V_183 ;
F_130 ( & V_2 -> V_46 . V_184 , 0 ) ;
if ( F_47 ( V_2 ) || F_46 ( V_2 ) ) {
V_183 = V_2 -> V_46 . V_153 . V_185 -> V_186 () ;
V_2 -> V_46 . V_154 = ( T_6 ) F_20 ( V_2 , V_152 )
* V_155 * V_2 -> V_156 ;
if ( ! V_2 -> V_46 . V_154 )
return;
if ( F_47 ( V_2 ) ) {
T_5 V_187 = V_188 * 1000LL ;
if ( V_2 -> V_46 . V_154 < V_187 ) {
F_131 (
L_25
L_26 ,
V_2 -> V_9 -> V_104 ,
V_2 -> V_46 . V_154 , V_187 ) ;
V_2 -> V_46 . V_154 = V_187 ;
}
}
F_132 ( & V_2 -> V_46 . V_153 ,
F_133 ( V_183 , V_2 -> V_46 . V_154 ) ,
V_189 ) ;
F_75 ( L_27 V_190 L_28
V_191 L_29
L_30
L_31 V_191 L_32 , V_192 ,
V_155 , F_114 ( V_183 ) ,
F_20 ( V_2 , V_152 ) ,
V_2 -> V_46 . V_154 ,
F_114 ( F_133 ( V_183 ,
V_2 -> V_46 . V_154 ) ) ) ;
} else if ( F_48 ( V_2 ) ) {
T_6 V_193 , V_194 = V_2 -> V_46 . V_194 ;
T_6 V_150 = 0 ;
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned long V_195 = V_9 -> V_11 . V_196 ;
unsigned long V_197 ;
if ( F_96 ( ! V_194 || ! V_195 ) )
return;
F_134 ( V_197 ) ;
V_183 = V_2 -> V_46 . V_153 . V_185 -> V_186 () ;
V_193 = V_70 -> V_198 ( V_9 , F_135 () ) ;
if ( F_81 ( V_194 > V_193 ) ) {
V_150 = ( V_194 - V_193 ) * 1000000ULL ;
F_136 ( V_150 , V_195 ) ;
}
F_132 ( & V_2 -> V_46 . V_153 ,
F_133 ( V_183 , V_150 ) , V_189 ) ;
F_137 ( V_197 ) ;
}
}
static void F_138 ( struct V_1 * V_2 , T_1 V_199 )
{
int V_200 = F_49 ( F_20 ( V_2 , V_201 ) ) ;
if ( F_49 ( V_199 ) ) {
if ( ! V_200 ) {
F_75 ( L_33
L_34 , V_2 -> V_9 -> V_104 ) ;
V_2 -> V_9 -> V_19 -> V_11 . V_202 ++ ;
}
} else if ( V_200 )
V_2 -> V_9 -> V_19 -> V_11 . V_202 -- ;
}
static int F_139 ( struct V_1 * V_2 , T_1 V_62 , T_1 V_4 )
{
int V_117 = 0 ;
F_140 ( V_62 , V_4 ) ;
switch ( V_62 ) {
case V_18 :
if ( ! F_32 ( V_2 ) )
F_42 ( V_2 , V_4 >> 24 ) ;
else
V_117 = 1 ;
break;
case V_98 :
F_120 ( V_2 , true ) ;
F_85 ( V_2 , V_4 & 0xff ) ;
break;
case V_203 :
F_105 ( V_2 ) ;
break;
case V_37 :
if ( ! F_32 ( V_2 ) )
F_43 ( V_2 , V_4 & V_204 ) ;
else
V_117 = 1 ;
break;
case V_34 :
if ( ! F_32 ( V_2 ) ) {
F_1 ( V_2 , V_34 , V_4 | 0x0FFFFFFF ) ;
F_27 ( V_2 -> V_9 -> V_19 ) ;
} else
V_117 = 1 ;
break;
case V_14 : {
T_1 V_205 = 0x3ff ;
if ( F_20 ( V_2 , V_61 ) & V_60 )
V_205 |= V_137 ;
F_19 ( V_2 , V_4 & V_205 ) ;
if ( ! ( V_4 & V_15 ) ) {
int V_23 ;
T_1 V_51 ;
for ( V_23 = 0 ; V_23 < V_206 ; V_23 ++ ) {
V_51 = F_20 ( V_2 ,
V_45 + 0x10 * V_23 ) ;
F_1 ( V_2 , V_45 + 0x10 * V_23 ,
V_51 | V_43 ) ;
}
F_130 ( & V_2 -> V_46 . V_184 , 0 ) ;
}
break;
}
case V_142 :
F_1 ( V_2 , V_142 , V_4 & ~ ( 1 << 12 ) ) ;
F_108 ( V_2 ) ;
break;
case V_144 :
if ( ! F_32 ( V_2 ) )
V_4 &= 0xff000000 ;
F_1 ( V_2 , V_144 , V_4 ) ;
break;
case V_201 :
F_138 ( V_2 , V_4 ) ;
case V_207 :
case V_208 :
case V_209 :
case V_210 :
if ( ! F_24 ( V_2 ) )
V_4 |= V_43 ;
V_4 &= V_211 [ ( V_62 - V_45 ) >> 4 ] ;
F_1 ( V_2 , V_62 , V_4 ) ;
break;
case V_45 :
if ( ( F_20 ( V_2 , V_45 ) &
V_2 -> V_46 . V_47 ) !=
( V_4 & V_2 -> V_46 . V_47 ) )
F_141 ( & V_2 -> V_46 . V_153 ) ;
if ( ! F_24 ( V_2 ) )
V_4 |= V_43 ;
V_4 &= ( V_211 [ 0 ] | V_2 -> V_46 . V_47 ) ;
F_1 ( V_2 , V_45 , V_4 ) ;
break;
case V_152 :
if ( F_48 ( V_2 ) )
break;
F_141 ( & V_2 -> V_46 . V_153 ) ;
F_1 ( V_2 , V_152 , V_4 ) ;
F_129 ( V_2 ) ;
break;
case V_182 :
if ( V_4 & 4 )
F_75 ( L_35 , V_4 ) ;
F_1 ( V_2 , V_182 , V_4 ) ;
F_128 ( V_2 ) ;
break;
case V_212 :
if ( F_32 ( V_2 ) && V_4 != 0 ) {
F_75 ( L_36 , V_4 ) ;
V_117 = 1 ;
}
break;
case V_213 :
if ( F_32 ( V_2 ) ) {
F_139 ( V_2 , V_142 , 0x40000 | ( V_4 & 0xff ) ) ;
} else
V_117 = 1 ;
break;
default:
V_117 = 1 ;
break;
}
if ( V_117 )
F_75 ( L_37 , V_62 ) ;
return V_117 ;
}
static int F_142 ( struct V_169 * V_176 ,
T_7 V_177 , int V_171 , const void * V_82 )
{
struct V_1 * V_2 = F_122 ( V_176 ) ;
unsigned int V_165 = V_177 - V_2 -> V_175 ;
T_1 V_4 ;
if ( ! F_126 ( V_2 , V_177 ) )
return - V_178 ;
if ( V_171 != 4 || ( V_165 & 0xf ) ) {
F_75 ( L_38 , V_171 , ( long ) V_177 ) ;
return 0 ;
}
V_4 = * ( T_1 * ) V_82 ;
if ( V_165 != V_203 )
F_75 ( L_39
L_40 , V_192 , V_165 , V_171 , V_4 ) ;
F_139 ( V_2 , V_165 & 0xff0 , V_4 ) ;
return 0 ;
}
void F_143 ( struct V_8 * V_9 )
{
if ( F_51 ( V_9 ) )
F_139 ( V_9 -> V_11 . V_2 , V_203 , 0 ) ;
}
void F_144 ( struct V_8 * V_9 , T_1 V_165 )
{
T_1 V_4 = 0 ;
V_165 &= 0xff0 ;
F_124 ( V_9 -> V_11 . V_2 , V_165 , 4 , & V_4 ) ;
F_139 ( V_9 -> V_11 . V_2 , V_165 , V_4 ) ;
}
void F_145 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! V_9 -> V_11 . V_2 )
return;
F_141 ( & V_2 -> V_46 . V_153 ) ;
if ( ! ( V_9 -> V_11 . V_214 & V_215 ) )
F_21 ( & V_216 ) ;
if ( ! ( F_20 ( V_2 , V_14 ) & V_15 ) )
F_21 ( & V_16 ) ;
if ( V_2 -> V_5 )
F_146 ( ( unsigned long ) V_2 -> V_5 ) ;
F_147 ( V_2 ) ;
}
T_6 F_148 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_51 ( V_9 ) || F_46 ( V_2 ) ||
F_47 ( V_2 ) )
return 0 ;
return V_2 -> V_46 . V_194 ;
}
void F_149 ( struct V_8 * V_9 , T_6 V_82 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_51 ( V_9 ) || F_46 ( V_2 ) ||
F_47 ( V_2 ) )
return;
F_141 ( & V_2 -> V_46 . V_153 ) ;
V_2 -> V_46 . V_194 = V_82 ;
F_129 ( V_2 ) ;
}
void F_150 ( struct V_8 * V_9 , unsigned long V_217 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_51 ( V_9 ) )
return;
F_85 ( V_2 , ( ( V_217 & 0x0f ) << 4 )
| ( F_20 ( V_2 , V_98 ) & 4 ) ) ;
}
T_6 F_151 ( struct V_8 * V_9 )
{
T_6 V_92 ;
if ( ! F_51 ( V_9 ) )
return 0 ;
V_92 = ( T_6 ) F_20 ( V_9 -> V_11 . V_2 , V_98 ) ;
return ( V_92 & 0xf0 ) >> 4 ;
}
void F_152 ( struct V_8 * V_9 , T_6 V_218 )
{
T_6 V_219 = V_9 -> V_11 . V_214 ;
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! V_2 ) {
V_218 |= V_220 ;
V_9 -> V_11 . V_214 = V_218 ;
return;
}
if ( ( V_9 -> V_11 . V_214 ^ V_218 ) & V_215 ) {
if ( V_218 & V_215 )
F_21 ( & V_216 ) ;
else
F_22 ( & V_216 . V_17 ) ;
F_27 ( V_9 -> V_19 ) ;
}
if ( ! F_153 ( V_2 -> V_9 ) )
V_218 &= ~ V_220 ;
V_9 -> V_11 . V_214 = V_218 ;
if ( ( V_219 ^ V_218 ) & V_221 ) {
if ( V_218 & V_221 ) {
T_1 V_41 = F_26 ( V_2 ) ;
T_1 V_33 = ( ( V_41 >> 4 ) << 16 ) | ( 1 << ( V_41 & 0xf ) ) ;
F_43 ( V_2 , V_33 ) ;
V_70 -> V_222 ( V_9 , true ) ;
} else
V_70 -> V_222 ( V_9 , false ) ;
}
V_2 -> V_175 = V_2 -> V_9 -> V_11 . V_214 &
V_223 ;
F_75 ( L_41 V_191 L_42
L_43 , V_2 -> V_9 -> V_11 . V_214 , V_2 -> V_175 ) ;
}
void F_154 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
int V_23 ;
F_75 ( L_44 , V_192 ) ;
ASSERT ( V_9 ) ;
V_2 = V_9 -> V_11 . V_2 ;
ASSERT ( V_2 != NULL ) ;
F_141 ( & V_2 -> V_46 . V_153 ) ;
F_42 ( V_2 , V_9 -> V_104 ) ;
F_50 ( V_2 -> V_9 ) ;
for ( V_23 = 0 ; V_23 < V_206 ; V_23 ++ )
F_1 ( V_2 , V_45 + 0x10 * V_23 , V_43 ) ;
F_1 ( V_2 , V_201 ,
F_155 ( 0 , V_224 ) ) ;
F_1 ( V_2 , V_34 , 0xffffffffU ) ;
F_19 ( V_2 , 0xff ) ;
F_1 ( V_2 , V_98 , 0 ) ;
F_43 ( V_2 , 0 ) ;
F_1 ( V_2 , V_212 , 0 ) ;
F_1 ( V_2 , V_142 , 0 ) ;
F_1 ( V_2 , V_144 , 0 ) ;
F_1 ( V_2 , V_182 , 0 ) ;
F_1 ( V_2 , V_152 , 0 ) ;
for ( V_23 = 0 ; V_23 < 8 ; V_23 ++ ) {
F_1 ( V_2 , V_13 + 0x10 * V_23 , 0 ) ;
F_1 ( V_2 , V_12 + 0x10 * V_23 , 0 ) ;
F_1 ( V_2 , V_91 + 0x10 * V_23 , 0 ) ;
}
V_2 -> V_68 = F_156 ( V_9 -> V_19 ) ;
V_2 -> V_72 = F_156 ( V_9 -> V_19 ) ;
V_2 -> V_73 = - 1 ;
F_128 ( V_2 ) ;
F_130 ( & V_2 -> V_46 . V_184 , 0 ) ;
if ( F_153 ( V_9 ) )
F_152 ( V_9 ,
V_9 -> V_11 . V_214 | V_220 ) ;
V_9 -> V_11 . V_81 . V_83 = 0 ;
F_83 ( V_2 ) ;
V_9 -> V_11 . V_122 = 0 ;
V_9 -> V_11 . V_88 = 0 ;
F_75 ( V_225 L_45
L_46 V_191 L_47 , V_192 ,
V_9 , F_26 ( V_2 ) ,
V_9 -> V_11 . V_214 , V_2 -> V_175 ) ;
}
static bool F_157 ( struct V_1 * V_2 )
{
return F_47 ( V_2 ) ;
}
int F_158 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( F_51 ( V_9 ) && F_23 ( V_2 ) &&
F_44 ( V_2 , V_45 ) )
return F_159 ( & V_2 -> V_46 . V_184 ) ;
return 0 ;
}
int F_160 ( struct V_1 * V_2 , int V_42 )
{
T_1 V_62 = F_20 ( V_2 , V_42 ) ;
int V_10 , V_226 , V_80 ;
if ( F_25 ( V_2 ) && ! ( V_62 & V_43 ) ) {
V_10 = V_62 & V_44 ;
V_226 = V_62 & V_52 ;
V_80 = V_62 & V_227 ;
return F_68 ( V_2 , V_226 , V_10 , 1 , V_80 ,
NULL ) ;
}
return 0 ;
}
void F_161 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( V_2 )
F_160 ( V_2 , V_201 ) ;
}
static enum V_228 F_162 ( struct V_229 * V_82 )
{
struct V_230 * V_231 = F_123 ( V_82 , struct V_230 , V_153 ) ;
struct V_1 * V_2 = F_123 ( V_231 , struct V_1 , V_46 ) ;
struct V_8 * V_9 = V_2 -> V_9 ;
T_8 * V_232 = & V_9 -> V_233 ;
if ( ! F_159 ( & V_231 -> V_184 ) ) {
F_163 ( & V_231 -> V_184 ) ;
F_84 ( V_234 , V_9 ) ;
}
if ( F_164 ( V_232 ) )
F_165 ( V_232 ) ;
if ( F_157 ( V_2 ) ) {
F_166 ( & V_231 -> V_153 , V_231 -> V_154 ) ;
return V_235 ;
} else
return V_236 ;
}
int F_167 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
ASSERT ( V_9 != NULL ) ;
F_75 ( L_48 , V_9 -> V_104 ) ;
V_2 = F_28 ( sizeof( * V_2 ) , V_24 ) ;
if ( ! V_2 )
goto V_237;
V_9 -> V_11 . V_2 = V_2 ;
V_2 -> V_5 = ( void * ) F_168 ( V_24 ) ;
if ( ! V_2 -> V_5 ) {
F_101 ( V_134 L_49 ,
V_9 -> V_104 ) ;
goto V_238;
}
V_2 -> V_9 = V_9 ;
F_169 ( & V_2 -> V_46 . V_153 , V_239 ,
V_189 ) ;
V_2 -> V_46 . V_153 . V_240 = F_162 ;
V_9 -> V_11 . V_214 = V_215 ;
F_152 ( V_9 ,
V_241 | V_215 ) ;
F_22 ( & V_16 . V_17 ) ;
F_154 ( V_9 ) ;
F_170 ( & V_2 -> V_170 , & V_242 ) ;
return 0 ;
V_238:
F_147 ( V_2 ) ;
V_237:
return - V_243 ;
}
int F_171 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
int V_74 ;
if ( ! F_51 ( V_9 ) || ! F_23 ( V_2 ) )
return - 1 ;
F_83 ( V_2 ) ;
V_74 = F_61 ( V_2 ) ;
if ( ( V_74 == - 1 ) ||
( ( V_74 & 0xF0 ) <= F_20 ( V_2 , V_97 ) ) )
return - 1 ;
return V_74 ;
}
int F_172 ( struct V_8 * V_9 )
{
T_1 V_244 = F_20 ( V_9 -> V_11 . V_2 , V_201 ) ;
int V_114 = 0 ;
if ( ! F_25 ( V_9 -> V_11 . V_2 ) )
V_114 = 1 ;
if ( ( V_244 & V_43 ) == 0 &&
F_173 ( V_244 ) == V_224 )
V_114 = 1 ;
return V_114 ;
}
void F_174 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_51 ( V_9 ) )
return;
if ( F_159 ( & V_2 -> V_46 . V_184 ) > 0 ) {
if ( F_160 ( V_2 , V_45 ) )
F_175 ( & V_2 -> V_46 . V_184 ) ;
}
}
int F_176 ( struct V_8 * V_9 )
{
int V_10 = F_171 ( V_9 ) ;
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( V_10 == - 1 )
return - 1 ;
F_63 ( V_10 , V_2 ) ;
F_83 ( V_2 ) ;
F_62 ( V_10 , V_2 ) ;
return V_10 ;
}
void F_177 ( struct V_8 * V_9 ,
struct V_245 * V_246 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
F_152 ( V_9 , V_9 -> V_11 . V_214 ) ;
F_19 ( V_2 , * ( ( T_1 * ) ( V_246 -> V_5 + V_14 ) ) ) ;
memcpy ( V_9 -> V_11 . V_2 -> V_5 , V_246 -> V_5 , sizeof *V_246 ) ;
F_42 ( V_2 , F_26 ( V_2 ) ) ;
F_50 ( V_9 ) ;
F_83 ( V_2 ) ;
F_141 ( & V_2 -> V_46 . V_153 ) ;
F_128 ( V_2 ) ;
F_129 ( V_2 ) ;
V_2 -> V_68 = true ;
V_2 -> V_72 = F_156 ( V_9 -> V_19 ) ?
1 : F_55 ( V_2 -> V_5 + V_12 ) ;
V_2 -> V_73 = - 1 ;
V_70 -> V_247 ( V_9 -> V_19 , F_80 ( V_2 ) ) ;
F_84 ( V_99 , V_9 ) ;
F_178 ( V_9 ) ;
}
void F_179 ( struct V_8 * V_9 )
{
struct V_229 * V_153 ;
if ( ! F_51 ( V_9 ) )
return;
V_153 = & V_9 -> V_11 . V_2 -> V_46 . V_153 ;
if ( F_141 ( V_153 ) )
F_180 ( V_153 , V_189 ) ;
}
static void F_181 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
bool V_184 ;
int V_10 ;
F_64 ( ! F_73 ( V_9 ) ) ;
V_184 = F_74 ( V_9 ) ;
F_78 ( V_9 ) ;
if ( V_184 )
return;
V_10 = F_105 ( V_2 ) ;
F_182 ( V_2 , V_10 ) ;
}
void F_183 ( struct V_8 * V_9 )
{
T_1 V_82 ;
void * V_248 ;
if ( F_9 ( V_87 , & V_9 -> V_11 . V_88 ) )
F_181 ( V_9 , V_9 -> V_11 . V_2 ) ;
if ( ! F_9 ( V_249 , & V_9 -> V_11 . V_88 ) )
return;
V_248 = F_184 ( V_9 -> V_11 . V_2 -> V_250 ) ;
V_82 = * ( T_1 * ) ( V_248 + F_185 ( V_9 -> V_11 . V_2 -> V_251 ) ) ;
F_186 ( V_248 ) ;
F_85 ( V_9 -> V_11 . V_2 , V_82 & 0xff ) ;
}
static void F_187 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
if ( ! F_73 ( V_9 ) ||
V_2 -> V_68 ||
V_2 -> V_73 == - 1 ||
F_103 ( V_9 -> V_19 , V_2 -> V_73 ) ) {
return;
}
F_76 ( V_2 -> V_9 ) ;
}
void F_188 ( struct V_8 * V_9 )
{
T_1 V_82 , V_92 ;
int V_252 , V_253 ;
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
void * V_248 ;
F_187 ( V_9 , V_2 ) ;
if ( ! F_9 ( V_249 , & V_9 -> V_11 . V_88 ) )
return;
V_92 = F_20 ( V_2 , V_98 ) & 0xff ;
V_252 = F_61 ( V_2 ) ;
if ( V_252 < 0 )
V_252 = 0 ;
V_253 = F_80 ( V_2 ) ;
if ( V_253 < 0 )
V_253 = 0 ;
V_82 = ( V_92 & 0xff ) | ( ( V_253 & 0xf0 ) << 8 ) | ( V_252 << 24 ) ;
V_248 = F_184 ( V_9 -> V_11 . V_2 -> V_250 ) ;
* ( T_1 * ) ( V_248 + F_185 ( V_9 -> V_11 . V_2 -> V_251 ) ) = V_82 ;
F_186 ( V_248 ) ;
}
void F_189 ( struct V_8 * V_9 , T_7 V_251 )
{
V_9 -> V_11 . V_2 -> V_251 = V_251 ;
if ( V_251 )
F_77 ( V_249 , & V_9 -> V_11 . V_88 ) ;
else
F_79 ( V_249 , & V_9 -> V_11 . V_88 ) ;
}
int F_190 ( struct V_8 * V_9 , T_1 V_254 , T_6 V_82 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_1 V_62 = ( V_254 - V_255 ) << 4 ;
if ( ! F_191 ( V_9 -> V_19 ) || ! F_32 ( V_2 ) )
return 1 ;
if ( V_254 == 0x830 )
F_139 ( V_2 , V_144 , ( T_1 ) ( V_82 >> 32 ) ) ;
return F_139 ( V_2 , V_62 , ( T_1 ) V_82 ) ;
}
int F_192 ( struct V_8 * V_9 , T_1 V_254 , T_6 * V_82 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_1 V_62 = ( V_254 - V_255 ) << 4 , V_256 , V_257 = 0 ;
if ( ! F_191 ( V_9 -> V_19 ) || ! F_32 ( V_2 ) )
return 1 ;
if ( F_124 ( V_2 , V_62 , 4 , & V_256 ) )
return 1 ;
if ( V_254 == 0x830 )
F_124 ( V_2 , V_144 , 4 , & V_257 ) ;
* V_82 = ( ( ( T_6 ) V_257 ) << 32 ) | V_256 ;
return 0 ;
}
int F_193 ( struct V_8 * V_9 , T_1 V_62 , T_6 V_82 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_51 ( V_9 ) )
return 1 ;
if ( V_62 == V_142 )
F_139 ( V_2 , V_144 , ( T_1 ) ( V_82 >> 32 ) ) ;
return F_139 ( V_2 , V_62 , ( T_1 ) V_82 ) ;
}
int F_194 ( struct V_8 * V_9 , T_1 V_62 , T_6 * V_82 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_1 V_256 , V_257 = 0 ;
if ( ! F_51 ( V_9 ) )
return 1 ;
if ( F_124 ( V_2 , V_62 , 4 , & V_256 ) )
return 1 ;
if ( V_62 == V_142 )
F_124 ( V_2 , V_144 , 4 , & V_257 ) ;
* V_82 = ( ( ( T_6 ) V_257 ) << 32 ) | V_256 ;
return 0 ;
}
int F_195 ( struct V_8 * V_9 , T_6 V_82 )
{
T_6 V_174 = V_82 & ~ V_84 ;
if ( ! F_196 ( V_174 , 4 ) )
return 1 ;
V_9 -> V_11 . V_81 . V_83 = V_82 ;
if ( ! F_73 ( V_9 ) )
return 0 ;
return F_197 ( V_9 -> V_19 , & V_9 -> V_11 . V_81 . V_82 ,
V_174 , sizeof( T_3 ) ) ;
}
void F_198 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
unsigned int V_131 ;
unsigned long V_258 ;
if ( ! F_51 ( V_9 ) || ! V_2 -> V_128 )
return;
V_258 = F_58 ( & V_2 -> V_128 , 0 ) ;
if ( F_9 ( V_129 , & V_258 ) ) {
F_154 ( V_9 ) ;
F_199 ( V_9 ) ;
if ( F_153 ( V_2 -> V_9 ) )
V_9 -> V_11 . V_259 = V_260 ;
else
V_9 -> V_11 . V_259 = V_261 ;
}
if ( F_9 ( V_132 , & V_258 ) &&
V_9 -> V_11 . V_259 == V_261 ) {
F_200 () ;
V_131 = V_2 -> V_131 ;
F_201 ( L_50 ,
V_9 -> V_104 , V_131 ) ;
F_202 ( V_9 , V_131 ) ;
V_9 -> V_11 . V_259 = V_260 ;
}
}
void F_203 ( void )
{
F_204 ( & V_216 , V_262 ) ;
F_204 ( & V_16 , V_262 ) ;
}
