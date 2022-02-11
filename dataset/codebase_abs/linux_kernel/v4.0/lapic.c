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
V_17 -> V_27 = V_28 ;
F_23 (i, vcpu, kvm) {
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_24 ( V_9 ) )
continue;
if ( F_25 ( V_2 ) ) {
V_17 -> V_23 = 32 ;
V_17 -> V_24 = 16 ;
V_17 -> V_25 = V_17 -> V_26 = 0xffff ;
V_17 -> V_27 = V_29 ;
} else if ( F_19 ( V_2 , V_30 ) ) {
if ( F_19 ( V_2 , V_31 ) ==
V_32 ) {
V_17 -> V_24 = 4 ;
V_17 -> V_25 = 0xf ;
V_17 -> V_26 = 0xf ;
} else {
V_17 -> V_24 = 8 ;
V_17 -> V_25 = 0 ;
V_17 -> V_26 = 0xff ;
}
}
if ( F_16 ( V_2 ) )
break;
}
F_23 (i, vcpu, kvm) {
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_2 V_33 , V_34 ;
T_1 V_35 , V_36 ;
if ( ! F_24 ( V_9 ) )
continue;
V_36 = F_18 ( V_2 ) ;
V_35 = F_19 ( V_2 , V_30 ) ;
V_33 = F_26 ( V_17 , V_35 ) ;
V_34 = F_27 ( V_17 , V_35 ) ;
if ( V_36 < F_28 ( V_17 -> V_37 ) )
V_17 -> V_37 [ V_36 ] = V_2 ;
if ( V_34 && V_33 < F_28 ( V_17 -> V_38 ) )
V_17 -> V_38 [ V_33 ] [ F_29 ( V_34 ) - 1 ] = V_2 ;
}
V_22:
V_18 = F_30 ( V_15 -> V_11 . V_39 ,
F_31 ( & V_15 -> V_11 . V_21 ) ) ;
F_32 ( V_15 -> V_11 . V_39 , V_17 ) ;
F_33 ( & V_15 -> V_11 . V_21 ) ;
if ( V_18 )
F_34 ( V_18 , V_40 ) ;
F_35 ( V_15 ) ;
}
static inline void F_36 ( struct V_1 * V_2 , T_1 V_4 )
{
bool V_41 = V_4 & V_42 ;
F_1 ( V_2 , V_43 , V_4 ) ;
if ( V_41 != V_2 -> V_44 ) {
V_2 -> V_44 = V_41 ;
if ( V_41 ) {
F_37 ( & V_45 ) ;
F_20 ( V_2 -> V_9 -> V_15 ) ;
} else
F_38 ( & V_45 . V_46 ) ;
}
}
static inline void F_39 ( struct V_1 * V_2 , T_3 V_47 )
{
F_1 ( V_2 , V_14 , V_47 << 24 ) ;
F_20 ( V_2 -> V_9 -> V_15 ) ;
}
static inline void F_40 ( struct V_1 * V_2 , T_1 V_47 )
{
F_1 ( V_2 , V_30 , V_47 ) ;
F_20 ( V_2 -> V_9 -> V_15 ) ;
}
static inline int F_41 ( struct V_1 * V_2 , int V_48 )
{
return ! ( F_19 ( V_2 , V_48 ) & V_49 ) ;
}
static inline int F_42 ( struct V_1 * V_2 , int V_48 )
{
return F_19 ( V_2 , V_48 ) & V_50 ;
}
static inline int F_43 ( struct V_1 * V_2 )
{
return V_2 -> V_51 . V_52 == V_53 ;
}
static inline int F_44 ( struct V_1 * V_2 )
{
return V_2 -> V_51 . V_52 == V_54 ;
}
static inline int F_45 ( struct V_1 * V_2 )
{
return V_2 -> V_51 . V_52 == V_55 ;
}
static inline int F_46 ( T_1 V_56 )
{
return ( V_56 & ( V_57 | V_49 ) ) == V_58 ;
}
void F_47 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
struct V_59 * V_60 ;
T_1 V_61 = V_62 ;
if ( ! F_48 ( V_9 ) )
return;
V_60 = F_49 ( V_2 -> V_9 , 0x1 , 0 ) ;
if ( V_60 && ( V_60 -> V_63 & ( 1 << ( V_64 & 31 ) ) ) )
V_61 |= V_65 ;
F_1 ( V_2 , V_66 , V_61 ) ;
}
static int F_50 ( void * V_7 )
{
int V_6 ;
T_1 * V_67 ;
for ( V_6 = V_68 - V_69 ;
V_6 >= 0 ; V_6 -= V_69 ) {
V_67 = V_7 + F_5 ( V_6 ) ;
if ( * V_67 )
return F_51 ( * V_67 ) - 1 + V_6 ;
}
return - 1 ;
}
static T_3 F_52 ( void * V_7 )
{
int V_6 ;
T_1 * V_67 ;
T_3 V_70 = 0 ;
for ( V_6 = 0 ; V_6 < V_68 ; V_6 += V_69 ) {
V_67 = V_7 + F_5 ( V_6 ) ;
V_70 += F_53 ( * V_67 ) ;
}
return V_70 ;
}
void F_54 ( T_1 * V_71 , void * V_5 )
{
T_1 V_19 , V_72 ;
for ( V_19 = 0 ; V_19 <= 7 ; V_19 ++ ) {
V_72 = F_55 ( & V_71 [ V_19 ] , 0 ) ;
if ( V_72 )
* ( ( T_1 * ) ( V_5 + V_13 + V_19 * 0x10 ) ) |= V_72 ;
}
}
void F_56 ( struct V_8 * V_9 , T_1 * V_71 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
F_54 ( V_71 , V_2 -> V_5 ) ;
}
static inline void F_57 ( int V_6 , struct V_1 * V_2 )
{
F_7 ( V_6 , V_2 -> V_5 + V_13 ) ;
V_2 -> V_73 = true ;
}
static inline int F_58 ( struct V_1 * V_2 )
{
return F_50 ( V_2 -> V_5 + V_13 ) ;
}
static inline int F_59 ( struct V_1 * V_2 )
{
int V_74 ;
if ( ! V_2 -> V_73 )
return - 1 ;
V_75 -> V_76 ( V_2 -> V_9 ) ;
V_74 = F_58 ( V_2 ) ;
ASSERT ( V_74 == - 1 || V_74 >= 16 ) ;
return V_74 ;
}
static inline void F_60 ( int V_6 , struct V_1 * V_2 )
{
struct V_8 * V_9 ;
V_9 = V_2 -> V_9 ;
if ( F_61 ( F_62 ( V_9 -> V_15 ) ) ) {
F_9 ( V_6 , V_2 -> V_5 + V_13 ) ;
F_63 ( V_77 , V_9 ) ;
} else {
V_2 -> V_73 = false ;
F_9 ( V_6 , V_2 -> V_5 + V_13 ) ;
if ( F_58 ( V_2 ) != - 1 )
V_2 -> V_73 = true ;
}
}
static inline void F_64 ( int V_6 , struct V_1 * V_2 )
{
struct V_8 * V_9 ;
if ( F_11 ( V_6 , V_2 -> V_5 + V_12 ) )
return;
V_9 = V_2 -> V_9 ;
if ( F_61 ( V_75 -> V_78 ) )
V_75 -> V_78 ( V_9 -> V_15 , V_6 ) ;
else {
++ V_2 -> V_79 ;
F_65 ( V_2 -> V_79 > V_68 ) ;
V_2 -> V_80 = V_6 ;
}
}
static inline int F_66 ( struct V_1 * V_2 )
{
int V_74 ;
if ( ! V_2 -> V_79 )
return - 1 ;
if ( F_67 ( V_2 -> V_80 != - 1 ) )
return V_2 -> V_80 ;
V_74 = F_50 ( V_2 -> V_5 + V_12 ) ;
ASSERT ( V_74 == - 1 || V_74 >= 16 ) ;
return V_74 ;
}
static inline void F_68 ( int V_6 , struct V_1 * V_2 )
{
struct V_8 * V_9 ;
if ( ! F_13 ( V_6 , V_2 -> V_5 + V_12 ) )
return;
V_9 = V_2 -> V_9 ;
if ( F_61 ( V_75 -> V_78 ) )
V_75 -> V_78 ( V_9 -> V_15 ,
F_66 ( V_2 ) ) ;
else {
-- V_2 -> V_79 ;
F_65 ( V_2 -> V_79 < 0 ) ;
V_2 -> V_80 = - 1 ;
}
}
int F_69 ( struct V_8 * V_9 )
{
int V_81 ;
if ( ! F_48 ( V_9 ) )
return 0 ;
V_81 = F_59 ( V_9 -> V_11 . V_2 ) ;
return V_81 ;
}
int F_70 ( struct V_8 * V_9 , struct V_82 * V_83 ,
unsigned long * V_84 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
return F_71 ( V_2 , V_83 -> V_85 , V_83 -> V_10 ,
V_83 -> V_86 , V_83 -> V_87 , V_84 ) ;
}
static int F_72 ( struct V_8 * V_9 , T_3 V_4 )
{
return F_73 ( V_9 -> V_15 , & V_9 -> V_11 . V_88 . V_89 , & V_4 ,
sizeof( V_4 ) ) ;
}
static int F_74 ( struct V_8 * V_9 , T_3 * V_4 )
{
return F_75 ( V_9 -> V_15 , & V_9 -> V_11 . V_88 . V_89 , V_4 ,
sizeof( * V_4 ) ) ;
}
static inline bool F_76 ( struct V_8 * V_9 )
{
return V_9 -> V_11 . V_88 . V_90 & V_91 ;
}
static bool F_77 ( struct V_8 * V_9 )
{
T_3 V_4 ;
if ( F_74 ( V_9 , & V_4 ) < 0 )
F_78 ( L_1 ,
( unsigned long long ) V_9 -> V_11 . V_88 . V_90 ) ;
return V_4 & 0x1 ;
}
static void F_79 ( struct V_8 * V_9 )
{
if ( F_72 ( V_9 , V_92 ) < 0 ) {
F_78 ( L_2 ,
( unsigned long long ) V_9 -> V_11 . V_88 . V_90 ) ;
return;
}
F_80 ( V_93 , & V_9 -> V_11 . V_94 ) ;
}
static void F_81 ( struct V_8 * V_9 )
{
if ( F_72 ( V_9 , V_95 ) < 0 ) {
F_78 ( L_3 ,
( unsigned long long ) V_9 -> V_11 . V_88 . V_90 ) ;
return;
}
F_82 ( V_93 , & V_9 -> V_11 . V_94 ) ;
}
void F_83 ( struct V_8 * V_9 , T_1 * V_96 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < 8 ; V_19 ++ )
F_1 ( V_2 , V_97 + 0x10 * V_19 , V_96 [ V_19 ] ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
T_1 V_98 , V_99 , V_100 , V_101 ;
int V_102 ;
V_101 = F_19 ( V_2 , V_103 ) ;
V_98 = F_19 ( V_2 , V_104 ) ;
V_102 = F_66 ( V_2 ) ;
V_99 = ( V_102 != - 1 ) ? V_102 : 0 ;
if ( ( V_98 & 0xf0 ) >= ( V_99 & 0xf0 ) )
V_100 = V_98 & 0xff ;
else
V_100 = V_99 & 0xf0 ;
F_78 ( L_4 ,
V_2 , V_100 , V_102 , V_99 ) ;
if ( V_101 != V_100 ) {
F_1 ( V_2 , V_103 , V_100 ) ;
if ( V_100 < V_101 )
F_63 ( V_77 , V_2 -> V_9 ) ;
}
}
static void F_85 ( struct V_1 * V_2 , T_1 V_98 )
{
F_1 ( V_2 , V_104 , V_98 ) ;
F_84 ( V_2 ) ;
}
static bool F_86 ( struct V_1 * V_2 , T_1 V_105 )
{
return V_105 == ( F_25 ( V_2 ) ?
V_29 : V_28 ) ;
}
static bool F_87 ( struct V_1 * V_2 , T_1 V_105 )
{
return F_18 ( V_2 ) == V_105 || F_86 ( V_2 , V_105 ) ;
}
static bool F_88 ( struct V_1 * V_2 , T_1 V_106 )
{
T_1 V_107 ;
if ( F_86 ( V_2 , V_106 ) )
return true ;
V_107 = F_19 ( V_2 , V_30 ) ;
if ( F_25 ( V_2 ) )
return ( ( V_107 >> 16 ) == ( V_106 >> 16 ) )
&& ( V_107 & V_106 & 0xffff ) != 0 ;
V_107 = F_89 ( V_107 ) ;
switch ( F_19 ( V_2 , V_31 ) ) {
case V_108 :
return ( V_107 & V_106 ) != 0 ;
case V_32 :
return ( ( V_107 >> 4 ) == ( V_106 >> 4 ) )
&& ( V_107 & V_106 & 0xf ) != 0 ;
default:
F_78 ( L_5 ,
V_2 -> V_9 -> V_109 , F_19 ( V_2 , V_31 ) ) ;
return false ;
}
}
bool F_90 ( struct V_8 * V_9 , struct V_1 * V_110 ,
int V_111 , unsigned int V_105 , int V_112 )
{
struct V_1 * V_113 = V_9 -> V_11 . V_2 ;
F_78 ( L_6
L_7 ,
V_113 , V_110 , V_105 , V_112 , V_111 ) ;
ASSERT ( V_113 ) ;
switch ( V_111 ) {
case V_114 :
if ( V_112 == V_115 )
return F_87 ( V_113 , V_105 ) ;
else
return F_88 ( V_113 , V_105 ) ;
case V_116 :
return V_113 == V_110 ;
case V_117 :
return true ;
case V_118 :
return V_113 != V_110 ;
default:
F_78 ( L_8 ,
V_111 ) ;
return false ;
}
}
bool F_91 ( struct V_15 * V_15 , struct V_1 * V_119 ,
struct V_82 * V_83 , int * V_120 , unsigned long * V_84 )
{
struct V_16 * V_121 ;
unsigned long V_7 = 1 ;
struct V_1 * * V_122 ;
int V_19 ;
bool V_123 = false ;
* V_120 = - 1 ;
if ( V_83 -> V_124 == V_116 ) {
* V_120 = F_70 ( V_119 -> V_9 , V_83 , V_84 ) ;
return true ;
}
if ( V_83 -> V_124 )
return false ;
F_92 () ;
V_121 = F_93 ( V_15 -> V_11 . V_39 ) ;
if ( ! V_121 )
goto V_22;
if ( V_83 -> V_125 == V_121 -> V_27 )
goto V_22;
V_123 = true ;
if ( V_83 -> V_112 == V_115 ) {
if ( V_83 -> V_125 >= F_28 ( V_121 -> V_37 ) )
goto V_22;
V_122 = & V_121 -> V_37 [ V_83 -> V_125 ] ;
} else {
T_1 V_106 = V_83 -> V_125 << ( 32 - V_121 -> V_23 ) ;
T_2 V_33 = F_26 ( V_121 , V_106 ) ;
if ( V_33 >= F_28 ( V_121 -> V_38 ) )
goto V_22;
V_122 = V_121 -> V_38 [ V_33 ] ;
V_7 = F_27 ( V_121 , V_106 ) ;
if ( V_83 -> V_85 == V_126 ) {
int V_127 = - 1 ;
F_94 (i, &bitmap, 16 ) {
if ( ! V_122 [ V_19 ] )
continue;
if ( V_127 < 0 )
V_127 = V_19 ;
else if ( F_95 ( V_122 [ V_19 ] -> V_9 , V_122 [ V_127 ] -> V_9 ) < 0 )
V_127 = V_19 ;
}
V_7 = ( V_127 >= 0 ) ? 1 << V_127 : 0 ;
}
}
F_94 (i, &bitmap, 16 ) {
if ( ! V_122 [ V_19 ] )
continue;
if ( * V_120 < 0 )
* V_120 = 0 ;
* V_120 += F_70 ( V_122 [ V_19 ] -> V_9 , V_83 , V_84 ) ;
}
V_22:
F_96 () ;
return V_123 ;
}
static int F_71 ( struct V_1 * V_2 , int V_85 ,
int V_10 , int V_86 , int V_87 ,
unsigned long * V_84 )
{
int V_74 = 0 ;
struct V_8 * V_9 = V_2 -> V_9 ;
F_97 ( V_9 -> V_109 , V_85 ,
V_87 , V_10 ) ;
switch ( V_85 ) {
case V_126 :
V_9 -> V_11 . V_128 ++ ;
case V_129 :
if ( F_61 ( ! F_15 ( V_2 ) ) )
break;
V_74 = 1 ;
if ( V_84 )
F_80 ( V_9 -> V_109 , V_84 ) ;
if ( V_75 -> V_130 )
V_75 -> V_130 ( V_9 , V_10 ) ;
else {
F_57 ( V_10 , V_2 ) ;
F_63 ( V_77 , V_9 ) ;
F_98 ( V_9 ) ;
}
break;
case V_131 :
V_74 = 1 ;
V_9 -> V_11 . V_132 . V_133 = 1 ;
F_63 ( V_77 , V_9 ) ;
F_98 ( V_9 ) ;
break;
case V_134 :
F_78 ( L_9 ) ;
break;
case V_58 :
V_74 = 1 ;
F_99 ( V_9 ) ;
F_98 ( V_9 ) ;
break;
case V_135 :
if ( ! V_87 || V_86 ) {
V_74 = 1 ;
V_2 -> V_136 = ( 1UL << V_137 ) ;
F_100 () ;
F_63 ( V_77 , V_9 ) ;
F_98 ( V_9 ) ;
} else {
F_78 ( L_10 ,
V_9 -> V_109 ) ;
}
break;
case V_138 :
F_78 ( L_11 ,
V_9 -> V_109 , V_10 ) ;
V_74 = 1 ;
V_2 -> V_139 = V_10 ;
F_100 () ;
F_8 ( V_140 , & V_2 -> V_136 ) ;
F_63 ( V_77 , V_9 ) ;
F_98 ( V_9 ) ;
break;
case V_141 :
break;
default:
F_101 ( V_142 L_12 ,
V_85 ) ;
break;
}
return V_74 ;
}
int F_95 ( struct V_8 * V_143 , struct V_8 * V_144 )
{
return V_143 -> V_11 . V_128 - V_144 -> V_11 . V_128 ;
}
static void F_102 ( struct V_1 * V_2 , int V_10 )
{
if ( F_103 ( V_2 -> V_9 -> V_15 , V_10 ) ) {
int V_145 ;
if ( F_2 ( V_10 , V_2 -> V_5 + V_97 ) )
V_145 = V_146 ;
else
V_145 = V_147 ;
F_104 ( V_2 -> V_9 , V_10 , V_145 ) ;
}
}
static int F_105 ( struct V_1 * V_2 )
{
int V_10 = F_66 ( V_2 ) ;
F_106 ( V_2 , V_10 ) ;
if ( V_10 == - 1 )
return V_10 ;
F_68 ( V_10 , V_2 ) ;
F_84 ( V_2 ) ;
F_102 ( V_2 , V_10 ) ;
F_63 ( V_77 , V_2 -> V_9 ) ;
return V_10 ;
}
void F_107 ( struct V_8 * V_9 , int V_10 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
F_106 ( V_2 , V_10 ) ;
F_102 ( V_2 , V_10 ) ;
F_63 ( V_77 , V_2 -> V_9 ) ;
}
static void F_108 ( struct V_1 * V_2 )
{
T_1 V_148 = F_19 ( V_2 , V_149 ) ;
T_1 V_150 = F_19 ( V_2 , V_151 ) ;
struct V_82 V_83 ;
V_83 . V_10 = V_148 & V_50 ;
V_83 . V_85 = V_148 & V_57 ;
V_83 . V_112 = V_148 & V_152 ;
V_83 . V_86 = V_148 & V_153 ;
V_83 . V_87 = V_148 & V_154 ;
V_83 . V_124 = V_148 & V_155 ;
if ( F_25 ( V_2 ) )
V_83 . V_125 = V_150 ;
else
V_83 . V_125 = F_109 ( V_150 ) ;
F_110 ( V_148 , V_83 . V_125 ) ;
F_78 ( L_13
L_14
L_15 ,
V_150 , V_148 , V_83 . V_124 , V_83 . V_125 ,
V_83 . V_87 , V_83 . V_86 , V_83 . V_112 , V_83 . V_85 ,
V_83 . V_10 ) ;
F_111 ( V_2 -> V_9 -> V_15 , V_2 , & V_83 , NULL ) ;
}
static T_1 F_112 ( struct V_1 * V_2 )
{
T_4 V_156 ;
T_5 V_157 ;
T_1 V_158 ;
ASSERT ( V_2 != NULL ) ;
if ( F_19 ( V_2 , V_159 ) == 0 ||
V_2 -> V_51 . V_160 == 0 )
return 0 ;
V_156 = F_113 ( & V_2 -> V_51 . V_161 ) ;
if ( F_114 ( V_156 ) < 0 )
V_156 = F_115 ( 0 , 0 ) ;
V_157 = F_116 ( F_114 ( V_156 ) , V_2 -> V_51 . V_160 ) ;
V_158 = F_117 ( V_157 ,
( V_162 * V_2 -> V_163 ) ) ;
return V_158 ;
}
static void F_118 ( struct V_1 * V_2 , bool V_164 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_165 * V_166 = V_9 -> V_166 ;
F_63 ( V_167 , V_9 ) ;
V_166 -> V_168 . V_169 = F_119 ( V_9 ) ;
V_166 -> V_168 . V_170 = V_164 ;
}
static inline void F_120 ( struct V_1 * V_2 , bool V_164 )
{
if ( V_2 -> V_9 -> V_11 . V_171 )
F_118 ( V_2 , V_164 ) ;
}
static T_1 F_121 ( struct V_1 * V_2 , unsigned int V_172 )
{
T_1 V_4 = 0 ;
if ( V_172 >= V_173 )
return 0 ;
switch ( V_172 ) {
case V_14 :
if ( F_25 ( V_2 ) )
V_4 = F_18 ( V_2 ) ;
else
V_4 = F_18 ( V_2 ) << 24 ;
break;
case V_174 :
F_78 ( L_16 ) ;
break;
case V_175 :
if ( F_45 ( V_2 ) )
return 0 ;
V_4 = F_112 ( V_2 ) ;
break;
case V_103 :
F_84 ( V_2 ) ;
V_4 = F_19 ( V_2 , V_172 ) ;
break;
case V_104 :
F_120 ( V_2 , false ) ;
default:
V_4 = F_19 ( V_2 , V_172 ) ;
break;
}
return V_4 ;
}
static inline struct V_1 * F_122 ( struct V_176 * V_177 )
{
return F_123 ( V_177 , struct V_1 , V_177 ) ;
}
static int F_124 ( struct V_1 * V_2 , T_1 V_172 , int V_178 ,
void * V_89 )
{
unsigned char V_179 = V_172 & 0xf ;
T_1 V_74 ;
static const T_6 V_180 = 0x43ff01ffffffe70cULL ;
if ( ( V_179 + V_178 ) > 4 ) {
F_78 ( L_17 ,
V_172 , V_178 ) ;
return 1 ;
}
if ( V_172 > 0x3f0 || ! ( V_180 & ( 1ULL << ( V_172 >> 4 ) ) ) ) {
F_78 ( L_18 ,
V_172 ) ;
return 1 ;
}
V_74 = F_121 ( V_2 , V_172 & ~ 0xf ) ;
F_125 ( V_172 , V_74 ) ;
switch ( V_178 ) {
case 1 :
case 2 :
case 4 :
memcpy ( V_89 , ( char * ) & V_74 + V_179 , V_178 ) ;
break;
default:
F_101 ( V_142 L_19
L_20 , V_178 ) ;
break;
}
return 0 ;
}
static int F_126 ( struct V_1 * V_2 , T_7 V_181 )
{
return F_17 ( V_2 ) &&
V_181 >= V_2 -> V_182 &&
V_181 < V_2 -> V_182 + V_173 ;
}
static int F_127 ( struct V_176 * V_183 ,
T_7 V_184 , int V_178 , void * V_89 )
{
struct V_1 * V_2 = F_122 ( V_183 ) ;
T_1 V_172 = V_184 - V_2 -> V_182 ;
if ( ! F_126 ( V_2 , V_184 ) )
return - V_185 ;
F_124 ( V_2 , V_172 , V_178 , V_89 ) ;
return 0 ;
}
static void F_128 ( struct V_1 * V_2 )
{
T_1 V_186 , V_187 , V_188 ;
V_188 = F_19 ( V_2 , V_189 ) ;
V_186 = V_188 & 0xf ;
V_187 = ( ( V_186 & 0x3 ) | ( ( V_186 & 0x8 ) >> 1 ) ) + 1 ;
V_2 -> V_163 = 0x1 << ( V_187 & 0x7 ) ;
F_78 ( L_21 ,
V_2 -> V_163 ) ;
}
static void F_129 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_8 * V_190 = & V_9 -> V_191 ;
struct V_192 * V_193 = & V_2 -> V_51 ;
if ( F_130 ( & V_2 -> V_51 . V_194 ) )
return;
F_131 ( & V_2 -> V_51 . V_194 ) ;
F_132 ( V_9 ) ;
if ( F_133 ( V_190 ) )
F_134 ( V_190 ) ;
if ( F_45 ( V_2 ) )
V_193 -> V_195 = V_193 -> V_196 ;
}
static bool F_135 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_1 V_67 = F_19 ( V_2 , V_197 ) ;
if ( F_17 ( V_2 ) ) {
int V_6 = V_67 & V_50 ;
void * V_7 = V_2 -> V_5 + V_12 ;
if ( V_75 -> V_130 )
V_7 = V_2 -> V_5 + V_13 ;
if ( F_2 ( V_6 , V_7 ) )
return true ;
}
return false ;
}
void F_136 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_6 V_198 , V_199 ;
if ( ! F_48 ( V_9 ) )
return;
if ( V_2 -> V_51 . V_195 == 0 )
return;
if ( ! F_135 ( V_9 ) )
return;
V_199 = V_2 -> V_51 . V_195 ;
V_2 -> V_51 . V_195 = 0 ;
V_198 = V_75 -> V_200 ( V_9 , F_137 () ) ;
F_138 ( V_9 -> V_109 , V_198 - V_199 ) ;
if ( V_198 < V_199 )
F_139 ( V_199 - V_198 ) ;
}
static void F_140 ( struct V_1 * V_2 )
{
T_4 V_201 ;
F_141 ( & V_2 -> V_51 . V_194 , 0 ) ;
if ( F_44 ( V_2 ) || F_43 ( V_2 ) ) {
V_201 = V_2 -> V_51 . V_161 . V_202 -> V_203 () ;
V_2 -> V_51 . V_160 = ( T_6 ) F_19 ( V_2 , V_159 )
* V_162 * V_2 -> V_163 ;
if ( ! V_2 -> V_51 . V_160 )
return;
if ( F_44 ( V_2 ) ) {
T_5 V_204 = V_205 * 1000LL ;
if ( V_2 -> V_51 . V_160 < V_204 ) {
F_142 (
L_22
L_23 ,
V_2 -> V_9 -> V_109 ,
V_2 -> V_51 . V_160 , V_204 ) ;
V_2 -> V_51 . V_160 = V_204 ;
}
}
F_143 ( & V_2 -> V_51 . V_161 ,
F_144 ( V_201 , V_2 -> V_51 . V_160 ) ,
V_206 ) ;
F_78 ( L_24 V_207 L_25
V_208 L_26
L_27
L_28 V_208 L_29 , V_209 ,
V_162 , F_114 ( V_201 ) ,
F_19 ( V_2 , V_159 ) ,
V_2 -> V_51 . V_160 ,
F_114 ( F_144 ( V_201 ,
V_2 -> V_51 . V_160 ) ) ) ;
} else if ( F_45 ( V_2 ) ) {
T_6 V_198 , V_196 = V_2 -> V_51 . V_196 ;
T_6 V_157 = 0 ;
T_4 V_210 ;
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned long V_211 = V_9 -> V_11 . V_212 ;
unsigned long V_213 ;
if ( F_61 ( ! V_196 || ! V_211 ) )
return;
F_145 ( V_213 ) ;
V_201 = V_2 -> V_51 . V_161 . V_202 -> V_203 () ;
V_198 = V_75 -> V_200 ( V_9 , F_137 () ) ;
if ( F_67 ( V_196 > V_198 ) ) {
V_157 = ( V_196 - V_198 ) * 1000000ULL ;
F_146 ( V_157 , V_211 ) ;
V_210 = F_144 ( V_201 , V_157 ) ;
V_210 = F_147 ( V_210 , V_214 ) ;
F_143 ( & V_2 -> V_51 . V_161 ,
V_210 , V_206 ) ;
} else
F_129 ( V_2 ) ;
F_148 ( V_213 ) ;
}
}
static void F_149 ( struct V_1 * V_2 , T_1 V_215 )
{
int V_216 = F_46 ( F_19 ( V_2 , V_217 ) ) ;
if ( F_46 ( V_215 ) ) {
if ( ! V_216 ) {
F_78 ( L_30
L_31 , V_2 -> V_9 -> V_109 ) ;
V_2 -> V_9 -> V_15 -> V_11 . V_218 ++ ;
}
} else if ( V_216 )
V_2 -> V_9 -> V_15 -> V_11 . V_218 -- ;
}
static int F_150 ( struct V_1 * V_2 , T_1 V_67 , T_1 V_4 )
{
int V_123 = 0 ;
F_151 ( V_67 , V_4 ) ;
switch ( V_67 ) {
case V_14 :
if ( ! F_25 ( V_2 ) )
F_39 ( V_2 , V_4 >> 24 ) ;
else
V_123 = 1 ;
break;
case V_104 :
F_120 ( V_2 , true ) ;
F_85 ( V_2 , V_4 & 0xff ) ;
break;
case V_219 :
F_105 ( V_2 ) ;
break;
case V_30 :
if ( ! F_25 ( V_2 ) )
F_40 ( V_2 , V_4 & V_220 ) ;
else
V_123 = 1 ;
break;
case V_31 :
if ( ! F_25 ( V_2 ) ) {
F_1 ( V_2 , V_31 , V_4 | 0x0FFFFFFF ) ;
F_20 ( V_2 -> V_9 -> V_15 ) ;
} else
V_123 = 1 ;
break;
case V_43 : {
T_1 V_221 = 0x3ff ;
if ( F_19 ( V_2 , V_66 ) & V_65 )
V_221 |= V_222 ;
F_36 ( V_2 , V_4 & V_221 ) ;
if ( ! ( V_4 & V_42 ) ) {
int V_19 ;
T_1 V_56 ;
for ( V_19 = 0 ; V_19 < V_223 ; V_19 ++ ) {
V_56 = F_19 ( V_2 ,
V_197 + 0x10 * V_19 ) ;
F_1 ( V_2 , V_197 + 0x10 * V_19 ,
V_56 | V_49 ) ;
}
F_141 ( & V_2 -> V_51 . V_194 , 0 ) ;
}
break;
}
case V_149 :
F_1 ( V_2 , V_149 , V_4 & ~ ( 1 << 12 ) ) ;
F_108 ( V_2 ) ;
break;
case V_151 :
if ( ! F_25 ( V_2 ) )
V_4 &= 0xff000000 ;
F_1 ( V_2 , V_151 , V_4 ) ;
break;
case V_217 :
F_149 ( V_2 , V_4 ) ;
case V_224 :
case V_225 :
case V_226 :
case V_227 :
if ( ! F_16 ( V_2 ) )
V_4 |= V_49 ;
V_4 &= V_228 [ ( V_67 - V_197 ) >> 4 ] ;
F_1 ( V_2 , V_67 , V_4 ) ;
break;
case V_197 : {
T_1 V_52 = V_4 & V_2 -> V_51 . V_229 ;
if ( V_2 -> V_51 . V_52 != V_52 ) {
V_2 -> V_51 . V_52 = V_52 ;
F_152 ( & V_2 -> V_51 . V_161 ) ;
}
if ( ! F_16 ( V_2 ) )
V_4 |= V_49 ;
V_4 &= ( V_228 [ 0 ] | V_2 -> V_51 . V_229 ) ;
F_1 ( V_2 , V_197 , V_4 ) ;
break;
}
case V_159 :
if ( F_45 ( V_2 ) )
break;
F_152 ( & V_2 -> V_51 . V_161 ) ;
F_1 ( V_2 , V_159 , V_4 ) ;
F_140 ( V_2 ) ;
break;
case V_189 :
if ( V_4 & 4 )
F_78 ( L_32 , V_4 ) ;
F_1 ( V_2 , V_189 , V_4 ) ;
F_128 ( V_2 ) ;
break;
case V_230 :
if ( F_25 ( V_2 ) && V_4 != 0 ) {
F_78 ( L_33 , V_4 ) ;
V_123 = 1 ;
}
break;
case V_231 :
if ( F_25 ( V_2 ) ) {
F_150 ( V_2 , V_149 , 0x40000 | ( V_4 & 0xff ) ) ;
} else
V_123 = 1 ;
break;
default:
V_123 = 1 ;
break;
}
if ( V_123 )
F_78 ( L_34 , V_67 ) ;
return V_123 ;
}
static int F_153 ( struct V_176 * V_183 ,
T_7 V_184 , int V_178 , const void * V_89 )
{
struct V_1 * V_2 = F_122 ( V_183 ) ;
unsigned int V_172 = V_184 - V_2 -> V_182 ;
T_1 V_4 ;
if ( ! F_126 ( V_2 , V_184 ) )
return - V_185 ;
if ( V_178 != 4 || ( V_172 & 0xf ) ) {
F_78 ( L_35 , V_178 , ( long ) V_184 ) ;
return 0 ;
}
V_4 = * ( T_1 * ) V_89 ;
if ( V_172 != V_219 )
F_78 ( L_36
L_37 , V_209 , V_172 , V_178 , V_4 ) ;
F_150 ( V_2 , V_172 & 0xff0 , V_4 ) ;
return 0 ;
}
void F_154 ( struct V_8 * V_9 )
{
if ( F_48 ( V_9 ) )
F_150 ( V_9 -> V_11 . V_2 , V_219 , 0 ) ;
}
void F_155 ( struct V_8 * V_9 , T_1 V_172 )
{
T_1 V_4 = 0 ;
V_172 &= 0xff0 ;
F_124 ( V_9 -> V_11 . V_2 , V_172 , 4 , & V_4 ) ;
F_150 ( V_9 -> V_11 . V_2 , V_172 , V_4 ) ;
}
void F_156 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! V_9 -> V_11 . V_2 )
return;
F_152 ( & V_2 -> V_51 . V_161 ) ;
if ( ! ( V_9 -> V_11 . V_232 & V_233 ) )
F_37 ( & V_234 ) ;
if ( ! V_2 -> V_44 )
F_37 ( & V_45 ) ;
if ( V_2 -> V_5 )
F_157 ( ( unsigned long ) V_2 -> V_5 ) ;
F_158 ( V_2 ) ;
}
T_6 F_159 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_48 ( V_9 ) || F_43 ( V_2 ) ||
F_44 ( V_2 ) )
return 0 ;
return V_2 -> V_51 . V_196 ;
}
void F_160 ( struct V_8 * V_9 , T_6 V_89 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_48 ( V_9 ) || F_43 ( V_2 ) ||
F_44 ( V_2 ) )
return;
F_152 ( & V_2 -> V_51 . V_161 ) ;
V_2 -> V_51 . V_196 = V_89 ;
F_140 ( V_2 ) ;
}
void F_161 ( struct V_8 * V_9 , unsigned long V_235 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_48 ( V_9 ) )
return;
F_85 ( V_2 , ( ( V_235 & 0x0f ) << 4 )
| ( F_19 ( V_2 , V_104 ) & 4 ) ) ;
}
T_6 F_162 ( struct V_8 * V_9 )
{
T_6 V_98 ;
if ( ! F_48 ( V_9 ) )
return 0 ;
V_98 = ( T_6 ) F_19 ( V_9 -> V_11 . V_2 , V_104 ) ;
return ( V_98 & 0xf0 ) >> 4 ;
}
void F_163 ( struct V_8 * V_9 , T_6 V_236 )
{
T_6 V_237 = V_9 -> V_11 . V_232 ;
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! V_2 ) {
V_236 |= V_238 ;
V_9 -> V_11 . V_232 = V_236 ;
return;
}
if ( ! F_164 ( V_2 -> V_9 ) )
V_236 &= ~ V_238 ;
V_9 -> V_11 . V_232 = V_236 ;
if ( ( V_237 ^ V_236 ) & V_233 ) {
if ( V_236 & V_233 )
F_37 ( & V_234 ) ;
else
F_38 ( & V_234 . V_46 ) ;
F_20 ( V_9 -> V_15 ) ;
}
if ( ( V_237 ^ V_236 ) & V_239 ) {
if ( V_236 & V_239 ) {
T_1 V_47 = F_18 ( V_2 ) ;
T_1 V_35 = ( ( V_47 >> 4 ) << 16 ) | ( 1 << ( V_47 & 0xf ) ) ;
F_40 ( V_2 , V_35 ) ;
V_75 -> V_240 ( V_9 , true ) ;
} else
V_75 -> V_240 ( V_9 , false ) ;
}
V_2 -> V_182 = V_2 -> V_9 -> V_11 . V_232 &
V_241 ;
if ( ( V_236 & V_233 ) &&
V_2 -> V_182 != V_242 )
F_165 ( L_38 ) ;
F_78 ( L_39 V_208 L_40
L_41 , V_2 -> V_9 -> V_11 . V_232 , V_2 -> V_182 ) ;
}
void F_166 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
int V_19 ;
F_78 ( L_42 , V_209 ) ;
ASSERT ( V_9 ) ;
V_2 = V_9 -> V_11 . V_2 ;
ASSERT ( V_2 != NULL ) ;
F_152 ( & V_2 -> V_51 . V_161 ) ;
F_39 ( V_2 , V_9 -> V_109 ) ;
F_47 ( V_2 -> V_9 ) ;
for ( V_19 = 0 ; V_19 < V_223 ; V_19 ++ )
F_1 ( V_2 , V_197 + 0x10 * V_19 , V_49 ) ;
V_2 -> V_51 . V_52 = 0 ;
F_1 ( V_2 , V_217 ,
F_167 ( 0 , V_243 ) ) ;
F_1 ( V_2 , V_31 , 0xffffffffU ) ;
F_36 ( V_2 , 0xff ) ;
F_1 ( V_2 , V_104 , 0 ) ;
F_40 ( V_2 , 0 ) ;
F_1 ( V_2 , V_230 , 0 ) ;
F_1 ( V_2 , V_149 , 0 ) ;
F_1 ( V_2 , V_151 , 0 ) ;
F_1 ( V_2 , V_189 , 0 ) ;
F_1 ( V_2 , V_159 , 0 ) ;
for ( V_19 = 0 ; V_19 < 8 ; V_19 ++ ) {
F_1 ( V_2 , V_13 + 0x10 * V_19 , 0 ) ;
F_1 ( V_2 , V_12 + 0x10 * V_19 , 0 ) ;
F_1 ( V_2 , V_97 + 0x10 * V_19 , 0 ) ;
}
V_2 -> V_73 = F_62 ( V_9 -> V_15 ) ;
V_2 -> V_79 = V_75 -> V_78 ? 1 : 0 ;
V_2 -> V_80 = - 1 ;
F_128 ( V_2 ) ;
F_141 ( & V_2 -> V_51 . V_194 , 0 ) ;
if ( F_164 ( V_9 ) )
F_163 ( V_9 ,
V_9 -> V_11 . V_232 | V_238 ) ;
V_9 -> V_11 . V_88 . V_90 = 0 ;
F_84 ( V_2 ) ;
V_9 -> V_11 . V_128 = 0 ;
V_9 -> V_11 . V_94 = 0 ;
F_78 ( L_43
L_44 V_208 L_45 , V_209 ,
V_9 , F_18 ( V_2 ) ,
V_9 -> V_11 . V_232 , V_2 -> V_182 ) ;
}
static bool F_168 ( struct V_1 * V_2 )
{
return F_44 ( V_2 ) ;
}
int F_169 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( F_48 ( V_9 ) && F_15 ( V_2 ) &&
F_41 ( V_2 , V_197 ) )
return F_130 ( & V_2 -> V_51 . V_194 ) ;
return 0 ;
}
int F_170 ( struct V_1 * V_2 , int V_48 )
{
T_1 V_67 = F_19 ( V_2 , V_48 ) ;
int V_10 , V_244 , V_87 ;
if ( F_17 ( V_2 ) && ! ( V_67 & V_49 ) ) {
V_10 = V_67 & V_50 ;
V_244 = V_67 & V_57 ;
V_87 = V_67 & V_245 ;
return F_71 ( V_2 , V_244 , V_10 , 1 , V_87 ,
NULL ) ;
}
return 0 ;
}
void F_171 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( V_2 )
F_170 ( V_2 , V_217 ) ;
}
static enum V_246 F_172 ( struct V_247 * V_89 )
{
struct V_192 * V_193 = F_123 ( V_89 , struct V_192 , V_161 ) ;
struct V_1 * V_2 = F_123 ( V_193 , struct V_1 , V_51 ) ;
F_129 ( V_2 ) ;
if ( F_168 ( V_2 ) ) {
F_173 ( & V_193 -> V_161 , V_193 -> V_160 ) ;
return V_248 ;
} else
return V_249 ;
}
int F_174 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
ASSERT ( V_9 != NULL ) ;
F_78 ( L_46 , V_9 -> V_109 ) ;
V_2 = F_21 ( sizeof( * V_2 ) , V_20 ) ;
if ( ! V_2 )
goto V_250;
V_9 -> V_11 . V_2 = V_2 ;
V_2 -> V_5 = ( void * ) F_175 ( V_20 ) ;
if ( ! V_2 -> V_5 ) {
F_101 ( V_142 L_47 ,
V_9 -> V_109 ) ;
goto V_251;
}
V_2 -> V_9 = V_9 ;
F_176 ( & V_2 -> V_51 . V_161 , V_252 ,
V_206 ) ;
V_2 -> V_51 . V_161 . V_253 = F_172 ;
V_9 -> V_11 . V_232 = V_233 ;
F_163 ( V_9 ,
V_242 | V_233 ) ;
F_38 ( & V_45 . V_46 ) ;
F_166 ( V_9 ) ;
F_177 ( & V_2 -> V_177 , & V_254 ) ;
return 0 ;
V_251:
F_158 ( V_2 ) ;
V_250:
return - V_255 ;
}
int F_178 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
int V_81 ;
if ( ! F_48 ( V_9 ) || ! F_15 ( V_2 ) )
return - 1 ;
F_84 ( V_2 ) ;
V_81 = F_59 ( V_2 ) ;
if ( ( V_81 == - 1 ) ||
( ( V_81 & 0xF0 ) <= F_19 ( V_2 , V_103 ) ) )
return - 1 ;
return V_81 ;
}
int F_179 ( struct V_8 * V_9 )
{
T_1 V_256 = F_19 ( V_9 -> V_11 . V_2 , V_217 ) ;
int V_120 = 0 ;
if ( ! F_17 ( V_9 -> V_11 . V_2 ) )
V_120 = 1 ;
if ( ( V_256 & V_49 ) == 0 &&
F_180 ( V_256 ) == V_243 )
V_120 = 1 ;
return V_120 ;
}
void F_181 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_48 ( V_9 ) )
return;
if ( F_130 ( & V_2 -> V_51 . V_194 ) > 0 ) {
F_170 ( V_2 , V_197 ) ;
if ( F_45 ( V_2 ) )
V_2 -> V_51 . V_196 = 0 ;
F_141 ( & V_2 -> V_51 . V_194 , 0 ) ;
}
}
int F_182 ( struct V_8 * V_9 )
{
int V_10 = F_178 ( V_9 ) ;
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( V_10 == - 1 )
return - 1 ;
F_64 ( V_10 , V_2 ) ;
F_84 ( V_2 ) ;
F_60 ( V_10 , V_2 ) ;
return V_10 ;
}
void F_183 ( struct V_8 * V_9 ,
struct V_257 * V_258 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
F_163 ( V_9 , V_9 -> V_11 . V_232 ) ;
F_36 ( V_2 , * ( ( T_1 * ) ( V_258 -> V_5 + V_43 ) ) ) ;
memcpy ( V_9 -> V_11 . V_2 -> V_5 , V_258 -> V_5 , sizeof *V_258 ) ;
F_39 ( V_2 , F_18 ( V_2 ) ) ;
F_47 ( V_9 ) ;
F_84 ( V_2 ) ;
F_152 ( & V_2 -> V_51 . V_161 ) ;
F_128 ( V_2 ) ;
F_140 ( V_2 ) ;
V_2 -> V_73 = true ;
V_2 -> V_79 = V_75 -> V_78 ?
1 : F_52 ( V_2 -> V_5 + V_12 ) ;
V_2 -> V_80 = - 1 ;
if ( V_75 -> V_259 )
V_75 -> V_259 ( V_9 ,
F_59 ( V_2 ) ) ;
if ( F_61 ( V_75 -> V_78 ) )
V_75 -> V_78 ( V_9 -> V_15 ,
F_66 ( V_2 ) ) ;
F_63 ( V_77 , V_9 ) ;
F_184 ( V_9 ) ;
}
void F_185 ( struct V_8 * V_9 )
{
struct V_247 * V_161 ;
if ( ! F_48 ( V_9 ) )
return;
V_161 = & V_9 -> V_11 . V_2 -> V_51 . V_161 ;
if ( F_152 ( V_161 ) )
F_186 ( V_161 , V_206 ) ;
}
static void F_187 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
bool V_194 ;
int V_10 ;
F_65 ( ! F_76 ( V_9 ) ) ;
V_194 = F_77 ( V_9 ) ;
F_81 ( V_9 ) ;
if ( V_194 )
return;
V_10 = F_105 ( V_2 ) ;
F_188 ( V_2 , V_10 ) ;
}
void F_189 ( struct V_8 * V_9 )
{
T_1 V_89 ;
if ( F_3 ( V_93 , & V_9 -> V_11 . V_94 ) )
F_187 ( V_9 , V_9 -> V_11 . V_2 ) ;
if ( ! F_3 ( V_260 , & V_9 -> V_11 . V_94 ) )
return;
F_75 ( V_9 -> V_15 , & V_9 -> V_11 . V_2 -> V_261 , & V_89 ,
sizeof( T_1 ) ) ;
F_85 ( V_9 -> V_11 . V_2 , V_89 & 0xff ) ;
}
static void F_190 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
if ( ! F_76 ( V_9 ) ||
V_2 -> V_73 ||
V_2 -> V_80 == - 1 ||
F_103 ( V_9 -> V_15 , V_2 -> V_80 ) ) {
return;
}
F_79 ( V_2 -> V_9 ) ;
}
void F_191 ( struct V_8 * V_9 )
{
T_1 V_89 , V_98 ;
int V_262 , V_263 ;
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
F_190 ( V_9 , V_2 ) ;
if ( ! F_3 ( V_260 , & V_9 -> V_11 . V_94 ) )
return;
V_98 = F_19 ( V_2 , V_104 ) & 0xff ;
V_262 = F_59 ( V_2 ) ;
if ( V_262 < 0 )
V_262 = 0 ;
V_263 = F_66 ( V_2 ) ;
if ( V_263 < 0 )
V_263 = 0 ;
V_89 = ( V_98 & 0xff ) | ( ( V_263 & 0xf0 ) << 8 ) | ( V_262 << 24 ) ;
F_73 ( V_9 -> V_15 , & V_9 -> V_11 . V_2 -> V_261 , & V_89 ,
sizeof( T_1 ) ) ;
}
int F_192 ( struct V_8 * V_9 , T_7 V_264 )
{
if ( V_264 ) {
if ( F_193 ( V_9 -> V_15 ,
& V_9 -> V_11 . V_2 -> V_261 ,
V_264 , sizeof( T_1 ) ) )
return - V_265 ;
F_80 ( V_260 , & V_9 -> V_11 . V_94 ) ;
} else {
F_82 ( V_260 , & V_9 -> V_11 . V_94 ) ;
}
V_9 -> V_11 . V_2 -> V_264 = V_264 ;
return 0 ;
}
int F_194 ( struct V_8 * V_9 , T_1 V_266 , T_6 V_89 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_1 V_67 = ( V_266 - V_267 ) << 4 ;
if ( ! F_195 ( V_9 -> V_15 ) || ! F_25 ( V_2 ) )
return 1 ;
if ( V_67 == V_151 )
return 1 ;
if ( V_67 == V_149 )
F_150 ( V_2 , V_151 , ( T_1 ) ( V_89 >> 32 ) ) ;
return F_150 ( V_2 , V_67 , ( T_1 ) V_89 ) ;
}
int F_196 ( struct V_8 * V_9 , T_1 V_266 , T_6 * V_89 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_1 V_67 = ( V_266 - V_267 ) << 4 , V_268 , V_269 = 0 ;
if ( ! F_195 ( V_9 -> V_15 ) || ! F_25 ( V_2 ) )
return 1 ;
if ( V_67 == V_31 || V_67 == V_151 ) {
F_78 ( L_48 ,
V_67 ) ;
return 1 ;
}
if ( F_124 ( V_2 , V_67 , 4 , & V_268 ) )
return 1 ;
if ( V_67 == V_149 )
F_124 ( V_2 , V_151 , 4 , & V_269 ) ;
* V_89 = ( ( ( T_6 ) V_269 ) << 32 ) | V_268 ;
return 0 ;
}
int F_197 ( struct V_8 * V_9 , T_1 V_67 , T_6 V_89 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_48 ( V_9 ) )
return 1 ;
if ( V_67 == V_149 )
F_150 ( V_2 , V_151 , ( T_1 ) ( V_89 >> 32 ) ) ;
return F_150 ( V_2 , V_67 , ( T_1 ) V_89 ) ;
}
int F_198 ( struct V_8 * V_9 , T_1 V_67 , T_6 * V_89 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_1 V_268 , V_269 = 0 ;
if ( ! F_48 ( V_9 ) )
return 1 ;
if ( F_124 ( V_2 , V_67 , 4 , & V_268 ) )
return 1 ;
if ( V_67 == V_149 )
F_124 ( V_2 , V_151 , 4 , & V_269 ) ;
* V_89 = ( ( ( T_6 ) V_269 ) << 32 ) | V_268 ;
return 0 ;
}
int F_199 ( struct V_8 * V_9 , T_6 V_89 )
{
T_6 V_181 = V_89 & ~ V_91 ;
if ( ! F_200 ( V_181 , 4 ) )
return 1 ;
V_9 -> V_11 . V_88 . V_90 = V_89 ;
if ( ! F_76 ( V_9 ) )
return 0 ;
return F_193 ( V_9 -> V_15 , & V_9 -> V_11 . V_88 . V_89 ,
V_181 , sizeof( T_3 ) ) ;
}
void F_201 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_3 V_139 ;
unsigned long V_270 ;
if ( ! F_48 ( V_9 ) || ! V_2 -> V_136 )
return;
V_270 = F_55 ( & V_2 -> V_136 , 0 ) ;
if ( F_3 ( V_137 , & V_270 ) ) {
F_166 ( V_9 ) ;
F_202 ( V_9 ) ;
if ( F_164 ( V_2 -> V_9 ) )
V_9 -> V_11 . V_271 = V_272 ;
else
V_9 -> V_11 . V_271 = V_273 ;
}
if ( F_3 ( V_140 , & V_270 ) &&
V_9 -> V_11 . V_271 == V_273 ) {
F_203 () ;
V_139 = V_2 -> V_139 ;
F_78 ( L_49 ,
V_9 -> V_109 , V_139 ) ;
F_204 ( V_9 , V_139 ) ;
V_9 -> V_11 . V_271 = V_272 ;
}
}
void F_205 ( void )
{
F_206 ( & V_234 , V_274 ) ;
F_206 ( & V_45 , V_274 ) ;
}
