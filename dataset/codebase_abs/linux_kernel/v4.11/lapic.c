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
sizeof( struct V_6 * ) * ( ( V_37 ) V_35 + 1 ) ) ;
if ( ! V_32 )
goto V_38;
V_32 -> V_22 = V_35 ;
F_25 (i, vcpu, kvm) {
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
struct V_6 * * V_17 ;
T_3 V_18 ;
T_2 V_39 ;
T_1 V_40 ;
T_2 V_41 ;
if ( ! F_26 ( V_4 ) )
continue;
V_40 = F_15 ( V_7 ) ;
V_41 = F_17 ( V_7 ) ;
if ( ( F_29 ( V_7 ) || V_41 > 0xff ) &&
V_41 <= V_32 -> V_22 )
V_32 -> V_24 [ V_41 ] = V_7 ;
if ( ! F_29 ( V_7 ) && ! V_32 -> V_24 [ V_40 ] )
V_32 -> V_24 [ V_40 ] = V_7 ;
V_39 = F_16 ( V_7 , V_42 ) ;
if ( F_29 ( V_7 ) ) {
V_32 -> V_19 |= V_20 ;
} else if ( V_39 ) {
V_39 = F_30 ( V_39 ) ;
if ( F_16 ( V_7 , V_43 ) == V_44 )
V_32 -> V_19 |= V_25 ;
else
V_32 -> V_19 |= V_27 ;
}
if ( ! F_18 ( V_32 , V_39 , & V_17 , & V_18 ) )
continue;
if ( V_18 )
V_17 [ F_31 ( V_18 ) - 1 ] = V_7 ;
}
V_38:
V_33 = F_32 ( V_31 -> V_8 . V_45 ,
F_33 ( & V_31 -> V_8 . V_36 ) ) ;
F_34 ( V_31 -> V_8 . V_45 , V_32 ) ;
F_35 ( & V_31 -> V_8 . V_36 ) ;
if ( V_33 )
F_36 ( & V_33 -> V_30 , F_20 ) ;
F_37 ( V_31 ) ;
}
static inline void F_38 ( struct V_6 * V_7 , T_2 V_46 )
{
bool V_47 = V_46 & V_48 ;
F_39 ( V_7 , V_49 , V_46 ) ;
if ( V_47 != V_7 -> V_50 ) {
V_7 -> V_50 = V_47 ;
if ( V_47 ) {
F_40 ( & V_51 ) ;
F_23 ( V_7 -> V_4 -> V_31 ) ;
} else
F_41 ( & V_51 . V_52 ) ;
}
}
static inline void F_42 ( struct V_6 * V_7 , T_1 V_53 )
{
F_39 ( V_7 , V_12 , V_53 << 24 ) ;
F_23 ( V_7 -> V_4 -> V_31 ) ;
}
static inline void F_43 ( struct V_6 * V_7 , T_2 V_53 )
{
F_39 ( V_7 , V_42 , V_53 ) ;
F_23 ( V_7 -> V_4 -> V_31 ) ;
}
static inline void F_44 ( struct V_6 * V_7 , T_2 V_53 )
{
T_2 V_39 = ( ( V_53 >> 4 ) << 16 ) | ( 1 << ( V_53 & 0xf ) ) ;
F_45 ( V_53 != V_7 -> V_4 -> V_13 ) ;
F_39 ( V_7 , V_12 , V_53 ) ;
F_39 ( V_7 , V_42 , V_39 ) ;
F_23 ( V_7 -> V_4 -> V_31 ) ;
}
static inline int F_46 ( struct V_6 * V_7 , int V_54 )
{
return ! ( F_16 ( V_7 , V_54 ) & V_55 ) ;
}
static inline int F_47 ( struct V_6 * V_7 , int V_54 )
{
return F_16 ( V_7 , V_54 ) & V_56 ;
}
static inline int F_48 ( struct V_6 * V_7 )
{
return V_7 -> V_57 . V_58 == V_59 ;
}
static inline int F_49 ( struct V_6 * V_7 )
{
return V_7 -> V_57 . V_58 == V_60 ;
}
static inline int F_50 ( struct V_6 * V_7 )
{
return V_7 -> V_57 . V_58 == V_61 ;
}
static inline int F_51 ( T_2 V_62 )
{
return ( V_62 & ( V_63 | V_55 ) ) == V_64 ;
}
void F_52 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
struct V_65 * V_66 ;
T_2 V_67 = V_68 ;
if ( ! F_53 ( V_4 ) )
return;
V_66 = F_54 ( V_7 -> V_4 , 0x1 , 0 ) ;
if ( V_66 && ( V_66 -> V_69 & ( 1 << ( V_70 & 31 ) ) ) )
V_67 |= V_71 ;
F_39 ( V_7 , V_72 , V_67 ) ;
}
static int F_55 ( void * V_2 )
{
int V_1 ;
T_2 * V_73 ;
for ( V_1 = V_74 - V_75 ;
V_1 >= 0 ; V_1 -= V_75 ) {
V_73 = V_2 + F_4 ( V_1 ) ;
if ( * V_73 )
return F_56 ( * V_73 ) + V_1 ;
}
return - 1 ;
}
static T_1 F_57 ( void * V_2 )
{
int V_1 ;
T_2 * V_73 ;
T_1 V_76 = 0 ;
for ( V_1 = 0 ; V_1 < V_74 ; V_1 += V_75 ) {
V_73 = V_2 + F_4 ( V_1 ) ;
V_76 += F_58 ( * V_73 ) ;
}
return V_76 ;
}
int F_59 ( T_2 * V_77 , void * V_9 )
{
T_2 V_34 , V_1 ;
T_2 V_78 , V_79 ;
int V_80 = - 1 ;
for ( V_34 = V_1 = 0 ; V_34 <= 7 ; V_34 ++ , V_1 += 32 ) {
V_78 = F_60 ( V_77 [ V_34 ] ) ;
V_79 = * ( ( T_2 * ) ( V_9 + V_11 + V_34 * 0x10 ) ) ;
if ( V_78 ) {
V_79 |= F_61 ( & V_77 [ V_34 ] , 0 ) ;
* ( ( T_2 * ) ( V_9 + V_11 + V_34 * 0x10 ) ) = V_79 ;
}
if ( V_79 )
V_80 = F_56 ( V_79 ) + V_1 ;
}
return V_80 ;
}
int F_62 ( struct V_3 * V_4 , T_2 * V_77 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
return F_59 ( V_77 , V_7 -> V_9 ) ;
}
static inline int F_63 ( struct V_6 * V_7 )
{
return F_55 ( V_7 -> V_9 + V_11 ) ;
}
static inline int F_64 ( struct V_6 * V_7 )
{
int V_81 ;
if ( ! V_7 -> V_82 )
return - 1 ;
V_81 = F_63 ( V_7 ) ;
ASSERT ( V_81 == - 1 || V_81 >= 16 ) ;
return V_81 ;
}
static inline void F_65 ( int V_1 , struct V_6 * V_7 )
{
struct V_3 * V_4 ;
V_4 = V_7 -> V_4 ;
if ( F_66 ( V_4 -> V_8 . V_83 ) ) {
F_6 ( V_1 , V_7 -> V_9 + V_11 ) ;
V_84 -> V_85 ( V_4 ,
F_64 ( V_7 ) ) ;
} else {
V_7 -> V_82 = false ;
F_6 ( V_1 , V_7 -> V_9 + V_11 ) ;
if ( F_63 ( V_7 ) != - 1 )
V_7 -> V_82 = true ;
}
}
static inline void F_67 ( int V_1 , struct V_6 * V_7 )
{
struct V_3 * V_4 ;
if ( F_8 ( V_1 , V_7 -> V_9 + V_10 ) )
return;
V_4 = V_7 -> V_4 ;
if ( F_66 ( V_4 -> V_8 . V_83 ) )
V_84 -> V_86 ( V_4 , V_1 ) ;
else {
++ V_7 -> V_87 ;
F_68 ( V_7 -> V_87 > V_74 ) ;
V_7 -> V_88 = V_1 ;
}
}
static inline int F_69 ( struct V_6 * V_7 )
{
int V_81 ;
if ( ! V_7 -> V_87 )
return - 1 ;
if ( F_70 ( V_7 -> V_88 != - 1 ) )
return V_7 -> V_88 ;
V_81 = F_55 ( V_7 -> V_9 + V_10 ) ;
ASSERT ( V_81 == - 1 || V_81 >= 16 ) ;
return V_81 ;
}
static inline void F_71 ( int V_1 , struct V_6 * V_7 )
{
struct V_3 * V_4 ;
if ( ! F_10 ( V_1 , V_7 -> V_9 + V_10 ) )
return;
V_4 = V_7 -> V_4 ;
if ( F_66 ( V_4 -> V_8 . V_83 ) )
V_84 -> V_86 ( V_4 ,
F_69 ( V_7 ) ) ;
else {
-- V_7 -> V_87 ;
F_68 ( V_7 -> V_87 < 0 ) ;
V_7 -> V_88 = - 1 ;
}
}
int F_72 ( struct V_3 * V_4 )
{
return F_64 ( V_4 -> V_8 . V_7 ) ;
}
int F_73 ( struct V_3 * V_4 , struct V_89 * V_90 ,
struct V_91 * V_91 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
return F_74 ( V_7 , V_90 -> V_92 , V_90 -> V_5 ,
V_90 -> V_93 , V_90 -> V_94 , V_91 ) ;
}
static int F_75 ( struct V_3 * V_4 , T_1 V_46 )
{
return F_76 ( V_4 , & V_4 -> V_8 . V_95 . V_96 , & V_46 ,
sizeof( V_46 ) ) ;
}
static int F_77 ( struct V_3 * V_4 , T_1 * V_46 )
{
return F_78 ( V_4 , & V_4 -> V_8 . V_95 . V_96 , V_46 ,
sizeof( * V_46 ) ) ;
}
static inline bool F_79 ( struct V_3 * V_4 )
{
return V_4 -> V_8 . V_95 . V_97 & V_98 ;
}
static bool F_80 ( struct V_3 * V_4 )
{
T_1 V_46 ;
if ( F_77 ( V_4 , & V_46 ) < 0 )
F_81 ( L_1 ,
( unsigned long long ) V_4 -> V_8 . V_95 . V_97 ) ;
return V_46 & 0x1 ;
}
static void F_82 ( struct V_3 * V_4 )
{
if ( F_75 ( V_4 , V_99 ) < 0 ) {
F_81 ( L_2 ,
( unsigned long long ) V_4 -> V_8 . V_95 . V_97 ) ;
return;
}
F_83 ( V_100 , & V_4 -> V_8 . V_101 ) ;
}
static void F_84 ( struct V_3 * V_4 )
{
if ( F_75 ( V_4 , V_102 ) < 0 ) {
F_81 ( L_3 ,
( unsigned long long ) V_4 -> V_8 . V_95 . V_97 ) ;
return;
}
F_85 ( V_100 , & V_4 -> V_8 . V_101 ) ;
}
static int F_86 ( struct V_6 * V_7 , T_2 V_103 )
{
int V_104 ;
if ( V_84 -> V_105 && V_7 -> V_4 -> V_8 . V_83 )
V_104 = V_84 -> V_105 ( V_7 -> V_4 ) ;
else
V_104 = F_64 ( V_7 ) ;
if ( V_104 == - 1 || ( V_104 & 0xF0 ) <= V_103 )
return - 1 ;
return V_104 ;
}
static bool F_87 ( struct V_6 * V_7 , T_2 * V_106 )
{
T_2 V_107 , V_108 , V_103 , V_109 ;
int V_110 ;
V_109 = F_16 ( V_7 , V_111 ) ;
V_107 = F_16 ( V_7 , V_112 ) ;
V_110 = F_69 ( V_7 ) ;
V_108 = ( V_110 != - 1 ) ? V_110 : 0 ;
if ( ( V_107 & 0xf0 ) >= ( V_108 & 0xf0 ) )
V_103 = V_107 & 0xff ;
else
V_103 = V_108 & 0xf0 ;
F_81 ( L_4 ,
V_7 , V_103 , V_110 , V_108 ) ;
* V_106 = V_103 ;
if ( V_109 != V_103 )
F_39 ( V_7 , V_111 , V_103 ) ;
return V_103 < V_109 ;
}
static void F_88 ( struct V_6 * V_7 )
{
T_2 V_103 ;
if ( F_87 ( V_7 , & V_103 ) &&
F_86 ( V_7 , V_103 ) != - 1 )
F_89 ( V_113 , V_7 -> V_4 ) ;
}
void F_90 ( struct V_3 * V_4 )
{
F_88 ( V_4 -> V_8 . V_7 ) ;
}
static void F_91 ( struct V_6 * V_7 , T_2 V_107 )
{
F_39 ( V_7 , V_112 , V_107 ) ;
F_88 ( V_7 ) ;
}
static bool F_92 ( struct V_6 * V_7 , T_2 V_114 )
{
return V_114 == ( F_29 ( V_7 ) ?
V_115 : V_116 ) ;
}
static bool F_93 ( struct V_6 * V_7 , T_2 V_114 )
{
if ( F_92 ( V_7 , V_114 ) )
return true ;
if ( F_29 ( V_7 ) )
return V_114 == F_17 ( V_7 ) ;
if ( F_17 ( V_7 ) > 0xff && V_114 == F_17 ( V_7 ) )
return true ;
return V_114 == F_15 ( V_7 ) ;
}
static bool F_94 ( struct V_6 * V_7 , T_2 V_114 )
{
T_2 V_117 ;
if ( F_92 ( V_7 , V_114 ) )
return true ;
V_117 = F_16 ( V_7 , V_42 ) ;
if ( F_29 ( V_7 ) )
return ( ( V_117 >> 16 ) == ( V_114 >> 16 ) )
&& ( V_117 & V_114 & 0xffff ) != 0 ;
V_117 = F_30 ( V_117 ) ;
switch ( F_16 ( V_7 , V_43 ) ) {
case V_44 :
return ( V_117 & V_114 ) != 0 ;
case V_118 :
return ( ( V_117 >> 4 ) == ( V_114 >> 4 ) )
&& ( V_117 & V_114 & 0xf ) != 0 ;
default:
F_81 ( L_5 ,
V_7 -> V_4 -> V_13 , F_16 ( V_7 , V_43 ) ) ;
return false ;
}
}
static T_2 F_95 ( struct V_3 * V_4 , unsigned int V_16 ,
struct V_6 * V_119 , struct V_6 * V_120 )
{
bool V_121 = V_119 != NULL ;
if ( ! V_4 -> V_31 -> V_8 . V_122 &&
! V_121 && V_16 == V_116 && F_29 ( V_120 ) )
return V_115 ;
return V_16 ;
}
bool F_96 ( struct V_3 * V_4 , struct V_6 * V_119 ,
int V_123 , unsigned int V_124 , int V_125 )
{
struct V_6 * V_120 = V_4 -> V_8 . V_7 ;
T_2 V_114 = F_95 ( V_4 , V_124 , V_119 , V_120 ) ;
F_81 ( L_6
L_7 ,
V_120 , V_119 , V_124 , V_125 , V_123 ) ;
ASSERT ( V_120 ) ;
switch ( V_123 ) {
case V_126 :
if ( V_125 == V_127 )
return F_93 ( V_120 , V_114 ) ;
else
return F_94 ( V_120 , V_114 ) ;
case V_128 :
return V_120 == V_119 ;
case V_129 :
return true ;
case V_130 :
return V_120 != V_119 ;
default:
F_81 ( L_8 ,
V_123 ) ;
return false ;
}
}
int F_97 ( T_2 V_5 , T_2 V_131 ,
const unsigned long * V_2 , T_2 V_132 )
{
T_2 V_133 ;
int V_34 , V_134 = - 1 ;
V_133 = V_5 % V_131 ;
for ( V_34 = 0 ; V_34 <= V_133 ; V_34 ++ ) {
V_134 = F_98 ( V_2 , V_132 , V_134 + 1 ) ;
F_68 ( V_134 == V_132 ) ;
}
return V_134 ;
}
static void F_99 ( struct V_31 * V_31 )
{
if ( ! V_31 -> V_8 . V_135 ) {
V_31 -> V_8 . V_135 = true ;
F_100 ( V_136
L_9 ) ;
}
}
static bool F_101 ( struct V_31 * V_31 , struct V_6 * * V_137 ,
struct V_89 * V_90 , struct V_14 * V_15 )
{
if ( V_31 -> V_8 . V_122 ) {
if ( ( V_90 -> V_16 == V_116 &&
V_15 -> V_19 != V_20 ) )
return true ;
if ( V_90 -> V_16 == V_115 )
return true ;
} else {
bool V_138 = V_137 && * V_137 && F_29 ( * V_137 ) ;
if ( V_90 -> V_16 == ( V_138 ?
V_115 : V_116 ) )
return true ;
}
return false ;
}
static inline bool F_102 ( struct V_31 * V_31 ,
struct V_6 * * V_137 , struct V_89 * V_90 ,
struct V_14 * V_15 , struct V_6 * * * V_139 ,
unsigned long * V_2 )
{
int V_34 , V_140 ;
if ( V_90 -> V_141 == V_128 && V_137 ) {
* V_139 = V_137 ;
* V_2 = 1 ;
return true ;
} else if ( V_90 -> V_141 )
return false ;
if ( ! V_15 || F_101 ( V_31 , V_137 , V_90 , V_15 ) )
return false ;
if ( V_90 -> V_125 == V_127 ) {
if ( V_90 -> V_16 > V_15 -> V_22 ) {
* V_2 = 0 ;
} else {
* V_139 = & V_15 -> V_24 [ V_90 -> V_16 ] ;
* V_2 = 1 ;
}
return true ;
}
* V_2 = 0 ;
if ( ! F_18 ( V_15 , V_90 -> V_16 , V_139 ,
( T_3 * ) V_2 ) )
return false ;
if ( ! F_103 ( V_90 ) )
return true ;
if ( ! F_104 () ) {
V_140 = - 1 ;
F_105 (i, bitmap, 16 ) {
if ( ! ( * V_139 ) [ V_34 ] )
continue;
if ( V_140 < 0 )
V_140 = V_34 ;
else if ( F_106 ( ( * V_139 ) [ V_34 ] -> V_4 ,
( * V_139 ) [ V_140 ] -> V_4 ) < 0 )
V_140 = V_34 ;
}
} else {
if ( ! * V_2 )
return true ;
V_140 = F_97 ( V_90 -> V_5 , F_107 ( * V_2 ) ,
V_2 , 16 ) ;
if ( ! ( * V_139 ) [ V_140 ] ) {
F_99 ( V_31 ) ;
* V_2 = 0 ;
return true ;
}
}
* V_2 = ( V_140 >= 0 ) ? 1 << V_140 : 0 ;
return true ;
}
bool F_108 ( struct V_31 * V_31 , struct V_6 * V_137 ,
struct V_89 * V_90 , int * V_142 , struct V_91 * V_91 )
{
struct V_14 * V_15 ;
unsigned long V_2 ;
struct V_6 * * V_139 = NULL ;
int V_34 ;
bool V_143 ;
* V_142 = - 1 ;
if ( V_90 -> V_141 == V_128 ) {
* V_142 = F_73 ( V_137 -> V_4 , V_90 , V_91 ) ;
return true ;
}
F_109 () ;
V_15 = F_110 ( V_31 -> V_8 . V_45 ) ;
V_143 = F_102 ( V_31 , & V_137 , V_90 , V_15 , & V_139 , & V_2 ) ;
if ( V_143 )
F_105 (i, &bitmap, 16 ) {
if ( ! V_139 [ V_34 ] )
continue;
if ( * V_142 < 0 )
* V_142 = 0 ;
* V_142 += F_73 ( V_139 [ V_34 ] -> V_4 , V_90 , V_91 ) ;
}
F_111 () ;
return V_143 ;
}
bool F_112 ( struct V_31 * V_31 , struct V_89 * V_90 ,
struct V_3 * * V_144 )
{
struct V_14 * V_15 ;
unsigned long V_2 ;
struct V_6 * * V_139 = NULL ;
bool V_143 = false ;
if ( V_90 -> V_141 )
return false ;
F_109 () ;
V_15 = F_110 ( V_31 -> V_8 . V_45 ) ;
if ( F_102 ( V_31 , NULL , V_90 , V_15 , & V_139 , & V_2 ) &&
F_107 ( V_2 ) == 1 ) {
unsigned long V_34 = F_113 ( & V_2 , 16 ) ;
if ( V_139 [ V_34 ] ) {
* V_144 = V_139 [ V_34 ] -> V_4 ;
V_143 = true ;
}
}
F_111 () ;
return V_143 ;
}
static int F_74 ( struct V_6 * V_7 , int V_92 ,
int V_5 , int V_93 , int V_94 ,
struct V_91 * V_91 )
{
int V_81 = 0 ;
struct V_3 * V_4 = V_7 -> V_4 ;
F_114 ( V_4 -> V_13 , V_92 ,
V_94 , V_5 ) ;
switch ( V_92 ) {
case V_145 :
V_4 -> V_8 . V_146 ++ ;
case V_147 :
if ( F_66 ( V_94 && ! V_93 ) )
break;
if ( F_66 ( ! F_12 ( V_7 ) ) )
break;
V_81 = 1 ;
if ( V_91 ) {
F_83 ( V_4 -> V_13 , V_91 -> V_15 ) ;
V_91 -> V_148 [ V_4 -> V_13 ] = V_5 ;
}
if ( F_1 ( V_5 , V_7 -> V_9 + V_149 ) != ! ! V_94 ) {
if ( V_94 )
F_115 ( V_5 , V_7 -> V_9 + V_149 ) ;
else
F_6 ( V_5 , V_7 -> V_9 + V_149 ) ;
}
if ( V_4 -> V_8 . V_83 )
V_84 -> V_150 ( V_4 , V_5 ) ;
else {
F_116 ( V_5 , V_7 ) ;
F_89 ( V_113 , V_4 ) ;
F_117 ( V_4 ) ;
}
break;
case V_151 :
V_81 = 1 ;
V_4 -> V_8 . V_152 . V_153 = 1 ;
F_89 ( V_113 , V_4 ) ;
F_117 ( V_4 ) ;
break;
case V_154 :
V_81 = 1 ;
F_89 ( V_155 , V_4 ) ;
F_117 ( V_4 ) ;
break;
case V_64 :
V_81 = 1 ;
F_118 ( V_4 ) ;
F_117 ( V_4 ) ;
break;
case V_156 :
if ( ! V_94 || V_93 ) {
V_81 = 1 ;
V_7 -> V_157 = ( 1UL << V_158 ) ;
F_119 () ;
F_89 ( V_113 , V_4 ) ;
F_117 ( V_4 ) ;
} else {
F_81 ( L_10 ,
V_4 -> V_13 ) ;
}
break;
case V_159 :
F_81 ( L_11 ,
V_4 -> V_13 , V_5 ) ;
V_81 = 1 ;
V_7 -> V_160 = V_5 ;
F_119 () ;
F_120 ( V_161 , & V_7 -> V_157 ) ;
F_89 ( V_113 , V_4 ) ;
F_117 ( V_4 ) ;
break;
case V_162 :
break;
default:
F_100 ( V_163 L_12 ,
V_92 ) ;
break;
}
return V_81 ;
}
int F_106 ( struct V_3 * V_164 , struct V_3 * V_165 )
{
return V_164 -> V_8 . V_146 - V_165 -> V_8 . V_146 ;
}
static bool F_121 ( struct V_6 * V_7 , int V_5 )
{
return F_2 ( V_5 , V_7 -> V_4 -> V_8 . V_166 ) ;
}
static void F_122 ( struct V_6 * V_7 , int V_5 )
{
int V_167 ;
if ( ! F_121 ( V_7 , V_5 ) )
return;
if ( F_123 ( V_7 -> V_4 -> V_31 ) ) {
V_7 -> V_4 -> V_8 . V_168 = V_5 ;
F_89 ( V_169 , V_7 -> V_4 ) ;
return;
}
if ( F_1 ( V_5 , V_7 -> V_9 + V_149 ) )
V_167 = V_170 ;
else
V_167 = V_171 ;
F_124 ( V_7 -> V_4 , V_5 , V_167 ) ;
}
static int F_125 ( struct V_6 * V_7 )
{
int V_5 = F_69 ( V_7 ) ;
F_126 ( V_7 , V_5 ) ;
if ( V_5 == - 1 )
return V_5 ;
F_71 ( V_5 , V_7 ) ;
F_88 ( V_7 ) ;
if ( F_2 ( V_5 , F_127 ( V_7 -> V_4 ) -> V_172 ) )
F_128 ( V_7 -> V_4 , V_5 ) ;
F_122 ( V_7 , V_5 ) ;
F_89 ( V_113 , V_7 -> V_4 ) ;
return V_5 ;
}
void F_129 ( struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
F_126 ( V_7 , V_5 ) ;
F_122 ( V_7 , V_5 ) ;
F_89 ( V_113 , V_7 -> V_4 ) ;
}
static void F_130 ( struct V_6 * V_7 )
{
T_2 V_173 = F_16 ( V_7 , V_174 ) ;
T_2 V_175 = F_16 ( V_7 , V_176 ) ;
struct V_89 V_90 ;
V_90 . V_5 = V_173 & V_56 ;
V_90 . V_92 = V_173 & V_63 ;
V_90 . V_125 = V_173 & V_177 ;
V_90 . V_93 = ( V_173 & V_178 ) != 0 ;
V_90 . V_94 = V_173 & V_179 ;
V_90 . V_141 = V_173 & V_180 ;
V_90 . V_181 = false ;
if ( F_29 ( V_7 ) )
V_90 . V_16 = V_175 ;
else
V_90 . V_16 = F_131 ( V_175 ) ;
F_132 ( V_173 , V_90 . V_16 ) ;
F_81 ( L_13
L_14
L_15
L_16 ,
V_175 , V_173 , V_90 . V_141 , V_90 . V_16 ,
V_90 . V_94 , V_90 . V_93 , V_90 . V_125 , V_90 . V_92 ,
V_90 . V_5 , V_90 . V_181 ) ;
F_133 ( V_7 -> V_4 -> V_31 , V_7 , & V_90 , NULL ) ;
}
static T_2 F_134 ( struct V_6 * V_7 )
{
T_4 V_182 , V_183 ;
T_5 V_184 ;
T_2 V_185 ;
ASSERT ( V_7 != NULL ) ;
if ( F_16 ( V_7 , V_186 ) == 0 ||
V_7 -> V_57 . V_187 == 0 )
return 0 ;
V_183 = F_135 () ;
V_182 = F_136 ( V_7 -> V_57 . V_188 , V_183 ) ;
if ( F_137 ( V_182 ) < 0 )
V_182 = 0 ;
V_184 = F_138 ( F_137 ( V_182 ) , V_7 -> V_57 . V_187 ) ;
V_185 = F_139 ( V_184 ,
( V_189 * V_7 -> V_190 ) ) ;
return V_185 ;
}
static void F_140 ( struct V_6 * V_7 , bool V_191 )
{
struct V_3 * V_4 = V_7 -> V_4 ;
struct V_192 * V_193 = V_4 -> V_193 ;
F_89 ( V_194 , V_4 ) ;
V_193 -> V_195 . V_196 = F_141 ( V_4 ) ;
V_193 -> V_195 . V_197 = V_191 ;
}
static inline void F_142 ( struct V_6 * V_7 , bool V_191 )
{
if ( V_7 -> V_4 -> V_8 . V_198 )
F_140 ( V_7 , V_191 ) ;
}
static T_2 F_143 ( struct V_6 * V_7 , unsigned int V_21 )
{
T_2 V_46 = 0 ;
if ( V_21 >= V_199 )
return 0 ;
switch ( V_21 ) {
case V_200 :
F_81 ( L_17 ) ;
break;
case V_201 :
if ( F_50 ( V_7 ) )
return 0 ;
V_46 = F_134 ( V_7 ) ;
break;
case V_111 :
F_88 ( V_7 ) ;
V_46 = F_16 ( V_7 , V_21 ) ;
break;
case V_112 :
F_142 ( V_7 , false ) ;
default:
V_46 = F_16 ( V_7 , V_21 ) ;
break;
}
return V_46 ;
}
static inline struct V_6 * F_144 ( struct V_202 * V_203 )
{
return F_21 ( V_203 , struct V_6 , V_203 ) ;
}
int F_145 ( struct V_6 * V_7 , T_2 V_21 , int V_204 ,
void * V_96 )
{
unsigned char V_205 = V_21 & 0xf ;
T_2 V_81 ;
static const V_37 V_206 = 0x43ff01ffffffe70cULL ;
if ( ( V_205 + V_204 ) > 4 ) {
F_81 ( L_18 ,
V_21 , V_204 ) ;
return 1 ;
}
if ( V_21 > 0x3f0 || ! ( V_206 & ( 1ULL << ( V_21 >> 4 ) ) ) ) {
F_81 ( L_19 ,
V_21 ) ;
return 1 ;
}
V_81 = F_143 ( V_7 , V_21 & ~ 0xf ) ;
F_146 ( V_21 , V_81 ) ;
switch ( V_204 ) {
case 1 :
case 2 :
case 4 :
memcpy ( V_96 , ( char * ) & V_81 + V_205 , V_204 ) ;
break;
default:
F_100 ( V_163 L_20
L_21 , V_204 ) ;
break;
}
return 0 ;
}
static int F_147 ( struct V_6 * V_7 , T_6 V_207 )
{
return F_14 ( V_7 ) &&
V_207 >= V_7 -> V_208 &&
V_207 < V_7 -> V_208 + V_199 ;
}
static int F_148 ( struct V_3 * V_4 , struct V_202 * V_209 ,
T_6 V_210 , int V_204 , void * V_96 )
{
struct V_6 * V_7 = F_144 ( V_209 ) ;
T_2 V_21 = V_210 - V_7 -> V_208 ;
if ( ! F_147 ( V_7 , V_210 ) )
return - V_211 ;
F_145 ( V_7 , V_21 , V_204 , V_96 ) ;
return 0 ;
}
static void F_149 ( struct V_6 * V_7 )
{
T_2 V_212 , V_213 , V_214 ;
V_214 = F_16 ( V_7 , V_215 ) ;
V_212 = V_214 & 0xf ;
V_213 = ( ( V_212 & 0x3 ) | ( ( V_212 & 0x8 ) >> 1 ) ) + 1 ;
V_7 -> V_190 = 0x1 << ( V_213 & 0x7 ) ;
F_81 ( L_22 ,
V_7 -> V_190 ) ;
}
static void F_150 ( struct V_6 * V_7 )
{
T_2 V_58 = F_16 ( V_7 , V_216 ) &
V_7 -> V_57 . V_217 ;
if ( V_7 -> V_57 . V_58 != V_58 ) {
V_7 -> V_57 . V_58 = V_58 ;
F_151 ( & V_7 -> V_57 . V_218 ) ;
}
}
static void F_152 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_4 ;
struct V_219 * V_220 = & V_4 -> V_221 ;
struct V_222 * V_223 = & V_7 -> V_57 ;
if ( F_153 ( & V_7 -> V_57 . V_224 ) )
return;
F_154 ( & V_7 -> V_57 . V_224 ) ;
F_155 ( V_4 ) ;
if ( F_156 ( V_220 ) )
F_157 ( V_220 ) ;
if ( F_50 ( V_7 ) )
V_223 -> V_225 = V_223 -> V_226 ;
}
static bool F_158 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
T_2 V_73 = F_16 ( V_7 , V_216 ) ;
if ( F_14 ( V_7 ) ) {
int V_1 = V_73 & V_56 ;
void * V_2 = V_7 -> V_9 + V_10 ;
if ( V_4 -> V_8 . V_83 )
V_2 = V_7 -> V_9 + V_11 ;
if ( F_1 ( V_1 , V_2 ) )
return true ;
}
return false ;
}
void F_159 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
V_37 V_227 , V_228 ;
if ( ! F_53 ( V_4 ) )
return;
if ( V_7 -> V_57 . V_225 == 0 )
return;
if ( ! F_158 ( V_4 ) )
return;
V_228 = V_7 -> V_57 . V_225 ;
V_7 -> V_57 . V_225 = 0 ;
V_227 = F_160 ( V_4 , F_161 () ) ;
F_162 ( V_4 -> V_13 , V_227 - V_228 ) ;
if ( V_227 < V_228 )
F_163 ( F_19 ( V_228 - V_227 ,
F_164 ( V_4 , V_229 ) ) ) ;
}
static void F_165 ( struct V_6 * V_7 )
{
V_37 V_227 , V_226 = V_7 -> V_57 . V_226 ;
V_37 V_184 = 0 ;
T_4 V_230 ;
struct V_3 * V_4 = V_7 -> V_4 ;
unsigned long V_231 = V_4 -> V_8 . V_232 ;
unsigned long V_233 ;
T_4 V_183 ;
if ( F_66 ( ! V_226 || ! V_231 ) )
return;
F_166 ( V_233 ) ;
V_183 = F_135 () ;
V_227 = F_160 ( V_4 , F_161 () ) ;
if ( F_70 ( V_226 > V_227 ) ) {
V_184 = ( V_226 - V_227 ) * 1000000ULL ;
F_167 ( V_184 , V_231 ) ;
V_230 = F_168 ( V_183 , V_184 ) ;
V_230 = F_169 ( V_230 , V_229 ) ;
F_170 ( & V_7 -> V_57 . V_218 ,
V_230 , V_234 ) ;
} else
F_152 ( V_7 ) ;
F_171 ( V_233 ) ;
}
static void F_172 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_57 . V_187 )
return;
if ( F_48 ( V_7 ) &&
F_173 ( F_135 () ,
V_7 -> V_57 . V_188 ) ) {
F_152 ( V_7 ) ;
return;
}
F_170 ( & V_7 -> V_57 . V_218 ,
V_7 -> V_57 . V_188 ,
V_234 ) ;
}
static bool F_174 ( struct V_6 * V_7 )
{
T_4 V_183 ;
V_37 V_235 = F_161 () ;
V_183 = F_135 () ;
V_7 -> V_57 . V_187 = ( V_37 ) F_16 ( V_7 , V_186 )
* V_189 * V_7 -> V_190 ;
if ( ! V_7 -> V_57 . V_187 )
return false ;
if ( F_49 ( V_7 ) ) {
T_5 V_236 = V_237 * 1000LL ;
if ( V_7 -> V_57 . V_187 < V_236 ) {
F_175 (
L_23
L_24 ,
V_7 -> V_4 -> V_13 ,
V_7 -> V_57 . V_187 , V_236 ) ;
V_7 -> V_57 . V_187 = V_236 ;
}
}
F_81 ( L_25 V_238 L_26
V_239 L_27
L_28
L_29 V_239 L_30 , V_240 ,
V_189 , F_137 ( V_183 ) ,
F_16 ( V_7 , V_186 ) ,
V_7 -> V_57 . V_187 ,
F_137 ( F_168 ( V_183 ,
V_7 -> V_57 . V_187 ) ) ) ;
V_7 -> V_57 . V_226 = F_160 ( V_7 -> V_4 , V_235 ) +
F_164 ( V_7 -> V_4 , V_7 -> V_57 . V_187 ) ;
V_7 -> V_57 . V_188 = F_168 ( V_183 , V_7 -> V_57 . V_187 ) ;
return true ;
}
static void F_176 ( struct V_6 * V_7 )
{
V_7 -> V_57 . V_226 +=
F_164 ( V_7 -> V_4 , V_7 -> V_57 . V_187 ) ;
V_7 -> V_57 . V_188 =
F_168 ( V_7 -> V_57 . V_188 ,
V_7 -> V_57 . V_187 ) ;
}
bool F_177 ( struct V_3 * V_4 )
{
if ( ! F_53 ( V_4 ) )
return false ;
return V_4 -> V_8 . V_7 -> V_57 . V_241 ;
}
static void F_178 ( struct V_6 * V_7 )
{
V_84 -> F_178 ( V_7 -> V_4 ) ;
V_7 -> V_57 . V_241 = false ;
}
static bool F_179 ( struct V_6 * V_7 )
{
V_37 V_226 = V_7 -> V_57 . V_226 ;
if ( ( F_153 ( & V_7 -> V_57 . V_224 ) &&
! F_49 ( V_7 ) ) ||
V_84 -> V_242 ( V_7 -> V_4 , V_226 ) ) {
if ( V_7 -> V_57 . V_241 )
F_178 ( V_7 ) ;
} else {
V_7 -> V_57 . V_241 = true ;
F_151 ( & V_7 -> V_57 . V_218 ) ;
if ( F_153 ( & V_7 -> V_57 . V_224 ) &&
! F_49 ( V_7 ) )
F_178 ( V_7 ) ;
}
F_180 ( V_7 -> V_4 -> V_13 ,
V_7 -> V_57 . V_241 ) ;
return V_7 -> V_57 . V_241 ;
}
void F_181 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
F_182 ( ! V_7 -> V_57 . V_241 ) ;
F_182 ( F_156 ( & V_4 -> V_221 ) ) ;
F_178 ( V_7 ) ;
F_152 ( V_7 ) ;
if ( F_49 ( V_7 ) && V_7 -> V_57 . V_187 ) {
F_176 ( V_7 ) ;
if ( ! F_179 ( V_7 ) )
F_172 ( V_7 ) ;
}
}
void F_183 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
F_182 ( V_7 -> V_57 . V_241 ) ;
F_179 ( V_7 ) ;
}
void F_184 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
if ( ! V_7 -> V_57 . V_241 )
return;
F_178 ( V_7 ) ;
if ( F_153 ( & V_7 -> V_57 . V_224 ) )
return;
if ( F_49 ( V_7 ) || F_48 ( V_7 ) )
F_172 ( V_7 ) ;
else if ( F_50 ( V_7 ) )
F_165 ( V_7 ) ;
}
static void F_185 ( struct V_6 * V_7 )
{
F_186 ( & V_7 -> V_57 . V_224 , 0 ) ;
if ( F_49 ( V_7 ) || F_48 ( V_7 ) ) {
if ( F_174 ( V_7 ) &&
! ( V_84 -> V_242 && F_179 ( V_7 ) ) )
F_172 ( V_7 ) ;
} else if ( F_50 ( V_7 ) ) {
if ( ! ( V_84 -> V_242 && F_179 ( V_7 ) ) )
F_165 ( V_7 ) ;
}
}
static void F_187 ( struct V_6 * V_7 , T_2 V_243 )
{
bool V_244 = F_51 ( V_243 ) ;
if ( V_7 -> V_244 != V_244 ) {
V_7 -> V_244 = V_244 ;
if ( V_244 ) {
F_81 ( L_31
L_32 , V_7 -> V_4 -> V_13 ) ;
F_154 ( & V_7 -> V_4 -> V_31 -> V_8 . V_245 ) ;
} else
F_188 ( & V_7 -> V_4 -> V_31 -> V_8 . V_245 ) ;
}
}
int F_189 ( struct V_6 * V_7 , T_2 V_73 , T_2 V_46 )
{
int V_143 = 0 ;
F_190 ( V_73 , V_46 ) ;
switch ( V_73 ) {
case V_12 :
if ( ! F_29 ( V_7 ) )
F_42 ( V_7 , V_46 >> 24 ) ;
else
V_143 = 1 ;
break;
case V_112 :
F_142 ( V_7 , true ) ;
F_91 ( V_7 , V_46 & 0xff ) ;
break;
case V_246 :
F_125 ( V_7 ) ;
break;
case V_42 :
if ( ! F_29 ( V_7 ) )
F_43 ( V_7 , V_46 & V_247 ) ;
else
V_143 = 1 ;
break;
case V_43 :
if ( ! F_29 ( V_7 ) ) {
F_39 ( V_7 , V_43 , V_46 | 0x0FFFFFFF ) ;
F_23 ( V_7 -> V_4 -> V_31 ) ;
} else
V_143 = 1 ;
break;
case V_49 : {
T_2 V_18 = 0x3ff ;
if ( F_16 ( V_7 , V_72 ) & V_71 )
V_18 |= V_248 ;
F_38 ( V_7 , V_46 & V_18 ) ;
if ( ! ( V_46 & V_48 ) ) {
int V_34 ;
T_2 V_62 ;
for ( V_34 = 0 ; V_34 < V_249 ; V_34 ++ ) {
V_62 = F_16 ( V_7 ,
V_216 + 0x10 * V_34 ) ;
F_39 ( V_7 , V_216 + 0x10 * V_34 ,
V_62 | V_55 ) ;
}
F_150 ( V_7 ) ;
F_186 ( & V_7 -> V_57 . V_224 , 0 ) ;
}
break;
}
case V_174 :
F_39 ( V_7 , V_174 , V_46 & ~ ( 1 << 12 ) ) ;
F_130 ( V_7 ) ;
break;
case V_176 :
if ( ! F_29 ( V_7 ) )
V_46 &= 0xff000000 ;
F_39 ( V_7 , V_176 , V_46 ) ;
break;
case V_250 :
F_187 ( V_7 , V_46 ) ;
case V_251 :
case V_252 :
case V_253 :
case V_254 :
if ( ! F_13 ( V_7 ) )
V_46 |= V_55 ;
V_46 &= V_255 [ ( V_73 - V_216 ) >> 4 ] ;
F_39 ( V_7 , V_73 , V_46 ) ;
break;
case V_216 :
if ( ! F_13 ( V_7 ) )
V_46 |= V_55 ;
V_46 &= ( V_255 [ 0 ] | V_7 -> V_57 . V_217 ) ;
F_39 ( V_7 , V_216 , V_46 ) ;
F_150 ( V_7 ) ;
break;
case V_186 :
if ( F_50 ( V_7 ) )
break;
F_151 ( & V_7 -> V_57 . V_218 ) ;
F_39 ( V_7 , V_186 , V_46 ) ;
F_185 ( V_7 ) ;
break;
case V_215 :
if ( V_46 & 4 )
F_81 ( L_33 , V_46 ) ;
F_39 ( V_7 , V_215 , V_46 ) ;
F_149 ( V_7 ) ;
break;
case V_256 :
if ( F_29 ( V_7 ) && V_46 != 0 ) {
F_81 ( L_34 , V_46 ) ;
V_143 = 1 ;
}
break;
case V_257 :
if ( F_29 ( V_7 ) ) {
F_189 ( V_7 , V_174 , 0x40000 | ( V_46 & 0xff ) ) ;
} else
V_143 = 1 ;
break;
default:
V_143 = 1 ;
break;
}
if ( V_143 )
F_81 ( L_35 , V_73 ) ;
return V_143 ;
}
static int F_191 ( struct V_3 * V_4 , struct V_202 * V_209 ,
T_6 V_210 , int V_204 , const void * V_96 )
{
struct V_6 * V_7 = F_144 ( V_209 ) ;
unsigned int V_21 = V_210 - V_7 -> V_208 ;
T_2 V_46 ;
if ( ! F_147 ( V_7 , V_210 ) )
return - V_211 ;
if ( V_204 != 4 || ( V_21 & 0xf ) ) {
F_81 ( L_36 , V_204 , ( long ) V_210 ) ;
return 0 ;
}
V_46 = * ( T_2 * ) V_96 ;
if ( V_21 != V_246 )
F_81 ( L_37
L_38 , V_240 , V_21 , V_204 , V_46 ) ;
F_189 ( V_7 , V_21 & 0xff0 , V_46 ) ;
return 0 ;
}
void F_192 ( struct V_3 * V_4 )
{
F_189 ( V_4 -> V_8 . V_7 , V_246 , 0 ) ;
}
void F_193 ( struct V_3 * V_4 , T_2 V_21 )
{
T_2 V_46 = 0 ;
V_21 &= 0xff0 ;
F_145 ( V_4 -> V_8 . V_7 , V_21 , 4 , & V_46 ) ;
F_189 ( V_4 -> V_8 . V_7 , V_21 , V_46 ) ;
}
void F_194 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
if ( ! V_4 -> V_8 . V_7 )
return;
F_151 ( & V_7 -> V_57 . V_218 ) ;
if ( ! ( V_4 -> V_8 . V_258 & V_259 ) )
F_40 ( & V_260 ) ;
if ( ! V_7 -> V_50 )
F_40 ( & V_51 ) ;
if ( V_7 -> V_9 )
F_195 ( ( unsigned long ) V_7 -> V_9 ) ;
F_196 ( V_7 ) ;
}
V_37 F_197 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
if ( ! F_53 ( V_4 ) )
return 0 ;
return V_7 -> V_57 . V_226 ;
}
V_37 F_198 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
if ( ! F_53 ( V_4 ) ||
! F_50 ( V_7 ) )
return 0 ;
return V_7 -> V_57 . V_226 ;
}
void F_199 ( struct V_3 * V_4 , V_37 V_96 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
if ( ! F_53 ( V_4 ) || F_48 ( V_7 ) ||
F_49 ( V_7 ) )
return;
F_151 ( & V_7 -> V_57 . V_218 ) ;
V_7 -> V_57 . V_226 = V_96 ;
F_185 ( V_7 ) ;
}
void F_200 ( struct V_3 * V_4 , unsigned long V_261 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
F_91 ( V_7 , ( ( V_261 & 0x0f ) << 4 )
| ( F_16 ( V_7 , V_112 ) & 4 ) ) ;
}
V_37 F_201 ( struct V_3 * V_4 )
{
V_37 V_107 ;
V_107 = ( V_37 ) F_16 ( V_4 -> V_8 . V_7 , V_112 ) ;
return ( V_107 & 0xf0 ) >> 4 ;
}
void F_202 ( struct V_3 * V_4 , V_37 V_262 )
{
V_37 V_263 = V_4 -> V_8 . V_258 ;
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
if ( ! V_7 )
V_262 |= V_264 ;
V_4 -> V_8 . V_258 = V_262 ;
if ( ( V_263 ^ V_262 ) & V_259 )
F_203 ( V_4 ) ;
if ( ! V_7 )
return;
if ( ( V_263 ^ V_262 ) & V_259 ) {
if ( V_262 & V_259 ) {
F_42 ( V_7 , V_4 -> V_13 ) ;
F_40 ( & V_260 ) ;
} else {
F_41 ( & V_260 . V_52 ) ;
F_23 ( V_4 -> V_31 ) ;
}
}
if ( ( V_263 ^ V_262 ) & V_265 ) {
if ( V_262 & V_265 ) {
F_44 ( V_7 , V_4 -> V_13 ) ;
V_84 -> V_266 ( V_4 , true ) ;
} else
V_84 -> V_266 ( V_4 , false ) ;
}
V_7 -> V_208 = V_7 -> V_4 -> V_8 . V_258 &
V_267 ;
if ( ( V_262 & V_259 ) &&
V_7 -> V_208 != V_268 )
F_204 ( L_39 ) ;
F_81 ( L_40 V_239 L_41
L_42 , V_7 -> V_4 -> V_8 . V_258 , V_7 -> V_208 ) ;
}
void F_205 ( struct V_3 * V_4 , bool V_269 )
{
struct V_6 * V_7 ;
int V_34 ;
F_81 ( L_43 , V_240 ) ;
ASSERT ( V_4 ) ;
V_7 = V_4 -> V_8 . V_7 ;
ASSERT ( V_7 != NULL ) ;
F_151 ( & V_7 -> V_57 . V_218 ) ;
if ( ! V_269 ) {
F_202 ( V_4 , V_268 |
V_259 ) ;
F_42 ( V_7 , V_4 -> V_13 ) ;
}
F_52 ( V_7 -> V_4 ) ;
for ( V_34 = 0 ; V_34 < V_249 ; V_34 ++ )
F_39 ( V_7 , V_216 + 0x10 * V_34 , V_55 ) ;
F_150 ( V_7 ) ;
if ( F_206 ( V_4 -> V_31 , V_270 ) )
F_39 ( V_7 , V_250 ,
F_207 ( 0 , V_271 ) ) ;
F_187 ( V_7 , F_16 ( V_7 , V_250 ) ) ;
F_39 ( V_7 , V_43 , 0xffffffffU ) ;
F_38 ( V_7 , 0xff ) ;
F_39 ( V_7 , V_112 , 0 ) ;
if ( ! F_29 ( V_7 ) )
F_43 ( V_7 , 0 ) ;
F_39 ( V_7 , V_256 , 0 ) ;
F_39 ( V_7 , V_174 , 0 ) ;
F_39 ( V_7 , V_176 , 0 ) ;
F_39 ( V_7 , V_215 , 0 ) ;
F_39 ( V_7 , V_186 , 0 ) ;
for ( V_34 = 0 ; V_34 < 8 ; V_34 ++ ) {
F_39 ( V_7 , V_11 + 0x10 * V_34 , 0 ) ;
F_39 ( V_7 , V_10 + 0x10 * V_34 , 0 ) ;
F_39 ( V_7 , V_149 + 0x10 * V_34 , 0 ) ;
}
V_7 -> V_82 = V_4 -> V_8 . V_83 ;
V_7 -> V_87 = V_4 -> V_8 . V_83 ? 1 : 0 ;
V_7 -> V_88 = - 1 ;
F_149 ( V_7 ) ;
F_186 ( & V_7 -> V_57 . V_224 , 0 ) ;
if ( F_208 ( V_4 ) )
F_202 ( V_4 ,
V_4 -> V_8 . V_258 | V_264 ) ;
V_4 -> V_8 . V_95 . V_97 = 0 ;
F_88 ( V_7 ) ;
V_4 -> V_8 . V_146 = 0 ;
V_4 -> V_8 . V_101 = 0 ;
F_81 ( L_44
L_45 V_239 L_46 , V_240 ,
V_4 , F_16 ( V_7 , V_12 ) ,
V_4 -> V_8 . V_258 , V_7 -> V_208 ) ;
}
static bool F_209 ( struct V_6 * V_7 )
{
return F_49 ( V_7 ) ;
}
int F_210 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
if ( F_12 ( V_7 ) && F_46 ( V_7 , V_216 ) )
return F_153 ( & V_7 -> V_57 . V_224 ) ;
return 0 ;
}
int F_211 ( struct V_6 * V_7 , int V_54 )
{
T_2 V_73 = F_16 ( V_7 , V_54 ) ;
int V_5 , V_19 , V_94 ;
if ( F_14 ( V_7 ) && ! ( V_73 & V_55 ) ) {
V_5 = V_73 & V_56 ;
V_19 = V_73 & V_63 ;
V_94 = V_73 & V_272 ;
return F_74 ( V_7 , V_19 , V_5 , 1 , V_94 ,
NULL ) ;
}
return 0 ;
}
void F_212 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
if ( V_7 )
F_211 ( V_7 , V_250 ) ;
}
static enum V_273 F_213 ( struct V_274 * V_96 )
{
struct V_222 * V_223 = F_21 ( V_96 , struct V_222 , V_218 ) ;
struct V_6 * V_7 = F_21 ( V_223 , struct V_6 , V_57 ) ;
F_152 ( V_7 ) ;
if ( F_209 ( V_7 ) ) {
F_176 ( V_7 ) ;
F_214 ( & V_223 -> V_218 , V_223 -> V_187 ) ;
return V_275 ;
} else
return V_276 ;
}
int F_215 ( struct V_3 * V_4 )
{
struct V_6 * V_7 ;
ASSERT ( V_4 != NULL ) ;
F_81 ( L_47 , V_4 -> V_13 ) ;
V_7 = F_216 ( sizeof( * V_7 ) , V_277 ) ;
if ( ! V_7 )
goto V_278;
V_4 -> V_8 . V_7 = V_7 ;
V_7 -> V_9 = ( void * ) F_217 ( V_277 ) ;
if ( ! V_7 -> V_9 ) {
F_100 ( V_163 L_48 ,
V_4 -> V_13 ) ;
goto V_279;
}
V_7 -> V_4 = V_4 ;
F_218 ( & V_7 -> V_57 . V_218 , V_280 ,
V_234 ) ;
V_7 -> V_57 . V_218 . V_281 = F_213 ;
V_4 -> V_8 . V_258 = V_259 ;
F_41 ( & V_51 . V_52 ) ;
F_205 ( V_4 , false ) ;
F_219 ( & V_7 -> V_203 , & V_282 ) ;
return 0 ;
V_279:
F_196 ( V_7 ) ;
V_278:
return - V_283 ;
}
int F_220 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
T_2 V_103 ;
if ( ! F_12 ( V_7 ) )
return - 1 ;
F_87 ( V_7 , & V_103 ) ;
return F_86 ( V_7 , V_103 ) ;
}
int F_221 ( struct V_3 * V_4 )
{
T_2 V_284 = F_16 ( V_4 -> V_8 . V_7 , V_250 ) ;
int V_142 = 0 ;
if ( ! F_14 ( V_4 -> V_8 . V_7 ) )
V_142 = 1 ;
if ( ( V_284 & V_55 ) == 0 &&
F_222 ( V_284 ) == V_271 )
V_142 = 1 ;
return V_142 ;
}
void F_223 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
if ( F_153 ( & V_7 -> V_57 . V_224 ) > 0 ) {
F_211 ( V_7 , V_216 ) ;
if ( F_50 ( V_7 ) )
V_7 -> V_57 . V_226 = 0 ;
if ( F_48 ( V_7 ) ) {
V_7 -> V_57 . V_226 = 0 ;
V_7 -> V_57 . V_188 = 0 ;
}
F_186 ( & V_7 -> V_57 . V_224 , 0 ) ;
}
}
int F_224 ( struct V_3 * V_4 )
{
int V_5 = F_220 ( V_4 ) ;
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
T_2 V_103 ;
if ( V_5 == - 1 )
return - 1 ;
F_65 ( V_5 , V_7 ) ;
if ( F_2 ( V_5 , F_127 ( V_4 ) -> V_285 ) ) {
F_88 ( V_7 ) ;
} else {
F_67 ( V_5 , V_7 ) ;
F_87 ( V_7 , & V_103 ) ;
}
return V_5 ;
}
static int F_225 ( struct V_3 * V_4 ,
struct V_286 * V_287 , bool V_288 )
{
if ( F_29 ( V_4 -> V_8 . V_7 ) ) {
T_2 * V_53 = ( T_2 * ) ( V_287 -> V_9 + V_12 ) ;
if ( V_4 -> V_31 -> V_8 . V_289 ) {
if ( * V_53 != V_4 -> V_13 )
return - V_290 ;
} else {
if ( V_288 )
* V_53 >>= 24 ;
else
* V_53 <<= 24 ;
}
}
return 0 ;
}
int F_226 ( struct V_3 * V_4 , struct V_286 * V_287 )
{
memcpy ( V_287 -> V_9 , V_4 -> V_8 . V_7 -> V_9 , sizeof( * V_287 ) ) ;
return F_225 ( V_4 , V_287 , false ) ;
}
int F_227 ( struct V_3 * V_4 , struct V_286 * V_287 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
int V_142 ;
F_202 ( V_4 , V_4 -> V_8 . V_258 ) ;
F_38 ( V_7 , * ( ( T_2 * ) ( V_287 -> V_9 + V_49 ) ) ) ;
V_142 = F_225 ( V_4 , V_287 , true ) ;
if ( V_142 )
return V_142 ;
memcpy ( V_4 -> V_8 . V_7 -> V_9 , V_287 -> V_9 , sizeof *V_287 ) ;
F_23 ( V_4 -> V_31 ) ;
F_52 ( V_4 ) ;
F_88 ( V_7 ) ;
F_151 ( & V_7 -> V_57 . V_218 ) ;
F_150 ( V_7 ) ;
F_187 ( V_7 , F_16 ( V_7 , V_250 ) ) ;
F_149 ( V_7 ) ;
F_185 ( V_7 ) ;
V_7 -> V_82 = true ;
V_7 -> V_87 = V_4 -> V_8 . V_83 ?
1 : F_57 ( V_7 -> V_9 + V_10 ) ;
V_7 -> V_88 = - 1 ;
if ( V_4 -> V_8 . V_83 ) {
V_84 -> V_291 ( V_4 ) ;
V_84 -> V_85 ( V_4 ,
F_64 ( V_7 ) ) ;
V_84 -> V_86 ( V_4 ,
F_69 ( V_7 ) ) ;
}
F_89 ( V_113 , V_4 ) ;
if ( F_228 ( V_4 -> V_31 ) )
F_229 ( V_4 ) ;
V_4 -> V_8 . V_146 = 0 ;
return 0 ;
}
void F_230 ( struct V_3 * V_4 )
{
struct V_274 * V_218 ;
if ( ! F_53 ( V_4 ) )
return;
V_218 = & V_4 -> V_8 . V_7 -> V_57 . V_218 ;
if ( F_151 ( V_218 ) )
F_231 ( V_218 , V_234 ) ;
}
static void F_232 ( struct V_3 * V_4 ,
struct V_6 * V_7 )
{
bool V_224 ;
int V_5 ;
F_68 ( ! F_79 ( V_4 ) ) ;
V_224 = F_80 ( V_4 ) ;
F_84 ( V_4 ) ;
if ( V_224 )
return;
V_5 = F_125 ( V_7 ) ;
F_233 ( V_7 , V_5 ) ;
}
void F_234 ( struct V_3 * V_4 )
{
T_2 V_96 ;
if ( F_2 ( V_100 , & V_4 -> V_8 . V_101 ) )
F_232 ( V_4 , V_4 -> V_8 . V_7 ) ;
if ( ! F_2 ( V_292 , & V_4 -> V_8 . V_101 ) )
return;
if ( F_78 ( V_4 , & V_4 -> V_8 . V_7 -> V_293 , & V_96 ,
sizeof( T_2 ) ) )
return;
F_91 ( V_4 -> V_8 . V_7 , V_96 & 0xff ) ;
}
static void F_235 ( struct V_3 * V_4 ,
struct V_6 * V_7 )
{
if ( ! F_79 ( V_4 ) ||
V_7 -> V_82 ||
V_7 -> V_88 == - 1 ||
F_121 ( V_7 , V_7 -> V_88 ) ) {
return;
}
F_82 ( V_7 -> V_4 ) ;
}
void F_236 ( struct V_3 * V_4 )
{
T_2 V_96 , V_107 ;
int V_80 , V_294 ;
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
F_235 ( V_4 , V_7 ) ;
if ( ! F_2 ( V_292 , & V_4 -> V_8 . V_101 ) )
return;
V_107 = F_16 ( V_7 , V_112 ) & 0xff ;
V_80 = F_64 ( V_7 ) ;
if ( V_80 < 0 )
V_80 = 0 ;
V_294 = F_69 ( V_7 ) ;
if ( V_294 < 0 )
V_294 = 0 ;
V_96 = ( V_107 & 0xff ) | ( ( V_294 & 0xf0 ) << 8 ) | ( V_80 << 24 ) ;
F_76 ( V_4 , & V_4 -> V_8 . V_7 -> V_293 , & V_96 ,
sizeof( T_2 ) ) ;
}
int F_237 ( struct V_3 * V_4 , T_6 V_295 )
{
if ( V_295 ) {
if ( F_238 ( V_4 ,
& V_4 -> V_8 . V_7 -> V_293 ,
V_295 , sizeof( T_2 ) ) )
return - V_290 ;
F_83 ( V_292 , & V_4 -> V_8 . V_101 ) ;
} else {
F_85 ( V_292 , & V_4 -> V_8 . V_101 ) ;
}
V_4 -> V_8 . V_7 -> V_295 = V_295 ;
return 0 ;
}
int F_239 ( struct V_3 * V_4 , T_2 V_296 , V_37 V_96 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
T_2 V_73 = ( V_296 - V_297 ) << 4 ;
if ( ! F_53 ( V_4 ) || ! F_29 ( V_7 ) )
return 1 ;
if ( V_73 == V_176 )
return 1 ;
if ( V_73 == V_174 )
F_189 ( V_7 , V_176 , ( T_2 ) ( V_96 >> 32 ) ) ;
return F_189 ( V_7 , V_73 , ( T_2 ) V_96 ) ;
}
int F_240 ( struct V_3 * V_4 , T_2 V_296 , V_37 * V_96 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
T_2 V_73 = ( V_296 - V_297 ) << 4 , V_298 , V_299 = 0 ;
if ( ! F_53 ( V_4 ) || ! F_29 ( V_7 ) )
return 1 ;
if ( V_73 == V_43 || V_73 == V_176 ) {
F_81 ( L_49 ,
V_73 ) ;
return 1 ;
}
if ( F_145 ( V_7 , V_73 , 4 , & V_298 ) )
return 1 ;
if ( V_73 == V_174 )
F_145 ( V_7 , V_176 , 4 , & V_299 ) ;
* V_96 = ( ( ( V_37 ) V_299 ) << 32 ) | V_298 ;
return 0 ;
}
int F_241 ( struct V_3 * V_4 , T_2 V_73 , V_37 V_96 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
if ( ! F_53 ( V_4 ) )
return 1 ;
if ( V_73 == V_174 )
F_189 ( V_7 , V_176 , ( T_2 ) ( V_96 >> 32 ) ) ;
return F_189 ( V_7 , V_73 , ( T_2 ) V_96 ) ;
}
int F_242 ( struct V_3 * V_4 , T_2 V_73 , V_37 * V_96 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
T_2 V_298 , V_299 = 0 ;
if ( ! F_53 ( V_4 ) )
return 1 ;
if ( F_145 ( V_7 , V_73 , 4 , & V_298 ) )
return 1 ;
if ( V_73 == V_174 )
F_145 ( V_7 , V_176 , 4 , & V_299 ) ;
* V_96 = ( ( ( V_37 ) V_299 ) << 32 ) | V_298 ;
return 0 ;
}
int F_243 ( struct V_3 * V_4 , V_37 V_96 )
{
V_37 V_207 = V_96 & ~ V_98 ;
if ( ! F_244 ( V_207 , 4 ) )
return 1 ;
V_4 -> V_8 . V_95 . V_97 = V_96 ;
if ( ! F_79 ( V_4 ) )
return 0 ;
return F_238 ( V_4 , & V_4 -> V_8 . V_95 . V_96 ,
V_207 , sizeof( T_1 ) ) ;
}
void F_245 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
T_1 V_160 ;
unsigned long V_300 ;
if ( ! F_53 ( V_4 ) || ! V_7 -> V_157 )
return;
if ( F_246 ( V_4 ) ) {
F_45 ( V_4 -> V_8 . V_301 == V_302 ) ;
if ( F_2 ( V_161 , & V_7 -> V_157 ) )
F_7 ( V_161 , & V_7 -> V_157 ) ;
return;
}
V_300 = F_61 ( & V_7 -> V_157 , 0 ) ;
if ( F_2 ( V_158 , & V_300 ) ) {
F_205 ( V_4 , true ) ;
F_247 ( V_4 , true ) ;
if ( F_208 ( V_7 -> V_4 ) )
V_4 -> V_8 . V_301 = V_303 ;
else
V_4 -> V_8 . V_301 = V_302 ;
}
if ( F_2 ( V_161 , & V_300 ) &&
V_4 -> V_8 . V_301 == V_302 ) {
F_248 () ;
V_160 = V_7 -> V_160 ;
F_81 ( L_50 ,
V_4 -> V_13 , V_160 ) ;
F_249 ( V_4 , V_160 ) ;
V_4 -> V_8 . V_301 = V_303 ;
}
}
void F_250 ( void )
{
F_251 ( & V_260 , V_304 ) ;
F_251 ( & V_51 , V_304 ) ;
}
void F_252 ( void )
{
F_253 ( & V_260 ) ;
F_253 ( & V_51 ) ;
}
