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
static inline void F_43 ( struct V_1 * V_2 , T_3 V_47 )
{
T_1 V_32 = ( ( V_47 >> 4 ) << 16 ) | ( 1 << ( V_47 & 0xf ) ) ;
F_1 ( V_2 , V_14 , V_47 << 24 ) ;
F_1 ( V_2 , V_34 , V_32 ) ;
F_23 ( V_2 -> V_9 -> V_25 ) ;
}
static inline int F_44 ( struct V_1 * V_2 , int V_48 )
{
return ! ( F_19 ( V_2 , V_48 ) & V_49 ) ;
}
static inline int F_45 ( struct V_1 * V_2 , int V_48 )
{
return F_19 ( V_2 , V_48 ) & V_50 ;
}
static inline int F_46 ( struct V_1 * V_2 )
{
return V_2 -> V_51 . V_52 == V_53 ;
}
static inline int F_47 ( struct V_1 * V_2 )
{
return V_2 -> V_51 . V_52 == V_54 ;
}
static inline int F_48 ( struct V_1 * V_2 )
{
return V_2 -> V_51 . V_52 == V_55 ;
}
static inline int F_49 ( T_1 V_56 )
{
return ( V_56 & ( V_57 | V_49 ) ) == V_58 ;
}
void F_50 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
struct V_59 * V_60 ;
T_1 V_61 = V_62 ;
if ( ! F_51 ( V_9 ) )
return;
V_60 = F_52 ( V_2 -> V_9 , 0x1 , 0 ) ;
if ( V_60 && ( V_60 -> V_63 & ( 1 << ( V_64 & 31 ) ) ) )
V_61 |= V_65 ;
F_1 ( V_2 , V_66 , V_61 ) ;
}
static int F_53 ( void * V_7 )
{
int V_6 ;
T_1 * V_67 ;
for ( V_6 = V_68 - V_69 ;
V_6 >= 0 ; V_6 -= V_69 ) {
V_67 = V_7 + F_5 ( V_6 ) ;
if ( * V_67 )
return F_54 ( * V_67 ) - 1 + V_6 ;
}
return - 1 ;
}
static T_3 F_55 ( void * V_7 )
{
int V_6 ;
T_1 * V_67 ;
T_3 V_70 = 0 ;
for ( V_6 = 0 ; V_6 < V_68 ; V_6 += V_69 ) {
V_67 = V_7 + F_5 ( V_6 ) ;
V_70 += F_56 ( * V_67 ) ;
}
return V_70 ;
}
void F_57 ( T_1 * V_71 , void * V_5 )
{
T_1 V_28 , V_72 ;
for ( V_28 = 0 ; V_28 <= 7 ; V_28 ++ ) {
V_72 = F_58 ( & V_71 [ V_28 ] , 0 ) ;
if ( V_72 )
* ( ( T_1 * ) ( V_5 + V_13 + V_28 * 0x10 ) ) |= V_72 ;
}
}
void F_59 ( struct V_8 * V_9 , T_1 * V_71 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
F_57 ( V_71 , V_2 -> V_5 ) ;
}
static inline void F_60 ( int V_6 , struct V_1 * V_2 )
{
F_7 ( V_6 , V_2 -> V_5 + V_13 ) ;
V_2 -> V_73 = true ;
}
static inline int F_61 ( struct V_1 * V_2 )
{
return F_53 ( V_2 -> V_5 + V_13 ) ;
}
static inline int F_62 ( struct V_1 * V_2 )
{
int V_74 ;
if ( ! V_2 -> V_73 )
return - 1 ;
V_75 -> V_76 ( V_2 -> V_9 ) ;
V_74 = F_61 ( V_2 ) ;
ASSERT ( V_74 == - 1 || V_74 >= 16 ) ;
return V_74 ;
}
static inline void F_63 ( int V_6 , struct V_1 * V_2 )
{
struct V_8 * V_9 ;
V_9 = V_2 -> V_9 ;
if ( F_64 ( F_65 ( V_9 -> V_25 ) ) ) {
F_9 ( V_6 , V_2 -> V_5 + V_13 ) ;
F_66 ( V_77 , V_9 ) ;
} else {
V_2 -> V_73 = false ;
F_9 ( V_6 , V_2 -> V_5 + V_13 ) ;
if ( F_61 ( V_2 ) != - 1 )
V_2 -> V_73 = true ;
}
}
static inline void F_67 ( int V_6 , struct V_1 * V_2 )
{
struct V_8 * V_9 ;
if ( F_11 ( V_6 , V_2 -> V_5 + V_12 ) )
return;
V_9 = V_2 -> V_9 ;
if ( F_64 ( V_75 -> V_78 ) )
V_75 -> V_78 ( V_9 -> V_25 , V_6 ) ;
else {
++ V_2 -> V_79 ;
F_68 ( V_2 -> V_79 > V_68 ) ;
V_2 -> V_80 = V_6 ;
}
}
static inline int F_69 ( struct V_1 * V_2 )
{
int V_74 ;
if ( ! V_2 -> V_79 )
return - 1 ;
if ( F_70 ( V_2 -> V_80 != - 1 ) )
return V_2 -> V_80 ;
V_74 = F_53 ( V_2 -> V_5 + V_12 ) ;
ASSERT ( V_74 == - 1 || V_74 >= 16 ) ;
return V_74 ;
}
static inline void F_71 ( int V_6 , struct V_1 * V_2 )
{
struct V_8 * V_9 ;
if ( ! F_13 ( V_6 , V_2 -> V_5 + V_12 ) )
return;
V_9 = V_2 -> V_9 ;
if ( F_64 ( V_75 -> V_78 ) )
V_75 -> V_78 ( V_9 -> V_25 ,
F_69 ( V_2 ) ) ;
else {
-- V_2 -> V_79 ;
F_68 ( V_2 -> V_79 < 0 ) ;
V_2 -> V_80 = - 1 ;
}
}
int F_72 ( struct V_8 * V_9 )
{
int V_81 ;
if ( ! F_51 ( V_9 ) )
return 0 ;
V_81 = F_62 ( V_9 -> V_11 . V_2 ) ;
return V_81 ;
}
int F_73 ( struct V_8 * V_9 , struct V_82 * V_83 ,
unsigned long * V_84 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
return F_74 ( V_2 , V_83 -> V_85 , V_83 -> V_10 ,
V_83 -> V_86 , V_83 -> V_87 , V_84 ) ;
}
static int F_75 ( struct V_8 * V_9 , T_3 V_4 )
{
return F_76 ( V_9 -> V_25 , & V_9 -> V_11 . V_88 . V_89 , & V_4 ,
sizeof( V_4 ) ) ;
}
static int F_77 ( struct V_8 * V_9 , T_3 * V_4 )
{
return F_78 ( V_9 -> V_25 , & V_9 -> V_11 . V_88 . V_89 , V_4 ,
sizeof( * V_4 ) ) ;
}
static inline bool F_79 ( struct V_8 * V_9 )
{
return V_9 -> V_11 . V_88 . V_90 & V_91 ;
}
static bool F_80 ( struct V_8 * V_9 )
{
T_3 V_4 ;
if ( F_77 ( V_9 , & V_4 ) < 0 )
F_81 ( L_1 ,
( unsigned long long ) V_9 -> V_11 . V_88 . V_90 ) ;
return V_4 & 0x1 ;
}
static void F_82 ( struct V_8 * V_9 )
{
if ( F_75 ( V_9 , V_92 ) < 0 ) {
F_81 ( L_2 ,
( unsigned long long ) V_9 -> V_11 . V_88 . V_90 ) ;
return;
}
F_83 ( V_93 , & V_9 -> V_11 . V_94 ) ;
}
static void F_84 ( struct V_8 * V_9 )
{
if ( F_75 ( V_9 , V_95 ) < 0 ) {
F_81 ( L_3 ,
( unsigned long long ) V_9 -> V_11 . V_88 . V_90 ) ;
return;
}
F_85 ( V_93 , & V_9 -> V_11 . V_94 ) ;
}
void F_86 ( struct V_8 * V_9 , T_1 * V_96 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < 8 ; V_28 ++ )
F_1 ( V_2 , V_97 + 0x10 * V_28 , V_96 [ V_28 ] ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
T_1 V_98 , V_99 , V_100 , V_101 ;
int V_102 ;
V_101 = F_19 ( V_2 , V_103 ) ;
V_98 = F_19 ( V_2 , V_104 ) ;
V_102 = F_69 ( V_2 ) ;
V_99 = ( V_102 != - 1 ) ? V_102 : 0 ;
if ( ( V_98 & 0xf0 ) >= ( V_99 & 0xf0 ) )
V_100 = V_98 & 0xff ;
else
V_100 = V_99 & 0xf0 ;
F_81 ( L_4 ,
V_2 , V_100 , V_102 , V_99 ) ;
if ( V_101 != V_100 ) {
F_1 ( V_2 , V_103 , V_100 ) ;
if ( V_100 < V_101 )
F_66 ( V_77 , V_2 -> V_9 ) ;
}
}
static void F_88 ( struct V_1 * V_2 , T_1 V_98 )
{
F_1 ( V_2 , V_104 , V_98 ) ;
F_87 ( V_2 ) ;
}
static bool F_89 ( struct V_1 * V_2 , T_1 V_105 )
{
if ( F_29 ( V_2 ) )
return V_105 == V_106 ;
return F_90 ( V_105 ) == V_107 ;
}
static bool F_91 ( struct V_1 * V_2 , T_1 V_105 )
{
if ( F_89 ( V_2 , V_105 ) )
return true ;
if ( F_29 ( V_2 ) )
return V_105 == F_18 ( V_2 ) ;
return V_105 == F_92 ( F_18 ( V_2 ) ) ;
}
static bool F_93 ( struct V_1 * V_2 , T_1 V_105 )
{
T_1 V_108 ;
if ( F_89 ( V_2 , V_105 ) )
return true ;
V_108 = F_19 ( V_2 , V_34 ) ;
if ( F_29 ( V_2 ) )
return ( ( V_108 >> 16 ) == ( V_105 >> 16 ) )
&& ( V_108 & V_105 & 0xffff ) != 0 ;
V_108 = F_30 ( V_108 ) ;
V_105 = F_90 ( V_105 ) ;
switch ( F_19 ( V_2 , V_36 ) ) {
case V_37 :
return ( V_108 & V_105 ) != 0 ;
case V_109 :
return ( ( V_108 >> 4 ) == ( V_105 >> 4 ) )
&& ( V_108 & V_105 & 0xf ) != 0 ;
default:
F_81 ( L_5 ,
V_2 -> V_9 -> V_110 , F_19 ( V_2 , V_36 ) ) ;
return false ;
}
}
static T_1 F_94 ( unsigned int V_18 , struct V_1 * V_111 ,
struct V_1 * V_112 )
{
bool V_113 = V_111 != NULL ;
bool V_114 = F_29 ( V_113 ? V_111 : V_112 ) ;
if ( ! V_113 && V_18 == V_107 && V_114 )
return V_106 ;
return V_114 ? V_18 : F_92 ( V_18 ) ;
}
bool F_95 ( struct V_8 * V_9 , struct V_1 * V_111 ,
int V_115 , unsigned int V_116 , int V_117 )
{
struct V_1 * V_112 = V_9 -> V_11 . V_2 ;
T_1 V_105 = F_94 ( V_116 , V_111 , V_112 ) ;
F_81 ( L_6
L_7 ,
V_112 , V_111 , V_116 , V_117 , V_115 ) ;
ASSERT ( V_112 ) ;
switch ( V_115 ) {
case V_118 :
if ( V_117 == V_119 )
return F_91 ( V_112 , V_105 ) ;
else
return F_93 ( V_112 , V_105 ) ;
case V_120 :
return V_112 == V_111 ;
case V_121 :
return true ;
case V_122 :
return V_112 != V_111 ;
default:
F_81 ( L_8 ,
V_115 ) ;
return false ;
}
}
bool F_96 ( struct V_25 * V_25 , struct V_1 * V_123 ,
struct V_82 * V_83 , int * V_124 , unsigned long * V_84 )
{
struct V_15 * V_16 ;
unsigned long V_7 = 1 ;
struct V_1 * * V_125 ;
int V_28 ;
bool V_126 , V_127 ;
* V_124 = - 1 ;
if ( V_83 -> V_128 == V_120 ) {
* V_124 = F_73 ( V_123 -> V_9 , V_83 , V_84 ) ;
return true ;
}
if ( V_83 -> V_128 )
return false ;
V_127 = V_123 && F_29 ( V_123 ) ;
if ( V_83 -> V_18 == ( V_127 ? V_106 : V_107 ) )
return false ;
V_126 = true ;
F_97 () ;
V_16 = F_98 ( V_25 -> V_11 . V_39 ) ;
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
if ( F_99 ( V_83 ) ) {
int V_129 = - 1 ;
F_100 (i, &bitmap, 16 ) {
if ( ! V_125 [ V_28 ] )
continue;
if ( V_129 < 0 )
V_129 = V_28 ;
else if ( F_101 ( V_125 [ V_28 ] -> V_9 , V_125 [ V_129 ] -> V_9 ) < 0 )
V_129 = V_28 ;
}
V_7 = ( V_129 >= 0 ) ? 1 << V_129 : 0 ;
}
}
F_100 (i, &bitmap, 16 ) {
if ( ! V_125 [ V_28 ] )
continue;
if ( * V_124 < 0 )
* V_124 = 0 ;
* V_124 += F_73 ( V_125 [ V_28 ] -> V_9 , V_83 , V_84 ) ;
}
V_31:
F_102 () ;
return V_126 ;
}
static int F_74 ( struct V_1 * V_2 , int V_85 ,
int V_10 , int V_86 , int V_87 ,
unsigned long * V_84 )
{
int V_74 = 0 ;
struct V_8 * V_9 = V_2 -> V_9 ;
F_103 ( V_9 -> V_110 , V_85 ,
V_87 , V_10 ) ;
switch ( V_85 ) {
case V_130 :
V_9 -> V_11 . V_131 ++ ;
case V_132 :
if ( F_64 ( ! F_15 ( V_2 ) ) )
break;
V_74 = 1 ;
if ( V_84 )
F_83 ( V_9 -> V_110 , V_84 ) ;
if ( V_75 -> V_133 )
V_75 -> V_133 ( V_9 , V_10 ) ;
else {
F_60 ( V_10 , V_2 ) ;
F_66 ( V_77 , V_9 ) ;
F_104 ( V_9 ) ;
}
break;
case V_134 :
V_74 = 1 ;
V_9 -> V_11 . V_135 . V_136 = 1 ;
F_66 ( V_77 , V_9 ) ;
F_104 ( V_9 ) ;
break;
case V_137 :
V_74 = 1 ;
F_66 ( V_138 , V_9 ) ;
F_104 ( V_9 ) ;
break;
case V_58 :
V_74 = 1 ;
F_105 ( V_9 ) ;
F_104 ( V_9 ) ;
break;
case V_139 :
if ( ! V_87 || V_86 ) {
V_74 = 1 ;
V_2 -> V_140 = ( 1UL << V_141 ) ;
F_106 () ;
F_66 ( V_77 , V_9 ) ;
F_104 ( V_9 ) ;
} else {
F_81 ( L_9 ,
V_9 -> V_110 ) ;
}
break;
case V_142 :
F_81 ( L_10 ,
V_9 -> V_110 , V_10 ) ;
V_74 = 1 ;
V_2 -> V_143 = V_10 ;
F_106 () ;
F_8 ( V_144 , & V_2 -> V_140 ) ;
F_66 ( V_77 , V_9 ) ;
F_104 ( V_9 ) ;
break;
case V_145 :
break;
default:
F_107 ( V_146 L_11 ,
V_85 ) ;
break;
}
return V_74 ;
}
int F_101 ( struct V_8 * V_147 , struct V_8 * V_148 )
{
return V_147 -> V_11 . V_131 - V_148 -> V_11 . V_131 ;
}
static void F_108 ( struct V_1 * V_2 , int V_10 )
{
if ( F_109 ( V_2 -> V_9 -> V_25 , V_10 ) ) {
int V_149 ;
if ( F_2 ( V_10 , V_2 -> V_5 + V_97 ) )
V_149 = V_150 ;
else
V_149 = V_151 ;
F_110 ( V_2 -> V_9 , V_10 , V_149 ) ;
}
}
static int F_111 ( struct V_1 * V_2 )
{
int V_10 = F_69 ( V_2 ) ;
F_112 ( V_2 , V_10 ) ;
if ( V_10 == - 1 )
return V_10 ;
F_71 ( V_10 , V_2 ) ;
F_87 ( V_2 ) ;
F_108 ( V_2 , V_10 ) ;
F_66 ( V_77 , V_2 -> V_9 ) ;
return V_10 ;
}
void F_113 ( struct V_8 * V_9 , int V_10 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
F_112 ( V_2 , V_10 ) ;
F_108 ( V_2 , V_10 ) ;
F_66 ( V_77 , V_2 -> V_9 ) ;
}
static void F_114 ( struct V_1 * V_2 )
{
T_1 V_152 = F_19 ( V_2 , V_153 ) ;
T_1 V_154 = F_19 ( V_2 , V_155 ) ;
struct V_82 V_83 ;
V_83 . V_10 = V_152 & V_50 ;
V_83 . V_85 = V_152 & V_57 ;
V_83 . V_117 = V_152 & V_156 ;
V_83 . V_86 = ( V_152 & V_157 ) != 0 ;
V_83 . V_87 = V_152 & V_158 ;
V_83 . V_128 = V_152 & V_159 ;
V_83 . V_160 = false ;
if ( F_29 ( V_2 ) )
V_83 . V_18 = V_154 ;
else
V_83 . V_18 = F_90 ( V_154 ) ;
F_115 ( V_152 , V_83 . V_18 ) ;
F_81 ( L_12
L_13
L_14
L_15 ,
V_154 , V_152 , V_83 . V_128 , V_83 . V_18 ,
V_83 . V_87 , V_83 . V_86 , V_83 . V_117 , V_83 . V_85 ,
V_83 . V_10 , V_83 . V_160 ) ;
F_116 ( V_2 -> V_9 -> V_25 , V_2 , & V_83 , NULL ) ;
}
static T_1 F_117 ( struct V_1 * V_2 )
{
T_4 V_161 ;
T_5 V_162 ;
T_1 V_163 ;
ASSERT ( V_2 != NULL ) ;
if ( F_19 ( V_2 , V_164 ) == 0 ||
V_2 -> V_51 . V_165 == 0 )
return 0 ;
V_161 = F_118 ( & V_2 -> V_51 . V_166 ) ;
if ( F_119 ( V_161 ) < 0 )
V_161 = F_120 ( 0 , 0 ) ;
V_162 = F_121 ( F_119 ( V_161 ) , V_2 -> V_51 . V_165 ) ;
V_163 = F_122 ( V_162 ,
( V_167 * V_2 -> V_168 ) ) ;
return V_163 ;
}
static void F_123 ( struct V_1 * V_2 , bool V_169 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_170 * V_171 = V_9 -> V_171 ;
F_66 ( V_172 , V_9 ) ;
V_171 -> V_173 . V_174 = F_124 ( V_9 ) ;
V_171 -> V_173 . V_175 = V_169 ;
}
static inline void F_125 ( struct V_1 * V_2 , bool V_169 )
{
if ( V_2 -> V_9 -> V_11 . V_176 )
F_123 ( V_2 , V_169 ) ;
}
static T_1 F_126 ( struct V_1 * V_2 , unsigned int V_177 )
{
T_1 V_4 = 0 ;
if ( V_177 >= V_178 )
return 0 ;
switch ( V_177 ) {
case V_14 :
if ( F_29 ( V_2 ) )
V_4 = F_18 ( V_2 ) ;
else
V_4 = F_18 ( V_2 ) << 24 ;
break;
case V_179 :
F_81 ( L_16 ) ;
break;
case V_180 :
if ( F_48 ( V_2 ) )
return 0 ;
V_4 = F_117 ( V_2 ) ;
break;
case V_103 :
F_87 ( V_2 ) ;
V_4 = F_19 ( V_2 , V_177 ) ;
break;
case V_104 :
F_125 ( V_2 , false ) ;
default:
V_4 = F_19 ( V_2 , V_177 ) ;
break;
}
return V_4 ;
}
static inline struct V_1 * F_127 ( struct V_181 * V_182 )
{
return F_128 ( V_182 , struct V_1 , V_182 ) ;
}
static int F_129 ( struct V_1 * V_2 , T_1 V_177 , int V_183 ,
void * V_89 )
{
unsigned char V_184 = V_177 & 0xf ;
T_1 V_74 ;
static const T_6 V_185 = 0x43ff01ffffffe70cULL ;
if ( ( V_184 + V_183 ) > 4 ) {
F_81 ( L_17 ,
V_177 , V_183 ) ;
return 1 ;
}
if ( V_177 > 0x3f0 || ! ( V_185 & ( 1ULL << ( V_177 >> 4 ) ) ) ) {
F_81 ( L_18 ,
V_177 ) ;
return 1 ;
}
V_74 = F_126 ( V_2 , V_177 & ~ 0xf ) ;
F_130 ( V_177 , V_74 ) ;
switch ( V_183 ) {
case 1 :
case 2 :
case 4 :
memcpy ( V_89 , ( char * ) & V_74 + V_184 , V_183 ) ;
break;
default:
F_107 ( V_146 L_19
L_20 , V_183 ) ;
break;
}
return 0 ;
}
static int F_131 ( struct V_1 * V_2 , T_7 V_186 )
{
return F_17 ( V_2 ) &&
V_186 >= V_2 -> V_187 &&
V_186 < V_2 -> V_187 + V_178 ;
}
static int F_132 ( struct V_8 * V_9 , struct V_181 * V_188 ,
T_7 V_189 , int V_183 , void * V_89 )
{
struct V_1 * V_2 = F_127 ( V_188 ) ;
T_1 V_177 = V_189 - V_2 -> V_187 ;
if ( ! F_131 ( V_2 , V_189 ) )
return - V_190 ;
F_129 ( V_2 , V_177 , V_183 , V_89 ) ;
return 0 ;
}
static void F_133 ( struct V_1 * V_2 )
{
T_1 V_191 , V_192 , V_193 ;
V_193 = F_19 ( V_2 , V_194 ) ;
V_191 = V_193 & 0xf ;
V_192 = ( ( V_191 & 0x3 ) | ( ( V_191 & 0x8 ) >> 1 ) ) + 1 ;
V_2 -> V_168 = 0x1 << ( V_192 & 0x7 ) ;
F_81 ( L_21 ,
V_2 -> V_168 ) ;
}
static void F_134 ( struct V_1 * V_2 )
{
T_1 V_52 = F_19 ( V_2 , V_195 ) &
V_2 -> V_51 . V_196 ;
if ( V_2 -> V_51 . V_52 != V_52 ) {
V_2 -> V_51 . V_52 = V_52 ;
F_135 ( & V_2 -> V_51 . V_166 ) ;
}
}
static void F_136 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_8 * V_197 = & V_9 -> V_198 ;
struct V_199 * V_200 = & V_2 -> V_51 ;
if ( F_137 ( & V_2 -> V_51 . V_201 ) )
return;
F_138 ( & V_2 -> V_51 . V_201 ) ;
F_139 ( V_9 ) ;
if ( F_140 ( V_197 ) )
F_141 ( V_197 ) ;
if ( F_48 ( V_2 ) )
V_200 -> V_202 = V_200 -> V_203 ;
}
static bool F_142 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_1 V_67 = F_19 ( V_2 , V_195 ) ;
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
void F_143 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_6 V_204 , V_205 ;
if ( ! F_51 ( V_9 ) )
return;
if ( V_2 -> V_51 . V_202 == 0 )
return;
if ( ! F_142 ( V_9 ) )
return;
V_205 = V_2 -> V_51 . V_202 ;
V_2 -> V_51 . V_202 = 0 ;
V_204 = V_75 -> V_206 ( V_9 , F_144 () ) ;
F_145 ( V_9 -> V_110 , V_204 - V_205 ) ;
if ( V_204 < V_205 )
F_146 ( V_205 - V_204 ) ;
}
static void F_147 ( struct V_1 * V_2 )
{
T_4 V_207 ;
F_148 ( & V_2 -> V_51 . V_201 , 0 ) ;
if ( F_47 ( V_2 ) || F_46 ( V_2 ) ) {
V_207 = V_2 -> V_51 . V_166 . V_208 -> V_209 () ;
V_2 -> V_51 . V_165 = ( T_6 ) F_19 ( V_2 , V_164 )
* V_167 * V_2 -> V_168 ;
if ( ! V_2 -> V_51 . V_165 )
return;
if ( F_47 ( V_2 ) ) {
T_5 V_210 = V_211 * 1000LL ;
if ( V_2 -> V_51 . V_165 < V_210 ) {
F_149 (
L_22
L_23 ,
V_2 -> V_9 -> V_110 ,
V_2 -> V_51 . V_165 , V_210 ) ;
V_2 -> V_51 . V_165 = V_210 ;
}
}
F_150 ( & V_2 -> V_51 . V_166 ,
F_151 ( V_207 , V_2 -> V_51 . V_165 ) ,
V_212 ) ;
F_81 ( L_24 V_213 L_25
V_214 L_26
L_27
L_28 V_214 L_29 , V_215 ,
V_167 , F_119 ( V_207 ) ,
F_19 ( V_2 , V_164 ) ,
V_2 -> V_51 . V_165 ,
F_119 ( F_151 ( V_207 ,
V_2 -> V_51 . V_165 ) ) ) ;
} else if ( F_48 ( V_2 ) ) {
T_6 V_204 , V_203 = V_2 -> V_51 . V_203 ;
T_6 V_162 = 0 ;
T_4 V_216 ;
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned long V_217 = V_9 -> V_11 . V_218 ;
unsigned long V_219 ;
if ( F_64 ( ! V_203 || ! V_217 ) )
return;
F_152 ( V_219 ) ;
V_207 = V_2 -> V_51 . V_166 . V_208 -> V_209 () ;
V_204 = V_75 -> V_206 ( V_9 , F_144 () ) ;
if ( F_70 ( V_203 > V_204 ) ) {
V_162 = ( V_203 - V_204 ) * 1000000ULL ;
F_153 ( V_162 , V_217 ) ;
V_216 = F_151 ( V_207 , V_162 ) ;
V_216 = F_154 ( V_216 , V_220 ) ;
F_150 ( & V_2 -> V_51 . V_166 ,
V_216 , V_212 ) ;
} else
F_136 ( V_2 ) ;
F_155 ( V_219 ) ;
}
}
static void F_156 ( struct V_1 * V_2 , T_1 V_221 )
{
bool V_222 = F_49 ( V_221 ) ;
if ( V_2 -> V_222 != V_222 ) {
V_2 -> V_222 = V_222 ;
if ( V_222 ) {
F_81 ( L_30
L_31 , V_2 -> V_9 -> V_110 ) ;
F_138 ( & V_2 -> V_9 -> V_25 -> V_11 . V_223 ) ;
} else
F_157 ( & V_2 -> V_9 -> V_25 -> V_11 . V_223 ) ;
}
}
static int F_158 ( struct V_1 * V_2 , T_1 V_67 , T_1 V_4 )
{
int V_126 = 0 ;
F_159 ( V_67 , V_4 ) ;
switch ( V_67 ) {
case V_14 :
if ( ! F_29 ( V_2 ) )
F_41 ( V_2 , V_4 >> 24 ) ;
else
V_126 = 1 ;
break;
case V_104 :
F_125 ( V_2 , true ) ;
F_88 ( V_2 , V_4 & 0xff ) ;
break;
case V_224 :
F_111 ( V_2 ) ;
break;
case V_34 :
if ( ! F_29 ( V_2 ) )
F_42 ( V_2 , V_4 & V_225 ) ;
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
T_1 V_226 = 0x3ff ;
if ( F_19 ( V_2 , V_66 ) & V_65 )
V_226 |= V_227 ;
F_38 ( V_2 , V_4 & V_226 ) ;
if ( ! ( V_4 & V_42 ) ) {
int V_28 ;
T_1 V_56 ;
for ( V_28 = 0 ; V_28 < V_228 ; V_28 ++ ) {
V_56 = F_19 ( V_2 ,
V_195 + 0x10 * V_28 ) ;
F_1 ( V_2 , V_195 + 0x10 * V_28 ,
V_56 | V_49 ) ;
}
F_134 ( V_2 ) ;
F_148 ( & V_2 -> V_51 . V_201 , 0 ) ;
}
break;
}
case V_153 :
F_1 ( V_2 , V_153 , V_4 & ~ ( 1 << 12 ) ) ;
F_114 ( V_2 ) ;
break;
case V_155 :
if ( ! F_29 ( V_2 ) )
V_4 &= 0xff000000 ;
F_1 ( V_2 , V_155 , V_4 ) ;
break;
case V_229 :
F_156 ( V_2 , V_4 ) ;
case V_230 :
case V_231 :
case V_232 :
case V_233 :
if ( ! F_16 ( V_2 ) )
V_4 |= V_49 ;
V_4 &= V_234 [ ( V_67 - V_195 ) >> 4 ] ;
F_1 ( V_2 , V_67 , V_4 ) ;
break;
case V_195 :
if ( ! F_16 ( V_2 ) )
V_4 |= V_49 ;
V_4 &= ( V_234 [ 0 ] | V_2 -> V_51 . V_196 ) ;
F_1 ( V_2 , V_195 , V_4 ) ;
F_134 ( V_2 ) ;
break;
case V_164 :
if ( F_48 ( V_2 ) )
break;
F_135 ( & V_2 -> V_51 . V_166 ) ;
F_1 ( V_2 , V_164 , V_4 ) ;
F_147 ( V_2 ) ;
break;
case V_194 :
if ( V_4 & 4 )
F_81 ( L_32 , V_4 ) ;
F_1 ( V_2 , V_194 , V_4 ) ;
F_133 ( V_2 ) ;
break;
case V_235 :
if ( F_29 ( V_2 ) && V_4 != 0 ) {
F_81 ( L_33 , V_4 ) ;
V_126 = 1 ;
}
break;
case V_236 :
if ( F_29 ( V_2 ) ) {
F_158 ( V_2 , V_153 , 0x40000 | ( V_4 & 0xff ) ) ;
} else
V_126 = 1 ;
break;
default:
V_126 = 1 ;
break;
}
if ( V_126 )
F_81 ( L_34 , V_67 ) ;
return V_126 ;
}
static int F_160 ( struct V_8 * V_9 , struct V_181 * V_188 ,
T_7 V_189 , int V_183 , const void * V_89 )
{
struct V_1 * V_2 = F_127 ( V_188 ) ;
unsigned int V_177 = V_189 - V_2 -> V_187 ;
T_1 V_4 ;
if ( ! F_131 ( V_2 , V_189 ) )
return - V_190 ;
if ( V_183 != 4 || ( V_177 & 0xf ) ) {
F_81 ( L_35 , V_183 , ( long ) V_189 ) ;
return 0 ;
}
V_4 = * ( T_1 * ) V_89 ;
if ( V_177 != V_224 )
F_81 ( L_36
L_37 , V_215 , V_177 , V_183 , V_4 ) ;
F_158 ( V_2 , V_177 & 0xff0 , V_4 ) ;
return 0 ;
}
void F_161 ( struct V_8 * V_9 )
{
if ( F_51 ( V_9 ) )
F_158 ( V_9 -> V_11 . V_2 , V_224 , 0 ) ;
}
void F_162 ( struct V_8 * V_9 , T_1 V_177 )
{
T_1 V_4 = 0 ;
V_177 &= 0xff0 ;
F_129 ( V_9 -> V_11 . V_2 , V_177 , 4 , & V_4 ) ;
F_158 ( V_9 -> V_11 . V_2 , V_177 , V_4 ) ;
}
void F_163 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! V_9 -> V_11 . V_2 )
return;
F_135 ( & V_2 -> V_51 . V_166 ) ;
if ( ! ( V_9 -> V_11 . V_237 & V_238 ) )
F_39 ( & V_239 ) ;
if ( ! V_2 -> V_44 )
F_39 ( & V_45 ) ;
if ( V_2 -> V_5 )
F_164 ( ( unsigned long ) V_2 -> V_5 ) ;
F_165 ( V_2 ) ;
}
T_6 F_166 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_51 ( V_9 ) || F_46 ( V_2 ) ||
F_47 ( V_2 ) )
return 0 ;
return V_2 -> V_51 . V_203 ;
}
void F_167 ( struct V_8 * V_9 , T_6 V_89 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_51 ( V_9 ) || F_46 ( V_2 ) ||
F_47 ( V_2 ) )
return;
F_135 ( & V_2 -> V_51 . V_166 ) ;
V_2 -> V_51 . V_203 = V_89 ;
F_147 ( V_2 ) ;
}
void F_168 ( struct V_8 * V_9 , unsigned long V_240 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_51 ( V_9 ) )
return;
F_88 ( V_2 , ( ( V_240 & 0x0f ) << 4 )
| ( F_19 ( V_2 , V_104 ) & 4 ) ) ;
}
T_6 F_169 ( struct V_8 * V_9 )
{
T_6 V_98 ;
if ( ! F_51 ( V_9 ) )
return 0 ;
V_98 = ( T_6 ) F_19 ( V_9 -> V_11 . V_2 , V_104 ) ;
return ( V_98 & 0xf0 ) >> 4 ;
}
void F_170 ( struct V_8 * V_9 , T_6 V_241 )
{
T_6 V_242 = V_9 -> V_11 . V_237 ;
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! V_2 ) {
V_241 |= V_243 ;
V_9 -> V_11 . V_237 = V_241 ;
return;
}
V_9 -> V_11 . V_237 = V_241 ;
if ( ( V_242 ^ V_241 ) & V_238 ) {
if ( V_241 & V_238 )
F_39 ( & V_239 ) ;
else
F_40 ( & V_239 . V_46 ) ;
F_23 ( V_9 -> V_25 ) ;
}
if ( ( V_242 ^ V_241 ) & V_244 ) {
if ( V_241 & V_244 ) {
F_43 ( V_2 , V_9 -> V_110 ) ;
V_75 -> V_245 ( V_9 , true ) ;
} else
V_75 -> V_245 ( V_9 , false ) ;
}
V_2 -> V_187 = V_2 -> V_9 -> V_11 . V_237 &
V_246 ;
if ( ( V_241 & V_238 ) &&
V_2 -> V_187 != V_247 )
F_171 ( L_38 ) ;
F_81 ( L_39 V_214 L_40
L_41 , V_2 -> V_9 -> V_11 . V_237 , V_2 -> V_187 ) ;
}
void F_172 ( struct V_8 * V_9 , bool V_248 )
{
struct V_1 * V_2 ;
int V_28 ;
F_81 ( L_42 , V_215 ) ;
ASSERT ( V_9 ) ;
V_2 = V_9 -> V_11 . V_2 ;
ASSERT ( V_2 != NULL ) ;
F_135 ( & V_2 -> V_51 . V_166 ) ;
if ( ! V_248 )
F_41 ( V_2 , V_9 -> V_110 ) ;
F_50 ( V_2 -> V_9 ) ;
for ( V_28 = 0 ; V_28 < V_228 ; V_28 ++ )
F_1 ( V_2 , V_195 + 0x10 * V_28 , V_49 ) ;
F_134 ( V_2 ) ;
if ( F_173 ( V_9 -> V_25 , V_249 ) )
F_1 ( V_2 , V_229 ,
F_174 ( 0 , V_250 ) ) ;
F_156 ( V_2 , F_19 ( V_2 , V_229 ) ) ;
F_1 ( V_2 , V_36 , 0xffffffffU ) ;
F_38 ( V_2 , 0xff ) ;
F_1 ( V_2 , V_104 , 0 ) ;
if ( ! F_29 ( V_2 ) )
F_42 ( V_2 , 0 ) ;
F_1 ( V_2 , V_235 , 0 ) ;
F_1 ( V_2 , V_153 , 0 ) ;
F_1 ( V_2 , V_155 , 0 ) ;
F_1 ( V_2 , V_194 , 0 ) ;
F_1 ( V_2 , V_164 , 0 ) ;
for ( V_28 = 0 ; V_28 < 8 ; V_28 ++ ) {
F_1 ( V_2 , V_13 + 0x10 * V_28 , 0 ) ;
F_1 ( V_2 , V_12 + 0x10 * V_28 , 0 ) ;
F_1 ( V_2 , V_97 + 0x10 * V_28 , 0 ) ;
}
V_2 -> V_73 = F_65 ( V_9 -> V_25 ) ;
V_2 -> V_79 = V_75 -> V_78 ? 1 : 0 ;
V_2 -> V_80 = - 1 ;
F_133 ( V_2 ) ;
F_148 ( & V_2 -> V_51 . V_201 , 0 ) ;
if ( F_175 ( V_9 ) )
F_170 ( V_9 ,
V_9 -> V_11 . V_237 | V_243 ) ;
V_9 -> V_11 . V_88 . V_90 = 0 ;
F_87 ( V_2 ) ;
V_9 -> V_11 . V_131 = 0 ;
V_9 -> V_11 . V_94 = 0 ;
F_81 ( L_43
L_44 V_214 L_45 , V_215 ,
V_9 , F_18 ( V_2 ) ,
V_9 -> V_11 . V_237 , V_2 -> V_187 ) ;
}
static bool F_176 ( struct V_1 * V_2 )
{
return F_47 ( V_2 ) ;
}
int F_177 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( F_51 ( V_9 ) && F_15 ( V_2 ) &&
F_44 ( V_2 , V_195 ) )
return F_137 ( & V_2 -> V_51 . V_201 ) ;
return 0 ;
}
int F_178 ( struct V_1 * V_2 , int V_48 )
{
T_1 V_67 = F_19 ( V_2 , V_48 ) ;
int V_10 , V_17 , V_87 ;
if ( F_17 ( V_2 ) && ! ( V_67 & V_49 ) ) {
V_10 = V_67 & V_50 ;
V_17 = V_67 & V_57 ;
V_87 = V_67 & V_251 ;
return F_74 ( V_2 , V_17 , V_10 , 1 , V_87 ,
NULL ) ;
}
return 0 ;
}
void F_179 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( V_2 )
F_178 ( V_2 , V_229 ) ;
}
static enum V_252 F_180 ( struct V_253 * V_89 )
{
struct V_199 * V_200 = F_128 ( V_89 , struct V_199 , V_166 ) ;
struct V_1 * V_2 = F_128 ( V_200 , struct V_1 , V_51 ) ;
F_136 ( V_2 ) ;
if ( F_176 ( V_2 ) ) {
F_181 ( & V_200 -> V_166 , V_200 -> V_165 ) ;
return V_254 ;
} else
return V_255 ;
}
int F_182 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
ASSERT ( V_9 != NULL ) ;
F_81 ( L_46 , V_9 -> V_110 ) ;
V_2 = F_24 ( sizeof( * V_2 ) , V_29 ) ;
if ( ! V_2 )
goto V_256;
V_9 -> V_11 . V_2 = V_2 ;
V_2 -> V_5 = ( void * ) F_183 ( V_29 ) ;
if ( ! V_2 -> V_5 ) {
F_107 ( V_146 L_47 ,
V_9 -> V_110 ) ;
goto V_257;
}
V_2 -> V_9 = V_9 ;
F_184 ( & V_2 -> V_51 . V_166 , V_258 ,
V_212 ) ;
V_2 -> V_51 . V_166 . V_259 = F_180 ;
V_9 -> V_11 . V_237 = V_238 ;
F_170 ( V_9 ,
V_247 | V_238 ) ;
F_40 ( & V_45 . V_46 ) ;
F_172 ( V_9 , false ) ;
F_185 ( & V_2 -> V_182 , & V_260 ) ;
return 0 ;
V_257:
F_165 ( V_2 ) ;
V_256:
return - V_261 ;
}
int F_186 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
int V_81 ;
if ( ! F_51 ( V_9 ) || ! F_15 ( V_2 ) )
return - 1 ;
F_87 ( V_2 ) ;
V_81 = F_62 ( V_2 ) ;
if ( ( V_81 == - 1 ) ||
( ( V_81 & 0xF0 ) <= F_19 ( V_2 , V_103 ) ) )
return - 1 ;
return V_81 ;
}
int F_187 ( struct V_8 * V_9 )
{
T_1 V_262 = F_19 ( V_9 -> V_11 . V_2 , V_229 ) ;
int V_124 = 0 ;
if ( ! F_17 ( V_9 -> V_11 . V_2 ) )
V_124 = 1 ;
if ( ( V_262 & V_49 ) == 0 &&
F_188 ( V_262 ) == V_250 )
V_124 = 1 ;
return V_124 ;
}
void F_189 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_51 ( V_9 ) )
return;
if ( F_137 ( & V_2 -> V_51 . V_201 ) > 0 ) {
F_178 ( V_2 , V_195 ) ;
if ( F_48 ( V_2 ) )
V_2 -> V_51 . V_203 = 0 ;
F_148 ( & V_2 -> V_51 . V_201 , 0 ) ;
}
}
int F_190 ( struct V_8 * V_9 )
{
int V_10 = F_186 ( V_9 ) ;
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( V_10 == - 1 )
return - 1 ;
F_67 ( V_10 , V_2 ) ;
F_87 ( V_2 ) ;
F_63 ( V_10 , V_2 ) ;
return V_10 ;
}
void F_191 ( struct V_8 * V_9 ,
struct V_263 * V_264 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
F_170 ( V_9 , V_9 -> V_11 . V_237 ) ;
F_38 ( V_2 , * ( ( T_1 * ) ( V_264 -> V_5 + V_43 ) ) ) ;
memcpy ( V_9 -> V_11 . V_2 -> V_5 , V_264 -> V_5 , sizeof *V_264 ) ;
F_41 ( V_2 , F_18 ( V_2 ) ) ;
F_50 ( V_9 ) ;
F_87 ( V_2 ) ;
F_135 ( & V_2 -> V_51 . V_166 ) ;
F_134 ( V_2 ) ;
F_156 ( V_2 , F_19 ( V_2 , V_229 ) ) ;
F_133 ( V_2 ) ;
F_147 ( V_2 ) ;
V_2 -> V_73 = true ;
V_2 -> V_79 = V_75 -> V_78 ?
1 : F_55 ( V_2 -> V_5 + V_12 ) ;
V_2 -> V_80 = - 1 ;
if ( V_75 -> V_265 )
V_75 -> V_265 ( V_9 ,
F_62 ( V_2 ) ) ;
if ( F_64 ( V_75 -> V_78 ) )
V_75 -> V_78 ( V_9 -> V_25 ,
F_69 ( V_2 ) ) ;
F_66 ( V_77 , V_9 ) ;
F_192 ( V_9 ) ;
}
void F_193 ( struct V_8 * V_9 )
{
struct V_253 * V_166 ;
if ( ! F_51 ( V_9 ) )
return;
V_166 = & V_9 -> V_11 . V_2 -> V_51 . V_166 ;
if ( F_135 ( V_166 ) )
F_194 ( V_166 , V_212 ) ;
}
static void F_195 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
bool V_201 ;
int V_10 ;
F_68 ( ! F_79 ( V_9 ) ) ;
V_201 = F_80 ( V_9 ) ;
F_84 ( V_9 ) ;
if ( V_201 )
return;
V_10 = F_111 ( V_2 ) ;
F_196 ( V_2 , V_10 ) ;
}
void F_197 ( struct V_8 * V_9 )
{
T_1 V_89 ;
if ( F_3 ( V_93 , & V_9 -> V_11 . V_94 ) )
F_195 ( V_9 , V_9 -> V_11 . V_2 ) ;
if ( ! F_3 ( V_266 , & V_9 -> V_11 . V_94 ) )
return;
F_78 ( V_9 -> V_25 , & V_9 -> V_11 . V_2 -> V_267 , & V_89 ,
sizeof( T_1 ) ) ;
F_88 ( V_9 -> V_11 . V_2 , V_89 & 0xff ) ;
}
static void F_198 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
if ( ! F_79 ( V_9 ) ||
V_2 -> V_73 ||
V_2 -> V_80 == - 1 ||
F_109 ( V_9 -> V_25 , V_2 -> V_80 ) ) {
return;
}
F_82 ( V_2 -> V_9 ) ;
}
void F_199 ( struct V_8 * V_9 )
{
T_1 V_89 , V_98 ;
int V_268 , V_269 ;
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
F_198 ( V_9 , V_2 ) ;
if ( ! F_3 ( V_266 , & V_9 -> V_11 . V_94 ) )
return;
V_98 = F_19 ( V_2 , V_104 ) & 0xff ;
V_268 = F_62 ( V_2 ) ;
if ( V_268 < 0 )
V_268 = 0 ;
V_269 = F_69 ( V_2 ) ;
if ( V_269 < 0 )
V_269 = 0 ;
V_89 = ( V_98 & 0xff ) | ( ( V_269 & 0xf0 ) << 8 ) | ( V_268 << 24 ) ;
F_76 ( V_9 -> V_25 , & V_9 -> V_11 . V_2 -> V_267 , & V_89 ,
sizeof( T_1 ) ) ;
}
int F_200 ( struct V_8 * V_9 , T_7 V_270 )
{
if ( V_270 ) {
if ( F_201 ( V_9 -> V_25 ,
& V_9 -> V_11 . V_2 -> V_267 ,
V_270 , sizeof( T_1 ) ) )
return - V_271 ;
F_83 ( V_266 , & V_9 -> V_11 . V_94 ) ;
} else {
F_85 ( V_266 , & V_9 -> V_11 . V_94 ) ;
}
V_9 -> V_11 . V_2 -> V_270 = V_270 ;
return 0 ;
}
int F_202 ( struct V_8 * V_9 , T_1 V_272 , T_6 V_89 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_1 V_67 = ( V_272 - V_273 ) << 4 ;
if ( ! F_203 ( V_9 -> V_25 ) || ! F_29 ( V_2 ) )
return 1 ;
if ( V_67 == V_155 )
return 1 ;
if ( V_67 == V_153 )
F_158 ( V_2 , V_155 , ( T_1 ) ( V_89 >> 32 ) ) ;
return F_158 ( V_2 , V_67 , ( T_1 ) V_89 ) ;
}
int F_204 ( struct V_8 * V_9 , T_1 V_272 , T_6 * V_89 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_1 V_67 = ( V_272 - V_273 ) << 4 , V_274 , V_275 = 0 ;
if ( ! F_203 ( V_9 -> V_25 ) || ! F_29 ( V_2 ) )
return 1 ;
if ( V_67 == V_36 || V_67 == V_155 ) {
F_81 ( L_48 ,
V_67 ) ;
return 1 ;
}
if ( F_129 ( V_2 , V_67 , 4 , & V_274 ) )
return 1 ;
if ( V_67 == V_153 )
F_129 ( V_2 , V_155 , 4 , & V_275 ) ;
* V_89 = ( ( ( T_6 ) V_275 ) << 32 ) | V_274 ;
return 0 ;
}
int F_205 ( struct V_8 * V_9 , T_1 V_67 , T_6 V_89 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
if ( ! F_51 ( V_9 ) )
return 1 ;
if ( V_67 == V_153 )
F_158 ( V_2 , V_155 , ( T_1 ) ( V_89 >> 32 ) ) ;
return F_158 ( V_2 , V_67 , ( T_1 ) V_89 ) ;
}
int F_206 ( struct V_8 * V_9 , T_1 V_67 , T_6 * V_89 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_1 V_274 , V_275 = 0 ;
if ( ! F_51 ( V_9 ) )
return 1 ;
if ( F_129 ( V_2 , V_67 , 4 , & V_274 ) )
return 1 ;
if ( V_67 == V_153 )
F_129 ( V_2 , V_155 , 4 , & V_275 ) ;
* V_89 = ( ( ( T_6 ) V_275 ) << 32 ) | V_274 ;
return 0 ;
}
int F_207 ( struct V_8 * V_9 , T_6 V_89 )
{
T_6 V_186 = V_89 & ~ V_91 ;
if ( ! F_208 ( V_186 , 4 ) )
return 1 ;
V_9 -> V_11 . V_88 . V_90 = V_89 ;
if ( ! F_79 ( V_9 ) )
return 0 ;
return F_201 ( V_9 -> V_25 , & V_9 -> V_11 . V_88 . V_89 ,
V_186 , sizeof( T_3 ) ) ;
}
void F_209 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_11 . V_2 ;
T_3 V_143 ;
unsigned long V_276 ;
if ( ! F_51 ( V_9 ) || ! V_2 -> V_140 )
return;
if ( F_210 ( V_9 ) ) {
F_211 ( V_9 -> V_11 . V_277 == V_278 ) ;
if ( F_3 ( V_144 , & V_2 -> V_140 ) )
F_10 ( V_144 , & V_2 -> V_140 ) ;
return;
}
V_276 = F_58 ( & V_2 -> V_140 , 0 ) ;
if ( F_3 ( V_141 , & V_276 ) ) {
F_172 ( V_9 , true ) ;
F_212 ( V_9 , true ) ;
if ( F_175 ( V_2 -> V_9 ) )
V_9 -> V_11 . V_277 = V_279 ;
else
V_9 -> V_11 . V_277 = V_278 ;
}
if ( F_3 ( V_144 , & V_276 ) &&
V_9 -> V_11 . V_277 == V_278 ) {
F_213 () ;
V_143 = V_2 -> V_143 ;
F_81 ( L_49 ,
V_9 -> V_110 , V_143 ) ;
F_214 ( V_9 , V_143 ) ;
V_9 -> V_11 . V_277 = V_279 ;
}
}
void F_215 ( void )
{
F_216 ( & V_239 , V_280 ) ;
F_216 ( & V_45 , V_280 ) ;
}
