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
static inline bool F_15 ( struct V_12 * V_13 ,
T_1 V_14 , struct V_6 * * * V_15 , T_2 * V_16 ) {
switch ( V_13 -> V_17 ) {
case V_18 : {
T_1 V_19 = ( V_14 >> 16 ) * 16 ;
T_1 V_20 = V_13 -> V_20 ;
if ( V_19 <= V_20 ) {
T_3 V_21 = F_16 ( V_20 - V_19 + 1 , 16U ) ;
* V_15 = & V_13 -> V_22 [ V_19 ] ;
* V_16 = V_14 & ( 0xffff >> ( 16 - V_21 ) ) ;
} else {
* V_16 = 0 ;
}
return true ;
}
case V_23 :
* V_15 = V_13 -> V_24 ;
* V_16 = V_14 & 0xff ;
return true ;
case V_25 :
* V_15 = V_13 -> V_26 [ ( V_14 >> 4 ) & 0xf ] ;
* V_16 = V_14 & 0xf ;
return true ;
default:
return false ;
}
}
static void F_17 ( struct V_27 * V_28 )
{
struct V_12 * V_13 = F_18 ( V_28 , struct V_12 , V_28 ) ;
F_19 ( V_13 ) ;
}
static void F_20 ( struct V_29 * V_29 )
{
struct V_12 * V_30 , * V_31 = NULL ;
struct V_3 * V_4 ;
int V_32 ;
T_1 V_33 = 255 ;
F_21 ( & V_29 -> V_8 . V_34 ) ;
F_22 (i, vcpu, kvm)
if ( F_23 ( V_4 ) )
V_33 = F_24 ( V_33 , F_25 ( V_4 -> V_8 . V_7 ) ) ;
V_30 = F_26 ( sizeof( struct V_12 ) +
sizeof( struct V_6 * ) * ( ( V_35 ) V_33 + 1 ) ) ;
if ( ! V_30 )
goto V_36;
V_30 -> V_20 = V_33 ;
F_22 (i, vcpu, kvm) {
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
struct V_6 * * V_15 ;
T_2 V_16 ;
T_1 V_37 , V_38 ;
if ( ! F_23 ( V_4 ) )
continue;
V_38 = F_25 ( V_7 ) ;
V_37 = F_27 ( V_7 , V_39 ) ;
if ( V_38 <= V_30 -> V_20 )
V_30 -> V_22 [ V_38 ] = V_7 ;
if ( F_28 ( V_7 ) ) {
V_30 -> V_17 |= V_18 ;
} else if ( V_37 ) {
V_37 = F_29 ( V_37 ) ;
if ( F_27 ( V_7 , V_40 ) == V_41 )
V_30 -> V_17 |= V_23 ;
else
V_30 -> V_17 |= V_25 ;
}
if ( ! F_15 ( V_30 , V_37 , & V_15 , & V_16 ) )
continue;
if ( V_16 )
V_15 [ F_30 ( V_16 ) - 1 ] = V_7 ;
}
V_36:
V_31 = F_31 ( V_29 -> V_8 . V_42 ,
F_32 ( & V_29 -> V_8 . V_34 ) ) ;
F_33 ( V_29 -> V_8 . V_42 , V_30 ) ;
F_34 ( & V_29 -> V_8 . V_34 ) ;
if ( V_31 )
F_35 ( & V_31 -> V_28 , F_17 ) ;
F_36 ( V_29 ) ;
}
static inline void F_37 ( struct V_6 * V_7 , T_1 V_43 )
{
bool V_44 = V_43 & V_45 ;
F_38 ( V_7 , V_46 , V_43 ) ;
if ( V_44 != V_7 -> V_47 ) {
V_7 -> V_47 = V_44 ;
if ( V_44 ) {
F_39 ( & V_48 ) ;
F_20 ( V_7 -> V_4 -> V_29 ) ;
} else
F_40 ( & V_48 . V_49 ) ;
}
}
static inline void F_41 ( struct V_6 * V_7 , T_3 V_50 )
{
F_38 ( V_7 , V_51 , V_50 << 24 ) ;
F_20 ( V_7 -> V_4 -> V_29 ) ;
}
static inline void F_42 ( struct V_6 * V_7 , T_1 V_50 )
{
F_38 ( V_7 , V_39 , V_50 ) ;
F_20 ( V_7 -> V_4 -> V_29 ) ;
}
static inline void F_43 ( struct V_6 * V_7 , T_1 V_50 )
{
T_1 V_37 = ( ( V_50 >> 4 ) << 16 ) | ( 1 << ( V_50 & 0xf ) ) ;
F_38 ( V_7 , V_51 , V_50 ) ;
F_38 ( V_7 , V_39 , V_37 ) ;
F_20 ( V_7 -> V_4 -> V_29 ) ;
}
static inline int F_44 ( struct V_6 * V_7 , int V_52 )
{
return ! ( F_27 ( V_7 , V_52 ) & V_53 ) ;
}
static inline int F_45 ( struct V_6 * V_7 , int V_52 )
{
return F_27 ( V_7 , V_52 ) & V_54 ;
}
static inline int F_46 ( struct V_6 * V_7 )
{
return V_7 -> V_55 . V_56 == V_57 ;
}
static inline int F_47 ( struct V_6 * V_7 )
{
return V_7 -> V_55 . V_56 == V_58 ;
}
static inline int F_48 ( struct V_6 * V_7 )
{
return V_7 -> V_55 . V_56 == V_59 ;
}
static inline int F_49 ( T_1 V_60 )
{
return ( V_60 & ( V_61 | V_53 ) ) == V_62 ;
}
void F_50 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
struct V_63 * V_64 ;
T_1 V_65 = V_66 ;
if ( ! F_51 ( V_4 ) )
return;
V_64 = F_52 ( V_7 -> V_4 , 0x1 , 0 ) ;
if ( V_64 && ( V_64 -> V_67 & ( 1 << ( V_68 & 31 ) ) ) )
V_65 |= V_69 ;
F_38 ( V_7 , V_70 , V_65 ) ;
}
static int F_53 ( void * V_2 )
{
int V_1 ;
T_1 * V_71 ;
for ( V_1 = V_72 - V_73 ;
V_1 >= 0 ; V_1 -= V_73 ) {
V_71 = V_2 + F_4 ( V_1 ) ;
if ( * V_71 )
return F_54 ( * V_71 ) - 1 + V_1 ;
}
return - 1 ;
}
static T_3 F_55 ( void * V_2 )
{
int V_1 ;
T_1 * V_71 ;
T_3 V_74 = 0 ;
for ( V_1 = 0 ; V_1 < V_72 ; V_1 += V_73 ) {
V_71 = V_2 + F_4 ( V_1 ) ;
V_74 += F_56 ( * V_71 ) ;
}
return V_74 ;
}
void F_57 ( T_1 * V_75 , void * V_9 )
{
T_1 V_32 , V_76 ;
for ( V_32 = 0 ; V_32 <= 7 ; V_32 ++ ) {
V_76 = F_58 ( V_75 [ V_32 ] ) ;
if ( V_76 ) {
V_76 = F_59 ( & V_75 [ V_32 ] , 0 ) ;
* ( ( T_1 * ) ( V_9 + V_11 + V_32 * 0x10 ) ) |= V_76 ;
}
}
}
void F_60 ( struct V_3 * V_4 , T_1 * V_75 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
F_57 ( V_75 , V_7 -> V_9 ) ;
F_61 ( V_77 , V_4 ) ;
}
static inline int F_62 ( struct V_6 * V_7 )
{
return F_53 ( V_7 -> V_9 + V_11 ) ;
}
static inline int F_63 ( struct V_6 * V_7 )
{
int V_78 ;
if ( ! V_7 -> V_79 )
return - 1 ;
if ( V_7 -> V_4 -> V_8 . V_80 )
V_81 -> V_82 ( V_7 -> V_4 ) ;
V_78 = F_62 ( V_7 ) ;
ASSERT ( V_78 == - 1 || V_78 >= 16 ) ;
return V_78 ;
}
static inline void F_64 ( int V_1 , struct V_6 * V_7 )
{
struct V_3 * V_4 ;
V_4 = V_7 -> V_4 ;
if ( F_65 ( V_4 -> V_8 . V_80 ) ) {
F_6 ( V_1 , V_7 -> V_9 + V_11 ) ;
F_61 ( V_77 , V_4 ) ;
} else {
V_7 -> V_79 = false ;
F_6 ( V_1 , V_7 -> V_9 + V_11 ) ;
if ( F_62 ( V_7 ) != - 1 )
V_7 -> V_79 = true ;
}
}
static inline void F_66 ( int V_1 , struct V_6 * V_7 )
{
struct V_3 * V_4 ;
if ( F_8 ( V_1 , V_7 -> V_9 + V_10 ) )
return;
V_4 = V_7 -> V_4 ;
if ( F_65 ( V_4 -> V_8 . V_80 ) )
V_81 -> V_83 ( V_4 , V_1 ) ;
else {
++ V_7 -> V_84 ;
F_67 ( V_7 -> V_84 > V_72 ) ;
V_7 -> V_85 = V_1 ;
}
}
static inline int F_68 ( struct V_6 * V_7 )
{
int V_78 ;
if ( ! V_7 -> V_84 )
return - 1 ;
if ( F_69 ( V_7 -> V_85 != - 1 ) )
return V_7 -> V_85 ;
V_78 = F_53 ( V_7 -> V_9 + V_10 ) ;
ASSERT ( V_78 == - 1 || V_78 >= 16 ) ;
return V_78 ;
}
static inline void F_70 ( int V_1 , struct V_6 * V_7 )
{
struct V_3 * V_4 ;
if ( ! F_10 ( V_1 , V_7 -> V_9 + V_10 ) )
return;
V_4 = V_7 -> V_4 ;
if ( F_65 ( V_4 -> V_8 . V_80 ) )
V_81 -> V_83 ( V_4 ,
F_68 ( V_7 ) ) ;
else {
-- V_7 -> V_84 ;
F_67 ( V_7 -> V_84 < 0 ) ;
V_7 -> V_85 = - 1 ;
}
}
int F_71 ( struct V_3 * V_4 )
{
return F_63 ( V_4 -> V_8 . V_7 ) ;
}
int F_72 ( struct V_3 * V_4 , struct V_86 * V_87 ,
struct V_88 * V_88 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
return F_73 ( V_7 , V_87 -> V_89 , V_87 -> V_5 ,
V_87 -> V_90 , V_87 -> V_91 , V_88 ) ;
}
static int F_74 ( struct V_3 * V_4 , T_3 V_43 )
{
return F_75 ( V_4 -> V_29 , & V_4 -> V_8 . V_92 . V_93 , & V_43 ,
sizeof( V_43 ) ) ;
}
static int F_76 ( struct V_3 * V_4 , T_3 * V_43 )
{
return F_77 ( V_4 -> V_29 , & V_4 -> V_8 . V_92 . V_93 , V_43 ,
sizeof( * V_43 ) ) ;
}
static inline bool F_78 ( struct V_3 * V_4 )
{
return V_4 -> V_8 . V_92 . V_94 & V_95 ;
}
static bool F_79 ( struct V_3 * V_4 )
{
T_3 V_43 ;
if ( F_76 ( V_4 , & V_43 ) < 0 )
F_80 ( L_1 ,
( unsigned long long ) V_4 -> V_8 . V_92 . V_94 ) ;
return V_43 & 0x1 ;
}
static void F_81 ( struct V_3 * V_4 )
{
if ( F_74 ( V_4 , V_96 ) < 0 ) {
F_80 ( L_2 ,
( unsigned long long ) V_4 -> V_8 . V_92 . V_94 ) ;
return;
}
F_82 ( V_97 , & V_4 -> V_8 . V_98 ) ;
}
static void F_83 ( struct V_3 * V_4 )
{
if ( F_74 ( V_4 , V_99 ) < 0 ) {
F_80 ( L_3 ,
( unsigned long long ) V_4 -> V_8 . V_92 . V_94 ) ;
return;
}
F_84 ( V_97 , & V_4 -> V_8 . V_98 ) ;
}
static void F_85 ( struct V_6 * V_7 )
{
T_1 V_100 , V_101 , V_102 , V_103 ;
int V_104 ;
V_103 = F_27 ( V_7 , V_105 ) ;
V_100 = F_27 ( V_7 , V_106 ) ;
V_104 = F_68 ( V_7 ) ;
V_101 = ( V_104 != - 1 ) ? V_104 : 0 ;
if ( ( V_100 & 0xf0 ) >= ( V_101 & 0xf0 ) )
V_102 = V_100 & 0xff ;
else
V_102 = V_101 & 0xf0 ;
F_80 ( L_4 ,
V_7 , V_102 , V_104 , V_101 ) ;
if ( V_103 != V_102 ) {
F_38 ( V_7 , V_105 , V_102 ) ;
if ( V_102 < V_103 )
F_61 ( V_77 , V_7 -> V_4 ) ;
}
}
static void F_86 ( struct V_6 * V_7 , T_1 V_100 )
{
F_38 ( V_7 , V_106 , V_100 ) ;
F_85 ( V_7 ) ;
}
static bool F_87 ( struct V_6 * V_7 , T_1 V_107 )
{
if ( F_28 ( V_7 ) )
return V_107 == V_108 ;
return F_88 ( V_107 ) == V_109 ;
}
static bool F_89 ( struct V_6 * V_7 , T_1 V_107 )
{
if ( F_87 ( V_7 , V_107 ) )
return true ;
if ( F_28 ( V_7 ) )
return V_107 == F_25 ( V_7 ) ;
return V_107 == F_90 ( F_25 ( V_7 ) ) ;
}
static bool F_91 ( struct V_6 * V_7 , T_1 V_107 )
{
T_1 V_110 ;
if ( F_87 ( V_7 , V_107 ) )
return true ;
V_110 = F_27 ( V_7 , V_39 ) ;
if ( F_28 ( V_7 ) )
return ( ( V_110 >> 16 ) == ( V_107 >> 16 ) )
&& ( V_110 & V_107 & 0xffff ) != 0 ;
V_110 = F_29 ( V_110 ) ;
V_107 = F_88 ( V_107 ) ;
switch ( F_27 ( V_7 , V_40 ) ) {
case V_41 :
return ( V_110 & V_107 ) != 0 ;
case V_111 :
return ( ( V_110 >> 4 ) == ( V_107 >> 4 ) )
&& ( V_110 & V_107 & 0xf ) != 0 ;
default:
F_80 ( L_5 ,
V_7 -> V_4 -> V_112 , F_27 ( V_7 , V_40 ) ) ;
return false ;
}
}
static T_1 F_92 ( struct V_3 * V_4 , unsigned int V_14 ,
struct V_6 * V_113 , struct V_6 * V_114 )
{
bool V_115 = V_113 != NULL ;
bool V_116 = F_28 ( V_115 ? V_113 : V_114 ) ;
if ( ! V_4 -> V_29 -> V_8 . V_117 &&
! V_115 && V_14 == V_109 && V_116 )
return V_108 ;
return V_116 ? V_14 : F_90 ( V_14 ) ;
}
bool F_93 ( struct V_3 * V_4 , struct V_6 * V_113 ,
int V_118 , unsigned int V_119 , int V_120 )
{
struct V_6 * V_114 = V_4 -> V_8 . V_7 ;
T_1 V_107 = F_92 ( V_4 , V_119 , V_113 , V_114 ) ;
F_80 ( L_6
L_7 ,
V_114 , V_113 , V_119 , V_120 , V_118 ) ;
ASSERT ( V_114 ) ;
switch ( V_118 ) {
case V_121 :
if ( V_120 == V_122 )
return F_89 ( V_114 , V_107 ) ;
else
return F_91 ( V_114 , V_107 ) ;
case V_123 :
return V_114 == V_113 ;
case V_124 :
return true ;
case V_125 :
return V_114 != V_113 ;
default:
F_80 ( L_8 ,
V_118 ) ;
return false ;
}
}
int F_94 ( T_1 V_5 , T_1 V_126 ,
const unsigned long * V_2 , T_1 V_127 )
{
T_1 V_128 ;
int V_32 , V_129 = - 1 ;
V_128 = V_5 % V_126 ;
for ( V_32 = 0 ; V_32 <= V_128 ; V_32 ++ ) {
V_129 = F_95 ( V_2 , V_127 , V_129 + 1 ) ;
F_67 ( V_129 == V_127 ) ;
}
return V_129 ;
}
static void F_96 ( struct V_29 * V_29 )
{
if ( ! V_29 -> V_8 . V_130 ) {
V_29 -> V_8 . V_130 = true ;
F_97 ( V_131
L_9 ) ;
}
}
static bool F_98 ( struct V_29 * V_29 , struct V_6 * * V_132 ,
struct V_86 * V_87 , struct V_12 * V_13 )
{
if ( V_29 -> V_8 . V_117 ) {
if ( ( V_87 -> V_14 == V_109 &&
V_13 -> V_17 != V_18 ) )
return true ;
if ( V_87 -> V_14 == V_108 )
return true ;
} else {
bool V_133 = V_132 && * V_132 && F_28 ( * V_132 ) ;
if ( V_87 -> V_14 == ( V_133 ?
V_108 : V_109 ) )
return true ;
}
return false ;
}
static inline bool F_99 ( struct V_29 * V_29 ,
struct V_6 * * V_132 , struct V_86 * V_87 ,
struct V_12 * V_13 , struct V_6 * * * V_134 ,
unsigned long * V_2 )
{
int V_32 , V_135 ;
if ( V_87 -> V_136 == V_123 && V_132 ) {
* V_134 = V_132 ;
* V_2 = 1 ;
return true ;
} else if ( V_87 -> V_136 )
return false ;
if ( ! V_13 || F_98 ( V_29 , V_132 , V_87 , V_13 ) )
return false ;
if ( V_87 -> V_120 == V_122 ) {
if ( V_87 -> V_14 > V_13 -> V_20 ) {
* V_2 = 0 ;
} else {
* V_134 = & V_13 -> V_22 [ V_87 -> V_14 ] ;
* V_2 = 1 ;
}
return true ;
}
* V_2 = 0 ;
if ( ! F_15 ( V_13 , V_87 -> V_14 , V_134 ,
( T_2 * ) V_2 ) )
return false ;
if ( ! F_100 ( V_87 ) )
return true ;
if ( ! F_101 () ) {
V_135 = - 1 ;
F_102 (i, bitmap, 16 ) {
if ( ! ( * V_134 ) [ V_32 ] )
continue;
if ( V_135 < 0 )
V_135 = V_32 ;
else if ( F_103 ( ( * V_134 ) [ V_32 ] -> V_4 ,
( * V_134 ) [ V_135 ] -> V_4 ) < 0 )
V_135 = V_32 ;
}
} else {
if ( ! * V_2 )
return true ;
V_135 = F_94 ( V_87 -> V_5 , F_104 ( * V_2 ) ,
V_2 , 16 ) ;
if ( ! ( * V_134 ) [ V_135 ] ) {
F_96 ( V_29 ) ;
* V_2 = 0 ;
return true ;
}
}
* V_2 = ( V_135 >= 0 ) ? 1 << V_135 : 0 ;
return true ;
}
bool F_105 ( struct V_29 * V_29 , struct V_6 * V_132 ,
struct V_86 * V_87 , int * V_137 , struct V_88 * V_88 )
{
struct V_12 * V_13 ;
unsigned long V_2 ;
struct V_6 * * V_134 = NULL ;
int V_32 ;
bool V_138 ;
* V_137 = - 1 ;
if ( V_87 -> V_136 == V_123 ) {
* V_137 = F_72 ( V_132 -> V_4 , V_87 , V_88 ) ;
return true ;
}
F_106 () ;
V_13 = F_107 ( V_29 -> V_8 . V_42 ) ;
V_138 = F_99 ( V_29 , & V_132 , V_87 , V_13 , & V_134 , & V_2 ) ;
if ( V_138 )
F_102 (i, &bitmap, 16 ) {
if ( ! V_134 [ V_32 ] )
continue;
if ( * V_137 < 0 )
* V_137 = 0 ;
* V_137 += F_72 ( V_134 [ V_32 ] -> V_4 , V_87 , V_88 ) ;
}
F_108 () ;
return V_138 ;
}
bool F_109 ( struct V_29 * V_29 , struct V_86 * V_87 ,
struct V_3 * * V_139 )
{
struct V_12 * V_13 ;
unsigned long V_2 ;
struct V_6 * * V_134 = NULL ;
bool V_138 = false ;
if ( V_87 -> V_136 )
return false ;
F_106 () ;
V_13 = F_107 ( V_29 -> V_8 . V_42 ) ;
if ( F_99 ( V_29 , NULL , V_87 , V_13 , & V_134 , & V_2 ) &&
F_104 ( V_2 ) == 1 ) {
unsigned long V_32 = F_110 ( & V_2 , 16 ) ;
if ( V_134 [ V_32 ] ) {
* V_139 = V_134 [ V_32 ] -> V_4 ;
V_138 = true ;
}
}
F_108 () ;
return V_138 ;
}
static int F_73 ( struct V_6 * V_7 , int V_89 ,
int V_5 , int V_90 , int V_91 ,
struct V_88 * V_88 )
{
int V_78 = 0 ;
struct V_3 * V_4 = V_7 -> V_4 ;
F_111 ( V_4 -> V_112 , V_89 ,
V_91 , V_5 ) ;
switch ( V_89 ) {
case V_140 :
V_4 -> V_8 . V_141 ++ ;
case V_142 :
if ( F_65 ( V_91 && ! V_90 ) )
break;
if ( F_65 ( ! F_12 ( V_7 ) ) )
break;
V_78 = 1 ;
if ( V_88 ) {
F_82 ( V_4 -> V_112 , V_88 -> V_13 ) ;
V_88 -> V_143 [ V_4 -> V_112 ] = V_5 ;
}
if ( F_1 ( V_5 , V_7 -> V_9 + V_144 ) != ! ! V_91 ) {
if ( V_91 )
F_112 ( V_5 , V_7 -> V_9 + V_144 ) ;
else
F_6 ( V_5 , V_7 -> V_9 + V_144 ) ;
}
if ( V_4 -> V_8 . V_80 )
V_81 -> V_145 ( V_4 , V_5 ) ;
else {
F_113 ( V_5 , V_7 ) ;
F_61 ( V_77 , V_4 ) ;
F_114 ( V_4 ) ;
}
break;
case V_146 :
V_78 = 1 ;
V_4 -> V_8 . V_147 . V_148 = 1 ;
F_61 ( V_77 , V_4 ) ;
F_114 ( V_4 ) ;
break;
case V_149 :
V_78 = 1 ;
F_61 ( V_150 , V_4 ) ;
F_114 ( V_4 ) ;
break;
case V_62 :
V_78 = 1 ;
F_115 ( V_4 ) ;
F_114 ( V_4 ) ;
break;
case V_151 :
if ( ! V_91 || V_90 ) {
V_78 = 1 ;
V_7 -> V_152 = ( 1UL << V_153 ) ;
F_116 () ;
F_61 ( V_77 , V_4 ) ;
F_114 ( V_4 ) ;
} else {
F_80 ( L_10 ,
V_4 -> V_112 ) ;
}
break;
case V_154 :
F_80 ( L_11 ,
V_4 -> V_112 , V_5 ) ;
V_78 = 1 ;
V_7 -> V_155 = V_5 ;
F_116 () ;
F_117 ( V_156 , & V_7 -> V_152 ) ;
F_61 ( V_77 , V_4 ) ;
F_114 ( V_4 ) ;
break;
case V_157 :
break;
default:
F_97 ( V_158 L_12 ,
V_89 ) ;
break;
}
return V_78 ;
}
int F_103 ( struct V_3 * V_159 , struct V_3 * V_160 )
{
return V_159 -> V_8 . V_141 - V_160 -> V_8 . V_141 ;
}
static bool F_118 ( struct V_6 * V_7 , int V_5 )
{
return F_2 ( V_5 , V_7 -> V_4 -> V_8 . V_161 ) ;
}
static void F_119 ( struct V_6 * V_7 , int V_5 )
{
int V_162 ;
if ( ! F_118 ( V_7 , V_5 ) )
return;
if ( F_120 ( V_7 -> V_4 -> V_29 ) ) {
V_7 -> V_4 -> V_8 . V_163 = V_5 ;
F_61 ( V_164 , V_7 -> V_4 ) ;
return;
}
if ( F_1 ( V_5 , V_7 -> V_9 + V_144 ) )
V_162 = V_165 ;
else
V_162 = V_166 ;
F_121 ( V_7 -> V_4 , V_5 , V_162 ) ;
}
static int F_122 ( struct V_6 * V_7 )
{
int V_5 = F_68 ( V_7 ) ;
F_123 ( V_7 , V_5 ) ;
if ( V_5 == - 1 )
return V_5 ;
F_70 ( V_5 , V_7 ) ;
F_85 ( V_7 ) ;
if ( F_2 ( V_5 , F_124 ( V_7 -> V_4 ) -> V_167 ) )
F_125 ( V_7 -> V_4 , V_5 ) ;
F_119 ( V_7 , V_5 ) ;
F_61 ( V_77 , V_7 -> V_4 ) ;
return V_5 ;
}
void F_126 ( struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
F_123 ( V_7 , V_5 ) ;
F_119 ( V_7 , V_5 ) ;
F_61 ( V_77 , V_7 -> V_4 ) ;
}
static void F_127 ( struct V_6 * V_7 )
{
T_1 V_168 = F_27 ( V_7 , V_169 ) ;
T_1 V_170 = F_27 ( V_7 , V_171 ) ;
struct V_86 V_87 ;
V_87 . V_5 = V_168 & V_54 ;
V_87 . V_89 = V_168 & V_61 ;
V_87 . V_120 = V_168 & V_172 ;
V_87 . V_90 = ( V_168 & V_173 ) != 0 ;
V_87 . V_91 = V_168 & V_174 ;
V_87 . V_136 = V_168 & V_175 ;
V_87 . V_176 = false ;
if ( F_28 ( V_7 ) )
V_87 . V_14 = V_170 ;
else
V_87 . V_14 = F_88 ( V_170 ) ;
F_128 ( V_168 , V_87 . V_14 ) ;
F_80 ( L_13
L_14
L_15
L_16 ,
V_170 , V_168 , V_87 . V_136 , V_87 . V_14 ,
V_87 . V_91 , V_87 . V_90 , V_87 . V_120 , V_87 . V_89 ,
V_87 . V_5 , V_87 . V_176 ) ;
F_129 ( V_7 -> V_4 -> V_29 , V_7 , & V_87 , NULL ) ;
}
static T_1 F_130 ( struct V_6 * V_7 )
{
T_4 V_177 , V_178 ;
T_5 V_179 ;
T_1 V_180 ;
ASSERT ( V_7 != NULL ) ;
if ( F_27 ( V_7 , V_181 ) == 0 ||
V_7 -> V_55 . V_182 == 0 )
return 0 ;
V_178 = F_131 () ;
V_177 = F_132 ( V_7 -> V_55 . V_183 , V_178 ) ;
if ( F_133 ( V_177 ) < 0 )
V_177 = 0 ;
V_179 = F_134 ( F_133 ( V_177 ) , V_7 -> V_55 . V_182 ) ;
V_180 = F_135 ( V_179 ,
( V_184 * V_7 -> V_185 ) ) ;
return V_180 ;
}
static void F_136 ( struct V_6 * V_7 , bool V_186 )
{
struct V_3 * V_4 = V_7 -> V_4 ;
struct V_187 * V_188 = V_4 -> V_188 ;
F_61 ( V_189 , V_4 ) ;
V_188 -> V_190 . V_191 = F_137 ( V_4 ) ;
V_188 -> V_190 . V_192 = V_186 ;
}
static inline void F_138 ( struct V_6 * V_7 , bool V_186 )
{
if ( V_7 -> V_4 -> V_8 . V_193 )
F_136 ( V_7 , V_186 ) ;
}
static T_1 F_139 ( struct V_6 * V_7 , unsigned int V_19 )
{
T_1 V_43 = 0 ;
if ( V_19 >= V_194 )
return 0 ;
switch ( V_19 ) {
case V_195 :
F_80 ( L_17 ) ;
break;
case V_196 :
if ( F_48 ( V_7 ) )
return 0 ;
V_43 = F_130 ( V_7 ) ;
break;
case V_105 :
F_85 ( V_7 ) ;
V_43 = F_27 ( V_7 , V_19 ) ;
break;
case V_106 :
F_138 ( V_7 , false ) ;
default:
V_43 = F_27 ( V_7 , V_19 ) ;
break;
}
return V_43 ;
}
static inline struct V_6 * F_140 ( struct V_197 * V_198 )
{
return F_18 ( V_198 , struct V_6 , V_198 ) ;
}
int F_141 ( struct V_6 * V_7 , T_1 V_19 , int V_199 ,
void * V_93 )
{
unsigned char V_200 = V_19 & 0xf ;
T_1 V_78 ;
static const V_35 V_201 = 0x43ff01ffffffe70cULL ;
if ( ( V_200 + V_199 ) > 4 ) {
F_80 ( L_18 ,
V_19 , V_199 ) ;
return 1 ;
}
if ( V_19 > 0x3f0 || ! ( V_201 & ( 1ULL << ( V_19 >> 4 ) ) ) ) {
F_80 ( L_19 ,
V_19 ) ;
return 1 ;
}
V_78 = F_139 ( V_7 , V_19 & ~ 0xf ) ;
F_142 ( V_19 , V_78 ) ;
switch ( V_199 ) {
case 1 :
case 2 :
case 4 :
memcpy ( V_93 , ( char * ) & V_78 + V_200 , V_199 ) ;
break;
default:
F_97 ( V_158 L_20
L_21 , V_199 ) ;
break;
}
return 0 ;
}
static int F_143 ( struct V_6 * V_7 , T_6 V_202 )
{
return F_14 ( V_7 ) &&
V_202 >= V_7 -> V_203 &&
V_202 < V_7 -> V_203 + V_194 ;
}
static int F_144 ( struct V_3 * V_4 , struct V_197 * V_204 ,
T_6 V_205 , int V_199 , void * V_93 )
{
struct V_6 * V_7 = F_140 ( V_204 ) ;
T_1 V_19 = V_205 - V_7 -> V_203 ;
if ( ! F_143 ( V_7 , V_205 ) )
return - V_206 ;
F_141 ( V_7 , V_19 , V_199 , V_93 ) ;
return 0 ;
}
static void F_145 ( struct V_6 * V_7 )
{
T_1 V_207 , V_208 , V_209 ;
V_209 = F_27 ( V_7 , V_210 ) ;
V_207 = V_209 & 0xf ;
V_208 = ( ( V_207 & 0x3 ) | ( ( V_207 & 0x8 ) >> 1 ) ) + 1 ;
V_7 -> V_185 = 0x1 << ( V_208 & 0x7 ) ;
F_80 ( L_22 ,
V_7 -> V_185 ) ;
}
static void F_146 ( struct V_6 * V_7 )
{
T_1 V_56 = F_27 ( V_7 , V_211 ) &
V_7 -> V_55 . V_212 ;
if ( V_7 -> V_55 . V_56 != V_56 ) {
V_7 -> V_55 . V_56 = V_56 ;
F_147 ( & V_7 -> V_55 . V_213 ) ;
}
}
static void F_148 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_4 ;
struct V_214 * V_215 = & V_4 -> V_216 ;
struct V_217 * V_218 = & V_7 -> V_55 ;
if ( F_149 ( & V_7 -> V_55 . V_219 ) )
return;
F_150 ( & V_7 -> V_55 . V_219 ) ;
F_151 ( V_4 ) ;
if ( F_152 ( V_215 ) )
F_153 ( V_215 ) ;
if ( F_48 ( V_7 ) )
V_218 -> V_220 = V_218 -> V_221 ;
}
static bool F_154 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
T_1 V_71 = F_27 ( V_7 , V_211 ) ;
if ( F_14 ( V_7 ) ) {
int V_1 = V_71 & V_54 ;
void * V_2 = V_7 -> V_9 + V_10 ;
if ( V_4 -> V_8 . V_80 )
V_2 = V_7 -> V_9 + V_11 ;
if ( F_1 ( V_1 , V_2 ) )
return true ;
}
return false ;
}
void F_155 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
V_35 V_222 , V_223 ;
if ( ! F_51 ( V_4 ) )
return;
if ( V_7 -> V_55 . V_220 == 0 )
return;
if ( ! F_154 ( V_4 ) )
return;
V_223 = V_7 -> V_55 . V_220 ;
V_7 -> V_55 . V_220 = 0 ;
V_222 = F_156 ( V_4 , F_157 () ) ;
F_158 ( V_4 -> V_112 , V_222 - V_223 ) ;
if ( V_222 < V_223 )
F_159 ( F_16 ( V_223 - V_222 ,
F_160 ( V_4 , V_224 ) ) ) ;
}
static void F_161 ( struct V_6 * V_7 )
{
V_35 V_222 , V_221 = V_7 -> V_55 . V_221 ;
V_35 V_179 = 0 ;
T_4 V_225 ;
struct V_3 * V_4 = V_7 -> V_4 ;
unsigned long V_226 = V_4 -> V_8 . V_227 ;
unsigned long V_228 ;
T_4 V_178 ;
if ( F_65 ( ! V_221 || ! V_226 ) )
return;
F_162 ( V_228 ) ;
V_178 = F_131 () ;
V_222 = F_156 ( V_4 , F_157 () ) ;
if ( F_69 ( V_221 > V_222 ) ) {
V_179 = ( V_221 - V_222 ) * 1000000ULL ;
F_163 ( V_179 , V_226 ) ;
V_225 = F_164 ( V_178 , V_179 ) ;
V_225 = F_165 ( V_225 , V_224 ) ;
F_166 ( & V_7 -> V_55 . V_213 ,
V_225 , V_229 ) ;
} else
F_148 ( V_7 ) ;
F_167 ( V_228 ) ;
}
static void F_168 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_55 . V_182 )
return;
if ( F_46 ( V_7 ) &&
F_169 ( F_131 () ,
V_7 -> V_55 . V_183 ) ) {
F_148 ( V_7 ) ;
return;
}
F_166 ( & V_7 -> V_55 . V_213 ,
V_7 -> V_55 . V_183 ,
V_229 ) ;
}
static bool F_170 ( struct V_6 * V_7 )
{
T_4 V_178 ;
V_35 V_230 = F_157 () ;
V_178 = F_131 () ;
V_7 -> V_55 . V_182 = ( V_35 ) F_27 ( V_7 , V_181 )
* V_184 * V_7 -> V_185 ;
if ( ! V_7 -> V_55 . V_182 )
return false ;
if ( F_47 ( V_7 ) ) {
T_5 V_231 = V_232 * 1000LL ;
if ( V_7 -> V_55 . V_182 < V_231 ) {
F_171 (
L_23
L_24 ,
V_7 -> V_4 -> V_112 ,
V_7 -> V_55 . V_182 , V_231 ) ;
V_7 -> V_55 . V_182 = V_231 ;
}
}
F_80 ( L_25 V_233 L_26
V_234 L_27
L_28
L_29 V_234 L_30 , V_235 ,
V_184 , F_133 ( V_178 ) ,
F_27 ( V_7 , V_181 ) ,
V_7 -> V_55 . V_182 ,
F_133 ( F_164 ( V_178 ,
V_7 -> V_55 . V_182 ) ) ) ;
V_7 -> V_55 . V_221 = F_156 ( V_7 -> V_4 , V_230 ) +
F_160 ( V_7 -> V_4 , V_7 -> V_55 . V_182 ) ;
V_7 -> V_55 . V_183 = F_164 ( V_178 , V_7 -> V_55 . V_182 ) ;
return true ;
}
static void F_172 ( struct V_6 * V_7 )
{
V_7 -> V_55 . V_221 +=
F_160 ( V_7 -> V_4 , V_7 -> V_55 . V_182 ) ;
V_7 -> V_55 . V_183 =
F_164 ( V_7 -> V_55 . V_183 ,
V_7 -> V_55 . V_182 ) ;
}
bool F_173 ( struct V_3 * V_4 )
{
if ( ! F_51 ( V_4 ) )
return false ;
return V_4 -> V_8 . V_7 -> V_55 . V_236 ;
}
static void F_174 ( struct V_6 * V_7 )
{
V_81 -> F_174 ( V_7 -> V_4 ) ;
V_7 -> V_55 . V_236 = false ;
}
static bool F_175 ( struct V_6 * V_7 )
{
V_35 V_221 = V_7 -> V_55 . V_221 ;
if ( ( F_149 ( & V_7 -> V_55 . V_219 ) &&
! F_47 ( V_7 ) ) ||
V_81 -> V_237 ( V_7 -> V_4 , V_221 ) ) {
if ( V_7 -> V_55 . V_236 )
F_174 ( V_7 ) ;
} else {
V_7 -> V_55 . V_236 = true ;
F_147 ( & V_7 -> V_55 . V_213 ) ;
if ( F_149 ( & V_7 -> V_55 . V_219 ) &&
! F_47 ( V_7 ) )
F_174 ( V_7 ) ;
}
F_176 ( V_7 -> V_4 -> V_112 ,
V_7 -> V_55 . V_236 ) ;
return V_7 -> V_55 . V_236 ;
}
void F_177 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
F_178 ( ! V_7 -> V_55 . V_236 ) ;
F_178 ( F_152 ( & V_4 -> V_216 ) ) ;
F_174 ( V_7 ) ;
F_148 ( V_7 ) ;
if ( F_47 ( V_7 ) && V_7 -> V_55 . V_182 ) {
F_172 ( V_7 ) ;
if ( ! F_175 ( V_7 ) )
F_168 ( V_7 ) ;
}
}
void F_179 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
F_178 ( V_7 -> V_55 . V_236 ) ;
F_175 ( V_7 ) ;
}
void F_180 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
if ( ! V_7 -> V_55 . V_236 )
return;
F_174 ( V_7 ) ;
if ( F_149 ( & V_7 -> V_55 . V_219 ) )
return;
if ( F_47 ( V_7 ) || F_46 ( V_7 ) )
F_168 ( V_7 ) ;
else if ( F_48 ( V_7 ) )
F_161 ( V_7 ) ;
}
static void F_181 ( struct V_6 * V_7 )
{
F_182 ( & V_7 -> V_55 . V_219 , 0 ) ;
if ( F_47 ( V_7 ) || F_46 ( V_7 ) ) {
if ( F_170 ( V_7 ) &&
! ( V_81 -> V_237 && F_175 ( V_7 ) ) )
F_168 ( V_7 ) ;
} else if ( F_48 ( V_7 ) ) {
if ( ! ( V_81 -> V_237 && F_175 ( V_7 ) ) )
F_161 ( V_7 ) ;
}
}
static void F_183 ( struct V_6 * V_7 , T_1 V_238 )
{
bool V_239 = F_49 ( V_238 ) ;
if ( V_7 -> V_239 != V_239 ) {
V_7 -> V_239 = V_239 ;
if ( V_239 ) {
F_80 ( L_31
L_32 , V_7 -> V_4 -> V_112 ) ;
F_150 ( & V_7 -> V_4 -> V_29 -> V_8 . V_240 ) ;
} else
F_184 ( & V_7 -> V_4 -> V_29 -> V_8 . V_240 ) ;
}
}
int F_185 ( struct V_6 * V_7 , T_1 V_71 , T_1 V_43 )
{
int V_138 = 0 ;
F_186 ( V_71 , V_43 ) ;
switch ( V_71 ) {
case V_51 :
if ( ! F_28 ( V_7 ) )
F_41 ( V_7 , V_43 >> 24 ) ;
else
V_138 = 1 ;
break;
case V_106 :
F_138 ( V_7 , true ) ;
F_86 ( V_7 , V_43 & 0xff ) ;
break;
case V_241 :
F_122 ( V_7 ) ;
break;
case V_39 :
if ( ! F_28 ( V_7 ) )
F_42 ( V_7 , V_43 & V_242 ) ;
else
V_138 = 1 ;
break;
case V_40 :
if ( ! F_28 ( V_7 ) ) {
F_38 ( V_7 , V_40 , V_43 | 0x0FFFFFFF ) ;
F_20 ( V_7 -> V_4 -> V_29 ) ;
} else
V_138 = 1 ;
break;
case V_46 : {
T_1 V_16 = 0x3ff ;
if ( F_27 ( V_7 , V_70 ) & V_69 )
V_16 |= V_243 ;
F_37 ( V_7 , V_43 & V_16 ) ;
if ( ! ( V_43 & V_45 ) ) {
int V_32 ;
T_1 V_60 ;
for ( V_32 = 0 ; V_32 < V_244 ; V_32 ++ ) {
V_60 = F_27 ( V_7 ,
V_211 + 0x10 * V_32 ) ;
F_38 ( V_7 , V_211 + 0x10 * V_32 ,
V_60 | V_53 ) ;
}
F_146 ( V_7 ) ;
F_182 ( & V_7 -> V_55 . V_219 , 0 ) ;
}
break;
}
case V_169 :
F_38 ( V_7 , V_169 , V_43 & ~ ( 1 << 12 ) ) ;
F_127 ( V_7 ) ;
break;
case V_171 :
if ( ! F_28 ( V_7 ) )
V_43 &= 0xff000000 ;
F_38 ( V_7 , V_171 , V_43 ) ;
break;
case V_245 :
F_183 ( V_7 , V_43 ) ;
case V_246 :
case V_247 :
case V_248 :
case V_249 :
if ( ! F_13 ( V_7 ) )
V_43 |= V_53 ;
V_43 &= V_250 [ ( V_71 - V_211 ) >> 4 ] ;
F_38 ( V_7 , V_71 , V_43 ) ;
break;
case V_211 :
if ( ! F_13 ( V_7 ) )
V_43 |= V_53 ;
V_43 &= ( V_250 [ 0 ] | V_7 -> V_55 . V_212 ) ;
F_38 ( V_7 , V_211 , V_43 ) ;
F_146 ( V_7 ) ;
break;
case V_181 :
if ( F_48 ( V_7 ) )
break;
F_147 ( & V_7 -> V_55 . V_213 ) ;
F_38 ( V_7 , V_181 , V_43 ) ;
F_181 ( V_7 ) ;
break;
case V_210 :
if ( V_43 & 4 )
F_80 ( L_33 , V_43 ) ;
F_38 ( V_7 , V_210 , V_43 ) ;
F_145 ( V_7 ) ;
break;
case V_251 :
if ( F_28 ( V_7 ) && V_43 != 0 ) {
F_80 ( L_34 , V_43 ) ;
V_138 = 1 ;
}
break;
case V_252 :
if ( F_28 ( V_7 ) ) {
F_185 ( V_7 , V_169 , 0x40000 | ( V_43 & 0xff ) ) ;
} else
V_138 = 1 ;
break;
default:
V_138 = 1 ;
break;
}
if ( V_138 )
F_80 ( L_35 , V_71 ) ;
return V_138 ;
}
static int F_187 ( struct V_3 * V_4 , struct V_197 * V_204 ,
T_6 V_205 , int V_199 , const void * V_93 )
{
struct V_6 * V_7 = F_140 ( V_204 ) ;
unsigned int V_19 = V_205 - V_7 -> V_203 ;
T_1 V_43 ;
if ( ! F_143 ( V_7 , V_205 ) )
return - V_206 ;
if ( V_199 != 4 || ( V_19 & 0xf ) ) {
F_80 ( L_36 , V_199 , ( long ) V_205 ) ;
return 0 ;
}
V_43 = * ( T_1 * ) V_93 ;
if ( V_19 != V_241 )
F_80 ( L_37
L_38 , V_235 , V_19 , V_199 , V_43 ) ;
F_185 ( V_7 , V_19 & 0xff0 , V_43 ) ;
return 0 ;
}
void F_188 ( struct V_3 * V_4 )
{
F_185 ( V_4 -> V_8 . V_7 , V_241 , 0 ) ;
}
void F_189 ( struct V_3 * V_4 , T_1 V_19 )
{
T_1 V_43 = 0 ;
V_19 &= 0xff0 ;
F_141 ( V_4 -> V_8 . V_7 , V_19 , 4 , & V_43 ) ;
F_185 ( V_4 -> V_8 . V_7 , V_19 , V_43 ) ;
}
void F_190 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
if ( ! V_4 -> V_8 . V_7 )
return;
F_147 ( & V_7 -> V_55 . V_213 ) ;
if ( ! ( V_4 -> V_8 . V_253 & V_254 ) )
F_39 ( & V_255 ) ;
if ( ! V_7 -> V_47 )
F_39 ( & V_48 ) ;
if ( V_7 -> V_9 )
F_191 ( ( unsigned long ) V_7 -> V_9 ) ;
F_192 ( V_7 ) ;
}
V_35 F_193 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
if ( ! F_51 ( V_4 ) )
return 0 ;
return V_7 -> V_55 . V_221 ;
}
V_35 F_194 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
if ( ! F_51 ( V_4 ) ||
! F_48 ( V_7 ) )
return 0 ;
return V_7 -> V_55 . V_221 ;
}
void F_195 ( struct V_3 * V_4 , V_35 V_93 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
if ( ! F_51 ( V_4 ) || F_46 ( V_7 ) ||
F_47 ( V_7 ) )
return;
F_147 ( & V_7 -> V_55 . V_213 ) ;
V_7 -> V_55 . V_221 = V_93 ;
F_181 ( V_7 ) ;
}
void F_196 ( struct V_3 * V_4 , unsigned long V_256 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
F_86 ( V_7 , ( ( V_256 & 0x0f ) << 4 )
| ( F_27 ( V_7 , V_106 ) & 4 ) ) ;
}
V_35 F_197 ( struct V_3 * V_4 )
{
V_35 V_100 ;
V_100 = ( V_35 ) F_27 ( V_4 -> V_8 . V_7 , V_106 ) ;
return ( V_100 & 0xf0 ) >> 4 ;
}
void F_198 ( struct V_3 * V_4 , V_35 V_257 )
{
V_35 V_258 = V_4 -> V_8 . V_253 ;
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
if ( ! V_7 )
V_257 |= V_259 ;
V_4 -> V_8 . V_253 = V_257 ;
if ( ( V_258 ^ V_257 ) & V_254 )
F_199 ( V_4 ) ;
if ( ! V_7 )
return;
if ( ( V_258 ^ V_257 ) & V_254 ) {
if ( V_257 & V_254 ) {
F_41 ( V_7 , V_4 -> V_112 ) ;
F_39 ( & V_255 ) ;
} else {
F_40 ( & V_255 . V_49 ) ;
F_20 ( V_4 -> V_29 ) ;
}
}
if ( ( V_258 ^ V_257 ) & V_260 ) {
if ( V_257 & V_260 ) {
F_43 ( V_7 , V_4 -> V_112 ) ;
V_81 -> V_261 ( V_4 , true ) ;
} else
V_81 -> V_261 ( V_4 , false ) ;
}
V_7 -> V_203 = V_7 -> V_4 -> V_8 . V_253 &
V_262 ;
if ( ( V_257 & V_254 ) &&
V_7 -> V_203 != V_263 )
F_200 ( L_39 ) ;
F_80 ( L_40 V_234 L_41
L_42 , V_7 -> V_4 -> V_8 . V_253 , V_7 -> V_203 ) ;
}
void F_201 ( struct V_3 * V_4 , bool V_264 )
{
struct V_6 * V_7 ;
int V_32 ;
F_80 ( L_43 , V_235 ) ;
ASSERT ( V_4 ) ;
V_7 = V_4 -> V_8 . V_7 ;
ASSERT ( V_7 != NULL ) ;
F_147 ( & V_7 -> V_55 . V_213 ) ;
if ( ! V_264 ) {
F_198 ( V_4 , V_263 |
V_254 ) ;
F_41 ( V_7 , V_4 -> V_112 ) ;
}
F_50 ( V_7 -> V_4 ) ;
for ( V_32 = 0 ; V_32 < V_244 ; V_32 ++ )
F_38 ( V_7 , V_211 + 0x10 * V_32 , V_53 ) ;
F_146 ( V_7 ) ;
if ( F_202 ( V_4 -> V_29 , V_265 ) )
F_38 ( V_7 , V_245 ,
F_203 ( 0 , V_266 ) ) ;
F_183 ( V_7 , F_27 ( V_7 , V_245 ) ) ;
F_38 ( V_7 , V_40 , 0xffffffffU ) ;
F_37 ( V_7 , 0xff ) ;
F_38 ( V_7 , V_106 , 0 ) ;
if ( ! F_28 ( V_7 ) )
F_42 ( V_7 , 0 ) ;
F_38 ( V_7 , V_251 , 0 ) ;
F_38 ( V_7 , V_169 , 0 ) ;
F_38 ( V_7 , V_171 , 0 ) ;
F_38 ( V_7 , V_210 , 0 ) ;
F_38 ( V_7 , V_181 , 0 ) ;
for ( V_32 = 0 ; V_32 < 8 ; V_32 ++ ) {
F_38 ( V_7 , V_11 + 0x10 * V_32 , 0 ) ;
F_38 ( V_7 , V_10 + 0x10 * V_32 , 0 ) ;
F_38 ( V_7 , V_144 + 0x10 * V_32 , 0 ) ;
}
V_7 -> V_79 = V_4 -> V_8 . V_80 ;
V_7 -> V_84 = V_4 -> V_8 . V_80 ? 1 : 0 ;
V_7 -> V_85 = - 1 ;
F_145 ( V_7 ) ;
F_182 ( & V_7 -> V_55 . V_219 , 0 ) ;
if ( F_204 ( V_4 ) )
F_198 ( V_4 ,
V_4 -> V_8 . V_253 | V_259 ) ;
V_4 -> V_8 . V_92 . V_94 = 0 ;
F_85 ( V_7 ) ;
V_4 -> V_8 . V_141 = 0 ;
V_4 -> V_8 . V_98 = 0 ;
F_80 ( L_44
L_45 V_234 L_46 , V_235 ,
V_4 , F_25 ( V_7 ) ,
V_4 -> V_8 . V_253 , V_7 -> V_203 ) ;
}
static bool F_205 ( struct V_6 * V_7 )
{
return F_47 ( V_7 ) ;
}
int F_206 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
if ( F_12 ( V_7 ) && F_44 ( V_7 , V_211 ) )
return F_149 ( & V_7 -> V_55 . V_219 ) ;
return 0 ;
}
int F_207 ( struct V_6 * V_7 , int V_52 )
{
T_1 V_71 = F_27 ( V_7 , V_52 ) ;
int V_5 , V_17 , V_91 ;
if ( F_14 ( V_7 ) && ! ( V_71 & V_53 ) ) {
V_5 = V_71 & V_54 ;
V_17 = V_71 & V_61 ;
V_91 = V_71 & V_267 ;
return F_73 ( V_7 , V_17 , V_5 , 1 , V_91 ,
NULL ) ;
}
return 0 ;
}
void F_208 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
if ( V_7 )
F_207 ( V_7 , V_245 ) ;
}
static enum V_268 F_209 ( struct V_269 * V_93 )
{
struct V_217 * V_218 = F_18 ( V_93 , struct V_217 , V_213 ) ;
struct V_6 * V_7 = F_18 ( V_218 , struct V_6 , V_55 ) ;
F_148 ( V_7 ) ;
if ( F_205 ( V_7 ) ) {
F_172 ( V_7 ) ;
F_210 ( & V_218 -> V_213 , V_218 -> V_182 ) ;
return V_270 ;
} else
return V_271 ;
}
int F_211 ( struct V_3 * V_4 )
{
struct V_6 * V_7 ;
ASSERT ( V_4 != NULL ) ;
F_80 ( L_47 , V_4 -> V_112 ) ;
V_7 = F_212 ( sizeof( * V_7 ) , V_272 ) ;
if ( ! V_7 )
goto V_273;
V_4 -> V_8 . V_7 = V_7 ;
V_7 -> V_9 = ( void * ) F_213 ( V_272 ) ;
if ( ! V_7 -> V_9 ) {
F_97 ( V_158 L_48 ,
V_4 -> V_112 ) ;
goto V_274;
}
V_7 -> V_4 = V_4 ;
F_214 ( & V_7 -> V_55 . V_213 , V_275 ,
V_229 ) ;
V_7 -> V_55 . V_213 . V_276 = F_209 ;
V_4 -> V_8 . V_253 = V_254 ;
F_40 ( & V_48 . V_49 ) ;
F_201 ( V_4 , false ) ;
F_215 ( & V_7 -> V_198 , & V_277 ) ;
return 0 ;
V_274:
F_192 ( V_7 ) ;
V_273:
return - V_278 ;
}
int F_216 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
int V_279 ;
if ( ! F_12 ( V_7 ) )
return - 1 ;
F_85 ( V_7 ) ;
V_279 = F_63 ( V_7 ) ;
if ( ( V_279 == - 1 ) ||
( ( V_279 & 0xF0 ) <= F_27 ( V_7 , V_105 ) ) )
return - 1 ;
return V_279 ;
}
int F_217 ( struct V_3 * V_4 )
{
T_1 V_280 = F_27 ( V_4 -> V_8 . V_7 , V_245 ) ;
int V_137 = 0 ;
if ( ! F_14 ( V_4 -> V_8 . V_7 ) )
V_137 = 1 ;
if ( ( V_280 & V_53 ) == 0 &&
F_218 ( V_280 ) == V_266 )
V_137 = 1 ;
return V_137 ;
}
void F_219 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
if ( F_149 ( & V_7 -> V_55 . V_219 ) > 0 ) {
F_207 ( V_7 , V_211 ) ;
if ( F_48 ( V_7 ) )
V_7 -> V_55 . V_221 = 0 ;
if ( F_46 ( V_7 ) ) {
V_7 -> V_55 . V_221 = 0 ;
V_7 -> V_55 . V_183 = 0 ;
}
F_182 ( & V_7 -> V_55 . V_219 , 0 ) ;
}
}
int F_220 ( struct V_3 * V_4 )
{
int V_5 = F_216 ( V_4 ) ;
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
if ( V_5 == - 1 )
return - 1 ;
F_66 ( V_5 , V_7 ) ;
F_85 ( V_7 ) ;
F_64 ( V_5 , V_7 ) ;
if ( F_2 ( V_5 , F_124 ( V_4 ) -> V_281 ) ) {
F_70 ( V_5 , V_7 ) ;
F_85 ( V_7 ) ;
}
return V_5 ;
}
static int F_221 ( struct V_3 * V_4 ,
struct V_282 * V_283 , bool V_284 )
{
if ( F_28 ( V_4 -> V_8 . V_7 ) ) {
T_1 * V_50 = ( T_1 * ) ( V_283 -> V_9 + V_51 ) ;
if ( V_4 -> V_29 -> V_8 . V_285 ) {
if ( * V_50 != V_4 -> V_112 )
return - V_286 ;
} else {
if ( V_284 )
* V_50 >>= 24 ;
else
* V_50 <<= 24 ;
}
}
return 0 ;
}
int F_222 ( struct V_3 * V_4 , struct V_282 * V_283 )
{
memcpy ( V_283 -> V_9 , V_4 -> V_8 . V_7 -> V_9 , sizeof( * V_283 ) ) ;
return F_221 ( V_4 , V_283 , false ) ;
}
int F_223 ( struct V_3 * V_4 , struct V_282 * V_283 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
int V_137 ;
F_198 ( V_4 , V_4 -> V_8 . V_253 ) ;
F_37 ( V_7 , * ( ( T_1 * ) ( V_283 -> V_9 + V_46 ) ) ) ;
V_137 = F_221 ( V_4 , V_283 , true ) ;
if ( V_137 )
return V_137 ;
memcpy ( V_4 -> V_8 . V_7 -> V_9 , V_283 -> V_9 , sizeof *V_283 ) ;
F_20 ( V_4 -> V_29 ) ;
F_50 ( V_4 ) ;
F_85 ( V_7 ) ;
F_147 ( & V_7 -> V_55 . V_213 ) ;
F_146 ( V_7 ) ;
F_183 ( V_7 , F_27 ( V_7 , V_245 ) ) ;
F_145 ( V_7 ) ;
F_181 ( V_7 ) ;
V_7 -> V_79 = true ;
V_7 -> V_84 = V_4 -> V_8 . V_80 ?
1 : F_55 ( V_7 -> V_9 + V_10 ) ;
V_7 -> V_85 = - 1 ;
if ( V_4 -> V_8 . V_80 ) {
if ( V_81 -> V_287 )
V_81 -> V_287 ( V_4 ) ;
V_81 -> V_288 ( V_4 ,
F_63 ( V_7 ) ) ;
V_81 -> V_83 ( V_4 ,
F_68 ( V_7 ) ) ;
}
F_61 ( V_77 , V_4 ) ;
if ( F_224 ( V_4 -> V_29 ) )
F_225 ( V_4 ) ;
V_4 -> V_8 . V_141 = 0 ;
return 0 ;
}
void F_226 ( struct V_3 * V_4 )
{
struct V_269 * V_213 ;
if ( ! F_51 ( V_4 ) )
return;
V_213 = & V_4 -> V_8 . V_7 -> V_55 . V_213 ;
if ( F_147 ( V_213 ) )
F_227 ( V_213 , V_229 ) ;
}
static void F_228 ( struct V_3 * V_4 ,
struct V_6 * V_7 )
{
bool V_219 ;
int V_5 ;
F_67 ( ! F_78 ( V_4 ) ) ;
V_219 = F_79 ( V_4 ) ;
F_83 ( V_4 ) ;
if ( V_219 )
return;
V_5 = F_122 ( V_7 ) ;
F_229 ( V_7 , V_5 ) ;
}
void F_230 ( struct V_3 * V_4 )
{
T_1 V_93 ;
if ( F_2 ( V_97 , & V_4 -> V_8 . V_98 ) )
F_228 ( V_4 , V_4 -> V_8 . V_7 ) ;
if ( ! F_2 ( V_289 , & V_4 -> V_8 . V_98 ) )
return;
if ( F_77 ( V_4 -> V_29 , & V_4 -> V_8 . V_7 -> V_290 , & V_93 ,
sizeof( T_1 ) ) )
return;
F_86 ( V_4 -> V_8 . V_7 , V_93 & 0xff ) ;
}
static void F_231 ( struct V_3 * V_4 ,
struct V_6 * V_7 )
{
if ( ! F_78 ( V_4 ) ||
V_7 -> V_79 ||
V_7 -> V_85 == - 1 ||
F_118 ( V_7 , V_7 -> V_85 ) ) {
return;
}
F_81 ( V_7 -> V_4 ) ;
}
void F_232 ( struct V_3 * V_4 )
{
T_1 V_93 , V_100 ;
int V_291 , V_292 ;
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
F_231 ( V_4 , V_7 ) ;
if ( ! F_2 ( V_289 , & V_4 -> V_8 . V_98 ) )
return;
V_100 = F_27 ( V_7 , V_106 ) & 0xff ;
V_291 = F_63 ( V_7 ) ;
if ( V_291 < 0 )
V_291 = 0 ;
V_292 = F_68 ( V_7 ) ;
if ( V_292 < 0 )
V_292 = 0 ;
V_93 = ( V_100 & 0xff ) | ( ( V_292 & 0xf0 ) << 8 ) | ( V_291 << 24 ) ;
F_75 ( V_4 -> V_29 , & V_4 -> V_8 . V_7 -> V_290 , & V_93 ,
sizeof( T_1 ) ) ;
}
int F_233 ( struct V_3 * V_4 , T_6 V_293 )
{
if ( V_293 ) {
if ( F_234 ( V_4 -> V_29 ,
& V_4 -> V_8 . V_7 -> V_290 ,
V_293 , sizeof( T_1 ) ) )
return - V_286 ;
F_82 ( V_289 , & V_4 -> V_8 . V_98 ) ;
} else {
F_84 ( V_289 , & V_4 -> V_8 . V_98 ) ;
}
V_4 -> V_8 . V_7 -> V_293 = V_293 ;
return 0 ;
}
int F_235 ( struct V_3 * V_4 , T_1 V_294 , V_35 V_93 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
T_1 V_71 = ( V_294 - V_295 ) << 4 ;
if ( ! F_51 ( V_4 ) || ! F_28 ( V_7 ) )
return 1 ;
if ( V_71 == V_171 )
return 1 ;
if ( V_71 == V_169 )
F_185 ( V_7 , V_171 , ( T_1 ) ( V_93 >> 32 ) ) ;
return F_185 ( V_7 , V_71 , ( T_1 ) V_93 ) ;
}
int F_236 ( struct V_3 * V_4 , T_1 V_294 , V_35 * V_93 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
T_1 V_71 = ( V_294 - V_295 ) << 4 , V_296 , V_297 = 0 ;
if ( ! F_51 ( V_4 ) || ! F_28 ( V_7 ) )
return 1 ;
if ( V_71 == V_40 || V_71 == V_171 ) {
F_80 ( L_49 ,
V_71 ) ;
return 1 ;
}
if ( F_141 ( V_7 , V_71 , 4 , & V_296 ) )
return 1 ;
if ( V_71 == V_169 )
F_141 ( V_7 , V_171 , 4 , & V_297 ) ;
* V_93 = ( ( ( V_35 ) V_297 ) << 32 ) | V_296 ;
return 0 ;
}
int F_237 ( struct V_3 * V_4 , T_1 V_71 , V_35 V_93 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
if ( ! F_51 ( V_4 ) )
return 1 ;
if ( V_71 == V_169 )
F_185 ( V_7 , V_171 , ( T_1 ) ( V_93 >> 32 ) ) ;
return F_185 ( V_7 , V_71 , ( T_1 ) V_93 ) ;
}
int F_238 ( struct V_3 * V_4 , T_1 V_71 , V_35 * V_93 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
T_1 V_296 , V_297 = 0 ;
if ( ! F_51 ( V_4 ) )
return 1 ;
if ( F_141 ( V_7 , V_71 , 4 , & V_296 ) )
return 1 ;
if ( V_71 == V_169 )
F_141 ( V_7 , V_171 , 4 , & V_297 ) ;
* V_93 = ( ( ( V_35 ) V_297 ) << 32 ) | V_296 ;
return 0 ;
}
int F_239 ( struct V_3 * V_4 , V_35 V_93 )
{
V_35 V_202 = V_93 & ~ V_95 ;
if ( ! F_240 ( V_202 , 4 ) )
return 1 ;
V_4 -> V_8 . V_92 . V_94 = V_93 ;
if ( ! F_78 ( V_4 ) )
return 0 ;
return F_234 ( V_4 -> V_29 , & V_4 -> V_8 . V_92 . V_93 ,
V_202 , sizeof( T_3 ) ) ;
}
void F_241 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
T_3 V_155 ;
unsigned long V_298 ;
if ( ! F_51 ( V_4 ) || ! V_7 -> V_152 )
return;
if ( F_242 ( V_4 ) ) {
F_243 ( V_4 -> V_8 . V_299 == V_300 ) ;
if ( F_2 ( V_156 , & V_7 -> V_152 ) )
F_7 ( V_156 , & V_7 -> V_152 ) ;
return;
}
V_298 = F_59 ( & V_7 -> V_152 , 0 ) ;
if ( F_2 ( V_153 , & V_298 ) ) {
F_201 ( V_4 , true ) ;
F_244 ( V_4 , true ) ;
if ( F_204 ( V_7 -> V_4 ) )
V_4 -> V_8 . V_299 = V_301 ;
else
V_4 -> V_8 . V_299 = V_300 ;
}
if ( F_2 ( V_156 , & V_298 ) &&
V_4 -> V_8 . V_299 == V_300 ) {
F_245 () ;
V_155 = V_7 -> V_155 ;
F_80 ( L_50 ,
V_4 -> V_112 , V_155 ) ;
F_246 ( V_4 , V_155 ) ;
V_4 -> V_8 . V_299 = V_301 ;
}
}
void F_247 ( void )
{
F_248 ( & V_255 , V_302 ) ;
F_248 ( & V_48 , V_302 ) ;
}
void F_249 ( void )
{
F_250 ( & V_255 ) ;
F_250 ( & V_48 ) ;
}
