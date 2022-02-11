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
static inline bool F_20 ( struct V_15 * V_16 )
{
return ! ( V_16 -> V_17 & ( V_16 -> V_17 - 1 ) ) ;
}
static inline void
F_21 ( struct V_15 * V_16 , T_1 V_18 , T_2 * V_19 , T_2 * V_20 )
{
unsigned V_21 ;
F_22 ( V_22 != 4 ) ;
F_22 ( V_23 != 8 ) ;
F_22 ( V_24 != 16 ) ;
V_21 = V_16 -> V_17 ;
* V_19 = V_18 >> V_21 ;
* V_20 = V_18 & ( ( 1 << V_21 ) - 1 ) ;
}
static void F_23 ( struct V_25 * V_25 )
{
struct V_15 * V_26 , * V_27 = NULL ;
struct V_8 * V_9 ;
int V_28 ;
V_26 = F_24 ( sizeof( struct V_15 ) , V_29 ) ;
F_25 ( & V_25 -> V_11 . V_30 ) ;
if ( ! V_26 )
goto V_31;
F_26 (i, vcpu, kvm) {
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_2 V_19 , V_20 ;
T_1 V_32 , V_33 ;
if ( ! F_27 ( V_9 ) )
continue;
V_33 = F_18 ( V_2 ) ;
V_32 = F_19 ( V_2 , V_34 ) ;
if ( V_33 < F_28 ( V_26 -> V_35 ) )
V_26 -> V_35 [ V_33 ] = V_2 ;
if ( F_29 ( V_2 ) ) {
V_26 -> V_17 |= V_24 ;
} else if ( V_32 ) {
V_32 = F_30 ( V_32 ) ;
if ( F_19 ( V_2 , V_36 ) == V_37 )
V_26 -> V_17 |= V_23 ;
else
V_26 -> V_17 |= V_22 ;
}
if ( ! F_20 ( V_26 ) )
continue;
F_21 ( V_26 , V_32 , & V_19 , & V_20 ) ;
if ( V_20 && V_19 < F_28 ( V_26 -> V_38 ) )
V_26 -> V_38 [ V_19 ] [ F_31 ( V_20 ) - 1 ] = V_2 ;
}
V_31:
V_27 = F_32 ( V_25 -> V_11 . V_39 ,
F_33 ( & V_25 -> V_11 . V_30 ) ) ;
F_34 ( V_25 -> V_11 . V_39 , V_26 ) ;
F_35 ( & V_25 -> V_11 . V_30 ) ;
if ( V_27 )
F_36 ( V_27 , V_40 ) ;
F_37 ( V_25 ) ;
}
static inline void F_38 ( struct V_1 * V_2 , T_1 V_4 )
{
bool V_41 = V_4 & V_42 ;
F_1 ( V_2 , V_43 , V_4 ) ;
if ( V_41 != V_2 -> V_44 ) {
V_2 -> V_44 = V_41 ;
if ( V_41 ) {
F_39 ( & V_45 ) ;
F_23 ( V_2 -> V_9 -> V_25 ) ;
} else
F_40 ( & V_45 . V_46 ) ;
}
}
static inline void F_41 ( struct V_1 * V_2 , T_3 V_47 )
{
F_1 ( V_2 , V_14 , V_47 << 24 ) ;
F_23 ( V_2 -> V_9 -> V_25 ) ;
}
static inline void F_42 ( struct V_1 * V_2 , T_1 V_47 )
{
F_1 ( V_2 , V_34 , V_47 ) ;
F_23 ( V_2 -> V_9 -> V_25 ) ;
}
static inline int F_43 ( struct V_1 * V_2 , int V_48 )
{
return ! ( F_19 ( V_2 , V_48 ) & V_49 ) ;
}
static inline int F_44 ( struct V_1 * V_2 , int V_48 )
{
return F_19 ( V_2 , V_48 ) & V_50 ;
}
static inline int F_45 ( struct V_1 * V_2 )
{
return V_2 -> V_51 . V_52 == V_53 ;
}
static inline int F_46 ( struct V_1 * V_2 )
{
return V_2 -> V_51 . V_52 == V_54 ;
}
static inline int F_47 ( struct V_1 * V_2 )
{
return V_2 -> V_51 . V_52 == V_55 ;
}
static inline int F_48 ( T_1 V_56 )
{
return ( V_56 & ( V_57 | V_49 ) ) == V_58 ;
}
void F_49 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
struct V_59 * V_60 ;
T_1 V_61 = V_62 ;
if ( ! F_50 ( V_9 ) )
return;
V_60 = F_51 ( V_2 -> V_9 , 0x1 , 0 ) ;
if ( V_60 && ( V_60 -> V_63 & ( 1 << ( V_64 & 31 ) ) ) )
V_61 |= V_65 ;
F_1 ( V_2 , V_66 , V_61 ) ;
}
static int F_52 ( void * V_7 )
{
int V_6 ;
T_1 * V_67 ;
for ( V_6 = V_68 - V_69 ;
V_6 >= 0 ; V_6 -= V_69 ) {
V_67 = V_7 + F_5 ( V_6 ) ;
if ( * V_67 )
return F_53 ( * V_67 ) - 1 + V_6 ;
}
return - 1 ;
}
static T_3 F_54 ( void * V_7 )
{
int V_6 ;
T_1 * V_67 ;
T_3 V_70 = 0 ;
for ( V_6 = 0 ; V_6 < V_68 ; V_6 += V_69 ) {
V_67 = V_7 + F_5 ( V_6 ) ;
V_70 += F_55 ( * V_67 ) ;
}
return V_70 ;
}
void F_56 ( T_1 * V_71 , void * V_5 )
{
T_1 V_28 , V_72 ;
for ( V_28 = 0 ; V_28 <= 7 ; V_28 ++ ) {
V_72 = F_57 ( & V_71 [ V_28 ] , 0 ) ;
if ( V_72 )
* ( ( T_1 * ) ( V_5 + V_13 + V_28 * 0x10 ) ) |= V_72 ;
}
}
void F_58 ( struct V_8 * V_9 , T_1 * V_71 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
F_56 ( V_71 , V_2 -> V_5 ) ;
}
static inline void F_59 ( int V_6 , struct V_1 * V_2 )
{
F_7 ( V_6 , V_2 -> V_5 + V_13 ) ;
V_2 -> V_73 = true ;
}
static inline int F_60 ( struct V_1 * V_2 )
{
return F_52 ( V_2 -> V_5 + V_13 ) ;
}
static inline int F_61 ( struct V_1 * V_2 )
{
int V_74 ;
if ( ! V_2 -> V_73 )
return - 1 ;
V_75 -> V_76 ( V_2 -> V_9 ) ;
V_74 = F_60 ( V_2 ) ;
ASSERT ( V_74 == - 1 || V_74 >= 16 ) ;
return V_74 ;
}
static inline void F_62 ( int V_6 , struct V_1 * V_2 )
{
struct V_8 * V_9 ;
V_9 = V_2 -> V_9 ;
if ( F_63 ( F_64 ( V_9 -> V_25 ) ) ) {
F_9 ( V_6 , V_2 -> V_5 + V_13 ) ;
F_65 ( V_77 , V_9 ) ;
} else {
V_2 -> V_73 = false ;
F_9 ( V_6 , V_2 -> V_5 + V_13 ) ;
if ( F_60 ( V_2 ) != - 1 )
V_2 -> V_73 = true ;
}
}
static inline void F_66 ( int V_6 , struct V_1 * V_2 )
{
struct V_8 * V_9 ;
if ( F_11 ( V_6 , V_2 -> V_5 + V_12 ) )
return;
V_9 = V_2 -> V_9 ;
if ( F_63 ( V_75 -> V_78 ) )
V_75 -> V_78 ( V_9 -> V_25 , V_6 ) ;
else {
++ V_2 -> V_79 ;
F_67 ( V_2 -> V_79 > V_68 ) ;
V_2 -> V_80 = V_6 ;
}
}
static inline int F_68 ( struct V_1 * V_2 )
{
int V_74 ;
if ( ! V_2 -> V_79 )
return - 1 ;
if ( F_69 ( V_2 -> V_80 != - 1 ) )
return V_2 -> V_80 ;
V_74 = F_52 ( V_2 -> V_5 + V_12 ) ;
ASSERT ( V_74 == - 1 || V_74 >= 16 ) ;
return V_74 ;
}
static inline void F_70 ( int V_6 , struct V_1 * V_2 )
{
struct V_8 * V_9 ;
if ( ! F_13 ( V_6 , V_2 -> V_5 + V_12 ) )
return;
V_9 = V_2 -> V_9 ;
if ( F_63 ( V_75 -> V_78 ) )
V_75 -> V_78 ( V_9 -> V_25 ,
F_68 ( V_2 ) ) ;
else {
-- V_2 -> V_79 ;
F_67 ( V_2 -> V_79 < 0 ) ;
V_2 -> V_80 = - 1 ;
}
}
int F_71 ( struct V_8 * V_9 )
{
int V_81 ;
if ( ! F_50 ( V_9 ) )
return 0 ;
V_81 = F_61 ( V_9 -> V_11 . V_2 ) ;
return V_81 ;
}
int F_72 ( struct V_8 * V_9 , struct V_82 * V_83 ,
unsigned long * V_84 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
return F_73 ( V_2 , V_83 -> V_85 , V_83 -> V_10 ,
V_83 -> V_86 , V_83 -> V_87 , V_84 ) ;
}
static int F_74 ( struct V_8 * V_9 , T_3 V_4 )
{
return F_75 ( V_9 -> V_25 , & V_9 -> V_11 . V_88 . V_89 , & V_4 ,
sizeof( V_4 ) ) ;
}
static int F_76 ( struct V_8 * V_9 , T_3 * V_4 )
{
return F_77 ( V_9 -> V_25 , & V_9 -> V_11 . V_88 . V_89 , V_4 ,
sizeof( * V_4 ) ) ;
}
static inline bool F_78 ( struct V_8 * V_9 )
{
return V_9 -> V_11 . V_88 . V_90 & V_91 ;
}
static bool F_79 ( struct V_8 * V_9 )
{
T_3 V_4 ;
if ( F_76 ( V_9 , & V_4 ) < 0 )
F_80 ( L_1 ,
( unsigned long long ) V_9 -> V_11 . V_88 . V_90 ) ;
return V_4 & 0x1 ;
}
static void F_81 ( struct V_8 * V_9 )
{
if ( F_74 ( V_9 , V_92 ) < 0 ) {
F_80 ( L_2 ,
( unsigned long long ) V_9 -> V_11 . V_88 . V_90 ) ;
return;
}
F_82 ( V_93 , & V_9 -> V_11 . V_94 ) ;
}
static void F_83 ( struct V_8 * V_9 )
{
if ( F_74 ( V_9 , V_95 ) < 0 ) {
F_80 ( L_3 ,
( unsigned long long ) V_9 -> V_11 . V_88 . V_90 ) ;
return;
}
F_84 ( V_93 , & V_9 -> V_11 . V_94 ) ;
}
void F_85 ( struct V_8 * V_9 , T_1 * V_96 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < 8 ; V_28 ++ )
F_1 ( V_2 , V_97 + 0x10 * V_28 , V_96 [ V_28 ] ) ;
}
static void F_86 ( struct V_1 * V_2 )
{
T_1 V_98 , V_99 , V_100 , V_101 ;
int V_102 ;
V_101 = F_19 ( V_2 , V_103 ) ;
V_98 = F_19 ( V_2 , V_104 ) ;
V_102 = F_68 ( V_2 ) ;
V_99 = ( V_102 != - 1 ) ? V_102 : 0 ;
if ( ( V_98 & 0xf0 ) >= ( V_99 & 0xf0 ) )
V_100 = V_98 & 0xff ;
else
V_100 = V_99 & 0xf0 ;
F_80 ( L_4 ,
V_2 , V_100 , V_102 , V_99 ) ;
if ( V_101 != V_100 ) {
F_1 ( V_2 , V_103 , V_100 ) ;
if ( V_100 < V_101 )
F_65 ( V_77 , V_2 -> V_9 ) ;
}
}
static void F_87 ( struct V_1 * V_2 , T_1 V_98 )
{
F_1 ( V_2 , V_104 , V_98 ) ;
F_86 ( V_2 ) ;
}
static bool F_88 ( struct V_1 * V_2 , T_1 V_105 )
{
if ( F_29 ( V_2 ) )
return V_105 == V_106 ;
return F_89 ( V_105 ) == V_107 ;
}
static bool F_90 ( struct V_1 * V_2 , T_1 V_105 )
{
if ( F_88 ( V_2 , V_105 ) )
return true ;
if ( F_29 ( V_2 ) )
return V_105 == F_18 ( V_2 ) ;
return V_105 == F_91 ( F_18 ( V_2 ) ) ;
}
static bool F_92 ( struct V_1 * V_2 , T_1 V_105 )
{
T_1 V_108 ;
if ( F_88 ( V_2 , V_105 ) )
return true ;
V_108 = F_19 ( V_2 , V_34 ) ;
if ( F_29 ( V_2 ) )
return ( ( V_108 >> 16 ) == ( V_105 >> 16 ) )
&& ( V_108 & V_105 & 0xffff ) != 0 ;
V_108 = F_30 ( V_108 ) ;
V_105 = F_89 ( V_105 ) ;
switch ( F_19 ( V_2 , V_36 ) ) {
case V_37 :
return ( V_108 & V_105 ) != 0 ;
case V_109 :
return ( ( V_108 >> 4 ) == ( V_105 >> 4 ) )
&& ( V_108 & V_105 & 0xf ) != 0 ;
default:
F_80 ( L_5 ,
V_2 -> V_9 -> V_110 , F_19 ( V_2 , V_36 ) ) ;
return false ;
}
}
static T_1 F_93 ( unsigned int V_18 , struct V_1 * V_111 ,
struct V_1 * V_112 )
{
bool V_113 = V_111 != NULL ;
bool V_114 = F_29 ( V_113 ? V_111 : V_112 ) ;
if ( ! V_113 && V_18 == V_107 && V_114 )
return V_106 ;
return V_114 ? V_18 : F_91 ( V_18 ) ;
}
bool F_94 ( struct V_8 * V_9 , struct V_1 * V_111 ,
int V_115 , unsigned int V_116 , int V_117 )
{
struct V_1 * V_112 = V_9 -> V_11 . V_2 ;
T_1 V_105 = F_93 ( V_116 , V_111 , V_112 ) ;
F_80 ( L_6
L_7 ,
V_112 , V_111 , V_116 , V_117 , V_115 ) ;
ASSERT ( V_112 ) ;
switch ( V_115 ) {
case V_118 :
if ( V_117 == V_119 )
return F_90 ( V_112 , V_105 ) ;
else
return F_92 ( V_112 , V_105 ) ;
case V_120 :
return V_112 == V_111 ;
case V_121 :
return true ;
case V_122 :
return V_112 != V_111 ;
default:
F_80 ( L_8 ,
V_115 ) ;
return false ;
}
}
bool F_95 ( struct V_25 * V_25 , struct V_1 * V_123 ,
struct V_82 * V_83 , int * V_124 , unsigned long * V_84 )
{
struct V_15 * V_16 ;
unsigned long V_7 = 1 ;
struct V_1 * * V_125 ;
int V_28 ;
bool V_126 , V_127 ;
* V_124 = - 1 ;
if ( V_83 -> V_128 == V_120 ) {
* V_124 = F_72 ( V_123 -> V_9 , V_83 , V_84 ) ;
return true ;
}
if ( V_83 -> V_128 )
return false ;
V_127 = V_123 && F_29 ( V_123 ) ;
if ( V_83 -> V_18 == ( V_127 ? V_106 : V_107 ) )
return false ;
V_126 = true ;
F_96 () ;
V_16 = F_97 ( V_25 -> V_11 . V_39 ) ;
if ( ! V_16 ) {
V_126 = false ;
goto V_31;
}
if ( V_83 -> V_117 == V_119 ) {
if ( V_83 -> V_18 >= F_28 ( V_16 -> V_35 ) )
goto V_31;
V_125 = & V_16 -> V_35 [ V_83 -> V_18 ] ;
} else {
T_2 V_19 ;
if ( ! F_20 ( V_16 ) ) {
V_126 = false ;
goto V_31;
}
F_21 ( V_16 , V_83 -> V_18 , & V_19 , ( T_2 * ) & V_7 ) ;
if ( V_19 >= F_28 ( V_16 -> V_38 ) )
goto V_31;
V_125 = V_16 -> V_38 [ V_19 ] ;
if ( V_83 -> V_85 == V_129 ) {
int V_130 = - 1 ;
F_98 (i, &bitmap, 16 ) {
if ( ! V_125 [ V_28 ] )
continue;
if ( V_130 < 0 )
V_130 = V_28 ;
else if ( F_99 ( V_125 [ V_28 ] -> V_9 , V_125 [ V_130 ] -> V_9 ) < 0 )
V_130 = V_28 ;
}
V_7 = ( V_130 >= 0 ) ? 1 << V_130 : 0 ;
}
}
F_98 (i, &bitmap, 16 ) {
if ( ! V_125 [ V_28 ] )
continue;
if ( * V_124 < 0 )
* V_124 = 0 ;
* V_124 += F_72 ( V_125 [ V_28 ] -> V_9 , V_83 , V_84 ) ;
}
V_31:
F_100 () ;
return V_126 ;
}
static int F_73 ( struct V_1 * V_2 , int V_85 ,
int V_10 , int V_86 , int V_87 ,
unsigned long * V_84 )
{
int V_74 = 0 ;
struct V_8 * V_9 = V_2 -> V_9 ;
F_101 ( V_9 -> V_110 , V_85 ,
V_87 , V_10 ) ;
switch ( V_85 ) {
case V_129 :
V_9 -> V_11 . V_131 ++ ;
case V_132 :
if ( F_63 ( ! F_15 ( V_2 ) ) )
break;
V_74 = 1 ;
if ( V_84 )
F_82 ( V_9 -> V_110 , V_84 ) ;
if ( V_75 -> V_133 )
V_75 -> V_133 ( V_9 , V_10 ) ;
else {
F_59 ( V_10 , V_2 ) ;
F_65 ( V_77 , V_9 ) ;
F_102 ( V_9 ) ;
}
break;
case V_134 :
V_74 = 1 ;
V_9 -> V_11 . V_135 . V_136 = 1 ;
F_65 ( V_77 , V_9 ) ;
F_102 ( V_9 ) ;
break;
case V_137 :
F_80 ( L_9 ) ;
break;
case V_58 :
V_74 = 1 ;
F_103 ( V_9 ) ;
F_102 ( V_9 ) ;
break;
case V_138 :
if ( ! V_87 || V_86 ) {
V_74 = 1 ;
V_2 -> V_139 = ( 1UL << V_140 ) ;
F_104 () ;
F_65 ( V_77 , V_9 ) ;
F_102 ( V_9 ) ;
} else {
F_80 ( L_10 ,
V_9 -> V_110 ) ;
}
break;
case V_141 :
F_80 ( L_11 ,
V_9 -> V_110 , V_10 ) ;
V_74 = 1 ;
V_2 -> V_142 = V_10 ;
F_104 () ;
F_8 ( V_143 , & V_2 -> V_139 ) ;
F_65 ( V_77 , V_9 ) ;
F_102 ( V_9 ) ;
break;
case V_144 :
break;
default:
F_105 ( V_145 L_12 ,
V_85 ) ;
break;
}
return V_74 ;
}
int F_99 ( struct V_8 * V_146 , struct V_8 * V_147 )
{
return V_146 -> V_11 . V_131 - V_147 -> V_11 . V_131 ;
}
static void F_106 ( struct V_1 * V_2 , int V_10 )
{
if ( F_107 ( V_2 -> V_9 -> V_25 , V_10 ) ) {
int V_148 ;
if ( F_2 ( V_10 , V_2 -> V_5 + V_97 ) )
V_148 = V_149 ;
else
V_148 = V_150 ;
F_108 ( V_2 -> V_9 , V_10 , V_148 ) ;
}
}
static int F_109 ( struct V_1 * V_2 )
{
int V_10 = F_68 ( V_2 ) ;
F_110 ( V_2 , V_10 ) ;
if ( V_10 == - 1 )
return V_10 ;
F_70 ( V_10 , V_2 ) ;
F_86 ( V_2 ) ;
F_106 ( V_2 , V_10 ) ;
F_65 ( V_77 , V_2 -> V_9 ) ;
return V_10 ;
}
void F_111 ( struct V_8 * V_9 , int V_10 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
F_110 ( V_2 , V_10 ) ;
F_106 ( V_2 , V_10 ) ;
F_65 ( V_77 , V_2 -> V_9 ) ;
}
static void F_112 ( struct V_1 * V_2 )
{
T_1 V_151 = F_19 ( V_2 , V_152 ) ;
T_1 V_153 = F_19 ( V_2 , V_154 ) ;
struct V_82 V_83 ;
V_83 . V_10 = V_151 & V_50 ;
V_83 . V_85 = V_151 & V_57 ;
V_83 . V_117 = V_151 & V_155 ;
V_83 . V_86 = V_151 & V_156 ;
V_83 . V_87 = V_151 & V_157 ;
V_83 . V_128 = V_151 & V_158 ;
if ( F_29 ( V_2 ) )
V_83 . V_18 = V_153 ;
else
V_83 . V_18 = F_89 ( V_153 ) ;
F_113 ( V_151 , V_83 . V_18 ) ;
F_80 ( L_13
L_14
L_15 ,
V_153 , V_151 , V_83 . V_128 , V_83 . V_18 ,
V_83 . V_87 , V_83 . V_86 , V_83 . V_117 , V_83 . V_85 ,
V_83 . V_10 ) ;
F_114 ( V_2 -> V_9 -> V_25 , V_2 , & V_83 , NULL ) ;
}
static T_1 F_115 ( struct V_1 * V_2 )
{
T_4 V_159 ;
T_5 V_160 ;
T_1 V_161 ;
ASSERT ( V_2 != NULL ) ;
if ( F_19 ( V_2 , V_162 ) == 0 ||
V_2 -> V_51 . V_163 == 0 )
return 0 ;
V_159 = F_116 ( & V_2 -> V_51 . V_164 ) ;
if ( F_117 ( V_159 ) < 0 )
V_159 = F_118 ( 0 , 0 ) ;
V_160 = F_119 ( F_117 ( V_159 ) , V_2 -> V_51 . V_163 ) ;
V_161 = F_120 ( V_160 ,
( V_165 * V_2 -> V_166 ) ) ;
return V_161 ;
}
static void F_121 ( struct V_1 * V_2 , bool V_167 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_168 * V_169 = V_9 -> V_169 ;
F_65 ( V_170 , V_9 ) ;
V_169 -> V_171 . V_172 = F_122 ( V_9 ) ;
V_169 -> V_171 . V_173 = V_167 ;
}
static inline void F_123 ( struct V_1 * V_2 , bool V_167 )
{
if ( V_2 -> V_9 -> V_11 . V_174 )
F_121 ( V_2 , V_167 ) ;
}
static T_1 F_124 ( struct V_1 * V_2 , unsigned int V_175 )
{
T_1 V_4 = 0 ;
if ( V_175 >= V_176 )
return 0 ;
switch ( V_175 ) {
case V_14 :
if ( F_29 ( V_2 ) )
V_4 = F_18 ( V_2 ) ;
else
V_4 = F_18 ( V_2 ) << 24 ;
break;
case V_177 :
F_80 ( L_16 ) ;
break;
case V_178 :
if ( F_47 ( V_2 ) )
return 0 ;
V_4 = F_115 ( V_2 ) ;
break;
case V_103 :
F_86 ( V_2 ) ;
V_4 = F_19 ( V_2 , V_175 ) ;
break;
case V_104 :
F_123 ( V_2 , false ) ;
default:
V_4 = F_19 ( V_2 , V_175 ) ;
break;
}
return V_4 ;
}
static inline struct V_1 * F_125 ( struct V_179 * V_180 )
{
return F_126 ( V_180 , struct V_1 , V_180 ) ;
}
static int F_127 ( struct V_1 * V_2 , T_1 V_175 , int V_181 ,
void * V_89 )
{
unsigned char V_182 = V_175 & 0xf ;
T_1 V_74 ;
static const T_6 V_183 = 0x43ff01ffffffe70cULL ;
if ( ( V_182 + V_181 ) > 4 ) {
F_80 ( L_17 ,
V_175 , V_181 ) ;
return 1 ;
}
if ( V_175 > 0x3f0 || ! ( V_183 & ( 1ULL << ( V_175 >> 4 ) ) ) ) {
F_80 ( L_18 ,
V_175 ) ;
return 1 ;
}
V_74 = F_124 ( V_2 , V_175 & ~ 0xf ) ;
F_128 ( V_175 , V_74 ) ;
switch ( V_181 ) {
case 1 :
case 2 :
case 4 :
memcpy ( V_89 , ( char * ) & V_74 + V_182 , V_181 ) ;
break;
default:
F_105 ( V_145 L_19
L_20 , V_181 ) ;
break;
}
return 0 ;
}
static int F_129 ( struct V_1 * V_2 , T_7 V_184 )
{
return F_17 ( V_2 ) &&
V_184 >= V_2 -> V_185 &&
V_184 < V_2 -> V_185 + V_176 ;
}
static int F_130 ( struct V_8 * V_9 , struct V_179 * V_186 ,
T_7 V_187 , int V_181 , void * V_89 )
{
struct V_1 * V_2 = F_125 ( V_186 ) ;
T_1 V_175 = V_187 - V_2 -> V_185 ;
if ( ! F_129 ( V_2 , V_187 ) )
return - V_188 ;
F_127 ( V_2 , V_175 , V_181 , V_89 ) ;
return 0 ;
}
static void F_131 ( struct V_1 * V_2 )
{
T_1 V_189 , V_190 , V_191 ;
V_191 = F_19 ( V_2 , V_192 ) ;
V_189 = V_191 & 0xf ;
V_190 = ( ( V_189 & 0x3 ) | ( ( V_189 & 0x8 ) >> 1 ) ) + 1 ;
V_2 -> V_166 = 0x1 << ( V_190 & 0x7 ) ;
F_80 ( L_21 ,
V_2 -> V_166 ) ;
}
static void F_132 ( struct V_1 * V_2 )
{
T_1 V_52 = F_19 ( V_2 , V_193 ) &
V_2 -> V_51 . V_194 ;
if ( V_2 -> V_51 . V_52 != V_52 ) {
V_2 -> V_51 . V_52 = V_52 ;
F_133 ( & V_2 -> V_51 . V_164 ) ;
}
}
static void F_134 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_8 * V_195 = & V_9 -> V_196 ;
struct V_197 * V_198 = & V_2 -> V_51 ;
if ( F_135 ( & V_2 -> V_51 . V_199 ) )
return;
F_136 ( & V_2 -> V_51 . V_199 ) ;
F_137 ( V_9 ) ;
if ( F_138 ( V_195 ) )
F_139 ( V_195 ) ;
if ( F_47 ( V_2 ) )
V_198 -> V_200 = V_198 -> V_201 ;
}
static bool F_140 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_1 V_67 = F_19 ( V_2 , V_193 ) ;
if ( F_17 ( V_2 ) ) {
int V_6 = V_67 & V_50 ;
void * V_7 = V_2 -> V_5 + V_12 ;
if ( V_75 -> V_133 )
V_7 = V_2 -> V_5 + V_13 ;
if ( F_2 ( V_6 , V_7 ) )
return true ;
}
return false ;
}
void F_141 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_6 V_202 , V_203 ;
if ( ! F_50 ( V_9 ) )
return;
if ( V_2 -> V_51 . V_200 == 0 )
return;
if ( ! F_140 ( V_9 ) )
return;
V_203 = V_2 -> V_51 . V_200 ;
V_2 -> V_51 . V_200 = 0 ;
V_202 = V_75 -> V_204 ( V_9 , F_142 () ) ;
F_143 ( V_9 -> V_110 , V_202 - V_203 ) ;
if ( V_202 < V_203 )
F_144 ( V_203 - V_202 ) ;
}
static void F_145 ( struct V_1 * V_2 )
{
T_4 V_205 ;
F_146 ( & V_2 -> V_51 . V_199 , 0 ) ;
if ( F_46 ( V_2 ) || F_45 ( V_2 ) ) {
V_205 = V_2 -> V_51 . V_164 . V_206 -> V_207 () ;
V_2 -> V_51 . V_163 = ( T_6 ) F_19 ( V_2 , V_162 )
* V_165 * V_2 -> V_166 ;
if ( ! V_2 -> V_51 . V_163 )
return;
if ( F_46 ( V_2 ) ) {
T_5 V_208 = V_209 * 1000LL ;
if ( V_2 -> V_51 . V_163 < V_208 ) {
F_147 (
L_22
L_23 ,
V_2 -> V_9 -> V_110 ,
V_2 -> V_51 . V_163 , V_208 ) ;
V_2 -> V_51 . V_163 = V_208 ;
}
}
F_148 ( & V_2 -> V_51 . V_164 ,
F_149 ( V_205 , V_2 -> V_51 . V_163 ) ,
V_210 ) ;
F_80 ( L_24 V_211 L_25
V_212 L_26
L_27
L_28 V_212 L_29 , V_213 ,
V_165 , F_117 ( V_205 ) ,
F_19 ( V_2 , V_162 ) ,
V_2 -> V_51 . V_163 ,
F_117 ( F_149 ( V_205 ,
V_2 -> V_51 . V_163 ) ) ) ;
} else if ( F_47 ( V_2 ) ) {
T_6 V_202 , V_201 = V_2 -> V_51 . V_201 ;
T_6 V_160 = 0 ;
T_4 V_214 ;
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned long V_215 = V_9 -> V_11 . V_216 ;
unsigned long V_217 ;
if ( F_63 ( ! V_201 || ! V_215 ) )
return;
F_150 ( V_217 ) ;
V_205 = V_2 -> V_51 . V_164 . V_206 -> V_207 () ;
V_202 = V_75 -> V_204 ( V_9 , F_142 () ) ;
if ( F_69 ( V_201 > V_202 ) ) {
V_160 = ( V_201 - V_202 ) * 1000000ULL ;
F_151 ( V_160 , V_215 ) ;
V_214 = F_149 ( V_205 , V_160 ) ;
V_214 = F_152 ( V_214 , V_218 ) ;
F_148 ( & V_2 -> V_51 . V_164 ,
V_214 , V_210 ) ;
} else
F_134 ( V_2 ) ;
F_153 ( V_217 ) ;
}
}
static void F_154 ( struct V_1 * V_2 , T_1 V_219 )
{
int V_220 = F_48 ( F_19 ( V_2 , V_221 ) ) ;
if ( F_48 ( V_219 ) ) {
if ( ! V_220 ) {
F_80 ( L_30
L_31 , V_2 -> V_9 -> V_110 ) ;
V_2 -> V_9 -> V_25 -> V_11 . V_222 ++ ;
}
} else if ( V_220 )
V_2 -> V_9 -> V_25 -> V_11 . V_222 -- ;
}
static int F_155 ( struct V_1 * V_2 , T_1 V_67 , T_1 V_4 )
{
int V_126 = 0 ;
F_156 ( V_67 , V_4 ) ;
switch ( V_67 ) {
case V_14 :
if ( ! F_29 ( V_2 ) )
F_41 ( V_2 , V_4 >> 24 ) ;
else
V_126 = 1 ;
break;
case V_104 :
F_123 ( V_2 , true ) ;
F_87 ( V_2 , V_4 & 0xff ) ;
break;
case V_223 :
F_109 ( V_2 ) ;
break;
case V_34 :
if ( ! F_29 ( V_2 ) )
F_42 ( V_2 , V_4 & V_224 ) ;
else
V_126 = 1 ;
break;
case V_36 :
if ( ! F_29 ( V_2 ) ) {
F_1 ( V_2 , V_36 , V_4 | 0x0FFFFFFF ) ;
F_23 ( V_2 -> V_9 -> V_25 ) ;
} else
V_126 = 1 ;
break;
case V_43 : {
T_1 V_225 = 0x3ff ;
if ( F_19 ( V_2 , V_66 ) & V_65 )
V_225 |= V_226 ;
F_38 ( V_2 , V_4 & V_225 ) ;
if ( ! ( V_4 & V_42 ) ) {
int V_28 ;
T_1 V_56 ;
for ( V_28 = 0 ; V_28 < V_227 ; V_28 ++ ) {
V_56 = F_19 ( V_2 ,
V_193 + 0x10 * V_28 ) ;
F_1 ( V_2 , V_193 + 0x10 * V_28 ,
V_56 | V_49 ) ;
}
F_132 ( V_2 ) ;
F_146 ( & V_2 -> V_51 . V_199 , 0 ) ;
}
break;
}
case V_152 :
F_1 ( V_2 , V_152 , V_4 & ~ ( 1 << 12 ) ) ;
F_112 ( V_2 ) ;
break;
case V_154 :
if ( ! F_29 ( V_2 ) )
V_4 &= 0xff000000 ;
F_1 ( V_2 , V_154 , V_4 ) ;
break;
case V_221 :
F_154 ( V_2 , V_4 ) ;
case V_228 :
case V_229 :
case V_230 :
case V_231 :
if ( ! F_16 ( V_2 ) )
V_4 |= V_49 ;
V_4 &= V_232 [ ( V_67 - V_193 ) >> 4 ] ;
F_1 ( V_2 , V_67 , V_4 ) ;
break;
case V_193 :
if ( ! F_16 ( V_2 ) )
V_4 |= V_49 ;
V_4 &= ( V_232 [ 0 ] | V_2 -> V_51 . V_194 ) ;
F_1 ( V_2 , V_193 , V_4 ) ;
F_132 ( V_2 ) ;
break;
case V_162 :
if ( F_47 ( V_2 ) )
break;
F_133 ( & V_2 -> V_51 . V_164 ) ;
F_1 ( V_2 , V_162 , V_4 ) ;
F_145 ( V_2 ) ;
break;
case V_192 :
if ( V_4 & 4 )
F_80 ( L_32 , V_4 ) ;
F_1 ( V_2 , V_192 , V_4 ) ;
F_131 ( V_2 ) ;
break;
case V_233 :
if ( F_29 ( V_2 ) && V_4 != 0 ) {
F_80 ( L_33 , V_4 ) ;
V_126 = 1 ;
}
break;
case V_234 :
if ( F_29 ( V_2 ) ) {
F_155 ( V_2 , V_152 , 0x40000 | ( V_4 & 0xff ) ) ;
} else
V_126 = 1 ;
break;
default:
V_126 = 1 ;
break;
}
if ( V_126 )
F_80 ( L_34 , V_67 ) ;
return V_126 ;
}
static int F_157 ( struct V_8 * V_9 , struct V_179 * V_186 ,
T_7 V_187 , int V_181 , const void * V_89 )
{
struct V_1 * V_2 = F_125 ( V_186 ) ;
unsigned int V_175 = V_187 - V_2 -> V_185 ;
T_1 V_4 ;
if ( ! F_129 ( V_2 , V_187 ) )
return - V_188 ;
if ( V_181 != 4 || ( V_175 & 0xf ) ) {
F_80 ( L_35 , V_181 , ( long ) V_187 ) ;
return 0 ;
}
V_4 = * ( T_1 * ) V_89 ;
if ( V_175 != V_223 )
F_80 ( L_36
L_37 , V_213 , V_175 , V_181 , V_4 ) ;
F_155 ( V_2 , V_175 & 0xff0 , V_4 ) ;
return 0 ;
}
void F_158 ( struct V_8 * V_9 )
{
if ( F_50 ( V_9 ) )
F_155 ( V_9 -> V_11 . V_2 , V_223 , 0 ) ;
}
void F_159 ( struct V_8 * V_9 , T_1 V_175 )
{
T_1 V_4 = 0 ;
V_175 &= 0xff0 ;
F_127 ( V_9 -> V_11 . V_2 , V_175 , 4 , & V_4 ) ;
F_155 ( V_9 -> V_11 . V_2 , V_175 , V_4 ) ;
}
void F_160 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! V_9 -> V_11 . V_2 )
return;
F_133 ( & V_2 -> V_51 . V_164 ) ;
if ( ! ( V_9 -> V_11 . V_235 & V_236 ) )
F_39 ( & V_237 ) ;
if ( ! V_2 -> V_44 )
F_39 ( & V_45 ) ;
if ( V_2 -> V_5 )
F_161 ( ( unsigned long ) V_2 -> V_5 ) ;
F_162 ( V_2 ) ;
}
T_6 F_163 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_50 ( V_9 ) || F_45 ( V_2 ) ||
F_46 ( V_2 ) )
return 0 ;
return V_2 -> V_51 . V_201 ;
}
void F_164 ( struct V_8 * V_9 , T_6 V_89 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_50 ( V_9 ) || F_45 ( V_2 ) ||
F_46 ( V_2 ) )
return;
F_133 ( & V_2 -> V_51 . V_164 ) ;
V_2 -> V_51 . V_201 = V_89 ;
F_145 ( V_2 ) ;
}
void F_165 ( struct V_8 * V_9 , unsigned long V_238 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_50 ( V_9 ) )
return;
F_87 ( V_2 , ( ( V_238 & 0x0f ) << 4 )
| ( F_19 ( V_2 , V_104 ) & 4 ) ) ;
}
T_6 F_166 ( struct V_8 * V_9 )
{
T_6 V_98 ;
if ( ! F_50 ( V_9 ) )
return 0 ;
V_98 = ( T_6 ) F_19 ( V_9 -> V_11 . V_2 , V_104 ) ;
return ( V_98 & 0xf0 ) >> 4 ;
}
void F_167 ( struct V_8 * V_9 , T_6 V_239 )
{
T_6 V_240 = V_9 -> V_11 . V_235 ;
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! V_2 ) {
V_239 |= V_241 ;
V_9 -> V_11 . V_235 = V_239 ;
return;
}
V_9 -> V_11 . V_235 = V_239 ;
if ( ( V_240 ^ V_239 ) & V_236 ) {
if ( V_239 & V_236 )
F_39 ( & V_237 ) ;
else
F_40 ( & V_237 . V_46 ) ;
F_23 ( V_9 -> V_25 ) ;
}
if ( ( V_240 ^ V_239 ) & V_242 ) {
if ( V_239 & V_242 ) {
T_1 V_47 = F_18 ( V_2 ) ;
T_1 V_32 = ( ( V_47 >> 4 ) << 16 ) | ( 1 << ( V_47 & 0xf ) ) ;
F_42 ( V_2 , V_32 ) ;
V_75 -> V_243 ( V_9 , true ) ;
} else
V_75 -> V_243 ( V_9 , false ) ;
}
V_2 -> V_185 = V_2 -> V_9 -> V_11 . V_235 &
V_244 ;
if ( ( V_239 & V_236 ) &&
V_2 -> V_185 != V_245 )
F_168 ( L_38 ) ;
F_80 ( L_39 V_212 L_40
L_41 , V_2 -> V_9 -> V_11 . V_235 , V_2 -> V_185 ) ;
}
void F_169 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
int V_28 ;
F_80 ( L_42 , V_213 ) ;
ASSERT ( V_9 ) ;
V_2 = V_9 -> V_11 . V_2 ;
ASSERT ( V_2 != NULL ) ;
F_133 ( & V_2 -> V_51 . V_164 ) ;
F_41 ( V_2 , V_9 -> V_110 ) ;
F_49 ( V_2 -> V_9 ) ;
for ( V_28 = 0 ; V_28 < V_227 ; V_28 ++ )
F_1 ( V_2 , V_193 + 0x10 * V_28 , V_49 ) ;
F_132 ( V_2 ) ;
F_1 ( V_2 , V_221 ,
F_170 ( 0 , V_246 ) ) ;
F_1 ( V_2 , V_36 , 0xffffffffU ) ;
F_38 ( V_2 , 0xff ) ;
F_1 ( V_2 , V_104 , 0 ) ;
F_42 ( V_2 , 0 ) ;
F_1 ( V_2 , V_233 , 0 ) ;
F_1 ( V_2 , V_152 , 0 ) ;
F_1 ( V_2 , V_154 , 0 ) ;
F_1 ( V_2 , V_192 , 0 ) ;
F_1 ( V_2 , V_162 , 0 ) ;
for ( V_28 = 0 ; V_28 < 8 ; V_28 ++ ) {
F_1 ( V_2 , V_13 + 0x10 * V_28 , 0 ) ;
F_1 ( V_2 , V_12 + 0x10 * V_28 , 0 ) ;
F_1 ( V_2 , V_97 + 0x10 * V_28 , 0 ) ;
}
V_2 -> V_73 = F_64 ( V_9 -> V_25 ) ;
V_2 -> V_79 = V_75 -> V_78 ? 1 : 0 ;
V_2 -> V_80 = - 1 ;
F_131 ( V_2 ) ;
F_146 ( & V_2 -> V_51 . V_199 , 0 ) ;
if ( F_171 ( V_9 ) )
F_167 ( V_9 ,
V_9 -> V_11 . V_235 | V_241 ) ;
V_9 -> V_11 . V_88 . V_90 = 0 ;
F_86 ( V_2 ) ;
V_9 -> V_11 . V_131 = 0 ;
V_9 -> V_11 . V_94 = 0 ;
F_80 ( L_43
L_44 V_212 L_45 , V_213 ,
V_9 , F_18 ( V_2 ) ,
V_9 -> V_11 . V_235 , V_2 -> V_185 ) ;
}
static bool F_172 ( struct V_1 * V_2 )
{
return F_46 ( V_2 ) ;
}
int F_173 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( F_50 ( V_9 ) && F_15 ( V_2 ) &&
F_43 ( V_2 , V_193 ) )
return F_135 ( & V_2 -> V_51 . V_199 ) ;
return 0 ;
}
int F_174 ( struct V_1 * V_2 , int V_48 )
{
T_1 V_67 = F_19 ( V_2 , V_48 ) ;
int V_10 , V_17 , V_87 ;
if ( F_17 ( V_2 ) && ! ( V_67 & V_49 ) ) {
V_10 = V_67 & V_50 ;
V_17 = V_67 & V_57 ;
V_87 = V_67 & V_247 ;
return F_73 ( V_2 , V_17 , V_10 , 1 , V_87 ,
NULL ) ;
}
return 0 ;
}
void F_175 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( V_2 )
F_174 ( V_2 , V_221 ) ;
}
static enum V_248 F_176 ( struct V_249 * V_89 )
{
struct V_197 * V_198 = F_126 ( V_89 , struct V_197 , V_164 ) ;
struct V_1 * V_2 = F_126 ( V_198 , struct V_1 , V_51 ) ;
F_134 ( V_2 ) ;
if ( F_172 ( V_2 ) ) {
F_177 ( & V_198 -> V_164 , V_198 -> V_163 ) ;
return V_250 ;
} else
return V_251 ;
}
int F_178 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
ASSERT ( V_9 != NULL ) ;
F_80 ( L_46 , V_9 -> V_110 ) ;
V_2 = F_24 ( sizeof( * V_2 ) , V_29 ) ;
if ( ! V_2 )
goto V_252;
V_9 -> V_11 . V_2 = V_2 ;
V_2 -> V_5 = ( void * ) F_179 ( V_29 ) ;
if ( ! V_2 -> V_5 ) {
F_105 ( V_145 L_47 ,
V_9 -> V_110 ) ;
goto V_253;
}
V_2 -> V_9 = V_9 ;
F_180 ( & V_2 -> V_51 . V_164 , V_254 ,
V_210 ) ;
V_2 -> V_51 . V_164 . V_255 = F_176 ;
V_9 -> V_11 . V_235 = V_236 ;
F_167 ( V_9 ,
V_245 | V_236 ) ;
F_40 ( & V_45 . V_46 ) ;
F_169 ( V_9 ) ;
F_181 ( & V_2 -> V_180 , & V_256 ) ;
return 0 ;
V_253:
F_162 ( V_2 ) ;
V_252:
return - V_257 ;
}
int F_182 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
int V_81 ;
if ( ! F_50 ( V_9 ) || ! F_15 ( V_2 ) )
return - 1 ;
F_86 ( V_2 ) ;
V_81 = F_61 ( V_2 ) ;
if ( ( V_81 == - 1 ) ||
( ( V_81 & 0xF0 ) <= F_19 ( V_2 , V_103 ) ) )
return - 1 ;
return V_81 ;
}
int F_183 ( struct V_8 * V_9 )
{
T_1 V_258 = F_19 ( V_9 -> V_11 . V_2 , V_221 ) ;
int V_124 = 0 ;
if ( ! F_17 ( V_9 -> V_11 . V_2 ) )
V_124 = 1 ;
if ( ( V_258 & V_49 ) == 0 &&
F_184 ( V_258 ) == V_246 )
V_124 = 1 ;
return V_124 ;
}
void F_185 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_50 ( V_9 ) )
return;
if ( F_135 ( & V_2 -> V_51 . V_199 ) > 0 ) {
F_174 ( V_2 , V_193 ) ;
if ( F_47 ( V_2 ) )
V_2 -> V_51 . V_201 = 0 ;
F_146 ( & V_2 -> V_51 . V_199 , 0 ) ;
}
}
int F_186 ( struct V_8 * V_9 )
{
int V_10 = F_182 ( V_9 ) ;
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( V_10 == - 1 )
return - 1 ;
F_66 ( V_10 , V_2 ) ;
F_86 ( V_2 ) ;
F_62 ( V_10 , V_2 ) ;
return V_10 ;
}
void F_187 ( struct V_8 * V_9 ,
struct V_259 * V_260 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
F_167 ( V_9 , V_9 -> V_11 . V_235 ) ;
F_38 ( V_2 , * ( ( T_1 * ) ( V_260 -> V_5 + V_43 ) ) ) ;
memcpy ( V_9 -> V_11 . V_2 -> V_5 , V_260 -> V_5 , sizeof *V_260 ) ;
F_41 ( V_2 , F_18 ( V_2 ) ) ;
F_49 ( V_9 ) ;
F_86 ( V_2 ) ;
F_133 ( & V_2 -> V_51 . V_164 ) ;
F_132 ( V_2 ) ;
F_131 ( V_2 ) ;
F_145 ( V_2 ) ;
V_2 -> V_73 = true ;
V_2 -> V_79 = V_75 -> V_78 ?
1 : F_54 ( V_2 -> V_5 + V_12 ) ;
V_2 -> V_80 = - 1 ;
if ( V_75 -> V_261 )
V_75 -> V_261 ( V_9 ,
F_61 ( V_2 ) ) ;
if ( F_63 ( V_75 -> V_78 ) )
V_75 -> V_78 ( V_9 -> V_25 ,
F_68 ( V_2 ) ) ;
F_65 ( V_77 , V_9 ) ;
F_188 ( V_9 ) ;
}
void F_189 ( struct V_8 * V_9 )
{
struct V_249 * V_164 ;
if ( ! F_50 ( V_9 ) )
return;
V_164 = & V_9 -> V_11 . V_2 -> V_51 . V_164 ;
if ( F_133 ( V_164 ) )
F_190 ( V_164 , V_210 ) ;
}
static void F_191 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
bool V_199 ;
int V_10 ;
F_67 ( ! F_78 ( V_9 ) ) ;
V_199 = F_79 ( V_9 ) ;
F_83 ( V_9 ) ;
if ( V_199 )
return;
V_10 = F_109 ( V_2 ) ;
F_192 ( V_2 , V_10 ) ;
}
void F_193 ( struct V_8 * V_9 )
{
T_1 V_89 ;
if ( F_3 ( V_93 , & V_9 -> V_11 . V_94 ) )
F_191 ( V_9 , V_9 -> V_11 . V_2 ) ;
if ( ! F_3 ( V_262 , & V_9 -> V_11 . V_94 ) )
return;
F_77 ( V_9 -> V_25 , & V_9 -> V_11 . V_2 -> V_263 , & V_89 ,
sizeof( T_1 ) ) ;
F_87 ( V_9 -> V_11 . V_2 , V_89 & 0xff ) ;
}
static void F_194 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
if ( ! F_78 ( V_9 ) ||
V_2 -> V_73 ||
V_2 -> V_80 == - 1 ||
F_107 ( V_9 -> V_25 , V_2 -> V_80 ) ) {
return;
}
F_81 ( V_2 -> V_9 ) ;
}
void F_195 ( struct V_8 * V_9 )
{
T_1 V_89 , V_98 ;
int V_264 , V_265 ;
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
F_194 ( V_9 , V_2 ) ;
if ( ! F_3 ( V_262 , & V_9 -> V_11 . V_94 ) )
return;
V_98 = F_19 ( V_2 , V_104 ) & 0xff ;
V_264 = F_61 ( V_2 ) ;
if ( V_264 < 0 )
V_264 = 0 ;
V_265 = F_68 ( V_2 ) ;
if ( V_265 < 0 )
V_265 = 0 ;
V_89 = ( V_98 & 0xff ) | ( ( V_265 & 0xf0 ) << 8 ) | ( V_264 << 24 ) ;
F_75 ( V_9 -> V_25 , & V_9 -> V_11 . V_2 -> V_263 , & V_89 ,
sizeof( T_1 ) ) ;
}
int F_196 ( struct V_8 * V_9 , T_7 V_266 )
{
if ( V_266 ) {
if ( F_197 ( V_9 -> V_25 ,
& V_9 -> V_11 . V_2 -> V_263 ,
V_266 , sizeof( T_1 ) ) )
return - V_267 ;
F_82 ( V_262 , & V_9 -> V_11 . V_94 ) ;
} else {
F_84 ( V_262 , & V_9 -> V_11 . V_94 ) ;
}
V_9 -> V_11 . V_2 -> V_266 = V_266 ;
return 0 ;
}
int F_198 ( struct V_8 * V_9 , T_1 V_268 , T_6 V_89 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_1 V_67 = ( V_268 - V_269 ) << 4 ;
if ( ! F_199 ( V_9 -> V_25 ) || ! F_29 ( V_2 ) )
return 1 ;
if ( V_67 == V_154 )
return 1 ;
if ( V_67 == V_152 )
F_155 ( V_2 , V_154 , ( T_1 ) ( V_89 >> 32 ) ) ;
return F_155 ( V_2 , V_67 , ( T_1 ) V_89 ) ;
}
int F_200 ( struct V_8 * V_9 , T_1 V_268 , T_6 * V_89 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_1 V_67 = ( V_268 - V_269 ) << 4 , V_270 , V_271 = 0 ;
if ( ! F_199 ( V_9 -> V_25 ) || ! F_29 ( V_2 ) )
return 1 ;
if ( V_67 == V_36 || V_67 == V_154 ) {
F_80 ( L_48 ,
V_67 ) ;
return 1 ;
}
if ( F_127 ( V_2 , V_67 , 4 , & V_270 ) )
return 1 ;
if ( V_67 == V_152 )
F_127 ( V_2 , V_154 , 4 , & V_271 ) ;
* V_89 = ( ( ( T_6 ) V_271 ) << 32 ) | V_270 ;
return 0 ;
}
int F_201 ( struct V_8 * V_9 , T_1 V_67 , T_6 V_89 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_50 ( V_9 ) )
return 1 ;
if ( V_67 == V_152 )
F_155 ( V_2 , V_154 , ( T_1 ) ( V_89 >> 32 ) ) ;
return F_155 ( V_2 , V_67 , ( T_1 ) V_89 ) ;
}
int F_202 ( struct V_8 * V_9 , T_1 V_67 , T_6 * V_89 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_1 V_270 , V_271 = 0 ;
if ( ! F_50 ( V_9 ) )
return 1 ;
if ( F_127 ( V_2 , V_67 , 4 , & V_270 ) )
return 1 ;
if ( V_67 == V_152 )
F_127 ( V_2 , V_154 , 4 , & V_271 ) ;
* V_89 = ( ( ( T_6 ) V_271 ) << 32 ) | V_270 ;
return 0 ;
}
int F_203 ( struct V_8 * V_9 , T_6 V_89 )
{
T_6 V_184 = V_89 & ~ V_91 ;
if ( ! F_204 ( V_184 , 4 ) )
return 1 ;
V_9 -> V_11 . V_88 . V_90 = V_89 ;
if ( ! F_78 ( V_9 ) )
return 0 ;
return F_197 ( V_9 -> V_25 , & V_9 -> V_11 . V_88 . V_89 ,
V_184 , sizeof( T_3 ) ) ;
}
void F_205 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_3 V_142 ;
unsigned long V_272 ;
if ( ! F_50 ( V_9 ) || ! V_2 -> V_139 )
return;
V_272 = F_57 ( & V_2 -> V_139 , 0 ) ;
if ( F_3 ( V_140 , & V_272 ) ) {
F_169 ( V_9 ) ;
F_206 ( V_9 ) ;
if ( F_171 ( V_2 -> V_9 ) )
V_9 -> V_11 . V_273 = V_274 ;
else
V_9 -> V_11 . V_273 = V_275 ;
}
if ( F_3 ( V_143 , & V_272 ) &&
V_9 -> V_11 . V_273 == V_275 ) {
F_207 () ;
V_142 = V_2 -> V_142 ;
F_80 ( L_49 ,
V_9 -> V_110 , V_142 ) ;
F_208 ( V_9 , V_142 ) ;
V_9 -> V_11 . V_273 = V_274 ;
}
}
void F_209 ( void )
{
F_210 ( & V_237 , V_276 ) ;
F_210 ( & V_45 , V_276 ) ;
}
