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
void F_54 ( struct V_8 * V_9 , T_1 * V_71 )
{
T_1 V_19 , V_72 ;
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
for ( V_19 = 0 ; V_19 <= 7 ; V_19 ++ ) {
V_72 = F_55 ( & V_71 [ V_19 ] , 0 ) ;
if ( V_72 )
* ( ( T_1 * ) ( V_2 -> V_5 + V_13 + V_19 * 0x10 ) ) |= V_72 ;
}
}
static inline void F_56 ( int V_6 , struct V_1 * V_2 )
{
F_7 ( V_6 , V_2 -> V_5 + V_13 ) ;
V_2 -> V_73 = true ;
}
static inline int F_57 ( struct V_1 * V_2 )
{
return F_50 ( V_2 -> V_5 + V_13 ) ;
}
static inline int F_58 ( struct V_1 * V_2 )
{
int V_74 ;
if ( ! V_2 -> V_73 )
return - 1 ;
V_75 -> V_76 ( V_2 -> V_9 ) ;
V_74 = F_57 ( V_2 ) ;
ASSERT ( V_74 == - 1 || V_74 >= 16 ) ;
return V_74 ;
}
static inline void F_59 ( int V_6 , struct V_1 * V_2 )
{
struct V_8 * V_9 ;
V_9 = V_2 -> V_9 ;
if ( F_60 ( F_61 ( V_9 -> V_15 ) ) ) {
F_9 ( V_6 , V_2 -> V_5 + V_13 ) ;
F_62 ( V_77 , V_9 ) ;
} else {
V_2 -> V_73 = false ;
F_9 ( V_6 , V_2 -> V_5 + V_13 ) ;
if ( F_57 ( V_2 ) != - 1 )
V_2 -> V_73 = true ;
}
}
static inline void F_63 ( int V_6 , struct V_1 * V_2 )
{
struct V_8 * V_9 ;
if ( F_11 ( V_6 , V_2 -> V_5 + V_12 ) )
return;
V_9 = V_2 -> V_9 ;
if ( F_60 ( F_61 ( V_9 -> V_15 ) ) )
V_75 -> V_78 ( V_9 -> V_15 , V_6 ) ;
else {
++ V_2 -> V_79 ;
F_64 ( V_2 -> V_79 > V_68 ) ;
V_2 -> V_80 = V_6 ;
}
}
static inline int F_65 ( struct V_1 * V_2 )
{
int V_74 ;
if ( ! V_2 -> V_79 )
return - 1 ;
if ( F_66 ( V_2 -> V_80 != - 1 ) )
return V_2 -> V_80 ;
V_74 = F_50 ( V_2 -> V_5 + V_12 ) ;
ASSERT ( V_74 == - 1 || V_74 >= 16 ) ;
return V_74 ;
}
static inline void F_67 ( int V_6 , struct V_1 * V_2 )
{
struct V_8 * V_9 ;
if ( ! F_13 ( V_6 , V_2 -> V_5 + V_12 ) )
return;
V_9 = V_2 -> V_9 ;
if ( F_60 ( F_61 ( V_9 -> V_15 ) ) )
V_75 -> V_78 ( V_9 -> V_15 ,
F_65 ( V_2 ) ) ;
else {
-- V_2 -> V_79 ;
F_64 ( V_2 -> V_79 < 0 ) ;
V_2 -> V_80 = - 1 ;
}
}
int F_68 ( struct V_8 * V_9 )
{
int V_81 ;
if ( ! F_48 ( V_9 ) )
return 0 ;
V_81 = F_58 ( V_9 -> V_11 . V_2 ) ;
return V_81 ;
}
int F_69 ( struct V_8 * V_9 , struct V_82 * V_83 ,
unsigned long * V_84 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
return F_70 ( V_2 , V_83 -> V_85 , V_83 -> V_10 ,
V_83 -> V_86 , V_83 -> V_87 , V_84 ) ;
}
static int F_71 ( struct V_8 * V_9 , T_3 V_4 )
{
return F_72 ( V_9 -> V_15 , & V_9 -> V_11 . V_88 . V_89 , & V_4 ,
sizeof( V_4 ) ) ;
}
static int F_73 ( struct V_8 * V_9 , T_3 * V_4 )
{
return F_74 ( V_9 -> V_15 , & V_9 -> V_11 . V_88 . V_89 , V_4 ,
sizeof( * V_4 ) ) ;
}
static inline bool F_75 ( struct V_8 * V_9 )
{
return V_9 -> V_11 . V_88 . V_90 & V_91 ;
}
static bool F_76 ( struct V_8 * V_9 )
{
T_3 V_4 ;
if ( F_73 ( V_9 , & V_4 ) < 0 )
F_77 ( L_1 ,
( unsigned long long ) V_9 -> V_11 . V_88 . V_90 ) ;
return V_4 & 0x1 ;
}
static void F_78 ( struct V_8 * V_9 )
{
if ( F_71 ( V_9 , V_92 ) < 0 ) {
F_77 ( L_2 ,
( unsigned long long ) V_9 -> V_11 . V_88 . V_90 ) ;
return;
}
F_79 ( V_93 , & V_9 -> V_11 . V_94 ) ;
}
static void F_80 ( struct V_8 * V_9 )
{
if ( F_71 ( V_9 , V_95 ) < 0 ) {
F_77 ( L_3 ,
( unsigned long long ) V_9 -> V_11 . V_88 . V_90 ) ;
return;
}
F_81 ( V_93 , & V_9 -> V_11 . V_94 ) ;
}
void F_82 ( struct V_8 * V_9 , T_1 * V_96 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < 8 ; V_19 ++ )
F_1 ( V_2 , V_97 + 0x10 * V_19 , V_96 [ V_19 ] ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
T_1 V_98 , V_99 , V_100 , V_101 ;
int V_102 ;
V_101 = F_19 ( V_2 , V_103 ) ;
V_98 = F_19 ( V_2 , V_104 ) ;
V_102 = F_65 ( V_2 ) ;
V_99 = ( V_102 != - 1 ) ? V_102 : 0 ;
if ( ( V_98 & 0xf0 ) >= ( V_99 & 0xf0 ) )
V_100 = V_98 & 0xff ;
else
V_100 = V_99 & 0xf0 ;
F_77 ( L_4 ,
V_2 , V_100 , V_102 , V_99 ) ;
if ( V_101 != V_100 ) {
F_1 ( V_2 , V_103 , V_100 ) ;
if ( V_100 < V_101 )
F_62 ( V_77 , V_2 -> V_9 ) ;
}
}
static void F_84 ( struct V_1 * V_2 , T_1 V_98 )
{
F_1 ( V_2 , V_104 , V_98 ) ;
F_83 ( V_2 ) ;
}
static int F_85 ( struct V_1 * V_2 , T_1 V_105 )
{
return V_105 == ( F_25 ( V_2 ) ?
V_29 : V_28 ) ;
}
int F_86 ( struct V_1 * V_2 , T_1 V_105 )
{
return F_18 ( V_2 ) == V_105 || F_85 ( V_2 , V_105 ) ;
}
int F_87 ( struct V_1 * V_2 , T_1 V_106 )
{
int V_74 = 0 ;
T_1 V_107 ;
if ( F_85 ( V_2 , V_106 ) )
return 1 ;
if ( F_25 ( V_2 ) ) {
V_107 = F_19 ( V_2 , V_30 ) ;
return V_107 & V_106 ;
}
V_107 = F_88 ( F_19 ( V_2 , V_30 ) ) ;
switch ( F_19 ( V_2 , V_31 ) ) {
case V_108 :
if ( V_107 & V_106 )
V_74 = 1 ;
break;
case V_32 :
if ( ( ( V_107 >> 4 ) == ( V_106 >> 0x4 ) )
&& ( V_107 & V_106 & 0xf ) )
V_74 = 1 ;
break;
default:
F_77 ( L_5 ,
V_2 -> V_9 -> V_109 , F_19 ( V_2 , V_31 ) ) ;
break;
}
return V_74 ;
}
int F_89 ( struct V_8 * V_9 , struct V_1 * V_110 ,
int V_111 , unsigned int V_105 , int V_112 )
{
int V_74 = 0 ;
struct V_1 * V_113 = V_9 -> V_11 . V_2 ;
F_77 ( L_6
L_7 ,
V_113 , V_110 , V_105 , V_112 , V_111 ) ;
ASSERT ( V_113 ) ;
switch ( V_111 ) {
case V_114 :
if ( V_112 == 0 )
V_74 = F_86 ( V_113 , V_105 ) ;
else
V_74 = F_87 ( V_113 , V_105 ) ;
break;
case V_115 :
V_74 = ( V_113 == V_110 ) ;
break;
case V_116 :
V_74 = 1 ;
break;
case V_117 :
V_74 = ( V_113 != V_110 ) ;
break;
default:
F_77 ( L_8 ,
V_111 ) ;
break;
}
return V_74 ;
}
bool F_90 ( struct V_15 * V_15 , struct V_1 * V_118 ,
struct V_82 * V_83 , int * V_119 , unsigned long * V_84 )
{
struct V_16 * V_120 ;
unsigned long V_7 = 1 ;
struct V_1 * * V_121 ;
int V_19 ;
bool V_122 = false ;
* V_119 = - 1 ;
if ( V_83 -> V_123 == V_115 ) {
* V_119 = F_69 ( V_118 -> V_9 , V_83 , V_84 ) ;
return true ;
}
if ( V_83 -> V_123 )
return false ;
F_91 () ;
V_120 = F_92 ( V_15 -> V_11 . V_39 ) ;
if ( ! V_120 )
goto V_22;
if ( V_83 -> V_124 == V_120 -> V_27 )
goto V_22;
V_122 = true ;
if ( V_83 -> V_112 == 0 ) {
if ( V_83 -> V_124 >= F_28 ( V_120 -> V_37 ) )
goto V_22;
V_121 = & V_120 -> V_37 [ V_83 -> V_124 ] ;
} else {
T_1 V_106 = V_83 -> V_124 << ( 32 - V_120 -> V_23 ) ;
T_2 V_33 = F_26 ( V_120 , V_106 ) ;
if ( V_33 >= F_28 ( V_120 -> V_38 ) )
goto V_22;
V_121 = V_120 -> V_38 [ V_33 ] ;
V_7 = F_27 ( V_120 , V_106 ) ;
if ( V_83 -> V_85 == V_125 ) {
int V_126 = - 1 ;
F_93 (i, &bitmap, 16 ) {
if ( ! V_121 [ V_19 ] )
continue;
if ( V_126 < 0 )
V_126 = V_19 ;
else if ( F_94 ( V_121 [ V_19 ] -> V_9 , V_121 [ V_126 ] -> V_9 ) < 0 )
V_126 = V_19 ;
}
V_7 = ( V_126 >= 0 ) ? 1 << V_126 : 0 ;
}
}
F_93 (i, &bitmap, 16 ) {
if ( ! V_121 [ V_19 ] )
continue;
if ( * V_119 < 0 )
* V_119 = 0 ;
* V_119 += F_69 ( V_121 [ V_19 ] -> V_9 , V_83 , V_84 ) ;
}
V_22:
F_95 () ;
return V_122 ;
}
static int F_70 ( struct V_1 * V_2 , int V_85 ,
int V_10 , int V_86 , int V_87 ,
unsigned long * V_84 )
{
int V_74 = 0 ;
struct V_8 * V_9 = V_2 -> V_9 ;
F_96 ( V_9 -> V_109 , V_85 ,
V_87 , V_10 ) ;
switch ( V_85 ) {
case V_125 :
V_9 -> V_11 . V_127 ++ ;
case V_128 :
if ( F_60 ( ! F_15 ( V_2 ) ) )
break;
V_74 = 1 ;
if ( V_84 )
F_79 ( V_9 -> V_109 , V_84 ) ;
if ( V_75 -> V_129 )
V_75 -> V_129 ( V_9 , V_10 ) ;
else {
F_56 ( V_10 , V_2 ) ;
F_62 ( V_77 , V_9 ) ;
F_97 ( V_9 ) ;
}
break;
case V_130 :
V_74 = 1 ;
V_9 -> V_11 . V_131 . V_132 = 1 ;
F_62 ( V_77 , V_9 ) ;
F_97 ( V_9 ) ;
break;
case V_133 :
F_77 ( L_9 ) ;
break;
case V_58 :
V_74 = 1 ;
F_98 ( V_9 ) ;
F_97 ( V_9 ) ;
break;
case V_134 :
if ( ! V_87 || V_86 ) {
V_74 = 1 ;
V_2 -> V_135 = ( 1UL << V_136 ) ;
F_99 () ;
F_62 ( V_77 , V_9 ) ;
F_97 ( V_9 ) ;
} else {
F_77 ( L_10 ,
V_9 -> V_109 ) ;
}
break;
case V_137 :
F_77 ( L_11 ,
V_9 -> V_109 , V_10 ) ;
V_74 = 1 ;
V_2 -> V_138 = V_10 ;
F_99 () ;
F_8 ( V_139 , & V_2 -> V_135 ) ;
F_62 ( V_77 , V_9 ) ;
F_97 ( V_9 ) ;
break;
case V_140 :
break;
default:
F_100 ( V_141 L_12 ,
V_85 ) ;
break;
}
return V_74 ;
}
int F_94 ( struct V_8 * V_142 , struct V_8 * V_143 )
{
return V_142 -> V_11 . V_127 - V_143 -> V_11 . V_127 ;
}
static void F_101 ( struct V_1 * V_2 , int V_10 )
{
if ( ! ( F_19 ( V_2 , V_43 ) & V_144 ) &&
F_102 ( V_2 -> V_9 -> V_15 , V_10 ) ) {
int V_145 ;
if ( F_2 ( V_10 , V_2 -> V_5 + V_97 ) )
V_145 = V_146 ;
else
V_145 = V_147 ;
F_103 ( V_2 -> V_9 , V_10 , V_145 ) ;
}
}
static int F_104 ( struct V_1 * V_2 )
{
int V_10 = F_65 ( V_2 ) ;
F_105 ( V_2 , V_10 ) ;
if ( V_10 == - 1 )
return V_10 ;
F_67 ( V_10 , V_2 ) ;
F_83 ( V_2 ) ;
F_101 ( V_2 , V_10 ) ;
F_62 ( V_77 , V_2 -> V_9 ) ;
return V_10 ;
}
void F_106 ( struct V_8 * V_9 , int V_10 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
F_105 ( V_2 , V_10 ) ;
F_101 ( V_2 , V_10 ) ;
F_62 ( V_77 , V_2 -> V_9 ) ;
}
static void F_107 ( struct V_1 * V_2 )
{
T_1 V_148 = F_19 ( V_2 , V_149 ) ;
T_1 V_150 = F_19 ( V_2 , V_151 ) ;
struct V_82 V_83 ;
V_83 . V_10 = V_148 & V_50 ;
V_83 . V_85 = V_148 & V_57 ;
V_83 . V_112 = V_148 & V_152 ;
V_83 . V_86 = V_148 & V_153 ;
V_83 . V_87 = V_148 & V_154 ;
V_83 . V_123 = V_148 & V_155 ;
if ( F_25 ( V_2 ) )
V_83 . V_124 = V_150 ;
else
V_83 . V_124 = F_108 ( V_150 ) ;
F_109 ( V_148 , V_83 . V_124 ) ;
F_77 ( L_13
L_14
L_15 ,
V_150 , V_148 , V_83 . V_123 , V_83 . V_124 ,
V_83 . V_87 , V_83 . V_86 , V_83 . V_112 , V_83 . V_85 ,
V_83 . V_10 ) ;
F_110 ( V_2 -> V_9 -> V_15 , V_2 , & V_83 , NULL ) ;
}
static T_1 F_111 ( struct V_1 * V_2 )
{
T_4 V_156 ;
T_5 V_157 ;
T_1 V_158 ;
ASSERT ( V_2 != NULL ) ;
if ( F_19 ( V_2 , V_159 ) == 0 ||
V_2 -> V_51 . V_160 == 0 )
return 0 ;
V_156 = F_112 ( & V_2 -> V_51 . V_161 ) ;
if ( F_113 ( V_156 ) < 0 )
V_156 = F_114 ( 0 , 0 ) ;
V_157 = F_115 ( F_113 ( V_156 ) , V_2 -> V_51 . V_160 ) ;
V_158 = F_116 ( V_157 ,
( V_162 * V_2 -> V_163 ) ) ;
return V_158 ;
}
static void F_117 ( struct V_1 * V_2 , bool V_164 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_165 * V_166 = V_9 -> V_166 ;
F_62 ( V_167 , V_9 ) ;
V_166 -> V_168 . V_169 = F_118 ( V_9 ) ;
V_166 -> V_168 . V_170 = V_164 ;
}
static inline void F_119 ( struct V_1 * V_2 , bool V_164 )
{
if ( V_2 -> V_9 -> V_11 . V_171 )
F_117 ( V_2 , V_164 ) ;
}
static T_1 F_120 ( struct V_1 * V_2 , unsigned int V_172 )
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
F_77 ( L_16 ) ;
break;
case V_175 :
if ( F_45 ( V_2 ) )
return 0 ;
V_4 = F_111 ( V_2 ) ;
break;
case V_103 :
F_83 ( V_2 ) ;
V_4 = F_19 ( V_2 , V_172 ) ;
break;
case V_104 :
F_119 ( V_2 , false ) ;
default:
V_4 = F_19 ( V_2 , V_172 ) ;
break;
}
return V_4 ;
}
static inline struct V_1 * F_121 ( struct V_176 * V_177 )
{
return F_122 ( V_177 , struct V_1 , V_177 ) ;
}
static int F_123 ( struct V_1 * V_2 , T_1 V_172 , int V_178 ,
void * V_89 )
{
unsigned char V_179 = V_172 & 0xf ;
T_1 V_74 ;
static const T_6 V_180 = 0x43ff01ffffffe70cULL ;
if ( ( V_179 + V_178 ) > 4 ) {
F_77 ( L_17 ,
V_172 , V_178 ) ;
return 1 ;
}
if ( V_172 > 0x3f0 || ! ( V_180 & ( 1ULL << ( V_172 >> 4 ) ) ) ) {
F_77 ( L_18 ,
V_172 ) ;
return 1 ;
}
V_74 = F_120 ( V_2 , V_172 & ~ 0xf ) ;
F_124 ( V_172 , V_74 ) ;
switch ( V_178 ) {
case 1 :
case 2 :
case 4 :
memcpy ( V_89 , ( char * ) & V_74 + V_179 , V_178 ) ;
break;
default:
F_100 ( V_141 L_19
L_20 , V_178 ) ;
break;
}
return 0 ;
}
static int F_125 ( struct V_1 * V_2 , T_7 V_181 )
{
return F_17 ( V_2 ) &&
V_181 >= V_2 -> V_182 &&
V_181 < V_2 -> V_182 + V_173 ;
}
static int F_126 ( struct V_176 * V_183 ,
T_7 V_184 , int V_178 , void * V_89 )
{
struct V_1 * V_2 = F_121 ( V_183 ) ;
T_1 V_172 = V_184 - V_2 -> V_182 ;
if ( ! F_125 ( V_2 , V_184 ) )
return - V_185 ;
F_123 ( V_2 , V_172 , V_178 , V_89 ) ;
return 0 ;
}
static void F_127 ( struct V_1 * V_2 )
{
T_1 V_186 , V_187 , V_188 ;
V_188 = F_19 ( V_2 , V_189 ) ;
V_186 = V_188 & 0xf ;
V_187 = ( ( V_186 & 0x3 ) | ( ( V_186 & 0x8 ) >> 1 ) ) + 1 ;
V_2 -> V_163 = 0x1 << ( V_187 & 0x7 ) ;
F_77 ( L_21 ,
V_2 -> V_163 ) ;
}
static void F_128 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_8 * V_190 = & V_9 -> V_191 ;
if ( F_129 ( & V_2 -> V_51 . V_192 ) )
return;
F_130 ( & V_2 -> V_51 . V_192 ) ;
F_62 ( V_193 , V_9 ) ;
if ( F_131 ( V_190 ) )
F_132 ( V_190 ) ;
}
static void F_133 ( struct V_1 * V_2 )
{
T_4 V_194 ;
F_134 ( & V_2 -> V_51 . V_192 , 0 ) ;
if ( F_44 ( V_2 ) || F_43 ( V_2 ) ) {
V_194 = V_2 -> V_51 . V_161 . V_195 -> V_196 () ;
V_2 -> V_51 . V_160 = ( T_6 ) F_19 ( V_2 , V_159 )
* V_162 * V_2 -> V_163 ;
if ( ! V_2 -> V_51 . V_160 )
return;
if ( F_44 ( V_2 ) ) {
T_5 V_197 = V_198 * 1000LL ;
if ( V_2 -> V_51 . V_160 < V_197 ) {
F_135 (
L_22
L_23 ,
V_2 -> V_9 -> V_109 ,
V_2 -> V_51 . V_160 , V_197 ) ;
V_2 -> V_51 . V_160 = V_197 ;
}
}
F_136 ( & V_2 -> V_51 . V_161 ,
F_137 ( V_194 , V_2 -> V_51 . V_160 ) ,
V_199 ) ;
F_77 ( L_24 V_200 L_25
V_201 L_26
L_27
L_28 V_201 L_29 , V_202 ,
V_162 , F_113 ( V_194 ) ,
F_19 ( V_2 , V_159 ) ,
V_2 -> V_51 . V_160 ,
F_113 ( F_137 ( V_194 ,
V_2 -> V_51 . V_160 ) ) ) ;
} else if ( F_45 ( V_2 ) ) {
T_6 V_203 , V_204 = V_2 -> V_51 . V_204 ;
T_6 V_157 = 0 ;
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned long V_205 = V_9 -> V_11 . V_206 ;
unsigned long V_207 ;
if ( F_60 ( ! V_204 || ! V_205 ) )
return;
F_138 ( V_207 ) ;
V_194 = V_2 -> V_51 . V_161 . V_195 -> V_196 () ;
V_203 = V_75 -> V_208 ( V_9 , F_139 () ) ;
if ( F_66 ( V_204 > V_203 ) ) {
V_157 = ( V_204 - V_203 ) * 1000000ULL ;
F_140 ( V_157 , V_205 ) ;
F_136 ( & V_2 -> V_51 . V_161 ,
F_137 ( V_194 , V_157 ) , V_199 ) ;
} else
F_128 ( V_2 ) ;
F_141 ( V_207 ) ;
}
}
static void F_142 ( struct V_1 * V_2 , T_1 V_209 )
{
int V_210 = F_46 ( F_19 ( V_2 , V_211 ) ) ;
if ( F_46 ( V_209 ) ) {
if ( ! V_210 ) {
F_77 ( L_30
L_31 , V_2 -> V_9 -> V_109 ) ;
V_2 -> V_9 -> V_15 -> V_11 . V_212 ++ ;
}
} else if ( V_210 )
V_2 -> V_9 -> V_15 -> V_11 . V_212 -- ;
}
static int F_143 ( struct V_1 * V_2 , T_1 V_67 , T_1 V_4 )
{
int V_122 = 0 ;
F_144 ( V_67 , V_4 ) ;
switch ( V_67 ) {
case V_14 :
if ( ! F_25 ( V_2 ) )
F_39 ( V_2 , V_4 >> 24 ) ;
else
V_122 = 1 ;
break;
case V_104 :
F_119 ( V_2 , true ) ;
F_84 ( V_2 , V_4 & 0xff ) ;
break;
case V_213 :
F_104 ( V_2 ) ;
break;
case V_30 :
if ( ! F_25 ( V_2 ) )
F_40 ( V_2 , V_4 & V_214 ) ;
else
V_122 = 1 ;
break;
case V_31 :
if ( ! F_25 ( V_2 ) ) {
F_1 ( V_2 , V_31 , V_4 | 0x0FFFFFFF ) ;
F_20 ( V_2 -> V_9 -> V_15 ) ;
} else
V_122 = 1 ;
break;
case V_43 : {
T_1 V_215 = 0x3ff ;
if ( F_19 ( V_2 , V_66 ) & V_65 )
V_215 |= V_144 ;
F_36 ( V_2 , V_4 & V_215 ) ;
if ( ! ( V_4 & V_42 ) ) {
int V_19 ;
T_1 V_56 ;
for ( V_19 = 0 ; V_19 < V_216 ; V_19 ++ ) {
V_56 = F_19 ( V_2 ,
V_217 + 0x10 * V_19 ) ;
F_1 ( V_2 , V_217 + 0x10 * V_19 ,
V_56 | V_49 ) ;
}
F_134 ( & V_2 -> V_51 . V_192 , 0 ) ;
}
break;
}
case V_149 :
F_1 ( V_2 , V_149 , V_4 & ~ ( 1 << 12 ) ) ;
F_107 ( V_2 ) ;
break;
case V_151 :
if ( ! F_25 ( V_2 ) )
V_4 &= 0xff000000 ;
F_1 ( V_2 , V_151 , V_4 ) ;
break;
case V_211 :
F_142 ( V_2 , V_4 ) ;
case V_218 :
case V_219 :
case V_220 :
case V_221 :
if ( ! F_16 ( V_2 ) )
V_4 |= V_49 ;
V_4 &= V_222 [ ( V_67 - V_217 ) >> 4 ] ;
F_1 ( V_2 , V_67 , V_4 ) ;
break;
case V_217 : {
T_1 V_52 = V_4 & V_2 -> V_51 . V_223 ;
if ( V_2 -> V_51 . V_52 != V_52 ) {
V_2 -> V_51 . V_52 = V_52 ;
F_145 ( & V_2 -> V_51 . V_161 ) ;
}
if ( ! F_16 ( V_2 ) )
V_4 |= V_49 ;
V_4 &= ( V_222 [ 0 ] | V_2 -> V_51 . V_223 ) ;
F_1 ( V_2 , V_217 , V_4 ) ;
break;
}
case V_159 :
if ( F_45 ( V_2 ) )
break;
F_145 ( & V_2 -> V_51 . V_161 ) ;
F_1 ( V_2 , V_159 , V_4 ) ;
F_133 ( V_2 ) ;
break;
case V_189 :
if ( V_4 & 4 )
F_77 ( L_32 , V_4 ) ;
F_1 ( V_2 , V_189 , V_4 ) ;
F_127 ( V_2 ) ;
break;
case V_224 :
if ( F_25 ( V_2 ) && V_4 != 0 ) {
F_77 ( L_33 , V_4 ) ;
V_122 = 1 ;
}
break;
case V_225 :
if ( F_25 ( V_2 ) ) {
F_143 ( V_2 , V_149 , 0x40000 | ( V_4 & 0xff ) ) ;
} else
V_122 = 1 ;
break;
default:
V_122 = 1 ;
break;
}
if ( V_122 )
F_77 ( L_34 , V_67 ) ;
return V_122 ;
}
static int F_146 ( struct V_176 * V_183 ,
T_7 V_184 , int V_178 , const void * V_89 )
{
struct V_1 * V_2 = F_121 ( V_183 ) ;
unsigned int V_172 = V_184 - V_2 -> V_182 ;
T_1 V_4 ;
if ( ! F_125 ( V_2 , V_184 ) )
return - V_185 ;
if ( V_178 != 4 || ( V_172 & 0xf ) ) {
F_77 ( L_35 , V_178 , ( long ) V_184 ) ;
return 0 ;
}
V_4 = * ( T_1 * ) V_89 ;
if ( V_172 != V_213 )
F_77 ( L_36
L_37 , V_202 , V_172 , V_178 , V_4 ) ;
F_143 ( V_2 , V_172 & 0xff0 , V_4 ) ;
return 0 ;
}
void F_147 ( struct V_8 * V_9 )
{
if ( F_48 ( V_9 ) )
F_143 ( V_9 -> V_11 . V_2 , V_213 , 0 ) ;
}
void F_148 ( struct V_8 * V_9 , T_1 V_172 )
{
T_1 V_4 = 0 ;
V_172 &= 0xff0 ;
F_123 ( V_9 -> V_11 . V_2 , V_172 , 4 , & V_4 ) ;
F_143 ( V_9 -> V_11 . V_2 , V_172 , V_4 ) ;
}
void F_149 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! V_9 -> V_11 . V_2 )
return;
F_145 ( & V_2 -> V_51 . V_161 ) ;
if ( ! ( V_9 -> V_11 . V_226 & V_227 ) )
F_37 ( & V_228 ) ;
if ( ! V_2 -> V_44 )
F_37 ( & V_45 ) ;
if ( V_2 -> V_5 )
F_150 ( ( unsigned long ) V_2 -> V_5 ) ;
F_151 ( V_2 ) ;
}
T_6 F_152 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_48 ( V_9 ) || F_43 ( V_2 ) ||
F_44 ( V_2 ) )
return 0 ;
return V_2 -> V_51 . V_204 ;
}
void F_153 ( struct V_8 * V_9 , T_6 V_89 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_48 ( V_9 ) || F_43 ( V_2 ) ||
F_44 ( V_2 ) )
return;
F_145 ( & V_2 -> V_51 . V_161 ) ;
V_2 -> V_51 . V_204 = V_89 ;
F_133 ( V_2 ) ;
}
void F_154 ( struct V_8 * V_9 , unsigned long V_229 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_48 ( V_9 ) )
return;
F_84 ( V_2 , ( ( V_229 & 0x0f ) << 4 )
| ( F_19 ( V_2 , V_104 ) & 4 ) ) ;
}
T_6 F_155 ( struct V_8 * V_9 )
{
T_6 V_98 ;
if ( ! F_48 ( V_9 ) )
return 0 ;
V_98 = ( T_6 ) F_19 ( V_9 -> V_11 . V_2 , V_104 ) ;
return ( V_98 & 0xf0 ) >> 4 ;
}
void F_156 ( struct V_8 * V_9 , T_6 V_230 )
{
T_6 V_231 = V_9 -> V_11 . V_226 ;
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! V_2 ) {
V_230 |= V_232 ;
V_9 -> V_11 . V_226 = V_230 ;
return;
}
if ( ! F_157 ( V_2 -> V_9 ) )
V_230 &= ~ V_232 ;
V_9 -> V_11 . V_226 = V_230 ;
if ( ( V_231 ^ V_230 ) & V_227 ) {
if ( V_230 & V_227 )
F_37 ( & V_228 ) ;
else
F_38 ( & V_228 . V_46 ) ;
F_20 ( V_9 -> V_15 ) ;
}
if ( ( V_231 ^ V_230 ) & V_233 ) {
if ( V_230 & V_233 ) {
T_1 V_47 = F_18 ( V_2 ) ;
T_1 V_35 = ( ( V_47 >> 4 ) << 16 ) | ( 1 << ( V_47 & 0xf ) ) ;
F_40 ( V_2 , V_35 ) ;
V_75 -> V_234 ( V_9 , true ) ;
} else
V_75 -> V_234 ( V_9 , false ) ;
}
V_2 -> V_182 = V_2 -> V_9 -> V_11 . V_226 &
V_235 ;
if ( ( V_230 & V_227 ) &&
V_2 -> V_182 != V_236 )
F_158 ( L_38 ) ;
F_77 ( L_39 V_201 L_40
L_41 , V_2 -> V_9 -> V_11 . V_226 , V_2 -> V_182 ) ;
}
void F_159 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
int V_19 ;
F_77 ( L_42 , V_202 ) ;
ASSERT ( V_9 ) ;
V_2 = V_9 -> V_11 . V_2 ;
ASSERT ( V_2 != NULL ) ;
F_145 ( & V_2 -> V_51 . V_161 ) ;
F_39 ( V_2 , V_9 -> V_109 ) ;
F_47 ( V_2 -> V_9 ) ;
for ( V_19 = 0 ; V_19 < V_216 ; V_19 ++ )
F_1 ( V_2 , V_217 + 0x10 * V_19 , V_49 ) ;
V_2 -> V_51 . V_52 = 0 ;
F_1 ( V_2 , V_211 ,
F_160 ( 0 , V_237 ) ) ;
F_1 ( V_2 , V_31 , 0xffffffffU ) ;
F_36 ( V_2 , 0xff ) ;
F_1 ( V_2 , V_104 , 0 ) ;
F_40 ( V_2 , 0 ) ;
F_1 ( V_2 , V_224 , 0 ) ;
F_1 ( V_2 , V_149 , 0 ) ;
F_1 ( V_2 , V_151 , 0 ) ;
F_1 ( V_2 , V_189 , 0 ) ;
F_1 ( V_2 , V_159 , 0 ) ;
for ( V_19 = 0 ; V_19 < 8 ; V_19 ++ ) {
F_1 ( V_2 , V_13 + 0x10 * V_19 , 0 ) ;
F_1 ( V_2 , V_12 + 0x10 * V_19 , 0 ) ;
F_1 ( V_2 , V_97 + 0x10 * V_19 , 0 ) ;
}
V_2 -> V_73 = F_61 ( V_9 -> V_15 ) ;
V_2 -> V_79 = F_61 ( V_9 -> V_15 ) ;
V_2 -> V_80 = - 1 ;
F_127 ( V_2 ) ;
F_134 ( & V_2 -> V_51 . V_192 , 0 ) ;
if ( F_157 ( V_9 ) )
F_156 ( V_9 ,
V_9 -> V_11 . V_226 | V_232 ) ;
V_9 -> V_11 . V_88 . V_90 = 0 ;
F_83 ( V_2 ) ;
V_9 -> V_11 . V_127 = 0 ;
V_9 -> V_11 . V_94 = 0 ;
F_77 ( L_43
L_44 V_201 L_45 , V_202 ,
V_9 , F_18 ( V_2 ) ,
V_9 -> V_11 . V_226 , V_2 -> V_182 ) ;
}
static bool F_161 ( struct V_1 * V_2 )
{
return F_44 ( V_2 ) ;
}
int F_162 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( F_48 ( V_9 ) && F_15 ( V_2 ) &&
F_41 ( V_2 , V_217 ) )
return F_129 ( & V_2 -> V_51 . V_192 ) ;
return 0 ;
}
int F_163 ( struct V_1 * V_2 , int V_48 )
{
T_1 V_67 = F_19 ( V_2 , V_48 ) ;
int V_10 , V_238 , V_87 ;
if ( F_17 ( V_2 ) && ! ( V_67 & V_49 ) ) {
V_10 = V_67 & V_50 ;
V_238 = V_67 & V_57 ;
V_87 = V_67 & V_239 ;
return F_70 ( V_2 , V_238 , V_10 , 1 , V_87 ,
NULL ) ;
}
return 0 ;
}
void F_164 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( V_2 )
F_163 ( V_2 , V_211 ) ;
}
static enum V_240 F_165 ( struct V_241 * V_89 )
{
struct V_242 * V_243 = F_122 ( V_89 , struct V_242 , V_161 ) ;
struct V_1 * V_2 = F_122 ( V_243 , struct V_1 , V_51 ) ;
F_128 ( V_2 ) ;
if ( F_161 ( V_2 ) ) {
F_166 ( & V_243 -> V_161 , V_243 -> V_160 ) ;
return V_244 ;
} else
return V_245 ;
}
int F_167 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
ASSERT ( V_9 != NULL ) ;
F_77 ( L_46 , V_9 -> V_109 ) ;
V_2 = F_21 ( sizeof( * V_2 ) , V_20 ) ;
if ( ! V_2 )
goto V_246;
V_9 -> V_11 . V_2 = V_2 ;
V_2 -> V_5 = ( void * ) F_168 ( V_20 ) ;
if ( ! V_2 -> V_5 ) {
F_100 ( V_141 L_47 ,
V_9 -> V_109 ) ;
goto V_247;
}
V_2 -> V_9 = V_9 ;
F_169 ( & V_2 -> V_51 . V_161 , V_248 ,
V_199 ) ;
V_2 -> V_51 . V_161 . V_249 = F_165 ;
V_9 -> V_11 . V_226 = V_227 ;
F_156 ( V_9 ,
V_236 | V_227 ) ;
F_38 ( & V_45 . V_46 ) ;
F_159 ( V_9 ) ;
F_170 ( & V_2 -> V_177 , & V_250 ) ;
return 0 ;
V_247:
F_151 ( V_2 ) ;
V_246:
return - V_251 ;
}
int F_171 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
int V_81 ;
if ( ! F_48 ( V_9 ) || ! F_15 ( V_2 ) )
return - 1 ;
F_83 ( V_2 ) ;
V_81 = F_58 ( V_2 ) ;
if ( ( V_81 == - 1 ) ||
( ( V_81 & 0xF0 ) <= F_19 ( V_2 , V_103 ) ) )
return - 1 ;
return V_81 ;
}
int F_172 ( struct V_8 * V_9 )
{
T_1 V_252 = F_19 ( V_9 -> V_11 . V_2 , V_211 ) ;
int V_119 = 0 ;
if ( ! F_17 ( V_9 -> V_11 . V_2 ) )
V_119 = 1 ;
if ( ( V_252 & V_49 ) == 0 &&
F_173 ( V_252 ) == V_237 )
V_119 = 1 ;
return V_119 ;
}
void F_174 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_48 ( V_9 ) )
return;
if ( F_129 ( & V_2 -> V_51 . V_192 ) > 0 ) {
F_163 ( V_2 , V_217 ) ;
if ( F_45 ( V_2 ) )
V_2 -> V_51 . V_204 = 0 ;
F_134 ( & V_2 -> V_51 . V_192 , 0 ) ;
}
}
int F_175 ( struct V_8 * V_9 )
{
int V_10 = F_171 ( V_9 ) ;
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( V_10 == - 1 )
return - 1 ;
F_63 ( V_10 , V_2 ) ;
F_83 ( V_2 ) ;
F_59 ( V_10 , V_2 ) ;
return V_10 ;
}
void F_176 ( struct V_8 * V_9 ,
struct V_253 * V_254 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
F_156 ( V_9 , V_9 -> V_11 . V_226 ) ;
F_36 ( V_2 , * ( ( T_1 * ) ( V_254 -> V_5 + V_43 ) ) ) ;
memcpy ( V_9 -> V_11 . V_2 -> V_5 , V_254 -> V_5 , sizeof *V_254 ) ;
F_39 ( V_2 , F_18 ( V_2 ) ) ;
F_47 ( V_9 ) ;
F_83 ( V_2 ) ;
F_145 ( & V_2 -> V_51 . V_161 ) ;
F_127 ( V_2 ) ;
F_133 ( V_2 ) ;
V_2 -> V_73 = true ;
V_2 -> V_79 = F_61 ( V_9 -> V_15 ) ?
1 : F_52 ( V_2 -> V_5 + V_12 ) ;
V_2 -> V_80 = - 1 ;
if ( V_75 -> V_255 )
V_75 -> V_255 ( V_9 ,
F_58 ( V_2 ) ) ;
V_75 -> V_78 ( V_9 -> V_15 , F_65 ( V_2 ) ) ;
F_62 ( V_77 , V_9 ) ;
F_177 ( V_9 ) ;
}
void F_178 ( struct V_8 * V_9 )
{
struct V_241 * V_161 ;
if ( ! F_48 ( V_9 ) )
return;
V_161 = & V_9 -> V_11 . V_2 -> V_51 . V_161 ;
if ( F_145 ( V_161 ) )
F_179 ( V_161 , V_199 ) ;
}
static void F_180 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
bool V_192 ;
int V_10 ;
F_64 ( ! F_75 ( V_9 ) ) ;
V_192 = F_76 ( V_9 ) ;
F_80 ( V_9 ) ;
if ( V_192 )
return;
V_10 = F_104 ( V_2 ) ;
F_181 ( V_2 , V_10 ) ;
}
void F_182 ( struct V_8 * V_9 )
{
T_1 V_89 ;
if ( F_3 ( V_93 , & V_9 -> V_11 . V_94 ) )
F_180 ( V_9 , V_9 -> V_11 . V_2 ) ;
if ( ! F_3 ( V_256 , & V_9 -> V_11 . V_94 ) )
return;
F_74 ( V_9 -> V_15 , & V_9 -> V_11 . V_2 -> V_257 , & V_89 ,
sizeof( T_1 ) ) ;
F_84 ( V_9 -> V_11 . V_2 , V_89 & 0xff ) ;
}
static void F_183 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
if ( ! F_75 ( V_9 ) ||
V_2 -> V_73 ||
V_2 -> V_80 == - 1 ||
F_102 ( V_9 -> V_15 , V_2 -> V_80 ) ) {
return;
}
F_78 ( V_2 -> V_9 ) ;
}
void F_184 ( struct V_8 * V_9 )
{
T_1 V_89 , V_98 ;
int V_258 , V_259 ;
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
F_183 ( V_9 , V_2 ) ;
if ( ! F_3 ( V_256 , & V_9 -> V_11 . V_94 ) )
return;
V_98 = F_19 ( V_2 , V_104 ) & 0xff ;
V_258 = F_58 ( V_2 ) ;
if ( V_258 < 0 )
V_258 = 0 ;
V_259 = F_65 ( V_2 ) ;
if ( V_259 < 0 )
V_259 = 0 ;
V_89 = ( V_98 & 0xff ) | ( ( V_259 & 0xf0 ) << 8 ) | ( V_258 << 24 ) ;
F_72 ( V_9 -> V_15 , & V_9 -> V_11 . V_2 -> V_257 , & V_89 ,
sizeof( T_1 ) ) ;
}
int F_185 ( struct V_8 * V_9 , T_7 V_260 )
{
if ( V_260 ) {
if ( F_186 ( V_9 -> V_15 ,
& V_9 -> V_11 . V_2 -> V_257 ,
V_260 , sizeof( T_1 ) ) )
return - V_261 ;
F_79 ( V_256 , & V_9 -> V_11 . V_94 ) ;
} else {
F_81 ( V_256 , & V_9 -> V_11 . V_94 ) ;
}
V_9 -> V_11 . V_2 -> V_260 = V_260 ;
return 0 ;
}
int F_187 ( struct V_8 * V_9 , T_1 V_262 , T_6 V_89 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_1 V_67 = ( V_262 - V_263 ) << 4 ;
if ( ! F_188 ( V_9 -> V_15 ) || ! F_25 ( V_2 ) )
return 1 ;
if ( V_67 == V_151 )
return 1 ;
if ( V_67 == V_149 )
F_143 ( V_2 , V_151 , ( T_1 ) ( V_89 >> 32 ) ) ;
return F_143 ( V_2 , V_67 , ( T_1 ) V_89 ) ;
}
int F_189 ( struct V_8 * V_9 , T_1 V_262 , T_6 * V_89 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_1 V_67 = ( V_262 - V_263 ) << 4 , V_264 , V_265 = 0 ;
if ( ! F_188 ( V_9 -> V_15 ) || ! F_25 ( V_2 ) )
return 1 ;
if ( V_67 == V_31 || V_67 == V_151 ) {
F_77 ( L_48 ,
V_67 ) ;
return 1 ;
}
if ( F_123 ( V_2 , V_67 , 4 , & V_264 ) )
return 1 ;
if ( V_67 == V_149 )
F_123 ( V_2 , V_151 , 4 , & V_265 ) ;
* V_89 = ( ( ( T_6 ) V_265 ) << 32 ) | V_264 ;
return 0 ;
}
int F_190 ( struct V_8 * V_9 , T_1 V_67 , T_6 V_89 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_48 ( V_9 ) )
return 1 ;
if ( V_67 == V_149 )
F_143 ( V_2 , V_151 , ( T_1 ) ( V_89 >> 32 ) ) ;
return F_143 ( V_2 , V_67 , ( T_1 ) V_89 ) ;
}
int F_191 ( struct V_8 * V_9 , T_1 V_67 , T_6 * V_89 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_1 V_264 , V_265 = 0 ;
if ( ! F_48 ( V_9 ) )
return 1 ;
if ( F_123 ( V_2 , V_67 , 4 , & V_264 ) )
return 1 ;
if ( V_67 == V_149 )
F_123 ( V_2 , V_151 , 4 , & V_265 ) ;
* V_89 = ( ( ( T_6 ) V_265 ) << 32 ) | V_264 ;
return 0 ;
}
int F_192 ( struct V_8 * V_9 , T_6 V_89 )
{
T_6 V_181 = V_89 & ~ V_91 ;
if ( ! F_193 ( V_181 , 4 ) )
return 1 ;
V_9 -> V_11 . V_88 . V_90 = V_89 ;
if ( ! F_75 ( V_9 ) )
return 0 ;
return F_186 ( V_9 -> V_15 , & V_9 -> V_11 . V_88 . V_89 ,
V_181 , sizeof( T_3 ) ) ;
}
void F_194 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_3 V_138 ;
unsigned long V_266 ;
if ( ! F_48 ( V_9 ) || ! V_2 -> V_135 )
return;
V_266 = F_55 ( & V_2 -> V_135 , 0 ) ;
if ( F_3 ( V_136 , & V_266 ) ) {
F_159 ( V_9 ) ;
F_195 ( V_9 ) ;
if ( F_157 ( V_2 -> V_9 ) )
V_9 -> V_11 . V_267 = V_268 ;
else
V_9 -> V_11 . V_267 = V_269 ;
}
if ( F_3 ( V_139 , & V_266 ) &&
V_9 -> V_11 . V_267 == V_269 ) {
F_196 () ;
V_138 = V_2 -> V_138 ;
F_77 ( L_49 ,
V_9 -> V_109 , V_138 ) ;
F_197 ( V_9 , V_138 ) ;
V_9 -> V_11 . V_267 = V_268 ;
}
}
void F_198 ( void )
{
F_199 ( & V_228 , V_270 ) ;
F_199 ( & V_45 , V_270 ) ;
}
