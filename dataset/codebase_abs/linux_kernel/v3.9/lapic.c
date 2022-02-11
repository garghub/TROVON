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
static inline void F_10 ( int V_6 , void * V_7 )
{
F_11 ( F_4 ( V_6 ) , ( V_7 ) + F_5 ( V_6 ) ) ;
}
static inline void F_12 ( int V_6 , void * V_7 )
{
F_13 ( F_4 ( V_6 ) , ( V_7 ) + F_5 ( V_6 ) ) ;
}
static inline int F_14 ( int V_6 , void * V_7 )
{
return F_15 ( F_4 ( V_6 ) , ( V_7 ) + F_5 ( V_6 ) ) ;
}
static inline int F_16 ( int V_6 , void * V_7 )
{
return F_17 ( F_4 ( V_6 ) , ( V_7 ) + F_5 ( V_6 ) ) ;
}
static inline void F_18 ( struct V_1 * V_2 , T_1 V_4 )
{
if ( ( F_19 ( V_2 , V_8 ) ^ V_4 ) & V_9 ) {
if ( V_4 & V_9 )
F_20 ( & V_10 ) ;
else
F_21 ( & V_10 . V_11 ) ;
}
F_1 ( V_2 , V_8 , V_4 ) ;
}
static inline int F_22 ( struct V_1 * V_2 )
{
return F_23 ( V_2 ) && F_24 ( V_2 ) ;
}
static inline int F_25 ( struct V_1 * V_2 )
{
return ( F_19 ( V_2 , V_12 ) >> 24 ) & 0xff ;
}
void F_26 ( struct V_13 * V_14 ,
struct V_15 * V_16 ,
T_2 * V_17 )
{
struct V_1 * * V_18 ;
struct V_19 * V_20 ;
unsigned long V_7 = 1 ;
int V_21 ;
F_27 () ;
V_20 = F_28 ( V_14 -> V_22 -> V_23 . V_24 ) ;
if ( F_29 ( ! V_20 ) ) {
F_30 ( V_16 -> V_25 , ( unsigned long * ) V_17 ) ;
goto V_26;
}
if ( V_16 -> V_27 == 0 ) {
if ( V_16 -> V_28 == V_29 ||
V_16 -> V_30 == 0xff ) {
F_30 ( V_16 -> V_25 ,
( unsigned long * ) V_17 ) ;
goto V_26;
}
V_18 = & V_20 -> V_31 [ V_16 -> V_30 & 0xff ] ;
} else {
T_1 V_32 = V_16 -> V_30 << ( 32 - V_20 -> V_33 ) ;
V_18 = V_20 -> V_34 [ F_31 ( V_20 , V_32 ) ] ;
V_7 = F_32 ( V_20 , V_32 ) ;
}
F_33 (i, &bitmap, 16 ) {
if ( ! V_18 [ V_21 ] )
continue;
if ( V_18 [ V_21 ] -> V_14 == V_14 ) {
F_30 ( V_16 -> V_25 ,
( unsigned long * ) V_17 ) ;
break;
}
}
V_26:
F_34 () ;
}
static void F_35 ( struct V_22 * V_22 )
{
struct V_19 * V_35 , * V_36 = NULL ;
struct V_13 * V_14 ;
int V_21 ;
V_35 = F_36 ( sizeof( struct V_19 ) , V_37 ) ;
F_37 ( & V_22 -> V_23 . V_38 ) ;
if ( ! V_35 )
goto V_26;
V_35 -> V_33 = 8 ;
V_35 -> V_39 = 8 ;
V_35 -> V_40 = 0 ;
V_35 -> V_41 = 0xff ;
F_38 (i, vcpu, kvm) {
struct V_1 * V_2 = V_14 -> V_23 . V_2 ;
T_3 V_42 , V_43 ;
T_1 V_44 ;
if ( ! F_39 ( V_14 ) )
continue;
if ( F_40 ( V_2 ) ) {
V_35 -> V_33 = 32 ;
V_35 -> V_39 = 16 ;
V_35 -> V_40 = V_35 -> V_41 = 0xffff ;
} else if ( F_23 ( V_2 ) &&
! V_35 -> V_40 &&
F_19 ( V_2 , V_45 ) == V_46 ) {
V_35 -> V_39 = 4 ;
V_35 -> V_40 = 0xf ;
V_35 -> V_41 = 0xf ;
}
V_35 -> V_31 [ F_25 ( V_2 ) ] = V_2 ;
V_44 = F_19 ( V_2 , V_47 ) ;
V_42 = F_31 ( V_35 , V_44 ) ;
V_43 = F_32 ( V_35 , V_44 ) ;
if ( V_43 )
V_35 -> V_34 [ V_42 ] [ F_41 ( V_43 ) - 1 ] = V_2 ;
}
V_26:
V_36 = F_42 ( V_22 -> V_23 . V_24 ,
F_43 ( & V_22 -> V_23 . V_38 ) ) ;
F_44 ( V_22 -> V_23 . V_24 , V_35 ) ;
F_45 ( & V_22 -> V_23 . V_38 ) ;
if ( V_36 )
F_46 ( V_36 , V_48 ) ;
F_47 ( V_22 ) ;
}
static inline void F_48 ( struct V_1 * V_2 , T_4 V_49 )
{
F_1 ( V_2 , V_12 , V_49 << 24 ) ;
F_35 ( V_2 -> V_14 -> V_22 ) ;
}
static inline void F_49 ( struct V_1 * V_2 , T_1 V_49 )
{
F_1 ( V_2 , V_47 , V_49 ) ;
F_35 ( V_2 -> V_14 -> V_22 ) ;
}
static inline int F_50 ( struct V_1 * V_2 , int V_50 )
{
return ! ( F_19 ( V_2 , V_50 ) & V_51 ) ;
}
static inline int F_51 ( struct V_1 * V_2 , int V_50 )
{
return F_19 ( V_2 , V_50 ) & V_52 ;
}
static inline int F_52 ( struct V_1 * V_2 )
{
return ( ( F_19 ( V_2 , V_53 ) &
V_2 -> V_54 . V_55 ) == V_56 ) ;
}
static inline int F_53 ( struct V_1 * V_2 )
{
return ( ( F_19 ( V_2 , V_53 ) &
V_2 -> V_54 . V_55 ) == V_57 ) ;
}
static inline int F_54 ( struct V_1 * V_2 )
{
return ( ( F_19 ( V_2 , V_53 ) &
V_2 -> V_54 . V_55 ) ==
V_58 ) ;
}
static inline int F_55 ( T_1 V_59 )
{
return ( V_59 & ( V_60 | V_51 ) ) == V_61 ;
}
void F_56 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_23 . V_2 ;
struct V_62 * V_63 ;
T_1 V_64 = V_65 ;
if ( ! F_57 ( V_14 ) )
return;
V_63 = F_58 ( V_2 -> V_14 , 0x1 , 0 ) ;
if ( V_63 && ( V_63 -> V_66 & ( 1 << ( V_67 & 31 ) ) ) )
V_64 |= V_68 ;
F_1 ( V_2 , V_69 , V_64 ) ;
}
static int F_59 ( void * V_7 )
{
int V_6 ;
T_1 * V_70 ;
for ( V_6 = V_71 - V_72 ;
V_6 >= 0 ; V_6 -= V_72 ) {
V_70 = V_7 + F_5 ( V_6 ) ;
if ( * V_70 )
return F_60 ( * V_70 ) - 1 + V_6 ;
}
return - 1 ;
}
static T_4 F_61 ( void * V_7 )
{
int V_6 ;
T_1 * V_70 ;
T_4 V_73 = 0 ;
for ( V_6 = 0 ; V_6 < V_71 ; V_6 += V_72 ) {
V_70 = V_7 + F_5 ( V_6 ) ;
V_73 += F_62 ( * V_70 ) ;
}
return V_73 ;
}
static inline int F_63 ( int V_6 , struct V_1 * V_2 )
{
V_2 -> V_74 = true ;
return F_2 ( V_6 , V_2 -> V_5 + V_75 ) ;
}
static inline int F_64 ( struct V_1 * V_2 )
{
return F_59 ( V_2 -> V_5 + V_75 ) ;
}
static inline int F_65 ( struct V_1 * V_2 )
{
int V_76 ;
if ( ! V_2 -> V_74 )
return - 1 ;
V_76 = F_64 ( V_2 ) ;
ASSERT ( V_76 == - 1 || V_76 >= 16 ) ;
return V_76 ;
}
static inline void F_66 ( int V_6 , struct V_1 * V_2 )
{
V_2 -> V_74 = false ;
F_12 ( V_6 , V_2 -> V_5 + V_75 ) ;
if ( F_64 ( V_2 ) != - 1 )
V_2 -> V_74 = true ;
}
static inline void F_67 ( int V_6 , struct V_1 * V_2 )
{
if ( ! F_14 ( V_6 , V_2 -> V_5 + V_77 ) )
++ V_2 -> V_78 ;
F_68 ( V_2 -> V_78 > V_71 ) ;
V_2 -> V_79 = V_6 ;
}
static inline void F_69 ( int V_6 , struct V_1 * V_2 )
{
if ( F_16 ( V_6 , V_2 -> V_5 + V_77 ) )
-- V_2 -> V_78 ;
F_68 ( V_2 -> V_78 < 0 ) ;
V_2 -> V_79 = - 1 ;
}
int F_70 ( struct V_13 * V_14 )
{
int V_80 ;
if ( ! F_57 ( V_14 ) )
return 0 ;
V_80 = F_65 ( V_14 -> V_23 . V_2 ) ;
return V_80 ;
}
int F_71 ( struct V_13 * V_14 , struct V_15 * V_16 )
{
struct V_1 * V_2 = V_14 -> V_23 . V_2 ;
return F_72 ( V_2 , V_16 -> V_28 , V_16 -> V_25 ,
V_16 -> V_81 , V_16 -> V_82 ) ;
}
static int F_73 ( struct V_13 * V_14 , T_4 V_4 )
{
return F_74 ( V_14 -> V_22 , & V_14 -> V_23 . V_83 . V_84 , & V_4 ,
sizeof( V_4 ) ) ;
}
static int F_75 ( struct V_13 * V_14 , T_4 * V_4 )
{
return F_76 ( V_14 -> V_22 , & V_14 -> V_23 . V_83 . V_84 , V_4 ,
sizeof( * V_4 ) ) ;
}
static inline bool F_77 ( struct V_13 * V_14 )
{
return V_14 -> V_23 . V_83 . V_85 & V_86 ;
}
static bool F_78 ( struct V_13 * V_14 )
{
T_4 V_4 ;
if ( F_75 ( V_14 , & V_4 ) < 0 )
F_79 ( L_1 ,
( unsigned long long ) V_87 -> V_23 . V_83 . V_85 ) ;
return V_4 & 0x1 ;
}
static void F_80 ( struct V_13 * V_14 )
{
if ( F_73 ( V_14 , V_88 ) < 0 ) {
F_79 ( L_2 ,
( unsigned long long ) V_87 -> V_23 . V_83 . V_85 ) ;
return;
}
F_30 ( V_89 , & V_14 -> V_23 . V_90 ) ;
}
static void F_81 ( struct V_13 * V_14 )
{
if ( F_73 ( V_14 , V_91 ) < 0 ) {
F_79 ( L_3 ,
( unsigned long long ) V_87 -> V_23 . V_83 . V_85 ) ;
return;
}
F_82 ( V_89 , & V_14 -> V_23 . V_90 ) ;
}
static inline int F_83 ( struct V_1 * V_2 )
{
int V_76 ;
if ( ! V_2 -> V_78 )
return - 1 ;
if ( F_84 ( V_2 -> V_79 != - 1 ) )
return V_2 -> V_79 ;
V_76 = F_59 ( V_2 -> V_5 + V_77 ) ;
ASSERT ( V_76 == - 1 || V_76 >= 16 ) ;
return V_76 ;
}
static void F_85 ( struct V_1 * V_2 )
{
T_1 V_92 , V_93 , V_94 , V_95 ;
int V_96 ;
V_95 = F_19 ( V_2 , V_97 ) ;
V_92 = F_19 ( V_2 , V_98 ) ;
V_96 = F_83 ( V_2 ) ;
V_93 = ( V_96 != - 1 ) ? V_96 : 0 ;
if ( ( V_92 & 0xf0 ) >= ( V_93 & 0xf0 ) )
V_94 = V_92 & 0xff ;
else
V_94 = V_93 & 0xf0 ;
F_79 ( L_4 ,
V_2 , V_94 , V_96 , V_93 ) ;
if ( V_95 != V_94 ) {
F_1 ( V_2 , V_97 , V_94 ) ;
if ( V_94 < V_95 )
F_86 ( V_99 , V_2 -> V_14 ) ;
}
}
static void F_87 ( struct V_1 * V_2 , T_1 V_92 )
{
F_1 ( V_2 , V_98 , V_92 ) ;
F_85 ( V_2 ) ;
}
int F_88 ( struct V_1 * V_2 , T_3 V_100 )
{
return V_100 == 0xff || F_25 ( V_2 ) == V_100 ;
}
int F_89 ( struct V_1 * V_2 , T_4 V_32 )
{
int V_76 = 0 ;
T_1 V_101 ;
if ( F_40 ( V_2 ) ) {
V_101 = F_19 ( V_2 , V_47 ) ;
return V_101 & V_32 ;
}
V_101 = F_90 ( F_19 ( V_2 , V_47 ) ) ;
switch ( F_19 ( V_2 , V_45 ) ) {
case V_102 :
if ( V_101 & V_32 )
V_76 = 1 ;
break;
case V_46 :
if ( ( ( V_101 >> 4 ) == ( V_32 >> 0x4 ) )
&& ( V_101 & V_32 & 0xf ) )
V_76 = 1 ;
break;
default:
F_79 ( L_5 ,
V_2 -> V_14 -> V_103 , F_19 ( V_2 , V_45 ) ) ;
break;
}
return V_76 ;
}
int F_91 ( struct V_13 * V_14 , struct V_1 * V_104 ,
int V_105 , int V_100 , int V_27 )
{
int V_76 = 0 ;
struct V_1 * V_106 = V_14 -> V_23 . V_2 ;
F_79 ( L_6
L_7 ,
V_106 , V_104 , V_100 , V_27 , V_105 ) ;
ASSERT ( V_106 ) ;
switch ( V_105 ) {
case V_107 :
if ( V_27 == 0 )
V_76 = F_88 ( V_106 , V_100 ) ;
else
V_76 = F_89 ( V_106 , V_100 ) ;
break;
case V_108 :
V_76 = ( V_106 == V_104 ) ;
break;
case V_109 :
V_76 = 1 ;
break;
case V_110 :
V_76 = ( V_106 != V_104 ) ;
break;
default:
F_79 ( L_8 ,
V_105 ) ;
break;
}
return V_76 ;
}
bool F_92 ( struct V_22 * V_22 , struct V_1 * V_111 ,
struct V_15 * V_16 , int * V_112 )
{
struct V_19 * V_20 ;
unsigned long V_7 = 1 ;
struct V_1 * * V_18 ;
int V_21 ;
bool V_113 = false ;
* V_112 = - 1 ;
if ( V_16 -> V_114 == V_108 ) {
* V_112 = F_71 ( V_111 -> V_14 , V_16 ) ;
return true ;
}
if ( V_16 -> V_114 )
return false ;
F_27 () ;
V_20 = F_28 ( V_22 -> V_23 . V_24 ) ;
if ( ! V_20 )
goto V_26;
if ( V_16 -> V_27 == 0 ) {
if ( V_16 -> V_28 == V_29 ||
V_16 -> V_30 == 0xff )
goto V_26;
V_18 = & V_20 -> V_31 [ V_16 -> V_30 & 0xff ] ;
} else {
T_1 V_32 = V_16 -> V_30 << ( 32 - V_20 -> V_33 ) ;
V_18 = V_20 -> V_34 [ F_31 ( V_20 , V_32 ) ] ;
V_7 = F_32 ( V_20 , V_32 ) ;
if ( V_16 -> V_28 == V_29 ) {
int V_115 = - 1 ;
F_33 (i, &bitmap, 16 ) {
if ( ! V_18 [ V_21 ] )
continue;
if ( V_115 < 0 )
V_115 = V_21 ;
else if ( F_93 ( V_18 [ V_21 ] -> V_14 , V_18 [ V_115 ] -> V_14 ) < 0 )
V_115 = V_21 ;
}
V_7 = ( V_115 >= 0 ) ? 1 << V_115 : 0 ;
}
}
F_33 (i, &bitmap, 16 ) {
if ( ! V_18 [ V_21 ] )
continue;
if ( * V_112 < 0 )
* V_112 = 0 ;
* V_112 += F_71 ( V_18 [ V_21 ] -> V_14 , V_16 ) ;
}
V_113 = true ;
V_26:
F_34 () ;
return V_113 ;
}
static int F_72 ( struct V_1 * V_2 , int V_28 ,
int V_25 , int V_81 , int V_82 )
{
int V_76 = 0 ;
struct V_13 * V_14 = V_2 -> V_14 ;
switch ( V_28 ) {
case V_29 :
V_14 -> V_23 . V_116 ++ ;
case V_117 :
if ( F_29 ( ! F_22 ( V_2 ) ) )
break;
if ( V_82 ) {
F_79 ( L_9 , V_25 ) ;
F_10 ( V_25 , V_2 -> V_5 + V_118 ) ;
} else
F_12 ( V_25 , V_2 -> V_5 + V_118 ) ;
V_76 = ! F_63 ( V_25 , V_2 ) ;
F_94 ( V_14 -> V_103 , V_28 ,
V_82 , V_25 , ! V_76 ) ;
if ( ! V_76 ) {
if ( V_82 )
F_79 ( L_10
L_11 , V_25 ) ;
break;
}
F_86 ( V_99 , V_14 ) ;
F_95 ( V_14 ) ;
break;
case V_119 :
F_79 ( L_12 ) ;
break;
case V_120 :
F_79 ( L_13 ) ;
break;
case V_61 :
V_76 = 1 ;
F_96 ( V_14 ) ;
F_95 ( V_14 ) ;
break;
case V_121 :
if ( ! V_82 || V_81 ) {
V_76 = 1 ;
V_14 -> V_23 . V_122 = V_123 ;
F_86 ( V_99 , V_14 ) ;
F_95 ( V_14 ) ;
} else {
F_79 ( L_14 ,
V_14 -> V_103 ) ;
}
break;
case V_124 :
F_79 ( L_15 ,
V_14 -> V_103 , V_25 ) ;
if ( V_14 -> V_23 . V_122 == V_123 ) {
V_76 = 1 ;
V_14 -> V_23 . V_125 = V_25 ;
V_14 -> V_23 . V_122 = V_126 ;
F_86 ( V_99 , V_14 ) ;
F_95 ( V_14 ) ;
}
break;
case V_127 :
break;
default:
F_97 ( V_128 L_16 ,
V_28 ) ;
break;
}
return V_76 ;
}
int F_93 ( struct V_13 * V_129 , struct V_13 * V_130 )
{
return V_129 -> V_23 . V_116 - V_130 -> V_23 . V_116 ;
}
static void F_98 ( struct V_1 * V_2 , int V_25 )
{
if ( ! ( F_19 ( V_2 , V_8 ) & V_131 ) &&
F_99 ( V_2 -> V_14 -> V_22 , V_25 ) ) {
int V_132 ;
if ( F_8 ( V_25 , V_2 -> V_5 + V_118 ) )
V_132 = V_133 ;
else
V_132 = V_134 ;
F_100 ( V_2 -> V_14 -> V_22 , V_25 , V_132 ) ;
}
}
static int F_101 ( struct V_1 * V_2 )
{
int V_25 = F_83 ( V_2 ) ;
F_102 ( V_2 , V_25 ) ;
if ( V_25 == - 1 )
return V_25 ;
F_69 ( V_25 , V_2 ) ;
F_85 ( V_2 ) ;
F_98 ( V_2 , V_25 ) ;
F_86 ( V_99 , V_2 -> V_14 ) ;
return V_25 ;
}
void F_103 ( struct V_13 * V_14 , int V_25 )
{
struct V_1 * V_2 = V_14 -> V_23 . V_2 ;
F_102 ( V_2 , V_25 ) ;
F_98 ( V_2 , V_25 ) ;
F_86 ( V_99 , V_2 -> V_14 ) ;
}
static void F_104 ( struct V_1 * V_2 )
{
T_1 V_135 = F_19 ( V_2 , V_136 ) ;
T_1 V_137 = F_19 ( V_2 , V_138 ) ;
struct V_15 V_16 ;
V_16 . V_25 = V_135 & V_52 ;
V_16 . V_28 = V_135 & V_60 ;
V_16 . V_27 = V_135 & V_139 ;
V_16 . V_81 = V_135 & V_140 ;
V_16 . V_82 = V_135 & V_141 ;
V_16 . V_114 = V_135 & V_142 ;
if ( F_40 ( V_2 ) )
V_16 . V_30 = V_137 ;
else
V_16 . V_30 = F_105 ( V_137 ) ;
F_106 ( V_135 , V_16 . V_30 ) ;
F_79 ( L_17
L_18
L_19 ,
V_137 , V_135 , V_16 . V_114 , V_16 . V_30 ,
V_16 . V_82 , V_16 . V_81 , V_16 . V_27 , V_16 . V_28 ,
V_16 . V_25 ) ;
F_107 ( V_2 -> V_14 -> V_22 , V_2 , & V_16 ) ;
}
static T_1 F_108 ( struct V_1 * V_2 )
{
T_5 V_143 ;
T_6 V_144 ;
T_1 V_145 ;
ASSERT ( V_2 != NULL ) ;
if ( F_19 ( V_2 , V_146 ) == 0 )
return 0 ;
V_143 = F_109 ( & V_2 -> V_54 . V_147 ) ;
if ( F_110 ( V_143 ) < 0 )
V_143 = F_111 ( 0 , 0 ) ;
V_144 = F_112 ( F_110 ( V_143 ) , V_2 -> V_54 . V_148 ) ;
V_145 = F_113 ( V_144 ,
( V_149 * V_2 -> V_150 ) ) ;
return V_145 ;
}
static void F_114 ( struct V_1 * V_2 , bool V_151 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_152 * V_153 = V_14 -> V_153 ;
F_86 ( V_154 , V_14 ) ;
V_153 -> V_155 . V_156 = F_115 ( V_14 ) ;
V_153 -> V_155 . V_157 = V_151 ;
}
static inline void F_116 ( struct V_1 * V_2 , bool V_151 )
{
if ( V_2 -> V_14 -> V_23 . V_158 )
F_114 ( V_2 , V_151 ) ;
}
static T_1 F_117 ( struct V_1 * V_2 , unsigned int V_159 )
{
T_1 V_4 = 0 ;
if ( V_159 >= V_160 )
return 0 ;
switch ( V_159 ) {
case V_12 :
if ( F_40 ( V_2 ) )
V_4 = F_25 ( V_2 ) ;
else
V_4 = F_25 ( V_2 ) << 24 ;
break;
case V_161 :
F_79 ( L_20 ) ;
break;
case V_162 :
if ( F_54 ( V_2 ) )
return 0 ;
V_4 = F_108 ( V_2 ) ;
break;
case V_97 :
F_85 ( V_2 ) ;
V_4 = F_19 ( V_2 , V_159 ) ;
break;
case V_98 :
F_116 ( V_2 , false ) ;
default:
V_4 = F_19 ( V_2 , V_159 ) ;
break;
}
return V_4 ;
}
static inline struct V_1 * F_118 ( struct V_163 * V_164 )
{
return F_119 ( V_164 , struct V_1 , V_164 ) ;
}
static int F_120 ( struct V_1 * V_2 , T_1 V_159 , int V_165 ,
void * V_84 )
{
unsigned char V_166 = V_159 & 0xf ;
T_1 V_76 ;
static const T_2 V_167 = 0x43ff01ffffffe70cULL ;
if ( ( V_166 + V_165 ) > 4 ) {
F_79 ( L_21 ,
V_159 , V_165 ) ;
return 1 ;
}
if ( V_159 > 0x3f0 || ! ( V_167 & ( 1ULL << ( V_159 >> 4 ) ) ) ) {
F_79 ( L_22 ,
V_159 ) ;
return 1 ;
}
V_76 = F_117 ( V_2 , V_159 & ~ 0xf ) ;
F_121 ( V_159 , V_76 ) ;
switch ( V_165 ) {
case 1 :
case 2 :
case 4 :
memcpy ( V_84 , ( char * ) & V_76 + V_166 , V_165 ) ;
break;
default:
F_97 ( V_128 L_23
L_24 , V_165 ) ;
break;
}
return 0 ;
}
static int F_122 ( struct V_1 * V_2 , T_7 V_168 )
{
return F_24 ( V_2 ) &&
V_168 >= V_2 -> V_169 &&
V_168 < V_2 -> V_169 + V_160 ;
}
static int F_123 ( struct V_163 * V_170 ,
T_7 V_171 , int V_165 , void * V_84 )
{
struct V_1 * V_2 = F_118 ( V_170 ) ;
T_1 V_159 = V_171 - V_2 -> V_169 ;
if ( ! F_122 ( V_2 , V_171 ) )
return - V_172 ;
F_120 ( V_2 , V_159 , V_165 , V_84 ) ;
return 0 ;
}
static void F_124 ( struct V_1 * V_2 )
{
T_1 V_173 , V_174 , V_175 ;
V_175 = F_19 ( V_2 , V_176 ) ;
V_173 = V_175 & 0xf ;
V_174 = ( ( V_173 & 0x3 ) | ( ( V_173 & 0x8 ) >> 1 ) ) + 1 ;
V_2 -> V_150 = 0x1 << ( V_174 & 0x7 ) ;
F_79 ( L_25 ,
V_2 -> V_150 ) ;
}
static void F_125 ( struct V_1 * V_2 )
{
T_5 V_177 ;
F_126 ( & V_2 -> V_54 . V_178 , 0 ) ;
if ( F_53 ( V_2 ) || F_52 ( V_2 ) ) {
V_177 = V_2 -> V_54 . V_147 . V_179 -> V_180 () ;
V_2 -> V_54 . V_148 = ( T_2 ) F_19 ( V_2 , V_146 )
* V_149 * V_2 -> V_150 ;
if ( ! V_2 -> V_54 . V_148 )
return;
if ( F_53 ( V_2 ) ) {
T_6 V_181 = V_182 * 1000LL ;
if ( V_2 -> V_54 . V_148 < V_181 ) {
F_127 (
L_26
L_27 ,
V_2 -> V_14 -> V_103 ,
V_2 -> V_54 . V_148 , V_181 ) ;
V_2 -> V_54 . V_148 = V_181 ;
}
}
F_128 ( & V_2 -> V_54 . V_147 ,
F_129 ( V_177 , V_2 -> V_54 . V_148 ) ,
V_183 ) ;
F_79 ( L_28 V_184 L_29
V_185 L_30
L_31
L_32 V_185 L_33 , V_186 ,
V_149 , F_110 ( V_177 ) ,
F_19 ( V_2 , V_146 ) ,
V_2 -> V_54 . V_148 ,
F_110 ( F_129 ( V_177 ,
V_2 -> V_54 . V_148 ) ) ) ;
} else if ( F_54 ( V_2 ) ) {
T_2 V_187 , V_188 = V_2 -> V_54 . V_188 ;
T_2 V_144 = 0 ;
struct V_13 * V_14 = V_2 -> V_14 ;
unsigned long V_189 = V_14 -> V_23 . V_190 ;
unsigned long V_191 ;
if ( F_29 ( ! V_188 || ! V_189 ) )
return;
F_130 ( V_191 ) ;
V_177 = V_2 -> V_54 . V_147 . V_179 -> V_180 () ;
V_187 = V_192 -> V_193 ( V_14 , F_131 () ) ;
if ( F_84 ( V_188 > V_187 ) ) {
V_144 = ( V_188 - V_187 ) * 1000000ULL ;
F_132 ( V_144 , V_189 ) ;
}
F_128 ( & V_2 -> V_54 . V_147 ,
F_129 ( V_177 , V_144 ) , V_183 ) ;
F_133 ( V_191 ) ;
}
}
static void F_134 ( struct V_1 * V_2 , T_1 V_194 )
{
int V_195 = F_55 ( F_19 ( V_2 , V_196 ) ) ;
if ( F_55 ( V_194 ) ) {
if ( ! V_195 ) {
F_79 ( L_34
L_35 , V_2 -> V_14 -> V_103 ) ;
V_2 -> V_14 -> V_22 -> V_23 . V_197 ++ ;
}
} else if ( V_195 )
V_2 -> V_14 -> V_22 -> V_23 . V_197 -- ;
}
static int F_135 ( struct V_1 * V_2 , T_1 V_70 , T_1 V_4 )
{
int V_113 = 0 ;
F_136 ( V_70 , V_4 ) ;
switch ( V_70 ) {
case V_12 :
if ( ! F_40 ( V_2 ) )
F_48 ( V_2 , V_4 >> 24 ) ;
else
V_113 = 1 ;
break;
case V_98 :
F_116 ( V_2 , true ) ;
F_87 ( V_2 , V_4 & 0xff ) ;
break;
case V_198 :
F_101 ( V_2 ) ;
break;
case V_47 :
if ( ! F_40 ( V_2 ) )
F_49 ( V_2 , V_4 & V_199 ) ;
else
V_113 = 1 ;
break;
case V_45 :
if ( ! F_40 ( V_2 ) ) {
F_1 ( V_2 , V_45 , V_4 | 0x0FFFFFFF ) ;
F_35 ( V_2 -> V_14 -> V_22 ) ;
} else
V_113 = 1 ;
break;
case V_8 : {
T_1 V_200 = 0x3ff ;
if ( F_19 ( V_2 , V_69 ) & V_68 )
V_200 |= V_131 ;
F_18 ( V_2 , V_4 & V_200 ) ;
if ( ! ( V_4 & V_9 ) ) {
int V_21 ;
T_1 V_59 ;
for ( V_21 = 0 ; V_21 < V_201 ; V_21 ++ ) {
V_59 = F_19 ( V_2 ,
V_53 + 0x10 * V_21 ) ;
F_1 ( V_2 , V_53 + 0x10 * V_21 ,
V_59 | V_51 ) ;
}
F_126 ( & V_2 -> V_54 . V_178 , 0 ) ;
}
break;
}
case V_136 :
F_1 ( V_2 , V_136 , V_4 & ~ ( 1 << 12 ) ) ;
F_104 ( V_2 ) ;
break;
case V_138 :
if ( ! F_40 ( V_2 ) )
V_4 &= 0xff000000 ;
F_1 ( V_2 , V_138 , V_4 ) ;
break;
case V_196 :
F_134 ( V_2 , V_4 ) ;
case V_202 :
case V_203 :
case V_204 :
case V_205 :
if ( ! F_23 ( V_2 ) )
V_4 |= V_51 ;
V_4 &= V_206 [ ( V_70 - V_53 ) >> 4 ] ;
F_1 ( V_2 , V_70 , V_4 ) ;
break;
case V_53 :
if ( ( F_19 ( V_2 , V_53 ) &
V_2 -> V_54 . V_55 ) !=
( V_4 & V_2 -> V_54 . V_55 ) )
F_137 ( & V_2 -> V_54 . V_147 ) ;
if ( ! F_23 ( V_2 ) )
V_4 |= V_51 ;
V_4 &= ( V_206 [ 0 ] | V_2 -> V_54 . V_55 ) ;
F_1 ( V_2 , V_53 , V_4 ) ;
break;
case V_146 :
if ( F_54 ( V_2 ) )
break;
F_137 ( & V_2 -> V_54 . V_147 ) ;
F_1 ( V_2 , V_146 , V_4 ) ;
F_125 ( V_2 ) ;
break;
case V_176 :
if ( V_4 & 4 )
F_79 ( L_36 , V_4 ) ;
F_1 ( V_2 , V_176 , V_4 ) ;
F_124 ( V_2 ) ;
break;
case V_207 :
if ( F_40 ( V_2 ) && V_4 != 0 ) {
F_79 ( L_37 , V_4 ) ;
V_113 = 1 ;
}
break;
case V_208 :
if ( F_40 ( V_2 ) ) {
F_135 ( V_2 , V_136 , 0x40000 | ( V_4 & 0xff ) ) ;
} else
V_113 = 1 ;
break;
default:
V_113 = 1 ;
break;
}
if ( V_113 )
F_79 ( L_38 , V_70 ) ;
return V_113 ;
}
static int F_138 ( struct V_163 * V_170 ,
T_7 V_171 , int V_165 , const void * V_84 )
{
struct V_1 * V_2 = F_118 ( V_170 ) ;
unsigned int V_159 = V_171 - V_2 -> V_169 ;
T_1 V_4 ;
if ( ! F_122 ( V_2 , V_171 ) )
return - V_172 ;
if ( V_165 != 4 || ( V_159 & 0xf ) ) {
F_79 ( L_39 , V_165 , ( long ) V_171 ) ;
return 0 ;
}
V_4 = * ( T_1 * ) V_84 ;
if ( V_159 != V_198 )
F_79 ( L_40
L_41 , V_186 , V_159 , V_165 , V_4 ) ;
F_135 ( V_2 , V_159 & 0xff0 , V_4 ) ;
return 0 ;
}
void F_139 ( struct V_13 * V_14 )
{
if ( F_57 ( V_14 ) )
F_135 ( V_14 -> V_23 . V_2 , V_198 , 0 ) ;
}
void F_140 ( struct V_13 * V_14 , T_1 V_159 )
{
T_1 V_4 = 0 ;
V_159 &= 0xff0 ;
F_120 ( V_14 -> V_23 . V_2 , V_159 , 4 , & V_4 ) ;
F_135 ( V_14 -> V_23 . V_2 , V_159 , V_4 ) ;
}
void F_141 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_23 . V_2 ;
if ( ! V_14 -> V_23 . V_2 )
return;
F_137 ( & V_2 -> V_54 . V_147 ) ;
if ( ! ( V_14 -> V_23 . V_209 & V_210 ) )
F_20 ( & V_211 ) ;
if ( ! ( F_19 ( V_2 , V_8 ) & V_9 ) )
F_20 ( & V_10 ) ;
if ( V_2 -> V_5 )
F_142 ( ( unsigned long ) V_2 -> V_5 ) ;
F_143 ( V_2 ) ;
}
T_2 F_144 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_23 . V_2 ;
if ( ! F_57 ( V_14 ) || F_52 ( V_2 ) ||
F_53 ( V_2 ) )
return 0 ;
return V_2 -> V_54 . V_188 ;
}
void F_145 ( struct V_13 * V_14 , T_2 V_84 )
{
struct V_1 * V_2 = V_14 -> V_23 . V_2 ;
if ( ! F_57 ( V_14 ) || F_52 ( V_2 ) ||
F_53 ( V_2 ) )
return;
F_137 ( & V_2 -> V_54 . V_147 ) ;
V_2 -> V_54 . V_188 = V_84 ;
F_125 ( V_2 ) ;
}
void F_146 ( struct V_13 * V_14 , unsigned long V_212 )
{
struct V_1 * V_2 = V_14 -> V_23 . V_2 ;
if ( ! F_57 ( V_14 ) )
return;
F_87 ( V_2 , ( ( V_212 & 0x0f ) << 4 )
| ( F_19 ( V_2 , V_98 ) & 4 ) ) ;
}
T_2 F_147 ( struct V_13 * V_14 )
{
T_2 V_92 ;
if ( ! F_57 ( V_14 ) )
return 0 ;
V_92 = ( T_2 ) F_19 ( V_14 -> V_23 . V_2 , V_98 ) ;
return ( V_92 & 0xf0 ) >> 4 ;
}
void F_148 ( struct V_13 * V_14 , T_2 V_213 )
{
T_2 V_214 = V_14 -> V_23 . V_209 ;
struct V_1 * V_2 = V_14 -> V_23 . V_2 ;
if ( ! V_2 ) {
V_213 |= V_215 ;
V_14 -> V_23 . V_209 = V_213 ;
return;
}
if ( ( V_14 -> V_23 . V_209 ^ V_213 ) & V_210 ) {
if ( V_213 & V_210 )
F_20 ( & V_211 ) ;
else
F_21 ( & V_211 . V_11 ) ;
F_35 ( V_14 -> V_22 ) ;
}
if ( ! F_149 ( V_2 -> V_14 ) )
V_213 &= ~ V_215 ;
V_14 -> V_23 . V_209 = V_213 ;
if ( ( V_214 ^ V_213 ) & V_216 ) {
if ( V_213 & V_216 ) {
T_1 V_49 = F_25 ( V_2 ) ;
T_1 V_44 = ( ( V_49 >> 4 ) << 16 ) | ( 1 << ( V_49 & 0xf ) ) ;
F_49 ( V_2 , V_44 ) ;
V_192 -> V_217 ( V_14 , true ) ;
} else
V_192 -> V_217 ( V_14 , false ) ;
}
V_2 -> V_169 = V_2 -> V_14 -> V_23 . V_209 &
V_218 ;
F_79 ( L_42 V_185 L_43
L_44 , V_2 -> V_14 -> V_23 . V_209 , V_2 -> V_169 ) ;
}
void F_150 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
int V_21 ;
F_79 ( L_45 , V_186 ) ;
ASSERT ( V_14 ) ;
V_2 = V_14 -> V_23 . V_2 ;
ASSERT ( V_2 != NULL ) ;
F_137 ( & V_2 -> V_54 . V_147 ) ;
F_48 ( V_2 , V_14 -> V_103 ) ;
F_56 ( V_2 -> V_14 ) ;
for ( V_21 = 0 ; V_21 < V_201 ; V_21 ++ )
F_1 ( V_2 , V_53 + 0x10 * V_21 , V_51 ) ;
F_1 ( V_2 , V_196 ,
F_151 ( 0 , V_219 ) ) ;
F_1 ( V_2 , V_45 , 0xffffffffU ) ;
F_18 ( V_2 , 0xff ) ;
F_1 ( V_2 , V_98 , 0 ) ;
F_49 ( V_2 , 0 ) ;
F_1 ( V_2 , V_207 , 0 ) ;
F_1 ( V_2 , V_136 , 0 ) ;
F_1 ( V_2 , V_138 , 0 ) ;
F_1 ( V_2 , V_176 , 0 ) ;
F_1 ( V_2 , V_146 , 0 ) ;
for ( V_21 = 0 ; V_21 < 8 ; V_21 ++ ) {
F_1 ( V_2 , V_75 + 0x10 * V_21 , 0 ) ;
F_1 ( V_2 , V_77 + 0x10 * V_21 , 0 ) ;
F_1 ( V_2 , V_118 + 0x10 * V_21 , 0 ) ;
}
V_2 -> V_74 = F_152 ( V_14 -> V_22 ) ;
V_2 -> V_78 = F_152 ( V_14 -> V_22 ) ;
V_2 -> V_79 = - 1 ;
F_124 ( V_2 ) ;
F_126 ( & V_2 -> V_54 . V_178 , 0 ) ;
if ( F_149 ( V_14 ) )
F_148 ( V_14 ,
V_14 -> V_23 . V_209 | V_215 ) ;
V_14 -> V_23 . V_83 . V_85 = 0 ;
F_85 ( V_2 ) ;
V_14 -> V_23 . V_116 = 0 ;
V_14 -> V_23 . V_90 = 0 ;
F_79 ( V_220 L_46
L_47 V_185 L_48 , V_186 ,
V_14 , F_25 ( V_2 ) ,
V_14 -> V_23 . V_209 , V_2 -> V_169 ) ;
}
static bool F_153 ( struct V_1 * V_2 )
{
return F_53 ( V_2 ) ;
}
int F_154 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_23 . V_2 ;
if ( F_57 ( V_14 ) && F_22 ( V_2 ) &&
F_50 ( V_2 , V_53 ) )
return F_155 ( & V_2 -> V_54 . V_178 ) ;
return 0 ;
}
int F_156 ( struct V_1 * V_2 , int V_50 )
{
T_1 V_70 = F_19 ( V_2 , V_50 ) ;
int V_25 , V_221 , V_82 ;
if ( F_24 ( V_2 ) && ! ( V_70 & V_51 ) ) {
V_25 = V_70 & V_52 ;
V_221 = V_70 & V_60 ;
V_82 = V_70 & V_222 ;
return F_72 ( V_2 , V_221 , V_25 , 1 , V_82 ) ;
}
return 0 ;
}
void F_157 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_23 . V_2 ;
if ( V_2 )
F_156 ( V_2 , V_196 ) ;
}
static enum V_223 F_158 ( struct V_224 * V_84 )
{
struct V_225 * V_226 = F_119 ( V_84 , struct V_225 , V_147 ) ;
struct V_1 * V_2 = F_119 ( V_226 , struct V_1 , V_54 ) ;
struct V_13 * V_14 = V_2 -> V_14 ;
T_8 * V_227 = & V_14 -> V_228 ;
if ( ! F_155 ( & V_226 -> V_178 ) ) {
F_159 ( & V_226 -> V_178 ) ;
F_86 ( V_229 , V_14 ) ;
}
if ( F_160 ( V_227 ) )
F_161 ( V_227 ) ;
if ( F_153 ( V_2 ) ) {
F_162 ( & V_226 -> V_147 , V_226 -> V_148 ) ;
return V_230 ;
} else
return V_231 ;
}
int F_163 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
ASSERT ( V_14 != NULL ) ;
F_79 ( L_49 , V_14 -> V_103 ) ;
V_2 = F_36 ( sizeof( * V_2 ) , V_37 ) ;
if ( ! V_2 )
goto V_232;
V_14 -> V_23 . V_2 = V_2 ;
V_2 -> V_5 = ( void * ) F_164 ( V_37 ) ;
if ( ! V_2 -> V_5 ) {
F_97 ( V_128 L_50 ,
V_14 -> V_103 ) ;
goto V_233;
}
V_2 -> V_14 = V_14 ;
F_165 ( & V_2 -> V_54 . V_147 , V_234 ,
V_183 ) ;
V_2 -> V_54 . V_147 . V_235 = F_158 ;
V_14 -> V_23 . V_209 = V_210 ;
F_148 ( V_14 ,
V_236 | V_210 ) ;
F_21 ( & V_10 . V_11 ) ;
F_150 ( V_14 ) ;
F_166 ( & V_2 -> V_164 , & V_237 ) ;
return 0 ;
V_233:
F_143 ( V_2 ) ;
V_232:
return - V_238 ;
}
int F_167 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_23 . V_2 ;
int V_80 ;
if ( ! F_57 ( V_14 ) || ! F_22 ( V_2 ) )
return - 1 ;
F_85 ( V_2 ) ;
V_80 = F_65 ( V_2 ) ;
if ( ( V_80 == - 1 ) ||
( ( V_80 & 0xF0 ) <= F_19 ( V_2 , V_97 ) ) )
return - 1 ;
return V_80 ;
}
int F_168 ( struct V_13 * V_14 )
{
T_1 V_239 = F_19 ( V_14 -> V_23 . V_2 , V_196 ) ;
int V_112 = 0 ;
if ( ! F_24 ( V_14 -> V_23 . V_2 ) )
V_112 = 1 ;
if ( ( V_239 & V_51 ) == 0 &&
F_169 ( V_239 ) == V_219 )
V_112 = 1 ;
return V_112 ;
}
void F_170 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_23 . V_2 ;
if ( ! F_57 ( V_14 ) )
return;
if ( F_155 ( & V_2 -> V_54 . V_178 ) > 0 ) {
if ( F_156 ( V_2 , V_53 ) )
F_171 ( & V_2 -> V_54 . V_178 ) ;
}
}
int F_172 ( struct V_13 * V_14 )
{
int V_25 = F_167 ( V_14 ) ;
struct V_1 * V_2 = V_14 -> V_23 . V_2 ;
if ( V_25 == - 1 )
return - 1 ;
F_67 ( V_25 , V_2 ) ;
F_85 ( V_2 ) ;
F_66 ( V_25 , V_2 ) ;
return V_25 ;
}
void F_173 ( struct V_13 * V_14 ,
struct V_240 * V_241 )
{
struct V_1 * V_2 = V_14 -> V_23 . V_2 ;
F_148 ( V_14 , V_14 -> V_23 . V_209 ) ;
F_18 ( V_2 , * ( ( T_1 * ) ( V_241 -> V_5 + V_8 ) ) ) ;
memcpy ( V_14 -> V_23 . V_2 -> V_5 , V_241 -> V_5 , sizeof *V_241 ) ;
F_48 ( V_2 , F_25 ( V_2 ) ) ;
F_56 ( V_14 ) ;
F_85 ( V_2 ) ;
F_137 ( & V_2 -> V_54 . V_147 ) ;
F_124 ( V_2 ) ;
F_125 ( V_2 ) ;
V_2 -> V_74 = true ;
V_2 -> V_78 = F_152 ( V_14 -> V_22 ) ?
1 : F_61 ( V_2 -> V_5 + V_77 ) ;
V_2 -> V_79 = - 1 ;
V_192 -> V_242 ( V_14 -> V_22 , F_83 ( V_2 ) ) ;
F_86 ( V_99 , V_14 ) ;
}
void F_174 ( struct V_13 * V_14 )
{
struct V_224 * V_147 ;
if ( ! F_57 ( V_14 ) )
return;
V_147 = & V_14 -> V_23 . V_2 -> V_54 . V_147 ;
if ( F_137 ( V_147 ) )
F_175 ( V_147 , V_183 ) ;
}
static void F_176 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
bool V_178 ;
int V_25 ;
F_68 ( ! F_77 ( V_14 ) ) ;
V_178 = F_78 ( V_14 ) ;
F_81 ( V_14 ) ;
if ( V_178 )
return;
V_25 = F_101 ( V_2 ) ;
F_177 ( V_2 , V_25 ) ;
}
void F_178 ( struct V_13 * V_14 )
{
T_1 V_84 ;
void * V_243 ;
if ( F_9 ( V_89 , & V_14 -> V_23 . V_90 ) )
F_176 ( V_14 , V_14 -> V_23 . V_2 ) ;
if ( ! F_9 ( V_244 , & V_14 -> V_23 . V_90 ) )
return;
V_243 = F_179 ( V_14 -> V_23 . V_2 -> V_245 ) ;
V_84 = * ( T_1 * ) ( V_243 + F_180 ( V_14 -> V_23 . V_2 -> V_246 ) ) ;
F_181 ( V_243 ) ;
F_87 ( V_14 -> V_23 . V_2 , V_84 & 0xff ) ;
}
static void F_182 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
if ( ! F_77 ( V_14 ) ||
V_2 -> V_74 ||
V_2 -> V_79 == - 1 ||
F_99 ( V_14 -> V_22 , V_2 -> V_79 ) ) {
return;
}
F_80 ( V_2 -> V_14 ) ;
}
void F_183 ( struct V_13 * V_14 )
{
T_1 V_84 , V_92 ;
int V_247 , V_248 ;
struct V_1 * V_2 = V_14 -> V_23 . V_2 ;
void * V_243 ;
F_182 ( V_14 , V_2 ) ;
if ( ! F_9 ( V_244 , & V_14 -> V_23 . V_90 ) )
return;
V_92 = F_19 ( V_2 , V_98 ) & 0xff ;
V_247 = F_65 ( V_2 ) ;
if ( V_247 < 0 )
V_247 = 0 ;
V_248 = F_83 ( V_2 ) ;
if ( V_248 < 0 )
V_248 = 0 ;
V_84 = ( V_92 & 0xff ) | ( ( V_248 & 0xf0 ) << 8 ) | ( V_247 << 24 ) ;
V_243 = F_179 ( V_14 -> V_23 . V_2 -> V_245 ) ;
* ( T_1 * ) ( V_243 + F_180 ( V_14 -> V_23 . V_2 -> V_246 ) ) = V_84 ;
F_181 ( V_243 ) ;
}
void F_184 ( struct V_13 * V_14 , T_7 V_246 )
{
V_14 -> V_23 . V_2 -> V_246 = V_246 ;
if ( V_246 )
F_30 ( V_244 , & V_14 -> V_23 . V_90 ) ;
else
F_82 ( V_244 , & V_14 -> V_23 . V_90 ) ;
}
int F_185 ( struct V_13 * V_14 , T_1 V_249 , T_2 V_84 )
{
struct V_1 * V_2 = V_14 -> V_23 . V_2 ;
T_1 V_70 = ( V_249 - V_250 ) << 4 ;
if ( ! F_186 ( V_14 -> V_22 ) || ! F_40 ( V_2 ) )
return 1 ;
if ( V_249 == 0x830 )
F_135 ( V_2 , V_138 , ( T_1 ) ( V_84 >> 32 ) ) ;
return F_135 ( V_2 , V_70 , ( T_1 ) V_84 ) ;
}
int F_187 ( struct V_13 * V_14 , T_1 V_249 , T_2 * V_84 )
{
struct V_1 * V_2 = V_14 -> V_23 . V_2 ;
T_1 V_70 = ( V_249 - V_250 ) << 4 , V_251 , V_252 = 0 ;
if ( ! F_186 ( V_14 -> V_22 ) || ! F_40 ( V_2 ) )
return 1 ;
if ( F_120 ( V_2 , V_70 , 4 , & V_251 ) )
return 1 ;
if ( V_249 == 0x830 )
F_120 ( V_2 , V_138 , 4 , & V_252 ) ;
* V_84 = ( ( ( T_2 ) V_252 ) << 32 ) | V_251 ;
return 0 ;
}
int F_188 ( struct V_13 * V_14 , T_1 V_70 , T_2 V_84 )
{
struct V_1 * V_2 = V_14 -> V_23 . V_2 ;
if ( ! F_57 ( V_14 ) )
return 1 ;
if ( V_70 == V_136 )
F_135 ( V_2 , V_138 , ( T_1 ) ( V_84 >> 32 ) ) ;
return F_135 ( V_2 , V_70 , ( T_1 ) V_84 ) ;
}
int F_189 ( struct V_13 * V_14 , T_1 V_70 , T_2 * V_84 )
{
struct V_1 * V_2 = V_14 -> V_23 . V_2 ;
T_1 V_251 , V_252 = 0 ;
if ( ! F_57 ( V_14 ) )
return 1 ;
if ( F_120 ( V_2 , V_70 , 4 , & V_251 ) )
return 1 ;
if ( V_70 == V_136 )
F_120 ( V_2 , V_138 , 4 , & V_252 ) ;
* V_84 = ( ( ( T_2 ) V_252 ) << 32 ) | V_251 ;
return 0 ;
}
int F_190 ( struct V_13 * V_14 , T_2 V_84 )
{
T_2 V_168 = V_84 & ~ V_86 ;
if ( ! F_191 ( V_168 , 4 ) )
return 1 ;
V_14 -> V_23 . V_83 . V_85 = V_84 ;
if ( ! F_77 ( V_14 ) )
return 0 ;
return F_192 ( V_14 -> V_22 , & V_14 -> V_23 . V_83 . V_84 ,
V_168 , sizeof( T_4 ) ) ;
}
void F_193 ( void )
{
F_194 ( & V_211 , V_253 ) ;
F_194 ( & V_10 , V_253 ) ;
}
