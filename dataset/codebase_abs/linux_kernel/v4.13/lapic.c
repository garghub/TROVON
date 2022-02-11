static inline int F_1 ( int V_1 , void * V_2 )
{
return F_2 ( F_3 ( V_1 ) , ( V_2 ) + F_4 ( V_1 ) ) ;
}
bool F_5 ( struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
return F_1 ( V_5 , V_7 -> V_9 + V_10 ) ||
F_1 ( V_5 , V_7 -> V_9 + V_11 ) ;
}
static inline void F_6 ( int V_1 , void * V_2 )
{
F_7 ( F_3 ( V_1 ) , ( V_2 ) + F_4 ( V_1 ) ) ;
}
static inline int F_8 ( int V_1 , void * V_2 )
{
return F_9 ( F_3 ( V_1 ) , ( V_2 ) + F_4 ( V_1 ) ) ;
}
static inline int F_10 ( int V_1 , void * V_2 )
{
return F_11 ( F_3 ( V_1 ) , ( V_2 ) + F_4 ( V_1 ) ) ;
}
static inline int F_12 ( struct V_6 * V_7 )
{
return F_13 ( V_7 ) && F_14 ( V_7 ) ;
}
static inline T_1 F_15 ( struct V_6 * V_7 )
{
return F_16 ( V_7 , V_12 ) >> 24 ;
}
static inline T_2 F_17 ( struct V_6 * V_7 )
{
return V_7 -> V_4 -> V_13 ;
}
static inline bool F_18 ( struct V_14 * V_15 ,
T_2 V_16 , struct V_6 * * * V_17 , T_3 * V_18 ) {
switch ( V_15 -> V_19 ) {
case V_20 : {
T_2 V_21 = ( V_16 >> 16 ) * 16 ;
T_2 V_22 = V_15 -> V_22 ;
if ( V_21 <= V_22 ) {
T_1 V_23 = F_19 ( V_22 - V_21 + 1 , 16U ) ;
* V_17 = & V_15 -> V_24 [ V_21 ] ;
* V_18 = V_16 & ( 0xffff >> ( 16 - V_23 ) ) ;
} else {
* V_18 = 0 ;
}
return true ;
}
case V_25 :
* V_17 = V_15 -> V_26 ;
* V_18 = V_16 & 0xff ;
return true ;
case V_27 :
* V_17 = V_15 -> V_28 [ ( V_16 >> 4 ) & 0xf ] ;
* V_18 = V_16 & 0xf ;
return true ;
default:
return false ;
}
}
static void F_20 ( struct V_29 * V_30 )
{
struct V_14 * V_15 = F_21 ( V_30 , struct V_14 , V_30 ) ;
F_22 ( V_15 ) ;
}
static void F_23 ( struct V_31 * V_31 )
{
struct V_14 * V_32 , * V_33 = NULL ;
struct V_3 * V_4 ;
int V_34 ;
T_2 V_35 = 255 ;
F_24 ( & V_31 -> V_8 . V_36 ) ;
F_25 (i, vcpu, kvm)
if ( F_26 ( V_4 ) )
V_35 = F_27 ( V_35 , F_17 ( V_4 -> V_8 . V_7 ) ) ;
V_32 = F_28 ( sizeof( struct V_14 ) +
sizeof( struct V_6 * ) * ( ( V_37 ) V_35 + 1 ) , V_38 ) ;
if ( ! V_32 )
goto V_39;
V_32 -> V_22 = V_35 ;
F_25 (i, vcpu, kvm) {
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
struct V_6 * * V_17 ;
T_3 V_18 ;
T_2 V_40 ;
T_1 V_41 ;
T_2 V_42 ;
if ( ! F_26 ( V_4 ) )
continue;
V_41 = F_15 ( V_7 ) ;
V_42 = F_17 ( V_7 ) ;
if ( ( F_29 ( V_7 ) || V_42 > 0xff ) &&
V_42 <= V_32 -> V_22 )
V_32 -> V_24 [ V_42 ] = V_7 ;
if ( ! F_29 ( V_7 ) && ! V_32 -> V_24 [ V_41 ] )
V_32 -> V_24 [ V_41 ] = V_7 ;
V_40 = F_16 ( V_7 , V_43 ) ;
if ( F_29 ( V_7 ) ) {
V_32 -> V_19 |= V_20 ;
} else if ( V_40 ) {
V_40 = F_30 ( V_40 ) ;
if ( F_16 ( V_7 , V_44 ) == V_45 )
V_32 -> V_19 |= V_25 ;
else
V_32 -> V_19 |= V_27 ;
}
if ( ! F_18 ( V_32 , V_40 , & V_17 , & V_18 ) )
continue;
if ( V_18 )
V_17 [ F_31 ( V_18 ) - 1 ] = V_7 ;
}
V_39:
V_33 = F_32 ( V_31 -> V_8 . V_46 ,
F_33 ( & V_31 -> V_8 . V_36 ) ) ;
F_34 ( V_31 -> V_8 . V_46 , V_32 ) ;
F_35 ( & V_31 -> V_8 . V_36 ) ;
if ( V_33 )
F_36 ( & V_33 -> V_30 , F_20 ) ;
F_37 ( V_31 ) ;
}
static inline void F_38 ( struct V_6 * V_7 , T_2 V_47 )
{
bool V_48 = V_47 & V_49 ;
F_39 ( V_7 , V_50 , V_47 ) ;
if ( V_48 != V_7 -> V_51 ) {
V_7 -> V_51 = V_48 ;
if ( V_48 ) {
F_40 ( & V_52 ) ;
F_23 ( V_7 -> V_4 -> V_31 ) ;
} else
F_41 ( & V_52 . V_53 ) ;
}
}
static inline void F_42 ( struct V_6 * V_7 , T_1 V_54 )
{
F_39 ( V_7 , V_12 , V_54 << 24 ) ;
F_23 ( V_7 -> V_4 -> V_31 ) ;
}
static inline void F_43 ( struct V_6 * V_7 , T_2 V_54 )
{
F_39 ( V_7 , V_43 , V_54 ) ;
F_23 ( V_7 -> V_4 -> V_31 ) ;
}
static inline void F_44 ( struct V_6 * V_7 , T_2 V_54 )
{
T_2 V_40 = ( ( V_54 >> 4 ) << 16 ) | ( 1 << ( V_54 & 0xf ) ) ;
F_45 ( V_54 != V_7 -> V_4 -> V_13 ) ;
F_39 ( V_7 , V_12 , V_54 ) ;
F_39 ( V_7 , V_43 , V_40 ) ;
F_23 ( V_7 -> V_4 -> V_31 ) ;
}
static inline int F_46 ( struct V_6 * V_7 , int V_55 )
{
return ! ( F_16 ( V_7 , V_55 ) & V_56 ) ;
}
static inline int F_47 ( struct V_6 * V_7 , int V_55 )
{
return F_16 ( V_7 , V_55 ) & V_57 ;
}
static inline int F_48 ( struct V_6 * V_7 )
{
return V_7 -> V_58 . V_59 == V_60 ;
}
static inline int F_49 ( struct V_6 * V_7 )
{
return V_7 -> V_58 . V_59 == V_61 ;
}
static inline int F_50 ( struct V_6 * V_7 )
{
return V_7 -> V_58 . V_59 == V_62 ;
}
static inline int F_51 ( T_2 V_63 )
{
return ( V_63 & ( V_64 | V_56 ) ) == V_65 ;
}
void F_52 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
struct V_66 * V_67 ;
T_2 V_68 = V_69 ;
if ( ! F_53 ( V_4 ) )
return;
V_67 = F_54 ( V_7 -> V_4 , 0x1 , 0 ) ;
if ( V_67 && ( V_67 -> V_70 & ( 1 << ( V_71 & 31 ) ) ) )
V_68 |= V_72 ;
F_39 ( V_7 , V_73 , V_68 ) ;
}
static int F_55 ( void * V_2 )
{
int V_1 ;
T_2 * V_74 ;
for ( V_1 = V_75 - V_76 ;
V_1 >= 0 ; V_1 -= V_76 ) {
V_74 = V_2 + F_4 ( V_1 ) ;
if ( * V_74 )
return F_56 ( * V_74 ) + V_1 ;
}
return - 1 ;
}
static T_1 F_57 ( void * V_2 )
{
int V_1 ;
T_2 * V_74 ;
T_1 V_77 = 0 ;
for ( V_1 = 0 ; V_1 < V_75 ; V_1 += V_76 ) {
V_74 = V_2 + F_4 ( V_1 ) ;
V_77 += F_58 ( * V_74 ) ;
}
return V_77 ;
}
int F_59 ( T_2 * V_78 , void * V_9 )
{
T_2 V_34 , V_1 ;
T_2 V_79 , V_80 ;
int V_81 = - 1 ;
for ( V_34 = V_1 = 0 ; V_34 <= 7 ; V_34 ++ , V_1 += 32 ) {
V_79 = F_60 ( V_78 [ V_34 ] ) ;
V_80 = * ( ( T_2 * ) ( V_9 + V_11 + V_34 * 0x10 ) ) ;
if ( V_79 ) {
V_80 |= F_61 ( & V_78 [ V_34 ] , 0 ) ;
* ( ( T_2 * ) ( V_9 + V_11 + V_34 * 0x10 ) ) = V_80 ;
}
if ( V_80 )
V_81 = F_56 ( V_80 ) + V_1 ;
}
return V_81 ;
}
int F_62 ( struct V_3 * V_4 , T_2 * V_78 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
return F_59 ( V_78 , V_7 -> V_9 ) ;
}
static inline int F_63 ( struct V_6 * V_7 )
{
return F_55 ( V_7 -> V_9 + V_11 ) ;
}
static inline int F_64 ( struct V_6 * V_7 )
{
int V_82 ;
if ( ! V_7 -> V_83 )
return - 1 ;
V_82 = F_63 ( V_7 ) ;
ASSERT ( V_82 == - 1 || V_82 >= 16 ) ;
return V_82 ;
}
static inline void F_65 ( int V_1 , struct V_6 * V_7 )
{
struct V_3 * V_4 ;
V_4 = V_7 -> V_4 ;
if ( F_66 ( V_4 -> V_8 . V_84 ) ) {
F_6 ( V_1 , V_7 -> V_9 + V_11 ) ;
V_85 -> V_86 ( V_4 ,
F_64 ( V_7 ) ) ;
} else {
V_7 -> V_83 = false ;
F_6 ( V_1 , V_7 -> V_9 + V_11 ) ;
if ( F_63 ( V_7 ) != - 1 )
V_7 -> V_83 = true ;
}
}
static inline void F_67 ( int V_1 , struct V_6 * V_7 )
{
struct V_3 * V_4 ;
if ( F_8 ( V_1 , V_7 -> V_9 + V_10 ) )
return;
V_4 = V_7 -> V_4 ;
if ( F_66 ( V_4 -> V_8 . V_84 ) )
V_85 -> V_87 ( V_4 , V_1 ) ;
else {
++ V_7 -> V_88 ;
F_68 ( V_7 -> V_88 > V_75 ) ;
V_7 -> V_89 = V_1 ;
}
}
static inline int F_69 ( struct V_6 * V_7 )
{
int V_82 ;
if ( ! V_7 -> V_88 )
return - 1 ;
if ( F_70 ( V_7 -> V_89 != - 1 ) )
return V_7 -> V_89 ;
V_82 = F_55 ( V_7 -> V_9 + V_10 ) ;
ASSERT ( V_82 == - 1 || V_82 >= 16 ) ;
return V_82 ;
}
static inline void F_71 ( int V_1 , struct V_6 * V_7 )
{
struct V_3 * V_4 ;
if ( ! F_10 ( V_1 , V_7 -> V_9 + V_10 ) )
return;
V_4 = V_7 -> V_4 ;
if ( F_66 ( V_4 -> V_8 . V_84 ) )
V_85 -> V_87 ( V_4 ,
F_69 ( V_7 ) ) ;
else {
-- V_7 -> V_88 ;
F_68 ( V_7 -> V_88 < 0 ) ;
V_7 -> V_89 = - 1 ;
}
}
int F_72 ( struct V_3 * V_4 )
{
return F_64 ( V_4 -> V_8 . V_7 ) ;
}
int F_73 ( struct V_3 * V_4 , struct V_90 * V_91 ,
struct V_92 * V_92 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
return F_74 ( V_7 , V_91 -> V_93 , V_91 -> V_5 ,
V_91 -> V_94 , V_91 -> V_95 , V_92 ) ;
}
static int F_75 ( struct V_3 * V_4 , T_1 V_47 )
{
return F_76 ( V_4 -> V_31 , & V_4 -> V_8 . V_96 . V_97 , & V_47 ,
sizeof( V_47 ) ) ;
}
static int F_77 ( struct V_3 * V_4 , T_1 * V_47 )
{
return F_78 ( V_4 -> V_31 , & V_4 -> V_8 . V_96 . V_97 , V_47 ,
sizeof( * V_47 ) ) ;
}
static inline bool F_79 ( struct V_3 * V_4 )
{
return V_4 -> V_8 . V_96 . V_98 & V_99 ;
}
static bool F_80 ( struct V_3 * V_4 )
{
T_1 V_47 ;
if ( F_77 ( V_4 , & V_47 ) < 0 )
F_81 ( L_1 ,
( unsigned long long ) V_4 -> V_8 . V_96 . V_98 ) ;
return V_47 & 0x1 ;
}
static void F_82 ( struct V_3 * V_4 )
{
if ( F_75 ( V_4 , V_100 ) < 0 ) {
F_81 ( L_2 ,
( unsigned long long ) V_4 -> V_8 . V_96 . V_98 ) ;
return;
}
F_83 ( V_101 , & V_4 -> V_8 . V_102 ) ;
}
static void F_84 ( struct V_3 * V_4 )
{
if ( F_75 ( V_4 , V_103 ) < 0 ) {
F_81 ( L_3 ,
( unsigned long long ) V_4 -> V_8 . V_96 . V_98 ) ;
return;
}
F_85 ( V_101 , & V_4 -> V_8 . V_102 ) ;
}
static int F_86 ( struct V_6 * V_7 , T_2 V_104 )
{
int V_105 ;
if ( V_85 -> V_106 && V_7 -> V_4 -> V_8 . V_84 )
V_105 = V_85 -> V_106 ( V_7 -> V_4 ) ;
else
V_105 = F_64 ( V_7 ) ;
if ( V_105 == - 1 || ( V_105 & 0xF0 ) <= V_104 )
return - 1 ;
return V_105 ;
}
static bool F_87 ( struct V_6 * V_7 , T_2 * V_107 )
{
T_2 V_108 , V_109 , V_104 , V_110 ;
int V_111 ;
V_110 = F_16 ( V_7 , V_112 ) ;
V_108 = F_16 ( V_7 , V_113 ) ;
V_111 = F_69 ( V_7 ) ;
V_109 = ( V_111 != - 1 ) ? V_111 : 0 ;
if ( ( V_108 & 0xf0 ) >= ( V_109 & 0xf0 ) )
V_104 = V_108 & 0xff ;
else
V_104 = V_109 & 0xf0 ;
F_81 ( L_4 ,
V_7 , V_104 , V_111 , V_109 ) ;
* V_107 = V_104 ;
if ( V_110 != V_104 )
F_39 ( V_7 , V_112 , V_104 ) ;
return V_104 < V_110 ;
}
static void F_88 ( struct V_6 * V_7 )
{
T_2 V_104 ;
if ( F_87 ( V_7 , & V_104 ) &&
F_86 ( V_7 , V_104 ) != - 1 )
F_89 ( V_114 , V_7 -> V_4 ) ;
}
void F_90 ( struct V_3 * V_4 )
{
F_88 ( V_4 -> V_8 . V_7 ) ;
}
static void F_91 ( struct V_6 * V_7 , T_2 V_108 )
{
F_39 ( V_7 , V_113 , V_108 ) ;
F_88 ( V_7 ) ;
}
static bool F_92 ( struct V_6 * V_7 , T_2 V_115 )
{
return V_115 == ( F_29 ( V_7 ) ?
V_116 : V_117 ) ;
}
static bool F_93 ( struct V_6 * V_7 , T_2 V_115 )
{
if ( F_92 ( V_7 , V_115 ) )
return true ;
if ( F_29 ( V_7 ) )
return V_115 == F_17 ( V_7 ) ;
if ( F_17 ( V_7 ) > 0xff && V_115 == F_17 ( V_7 ) )
return true ;
return V_115 == F_15 ( V_7 ) ;
}
static bool F_94 ( struct V_6 * V_7 , T_2 V_115 )
{
T_2 V_118 ;
if ( F_92 ( V_7 , V_115 ) )
return true ;
V_118 = F_16 ( V_7 , V_43 ) ;
if ( F_29 ( V_7 ) )
return ( ( V_118 >> 16 ) == ( V_115 >> 16 ) )
&& ( V_118 & V_115 & 0xffff ) != 0 ;
V_118 = F_30 ( V_118 ) ;
switch ( F_16 ( V_7 , V_44 ) ) {
case V_45 :
return ( V_118 & V_115 ) != 0 ;
case V_119 :
return ( ( V_118 >> 4 ) == ( V_115 >> 4 ) )
&& ( V_118 & V_115 & 0xf ) != 0 ;
default:
F_81 ( L_5 ,
V_7 -> V_4 -> V_13 , F_16 ( V_7 , V_44 ) ) ;
return false ;
}
}
static T_2 F_95 ( struct V_3 * V_4 , unsigned int V_16 ,
struct V_6 * V_120 , struct V_6 * V_121 )
{
bool V_122 = V_120 != NULL ;
if ( ! V_4 -> V_31 -> V_8 . V_123 &&
! V_122 && V_16 == V_117 && F_29 ( V_121 ) )
return V_116 ;
return V_16 ;
}
bool F_96 ( struct V_3 * V_4 , struct V_6 * V_120 ,
int V_124 , unsigned int V_125 , int V_126 )
{
struct V_6 * V_121 = V_4 -> V_8 . V_7 ;
T_2 V_115 = F_95 ( V_4 , V_125 , V_120 , V_121 ) ;
F_81 ( L_6
L_7 ,
V_121 , V_120 , V_125 , V_126 , V_124 ) ;
ASSERT ( V_121 ) ;
switch ( V_124 ) {
case V_127 :
if ( V_126 == V_128 )
return F_93 ( V_121 , V_115 ) ;
else
return F_94 ( V_121 , V_115 ) ;
case V_129 :
return V_121 == V_120 ;
case V_130 :
return true ;
case V_131 :
return V_121 != V_120 ;
default:
F_81 ( L_8 ,
V_124 ) ;
return false ;
}
}
int F_97 ( T_2 V_5 , T_2 V_132 ,
const unsigned long * V_2 , T_2 V_133 )
{
T_2 V_134 ;
int V_34 , V_135 = - 1 ;
V_134 = V_5 % V_132 ;
for ( V_34 = 0 ; V_34 <= V_134 ; V_34 ++ ) {
V_135 = F_98 ( V_2 , V_133 , V_135 + 1 ) ;
F_68 ( V_135 == V_133 ) ;
}
return V_135 ;
}
static void F_99 ( struct V_31 * V_31 )
{
if ( ! V_31 -> V_8 . V_136 ) {
V_31 -> V_8 . V_136 = true ;
F_100 ( V_137
L_9 ) ;
}
}
static bool F_101 ( struct V_31 * V_31 , struct V_6 * * V_138 ,
struct V_90 * V_91 , struct V_14 * V_15 )
{
if ( V_31 -> V_8 . V_123 ) {
if ( ( V_91 -> V_16 == V_117 &&
V_15 -> V_19 != V_20 ) )
return true ;
if ( V_91 -> V_16 == V_116 )
return true ;
} else {
bool V_139 = V_138 && * V_138 && F_29 ( * V_138 ) ;
if ( V_91 -> V_16 == ( V_139 ?
V_116 : V_117 ) )
return true ;
}
return false ;
}
static inline bool F_102 ( struct V_31 * V_31 ,
struct V_6 * * V_138 , struct V_90 * V_91 ,
struct V_14 * V_15 , struct V_6 * * * V_140 ,
unsigned long * V_2 )
{
int V_34 , V_141 ;
if ( V_91 -> V_142 == V_129 && V_138 ) {
* V_140 = V_138 ;
* V_2 = 1 ;
return true ;
} else if ( V_91 -> V_142 )
return false ;
if ( ! V_15 || F_101 ( V_31 , V_138 , V_91 , V_15 ) )
return false ;
if ( V_91 -> V_126 == V_128 ) {
if ( V_91 -> V_16 > V_15 -> V_22 ) {
* V_2 = 0 ;
} else {
* V_140 = & V_15 -> V_24 [ V_91 -> V_16 ] ;
* V_2 = 1 ;
}
return true ;
}
* V_2 = 0 ;
if ( ! F_18 ( V_15 , V_91 -> V_16 , V_140 ,
( T_3 * ) V_2 ) )
return false ;
if ( ! F_103 ( V_91 ) )
return true ;
if ( ! F_104 () ) {
V_141 = - 1 ;
F_105 (i, bitmap, 16 ) {
if ( ! ( * V_140 ) [ V_34 ] )
continue;
if ( V_141 < 0 )
V_141 = V_34 ;
else if ( F_106 ( ( * V_140 ) [ V_34 ] -> V_4 ,
( * V_140 ) [ V_141 ] -> V_4 ) < 0 )
V_141 = V_34 ;
}
} else {
if ( ! * V_2 )
return true ;
V_141 = F_97 ( V_91 -> V_5 , F_107 ( * V_2 ) ,
V_2 , 16 ) ;
if ( ! ( * V_140 ) [ V_141 ] ) {
F_99 ( V_31 ) ;
* V_2 = 0 ;
return true ;
}
}
* V_2 = ( V_141 >= 0 ) ? 1 << V_141 : 0 ;
return true ;
}
bool F_108 ( struct V_31 * V_31 , struct V_6 * V_138 ,
struct V_90 * V_91 , int * V_143 , struct V_92 * V_92 )
{
struct V_14 * V_15 ;
unsigned long V_2 ;
struct V_6 * * V_140 = NULL ;
int V_34 ;
bool V_144 ;
* V_143 = - 1 ;
if ( V_91 -> V_142 == V_129 ) {
* V_143 = F_73 ( V_138 -> V_4 , V_91 , V_92 ) ;
return true ;
}
F_109 () ;
V_15 = F_110 ( V_31 -> V_8 . V_46 ) ;
V_144 = F_102 ( V_31 , & V_138 , V_91 , V_15 , & V_140 , & V_2 ) ;
if ( V_144 )
F_105 (i, &bitmap, 16 ) {
if ( ! V_140 [ V_34 ] )
continue;
if ( * V_143 < 0 )
* V_143 = 0 ;
* V_143 += F_73 ( V_140 [ V_34 ] -> V_4 , V_91 , V_92 ) ;
}
F_111 () ;
return V_144 ;
}
bool F_112 ( struct V_31 * V_31 , struct V_90 * V_91 ,
struct V_3 * * V_145 )
{
struct V_14 * V_15 ;
unsigned long V_2 ;
struct V_6 * * V_140 = NULL ;
bool V_144 = false ;
if ( V_91 -> V_142 )
return false ;
F_109 () ;
V_15 = F_110 ( V_31 -> V_8 . V_46 ) ;
if ( F_102 ( V_31 , NULL , V_91 , V_15 , & V_140 , & V_2 ) &&
F_107 ( V_2 ) == 1 ) {
unsigned long V_34 = F_113 ( & V_2 , 16 ) ;
if ( V_140 [ V_34 ] ) {
* V_145 = V_140 [ V_34 ] -> V_4 ;
V_144 = true ;
}
}
F_111 () ;
return V_144 ;
}
static int F_74 ( struct V_6 * V_7 , int V_93 ,
int V_5 , int V_94 , int V_95 ,
struct V_92 * V_92 )
{
int V_82 = 0 ;
struct V_3 * V_4 = V_7 -> V_4 ;
F_114 ( V_4 -> V_13 , V_93 ,
V_95 , V_5 ) ;
switch ( V_93 ) {
case V_146 :
V_4 -> V_8 . V_147 ++ ;
case V_148 :
if ( F_66 ( V_95 && ! V_94 ) )
break;
if ( F_66 ( ! F_12 ( V_7 ) ) )
break;
V_82 = 1 ;
if ( V_92 ) {
F_83 ( V_4 -> V_13 , V_92 -> V_15 ) ;
V_92 -> V_149 [ V_4 -> V_13 ] = V_5 ;
}
if ( F_1 ( V_5 , V_7 -> V_9 + V_150 ) != ! ! V_95 ) {
if ( V_95 )
F_115 ( V_5 , V_7 -> V_9 + V_150 ) ;
else
F_6 ( V_5 , V_7 -> V_9 + V_150 ) ;
}
if ( V_4 -> V_8 . V_84 )
V_85 -> V_151 ( V_4 , V_5 ) ;
else {
F_116 ( V_5 , V_7 ) ;
F_89 ( V_114 , V_4 ) ;
F_117 ( V_4 ) ;
}
break;
case V_152 :
V_82 = 1 ;
V_4 -> V_8 . V_153 . V_154 = 1 ;
F_89 ( V_114 , V_4 ) ;
F_117 ( V_4 ) ;
break;
case V_155 :
V_82 = 1 ;
F_89 ( V_156 , V_4 ) ;
F_117 ( V_4 ) ;
break;
case V_65 :
V_82 = 1 ;
F_118 ( V_4 ) ;
F_117 ( V_4 ) ;
break;
case V_157 :
if ( ! V_95 || V_94 ) {
V_82 = 1 ;
V_7 -> V_158 = ( 1UL << V_159 ) ;
F_119 () ;
F_89 ( V_114 , V_4 ) ;
F_117 ( V_4 ) ;
} else {
F_81 ( L_10 ,
V_4 -> V_13 ) ;
}
break;
case V_160 :
F_81 ( L_11 ,
V_4 -> V_13 , V_5 ) ;
V_82 = 1 ;
V_7 -> V_161 = V_5 ;
F_119 () ;
F_120 ( V_162 , & V_7 -> V_158 ) ;
F_89 ( V_114 , V_4 ) ;
F_117 ( V_4 ) ;
break;
case V_163 :
break;
default:
F_100 ( V_164 L_12 ,
V_93 ) ;
break;
}
return V_82 ;
}
int F_106 ( struct V_3 * V_165 , struct V_3 * V_166 )
{
return V_165 -> V_8 . V_147 - V_166 -> V_8 . V_147 ;
}
static bool F_121 ( struct V_6 * V_7 , int V_5 )
{
return F_2 ( V_5 , V_7 -> V_4 -> V_8 . V_167 ) ;
}
static void F_122 ( struct V_6 * V_7 , int V_5 )
{
int V_168 ;
if ( ! F_121 ( V_7 , V_5 ) )
return;
if ( F_123 ( V_7 -> V_4 -> V_31 ) ) {
V_7 -> V_4 -> V_8 . V_169 = V_5 ;
F_89 ( V_170 , V_7 -> V_4 ) ;
return;
}
if ( F_1 ( V_5 , V_7 -> V_9 + V_150 ) )
V_168 = V_171 ;
else
V_168 = V_172 ;
F_124 ( V_7 -> V_4 , V_5 , V_168 ) ;
}
static int F_125 ( struct V_6 * V_7 )
{
int V_5 = F_69 ( V_7 ) ;
F_126 ( V_7 , V_5 ) ;
if ( V_5 == - 1 )
return V_5 ;
F_71 ( V_5 , V_7 ) ;
F_88 ( V_7 ) ;
if ( F_2 ( V_5 , F_127 ( V_7 -> V_4 ) -> V_173 ) )
F_128 ( V_7 -> V_4 , V_5 ) ;
F_122 ( V_7 , V_5 ) ;
F_89 ( V_114 , V_7 -> V_4 ) ;
return V_5 ;
}
void F_129 ( struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
F_126 ( V_7 , V_5 ) ;
F_122 ( V_7 , V_5 ) ;
F_89 ( V_114 , V_7 -> V_4 ) ;
}
static void F_130 ( struct V_6 * V_7 )
{
T_2 V_174 = F_16 ( V_7 , V_175 ) ;
T_2 V_176 = F_16 ( V_7 , V_177 ) ;
struct V_90 V_91 ;
V_91 . V_5 = V_174 & V_57 ;
V_91 . V_93 = V_174 & V_64 ;
V_91 . V_126 = V_174 & V_178 ;
V_91 . V_94 = ( V_174 & V_179 ) != 0 ;
V_91 . V_95 = V_174 & V_180 ;
V_91 . V_142 = V_174 & V_181 ;
V_91 . V_182 = false ;
if ( F_29 ( V_7 ) )
V_91 . V_16 = V_176 ;
else
V_91 . V_16 = F_131 ( V_176 ) ;
F_132 ( V_174 , V_91 . V_16 ) ;
F_81 ( L_13
L_14
L_15
L_16 ,
V_176 , V_174 , V_91 . V_142 , V_91 . V_16 ,
V_91 . V_95 , V_91 . V_94 , V_91 . V_126 , V_91 . V_93 ,
V_91 . V_5 , V_91 . V_182 ) ;
F_133 ( V_7 -> V_4 -> V_31 , V_7 , & V_91 , NULL ) ;
}
static T_2 F_134 ( struct V_6 * V_7 )
{
T_4 V_183 , V_184 ;
T_5 V_185 ;
T_2 V_186 ;
ASSERT ( V_7 != NULL ) ;
if ( F_16 ( V_7 , V_187 ) == 0 ||
V_7 -> V_58 . V_188 == 0 )
return 0 ;
V_184 = F_135 () ;
V_183 = F_136 ( V_7 -> V_58 . V_189 , V_184 ) ;
if ( F_137 ( V_183 ) < 0 )
V_183 = 0 ;
V_185 = F_138 ( F_137 ( V_183 ) , V_7 -> V_58 . V_188 ) ;
V_186 = F_139 ( V_185 ,
( V_190 * V_7 -> V_191 ) ) ;
return V_186 ;
}
static void F_140 ( struct V_6 * V_7 , bool V_192 )
{
struct V_3 * V_4 = V_7 -> V_4 ;
struct V_193 * V_194 = V_4 -> V_194 ;
F_89 ( V_195 , V_4 ) ;
V_194 -> V_196 . V_197 = F_141 ( V_4 ) ;
V_194 -> V_196 . V_198 = V_192 ;
}
static inline void F_142 ( struct V_6 * V_7 , bool V_192 )
{
if ( V_7 -> V_4 -> V_8 . V_199 )
F_140 ( V_7 , V_192 ) ;
}
static T_2 F_143 ( struct V_6 * V_7 , unsigned int V_21 )
{
T_2 V_47 = 0 ;
if ( V_21 >= V_200 )
return 0 ;
switch ( V_21 ) {
case V_201 :
F_81 ( L_17 ) ;
break;
case V_202 :
if ( F_50 ( V_7 ) )
return 0 ;
V_47 = F_134 ( V_7 ) ;
break;
case V_112 :
F_88 ( V_7 ) ;
V_47 = F_16 ( V_7 , V_21 ) ;
break;
case V_113 :
F_142 ( V_7 , false ) ;
default:
V_47 = F_16 ( V_7 , V_21 ) ;
break;
}
return V_47 ;
}
static inline struct V_6 * F_144 ( struct V_203 * V_204 )
{
return F_21 ( V_204 , struct V_6 , V_204 ) ;
}
int F_145 ( struct V_6 * V_7 , T_2 V_21 , int V_205 ,
void * V_97 )
{
unsigned char V_206 = V_21 & 0xf ;
T_2 V_82 ;
static const V_37 V_207 = 0x43ff01ffffffe70cULL ;
if ( ( V_206 + V_205 ) > 4 ) {
F_81 ( L_18 ,
V_21 , V_205 ) ;
return 1 ;
}
if ( V_21 > 0x3f0 || ! ( V_207 & ( 1ULL << ( V_21 >> 4 ) ) ) ) {
F_81 ( L_19 ,
V_21 ) ;
return 1 ;
}
V_82 = F_143 ( V_7 , V_21 & ~ 0xf ) ;
F_146 ( V_21 , V_82 ) ;
switch ( V_205 ) {
case 1 :
case 2 :
case 4 :
memcpy ( V_97 , ( char * ) & V_82 + V_206 , V_205 ) ;
break;
default:
F_100 ( V_164 L_20
L_21 , V_205 ) ;
break;
}
return 0 ;
}
static int F_147 ( struct V_6 * V_7 , T_6 V_208 )
{
return F_14 ( V_7 ) &&
V_208 >= V_7 -> V_209 &&
V_208 < V_7 -> V_209 + V_200 ;
}
static int F_148 ( struct V_3 * V_4 , struct V_203 * V_210 ,
T_6 V_211 , int V_205 , void * V_97 )
{
struct V_6 * V_7 = F_144 ( V_210 ) ;
T_2 V_21 = V_211 - V_7 -> V_209 ;
if ( ! F_147 ( V_7 , V_211 ) )
return - V_212 ;
F_145 ( V_7 , V_21 , V_205 , V_97 ) ;
return 0 ;
}
static void F_149 ( struct V_6 * V_7 )
{
T_2 V_213 , V_214 , V_215 ;
V_215 = F_16 ( V_7 , V_216 ) ;
V_213 = V_215 & 0xf ;
V_214 = ( ( V_213 & 0x3 ) | ( ( V_213 & 0x8 ) >> 1 ) ) + 1 ;
V_7 -> V_191 = 0x1 << ( V_214 & 0x7 ) ;
F_81 ( L_22 ,
V_7 -> V_191 ) ;
}
static void F_150 ( struct V_6 * V_7 )
{
T_2 V_59 = F_16 ( V_7 , V_217 ) &
V_7 -> V_58 . V_218 ;
if ( V_7 -> V_58 . V_59 != V_59 ) {
V_7 -> V_58 . V_59 = V_59 ;
F_151 ( & V_7 -> V_58 . V_219 ) ;
}
}
static void F_152 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_4 ;
struct V_220 * V_221 = & V_4 -> V_222 ;
struct V_223 * V_224 = & V_7 -> V_58 ;
if ( F_153 ( & V_7 -> V_58 . V_225 ) )
return;
F_154 ( & V_7 -> V_58 . V_225 ) ;
F_155 ( V_4 ) ;
if ( F_156 ( V_221 ) )
F_157 ( V_221 ) ;
if ( F_50 ( V_7 ) )
V_224 -> V_226 = V_224 -> V_227 ;
}
static bool F_158 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
T_2 V_74 = F_16 ( V_7 , V_217 ) ;
if ( F_14 ( V_7 ) ) {
int V_1 = V_74 & V_57 ;
void * V_2 = V_7 -> V_9 + V_10 ;
if ( V_4 -> V_8 . V_84 )
V_2 = V_7 -> V_9 + V_11 ;
if ( F_1 ( V_1 , V_2 ) )
return true ;
}
return false ;
}
void F_159 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
V_37 V_228 , V_229 ;
if ( ! F_53 ( V_4 ) )
return;
if ( V_7 -> V_58 . V_226 == 0 )
return;
if ( ! F_158 ( V_4 ) )
return;
V_229 = V_7 -> V_58 . V_226 ;
V_7 -> V_58 . V_226 = 0 ;
V_228 = F_160 ( V_4 , F_161 () ) ;
F_162 ( V_4 -> V_13 , V_228 - V_229 ) ;
if ( V_228 < V_229 )
F_163 ( F_19 ( V_229 - V_228 ,
F_164 ( V_4 , V_230 ) ) ) ;
}
static void F_165 ( struct V_6 * V_7 )
{
V_37 V_228 , V_227 = V_7 -> V_58 . V_227 ;
V_37 V_185 = 0 ;
T_4 V_231 ;
struct V_3 * V_4 = V_7 -> V_4 ;
unsigned long V_232 = V_4 -> V_8 . V_233 ;
unsigned long V_234 ;
T_4 V_184 ;
if ( F_66 ( ! V_227 || ! V_232 ) )
return;
F_166 ( V_234 ) ;
V_184 = F_135 () ;
V_228 = F_160 ( V_4 , F_161 () ) ;
if ( F_70 ( V_227 > V_228 ) ) {
V_185 = ( V_227 - V_228 ) * 1000000ULL ;
F_167 ( V_185 , V_232 ) ;
V_231 = F_168 ( V_184 , V_185 ) ;
V_231 = F_169 ( V_231 , V_230 ) ;
F_170 ( & V_7 -> V_58 . V_219 ,
V_231 , V_235 ) ;
} else
F_152 ( V_7 ) ;
F_171 ( V_234 ) ;
}
static void F_172 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_58 . V_188 )
return;
if ( F_48 ( V_7 ) &&
F_173 ( F_135 () ,
V_7 -> V_58 . V_189 ) ) {
F_152 ( V_7 ) ;
return;
}
F_170 ( & V_7 -> V_58 . V_219 ,
V_7 -> V_58 . V_189 ,
V_235 ) ;
}
static bool F_174 ( struct V_6 * V_7 )
{
T_4 V_184 ;
V_37 V_236 = F_161 () ;
V_184 = F_135 () ;
V_7 -> V_58 . V_188 = ( V_37 ) F_16 ( V_7 , V_187 )
* V_190 * V_7 -> V_191 ;
if ( ! V_7 -> V_58 . V_188 )
return false ;
if ( F_49 ( V_7 ) ) {
T_5 V_237 = V_238 * 1000LL ;
if ( V_7 -> V_58 . V_188 < V_237 ) {
F_175 (
L_23
L_24 ,
V_7 -> V_4 -> V_13 ,
V_7 -> V_58 . V_188 , V_237 ) ;
V_7 -> V_58 . V_188 = V_237 ;
}
}
F_81 ( L_25 V_239 L_26
V_240 L_27
L_28
L_29 V_240 L_30 , V_241 ,
V_190 , F_137 ( V_184 ) ,
F_16 ( V_7 , V_187 ) ,
V_7 -> V_58 . V_188 ,
F_137 ( F_168 ( V_184 ,
V_7 -> V_58 . V_188 ) ) ) ;
V_7 -> V_58 . V_227 = F_160 ( V_7 -> V_4 , V_236 ) +
F_164 ( V_7 -> V_4 , V_7 -> V_58 . V_188 ) ;
V_7 -> V_58 . V_189 = F_168 ( V_184 , V_7 -> V_58 . V_188 ) ;
return true ;
}
static void F_176 ( struct V_6 * V_7 )
{
V_7 -> V_58 . V_227 +=
F_164 ( V_7 -> V_4 , V_7 -> V_58 . V_188 ) ;
V_7 -> V_58 . V_189 =
F_168 ( V_7 -> V_58 . V_189 ,
V_7 -> V_58 . V_188 ) ;
}
bool F_177 ( struct V_3 * V_4 )
{
if ( ! F_53 ( V_4 ) )
return false ;
return V_4 -> V_8 . V_7 -> V_58 . V_242 ;
}
static void F_178 ( struct V_6 * V_7 )
{
F_179 ( F_180 () ) ;
F_179 ( ! V_7 -> V_58 . V_242 ) ;
V_85 -> F_178 ( V_7 -> V_4 ) ;
V_7 -> V_58 . V_242 = false ;
}
static bool F_181 ( struct V_6 * V_7 )
{
struct V_223 * V_224 = & V_7 -> V_58 ;
int V_143 ;
F_179 ( F_180 () ) ;
if ( ! V_85 -> V_243 )
return false ;
if ( ! F_49 ( V_7 ) && F_153 ( & V_224 -> V_225 ) )
return false ;
V_143 = V_85 -> V_243 ( V_7 -> V_4 , V_224 -> V_227 ) ;
if ( V_143 < 0 )
return false ;
V_224 -> V_242 = true ;
F_151 ( & V_224 -> V_219 ) ;
if ( ! F_49 ( V_7 ) && ( V_143 || F_153 ( & V_224 -> V_225 ) ) ) {
if ( V_143 )
F_152 ( V_7 ) ;
return false ;
}
F_182 ( V_7 -> V_4 -> V_13 , true ) ;
return true ;
}
static void F_183 ( struct V_6 * V_7 )
{
struct V_223 * V_224 = & V_7 -> V_58 ;
F_179 ( F_180 () ) ;
if ( V_7 -> V_58 . V_242 )
F_178 ( V_7 ) ;
if ( ! F_49 ( V_7 ) && F_153 ( & V_224 -> V_225 ) )
return;
if ( F_49 ( V_7 ) || F_48 ( V_7 ) )
F_172 ( V_7 ) ;
else if ( F_50 ( V_7 ) )
F_165 ( V_7 ) ;
F_182 ( V_7 -> V_4 -> V_13 , false ) ;
}
static void F_184 ( struct V_6 * V_7 )
{
F_185 () ;
if ( ! F_181 ( V_7 ) )
F_183 ( V_7 ) ;
F_186 () ;
}
void F_187 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
F_185 () ;
if ( ! V_7 -> V_58 . V_242 )
goto V_39;
F_179 ( F_156 ( & V_4 -> V_222 ) ) ;
F_178 ( V_7 ) ;
F_152 ( V_7 ) ;
if ( F_49 ( V_7 ) && V_7 -> V_58 . V_188 ) {
F_176 ( V_7 ) ;
F_184 ( V_7 ) ;
}
V_39:
F_186 () ;
}
void F_188 ( struct V_3 * V_4 )
{
F_184 ( V_4 -> V_8 . V_7 ) ;
}
void F_189 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
F_185 () ;
if ( V_7 -> V_58 . V_242 )
F_183 ( V_7 ) ;
F_186 () ;
}
void F_190 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
F_179 ( ! V_7 -> V_58 . V_242 ) ;
F_184 ( V_7 ) ;
}
static void F_191 ( struct V_6 * V_7 )
{
F_192 ( & V_7 -> V_58 . V_225 , 0 ) ;
if ( ( F_49 ( V_7 ) || F_48 ( V_7 ) )
&& ! F_174 ( V_7 ) )
return;
F_184 ( V_7 ) ;
}
static void F_193 ( struct V_6 * V_7 , T_2 V_244 )
{
bool V_245 = F_51 ( V_244 ) ;
if ( V_7 -> V_245 != V_245 ) {
V_7 -> V_245 = V_245 ;
if ( V_245 ) {
F_81 ( L_31
L_32 , V_7 -> V_4 -> V_13 ) ;
F_154 ( & V_7 -> V_4 -> V_31 -> V_8 . V_246 ) ;
} else
F_194 ( & V_7 -> V_4 -> V_31 -> V_8 . V_246 ) ;
}
}
int F_195 ( struct V_6 * V_7 , T_2 V_74 , T_2 V_47 )
{
int V_144 = 0 ;
F_196 ( V_74 , V_47 ) ;
switch ( V_74 ) {
case V_12 :
if ( ! F_29 ( V_7 ) )
F_42 ( V_7 , V_47 >> 24 ) ;
else
V_144 = 1 ;
break;
case V_113 :
F_142 ( V_7 , true ) ;
F_91 ( V_7 , V_47 & 0xff ) ;
break;
case V_247 :
F_125 ( V_7 ) ;
break;
case V_43 :
if ( ! F_29 ( V_7 ) )
F_43 ( V_7 , V_47 & V_248 ) ;
else
V_144 = 1 ;
break;
case V_44 :
if ( ! F_29 ( V_7 ) ) {
F_39 ( V_7 , V_44 , V_47 | 0x0FFFFFFF ) ;
F_23 ( V_7 -> V_4 -> V_31 ) ;
} else
V_144 = 1 ;
break;
case V_50 : {
T_2 V_18 = 0x3ff ;
if ( F_16 ( V_7 , V_73 ) & V_72 )
V_18 |= V_249 ;
F_38 ( V_7 , V_47 & V_18 ) ;
if ( ! ( V_47 & V_49 ) ) {
int V_34 ;
T_2 V_63 ;
for ( V_34 = 0 ; V_34 < V_250 ; V_34 ++ ) {
V_63 = F_16 ( V_7 ,
V_217 + 0x10 * V_34 ) ;
F_39 ( V_7 , V_217 + 0x10 * V_34 ,
V_63 | V_56 ) ;
}
F_150 ( V_7 ) ;
F_192 ( & V_7 -> V_58 . V_225 , 0 ) ;
}
break;
}
case V_175 :
F_39 ( V_7 , V_175 , V_47 & ~ ( 1 << 12 ) ) ;
F_130 ( V_7 ) ;
break;
case V_177 :
if ( ! F_29 ( V_7 ) )
V_47 &= 0xff000000 ;
F_39 ( V_7 , V_177 , V_47 ) ;
break;
case V_251 :
F_193 ( V_7 , V_47 ) ;
case V_252 :
case V_253 :
case V_254 :
case V_255 :
if ( ! F_13 ( V_7 ) )
V_47 |= V_56 ;
V_47 &= V_256 [ ( V_74 - V_217 ) >> 4 ] ;
F_39 ( V_7 , V_74 , V_47 ) ;
break;
case V_217 :
if ( ! F_13 ( V_7 ) )
V_47 |= V_56 ;
V_47 &= ( V_256 [ 0 ] | V_7 -> V_58 . V_218 ) ;
F_39 ( V_7 , V_217 , V_47 ) ;
F_150 ( V_7 ) ;
break;
case V_187 :
if ( F_50 ( V_7 ) )
break;
F_151 ( & V_7 -> V_58 . V_219 ) ;
F_39 ( V_7 , V_187 , V_47 ) ;
F_191 ( V_7 ) ;
break;
case V_216 :
if ( V_47 & 4 )
F_81 ( L_33 , V_47 ) ;
F_39 ( V_7 , V_216 , V_47 ) ;
F_149 ( V_7 ) ;
break;
case V_257 :
if ( F_29 ( V_7 ) && V_47 != 0 ) {
F_81 ( L_34 , V_47 ) ;
V_144 = 1 ;
}
break;
case V_258 :
if ( F_29 ( V_7 ) ) {
F_195 ( V_7 , V_175 , 0x40000 | ( V_47 & 0xff ) ) ;
} else
V_144 = 1 ;
break;
default:
V_144 = 1 ;
break;
}
if ( V_144 )
F_81 ( L_35 , V_74 ) ;
return V_144 ;
}
static int F_197 ( struct V_3 * V_4 , struct V_203 * V_210 ,
T_6 V_211 , int V_205 , const void * V_97 )
{
struct V_6 * V_7 = F_144 ( V_210 ) ;
unsigned int V_21 = V_211 - V_7 -> V_209 ;
T_2 V_47 ;
if ( ! F_147 ( V_7 , V_211 ) )
return - V_212 ;
if ( V_205 != 4 || ( V_21 & 0xf ) ) {
F_81 ( L_36 , V_205 , ( long ) V_211 ) ;
return 0 ;
}
V_47 = * ( T_2 * ) V_97 ;
if ( V_21 != V_247 )
F_81 ( L_37
L_38 , V_241 , V_21 , V_205 , V_47 ) ;
F_195 ( V_7 , V_21 & 0xff0 , V_47 ) ;
return 0 ;
}
void F_198 ( struct V_3 * V_4 )
{
F_195 ( V_4 -> V_8 . V_7 , V_247 , 0 ) ;
}
void F_199 ( struct V_3 * V_4 , T_2 V_21 )
{
T_2 V_47 = 0 ;
V_21 &= 0xff0 ;
F_145 ( V_4 -> V_8 . V_7 , V_21 , 4 , & V_47 ) ;
F_195 ( V_4 -> V_8 . V_7 , V_21 , V_47 ) ;
}
void F_200 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
if ( ! V_4 -> V_8 . V_7 )
return;
F_151 ( & V_7 -> V_58 . V_219 ) ;
if ( ! ( V_4 -> V_8 . V_259 & V_260 ) )
F_40 ( & V_261 ) ;
if ( ! V_7 -> V_51 )
F_40 ( & V_52 ) ;
if ( V_7 -> V_9 )
F_201 ( ( unsigned long ) V_7 -> V_9 ) ;
F_202 ( V_7 ) ;
}
V_37 F_203 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
if ( ! F_53 ( V_4 ) ||
! F_50 ( V_7 ) )
return 0 ;
return V_7 -> V_58 . V_227 ;
}
void F_204 ( struct V_3 * V_4 , V_37 V_97 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
if ( ! F_53 ( V_4 ) || F_48 ( V_7 ) ||
F_49 ( V_7 ) )
return;
F_151 ( & V_7 -> V_58 . V_219 ) ;
V_7 -> V_58 . V_227 = V_97 ;
F_191 ( V_7 ) ;
}
void F_205 ( struct V_3 * V_4 , unsigned long V_262 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
F_91 ( V_7 , ( ( V_262 & 0x0f ) << 4 )
| ( F_16 ( V_7 , V_113 ) & 4 ) ) ;
}
V_37 F_206 ( struct V_3 * V_4 )
{
V_37 V_108 ;
V_108 = ( V_37 ) F_16 ( V_4 -> V_8 . V_7 , V_113 ) ;
return ( V_108 & 0xf0 ) >> 4 ;
}
void F_207 ( struct V_3 * V_4 , V_37 V_263 )
{
V_37 V_264 = V_4 -> V_8 . V_259 ;
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
if ( ! V_7 )
V_263 |= V_265 ;
V_4 -> V_8 . V_259 = V_263 ;
if ( ( V_264 ^ V_263 ) & V_260 )
F_208 ( V_4 ) ;
if ( ! V_7 )
return;
if ( ( V_264 ^ V_263 ) & V_260 ) {
if ( V_263 & V_260 ) {
F_42 ( V_7 , V_4 -> V_13 ) ;
F_40 ( & V_261 ) ;
} else {
F_41 ( & V_261 . V_53 ) ;
F_23 ( V_4 -> V_31 ) ;
}
}
if ( ( V_264 ^ V_263 ) & V_266 ) {
if ( V_263 & V_266 ) {
F_44 ( V_7 , V_4 -> V_13 ) ;
V_85 -> V_267 ( V_4 , true ) ;
} else
V_85 -> V_267 ( V_4 , false ) ;
}
V_7 -> V_209 = V_7 -> V_4 -> V_8 . V_259 &
V_268 ;
if ( ( V_263 & V_260 ) &&
V_7 -> V_209 != V_269 )
F_209 ( L_39 ) ;
F_81 ( L_40 V_240 L_41
L_42 , V_7 -> V_4 -> V_8 . V_259 , V_7 -> V_209 ) ;
}
void F_210 ( struct V_3 * V_4 , bool V_270 )
{
struct V_6 * V_7 ;
int V_34 ;
F_81 ( L_43 , V_241 ) ;
ASSERT ( V_4 ) ;
V_7 = V_4 -> V_8 . V_7 ;
ASSERT ( V_7 != NULL ) ;
F_151 ( & V_7 -> V_58 . V_219 ) ;
if ( ! V_270 ) {
F_207 ( V_4 , V_269 |
V_260 ) ;
F_42 ( V_7 , V_4 -> V_13 ) ;
}
F_52 ( V_7 -> V_4 ) ;
for ( V_34 = 0 ; V_34 < V_250 ; V_34 ++ )
F_39 ( V_7 , V_217 + 0x10 * V_34 , V_56 ) ;
F_150 ( V_7 ) ;
if ( F_211 ( V_4 ) &&
F_212 ( V_4 -> V_31 , V_271 ) )
F_39 ( V_7 , V_251 ,
F_213 ( 0 , V_272 ) ) ;
F_193 ( V_7 , F_16 ( V_7 , V_251 ) ) ;
F_39 ( V_7 , V_44 , 0xffffffffU ) ;
F_38 ( V_7 , 0xff ) ;
F_39 ( V_7 , V_113 , 0 ) ;
if ( ! F_29 ( V_7 ) )
F_43 ( V_7 , 0 ) ;
F_39 ( V_7 , V_257 , 0 ) ;
F_39 ( V_7 , V_175 , 0 ) ;
F_39 ( V_7 , V_177 , 0 ) ;
F_39 ( V_7 , V_216 , 0 ) ;
F_39 ( V_7 , V_187 , 0 ) ;
for ( V_34 = 0 ; V_34 < 8 ; V_34 ++ ) {
F_39 ( V_7 , V_11 + 0x10 * V_34 , 0 ) ;
F_39 ( V_7 , V_10 + 0x10 * V_34 , 0 ) ;
F_39 ( V_7 , V_150 + 0x10 * V_34 , 0 ) ;
}
V_7 -> V_83 = V_4 -> V_8 . V_84 ;
V_7 -> V_88 = V_4 -> V_8 . V_84 ? 1 : 0 ;
V_7 -> V_89 = - 1 ;
F_149 ( V_7 ) ;
F_192 ( & V_7 -> V_58 . V_225 , 0 ) ;
if ( F_214 ( V_4 ) )
F_207 ( V_4 ,
V_4 -> V_8 . V_259 | V_265 ) ;
V_4 -> V_8 . V_96 . V_98 = 0 ;
F_88 ( V_7 ) ;
V_4 -> V_8 . V_147 = 0 ;
V_4 -> V_8 . V_102 = 0 ;
F_81 ( L_44
L_45 V_240 L_46 , V_241 ,
V_4 , F_16 ( V_7 , V_12 ) ,
V_4 -> V_8 . V_259 , V_7 -> V_209 ) ;
}
static bool F_215 ( struct V_6 * V_7 )
{
return F_49 ( V_7 ) ;
}
int F_216 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
if ( F_12 ( V_7 ) && F_46 ( V_7 , V_217 ) )
return F_153 ( & V_7 -> V_58 . V_225 ) ;
return 0 ;
}
int F_217 ( struct V_6 * V_7 , int V_55 )
{
T_2 V_74 = F_16 ( V_7 , V_55 ) ;
int V_5 , V_19 , V_95 ;
if ( F_14 ( V_7 ) && ! ( V_74 & V_56 ) ) {
V_5 = V_74 & V_57 ;
V_19 = V_74 & V_64 ;
V_95 = V_74 & V_273 ;
return F_74 ( V_7 , V_19 , V_5 , 1 , V_95 ,
NULL ) ;
}
return 0 ;
}
void F_218 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
if ( V_7 )
F_217 ( V_7 , V_251 ) ;
}
static enum V_274 F_219 ( struct V_275 * V_97 )
{
struct V_223 * V_224 = F_21 ( V_97 , struct V_223 , V_219 ) ;
struct V_6 * V_7 = F_21 ( V_224 , struct V_6 , V_58 ) ;
F_152 ( V_7 ) ;
if ( F_215 ( V_7 ) ) {
F_176 ( V_7 ) ;
F_220 ( & V_224 -> V_219 , V_224 -> V_188 ) ;
return V_276 ;
} else
return V_277 ;
}
int F_221 ( struct V_3 * V_4 )
{
struct V_6 * V_7 ;
ASSERT ( V_4 != NULL ) ;
F_81 ( L_47 , V_4 -> V_13 ) ;
V_7 = F_222 ( sizeof( * V_7 ) , V_38 ) ;
if ( ! V_7 )
goto V_278;
V_4 -> V_8 . V_7 = V_7 ;
V_7 -> V_9 = ( void * ) F_223 ( V_38 ) ;
if ( ! V_7 -> V_9 ) {
F_100 ( V_164 L_48 ,
V_4 -> V_13 ) ;
goto V_279;
}
V_7 -> V_4 = V_4 ;
F_224 ( & V_7 -> V_58 . V_219 , V_280 ,
V_235 ) ;
V_7 -> V_58 . V_219 . V_281 = F_219 ;
V_4 -> V_8 . V_259 = V_260 ;
F_41 ( & V_52 . V_53 ) ;
F_210 ( V_4 , false ) ;
F_225 ( & V_7 -> V_204 , & V_282 ) ;
return 0 ;
V_279:
F_202 ( V_7 ) ;
V_278:
return - V_283 ;
}
int F_226 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
T_2 V_104 ;
if ( ! F_12 ( V_7 ) )
return - 1 ;
F_87 ( V_7 , & V_104 ) ;
return F_86 ( V_7 , V_104 ) ;
}
int F_227 ( struct V_3 * V_4 )
{
T_2 V_284 = F_16 ( V_4 -> V_8 . V_7 , V_251 ) ;
int V_143 = 0 ;
if ( ! F_14 ( V_4 -> V_8 . V_7 ) )
V_143 = 1 ;
if ( ( V_284 & V_56 ) == 0 &&
F_228 ( V_284 ) == V_272 )
V_143 = 1 ;
return V_143 ;
}
void F_229 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
if ( F_153 ( & V_7 -> V_58 . V_225 ) > 0 ) {
F_217 ( V_7 , V_217 ) ;
if ( F_50 ( V_7 ) )
V_7 -> V_58 . V_227 = 0 ;
if ( F_48 ( V_7 ) ) {
V_7 -> V_58 . V_227 = 0 ;
V_7 -> V_58 . V_189 = 0 ;
}
F_192 ( & V_7 -> V_58 . V_225 , 0 ) ;
}
}
int F_230 ( struct V_3 * V_4 )
{
int V_5 = F_226 ( V_4 ) ;
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
T_2 V_104 ;
if ( V_5 == - 1 )
return - 1 ;
F_65 ( V_5 , V_7 ) ;
if ( F_2 ( V_5 , F_127 ( V_4 ) -> V_285 ) ) {
F_88 ( V_7 ) ;
} else {
F_67 ( V_5 , V_7 ) ;
F_87 ( V_7 , & V_104 ) ;
}
return V_5 ;
}
static int F_231 ( struct V_3 * V_4 ,
struct V_286 * V_287 , bool V_288 )
{
if ( F_29 ( V_4 -> V_8 . V_7 ) ) {
T_2 * V_54 = ( T_2 * ) ( V_287 -> V_9 + V_12 ) ;
if ( V_4 -> V_31 -> V_8 . V_289 ) {
if ( * V_54 != V_4 -> V_13 )
return - V_290 ;
} else {
if ( V_288 )
* V_54 >>= 24 ;
else
* V_54 <<= 24 ;
}
}
return 0 ;
}
int F_232 ( struct V_3 * V_4 , struct V_286 * V_287 )
{
memcpy ( V_287 -> V_9 , V_4 -> V_8 . V_7 -> V_9 , sizeof( * V_287 ) ) ;
return F_231 ( V_4 , V_287 , false ) ;
}
int F_233 ( struct V_3 * V_4 , struct V_286 * V_287 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
int V_143 ;
F_207 ( V_4 , V_4 -> V_8 . V_259 ) ;
F_38 ( V_7 , * ( ( T_2 * ) ( V_287 -> V_9 + V_50 ) ) ) ;
V_143 = F_231 ( V_4 , V_287 , true ) ;
if ( V_143 )
return V_143 ;
memcpy ( V_4 -> V_8 . V_7 -> V_9 , V_287 -> V_9 , sizeof *V_287 ) ;
F_23 ( V_4 -> V_31 ) ;
F_52 ( V_4 ) ;
F_88 ( V_7 ) ;
F_151 ( & V_7 -> V_58 . V_219 ) ;
F_150 ( V_7 ) ;
F_193 ( V_7 , F_16 ( V_7 , V_251 ) ) ;
F_149 ( V_7 ) ;
F_191 ( V_7 ) ;
V_7 -> V_83 = true ;
V_7 -> V_88 = V_4 -> V_8 . V_84 ?
1 : F_57 ( V_7 -> V_9 + V_10 ) ;
V_7 -> V_89 = - 1 ;
if ( V_4 -> V_8 . V_84 ) {
V_85 -> V_291 ( V_4 ) ;
V_85 -> V_86 ( V_4 ,
F_64 ( V_7 ) ) ;
V_85 -> V_87 ( V_4 ,
F_69 ( V_7 ) ) ;
}
F_89 ( V_114 , V_4 ) ;
if ( F_234 ( V_4 -> V_31 ) )
F_235 ( V_4 ) ;
V_4 -> V_8 . V_147 = 0 ;
return 0 ;
}
void F_236 ( struct V_3 * V_4 )
{
struct V_275 * V_219 ;
if ( ! F_53 ( V_4 ) )
return;
V_219 = & V_4 -> V_8 . V_7 -> V_58 . V_219 ;
if ( F_151 ( V_219 ) )
F_237 ( V_219 , V_235 ) ;
}
static void F_238 ( struct V_3 * V_4 ,
struct V_6 * V_7 )
{
bool V_225 ;
int V_5 ;
F_68 ( ! F_79 ( V_4 ) ) ;
V_225 = F_80 ( V_4 ) ;
F_84 ( V_4 ) ;
if ( V_225 )
return;
V_5 = F_125 ( V_7 ) ;
F_239 ( V_7 , V_5 ) ;
}
void F_240 ( struct V_3 * V_4 )
{
T_2 V_97 ;
if ( F_2 ( V_101 , & V_4 -> V_8 . V_102 ) )
F_238 ( V_4 , V_4 -> V_8 . V_7 ) ;
if ( ! F_2 ( V_292 , & V_4 -> V_8 . V_102 ) )
return;
if ( F_78 ( V_4 -> V_31 , & V_4 -> V_8 . V_7 -> V_293 , & V_97 ,
sizeof( T_2 ) ) )
return;
F_91 ( V_4 -> V_8 . V_7 , V_97 & 0xff ) ;
}
static void F_241 ( struct V_3 * V_4 ,
struct V_6 * V_7 )
{
if ( ! F_79 ( V_4 ) ||
V_7 -> V_83 ||
V_7 -> V_89 == - 1 ||
F_121 ( V_7 , V_7 -> V_89 ) ) {
return;
}
F_82 ( V_7 -> V_4 ) ;
}
void F_242 ( struct V_3 * V_4 )
{
T_2 V_97 , V_108 ;
int V_81 , V_294 ;
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
F_241 ( V_4 , V_7 ) ;
if ( ! F_2 ( V_292 , & V_4 -> V_8 . V_102 ) )
return;
V_108 = F_16 ( V_7 , V_113 ) & 0xff ;
V_81 = F_64 ( V_7 ) ;
if ( V_81 < 0 )
V_81 = 0 ;
V_294 = F_69 ( V_7 ) ;
if ( V_294 < 0 )
V_294 = 0 ;
V_97 = ( V_108 & 0xff ) | ( ( V_294 & 0xf0 ) << 8 ) | ( V_81 << 24 ) ;
F_76 ( V_4 -> V_31 , & V_4 -> V_8 . V_7 -> V_293 , & V_97 ,
sizeof( T_2 ) ) ;
}
int F_243 ( struct V_3 * V_4 , T_6 V_295 )
{
if ( V_295 ) {
if ( F_244 ( V_4 -> V_31 ,
& V_4 -> V_8 . V_7 -> V_293 ,
V_295 , sizeof( T_2 ) ) )
return - V_290 ;
F_83 ( V_292 , & V_4 -> V_8 . V_102 ) ;
} else {
F_85 ( V_292 , & V_4 -> V_8 . V_102 ) ;
}
V_4 -> V_8 . V_7 -> V_295 = V_295 ;
return 0 ;
}
int F_245 ( struct V_3 * V_4 , T_2 V_296 , V_37 V_97 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
T_2 V_74 = ( V_296 - V_297 ) << 4 ;
if ( ! F_53 ( V_4 ) || ! F_29 ( V_7 ) )
return 1 ;
if ( V_74 == V_177 )
return 1 ;
if ( V_74 == V_175 )
F_195 ( V_7 , V_177 , ( T_2 ) ( V_97 >> 32 ) ) ;
return F_195 ( V_7 , V_74 , ( T_2 ) V_97 ) ;
}
int F_246 ( struct V_3 * V_4 , T_2 V_296 , V_37 * V_97 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
T_2 V_74 = ( V_296 - V_297 ) << 4 , V_298 , V_299 = 0 ;
if ( ! F_53 ( V_4 ) || ! F_29 ( V_7 ) )
return 1 ;
if ( V_74 == V_44 || V_74 == V_177 ) {
F_81 ( L_49 ,
V_74 ) ;
return 1 ;
}
if ( F_145 ( V_7 , V_74 , 4 , & V_298 ) )
return 1 ;
if ( V_74 == V_175 )
F_145 ( V_7 , V_177 , 4 , & V_299 ) ;
* V_97 = ( ( ( V_37 ) V_299 ) << 32 ) | V_298 ;
return 0 ;
}
int F_247 ( struct V_3 * V_4 , T_2 V_74 , V_37 V_97 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
if ( ! F_53 ( V_4 ) )
return 1 ;
if ( V_74 == V_175 )
F_195 ( V_7 , V_177 , ( T_2 ) ( V_97 >> 32 ) ) ;
return F_195 ( V_7 , V_74 , ( T_2 ) V_97 ) ;
}
int F_248 ( struct V_3 * V_4 , T_2 V_74 , V_37 * V_97 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
T_2 V_298 , V_299 = 0 ;
if ( ! F_53 ( V_4 ) )
return 1 ;
if ( F_145 ( V_7 , V_74 , 4 , & V_298 ) )
return 1 ;
if ( V_74 == V_175 )
F_145 ( V_7 , V_177 , 4 , & V_299 ) ;
* V_97 = ( ( ( V_37 ) V_299 ) << 32 ) | V_298 ;
return 0 ;
}
int F_249 ( struct V_3 * V_4 , V_37 V_97 )
{
V_37 V_208 = V_97 & ~ V_99 ;
if ( ! F_250 ( V_208 , 4 ) )
return 1 ;
V_4 -> V_8 . V_96 . V_98 = V_97 ;
if ( ! F_79 ( V_4 ) )
return 0 ;
return F_244 ( V_4 -> V_31 , & V_4 -> V_8 . V_96 . V_97 ,
V_208 , sizeof( T_1 ) ) ;
}
void F_251 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
T_1 V_161 ;
unsigned long V_300 ;
if ( ! F_53 ( V_4 ) || ! V_7 -> V_158 )
return;
if ( F_252 ( V_4 ) ) {
F_45 ( V_4 -> V_8 . V_301 == V_302 ) ;
if ( F_2 ( V_162 , & V_7 -> V_158 ) )
F_7 ( V_162 , & V_7 -> V_158 ) ;
return;
}
V_300 = F_61 ( & V_7 -> V_158 , 0 ) ;
if ( F_2 ( V_159 , & V_300 ) ) {
F_210 ( V_4 , true ) ;
F_253 ( V_4 , true ) ;
if ( F_214 ( V_7 -> V_4 ) )
V_4 -> V_8 . V_301 = V_303 ;
else
V_4 -> V_8 . V_301 = V_302 ;
}
if ( F_2 ( V_162 , & V_300 ) &&
V_4 -> V_8 . V_301 == V_302 ) {
F_254 () ;
V_161 = V_7 -> V_161 ;
F_81 ( L_50 ,
V_4 -> V_13 , V_161 ) ;
F_255 ( V_4 , V_161 ) ;
V_4 -> V_8 . V_301 = V_303 ;
}
}
void F_256 ( void )
{
F_257 ( & V_261 , V_304 ) ;
F_257 ( & V_52 , V_304 ) ;
}
void F_258 ( void )
{
F_259 ( & V_261 ) ;
F_259 ( & V_52 ) ;
}
